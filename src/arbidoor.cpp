// author: zlice
// license: MIT (see LICENSE file or https://mit-license.org)

// compile with mingw32, or you know, suffer MSVC
//
// i686-w64-mingw32-g++ -mdll -mwindows -fpermissive -masm=intel -Os -s -static -o arbidoor.dll arbidoor.cpp
//
// permissive, because with all this pointer math the compiler can shut up
// intel, because at&t syntax? are you crazy?
// static, or else plugin fails to load as it has weird mingw deps

#include <cstdint>
#include <ctime>
#include <random>
#include <unordered_map>
#include <utility> // swap

#include <fileapi.h>
#include <handleapi.h>

#include "doors.h" // some vars and arrays of doors
#include "cell_sw.h" // list of cells with door ids
#include "SafeWrite.cpp" // fose rewrite
#include "fose_types.h"

using namespace std;

#define ARBVERSION 8

// 0-based start of DLC in areas[] below
// areas_enabled[DLC_START] = anchorage
#define DLC_START 5

struct {
  int enabled = 1,    // non-0 true, 0 false
      sane_doors = 1; // 1 true, non-1 false
  // see doors.h arrays
  int areas_enabled[10] = { 1, 0, 0, 0, 0,
                            1, 1, 1, 0, 1 };
    // areas used below as:
    //  fo3base
    //  vault101child
    //  tranquility
    //  vault87
    //  ravenrock
    //  (DLCs)
    // code DLC order is:
    //   anchorage
    //   pitt
    //   pointlookout
    //   zeta
    //   brokensteel
  int version = ARBVERSION, // mainly for debug purposes right now
      reserved1 = 0, // so doors start on a 4th 4byte
      reserved2 = 0,
      reserved3 = 0,
      tot_zones = 0, // amount of 'zones' originally found
      tot_bad = 0, // for debuging. rixing abandoned doors is imperfect.
      tot_mv = 0, // helps to know if the number of bad < moveable on seed-gen
      tot_doors = 0; // last so it is before the hashmap table
} cfg;

// these change per game run or save load
// player name is used for seed name : e.g. <player>.arb
char player_name[] = "12345678901234567890\0"; // should always be less than 20?
int player_changed = 0; // if player(seed)-name are different
int dlc_ids[5] = { 0, 0, 0, 0, 0 }; // ??xxxxxx ID of DLCs loaded once at game start


// first functions rely on asm

// player name is [[[hardcoded_ptr] + 0x1C] + 0xD0 + 0x4]
void get_player_name() {
  char *new_name = 0;
  asm volatile("mov ecx, [0x107A104];" // hardcoded (1.7.0.3) static pointer
      "add ecx, 0x1C;" // to player struct
      "mov ecx, [ecx];"
      "add ecx, 0xD4;" // to player name
      "mov ecx, [ecx];"
      : "=r"(new_name) );
  // strcpy with setter
  size_t nm_pos = 0;
  player_changed = 0;
  while (nm_pos < 19 && new_name[nm_pos] != 0) {
    // set multiple times, less instructions than checking
    player_changed |= player_name[nm_pos] != new_name[nm_pos];
    player_name[nm_pos] = new_name[nm_pos];
    nm_pos++;
  }
  if (nm_pos > 0) // cap new null terminated string
    player_name[nm_pos] = 0;
}


// DLC(mod) list is stored at [hardcoded_ptr] + 1AC
// +1A8 is base game, +1A4 is total DLC/mods
void find_dlc_ids() {
  uint32_t *dlc_tbl = 0, dlc_cnt = 0;
  char *dlc_name = 0;
  const char dlc_names[] = "ATPZB";
  // !!!order important!!! see above
  // going to cheat and check only the first letter
  // instead of
  //const char *dlc_names[5] = {
  //  "Anchorage", "ThePitt",
  //  "PointLookout", "Zeta", "BrokenSteel"
  //};

  asm volatile("mov ecx, [0x106CDCC];" // hardcoded (1.7.0.3) static pointer
      "add ecx, 0x1AC;" // DLC table (after Fallout3.esm)
      "mov %0, ecx;"
      : "=r"(dlc_tbl) : : "ecx" );

  while (dlc_tbl[dlc_cnt] != 0) {
    dlc_name = (char*)dlc_tbl[dlc_cnt] + 0x20;
    for (int cur_dlc = 0 ; cur_dlc < 5 ; cur_dlc++) {
      if (dlc_name[0] == dlc_names[cur_dlc] ) {
        dlc_ids[cur_dlc] = dlc_cnt + 1; // main game is always 0
        break;
      }
    } // for dlc_names[]
    dlc_cnt++;
  } // while dlc_tbl
} // find_dlc_ids()


// hardcoded fo3 function 'get ref-ID' (some kind of hash%map)
// this really returns a 'pointer', but we're treating it as 'int'
// as we do a bunch of pointer math
// may or may not return a parent object
uint32_t (*get_ref_id)(uint32_t refid) = 0xBEA7B0; // Fallout 3 - GOG 1.7.0.3

uint32_t get_door_ptr(uint32_t refid) {
  // MUST put hardcoded fallout pointer in ECX, BEA() expects this
  asm volatile("mov ecx, [0x106DD14];"
      "push edx;" // clobbered by BEA
      "push esp;"
      "push %0;"
      : : "r" (refid) );
  uint32_t ptr280 = get_ref_id(refid); // has 280xxx01 usually, not true id, that's on stack
  asm volatile("cmp al, 1;" // 1 is success / a 'valid' pointer to a ref-id
      "pop eax;"
      "jne notfound;"
          "mov edx, [eax];"
          "cmp edx, 0xDCEE7C;" // door ptr tag/type. sometimes you get back nonsense
      "je valid;"
      "notfound:"
      "xor eax, eax;" // e.g. dlc is loaded, but not active
      "valid:"
      "mov %0, eax;" // redundant, but compiler is confused on eax being ptr280
      "pop edx;"
      : "=r" (ptr280) );
  return ptr280;
}


// crawls door REFR IDs to build pointer maps.
// need to rebuild on loads in case memory changes
// (usually between multiple player-name loads)
//
// these addresses are particular to my setup but...
//
// typically a 03* table gives you a 280* pointer. (see BEA* above)
// 280* typically holds a 16* pointer which is a
// single pointer with no other references (i think).
// (sometimes doors hops around for DLC, outside, or misc)
// 16* holds a pointer to 1b*, which has XTEL data.
// (destination 280* and xyz coords)
// e.g.
// Arefu <> West Residence
// [2806FB40 +0x44] > [160051806 + 0xC] > 1B0597A0
// 1B0597A0 is <280*> <f32> <f32> <f32>
//   (dest REFR ID pointer, xyz floats)
//
// by changing 1b*'s 280* you effectively change the
// door_to but teleport to a weird position, not by the door.
// by changing 16*'s 1b* (pointer to XTEL), you warp in front
// of the door. not falling out of the sky :)

// it's honestly harder to read pointer math in C
// so, more inline asm
int add_doors_of(const uint32_t *area_doors, int dlcid) {
  uint32_t cnt = 0; // returns total doors added or 0
  dlcid = (dlcid << 24) | 0x00FFFFFF; // for logical-AND ahead

  while (area_doors[cnt] != 0x0) {
  uint32_t door_16 = 0, door_1b = 0,
           door_refr = area_doors[cnt++]; // inc here
  // 'and' appropriate ??xxxxxx DLC id
  get_door_ptr(door_refr & dlcid); // 280*
  asm volatile("cmp eax, 0;"
            "je next_door;"
        "add eax, 0x44;"
        "mov eax, [eax];" // assume get_ref doors ptr (280*) are fine
        "mov ebx, [eax];" // door tag
        "cmp ebx, 0xDB5844;" // door tag
    "dig:" // some doors (outside?) 171 > 170 have more ptr to ptr for 16* > 1b* (XTEL)
        "je get_xtel;"
            "add eax, 0x8;" // 28 > 171 > 170 > 16 or 28 > 16(2f) > 16
            "mov eax, [eax];"
            "mov ebx, [eax];"
                "cmp ebx, 0xDB5844;" // door tag
                "jne dig;"
    "get_xtel:"
        "add eax, 0xC;"
        "mov %0, eax;" // save 16* (door 'xtel' ptr-ptr)
        "mov %1, [eax];"
    "next_door:"
    : "=r"(door_16), "=r"(door_1b) : : "ebx", "edx");

    if (door_16 == 0 || door_1b == 0)
      return 0; // error, DLC may not be active?
      // may have extra in pointer maps? oh well

    door_16_map[door_refr] = door_16;
    door_1b_map[door_refr] = door_1b;
  } // for door list
  return cnt;
} // add_doors_of()

// end of asm heavy bits

// randomize our <refr-id> : <refr-id> hashmap
// and if sane_doors try to match pairs and make all paths reachable
void shuffle_doors() {
  rgen.seed(rand_dev() ); // mersenne_twister_engine seeded randomness
  src_distrib = uniform_int_distribution<uint32_t>(10000, 1000000);
  dst_distrib = uniform_int_distribution<uint32_t>(0, TOT_DOORS - 1);

  unordered_map<uint32_t, uint32_t> seen, comp_doors; // seen cells/doors

  uint32_t src_doors[1488], dst_doors[1488], i = 0,
           src_comp = 0, dst_comp = 0,
           src_rnd = 0, dst_rnd = 0,
           // cell crawl - 535 total cells, 315 are single door 'houses'
           bad_doors[700], can_move[700], nxt_cells[250], // only 246 in cell_sw
           world_doors[300], bad_cnt = 0, can_mv_cnt = 0, cur_cell_door = 0;

  // use pos, not value
  for (i = 0 ; i < TOT_DOORS ; i++)
    src_doors[i] = dst_doors[i] = i;

  // shuffle (swap) src and dst doors between 10k and 1mil times
  for (i = 0 ; i < src_distrib(rgen) ; i++) {
    src_rnd = dst_rnd = dst_distrib(rgen);
    while (dst_rnd == src_rnd)
      dst_rnd = dst_distrib(rgen);
    swap(src_doors[src_rnd], src_doors[dst_rnd]);
  } // for src shuffle

  for (i = 0 ; i < src_distrib(rgen) ; i++) {
    src_rnd = dst_rnd = dst_distrib(rgen);
    while (dst_rnd == src_rnd)
      dst_rnd = dst_distrib(rgen);
    swap(dst_doors[src_rnd], dst_doors[dst_rnd]);
  } // for dst shuffle

  // for insane doors, you're basically done

  if (cfg.sane_doors == 1) {
    i = 0;
    while (i < TOT_DOORS - 1) {
      src_rnd = src_doors[i];
      dst_rnd = dst_doors[i];
      if ((src_rnd ^ 1) == dst_rnd) // <4 5> wont find itself^1 <4 5>
        swap(src_rnd, dst_rnd); // so search for <5 4> instead

      i++;

      // find compliment door positions
      src_comp = dst_comp = i;
      while (src_comp < TOT_DOORS && (dst_rnd ^ 1) != src_doors[src_comp])
        src_comp++;
      while (dst_comp < TOT_DOORS && (src_rnd ^ 1) != dst_doors[dst_comp])
        dst_comp++;

      if (src_comp != TOT_DOORS || dst_comp != TOT_DOORS) {
        // swap list match to compliments
        //   randomized           not-randomized
        // [0] <1 5>   -or-   [0] <4 5>  ->  [0] <4 4>
        // [1] <4 0>   -or-   [1] <5 4>  ->  [1] <5 5>
        if (src_comp != i)
          swap(src_doors[i], src_doors[src_comp]);
        if (dst_comp != i)
          swap(dst_doors[i], dst_doors[dst_comp]);
        // for to-self you actually want 0<>0, not 0<>1
        if (src_rnd == (dst_rnd ^ 1) )
          swap(src_doors[i-1], src_doors[i]);
        i++;
      } else { // swap and retry
        i--; // retry
        swap(src_doors[i], src_doors[i+1]); // make <0 1> <x 1>
      } // if compliment doors
    } // while 'for' doors
  } // if sane doors

  // fill out door map with ref-IDs
  for (i = 0 ; i < TOT_DOORS ; i++)
    arbidoor[found_doors[src_doors[i]]] = found_doors[dst_doors[i]];

  // messy, in short, crawl through cells, track seen doors/cells,
  // and see if a 'zone' hits the world cell to prevent isolated doors.
  if (cfg.sane_doors == 1) {
    int zone_cnt = 0; // purely for info in arb seed file

    comp_doors[0] = 0;
    seen[0] = seen[(uint32_t)cell_00002DB4] = 1;
    for (i = 0 ; i < TOT_DOORS ; i += 2) { // compliment map
      comp_doors[found_doors[i]] = found_doors[i+1];
      comp_doors[found_doors[i+1]] = found_doors[i];
    }

    for (auto [src_door, dst_door] : arbidoor) {
      if (seen[src_door] == 1)
        continue;

      int world_cnt = 0, // number of world (main map) doors in 'zone'
          cd_cnt = 0, // current door count
          cell_depth = 0;

      uint32_t *cur_cell = (uint32_t*)get_door_cell(src_door),
                chk_cell = (uint32_t)get_door_cell(comp_doors[dst_door]);

      if (cur_cell == cell_00002DB4 || (uint32_t*)chk_cell == cell_00002DB4) {
        // world<>world can be moved
        // they are not as useful, and the main game doesn't do this
        if (chk_cell == (uint32_t)cur_cell) {
          can_move[can_mv_cnt++] = src_door;
          seen[src_door] = seen[comp_doors[dst_door]] = 1;
        }
        continue;
      }

      nxt_cells[cell_depth++] = 0; // [0] stops loop
      nxt_cells[cell_depth] = (uint32_t)cur_cell;

      while (cell_depth > 0) {
        cur_cell = (uint32_t*)nxt_cells[cell_depth];
        cur_cell_door = cur_cell ? cur_cell[0] : 0;

        if (seen[(uint32_t)cur_cell] == 0) {
          seen[(uint32_t)cur_cell] = 1;
          cd_cnt = 0;
          while (cur_cell_door != 0) {
            cur_cell_door = cur_cell[cd_cnt++];
            if (arbidoor.count(cur_cell_door) != 0) {
              chk_cell = arbidoor[cur_cell_door];
              chk_cell = comp_doors[chk_cell];
              seen[cur_cell_door] = seen[chk_cell] = 1;
              chk_cell = (uint32_t)get_door_cell(chk_cell);

              if ((uint32_t*)chk_cell == cell_00002DB4)
                world_doors[world_cnt++] = cur_cell_door;
              else if (chk_cell != 0 && seen[chk_cell] == 0) // not seen + not 1 door cell
                nxt_cells[cell_depth++] = chk_cell;
            } // if door in randomizer
          } // while doors in cell
        } // if seen cell
        cell_depth--;
      } // while nxt_cells

      if (world_cnt == 0)
        bad_doors[bad_cnt++] = src_door;
      else {
        while (--world_cnt > 0) { // leave 0 so each zone has at least 1 world door
          int c = 0;
          for ( ; c < can_mv_cnt ; c++)
            if (can_move[c] == world_doors[world_cnt])
              break; // make sure it's not already in list
          if (c == can_mv_cnt)
            can_move[can_mv_cnt++] = world_doors[world_cnt];
        }
      }

      zone_cnt++;
    } // for crawl cells

// debug dump
//    if (bad_cnt != 0 || can_mv_cnt != 0) {
//       HANDLE badbad = CreateFile("ISBAD", GENERIC_WRITE, 0,
//                         0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
//       WriteFile(badbad, bad_doors, bad_cnt * 4, 0, 0);
//       CloseHandle(badbad);
//
//       HANDLE mvmv = CreateFile("ISMV", GENERIC_WRITE, 0,
//                         0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
//       WriteFile(mvmv, can_move, can_mv_cnt * 4, 0, 0);
//       CloseHandle(mvmv);
//    }

    cfg.tot_zones = zone_cnt;
    cfg.tot_bad = bad_cnt;
    cfg.tot_mv = can_mv_cnt;

    // fix any abandoned doors/zones
    // if can_mv_cnt < bad_cnt, we're going to have a problem
    while (bad_cnt != 0 && can_mv_cnt != 0) {
      bad_cnt--;
      can_mv_cnt--;
      uint32_t bad_src, bad_dst, bad_src_cmp, bad_dst_cmp,
               mv_src, mv_dst, mv_src_cmp, mv_dst_cmp;
               // <0 5> similar to above <bs mvsc>
               // <4 1>                  <mvs bsc>

      bad_src = bad_doors[bad_cnt];
      bad_src_cmp = comp_doors[bad_src];
      bad_dst = arbidoor[bad_src];
      bad_dst_cmp = comp_doors[bad_dst];

      mv_src = can_move[can_mv_cnt]; // likely non-world door
      mv_src_cmp = comp_doors[mv_src];
      mv_dst = arbidoor[mv_src];
      mv_dst_cmp = comp_doors[mv_dst]; // should be outside world door

      arbidoor[bad_src] = mv_src_cmp;
      arbidoor[mv_src] = bad_src_cmp;

      arbidoor[bad_dst_cmp] = mv_dst;
      arbidoor[mv_dst_cmp] = bad_dst;
    }
  } // if sane door - prevent abandoned zones
} // shuffle_doors()


// write doors (XTELs) in game memory. original or what's in map
void overwrite_doors(int do_orig_doors) {
  for (auto [from_door, to_door] : arbidoor) {
    uint32_t from_ptr16 = door_16_map[from_door],
             to_ptr1b = door_1b_map[do_orig_doors ? from_door : to_door];
    // this should NOT happen. but if it does you're screwed
    // if (from_ptr16 == 0 || to_ptr1b == 0) continue;
    *(uint32_t*)(from_ptr16) = to_ptr1b;
  }

  if (do_orig_doors) {
    if (player_changed) // diff seed may have diff doors
      arbidoor.clear();
    memset(found_doors, 0, TOT_DOORS * 4);
    TOT_DOORS = 0;
  }
} // overwrite doors


// save cfg used and seed file
void save_seed() {
  // going off of int size
  // but file funcs take char size typically
  uint32_t cfg_sz = sizeof(cfg) / 4,
           map_sz = arbidoor.size(),
           file_sz = cfg_sz + (map_sz * 2),
           pos = cfg_sz;

  uint32_t seed_buf[file_sz];

  cfg.tot_doors = map_sz;
  memcpy(seed_buf, &cfg, cfg_sz * 4);

  for (auto [from_door, to_door] : arbidoor) {
    seed_buf[pos++] = from_door;
    seed_buf[pos++] = to_door;
  }

  string filename = player_name;
         filename += ".arb";
  // overwrites any existing file, but shouldn't be called if it exist
  HANDLE seed_file = CreateFile(filename.c_str(), GENERIC_WRITE, 0,
                   0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
  WriteFile(seed_file, seed_buf, file_sz * 4, 0, 0);
  CloseHandle(seed_file);
} // save_seed();


// load seed file with used config
void load_seed() {
  // like save, this uses int sizes
  uint32_t file_sz = 0, file_sz_hi = 0,
           pos = sizeof(cfg) / 4;
  uint32_t seed_buf[15000]; // over sized

  string filename = player_name;
         filename += ".arb";
  HANDLE seed_file = CreateFile(filename.c_str(), GENERIC_READ, 0,
                   0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
  // the 'hi' bit should be empty
  file_sz = GetFileSize(seed_file, (LPDWORD)&file_sz_hi);

  // saftey bound check ig
  if (file_sz > 14000)
    file_sz = 13000; // 3250 * 4
  file_sz = file_sz / 4;

  ReadFile(seed_file, seed_buf, file_sz * 4, 0, 0);
  CloseHandle(seed_file);

  memcpy(&cfg, seed_buf, pos * 4); // sizeof(cfg)

  if (TOT_DOORS < cfg.tot_doors)
    return; // error, we're going to load invalid doors
  // more doors 'may' be bad, but can't be sure
  // DLC load section will check

  // map should be cleared/reset each load
  while (pos < file_sz) {
    uint32_t from_door = seed_buf[pos++],
             to_door = seed_buf[pos++];
    arbidoor[from_door] = to_door;
  }
} // load_seed()


// read the config file arbidoor.ini
void read_cfg() {
  string line, key, val;
  char cfg_buf[5000]; // should be 500 bytes, 10x less
  uint32_t line_start = 0, line_end = 0, eq_pos = string::npos,
           file_sz = 0, file_sz_hi = 0;

  HANDLE cfg_file = CreateFile("arbidoor.ini", GENERIC_READ, 0,
                   0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

  if (cfg_file != INVALID_HANDLE_VALUE) { // if open
  file_sz = GetFileSize(cfg_file, (LPDWORD)&file_sz_hi);
  ReadFile(cfg_file, cfg_buf, file_sz, 0, 0);

  while (line_end < file_sz) {
    while (cfg_buf[line_end] != '\n') // get next line
      line_end++;
    if (cfg_buf[line_end - 1] == '\r')
      cfg_buf[line_end - 1] = 0; // windows newlines do \r\n
    cfg_buf[line_end] = 0; // the \n

    line = cfg_buf+line_start;
    const unsigned char cmt_chk = line.c_str()[0];

    if ((cmt_chk >= 'a' && cmt_chk <= 'z')
       || (cmt_chk >= 'A' && cmt_chk <= 'Z') ) {

      for (int i = 0 ; i < line.length() ; i++)
        line[i] = tolower(line[i]);

      eq_pos = line.find('=');

      if (eq_pos != string::npos) {
        key = line.substr(0, eq_pos);
        val = line.substr(eq_pos+1);
        // cheating. anything that's not '1' will be 0
        int _enabled = val == "1" ? 1 : 0;
        if (key == "enabled")                    cfg.enabled = _enabled;
        else if (key == "sane_doors")            cfg.sane_doors = _enabled;
        else if (key == "fo3base_enabled")       cfg.areas_enabled[0] = _enabled;
        else if (key == "vault101child_enabled") cfg.areas_enabled[1] = _enabled;
        else if (key == "tranquility_enabled")   cfg.areas_enabled[2] = _enabled;
        else if (key == "vault87_enabled")       cfg.areas_enabled[3] = _enabled;
        else if (key == "ravenrock_enabled")     cfg.areas_enabled[4] = _enabled;
        else if (key == "anchorage_enabled")     cfg.areas_enabled[5] = _enabled;
        else if (key == "pitt_enabled")          cfg.areas_enabled[6] = _enabled;
        else if (key == "pointlookout_enabled")  cfg.areas_enabled[7] = _enabled;
        else if (key == "zeta_enabled")          cfg.areas_enabled[8] = _enabled;
        else if (key == "brokensteel_enabled")   cfg.areas_enabled[9] = _enabled;
      }
    } // if not a comment
    line_start = ++line_end;
  } // while read
  CloseHandle(cfg_file);
  } // if open
} // read_cfg()


// finds DLC IDs
// builds found_doors[] with active chosen areas/DLCs
void load_rando() {
  // !!!this is tied to 'cfg.areas_enabled[]' !!!
  // !!!keep order the same!!!
  uint32_t const *areas[] = {
    fo3base_doors,
    vault101child_doors,
    tranquility_doors,
    vault87_doors,
    ravenrock_doors,
    anchorage_doors,
    pitt_doors,
    pointlookout_doors,
    zeta_doors,
    brokensteel_doors,
    0x0
  };

  get_player_name(); // sets player_changed if we change player name

  read_cfg(); // sets cfg struct. mainly for first time seed gens.
  // or for 'enabled' for hot-dis/en-abling to un/re-randomize doors.
  // (unlikely as most ppl can't alt+tab fo3)

  if (cfg.enabled == 0) {
    player_name[0] = 0; // hack to re-trigger player_changed
    return;
  }

  if (TOT_DOORS == 0) { // memory locations may change
    find_dlc_ids(); // should be same per game start, but running at plugin load crashes
    for (int area = 0 ; areas[area] != 0x0 ; area++) {
      if (cfg.areas_enabled[area] == 1) {
        int dlc_id = 0;
        if (area >= DLC_START) {
          dlc_id = dlc_ids[area - DLC_START];
          if (dlc_id == 0)
            continue;
        }

        int added = add_doors_of(areas[area], dlc_id);
        if (added != 0) {
          memcpy(&found_doors[TOT_DOORS], areas[area], added * 4);
          TOT_DOORS += added;
        }
      } // if area enabled
    } // for areas copy doors
  } // if !TOT_DOORS

  // if we reached here, the doors were reset by pre-load wipe
  if (player_changed) {
    player_changed = 0; // prevents pre-load resets for same player
    string filename = player_name;
           filename += ".arb";
    DWORD filechk = GetFileAttributes(filename.c_str() );

    if (filechk != INVALID_FILE_ATTRIBUTES
        && !(filechk & FILE_ATTRIBUTE_DIRECTORY) )
      load_seed();
    else {
      shuffle_doors();
      save_seed(); // only save on new seed
    }
  }

  overwrite_doors(0); // MAGIC
} // load_rando


// when you load a save, the game detects changes to reset,
// like locked vs unlocked doors. it will use the original
// game's door which resets the randomized door and leaves
// you with a 1-way door.
// so sadly we must reset and re-overwrite doors every load.
// this is just a wrapper to avoid stack manip
// NOTE: this also fixes crashes when loading different
//       player saves back and forward, like 1>2>1
void reset_doors() {
  overwrite_doors(1); // nuke
}

void __declspec(naked) hijack_preload() {
  // naked = handle own stack
  // save registers
  asm volatile("pusha;"
      "push ebp;"
      "push esp;");

  reset_doors();

  asm volatile(
      "pop esp;"
      "pop ebp;"
      "popa;"); // restore fo3_load_save() stack

  // replace what we hijacked
  asm volatile("mov eax, ds:[0x0106AB70]"
    : : : "eax");
  asm volatile("ret");
} // hijack into the game via fo3_load_save() for pre-checks


void __declspec(naked) hijack_postload() {
  asm volatile("pusha;"
      "push ebp;"
      "push esp;");

  load_rando(); // loads config, seed and randomizes doors

  asm volatile(
      "pop esp;"
      "pop ebp;"
      "popa");
  asm volatile("ret 0x10"); // fo3_load_save()'s ret
} // hijack into the game via fo3_load_save() and do magic


// as far as DLLs/plugins are concerened, this is "main()"

extern "C"
{

BOOL WINAPI DllMain(HANDLE hDllHandle, DWORD dwReason, LPVOID lpreserved) {
  return TRUE;
}

// prevent mingw32 mangling to _FOSE names
bool __declspec(dllexport) FOSEPlugin_Query(const FOSEInterface *fose, PluginInfo *info) {
  info->infoVersion = PluginInfo::kInfoVersion; // static always 1 ?
  info->name = "FO3arbidoor";
  info->version = ARBVERSION;

  // since this is no longer developed, and you should always be on 1.7.0.3
  // ?? info->runtimeVersion ??? game version? could check that
  return true;
}

bool __declspec(dllexport) FOSEPlugin_Load(const FOSEInterface *fose) {
  // hijack start of fo3_load_save() function
  WriteRelCall(0x006D5756, uint32_t(hijack_preload) );
  // hijack end of fo3_load_save() function
  WriteRelJump(0x006D5915, uint32_t(hijack_postload) );
  SafeWrite32(0x006D591A, 0xCC0010C2); // replace "ret 10 ; int 3 ;"
  // should never hit this ret but i feel better replacing it anyway
  return true;
}

}; // extern C
