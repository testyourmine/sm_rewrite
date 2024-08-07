#pragma once

#include "types.h"

#define PLMS_ENABLED 0x8000
#define MAX_PLMS 80
#define PLM_TYPE_BTS(blk_type, bts) ( ((blk_type) << 12) | (bts))
#define SET_BLK_TYPE(blk, blk_type) ((blk) & ~(0xF000) | ((blk_type) << 12))
#define DEACTIVATE_BLK(blk) ((blk) & 0x8FFF)

#define BLK_HORIZ_FLIP 0x400
#define BLK_VERT_FLIP 0x800
#define BLK_HAS_FLIP (BLK_HORIZ_FLIP | BLK_VERT_FLIP)
#define BLK_X_FLIP 0x4000
#define BLK_Y_FILP 0x8000
#define BLK_X_Y_FLIP (BLK_X_FLIP | BLK_Y_FILP)

#define DRAW_VERTICAL 0x0000
#define DRAW_HORIZONTAL 0x8000

//#define kGoldenTorizoPalette1 ((uint16*)RomFixedPtr(0x848032))
//#define kGoldenTorizoPalette2 ((uint16*)RomFixedPtr(0x848132))

uint16 kGoldenTorizoPalette1[] = { 0x1000, 0x56ba, 0x41b2, 0x1447,  0x403, 0x4e15, 0x3570, 0x24cb, 0x1868, 0x6f7f, 0x51f8, 0x410e,  0x31f,  0x1da,   0xf5,  0xc63, 
								   0x1000, 0x56db, 0x39d3, 0x1047,  0x403, 0x4636, 0x2d91, 0x20ec, 0x1489, 0x6f9b, 0x5215, 0x3d2c, 0x133b,  0xdf6,  0xcf2,  0xc63, 
								   0x1000, 0x52fb, 0x31f4, 0x1067,  0x402, 0x3e76, 0x25b2, 0x192d, 0x10a9, 0x6f96, 0x5251, 0x396a, 0x2756, 0x1a13, 0x190f,  0x863, 
								   0x1000, 0x531c, 0x2a15,  0xc67,  0x402, 0x3697, 0x1dd3, 0x154e,  0xcca, 0x6fb2, 0x526e, 0x3588, 0x3772, 0x262f, 0x250c,  0x863, 
								   0x1000, 0x4f5c, 0x1e56,  0x888,    0x1, 0x2eb8, 0x1a13, 0x116f,  0xceb, 0x73ad, 0x4eaa, 0x35a6, 0x4b8d, 0x364b, 0x3509,  0x443, 
								   0x1000, 0x4f7d, 0x1677,  0x488,    0x1, 0x26d9, 0x1234,  0xd90,  0x90c, 0x73c9, 0x4ec7, 0x31c4, 0x5ba9, 0x4267, 0x4106,  0x443, 
								   0x1000, 0x4b9d,  0xe98,  0x4a8,    0x0, 0x1f19,  0xa55,  0x5d1,  0x52c, 0x73c4, 0x4f03, 0x2e02, 0x6fc4, 0x4e84, 0x4d23,   0x43, 
								      0x0, 0x4bbe,  0x6b9,   0xa8,    0x0, 0x173a,  0x276,  0x1f2,  0x14d, 0x73e0, 0x4f20, 0x2a20, 0x7fe0, 0x5aa0, 0x5920,   0x43, };

uint16 kGoldenTorizoPalette2[] = { 0x1000, 0x4215, 0x2d0d,    0x2,    0x0, 0x3970, 0x20cb,  0xc26,  0x403, 0x463a, 0x28b3, 0x1809, 0x6f7f, 0x51fd, 0x4113,  0xc63, 
								   0x1000, 0x4236, 0x252e,    0x2,    0x0, 0x3191, 0x1cec,  0xc47,  0x424, 0x4656, 0x28d0, 0x1428, 0x6f7b, 0x51f9, 0x40f0,  0xc63, 
								   0x1000, 0x3e56, 0x214f,    0x2,    0x0, 0x29d1, 0x190d,  0x888,  0x424, 0x4693, 0x290e, 0x1046, 0x6f76, 0x4df5, 0x40ee,  0x842, 
								   0x1000, 0x3e77, 0x1970,    0x2,    0x0, 0x21f2, 0x152e,  0x8a9,  0x445, 0x46af, 0x292b,  0xc65, 0x6f72, 0x4df1, 0x40cb,  0x842, 
								   0x1000, 0x3ab7, 0x15b1,    0x3,    0x0, 0x1a13,  0xd6e,  0x4ca,   0x66, 0x4acb, 0x2568,  0xc84, 0x6b4d, 0x4a0c, 0x44c8,  0x421, 
								   0x1000, 0x3ad8,  0xdd2,    0x3,    0x0, 0x1234,  0x98f,  0x4eb,   0x87, 0x4ae7, 0x2585,  0x8a3, 0x6b49, 0x4a08, 0x44a5,  0x421, 
								   0x1000, 0x36f8,  0x9f3,    0x3,    0x0,  0xa74,  0x5b0,  0x12c,   0x87, 0x4b24, 0x25c3,  0x4c1, 0x6b44, 0x4604, 0x44a3,    0x0, 
								   0x1000, 0x3719,  0x214,    0x3,    0x0,  0x295,  0x1d1,  0x14d,   0xa8, 0x4b40, 0x25e0,   0xe0, 0x6b40, 0x4600, 0x4480,    0x0, };

//#define kXrayBlockDrawingInstrs ((uint16*)RomFixedPtr(0x84839d))

uint16 kXrayBlockDrawingInstrs[] = { 0xa30f, 0xa31b, 0xa327, 0xa333, 0xa2df, 0xa2f1, 0xa2fd, 0xa303, };

//#define kGrayDoorPreInstrs ((uint16*)RomFixedPtr(0x84be4b))

//uint16 kGrayDoorPreInstrs[] = { 0xbdd4, 0xbde3, 0xbdf2, 0xbe01, 0xbe1c, 0xbe1f, 0xbe30, };

//#define kDownwardGatePlmListPtrs ((uint16*)RomFixedPtr(0x84c70a))
//#define kDownwardGateLeftBlockBts ((uint16*)RomFixedPtr(0x84c71a))
//#define kDownwardGateRightBlockBts ((uint16*)RomFixedPtr(0x84c72a))

//uint16 kDownwardGatePlmListPtrs[] = { 0xbcaf, 0xbcb5, 0xbcbb, 0xbcc1, 0xbcc7, 0xbccd, 0xbcd3, 0xbcd9, };
//
//uint16 kDownwardGateLeftBlockBts[] = { 0xc046, 0x0, 0xc048, 0x0, 0xc04a, 0x0, 0xc04c, 0x0, };
//
//uint16 kDownwardGateRightBlockBts[] = { 0x0, 0xc047, 0x0, 0xc049, 0x0, 0xc04b, 0x0, 0xc04d, };

//#define kUpwardGatePlmListPtrs ((uint16*)RomFixedPtr(0x84c764))
//#define kUpwardGateLeftBlockBts ((uint16*)RomFixedPtr(0x84c774))
//#define kUpwardGateRightBlockBts ((uint16*)RomFixedPtr(0x84c784))

//uint16 kUpwardGatePlmListPtrs[] = { 0xbcdf, 0xbce5, 0xbceb, 0xbcf1, 0xbcf7, 0xbcfd, 0xbd03, 0xbd09, };
//
//uint16 kUpwardGateLeftBlockBts[] = { 0xc046, 0x0, 0xc048, 0x0, 0xc04a, 0x0, 0xc04c, 0x0, };
//
//uint16 kUpwardGateRightBlockBts[] = { 0x0, 0xc047, 0x0, 0xc049, 0x0, 0xc04b, 0x0, 0xc04d, };

//#define kSetMetroidsClearStatePreInstrs ((uint16*)RomFixedPtr(0x84db28))

//uint16 kSetMetroidsClearStatePreInstrs[] = { 0xdad5, 0xdad6, 0xdad7, 0xdad8, 0xdad9, 0xdada, 0xdadb, 0xdadc, 0xdadd, 0xdade, 0xdaee, 0xdafe, 0xdb0e, };

//#define kDrawItemFrame0DrawInstrs ((uint16*)RomFixedPtr(0x84e05f))

uint16 kDrawItemFrame0DrawInstrs[] = { 0xa30f, 0xa31b, 0xa327, 0xa333, };

//#define kDrawItemFrame1DrawInstrs ((uint16*)RomFixedPtr(0x84e077))

uint16 kDrawItemFrame1DrawInstrs[] = { 0xa315, 0xa321, 0xa32d, 0xa339, };

//#define kPlmVramAddresses ((uint16*)RomFixedPtr(0x8487cd))
//#define kPlmTileDataOffs ((uint16*)RomFixedPtr(0x8487d5))
//#define kPlmStartingTileNumber ((uint16*)RomFixedPtr(0x8487dd))

uint16 kPlmVramAddresses[] = { 0x3e00, 0x3e80, 0x3f00, 0x3f80, };

uint16 kPlmTileDataOffs[] = { 0x470, 0x480, 0x490, 0x4a0, };

uint16 kPlmStartingTileNumber[] = { 0x3e0, 0x3e8, 0x3f0, 0x3f8, };
