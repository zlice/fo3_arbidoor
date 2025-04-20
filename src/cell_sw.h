#include "cell_arr.h"

const uint32_t *get_door_cell(uint32_t door_id) {
  switch (door_id) {
  case 0xFF005691: case 0x00043B8B: case 0x0001DFEA:
  case 0xFF0043A3: case 0xFF0068E6: case 0xFF00734D:
  case 0x000155F5: case 0x00026D27: case 0x0001C27A:
  case 0x000C3CF6: case 0x000A2433: case 0x0007E093:
  case 0x0007D404: case 0x0006A820: case 0x00059503:
  case 0x000594C2: case 0x0003DA4F: case 0x0002EE95:
  case 0x0002EED6: case 0x0002EED7: case 0x0002EE93:
  case 0x000184F7: case 0x000184F5: case 0x000183DB:
  case 0x000183D8: case 0x000183D5: case 0x000183D2:
  case 0x000183CF: case 0x000183C9: case 0x000183B1:
  case 0x000183AE: case 0x00017473: case 0x0001707F:
  case 0x00017083: case 0x00017084: case 0x00003B24:
  case 0x00018613: case 0x00018616: case 0x0001BCD3:
  case 0x0001BD36: case 0x0001BD41: case 0x0001D5FE:
  case 0x0001D5FF: case 0x00017411: case 0x00017A17:
  case 0x00019B4E: case 0x0001DA16: case 0x0001E352:
  case 0x0001E984: case 0x0001E987: case 0x00023609:
  case 0x0002363E: case 0x0002360A: case 0x00025420:
  case 0x0002ABBA: case 0x0002ABB9: case 0x0002ABB8:
  case 0x0002ABBB: case 0x00028528: case 0x00028529:
  case 0x0002B0F8: case 0x0002B0FC: case 0x0002B0FD:
  case 0x0002B0FE: case 0x0002B8D1: case 0x0002DCD9:
  case 0x0002DB45: case 0x0002DCDD: case 0x0002DCDE:
  case 0x0002DCE0: case 0x0002DED7: case 0x0002DED8:
  case 0x0002E03C: case 0x0002E0E4: case 0x0002E5E4:
  case 0x0002FCC7: case 0x00030602: case 0x0003C840:
  case 0x0003C841: case 0x0003C847: case 0x0003C948:
  case 0x0003C949: case 0x0003BD8C: case 0x0003C2FA:
  case 0x0003D447: case 0x000433AC: case 0x00043B8A:
  case 0x00044B12: case 0x00044B14: case 0x00044D09:
  case 0x00048190: case 0x00048191: case 0x00048192:
  case 0x00048306: case 0x0004CCE9: case 0x0004CCEA:
  case 0x0004D030: case 0x0004D031: case 0x0004E73A:
  case 0x0004F135: case 0x0004F656: case 0x00050F55:
  case 0x00051466: case 0x00051467: case 0x0005364D:
  case 0x000560EC: case 0x000560F4: case 0x0004021A:
  case 0x00042F27: case 0x0004E1C4: case 0x00057E2A:
  case 0x00058BFB: case 0x0003F535: case 0x0003F538:
  case 0x0005AAB5: case 0x0005AB78: case 0x0005D863:
  case 0x00063B37: case 0x00063B72: case 0x000687CD:
  case 0x00068C88: case 0x0006A17B: case 0x0006C247:
  case 0x0007012B: case 0x000752C9: case 0x000752CA:
  case 0x00079F14: case 0x00089C77: case 0x0006F6A6:
  case 0x00093706: case 0x00098744: case 0x0003DFC6:
  case 0x0009C4CB: case 0x0009DF52: case 0x0009DF53:
  case 0x000A5E88: case 0x000A6F41: case 0x0005DD39:
  case 0x000B36E4: case 0x000B5F0B: case 0x000B754F:
  case 0x000B7550: case 0x000B754E: case 0x00018E56:
  case 0x000190F2: case 0x000B548B: case 0x0001FC8F:
  case 0x00023603: case 0x000B9E64: case 0x00024ECA:
  case 0x0002A344: case 0x00017281: case 0x0002DF06:
  case 0x00039272: case 0x00039391: case 0x000392A7:
  case 0x0003E897: case 0x0003EE0D: case 0x00061520:
  case 0x00061BB7: case 0x00064C00: case 0x00070C6C:
  case 0x00076E43: case 0x00076E46: case 0x00076E49:
  case 0x000A3422: case 0x000C25A7: case 0x000C25EA:
  case 0x000C2677: case 0x000C2727: case 0x000C27B0:
  case 0x000C27BB: case 0x000C30AF: case 0x000C3C1C:
  case 0x000C84C5: case 0x0005608F: case 0x000494D2:
  case 0x00049C94: case 0x000CA776: case 0x000CA9F7:
  case 0x0009CA2A: case 0x0009DBB2: case 0x000A4291:
  case 0x00044C5E: case 0x0004E776: case 0x0005281B:
  case 0x00049135: case 0x00054CDD: case 0x00054DEF:
  case 0x00056ECC: case 0x000C991F: case 0x0005C1E0:
  case 0x00022F27: case 0x0006744D: case 0x0006753C:
  case 0x0005C28B: case 0x0004C6CA: case 0x0004960E:
  case 0xFF0009A9: case 0x0004B9DD: case 0x0009B5A0:
  return cell_00002DB4;

  case 0x0002A144: case 0x0002A14E:
  return cell_00000222;

  case 0x0007684E: case 0x0007684D:
  return cell_00000332; // bot inside cell is 0007684A

  case 0x00076E41: case 0x00076E48:
  return cell_00000333;

  case 0x00064BFD: case 0x00064D38:
  return cell_00000444;

  case 0x000C3D33: case 0x000C3D34:
  return cell_00000555;

  case 0x00076E42: case 0x00076E44:
  return cell_00000556;

  case 0x000C3EA3: case 0x000C3EA4:
  return cell_00000557;

  case 0x000C3EA5: case 0x000C3CF2:
  return cell_00000558;

  case 0x0004E019: case 0x0004E01A:
  return cell_00000777;

  case 0x000503B7: case 0x00050D36:
  return cell_00000778;

  case 0x0004CEF7: case 0x0004CEF8:
  return cell_00000888;

  case 0x0002541E: case 0x0002541F:
  return cell_00000999;

  case 0x000039B7: case 0x00003A12: case 0x00003A14:
  case 0x00003A15: case 0x00003A16: case 0x00003A19:
  case 0x00003A1C: case 0x00003A1D: case 0x00003A1F:
  case 0x00003A23: case 0x00003A24: case 0x00003A25:
  case 0x00003A26: case 0x00003A81: case 0x00003B2C:
  case 0x00003B39: case 0x00003F7D: case 0x0000435C:
  case 0x00002DFF: case 0x00014E1A:
  return cell_00000A96;

  case 0x0006B0A8: case 0x00014FDC: case 0x00014FDD:
  case 0x000BBB5F: case 0x000BBB6B:
  return cell_000035D3;

  case 0x000038B9: case 0x000038B8:
  return cell_000035D4;

  case 0x0000374D: case 0x0000374E:
  return cell_000035D5;

  case 0x000036C6: case 0x000036C7:
  return cell_000035D6;

  case 0x00003A4F: case 0x00003F7E:
  return cell_00003A29;

  case 0x00003F8E: case 0x00003A5F:
  return cell_00003A35;

  case 0x00003C51: case 0x00003C72:
  return cell_00003B85;

  case 0x0001FA59: case 0x0001FA3A:
  return cell_0001516F;

  case 0x0007DD37: case 0x000173EF:
  return cell_00016D9F;

  case 0x0006184D: case 0x000172F6:
  return cell_00016DA1;

  case 0x0001727D: case 0x0001727C:
  return cell_00016DA2;

  case 0x00053C9A: case 0x00053C9B:
  return cell_00016DA7;

  case 0x00052F32: case 0x00052F33:
  case 0x000170FD:
  return cell_00016DA8;

  case 0x000B5CE6: case 0x000B5CFB:
  return cell_000173EC;

  case 0x000178BF: case 0x0001798C: case 0x00017972:
  return cell_000178B8;

  case 0x0004F2C8: case 0x00044DA7:
  return cell_00017E14;

  case 0x00017ECB: case 0x00017ECA:
  return cell_00017E17;

  case 0x00035B6E: case 0x00047E6F:
  return cell_00017E18;

  case 0x00035B81: case 0x00035B80:
  return cell_00017E19;

  case 0x00018396: case 0x00018397:
  return cell_00017F2F;

  case 0x00018389: case 0x0001838A:
  return cell_00017F30;

  case 0x0001837B: case 0x0001837C: case 0x0001837D:
  return cell_00017F31;

  case 0x000178C0: case 0x0001835E:
  return cell_00017F33;

  case 0x000172E7: case 0x000173CB:
  case 0x00018351: case 0x00021FB6:
  return cell_00017F34;

  case 0x000414F6: case 0x000414F7:
  return cell_00017F37;

  case 0x000882F5: case 0x00018308: case 0x00018309:
  return cell_00017F39;

  case 0x000882F6: case 0x00059A0B:
  case 0x000182FA: case 0x000182FC:
  return cell_00017F3A;

  case 0x0003B1D2: case 0x000182EA:
  return cell_00017F3B;

  case 0x000182DD: case 0x000182DE: case 0x0003BCC5:
  return cell_00017F3C;

  case 0x0003B371: case 0x0002A019: case 0x000182CF:
  return cell_00017F3D;

  case 0x000182A4: case 0x000182A6:
  return cell_00017F40;

  case 0x0002BCA0: case 0x0002BCAD:
  case 0x0001827B: case 0x0001B8B0:
  return cell_00017F43;

  case 0x00018269: case 0x0001826A:
  return cell_00017F44;

  case 0x0001825C: case 0x0001825D:
  return cell_00017F45;

  case 0x0001824E: case 0x0001824F: case 0x00018250:
  return cell_00017F46;

  case 0x00050B84: case 0x00050BEA: case 0x00050BEC:
  return cell_00017F47;

  case 0x00050090: case 0x000509FC: case 0x00050A17:
  case 0x00050A18: case 0x00050BEB: case 0x000514D2:
  return cell_00017F48;

  case 0x0005092E: case 0x00051465:
  return cell_00017F49;

  case 0x00018214: case 0x00029930:
  return cell_00017F4A;

  case 0x000181F9: case 0x000181FA: case 0x00029932:
  return cell_00017F4C;

  case 0x0002A93C: case 0x000181F3: case 0x000181F4:
  return cell_00017F4D;

  case 0x000181E6: case 0x000181E7: case 0x0002DD62:
  return cell_00017F4E;

  case 0x000181B0: case 0x000181B1:
  return cell_00017F51;

  case 0x000181A2: case 0x000181A3: case 0x000181A4:
  return cell_00017F52;

  case 0x00018192: case 0x00018193:
  return cell_00017F53;

  case 0x00018185: case 0x00018186:
  return cell_00017F54;

  case 0x00018177: case 0x00018178: case 0x00018179:
  return cell_00017F55;

  case 0x00024A08: case 0x00043F60:
  return cell_00017F57;

  case 0x0001813C: case 0x000547B2:
  return cell_00017F59;

  case 0x00018121: case 0x00018122: case 0x00039393:
  return cell_00017F5B;

  case 0x0003D824: case 0x0003D811:
  return cell_00017F5F;

  case 0x000A5401: case 0x0003D3DF: case 0x0003D22A:
  return cell_00017F61;

  case 0x0002CAFB: case 0x000180A3:
  return cell_00017F64;

  case 0x00039B70: case 0x00018080:
  return cell_00017F67;

  case 0x00042039: case 0x0004202D: case 0x0004203C:
  return cell_0001845D;

  case 0x00074F5A: case 0x0001741A:
  case 0x00004440: case 0x000184D6:
  return cell_00018461;

  case 0x00044B13: case 0x00044B11: case 0x00044AA6:
  return cell_00018464;

  case 0x0001865B: case 0x0001865C:
  return cell_0001851F;

  case 0x00003BB5: case 0x00003BBA:
  return cell_00018522;

  case 0x0001D877: case 0x00018634: case 0x00018635:
  return cell_00018523;

  case 0x00018608: case 0x00018609:
  return cell_00018528;

  case 0x000185FA: case 0x000185FB:
  return cell_00018529;

  case 0x0002F4CD: case 0x0002F4CA:
  return cell_0001852A;

  case 0x00093FC2: case 0x0003ACEF: case 0x0003AD0E:
  case 0x0003AD1C: case 0x0003AE20: case 0x0003AD1F:
  case 0x0003AD1D: case 0x000A39A1:
  return cell_0001852B;

  case 0x000317B5: case 0x00030B1E: case 0x00030B00:
  return cell_0001852D;

  case 0x000317A4: case 0x000317B4:
  return cell_00018530;

  case 0x0003AD3A: case 0x0003ADA6:
  return cell_00018532;

  case 0x0003179F: case 0x0003179C:
  return cell_00018533;

  case 0x00018617: case 0x00053671:
  return cell_00018534;

  case 0x000356CB: case 0x00018589:
  return cell_00018536;

  case 0x00021026: case 0x0002F4D4:
  return cell_00018537;

  case 0x0003ADAF: case 0x0003ADF4:
  return cell_00018538;

  case 0x0001E33B: case 0x0001E339:
  return cell_00018539;

  case 0x0001E33A: case 0x0001E338: case 0x0001E337:
  return cell_0001853A;

  case 0x000AEC1B: case 0x0001E351:
  return cell_0001853B;

  case 0x00053EEE: case 0x00053E41: case 0x00053E3C:
  return cell_00019FBB;

  case 0x0005043B: case 0x0001B9BE: case 0x0005032A:
  case 0x0005036C: case 0x000503A9:
  return cell_0001A270;

  case 0x000AE886: case 0x0001B9D7:
  return cell_0001A271;

  case 0x0001B9D4: case 0x0001B9D5:
  return cell_0001A272;

  case 0x000B5158: case 0x0007F7E3: case 0x0001B9CC:
  return cell_0001A273;

  case 0x00050D35: case 0x00050D6A: case 0x00050C53:
  case 0x00050C54: case 0x0001B9E4: case 0x00050299:
  return cell_0001A274;

  case 0x0002F14B: case 0x0002F8A2:
  case 0x0002F8A1: case 0x0005B3B3:
  return cell_0001A276;

  case 0x0001B928: case 0x0001B929:
  return cell_0001A281;

  case 0x0001B5C6: case 0x00035EA3: case 0x00034FB1:
  return cell_0001A283;

  case 0x0001B738: case 0x0001B90F:
  case 0x0001B910: case 0x0001BD24:
  return cell_0001A284;

  case 0x0001B900: case 0x0001B901: case 0x0001ED98:
  return cell_0001A285;

  case 0x0001B64E: case 0x0001B8FC:
  return cell_0001A286;

  case 0x0001B8EC: case 0x0001B8ED: case 0x000446E7:
  return cell_0001A287;

  case 0x00061AB3: case 0x0001B8E8: case 0x000603FE:
  return cell_0001A288;

  case 0x0003ED59: case 0x0001B8BE: case 0x0001B8C9:
  case 0x0001B8CA: case 0x0001B8CC:
  return cell_0001A28C;

  case 0x0001B8B8: case 0x0001B8B9:
  return cell_0001A28D;

  case 0x000959B9: case 0x0002A129:
  case 0x0001B8AD: case 0x0001B8AF:
  case 0x0002B5D4: case 0x00032EC1: case 0x0001B5EF:
  case 0x0001B5F1: case 0x0001B60D: case 0x0001B615:
  return cell_0001A28E;

  case 0x0001B764: case 0x0001B6F0: case 0x0001B89E:
  case 0x0001B89D: case 0x00033CB1: case 0x0003E648:
  case 0x000B5EB5: case 0x000C8129: case 0x0006A9D3:
  return cell_0001A292;

  case 0x0001B834: case 0x0001B833:
  return cell_0001B478;

  case 0x0001BA98: case 0x0001B816: case 0x00022BBC:
  case 0x00022D93: case 0x00022D94: case 0x000BC433:
  case 0x0001B7D4:
  return cell_0001BA01;

  case 0x0001FA1D: case 0x0001FA36:
  case 0x0001F6BD: case 0x0005AE0C:
  return cell_0001BA03;

  case 0x0001BD50: case 0x0001B79A: case 0x0001B7ED:
  case 0x0003EEA5: case 0x00061F70: case 0x000CC22A:
  return cell_0001BC8A;

  case 0x00038D5C: case 0x0001B7D0: case 0x00003417:
  return cell_0001BC8B;

  case 0x0006151A: case 0x000603F3:
  return cell_0001BC8D;

  case 0x0003EE77: case 0x0001BD21: case 0x0001BD22:
  return cell_0001BC8F;

  case 0x0001BD18: case 0x0001BD23: case 0x0003354A:
  case 0x00033EE5: case 0x0001B766: case 0x00049FDE:
  case 0x0004F2AF: case 0x00061F92: case 0x000658C8:
  return cell_0001BC90;

  case 0x000C0A69: case 0x0001BD17: case 0x0001C85B:
  case 0x000314CA: case 0x0001B5EE: case 0x000B16AD:
  return cell_0001BC91;

  case 0x00025CD0: case 0x00025F72:
  case 0x0004423F: case 0x00044248:
  return cell_0001BC93;

  case 0x000AE871: case 0x0004F2AE:
  case 0x00054A3A: case 0x0002F3F0:
  return cell_0001BC95;

  case 0x0001BCD4: case 0x0004DD32: case 0x0004DD33:
  case 0x0004DB4A: case 0x0004DB49: case 0x0004DB4B:
  case 0x0006D994: case 0x0007C608:
  return cell_0001BC98;

  case 0x0006C246: case 0x0001BCD1:
  return cell_0001BC99;

  case 0x0004F23C: case 0x0004F263:
  return cell_0001BC9A;

  case 0x00029043: case 0x0004EF72: case 0x0004EF67:
  case 0x0004EF5D: case 0x0004EF4D: case 0x0001E986:
  case 0x0001DA1E: case 0x0001DA41: case 0x0001DA74:
  return cell_0001D6A3;

  case 0x00051271: case 0x00053E1F:
  case 0x00053E20: case 0x00053E71:
  return cell_0001D6AA;

  case 0x00053E8E: case 0x00053E9B: case 0x00053E8F:
  return cell_0001D6AB;

  case 0x0001E336: case 0x000AEB62:
  return cell_0001E0F1;

  case 0x00020FD8: case 0x00020FD9:
  return cell_00020F90;

  case 0x0004561C: case 0x0004561F: case 0x00045268:
  case 0x0002D96C: case 0x0002FA9E: case 0x0002FB26:
  return cell_00020F91;

  case 0x00053D2E: case 0x00053D1B:
  case 0x00029080: case 0x000594C1:
  return cell_0002107F;

  case 0x0002270C: case 0x0002270B:
  case 0x0002270A: case 0x0004C6C8:
  return cell_0002263C;

  case 0x0002268C: case 0x0002268B:
  return cell_0002263D;

  case 0x0004C333: case 0x00022650:
  return cell_0002263E;

  case 0x00022DB8: case 0x00022DB9:
  return cell_00022D92;

  case 0x00023240: case 0x0002324D:
  case 0x0002324B: case 0x0002325F:
  return cell_00023226;

  case 0x0002366C: case 0x000236AD:
  return cell_000235F1;

  case 0x0003A572: case 0x0001F1FA:
  case 0x0003AF6D: case 0x00096177:
  return cell_000236DB;

  case 0x00024CAF: case 0x000298D1:
  return cell_000244AA;

  case 0x00024BE9: case 0x00024BF7: case 0x00024C0A:
  case 0x00024C1D: case 0x00024C40: case 0x0002B536:
  return cell_000244BE;

  case 0x0005398D: case 0x0005398B: case 0x00052196:
  return cell_00024511;

  case 0x000253FD: case 0x0002541D:
  return cell_00024513;

  case 0x00095E92: case 0x00095E91: case 0x00095E57:
  case 0x00095E58: case 0x00095E59: case 0x00095E5A:
  case 0x00024E1B:
  return cell_00024D6B;

  case 0x00095EB4: case 0x00095EB5:
  return cell_00024D6C;

  case 0x00024DF1: case 0x00038B3F:
  return cell_00024D71;

  case 0x00063B71: case 0x00063B70: case 0x0002796D:
  return cell_00024D78;

  case 0x00063B2B: case 0x00028001:
  return cell_00024D79;

  case 0x0002DCA0: case 0x0002DC9F:
  return cell_00024D7B;

  case 0x0002544A: case 0x0001C1B7:
  return cell_000252DA;

  case 0x00027DEE: case 0x00027E32:
  return cell_0002798D;

  case 0x00054285: case 0x000290D8: case 0x0009DB79:
  return cell_00028138;

  case 0x0002A328: case 0x0002A088:
  return cell_00029AAB;

  case 0x0006BA8E: case 0x00047E36:
  return cell_0002A58A;

  case 0x00095E93: case 0x00095E94:
  return cell_0002AFAF;

  case 0x00095E8F: case 0x00095E8E:
  return cell_0002AFB0;

  case 0x0002BD2B: case 0x0002BCAE:
  return cell_0002B952;

  case 0x000482CF: case 0x000482CE: case 0x000482CD:
  return cell_0002D0E2;

  case 0x0002D204: case 0x0002D205:
  return cell_0002D0E4;

  case 0x0004CFA3: case 0x0004CD80:
  case 0x0004CDAA: case 0x0004CD24:
  return cell_0002D0E5;

  case 0x0002D15E: case 0x0002D230: case 0x00069FC3:
  return cell_0002D0E6;

  case 0x0004AEA2: case 0x0002D775:
  return cell_0002D6EE;

  case 0x0002DBD8: case 0x0002DBE1:
  return cell_0002D743;

  case 0x0002DC39: case 0x0002DC38:
  return cell_0002DC04;

  case 0x0002F526: case 0x0002F533: case 0x0002F534:
  case 0x0002F535: case 0x0002F53E: case 0x0002F53F:
  case 0x00038B3D: case 0x000695E2: case 0x0006EC68:
  return cell_0002F22B;

  case 0x0002F897: case 0x0002F899: case 0x0002F898:
  return cell_0002F69E;

  case 0x0004EDAB: case 0x0004E6D1:
  return cell_00033B0B;

  case 0x00039E44: case 0x0003A245:
  return cell_00039E38;

  case 0x0003AE6F: case 0x0003AE79:
  return cell_0003ABF8;

  case 0x0003BCF7: case 0x0003BCE7:
  return cell_0003BC89;

  case 0x00096D8B: case 0x0003C8B0:
  return cell_0003C83E;

  case 0x0003C96F: case 0x0003C99C: case 0x0003C99E:
  return cell_0003C944;

  case 0x0003D68F: case 0x0003D583:
  return cell_0003D444;

  case 0x0003D44A: case 0x0003D51A:
  return cell_0003D445;

  case 0x000A5E2D: case 0x000407D7:
  return cell_000406AE;

  case 0x000A5E83: case 0x00040710:
  return cell_000406AF;

  case 0x000420E8: case 0x000420EA:
  return cell_00041FDD;

  case 0x00043DD5: case 0x00043DD6:
  return cell_0004363B;

  case 0x00043CC2: case 0x00043CC3:
  return cell_0004363E;

  case 0x00045AC4: case 0x00045A1B:
  return cell_000459CD;

  case 0x0004B3F3: case 0x0004B3FA:
  return cell_0004AEC3;

  case 0x00050395: case 0x0004CAA8: case 0x0004CAA9:
  return cell_0004C4E6;

  case 0x0005634C: case 0x00062E9B:
  return cell_0004D4BB;

  case 0x0004E89C: case 0x0004E8E6:
  return cell_0004DD5B;

  case 0x0004DDC1: case 0x0004DDC2:
  return cell_0004DD8A;

  case 0x0006DBAB: case 0x0006DB9A: case 0x0006DB38:
  case 0x0004E7E7: case 0x0004E7E8:
  return cell_0004DD8B;

  case 0x000509E3: case 0x000509E2: case 0x000509DF:
  return cell_000508E6;

  case 0x000513D1: case 0x000513D0: case 0x000513CF:
  case 0x000513B3: case 0x000513AC:
  return cell_00051245;

  case 0x00051EB6: case 0x00051EB7:
  return cell_00051E79;

  case 0x00051E94: case 0x00051E93:
  return cell_00051E7A;

  case 0x00051E81: case 0x00051E82:
  return cell_00051E7B;

  case 0x00056D22: case 0x00056975:
  return cell_0005559E;

  case 0x00064CBC: case 0x00064C5C:
  return cell_00064BF0;

  case 0x00068C84: case 0x000689C3:
  return cell_00067488;

  case 0x00070B96: case 0x00070C6A:
  return cell_0006F9F8;

  case 0x000752D9: case 0x000752D8: case 0x000752D7:
  return cell_0007523C;

  case 0x0007684C: case 0x0007684B:
  return cell_0007684A;

  case 0x00064D20: case 0x00064D27:
  return cell_00082DF9;

  case 0x00085878: case 0x00085877:
  return cell_00084305;

  case 0x00098737: case 0x00098738:
  return cell_00098736;

  case 0x000BB795: case 0x000B5A74:
  case 0x000B5A7E: case 0x000B5AA4:
  return cell_00099E9B;

  case 0x000B5756: case 0x000B5718: case 0x000B57FF:
  case 0x000B5715: case 0x000B5742:
  return cell_00099E9D;

  case 0x0009DF50: case 0x0009DF51:
  return cell_0009DF08;

  case 0x000A0D80: case 0x000A2432: case 0x0006BAAC:
  return cell_000A0C3C;

  case 0x000AB579: case 0x000AB578:
  return cell_000AB546;

  case 0x000BC6D0: case 0x000BC6D1:
  return cell_000BC4C2;

  case 0x000BC527: case 0x000BC4D1:
  return cell_000BC4C3;

  case 0x000C585D: case 0x000C578E: case 0x000C578D:
  return cell_000C568B;

  case 0x000C5863: case 0x000C5785:
  return cell_000C568C;

  case 0x000C9A46: case 0x000C99FD:
  return cell_000C99FC;

  case 0xFF00287E: case 0xFF00288B:
  return cell_01002738;

  case 0x00020A5F: case 0x00020A6C:
  return cell_00015157;

  case 0x0001560D: case 0x00015622:
  case 0x00020AE1: case 0x0002377D:
  return cell_00015158;

  case 0x00018652: case 0x0001C984:
  return cell_00018520;

  case 0x00018649: case 0x0001BD73:
  case 0x0001CC21: case 0x0001DF0E:
  return cell_00018521;

  case 0x0001B9FC: case 0x000BB74C:
  return cell_0001A26E;

  case 0x0001B5BA: case 0x0001B8CD: case 0x0001B8CE:
  case 0x00076E3E: case 0x00076E72: case 0x000BB0C3:
  case 0x000BB0B4: case 0x000BB0B7: case 0x000BB1E0:
  return cell_0001A28B;

  case 0x000401D3: case 0x00022F26: case 0x0002325B:
  case 0x00023260: case 0x00022F16: case 0x00027DD3:
  case 0x00027DE6: case 0x0004BC2F: case 0x000606B7:
  case 0x0006937A: case 0x00041562: case 0x000A4B13:
  case 0x000AE889: case 0x0001B5B5: case 0x0001B5B6:
  return cell_0001BC8E;

  case 0x000209C4: case 0x000209C5: case 0x00020A5C:
  case 0x00020A5D: case 0x00020A5E:
  return cell_000207A2;

  case 0x000453EB: case 0x0004566A: case 0x000506E1:
  return cell_00045219;

  case 0x0004F756: case 0x0004F757:
  return cell_0004F4E1;

  case 0x00074EDE: case 0x0007D75F: case 0x000B037B:
  return cell_00074EB2;

  case 0x00076E5A: case 0x00076E68:
  return cell_00076DA3;

  case 0xFF0020A3: case 0x0002A273: case 0x00095F5B:
  return cell_00095B7A;

  case 0xFF0028BC: case 0xFF003293:
  case 0xFF002349: case 0xFF00234A:
  return cell_01000805;

  case 0xFF00248F: case 0xFF006EF9:
  return cell_01000806;

  case 0xFF000FC9: case 0xFF0022ED: case 0xFF0022F9:
  case 0xFF00248B: case 0xFF00248C: case 0xFF00444D:
  return cell_0100106C;

  case 0xFF00248A: case 0xFF00248D:
  case 0xFF006EFA: case 0xFF006EFB:
  return cell_010011C3;

  case 0xFF00406A: case 0xFF00406B: case 0xFF00406E:
  return cell_01003D64;

  case 0xFF004448: case 0xFF004449:
  return cell_01004418;

  case 0xFF0045B3: case 0xFF0045B4:
  return cell_010045B2;

  case 0xFF00733F: case 0xFF007340:
  return cell_0100731E;

  case 0xFF007CA6: case 0xFF00BE0C:
  return cell_0100739A;

  case 0xFF008A10: case 0xFF008A11:
  return cell_01008A0F;

  case 0xFF00150F: case 0xFF0094A7:
  return cell_0100133A;

  case 0xFF001505: case 0xFF001507: case 0xFF00602D:
  case 0xFF00602E: case 0xFF006973: case 0xFF00A36E:
  return cell_0100133B;

  case 0xFF00150A: case 0xFF00150E: case 0xFF009AFE:
  return cell_0100133F;

  case 0xFF0060A0: case 0xFF0061B2:
  return cell_0100602C;

  case 0xFF007E01: case 0xFF007E02:
  return cell_01007D87;

  case 0xFF006BE5: case 0xFF0081ED: case 0xFF008311:
  case 0xFF008312: case 0xFF00AFEC: case 0xFF00B5D3:
  case 0xFF00A55C: case 0xFF00B57E: case 0xFF00BF62:
  case 0xFF00C0B3: case 0xFF0088F2: case 0xFF00C50D:
  case 0xFF00C532: case 0xFF00C0B8: case 0xFF00C0B9:
  case 0xFF00C0BA: case 0xFF00D202: case 0xFF00D6B1:
  case 0xFF00DA2E: case 0xFF00DDD6: case 0xFF00DF5A:
  case 0xFF00DDFB: case 0xFF00E27E: case 0xFF00B2D2:
  case 0xFF00BFF8: case 0xFF00C04A: case 0xFF00CDD8:
  case 0xFF00CDDB: case 0xFF00CDE8: case 0xFF00A55B:
  case 0xFF00B14E: case 0xFF00F030: case 0xFF00A546:
  case 0xFF00A54A: case 0xFF011FA2: case 0xFF00583B:
  case 0xFF00643D: case 0xFF006B69: case 0xFF007AFA:
  case 0xFF00AE73: case 0xFF00B86B:
  return cell_01003E25;

  case 0xFF004E71: case 0xFF004F15:
  return cell_01004E2D;

  case 0xFF008214: case 0xFF00EDB0:
  return cell_01008120;

  case 0xFF0081C2: case 0xFF008869: case 0xFF00F7B3:
  return cell_01008122;

  case 0xFF0081C0: case 0xFF0081C1:
  return cell_01008123;

  case 0xFF00D6BE: case 0xFF00DF58:
  return cell_0100D6AF;

  case 0xFF00DF24: case 0xFF00DF25:
  return cell_0100DF23;

  case 0xFF00F080: case 0xFF00F082:
  return cell_0100F05A;

  case 0xFF00E17E: case 0xFF009B7A:
  return cell_0100F28F;

  default: return 0;
  } // switch
};
