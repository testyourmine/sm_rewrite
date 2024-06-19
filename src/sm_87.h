#pragma once


#define ANIMTILE_INSTR(INSTR) (addr_kAnimtiles_IList_##INSTR)
#define ANIMTILE_INSTR_DRAW(INSTR, ENTRY, OFFSET) (addr_kAnimtiles_IList_##INSTR + ENTRY*4 + OFFSET*2)
#define ANIMTILE_INSTR_FUNC(INSTR, ENTRY, OFFSET) (addr_kAnimtiles_IList_##INSTR + ENTRY*4 + OFFSET*2)

AnimtilesObject get_AnimtilesObject(uint16 anim_tile_ptr) {
  switch(anim_tile_ptr) {
    case addr_kAnimtiles_Nothing                   : return (AnimtilesObject){ .instruction_list = ANIMTILE_INSTR(Nothing)                   , .size = 0x0   , .vram_addr = 0x0    };
    case addr_kAnimtiles_VerticalSpikes            : return (AnimtilesObject){ .instruction_list = ANIMTILE_INSTR(VerticalSpikes)            , .size = 0x80  , .vram_addr = 0x3880 };
    case addr_kAnimtiles_HorizontalSpikes          : return (AnimtilesObject){ .instruction_list = ANIMTILE_INSTR(HorizontalSpikes)          , .size = 0x80  , .vram_addr = 0x3d60 };
    case addr_kAnimtiles_CrateriaLake              : return (AnimtilesObject){ .instruction_list = ANIMTILE_INSTR(CrateriaLake)              , .size = 0x200 , .vram_addr = 0x1b00 };
    case addr_kAnimtiles_CrateriaLava_Unused1      : return (AnimtilesObject){ .instruction_list = ANIMTILE_INSTR(CrateriaLava_Unused)       , .size = 0xc0  , .vram_addr = 0xa00  };
    case addr_kAnimtiles_WreckedShipScreen         : return (AnimtilesObject){ .instruction_list = ANIMTILE_INSTR(WreckedShipScreen)         , .size = 0x80  , .vram_addr = 0x19c0 };
    case addr_kAnimtiles_WreckedShipTreadmillRight : return (AnimtilesObject){ .instruction_list = ANIMTILE_INSTR(WreckedShipTreadmillRight) , .size = 0x20  , .vram_addr = 0xe0   };
    case addr_kAnimtiles_WreckedShipTreadmillLeft  : return (AnimtilesObject){ .instruction_list = ANIMTILE_INSTR(WreckedShipTreadmillLeft)  , .size = 0x20  , .vram_addr = 0xe0   };
    case addr_kAnimtiles_BrinstarMouth             : return (AnimtilesObject){ .instruction_list = ANIMTILE_INSTR(BrinstarMouth)             , .size = 0xe0  , .vram_addr = 0x410  };
    case addr_kAnimtiles_MaridiaSandCeiling        : return (AnimtilesObject){ .instruction_list = ANIMTILE_INSTR(MaridiaSandCeiling)        , .size = 0x40  , .vram_addr = 0x1000 };
    case addr_kAnimtiles_MaridiaSandFalling        : return (AnimtilesObject){ .instruction_list = ANIMTILE_INSTR(MaridiaSandFalling)        , .size = 0x20  , .vram_addr = 0x1020 };
    case addr_kAnimtiles_Lava                      : return (AnimtilesObject){ .instruction_list = ANIMTILE_INSTR(Lava)                      , .size = 0x40  , .vram_addr = 0x4280 };
    case addr_kAnimtiles_Acid                      : return (AnimtilesObject){ .instruction_list = ANIMTILE_INSTR(Acid)                      , .size = 0x40  , .vram_addr = 0x4280 };
    case addr_kAnimtiles_Rain                      : return (AnimtilesObject){ .instruction_list = ANIMTILE_INSTR(Rain)                      , .size = 0x50  , .vram_addr = 0x4280 };
    case addr_kAnimtiles_Spores                    : return (AnimtilesObject){ .instruction_list = ANIMTILE_INSTR(Spores)                    , .size = 0x30  , .vram_addr = 0x4280 };
    case addr_kAnimtiles_TourianStatue_Phantoon    : return (AnimtilesObject){ .instruction_list = ANIMTILE_INSTR(TourianStatue_Phantoon)    , .size = 0x80  , .vram_addr = 0x7800 };
    case addr_kAnimtiles_TourianStatue_Ridley      : return (AnimtilesObject){ .instruction_list = ANIMTILE_INSTR(TourianStatue_Ridley)      , .size = 0x40  , .vram_addr = 0x7220 };
    case addr_kAnimtiles_TourianStatue_Kraid       : return (AnimtilesObject){ .instruction_list = ANIMTILE_INSTR(TourianStatue_Kraid)       , .size = 0x40  , .vram_addr = 0xb40  };
    case addr_kAnimtiles_TourianStatue_Draygon     : return (AnimtilesObject){ .instruction_list = ANIMTILE_INSTR(TourianStatue_Draygon)     , .size = 0x80  , .vram_addr = 0xca0  };
    default: Unreachable(); return (AnimtilesObject){0};
  }
}

AnimtilesEntry get_AnimtilesEntry(uint16 instr_ptr) {
  switch(instr_ptr) {
    case ANIMTILE_INSTR_DRAW(VerticalSpikes, 0, 0)             : return (AnimtilesEntry){ .timer = 8, .tile_src = 0x9c04 };
    case ANIMTILE_INSTR_DRAW(VerticalSpikes, 1, 0)             : return (AnimtilesEntry){ .timer = 8, .tile_src = 0x9c84 };
    case ANIMTILE_INSTR_DRAW(VerticalSpikes, 2, 0)             : return (AnimtilesEntry){ .timer = 8, .tile_src = 0x9d04 };
    case ANIMTILE_INSTR_DRAW(VerticalSpikes, 3, 0)             : return (AnimtilesEntry){ .timer = 8, .tile_src = 0x9c84 };
    case ANIMTILE_INSTR_FUNC(VerticalSpikes, 4, 0)             : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_Goto), .instr_list_ptr1 = ANIMTILE_INSTR_DRAW(VerticalSpikes, 0, 0) };

    case ANIMTILE_INSTR_DRAW(HorizontalSpikes, 0, 0)           : return (AnimtilesEntry){ .timer = 8, .tile_src = 0x9d84 };
    case ANIMTILE_INSTR_DRAW(HorizontalSpikes, 1, 0)           : return (AnimtilesEntry){ .timer = 8, .tile_src = 0x9e04 };
    case ANIMTILE_INSTR_DRAW(HorizontalSpikes, 2, 0)           : return (AnimtilesEntry){ .timer = 8, .tile_src = 0x9e84 };
    case ANIMTILE_INSTR_DRAW(HorizontalSpikes, 3, 0)           : return (AnimtilesEntry){ .timer = 8, .tile_src = 0x9e04 };
    case ANIMTILE_INSTR_FUNC(HorizontalSpikes, 4, 0)           : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_Goto), .instr_list_ptr1 = ANIMTILE_INSTR_DRAW(HorizontalSpikes, 0, 0) };

    case ANIMTILE_INSTR_DRAW(CrateriaLake, 0, 0)               : return (AnimtilesEntry){ .timer = 10, .tile_src = 0x8564 };
    case ANIMTILE_INSTR_DRAW(CrateriaLake, 1, 0)               : return (AnimtilesEntry){ .timer = 10, .tile_src = 0x8764 };
    case ANIMTILE_INSTR_DRAW(CrateriaLake, 2, 0)               : return (AnimtilesEntry){ .timer = 10, .tile_src = 0x8964 };
    case ANIMTILE_INSTR_DRAW(CrateriaLake, 3, 0)               : return (AnimtilesEntry){ .timer = 10, .tile_src = 0x8764 };
    case ANIMTILE_INSTR_FUNC(CrateriaLake, 4, 0)               : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_Goto), .instr_list_ptr1 = ANIMTILE_INSTR_DRAW(CrateriaLake, 0, 0) };

    case ANIMTILE_INSTR_DRAW(CrateriaLava_Unused, 0, 0)        : return (AnimtilesEntry){ .timer = 10, .tile_src = 0x8b64 };
    case ANIMTILE_INSTR_DRAW(CrateriaLava_Unused, 1, 0)        : return (AnimtilesEntry){ .timer = 10, .tile_src = 0x8c24 };
    case ANIMTILE_INSTR_DRAW(CrateriaLava_Unused, 2, 0)        : return (AnimtilesEntry){ .timer = 10, .tile_src = 0x8ce4 };
    case ANIMTILE_INSTR_DRAW(CrateriaLava_Unused, 3, 0)        : return (AnimtilesEntry){ .timer = 10, .tile_src = 0x8da4 };
    case ANIMTILE_INSTR_FUNC(CrateriaLava_Unused, 4, 0)        : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_Goto), .instr_list_ptr1 = ANIMTILE_INSTR_DRAW(CrateriaLava_Unused, 0, 0) };

    case ANIMTILE_INSTR_FUNC(WreckedShipScreen, 0, 0)          : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_WaitUntilAreaBossDead_DoubleRet) };
    case ANIMTILE_INSTR_DRAW(WreckedShipScreen, 1, -1)         : return (AnimtilesEntry){ .timer = 10, .tile_src = 0x8ee4 };
    case ANIMTILE_INSTR_DRAW(WreckedShipScreen, 2, -1)         : return (AnimtilesEntry){ .timer = 10, .tile_src = 0x8f64 };
    case ANIMTILE_INSTR_DRAW(WreckedShipScreen, 3, -1)         : return (AnimtilesEntry){ .timer = 10, .tile_src = 0x8fe4 };
    case ANIMTILE_INSTR_DRAW(WreckedShipScreen, 4, -1)         : return (AnimtilesEntry){ .timer = 10, .tile_src = 0x8f64 };
    case ANIMTILE_INSTR_FUNC(WreckedShipScreen, 5, -1)         : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_Goto), .instr_list_ptr1 = ANIMTILE_INSTR_DRAW(WreckedShipScreen, 1, -1) };

    case ANIMTILE_INSTR_FUNC(WreckedShipTreadmillRight, 0, 0)  : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_WaitUntilAreaBossDead_DoubleRet) };
    case ANIMTILE_INSTR_DRAW(WreckedShipTreadmillRight, 1, -1) : return (AnimtilesEntry){ .timer = 1, .tile_src = 0x8e64 };
    case ANIMTILE_INSTR_DRAW(WreckedShipTreadmillRight, 2, -1) : return (AnimtilesEntry){ .timer = 1, .tile_src = 0x8e84 };
    case ANIMTILE_INSTR_DRAW(WreckedShipTreadmillRight, 3, -1) : return (AnimtilesEntry){ .timer = 1, .tile_src = 0x8ea4 };
    case ANIMTILE_INSTR_DRAW(WreckedShipTreadmillRight, 4, -1) : return (AnimtilesEntry){ .timer = 1, .tile_src = 0x8ec4 };
    case ANIMTILE_INSTR_FUNC(WreckedShipTreadmillRight, 5, -1) : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_Goto), .instr_list_ptr1 = ANIMTILE_INSTR_DRAW(WreckedShipTreadmillRight, 1, -1) };

    case ANIMTILE_INSTR_FUNC(WreckedShipTreadmillLeft, 0, 0)   : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_WaitUntilAreaBossDead_DoubleRet) };
    case ANIMTILE_INSTR_DRAW(WreckedShipTreadmillLeft, 1, -1)  : return (AnimtilesEntry){ .timer = 1, .tile_src = 0x8ec4 };
    case ANIMTILE_INSTR_DRAW(WreckedShipTreadmillLeft, 2, -1)  : return (AnimtilesEntry){ .timer = 1, .tile_src = 0x8ea4 };
    case ANIMTILE_INSTR_DRAW(WreckedShipTreadmillLeft, 3, -1)  : return (AnimtilesEntry){ .timer = 1, .tile_src = 0x8e84 };
    case ANIMTILE_INSTR_DRAW(WreckedShipTreadmillLeft, 4, -1)  : return (AnimtilesEntry){ .timer = 1, .tile_src = 0x8e64 };
    case ANIMTILE_INSTR_FUNC(WreckedShipTreadmillLeft, 5, -1)  : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_Goto), .instr_list_ptr1 = ANIMTILE_INSTR_DRAW(WreckedShipTreadmillLeft, 1, -1) };

    case ANIMTILE_INSTR_DRAW(BrinstarMouth, 0, 0)              : return (AnimtilesEntry){ .timer = 16, .tile_src = 0x9964 };
    case ANIMTILE_INSTR_DRAW(BrinstarMouth, 1, 0)              : return (AnimtilesEntry){ .timer = 16, .tile_src = 0x9a44 };
    case ANIMTILE_INSTR_DRAW(BrinstarMouth, 2, 0)              : return (AnimtilesEntry){ .timer = 16, .tile_src = 0x9b24 };
    case ANIMTILE_INSTR_DRAW(BrinstarMouth, 3, 0)              : return (AnimtilesEntry){ .timer = 16, .tile_src = 0x9a44 };
    case ANIMTILE_INSTR_FUNC(BrinstarMouth, 4, 0)              : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_Goto), .instr_list_ptr1 = ANIMTILE_INSTR_DRAW(BrinstarMouth, 0, 0) };

    case ANIMTILE_INSTR_DRAW(MaridiaSandCeiling, 0, 0)         : return (AnimtilesEntry){ .timer = 10, .tile_src = 0x91e4 };
    case ANIMTILE_INSTR_DRAW(MaridiaSandCeiling, 1, 0)         : return (AnimtilesEntry){ .timer = 10, .tile_src = 0x9224 };
    case ANIMTILE_INSTR_DRAW(MaridiaSandCeiling, 2, 0)         : return (AnimtilesEntry){ .timer = 10, .tile_src = 0x9264 };
    case ANIMTILE_INSTR_DRAW(MaridiaSandCeiling, 3, 0)         : return (AnimtilesEntry){ .timer = 10, .tile_src = 0x92a4 };
    case ANIMTILE_INSTR_FUNC(MaridiaSandCeiling, 4, 0)         : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_Goto), .instr_list_ptr1 = ANIMTILE_INSTR_DRAW(MaridiaSandCeiling, 0, 0) };

    case ANIMTILE_INSTR_DRAW(MaridiaSandFalling, 0, 0)         : return (AnimtilesEntry){ .timer = 10, .tile_src = 0x9164 };
    case ANIMTILE_INSTR_DRAW(MaridiaSandFalling, 1, 0)         : return (AnimtilesEntry){ .timer = 10, .tile_src = 0x9184 };
    case ANIMTILE_INSTR_DRAW(MaridiaSandFalling, 2, 0)         : return (AnimtilesEntry){ .timer = 10, .tile_src = 0x91a4 };
    case ANIMTILE_INSTR_DRAW(MaridiaSandFalling, 3, 0)         : return (AnimtilesEntry){ .timer = 10, .tile_src = 0x91c4 };
    case ANIMTILE_INSTR_FUNC(MaridiaSandFalling, 4, 0)         : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_Goto), .instr_list_ptr1 = ANIMTILE_INSTR_DRAW(MaridiaSandFalling, 0, 0) };

    case ANIMTILE_INSTR_FUNC(Nothing, 0, 0)                    : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_Delete) };

    case ANIMTILE_INSTR_DRAW(Lava, 0, 0)                       : return (AnimtilesEntry){ .timer = 13, .tile_src = 0xa564 };
    case ANIMTILE_INSTR_DRAW(Lava, 1, 0)                       : return (AnimtilesEntry){ .timer = 13, .tile_src = 0xa5a4 };
    case ANIMTILE_INSTR_DRAW(Lava, 2, 0)                       : return (AnimtilesEntry){ .timer = 13, .tile_src = 0xa5e4 };
    case ANIMTILE_INSTR_DRAW(Lava, 3, 0)                       : return (AnimtilesEntry){ .timer = 13, .tile_src = 0xa624 };
    case ANIMTILE_INSTR_DRAW(Lava, 4, 0)                       : return (AnimtilesEntry){ .timer = 13, .tile_src = 0xa664 };
    case ANIMTILE_INSTR_FUNC(Lava, 5, 0)                       : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_Goto), .instr_list_ptr1 = ANIMTILE_INSTR_DRAW(Lava, 0, 0) };

    case ANIMTILE_INSTR_DRAW(Acid, 0, 0)                       : return (AnimtilesEntry){ .timer = 10, .tile_src = 0xa6a4 };
    case ANIMTILE_INSTR_DRAW(Acid, 1, 0)                       : return (AnimtilesEntry){ .timer = 10, .tile_src = 0xa6e4 };
    case ANIMTILE_INSTR_DRAW(Acid, 2, 0)                       : return (AnimtilesEntry){ .timer = 10, .tile_src = 0xa724 };
    case ANIMTILE_INSTR_DRAW(Acid, 3, 0)                       : return (AnimtilesEntry){ .timer = 10, .tile_src = 0xa764 };
    case ANIMTILE_INSTR_DRAW(Acid, 4, 0)                       : return (AnimtilesEntry){ .timer = 10, .tile_src = 0xa7a4 };
    case ANIMTILE_INSTR_FUNC(Acid, 5, 0)                       : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_Goto), .instr_list_ptr1 = ANIMTILE_INSTR_DRAW(Acid, 0, 0) };

    case ANIMTILE_INSTR_DRAW(Rain, 0, 0)                       : return (AnimtilesEntry){ .timer = 10, .tile_src = 0xa874 };
    case ANIMTILE_INSTR_DRAW(Rain, 1, 0)                       : return (AnimtilesEntry){ .timer = 10, .tile_src = 0xa8c4 };
    case ANIMTILE_INSTR_DRAW(Rain, 2, 0)                       : return (AnimtilesEntry){ .timer = 10, .tile_src = 0xa914 };
    case ANIMTILE_INSTR_DRAW(Rain, 3, 0)                       : return (AnimtilesEntry){ .timer = 10, .tile_src = 0xa964 };
    case ANIMTILE_INSTR_DRAW(Rain, 4, 0)                       : return (AnimtilesEntry){ .timer = 10, .tile_src = 0xa9b4 };
    case ANIMTILE_INSTR_FUNC(Rain, 5, 0)                       : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_Goto), .instr_list_ptr1 = ANIMTILE_INSTR_DRAW(Rain, 0, 0) };

    case ANIMTILE_INSTR_DRAW(Spores, 0, 0)                     : return (AnimtilesEntry){ .timer = 10, .tile_src = 0xa7e4 };
    case ANIMTILE_INSTR_DRAW(Spores, 1, 0)                     : return (AnimtilesEntry){ .timer = 10, .tile_src = 0xa814 };
    case ANIMTILE_INSTR_DRAW(Spores, 2, 0)                     : return (AnimtilesEntry){ .timer = 10, .tile_src = 0xa844 };
    case ANIMTILE_INSTR_FUNC(Spores, 3, 0)                     : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_Goto), .instr_list_ptr1 = ANIMTILE_INSTR_DRAW(Spores, 0, 0) };

    case ANIMTILE_INSTR_FUNC(TourianStatue_Phantoon, 0, 0)     : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_TourianStatueSetState), .tourian_statue_state = kStatueState_PhantoonProcessing };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Phantoon, 1, 0)     : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_GotoIfEventHappened), .game_event = kEvent_6_PhantoonStatueGray, .instr_list_ptr2 = ANIMTILE_INSTR_FUNC(TourianStatue_Phantoon, 23, 1) };
    case ANIMTILE_INSTR_DRAW(TourianStatue_Phantoon, 2, 1)     : return (AnimtilesEntry){ .timer = 6, .tile_src = 0x9364 };
    case ANIMTILE_INSTR_DRAW(TourianStatue_Phantoon, 3, 1)     : return (AnimtilesEntry){ .timer = 12, .tile_src = 0x93e4 };
    case ANIMTILE_INSTR_DRAW(TourianStatue_Phantoon, 4, 1)     : return (AnimtilesEntry){ .timer = 12, .tile_src = 0x9464 };
    case ANIMTILE_INSTR_DRAW(TourianStatue_Phantoon, 5, 1)     : return (AnimtilesEntry){ .timer = 12, .tile_src = 0x93e4 };
    case ANIMTILE_INSTR_DRAW(TourianStatue_Phantoon, 6, 1)     : return (AnimtilesEntry){ .timer = 16, .tile_src = 0x9364 };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Phantoon, 7, 1)     : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_GotoIfBossBitSetInArea), .boss_bit = kBossBit_AreaBoss, .area = kArea_3_WreckedShip, .instr_list_ptr2 = ANIMTILE_INSTR_FUNC(TourianStatue_Phantoon, 10, 2) };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Phantoon, 8, 2)     : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_TourianStatueClearState), .tourian_statue_state = kStatueState_PhantoonProcessing };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Phantoon, 9, 2)     : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_Goto), .instr_list_ptr1 = ANIMTILE_INSTR_DRAW(TourianStatue_Phantoon, 3, 1) };

    case ANIMTILE_INSTR_FUNC(TourianStatue_Phantoon, 10, 2)    : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_GotoIfTourianStatueBusy), .instr_list_ptr1 = ANIMTILE_INSTR_DRAW(TourianStatue_Phantoon, 3, 1) };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Phantoon, 11, 2)    : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_TourianStatueSetState), .tourian_statue_state = kStatueState_ReleasingBossLock };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Phantoon, 12, 2)    : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_Clear3PaletteColors), .palette_offset =  0x158 };
    case ANIMTILE_INSTR_DRAW(TourianStatue_Phantoon, 13, 2)    : return (AnimtilesEntry){ .timer = 16, .tile_src = 0x93e4 };
    case ANIMTILE_INSTR_DRAW(TourianStatue_Phantoon, 14, 2)    : return (AnimtilesEntry){ .timer = 16, .tile_src = 0x9464 };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Phantoon, 15, 2)    : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_SpawnTourianStatueEyeGlow), .eproj_param = 0 };
    case ANIMTILE_INSTR_DRAW(TourianStatue_Phantoon, 16, 2)    : return (AnimtilesEntry){ .timer = 192, .tile_src = 0x97e4 };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Phantoon, 17, 2)    : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_SpawnTourianStatueSoul), .eproj_param = 0 };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Phantoon, 18, 2)    : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_SpawnPalfxObj), .palfx_id = 0xf755 };
    case ANIMTILE_INSTR_DRAW(TourianStatue_Phantoon, 19, 2)    : return (AnimtilesEntry){ .timer = 128, .tile_src = 0x97e4 };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Phantoon, 20, 2)    : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_SetEventHappened), .game_event = kEvent_6_PhantoonStatueGray };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Phantoon, 21, 2)    : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_TourianStatueClearState), .tourian_statue_state = kStatueState_ReleasingBossLock | kStatueState_PhantoonProcessing };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Phantoon, 22, 2)    : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_Delete) };

    case ANIMTILE_INSTR_FUNC(TourianStatue_Phantoon, 23, 1)    : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_TourianStatueClearState), .tourian_statue_state = kStatueState_ReleasingBossLock | kStatueState_PhantoonProcessing };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Phantoon, 24, 1)    : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_Write8PaletteColors), .palette_offset =  0x140 };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Phantoon, 25, 1)    : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_Delete) };

    case ANIMTILE_INSTR_FUNC(TourianStatue_Ridley, 0, 0)       : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_TourianStatueSetState), .tourian_statue_state = kStatueState_RidleyProcessing };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Ridley, 1, 0)       : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_GotoIfEventHappened), .game_event = kEvent_7_RidleyStatueGray, .instr_list_ptr2 = ANIMTILE_INSTR_FUNC(TourianStatue_Ridley, 23, 1) };
    case ANIMTILE_INSTR_DRAW(TourianStatue_Ridley, 2, 1)       : return (AnimtilesEntry){ .timer = 10, .tile_src = 0x94e4 };
    case ANIMTILE_INSTR_DRAW(TourianStatue_Ridley, 3, 1)       : return (AnimtilesEntry){ .timer = 12, .tile_src = 0x9524 };
    case ANIMTILE_INSTR_DRAW(TourianStatue_Ridley, 4, 1)       : return (AnimtilesEntry){ .timer = 12, .tile_src = 0x9564 };
    case ANIMTILE_INSTR_DRAW(TourianStatue_Ridley, 5, 1)       : return (AnimtilesEntry){ .timer = 12, .tile_src = 0x9524 };
    case ANIMTILE_INSTR_DRAW(TourianStatue_Ridley, 6, 1)       : return (AnimtilesEntry){ .timer = 16, .tile_src = 0x94e4 };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Ridley, 7, 1)       : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_GotoIfBossBitSetInArea), .boss_bit = kBossBit_AreaBoss, .area = kArea_2_Norfair, .instr_list_ptr2 = ANIMTILE_INSTR_FUNC(TourianStatue_Ridley, 10, 2) };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Ridley, 8, 2)       : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_TourianStatueClearState), .tourian_statue_state = kStatueState_RidleyProcessing };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Ridley, 9, 2)       : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_Goto), .instr_list_ptr1 = ANIMTILE_INSTR_DRAW(TourianStatue_Ridley, 3, 1) };

    case ANIMTILE_INSTR_FUNC(TourianStatue_Ridley, 10, 2)      : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_GotoIfTourianStatueBusy), .instr_list_ptr1 = ANIMTILE_INSTR_DRAW(TourianStatue_Ridley, 3, 1) };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Ridley, 11, 2)      : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_TourianStatueSetState), .tourian_statue_state = kStatueState_ReleasingBossLock };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Ridley, 12, 2)      : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_Clear3PaletteColors), .palette_offset =  0x132 };
    case ANIMTILE_INSTR_DRAW(TourianStatue_Ridley, 13, 2)      : return (AnimtilesEntry){ .timer = 16, .tile_src = 0x9524 };
    case ANIMTILE_INSTR_DRAW(TourianStatue_Ridley, 14, 2)      : return (AnimtilesEntry){ .timer = 16, .tile_src = 0x9564 };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Ridley, 15, 2)      : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_SpawnTourianStatueEyeGlow), .eproj_param = 2 };
    case ANIMTILE_INSTR_DRAW(TourianStatue_Ridley, 16, 2)      : return (AnimtilesEntry){ .timer = 192, .tile_src = 0x9864 };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Ridley, 17, 2)      : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_SpawnTourianStatueSoul), .eproj_param = 2 };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Ridley, 18, 2)      : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_SpawnPalfxObj), .palfx_id = 0xf751 };
    case ANIMTILE_INSTR_DRAW(TourianStatue_Ridley, 19, 2)      : return (AnimtilesEntry){ .timer = 128, .tile_src = 0x9864 };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Ridley, 20, 2)      : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_SetEventHappened), .game_event = kEvent_7_RidleyStatueGray };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Ridley, 21, 2)      : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_TourianStatueClearState), .tourian_statue_state = kStatueState_ReleasingBossLock | kStatueState_RidleyProcessing };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Ridley, 22, 2)      : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_Delete) };

    case ANIMTILE_INSTR_FUNC(TourianStatue_Ridley, 23, 1)      : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_TourianStatueClearState), .tourian_statue_state = kStatueState_ReleasingBossLock | kStatueState_RidleyProcessing };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Ridley, 24, 1)      : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_Write8PaletteColors), .palette_offset =  0x120 };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Ridley, 25, 1)      : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_Delete) };

    case ANIMTILE_INSTR_FUNC(TourianStatue_Kraid, 0, 0)        : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_TourianStatueSetState), .tourian_statue_state = kStatueState_KraidProcessing };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Kraid, 1, 0)        : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_GotoIfEventHappened), .game_event = kEvent_9_KraidStatueGray, .instr_list_ptr2 = ANIMTILE_INSTR_FUNC(TourianStatue_Kraid, 23, 1) };
    case ANIMTILE_INSTR_DRAW(TourianStatue_Kraid, 2, 1)        : return (AnimtilesEntry){ .timer = 4, .tile_src = 0x9724 };
    case ANIMTILE_INSTR_DRAW(TourianStatue_Kraid, 3, 1)        : return (AnimtilesEntry){ .timer = 12, .tile_src = 0x9764 };
    case ANIMTILE_INSTR_DRAW(TourianStatue_Kraid, 4, 1)        : return (AnimtilesEntry){ .timer = 12, .tile_src = 0x97a4 };
    case ANIMTILE_INSTR_DRAW(TourianStatue_Kraid, 5, 1)        : return (AnimtilesEntry){ .timer = 12, .tile_src = 0x9764 };
    case ANIMTILE_INSTR_DRAW(TourianStatue_Kraid, 6, 1)        : return (AnimtilesEntry){ .timer = 16, .tile_src = 0x9724 };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Kraid, 7, 1)        : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_GotoIfBossBitSetInArea), .boss_bit = kBossBit_AreaBoss, .area = kArea_1_Brinstar, .instr_list_ptr2 = ANIMTILE_INSTR_FUNC(TourianStatue_Kraid, 10, 2) };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Kraid, 8, 2)        : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_TourianStatueClearState), .tourian_statue_state = kStatueState_KraidProcessing };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Kraid, 9, 2)        : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_Goto), .instr_list_ptr1 = ANIMTILE_INSTR_DRAW(TourianStatue_Kraid, 3, 1) };

    case ANIMTILE_INSTR_FUNC(TourianStatue_Kraid, 10, 2)       : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_GotoIfTourianStatueBusy), .instr_list_ptr1 = ANIMTILE_INSTR_DRAW(TourianStatue_Kraid, 3, 1) };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Kraid, 11, 2)       : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_TourianStatueSetState), .tourian_statue_state = kStatueState_ReleasingBossLock };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Kraid, 12, 2)       : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_Clear3PaletteColors), .palette_offset =   0xf8 };
    case ANIMTILE_INSTR_DRAW(TourianStatue_Kraid, 13, 2)       : return (AnimtilesEntry){ .timer = 16, .tile_src = 0x9764 };
    case ANIMTILE_INSTR_DRAW(TourianStatue_Kraid, 14, 2)       : return (AnimtilesEntry){ .timer = 16, .tile_src = 0x97a4 };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Kraid, 15, 2)       : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_SpawnTourianStatueEyeGlow), .eproj_param = 6 };
    case ANIMTILE_INSTR_DRAW(TourianStatue_Kraid, 16, 2)       : return (AnimtilesEntry){ .timer = 192, .tile_src = 0x98a4 };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Kraid, 17, 2)       : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_SpawnTourianStatueSoul), .eproj_param = 6 };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Kraid, 18, 2)       : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_SpawnPalfxObj), .palfx_id = 0xf74d };
    case ANIMTILE_INSTR_DRAW(TourianStatue_Kraid, 19, 2)       : return (AnimtilesEntry){ .timer = 128, .tile_src = 0x98a4 };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Kraid, 20, 2)       : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_SetEventHappened), .game_event = kEvent_9_KraidStatueGray };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Kraid, 21, 2)       : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_TourianStatueClearState), .tourian_statue_state = kStatueState_ReleasingBossLock | kStatueState_KraidProcessing };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Kraid, 22, 2)       : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_Delete) };

    case ANIMTILE_INSTR_FUNC(TourianStatue_Kraid, 23, 1)       : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_TourianStatueClearState), .tourian_statue_state = kStatueState_ReleasingBossLock | kStatueState_KraidProcessing };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Kraid, 24, 1)       : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_Write8PaletteColors), .palette_offset =   0xe0 };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Kraid, 25, 1)       : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_Delete) };

    case ANIMTILE_INSTR_FUNC(TourianStatue_Draygon, 0, 0)      : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_TourianStatueSetState), .tourian_statue_state = kStatueState_DraygonProcessing };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Draygon, 1, 0)      : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_GotoIfEventHappened), .game_event = kEvent_8_DraygonStatueGray, .instr_list_ptr2 = ANIMTILE_INSTR_FUNC(TourianStatue_Draygon, 23, 1) };
    case ANIMTILE_INSTR_DRAW(TourianStatue_Draygon, 2, 1)      : return (AnimtilesEntry){ .timer = 8, .tile_src = 0x95a4 };
    case ANIMTILE_INSTR_DRAW(TourianStatue_Draygon, 3, 1)      : return (AnimtilesEntry){ .timer = 12, .tile_src = 0x9624 };
    case ANIMTILE_INSTR_DRAW(TourianStatue_Draygon, 4, 1)      : return (AnimtilesEntry){ .timer = 12, .tile_src = 0x96a4 };
    case ANIMTILE_INSTR_DRAW(TourianStatue_Draygon, 5, 1)      : return (AnimtilesEntry){ .timer = 12, .tile_src = 0x9624 };
    case ANIMTILE_INSTR_DRAW(TourianStatue_Draygon, 6, 1)      : return (AnimtilesEntry){ .timer = 16, .tile_src = 0x95a4 };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Draygon, 7, 1)      : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_GotoIfBossBitSetInArea), .boss_bit = kBossBit_AreaBoss, .area = kArea_4_Maridia, .instr_list_ptr2 = ANIMTILE_INSTR_FUNC(TourianStatue_Draygon, 10, 2) };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Draygon, 8, 2)      : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_TourianStatueClearState), .tourian_statue_state = kStatueState_DraygonProcessing };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Draygon, 9, 2)      : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_Goto), .instr_list_ptr1 = ANIMTILE_INSTR_DRAW(TourianStatue_Draygon, 3, 1) };

    case ANIMTILE_INSTR_FUNC(TourianStatue_Draygon, 10, 2)     : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_GotoIfTourianStatueBusy), .instr_list_ptr1 = ANIMTILE_INSTR_DRAW(TourianStatue_Draygon, 3, 1) };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Draygon, 11, 2)     : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_TourianStatueSetState), .tourian_statue_state = kStatueState_ReleasingBossLock };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Draygon, 12, 2)     : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_Clear3PaletteColors), .palette_offset =   0xd2 };
    case ANIMTILE_INSTR_DRAW(TourianStatue_Draygon, 13, 2)     : return (AnimtilesEntry){ .timer = 16, .tile_src = 0x9624 };
    case ANIMTILE_INSTR_DRAW(TourianStatue_Draygon, 14, 2)     : return (AnimtilesEntry){ .timer = 16, .tile_src = 0x96a4 };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Draygon, 15, 2)     : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_SpawnTourianStatueEyeGlow), .eproj_param = 4 };
    case ANIMTILE_INSTR_DRAW(TourianStatue_Draygon, 16, 2)     : return (AnimtilesEntry){ .timer = 192, .tile_src = 0x98e4 };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Draygon, 17, 2)     : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_SpawnTourianStatueSoul), .eproj_param = 4 };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Draygon, 18, 2)     : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_SpawnPalfxObj), .palfx_id = 0xf749 };
    case ANIMTILE_INSTR_DRAW(TourianStatue_Draygon, 19, 2)     : return (AnimtilesEntry){ .timer = 128, .tile_src = 0x98e4 };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Draygon, 20, 2)     : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_SetEventHappened), .game_event = kEvent_8_DraygonStatueGray };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Draygon, 21, 2)     : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_TourianStatueClearState), .tourian_statue_state = kStatueState_ReleasingBossLock | kStatueState_DraygonProcessing };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Draygon, 22, 2)     : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_Delete) };

    case ANIMTILE_INSTR_FUNC(TourianStatue_Draygon, 23, 1)     : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_TourianStatueClearState), .tourian_statue_state = kStatueState_ReleasingBossLock | kStatueState_DraygonProcessing };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Draygon, 24, 1)     : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_Write8PaletteColors), .palette_offset =   0xc0 };
    case ANIMTILE_INSTR_FUNC(TourianStatue_Draygon, 25, 1)     : return (AnimtilesEntry){ .func_ptr = FUNC16(AnimtilesInstr_Delete) };

    default: Unreachable(); return (AnimtilesEntry){0};
  }
}
