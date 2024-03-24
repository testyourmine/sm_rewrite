#pragma once

//#define kMessageBoxDefs ((MsgBoxConfig*)RomFixedPtr(0x85869b))

//MsgBoxConfig kMessageBoxDefs[] = {
//  0x8436, 0x8289, 0x877f, 
//  0x83c5, 0x825a, 0x87bf, 
//  0x83c5, 0x825a, 0x88bf, 
//  0x83c5, 0x825a, 0x89bf, 
//  0x83c5, 0x825a, 0x8abf, 
//  0x83cc, 0x825a, 0x8bbf, 
//  0x8436, 0x8289, 0x8cbf, 
//  0x8436, 0x8289, 0x8cff, 
//  0x8436, 0x8289, 0x8d3f, 
//  0x8436, 0x8289, 0x8d7f, 
//  0x8436, 0x8289, 0x8dbf, 
//  0x8436, 0x8289, 0x8dff, 
//  0x83cc, 0x825a, 0x8e3f, 
//  0x8436, 0x8289, 0x8f3f, 
//  0x8436, 0x8289, 0x8f7f, 
//  0x8436, 0x8289, 0x8fbf, 
//  0x8436, 0x8289, 0x8fff, 
//  0x8436, 0x8289, 0x903f, 
//  0x83c5, 0x825a, 0x907f, 
//  0x8436, 0x8289, 0x917f, 
//  0x8436, 0x8289, 0x923f, 
//  0x8436, 0x8289, 0x92ff, 
//  0x8441, 0x8289, 0x93bf, 
//  0x8436, 0x8289, 0x94bf, 
//  0x8436, 0x8289, 0x94ff, 
//  0x8436, 0x8289, 0x953f, 
//  0x8436, 0x8289, 0x957f, 
//  0x8441, 0x8289, 0x93bf, 
//  0x8436, 0x8289, 0x94bf, 
//};

#define PR(x) (0x2800 | x)  //Purple letters
#define GN(x) (0x3800 | x)  //Green letters
#define YL(x) (0x3C00 | x)  //Yellow letters

static const uint16 kLargeMsgBoxTopBottomBorderTilemap[32] = {
     0xe,    0xe,    0xe, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x280f, 0x280f, 0x280f, 0x280f, 0x280f, 0x280f, 0x280f,
  0x280f, 0x280f, 0x280f, 0x280f, 0x280f, 0x280f, 0x280f, 0x280f, 0x280f, 0x280f, 0x280f, 0x284e, 0x284e,    0xe,    0xe,    0xe,
};

static const uint16 kSmallMsgBoxTopBottomBorderTilemap[32] = {
     0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e,
  0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,
};

static const uint16 kMsgBoxSpecialButtonTilemapOffs[27] = {  
  0, 0x12a, 0x12a, 0x12c, 0x12c, 0x12c, 0, 0, 0, 0, 0, 0, 0x120, 
  0,     0,     0,     0,     0, 0x12a, 0, 0, 0, 0, 0, 0,     0, 0,
};

static const uint16 kTileNumbersForButtonLetters[8] = { 0x28e0, 0x3ce1, 0x2cf7, 0x38f8, 0x38d0, 0x38eb, 0x38f1, 0x284e };

static const uint16 kSaveConfirmationSelectionTilemap[96] = {
     0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 0x3c4e, 0x3c4e, 0x38cc, 0x38cd, 0x3cf8, 0x3ce4, 0x3cf2, 0x3c4e, 0x3c4e, 0x3c4e,
  0x3c4e, 0x3c4e, 0x3c4e, 0x2ced, 0x2cee, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,
     0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 0x3c4e, 0x3c4e, 0x38cc, 0x38cd, 0x3cf8, 0x3ce4, 0x3cf2, 0x3c4e, 0x3c4e, 0x3c4e,
  0x3c4e, 0x3c4e, 0x3c4e, 0x2ced, 0x2cee, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,
     0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x2cf8, 0x2ce4, 0x2cf2, 0x3c4e, 0x3c4e, 0x3c4e,
  0x3c4e, 0x38cc, 0x38cd, 0x3ced, 0x3cee, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,
};



uint16 kEnergyTankMsgBoxTilemap[] = {
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),    PR(kTxt_E),    PR(kTxt_N),    PR(kTxt_E),    PR(kTxt_R),    PR(kTxt_G),    PR(kTxt_Y),   PR(kTxt_Sp),    PR(kTxt_T),    PR(kTxt_A),    PR(kTxt_N),    PR(kTxt_K),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
 };

uint16 kMissileMsgBoxTilemap[] = {
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),    PR(kTxt_M),    PR(kTxt_I),    PR(kTxt_S),    PR(kTxt_S),    PR(kTxt_I),    PR(kTxt_L),    PR(kTxt_E),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),        0x304B,        0x3049,        0x704B,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),   PR(kTxt_Sp),        0x28B9,        0x28BA,        0x28BB,   PR(kTxt_Sp),        0x304C,        0x304A,        0x704C,   PR(kTxt_Sp),        0x28C8,   PR(kTxt_Sp),        0x28B0,        0x28B1,        0x28B2,        0x28C0,        0x28C1,        0x28D1,    PR(kTxt_A),        0x28D3,        0x28B5,        0x28B6,        0x28B7,        0x28CB,   PR(kTxt_Sp),   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
 };

uint16 kSuperMissileMsgBoxTilemap[] = {
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),    PR(kTxt_S),    PR(kTxt_U),    PR(kTxt_P),    PR(kTxt_E),    PR(kTxt_R),   PR(kTxt_Sp),    PR(kTxt_M),    PR(kTxt_I),    PR(kTxt_S),    PR(kTxt_S),    PR(kTxt_I),    PR(kTxt_L),    PR(kTxt_E),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),        0x3034,        0x7034,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),        0x28B9,        0x28BA,        0x28BB,   PR(kTxt_Sp),        0x3035,        0x7035,   PR(kTxt_Sp),        0x28C8,   PR(kTxt_Sp),        0x28B0,        0x28B1,        0x28B2,        0x28C0,        0x28C1,        0x28D1,    YL(kTxt_B),        0x28D3,        0x28B5,        0x28B6,        0x28B7,        0x28CB,   PR(kTxt_Sp),   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
 };

uint16 kPowerBombMsgBoxTilemap[] = {
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),    PR(kTxt_P),    PR(kTxt_O),    PR(kTxt_W),    PR(kTxt_E),    PR(kTxt_R),   PR(kTxt_Sp),    PR(kTxt_B),    PR(kTxt_O),    PR(kTxt_M),    PR(kTxt_B),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),        0x3036,        0x7036,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),        0x28B9,        0x28BA,        0x28BB,   PR(kTxt_Sp),        0x3037,        0x7037,   PR(kTxt_Sp),        0x28C8,   PR(kTxt_Sp),        0x28C5,        0x28C6,        0x28C7,   PR(kTxt_Sp),        0x28BE,        0x28BF,        0x28C0,        0x28C1,        0x28D1,    GN(kTxt_R),        0x28D3,        0x28B5,        0x28B6,        0x28B7,        0x28CB,   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
 };

uint16 kGrapplingBeamMsgBoxTilemap[] = {
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),    PR(kTxt_G),    PR(kTxt_R),    PR(kTxt_A),    PR(kTxt_P),    PR(kTxt_P),    PR(kTxt_L),    PR(kTxt_I),    PR(kTxt_N),    PR(kTxt_G),   PR(kTxt_Sp),    PR(kTxt_B),    PR(kTxt_E),    PR(kTxt_A),    PR(kTxt_M),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),        0x3038,        0x7038,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),        0x28B9,        0x28BA,        0x28BB,   PR(kTxt_Sp),        0x3039,        0x7039,   PR(kTxt_Sp),        0x28B0,        0x28B1,        0x28B2,   PR(kTxt_Sp),        0x28C8,   PR(kTxt_Sp),        0x28B3,        0x28B4,        0x28C0,        0x28C1,        0x28D1,    GN(kTxt_Y),        0x28D3,        0x28B5,        0x28B6,        0x28B7,        0x28CB,   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
 };

uint16 kXrayScopeMsgBoxTilemap[] = {
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),    PR(kTxt_X), PR(kTxt_Dash),    PR(kTxt_R),    PR(kTxt_A),    PR(kTxt_Y),   PR(kTxt_Sp),    PR(kTxt_S),    PR(kTxt_C),    PR(kTxt_O),    PR(kTxt_P),    PR(kTxt_E),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),        0x303A,        0x703A,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),        0x28B9,        0x28BA,        0x28BB,   PR(kTxt_Sp),        0x303B,        0x703B,   PR(kTxt_Sp),        0x28B0,        0x28B1,        0x28B2,   PR(kTxt_Sp),        0x28C8,   PR(kTxt_Sp),        0x28B3,        0x28B4,        0x28C0,        0x28C1,        0x28D1,        0x2CF7,        0x28D3,        0x28B5,        0x28B6,        0x28B7,        0x28CB,   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
 };

uint16 kVariaSuitMsgBoxTilemap[] = {
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),    PR(kTxt_V),    PR(kTxt_A),    PR(kTxt_R),    PR(kTxt_I),    PR(kTxt_A),   PR(kTxt_Sp),    PR(kTxt_S),    PR(kTxt_U),    PR(kTxt_I),    PR(kTxt_T),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
 };

uint16 kSpringBallMsgBoxTilemap[] = {
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),    PR(kTxt_S),    PR(kTxt_P),    PR(kTxt_R),    PR(kTxt_I),    PR(kTxt_N),    PR(kTxt_G),   PR(kTxt_Sp),    PR(kTxt_B),    PR(kTxt_A),    PR(kTxt_L),    PR(kTxt_L),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
 };

uint16 kMorphingBallMsgBoxTilemap[] = {
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),    PR(kTxt_M),    PR(kTxt_O),    PR(kTxt_R),    PR(kTxt_P),    PR(kTxt_H),    PR(kTxt_I),    PR(kTxt_N),    PR(kTxt_G),   PR(kTxt_Sp),    PR(kTxt_B),    PR(kTxt_A),    PR(kTxt_L),    PR(kTxt_L),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
 };

uint16 kScrewAttackMsgBoxTilemap[] = {
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),    PR(kTxt_S),    PR(kTxt_C),    PR(kTxt_R),    PR(kTxt_E),    PR(kTxt_W),   PR(kTxt_Sp),    PR(kTxt_A),    PR(kTxt_T),    PR(kTxt_T),    PR(kTxt_A),    PR(kTxt_C),    PR(kTxt_K),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
 };

uint16 kHiJumpBootsMsgBoxTilemap[] = {
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),    PR(kTxt_H),    PR(kTxt_I), PR(kTxt_Dash),    PR(kTxt_J),    PR(kTxt_U),    PR(kTxt_M),    PR(kTxt_P),   PR(kTxt_Sp),    PR(kTxt_B),    PR(kTxt_O),    PR(kTxt_O),    PR(kTxt_T),    PR(kTxt_S),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
 };

uint16 kSpaceJumpMsgBoxTilemap[] = {
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),    PR(kTxt_S),    PR(kTxt_P),    PR(kTxt_A),    PR(kTxt_C),    PR(kTxt_E),   PR(kTxt_Sp),    PR(kTxt_J),    PR(kTxt_U),    PR(kTxt_M),    PR(kTxt_P),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
 };

uint16 kSpeedBoosterMsgBoxTilemap[] = {
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),    PR(kTxt_S),    PR(kTxt_P),    PR(kTxt_E),    PR(kTxt_E),    PR(kTxt_D),   PR(kTxt_Sp),    PR(kTxt_B),    PR(kTxt_O),    PR(kTxt_O),    PR(kTxt_S),    PR(kTxt_T),    PR(kTxt_E),    PR(kTxt_R),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),   PR(kTxt_Sp),        0x28B0,        0x28B1,        0x28B2,   PR(kTxt_Sp),        0x28C8,   PR(kTxt_Sp),        0x28B3,        0x28B4,        0x28C0,        0x28C1,        0x28D1,        0x38D0,        0x28D3,        0x28B5,        0x28B6,        0x28B7,   PR(kTxt_Sp),        0x28C2,   PR(kTxt_Sp),        0x28BC,        0x28BD,        0x28CB,   PR(kTxt_Sp),   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
 };

uint16 kChargeBeamMsgBoxTilemap[] = {
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),    PR(kTxt_C),    PR(kTxt_H),    PR(kTxt_A),    PR(kTxt_R),    PR(kTxt_G),    PR(kTxt_E),   PR(kTxt_Sp),    PR(kTxt_B),    PR(kTxt_E),    PR(kTxt_A),    PR(kTxt_M),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
 };

uint16 kIceBeamMsgBoxTilemap[] = {
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),    PR(kTxt_I),    PR(kTxt_C),    PR(kTxt_E),   PR(kTxt_Sp),    PR(kTxt_B),    PR(kTxt_E),    PR(kTxt_A),    PR(kTxt_M),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
 };

uint16 kWaveBeamMsgBoxTilemap[] = {
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),    PR(kTxt_W),    PR(kTxt_A),    PR(kTxt_V),    PR(kTxt_E),   PR(kTxt_Sp),    PR(kTxt_B),    PR(kTxt_E),    PR(kTxt_A),    PR(kTxt_M),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
 };

uint16 kSpazerMsgBoxTilemap[] = {
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),    PR(kTxt_S),    PR(kTxt_P),    PR(kTxt_A),    PR(kTxt_Z),    PR(kTxt_E),    PR(kTxt_R),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
 };

uint16 kPlasmaBeamMsgBoxTilemap[] = {
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),    PR(kTxt_P),    PR(kTxt_L),    PR(kTxt_A),    PR(kTxt_S),    PR(kTxt_M),    PR(kTxt_A),   PR(kTxt_Sp),    PR(kTxt_B),    PR(kTxt_E),    PR(kTxt_A),    PR(kTxt_M),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
 };

uint16 kBombMsgBoxTilemap[] = {
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),    PR(kTxt_B),    PR(kTxt_O),    PR(kTxt_M),    PR(kTxt_B),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),   PR(kTxt_Sp),        0x38DC,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),   PR(kTxt_Sp),        0x3CDD,        0x3CDF,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),   PR(kTxt_Sp),        0x3CDE,        0x3CCC,        0x38CD,        0x3CC9,   PR(kTxt_Sp),        0x28C8,   PR(kTxt_Sp),        0x28C5,        0x28C6,        0x28C7,   PR(kTxt_Sp),        0x28BE,        0x28BF,        0x28C0,        0x28C1,        0x28D1,    GN(kTxt_L),        0x28D3,        0x28B5,        0x28B6,        0x28B7,        0x28CB,   PR(kTxt_Sp),   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
 };

uint16 kMapDataAccessCompletedMsgBoxTilemap[] = {
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   YL(kTxt_Sp),   YL(kTxt_Sp),    YL(kTxt_M),    YL(kTxt_A),    YL(kTxt_P),   YL(kTxt_Sp),    YL(kTxt_D),    YL(kTxt_A),    YL(kTxt_T),    YL(kTxt_A),   YL(kTxt_Sp),    YL(kTxt_A),    YL(kTxt_C),    YL(kTxt_C),    YL(kTxt_E),    YL(kTxt_S),    YL(kTxt_S),   YL(kTxt_Sp),   YL(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),    YL(kTxt_C),    YL(kTxt_O),    YL(kTxt_M),    YL(kTxt_P),    YL(kTxt_L),    YL(kTxt_E),    YL(kTxt_T),    YL(kTxt_E),    YL(kTxt_D),        0x3CFA,   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
 };

uint16 kEnergyRechargeCompletedMsgBoxTilemap[] = {
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   YL(kTxt_Sp),   YL(kTxt_Sp),    YL(kTxt_E),    YL(kTxt_N),    YL(kTxt_E),    YL(kTxt_R),    YL(kTxt_G),    YL(kTxt_Y),   YL(kTxt_Sp),    YL(kTxt_R),    YL(kTxt_E),    YL(kTxt_C),    YL(kTxt_H),    YL(kTxt_A),    YL(kTxt_R),    YL(kTxt_G),    YL(kTxt_E),   YL(kTxt_Sp),   YL(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),    YL(kTxt_C),    YL(kTxt_O),    YL(kTxt_M),    YL(kTxt_P),    YL(kTxt_L),    YL(kTxt_E),    YL(kTxt_T),    YL(kTxt_E),    YL(kTxt_D),        0x3CFA,   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
 };

uint16 kMissileReloadCompletedMsgBoxTilemap[] = {
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   YL(kTxt_Sp),   YL(kTxt_Sp),    YL(kTxt_M),    YL(kTxt_I),    YL(kTxt_S),    YL(kTxt_S),    YL(kTxt_I),    YL(kTxt_L),    YL(kTxt_E),   YL(kTxt_Sp),    YL(kTxt_R),    YL(kTxt_E),    YL(kTxt_L),    YL(kTxt_O),    YL(kTxt_A),    YL(kTxt_D),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   YL(kTxt_Sp),   YL(kTxt_Sp),   GN(kTxt_Sp),   GN(kTxt_Sp),   GN(kTxt_Sp),   GN(kTxt_Sp),   GN(kTxt_Sp),   GN(kTxt_Sp),   GN(kTxt_Sp),   GN(kTxt_Sp),   GN(kTxt_Sp),   GN(kTxt_Sp),   GN(kTxt_Sp),   GN(kTxt_Sp),   GN(kTxt_Sp),   GN(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   YL(kTxt_Sp),   YL(kTxt_Sp),   GN(kTxt_Sp),   GN(kTxt_Sp),    YL(kTxt_C),    YL(kTxt_O),    YL(kTxt_M),    YL(kTxt_P),    YL(kTxt_L),    YL(kTxt_E),    YL(kTxt_T),    YL(kTxt_E),    YL(kTxt_D),        0x3CFA,   GN(kTxt_Sp),   GN(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
 };

uint16 kWouldYouLikeToSaveMsgBoxTilemap[] = {
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   YL(kTxt_Sp),   YL(kTxt_Sp),    YL(kTxt_W),    YL(kTxt_O),    YL(kTxt_U),    YL(kTxt_L),    YL(kTxt_D),   YL(kTxt_Sp),    YL(kTxt_Y),    YL(kTxt_O),    YL(kTxt_U),   YL(kTxt_Sp),    YL(kTxt_L),    YL(kTxt_I),    YL(kTxt_K),    YL(kTxt_E),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   YL(kTxt_Sp),   YL(kTxt_Sp),    YL(kTxt_T),    YL(kTxt_O),   YL(kTxt_Sp),    YL(kTxt_S),    YL(kTxt_A),    YL(kTxt_V),    YL(kTxt_E),        0x3CFE,   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   YL(kTxt_Sp),   YL(kTxt_Sp),        0x38CC,        0x38CD,    YL(kTxt_Y),    YL(kTxt_E),    YL(kTxt_S),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),        0x2CED,        0x2CEE,   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
 };

uint16 kSaveCompletedMsgBoxTilemap[] = {
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   YL(kTxt_Sp),   YL(kTxt_Sp),    YL(kTxt_S),    YL(kTxt_A),    YL(kTxt_V),    YL(kTxt_E),   YL(kTxt_Sp),    YL(kTxt_C),    YL(kTxt_O),    YL(kTxt_M),    YL(kTxt_P),    YL(kTxt_L),    YL(kTxt_E),    YL(kTxt_T),    YL(kTxt_E),    YL(kTxt_D),        0x3CFA,   YL(kTxt_Sp),   YL(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
 };

uint16 kReserveTankMsgBoxTilemap[] = {
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),    PR(kTxt_R),    PR(kTxt_E),    PR(kTxt_S),    PR(kTxt_E),    PR(kTxt_R),    PR(kTxt_V),    PR(kTxt_E),   PR(kTxt_Sp),    PR(kTxt_T),    PR(kTxt_A),    PR(kTxt_N),    PR(kTxt_K),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
 };

uint16 kGravitySuitMsgBoxTilemap[] = {
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),    PR(kTxt_G),    PR(kTxt_R),    PR(kTxt_A),    PR(kTxt_V),    PR(kTxt_I),    PR(kTxt_T),    PR(kTxt_Y),   PR(kTxt_Sp),    PR(kTxt_S),    PR(kTxt_U),    PR(kTxt_I),    PR(kTxt_T),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),   PR(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
 };

uint16 kTerminator1MsgBoxTilemap[] = {
         0x0000,
};

uint16 kWouldYouLikeToSaveGunshipMsgBoxTilemap[] = {
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   YL(kTxt_Sp),   YL(kTxt_Sp),    YL(kTxt_W),    YL(kTxt_O),    YL(kTxt_U),    YL(kTxt_L),    YL(kTxt_D),   YL(kTxt_Sp),    YL(kTxt_Y),    YL(kTxt_O),    YL(kTxt_U),   YL(kTxt_Sp),    YL(kTxt_L),    YL(kTxt_I),    YL(kTxt_K),    YL(kTxt_E),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   YL(kTxt_Sp),   YL(kTxt_Sp),    YL(kTxt_T),    YL(kTxt_O),   YL(kTxt_Sp),    YL(kTxt_S),    YL(kTxt_A),    YL(kTxt_V),    YL(kTxt_E),        0x3CFE,   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
       kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,   YL(kTxt_Sp),   YL(kTxt_Sp),        0x38CC,        0x38CD,    YL(kTxt_Y),    YL(kTxt_E),    YL(kTxt_S),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),        0x2CED,        0x2CEE,   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),   YL(kTxt_Sp),      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,      kTxt_Nul,
 };

uint16 kTerminatorSaveCompletedUnusedMsgBoxTilemap[] = {
       kTxt_Nul,
};


uint16* getMessageTilemap(uint16 tilemap) {
  switch(tilemap) {
    case addr_kEnergyTankMsgBoxTilemap: return kEnergyTankMsgBoxTilemap;
    case addr_kMissileMsgBoxTilemap: return kMissileMsgBoxTilemap;
    case addr_kSuperMissileMsgBoxTilemap: return kSuperMissileMsgBoxTilemap;
    case addr_kPowerBombMsgBoxTilemap: return kPowerBombMsgBoxTilemap;
    case addr_kGrapplingBeamMsgBoxTilemap: return kGrapplingBeamMsgBoxTilemap;
    case addr_kXrayScopeMsgBoxTilemap: return kXrayScopeMsgBoxTilemap;
    case addr_kVariaSuitMsgBoxTilemap: return kVariaSuitMsgBoxTilemap;
    case addr_kSpringBallMsgBoxTilemap: return kSpringBallMsgBoxTilemap;
    case addr_kMorphingBallMsgBoxTilemap: return kMorphingBallMsgBoxTilemap;
    case addr_kScrewAttackMsgBoxTilemap: return kScrewAttackMsgBoxTilemap;
    case addr_kHiJumpBootsMsgBoxTilemap: return kHiJumpBootsMsgBoxTilemap;
    case addr_kSpaceJumpMsgBoxTilemap: return kSpaceJumpMsgBoxTilemap;
    case addr_kSpeedBoosterMsgBoxTilemap: return kSpeedBoosterMsgBoxTilemap;
    case addr_kChargeBeamMsgBoxTilemap: return kChargeBeamMsgBoxTilemap;
    case addr_kIceBeamMsgBoxTilemap: return kIceBeamMsgBoxTilemap;
    case addr_kWaveBeamMsgBoxTilemap: return kWaveBeamMsgBoxTilemap;
    case addr_kSpazerMsgBoxTilemap: return kSpazerMsgBoxTilemap;
    case addr_kPlasmaBeamMsgBoxTilemap: return kPlasmaBeamMsgBoxTilemap;
    case addr_kBombMsgBoxTilemap: return kBombMsgBoxTilemap;
    case addr_kMapDataAccessCompletedMsgBoxTilemap: return kMapDataAccessCompletedMsgBoxTilemap;
    case addr_kEnergyRechargeCompletedMsgBoxTilemap: return kEnergyRechargeCompletedMsgBoxTilemap;
    case addr_kMissileReloadCompletedMsgBoxTilemap: return kMissileReloadCompletedMsgBoxTilemap;
    case addr_kWouldYouLikeToSaveMsgBoxTilemap: return kWouldYouLikeToSaveMsgBoxTilemap;
    case addr_kSaveCompletedMsgBoxTilemap: return kSaveCompletedMsgBoxTilemap;
    case addr_kReserveTankMsgBoxTilemap: return kReserveTankMsgBoxTilemap;
    case addr_kGravitySuitMsgBoxTilemap: return kGravitySuitMsgBoxTilemap;
    case addr_kTerminator1MsgBoxTilemap: return kTerminator1MsgBoxTilemap;
    default: Unreachable(); return (uint16*){0};
  }
}
MsgBoxConfig kMessageBoxDefs[] = {
  [kMessageBox_1_EnergyTank-1]                  = { .modify_box_func = FUNC16(SetupPpuForSmallMessageBox),                   .draw_initial_tilemap = FUNC16(WriteSmallMessageBoxTilemap), .message_tilemap = addr_kEnergyTankMsgBoxTilemap              },
  [kMessageBox_2_Missile-1]                     = { .modify_box_func = FUNC16(DrawShootButtonAndSetupPpuForLargeMessageBox), .draw_initial_tilemap = FUNC16(WriteLargeMessageBoxTilemap), .message_tilemap = addr_kMissileMsgBoxTilemap                 },
  [kMessageBox_3_SuperMissile-1]                = { .modify_box_func = FUNC16(DrawShootButtonAndSetupPpuForLargeMessageBox), .draw_initial_tilemap = FUNC16(WriteLargeMessageBoxTilemap), .message_tilemap = addr_kSuperMissileMsgBoxTilemap            },
  [kMessageBox_4_PowerBomb-1]                   = { .modify_box_func = FUNC16(DrawShootButtonAndSetupPpuForLargeMessageBox), .draw_initial_tilemap = FUNC16(WriteLargeMessageBoxTilemap), .message_tilemap = addr_kPowerBombMsgBoxTilemap               },
  [kMessageBox_5_GrapplingBeam-1]               = { .modify_box_func = FUNC16(DrawShootButtonAndSetupPpuForLargeMessageBox), .draw_initial_tilemap = FUNC16(WriteLargeMessageBoxTilemap), .message_tilemap = addr_kGrapplingBeamMsgBoxTilemap           },
  [kMessageBox_6_XrayScope-1]                   = { .modify_box_func = FUNC16(DrawRunButtonAndSetupPpuForLargeMessageBox),   .draw_initial_tilemap = FUNC16(WriteLargeMessageBoxTilemap), .message_tilemap = addr_kXrayScopeMsgBoxTilemap               },
  [kMessageBox_7_VariaSuit-1]                   = { .modify_box_func = FUNC16(SetupPpuForSmallMessageBox),                   .draw_initial_tilemap = FUNC16(WriteSmallMessageBoxTilemap), .message_tilemap = addr_kVariaSuitMsgBoxTilemap               },
  [kMessageBox_8_SpringBall-1]                  = { .modify_box_func = FUNC16(SetupPpuForSmallMessageBox),                   .draw_initial_tilemap = FUNC16(WriteSmallMessageBoxTilemap), .message_tilemap = addr_kSpringBallMsgBoxTilemap              },
  [kMessageBox_9_MorphingBall-1]                = { .modify_box_func = FUNC16(SetupPpuForSmallMessageBox),                   .draw_initial_tilemap = FUNC16(WriteSmallMessageBoxTilemap), .message_tilemap = addr_kMorphingBallMsgBoxTilemap            },
  [kMessageBox_10_ScrewAttack-1]                = { .modify_box_func = FUNC16(SetupPpuForSmallMessageBox),                   .draw_initial_tilemap = FUNC16(WriteSmallMessageBoxTilemap), .message_tilemap = addr_kScrewAttackMsgBoxTilemap             },
  [kMessageBox_11_HiJumpBoots-1]                = { .modify_box_func = FUNC16(SetupPpuForSmallMessageBox),                   .draw_initial_tilemap = FUNC16(WriteSmallMessageBoxTilemap), .message_tilemap = addr_kHiJumpBootsMsgBoxTilemap             },
  [kMessageBox_12_SpaceJump-1]                  = { .modify_box_func = FUNC16(SetupPpuForSmallMessageBox),                   .draw_initial_tilemap = FUNC16(WriteSmallMessageBoxTilemap), .message_tilemap = addr_kSpaceJumpMsgBoxTilemap               },
  [kMessageBox_13_SpeedBooster-1]               = { .modify_box_func = FUNC16(DrawRunButtonAndSetupPpuForLargeMessageBox),   .draw_initial_tilemap = FUNC16(WriteLargeMessageBoxTilemap), .message_tilemap = addr_kSpeedBoosterMsgBoxTilemap            },
  [kMessageBox_14_ChargeBeam-1]                 = { .modify_box_func = FUNC16(SetupPpuForSmallMessageBox),                   .draw_initial_tilemap = FUNC16(WriteSmallMessageBoxTilemap), .message_tilemap = addr_kChargeBeamMsgBoxTilemap              },
  [kMessageBox_15_IceBeam-1]                    = { .modify_box_func = FUNC16(SetupPpuForSmallMessageBox),                   .draw_initial_tilemap = FUNC16(WriteSmallMessageBoxTilemap), .message_tilemap = addr_kIceBeamMsgBoxTilemap                 },
  [kMessageBox_16_WaveBeam-1]                   = { .modify_box_func = FUNC16(SetupPpuForSmallMessageBox),                   .draw_initial_tilemap = FUNC16(WriteSmallMessageBoxTilemap), .message_tilemap = addr_kWaveBeamMsgBoxTilemap                },
  [kMessageBox_17_Spazer-1]                     = { .modify_box_func = FUNC16(SetupPpuForSmallMessageBox),                   .draw_initial_tilemap = FUNC16(WriteSmallMessageBoxTilemap), .message_tilemap = addr_kSpazerMsgBoxTilemap                  },
  [kMessageBox_18_PlasmaBeam-1]                 = { .modify_box_func = FUNC16(SetupPpuForSmallMessageBox),                   .draw_initial_tilemap = FUNC16(WriteSmallMessageBoxTilemap), .message_tilemap = addr_kPlasmaBeamMsgBoxTilemap              },
  [kMessageBox_19_Bomb-1]                       = { .modify_box_func = FUNC16(DrawShootButtonAndSetupPpuForLargeMessageBox), .draw_initial_tilemap = FUNC16(WriteLargeMessageBoxTilemap), .message_tilemap = addr_kBombMsgBoxTilemap                    },
  [kMessageBox_20_MapDataAccessCompleted-1]     = { .modify_box_func = FUNC16(SetupPpuForSmallMessageBox),                   .draw_initial_tilemap = FUNC16(WriteSmallMessageBoxTilemap), .message_tilemap = addr_kMapDataAccessCompletedMsgBoxTilemap  },
  [kMessageBox_21_EnergyRechargeCompleted-1]    = { .modify_box_func = FUNC16(SetupPpuForSmallMessageBox),                   .draw_initial_tilemap = FUNC16(WriteSmallMessageBoxTilemap), .message_tilemap = addr_kEnergyRechargeCompletedMsgBoxTilemap },
  [kMessageBox_22_MissileReloadCompleted-1]     = { .modify_box_func = FUNC16(SetupPpuForSmallMessageBox),                   .draw_initial_tilemap = FUNC16(WriteSmallMessageBoxTilemap), .message_tilemap = addr_kMissileReloadCompletedMsgBoxTilemap  },
  [kMessageBox_23_WouldYouLikeToSave-1]         = { .modify_box_func = FUNC16(SetupPpuForLargeMessageBox),                   .draw_initial_tilemap = FUNC16(WriteSmallMessageBoxTilemap), .message_tilemap = addr_kWouldYouLikeToSaveMsgBoxTilemap      },
  [kMessageBox_24_SaveCompleted-1]              = { .modify_box_func = FUNC16(SetupPpuForSmallMessageBox),                   .draw_initial_tilemap = FUNC16(WriteSmallMessageBoxTilemap), .message_tilemap = addr_kSaveCompletedMsgBoxTilemap           },
  [kMessageBox_25_ReserveTank-1]                = { .modify_box_func = FUNC16(SetupPpuForSmallMessageBox),                   .draw_initial_tilemap = FUNC16(WriteSmallMessageBoxTilemap), .message_tilemap = addr_kReserveTankMsgBoxTilemap             },
  [kMessageBox_26_GravitySuit-1]                = { .modify_box_func = FUNC16(SetupPpuForSmallMessageBox),                   .draw_initial_tilemap = FUNC16(WriteSmallMessageBoxTilemap), .message_tilemap = addr_kGravitySuitMsgBoxTilemap             },
  [kMessageBox_27_Terminator1-1]                = { .modify_box_func = FUNC16(SetupPpuForSmallMessageBox),                   .draw_initial_tilemap = FUNC16(WriteSmallMessageBoxTilemap), .message_tilemap = addr_kTerminator1MsgBoxTilemap             },
  [kMessageBox_28_WouldYouLikeToSave_Gunship-1] = { .modify_box_func = FUNC16(SetupPpuForLargeMessageBox),                   .draw_initial_tilemap = FUNC16(WriteSmallMessageBoxTilemap), .message_tilemap = addr_kWouldYouLikeToSaveMsgBoxTilemap      },
  [kMessageBox_29_Terminator2-1]                = { .modify_box_func = FUNC16(SetupPpuForSmallMessageBox),                   .draw_initial_tilemap = FUNC16(WriteSmallMessageBoxTilemap), .message_tilemap = addr_kSaveCompletedMsgBoxTilemap           },
};

