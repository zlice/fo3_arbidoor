// a list of all doors per cell
// any 'house' (or otherwise 1 door cell) is not listed
// any quest locked doors that were excluded from randomizing are exluded here too
// any 'unreachable' door is treated as a 'house' or 1 door cell, which ends up
// removing some cells.
// unreachable typically means it hits a cell/world map but is on a balcony
// e.g. tenpennys upper tower outisde, or rivet cities weird balconies outside

// all roads must lead to rome
const uint32_t cell_00002DB4[] = {
  0xFF005691, 0x00043B8B, 0x0001DFEA, 0xFF0043A3, 0xFF0068E6,
  0xFF00734D, 0x000155F5, 0x00026D27, 0x0001C27A, 0x000C3CF6,
  0x000A2433, 0x0007E093, 0x0007D404, 0x0006A820, 0x00059503,
  0x000594C2, 0x0003DA4F, 0x0002EE95, 0x0002EED6, 0x0002EED7,
  0x0002EE93, 0x000184F7, 0x000184F5, 0x000183DB, 0x000183D8,
  0x000183D5, 0x000183D2, 0x000183CF, 0x000183C9, 0x000183B1,
  0x000183AE, 0x00017473, 0x0001707F, 0x00017083, 0x00017084,
  0x00003B24, 0x00018613, 0x00018616, 0x0001BCD3, 0x0001BD36,
  0x0001BD41, 0x0001D5FE, 0x0001D5FF, 0x00017411, 0x00017A17,
  0x00019B4E, 0x0001DA16, 0x0001E352, 0x0001E984, 0x0001E987,
  0x00023609, 0x0002363E, 0x0002360A, 0x00025420, 0x0002ABBA,
  0x0002ABB9, 0x0002ABB8, 0x0002ABBB, 0x00028528, 0x00028529,
  0x0002B0F8, 0x0002B0FC, 0x0002B0FD, 0x0002B0FE, 0x0002B8D1,
  0x0002DCD9, 0x0002DB45, 0x0002DCDD, 0x0002DCDE, 0x0002DCE0,
  0x0002DED7, 0x0002DED8, 0x0002E03C, 0x0002E0E4, 0x0002E5E4,
  0x0002FCC7, 0x00030602, 0x0003C840, 0x0003C841, 0x0003C847,
  0x0003C948, 0x0003C949, 0x0003BD8C, 0x0003C2FA, 0x0003D447,
  0x000433AC, 0x00043B8A, 0x00044B12, 0x00044B14, 0x00044D09,
  0x00048190, 0x00048191, 0x00048192, 0x00048306, 0x0004CCE9,
  0x0004CCEA, 0x0004D030, 0x0004D031, 0x0004E73A, 0x0004F135,
  0x0004F656, 0x00050F55, 0x00051466, 0x00051467, 0x0005364D,
  0x000560EC, 0x000560F4, 0x0004021A, 0x00042F27, 0x0004E1C4,
  0x00057E2A, 0x00058BFB, 0x0003F535, 0x0003F538, 0x0005AAB5,
  0x0005AB78, 0x0005D863, 0x00063B37, 0x00063B72, 0x000687CD,
  0x00068C88, 0x0006A17B, 0x0006C247, 0x0007012B, 0x000752C9,
  0x000752CA, 0x00079F14, 0x00089C77, 0x0006F6A6, 0x00093706,
  0x00098744, 0x0003DFC6, 0x0009C4CB, 0x0009DF52, 0x0009DF53,
  0x000A5E88, 0x000A6F41, 0x0005DD39, 0x000B36E4, 0x000B5F0B,
  0x000B754F, 0x000B7550, 0x000B754E, 0x00018E56, 0x000190F2,
  0x000B548B, 0x0001FC8F, 0x00023603, 0x000B9E64, 0x00024ECA,
  0x0002A344, 0x00017281, 0x0002DF06, 0x00039272, 0x00039391,
  0x000392A7, 0x0003E897, 0x0003EE0D, 0x00061520, 0x00061BB7,
  0x00064C00, 0x00070C6C, 0x00076E43, 0x00076E49, 0x000A3422,
  0x000C25A7, 0x000C25EA, 0x000C2677, 0x000C2727, 0x000C27B0,
  0x000C27BB, 0x000C30AF, 0x000C3C1C, 0x000C84C5, 0x0005608F,
  0x000494D2, 0x00049C94, 0x000CA776, 0x000CA9F7, 0x0009CA2A,
  0x0009DBB2, 0x000A4291, 0x00044C5E, 0x0004E776, 0x0005281B,
  0x00049135, 0x00054CDD, 0x00054DEF, 0x00056ECC, 0x000C991F,
  0x0005C1E0, 0x00022F27, 0x0006744D, 0x0006753C, 0x0005C28B,
  0x0004960E, 0xFF0009A9, 0x0004B9DD, 0x0009B5A0,
  /*0x0001DFF7, 0x0001DFF1 0x00018612,
  *0x0002F876, 0x00034A35, 0x0004623F,
  *0x0006F20C, 0x000790FA, 0x0002DBE5,
  *0x0004F657, 0x0003C947, 0x00019409,
  *0x0001D5FC, 0x0001D5FD, 0x0004E6F3,*/
  /* 0xFF001491, 0xFF003A22, 0xFF006852,
  *0xFF007539, 0x0002281B, 0xFF0091C0,
  *0xFF00A98C, 0xFF00BE09, 0xFF00D3D8,
  *0x00060176,*/
  /*0x0002281A, tenpenny back basement outside
  this is a weird 1, you can easily access from tenpenny
  by pickpocket or killing. but other side will be locked.
  since it's out of logic, this should be seen as a 1-way?*/
  /*0x000179CE, 0x000179D3, tenpenny tower
  *0x0004C6CA, tenpenny attach follower escape hatch
  *0x0001DA15, rivet
  *0x0004BC64,
  *0x0004BC65,
  *0x0004EF46,
  *0x0004EF73,
  *0x00076E46, west single sat top, goes nowhere
  *0x00064BFF, single sat top, goes nowhere
  *0x00076E45, tri sat top, can fall but dmg
  *0x00098743,
  *0xFF00734E,*/
  0x0,
};

/* fake satellite cells for logic */

// west most with down'ed dish as trader camp
// for whatever reason, this sat has a shared
// inside with different areas, so split them

// bot inside cell is 0007684A
const uint32_t cell_00000332[] = {
  0x0007684E, 0x0007684D, // mid inside
  0x0,
};

const uint32_t cell_00000333[] = {
  0x00076E41, 0x00076E48, // outside mid
  0x0,
};

const uint32_t cell_00000444[] = {
  0x00064BFD, 0x00064D38, // mid
  0x0,
};

const uint32_t cell_00000555[] = {
  0x000C3D33, 0x000C3D34, // mid
  0x0,
};

const uint32_t cell_00000556[] = {
  0x00076E42, 0x00076E44, // mid
  0x0,
};

const uint32_t cell_00000557[] = {
  0x000C3EA3, 0x000C3EA4, // mid
  0x0,
};

const uint32_t cell_00000558[] = {
  0x000C3EA5, 0x000C3CF2, // top, small wood bridge
  0x0,
};

/* fake for statesmen<>hope 'bridge'*/
// real cell for vernon square is 0001A28E
const uint32_t cell_00000222[] = {
  0x0002A14E, 0x0002A144,
  0x0,
};

/* fake for mama dolce bridges */
const uint32_t cell_00000777[] = {
  0x0004E019, 0x0004E01A,
  0x0,
};

const uint32_t cell_00000778[] = {
  0x000503B7, 0x00050D36,
  0x0,
};

/* fake for constantine bridge */
const uint32_t cell_00000888[] = {
  0x0004CEF7, 0x0004CEF8,
  0x0,
};

/* fake for bethesda ruins bridge */
const uint32_t cell_00000999[] = {
  0x0002541E, 0x0002541F,
  0x0,
};

const uint32_t cell_00000A96[] = {
  0x00003A12, 0x00003A14, 0x00003A15,
  0x00003A16, 0x00003A19, 0x00003A1C,
  0x00003A1D, 0x00003A1F, 0x00003A23,
  0x00003A24, 0x00003A25, 0x00003A26,
  0x00003A81, 0x00003B2C, 0x00003B39,
  0x00003F7D, 0x0000435C, 0x00002DFF,
  0x00014E1A,
  /*0x000790FB,*/
  /*0x000039B7, player house*/
  0x0,
};

const uint32_t cell_000035D3[] = {
  0x0006B0A8, 0x00014FDC, 0x00014FDD,
  0x000BBB5F, 0x000BBB6B,
  0x0,
};

const uint32_t cell_000035D4[] = {
  0x000038B9, 0x000038B8,
  0x0,
};

const uint32_t cell_000035D5[] = {
  0x0000374D, 0x0000374E,
  0x0,
};

const uint32_t cell_000035D6[] = {
  0x000036C6, 0x000036C7,
  0x0,
};

const uint32_t cell_00003A29[] = {
  0x00003A4F, 0x00003F7E,
  0x0,
};

const uint32_t cell_00003A35[] = {
  0x00003F8E, 0x00003A5F,
  0x0,
};

/*
*const uint32_t cell_00003B72[] = {
*  0x00003CEF, becomes 1 door cell
*  0x000A257B, declaration quest lock
*  0x0,
*/

const uint32_t cell_00003B85[] = {
  0x00003C51, 0x00003C72,
  /*0x000ABD29,*/
  0x0,
};

const uint32_t cell_0001516F[] = {
  0x0001FA59, 0x0001FA3A,
  0x0,
};

const uint32_t cell_00016D9F[] = {
  0x0007DD37, 0x000173EF,
  /*0x000310CC, leskos door locked*/
  0x0,
};

const uint32_t cell_00016DA1[] = {
  0x0006184D, 0x000172F6,
  /*0x0001940B, quest locked roy*/
  0x0,
};

const uint32_t cell_00016DA2[] = {
  0x0001727D, 0x0001727C,
  0x0,
};

const uint32_t cell_00016DA7[] = {
  0x00053C9A, 0x00053C9B,
  0x0,
};

const uint32_t cell_00016DA8[] = {
  0x00052F32, 0x00052F33, 0x000170FD,
  0x0,
};

/* tenpenny player house
*const uint32_t cell_000170E7[] = {
*  0x00017191, 0x000179D1,
*  0x0,
*};
*/

const uint32_t cell_000173EC[] = {
  0x000B5CE6, 0x000B5CFB,
  0x0,
};

const uint32_t cell_000178B8[] = {
  0x000178BF, 0x0001798C,
  /*0x00017972, tenpenny player house*/
  0x0,
};

const uint32_t cell_00017E14[] = {
  0x0004F2C8, 0x00044DA7,
  0x0,
};

const uint32_t cell_00017E17[] = {
  0x00017ECB, 0x00017ECA,
  0x0,
};

/*
*const uint32_t cell_00017E18[] = {
*  0x00047E6F, becomes 1 door cell
*  0x00035B6E, quest locked
*  0x0,
*};
*/

const uint32_t cell_00017E19[] = {
  0x00035B81, 0x00035B80,
  0x0,
};

const uint32_t cell_00017F2F[] = {
  0x00018396, 0x00018397,
  0x0,
};

const uint32_t cell_00017F30[] = {
  0x00018389, 0x0001838A,
  0x0,
};

const uint32_t cell_00017F31[] = {
  0x0001837B, 0x0001837C, 0x0001837D,
  0x0,
};

const uint32_t cell_00017F33[] = {
  0x000178C0, 0x0001835E,
  0x0,
};

const uint32_t cell_00017F34[] = {
  0x000172E7, 0x000173CB,
  0x00018351, 0x00021FB6,
  /*0x00018350,*/
  0x0,
};

const uint32_t cell_00017F37[] = {
  0x000414F6, 0x000414F7,
  0x0,
};

const uint32_t cell_00017F39[] = {
  0x000882F5, 0x00018308, 0x00018309,
  0x0,
};

const uint32_t cell_00017F3A[] = {
  0x000882F6, 0x00059A0B,
  0x000182FA, 0x000182FC,
  0x0,
};

const uint32_t cell_00017F3B[] = {
  0x0003B1D2, 0x000182EA,
  0x0,
};

const uint32_t cell_00017F3C[] = {
  0x000182DD, 0x000182DE, 0x0003BCC5,
  0x0,
};

const uint32_t cell_00017F3D[] = {
  0x0003B371, 0x0002A019, 0x000182CF,
  0x0,
};

const uint32_t cell_00017F40[] = {
  0x000182A4, 0x000182A6,
  0x0,
};

const uint32_t cell_00017F43[] = {
  0x0002BCA0, 0x0002BCAD,
  0x0001827B, 0x0001B8B0,
  0x0,
};

const uint32_t cell_00017F44[] = {
  0x00018269, 0x0001826A,
  0x0,
};

const uint32_t cell_00017F45[] = {
  0x0001825C, 0x0001825D,
  0x0,
};

const uint32_t cell_00017F46[] = {
  0x0001824E, 0x0001824F, 0x00018250,
  0x0,
};

const uint32_t cell_00017F47[] = {
  0x00050B84, 0x00050BEA, 0x00050BEC,
  0x0,
};

const uint32_t cell_00017F48[] = {
  0x00050090, 0x000509FC, 0x00050A17,
  0x00050A18, 0x00050BEB, 0x000514D2,
  0x0,
};

const uint32_t cell_00017F49[] = {
  0x0005092E, 0x00051465,
  0x0,
};

const uint32_t cell_00017F4A[] = {
  0x00018214, 0x00029930,
  0x0,
};

const uint32_t cell_00017F4C[] = {
  0x000181F9, 0x000181FA, 0x00029932,
  0x0,
};

const uint32_t cell_00017F4D[] = {
  0x0002A93C, 0x000181F3, 0x000181F4,
  0x0,
};

const uint32_t cell_00017F4E[] = {
  0x000181E6, 0x000181E7, 0x0002DD62,
  0x0,
};

/*
*const uint32_t cell_00017F4F[] = {
*  0x000181D8, becomes 1 door cell
*  0x000181D4, quest elevator no power
*  0x0,
*};
*/

/* dunwhich virulent underchambers
const uint32_t cell_00017F50[] = {
  0x000181BD, top of pitt you can't climb
  0x000181BE, becomes 1 door cell
  0x0,
};
*/

const uint32_t cell_00017F51[] = {
  0x000181B0, 0x000181B1,
  0x0,
};

const uint32_t cell_00017F52[] = {
  0x000181A2, 0x000181A3, 0x000181A4,
  0x0,
};

const uint32_t cell_00017F53[] = {
  0x00018192, 0x00018193,
  0x0,
};

const uint32_t cell_00017F54[] = {
  0x00018185, 0x00018186,
  0x0,
};

const uint32_t cell_00017F55[] = {
  0x00018177, 0x00018178, 0x00018179,
  0x0,
};

const uint32_t cell_00017F57[] = {
  0x00024A08, 0x00043F60,
  0x0,
};

const uint32_t cell_00017F59[] = {
  0x0001813C, 0x000547B2,
  0x0,
};

/*
*const uint32_t cell_00017F5A[] = {
*  0x00018130, becomes 1 door cell
*  0x00054830, cant climb to
*  0x0,
*};
*/

const uint32_t cell_00017F5B[] = {
  0x00018121, 0x00018122, 0x00039393,
  0x0,
};

const uint32_t cell_00017F5F[] = {
  0x0003D824, 0x0003D811,
  0x0,
};

const uint32_t cell_00017F61[] = {
  0x000A5401, 0x0003D3DF, 0x0003D22A,
  0x0,
};

const uint32_t cell_00017F64[] = {
  0x0002CAFB, 0x000180A3,
  0x0,
};

const uint32_t cell_00017F67[] = {
  0x00039B70, 0x00018080,
  0x0,
};

const uint32_t cell_0001845D[] = {
  0x00042039, 0x0004202D, 0x0004203C,
  0x0,
};

const uint32_t cell_00018461[] = {
  0x00074F5A, 0x0001741A,
  0x00004440, 0x000184D6,
  0x0,
};

const uint32_t cell_00018464[] = {
  0x00044B13, 0x00044B11, 0x00044AA6,
  0x0,
};

const uint32_t cell_0001851F[] = {
  0x0001865B, 0x0001865C,
  0x0,
};

const uint32_t cell_00018522[] = {
  0x00003BB5, 0x00003BBA,
  0x0,
};

const uint32_t cell_00018523[] = {
  0x0001D877, 0x00018634, 0x00018635,
  /*0x0001863A, 0x000A53BD,*/
  0x0,
};

/*
*const uint32_t cell_00018525[] = {
*  0x00018626, 0x00072020,
*  0x0,
*};
*/

const uint32_t cell_00018528[] = {
  0x00018608, 0x00018609,
  0x0,
};

const uint32_t cell_00018529[] = {
  0x000185FA, 0x000185FB,
  /*0x00035363, internal 1-door room*/
  0x0,
};

const uint32_t cell_0001852A[] = {
  0x0002F4CD, 0x0002F4CA,
  0x0,
};

const uint32_t cell_0001852B[] = {
  0x00093FC2, 0x0003ACEF, 0x0003AD0E,
  0x0003AD1C, 0x0003AE20, 0x0003AD1F,
  0x0003AD1D, 0x000A39A1,
  0x0,
};

/*
*const uint32_t cell_0001852C[] = {
*  0x000185E8, becomes 1 door cell
*  0x000252D9, tranquility 'chair'
*  0x0,
*};
*/

const uint32_t cell_0001852D[] = {
  0x000317B5, 0x00030B1E, 0x00030B00,
  0x0,
};

const uint32_t cell_00018530[] = {
  0x000317A4, 0x000317B4,
  0x0,
};

const uint32_t cell_00018532[] = {
  0x0003AD3A, 0x0003ADA6,
  0x0,
};

const uint32_t cell_00018533[] = {
  0x0003179F, 0x0003179C,
  0x0,
};

const uint32_t cell_00018534[] = {
  0x00018617, 0x00053671,
  0x0,
};

const uint32_t cell_00018536[] = {
  0x000356CB, 0x00018589,
  0x0,
};

const uint32_t cell_00018537[] = {
  0x00021026, 0x0002F4D4,
  /*0x00021025,*/
  0x0,
};

const uint32_t cell_00018538[] = {
  0x0003ADAF, 0x0003ADF4,
  /*0x000A5F56,*/
  0x0,
};

const uint32_t cell_00018539[] = {
  0x0001E33B, 0x0001E339,
  0x0,
};

const uint32_t cell_0001853A[] = {
  0x0001E33A, 0x0001E338, 0x0001E337,
  0x0,
};

const uint32_t cell_0001853B[] = {
  0x000AEC1B, 0x0001E351,
  0x0,
};

const uint32_t cell_00019FBB[] = {
  0x00053EEE, 0x00053E41, 0x00053E3C,
  0x0,
};

/* gnr inside
*const uint32_t cell_0001A26F[] = {
*  0x00026F82, 0x00026231,
*  0x00026F63, 0x0002622E,
*  0x0,
*};
*/

const uint32_t cell_0001A270[] = {
  0x0005043B, 0x0001B9BE, 0x0005032A,
  0x0005036C, 0x000503A9,
  0x0,
};

const uint32_t cell_0001A271[] = {
  0x000AE886, 0x0001B9D7,
  0x0,
};

const uint32_t cell_0001A272[] = {
  0x0001B9D4, 0x0001B9D5,
  0x0,
};

const uint32_t cell_0001A273[] = {
  0x000B5158, 0x0007F7E3, 0x0001B9CC,
  0x0,
};

const uint32_t cell_0001A274[] = {
  0x00050D35, 0x00050D6A, 0x00050C53,
  0x00050C54, 0x0001B9E4, 0x00050299,
  0x0,
};

const uint32_t cell_0001A276[] = {
  0x0002F14B, 0x0002F8A2,
  0x0002F8A1, 0x0005B3B3,
  0x0,
};

/*
*const uint32_t cell_0001A279[] = {
*  0x0002627D, 0x0002625A,
*  0x0,
*};
*/

const uint32_t cell_0001A281[] = {
  0x0001B928, 0x0001B929,
  0x0,
};

const uint32_t cell_0001A283[] = {
  0x0001B5C6, 0x00035EA3, 0x00034FB1,
  0x0,
};

const uint32_t cell_0001A284[] = {
  0x0001B738, 0x0001B90F,
  0x0001B910, 0x0001BD24,
  0x0,
};

const uint32_t cell_0001A285[] = {
  0x0001B900, 0x0001B901, 0x0001ED98,
  0x0,
};

const uint32_t cell_0001A286[] = {
  0x0001B64E, 0x0001B8FC,
  0x0,
};

const uint32_t cell_0001A287[] = {
  0x0001B8EC, 0x0001B8ED, 0x000446E7,
  0x0,
};

const uint32_t cell_0001A288[] = {
  0x00061AB3, 0x0001B8E8, 0x000603FE,
  0x0,
};

const uint32_t cell_0001A28C[] = {
  0x0003ED59, 0x0001B8BE, 0x0001B8C9,
  0x0001B8CA, 0x0001B8CC,
  0x0,
};

const uint32_t cell_0001A28D[] = {
  0x0001B8B8, 0x0001B8B9,
  0x0,
};

const uint32_t cell_0001A28E[] = {
  0x000959B9, 0x0002A129,
  0x0001B8AD, 0x0001B8AF,
  0x0002B5D4, 0x00032EC1,
  0x0001B5EF, 0x0001B5F1,
  0x0001B60D, 0x0001B615,
  0x0,
};

const uint32_t cell_0001A292[] = {
  0x0001B764, 0x0001B6F0, 0x0001B89E,
  0x0001B89D, 0x00033CB1, 0x0003E648,
  0x000B5EB5, 0x000C8129, 0x0006A9D3,
  /*0x0001B89C,*/
  0x0,
};

const uint32_t cell_0001B478[] = {
  0x0001B834, 0x0001B833,
  0x0,
};

/* taft =/ can't use
*const uint32_t cell_0001B56C[] = {
*  0x000B5C3E, 0x0003DC6F,
*  ^ these mess with Li WOL and TIB
*  0x0001B625, quest locked
*  0x0,
*};
*/

const uint32_t cell_0001BA01[] = {
  0x0001BA98, 0x0001B816, 0x00022BBC,
  0x00022D93, 0x00022D94, 0x000BC433,
  0x0001B7D4,
  0x0,
};

const uint32_t cell_0001BA03[] = {
  0x0001FA1D, 0x0001FA36,
  0x0001F6BD, 0x0005AE0C,
  0x0,
};

const uint32_t cell_0001BC8A[] = {
  0x0001BD50, 0x0001B79A, 0x0001B7ED,
  0x0003EEA5, 0x00061F70, 0x000CC22A,
  0x0,
};

const uint32_t cell_0001BC8B[] = {
  0x00038D5C, 0x0001B7D0, 0x00003417,
  0x0,
};

const uint32_t cell_0001BC8D[] = {
  0x0006151A, 0x000603F3,
  0x0,
};

const uint32_t cell_0001BC8F[] = {
  0x0003EE77, 0x0001BD21, 0x0001BD22,
  0x0,
};

const uint32_t cell_0001BC90[] = {
  0x0001BD18, 0x0001BD23, 0x0003354A,
  0x00033EE5, 0x0001B766, 0x00049FDE,
  0x0004F2AF, 0x00061F92, 0x000658C8,
  0x0,
};

const uint32_t cell_0001BC91[] = {
  0x000C0A69, 0x0001BD17, 0x0001C85B,
  0x000314CA, 0x0001B5EE, 0x000B16AD,
  0x0,
  /*0x000C0A67,*/
};

const uint32_t cell_0001BC93[] = {
  0x00025CD0, 0x00025F72,
  0x0004423F, 0x00044248,
  0x0,
};

const uint32_t cell_0001BC95[] = {
  0x000AE871, 0x0004F2AE,
  0x00054A3A, 0x0002F3F0,
  0x0,
};

const uint32_t cell_0001BC98[] = {
  0x0001BCD4, 0x0004DD32, 0x0004DD33,
  0x0004DB4A, 0x0004DB49, 0x0004DB4B,
  0x0006D994, 0x0007C608,
  0x0,
  /*0x0004DB47, unreachable half-bridge*/
};

const uint32_t cell_0001BC99[] = {
  0x0006C246, 0x0001BCD1,
  0x0,
};

const uint32_t cell_0001BC9A[] = {
  0x0004F23C, 0x0004F263,
  0x0,
};

const uint32_t cell_0001D6A3[] = {
  0x00029043, 0x0004EF72, 0x0004EF67,
  0x0004EF5D, 0x0004EF4D, 0x0001E986,
  0x0001DA1E, 0x0001DA41, 0x0001DA74,
  0x0,
};

const uint32_t cell_0001D6AA[] = {
  0x00051271, 0x00053E1F,
  0x00053E20, 0x00053E71,
  0x0,
};

const uint32_t cell_0001D6AB[] = {
  0x00053E8E, 0x00053E9B, 0x00053E8F,
  0x0,
};

/*
*const uint32_t cell_0001DEAE[] = {
*  0x0001DEC1, locked after pipe scene
*  0x0001DED3, waters of life quest locked
*  0x0,
*};
*/

/* waters of life pipes
*const uint32_t cell_0001DEB0[] = {
*  0x0001DF6C, pipe qlock, becomes 1 door cell
*  0x0001DFE2, jefferson basement
*  0x0,
*};
*
*const uint32_t cell_0001DEB1[] = {
*  0x0001DEDA, 0x0001DEDB,
*  0x0,
*};
*/

const uint32_t cell_0001E0F1[] = {
  0x0001E336, 0x000AEB62,
  0x0,
};

const uint32_t cell_00020F90[] = {
  0x00020FD8, 0x00020FD9,
  0x0,
};

const uint32_t cell_00020F91[] = {
  0x0004561C, 0x0004561F, 0x00045268,
  0x0002D96C, 0x0002FA9E, 0x0002FB26,
  /*0x00045267, gate bocks murder pass, 1-way*/
  0x0,
};

const uint32_t cell_0002107F[] = {
  0x00053D2E, 0x00053D1B,
  0x00029080, 0x000594C1,
  0x0,
};

// tenpenny dark world, front/genny
const uint32_t cell_0002263C[] = {
  0x0002270C, 0x0002270B,
  0x0002270A,
  /*0x0004C6C8, follower escape hatch*/
  /*0x0002270D, 0x0002270E,*/
  0x0,
};

const uint32_t cell_0002263D[] = {
  0x0002268C, 0x0002268B,
  0x0,
};

const uint32_t cell_0002263E[] = {
  0x0004C333, 0x00022650,
  0x0,
};

const uint32_t cell_00022D92[] = {
  0x00022DB8, 0x00022DB9,
  0x0,
};

const uint32_t cell_00023226[] = {
  0x00023240, 0x0002324D,
  0x0002324B, 0x0002325F,
  0x0,
};

const uint32_t cell_000235F1[] = {
  0x0002366C, 0x000236AD,
  0x0,
};

/*
*const uint32_t cell_000236D9[] = {
*  0x000468E6, becomes 1 door cell
*  0x000467BE, hall columns invis walls
*  0x0,
*};
*
*const uint32_t cell_000236DA[] = {
*  0x0003E8F8, becomes 1 door cell
*  0x0004665B, hall columns
*  0x0,
*};
*/

const uint32_t cell_000236DB[] = {
  0x0003A572, 0x0001F1FA,
  0x0003AF6D, 0x00096177,
  0x0,
};

const uint32_t cell_000244AA[] = {
  0x00024CAF, 0x000298D1,
  0x0,
};

const uint32_t cell_000244BE[] = {
  0x00024BE9, 0x00024BF7, 0x00024C0A,
  0x00024C1D, 0x00024C40, 0x0002B536,
  /*0x000252D8,*/
  0x0,
};

const uint32_t cell_00024511[] = {
  0x0005398D, 0x0005398B, 0x00052196,
  0x0,
};

const uint32_t cell_00024512[] = {
  0x00052197, 0x00028579, /*0x00024720,*/
  0x0,
};

const uint32_t cell_00024513[] = {
  0x000253FD, 0x0002541D,
  0x0,
};

const uint32_t cell_00024D6B[] = {
  0x00095E92, 0x00095E91, 0x00095E57,
  0x00095E58, 0x00095E59, 0x00095E5A,
  0x00024E1B,
  0x0,
};

const uint32_t cell_00024D6C[] = {
  0x00095EB4, 0x00095EB5,
  0x0,
};

const uint32_t cell_00024D71[] = {
  0x00024DF1, 0x00038B3F,
  0x0,
};

const uint32_t cell_00024D78[] = {
  0x00063B71, 0x00063B70, 0x0002796D,
  0x0,
};

const uint32_t cell_00024D79[] = {
  0x00063B2B, 0x00028001,
  0x0,
};

const uint32_t cell_00024D7B[] = {
  0x0002DCA0, 0x0002DC9F,
  0x0,
};

const uint32_t cell_000252DA[] = {
  0x0002544A, 0x0001C1B7,
  0x0,
};

const uint32_t cell_0002798D[] = {
  0x00027DEE, 0x00027E32,
  0x0,
};

const uint32_t cell_00028138[] = {
  0x00054285, 0x000290D8, 0x0009DB79,
  0x0,
};

const uint32_t cell_00029AAB[] = {
  0x0002A328, 0x0002A088,
  0x0,
};

const uint32_t cell_0002A58A[] = {
  0x0006BA8E, 0x00047E36,
  0x0,
};

const uint32_t cell_0002AFAF[] = {
  0x00095E93, 0x00095E94,
  0x0,
};

const uint32_t cell_0002AFB0[] = {
  0x00095E8F, 0x00095E8E,
  0x0,
};

const uint32_t cell_0002B952[] = {
  0x0002BD2B, 0x0002BCAE,
  0x0,
};

const uint32_t cell_0002D0E2[] = {
  0x000482CF, 0x000482CE, 0x000482CD,
  0x0,
};

const uint32_t cell_0002D0E4[] = {
  0x0002D204, 0x0002D205,
  0x0,
};

const uint32_t cell_0002D0E5[] = {
  0x0004CFA3, 0x0004CD80,
  0x0004CDAA, 0x0004CD24,
  /*0x0002D247,*/
  0x0,
};

const uint32_t cell_0002D0E6[] = {
  0x0002D15E, 0x0002D230, 0x00069FC3,
  0x0,
};

const uint32_t cell_0002D6EE[] = {
  0x0004AEA2, 0x0002D775,
  0x0,
};

const uint32_t cell_0002D743[] = {
  0x0002DBD8, 0x0002DBE1,
  0x0,
};

const uint32_t cell_0002DC04[] = {
  0x0002DC39, 0x0002DC38,
  0x0,
};

const uint32_t cell_0002F22B[] = {
  0x0002F526, 0x0002F533, 0x0002F534,
  0x0002F535, 0x0002F53E, 0x0002F53F,
  0x00038B3D, 0x000695E2, 0x0006EC68,
  0x0,
};

const uint32_t cell_0002F69E[] = {
  0x0002F897, 0x0002F899, 0x0002F898,
  0x0,
};

const uint32_t cell_00033B0B[] = {
  0x0004EDAB, 0x0004E6D1,
  0x0,
};

const uint32_t cell_00039E38[] = {
  0x00039E44, 0x0003A245,
  0x0,
};

const uint32_t cell_0003ABF8[] = {
  0x0003AE6F, 0x0003AE79,
  0x0,
};

const uint32_t cell_0003BC89[] = {
  0x0003BCF7, 0x0003BCE7,
  0x0,
};

const uint32_t cell_0003C83E[] = {
  0x00096D8B, 0x0003C8B0,
  0x0,
};

const uint32_t cell_0003C944[] = {
  0x0003C96F, 0x0003C99C, 0x0003C99E,
  0x0,
};

const uint32_t cell_0003D444[] = {
  0x0003D68F, 0x0003D583,
  0x0,
};

const uint32_t cell_0003D445[] = {
  0x0003D44A, 0x0003D51A,
  0x0,
};

const uint32_t cell_000406AE[] = {
  0x000A5E2D, 0x000407D7,
  0x0,
};

const uint32_t cell_000406AF[] = {
  0x000A5E83, 0x00040710,
  0x0,
};

const uint32_t cell_00041FDD[] = {
  0x000420E8, 0x000420EA,
  0x0,
};

const uint32_t cell_0004363B[] = {
  0x00043DD5, 0x00043DD6,
  0x0,
};

const uint32_t cell_0004363E[] = {
  0x00043CC2, 0x00043CC3,
  0x0,
};

const uint32_t cell_0004550F[] = {
  0x0004561A, 0x0004561B, /*0x00045612,*/
  0x0,
};

const uint32_t cell_000459CD[] = {
  0x00045AC4, 0x00045A1B,
  0x0,
};

const uint32_t cell_0004AEC3[] = {
  0x0004B3F3, 0x0004B3FA,
  0x0,
};

const uint32_t cell_0004C4E6[] = {
  0x00050395, 0x0004CAA8, 0x0004CAA9,
  0x0,
};

const uint32_t cell_0004D4BB[] = {
  0x0005634C, 0x00062E9B,
  0x0,
};

const uint32_t cell_0004DD5B[] = {
  0x0004E89C, 0x0004E8E6,
  0x0,
};

const uint32_t cell_0004DD8A[] = {
  0x0004DDC1, 0x0004DDC2,
  0x0,
};

const uint32_t cell_0004DD8B[] = {
  0x0006DBAB, 0x0006DB9A, 0x0006DB38,
  0x0004E7E7, 0x0004E7E8,
  0x0,
};

const uint32_t cell_000508E6[] = {
  0x000509E3, 0x000509E2, 0x000509DF,
  0x0,
};

const uint32_t cell_00051245[] = {
  0x000513D1, 0x000513D0, 0x000513CF,
  0x000513B3, 0x000513AC,
  0x0,
};

const uint32_t cell_00051E79[] = {
  0x00051EB6, 0x00051EB7,
  0x0,
};

const uint32_t cell_00051E7A[] = {
  0x00051E94, 0x00051E93,
  0x0,
};

const uint32_t cell_00051E7B[] = {
  0x00051E81, 0x00051E82,
  0x0,
};

const uint32_t cell_0005559E[] = {
  0x00056D22, 0x00056975,
  0x0,
};

/* tenpenny/waringtonstation03 basement
* the door is 'quest' locked by blowing
* up generators or terminal.
* speedrunny to assume someone will missile
* the right spot, so all of these become a 1-way
* dad got stuck here :)
*const uint32_t cell_000617FC[] = {
*  0x00021FC4, 0x0006184C,
*  0x00022646, dark world version, 1-way
*  0x00021FC1, tenpenny back, 1-way
*};
*/

const uint32_t cell_00064BF0[] = {
  0x00064CBC, 0x00064C5C,
  0x0,
};

const uint32_t cell_00067488[] = {
  0x00068C84, 0x000689C3,
  0x0,
};

/*
*const uint32_t cell_000695DE[] = {
*  0x00069646, bathroom, becomes 1 door cell
*  0x00069647, paradise child sewer
*  0x0,
*};
*/

/*
*const uint32_t cell_0006A8FF[] = {
*  0x000B5C33, has terminal locked door
*  0x0006B945, top becomes 1 door cell
*  *0x0005CF55, quest locked taft sewer
*  0x0,
*};
*/

const uint32_t cell_0006F9F8[] = {
  0x00070B96, 0x00070C6A,
  0x0,
};

const uint32_t cell_0007523C[] = {
  0x000752D9, 0x000752D8, 0x000752D7,
  0x0,
};

// stripped down version of fake 333
const uint32_t cell_0007684A[] = {
  0x0007684B, 0x0007684C,
  0x0,
};

const uint32_t cell_00082DF9[] = {
  0x00064D20, 0x00064D27,
  0x0,
};

const uint32_t cell_00084305[] = {
  0x00085878, 0x00085877,
  0x0,
};

const uint32_t cell_00098736[] = {
  0x00098737, 0x00098738,
  0x0,
};

const uint32_t cell_00099E9B[] = {
  0x000BB795, 0x000B5A74,
  0x000B5A7E, 0x000B5AA4,
  0x0,
};

const uint32_t cell_00099E9D[] = {
  0x000B5756, 0x000B5718, 0x000B57FF,
  0x000B5715, 0x000B5742,
  0x0,
};

/*
*const uint32_t cell_00099E9E[] = {
*  0x000B55BE, becoms 1 door cell
*  0x000B553E, 1-way from switch
*  0x00099F16, cave door quest locked
*  0x0,
*};
*/

const uint32_t cell_0009DF08[] = {
  0x0009DF50, 0x0009DF51,
  0x0,
};

/*
*const uint32_t cell_000A0C3C[] = {
*  0x000A0D80, 0x000A2432, oasis quest locked
*  0x0006BAAC, becomes 1 door cell
*  0x0,
*};
*/

/*
*const uint32_t cell_000A3977[] = {
*  0x000A39A9, becomes 1 door cell
*  0x000A3A87, vault 92 overseer
*  0x0,
*};
*/

const uint32_t cell_000AB546[] = {
  0x000AB579, 0x000AB578,
  0x0,
};

const uint32_t cell_000BC4C2[] = {
  0x000BC6D0, 0x000BC6D1,
  0x0,
};

const uint32_t cell_000BC4C3[] = {
  0x000BC527, 0x000BC4D1,
  0x0,
};

const uint32_t cell_000C568B[] = {
  0x000C585D, 0x000C578E, 0x000C578D,
  0x0,
};

const uint32_t cell_000C568C[] = {
  0x000C5863, 0x000C5785,
  0x0,
};

const uint32_t cell_000C99FC[] = {
  0x000C9A46, 0x000C99FD,
  0x0,
};


/* DLC */


/* anchorage */

// baileys tunnel
const uint32_t cell_01002738[] = {
  0xFF00287E, 0xFF00288B,
  0x0,
};

/* rest are simulation, a couple are in world space
*const uint32_t cell_01000C10[] = {
*  0xFF00B9B7, 0xFF00B9B1, 0xFF00B4EF,
*  0xFF00B4EE, 0xFF004D24, 0xFF0048A9,
*  0xFF000D64,
*  0x0,
*};
*
*const uint32_t cell_01000E29[] = {
*  0xFF001426, 0xFF001458,
*  0x0,
*};
*
*const uint32_t cell_01000F1A[] = {
*  0xFF0015EE, 0xFF001098,
*  0xFF001A97, 0xFF001AD2,
*  0x0,
*};
*
*const uint32_t cell_010019F6[] = {
*  0xFF001B15, 0xFF001B46,
*  0x0,
*};
*const uint32_t cell_010047DD[] = {
*  0xFF004947, 0xFF004D1E,
*  0x0,
*};
*
*const uint32_t cell_0100B94C[] = {
*  0xFF00B9B0, 0xFF00B9BF,
*  0x0,
*};
*/




/* broken steel */

const uint32_t cell_00015157[] = {
  0x00020A5F, 0x00020A6C,
  0x0,
};

const uint32_t cell_00015158[] = {
  0x00015622, 0x00020AE1, 0x0002377D,
  /*0x0001560D, quest locked even though clips and secret tunnel work*/
  0x0,
};

const uint32_t cell_00018520[] = {
  0x00018652, 0x0001C984,
  0x0,
};

const uint32_t cell_00018521[] = {
  0x00018649, 0x0001BD73, 0x0001CC21,
  0x0001DF0E,
  /*0x0001E005,*/
  /*0x0001CC7D,*/
  0x0,
};

const uint32_t cell_0001A26E[] = {
  0x0001B9FC, 0x000BB74C,
  /*0x00021E98, 0x00021E99, 0x0001B9FB,*/
  0x0,
};

const uint32_t cell_0001A28B[] = {
  0x0001B5BA, 0x0001B8CD, 0x0001B8CE,
  0x00076E72, 0x000BB0C3, 0x000BB0B4,
  0x000BB0B7, 0x000BB1E0,
  /*0x00076E3E, whitehouse walled off shared cell*/
  0x0,
};

const uint32_t cell_0001BC8E[] = {
  0x000401D3, 0x00022F26, 0x0002325B,
  0x00023260, 0x00022F16, 0x00027DD3,
  0x00027DE6, 0x0004BC2F, 0x000606B7,
  0x0006937A, 0x00041562, 0x000A4B13,
  0x000AE889, 0x0001B5B5, 0x0001B5B6,
  /*0x0001BD32, 0xFF003A50, 0x0004BC30,
  *0x0004BC40,*/
  0x0,
};

/*
*const uint32_t cell_000207A1[] = {
*  0x000209CA, becomes 1 door cell
*  0x00020A3D, prez metro
*  0x0,
*};
*/

const uint32_t cell_000207A2[] = {
  0x000209C4, 0x000209C5, 0x00020A5C,
  0x00020A5D, 0x00020A5E,
  0x0,
};

const uint32_t cell_00045219[] = {
  0x000453EB, 0x0004566A, 0x000506E1,
  0x0,
};

const uint32_t cell_0004F4E1[] = {
  0x0004F756, 0x0004F757,
  /*0xFF009193,*/
  0x0,
};

const uint32_t cell_00074EB2[] = {
  0x00074EDE, 0x0007D75F, 0x000B037B,
  0x0,
};

const uint32_t cell_00076DA3[] = {
  0x00076E5A, 0x00076E68,
  /*0xFF001075,*/
  0x0,
};

const uint32_t cell_00095B7A[] = {
  0xFF0020A3, 0x0002A273, 0x00095F5B,
  0x0,
};

const uint32_t cell_01000805[] = {
  0xFF0028BC, 0xFF003293,
  0xFF002349, 0xFF00234A,
  /*0xFF0015FE, 0xFF001603,*/
  /*0xFF005D3F, 0xFF00D2B7,*/
  0x0,
};

const uint32_t cell_01000806[] = {
  0xFF00248F, 0xFF006EF9,
  /*0xFF006EF8,*/
  0x0,
};

/*
*const uint32_t cell_01000807[] = {
*  0xFF001F0E, becomes 1 door cell
*  0xFF00BCD7, under train door
*  0xFF0020A9, prez metro quest locked
*  0x0,
*};
*/

/*
*const uint32_t cell_01000808[] = {
*  0xFF001079, prez metro
*  0xFF001F45, becomes 1 door cell
*  0x0,
*};
*/

/*
*const uint32_t cell_01000913[] = {
*  0xFF000915, rockland, all quest locked
*  0xFF000917,
*  0x0,
*};
*/

/*
const uint32_t cell_01000B0E[] = {
  0xFF000B16, rockland, all quest locked
  0xFF00151D,
  0x0,
};
*/

const uint32_t cell_0100106C[] = {
  0xFF000FC9, 0xFF0022ED, 0xFF0022F9,
  0xFF00248B, 0xFF00248C, 0xFF00444D,
  0xFF008AF8,
  /*0xFF002490, 0xFF008AF7, 0xFF00D2C7,*/
  /*0xFF004452, shared cell, but this is ATC 1-way*/
  0x0,
};

const uint32_t cell_010011C3[] = {
  0xFF00248A, 0xFF00248D,
  0xFF006EFA, 0xFF006EFB,
  0x0,
};

/* rockland - dupe with pitt
*const uint32_t cell_01001490[] = {
*  0xFF00150F, < the pitt dupe
*  0xFF00151C,
*  0x0,
*};
*/

/* destroyed citadel
*const uint32_t cell_01001B68[] = {
*  0xFF009774, armory bottom
*  0xFF009775, armory top
*  0xFF001BAD, top entrance, not climbable
*  0x0,
*};
*/

/*
*const uint32_t cell_010035A1[] = {
*  0xFF003C68, quest locked
*  0xFF00BE01, paperworks manhole
*  0x0,
*};
*/

const uint32_t cell_01003D64[] = {
  0xFF00406A, 0xFF00406B, 0xFF00406E,
  0x0,
};

const uint32_t cell_01004418[] = {
  0xFF004448, 0xFF004449,
  0x0,
};

/*
*const uint32_t cell_0100452A[] = {
*  0xFF004543, becomes 1 door cell
*  0xFF00BCD8, prez metro underground train door
*  0x0,
*};
*/

const uint32_t cell_010045B2[] = {
  0xFF0045B3, 0xFF0045B4,
  0x0,
};

/*
*const uint32_t cell_0100674D[] = {
*  0xFF006851, hatch to unreachable roof
*  0xFF0068E4, becomes 1 door cell
*  0x0,
*};
*/

const uint32_t cell_0100731E[] = {
  0xFF00733F, 0xFF007340,
  0x0,
};

const uint32_t cell_0100739A[] = {
  0xFF007CA6, 0xFF00BE0C,
  0x0,
};

const uint32_t cell_01008A0F[] = {
  0xFF008A10, 0xFF008A11,
  0x0,
};

/* destroyed citadel armory
* outside can't be random, so this stays not-random
*const uint32_t cell_010095C3[] = {
*  0xFF0095CA, 0xFF0095CB,
*  0x0,
*};
*/

/*
*const uint32_t cell_0100A107[] = {
*  0xFF00A44F, inside paperworks
*  0xFF00739B, quest locked
*  0x0,
*};
*/











/* pitt */

/*
*const uint32_t cell_010011AB[] = {
*  0xFF0011C0, becomes 1 door cell
*  0xFF0011C1, other side of 'not locked' door below
*  0x0,
*};
*/

/*
*const uint32_t cell_010011AC[] = {
*  0xFF0011B7, becomes 1 door cell
*  0xFF001509, door isn't locked, but a midway-door before it is
*              so it requires a clip to get to so it has to be
*              excluded from logic.
*  0xFF0011B8, mill to uptime quest locked
*  0xFF001510, arena quest locked
*  0x0,
*};
*/

const uint32_t cell_0100133A[] = {
  0xFF00150F, 0xFF0094A7,
  /*0xFF004627, 0xFF006971,*/
  0x0,
};

const uint32_t cell_0100133B[] = {
  0xFF001505, 0xFF001507, 0xFF00602D,
  0xFF00602E, 0xFF006973, 0xFF00A36E,
  /*0xFF001506, uptown mill quest lock*/
  0x0,
};

const uint32_t cell_0100133F[] = {
  0xFF00150A, 0xFF00150E, 0xFF009AFE,
  /*0xFF001503, 0xFF00150B, midea and pitt gate*/
  0x0,
};

const uint32_t cell_0100602C[] = {
  0xFF0060A0, 0xFF0061B2,
  0x0,
};

/*
*const uint32_t cell_01006355[] = {
*  0xFF0066B2, becomes 1 door cell
*  0xFF0066C1, steelyard sewer underground
*  0x0,
*};
*/

const uint32_t cell_01007D87[] = {
  0xFF007E01, 0xFF007E02,
  0x0,
};





/* point lookout */

const uint32_t cell_01003E25[] = {
  0xFF006BE5, 0xFF0081ED, 0xFF008311,
  0xFF008312, 0xFF00AFEC, 0xFF00B5D3,
  0xFF00A55C, 0xFF00B57E, 0xFF00BF62,
  0xFF00C0B3, 0xFF0088F2, 0xFF00C50D,
  0xFF00C532, 0xFF00C0B8, 0xFF00C0B9,
  0xFF00C0BA, 0xFF00D202, 0xFF00D6B1,
  0xFF00DA2E, 0xFF00DDD6, 0xFF00DF5A,
  0xFF00DDFB, 0xFF00E27E, 0xFF00B2D2,
  0xFF00BFF8, 0xFF00C04A, 0xFF00CDD8,
  0xFF00CDDB, 0xFF00CDE8, 0xFF00A55B,
  0xFF00B14E, 0xFF00F030, 0xFF00A546,
  0xFF00A54A, 0xFF011FA2,
  /*0xFF01099E, 0xFF003F16, 0xFF00438F,
  0xFF00583B, 0xFF00643D, 0xFF006B69,
  0xFF007AFA, 0xFF00AE73, 0xFF00B86B,
  0xFF00B46A, 0xFF011D64, 0xFF00CA58,*/
  0x0,
};

const uint32_t cell_01004E2D[] = {
  0xFF004E71, 0xFF004F15,
  /*0xFF004FC0,*/
  0x0,
};

/*
*const uint32_t cell_0100731F[] = {
*  0xFF0073A7, end of chinese mission
*  0xFF0073AE, pipe too steep
*  0x0,
*};
*/

/*
*const uint32_t cell_01007323[] = {
*  0xFF007357, end of chinese mission
*  0xFF007359, quest locked
*  0x0,
*};
*/

const uint32_t cell_01008120[] = {
  0xFF008214, 0xFF00EDB0,
  0x0,
};

const uint32_t cell_01008122[] = {
  0xFF0081C2, 0xFF008869, 0xFF00F7B3,
  0x0,
};

const uint32_t cell_01008123[] = {
  0xFF0081C0, 0xFF0081C1,
  0x0,
};

/*
*const uint32_t cell_0100928B[] = {
*  0xFF0093A7, wrecked seatub quest locked
*  0xFF00951A, exit hatch quest locked
*  0x0,
*};
*/

/*
*const uint32_t cell_0100977F[] = {
*  0xFF0097C3, under lighthouse
*  0xFF01099D, under lighthouse exit hatch
*  0x0,
*};
*/

/*
*const uint32_t cell_0100B85A[] = {
*  0xFF00BF18, tobars 'engine' room
*  0xFF01034E, quest locked
*  0x0,
*};
*/

const uint32_t cell_0100D6AF[] = {
  0xFF00D6BE, 0xFF00DF58,
  0x0,
};

const uint32_t cell_0100DF23[] = {
  0xFF00DF24, 0xFF00DF25,
  0x0,
};

/*
*const uint32_t cell_0100E91D[] = {
*  0xFF00E925, bog quest locked
*  0xFF00E931, can't really return
*  0x0,
*};
*/

const uint32_t cell_0100F05A[] = {
  0xFF00F080, 0xFF00F082,
  /*0xFF00F081, under lighthouse*/
  0x0,
};

const uint32_t cell_0100F28F[] = {
  0xFF00E17E, 0xFF009B7A,
  0x0,
};




/* zeta
*
*const uint32_t cell_0100098B[] = {
*  0xFF003B3A, 0xFF005D31, 0xFF00B458,
*  0x0,
*};
*
*const uint32_t cell_01000EF8[] = {
*  0xFF003098, 0xFF003099,
*  0x0,
*};
*
*const uint32_t cell_01000F96[] = {
*  0xFF002C03, 0xFF003350, 0xFF0039B4,
*  0xFF0039B5, 0xFF00C370,
*  0x0,
*};
*
*const uint32_t cell_01001616[] = {
*  0xFF00334F, 0xFF0038D9, 0xFF005B23,
*  0x0,
*};
*
*const uint32_t cell_01002FCE[] = {
*  0xFF00309F, 0xFF00711C,
*  0xFF00A98B, 0xFF00D2CA,
*  0x0,
*};
*
*const uint32_t cell_01002FCF[] = {
*  0xFF004BBC, 0xFF004E63, 0xFF0079B0,
*  0x0,
*};
*
*const uint32_t cell_01002FD2[] = {
*  0xFF00307F, 0xFF0031AE, 0xFF0032F4,
*  0xFF0032F5, 0xFF0032F6, 0xFF0032F8,
*  0xFF0032F9, 0xFF0032FA, 0xFF004E64,
*  0xFF00800B, 0xFF00D25C,
*  0x0,
*};
*
*const uint32_t cell_01002FD3[] = {
*  0xFF0031AF, 0xFF0032F2,
*  0x0,
*};
*
*const uint32_t cell_01003721[] = {
*  0xFF0038DC, 0xFF005B27,
*  0x0,
*};
*
*const uint32_t cell_0100428E[] = {
*  0xFF0043C8, 0xFF0043CA,
*  0x0,
*};
*
*const uint32_t cell_010047BD[] = {
*  0xFF007FE5, 0xFF007FF2,
*  0x0,
*};
*
*const uint32_t cell_0100481F[] = {
*  0xFF00492B, 0xFF003089,
*  0x0,
*};
*
*const uint32_t cell_01004820[] = {
*  0xFF0048C3, 0xFF00487C,
*  0x0,
*};
*
*const uint32_t cell_01004A12[] = {
*  0xFF006B12, 0xFF0067DA,
*  0x0,
*};
*
*const uint32_t cell_01004A13[] = {
*  0xFF004BD1, 0xFF004BD4,
*  0xFF0056AA, 0xFF0056A9,
*  0x0,
*};
*
*const uint32_t cell_01004A14[] = {
*  0xFF004BBB, 0xFF005F8C,
*  0xFF005F8D, 0xFF005FCC,
*  0x0,
*};
*
*const uint32_t cell_01007397[] = {
*  0xFF007EF3, 0xFF006D5B,
*  0x0,
*};
*
*const uint32_t cell_01008EC7[] = {
*  0xFF009169, 0xFF00B42C,
*  0x0,
*};
*/
