#pragma once

#include "funcs.h"
#include "ida_types.h"
#include "types.h"

#define PR(x) (0x2800 | kTxt_##x)  //Purple letters
#define GN(x) (0x3800 | kTxt_##x)  //Green letters
#define YL(x) (0x3C00 | kTxt_##x)  //Yellow letters
#define NUL kTxt_Nul

static const uint16 kLargeMsgBoxTopBottomBorderTilemap[32] = {  // 0x858000
  NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   0x280F,   0x280F,   0x280F,   0x280F,   0x280F,   0x280F,   0x280F,   0x280F,   0x280F,   0x280F,   0x280F,   0x280F,   0x280F,   0x280F,   0x280F,   0x280F,   0x280F,   0x280F,   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,
};

static const uint16 kSmallMsgBoxTopBottomBorderTilemap[32] = {  // 0x858040
  NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      NUL,
};

static const uint16 kTileNumbersForButtonLetters[8] = {  // 0x858426
  0x28e0, 0x3ce1, 0x2cf7, 0x38f8, 0x38d0, 0x38eb, 0x38f1, 0x284e
};

MsgBoxConfig kMessageBoxDefs[29] = {  // 0x85869B
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

static const uint16 kMsgBoxSpecialButtonTilemapOffs[27] = {  // 0x858749
  [kMessageBox_1_EnergyTank-1]                  = 0,
  [kMessageBox_2_Missile-1]                     = 0x12a,
  [kMessageBox_3_SuperMissile-1]                = 0x12a,
  [kMessageBox_4_PowerBomb-1]                   = 0x12c,
  [kMessageBox_5_GrapplingBeam-1]               = 0x12c,
  [kMessageBox_6_XrayScope-1]                   = 0x12c, 
  [kMessageBox_7_VariaSuit-1]                   = 0,
  [kMessageBox_8_SpringBall-1]                  = 0,
  [kMessageBox_9_MorphingBall-1]                = 0,
  [kMessageBox_10_ScrewAttack-1]                = 0,
  [kMessageBox_11_HiJumpBoots-1]                = 0,
  [kMessageBox_12_SpaceJump-1]                  = 0,
  [kMessageBox_13_SpeedBooster-1]               = 0x120,
  [kMessageBox_14_ChargeBeam-1]                 = 0,
  [kMessageBox_15_IceBeam-1]                    = 0,
  [kMessageBox_16_WaveBeam-1]                   = 0,
  [kMessageBox_17_Spazer-1]                     = 0,
  [kMessageBox_18_PlasmaBeam-1]                 = 0,
  [kMessageBox_19_Bomb-1]                       = 0x12a,
  [kMessageBox_20_MapDataAccessCompleted-1]     = 0,
  [kMessageBox_21_EnergyRechargeCompleted-1]    = 0,
  [kMessageBox_22_MissileReloadCompleted-1]     = 0,
  [kMessageBox_23_WouldYouLikeToSave-1]         = 0,
  [kMessageBox_24_SaveCompleted-1]              = 0,
  [kMessageBox_25_ReserveTank-1]                = 0,
  [kMessageBox_26_GravitySuit-1]                = 0,
  [kMessageBox_27_Terminator1-1]                = 0,
};

static const uint16 kEnergyTankMsgBoxTilemap[32] = {  // 0x85877F
  NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(E),    PR(N),    PR(E),    PR(R),    PR(G),    PR(Y),    PR(Sp),   PR(T),    PR(A),    PR(N),    PR(K),    PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      NUL,
};

static const uint16 kMissileMsgBoxTilemap[128] = {  // 0x8587BF
  NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(M),    PR(I),    PR(S),    PR(S),    PR(I),    PR(L),    PR(E),    PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,
  NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,
  NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   0x304B,   0x3049,   0x704B,   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,
  NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   0x28B9,   0x28BA,   0x28BB,   PR(Sp),   0x304C,   0x304A,   0x704C,   PR(Sp),   0x28C8,   PR(Sp),   0x28B0,   0x28B1,   0x28B2,   0x28C0,   0x28C1,   0x28D1,   PR(A),    0x28D3,   0x28B5,   0x28B6,   0x28B7,   0x28CB,   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,
};

static const uint16 kSuperMissileMsgBoxTilemap[128] = {  // 0x8588BF
  NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(S),    PR(U),    PR(P),    PR(E),    PR(R),    PR(Sp),   PR(M),    PR(I),    PR(S),    PR(S),    PR(I),    PR(L),    PR(E),    PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,
  NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,
  NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   0x3034,   0x7034,   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,
  NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   PR(Sp),   0x28B9,   0x28BA,   0x28BB,   PR(Sp),   0x3035,   0x7035,   PR(Sp),   0x28C8,   PR(Sp),   0x28B0,   0x28B1,   0x28B2,   0x28C0,   0x28C1,   0x28D1,   YL(B),    0x28D3,   0x28B5,   0x28B6,   0x28B7,   0x28CB,   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,
};

static const uint16 kPowerBombMsgBoxTilemap[128] = {  // 0x8589BF
  NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(P),    PR(O),    PR(W),    PR(E),    PR(R),    PR(Sp),   PR(B),    PR(O),    PR(M),    PR(B),    PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,
  NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,
  NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   0x3036,   0x7036,   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,
  NUL,      NUL,      NUL,      PR(Sp),   0x28B9,   0x28BA,   0x28BB,   PR(Sp),   0x3037,   0x7037,   PR(Sp),   0x28C8,   PR(Sp),   0x28C5,   0x28C6,   0x28C7,   PR(Sp),   0x28BE,   0x28BF,   0x28C0,   0x28C1,   0x28D1,   GN(R),    0x28D3,   0x28B5,   0x28B6,   0x28B7,   0x28CB,   PR(Sp),   NUL,      NUL,      NUL,
};

static const uint16 kGrapplingBeamMsgBoxTilemap[128] = {  // 0x858ABF
  NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(G),    PR(R),    PR(A),    PR(P),    PR(P),    PR(L),    PR(I),    PR(N),    PR(G),    PR(Sp),   PR(B),    PR(E),    PR(A),    PR(M),    PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,
  NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,
  NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   0x3038,   0x7038,   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,
  NUL,      NUL,      NUL,      PR(Sp),   0x28B9,   0x28BA,   0x28BB,   PR(Sp),   0x3039,   0x7039,   PR(Sp),   0x28B0,   0x28B1,   0x28B2,   PR(Sp),   0x28C8,   PR(Sp),   0x28B3,   0x28B4,   0x28C0,   0x28C1,   0x28D1,   GN(Y),    0x28D3,   0x28B5,   0x28B6,   0x28B7,   0x28CB,   PR(Sp),   NUL,      NUL,      NUL,
};

static const uint16 kXrayScopeMsgBoxTilemap[128] = {  // 0x858BBF
  NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(X),    PR(Dash), PR(R),    PR(A),    PR(Y),    PR(Sp),   PR(S),    PR(C),    PR(O),    PR(P),    PR(E),    PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,
  NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,
  NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   0x303A,   0x703A,   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,
  NUL,      NUL,      NUL,      PR(Sp),   0x28B9,   0x28BA,   0x28BB,   PR(Sp),   0x303B,   0x703B,   PR(Sp),   0x28B0,   0x28B1,   0x28B2,   PR(Sp),   0x28C8,   PR(Sp),   0x28B3,   0x28B4,   0x28C0,   0x28C1,   0x28D1,   0x2CF7,   0x28D3,   0x28B5,   0x28B6,   0x28B7,   0x28CB,   PR(Sp),   NUL,      NUL,      NUL,
};

static const uint16 kVariaSuitMsgBoxTilemap[32] = {  // 0x858CBF
  NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(V),    PR(A),    PR(R),    PR(I),    PR(A),    PR(Sp),   PR(S),    PR(U),    PR(I),    PR(T),    PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      NUL,
};

static const uint16 kSpringBallMsgBoxTilemap[32] = {  // 0x858CFF
  NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(S),    PR(P),    PR(R),    PR(I),    PR(N),    PR(G),    PR(Sp),   PR(B),    PR(A),    PR(L),    PR(L),    PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      NUL,
};

static const uint16 kMorphingBallMsgBoxTilemap[32] = {  // 0x858D3F
  NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   PR(Sp),   PR(M),    PR(O),    PR(R),    PR(P),    PR(H),    PR(I),    PR(N),    PR(G),    PR(Sp),   PR(B),    PR(A),    PR(L),    PR(L),    PR(Sp),   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      NUL,
};

static const uint16 kScrewAttackMsgBoxTilemap[32] = {  // 0x858D7F
  NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   PR(Sp),   PR(S),    PR(C),    PR(R),    PR(E),    PR(W),    PR(Sp),   PR(A),    PR(T),    PR(T),    PR(A),    PR(C),    PR(K),    PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      NUL,
};

static const uint16 kHiJumpBootsMsgBoxTilemap[32] = {  // 0x858DBF
  NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   PR(Sp),   PR(H),    PR(I),    PR(Dash), PR(J),    PR(U),    PR(M),    PR(P),    PR(Sp),   PR(B),    PR(O),    PR(O),    PR(T),    PR(S),    PR(Sp),   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      NUL,
};

static const uint16 kSpaceJumpMsgBoxTilemap[32] = {  // 0x858DFF
  NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(S),    PR(P),    PR(A),    PR(C),    PR(E),    PR(Sp),   PR(J),    PR(U),    PR(M),    PR(P),    PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      NUL,
};

static const uint16 kSpeedBoosterMsgBoxTilemap[128] = {  // 0x858E3F
  NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(S),    PR(P),    PR(E),    PR(E),    PR(D),    PR(Sp),   PR(B),    PR(O),    PR(O),    PR(S),    PR(T),    PR(E),    PR(R),    PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,
  NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,
  NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,
  NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   0x28B0,   0x28B1,   0x28B2,   PR(Sp),   0x28C8,   PR(Sp),   0x28B3,   0x28B4,   0x28C0,   0x28C1,   0x28D1,   0x38D0,   0x28D3,   0x28B5,   0x28B6,   0x28B7,   PR(Sp),   0x28C2,   PR(Sp),   0x28BC,   0x28BD,   0x28CB,   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,
};

static const uint16 kChargeBeamMsgBoxTilemap[32] = {  // 0x858F3F
  NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(C),    PR(H),    PR(A),    PR(R),    PR(G),    PR(E),    PR(Sp),   PR(B),    PR(E),    PR(A),    PR(M),    PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      NUL,
};

static const uint16 kIceBeamMsgBoxTilemap[32] = {  // 0x858F7F
  NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(I),    PR(C),    PR(E),    PR(Sp),   PR(B),    PR(E),    PR(A),    PR(M),    PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      NUL,
};

static const uint16 kWaveBeamMsgBoxTilemap[32] = {  // 0x858FBF
  NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(W),    PR(A),    PR(V),    PR(E),    PR(Sp),   PR(B),    PR(E),    PR(A),    PR(M),    PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      NUL,
};

static const uint16 kSpazerMsgBoxTilemap[32] = {  // 0x858FFF
  NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(S),    PR(P),    PR(A),    PR(Z),    PR(E),    PR(R),    PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      NUL,
};

static const uint16 kPlasmaBeamMsgBoxTilemap[32] = {  // 0x85903F
  NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(P),    PR(L),    PR(A),    PR(S),    PR(M),    PR(A),    PR(Sp),   PR(B),    PR(E),    PR(A),    PR(M),    PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      NUL,
};

static const uint16 kBombMsgBoxTilemap[128] = {  // 0x85907F
  NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(B),    PR(O),    PR(M),    PR(B),    PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,
  NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   0x38DC,   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,
  NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   0x3CDD,   0x3CDF,   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,
  NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   0x3CDE,   0x3CCC,   0x38CD,   0x3CC9,   PR(Sp),   0x28C8,   PR(Sp),   0x28C5,   0x28C6,   0x28C7,   PR(Sp),   0x28BE,   0x28BF,   0x28C0,   0x28C1,   0x28D1,   GN(L),    0x28D3,   0x28B5,   0x28B6,   0x28B7,   0x28CB,   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,
};

static const uint16 kMapDataAccessCompletedMsgBoxTilemap[96] = {  // 0x85917F
  NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      YL(Sp),   YL(Sp),   YL(M),    YL(A),    YL(P),    YL(Sp),   YL(D),    YL(A),    YL(T),    YL(A),    YL(Sp),   YL(A),    YL(C),    YL(C),    YL(E),    YL(S),    YL(S),    YL(Sp),   YL(Sp),   NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      NUL,
  NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      NUL,
  NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(C),    YL(O),    YL(M),    YL(P),    YL(L),    YL(E),    YL(T),    YL(E),    YL(D),    0x3CFA,   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      NUL,
};

static const uint16 kEnergyRechargeCompletedMsgBoxTilemap[96] = {  // 0x85923F
  NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      YL(Sp),   YL(Sp),   YL(E),    YL(N),    YL(E),    YL(R),    YL(G),    YL(Y),    YL(Sp),   YL(R),    YL(E),    YL(C),    YL(H),    YL(A),    YL(R),    YL(G),    YL(E),    YL(Sp),   YL(Sp),   NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      NUL,
  NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      NUL,
  NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(C),    YL(O),    YL(M),    YL(P),    YL(L),    YL(E),    YL(T),    YL(E),    YL(D),    0x3CFA,   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      NUL,
};

static const uint16 kAmmoRechargeCompletedMsgBoxTilemap[96] = {
  NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      YL(Sp),   YL(Sp),   YL(A),    YL(M),    YL(M),    YL(O),    YL(Sp),   YL(R),    YL(E),    YL(C),    YL(H),    YL(A),    YL(R),    YL(G),    YL(E),    YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      NUL,
  NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      NUL,
  NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(C),    YL(O),    YL(M),    YL(P),    YL(L),    YL(E),    YL(T),    YL(E),    YL(D),    0x3CFA,   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      NUL,
};

static const uint16 kMissileReloadCompletedMsgBoxTilemap[96] = {  // 0x8592FF
  NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      YL(Sp),   YL(Sp),   YL(M),    YL(I),    YL(S),    YL(S),    YL(I),    YL(L),    YL(E),    YL(Sp),   YL(R),    YL(E),    YL(L),    YL(O),    YL(A),    YL(D),    YL(Sp),   YL(Sp),   YL(Sp),   NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      NUL,
  NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      YL(Sp),   YL(Sp),   GN(Sp),   GN(Sp),   GN(Sp),   GN(Sp),   GN(Sp),   GN(Sp),   GN(Sp),   GN(Sp),   GN(Sp),   GN(Sp),   GN(Sp),   GN(Sp),   GN(Sp),   GN(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      NUL,
  NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      YL(Sp),   YL(Sp),   GN(Sp),   GN(Sp),   YL(C),    YL(O),    YL(M),    YL(P),    YL(L),    YL(E),    YL(T),    YL(E),    YL(D),    0x3CFA,   GN(Sp),   GN(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      NUL,
};

static const uint16 kWouldYouLikeToSaveMsgBoxTilemap[128] = {  // 0x8593BF
  NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      YL(Sp),   YL(Sp),   YL(W),    YL(O),    YL(U),    YL(L),    YL(D),    YL(Sp),   YL(Y),    YL(O),    YL(U),    YL(Sp),   YL(L),    YL(I),    YL(K),    YL(E),    YL(Sp),   YL(Sp),   YL(Sp),   NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      NUL,
  NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      YL(Sp),   YL(Sp),   YL(T),    YL(O),    YL(Sp),   YL(S),    YL(A),    YL(V),    YL(E),    0x3CFE,   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      NUL,
  NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      NUL,
  NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      YL(Sp),   YL(Sp),   0x38CC,   0x38CD,   YL(Y),    YL(E),    YL(S),    YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   0x2CED,   0x2CEE,   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      NUL,
};

static const uint16 kSaveCompletedMsgBoxTilemap[32] = {  // 0x8594BF
  NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      YL(Sp),   YL(Sp),   YL(S),    YL(A),    YL(V),    YL(E),    YL(Sp),   YL(C),    YL(O),    YL(M),    YL(P),    YL(L),    YL(E),    YL(T),    YL(E),    YL(D),    0x3CFA,   YL(Sp),   YL(Sp),   NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      NUL,
};

static const uint16 kReserveTankMsgBoxTilemap[32] = {  // 0x8594FF
  NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   PR(Sp),   PR(R),    PR(E),    PR(S),    PR(E),    PR(R),    PR(V),    PR(E),    PR(Sp),   PR(T),    PR(A),    PR(N),    PR(K),    PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      NUL,
};

static const uint16 kGravitySuitMsgBoxTilemap[32] = {  // 0x85953F
  NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      PR(Sp),   PR(Sp),   PR(Sp),   PR(G),    PR(R),    PR(A),    PR(V),    PR(I),    PR(T),    PR(Y),    PR(Sp),   PR(S),    PR(U),    PR(I),    PR(T),    PR(Sp),   PR(Sp),   PR(Sp),   PR(Sp),   NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      NUL,
};

static const uint16 kTerminator1MsgBoxTilemap[1] = {  // 0x85957F
  0x0000,
};

static const uint16 kSaveConfirmationSelectionTilemap[96] = {  // 0x859581
  NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      YL(Sp),   YL(Sp),   0x38CC,   0x38CD,   YL(Y),    YL(E),    YL(S),    YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   0x2CED,   0x2CEE,   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      NUL,
  NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      YL(Sp),   YL(Sp),   0x38CC,   0x38CD,   YL(Y),    YL(E),    YL(S),    YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   0x2CED,   0x2CEE,   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      NUL,
  NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   0x2CF8,   0x2CE4,   0x2CF2,   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   0x38CC,   0x38CD,   YL(N),    YL(O),    YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      NUL,
};

//static const uint16 kWouldYouLikeToSaveGunshipMsgBoxTilemap[128] = {  // 0x8593BF
//  NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      YL(Sp),   YL(Sp),   YL(W),    YL(O),    YL(U),    YL(L),    YL(D),    YL(Sp),   YL(Y),    YL(O),    YL(U),    YL(Sp),   YL(L),    YL(I),    YL(K),    YL(E),    YL(Sp),   YL(Sp),   YL(Sp),   NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      NUL,
//  NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      YL(Sp),   YL(Sp),   YL(T),    YL(O),    YL(Sp),   YL(S),    YL(A),    YL(V),    YL(E),    0x3CFE,   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      NUL,
//  NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      NUL,
//  NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      YL(Sp),   YL(Sp),   0x38CC,   0x38CD,   YL(Y),    YL(E),    YL(S),    YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   0x2CED,   0x2CEE,   YL(Sp),   YL(Sp),   YL(Sp),   YL(Sp),   NUL,      NUL,      NUL,      NUL,      NUL,      NUL,      NUL,
//};

//static const uint16 kTerminatorSaveCompletedUnusedMsgBoxTilemap[1] = {  // 0x8594BF
//  NUL,
//};

static const uint16* getMessageTilemap(uint16 tilemap) {
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

