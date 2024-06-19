#pragma once

#include "types.h"

//#define kEnemyInit_MorphBallEye_InstrListPtrs ((uint16*)RomFixedPtr(0xa890da))
//#define kYappingMaw_Constant0 (*(uint16*)RomFixedPtr(0xa8a0a7))
//#define kYappingMaw_Constant1 (*(uint16*)RomFixedPtr(0xa8a0a9))
//#define kYappingMaw_Constant2 (*(uint16*)RomFixedPtr(0xa8a0ab))
//#define kYappingMaw_Constant3 (*(uint16*)RomFixedPtr(0xa8a0ad))
//#define kYappingMaw_Constant4 (*(uint16*)RomFixedPtr(0xa8a0b3))
//#define kYappingMaw_Constant5 (*(uint16*)RomFixedPtr(0xa8a0b5))
//#define kYappingMaw_Constant6 (*(uint16*)RomFixedPtr(0xa8a0b7))
//#define kYappingMaw_Constant7 (*(uint16*)RomFixedPtr(0xa8a0b9))
//#define kYappingMaw_Constant8 (*(uint16*)RomFixedPtr(0xa8a0bb))
//#define kYappingMaw_Constant9 (*(uint16*)RomFixedPtr(0xa8a0bd))
//#define kYappingMaw_Constant10 (*(uint16*)RomFixedPtr(0xa8a0c3))
//#define kYappingMaw_Constant11 (*(uint16*)RomFixedPtr(0xa8a0c5))
//#define kYappingMaw_InstrListPtrs ((uint16*)RomFixedPtr(0xa8a097))
//#define kNorfairLavaMan_Palette ((uint16*)RomFixedPtr(0xa8ac1c))
//#define kNorfairLavaMan_Tab2 ((uint16*)RomFixedPtr(0xa8af79))
//#define kNorfairLavaMan_Tab0 ((uint16*)RomFixedPtr(0xa8af55))
//#define kNorfairLavaMan_Tab1 ((uint16*)RomFixedPtr(0xa8af67))
//#define kBeetom_SamusNotInProximityFuncPtrs ((uint16*)RomFixedPtr(0xa8b74e))
//#define kMaridiaFloater_InstrListPtrs ((uint16*)RomFixedPtr(0xa8c599))
//#define kEnemyInit_WreckedShipRobotDeactivated_InstrListPtrs ((uint16*)RomFixedPtr(0xa8cc30))
//#define kEnemyInit_WreckedShipOrbs_InstrListPtrs ((uint16*)RomFixedPtr(0xa8e380))
//#define kEnemyInit_WreckedShipSpark_InstrListPtrs ((uint16*)RomFixedPtr(0xa8e682))
//#define kEnemyInit_WreckedShipSpark_FuncPtrs ((uint16*)RomFixedPtr(0xa8e688))
//#define kBlueBrinstarFaceBlock_GlowPalette ((uint16*)RomFixedPtr(0xa8e7cc))
//#define kKiHunter_InstrListPtrs ((uint16*)RomFixedPtr(0xa8f3b0))

uint16 kEnemyInit_MorphBallEye_InstrListPtrs[] = {
  0x9044, 0x9038, 0x904a, 0x903e,
};

uint16 kYappingMaw_Constants[] = {
    0x0, 0xFFF0, 0x8, 0xFFF8, 0x10, 0x0, 0x8, 0x8, 0x0, 0x10, 0xFFF8, 0x8, 0xFFF0, 0x0, 0xFFF8, 0xFFF8,
};

uint16 kYappingMaw_Constant0 = {    0x0 };

uint16 kYappingMaw_Constant1 = { 0xfff0 };

uint16 kYappingMaw_Constant2 = {    0x8 };

uint16 kYappingMaw_Constant3 = { 0xfff8 };

uint16 kYappingMaw_Constant4 = {    0x8 };

uint16 kYappingMaw_Constant5 = {    0x8 };

uint16 kYappingMaw_Constant6 = {    0x0 };

uint16 kYappingMaw_Constant7 = {   0x10 };

uint16 kYappingMaw_Constant8 = { 0xfff8 };

uint16 kYappingMaw_Constant9 = {    0x8 };

uint16 kYappingMaw_Constant10 = { 0xfff8 };

uint16 kYappingMaw_Constant11 = { 0xfff8 };

uint16 kYappingMaw_InstrListPtrs[] = {
  0x9f6f, 0x9f85, 0x9f9b, 0x9fb1, 0x9fc7, 0x9fdd, 0x9ff3, 0xa009,
};

uint16 kNorfairLavaMan_Palette[] = {
  0x3800,   0x1f,   0x1c,   0x18,   0x15, 0x7fff, 0x3be0, 0x2680, 0x1580,  0x23f,   0xbd,   0x14,   0x10,    0x0,    0x0,    0x0, 
  0x3800,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,   0xbd,   0x14,   0x10,  0x23f,    0x0,    0x0,    0x0,
  0x3800,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,   0x14,   0x10,  0x23f,   0xbd,    0x0,    0x0,    0x0,
  0x3800,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,   0x10,  0x23f,   0xbd,   0x14,    0x0,    0x0,    0x0,
};

uint16 kNorfairLavaMan_Tab2[] = {
     12,    12,    20,    28,    36,    44,    52,    60,    68,
};

uint16 kNorfairLavaMan_Tab0[] = {
      0,    16,    32,    48,    64,    80,    96,   112,   128,
};

uint16 kNorfairLavaMan_Tab1[] = {
  0xaddc, 0xaddc, 0xade2, 0xade8, 0xadee, 0xadf4, 0xadfa, 0xae00, 0xae06,
};

uint16 kBeetom_SamusNotInProximityFuncPtrs[] = {
  0xb84f, 0xb84f, 
  0xb887, 0xb8ed, 
  0xb887, 0xb8a9, 
  0xb8cb, 0xb8ed,
};

uint16 kMaridiaFloater_InstrListPtrs[] = {
  0xc18b, 0xc187, 0xc183,
};

uint16 kEnemyInit_WreckedShipRobotDeactivated_InstrListPtrs[] = {
  0xc6d3, 0xc6d9, 0xc6df,
};

uint16 kEnemyInit_WreckedShipOrbs_InstrListPtrs[] = {
  0xe310, 0xe32c, 0xe348, 0xe364,
};

uint16 kEnemyInit_WreckedShipSpark_InstrListPtrs[] = {
  0xe5d1, 0xe5d1, 0xe609,
};

uint16 kEnemyInit_WreckedShipSpark_FuncPtrs[] = {
  0xe694, 0xe6b7, 0xe6dc,
};

uint16 kBlueBrinstarFaceBlock_GlowPalette[] = {
    0x1f,   0x12,    0xa,   0x2b, 
   0x51f,   0x96,   0x11,    0x7, 
   0xa3f,  0x13b,   0x18,    0xd, 
   0xf3f,  0x1bf,   0x1f,   0x12, 
   0xf3f,  0x1bf,   0x1f,   0x12, 
   0xa3f,  0x13b,   0x18,    0xd, 
   0x51f,   0x96,   0x11,    0x7, 
    0x1f,   0x12,    0xa,   0x2b,
};

uint16 kKiHunter_InstrListPtrs[] = {
  0xe9fa,0xea4e, 0xea24,0xea5e,
};


