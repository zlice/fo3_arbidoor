#include <stdio.h>
#include <stdint.h>

#include "alldoors.h"

int main() {

uint32_t buf[3000] = {0};
int buf_i = 0, i = 0, allsz = sizeof(alldoors) / 4;

FILE *f = fopen("zeg.arb", "rb");
fread(buf, 4, 3000, f);

//while (i < 3000)
//  printf("%08X %08X\n", buf[i++], buf[i++]);

uint32_t TOT_DOORS = 1500;
uint32_t src_doors[TOT_DOORS], dst_doors[TOT_DOORS],
         src_comp = 0, dst_comp = 0,
         src_rnd = 0, dst_rnd = 0,
         comp_src_id = 0, comp_dst_id = 0;

  buf_i = 20;
  i = 0;
  //while (buf_i < buf[11] * 2) {
  while (i < buf[19]) {
    if (buf[buf_i] == 0)
      break;
    src_doors[i] = buf[buf_i];
    dst_doors[i] = buf[buf_i+1];
    printf("[%d] = %08X %08X\n", i, src_doors[i], dst_doors[i]);
    i++;
    buf_i+=2;
  }

  for (i = 0; i < buf[15] ; i++) {
    src_rnd = src_doors[i];
    dst_rnd = dst_doors[i];

    src_comp = dst_comp = 0;
    while (src_comp < allsz && dst_rnd != alldoors[src_comp])
      src_comp++;
    while (dst_comp < allsz && src_rnd != alldoors[dst_comp])
      dst_comp++;
    if (src_comp == (dst_comp ^ 1) )
      printf("ERROR 180 door [%d] - %08X == %08X\n", i, src_rnd, dst_rnd);
    comp_src_id = alldoors[src_comp ^ 1];
    comp_dst_id = alldoors[dst_comp ^ 1];

    if (src_rnd == alldoors[dst_comp ^ 1] && dst_rnd == alldoors[dst_comp ^ 1])
      printf("ERROR nowhere door pair[%d] - %08X == %08X\n", i, src_rnd, dst_rnd);

    src_comp = dst_comp = 0;
    while (src_comp < allsz && comp_src_id != src_doors[src_comp])
      src_comp++;
    while (dst_comp < allsz && comp_dst_id != dst_doors[dst_comp])
      dst_comp++;

    if (src_rnd == dst_rnd)
      printf("WARNING no-rando pair[%d] - %08X == %08X\n", i, src_rnd, dst_rnd);

    if (src_comp != dst_comp)
      printf("ERROR mismatch pair[%d] ... %08X <> %08X\n"
             "\t\t\tcompliments ... %08X --- %08X\n"
             "\t\tgot pairs\n"
             "\t\t\t src_comp [%d] %08X <> %08X\n"
             "\t\t\t dst_comp [%d] %08X <> %08X\n\n",
             i, src_rnd, dst_rnd,
             comp_src_id, comp_dst_id,
             src_comp, src_doors[src_comp], dst_doors[src_comp],
             dst_comp, src_doors[dst_comp], dst_doors[dst_comp]);
  }

return 0;
}
