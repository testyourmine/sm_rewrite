// Item PLM graphics, FX loader

#include "ida_types.h"
#include "variables.h"
#include "funcs.h"
#include "sm_89.h"


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
  if (FD.palette_blend) {
    int v2 = FD.palette_blend >> 1;
    palette_buffer.bg3_pal_6[1] = kPaletteBlends[v2];
    palette_buffer.bg3_pal_6[2] = kPaletteBlends[v2 + 1];
    palette_buffer.bg3_pal_6[3] = kPaletteBlends[v2 + 2];
  } else {
    palette_buffer.bg3_pal_6[3] = 0;
  }
}

void nullsub_106(void) {}

static Func_V *const kFxTypeFuncPtrs[23] = {  // 0x89AB82
  nullsub_106,
  FxTypeFunc_2_Lava,
  FxTypeFunc_4_Acid,
  FxTypeFunc_6_Water,
  FxTypeFunc_8_Spores,
  FxTypeFunc_A_Rain,
  FxTypeFunc_C_Fog,
  nullsub_106,
  nullsub_106,
  nullsub_106,
  nullsub_106,
  nullsub_106,
  nullsub_106,
  nullsub_106,
  nullsub_106,
  nullsub_106,
  FxTypeFunc_20_ScrollingSkyLand,
  FxTypeFunc_22_Unused,
  FxTypeFunc_24_Fireflea,
  FxTypeFunc_26_TourianEntranceStatue,
  FxTypeFunc_28_CeresRidley,
  FxTypeFunc_2A_CeresElevator,
  FxTypeFunc_2C_Haze,
};
void LoadFXHeader(void) {
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
  if (FD.palette_blend) {
    int v4 = FD.palette_blend >> 1;
    target_palettes.bg3_pal_6[1] = kPaletteBlends[v4];
    target_palettes.bg3_pal_6[2] = kPaletteBlends[v4 + 1];
    target_palettes.bg3_pal_6[3] = kPaletteBlends[v4 + 2];
  } else {
    target_palettes.bg3_pal_6[3] = 0;
  }
  fx_type = FD.type;
  if (FD.type != kFxType_0_None) {
    fx_tilemap_ptr = kFxTypeTilemapPtrs[FD.type >> 1];
    kFxTypeFuncPtrs[FD.type >> 1]();
  }
  if (FD.palette_fx_bitset) {
    int bits = FD.palette_fx_bitset;
    const uint8 *v11 = RomPtr_83(kAreaPalFxListPointers[area_index]);
    for (int j = 0; j != 16; j += 2, bits >>= 1) {
      if (bits & 1)
        SpawnPalfxObject(*(uint16 *)&v11[j]);
    }
  }
  if (FD.animtiles_bitset) {
    int bits = FD.animtiles_bitset;
    const uint16 *v14 = kAreaAnimtilesListPtrs[area_index];
    for (int k = 0; k != 16; k += 2, bits >>= 1) {
      if (bits & 1)
        SpawnAnimtiles(v14[k >> 1]);
    }
  }
}
void RoomCode_CeresElevatorShaft(void) {  // 0x89ACC3
  int16 v1;

  if ((ceres_status & kCeresStatus_8000_ElevatorRoomRotate) != 0) {
    if ((128 - 16) < samus_x_pos && samus_x_pos <= (128 + 16)
        && 128 > samus_y_pos && samus_y_pos >= 75
        && samus_y_speed == 0 && samus_y_subspeed == 0
        && game_state == kGameState_8_MainGameplay) {
      RunSamusCode(kSamusCode_2_ReachCeresElevator);
      screen_fade_delay = 0;
      screen_fade_counter = 0;
      game_state = kGameState_32_MadeItToCeresElevator;
    }
    --(WORD(room_main_asm_variables[2]));
    if (sign16(WORD(room_main_asm_variables[2]))) {
      int v0 = (uint16)(6 * WORD(room_main_asm_variables[0])) >> 1;
      WORD(room_main_asm_variables[2]) = kCereElevatorShaftMode7TransformationMatrix[v0];
      reg_M7B = kCereElevatorShaftMode7TransformationMatrix[v0 + 1];
      reg_M7C = -reg_M7B;
      reg_M7A = kCereElevatorShaftMode7TransformationMatrix[v0 + 2];
      reg_M7D = reg_M7A;
      if (sign16(WORD(room_main_asm_variables[0]))) {
        v1 = WORD(room_main_asm_variables[0]) - 1;
        if (WORD(room_main_asm_variables[0]) == 0x8001)
          v1 = 0;
      } else {
        v1 = WORD(room_main_asm_variables[0]) + 1;
        if (WORD(room_main_asm_variables[0]) == 67)
          v1 = -32700;
      }
      WORD(room_main_asm_variables[0]) = v1;
    }
  }
}
