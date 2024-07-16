#pragma once

#include "ida_types.h"
#include "types.h"

#define BLK_HORIZ_FLIP 0x400
#define BLK_VERT_FLIP 0x800
#define BLK_HAS_FLIP (BLK_HORIZ_FLIP | BLK_VERT_FLIP)
#define BLK_X_FLIP 0x4000
#define BLK_Y_FILP 0x8000
#define BLK_X_Y_FLIP (BLK_X_FLIP | BLK_Y_FILP)

#define VRAM_WRITE 0x80
#define CGRAM_WRITE 0x40
#define VRAM_WRITE_TILEMAP 0x80
#define VRAM_WRITE_TILES 0x40

#define HUD_RAM_OFFSET(x) (ADDR16_OF_RAM_OFFSET(x, hud_tilemap))

static const uint16 kHudTilemaps_TopRow[32] = {  // 0x80988B
  0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c1d, 0x2c1d, 0x2c1d, 0x2c1d, 0x2c1d, 0x2c1c,
};

static const uint16 kHudTilemaps_Row1to3[96] = {  // 0x8098CB
  0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c12, 0x2c12, 0x2c23, 0x2c12, 0x2c12, 0x2c1e,
  0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2822, 0x2822, 0x2823, 0x2813, 0x2c14, 0x2c1e,
  0x2c0f, 0x2c0b, 0x2c0c, 0x2c0d, 0x2c32, 0x2c0f, 0x2c09, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c12, 0x2c12, 0xa824, 0x2815, 0x2c16, 0x2c1e,
};

static const uint16 kHudTilemaps_AutoReserve[6] = {  // 0x80998B
  0x3c33, 0x3c46,
  0x3c47, 0x3c48,
  0xbc33, 0xbc46,
};

static const uint16 kHudTilemaps_EmptyAutoReserve[6] = {  // 0x809997
  0x2c33, 0x2c46,
  0x2c47, 0x2c48,
  0xac33, 0xac46,
};

static const uint16 kHudTilemaps_Missiles[6] = {  // 0x8099A3
  0x344b, 0x3449, 0x744b,
  0x344c, 0x344a, 0x744c,
};

static const uint16 kHudTilemaps_SuperMissiles[4] = {  // 0x8099AF
  0x3434, 0x7434,
  0x3435, 0x7435,
};

static const uint16 kHudTilemaps_PowerBombs[4] = {  // 0x8099B7
  0x3436, 0x7436,
  0x3437, 0x7437,
};

static const uint16 kHudTilemaps_Grapple[4] = {  // 0x8099BF
  0x3438, 0x7438,
  0x3439, 0x7439,
};

static const uint16 kHudTilemaps_Xray[4] = {  // 0x8099C7
  0x343a, 0x743a,
  0x343b, 0x743b,
};

static const uint16 kEnergyTankIconTilemapOffsets[14] = {  // 0x809CCE
  0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e,  // Bottom row = Top row + 0x40
     2,    4,    6,    8,  0xa,  0xc,  0xe,  // Top row
};

static const uint16 kHudItemTilemapOffsets[5] = {  // 0x809CEA
  [kHudItem_1_Missile-1]      = 0x14,  // HUD_RAM_OFFSET(hud_tilemap.row1.missiles),
  [kHudItem_2_SuperMissile-1] = 0x1c,  // HUD_RAM_OFFSET(hud_tilemap.row1.super_missiles)
  [kHudItem_3_PowerBomb-1]    = 0x22,  // HUD_RAM_OFFSET(hud_tilemap.row1.power_bombs)
  [kHudItem_4_Grapple-1]      = 0x28,  // HUD_RAM_OFFSET(hud_tilemap.row1.grapple)
  [kHudItem_5_Xray-1]         = 0x2e,  // HUD_RAM_OFFSET(hud_tilemap.row1.x_ray)
};

static const uint16 kDigitTilesetsHealth[10] = {  // 0x809DBF
  0x2c09, 0x2c00, 0x2c01, 0x2c02, 0x2c03, 0x2c04, 0x2c05, 0x2c06, 0x2c07, 0x2c08,
};

static const uint16 kDigitTilesetsWeapon[10] = {  // 0x809DD3
  0x2c09, 0x2c00, 0x2c01, 0x2c02, 0x2c03, 0x2c04, 0x2c05, 0x2c06, 0x2c07, 0x2c08,
};

static const uint8 kTimerCentisecondDecrements[128] = {  // 0x809EEC
  1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 1, 2, 2, 1, 2, 2, 1, 2,
  1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 1, 2, 2, 1, 2, 2, 1, 2,
  1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 1, 2, 2, 1, 2, 2, 1, 2,
  1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 2,
};

static const uint16 kTimerDigitsSpritemapPtr[10] = {  // 0x809FD4
  0x9fe8, 0x9ff4, 0xa000, 0xa00c, 0xa018, 0xa024, 0xa030, 0xa03c, 0xa048, 0xa054,
};

static const LoadStationList kLoadStationLists[9][23] = {
  [kArea_0_Crateria] = {
    [0]  = { .room_ptr_ = kRoom_91F8_Landing_site                                             , .door_ptr = 0x896a , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0x40  , .samus_x_offset = 0x0    , },
    [1]  = { .room_ptr_ = kRoom_93D5_Crateria_save_station                                    , .door_ptr = 0x899a , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x98  , .samus_x_offset = 0xffe0 , },
    [2]  = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [3]  = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [4]  = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [5]  = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [6]  = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [7]  = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [8]  = { .room_ptr_ = kRoom_94CC_Crateria_to_Maridia_elevator                             , .door_ptr = 0x8aba , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0xa8  , .samus_x_offset = 0x0    , },
    [9]  = { .room_ptr_ = kRoom_962A_Crateria_to_Red_Brinstar_elevator                        , .door_ptr = 0x8a42 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0xa8  , .samus_x_offset = 0x0    , },
    [10] = { .room_ptr_ = kRoom_97B5_Crateria_to_Blue_Brinstar_elevator                       , .door_ptr = 0x8b86 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x88  , .samus_x_offset = 0x0    , },
    [11] = { .room_ptr_ = kRoom_9938_Crateria_to_Green_Brinstar_elevator                      , .door_ptr = 0x8c22 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x88  , .samus_x_offset = 0x0    , },
    [12] = { .room_ptr_ = kRoom_A66A_Tourian_entrance                                         , .door_ptr = 0x91f2 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x100 , .samus_y_offset = 0x98  , .samus_x_offset = 0x0    , },
    [13] = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [14] = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [15] = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [16] = { .room_ptr_ = kRoom_91F8_Landing_site                                             , .door_ptr = 0x896a , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0x40  , .samus_x_offset = 0x0    , },
    [17] = { .room_ptr_ = kRoom_94FD_Wrecked_Ship_back_door                                   , .door_ptr = 0x8a7e , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x400 , .samus_y_offset = 0x95  , .samus_x_offset = 0x0    , },
    [18] = { .room_ptr_ = kRoom_91F8_Landing_site                                             , .door_ptr = 0x88fe , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x0   , .samus_y_offset = 0x80  , .samus_x_offset = 0x0    , },
  },
  [kArea_1_Brinstar] = {
    [0]  = { .room_ptr_ = kRoom_A184_Pre_Spore_Spawn_save_station                             , .door_ptr = 0x8df6 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x98  , .samus_x_offset = 0xffe0 , },
    [1]  = { .room_ptr_ = kRoom_A201_Green_Brinstar_mainstreet_save_station                   , .door_ptr = 0x8d12 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x98  , .samus_x_offset = 0xffe0 , },
    [2]  = { .room_ptr_ = kRoom_A22A_Brinstar_false_floor_save_station                        , .door_ptr = 0x8f52 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x98  , .samus_x_offset = 0xffe0 , },
    [3]  = { .room_ptr_ = kRoom_A70B_Kraid_save_station                                       , .door_ptr = 0x9186 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x98  , .samus_x_offset = 0x0    , },
    [4]  = { .room_ptr_ = kRoom_A734_Red_Brinstar_save_station                                , .door_ptr = 0x90d2 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x98  , .samus_x_offset = 0x0    , },
    [5]  = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [6]  = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [7]  = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [8]  = { .room_ptr_ = kRoom_9AD9_Green_Brinstar_mainstreet                                , .door_ptr = 0x8d42 , .door_bts = 0x1   , .screen_x_pos = 0x0   , .screen_y_pos = 0x200 , .samus_y_offset = 0xa8  , .samus_x_offset = 0x0    , },
    [9]  = { .room_ptr_ = kRoom_9E9F_Morph_ball_room                                          , .door_ptr = 0x8e86 , .door_bts = 0x0   , .screen_x_pos = 0x500 , .screen_y_pos = 0x200 , .samus_y_offset = 0xa8  , .samus_x_offset = 0x0    , },
    [10] = { .room_ptr_ = kRoom_A322_Red_Brinstar_to_Crateria_elevator                        , .door_ptr = 0x908a , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x200 , .samus_y_offset = 0xa8  , .samus_x_offset = 0x0    , },
    [11] = { .room_ptr_ = kRoom_A6A1_Kraids_lair_entrance                                     , .door_ptr = 0xa384 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x88  , .samus_x_offset = 0x0    , },
    [12] = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [13] = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [14] = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [15] = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [16] = { .room_ptr_ = kRoom_9AD9_Green_Brinstar_mainstreet                                , .door_ptr = 0x8d42 , .door_bts = 0x1   , .screen_x_pos = 0x0   , .screen_y_pos = 0x200 , .samus_y_offset = 0xa8  , .samus_x_offset = 0x0    , },
    [17] = { .room_ptr_ = kRoom_A56B_Pre_Kraid_room                                           , .door_ptr = 0x91ce , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x100 , .samus_y_offset = 0x80  , .samus_x_offset = 0x0    , },
    [18] = { .room_ptr_ = kRoom_9D19_Charge_beam_room                                         , .door_ptr = 0x8e62 , .door_bts = 0x0   , .screen_x_pos = 0x300 , .screen_y_pos = 0x0   , .samus_y_offset = 0x80  , .samus_x_offset = 0x0    , },
  },
  [kArea_2_Norfair]  = {
    [0]  = { .room_ptr_ = kRoom_AAB5_Post_Crocomire_save_station                              , .door_ptr = 0x9456 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x98  , .samus_x_offset = 0x0    , },
    [1]  = { .room_ptr_ = kRoom_B0DD_Bubble_Norfair_save_station                              , .door_ptr = 0x959a , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x98  , .samus_x_offset = 0xffe0 , },
    [2]  = { .room_ptr_ = kRoom_B167_Rock_Norfair_save_station                                , .door_ptr = 0x97da , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x98  , .samus_x_offset = 0x0    , },
    [3]  = { .room_ptr_ = kRoom_B192_Pre_Crocomire_save_station                               , .door_ptr = 0x93ba , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x98  , .samus_x_offset = 0x0    , },
    [4]  = { .room_ptr_ = kRoom_B1BB_Pre_Lower_Norfair_save_station                           , .door_ptr = 0x9702 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x98  , .samus_x_offset = 0xffe0 , },
    [5]  = { .room_ptr_ = kRoom_B741_Lower_Norfair_save_station                               , .door_ptr = 0x9a0e , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x98  , .samus_x_offset = 0x0    , },
    [6]  = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [7]  = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [8]  = { .room_ptr_ = kRoom_A7DE_Norfair_mainstreet                                       , .door_ptr = 0x92a6 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x200 , .samus_y_offset = 0xa8  , .samus_x_offset = 0x0    , },
    [9]  = { .room_ptr_ = kRoom_AF3F_Norfair_to_Lower_Norfair_elevator                        , .door_ptr = 0x96de , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x88  , .samus_x_offset = 0x0    , },
    [10] = { .room_ptr_ = kRoom_B236_Lower_Norfair_mainstreet                                 , .door_ptr = 0x9846 , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x200 , .samus_y_offset = 0x88  , .samus_x_offset = 0x0    , },
    [11] = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [12] = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [13] = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [14] = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [15] = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [16] = { .room_ptr_ = kRoom_A7DE_Norfair_mainstreet                                       , .door_ptr = 0x932a , .door_bts = 0x2   , .screen_x_pos = 0x0   , .screen_y_pos = 0x200 , .samus_y_offset = 0xa8  , .samus_x_offset = 0x0    , },
    [17] = { .room_ptr_ = kRoom_A923_Norfair_slope                                            , .door_ptr = 0x93ea , .door_bts = 0x1   , .screen_x_pos = 0xc00 , .screen_y_pos = 0x200 , .samus_y_offset = 0xa0  , .samus_x_offset = 0x0    , },
    [18] = { .room_ptr_ = kRoom_B37A_Pre_Ridley_hall                                          , .door_ptr = 0x995a , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0xa0  , .samus_x_offset = 0x0    , },
    [19] = { .room_ptr_ = kRoom_AA82_Post_Crocomire_room                                      , .door_ptr = 0x946e , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0xb5  , .samus_x_offset = 0x0    , },
    [20] = { .room_ptr_ = kRoom_B236_Lower_Norfair_mainstreet                                 , .door_ptr = 0x9846 , .door_bts = 0x1   , .screen_x_pos = 0x500 , .screen_y_pos = 0x200 , .samus_y_offset = 0x35  , .samus_x_offset = 0x0    , },
    [21] = { .room_ptr_ = kRoom_B283_Golden_Torizo                                            , .door_ptr = 0x98a6 , .door_bts = 0x0   , .screen_x_pos = 0x200 , .screen_y_pos = 0x200 , .samus_y_offset = 0x0   , .samus_x_offset = 0x0    , },
    [22] = { .room_ptr_ = kRoom_B283_Golden_Torizo                                            , .door_ptr = 0x983a , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x80  , .samus_x_offset = 0x0    , },
  },
  [kArea_3_WreckedShip] = {
    [0]  = { .room_ptr_ = kRoom_CE8A_Wrecked_Ship_save_station                                , .door_ptr = 0xa240 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x98  , .samus_x_offset = 0x0    , },
    [1]  = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [2]  = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [3]  = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [4]  = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [5]  = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [6]  = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [7]  = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [8]  = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [9]  = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [10] = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [11] = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [12] = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [13] = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [14] = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [15] = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [16] = { .room_ptr_ = kRoom_CA08_Wrecked_Ship_entrance_treadmill                          , .door_ptr = 0xa1f8 , .door_bts = 0x1   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x80  , .samus_x_offset = 0x0    , },
    [17] = { .room_ptr_ = kRoom_CC6F_Pre_Phantoon_hall                                        , .door_ptr = 0xa2b8 , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x0   , .samus_y_offset = 0x80  , .samus_x_offset = 0x0    , },
  },
  [kArea_4_Maridia]  = {
    [0]  = { .room_ptr_ = kRoom_CED2_n00b_tube_save_station                                   , .door_ptr = 0xa354 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x98  , .samus_x_offset = 0x0    , },
    [1]  = { .room_ptr_ = kRoom_D3DF_Sandy_Maridia_save_station                               , .door_ptr = 0xa588 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x98  , .samus_x_offset = 0x0    , },
    [2]  = { .room_ptr_ = kRoom_D765_Snail_room_save_station                                  , .door_ptr = 0xa744 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x98  , .samus_x_offset = 0xffe0 , },
    [3]  = { .room_ptr_ = kRoom_D81A_Draygon_save_station                                     , .door_ptr = 0xa7ec , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x98  , .samus_x_offset = 0x0    , },
    [4]  = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [5]  = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [6]  = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [7]  = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [8]  = { .room_ptr_ = kRoom_D30B_Maridia_to_Crateria_elevator                             , .door_ptr = 0xa570 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x200 , .samus_y_offset = 0xa8  , .samus_x_offset = 0x0    , },
    [9]  = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [10] = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [11] = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [12] = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [13] = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [14] = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [15] = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [16] = { .room_ptr_ = kRoom_D1DD_Sandy_Maridia_unused_passage_to_Sandy_Maridia_mainstreet , .door_ptr = 0xa4a4 , .door_bts = 0x1   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0xd0  , .samus_x_offset = 0x0    , },
    [17] = { .room_ptr_ = kRoom_D78F_Pre_Draygon_room                                         , .door_ptr = 0xa81c , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x200 , .samus_y_offset = 0x80  , .samus_x_offset = 0x0    , },
    [18] = { .room_ptr_ = kRoom_D617_Mochtroid_room                                           , .door_ptr = 0xa72c , .door_bts = 0x0   , .screen_x_pos = 0x300 , .screen_y_pos = 0x0   , .samus_y_offset = 0x80  , .samus_x_offset = 0x0    , },
    [19] = { .room_ptr_ = kRoom_D48E_Elevatube_south                                          , .door_ptr = 0xa648 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x100 , .samus_y_offset = 0x80  , .samus_x_offset = 0x0    , },
  },
  [kArea_5_Tourian]  = {
    [0]  = { .room_ptr_ = kRoom_DE23_Pre_Mother_Brain_save_station_trap                       , .door_ptr = 0xaabc , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x98  , .samus_x_offset = 0xffe0 , },
    [1]  = { .room_ptr_ = kRoom_DF1B_Tourian_save_station                                     , .door_ptr = 0xa99c , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x98  , .samus_x_offset = 0x0    , },
    [2]  = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [3]  = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [4]  = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [5]  = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [6]  = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [7]  = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [8]  = { .room_ptr_ = kRoom_DAAE_Tourian_to_Crateria_elevator                             , .door_ptr = 0xa9a8 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x200 , .samus_y_offset = 0xa8  , .samus_x_offset = 0x0    , },
    [9]  = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [10] = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [11] = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [12] = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [13] = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [14] = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [15] = { .room_ptr_ = 0x0                                                                 , .door_ptr = 0x0    , .door_bts = 0x0   , .screen_x_pos = 0x400 , .screen_y_pos = 0x400 , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [16] = { .room_ptr_ = kRoom_DDF3_Pre_Mother_Brain_shaft                                   , .door_ptr = 0xaaa4 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x200 , .samus_y_offset = 0x80  , .samus_x_offset = 0x0    , },
    [17] = { .room_ptr_ = kRoom_DDF3_Pre_Mother_Brain_shaft                                   , .door_ptr = 0xaa38 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x80  , .samus_x_offset = 0x0    , },
  },
  [kArea_6_Ceres]    = {
    [0]  = { .room_ptr_ = kRoom_DF45_Ceres_elevator_shaft                                     , .door_ptr = 0xab58 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x48  , .samus_x_offset = 0x0    , },
    [1]  = { .room_ptr_ = kRoom_DF45_Ceres_elevator_shaft                                     , .door_ptr = 0xab58 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x40  , .samus_x_offset = 0x0    , },
    [2]  = { .room_ptr_ = kRoom_DF45_Ceres_elevator_shaft                                     , .door_ptr = 0xab58 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x40  , .samus_x_offset = 0x0    , },
    [3]  = { .room_ptr_ = kRoom_DF45_Ceres_elevator_shaft                                     , .door_ptr = 0xab58 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x40  , .samus_x_offset = 0x0    , },
    [4]  = { .room_ptr_ = kRoom_DF45_Ceres_elevator_shaft                                     , .door_ptr = 0xab58 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x40  , .samus_x_offset = 0x0    , },
    [5]  = { .room_ptr_ = kRoom_DF45_Ceres_elevator_shaft                                     , .door_ptr = 0xab58 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x40  , .samus_x_offset = 0x0    , },
    [6]  = { .room_ptr_ = kRoom_DF45_Ceres_elevator_shaft                                     , .door_ptr = 0xab58 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x40  , .samus_x_offset = 0x0    , },
    [7]  = { .room_ptr_ = kRoom_DF45_Ceres_elevator_shaft                                     , .door_ptr = 0xab58 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x40  , .samus_x_offset = 0x0    , },
    [8]  = { .room_ptr_ = kRoom_DF45_Ceres_elevator_shaft                                     , .door_ptr = 0xab58 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x40  , .samus_x_offset = 0x0    , },
    [9]  = { .room_ptr_ = kRoom_DF45_Ceres_elevator_shaft                                     , .door_ptr = 0xab58 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x40  , .samus_x_offset = 0x0    , },
    [10] = { .room_ptr_ = kRoom_DF45_Ceres_elevator_shaft                                     , .door_ptr = 0xab58 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x40  , .samus_x_offset = 0x0    , },
    [11] = { .room_ptr_ = kRoom_DF45_Ceres_elevator_shaft                                     , .door_ptr = 0xab58 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x40  , .samus_x_offset = 0x0    , },
    [12] = { .room_ptr_ = kRoom_DF45_Ceres_elevator_shaft                                     , .door_ptr = 0xab58 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x40  , .samus_x_offset = 0x0    , },
    [13] = { .room_ptr_ = kRoom_DF45_Ceres_elevator_shaft                                     , .door_ptr = 0xab58 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x40  , .samus_x_offset = 0x0    , },
    [14] = { .room_ptr_ = kRoom_DF45_Ceres_elevator_shaft                                     , .door_ptr = 0xab58 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x40  , .samus_x_offset = 0x0    , },
    [15] = { .room_ptr_ = kRoom_DF45_Ceres_elevator_shaft                                     , .door_ptr = 0xab58 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x40  , .samus_x_offset = 0x0    , },
    [16] = { .room_ptr_ = kRoom_DF45_Ceres_elevator_shaft                                     , .door_ptr = 0xab58 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0x40  , .samus_x_offset = 0x0    , },
  },
  [kArea_7_Debug]    = {
    [0]  = { .room_ptr_ = kRoom_E82C_Debug_room                                               , .door_ptr = 0xabc4 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [1]  = { .room_ptr_ = kRoom_E82C_Debug_room                                               , .door_ptr = 0xabc4 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [2]  = { .room_ptr_ = kRoom_E82C_Debug_room                                               , .door_ptr = 0xabc4 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [3]  = { .room_ptr_ = kRoom_E82C_Debug_room                                               , .door_ptr = 0xabc4 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [4]  = { .room_ptr_ = kRoom_E82C_Debug_room                                               , .door_ptr = 0xabc4 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [5]  = { .room_ptr_ = kRoom_E82C_Debug_room                                               , .door_ptr = 0xabc4 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [6]  = { .room_ptr_ = kRoom_E82C_Debug_room                                               , .door_ptr = 0xabc4 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [7]  = { .room_ptr_ = kRoom_E82C_Debug_room                                               , .door_ptr = 0xabc4 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [8]  = { .room_ptr_ = kRoom_E82C_Debug_room                                               , .door_ptr = 0xabc4 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [9]  = { .room_ptr_ = kRoom_E82C_Debug_room                                               , .door_ptr = 0xabc4 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [10] = { .room_ptr_ = kRoom_E82C_Debug_room                                               , .door_ptr = 0xabc4 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [11] = { .room_ptr_ = kRoom_E82C_Debug_room                                               , .door_ptr = 0xabc4 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [12] = { .room_ptr_ = kRoom_E82C_Debug_room                                               , .door_ptr = 0xabc4 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [13] = { .room_ptr_ = kRoom_E82C_Debug_room                                               , .door_ptr = 0xabc4 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [14] = { .room_ptr_ = kRoom_E82C_Debug_room                                               , .door_ptr = 0xabc4 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [15] = { .room_ptr_ = kRoom_E82C_Debug_room                                               , .door_ptr = 0xabc4 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
    [16] = { .room_ptr_ = kRoom_E82C_Debug_room                                               , .door_ptr = 0xabc4 , .door_bts = 0x0   , .screen_x_pos = 0x0   , .screen_y_pos = 0x0   , .samus_y_offset = 0xb0  , .samus_x_offset = 0x0    , },
  },
};

static const ElevatorsUsedConf kAreaElevatorBits[6][5] = {  // 0x80CD46
  [kArea_0_Crateria] = {
    [0] = { .src_area =  1, .src_bit =  1, .dst_area =  9, .dst_bit =  1 },
    [1] = { .src_area =  1, .src_bit =  2, .dst_area =  3, .dst_bit =  4, },
    [2] = { .src_area =  1, .src_bit =  4, .dst_area =  3, .dst_bit =  2, },
    [3] = { .src_area =  1, .src_bit =  8, .dst_area =  3, .dst_bit =  1, },
    [4] = { .src_area =  1, .src_bit = 16, .dst_area = 11, .dst_bit =  1, },
  },
  [kArea_1_Brinstar] = {
    [0] = { .src_area =  3, .src_bit =  1, .dst_area =  1, .dst_bit =  8, },
    [1] = { .src_area =  3, .src_bit =  2, .dst_area =  1, .dst_bit =  4, },
    [2] = { .src_area =  3, .src_bit =  4, .dst_area =  1, .dst_bit =  2, },
    [3] = { .src_area =  3, .src_bit =  8, .dst_area =  5, .dst_bit =  1, },
  },
  [kArea_2_Norfair] = {
    [0] = { .src_area =  5, .src_bit =  1, .dst_area =  3, .dst_bit =  8, },
    [1] = { .src_area =  5, .src_bit =  2, .dst_area =  5, .dst_bit =  4, },
    [2] = { .src_area =  5, .src_bit =  4, .dst_area =  5, .dst_bit =  2, },
  },
  [kArea_3_WreckedShip] = {
    [0] = { .src_area =  0, .src_bit =  0, .dst_area =  0, .dst_bit =  0, },
  },
  [kArea_4_Maridia] = {
    [0] = { .src_area =  9, .src_bit =  1, .dst_area =  1, .dst_bit =  1, },
  },
  [kArea_5_Tourian] = {
    [0] = { .src_area = 11, .src_bit =  1, .dst_area =  1, .dst_bit = 16, },
  },
};

static const LongPtr kMusicPointers[] = {  // 0x8FE7E1
  [(uint8)kMusic_SpcEngine                   / sizeof(LongPtr)] = LONGPTR(0xcf8000),
  [(uint8)kMusic_TitleSequence               / sizeof(LongPtr)] = LONGPTR(0xd0e20d),
  [(uint8)kMusic_EmptyCrateria               / sizeof(LongPtr)] = LONGPTR(0xd1b62a),
  [(uint8)kMusic_LowerCrateria               / sizeof(LongPtr)] = LONGPTR(0xd288ca),
  [(uint8)kMusic_UpperCrateria               / sizeof(LongPtr)] = LONGPTR(0xd2d9b6),
  [(uint8)kMusic_GreenBrinstar               / sizeof(LongPtr)] = LONGPTR(0xd3933c),
  [(uint8)kMusic_RedBrinstar                 / sizeof(LongPtr)] = LONGPTR(0xd3e812),
  [(uint8)kMusic_UpperNorfair                / sizeof(LongPtr)] = LONGPTR(0xd4b86c),
  [(uint8)kMusic_LowerNorfair                / sizeof(LongPtr)] = LONGPTR(0xd4f420),
  [(uint8)kMusic_Maridia                     / sizeof(LongPtr)] = LONGPTR(0xd5c844),
  [(uint8)kMusic_Tourian                     / sizeof(LongPtr)] = LONGPTR(0xd698b7),
  [(uint8)kMusic_MotherBrain                 / sizeof(LongPtr)] = LONGPTR(0xd6ef9d),
  [(uint8)kMusic_BossFight1                  / sizeof(LongPtr)] = LONGPTR(0xd7bf73),
  [(uint8)kMusic_BossFight2                  / sizeof(LongPtr)] = LONGPTR(0xd899b2),
  [(uint8)kMusic_MinibossFight               / sizeof(LongPtr)] = LONGPTR(0xd8ea8b),
  [(uint8)kMusic_Ceres                       / sizeof(LongPtr)] = LONGPTR(0xd9b67b),
  [(uint8)kMusic_WreckedShip                 / sizeof(LongPtr)] = LONGPTR(0xd9f5dd),
  [(uint8)kMusic_ZebesBoom                   / sizeof(LongPtr)] = LONGPTR(0xdab650),
  [(uint8)kMusic_Intro                       / sizeof(LongPtr)] = LONGPTR(0xdad63b),
  [(uint8)kMusic_Death                       / sizeof(LongPtr)] = LONGPTR(0xdba40f),
  [(uint8)kMusic_Credits                     / sizeof(LongPtr)] = LONGPTR(0xdbdf4f),
  [(uint8)kMusic_TheLastMetroidIsInCaptivity / sizeof(LongPtr)] = LONGPTR(0xdcaf6c),
  [(uint8)kMusic_TheGalaxyIsAtPeace          / sizeof(LongPtr)] = LONGPTR(0xdcfac7),
  [(uint8)kMusic_Shitroid                    / sizeof(LongPtr)] = LONGPTR(0xddb104),
  [(uint8)kMusic_SamusTheme                  / sizeof(LongPtr)] = LONGPTR(0xde81c1),
};
