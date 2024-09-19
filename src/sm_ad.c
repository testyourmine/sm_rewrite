// Extra Mother Brain code

#include <stdio.h>

#include "ida_types.h"
#include "variables.h"
#include "funcs.h"
#include "enemy_types.h"
#include "sm_ad.h"

void nullsub_341(void) {}

static Func_V *const kMotherBrain_CalcHdma_Funcs[16] = {
  MotherBrain_CalcHdma_BeamAimedDown, MotherBrain_CalcHdma_BeamAimedRight,                                0,                                  0,
                                   0,    MotherBrain_CalcHdma_BeamAimedUp, MotherBrain_CalcHdma_BeamAimedUp,                                  0,
                                   0,                                   0, MotherBrain_CalcHdma_BeamAimedUp,                        nullsub_341,
  MotherBrain_CalcHdma_BeamAimedDown,                                   0,                                0, MotherBrain_CalcHdma_BeamAimedDown,
};

/**
* @brief Calculate the HDMA tables and setup the indirect HDMA for Mother Brain's rainbow beam
*/
void MotherBrain_CalcHdma(void) {  // 0xADDE00
  Enemy_MotherBrain *E = Get_MotherBrain(0);
  Enemy_MotherBrain *E1 = Get_MotherBrain(0x40);

  uint16 beam_angular_width = HIBYTE(E->rainbow_beam_angular_width) / 2;
  E->rainbow_beam_right_edge_angle = E->rainbow_beam_angle - beam_angular_width;
  E->rainbow_beam_left_edge_angle = E->rainbow_beam_angle + beam_angular_width;

  uint16 beam_origin_x_pos = (LOBYTE(E1->base.x_pos) + 14) << 8;
  E->rainbow_beam_left_origin_x_pos = beam_origin_x_pos;
  E->rainbow_beam_right_origin_x_pos = beam_origin_x_pos;

  uint16 beam_origin_y_pos = E1->base.y_pos + 5;
  E->rainbow_beam_origin_y_pos = beam_origin_y_pos;
  E->rainbow_beam_aimed_right_origin_y_pos = beam_origin_y_pos;

  // 0 is bottom right, 1 is top right, 2 is top left, 3 is bottom left
  uint16 beam_right_edge_quadrant = (E->rainbow_beam_right_edge_angle >> 4) & 0xC;
  uint16 beam_left_edge_quadrant = (E->rainbow_beam_left_edge_angle >> 6) & 3;
  int edge_quadrant_idx = beam_right_edge_quadrant | beam_left_edge_quadrant;
  kMotherBrain_CalcHdma_Funcs[edge_quadrant_idx]();
}

/**
* @brief Calculate the HDMA tables and setup the indirect HDMA for Mother Brain's rainbow beam aimed towards the right
*/
void MotherBrain_CalcHdma_BeamAimedRight(void) {  // 0xADDE7F
  Enemy_MotherBrain *E = Get_MotherBrain(0);
  MotherBrain_CalcHdma_Right_Right(E->rainbow_beam_left_origin_x_pos, E->rainbow_beam_right_origin_x_pos);
  mother_brain_indirect_hdma[0] = 0x10;
  WORD(mother_brain_indirect_hdma[1]) = 0x9C00;

  mother_brain_indirect_hdma[3] = 0x10;
  WORD(mother_brain_indirect_hdma[4]) = 0x9C03;

  mother_brain_indirect_hdma[6] = 0xF0;
  WORD(mother_brain_indirect_hdma[7]) = 0x9D04;

  mother_brain_indirect_hdma[9] = 0xF4;
  WORD(mother_brain_indirect_hdma[10]) = 0x9DEC;

  WORD(mother_brain_indirect_hdma[12]) = 0;
}

/**
* @brief Calcualte the HDMA tables for Mother Brain's rainbow beam aimed towards the right
*/
void MotherBrain_CalcHdma_Right_Right(uint16 right_edge_origin_x_pos, uint16 left_edge_origin_x_pos) {  // 0xADDECE
  hdma_table_2[0] = 0x00FF;
  hdma_table_2[1] = 0x00FF;
  Enemy_MotherBrain *E = Get_MotherBrain(0);
  uint16 right_edge_gradient = kAbsTanTable[LOBYTE(E->rainbow_beam_right_edge_angle)];
  uint16 left_edge_gradient = kAbsTanTable[LOBYTE(E->rainbow_beam_left_edge_angle)];
  uint16 beam_y_pos = E->rainbow_beam_aimed_right_origin_y_pos;
  uint16 num_pad_lines = beam_y_pos - 32;
  uint16 *left_dst = hdma_table_2 + num_pad_lines + 1;
  left_dst[1] = 0x00FF;
  left_dst[2] = 0x00FF;
  uint16 *right_dst = left_dst + 1;

  // left edge
  for (beam_y_pos; beam_y_pos > 32; beam_y_pos--) {
    if (left_edge_origin_x_pos + left_edge_gradient > UINT16_MAX)
      break;
    left_edge_origin_x_pos += left_edge_gradient;
    *left_dst-- = HIBYTE(left_edge_origin_x_pos) | 0xFF00;
  }

  // pad0
  do {
    *left_dst-- = 0x00FF;
  } while (--beam_y_pos > 32);

  // right edge
  beam_y_pos = E->rainbow_beam_aimed_right_origin_y_pos;
  while (1) {
    if (right_edge_origin_x_pos + right_edge_gradient > UINT16_MAX)
      break;
    right_edge_origin_x_pos += right_edge_gradient;
    *right_dst++ = HIBYTE(right_edge_origin_x_pos) | 0xFF00;
    if (++beam_y_pos == 232)
      return;
  }

  // pad0
  do {
    *right_dst++ = 0x00FF;
  } while (++beam_y_pos < 232);
}

typedef void Func_CalcHdma(uint16 r22, uint16 r24);

static Func_CalcHdma *const kMotherBrain_CalcHdma_UpFuncs[4] = {  // 0xADDF6E
  MotherBrain_CalcHdma_Up_UpRight, MotherBrain_CalcHdma_Up_Up,
  0,                               MotherBrain_CalcHdma_Up_UpLeft,
};

/**
* @brief Calculate the HDMA tables and setup the indirect HDMA for Mother Brain's rainbow beam aimed towards the top
*/
void MotherBrain_CalcHdma_BeamAimedUp(void) {
  Enemy_MotherBrain *E = Get_MotherBrain(0);

  // 0 is right half, 1 is left half
  uint16 right_edge_quadrant = (E->rainbow_beam_right_edge_angle >> 6) & 2;
  uint16 left_edge_quadrant = (E->rainbow_beam_left_edge_angle >> 7) & 1;
  uint16 quadrant_idx = right_edge_quadrant | left_edge_quadrant;
  kMotherBrain_CalcHdma_UpFuncs[quadrant_idx](E->rainbow_beam_left_origin_x_pos, E->rainbow_beam_right_origin_x_pos);

  WORD(mother_brain_indirect_hdma[0]) = 16;
  WORD(mother_brain_indirect_hdma[1]) = 0x9D00;
  WORD(mother_brain_indirect_hdma[3]) = 16;
  WORD(mother_brain_indirect_hdma[4]) = 0x9D02;

  uint16 num_pad_lines = E->rainbow_beam_origin_y_pos - 32;
  printf("Carry crap!\n");
  if (num_pad_lines >= 128) {
    WORD(mother_brain_indirect_hdma[6]) = (num_pad_lines - 127) | 0x80;
    WORD(mother_brain_indirect_hdma[7]) = 0x9D04;

    WORD(mother_brain_indirect_hdma[9]) = 0xFF;
    WORD(mother_brain_indirect_hdma[10]) = 0x9D04 + 2 * (num_pad_lines - 127);

    // 2*(num_pad_lines - 127) + 254
    // 2*num_pad_lines - 2*127 + 254
    // 2*num_pad_lines - 254 + 254
    // 2*num_pad_lines
    WORD(mother_brain_indirect_hdma[12]) = 0x7F;
    WORD(mother_brain_indirect_hdma[13]) = 0x9D04 + 2 * num_pad_lines;

    WORD(mother_brain_indirect_hdma[15]) = 0;
  }
  else {
    WORD(mother_brain_indirect_hdma[6]) = num_pad_lines | 0x80;
    WORD(mother_brain_indirect_hdma[7]) = 0x9D04;

    WORD(mother_brain_indirect_hdma[9]) = 0x7F;
    WORD(mother_brain_indirect_hdma[10]) = 0x9D04 + 2 * num_pad_lines;

    WORD(mother_brain_indirect_hdma[12]) = 0;
  }
}

/**
* @brief Calcualte the HDMA tables for Mother Brain's rainbow beam aimed towards the top right
*/
void MotherBrain_CalcHdma_Up_UpRight(uint16 left_edge_origin_x_pos, uint16 right_edge_origin_x_pos) {  // 0xADE02C
  hdma_table_2[0] = 0x00FF;
  hdma_table_2[1] = 0x00FF;
  Enemy_MotherBrain *E = Get_MotherBrain(0);
  uint16 left_edge_gradient = kAbsTanTable[LOBYTE(E->rainbow_beam_left_edge_angle)];
  uint16 right_edge_gradient = kAbsTanTable[LOBYTE(E->rainbow_beam_right_edge_angle)];
  uint16 beam_y_pos = E->rainbow_beam_origin_y_pos;
  uint16 num_pad_lines = beam_y_pos - 32;
  uint16 *dst = hdma_table_2 + num_pad_lines + 1;
  dst[1] = 0x00FF;
  dst[2] = 0x00FF;

  for (beam_y_pos; beam_y_pos > 32; beam_y_pos--) {
    left_edge_origin_x_pos = IntMin(UINT16_MAX, left_edge_origin_x_pos + left_edge_gradient);
    right_edge_origin_x_pos = IntMin(UINT16_MAX, right_edge_origin_x_pos + right_edge_gradient);

    uint16 hdma_entry = (right_edge_origin_x_pos & 0xFF00) | (left_edge_origin_x_pos / 0x100);
    if (hdma_entry == 0xFFFF)
      hdma_entry = 0x00FF;
    *dst-- = hdma_entry;
  }
}

/**
* @brief Calcualte the HDMA tables for Mother Brain's rainbow beam aimed towards the top
*/
void MotherBrain_CalcHdma_Up_Up(uint16 left_edge_origin_x_pos, uint16 right_edge_origin_x_pos) {  // 0xADE0A6
  hdma_table_2[0] = 0x00FF;
  hdma_table_2[1] = 0x00FF;
  Enemy_MotherBrain *E = Get_MotherBrain(0);
  uint16 left_edge_gradient = kAbsTanTable[(uint8)-LOBYTE(E->rainbow_beam_left_edge_angle)];
  uint16 right_edge_gradient = kAbsTanTable[LOBYTE(E->rainbow_beam_right_edge_angle)];
  uint16 beam_y_pos = E->rainbow_beam_origin_y_pos;
  uint16 num_pad_lines = beam_y_pos - 32;
  uint16 *dst = hdma_table_2 + num_pad_lines + 1;
  dst[1] = 0x00FF;
  dst[2] = 0x00FF;

  for (beam_y_pos; beam_y_pos > 32; beam_y_pos--) {
    left_edge_origin_x_pos = IntMax(0, left_edge_origin_x_pos - left_edge_gradient);
    right_edge_origin_x_pos = IntMin(UINT16_MAX, right_edge_origin_x_pos + right_edge_gradient);

    uint16 hdma_entry = (right_edge_origin_x_pos & 0xFF00) | (left_edge_origin_x_pos / 0x100);
    if (hdma_entry == 0xFFFF)
      hdma_entry = 0x00FF;
    *dst-- = hdma_entry;
  }
}

/**
* @brief Calcualte the HDMA tables for Mother Brain's rainbow beam aimed towards the top left
*/
void MotherBrain_CalcHdma_Up_UpLeft(uint16 left_edge_origin_x_pos, uint16 right_edge_origin_x_pos) {  // 0xADE124
  hdma_table_2[0] = 0xFF;
  hdma_table_2[1] = 0xFF;
  Enemy_MotherBrain *E = Get_MotherBrain(0);
  uint16 left_edge_gradient = kAbsTanTable[(uint8)-LOBYTE(E->rainbow_beam_left_edge_angle)];
  uint16 right_edge_gradient = kAbsTanTable[(uint8)-LOBYTE(E->rainbow_beam_right_edge_angle)];
  uint16 beam_y_pos = E->rainbow_beam_origin_y_pos;
  uint16 num_pad_lines = beam_y_pos - 32;
  uint16 *dst = hdma_table_2 + num_pad_lines + 1;
  dst[1] = 0x00FF;
  dst[2] = 0x00FF;

  for (beam_y_pos; beam_y_pos > 32; beam_y_pos--) {
    left_edge_origin_x_pos = IntMax(0, left_edge_origin_x_pos - left_edge_gradient);
    right_edge_origin_x_pos = IntMax(0, right_edge_origin_x_pos - right_edge_gradient);

    uint16 hdma_entry = (right_edge_origin_x_pos & 0xFF00) | (left_edge_origin_x_pos / 0x100);
    if (hdma_entry == 0xFFFF)
      hdma_entry = 0x00FF;
    *dst-- = hdma_entry;
  }
}

static Func_CalcHdma *const kMotherBrain_CalcHdma_DownFuncs[4] = {
  MotherBrain_CalcHdma_Down_DownRight, 0,
  MotherBrain_CalcHdma_Down_Down,      MotherBrain_CalcHdma_Down_DownLeft
};

/**
* @brief Calculate the HDMA tables and setup the indirect HDMA for Mother Brain's rainbow beam aimed towards the bottom
*/
void MotherBrain_CalcHdma_BeamAimedDown(void) {  // 0xADE1A6
  Enemy_MotherBrain *E = Get_MotherBrain(0);

  // 0 is right half, 1 is left half
  uint16 right_edge_quadrant = (E->rainbow_beam_right_edge_angle >> 6) & 2;
  uint16 left_edge_quadrant = (E->rainbow_beam_left_edge_angle >> 7) & 1;
  uint16 quadrant_idx = right_edge_quadrant | left_edge_quadrant;
  kMotherBrain_CalcHdma_DownFuncs[quadrant_idx](E->rainbow_beam_left_origin_x_pos, E->rainbow_beam_right_origin_x_pos);

  mother_brain_indirect_hdma[0] = 0x10;
  WORD(mother_brain_indirect_hdma[1]) = 0x9C00;

  mother_brain_indirect_hdma[3] = 0x10;
  WORD(mother_brain_indirect_hdma[4]) = 0x9C03;

  mother_brain_indirect_hdma[6] = 0xF0;
  WORD(mother_brain_indirect_hdma[7]) = 0x9D04;

  mother_brain_indirect_hdma[9] = 0xF4;
  WORD(mother_brain_indirect_hdma[10]) = 0x9DE6;

  WORD(mother_brain_indirect_hdma[12]) = 0;
}

/**
* @brief Calcualte the HDMA tables for Mother Brain's rainbow beam aimed towards the bottom right
*/
void MotherBrain_CalcHdma_Down_DownRight(uint16 right_edge_origin_x_pos, uint16 left_edge_origin_x_pos) {  // 0xADE216
  hdma_table_2[0] = 0xFF;
  hdma_table_2[1] = 0xFF;
  Enemy_MotherBrain *E = Get_MotherBrain(0);
  uint16 right_edge_gradient = kAbsTanTable[LOBYTE(E->rainbow_beam_right_edge_angle)];
  uint16 left_edge_gradient = kAbsTanTable[LOBYTE(E->rainbow_beam_left_edge_angle)];
  uint16 beam_y_pos = E->rainbow_beam_origin_y_pos;
  uint16 num_pad_lines = beam_y_pos - 32;
  uint16 *dst = hdma_table_2 + 2;
  memset7E(dst, 0x00FF, num_pad_lines * 2);
  dst += num_pad_lines;

  for (beam_y_pos; beam_y_pos < 232; beam_y_pos++) {
    right_edge_origin_x_pos = IntMin(UINT16_MAX, right_edge_origin_x_pos + right_edge_gradient);
    left_edge_origin_x_pos = IntMin(UINT16_MAX, left_edge_origin_x_pos + left_edge_gradient);

    uint16 hdma_entry = (left_edge_origin_x_pos & 0xFF00) | (right_edge_origin_x_pos / 0x100);
    if (hdma_entry == 0xFFFF)
      hdma_entry = 0x00FF;
    *dst++ = hdma_entry;
  }
}

/**
* @brief Calcualte the HDMA tables for Mother Brain's rainbow beam aimed towards the bottom
*/
void MotherBrain_CalcHdma_Down_Down(uint16 right_edge_origin_x_pos, uint16 left_edge_origin_x_pos) {  // 0xADE293
  hdma_table_2[0] = 0xFF;
  hdma_table_2[1] = 0xFF;
  Enemy_MotherBrain *E = Get_MotherBrain(0);
  uint16 right_edge_gradient = kAbsTanTable[(uint8)-LOBYTE(E->rainbow_beam_right_edge_angle)];
  uint16 left_edge_gradient = kAbsTanTable[LOBYTE(E->rainbow_beam_left_edge_angle)];
  uint16 beam_y_pos = E->rainbow_beam_origin_y_pos;
  uint16 num_pad_lines = beam_y_pos - 32;
  uint16 *dst = hdma_table_2 + 2;
  memset7E(dst, 0x00FF, num_pad_lines * 2);
  dst += num_pad_lines;

  for (beam_y_pos; beam_y_pos < 232; beam_y_pos++) {
    right_edge_origin_x_pos = IntMax(0, right_edge_origin_x_pos - right_edge_gradient);
    left_edge_origin_x_pos = IntMin(UINT16_MAX, left_edge_origin_x_pos + left_edge_gradient);

    uint16 hdma_entry = (left_edge_origin_x_pos & 0xFF00) | (right_edge_origin_x_pos / 0x100);
    if (hdma_entry == 0xFFFF)
      hdma_entry = 0x00FF;
    *dst++ = hdma_entry;
  }
}

/**
* @brief Calcualte the HDMA tables for Mother Brain's rainbow beam aimed towards the bottom left
*/
void MotherBrain_CalcHdma_Down_DownLeft(uint16 right_edge_origin_x_pos, uint16 left_edge_origin_x_pos) {  // 0xADE314
  hdma_table_2[0] = 0xFF;
  hdma_table_2[1] = 0xFF;
  Enemy_MotherBrain *E = Get_MotherBrain(0);
  uint16 right_edge_gradient = kAbsTanTable[(uint8)-LOBYTE(E->rainbow_beam_right_edge_angle)];
  uint16 left_edge_gradient = kAbsTanTable[(uint8)-LOBYTE(E->rainbow_beam_left_edge_angle)];
  uint16 beam_y_pos = E->rainbow_beam_origin_y_pos;
  uint16 num_pad_lines = beam_y_pos - 32;
  uint16 *dst = hdma_table_2 + 2;
  memset7E(dst, 0x00FF, num_pad_lines * 2);
  dst += num_pad_lines;

  for (beam_y_pos; beam_y_pos < 232; beam_y_pos++) {
    right_edge_origin_x_pos = IntMax(0, right_edge_origin_x_pos - right_edge_gradient);
    left_edge_origin_x_pos = IntMax(0, left_edge_origin_x_pos - left_edge_gradient);
    uint16 hdma_entry = (left_edge_origin_x_pos & 0xFF00) | (right_edge_origin_x_pos / 0x100);
    if (hdma_entry == 0x0000)
      hdma_entry = 0x00FF;
    *dst++ = hdma_entry;
  }
}

/**
* @brief Spawns dust and the PLMs to seal the wall up
*/
void MotherBrain_SealWall(void) {  // 0xADE396
  eproj_spawn_pt = (Point16U){ 248, 72 };
  SpawnEprojWithRoomGfx(addr_kEproj_DustCloudExplosion, 9);
  eproj_spawn_pt = (Point16U){ 248, 152 };
  SpawnEprojWithRoomGfx(addr_kEproj_DustCloudExplosion, 9);
  SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { .x_pos = 15, .y_pos = 4, .plm_id_ = addr_kPlmHeader_B673_MotherBrainsRoom_FillWall });
  SpawnHardcodedPlm((SpawnHardcodedPlmArgs) { .x_pos = 15, .y_pos = 9, .plm_id_ = addr_kPlmHeader_B673_MotherBrainsRoom_FillWall });
  Get_MotherBrain(0)->enemy_func = FUNC16(MotherBrainBody_FakeDeath_Descent_0_Pause);
}

/**
* @brief Sets Mother Brain's palette based on the remaining health
*/
void MotherBrain_HealthBasedPaletteHandling(void) {  // 0xADE3D5
  // If Mother Brain is no longer a corpse
  if (Get_MotherBrain(0)->phase2_corpse_state >= 2) {
    uint16 pal_offset = 0;
    uint16 health = Get_MotherBrain(0x40)->base.health;
    if (health < 9000) {
      pal_offset = 2;
      if (health < 5400) {
        pal_offset = 4;
        if (health < 1800)
          pal_offset = 6;
      }
    }
    WriteColorsToPalette(PAL_RAM_OFFSET(palette_buffer.bg1_bg2_pal_4[1]), 0xad, kMotherBrain_HealthBasedPalettes_Brain[pal_offset >> 1], 15);
    WriteColorsToPalette(PAL_RAM_OFFSET(palette_buffer.sprite_pal_1[1]), 0xad, kMotherBrain_HealthBasedPalettes_Brain[pal_offset >> 1], 15);
    WriteColorsToPalette(PAL_RAM_OFFSET(palette_buffer.sprite_pal_3[1]), 0xad, kMotherBrain_HealthBasedPalettes_BackLeg[pal_offset >> 1], 15);
  }
}

/**
* @brief Fades Mother Brain's palette to black during the real body death sequence
* @param fade_idx The index into the array of pointers to the palettes
* @return 1 if finished fading, 0 otherwise
*/
uint8 MotherBrain_FadePalToBlack(uint16 fade_idx) {  // 0xADE9B4
  uint16 pal_ptr = kMotherBrain_FadePalToBlack[fade_idx];
  if (pal_ptr == 0)
    return 1;

  WriteColorsToPalette(PAL_RAM_OFFSET(palette_buffer.bg1_bg2_pal_4[1]), 0xad, pal_ptr, 14);
  WriteColorsToPalette(PAL_RAM_OFFSET(palette_buffer.sprite_pal_1[1]), 0xad, pal_ptr, 14);
  WriteColorsToPalette(PAL_RAM_OFFSET(palette_buffer.sprite_pal_3[1]), 0xad, pal_ptr + 28, 14);
  return 0;
}

/**
* @brief Fades Mother Brain's palette to gray during the descent into the fake death
* @param fade_idx The index into the array of pointers to the palettes
* @return 1 if finished fading, 0 otherwise
*/
uint8 MotherBrain_FadeToGray_FakeDeath(uint16 fade_idx) {  // 0xADEEDE
  uint16 pal_ptr = kMotherBrain_TransitionToFromGrey_Incr[fade_idx];
  if (pal_ptr == 0)
    return 1;

  return MotherBrain_FadeToFromGray_FakeDeath(pal_ptr);
}

/**
* @brief Fades Mother Brain's palette from gray during the ascent from the fake death
* @param fade_idx The index into the array of pointers to the palettes
* @return 1 if finished fading, 0 otherwise
*/
uint8 MotherBrain_FadeFromGray_FakeDeath(uint16 fade_idx) {  // 0xADEEEA
  uint16 pal_ptr = kMotherBrain_TransitionToFromGrey_Decr[fade_idx];
  if (pal_ptr == 0)
    return 1;

  return MotherBrain_FadeToFromGray_FakeDeath(pal_ptr);
}

/**
* @brief Fades Mother Brain's palette to or from gray during the fake death transitions
* @param pal_ptr The pointer to the palette
* @return 0, indicating the palette is not finished fading
*/
uint8 MotherBrain_FadeToFromGray_FakeDeath(uint16 pal_ptr) {  // 0xADEEF6
  WriteColorsToPalette(PAL_RAM_OFFSET(palette_buffer.sprite_pal_1[1]), 0xad, pal_ptr, 3);
  return 0;
}

/**
* @brief Fades Mother Brain's palette from gray while Mother Brain is reviving
* @param fade_idx The index into the array of pointers to the palettes
* @return 1 if finished fading, 0 otherwise
*/
uint8 MotherBrain_FadeFromGray_Drained(uint16 fade_idx) {  // 0xADEF0D
  uint16 pal_ptr = kMotherBrain_TransitionToFromGrey_Decr[fade_idx];
  if (pal_ptr == 0)
    return 1;
  
  WriteColorsToPalette(PAL_RAM_OFFSET(palette_buffer.bg1_bg2_pal_4[1]), 0xad, pal_ptr, 13);
  WriteColorsToPalette(PAL_RAM_OFFSET(palette_buffer.sprite_pal_1[1]), 0xad, pal_ptr, 13);
  WriteColorsToPalette(PAL_RAM_OFFSET(palette_buffer.sprite_pal_3[4]), 0xad, pal_ptr + 26, 5);
  /*
  * @bug Should be writing to RAM 0xC17C, which is palette_buffer.sprite_pal_3[14],
  * but accidentally writes to RAM 0x17C, which is in the middle of vram_write_queue
  */
  WORD(g_ram[0x17C]) = GET_WORD(RomPtr_AD(pal_ptr + 36));
  return 0;
}

/**
* @brief Fades Mother Brain's body palette to gray while the Shitroid is finishing draining Mother Brain
* @param fade_idx The index into the array of pointers to the palettes
* @return 1 if finished fading, 0 otherwise
*/
uint8 MotherBrain_FadeToGray_Drained(uint16 fade_idx) {  // 0xADEF4A
  uint16 pal_ptr = kMotherBrain_FadeToGray_Drained[fade_idx];
  if (pal_ptr == 0)
    return 1;

  WriteColorsToPalette(PAL_RAM_OFFSET(palette_buffer.bg1_bg2_pal_4[1]), 0xad, pal_ptr, 15);
  WriteColorsToPalette(PAL_RAM_OFFSET(palette_buffer.sprite_pal_1[1]), 0xad, pal_ptr, 15);
  WriteColorsToPalette(PAL_RAM_OFFSET(palette_buffer.sprite_pal_3[4]), 0xad, pal_ptr + 30, 5);
  /*
  * @bug Should be writing to RAM 0xC17C, which is palette_buffer.sprite_pal_3[14],
  * but accidentally writes to RAM 0x17C, which is in the middle of vram_write_queue
  */
  WORD(g_ram[0x17C]) = GET_WORD(RomPtr_AD(pal_ptr + 40));
  return 0;
}

/**
* @brief Fades Mother Brain's palette to gray during the real death sequence
* @param fade_idx The index into the array of pointers to the palettes
* @return 1 if finished fading, 0 otherwise
*/
uint8 MotherBrain_FadeToGray_RealDeath(uint16 fade_idx) {  // 0xADF0E9
  uint16 pal_ptr = kMotherBrain_FadeToGray_RealDeath[fade_idx];
  if (pal_ptr == 0)
    return 1;

  WriteColorsToPalette(PAL_RAM_OFFSET(palette_buffer.sprite_pal_7[1]), 0xad, pal_ptr, 15);
  return 0;
}

/**
* @brief Sets the background and level to black during the Shitroid death sequence
*/
void TurnOffLightsForShitroidDeath(void) {  // 0xADF209
  uint16 pal_ptr = addr_kTurnOffLightsForShitroidDeath;
  WriteColorsToPalette(PAL_RAM_OFFSET(palette_buffer.bg1_bg2_pal_3[1]), 0xad, pal_ptr, 14);
  WriteColorsToPalette(PAL_RAM_OFFSET(palette_buffer.bg1_bg2_pal_5[1]), 0xad, pal_ptr, 14);
}

/**
* @brief Restores the background and level palettes after the Shitroid death sequence
* @param fade_idx The index into the array of pointers to the palettes
* @return 1 if finished fading, 0 otherwise
*/
uint8 MotherBrain_Phase3_TurnLightsBackOn(uint16 fade_idx) {  // 0xADF24B
  uint16 pal_ptr = kMotherBrain_Phase3_TurnLightsBackOn[fade_idx];
  if (pal_ptr == 0)
    return 1;

  WriteColorsToPalette(PAL_RAM_OFFSET(palette_buffer.bg1_bg2_pal_3[1]), 0xad, pal_ptr, 14);
  WriteColorsToPalette(PAL_RAM_OFFSET(palette_buffer.bg1_bg2_pal_5[1]), 0xad, pal_ptr + 28, 14);
  return 0;
}

/**
* @brief Sets the earthquake to the specified type for 20 frames
* @param earthquake The earthquake type
*/
void EnableEarthquakeTypeAFor20Frames(uint16 earthquake) {  // 0xADF40B
  earthquake_type = earthquake;
  earthquake_timer = 20;
  QueueSfx2_Max6(kSfx2_BigExplosion);
}

/**
* @brief Flickers Mother Brain's body every other frame
*/
void HandleMotherBrainBodyFlickering(void) {  // 0xADF41C
  Enemy_MotherBrain* E = Get_MotherBrain(0);
  if (E->base.frame_counter & 1) {
    reg_TM |= 2;
    E->base.properties &= ~kEnemyProps_Invisible;
  }
  else {
    reg_TM &= ~2;
    E->base.properties |= kEnemyProps_Invisible;
  }
}
