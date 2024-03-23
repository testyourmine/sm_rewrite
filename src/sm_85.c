// Message boxes
#include "ida_types.h"
#include "variables.h"
#include "funcs.h"
#include "sm_85.h"

uint16 message_box_das0l_value;

static void InitializePpuForMessageBoxes(void) {  // 0x858143
  save_confirmation_selection = kConfirmSave_Yes;
  WriteReg(HDMAEN, 0);
  WriteReg(CGADD, 0x19);
  WriteReg(CGDATA, 0xB1);
  WriteReg(CGDATA, 0xB);
  WriteReg(CGDATA, 0x1F);
  WriteReg(CGDATA, 0);
  ram3000.msgbox.backup_of_enabled_hdma_channels = reg_HDMAEN;
  ram3000.msgbox.backup_of_bg3_tilemap_and_size = gameplay_BG3SC;
  gameplay_BG3SC = 0x58;
  gameplay_TM = 23;
  gameplay_CGWSEL = 0;
  gameplay_CGADSUB = 0;
  WriteReg(COLDATA, 0x20);
  WriteReg(COLDATA, 0x40);
  WriteReg(COLDATA, 0x80);
  ReadReg(BG3HOFS);
  WriteReg(BG3HOFS, 0);
  WriteReg(BG3HOFS, 0);
  ReadReg(BG3VOFS);
  WriteReg(BG3VOFS, 0);
  WriteReg(BG3VOFS, 0);
  for (int i = 0x80; i >= 0; i -= 2)
    //*(uint16 *)((uint8 *)ram3000.pause_menu_map_tilemap + (uint16)i) = 0;
    ram3000.pause_menu_map_tilemap[i >> 1] = 0;
  WriteRegWord(VMADDL, addr_unk_605880);
  ReadRegWord(RDVRAML);
  WriteRegWord(DMAP1, 0x3981);
  WriteRegWord(A1T1L, ADDR16_OF_RAM(ram4000.backups.backup_of_vram_0x5880_msgbox));
  WriteRegWord(A1B1, 0x7E);
  WriteRegWord(DAS1L, 0x700);
  WriteRegWord(DAS10, 0);
  WriteRegWord(A2A1H, 0);
  WriteReg(VMAIN, 0x80);
  WriteReg(MDMAEN, 2);
}

static void ClearMessageBoxBg3Tilemap(void) {  // 0x8581F3
  int16 v0 = 0x6FE;
  do {
    //*(uint16 *)((uint8 *)ram3800.cinematic_bg_tilemap + (uint16)v0) = 0xe;
    ram3800.cleared_message_box_bg3_tilemap[v0 >> 1] = kTxt_Empty;
    v0 -= 2;
  } while (v0 >= 0);
  WriteRegWord(VMADDL, addr_unk_605880);
  WriteRegWord(DMAP1, 0x1801);
  WriteRegWord(A1T1L, ADDR16_OF_RAM(ram3800));
  WriteRegWord(A1B1, 0x7E);
  WriteRegWord(DAS1L, 0x700);
  WriteRegWord(DAS10, 0);
  WriteRegWord(A2A1H, 0);
  WriteReg(VMAIN, 0x80);
  WriteReg(MDMAEN, 2);
}

static uint16 WriteMessageTilemap(void) {  // 0x8582B8
  message_box_animation_y1_bottom_half = 112;
  message_box_animation_y0_bottom_half = 124;
  message_box_animation_y_radius = 0;
  for (int i = 0; i != 0xE0; i += 2)
    ram3000.pause_menu_map_tilemap[i >> 1] = 0;
  uint16 r0 = kMessageBoxDefs[message_box_index - 1].message_tilemap;
  uint16 r9 = kMessageBoxDefs[message_box_index].message_tilemap - r0;
  int n = r9 >> 1;
  r9 += 128;
  message_box_das0l_value = r9;
  uint16 v1 = 0x40;
  uint16 v2 = 0;
  do {
    //ram3000.pause_menu_map_tilemap[v1 + 256] = *(uint16 *)&RomPtr_85(r0)[v2];
    ram3000.msgbox.tilemap[v1 >> 1] = getMessageTilemap(r0)[v2 >> 1];
    v1 += 2;
    v2 += 2;
  } while (--n);
  return v1;
}

static void WriteLargeMessageBoxTilemap(void) {  // 0x85825A
  for (int i = 0; i != 0x40; i += 2)
    ram3000.msgbox.tilemap[i >> 1] = kLargeMsgBoxTopBottomBorderTilemap[i >> 1];
  uint16 i = WriteMessageTilemap();
  int n = 32;
  uint16 v1 = 0;
  do {
    ram3000.msgbox.tilemap[i >> 1] = kLargeMsgBoxTopBottomBorderTilemap[v1 >> 1];
    v1 += 2;
    i += 2;
  } while (--n);
}

static void WriteSmallMessageBoxTilemap(void) {  // 0x858289
  for (int i = 0; i != 0x40; i += 2)
    ram3000.msgbox.tilemap[i >> 1] = kSmallMsgBoxTopBottomBorderTilemap[i >> 1];
  uint16 i = WriteMessageTilemap();
  int n = 32;
  uint16 v1 = 0;
  do {
    ram3000.msgbox.tilemap[i >> 1] = kSmallMsgBoxTopBottomBorderTilemap[v1 >> 1];
    v1 += 2;
    i += 2;
  } while (--n);
}

static void CallMsgBoxDraw(uint32 ea) {
  switch (ea) {
  case fnWriteLargeMessageBoxTilemap: WriteLargeMessageBoxTilemap(); return;
  case fnWriteSmallMessageBoxTilemap: WriteSmallMessageBoxTilemap(); return;
  default: Unreachable();
  }
}

static void MsgBoxMakeHdmaTable(void) {
  message_box_animation_y2_top_half = (uint16)(0x7B00 - message_box_animation_y_radius) >> 8;
  message_box_animation_y3_top_half = 99;
  message_box_animation_y0_bottom_half = (uint16)(0x7C00 + message_box_animation_y_radius) >> 8;
  message_box_animation_y1_bottom_half = 148;
  uint16 v0 = 123;
  uint16 v1 = 124;
  uint16 r20 = 30;
  do {
    ram3000.msgbox.msg_box_anim_y_radius_neg[v0 - 94] = message_box_animation_y3_top_half - message_box_animation_y2_top_half;
    --message_box_animation_y3_top_half;
    --message_box_animation_y2_top_half;
    ram3000.msgbox.msg_box_anim_y_radius[v1 - 124] = message_box_animation_y1_bottom_half - message_box_animation_y0_bottom_half;
    --v0;
    ++message_box_animation_y1_bottom_half;
    ++message_box_animation_y0_bottom_half;
    ++v1;
  } while (--r20);
  int16 v2 = v1 * 2;
  do {
    *(uint16 *)((uint8 *)ram3000.pause_menu_map_tilemap + v2) = 0;
    v2 += 2;
  } while (v2 < 480);
}

static void SetupMessageBoxBg3YscrollHdma(void) {  // 0x858363
  //*(uint32 *)&ram3000.menu.palette_backup_in_menu[64] = -516947713;
  //ram3000.pause_menu_map_tilemap[450] = 12542;
  ram3000.msgbox.indirect_hdma[0] = 0xFF;
  WORD(ram3000.msgbox.indirect_hdma[1]) = 0x3000;
  ram3000.msgbox.indirect_hdma[3] = 0xE1;
  WORD(ram3000.msgbox.indirect_hdma[4]) = 0x30FE;
  ram3000.msgbox.indirect_hdma[6] = 0;
  WriteReg(DMAP6, 0x42);
  WriteReg(BBAD6, 0x12);
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
  WriteReg(HDMAEN, 0x40);
}

static void SetupPpuForActiveMessageBox(uint16 r52) {  // 0x85831E
  SetupMessageBoxBg3YscrollHdma();
  r52 += 0x5800;
  WriteRegWord(VMADDL, r52);
  WriteRegWord(DMAP1, 0x1801);
  WriteRegWord(A1T1L, ADDR16_OF_RAM(ram3000.msgbox.tilemap));
  WriteRegWord(A1B1, 0x7E);
  WriteRegWord(DAS1L, message_box_das0l_value);
  WriteRegWord(DAS10, 0);
  WriteRegWord(A2A1H, 0);
  WriteReg(VMAIN, 0x80);
  WriteReg(MDMAEN, 2);
}

static void DrawSpecialButtonAndSetupPpuForLargeMessageBox(uint16 a) {  // 0x8583D1
  uint16 v1 = 0;
  if ((a & kButton_A) == 0) {
    v1 = 2;
    if ((a & kButton_B) == 0) {
      v1 = 4;
      if ((a & kButton_X) == 0) {
        v1 = 6;
        if ((a & kButton_Y) == 0) {
          v1 = 8;
          if ((a & kButton_Select) == 0) {
            v1 = 10;
            if ((a & kButton_L) == 0) {
              v1 = 12;
              if ((a & kButton_R) == 0)
                v1 = 14;
            }
          }
        }
      }
    }
  }
  //*(uint16 *)((uint8 *)&ram3000.msgbox.tilemap + kMsgBoxSpecialButtonTilemapOffs[message_box_index - 1]) = kTileNumbersForButtonLetters[v1 >> 1];
  ram3000.msgbox.tilemap[kMsgBoxSpecialButtonTilemapOffs[message_box_index -1] >> 1] = kTileNumbersForButtonLetters[v1 >> 1];
  SetupPpuForActiveMessageBox(0x1A0);
}

static void DrawShootButtonAndSetupPpuForLargeMessageBox(void) {  // 0x8583C5
  DrawSpecialButtonAndSetupPpuForLargeMessageBox(button_config_shoot_x);
}

static void DrawRunButtonAndSetupPpuForLargeMessageBox(void) {  // 0x8583CC
  DrawSpecialButtonAndSetupPpuForLargeMessageBox(button_config_run_b);
}

static void SetupPpuForSmallMessageBox(void) {  // 0x858436
  SetupPpuForActiveMessageBox(0x1C0);
}

static void SetupPpuForLargeMessageBox(void) {  // 0x858441
  SetupPpuForActiveMessageBox(0x1A0);
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

static void InitializeMessageBox(void) {  // 0x858241
  int v0 = message_box_index - 1;
  CallMsgBoxDraw(kMessageBoxDefs[v0].draw_initial_tilemap | 0x850000);
  CallMsgBoxModify(kMessageBoxDefs[v0].modify_box_func | 0x850000);
}

static void ToggleSaveConfirmationSelection(void) {  // 0x858507
  save_confirmation_selection ^= kConfirmSave_No;
  uint16 v0 = 0x40;
  if (save_confirmation_selection == kConfirmSave_No)
    v0 = 0x80;
  uint16 v1 = 128;
  int r52 = 32;
  do {
    ram3000.msgbox.tilemap[v1] = kSaveConfirmationSelectionTilemap[v0 >> 1];
    ++v1;
    v0 += 2;
  } while (--r52);
  WriteRegWord(VMADDL, addr_unk_6059A0);
  WriteRegWord(DMAP1, 0x1801);
  WriteRegWord(A1T1L, ADDR16_OF_RAM(ram3000.msgbox.tilemap));
  WriteRegWord(A1B1, 0x7E);
  WriteRegWord(DAS1L, 0x180);
  WriteRegWord(DAS10, 0);
  WriteRegWord(A2A1H, 0);
  WriteReg(VMAIN, 0x80);
  WriteReg(MDMAEN, 2);
}

static void RestorePpuForMessageBox(void) {  // 0x85861A
  WriteRegWord(VMADDL, addr_unk_605880);
  WriteRegWord(DMAP1, 0x1801);
  WriteRegWord(A1T1L, ADDR16_OF_RAM(ram4000.backups.backup_of_vram_0x5880_msgbox));
  WriteRegWord(A1B1, 0x7E);
  WriteRegWord(DAS1L, 0x700);
  WriteRegWord(DAS10, 0);
  WriteRegWord(A2A1H, 0);
  WriteReg(VMAIN, 0x80);
  WriteReg(MDMAEN, 2);
  reg_HDMAEN = ram3000.msgbox.backup_of_enabled_hdma_channels;
  WriteReg(HDMAEN, ram3000.msgbox.backup_of_enabled_hdma_channels);
  gameplay_BG3SC = ram3000.msgbox.backup_of_bg3_tilemap_and_size;
  gameplay_TM = reg_TM;
  gameplay_CGWSEL = next_gameplay_CGWSEL;
  gameplay_CGADSUB = next_gameplay_CGADSUB;
  WriteReg(CGADD, 0x19);
  WriteReg(CGDATA, palette_buffer.bg3_pal_6[1]);
  WriteReg(CGDATA, HIBYTE(palette_buffer.bg3_pal_6[1]));
  WriteReg(CGDATA, palette_buffer.bg3_pal_6[2]);
  WriteReg(CGDATA, HIBYTE(palette_buffer.bg3_pal_6[2]));
}

static CoroutineRet OpenMessageBox_Async(void) {  // 0x85844C
  COROUTINE_BEGIN(coroutine_state_4, 0);
  for (message_box_animation_y_radius = 0;; message_box_animation_y_radius += 512) {
    COROUTINE_AWAIT(1, WaitForNMI_NoUpdate_Async());
    HandleMusicQueue();
    HandleSoundEffects();
    MsgBoxMakeHdmaTable();
    if (message_box_animation_y_radius == 0x1800)
      break;
  }
  COROUTINE_END(0);
}

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
      } while (!joypad1_newkeys);
      if ((joypad1_newkeys & kButton_A) != 0)
        break;
      if ((joypad1_newkeys & kButton_B) != 0) {
        save_confirmation_selection = kConfirmSave_No;
        goto GETOUT;
      }
      if ((joypad1_newkeys & (kButton_Select | kButton_Left | kButton_Right)) != 0) {
        ToggleSaveConfirmationSelection();
        QueueSfx1_Max6(kSfx1_MovedCursorToggleReserveMode);
      }
    }
  } else {
    my_counter = 10;
    if (message_box_index != kMessageBox_20_MapDataAccessCompleted && message_box_index != kMessageBox_21_EnergyRechargeCompleted 
        && message_box_index != kMessageBox_22_MissileReloadCompleted && message_box_index != kMessageBox_24_SaveCompleted)
      my_counter = 360;
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
GETOUT:;
  COROUTINE_END(0);
}

static CoroutineRet CloseMessageBox_Async(void) {  // 0x858589
  COROUTINE_BEGIN(coroutine_state_4, 0);
  do {
    COROUTINE_AWAIT(1, WaitForNMI_NoUpdate_Async());
    HandleMusicQueue();
    HandleSoundEffects();
    MsgBoxMakeHdmaTable();
    message_box_animation_y_radius -= 512;
  } while (sign16(message_box_animation_y_radius) == 0);
  COROUTINE_END(0);
}

CoroutineRet DisplayMessageBox_Async(uint16 a) {  // 0x858080
  COROUTINE_BEGIN(coroutine_state_3, 0)
  message_box_index = a;
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
    } while (--my_counter);

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
  //  else if (message_box_index == 28 || message_box_index == 23) {
  //    return save_confirmation_selection;
  //  }
  //  return 0;
}

int DisplayMessageBox_Poll(uint16 a) {
  if (a == message_box_index) {
    message_box_index = 0;
    return save_confirmation_selection;
  }
  queued_message_box_index = a;
  return -1;
}

void DisplayMessageBox(uint16 a) {  // 0x858080
  queued_message_box_index = a;
}
