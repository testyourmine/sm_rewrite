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
     0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 0x284e, 0x284e, 0x284e, 0x284e, PR(kTxt_E), 0x28ed, 0x28e4, 0x28f1, 0x28e6, 0x28f8, 0x284e, 0x28f3, 0x28e0, 0x28ed, 0x28ea, 0x284e, 0x284e, 0x284e, 0x284e,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,
};

uint16 kMissileMsgBoxTilemap[] = {
     0xe,    0xe,    0xe, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x28ec, 0x28e8, 0x28f2, 0x28f2, 0x28e8, 0x28eb, 0x28e4, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e,    0xe,    0xe,    0xe, 
     0xe,    0xe,    0xe, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e,    0xe,    0xe,    0xe, 
     0xe,    0xe,    0xe, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x304b, 0x3049, 0x704b, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e,    0xe,    0xe,    0xe, 
     0xe,    0xe,    0xe, 0x284e, 0x284e, 0x28b9, 0x28ba, 0x28bb, 0x284e, 0x304c, 0x304a, 0x704c, 0x284e, 0x28c8, 0x284e, 0x28b0, 0x28b1, 0x28b2, 0x28c0, 0x28c1, 0x28d1, 0x28e0, 0x28d3, 0x28b5, 0x28b6, 0x28b7, 0x28cb, 0x284e, 0x284e,    0xe,    0xe,    0xe,
};

uint16 kSuperMissileMsgBoxTilemap[] = {
     0xe,    0xe,    0xe, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x28f2, 0x28f4, 0x28ef, 0x28e4, 0x28f1, 0x284e, 0x28ec, 0x28e8, 0x28f2, 0x28f2, 0x28e8, 0x28eb, 0x28e4, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e,    0xe,    0xe,    0xe, 
     0xe,    0xe,    0xe, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e,    0xe,    0xe,    0xe, 
     0xe,    0xe,    0xe, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x3034, 0x7034, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e,    0xe,    0xe,    0xe, 
     0xe,    0xe,    0xe, 0x284e, 0x284e, 0x284e, 0x28b9, 0x28ba, 0x28bb, 0x284e, 0x3035, 0x7035, 0x284e, 0x28c8, 0x284e, 0x28b0, 0x28b1, 0x28b2, 0x28c0, 0x28c1, 0x28d1, 0x3ce1, 0x28d3, 0x28b5, 0x28b6, 0x28b7, 0x28cb, 0x284e, 0x284e,    0xe,    0xe,    0xe,
};

uint16 kPowerBombMsgBoxTilemap[] = {
     0xe,    0xe,    0xe, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x28ef, 0x28ee, 0x28f6, 0x28e4, 0x28f1, 0x284e, 0x28e1, 0x28ee, 0x28ec, 0x28e1, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e,    0xe,    0xe,    0xe, 
     0xe,    0xe,    0xe, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e,    0xe,    0xe,    0xe, 
     0xe,    0xe,    0xe, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x3036, 0x7036, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e,    0xe,    0xe,    0xe, 
     0xe,    0xe,    0xe, 0x284e, 0x28b9, 0x28ba, 0x28bb, 0x284e, 0x3037, 0x7037, 0x284e, 0x28c8, 0x284e, 0x28c5, 0x28c6, 0x28c7, 0x284e, 0x28be, 0x28bf, 0x28c0, 0x28c1, 0x28d1, 0x38f1, 0x28d3, 0x28b5, 0x28b6, 0x28b7, 0x28cb, 0x284e,    0xe,    0xe,    0xe,
};

uint16 kGrapplingBeamMsgBoxTilemap[] = {
     0xe,    0xe,    0xe, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x28e6, 0x28f1, 0x28e0, 0x28ef, 0x28ef, 0x28eb, 0x28e8, 0x28ed, 0x28e6, 0x284e, 0x28e1, 0x28e4, 0x28e0, 0x28ec, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e,    0xe,    0xe,    0xe, 
     0xe,    0xe,    0xe, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e,    0xe,    0xe,    0xe, 
     0xe,    0xe,    0xe, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x3038, 0x7038, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e,    0xe,    0xe,    0xe, 
     0xe,    0xe,    0xe, 0x284e, 0x28b9, 0x28ba, 0x28bb, 0x284e, 0x3039, 0x7039, 0x284e, 0x28b0, 0x28b1, 0x28b2, 0x284e, 0x28c8, 0x284e, 0x28b3, 0x28b4, 0x28c0, 0x28c1, 0x28d1, 0x38f8, 0x28d3, 0x28b5, 0x28b6, 0x28b7, 0x28cb, 0x284e,    0xe,    0xe,    0xe,
};

uint16 kXrayScopeMsgBoxTilemap[] = {
     0xe,    0xe,    0xe, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x28f7, 0x28cf, 0x28f1, 0x28e0, 0x28f8, 0x284e, 0x28f2, 0x28e2, 0x28ee, 0x28ef, 0x28e4, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e,    0xe,    0xe,    0xe, 
     0xe,    0xe,    0xe, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e,    0xe,    0xe,    0xe, 
     0xe,    0xe,    0xe, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x303a, 0x703a, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e,    0xe,    0xe,    0xe, 
     0xe,    0xe,    0xe, 0x284e, 0x28b9, 0x28ba, 0x28bb, 0x284e, 0x303b, 0x703b, 0x284e, 0x28b0, 0x28b1, 0x28b2, 0x284e, 0x28c8, 0x284e, 0x28b3, 0x28b4, 0x28c0, 0x28c1, 0x28d1, 0x2cf7, 0x28d3, 0x28b5, 0x28b6, 0x28b7, 0x28cb, 0x284e,    0xe,    0xe,    0xe,
};

uint16 kVariaSuitMsgBoxTilemap[] = {
     0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 0x284e, 0x284e, 0x284e, 0x284e, 0x28f5, 0x28e0, 0x28f1, 0x28e8, 0x28e0, 0x284e, 0x28f2, 0x28f4, 0x28e8, 0x28f3, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,
};

uint16 kSpringBallMsgBoxTilemap[] = {
     0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 0x284e, 0x284e, 0x284e, 0x284e, 0x28f2, 0x28ef, 0x28f1, 0x28e8, 0x28ed, 0x28e6, 0x284e, 0x28e1, 0x28e0, 0x28eb, 0x28eb, 0x284e, 0x284e, 0x284e, 0x284e,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,
};

uint16 kMorphingBallMsgBoxTilemap[] = {
     0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 0x284e, 0x284e, 0x284e, 0x28ec, 0x28ee, 0x28f1, 0x28ef, 0x28e7, 0x28e8, 0x28ed, 0x28e6, 0x284e, 0x28e1, 0x28e0, 0x28eb, 0x28eb, 0x284e, 0x284e, 0x284e,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,
};

uint16 kScrewAttackMsgBoxTilemap[] = {
     0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 0x284e, 0x284e, 0x284e, 0x28f2, 0x28e2, 0x28f1, 0x28e4, 0x28f6, 0x284e, 0x28e0, 0x28f3, 0x28f3, 0x28e0, 0x28e2, 0x28ea, 0x284e, 0x284e, 0x284e, 0x284e,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,
};

uint16 kHiJumpBootsMsgBoxTilemap[] = {
     0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 0x284e, 0x284e, 0x284e, 0x28e7, 0x28e8, 0x28cf, 0x28e9, 0x28f4, 0x28ec, 0x28ef, 0x284e, 0x28e1, 0x28ee, 0x28ee, 0x28f3, 0x28f2, 0x284e, 0x284e, 0x284e,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,
};

uint16 kSpaceJumpMsgBoxTilemap[] = {
     0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 0x284e, 0x284e, 0x284e, 0x284e, 0x28f2, 0x28ef, 0x28e0, 0x28e2, 0x28e4, 0x284e, 0x28e9, 0x28f4, 0x28ec, 0x28ef, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,
};

uint16 kSpeedBoosterMsgBoxTilemap[] = {
     0xe,    0xe,    0xe, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x28f2, 0x28ef, 0x28e4, 0x28e4, 0x28e3, 0x284e, 0x28e1, 0x28ee, 0x28ee, 0x28f2, 0x28f3, 0x28e4, 0x28f1, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e,    0xe,    0xe,    0xe, 
     0xe,    0xe,    0xe, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e,    0xe,    0xe,    0xe, 
     0xe,    0xe,    0xe, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e,    0xe,    0xe,    0xe, 
     0xe,    0xe,    0xe, 0x284e, 0x284e, 0x28b0, 0x28b1, 0x28b2, 0x284e, 0x28c8, 0x284e, 0x28b3, 0x28b4, 0x28c0, 0x28c1, 0x28d1, 0x38d0, 0x28d3, 0x28b5, 0x28b6, 0x28b7, 0x284e, 0x28c2, 0x284e, 0x28bc, 0x28bd, 0x28cb, 0x284e, 0x284e,    0xe,    0xe,    0xe,
};

uint16 kChargeBeamMsgBoxTilemap[] = {
     0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 0x284e, 0x284e, 0x284e, 0x284e, 0x28e2, 0x28e7, 0x28e0, 0x28f1, 0x28e6, 0x28e4, 0x284e, 0x28e1, 0x28e4, 0x28e0, 0x28ec, 0x284e, 0x284e, 0x284e, 0x284e,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,
};

uint16 kIceBeamMsgBoxTilemap[] = {
     0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x28e8, 0x28e2, 0x28e4, 0x284e, 0x28e1, 0x28e4, 0x28e0, 0x28ec, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,
};

uint16 kWaveBeamMsgBoxTilemap[] = {
     0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x28f6, 0x28e0, 0x28f5, 0x28e4, 0x284e, 0x28e1, 0x28e4, 0x28e0, 0x28ec, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,
};

uint16 kSpazerMsgBoxTilemap[] = {
     0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x28f2, 0x28ef, 0x28e0, 0x28f9, 0x28e4, 0x28f1, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,
};

uint16 kPlasmaBeamMsgBoxTilemap[] = {
     0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 0x284e, 0x284e, 0x284e, 0x284e, 0x28ef, 0x28eb, 0x28e0, 0x28f2, 0x28ec, 0x28e0, 0x284e, 0x28e1, 0x28e4, 0x28e0, 0x28ec, 0x284e, 0x284e, 0x284e, 0x284e,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,
};

uint16 kBombMsgBoxTilemap[] = {
     0xe,    0xe,    0xe, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x28e1, 0x28ee, 0x28ec, 0x28e1, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e,    0xe,    0xe,    0xe, 
     0xe,    0xe,    0xe, 0x284e, 0x284e, 0x38dc, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e,    0xe,    0xe,    0xe, 
     0xe,    0xe,    0xe, 0x284e, 0x284e, 0x3cdd, 0x3cdf, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e, 0x284e,    0xe,    0xe,    0xe, 
     0xe,    0xe,    0xe, 0x284e, 0x284e, 0x3cde, 0x3ccc, 0x38cd, 0x3cc9, 0x284e, 0x28c8, 0x284e, 0x28c5, 0x28c6, 0x28c7, 0x284e, 0x28be, 0x28bf, 0x28c0, 0x28c1, 0x28d1, 0x38eb, 0x28d3, 0x28b5, 0x28b6, 0x28b7, 0x28cb, 0x284e, 0x284e,    0xe,    0xe,    0xe,
};

uint16 kMapDataAccessCompletedMsgBoxTilemap[] = {
     0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 0x3c4e, 0x3c4e, 0x3cec, 0x3ce0, 0x3cef, 0x3c4e, 0x3ce3, 0x3ce0, 0x3cf3, 0x3ce0, 0x3c4e, 0x3ce0, 0x3ce2, 0x3ce2, 0x3ce4, 0x3cf2, 0x3cf2, 0x3c4e, 0x3c4e,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 
     0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 
     0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3ce2, 0x3cee, 0x3cec, 0x3cef, 0x3ceb, 0x3ce4, 0x3cf3, 0x3ce4, 0x3ce3, 0x3cfa, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,
};

uint16 kEnergyRechargeCompletedMsgBoxTilemap[] = {
     0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 0x3c4e, 0x3c4e, 0x3ce4, 0x3ced, 0x3ce4, 0x3cf1, 0x3ce6, 0x3cf8, 0x3c4e, 0x3cf1, 0x3ce4, 0x3ce2, 0x3ce7, 0x3ce0, 0x3cf1, 0x3ce6, 0x3ce4, 0x3c4e, 0x3c4e,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 
     0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 
     0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3ce2, 0x3cee, 0x3cec, 0x3cef, 0x3ceb, 0x3ce4, 0x3cf3, 0x3ce4, 0x3ce3, 0x3cfa, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,
};

uint16 kMissileReloadCompletedMsgBoxTilemap[] = {
     0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 0x3c4e, 0x3c4e, 0x3cec, 0x3ce8, 0x3cf2, 0x3cf2, 0x3ce8, 0x3ceb, 0x3ce4, 0x3c4e, 0x3cf1, 0x3ce4, 0x3ceb, 0x3cee, 0x3ce0, 0x3ce3, 0x3c4e, 0x3c4e, 0x3c4e,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 
     0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 0x3c4e, 0x3c4e, 0x384e, 0x384e, 0x384e, 0x384e, 0x384e, 0x384e, 0x384e, 0x384e, 0x384e, 0x384e, 0x384e, 0x384e, 0x384e, 0x384e, 0x3c4e, 0x3c4e, 0x3c4e,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 
     0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 0x3c4e, 0x3c4e, 0x384e, 0x384e, 0x3ce2, 0x3cee, 0x3cec, 0x3cef, 0x3ceb, 0x3ce4, 0x3cf3, 0x3ce4, 0x3ce3, 0x3cfa, 0x384e, 0x384e, 0x3c4e, 0x3c4e, 0x3c4e,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,
};

uint16 kWouldYouLikeToSaveMsgBoxTilemap[] = {
     0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 0x3c4e, 0x3c4e, 0x3cf6, 0x3cee, 0x3cf4, 0x3ceb, 0x3ce3, 0x3c4e, 0x3cf8, 0x3cee, 0x3cf4, 0x3c4e, 0x3ceb, 0x3ce8, 0x3cea, 0x3ce4, 0x3c4e, 0x3c4e, 0x3c4e,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 
     0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 0x3c4e, 0x3c4e, 0x3cf3, 0x3cee, 0x3c4e, 0x3cf2, 0x3ce0, 0x3cf5, 0x3ce4, 0x3cfe, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 
     0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 
     0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 0x3c4e, 0x3c4e, 0x38cc, 0x38cd, 0x3cf8, 0x3ce4, 0x3cf2, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x2ced, 0x2cee, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,
};

uint16 kSaveCompletedMsgBoxTilemap[] = {
     0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 0x3c4e, 0x3c4e, 0x3cf2, 0x3ce0, 0x3cf5, 0x3ce4, 0x3c4e, 0x3ce2, 0x3cee, 0x3cec, 0x3cef, 0x3ceb, 0x3ce4, 0x3cf3, 0x3ce4, 0x3ce3, 0x3cfa, 0x3c4e, 0x3c4e,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,
};

uint16 kReserveTankMsgBoxTilemap[] = {
     0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 0x284e, 0x284e, 0x284e, 0x28f1, 0x28e4, 0x28f2, 0x28e4, 0x28f1, 0x28f5, 0x28e4, 0x284e, 0x28f3, 0x28e0, 0x28ed, 0x28ea, 0x284e, 0x284e, 0x284e, 0x284e,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,
};

uint16 kGravitySuitMsgBoxTilemap[] = {
     0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 0x284e, 0x284e, 0x284e, 0x28e6, 0x28f1, 0x28e0, 0x28f5, 0x28e8, 0x28f3, 0x28f8, 0x284e, 0x28f2, 0x28f4, 0x28e8, 0x28f3, 0x284e, 0x284e, 0x284e, 0x284e,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,
};

uint16 kTerminator1MsgBoxTilemap[] = {
     0x0,
};

uint16 kWouldYouLikeToSaveGunshipMsgBoxTilemap[] = {
     0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 0x3c4e, 0x3c4e, 0x3cf6, 0x3cee, 0x3cf4, 0x3ceb, 0x3ce3, 0x3c4e, 0x3cf8, 0x3cee, 0x3cf4, 0x3c4e, 0x3ceb, 0x3ce8, 0x3cea, 0x3ce4, 0x3c4e, 0x3c4e, 0x3c4e,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 
     0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 0x3c4e, 0x3c4e, 0x3cf3, 0x3cee, 0x3c4e, 0x3cf2, 0x3ce0, 0x3cf5, 0x3ce4, 0x3cfe, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 
     0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 
     0xe,    0xe,    0xe,    0xe,    0xe,    0xe, 0x3c4e, 0x3c4e, 0x38cc, 0x38cd, 0x3cf8, 0x3ce4, 0x3cf2, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e, 0x2ced, 0x2cee, 0x3c4e, 0x3c4e, 0x3c4e, 0x3c4e,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,    0xe,
};

uint16 kTerminatorSaveCompletedUnusedMsgBoxTilemap[] = {
     0xe,
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

