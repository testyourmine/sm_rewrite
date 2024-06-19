#pragma once

#include "types.h"

//#define kEnemyInit_BouncingGoofball_Tab0 ((uint16*)RomFixedPtr(0xa286df))
//#define kEnemyInit_BouncingGoofball_Tab1 ((uint16*)RomFixedPtr(0xa286ef))
//#define kBouncingGoofball_Tab0 ((uint8*)RomFixedPtr(0xa28701))
//#define kMaridiaBeybladeTurtle_Tab0 (*(uint16*)RomFixedPtr(0xa28d56))
////#define kMaridiaBeybladeTurtle_Tab1 (*(uint16*)RomFixedPtr(0xa28d58))
//#define kThinHoppingBlobs_HopTable (*(uint16*)RomFixedPtr(0xa29a07))
////#define kThinHoppingBlobs_HopTable (*(uint16*)RomFixedPtr(0xa29a09))
////#define kThinHoppingBlobs_HopTable (*(uint16*)RomFixedPtr(0xa29a0b))
////#define kThinHoppingBlobs_HopTable (*(uint16*)RomFixedPtr(0xa29a0d))
//#define kEnemyInit_SpikeShootingPlant_XRadiusTravel ((uint16*)RomFixedPtr(0xa29f36))
//#define kEnemyInit_SpikeShootingPlant_FuncPtrs ((uint16*)RomFixedPtr(0xa29f42))
//#define kEnemyInit_MaridiaSpikeyShell_XDistanceRanges ((uint16*)RomFixedPtr(0xa2a3dd))
//#define kEnemyInit_MaridiaSpikeyShell_UndergroundTimers ((uint16*)RomFixedPtr(0xa2a3ed))
//#define kGunshipTop_HoverValues ((uint8*)RomFixedPtr(0xa2a7cf))
//#define kGunshipTop_YVelocitiesBrakeData ((uint16*)RomFixedPtr(0xa2a622))
//#define kGunshipTop_DustCloudTilesSourceAddresses ((uint16*)RomFixedPtr(0xa2ac07))
//#define kGunshipTop_DustCloudTilesDestinationAddresses ((uint16*)RomFixedPtr(0xa2ac11))
//#define kLavaquakeRocks_Tab0 ((uint16*)RomFixedPtr(0xa2b520))
//#define kLavaquakeRocks_Tab1 ((uint16*)RomFixedPtr(0xa2b530))
//#define kLavaquakeRocks_Tab2 ((uint16*)RomFixedPtr(0xa2b550))
//#define kRinka_MotherBrainRoomSpawnTable ((uint16*)RomFixedPtr(0xa2b75b))
//#define kRio_Constant0 (*(uint16*)RomFixedPtr(0xa2bbbb))
//#define kRio_Constant1 (*(uint16*)RomFixedPtr(0xa2bbbf))
//#define kNorfairLavajumpingEnemy_Tab0 ((uint16*)RomFixedPtr(0xa2be86))
//#define kNorfairRio_Tab0 ((uint16*)RomFixedPtr(0xa2c1c1))
//#define kNorfairRio_Constant0 (*(uint16*)RomFixedPtr(0xa2c1c5))
//#define kLowerNorfairRio_Constant0 (*(uint16*)RomFixedPtr(0xa2c6ca))
//#define kLowerNorfairRio_Constant1 (*(uint16*)RomFixedPtr(0xa2c6ce))
//#define kMaridiaLargeSnail_InstrListPtrs ((uint16*)RomFixedPtr(0xa2cb77))
//#define kHirisingSlowFalling_Ptrs0 ((uint16*)RomFixedPtr(0xa2df5e))
//#define kHirisingSlowFalling_Ptrs1 ((uint16*)RomFixedPtr(0xa2df6a))
//#define kLavaSeahorse_InstrListPtrs ((uint16*)RomFixedPtr(0xa2e5ef))
//#define kEnemyInit_TimedShutter_YPositionIndices ((uint16*)RomFixedPtr(0xa2ea56))
//#define kEnemyInit_TimedShutter_FuncPtrs ((uint16*)RomFixedPtr(0xa2ea4e))
////#define g_off_A2EC3A ((uint16*)RomFixedPtr(0xa2ec3a))
////#define g_off_A2EDFB ((uint16*)RomFixedPtr(0xa2edfb))
////#define g_off_A2F107 ((uint16*)RomFixedPtr(0xa2f107))

uint16 kEnemyInit_BouncingGoofball_Tab0[] = {
      1,     2,     4,     8,    10,    13,    16,    20,
};

uint16 kEnemyInit_BouncingGoofball_Tab1[] = {
  0x3000, 0x4000, 0x5000, 0x6000, 0x7000, 0x8000, 0x9000, 0xa000, 0xb000,
};

uint8 kBouncingGoofball_Tab0[] = {
    0,   1,   3,   6,  10,  15,  21,  28,  36,  45,  55,  66,  78,  91, 105, 120, 136, 153, 171, 190, 210, 231, 253,
};

uint16 kMaridiaBeybladeTurtle_Tab0[] = {
  0xf000, 0xffff, 0x1000,    0x0,
};

uint16 kThinHoppingBlobs_HopTable[] = {
    0x10,  0x100,  0x200, 0x9d0b, 
    0x20,  0x100,  0x200, 0x9d2b, 
    0x20,  0x200,  0x300, 0x9d4b, 
    0x80,  0x140,  0x200, 0x9d6b, 
     0x0,    0x0,  0x100, 0x9d98, 
    0x10,  0x100,  0x1c0, 0x9dcd, 
    0x15,  0x100,  0x1c0, 0x9dcd,
};

uint16 kEnemyInit_SpikeShootingPlant_XRadiusTravel[] = {
     16,    64,    80,    96,   112,   128,
};

uint16 kEnemyInit_SpikeShootingPlant_FuncPtrs[] = {
  0x9fba, 0x9fec, 0xa01b,
};

uint16 kEnemyInit_MaridiaSpikeyShell_XDistanceRanges[] = {
     16,    32,    48,    64,    80,    96,   112,   128,
};

uint16 kEnemyInit_MaridiaSpikeyShell_UndergroundTimers[] = {
     32,    64,    96,   128,   160,   192,
};

uint8 kGunshipTop_HoverValues[] = {
  0x10,  0x1, 
  0x10, 0xff, 
  0x10, 0xff, 
  0x10,  0x1,
};

uint16 kGunshipTop_YVelocitiesBrakeData[] = {
     0x1,    0x1,    0x1,    0x1,    0x1,    0x1, 
     0x0,    0x0,    0x0,    0x0,    0x0, 0xffff, 
  0xffff, 0xffff, 0xffff, 0xffff, 0xffff,
};

uint16 kGunshipTop_DustCloudTilesSourceAddresses[] = {
  0xc800, 0xcc00, 0xd000, 0xd400, 0xd800,
};

uint16 kGunshipTop_DustCloudTilesDestinationAddresses[] = {
  0x7600, 0x7800, 0x7a00, 0x7c00, 0x7e00,
};

uint16 kLavaquakeRocks_Tab0[] = {
    0x10,   0x18,   0x20,   0x28,   0x30,   0x38,   0x40,   0x48,
};

uint16 kLavaquakeRocks_Tab1[] = {
    0x1c,   0x1d,   0x1e,   0x1f,   0x20,   0x21,   0x22,   0x23, 
    0x24,   0x25,   0x26,   0x27,   0x28,   0x29,   0x2a,   0x2b,
};

uint16 kLavaquakeRocks_Tab2[] = {
    0x60,   0x70,   0x80,   0x90,   0xa0,   0xb0,   0xc0,   0xd0, 
  0xffa0, 0xff90, 0xff80, 0xff70, 0xff60, 0xff50, 0xff40, 0xff30,
};

uint16 kRinka_MotherBrainRoomSpawnTable[] = {
   0x3e7,   0x26,    0x2, 
   0x3e7,   0xa6,    0x4, 
   0x337,   0x36,    0x6, 
   0x337,   0xa6,    0x8, 
   0x277,   0x1c,    0xa, 
   0x277,   0xb6,    0xc, 
   0x1b7,   0x36,    0xe, 
   0x1b7,   0xa6,   0x10, 
    0xf7,   0x1c,   0x12, 
    0xf7,   0xb6,   0x14, 
    0x80,   0xa8,   0x16,
};

uint16 kRio_Constant0 = {  0x580 };

uint16 kRio_Constant1 = {  0x180 };

uint16 kNorfairLavajumpingEnemy_Tab0[] = {
  0xf7ff, 0xf8fe, 0xf9bf, 0xfaff,
};

uint16 kNorfairRio_Tab0[] = {
   0x700,  0x5c0,
};

uint16 kNorfairRio_Constant0 = {  0x100 };

uint16 kLowerNorfairRio_Constant0 = {  0x700 };

uint16 kLowerNorfairRio_Constant1 = {  0x100 };

uint16 kMaridiaLargeSnail_InstrListPtrs[] = {
  0xcadb, 0xca4b, 0xcb1b, 0xca8b, 0xcae1, 0xca51, 0xcb43, 0xcab3,
};

uint16 kHirisingSlowFalling_Ptrs0[] = {
  0xd84c, 0xd976, 0xdaa0, 0xdbca, 0xdd44, 0xdf5e,
};

uint16 kHirisingSlowFalling_Ptrs1[] = {
  0xd974, 0xda9e, 0xdbc8, 0xdd42, 0xdf5c, 0xdf5e,
};

uint16 kLavaSeahorse_InstrListPtrs[] = {
  0xe59b, 0xe5ad, 0xe5a1, 0xe5b3, 0xe5bf, 0xe5d7,
};

uint16 kEnemyInit_TimedShutter_YPositionIndices[] = {
     0x0,0x1000,    0x0,0x2000,    0x0,0x3000,    0x0,0x4000,    0x0,0x5000,    0x0,0x6000,    0x0,0x7000,    0x0,0x8000, 
     0x0,0x9000,    0x0,0xa000,    0x0,0xb000,    0x0,0xc000,    0x0,0xd000,    0x0,0xe000,    0x0,0xf000,    0x1,   0x0, 
     0x1,0x1000,    0x1,0x2000,    0x1,0x3000,    0x1,0x4000,    0x1,0x5000,    0x1,0x6000,    0x1,0x7000,    0x1,0x8000,
};

uint16 kEnemyInit_TimedShutter_FuncPtrs[] = {
  0xeafd, 0xeae7, 0xeabd, 0xead1,
};


