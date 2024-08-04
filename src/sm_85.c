// Message boxes
#include <string.h>

#include "ida_types.h"
#include "variables.h"
#include "sm_rtl.h"
#include "funcs.h"
#include "sm_85.h"

uint16 message_box_tilemap_size;

/**
* @brief Sets up the PPU to display Message Boxes
*/
static void InitializePpuForMessageBoxes(void) {  // 0x858143
  save_confirmation_selection = kConfirmSave_Yes;
  // Clear HDMA enable
  WriteReg(HDMAEN, 0);
  // Write color 0x0BB1 (green Y button) to CGRAM BG3 palette 6 color 1
  WriteReg(CGADD, 0x19);
  WriteReg(CGDATA, 0xB1);
  WriteReg(CGDATA, 0xB);
  // Write color 0x00F1 (red select arrow) to CGRAM BG3 palette 6 color 2
  WriteReg(CGDATA, 0x1F);
  WriteReg(CGDATA, 0);
  ram3000.msgbox.backup_of_enabled_hdma_channels = reg_HDMAEN;
  ram3000.msgbox.backup_of_bg3_tilemap_and_size = gameplay_BG3SC;
  gameplay_BG3SC = 0x58;
  gameplay_TM = 23;
  gameplay_CGWSEL = 0;
  gameplay_CGADSUB = 0;
  // Set color math subscreen backdrop to transparent
  WriteReg(COLDATA, 0x20);
  WriteReg(COLDATA, 0x40);
  WriteReg(COLDATA, 0x80);
  ReadReg(BG3HOFS);         // Useless
  // Initialize BG3 X scroll to 0
  WriteReg(BG3HOFS, 0);
  WriteReg(BG3HOFS, 0);     // Doubly useless
  ReadReg(BG3VOFS);         // Triply useless
  // Initialize BG3 Y scroll to 0
  WriteReg(BG3VOFS, 0);
  WriteReg(BG3VOFS, 0);     // Combo breaker
  memset(&ram3000.msgbox, 0, 0x80);
  uint16 vram_backup_size = sizeof(ram4000.backups.backup_of_vram_0x5880_msgbox);
  CopyFromVram(addr_kVram_FxBackup, ram4000.backups.backup_of_vram_0x5880_msgbox, vram_backup_size, 1);
}

/**
* @brief Clears the message box BG3 tilemap and transfers it to VRAM
*/
static void ClearMessageBoxBg3Tilemap(void) {  // 0x8581F3
  uint16 cleared_tilemap_size = sizeof(ram3800.cleared_message_box_bg3_tilemap);
  memset7E(ram3800.cleared_message_box_bg3_tilemap, kTxt_Nul, cleared_tilemap_size);
  CopyToVram(addr_kVram_FxBackup, ram3800.cleared_message_box_bg3_tilemap, cleared_tilemap_size, 1);
}

/**
* @brief Writes the message box tilemap to RAM
* @return uint16 The tilemap offset of the bottom border
*/
static uint16 WriteMessageTilemap(void) {  // 0x8582B8
  message_box_animation_y1_bottom_half = 112;
  message_box_animation_y0_bottom_half = 124;
  message_box_animation_y_radius = 0;
  memset(&ram3000.msgbox, 0, 0xE0);
  uint16 message_src = kMessageBoxDefs[message_box_index-1].message_tilemap;
  uint16 message_size = kMessageBoxDefs[message_box_index].message_tilemap - message_src;
  uint16 top_border_size = sizeof(kSmallMsgBoxTopBottomBorderTilemap);
  uint16 bottom_border_size = top_border_size;
  message_box_tilemap_size = top_border_size + message_size + bottom_border_size;
  const uint16* message_tilemap = getMessageTilemap(message_src);
#if 1
  if (message_src == addr_kMissileReloadCompletedMsgBoxTilemap) {
    message_tilemap = kAmmoRechargeCompletedMsgBoxTilemap;
  }
#endif
  uint16 tilemap_offset = top_border_size >> 1;
  MemCpy(ram3000.msgbox.tilemap + tilemap_offset, message_tilemap, message_size);
  return top_border_size + message_size;
}

/**
* @brief Writes the large message box top border, message, and bottom border to RAM
*/
static void WriteLargeMessageBoxTilemap(void) {  // 0x85825A
  uint16 border_size = sizeof(kLargeMsgBoxTopBottomBorderTilemap);
  MemCpy(ram3000.msgbox.tilemap, kLargeMsgBoxTopBottomBorderTilemap, border_size);
  uint16 bottom_border_offset = WriteMessageTilemap() >> 1;
  MemCpy(ram3000.msgbox.tilemap + bottom_border_offset, kLargeMsgBoxTopBottomBorderTilemap, border_size);
}

/**
* @brief Writes the small message box top border, message, and bottom border to RAM
*/
static void WriteSmallMessageBoxTilemap(void) {  // 0x858289
  uint16 border_size = sizeof(kSmallMsgBoxTopBottomBorderTilemap);
  MemCpy(ram3000.msgbox.tilemap, kSmallMsgBoxTopBottomBorderTilemap, border_size);
  uint16 bottom_border_offset = WriteMessageTilemap() >> 1;
  MemCpy(ram3000.msgbox.tilemap + bottom_border_offset, kSmallMsgBoxTopBottomBorderTilemap, border_size);
}

/**
* @brief Creates a squishing effect using an HDMA table as the message box expands/contracts
  @brief until it reaches the desired Y radius
*/
static void MsgBoxMakeHdmaTable(void) {  // 0x85959B
  message_box_animation_y2_top_half = (uint16)(0x7B00 - message_box_animation_y_radius) >> 8;
  message_box_animation_y3_top_half = 99;
  message_box_animation_y0_bottom_half = (uint16)(0x7C00 + message_box_animation_y_radius) >> 8;
  message_box_animation_y1_bottom_half = 148;
  uint16 max_radius = sizeof(ram3000.msgbox.msg_box_anim_y_radius) / 2;
  uint16 y_top_pos = max_radius - 1;
  uint16 y_bottom_pos = 0;
  // Subtracting and incrementing the bases does nothing
  // Should just do a two equations beforehand and write the result to RAM
  for (int r20 = max_radius; r20 > 0; r20--) {
    ram3000.msgbox.msg_box_anim_y_radius_neg[y_top_pos] = message_box_animation_y3_top_half - message_box_animation_y2_top_half;
    --message_box_animation_y3_top_half;
    --message_box_animation_y2_top_half;
    --y_top_pos;
    ram3000.msgbox.msg_box_anim_y_radius[y_bottom_pos] = message_box_animation_y1_bottom_half - message_box_animation_y0_bottom_half;
    ++message_box_animation_y1_bottom_half;
    ++message_box_animation_y0_bottom_half;
    ++y_bottom_pos;
  }
  memset(ram3000.msgbox.msg_box_anim_clear, 0, sizeof(ram3000.msgbox.msg_box_anim_clear));
}

/**
* @brief Sets up an indirect HDMA to BG3 Y scroll for the expanding/contracting squish effect
*/
static void SetupMessageBoxBg3YscrollHdma(void) {  // 0x858363
  ram3000.msgbox.indirect_hdma[0] = 0xFF;
  WORD(ram3000.msgbox.indirect_hdma[1]) = 0x3000;
  ram3000.msgbox.indirect_hdma[3] = 0xE1;
  WORD(ram3000.msgbox.indirect_hdma[4]) = 0x30FE;
  ram3000.msgbox.indirect_hdma[6] = 0;
  // Set up indirect HDMA to BG3 Y scroll on HDMA channel 6
  WriteReg(DMAP6, HDMA_CONTROL(0, 1, 2));
  WriteReg(BBAD6, REG(BG3VOFS));
  WriteReg(A1T6L, 0x80);
  WriteReg(DAS6L, 0x80);
  WriteReg(A1T6H, 0x33);
  WriteReg(DAS6H, 0x33);
  WriteReg(A1B6, 0x7E);
  WriteReg(DAS60, 0x7E);
  WriteReg(A2A6L, 0);
  WriteReg(A2A6H, 0);
  WriteReg(NTRL6, 0);
  MsgBoxMakeHdmaTable();
  // Enable HDMA channel 6
  WriteReg(HDMAEN, 0x40);
}

/**
* @brief Sets up the message box effect and transfers the message box tilemap to VRAM
* @param bg3_tilemap_offset The offset into VRAM based off the message box size
*/
static void SetupPpuForActiveMessageBox(uint16 bg3_tilemap_offset) {  // 0x85831E
  SetupMessageBoxBg3YscrollHdma();
  CopyToVram(addr_kVram_Bg3Tilemap + bg3_tilemap_offset, ram3000.msgbox.tilemap, message_box_tilemap_size, 1);
}

/**
* @brief Gets the button config assigned to the action, draws the button letter tile,
* @brief and sets up the PPU for a large message box.
* @param special_button The button binding assigned to the specified action
*/
static void DrawSpecialButtonAndSetupPpuForLargeMessageBox(uint16 special_button) {  // 0x8583D1
  uint16 button_offset = 0;
  if ((special_button & kButton_A) == 0) {
    button_offset = 2;
    if ((special_button & kButton_B) == 0) {
      button_offset = 4;
      if ((special_button & kButton_X) == 0) {
        button_offset = 6;
        if ((special_button & kButton_Y) == 0) {
          button_offset = 8;
          if ((special_button & kButton_Select) == 0) {
            button_offset = 10;
            if ((special_button & kButton_L) == 0) {
              button_offset = 12;
              if ((special_button & kButton_R) == 0)
                button_offset = 14;
            }
          }
        }
      }
    }
  }
  uint16 button_tilemap_offset = kMsgBoxSpecialButtonTilemapOffs[message_box_index-1];
  ram3000.msgbox.tilemap[button_tilemap_offset >> 1] = kTileNumbersForButtonLetters[button_offset >> 1];
  uint16 large_msg_offset = addr_kVram_LargeMessageBox - addr_kVram_Bg3Tilemap;
  SetupPpuForActiveMessageBox(large_msg_offset);
}

/**
* @brief Draws the button assigned to shoot and sets up the PPU for a large message box
*/
static void DrawShootButtonAndSetupPpuForLargeMessageBox(void) {  // 0x8583C5
  DrawSpecialButtonAndSetupPpuForLargeMessageBox(button_config_shoot_x);
}

/**
* @brief Draws the button assigned to run and sets up the PPU for a large message box
*/
static void DrawRunButtonAndSetupPpuForLargeMessageBox(void) {  // 0x8583CC
  DrawSpecialButtonAndSetupPpuForLargeMessageBox(button_config_run_b);
}

/**
* @brief Sets up the PPU with the VRAM offset for a small message box
*/
static void SetupPpuForSmallMessageBox(void) {  // 0x858436
  uint16 small_msg_offset = addr_kVram_SmallMessageBox - addr_kVram_Bg3Tilemap;
  SetupPpuForActiveMessageBox(small_msg_offset);
}

/**
* @brief Sets up the PPU with the VRAM offset for a large message box
*/
static void SetupPpuForLargeMessageBox(void) {  // 0x858441
  uint16 large_msg_offset = addr_kVram_LargeMessageBox - addr_kVram_Bg3Tilemap;
  SetupPpuForActiveMessageBox(large_msg_offset);
}

static void CallMsgBoxDraw(uint32 ea) {
  switch (ea) {
  case fnWriteLargeMessageBoxTilemap: WriteLargeMessageBoxTilemap(); return;
  case fnWriteSmallMessageBoxTilemap: WriteSmallMessageBoxTilemap(); return;
  default: Unreachable();
  }
}

static void CallMsgBoxModify(uint32 ea) {
  switch (ea) {
  case fnDrawShootButtonAndSetupPpuForLargeMessageBox: DrawShootButtonAndSetupPpuForLargeMessageBox(); return;
  case fnDrawRunButtonAndSetupPpuForLargeMessageBox: DrawRunButtonAndSetupPpuForLargeMessageBox(); return;
  case fnSetupPpuForSmallMessageBox: SetupPpuForSmallMessageBox(); return;
  case fnSetupPpuForLargeMessageBox: SetupPpuForLargeMessageBox(); return;
  default: Unreachable();
  }
}

/**
* @brief Writes the message box tilemap to RAM and transfers it to the PPU
*/
static void InitializeMessageBox(void) {  // 0x858241
  MsgBoxConfig message_box_def = kMessageBoxDefs[message_box_index-1];
  CallMsgBoxDraw(message_box_def.draw_initial_tilemap | 0x850000);
  CallMsgBoxModify(message_box_def.modify_box_func | 0x850000);
}

/**
* @brief Toggles the save confirmation and writes the highlighted option tilemap to RAM
* @brief Writes the message box tilemap in VRAM to RAM
*/
static void ToggleSaveConfirmationSelection(void) {  // 0x858507
  uint16 tilemap_row_size = sizeof(kSaveConfirmationSelectionTilemap) / 3;
  uint16 select_yes_offset = tilemap_row_size * 1;
  uint16 select_no_offset = tilemap_row_size * 2;

  save_confirmation_selection ^= kConfirmSave_Toggle;
  uint16 confirm_select_offset = select_yes_offset >> 1;
  if (save_confirmation_selection == kConfirmSave_No)
    confirm_select_offset = select_no_offset >> 1;
  uint16 index = (tilemap_row_size * 4) >> 1;
  MemCpy(ram3000.msgbox.tilemap + index, kSaveConfirmationSelectionTilemap + confirm_select_offset, tilemap_row_size);
  CopyToVram(addr_kVram_LargeMessageBox, ram3000.msgbox.tilemap, sizeof(ram3000.msgbox.tilemap), 1);
}

/**
* @brief Restores VRAM, HDMA channels, BG3 tilemap, and main screen layers and colors
*/
static void RestorePpuForMessageBox(void) {  // 0x85861A
  uint16 vram_backup_size = sizeof(ram4000.backups.backup_of_vram_0x5880_msgbox);
  CopyToVram(addr_kVram_FxBackup, ram4000.backups.backup_of_vram_0x5880_msgbox, vram_backup_size, 1);
  reg_HDMAEN = ram3000.msgbox.backup_of_enabled_hdma_channels;
  WriteReg(HDMAEN, ram3000.msgbox.backup_of_enabled_hdma_channels);
  gameplay_BG3SC = ram3000.msgbox.backup_of_bg3_tilemap_and_size;
  gameplay_TM = reg_TM;
  gameplay_CGWSEL = next_gameplay_CGWSEL;
  gameplay_CGADSUB = next_gameplay_CGADSUB;
  // Restore BG3 palette 6 color 1 to CGRAM
  WriteReg(CGADD, 0x19);
  WriteReg(CGDATA, LOBYTE(palette_buffer.bg3_pal_6[1]));
  WriteReg(CGDATA, HIBYTE(palette_buffer.bg3_pal_6[1]));
  // Restore BG3 palette 6 color 2 to CGRAM
  WriteReg(CGDATA, LOBYTE(palette_buffer.bg3_pal_6[2]));
  WriteReg(CGDATA, HIBYTE(palette_buffer.bg3_pal_6[2]));
}

/**
* @brief Expands the message box until it's reached the max radius
*/
static CoroutineRet OpenMessageBox_Async(void) {  // 0x85844C
  COROUTINE_BEGIN(coroutine_state_4, 0);
  for (message_box_animation_y_radius = 0;; message_box_animation_y_radius += 0x200) {
    COROUTINE_AWAIT(1, WaitForNMI_NoUpdate_Async());
    HandleMusicQueue();
    HandleSoundEffects();
    MsgBoxMakeHdmaTable();
    if (message_box_animation_y_radius == 0x200*12)
      break;
  }
  COROUTINE_END(0);
}

/**
* @brief Checks for input and handles the message box and sound depending on the message type
*/
static CoroutineRet HandleMessageBoxInteraction_Async(void) {  // 0x85846D
  COROUTINE_BEGIN(coroutine_state_4, 0);
  if (message_box_index == kMessageBox_23_WouldYouLikeToSave || message_box_index == kMessageBox_28_WouldYouLikeToSave_Gunship) {
    save_confirmation_selection = kConfirmSave_Yes;
    while (1) {
      do {
        COROUTINE_AWAIT(1, WaitForNMI_NoUpdate_Async());
        HandleMusicQueue();
        HandleSoundEffects();
        ReadJoypadInputs();
      } while (joypad1_newkeys == 0);
      if (joypad1_newkeys & kButton_A)
        break;
      if (joypad1_newkeys & kButton_B) {
        save_confirmation_selection = kConfirmSave_No;
        break;
      }
      if (joypad1_newkeys & (kButton_Select | kButton_Left | kButton_Right)) {
        ToggleSaveConfirmationSelection();
        QueueSfx1_Max6(kSfx1_MovedCursorToggleReserveMode);
      }
    }
  }
  else {
    my_counter = 10;
    if (message_box_index != kMessageBox_20_MapDataAccessCompleted && message_box_index != kMessageBox_21_EnergyRechargeCompleted 
        && message_box_index != kMessageBox_22_MissileReloadCompleted && message_box_index != kMessageBox_24_SaveCompleted)
  // Feature: Quick pickups
    if (enhanced_features0 & kFeatures0_InstantPickups) {
      my_counter = 30;
    }else{
      my_counter = 360;
      }
    do {
      COROUTINE_AWAIT(2, WaitForNMI_NoUpdate_Async());
      HandleMusicQueue();
      HandleSoundEffects();
    } while (--my_counter);
    do {
      COROUTINE_AWAIT(3, WaitForNMI_NoUpdate_Async());
      ReadJoypadInputs();
    } while ((bug_fix_counter < 1 ? joypad1_newkeys : joypad1_lastkeys) == 0);
  }
  COROUTINE_END(0);
}

/**
* @brief Shrinks the message box until it's gone
*/
static CoroutineRet CloseMessageBox_Async(void) {  // 0x858589
  COROUTINE_BEGIN(coroutine_state_4, 0);
  do {
    COROUTINE_AWAIT(1, WaitForNMI_NoUpdate_Async());
    HandleMusicQueue();
    HandleSoundEffects();
    MsgBoxMakeHdmaTable();
    message_box_animation_y_radius -= 512;
  } while ((int16)message_box_animation_y_radius >= 0);
  COROUTINE_END(0);
}

/**
* @brief Creates the message box and sets up the sound and PPU depending on the type of message
* @brief Runs until the message box is no longer displayed
* @param queued_message The message that has been queued for display
*/
CoroutineRet DisplayMessageBox_Async(uint16 queued_message) {  // 0x858080
  COROUTINE_BEGIN(coroutine_state_3, 0)
  message_box_index = queued_message;
  CancelSoundEffects();
  InitializePpuForMessageBoxes();
  ClearMessageBoxBg3Tilemap();
  InitializeMessageBox();
  COROUTINE_AWAIT(2, OpenMessageBox_Async());
  COROUTINE_AWAIT(3, HandleMessageBoxInteraction_Async());
  COROUTINE_AWAIT(4, CloseMessageBox_Async());

  if (message_box_index == kMessageBox_28_WouldYouLikeToSave_Gunship && save_confirmation_selection != kConfirmSave_No) {
    message_box_index = kMessageBox_24_SaveCompleted;
    ClearMessageBoxBg3Tilemap();
    QueueSfx1_Max6(kSfx1_Saving);

    my_counter = 160;
    do {
      HandleMusicQueue();
      HandleSoundEffects();
      COROUTINE_AWAIT(8, WaitForNMI_NoUpdate_Async());
    } while (--my_counter != 0);

    InitializeMessageBox();
    COROUTINE_AWAIT(5, OpenMessageBox_Async());
    COROUTINE_AWAIT(6, HandleMessageBoxInteraction_Async());
    COROUTINE_AWAIT(7, CloseMessageBox_Async());
    message_box_index = kMessageBox_28_WouldYouLikeToSave_Gunship;
  }
  ClearMessageBoxBg3Tilemap();
  RestorePpuForMessageBox();
  QueueSamusMovementSfx();

  if (message_box_index == kMessageBox_20_MapDataAccessCompleted) {
    game_state = kGameState_12_Pausing;
  }
  COROUTINE_END(0);
}

/**
* @brief Queues the message if it is not being displayed
* @param message The index into the message to be displayed
* @return int -1 if the message is not done being displayed, otherwise returns the save selection index
*/
int DisplayMessageBox_Poll(uint16 message) {
  if (message == message_box_index) {
    message_box_index = 0;
    return save_confirmation_selection;
  }
  queued_message_box_index = message;
  return -1;
}

/**
* @brief Queues the message to be displayed
* @param message The index into the message to be displayed
*/
void DisplayMessageBox(uint16 message) {
  queued_message_box_index = message;
}
