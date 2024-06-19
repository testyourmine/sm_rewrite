#pragma once

#include "types.h"

//#define kMotherBrain_FakeDeathExplosionsXYPositions ((uint16*)RomFixedPtr(0xa98929))
//#define kMotherBrainTubesFallingFuncPtrs ((uint16*)RomFixedPtr(0xa98b7b))
//#define kMotherBrain_ExplosionsXYOffsets ((uint16*)RomFixedPtr(0xa9b099))
////#define g_word_A9B109 ((uint16*)RomFixedPtr(0xa9b109))
////#define g_word_A9B10F ((uint16*)RomFixedPtr(0xa9b10f))
//#define kMotherBrain_AttackInstrListPtrs ((uint16*)RomFixedPtr(0xa9b6d4))
//#define kMotherBrain_RainbowBeamPalettes ((uint16*)RomFixedPtr(0xade434))
//#define kMotherBrain_WalkForwardsFuncPtrs ((uint16*)RomFixedPtr(0xa9c61e))
//#define kMotherBrain_WalkBackwardsFuncPtrs ((uint16*)RomFixedPtr(0xa9c664))
//#define kShitroid_FadingToBlack ((uint16*)RomFixedPtr(0xade8e2))
//#define kShitroid_DeathExplosionsXYOffsets ((uint16*)RomFixedPtr(0xa9cdfc))
//#define kShitroid_HealthBasedPalettes_Shell ((uint16*)RomFixedPtr(0xade7e2))
//#define kShitroid_HealthBasedPalettes_Innards ((uint16*)RomFixedPtr(0xade882))
//#define kMotherBrain_PaletteSetPtrs ((uint16*)RomFixedPtr(0xa9d260))
//#define kDeadTorizo_VramWriteTableIndices_1 ((uint16*)RomFixedPtr(0xa9d583))
//#define kDeadTorizo_VramWriteTableIndices_2 ((uint16*)RomFixedPtr(0xa9d549))
//#define kDeadTorizo_SandHeapDestinationOffsets ((uint16*)RomFixedPtr(0xa9d67c))
//#define kDeadTorizo_SandHeapSourceOffsets ((uint16*)RomFixedPtr(0xa9d69c))
#define kDeadTorizo_TileData ((uint16*)RomFixedPtr(0xb7a800))
//#define kDeadZoomer_InstrListPtrs ((uint16*)RomFixedPtr(0xa9d86a))
//#define kDeadZoomer_CorpseRottingDefinitionPtrs ((uint16*)RomFixedPtr(0xa9d870))
//#define kDeadRipper_InstrListPtrs ((uint16*)RomFixedPtr(0xa9d897))
//#define kDeadRipper_CorpseRottingDefinitionPtrs ((uint16*)RomFixedPtr(0xa9d89b))
//#define kDeadSkree_InstrListPtrs ((uint16*)RomFixedPtr(0xa9d8c0))
//#define kDeadSkree_CorpseRottingDefinitionPtrs ((uint16*)RomFixedPtr(0xa9d8c6))
//#define kDeadMonsters_Tab0 ((uint16*)RomFixedPtr(0xa9d951))
//#define kDeadMonsters_Tab1 ((uint16*)RomFixedPtr(0xa9d959))
#define TILEMAP_ADDR(x) &g_ram[0x2000 + x]
#define kDeadMonsters_TileData RomPtr_B7(addr_kDeadMonsters_TileData)

uint16 kMotherBrain_FakeDeathExplosionsXYPositions[] = {
    136,   116, 
    120,   132, 
    124,    90, 
    138,   146, 
    120,    52, 
    124,   170, 
    138,    72, 
    120,   206,
};

uint16 kMotherBrainTubesFallingFuncPtrs[] = {
  0x8b88, 0x8b88, 0x8b88, 0x8b88, 0x8bcb,
};

uint16 kMotherBrain_ExplosionsXYOffsets[] = {
    0x24,0xffdb, 0xffed,0xfff1, 0xfffc,   0xd,   0x1d,  0x19, 
    0x11,0xffc9,   0x1e,0xffea, 0xfffd,0xfffb,    0x0,  0x28, 
    0x34,0xffde, 0xfffd,0xfff1,    0xc,  0x13,   0x19,  0x2c, 
     0x4,0xffd5, 0xfff4,0xffea,    0xd,0xfffe, 0xfff8,  0x34, 
  0xfffe,0xffdf,    0xa,0xfff6, 0xfff2,  0x10,    0x6,  0x3b, 
    0x14,0xffd7,    0x4,0xffea, 0xffec,   0x3, 0xffe5,  0x39, 
     0xa,0xffe1, 0xffec,0xfff8,    0x0,  0x17,   0x1e,  0x3d,
};

uint16 kMotherBrain_AttackInstrListPtrs[] = {
  0x9c87, 0x9d3d, 0x9f34, 0x9ecc,
};

uint16 kMotherBrain_RainbowBeamPalettes[] = {
  0xe44a, 0xe486, 0xe4c2, 0xe4fe, 0xe53a, 0xe576, 0xe5b2, 0xe5ee, 0xe62a, 0xe666,    0x0,
};

uint16 kMotherBrain_WalkForwardsFuncPtrs[] = {
  0xc61e, 0x9730, 0x976a, 0x97a4, 0x97de, 0x9818,
};

uint16 kMotherBrain_WalkBackwardsFuncPtrs[] = {
  0xc664, 0x988c, 0x98c6, 0x9900, 0x9852, 0x993a,
};

uint16 kShitroid_FadingToBlack[] = {
  0xe8f0, 0xe90c, 0xe928, 0xe944, 0xe960, 0xe97c, 0xe998,
};

uint16 kShitroid_DeathExplosionsXYOffsets[] = {
  0xffe8, 0xffe8, 
  0xffec,   0x14, 
    0x10, 0xffe2, 
    0x1e, 0xfffd, 
     0xe, 0xfff3, 
  0xfffe,   0x12, 
  0xfffe, 0xffe0, 
  0xffe1,    0x8, 
  0xfffc, 0xfff6, 
    0x13,   0x13,
};

uint16 kShitroid_HealthBasedPalettes_Shell[] = {
  0xe7f2, 0xe804, 0xe816, 0xe828, 0xe83a, 0xe84c, 0xe85e, 0xe870,
};

uint16 kShitroid_HealthBasedPalettes_Innards[] = {
  0xe892, 0xe89c, 0xe8a6, 0xe8b0, 0xe8ba, 0xe8c4, 0xe8ce, 0xe8d8,
};

uint16 kMotherBrain_PaletteSetPtrs[] = {
  0xd264, 0xd2a4,
};

uint16 kDeadTorizo_VramWriteTableIndices_1[] = {
   0x100, 0x7e00, 0x27c0, 0x7680, 
   0x100, 0x7e00, 0x2900, 0x7780, 
   0x100, 0x7e00, 0x2a40, 0x7880, 
   0x120, 0x7e00, 0x2b60, 0x7970, 
   0x140, 0x7e00, 0x2c80, 0x7a60, 
   0x140, 0x7e00, 0x2dc0, 0x7b60, 
   0x100, 0x7e00, 0x9500, 0x7000, 
     0x0,
};

uint16 kDeadTorizo_VramWriteTableIndices_2[] = {
    0xc0, 0x7e00, 0x2060, 0x7090, 
    0xc0, 0x7e00, 0x21a0, 0x7190, 
   0x100, 0x7e00, 0x22c0, 0x7280, 
   0x100, 0x7e00, 0x2400, 0x7380, 
   0x100, 0x7e00, 0x2540, 0x7480, 
   0x100, 0x7e00, 0x2680, 0x7580, 
   0x120, 0x7e00, 0x9620, 0x7100, 
     0x0,
};

uint16 kDeadTorizo_SandHeapDestinationOffsets[] = {
     0x0,    0x2,    0x4,    0x6,    0x8,    0xa,    0xc,    0xe,  0x120,  0x122,  0x124,  0x126,  0x128,  0x12a,  0x12c,  0x12e,
};

uint16 kDeadTorizo_SandHeapSourceOffsets[] = {
     0x0,    0x2,    0x4,    0x6,    0x8,    0xa,    0xc,    0xe,  0x200,  0x202,  0x204,  0x206,  0x208,  0x20a,  0x20c,  0x20e,
};

uint16 kDeadZoomer_InstrListPtrs[] = {
  0xecf5, 0xecfb, 0xed01,
};

uint16 kDeadZoomer_CorpseRottingDefinitionPtrs[] = {
  0xdd88, 0xdd98, 0xdda8,
};

uint16 kDeadRipper_InstrListPtrs[] = {
  0xed07, 0xed0d,
};

uint16 kDeadRipper_CorpseRottingDefinitionPtrs[] = {
  0xddb8, 0xddc8,
};

uint16 kDeadSkree_InstrListPtrs[] = {
  0xed13, 0xed19, 0xed1f,
};

uint16 kDeadSkree_CorpseRottingDefinitionPtrs[] = {
  0xddd8, 0xdde8, 0xddf8,
};

uint16 kDeadMonsters_Tab0[] = {
  0xfe00, 0xfe00, 0xfe00, 0xfc00,
};

uint16 kDeadMonsters_Tab1[] = {
   0x1c0,  0x120,  0x120,  0x300,
};


