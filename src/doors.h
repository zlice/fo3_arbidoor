// author: zlice
// license: MIT (see LICENSE file or https://mit-license.org)

using namespace std;

// std rand related stuff
random_device rand_dev;
mt19937 rgen; // mersenne_twister_engine seeding
uniform_int_distribution<uint32_t> src_distrib, dst_distrib;

// randomized doors and their pointers kept in hash maps
// arbidoor <door-id, door-id>
// 16/1b    <door-id, pointer> (16 = XTEL, 1b = XTEL ptr)
// pointers can change on multiple loads, especially between characters.
unordered_map<uint32_t, uint32_t> arbidoor, door_16_map, door_1b_map;

uint32_t TOT_DOORS = 0;
uint32_t found_doors[1488] = { 0 }; // actively loaded door-IDs to randomize
// there are over 1400+ doors in base game and DLCs.
// this excludes dupes from broken-steel that are in base game.
// the total is closer to 1200 without doors that are 'ineligible' (see notes)

// single door-id dupe from BrokenSteel and Pitt
// 0x0100150F
// brokensteeldoors.txt: xtel ::: [REFR:0100150F] (places OffDoorMetalSmL01 "Door" [DOOR:00019CF5] in GRUP Cell Persistent Children of zDLC03CarTunnel "Rockland Car Tunnel" [CELL:01001490])
// pittdoors.txt:        xtel ::: SteelMillExteriortoSteelMill02REF [REFR:0100150F] (places IndDoorSmAnim01 "Door" [DOOR:000463CE] in GRUP Cell Persistent Children of [CELL:0100133A] (in DLC01SteelMillExterior "The Steelyard" [WRLD:010011A9]) at 1,0)

// lists of areas/DLCs
// dynamically added for randomization.
// they end with '0x0' for parsing and getting size.
const uint32_t fo3base_doors[] = {
    // pairs of linked door
    // being next to each other makes it easy to get with '^ 1'
    // the compliment door       <door1>    <door2>
    0x0001825D, 0x00018269,    0x0006BAAC, 0x0006BA8E,
    0x00062E9B, 0x00035B80,    0x0004E019, 0x0005032A,
    0x00050395, 0x0005036C,    0x000503B7, 0x000503A9,
    0x0004CAA8, 0x00050C54,    0x0004CAA9, 0x00050C53,
    0x0004E01A, 0x00050299,    0x00050D36, 0x00050D35,
    0x0002F526, 0x0002F425,    0x0002F533, 0x00024DD5,
    0x0002F534, 0x0002F429,    0x0002F535, 0x0002F41E,
    0x0002F53E, 0x00024DF1,    0x0002F53F, 0x0006A820,
    0x00038B3D, 0x00038B3F,    0x000695E2, 0x00069646,
    0x0006EC68, 0x0006ECA3,    0x0002A328, 0x000181F3,
    0x0001B89E, 0x0001B8B8,    0x000178BF, 0x00018351,
    0x0001B89D, 0x0001B8ED,    0x0003E648, 0x0004566A,
    0x00033CB1, 0x000453EB,    0x000B5EB5, 0x0006FE31,
    0x0001B6F0, 0x000BBB6B,    0x0001B764, 0x0001B738,
    0x000C8129, 0x000C819F,    0x0006A9D3, 0x0006B0A8,
    0x0001BCD4, 0x0001B8FC,    0x0004DD32, 0x0004DDC2,
    0x0004DD33, 0x0004DDC1,    0x0004DB47, 0x0004E7E8,
    0x0004DB4A, 0x0004E7E7,    0x0004DB49, 0x0006DBAB,
    0x0004DB4B, 0x0006DB38,    0x0006D994, 0x0006DB9A,
    0x0007C608, 0x0007C54F,    0x000959B9, 0x00095A1C,
    0x0002A129, 0x0002BCAD,    0x0002A144, 0x000181E6,
    0x0002A14E, 0x0002BCAE,    0x0001B8AD, 0x0001837D,
    0x0001B8AF, 0x0001827B,    0x0002B5D4, 0x000181D8,
    0x00032EC1, 0x00061566,    0x0001B5EF, 0x000BBB5F,
    0x0001B5F1, 0x0001B901,    0x0001B60D, 0x00014FDC,
    0x0001B615, 0x0001B64E,    0x000BB1E0, 0x000BB1DF,
    0x0001B8CD, 0x0001B8CC,    0x0001B8CE, 0x00045AC4,
    0x00076E3E, 0x00076E5A,    0x00076E72, 0x00076E68,
    0x0001B5BA, 0x0001B834,    0x000BB0C3, 0x000BC4D1,
    0x000BB0B7, 0x0001ED98,    0x000BB0B4, 0x000036C6,
    0x00022F26, 0x0002324B,    0x00018613, 0x00061AB3,
    0x0002325B, 0x0007D75F,    0x00023260, 0x0002325F,
    0x00022F16, 0x0004B3FA,    0x00027DD3, 0x00027E32,
    0x00027DE6, 0x00027DEE,    0x000401D3, 0x00019CD8,
    0x0006937A, 0x0006C03E,    0x00041562, 0x0001D877,
    0x000A4B13, 0x00018634,    0x000AE889, 0x000AE886,
    0x0001B5B5, 0x0000374E,    0x0001B5B6, 0x0001B833,
    0x000AE871, 0x0001B9D7,    0x0004F2AE, 0x0004F2C8,
    0x00054A3A, 0x0005497C,    0x0002F3F0, 0x0005A862,
    0x000C0A69, 0x0003A245,    0x000C0A67, 0x00039E44,
    0x0001BD17, 0x00045A1B,    0x0001C85B, 0x00034FB1,
    0x000314CA, 0x000314CF,    0x0001B5EE, 0x000BC527,
    0x000B16AD, 0x0002A273,    0x0001BD18, 0x0001B90F,
    0x0001BD23, 0x0000374D,    0x0003354A, 0x0003354B,
    0x00033EE5, 0x00033EE6,    0x0001B766, 0x000036C7,
    0x00049FDE, 0x0003EE77,    0x0004F2AF, 0x0004F263,
    0x00061F92, 0x00062678,    0x000658C8, 0x0006536A,
    0x00038D5C, 0x0005B3B3,    0x0001B7D0, 0x00017ECB,
    0x00003417, 0x0001B9CC,    0x0001BA98, 0x0001FA36,
    0x0001B816, 0x0007DD37,    0x00022BBC, 0x00022B28,
    0x00022D93, 0x00022DB8,    0x00022D94, 0x00022DB9,
    0x000BC433, 0x000B5158,    0x0001B7D4, 0x000BC6D1,
    0x0001BD50, 0x0001B9E4,    0x0001B79A, 0x000038B9,
    0x0001B7ED, 0x000BC6D0,    0x0003EEA5, 0x0001B929,
    0x00061F70, 0x0001B9BE,    0x000CC22A, 0x000CC21A,
    0x000BB74C, 0x00014FDD,    0x00018121, 0x00018130,
    0x00015622, 0x00020A6C,    0x00020AE1, 0x00020A5E,
    0x0002377D, 0x00020A5C,    0x00003A12, 0x00003A53,
    0x00003A14, 0x00003A37,    0x00003A15, 0x00003A5B,
    0x00003A16, 0x00003A3F,    0x00003A19, 0x00003A63,
    0x00003A1C, 0x00003A73,    0x00003A1D, 0x00003A43,
    0x00003A1F, 0x00003A6F,    0x00003A23, 0x00003A5F,
    0x00003A24, 0x00003A6B,    0x00003A25, 0x00003A4F,
    0x00003A26, 0x00003A57,    0x00003A81, 0x00003A67,
    0x00003F7D, 0x00003F7E,    0x0000435C, 0x000043AD,
    0x00002DFF, 0x00003A4B,    0x00014E1A, 0x00003A47,
    0x00026D27, 0x00043D5F,    0x0001C27A, 0x0001D3CE,
    0x000C3EA5, 0x00051E93,    0x000C3EA4, 0x000C5785,
    0x000C3EA3, 0x00051E94,    0x000C3D34, 0x00051EB6,
    0x000C3D33, 0x00085878,    0x000C3CF2, 0x00051EB7,
    0x000C3CF6, 0x00085877,    0x0007E093, 0x000534B3,
    0x0007D404, 0x0007D406,    0x00059503, 0x00029080,
    0x000594C2, 0x000594C1,    0x0003DA4F, 0x00093FC2,
    0x0002EE95, 0x0002EEB8,    0x0002EED6, 0x0002EED4,
    0x0002EED7, 0x0002EECA,    0x0002EE93, 0x0002EEBF,
    0x000184F7, 0x000184D6,    0x000184F5, 0x000A5E2D,
    0x000183DB, 0x0003D22A,    0x000183D8, 0x0002CAFB,
    0x000183D5, 0x00018080,    0x000183D2, 0x000414F6,
    0x000183CF, 0x000182FC,    0x000183C9, 0x000182A6,
    0x000183B1, 0x00018179,    0x000183AE, 0x0003C67E,
    0x00017473, 0x000173EF,    0x0001707F, 0x0001B5C6,
    0x00017083, 0x000B01A3,    0x00017084, 0x0001727C,
    0x00018616, 0x00018608,    0x0001BCD3, 0x0004F23C,
    0x0001BD36, 0x00030B00,    0x0001BD41, 0x0002F899,
    0x0001D5FE, 0x0001D62B,    0x0001D5FF, 0x0001D66F,
    0x00017411, 0x0001741A,    0x000179CE, 0x0001798C,
    0x00017A17, 0x000170FD,    0x00018122, 0x0001813C,
    0x0001DA15, 0x0001DA41,    0x0001DA16, 0x0001DA74,
    0x0001E984, 0x0001DA1E,    0x0001E987, 0x0001E986,
    0x00023609, 0x0002366C,    0x0002281A, 0x00021FC1, // < tenpenny back basement
    0x0002363E, 0x000236AD,    0x0002360A, 0x000253FD,
    0x0002541E, 0x0002541D,    0x0002541F, 0x0002544A,
    0x00025420, 0x0001C1B7,    0x0002ABBA, 0x00028001,
    0x0002ABB9, 0x0002796D,    0x0002ABB8, 0x00048380,
    0x0002ABBB, 0x0002ABB2,    0x00028528, 0x00029930,
    0x00028529, 0x00029932,    0x0002B0F8, 0x0002B10C,
    0x0002B0FC, 0x0002B10E,    0x0002B0FD, 0x0002B127,
    0x0002B0FE, 0x0002B125,    0x0002B8D1, 0x0001BCD1,
    0x0002DCD9, 0x0002DC38,    0x0002DB45, 0x0002DC39,
    0x0002DCDD, 0x0002DC9F,    0x0002DCDE, 0x0002DC72,
    0x0002DCE0, 0x0002DCCF,    0x0002DED7, 0x0002DF0C,
    0x0002DED8, 0x0002DF0E,    0x0002E03C, 0x0004EF36,
    0x0002E0E4, 0x0002E0EA,    0x0002E5E4, 0x0002E5FD,
    0x0002FCC7, 0x0002FD33,    0x00030602, 0x0002A019,
    0x0003D447, 0x0003D44A,    0x0003C840, 0x0003B371,
    0x0003C841, 0x0003BCE7,    0x0003C847, 0x0003B1D2,
    0x0003C947, 0x0003C96F,    0x0003C948, 0x0003C99C,
    0x0003C949, 0x0003C99E,    0x0003BD8C, 0x0003D616,
    0x0003C2FA, 0x0003D68F,    0x000433AC, 0x000414F7,
    0x00043B8A, 0x00043DD5,    0x00043B8B, 0x00043CC2,
    0x00044B12, 0x00044B11,    0x00044B14, 0x00044B13,
    0x00044D09, 0x00044DA7,    0x00048190, 0x000482CE,
    0x00048191, 0x000482CF,    0x00048192, 0x000482CD,
    0x00048306, 0x0002D15E,    0x0004BC64, 0x0004EF67,
    0x0004BC65, 0x0004EF5D,    0x0004CCE9, 0x0004CFA3,
    0x0004CCEA, 0x0004CD80,    0x0004CEF7, 0x0004CDAA,
    0x0004CEF8, 0x0004CD24,    0x0004D030, 0x0002E07D,
    0x0004D031, 0x0002E079,    0x0004E73A, 0x000509DF,
    0x0004EF46, 0x0004EF4D,    0x0004EF73, 0x0004EF72,
    0x0004F135, 0x00050090,    0x0004F656, 0x0004F757,
    0x0004F657, 0x0004F756,    0x00050F55, 0x00050F54,
    0x00051466, 0x00051465,    0x00051467, 0x00050B84,
    0x000560F4, 0x0001B9D5,    0x0004021A, 0x0004022D,
    0x00042F27, 0x00042F40,    0x0004E1C4, 0x0004E1A6,
    0x00057E2A, 0x00057E00,    0x00058BFB, 0x000AB578,
    0x0003F535, 0x00059A0B,    0x0003F538, 0x00018308,
    0x0005AAB5, 0x0005AB2E,    0x0005AB78, 0x0005AB30,
    0x0005D863, 0x000689C3,    0x000301E6, 0x0002F14B,
    0x00063B37, 0x00063B2B,    0x00063B72, 0x00063B71,
    0x000687CD, 0x0002D775,    0x00068C88, 0x00068C84,
    0x0006A17B, 0x00045268,    0x0006C247, 0x0006C246,
    0x0007012B, 0x0004203C,    0x000752C9, 0x000752D8,
    0x000752CA, 0x000752D9,    0x00079F14, 0x000184E2,
    0x00089C77, 0x000184CA,    0x0006F6A6, 0x0006F6B1,
    0x00093706, 0x00093665,    0x00098743, 0x00098737,
    0x0003DFC6, 0x0003DFC2,    0x0009C4CB, 0x000184E8,
    0x0009DF52, 0x0009DF51,    0x0009DF53, 0x0009DF50,
    0x000A5E88, 0x000A5E83,    0x000A6F41, 0x000513CF,
    0x0005DD39, 0x000AB579,    0x000B36E4, 0x000181A3,
    0x000B5F0B, 0x000B5F6E,    0x000B754F, 0x000B7A49,
    0x000B7550, 0x000B8B5B,    0x000B754E, 0x000B9D13,
    0x00018E56, 0x00036F6A,    0x000190F2, 0x000190FC,
    0x000B548B, 0x0004E6D1,    0x0001FC8F, 0x0001FD11,
    0x00023603, 0x0002362F,    0x000B9E64, 0x000038B8,
    0x00024ECA, 0x00017ECA,    0x0002A344, 0x0002A350,
    0x00017281, 0x0002DBD8,    0x0002DBE5, 0x0002DBE1,
    0x0002DF06, 0x0002DF0D,    0x00039272, 0x00039225,
    0x00039391, 0x00039393,    0x000392A7, 0x000392C5,
    0x0003E897, 0x0003E91E,    0x0003EE0D, 0x0003EE16,
    0x00061520, 0x0006151A,    0x00061BB7, 0x000615C8,
    0x00064BFD, 0x00064C5C,    0x00064BFF, 0x00064D20,
    0x00064C00, 0x00064CBC,    0x00064D38, 0x00064D27,
    0x00070C6C, 0x0004423F,    0x00076E41, 0x0007684B,
    0x00076E42, 0x000C578E,    0x00076E43, 0x000C578D,
    0x00076E44, 0x00051E81,    0x00076E45, 0x00051E82,
    0x00076E46, 0x0007684D,    0x00076E48, 0x0007684E,
    0x00076E49, 0x0007684C,    0x000606B7, 0x0001F1FA,
    0x000C25A7, 0x000C26C3,    0x000C25EA, 0x000C25D7,
    0x000C2677, 0x000C2606,    0x000C2727, 0x000C26C6,
    0x000C27B0, 0x000C2FCC,    0x000C27BB, 0x000C2FCE,
    0x000C30AF, 0x000C3042,    0x000C3C1C, 0x000C3C1D,
    0x000C84C5, 0x000C84C6,    0x0005608F, 0x000C9201,
    0x000494D2, 0x000C9A46,    0x00049C94, 0x000C99FD,
    0x000CA776, 0x00043D04,    0x000CA9F7, 0x000CA9F0,
    0x0009CA2A, 0x000CB0E0,    0x0009DBB2, 0x00020B99,
    0x000A4291, 0x000349DE,    0x00044C5E, 0x0003CFC1,
    0x0004E6F3, 0x0004E8E6,    0x0004E776, 0x0004E89C,
    0x0005281B, 0x00052811,    0x00049135, 0x00052ADB,
    0x00054CDD, 0x00056D22,    0x00054DEF, 0x00054DD5,
    0x00056ECC, 0x00057116,    0x000C991F, 0x000574ED,
    0x0005C1E0, 0x0005C1C2,    0x00022F27, 0x00064C70,
    0x0006744D, 0x0003C57B,    0x0006753C, 0x00018250,
    0x0004960E, 0x00056975,    0x000178C0, 0x000172E7,
    0x0001835E, 0x000173CB,    0x000310CC, 0x000310F7,
    0x00020A5F, 0x00020A5D,    0x000A5401, 0x0003D824,
    0x0003D51A, 0x0003D583,    0x0002D247, 0x0002D205,
    0x0001B8B9, 0x0001B8B0,    0x00035EA3, 0x0002324D,
    0x000317B5, 0x0003179F,    0x00030B1E, 0x000317B4,
    0x000181B0, 0x000181BD,    0x000181B1, 0x000181A2,
    0x0004561A, 0x0004561C,    0x0004561B, 0x0004561F,
    0x00018635, 0x00003BB5,    0x00050BEA, 0x000514D2,
    0x00050BEC, 0x00050BEB,    0x0007CEE4, 0x0004B3F3,
    0x000182CF, 0x000182DD,    0x00074EDE, 0x0001865C,
    0x000B037B, 0x00024E1B,    0x000C5863, 0x000C585D,
    0x0002915D, 0x0004AEA2,    0x000509E3, 0x00050A18,
    0x000509E2, 0x00050A17,    0x0002D96D, 0x0002D96C,
    0x0002D204, 0x0002D230,    0x00095E8F, 0x00095E91,
    0x00095E8E, 0x00095E5A,    0x0003ED59, 0x0001B900,
    0x0001B8BE, 0x00023240,    0x0001B8C9, 0x0001B8EC,
    0x0001B8CA, 0x0001BD24,    0x000180A3, 0x000180B0,
    0x000356CB, 0x00035363,    0x00018589, 0x000185FA,
    0x00054830, 0x000547B2,    0x0001F802, 0x0005AE0C,
    0x00044AA6, 0x00044A10,    0x00043DD6, 0x00043CC3,
    0x000181BE, 0x000181A4,    0x00003BBA, 0x00003C72,
    0x0001824E, 0x0001825C,    0x0001824F, 0x0001826A,
    0x00003CEF, 0x00003C51,    0x00070B96, 0x00024A08,
    0x00070C6A, 0x00025CD0,    0x000182DE, 0x000182EA,
    0x0003BCC5, 0x0003BCF7,    0x00052F32, 0x00053C9B,
    0x00052F33, 0x00053C9A,    0x0001837B, 0x0001838A,
    0x0001837C, 0x00018396,    0x000267B2, 0x00025F72,
    0x000513D1, 0x00051271,    0x000513D0, 0x00053E43,
    0x000513B3, 0x00053E3C,    0x000513AC, 0x00029043,
    0x00045267, 0x00020FD8,    0x0002FA9E, 0x0002FA60,
    0x0002FB26, 0x0002FB24,    0x00095E93, 0x00095E92,
    0x00095E94, 0x00095E59,    0x0001B928, 0x0001BD22,
    0x00053EEE, 0x00053E8E,    0x00053E41, 0x00053D2E,
    0x0003ACEF, 0x0003AD3A,    0x0003AD0E, 0x0003ADA6,
    0x0003AD1C, 0x0003ADF4,    0x0003AE20, 0x0003ADAF,
    0x0003AD1F, 0x0003AE79,    0x0003AD1D, 0x0003AE6F,
    0x000A39A1, 0x000A39A9,    0x0001DF0E, 0x0001DF6C, // jefferson basement
    0x00018649, 0x00018652,    0x0001CC21, 0x0001C984, // jefferson rotunda
    0x0002DCA0, 0x0002DC5F,    0x0001BD21, 0x0001B910,
    0x00018389, 0x00018397,    0x0006184C, 0x0006184D,
    0x000AFDC1, 0x0007F7E3,    0x00036C33, 0x00036E9E, // :) big small world
    0x000209C5, 0x00020A3D,    0x000209C4, 0x000209CA,
    0x0002F8A2, 0x0002F898,    0x0002F8A1, 0x0002F897,
    0x000181E7, 0x000181F4,    0x00003B39, 0x00003F8E,
    0x0002DD62, 0x0002A93C,    0x00047E6F, 0x00047E36,
    0x000882F6, 0x000882F5,    0x000182FA, 0x00018309,
    0x00053D1B, 0x00053E1F,    0x00040710, 0x000407D7,
    0x0001FA1D, 0x0001FA59,    0x0001F6BD, 0x0001FA3A,
    0x0003D3DF, 0x0003D811,    0x0003179C, 0x000317A4,
    0x00043F60, 0x00044248,    0x000185FB, 0x00018609,
    0x00074F5A, 0x000B5CFB,    0x00004440, 0x00014A88,
    0x0003A572, 0x000468E6,    0x0003AF6D, 0x0003E8F8,
    0x00096177, 0x00095F5B,    0x0001865B, 0x00018674,
    0x0002BCA0, 0x0002BD2B,    0x000603F3, 0x000752D7,
    0x000603FE, 0x0004EDAB,    0x00050D6A, 0x0005043B,
    0x000181F9, 0x00018206,    0x000181FA, 0x00018214,
    0x000446E7, 0x000506E1,    0x00018177, 0x00018186,
    0x00018178, 0x00018192,    0x00095EB4, 0x00095E58,
    0x00095EB5, 0x00095E57,    0x00022650, 0x0002270A,
    0x00018185, 0x00018193,    0x000182A4, 0x000182BF,
    0x0001727D, 0x000172F6,    0x00053E9B, 0x00053E71,
    0x0002268C, 0x0002270C,    0x0002268B, 0x0002270B,
    0x00039B70, 0x00039B6F,    0x00042039, 0x000420E8,
    0x0004202D, 0x000420EA,    0x0005092E, 0x000509FC,
    0x00063B70, 0x00063B98,    0x000560EC, 0x0001B9D4,
    0x0001B9FC, 0x0001B8E8,    0x00098744, 0x00098738,
    0x00019B4E, 0x000B5CE6,    0x0005C28B, 0x00069FC3,
    0x00053E8F, 0x00053E20,    0x00096D8B, 0x0003C8B0, // :)
    0x000185E8, 0x00018617,    0x0005364D, 0x00053671,
    // ^ vault 112 entrance    ^ smith casey upstairs
    0x00003B2C, 0x00003B24,
    // ^ megaton gates
    // 0x000790FB, 0x000790FA,
    // ^ megaton follower exits? "follower escape hatch"
    // under map and not visible. makes 1 ways

    // vault 101 - homefront
    0x000B57FF, 0x000B553E,    0x000B5742, 0x000B5AA4,
    0x000B5A7E, 0x0009A6EF,    0x000B5756, 0x000BB795,
    0x000B5715, 0x000B5A74,    0x000B5718, 0x000B55BE,
    // 0x0009B5A0, 0x00099F16,
    // this is the vault 101 outside cave door again
    // effectively becomes a 1-way because the quest
    // swaps this with the child (pre-homefront/MS16) versions

    // 0x0006B945, 0x0003DC6F,    0x000B5C33, 0x000B5C3E,
    // ^ taft intended door    ^ taft upper smol door
    // these can be reached with some parkour...but
    // touching taft before the Li escort advances some stage.
    // then there are barriers up and she may bug out at the
    // end game during "take it back"
    // 0x0002F876, 0x0001B625,
    // ^ taft exit by citadel - locked until end of waters of life
    // 0x0005CF55, 0x0001CC7D,
    // ^ sewer to taft tunnels. only active 1 time during quest.
    // gets locked off from jefferson and plasma walled
    // off in tunnel after clearing taft.

    // 0x0001E005, 0x0001DED3, 0x0001DFF1, 0x0001DEC1,
    // 0x0001DFF7, 0x0001DEDA, 0x0001DEDB, 0x0001DFE2,
    // ^ pipes for waters of life (jeff, outside, under)
    // both sides get locked before/after quest

    // 0x000039B7, 0x00015203,
    // ^ player house for saving megaton - quest locked
    // logic thinks you can always go through this too
    // but also...
    // 0x000179D3, 0x000179D1, 0x00017191, 0x00017972,
    // ^ tenpenny player house - quest locked
    // tends to crash when enter/exiting before getting
    // the key? or just because? excluding for crashes

    // 0x0004B9DD, 0x00018350, 0x0002281B, 0x0002270D,
    // ^ tenpenny front        ^ roys front
    // 0x00021FC4, 0x00021FB6, 0x00022646, 0x0002270E,
    // ^ tenpenny basement to gen - ^ roys basement
    // 0x000A3422, 0x0004C333,
    // ^ tenpenny toy's alister balcony
    // doing roy's quest resets the front, generator and balcony
    // for a few days so those doors would never be reachable
    // during normal playthroughs and be 1-ways.
    // generator room is a 'shared cell', 1 door behind the other.
    // these will both always be 1-ways, but you'd have
    // to cut the whole tenpenny'attack' version so it stays.
    // 0x0004C6CA, 0x0004C6C8,
    // ^ tenpenny attack follower escape hatch, similar to megaton

    // 0x00019409, 0x0001940B,
    // ^ warrington station - quest locked from roy tenpenny quest

    // 0x00034A35, 0x00069647,
    // ^ paradise falls children exit. the player can never use this

    // 0x0002A088, 0x000181D4,
    // ^ statesment top floor - quest + fission/repair locked
    // reillys rangers, if you come in this way, there are invisible
    // walls blocking you, and you can only leave if you have a battery
    // AND 75 repair. the inside door is also locked.

    // 0x0001863A, 0x000ABD29, 0x000A53BD, 0x000A257B,
    // ^nat archives - sydneys elevator ^ gwinnett's rooms
    // if she dies or turns hostile this cannot spawn in.
    // the big double doors are locked from a terminal,
    // which is locked from buttons code

    // 0x0004623F, 0x0006F1ED, 0x0006F20C, 0x0006F20F,
    // ^ contract killer       ^ lawbringer
    // these doors only spawns when you get the karma perks

    // 0x00021025, 0x00045612,
    // ^ little lamplight computer door to vault 87
    // not active until joeseph unlocks in main quest

    // 0x00021E98, 0x00026231,    0x00021E99, 0x00026F82,
    // ^ gnr 'top outside' doors most ppl forget
    // left 1 is reachable, but inside is quest locked
    // 0x0001B89C, 0x0002625A, 0x0001B9FB, 0x0002622E,
    // ^ three-dog to dupont circle ^ gnr entrance
    // 0x0002627D, 0x00026F63, < inside gnr
    // you cannot enter backwards.
    // (even though it is barely possible to climb up to it)
    // a message pops up about it being "a one-way door"
    // entrance is quest locked.
    // since both sides are a no go, don't touch gnr proper either.

    // 0x0004665B, 0x000467BE,
    // ^ capitol building 'hall of columns' / 'conference hall'
    // 4665b side, invisible walls before script or quest

    // 0x0001BD32, 0x00018626, 0x0007201E, 0x00072020,
    // ^ washington monument base ^ elevator
    // the oob doors swap, but elevator script doesn't care.
    // always takes you to top by dish.
    // outside is quest locked and you can travel to mall anyway.

    // 0x0004BC2F, 0x00059C3F,  0x0004BC30, 0x00059BEF, :(
    // ^ refugee tent           ^ calebs tent
    // 0x0004BC40, 0x00059C04,
    // ^ simone tent
    // these are quest locked for 'head of state.
    // all drop you middle of air outside lincoln memorial.

    // 0x000A3A87, 0x000A5F56,
    // ^ vault 92 overseer
    // overseer hatch doesn't open. sound testing side has broke door.

    // 0x00060176, 0x000600E2,
    // ^ arefu bottom house - quest locked
    // 0x0001D5FC, 0x0001D622,    0x0001D5FD, 0x0001D695,
    // ^ ewer                      ^ schenzy
    // unfortunately these are quest locked.
    // unless swapped with another locked door, no way in.

    // 0x000A0D80, 0x0005634C, 0x000A2432, 0x000A2433,
    // ^ harold                ^ front oasis
    // 0x00035B81, 0x00035B6E,
    // oasis sunken chambers - all quest locked
    0x0, 0x0,
};

// these may softlock?
// you cannot access them after you leave
const uint32_t vault101child_doors[] = {
    0x00052197, 0x00052196,    0x00028579, 0x0005398D,
    0x0005398B, 0x00054285,    0x000290D8, 0x0009DB79,
    // 0x00018612, 0x00024720,
    // ^ vault 101 wooden cave door to outside
    // see notes about homefront swapping it
    0x0, 0x0,
};

// the chair is a major softlock unless you avoid it entirely.
// if you use it first, chances are the doors inside will go to the
// outside world, and you're defenseless. if you go in after doing
// the quest then leave, you sit in the chair for the 'first time'
// and get pulled back in, softlocking you as a kid.
const uint32_t tranquility_doors[] = {
    0x00024C1D, 0x00024CD9,    0x0002B536, 0x0002B558,
    0x00024BE9, 0x00024C65,    0x00024C40, 0x00024CAF,
    0x00024BF7, 0x00024CB4,    0x00024C0A, 0x00024C6A,
    0x000298D2, 0x000298D1,
    // 0x000252D8, 0x000252D9,
    // ^ failsafe exit - becomes 1-way, ALWAYS takes you to chair.
    // leaves you without pip-boy and its 'door' is actually oob
    // next to a box it puts your items before simulation.
    // so that door is unreachable.
    //
    // if you go to 112 to talk to dad, you get the quest, exp and
    // things seem ok, except he doesn't move or walk to you.
    // going to rivet he does talk to li and the main quest continues.
    0x0, 0x0,
};

// nothing particularly wrong with these but you don't get
// a proper quest marker at the end of finding murder pass.
// so it makes finding these a huge pain in the ass.
// threw citadel and jefferson front in here too.
// simliar issues. citadel has no quest marker because the door
// is literally right in front of you at this stage.
// jefferson pipes are actually outside and you have to go
// inside and hope the map routes you somewhere different.
// you CAN reach citadel by glitching or taking a specific OOB
// path to get behind the gate/door.
// you CAN reach jefferson with a specific path, or glitching,
// after enclave.
const uint32_t vault87_doors[] = {
    0x00021026, 0x00020FD9,    0x0002F4D4, 0x0002F4CA,
    0x0002F4CD, 0x0002F4DD,
    // ^ murder > living > test labs
    0x0001560D, 0x000155F5,    0x0001DFEA, 0x0001BD73,
    // ^ citadel front         ^ jefferson front
    0x0, 0x0,
};

// you can get into raven rock from outside in base game
// but it has invisible walls all over inside.
// if you tcl past them, most doors are locked or inaccesible
// as you're not in the right quest stage.
const uint32_t ravenrock_doors[] = {
    0x0001E338, 0x0001E339,    0x0001E337, 0x0001E336,
    0x0001E33A, 0x0001E33B,    0x000AEC1B, 0x000AEB62,
    0x0001E352, 0x0001E351,
    // ^ raven rock to outside - may be disabled after quest?
    0x0, 0x0,
};

// the whole simulation is trying to softlock you
// so only the main world doors are included
const uint32_t anchorage_doors[] = {
    0xFF005691, 0xFF00287E,    0xFF0028BC, 0xFF00288B,
    // ^ baileys entrance to main map ^ baileys exit
    0xFF003293, 0xFF00136E,
    // ^ elevator door to outcast
    // (actual door hidden under elevator)
    // it works fine, unlike washington monument

    // the problem with 'cliffs' is it's all 1 cell
    // but it is clearly split into 2, with the cave
    // interior blocking it

    // 0xFF0048A9, 0xFF004947, 0xFF004D24, 0xFF004D1E,
    // cliffs entrance/exit. if you go inside without
    // starting the quest, you reach a point where
    // montgomery is supposed to talk to you. since
    // you're breaking sequence he doesn't, and the
    // metal sliding door in front of you and behind
    // you get holo-walled off for some reason.
    // so you're softlocked.

    // 0xFF00B9B1, 0xFF00B9B0,     0xFF00B9B7, 0xFF00B9BF,
    // ^ cliffs side cave passage
    // 0xFF00B4EE, 0xFF00B4F7,     0xFF00B4EF, 0xFF00B529,
    // ^ intel doors
    // as these are the only doors in the simulation that
    // won't lock on you, they're completely useless.
    // 2 of them lead to 2 doors that will lock you
    // (artillery and cave) and you won't be able to get
    // out after you beat the DLC. the inside 2 are neat but
    // are just a tunnel room that will likely lock you

    // 0xFF001550, 0xFF001458, 0xFF000D64, 0xFF001426,
    // ^ to artillery          ^artillery outpost
    // no way back here. and the doors are is behind
    // a hologram version in the walls.
    // the only way out, is blowing the guns up so
    // the quest will teleport you.

    // 0xFF0015EE, 0xFF0015ED,
    // ^ commander's tent - runs script and softlocks

    // 0xFF001A97, 0xFF001B46,    0xFF001AD2, 0xFF001B15,
    // ^ listening post top and bottom
    // only 1 of these is reachable, so the other can't stay.
    // even they did, it's only 2 doors for this whole area.

    // 0xFF001885, 0xFF001098,
    // ^ pulse field door - end of DLC fight with chinese
    // this door is never intended to be walked through
    // the other way. player controls get disabled
    0x0, 0x0,
};

const uint32_t pitt_doors[] = {
    0xFF00150A, 0xFF0011B7,    0xFF007E02, 0xFF0011B5,
    0xFF00602D, 0xFF0060A0,
    0xFF00602E, 0xFF0061B2,    0xFF006973, 0xFF0066B2,
    0xFF001509, 0xFF0011C1,    0xFF001505, 0xFF007E01,
    0xFF0011C0, 0xFF00150F,    0xFF001503, 0xFF00108F,
    // ^ dupe with broken steel ^ midea's hut
    0xFF0009A9, 0xFF004E8F,    0xFF0094A7, 0xFF008E34,
    // ^ door to pitt with handcar
    // sort of a 1 way, until you talk to wernher
    // will always take you to pitt entrance spot (not a door)

    // 0xFF00A36E, 0xFF009AFE, 0xFF001507, 0xFF00150E,
    // ^ uptown quest locked - door behind another door to downtown
    // 9AFE swaps when you finish arena and go to downtown
    // A36E is always behind 1507

    // 0xFF00150B, 0xFF00150C,
    // ^ pitt front gate
    // quest locked on inside until you complete pitt

    // 0xFF001506, 0xFF0011B8,
    // ^ uptown and mill - quest locked

    // 0xFF004627, 0xFF004626, 0xFF006971, 0xFF0066C1,
    // ^ steelyard to wernher end and ^sewer - quest locked

    // 0xFF001510, 0xFF001520,
    // ^ arena - quest locked, and shared cell
    0x0, 0x0,
};

const uint32_t pointlookout_doors[] = {
    0xFF00A55C, 0xFF00821A,    0xFF00DF58, 0xFF00DF24,
    0xFF00B57E, 0xFF00BF41,    0xFF00AFEC, 0xFF00AFDD,
    0xFF00BF62, 0xFF00BF1E,    0xFF00C0B3, 0xFF002F2C,
    0xFF0088F2, 0xFF00C2C5,    0xFF00C50D, 0xFF008161,
    0xFF00C532, 0xFF008174,    0xFF00C0B8, 0xFF00C824,
    0xFF00C0B9, 0xFF00C816,    0xFF00C0BA, 0xFF00C81C,
    0xFF00D202, 0xFF00CAEC,    0xFF00E27E, 0xFF00E282,
    0xFF00D6B1, 0xFF00D6BE,    0xFF00DA2E, 0xFF00DA2D,
    0xFF00DDD6, 0xFF0081C1,    0xFF00DF5A, 0xFF00DF25,
    0xFF00B2D2, 0xFF00E804,    0xFF00BFF8, 0xFF00E94A,
    0xFF00A55B, 0xFF008214,    0xFF00B14E, 0xFF00EDB0,
    0xFF00A546, 0xFF008264,    0xFF00A54A, 0xFF00826A,
    0xFF00C04A, 0xFF00E906,    0xFF011FA2, 0xFF011EF3,
    0xFF00B5D3, 0xFF00B58E,

    0xFF0081ED, 0xFF0081C9,    0xFF00CDDB, 0xFF00E8AE,
    0xFF00CDE8, 0xFF00E8E3,    0xFF00CDD8, 0xFF00E8AC,
    // ^ motels

    0xFF0081C0, 0xFF0081C2,    0xFF008866, 0xFF008869,
    // 0xFF00F030, 0xFF00F7B3, ^ blackdamp shaft
    // ^ "miners rest" locked ladder - requires key

    0xFF00DDFB, 0xFF00E17E, // 0xFF00F2D2, 0xFF009B7A,
    // ^ plik               ^ plik's safari
    // locked until you start plik's 'side quest'

    0xFF00CA58, 0xFF00F082,    0xFF006BE5, 0xFF00F080,
    // ^ lighthouse top        ^ lighthouse bottom
    // 0xFF0097C3, 0xFF00F081,
    // ^ end of meeting of minds under lighthouse
    // 0xFF01099E, 0xFF01099D,
    // ^ meeting of the minds exit hatch
    // quest locked

    0xFF008311, 0xFF004F15,    0xFF008312, 0xFF004E71,
    // ^ blackhall
    // 0xFF00F8D2, 0xFF004FC0, 0xFF00AE73, 0xFF00B05E,
    // ^ blackhall basement    ^ ritual site
    // quest locked for giving him book, and starting quest

    // 0xFF00B86B, 0xFF00BF18, 0xFF00D3D8, 0xFF01034E,
    // ^ tobar's room          ^ 'engine' room (DC side)
    // these switch somehow so even after you unlock it
    // i think it's a semi-1way

    // 0xFF00643D, 0xFF007357, 0xFF007359, 0xFF0073A7,
    // ^ top hatch end of chinese spy quest - ^basement
    // 0xFF00B46A, 0xFF0073AE,
    // ^ escape pipe side - too steep to climb

    // 0xFF003F16, 0xFF00311F, 0xFF011D64, 0xFF011D85,
    // ^ calver mansion        ^ desmond bunker?
    // gets blown up, quest locked

    // 0xFF00438F, 0xFF0042E4, 0xFF00583B, 0xFF0093A7,
    // ^ ark dove cathedral    ^ wrecked seatub
    // 0xFF006B69, 0xFF00951A,
    // ^ well to sea caves - all quest locked

    // 0xFF007AFA, 0xFF00E925, 0xFF00A8E0, 0xFF00E931,
    // ^ bog map entrance      ^ bog
    // quest locked, don't think you can go back
    // tunnel may not be quest locked, but would have to test
    0x0, 0x0,
};

const uint32_t zeta_doors[] = {
    // sadly, this whole DLC is unusable for door randomizing.
    // even though some of these rooms are neat and have multiple
    // doors, you get completely locked off to most of them after
    // half way through, or beating, the DLC.
    // and if doors are random, you will may have to beat
    // the DLC to exit, which defeats the purpose.

    // 0xFF0015FE, 0xFF001603,    0xFF005D40, 0xFF005D3F,
    // 0xFF00D2E6, 0xFF00D2E9, // these 3/6 are secrets :)
    // check them out if you have some time. player.moveto <??xxxxxx>
    // can't even use but 1 of them...

    // 0xFF0079B0, 0xFF0056AA,    0xFF0043C8, 0xFF0043D1,
    // 0xFF0043CA, 0xFF00307F,    0xFF007FF2, 0xFF00800B,
    // 0xFF005F8C, 0xFF005F8D,    0xFF005FCC, 0xFF006B12,
    // 0xFF0048C3, 0xFF00492B,    0xFF00487C, 0xFF004BD4,
    // 0xFF00334F, 0xFF0032F6,    0xFF0038D9, 0xFF0038DC,
    // 0xFF005B23, 0xFF005B27,    0xFF004BD1, 0xFF0067DA,
    // 0xFF003089, 0xFF003098,    0xFF007FE5, 0xFF007EF3,
    // 0xFF003B3A, 0xFF0032F4,    0xFF00334E, 0xFF0032F5,
    // 0xFF005D31, 0xFF009169,    0xFF00B458, 0xFF00B42C,
    // 0xFF003533, 0xFF0032F9,    0xFF004BBC, 0xFF004BBB,
    // 0xFF0032F8, 0xFF006D5B,    0xFF0032FA, 0xFF003350,
    // 0xFF002C03, 0xFF00C370,    0xFF0039B4, 0xFF0039B5,
    // misc doors inside the ship.
    // most of the 'teleporters' are disabled willy-nilly

    // 0xFF00A98C, 0xFF00A98B,    0xFF00D2CA, 0xFF00D25C,
    // ^ homing beacon            ^ bridge - both post DLC
    // beacon can disable player movement =(
    // may be from teleporting to the final room
    // and beating DLC, then beaming up after.

    // 0xFF00309F, 0xFF003099,    0xFF00711C, 0xFF0056A9
    // ^ bridge 'oldtele'        bio engineering access ^
    // same destination. literally under map of 'oldtele'
    // disabled after beating DLC

    // 0xFF0031AF, 0xFF0031AE,    0xFF0032EF, 0xFF0032F2,
    // ^ steamworks               ^ holding cells
    // the only way out of holding is steamworks.
    // and the only way into holding is the beam up script

    // 0xFF004E63, 0xFF004E64,
    // ^ 'outside airlock' door (before yap city)
    // going through this seems to go the wrong way.
    // it is supposed to be mid way through the DLC
    // past the point of no return for the first half
    // of the ship, where you need the spacesuit or die
    0x0, 0x0,
};

const uint32_t brokensteel_doors[] = {
    0xFF003C68, 0xFF00BE0C,    0xFF007CA6, 0xFF00739B,
    0xFF0022ED, 0xFF00234A,    0xFF0022F9, 0xFF002349,
    0xFF00248B, 0xFF00248A,    0xFF00248C, 0xFF006EFB,
    0xFF00444D, 0xFF004449,    0xFF008AF8, 0xFF008A11,
    0xFF000FC9, 0xFF004543,    // stairs from prez tunnel
    0xFF004452, 0xFF004448,    // ATC technically a house
    0xFF008AF7, 0xFF008A10,    // balcony
    0xFF0068E6, 0xFF0068E4,    // hanks
    0xFF00734D, 0xFF007340,    // random silo top-mid of map by water reservoir
    0xFF006EFA, 0xFF006EF9,    0xFF001F45, 0xFF001F0E,
    0xFF00248D, 0xFF00248F,    0xFF0043A3, 0xFF00406A,
    0xFF00406B, 0xFF0045B4,    0xFF00406E, 0xFF0045B3,
    0xFF00734E, 0xFF00733F,

    // 0xFF006852, 0xFF006851,
    // ^ hatch to hanks electrical supply
    // on top of building by jurry st metro, no way to reach

    // 0xFF003A22, 0xFF003A35,
    // ^ springvale cellar to cult - quest locked

    // 0xFF003A50, 0xFF005D8D,
    // ^ water bandit hideout by washington monument - quest locked

    // 0xFF001491, 0x7F00150F, 0xFF00151D, 0xFF00151C,
    // ^ dupe with pitt - entrance to rockland and other side
    // both quest locked

    // 0xFF0091C0, 0xFF000915,
    // ^ this door is quest locked at the end of rockcar tunnel
    // after sat codes, the start quest of "death from above"

    // 0xFF00BE09, 0xFF00BE01,
    // ^ olney manhole to paperworks - quest locked

    // 0xFF009193, 0xFF00A44F,
    // ^ ladder inside olney sewers to electroboom - quest locked

    // 0xFF000B16, 0xFF000917,
    // ^ where prime blows up - quest locked and walled

    // 0xFF0020A9, 0xFF0020A3,
    // ^ quest locked prez metro doors

    // 0xFF001075, 0xFF001079,
    // ^ prez sublevel - quest locked

    // 0xFF00BCD8, 0xFF00BCD7,
    // underground doors between prez metro lines.
    // if you're lucky, you end up in the car

    // 0xFF002490, 0xFF006EF8,
    // ^ mobile base ground entrace - quest triggers stairs to fall

    // 0xFF00D2C7, 0xFF00D2B7,
    // NPC door? middle of crawler...outside of sat ctrl tower

    // 0xFF001BAD, 0xFF007539, up top - assume replaces normal entrance
    // 0xFF009775, 0xFF0095CA, armory up top (another smol door)
    // 0xFF009774, 0xFF0095CB, - armory bottom
    // ^destroyed citadel - unclimbable pitt is a no go =/
    0x0, 0x0,
};
