// SRAM, spritemap processing & menus

#include <string.h>

#include "sm_rtl.h"
#include "ida_types.h"
#include "variables.h"
#include "funcs.h"
#include "enemy_types.h"
#include "sm_81.h"


void SoftReset(void) {
  game_state = 0xffff;
}

/**
* @brief Saves the current game progress to SRAM
* @param selected_save_slot_ The current save slot
*/
void SaveToSram(uint16 selected_save_slot_) {  // 0x818000
  uint16 save_data;

  uint16 checksum_value = 0;
  uint16 save_slot_idx = 2 * (selected_save_slot_ & 3);

  int player_data_size = ADDR16_OF_RAM_OFFSET(*events_that_happened, *player_data_saved);
  MemCpy(player_data_saved, &equipped_items, player_data_size);

  uint16 area_map_tiles_size = ADDR16_OF_RAM_OFFSET(layer1_x_block, *map_tiles_explored);
  uint16 area_map_tiles_offset = (area_index * area_map_tiles_size) >> 1;
  MemCpy(explored_map_tiles_saved + area_map_tiles_offset, map_tiles_explored, area_map_tiles_size);

  PackMapToSave();
  sram_save_station_index = load_station_index;
  sram_area_index = area_index;

  uint16 sram_save_slot_offset = kOffsetToSaveSlot[save_slot_idx >> 1];
  uint16 *save_data_ptr = player_data_saved;
  do {
    save_data = *save_data_ptr++;
    WORD(g_sram[sram_save_slot_offset]) = save_data;
    checksum_value += save_data;
    sram_save_slot_offset += 2;
  } while (save_data_ptr != plm_instruction_timer);

  int idx = save_slot_idx >> 1;
  kSramChecksum[idx] = checksum_value;
  kSramChecksumUpper[idx] = checksum_value;

  uint16 checksum_complement_value = ~checksum_value;
  kSramChecksumInverted[idx] = checksum_complement_value;
  kSramChecksumInvertedUpper[idx] = checksum_complement_value;

  RtlWriteSram();
}

/**
* @brief Loads the saved game progress from SRAM
* @param selected_save_slot_ The current save slot
* @return uint8 1 if save file is cleared, else 0
*/
uint8 LoadFromSram(uint16 selected_save_slot_) {  // 0x818085
  uint16 save_data;

  uint16 checksum_value = 0;
  uint16 save_slot_idx = 2 * (selected_save_slot_ & 3);

  uint16 sram_save_slot_offset = kOffsetToSaveSlot[save_slot_idx >> 1];
  uint16 *save_data_ptr = player_data_saved;
  do {
    save_data = WORD(g_sram[sram_save_slot_offset]);
    *save_data_ptr++ = save_data;
    checksum_value += save_data;
    sram_save_slot_offset += 2;
  } while (save_data_ptr != plm_instruction_timer);

  // If the calculated checksum matches the stored checksum, load save file
  int idx = save_slot_idx >> 1;
  if (checksum_value == kSramChecksum[idx] && (checksum_value ^ 0xffff) == kSramChecksumInverted[idx]
      || checksum_value == kSramChecksumUpper[idx] && (checksum_value ^ 0xffff) == kSramChecksumInvertedUpper[idx]) {
    int player_data_size = ADDR16_OF_RAM_OFFSET(*events_that_happened, *player_data_saved);
    MemCpy(&equipped_items, player_data_saved, player_data_size);

    UnpackMapFromSave();
    load_station_index = sram_save_station_index;
    area_index = sram_area_index;
    return 0;
  }
  // Else, clear save file
  else {
    sram_save_slot_offset = kOffsetToSaveSlot[save_slot_idx >> 1];
    int game_sram_size = ADDR16_OF_RAM_OFFSET(*plm_instruction_timer, *player_data_saved);
    memset7E((uint16*)(g_sram + sram_save_slot_offset), 0, game_sram_size);
    load_station_index = 0;
    area_index = 0;
    return 1;
  }
}

/**
* @brief Load saved map data for each area
*/
void UnpackMapFromSave(void) {  // 0x8182E4
  memset7E(explored_map_tiles_saved, 0, 0x700 + 2);
  for(int area_idx = kArea_0_Crateria; area_idx < kArea_6_Ceres; area_idx++) {
    int area_map_size = kMapRoomData_AreaSize[area_idx];
    const uint8 *area_map_room_ptr = kMapRoomData[area_idx];
    int saved_area_map_offset = kMapRoomData_AreaOffset[area_idx];
    uint16 area_map_tiles_size = ADDR16_OF_RAM_OFFSET(layer1_x_block, *map_tiles_explored);
    uint16 area_map_tiles_offset = area_idx * area_map_tiles_size;
    uint8 *unpacked = (uint8 *)explored_map_tiles_saved;
    do {
      uint16 area_map_room_tile_offset = area_map_tiles_offset + *area_map_room_ptr++;
      unpacked[area_map_room_tile_offset] = compressed_map_data[saved_area_map_offset++];
    } while (--area_map_size);
  }
}

/**
* @brief Save map data for each area
*/
void PackMapToSave(void) {  // 0x81834B
  for (int area_idx = kArea_0_Crateria; area_idx < kArea_6_Ceres; area_idx++) {
    int area_map_size = kMapRoomData_AreaSize[area_idx];
    const uint8 *area_map_room_data = kMapRoomData[area_idx];
    int saved_area_map_offset = kMapRoomData_AreaOffset[area_idx];
    uint16 area_map_tiles_size = ADDR16_OF_RAM_OFFSET(layer1_x_block, *map_tiles_explored);
    uint16 area_map_tiles_offset = area_idx * area_map_tiles_size;
    uint8 *unpacked = (uint8 *)explored_map_tiles_saved;
    do {
      uint16 area_map_room_tile_offset = area_map_tiles_offset + *area_map_room_data++;
      compressed_map_data[saved_area_map_offset++] = unpacked[area_map_room_tile_offset];
    } while (--area_map_size);
  }
}

/**
* @brief Draw a spritemap to the screen
* @param bank The bank of the pointer
* @param addr The address of the pointer
* @param sprmap_center_x_pos The spritemap center X position
* @param sprmap_center_y_pos The spritemap center Y position
* @param spr_pal The sprite palette, where the palette is * 0x200
*/
void DrawSpritemap(uint8 bank, uint16 addr, uint16 sprmap_center_x_pos, uint16 sprmap_center_y_pos, uint16 spr_pal) {  // 0x81879F
  const uint8 *sprmap_ptr = RomPtrWithBank(bank, addr);
  int num_entries = GET_WORD(sprmap_ptr);
  sprmap_ptr += 2;
  int idx = oam_next_ptr;
  for (; (num_entries != 0) && (idx < 0x200); num_entries--) {
    OamEnt *oam = gOamEnt(idx);
    int oam_x_coord = sprmap_center_x_pos + GET_WORD(sprmap_ptr);
    int oam_y_coord = (uint8)sprmap_center_y_pos + sprmap_ptr[2];
    // can this be simplified?
    if (!sign8(sprmap_ptr[2]) ? (oam_y_coord >= 14*16)
                              : ((oam_y_coord & 0x100) ? ((uint8)oam_y_coord >= 14*16) : ((uint8)oam_y_coord < 14*16)) )
      oam_x_coord = 24*16, oam_y_coord = 14*16;

    oam->xcoord = oam_x_coord;
    oam->ycoord = oam_y_coord;
    WORD(oam->charnum) = (GET_WORD(sprmap_ptr + 3) & 0xF1FF) | spr_pal;
    oam_ext[idx >> 5] |= (((oam_x_coord & 0x100) >> 8) | (*(int16 *)sprmap_ptr < 0) * 2) << (2 * ((idx >> 2) & 7));
    idx += 4;
    sprmap_ptr += 5;
  }
  oam_next_ptr = idx;
}

/**
* @brief Draw a spritemap off the screen
* @param addr The address of the pointer
* @param sprmap_center_x_pos The spritemap center X position
* @param sprmap_center_y_pos The spritemap center Y position
* @param spr_pal The sprite palette, where the palette is * 0x200
*/
void DrawSpritemapOffScreen(uint16 addr, uint16 sprmap_center_x_pos, uint16 sprmap_center_y_pos, uint16 spr_pal) {  // 0x818853
  const uint8 *sprmap_ptr = RomPtr_8C(addr);
  int num_entries = GET_WORD(sprmap_ptr);
  sprmap_ptr += 2;
  int idx = oam_next_ptr;
  for (; (num_entries != 0) && (idx < 0x200); num_entries--) {
    OamEnt *oam = gOamEnt(idx);
    int oam_x_coord = sprmap_center_x_pos + GET_WORD(sprmap_ptr);
    int oam_y_coord = (uint8)sprmap_center_y_pos + sprmap_ptr[2];
    // can this be simplified?
    if (!sign8(sprmap_ptr[2]) ? (oam_y_coord < 14*16)
                              : ((oam_y_coord & 0x100) ? ((uint8)oam_y_coord < 14*16) : ((uint8)oam_y_coord >= 14*16)) )
      oam_x_coord = 24*16, oam_y_coord = 14*16;
    oam->xcoord = oam_x_coord;
    oam->ycoord = oam_y_coord;
    WORD(oam->charnum) = (GET_WORD(sprmap_ptr + 3) & 0xF1FF) | spr_pal;
    oam_ext[idx >> 5] |= (((oam_x_coord & 0x100) >> 8) | (*(int16 *)sprmap_ptr < 0) * 2) << (2 * ((idx >> 2) & 7));
    idx += 4;
    sprmap_ptr += 5;
  }
  oam_next_ptr = idx;
}

/**
* @brief Draw a menu spritemap to the screen
* @param sprmap_idx The index into the spritemap table
* @param sprmap_center_x_pos The spritemap center X position
* @param sprmap_center_y_pos The spritemap center Y position
* @param spr_pal The sprite palette, where the palette is * 0x200
*/
void DrawMenuSpritemap(uint16 sprmap_idx, uint16 sprmap_center_x_pos, uint16 sprmap_center_y_pos, uint16 spr_pal) {  // 0x81891F
  const uint8 *sprmap_ptr = RomPtr_82(gMenuSpritemapTable[sprmap_idx]);
  int num_entries = GET_WORD(sprmap_ptr);
  sprmap_ptr += 2;
  int idx = oam_next_ptr;
  for (; num_entries != 0; num_entries--) {
    OamEnt *oam = gOamEnt(idx);
    int oam_x_coord = sprmap_center_x_pos + GET_WORD(sprmap_ptr);
    int oam_y_coord = sprmap_center_y_pos + sprmap_ptr[2];
    oam->xcoord = oam_x_coord;
    oam->ycoord = oam_y_coord;
    WORD(oam->charnum) = (GET_WORD(sprmap_ptr + 3) & 0xF1FF) | spr_pal;
    oam_ext[idx >> 5] |= (((oam_x_coord & 0x100) >> 8) | (*(int16 *)sprmap_ptr < 0) * 2) << (2 * ((idx >> 2) & 7));
    sprmap_ptr += 5;
    idx = (idx + 4) % 0x200;
  }
  oam_next_ptr = idx;
}

/**
* @brief Draw a Samus spritemap to the screen
* @param sprmap_idx The index into the spritemap table
* @param sprmap_center_x_pos The spritemap center X position
* @param sprmap_center_y_pos The spritemap center Y position
*/
void DrawSamusSpritemap(uint16 sprmap_idx, uint16 sprmap_center_x_pos, uint16 sprmap_center_y_pos) {  // 0x8189AE
  if (kSamusSpritemapTable[sprmap_idx] == 0)
    return;

  const uint8 *sprmap_ptr = RomPtr_92(kSamusSpritemapTable[sprmap_idx]);
  int idx = oam_next_ptr;
  int num_entries = GET_WORD(sprmap_ptr);
  sprmap_ptr += 2;
  for(; num_entries != 0; num_entries--) {
    OamEnt *oam = gOamEnt(idx);
    int oam_x_coord = sprmap_center_x_pos + GET_WORD(sprmap_ptr);
    int oam_y_coord = sprmap_center_y_pos + sprmap_ptr[2];
    oam->xcoord = oam_x_coord;
    oam->ycoord = oam_y_coord;
    WORD(oam->charnum) = GET_WORD(sprmap_ptr + 3);
    oam_ext[idx >> 5] |= (((oam_x_coord & 0x100) >> 8) | (*(int16 *)sprmap_ptr < 0) * 2) << (2 * ((idx >> 2) & 7));
    sprmap_ptr += 5;
    idx = (idx + 4) % 0x200;
  }
  oam_next_ptr = idx;
}

/**
* @brief Draw a flare spritemap to the screen
* @param sprmap_idx The index into the spritemap table
* @param sprmap_center_x_pos The spritemap center X position
* @param sprmap_center_y_pos The spritemap center Y position
*/
void DrawBeamGrappleSpritemap(uint16 sprmap_idx, uint16 sprmap_center_x_pos, uint16 sprmap_center_y_pos) {  // 0x818A37
  DrawGrappleOrProjectileSpritemap(RomPtr_93(gFlareSpritemapTable[sprmap_idx]), sprmap_center_x_pos, sprmap_center_y_pos);
}

/**
* @brief Draw a projectile spritemap to the screen
* @param proj_idx The index of the current projectile
* @param sprmap_center_x_pos The spritemap center X position
* @param sprmap_center_y_pos The spritemap center Y position
*/
void DrawProjectileSpritemap(uint16 proj_idx, uint16 sprmap_center_x_pos, uint16 sprmap_center_y_pos) {  // 0x818A4B
  DrawGrappleOrProjectileSpritemap(RomPtr_93(projectile_spritemap_pointers[proj_idx >> 1]), sprmap_center_x_pos, sprmap_center_y_pos);
}

/**
* @brief Draw a flare or projectile spritemap to the screen
* @param sprmap_ptr The pointer to the spritemap
* @param sprmap_center_x_pos The spritemap center X position
* @param sprmap_center_y_pos The spritemap center Y position
*/
void DrawGrappleOrProjectileSpritemap(const uint8 *sprmap_ptr, uint16 sprmap_center_x_pos, uint16 sprmap_center_y_pos) {  // 0x818A5F
  int idx = oam_next_ptr;
  int num_entries = GET_WORD(sprmap_ptr);
  sprmap_ptr += 2;
  for (; num_entries != 0; num_entries--) {
    OamEnt *oam = gOamEnt(idx);
    int oam_x_coord = sprmap_center_x_pos + GET_WORD(sprmap_ptr);
    int oam_y_coord = sprmap_center_y_pos + sprmap_ptr[2];
    oam->xcoord = oam_x_coord;
    oam->ycoord = oam_y_coord;
    WORD(oam->charnum) = GET_WORD(sprmap_ptr + 3);
    oam_ext[idx >> 5] |= (((oam_x_coord & 0x100) >> 8) | (*(int16 *)sprmap_ptr < 0) * 2) << (2 * ((idx >> 2) & 7));
    sprmap_ptr += 5;
    idx = (idx + 4) % 0x200;
  }
  oam_next_ptr = idx;
}

/**
* @brief Draw a spritemap to the screen with a base tile number
* @param bank The bank of the pointer
* @param addr The address of the pointer
* @param sprmap_center_x_pos The spritemap center X position
* @param sprmap_center_y_pos The spritemap center Y position
* @param spr_pal The sprite palette, where the palette is * 0x200
* @param base_tile The base tile number
*/
void DrawSpritemapWithBaseTile(uint8 bank, uint16 addr, uint16 sprmap_center_x_pos, uint16 sprmap_center_y_pos, uint16 spr_pal, uint16 base_tile) {  // 0x818AB8
  if (addr == 0)
    return; // bug fix

  uint8 *sprmap_ptr = (uint8 *)RomPtrWithBank(bank, addr);
  int idx = oam_next_ptr;
  int num_entries = GET_WORD(sprmap_ptr);
  sprmap_ptr += 2;
  for(; num_entries != 0; num_entries--) {
    OamEnt *oam = gOamEnt(idx);
    int oam_x_coord = sprmap_center_x_pos + GET_WORD(sprmap_ptr + 0);
    int oam_y_coord = sprmap_center_y_pos + sprmap_ptr[2];
    oam->xcoord = oam_x_coord;
    oam->ycoord = oam_y_coord;
    WORD(oam->charnum) = (base_tile + GET_WORD(sprmap_ptr + 3)) | spr_pal;
    oam_ext[idx >> 5] |= (((oam_x_coord & 0x100) >> 8) | (*(int16 *)sprmap_ptr < 0) * 2) << (2 * ((idx >> 2) & 7));
    sprmap_ptr += 5;
    idx = (idx + 4) % 0x200;
  }
  oam_next_ptr = idx;
}

/**
* @brief Draw a spritemap to the screen with a base tile number
* @param bank The bank of the pointer
* @param addr The address of the pointer
* @param sprmap_center_x_pos The spritemap center X position
* @param sprmap_center_y_pos The spritemap center Y position
* @param spr_pal The sprite palette, where the palette is * 0x200
* @param base_tile The base tile number
*/
void DrawSpritemapWithBaseTile2(uint8 bank, uint16 addr, uint16 sprmap_center_x_pos, uint16 sprmap_center_y_pos, uint16 spr_pal, uint16 base_tile) {  // 0x818B22
  const uint8 *sprmap_ptr = RomPtrWithBank(bank, addr);
  int idx = oam_next_ptr;
  int num_entries = GET_WORD(sprmap_ptr);
  sprmap_ptr += 2;
  for (; num_entries != 0; num_entries--) {
    OamEnt *oam = gOamEnt(idx);
    int oam_x_coord = sprmap_center_x_pos + GET_WORD(sprmap_ptr);
    int oam_y_coord = (uint8)sprmap_center_y_pos + sprmap_ptr[2];
    oam->xcoord = oam_x_coord;
    oam->ycoord = (!(oam_y_coord & 0x100) == !sign8(sprmap_ptr[2])) ? oam_y_coord : 0xf0;
    WORD(oam->charnum) = (base_tile + GET_WORD(sprmap_ptr + 3)) | spr_pal;
    oam_ext[idx >> 5] |= (((oam_x_coord & 0x100) >> 8) | (*(int16 *)sprmap_ptr < 0) * 2) << (2 * ((idx >> 2) & 7));
    sprmap_ptr += 5;
    idx = (idx + 4) % 0x200;
  }
  oam_next_ptr = idx;
}

/**
* @brief Draw a spritemap off the screen with a base tile number
* @param bank The bank of the pointer
* @param addr The address of the pointer
* @param sprmap_center_x_pos The spritemap center X position
* @param sprmap_center_y_pos The spritemap center Y position
* @param spr_pal The sprite palette, where the palette is * 0x200
* @param base_tile The base tile number
*/
void DrawSpritemapWithBaseTileOffscreen(uint8 bank, uint16 addr, uint16 sprmap_center_x_pos, uint16 sprmap_center_y_pos, uint16 spr_pal, uint16 base_tile) {  // 0x818B96
  const uint8 *sprmap_ptr = RomPtrWithBank(bank, addr);
  int idx = oam_next_ptr;
  int num_entries = GET_WORD(sprmap_ptr);
  sprmap_ptr += 2;
  for (; num_entries != 0; num_entries--) {
    OamEnt *oam = gOamEnt(idx);
    int oam_x_coord = sprmap_center_x_pos + GET_WORD(sprmap_ptr);
    int oam_y_coord = (uint8)sprmap_center_y_pos + sprmap_ptr[2];
    oam->xcoord = oam_x_coord;
    oam->ycoord = (!(oam_y_coord & 0x100) != !sign8(sprmap_ptr[2])) ? oam_y_coord : 0xf0;
    WORD(oam->charnum) = spr_pal | (base_tile + GET_WORD(sprmap_ptr + 3));
    oam_ext[idx >> 5] |= (((oam_x_coord & 0x100) >> 8) | (*(int16 *)sprmap_ptr < 0) * 2) << (2 * ((idx >> 2) & 7));
    sprmap_ptr += 5;
    idx = (idx + 4) % 0x200;
  }
  oam_next_ptr = idx;
}

/**
* @brief Draw an enemy projectile spritemap to the screen with a base tile number
* @param bank The bank of the pointer
* @param addr The address of the pointer
* @param sprmap_center_x_pos The spritemap center X position
* @param sprmap_center_y_pos The spritemap center Y position
* @param spr_pal The sprite palette, where the palette is * 0x200
* @param base_tile The base tile number
*/
void DrawEprojSpritemapWithBaseTile(uint8 bank, uint16 addr, uint16 sprmap_center_x_pos, uint16 sprmap_center_y_pos, uint16 spr_pal, uint16 base_tile) {  // 0x818C0A
  const uint8 *sprmap_ptr = RomPtrWithBank(bank, addr);
  int idx = oam_next_ptr;
  int num_entries = GET_WORD(sprmap_ptr);
  sprmap_ptr += 2;
  for (; num_entries != 0; num_entries--) {
    OamEnt *oam = gOamEnt(idx);
    int oam_x_coord = sprmap_center_x_pos + GET_WORD(sprmap_ptr);
    int oam_y_coord = (uint8)sprmap_center_y_pos + sprmap_ptr[2];
    oam->xcoord = oam_x_coord;
    oam->ycoord = (!(oam_y_coord & 0x100) == !sign8(sprmap_ptr[2])) ? oam_y_coord : 0xf0;
    WORD(oam->charnum) = base_tile | (spr_pal + GET_WORD(sprmap_ptr + 3));
    oam_ext[idx >> 5] |= (((oam_x_coord & 0x100) >> 8) | (*(int16 *)sprmap_ptr < 0) * 2) << (2 * ((idx >> 2) & 7));
    idx = (idx + 4) % 0x200;
    sprmap_ptr += 5;
  }
  oam_next_ptr = idx;
}

/**
* @brief Draw an enemy projectile spritemap off the screen with a base tile number
* @param bank The bank of the pointer
* @param addr The address of the pointer
* @param sprmap_center_x_pos The spritemap center X position
* @param sprmap_center_y_pos The spritemap center Y position
* @param spr_pal The sprite palette, where the palette is * 0x200
* @param base_tile The base tile number
*/
void DrawEprojSpritemapWithBaseTileOffscreen(uint8 bank, uint16 addr, uint16 sprmap_center_x_pos, uint16 sprmap_center_y_pos, uint16 spr_pal, uint16 base_tile) {  // 0x818C7F
  const uint8 *sprmap_ptr = RomPtrWithBank(bank, addr);
  int idx = oam_next_ptr;
  int num_entries = GET_WORD(sprmap_ptr);
  sprmap_ptr += 2;
  for (; num_entries != 0; num_entries--) {
    OamEnt *oam = gOamEnt(idx);
    int oam_x_coord = sprmap_center_x_pos + GET_WORD(sprmap_ptr);
    int oam_y_coord = (uint8)sprmap_center_y_pos + sprmap_ptr[2];
    oam->xcoord = oam_x_coord;
    oam->ycoord = (!(oam_y_coord & 0x100) != !sign8(sprmap_ptr[2])) ? oam_y_coord : 0xf0;
    WORD(oam->charnum) = base_tile | (spr_pal + GET_WORD(sprmap_ptr + 3));
    oam_ext[idx >> 5] |= (((oam_x_coord & 0x100) >> 8) | (*(int16 *)sprmap_ptr < 0) * 2) << (2 * ((idx >> 2) & 7));
    idx = (idx + 4) % 0x200;
    sprmap_ptr += 5;
  }
  oam_next_ptr = idx;
}

/**
* @brief Fade out the screen and set up menu graphics
*/
void GameOverMenu_0_FadeOutConfigGfx(void) {  // 0x818D0F
  HandleFadeOut();
  if ((reg_INIDISP & 0xF) == 0) {
    ScreenOff();
    QueueSfx3_Max6(kSfx3_Silence);
    DisableHdmaObjects();
    WaitUntilEndOfVblankAndClearHdma();
    MemCpy(ram3000.menu.palette_backup_in_menu, palette_buffer.pal, sizeof(Palettes));
    MemCpy(ram3000.menu.backup_of_io_registers_in_gameover, &reg_INIDISP, sizeof(ram3000.menu.backup_of_io_registers_in_gameover));
    MapVramForMenu();
    LoadInitialMenuTiles();
    reg_BG1HOFS = 0;
    reg_BG2HOFS = 0;
    reg_BG3HOFS = 0;
    reg_BG1VOFS = 0;
    reg_BG2VOFS = 0;
    reg_BG3VOFS = 0;
    LoadMenuPalettes();
    menu_index = kGameOverMenu_1_Initalize;
  }
}

/**
* @brief Fade in screen for debug game over menu
*/
void DebugGameOverMenu_2_4_FadeIn(void) {  // 0x818DA6
  HandleFadeIn();
  if ((reg_INIDISP & 0xF) == 15)
    ++menu_index;
}

/**
* @brief Set up VRAM for menu
*/
void MapVramForMenu(void) {  // 0x818DBA
  reg_TS = 0;
  reg_OBSEL = 0x2 | 0x1;
  reg_BG1SC = 0x40 | 0x10 | 0x1;
  reg_BG2SC = 0x40 | 0x10 | 0x8;
  reg_BG3SC = 0x40 | 0x10 | 0x8 | 0x4;
  reg_BG12NBA = 0;
  reg_BG34NBA = 4;
  reg_TM = 0x10 | 0x2 | 0x1;
}

/**
* @brief Load menu screen tiles to VRAM
*/
void LoadInitialMenuTiles(void) {  // 0x818DDB
  // Transfer menu tiles to VRAM 0x0000
  WriteRegWord(VMADDL, 0x0000);
  WriteReg(VMAIN, 0x80);
  static const StartDmaCopy kDmaCopy_MenuTiles = { .chan = 1, .dmap = 1, .bbad = 0x18, .a1 = LONGPTR(0x8e8000), .das = 0x5600 };
  SetupDmaTransfer(&kDmaCopy_MenuTiles);
  WriteReg(MDMAEN, 2);

  // Transfer first half of pause screen BG1 and BG2 tiles to VRAM 0x3000
  WriteRegWord(VMADDL, 0x3000);
  WriteReg(VMAIN, 0x80);
  static const StartDmaCopy kDmaCopy_FirstHalf_PauseScreenTiles_Bg1_Bg2 = { .chan = 1, .dmap = 1, .bbad = 0x18, .a1 = LONGPTR(0xb68000), .das = 0x2000 };
  SetupDmaTransfer(&kDmaCopy_FirstHalf_PauseScreenTiles_Bg1_Bg2);
  WriteReg(MDMAEN, 2);

  // Transfer menu and pause screen sprite tiles to VRAM 0x6000
  WriteRegWord(VMADDL, 0x6000);
  WriteReg(VMAIN, 0x80);
  static const StartDmaCopy kDmaCopy_MenuPauseScreenSpriteTiles = { .chan = 1, .dmap = 1, .bbad = 0x18, .a1 = LONGPTR(0xb6c000), .das = 0x2000 };
  SetupDmaTransfer(&kDmaCopy_MenuPauseScreenSpriteTiles);
  WriteReg(MDMAEN, 2);

  // Transfer area select BG3 map tiles to VRAM 0x4000
  WriteRegWord(VMADDL, 0x4000);
  WriteReg(VMAIN, 0x80);
  static const StartDmaCopy kDmaCopy_AreaSelectMapTiles_Bg3 = { .chan = 1, .dmap = 1, .bbad = 0x18, .a1 = LONGPTR(0x8ed600), .das = 0x0600 };
  SetupDmaTransfer(&kDmaCopy_AreaSelectMapTiles_Bg3);
  WriteReg(MDMAEN, 2);
}

/**
* @brief Load menu palettes
*/
void LoadMenuPalettes(void) {  // 0x818E60
  MemCpy(&palette_buffer, kMenuPalettes, sizeof(Palettes));
}

void DebugGameOverMenu_3_Main(void) {  // 0x819003
  if ((joypad1_newkeys & kButton_Select) || (joypad1_newkeys & kButton_Up) || (joypad1_newkeys & kButton_Down)) {
    file_select_map_area_index ^= 1;
  }
  else if (joypad1_newkeys & (kButton_B | kButton_Start | kButton_A)) {
    if (file_select_map_area_index) {
      menu_index = kDebugGameOverMenu_4_FadeToContinue;
    }
    else {
      SaveToSram(selected_save_slot);
      SoftReset();
    }
    return;
  }
  uint16 oam_y_coord = 0x78;
  if (file_select_map_area_index)
    oam_y_coord = 0x88;
  OamEnt *oam = gOamEnt(oam_next_ptr);
  oam->xcoord = 0x28;
  oam->ycoord = oam_y_coord;
  WORD(oam->charnum) = OAM_DATA(0, 0, 0, 0, 0xB6);
  oam_next_ptr += sizeof(OamEnt);
}

void RestorePalettesAndIoAfterDebugGameover(void) {  // 0x81905B
  MemCpy(&palette_buffer, ram3000.menu.palette_backup_in_menu, sizeof(Palettes));
  MemCpy(&reg_INIDISP, ram3000.menu.backup_of_io_registers_in_gameover, sizeof(ram3000.menu.backup_of_io_registers_in_gameover));
}

void DebugGameOverMenu_5_Continue(void) {  // 0x81907E
  // Transfer standard BG3 tiles, clear BG2 tiles to VRAM 0x4000
  WriteRegWord(VMADDL, 0x4000);
  WriteReg(VMAIN, 0x80);
  static const StartDmaCopy kDmaCopy_GameOver_StandardBg3Tiles_ClearBg2 = { .chan = 1, .dmap = 1, .bbad = 0x18, .a1 = LONGPTR(0x9ab200), .das = 0x2000 };
  SetupDmaTransfer(&kDmaCopy_GameOver_StandardBg3Tiles_ClearBg2);
  WriteReg(MDMAEN, 2);

  game_state = kGameState_16_Unpausing;
  file_select_map_area_index = 0;
  RestorePalettesAndIoAfterDebugGameover();
}

static Func_V *const kGameOverMenuFuncs[8] = {  // 0x8190AE
  GameOverMenu_0_FadeOutConfigGfx,
  GameOverMenu_1_Init,
  GameOverMenu_2_PlayMusic,
  GameOverMenu_3_FadeIn,
  GameOverMenu_4_Main,
  GameOverMenu_5_FadeOutToGameMap,
  GameOverMenu_6_LoadGameMapView,
  GameOverMenu_7_FadeOutToSoftReset,
};

/**
* @brief Run game over menu
*/
void GameOverMenu(void) {
  kGameOverMenuFuncs[menu_index]();
}

/**
* @brief Handle fade in to game over menu
*/
void GameOverMenu_3_FadeIn(void) {  // 0x8190CD
  HandleGameOverBabyMetroid();
  DrawMenuSelectionMissile();
  HandleFadeIn();
  if ((reg_INIDISP & 0xF) == 15)
    menu_index = kGameOverMenu_4_Main;
}

/**
* @brief Handle fade out from game over menu to game map (from continue)
*/
void GameOverMenu_5_FadeOutToGameMap(void) {  // 0x8190E7
  HandleGameOverBabyMetroid();
  DrawMenuSelectionMissile();
  HandleFadeOut();
  if ((reg_INIDISP & 0xF) == 0)
    menu_index = kGameOverMenu_6_LoadGameMapView;
}

/**
* @brief Handle fade out from game over menu to soft reset (from quit)
*/
void GameOverMenu_7_FadeOutToSoftReset(void) {  // 0x8190FE
  DrawMenuSelectionMissile();
  HandleGameOverBabyMetroid();
  HandleFadeOut();
  if ((reg_INIDISP & 0xF) == 0)
    SoftReset();
}

/**
* @brief Load game map after game over menu (from continue)
*/
void GameOverMenu_6_LoadGameMapView(void) {  // 0x819116
  DisableHdmaObjects();
  WaitUntilEndOfVblankAndClearHdma();
  game_state = kGameState_5_FileSelectMap;
  menu_index = kFileSelectMap_0_OptionsToAreaSelect_ClearBg2_SetUpFadeOut;
}

/**
* @brief Handle main game over menu selection
*/
void GameOverMenu_4_Main(void) {  // 0x81912B
  HandleGameOverBabyMetroid();
  DrawMenuSelectionMissile();
  if ((joypad1_newkeys & kButton_Select) || (joypad1_newkeys & kButton_Up) || (joypad1_newkeys & kButton_Down)) {
    QueueSfx1_Max6(kSfx1_MovedCursorToggleReserveMode);
    game_over_menu_selection ^= 1;
  }
  else if (joypad1_newkeys & kButton_A) {
    enemy_data[0].instruction_timer = 60*3;
    if (game_over_menu_selection == kGameOverMenuSelect_Yes) {
      if (loading_game_state == kLoadingGameState_1F_StartingAtCeres)
        game_state = loading_game_state;
      else /* loading_game_state != kLoadingGameState_1F_StartingAtCeres */
        menu_index = kGameOverMenu_5_FadeToGameMapView;
      LoadFromSram(selected_save_slot);
    }
    else { /* game_over_menu_selection == kGameOverMenuSelect_No */
      menu_index = kGameOverMenu_7_FadeToSoftReset;
    }
    return;
  }

  menu_selection_missile_x_pos = 2*16 + 8;
  menu_selection_missile_y_pos = (game_over_menu_selection == kGameOverMenuSelect_Yes) ? 10*16 : 12*16;
}

/**
* @brief Set up game over menu
*/
void GameOverMenu_1_Init(void) {  // 0x8191A4
  reg_TM = 0x10 | 0x1;
  reg_COLDATA[0] = 0x20;
  reg_COLDATA[1] = 0x40;
  reg_COLDATA[2] = 0x80;
  QueueMusic_Delayed8(kMusic_Stop);
  QueueMusic_Delayed8(kMusic_TitleSequence);
  menu_selection_missile_anim_timer = 1;
  menu_selection_missile_anim_frame = 0;

  // Set menu tilemap to 15 and transfer to VRAM BG1 tilemap
  memset7E((uint16*)ram3000.menu.menu_tilemap, 15, sizeof(ram3000.menu.menu_tilemap));
  VramWriteEntry *vram_entry = gVramWriteEntry(vram_write_queue_tail);
  vram_entry->size = sizeof(ram3000.menu.menu_tilemap);
  vram_entry->src.addr = ADDR16_OF_RAM(ram3000.menu.menu_tilemap);
  vram_entry->src.bank = 0x7E;
  vram_entry->vram_dst = (reg_BG1SC & 0xFC) << 8;
  vram_write_queue_tail += sizeof(VramWriteEntry);

  enemy_data[0].palette_index = 0;
  LoadMenuTilemap(MENU_TILEMAP_COORD(11, 5), addr_kMenuTilemap_GameOver);
  LoadMenuTilemap(MENU_TILEMAP_COORD(5, 14), addr_kMenuTilemap_FindMetroidLarva);
  LoadMenuTilemap(MENU_TILEMAP_COORD(10, 16), addr_kMenuTilemap_TryAgain);
  LoadMenuTilemap(MENU_TILEMAP_COORD(7, 19), addr_kMenuTilemap_YesReturnToGame);
  LoadMenuTilemap(MENU_TILEMAP_COORD(7, 23), addr_kMenuTilemap_NoGoToTitle);
  enemy_data[0].current_instruction = 0;
  enemy_data[0].instruction_timer = 0;
  HandleGameOverBabyMetroid();

  reg_CGWSEL = 0;
  DisableHdmaObjects();
  WaitUntilEndOfVblankAndClearHdma();
  EnableHdmaObjects();
  static const SpawnHdmaObject_Args kSpawnHdmaObject_819254 = {
    .hdma_control = HDMA_CONTROL(0, 0, 0),
    .hdma_target = REG(COLDATA),
    .hdma_instr_list_ptr = addr_kHdmaObject_IList_GameOverGradient_ColorMathSubBackdropColor
  };
  static const SpawnHdmaObject_Args kSpawnHdmaObject_81925C = {
    .hdma_control = HDMA_CONTROL(0, 0, 0),
    .hdma_target = REG(CGADSUB),
    .hdma_instr_list_ptr = addr_kHdmaObject_IList_GameOverGradient_ColorMathControlReg0
  };
  SpawnHdmaObject(0x81, &kSpawnHdmaObject_819254);
  SpawnHdmaObject(0x81, &kSpawnHdmaObject_81925C);
  ScreenOn();

  menu_index = kGameOverMenu_2_PlayPreStatueTrack;
  screen_fade_delay = 0;
  screen_fade_counter = 0;
  file_select_map_area_index = kGameOverMenuSelect_Yes;
  menu_selection_missile_x_pos = 2*16 + 8;
  menu_selection_missile_y_pos = 10*16;
}

/**
* @brief Play game over menu music
*/
void GameOverMenu_2_PlayMusic(void) {  // 0x8193E8
  if (!HasQueuedMusic()) {
    menu_index = kGameOverMenu_3_FadeToMain;
    QueueMusic_Delayed8(kMusic_PreStatueHall_PreRidleyFight_GameOver);
  }
}

static Func_V *const kFileSelectMenuFuncs[34] = {  // 0x8193FB
  FileSelectMenu_0_FadeOutConfigGfx,
  FileSelectMenu_1_LoadFileSelectMenuBG2,
  FileSelectMenu_2_InitMain,
  FileSelectMenu_3_FadeInToMain,
  FileSelectMenu_4_Main,
  FileSelectMenu_5_19_FadeOutFromMain,
  FileSelectMenu_6_FileCopyInit,
  FileSelectMenu_7_21_FadeInFromMain,
  FileSelectMenu_8_FileCopySelectSrc,
  FileSelectMenu_9_InitializeSelectDest,
  FileSelectMenu_10_FileCopySelectDest,
  FileSelectMenu_11_InitializeConfirm,
  FileSelectMenu_12_FileCopyConfirm,
  FileSelectMenu_13_FileCopyDoIt,
  FileSelectMenu_14_CopyCompleted,
  FileSelectMenu_15_27_FadeOutToMain,
  FileSelectMenu_16_28_ReloadMain,
  FileSelectMenu_17_29_FadeInToMain,
  FileSelectMenu_18_FileCopyMenuToMain,
  FileSelectMenu_5_19_FadeOutFromMain,
  FileSelectMenu_20_FileClearInit,
  FileSelectMenu_7_21_FadeInFromMain,
  FileSelectMenu_22_FileClearSelectSlot,
  FileSelectMenu_23_FileClearInitConfirm,
  FileSelectMenu_24_FileClearConfirm,
  FileSelectMenu_25_FileClearDoClear,
  FileSelectMenu_26_ClearCompleted,
  FileSelectMenu_15_27_FadeOutToMain,
  FileSelectMenu_16_28_ReloadMain,
  FileSelectMenu_17_29_FadeInToMain,
  FileSelectMenu_30_FileClearMenuToMain,
  FileSelectMenu_31_TurnSamusHelmet,
  FileSelectMenu_32_FadeOutToOptions,
  FileSelectMenu_33_FadeOutToTitle,
};

/**
* @brief Run file select menu
*/
void FileSelectMenu(void) {
  kFileSelectMenuFuncs[menu_index]();
}

/**
* @brief Fade out screen and set up menu graphics
*/
void FileSelectMenu_0_FadeOutConfigGfx(void) {  // 0x81944E
  HandleFadeOut();
  if ((reg_INIDISP & 0xF) != 0)
    return;

  ScreenOff();
  QueueSfx3_Max6(kSfx3_Silence);
  DisableHdmaObjects();
  WaitUntilEndOfVblankAndClearHdma();
  menu_index = kFileSelectMenu_1_TitleToMain_LoadBg2;
  MapVramForMenu();
  LoadInitialMenuTiles();
  reg_BG1HOFS = 0;
  reg_BG2HOFS = 0;
  reg_BG3HOFS = 0;
  reg_BG1VOFS = 0;
  reg_BG2VOFS = 0;
  reg_BG3VOFS = 0;
  LoadFileSelectPalettes();
}

/**
* @brief Load file select palette
*/
void LoadFileSelectPalettes(void) {  // 0x819486
  MemCpy(&palette_buffer, kMenuPalettes, sizeof(Palettes));

}

/**
* @brief Fade out file select menu to option menu
*/
void FileSelectMenu_32_FadeOutToOptions(void) {  // 0x8194A3
  DrawMenuSelectionMissile();
  DrawBorderAroundSamusData();
  DrawFileSelectSamusHelmets();
  HandleFadeOut();
  if ((reg_INIDISP & 0xF) == 0) {
    game_state = kGameState_2_GameOptionsMenu;
    menu_index = 0;
    int menu_selection_size = ADDR16_OF_RAM_OFFSET(menu_selection_file_destination_slot, menu_selection_missile_anim_timer) + 4;
    memset7E(&menu_selection_missile_anim_timer, 0, menu_selection_size);
  }
}

/**
* @brief Fade out file select menu to title screen
*/
void FileSelectMenu_33_FadeOutToTitle(void) {  // 0x8194D5
  DrawBorderAroundSamusData();
  DrawFileSelectSamusHelmets();
  HandleFadeOut();
  if ((reg_INIDISP & 0xF) == 0)
    SoftReset();
}

/**
* @brief Fade out to file select menu from main menu
*/
void FileSelectMenu_5_19_FadeOutFromMain(void) {  // 0x8194EE
  DrawMenuSelectionMissile();
  FileSelectMenu_15_27_FadeOutToMain();
}

/**
* @brief Fade out to main menu from file select menu
*/
void FileSelectMenu_15_27_FadeOutToMain(void) {  // 0x8194F4
  HandleFadeOut();
  reg_MOSAIC = (reg_MOSAIC & 0xF) | ((reg_INIDISP & 0xF) ^ 0xF) << 4;
  if ((reg_INIDISP & 0xF) == 0) {
    ScreenOff();
    ++menu_index;
  }
}

/**
* @brief Fade in to main menu from file select menu
*/
void FileSelectMenu_17_29_FadeInToMain(void) {  // 0x81951E
  menu_selection_missile_y_pos = kMenuSelectionMissileXY[selected_save_slot].y_pos;
  menu_selection_missile_x_pos = kMenuSelectionMissileXY[selected_save_slot].x_pos;
  FileSelectMenu_7_21_FadeInFromMain();
}

/**
* @brief Fade in to file select menu from main menu
*/
void FileSelectMenu_7_21_FadeInFromMain(void) {  // 0x819532
  DrawMenuSelectionMissile();
  HandleFadeIn();
  reg_MOSAIC = reg_MOSAIC & 0xF | (16 * (reg_INIDISP & 0xF)) ^ 0xF0;
  if ((reg_INIDISP & 0xF) == 15)
    ++menu_index;
}

/**
* @brief Initialize file copy in file select menu
*/
void FileSelectMenu_6_FileCopyInit(void) {  // 0x819561
  menu_index = kFileSelectMenu_7_MainToFileCopy_FadeIn;
  InitFileSelectMenuFileCopy();
}

/**
* @brief Initialize file copy in file select menu
*/
void InitFileSelectMenuFileCopy(void) {  // 0x819566
  ClearMenuTilemap();
  enemy_data[0].palette_index = 0;
  LoadMenuTilemap(MENU_TILEMAP_COORD(9, 1), addr_kMenuTilemap_DataCopyMode);
  LoadMenuTilemap(MENU_TILEMAP_COORD(8, 5), addr_kMenuTilemap_CopyWhichData);
  LoadMenuExitTilemap();
  DrawFileCopySaveFileInfo();
  SetInitialFileCopyClearMenuSelection();
  SetFileCopyMenuSelectionMissilePosition();
  menu_selection_file_copy_source_clear_slot = 0;
  menu_selection_file_destination_slot = 0;
}

void UNUSED_sub_819591(void) {  // 0x819591
  SetInitialFileCopyClearMenuSelection();
}

/**
* @brief Set the file copy/clear selection to the first non-empty save slot
*/
void SetInitialFileCopyClearMenuSelection(void) {  // 0x819593
  int non_empty_save_slots = nonempty_save_slots;
  int first_available_save_slot;
  for (first_available_save_slot = 0; first_available_save_slot < 3; first_available_save_slot++) {
    if (non_empty_save_slots & 1)
      break;
    non_empty_save_slots >>= 1;
  }
  menu_selection_file_copy_clear_select = first_available_save_slot;
}

/**
* @brief Clear the menu tilemap
*/
void ClearMenuTilemap(void) {  // 0x8195A6
  memset7E((uint16*)ram3000.menu.menu_tilemap, 15, sizeof(ram3000.menu.menu_tilemap));
}

/**
* @brief Load the tilemap for "EXIT" text when entering file copy/clear
*/
void LoadMenuExitTilemap(void) {  // 0x8195B5
  LoadMenuTilemap(MENU_TILEMAP_COORD(4, 26), addr_kMenuTilemap_Exit);
}

/**
* @brief Draw each save file info for file copy/clear
*/
void DrawFileCopySaveFileInfo(void) {  // 0x8195BE
  LoadFromSram_(0);
  enemy_data[0].palette_index = 0;
  if (!(nonempty_save_slots & 1))
    enemy_data[0].palette_index = 4 * 0x100;
  DrawFileCopySaveSlotAInfo();
  LoadFromSram_(1);
  enemy_data[0].palette_index = 0;
  if (!(nonempty_save_slots & 2))
    enemy_data[0].palette_index = 4 * 0x100;
  DrawFileCopySaveSlotBInfo();
  LoadFromSram_(2);
  enemy_data[0].palette_index = 0;
  if (!(nonempty_save_slots & 4))
    enemy_data[0].palette_index = 4 * 0x100;
  DrawFileCopySaveSlotCInfo();
  QueueTransferOfMenuTilemapToVramBG1();
}

/**
* @brief Draw save file A info for file copy/clear
*/
void DrawFileCopySaveSlotAInfo(void) {  // 0x81960F
  DrawFileSelectionHealth(!(nonempty_save_slots & 1), MENU_TILEMAP_COORD(12, 8));
  DrawFileSelectionTime(!(nonempty_save_slots & 1), MENU_TILEMAP_COORD(25, 9));
  LoadMenuTilemap(MENU_TILEMAP_COORD(26, 8), addr_kMenuTilemap_TIME);
  LoadMenuTilemap(MENU_TILEMAP_COORD(4, 8), addr_kMenuTilemap_SamusA);
}

/**
* @brief Draw save file B info for file copy/clear
*/
void DrawFileCopySaveSlotBInfo(void) {  // 0x81963F
  DrawFileSelectionHealth(~nonempty_save_slots & 2, MENU_TILEMAP_COORD(12, 12));
  DrawFileSelectionTime(~nonempty_save_slots & 2, MENU_TILEMAP_COORD(25, 13));
  LoadMenuTilemap(MENU_TILEMAP_COORD(26, 12), addr_kMenuTilemap_TIME);
  LoadMenuTilemap(MENU_TILEMAP_COORD(4, 12), addr_kMenuTilemap_SamusB);
}

/**
* @brief Draw save file C info for file copy/clear
*/
void DrawFileCopySaveSlotCInfo(void) {  // 0x81966F
  DrawFileSelectionHealth(~nonempty_save_slots & 4, MENU_TILEMAP_COORD(12, 16));
  DrawFileSelectionTime(~nonempty_save_slots & 4, MENU_TILEMAP_COORD(25, 17));
  LoadMenuTilemap(MENU_TILEMAP_COORD(26, 16), addr_kMenuTilemap_TIME);
  LoadMenuTilemap(MENU_TILEMAP_COORD(4, 16), addr_kMenuTilemap_SamusC);
}

/**
* @brief Transfer menu tilemap to VRAM BG1 tilemap
*/
void QueueTransferOfMenuTilemapToVramBG1(void) {  // 0x81969F
  // Transfer menu tilemap to VRAM BG1 tilemap
  VramWriteEntry *vram_entry = gVramWriteEntry(vram_write_queue_tail);
  vram_entry->size = sizeof(ram3000.menu.menu_tilemap);
  vram_entry->src.addr = ADDR16_OF_RAM(ram3000.menu.menu_tilemap);
  vram_entry->src.bank = 0x7E;
  vram_entry->vram_dst = (reg_BG1SC & 0xFC) << 8;
  vram_write_queue_tail += sizeof(VramWriteEntry);
}

/**
* @brief Handle selecting source file for file copy
*/
void FileSelectMenu_8_FileCopySelectSrc(void) {  // 0x8196C2
  int8 file_copy_selection;

  DrawBorderAroundDataCopyMode();
  DrawMenuSelectionMissile();
  if (joypad1_newkeys & (kButton_Start | kButton_A)) {
    QueueSfx1_Max6(kSfx1_MovedCursorToggleReserveMode);
    if (menu_selection_file_copy_clear_select == 3) {
      menu_index = kFileSelectMenu_15_FileCopyToMain_FadeOut;
    }
    else {
      menu_selection_file_copy_source_clear_slot = menu_selection_file_copy_clear_select;
      menu_index = kFileSelectMenu_9_FileCopy_InitalizeSelectDestination;
    }
  }
  else if (joypad1_newkeys & kButton_B) {
    menu_index = kFileSelectMenu_15_FileCopyToMain_FadeOut;
    QueueSfx1_Max6(kSfx1_MovedCursorToggleReserveMode);
  }
  else {
    // If press up, then move the cursor to the next available position up
    if (joypad1_newkeys & kButton_Up) {
      file_copy_selection = menu_selection_file_copy_clear_select;
      while (--file_copy_selection >= 0) {
        if ((nonempty_save_slots & (1 << file_copy_selection)) != 0) {
          LOBYTE(menu_selection_file_copy_clear_select) = file_copy_selection;
          QueueSfx1_Max6(kSfx1_MovedCursorToggleReserveMode);
          SetFileCopyMenuSelectionMissilePosition();
          return;
        }
      }
    }
    // If press down, then move the cursor to the next available position down
    else if (joypad1_newkeys & kButton_Down) {
      file_copy_selection = menu_selection_file_copy_clear_select;
      while (++file_copy_selection < 4) {
        if (file_copy_selection == 3 || (nonempty_save_slots & (1 << file_copy_selection)) != 0) {
          LOBYTE(menu_selection_file_copy_clear_select) = file_copy_selection;
          QueueSfx1_Max6(kSfx1_MovedCursorToggleReserveMode);
          SetFileCopyMenuSelectionMissilePosition();
          return;
        }
      }
    }
    SetFileCopyMenuSelectionMissilePosition();
  }
}

/**
* @brief Set missile position to one of the options in the file copy menu
*/
void SetFileCopyMenuSelectionMissilePosition(void) {  // 0x81975E
  static const uint16 kFileCopyMissileY[4] = { 72, 104, 136, 211 };

  menu_selection_missile_y_pos = kFileCopyMissileY[menu_selection_file_copy_clear_select];
  menu_selection_missile_x_pos = 22;
}

/**
* @brief Setup the destination selection for file copy
*/
void FileSelectMenu_9_InitializeSelectDest(void) {  // 0x81977A
  DrawBorderAroundDataCopyMode();
  DrawFileCopySelectDestinationSaveFileInfo();
  menu_index = kFileSelectMenu_10_FileCopy_SelectDestination;
  uint16 file_copy_dest_slot;
  // Get first available slot for the destination (i.e. first slot that isn't the source slot)
  for (file_copy_dest_slot = 0; file_copy_dest_slot < 3; file_copy_dest_slot++) {
    if (file_copy_dest_slot != menu_selection_file_copy_source_clear_slot)
      break;
  }
  menu_selection_file_copy_clear_select = file_copy_dest_slot;
  SetFileCopyMenuSelectionMissilePosition();
}

/**
* @brief Setup file copy destination drawing and file info
*/
void DrawFileCopySelectDestinationSaveFileInfo(void) {  // 0x819799
  ClearMenuTilemap();
  enemy_data[0].palette_index = 0;
  LoadMenuTilemap(MENU_TILEMAP_COORD(9, 1), addr_kMenuTilemap_DataCopyMode);
  enemy_data[0].palette_index = 0;
  LoadMenuTilemap(MENU_TILEMAP_COORD(4, 5), addr_kMenuTilemap_CopySamusToWhere);
  WORD(ram3000.menu.menu_tilemap[MENU_TILEMAP_COORD(16, 5)]) = 0x206A + menu_selection_file_copy_source_clear_slot;
  LoadMenuExitTilemap();

  LoadFromSram_(0);
  enemy_data[0].palette_index = (menu_selection_file_copy_source_clear_slot != 0) ? 0 : (4 * 0x100);
  DrawFileCopySaveSlotAInfo();

  LoadFromSram_(1);
  enemy_data[0].palette_index = (menu_selection_file_copy_source_clear_slot != 1) ? 0 : (4 * 0x100);
  DrawFileCopySaveSlotBInfo();

  LoadFromSram_(2);
  enemy_data[0].palette_index = (menu_selection_file_copy_source_clear_slot != 2) ? 0 : (4 * 0x100);
  DrawFileCopySaveSlotCInfo();

  QueueTransferOfMenuTilemapToVramBG1();
}

/**
* @brief Handle selecting destination for file copy
*/
void FileSelectMenu_10_FileCopySelectDest(void) {  // 0x819813
  static const uint16 kFileCopySelectDest_MissileY[4] = { 72, 104, 136, 212 };
  int16 file_copy_selection;

  DrawBorderAroundDataCopyMode();
  DrawMenuSelectionMissile();
  if (joypad1_newkeys & (kButton_Start | kButton_A)) {
    QueueSfx1_Max6(kSfx1_MovedCursorToggleReserveMode);
    if (menu_selection_file_copy_clear_select == 3) {
      menu_index = kFileSelectMenu_15_FileCopyToMain_FadeOut;
    }
    else {
      menu_selection_file_destination_slot = menu_selection_file_copy_clear_select;
      menu_index = kFileSelectMenu_11_FileCopy_InitalizeConfirmation;
      menu_selection_missile_y_pos = kFileCopySelectDest_MissileY[menu_selection_file_copy_clear_select];
      menu_selection_missile_x_pos = 22;
    }
  }
  else if (joypad1_newkeys & kButton_B) {
    menu_index = kFileSelectMenu_8_FileCopy_SelectSource;
    menu_selection_file_copy_clear_select = menu_selection_file_copy_source_clear_slot;
    QueueSfx1_Max6(kSfx1_MovedCursorToggleReserveMode);
    InitFileSelectMenuFileCopy();
  }
  else {
    // If press up, then move the cursor to the next available position up
    if (joypad1_newkeys & kButton_Up) {
      QueueSfx1_Max6(kSfx1_MovedCursorToggleReserveMode);
      file_copy_selection = menu_selection_file_copy_clear_select;
      while (--file_copy_selection >= 0) {
        if (file_copy_selection != menu_selection_file_copy_source_clear_slot) {
          menu_selection_file_copy_clear_select = file_copy_selection;
          menu_selection_missile_y_pos = kFileCopySelectDest_MissileY[menu_selection_file_copy_clear_select];
          menu_selection_missile_x_pos = 22;
          return;
        }
      }
    }
    // If press down, then move the cursor to the next available position down
    else if (joypad1_newkeys & kButton_Down) {
      QueueSfx1_Max6(kSfx1_MovedCursorToggleReserveMode);
      file_copy_selection = menu_selection_file_copy_clear_select;
      while (++file_copy_selection < 4) {
        if (file_copy_selection != menu_selection_file_copy_source_clear_slot) {
          menu_selection_file_copy_clear_select = file_copy_selection;
          menu_selection_missile_y_pos = kFileCopySelectDest_MissileY[menu_selection_file_copy_clear_select];
          menu_selection_missile_x_pos = 22;
          return;
        }
      }
    }
    menu_selection_missile_y_pos = kFileCopySelectDest_MissileY[menu_selection_file_copy_clear_select];
    menu_selection_missile_x_pos = 22;
  }
}

/**
* @brief Setup file copy confirmation drawing and file info
*/
void FileSelectMenu_11_InitializeConfirm(void) {  // 0x8198B7
  DrawBorderAroundDataCopyMode();
  enemy_data[0].palette_index = 0;
  LoadMenuTilemap(MENU_TILEMAP_COORD(2, 5), addr_kMenuTilemap_CopySamusToSamus);
  WORD(ram3000.menu.menu_tilemap[MENU_TILEMAP_COORD(14, 5)]) = 0x206A + menu_selection_file_copy_source_clear_slot;
  WORD(ram3000.menu.menu_tilemap[MENU_TILEMAP_COORD(27, 5)]) = 0x206A + menu_selection_file_destination_slot;
  DrawFileCopyClearConfirmation();
  menu_index = kFileSelectMenu_12_FileCopy_Confirmation;
  menu_selection_file_copy_clear_select = 0;
  menu_selection_file_copy_arrow_palette_timer = 8;
}

/**
* @brief Setup file copy/clear confirmation drawing and file info
*/
void DrawFileCopyClearConfirmation(void) {  // 0x8198ED
  enemy_data[0].palette_index = 0;
  LoadMenuTilemap(MENU_TILEMAP_COORD(10, 20), addr_kMenuTilemap_IsThisOk);
  enemy_data[0].palette_index = 0;
  LoadMenuTilemap(MENU_TILEMAP_COORD(14, 22), addr_kMenuTilemap_Yes);
  memset7E((uint16*)(ram3000.menu.menu_tilemap + MENU_TILEMAP_COORD(0, 26)), 15, 0x20);
  enemy_data[0].palette_index = 0;
  LoadMenuTilemap(MENU_TILEMAP_COORD(14, 25), addr_kMenuTilemap_No);
  DrawFileCopyConfirmationSaveFileInfo();
}

/**
* @brief Setup file copy/clear confirmation drawing and file info
*/
void DrawFileCopyConfirmationSaveFileInfo(void) {  // 0x819922
  LoadFromSram_(0);
  enemy_data[0].palette_index = (menu_selection_file_copy_source_clear_slot != 0 && menu_selection_file_destination_slot != 0)
                                ? (4 * 0x100) : 0;
  DrawFileCopySaveSlotAInfo();

  LoadFromSram_(1);
  enemy_data[0].palette_index = (menu_selection_file_copy_source_clear_slot != 1 && menu_selection_file_destination_slot != 1)
                                ? (4 * 0x100) : 0;
  DrawFileCopySaveSlotBInfo();

  LoadFromSram_(2);
  enemy_data[0].palette_index = (menu_selection_file_copy_source_clear_slot != 2 && menu_selection_file_destination_slot != 2)
                                ? (4 * 0x100) : 0;
  DrawFileCopySaveSlotCInfo();

  QueueTransferOfMenuTilemapToVramBG1();
}

/**
* @brief Handle drawing and initializing file copy
*/
void FileSelectMenu_12_FileCopyConfirm(void) {  // 0x819984
  DrawBorderAroundDataCopyMode();
  DrawMenuSelectionMissile();
  HandleFileCopyArrowPalette();
  DrawFileCopyArrow();
  if (joypad1_newkeys & (kButton_Up | kButton_Down)) {
    menu_selection_file_copy_clear_select ^= 1;
    QueueSfx1_Max6(kSfx1_MovedCursorToggleReserveMode);
  }
  else {
    if (joypad1_newkeys & kButton_B) {
      menu_index = kFileSelectMenu_9_FileCopy_InitalizeSelectDestination;
      menu_selection_file_copy_clear_select = menu_selection_file_destination_slot;
      QueueSfx1_Max6(kSfx1_MovedCursorToggleReserveMode);
      return;
    }
    if (joypad1_newkeys & (kButton_Start | kButton_A)) {
      QueueSfx1_Max6(kSfx1_MenuOptionSelected);
      if (menu_selection_file_copy_clear_select != 0) {
        menu_index = kFileSelectMenu_8_FileCopy_SelectSource;
        InitFileSelectMenuFileCopy();
      }
      else {
        menu_index = kFileSelectMenu_13_FileCopy_DoFileCopy;
      }
      return;
    }
  }

  menu_selection_missile_y_pos = (menu_selection_file_copy_clear_select != 0) ? 208 : 184;
  menu_selection_missile_x_pos = 94;
}

/**
* @brief Handle file copy arrow palette and create flowing effect
*/
void HandleFileCopyArrowPalette(void) {  // 0x8199FE
  if (menu_selection_file_copy_arrow_palette_timer != 0) {
    if (--menu_selection_file_copy_arrow_palette_timer == 0) {
      menu_selection_file_copy_arrow_palette_timer = 4;
      // Creates the arrow flow effect by moving all colors down in the palette and wrapping the first color to the last color
      uint16 color_pivot = palette_buffer.sprite_pal_1[1];
      MemCpy((uint16*)(palette_buffer.sprite_pal_1 + 1), (uint16*)(palette_buffer.sprite_pal_1 + 2), 12);
      palette_buffer.sprite_pal_1[7] = color_pivot;
    }
  }
}

/**
* @brief Perform save file transfer and handle file copying confirmation drawing and handling
*/
void FileSelectMenu_13_FileCopyDoIt(void) {  // 0x819A2C
  DrawBorderAroundDataCopyMode();
  DrawMenuSelectionMissile();
  HandleFileCopyArrowPalette();
  DrawFileCopyArrow();

  // Copy source file to destination file
  uint16 src_addr = kOffsetToSaveSlot[menu_selection_file_copy_source_clear_slot];
  uint16 dst_addr = kOffsetToSaveSlot[menu_selection_file_destination_slot];
  int save_slot_size = ADDR16_OF_RAM_OFFSET(*plm_instruction_timer, *player_data_saved);
  memcpy(&g_sram[dst_addr], &g_sram[src_addr], save_slot_size);

  // Copy over checksums
  int src_slot = menu_selection_file_copy_source_clear_slot;
  int dst_slot = menu_selection_file_destination_slot;
  kSramChecksumInverted[dst_slot] = kSramChecksumInverted[src_slot];
  kSramChecksum[dst_slot] = kSramChecksum[src_slot];
  kSramChecksumInvertedUpper[dst_slot] = kSramChecksumInvertedUpper[src_slot];
  kSramChecksumUpper[dst_slot] = kSramChecksumUpper[src_slot];

  menu_index = kFileSelectMenu_14_FileCopy_CopyCompleted;
  memset7E((uint16*)(ram3000.menu.menu_tilemap + MENU_TILEMAP_COORD(0, 20)), 15, MENU_TILEMAP_COORD(0, 29) - MENU_TILEMAP_COORD(0, 20));
  nonempty_save_slots |= (1 << menu_selection_file_destination_slot);

  // Set columns 12 to 22 of rows 8 and 9 of the tilemap, offset by the destination slot, to 15 (black)
  int slot = menu_selection_file_destination_slot * MENU_TILEMAP_COORD(0, 4);
  memset7E((uint16*)(ram3000.menu.menu_tilemap + slot + MENU_TILEMAP_COORD(0, 8) + MENU_TILEMAP_COORD(12, 0)), 15, MENU_TILEMAP_COORD(23, 0) - MENU_TILEMAP_COORD(12, 0));
  memset7E((uint16*)(ram3000.menu.menu_tilemap + slot + MENU_TILEMAP_COORD(0, 9) + MENU_TILEMAP_COORD(12, 0)), 15, MENU_TILEMAP_COORD(23, 0) - MENU_TILEMAP_COORD(12, 0));

  enemy_data[0].palette_index = 0;
  LoadMenuTilemap(MENU_TILEMAP_COORD(8, 20), addr_kMenuTilemap_CopyCompleted);
  DrawFileCopyConfirmationSaveFileInfo();
  RtlWriteSram();
}

/**
* @brief Handle end of file copy
*/
void FileSelectMenu_14_CopyCompleted(void) {  // 0x819AFA
  DrawBorderAroundDataCopyMode();
  if (joypad1_newkeys) {
    QueueSfx1_Max6(kSfx1_MovedCursorToggleReserveMode);
    menu_index = kFileSelectMenu_15_FileCopyToMain_FadeOut;
    int slot = sram_save_slot_selected;
    // If the save slot is not valid, set slot to 0
    if (slot < kSaveSlotSelected_SlotA || slot > kSaveSlotSelected_SlotC || (slot & sram_save_slot_selected_complement)) {
      slot = kSaveSlotSelected_SlotA;
    }
    selected_save_slot = slot;
  }
}

/**
* @brief Go from file copy menu to main menu
*/
void FileSelectMenu_18_FileCopyMenuToMain(void) {  // 0x819B28
  menu_index = kFileSelectMenu_4_Main;
}

/**
* @brief Setup transition from main menu to file clear menu
*/
void FileSelectMenu_20_FileClearInit(void) {  // 0x819B33
  DrawBorderAroundDataClearMode();
  menu_index = kFileSelectMenu_21_MainToFileClear_FadeIn;
  InitFileSelectMenuFileClear();
}

/**
* @brief Setup file clear menu
*/
void InitFileSelectMenuFileClear(void) {  // 0x819B3C
  ClearMenuTilemap();
  enemy_data[0].palette_index = 0;
  LoadMenuTilemap(MENU_TILEMAP_COORD(8, 1), addr_kMenuTilemap_DataClearMode);
  LoadMenuTilemap(MENU_TILEMAP_COORD(0, 5), addr_kMenuTilemap_ClearWhichData);
  LoadMenuExitTilemap();
  DrawFileCopySaveFileInfo();
  menu_selection_file_copy_source_clear_slot = 0;
  SetInitialFileCopyClearMenuSelection();
  SetFileClearMenuMissilePos();
}

/**
* @brief Handle selecting file in file clear menu
*/
void FileSelectMenu_22_FileClearSelectSlot(void) {  // 0x819B64
  int8 file_clear_selection;

  DrawBorderAroundDataClearMode();
  DrawMenuSelectionMissile();
  if (joypad1_newkeys & (kButton_Start | kButton_A)) {
    QueueSfx1_Max6(kSfx1_MovedCursorToggleReserveMode);
    if (menu_selection_file_copy_clear_select == 3) {
      QueueSfx1_Max6(kSfx1_MovedCursorToggleReserveMode);
      menu_index = kFileSelectMenu_27_FileClearToMain_FadeOut;
    }
    else {
      menu_selection_file_copy_source_clear_slot = menu_selection_file_copy_clear_select;
      menu_index = kFileSelectMenu_23_FileClear_InitializeConfirmation;
    }
  }
  else if (joypad1_newkeys & kButton_B) {
    QueueSfx1_Max6(kSfx1_MovedCursorToggleReserveMode);
    menu_index = kFileSelectMenu_27_FileClearToMain_FadeOut;
  }
  else {
    // If press up, then move the cursor to the next available position up
    if (joypad1_newkeys & kButton_Up) {
      file_clear_selection = menu_selection_file_copy_clear_select;
      while (--file_clear_selection >= 0) {
        if (nonempty_save_slots & (1 << file_clear_selection)) {
          LOBYTE(menu_selection_file_copy_clear_select) = file_clear_selection;
          QueueSfx1_Max6(kSfx1_MovedCursorToggleReserveMode);
          SetFileClearMenuMissilePos();
          return;
        }
      }
    }
    // If press down, then move the cursor to the next available position down
    else if (joypad1_newkeys & kButton_Down) {
      file_clear_selection = menu_selection_file_copy_clear_select;
      while (++file_clear_selection < 4) {
        if (file_clear_selection == 3 || (nonempty_save_slots & (1 << file_clear_selection))) {
          LOBYTE(menu_selection_file_copy_clear_select) = file_clear_selection;
          QueueSfx1_Max6(kSfx1_MovedCursorToggleReserveMode);
          SetFileClearMenuMissilePos();
          return;
        }
      }
    }
    SetFileClearMenuMissilePos();
  }
}

/**
* @brief Set missile position to one of the options in the file clear menu
*/
void SetFileClearMenuMissilePos(void) {  // 0x819BEF
  static const uint16 kFileClear_MissileY[4] = { 4*16 + 8, 6*16 + 8, 8*16 + 8, 13*16 + 3 };

  menu_selection_missile_y_pos = kFileClear_MissileY[menu_selection_file_copy_clear_select];
  menu_selection_missile_x_pos = 1*16 + 6;
}

/**
* @brief Setup file clear confirmation
*/
void FileSelectMenu_23_FileClearInitConfirm(void) {  // 0x819C0B
  DrawBorderAroundDataClearMode();
  enemy_data[0].palette_index = 0;
  LoadMenuTilemap(MENU_TILEMAP_COORD(0, 5), addr_kMenuTilemap_ClearSamusA);
  WORD(ram3000.menu.menu_tilemap[MENU_TILEMAP_COORD(21, 5)]) = 0x206A + menu_selection_file_copy_source_clear_slot;
  menu_selection_file_destination_slot = 3;
  DrawFileCopyClearConfirmation();
  menu_index = kFileSelectMenu_24_FileClear_Confirmation;
  menu_selection_file_copy_clear_select = 0;
}

/**
* @brief Handle drawing and initializing file clear confirmation
*/
void FileSelectMenu_24_FileClearConfirm(void) {  // 0x819C36
  DrawBorderAroundDataClearMode();
  DrawMenuSelectionMissile();
  if (joypad1_newkeys & (kButton_Up | kButton_Down)) {
    menu_selection_file_copy_clear_select ^= 1;
    QueueSfx1_Max6(kSfx1_MovedCursorToggleReserveMode);
    menu_selection_missile_y_pos = (menu_selection_file_copy_clear_select != 0) ? 13*16 : 11*16 + 8;
    menu_selection_missile_x_pos = 5*16 + 14;
  }
  else if (joypad1_newkeys & kButton_B) {
    menu_index = kFileSelectMenu_22_FileClear_SelectSlot;
    menu_selection_file_copy_clear_select = menu_selection_file_copy_source_clear_slot;
    QueueSfx1_Max6(kSfx1_MovedCursorToggleReserveMode);
    InitFileSelectMenuFileClear();
  }
  else if ((joypad1_newkeys & (kButton_Start | kButton_A))) {
    QueueSfx1_Max6(kSfx1_MenuOptionSelected);
    if (menu_selection_file_copy_clear_select == 0) {
      menu_index = kFileSelectMenu_25_FileClear_DoFileClear;
    }
    else {
      menu_index = kFileSelectMenu_22_FileClear_SelectSlot;
      menu_selection_file_copy_clear_select = menu_selection_file_copy_source_clear_slot;
      QueueSfx1_Max6(kSfx1_MovedCursorToggleReserveMode);
      InitFileSelectMenuFileClear();
    }
  }
  else {
    menu_selection_missile_y_pos = (menu_selection_file_copy_clear_select != 0) ? 13*16 : 11*16 + 8;
    menu_selection_missile_x_pos = 94;
  }
}

/**
* @brief Perform save file deletion and handle file deletion confirmation drawing and handling
*/
void FileSelectMenu_25_FileClearDoClear(void) {  // 0x819C9E
  DrawBorderAroundDataClearMode();
  int sram_addr = kOffsetToSaveSlot[menu_selection_file_copy_source_clear_slot];
  int save_slot_size = ADDR16_OF_RAM_OFFSET(*plm_instruction_timer, *player_data_saved);
  memset(&g_sram[sram_addr], 0, save_slot_size);

  int src_slot = menu_selection_file_copy_source_clear_slot;
  kSramChecksum[src_slot] = 0;
  kSramChecksumInverted[src_slot] = 0;
  kSramChecksumUpper[src_slot] = 0;
  kSramChecksumInvertedUpper[src_slot] = 0;

  menu_index = kFileSelectMenu_26_FileClear_ClearComplete;
  // No reason to create a save file and load it since the file is already deleted
  NewSaveFile();
  LoadFromSram(menu_selection_file_copy_source_clear_slot);

  area_index = menu_selection_file_copy_source_clear_slot;
  LoadMirrorOfExploredMapTiles();

  // Clear save slot
  memset7E((uint16*)(ram3000.menu.menu_tilemap + MENU_TILEMAP_COORD(0, 20)), 15, MENU_TILEMAP_COORD(0, 29) - MENU_TILEMAP_COORD(0, 20));
  nonempty_save_slots &= ~(1 << menu_selection_file_copy_source_clear_slot);
  enemy_data[0].palette_index = 0;
  LoadMenuTilemap(MENU_TILEMAP_COORD(0, 20), addr_kMenuTilemap_DataCleared);
  DrawFileCopyConfirmationSaveFileInfo();
  RtlWriteSram();
}

/**
* @brief Handle the file clear completed screen and load the first active save slot
*/
void FileSelectMenu_26_ClearCompleted(void) {  // 0x819D26
  DrawBorderAroundDataClearMode();
  if (joypad1_newkeys) {
    QueueSfx1_Max6(kSfx1_MovedCursorToggleReserveMode);
    menu_index = kFileSelectMenu_27_FileClearToMain_FadeOut;
    if (!LoadFromSram(kSaveSlotSelected_SlotA)) {
      selected_save_slot = kFileSelectMenuSelection_SlotA;
    }
    else if (!LoadFromSram(kSaveSlotSelected_SlotB)) {
      selected_save_slot = kFileSelectMenuSelection_SlotB;
    }
    else if (!LoadFromSram(kSaveSlotSelected_SlotC)) {
      selected_save_slot = kFileSelectMenuSelection_SlotC;
    }
    else {
      selected_save_slot = kFileSelectMenuSelection_SlotA;
    }
  }
}

/**
* @brief Transition from file clear menu to main menu
*/
void FileSelectMenu_30_FileClearMenuToMain(void) {  // 0x819D68
  DrawBorderAroundSamusData();
  menu_index = kFileSelectMenu_4_Main;
}

void FileSelectMenu_31_TurnSamusHelmet(void) {  // 0x819D77
  DrawMenuSelectionMissile();
  DrawBorderAroundSamusData();
  DrawFileSelectSlotSamusHelmet(0);
  DrawFileSelectSlotSamusHelmet(2);
  DrawFileSelectSlotSamusHelmet(4);
  if ((joypad1_newkeys & (kButton_Start | kButton_A))
      || (menu_selection_slot_a_samus_helmet_anim_frame == 7 && menu_selection_slot_a_samus_helmet_anim_timer == 0)
      || (menu_selection_slot_b_samus_helmet_anim_frame == 7 && menu_selection_slot_b_samus_helmet_anim_timer == 0)
      || (menu_selection_slot_c_samus_helmet_anim_frame == 7 && menu_selection_slot_c_samus_helmet_anim_timer == 0)) {
    menu_index = kFileSelectMenu_32_MainToOptions_FadeOut;
  }
}

void DrawFileSelectSamusHelmets(void) {  // 0x819DC3
  menu_selection_slot_a_samus_helmet_anim_timer = 0;
  DrawFileSelectSlotSamusHelmet(0);
  menu_selection_slot_b_samus_helmet_anim_timer = 0;
  DrawFileSelectSlotSamusHelmet(2);
  menu_selection_slot_c_samus_helmet_anim_timer = 0;
  DrawFileSelectSlotSamusHelmet(4);
}

/**
* @brief Draw the file select slot Samus helmet
* @param samus_helmet_slot_idx The Samus helmet index of slots A, B, C
*/
void DrawFileSelectSlotSamusHelmet(uint16 samus_helmet_slot_idx) {  // 0x819DE4
  static const uint16 kDrawFileSlotHelmet_Spritemaps[9] = { 0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0x33 };

  int idx = samus_helmet_slot_idx >> 1;
  if (menu_selection_slot_samus_helmet_anim_timer[idx] != 0) {
    if (--menu_selection_slot_samus_helmet_anim_timer[idx] == 0) {
      menu_selection_slot_samus_helmet_anim_timer[idx] = 8;

      uint16 next_frame = menu_selection_slot_samus_helmet_anim_frame[idx] + 1;
      if (next_frame > 7) {
        menu_selection_slot_samus_helmet_anim_timer[idx] = 0;
        next_frame = 7;
      }
      menu_selection_slot_samus_helmet_anim_frame[idx] = next_frame;
    }
  }

  uint16 frame_idx = menu_selection_slot_samus_helmet_anim_frame[idx];
  uint16 sprmap_idx = kDrawFileSlotHelmet_Spritemaps[frame_idx];
  uint16 sprmap_center_x_pos = menu_selection_slot_samus_helmet_x_pos[idx];
  uint16 sprmap_center_y_pos = menu_selection_slot_samus_helmet_y_pos[idx];
  DrawMenuSpritemap(sprmap_idx, sprmap_center_x_pos, sprmap_center_y_pos, 7 * 0x200);
}

static Func_V *const kFileSelectMapFuncs[23] = {  // 0x819E3E
  FileSelectMap_0_OptionsToAreaSelectSetupFadeOut,
  FileSelectMap_1_OptionsToAreaSelectFadeOut,
  FileSelectMap_2_17_LoadAreaSelectForegroundTilemap,
  FileSelectMap_3_LoadAreaSelectBackgroundTilemap,
  FileSelectMap_4_19_SetupExpandingSquareTransition,
  FileSelectMap_5_ExpandingSquare,
  FileSelectMap_6_AreaSelectMap,
  FileSelectMap_7_PrepExpandSquareTransToRoomMap,
  FileSelectMap_8_ExpandSquareTransToRoomSelectMap,
  FileSelectMap_9_InitRoomSelectMap,
  FileSelectMap_10_RoomSelectMap,
  FileSelectMap_11_12_RoomSelectToGameWaitForFadeOut,
  FileSelectMap_11_12_RoomSelectToGameWaitForFadeOut,
  FileSelectMap_13_RoomSelectToLoadGameFadeOut,
  FileSelectMap_14_RoomSelectToLoadGameWait,
  FileSelectMap_15_RoomSelectToAreaSelectClearTileMap,
  FileSelectMap_16_RoomSelectToAreaSelectLoadPalettes,
  FileSelectMap_2_17_LoadAreaSelectForegroundTilemap,
  FileSelectMap_18_RoomSelectToAreaSelectLoadBackgroundTilemap,
  FileSelectMap_4_19_SetupExpandingSquareTransition,
  FileSelectMap_20_SetupContractingSquare,
  FileSelectMap_21_RoomSelectToAreaSelectMoveExpandingSquare,
  FileSelectMap_22_SelectSlotFromFileClear,
};

/**
* @brief Handle file select map
*/
void FileSelectMap(void) {
  kFileSelectMapFuncs[menu_index]();
}

/**
* @brief Handle fading from area select map to game options menu
*/
void FileSelectMap_22_SelectSlotFromFileClear(void) {  // 0x819E7B
  DrawAreaSelectMapLabels();
  HandleFadeOut();
  if ((reg_INIDISP & 0xF) == 0) {
    game_state = kGameState_2_GameOptionsMenu;
    menu_index = 0;
  }
}

/**
* @brief Draw Zebes and star tilemap for file select menu coming from title sequence
*/
void FileSelectMenu_1_LoadFileSelectMenuBG2(void) {  // 0x819E93
  // Copy Zebes and stars tilemap to menu tilemap and transfer to VRAM BG2 tilemap
  MemCpy(ram3000.menu.menu_tilemap, kZebesAndStarsTilemap, sizeof(kZebesAndStarsTilemap));
  VramWriteEntry *vram_entry = gVramWriteEntry(vram_write_queue_tail);
  vram_entry->size = sizeof(ram3000.menu.menu_tilemap);
  vram_entry->src.addr = ADDR16_OF_RAM(ram3000.menu.menu_tilemap);
  vram_entry->src.bank = 0x7E;
  vram_entry->vram_dst = (reg_BG2SC & 0xFC) << 8;
  vram_write_queue_tail += sizeof(VramWriteEntry);

  menu_index = kFileSelectMenu_2_TitleToMain_Initialize;
  menu_selection_missile_anim_timer = 1;
  menu_selection_missile_anim_frame = 0;
}

/**
* @brief Handle transition from title sequence to main menu
*/
void FileSelectMenu_2_InitMain(void) {  // 0x819ED6
  uint16 save_slot;

  if ((int16)sram_save_slot_selected < kSaveSlotSelected_SlotA || (int16)sram_save_slot_selected > kSaveSlotSelected_SlotC
      || (save_slot = sram_save_slot_selected, (sram_save_slot_selected & sram_save_slot_selected_complement))) {
    save_slot = kSaveSlotSelected_SlotA;
  }
  selected_save_slot = save_slot;
  FileSelectMenu_16_28_ReloadMain();
}

/**
* @brief (Re)Draw main menu screen
*/
void FileSelectMenu_16_28_ReloadMain(void) {  // 0x819EF3
  // Sets the nonempty_save_slots bit 15 (0x8000) if file is empty
  uint16 file_is_empty;

  memset7E((uint16*)ram3000.menu.menu_tilemap, 15, sizeof(ram3000.menu.menu_tilemap));
  nonempty_save_slots = -1;

  enemy_data[0].palette_index = 0;
  LoadMenuTilemap(MENU_TILEMAP_COORD(11, 1), addr_kMenuTilemap_SamusData);
  LoadMenuTilemap(MENU_TILEMAP_COORD(3, 5), addr_kMenuTilemap_SamusA);
  file_is_empty = LoadFromSram_(kSaveSlotSelected_SlotA) << 15;
  nonempty_save_slots = (nonempty_save_slots >> 1) | file_is_empty;
  DrawFileSelectionHealth(nonempty_save_slots & FILE_IS_EMPTY, MENU_TILEMAP_COORD(14, 5));
  DrawFileSelectionTime(nonempty_save_slots & FILE_IS_EMPTY, MENU_TILEMAP_COORD(26, 6));
  LoadMenuTilemap(MENU_TILEMAP_COORD(27, 5), addr_kMenuTilemap_TIME);

  enemy_data[0].palette_index = 0;
  LoadMenuTilemap(MENU_TILEMAP_COORD(3, 10), addr_kMenuTilemap_SamusB);
  file_is_empty = LoadFromSram_(kSaveSlotSelected_SlotB) << 15;
  nonempty_save_slots = (nonempty_save_slots >> 1) | file_is_empty;
  DrawFileSelectionHealth(nonempty_save_slots & FILE_IS_EMPTY, MENU_TILEMAP_COORD(14, 10));
  DrawFileSelectionTime(nonempty_save_slots & FILE_IS_EMPTY, MENU_TILEMAP_COORD(26, 11));
  LoadMenuTilemap(MENU_TILEMAP_COORD(27, 10), addr_kMenuTilemap_TIME);

  enemy_data[0].palette_index = 0;
  LoadMenuTilemap(MENU_TILEMAP_COORD(3, 15), addr_kMenuTilemap_SamusC);
  file_is_empty = LoadFromSram_(kSaveSlotSelected_SlotC) << 15;
  nonempty_save_slots = (nonempty_save_slots >> 1) | file_is_empty;
  DrawFileSelectionHealth(nonempty_save_slots & FILE_IS_EMPTY, MENU_TILEMAP_COORD(14, 15));
  DrawFileSelectionTime(nonempty_save_slots & FILE_IS_EMPTY, MENU_TILEMAP_COORD(26, 16));
  LoadMenuTilemap(MENU_TILEMAP_COORD(27, 15), addr_kMenuTilemap_TIME);

  nonempty_save_slots = swap16(~nonempty_save_slots) >> 5;
  // Only draw copy/clear options if there are any non-empty save slots
  if (nonempty_save_slots) {
    enemy_data[0].palette_index = 0;
    LoadMenuTilemap(MENU_TILEMAP_COORD(4, 20), addr_kMenuTilemap_DataCopy);
    enemy_data[0].palette_index = 0;
    LoadMenuTilemap(MENU_TILEMAP_COORD(4, 23), addr_kMenuTilemap_DataClear);
  }
  enemy_data[0].palette_index = 0;
  LoadMenuTilemap(MENU_TILEMAP_COORD(4, 26), addr_kMenuTilemap_Exit);
  QueueTransferOfMenuTilemapToVramBG1();

  menu_selection_missile_anim_timer = 1;
  menu_selection_file_copy_arrow_palette_timer = 0;
  menu_selection_slot_a_samus_helmet_anim_timer = 0;
  menu_selection_slot_b_samus_helmet_anim_timer = 0;
  menu_selection_slot_c_samus_helmet_anim_timer = 0;
  menu_selection_missile_anim_frame = 0;
  eproj_id[1] = 0;
  menu_selection_slot_a_samus_helmet_anim_frame = 0;
  menu_selection_slot_b_samus_helmet_anim_frame = 0;
  menu_selection_slot_c_samus_helmet_anim_frame = 0;
  menu_selection_missile_x_pos = 0;
  menu_selection_missile_y_pos = 0;
  eproj_id[6] = 0;
  eproj_id[11] = 0;
  menu_selection_slot_a_samus_helmet_x_pos = 6*16 + 4;
  menu_selection_slot_b_samus_helmet_x_pos = 6*16 + 4;
  menu_selection_slot_c_samus_helmet_x_pos = 6*16 + 4;
  menu_selection_slot_a_samus_helmet_y_pos = 2*16 + 15;
  menu_selection_slot_b_samus_helmet_y_pos = 5*16 + 7;
  menu_selection_slot_c_samus_helmet_y_pos = 7*16 + 15;
  screen_fade_delay = 1;
  screen_fade_counter = 1;
  ScreenOn();
  ++menu_index;
  menu_selection_file_copy_clear_select = 0;
  menu_selection_file_copy_source_clear_slot = 0;
  menu_selection_file_destination_slot = 0;
}

/**
* @brief Loads the saved game progress from SRAM
* @param selected_save_slot_ The current save slot
* @return uint8 1 if save file is cleared, else 0
*/
uint8 LoadFromSram_(uint16 selected_save_slot_) {  // 0x81A053
  return LoadFromSram(selected_save_slot_);
}

/**
* @brief Handle drawing fade in from title sequence to main
*/
void FileSelectMenu_3_FadeInToMain(void) {  // 0x81A058
  DrawFileSelectSamusHelmets();
  menu_selection_missile_y_pos = kMenuSelectionMissileXY[selected_save_slot].y_pos;
  menu_selection_missile_x_pos = kMenuSelectionMissileXY[selected_save_slot].x_pos;
  DrawMenuSelectionMissile();
  DrawBorderAroundSamusData();
  HandleFadeIn();
  if ((reg_INIDISP & 0xF) == 15)
    menu_index = kFileSelectMenu_4_Main;
}

/**
* @brief Draws the health of a file in the file selection menu
* @param file_is_empty Boolean of whether the file is empty
* @param menu_tilemap_idx An index into the menu tilemap
*/
void DrawFileSelectionHealth(uint16 file_is_empty, uint16 menu_tilemap_idx) {  // 0x81A087
  int16 energy_tank_tile;

  if (file_is_empty) {
    FileSelectClearRestOfMenuTilemapRow(menu_tilemap_idx);
    LoadMenuTilemap(menu_tilemap_idx + MENU_TILEMAP_COORD(0, 1), addr_kMenuTilemap_NoData);
  }
  else {
    LoadMenuTilemap(menu_tilemap_idx, addr_kMenuTilemap_Energy);

    int whole_tank_count = samus_health / 100;
    int sub_tank_energy = samus_health % 100;
    int collected_tank_count = samus_max_health / 100;
    int max_row_tanks = 7;
    uint16 health_tilemap_idx = menu_tilemap_idx + MENU_TILEMAP_COORD(4, 0) + MENU_TILEMAP_COORD(0, 1);

    while (--collected_tank_count >= 0) {
      energy_tank_tile = 0x99;  // empty energy tank tile
      if (whole_tank_count != 0) {
        --whole_tank_count;
        energy_tank_tile = 0x98;  // full energy tank tile
      }
      WORD(ram3000.menu.menu_tilemap[health_tilemap_idx]) = energy_tank_tile | enemy_data[0].palette_index;
      health_tilemap_idx += MENU_TILEMAP_COORD(1, 0);
      if (--max_row_tanks == 0) {
        health_tilemap_idx -= MENU_TILEMAP_COORD(7, 1);
        max_row_tanks = 8;
      }
    }

    int tens_digit = sub_tank_energy / 10;
    int ones_digit = sub_tank_energy % 10;
    WORD(ram3000.menu.menu_tilemap[menu_tilemap_idx + MENU_TILEMAP_COORD(2, 1)]) = (0x2060 + ones_digit) | enemy_data[0].palette_index;
    WORD(ram3000.menu.menu_tilemap[menu_tilemap_idx + MENU_TILEMAP_COORD(1, 1)]) = (0x2060 + tens_digit) | enemy_data[0].palette_index;
  }
}

/**
* @brief Draws the play time of a file in the file selection menu
* @param file_is_empty Boolean of whether the file is empty
* @param menu_tilemap_idx An index into the menu tilemap
*/
void DrawFileSelectionTime(uint16 file_is_empty, uint16 menu_tilemap_idx) {  // 0x81A14E
  if (!file_is_empty) {
    int hours_tens_digit = game_time_hours / 10;
    int hours_ones_digit = game_time_hours % 10;
    WORD(ram3000.menu.menu_tilemap[menu_tilemap_idx + MENU_TILEMAP_COORD(1, 0)]) = (0x2060 + hours_ones_digit) | enemy_data[0].palette_index;
    WORD(ram3000.menu.menu_tilemap[menu_tilemap_idx + MENU_TILEMAP_COORD(0, 0)]) = (0x2060 + hours_tens_digit) | enemy_data[0].palette_index;
    LoadMenuTilemap(menu_tilemap_idx + MENU_TILEMAP_COORD(2, 0), addr_kMenuTilemap_Colon);

    int minutes_tens_digit = game_time_minutes / 10;
    int minutes_ones_digit = game_time_minutes % 10;
    WORD(ram3000.menu.menu_tilemap[menu_tilemap_idx + MENU_TILEMAP_COORD(4, 0)]) = (0x2060 + minutes_ones_digit) | enemy_data[0].palette_index;
    WORD(ram3000.menu.menu_tilemap[menu_tilemap_idx + MENU_TILEMAP_COORD(3, 0)]) = (0x2060 + minutes_tens_digit) | enemy_data[0].palette_index;
  }
}

/**
* @brief Draw and handle file select menu
*/
void FileSelectMenu_4_Main(void) {  // 0x81A1C2
  DrawBorderAroundSamusData();
  DrawMenuSelectionMissile();
  DrawFileSelectSlotSamusHelmet(0);
  DrawFileSelectSlotSamusHelmet(2);
  DrawFileSelectSlotSamusHelmet(4);

  // If selected something
  if (joypad1_newkeys & (kButton_Start | kButton_A)) {
    if ((int16)selected_save_slot <= kFileSelectMenuSelection_SlotC) {
      QueueSfx1_Max6(kSfx1_SelectedSaveFile);
      menu_index = kFileSelectMenu_31_MainToOptions_TurnSamusHelmet;
      menu_selection_slot_samus_helmet_anim_timer[selected_save_slot] = 1;
      sram_save_slot_selected = selected_save_slot;
      sram_save_slot_selected_complement = ~selected_save_slot;
      RtlWriteSram();
      if (LoadFromSram(selected_save_slot)) {
        NewSaveFile();
        has_area_map = false;
      }
      else {
        LoadMirrorOfExploredMapTiles();
      }
      menu_selection_missile_y_pos = kMenuSelectionMissileXY[selected_save_slot].y_pos;
      menu_selection_missile_x_pos = kMenuSelectionMissileXY[selected_save_slot].x_pos;
    }
    else if (selected_save_slot == kFileSelectMenuSelection_FileCopy) {
      QueueSfx1_Max6(kSfx1_MovedCursorToggleReserveMode);
      menu_index = kFileSelectMenu_5_MainToFileCopy_FadeOut;
      reg_MOSAIC = reg_MOSAIC & 0xC | 3;
    }
    else if (selected_save_slot == kFileSelectMenuSelection_FileClear) {
      QueueSfx1_Max6(kSfx1_MovedCursorToggleReserveMode);
      menu_index = kFileSelectMenu_19_MainToFileClear_FadeOut;
      // CHANGE: Code originally forgot to return after this if statement and instead continues to the next if statement
      // This would use the value from reg_MOSAIC in the next if statement
      // This fix shouldn't affect any outcomes
      reg_MOSAIC = reg_MOSAIC & 0xC | 3;
    }
    else if (selected_save_slot == kFileSelectMenuSelection_Exit) {
      menu_index = kFileSelectMenu_33_MainToTitle;
    }
    return;
  }
  // If press up, go to next slot up, skip file copy/clear slots if no non-empty slots and wrap around if needed
  else if (joypad1_newkeys & kButton_Up) {
    int16 previous_slot;
    if (nonempty_save_slots) {
      previous_slot = selected_save_slot - 1;
      if (previous_slot < kFileSelectMenuSelection_SlotA)
        previous_slot = kFileSelectMenuSelection_Exit;
    }
    else {
      previous_slot = selected_save_slot - 1;
      if (previous_slot < kFileSelectMenuSelection_SlotA) {
        previous_slot = kFileSelectMenuSelection_Exit;
      }
      else {
        if (previous_slot >= kFileSelectMenuSelection_FileClear)
          previous_slot = kFileSelectMenuSelection_SlotC;
      }
    }
    selected_save_slot = previous_slot;
    QueueSfx1_Max6(kSfx1_MovedCursorToggleReserveMode);
  }
  // If press down, go to next slot down, skip file copy/clear slots if no non-empty slots and wrap around if needed
  else if (joypad1_newkeys & kButton_Down) {
    int16 next_slot;
    if (nonempty_save_slots) {
      next_slot = selected_save_slot + 1;
      if (next_slot > kFileSelectMenuSelection_Exit)
        next_slot = kFileSelectMenuSelection_SlotA;
    }
    else {
      next_slot = selected_save_slot + 1;
      if (next_slot > kFileSelectMenuSelection_SlotC) {
        if (next_slot > kFileSelectMenuSelection_Exit)
          next_slot = kFileSelectMenuSelection_SlotA;
        else
          next_slot = kFileSelectMenuSelection_Exit;
      }
    }
    selected_save_slot = next_slot;
    QueueSfx1_Max6(kSfx1_MovedCursorToggleReserveMode);
  }
  // If press B, exit file select menu
  else if (joypad1_newkeys & kButton_B) {
    QueueSfx1_Max6(kSfx1_MovedCursorToggleReserveMode);
    menu_index = kFileSelectMenu_33_MainToTitle;
    QueueSfx1_Max6(kSfx1_MovedCursorToggleReserveMode);
  }

  menu_selection_missile_y_pos = kMenuSelectionMissileXY[selected_save_slot].y_pos;
  menu_selection_missile_x_pos = kMenuSelectionMissileXY[selected_save_slot].x_pos;
}

/**
* @brief Clear and transfer menu tilemap to VRAM and begin to fade out to area select
*/
void FileSelectMap_0_OptionsToAreaSelectSetupFadeOut(void) {  // 0x81A32A
  ClearMenuTilemap();

  // Transfer menu tilemap to VRAM BG2 tilemap
  VramWriteEntry *vram_entry = gVramWriteEntry(vram_write_queue_tail);
  vram_entry->size = sizeof(ram3000.menu.menu_tilemap);
  vram_entry->src.addr = ADDR16_OF_RAM(ram3000.menu.menu_tilemap);
  vram_entry->src.bank = 0x7E;
  vram_entry->vram_dst = (reg_BG2SC & 0xFC) << 8;
  vram_write_queue_tail += sizeof(VramWriteEntry);

  palette_change_num = 0;
  LoadFileSelectPalettes();
  MemCpy(target_palettes.bg1_bg2_pal_0, palette_buffer.bg1_bg2_pal_0, sizeof(palette_buffer.bg1_bg2_pal_0));
  MemCpy(target_palettes.bg1_bg2_pal_1, palette_buffer.bg1_bg2_pal_1, sizeof(palette_buffer.bg1_bg2_pal_1));
  target_palettes.bg1_bg2_pal_0[14] = 0;
  target_palettes.bg1_bg2_pal_1[14] = 0;
  menu_index = kFileSelectMap_1_OptionsToAreaSelect_FadeOut_LoadAreaPalette;
}

/**
* @brief Handle fade out from game options menu to area select map and load area palettes
*/
void FileSelectMap_1_OptionsToAreaSelectFadeOut(void) {  // 0x81A37C
  if (AdvanceGradualColorChangeOfPalette(0, 0x40)) {
    reg_BG1VOFS = 0;
    reg_BG1HOFS = 0;
    reg_BG2VOFS = 0;
    reg_BG2HOFS = 0;
    uint16 map_area_idx = 0;
    while (area_index != kFileSelectMap_AreaIndexes[map_area_idx]) {
      if (++map_area_idx >= arraysize(kFileSelectMap_AreaIndexes)) {
        map_area_idx = 0;
        break;
      }
    }
    file_select_map_area_index = map_area_idx;

    for (int area_idx = 0; area_idx <= kArea_5_Tourian; area_idx++) {
      if (area_idx == area_index)
        LoadActiveAreaMapForegroundColors(area_idx);
      else
        LoadInactiveAreaMapForegroundColors(area_idx);
    }
    menu_index = kFileSelectMap_2_OptionsToAreaSelect_LoadForegroundTilemap;
    g_word_7E0787 = 0;
    reg_TM = 2;
  }
}

void UNUSED_sub_81A3D1(uint16 k) {  // 0x81A3D1
  LoadActiveAreaMapForegroundColors(k);
}

/**
* @brief Load inactive area select map foreground palette
* @brief area_idx The area index
*/
void LoadActiveAreaMapForegroundColors(uint16 area_idx) {  // 0x81A3D3
  LoadAreaMapForegroundColors(kActiveAreaMapForegroundColors[area_idx]);
}

/**
* @brief Load inactive area select map foreground palette
* @brief area_idx The area index
*/
void LoadInactiveAreaMapForegroundColors(uint16 area_idx) {  // 0x81A3DC
  LoadAreaMapForegroundColors(kInactiveAreaMapForegroundColors[area_idx]);
}

/**
* @brief Load area select map foreground palette
* @param area_map_pal_idx The index into the area select map foreground palette table
*/
void LoadAreaMapForegroundColors(uint16 area_map_pal_idx) {  // 0x81A3E3
  for (int idx = area_map_pal_idx >> 1; kAreaMapForegroundSetDefs[idx] != 0xFFFF; idx += 2) {
    uint16 pal_data_ram_idx = kAreaMapForegroundSetDefs[idx + 1] >> 1;
    uint16 pal_data_src_idx = kAreaMapForegroundSetDefs[idx] >> 1;
    MemCpy(palette_buffer.pal + pal_data_ram_idx, kAreaMapForegroundColors + pal_data_src_idx, 10);
  }
}

/**
* @brief Load area select foreground tilemap 
*/
void FileSelectMap_2_17_LoadAreaSelectForegroundTilemap(void) {  // 0x81A546
  // Transfer area select foreground tilemap to VRAM BG1 tilemap
  VramWriteEntry *vram_entry = gVramWriteEntry(vram_write_queue_tail);
  vram_entry->size = 0x800;  // sizeof(kAreaSelectForegroundTilemap)
  vram_entry->src.addr = addr_kAreaSelectForegroundTilemap;
  vram_entry->src.bank = 0x81;
  vram_entry->vram_dst = (reg_BG1SC & 0xFC) << 8;
  vram_write_queue_tail += sizeof(VramWriteEntry);

  reg_INIDISP = 0xF;
  ++menu_index;
}

/**
* @brief Loads the current area select background tilemap during transition of room select map to area select map
*/
void FileSelectMap_18_RoomSelectToAreaSelectLoadBackgroundTilemap(void) {  // 0x81A578
  menu_index = kFileSelectMap_19_RoomSelectToAreaSelect_PrepareExpandingContractingSquareTransition;
  LoadAreaSelectBackgroundTilemap(area_index);
}

/**
* @brief Loads the current area select background tilemap during transition of game optiosn to area select map
*/
void FileSelectMap_3_LoadAreaSelectBackgroundTilemap(void) {  // 0x81A582
  menu_index = kFileSelectMap_4_OptionsToAreaSelect_PrepareExpandingContractingSquareTransition;
  LoadAreaSelectBackgroundTilemap(area_index);
}

/**
* @brief Loads the current area select background tilemap
* @param area_index_ The index of the current anime
*/
void LoadAreaSelectBackgroundTilemap(uint16 area_index_) {  // 0x81A58A
  // Transfer area select background tilemap to VRAM BG3 tilemap
  VramWriteEntry *vram_entry = gVramWriteEntry(vram_write_queue_tail);
  vram_entry->size = 0x800;  // sizeof(kAreaSelectBackgroundTilemap)
  vram_entry->src.addr = kAreaSelectBackgroundTilemaps[area_index_];
  vram_entry->src.bank = 0x81;
  vram_entry->vram_dst = (reg_BG3SC & 0xFC) << 8;
  vram_write_queue_tail += sizeof(VramWriteEntry);
}

/**
* @brief Set up expanding and contracting square transition for area select map
*/
void FileSelectMap_4_19_SetupExpandingSquareTransition(void) {  // 0x81A5B3
  reg_TS = 4;
  WriteReg(TS, 4);
  reg_TSW = 4;
  WriteReg(TSW, 4);
  reg_CGWSEL = 2;
  WriteReg(CGWSEL, 2);
  reg_CGADSUB = 0x20 | 0x4 | 0x1;
  WriteReg(CGADSUB, 0x20 | 0x4 | 0x1);

  reg_COLDATA[2] = 0x80;
  reg_COLDATA[1] = 0x40;
  reg_COLDATA[0] = 0x20;
  SetupInitialExpandingSquareHDMA();
  reg_HDMAEN = 8 | 4;
  WriteReg(HDMAEN, 8 | 4);
  ConfigureWindow1ForExpandingSquare();
  hdma_objects_enable_flag = 0;
  LOBYTE(menu_index) = menu_index + 1;
}

/**
* @brief Set up window 1 for expanding square effect
*/
void ConfigureWindow1ForExpandingSquare(void) {  // 0x81A5F6
  reg_TM = 0x10 | 0x2 | 0x1;
  WriteReg(TM, 0x10 | 0x2 | 0x1);

  reg_TMW = 0x10 | 0x2 | 0x1;
  WriteReg(TMW, 0x10 | 0x2 | 0x1);

  reg_W12SEL = 0x20 | 0x2 | 0x1;
  WriteReg(W12SEL, 0x20 | 0x2 | 0x1);

  reg_W34SEL = 0x2 | 0x1;
  WriteReg(W34SEL, 0x2 | 0x1);

  reg_WOBJSEL = 0x20 | 0x2 | 0x1;
  WriteReg(WOBJSEL, 0x20 | 0x2 | 0x1);
}

/**
* @Brief Set up HDMA for window 1 expanding and contracting square transition
*/
void SetupInitialExpandingSquareHDMA(void) {  // 0x81A61C
  expand_sq_topbottom_margin_right_pos = 0;
  expand_sq_topbottom_margin_left_pos = -1;
  LOBYTE(expand_sq_left_pos) = 127;
  LOBYTE(expand_sq_right_pos) = 129;

  hdma_window_1_left_pos[0].height = 0x6F;
  hdma_window_1_left_pos[0].addr = ADDR16_OF_RAM(expand_sq_topbottom_margin_left_pos);

  hdma_window_1_left_pos[1].height = 1;
  hdma_window_1_left_pos[1].addr = ADDR16_OF_RAM(expand_sq_left_pos);

  hdma_window_1_left_pos[2].height = 1;
  hdma_window_1_left_pos[2].addr = ADDR16_OF_RAM(expand_sq_left_pos);

  hdma_window_1_left_pos[3].height = 0x6F;
  hdma_window_1_left_pos[3].addr = ADDR16_OF_RAM(expand_sq_topbottom_margin_right_pos);

  WriteReg(DMAP2, HDMA_CONTROL(0, 1, 0));
  WriteReg(BBAD2, REG(WH0));
  WriteRegWord(A1T2L, ADDR16_OF_RAM(*hdma_window_1_left_pos));
  WriteReg(A1B2, 0x7E);
  WriteReg(DAS20, 0x7E);
  WriteReg(DAS2L, 0);
  WriteReg(DAS2H, 0);
  WriteReg(A2A2L, 0);
  WriteReg(A2A2H, 0);
  WriteReg(NTRL2, 0);

  hdma_window_1_right_pos[0].height = 0x6F;
  hdma_window_1_right_pos[0].addr = ADDR16_OF_RAM(expand_sq_topbottom_margin_right_pos);

  hdma_window_1_right_pos[1].height = 1;
  hdma_window_1_right_pos[1].addr = ADDR16_OF_RAM(expand_sq_right_pos);

  hdma_window_1_right_pos[2].height = 1;
  hdma_window_1_right_pos[2].addr = ADDR16_OF_RAM(expand_sq_right_pos);

  hdma_window_1_right_pos[3].height = 0x6F;
  hdma_window_1_right_pos[3].addr = ADDR16_OF_RAM(expand_sq_topbottom_margin_right_pos);

  WriteReg(DMAP2, HDMA_CONTROL(0, 1, 0));
  WriteReg(BBAD2, REG(WH1));
  WriteRegWord(A1T3L, ADDR16_OF_RAM(*hdma_window_1_right_pos));
  WriteReg(A1B3, 0x7E);
  WriteReg(DAS30, 0x7E);
  WriteReg(DAS3L, 0);
  WriteReg(DAS3H, 0);
  WriteReg(A2A3L, 0);
  WriteReg(A2A3H, 0);
  WriteReg(NTRL3, 0);
}

static const uint8 kExpandingSquareTransitionSpeed = 4;

/**
* @brief Handle expanding square transition to area select map
*/
void FileSelectMap_5_ExpandingSquare(void) {  // 0x81A725
  DrawAreaSelectMapLabels();
  uint8 margin_height = hdma_window_1_left_pos[0].height - kExpandingSquareTransitionSpeed;
  uint8 half_square_height = hdma_window_1_left_pos[1].height + kExpandingSquareTransitionSpeed;
  // If transition is finished
  if ((int8)margin_height < 0) {
    LOBYTE(menu_index) = kFileSelectMap_6_AreaSelect;
    reg_TM &= ~2;
    reg_TMW = 0;
    reg_TSW = 0;
    reg_BG2VOFS = 0x10 | 0x8;
    pausemenu_palette_animation_timer = 1;

    MemCpy(ram4000.bg2_room_select_map_tilemap, kBg2RoomSelectMapTilemap, 1600);
    memset7E(ram4000.bg2_room_select_map_tilemap + 800, 0x2801, sizeof(ram4000.bg2_room_select_map_tilemap) - 1600);
    DrawRoomSelectMapAreaLabel(ram4000.bg2_room_select_map_tilemap + 170);
    MemCpy(ram4000.bg2_room_select_map_tilemap + 800, kFileSelectExpandingSquareTilemap + 1, 320);

    // Transfer BG2 room select map tilemap to VRAM BG2 tilemap
    VramWriteEntry *vram_entry = gVramWriteEntry(vram_write_queue_tail);
    vram_entry->size = sizeof(ram4000.bg2_room_select_map_tilemap);
    vram_entry->src.addr = ADDR16_OF_RAM(ram4000.bg2_room_select_map_tilemap);
    vram_entry->src.bank = 0x7E;
    vram_entry->vram_dst = (reg_BG2SC & 0xFC) << 8;
    vram_write_queue_tail += sizeof(VramWriteEntry);
  }
  else {
    hdma_window_1_left_pos[0].height = margin_height;
    hdma_window_1_left_pos[3].height = margin_height;
    hdma_window_1_right_pos[0].height = margin_height;
    hdma_window_1_right_pos[3].height = margin_height;

    hdma_window_1_left_pos[1].height = half_square_height;
    hdma_window_1_left_pos[2].height = half_square_height;
    hdma_window_1_right_pos[1].height = half_square_height;
    hdma_window_1_right_pos[2].height = half_square_height;

    LOBYTE(expand_sq_left_pos) = expand_sq_left_pos - kExpandingSquareTransitionSpeed;
    LOBYTE(expand_sq_right_pos) = expand_sq_right_pos + kExpandingSquareTransitionSpeed;
  }
}

/**
* @brief Handle area select map menu
*/
void FileSelectMap_6_AreaSelectMap(void) {  // 0x81A800
  // This function is buggy, as it repeatedly uses the wrong value after checking debug
  // @todo Clean up this function
  int16 v0 = joypad1_newkeys;
  if (joypad1_newkeys & (kButton_Up | kButton_Left)) {
    v0 = enable_debug;
    if (enable_debug) {
      uint16 R28 = DecAndWraparoundTo5(file_select_map_area_index);
      if (Debug_CheckIfFileSelectMapAreaCanBeSelected(R28)
          || (R28 = DecAndWraparoundTo5(R28), Debug_CheckIfFileSelectMapAreaCanBeSelected(R28))
          || (R28 = DecAndWraparoundTo5(R28), Debug_CheckIfFileSelectMapAreaCanBeSelected(R28))) {
        QueueSfx1_Max6(kSfx1_MovedCursorToggleReserveMode);
        Debug_SwitchActiveFileSelectMapArea(R28);
        DrawAreaSelectMapLabels();
        return;
      }
      DrawAreaSelectMapLabels();
      return;
    }
LABEL_6:
    if (v0 & kButton_B) {
      menu_index = kFileSelectMap_22_AreaSelectToOptions;
      DrawAreaSelectMapLabels();
      return;
    }
    if (v0 & (kButton_Start | kButton_A)) {
      QueueSfx1_Max6(kSfx1_MenuOptionSelected);
      SelectFileSelectMapArea();
      return;
    }
    DrawAreaSelectMapLabels();
    return;
  }
  if (!(joypad1_newkeys & (kButton_Select | kButton_Down | kButton_Right)))
    goto LABEL_6;
  v0 = enable_debug;
  if (!enable_debug)
    goto LABEL_6;

  // The following code only works in debug mode, which is not officially supported
  int n = 6;
  uint16 area_idx = file_select_map_area_index;
  while (1) {
    //area_idx = WraparoundFrom6to0(area_idx);
    area_idx = (area_idx + 1) % 6;
    if (Debug_CheckIfFileSelectMapAreaCanBeSelected(area_idx))
      break;
    if (--n == 0) {
      DrawAreaSelectMapLabels();
      return;
    }
  }
  Debug_SwitchActiveFileSelectMapArea(area_idx);
  QueueSfx1_Max6(kSfx1_MovedCursorToggleReserveMode);
  DrawAreaSelectMapLabels();
}

/**
* @brief Performs (a - 1) % 6 (only works for small a less than 6)
* @param a The value to calculate with
* @return uint16 (a - 1) % 6
*/
uint16 DecAndWraparoundTo5(uint16 a) {  // 0x81A898
  int16 result = a - 1;
  if (result < 0)
    return 5;
  return result;
}

/**
* @brief Performs (a + 1) % 6 (only works for small a less than 6)
* @param a The value to calculate with
* @return uint16 (a + 1) % 6
*/
uint16 WraparoundFrom6to0(uint16 a) {  // 0x81A89F
  uint16 result = a + 1;
  if (result >= 6)
    return 0;
  return result;
}

/**
* @brief Select the currently highlighted map area
*/
void SelectFileSelectMapArea(void) {  // 0x81A8A9
  int8 used_station;
  int16 icon_position;

  menu_index = kFileSelectMap_7_AreaSelectToRoomSelect_PrepareExpandingSquareTransition;
  if (!enable_debug) {
    area_index = sram_area_index;
    load_station_index = sram_save_station_index;
    DrawAreaSelectMapLabels();
    return;
  }

  // The following code only works in debug mode, which is not officially supported
  area_index = kFileSelectMap_AreaIndexes[file_select_map_area_index];
  uint16 area_used_station = WORD(used_save_stations_and_elevators[2 * area_index]);
  uint16 station_idx = 0;
  uint16* icon_position_ptr = (uint16*)kMapIconPositions_SavePoints[area_index];
  uint16 station_counter = 16;
  while (1) {
    used_station = area_used_station & 1;
    area_used_station >>= 1;
    if (used_station) {
      icon_position = icon_position_ptr[2 * station_idx];
      if (icon_position != 0xFFFE) {
        if (icon_position != 0xFFFF)
          break;
        station_idx = -1;
      }
    }
    ++station_idx;
    if (--station_counter == 0) {
      while (1) {
        icon_position = icon_position_ptr[2 * station_idx];
        if (icon_position != 0xFFFE) {
          if (icon_position != 0xFFFF)
            goto POSITION_FOUND;
          station_idx = -1;
        }
        ++station_idx;
        if (--station_counter == 0) {
          Unreachable();
        }
      }
    }
  }
POSITION_FOUND:
  load_station_index = station_idx;
  DrawAreaSelectMapLabels();
}

uint16 Debug_CheckIfFileSelectMapAreaCanBeSelected(uint16 area_idx) {  // 0x81A931
  int v1 = 2 * kFileSelectMap_AreaIndexes[area_idx];
  if (WORD(used_save_stations_and_elevators[v1]) != 0)
    return true;
  //uint16 t = *(uint16 *)((uint8 *)&kMapIconDataPointers[4].crateria + v1) + 64;
  uint16 t = kMapIconPositions_DebugSavePoints[v1 >> 1][0].x;
  return t != 0xffff;
}

void Debug_SwitchActiveFileSelectMapArea(uint16 R28) {  // 0x81A958
  LoadInactiveAreaMapForegroundColors(kFileSelectMap_AreaIndexes[file_select_map_area_index]);
  file_select_map_area_index = R28;
  LoadActiveAreaMapForegroundColors(kFileSelectMap_AreaIndexes[R28]);
  LoadAreaSelectBackgroundTilemap(kFileSelectMap_AreaIndexes[file_select_map_area_index]);
}

static const Point16U kAreaSelectMapLabelPositions[6] = {  // 0x81AA1C
  [kArea_0_Crateria]    = { .x = 0x5b, .y = 0x32 },
  [kArea_1_Brinstar]    = { .x = 0x2a, .y = 0x7f },
  [kArea_2_Norfair]     = { .x = 0x5e, .y = 0xb5 },
  [kArea_3_WreckedShip] = { .x = 0xce, .y = 0x50 },
  [kArea_4_Maridia]     = { .x = 0xce, .y = 0x9f },
  [kArea_5_Tourian]     = { .x = 0x87, .y = 0x8b },
};

/**
* @brief Draw the label for each area map
*/
void DrawAreaSelectMapLabels(void) {  // 0x81A97E
  uint16 area_select_pal = 0 * 0x200;
  DrawMenuSpritemap(gAreaSelectSpritemapOffset, 0x80, 0x10, area_select_pal);
  for(int area_idx = 0; area_idx < arraysize(kFileSelectMap_AreaIndexes); area_idx++) {
    area_select_pal = (area_idx == file_select_map_area_index) ? 0 * 0x200 : 1 * 0x200;
    uint16 area_select_idx = 2 * kFileSelectMap_AreaIndexes[area_idx];
    uint16 area_used_stations = *(uint16 *)&used_save_stations_and_elevators[area_select_idx];
    Point16U *icon_position_ptr = kMapIconPositions_SavePoints[area_select_idx >> 1];
    int station_counter = 16;

    while ((*icon_position_ptr).x != 0xFFFF) {
      int used_station = area_used_stations & 1;
      area_used_stations >>= 1;

      if (used_station && (*icon_position_ptr).x != 0xFFFE) {
        int map_area_index = kFileSelectMap_AreaIndexes[area_idx];
        DrawMenuSpritemap(
          gAreaSelectSpritemapOffset + kFileSelectMap_AreaIndexes[area_idx] + 1,
          kAreaSelectMapLabelPositions[map_area_index].x,
          kAreaSelectMapLabelPositions[map_area_index].y, area_select_pal);
        break;
      }

      icon_position_ptr += 1;
      if (--station_counter == 0) {
        if (enable_debug && (*icon_position_ptr).x != 0xFFFF) {
          int map_area_index = kFileSelectMap_AreaIndexes[area_idx];
          DrawMenuSpritemap(
            gAreaSelectSpritemapOffset + kFileSelectMap_AreaIndexes[area_idx] + 1,
            kAreaSelectMapLabelPositions[map_area_index].x,
            kAreaSelectMapLabelPositions[map_area_index].y, area_select_pal);
          break;
        }
        break;
      }
    }
  }
}

/**
* @brief Set up expanding square transition from area select map to room select map
*/
void FileSelectMap_7_PrepExpandSquareTransToRoomMap(void) {  // 0x81AAAC
  DrawAreaSelectMapLabels();
  SetupInitialExpandingSquareHDMA();
  reg_TM = 0x10 | 0x2 | 0x1;
  reg_TMW = 0x10 | 0x2 | 0x1;
  reg_W12SEL = 0x20 | 0x10 | 0x2;
  WriteReg(W12SEL, 0x20 | 0x10 | 0x2);

  reg_W34SEL = 2;
  WriteReg(W34SEL, 2);

  reg_CGADSUB = 4 | 1;
  WriteReg(CGADSUB, 4 | 1);

  reg_WOBJSEL = 0x20 | 0x2;
  WriteReg(WOBJSEL, 0x20 | 0x2);

  reg_BG12NBA = 0x20 | 0x10;
  hdma_window_1_left_pos[3].height = 0;
  hdma_window_1_right_pos[3].height = 0;
  DrawRoomSelectMapAreaLabel(ram4000.bg2_room_select_map_tilemap + 170);

  // Transfer RAM 0x4000 to VRAM BG2 tilemap
  VramWriteEntry *vram_entry = gVramWriteEntry(vram_write_queue_tail);
  vram_entry->size = 0x200;
  vram_entry->src.addr = ADDR16_OF_RAM(ram4000.bg2_room_select_map_tilemap);
  vram_entry->src.bank = 0x7E;
  vram_entry->vram_dst = (reg_BG2SC & 0xFC) << 8;
  vram_write_queue_tail += sizeof(VramWriteEntry);

  expand_sq_timer = kRoomSelectMapExpandingSquareTimers[area_index];
  expand_sq_left_pos = kAreaSelectMapLabelPositions[area_index].x;
  expand_sq_right_pos = expand_sq_left_pos;
  expand_sq_top_pos = kAreaSelectMapLabelPositions[area_index].y;
  expand_sq_bottom_pos = expand_sq_top_pos;
  expand_sq_left_subpos = 0;
  expand_sq_right_subpos = 0;
  expand_sq_top_subpos = 0;
  expand_sq_bottom_subpos = 0;

  const ExpandingSquareVels *vels = &kExpandingSquareVels[area_index];
  expand_sq_left_subvel = vels->left_subvel;
  expand_sq_left_vel = vels->left_vel;
  expand_sq_right_subvel = vels->right_subvel;
  expand_sq_right_vel = vels->right_vel;
  expand_sq_top_subvel = vels->top_subvel;
  expand_sq_top_vel = vels->top_vel;
  expand_sq_bottom_subvel = vels->bottom_subvel;
  expand_sq_bottom_vel = vels->bottom_vel;

  SetupRoomSelectMapExpandingSquareTransHDMA();
  reg_HDMAEN = 0x8 | 0x4;
  WriteReg(HDMAEN, 0x8 | 0x4);
  menu_index = kFileSelectMap_8_AreaSelectToRoomSelect_ExpandingSquareTransition;
  QueueSfx1_Max6(kSfx1_HexagonMapToSquareMapTransition);
}

/**
* @brief Set up the expanding square transition HDMA for room select map
*/
void SetupRoomSelectMapExpandingSquareTransHDMA(void) {  // 0x81ABA7
  uint16 tab_offset = 0;
  uint16 num_lines_top = expand_sq_top_pos;
  AddExpandingSqTransLeftIndirHDMA(num_lines_top, tab_offset, ADDR16_OF_RAM(expand_sq_topbottom_margin_left_pos));
  tab_offset = AddExpandingSqTransRightIndirHDMA(num_lines_top, tab_offset, ADDR16_OF_RAM(expand_sq_topbottom_margin_right_pos));

  uint16 num_lines_vert = expand_sq_bottom_pos - expand_sq_top_pos;
  if ((uint8)expand_sq_bottom_pos == (uint8)expand_sq_top_pos)
    num_lines_vert = 1;
  AddExpandingSqTransLeftIndirHDMA(num_lines_vert, tab_offset, ADDR16_OF_RAM(expand_sq_left_pos));
  tab_offset = AddExpandingSqTransRightIndirHDMA(num_lines_vert, tab_offset, ADDR16_OF_RAM(expand_sq_right_pos));

  uint16 num_lines_bottom = 224 - expand_sq_bottom_pos;
  if ((uint8)expand_sq_bottom_pos == 224)
    num_lines_bottom = 1;
  AddExpandingSqTransLeftIndirHDMA(num_lines_bottom, tab_offset, ADDR16_OF_RAM(expand_sq_topbottom_margin_left_pos));
  tab_offset = AddExpandingSqTransRightIndirHDMA(num_lines_bottom, tab_offset, ADDR16_OF_RAM(expand_sq_topbottom_margin_right_pos));

  *(&hdma_window_1_left_pos[0].height + tab_offset) = 0;
  *(&hdma_window_1_right_pos[0].height + tab_offset) = 0;
}

/**
* @brief Add the expanding square transition left position to the indirect HDMA window table
* @param num_lines The amount of lines the HDMA will affect
* @param tab_offset The offset into the indirect HDMA window table
* @param window_1_left_pos_addr The address to the window 1 left position
*/
void AddExpandingSqTransLeftIndirHDMA(uint16 num_lines, uint16 tab_offset, uint16 window_1_left_pos_addr) {  // 0x81ABF7
  if ((int8)num_lines < 0) {
    *(&hdma_window_1_left_pos[0].height + tab_offset) = num_lines - 127;
    *(&hdma_window_1_left_pos[1].height + tab_offset) = 127;
    *(uint16 *)(&hdma_window_1_left_pos[0].addr_lo + tab_offset) = window_1_left_pos_addr;
    *(uint16 *)(&hdma_window_1_left_pos[1].addr_lo + tab_offset) = window_1_left_pos_addr;
  }
  else {
    *(&hdma_window_1_left_pos[0].height + tab_offset) = num_lines;
    *(uint16 *)(&hdma_window_1_left_pos[0].addr_lo + tab_offset) = window_1_left_pos_addr;
  }
}

/**
* @brief Add the expanding square transition right position to the indirect HDMA window table
* @param num_lines The amount of lines the HDMA will affect
* @param tab_offset The offset into the indirect HDMA window table
* @param window_1_right_pos_addr The address to the window 1 right position
* @return uint16 The offset into the next indirect HDMA window table
*/
uint16 AddExpandingSqTransRightIndirHDMA(uint16 num_lines, uint16 tab_offset, uint16 window_1_right_pos_addr) {  // 0x81AC2D
  if ((int8)num_lines < 0) {
    *(&hdma_window_1_right_pos[0].height + tab_offset) = num_lines - 127;
    *(&hdma_window_1_right_pos[1].height + tab_offset) = 127;
    *(uint16 *)(&hdma_window_1_right_pos[0].addr_lo + tab_offset) = window_1_right_pos_addr;
    *(uint16 *)(&hdma_window_1_right_pos[1].addr_lo + tab_offset) = window_1_right_pos_addr;
    return tab_offset + 2 * sizeof(ExpandingSquareTransitionHdma);
  }
  else {
    *(&hdma_window_1_right_pos[0].height + tab_offset) = num_lines;
    *(uint16 *)(&hdma_window_1_right_pos[0].addr_lo + tab_offset) = window_1_right_pos_addr;
    return tab_offset + sizeof(ExpandingSquareTransitionHdma);
  }
}

/**
* @brief Handle drawing the expanding square and area select map lables
*/
void FileSelectMap_8_ExpandSquareTransToRoomSelectMap(void) {  // 0x81AC66
  if ((int16)HandleRoomSelectMapExpandingSquareTrans() < 0) {
    menu_index = kFileSelectMap_9_AreaSelectToRoomSelect_Initialize;
    reg_TM = 2;
    reg_TMW = 0;
    reg_TSW = 0;
    reg_TS = 0;
  }
  DrawAreaSelectMapLabels();
}

/**
* @brief Handle the expanding square transition for room select map
* @return uint16 The time remaining for the expanding square transition
*/
uint16 HandleRoomSelectMapExpandingSquareTrans(void) {  // 0x81AC84
  AddToHiLo(&expand_sq_left_pos, &expand_sq_left_subpos, __PAIR32__(expand_sq_left_vel, expand_sq_left_subvel));
  if ((int16)expand_sq_left_pos < 1)
    expand_sq_left_pos = 1;

  AddToHiLo(&expand_sq_right_pos, &expand_sq_right_subpos, __PAIR32__(expand_sq_right_vel, expand_sq_right_subvel));
  if ((int16)expand_sq_right_pos > 255)
    expand_sq_right_pos = 255;

  AddToHiLo(&expand_sq_top_pos, &expand_sq_top_subpos, __PAIR32__(expand_sq_top_vel, expand_sq_top_subvel));
  if ((int16)expand_sq_top_pos < 1)
    expand_sq_top_pos = 1;

  AddToHiLo(&expand_sq_bottom_pos, &expand_sq_bottom_subpos, __PAIR32__(expand_sq_bottom_vel, expand_sq_bottom_subvel));
  if ((int16)expand_sq_bottom_pos >= 224)
    expand_sq_bottom_pos = 224;

  SetupRoomSelectMapExpandingSquareTransHDMA();
  return --expand_sq_timer;
}

/**
* @brief Set up the transition from area select map to room select map
*/
void FileSelectMap_9_InitRoomSelectMap(void) {  // 0x81AD17
  LoadMirrorOfExploredMapTiles();
  DrawRoomSelectMap();
  LoadFromLoadStation();
  DisableHdmaObjects();
  WaitUntilEndOfVblankAndClearHdma();
  RoomDefHeader RoomDefHeader = get_RoomDefHeader(room_ptr);
  LOBYTE(area_index) = RoomDefHeader.area_index_;
  LOBYTE(room_x_coordinate_on_map) = RoomDefHeader.x_coordinate_on_map;
  LOBYTE(room_y_coordinate_on_map) = RoomDefHeader.y_coordinate_on_map;

  SetupMapScrollingForFileSelectMap();
  map_min_y_scroll += 24;
  reg_BG2VOFS = 24;
  reg_TM &= ~4;
  menu_index = kFileSelectMap_10_RoomSelect;
  map_scrolling_direction = kMapScrollingDirection_None;
  map_scrolling_speed_index = 0;
  samus_position_indicator_animation_frame = 0;
  samus_position_indicator_animation_timer = 0;
  samus_position_indicator_animation_loop_counter = 0;
}

/**
* @brief Handle drawing the room select map and going to gameplay or back to area select map
*/
void FileSelectMap_10_RoomSelectMap(void) {  // 0x81AD7F
  int16 v1;
  int16 v3;
  int8 v4;
  int16 v5;
  int16 v8;

  DrawFileSelectMapIcons();
  HandleFileSelectMapScrollArrows();
  MapScrolling();
  DisplayMapElevatorDestinations();

  // This code is debug only
  if (enable_debug && (joypad2_new_keys & kButton_Select)) {
    QueueSfx1_Max6(kSfx1_MenuOptionSelected);
    
    uint16 r24 = *(uint16 *)&used_save_stations_and_elevators[2 * area_index];
    v1 = load_station_index;
    do {
      r24 >>= 1;
      --v1;
    } while (v1 >= 0);

    uint16* icon_position_ptr = (uint16*)kMapIconPositions_SavePoints[area_index];
    v3 = 4 * load_station_index;
    uint16 r18 = icon_position_ptr[v3 >> 1];
    uint16 r20 = icon_position_ptr[(v3 >> 1) + 1];
    if (!sign16(load_station_index - 16))
      goto LABEL_23;
    do {
      if (!sign16(++load_station_index - 16)) {
        while (1) {
          v5 = icon_position_ptr[2 * load_station_index];
          if (v5 == -1)
            break;
          if (v5 != -2)
            goto LABEL_25;
LABEL_23:
          ++load_station_index;
        }
        load_station_index = 0;
        r24 = *(uint16 *)&used_save_stations_and_elevators[2 * area_index];
      }
      v4 = r24 & 1;
      r24 >>= 1;
    } while (!v4 || icon_position_ptr[2 * load_station_index] >= 0xFFFE);
LABEL_25:;
    uint16 v6 = 4 * load_station_index;
    uint16 w7 = icon_position_ptr[2 * load_station_index];
    if (sign16(w7 - reg_BG1HOFS) || !sign16(w7 - 256 - reg_BG1HOFS)) {
      v8 = reg_BG1HOFS + icon_position_ptr[v6 >> 1] - r18;
      if (v8 >= 0) {
        if ((int16)(v8 - map_min_x_scroll) >= 0)
          v8 = map_min_x_scroll;
      } else {
        v8 = 0;
      }
      reg_BG1HOFS = v8;
    }
    uint16 v9 = v6 + 2;
    uint16 v10 = icon_position_ptr[v9 >> 1];
    if (sign16(v10 - reg_BG1VOFS) || !sign16(v10 - 161 - reg_BG1VOFS)) {
      uint16 v11 = reg_BG1VOFS + icon_position_ptr[v9 >> 1] - r20;
      if ((int16)(v11 - map_min_y_scroll) >= 0)
        v11 = map_min_y_scroll;
      reg_BG1VOFS = v11;
    }
  }

  else if (joypad1_newkeys & kButton_B) {
    menu_index = kFileSelectMap_15_RoomSelectToAreaSelect_ClearBg1Tilemap;
    uint16 file_select_map_area_idx = 0;
    while (area_index != kFileSelectMap_AreaIndexes[file_select_map_area_idx >> 1]) {
      file_select_map_area_idx += 2;
      if (file_select_map_area_idx >= sizeof(kFileSelectMap_AreaIndexes)) {
        file_select_map_area_index = 0;
        return;
      }
    }
    file_select_map_area_index = file_select_map_area_idx >> 1;
    QueueSfx1_Max6(kSfx1_SquareMapToHexagonMapTransition);
  }
  else if (joypad1_newkeys & (kButton_Start | kButton_A)) {
    menu_index = kFileSelectMap_11_RoomSelectToLoadGame_FadeOut2FrameDelay;
    QueueSfx1_Max6(kSfx1_MenuOptionSelected);
  }
}

void UNUSED_sub_81AEC8(void) {  // 0x81AEC8
  HandleFileSelectMapScrollArrows();
}

/**
* @brief Handle drawing and scrolling map arrows in room select map
*/
void HandleFileSelectMapScrollArrows(void) {  // 0x81AECA
  if ((int16)(map_min_x_scroll - 24) < (int16)reg_BG1HOFS)
    DrawMapScrollArrowAndCheckToScroll(kFileSelectLeftMapScrollArrowData);
  if ((int16)(map_max_x_scroll - 232) >= (int16)reg_BG1HOFS)
    DrawMapScrollArrowAndCheckToScroll(kFileSelectRightMapScrollArrowData);
  if ((int16)(map_min_y_scroll - 64) < (int16)reg_BG1VOFS)
    DrawMapScrollArrowAndCheckToScroll(kFileSelectUpMapScrollArrowData);
  if ((int16)(map_max_y_scroll - 145) >= (int16)reg_BG1VOFS) {
    DrawMapScrollArrowAndCheckToScroll(kFileSelectDownMapScrollArrowData);
  }
  else {
    if (map_scrolling_direction == kFileSelectDownMapScrollArrowData.map_scroll_dir) {
      map_scrolling_gear_switch_timer = 0;
      map_scrolling_direction = kMapScrollingDirection_None;
      map_scrolling_speed_index = 0;
    }
  }
}

/**
* @brief Handle drawing room select map before gameplay transition starts
*/
void FileSelectMap_11_12_RoomSelectToGameWaitForFadeOut(void) {  // 0x81AF5A
  DrawFileSelectMapIcons();
  DisplayMapElevatorDestinations();
  ++menu_index;
}

/**
* @brief Handle drawing fade out from room select map to gameplay
*/
void FileSelectMap_13_RoomSelectToLoadGameFadeOut(void) {  // 0x81AF66
  DrawFileSelectMapIcons();
  DisplayMapElevatorDestinations();
  HandleFadeOut();
  if ((reg_INIDISP & 0xF) == 0) {
    menu_index = kFileSelectMap_14_RoomSelectToLoadGame_Wait;
    enemy_data[0].x_pos = 2*16;
  }
}

/**
* @brief Wait for fade out to finish between room select map to gameplay
*/
void FileSelectMap_14_RoomSelectToLoadGameWait(void) {  // 0x81AF83
  if (--enemy_data[0].x_pos == 0) {
    ScreenOff();
    game_state = kGameState_6_LoadingGameData;
    menu_index = 0;
  }
}

/**
* @brief Clear the tilemap when going from room select map back to area select map
*/
void FileSelectMap_15_RoomSelectToAreaSelectClearTileMap(void) {  // 0x81AF97
  reg_TM = 0x10 | 0x2;

  // Clear area select map and transfer to VRAM BG1 tilemap
  memset7E(ram3000.pause_menu_map_tilemap, 15, sizeof(ram3000.pause_menu_map_tilemap));
  VramWriteEntry *vram_entry = gVramWriteEntry(vram_write_queue_tail);
  vram_entry->size = sizeof(ram3000.pause_menu_map_tilemap);
  vram_entry->src.addr = ADDR16_OF_RAM(ram3000.pause_menu_map_tilemap);
  vram_entry->src.bank = 0x7E;
  vram_entry->vram_dst = (reg_BG1SC & 0xFC) << 8;
  vram_write_queue_tail += sizeof(VramWriteEntry);

  menu_index = kFileSelectMap_16_RoomSelectToAreaSelect_LoadPalettes;
}

/**
* @brief Handle loading palettes and tilemaps for area select map when coming from room select map
*/
void FileSelectMap_16_RoomSelectToAreaSelectLoadPalettes(void) {  // 0x81AFD3
  LoadMenuPalettes();
  for (int area_idx = 0; area_idx < kArea_6_Ceres; area_idx++) {
    LoadInactiveAreaMapForegroundColors(area_idx);
  }
  LoadActiveAreaMapForegroundColors(area_index);
  LoadAreaSelectBackgroundTilemap(area_index);
  menu_index = kFileSelectMap_17_RoomSelectToAreaSelect_LoadForegroundTilemap;
}

/**
* @brief Set up contracting square transition from room select map back to area select map
*/
void FileSelectMap_20_SetupContractingSquare(void) {  // 0x81AFF6
  reg_HDMAEN = 0;
  QueueSfx1_Max6(kSfx1_SquareMapToHexagonMapTransition);

  expand_sq_timer = kRoomSelectMapExpandingSquareTimers[area_index] - 12;
  expand_sq_left_subvel = kExpandingSquareVels[area_index].left_subvel;
  expand_sq_left_vel = kExpandingSquareVels[area_index].left_vel;
  expand_sq_right_subvel = kExpandingSquareVels[area_index].right_subvel;
  expand_sq_right_vel = kExpandingSquareVels[area_index].right_vel;
  expand_sq_top_subvel = kExpandingSquareVels[area_index].top_subvel;
  expand_sq_top_vel = kExpandingSquareVels[area_index].top_vel;
  expand_sq_bottom_subvel = kExpandingSquareVels[area_index].bottom_subvel;
  expand_sq_bottom_vel = kExpandingSquareVels[area_index].bottom_vel;
  expand_sq_left_pos = 8;
  expand_sq_right_pos = (uint8)(-8);
  expand_sq_top_pos = 8;
  expand_sq_bottom_pos = (uint8)(-40);
  expand_sq_left_subpos = 0;
  expand_sq_right_subpos = 0;
  expand_sq_top_subpos = 0;
  expand_sq_bottom_subpos = 0;

  SetupRoomSelectMapExpandingSquareTransHDMA();
  menu_index = kFileSelectMap_21_RoomSelectToAreaSelect_ContractingSquareTransition;

  reg_HDMAEN = 0x8 | 0x4; 0x30 | 0x2;
  WriteReg(HDMAEN, 0x8 | 0x4);

  reg_W12SEL = 0x20 | 0x10 | 0x2;
  WriteReg(W12SEL, 0x20 | 0x10 | 0x2);

  reg_W34SEL = 2;
  WriteReg(W34SEL, 2);

  reg_BG12NBA = 0x20 | 0x10;
  reg_WOBJSEL = 0x20 | 0x2;
  hdma_window_1_left_pos[3].height = 0;
  hdma_window_1_right_pos[3].height = 0;
  reg_BG1VOFS = 0;
  reg_BG1HOFS = 0;
}

/**
* @Brief Handle the contracting square transition from room select map back to area select map
*/
void FileSelectMap_21_RoomSelectToAreaSelectMoveExpandingSquare(void) {  // 0x81B0BB
  AddToHiLo(&expand_sq_left_pos, &expand_sq_left_subpos, -IPAIR32(expand_sq_left_vel, expand_sq_left_subvel));
  AddToHiLo(&expand_sq_right_pos, &expand_sq_right_subpos, -IPAIR32(expand_sq_right_vel, expand_sq_right_subvel));
  AddToHiLo(&expand_sq_top_pos, &expand_sq_top_subpos, -IPAIR32(expand_sq_top_vel, expand_sq_top_subvel));
  AddToHiLo(&expand_sq_bottom_pos, &expand_sq_bottom_subpos, -IPAIR32(expand_sq_bottom_vel, expand_sq_bottom_subvel));
  SetupRoomSelectMapExpandingSquareTransHDMA();
  DrawAreaSelectMapLabels();
  if ((int16)--expand_sq_timer < 0) {
    menu_index = kFileSelectMap_6_AreaSelect;
    reg_TM = 0x10 | 0x1;
    reg_TMW = 0;
    reg_TSW = 0;
  }
}

/**
* @brief Set up a new empty save file
*/
void NewSaveFile(void) {  // 0x81B2CB
  samus_max_health = 99;
  samus_health = 99;
  samus_max_missiles = 0;
  samus_missiles = 0;
  samus_max_super_missiles = 0;
  samus_super_missiles = 0;
  samus_max_power_bombs = 0;
  samus_power_bombs = 0;

  hud_item_index = 0;
  collected_beams = 0;
  equipped_beams = 0;
  collected_items = 0;
  equipped_items = 0;
  reserve_health_mode = 0;
  samus_max_reserve_health = 0;
  samus_reserve_health = 0;
  samus_reserve_missiles = 0;

  button_config_up = kButton_Up;
  button_config_down = kButton_Down;
  button_config_left = kButton_Left;
  button_config_right = kButton_Right;
  button_config_jump = kButton_A;
  button_config_run = kButton_B;
  button_config_shoot = kButton_X;
  button_config_itemcancel = kButton_Y;
  button_config_itemswitch = kButton_Select;
  button_config_aim_up = kButton_R;
  button_config_aim_down = kButton_L;

  game_time_frames = 0;
  game_time_seconds = 0;
  game_time_minutes = 0;
  game_time_hours = 0;

  japanese_text_flag = 0;
  moonwalk_flag = 0;
  hud_auto_cancel_flag = 0;
  debug_flag = 1;
  UNUSED_word_7E09E8 = 1;
  
  memset7E((uint16*)room_chozo_bits, 0, ADDR16_OF_RAM_OFFSET(*item_bit_array, *room_chozo_bits));
  memset7E((uint16*)item_bit_array, 0, ADDR16_OF_RAM_OFFSET(*opened_door_bit_array, *item_bit_array));
  memset7E((uint16*)opened_door_bit_array, 0, ADDR16_OF_RAM_OFFSET(*UNUSED_word_7ED8F0, *opened_door_bit_array));
  memset7E(UNUSED_word_7ED8F0, 0, ADDR16_OF_RAM_OFFSET(*used_save_stations_and_elevators, *UNUSED_word_7ED8F0));
  memset7E((uint16*)map_station_byte_array, 0, 8);
  memset7E((uint16*)used_save_stations_and_elevators, 0, 8);
  memset7E((uint16*)used_save_stations_and_elevators + 8, 0, 8);
  memset7E(explored_map_tiles_saved, 0, 1792);
}

/**
* @brief Clear the remaining columns of the menu tilemap row
* @param menu_tilemap_idx The index into the menu tilemap
*/
void FileSelectClearRestOfMenuTilemapRow(uint16 menu_tilemap_idx) {  // 0x81B3C5
  int cols_remaining = 32 - ((menu_tilemap_idx & 0x3F) >> 1);
  memset7E((uint16*)(ram3000.menu.menu_tilemap + menu_tilemap_idx), 15, cols_remaining*2);
}

/**
* @brief Load the menu tilemap
* @param menu_tilemap_idx The index into the menu tilemap
* @param addr The address to the tilemaps
*/
void LoadMenuTilemap(uint16 menu_tilemap_idx, uint16 addr) {  // 0x81B3E2
  uint16 tilemap;
  int menu_tilemap_base_idx = menu_tilemap_idx;

  while (1) {
    while (1) {
      tilemap = GET_WORD(RomPtr_81(addr));
      if (tilemap != 0xFFFE)
        break;
      addr += 2;
      menu_tilemap_idx = (menu_tilemap_base_idx += MENU_TILEMAP_COORD(0, 1));
    }

    if (tilemap == 0xFFFF)
      break;
    WORD(ram3000.menu.menu_tilemap[menu_tilemap_idx]) = enemy_data[0].palette_index | tilemap;
    menu_tilemap_idx += 2;
    addr += 2;
  }
}
