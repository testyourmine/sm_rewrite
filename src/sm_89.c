// Item PLM graphics, FX loader

#include "ida_types.h"
#include "variables.h"
#include "funcs.h"
#include "sm_89.h"


/**
* @brief Loads the FX entry for the room
* @brief This is called by Mother Brain's room
* @param fx_def_index The index of the FX entry for the room
*/
void LoadFxEntry(uint16 fx_def_index) {  // 0x89AB02
  uint16 fx_def_offset = sizeof(FxDef) * (fx_def_index & 7);
  FxDef FD = get_FxDef(room_layer3_fx_ptr + fx_def_offset);
  fx_base_y_pos = FD.base_y_pos;
  fx_target_y_pos = FD.target_y_pos;
  fx_y_vel = FD.y_vel;
  fx_timer = FD.timer;
  fx_layer_blending_config_a = FD.default_layer_blend;
  fx_layer_blending_config_b = FD.layer3_layer_blend;
  fx_liquid_options = FD.fx_liquid_options_;
  if (FD.palette_blend != 0) {
    int blend = FD.palette_blend >> 1;
    palette_buffer.bg3_pal_6[1] = kPaletteBlends[blend];
    palette_buffer.bg3_pal_6[2] = kPaletteBlends[blend + 1];
    palette_buffer.bg3_pal_6[3] = kPaletteBlends[blend + 2];
  }
  else {
    palette_buffer.bg3_pal_6[3] = 0;
  }
}

/**
* @brief Loads the FX for the current room
*/
void LoadFXHeader(void) {  // 0x89AB82
  uint16 list_size;

  uint16 fx_entry_ptr = room_layer3_fx_ptr;
  if (fx_entry_ptr == 0)
    return;
  for(;;) {
    uint16 door_ptr = get_FxDef(fx_entry_ptr).door_ptr;
    if (door_ptr == 0)
      break;
    if (door_ptr == 0xFFFF)
      return;
    if (door_ptr == door_def_ptr)
      break;
    fx_entry_ptr += sizeof(FxDef);
  }

  FxDef FD = get_FxDef(fx_entry_ptr);
  fx_base_y_pos = FD.base_y_pos;
  fx_target_y_pos = FD.target_y_pos;
  fx_y_vel = FD.y_vel;
  fx_timer = FD.timer;
  fx_layer_blending_config_a = FD.default_layer_blend;
  fx_layer_blending_config_b = FD.layer3_layer_blend;
  fx_liquid_options = FD.fx_liquid_options_;
  if (FD.palette_blend != 0) {
    int blend = FD.palette_blend >> 1;
    target_palettes.bg3_pal_6[1] = kPaletteBlends[blend];
    target_palettes.bg3_pal_6[2] = kPaletteBlends[blend + 1];
    target_palettes.bg3_pal_6[3] = kPaletteBlends[blend + 2];
  }
  else {
    target_palettes.bg3_pal_6[3] = 0;
  }

  fx_type = FD.type;
  if (FD.type != kFxType_0_None) {
    fx_tilemap_ptr = kFxTypeTilemapPtrs[FD.type >> 1];
    kFxTypeFuncPtrs[FD.type >> 1]();
  }

  if (FD.palette_fx_bitset != 0) {
    int bits = FD.palette_fx_bitset;
    const uint16 *area_pal_fx = kAreaPalFxLists[area_index];
    list_size = 2 * arraysize(kAreaPalFxLists);
    for (int pal_fx_index = 0; pal_fx_index < list_size; pal_fx_index += 2, bits >>= 1) {
      if (bits & 1)
        SpawnPalfxObject(area_pal_fx[pal_fx_index >> 1]);
    }
  }
  if (FD.animtiles_bitset != 0) {
    int bits = FD.animtiles_bitset;
    const uint16 *area_anim_tiles = kAreaAnimtilesLists[area_index];
    list_size = 2 * arraysize(kAreaAnimtilesLists);
    for (int anim_tiles_index = 0; anim_tiles_index < list_size; anim_tiles_index += 2, bits >>= 1) {
      if (bits & 1)
        SpawnAnimtiles(area_anim_tiles[anim_tiles_index >> 1]);
    }
  }
}

/**
* @brief Handles Mode 7 operations and landing on the elevator for the Ceres elevator shaft during the escape
*/
void RoomCode_CeresElevatorShaft(void) {  // 0x89ACC3
  uint16 new_index;

  if (ceres_status & kCeresStatus_8000_ElevatorRoomRotate) {
    // If standing on the elevator
    if ((128 - 16) < samus_x_pos && samus_x_pos <= (128 + 16)
        && 128 > samus_y_pos && samus_y_pos >= 75
        && samus_y_speed == 0 && samus_y_subspeed == 0
        && game_state == kGameState_8_MainGameplay) {
      RunSamusCode(kSamusCode_2_ReachCeresElevator);
      screen_fade_delay = 0;
      screen_fade_counter = 0;
      game_state = kGameState_32_MadeItToCeresElevator;
    }
    if ((int16)--rotation_matrix_timer < 0) {
      int index = LOBYTE(rotation_matrix_index);
      rotation_matrix_timer = kCeresElevatorShaftMode7TransformationMatrix[index].timer;
      reg_M7B = kCeresElevatorShaftMode7TransformationMatrix[index].sin_t;
      reg_M7C = -reg_M7B;
      reg_M7A = kCeresElevatorShaftMode7TransformationMatrix[index].cos_t;
      reg_M7D = reg_M7A;
      if (rotation_matrix_index & ROTATE_CCW) {
        new_index = rotation_matrix_index - 1;
        if (new_index == (ROTATE_CCW|0))
          new_index = ROTATE_CW;
      }
      else {
        new_index = rotation_matrix_index + 1;
        uint16 max_index = arrayend(kCeresElevatorShaftMode7TransformationMatrix);
        if (new_index == max_index)
          new_index |= ROTATE_CCW;
      }
      rotation_matrix_index = new_index;
    }
  }
}
