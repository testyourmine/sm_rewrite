#pragma once

#include "funcs.h"
#include "ida_types.h"

#define PROJ_INSTR(INSTR) (addr_kProjectile_IList_##INSTR)
#define PROJ_INSTR_DRAW(INSTR, ENTRY, ANIM) (addr_kProjectile_IList_##INSTR + ENTRY*sizeof(ProjectileInstr_1) + ANIM*sizeof(ProjectileInstr_2))
#define PROJ_INSTR_FUNC(INSTR, ENTRY, ANIM) (addr_kProjectile_IList_##INSTR + ENTRY*sizeof(ProjectileInstr_1) + ANIM*sizeof(ProjectileInstr_2))

static const ProjectileDataTable kProjectileData_UnchargedBeams[] = {  // 0x9383C1
  [kProjectileType_Power]                                           = { .damage =  20, .up_to_right = PROJ_INSTR(Power_Up)                    , .up_right = PROJ_INSTR(Power_UpRight)                     , .right = PROJ_INSTR(Power_Right)                         , .down_right = PROJ_INSTR(Power_DownRight)                     , .down_to_right = PROJ_INSTR(Power_Down)                     , .down_to_left = PROJ_INSTR(Power_Down)                    , .down_left = PROJ_INSTR(Power_DownLeft)                    , .left = PROJ_INSTR(Power_Left)                          , .up_left = PROJ_INSTR(Power_UpLeft)                      , .up_to_left = PROJ_INSTR(Power_Up)                    },
  [kProjectileType_Wave]                                            = { .damage =  50, .up_to_right = PROJ_INSTR(Wave_IceWave_Up)             , .up_right = PROJ_INSTR(Wave_IceWave_DownLeft_UpRight)     , .right = PROJ_INSTR(Wave_IceWave_Left_Right)             , .down_right = PROJ_INSTR(Wave_IceWave_DownRight_UpLeft)       , .down_to_right = PROJ_INSTR(Wave_IceWave_Down)              , .down_to_left = PROJ_INSTR(Wave_IceWave_Down)             , .down_left = PROJ_INSTR(Wave_IceWave_DownLeft_UpRight)     , .left = PROJ_INSTR(Wave_IceWave_Left_Right)             , .up_left = PROJ_INSTR(Wave_IceWave_DownRight_UpLeft)     , .up_to_left = PROJ_INSTR(Wave_IceWave_Up)             },
  [kProjectileType_Ice]                                             = { .damage =  30, .up_to_right = PROJ_INSTR(Ice)                         , .up_right = PROJ_INSTR(Ice)                               , .right = PROJ_INSTR(Ice)                                 , .down_right = PROJ_INSTR(Ice)                                 , .down_to_right = PROJ_INSTR(Ice)                            , .down_to_left = PROJ_INSTR(Ice)                           , .down_left = PROJ_INSTR(Ice)                               , .left = PROJ_INSTR(Ice)                                 , .up_left = PROJ_INSTR(Ice)                               , .up_to_left = PROJ_INSTR(Ice)                         },
  [kProjectileType_Ice|kProjectileType_Wave]                        = { .damage =  60, .up_to_right = PROJ_INSTR(Wave_IceWave_Up)             , .up_right = PROJ_INSTR(Wave_IceWave_DownLeft_UpRight)     , .right = PROJ_INSTR(Wave_IceWave_Left_Right)             , .down_right = PROJ_INSTR(Wave_IceWave_DownRight_UpLeft)       , .down_to_right = PROJ_INSTR(Wave_IceWave_Down)              , .down_to_left = PROJ_INSTR(Wave_IceWave_Down)             , .down_left = PROJ_INSTR(Wave_IceWave_DownLeft_UpRight)     , .left = PROJ_INSTR(Wave_IceWave_Left_Right)             , .up_left = PROJ_INSTR(Wave_IceWave_DownRight_UpLeft)     , .up_to_left = PROJ_INSTR(Wave_IceWave_Up)             },
  [kProjectileType_Spazer]                                          = { .damage =  40, .up_to_right = PROJ_INSTR(Spazer_SpazerIce_Up)         , .up_right = PROJ_INSTR(Spazer_SpazerIce_UpRight)          , .right = PROJ_INSTR(Spazer_SpazerIce_Right)              , .down_right = PROJ_INSTR(Spazer_SpazerIce_DownRight)          , .down_to_right = PROJ_INSTR(Spazer_SpazerIce_Down)          , .down_to_left = PROJ_INSTR(Spazer_SpazerIce_Down)         , .down_left = PROJ_INSTR(Spazer_SpazerIce_DownLeft)         , .left = PROJ_INSTR(Spazer_SpazerIce_Left)               , .up_left = PROJ_INSTR(Spazer_SpazerIce_UpLeft)           , .up_to_left = PROJ_INSTR(Spazer_SpazerIce_Up)         },
  [kProjectileType_Spazer|kProjectileType_Wave]                     = { .damage =  70, .up_to_right = PROJ_INSTR(SpazerWave_SpazerIceWave_Up) , .up_right = PROJ_INSTR(SpazerWave_SpazerIceWave_UpRight)  , .right = PROJ_INSTR(SpazerWave_SpazerIceWave_Right)      , .down_right = PROJ_INSTR(SpazerWave_SpazerIceWave_DownRight)  , .down_to_right = PROJ_INSTR(SpazerWave_SpazerIceWave_Down)  , .down_to_left = PROJ_INSTR(SpazerWave_SpazerIceWave_Down) , .down_left = PROJ_INSTR(SpazerWave_SpazerIceWave_DownLeft) , .left = PROJ_INSTR(SpazerWave_SpazerIceWave_Left)       , .up_left = PROJ_INSTR(SpazerWave_SpazerIceWave_UpLeft)   , .up_to_left = PROJ_INSTR(SpazerWave_SpazerIceWave_Up) },
  [kProjectileType_Spazer|kProjectileType_Ice]                      = { .damage =  60, .up_to_right = PROJ_INSTR(Spazer_SpazerIce_Up)         , .up_right = PROJ_INSTR(Spazer_SpazerIce_UpRight)          , .right = PROJ_INSTR(Spazer_SpazerIce_Right)              , .down_right = PROJ_INSTR(Spazer_SpazerIce_DownRight)          , .down_to_right = PROJ_INSTR(Spazer_SpazerIce_Down)          , .down_to_left = PROJ_INSTR(Spazer_SpazerIce_Down)         , .down_left = PROJ_INSTR(Spazer_SpazerIce_DownLeft)         , .left = PROJ_INSTR(Spazer_SpazerIce_Left)               , .up_left = PROJ_INSTR(Spazer_SpazerIce_UpLeft)           , .up_to_left = PROJ_INSTR(Spazer_SpazerIce_Up)         },
  [kProjectileType_Spazer|kProjectileType_Ice|kProjectileType_Wave] = { .damage = 100, .up_to_right = PROJ_INSTR(SpazerWave_SpazerIceWave_Up) , .up_right = PROJ_INSTR(SpazerWave_SpazerIceWave_UpRight)  , .right = PROJ_INSTR(SpazerWave_SpazerIceWave_Right)      , .down_right = PROJ_INSTR(SpazerWave_SpazerIceWave_DownRight)  , .down_to_right = PROJ_INSTR(SpazerWave_SpazerIceWave_Down)  , .down_to_left = PROJ_INSTR(SpazerWave_SpazerIceWave_Down) , .down_left = PROJ_INSTR(SpazerWave_SpazerIceWave_DownLeft) , .left = PROJ_INSTR(SpazerWave_SpazerIceWave_Left)       , .up_left = PROJ_INSTR(SpazerWave_SpazerIceWave_UpLeft)   , .up_to_left = PROJ_INSTR(SpazerWave_SpazerIceWave_Up) },
  [kProjectileType_Plasma]                                          = { .damage = 150, .up_to_right = PROJ_INSTR(Plasma_PlasmaIce_Down_Up)    , .up_right = PROJ_INSTR(Plasma_PlasmaIce_DownLeft_UpRight) , .right = PROJ_INSTR(Plasma_PlasmaIce_Left_Right)         , .down_right = PROJ_INSTR(Plasma_PlasmaIce_DownRight_UpLeft)   , .down_to_right = PROJ_INSTR(Plasma_PlasmaIce_Down_Up)       , .down_to_left = PROJ_INSTR(Plasma_PlasmaIce_Down_Up)      , .down_left = PROJ_INSTR(Plasma_PlasmaIce_DownLeft_UpRight) , .left = PROJ_INSTR(Plasma_PlasmaIce_Left_Right)         , .up_left = PROJ_INSTR(Plasma_PlasmaIce_DownRight_UpLeft) , .up_to_left = PROJ_INSTR(Plasma_PlasmaIce_Down_Up)    },
  [kProjectileType_Plasma|kProjectileType_Wave]                     = { .damage = 250, .up_to_right = PROJ_INSTR(PlasmaWave_Down_Up)          , .up_right = PROJ_INSTR(PlasmaWave_DownLeft_UpRight)       , .right = PROJ_INSTR(PlasmaWave_PlasmaIceWave_Left_Right) , .down_right = PROJ_INSTR(PlasmaWave_DownRight_UpLeft)         , .down_to_right = PROJ_INSTR(PlasmaWave_Down_Up)             , .down_to_left = PROJ_INSTR(PlasmaWave_Down_Up)            , .down_left = PROJ_INSTR(PlasmaWave_DownLeft_UpRight)       , .left = PROJ_INSTR(PlasmaWave_PlasmaIceWave_Left_Right) , .up_left = PROJ_INSTR(PlasmaWave_DownRight_UpLeft)       , .up_to_left = PROJ_INSTR(PlasmaWave_Down_Up)          },
  [kProjectileType_Plasma|kProjectileType_Ice]                      = { .damage = 200, .up_to_right = PROJ_INSTR(Plasma_PlasmaIce_Down_Up)    , .up_right = PROJ_INSTR(Plasma_PlasmaIce_DownLeft_UpRight) , .right = PROJ_INSTR(Plasma_PlasmaIce_Left_Right)         , .down_right = PROJ_INSTR(Plasma_PlasmaIce_DownRight_UpLeft)   , .down_to_right = PROJ_INSTR(Plasma_PlasmaIce_Down_Up)       , .down_to_left = PROJ_INSTR(Plasma_PlasmaIce_Down_Up)      , .down_left = PROJ_INSTR(Plasma_PlasmaIce_DownLeft_UpRight) , .left = PROJ_INSTR(Plasma_PlasmaIce_Left_Right)         , .up_left = PROJ_INSTR(Plasma_PlasmaIce_DownRight_UpLeft) , .up_to_left = PROJ_INSTR(Plasma_PlasmaIce_Down_Up)    },
  [kProjectileType_Plasma|kProjectileType_Ice|kProjectileType_Wave] = { .damage = 300, .up_to_right = PROJ_INSTR(PlasmaIceWave_Down_Up)       , .up_right = PROJ_INSTR(PlasmaIceWave_DownLeft_UpRight)    , .right = PROJ_INSTR(PlasmaWave_PlasmaIceWave_Left_Right) , .down_right = PROJ_INSTR(PlasmaIceWave_DownRight_UpLeft)      , .down_to_right = PROJ_INSTR(PlasmaIceWave_Down_Up)          , .down_to_left = PROJ_INSTR(PlasmaIceWave_Down_Up)         , .down_left = PROJ_INSTR(PlasmaIceWave_DownLeft_UpRight)    , .left = PROJ_INSTR(PlasmaWave_PlasmaIceWave_Left_Right) , .up_left = PROJ_INSTR(PlasmaIceWave_DownRight_UpLeft)    , .up_to_left = PROJ_INSTR(PlasmaIceWave_Down_Up)       },
};

static const ProjectileDataTable kProjectileData_ChargedBeams[] = {  // 0x9383D9
  [kProjectileType_Power]                                           = { .damage =  60, .up_to_right = PROJ_INSTR(Charged_Power_Up)                         , .up_right = PROJ_INSTR(Charged_Power_UpRight)                             , .right = PROJ_INSTR(Charged_Power_Right)                         , .down_right = PROJ_INSTR(Charged_Power_DownRight)                           , .down_to_right = PROJ_INSTR(Charged_Power_Down)                       , .down_to_left = PROJ_INSTR(Charged_Power_Down)                       , .down_left = PROJ_INSTR(Charged_Power_DownLeft)                            , .left = PROJ_INSTR(Charged_Power_Left)                          , .up_left = PROJ_INSTR(Charged_Power_UpLeft)                              , .up_to_left = PROJ_INSTR(Charged_Power_Up)                         },
  [kProjectileType_Wave]                                            = { .damage = 150, .up_to_right = PROJ_INSTR(Charged_Wave_Up)                          , .up_right = PROJ_INSTR(Charged_Wave_DownLeft_UpRight)                     , .right = PROJ_INSTR(Charged_Wave_Left_Right)                     , .down_right = PROJ_INSTR(Charged_Wave_DownRight_UpLeft)                     , .down_to_right = PROJ_INSTR(Charged_Wave_Down)                        , .down_to_left = PROJ_INSTR(Charged_Wave_Down)                        , .down_left = PROJ_INSTR(Charged_Wave_DownLeft_UpRight)                     , .left = PROJ_INSTR(Charged_Wave_Left_Right)                     , .up_left = PROJ_INSTR(Charged_Wave_DownRight_UpLeft)                     , .up_to_left = PROJ_INSTR(Charged_Wave_Up)                          },
  [kProjectileType_Ice]                                             = { .damage =  90, .up_to_right = PROJ_INSTR(Charged_Ice)                              , .up_right = PROJ_INSTR(Charged_Ice)                                       , .right = PROJ_INSTR(Charged_Ice)                                 , .down_right = PROJ_INSTR(Charged_Ice)                                       , .down_to_right = PROJ_INSTR(Charged_Ice)                              , .down_to_left = PROJ_INSTR(Charged_Ice)                              , .down_left = PROJ_INSTR(Charged_Ice)                                       , .left = PROJ_INSTR(Charged_Ice)                                 , .up_left = PROJ_INSTR(Charged_Ice)                                       , .up_to_left = PROJ_INSTR(Charged_Ice)                              },
  [kProjectileType_Ice|kProjectileType_Wave]                        = { .damage = 180, .up_to_right = PROJ_INSTR(Charged_IceWave_Up)                       , .up_right = PROJ_INSTR(Charged_IceWave_DownLeft_UpRight)                  , .right = PROJ_INSTR(Charged_IceWave_Left_Right)                  , .down_right = PROJ_INSTR(Charged_IceWave_DownRight_UpLeft)                  , .down_to_right = PROJ_INSTR(Charged_IceWave_Down)                     , .down_to_left = PROJ_INSTR(Charged_IceWave_Down)                     , .down_left = PROJ_INSTR(Charged_IceWave_DownLeft_UpRight)                  , .left = PROJ_INSTR(Charged_IceWave_Left_Right)                  , .up_left = PROJ_INSTR(Charged_IceWave_DownRight_UpLeft)                  , .up_to_left = PROJ_INSTR(Charged_IceWave_Up)                       },
  [kProjectileType_Spazer]                                          = { .damage = 120, .up_to_right = PROJ_INSTR(Charged_Spazer_SpazerIce_Down_Up)         , .up_right = PROJ_INSTR(Charged_Spazer_SpazerIce_DownLeft_UpRight)         , .right = PROJ_INSTR(Charged_Spazer_SpazerIce_Left_Right)         , .down_right = PROJ_INSTR(Charged_Spazer_SpazerIce_DownRight_UpLeft)         , .down_to_right = PROJ_INSTR(Charged_Spazer_SpazerIce_Down_Up)         , .down_to_left = PROJ_INSTR(Charged_Spazer_SpazerIce_Down_Up)         , .down_left = PROJ_INSTR(Charged_Spazer_SpazerIce_DownLeft_UpRight)         , .left = PROJ_INSTR(Charged_Spazer_SpazerIce_Left_Right)         , .up_left = PROJ_INSTR(Charged_Spazer_SpazerIce_DownRight_UpLeft)         , .up_to_left = PROJ_INSTR(Charged_Spazer_SpazerIce_Down_Up)         },
  [kProjectileType_Spazer|kProjectileType_Wave]                     = { .damage = 210, .up_to_right = PROJ_INSTR(Charged_SpazerWave_SpazerIceWave_Up)      , .up_right = PROJ_INSTR(Charged_SpazerWave_SpazerIceWave_UpRight)          , .right = PROJ_INSTR(Charged_SpazerWave_SpazerIceWave_Right)      , .down_right = PROJ_INSTR(Charged_SpazerWave_SpazerIceWave_DownRight)        , .down_to_right = PROJ_INSTR(Charged_SpazerWave_SpazerIceWave_Down)    , .down_to_left = PROJ_INSTR(Charged_SpazerWave_SpazerIceWave_Down)    , .down_left = PROJ_INSTR(Charged_SpazerWave_SpazerIceWave_DownLeft)         , .left = PROJ_INSTR(Charged_SpazerWave_SpazerIceWave_Left)       , .up_left = PROJ_INSTR(Charged_SpazerWave_SpazerIceWave_UpLeft)           , .up_to_left = PROJ_INSTR(Charged_SpazerWave_SpazerIceWave_Up)      },
  [kProjectileType_Spazer|kProjectileType_Ice]                      = { .damage = 180, .up_to_right = PROJ_INSTR(Charged_Spazer_SpazerIce_Down_Up)         , .up_right = PROJ_INSTR(Charged_Spazer_SpazerIce_DownLeft_UpRight)         , .right = PROJ_INSTR(Charged_Spazer_SpazerIce_Left_Right)         , .down_right = PROJ_INSTR(Charged_Spazer_SpazerIce_DownRight_UpLeft)         , .down_to_right = PROJ_INSTR(Charged_Spazer_SpazerIce_Down_Up)         , .down_to_left = PROJ_INSTR(Charged_Spazer_SpazerIce_Down_Up)         , .down_left = PROJ_INSTR(Charged_Spazer_SpazerIce_DownLeft_UpRight)         , .left = PROJ_INSTR(Charged_Spazer_SpazerIce_Left_Right)         , .up_left = PROJ_INSTR(Charged_Spazer_SpazerIce_DownRight_UpLeft)         , .up_to_left = PROJ_INSTR(Charged_Spazer_SpazerIce_Down_Up)         },
  [kProjectileType_Spazer|kProjectileType_Ice|kProjectileType_Wave] = { .damage = 300, .up_to_right = PROJ_INSTR(Charged_SpazerWave_SpazerIceWave_Up)      , .up_right = PROJ_INSTR(Charged_SpazerWave_SpazerIceWave_UpRight)          , .right = PROJ_INSTR(Charged_SpazerWave_SpazerIceWave_Right)      , .down_right = PROJ_INSTR(Charged_SpazerWave_SpazerIceWave_DownRight)        , .down_to_right = PROJ_INSTR(Charged_SpazerWave_SpazerIceWave_Down)    , .down_to_left = PROJ_INSTR(Charged_SpazerWave_SpazerIceWave_Down)    , .down_left = PROJ_INSTR(Charged_SpazerWave_SpazerIceWave_DownLeft)         , .left = PROJ_INSTR(Charged_SpazerWave_SpazerIceWave_Left)       , .up_left = PROJ_INSTR(Charged_SpazerWave_SpazerIceWave_UpLeft)           , .up_to_left = PROJ_INSTR(Charged_SpazerWave_SpazerIceWave_Up)      },
  [kProjectileType_Plasma]                                          = { .damage = 450, .up_to_right = PROJ_INSTR(Charged_Plasma_PlasmaIce_Down_Up)         , .up_right = PROJ_INSTR(Charged_Plasma_PlasmaIce_DownLeft_UpRight)         , .right = PROJ_INSTR(Charged_Plasma_PlasmaIce_Left_Right)         , .down_right = PROJ_INSTR(Charged_Plasma_PlasmaIce_DownRight_UpLeft)         , .down_to_right = PROJ_INSTR(Charged_Plasma_PlasmaIce_Down_Up)         , .down_to_left = PROJ_INSTR(Charged_Plasma_PlasmaIce_Down_Up)         , .down_left = PROJ_INSTR(Charged_Plasma_PlasmaIce_DownLeft_UpRight)         , .left = PROJ_INSTR(Charged_Plasma_PlasmaIce_Left_Right)         , .up_left = PROJ_INSTR(Charged_Plasma_PlasmaIce_DownRight_UpLeft)         , .up_to_left = PROJ_INSTR(Charged_Plasma_PlasmaIce_Down_Up)         },
  [kProjectileType_Plasma|kProjectileType_Wave]                     = { .damage = 750, .up_to_right = PROJ_INSTR(Charged_PlasmaWave_PlasmaIceWave_Down_Up) , .up_right = PROJ_INSTR(Charged_PlasmaWave_PlasmaIceWave_DownLeft_UpRight) , .right = PROJ_INSTR(Charged_PlasmaWave_PlasmaIceWave_Left_Right) , .down_right = PROJ_INSTR(Charged_PlasmaWave_PlasmaIceWave_DownRight_UpLeft) , .down_to_right = PROJ_INSTR(Charged_PlasmaWave_PlasmaIceWave_Down_Up) , .down_to_left = PROJ_INSTR(Charged_PlasmaWave_PlasmaIceWave_Down_Up) , .down_left = PROJ_INSTR(Charged_PlasmaWave_PlasmaIceWave_DownLeft_UpRight) , .left = PROJ_INSTR(Charged_PlasmaWave_PlasmaIceWave_Left_Right) , .up_left = PROJ_INSTR(Charged_PlasmaWave_PlasmaIceWave_DownRight_UpLeft) , .up_to_left = PROJ_INSTR(Charged_PlasmaWave_PlasmaIceWave_Down_Up) },
  [kProjectileType_Plasma|kProjectileType_Ice]                      = { .damage = 600, .up_to_right = PROJ_INSTR(Charged_Plasma_PlasmaIce_Down_Up)         , .up_right = PROJ_INSTR(Charged_Plasma_PlasmaIce_DownLeft_UpRight)         , .right = PROJ_INSTR(Charged_Plasma_PlasmaIce_Left_Right)         , .down_right = PROJ_INSTR(Charged_Plasma_PlasmaIce_DownRight_UpLeft)         , .down_to_right = PROJ_INSTR(Charged_Plasma_PlasmaIce_Down_Up)         , .down_to_left = PROJ_INSTR(Charged_Plasma_PlasmaIce_Down_Up)         , .down_left = PROJ_INSTR(Charged_Plasma_PlasmaIce_DownLeft_UpRight)         , .left = PROJ_INSTR(Charged_Plasma_PlasmaIce_Left_Right)         , .up_left = PROJ_INSTR(Charged_Plasma_PlasmaIce_DownRight_UpLeft)         , .up_to_left = PROJ_INSTR(Charged_Plasma_PlasmaIce_Down_Up)         },
  [kProjectileType_Plasma|kProjectileType_Ice|kProjectileType_Wave] = { .damage = 900, .up_to_right = PROJ_INSTR(Charged_PlasmaWave_PlasmaIceWave_Down_Up) , .up_right = PROJ_INSTR(Charged_PlasmaWave_PlasmaIceWave_DownLeft_UpRight) , .right = PROJ_INSTR(Charged_PlasmaWave_PlasmaIceWave_Left_Right) , .down_right = PROJ_INSTR(Charged_PlasmaWave_PlasmaIceWave_DownRight_UpLeft) , .down_to_right = PROJ_INSTR(Charged_PlasmaWave_PlasmaIceWave_Down_Up) , .down_to_left = PROJ_INSTR(Charged_PlasmaWave_PlasmaIceWave_Down_Up) , .down_left = PROJ_INSTR(Charged_PlasmaWave_PlasmaIceWave_DownLeft_UpRight) , .left = PROJ_INSTR(Charged_PlasmaWave_PlasmaIceWave_Left_Right) , .up_left = PROJ_INSTR(Charged_PlasmaWave_PlasmaIceWave_DownRight_UpLeft) , .up_to_left = PROJ_INSTR(Charged_PlasmaWave_PlasmaIceWave_Down_Up) },
};

static const ProjectileDataTable kProjectileData_NonBeams[] = {  // 0x9383F1
  [0]                                   = { .damage = 100, .up_to_right = PROJ_INSTR(Missiles_Up)     , .up_right = PROJ_INSTR(Missiles_UpRight)     , .right = PROJ_INSTR(Missiles_Right)     , .down_right = PROJ_INSTR(Missiles_DownRight)     , .down_to_right = PROJ_INSTR(Missiles_Down)     , .down_to_left = PROJ_INSTR(Missiles_Down)     , .down_left = PROJ_INSTR(Missiles_DownLeft)     , .left = PROJ_INSTR(Missiles_Left)     , .up_left = PROJ_INSTR(Missiles_UpLeft)     , .up_to_left = PROJ_INSTR(Missiles_Up)     },
  [kProjectileType_Missile>>8]          = { .damage = 100, .up_to_right = PROJ_INSTR(Missiles_Up)     , .up_right = PROJ_INSTR(Missiles_UpRight)     , .right = PROJ_INSTR(Missiles_Right)     , .down_right = PROJ_INSTR(Missiles_DownRight)     , .down_to_right = PROJ_INSTR(Missiles_Down)     , .down_to_left = PROJ_INSTR(Missiles_Down)     , .down_left = PROJ_INSTR(Missiles_DownLeft)     , .left = PROJ_INSTR(Missiles_Left)     , .up_left = PROJ_INSTR(Missiles_UpLeft)     , .up_to_left = PROJ_INSTR(Missiles_Up)     },
  [kProjectileType_SuperMissile>>8]     = { .damage = 300, .up_to_right = PROJ_INSTR(SuperMissile_Up) , .up_right = PROJ_INSTR(SuperMissile_UpRight) , .right = PROJ_INSTR(SuperMissile_Right) , .down_right = PROJ_INSTR(SuperMissile_DownRight) , .down_to_right = PROJ_INSTR(SuperMissile_Down) , .down_to_left = PROJ_INSTR(SuperMissile_Down) , .down_left = PROJ_INSTR(SuperMissile_DownLeft) , .left = PROJ_INSTR(SuperMissile_Left) , .up_left = PROJ_INSTR(SuperMissile_UpLeft) , .up_to_left = PROJ_INSTR(SuperMissile_Up) },
  [kProjectileType_PowerBomb>>8]        = { .damage = 200, .instr_ptrs[0] = PROJ_INSTR(PowerBomb) },                                                                                                                                              
  [4]                                   = { .damage = 100, .up_to_right = PROJ_INSTR(Missiles_Up)     , .up_right = PROJ_INSTR(Missiles_UpRight)     , .right = PROJ_INSTR(Missiles_Right)     , .down_right = PROJ_INSTR(Missiles_DownRight)     , .down_to_right = PROJ_INSTR(Missiles_Down)     , .down_to_left = PROJ_INSTR(Missiles_Down)     , .down_left = PROJ_INSTR(Missiles_DownLeft)     , .left = PROJ_INSTR(Missiles_Left)     , .up_left = PROJ_INSTR(Missiles_UpLeft)     , .up_to_left = PROJ_INSTR(Missiles_Up)     },
  [kProjectileType_Bomb>>8]             = { .damage =  30, .instr_ptrs[0] = PROJ_INSTR(Bomb) },                                                                                                                                                   
  [6]                                   = { .damage = 100, .up_to_right = PROJ_INSTR(Missiles_Up)     , .up_right = PROJ_INSTR(Missiles_UpRight)     , .right = PROJ_INSTR(Missiles_Right)     , .down_right = PROJ_INSTR(Missiles_DownRight)     , .down_to_right = PROJ_INSTR(Missiles_Down)     , .down_to_left = PROJ_INSTR(Missiles_Down)     , .down_left = PROJ_INSTR(Missiles_DownLeft)     , .left = PROJ_INSTR(Missiles_Left)     , .up_left = PROJ_INSTR(Missiles_UpLeft)     , .up_to_left = PROJ_INSTR(Missiles_Up)     },
  [kProjectileType_BeamExplosion>>8]    = { .damage =   8, .instr_ptrs[0] = PROJ_INSTR(BeamExplosion) },
  [kProjectileType_MissileExplosion>>8] = { .damage =   8, .instr_ptrs[0] = PROJ_INSTR(MissileExplosion) },
};

static const ProjectileDataTable kProjectileData_ShinesparkEchoSpazerSba[] = {  // 0x938403
  [0]                                 = { 0 },
  [1]                                 = { 0 },
  [kProjectileType_SpazerSbaTrail-34] = { .damage = 300,   .up_to_right = PROJ_INSTR(Spazer_SBA_Trail)     , .up_right = PROJ_INSTR(Spazer_SBA_Trail)     , .right = PROJ_INSTR(Spazer_SBA_Trail)     , .down_right = PROJ_INSTR(Spazer_SBA_Trail)     , .down_to_right = PROJ_INSTR(Spazer_SBA_Trail)     , .down_to_left = PROJ_INSTR(Spazer_SBA_Trail)     , .down_left = PROJ_INSTR(Spazer_SBA_Trail)     , .left = PROJ_INSTR(Spazer_SBA_Trail)     , .up_left = PROJ_INSTR(Spazer_SBA_Trail)     , .up_to_left = PROJ_INSTR(Spazer_SBA_Trail)     },
  [3]                                 = { .damage = 61440, .up_to_right = PROJ_INSTR(UnusedProjectile_25h) , .up_right = PROJ_INSTR(UnusedProjectile_25h) , .right = PROJ_INSTR(UnusedProjectile_25h) , .down_right = PROJ_INSTR(UnusedProjectile_25h) , .down_to_right = PROJ_INSTR(UnusedProjectile_25h) , .down_to_left = PROJ_INSTR(UnusedProjectile_25h) , .down_left = PROJ_INSTR(UnusedProjectile_25h) , .left = PROJ_INSTR(UnusedProjectile_25h) , .up_left = PROJ_INSTR(UnusedProjectile_25h) , .up_to_left = PROJ_INSTR(UnusedProjectile_25h) },
  [4]                                 = { .damage = 300,   .up_to_right = PROJ_INSTR(Spazer_SBA_Trail)     , .up_right = PROJ_INSTR(Spazer_SBA_Trail)     , .right = PROJ_INSTR(Spazer_SBA_Trail)     , .down_right = PROJ_INSTR(Spazer_SBA_Trail)     , .down_to_right = PROJ_INSTR(Spazer_SBA_Trail)     , .down_to_left = PROJ_INSTR(Spazer_SBA_Trail)     , .down_left = PROJ_INSTR(Spazer_SBA_Trail)     , .left = PROJ_INSTR(Spazer_SBA_Trail)     , .up_left = PROJ_INSTR(Spazer_SBA_Trail)     , .up_to_left = PROJ_INSTR(Spazer_SBA_Trail)     },
  [5]                                 = { .damage =   0, .instr_ptrs[0] = PROJ_INSTR(UnusedShinesparkBeam_Projectile_27h) },                               
  [6]                                 = { 0 },                                                                                                             
  [kProjectileType_ShinesparkEcho-34] = { .damage = 4096,  .up_to_right = PROJ_INSTR(ShinesparkEchoes)     , .up_right = PROJ_INSTR(ShinesparkEchoes)     , .right = PROJ_INSTR(ShinesparkEchoes)     , .down_right = PROJ_INSTR(ShinesparkEchoes)     , .down_to_right = PROJ_INSTR(ShinesparkEchoes)     , .down_to_left = PROJ_INSTR(ShinesparkEchoes)     , .down_left = PROJ_INSTR(ShinesparkEchoes)     , .left = PROJ_INSTR(ShinesparkEchoes)     , .up_left = PROJ_INSTR(ShinesparkEchoes)     , .up_to_left = PROJ_INSTR(ShinesparkEchoes)     },
};

static const ProjectileDataTable kProjectileData_SBA[] = {  // 0x938413
  [0] = { 0 },
  [kProjectileType_Wave]     = { .damage = 300, .instr_ptrs[0] = PROJ_INSTR(Wave_SBA) },
  [2] = { 0 },
  [3] = { 0 },
  [kProjectileType_Spazer]   = { .damage = 300, .instr_ptrs[0] = PROJ_INSTR(Spazer_SpazerIce_Up) },
  [kProjectileType_Spazer+1] = { .damage = 300, .instr_ptrs[0] = PROJ_INSTR(Spazer_SpazerIce_Up) },
  [6] = { 0 },
  [7] = { 0 },
  [kProjectileType_Plasma]   = { .damage = 300, .instr_ptrs[0] = PROJ_INSTR(PlasmaSBA) },
  [kProjectileType_Plasma+1] = { .damage = 300, .instr_ptrs[0] = PROJ_INSTR(PlasmaSBA) },
  [10] = { 0 },
  [11] = { 0 },
};

static const ProjectileDataTable kRunInstrForSuperMissile[] = {  // 0x93842B
  [0]                               = { 0 },
  [1]                               = { 0 },
  [kProjectileType_SuperMissile>>8] = {.damage = 300, .instr_ptrs[0] = PROJ_INSTR(SuperMissile_Link) },
};

static const ProjectileDamagesAndInstrPtr kProjInstrList_BeamExplosion = {  // 0x938679
  .damage =   8, .instr_ptr = PROJ_INSTR(BeamExplosion)
};

static const ProjectileDamagesAndInstrPtr kProjInstrList_MissileExplosion = {  // 0x93867D
  .damage =   8, .instr_ptr = PROJ_INSTR(MissileExplosion)
};

static const ProjectileDamagesAndInstrPtr kProjInstrList_BombExplosion = {  // 0x938681
  .damage =   0, .instr_ptr = PROJ_INSTR(BombExplosion)
};

static const ProjectileDamagesAndInstrPtr kProjInstrList_SuperMissileExplosion = {  // 0x938691
  .damage =   8, .instr_ptr = PROJ_INSTR(SuperMissileExplosion)
};


ProjectileInstr get_ProjectileInstr(uint16 instr_ptr) {
  switch (instr_ptr) {
    case PROJ_INSTR_DRAW(Power_Up, 0, 0)                                           : return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xa25b, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case PROJ_INSTR_FUNC(Power_Up, 1, 0)                                           : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Power_Up, 0, 0) };

    case PROJ_INSTR_DRAW(Power_UpRight, 0, 0)                                      : return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xa262, .x_radius =  8, .y_radius =  4, .trail_frame =  0 };
    case PROJ_INSTR_FUNC(Power_UpRight, 1, 0)                                      : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Power_UpRight, 0, 0) };

    case PROJ_INSTR_DRAW(Power_Right, 0, 0)                                        : return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xa269, .x_radius =  8, .y_radius =  4, .trail_frame =  0 };
    case PROJ_INSTR_FUNC(Power_Right, 1, 0)                                        : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Power_Right, 0, 0) };

    case PROJ_INSTR_DRAW(Power_DownRight, 0, 0)                                    : return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xa270, .x_radius =  8, .y_radius =  4, .trail_frame =  0 };
    case PROJ_INSTR_FUNC(Power_DownRight, 1, 0)                                    : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Power_DownRight, 0, 0) };

    case PROJ_INSTR_DRAW(Power_Down, 0, 0)                                         : return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xa277, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case PROJ_INSTR_FUNC(Power_Down, 1, 0)                                         : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Power_Down, 0, 0) };

    case PROJ_INSTR_DRAW(Power_DownLeft, 0, 0)                                     : return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xa27e, .x_radius =  8, .y_radius =  4, .trail_frame =  0 };
    case PROJ_INSTR_FUNC(Power_DownLeft, 1, 0)                                     : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Power_DownLeft, 0, 0) };

    case PROJ_INSTR_DRAW(Power_Left, 0, 0)                                         : return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xa24d, .x_radius =  8, .y_radius =  4, .trail_frame =  0 };
    case PROJ_INSTR_FUNC(Power_Left, 1, 0)                                         : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Power_Left, 0, 0) };

    case PROJ_INSTR_DRAW(Power_UpLeft, 0, 0)                                       : return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xa254, .x_radius =  8, .y_radius =  4, .trail_frame =  0 };
    case PROJ_INSTR_FUNC(Power_UpLeft, 1, 0)                                       : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Power_UpLeft, 0, 0) };

    case PROJ_INSTR_DRAW(Wave_IceWave_Up, 0, 0)                                    : return (ProjectileInstr){ .timer =  4, .spritemap_ptr = 0xa117, .x_radius = 12, .y_radius =  4, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Wave_IceWave_Down, 0, 0)                                  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae65, .x_radius = 12, .y_radius =  4, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Wave_IceWave_Down, 1, 0)                                  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaedc, .x_radius = 12, .y_radius =  4, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Wave_IceWave_Down, 2, 0)                                  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaee3, .x_radius = 12, .y_radius =  4, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(Wave_IceWave_Down, 3, 0)                                  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaeea, .x_radius = 16, .y_radius =  4, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(Wave_IceWave_Down, 4, 0)                                  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaef1, .x_radius = 20, .y_radius =  4, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(Wave_IceWave_Down, 5, 0)                                  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaeea, .x_radius = 16, .y_radius =  4, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(Wave_IceWave_Down, 6, 0)                                  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaee3, .x_radius = 12, .y_radius =  4, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(Wave_IceWave_Down, 7, 0)                                  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaedc, .x_radius = 12, .y_radius =  4, .trail_frame =  7 };
    case PROJ_INSTR_DRAW(Wave_IceWave_Down, 8, 0)                                  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae65, .x_radius = 12, .y_radius =  4, .trail_frame =  8 };
    case PROJ_INSTR_DRAW(Wave_IceWave_Down, 9, 0)                                  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaef8, .x_radius = 12, .y_radius =  4, .trail_frame =  9 };
    case PROJ_INSTR_DRAW(Wave_IceWave_Down, 10, 0)                                 : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaeff, .x_radius = 12, .y_radius =  4, .trail_frame = 10 };
    case PROJ_INSTR_DRAW(Wave_IceWave_Down, 11, 0)                                 : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf06, .x_radius = 16, .y_radius =  4, .trail_frame = 11 };
    case PROJ_INSTR_DRAW(Wave_IceWave_Down, 12, 0)                                 : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf0d, .x_radius = 20, .y_radius =  4, .trail_frame = 12 };
    case PROJ_INSTR_DRAW(Wave_IceWave_Down, 13, 0)                                 : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf06, .x_radius = 16, .y_radius =  4, .trail_frame = 13 };
    case PROJ_INSTR_DRAW(Wave_IceWave_Down, 14, 0)                                 : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaeff, .x_radius = 12, .y_radius =  4, .trail_frame = 14 };
    case PROJ_INSTR_DRAW(Wave_IceWave_Down, 15, 0)                                 : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaef8, .x_radius = 12, .y_radius =  4, .trail_frame = 15 };
    case PROJ_INSTR_FUNC(Wave_IceWave_Down, 16, 0)                                 : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Wave_IceWave_Down, 0, 0) };

    case PROJ_INSTR_DRAW(Wave_IceWave_DownLeft_UpRight, 0, 0)                      : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae65, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Wave_IceWave_DownLeft_UpRight, 1, 0)                      : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf14, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Wave_IceWave_DownLeft_UpRight, 2, 0)                      : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf1b, .x_radius =  8, .y_radius =  8, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(Wave_IceWave_DownLeft_UpRight, 3, 0)                      : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf22, .x_radius = 10, .y_radius = 10, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(Wave_IceWave_DownLeft_UpRight, 4, 0)                      : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf29, .x_radius = 12, .y_radius = 12, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(Wave_IceWave_DownLeft_UpRight, 5, 0)                      : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf22, .x_radius = 10, .y_radius = 10, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(Wave_IceWave_DownLeft_UpRight, 6, 0)                      : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf1b, .x_radius =  8, .y_radius =  8, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(Wave_IceWave_DownLeft_UpRight, 7, 0)                      : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf14, .x_radius =  6, .y_radius =  6, .trail_frame =  7 };
    case PROJ_INSTR_DRAW(Wave_IceWave_DownLeft_UpRight, 8, 0)                      : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae65, .x_radius =  4, .y_radius =  4, .trail_frame =  8 };
    case PROJ_INSTR_DRAW(Wave_IceWave_DownLeft_UpRight, 9, 0)                      : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf30, .x_radius =  6, .y_radius =  6, .trail_frame =  9 };
    case PROJ_INSTR_DRAW(Wave_IceWave_DownLeft_UpRight, 10, 0)                     : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf37, .x_radius =  8, .y_radius =  8, .trail_frame = 10 };
    case PROJ_INSTR_DRAW(Wave_IceWave_DownLeft_UpRight, 11, 0)                     : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf3e, .x_radius = 10, .y_radius = 10, .trail_frame = 11 };
    case PROJ_INSTR_DRAW(Wave_IceWave_DownLeft_UpRight, 12, 0)                     : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf45, .x_radius = 12, .y_radius = 12, .trail_frame = 12 };
    case PROJ_INSTR_DRAW(Wave_IceWave_DownLeft_UpRight, 13, 0)                     : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf3e, .x_radius = 10, .y_radius = 10, .trail_frame = 13 };
    case PROJ_INSTR_DRAW(Wave_IceWave_DownLeft_UpRight, 14, 0)                     : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf37, .x_radius =  8, .y_radius =  8, .trail_frame = 14 };
    case PROJ_INSTR_DRAW(Wave_IceWave_DownLeft_UpRight, 15, 0)                     : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf30, .x_radius =  8, .y_radius =  8, .trail_frame = 15 };
    case PROJ_INSTR_FUNC(Wave_IceWave_DownLeft_UpRight, 16, 0)                     : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Wave_IceWave_DownLeft_UpRight, 0, 0) };

    case PROJ_INSTR_DRAW(Wave_IceWave_Left_Right, 0, 0)                            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae65, .x_radius =  4, .y_radius = 12, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Wave_IceWave_Left_Right, 1, 0)                            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae6c, .x_radius =  4, .y_radius = 12, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Wave_IceWave_Left_Right, 2, 0)                            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae73, .x_radius =  4, .y_radius = 12, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(Wave_IceWave_Left_Right, 3, 0)                            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae7a, .x_radius =  4, .y_radius = 16, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(Wave_IceWave_Left_Right, 4, 0)                            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae81, .x_radius =  4, .y_radius = 20, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(Wave_IceWave_Left_Right, 5, 0)                            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae7a, .x_radius =  4, .y_radius = 16, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(Wave_IceWave_Left_Right, 6, 0)                            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae73, .x_radius =  4, .y_radius = 12, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(Wave_IceWave_Left_Right, 7, 0)                            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae6c, .x_radius =  4, .y_radius = 12, .trail_frame =  7 };
    case PROJ_INSTR_DRAW(Wave_IceWave_Left_Right, 8, 0)                            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae65, .x_radius =  4, .y_radius = 12, .trail_frame =  8 };
    case PROJ_INSTR_DRAW(Wave_IceWave_Left_Right, 9, 0)                            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae88, .x_radius =  4, .y_radius = 12, .trail_frame =  9 };
    case PROJ_INSTR_DRAW(Wave_IceWave_Left_Right, 10, 0)                           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae8f, .x_radius =  4, .y_radius = 12, .trail_frame = 10 };
    case PROJ_INSTR_DRAW(Wave_IceWave_Left_Right, 11, 0)                           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae96, .x_radius =  4, .y_radius = 16, .trail_frame = 11 };
    case PROJ_INSTR_DRAW(Wave_IceWave_Left_Right, 12, 0)                           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae9d, .x_radius =  4, .y_radius = 20, .trail_frame = 12 };
    case PROJ_INSTR_DRAW(Wave_IceWave_Left_Right, 13, 0)                           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae96, .x_radius =  4, .y_radius = 16, .trail_frame = 13 };
    case PROJ_INSTR_DRAW(Wave_IceWave_Left_Right, 14, 0)                           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae8f, .x_radius =  4, .y_radius = 12, .trail_frame = 14 };
    case PROJ_INSTR_DRAW(Wave_IceWave_Left_Right, 15, 0)                           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae88, .x_radius =  4, .y_radius = 12, .trail_frame = 15 };
    case PROJ_INSTR_FUNC(Wave_IceWave_Left_Right, 16, 0)                           : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Wave_IceWave_Left_Right, 0, 0) };

    case PROJ_INSTR_DRAW(Wave_IceWave_DownRight_UpLeft, 0, 0)                      : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae65, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Wave_IceWave_DownRight_UpLeft, 1, 0)                      : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaea4, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Wave_IceWave_DownRight_UpLeft, 2, 0)                      : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaeab, .x_radius =  8, .y_radius =  8, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(Wave_IceWave_DownRight_UpLeft, 3, 0)                      : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaeb2, .x_radius = 10, .y_radius = 10, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(Wave_IceWave_DownRight_UpLeft, 4, 0)                      : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaeb9, .x_radius = 12, .y_radius = 12, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(Wave_IceWave_DownRight_UpLeft, 5, 0)                      : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaeb2, .x_radius = 10, .y_radius = 10, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(Wave_IceWave_DownRight_UpLeft, 6, 0)                      : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaeab, .x_radius =  8, .y_radius =  8, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(Wave_IceWave_DownRight_UpLeft, 7, 0)                      : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaea4, .x_radius =  6, .y_radius =  6, .trail_frame =  7 };
    case PROJ_INSTR_DRAW(Wave_IceWave_DownRight_UpLeft, 8, 0)                      : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae65, .x_radius =  4, .y_radius =  4, .trail_frame =  8 };
    case PROJ_INSTR_DRAW(Wave_IceWave_DownRight_UpLeft, 9, 0)                      : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaec0, .x_radius =  6, .y_radius =  6, .trail_frame =  9 };
    case PROJ_INSTR_DRAW(Wave_IceWave_DownRight_UpLeft, 10, 0)                     : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaec7, .x_radius =  8, .y_radius =  8, .trail_frame = 10 };
    case PROJ_INSTR_DRAW(Wave_IceWave_DownRight_UpLeft, 11, 0)                     : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaece, .x_radius = 10, .y_radius = 10, .trail_frame = 11 };
    case PROJ_INSTR_DRAW(Wave_IceWave_DownRight_UpLeft, 12, 0)                     : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaed5, .x_radius = 12, .y_radius = 12, .trail_frame = 12 };
    case PROJ_INSTR_DRAW(Wave_IceWave_DownRight_UpLeft, 13, 0)                     : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaece, .x_radius = 10, .y_radius = 10, .trail_frame = 13 };
    case PROJ_INSTR_DRAW(Wave_IceWave_DownRight_UpLeft, 14, 0)                     : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaec7, .x_radius =  8, .y_radius =  8, .trail_frame = 14 };
    case PROJ_INSTR_DRAW(Wave_IceWave_DownRight_UpLeft, 15, 0)                     : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaec0, .x_radius =  8, .y_radius =  8, .trail_frame = 15 };
    case PROJ_INSTR_FUNC(Wave_IceWave_DownRight_UpLeft, 16, 0)                     : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Wave_IceWave_DownRight_UpLeft, 0, 0) };

    case PROJ_INSTR_DRAW(Ice, 0, 0)                                                : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xedf6, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Ice, 1, 0)                                                : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xedfd, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Ice, 2, 0)                                                : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xee04, .x_radius =  8, .y_radius =  8, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(Ice, 3, 0)                                                : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xee0b, .x_radius =  8, .y_radius =  8, .trail_frame =  3 };
    case PROJ_INSTR_FUNC(Ice, 4, 0)                                                : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Ice, 0, 0) };

    case PROJ_INSTR_DRAW(Spazer_SpazerIce_Up, 0, 0)                                : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd796, .x_radius = 12, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Spazer_SpazerIce_Up, 1, 0)                                : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd7c2, .x_radius = 12, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Spazer_SpazerIce_Up, 2, 0)                                : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd822, .x_radius = 20, .y_radius =  8, .trail_frame =  2 };
    case PROJ_INSTR_FUNC(Spazer_SpazerIce_Up, 3, 0)                                : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Spazer_SpazerIce_Up, 2, 0) };

    case PROJ_INSTR_DRAW(Spazer_SpazerIce_UpRight, 0, 0)                           : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd10e, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Spazer_SpazerIce_UpRight, 1, 0)                           : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd124, .x_radius = 12, .y_radius = 12, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Spazer_SpazerIce_UpRight, 2, 0)                           : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd1de, .x_radius = 16, .y_radius = 16, .trail_frame =  2 };
    case PROJ_INSTR_FUNC(Spazer_SpazerIce_UpRight, 3, 0)                           : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Spazer_SpazerIce_UpRight, 2, 0) };

    case PROJ_INSTR_DRAW(Spazer_SpazerIce_Right, 0, 0)                             : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd842, .x_radius =  8, .y_radius = 12, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Spazer_SpazerIce_Right, 1, 0)                             : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd86e, .x_radius =  8, .y_radius = 12, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Spazer_SpazerIce_Right, 2, 0)                             : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd8ce, .x_radius =  8, .y_radius = 20, .trail_frame =  2 };
    case PROJ_INSTR_FUNC(Spazer_SpazerIce_Right, 3, 0)                             : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Spazer_SpazerIce_Right, 2, 0) };

    case PROJ_INSTR_DRAW(Spazer_SpazerIce_DownRight, 0, 0)                         : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd25a, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Spazer_SpazerIce_DownRight, 1, 0)                         : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd270, .x_radius = 12, .y_radius = 12, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Spazer_SpazerIce_DownRight, 2, 0)                         : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd32a, .x_radius = 16, .y_radius = 16, .trail_frame =  2 };
    case PROJ_INSTR_FUNC(Spazer_SpazerIce_DownRight, 3, 0)                         : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Spazer_SpazerIce_DownRight, 2, 0) };

    case PROJ_INSTR_DRAW(Spazer_SpazerIce_Down, 0, 0)                              : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd63e, .x_radius = 12, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Spazer_SpazerIce_Down, 1, 0)                              : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd66a, .x_radius = 12, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Spazer_SpazerIce_Down, 2, 0)                              : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd6ca, .x_radius = 20, .y_radius =  8, .trail_frame =  2 };
    case PROJ_INSTR_FUNC(Spazer_SpazerIce_Down, 3, 0)                              : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Spazer_SpazerIce_Down, 2, 0) };

    case PROJ_INSTR_DRAW(Spazer_SpazerIce_DownLeft, 0, 0)                          : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd3a6, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Spazer_SpazerIce_DownLeft, 1, 0)                          : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd3bc, .x_radius = 12, .y_radius = 12, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Spazer_SpazerIce_DownLeft, 2, 0)                          : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd476, .x_radius = 16, .y_radius = 16, .trail_frame =  2 };
    case PROJ_INSTR_FUNC(Spazer_SpazerIce_DownLeft, 3, 0)                          : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Spazer_SpazerIce_DownLeft, 2, 0) };

    case PROJ_INSTR_DRAW(Spazer_SpazerIce_Left, 0, 0)                              : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd6ea, .x_radius =  8, .y_radius = 12, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Spazer_SpazerIce_Left, 1, 0)                              : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd716, .x_radius =  8, .y_radius = 12, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Spazer_SpazerIce_Left, 2, 0)                              : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd776, .x_radius =  8, .y_radius = 20, .trail_frame =  2 };
    case PROJ_INSTR_FUNC(Spazer_SpazerIce_Left, 3, 0)                              : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Spazer_SpazerIce_Left, 2, 0) };

    case PROJ_INSTR_DRAW(Spazer_SpazerIce_UpLeft, 0, 0)                            : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd4f2, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Spazer_SpazerIce_UpLeft, 1, 0)                            : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd508, .x_radius = 12, .y_radius = 12, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Spazer_SpazerIce_UpLeft, 2, 0)                            : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd5c2, .x_radius = 16, .y_radius = 16, .trail_frame =  2 };
    case PROJ_INSTR_FUNC(Spazer_SpazerIce_UpLeft, 3, 0)                            : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Spazer_SpazerIce_UpLeft, 2, 0) };

    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Up, 0, 0)                        : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd796, .x_radius = 12, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Up, 1, 0)                        : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd7a2, .x_radius = 12, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Up, 2, 0)                        : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd7c2, .x_radius = 12, .y_radius =  8, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Up, 3, 0)                        : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd7e2, .x_radius = 17, .y_radius =  8, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Up, 4, 0)                        : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd802, .x_radius = 19, .y_radius =  8, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Up, 5, 0)                        : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd822, .x_radius = 20, .y_radius =  8, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Up, 6, 0)                        : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd802, .x_radius = 19, .y_radius =  8, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Up, 7, 0)                        : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd7e2, .x_radius = 17, .y_radius =  8, .trail_frame =  7 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Up, 8, 0)                        : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd7c2, .x_radius = 12, .y_radius =  8, .trail_frame =  8 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Up, 9, 0)                        : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd7a2, .x_radius = 12, .y_radius =  8, .trail_frame =  9 };
    case PROJ_INSTR_FUNC(SpazerWave_SpazerIceWave_Up, 10, 0)                       : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Up, 0, 0) };

    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_UpRight, 0, 0)                   : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd10e, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_UpRight, 1, 0)                   : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd21c, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_UpRight, 2, 0)                   : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd124, .x_radius = 12, .y_radius = 12, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_UpRight, 3, 0)                   : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd162, .x_radius = 16, .y_radius = 16, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_UpRight, 4, 0)                   : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd1a0, .x_radius = 16, .y_radius = 16, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_UpRight, 5, 0)                   : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd1de, .x_radius = 16, .y_radius = 16, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_UpRight, 6, 0)                   : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd1a0, .x_radius = 16, .y_radius = 16, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_UpRight, 7, 0)                   : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd162, .x_radius = 16, .y_radius = 16, .trail_frame =  7 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_UpRight, 8, 0)                   : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd124, .x_radius = 12, .y_radius = 12, .trail_frame =  8 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_UpRight, 9, 0)                   : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd21c, .x_radius =  8, .y_radius =  8, .trail_frame =  9 };
    case PROJ_INSTR_FUNC(SpazerWave_SpazerIceWave_UpRight, 10, 0)                  : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_UpRight, 0, 0) };

    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Right, 0, 0)                     : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd842, .x_radius =  8, .y_radius = 12, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Right, 1, 0)                     : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd84e, .x_radius =  8, .y_radius = 12, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Right, 2, 0)                     : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd86e, .x_radius =  8, .y_radius = 12, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Right, 3, 0)                     : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd88e, .x_radius =  8, .y_radius = 17, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Right, 4, 0)                     : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd8ae, .x_radius =  8, .y_radius = 19, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Right, 5, 0)                     : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd8ce, .x_radius =  8, .y_radius = 20, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Right, 6, 0)                     : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd8ae, .x_radius =  8, .y_radius = 19, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Right, 7, 0)                     : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd88e, .x_radius =  8, .y_radius = 17, .trail_frame =  7 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Right, 8, 0)                     : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd86e, .x_radius =  8, .y_radius = 12, .trail_frame =  8 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Right, 9, 0)                     : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd84e, .x_radius =  8, .y_radius = 12, .trail_frame =  9 };
    case PROJ_INSTR_FUNC(SpazerWave_SpazerIceWave_Right, 10, 0)                    : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Right, 0, 0) };

    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_DownRight, 0, 0)                 : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd25a, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_DownRight, 1, 0)                 : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd368, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_DownRight, 2, 0)                 : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd270, .x_radius = 12, .y_radius = 12, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_DownRight, 3, 0)                 : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd2ae, .x_radius = 16, .y_radius = 16, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_DownRight, 4, 0)                 : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd2ec, .x_radius = 16, .y_radius = 16, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_DownRight, 5, 0)                 : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd32a, .x_radius = 16, .y_radius = 16, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_DownRight, 6, 0)                 : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd2ec, .x_radius = 16, .y_radius = 16, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_DownRight, 7, 0)                 : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd2ae, .x_radius = 16, .y_radius = 16, .trail_frame =  7 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_DownRight, 8, 0)                 : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd270, .x_radius = 12, .y_radius = 12, .trail_frame =  8 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_DownRight, 9, 0)                 : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd368, .x_radius =  8, .y_radius =  8, .trail_frame =  9 };
    case PROJ_INSTR_FUNC(SpazerWave_SpazerIceWave_DownRight, 10, 0)                : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_DownRight, 0, 0) };

    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Down, 0, 0)                      : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd63e, .x_radius = 12, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Down, 1, 0)                      : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd64a, .x_radius = 12, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Down, 2, 0)                      : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd66a, .x_radius = 12, .y_radius =  8, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Down, 3, 0)                      : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd68a, .x_radius = 17, .y_radius =  8, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Down, 4, 0)                      : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd6aa, .x_radius = 19, .y_radius =  8, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Down, 5, 0)                      : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd6ca, .x_radius = 20, .y_radius =  8, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Down, 6, 0)                      : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd6aa, .x_radius = 19, .y_radius =  8, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Down, 7, 0)                      : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd68a, .x_radius = 17, .y_radius =  8, .trail_frame =  7 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Down, 8, 0)                      : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd66a, .x_radius = 12, .y_radius =  8, .trail_frame =  8 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Down, 9, 0)                      : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd64a, .x_radius = 12, .y_radius =  8, .trail_frame =  9 };
    case PROJ_INSTR_FUNC(SpazerWave_SpazerIceWave_Down, 10, 0)                     : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Down, 0, 0) };

    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_DownLeft, 0, 0)                  : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd3a6, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_DownLeft, 1, 0)                  : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd3bc, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_DownLeft, 2, 0)                  : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd3fa, .x_radius = 12, .y_radius = 12, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_DownLeft, 3, 0)                  : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd438, .x_radius = 16, .y_radius = 16, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_DownLeft, 4, 0)                  : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd476, .x_radius = 16, .y_radius = 16, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_DownLeft, 5, 0)                  : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd476, .x_radius = 16, .y_radius = 16, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_DownLeft, 6, 0)                  : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd476, .x_radius = 16, .y_radius = 16, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_DownLeft, 7, 0)                  : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd438, .x_radius = 16, .y_radius = 16, .trail_frame =  7 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_DownLeft, 8, 0)                  : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd3fa, .x_radius = 12, .y_radius = 12, .trail_frame =  8 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_DownLeft, 9, 0)                  : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd3bc, .x_radius =  8, .y_radius =  8, .trail_frame =  9 };
    case PROJ_INSTR_FUNC(SpazerWave_SpazerIceWave_DownLeft, 10, 0)                 : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_DownLeft, 0, 0) };

    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Left, 0, 0)                      : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd6ea, .x_radius =  8, .y_radius = 12, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Left, 1, 0)                      : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd6f6, .x_radius =  8, .y_radius = 12, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Left, 2, 0)                      : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd716, .x_radius =  8, .y_radius = 12, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Left, 3, 0)                      : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd736, .x_radius =  8, .y_radius = 17, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Left, 4, 0)                      : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd756, .x_radius =  8, .y_radius = 19, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Left, 5, 0)                      : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd776, .x_radius =  8, .y_radius = 20, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Left, 6, 0)                      : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd756, .x_radius =  8, .y_radius = 19, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Left, 7, 0)                      : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd736, .x_radius =  8, .y_radius = 17, .trail_frame =  7 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Left, 8, 0)                      : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd716, .x_radius =  8, .y_radius = 12, .trail_frame =  8 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Left, 9, 0)                      : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd6f6, .x_radius =  8, .y_radius = 12, .trail_frame =  9 };
    case PROJ_INSTR_FUNC(SpazerWave_SpazerIceWave_Left, 10, 0)                     : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_Left, 0, 0) };

    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_UpLeft, 0, 0)                    : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd4f2, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_UpLeft, 1, 0)                    : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd600, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_UpLeft, 2, 0)                    : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd508, .x_radius = 12, .y_radius = 12, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_UpLeft, 3, 0)                    : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd546, .x_radius = 16, .y_radius = 16, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_UpLeft, 4, 0)                    : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd584, .x_radius = 16, .y_radius = 16, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_UpLeft, 5, 0)                    : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd5c2, .x_radius = 16, .y_radius = 16, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_UpLeft, 6, 0)                    : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd584, .x_radius = 16, .y_radius = 16, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_UpLeft, 7, 0)                    : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd546, .x_radius = 16, .y_radius = 16, .trail_frame =  7 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_UpLeft, 8, 0)                    : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd508, .x_radius = 12, .y_radius = 12, .trail_frame =  8 };
    case PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_UpLeft, 9, 0)                    : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd600, .x_radius =  8, .y_radius =  8, .trail_frame =  9 };
    case PROJ_INSTR_FUNC(SpazerWave_SpazerIceWave_UpLeft, 10, 0)                   : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(SpazerWave_SpazerIceWave_UpLeft, 0, 0) };

    case PROJ_INSTR_DRAW(Plasma_PlasmaIce_Down_Up, 0, 0)                           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf194, .x_radius =  8, .y_radius = 16, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Plasma_PlasmaIce_Down_Up, 1, 0)                           : return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xa3b3, .x_radius =  8, .y_radius = 16, .trail_frame =  1 };
    case PROJ_INSTR_FUNC(Plasma_PlasmaIce_Down_Up, 2, 0)                           : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Plasma_PlasmaIce_Down_Up, 1, 0) };

    case PROJ_INSTR_DRAW(Plasma_PlasmaIce_DownLeft_UpRight, 0, 0)                  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf2ce, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Plasma_PlasmaIce_DownLeft_UpRight, 1, 0)                  : return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xa3c9, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_FUNC(Plasma_PlasmaIce_DownLeft_UpRight, 2, 0)                  : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Plasma_PlasmaIce_DownLeft_UpRight, 1, 0) };

    case PROJ_INSTR_DRAW(Plasma_PlasmaIce_Left_Right, 0, 0)                        : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf0fa, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Plasma_PlasmaIce_Left_Right, 1, 0)                        : return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xa37d, .x_radius = 16, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_FUNC(Plasma_PlasmaIce_Left_Right, 2, 0)                        : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Plasma_PlasmaIce_Left_Right, 1, 0) };

    case PROJ_INSTR_DRAW(Plasma_PlasmaIce_DownRight_UpLeft, 0, 0)                  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf22e, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Plasma_PlasmaIce_DownRight_UpLeft, 1, 0)                  : return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xa393, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_FUNC(Plasma_PlasmaIce_DownRight_UpLeft, 2, 0)                  : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Plasma_PlasmaIce_DownRight_UpLeft, 1, 0) };

    case PROJ_INSTR_DRAW(PlasmaIceWave_Down_Up, 0, 0)                              : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf194, .x_radius = 12, .y_radius = 16, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(PlasmaWave_Down_Up, 0, 0)                                 : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xc0f1, .x_radius = 12, .y_radius = 16, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(PlasmaWave_Down_Up, 1, 0)                                 : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xc107, .x_radius = 12, .y_radius = 16, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(PlasmaWave_Down_Up, 2, 0)                                 : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xc131, .x_radius = 17, .y_radius = 16, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(PlasmaWave_Down_Up, 3, 0)                                 : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xc15b, .x_radius = 19, .y_radius = 16, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(PlasmaWave_Down_Up, 4, 0)                                 : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xc185, .x_radius = 20, .y_radius = 16, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(PlasmaWave_Down_Up, 5, 0)                                 : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xc15b, .x_radius = 19, .y_radius = 16, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(PlasmaWave_Down_Up, 6, 0)                                 : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xc131, .x_radius = 17, .y_radius = 16, .trail_frame =  7 };
    case PROJ_INSTR_DRAW(PlasmaWave_Down_Up, 7, 0)                                 : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xc107, .x_radius = 12, .y_radius = 16, .trail_frame =  8 };
    case PROJ_INSTR_FUNC(PlasmaWave_Down_Up, 8, 0)                                 : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(PlasmaWave_Down_Up, 0, 0) };

    case PROJ_INSTR_DRAW(PlasmaIceWave_DownLeft_UpRight, 0, 0)                     : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf2ce, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(PlasmaWave_DownLeft_UpRight, 0, 0)                        : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xce2a, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(PlasmaWave_DownLeft_UpRight, 1, 0)                        : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xce4a, .x_radius = 12, .y_radius = 12, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(PlasmaWave_DownLeft_UpRight, 2, 0)                        : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xce88, .x_radius = 16, .y_radius = 16, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(PlasmaWave_DownLeft_UpRight, 3, 0)                        : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xcec6, .x_radius = 16, .y_radius = 16, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(PlasmaWave_DownLeft_UpRight, 4, 0)                        : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xcf04, .x_radius = 20, .y_radius = 20, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(PlasmaWave_DownLeft_UpRight, 5, 0)                        : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xcec6, .x_radius = 16, .y_radius = 16, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(PlasmaWave_DownLeft_UpRight, 6, 0)                        : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xce88, .x_radius = 16, .y_radius = 16, .trail_frame =  7 };
    case PROJ_INSTR_DRAW(PlasmaWave_DownLeft_UpRight, 7, 0)                        : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xce4a, .x_radius = 12, .y_radius = 12, .trail_frame =  8 };
    case PROJ_INSTR_FUNC(PlasmaWave_DownLeft_UpRight, 8, 0)                        : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(PlasmaWave_DownLeft_UpRight, 0, 0) };

    case PROJ_INSTR_DRAW(PlasmaWave_PlasmaIceWave_Left_Right, 0, 0)                : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf0fa, .x_radius =  8, .y_radius = 12, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(PlasmaWave_PlasmaIceWave_Left_Right, 1, 0)                : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xbc0a, .x_radius = 16, .y_radius = 12, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(PlasmaWave_PlasmaIceWave_Left_Right, 2, 0)                : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xbc20, .x_radius = 16, .y_radius = 12, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(PlasmaWave_PlasmaIceWave_Left_Right, 3, 0)                : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xbc4a, .x_radius = 16, .y_radius = 17, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(PlasmaWave_PlasmaIceWave_Left_Right, 4, 0)                : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xbc74, .x_radius = 16, .y_radius = 19, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(PlasmaWave_PlasmaIceWave_Left_Right, 5, 0)                : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xbc9e, .x_radius = 16, .y_radius = 20, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(PlasmaWave_PlasmaIceWave_Left_Right, 6, 0)                : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xbc74, .x_radius = 16, .y_radius = 19, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(PlasmaWave_PlasmaIceWave_Left_Right, 7, 0)                : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xbc4a, .x_radius = 16, .y_radius = 17, .trail_frame =  7 };
    case PROJ_INSTR_DRAW(PlasmaWave_PlasmaIceWave_Left_Right, 8, 0)                : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xbc20, .x_radius = 16, .y_radius = 12, .trail_frame =  8 };
    case PROJ_INSTR_FUNC(PlasmaWave_PlasmaIceWave_Left_Right, 9, 0)                : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(PlasmaWave_PlasmaIceWave_Left_Right, 1, 0) };

    case PROJ_INSTR_DRAW(PlasmaIceWave_DownRight_UpLeft, 0, 0)                     : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf22e, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(PlasmaWave_DownRight_UpLeft, 0, 0)                        : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xbe0d, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(PlasmaWave_DownRight_UpLeft, 1, 0)                        : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xbe2d, .x_radius = 12, .y_radius = 12, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(PlasmaWave_DownRight_UpLeft, 2, 0)                        : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xbe6b, .x_radius = 16, .y_radius = 16, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(PlasmaWave_DownRight_UpLeft, 3, 0)                        : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xbea9, .x_radius = 16, .y_radius = 16, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(PlasmaWave_DownRight_UpLeft, 4, 0)                        : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xbee7, .x_radius = 20, .y_radius = 20, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(PlasmaWave_DownRight_UpLeft, 5, 0)                        : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xbea9, .x_radius = 16, .y_radius = 16, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(PlasmaWave_DownRight_UpLeft, 6, 0)                        : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xbe6b, .x_radius = 16, .y_radius = 16, .trail_frame =  7 };
    case PROJ_INSTR_DRAW(PlasmaWave_DownRight_UpLeft, 7, 0)                        : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xbe2d, .x_radius = 12, .y_radius = 12, .trail_frame =  8 };
    case PROJ_INSTR_FUNC(PlasmaWave_DownRight_UpLeft, 8, 0)                        : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(PlasmaWave_DownRight_UpLeft, 0, 0) };

    case PROJ_INSTR_DRAW(Charged_Power_Up, 0, 0)                                   : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xec6a, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Charged_Power_Up, 1, 0)                                   : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xed1a, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_FUNC(Charged_Power_Up, 2, 0)                                   : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Charged_Power_Up, 0, 0) };

    case PROJ_INSTR_DRAW(Charged_Power_UpRight, 0, 0)                              : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xec80, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Charged_Power_UpRight, 1, 0)                              : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xed30, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_FUNC(Charged_Power_UpRight, 2, 0)                              : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Charged_Power_UpRight, 0, 0) };

    case PROJ_INSTR_DRAW(Charged_Power_Right, 0, 0)                                : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xec96, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Charged_Power_Right, 1, 0)                                : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xed46, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_FUNC(Charged_Power_Right, 2, 0)                                : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Charged_Power_Right, 0, 0) };

    case PROJ_INSTR_DRAW(Charged_Power_DownRight, 0, 0)                            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xecac, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Charged_Power_DownRight, 1, 0)                            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xed5c, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_FUNC(Charged_Power_DownRight, 2, 0)                            : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Charged_Power_DownRight, 0, 0) };

    case PROJ_INSTR_DRAW(Charged_Power_Down, 0, 0)                                 : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xecc2, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Charged_Power_Down, 1, 0)                                 : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xed72, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_FUNC(Charged_Power_Down, 2, 0)                                 : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Charged_Power_Down, 0, 0) };

    case PROJ_INSTR_DRAW(Charged_Power_DownLeft, 0, 0)                             : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xecd8, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Charged_Power_DownLeft, 1, 0)                             : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xed88, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_FUNC(Charged_Power_DownLeft, 2, 0)                             : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Charged_Power_DownLeft, 0, 0) };

    case PROJ_INSTR_DRAW(Charged_Power_Left, 0, 0)                                 : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xec3e, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Charged_Power_Left, 1, 0)                                 : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xecee, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_FUNC(Charged_Power_Left, 2, 0)                                 : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Charged_Power_Left, 0, 0) };

    case PROJ_INSTR_DRAW(Charged_Power_UpLeft, 0, 0)                               : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xec54, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Charged_Power_UpLeft, 1, 0)                               : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xed04, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_FUNC(Charged_Power_UpLeft, 2, 0)                               : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Charged_Power_UpLeft, 0, 0) };

    case PROJ_INSTR_DRAW(Charged_Wave_Up, 0, 0)                                    : return (ProjectileInstr){ .timer =  3, .spritemap_ptr = 0xa117, .x_radius = 12, .y_radius =  8, .trail_frame =  0 };

    case PROJ_INSTR_DRAW(Charged_Wave_Down, 0, 0)                                  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf4c, .x_radius = 12, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Charged_Wave_Down, 1, 0)                                  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf62, .x_radius = 12, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Charged_Wave_Down, 2, 0)                                  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb394, .x_radius = 16, .y_radius =  8, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(Charged_Wave_Down, 3, 0)                                  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb3be, .x_radius = 16, .y_radius =  8, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(Charged_Wave_Down, 4, 0)                                  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb3e8, .x_radius = 20, .y_radius =  8, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(Charged_Wave_Down, 5, 0)                                  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb412, .x_radius = 20, .y_radius =  8, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(Charged_Wave_Down, 6, 0)                                  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb43c, .x_radius = 23, .y_radius =  8, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(Charged_Wave_Down, 7, 0)                                  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb466, .x_radius = 23, .y_radius =  8, .trail_frame =  7 };
    case PROJ_INSTR_DRAW(Charged_Wave_Down, 8, 0)                                  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb490, .x_radius = 24, .y_radius =  8, .trail_frame =  8 };
    case PROJ_INSTR_DRAW(Charged_Wave_Down, 9, 0)                                  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb4ba, .x_radius = 24, .y_radius =  8, .trail_frame =  9 };
    case PROJ_INSTR_DRAW(Charged_Wave_Down, 10, 0)                                 : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb43c, .x_radius = 23, .y_radius =  8, .trail_frame = 10 };
    case PROJ_INSTR_DRAW(Charged_Wave_Down, 11, 0)                                 : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb466, .x_radius = 23, .y_radius =  8, .trail_frame = 11 };
    case PROJ_INSTR_DRAW(Charged_Wave_Down, 12, 0)                                 : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb3e8, .x_radius = 20, .y_radius =  8, .trail_frame = 12 };
    case PROJ_INSTR_DRAW(Charged_Wave_Down, 13, 0)                                 : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb412, .x_radius = 20, .y_radius =  8, .trail_frame = 13 };
    case PROJ_INSTR_DRAW(Charged_Wave_Down, 14, 0)                                 : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb3be, .x_radius = 16, .y_radius =  8, .trail_frame = 14 };
    case PROJ_INSTR_DRAW(Charged_Wave_Down, 15, 0)                                 : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb394, .x_radius = 16, .y_radius =  8, .trail_frame = 15 };
    case PROJ_INSTR_FUNC(Charged_Wave_Down, 16, 0)                                 : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Charged_Wave_Down, 0, 0) };

    case PROJ_INSTR_DRAW(Charged_Wave_DownLeft_UpRight, 0, 0)                      : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf4c, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Charged_Wave_DownLeft_UpRight, 1, 0)                      : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf62, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Charged_Wave_DownLeft_UpRight, 2, 0)                      : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb218, .x_radius = 12, .y_radius = 12, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(Charged_Wave_DownLeft_UpRight, 3, 0)                      : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb242, .x_radius = 12, .y_radius = 12, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(Charged_Wave_DownLeft_UpRight, 4, 0)                      : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb26c, .x_radius = 16, .y_radius = 16, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(Charged_Wave_DownLeft_UpRight, 5, 0)                      : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb296, .x_radius = 16, .y_radius = 16, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(Charged_Wave_DownLeft_UpRight, 6, 0)                      : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb2c0, .x_radius = 17, .y_radius = 17, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(Charged_Wave_DownLeft_UpRight, 7, 0)                      : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb2ea, .x_radius = 17, .y_radius = 17, .trail_frame =  7 };
    case PROJ_INSTR_DRAW(Charged_Wave_DownLeft_UpRight, 8, 0)                      : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb314, .x_radius = 18, .y_radius = 18, .trail_frame =  8 };
    case PROJ_INSTR_DRAW(Charged_Wave_DownLeft_UpRight, 9, 0)                      : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb33e, .x_radius = 18, .y_radius = 18, .trail_frame =  9 };
    case PROJ_INSTR_DRAW(Charged_Wave_DownLeft_UpRight, 10, 0)                     : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb2c0, .x_radius = 17, .y_radius = 17, .trail_frame = 10 };
    case PROJ_INSTR_DRAW(Charged_Wave_DownLeft_UpRight, 11, 0)                     : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb2ea, .x_radius = 17, .y_radius = 17, .trail_frame = 11 };
    case PROJ_INSTR_DRAW(Charged_Wave_DownLeft_UpRight, 12, 0)                     : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb26c, .x_radius = 16, .y_radius = 16, .trail_frame = 12 };
    case PROJ_INSTR_DRAW(Charged_Wave_DownLeft_UpRight, 13, 0)                     : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb296, .x_radius = 16, .y_radius = 16, .trail_frame = 13 };
    case PROJ_INSTR_DRAW(Charged_Wave_DownLeft_UpRight, 14, 0)                     : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb218, .x_radius = 12, .y_radius = 12, .trail_frame = 14 };
    case PROJ_INSTR_DRAW(Charged_Wave_DownLeft_UpRight, 15, 0)                     : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb242, .x_radius = 12, .y_radius = 12, .trail_frame = 15 };
    case PROJ_INSTR_FUNC(Charged_Wave_DownLeft_UpRight, 16, 0)                     : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Charged_Wave_DownLeft_UpRight, 0, 0) };

    case PROJ_INSTR_DRAW(Charged_Wave_Left_Right, 0, 0)                            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf4c, .x_radius =  8, .y_radius = 12, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Charged_Wave_Left_Right, 1, 0)                            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf62, .x_radius =  8, .y_radius = 12, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Charged_Wave_Left_Right, 2, 0)                            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf78, .x_radius =  8, .y_radius = 16, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(Charged_Wave_Left_Right, 3, 0)                            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xafa2, .x_radius =  8, .y_radius = 16, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(Charged_Wave_Left_Right, 4, 0)                            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xafcc, .x_radius =  8, .y_radius = 20, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(Charged_Wave_Left_Right, 5, 0)                            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaff6, .x_radius =  8, .y_radius = 20, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(Charged_Wave_Left_Right, 6, 0)                            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb020, .x_radius =  8, .y_radius = 23, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(Charged_Wave_Left_Right, 7, 0)                            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb04a, .x_radius =  8, .y_radius = 23, .trail_frame =  7 };
    case PROJ_INSTR_DRAW(Charged_Wave_Left_Right, 8, 0)                            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb074, .x_radius =  8, .y_radius = 24, .trail_frame =  8 };
    case PROJ_INSTR_DRAW(Charged_Wave_Left_Right, 9, 0)                            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb09e, .x_radius =  8, .y_radius = 24, .trail_frame =  9 };
    case PROJ_INSTR_DRAW(Charged_Wave_Left_Right, 10, 0)                           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb020, .x_radius =  8, .y_radius = 23, .trail_frame = 10 };
    case PROJ_INSTR_DRAW(Charged_Wave_Left_Right, 11, 0)                           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb04a, .x_radius =  8, .y_radius = 23, .trail_frame = 11 };
    case PROJ_INSTR_DRAW(Charged_Wave_Left_Right, 12, 0)                           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xafcc, .x_radius =  8, .y_radius = 20, .trail_frame = 12 };
    case PROJ_INSTR_DRAW(Charged_Wave_Left_Right, 13, 0)                           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaff6, .x_radius =  8, .y_radius = 20, .trail_frame = 13 };
    case PROJ_INSTR_DRAW(Charged_Wave_Left_Right, 14, 0)                           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xafa2, .x_radius =  8, .y_radius = 16, .trail_frame = 14 };
    case PROJ_INSTR_DRAW(Charged_Wave_Left_Right, 15, 0)                           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf78, .x_radius =  8, .y_radius = 16, .trail_frame = 15 };
    case PROJ_INSTR_FUNC(Charged_Wave_Left_Right, 16, 0)                           : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Charged_Wave_Left_Right, 0, 0) };

    case PROJ_INSTR_DRAW(Charged_Wave_DownRight_UpLeft, 0, 0)                      : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf4c, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Charged_Wave_DownRight_UpLeft, 1, 0)                      : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf62, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Charged_Wave_DownRight_UpLeft, 2, 0)                      : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb0c8, .x_radius = 12, .y_radius = 12, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(Charged_Wave_DownRight_UpLeft, 3, 0)                      : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb0f2, .x_radius = 12, .y_radius = 12, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(Charged_Wave_DownRight_UpLeft, 4, 0)                      : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb11c, .x_radius = 16, .y_radius = 16, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(Charged_Wave_DownRight_UpLeft, 5, 0)                      : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb146, .x_radius = 16, .y_radius = 16, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(Charged_Wave_DownRight_UpLeft, 6, 0)                      : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb170, .x_radius = 17, .y_radius = 17, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(Charged_Wave_DownRight_UpLeft, 7, 0)                      : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb19a, .x_radius = 17, .y_radius = 17, .trail_frame =  7 };
    case PROJ_INSTR_DRAW(Charged_Wave_DownRight_UpLeft, 8, 0)                      : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb1c4, .x_radius = 18, .y_radius = 18, .trail_frame =  8 };
    case PROJ_INSTR_DRAW(Charged_Wave_DownRight_UpLeft, 9, 0)                      : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb1ee, .x_radius = 18, .y_radius = 18, .trail_frame =  9 };
    case PROJ_INSTR_DRAW(Charged_Wave_DownRight_UpLeft, 10, 0)                     : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb170, .x_radius = 17, .y_radius = 17, .trail_frame = 10 };
    case PROJ_INSTR_DRAW(Charged_Wave_DownRight_UpLeft, 11, 0)                     : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb19a, .x_radius = 17, .y_radius = 17, .trail_frame = 11 };
    case PROJ_INSTR_DRAW(Charged_Wave_DownRight_UpLeft, 12, 0)                     : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb11c, .x_radius = 16, .y_radius = 16, .trail_frame = 12 };
    case PROJ_INSTR_DRAW(Charged_Wave_DownRight_UpLeft, 13, 0)                     : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb146, .x_radius = 16, .y_radius = 16, .trail_frame = 13 };
    case PROJ_INSTR_DRAW(Charged_Wave_DownRight_UpLeft, 14, 0)                     : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb0c8, .x_radius = 12, .y_radius = 12, .trail_frame = 14 };
    case PROJ_INSTR_DRAW(Charged_Wave_DownRight_UpLeft, 15, 0)                     : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb0f2, .x_radius = 12, .y_radius = 12, .trail_frame = 15 };
    case PROJ_INSTR_FUNC(Charged_Wave_DownRight_UpLeft, 16, 0)                     : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Charged_Wave_DownRight_UpLeft, 0, 0) };

    case PROJ_INSTR_DRAW(Charged_Ice, 0, 0)                                        : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xed9e, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Charged_Ice, 1, 0)                                        : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xedb4, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Charged_Ice, 2, 0)                                        : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xedca, .x_radius =  8, .y_radius =  8, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(Charged_Ice, 3, 0)                                        : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xede0, .x_radius =  8, .y_radius =  8, .trail_frame =  3 };
    case PROJ_INSTR_FUNC(Charged_Ice, 4, 0)                                        : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Charged_Ice, 0, 0) };

    case PROJ_INSTR_DRAW(Charged_IceWave_Up, 0, 0)                                 : return (ProjectileInstr){ .timer =  3, .spritemap_ptr = 0xa117, .x_radius = 12, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Charged_IceWave_Down, 0, 0)                               : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb672, .x_radius = 12, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Charged_IceWave_Down, 1, 0)                               : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb688, .x_radius = 12, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Charged_IceWave_Down, 2, 0)                               : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbaba, .x_radius = 16, .y_radius =  8, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(Charged_IceWave_Down, 3, 0)                               : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbae4, .x_radius = 16, .y_radius =  8, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(Charged_IceWave_Down, 4, 0)                               : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbb0e, .x_radius = 20, .y_radius =  8, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(Charged_IceWave_Down, 5, 0)                               : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbb38, .x_radius = 20, .y_radius =  8, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(Charged_IceWave_Down, 6, 0)                               : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbb62, .x_radius = 23, .y_radius =  8, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(Charged_IceWave_Down, 7, 0)                               : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbb8c, .x_radius = 23, .y_radius =  8, .trail_frame =  7 };
    case PROJ_INSTR_DRAW(Charged_IceWave_Down, 8, 0)                               : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbbb6, .x_radius = 24, .y_radius =  8, .trail_frame =  8 };
    case PROJ_INSTR_DRAW(Charged_IceWave_Down, 9, 0)                               : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbbe0, .x_radius = 24, .y_radius =  8, .trail_frame =  9 };
    case PROJ_INSTR_DRAW(Charged_IceWave_Down, 10, 0)                              : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbb62, .x_radius = 23, .y_radius =  8, .trail_frame = 10 };
    case PROJ_INSTR_DRAW(Charged_IceWave_Down, 11, 0)                              : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbb8c, .x_radius = 23, .y_radius =  8, .trail_frame = 11 };
    case PROJ_INSTR_DRAW(Charged_IceWave_Down, 12, 0)                              : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbb0e, .x_radius = 20, .y_radius =  8, .trail_frame = 12 };
    case PROJ_INSTR_DRAW(Charged_IceWave_Down, 13, 0)                              : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbb38, .x_radius = 20, .y_radius =  8, .trail_frame = 13 };
    case PROJ_INSTR_DRAW(Charged_IceWave_Down, 14, 0)                              : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbae4, .x_radius = 16, .y_radius =  8, .trail_frame = 14 };
    case PROJ_INSTR_DRAW(Charged_IceWave_Down, 15, 0)                              : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbaba, .x_radius = 16, .y_radius =  8, .trail_frame = 15 };
    case PROJ_INSTR_FUNC(Charged_IceWave_Down, 16, 0)                              : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Charged_IceWave_Down, 0, 0) };

    case PROJ_INSTR_DRAW(Charged_IceWave_DownLeft_UpRight, 0, 0)                   : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb672, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Charged_IceWave_DownLeft_UpRight, 1, 0)                   : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb688, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Charged_IceWave_DownLeft_UpRight, 2, 0)                   : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb93e, .x_radius = 12, .y_radius = 12, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(Charged_IceWave_DownLeft_UpRight, 3, 0)                   : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb968, .x_radius = 12, .y_radius = 12, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(Charged_IceWave_DownLeft_UpRight, 4, 0)                   : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb992, .x_radius = 16, .y_radius = 16, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(Charged_IceWave_DownLeft_UpRight, 5, 0)                   : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb9bc, .x_radius = 16, .y_radius = 16, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(Charged_IceWave_DownLeft_UpRight, 6, 0)                   : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb9e6, .x_radius = 17, .y_radius = 17, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(Charged_IceWave_DownLeft_UpRight, 7, 0)                   : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xba10, .x_radius = 17, .y_radius = 17, .trail_frame =  7 };
    case PROJ_INSTR_DRAW(Charged_IceWave_DownLeft_UpRight, 8, 0)                   : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xba3a, .x_radius = 18, .y_radius = 18, .trail_frame =  8 };
    case PROJ_INSTR_DRAW(Charged_IceWave_DownLeft_UpRight, 9, 0)                   : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xba64, .x_radius = 18, .y_radius = 18, .trail_frame =  9 };
    case PROJ_INSTR_DRAW(Charged_IceWave_DownLeft_UpRight, 10, 0)                  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb9e6, .x_radius = 17, .y_radius = 17, .trail_frame = 10 };
    case PROJ_INSTR_DRAW(Charged_IceWave_DownLeft_UpRight, 11, 0)                  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xba10, .x_radius = 17, .y_radius = 17, .trail_frame = 11 };
    case PROJ_INSTR_DRAW(Charged_IceWave_DownLeft_UpRight, 12, 0)                  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb992, .x_radius = 16, .y_radius = 16, .trail_frame = 12 };
    case PROJ_INSTR_DRAW(Charged_IceWave_DownLeft_UpRight, 13, 0)                  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb9bc, .x_radius = 16, .y_radius = 16, .trail_frame = 13 };
    case PROJ_INSTR_DRAW(Charged_IceWave_DownLeft_UpRight, 14, 0)                  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb93e, .x_radius = 12, .y_radius = 12, .trail_frame = 14 };
    case PROJ_INSTR_DRAW(Charged_IceWave_DownLeft_UpRight, 15, 0)                  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb968, .x_radius = 12, .y_radius = 12, .trail_frame = 15 };
    case PROJ_INSTR_FUNC(Charged_IceWave_DownLeft_UpRight, 16, 0)                  : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Charged_IceWave_DownLeft_UpRight, 0, 0) };

    case PROJ_INSTR_DRAW(Charged_IceWave_Left_Right, 0, 0)                         : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb672, .x_radius =  8, .y_radius = 12, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Charged_IceWave_Left_Right, 1, 0)                         : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb688, .x_radius =  8, .y_radius = 12, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Charged_IceWave_Left_Right, 2, 0)                         : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb69e, .x_radius =  8, .y_radius = 16, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(Charged_IceWave_Left_Right, 3, 0)                         : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb6c8, .x_radius =  8, .y_radius = 16, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(Charged_IceWave_Left_Right, 4, 0)                         : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb6f2, .x_radius =  8, .y_radius = 20, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(Charged_IceWave_Left_Right, 5, 0)                         : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb71c, .x_radius =  8, .y_radius = 20, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(Charged_IceWave_Left_Right, 6, 0)                         : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb746, .x_radius =  8, .y_radius = 23, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(Charged_IceWave_Left_Right, 7, 0)                         : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb770, .x_radius =  8, .y_radius = 23, .trail_frame =  7 };
    case PROJ_INSTR_DRAW(Charged_IceWave_Left_Right, 8, 0)                         : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb79a, .x_radius =  8, .y_radius = 24, .trail_frame =  8 };
    case PROJ_INSTR_DRAW(Charged_IceWave_Left_Right, 9, 0)                         : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb7c4, .x_radius =  8, .y_radius = 24, .trail_frame =  9 };
    case PROJ_INSTR_DRAW(Charged_IceWave_Left_Right, 10, 0)                        : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb746, .x_radius =  8, .y_radius = 23, .trail_frame = 10 };
    case PROJ_INSTR_DRAW(Charged_IceWave_Left_Right, 11, 0)                        : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb770, .x_radius =  8, .y_radius = 23, .trail_frame = 11 };
    case PROJ_INSTR_DRAW(Charged_IceWave_Left_Right, 12, 0)                        : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb6f2, .x_radius =  8, .y_radius = 20, .trail_frame = 12 };
    case PROJ_INSTR_DRAW(Charged_IceWave_Left_Right, 13, 0)                        : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb71c, .x_radius =  8, .y_radius = 20, .trail_frame = 13 };
    case PROJ_INSTR_DRAW(Charged_IceWave_Left_Right, 14, 0)                        : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb6c8, .x_radius =  8, .y_radius = 16, .trail_frame = 14 };
    case PROJ_INSTR_DRAW(Charged_IceWave_Left_Right, 15, 0)                        : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb69e, .x_radius =  8, .y_radius = 16, .trail_frame = 15 };
    case PROJ_INSTR_FUNC(Charged_IceWave_Left_Right, 16, 0)                        : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Charged_IceWave_Left_Right, 0, 0) };

    case PROJ_INSTR_DRAW(Charged_IceWave_DownRight_UpLeft, 0, 0)                   : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb672, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Charged_IceWave_DownRight_UpLeft, 1, 0)                   : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb688, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Charged_IceWave_DownRight_UpLeft, 2, 0)                   : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb7ee, .x_radius = 12, .y_radius = 12, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(Charged_IceWave_DownRight_UpLeft, 3, 0)                   : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb818, .x_radius = 12, .y_radius = 12, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(Charged_IceWave_DownRight_UpLeft, 4, 0)                   : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb842, .x_radius = 16, .y_radius = 16, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(Charged_IceWave_DownRight_UpLeft, 5, 0)                   : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb86c, .x_radius = 16, .y_radius = 16, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(Charged_IceWave_DownRight_UpLeft, 6, 0)                   : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb896, .x_radius = 17, .y_radius = 17, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(Charged_IceWave_DownRight_UpLeft, 7, 0)                   : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb8c0, .x_radius = 17, .y_radius = 17, .trail_frame =  7 };
    case PROJ_INSTR_DRAW(Charged_IceWave_DownRight_UpLeft, 8, 0)                   : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb8ea, .x_radius = 18, .y_radius = 18, .trail_frame =  8 };
    case PROJ_INSTR_DRAW(Charged_IceWave_DownRight_UpLeft, 9, 0)                   : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb914, .x_radius = 18, .y_radius = 18, .trail_frame =  9 };
    case PROJ_INSTR_DRAW(Charged_IceWave_DownRight_UpLeft, 10, 0)                  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb896, .x_radius = 17, .y_radius = 17, .trail_frame = 10 };
    case PROJ_INSTR_DRAW(Charged_IceWave_DownRight_UpLeft, 11, 0)                  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb8c0, .x_radius = 17, .y_radius = 17, .trail_frame = 11 };
    case PROJ_INSTR_DRAW(Charged_IceWave_DownRight_UpLeft, 12, 0)                  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb842, .x_radius = 16, .y_radius = 16, .trail_frame = 12 };
    case PROJ_INSTR_DRAW(Charged_IceWave_DownRight_UpLeft, 13, 0)                  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb86c, .x_radius = 16, .y_radius = 16, .trail_frame = 13 };
    case PROJ_INSTR_DRAW(Charged_IceWave_DownRight_UpLeft, 14, 0)                  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb7ee, .x_radius = 12, .y_radius = 12, .trail_frame = 14 };
    case PROJ_INSTR_DRAW(Charged_IceWave_DownRight_UpLeft, 15, 0)                  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb818, .x_radius = 12, .y_radius = 12, .trail_frame = 15 };
    case PROJ_INSTR_FUNC(Charged_IceWave_DownRight_UpLeft, 16, 0)                  : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Charged_IceWave_DownRight_UpLeft, 0, 0) };

    case PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_Down_Up, 0, 0)                   : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xee8e, .x_radius = 12, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_Down_Up, 1, 0)                   : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf07e, .x_radius = 12, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_Down_Up, 2, 0)                   : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xee95, .x_radius = 12, .y_radius =  8, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_Down_Up, 3, 0)                   : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf085, .x_radius = 12, .y_radius =  8, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_Down_Up, 4, 0)                   : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe9a6, .x_radius = 12, .y_radius = 16, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_Down_Up, 5, 0)                   : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xda3a, .x_radius = 12, .y_radius = 16, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_Down_Up, 6, 0)                   : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe9fa, .x_radius = 12, .y_radius = 16, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_Down_Up, 7, 0)                   : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xda8e, .x_radius = 12, .y_radius = 16, .trail_frame =  7 };
    case PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_Down_Up, 8, 0)                   : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xeab4, .x_radius = 20, .y_radius = 16, .trail_frame =  8 };
    case PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_Down_Up, 9, 0)                   : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdb48, .x_radius = 20, .y_radius = 16, .trail_frame =  9 };
    case PROJ_INSTR_FUNC(Charged_Spazer_SpazerIce_Down_Up, 10, 0)                  : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_Down_Up, 8, 0) };

    case PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_DownLeft_UpRight, 0, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xeec8, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_DownLeft_UpRight, 1, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf0b8, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_DownLeft_UpRight, 2, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xeed4, .x_radius =  8, .y_radius =  8, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_DownLeft_UpRight, 3, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf0c4, .x_radius =  8, .y_radius =  8, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_DownLeft_UpRight, 4, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdf5e, .x_radius = 12, .y_radius = 12, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_DownLeft_UpRight, 5, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdd72, .x_radius = 12, .y_radius = 12, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_DownLeft_UpRight, 6, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdf7e, .x_radius = 16, .y_radius = 16, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_DownLeft_UpRight, 7, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xddee, .x_radius = 16, .y_radius = 16, .trail_frame =  7 };
    case PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_DownLeft_UpRight, 8, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe092, .x_radius = 20, .y_radius = 20, .trail_frame =  8 };
    case PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_DownLeft_UpRight, 9, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdf02, .x_radius = 20, .y_radius = 20, .trail_frame =  9 };
    case PROJ_INSTR_FUNC(Charged_Spazer_SpazerIce_DownLeft_UpRight, 10, 0)         : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_DownLeft_UpRight, 8, 0) };

    case PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_Left_Right, 0, 0)                : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xef0a, .x_radius =  8, .y_radius = 12, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_Left_Right, 1, 0)                : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf002, .x_radius =  8, .y_radius = 12, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_Left_Right, 2, 0)                : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xef11, .x_radius =  8, .y_radius = 12, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_Left_Right, 3, 0)                : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf009, .x_radius =  8, .y_radius = 12, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_Left_Right, 4, 0)                : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe85a, .x_radius = 16, .y_radius = 12, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_Left_Right, 5, 0)                : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd8ee, .x_radius = 16, .y_radius = 12, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_Left_Right, 6, 0)                : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe8ae, .x_radius = 16, .y_radius = 12, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_Left_Right, 7, 0)                : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd942, .x_radius = 16, .y_radius = 12, .trail_frame =  7 };
    case PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_Left_Right, 8, 0)                : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe968, .x_radius = 16, .y_radius = 20, .trail_frame =  8 };
    case PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_Left_Right, 9, 0)                : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd9fc, .x_radius = 16, .y_radius = 20, .trail_frame =  9 };
    case PROJ_INSTR_FUNC(Charged_Spazer_SpazerIce_Left_Right, 10, 0)               : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_Left_Right, 8, 0) };

    case PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_DownRight_UpLeft, 0, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xef44, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_DownRight_UpLeft, 1, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf03c, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_DownRight_UpLeft, 2, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xef50, .x_radius =  8, .y_radius =  8, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_DownRight_UpLeft, 3, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf048, .x_radius =  8, .y_radius =  8, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_DownRight_UpLeft, 4, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe14a, .x_radius = 12, .y_radius = 12, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_DownRight_UpLeft, 5, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdb86, .x_radius = 12, .y_radius = 12, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_DownRight_UpLeft, 6, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe16a, .x_radius = 16, .y_radius = 16, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_DownRight_UpLeft, 7, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdc02, .x_radius = 16, .y_radius = 16, .trail_frame =  7 };
    case PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_DownRight_UpLeft, 8, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe27e, .x_radius = 20, .y_radius = 20, .trail_frame =  8 };
    case PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_DownRight_UpLeft, 9, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdd16, .x_radius = 20, .y_radius = 20, .trail_frame =  9 };
    case PROJ_INSTR_FUNC(Charged_Spazer_SpazerIce_DownRight_UpLeft, 10, 0)         : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Charged_Spazer_SpazerIce_DownRight_UpLeft, 8, 0) };

    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Up, 0, 0)                : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xee8e, .x_radius = 12, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Up, 1, 0)                : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf07e, .x_radius = 12, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Up, 2, 0)                : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xee95, .x_radius = 12, .y_radius =  8, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Up, 3, 0)                : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf085, .x_radius = 12, .y_radius =  8, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Up, 4, 0)                : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe9a6, .x_radius = 12, .y_radius = 16, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Up, 5, 0)                : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xda3a, .x_radius = 12, .y_radius = 16, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Up, 6, 0)                : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe9bc, .x_radius = 12, .y_radius = 16, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Up, 7, 0)                : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xda50, .x_radius = 12, .y_radius = 16, .trail_frame =  7 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Up, 8, 0)                : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe9fa, .x_radius = 12, .y_radius = 16, .trail_frame =  8 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Up, 9, 0)                : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xda8e, .x_radius = 12, .y_radius = 16, .trail_frame =  9 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Up, 10, 0)               : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xea38, .x_radius = 16, .y_radius = 16, .trail_frame = 10 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Up, 11, 0)               : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdacc, .x_radius = 16, .y_radius = 16, .trail_frame = 11 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Up, 12, 0)               : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xea76, .x_radius = 18, .y_radius = 16, .trail_frame = 12 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Up, 13, 0)               : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdb0a, .x_radius = 18, .y_radius = 16, .trail_frame = 13 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Up, 14, 0)               : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xeab4, .x_radius = 20, .y_radius = 16, .trail_frame = 14 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Up, 15, 0)               : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdb48, .x_radius = 20, .y_radius = 16, .trail_frame = 15 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Up, 16, 0)               : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xea76, .x_radius = 18, .y_radius = 16, .trail_frame = 16 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Up, 17, 0)               : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdb0a, .x_radius = 18, .y_radius = 16, .trail_frame = 17 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Up, 18, 0)               : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xea38, .x_radius = 16, .y_radius = 16, .trail_frame = 18 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Up, 19, 0)               : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdacc, .x_radius = 16, .y_radius = 16, .trail_frame = 19 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Up, 20, 0)               : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe9fa, .x_radius = 12, .y_radius = 16, .trail_frame = 20 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Up, 21, 0)               : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xda8e, .x_radius = 12, .y_radius = 16, .trail_frame = 21 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Up, 22, 0)               : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe9bc, .x_radius =  8, .y_radius = 16, .trail_frame = 22 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Up, 23, 0)               : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xda50, .x_radius =  8, .y_radius = 16, .trail_frame = 23 };
    case PROJ_INSTR_FUNC(Charged_SpazerWave_SpazerIceWave_Up, 24, 0)               : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Up, 4, 0) };

    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpRight, 0, 0)           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xeec8, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpRight, 1, 0)           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf0b8, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpRight, 2, 0)           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xeed4, .x_radius =  8, .y_radius =  8, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpRight, 3, 0)           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf0c4, .x_radius =  8, .y_radius =  8, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpRight, 4, 0)           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdf5e, .x_radius = 12, .y_radius = 12, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpRight, 5, 0)           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdd72, .x_radius = 12, .y_radius = 12, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpRight, 6, 0)           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe0ee, .x_radius = 12, .y_radius = 12, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpRight, 7, 0)           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdd92, .x_radius = 12, .y_radius = 12, .trail_frame =  7 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpRight, 8, 0)           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdf7e, .x_radius = 16, .y_radius = 16, .trail_frame =  8 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpRight, 9, 0)           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xddee, .x_radius = 16, .y_radius = 16, .trail_frame =  9 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpRight, 10, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdfda, .x_radius = 16, .y_radius = 16, .trail_frame = 10 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpRight, 11, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xde4a, .x_radius = 16, .y_radius = 16, .trail_frame = 11 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpRight, 12, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe036, .x_radius = 16, .y_radius = 16, .trail_frame = 12 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpRight, 13, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdea6, .x_radius = 16, .y_radius = 16, .trail_frame = 13 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpRight, 14, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe092, .x_radius = 20, .y_radius = 20, .trail_frame = 14 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpRight, 15, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdf02, .x_radius = 20, .y_radius = 20, .trail_frame = 15 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpRight, 16, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe036, .x_radius = 16, .y_radius = 16, .trail_frame = 16 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpRight, 17, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdea6, .x_radius = 16, .y_radius = 16, .trail_frame = 17 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpRight, 18, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdfda, .x_radius = 16, .y_radius = 16, .trail_frame = 18 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpRight, 19, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xde4a, .x_radius = 16, .y_radius = 16, .trail_frame = 19 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpRight, 20, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdf7e, .x_radius = 16, .y_radius = 16, .trail_frame = 20 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpRight, 21, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xddee, .x_radius = 16, .y_radius = 16, .trail_frame = 21 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpRight, 22, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe0ee, .x_radius = 12, .y_radius = 12, .trail_frame = 22 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpRight, 23, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdd92, .x_radius = 12, .y_radius = 12, .trail_frame = 23 };
    case PROJ_INSTR_FUNC(Charged_SpazerWave_SpazerIceWave_UpRight, 24, 0)          : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpRight, 4, 0) };

    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Right, 0, 0)             : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xef0a, .x_radius =  8, .y_radius = 12, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Right, 1, 0)             : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf002, .x_radius =  8, .y_radius = 12, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Right, 2, 0)             : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xef11, .x_radius =  8, .y_radius = 12, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Right, 3, 0)             : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf009, .x_radius =  8, .y_radius = 12, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Right, 4, 0)             : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xeaf2, .x_radius = 16, .y_radius = 12, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Right, 5, 0)             : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd8ee, .x_radius = 16, .y_radius = 12, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Right, 6, 0)             : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xeb08, .x_radius = 16, .y_radius = 12, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Right, 7, 0)             : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd904, .x_radius = 16, .y_radius = 12, .trail_frame =  7 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Right, 8, 0)             : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xeb46, .x_radius = 16, .y_radius = 12, .trail_frame =  8 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Right, 9, 0)             : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd942, .x_radius = 16, .y_radius = 12, .trail_frame =  9 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Right, 10, 0)            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xeb84, .x_radius = 16, .y_radius = 16, .trail_frame = 10 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Right, 11, 0)            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd980, .x_radius = 16, .y_radius = 16, .trail_frame = 11 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Right, 12, 0)            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xebc2, .x_radius = 16, .y_radius = 18, .trail_frame = 12 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Right, 13, 0)            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd9be, .x_radius = 16, .y_radius = 18, .trail_frame = 13 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Right, 14, 0)            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xec00, .x_radius = 16, .y_radius = 20, .trail_frame = 14 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Right, 15, 0)            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd9fc, .x_radius = 16, .y_radius = 20, .trail_frame = 15 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Right, 16, 0)            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xebc2, .x_radius = 16, .y_radius = 18, .trail_frame = 16 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Right, 17, 0)            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd9be, .x_radius = 16, .y_radius = 18, .trail_frame = 17 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Right, 18, 0)            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xeb84, .x_radius = 16, .y_radius = 16, .trail_frame = 18 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Right, 19, 0)            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd980, .x_radius = 16, .y_radius = 16, .trail_frame = 19 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Right, 20, 0)            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xeb46, .x_radius = 16, .y_radius = 12, .trail_frame = 20 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Right, 21, 0)            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd942, .x_radius = 16, .y_radius = 12, .trail_frame = 21 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Right, 22, 0)            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xeb08, .x_radius = 16, .y_radius =  8, .trail_frame = 22 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Right, 23, 0)            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd904, .x_radius = 16, .y_radius =  8, .trail_frame = 23 };
    case PROJ_INSTR_FUNC(Charged_SpazerWave_SpazerIceWave_Right, 24, 0)            : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Right, 4, 0) };

    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownRight, 0, 0)         : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xef44, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownRight, 1, 0)         : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf03c, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownRight, 2, 0)         : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xef50, .x_radius =  8, .y_radius =  8, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownRight, 3, 0)         : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf048, .x_radius =  8, .y_radius =  8, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownRight, 4, 0)         : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe14a, .x_radius = 12, .y_radius = 12, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownRight, 5, 0)         : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdb86, .x_radius = 12, .y_radius = 12, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownRight, 6, 0)         : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe2da, .x_radius = 12, .y_radius = 12, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownRight, 7, 0)         : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdba6, .x_radius = 12, .y_radius = 12, .trail_frame =  7 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownRight, 8, 0)         : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe16a, .x_radius = 16, .y_radius = 16, .trail_frame =  8 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownRight, 9, 0)         : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdc02, .x_radius = 16, .y_radius = 16, .trail_frame =  9 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownRight, 10, 0)        : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe1c6, .x_radius = 16, .y_radius = 16, .trail_frame = 10 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownRight, 11, 0)        : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdc5e, .x_radius = 16, .y_radius = 16, .trail_frame = 11 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownRight, 12, 0)        : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe222, .x_radius = 16, .y_radius = 16, .trail_frame = 12 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownRight, 13, 0)        : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdcba, .x_radius = 16, .y_radius = 16, .trail_frame = 13 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownRight, 14, 0)        : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe27e, .x_radius = 20, .y_radius = 20, .trail_frame = 14 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownRight, 15, 0)        : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdd16, .x_radius = 20, .y_radius = 20, .trail_frame = 15 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownRight, 16, 0)        : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe222, .x_radius = 16, .y_radius = 16, .trail_frame = 16 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownRight, 17, 0)        : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdcba, .x_radius = 16, .y_radius = 16, .trail_frame = 17 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownRight, 18, 0)        : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe1c6, .x_radius = 16, .y_radius = 16, .trail_frame = 18 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownRight, 19, 0)        : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdc5e, .x_radius = 16, .y_radius = 16, .trail_frame = 19 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownRight, 20, 0)        : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe16a, .x_radius = 16, .y_radius = 16, .trail_frame = 20 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownRight, 21, 0)        : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdc02, .x_radius = 16, .y_radius = 16, .trail_frame = 21 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownRight, 22, 0)        : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe2da, .x_radius = 12, .y_radius = 12, .trail_frame = 22 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownRight, 23, 0)        : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdba6, .x_radius = 12, .y_radius = 12, .trail_frame = 23 };
    case PROJ_INSTR_FUNC(Charged_SpazerWave_SpazerIceWave_DownRight, 24, 0)        : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownRight, 4, 0) };

    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Down, 0, 0)              : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xef86, .x_radius = 12, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Down, 1, 0)              : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf07e, .x_radius = 12, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Down, 2, 0)              : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xef8d, .x_radius = 12, .y_radius =  8, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Down, 3, 0)              : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf085, .x_radius = 12, .y_radius =  8, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Down, 4, 0)              : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe70e, .x_radius = 12, .y_radius = 16, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Down, 5, 0)              : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xda3a, .x_radius = 12, .y_radius = 16, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Down, 6, 0)              : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe724, .x_radius = 12, .y_radius = 16, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Down, 7, 0)              : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xda50, .x_radius = 12, .y_radius = 16, .trail_frame =  7 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Down, 8, 0)              : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe762, .x_radius = 12, .y_radius = 16, .trail_frame =  8 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Down, 9, 0)              : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xda8e, .x_radius = 12, .y_radius = 16, .trail_frame =  9 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Down, 10, 0)             : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe7a0, .x_radius = 16, .y_radius = 16, .trail_frame = 10 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Down, 11, 0)             : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdacc, .x_radius = 16, .y_radius = 16, .trail_frame = 11 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Down, 12, 0)             : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe7de, .x_radius = 18, .y_radius = 16, .trail_frame = 12 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Down, 13, 0)             : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdb0a, .x_radius = 18, .y_radius = 16, .trail_frame = 13 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Down, 14, 0)             : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe81c, .x_radius = 20, .y_radius = 16, .trail_frame = 14 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Down, 15, 0)             : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdb48, .x_radius = 20, .y_radius = 16, .trail_frame = 15 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Down, 16, 0)             : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe7de, .x_radius = 18, .y_radius = 16, .trail_frame = 16 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Down, 17, 0)             : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdb0a, .x_radius = 18, .y_radius = 16, .trail_frame = 17 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Down, 18, 0)             : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe7a0, .x_radius = 16, .y_radius = 16, .trail_frame = 18 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Down, 19, 0)             : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdacc, .x_radius = 16, .y_radius = 16, .trail_frame = 19 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Down, 20, 0)             : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe762, .x_radius = 12, .y_radius = 16, .trail_frame = 20 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Down, 21, 0)             : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xda8e, .x_radius = 12, .y_radius = 16, .trail_frame = 21 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Down, 22, 0)             : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe724, .x_radius =  8, .y_radius = 16, .trail_frame = 22 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Down, 23, 0)             : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xda50, .x_radius =  8, .y_radius = 16, .trail_frame = 23 };
    case PROJ_INSTR_FUNC(Charged_SpazerWave_SpazerIceWave_Down, 24, 0)             : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Down, 4, 0) };

    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownLeft, 0, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xeec8, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownLeft, 1, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf0b8, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownLeft, 2, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xeed4, .x_radius =  8, .y_radius =  8, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownLeft, 3, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf0c4, .x_radius =  8, .y_radius =  8, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownLeft, 4, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe336, .x_radius = 12, .y_radius = 12, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownLeft, 5, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdd72, .x_radius = 12, .y_radius = 12, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownLeft, 6, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe4c6, .x_radius = 12, .y_radius = 12, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownLeft, 7, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdd92, .x_radius = 12, .y_radius = 12, .trail_frame =  7 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownLeft, 8, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe356, .x_radius = 16, .y_radius = 16, .trail_frame =  8 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownLeft, 9, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xddee, .x_radius = 16, .y_radius = 16, .trail_frame =  9 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownLeft, 10, 0)         : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe3b2, .x_radius = 16, .y_radius = 16, .trail_frame = 10 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownLeft, 11, 0)         : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xde4a, .x_radius = 16, .y_radius = 16, .trail_frame = 11 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownLeft, 12, 0)         : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe40e, .x_radius = 16, .y_radius = 16, .trail_frame = 12 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownLeft, 13, 0)         : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdea6, .x_radius = 16, .y_radius = 16, .trail_frame = 13 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownLeft, 14, 0)         : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe46a, .x_radius = 20, .y_radius = 20, .trail_frame = 14 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownLeft, 15, 0)         : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdf02, .x_radius = 20, .y_radius = 20, .trail_frame = 15 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownLeft, 16, 0)         : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe40e, .x_radius = 16, .y_radius = 16, .trail_frame = 16 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownLeft, 17, 0)         : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdea6, .x_radius = 16, .y_radius = 16, .trail_frame = 17 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownLeft, 18, 0)         : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe3b2, .x_radius = 16, .y_radius = 16, .trail_frame = 18 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownLeft, 19, 0)         : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xde4a, .x_radius = 16, .y_radius = 16, .trail_frame = 19 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownLeft, 20, 0)         : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe356, .x_radius = 16, .y_radius = 16, .trail_frame = 20 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownLeft, 21, 0)         : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xddee, .x_radius = 16, .y_radius = 16, .trail_frame = 21 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownLeft, 22, 0)         : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe4c6, .x_radius = 12, .y_radius = 12, .trail_frame = 22 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownLeft, 23, 0)         : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdd92, .x_radius = 12, .y_radius = 12, .trail_frame = 23 };
    case PROJ_INSTR_FUNC(Charged_SpazerWave_SpazerIceWave_DownLeft, 24, 0)         : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_DownLeft, 4, 0) };

    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Left, 0, 0)              : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xee12, .x_radius =  8, .y_radius = 12, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Left, 1, 0)              : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf002, .x_radius =  8, .y_radius = 12, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Left, 2, 0)              : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xee19, .x_radius =  8, .y_radius = 12, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Left, 3, 0)              : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf009, .x_radius =  8, .y_radius = 12, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Left, 4, 0)              : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe85a, .x_radius = 16, .y_radius = 12, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Left, 5, 0)              : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd8ee, .x_radius = 16, .y_radius = 12, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Left, 6, 0)              : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe870, .x_radius = 16, .y_radius = 12, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Left, 7, 0)              : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd904, .x_radius = 16, .y_radius = 12, .trail_frame =  7 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Left, 8, 0)              : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe8ae, .x_radius = 16, .y_radius = 12, .trail_frame =  8 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Left, 9, 0)              : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd942, .x_radius = 16, .y_radius = 12, .trail_frame =  9 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Left, 10, 0)             : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe8ec, .x_radius = 16, .y_radius = 16, .trail_frame = 10 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Left, 11, 0)             : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd980, .x_radius = 16, .y_radius = 16, .trail_frame = 11 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Left, 12, 0)             : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe92a, .x_radius = 16, .y_radius = 18, .trail_frame = 12 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Left, 13, 0)             : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd9be, .x_radius = 16, .y_radius = 18, .trail_frame = 13 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Left, 14, 0)             : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe968, .x_radius = 16, .y_radius = 20, .trail_frame = 14 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Left, 15, 0)             : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd9fc, .x_radius = 16, .y_radius = 20, .trail_frame = 15 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Left, 16, 0)             : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe92a, .x_radius = 16, .y_radius = 18, .trail_frame = 16 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Left, 17, 0)             : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd9be, .x_radius = 16, .y_radius = 18, .trail_frame = 17 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Left, 18, 0)             : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe8ec, .x_radius = 16, .y_radius = 16, .trail_frame = 18 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Left, 19, 0)             : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd980, .x_radius = 16, .y_radius = 16, .trail_frame = 19 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Left, 20, 0)             : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe8ae, .x_radius = 16, .y_radius = 12, .trail_frame = 20 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Left, 21, 0)             : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd942, .x_radius = 16, .y_radius = 12, .trail_frame = 21 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Left, 22, 0)             : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe870, .x_radius = 16, .y_radius =  8, .trail_frame = 22 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Left, 23, 0)             : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd904, .x_radius = 16, .y_radius =  8, .trail_frame = 23 };
    case PROJ_INSTR_FUNC(Charged_SpazerWave_SpazerIceWave_Left, 24, 0)             : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_Left, 4, 0) };

    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpLeft, 0, 0)            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xee4c, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpLeft, 1, 0)            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf03c, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpLeft, 2, 0)            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xee58, .x_radius =  8, .y_radius =  8, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpLeft, 3, 0)            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf048, .x_radius =  8, .y_radius =  8, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpLeft, 4, 0)            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe522, .x_radius = 12, .y_radius = 12, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpLeft, 5, 0)            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdb86, .x_radius = 12, .y_radius = 12, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpLeft, 6, 0)            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe6b2, .x_radius = 12, .y_radius = 12, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpLeft, 7, 0)            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdba6, .x_radius = 12, .y_radius = 12, .trail_frame =  7 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpLeft, 8, 0)            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe542, .x_radius = 16, .y_radius = 16, .trail_frame =  8 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpLeft, 9, 0)            : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdc02, .x_radius = 16, .y_radius = 16, .trail_frame =  9 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpLeft, 10, 0)           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe59e, .x_radius = 16, .y_radius = 16, .trail_frame = 10 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpLeft, 11, 0)           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdc5e, .x_radius = 16, .y_radius = 16, .trail_frame = 11 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpLeft, 12, 0)           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe5fa, .x_radius = 16, .y_radius = 16, .trail_frame = 12 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpLeft, 13, 0)           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdcba, .x_radius = 16, .y_radius = 16, .trail_frame = 13 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpLeft, 14, 0)           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe656, .x_radius = 20, .y_radius = 20, .trail_frame = 14 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpLeft, 15, 0)           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdd16, .x_radius = 20, .y_radius = 20, .trail_frame = 15 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpLeft, 16, 0)           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe5fa, .x_radius = 16, .y_radius = 16, .trail_frame = 16 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpLeft, 17, 0)           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdcba, .x_radius = 16, .y_radius = 16, .trail_frame = 17 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpLeft, 18, 0)           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe59e, .x_radius = 16, .y_radius = 16, .trail_frame = 18 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpLeft, 19, 0)           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdc5e, .x_radius = 16, .y_radius = 16, .trail_frame = 19 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpLeft, 20, 0)           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe542, .x_radius = 16, .y_radius = 16, .trail_frame = 20 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpLeft, 21, 0)           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdc02, .x_radius = 16, .y_radius = 16, .trail_frame = 21 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpLeft, 22, 0)           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe6b2, .x_radius = 12, .y_radius = 12, .trail_frame = 22 };
    case PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpLeft, 23, 0)           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdba6, .x_radius = 12, .y_radius = 12, .trail_frame = 23 };
    case PROJ_INSTR_FUNC(Charged_SpazerWave_SpazerIceWave_UpLeft, 24, 0)           : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Charged_SpazerWave_SpazerIceWave_UpLeft, 4, 0) };

    case PROJ_INSTR_DRAW(Charged_Plasma_PlasmaIce_Down_Up, 0, 0)                   : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf194, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Charged_Plasma_PlasmaIce_Down_Up, 1, 0)                   : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf408, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Charged_Plasma_PlasmaIce_Down_Up, 2, 0)                   : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf1a7, .x_radius =  8, .y_radius = 16, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(Charged_Plasma_PlasmaIce_Down_Up, 3, 0)                   : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf41b, .x_radius =  8, .y_radius = 16, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(Charged_Plasma_PlasmaIce_Down_Up, 4, 0)                   : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf1e9, .x_radius =  8, .y_radius = 24, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(Charged_Plasma_PlasmaIce_Down_Up, 5, 0)                   : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf45d, .x_radius =  8, .y_radius = 24, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(Charged_Plasma_PlasmaIce_Down_Up, 6, 0)                   : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf209, .x_radius =  8, .y_radius = 28, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(Charged_Plasma_PlasmaIce_Down_Up, 7, 0)                   : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf47d, .x_radius =  8, .y_radius = 28, .trail_frame =  7 };
    case PROJ_INSTR_FUNC(Charged_Plasma_PlasmaIce_Down_Up, 8, 0)                   : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Charged_Plasma_PlasmaIce_Down_Up, 6, 0) };

    case PROJ_INSTR_DRAW(Charged_Plasma_PlasmaIce_DownLeft_UpRight, 0, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf2ce, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Charged_Plasma_PlasmaIce_DownLeft_UpRight, 1, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf542, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Charged_Plasma_PlasmaIce_DownLeft_UpRight, 2, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf2da, .x_radius = 12, .y_radius = 12, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(Charged_Plasma_PlasmaIce_DownLeft_UpRight, 3, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf54e, .x_radius = 12, .y_radius = 12, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(Charged_Plasma_PlasmaIce_DownLeft_UpRight, 4, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf310, .x_radius = 16, .y_radius = 16, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(Charged_Plasma_PlasmaIce_DownLeft_UpRight, 5, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf584, .x_radius = 16, .y_radius = 16, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(Charged_Plasma_PlasmaIce_DownLeft_UpRight, 6, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf33a, .x_radius = 20, .y_radius = 20, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(Charged_Plasma_PlasmaIce_DownLeft_UpRight, 7, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf5ae, .x_radius = 20, .y_radius = 20, .trail_frame =  7 };
    case PROJ_INSTR_FUNC(Charged_Plasma_PlasmaIce_DownLeft_UpRight, 8, 0)          : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Charged_Plasma_PlasmaIce_DownLeft_UpRight, 6, 0) };

    case PROJ_INSTR_DRAW(Charged_Plasma_PlasmaIce_Left_Right, 0, 0)                : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf0fa, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Charged_Plasma_PlasmaIce_Left_Right, 1, 0)                : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf36e, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Charged_Plasma_PlasmaIce_Left_Right, 2, 0)                : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf10d, .x_radius = 16, .y_radius =  8, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(Charged_Plasma_PlasmaIce_Left_Right, 3, 0)                : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf381, .x_radius = 16, .y_radius =  8, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(Charged_Plasma_PlasmaIce_Left_Right, 4, 0)                : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf14f, .x_radius = 24, .y_radius =  8, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(Charged_Plasma_PlasmaIce_Left_Right, 5, 0)                : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf3c3, .x_radius = 24, .y_radius =  8, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(Charged_Plasma_PlasmaIce_Left_Right, 6, 0)                : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf16f, .x_radius = 28, .y_radius =  8, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(Charged_Plasma_PlasmaIce_Left_Right, 7, 0)                : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf3e3, .x_radius = 28, .y_radius =  8, .trail_frame =  7 };
    case PROJ_INSTR_FUNC(Charged_Plasma_PlasmaIce_Left_Right, 8, 0)                : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Charged_Plasma_PlasmaIce_Left_Right, 6, 0) };

    case PROJ_INSTR_DRAW(Charged_Plasma_PlasmaIce_DownRight_UpLeft, 0, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf22e, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Charged_Plasma_PlasmaIce_DownRight_UpLeft, 1, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf4a2, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Charged_Plasma_PlasmaIce_DownRight_UpLeft, 2, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf23a, .x_radius = 12, .y_radius = 12, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(Charged_Plasma_PlasmaIce_DownRight_UpLeft, 3, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf4ae, .x_radius = 12, .y_radius = 12, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(Charged_Plasma_PlasmaIce_DownRight_UpLeft, 4, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf270, .x_radius = 16, .y_radius = 16, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(Charged_Plasma_PlasmaIce_DownRight_UpLeft, 5, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf4e4, .x_radius = 16, .y_radius = 16, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(Charged_Plasma_PlasmaIce_DownRight_UpLeft, 6, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf29a, .x_radius = 20, .y_radius = 20, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(Charged_Plasma_PlasmaIce_DownRight_UpLeft, 7, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf50e, .x_radius = 20, .y_radius = 20, .trail_frame =  7 };
    case PROJ_INSTR_FUNC(Charged_Plasma_PlasmaIce_DownRight_UpLeft, 8, 0)          : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Charged_Plasma_PlasmaIce_DownRight_UpLeft, 6, 0) };

    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Down_Up, 0, 0)           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf194, .x_radius = 12, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Down_Up, 1, 0)           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf408, .x_radius = 12, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Down_Up, 2, 0)           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf1a7, .x_radius = 12, .y_radius =  8, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Down_Up, 3, 0)           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf41b, .x_radius = 12, .y_radius =  8, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Down_Up, 4, 0)           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf1e9, .x_radius = 12, .y_radius = 24, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Down_Up, 5, 0)           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf45d, .x_radius = 12, .y_radius = 24, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Down_Up, 6, 0)           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc1af, .x_radius = 12, .y_radius = 30, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Down_Up, 7, 0)           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc94d, .x_radius = 12, .y_radius = 30, .trail_frame =  7 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Down_Up, 8, 0)           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc1d4, .x_radius = 12, .y_radius = 30, .trail_frame =  8 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Down_Up, 9, 0)           : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc972, .x_radius = 12, .y_radius = 30, .trail_frame =  9 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Down_Up, 10, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc21c, .x_radius = 17, .y_radius = 30, .trail_frame = 10 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Down_Up, 11, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc9ba, .x_radius = 17, .y_radius = 30, .trail_frame = 11 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Down_Up, 12, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc264, .x_radius = 19, .y_radius = 30, .trail_frame = 12 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Down_Up, 13, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xca02, .x_radius = 19, .y_radius = 30, .trail_frame = 13 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Down_Up, 14, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc2ac, .x_radius = 20, .y_radius = 30, .trail_frame = 14 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Down_Up, 15, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xca4a, .x_radius = 20, .y_radius = 30, .trail_frame = 15 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Down_Up, 16, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc264, .x_radius = 19, .y_radius = 30, .trail_frame = 16 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Down_Up, 17, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xca02, .x_radius = 19, .y_radius = 30, .trail_frame = 17 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Down_Up, 18, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc21c, .x_radius = 17, .y_radius = 30, .trail_frame = 18 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Down_Up, 19, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc9ba, .x_radius = 17, .y_radius = 30, .trail_frame = 19 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Down_Up, 20, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc1d4, .x_radius = 12, .y_radius = 30, .trail_frame = 20 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Down_Up, 21, 0)          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc972, .x_radius = 12, .y_radius = 30, .trail_frame = 21 };
    case PROJ_INSTR_FUNC(Charged_PlasmaWave_PlasmaIceWave_Down_Up, 22, 0)          : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Down_Up, 6, 0) };

    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownLeft_UpRight, 0, 0)  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf2ce, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownLeft_UpRight, 1, 0)  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf542, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownLeft_UpRight, 2, 0)  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf2da, .x_radius =  8, .y_radius =  8, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownLeft_UpRight, 3, 0)  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf54e, .x_radius =  8, .y_radius =  8, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownLeft_UpRight, 4, 0)  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf310, .x_radius = 12, .y_radius = 12, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownLeft_UpRight, 5, 0)  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf584, .x_radius = 12, .y_radius = 12, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownLeft_UpRight, 6, 0)  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xcf42, .x_radius = 12, .y_radius = 12, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownLeft_UpRight, 7, 0)  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xcc04, .x_radius = 12, .y_radius = 12, .trail_frame =  7 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownLeft_UpRight, 8, 0)  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xcf76, .x_radius = 16, .y_radius = 16, .trail_frame =  8 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownLeft_UpRight, 9, 0)  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xcc42, .x_radius = 16, .y_radius = 16, .trail_frame =  9 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownLeft_UpRight, 10, 0) : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xcfdc, .x_radius = 17, .y_radius = 17, .trail_frame = 10 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownLeft_UpRight, 11, 0) : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xccbc, .x_radius = 17, .y_radius = 17, .trail_frame = 11 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownLeft_UpRight, 12, 0) : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd042, .x_radius = 20, .y_radius = 20, .trail_frame = 12 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownLeft_UpRight, 13, 0) : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xcd36, .x_radius = 20, .y_radius = 20, .trail_frame = 13 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownLeft_UpRight, 14, 0) : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd0a8, .x_radius = 24, .y_radius = 24, .trail_frame = 14 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownLeft_UpRight, 15, 0) : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xcdb0, .x_radius = 24, .y_radius = 24, .trail_frame = 15 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownLeft_UpRight, 16, 0) : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd042, .x_radius = 20, .y_radius = 20, .trail_frame = 16 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownLeft_UpRight, 17, 0) : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xcd36, .x_radius = 20, .y_radius = 20, .trail_frame = 17 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownLeft_UpRight, 18, 0) : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xcfdc, .x_radius = 17, .y_radius = 17, .trail_frame = 18 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownLeft_UpRight, 19, 0) : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xccbc, .x_radius = 17, .y_radius = 17, .trail_frame = 19 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownLeft_UpRight, 20, 0) : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xcf76, .x_radius = 16, .y_radius = 16, .trail_frame = 20 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownLeft_UpRight, 21, 0) : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xcc42, .x_radius = 16, .y_radius = 16, .trail_frame = 21 };
    case PROJ_INSTR_FUNC(Charged_PlasmaWave_PlasmaIceWave_DownLeft_UpRight, 22, 0) : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownLeft_UpRight, 6, 0) };

    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Left_Right, 0, 0)        : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf0fa, .x_radius =  8, .y_radius = 12, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Left_Right, 1, 0)        : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf36e, .x_radius =  8, .y_radius = 12, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Left_Right, 2, 0)        : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf10d, .x_radius =  8, .y_radius = 12, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Left_Right, 3, 0)        : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf381, .x_radius =  8, .y_radius = 12, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Left_Right, 4, 0)        : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf14f, .x_radius = 24, .y_radius = 12, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Left_Right, 5, 0)        : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf3c3, .x_radius = 24, .y_radius = 12, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Left_Right, 6, 0)        : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbcc8, .x_radius = 28, .y_radius = 12, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Left_Right, 7, 0)        : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc3b2, .x_radius = 28, .y_radius = 12, .trail_frame =  7 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Left_Right, 8, 0)        : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbced, .x_radius = 28, .y_radius = 12, .trail_frame =  8 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Left_Right, 9, 0)        : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc3d7, .x_radius = 28, .y_radius = 12, .trail_frame =  9 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Left_Right, 10, 0)       : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbd35, .x_radius = 28, .y_radius = 17, .trail_frame = 10 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Left_Right, 11, 0)       : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc41f, .x_radius = 28, .y_radius = 17, .trail_frame = 11 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Left_Right, 12, 0)       : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbd7d, .x_radius = 28, .y_radius = 19, .trail_frame = 12 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Left_Right, 13, 0)       : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc467, .x_radius = 28, .y_radius = 19, .trail_frame = 13 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Left_Right, 14, 0)       : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbdc5, .x_radius = 28, .y_radius = 20, .trail_frame = 14 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Left_Right, 15, 0)       : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc4af, .x_radius = 28, .y_radius = 20, .trail_frame = 15 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Left_Right, 16, 0)       : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbd7d, .x_radius = 28, .y_radius = 19, .trail_frame = 16 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Left_Right, 17, 0)       : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc467, .x_radius = 28, .y_radius = 19, .trail_frame = 17 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Left_Right, 18, 0)       : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbd35, .x_radius = 28, .y_radius = 17, .trail_frame = 18 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Left_Right, 19, 0)       : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc41f, .x_radius = 28, .y_radius = 17, .trail_frame = 19 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Left_Right, 20, 0)       : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbced, .x_radius = 28, .y_radius = 12, .trail_frame = 20 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Left_Right, 21, 0)       : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc3d7, .x_radius = 28, .y_radius = 12, .trail_frame = 21 };
    case PROJ_INSTR_FUNC(Charged_PlasmaWave_PlasmaIceWave_Left_Right, 22, 0)       : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_Left_Right, 6, 0) };

    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownRight_UpLeft, 0, 0)  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf22e, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownRight_UpLeft, 1, 0)  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf4a2, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownRight_UpLeft, 2, 0)  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf23a, .x_radius =  8, .y_radius =  8, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownRight_UpLeft, 3, 0)  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf4ae, .x_radius =  8, .y_radius =  8, .trail_frame =  3 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownRight_UpLeft, 4, 0)  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf270, .x_radius = 12, .y_radius = 12, .trail_frame =  4 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownRight_UpLeft, 5, 0)  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf4e4, .x_radius = 12, .y_radius = 12, .trail_frame =  5 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownRight_UpLeft, 6, 0)  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbf25, .x_radius = 12, .y_radius = 12, .trail_frame =  6 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownRight_UpLeft, 7, 0)  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc669, .x_radius = 12, .y_radius = 12, .trail_frame =  7 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownRight_UpLeft, 8, 0)  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbf59, .x_radius = 16, .y_radius = 16, .trail_frame =  8 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownRight_UpLeft, 9, 0)  : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc6a7, .x_radius = 16, .y_radius = 16, .trail_frame =  9 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownRight_UpLeft, 10, 0) : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbfbf, .x_radius = 17, .y_radius = 17, .trail_frame = 10 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownRight_UpLeft, 11, 0) : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc721, .x_radius = 17, .y_radius = 17, .trail_frame = 11 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownRight_UpLeft, 12, 0) : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc025, .x_radius = 20, .y_radius = 20, .trail_frame = 12 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownRight_UpLeft, 13, 0) : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc79b, .x_radius = 20, .y_radius = 20, .trail_frame = 13 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownRight_UpLeft, 14, 0) : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc08b, .x_radius = 24, .y_radius = 24, .trail_frame = 14 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownRight_UpLeft, 15, 0) : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc815, .x_radius = 24, .y_radius = 24, .trail_frame = 15 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownRight_UpLeft, 16, 0) : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc025, .x_radius = 20, .y_radius = 20, .trail_frame = 16 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownRight_UpLeft, 17, 0) : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc79b, .x_radius = 20, .y_radius = 20, .trail_frame = 17 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownRight_UpLeft, 18, 0) : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbfbf, .x_radius = 17, .y_radius = 17, .trail_frame = 18 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownRight_UpLeft, 19, 0) : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc721, .x_radius = 17, .y_radius = 17, .trail_frame = 19 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownRight_UpLeft, 20, 0) : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbf59, .x_radius = 16, .y_radius = 16, .trail_frame = 20 };
    case PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownRight_UpLeft, 21, 0) : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc6a7, .x_radius = 16, .y_radius = 16, .trail_frame = 21 };
    case PROJ_INSTR_FUNC(Charged_PlasmaWave_PlasmaIceWave_DownRight_UpLeft, 22, 0) : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Charged_PlasmaWave_PlasmaIceWave_DownRight_UpLeft, 6, 0) };

    case PROJ_INSTR_DRAW(Missiles_Up, 0, 0)                                        : return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xad7e, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case PROJ_INSTR_FUNC(Missiles_Up, 1, 0)                                        : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Missiles_Up, 0, 0) };

    case PROJ_INSTR_DRAW(Missiles_UpRight, 0, 0)                                   : return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xad8a, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case PROJ_INSTR_FUNC(Missiles_UpRight, 1, 0)                                   : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Missiles_UpRight, 0, 0) };

    case PROJ_INSTR_DRAW(Missiles_Right, 0, 0)                                     : return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xad9b, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case PROJ_INSTR_FUNC(Missiles_Right, 1, 0)                                     : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Missiles_Right, 0, 0) };

    case PROJ_INSTR_DRAW(Missiles_DownRight, 0, 0)                                 : return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xada7, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case PROJ_INSTR_FUNC(Missiles_DownRight, 1, 0)                                 : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Missiles_DownRight, 0, 0) };

    case PROJ_INSTR_DRAW(Missiles_Down, 0, 0)                                      : return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xadb8, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case PROJ_INSTR_FUNC(Missiles_Down, 1, 0)                                      : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Missiles_Down, 0, 0) };

    case PROJ_INSTR_DRAW(Missiles_DownLeft, 0, 0)                                  : return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xadc4, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case PROJ_INSTR_FUNC(Missiles_DownLeft, 1, 0)                                  : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Missiles_DownLeft, 0, 0) };

    case PROJ_INSTR_DRAW(Missiles_Left, 0, 0)                                      : return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xad61, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case PROJ_INSTR_FUNC(Missiles_Left, 1, 0)                                      : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Missiles_Left, 0, 0) };

    case PROJ_INSTR_DRAW(Missiles_UpLeft, 0, 0)                                    : return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xad6d, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case PROJ_INSTR_FUNC(Missiles_UpLeft, 1, 0)                                    : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Missiles_UpLeft, 0, 0) };

    case PROJ_INSTR_DRAW(SuperMissile_Up, 0, 0)                                    : return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xadf2, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_FUNC(SuperMissile_Up, 1, 0)                                    : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(SuperMissile_Up, 0, 0) };

    case PROJ_INSTR_DRAW(SuperMissile_UpRight, 0, 0)                               : return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xadfe, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_FUNC(SuperMissile_UpRight, 1, 0)                               : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(SuperMissile_UpRight, 0, 0) };

    case PROJ_INSTR_DRAW(SuperMissile_Right, 0, 0)                                 : return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xae0f, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_FUNC(SuperMissile_Right, 1, 0)                                 : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(SuperMissile_Right, 0, 0) };

    case PROJ_INSTR_DRAW(SuperMissile_DownRight, 0, 0)                             : return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xae1b, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_FUNC(SuperMissile_DownRight, 1, 0)                             : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(SuperMissile_DownRight, 0, 0) };

    case PROJ_INSTR_DRAW(SuperMissile_Down, 0, 0)                                  : return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xae2c, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_FUNC(SuperMissile_Down, 1, 0)                                  : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(SuperMissile_Down, 0, 0) };

    case PROJ_INSTR_DRAW(SuperMissile_DownLeft, 0, 0)                              : return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xae38, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_FUNC(SuperMissile_DownLeft, 1, 0)                              : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(SuperMissile_DownLeft, 0, 0) };

    case PROJ_INSTR_DRAW(SuperMissile_Left, 0, 0)                                  : return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xadd5, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_FUNC(SuperMissile_Left, 1, 0)                                  : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(SuperMissile_Left, 0, 0) };

    case PROJ_INSTR_DRAW(SuperMissile_UpLeft, 0, 0)                                : return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xade1, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_FUNC(SuperMissile_UpLeft, 1, 0)                                : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(SuperMissile_UpLeft, 0, 0) };

    case PROJ_INSTR_DRAW(SuperMissile_Link, 0, 0)                                  : return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xa117, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_FUNC(SuperMissile_Link, 1, 0)                                  : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(SuperMissile_Link, 0, 0) };

    case PROJ_INSTR_DRAW(PowerBomb, 0, 0)                                          : return (ProjectileInstr){ .timer =  5, .spritemap_ptr = 0xab97, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(PowerBomb, 1, 0)                                          : return (ProjectileInstr){ .timer =  5, .spritemap_ptr = 0xab9e, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(PowerBomb, 2, 0)                                          : return (ProjectileInstr){ .timer =  5, .spritemap_ptr = 0xaba5, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case PROJ_INSTR_FUNC(PowerBomb, 3, 0)                                          : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(PowerBomb, 0, 0) };

    case PROJ_INSTR_DRAW(PowerBomb, 3, 1)                                          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xab97, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(PowerBomb, 4, 1)                                          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xab9e, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(PowerBomb, 5, 1)                                          : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaba5, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case PROJ_INSTR_FUNC(PowerBomb, 6, 1)                                          : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(PowerBomb, 3, 1) };

    case PROJ_INSTR_DRAW(Bomb, 0, 0)                                               : return (ProjectileInstr){ .timer =  5, .spritemap_ptr = 0xad45, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Bomb, 1, 0)                                               : return (ProjectileInstr){ .timer =  5, .spritemap_ptr = 0xad4c, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Bomb, 2, 0)                                               : return (ProjectileInstr){ .timer =  5, .spritemap_ptr = 0xad53, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Bomb, 3, 0)                                               : return (ProjectileInstr){ .timer =  5, .spritemap_ptr = 0xad5a, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case PROJ_INSTR_FUNC(Bomb, 4, 0)                                               : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Bomb, 0, 0) };

    case PROJ_INSTR_DRAW(Bomb, 4, 1)                                               : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xad45, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Bomb, 5, 1)                                               : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xad4c, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Bomb, 6, 1)                                               : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xad53, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Bomb, 7, 1)                                               : return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xad5a, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case PROJ_INSTR_FUNC(Bomb, 8, 1)                                               : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Bomb, 4, 1) };

    case PROJ_INSTR_DRAW(BeamExplosion, 0, 0)                                      : return (ProjectileInstr){ .timer =  3, .spritemap_ptr = 0xabb3, .x_radius =  0, .y_radius =  0, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(BeamExplosion, 1, 0)                                      : return (ProjectileInstr){ .timer =  3, .spritemap_ptr = 0xabba, .x_radius =  0, .y_radius =  0, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(BeamExplosion, 2, 0)                                      : return (ProjectileInstr){ .timer =  3, .spritemap_ptr = 0xabc1, .x_radius =  0, .y_radius =  0, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(BeamExplosion, 3, 0)                                      : return (ProjectileInstr){ .timer =  3, .spritemap_ptr = 0xabd7, .x_radius =  0, .y_radius =  0, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(BeamExplosion, 4, 0)                                      : return (ProjectileInstr){ .timer =  3, .spritemap_ptr = 0xabed, .x_radius =  0, .y_radius =  0, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(BeamExplosion, 5, 0)                                      : return (ProjectileInstr){ .timer =  3, .spritemap_ptr = 0xac03, .x_radius =  0, .y_radius =  0, .trail_frame =  0 };
    case PROJ_INSTR_FUNC(BeamExplosion, 6, 0)                                      : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Delete) };

    case PROJ_INSTR_DRAW(MissileExplosion, 0, 0)                                   : return (ProjectileInstr){ .timer =  3, .spritemap_ptr = 0xa7c9, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(MissileExplosion, 1, 0)                                   : return (ProjectileInstr){ .timer =  3, .spritemap_ptr = 0xa7d0, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(MissileExplosion, 2, 0)                                   : return (ProjectileInstr){ .timer =  3, .spritemap_ptr = 0xa7e6, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(MissileExplosion, 3, 0)                                   : return (ProjectileInstr){ .timer =  3, .spritemap_ptr = 0xa7fc, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(MissileExplosion, 4, 0)                                   : return (ProjectileInstr){ .timer =  3, .spritemap_ptr = 0xa812, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(MissileExplosion, 5, 0)                                   : return (ProjectileInstr){ .timer =  3, .spritemap_ptr = 0xa828, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_FUNC(MissileExplosion, 6, 0)                                   : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Delete) };

    case PROJ_INSTR_DRAW(BombExplosion, 0, 0)                                      : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa83e, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(BombExplosion, 1, 0)                                      : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa854, .x_radius = 12, .y_radius = 12, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(BombExplosion, 2, 0)                                      : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa86a, .x_radius = 16, .y_radius = 16, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(BombExplosion, 3, 0)                                      : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa880, .x_radius = 16, .y_radius = 16, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(BombExplosion, 4, 0)                                      : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa896, .x_radius = 16, .y_radius = 16, .trail_frame =  0 };
    case PROJ_INSTR_FUNC(BombExplosion, 5, 0)                                      : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Delete) };

    case PROJ_INSTR_DRAW(PlasmaSBA, 0, 0)                                          : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa83e, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(PlasmaSBA, 1, 0)                                          : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa854, .x_radius = 12, .y_radius = 12, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(PlasmaSBA, 2, 0)                                          : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa86a, .x_radius = 16, .y_radius = 16, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(PlasmaSBA, 3, 0)                                          : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa880, .x_radius = 16, .y_radius = 16, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(PlasmaSBA, 4, 0)                                          : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa896, .x_radius = 16, .y_radius = 16, .trail_frame =  0 };
    case PROJ_INSTR_FUNC(PlasmaSBA, 5, 0)                                          : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(PlasmaSBA, 0, 0) };

    case PROJ_INSTR_DRAW(SuperMissileExplosion, 0, 0)                              : return (ProjectileInstr){ .timer =  5, .spritemap_ptr = 0xaa84, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(SuperMissileExplosion, 1, 0)                              : return (ProjectileInstr){ .timer =  5, .spritemap_ptr = 0xaa9a, .x_radius = 12, .y_radius = 12, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(SuperMissileExplosion, 2, 0)                              : return (ProjectileInstr){ .timer =  5, .spritemap_ptr = 0xaab0, .x_radius = 16, .y_radius = 16, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(SuperMissileExplosion, 3, 0)                              : return (ProjectileInstr){ .timer =  5, .spritemap_ptr = 0xaac6, .x_radius = 16, .y_radius = 16, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(SuperMissileExplosion, 4, 0)                              : return (ProjectileInstr){ .timer =  5, .spritemap_ptr = 0xab04, .x_radius = 16, .y_radius = 16, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(SuperMissileExplosion, 5, 0)                              : return (ProjectileInstr){ .timer =  5, .spritemap_ptr = 0xab2e, .x_radius = 16, .y_radius = 16, .trail_frame =  0 };
    case PROJ_INSTR_FUNC(SuperMissileExplosion, 6, 0)                              : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Delete) };

    case PROJ_INSTR_DRAW(UnusedProjectile_25h, 0, 0)                               : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa117, .x_radius = 16, .y_radius = 32, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(UnusedProjectile_25h, 1, 0)                               : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa117, .x_radius = 16, .y_radius = 32, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(UnusedProjectile_25h, 2, 0)                               : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa117, .x_radius = 16, .y_radius = 32, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(UnusedProjectile_25h, 3, 0)                               : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa117, .x_radius = 16, .y_radius = 32, .trail_frame =  3 };
    case PROJ_INSTR_FUNC(UnusedProjectile_25h, 4, 0)                               : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(UnusedProjectile_25h, 0, 0) };

    case PROJ_INSTR_DRAW(ShinesparkEchoes, 0, 0)                                   : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa117, .x_radius = 32, .y_radius = 32, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(ShinesparkEchoes, 1, 0)                                   : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa117, .x_radius = 32, .y_radius = 32, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(ShinesparkEchoes, 2, 0)                                   : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa117, .x_radius = 32, .y_radius = 32, .trail_frame =  2 };
    case PROJ_INSTR_DRAW(ShinesparkEchoes, 3, 0)                                   : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa117, .x_radius = 32, .y_radius = 32, .trail_frame =  3 };
    case PROJ_INSTR_FUNC(ShinesparkEchoes, 4, 0)                                   : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(ShinesparkEchoes, 0, 0) };

    case PROJ_INSTR_DRAW(Spazer_SBA_Trail, 0, 0)                                   : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa117, .x_radius =  4, .y_radius =  8, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Spazer_SBA_Trail, 1, 0)                                   : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa117, .x_radius = 12, .y_radius =  8, .trail_frame =  1 };
    case PROJ_INSTR_DRAW(Spazer_SBA_Trail, 2, 0)                                   : return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa117, .x_radius = 20, .y_radius =  8, .trail_frame =  2 };
    case PROJ_INSTR_FUNC(Spazer_SBA_Trail, 3, 0)                                   : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Spazer_SBA_Trail, 2, 0) };

    case PROJ_INSTR_DRAW(Wave_SBA, 0, 0)                                           : return (ProjectileInstr){ .timer =  8, .spritemap_ptr = 0xaf4c, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(Wave_SBA, 1, 0)                                           : return (ProjectileInstr){ .timer =  8, .spritemap_ptr = 0xaf62, .x_radius =  4, .y_radius =  4, .trail_frame =  1 };
    case PROJ_INSTR_FUNC(Wave_SBA, 2, 0)                                           : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(Wave_SBA, 0, 0) };

    case PROJ_INSTR_DRAW(UnusedShinesparkBeam_Projectile_27h, 0, 0)                : return (ProjectileInstr){ .timer =  3, .spritemap_ptr = 0xabb3, .x_radius =  0, .y_radius =  0, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(UnusedShinesparkBeam_Projectile_27h, 1, 0)                : return (ProjectileInstr){ .timer =  3, .spritemap_ptr = 0xabba, .x_radius =  0, .y_radius =  0, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(UnusedShinesparkBeam_Projectile_27h, 2, 0)                : return (ProjectileInstr){ .timer =  3, .spritemap_ptr = 0xabc1, .x_radius =  0, .y_radius =  0, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(UnusedShinesparkBeam_Projectile_27h, 3, 0)                : return (ProjectileInstr){ .timer =  3, .spritemap_ptr = 0xabd7, .x_radius =  0, .y_radius =  0, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(UnusedShinesparkBeam_Projectile_27h, 4, 0)                : return (ProjectileInstr){ .timer =  3, .spritemap_ptr = 0xabed, .x_radius =  0, .y_radius =  0, .trail_frame =  0 };
    case PROJ_INSTR_DRAW(UnusedShinesparkBeam_Projectile_27h, 5, 0)                : return (ProjectileInstr){ .timer =  3, .spritemap_ptr = 0xac03, .x_radius =  0, .y_radius =  0, .trail_frame =  0 };
    case PROJ_INSTR_FUNC(UnusedShinesparkBeam_Projectile_27h, 6, 0)                : return (ProjectileInstr){ .func_ptr = FUNC16(ProjInstr_Goto), .instr_list_ptr = PROJ_INSTR_DRAW(UnusedShinesparkBeam_Projectile_27h, 0, 0) };

    default: return (ProjectileInstr){ Unreachable() };
  }
}


