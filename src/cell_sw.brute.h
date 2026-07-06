#include "cell_arr.h"

const uint32_t *get_door_cell(uint32_t door_id) {

  uint32_t cell_inc = 0, door_inc = 0;

  const uint32_t *all_cells[] = {
  cell_00002DB4, cell_00000222, cell_00000332,
  cell_00000333, cell_00000444, cell_00000555,
  cell_00000556, cell_00000557, cell_00000558,
  cell_00000777, cell_00000778, cell_00000888,
  cell_00000999, cell_00550000, cell_00000A96,
  cell_000035D3, cell_000035D4, cell_000035D5,
  cell_000035D6, cell_00003A29, cell_00003A35,
  cell_00003B85, cell_0001516F, cell_00016D9F,
  cell_00016DA1, cell_00016DA2, cell_00016DA7,
  cell_00016DA8, cell_000173EC, cell_000178B8,
  cell_00017E14, cell_00017E17, cell_00017E19,
  cell_00017F2F, cell_00017F30, cell_00017F31,
  cell_00017F33, cell_00017F34, cell_00017F37,
  cell_00017F39, cell_00017F3A, cell_00017F3B,
  cell_00017F3C, cell_00017F3D, cell_00017F40,
  cell_00017F43, cell_00017F44, cell_00017F45,
  cell_00017F46, cell_00017F47, cell_00017F48,
  cell_00017F49, cell_00017F4A, cell_00017F4C,
  cell_00017F4D, cell_00017F4E, cell_00017F51,
  cell_00017F52, cell_00017F53, cell_00017F54,
  cell_00017F55, cell_00017F57, cell_00017F59,
  cell_00017F5B, cell_00017F5F, cell_00017F61,
  cell_00017F64, cell_00017F67, cell_0001845D,
  cell_00018461, cell_00018464, cell_0001851F,
  cell_00018522, cell_00018523, cell_00018529,
  cell_0001852A, cell_0001852B, cell_0001852D,
  cell_00018530, cell_00018532, cell_00018533,
  cell_00018534, cell_00018536, cell_00018537,
  cell_00018538, cell_00018539, cell_0001853A,
  cell_0001853B, cell_00019FBB, cell_0001A270,
  cell_0001A271, cell_0001A272, cell_0001A273,
  cell_0001A274, cell_0001A276, cell_0001A281,
  cell_0001A283, cell_0001A284, cell_0001A285,
  cell_0001A286, cell_0001A287, cell_0001A288,
  cell_0001A28C, cell_0001A28D, cell_0001A28E,
  cell_0001A292, cell_0001B478, cell_0001BA01,
  cell_0001BA03, cell_0001BC8A, cell_0001BC8B,
  cell_0001BC8D, cell_0001BC8F, cell_0001BC90,
  cell_0001BC91, cell_0001BC93, cell_0001BC95,
  cell_0001BC98, cell_0001BC99, cell_0001BC9A,
  cell_0001D6A3, cell_0001D6AA, cell_0001D6AB,
  cell_0001E0F1, cell_00020F90, cell_00020F91,
  cell_0002107F, cell_0002263C, cell_0002263D,
  cell_00022D92, cell_00023226, cell_000235F1,
  cell_000236DB, cell_000244AA, cell_000244BE,
  cell_00024511, cell_00024513, cell_00024D6B,
  cell_00024D6C, cell_00024D71, cell_00024D78,
  cell_00024D79, cell_00024D7B, cell_000252DA,
  cell_0002798D, cell_00028138, cell_00029AAB,
  cell_0002A58A, cell_0002AFAF, cell_0002AFB0,
  cell_0002B952, cell_0002D0E2, cell_0002D0E4,
  cell_0002D0E5, cell_0002D0E6, cell_0002D6EE,
  cell_0002D743, cell_0002DC04, cell_0002F22B,
  cell_0002F69E, cell_00033B0B, cell_00039E38,
  cell_0003ABF8, cell_0003BC89, cell_0003C83E,
  cell_0003C944, cell_0003D444, cell_0003D445,
  cell_000406AE, cell_000406AF, cell_00041FDD,
  cell_0004363B, cell_0004363E, cell_000459CD,
  cell_0004AEC3, cell_0004C4E6, cell_0004D4BB,
  cell_0004DD5B, cell_0004DD8A, cell_0004DD8B,
  cell_000508E6, cell_00051245, cell_00051E79,
  cell_00051E7A, cell_00051E7B, cell_0005559E,
  cell_00064BF0, cell_00067488, cell_0006F9F8,
  cell_0007523C, cell_0007684A, cell_00082DF9,
  cell_00084305, cell_00098736, cell_00099E9B,
  cell_00099E9D, cell_0009DF08, cell_000AB546,
  cell_000BC4C2, cell_000BC4C3, cell_000C568B,
  cell_000C568C, cell_000C99FC, cell_01002738,
  cell_00015157, cell_00015158, cell_00018520,
  cell_00018521, cell_0001A26E, cell_0001A28B,
  cell_0001BC8E, cell_000207A2, cell_00045219,
  cell_0004F4E1, cell_00074EB2, cell_00076DA3,
  cell_00095B7A, cell_01000805, cell_01000806,
  cell_0100106C, cell_010011C3, cell_01003D64,
  cell_01004418, cell_010045B2, cell_0100731E,
  cell_0100739A, cell_01008A0F, cell_0100133A,
  cell_0100133B, cell_0100133F, cell_0100602C,
  cell_01007D87, cell_01003E25, cell_01004E2D,
  cell_01008120, cell_01008122, cell_01008123,
  cell_0100D6AF, cell_0100DF23, cell_0100F05A,
  cell_0100F28F, 0x0, };

  //while (all_cells[cell_inc] != 0) {
  //  while (all_cells[cell_inc][door_inc] != 0) {
  //    if (all_cells[cell_inc][door_inc] == door_id)
  //      return all_cells[cell_inc];
  //    door_inc++;
  //  }
  //  door_inc = 0;
  //  cell_inc++;
  //}
  while (all_cells[cell_inc]) {
    if (all_cells[cell_inc][door_inc] == door_id)
      return all_cells[cell_inc];
    door_inc++;
    if (all_cells[cell_inc][door_inc] == 0) {
      door_inc = 0;
      cell_inc++;
    }
  }
  //const uint32_t *crawl_cell = all_cells[0];
  //while (crawl_cell != 0) {
  //  while (crawl_cell[door_inc] != 0) {
  //    if ((uint32_t)crawl_cell[door_inc++] == door_id)
  //      return crawl_cell;
  //  }

  //  door_inc = 0;
  //  cell_inc++;
  //  crawl_cell = all_cells[cell_inc];
  //}

  return 0;
};
