#pragma once

#include "ida_types.h"

// Bank 80
bool CheckEventHappened(uint16 a);
uint16 NextRandom(void);
uint16 PrepareBitAccess(uint16 a);
uint8 CalculateLayer2Xpos(void);
uint8 CalculateLayer2Ypos(void);
bool CheckBossBitForCurArea(uint16 a);
uint8 DoorTransition_Down(void);
uint8 DoorTransition_Left(void);
uint8 DoorTransition_Right(void);
uint8 DoorTransition_Up(void);
bool HasQueuedMusic(void);
uint8 ProcessTimer(void);
uint8 ProcessTimer_CeresStart(void);
uint8 ProcessTimer_Decrement(void);
uint8 ProcessTimer_Inactive(void);
uint8 ProcessTimer_InitialDelay(void);
uint8 ProcessTimer_MotherBrainStart(void);
uint8 ProcessTimer_MovedIntoPlace(void);
uint8 ProcessTimer_MovementDelayed(void);
uint8 ProcessTimer_MovingIntoPlace(void);
void APU_UploadBank(uint32 addr);
void AddGrappleToHudTilemap(void);
void AddMissilesToHudTilemap(void);
void AddPowerBombsToHudTilemap(void);
void AddSuperMissilesToHudTilemap(void);
void AddToTilemapInner(uint16 k, const uint16 *j);
void AddXrayToHudTilemap(void);
void CalculateBgScrollAndLayerPositionBlocks(void);
void CalculateBgScrolls(void);
void CalculateLayer2PosAndScrollsWhenScrolling(void);
void ClearBG2Tilemap(void);
void ClearBossBitForCurArea_UNUSED(uint16 a);
void ClearEventHappened(uint16 a);
void ClearFXTilemap(void);
void ClearOamExt(void);
void ClearTimerRam(void);
void UNUSED_ConfigureMode7RotationMatrix(void);
void CopySuperMetroidString(void);
void DebugScrollPosSaveLoad(void);
void DecompressToMem(uint32 src, uint8 *decompress_dst);
void DecompressToVRAM(uint32 src, uint16 dst_addr);
void DisableIrqInterrupts(void);
void DisableNMI(void);
void DisplayViewablePartOfRoom(void);
void DoorTransitionScrollingSetup(void);
void DoorTransitionScrollingSetup_Down(void);
void DoorTransitionScrollingSetup_Left(void);
void DoorTransitionScrollingSetup_Right(void);
void DoorTransitionScrollingSetup_Up(void);
void DrawThreeHudDigits(const uint16* addr, uint16 a, uint16 k);
void DrawTimer(void);
void DrawTimerSpritemap(uint16 a, uint16 j);
void DrawTwoHudDigits(const uint16* addr, uint16 a, uint16 k);
void DrawTwoTimerDigits(uint16 a, uint16 k);
void EnableIrqInterrupts(void);
void EnableIrqInterruptsNow(void);
void EnableNMI(void);
void FixDoorsMovingUp(void);
void Irq_FollowDoorTransition(void);
void HandleAutoscrolling_X(void);
void HandleAutoscrolling_Y(void);
void HandleFadeIn(void);
void ClearUnusedOam(void);
void HandleFadeOut(void);
void HandleHudTilemap(void);
void HandleMusicQueue(void);
void HandleScrollingWhenTriggeringScrollDown(void);
void HandleScrollingWhenTriggeringScrollLeft(void);
void HandleScrollingWhenTriggeringScrollRight(void);
void HandleScrollingWhenTriggeringScrollUp(void);
void InitializeCpuIoRegs(void);
void InitializeHud(void);
void InitializePpuIoRegs(void);
void InvalidInterrupt_Crash(void);
void IrqHandler_0_Nothing(void);
void IrqHandler_10_StartOfDoor_EndHud(void);
void IrqHandler_12_Draygon_BeginHud(void);
void IrqHandler_14_Draygon_EndHud(void);
void IrqHandler_16_VerticalDoor_BeginHud(void);
void IrqHandler_18_VerticalDoor_EndHud(void);
void IrqHandler_20_VerticalDoor_EndDraw(void);
void IrqHandler_22_HorizDoor_BeginHud(void);
void IrqHandler_24_HorizDoor_EndHud(void);
void IrqHandler_26_HorizDoor_EndDraw(void);
void IrqHandler_2_DisableIRQ(void);
void IrqHandler_4_Main_BeginHudDraw(void);
void IrqHandler_6_Main_EndHudDraw(void);
void IrqHandler_8_StartOfDoor_BeginHud(void);
void CopyToVramNow(uint16 vram_dst, uint32 src, uint16 size);
void LoadFromLoadStation(void);
void LoadMirrorOfExploredMapTiles(void);
uint32 Multiply16x16(uint16 a, uint16 j);
void NMI_ProcessMode7Queue(void);
void NMI_ProcessMode7QueueInner(const uint8 *p);
void NMI_ProcessVramReadQueue(void);
void NMI_ProcessVramWriteQueue(void);
void NmiProcessAnimtilesVramTransfers(void);
void NmiTransferSamusToVram(void);
void NmiUpdateIoRegisters(void);
void NmiUpdatePalettesAndOam(void);
void Nmi_ProcessHorizScrollingDma(void);
void Nmi_ProcessVertScrollingDma(void);
CoroutineRet Play20FramesOfMusic_Async(void);
void QueueClearingOfFxTilemap(void);
void QueueMode7Transfers(uint8 db, uint16 k);
void QueueMusic_Delayed8(uint16 a);
void QueueMusic_DelayedY(uint16 a, uint16 j);
void QueueSfx1_Internal(uint16 a);
void QueueSfx1_Max1(uint16 a);
void QueueSfx1_Max15(uint16 a);
void QueueSfx1_Max3(uint16 a);
void QueueSfx1_Max6(uint16 a);
void QueueSfx1_Max9(uint16 a);
void QueueSfx2_Internal(uint16 a);
void QueueSfx2_Max1(uint16 a);
void QueueSfx2_Max15(uint16 a);
void QueueSfx2_Max3(uint16 a);
void QueueSfx2_Max6(uint16 a);
void QueueSfx2_Max9(uint16 a);
void QueueSfx3_Internal(uint16 a);
void QueueSfx3_Max1(uint16 a);
void QueueSfx3_Max15(uint16 a);
void QueueSfx3_Max3(uint16 a);
void QueueSfx3_Max6(uint16 a);
void QueueSfx3_Max9(uint16 a);
void ReadJoypadInputs(void);
void ReleaseButtonsFilter(uint16 a);
void ResumeGameplay(void);
void SaveExploredMapTilesToSaved(void);
void ScreenOff(void);
void ScreenOn(void);
void SetBossBitForCurArea(uint16 a);
void SetDebugElevatorsAsUsed(void);
void SetEventHappened(uint16 a);
void SetTimerMinutes(uint16 a);
void SetupDmaTransfer(const void* p);
CoroutineRet StartGameplay_Async(void);
void ToggleHudItemHighlight(uint16 a, uint16 k);
void UpdateBackgroundDataRow(void);
void UpdateBgGraphicsWhenScrolling(void);
void UpdateBgScrollOffsets(void);
void UpdateLevelDataRow(void);
void UpdateLevelOrBackgroundDataColumn(uint16 k);
void UpdateLevelOrBackgroundDataRow(uint16 k);
void UpdatePreviousLayerBlocks(void);
void UpdateScrollVarsUpdateMap(void);
void UploadBackgroundDataColumn(void);
void UploadLevelDataColumn(void);
void Vector_IRQ(void);
void Vector_NMI(void);
CoroutineRet Vector_RESET_Async(void);
void VerifySRAM(void);
CoroutineRet WaitForNMI_Async(void);
CoroutineRet WaitForNMI_NoUpdate_Async(void);
void WriteLotsOf0x1c2f(void);
void memset7E(uint16 *dst, uint16 val, uint16 size);
void Write0x800BytesToRam3000(uint16 a);
void Write0x800BytesToRam4000(uint16 a);
void Write0x800BytesToRam6000(uint16 a);

// Bank 81
uint16 Debug_CheckIfFileSelectMapAreaCanBeSelected(uint16 a);
uint16 DecAndWraparoundTo5(uint16 a);
uint16 HandleRoomSelectMapExpandingSquareTrans(void);
uint16 WraparoundFrom6to0(uint16 a);
uint8 LoadFromSram(uint16 a);
uint8 LoadFromSram_(uint16 a);
void AddExpandingSqTransLeftIndirHDMA(uint16 a, uint16 k, uint16 j);
uint16 AddExpandingSqTransRightIndirHDMA(uint16 a, uint16 k, uint16 j);
void ClearMenuTilemap(void);
void ConfigureWindow1ForExpandingSquare(void);
void DebugGameOverMenu(void);
void DrawAreaSelectMapLabels(void);
void DrawBeamGrappleSpritemap(uint16 a, uint16 x_r20, uint16 y_r18);
void DrawEprojSpritemapWithBaseTile(uint8 db, uint16 j, uint16 x_r20, uint16 y_r18, uint16 chr_r26, uint16 chr_r28);
void DrawEprojSpritemapWithBaseTileOffscreen(uint8 db, uint16 j, uint16 x_r20, uint16 y_r18, uint16 chr_r26, uint16 chr_r28);
void DrawFileCopyClearConfirmation(void);
void DrawFileCopyConfirmationSaveFileInfo(void);
void DrawFileCopySaveFileInfo(void);
void DrawFileCopySaveSlotAInfo(void);
void DrawFileCopySaveSlotBInfo(void);
void DrawFileCopySaveSlotCInfo(void);
void DrawFileCopySelectDestinationSaveFileInfo(void);
void DrawFileSelectSamusHelmets(void);
void DrawFileSelectSlotSamusHelmet(uint16 k);
void DrawFileSelectionHealth(uint16 a, uint16 k);
void DrawFileSelectionTime(uint16 a, uint16 k);
void DrawMenuSpritemap(uint16 a, uint16 k, uint16 j, uint16 chr_r3);
void DrawProjectileSpritemap(uint16 k, uint16 x_r20, uint16 y_r18);
void DrawSamusSpritemap(uint16 a, uint16 k, uint16 j);
void DrawSpritemap(uint8 db, uint16 j, uint16 x_r20, uint16 y_r18, uint16 chr_r22);
void DrawSpritemapOffScreen(uint16 j, uint16 x_r20, uint16 y_r18, uint16 chr_r22);
void DrawSpritemapWithBaseTile(uint8 db, uint16 j, uint16 r20_x, uint16 r18_y, uint16 r3, uint16 r0);
void DrawSpritemapWithBaseTile2(uint8 db, uint16 j, uint16 r20_x, uint16 r18_y, uint16 r3, uint16 r0);
void DrawSpritemapWithBaseTileOffscreen(uint8 db, uint16 j, uint16 r20_x, uint16 r18_y, uint16 r3, uint16 r0);
void FileSelectClearRestOfMenuTilemapRow(uint16 k);
void FileSelectMap(void);
void FileSelectMap_0_OptionsToAreaSelectSetupFadeOut(void);
void FileSelectMap_1_OptionsToAreaSelectFadeOut(void);
void FileSelectMap_10_RoomSelectMap(void);
void FileSelectMap_11_12_RoomSelectToGameWaitForFadeOut(void);
void FileSelectMap_13_RoomSelectToLoadGameFadeOut(void);
void FileSelectMap_14_RoomSelectToLoadGameWait(void);
void FileSelectMap_15_RoomSelectToAreaSelectClearTileMap(void);
void FileSelectMap_16_RoomSelectToAreaSelectLoadPalettes(void);
void FileSelectMap_18_RoomSelectToAreaSelectLoadBackgroundTilemap(void);
void FileSelectMap_20_SetupContractingSquare(void);
void FileSelectMap_21_RoomSelectToAreaSelectMoveExpandingSquare(void);
void FileSelectMap_22_SelectSlotFromFileClear(void);
void FileSelectMap_2_17_LoadAreaSelectForegroundTilemap(void);
void FileSelectMap_3_LoadAreaSelectBackgroundTilemap(void);
void FileSelectMap_4_19_SetupExpandingSquareTransition(void);
void FileSelectMap_5_ExpandingSquare(void);
void FileSelectMap_6_AreaSelectMap(void);
void FileSelectMap_7_PrepExpandSquareTransToRoomMap(void);
void FileSelectMap_8_ExpandSquareTransToRoomSelectMap(void);
void FileSelectMap_9_InitRoomSelectMap(void);
void FileSelectMenu(void);
void FileSelectMenu_0_FadeOutConfigGfx(void);
void FileSelectMenu_10_FileCopySelectDest(void);
void FileSelectMenu_11_InitializeConfirm(void);
void FileSelectMenu_12_FileCopyConfirm(void);
void FileSelectMenu_13_FileCopyDoIt(void);
void FileSelectMenu_14_CopyCompleted(void);
void FileSelectMenu_15_27_FadeOutToMain(void);
void FileSelectMenu_16_28_ReloadMain(void);
void FileSelectMenu_17_29_FadeInToMain(void);
void FileSelectMenu_18_FileCopyMenuToMain(void);
void FileSelectMenu_1_LoadFileSelectMenuBG2(void);
void FileSelectMenu_20_FileClearInit(void);
void FileSelectMenu_22_FileClearSelectSlot(void);
void FileSelectMenu_23_FileClearInitConfirm(void);
void FileSelectMenu_24_FileClearConfirm(void);
void FileSelectMenu_25_FileClearDoClear(void);
void FileSelectMenu_26_ClearCompleted(void);
void FileSelectMenu_2_InitMain(void);
void FileSelectMenu_30_FileClearMenuToMain(void);
void FileSelectMenu_31_TurnSamusHelmet(void);
void FileSelectMenu_32_FadeOutToOptions(void);
void FileSelectMenu_33_FadeOutToTitle(void);
void FileSelectMenu_3_FadeInToMain(void);
void FileSelectMenu_4_Main(void);
void FileSelectMenu_5_19_FadeOutFromMain(void);
void FileSelectMenu_6_FileCopyInit(void);
void FileSelectMenu_7_21_FadeInFromMain(void);
void FileSelectMenu_8_FileCopySelectSrc(void);
void FileSelectMenu_9_InitializeSelectDest(void);
void InitFileSelectMenuFileCopy(void);
void GameOverMenu(void);
void GameOverMenu_0_FadeOutConfigGfx(void);
void GameOverMenu_1_Init(void);
void DebugGameOverMenu_2_4_FadeIn(void);
void GameOverMenu_2_PlayMusic(void);
void GameOverMenu_3_FadeIn(void);
void DebugGameOverMenu_3_Main(void);
void GameOverMenu_4_Main(void);
void DebugGameOverMenu_5_Continue(void);
void GameOverMenu_5_FadeOutToGameMap(void);
void GameOverMenu_6_LoadGameMapView(void);
void GameOverMenu_7_FadeOutToSoftReset(void);
void HandleFileCopyArrowPalette(void);
void HandleFileSelectMapScrollArrows(void);
void InitFileSelectMenuFileClear(void);
void LoadActiveAreaMapForegroundColors(uint16 k);
void LoadAreaMapForegroundColors(uint16 j);
void LoadAreaSelectBackgroundTilemap(uint16 j);
void LoadFileSelectPalettes(void);
void LoadInactiveAreaMapForegroundColors(uint16 k);
void LoadInitialMenuTiles(void);
void LoadMenuExitTilemap(void);
void LoadMenuPalettes(void);
void LoadMenuTilemap(uint16 k, uint16 j);
void MapVramForMenu(void);
void NewSaveFile(void);
void PackMapToSave(void);
void QueueTransferOfMenuTilemapToVramBG1(void);
void RestorePalettesAndIoAfterDebugGameover(void);
void SaveToSram(uint16 a);
void SelectFileSelectMapArea(void);
void SetFileClearMenuMissilePos(void);
void SetFileCopyMenuSelectionMissilePosition(void);
void SetInitialFileCopyClearMenuSelection(void);
void SetupInitialExpandingSquareHDMA(void);
void SetupRoomSelectMapExpandingSquareTransHDMA(void);
void Debug_SwitchActiveFileSelectMapArea(uint16 R28);
void UnpackMapFromSave(void);
void DrawGrappleOrProjectileSpritemap(const uint8 *pp, uint16 x_r20, uint16 y_r18);
void UNUSED_sub_819591(void);
void UNUSED_sub_81A3D1(uint16 k);
void UNUSED_sub_81AEC8(void);
void SoftReset(void);

// Bank 82
uint16 CalculateNthTransitionColorComponentFromXtoY(uint16 a, uint16 k, uint16 j);
uint16 CalculateNthTransitionColorFromXtoY(uint16 a, uint16 k, uint16 j);
uint16 CheckIfMapPositionIsExplored(uint16 k, uint16 j);
uint16 EquipmentScreenCategory_Boots_MoveUpInBoots(uint16 k);
uint16 EquipmentScreenMoveLowerOnSuitsMisc(uint16 k);
uint16 EquipmentScreenMoveToBottomOfBeams(uint16 k);
uint16 EquipmentScreenMoveToReserveTanks(void);
uint16 LoadLibraryBackgroundFunc_0_DONE(uint16 j);
uint16 LoadLibraryBackgroundFunc_2_TransferToVram(uint16 j);
uint16 LoadLibraryBackgroundFunc_4_Decompress(uint16 j);
uint16 LoadLibraryBackgroundFunc_6_ClearFxTilemap(uint16 j);
uint16 LoadLibraryBackgroundFunc_8_TransferToVramAndSetBg3(uint16 j);
uint16 LoadLibraryBackgroundFunc_A_ClearBG2Tilemap(uint16 j);
uint16 LoadLibraryBackgroundFunc_C_ClearKraidLayer2(uint16 j);
uint16 LoadLibraryBackgroundFunc_E_DoorDependentTransferToVram(uint16 j);
uint16 MapScrolling_GetSpeedIndex(void);
uint16 OptionsInstr_Sleep(uint16 k, uint16 j);
uint16 OptionsInstr_ClearPreInstr(uint16 k, uint16 j);
uint16 OptionsInstr_DecrementTimerAndGoto(uint16 k, uint16 j);
uint16 OptionsInstr_SetTimer(uint16 k, uint16 j);
uint16 OptionsInstr_Destroy(uint16 k, uint16 j);
uint16 OptionsInstr_Goto(uint16 k, uint16 j);
uint16 OptionsInstr_SetPreInstr(uint16 k, uint16 j);
uint16 UpdateBackgroundCommand_0_Finish(uint16 j);
uint16 UpdateBackgroundCommand_2_TransferToVram(uint16 j);
uint16 UpdateBackgroundCommand_4_Decompression(uint16 j);
uint16 UpdateBackgroundCommand_6_ClearFxTilemap(uint16 j);
uint16 UpdateBackgroundCommand_8_TransferToVramAndSetBg3(uint16 j);
uint16 UpdateBackgroundCommand_A_ClearBg2Tilemap(uint16 j);
uint16 UpdateBackgroundCommand_C_ClearKraidBg2Tilemap(uint16 j);
uint16 UpdateBackgroundCommand_E_DoorDependentTransferToVRAM(uint16 j);
uint16 UpdateSamusPositionIndicatorAnimation(void);
uint8 AdvanceGradualColorChangeOfPalette(uint16 k, uint16 j);
uint8 AdvancePaletteFadeForAllPalettes(void);
uint8 AdvancePaletteFadeForAllPalettes_0xc(void);
uint8 AdvancePaletteFade_BgPalette6(void);
uint8 CheckIfColoredDoorCapSpawned(void);
uint8 CreateOptionsMenuObject_(uint16 a, uint16 j);
CoroutineRet DoorTransitionFunction_HandleElevator(void);
CoroutineRet DoorTransitionFunction_Wait48frames(void);
uint8 RefillHealthFromReserveTanks(void);
uint8 AdvancePaletteFadeForAllPalettesInA(uint16 a);
uint8 AdvancePaletteFadeForAllPalettesInA_0xc(uint16 a);
void BabyMetroidPlayCry1Sfx(void);
void BabyMetroidPlayCry2Sfx(void);
void BabyMetroidPlayCry3Sfx(void);
void BackupBG2TilemapForPauseMenu(void);
void BackupGameplayPalettesAndLoadForPause(void);
void BackupSomeGfxStateForPause(void);
void CalculateBgScrolls_Unpause(void);
void CancelSoundEffects(void);
void CheckForNextDemo(void);
void ClearBg2Tilemap(void);
void ClearFxTilemap(void);
void ClearKraidBg2Tilemap(void);
void ClearPauseMenuData(void);
void ClearSamusBeamTiles(void);
void ContinueInitGameplayResume(void);
void ContinueInitPauseMenu(void);
void CreatePlmsExecuteDoorAsmRoomSetup(void);
void DeleteAllOptionsMenuObjects_(void);
void DemoRoom_ChargeBeamRoomScroll21(void);
void DemoRoom_SetBG2TilemapBase(void);
void DemoRoom_SetBrinstarBossBits(void);
void DemoRoom_SetKraidFunctionTimer(void);
void DetermineMapScrollLimits(void);
void DisplayMapElevatorDestinations(void);
CoroutineRet DoorTransitionFunction_FadeOutScreen(void);
CoroutineRet DoorTransitionFunction_FixDoorsMovingUp(void);
CoroutineRet DoorTransitionFunction_LoadDoorHeaderEtc(void);
CoroutineRet DoorTransitionFunction_LoadMoreThings_Async(void);
CoroutineRet DoorTransitionFunction_PlaceSamusLoadTiles(void);
CoroutineRet DoorTransitionFunction_ScrollScreenToAlignment(void);
CoroutineRet DoorTransitionFunction_SetupNewRoom(void);
CoroutineRet DoorTransitionFunction_SetupScrolling(void);
CoroutineRet DoorTransitionFunction_WaitForSoundsToFinish(void);
CoroutineRet DoorTransitionFunction_FadeInScreenAndFinish(void);
CoroutineRet DoorTransitionFunction_HandleTransition(void);
CoroutineRet DoorTransitionFunction_WaitForMusicToClear(void);
void DrawBabyMetroid(uint16 k);
void DrawBorderAroundDataClearMode(void);
void DrawBorderAroundDataCopyMode(void);
void DrawBorderAroundSamusData(void);
void DrawBossMapIcons(uint16 a, uint16 k);
void DrawDebugElevatorMapIcons(uint16 a, uint16 k, uint16 r3);
void DrawDebugSaveMapIcons(uint16 a, uint16 k, uint16 r3);
void DrawFileCopyArrow(void);
void DrawFileSelectMapIcons(void);
void DrawLrHighlight(void);
void DrawMapIcons(void);
void DrawMapIconsOfType(uint16 a, uint16 r34, uint16 r36, uint16 r3);
void DrawMapScrollArrowAndCheckToScroll(MapScrollArrowData k);
void DrawMenuSelectionMissile(void);
void DrawOptionsMenuSpritemaps(void);
void DrawPauseMenuDuringFadeIn(void);
void DrawPauseMenuDuringFadeout(void);
void DrawPauseScreenSpriteAnim(uint16 a, uint16 k, uint16 j);
void DrawRoomSelectMap(void);
void DrawRoomSelectMapAreaLabel(uint16 *dst);
void DrawSaveStationMapIcon(uint16 a, uint16 k, uint16 r3);
void DrawSimpleMapIcons(uint16 a, uint16 k, uint16 r3);
void EnsureSamusDrawnEachFrame(void);
void EquipmentScreenCategory_Boots(void);
void EquipmentScreenCategory_Boots_MoveResponse(void);
void EquipmentScreenCategory_ButtonResponse(uint16 r24);
void EquipmentScreenCategory_Suit(void);
void EquipmentScreenCategory_Suit_MoveResponse(void);
void EquipmentScreenCategory_Tanks(void);
void EquipmentScreenCategory_Tanks_0(void);
void EquipmentScreenCategory_Tanks_1(void);
void EquipmentScreenCategory_Weapons(void);
void EquipmentScreenCategory_Weapons_MoveButtons(void);
void EquipmentScreenCategory_Weapons_PlazmaSpazerCheck(uint16 R36);
void EquipmentScreenDisplayReserveTankAmount(void);
void EquipmentScreenDisplayReserveTankAmount_(void);
uint16 EquipmentScreenDisplayReserves_PaletteSetup(void);
void EquipmentScreenDrawItemSelector(void);
void EquipmentScreenEnergyArrowGlow_Off(void);
void EquipmentScreenEnergyArrowGlow_On(void);
void EquipmentScreenGlowingArrow(void);
void EquipmentScreenGlowingArrowAnimated(void);
void EquipmentScreenGlowingArrowSolidOff(void);
void EquipmentScreenGlowingArrowSolidOn(void);
void EquipmentScreenHandleDpad(void);
void EquipmentScreenHudReserveAutoTilemap_Off(void);
void EquipmentScreenHudReserveAutoTilemap_On_BUGGY(void);
void EquipmentScreenMain(void);
void EquipmentScreenMoveToBeams(uint16 k, uint16 r18);
void EquipmentScreenMoveToHighJumpOrLowerInBoots(uint16 k, uint16 r18);
void EquipmentScreenMoveToScrewOrHigherOnSuits(uint16 k, uint16 r18);
void EquipmentScreenSetupReserveMode(void);
void EquipmentScreenTransferBG1Tilemap(void);
void FinishProcessingGameOverBabyMetroidAsm(void);
void GameOptionsMenuFunc_0(void);
void GameOptionsMenuItemFunc_0_StartGame(void);
void GameOptionsMenuItemFunc_2_ToggleJapanese(void);
void GameOptionsMenuItemFunc_4_StartGameDissolveTransition(void);
void GameOptionsMenuSpecialSettings_ToggleSetting(void);
void GameOptionsMenuSpecialSettings_End(void);
void GameOptionsMenu_1_LoadingOptionsScreen(void);
void GameOptionsMenu_2_FadeInOptionsScreen(void);
void GameOptionsMenu_3_OptionsScreen(void);
void GameOptionsMenu_4_StartGame(void);
void GameOptionsMenu_5_DissolveOutScreen(void);
void GameOptionsMenu_6_DissolveInScreen(void);
void GameOptionsMenu_7_ControllerSettings(void);
void GameOptionsMenu_8_SpecialSettings(void);
void GameOptionsMenu_9_ScrollControllerSettingsDown(void);
void GameOptionsMenu_A_ScrollControllerSettingsUp(void);
void GameOptionsMenu_B_TransitionBackToFileSelect(void);
void GameOptionsMenu_C_FadeOutOptionsScreenToStart(void);
CoroutineRet GameState_0_Reset_Async(void);
CoroutineRet GameState_10_LoadingNextRoom_Async(void);
CoroutineRet GameState_11_LoadingNextRoom_Async(void);
CoroutineRet GameState_12_Pausing_Darkening_Async(void);
CoroutineRet GameState_13_Pausing_Async(void);
CoroutineRet GameState_14_Paused_Async(void);
CoroutineRet GameState_15_Paused_Async(void);
CoroutineRet GameState_16_Unpausing_Async(void);
CoroutineRet GameState_17_Unpausing_Async(void);
CoroutineRet GameState_18_Unpausing(void);
CoroutineRet GameState_19_SamusNoHealth(void);
CoroutineRet GameState_1_OpeningCinematic(void);
CoroutineRet GameState_20_SamusNoHealth_BlackOut(void);
CoroutineRet GameState_21_SamusNoHealth(void);
CoroutineRet GameState_22_SamusNoHealth_Dying(void);
CoroutineRet GameState_23_SamusNoHealth_Flashing(void);
CoroutineRet GameState_24_SamusNoHealth_Explosion(void);
CoroutineRet GameState_25_SamusNoHealth_BlackOut(void);
CoroutineRet GameState_26_GameOverMenu(void);
CoroutineRet GameState_27_ReserveTanksAuto(void);
CoroutineRet GameState_28_Unused(void);
CoroutineRet GameState_29_DebugGameOverMenu(void);
CoroutineRet GameState_2_GameOptionsMenu(void);
CoroutineRet GameState_3_Null(void);
CoroutineRet GameState_32_MadeItToCeresElevator(void);
CoroutineRet GameState_33_BlackoutFromCeres(void);
CoroutineRet GameState_35_TimeUp(void);
CoroutineRet GameState_36_WhitingOutFromTimeUp(void);
CoroutineRet GameState_37_CeresGoesBoomWithSamus(void);
CoroutineRet GameState_38_SamusEscapesFromZebes(void);
CoroutineRet GameState_39_EndingAndCredits(void);
CoroutineRet GameState_41_TransitionToDemo(void);
CoroutineRet GameState_42_PlayingDemo_Async(void);
CoroutineRet GameState_43_TransitionFromDemo(void);
CoroutineRet GameState_44_TransitionFromDemo(void);
CoroutineRet GameState_4_FileSelectMenus(void);
CoroutineRet GameState_5_FileSelectMap(void);
CoroutineRet GameState_7_MainGameplayFadeIn(void);
CoroutineRet GameState_8_MainGameplay(void);
CoroutineRet GameState_9_HitDoorBlock(void);
void HandleGameOverBabyMetroid(void);
void HandleMapScrollArrows(void);
void HandlePauseMenuLRPressHighlight(void);
void HandlePauseScreenLR(void);
void HandlePauseScreenLrInput(void);
void HandlePauseScreenPaletteAnimation(void);
void HandlePauseScreenStart(void);
void HandleSamusOutOfHealthAndGameTile(void);
void HandleSoundEffects(void);
void HighlightPauseScreenButton(void);
CoroutineRet InitAndLoadGameData_Async(void);
void InitCpuForGameplay(void);
void InitIoForGameplay(void);
void InitPpuForGameplay(void);
void LoaadDesinationRoomCreBitset(void);
void LoadCRETilesTilesetTilesAndPalette(void);
void LoadColorsForSpritesBeamsAndEnemies(void);
void LoadControllerOptionsFromControllerBindings(void);
void LoadDemoRoomData(void);
void LoadDestinationRoomThings(void);
void LoadDoorHeader(void);
void LoadEnemyGfxToVram(void);
void LoadEquipmentScreenEquipmentTilemaps(void);
void LoadEqupmentScreenReserveHealthTilemap(void);
void LoadInitialPalette(void);
void LoadLevelDataAndOtherThings(void);
void LoadLevelScrollAndCre(void);
void LoadLibraryBackground(void);
void LoadMapExploredIfElevator(void);
void LoadNewMusicTrackIfChanged(void);
void LoadPauseMenuMapTilemap(void);
void LoadPauseMenuMapTilemapAndAreaLabel(void);
void LoadPauseMenuTilesAndClearBG2(void);
void LoadPauseScreenBaseTilemaps(void);
void LoadRoomHeader(void);
void LoadRoomMusic(void);
void LoadStateHeader(void);
void LoadStdBG3andSpriteTilesClearTilemaps(void);
void MainPauseRoutine(void);
void MapScreenDrawSamusPositionIndicator(void);
void MapScrolling(void);
void MapScrolling_0_None(void);
void MapScrolling_1_Left(void);
void MapScrolling_2_Right(void);
void MapScrolling_3_Up(void);
void MapScrolling_4_Down(void);
void MapScrolling_Common(void);
void NullFunc(void);
void OptionsMenuControllerFunc_SetBinding(void);
void OptionsMenuControllerFunc_End(void);
void OptionsMenuControllerFunc_ResetToDefault(void);
void OptionsMenuFunc1_HandleObject(void);
void OptionsMenuFunc2_ProcessObject(uint16 k);
void OptionsMenuFunc4_SetLanguageHighlight(void);
void OptionsMenuFunc5_SetMenuPalettes(uint16 a, uint16 k, uint16 j);
void OptionsMenuFunc6_DrawControllerBindings(void);
void OptionsMenuFunc7_SetSpecialSettingsHighlight(void);
uint8 OptionsMenuFunc8_DrawGameOptionsMenuControllerBindings(void);
void OptionsMenu_AddToVramQueue(void);
void OptionsPreInstr_MenuSelectMissile(uint16 k);
void OptionsPreInstr_OptionsModeBorder(uint16 k);
void OptionsPreInstr_ControllerSettingModeBorder(uint16 k);
void OptionsPreInstr_SpecialSettingModeBorder(uint16 k);
void OptionsPreInstr_FileSelectHelmet(uint16 k);
void OptionsPreInstr_nullsub_57(uint16 k);
void PauseMenu_0_MapScreen(void);
void PauseMenu_1_EquipmentScreen(void);
void PauseMenu_2_MapToEquipment_FadeOut(void);
void PauseMenu_3_MapToEquipment_Load(void);
void PauseMenu_4_MapToEquipment_FadeIn(void);
void PauseMenu_5_EquipmentToMap_FadeOut(void);
void PauseMenu_6_EquipmentToMap_Load(void);
void PauseMenu_7_EquipmentToMap_FadeIn(void);
void PlayRoomMusicTrackAfterAFrames(uint16 a);
void PointlessFunctionStupidToo(void);
void QueueSamusMovementSfx(void);
void ResetPauseMenuAnimations(void);
void ResetSoundQueues(void);
void RestoreBG2TilemapFromPauseScreen(void);
void RestoreSomeGfxStateForPause(void);
void SaveMapExploredifElevator(void);
void SetPauseScreenButtonLabelPalettes(void);
void SetPauseScreenButtonLabelPalettes_0(void);
void SetPauseScreenButtonLabelPalettes_1(void);
void SetPauseScreenButtonLabelPalettes_2(void);
void SetupMapScrollingForFileSelectMap(void);
void SetupMapScrollingForPauseMenu(uint16 a);
void SetupPpuForGameplayResume(void);
void SetupPpuForPauseMenu(void);
void SfxHandlers_0_SendToApu(uint16 j);
void SfxHandlers_1_WaitForAck(uint16 j);
void SfxHandlers_2_ClearRequest(uint16 j);
void SfxHandlers_3_WaitForAck(uint16 j);
void SfxHandlers_4_Reset(uint16 j);
void ShowSpareCpu(void);
void SpawnDoorClosingPLM(void);
CoroutineRet DoorTransitionFunction_HandleAnimTiles(void);
void UpdateBeamTilesAndPalette_Unpause(void);
void UpdateMusicTrackIndex(void);
void UpdatePauseMenuLRStartVramTilemap(void);
void WaitUntilEndOfVblankAndEnableIrq(void);
void WriteSamusWireframeTilemap(void);
void WriteSamusWireframeTilemapAndQueue(void);

void UNUSED_ChangePoseDueToEquipmentChange_None(void);
void UNUSED_ChangePoseDueToEquipmentChange_SpinJump(void);
void UNUSED_ChangePoseDueToEquipmentChange_MovementTypes7And9(void);
void UNUSED_ChangePoseDueToEquipmentChange_Morph(void);
void UNUSED_sub_82B932(void);
void ProcessGameOverBabyMetroidInstructionList(uint16 a);
void RestartGameOverBabyMetroidInstructionList(void);
void AdvancePaletteFadeForPaletteInX_0x20(void);
void OptionsInit_MenuSelectMissile(uint16 j);
void OptionsInit_OptionModeBorder(uint16 j);
void OptionsInit_ControllerSettingModeBorder(uint16 j);
void OptionsInit_SpecialSettingModeBorder(uint16 j);
void OptionsInit_SamusDataBorder(uint16 j);
void OptionsInit_CommonBorder(uint16 j);
void UNUSED_sub_82F404(uint16 k);
void OptionsInit_FileSelectHelmet(uint16 j);

// Bank 84
uint16 SetBtsToGateBlockMoveDownRow(uint16 k);
uint16 SetBtsToGateBlockMoveUpRow(uint16 k);
uint8 ActivateStationIfSamusCannonLinedUp(uint16 a, uint16 j);
uint8 SpawnPLM(uint16 a);
uint8 WakePlmIfSamusIsBelowAndRightOfTarget(uint16 k, uint16 x_r18, uint16 y_r20);
uint8 PlmSetup_B9F1_TurnCeresDoorSolid(uint16 j);
uint8 TriggerPlmOfBlockToTheRight(uint16 j);
uint8 TriggerPlmOfBlockToTheLeft(uint16 j);
uint8 TriggerPlmAtBlockIndex(uint16 j, uint16 a);
uint8 PlmSetup_EnergyTank(uint16 j);
uint8 PlmSetup_MissileTank(uint16 j);
uint8 PlmSetup_SuperMissileTank(uint16 j);
uint8 PlmSetup_PowerBombTank(uint16 j);
uint8 SetPlmGfxAndSetupAbility(uint16 j, uint16 a);
uint8 PlmSetup_AbilityTank(uint16 j);
uint8 PlmSetup_EnergyTankShotBlock(uint16 j);
uint8 PlmSetup_MissileTankShotBlock(uint16 j);
uint8 PlmSetup_SuperMissileTankShotBlock(uint16 j);
uint8 PlmSetup_PowerBombTankShotBlock(uint16 j);
uint8 SetPlmGfxAndSetupAbilityShotBlock(uint16 j, uint16 a);
uint8 PlmSetup_AbilityTankShotBlock(uint16 j);
uint8 PlmSetup_ItemCollisionDetection(uint16 j);
void CalculatePlmBlockCoords(uint16 k);
void ClearPLMs(void);
void ClearSoundsWhenGoingThroughDoor(void);
void DeletePlm(uint16 j);
void DisablePLMs(void);
void DrawPlm(uint16 k);
void EnablePLMs(void);
void LoadRoomPlmGfx(void);
void LoadXrayBlocks(void);
void PlaySpinJumpSoundIfSpinJumping(void);
CoroutineRet PlmHandler_Async(void);
void InReact_QuicksandSurface_SamusOnGround(uint16 j);
void InReact_QuicksandSurface_SamusMovingUp(uint16 j);
void InReact_QuicksandSurface_SamusMovingDown(uint16 j);
uint16 CollReact_QuicksandSurface_SamusOnGround(uint16 j);
uint16 CollReact_QuicksandSurface_SamusMovingUp(uint16 j);
uint16 CollReact_QuicksandSurface_SamusMovingDown(uint16 j);
uint16 CollReact_QuicksandSurface_SpeedBoosting(void);
void ProcessPlmDrawInstruction(uint16 k);
void Spawn5BlocksOfGateBlocksDownwards(uint16 j);
void Spawn5BlocksOfGateBlocksUpwards(uint16 j);
void SetGoldenTorizoPalette(uint16 a);
void SkipDebugDrawInstructionsForScrollPlms(uint16 j);

typedef struct SpawnHardcodedPlmArgs {
  uint8 x_pos;
  uint8 y_pos;
  VoidP plm_id_;
} SpawnHardcodedPlmArgs;

void SpawnHardcodedPlm(SpawnHardcodedPlmArgs p);
void SpawnMotherBrainGlassShatteringShard(uint16 a);
void SpawnRoomPLM(uint16 k);
void WriteLevelDataBlockTypeAndBts(uint16 k, uint16 a);

void Create3BlocksVerticalExtension(uint16 k);

// Bank 85

int DisplayMessageBox_Poll(uint16 a);
void DisplayMessageBox(uint16 a);
CoroutineRet DisplayMessageBox_Async(uint16 a);

// Bank 86
extern Rect16U eproj_spawn_rect;
extern uint16 eproj_spawn_r22;
extern Point16U eproj_spawn_pt;
extern uint16 eproj_spawn_header_pt;

uint16 Math_MultByCos(uint16 a, uint16 r18);
uint16 Math_MultBySin(uint16 a, uint16 r18);
uint16 Math_MultBySinCos(uint16 r38, uint16 a);

uint16 EprojPreInstrHelper_DBF2_Func2(uint16 k);
uint16 EprojPreInstrHelper_SpikeShootingPlantSpikes_Func2(uint16 k);
uint16 EprojPreInstr_NorfairLavaquakeRocks_Inner2(uint16 k);
uint16 CheckForEprojInDraygonRoom(uint16 k);
uint16 Eproj_PhantomFireballs_GetRadiusComponent(uint16 k, uint16 r24);
uint16 RandomDropRoutine(uint16 k);
const uint8 *sub_86B13E(uint16 k, const uint8 *epjp);
uint16 sub_86DFA0(uint16 k);
uint16 sub_86E0B0(uint16 k);
uint16 CheckEprojOffScreen(uint16 k);
uint8 CheckForBlueRingCollisionWithRoom(uint16 k);
uint8 CheckForCollisionWithShitroid_DoubleRet(uint16 k);
uint8 EprojBlockCollision_Horiz(uint16 k);
uint8 EprojBlockCollision_Vertical(uint16 k);
uint8 Eproj_MotherBrainRoomTurretBullets_CheckIfTurretOnScreen(uint16 k);
uint8 MotherBrainBomb_Bomb_CollDetect_DoubleRet(uint16 k);
uint8 MoveMotherBrainBomb(uint16 k, uint16 a);
void BlueRingContactExplosion(uint16 k);
void ClearEprojs(void);
void DisableEprojs(void);
void DrawEprojs(uint16 k, Point16U pt);
void DrawHighPriorityEprojs(void);
void DrawLowPriorityEprojs(void);
void EnableEprojs(void);

void EprojRunAll(void);
void Eproj_AngleToSamus(uint16 j, uint16 r18, uint16 r20);
void Eproj_BotwonsBodyFunction_DyingSetDelay(uint16 k);
void Eproj_BotwonsBodyFunction_DyingWaiting(uint16 k);
void Eproj_BotwonsBodyFunction_DyingFalling(uint16 k);
void Eproj_BotwoonsBodyHurtFlashHandling1(uint16 k);
void Eproj_BotwoonsBodyHurtFlashHandling2(uint16 j);
void Eproj_BotwoonsBody_Main(uint16 k);
void Eproj_DeleteIfYposOutside(uint16 k);
void BlueRingContactEarthquake(uint16 k);
void MoveEprojWithAngleAndSpeed(uint16 k);
void Eproj_LavaThrownByLavaman_MoveX1(uint16 k);
void Eproj_LavaThrownByLavaman_MoveX2(uint16 k);
void Eproj_MotherBrainRoomTurretBullets_Func2(uint16 k);
void Eproj_MotherBrainsBlueRingLasers(uint16 j);
void Eproj_MoveToBlueRingSpawnPosition(uint16 k);
void Eproj_NamiFuneFireball_After(uint16 k);
void Eproj_NorfairLavaquakeRocks_Func1(uint16 k);
void Eproj_NorfairLavaquakeRocks_Func2(uint16 k);
void Eproj_NorfairLavaquakeRocks_Func3(uint16 k);
Point16U Eproj_PhantoonFireballs_GetXYRadius(uint16 j, uint16 a);
void Eproj_Pickup_BigHealth(void);
void Eproj_Pickup_Missiles(void);
void Eproj_Pickup_PowerBombs(void);
void Eproj_Pickup_SmallHealth(void);
void Eproj_Pickup_SuperMissiles(void);
const uint8 *EprojInstr_SetVelTowardsSamus1(uint16 k, const uint8 *epjp);
const uint8 *EprojInstr_SetVelTowardsSamus2(uint16 k, const uint8 *epjp);
void Eproj_SetXvelRandom(uint16 k);
void Eproj_SetYvelRandom(uint16 k);
Point16U GetValuesForScreenShaking(void);
void MotherBrainTubeFallingFunc_Falling(uint16 k);
void MotherBrainTubeFallingFunc_GenerateExplosion(uint16 k);
void QueueSmallExplosionSfx(void);
void RespawnEnemy(uint16 a);
void SetAreaDependentEprojProperties(uint16 j);
void SetAreaDependentEprojPropertiesEx(uint16 k, uint16 j);
void SpawnEprojWithGfx(uint16 a, uint16 k, uint16 j);
void SpawnEprojWithRoomGfx(uint16 j, uint16 a);
void SpawnMotherBrainDeathBeam(uint16 k);

// Bank 87
uint16 AnimtilesInstr_Clear3PaletteColors(uint16 k, uint16 j);
uint16 AnimtilesInstr_DecrementTimerAndGoto_Unused(uint16 k, uint16 j);
uint16 AnimtilesInstr_DecrementTimerAndGotoRel_Unused(uint16 k, uint16 j);
uint16 AnimtilesInstr_Delete(uint16 k, uint16 j);
uint16 AnimtilesInstr_Goto(uint16 k, uint16 j);
uint16 AnimtilesInstr_GotoIfBossBitSet_Unused(uint16 k, uint16 j);
uint16 AnimtilesInstr_GotoIfBossBitSetInArea(uint16 k, uint16 j);
uint16 AnimtilesInstr_GotoIfEventHappened(uint16 k, uint16 j);
uint16 AnimtilesInstr_GotoIfTourianStatueBusy(uint16 k, uint16 j);
uint16 AnimtilesInstr_GotoRel_Unused(uint16 k, uint16 j);
uint16 AnimtilesInstr_QueueMusic_Unused(uint16 k, uint16 j);
uint16 AnimtilesInstr_QueueSfx1_Unused(uint16 k, uint16 j);
uint16 AnimtilesInstr_QueueSfx2_Unused(uint16 k, uint16 j);
uint16 AnimtilesInstr_QueueSfx3_Unused(uint16 k, uint16 j);
uint16 AnimtilesInstr_SetBossBit_Unused(uint16 k, uint16 j);
uint16 AnimtilesInstr_SetEventHappened(uint16 k, uint16 j);
uint16 AnimtilesInstr_SetTimer_Unused(uint16 k, uint16 j);
uint16 AnimtilesInstr_SpawnPalfxObj(uint16 k, uint16 j);
uint16 AnimtilesInstr_SpawnTourianStatueEyeGlow(uint16 k, uint16 j);
uint16 AnimtilesInstr_SpawnTourianStatueSoul(uint16 k, uint16 j);
uint16 AnimtilesInstr_TourianStatueClearState(uint16 k, uint16 j);
uint16 AnimtilesInstr_TourianStatueSetState(uint16 k, uint16 j);
uint16 AnimtilesInstr_WaitUntilAreaBossDead_DoubleRet(uint16 k, uint16 j);
uint16 AnimtilesInstr_Write8PaletteColors(uint16 k, uint16 j);
void AnimtilesHandler(void);
void ClearAnimtiles(void);
void DisableAnimtiles(void);
void EnableAnimtiles(void);
void ProcessAnimtilesObject(void);
void SpawnAnimtiles(uint16 j);

// Bank 88
uint16 CalculatePowerBombHdmaScaled_LeftOfScreen(uint16 k, uint16 j, uint8 multval);
uint16 CalculatePowerBombHdmaScaled_OnScreen(uint16 k, uint16 j, uint8 multval);
uint16 CalculatePowerBombHdmaScaled_RightOfScreen(uint16 k, uint16 j, uint8 multval);
uint16 MotherBrainRisingHdmaObject(void);
uint16 SpawnHdmaObject(uint8 db, const void* p);
uint16 SpawnMotherBrainRainbowBeamHdma(void);
uint8 AdvanceSuitPickupColorMathSubscreenToWhite(void);
uint8 AdvanceSuitPickupColorMathToBlue(void);
uint8 AdvanceSuitPickupColorMathToOrange(void);
uint8 GravitySuitPickup_3_GiveSamusGravitySuit(void);
uint8 GravitySuitPickup_6(void);
uint8 RaiseOrLowerFx(void);
uint8 VariaSuitPickup_0_LightBeamAppears(void);
uint8 VariaSuitPickup_1_LightBeamWidens_Linear(void);
uint8 VariaSuitPickup_2_LightBeamWidens_Curved(void);
uint8 VariaSuitPickup_3_GiveSamusVariaSuit(void);
uint8 VariaSuitPickup_4_LightBeamShrinks(void);
uint8 VariaSuitPickup_5_LightBeamDissipates(void);
uint8 VariaSuitPickup_6(void);
uint16 CalculateCrystalFlashHdmaDataTablesScaled_LeftOfScreen(uint16 k, uint16 j);
uint16 CalculateCrystalFlashHdmaDataTablesScaled_OnScreen(uint16 k, uint16 j);
uint16 CalculateCrystalFlashHdmaDataTablesScaled_RightOfScreen(uint16 k, uint16 j);
void CalculateCrystalFlashHdmaObjectTablePtrs(uint16 k);
void CalculatePowerBombHdmaObjectTablePtrs(uint16 k);
void CalculatePowerBombHdmaTablePointers(uint16 k);
void CalculatePowerBombHdma_LeftOfScreen(uint16 k, const uint8 *j);
void CalculatePowerBombHdma_OnScreen(uint16 k, const uint8 *j);
void CalculatePowerBombHdma_RightOfScreen(uint16 k, const uint8 *j);
void CalculateXrayHdmaTable(void);
void SpawnWavySamusHdmaObject(void);
void CrystalFlashCleanup(uint16 k);
void CrystalFlashSetupPart1(void);
void CrystalFlashSetupPart2(void);
void DamageSamusInTopRow(void);
void DisableHdmaObjects(void);
void EnableHdmaObjects(void);
void UNUSED_ExpandingContractingHdmaEffect(void);
void FxHandleTide(void);
void FxRisingFunction_C428_WaterNormal(void);
void FxRisingFunction_LavaAcid(void);
void FxRisingFunction_LavaAcid_Raising(void);
void FxRisingFunction_LavaAcid_WaitToRise(void);
void FxRisingFunction_WaterRising(void);
void FxRisingFunction_WaterWaitToRise(void);
void FxTypeFunc_20_ScrollingSkyLand(void);
void FxTypeFunc_22_Unused(void);
void FxTypeFunc_24_Fireflea(void);
void FxTypeFunc_26_TourianEntranceStatue(void);
void FxTypeFunc_28_CeresRidley(void);
void FxTypeFunc_2C_Haze(void);
void FxTypeFunc_2_Lava(void);
void FxTypeFunc_4_Acid(void);
void FxTypeFunc_6_Water(void);
void FxTypeFunc_8_Spores(void);
void FxTypeFunc_A_Rain(void);
void FxTypeFunc_C_Fog(void);
void FxTypeFunc_2A_CeresElevator(void);
void HandleEarthquakeSoundEffect(void);
void HandleLayerBlendingPowerBomb(uint16 j);
void HandleLayerBlendingXrayCanShowBlocks(void);
void HandleLayerBlendingXrayCantShowBlocks(void);
void HandleLayerBlendingXrayFirefleaRoom(void);
void HandleMovingXrayUpDown(void);
void Handle_LavaAcidBG2YScroll_Func1(uint16 k);
void Handle_LavaAcidBG2YScroll_Func2(uint16 k);
void Handle_LavaAcidBG2YScroll_Func3(uint16 k);
uint16 CalculateFxType34IndirectHdmaTable(uint16 k, uint16 r18, uint16 r20, uint16 r22);
void HdmaObjectHandler(void);
void HdmaobjInstructionHandler(uint8 k);
void Hdmaobj_CleanUpTryCrystalFlash(uint16 k);
void Hdmaobj_ExplodeWhite(void);
void Hdmaobj_ExplodeYellow(void);
void Hdmaobj_PreExplodeWhite(void);
void Hdmaobj_PreExplodeYellow(void);
void InitializeLayerBlending(void);
void InitializeRainbowBeam(void);
void InitializeSpecialEffectsForNewRoom(void);
void LayerBlendingHandler(void);
void MoveXrayDown(void);
void MoveXrayUp(void);
void RoomCode_ScrollingSkyLand(void);
void RoomMainAsm_ScrollingSky(const uint16 *src);
void RoomMainAsm_ScrollingSkyOcean(void);
void RoomSetupAsm_ScrollingSkyOcean(void);
void SpawnBG3ScrollHdmaObject(void);
void SpawnBombTorizoHaze(void);
void SpawnCrystalFlashHdmaObjs(void);
void SpawnHdmaObjectToSlot0xA(uint8 db, const void* p);
void SpawnIntroCutsceneCrossfadeHdma(void);
void SpawnMorphBallEyeBeamHdma(void);
void SpawnPowerBombExplosion(void);
void SpawnTitleScreenGradientObjs(void);
void WaitUntilEndOfVblankAndClearHdma(void);

void DeleteHdmaObjects(void);
void SetupTourianEntranceStatueBg2YScroll(uint16 k);
void SetupHazeColorMathSubscreenHdma(uint16 k, uint16 a);
void SpawnDraygonMainScreenLayerHdmaObject(void);
void UNUSED_sub_88DF3D(void);
void UNUSED_sub_88DF46(void);
void SpawnWavyPhantoonHdmaObject(uint16 a, uint16 r22);
void SetRainbowBeamColorMathSubscreenBackdropColor(void);
void UpdateMorphBallEyeBeamHdmaDataTableAndColorMathSubscreenBackdropColor(uint16 k);

// Bank 89
void LoadFXHeader(void);
void LoadFxEntry(uint16 a);
void RoomCode_CeresElevatorShaft(void);

// Bank 8B
uint16 CalcItemPercentageCount(uint16 k, uint16 j);
uint16 CalcSinMult(uint16 k, uint16 r24);
uint16 CinematicGetTilemapOffsetForTile(uint16 r18);
uint16 Mode7Instr_ClearPreInstr(uint16 k, uint16 j);
uint16 Mode7Instr_DecTimerAndGoto(uint16 k, uint16 j);
uint16 Mode7Instr_Delete(uint16 k, uint16 j);
uint16 Mode7Instr_Goto(uint16 k, uint16 j);
uint16 Mode7Instr_SetPreInstr(uint16 k, uint16 j);
uint16 Mode7Instr_SetTimer(uint16 k, uint16 j);
uint16 PlayBabyMetroidCry1(uint16 k, uint16 j);
uint16 PlayBabyMetroidCry2(uint16 k, uint16 j);
uint16 PlayBabyMetroidCry3(uint16 k, uint16 j);
uint8 AdvanceFastScreenFadeIn(void);
uint8 AdvanceFastScreenFadeOut(void);
uint8 AdvanceSlowScreenFadeIn(void);
uint8 AdvanceSlowScreenFadeOut(void);
uint8 SpawnCimenaticSpriteObjectInner(uint16 k, uint16 j);
uint8 SpawnCinematicBgObject(uint16 j, uint16 a);
uint8 SpawnCinematicSpriteObject(uint16 j, uint16 a);
uint8 SpawnCinematicSpriteObjectToR18(uint16 j, uint16 r18);
uint8 SpawnMode7Object(Mode7ObjectDef j, uint16 a);
void AddNintentoLogoToOam(void);
Point16U CalcCeresSteamPos_Mode7(Point16U pt);
Point16U CalcExplosion_Mode7(uint16 k);
void CinematicUpdateSomeBg(void);
void ClearCinematicBgObjects(uint16 a);
void ClearCinematicSprites(void);
void ClearEnglishTextTilemap(void);
void ClearJapaneseTextTiles(void);
void ClearYColorsFromIndexX(uint16 k, uint16 j);
void ComposeFadingPalettes(void);
void ConfigureTitleSequenceGradientHDMA(void);
void CopyPalettesToFadingPalettes(void);
void CreditsObject_LoadDecompressedTilesToCinematicBgTilemap(uint16 j);
void CreditsObject_Init(uint16 j);
void CreditsObject_Process(void);
void CreditsObject_ProcessOne(void);
void DecomposePaletteDataForFading(void);
void DisableCinematicBgObjects(void);
void DisableCinematicBgTilemapUpdates(void);
void DisableTextGlowObjects_(void);
void DrawCinematicSpriteObjects_Ending(void);
void DrawCinematicSpriteObjects_Intro(void);
void DrawIntroSprites(void);
void EnableCinematicBgObjects(void);
void EnableCinematicBgTilemapUpdates(void);
uint16 EnableCinematicBgTilemapUpdates__(uint16 k, uint16 j);
uint16 EnableCinematicBgTilemapUpdates__0(uint16 k, uint16 j);
void EnableTextGlowObjects_(void);
void FadeInYColorsFromIndexX(uint16 k, uint16 j);
void FadeOutYColorsFromIndexX(uint16 k, uint16 j);
CoroutineRet GameState_1_OpeningCinematic_(void);
CoroutineRet GameState_37_CeresGoesBoomWithSamus_(void);
CoroutineRet GameState_39_EndingAndCredits_(void);
void HandleCinematicBgObjects(void);
void HandleCinematicSprites(void);
void HandleCinematicsTransitions(void);
void HandleMode7Objects(void);
void HandleMode7TransformationMatrix(void);
void HandleMode7TransformationNoRotation(void);
void HandleSamusDuringIntro(void);
void HandleTextGlowObjects(void);
CoroutineRet InitializeIoDisplayLogo_Async(void);
void Instr_StartIntroPage_Common(void);
void LoadTitleSequenceGraphics(void);
void MaybeHandleCinematicBgObjects(void);
void MaybeSkipCinematics(void);
uint16 Mult0x80Add(uint16 r18);
void ProcessCinematicBgObject(uint16 k, uint16 r18);
void ProcessCinematicBgObject_DrawChar(uint16 k, uint16 j, uint16 r18);
void ProcessCinematicBgObject_DrawToBgTilemap(uint16 k, uint16 j, uint16 r18);
void ProcessCinematicBgObject_DrawToTextTilemap(uint16 k, uint16 j, uint16 r18);
void ProcessCinematicBgObject_Nothing(uint16 k, uint16 j, uint16 r18);
void ProcessCinematicBgObject_Unk1(uint16 k, uint16 j, uint16 r18);
void ProcessCinematicBgObject_Unk2(uint16 k, uint16 j, uint16 r18);
void ProcessCinematicBgObjectsInstrs(uint16 k);
void ProcessCinematicSpriteInstructionList(uint16 k);
void ProcessMode7ObjectInstructions(uint16 k);
void ProcessTextGlowObject(void);
void ResetButtonAssignmentsToDefault(void);
void RevertButtonConfig(void);
void Samus_CalcPos_Mode7(void);
void SetPpuBackdropBlack(void);
void SetPpuBackdropSomeColor(void);
void SetupPpuForTitleSequence(void);
void SetupPpu_3_Mode7(void);
void SetupPpu_4_Mode1(void);
void SetupPpu_5_Mode7(void);
void SetupPpu_6_Mode1(void);
void SetupPpu_7_Mode1(void);
void SetupPpu_Intro(void);
void SpawnTextGlowObject(uint16 j, uint16 r18);
void TransferJapaneseTextTilesToVram(void);
void UpdateCinematicBgTilemap(void);
void UpdateSamusEyesTilemap(void);
void sub_8B94E1(void);
void sub_8B9743(void);
void CinematicSprPreInstr_1994ScrollingText(uint16 k);
void sub_8B9CDE(void);
uint16 sub_8BB51E(uint16 k, uint16 j);

// Bank 8D
void ClearPaletteFXObjects(void);
void DisablePaletteFx(void);
void EnablePaletteFx(void);
void PalFx_ProcessOne(uint16 k);
void PaletteFxHandler(void);
void SpawnPalfxObject(uint16 j);

// Bank 8F
uint16 RoomDefStateSelect_Finish(uint16 k);
uint16 RoomDefStateSelect_IsBossDead(uint16 k);
uint16 RoomDefStateSelect_IsEventSet(uint16 k);
uint16 RoomDefStateSelect_CollectedMorphBallAndMissiles(uint16 k);
uint16 RoomDefStateSelect_CollectedPowerBombs(uint16 k);
uint16 RoomDefStateSelect_MainAreaBossDead(uint16 k);
void HandleRoomDefStateSelect(uint16 k);
void PauseHook_DraygonRoom(void);
void RunDoorSetupCode(void);
void RunRoomMainCode(void);
void RunRoomSetupCode(void);
CoroutineRet UnpauseHook_DraygonRoom(void);

// Bank 90
Point16U Samus_CalcSpritemapPos(uint16 k);
Point16U Samus_CalcSpritemapPos_Transitions(uint16 j);
Point16U Samus_CalcSpritemapPos_Default(uint16 j);
Point16U Samus_CalcSpritemapPos_Special(uint16 j);
Point16U Samus_CalcSpritemapPos_Standing(uint16 j);
uint16 RunSamusCode(uint16 a);
uint16 Samus_DetermineGrappleSwingSpeed_X(void);
uint16 Samus_DetermineSpeedTableEntryPtr_X(void);
uint8 ClearCarry(void);
uint8 DeleteProjectileIfFarOffScreen(void);
uint8 FireSba(void);
uint8 FireSba_ClearCarry(void);
uint8 FireSba_FireIce(void);
uint8 FireSba_FirePlasma(void);
uint8 FireSba_FireSpazer(void);
uint8 FireSba_FireWave(void);
uint8 CrystalFlash(void);
uint8 HudSelectionHandler_MorphBall_Helper_FireBombOrSpread(void);
uint8 HudSelectionHandler_MorphBall_Helper_FireBombOrPowerBomb(void);
uint8 InitProjectilePositionDirection(uint16 r20);
uint8 SamusBottomDrawn_0_Standing(void);
uint8 SamusBottomDrawn_1_FlagDrawn(void);
uint8 SamusBottomDrawn_14_WallJump(void);
uint8 SamusBottomDrawn_19_DamageBoost(void);
uint8 SamusBottomDrawn_1B_Shinespark_CrystalFlash_Drained_MBDamaged(void);
uint8 SamusBottomDrawn_3_SpinJump(void);
uint8 SamusBottomDrawn_4_FlagNotDrawn(void);
uint8 SamusBottomDrawn_A_Knockback_CrystalFlashEnd(void);
uint8 SamusBottomDrawn_F_Transitions(void);
uint8 SamusCode_00_LockSamus(void);
uint8 SamusCode_01_UnlockSamus(void);
uint8 SamusCode_02_ReachCeresElevator(void);
uint8 SamusCode_03_UnspinSamus(void);
uint8 SamusCode_04_EndChargeBeam(void);
uint8 EndChargeBeam(void);
uint8 SamusCode_05_SetupDrained_AbleToStand(void);
uint8 SamusCode_06_LockToStation(void);
uint8 SamusCode_07_SetupForElevator(void);
uint8 SamusCode_08_SetupForCeresStart(void);
uint8 SamusCode_09_SetupForZebesStart(void);
uint8 SamusCode_0A_ClearDrawHandler(void);
uint8 SamusCode_0B_UnlockFromFacingForward(void);
uint8 SamusCode_0C_UpdateDueToUnpause(void);
uint8 SamusCode_0D_IsGrappleActive(void);
uint8 SamusCode_0E_UnlockFromCeresElevator(void);
uint8 SamusCode_0F_EnableTimerHandling(void);
uint8 SamusCode_10_UnlockFromReserveTank(void);
uint8 LockSamus_SetInanimateDrawHandler(void);
uint8 SamusCode_11_SetupForDeath(void);
uint8 SamusCode_13_DisableBlueFlashing(void);
uint8 SamusCode_12_EnableBlueFlashing(void);
uint8 SamusCode_14_QueueSfx(void);
uint8 SamusCode_15_LockToSuitAcquisition(void);
uint8 SamusCode_16_EnableRainbowSamus(void);
uint8 SamusCode_17_DisableRainbowSamusAndStandUp(void);
uint8 SamusCode_19_FreezeDrainedSamus(void);
uint8 SamusCode_18_SetupDrained_UnableToStand(void);
uint8 SamusCode_1A_EnterGunship(void);
uint8 SamusCode_1B_LockForReserveTank(void);
uint8 SamusCode_1C_PlaySpinSfxIfSpinJumping(void);
uint8 SamusCode_1D_ClearSoundInDoor(void);
uint8 SamusCode_1E_ResumeSfxAfterPowerBombExplosion(void);
uint8 SamusCode_1F_KillGrappleBeam(void);
uint8 Samus_CanFireBeam(void);
uint8 Samus_CanFireAnyMissile(void);
uint8 Samus_MoveY_Simple(void);
uint8 Samus_EndShinespark(void);
uint8 UNUSED_Samus_Func26(void);
uint8 Samus_GrappleWallJumpCheck(int32 amt);
uint8 Samus_HitInterrupt_Ball(void);
uint8 Samus_HitInterrupt_Falling(void);
uint8 Samus_HitInterrupt_KnockbackGrapple(void);
uint8 Samus_HitInterrupt_Drained(void);
uint8 Samus_HitInterrupt_Stand(void);
uint8 Samus_HitInterrupt_Turning(void);
uint8 Samus_HitInterrupt_Unused(void);
uint8 Samus_MoveY_Simple_(void);
uint8 Samus_SetupForBeingDrained(void);
uint8 Samus_WallJumpCheck(int32 amt);
uint8 SetupBombJump_Run_Fall_Moonwalk_WallJump_RanIntoWall_Grapple(void);
uint8 SetupBombJump_Grabbed_Shinespark_CrystalFlash_Drained_MBAttack(void);
uint8 SetupBombJump_Jump_TurnAround_DamageBoost_Transition(void);
uint8 SetupBombJump_Morphed_Knockback_CrystalFlash(void);
uint8 SetupBombJump_Stand_Crouch(void);
uint8 SwitchToHudHandler_Grapple(void);
uint8 SwitchToHudHandler_Missiles(void);
uint8 SwitchToHudHandler_Nothing(void);
uint8 SwitchToHudHandler_PowerBombs(void);
uint8 SwitchToHudHandler_SuperMissiles(void);
uint8 SwitchToHudHandler_Xray(void);
uint8 UNUSED_SamusBottomDrawn_D(void);
uint8 UpdateArmCannonIsOpenFlag(void);
void AdvanceArmCannonFrame(void);
void AtmosphericTypeFunc_1_2_FootstepSplash(uint16 k, uint16 j);
void AtmosphericTypeFunc_3_DivingSplash(uint16 k, uint16 j);
void AtmosphericTypeFunc_4_LavaSurfaceDmg(uint16 k, uint16 j);
void AtmosphericTypeFunc_5_Bubbles(uint16 k, uint16 j);
void AtmosphericTypeFunc_6_7_Dust(uint16 k, uint16 j);
void AtmosphericTypeFunc_Common(uint16 j, uint16 a);
void BombSpread(void);
void HandleBomb(void);
void CheckBeamCollByDir(uint16 k);
void CheckBeamCollByDir_Vertical(void);
void CheckBeamCollByDir_Diagonal(void);
void CheckBeamCollByDir_Right(void);
void CheckBeamCollByDir_Left(void);
void ClearFlareAnimationState(void);
void ClearProjectile(uint16 k);
void DisableMinimapAndMarkBossRoomAsExplored(void);
void DrawFlareAnimationComponent(uint16 k);
void DrawSamusAndProjectiles(void);
void Samus_FrameHandlerGamma_DrawTimer(void);
void FireChargedBeam(void);
void FireEndOfSpazerSba(uint16 j);
void FireHyperBeam(void);
void FireUnchargedBeam(void);
void UNUSED_Grapple_Func1(void);
void HandleArmCannonOpenState(void);
void HandleAtmosphericEffects(void);
void Samus_InputHandler_AutoJump(void);
void HandleChargingBeamGfxAudio(void);
void HandleControllerInputForGamePhysics(void);
void HandleSamusPlacementModeToggles(void);
void Samus_FrameHandlerBeta_Debug(void);
void HandleProjectiles(void);
void HandleProjectileTrails(void);
void HandleSamusMovementAndPause(void);
void HandleSwitchingHudSelection(void);
void HudSelectionHandler_CrouchEtcTrans(void);
void HudSelectionHandler_GrabbedByDraygon(void);
void HudSelectionHandler_Grappling(void);
void HudSelectionHandler_JumpEtc(void);
void HudSelectionHandler_MissilesOrSuperMissiles(void);
void HudSelectionHandler_MorphBall(void);
void HudSelectionHandler_Normal(void);
void HudSelectionHandler_NothingOrPowerBombs(void);
void HudSelectionHandler_TurningAround(void);
void HudSelectionHandler_Xray(void);
void InitializeMiniMapBroken(void);
void InitializeProjectileSpeed(uint16 k, uint16 r22);
void InitializeAnyMissileSpeed(uint16 r20);
void KillProjectile(uint16 k);
void KillProjectileFunc_0_Up(uint16 j);
void KillProjectileFunc_1_UpRight(uint16 j);
void KillProjectileFunc_2_Right(uint16 j);
void KillProjectileFunc_3_DownRight(uint16 j);
void KillProjectileFunc_4_Down(uint16 j);
void KillProjectileFunc_6_DownLeft(uint16 j);
void KillProjectileFunc_7_Left(uint16 j);
void KillProjectileFunc_8_UpLeft(uint16 j);
void LoadProjectilePalette(uint16 a);
void MainScrollingRoutine(void);
void AccelerateMissileOrSuperMissile(uint16 k);
void SpawnSuperMissileLink(void);
void DemoRecorder_MoveSamusWithControlPad(void);
void HandlePowerBomb(void);
void ProjTrailInstr_MoveLeftProjectileTrailDown(uint16 j);
void ProjTrailInstr_MoveLeftProjectileTrailUp(uint16 j);
void ProjTrailInstr_MoveRightProjectileTrailDown(uint16 j);
void ProjPreInstr_BeamOrIceWave(uint16 k);
void ProjPreInstr_Beam_NoWaveBeam(uint16 k);
void ProjPreInstr_Bomb(uint16 k);
void ProjPreInstr_BlockCollNoWaveBeamVert(uint16 k);
void ProjPreInstr_BlockCollNoWaveBeamDiagonal(uint16 k);
void ProjPreInstr_BlockCollNoWaveBeamHoriz(uint16 k);
void ProjPreInstr_EndOfSpazerSba(uint16 k);
void ProjPreInstr_SuperMissileLink(uint16 k);
void ProjPreInstr_HyperBeam(uint16 k);
void ProjPreInstr_IceSbaMain(uint16 k);
void ProjPreInstr_IceSbaEnd(uint16 k);
void ProjPreInstr_Missile(uint16 k);
void ProjPreInstr_BlockCollMissileVert(uint16 k);
void ProjPreInstr_BlockCollMissileDiagonal(uint16 k);
void ProjPreInstr_BlockCollMissileHoriz(uint16 k);
void ProjPreInstr_PlasmaSba(uint16 k);
void ProjPreInstr_PlasmaSba_Phase0_Expand(uint16 j);
void ProjPreInstr_PlasmaSba_Phase1_Contract(uint16 j);
void ProjPreInstr_PlasmaSba_Phase2_Disperse(uint16 j);
void ProjPreInstr_PowerBomb(uint16 k);
void ProjPreInstr_SpazerSba(uint16 k);
void ProjPreInstr_SpazerSba_ClearProjPair0(uint16 k);
void ProjPreInstr_SpazerSba_ClearProjPair2(uint16 k);
void ProjPreInstr_SpazerSba_ClearProjPair4(uint16 k);
void ProjPreInstr_SpazerSba_ClearProjPair6(uint16 k);
void ProjPreInstr_SpazerSba_Phase0_Circle(uint16 j, uint16 r22);
void ProjPreInstr_SpazerSba_Phase2_FlyToPoint(uint16 j, uint16 r22);
void ProjPreInstr_SpazerSba_Phase4_FlyFromPoint(uint16 j, uint16 r22);
void ProjPreInstr_SpeedEcho(uint16 k);
void ProjPreInstr_SpreadBomb(uint16 k);
void ProjPreInstr_SuperMissile(uint16 k);
void ProjPreInstr_BlockCollSuperMissileVert(uint16 k);
void ProjPreInstr_BlockCollSuperMissileDiagonal(uint16 k);
void ProjPreInstr_BlockCollSuperMissileHoriz(uint16 k);
void ProjPreInstr_UnknownProj8027(uint16 k);
void ProjPreInstr_WaveCombined(uint16 k);
void ProjPreInstr_BlockCollWaveBeamVert(uint16 k);
void ProjPreInstr_BlockCollWaveBeamDiagonal(uint16 k);
void ProjPreInstr_BlockCollWaveBeamHoriz(uint16 k);
void ProjPreInstr_WaveSba(uint16 k);
void ProjPreInstr_Wave_Shared(uint16 k);
void ProjectileReflection(uint16 r20);
void UNUSED_ClearSuperMissileLinkIfExplosion(uint16 k);
void TriggerShinesparkWindup(void);
Point16U Projectile_SinLookup(uint16 j, uint16 a);
void ResetProjectileData(void);
void RunFrameHandlerGamma(void);
void RunSamusMovementHandler(void);
void UNUSED_SamusCrouching_Nothing(void);
void Samus_DisplayHandler_InanimateSamus(void);
void Samus_DisplayHandler_UsingElevator(void);
void Samus_DrawHandler_Default(void);
void DrawSamusSprites(void);
void Samus_MovementHandler_CrystalFlashMain(void);
void SamusMoveHandler_CrystalFlash_0_DecMissiles(void);
void SamusMoveHandler_CrystalFlash_1_DecSuperMissiles(void);
void SamusMoveHandler_CrystalFlash_2_DecPowerBombs(void);
void Samus_MovementHandler_CrystalFlashStart(void);
void Samus_MovementHandler_Xray(void);
void Samus_AlignBottomWithPrevPose(void);
void Samus_Animate(void);
void Samus_Animate_AcidFx(void);
void Samus_Animate_LavaFx(void);
void Samus_Animate_NoFx(void);
void Samus_Animate_SubmergedLavaAcid(void);
void Samus_Animate_WaterFx(void);
void Samus_ArmCannon_Draw(void);
void Samus_MoveX_CeresRidleyPush(void);
void Samus_MoveY_CeresRidleyPush(void);
void Samus_MoveX_KnockbackOrBombJump(void);
void Samus_BombJumpEnd(void);
int32 Samus_CalcBaseSpeed_X(uint16 k);
int32 Samus_CalcDisplacementMoveLeft(int32 amt);
int32 Samus_CalcDisplacementMoveRight(int32 amt);
void Samus_CalcDistanceMoved_X(void);
void Samus_CalcDistanceMoved_Y(void);
uint32 Samus_CalcSpeed_X(uint32 amt);
void Samus_CallInputHandler(void);
void Samus_CheckStartFalling(void);
void Samus_HandleKnockbackVerticalColl(void);
void Samus_ClearXSpeedIfColl(void);
void Samus_DetermineAccel_Y(void);
void Samus_Draw(void);
void Samus_DrawDuringDeathAnim(void);
void Samus_DrawEcho(uint16 j);
void Samus_DrawEchoes(void);
void Samus_DrawHandler_EndOfShinespark(void);
void Samus_DrawManyEchoes_Unused(void);
void Samus_DrawShinesparkCrashEchoProjectiles(void);
void Samus_DrawShinesparkCrashEchoes(uint16 k);
void Samus_DrawStartingDeathAnim(void);
void Samus_DrawInanimateSamus(void);
void Samus_FallingMovement(void);
void Samus_FootstepGraphics(void);
void Samus_FootstepGraphics_Common(void);
void Samus_FootstepGraphics_Crateria(void);
void Samus_FootstepGraphics_Maridia(void);
void Samus_FrameHandlerAlfa_Normal(void);
void Samus_FrameHandlerAlfa_Demo(void);
void Samus_FrameHandlerAlfa_SamusLocked(void);
void Samus_FrameHandlerBeta_TitleDemo(void);
void Samus_FrameHandlerBeta_Normal(void);
void Samus_FrameHandlerGamma_UnlockSamusFromDrained(void);
void Samus_ClearMovement_ResetPoseChanges(void);
void Samus_FrameHandlerBeta_IntroDemo(void);
void Samus_FrameHandlerBeta_SamusAppears(void);
void Samus_FrameHandlerBeta_Ceres(void);
void Samus_FrameHandlerBeta_RidingElevator(void);
void Samus_FrameHandlerGamma_KeepSamusLockedFromDrained(void);
void Samus_InputHandler_Xray(void);
void Samus_MovementHandler_F04B_Unused(void);
void Samus_FrameHandlerGamma_HandleTimer(void);
void Samus_FrameHandlerGamma_PushingOutOfRidleysWay(void);
void Samus_PushOutOfRidleysWay_Leftwards(void);
void Samus_PushOutOfRidleysWay_Rightwards(void);
void Samus_FrameHandlerGamma_PushMorphedSamusOutOfRidleysWay_Unused(void);
void Samus_ClearSpecialFalling_Unused(void);
void Samus_FrameHandlerGamma_SpecialFalling_Unused(void);
uint16 Samus_GetTopBound(void);
uint16 Samus_GetBottomBound(void);
void Samus_FrameHandlerGamma_GrabbedByDraygon(void);
static void Samus_HandleAnimDelay(void);
void Samus_HandleCooldown(void);
void Samus_HandleExtraRunspeedX(void);
void Samus_HandleHudSpecificBehaviorAndProjs(void);
void Samus_MovementHandler_DrainedCrouching(void);
void Samus_HandleMovement_X(void);
void Samus_HandlePeriodicDamage(void);
void Samus_HandleScroll_X(void);
void Samus_HandleScroll_Y(void);
void Samus_HitInterruption(void);
void Samus_MovementHandler_HorizontalBombJump(void);
void Samus_InitBombJump(void);
void Samus_InitJump(void);
void Samus_InitWallJump(void);
void Samus_InputHandler_Normal(void);
void Samus_InputHandler_Demo(void);
void Samus_AutoJump_HurtFlash_PreviousInput_Handler(void);
void Samus_JumpingMovement(void);
void Samus_FrameHandlerBeta_EnterExitGunship(void);
void Samus_LowHealthCheck_(void);
void Samus_LowHealthCheck_0(void);
void Samus_MorphedBouncingMovement(void);
void Samus_MorphedFallingMovement(void);
void Samus_MoveDown(int32 amt);
void Samus_MoveDown_NoColl(int32 amt);
void Samus_MoveDown_SetPoseCalcInput(void);
void Samus_MoveExtraY(void);
void Samus_MovementHandler_ShinesparkWindup(void);
void Samus_MovementHandler_VerticalShinespark(void);
void Samus_MovementHandler_EndBombJump(void);
void Samus_MovementHandler_BombJumpMain(void);
void Samus_MovementHandler_BombJumpStart(void);
void Samus_MovementHandler_F072_Unused(void);
void Samus_MovementHandler_Knockback(void);
void Samus_MovementHandler_Invalid(void);
void Samus_MovementHandler_Knockback_StraightUp_Unused(void);
void Samus_MovementHandler_Knockback_Down(void);
void Samus_MovementHandler_Knockback_Up(void);
void Samus_MovementHandler_ReleaseFromGrapple(void);
void Samus_MovementHandler_ShinesparkCrash_EchoCircle(void);
void Samus_MovementHandler_ShinesparkCrash_EchoCircle_Finish(void);
void Samus_MovementHandler_ShinesparkCrash_Finish(void);
void Samus_MovementHandler_ShinesparkCrash_EchoCircle_Phase0(void);
void Samus_MovementHandler_ShinesparkCrash_EchoCircle_Phase1(void);
void Samus_MovementHandler_ShinesparkCrash_EchoCircle_Phase2(void);
void Samus_MovementHandler_DiagonalShinespark(void);
void Samus_MovementHandler_HorizontalShinespark(void);
void Samus_MoveLeft(int32 amt);
void Samus_MoveLeft_NoColl(int32 amt);
void Samus_MoveRight(int32 amt);
void Samus_MoveRight_NoColl(int32 amt);
void Samus_MoveUp(int32 amt);
void Samus_MoveUp_NoColl(int32 amt);
void Samus_MoveUp_SetPoseCalcInput(void);
void Samus_MoveX(int32 amt);
void Samus_MoveY_WithSpeedCalc(void);
void Samus_Move_NoBaseSpeed_X(void);
void Samus_Move_NoSpeedCalc_Y(void);
void Samus_MovementHandler_Normal(void);
void Samus_Movement_00_Standing(void);
void Samus_Movement_01_Running(void);
void Samus_Movement_02_NormalJumping(void);
void Samus_Movement_03_SpinJumping(void);
void Samus_Movement_04_MorphBallOnGround(void);
void Samus_Movement_05_Crouching(void);
void Samus_Movement_06_Falling(void);
void Samus_Movement_07_Unused(void);
void Samus_Movement_08_MorphBallFalling(void);
void Samus_Movement_09_Unused(void);
void Samus_Movement_0A_KnockbackOrCrystalFlashEnding(void);
void Samus_Movement_0B_Unused(void);
void Samus_Movement_0C_Unused(void);
void Samus_Movement_0D_Unused(void);
void Samus_Movement_0E_TurningAroundOnGround(void);
void Samus_Movement_0F_CrouchingEtcTransition(void);
void Samus_Movement_10_Moonwalking(void);
void Samus_Movement_11_SpringBallOnGround(void);
void Samus_Movement_12_SpringBallInAir(void);
void Samus_Movement_13_SpringBallFalling(void);
void Samus_Movement_14_WallJumping(void);
void Samus_Movement_15_RanIntoWall(void);
void Samus_Movement_16_Grappling(void);
void Samus_Movement_17_TurningAroundJumping(void);
void Samus_Movement_18_TurningAroundFalling(void);
void Samus_Movement_19_DamageBoost(void);
void Samus_Movement_1A_GrabbedByDraygon(void);
void Samus_Movement_1B_ShinesparkEtc(void);
void Samus_PauseCheck(void);
void Samus_PostGrappleCollisionDetect(void);
void Samus_FrameHandlerGamma_PushOutOfRidleysWay(void);
void Samus_ReleaseFromDraygon(void);
void Samus_ReleaseFromDraygon_(void);
void Samus_ScrollFinishedHook_SporeSpawnFight(void);
void Samus_SetGrabbedByDraygonPose(uint16 a);
void Samus_SetPushedOutOfCeresRidley(void);
void Samus_SetRadius(void);
void Samus_SetSpeedForKnockback_Y(void);
void Samus_ShinesparkMove_X(void);
void Samus_ShinesparkMove_Y(void);
void Samus_ShootCheck(void);
void Samus_SpawnAirBubbles(void);
void Samus_SpawnWaterSplash(uint16 r18);
void Samus_SpinJumpMovement(void);
void Samus_UpdatePreviousPose(void);
void Samus_UpdateSpeedEchoPos(void);
void Samus_UpdateSuitPaletteIndex(void);
void Samus_MovementHandler_VerticalBombJump(void);
void Samus_FrameHandlerBeta_SamusLocked(void);
void SetInitialBeamSpeed(uint16 r20);
void SetLiquidPhysicsType(void);
void SetupBombJump(void);
void SpawnProjectileTrail(uint16 k);
void SuperMissileBlockCollDetect_Horizontal(void);
void SuperMissileBlockCollDetect_Vertical(void);
void DemoRecorder_DisplaySamusPositionAsAmmoIfMorphed(void);
void UpdateBeamTilesAndPalette(void);
void UpdateMinimap(void);
void UpdateHudMinimapTilemap(uint16 r18, uint16 r22, uint16 r34, uint16 r30, uint16 r32, uint16 r38, uint16 r24, uint16 r40, uint16 r26, uint16 r42, uint16 r28);

void WaveBeam_CheckColl(uint16 k);
void WaveBeam_CheckColl_Vertical(void);
void WaveBeam_CheckColl_Diagonal(void);
void WaveBeam_CheckColl_Right(void);
void WaveBeam_CheckColl_Left(void);
void WriteBeamPalette_A(uint16 a);
void WriteBeamPalette_Y(uint16 j);
void Samus_MovementHandler_CrystalFlashFinish(void);
void DrawSamus_NoChargeOrGrapple(void);
void Samus_DrawHandler_NoChargeOrGrapple(void);

// Bank 91
uint16 DemoInstr_ClearPreInstr(uint16 k, uint16 j);
uint16 DemoInstr_DecTimerAndGoto(uint16 k, uint16 j);
uint16 DemoInstr_DisableDemo(uint16 k, uint16 j);
uint16 DemoInstr_Finish(uint16 k, uint16 j);
uint16 DemoInstr_GiveInputToPlayerAndDisableDemo(uint16 k, uint16 j);
uint16 DemoInstr_FaceSamusLeftAndDisableDemo(uint16 k, uint16 j);
uint16 DemoInstr_Goto(uint16 k, uint16 j);
uint16 DemoInstr_SetPreInstr(uint16 k, uint16 j);
uint16 DemoInstr_SetTimer(uint16 k, uint16 j);
bool CanXrayShowBlocks(void);
uint8 HandleBeamChargePalettes(void);
uint8 HandleCollDueToChangedPose_Block_CollAbove(void);
uint8 HandleCollDueToChangedPose_Block_CollBelow(void);
uint8 HandleCollDueToChangedPose_Block_CollBoth(void);
uint8 HandleCollDueToChangedPose_Block_NoColl(void);
uint8 HandleCollDueToChangedPose_Solid_CollAbove(void);
uint8 HandleCollDueToChangedPose_Solid_CollBelow(void);
uint8 HandleCollDueToChangedPose_Solid_CollBoth(void);
uint8 HandleCollDueToChangedPose_Solid_NoColl(void);
uint8 HandleVisorPalette(void);
uint8 MaybeUnused_sub_91F7F4(void);
uint8 MaybeUnused_sub_91F840(void);
uint8 MaybeUnused_sub_91F8B0(void);
uint8 SamusFunc_F404(void);
uint8 SamusFunc_F468_CrouchTransEtc(void);
uint8 SamusFunc_F468_Crouching(void);
uint8 SamusFunc_F468_DamageBoost(void);
uint8 SamusFunc_F468_DamageBoost_(void);
uint8 SamusFunc_F468_Falling(void);
uint8 SamusFunc_F468_Moonwalking(void);
uint8 SamusFunc_F468_MorphBall(void);
uint8 SamusFunc_F468_NormalJump(void);
uint8 SamusFunc_F468_Running(void);
uint8 SamusFunc_F468_Shinespark(void);
uint8 SamusFunc_F468_SpinJump(void);
uint8 SamusFunc_F468_Springball(void);
uint8 SamusFunc_F468_Standing(void);
uint8 SamusFunc_F468_TurnAroundFalling(void);
uint8 SamusFunc_F468_TurnAroundJumping(void);
uint8 SamusFunc_F468_TurningAroundOnGround(void);
uint8 SamusFunc_F468_Unused(void);
uint8 SamusFunc_F468_WallJumping(void);
void Samus_CheckWalkedIntoSomething(void);
uint8 Samus_CrouchTrans(void);
uint8 Samus_HandleCrystalFlashPals(void);
uint8 Samus_HandleScrewAttackSpeedBoostingPals(void);
uint8 Samus_HandleShinesparkingPals(void);
uint8 Samus_HandleTransFromBlockColl_1_0(void);
uint8 Samus_HandleTransFromBlockColl_1_1(void);
uint8 Samus_HandleTransFromBlockColl_1_2(void);
uint8 Samus_HandleTransFromBlockColl_1_3(void);
uint8 Samus_HandleTransFromBlockColl_1_5(void);
uint8 Samus_HandleTransitionsA_5_1_0(void);
uint8 Samus_HandleTransitionsA_5_1_2(void);
uint8 Samus_HandleTransitionsA_5_1_5(void);
uint8 Samus_HandleTransitionsB_1_0(void);
uint8 Samus_HandleTransitionsB_1_10(void);
uint8 Samus_HandleTransitionsB_1_11(void);
uint8 Samus_HandleTransitionsB_1_4(void);
uint8 Samus_HandleTransitionsB_1_6(void);
uint8 Samus_HandleTransitionsB_1_7(void);
uint8 Samus_HandleXrayPals(void);
uint8 Samus_MorphBallBounceNoSpringballTrans(void);
uint8 Samus_MorphBallBounceSpringballTrans(void);
uint8 Samus_MorphTrans(void);
uint8 SetNewPoseCommand(void);
uint8 Samus_SpeedBoosterShinePals(void);
uint8 Samus_StandOrUnmorphTrans(void);
uint8 DrainedSamusHandler_0_LetSamusFall(void);
uint8 DrainedSamusHandler_1_SetSamusStandingDrainedPose(void);
uint8 DrainedSamusHandler_2_ReleaseSamusFromDrainedPose(void);
uint8 DrainedSamusHandler_3_EnableHyperBeam(void);
uint8 DrainedSamusHandler_4_SetSamusCrouchOrFallDrainedPose(void);
uint8 Xray_Initialize(void);
uint8 nullsub_164(void);
void CalculateXrayHdmaTableInner(uint16 k, uint16 j, uint16 r18, uint16 r20, bool off_screen, uint16 *dest_addr);
void CopyToSamusSuitPalette(uint16 k);
void CopyToSamusSuitTargetPalette(uint16 k);
void DemoObjectInputHandler(void);
void DemoPreInstr_BabyMetroidDiscovery_RunLeft(void);
void DemoPreInstr_BabyMetroidDiscovery_StopAndLook(void);
void DemoPreInstr_CheckLeaveDemo_Shinespark(void);
void DemoPreInstr_CheckLeaveDemo(void);
void DemoSet_LandingSite(void);
void DemoSet_StandFaceRight(void);
void DemoSet_StandFaceLeft(void);
void DemoSet_MorphBallMoveLeft(void);
void DemoSet_FallFaceLeft(void);
void DemoSet_Shinespark(void);
void DemoSet_GauntletEntrance(void);
void DemoSet_StandFaceLeft_LowHealth(void);
void DemoSet_SetSamusPose(uint16 a);
void DisableDemoInput(void);
void EnableDemoInput(void);
void GameState_28_Unused_(void);
void GravitySuitPickup(void);
void HandleCollDueToChangedPose(void);
void HandleJumpTransition(void);
void HandleJumpTransition_NormalJump(void);
void HandleJumpTransition_SpinJump(void);
void HandleJumpTransition_SpringBallInAir(void);
void HandleJumpTransition_WallJump(void);
void HandleLandingGraphics(void);
void HandleLandingGraphics_Brinstar(void);
void HandleLandingGraphics_Delete(void);
void HandleLandingGraphics_Crateria(void);
void HandleLandingGraphics_Maridia_FootstepSplashes(void);
void HandleLandingGraphics_Norfair_WreckedShip_Dust(void);
void HandleLandingGraphics_Tourian(void);
void HandleLandingSoundEffectsAndGfx(void);
void HandleMiscSamusPalette(void);
void HdmaobjPreInstr_XraySetup(uint16 k);
void InitializeSuitPickupHdma(void);
void LoadBlockToXrayBg2(uint16 a, uint16 k, uint16 j);
void LoadDemoData(void);
void LoadDemoInputObject(uint16 a, uint16 j);
void MakeSamusFaceForward(void);
void ProcessDemoInputObject(void);
void ResetDemoData(void);
void SetNonXraySamusPose(void);
void Samus_UpdatePoseFromEquipmentChange(void);
void Samus_UpdatePoseFromEquipmentChange_Standing(void);
void Samus_UpdatePoseFromEquipmentChange_SpringBall(void);
void Samus_UpdatePoseFromEquipmentChange_WallJump(void);
void Samus_UpdatePoseFromEquipmentChange_SpinJump(void);
void Samus_UpdatePoseFromEquipmentChange_MorphBall(void);
void SamusFunc_EC80(void);
void SamusFunc_F1D3(void);
void SamusFunc_F433(void);
void SamusFunc_F468(void);
void SamusFunc_FA0A(void);
void Samus_CancelSpeedBoost(void);
void Samus_Copy10PalColors(uint16 j);
void Samus_Copy6PalColors(uint16 j);
void Samus_DealDamage(uint16 a);
void XraySamusPostInputHandler(void);
void Samus_HandlePalette(void);
void Samus_HandleTransFromBlockColl(void);
void Samus_HandleTransFromBlockColl_1(void);
void Samus_HandleTransFromBlockColl_2(void);
void Samus_HandleTransFromBlockColl_3(void);
void Samus_HandleTransFromBlockColl_4(void);
void Samus_HandleTransFromBlockColl_5(void);
void Samus_HandleTransitions(void);
void Samus_HandleTransitionsA_1(void);
void Samus_HandleTransitionsA_2(void);
void Samus_HandleTransitionsA_5(void);
void Samus_HandleTransitionsA_5_1(void);
void Samus_HandleTransitionsA_5_2(void);
void Samus_HandleTransitionsA_5_4(void);
void Samus_HandleTransitionsA_5_5(void);
void Samus_HandleTransitionsA_5_6(void);
void Samus_HandleTransitionsA_6(void);
void Samus_HandleTransitionsA_7(void);
void Samus_HandleTransitionsA_8(void);
void Samus_HandleTransitionsB_1(void);
void Samus_HandleTransitionsB_10(void);
void Samus_HandleTransitionsB_2(void);
void Samus_HandleTransitionsB_3(void);
void Samus_HandleTransitionsB_4(void);
void Samus_HandleTransitionsB_5(void);
void Samus_HandleTransitionsB_8(void);
void Samus_HandleTransitionsB_9(void);
void Samus_HandleTransitionsB_9B(void);
void Samus_HandleTransitionsC_1(void);
void Samus_HandleTransitionsC_2(void);
void Samus_HandleTransitionsC_3(void);
void Samus_HandleTransitionsC_4(void);
void Samus_HandleTransitionsC_5(void);
void Samus_HandleTransitionsC_6(void);
void Samus_HandleTransitionsC_7(void);
void Samus_HandleTransitionsC_8(void);
void Samus_Initialize(void);
void Samus_InputHandler(void);
void Samus_Input_00_Standing(void);
void Samus_Input_01_Running(void);
void Samus_Input_02_NormalJumping(void);
void Samus_Input_03_SpinJumping(void);
void Samus_Input_04_MorphBallOnGround(void);
void Samus_Input_05_Crouching(void);
void Samus_Input_06_Falling(void);
void Samus_Input_07_Unused(void);
void Samus_Input_08_MorphBallFalling(void);
void Samus_Input_09_Unused(void);
void Samus_Input_0A_KnockbackOrCrystalFlashEnding(void);
void Samus_Input_0B_Unused(void);
void Samus_Input_0C_Unused(void);
void Samus_Input_0D_Unused(void);
void Samus_Input_0E_TurningAroundOnGround(void);
void Samus_Input_0F_CrouchingEtcTransition(void);
void Samus_Input_10_Moonwalking(void);
void Samus_Input_11_SpringBallOnGround(void);
void Samus_Input_12_SpringBallInAir(void);
void Samus_Input_13_SpringBallFalling(void);
void Samus_Input_14_WallJumping(void);
void Samus_Input_15_RanIntoWall(void);
void Samus_Input_16_Grappling(void);
void Samus_Input_17_TurningAroundJumping(void);
void Samus_Input_18_TurningAroundFalling(void);
void Samus_Input_19_DamageBoost(void);
void Samus_Input_1A_GrabbedByDraygon(void);
void Samus_Input_1B_ShinesparkEtc(void);
void Samus_LoadSuitPalette(void);
void Samus_LoadSuitTargetPalette(void);
void Samus_LookupTransitionTable(void);
void Samus_LookupTransitionTableFailureHandler(void);
void Samus_RestoreHealth(uint16 a);
void Samus_RestoreMissiles(uint16 a);
void Samus_RestorePowerBombs(uint16 a);
void Samus_RestoreSuperMissiles(uint16 a);
void Samus_SetAnimationFrameIfPoseChanged(void);
void Samus_UpdatePreviousPose_0(void);
void DrainedSamusHandler(uint16 a);
void VariaSuitPickup(void);
void XrayRunHandler(void);
void Xray_SetupStage1_FreezeTime_BackupBg2(uint16 k);
void Xray_SetupStage2_ReadBg1_2ndScreen(void);
void Xray_SetupStage3_ReadBg1_1stScreen(void);
void Xray_SetupStage4_SetupAndReadBg2_1stScreen(void);
void CopyBottomBg1RowToXrayBg2(uint16 dst_r22, uint16 r26, uint16 r28, uint16 r30);
void LoadRightHalfOfRevealedBlock(uint16 dst_r22, uint16 r34);
void LoadRevealedBlock(uint16 r18, uint16 r22, uint16 r36);
void Xray_SetupStage5_ReadBg2_2ndScreen(void);
void Xray_SetupStage6_TransferBg_1stScreen(void);
void Xray_SetupStage7_InitXrayBeam_TransferBg_2ndScreen(void);
void Xray_SetupStage8_SetBackdropColor(void);
void sub_91EFC3(void);
DemoInputEntry get_DemoInputEntry(uint16 demo_input_);

// Bank 92
uint8 PlaySamusFanfare(void);
void DrawSamusSuitExploding(void);
void SetSamusTilesDefsForCurAnim(void);
void Unused_DebugSamusTileViewer(void);

// Bank 93
uint16 ProjInstr_Delete(uint16 k, uint16 j);
uint16 ProjInstr_Goto(uint16 k, uint16 j);
void DrawBombAndProjectileExplosions(void);
void DrawProjectiles(void);
void InitializeBombExplosion(uint16 k);
void InitializeInstrForBombOrPowerBomb(uint16 k);
void InitializeInstrForSuperMissile(uint16 k);
void InitializeProjectile(uint16 k);
void InitializeSbaProjectile(uint16 k);
void InitializeShinesparkEchoOrSpazerSba(uint16 k);
void KillProjectileInner(uint16 k);
uint16 GetProjectileTrailFrame(uint16 k);
void RunProjectileInstructions(void);
void Unused_PartialDrawProjectiles(void);
ProjectileInstr get_ProjectileInstr(uint16 instr_ptr);

// Bank 94
uint8 BlockCollGrappleBeam(void);
uint8 BlockCollMissileHoriz(uint16 k);
uint8 BlockCollMissileVert(uint16 k);
uint8 BlockCollNoWaveBeamHoriz(uint16 k);
uint8 BlockCollNoWaveBeamVert(uint16 k);
uint8 BlockCollSpreadBomb(uint16 k);
uint8 BlockCollWaveBeamHoriz(uint16 k);
uint8 BlockCollWaveBeamVert(uint16 k);
uint8 BlockFunc_AC31(void);
uint8 BlockReactGrapple(void);
uint8 HandleMovementAndCollForSamusGrapple(void);
int32 Samus_CollDetectChangedPose(int32 amt);
int32 Samus_MoveDown_NoSolidColl(int32 amt);
int32 Samus_MoveRight_NoSolidColl(int32 amt);
int32 WallJumpBlockCollDetect(int32 amt);
void BlockFunc_AC11(void);
void BlockInsideDetection(void);
void BombOrPowerBomb_ExplosionBlockCollHandling(uint16 k);
void GrappleFunc_AF87(void);
void HandleGrappleBeamGfx(void);
void PostGrappleCollisionDetect_X(void);
void PostGrappleCollisionDetect_Y(void);
void Samus_AlignYPosSlope(void);

// Bank 9B
uint16 CheckBannedDraygonGrappleDirs(uint16 a);
uint16 GameState_24_SamusNoHealth_Explosion_2(void);
uint16 GameState_24_SamusNoHealth_Explosion_Helper(void);
uint16 HandleSamusDeathSequence(void);
uint8 CheckIfGrappleIsConnectedToBlock(void);
uint8 ClearCarry_12(void);
uint8 HandleSpecialGrappleBeamAngles(void);
void CancelGrappleBeamIfIncompatiblePose(void);
void CopyPalettesForSamusDeath(uint16 k);
void DrawSamusStartingDeathAnim_(void);
void GameState_24_SamusNoHealth_Explosion_1(void);
void GrappleBeamHandler(void);
void GrappleNext_CrouchAimDownLeft(void);
void GrappleNext_CrouchAimDownRight(void);
void GrappleNext_CrouchAimLeft(void);
void GrappleNext_CrouchAimRight(void);
void GrappleNext_StandAimDownLeft(void);
void GrappleNext_StandAimDownRight(void);
void GrappleNext_StandAimLeft(void);
void GrappleNext_StandAimRight(void);
void GrappleNext_SwingAntiClockwise(void);
void GrappleNext_SwingClockwise(void);
void HandleConnectingGrapple(void);
void HandleConnectingGrapple_StuckInPlace(void);
void HandleConnectingGrapple_Swinging(void);
void HandleGrappleBeamFlare(void);
void HandleSamusDeathSequence_Helper2(void);
void SetProjectileTrailPosition(uint16 k, uint16 j);
void PropelSamusFromGrappleSwing(void);
void QueueTransferOfSamusDeathSequence(uint16 j);
void StartSamusDeathAnimation(void);
void UpdateGrappleBeamTiles(void);
void UpdateGrappleBeamTilesAndIncrFlameCtr(void);
void GrappleBeamFunc_BD95(void);
void GrappleBeamFunc_BEEB(void);
void GrappleBeamFunc_BF1B(void);

// Bank A0
uint16 Abs16(uint16 a);
uint16 CalculateAngleFromXY(uint16 x_r18, uint16 y_r20);
uint16 CalculateAngleOfEnemyXfromEnemyY(uint16 k, uint16 j);
uint16 CalculateAngleOfSamusFromEnemy(uint16 k);
uint16 CalculateAngleOfSamusFromEproj(uint16 k);
uint16 CheckIfEnemyIsOnScreen(void);
uint16 CheckIfEnemyTouchesSamus(uint16 k);
uint16 DetermineDirectionOfSamusFromEnemy(void);
uint16 EnemyFunc_AC67(uint16 k);
PairU16 EnemyFunc_ACA8(Point16U base_pt, Point16U samus_pt);
uint16 CheckIfEnemyIsOverAPixelsOffScreen(uint16 a);
uint16 EnemyWithNormalSpritesIsOffScreen(void);
uint16 GetSamusEnemyDelta_X(uint16 k);
uint16 GetSamusEnemyDelta_Y(uint16 k);
PairU16 GrappleBeam_CollDetect_Enemy(void);
uint16 IsSamusWithinEnemy_X(uint16 k, uint16 a);
uint16 IsSamusWithinEnemy_Y(uint16 k, uint16 a);
uint16 Mult32(uint16 a);

typedef struct Pair_Bool_Amt {
  union {
    bool flag;
    bool max_speed_flag;
  };
  int32 amt;
} Pair_Bool_Amt;

typedef struct CheckSolidEnemyColl_Result {
  uint16 collision;
  int32 amt;
} CheckEnemyColl_Result;

CheckEnemyColl_Result Samus_CheckSolidEnemyColl(int32 amt);
uint16 SignExtend8(uint16 a);
uint16 SineMult8bit(uint16 a, uint16 varE32);
uint16 CosineMult8bit(uint16 a, uint16 varE32);
uint32 CosineMult8bitFull(uint16 a, uint16 varE32);
uint32 SineMult8bitFull(uint16 a, uint16 varE32);

uint16 SpawnEnemy(uint8 db, uint16 k);
uint16 SubtractThenAbs16(uint16 k, uint16 j);
uint16 SuitDamageDivision(uint16 a);
uint8 CompareDistToSamus_X(uint16 k, uint16 a);
uint8 CompareDistToSamus_Y(uint16 k, uint16 a);
uint8 EnemyFunc_BBBF(uint16 k, int32 amt);
uint8 EnemyFunc_BC76(uint16 k, int32 amt);
uint8 EnemyFunc_BF8A(uint16 k, uint16 a, int32 amt);
uint8 AlignEnemyYposToNonsquareSlope(uint16 k);
uint8 Enemy_MoveDown(uint16 k, int32 amt);
uint8 Enemy_MoveRight_IgnoreSlopes(uint16 k, int32 amt);
uint8 Enemy_MoveRight_ProcessSlopes(uint16 k, int32 amt);
uint8 Enemy_MoveRight_SlopesAsWalls(uint16 k, int32 amt);
uint8 IsEnemyLeavingScreen(uint16 k);
void ClearEnemyDataAndProcessEnemySet(void);

typedef struct Point32 {
  uint32 x;
  uint32 y;
} Point32;

Point32 ConvertAngleToXy(uint16 r18, uint16 r20);


void CreateADudShot(void);
void CreateDudShot(void);
void DecrementSamusTimers(void);
void DeleteEnemyAndConnectedEnemies(void);
void DetermineWhichEnemiesToProcess(void);
void DrawOneEnemy(void);
void DrawSamusEnemiesAndProjectiles(void);
void EnemyBombCollHandler(void);
void EnemyBombCollHandler_Multibox(void);
void EnemyCollisionHandler(void);
void EnemyDeathAnimation(uint16 k, uint16 a);
void EnemyFunc_A6B4_UsedBySporeSpawn(void);
void MoveEnemyByAngleAndXYSpeed(uint16 varE20, Point32 pt);
uint32 EnemyFunc_Divide(uint32 a, uint32 b);
void EnemyFunc_B7A1(void);
void EnemyGrappleDeath(void);
void EnemyMain(void);
void EprojCollHandler(void);
void EprojCollHandler_Multibox(void);
void EnemySamusCollHandler(void);
void EnemySamusCollHandler_Multibox(void);
void Enemy_GrappleReact_CancelBeam_A0(void);
void Enemy_GrappleReact_HurtSamus_A0(void);
void Enemy_GrappleReact_KillEnemy_A0(void);
void Enemy_GrappleReact_NoInteract_A0(void);
void Enemy_GrappleReact_SamusLatchesNoInvinc_A0(void);
void Enemy_GrappleReact_SamusLatchesOn_A0(void);
void Enemy_GrappleReact_SamusLatchesParalyze_A0(void);
void Enemy_ItemDrop_BombTorizo(uint16 k);
void Enemy_ItemDrop_Botwoon(uint16 k);
void Enemy_ItemDrop_Crocomire(uint16 k);
void Enemy_ItemDrop_Draygon(uint16 k);
void Enemy_ItemDrop_GoldenTorizo(uint16 k);
void Enemy_ItemDrop_Kraid(uint16 k);
void Enemy_ItemDrop_LowerNorfairSpacePirate(uint16 k);
void Enemy_ItemDrop_Metroid(uint16 k);
void Enemy_ItemDrop_MiniKraid(uint16 k);
void Enemy_ItemDrop_Phantoon(uint16 k);
void Enemy_ItemDrop_Ridley(uint16 k);
void Enemy_ItemDrop_SporeSpawn(uint16 k);
void Enemy_NormalFrozenAI(void);
void Enemy_NormalPowerBombAI_A0(void);
void Enemy_NormalPowerBombAI_SkipDeathAnim_A0(void);
void Enemy_NormalShotAI_A0(void);
void Enemy_NormalShotAI_SkipSomeParts_A0(void);
void Enemy_NormalTouchAI_A0(void);
void Enemy_NormalTouchAI_SkipDeathAnim_A0(void);
void Enemy_SwitchToFrozenAi(void);
void EprojProjCollDet(void);
void EprojSamusCollDetect(void);
void HandleEprojCollWithProj(uint16 k, uint16 j);
void HandleEprojCollWithSamus(uint16 k);
void HandleRoomShaking(void);
void InitializeEnemies(void);
void LoadEnemies(void);
void LoadEnemyGfxIndexes(uint16 k, uint16 j);
void LoadEnemyTileData(void);
void NormalEnemyFrozenAI(void);
void NormalEnemyPowerBombAi(void);
void NormalEnemyPowerBombAiSkipDeathAnim(void);
void NormalEnemyPowerBombAiSkipDeathAnim_CurEnemy(void);
void NormalEnemyShotAi(void);
uint16 NormalEnemyShotAiSkipDeathAnim(void);
void NormalEnemyShotAiSkipDeathAnim_CurEnemy(void);
void NormalEnemyTouchAi(void);
void NormalEnemyTouchAiSkipDeathAnim(void);
void NormalEnemyTouchAiSkipDeathAnim_CurEnemy(void);
void ProcessEnemyInstructions(void);
void ProcessEnemyPowerBombInteraction(void);
void ProcessEnemyTilesets(void);
void ProcessExtendedTilemap(uint8 db, uint16 r22);
void QueueEnemyBG2TilemapTransfers(void);
void RecordEnemySpawnData(uint16 j);
void RinkasDeathAnimation(uint16 a);
void SamusHurtFromGrapple(void);
void SamusLatchesOnWithGrapple(void);
void SamusLatchesOnWithGrappleNoInvinc(void);
void SamusLatchesOnWithGrappleParalyze(void);
void SamusProjectileInteractionHandler(void);
void SetAllEnemiesToShakeFor2Frames(void);
void SpawnEnemyDrops(uint16 a, uint16 k, uint16 varE20);
void SwitchEnemyAiToMainAi(void);
void TransferEnemyTilesToVramAndInit(void);
void WriteEnemyOams(void);

// Bank A2
const uint16 *BouncingGoofball_Instr_88C5(uint16 k, const uint16 *jp);
const uint16 *BouncingGoofball_Instr_88C6(uint16 k, const uint16 *jp);
uint16 BouncingGoofball_SamusCloseX(void);
const uint16 *EnemyInstr_Rio_Instr_1(uint16 k, const uint16 *jp);
uint16 Flies_2(uint16 k);
const uint16 *LavaSeahorse_Instr_E5FB(uint16 k, const uint16 *jp);
const uint16 *LowerNorfairRio_Instr_C6D2(uint16 k, const uint16 *jp);
const uint16 *LowerNorfairRio_Instr_C6DD(uint16 k, const uint16 *jp);
const uint16 *LowerNorfairRio_Instr_C6E8(uint16 k, const uint16 *jp);
const uint16 *MaridiaBeybladeTurtle_Instr_9381(uint16 k, const uint16 *jp);
const uint16 *MaridiaBeybladeTurtle_Instr_9412(uint16 k, const uint16 *jp);
const uint16 *MaridiaBeybladeTurtle_Instr_9447(uint16 k, const uint16 *jp);
const uint16 *MaridiaBeybladeTurtle_Instr_9451(uint16 k, const uint16 *jp);
const uint16 *MaridiaBeybladeTurtle_Instr_946B(uint16 k, const uint16 *jp);
const uint16 *MaridiaBeybladeTurtle_Instr_9485(uint16 k, const uint16 *jp);
const uint16 *MaridiaBeybladeTurtle_Instr_94A1(uint16 k, const uint16 *jp);
const uint16 *MaridiaBeybladeTurtle_Instr_94C7(uint16 k, const uint16 *jp);
const uint16 *MaridiaBeybladeTurtle_Instr_94D1(uint16 k, const uint16 *jp);
const uint16 *MaridiaLargeSnail_Instr_CB6B(uint16 k, const uint16 *jp);
const uint16 *MaridiaLargeSnail_Instr_CCB3(uint16 k, const uint16 *jp);
const uint16 *MaridiaLargeSnail_Instr_CCBE(uint16 k, const uint16 *jp);
const uint16 *MaridiaLargeSnail_Instr_CCC9(uint16 k, const uint16 *jp);
const uint16 *MaridiaSpikeyShell_Instr_A56D(uint16 k, const uint16 *jp);
const uint16 *MaridiaSpikeyShell_Instr_A571(uint16 k, const uint16 *jp);
const uint16 *MiniCrocomire_Instr_897E(uint16 k, const uint16 *jp);
const uint16 *MiniCrocomire_Instr_8990(uint16 k, const uint16 *jp);
const uint16 *MiniCrocomire_Instr_899D(uint16 k, const uint16 *jp);
const uint16 *NorfairLavajumpingEnemy_Instr_BE8E(uint16 k, const uint16 *jp);
const uint16 *NorfairRio_Instr_C1C9(uint16 k, const uint16 *jp);
const uint16 *NorfairRio_Instr_C1D4(uint16 k, const uint16 *jp);
const uint16 *NorfairRio_Instr_C1DF(uint16 k, const uint16 *jp);
const uint16 *NorfairRio_Instr_C1EA(uint16 k, const uint16 *jp);
const uint16 *NorfairRio_Instr_C1F5(uint16 k, const uint16 *jp);
const uint16 *NorfairRio_Instr_C200(uint16 k, const uint16 *jp);
const uint16 *NorfairRio_Instr_C20B(uint16 k, const uint16 *jp);
const uint16 *NorfairRio_Instr_C216(uint16 k, const uint16 *jp);
const uint16 *NorfairRio_Instr_C221(uint16 k, const uint16 *jp);
const uint16 *NorfairRio_Instr_C22C(uint16 k, const uint16 *jp);
const uint16 *NorfairRio_Instr_C237(uint16 k, const uint16 *jp);
uint16 Rinka_2(uint16 k);
uint16 Rinka_Instr_B9A2(uint16 k, uint16 j);
const uint16 *Rinka_Instr_B9B3(uint16 k, const uint16 *jp);
const uint16 *Rinka_Instr_B9BD(uint16 k, const uint16 *jp);
const uint16 *Rinka_Instr_B9C7(uint16 k, const uint16 *jp);
const uint16 *SpikeShootingPlant_Instr_9F2A(uint16 k, const uint16 *jp);
const uint16 *SpikeShootingPlant_Instr_A095(uint16 k, const uint16 *jp);
const uint16 *SpikeShootingPlant_Instr_A0A7(uint16 k, const uint16 *jp);
uint8 Gripper_Func_1(uint16 k);
uint8 Gripper_Func_2(uint16 k);
uint8 MiniCrocomire_Func9(void);
bool Rinka_10(uint16 r18, uint16 r20);
uint8 Rinka_9(uint16 k);
void BouncingGoofball_Func1(uint16 k);
void BouncingGoofball_Func2(void);
void BouncingGoofball_Func3(void);
void BouncingGoofball_Init(void);
void BouncingGoofball_Main(void);
void BouncingGoofball_State0(void);
void BouncingGoofball_State1(void);
void Enemy_GrappleReact_CancelBeam_A2(void);
void Enemy_GrappleReact_KillEnemy_A2(void);
void Enemy_GrappleReact_SamusLatchesOn_A2(void);
void Enemy_NormalFrozenAI_A2(void);
void Enemy_NormalPowerBombAI_A2(void);
void Enemy_NormalShotAI_A2(void);
void Enemy_NormalTouchAI_A2(void);
void Flies_1(uint16 k);
void Flies_3(uint16 k);
void Flies_4(uint16 k);
void Flies_5(uint16 k);
void Flies_6(uint16 k);
void Flies_7(uint16 k);
void Flies_Init(void);
void Flies_Main(void);
void Gripper_Func_3(void);
void Gripper_Func_4(void);
void Gripper_Init(void);
void Gripper_Main(void);
void GunshipBottom_Init(void);
void GunshipTop_1(uint16 k);
void GunshipTop_10(uint16 k);
void GunshipTop_11(uint16 k);
void GunshipTop_12(uint16 k);
void GunshipTop_13(uint16 k);
void GunshipTop_14(uint16 k);
void GunshipTop_15(uint16 k);
void GunshipTop_16(uint16 k);
void GunshipTop_17(uint16 k);
void GunshipTop_18(uint16 k);
void GunshipTop_19(uint16 k);
void GunshipTop_2(uint16 k);
void GunshipTop_20(uint16 k);
void GunshipTop_21(uint16 k);
void GunshipTop_3(uint16 k);
void GunshipTop_4(uint16 k);
void GunshipTop_5(uint16 k);
void GunshipTop_6(uint16 k);
void GunshipTop_7(uint16 k);
void GunshipTop_8(uint16 k);
void GunshipTop_9(uint16 k);
void GunshipTop_Init(void);
void GunshipTop_Main(void);
void HirisingSlowfalling_Func_2(uint16 k, uint16 r18);
void HirisingSlowfalling_Func_3(uint16 a);
void HirisingSlowfalling_Func_4(void);
void HirisingSlowfalling_Func_5(void);
void HirisingSlowfalling_Func_6(void);
void HirisingSlowfalling_Func_7(void);
void HirisingSlowfalling_Init(void);
void HirisingSlowfalling_Main(void);
void HorizontalShootableShutter_Func_1(uint16 k);
void HorizontalShootableShutter_Func_10(uint16 k);
void HorizontalShootableShutter_Func_11(uint16 k);
void HorizontalShootableShutter_Func_12(void);
void HorizontalShootableShutter_Func_13(void);
void HorizontalShootableShutter_Func_14(void);
void HorizontalShootableShutter_Func_2(void);
void HorizontalShootableShutter_Func_3(void);
void HorizontalShootableShutter_Func_4(void);
void HorizontalShootableShutter_Func_5(void);
void HorizontalShootableShutter_Func_6(void);
void HorizontalShootableShutter_Func_7(uint16 k);
void HorizontalShootableShutter_Func_8(void);
void HorizontalShootableShutter_Func_9(void);
void HorizontalShootableShutter_Init(void);
void HorizontalShootableShutter_Main(void);
void HorizontalShootableShutter_Powerbomb(void);
void HorizontalShootableShutter_Shot(void);
void HorizontalShootableShutter_Touch(void);
void JetPowerRipper_Init(void);
void JetPowerRipper_Main(void);
void JetPowerRipper_Shot(void);
void LavaSeahorse_E7DA(void);
void LavaSeahorse_Func_1(uint16 k);
void LavaSeahorse_Func_2(uint16 k);
void LavaSeahorse_Func_3(uint16 k);
void LavaSeahorse_Func_4(uint16 k);
void LavaSeahorse_Func_5(uint16 k);
void LavaSeahorse_Func_6(void);
void LavaSeahorse_Func_7(void);
void LavaSeahorse_Init(void);
void LavaSeahorse_Main(void);
void LavaSeahorse_Powerbomb(void);
void LavaSeahorse_Shot(void);
void LavaSeahorse_Touch(void);
void LavaquakeRocks_1(void);
void LavaquakeRocks_2(void);
void LavaquakeRocks_3(void);
void LavaquakeRocks_Init(void);
void LavaquakeRocks_Main(void);
void LowerNorfairRio_Func_1(uint16 k);
void LowerNorfairRio_Func_2(uint16 k);
void LowerNorfairRio_Func_3(uint16 k);
void LowerNorfairRio_Func_4(uint16 k);
void LowerNorfairRio_Func_5(uint16 k);
void LowerNorfairRio_Func_6(uint16 k);
void LowerNorfairRio_Func_7(uint16 a);
void LowerNorfairRio_Init(void);
void LowerNorfairRio_Main(void);
void MaridiaBeybladeTurtle_Func1(uint16 k);
void MaridiaBeybladeTurtle_Func10(uint16 k);
void MaridiaBeybladeTurtle_Func11(uint16 k);
void MaridiaBeybladeTurtle_Func2(uint16 k);
void MaridiaBeybladeTurtle_Func21(void);
void MaridiaBeybladeTurtle_Func3(uint16 k);
void MaridiaBeybladeTurtle_Func4(void);
void MaridiaBeybladeTurtle_Func5(uint16 k);
void MaridiaBeybladeTurtle_Func6(uint16 k);
void MaridiaBeybladeTurtle_Func7(uint16 k);
void MaridiaBeybladeTurtle_Func8(uint16 k);
void MaridiaBeybladeTurtle_Func9(uint16 k);
void MaridiaBeybladeTurtle_Init(void);
void MaridiaBeybladeTurtle_Main(void);
void MaridiaBeybladeTurtle_Touch(void);
void MaridiaLargeSnail_Func_1(uint16 k);
void MaridiaLargeSnail_Func_10(uint16 k);
void MaridiaLargeSnail_Func_11(void);
void MaridiaLargeSnail_Func_12(void);
void MaridiaLargeSnail_Func_2(uint16 k);
void MaridiaLargeSnail_Func_3(uint16 k);
void MaridiaLargeSnail_Func_4(void);
void MaridiaLargeSnail_Func_5(void);
void MaridiaLargeSnail_Func_6(void);
void MaridiaLargeSnail_Func_7(uint16 k);
void MaridiaLargeSnail_Func_8(uint16 k);
void MaridiaLargeSnail_Func_9(void);
void MaridiaLargeSnail_Init(void);
void MaridiaLargeSnail_Main(void);
void MaridiaLargeSnail_Shot(void);
void MaridiaLargeSnail_Touch(void);
void MaridiaSpikeyShell_1(void);
void MaridiaSpikeyShell_2(void);
void MaridiaSpikeyShell_3(void);
void MaridiaSpikeyShell_4(void);
void MaridiaSpikeyShell_5(void);
void MaridiaSpikeyShell_6(void);
void MaridiaSpikeyShell_7(void);
void MaridiaSpikeyShell_8(uint16 k);
void MaridiaSpikeyShell_Init(void);
void MaridiaSpikeyShell_Main(void);
void MaridiaSpikeyShell_Shot(void);
void MiniCrocomire_Func1(void);
void MiniCrocomire_Func2(void);
void MiniCrocomire_Func3(void);
void MiniCrocomire_Func4(void);
void MiniCrocomire_Func7(int32 amt);
void MiniCrocomire_Func8(void);
void MiniCrocomire_Init(void);
void MiniCrocomire_Main(void);
void MiniCrocomire_PreInstr5(uint16 k);
void MiniCrocomire_PreInstr6(uint16 k);
void MiniMaridiaBeybladeTurtle_Func1(uint16 k);
void MiniMaridiaBeybladeTurtle_Func2(uint16 k);
void MiniMaridiaBeybladeTurtle_Func3(uint16 k);
void MiniMaridiaBeybladeTurtle_Func4(uint16 k);
void MiniMaridiaBeybladeTurtle_Func5(uint16 k);
void MiniMaridiaBeybladeTurtle_Func6(uint16 k);
void MiniMaridiaBeybladeTurtle_Func7(void);
void MiniMaridiaBeybladeTurtle_Init(void);
void MiniMaridiaBeybladeTurtle_Main(void);
void MiniMaridiaBeybladeTurtle_Shot(void);
void MiniMaridiaBeybladeTurtle_Touch(void);
void NorfairErraticFireball_Init(void);
void NorfairErraticFireball_Main(void);
void NorfairLavajumpingEnemy_Func_1(uint16 k);
void NorfairLavajumpingEnemy_Func_2(uint16 k);
void NorfairLavajumpingEnemy_Func_3(uint16 k);
void NorfairLavajumpingEnemy_Func_4(uint16 k);
void NorfairLavajumpingEnemy_Func_5(uint16 k);
void NorfairLavajumpingEnemy_Func_6(uint16 a);
void NorfairLavajumpingEnemy_Init(void);
void NorfairLavajumpingEnemy_Main(void);
void NorfairRio_Func_1(uint16 k);
void NorfairRio_Func_2(uint16 k);
void NorfairRio_Func_3(uint16 k);
void NorfairRio_Func_4(uint16 k);
void NorfairRio_Func_5(uint16 k);
void NorfairRio_Func_6(uint16 k);
void NorfairRio_Func_7(uint16 a);
void NorfairRio_Init(void);
void NorfairRio_Main(void);
void Rinka_1(uint16 k);
void Rinka_3(uint16 k);
void Rinka_4(uint16 k);
void Rinka_5(uint16 k);
void Rinka_6(uint16 k);
void Rinka_7(uint16 k);
void Rinka_8(uint16 k);
void Rinka_B85B(uint16 k);
void Rinka_B865(uint16 k);
void Rinka_B960(uint16 k);
void Rinka_Frozen(uint16 k);
void Rinka_Init(void);
void Rinka_Init2(uint16 k);
void Rinka_Init3(uint16 k);
void Rinka_Main(void);
void Rinka_Powerbomb(uint16 k);
void Rinka_Shot(void);
void Rinka_Touch(void);
void Rio_1(uint16 k);
void Rio_2(uint16 k);
void Rio_3(uint16 k);
void Rio_4(uint16 k);
void Rio_5(uint16 k);
void Rio_6(uint16 a);
void Rio_Init(void);
void Rio_Main(void);
void Ripper_Func_1(void);
void Ripper_Init(void);
void Ripper_Main(void);
void RisingFallingPlatform_Func_1(uint16 k);
void RisingFallingPlatform_Func_10(void);
void RisingFallingPlatform_Func_11(void);
void RisingFallingPlatform_Func_12(void);
void RisingFallingPlatform_Func_13(void);
void RisingFallingPlatform_Func_2(void);
void RisingFallingPlatform_Func_3(void);
void RisingFallingPlatform_Func_4(void);
void RisingFallingPlatform_Func_5(void);
void RisingFallingPlatform_Func_6(void);
void RisingFallingPlatform_Func_7(uint16 k);
void RisingFallingPlatform_Func_8(void);
void RisingFallingPlatform_Func_9(void);
void RisingFallingPlatform_Init(void);
void RisingFallingPlatform_Main(void);
void RisingFallingPlatform_Powerbomb(void);
void RisingFallingPlatform_Shot(void);
void RisingFallingPlatform_Touch(void);
void ShootableShutter_Init(void);
void ShootableShutter_Shot(void);
void SpikeShootingPlant_2(uint16 k);
void SpikeShootingPlant_3(uint16 k);
void SpikeShootingPlant_4(void);
void SpikeShootingPlant_5(void);
void SpikeShootingPlant_6(void);
void SpikeShootingPlant_7(void);
void SpikeShootingPlant_8(void);
void SpikeShootingPlant_Init(void);
void SpikeShootingPlant_Main(void);
void ThinHoppingBlobs_Func1(uint16 k);
void ThinHoppingBlobs_Func10(void);
void ThinHoppingBlobs_Func11(void);
void ThinHoppingBlobs_Func12(void);
void ThinHoppingBlobs_Func13(void);
void ThinHoppingBlobs_Func14(void);
void ThinHoppingBlobs_Func15(void);
void ThinHoppingBlobs_Func16(void);
void ThinHoppingBlobs_Func3(void);
uint16 ThinHoppingBlobs_Func4(void);
void ThinHoppingBlobs_Func5(void);
void ThinHoppingBlobs_Func6(uint16 k);
void ThinHoppingBlobs_Func7(void);
void ThinHoppingBlobs_Func8(void);
void ThinHoppingBlobs_Func9(void);
void ThinHoppingBlobs_Init(void);
void ThinHoppingBlobs_Main(void);
void TimedShutter_Func_1(uint16 k);
void TimedShutter_Func_10(uint16 k);
void TimedShutter_Func_11(void);
void TimedShutter_Func_12(void);
void TimedShutter_Func_13(void);
void TimedShutter_Func_14(void);
void TimedShutter_Func_15(void);
void TimedShutter_Func_2(uint16 k);
void TimedShutter_Func_3(uint16 k);
void TimedShutter_Func_4(uint16 k);
void TimedShutter_Func_5(uint16 k);
void TimedShutter_Func_6(void);
void TimedShutter_Func_7(void);
void TimedShutter_Func_8(void);
void TimedShutter_Func_9(void);
void TimedShutter_Init(void);
void TimedShutter_Main(void);
void TwinHoppingBlobs_Func2(void);
void sub_A29A6C(uint16 a);

// Bank A3
uint16 Bang_Func_4(uint16 a);
const uint16 *Bang_Instr_1(uint16 k, const uint16 *jp);
const uint16 *Bang_Instr_2(uint16 k, const uint16 *jp);
const uint16 *MaridiaFish_Instr_1(uint16 k, const uint16 *jp);
const uint16 *MaridiaFish_Instr_2(uint16 k, const uint16 *jp);
const uint16 *MaridiaFish_Instr_3(uint16 k, const uint16 *jp);
const uint16 *MaridiaRefillCandy_Instr_1(uint16 k, const uint16 *jp);
const uint16 *MaridiaRefillCandy_Instr_2(uint16 k, const uint16 *jp);
const uint16 *MaridiaRefillCandy_Instr_3(uint16 k, const uint16 *jp);
const uint16 *MaridiaSnail_Instr_1(uint16 k, const uint16 *jp);
const uint16 *MaridiaSnail_Instr_2(uint16 k, const uint16 *jp);
const uint16 *MaridiaSnail_Instr_3(uint16 k, const uint16 *jp);
const uint16 *MaridiaSnail_Instr_4(uint16 k, const uint16 *jp);
const uint16 *MaridiaSnail_Instr_5(uint16 k, const uint16 *jp);
const uint16 *Metalee_Instr_1(uint16 k, const uint16 *jp);
const uint16 *Metroid_Instr_1(uint16 k, const uint16 *jp);
const uint16 *Metroid_Instr_2(uint16 k, const uint16 *jp);
const uint16 *PlatformThatFallsWithSamus_Instr_1(uint16 k, const uint16 *jp);
const uint16 *PlatformThatFallsWithSamus_Instr_2(uint16 k, const uint16 *jp);
const uint16 *PlatformThatFallsWithSamus_Instr_3(uint16 k, const uint16 *jp);
const uint16 *PlatformThatFallsWithSamus_Instr_4(uint16 k, const uint16 *jp);
const uint16 *Reflec_Instr_1(uint16 k, const uint16 *jp);
const uint16 *Sidehopper_Func_1(uint16 k, const uint16 *jp);
uint16 Sidehopper_Func_2(uint16 r22, uint16 r24);
const uint16 *Sidehopper_Instr_1(uint16 k, const uint16 *jp);
const uint16 *Skree_Instr_1(uint16 k, const uint16 *jp);
const uint16 *Waver_Instr_1(uint16 k, const uint16 *jp);
const uint16 *WreckedShipOrangeZoomer_Func_1(uint16 k, const uint16 *jp);
const uint16 *Zoomer_Instr_SetPreinstr(uint16 k, const uint16 *jp);
uint8 MaridiaSnail_Func_17(uint16 k);
uint8 MaridiaSnail_Func_18(uint16 k);
uint8 MaridiaSnail_Func_19(uint16 k);
uint8 MaridiaSnail_Func_20(uint16 k);
uint8 MaridiaSnail_Func_21(uint16 k);
void Bang_Func_1(void);
void Bang_Func_10(uint16 k);
void Bang_Func_11(uint16 k);
void Bang_Func_12(void);
void Bang_Func_13(void);
void Bang_Func_14(void);
void Bang_Func_15(void);
void Bang_Func_18(void);
void Bang_Func_2(void);
void Bang_Func_3(void);
void Bang_Func_5(void);
void Bang_Func_6(uint16 k);
void Bang_Func_7(uint16 k);
void Bang_Func_8(uint16 k);
void Bang_Func_9(void);
void Bang_Init(void);
void Bang_Main(void);
void Bang_Shot(void);
void BigEyeBugs_Init(void);
void Crab_Func_1(void);
void Crab_Init(void);
void Elevator_Main(void);
void Elevator_Func_EnteringRoom(void);
void Elevator_Func_Inactive(void);
void Elevator_Func_LeavingRoom(void);
void Elevator_Func_RoomTransition(void);
void PlaceSamusOnElevator(void);
void Elevator_Init(void);
void Enemy_GrappleReact_CancelBeam_A3(void);
void Enemy_GrappleReact_KillEnemy_A3(void);
void Enemy_GrappleReact_NoInteract_A3(void);
void Enemy_NormalFrozenAI_A3(void);
void Enemy_NormalPowerBombAI_A3(void);
void Enemy_NormalShotAI_A3(void);
void Enemy_NormalShotAI_SkipSomeParts_A3(void);
void Enemy_NormalTouchAI_A3(void);
void FastMovingSlowSinkingPlatform_Init(void);
void FastMovingSlowSinkingPlatform_Shot(void);
int32 FireZoomer_E8A5(uint16 k);
void FireZoomer_Func_1(uint16 k);
void FireZoomer_Func_2(uint16 k);
void FireZoomer_Func_3(uint16 k);
void FireZoomer_Init(void);
void Fireflea_Common(void);
void Fireflea_Func_1(uint16 k);
void Fireflea_Func_2(uint16 k);
void Fireflea_Func_3(uint16 k);
void Fireflea_Func_4(uint16 k);
void Fireflea_Func_5(uint16 k);
void Fireflea_Func_6(uint16 k);
void Fireflea_Init(void);
void Fireflea_Main(void);
void Fireflea_Powerbomb(void);
void Fireflea_Shot(void);
void Fireflea_Touch(uint16 k);
void MaridiaFish_Init(void);
void MaridiaFish_Main(void);
void MaridiaRefillCandy_Func_1(void);
void MaridiaRefillCandy_Func_2(uint16 k);
void MaridiaRefillCandy_Func_3(uint16 k);
void MaridiaRefillCandy_Func_4(void);
void MaridiaRefillCandy_Func_5(void);
void MaridiaRefillCandy_Func_6(void);
void MaridiaRefillCandy_Init(void);
void MaridiaRefillCandy_Main(void);
void MaridiaSnail_CFB7(uint16 k);
void MaridiaSnail_CFBD(uint16 k);
void MaridiaSnail_CFCE(uint16 k);
void MaridiaSnail_CFD4(uint16 k);
void MaridiaSnail_CFE5(uint16 k);
void MaridiaSnail_CFEB(uint16 k);
void MaridiaSnail_CFFC(uint16 k);
void MaridiaSnail_D002(uint16 k, const uint8 *j);
void MaridiaSnail_D07E(uint16 k, const uint8 *j);
void MaridiaSnail_Func_1(uint16 k);
void MaridiaSnail_Func_10(uint16 k, const uint8 *j);
void MaridiaSnail_Func_11(uint16 k, const uint8 *j);
void MaridiaSnail_Func_12(uint16 k, uint16 a);
void MaridiaSnail_Func_13(uint16 k, uint16 a);
void MaridiaSnail_Func_14(uint16 k);
void MaridiaSnail_Func_15(uint16 k);
void MaridiaSnail_Func_16(uint16 k);
void MaridiaSnail_Func_2(uint16 k, uint16 j);
void MaridiaSnail_Func_22(uint16 k);
void MaridiaSnail_Func_23(uint16 k);
void MaridiaSnail_Func_3(uint16 k);
void MaridiaSnail_Func_4(uint16 k);
void MaridiaSnail_Func_5(uint16 k);
void MaridiaSnail_Func_6(uint16 k);
void MaridiaSnail_Func_7(uint16 k);
void MaridiaSnail_Func_9(uint16 k);
void MaridiaSnail_Init(void);
void MaridiaSnail_Main(void);
void MaridiaSnail_Shot(void);
void MaridiaSnail_Touch(void);
void Metalee_Func_1(void);
void Metalee_Func_2(uint16 k);
void Metalee_Func_3(uint16 k);
void Metalee_Func_4(void);
void Metalee_Func_5(void);
void Metalee_Func_6(void);
void Metalee_Init(void);
void Metalee_Main(void);
void Metalee_Shot(void);
void Metroid_Frozen(void);
void Metroid_Func_1(uint16 varE32);
void Metroid_Func_2(uint16 varE32);
void Metroid_Func_3(uint16 varE32);
void Metroid_Func_4(uint16 varE32);
void Metroid_Func_5(uint16 k);
void Metroid_Hurt(void);
void Metroid_Init(void);
void Metroid_Main(void);
void Metroid_Powerbomb(uint16 k);
void Metroid_Shot(void);
void Metroid_Touch(void);
void Mochtroid_Func_NotTouchingSamus(void);
void Mochtroid_Func_2_UNUSED(void);
void Mochtroid_Func_TouchingSamus(void);
void SetMochtroidInstruction(uint16 k, uint16 a);
void Mochtroid_Init(void);
void Mochtroid_Main(void);
void Mochtroid_Shot(void);
void Mochtroid_Touch(void);
void NorfairSlowFireball_Func_1(void);
void NorfairSlowFireball_Init(void);
void PlatformThatFallsWithSamus_Func_1(void);
void PlatformThatFallsWithSamus_Func_10(void);
void PlatformThatFallsWithSamus_Func_2(void);
void PlatformThatFallsWithSamus_Func_3(void);
void PlatformThatFallsWithSamus_Func_4(void);
void PlatformThatFallsWithSamus_Func_5(void);
void PlatformThatFallsWithSamus_Func_6(void);
void PlatformThatFallsWithSamus_Func_7(void);
void PlatformThatFallsWithSamus_Func_8(void);
void PlatformThatFallsWithSamus_Func_9(void);
void PlatformThatFallsWithSamus_Init(void);
void PlatformThatFallsWithSamus_Main(void);
void PlatformThatFalls_Init(uint16 k, uint16 j);
void Reflec_Func_1(void);
void Reflec_Init(void);
void Reflec_Shot(void);
void Roach_Func_1(void);
void Roach_Func_10(void);
void Roach_Func_11(void);
void Roach_Func_12(void);
void Roach_Func_13(void);
void Roach_Func_14(void);
void Roach_Func_15(void);
void Roach_Func_16(void);
void Roach_Func_17(uint16 k);
void Roach_Func_18(uint16 k);
void Roach_Func_19(void);
void Roach_Func_2(uint16 k);
void Roach_Func_20(void);
void Roach_Func_21(void);
void Roach_Func_22(void);
void Roach_Func_23(void);
void Roach_Func_24(void);
void Roach_Func_25(void);
void Roach_Func_26(void);
void Roach_Func_27(void);
void Roach_Func_28(void);
void Roach_Func_29(uint16 k);
void Roach_Func_3(uint16 k);
void Roach_Func_30(uint16 k);
void Roach_Func_31(uint16 k);
void Roach_Func_32(uint16 k);
void Roach_Func_33(uint16 k);
void Roach_Func_4(uint16 k);
void Roach_Func_5(uint16 k);
void Roach_Func_6(uint16 k);
void Roach_Func_7(uint16 k);
void Roach_Func_8(uint16 k);
void Roach_Func_9(void);
void Roach_Init(void);
void Roach_Main(void);
void Sidehopper_Func_19(void);
void Sidehopper_Func_20(void);
void Sidehopper_Func_21(void);
void Sidehopper_Func_22(void);
void Sidehopper_Func_3(void);
void Sidehopper_Init(void);
void Sidehopper_Main(void);
void Skree_Func_1(void);
void Skree_Func_2(uint16 k);
void Skree_Func_3(void);
void Skree_Func_4(void);
void Skree_Func_5(void);
void Skree_Init(void);
void Skree_Main(void);
void Skree_Shot(void);
void Slug_Func_1(void);
void Slug_Init(void);
void StoneZoomer_E67A(uint16 k);
void StoneZoomer_Init(void);
void StoneZoomer_Main(void);
void Waver_Func_1(void);
void Waver_Init(void);
void Waver_Main(void);
void WreckedShipOrangeZoomer_Func_2(uint16 k);
void WreckedShipOrangeZoomer_Init(void);
void WreckedShipOrangeZoomer_Main(void);
void sub_A3E168(uint16 k);

// Bank A4
const uint16 *Crocomire_Func_10(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Func_11(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Func_12(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Func_13(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Func_14(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Func_15(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Func_16(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Func_17(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Func_18(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Func_19(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Func_2(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Func_20(uint16 k);
const uint16 *Crocomire_Func_21(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Func_22(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Func_23(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Func_24(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Func_25(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Func_26(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Func_3(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Func_4(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Func_5(uint16 k, const uint16 *jp);
uint16 Crocomire_Func_67(void);
const uint16 *Crocomire_Func_7(uint16 k, const uint16 *j);
const uint16 *Crocomire_Func_8(uint16 k, const uint16 *j);
const uint16 *Crocomire_Func_87(const uint16 *jp, uint16 a);
const uint16 *Crocomire_Func_9(uint16 k, const uint16 *j);
const uint16 *Crocomire_Instr_1(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Instr_10(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Instr_11(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Instr_12(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Instr_13(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Instr_14(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Instr_15(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Instr_16(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Instr_17(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Instr_18(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Instr_19(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Instr_2(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Instr_20(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Instr_21(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Instr_22(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Instr_23(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Instr_24(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Instr_25(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Instr_26(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Instr_27(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Instr_3(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Instr_4(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Instr_5(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Instr_6(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Instr_7(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Instr_8(uint16 k, const uint16 *jp);
const uint16 *Crocomire_Instr_9(uint16 k, const uint16 *jp);
void CrocomireTongue_Init(void);
void CrocomireTongue_Main(void);
void Crocomire_8BA4(void);
void Crocomire_8D47(void);
void Crocomire_8EE5(void);
void Crocomire_929E(void);
void Crocomire_92CE(void);
void Crocomire_92D8(void);
void Crocomire_93BE(uint16 k);
void Crocomire_9506(void);
void Crocomire_950F(void);
void Crocomire_9B65(void);
void Crocomire_9B86(void);
void Crocomire_9BB3(void);
void Crocomire_Func_1(void);
void Crocomire_Func_27(uint16 k);
void Crocomire_Func_28(void);
void Crocomire_Func_29(void);
void Crocomire_Func_30(void);
void Crocomire_Func_31(void);
void Crocomire_Func_35(void);
void Crocomire_Func_36(void);
void Crocomire_Func_37(void);
void Crocomire_Func_43(void);
void Crocomire_Func_49(void);
void Crocomire_Func_50(void);
void Crocomire_Func_51(void);
void Crocomire_Func_52(void);
void Crocomire_Func_53(void);
void Crocomire_Func_54(void);
void Crocomire_Func_55(void);
void Crocomire_Func_56(void);
void Crocomire_Func_57(void);
void Crocomire_Func_58(void);
void Crocomire_Func_59(void);
void Crocomire_Func_60(void);
void Crocomire_Func_61(void);
void Crocomire_Func_62(void);
void Crocomire_Func_63(void);
void Crocomire_Func_64(void);
void Crocomire_Func_65(void);
void Crocomire_Func_66(void);
void Crocomire_Func_68(void);
void Crocomire_Func_69(void);
void Crocomire_Func_70(void);
void Crocomire_Func_71(void);
void Crocomire_Func_72(void);
void Crocomire_Func_73(void);
void Crocomire_Func_88(void);
void Crocomire_Func_89(void);
void Crocomire_Func_90(void);
void Crocomire_Func_91(void);
void Crocomire_Func_92(void);
void Crocomire_Func_93(void);
void Crocomire_Func_94(void);
void Crocomire_Func_95(void);
void Crocomire_Hurt(void);
void Crocomire_Init(void);
void Crocomire_Main(void);
void Crocomire_Powerbomb(void);
void Enemy_GrappleReact_SamusLatchesOn_A4(void);
void Enemy_NormalFrozenAI_A4(void);
void Enemy_NormalShotAI_A4(void);
void Enemy_NormalTouchAI_A4(void);

// Bank A5
const uint16 *Draygon_Instr_1(uint16 k, const uint16 *jp);
const uint16 *Draygon_Instr_10(uint16 k, const uint16 *jp);
const uint16 *Draygon_Instr_11(uint16 k, const uint16 *jp);
const uint16 *Draygon_Instr_12(uint16 k, const uint16 *jp);
const uint16 *Draygon_Instr_13(uint16 k, const uint16 *jp);
const uint16 *Draygon_Instr_14(uint16 k, const uint16 *jp);
const uint16 *Draygon_Instr_15(uint16 k, const uint16 *jp);
const uint16 *Draygon_Instr_16(uint16 k, const uint16 *jp);
const uint16 *Draygon_Instr_17(uint16 k, const uint16 *jp);
const uint16 *Draygon_Instr_18(uint16 k, const uint16 *jp);
const uint16 *SporeSpawn_Instr_LoadDeathSequenceTargetPaletteWithOffset(uint16 k, const uint16 *jp);
const uint16 *Draygon_Instr_2(uint16 k, const uint16 *jp);
const uint16 *SporeSpawn_Instr_SetFunction(uint16 k, const uint16 *jp);
const uint16 *SporeSpawn_Instr_SetMaxXRadius_AngleDelta(uint16 k, const uint16 *jp);
const uint16 *SporeSpawn_Instr_SetGenerationFlag(uint16 k, const uint16 *jp);
const uint16 *SporeSpawn_Instr_QueueSfx2_Max6(uint16 k, const uint16 *jp);
const uint16 *SporeSpawn_Instr_ClearDamagedFlag(uint16 k, const uint16 *jp);
const uint16 *SporeSpawn_Instr_IncreaseMaxXRadius(uint16 k, const uint16 *jp);
const uint16 *SporeSpawn_Instr_SpawnDyingExplosion(uint16 k, const uint16 *jp);
const uint16 *SporeSpawn_Instr_Harden(uint16 k, const uint16 *jp);
const uint16 *SporeSpawn_Instr_SpawnHardeningDustCloud(uint16 k, const uint16 *jp);
const uint16 *SporeSpawn_Instr_LoadDeathSequencePaletteWithOffset(uint16 k, const uint16 *jp);
const uint16 *Draygon_Instr_3(uint16 k, const uint16 *jp);
const uint16 *SporeSpawn_Instr_SpawnItemDrops(uint16 k, const uint16 *jp);
const uint16 *Draygon_Instr_4(uint16 k, const uint16 *jp);
const uint16 *Draygon_Instr_5(uint16 k, const uint16 *jp);
const uint16 *Draygon_Instr_6(uint16 k, const uint16 *jp);
const uint16 *Draygon_Instr_7(uint16 k, const uint16 *jp);
const uint16 *Draygon_Instr_8(uint16 k, const uint16 *jp);
const uint16 *Draygon_Instr_9(uint16 k, const uint16 *jp);
void Draygon_Func_1(void);
void Draygon_Func_10(void);
void Draygon_Func_11(void);
void Draygon_Func_12(void);
void Draygon_Func_13(void);
void Draygon_Func_14(void);
void Draygon_Func_15(void);
void Draygon_Func_16(void);
void Draygon_Func_17(uint16 k);
void Draygon_Func_18(void);
void Draygon_Func_19(void);
void Draygon_Func_2(void);
void Draygon_Func_20(void);
void Draygon_Func_21(uint16 k);
void Draygon_Func_22(void);
void Draygon_Func_23(void);
void Draygon_Func_24(uint16 k);
void Draygon_Func_25(uint16 k);
void Draygon_Func_26(uint16 k);
void Draygon_Func_27(uint16 k);
void Draygon_Func_28(uint16 k);
void Draygon_Func_29(void);
void Draygon_Func_3(void);
void Draygon_Func_30(void);
void Draygon_Func_31(void);
void Draygon_Func_32(void);
void Draygon_Func_33(void);
void Draygon_Func_34(void);
void Draygon_Func_35(void);
void Draygon_Func_36(void);
void Draygon_Func_37(void);
void Draygon_Func_38(void);
void Draygon_Func_39(void);
void Draygon_Func_4(void);
void Draygon_Func_40(uint16 k);
void Draygon_Func_41(void);
void Draygon_Func_42(uint16 varE24);
void Draygon_Func_43(void);
void Draygon_Func_44(void);
void Draygon_Func_45(void);
void Draygon_Func_46(void);
void Draygon_Func_48(uint16 k);
void Draygon_Func_49(uint16 k);
void Draygon_Func_5(void);
void SporeSpawn_Instr_SetMaxXRadius_AngleDelta_Angle_Unused(uint16 j);
void SporeSpawn_Instr_SetMaxXRadius_Unused(uint16 j);
void SporeSpawn_Instr_SetAngleDelta_Unused(uint16 j);
void Draygon_Func_6(void);
void Draygon_Func_7(void);
void Draygon_Func_8(void);
void Draygon_Func_9(void);
void Draygon_Hurt(void);
void Draygon_Init(void);
void Draygon_Main(void);
void Draygon_Powerbomb(void);
void Draygon_Shot(void);
void Draygon_Touch(void);
void DraygonsArms_Init(void);
void DraygonsEye_Init(void);
void DraygonsEye_Main(void);
void DraygonsTail_Init(void);
void Enemy_GrappleReact_CancelBeam_A5(void);
void Enemy_GrappleReact_NoInteract_A5(void);
void Enemy_NormalFrozenAI_A5(void);
void Enemy_NormalShotAI_A5(void);
void Enemy_NormalTouchAI_A5(void);
void SporeSpawn_Func_Descent(void);
void SporeSpawn_Func_Moving(uint16 k);
void SporeSpawn_Func_SetUpDeath(void);
void SporeSpawn_Func_Dying(void);
void SporeSpawn_UpdateStalkSegmentPositions(void);
void SporeSpawn_Reaction(void);
void SporeSpawn_LoadHealthBasedPalette(uint16 a);
void SporeSpawn_Init(void);
void SporeSpawn_Main(void);
void SporeSpawn_Shot(void);
void SporeSpawn_Touch(void);
void sub_A5960D(void);
void SporeSpawn_SpawnCeilingSmoke(void);

// Bank A6
uint16 BabyMetroid_Instr_1(uint16 k);
uint16 BabyMetroid_Instr_2(uint16 k);
uint16 BabyMetroid_Instr_3(uint16 k);
uint16 BabyMetroid_Goto(uint16 k);
const uint16 *CeresDoor_Instr_1(uint16 k, const uint16 *jp);
const uint16 *CeresDoor_Instr_2(uint16 k, const uint16 *jp);
const uint16 *CeresDoor_Instr_3(uint16 k, const uint16 *jp);
const uint16 *CeresDoor_Instr_4(uint16 k, const uint16 *jp);
const uint16 *CeresDoor_Instr_5(uint16 k, const uint16 *jp);
const uint16 *CeresDoor_Instr_6(uint16 k, const uint16 *jp);
const uint16 *CeresDoor_Instr_7(uint16 k, const uint16 *jp);
const uint16 *CeresDoor_Instr_8(uint16 k, const uint16 *jp);
int16 CeresRidley_AC30(uint16 a, int16 r20);
const uint16 *CeresSteam_Instr_1(uint16 k, const uint16 *jp);
const uint16 *CeresSteam_Instr_2(uint16 k, const uint16 *jp);
const uint16 *CeresSteam_Instr_3(uint16 k, const uint16 *jp);
const uint16 *CeresSteam_Instr_4(uint16 k, const uint16 *jp);
const uint16 *CeresSteam_Instr_5(uint16 k, const uint16 *jp);
const uint16 *FakeKraid_Instr_1(uint16 k, const uint16 *jp);
const uint16 *FakeKraid_Instr_2(uint16 k, const uint16 *jp);
const uint16 *FakeKraid_Instr_3(uint16 k, const uint16 *jp);
const uint16 *FakeKraid_Instr_4(uint16 k, const uint16 *jp);
const uint16 *FakeKraid_Instr_5(uint16 k, const uint16 *jp);
const uint16 *FireGeyser_Instr_1(uint16 k, const uint16 *jp);
const uint16 *FireGeyser_Instr_10(uint16 k, const uint16 *jp);
const uint16 *FireGeyser_Instr_11(uint16 k, const uint16 *jp);
const uint16 *FireGeyser_Instr_12(uint16 k, const uint16 *jp);
const uint16 *FireGeyser_Instr_13(uint16 k, const uint16 *jp);
const uint16 *FireGeyser_Instr_14(uint16 k, const uint16 *jp);
const uint16 *FireGeyser_Instr_15(uint16 k, const uint16 *jp);
const uint16 *FireGeyser_Instr_16(uint16 k, const uint16 *jp);
const uint16 *FireGeyser_Instr_17(uint16 k, const uint16 *jp);
const uint16 *FireGeyser_Instr_18(uint16 k, const uint16 *jp);
const uint16 *FireGeyser_Instr_19(uint16 k, const uint16 *jp);
const uint16 *FireGeyser_Instr_2(uint16 k, const uint16 *jp);
const uint16 *FireGeyser_Instr_20(uint16 k, const uint16 *jp);
const uint16 *FireGeyser_Instr_21(uint16 k, const uint16 *jp);
const uint16 *FireGeyser_Instr_22(uint16 k, const uint16 *jp);
const uint16 *FireGeyser_Instr_23(uint16 k, const uint16 *jp);
const uint16 *FireGeyser_Instr_24(uint16 k, const uint16 *jp);
const uint16 *FireGeyser_Instr_3(uint16 k, const uint16 *jp);
const uint16 *FireGeyser_Instr_4(uint16 k, const uint16 *jp);
const uint16 *FireGeyser_Instr_5(uint16 k, const uint16 *jp);
const uint16 *FireGeyser_Instr_6(uint16 k, const uint16 *jp);
const uint16 *FireGeyser_Instr_7(uint16 k, const uint16 *jp);
const uint16 *FireGeyser_Instr_8(uint16 k, const uint16 *jp);
const uint16 *FireGeyser_Instr_9(uint16 k, const uint16 *jp);
uint16 NuclearWaffle_Func_5(uint16 a, uint16 *r28_out);
const uint16 *Ridley_E90C(uint16 k, const uint16 *j, uint16 a);
uint16 Ridley_Func_122(Rect16U rect);
uint16 Ridley_Func_7(void);
const uint16 *Ridley_Instr_1(uint16 k, const uint16 *jp);
const uint16 *Ridley_Instr_10(uint16 k, const uint16 *jp);
const uint16 *Ridley_Instr_11(uint16 k, const uint16 *jp);
const uint16 *Ridley_Instr_12(uint16 k, const uint16 *jp);
const uint16 *Ridley_Instr_13(uint16 k, const uint16 *jp);
const uint16 *Ridley_Instr_14(uint16 k, const uint16 *jp);
const uint16 *Ridley_Instr_15(uint16 k, const uint16 *jp);
const uint16 *Ridley_Instr_16(uint16 k, const uint16 *jp);
const uint16 *Ridley_Instr_2(uint16 k, const uint16 *jp);
const uint16 *Ridley_Instr_3(uint16 k, const uint16 *jp);
const uint16 *Ridley_Instr_4(uint16 k, const uint16 *jp);
const uint16 *Ridley_Instr_5(uint16 k, const uint16 *jp);
const uint16 *Ridley_Instr_6(uint16 k, const uint16 *jp);
const uint16 *Ridley_Instr_7(uint16 k, const uint16 *jp);
const uint16 *Ridley_Instr_8(uint16 k, const uint16 *jp);
const uint16 *Ridley_Instr_9(uint16 k, const uint16 *jp);
uint16 SpikeyPlatform_Func_5(uint16 k);
uint16 Zebetites_Func_9(void);
uint8 CeresRidley_Func_12(void);
uint8 CeresRidley_Func_8(uint16 a);
uint8 HandleTypewriterText(void);
uint8 HandleTypewriterText_Ext(uint16 a);
uint8 ProcessEscapeTimerTileTransfers(void);
uint8 Ridley_Func_103(uint16 k, uint16 j);
uint8 Ridley_Func_121(void);
uint8 Ridley_Func_124(Rect16U rect);
uint8 Ridley_Func_17(uint16 r18);
uint8 Ridley_Func_23(void);
uint8 Ridley_Func_25(void);
uint8 Ridley_Func_26(uint16 k, uint16 j);
uint8 Ridley_Func_41(void);
uint8 Ridley_Func_48(Rect16U rect);
uint8 Ridley_Func_68(void);
uint8 Ridley_Func_78(void);
uint8 Ridley_Func_80_DoubleRet(void);
uint8 Ridley_Func_90(Point16U *out);
uint8 Ridley_Func_97(void);
void Boulder_Func_1(void);
void Boulder_Func_2(void);
void Boulder_Func_3(void);
void Boulder_Func_4(void);
void Boulder_Func_5(void);
void Boulder_Func_6(void);
void Boulder_Func_7(uint16 j);
void Boulder_Func_8(uint16 j);
void Boulder_Func_9(uint16 j);
void Boulder_Init(void);
void Boulder_Main(void);
void CeresDoor_F773(uint16 j);
void CeresDoor_Func_1(uint16 k);
void CeresDoor_Func_2(void);
void CeresDoor_Func_3(void);
void CeresDoor_Func_4(void);
void CeresDoor_Func_5(uint16 k);
void CeresDoor_Func_6(uint16 k);
void CeresDoor_Func_6b(void);
void CeresDoor_Func_7(void);
void CeresDoor_Func_8(void);
void CeresDoor_Init(void);
void CeresDoor_Main(void);
void CeresRidley_A377(void);
void CeresRidley_A7F9(void);
void CeresRidley_A994(void);
void CeresRidley_Func_1(void);
void CeresRidley_Func_10(void);
void CeresRidley_Func_11(void);
void CeresRidley_Func_13(void);
void CeresRidley_Func_14(void);
void CeresRidley_Func_15(void);
void CeresRidley_Func_16(void);
void CeresRidley_Func_17(void);
void CeresRidley_Func_18(void);
void CeresRidley_Func_19(void);
void CeresRidley_Func_2(void);
void CeresRidley_Func_20(void);
void CeresRidley_Func_21(void);
void CeresRidley_Func_22(void);
void CeresRidley_Func_23(void);
void CeresRidley_Func_24(void);
void CeresRidley_Func_25(void);
void CeresRidley_Func_26(void);
void CeresRidley_Func_27(void);
void CeresRidley_Func_28(void);
void CeresRidley_Func_29(void);
void CeresRidley_Func_3(void);
void CeresRidley_Func_33(void);
void CeresRidley_Func_34(void);
void CeresRidley_Func_35(uint16 a);
void CeresRidley_Func_4(void);
void CeresRidley_Func_5(void);
void CeresRidley_Func_6(void);
void CeresRidley_Func_7(void);
void CeresRidley_Func_9(void);
void CeresRidley_Hurt(void);
void CeresRidley_Init(void);
void CeresRidley_Main(void);
void CeresSteam_Func_1(uint16 k);
void CeresSteam_Init(void);
void CeresSteam_Main(void);
void CeresSteam_Touch(void);
void DrawBabyMetroid_0(void);
void Enemy_GrappleReact_CancelBeam_A6(void);
void Enemy_GrappleReact_NoInteract_A6(void);
void Enemy_NormalFrozenAI_A6(void);
void Enemy_NormalShotAI_A6(void);
void Enemy_NormalTouchAI_A6(void);
void FakeKraid_9C50(void);
void FakeKraid_Func_1(uint16 k, uint16 j);
void FakeKraid_Init(void);
void FakeKraid_InstrHelper_45(uint16 k, uint16 j, uint16 a);
void FakeKraid_Main(void);
void FakeKraid_Shot(void);
void FakeKraid_Touch(void);
void FireGeyser_Func_1(void);
void FireGeyser_Func_2(void);
void FireGeyser_Init(void);
void FireGeyser_Main(void);
void HandleCeresRidleyGetawayCutscene(void);
void NuclearWaffle_Func_1(void);
void NuclearWaffle_Func_2(void);
void NuclearWaffle_Func_3(uint16 varE32);
void NuclearWaffle_Func_4(uint16 varE32);
void NuclearWaffle_Func_7(uint16 r30);
void NuclearWaffle_Init(void);
void NuclearWaffle_Main(void);
void Ridley_A2DC(void);
void Ridley_A2F2(void);
void Ridley_B455(void);
void Ridley_C08E(void);
void Ridley_C09F(void);
void Ridley_C104(void);
void Ridley_C53E(void);
void Ridley_C551(void);
void Ridley_CBC0(void);
void Ridley_CBC7(void);
void Ridley_CBCE(void);
void Ridley_CBD5(void);
void Ridley_CBDC(void);
void Ridley_D495(uint16 r18);
void Ridley_Func_1(void);
void Ridley_Func_10(void);
void Ridley_Func_100(void);
void Ridley_Func_101(void);
void Ridley_Func_102(void);
void Ridley_Func_104(uint16 k, uint16 j, uint16 a, uint16 r18, uint16 r20);
void Ridley_Func_104_0(uint16 k, uint16 j, uint16 r18, uint16 r20);
void Ridley_Func_105(uint16 k, uint16 r18, uint16 r24, uint16 r26);
void Ridley_Func_106(uint16 k, uint16 j, uint16 r18, uint16 r20);
void Ridley_Func_107(uint16 k, uint16 r18, uint16 r24);
void Ridley_Func_11(void);
void Ridley_Func_111(uint16 r18, uint16 r20, uint16 r22);
void Ridley_Func_112(void);
void Ridley_Func_113(uint16 k);
void Ridley_Func_114(void);
void Ridley_Func_115(void);
void Ridley_Func_116(void);
void Ridley_Func_117(void);
void Ridley_Func_118(void);
void Ridley_Func_119(uint8 carry);
void Ridley_Func_12(void);
void Ridley_Func_120(void);
void Ridley_Func_123(uint16 j);
void Ridley_Func_125(void);
void Ridley_Func_126(void);
void Ridley_Func_127(void);
void Ridley_Func_128(void);
void Ridley_Func_129(void);
void Ridley_Func_13(void);
void Ridley_Func_131(uint16 k);
void Ridley_Func_132(uint16 k, uint16 a);
void Ridley_Func_14(void);
void Ridley_Func_15(void);
void Ridley_Func_16(void);
void Ridley_Func_18(void);
void Ridley_Func_19(void);
void Ridley_Func_2(void);
void Ridley_Func_20(void);
void Ridley_Func_21(void);
void Ridley_Func_22(void);
void Ridley_Func_24(void);
void Ridley_Func_27(void);
void Ridley_Func_28(void);
void Ridley_Func_29(void);
void Ridley_Func_3(void);
void Ridley_Func_30(void);
void Ridley_Func_31(void);
void Ridley_Func_32(void);
void Ridley_Func_33(void);
void Ridley_Func_33b(void);
void Ridley_Func_34(void);
void Ridley_Func_35(void);
void Ridley_Func_36(void);
void Ridley_Func_37(void);
void Ridley_Func_38(void);
void Ridley_Func_39(void);
void Ridley_Func_3b(void);
uint16 Ridley_Func_4(void);
void Ridley_Func_42(void);
void Ridley_Func_43(void);
void Ridley_Func_44(void);
void Ridley_Func_45(void);
void Ridley_Func_46(void);
void Ridley_Func_47(void);
void Ridley_Func_49(void);
void Ridley_Func_5(void);
void Ridley_Func_50(void);
void Ridley_Func_51(void);
void Ridley_Func_52(void);
void Ridley_Func_53(void);
void Ridley_Func_54(void);
void Ridley_Func_55(void);
void Ridley_Func_56(void);
void Ridley_Func_57(void);
void Ridley_Func_58(void);
void Ridley_Func_59(void);
void Ridley_Func_6(void);
void Ridley_Func_60(void);
void Ridley_Func_61(void);
void Ridley_Func_62(void);
void Ridley_Func_63(void);
void Ridley_Func_64(void);
void Ridley_Func_65(void);
void Ridley_Func_66(void);
void Ridley_Func_67(void);
void Ridley_Func_69(void);
void Ridley_Func_70(void);
void Ridley_Func_71(void);
void Ridley_Func_72(void);
void Ridley_Func_73(void);
void Ridley_Func_74(void);
void Ridley_Func_75(void);
void Ridley_Func_77(void);
void Ridley_Func_79(void);
void Ridley_Func_8(void);
void Ridley_Func_81(void);
void Ridley_Func_83(void);
void Ridley_Func_84(void);
void Ridley_Func_85(void);
void Ridley_Func_86(void);
void Ridley_Func_87(void);
void Ridley_Func_88(uint16 k);
void Ridley_Func_89(uint16 a);
void Ridley_Func_9(void);
void Ridley_Func_91(void);
void Ridley_Func_92(void);
void Ridley_Func_93(uint16 j, uint16 k);
void Ridley_Func_94(void);
void Ridley_Func_95(void);
void Ridley_Func_96(void);
void Ridley_Func_98(void);
void Ridley_Func_99(uint16 a);
void Ridley_Func_D3DC(uint16 a);
void Ridley_Hurt(void);
void Ridley_Main(void);
void Ridley_Powerbomb(void);
void Ridley_Shot(void);
void RidleysExplosion_Func_1(uint16 k);
void RidleysExplosion_Func_2(void);
void RidleysExplosion_Init(void);
void RidleysExplosion_Main(void);
void SetupZebesEscapeTypewriter(void);
void SpikeyPlatform2ndEnemy_Init(void);
void SpikeyPlatform2ndEnemy_Main(void);
void SpikeyPlatform_Func_1(void);
void SpikeyPlatform_Func_2(void);
void SpikeyPlatform_Func_3(uint16 k);
void SpikeyPlatform_Func_4(void);
void SpikeyPlatform_Init(void);
void SpikeyPlatform_Main(void);
void Zebetites_Func_1(uint16 k);
void Zebetites_Func_2(uint16 k);
void Zebetites_Func_3(void);
void Zebetites_Func_4(void);
void Zebetites_Func_5(void);
void Zebetites_Func_6(void);
void Zebetites_Func_7(uint16 j, uint8 carry);
void Zebetites_Func_8(void);
void Zebetites_Init(void);
void Zebetites_Main(void);
void Zebetites_Shot(void);
void Zebetites_Touch(void);
void sub_A69C0B(void);
void sub_A6DB2A(void);
void sub_A6DBC2(uint16 j, uint16 x, uint16 y);
void sub_A6DC13(uint16 j, uint16 r18, uint16 r20, uint16 );
void sub_A6DF59(void);
void sub_A6DF60(void);

// Bank A7
PairU16 Phantoon_SetColorBasedOnHp_FindEntry(uint16 k);
const uint16 *EnemyInstr_Call_A7(uint16 k, const uint16 *jp);
uint16 Kraid_CheckIfDead(void);
uint16 Kraid_ExecuteInstr(void);
const uint16 *Kraid_Instr_1(uint16 k, const uint16 *jp);
const uint16 *Kraid_Instr_SlowArmIfLessThanHalfHealth(uint16 k, const uint16 *jp);
const uint16 *Kraid_Instr_DecYpos(uint16 k, const uint16 *jp);
const uint16 *Kraid_Instr_IncrYpos_Shake(uint16 k, const uint16 *jp);
const uint16 *Kraid_Instr_MoveHimRight(uint16 k, const uint16 *jp);
const uint16 *Kraid_Instr_PlayEarthQuakeSfx(uint16 k, const uint16 *jp);
const uint16 *Kraid_Instr_XposMinus3(uint16 k, const uint16 *jp);
const uint16 *Kraid_Instr_XposMinus3b(uint16 k, const uint16 *jp);
const uint16 *Kraid_Instr_XposPlus3(uint16 k, const uint16 *jp);
uint16 Kraid_ProcessKraidInstr(void);
uint16 Phantoon_CalculateNthTransitionColorComponentFromXtoY(uint16 a, uint16 k, uint16 j);
uint16 Phantoon_Func_10_CalculateNthTransitionColorFromXtoY(uint16 a, uint16 k, uint16 j);
uint8 Etecoon_Func_2(uint16 k);
uint8 Etecoon_Func_3(uint16 k);
uint8 Phantoon_Func_ChangeWaveAmplitude(int32 amt);
uint8 Phantoon_Func_8(void);
uint8 Phantoon_Func_9(void);
uint8 Phantoon_SetColorBasedOnHp(void);
void Dachora_Func_1(uint16 j, uint16 k);
void Dachora_Func_10(uint16 k);
void Dachora_Func_11(uint16 k);
void Dachora_Func_12(uint16 k);
void Dachora_Func_2(uint16 k);
void Dachora_Func_3(uint16 k);
void Dachora_Func_4(uint16 k);
void Dachora_Func_5(uint16 k);
int32 Dachora_Func_6(uint16 k);
void Dachora_Func_7(uint16 k);
void Dachora_Func_8(uint16 k);
void Dachora_Func_9(uint16 k);
void Dachora_Init(void);
void Dachora_Main(void);
void Enemy_GrappleReact_CancelBeam_A7(void);
void Enemy_GrappleReact_NoInteract_A7(void);
void Enemy_NormalFrozenAI_A7(void);
void Enemy_NormalPowerBombAI_SkipDeathAnim_A7(void);
void Enemy_NormalShotAI_A7(void);
void Etecoon_Func_1(uint16 k);
void Etecoon_Func_10(uint16 k);
void Etecoon_Func_11(uint16 k);
void Etecoon_Func_12(uint16 k);
void Etecoon_Func_13(uint16 j);
void Etecoon_Func_14(uint16 j);
void Etecoon_Func_15(uint16 j);
void Etecoon_Func_16(uint16 k);
void Etecoon_Func_17(uint16 k);
void Etecoon_Func_18(uint16 k);
void Etecoon_Func_19(uint16 k);
void Etecoon_Func_20(uint16 k);
void Etecoon_Func_21(uint16 k);
void Etecoon_Func_22(uint16 k);
void Etecoon_Func_23(uint16 k);
void Etecoon_Func_24(uint16 k);
void Etecoon_Func_25(uint16 k);
void Etecoon_Func_26(uint16 k);
void Etecoon_Func_4(uint16 k);
void Etecoon_Func_5(uint16 k);
void Etecoon_Func_6(uint16 k);
void Etecoon_Func_7(uint16 k);
void Etecoon_Func_8(uint16 k);
void Kraid_Shot(void);
void Kraid_Touch(void);
void Kraid_Touch_ArmFoot(void);
void KraidsArm_Init(void);
void KraidsArm_Main(void);
void KraidsArm_Touch(void);
void KraidsBadFingernail_Init(void);
void KraidsBadFingernail_Main(void);
void KraidsBadFingernail_Touch(void);
void KraidsBottomLint_Init(void);
void KraidsBottomLint_Main(void);
void KraidsFingernail_Init(void);
void KraidsFoot_Init(void);
void KraidsFoot_Main(void);
void KraidsFoot_SecondPhase_Init(void);
void KraidsGoodFingernail_Init(void);
void KraidsGoodFingernail_Main(void);
void KraidsGoodFingernail_Touch(void);
void KraidsMiddleLint_Init(void);
void KraidsMiddleLint_Main(void);
void KraidsTopLint_Init(void);
void KraidsTopLint_Main(void);
void Kraid_Init(void);
void Kraid_Main(void);
void Kraid_Arm_Shot(uint16 j);
CoroutineRet Kraid_UnpauseHook_IsSinking(void);

void Etecoon_Func_9(uint16 k);
void Etecoon_Init(void);
void Etecoon_Main(void);
void PauseHook_Kraid(void);
void Phantoon2_Init(void);
void Phantoon_AdjustSpeedAndMoveInFigure8(void);
void Phantoon_AdjustSpeedLeftSideClockwise(void);
void Phantoon_AdjustSpeedRightSideClockwise(void);
void Phantoon_AlmostDead(uint16 k);
void Phantoon_BecomeSolidAfterRainingFireballs(uint16 k);
void Phantoon_BecomesSolidAndBodyVuln(uint16 k);
void Phantoon_BeginSwoopingPattern(uint16 k);
void Phantoon_ChangeEyeSpriteBasedOnSamusDist(void);
void Phantoon_CompleteSwoopAfterFatalShot(uint16 k);
void Phantoon_Dead(uint16 k);
void Phantoon_DyingFadeOut(uint16 k);
void Phantoon_DyingPhantoonExplosions(uint16 k);
void Phantoon_DyingPhantoonFadeInOut(uint16 k);
void Phantoon_Enraged(uint16 k);
void Phantoon_EyeFollowsSamusUntilTimerRunsOut(uint16 k);
void Phantoon_FadeIn(uint16 a);
void Phantoon_FadeInBeforeFigure8(uint16 k);
void Phantoon_FadeInDuringFireballRain(uint16 k);
void Phantoon_FadeInEnragedPhantoon(uint16 k);
void Phantoon_FadeOut(uint16 a);
void Phantoon_FadeOutBeforeEnrage(uint16 k);
void Phantoon_FadeOutBeforeFirstFireballRain(uint16 k);
void Phantoon_FadeOutDuringFireballRain(uint16 k);
void Phantoon_FadeoutAfterEnrage(uint16 k);
void Phantoon_FadeoutWithSwoop(uint16 k);
void Phantoon_FollowSamusWithEyeDuringFireballRain(uint16 k);
void Phantoon_Func_1(void);
void Phantoon_Func_2(uint16 k);
void Phantoon_Func_4(uint16 k);
void Phantoon_Func_5(uint16 k);
void Phantoon_Func_6(uint16 k, uint16 a);
void Phantoon_Func_7(uint16 k);
void Phantoon_Hurt(void);
void Phantoon_Init(void);
void Phantoon_IsSwooping(uint16 k);
void Phantoon_Main(void);
void Phantoon_MoveEnragedPhantoonToTopCenter(uint16 k);
void Phantoon_MoveInFigure8_LeftSideClockwise(uint16 j, uint16 r20);
void Phantoon_MoveInFigure8_RightSideClockwise(uint16 j, uint16 r20);
void Phantoon_MoveInSwoopingPattern(uint16 k);
void Phantoon_MoveLeftOrRightAndPickEyeOpenPatt(uint16 k);
void Phantoon_MovePhantoonInFigure8ThenOpenEye(uint16 k);
void Phantoon_PickPatternForRound1(uint16 k);
void Phantoon_PickPatternForRound2(void);
void Phantoon_Shot(void);
void Phantoon_Spawn8FireballsInCircleAtStart(uint16 k);
void Phantoon_SpawnFireballsBeforeFight(uint16 k);
void Phantoon_SpawnRainingFireballs(uint16 k);
void Phantoon_StartDeathSequence(uint16 k);
void Phantoon_StartTrackingSamusAndInitEyeTimer(void);
void Phantoon_Touch(void);
void Phantoon_WaitAfterFadeOut(uint16 k);
void Phantoon_WaitBetweenSpawningAndSpinningFireballs(uint16 k);
void Phantoon_WavyDyingPhantoonAndCry(uint16 k);
void Phantoon_WavyFadeIn(uint16 k);
CoroutineRet UnpauseHook_Kraid_IsAlive(void);
CoroutineRet UnpauseHook_Kraid_IsDead(void);
void sub_A7A92A(void);

// Bank A8
uint16 Beetom_Func_2(uint16 r22, uint16 r24);
const uint16 *Beetom_Instr_1(uint16 k, const uint16 *jp);
uint16 Fune_Func_3(void);
const uint16 *Fune_Instr_1(uint16 k, const uint16 *jp);
const uint16 *Fune_Instr_2(uint16 k, const uint16 *jp);
const uint16 *Fune_Instr_3(uint16 k, const uint16 *jp);
const uint16 *Fune_Instr_4(uint16 k, const uint16 *jp);
const uint16 *Fune_Instr_5(uint16 k, const uint16 *jp);
const uint16 *Fune_Instr_6(uint16 k, const uint16 *jp);
const uint16 *Fune_Instr_7(uint16 k, const uint16 *jp);
const uint16 *KiHunter_Instr_1(uint16 k, const uint16 *jp);
const uint16 *KiHunter_Instr_2(uint16 k, const uint16 *jp);
const uint16 *KiHunter_Instr_3(uint16 k, const uint16 *jp);
const uint16 *KiHunter_Instr_4(uint16 k, const uint16 *jp);
const uint16 *KiHunter_Instr_5(uint16 k, const uint16 *jp);
const uint16 *MiniDraygon_Instr_1(uint16 k, const uint16 *jp);
const uint16 *MiniDraygon_Instr_2(uint16 k, const uint16 *jp);
const uint16 *MiniDraygon_Instr_3(uint16 k, const uint16 *jp);
const uint16 *MiniDraygon_Instr_4(uint16 k, const uint16 *jp);
const uint16 *NorfairLavaMan_Instr_1(uint16 k, const uint16 *jp);
const uint16 *NorfairLavaMan_Instr_10(uint16 k, const uint16 *jp);
const uint16 *NorfairLavaMan_Instr_11(uint16 k, const uint16 *jp);
const uint16 *NorfairLavaMan_Instr_12(uint16 k, const uint16 *jp);
const uint16 *NorfairLavaMan_Instr_13(uint16 k, const uint16 *jp);
const uint16 *NorfairLavaMan_Instr_14(uint16 k, const uint16 *jp);
const uint16 *NorfairLavaMan_Instr_15(uint16 k, const uint16 *jp);
const uint16 *NorfairLavaMan_Instr_16(uint16 k, const uint16 *jp);
const uint16 *NorfairLavaMan_Instr_2(uint16 k, const uint16 *jp);
const uint16 *NorfairLavaMan_Instr_3(uint16 k, const uint16 *jp);
const uint16 *NorfairLavaMan_Instr_4(uint16 k, const uint16 *jp);
const uint16 *NorfairLavaMan_Instr_5(uint16 k, const uint16 *jp);
const uint16 *NorfairLavaMan_Instr_6(uint16 k, const uint16 *jp);
const uint16 *NorfairLavaMan_Instr_7(uint16 k, const uint16 *jp);
const uint16 *NorfairLavaMan_Instr_8(uint16 k, const uint16 *jp);
const uint16 *NorfairLavaMan_Instr_9(uint16 k, const uint16 *jp);
uint16 WalkingLavaSeahorse_Func_2(uint16 k);
const uint16 *WalkingLavaSeahorse_Instr_1(uint16 k, const uint16 *jp);
const uint16 *WalkingLavaSeahorse_Instr_2(uint16 k, const uint16 *jp);
const uint16 *WalkingLavaSeahorse_Instr_3(uint16 k, const uint16 *jp);
const uint16 *WalkingLavaSeahorse_Instr_4(uint16 k, const uint16 *jp);
const uint16 *WalkingLavaSeahorse_Instr_5(uint16 k, const uint16 *jp);
const uint16 *WalkingLavaSeahorse_Instr_6(uint16 k, const uint16 *jp);
uint16 WreckedShipGhost_Func_8(void);
const uint16 *WreckedShipRobot_CommonInstr(uint16 k, const uint16 *jp, uint16 r50, uint16 r48);
const uint16 *WreckedShipRobot_D10C(uint16 k, const uint16 *jp, uint16 r50);
const uint16 *WreckedShipRobot_D147(uint16 k, const uint16 *jp, uint16 r48, uint16 r50);
const uint16 *WreckedShipRobot_Instr_1(uint16 k, const uint16 *jp);
const uint16 *WreckedShipRobot_Instr_10(uint16 k, const uint16 *jp);
const uint16 *WreckedShipRobot_Instr_11(uint16 k, const uint16 *jp);
const uint16 *WreckedShipRobot_Instr_12(uint16 k, const uint16 *jp);
const uint16 *WreckedShipRobot_Instr_13(uint16 k, const uint16 *jp);
const uint16 *WreckedShipRobot_Instr_14(uint16 k, const uint16 *jp);
const uint16 *WreckedShipRobot_Instr_15(uint16 k, const uint16 *jp);
const uint16 *WreckedShipRobot_Instr_16(uint16 k, const uint16 *jp);
const uint16 *WreckedShipRobot_Instr_17(uint16 k, const uint16 *jp);
const uint16 *WreckedShipRobot_Instr_18(uint16 k, const uint16 *jp);
const uint16 *WreckedShipRobot_Instr_2(uint16 k, const uint16 *jp);
const uint16 *WreckedShipRobot_Instr_3(uint16 k, const uint16 *jp);
const uint16 *WreckedShipRobot_Instr_4(uint16 k, const uint16 *jp);
const uint16 *WreckedShipRobot_Instr_5(uint16 k, const uint16 *jp);
const uint16 *WreckedShipRobot_Instr_6(uint16 k, const uint16 *jp);
const uint16 *WreckedShipRobot_Instr_7(uint16 k, const uint16 *jp);
const uint16 *WreckedShipRobot_Instr_8(uint16 k, const uint16 *jp);
const uint16 *WreckedShipRobot_Instr_9(uint16 k, const uint16 *jp);
const uint16 *WreckedShipSpark_Instr_1(uint16 k, const uint16 *jp);
const uint16 *WreckedShipSpark_Instr_2(uint16 k, const uint16 *jp);
uint16 YappingMaw_Func_16(uint16 a, uint16 varE32);
uint16 YappingMaw_Func_17(uint16 a, uint16 varE32);
const uint16 *YappingMaw_Instr_1(uint16 k, const uint16 *jp);
const uint16 *YappingMaw_Instr_2(uint16 k, const uint16 *jp);
const uint16 *YappingMaw_Instr_3(uint16 k, const uint16 *jp);
const uint16 *YappingMaw_Instr_4(uint16 k, const uint16 *jp);
const uint16 *YappingMaw_Instr_5(uint16 k, const uint16 *jp);
const uint16 *YappingMaw_Instr_6(uint16 k, const uint16 *jp);
const uint16 *YappingMaw_Instr_7(uint16 k, const uint16 *jp);
void Beetom_Init(void);
void Beetom_Main(void);
void Beetom_Shot(void);
void Beetom_Touch(void);
void BlueBrinstarFaceBlock_Func_1(void);
void BlueBrinstarFaceBlock_Init(void);
void BlueBrinstarFaceBlock_Main(void);
void BlueBrinstarFaceBlock_Shot(void);
void Enemy_GrappleReact_CancelBeam_A8(void);
void Enemy_GrappleReact_HurtSamus_A8(void);
void Enemy_GrappleReact_KillEnemy_A8(void);
void Enemy_GrappleReact_NoInteract_A8(void);
void Enemy_GrappleReact_SamusLatchesNoInvinc_A8(void);
void Enemy_NormalFrozenAI_A8(void);
void Enemy_NormalPowerBombAI_A8(void);
void Enemy_NormalShotAI_A8(void);
void Enemy_NormalTouchAI_A8(void);
void EvirProjectile_Init(void);
void EvirProjectile_Main(void);
void Fune_Func_1(void);
void Fune_Func_2(void);
void Fune_Func_4(void);
void Fune_Init(void);
void Fune_Main(void);
void Kago_Func_1(uint16 k);
void Kago_Init(void);
void Kago_Main(void);
void Kago_Shot(void);
void KiHunterWings_Init(void);
void KiHunterWings_Main(void);
void KiHunter_Func_1(uint16 k);
void KiHunter_Func_10(uint16 k);
void KiHunter_Func_11(void);
void KiHunter_Func_12(void);
void KiHunter_Func_13(void);
void KiHunter_Func_14(void);
void KiHunter_Func_15(uint16 k);
void KiHunter_Func_16(uint16 k);
void KiHunter_Func_17(void);
void KiHunter_Func_2(uint16 k);
void KiHunter_Func_3(uint16 k);
void KiHunter_Func_4(uint16 k);
void KiHunter_Func_5(uint16 k);
void KiHunter_Func_6(uint16 k);
void KiHunter_Func_7(uint16 k);
void KiHunter_Func_8(uint16 k);
void KiHunter_Func_9(uint16 k);
void KiHunter_Init(void);
void KiHunter_Main(void);
void KiHunter_Shot(void);
void MaridiaFloater_Func_1(uint16 k);
void MaridiaFloater_Func_10(uint16 k);
void MaridiaFloater_Func_11(uint16 k);
void MaridiaFloater_Func_12(uint16 k);
void MaridiaFloater_Func_13(uint16 k);
void MaridiaFloater_Func_2(uint16 k);
void MaridiaFloater_Func_3(uint16 k);
void MaridiaFloater_Func_4(uint16 k);
void MaridiaFloater_Func_5(uint16 k);
void MaridiaFloater_Func_6(uint16 k);
void MaridiaFloater_Func_7(uint16 k);
void MaridiaFloater_Func_8(uint16 k);
void MaridiaFloater_Func_9(uint16 k);
void MaridiaFloater_Init(void);
void MaridiaFloater_Main(void);
void MaridiaFloater_Powerbomb(void);
void MaridiaFloater_Shot(void);
void MaridiaFloater_Touch(void);
void MaridiaPuffer_Func_1(void);
void MaridiaPuffer_Func_10(void);
void MaridiaPuffer_Func_11(void);
void MaridiaPuffer_Func_2(void);
void MaridiaPuffer_Func_3(void);
void MaridiaPuffer_Func_4(void);
void MaridiaPuffer_Func_5(void);
void MaridiaPuffer_Func_6(void);
void MaridiaPuffer_Func_7(void);
void MaridiaPuffer_Func_8(uint16 k);
void MaridiaPuffer_Func_9(uint16 k);
void MaridiaPuffer_Init(void);
void MaridiaPuffer_Main(void);
void MaridiaPuffer_Shot(void);
void MiniDraygon_Func_1(void);
void MiniDraygon_Func_10(void);
void MiniDraygon_Func_11(void);
void MiniDraygon_Func_12(void);
void MiniDraygon_Func_13(void);
void MiniDraygon_Func_2(void);
void MiniDraygon_Func_3(void);
void MiniDraygon_Func_4(void);
void MiniDraygon_Func_5(void);
void MiniDraygon_Func_6(void);
void MiniDraygon_Func_7(void);
void MiniDraygon_Func_8(void);
void MiniDraygon_Func_9(void);
void MiniDraygon_Init(void);
void MiniDraygon_Main(void);
void MiniDraygon_Powerbomb(void);
void MiniDraygon_Shot(void);
void MiniDraygon_Touch(void);
void MorphBallEye_Func_1(uint16 k);
void MorphBallEye_Func_2(uint16 k);
void MorphBallEye_Func_3(uint16 k);
void MorphBallEye_Func_4(uint16 k);
void MorphBallEye_Init(void);
void MorphBallEye_Main(void);
void NorfairLavaMan_Common(void);
void NorfairLavaMan_Func_1(void);
void NorfairLavaMan_Func_10(uint16 k);
void NorfairLavaMan_Func_11(uint16 k);
void NorfairLavaMan_Func_12(uint16 k);
void NorfairLavaMan_Func_13(void);
void NorfairLavaMan_Func_14(uint16 k);
void NorfairLavaMan_Func_15(uint16 k);
void NorfairLavaMan_Func_16(uint16 k);
void NorfairLavaMan_Func_17(uint16 k);
void NorfairLavaMan_Func_18(uint16 k);
void NorfairLavaMan_Func_19(uint16 k);
void NorfairLavaMan_Func_2(void);
void NorfairLavaMan_Func_20(void);
void NorfairLavaMan_Func_3(void);
void NorfairLavaMan_Func_4(void);
void NorfairLavaMan_Func_5(uint16 k);
void NorfairLavaMan_Func_6(void);
void NorfairLavaMan_Func_7(uint16 k);
void NorfairLavaMan_Func_8(uint16 k);
void NorfairLavaMan_Func_9(uint16 k);
void NorfairLavaMan_Init(void);
void NorfairLavaMan_Main(void);
void NorfairLavaMan_Powerbomb(void);
void NorfairLavaMan_Shot(void);
void NorfairLavaMan_Touch(void);
void WalkingLavaSeahorse_DF20(uint16 a);
void WalkingLavaSeahorse_Func_1(uint16 k);
void WalkingLavaSeahorse_Func_10(void);
void WalkingLavaSeahorse_Func_3(uint16 k);
void WalkingLavaSeahorse_Func_4(uint16 k);
void WalkingLavaSeahorse_Func_5(uint16 k);
void WalkingLavaSeahorse_Func_6(uint16 k);
void WalkingLavaSeahorse_Func_7(uint16 k);
void WalkingLavaSeahorse_Func_8(uint16 k);
void WalkingLavaSeahorse_Func_9(uint16 k);
void WalkingLavaSeahorse_Init(void);
void WalkingLavaSeahorse_Main(void);
void WreckedShipGhost_Func_1(uint16 k);
void WreckedShipGhost_Func_2(uint16 k);
void WreckedShipGhost_Func_3(uint16 k);
void WreckedShipGhost_Func_4(uint16 k);
void WreckedShipGhost_Func_5(uint16 k);
void WreckedShipGhost_Func_6(uint16 k);
void WreckedShipGhost_Func_7(uint16 k);
void WreckedShipGhost_Init(void);
void WreckedShipGhost_Main(void);
void WreckedShipOrbs_Func_1(void);
void WreckedShipOrbs_Func_2(void);
void WreckedShipOrbs_Func_3(void);
void WreckedShipOrbs_Func_4(void);
void WreckedShipOrbs_Func_5(void);
void WreckedShipOrbs_Func_6(void);
void WreckedShipOrbs_Func_7(void);
void WreckedShipOrbs_Func_8(void);
void WreckedShipOrbs_Init(void);
void WreckedShipOrbs_Main(void);
void WreckedShipRobotDeactivated_Init(void);
void WreckedShipRobotDeactivated_Shot(void);
void WreckedShipRobotDeactivated_Touch(void);
void WreckedShipRobot_Func_1(void);
void WreckedShipRobot_Func_2(uint16 k);
void WreckedShipRobot_Init(void);
void WreckedShipRobot_Main(void);
void WreckedShipRobot_Shot(void);
void WreckedShipSpark_Func_1(uint16 k);
void WreckedShipSpark_Func_2(uint16 k);
void WreckedShipSpark_Func_3(uint16 k);
void WreckedShipSpark_Init(void);
void WreckedShipSpark_Main(void);
void WreckedShipSpark_Shot(void);
void YappingMaw_Frozen(void);
void YappingMaw_Func_1(void);
void YappingMaw_Func_10(void);
void YappingMaw_Func_11(void);
void YappingMaw_Func_12(void);
void YappingMaw_Func_13(void);
void YappingMaw_Func_14(void);
void YappingMaw_Func_15(void);
void YappingMaw_Func_18(uint16 j);
void YappingMaw_Func_19(void);
void YappingMaw_Func_2(void);
void YappingMaw_Func_3(void);
void YappingMaw_Func_4(void);
void YappingMaw_Func_5(void);
void YappingMaw_Func_6(void);
void YappingMaw_Func_7(void);
void YappingMaw_Func_8(void);
void YappingMaw_Func_9(uint16 k);
void YappingMaw_Init(void);
void YappingMaw_Main(void);
void YappingMaw_Shot(void);
void YappingMaw_Touch(void);
void sub_A8AF32(void);
void sub_A8B193(uint16 k);
void sub_A8B291(uint16 k);
void sub_A8DDDE(uint16 k);
void sub_A8F6DC(uint16 k, uint16 j);

// Bank A9
uint16 ComputeCosMult(uint16 a, uint16 r18);
uint16 ComputeSinMult(uint16 a, uint16 r18);
uint16 HandleMotherBrainInstructionList(uint16 a);
uint16 MotherBrain_DetermineShotReactionType(void);
uint16 MotherBrain_Func_1_DoubleRetTmp(void);
uint16 MotherBrain_Instr_AimRingsAtSamus(uint16 k);
uint16 MotherBrain_Instr_AimRingsAtShitroid(uint16 k);
uint16 MotherBrain_Instr_DisableNeckMovement(uint16 k);
const uint16 *MotherBrain_Instr_Down2Right15(uint16 k, const uint16 *jp);
const uint16 *MotherBrain_Instr_Down4Right6(uint16 k, const uint16 *jp);
uint16 MotherBrain_Instr_EnableNeckMovementGoto(uint16 k);
uint16 MotherBrain_Instr_Goto(uint16 k);
uint16 MotherBrain_Instr_Goto2(uint16 k);
uint16 MotherBrain_Instr_GotoEitherOr(uint16 k);
const uint16 *MotherBrain_Instr_IncrBeamAttackPhase(uint16 k, const uint16 *jp);
uint16 MotherBrain_Instr_IncrShitroidAttackCtr(uint16 k);
uint16 MotherBrain_Instr_MaybeGoto(uint16 k);
uint16 MotherBrain_Instr_MaybeGoto2(uint16 k);
const uint16 *MotherBrain_Instr_MoveBodyUp10Left4(uint16 k, const uint16 *jp);
const uint16 *MotherBrain_Instr_MoveBodyUp12Right2(uint16 k, const uint16 *jp);
const uint16 *MotherBrain_Instr_MoveBodyUp16Left4(uint16 k, const uint16 *jp);
const uint16 *MotherBrain_Instr_MoveDown1(uint16 k, const uint16 *jp);
const uint16 *MotherBrain_Instr_MoveDown10Right2(uint16 k, const uint16 *jp);
const uint16 *MotherBrain_Instr_MoveDown12Left4(uint16 k, const uint16 *jp);
const uint16 *MotherBrain_Instr_MoveDown16Right2(uint16 k, const uint16 *jp);
const uint16 *MotherBrain_Instr_MoveDown1Left3(uint16 k, const uint16 *jp);
const uint16 *MotherBrain_Instr_MoveDown2Right1(uint16 k, const uint16 *jp);
const uint16 *MotherBrain_Instr_MoveDown4Right2(uint16 k, const uint16 *jp);
const uint16 *MotherBrain_Instr_MoveLeft2(uint16 k, const uint16 *jp);
const uint16 *MotherBrain_Instr_MoveRight2(uint16 k, const uint16 *jp);
const uint16 *MotherBrain_Instr_MoveUp1(uint16 k, const uint16 *jp);
const uint16 *MotherBrain_Instr_MoveUp1Right3_Sfx(uint16 k, const uint16 *jp);
const uint16 *MotherBrain_Instr_MoveUp2Left15_Sfx(uint16 k, const uint16 *jp);
const uint16 *MotherBrain_Instr_MoveUp2Right1(uint16 k, const uint16 *jp);
const uint16 *MotherBrain_Instr_MoveUp4Left6(uint16 k, const uint16 *jp);
uint16 MotherBrain_Instr_QueueSfx2(uint16 k);
uint16 MotherBrain_Instr_QueueSfx3(uint16 k);
uint16 MotherBrain_Instr_QueueShitroidAttackSfx(uint16 k);
uint16 MotherBrain_Instr_SetMainShakeTimer50(uint16 k);
const uint16 *MotherBrain_Instr_SetPose_Crouched(uint16 k, const uint16 *jp);
const uint16 *MotherBrain_Instr_SetPose_CrouchedTrans(uint16 k, const uint16 *jp);
const uint16 *MotherBrain_Instr_SetPose_DeathBeamMode(uint16 k, const uint16 *jp);
const uint16 *MotherBrain_Instr_SetPose_LeaningDown(uint16 k, const uint16 *jp);
const uint16 *MotherBrain_Instr_SetPose_Standing(uint16 k, const uint16 *jp);
const uint16 *MotherBrain_Instr_SetPose_Walking(uint16 k, const uint16 *jp);
uint16 MotherBrain_Instr_SetShitroidAttackCtr0(uint16 k);
uint16 MotherBrain_Instr_SetupFxForRainbowBeam(uint16 k);
uint16 MotherBrain_Instr_SpawnBlueRingEproj(uint16 k);
uint16 MotherBrain_Instr_SpawnBombEproj(uint16 k);
const uint16 *MotherBrain_Instr_SpawnDeathBeamEproj(uint16 k, const uint16 *jp);
uint16 MotherBrain_Instr_SpawnDroolEproj(uint16 k);
const uint16 *MotherBrain_Instr_SpawnEprojToOffset(uint16 k, const uint16 *jp);
uint16 MotherBrain_Instr_SpawnLaserEproj(uint16 k);
uint16 MotherBrain_Instr_SpawnPurpleBreath(uint16 k);
uint16 MotherBrain_Instr_SpawnRainbowEproj(uint16 k);
const uint16 *MotherBrain_Instr_Up2Left1_Sfx(uint16 k, const uint16 *jp);
const uint16 *MotherBrain_Instr_Up2Left1_Sfx2(uint16 k, const uint16 *jp);
const uint16 *MotherBrain_Instr_Up4Left2(uint16 k, const uint16 *jp);
uint16 Shitroid_HandleCrySoundEffect(uint16 k, uint16 a);
const uint16 *Shitroid_Instr_1(uint16 k, const uint16 *jp);
const uint16 *Shitroid_Instr_2(uint16 k, const uint16 *jp);
const uint16 *Shitroid_Instr_3(uint16 k, const uint16 *jp);
const uint16 *Shitroid_Instr_4(uint16 k, const uint16 *jp);
const uint16 *Shitroid_Instr_5(uint16 k, const uint16 *jp);
const uint16 *Shitroid_Instr_6(uint16 k, const uint16 *jp);
uint16 sub_A9C46C(uint16 a, uint16 j);
const uint16 *sub_A9ECD0(uint16 k, const uint16 *jp);
uint8 DeadMonsters_Func_3(uint16 k);
uint8 DeadTorizo_Func_0(void);
uint8 MotherBrain_MakeHerCrouch(void);
uint8 MotherBrain_MakeHerLeanDown(void);
uint8 MotherBrain_MakeHerStandUp(void);
uint8 MotherBrain_MakeWalkBackwards(uint16 a, uint16 j);
uint8 MotherBrain_MakeWalkForwards(uint16 j, uint16 a);
uint8 MotherBrain_MoveSamusForFallingAfterBeam(void);
uint8 MotherBrain_MoveSamusHorizTowardsWall(uint16 a);
uint8 MotherBrain_MoveSamusTowardsWallDueToBeam(void);
uint8 MotherBrain_MoveSamusVerticallyTowardsCeilingFloor(uint16 a);
uint8 MotherBrain_Phase2_DecideAttackStrategy_DoubleRet(void);
uint8 MotherBrain_SamusCollDetectPart(uint16 k, uint16 r18, uint16 r20);
uint8 MotherBrain_WalkBackwardsSlowlyAndRetractHead(uint16 a);
uint8 ProcessCorpseRotting(uint16 k);
uint8 ProcessSpriteTilesTransfers(uint8 db, uint16 k);
uint8 Samus_HealDueToShitroid(void);
uint8 ShitroidInCutscene_FadeShitroidToBlack(uint16 k);
uint8 Shitroid_AccelerateTowardsPoint(uint16 k, uint16 a, uint16 r18, uint16 r20);
uint8 Shitroid_CheckIfOnScreen(uint16 k);
uint8 Shitroid_Func_1(uint16 k, uint16 j);
uint8 Shitroid_Func_2(uint16 k, Rect16U rect);
uint8 Shitroid_Func_27(uint16 k);
void CopyMoveCorpseRottingRotEntry(const uint16 *r20, uint16 a, uint16 r18);
void CorpseRottingRotEntryFinishedHook(void);
void DeadMonsters_Func_1(uint16 k);
void DeadMonsters_Func_2(uint16 k);
void DeadMonsters_Func_4(uint16 k, uint16 a);
void DeadMonsters_Func_5(uint16 k);
void DeadMonsters_PreRotDelay_Common(uint16 k, uint16 j);
void DeadMonsters_WaitForSamusColl(uint16 k, uint16 j);
void DeadRipper_Init(void);
void DeadRipper_Powerbomb(void);
void DeadRipper_PreRotDelay(uint16 k);
void DeadRipper_Rotting(uint16 k);
void DeadRipper_Shot(void);
void DeadRipper_WaitForSamusColl(uint16 k);
void DeadSidehopper_Activated(uint16 k);
void DeadSidehopper_Alive_WaitForActivate(uint16 k);
void DeadSidehopper_DD31(void);
void DeadSidehopper_DD34(uint16 a);
void DeadSidehopper_Init(void);
void DeadSidehopper_Init_0(void);
void DeadSidehopper_Init_1(void);
void DeadSidehopper_Main(void);
void DeadSidehopper_Powerbomb(void);
void DeadSidehopper_PreRotDelay(uint16 k);
void DeadSidehopper_Rotting(uint16 k);
void DeadSidehopper_Shot(void);
void DeadSidehopper_Touch(void);
void DeadSidehopper_WaitForSamusColl(uint16 k);
void DeadSkree_Init(void);
void DeadSkree_Powerbomb(void);
void DeadSkree_PreRotDelay(uint16 k);
void DeadSkree_Rotting(uint16 k);
void DeadSkree_Shot(void);
void DeadSkree_WaitForSamusColl(uint16 k);
void DeadTorizo_CopyLineOfSandHeapTileData(uint16 a);
void DeadTorizo_CorpseRottingFinished(void);
void DeadTorizo_Func_1(void);
void DeadTorizo_Init(void);
void DeadTorizo_Main(void);
void DeadTorizo_MainGfxHook(void);
void DeadTorizo_Powerbomb(void);
void DeadTorizo_PreRotDelay(void);
void DeadTorizo_Rotting(void);
void DeadTorizo_Shot(void);
void DeadTorizo_WaitForSamusColl(uint16 k);
void DeadZoomer_Init(void);
void DeadZoomer_Powerbomb(void);
void DeadZoomer_PreRotDelay(uint16 k);
void DeadZoomer_Rotting(uint16 k);
void DeadZoomer_Shot(void);
void DeadZoomer_WaitForSamusColl(uint16 k);
void Enemy_GrappleReact_CancelBeam_A9(void);
void Enemy_IncreaseYpos(uint16 k, uint16 a);
void Enemy_NormalFrozenAI_A9(void);
void Enemy_SetInstrList(uint16 k, uint16 a);
void HandleSamusRainbowPaletteAnimation(uint16 k);
void InitializeCorpseRottingDataTable(uint16 *table, uint16 a);
void InitializeEnemyCorpseRotting(uint16 k, uint16 j);
void MotherBomb_FiringDeathBeam(void);
void MotherBomb_FiringDeathBeam_0(void);
void MotherBomb_FiringDeathBeam_1(void);
void MotherBomb_FiringDeathBeam_2(void);
void MotherBomb_FiringDeathBeam_3(void);
void MotherBomb_FiringLaser_FinishAttack(void);
void MotherBomb_FiringLaser_PositionHead(void);
void MotherBomb_FiringLaser_PositionHeadSlowlyFire(void);
void MotherBomb_FiringRainbowBeam_0(void);
void MotherBomb_FiringRainbowBeam_10_FinishFiringRainbow(void);
void MotherBomb_FiringRainbowBeam_11_LetSamusFall(void);
void MotherBomb_FiringRainbowBeam_12_WaitForSamusHitGround(void);
void MotherBomb_FiringRainbowBeam_13_LowerHead(void);
void MotherBomb_FiringRainbowBeam_14_DecideNextAction(void);
void MotherBomb_FiringRainbowBeam_1_StartCharge(void);
void MotherBomb_FiringRainbowBeam_2_RetractNeck(void);
void MotherBomb_FiringRainbowBeam_3_Wait(void);
void MotherBomb_FiringRainbowBeam_4_ExtendNeckDown(void);
void MotherBomb_FiringRainbowBeam_5_StartFiring(void);
void MotherBomb_FiringRainbowBeam_6_MoveSamusToWall(void);
void MotherBomb_FiringRainbowBeam_7_DelayFrame(void);
void MotherBomb_FiringRainbowBeam_8_StartDrainSamus(void);
void MotherBomb_FiringRainbowBeam_9_DrainingSamus(void);
void MotherBrainBody_0_Wait(void);
void MotherBrainBody_10_ClearCeilingTubeColumn7(void);
void MotherBrainBody_11_SpawnTopMiddleRightFalling(void);
void MotherBrainBody_12_ClearCeilingTubeColumn8(void);
void MotherBrainBody_13_SpawnTubeFallingEnemy3(void);
void MotherBrainBody_14_ClearBottomMiddleRightTube(void);
void MotherBrainBody_15_SpawnTubeFallingEnemy4(void);
void MotherBrainBody_16_ClearBottomMiddleTubes(void);
void MotherBrainBody_1_ClearBottomLeftTube(void);
void MotherBrainBody_2_SpawnTopRightTubeFalling(void);
void MotherBrainBody_2ndphase_16_ShakeHeadMenacingly(void);
void MotherBrainBody_2ndphase_17_BringHeadBackUp(void);
void MotherBrainBody_2ndphase_18_FinishStretching(void);
void MotherBrainBody_3_ClearCeilingBlock9(void);
void MotherBrainBody_4_ClearCeilingBlock6(void);
void MotherBrainBody_4_SpawnTopLeftTubeFalling(void);
void MotherBrainBody_5_SpawnTubeFallingEnemy1(void);
void MotherBrainBody_6_ClearBottomRightTube(void);
void MotherBrainBody_7_SpawnTubeFallingEnemy2(void);
void MotherBrainBody_8_ClearBottomMiddleLeftTube(void);
void MotherBrainBody_9_SpawnTopMiddleLeftFalling(void);
void MotherBrainBody_FakeDeath_Ascent_0_DrawBG1Row23(void);
void MotherBrainBody_FakeDeath_Ascent_10_LoadLegTiles(void);
void MotherBrainBody_FakeDeath_Ascent_11_ContinuePause(void);
void MotherBrainBody_FakeDeath_Ascent_12_StartMusic(void);
void MotherBrainBody_FakeDeath_Ascent_13_Raise(void);
void MotherBrainBody_FakeDeath_Ascent_14_WaitForUncouching(void);
void MotherBrainBody_FakeDeath_Ascent_15_TransitionFromGrey(void);
void MotherBrainBody_FakeDeath_Ascent_1_DrawBG1Row45(void);
void MotherBrainBody_FakeDeath_Ascent_2_DrawBG1Row67(void);
void MotherBrainBody_FakeDeath_Ascent_3_DrawBG1Row89(void);
void MotherBrainBody_FakeDeath_Ascent_4_DrawBG1RowAB(void);
void MotherBrainBody_FakeDeath_Ascent_5_DrawBG1RowCD(void);
void MotherBrainBody_FakeDeath_Ascent_6_SetupPhase2Gfx(void);
void MotherBrainBody_FakeDeath_Ascent_7_SetupPhase2Brain(void);
void MotherBrainBody_FakeDeath_Ascent_8_Pause(void);
void MotherBrainBody_FakeDeath_Ascent_9_PrepareRise(void);
void MotherBrainBody_FakeDeath_Descent_0_Pause(void);
void MotherBrainBody_FakeDeath_Descent_1(void);
void MotherBrainBody_FakeDeath_Descent_2(void);
void MotherBrainBody_FakeDeath_Descent_3(void);
void MotherBrainBody_FakeDeath_Descent_4(void);
void MotherBrainBody_FakeDeath_Descent_5(void);
void MotherBrainBody_FakeDeath_Descent_6(void);
void MotherBrain_AddSpritemapToOam(uint16 j, uint16 r18, uint16 r20, uint16 r22);
void MotherBrain_AimBeam(void);
void MotherBrain_AimBeamAndIncrWidth(void);
void MotherBrain_B7CB(void);
void MotherBrain_BodyRainbowBeamPalAnimIndex0(void);
void MotherBrain_Body_Phase2_Thinking(void);
void MotherBrain_Body_Phase2_TryAttack(void);
void MotherBrain_CalculateRainbowBeamHdma(void);
void MotherBrain_CalculateRainbowBeamHdma_(void);
void MotherBrain_CorpseRottingCopyFunc(uint16 j, uint16 k);
void MotherBrain_CorpseRottingFinished(void);
void MotherBrain_CorpseRottingInitFunc(void);
void MotherBrain_CorpseRottingMoveFunc(uint16 j, uint16 k);
void MotherBrain_DrainedByShitroid_0(void);
void MotherBrain_DrainedByShitroid_1(void);
void MotherBrain_DrainedByShitroid_2(void);
void MotherBrain_DrainedByShitroid_3(void);
void MotherBrain_DrainedByShitroid_4(void);
void MotherBrain_DrainedByShitroid_5(void);
void MotherBrain_DrainedByShitroid_6(void);
void MotherBrain_DrainedByShitroid_7(void);
void MotherBrain_DrawBrain(void);
void MotherBrain_DrawBrainNeck_EnemyGfxDrawHook(void);
void MotherBrain_DrawNeck(void);
void MotherBrain_DrawNeckSegment(uint16 x, uint16 y);
void MotherBrain_ExplodeEscapeDoor(void);
void MotherBrain_FiringBomb_Crouch(void);
void MotherBrain_FiringBomb_DecideOnCrouching(void);
void MotherBrain_FiringBomb_DecideOnWalking(void);
void MotherBrain_FiringBomb_Finish(void);
void MotherBrain_FiringBomb_Fired(void);
void MotherBrain_FiringBomb_Standup(void);
void MotherBrain_FiringBomb_WalkingBackwards(void);
void MotherBrain_FootstepEffect(void);
void MotherBrain_GenerateEscapeDoorExploding(void);
void MotherBrain_GenerateExplosions(uint16 a, uint16 r22, uint16 r24);
void MotherBrain_GenerateMixedExplosions(void);
void MotherBrain_GenerateSmokyExplosions(void);
void MotherBrain_HandleBrainPal(void);
void MotherBrain_HandleFakeDeathExplosions(void);
void MotherBrain_HandleNeck(void);
void MotherBrain_HandleNeckLower(void);
void MotherBrain_HandleNeckLower_0(void);
void MotherBrain_HandleNeckLower_2_BobDown(void);
void MotherBrain_HandleNeckLower_4_BobUp(void);
void MotherBrain_HandleNeckLower_6_Lower(void);
void MotherBrain_HandleNeckLower_8_Raise(void);
void MotherBrain_HandleNeckUpper(void);
void MotherBrain_HandlePalette(void);
void MotherBrain_HandleRainbowBeamExplosions(void);
void MotherBrain_HandleRainbowBeamPalette(void);
void MotherBrain_HandleWalking(void);
void MotherBrain_HurtSamus(void);
void MotherBrain_Instr_AimRings(uint16 x, uint16 y);
void MotherBrain_MaybeStandupOrLeanDown(void);
void MotherBrain_MoveBodyDown(uint16 a);
void MotherBrain_MoveBodyDownScrollLeft(uint16 k, uint16 a);
void MotherBrain_MoveSamusTowardsMiddleOfWall(void);
void MotherBrain_PainfulWalkBackwards(void);
void MotherBrain_PainfulWalkForwards(void);
void MotherBrain_PainfulWalkingBackwards(void);
void MotherBrain_PainfulWalkingForwards(void);
void MotherBrain_Pal_BeginScreenFlash(void);
void MotherBrain_Pal_EndScreenFlash(void);
void MotherBrain_Pal_HandleRoomPal(void);
void MotherBrain_Pal_ProcessInvincibility(void);
void MotherBrain_Pal_WriteRoomPal(uint16 j);
void MotherBrain_Phase23_ShotReaction(void);
void MotherBrain_Phase2Cut_0(void);
void MotherBrain_Phase2Cut_1(void);
void MotherBrain_Phase2Cut_2(void);
void MotherBrain_Phase2Cut_3(void);
void MotherBrain_Phase2Cut_4(void);
void MotherBrain_Phase2Cut_5(void);
void MotherBrain_Phase2_Attack_Cooldown(void);
void MotherBrain_Phase2_Attack_End(void);
void MotherBrain_Phase2_ExecuteFinalkShitroid(void);
void MotherBrain_Phase2_MurderShitroid_1(void);
void MotherBrain_Phase2_MurderShitroid_2(void);
void MotherBrain_Phase2_PrepareForFinalShitroid(void);
void MotherBrain_Phase2_Revive_0(void);
void MotherBrain_Phase2_Revive_1(void);
void MotherBrain_Phase2_Revive_2(void);
void MotherBrain_Phase2_Revive_3(void);
void MotherBrain_Phase2_Revive_4(void);
void MotherBrain_Phase2_Revive_5(void);
void MotherBrain_Phase2_Revive_6(void);
void MotherBrain_Phase2_Revive_7(void);
void MotherBrain_Phase2_Revive_8(void);
void MotherBrain_Phase3_BeamShotReaction(void);
void MotherBrain_Phase3_Death_0(void);
void MotherBrain_Phase3_Death_1(void);
void MotherBrain_Phase3_Death_10(void);
void MotherBrain_Phase3_Death_11(void);
void MotherBrain_Phase3_Death_12(void);
void MotherBrain_Phase3_Death_13(void);
void MotherBrain_Phase3_Death_14_20framedelay(void);
void MotherBrain_Phase3_Death_15_LoadEscapeTimerTiles(void);
void MotherBrain_Phase3_Death_16_StartEscape(void);
void MotherBrain_Phase3_Death_17_SpawnTimeBomb(void);
void MotherBrain_Phase3_Death_18_TypesZebesText(void);
void MotherBrain_Phase3_Death_19_EscapeDoorExploding(void);
void MotherBrain_Phase3_Death_2(void);
void MotherBrain_Phase3_Death_20_BlowUpEscapeDoor(void);
void MotherBrain_Phase3_Death_21_KeepEarthquakeGoing(void);
void MotherBrain_Phase3_Death_3(void);
void MotherBrain_Phase3_Death_4(void);
void MotherBrain_Phase3_Death_5(void);
void MotherBrain_Phase3_Death_6(void);
void MotherBrain_Phase3_Death_7(void);
void MotherBrain_Phase3_Death_8(void);
void MotherBrain_Phase3_Death_9(void);
void MotherBrain_Phase3_Fighting_Cooldown(void);
void MotherBrain_Phase3_Fighting_Main(void);
void MotherBrain_Phase3_NeckHandler(void);
void MotherBrain_Phase3_Neck_HyperBeamRecoil(void);
void MotherBrain_Phase3_Neck_Normal(void);
void MotherBrain_Phase3_Neck_RecoilRecovery(void);
void MotherBrain_Phase3_Neck_SetupHyperBeamRecoil(void);
void MotherBrain_Phase3_Neck_SetupRecoilRecovery(void);
void MotherBrain_Phase3_Recover_MakeDistance(void);
void MotherBrain_Phase3_Recover_SetupForFight(void);
void MotherBrain_Phase3_WalkHandler(void);
void MotherBrain_Phase3_Walk_RetreatQuickly(void);
void MotherBrain_Phase3_Walk_RetreatSlowly(void);
void MotherBrain_Phase3_Walk_TryToInchForward(void);
void MotherBrain_PlayRainbowBeamSfx(void);
void MotherBrain_RetractHead(void);
void MotherBrain_SamusCollDetect(void);
void MotherBrain_SetBodyInstrs(uint16 a);
void MotherBrain_SetBrainInstrs(uint16 a);
void MotherBrain_SetBrainUnusedInstrs(uint16 a);
void MotherBrain_SetPainfulWalkingTimer(void);
void MotherBrain_SetToTryToInchForward(uint16 a);
void MotherBrain_SetupBrainNormalPal(void);
void MotherBrain_SetupBrainPalForLaser(void);
void MotherBrain_SetupNeckForFakeAscent(void);
void MotherBrain_SpawnDustCloudsForAscent(void);
void MotherBrain_SpawnShitroidInCutscene(void);
void MotherBrain_WriteDefaultPalette(void);
void MotherBrain_WritePalette(uint16 j);
void MotherBrain_WritePhase2DeathPalette(void);
void MotherBrainsBody_FirstPhase_DoubleRet(void);
void MotherBrainsBody_Hurt(void);
void MotherBrainsBody_Init(void);
void MotherBrainsBody_Powerbomb(void);
void MotherBrainsBody_Shot(void);
CoroutineRet MotherBrainsBody_UnpauseHook(void);
void MotherBrainsBrain_GfxDrawHook(void);
void MotherBrainsBrain_Hurt(void);
void MotherBrainsBrain_Init(void);
void MotherBrainsBrain_SetupBrainAndNeckToDraw(void);
void MotherBrainsBrain_SetupBrainToDraw(void);
void MotherBrainsBrain_Shot(void);
void MotherBrainsBrain_Touch(void);
void MotherBrainsTubesFalling_Explode(uint16 k);
void MotherBrainsTubesFalling_Falling(uint16 k);
void MotherBrainsTubesFalling_HandleSmoke(uint16 k);
void MotherBrainsTubesFalling_Init(void);
void MotherBrainsTubesFalling_Main(uint16 k);
void MotherBrainsTubesFalling_Main_NonMain(uint16 k);
void MotherBrainsTubesFalling_SpawnSmoke(uint16 k);
void MotherBrainsTubesFalling_WaitToFall(uint16 k);
void MoveEnemyWithVelocity(void);
void ProcessCorpseRottingVramTransfers(uint16 k);
void Ripper_CorpseRottingCopyFunc_0(uint16 j, uint16 k);
void Ripper_CorpseRottingCopyFunc_2(uint16 j, uint16 k);
void Ripper_CorpseRottingInitFunc_0(void);
void Ripper_CorpseRottingInitFunc_2(void);
void Ripper_CorpseRottingMoveFunc_0(uint16 j, uint16 k);
void Ripper_CorpseRottingMoveFunc_2(uint16 j, uint16 k);
void SamusRainbowPaletteFunc_ActivateWhenEnemyLow(uint16 k);
void SamusRainbowPaletteFunc_GraduallySlowDown(void);
void Samus_DamageDueToRainbowBeam(void);
void Samus_DamageDueToShitroid(void);
void Samus_DecrementAmmoDueToRainbowBeam(void);
void Samus_PlayGainingLosingHealthSfx(void);
void ShitroidInCutscene_AccelerateDownwards(uint16 k);
void ShitroidInCutscene_ActivateRainbowBeam(uint16 k);
void ShitroidInCutscene_BrainTurnsToCorpse(uint16 k);
void ShitroidInCutscene_CurveTowardsBrain(uint16 k);
void ShitroidInCutscene_DashOntoScreen(uint16 k);
void ShitroidInCutscene_DeathSequence(uint16 k);
void ShitroidInCutscene_FinalCharge(uint16 k);
void ShitroidInCutscene_FinishCutscene(uint16 k);
void ShitroidInCutscene_Flashing(uint16 k);
void ShitroidInCutscene_FlyOffScreen(uint16 k);
void ShitroidInCutscene_GetIntoFace(uint16 k);
void ShitroidInCutscene_HandleCry(void);
void ShitroidInCutscene_HandleEnemyBlinking(uint16 k);
void ShitroidInCutscene_HandleHealthBasedPalette(uint16 k);
void ShitroidInCutscene_HandleShitroidDeathExplosions(uint16 k);
void ShitroidInCutscene_HealSamusToFullHealth(uint16 k);
void ShitroidInCutscene_IdleUntilToNoHealth(uint16 k);
void ShitroidInCutscene_Init(void);
void ShitroidInCutscene_InitiateFinalCharge(uint16 k);
void ShitroidInCutscene_LatchOntoBrain(uint16 k);
void ShitroidInCutscene_LatchOntoSamus(uint16 k);
void ShitroidInCutscene_LetGoAndSpawnDust(uint16 k);
void ShitroidInCutscene_LetSamusRainbowMore(uint16 k);
void ShitroidInCutscene_Main(void);
void ShitroidInCutscene_MoveToFinalChargeStart(uint16 k);
void ShitroidInCutscene_MoveToSamus(uint16 k);
void ShitroidInCutscene_MoveUpToCeiling(uint16 k);
void ShitroidInCutscene_PlaySamusTheme(uint16 k);
void ShitroidInCutscene_PrepareSamusHyperbeam(uint16 k);
void ShitroidInCutscene_ReleaseSamus(uint16 k);
void ShitroidInCutscene_SetMotherBrainToStumbleBack(uint16 k);
void ShitroidInCutscene_Shake(uint16 k);
void ShitroidInCutscene_ShitroidFinalBelow(uint16 k);
void ShitroidInCutscene_SpawnThreeDustClouds(void);
void ShitroidInCutscene_StareDownMotherBrain(uint16 k);
void ShitroidInCutscene_StopDraining(uint16 k);
void ShitroidInCutscene_Touch(void);
void ShitroidInCutscene_UnloadShitroid(uint16 k);
void ShitroidInCutscene_UpdateSpeedAndAngle(uint16 k, uint16 r18, uint16 r20, uint16 r22);
uint16 Shitroid_AccelerateTowardsX(uint16 k, uint16 r18, uint16 r22);
uint16 Shitroid_AccelerateTowardsY(uint16 k, uint16 r20, uint16 r22);
void Shitroid_F3C4(uint16 k);
void Shitroid_Func_10(uint16 k);
void Shitroid_Func_11(uint16 k);
void Shitroid_Func_12(uint16 k);
void Shitroid_Func_13(uint16 k);
void Shitroid_Func_14(uint16 k);
void Shitroid_Func_15(uint16 k);
void Shitroid_Func_16(uint16 k);
void Shitroid_Func_17(uint16 k);
void Shitroid_Func_18(uint16 k);
void Shitroid_Func_19(uint16 k);
void Shitroid_Func_20(void);
void Shitroid_Func_21(void);
void Shitroid_Func_22(uint16 k);
void Shitroid_Func_23(void);
void Shitroid_Func_24(uint16 k);
void Shitroid_Func_25(uint16 k);
void Shitroid_Func_26(uint16 k);
void Shitroid_Func_3(uint16 k);
void Shitroid_Func_4(void);
void Shitroid_Func_5(uint16 k);
void Shitroid_Func_6(uint16 k);
void Shitroid_Func_7(uint16 k);
void Shitroid_Func_8(uint16 k);
void Shitroid_Func_9(uint16 k);
void Shitroid_Func_GraduallyAccelerateTowards0x400(uint16 k, uint16 j, uint16 r18, uint16 r20);
void Shitroid_GraduallyAccelerateHoriz(uint16 k, uint16 r18, uint16 r24, uint16 r26);
void Shitroid_GraduallyAccelerateTowards0x10(uint16 k, uint16 j, uint16 r18, uint16 r20);
void Shitroid_GraduallyAccelerateTowards0x4(uint16 k, uint16 j, uint16 r18, uint16 r20);
void Shitroid_GraduallyAccelerateTowards0x8(uint16 k, uint16 j, uint16 r18, uint16 r20);
void Shitroid_GraduallyAccelerateTowardsPt(uint16 k, uint16 j, uint16 r18, uint16 r20, uint16 r26);
void Shitroid_HandleCutscenePalette(void);
void Shitroid_HandleCutscenePalette_Common(uint16 r22, uint16 r18);
void Shitroid_HandleCutscenePalette_LowHealth(void);
void Shitroid_HandleNormalPalette(void);
void Shitroid_Init(void);
void Shitroid_Main(void);
void Shitroid_Powerbomb(void);
void Shitroid_Shot(void);
void Shitroid_Touch(void);
void Sidehopper_CorpseRottingCopyFunc_0(uint16 j, uint16 k);
void Sidehopper_CorpseRottingCopyFunc_2(uint16 j, uint16 k);
void Sidehopper_CorpseRottingInitFunc_0(void);
void Sidehopper_CorpseRottingInitFunc_2(void);
void Sidehopper_CorpseRottingMoveFunc_0(uint16 j, uint16 k);
void Sidehopper_CorpseRottingMoveFunc_2(uint16 j, uint16 k);
void Skree_CorpseRottingCopyFunc_0(uint16 j, uint16 k);
void Skree_CorpseRottingCopyFunc_2(uint16 j, uint16 k);
void Skree_CorpseRottingCopyFunc_4(uint16 j, uint16 k);
void Skree_CorpseRottingInitFunc_0(void);
void Skree_CorpseRottingInitFunc_2(void);
void Skree_CorpseRottingInitFunc_4(void);
void Skree_CorpseRottingMoveFunc_0(uint16 j, uint16 k);
void Skree_CorpseRottingMoveFunc_2(uint16 j, uint16 k);
void Skree_CorpseRottingMoveFunc_4(uint16 j, uint16 k);
void Torizo_CorpseRottingCopyFunc(uint16 j, uint16 k);
void Torizo_CorpseRottingInitFunc(void);
void Torizo_CorpseRottingMoveFunc(uint16 j, uint16 k);
void WriteColorsToPalette(uint16 k, uint8 db, uint16 j, uint16 a);
void WriteColorsToTargetPalette(uint8 db, uint16 k, uint16 j, uint16 a);
void Zoomer_CorpseRottingCopyFunc_0(uint16 j, uint16 k);
void Zoomer_CorpseRottingCopyFunc_2(uint16 j, uint16 k);
void Zoomer_CorpseRottingCopyFunc_4(uint16 j, uint16 k);
void Zoomer_CorpseRottingInitFunc_0(void);
void Zoomer_CorpseRottingInitFunc_2(void);
void Zoomer_CorpseRottingInitFunc_4(void);
void Zoomer_CorpseRottingMoveFunc_0(uint16 j, uint16 k);
void Zoomer_CorpseRottingMoveFunc_2(uint16 j, uint16 k);
void Zoomer_CorpseRottingMoveFunc_4(uint16 j, uint16 k);

// Bank AA
const uint16 *Enemy_ClearAiPreInstr_AA(uint16 k, const uint16 *jp);
const uint16 *Enemy_SetAiPreInstr_AA(uint16 k, const uint16 *jp);
const uint16 *Shaktool_D956(uint16 k, const uint16 *j, uint16 a);
const uint16 *Shaktool_Instr_1(uint16 k, const uint16 *jp);
const uint16 *Shaktool_Instr_10(uint16 k, const uint16 *jp);
const uint16 *Shaktool_Instr_11(uint16 k, const uint16 *jp);
const uint16 *Shaktool_Instr_12(uint16 k, const uint16 *jp);
const uint16 *Shaktool_Instr_13(uint16 k, const uint16 *jp);
const uint16 *Shaktool_Instr_14(uint16 k, const uint16 *jp);
const uint16 *Shaktool_Instr_2(uint16 k, const uint16 *jp);
const uint16 *Shaktool_Instr_3(uint16 k, const uint16 *jp);
const uint16 *Shaktool_Instr_4(uint16 k, const uint16 *jp);
const uint16 *Shaktool_Instr_5(uint16 k, const uint16 *jp);
const uint16 *Shaktool_Instr_6(uint16 k, const uint16 *jp);
const uint16 *Shaktool_Instr_7(uint16 k, const uint16 *jp);
const uint16 *Shaktool_Instr_8(uint16 k, const uint16 *jp);
const uint16 *Shaktool_Instr_9(uint16 k, const uint16 *jp);
uint16 Torizo_Func_12(uint16 k);
const uint16 *Torizo_Instr_1(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_10(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_11(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_12(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_13(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_14(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_15(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_16(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_17(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_18(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_19(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_2(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_20(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_21(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_22(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_23(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_24(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_25(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_26(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_27(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_28(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_29(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_3(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_30(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_31(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_32(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_33(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_34(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_35(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_36(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_37(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_38(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_39(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_4(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_40(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_41(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_42(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_43(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_44(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_45(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_46(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_47(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_48(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_49(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_5(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_50(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_51(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_52(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_53(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_54(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_55(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_56(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_57(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_58(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_59(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_6(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_60(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_61(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_62(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_63(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_7(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_8(uint16 k, const uint16 *jp);
const uint16 *Torizo_Instr_9(uint16 k, const uint16 *jp);
void ChozoStatue_Init(void);
void ChozoStatue_Main(void);
void Enemy_GrappleReact_CancelBeam_AA(void);
void Enemy_NormalFrozenAI_AA(void);
void GoldTorizo_Hurt(void);
void GoldTorizo_Main(void);
void GoldTorizo_Shot(void);
void GoldTorizo_Touch(void);
void N00bTubeCracks_Init(void);
void Shaktool_DAE5(uint16 k);
void Shaktool_DB0E(uint16 k, uint16 a);
void Shaktool_DB27(uint16 k, uint16 a);
void Shaktool_DB40(uint16 k, uint16 a);
void Shaktool_DB59(uint16 k);
void Shaktool_DC07(uint16 k);
void Shaktool_DC2A(uint16 k);
void Shaktool_DC6F(uint16 k);
void Shaktool_DCAC(uint16 k);
void Shaktool_DCD7(uint16 k);
void Shaktool_DD25(uint16 k);
void Shaktool_Hurt(void);
void Shaktool_Init(void);
void Shaktool_PreInstr_0(uint16 k);
void Shaktool_Shot(void);
void Shaktool_Touch(void);
void Torizo_C20A(uint16 k);
void Torizo_C22D(uint16 k);
void Torizo_C250(void);
void Torizo_C268(void);
void Torizo_C280(void);
void Torizo_C298(void);
void Torizo_C2B0(void);
void Torizo_C620(uint16 k);
void Torizo_C643(uint16 k);
void Torizo_D5E6(uint16 k);
void Torizo_D5ED(uint16 k);
void Torizo_D5F1(uint16 k);
void Torizo_D658(void);
void Torizo_D6A6(void);
void Torizo_D6D1(uint16 k, uint16 j);
void Torizo_D6F7(uint16 k, uint16 j);
void Torizo_Func_1(uint16 k);
void Torizo_Func_10(uint16 k);
void Torizo_Func_11(uint16 k);
void Torizo_Func_2(uint16 k);
void Torizo_Func_3(uint16 k);
void Torizo_Func_4(uint16 k);
void Torizo_Func_5(uint16 k);
void Torizo_Func_6(uint16 k);
void Torizo_Func_7(uint16 k);
void Torizo_Func_8(void);
void Torizo_Func_9(uint16 k);
void Torizo_Hurt(void);
void Torizo_Init(void);
void Torizo_Main(void);
void Torizo_Shot(void);
void TourianEntranceStatue_Init(void);
void sub_AAE445(uint16 k);
void sub_AAE784(void);

// Bank AD
uint8 MotherBrain_FadeToFromGray_FakeDeath(uint16 a);
uint8 MotherBrain_FadeFromGray_Drained(uint16 a);
uint8 MotherBrain_FadeFromGray_FakeDeath(uint16 a);
uint8 MotherBrain_FadePalToBlack(uint16 a);
uint8 MotherBrain_FadeToGray_Drained(uint16 a);
uint8 MotherBrain_FadeToGray_FakeDeath(uint16 a);
uint8 MotherBrain_FadeToGray_RealDeath(uint16 a);
uint8 MotherBrain_Phase3_TurnLightsBackOn(uint16 a);
void EnableEarthquakeTypeAFor20Frames(uint16 a);
void HandleMotherBrainBodyFlickering(void);
void MotherBrain_CalcHdma(void);
void MotherBrain_CalcHdma_Right_Right(uint16 r22, uint16 r24);
void MotherBrain_CalcHdma_BeamAimedRight(void);
void MotherBrain_CalcHdma_BeamAimedUp(void);
void MotherBrain_CalcHdma_BeamAimedDown(void);
void MotherBrain_CalcHdma_Down_Down(uint16 r22, uint16 r24);
void MotherBrain_CalcHdma_Down_DownLeft(uint16 r22, uint16 r24);
void MotherBrain_CalcHdma_Down_DownRight(uint16 r22, uint16 r24);
void MotherBrain_CalcHdma_Up_Up(uint16 r22, uint16 r24);
void MotherBrain_CalcHdma_Up_UpLeft(uint16 r22, uint16 r24);
void MotherBrain_CalcHdma_Up_UpRight(uint16 r22, uint16 r24);
void MotherBrain_HealthBasedPaletteHandling(void);
void MotherBrain_SealWall(void);
void TurnOffLightsForShitroidDeath(void);

// Bank B2
uint16 NinjaSpacePirates_StandKickTrigger(void);
uint16 NinjaSpacePirates_FlinchTrigger(void);
uint16 NinjaSpacePirates_SpinJumpTrigger(void);
const uint16 *WalkingSpacePirates_Instr_SetEnemyFunc(uint16 k, const uint16 *jp);
const uint16 *WalkingSpacePirates_Instr_FireLaserLOffsetY(uint16 k, const uint16 *jp);
const uint16 *WalkingSpacePirates_Instr_ChooseDir_FireLaserIfClose(uint16 k, const uint16 *jp);
const uint16 *WalkingSpacePirates_Instr_FireLaserROffsetY(uint16 k, const uint16 *jp);
const uint16 *NinjaSpacePirates_Instr_SpawnEprojPirateClaw(uint16 k, const uint16 *jp);
const uint16 *NinjaSpacePirates_Instr_QueueSfx2_Max6(uint16 k, const uint16 *jp);
const uint16 *NinjaSpacePirates_Instr_ResetXSpeed(uint16 k, const uint16 *jp);
const uint16 *NinjaSpacePirates_Instr_SetAiActive(uint16 k, const uint16 *jp);
const uint16 *NinjaSpacePirates_Instr_InitDivekickLJumpYSpeed(uint16 k, const uint16 *jp);
const uint16 *NinjaSpacePirates_Instr_SetPaletteIndex(uint16 k, const uint16 *jp);
const uint16 *NinjaSpacePirates_Instr_InitDivekickRJumpYSpeed(uint16 k, const uint16 *jp);
const uint16 *WallSpacePirates_Instr_FireLaserL(uint16 k, const uint16 *jp);
const uint16 *WallSpacePirates_Instr_FireLaserR(uint16 k, const uint16 *jp);
const uint16 *WallSpacePirates_Instr_MovePixelsDownAndChangeDirFaceLeft(uint16 k, const uint16 *jp);
const uint16 *WallSpacePirates_Instr_MovePixelsDownAndChangeDirFaceRight(uint16 k, const uint16 *jp);
const uint16 *WallSpacePirates_Instr_PlaySpacePirateAttackSfx(uint16 k, const uint16 *jp);
const uint16 *WallSpacePirates_Instr_PrepareWallJumpL(uint16 k, const uint16 *jp);
const uint16 *WallSpacePirates_Instr_PrepareWallJumpR(uint16 k, const uint16 *jp);
const uint16 *WallSpacePirates_Instr_RandomNewDirFaceL(uint16 k, const uint16 *jp);
const uint16 *WallSpacePirates_Instr_RandomNewDirFaceR(uint16 k, const uint16 *jp);
const uint16 *WallSpacePirates_Instr_SetEnemyFunc(uint16 k, const uint16 *jp);
void Enemy_GrappleReact_CancelBeam_B2(void);
void Enemy_NormalFrozenAI_B2(void);
void NinjaSpacePirates_Init(void);
void NinjaSpacePirates_Main(void);
void NinjaSpacePirates_Func_DivekickL_Jump(uint16 k);
void NinjaSpacePirates_Func_DivekickL_Divekick(uint16 k);
void NinjaSpacePirates_Func_DivekickL_WalkToLeftPost(uint16 k);
void NinjaSpacePirates_Func_DivekickR_Jump(uint16 k);
void NinjaSpacePirates_Func_DivekickR_Divekick(uint16 k);
void NinjaSpacePirates_Func_DivekickR_WalkToRightPost(uint16 k);
void NinjaSpacePirates_SpawnLandingDustCloud(uint16 k);
void WallSpacePirates_Func_ClimbLWall(uint16 k);
void NinjaSpacePirates_Func_SpinJumpL_Rise(uint16 k);
void NinjaSpacePirates_Func_SpinJumpL_Fall(uint16 k);
void NinjaSpacePirates_Func_SpinJumpR_Rise(uint16 k);
void NinjaSpacePirates_Func_SpinJumpR_Fall(uint16 k);
void NinjaSpacePirates_Func_DivekickReady(uint16 k);
void NinjaSpacePirates_DivekickTrigger(void);
void WallSpacePirates_Func_WallJumpR(uint16 k);
void WallSpacePirates_Func_ClimbRWall(uint16 k);
void WallSpacePirates_Func_WallJumpL(uint16 k);
void NinjaSpacePirates_Func_Initial(uint16 k);
void NinjaSpacePirates_Func_Active(uint16 k);
void NinjaSpacePirates_ProjClawAttackTrigger(uint16 k);
void SpacePirates_NormalShot(void);
void SpacePirates_Shot_LowerNorfairPirateVulnerable(void);
void SpacePirates_Shot_LowerNorfairPirateInvincible(void);
void WalkingSpacePirates_Func_WalkL(void);
void WalkingSpacePirates_Func_WalkR(void);
void WalkingSpacePirates_FlinchTrigger(void);
void WalkingSpacePirates_Init(void);
void WalkingSpacePirates_Main(void);
void SpacePirates_Powerbomb(void);
void SpacePirates_ShotAi(void);
void SpacePirates_TouchAi(void);
void WallSpacePirates_Init(void);
void WallSpacePirates_Main(void);
void NinjaSpacePirates_Instr_GoToEnemy_Unused(void);
void NinjaSpacePirates_Instr_SetAiStandKick_Unused(void);

// Bank B3
const uint16 *Botwoon_Instr_AimUpRadius8x16Unused(uint16 k, const uint16 *jp);
const uint16 *Botwoon_Instr_AimUpRadius8x16(uint16 k, const uint16 *jp);
const uint16 *Botwoon_Instr_AimUpLeftRadius12x12(uint16 k, const uint16 *jp);
const uint16 *Botwoon_Instr_AimLeftRadius16x8(uint16 k, const uint16 *jp);
const uint16 *Botwoon_Instr_AimDownLeftRadius12x12(uint16 k, const uint16 *jp);
const uint16 *Botwoon_Instr_AimDownRadius8x16Unused(uint16 k, const uint16 *jp);
const uint16 *Botwoon_Instr_AimDownRadius8x16(uint16 k, const uint16 *jp);
const uint16 *Botwoon_Instr_AimDownRightRadius12x12(uint16 k, const uint16 *jp);
const uint16 *Botwoon_Instr_AimRightRadius16x8(uint16 k, const uint16 *jp);
const uint16 *Botwoon_Instr_AimUprightRadius12x12(uint16 k, const uint16 *jp);
const uint16 *Botwoon_Instr_QueueSpitSfx(uint16 k, const uint16 *jp);
const uint16 *Botwoon_Instr_SetSpitting(uint16 k, const uint16 *jp);
const uint16 *Enemy_ClearAiPreInstr_B3(uint16 k, const uint16 *jp);
const uint16 *Enemy_SetAiPreInstr_B3(uint16 k, const uint16 *jp);
const uint16 *EscapeDachora_Instr_MoveLeft(uint16 k, const uint16 *jp);
const uint16 *EscapeDachora_Instr_MoveIfAcid(uint16 k, const uint16 *jp);
const uint16 *EscapeDachora_Instr_MoveIfCrittersEscaped(uint16 k, const uint16 *jp);
const uint16 *EscapeDachora_Instr_MoveRight(uint16 k, const uint16 *jp);
const uint16 *EscapeEtecoon_Instr_MoveIfAcid(uint16 k, const uint16 *jp);
const uint16 *EscapeEtecoon_Instr_MoveTo(uint16 k, const uint16 *jp);
void Botwoon_Func_1(uint16 k);
void Botwoon_Func_ChooseMovementPath(uint16 k);
void Botwoon_Func_SetSpeed(uint16 k);
void Botwoon_Func_MoveAround(void);
void Botwoon_Func_Spit(void);
void Botwoon_Func_PreDeathDelay(void);
void Botwoon_Func_FallToGround(void);
void Botwoon_Func_WaitForBodyToFall(void);
void Botwoon_Func_SpawnCrumbleWall(uint16 k);
void Botwoon_Func_CrumbleWall(uint16 k);
void Botwoon_Func_MoveToTargetHole(void);
void Botwoon_Func_2(void);
Point16U Botwoon_Func_GetOffsetToHole(uint16 k);
void Botwoon_Func_MoveToTargeHoleByAngleAndSpeed(void);
void Botwoon_Func_UpdatePositionHistory(void);
void Botwoon_Func_UpdateBodyPositions(void);
void Botwoon_Func_UpdatePositionHistoryIndex(void);
void Botwoon_Func_SetBodyTableIndexes(void);
void Botwoon_Func_MoveHeadAround(uint16 k);
void Botwoon_Func_SetSpitAngle(uint16 k);
void Botwoon_Func_SpawnFiveSpitProjectiles(uint16 k);
void Botwoon_Func_SpawnThreeSpitProjectiles(uint16 k);
void Botwoon_Func_CheckDeath(void);
void Botwoon_Func_CooldownSpit(uint16 k);
void Botwoon_Func_CollisionDetection(uint16 k);
void Botwoon_Func_StartMovementUsingData(void);
void Botwoon_Func_MoveUsingData(void);
void Botwoon_Func_SetIntangible(void);
void Botwoon_Func_5(void);
void Botwoon_Func_Initialize(void);
void Botwoon_Func_GoInHole(void);
void Botwoon_Func_SetUpMovement(void);
void Botwoon_Func_SetUpSpit(void);
void Botwoon_HealthBasedPalHandling(void);
void Botwoon_Init(void);
void Botwoon_Main(void);
void Botwoon_Powerbomb(void);
void Botwoon_QueueExplosionSfx(void);
void Botwoon_Shot(void);
void Botwoon_Touch(void);
void BrinstarPipeBug_Func_SetInstrList(void);
void BrinstarPipeBug_Init(void);
void BrinstarPipeBug_Main(void);
void BrinstarPipeBug_PreInstr_1(uint16 k);
void BrinstarPipeBug_PreInstr_2(uint16 k);
void BrinstarPipeBug_PreInstr_3(uint16 k);
void BrinstarPipeBug_PreInstr_4(uint16 k);
void BrinstarPipeBug_PreInstr_5(uint16 k);
void BrinstarYellowPipeBug_Func_1(void);
void BrinstarYellowPipeBug_Func_10(uint16 k);
void BrinstarYellowPipeBug_Func_2(uint16 k);
void BrinstarYellowPipeBug_Func_3(void);
void BrinstarYellowPipeBug_Func_4(uint16 k);
void BrinstarYellowPipeBug_Func_5(void);
void BrinstarYellowPipeBug_Func_6(uint16 k);
void BrinstarYellowPipeBug_Func_7(void);
void BrinstarYellowPipeBug_Func_8(void);
void BrinstarYellowPipeBug_Func_9(uint16 k);
void BrinstarYellowPipeBug_Init(void);
void BrinstarYellowPipeBug_Main(void);
void Enemy_GrappleReact_CancelBeam_B3(void);
void Enemy_GrappleReact_KillEnemy_B3(void);
void Enemy_GrappleReact_NoInteract_B3(void);
void Enemy_NormalFrozenAI_B3(void);
void Enemy_NormalPowerBombAI_SkipDeathAnim_B3(void);
void Enemy_NormalShotAI_B3(void);
void Enemy_NormalShotAI_SkipSomeParts_B3(void);
void Enemy_NormalTouchAI_B3(void);
void Enemy_NormalTouchAI_SkipDeathAnim_B3(void);
void EscapeDachora_Init(void);
void EscapeEtecoon_E65C(uint16 k);
void EscapeEtecoon_E670(uint16 k);
void EscapeEtecoon_E680(uint16 k);
void EscapeEtecoon_Init(void);
void EscapeEtecoon_Main(void);
void NorfairPipeBug_8BA8(void);
void NorfairPipeBug_Func_1(void);
void NorfairPipeBug_Func_10(void);
void NorfairPipeBug_Func_11(void);
void NorfairPipeBug_Func_12(void);
void NorfairPipeBug_Func_2(void);
void NorfairPipeBug_Func_3(uint16 k);
void NorfairPipeBug_Func_4(void);
void NorfairPipeBug_Func_5(uint16 k);
void NorfairPipeBug_Func_6(void);
void NorfairPipeBug_Func_7(void);
void NorfairPipeBug_Func_8(void);
void NorfairPipeBug_Func_9(void);
void NorfairPipeBug_Init(void);
void NorfairPipeBug_Main(void);
void UnusedSpinningTurtleEye_Init(void);
void UnusedSpinningTurtleEye_Main(void);
void sub_B38E56(void);

// Bank B4
void ClearSpriteObjects(void);
uint16 CreateSpriteAtPos(uint16 x_r18, uint16 y_r20, uint16 ilist_r22, uint16 pal_r24);
void DrawSpriteObjects(void);
void HandleSpriteObjects(void);
void SpriteObject_Instr_Goto(void);
void SpriteObject_Instr_RepeatLast(void);
void SpriteObject_Instr_Terminate(void);
void VerifySRAM(void);

#define fnDrawTimer 0x809F6C
#define fnnullsub_1 0x818AB7
#define fnnullsub_27 0x818B21
#define fnnullsub_56 0x8192DB
#define fnDemoRoom_ChargeBeamRoomScroll21 0x82891A
#define fnnullsub_291 0x828924
#define fnDemoRoom_SetBG2TilemapBase 0x828925
#define fnDemoRoom_SetKraidFunctionTimer 0x82892B
#define fnDemoRoom_SetBrinstarBossBits 0x828932
#define fnnullsub_8 0x828B0D
#define fnOptionsPreInstr_nullsub_57 0x828C10
#define fnOptionsInstr_Destroy 0x828C5A
#define fnOptionsInstr_Sleep 0x828C64
#define fnOptionsInstr_SetPreInstr 0x828C6E
#define fnOptionsInstr_ClearPreInstr 0x828C79
#define fnOptionsInstr_Goto 0x828C82
#define fnOptionsInstr_DecrementTimerAndGoto 0x828C89
#define fnOptionsInstr_SetTimer 0x828C93
#define fnBabyMetroidPlayCry1Sfx 0x82BC0C
#define fnBabyMetroidPlayCry2Sfx 0x82BC15
#define fnBabyMetroidPlayCry3Sfx 0x82BC1E
#define fnDoorTransitionFunction_HandleElevator 0x82E17D
#define fnDoorTransitionFunction_Wait48frames 0x82E19F
#define fnDoorTransitionFunction_WaitForSoundsToFinish 0x82E29E
#define fnDoorTransitionFunction_FadeOutScreen 0x82E2DB
#define fnDoorTransitionFunction_LoadDoorHeaderEtc 0x82E2F7
#define fnDoorTransitionFunction_ScrollScreenToAlignment 0x82E310
#define fnDoorTransitionFunction_FixDoorsMovingUp 0x82E353
#define fnDoorTransitionFunction_SetupNewRoom 0x82E36E
#define fnDoorTransitionFunction_SetupScrolling 0x82E38E
#define fnDoorTransitionFunction_PlaceSamusLoadTiles 0x82E3C0
#define fnDoorTransitionFunction_LoadMoreThings_Async 0x82E4A9
#define fnDoorTransitionFunction_HandleAnimTiles 0x82E659
#define fnDoorTransitionFunction_WaitForMusicToClear 0x82E664
#define fnDoorTransitionFunction_HandleTransition 0x82E6A2
#define fnDoorTransitionFunction_FadeInScreenAndFinish 0x82E737
#define fnOptionsInit_MenuSelectMissile 0x82F296
#define fnOptionsPreInstr_MenuSelectMissile 0x82F2A9
#define fnOptionsInit_OptionModeBorder 0x82F34B
#define fnOptionsInit_ControllerSettingModeBorder 0x82F353
#define fnOptionsInit_SpecialSettingModeBorder 0x82F35B
#define fnOptionsInit_SamusDataBorder 0x82F363
#define fnOptionsPreInstr_OptionsModeBorder 0x82F376
#define fnOptionsPreInstr_ControllerSettingModeBorder 0x82F3A0
#define fnOptionsPreInstr_SpecialSettingModeBorder 0x82F3E2
#define fnOptionsInit_FileSelectHelmet 0x82F419
#define fnOptionsPreInstr_FileSelectHelmet 0x82F42C
#define fnPlmPreInstr_nullsub_60 0x848469
#define fnPlmPreInstr_Empty2 0x8484E6
#define fnPlmPreInstr_Empty3 0x84853D
#define fnPlmPreInstr_Empty4 0x848AA6
#define fnPlmInstr_Sleep 0x8486B4
#define fnPlmInstr_Delete 0x8486BC
#define fnPlmInstr_PreInstr 0x8486C1
#define fnPlmInstr_ClearPreInstr 0x8486CA
#define fnPlmPreInstr_Empty 0x8486D0
#define fnPlmInstr_CallFunction 0x84870B
#define fnPlmInstr_Goto 0x848724
#define fnPlmInstr_DecrementAndBranchNonzero 0x84873F
#define fnPlmInstr_SetTimer 0x84874E
#define fnPlmInstr_LoadItemPlmGfx 0x848764
#define fnPlmInstr_CopyFromRamToVram 0x8487E5
#define fnPlmInstr_GotoIfBossBitSet 0x84880E
#define fnPlmInstr_GotoIfEventSet 0x84882D
#define fnPlmInstr_SetEvent 0x84883E
#define fnPlmInstr_GotoIfChozoSet 0x848848
#define fnPlmInstr_SetRoomChozoBit 0x848865
#define fnPlmInstr_GotoIfItemBitSet 0x84887C
#define fnPlmInstr_SetItemBit 0x848899
#define fnPlmInstr_PickupBeamAndShowMessage 0x8488B0
#define fnPlmInstr_PickupEquipmentAndShowMessage 0x8488F3
#define fnPlmInstr_PickupEquipmentAddGrappleShowMessage 0x84891A
#define fnPlmInstr_PickupEquipmentAddXrayShowMessage 0x848941
#define fnPlmInstr_CollectHealthEnergyTank 0x848968
#define fnPlmInstr_CollectHealthReserveTank 0x848986
#define fnPlmInstr_CollectAmmoMissileTank 0x8489A9
#define fnPlmInstr_CollectAmmoSuperMissileTank 0x8489D2
#define fnPlmInstr_CollectAmmoPowerBombTank 0x8489FB
#define fnPlmInstr_SetLinkReg 0x848A24
#define fnPlmInstr_Call 0x848A2E
#define fnPlmInstr_Return 0x848A3A
#define fnPlmInstr_GotoIfDoorBitSet 0x848A72
#define fnPlmInstr_IncrementDoorHitCounterAndJGE 0x848A91
#define fnPlmInstr_IncrementArgumentAndJGE 0x848ACD
#define fnlocret_848AE0 0x848AE0
#define fnPlmInstr_SetBTS 0x848AF1
#define fnPlmInstr_DrawPlmBlock 0x848B05
#define fnPlmInstr_DrawPlmBlock_ 0x848B17
#define fnPlmInstr_ProcessAirScrollUpdate 0x848B55
#define fnPlmInstr_ProcessSolidScrollUpdate 0x848B93
#define fnPlmInstr_QueueMusic 0x848BD1
#define fnPlmInstr_ClearMusicQueueAndQueueTrack 0x848BDD
#define fnPlmInstr_QueueSfx1_Max6 0x848C07
#define fnPlmInstr_QueueSfx2_Max6 0x848C10
#define fnPlmInstr_QueueSfx3_Max6 0x848C19
#define fnPlmInstr_QueueSfx1_Max15 0x848C22
#define fnPlmInstr_QueueSfx2_Max15 0x848C2B
#define fnPlmInstr_QueueSfx3_Max15 0x848C34
#define fnPlmInstr_QueueSfx1_Max3 0x848C3D
#define fnPlmInstr_QueueSfx2_Max3 0x848C46
#define fnPlmInstr_QueueSfx_Max3 0x848C4F
#define fnPlmInstr_QueueSfx1_Max9 0x848C58
#define fnPlmInstr_QueueSfx2_Max9 0x848C61
#define fnPlmInstr_QueueSfx3_Max9 0x848C6A
#define fnPlmInstr_QueueSfx1_Max1 0x848C73
#define fnPlmInstr_QueueSfx2_Max1 0x848C7C
#define fnPlmInstr_QueueSfx3_Max1 0x848C85
#define fnPlmInstr_ActivateMapStation 0x848C8F
#define fnPlmInstr_ActivateEnergyStation 0x848CAF
#define fnPlmInstr_ActivateMissileStation 0x848CD0
#define fnPlmInstr_ActivateSaveStationAndGotoIfNo 0x848CF1
#define fnPlmInstr_GotoIfSamusNear 0x848D41
#define fnPlmInstr_MovePlmDownOneBlock 0x84AB00
#define fnnullsub_67 0x84AB27
#define fnPlmSetup_CrumbleBotwoonWall 0x84AB28
#define fnPlmInstr_Scroll_0_1_Blue 0x84AB51
#define fnPlmInstr_MovePlmDownOneBlock_0 0x84AB59
#define fnPlmInstr_MovePlmRight1Block 0x84ABD6
#define fnPlmPreInstr_PositionSamusAndInvincible 0x84AC89
#define fnPlmInstr_DealDamage_2 0x84AC9D
#define fnPlmInstr_GiveInvincibility 0x84ACB1
#define fnPlmInstr_Draw0x38FramesOfRightTreadmill 0x84AD43
#define fnPlmInstr_Draw0x38FramesOfLeftTreadmill 0x84AD58
#define fnPlmInstr_GotoIfSamusHealthFull 0x84AE35
#define fnPlmInstr_GotoIfMissilesFull 0x84AEBF
#define fnPlmInstr_PlaceSamusOnSaveStation 0x84B00E
#define fnPlmInstr_DisplayGameSavedMessageBox 0x84B024
#define fnPlmInstr_EnableMovementAndSetSaveStationUsed 0x84B030
#define fnPlmSetup_SetupWreckedShipEntrance 0x84B04A
#define fnPlmSetup_BTS_Brinstar_0x80_Floorplant 0x84B0DC
#define fnPlmSetup_BTS_Brinstar_0x81_Ceilingplant 0x84B113
#define fnPlmSetup_B6D3_MapStation 0x84B18B
#define fnPlmSetup_Bts47_MapStationRightAccess 0x84B1C8
#define fnPlmSetup_Bts4_MapStationLeftAccess 0x84B1F0
#define fnPlmSetup_PlmB6DF_EnergyStation 0x84B21D
#define fnPlmSetup_PlmB6EB_MissileStation 0x84B245
#define fnPlmSetup_B6E3_EnergyStationRightAccess 0x84B26D
#define fnPlmSetup_B6E7_EnergyStationLeftAccess 0x84B29D
#define fnPlmSetup_B6EF_MissileStationRightAccess 0x84B2D0
#define fnPlmSetup_B6F3_MissileStationLeftAccess 0x84B300
#define fnPlmSetup_B638_Rightwards_Extension 0x84B33A
#define fnPlmSetup_B63F_Leftwards_Extension 0x84B345
#define fnPlmSetup_B643_Downwards_Extension 0x84B350
#define fnPlmSetup_B647_Upwards_Extension 0x84B35B
#define fnPlmSetup_B703_ScrollPLM 0x84B371
#define fnPlmSetup_B707_SolidScrollPLM 0x84B382
#define fnPlmSetup_B6FF_ScrollBlockTouch 0x84B393
#define fnPlmSetup_DeactivatePlm 0x84B3C1
#define fnnullsub_290 0x84B3CF
#define fnPlmSetup_ReturnCarryClear 0x84B3D0
#define fnPlmSetup_ReturnCarrySet 0x84B3D2
#define fnPlmSetup_D094_EnemyBreakableBlock 0x84B3D4
#define fnPlmSetup_B743_Unused 0x84B3E3
#define fnPlmSetup_B70F_IcePhysics 0x84B3EB
#define fnPlmSetup_InsideReaction_QuicksandSurface 0x84B408
#define fnPlmSetup_B71F_SubmergingQuicksand 0x84B497
#define fnPlmSetup_B723_SandfallsSlow 0x84B4A8
#define fnPlmSetup_B727_SandFallsFast 0x84B4B6
#define fnPlmSetup_CollisionReaction_QuicksandSurface 0x84B4C4
#define fnPlmSetup_B737_SubmergingQuicksand 0x84B541
#define fnPlmSetup_B73B_B73F_SandFalls 0x84B54F
#define fnPlmSetup_B763_ClearShitroidInvisibleWall 0x84B551
#define fnPlmSetup_B767_CreateShitroidInvisibleWall 0x84B56F
#define fnPlmSetup_B76B_SaveStationTrigger 0x84B590
#define fnPlmSetup_B76F_SaveStation 0x84B5EE
#define fnPlmSetup_MotherBrainRoomEscapeDoor 0x84B5F8
#define fnPlmSetup_B7EB_EnableSoundsIn32Frames 0x84B7C3
#define fnPlmPreInstr_B7EB_DecTimerEnableSoundsDeletePlm 0x84B7DD
#define fnPlmPreInstr_WakeAndLavaIfBoosterCollected 0x84B7EF
#define fnPlmPreInstr_WakePLMAndStartFxMotionSamusFarLeft 0x84B82A
#define fnPlmPreInstr_AdvanceLavaSamusMovesLeft 0x84B846
#define fnPlmSetup_SpeedBoosterEscape 0x84B89C
#define fnPlmPreInstr_ShaktoolsRoom 0x84B8B0
#define fnPlmSetup_ShaktoolsRoom 0x84B8DC
#define fnnullsub_68 0x84B8EF
#define fnPlmPreInstr_OldTourianEscapeShaftEscape 0x84B927
#define fnPlmPreInstr_EscapeRoomBeforeOldTourianEscapeShaft 0x84B948
#define fnPlmSetup_B974 0x84B96C
#define fnPlmSetup_B9C1_CrittersEscapeBlock 0x84B978
#define fnPlmInstr_SetCrittersEscapedEvent 0x84B9B9
#define fnPlmSetup_B9ED_CrittersEscapeBlock 0x84B9C5
#define fnPlmSetup_B9F1_TurnCeresDoorSolid 0x84B9F1
#define fnPlmInstr_JumpIfSamusHasNoBombs 0x84BA6F
#define fnnullsub_84BAFA 0x84BAFA
#define fnPlmSetup_BB30_CrateriaMainstreetEscape 0x84BB09
#define fnPlmInstr_MovePlmRight4Blocks 0x84BB25
#define fnPlmPreInstr_WakePlmIfTriggered 0x84BB52
#define fnnullsub_359 0x84BB6A
#define fnPlmPreInstr_WakePlmIfTriggeredOrSamusBelowPlm 0x84BB6B
#define fnPlmPreInstr_Empty5 0x84BBA3
#define fnPlmPreInstr_WakePlmIfTriggeredOrSamusAbovePlm 0x84BBA4
#define fnPlmInstr_ClearTrigger 0x84BBDD
#define fnPlmInstr_SpawnEproj 0x84BBE1
#define fnPlmInstr_WakeEprojAtPlmPos 0x84BBF0
#define fnPlmPreInstr_GoToLinkInstrIfShot 0x84BD0F
#define fnPlmPreInstr_GoToLinkInstrIfShotWithPowerBomb 0x84BD26
#define fnPlmPreInstr_GoToLinkInstrIfShotWithAnyMissile 0x84BD50
#define fnPlmPreInstr_GoToLinkInstrIfShotWithSuperMissile 0x84BD88
#define fnPlmPreInstr_GoToLinkInstruction 0x84BDB2
#define fnPlmPreInstr_GotoLinkIfAreaBossDead 0x84BDD4
#define fnPlmPreInstr_GotoLinkIfMiniBossDead 0x84BDE3
#define fnPlmPreInstr_GotoLinkIfTorizoDead 0x84BDF2
#define fnPlmPreInstr_GotoLinkIfEnemyDeathQuotaOk 0x84BE01
#define fnPlmPreInstr_PlayDudSound 0x84BE1C
#define fnPlmPreInstr_GotoLinkIfTourianStatueFinishedProcessing 0x84BE1F
#define fnPlmPreInstr_GotoLinkIfCrittersEscaped 0x84BE30
#define fnPlmInstr_SetGreyDoorPreInstr 0x84BE3F
#define fnPlmSetup_C806_LeftGreenGateTrigger 0x84C54D
#define fnPlmSetup_C80A_RightGreenGateTrigger 0x84C56C
#define fnPlmSetup_C80E_LeftRedGateTrigger 0x84C58B
#define fnPlmSetup_C812_RightRedGateTrigger 0x84C5AF
#define fnPlmSetup_C81E_LeftYellowGateTrigger 0x84C5D3
#define fnPlmSetup_C822_RightYellowGateTrigger 0x84C5F1
#define fnPlmSetup_C816_LeftBlueGateTrigger 0x84C610
#define fnPlmSetup_C81A_RightBlueGateTrigger 0x84C627
#define fnPlmSetup_C82A_DownwardsClosedGate 0x84C6BE
#define fnPlmSetup_C832_UpwardsClosedGate 0x84C6CB
#define fnPlmSetup_C826_DownwardsOpenGate 0x84C6D8
#define fnPlmSetup_C82E_UpwardsOpenGate 0x84C6DC
#define fnPlmSetup_C836_DownwardsGateShootblock 0x84C6E0
#define fnPlmSetup_C73A_UpwardsGateShootblock 0x84C73A
#define fnPlmSetup_GreyDoor 0x84C794
#define fnPlmSetup_Door_Colored 0x84C7B1
#define fnPlmSetup_Door_Blue 0x84C7BB
#define fnPlmSetup_C7E2_GenericShotTrigger 0x84C7E2
#define fnPlmInstr_SetBtsTo1 0x84CD93
#define fnPlmSetup_D028_D02C_Unused 0x84CDC2
#define fnPlmSetup_RespawningSpeedBoostBlock 0x84CDEA
#define fnPlmSetup_RespawningCrumbleBlock 0x84CE37
#define fnPlmSetup_RespawningShotBlock 0x84CE6B
#define fnPlmSetup_RespawningBombBlock 0x84CE83
#define fnPlmSetup_RespawningBombBlock2 0x84CEDA
#define fnPlmSetup_RespawningPowerBombBlock 0x84CF2E
#define fnPlmSetup_SuperMissileBlockRespawning 0x84CF67
#define fnPlmSetup_CrumbleBlock 0x84CFA0
#define fnPlmSetup_BreakableGrappleBlock 0x84CFB5
#define fnPlmSetup_D0D8_SetVFlag 0x84CFCD
#define fnPlmSetup_D0D8_ClearVflag 0x84CFD1
#define fnPlmSetup_D0E8_GiveSamusDamage 0x84CFD5
#define fnPlmSetup_D113_LowerNorfairChozoRoomPlug 0x84D108
#define fnPlmSetup_D127 0x84D117
#define fnPlmSetup_D138 0x84D12B
#define fnPlmInstr_FxBaseYPos_0x2D2 0x84D155
#define fnPlmPreInstr_DeletePlmAndSpawnTriggerIfBlockDestroyed 0x84D15C
#define fnnullsub_69 0x84D18E
#define fnPlmSetup_D6DA_LowerNorfairChozoHandTrigger 0x84D18F
#define fnPlmPreInstr_IncrementRoomArgIfShotBySuperMissile 0x84D1E6
#define fnPlmInstr_GotoIfRoomArgLess 0x84D2F9
#define fnPlmInstr_SpawnFourMotherBrainGlass 0x84D30B
#define fnPlmPreInstr_WakePlmIfSamusHasBombs 0x84D33B
#define fnnullsub_351 0x84D356
#define fnPlmInstr_SpawnTorizoStatueBreaking 0x84D357
#define fnPlmInstr_QueueSong1MusicTrack 0x84D3C7
#define fnPlmInstr_TransferWreckedShipChozoSpikesToSlopes 0x84D3D7
#define fnPlmInstr_TransferWreckedShipSlopesToChozoSpikes 0x84D3F4
#define fnPlmPreInstr_WakeOnKeyPress 0x84D4BF
#define fnPlmInstr_EnableWaterPhysics 0x84D525
#define fnPlmInstr_SpawnN00bTubeCrackEproj 0x84D52C
#define fnPlmInstr_DiagonalEarthquake 0x84D536
#define fnPlmInstr_Spawn10shardsAnd6n00bs 0x84D543
#define fnPlmInstr_DisableSamusControls 0x84D5E6
#define fnPlmInstr_EnableSamusControls 0x84D5EE
#define fnPlmSetup_MotherBrainGlass 0x84D5F6
#define fnPlmSetup_DeletePlmIfAreaTorizoDead 0x84D606
#define fnPlmSetup_MakeBllockChozoHandTrigger 0x84D616
#define fnPlmSetup_D6F2_WreckedShipChozoHandTrigger 0x84D620
#define fnPlmSetup_D700_MakePlmAirBlock_Unused 0x84D67F
#define fnPlmSetup_D704_AlteranateLowerNorfairChozoHand_Unused 0x84D689
#define fnPlmSetup_D708_LowerNorfairChozoBlockUnused 0x84D693
#define fnPlmSetup_D70C_NoobTube 0x84D6CC
#define fnnullsub_71 0x84D6F6
#define fnnullsub_72 0x84D6F7
#define fnPlmPreInstr_WakePlmIfRoomArgumentDoorIsSet 0x84D753
#define fnPlmInstr_ShootEyeDoorProjectileWithProjectileArg 0x84D77A
#define fnPlmInstr_SpawnEyeDoorSweatEproj 0x84D790
#define fnPlmInstr_SpawnTwoEyeDoorSmoke 0x84D79F
#define fnPlmInstr_SpawnEyeDoorSmokeProjectile 0x84D7B6
#define fnPlmInstr_MoveUpAndMakeBlueDoorFacingRight 0x84D7C3
#define fnPlmInstr_MoveUpAndMakeBlueDoorFacingLeft 0x84D7DA
#define fnPlmSetup_EyeDoorEye 0x84DA8C
#define fnPlmSetup_EyeDoor 0x84DAB9
#define fnnullsub_73 0x84DAD5
#define fnnullsub_74 0x84DAD6
#define fnnullsub_75 0x84DAD7
#define fnnullsub_76 0x84DAD8
#define fnnullsub_77 0x84DAD9
#define fnnullsub_78 0x84DADA
#define fnnullsub_79 0x84DADB
#define fnnullsub_80 0x84DADC
#define fnnullsub_81 0x84DADD
#define fnPlmPreInstr_SetMetroidsClearState_Ev0x10 0x84DADE
#define fnPlmPreInstr_SetMetroidsClearState_Ev0x11 0x84DAEE
#define fnPlmPreInstr_SetMetroidsClearState_Ev0x12 0x84DAFE
#define fnPlmPreInstr_SetMetroidsClearState_Ev0x13 0x84DB0E
#define fnPlmSetup_SetMetroidRequiredClearState 0x84DB1E
#define fnPlmPreInstr_GotoLinkIfShotWithSuperMissile 0x84DB64
#define fnPlmInstr_DamageDraygonTurret 0x84DB8E
#define fnPlmInstr_DamageDraygonTurretFacingDownRight 0x84DBB8
#define fnPlmInstr_DamageDraygonTurretFacingUpRight 0x84DBF7
#define fnPlmInstr_DamageDraygonTurret2 0x84DC36
#define fnPlmInstr_DamageDraygonTurretFacingDownLeft 0x84DC60
#define fnPlmInstr_DamageDraygonTurretFacingUpLeft 0x84DC9F
#define fnPlmSetup_DraygonCannonFacingRight 0x84DE94
#define fnPlmSetup_DraygonCannonFacingDiagonalRight 0x84DEB9
#define fnPlmSetup_DraygonCannonFacingLeft 0x84DEF0
#define fnPlmSetup_DraygonCannonFacingDiagonalLeft 0x84DF15
#define fnPlmSetup_DraygonCannon 0x84DF4C
#define fnPlmPreInstr_GotoLinkIfTriggered 0x84DF89
#define fnPlmPreInstr_nullsub_301 0x84DFA8
#define fnPlmPreInstr_WakeIfTriggered 0x84DFE6
#define fnPlmInstr_DrawItemFrame0 0x84E04F
#define fnPlmInstr_DrawItemFrame1 0x84E067
#define fnPlmInstr_DrawItemFrame_Common 0x84E07F
#define fnPlmInstr_ClearChargeBeamCounter 0x84E29D
#define fnPlmInstr_MoveFxYUp 0x84E63B
#define fnPlmSetup_EnergyTank 0x84EE4D
#define fnPlmSetup_MissileTank 0x84EE52
#define fnPlmSetup_SuperMissileTank 0x84EE57
#define fnPlmSetup_PowerBombTank 0x84EE5C
#define fnPlmSetup_AbilityTank 0x84EE64
#define fnPlmSetup_EnergyTankShotBlock 0x84EE77
#define fnPlmSetup_MissileTankShotBlock 0x84EE7C
#define fnPlmSetup_SuperMissileTankShotBlock 0x84EE81
#define fnPlmSetup_PowerBombTankShotBlock 0x84EE86
#define fnPlmSetup_AbilityTankShotBlock 0x84EE8E
#define fnPlmSetup_ItemCollisionDetection 0x84EEAB
#define fnWriteLargeMessageBoxTilemap 0x85825A
#define fnWriteSmallMessageBoxTilemap 0x858289
#define fnDrawShootButtonAndSetupPpuForLargeMessageBox 0x8583C5
#define fnDrawRunButtonAndSetupPpuForLargeMessageBox 0x8583CC
#define fnSetupPpuForSmallMessageBox 0x858436
#define fnSetupPpuForLargeMessageBox 0x858441
#define fnEprojInstr_Delete 0x868154
#define fnEprojInstr_Sleep 0x868159
#define fnEprojInstr_SetPreInstr_ 0x868161
#define fnEprojInstr_ClearPreInstr 0x86816A
#define fnEprojPreInstr_nullsub_297 0x868170
#define fnEprojInstr_CallFunc 0x868171
#define fnEprojInstr_Goto 0x8681AB
#define fnEprojInstr_GotoRel 0x8681B0
#define fnEprojInstr_DecTimerAndGotoIfNonZero 0x8681C6
#define fnEprojInstr_DecTimerAndGotoRelIfNonZero 0x8681CE
#define fnEprojInstr_SetTimer 0x8681D5
#define fnnullsub_82 0x8681DE
#define fnEprojInstr_MoveRandomlyWithinRadius 0x8681DF
#define fnEprojInstr_SetProjectileProperties 0x868230
#define fnEprojInstr_ClearProjectileProperties 0x86823C
#define fnEprojInstr_EnableCollisionWithSamusProj 0x868248
#define fnEprojInstr_DisableCollisionWithSamusProj 0x868252
#define fnEprojInstr_DisableCollisionWithSamus 0x86825C
#define fnEprojInstr_EnableCollisionWithSamus 0x868266
#define fnEprojInstr_SetToNotDieOnContact 0x868270
#define fnEprojInstr_SetToDieOnContact 0x86827A
#define fnEprojInstr_SetLowPriority 0x868284
#define fnEprojInstr_SetHighPriority 0x86828E
#define fnEprojInstr_SetXyRadius 0x868298
#define fnEprojInstr_SetXyRadiusZero 0x8682A1
#define fnEprojInstr_CalculateDirectionTowardsSamus 0x8682A5
#define fnEprojInstr_WriteColorsToPalette 0x8682D5
#define fnEprojInstr_QueueMusic 0x8682FD
#define fnEprojInstr_QueueSfx1_Max6 0x868309
#define fnEprojInstr_QueueSfx2_Max6 0x868312
#define fnEprojInstr_QueueSfx3_Max6 0x86831B
#define fnEprojInstr_QueueSfx1_Max15 0x868324
#define fnEprojInstr_QueueSfx2_Max15 0x86832D
#define fnEprojInstr_QueueSfx3_Max15 0x868336
#define fnEprojInstr_QueueSfx1_Max3 0x86833F
#define fnEprojInstr_QueueSfx2_Max3 0x868348
#define fnEprojInstr_QueueSfx3_Max3 0x868351
#define fnEprojInstr_QueueSfx1_Max9 0x86835A
#define fnEprojInstr_QueueSfx2_Max9 0x868363
#define fnEprojInstr_QueueSfx3_Max9 0x86836C
#define fnEprojInstr_QueueSfx1_Max1 0x868375
#define fnEprojInstr_QueueSfx2_Max1 0x86837E
#define fnEprojInstr_QueueSfx3_Max1 0x868387
#define fnEprojPreInstr_nullsub_83 0x8684FB
#define fnEproj_Init_0x8aaf 0x868A39
#define fnEproj_PreInit_0x8aaf 0x868A7D
#define fnEproj_Init_0x8bc2_SkreeDownRight 0x868ACD
#define fnEproj_Init_0x8bd0_SkreeUpRight 0x868AF1
#define fnEproj_Init_0x8bde_SkreeDownLeft 0x868B15
#define fnEproj_Init_0x8bec_SkreeUpLeft 0x868B39
#define fnEproj_PreInstr_SkreeParticle 0x868B5D
#define fnEprojInstr_SpawnEnemyDropsWithDraygonsEyeDrops 0x868C68
#define fnEprojInstr_SetPreInstrA 0x868CF6
#define fnEprojInstr_SetPreInstrB 0x868CFD
#define fnEprojInit_DraygonsGunk 0x868D04
#define fnEprojInit_DraygonsWallTurretProjs 0x868D40
#define fnnullsub_84 0x868D54
#define fnEprojInstr_868D99 0x868D99
#define fnEprojPreInstr_8DCA 0x868DCA
#define fnEprojPreInstr_DraygonsTurret_8DFF 0x868DFF
#define fnEprojPreInstr_DraygonsGunk_8E0F 0x868E0F
#define fnEprojInit_CrocomireProjectile 0x869023
#define fnEprojPreInstr_CrocomireProjectile 0x86906B
#define fnMoveEprojHorizAndOrVert 0x8690B3
#define fnEprojInit_CrocomireSpikeWallPieces 0x8690CF
#define fnEprojPreInstr_CrocomireSpikeWallPieces 0x869115
#define fnEprojInstr_9270 0x869270
#define fnEprojInit_CrocomireBridgeCrumbling 0x869286
#define fnEprojPreInstr_CrocomireBridgeCrumbling 0x8692BA
#define fnEprojInit_9634 0x86934D
#define fnEprojPreInstr_9634 0x869392
#define fnEprojInit_9642_RidleysFireball 0x8693CA
#define fnEprojPreInstr_9642_RidleysFireball 0x86940E
#define fnEprojInstr_DisableCollisionsWithSamus 0x869475
#define fnEprojInit_9660_FireballExplosion 0x86947F
#define fnEprojInit_9688 0x8694A0
#define fnEprojInit_9696 0x8694B4
#define fnEprojInit_966C 0x8694C8
#define fnEprojInit_967A 0x8694DC
#define fnnullsub_85 0x86950C
#define fnEprojPreInstr_966C 0x86950D
#define fnEprojPreInstr_9688 0x869522
#define fnEprojPreInstr_96A4 0x869537
#define fnEprojPreInstr_96C0 0x869540
#define fnEprojPreInstr_96CE 0x869549
#define fnEprojInstr_95BA 0x8695BA
#define fnEprojInstr_95ED 0x8695ED
#define fnEprojInstr_9620 0x869620
#define fnEprojInit_9734_CeresFallingDebris 0x8696DC
#define fnEprojPreInstr_9734_CeresFallingDebris 0x869701
#define fnEprojInstr_980E 0x86980E
#define fnEprojInit_PhantoonDestroyableFireballs 0x869824
#define fnEprojInit_PhantoonStartingFireballs 0x86993A
#define fnEprojPreInstr_PhantoonStartingFireballs 0x869981
#define fnEprojPreInstr_PhantoonStartingFireballs2 0x8699BF
#define fnEprojPreInstr_PhantoonStartingFireballs3 0x869A01
#define fnnullsub_86 0x869A44
#define fnEprojPreInstr_PhantoonDestroyableFireballs 0x869A45
#define fnEprojPreInstr_PhantoonDestroyableFireballs_2 0x869A94
#define fnEprojPreInstr_PhantoonDestroyableFireballs_3 0x869ADA
#define fnEprojPreInstr_PhantoonStartingFireballsB 0x869B29
#define fnEprojPreInstr_PhantoonStartingFireballsB_2 0x869B41
#define fnEprojInit_RocksKraidSpits 0x869CA3
#define fnEprojInit_RocksFallingKraidCeiling 0x869CD8
#define fnEprojInit_RocksWhenKraidRises 0x869D0C
#define fnEprojPreInstr_KraidRocks 0x869D56
#define fnEprojPreInstr_RocksFallingKraidCeiling 0x869D89
#define fnsub_869DA5 0x869DA5
#define fnEprojInit_MiniKraidSpit 0x869DEC
#define fnEprojPreInit_MiniKraidSpit 0x869E1E
#define fnEprojInit_MiniKraidSpikesLeft 0x869E46
#define fnEprojInit_MiniKraidSpikesRight 0x869E4B
#define fnEprojInit_MiniKraidSpikes 0x869E4E
#define fnEprojPreInstr_MiniKraidSpikes 0x869E83
#define fnEprojInit_WalkingLavaSeahorseFireball 0x869EB2
#define fnEprojPreInstr_WalkingLavaSeahorseFireball 0x869EFF
#define fnEprojInit_PirateMotherBrainLaser 0x86A009
#define fnEprojInstr_SetPreInstrAndRun 0x86A050
#define fnnullsub_87 0x86A05B
#define fnEprojPreInstr_PirateMotherBrainLaser_MoveLeft 0x86A05C
#define fnEprojPreInstr_PirateMotherBrainLaser_MoveRight 0x86A07A
#define fnEprojInit_PirateClaw 0x86A098
#define fnEprojPreInstr_PirateClawThrownLeft 0x86A0D1
#define fnEprojPreInstr_PirateClawThrownRight 0x86A124
#define fnEprojInit_A379 0x86A2A1
#define fnEprojInit_CeresElevatorPad 0x86A2EE
#define fnEprojInit_CeresElevatorPlatform 0x86A31B
#define fnnullsub_88 0x86A327
#define fnEprojPreInstr_CeresElevatorPad 0x86A328
#define fnEprojPreInstr_CeresElevatorPlatform 0x86A364
#define fnEprojPreInstr_PrePhantomRoom 0x86A3A3
#define fnEprojInstr_A3BE 0x86A3BE
#define fnEprojInstr_GotoWithProbability25 0x86A456
#define fnEprojInit_BombTorizoLowHealthDrool 0x86A5D3
#define fnEprojInit_BombTorizoLowHealthInitialDrool 0x86A65D
#define fnEprojInit_A977 0x86A6C7
#define fnEprojInit_BombTorizoExplosiveSwipe 0x86A6F6
#define fnEprojInit_BombTorizoStatueBreaking 0x86A764
#define fnEprojInit_BombTorizoLowHealthExplode 0x86A81B
#define fnEprojInit_BombTorizoDeathExplosion 0x86A871
#define fnsub_86A887 0x86A887
#define fnEprojPreInstr_A977 0x86A8EF
#define fnnullsub_352 0x86A918
#define fnnullsub_89 0x86A919
#define fnEprojInit_AB07 0x86AA3D
#define fnEprojPreInstr_AB07 0x86AA8C
#define fnEprojInstr_SpawnEnemyDrops 0x86AB8A
#define fnEprojInit_BombTorizosChozoOrbs 0x86ABEB
#define fnEprojInit_GoldenTorizosChozoOrbs 0x86AC7C
#define fnEprojPreInstr_BombTorizosChozoOrbs 0x86ACAD
#define fnEprojPreInstr_GoldenTorizosChozoOrbs 0x86ACFA
#define fnEprojInstr_GotoDependingOnXDirection 0x86AD92
#define fnEprojInit_TorizoSonicBoom 0x86AE15
#define fnEprojPreInstr_TorizoSonicBoom 0x86AE6C
#define fnEprojInit_WreckedShipChozoSpikeFootsteps 0x86AEFC
#define fnEprojInstr_ResetXYpos1 0x86AF36
#define fnEprojInit_TourianStatueDustClouds 0x86AF43
#define fnEprojInit_TourianLandingDustCloudsRightFoot 0x86AF50
#define fnEprojInstr_MoveY_Minus4 0x86AF92
#define fnEprojInstr_SetVelTowardsSamus1 0x86B269
#define fnEprojInstr_SetVelTowardsSamus2 0x86B272
#define fnEprojInit_TorizoLandingDustCloudLeftFoot 0x86AFCD
#define fnEprojInit_GoldenTorizoEgg 0x86B001
#define fnEprojPreInstr_GoldenTorizoEgg 0x86B043
#define fnsub_86B0B9 0x86B0B9
#define fnsub_86B0DD 0x86B0DD
#define fnsub_86B13E 0x86B13E
#define fnEprojInit_GoldenTorizoSuperMissile 0x86B1CE
#define fnEprojPreInstr_GoldenTorizoSuperMissile 0x86B20D
#define fnEprojPreInstr_B237 0x86B237
#define fnEprojInit_GoldenTorizoEyeBeam 0x86B328
#define fnEprojPreInstr_GoldenTorizoEyeBeam 0x86B38A
#define fnEprojInstr_GotoIfFunc1 0x86B3B8
#define fnEprojInstr_ResetXYpos2 0x86B436
#define fnEprojInit_TourianEscapeShaftFakeWallExplode 0x86B49D
#define fnnullsub_90 0x86B4B0
#define fnEprojInit_LavaSeahorseFireball 0x86B4EF
#define fnsub_86B535 0x86B535
#define fnEprojInit_EyeDoorProjectile 0x86B62D
#define fnEprojInit_EyeDoorSweat 0x86B683
#define fnEprojPreInstr_EyeDoorProjectile 0x86B6B9
#define fnEprojPreInstr_EyeDoorSweat 0x86B714
#define fnEprojInstr_SpawnTourianStatueUnlockingParticle 0x86B7EA
#define fnEprojInstr_Earthquake 0x86B7F5
#define fnEprojInstr_SpawnTourianStatueUnlockingParticleTail 0x86B818
#define fnEprojInstr_AddToYpos 0x86B841
#define fnEprojInit_TourianStatueUnlockingParticleWaterSplash 0x86B87A
#define fnEprojInit_TourianStatueEyeGlow 0x86B88E
#define fnEprojInit_TourianStatueUnlockingParticle 0x86B8B5
#define fnEprojIni_TourianStatueUnlockingParticleTail 0x86B8E8
#define fnEprojInit_TourianStatueSoul 0x86B8F8
#define fnEprojInit_TourianStatueBaseDecoration 0x86B93E
#define fnEprojInit_TourianStatueRidley 0x86B951
#define fnEprojInit_TourianStatuePhantoon 0x86B964
#define fnEprojPreInstr_TourianStatueUnlockingParticleWaterSplash 0x86B977
#define fnEprojPreInstr_TourianStatueUnlockingParticle 0x86B982
#define fnEprojPreInstr_TourianStatueSoul 0x86B9FD
#define fnEprojPreInstr_TourianStatueStuff 0x86BA37
#define fnEprojPreInstr_BA42 0x86BA42
#define fnsub_86BB30 0x86BB30
#define fnnullsub_91 0x86BB4F
#define fnEprojInit_NuclearWaffleBody 0x86BB92
#define fnnullsub_92 0x86BBC6
#define fnEprojInit_NorfairLavaquakeRocks 0x86BBDB
#define fnEprojPreInstr_NorfairLavaquakeRocks 0x86BC0F
#define fnEproj_NorfairLavaquakeRocks_Func1 0x86BC16
#define fnEproj_NorfairLavaquakeRocks_Func2 0x86BC8F
#define fnEprojPreInstr_NorfairLavaquakeRocks_Inner 0x86BD1E
#define fnEprojPreInstr_NorfairLavaquakeRocks_Inner2 0x86BD2A
#define fnEprojInit_ShaktoolAttackMiddleBackCircle 0x86BD9C
#define fnEprojInit_BDA2 0x86BDA2
#define fnEprojInit_ShaktoolAttackFrontCircle 0x86BE03
#define fnEprojPreInstr_BE12 0x86BE12
#define fnEprojInit_MotherBrainRoomTurrets 0x86BE4F
#define fnEprojInit_MotherBrainRoomTurretBullets 0x86BF59
#define fnEprojPreInstr_MotherBrainRoomTurrets 0x86BFDF
#define fnEprojPreInstr_MotherBrainRoomTurretBullets 0x86C0E0
#define fnEprojInstr_SwitchJump 0x86C173
#define fnEprojInstr_UserPalette0 0x86C1B4
#define fnEproj_MotherBrainsBlueRingLasers 0x86C2F3
#define fnEproj_MoveToBlueRingSpawnPosition 0x86C335
#define fnEprojInit_MotherBrainBomb 0x86C482
#define fnEprojPreInstr_MotherBrainBomb 0x86C4C8
#define fnsub_86C605 0x86C605
#define fnEprojInit_MotherBrainDeathBeemFired 0x86C684
#define fnnullsub_366 0x86C76D
#define fnSpawnMotherBrainDeathBeam 0x86C7FB
#define fnEprojInit_MotherBrainRainbowBeam 0x86C80A
#define fnEprojPreInstr_MotherBrainRainbowBeam 0x86C814
#define fnEprojInit_MotherBrainsDrool 0x86C843
#define fnEprojPreInstr_C84D 0x86C84D
#define fnEprojInit_MotherBrainsDrool_Falling 0x86C886
#define fnEprojInstr_Add12ToY 0x86C8D0
#define fnEprojInit_MotherBrainsDeathExplosion 0x86C8F5
#define fnEprojPreInit_MotherBrainsDeathExplosion_0 0x86C914
#define fnEprojInit_MotherBrainsRainbowBeamExplosion 0x86C92F
#define fnEprojPreInstr_MotherBrainsRainbowBeamExplosion 0x86C94C
#define fnEprojInit_MotherBrainEscapeDoorParticles 0x86C961
#define fnEprojPreInstr_MotherBrainsExplodedDoorParticles 0x86C9D2
#define fnEprojInit_MotherBrainPurpleBreathBig 0x86CA6A
#define fnEprojInit_MotherBrainPurpleBreathSmall 0x86CA83
#define fnnullsub_94 0x86CAA3
#define fnEprojInstr_MotherBrainPurpleBreathIsActive 0x86CAEE
#define fnEprojInit_TimeBombSetJapaneseText 0x86CAF6
#define fnEprojPreInstr_TimeBombSetJapaneseText 0x86CAFA
#define fnEprojInit_MotherBrainTubeFalling 0x86CBC9
#define fnEprojPreInstr_MotherBrainTubeFalling 0x86CBE7
#define fnMotherBrainTubeFallingFunc_GenerateExplosion 0x86CBEA
#define fnMotherBrainTubeFallingFunc_Falling 0x86CC08
#define fnEprojInit_MotherBrainGlassShatteringShard 0x86CDC5
#define fnEprojInit_MotherBrainGlassShatteringSparkle 0x86CE6D
#define fnEprojPreInstr_MotherBrainGlassShatteringShard 0x86CE9B
#define fnEprojInit_KiHunterAcidSpitLeft 0x86CF90
#define fnEprojInit_KiHunterAcidSpitRight 0x86CFA6
#define fnsub_86CFD5 0x86CFD5
#define fnsub_86CFE6 0x86CFE6
#define fnnullsub_95 0x86CFF7
#define fnsub_86CFF8 0x86CFF8
#define fnEprojInit_KagosBugs 0x86D088
#define fnEprojPreInstr_KagosBugs_Func1 0x86D0B3
#define fnEprojPreInstr_KagosBugs 0x86D0CA
#define fnnullsub_302 0x86D0EB
#define fnEprojPreInstr_D0EC 0x86D0EC
#define fnEprojPreInstr_D128 0x86D128
#define fnEprojInstr_D15C 0x86D15C
#define fnEprojInstr_D1B6 0x86D1B6
#define fnEprojInstr_D1C7 0x86D1C7
#define fnEprojInstr_D1CE 0x86D1CE
#define fnEprojPreInstr_KagosBugs_Func2 0x86D1E4
#define fnEprojInit_MaridiaFloatersSpikes 0x86D23A
#define fnEprojPreInstr_MaridiaFloatersSpikes 0x86D263
#define fnEprojInit_WreckedShipRobotLaserDown 0x86D30C
#define fnEprojInit_WreckedShipRobotLaserHorizontal 0x86D32E
#define fnEprojInit_WreckedShipRobotLaserUp 0x86D341
#define fnEprojPreInstr_WreckedShipRobotLaser 0x86D3BF
#define fnEprojInstr_AssignNewN00bTubeShardVelocity 0x86D5E1
#define fnEprojInstr_SetN00bTubeShardX 0x86D5F2
#define fnEprojInstr_D62A 0x86D62A
#define fnEprojInstr_SetXvelRandom 0x86D69A
#define fnEprojInit_N00bTubeCrack 0x86D6A5
#define fnEprojInit_N00bTubeShards 0x86D6C9
#define fnEprojInit_N00bTubeReleasedAirBubbles 0x86D774
#define fnsub_86D7BF 0x86D7BF
#define fnsub_86D7DE 0x86D7DE
#define fnEprojPreInstr_N00bTubeShards 0x86D7FD
#define fnsub_86D83D 0x86D83D
#define fnsub_86D89F 0x86D89F
#define fnsub_86D8DF 0x86D8DF
#define fnsub_86D992 0x86D992
#define fnEprojPreInstr_SpikeShootingPlantSpikes 0x86D9DB
#define fnEprojPreInstr_SpikeShootingPlantSpikes_MoveY1 0x86D9E6
#define fnEprojPreInstr_SpikeShootingPlantSpikes_MoveY2 0x86DA10
#define fnEprojPreInstr_SpikeShootingPlantSpikes_MoveX1 0x86DA3A
#define fnEprojPreInstr_SpikeShootingPlantSpikes_MoveX2 0x86DA64
#define fnEprojPreInstr_SpikeShootingPlantSpikes_0_MoveX1 0x86DA8E
#define fnEprojPreInstr_SpikeShootingPlantSpikes_2_MoveX2 0x86DA93
#define fnEprojPreInstr_SpikeShootingPlantSpikes_1_MoveY1 0x86DA98
#define fnEprojPreInstr_SpikeShootingPlantSpikes_4_MoveY2 0x86DA9D
#define fnEprojPreInstr_SpikeShootingPlantSpikes_6_MoveX1Y1 0x86DAA2
#define fnEprojPreInstr_SpikeShootingPlantSpikes_8_MoveX1Y2 0x86DAAA
#define fnEprojPreInstr_SpikeShootingPlantSpikes_7_MoveX2Y1 0x86DAB2
#define fnEprojPreInstr_SpikeShootingPlantSpikes_9_MoveX2Y2 0x86DABA
#define fnEprojInit_DBF2 0x86DB18
#define fnEprojPreInstr_DBF2 0x86DB5B
#define fnEprojPreInstr_DBF2_MoveX1 0x86DB62
#define fnEprojPreInstr_DBF2_MoveX2 0x86DB8C
#define fnEprojPreInstr_DBF2_Func1 0x86DBB6
#define fnEprojInstr_DC5A 0x86DC5A
#define fnEprojInstr_SpawnEnemyDrops_0 0x86DC61
#define fnEprojInstr_SpawnSporesEproj 0x86DC77
#define fnEprojInit_Spores 0x86DC8D
#define fnEprojInit_SporeSpawnStalk 0x86DCA3
#define fnEprojInit_SporeSpawners 0x86DCD4
#define fnEprojPreInstr_Spores 0x86DCEE
#define fnnullsub_96 0x86DD44
#define fnEprojPreInstr_SporeSpawners 0x86DD46
#define fnEprojInit_NamiFuneFireball 0x86DED6
#define fnEprojPreInstr_NamiFuneFireball 0x86DF39
#define fnEprojInit_NamiFuneFireball_MoveX1 0x86DF40
#define fnEprojInit_NamiFuneFireball_MoveX2 0x86DF6A
#define fnEprojInstr_DFEA 0x86DFEA
#define fnEprojInit_LavaThrownByLavaman 0x86E000
#define fnsub_86E049 0x86E049
#define fnEproj_LavaThrownByLavaman_MoveX1 0x86E050
#define fnEproj_LavaThrownByLavaman_MoveX2 0x86E07A
#define fnEprojInit_DustCloudOrExplosion 0x86E468
#define fnEprojInit_EyeDoorSmoke 0x86E4A6
#define fnEprojPreInstr_DustCloudOrExplosion 0x86E4FE
#define fnEprojPreInstr_nullsub_98 0x86E508
#define fnEprojInstr_SetYVel 0x86E533
#define fnEprojInit_SpawnedShotGate 0x86E5D0
#define fnEprojInit_ClosedDownwardsShotGate 0x86E5D5
#define fnEprojInit_ClosedUpwardsShotGate 0x86E5DA
#define fnEprojPreInstr_nullsub_99 0x86E604
#define fnEprojPreInstr_E605 0x86E605
#define fnEprojInit_SaveStationElectricity 0x86E6AD
#define fnnullsub_100 0x86E6D1
#define fnEprojInit_BotwoonsBody 0x86EA31
#define fnEprojPreInstr_BotwoonsBody 0x86EA80
#define fnEproj_BotwoonsBody_Main 0x86EA98
#define fnEproj_BotwonsBodyFunction_DyingSetDelay 0x86EAF4
#define fnEproj_BotwonsBodyFunction_DyingWaiting 0x86EB04
#define fnEproj_BotwonsBodyFunction_DyingFalling 0x86EB1F
#define fnnullsub_101 0x86EB93
#define fnEprojInit_BotwoonsSpit 0x86EBC6
#define fnEprojPreInstr_BotwoonsSpit 0x86EC05
#define fnEprojInit_YappingMawsBody 0x86EC62
#define fnEprojPreInstr_Empty2 0x86EC94
#define fnEprojInstr_ECE3 0x86ECE3
#define fnEprojInstr_ED17 0x86ED17
#define fnEprojInstr_QueueSfx2_9 0x86EE8B
#define fnEprojInstr_QueueSfx2_24 0x86EE97
#define fnEprojInstr_QueueSfx2_B 0x86EEA3
#define fnEprojInstr_EEAF 0x86EEAF
#define fnEprojInstr_HandleRespawningEnemy 0x86EF10
#define fnEprojInit_F337 0x86EF29
#define fnEprojInit_EnemyDeathExplosion 0x86EF89
#define fnEprojPreInstr_Empty 0x86EFDF
#define fnEprojPreInstr_Pickup 0x86EFE0
#define fnEprojInit_Sparks 0x86F391
#define fnEprojPreInstr_Sparks 0x86F3F0
#define fnAnimtilesInstr_Delete 0x8780B2
#define fnAnimtilesInstr_Goto 0x8780B7
#define fnAnimtilesInstr_GotoRel_Unused 0x8780BC
#define fnAnimtilesInstr_DecrementTimerAndGoto_Unused 0x8780D4
#define fnAnimtilesInstr_DecrementTimerAndGotoRel_Unused 0x8780DC
#define fnAnimtilesInstr_SetTimer_Unused 0x8780E3
#define fnAnimtilesInstr_QueueMusic_Unused 0x8780F0
#define fnAnimtilesInstr_QueueSfx1_Unused 0x8780FC
#define fnAnimtilesInstr_QueueSfx2_Unused 0x878108
#define fnAnimtilesInstr_QueueSfx3_Unused 0x878114
#define fnAnimtilesInstr_GotoIfBossBitSet_Unused 0x878120
#define fnAnimtilesInstr_SetBossBit_Unused 0x878133
#define fnAnimtilesInstr_GotoIfEventHappened 0x87813F
#define fnAnimtilesInstr_SetEventHappened 0x878150
#define fnAnimtilesInstr_WaitUntilAreaBossDead_DoubleRet 0x8781BA
#define fnAnimtilesInstr_GotoIfBossBitSetInArea 0x878303
#define fnAnimtilesInstr_SpawnTourianStatueEyeGlow 0x878320
#define fnAnimtilesInstr_SpawnTourianStatueSoul 0x87832F
#define fnAnimtilesInstr_GotoIfTourianStatueBusy 0x87833E
#define fnAnimtilesInstr_TourianStatueSetState 0x878349
#define fnAnimtilesInstr_TourianStatueClearState 0x878352
#define fnAnimtilesInstr_Clear3PaletteColors 0x87835B
#define fnAnimtilesInstr_SpawnPalfxObj 0x878372
#define fnAnimtilesInstr_Write8PaletteColors 0x87837F
#define fnLayerBlendingHandler 0x888000
#define fnnullsub_9 0x888074
#define fnnullsub_10 0x8880B7
#define fnnullsub_11 0x88810C
#define fnPauseHook_Empty 0x8883E1
#define fnnullsub_293 0x8884B8
#define fnHdmaobjInstr_Delete 0x888569
#define fnHdmaobjInstr_SetPreInstr 0x888570
#define fnHdmaobjInstr_ClearPreInstr 0x888584
#define fnHdmaobjInstr_CallFarFunc 0x8885B4
#define fnHdmaobjInstr_Goto 0x8885EC
#define fnHdmaobjInstr_GotoRel 0x8885F1
#define fnHdmaobjInstr_DecrementAndGoto 0x888607
#define fnHdmaobjInstr_DecrementAndGotoRel 0x88860F
#define fnHdmaobjInstr_SetTimer 0x888616
#define fnHdmaobjInstr_SetHdmaControl 0x888622
#define fnHdmaobjInstr_SetHdmaTarget 0x888637
#define fnHdmaobjInstr_SetHdmaTablePtr 0x88864C
#define fnHdmaobjInstr_SetHdmaTableBank 0x888655
#define fnHdmaobjInstr_SetIndirectHdmaDataBank 0x88866A
#define fnHdmaobjInstr_Sleep 0x888682
#define fnHdmaobjPreInstr_Xray 0x8886EF
#define fnHdmaobjPreInstr_XrayFunc0_NoBeam 0x888732
#define fnnullsub_2 0x888753
#define fnHdmaobjPreInstr_XrayFunc1_BeamWidening 0x888754
#define fnHdmaobjPreInstr_XrayFunc2_FullBeam 0x8887AB
#define fnHdmaobjPreInstr_XrayFunc3_DeactivateBeam_RestoreBg2_Part1 0x888934
#define fnHdmaobjPreInstr_XrayFunc4_DeactivateBeam_RestoreBg2_Part2 0x8889BA
#define fnHdmaobjPreInstr_XrayFunc5_DeactivateBeam 0x888A08
#define fnHdmaobj_PreExplodeWhite 0x888B14
#define fnHdmaobj_PreExplodeYellow 0x888B32
#define fnHdmaobj_ExplodeYellow 0x888B39
#define fnHdmaobj_ExplodeWhite 0x888B47
#define fnHdmaobj_CleanUpTryCrystalFlash 0x888B4E
#define fnHdmaobjPreInstr_PowerBombExplode_SetWindowConf 0x888B8F
#define fnHdmaobjPreInstr_PowerBombExplode_Stage5_Afterglow 0x888B98
#define fnHdmaobjPreInstr_PowerBombExplode_ExplosionYellow 0x888DE9
#define fnHdmaobjPreInstr_PowerBombExplode_ExplosionWhite 0x888EB2
#define fnHdmaobjPreInstr_PowerBombExplode_PreExplosionWhite 0x8890DF
#define fnHdmaobjPreInstr_PowerBombExplode_PreExplosionYellow 0x8891A8
#define fnCrystalFlashSetupPart1 0x88A2E4
#define fnCrystalFlashSetupPart2 0x88A309
#define fnCrystalFlashCleanup 0x88A317
#define fnHdmaobjPreInstr_CrystalFlash_CustomLayerBlend 0x88A339
#define fnHdmaobjPreInstr_CrystalFlash_Stage2_AfterGlow 0x88A35D
#define fnHdmaobjPreInstr_CrystalFlash_Stage1_Explosion 0x88A552
#define fnHdmaobjPreInstr_FxType22_BG3Yscroll 0x88A643
#define fnHdmaobjInstr_SetPhaseIncreaseTimer_1 0x88A66C
#define fnHdmaobjPreInstr_BG3Xscroll 0x88A673
#define fnHdmaobjPreInstr_SkyLandBG2Xscroll 0x88ADB2
#define fnHdmaobjPreInstr_SkyLandBG2Xscroll2 0x88ADBA
#define fnHdmaobjPreInstr_SkyLandBG2XscrollInner 0x88ADC2
#define fnRoomCode_ScrollingSkyLand 0x88AF8D
#define fnHdmaobjPreInstr_FirefleaBG3XScroll 0x88B0BC
#define fnFxRisingFunction_LavaAcid 0x88B343
#define fnFxRisingFunction_LavaAcid_WaitToRise 0x88B367
#define fnFxRisingFunction_LavaAcid_Raising 0x88B382
#define fnHdmaobjInstr_LavaSoundTimer_112 0x88B3A9
#define fnHdmaobjPreInstr_LavaAcidBG3YScroll 0x88B3B0
#define fnHdmaobjInstr_SetPhaseDecreaseTimer_1 0x88B4CE
#define fnHdmaobjPreInstr_LavaAcidBG2YScroll 0x88B4D5
#define fnFxRisingFunction_C428_WaterNormal 0x88C428
#define fnFxRisingFunction_WaterWaitToRise 0x88C44C
#define fnFxRisingFunction_WaterRising 0x88C458
#define fnHdmaobjInstr_SetPhaseIncreaseTimer_Copy1 0x88C467
#define fnHdmaobjPreInstr_WaterBG3XScroll 0x88C48E
#define fnHdmaobjInstr_SetPhaseIncreaseTimer_Copy2 0x88C582
#define fnHdmaobjPreInstr_WaterBG2XScroll 0x88C589
#define fnHdmaobjPreInstr_WaterBG2XScroll_Func2 0x88C5E4
#define fnHdmaobjPreInstr_WaterBG2XScroll_Func1 0x88C636
#define fnHdmaobjInstr_SetVideoMode1_FloorAndHud 0x88D916
#define fnHdmaobjInstr_SetVideoMode1_Hud 0x88D949
#define fnHdmaobjInstr_RandomBg3XVel 0x88D981
#define fnHdmaobjPreInstr_RainBg3Scroll 0x88D9A1
#define fnHdmaobjPreInstr_SporesBG3Xscroll 0x88DA47
#define fnnullsub_112 0x88DB2E
#define fnHdmaobjPreInstr_FogBG3Scroll 0x88DB36
#define fnHdmaobjPreInstr_TourianEntranceStatueBg2YScroll_WaitForUnlock 0x88DBD7
#define fnHdmaobjPreInstr_TourianEntranceStatueBg2YScroll_DescentDelay 0x88DC23
#define fnHdmaobjPreInstr_TourianEntranceStatueBg2YScroll_Descending 0x88DC69
#define fnHdmaobjPreInstr_TourianEntranceStatueBg2YScroll_EnableScrolling 0x88DCBA
#define fnHdmaobjInstr_GotoIfEventHappened 0x88DCCB
#define fnHdmaobjPreInstr_BombTorizoHazeColorMathBgColor 0x88DD43
#define fnHdmaobjPreInstr_HazeColorMathSubscreen_CeresRidleyAlive 0x88DE10
#define fnHdmaobjPreInstr_HazeColorMathSubscreen_CeresRidleyDead 0x88DE15
#define fnHdmaobjPreInstr_HazeColorMathSubscreen_FadingIn 0x88DE2D
#define fnHdmaobjPreInstr_HazeColorMathSubscreen_FadedIn 0x88DE74
#define fnHdmaobjPreInstr_HazeColorMathSubscreen_FadingOut 0x88DE96
#define fnnullsub_113 0x88DF91
#define fnnullsub_114 0x88DF92
#define fnHdmaobjPreInstr_DraygonMainScreenLayers 0x88DF94
#define fnHdmaobjPreInstr_VariaSuitPickup 0x88E026
#define fnHdmaobjPreInstr_GravitySuitPickup 0x88E05C
#define fnHdmaobjPreInstr_PhantoonSemiTransparency 0x88E449
#define fnHdmaobjInstr_SetUpWavyPhantoon 0x88E4BD
#define fnHdmaobjPreInstr_WavyPhantoon 0x88E567
#define fnnullsub_357 0x88E726
#define fnInitializeRainbowBeam 0x88E767
#define fnHdmaobjPreInstr_MotherBrainRainbowBeam 0x88E7BC
#define fnHdmaobjInstr_InitMorphBallEyeBeamHdma 0x88E917
#define fnHdmaobjPreInstr_MorphBallEyeBeam_BeamWidening 0x88E9E6
#define fnHdmaobjPreInstr_MorphBallEyeBeam_FullBeam 0x88EA3C
#define fnHdmaobjPreInstr_MorphBallEyeBeam_DeactivateBeam 0x88EACB
#define fnHdmaobjInstr_ConfigTitleSequenceGradientHDMA 0x88EB9F
#define fnHdmaobjPreInstr_Backdrop_TitleSequenceGradient 0x88EBB0
#define fnHdmaobjPreInstr_ColorMathControlB_TitleGradient 0x88EBD2
#define fnHdmaobjPreInstr_IntroCutsceneCrossfade 0x88EC1D
#define fnHdmaobjInstr_SetUpWavySamus 0x88EC9F
#define fnHdmaobjPreInstr_WavySamus 0x88ECB6
#define fnRoomCode_CeresElevatorShaft 0x89ACC3
#define fnnullsub_5 0x8B8697
#define fnProcessCinematicBgObject 0x8B8839
#define fnProcessCinematicBgObject_Nothing 0x8B8849
#define fnProcessCinematicBgObject_DrawChar 0x8B884D
#define fnProcessCinematicBgObject_DrawToTextTilemap 0x8B88B7
#define fnProcessCinematicBgObject_DrawToBgTilemap 0x8B88FD
#define fnProcessCinematicBgObject_Unk1 0x8B896B
#define fnProcessCinematicBgObject_Unk2 0x8B89CF
#define fnCinematicFunction_Intro_Func20 0x8B8D23
#define fnCinematicFunction_nullsub_116 0x8B93D9
#define fnCinematicSprInstr_Delete 0x8B9438
#define fnCinematicSprInstr_Sleep 0x8B9442
#define fnCinematicSprInstr_SetPreInstr 0x8B944C
#define fnCinematicSprInstr_ClearPreInstr 0x8B9457
#define fnCinematicFunction_nullsub_298 0x8B945F
#define fnCinematicSprInstr_GotoRel 0x8B94A2
#define fnCinematicSprInstr_Goto 0x8B94BC
#define fnCinematicSprInstr_DecTimerGoto 0x8B94C3
#define fnCinematicSprInstr_DecTimerGotoRel 0x8B94CD
#define fnCinematicSprInstr_SetTimer 0x8B94D6
#define fnMode7Instr_Delete 0x8B956B
#define fnMode7Instr_SetPreInstr 0x8B9572
#define fnMode7Instr_ClearPreInstr 0x8B957D
#define fnMode7Instr_Goto 0x8B9586
#define fnMode7Instr_DecTimerAndGoto 0x8B958D
#define fnMode7Instr_SetTimer 0x8B9597
#define fnEnableCinematicBgTilemapUpdates 0x8B95B8
#define fnCinematicBgInstr_Delete 0x8B9698
#define fnCinematicBgInstr_Goto 0x8B971E
#define fnIntroObject_Delete 0x8B99FE
#define fnIntroObject_Goto 0x8B9A06
#define fnIntroObject_DecTimerGoto 0x8B9A0D
#define fnIntroObject_SetTimer 0x8B9A17
#define fnCinematicFunctionNone 0x8B9A47
#define fnCinematicSpriteInit_7 0x8B9B1A
#define fnCinematicSpriteInit_8 0x8B9B2D
#define fnCinematicSpriteInit_9 0x8B9B40
#define fnCinematicFunctionOpening 0x8B9B68
#define fnCinematicSpriteInit_0 0x8B9CBC
#define fnsub_8B9CCF 0x8B9CCF
#define fnCinematicSprInstr_9CE1 0x8B9CE1
#define fnCinematicFunc_Func2 0x8B9D17
#define fnCinematicSpriteInit_1 0x8B9D4A
#define fnCinematicSprInstr_9D5D 0x8B9D5D
#define fnCinematicFunc_Func4 0x8B9D90
#define fnCinematicSpriteInit_2 0x8B9DC3
#define fnCinematicSprInstr_9DD6 0x8B9DD6
#define fnCinematicFunc_Func5 0x8B9E12
#define fnCinematicSpriteInit_3 0x8B9E45
#define fnCinematicSprInstr_Func8 0x8B9E58
#define fnCinematicFunc_Func7 0x8B9E8B
#define fnCinematicSpriteInit_4 0x8B9EB3
#define fnCinematicSprInstr_Func9 0x8B9ECD
#define fnCinematicSpriteInit_5 0x8B9ED6
#define fnCinematicSprInstr_sub_8B9EF0 0x8B9EF0
#define fnCinematicSpriteInit_6 0x8B9EFF
#define fnCinematicSprInstr_9F19 0x8B9F19
#define fnnullsub_117 0x8B9F28
#define fnCinematicFunc_Func1 0x8B9F29
#define fnCinematicFunc_Func10 0x8B9F52
#define fnCinematicFunc_Func9 0x8B9FAE
#define fnPlayBabyMetroidCry1 0x8BA25B
#define fnPlayBabyMetroidCry2 0x8BA263
#define fnPlayBabyMetroidCry3 0x8BA26B
#define fnCinematicSetPal1 0x8BA273
#define fnCinematicSetPal2 0x8BA284
#define fnCinematicSetPal3 0x8BA295
#define fnCinematicSetPal4 0x8BA2A6
#define fnnullsub_120 0x8BA38F
#define fnnullsub_121 0x8BA390
#define fnCinematicFunc_Nothing 0x8BA391
#define fnCinematicFunction_Intro_Initial 0x8BA395
#define fnCinematicFunction_Intro_FadeIn 0x8BA5A7
#define fnCinematicFunction_Intro_DrawInitJpn 0x8BA5BD
#define fnCinematicFunction_Intro_LastMetroidCaptivity 0x8BA5F8
#define fnCinematicFunc_Intro_QueueGalaxyIsAtPeace 0x8BA613
#define fnCinematicFunc_Intro_WaitForQueueWait4secs 0x8BA639
#define fnCinematicFunc_Intro_FadeOut 0x8BA64C
#define fnCinematicFunc_Intro_WaitForFadeOut 0x8BA663
#define fnCinematicFunc_Intro_SetupTextPage2 0x8BA66F
#define fnCinematicFunc_Intro_WaitFadeinShowText 0x8BA82B
#define fnCinematicFunc_Intro_WaitForFadeinSleep 0x8BA84A
#define fnSetSomeStuffForSpriteObject_2 0x8BA8C1
#define fnnullsub_122 0x8BA8D4
#define fnSetSomeStuffForSpriteObject_3 0x8BA8D5
#define fnSetSomeStuffForSpriteObject_4_MetroidEgg 0x8BA8E8
#define fnCinematicSprPreInstr_A903 0x8BA903
#define fnCinematicSprInstr_SpawnMetroidEggParticles 0x8BA918
#define fnSetSomeStuffForSpriteObject_6 0x8BA958
#define fnSetSomeStuffForSpriteObject_7 0x8BA994
#define fnSetSomeStuffForSpriteObject_8 0x8BAA9A
#define fnSetSomeStuffForSpriteObject_9 0x8BAAB3
#define fnSetSomeStuffForSpriteObject_10 0x8BAD55
#define fnSetSomeStuffForSpriteObject_11 0x8BAD68
#define fnSetSomeStuffForSpriteObject_12 0x8BAD93
#define fnSetSomeStuffForSpriteObject_13 0x8BADA6
#define fnCinematicBgInstr_SetSomeStuffForSpriteObject_14 0x8BADD4
#define fnSetSomeStuffForSpriteObject_17 0x8BAE07
#define fnSetSomeStuffForSpriteObject_18 0x8BAE1A
#define fnCinematicBgInstr_HandleCreateJpnText_Page1 0x8BAE43
#define fnCinematicBgInstr_SpawnMarkerWaitInput_Page1 0x8BAE5B
#define fnCinematicBgInstr_HandleCreateJpnText_Page2 0x8BAE79
#define fnCinematicBgInstr_SpawnMarkerWaitInput_Page2 0x8BAE91
#define fnCinematicFunction_Intro_WaitInputSetupMotherBrainFight 0x8BAEB8
#define fnCinematicFunction_Intro_WaitInputSetupBabyMetroid 0x8BAF6C
#define fnCinematicBgInstr_HandleCreateJpnText_Page3 0x8BB074
#define fnCinematicBgInstr_SpawnMarkerWaitInput_Page3 0x8BB08C
#define fnCinematicBgInstr_HandleCreateJpnText_Page4 0x8BB0B3
#define fnCinematicBgInstr_SpawnMarkerWaitInput_Page4 0x8BB0CB
#define fnCinematicFunction_Intro_Func11 0x8BB0F2
#define fnCinematicFunction_Intro_Func12 0x8BB123
#define fnCinematicFunction_Intro_Func13 0x8BB151
#define fnCinematicBgInstr_HandleCreateJpnText_Page5 0x8BB19B
#define fnCinematicBgInstr_SpawnMarkerWaitInput_Page5 0x8BB1B3
#define fnCinematicFunction_Intro_Func15 0x8BB1DA
#define fnCinematicFunction_Intro_Func15b 0x8BB207
#define fnCinematicBgInstr_Func16 0x8BB228
#define fnCinematicBgInstr_Func17 0x8BB240
#define fnCinematicFunction_Intro_XfadeGameplayFade 0x8BB250
#define fnCinematicFunction_Intro_XfadeScientistFade 0x8BB2D2
#define fnCinematicSprInstr_StartIntroPage2 0x8BB336
#define fnCinematicSprInstr_StartIntroPage3 0x8BB33E
#define fnCinematicSprInstr_StartIntroPage4 0x8BB346
#define fnCinematicSprInstr_StartIntroPage5 0x8BB34E
#define fnCinematicFunction_Intro_Page2 0x8BB35F
#define fnCinematicFunction_Intro_Page3 0x8BB370
#define fnCinematicFunction_Intro_Page4 0x8BB381
#define fnCinematicFunction_Intro_Page5 0x8BB392
#define fnCinematicFunction_Intro_Fadestuff 0x8BB3F4
#define fnCinematicFunction_Intro_Fadestuff2 0x8BB458
#define fnCinematicBgPreInstr_SamusBlink 0x8BB4BC
#define fnCinematicFunction_Intro_Func19 0x8BB4DC
#define fnCinematicFunction_Intro_Func18 0x8BB4EB
#define fnEnableCinematicBgTilemapUpdates_ 0x8BB519
#define fnsub_8BB51E 0x8BB51E
#define fnEnableCinematicBgTilemapUpdates__0 0x8BB54F
#define fnCinematicFunction_Intro_Func21 0x8BB554
#define fnCinematicFunction_Intro_Func22 0x8BB585
#define fnCinematicFunction_Intro_ThenWaitInputSetupBabyMetroid 0x8BB5B8
#define fnCinematicFunction_Intro_Func23 0x8BB5C3
#define fnCinematicFunction_Intro_Func24 0x8BB5EE
#define fnCinematicFunction_Intro_Func25 0x8BB61B
#define fnCinematicFunction_Intro_Func26 0x8BB626
#define fnCinematicFunction_Intro_Func27 0x8BB657
#define fnCinematicFunction_Intro_Func28 0x8BB68A
#define fnCinematicFunction_Intro_Func29 0x8BB695
#define fnCinematicFunction_Intro_Func30 0x8BB6C0
#define fnCinematicFunction_Intro_Func31 0x8BB6ED
#define fnCinematicFunction_Intro_Func32 0x8BB6F8
#define fnEnableCinematicBgTilemapUpdates__ 0x8BB70B
#define fnnullsub_26 0x8BB710
#define fnCinematicFunction_Intro_Func34 0x8BB72F
#define fnCinematicFunction_Intro_Func35 0x8BB773
#define fnCinematicFunction_Intro_Func36 0x8BB786
#define fnCinematicFunction_Intro_Func39 0x8BB80F
#define fnCinematicSprPreInstr_B82E 0x8BB82E
#define fnCinematicFunction_Intro_Func42 0x8BB896
#define fnCinematicSprInstr_Func43 0x8BB8C5
#define fnCinematicFunction_Intro_Func44 0x8BB8D8
#define fnCinematicFunction_Intro_Func45 0x8BB93B
#define fnCinematicFunction_Intro_Func46 0x8BB98D
#define fnCinematicFunction_Intro_Func47 0x8BB9D4
#define fnCinematicFunction_Intro_Func48 0x8BBA0F
#define fnCinematicSprInstr_SpawnIntroRinkas01 0x8BBA21
#define fnCinematicSprInstr_SpawnIntroRinkas23 0x8BBA36
#define fnCinematicFunction_Intro_Func49 0x8BBA4B
#define fnCinematicFunction_Intro_Func50 0x8BBA5E
#define fnCinematicFunction_Intro_Func51 0x8BBA73
#define fnCinematicFunction_Intro_Func52 0x8BBB0D
#define fnCinematicFunction_Intro_Func53 0x8BBB24
#define fnCinematicFunction_Intro_Func54 0x8BBCA0
#define fnCinematicFunction_Intro_Func55 0x8BBDE4
#define fnCinematicFunction_Intro_Func56 0x8BBDF9
#define fnCinematicFunction_Intro_Func57 0x8BBE7E
#define fnCinematicFunction_Intro_Func58 0x8BBEB5
#define fnCinematicFunction_Intro_Func59 0x8BBF22
#define fnCinematicFunction_Intro_Func60 0x8BBF35
#define fnCinematicFunction_Intro_Func61 0x8BBF4C
#define fnCinematicFunction_Intro_Func62 0x8BBF5F
#define fnCinematicFunction_Intro_Func63 0x8BBF76
#define fnCinematicFunction_Intro_Func64 0x8BBF89
#define fnCinematicFunction_Intro_Func65 0x8BBFA0
#define fnCinematicFunction_Intro_Func66 0x8BBFC6
#define fnCinematicSprPreInstr_nullsub_300 0x8BBFD9
#define fnCinematicFunction_Intro_Func67 0x8BBFDA
#define fnCinematicFunction_Intro_Func68 0x8BC083
#define fnCinematicCommonInstr_Func69 0x8BC096
#define fnCinematicCommonInstr_Func70 0x8BC0A2
#define fnCinematicFunction_Intro_Func71 0x8BC0B2
#define fnCinematicFunction_Intro_Func72 0x8BC0C5
#define fnCinematicFunction_Intro_Func73 0x8BC100
#define fnCinematicFunctionBlackoutFromCeres 0x8BC11B
#define fnCinematicFunction_Intro_Func74 0x8BC2E4
#define fnCinematicFunction_Intro_Func75 0x8BC2F1
#define fnCinematicFunction_Intro_Func76 0x8BC345
#define fnCinematicSprInstr_SpawnCeresExplosions1 0x8BC404
#define fnCinematicFunction_Intro_Func78 0x8BC434
#define fnCinematicSprPreInstr_C489 0x8BC489
#define fnCinematicFunction_Intro_Func80 0x8BC4B9
#define fnCinematicSprInstr_SpawnCeresExplosions3 0x8BC50C
#define fnCinematicFunction_Intro_Func81 0x8BC533
#define fnCinematicFunction_Intro_Func82 0x8BC582
#define fnCinematicFunction_Intro_Func83 0x8BC5A9
#define fnCinematicFunction_Intro_Func77 0x8BC5CA
#define fnCinematicFunction_Intro_Func84 0x8BC610
#define fnCinematicFunction_Intro_Func85 0x8BC627
#define fnCinematicFunction_Intro_Func86 0x8BC699
#define fnCinematicFunction_Intro_Func87 0x8BC79C
#define fnCinematicFunction_Intro_Func88 0x8BC7CA
#define fnCinematicFunction_Intro_Func89 0x8BC83B
#define fnCinematicFunction_Intro_Func90 0x8BC84E
#define fnCinematicFunction_Intro_Func91 0x8BC85D
#define fnCinematicFunction_Intro_Func92 0x8BC897
#define fnCinematicFunction_Intro_Func93 0x8BC8AA
#define fnCinematicFunction_Intro_Func94 0x8BC8B9
#define fnCinematicFunction_Intro_Func96 0x8BC8F9
#define fnCinematicFunction_Intro_Func97 0x8BC908
#define fnCinematicFunction_Intro_Func98 0x8BC942
#define fnCinematicFunction_Intro_Func99 0x8BC956
#define fnCinematicFunction_Intro_Func100 0x8BC96A
#define fnCinematicFunction_Intro_Func101 0x8BC97E
#define fnCinematicFunction_Intro_Func102 0x8BC992
#define fnCinematicSprInstr_C9A5 0x8BC9A5
#define fnCinematicSprInstr_C9AF 0x8BC9AF
#define fnCinematicSprInstr_C9BD 0x8BC9BD
#define fnCinematicSprInstr_C9C7 0x8BC9C7
#define fnCinematicFunction_Intro_Func104 0x8BC9E6
#define fnCinematicFunction_Intro_Func105 0x8BC9F9
#define fnCinematicFunction_Intro_Func106 0x8BCA36
#define fnCinematicFunction_Intro_Func107 0x8BCA85
#define fnCinematicFunction_Intro_Func108 0x8BCAD0
#define fnnullsub_124 0x8BCADE
#define fnCinematicFunction_Intro_Func95 0x8BCADF
#define fnCinematicFunctionEscapeFromCebes 0x8BD480
#define fnCinematicFunction_Intro_Func109 0x8BD6D7
#define fnCinematicFunction_Intro_Func110 0x8BD6F2
#define fnCinematicFunction_Intro_Func111 0x8BD701
#define fnCinematicFunction_Intro_Func112 0x8BD731
#define fnCinematicFunction_Intro_Func113 0x8BD7F8
#define fnCinematicFunction_Intro_Func114 0x8BD807
#define fnCinematicFunction_Intro_Func115 0x8BD837
#define fnCinematicFunction_Intro_Func116 0x8BDA02
#define fnCinematicFunction_Intro_Func117 0x8BDA1A
#define fnCinematicFunction_Intro_Func118 0x8BDAD3
#define fnnullsub_125 0x8BDB9D
#define fnCinematicFunction_Intro_Func119 0x8BDB9E
#define fnCinematicFunction_Intro_Func120 0x8BDBC4
#define fnCinematicFunction_Intro_Func121 0x8BDCA5
#define fnCinematicFunction_Intro_Func123 0x8BDD42
#define fnCinematicFunction_Intro_Func124 0x8BDDCD
#define fnnullsub_126 0x8BDE63
#define fnCinematicFunction_Intro_Func125 0x8BDE64
#define fnCinematicFunction_Intro_Func126 0x8BDE80
#define fnCinematicFunction_Intro_Func129 0x8BE0F4
#define fnCinematicFunction_Intro_Func130 0x8BE110
#define fnCinematicFunction_Intro_Func131 0x8BE158
#define fnCinematicFunction_Intro_Func132 0x8BE190
#define fnCinematicFunction_Intro_Func134 0x8BE1D2
#define fnCinematicFunction_Intro_Func136 0x8BE265
#define fnCinematicFunction_Intro_Func135 0x8BE293
#define fnCinematicFunction_Intro_Func137 0x8BE2DD
#define fnCinematicFunction_Intro_Func138 0x8BE314
#define fnCinematicFunction_Intro_Func145 0x8BE342
#define fnCinematicFunction_Intro_Func139 0x8BE3AE
#define fnCinematicFunction_Intro_Func141 0x8BE48A
#define fnCinematicFunction_Intro_Func143 0x8BE504
#define fnCinematicFunction_Intro_Func144 0x8BE58A
#define fnCalcItemPercentageCount 0x8BE627
#define fnCinematicFunction_Intro_Func146 0x8BE769
#define fnCinematicFunction_Intro_Func147 0x8BE780
#define fnCinematicFunction_Intro_Func148 0x8BE797
#define fnnullsub_127 0x8BE7BA
#define fnCinematicFunction_Intro_Func150 0x8BEF99
#define fnCinematicFunction_Intro_Func151 0x8BEFB2
#define fnCinematicFunction_Intro_Func152 0x8BEFEA
#define fnCinematicFunction_Intro_Func153 0x8BEFFD
#define fnCinematicFunction_Intro_Func154 0x8BF005
#define fnCinematicFunction_Intro_Func155 0x8BF018
#define fnCinematicFunction_Intro_Func156 0x8BF02B
#define fnCinematicFunction_Intro_Func157 0x8BF03E
#define fnCinematicFunction_Intro_Func159 0x8BF05E
#define fnCinematicFunction_Intro_Func161 0x8BF06D
#define fnCinematicFunction_Intro_Func162 0x8BF07C
#define fnCinematicFunction_Intro_Func163 0x8BF085
#define fnCinematicFunction_Intro_Func164 0x8BF094
#define fnCinematicFunction_Intro_Func165 0x8BF0B2
#define fnCinematicFunction_Intro_Func166 0x8BF0E1
#define fnCinematicFunction_Intro_Func167 0x8BF0E9
#define fnCinematicFunction_Intro_Func168 0x8BF0F1
#define fnCinematicFunction_Intro_Func169 0x8BF0F9
#define fnCinematicFunction_Intro_Func170 0x8BF11E
#define fnCinematicFunction_Intro_Func171 0x8BF143
#define fnCinematicFunction_Intro_Func172 0x8BF156
#define fnCinematicFunction_Intro_Func173 0x8BF169
#define fnCinematicFunction_Intro_Func174 0x8BF17C
#define fnCinematicFunction_Intro_Func175 0x8BF18F
#define fnCinematicFunction_Intro_Func176 0x8BF1A8
#define fnCinematicFunction_Intro_Func177 0x8BF1C1
#define fnCinematicFunction_Intro_Func178 0x8BF1D4
#define fnCinematicFunction_Intro_Func179 0x8BF1E7
#define fnCinematicFunction_Intro_Func180 0x8BF227
#define fnCinematicSprInstr_Func181 0x8BF25E
#define fnCinematicSprInstr_Func182 0x8BF284
#define fnCinematicSprInstr_Func183 0x8BF295
#define fnCinematicFunction_Intro_Func184 0x8BF2A5
#define fnCinematicSprInstr_Func185 0x8BF2B7
#define fnCinematicSprInstr_Func186 0x8BF2FA
#define fnCinematicSprInstr_Func187 0x8BF32B
#define fnCinematicSprPreInstr_F35A 0x8BF35A
#define fnCinematicFunction_Intro_Func189 0x8BF375
#define fnCinematicFunction_Intro_Func189b 0x8BF39B
#define fnCinematicSprInstr_Func190 0x8BF3B0
#define fnCinematicFunction_Intro_Func191 0x8BF3B9
#define fnCinematicSprInstr_Func192 0x8BF3CE
#define fnCinematicSprInstr_Func193 0x8BF41B
#define fnCinematicSprInstr_Func194 0x8BF424
#define fnCinematicSprInstr_Func195 0x8BF42D
#define fnCinematicSprInstr_Func196 0x8BF436
#define fnCinematicSprInstr_Func197 0x8BF43F
#define fnCinematicSprInstr_Func198 0x8BF448
#define fnCinematicFunction_Intro_Func199 0x8BF455
#define fnCinematicFunction_Intro_Func200 0x8BF464
#define fnCinematicFunction_Intro_Func201 0x8BF478
#define fnCinematicFunction_Intro_Func202 0x8BF487
#define fnCinematicFunction_Intro_Func203 0x8BF49B
#define fnCinematicFunction_Intro_Func204 0x8BF4AA
#define fnCinematicFunction_Intro_Func205 0x8BF4D1
#define fnCinematicFunction_Intro_Func206 0x8BF4E0
#define fnCinematicFunction_Intro_Func207 0x8BF507
#define fnnullsub_128 0x8BF51C
#define fnCinematicSprInstr_Func208 0x8BF51D
#define fnCinematicSprPreInstr_F528 0x8BF528
#define fnCinematicSprInstr_Func211 0x8BF554
#define fnCinematicSprPreInstr_F57F 0x8BF57F
#define fnCinematicSprInstr_Func213 0x8BF597
#define fnCinematicSprInstr_Func214 0x8BF5BA
#define fnCinematicFunction_Intro_Func215 0x8BF5DD
#define fnCinematicSprInstr_Func217 0x8BF604
#define fnCinematicSprInstr_Func218 0x8BF651
#define fnCinematicFunction_Intro_Func219 0x8BF6FE
#define fnPalPreInstr_nullsub_129 0x8DC526
#define fnPalInstr_Wait 0x8DC595
#define fnPalInstr_ColorPlus2 0x8DC599
#define fnPalInstr_ColorPlus3 0x8DC5A2
#define fnPalInstr_ColorPlus4 0x8DC5AB
#define fnPalInstr_ColorPlus8 0x8DC5B4
#define fnPalInstr_ColorPlus9 0x8DC5BD
#define fnUNUSED_PalInstr_ColorPlus15 0x8DC5C6
#define fnPalInstr_Delete 0x8DC5CF
#define fnPalInstr_SetPreInstr 0x8DC5D4
#define fnUNUSED_PalInstr_ClearPreInstr 0x8DC5DD
#define fnPalInstr_Goto 0x8DC61E
#define fnPalInstr_DecTimerGoto 0x8DC639
#define fnPalInstr_SetTimer 0x8DC648
#define fnPalInstr_SetColorIndex 0x8DC655
#define fnUNUSED_PalInstr_QueueMusic 0x8DC65E
#define fnUNUSED_PalInstr_QueueSfx1 0x8DC66A
#define fnPalInstr_QueueSfx2 0x8DC673
#define fnUNUSED_PalInstr_QueueSfx3 0x8DC67C
#define fnnullsub_131 0x8DC685
#define fnPalInit_E1BC_OldMotherBrainFightBgLights 0x8DE204
#define fnPalPreInstr_DisableBgLightsIfIntroPage2 0x8DE20B
#define fnPalPreInstr_CheckEnemy0Health 0x8DE2E0
#define fnPalPreInstr_SamusInHeat 0x8DE379
#define fnPalInit_F761_Norfair1_Tourian1 0x8DE440
#define fnPalPreInstr_SwitchIfYpos 0x8DEC59
#define fnPalPreInstr_SwitchIfYpos2 0x8DED84
#define fnPalPreInstr_DeletePalfxIfMinibossDead 0x8DEEC5
#define fnPalInstr_SetPalfxIndex 0x8DF1C6
#define fnPalPreInstr_DeletePalfxIfTwoMoreFxActive 0x8DF621
#define fnPalInit_F779_Brinstar8 0x8DF730
#define fnRoomSetup_AfterSavingAnimals 0x8F9194
#define fnRoomSetup_AutoDestroyWallAfterEscape 0x8F91A9
#define fnRoomSetup_TurnWallIntoShotblocks 0x8F91B2
#define fnnullsub_132 0x8F91BB
#define fnnullsub_133 0x8F91BC
#define fnRoomSetup_ShakeDuringEscape 0x8F91BD
#define fnRoomSetup_ScrollingSkyLand 0x8F91C9
#define fnRoomSetup_ScrollingSkyOcean 0x8F91CE
#define fnnullsub_134 0x8F91D3
#define fnnullsub_135 0x8F91D4
#define fnnullsub_136 0x8F91D5
#define fnnullsub_137 0x8F91D6
#define fnRoomSetup_RunStatueUnlockAnims 0x8F91D7
#define fnnullsub_138 0x8F91F4
#define fnnullsub_139 0x8F91F5
#define fnnullsub_140 0x8F91F6
#define fnnullsub_141 0x8F91F7
#define fnDoorCode_StartWreckedShipTreadmill_West 0x8FB971
#define fnDoorCode_Scroll6_Green 0x8FB981
#define fnDoorCode_Scroll0_Blue 0x8FB98C
#define fnDoorCode_Scroll13_Blue 0x8FB997
#define fnDoorCode_Scroll_4Blue_8Green 0x8FB9A2
#define fnDoorCode_Scroll_8toB_Red 0x8FB9B3
#define fnDoorCode_Scroll_LotsRed 0x8FB9CA
#define fnDoorCode_Scroll_1_4_Green 0x8FB9F1
#define fnDoorCode_Scroll_2_Blue 0x8FBA00
#define fnDoorCode_Scroll_17_Blue 0x8FBA0B
#define fnDoorCode_Scroll_4_Blue 0x8FBA16
#define fnDoorCode_Scroll_6_Green 0x8FBA21
#define fnDoorCode_Scroll_3_Green 0x8FBA2C
#define fnDoorCode_SetScroll_0 0x8FBD07
#define fnDoorCode_SetScroll_1 0x8FBD16
#define fnDoorCode_SetScroll_2 0x8FBD25
#define fnDoorCode_SetScroll_3 0x8FBD30
#define fnDoorCode_SetScroll_4 0x8FBD3F
#define fnDoorCode_SetScroll_5 0x8FBD50
#define fnDoorCode_SetScroll_6 0x8FBD5B
#define fnDoorCode_SetScroll_7 0x8FBD6C
#define fnDoorCode_SetScroll_8 0x8FBD77
#define fnDoorCode_SetScroll_9 0x8FBD8A
#define fnDoorCode_SetScroll_10 0x8FBD95
#define fnDoorCode_SetScroll_11 0x8FBDA0
#define fnDoorCode_SetScroll_12 0x8FBDAF
#define fnDoorCode_SetScroll_13 0x8FBDC0
#define fnDoorCode_SetScroll_14 0x8FBDD1
#define fnDoorCode_SetScroll_15 0x8FBDE2
#define fnDoorCode_SetScroll_16 0x8FBDF1
#define fnDoorCode_SetScroll_17 0x8FBE00
#define fnDoorCode_SetScroll_18 0x8FBE0B
#define fnDoorCode_SetScroll_19 0x8FBE1A
#define fnDoorCode_SetScroll_20 0x8FBE25
#define fnDoorCode_SetScroll_21 0x8FBE36
#define fnDoorCode_SetScroll_22 0x8FBF9E
#define fnDoorCode_SetScroll_23 0x8FBFBB
#define fnDoorCode_SetScroll_24 0x8FBFDA
#define fnDoorCode_SetScroll_25 0x8FBFE9
#define fnDoorCode_SetScroll_26 0x8FBFFA
#define fnDoorCode_SetScroll_28 0x8FC016
#define fnDoorCode_SetScroll_29 0x8FC025
#define fnDoorCode_SetScroll_30 0x8FC03A
#define fnDoorCode_SetScroll_31 0x8FC04B
#define fnDoorCode_SetScroll_32 0x8FC056
#define fnDoorCode_SetScroll_33 0x8FC067
#define fnDoorCode_SetScroll_34 0x8FC078
#define fnDoorCode_SetScroll_35 0x8FC089
#define fnDoorCode_SetScroll_36 0x8FC0A2
#define fnDoorCode_SetScroll_37 0x8FC0AD
#define fnDoorCode_SetScroll_38 0x8FC0C2
#define fnDoorCode_SetScroll_39 0x8FC0D3
#define fnDoorCode_SetScroll_40 0x8FC0DE
#define fnDoorCode_SetScroll_41 0x8FC0EF
#define fnDoorCode_SetScroll_42 0x8FC0FA
#define fnDoorCode_SetScroll_43 0x8FC10B
#define fnRoomCode_ScrollingSkyLand_ 0x8FC116
#define fnRoomCode_ScrollingSkyOcean_ 0x8FC11B
#define fnRoomCode_ScrollingSkyLand_Shakes 0x8FC120
#define fnRoomCode_ExplodeShakes 0x8FC124
#define fnRoomCode_GenRandomExplodes_4th 0x8FC183
#define fnRoomCode_GenRandomExplodes 0x8FC1A9
#define fnRoomCode_ScrollRightDachora 0x8FC1E6
#define fnnullsub_142 0x8FC8C7
#define fnRoomCode_SpawnPrePhantoonRoomEnemyProj 0x8FC8C8
#define fnnullsub_143 0x8FC8D0
#define fnnullsub_144 0x8FC8D1
#define fnnullsub_145 0x8FC8D2
#define fnRoomCode_SetupShaktoolRoomPlm 0x8FC8D3
#define fnnullsub_146 0x8FC8DC
#define fnRoomCode_SetPauseCodeForDraygon 0x8FC8DD
#define fnPauseHook_DraygonRoom 0x8FC8F6
#define fnUnpauseHook_DraygonRoom 0x8FC8FC
#define fnRoomCode_SetCollectedMap 0x8FC90A
#define fnnullsub_147 0x8FC91E
#define fnRoomCode_SetZebesTimebombEvent 0x8FC91F
#define fnRoomCode_SetLightHorizRoomShake 0x8FC933
#define fnRoomCode_SetMediumHorizRoomShake 0x8FC946
#define fnRoomCode_Escape4_SetMediumHorizRoomShake 0x8FC953
#define fnRoomCode_SetCeresDoorSolid 0x8FC96E
#define fnRoomCode_SpawnHaze 0x8FC976
#define fnRoomCode_SpawnHaze_BgBase 0x8FC97B
#define fnDoorCode_StartWreckedSkipTreadmill_East 0x8FE1D8
#define fnDoorCode_SetScroll_44 0x8FE1E8
#define fnDoorCode_SetScroll_45 0x8FE1F3
#define fnDoorCode_SetScroll_46 0x8FE1FE
#define fnDoorCode_SetScroll_47 0x8FE20F
#define fnDoorCode_SetScroll_48 0x8FE21A
#define fnDoorCode_SetScroll_49 0x8FE229
#define fnDoorCode_SetupElevatubeFromSouth 0x8FE26C
#define fnDoorCode_SetupElevatubeFromNorth 0x8FE291
#define fnRoomCode_Elevatube 0x8FE2B6
#define fnDoorCode_ResetElevatubeNorthExit 0x8FE301
#define fnDoorCode_ResetElevatubeSouthExit 0x8FE309
#define fnDoorCode_SetScroll_50 0x8FE318
#define fnDoorCode_SetScroll_53 0x8FE345
#define fnDoorCode_SetScroll_54 0x8FE356
#define fnDoorCode_SetScroll_55 0x8FE367
#define fnDoorCode_SetScroll_56 0x8FE378
#define fnDoorCode_SetScroll_57 0x8FE38D
#define fnDoorCode_SetScroll_58 0x8FE398
#define fnDoorCode_SetScroll_59 0x8FE3A3
#define fnDoorCode_SetScroll_61 0x8FE3B9
#define fnDoorCode_SetScroll_62 0x8FE3C8
#define fnDoorCode_SetScroll_63 0x8FE3D9
#define fnDoorCode_SetScroll_64 0x8FE4C0
#define fnDoorCode_SetScroll_65 0x8FE4CF
#define fnDoorCode_ToCeresElevatorShaft 0x8FE4E0
#define fnDoorCode_FromCeresElevatorShaft 0x8FE513
#define fnRoomCode_CeresElevatorShaft_ 0x8FE51F
#define fnnullsub_148 0x8FE524
#define fnRoomCode_SpawnCeresFallingDebris 0x8FE525
#define fnRoomCode_HandleCeresRidleyGetaway 0x8FE571
#define fnRoomCode_ShakeScreenHorizDiag 0x8FE57C
#define fnRoomCode_GenRandomExplodes_Every4Frames 0x8FE5A0
#define fnRoomCode_ShakeScreenHorizDiagStrong 0x8FE5A4
#define fnRoomDefStateSelect_Finish 0x8FE5E6
#define fnRoomDefStateSelect_MainAreaBossDead 0x8FE5FF
#define fnRoomDefStateSelect_IsEventSet 0x8FE612
#define fnRoomDefStateSelect_IsBossDead 0x8FE629
#define fnRoomDefStateSelect_CollectedMorphBallAndMissiles 0x8FE652
#define fnRoomDefStateSelect_CollectedPowerBombs 0x8FE669
#define fnRoomCode_CrocomireRoomShaking 0x8FE8CD
#define fnRoomCode_RidleyRoomShaking 0x8FE950
#define fnnullsub_12 0x908077
#define fnSamus_Draw 0x9085E2
#define fnnullsub_3 0x9092E9
#define fnSamus_MovementHandler_ReleaseFromGrapple 0x90946E
#define fnSamus_MovementHandler_DrainedCrouching 0x9094CB
#define fnSamus_ScrollFinishedHook_SporeSpawnFight 0x909589
#define fnSamus_MovementHandler_Normal 0x90A337
#define fnnullsub_13 0x90A671
#define fnProjPreInstr_Beam_NoWaveBeam 0x90AEF3
#define fnProjPreInstr_BlockCollNoWaveBeamVert 0x90AF4A
#define fnProjPreInstr_BlockCollNoWaveBeamDiagonal 0x90AF52
#define fnProjPreInstr_BlockCollNoWaveBeamHoriz 0x90AF60
#define fnProjPreInstr_Missile 0x90AF68
#define fnProjPreInstr_BlockCollMissileVert 0x90AFC7
#define fnProjPreInstr_BlockCollMissileDiagonal 0x90AFCF
#define fnProjPreInstr_BlockCollMissileHoriz 0x90AFDD
#define fnProjPreInstr_SuperMissile 0x90AFE5
#define fnProjPreInstr_BlockCollSuperMissileVert 0x90B047
#define fnProjPreInstr_BlockCollSuperMissileDiagonal 0x90B052
#define fnProjPreInstr_BlockCollSuperMissileHoriz 0x90B06A
#define fnProjPreInstr_SuperMissileLink 0x90B075
#define fnProjPreInstr_Bomb 0x90B099
#define fnProjPreInstr_PowerBomb 0x90B0AE
#define fnProjPreInstr_WaveCombined 0x90B0C3
#define fnProjPreInstr_BeamOrIceWave 0x90B0E4
#define fnProjPreInstr_Wave_Shared 0x90B103
#define fnProjPreInstr_BlockCollWaveBeamVert 0x90B13B
#define fnProjPreInstr_BlockCollWaveBeamDiagonal 0x90B143
#define fnProjPreInstr_BlockCollWaveBeamHoriz 0x90B151
#define fnProjPreInstr_HyperBeam 0x90B159
#define fnProjPreInstr_Empty 0x90B169
#define fnProjTrailInstr_MoveLeftProjectileTrailDown 0x90B525
#define fnProjTrailInstr_MoveRightProjectileTrailDown 0x90B587
#define fnProjTrailInstr_MoveLeftProjectileTrailUp 0x90B5B3
#define fnProjPreInstr_IceSbaMain 0x90CF09
#define fnProjPreInstr_IceSbaEnd 0x90CF7A
#define fnSamus_MovementHandler_ShinesparkWindup 0x90D068
#define fnSamus_MovementHandler_VerticalShinespark 0x90D0AB
#define fnSamus_MovementHandler_DiagonalShinespark 0x90D0D7
#define fnSamus_MovementHandler_HorizontalShinespark 0x90D106
#define fnSamus_MovementHandler_ShinesparkCrash_EchoCircle 0x90D346
#define fnSamus_MovementHandler_ShinesparkCrash_EchoCircle_Phase0 0x90D383
#define fnSamus_MovementHandler_ShinesparkCrash_EchoCircle_Phase1 0x90D396
#define fnSamus_MovementHandler_ShinesparkCrash_EchoCircle_Phase2 0x90D3CC
#define fnSamus_MovementHandler_ShinesparkCrash_EchoCircle_Finish 0x90D3F3
#define fnSamus_MovementHandler_ShinesparkCrash_Finish 0x90D40D
#define fnProjPreInstr_SpeedEcho 0x90D4D2
#define fnSamus_MovementHandler_CrystalFlashStart 0x90D678
#define fnSamus_MovementHandler_CrystalFlashMain 0x90D6CE
#define fnSamus_MovementHandler_CrystalFlashFinish 0x90D75B
#define fnProjPreInstr_PlasmaSba 0x90D793
#define fnProjPreInstr_PlasmaSba_Phase0Expand 0x90D7E1
#define fnProjPreInstr_PlasmaSba_Phase1Contract 0x90D7FA
#define fnProjPreInstr_PlasmaSba_Phase2Disperse 0x90D813
#define fnProjPreInstr_SpreadBomb 0x90D8F7
#define fnProjPreInstr_WaveSba 0x90DA08
#define fnProjPreInstr_SpazerSba 0x90DB06
#define fnProjPreInstr_SpazerSba_FuncA_0 0x90DB57
#define fnProjPreInstr_SpazerSba_FuncA_1 0x90DB66
#define fnProjPreInstr_SpazerSba_FuncA_2 0x90DB75
#define fnProjPreInstr_SpazerSba_FuncA_3 0x90DB84
#define fnProjPreInstr_SpazerSba_FuncB_0 0x90DB93
#define fnProjPreInstr_SpazerSba_FuncB_1 0x90DBCF
#define fnProjPreInstr_SpazerSba_FuncB_2 0x90DC30
#define fnProjPreInstr_EndOfSpazerSba 0x90DC9C
#define fnSamus_MovementHandler_Knockback 0x90DF38
#define fnSamus_MovementHandler_Invalid 0x90DF50
#define fnSamus_MovementHandler_Knockback_Up 0x90DF53
#define fnSamus_MovementHandler_Knockback_StraightUp_Unused 0x90DF5D
#define fnSamus_MovementHandler_Knockback_Down 0x90DF64
#define fnSamus_MovementHandler_BombJumpStart 0x90E025
#define fnSamus_MovementHandler_BombJumpMain 0x90E032
#define fnSamus_MovementHandler_EndBombJump 0x90E07D
#define fnSamus_FrameHandlerGamma_UnlockSamusFromDrained 0x90E09B
#define fnSamus_FrameHandlerGamma_KeepSamusLockedFromDrained 0x90E0C5
#define fnSamus_FrameHandlerGamma_HandleTimer 0x90E0E6
#define fnSamus_FrameHandlerGamma_DrawTimer 0x90E114
#define fnSamus_FrameHandlerGamma_PushOutOfRidleysWay 0x90E12E
#define fnSamus_FrameHandlerGamma_PushingOutOfRidleysWay 0x90E1C8
#define fnSamus_FrameHandlerGamma_GrabbedByDraygon 0x90E2A1
#define fnnullsub_151 0x90E37E
#define fnSamus_FrameHandlerGamma_PushMorphedSamusOutOfRidleysWay_Unused 0x90E3A3
#define fnSamus_FrameHandlerGamma_SpecialFalling_Unused 0x90E41B
#define fnSamus_FrameHandlerAlfa_Normal 0x90E695
#define fnSamus_FrameHandlerAlfa_Demo 0x90E6C9
#define fnSamus_FrameHandlerAlfa_SamusLocked 0x90E713
#define fnSamus_FrameHandlerBeta_Normal 0x90E725
#define fnSamus_FrameHandlerBeta_Debug 0x90E7D2
#define fnSamus_FrameHandlerBeta_TitleDemo 0x90E7F5
#define fnSamus_FrameHandlerBeta_IntroDemo 0x90E833
#define fnSamus_FrameHandlerBeta_SamusAppears 0x90E86A
#define fnSamus_FrameHandlerBeta_Ceres 0x90E8AA
#define fnSamus_FrameHandlerBeta_DoNothing 0x90E8CD
#define fnSamus_FrameHandlerBeta_SamusLockedToStation 0x90E8D6
#define fnSamus_FrameHandlerBeta_SamusBeingDrained 0x90E8D9
#define fnSamus_FrameHandlerBeta_SamusLocked 0x90E8DC
#define fnSamus_FrameHandlerBeta_RidingElevator 0x90E8EC
#define fnSamus_FrameHandlerBeta_EnterExitGunship 0x90E902
#define fnnullsub_152 0x90E90E
#define fnSamus_InputHandler_Normal 0x90E913
#define fnSamus_InputHandler_Xray 0x90E918
#define fnSamus_InputHandler_Demo 0x90E91D
#define fnSamus_InputHandler_AutoJump 0x90E926
#define fnSamus_MovementHandler_Xray 0x90E94F
#define fnSamus_DrawHandler_Default 0x90EB52
#define fnSamus_DrawHandler_NoChargeOrGrapple 0x90EB86
#define fnnullsub_156 0x90EBF2
#define fnSamus_DrawHandler_EndOfShinespark 0x90EBF3
#define fnSamus_DisplayHandler_UsingElevator 0x90EC14
#define fnSamus_DisplayHandler_InanimateSamus 0x90EC1D
#define fnProjPreInstr_UnknownProj8027 0x90EFD3
#define fnSamus_MovementHandler_F04B_Unused 0x90F04B
#define fnSamus_MovementHandler_F072_Unused 0x90F072
#define fnnullsub_7 0x90F52F
#define fnSamus_InputHandler 0x918000
#define fnDemoPreInstr_nullsub_162 0x9183BF
#define fnDemoInstr_Finish 0x918427
#define fnDemoInstr_SetPreInstr 0x918434
#define fnDemoInstr_ClearPreInstr 0x91843F
#define fnDemoInstr_Goto 0x918448
#define fnDemoInstr_DecTimerAndGoto 0x91844F
#define fnDemoInstr_SetTimer 0x918459
#define fnDemoInstr_GiveInputToPlayerAndDisableDemo 0x9185FC
#define fnDemoPreInstr_BabyMetroidDiscovery_RunLeft 0x91864F
#define fnDemoPreInstr_BabyMetroidDiscovery_StopAndLook 0x91866A
#define fnDemoInstr_DisableDemo 0x918682
#define fnDemoInstr_FaceSamusLeftAndDisableDemo 0x918739
#define fnDemoPreInstr_CheckLeaveDemo 0x918A9B
#define fnDemoPreInstr_CheckLeaveDemo_Shinespark 0x918AB0
#define fnXray_SetupStage1_FreezeTime_BackupBg2 0x91CAF9
#define fnXray_SetupStage2_ReadBg1_2ndScreen 0x91CB1C
#define fnXray_SetupStage3_ReadBg1_1stScreen 0x91CB57
#define fnXray_SetupStage4_SetupAndReadBg2_1stScreen 0x91CB8E
#define fnRevealedBlock_Func_Vertical 0x91CE79
#define fnRevealedBlock_Func_Horizontal 0x91CEBB
#define fnRevealedBlock_Func_Copy1x1BlockToXrayBg2 0x91CF36
#define fnRevealedBlock_Func_Copy1x1BlockToXrayBg2_Brinstar 0x91CF3E
#define fnRevealedBlock_Func_Copy2x1BlockToXrayBg2 0x91CF4E
#define fnRevealedBlock_Func_Copy1x2BlockToXrayBg2 0x91CF62
#define fnRevealedBlock_Func_Copy2x2BlockToXrayBg2 0x91CF6F
#define fnXray_SetupStage5_ReadBg2_2ndScreen 0x91D0D3
#define fnXray_SetupStage6_TransferBg_1stScreen 0x91D173
#define fnXray_SetupStage7_InitXrayBeam_TransferBg_2ndScreen 0x91D1A0
#define fnHdmaobjPreInstr_XraySetup 0x91D27F
#define fnXray_SetupStage8_SetBackdropColor 0x91D2BC
#define fnVariaSuitPickup 0x91D4E4
#define fnGravitySuitPickup 0x91D5BA
#define fnInitializeSuitPickupHdma 0x91D692
#define fnnullsub_17 0x91E732
#define fnnullsub_21 0x91ECD8
#define fnnullsub_22 0x91ECD9
#define fnnullsub_19 0x91EF39
#define fnnullsub_23 0x91EFDE
#define fnnullsub_24 0x91FC07
#define fnnullsub_25 0x91FCAE
#define fnSamus_Func20 0x91FCAF
#define fnProjInstr_Delete 0x93822F
#define fnProjInstr_Goto 0x938239
#define fnGrappleInstr_Goto 0x94B0F4
#define fnnullsub_6 0x9BB8D4
#define fnGrappleNext_SwingClockwise 0x9BB9D9
#define fnGrappleNext_SwingAntiClockwise 0x9BB9E2
#define fnGrappleNext_StandAimRight 0x9BB9EA
#define fnGrappleNext_StandAimDownRight 0x9BB9F3
#define fnGrappleNext_StandAimDownLeft 0x9BB9FC
#define fnGrappleNext_StandAimLeft 0x9BBA05
#define fnGrappleNext_CrouchAimRight 0x9BBA0E
#define fnGrappleNext_CrouchAimDownRight 0x9BBA17
#define fnGrappleNext_CrouchAimDownLeft 0x9BBA20
#define fnGrappleNext_CrouchAimLeft 0x9BBA29
#define fnGrappleBeamFunc_BB64 0x9BBB64
#define fnGrappleBeamFunc_BC1F 0x9BBC1F
#define fnGrappleBeamFunc_BCFF 0x9BBCFF
#define fnGrappleBeamFunc_BD44 0x9BBD44
#define fnGrappleBeamFunc_BD95 0x9BBD95
#define fnGrappleBeamFunc_BE98 0x9BBE98
#define fnGrappleBeamFunc_BEEB 0x9BBEEB
#define fnGrappleBeamFunc_BF1B 0x9BBF1B
#define fnGrappleBeamFunc_Inactive 0x9BC4F0
#define fnGrappleBeamFunc_FireGoToCancel 0x9BC51E
#define fnGrappleBeamFunc_Firing 0x9BC703
#define fnUNUSED_sub_9BC759 0x9BC759
#define fnGrappleBeamFunc_ConnectedLockedInPlace 0x9BC77E
#define fnGrappleBeamFunc_Connected_Swinging 0x9BC79D
#define fnGrappleBeamFunc_Wallgrab 0x9BC814
#define fnGrappleBeamFunc_C832 0x9BC832
#define fnGrappleBeamFunc_Cancel 0x9BC856
#define fnGrappleBeam_Func2 0x9BC8C5
#define fnGrappleBeamFunc_C9CE 0x9BC9CE
#define fnGrappleBeamFunc_ReleaseFromSwing 0x9BCB8B
#define fnEnemy_GrappleReact_NoInteract_A0 0xA08000
#define fnEnemy_GrappleReact_SamusLatchesOn_A0 0xA08005
#define fnEnemy_GrappleReact_KillEnemy_A0 0xA0800A
#define fnEnemy_GrappleReact_CancelBeam_A0 0xA0800F
#define fnEnemy_GrappleReact_SamusLatchesNoInvinc_A0 0xA08014
#define fnEnemy_GrappleReact_SamusLatchesParalyze_A0 0xA08019
#define fnEnemy_GrappleReact_HurtSamus_A0 0xA0801E
#define fnEnemy_NormalTouchAI_A0 0xA08023
#define fnEnemy_NormalShotAI_A0 0xA0802D
#define fnEnemy_NormalPowerBombAI_A0 0xA08037
#define fnEnemy_NormalFrozenAI 0xA08041
#define fnCreateADudShot 0xA08046
#define fnnullsub_169 0xA0804B
#define fnnullsub_170 0xA0804C
#define fnnullsub_171 0xA0807B
#define fnEnemyInstr_StopScript 0xA0807C
#define fnEnemyInstr_Call 0xA0808A
#define fnEnemyInstr_Goto 0xA080ED
#define fnEnemyInstr_DecTimerAndGoto 0xA08108
#define fnEnemyInstr_DecTimerAndGoto2 0xA08110
#define fnEnemyInstr_SetTimer 0xA08123
#define fnEnemyInstr_Sleep 0xA0812F
#define fnEnemyInstr_WaitNframes 0xA0813A
#define fnEnemyInstr_CopyToVram 0xA0814B
#define fnEnemyInstr_EnableOffScreenProcessing 0xA08173
#define fnEnemyInstr_DisableOffScreenProcessing 0xA0817D
#define fnnullsub_4 0xA09784
#define fnEnemy_GrappleReact_SamusLatchesOn_A2 0xA28005
#define fnEnemy_GrappleReact_KillEnemy_A2 0xA2800A
#define fnEnemy_GrappleReact_CancelBeam_A2 0xA2800F
#define fnEnemy_NormalTouchAI_A2 0xA28023
#define fnEnemy_NormalShotAI_A2 0xA2802D
#define fnEnemy_NormalPowerBombAI_A2 0xA28037
#define fnEnemy_NormalFrozenAI_A2 0xA28041
#define fnnullsub_170_A2 0xA2804C
#define fnnullsub_171_A2 0xA2807B
#define fnEnemyInstr_Goto_A2 0xA280ED
#define fnEnemyInstr_DecTimerAndGoto2_A2 0xA28110
#define fnEnemyInstr_SetTimer_A2 0xA28123
#define fnEnemyInstr_Sleep_A2 0xA2812F
#define fnEnemyInstr_EnableOffScreenProcessing_A2 0xA28173
#define fnEnemyInstr_DisableOffScreenProcessing_A2 0xA2817D
#define fnBouncingGoofball_Init 0xA2871C
#define fnBouncingGoofball_Main 0xA2879C
#define fnBouncingGoofball_Instr_88C5 0xA288C5
#define fnBouncingGoofball_Instr_88C6 0xA288C6
#define fnMiniCrocomire_Instr_897E 0xA2897E
#define fnMiniCrocomire_Instr_8990 0xA28990
#define fnMiniCrocomire_Instr_899D 0xA2899D
#define fnMiniCrocomire_Init 0xA289AD
#define fnMiniCrocomire_Main 0xA289F0
#define fnMiniCrocomire_PreInstr5 0xA28A43
#define fnMiniCrocomire_PreInstr6 0xA28A5C
#define fnnullsub_175 0xA28A75
#define fnMaridiaBeybladeTurtle_Init 0xA28D6C
#define fnMiniMaridiaBeybladeTurtle_Init 0xA28D9D
#define fnMaridiaBeybladeTurtle_Main 0xA28DD2
#define fnMaridiaBeybladeTurtle_Func1 0xA28DD8
#define fnnullsub_360 0xA28E09
#define fnMaridiaBeybladeTurtle_Func2 0xA28E0A
#define fnMaridiaBeybladeTurtle_Func3 0xA28EE0
#define fnMaridiaBeybladeTurtle_Func5 0xA28F3F
#define fnMaridiaBeybladeTurtle_Func7 0xA28F8D
#define fnMaridiaBeybladeTurtle_Func8 0xA28FEB
#define fnMaridiaBeybladeTurtle_Func9 0xA29083
#define fnMaridiaBeybladeTurtle_Func10 0xA290CC
#define fnMaridiaBeybladeTurtle_Func11 0xA290E1
#define fnMiniMaridiaBeybladeTurtle_Main 0xA2912E
#define fnMiniMaridiaBeybladeTurtle_Func1 0xA29142
#define fnMiniMaridiaBeybladeTurtle_Func2 0xA2916E
#define fnMiniMaridiaBeybladeTurtle_Func3 0xA29198
#define fnMiniMaridiaBeybladeTurtle_Func4 0xA291F8
#define fnMiniMaridiaBeybladeTurtle_Func6 0xA29239
#define fnMiniMaridiaBeybladeTurtle_Func7 0xA2925E
#define fnMaridiaBeybladeTurtle_Touch 0xA29281
#define fnMiniMaridiaBeybladeTurtle_Touch 0xA2929F
#define fnMiniMaridiaBeybladeTurtle_Shot 0xA2930F
#define fnMaridiaBeybladeTurtle_Instr_9381 0xA29381
#define fnMaridiaBeybladeTurtle_Instr_9412 0xA29412
#define fnMaridiaBeybladeTurtle_Instr_9447 0xA29447
#define fnMaridiaBeybladeTurtle_Instr_9451 0xA29451
#define fnMaridiaBeybladeTurtle_Instr_946B 0xA2946B
#define fnMaridiaBeybladeTurtle_Instr_9485 0xA29485
#define fnMaridiaBeybladeTurtle_Instr_94A1 0xA294A1
#define fnMaridiaBeybladeTurtle_Instr_94C7 0xA294C7
#define fnMaridiaBeybladeTurtle_Instr_94D1 0xA294D1
#define fnThinHoppingBlobs_Init 0xA29A3F
#define fnThinHoppingBlobs_Main 0xA29A7D
#define fnThinHoppingBlobs_Func1 0xA29A84
#define fnThinHoppingBlobs_Func6 0xA29B65
#define fnThinHoppingBlobs_Func7 0xA29B81
#define fnThinHoppingBlobs_Func11 0xA29D0B
#define fnThinHoppingBlobs_Func12 0xA29D2B
#define fnThinHoppingBlobs_Func13 0xA29D4B
#define fnThinHoppingBlobs_Func14 0xA29D6B
#define fnThinHoppingBlobs_Func15 0xA29D98
#define fnThinHoppingBlobs_Func16 0xA29DCD
#define fnSpikeShootingPlant_Instr_9F2A 0xA29F2A
#define fnSpikeShootingPlant_Init 0xA29F48
#define fnSpikeShootingPlant_Main 0xA29FB3
#define fnSpikeShootingPlant_2 0xA29FBA
#define fnSpikeShootingPlant_3 0xA29FEC
#define fnnullsub_182 0xA2A01B
#define fnSpikeShootingPlant_Instr_A095 0xA2A095
#define fnSpikeShootingPlant_Instr_A0A7 0xA2A0A7
#define fnMaridiaSpikeyShell_Init 0xA2A3F9
#define fnMaridiaSpikeyShell_Main 0xA2A47E
#define fnMaridiaSpikeyShell_Instr_A56D 0xA2A56D
#define fnMaridiaSpikeyShell_Instr_A571 0xA2A571
#define fnMaridiaSpikeyShell_Shot 0xA2A579
#define fnGunshipTop_Init 0xA2A644
#define fnGunshipBottom_Init 0xA2A6D2
#define fnGunshipTop_Main 0xA2A759
#define fnGunshipTop_1 0xA2A784
#define fnnullsub_187 0xA2A7D7
#define fnGunshipTop_2 0xA2A7D8
#define fnGunshipTop_3 0xA2A80C
#define fnGunshipTop_4 0xA2A8D0
#define fnGunshipTop_5 0xA2A942
#define fnGunshipTop_6 0xA2A950
#define fnGunshipTop_7 0xA2A987
#define fnGunshipTop_8 0xA2A9BD
#define fnGunshipTop_9 0xA2AA4F
#define fnGunshipTop_10 0xA2AA5D
#define fnGunshipTop_11 0xA2AA94
#define fnGunshipTop_12 0xA2AAA2
#define fnGunshipTop_13 0xA2AB1F
#define fnGunshipTop_14 0xA2AB60
#define fnGunshipTop_15 0xA2AB6E
#define fnGunshipTop_16 0xA2ABA5
#define fnGunshipTop_17 0xA2ABC7
#define fnGunshipTop_18 0xA2AC1B
#define fnGunshipTop_19 0xA2ACD7
#define fnGunshipTop_20 0xA2AD0E
#define fnGunshipTop_21 0xA2AD2D
#define fnFlies_Init 0xA2B06B
#define fnFlies_Main 0xA2B11F
#define fnFlies_4 0xA2B14E
#define fnFlies_5 0xA2B17C
#define fnFlies_6 0xA2B1AA
#define fnFlies_7 0xA2B1D2
#define fnNorfairErraticFireball_Init 0xA2B3E0
#define fnNorfairErraticFireball_Main 0xA2B40F
#define fnLavaquakeRocks_Init 0xA2B570
#define fnLavaquakeRocks_Main 0xA2B58F
#define fnLavaquakeRocks_1 0xA2B596
#define fnLavaquakeRocks_2 0xA2B5B2
#define fnLavaquakeRocks_3 0xA2B5EA
#define fnRinka_Init 0xA2B602
#define fnRinka_Main 0xA2B7C4
#define fnRinka_3 0xA2B7DF
#define fnRinka_4 0xA2B844
#define fnRinka_5 0xA2B852
#define fnRinka_B85B 0xA2B85B
#define fnRinka_Frozen 0xA2B929
#define fnRinka_Touch 0xA2B947
#define fnRinka_Shot 0xA2B94D
#define fnRinka_Powerbomb 0xA2B953
#define fnRinka_Instr_B9B3 0xA2B9B3
#define fnRinka_Instr_B9BD 0xA2B9BD
#define fnRinka_Instr_B9C7 0xA2B9C7
#define fnEnemyInstr_Rio_Instr_1 0xA2BBC3
#define fnRio_Init 0xA2BBCD
#define fnRio_Main 0xA2BBE3
#define fnRio_1 0xA2BBED
#define fnRio_2 0xA2BC32
#define fnRio_3 0xA2BC48
#define fnRio_4 0xA2BCB7
#define fnRio_5 0xA2BCFF
#define fnNorfairLavajumpingEnemy_Instr_BE8E 0xA2BE8E
#define fnNorfairLavajumpingEnemy_Init 0xA2BE99
#define fnNorfairLavajumpingEnemy_Main 0xA2BED2
#define fnNorfairLavajumpingEnemy_Func_1 0xA2BEDC
#define fnNorfairLavajumpingEnemy_Func_2 0xA2BF1A
#define fnNorfairLavajumpingEnemy_Func_3 0xA2BF3E
#define fnNorfairLavajumpingEnemy_Func_4 0xA2BF7C
#define fnNorfairLavajumpingEnemy_Func_5 0xA2BFBC
#define fnNorfairRio_Instr_C1C9 0xA2C1C9
#define fnNorfairRio_Instr_C1D4 0xA2C1D4
#define fnNorfairRio_Instr_C1DF 0xA2C1DF
#define fnNorfairRio_Instr_C1EA 0xA2C1EA
#define fnNorfairRio_Instr_C1F5 0xA2C1F5
#define fnNorfairRio_Instr_C200 0xA2C200
#define fnNorfairRio_Instr_C20B 0xA2C20B
#define fnNorfairRio_Instr_C216 0xA2C216
#define fnNorfairRio_Instr_C221 0xA2C221
#define fnNorfairRio_Instr_C22C 0xA2C22C
#define fnNorfairRio_Instr_C237 0xA2C237
#define fnNorfairRio_Init 0xA2C242
#define fnNorfairRio_Main 0xA2C277
#define fnNorfairRio_Func_1 0xA2C281
#define fnNorfairRio_Func_2 0xA2C2E7
#define fnNorfairRio_Func_3 0xA2C33F
#define fnNorfairRio_Func_4 0xA2C361
#define fnNorfairRio_Func_5 0xA2C3B1
#define fnNorfairRio_Func_6 0xA2C406
#define fnLowerNorfairRio_Instr_C6D2 0xA2C6D2
#define fnLowerNorfairRio_Instr_C6DD 0xA2C6DD
#define fnLowerNorfairRio_Instr_C6E8 0xA2C6E8
#define fnLowerNorfairRio_Init 0xA2C6F3
#define fnLowerNorfairRio_Main 0xA2C724
#define fnLowerNorfairRio_Func_1 0xA2C72E
#define fnLowerNorfairRio_Func_2 0xA2C771
#define fnLowerNorfairRio_Func_3 0xA2C7BB
#define fnLowerNorfairRio_Func_4 0xA2C7D6
#define fnLowerNorfairRio_Func_5 0xA2C82D
#define fnLowerNorfairRio_Func_6 0xA2C888
#define fnMaridiaLargeSnail_Instr_CB6B 0xA2CB6B
#define fnMaridiaLargeSnail_Instr_CCB3 0xA2CCB3
#define fnMaridiaLargeSnail_Instr_CCBE 0xA2CCBE
#define fnMaridiaLargeSnail_Instr_CCC9 0xA2CCC9
#define fnMaridiaLargeSnail_Init 0xA2CCD4
#define fnMaridiaLargeSnail_Main 0xA2CD13
#define fnMaridiaLargeSnail_Func_1 0xA2CD23
#define fnMaridiaLargeSnail_Func_4 0xA2CDE6
#define fnMaridiaLargeSnail_Func_5 0xA2CE2B
#define fnMaridiaLargeSnail_Func_6 0xA2CF40
#define fnMaridiaLargeSnail_Func_7 0xA2CF66
#define fnMaridiaLargeSnail_Func_8 0xA2CFA9
#define fnMaridiaLargeSnail_Func_12 0xA2D388
#define fnMaridiaLargeSnail_Touch 0xA2D38C
#define fnMaridiaLargeSnail_Shot 0xA2D3B4
#define fnHirisingSlowfalling_Init 0xA2DF76
#define fnHirisingSlowfalling_Main 0xA2E02E
#define fnHirisingSlowfalling_Func_4 0xA2E035
#define fnHirisingSlowfalling_Func_5 0xA2E04F
#define fnHirisingSlowfalling_Func_6 0xA2E06A
#define fnHirisingSlowfalling_Func_7 0xA2E0CD
#define fnGripper_Init 0xA2E1D3
#define fnGripper_Main 0xA2E221
#define fnJetPowerRipper_Init 0xA2E318
#define fnJetPowerRipper_Main 0xA2E353
#define fnJetPowerRipper_Shot 0xA2E3A9
#define fnRipper_Init 0xA2E49F
#define fnRipper_Main 0xA2E4DA
#define fnLavaSeahorse_Instr_E5FB 0xA2E5FB
#define fnLavaSeahorse_Init 0xA2E606
#define fnLavaSeahorse_Main 0xA2E64E
#define fnLavaSeahorse_Func_1 0xA2E654
#define fnLavaSeahorse_Func_2 0xA2E6AD
#define fnLavaSeahorse_Func_3 0xA2E6F1
#define fnLavaSeahorse_Func_4 0xA2E734
#define fnLavaSeahorse_Func_5 0xA2E749
#define fnnullsub_196 0xA2E781
#define fnLavaSeahorse_Touch 0xA2E7C8
#define fnLavaSeahorse_Shot 0xA2E7CE
#define fnLavaSeahorse_Powerbomb 0xA2E7D4
#define fnTimedShutter_Init 0xA2E9DA
#define fnTimedShutter_Main 0xA2EAB6
#define fnTimedShutter_Func_1 0xA2EABD
#define fnTimedShutter_Func_2 0xA2EAD1
#define fnTimedShutter_Func_3 0xA2EAE7
#define fnTimedShutter_Func_4 0xA2EAFD
#define fnTimedShutter_Func_5 0xA2EB11
#define fnTimedShutter_Func_10 0xA2EC13
#define fnRisingFallingPlatform_Init 0xA2EE05
#define fnShootableShutter_Init 0xA2EE12
#define fnRisingFallingPlatform_Func_1 0xA2EE1F
#define fnRisingFallingPlatform_Main 0xA2EED1
#define fnRisingFallingPlatform_Func_2 0xA2EF09
#define fnRisingFallingPlatform_Func_4 0xA2EF28
#define fnRisingFallingPlatform_Func_9 0xA2EF68
#define fnRisingFallingPlatform_Func_10 0xA2EFD4
#define fnRisingFallingPlatform_Func_11 0xA2F040
#define fnRisingFallingPlatform_Func_12 0xA2F072
#define fnRisingFallingPlatform_Func_13 0xA2F099
#define fnRisingFallingPlatform_Touch 0xA2F09D
#define fnRisingFallingPlatform_Shot 0xA2F0A2
#define fnShootableShutter_Shot 0xA2F0AA
#define fnRisingFallingPlatform_Powerbomb 0xA2F0B6
#define fnHorizontalShootableShutter_Init 0xA2F111
#define fnHorizontalShootableShutter_Func_1 0xA2F11E
#define fnHorizontalShootableShutter_Main 0xA2F1DE
#define fnHorizontalShootableShutter_Func_2 0xA2F224
#define fnHorizontalShootableShutter_Func_4 0xA2F243
#define fnHorizontalShootableShutter_Func_8 0xA2F272
#define fnHorizontalShootableShutter_Func_9 0xA2F2E4
#define fnHorizontalShootableShutter_Func_12 0xA2F38C
#define fnHorizontalShootableShutter_Func_13 0xA2F3B0
#define fnHorizontalShootableShutter_Func_14 0xA2F3D4
#define fnHorizontalShootableShutter_Touch 0xA2F3D8
#define fnHorizontalShootableShutter_Shot 0xA2F40E
#define fnHorizontalShootableShutter_Powerbomb 0xA2F41A
#define fnEnemy_GrappleReact_NoInteract_A3 0xA38000
#define fnEnemy_GrappleReact_KillEnemy_A3 0xA3800A
#define fnEnemy_GrappleReact_CancelBeam_A3 0xA3800F
#define fnEnemy_NormalTouchAI_A3 0xA38023
#define fnEnemy_NormalShotAI_A3 0xA3802D
#define fnEnemy_NormalPowerBombAI_A3 0xA38037
#define fnEnemy_NormalFrozenAI_A3 0xA38041
#define fnnullsub_170_A3 0xA3804C
#define fnEnemyInstr_Goto_A3 0xA380ED
#define fnEnemyInstr_Sleep_A3 0xA3812F
#define fnEnemyInstr_EnableOffScreenProcessing_A3 0xA38173
#define fnEnemyInstr_DisableOffScreenProcessing_A3 0xA3817D
#define fnWaver_Instr_1 0xA386E3
#define fnWaver_Init 0xA386ED
#define fnWaver_Main 0xA3874C
#define fnMetalee_Instr_1 0xA38956
#define fnMetalee_Init 0xA38960
#define fnMetalee_Main 0xA38979
#define fnMetalee_Func_1 0xA38987
#define fnMetalee_Func_3 0xA389D4
#define fnMetalee_Func_4 0xA389F3
#define fnMetalee_Func_5 0xA38A5C
#define fnMetalee_Shot 0xA38B0F
#define fnFireflea_Init 0xA38D2D
#define fnFireflea_Main 0xA38DEE
#define fnFireflea_Touch 0xA38E6B
#define fnFireflea_Powerbomb 0xA38E83
#define fnFireflea_Shot 0xA38E89
#define fnMaridiaFish_Instr_3 0xA39096
#define fnMaridiaFish_Instr_1 0xA390A0
#define fnMaridiaFish_Instr_2 0xA390AA
#define fnMaridiaFish_Init 0xA390B5
#define fnMaridiaFish_Main 0xA3912B
#define fnMaridiaFish_Func_1 0xA39132
#define fnMaridiaFish_Func_2 0xA391AB
#define fnMaridiaFish_Func_3 0xA39224
#define fnMaridiaFish_Func_4 0xA39256
#define fnElevator_Init 0xA394E6
#define fnElevator_Main 0xA3952A
#define fnCrab_Init 0xA396E3
#define fnSlug_Init 0xA3993B
#define fnPlatformThatFallsWithSamus_Instr_3 0xA39C6B
#define fnPlatformThatFallsWithSamus_Instr_4 0xA39C76
#define fnPlatformThatFallsWithSamus_Instr_1 0xA39C81
#define fnPlatformThatFallsWithSamus_Instr_2 0xA39C8C
#define fnPlatformThatFallsWithSamus_Init 0xA39C9F
#define fnFastMovingSlowSinkingPlatform_Init 0xA39CBA
#define fnPlatformThatFallsWithSamus_Main 0xA39D16
#define fnnullsub_32 0xA39F07
#define fnFastMovingSlowSinkingPlatform_Shot 0xA39F08
#define fnRoach_Func_1 0xA3A12F
#define fnRoach_Init 0xA3A14D
#define fnRoach_Func_2 0xA3A183
#define fnRoach_Main 0xA3A2D0
#define fnRoach_Func_9 0xA3A2D7
#define fnRoach_Func_10 0xA3A301
#define fnRoach_Func_11 0xA3A30B
#define fnRoach_Func_12 0xA3A315
#define fnRoach_Func_13 0xA3A325
#define fnRoach_Func_14 0xA3A33B
#define fnRoach_Func_15 0xA3A34B
#define fnRoach_Func_16 0xA3A380
#define fnRoach_Func_19 0xA3A407
#define fnRoach_Func_20 0xA3A40E
#define fnRoach_Func_21 0xA3A440
#define fnRoach_Func_22 0xA3A447
#define fnRoach_Func_23 0xA3A44E
#define fnRoach_Func_24 0xA3A462
#define fnRoach_Func_25 0xA3A476
#define fnRoach_Func_26 0xA3A4B6
#define fnRoach_Func_27 0xA3A4F0
#define fnMochtroid_Init 0xA3A77D
#define fnMochtroid_Main 0xA3A790
#define fnMochtroid_Touch 0xA3A953
#define fnMochtroid_Shot 0xA3A9A8
#define fnSidehopper_Func_1 0xA3AA68
#define fnSidehopper_Instr_1 0xA3AAFE
#define fnSidehopper_Init 0xA3AB09
#define fnSidehopper_Main 0xA3ABCF
#define fnSidehopper_Func_4 0xA3ABD6
#define fnSidehopper_Func_5 0xA3ABE6
#define fnSidehopper_Func_6 0xA3AC13
#define fnSidehopper_Func_7 0xA3AC40
#define fnSidehopper_Func_8 0xA3AC56
#define fnSidehopper_Func_9 0xA3AC6C
#define fnSidehopper_Func_10 0xA3AC8F
#define fnSidehopper_Func_11 0xA3ACA8
#define fnSidehopper_Func_12 0xA3ACCB
#define fnSidehopper_Func_13 0xA3ACE4
#define fnSidehopper_Func_14 0xA3AD0E
#define fnSidehopper_Func_15 0xA3AD20
#define fnSidehopper_Func_16 0xA3AD32
#define fnSidehopper_Func_17 0xA3AD44
#define fnSidehopper_Func_18 0xA3AD56
#define fnMaridiaRefillCandy_Instr_1 0xA3B429
#define fnMaridiaRefillCandy_Instr_2 0xA3B434
#define fnMaridiaRefillCandy_Instr_3 0xA3B43F
#define fnMaridiaRefillCandy_Init 0xA3B44A
#define fnMaridiaRefillCandy_Main 0xA3B47C
#define fnMaridiaRefillCandy_Func_1 0xA3B482
#define fnMaridiaRefillCandy_Func_2 0xA3B4A8
#define fnMaridiaRefillCandy_Func_3 0xA3B4D6
#define fnNorfairSlowFireball_Init 0xA3B66F
#define fnBang_Instr_1 0xA3BA78
#define fnBang_Instr_2 0xA3BAA8
#define fnBang_Init 0xA3BAB3
#define fnBang_Main 0xA3BB25
#define fnBang_Func_1 0xA3BB2B
#define fnBang_Func_6 0xA3BCA5
#define fnBang_Func_7 0xA3BCC1
#define fnBang_Func_8 0xA3BCC5
#define fnBang_Func_10 0xA3BD1C
#define fnBang_Func_11 0xA3BD2C
#define fnBang_Shot 0xA3BEFD
#define fnSkree_Instr_1 0xA3C6A4
#define fnSkree_Init 0xA3C6AE
#define fnSkree_Main 0xA3C6C7
#define fnSkree_Func_1 0xA3C6D5
#define fnSkree_Func_2 0xA3C6F7
#define fnSkree_Func_3 0xA3C716
#define fnSkree_Func_4 0xA3C77F
#define fnSkree_Shot 0xA3C7F5
#define fnMaridiaSnail_Instr_1 0xA3CC36
#define fnMaridiaSnail_Instr_2 0xA3CC3F
#define fnMaridiaSnail_Instr_4 0xA3CC48
#define fnMaridiaSnail_Instr_3 0xA3CC5F
#define fnMaridiaSnail_Instr_5 0xA3CC78
#define fnMaridiaSnail_Func_1 0xA3CC92
#define fnMaridiaSnail_Init 0xA3CDE2
#define fnMaridiaSnail_Main 0xA3CE64
#define fnnullsub_215 0xA3CF5F
#define fnMaridiaSnail_Func_7 0xA3CF60
#define fnMaridiaSnail_Func_9 0xA3CFA6
#define fnMaridiaSnail_CFB7 0xA3CFB7
#define fnMaridiaSnail_CFBD 0xA3CFBD
#define fnMaridiaSnail_CFCE 0xA3CFCE
#define fnMaridiaSnail_CFD4 0xA3CFD4
#define fnMaridiaSnail_CFE5 0xA3CFE5
#define fnMaridiaSnail_CFEB 0xA3CFEB
#define fnMaridiaSnail_CFFC 0xA3CFFC
#define fnMaridiaSnail_Func_15 0xA3D1B3
#define fnMaridiaSnail_Touch 0xA3D3B0
#define fnMaridiaSnail_Shot 0xA3D469
#define fnReflec_Func_1 0xA3DB0C
#define fnReflec_Instr_1 0xA3DBC8
#define fnReflec_Init 0xA3DBD3
#define fnnullsub_33 0xA3DC1B
#define fnReflec_Shot 0xA3DC1C
#define fnWreckedShipOrangeZoomer_Func_1 0xA3DFC2
#define fnWreckedShipOrangeZoomer_Init 0xA3E043
#define fnnullsub_343 0xA3E08A
#define fnWreckedShipOrangeZoomer_Func_2 0xA3E091
#define fnWreckedShipOrangeZoomer_Main 0xA3E08B
#define fnsub_A3E168 0xA3E168
#define fnBigEyeBugs_Init 0xA3E2D4
#define fnFireZoomer_Init 0xA3E59C
#define fnZoomer_Instr_SetPreinstr 0xA3E660
#define fnStoneZoomer_Init 0xA3E669
#define fnnullsub_304 0xA3E6C1
#define fnStoneZoomer_Main 0xA3E6C2
#define fnFireZoomer_Func_1 0xA3E6C8
#define fnFireZoomer_Func_2 0xA3E785
#define fnFireZoomer_Func_3 0xA3E7F2
#define fnMetroid_Init 0xA3EA4F
#define fnMetroid_Instr_2 0xA3EAA5
#define fnMetroid_Instr_1 0xA3EAB1
#define fnMetroid_Frozen 0xA3EAE6
#define fnMetroid_Hurt 0xA3EB33
#define fnMetroid_Main 0xA3EB98
#define fnMetroid_Touch 0xA3EDEB
#define fnMetroid_Shot 0xA3EF07
#define fnMetroid_Powerbomb 0xA3F042
#define fnEnemy_GrappleReact_SamusLatchesOn_A4 0xA48005
#define fnEnemy_NormalTouchAI_A4 0xA48023
#define fnEnemy_NormalShotAI_A4 0xA4802D
#define fnEnemy_NormalPowerBombAI_A4 0xA48037
#define fnEnemy_NormalFrozenAI_A4 0xA48041
#define fnnullsub_170_A4 0xA4804C
#define fnEnemyInstr_Goto_A4 0xA480ED
#define fnEnemyInstr_Sleep_A4 0xA4812F
#define fnCrocomire_Hurt 0xA48687
#define fnCrocomire_Instr_1 0xA486A6
#define fnCrocomire_Instr_14 0xA48752
#define fnCrocomire_Func_9 0xA487CA
#define fnCrocomire_Init 0xA48A5A
#define fnCrocomire_Main 0xA48C04
#define fnCrocomire_Instr_11 0xA48CFB
#define fnCrocomire_Instr_7 0xA48D07
#define fnCrocomire_Instr_19 0xA48D13
#define fnCrocomire_Instr_2 0xA48FC7
#define fnCrocomire_Instr_4 0xA48FDF
#define fnCrocomire_Instr_3 0xA48FFA
#define fnCrocomire_Instr_15 0xA48FFF
#define fnCrocomire_Instr_16 0xA4901D
#define fnCrocomire_Instr_13 0xA4905B
#define fnCrocomire_Instr_18 0xA4907F
#define fnCrocomire_Instr_12 0xA4908F
#define fnCrocomire_Instr_17 0xA49094
#define fnnullsub_309 0xA4943C
#define fnCrocomire_Instr_8 0xA49A9B
#define fnCrocomire_Instr_6 0xA49AA0
#define fnCrocomire_Instr_9 0xA49AA5
#define fnCrocomire_Instr_5 0xA49AAA
#define fnCrocomire_Instr_20 0xA49AAF
#define fnCrocomire_Instr_21 0xA49AB4
#define fnCrocomire_Instr_22 0xA49AB9
#define fnCrocomire_Instr_23 0xA49ABE
#define fnCrocomire_Instr_24 0xA49AC3
#define fnCrocomire_Instr_10 0xA49AC8
#define fnCrocomire_Instr_25 0xA49ACD
#define fnCrocomire_Instr_26 0xA49AD2
#define fnCrocomire_Instr_27 0xA49AD7
#define fnCrocomire_Func_92 0xA4B93D
#define fnnullsub_34 0xA4B950
#define fnCrocomire_Func_93 0xA4B951
#define fnCrocomire_Func_94 0xA4B968
#define fnCrocomire_Powerbomb 0xA4B992
#define fnCrocomire_Func_95 0xA4BA05
#define fnCrocomire_Func_1 0xA4BAB4
#define fnCrocomireTongue_Init 0xA4F67A
#define fnCrocomireTongue_Main 0xA4F6BB
#define fnEnemy_GrappleReact_NoInteract_A5 0xA58000
#define fnEnemy_GrappleReact_CancelBeam_A5 0xA5800F
#define fnEnemy_NormalTouchAI_A5 0xA58023
#define fnEnemy_NormalShotAI_A5 0xA5802D
#define fnEnemy_NormalPowerBombAI_A5 0xA58037
#define fnEnemy_NormalFrozenAI_A5 0xA58041
#define fnCreateADudShot_A5 0xA58046
#define fnnullsub_169_A5 0xA5804B
#define fnnullsub_170_A5 0xA5804C
#define fnEnemyInstr_StopScript_A5 0xA5807C
#define fnEnemyInstr_Goto_A5 0xA580ED
#define fnEnemyInstr_DecTimerAndGoto2_A5 0xA58110
#define fnEnemyInstr_SetTimer_A5 0xA58123
#define fnEnemyInstr_Sleep_A5 0xA5812F
#define fnEnemyInstr_WaitNframes_A5 0xA5813A
#define fnDraygon_Init 0xA58687
#define fnDraygon_Main 0xA586FC
#define fnDraygon_Func_1 0xA5871B
#define fnDraygon_Func_2 0xA5878B
#define fnDraygon_Func_3 0xA587AA
#define fnDraygon_Func_4 0xA587F4
#define fnDraygon_Func_6 0xA588B1
#define fnDraygon_Func_8 0xA58922
#define fnDraygon_Func_9 0xA58951
#define fnDraygon_Func_10 0xA589B3
#define fnDraygon_Func_11 0xA58A00
#define fnDraygon_Func_12 0xA58A50
#define fnDraygon_Func_13 0xA58A90
#define fnDraygon_Func_14 0xA58B0A
#define fnDraygon_Func_15 0xA58B52
#define fnDraygon_Func_16 0xA58BAE
#define fnDraygon_Func_17 0xA58C33
#define fnDraygon_Func_18 0xA58C8E
#define fnDraygon_Func_19 0xA58CD4
#define fnDraygon_Func_20 0xA58D30
#define fnDraygon_Func_21 0xA58DB2
#define fnDraygon_Func_22 0xA58E19
#define fnDraygon_Func_23 0xA58F10
#define fnDraygon_Func_24 0xA58F1E
#define fnDraygon_Func_25 0xA58FD6
#define fnDraygon_Func_26 0xA590D4
#define fnDraygon_Func_27 0xA59105
#define fnDraygon_Func_28 0xA59124
#define fnDraygon_Func_29 0xA59128
#define fnDraygon_Func_30 0xA59154
#define fnDraygon_Func_31 0xA59185
#define fnDraygon_Func_32 0xA59294
#define fnDraygon_Func_33 0xA592AB
#define fnDraygon_Func_36 0xA59342
#define fnDraygon_Instr_1 0xA594DD
#define fnDraygon_Hurt 0xA5954D
#define fnDraygon_Touch 0xA595EA
#define fnDraygon_Shot 0xA595F0
#define fnDraygon_Powerbomb 0xA59607
#define fnDraygon_Instr_13 0xA59736
#define fnDraygon_Instr_8 0xA5973F
#define fnDraygon_Instr_7 0xA59752
#define fnDraygon_Instr_6 0xA59765
#define fnDraygon_Instr_9 0xA59778
#define fnDraygon_Instr_2 0xA59895
#define fnDraygon_Instr_11 0xA598D3
#define fnDraygon_Instr_5 0xA598EF
#define fnDraygon_Instr_15 0xA59B9A
#define fnDraygon_Instr_17 0xA59C8A
#define fnDraygon_Instr_14 0xA59E0A
#define fnDraygon_Instr_16 0xA59F57
#define fnDraygon_Instr_10 0xA59F60
#define fnDraygon_Instr_4 0xA59F6E
#define fnDraygon_Instr_12 0xA59F7C
#define fnDraygon_Instr_18 0xA59FAE
#define fnDraygonsEye_Init 0xA5C46B
#define fnDraygon_Instr_3 0xA5C47B
#define fnDraygonsEye_Main 0xA5C486
#define fnDraygon_Func_48 0xA5C48D
#define fnDraygon_Func_49 0xA5C513
#define fnDraygonsTail_Init 0xA5C599
#define fnnullsub_37 0xA5C5AA
#define fnDraygonsArms_Init 0xA5C5AD
#define fnnullsub_38 0xA5C5C4
#define fnSporeSpawn_Instr_IncreaseMaxXRadius 0xA5E75F
#define fnSporeSpawn_Instr_ClearDamagedFlag 0xA5E771
#define fnSporeSpawn_Instr_SetMaxXRadius_AngleDelta 0xA5E82D
#define fnSporeSpawn_Instr_SetGenerationFlag 0xA5E872
#define fnSporeSpawn_Instr_Harden 0xA5E87C
#define fnSporeSpawn_Instr_QueueSfx2_Max6 0xA5E895
#define fnSporeSpawn_Instr_SpawnItemDrops 0xA5E8B1
#define fnSporeSpawn_Instr_SetFunction 0xA5E8BA
#define fnSporeSpawn_Instr_LoadDeathSequencePaletteWithOffset 0xA5E8CA
#define fnSporeSpawn_Instr_LoadDeathSequenceTargetPaletteWithOffset 0xA5E91C
#define fnSporeSpawn_Instr_SpawnHardeningDustCloud 0xA5E96E
#define fnSporeSpawn_Instr_SpawnDyingExplosion 0xA5E9B1
#define fnSporeSpawn_Init 0xA5EA2A
#define fnSporeSpawn_Main 0xA5EB13
#define fnSporeSpawn_nullsub_223 0xA5EB1A
#define fnSporeSpawn_Func_Descent 0xA5EB1B
#define fnSporeSpawn_Func_Moving 0xA5EB52
#define fnSporeSpawn_Func_SetUpDeath 0xA5EB9B
#define fnSporeSpawn_Func_Dying 0xA5EBEE
#define fnSporeSpawn_Shot 0xA5ED5A
#define fnSporeSpawn_Touch 0xA5EDEC
#define fnnullsub_39 0xA5EDF2
#define fnEnemy_GrappleReact_NoInteract_A6 0xA68000
#define fnEnemy_GrappleReact_CancelBeam_A6 0xA6800F
#define fnEnemy_NormalTouchAI_A6 0xA68023
#define fnEnemy_NormalShotAI_A6 0xA6802D
#define fnEnemy_NormalPowerBombAI_A6 0xA68037
#define fnEnemy_NormalFrozenAI_A6 0xA68041
#define fnnullsub_170_A6 0xA6804C
#define fnEnemyInstr_Goto_A6 0xA680ED
#define fnEnemyInstr_Sleep_A6 0xA6812F
#define fnBoulder_Init 0xA686F5
#define fnBoulder_Main 0xA68793
#define fnBoulder_Func_1 0xA6879A
#define fnBoulder_Func_2 0xA687ED
#define fnBoulder_Func_3 0xA68832
#define fnBoulder_Func_4 0xA6888B
#define fnBoulder_Func_5 0xA68942
#define fnBoulder_Func_6 0xA689FC
#define fnSpikeyPlatform_Init 0xA68B2F
#define fnSpikeyPlatform2ndEnemy_Init 0xA68B85
#define fnSpikeyPlatform2ndEnemy_Main 0xA68B99
#define fnSpikeyPlatform_Main 0xA68BAD
#define fnSpikeyPlatform_Func_1 0xA68BB4
#define fnSpikeyPlatform_Func_2 0xA68BDC
#define fnSpikeyPlatform_Func_3 0xA68C4A
#define fnSpikeyPlatform_Func_4 0xA68C5D
#define fnFireGeyser_Instr_1 0xA68DAF
#define fnFireGeyser_Instr_2 0xA68E13
#define fnFireGeyser_Instr_3 0xA68E2D
#define fnFireGeyser_Instr_4 0xA68E41
#define fnFireGeyser_Instr_5 0xA68E55
#define fnFireGeyser_Instr_6 0xA68E69
#define fnFireGeyser_Instr_7 0xA68E7D
#define fnFireGeyser_Instr_8 0xA68E91
#define fnFireGeyser_Instr_9 0xA68EA5
#define fnFireGeyser_Instr_10 0xA68EB9
#define fnFireGeyser_Instr_11 0xA68ECD
#define fnFireGeyser_Instr_12 0xA68EE1
#define fnFireGeyser_Instr_13 0xA68EF5
#define fnFireGeyser_Instr_14 0xA68F09
#define fnFireGeyser_Instr_15 0xA68F1D
#define fnFireGeyser_Instr_16 0xA68F31
#define fnFireGeyser_Instr_17 0xA68F45
#define fnFireGeyser_Instr_18 0xA68F59
#define fnFireGeyser_Instr_19 0xA68F6D
#define fnFireGeyser_Instr_20 0xA68F81
#define fnFireGeyser_Instr_21 0xA68F95
#define fnFireGeyser_Instr_22 0xA68FA9
#define fnFireGeyser_Instr_23 0xA68FBD
#define fnFireGeyser_Instr_24 0xA68FD1
#define fnFireGeyser_Init 0xA68FFC
#define fnFireGeyser_Main 0xA69023
#define fnFireGeyser_Func_1 0xA6902F
#define fnFireGeyser_Func_2 0xA69062
#define fnNuclearWaffle_Init 0xA694C4
#define fnNuclearWaffle_Main 0xA6960E
#define fnNuclearWaffle_Func_1 0xA69615
#define fnNuclearWaffle_Func_2 0xA69682
#define fnFakeKraid_Init 0xA69A58
#define fnFakeKraid_Main 0xA69AC2
#define fnFakeKraid_Instr_2 0xA69B26
#define fnFakeKraid_Instr_1 0xA69B74
#define fnFakeKraid_Instr_3 0xA69BB2
#define fnFakeKraid_Instr_4 0xA69BC4
#define fnFakeKraid_Instr_5 0xA69C02
#define fnFakeKraid_Touch 0xA69C22
#define fnFakeKraid_Shot 0xA69C39
#define fnCeresRidley_Init 0xA6A0F5
#define fnCeresRidley_Main 0xA6A288
#define fnCeresRidley_Func_1 0xA6A2BD
#define fnCeresRidley_Hurt 0xA6A2D3
#define fnRidley_A2F2 0xA6A2F2
#define fnCeresRidley_Func_2 0xA6A354
#define fnCeresRidley_Func_3 0xA6A35B
#define fnCeresRidley_A377 0xA6A377
#define fnCeresRidley_Func_4 0xA6A389
#define fnCeresRidley_Func_5 0xA6A3DF
#define fnCeresRidley_Func_6 0xA6A455
#define fnCeresRidley_Func_7 0xA6A478
#define fnCeresRidley_Func_9 0xA6A6AF
#define fnCeresRidley_Func_10 0xA6A6C8
#define fnCeresRidley_Func_11 0xA6A6E8
#define fnCeresRidley_Func_13 0xA6A782
#define fnCeresRidley_A7F9 0xA6A7F9
#define fnCeresRidley_Func_14 0xA6A83C
#define fnCeresRidley_Func_15 0xA6A84E
#define fnCeresRidley_Func_16 0xA6A88D
#define fnCeresRidley_Func_17 0xA6A8A4
#define fnCeresRidley_Func_18 0xA6A8D4
#define fnCeresRidley_Func_19 0xA6A8F8
#define fnCeresRidley_Func_20 0xA6A923
#define fnCeresRidley_Func_21 0xA6A947
#define fnCeresRidley_Func_22 0xA6A971
#define fnCeresRidley_Func_23 0xA6A9A0
#define fnCeresRidley_Func_24 0xA6AA11
#define fnnullsub_233 0xA6AA4F
#define fnCeresRidley_Func_26 0xA6AA50
#define fnRidley_Main 0xA6B227
#define fnRidley_Func_1 0xA6B26F
#define fnRidley_Func_2 0xA6B28A
#define fnRidley_Hurt 0xA6B297
#define fnRidley_Func_3 0xA6B2F3
#define fnRidley_Func_3b 0xA6B321
#define fnRidley_Func_4 0xA6B335
#define fnRidley_Func_5 0xA6B3EC
#define fnRidley_Func_6 0xA6B3F8
#define fnRidley_Func_8 0xA6B441
#define fnRidley_B455 0xA6B455
#define fnRidley_Func_9 0xA6B493
#define fnRidley_Func_10 0xA6B4D1
#define fnRidley_Func_11 0xA6B516
#define fnRidley_Func_12 0xA6B554
#define fnRidley_Func_13 0xA6B594
#define fnRidley_Func_14 0xA6B5C4
#define fnRidley_Func_15 0xA6B5E5
#define fnRidley_Func_16 0xA6B613
#define fnRidley_Func_19 0xA6B6A7
#define fnRidley_Func_20 0xA6B6DD
#define fnRidley_Func_21 0xA6B70E
#define fnRidley_Func_22 0xA6B7B9
#define fnRidley_Func_33 0xA6BAB7
#define fnRidley_Func_33b 0xA6BB8F
#define fnRidley_Func_34 0xA6BBC4
#define fnRidley_Func_35 0xA6BBF1
#define fnRidley_Func_36 0xA6BC2E
#define fnRidley_Func_43 0xA6BD4E
#define fnRidley_Func_44 0xA6BD9A
#define fnRidley_Func_45 0xA6BDBC
#define fnRidley_Func_46 0xA6BDF2
#define fnRidley_Func_47 0xA6BE03
#define fnRidley_Func_50 0xA6BE9C
#define fnRidley_Func_51 0xA6BEB3
#define fnRidley_Func_52 0xA6BECA
#define fnRidley_Func_53 0xA6BEDC
#define fnnullsub_348 0xA6BF19
#define fnBabyMetroid_Instr_2 0xA6BFC9
#define fnBabyMetroid_Instr_3 0xA6BFE1
#define fnBabyMetroid_Instr_1 0xA6BFF2
#define fnBabyMetroid_Instr_4 0xA6BFF8
#define fnRidley_Func_54 0xA6C04E
#define fnRidley_Func_63 0xA6C538
#define fnRidley_C53E 0xA6C53E
#define fnRidley_C551 0xA6C551
#define fnRidley_Func_64 0xA6C588
#define fnRidley_Func_65 0xA6C5A8
#define fnRidley_Func_66 0xA6C5C8
#define fnRidley_Func_67 0xA6C5DA
#define fnnullsub_349 0xA6C600
#define fnRidleysExplosion_Init 0xA6C696
#define fnRidleysExplosion_Main 0xA6C8D4
#define fnRidley_Func_79 0xA6CC39
#define fnRidley_Func_81 0xA6CCBD
#define fnRidley_Func_83 0xA6CD24
#define fnRidley_Func_84 0xA6CDAA
#define fnsub_A6DF59 0xA6DF59
#define fnRidley_Shot 0xA6DF8A
#define fnRidley_Powerbomb 0xA6DFB2
#define fnRidley_Instr_5 0xA6E4BE
#define fnRidley_Instr_6 0xA6E4CA
#define fnRidley_Instr_10 0xA6E4D2
#define fnRidley_Instr_4 0xA6E4EE
#define fnRidley_Instr_3 0xA6E4F8
#define fnRidley_Instr_2 0xA6E501
#define fnRidley_Instr_1 0xA6E517
#define fnRidley_Instr_14 0xA6E51F
#define fnRidley_Instr_9 0xA6E71C
#define fnRidley_Instr_7 0xA6E727
#define fnRidley_Instr_8 0xA6E72F
#define fnRidley_Instr_11 0xA6E84D
#define fnRidley_Instr_12 0xA6E904
#define fnRidley_Instr_13 0xA6E909
#define fnRidley_Instr_15 0xA6E969
#define fnRidley_Instr_16 0xA6E976
#define fnCeresSteam_Init 0xA6EFB1
#define fnnullsub_350 0xA6EFF4
#define fnCeresSteam_Main 0xA6F00D
#define fnCeresSteam_Func_1 0xA6F019
#define fnCeresSteam_Touch 0xA6F03F
#define fnCeresSteam_Instr_1 0xA6F11D
#define fnCeresSteam_Instr_2 0xA6F127
#define fnCeresSteam_Instr_3 0xA6F135
#define fnCeresDoor_Instr_6 0xA6F63E
#define fnCeresDoor_Instr_4 0xA6F66A
#define fnCeresDoor_Instr_8 0xA6F678
#define fnCeresSteam_Instr_4 0xA6F68B
#define fnCeresDoor_Instr_1 0xA6F695
#define fnCeresDoor_Instr_3 0xA6F69F
#define fnCeresSteam_Instr_5 0xA6F6A6
#define fnCeresDoor_Instr_5 0xA6F6B0
#define fnCeresDoor_Instr_2 0xA6F6B3
#define fnCeresDoor_Instr_7 0xA6F6BD
#define fnCeresDoor_Init 0xA6F6C5
#define fnCeresDoor_Main 0xA6F765
#define fnCeresDoor_Func_2 0xA6F76B
#define fnCeresDoor_Func_3 0xA6F770
#define fnCeresDoor_Func_4 0xA6F7A5
#define fnCeresDoor_Func_5 0xA6F7BD
#define fnCeresDoor_Func_6 0xA6F7DC
#define fnCeresDoor_Func_7 0xA6F850
#define fnnullsub_41 0xA6F920
#define fnZebetites_Init 0xA6FB72
#define fnZebetites_Main 0xA6FC33
#define fnZebetites_Func_1 0xA6FC41
#define fnZebetites_Func_2 0xA6FC5B
#define fnZebetites_Func_3 0xA6FC67
#define fnZebetites_Touch 0xA6FDA7
#define fnZebetites_Shot 0xA6FDAC
#define fnEnemy_GrappleReact_NoInteract_A7 0xA78000
#define fnEnemy_GrappleReact_CancelBeam_A7 0xA7800F
#define fnEnemy_NormalShotAI_A7 0xA7802D
#define fnEnemy_NormalPowerBombAI_A7 0xA78037
#define fnEnemy_NormalPowerBombAI_SkipDeathAnim_A7 0xA7803C
#define fnEnemy_NormalFrozenAI_A7 0xA78041
#define fnnullsub_170_A7 0xA7804C
#define fnEnemyInstr_Call_A7 0xA7808A
#define fnEnemyInstr_Goto_A7 0xA780ED
#define fnEnemyInstr_DecTimerAndGoto2_A7 0xA78110
#define fnEnemyInstr_SetTimer_A7 0xA78123
#define fnEnemyInstr_Sleep_A7 0xA7812F
#define fnKraid_Instr_9 0xA78A8F
#define fnKraid_Touch_ArmFoot 0xA7948B
#define fnnullsub_44 0xA7948F
#define fnKraidsArm_Touch 0xA79490
#define fnKraid_Touch 0xA7949F
#define fnKraid_Shot 0xA794B1
#define fnnullsub_43 0xA794B5
#define fnKraid_Arm_Shot 0xA794B6
#define fnKraid_Init 0xA7A959
#define fnKraidsArm_Init 0xA7AB43
#define fnKraidsTopLint_Init 0xA7AB68
#define fnKraidsMiddleLint_Init 0xA7AB9C
#define fnKraidsBottomLint_Init 0xA7ABCA
#define fnKraidsFoot_Init 0xA7ABF8
#define fnKraid_Main 0xA7AC21
#define fnKraid_GetsBig_BreakCeilingPlatforms 0xA7AC4D
#define fnKraid_GetsBig_SetBG2TilemapPrioBits 0xA7AD3A
#define fnKraid_GetsBig_FinishUpdateBg2Tilemap 0xA7AD61
#define fnKraid_GetsBig_DrawRoomBg 0xA7AD8E
#define fnKraid_GetsBig_FadeInRoomBg 0xA7AE23
#define fnKraid_Mainloop_Thinking 0xA7AEA4
#define fnKraid_GetsBig_Thinking 0xA7AEC4
#define fnKraid_Shot_MouthIsOpen 0xA7AEE4
#define fnKraidInstr_PlayRoarSfx 0xA7AF94
#define fnKraidInstr_PlayDyingSfx 0xA7AF9F
#define fnKraid_Shot_Mouth 0xA7AFAA
#define fnKraid_Instr_1 0xA7B633
#define fnKraid_Instr_DecYpos 0xA7B636
#define fnKraid_Instr_IncrYpos_Shake 0xA7B63C
#define fnKraid_Instr_PlaySound_0x76 0xA7B64E
#define fnKraid_Instr_XposMinus3 0xA7B65A
#define fnKraid_Instr_XposMinus3b 0xA7B667
#define fnKraid_Instr_XposPlus3 0xA7B674
#define fnKraid_Instr_MoveHimRight 0xA7B683
#define fnKraid_InitEyeGlowing 0xA7B6BF
#define fnKraid_Shot_GlowHisEye 0xA7B6D7
#define fnKraid_Shot_UnglowEye 0xA7B73D
#define fnKraidsArm_Main 0xA7B7BD
#define fnKraidsTopLint_Main 0xA7B801
#define fnKraidsMiddleLint_Main 0xA7B80D
#define fnKraidsBottomLint_Main 0xA7B819
#define fnnullsub_347 0xA7B831
#define fnKraidLint_ProduceLint 0xA7B832
#define fnKraidLint_ChargeLint 0xA7B868
#define fnKraidLint_FireLint 0xA7B89B
#define fnKraidFingernail_WaitForLintXpos 0xA7B907
#define fnKraid_AlignEnemyToKraid 0xA7B923
#define fnKraidEnemy_HandleFunctionTimer 0xA7B92D
#define fnKraidEnemy_DecrementEnemyFunctionTimer 0xA7B93F
#define fnKraidFoot_FirstPhase_Thinking 0xA7B960
#define fnKraidEnemy_ProcessInstrEnemyTimer 0xA7B965
#define fnKraidsFoot_Main 0xA7B9F6
#define fnnullsub_234 0xA7BA2D
#define fnKraidsFoot_SecondPhase_Thinking 0xA7BA2E
#define fnKraidsFoot_SecondPhase_WalkingBackwards 0xA7BB45
#define fnKraidsFoot_SecondPhaseSetup_WalkToStartPt 0xA7BB6E
#define fnKraidsFoot_SecondPhase_Init 0xA7BBA4
#define fnKraidsFoot_SecondPhase_WalkForward 0xA7BBAE
#define fnKraid_Main_AttackWithMouthOpen 0xA7BBEA
#define fnKraidsGoodFingernail_Touch 0xA7BCCF
#define fnKraidsBadFingernail_Touch 0xA7BCDE
#define fnKraidsGoodFingernail_Init 0xA7BCEF
#define fnKraidsBadFingernail_Init 0xA7BD2D
#define fnKraidsGoodFingernail_Main 0xA7BD32
#define fnKraidsBadFingernail_Main 0xA7BD49
#define fnKraidsFingernail_Init 0xA7BD60
#define fnKraidsFingernail_Fire 0xA7BE8E
#define fnKraidsFoot_PrepareToLungeForward 0xA7BF2D
#define fnKraidsFoot_FirstPhase_LungeForward 0xA7BF5D
#define fnKraidsFoot_FirstPhase_RetreatFromLunge 0xA7BFAB
#define fnKraid_GetsBig_ReleaseCamera 0xA7C0A1
#define fnUnpauseHook_Kraid_IsDead 0xA7C1FB
#define fnUnpauseHook_Kraid_IsAlive 0xA7C24E
#define fnKraid_UnpauseHook_IsSinking 0xA7C2A0
#define fnPauseHook_Kraid 0xA7C325
#define fnKraid_Death_Init 0xA7C360
#define fnKraid_Death_Fadeout 0xA7C3F9
#define fnKraid_Death_UpdateBG2TilemapTopHalf 0xA7C4A4
#define fnKraid_Death_UpdateBG2TilemapBottomHalf 0xA7C4C8
#define fnKraid_Death_SinkThroughFloor 0xA7C537
#define fnKraid_CrumbleLeftPlatform_Left 0xA7C691
#define fnnullsub_356 0xA7C6A6
#define fnKraid_CrumbleRightPlatform_Middle 0xA7C6A7
#define fnKraid_CrumbleRightPlatform_Left 0xA7C6BD
#define fnKraid_CrumbleLeftPlatform_Right 0xA7C6D3
#define fnKraid_CrumbleLeftPlatform_Middle 0xA7C6E9
#define fnKraid_CrumbleRightPlatform_Right 0xA7C6FF
#define fnKraid_FadeInBg_ClearBg2TilemapTopHalf 0xA7C715
#define fnKraid_FadeInBg_ClearBg2TilemapBottomHalf 0xA7C751
#define fnKraid_FadeInBg_LoadBg3Tiles1of4 0xA7C777
#define fnKraid_FadeInBg_LoadBg3Tiles2of4 0xA7C7A3
#define fnKraid_FadeInBg_LoadBg3Tiles3of4 0xA7C7C9
#define fnKraid_FadeInBg_LoadBg3Tiles4of4 0xA7C7EF
#define fnKraid_FadeInBg_FadeInBp6 0xA7C815
#define fnKraid_FadeInBg_SetEnemyDead_KraidWasAlive 0xA7C843
#define fnKraid_FadeInBg_SetEnemyDead_KraidWasDead 0xA7C851
#define fnKraid_RestrictSamusXtoFirstScreen 0xA7C865
#define fnKraid_RaiseKraidThroughFloor 0xA7C86B
#define fnKraid_Raise_LoadTilemapBottomAndShake 0xA7C89A
#define fnKraid_Raise_SpawnRandomEarthquakeProjs16 0xA7C8E0
#define fnKraid_Raise_SpawnRandomEarthquakeProjs8 0xA7C902
#define fnKraid_Raise_Handler 0xA7C924
#define fnPhantoon_Init 0xA7CDF3
#define fnPhantoon2_Init 0xA7CE55
#define fnPhantoon_Main 0xA7CEA6
#define fnPhantoon_Func_1 0xA7CEED
#define fnPhantoon_Func_4 0xA7CF5E
#define fnPhantoon_StartTrackingSamusAndInitEyeTimer 0xA7D03F
#define fnPhantoon_PickPatternForRound2 0xA7D076
#define fnPhantoon_FadeOut 0xA7D464
#define fnPhantoon_FadeIn 0xA7D486
#define fnnullsub_237 0xA7D4A8
#define fnPhantoon_Spawn8FireballsInCircleAtStart 0xA7D4A9
#define fnPhantoon_WaitBetweenSpawningAndSpinningFireballs 0xA7D4EE
#define fnPhantoon_SpawnFireballsBeforeFight 0xA7D508
#define fnPhantoon_WavyFadeIn 0xA7D54A
#define fnPhantoon_PickPatternForRound1 0xA7D596
#define fnPhantoon_MovePhantoonInFigure8ThenOpenEye 0xA7D5E7
#define fnPhantoon_EyeFollowsSamusUntilTimerRunsOut 0xA7D60D
#define fnPhantoon_BecomesSolidAndBodyVuln 0xA7D65C
#define fnPhantoon_IsSwooping 0xA7D678
#define fnPhantoon_FadeoutWithSwoop 0xA7D6B9
#define fnPhantoon_WaitAfterFadeOut 0xA7D6D4
#define fnPhantoon_MoveLeftOrRightAndPickEyeOpenPatt 0xA7D6E2
#define fnPhantoon_FadeInBeforeFigure8 0xA7D72D
#define fnPhantoon_BecomeSolidAfterRainingFireballs 0xA7D73F
#define fnPhantoon_FadeInDuringFireballRain 0xA7D767
#define fnPhantoon_FollowSamusWithEyeDuringFireballRain 0xA7D788
#define fnPhantoon_FadeOutDuringFireballRain 0xA7D7D5
#define fnPhantoon_SpawnRainingFireballs 0xA7D7F7
#define fnPhantoon_FadeOutBeforeFirstFireballRain 0xA7D82A
#define fnPhantoon_FadeOutBeforeEnrage 0xA7D85C
#define fnPhantoon_MoveEnragedPhantoonToTopCenter 0xA7D874
#define fnPhantoon_FadeInEnragedPhantoon 0xA7D891
#define fnPhantoon_Enraged 0xA7D8AC
#define fnPhantoon_FadeoutAfterEnrage 0xA7D916
#define fnPhantoon_CompleteSwoopAfterFatalShot 0xA7D92E
#define fnPhantoon_DyingPhantoonFadeInOut 0xA7D948
#define fnPhantoon_DyingPhantoonExplosions 0xA7D98B
#define fnPhantoon_WavyDyingPhantoonAndCry 0xA7DA51
#define fnPhantoon_DyingFadeOut 0xA7DA86
#define fnPhantoon_AlmostDead 0xA7DAD7
#define fnPhantoon_Dead 0xA7DB3D
#define fnPhantoon_Hurt 0xA7DD3F
#define fnPhantoon_Touch 0xA7DD95
#define fnnullsub_358 0xA7DD9A
#define fnPhantoon_Shot 0xA7DD9B
#define fnnullsub_45 0xA7E011
#define fnEtecoon_Init 0xA7E912
#define fnEtecoon_Main 0xA7E940
#define fnEtecoon_Func_1 0xA7E958
#define fnEtecoon_Func_2 0xA7E974
#define fnEtecoon_Func_4 0xA7E9AF
#define fnEtecoon_Func_5 0xA7EA00
#define fnEtecoon_Func_6 0xA7EA37
#define fnEtecoon_Func_7 0xA7EAB5
#define fnEtecoon_Func_8 0xA7EB02
#define fnEtecoon_Func_9 0xA7EB2C
#define fnEtecoon_Func_10 0xA7EB50
#define fnEtecoon_Func_11 0xA7EBCD
#define fnEtecoon_Func_12 0xA7EC1B
#define fnEtecoon_Func_16 0xA7EC97
#define fnEtecoon_Func_17 0xA7ECBB
#define fnEtecoon_Func_18 0xA7ECDF
#define fnEtecoon_Func_19 0xA7ED09
#define fnEtecoon_Func_20 0xA7ED2A
#define fnEtecoon_Func_21 0xA7ED54
#define fnEtecoon_Func_22 0xA7ED75
#define fnEtecoon_Func_23 0xA7EDC7
#define fnEtecoon_Func_24 0xA7EE3E
#define fnEtecoon_Func_25 0xA7EE9A
#define fnEtecoon_Func_26 0xA7EEB8
#define fnDachora_Init 0xA7F4DD
#define fnDachora_Main 0xA7F52E
#define fnDachora_Func_1 0xA7F535
#define fnDachora_Func_2 0xA7F570
#define fnDachora_Func_3 0xA7F5BC
#define fnDachora_Func_4 0xA7F5ED
#define fnDachora_Func_5 0xA7F65E
#define fnDachora_Func_7 0xA7F78F
#define fnDachora_Func_8 0xA7F806
#define fnDachora_Func_11 0xA7F935
#define fnDachora_Func_12 0xA7F98C
#define fnEnemy_GrappleReact_NoInteract_A8 0xA88000
#define fnEnemy_GrappleReact_KillEnemy_A8 0xA8800A
#define fnEnemy_GrappleReact_CancelBeam_A8 0xA8800F
#define fnEnemy_GrappleReact_SamusLatchesNoInvinc_A8 0xA88014
#define fnEnemy_GrappleReact_HurtSamus_A8 0xA8801E
#define fnEnemy_NormalTouchAI_A8 0xA88023
#define fnEnemy_NormalShotAI_A8 0xA8802D
#define fnEnemy_NormalPowerBombAI_A8 0xA88037
#define fnEnemy_NormalFrozenAI_A8 0xA88041
#define fnnullsub_170_A8 0xA8804C
#define fnEnemyInstr_Goto_A8 0xA880ED
#define fnEnemyInstr_DecTimerAndGoto2_A8 0xA88110
#define fnEnemyInstr_SetTimer_A8 0xA88123
#define fnEnemyInstr_Sleep_A8 0xA8812F
#define fnEnemyInstr_EnableOffScreenProcessing_A8 0xA88173
#define fnEnemyInstr_DisableOffScreenProcessing_A8 0xA8817D
#define fnMiniDraygon_Instr_2 0xA8878F
#define fnMiniDraygon_Instr_1 0xA8879B
#define fnMiniDraygon_Instr_3 0xA887B6
#define fnMiniDraygon_Instr_4 0xA887CB
#define fnMiniDraygon_Init 0xA887E0
#define fnMiniDraygon_Func_1 0xA88838
#define fnEvirProjectile_Init 0xA888B0
#define fnMiniDraygon_Main 0xA8891B
#define fnMiniDraygon_Func_4 0xA88922
#define fnEvirProjectile_Main 0xA8899E
#define fnMiniDraygon_Func_8 0xA88A34
#define fnMiniDraygon_Func_9 0xA88A3B
#define fnMiniDraygon_Func_10 0xA88A78
#define fnMiniDraygon_Touch 0xA88B06
#define fnMiniDraygon_Powerbomb 0xA88B0C
#define fnMiniDraygon_Shot 0xA88B12
#define fnMorphBallEye_Init 0xA89058
#define fnMorphBallEye_Main 0xA890E2
#define fnMorphBallEye_Func_1 0xA890F1
#define fnMorphBallEye_Func_2 0xA8912E
#define fnMorphBallEye_Func_3 0xA89160
#define fnMorphBallEye_Func_4 0xA891CE
#define fnnullsub_244 0xA891DC
#define fnFune_Instr_2 0xA89625
#define fnFune_Instr_6 0xA89631
#define fnFune_Instr_7 0xA8964A
#define fnFune_Instr_1 0xA89663
#define fnFune_Instr_4 0xA8967C
#define fnFune_Instr_3 0xA89695
#define fnFune_Instr_5 0xA896B4
#define fnFune_Init 0xA896E3
#define fnFune_Main 0xA89730
#define fnFune_Func_1 0xA89737
#define fnFune_Func_2 0xA8975C
#define fnnullsub_247 0xA8978E
#define fnnullsub_248 0xA8978F
#define fnWreckedShipGhost_Init 0xA89AEE
#define fnWreckedShipGhost_Main 0xA89B3C
#define fnWreckedShipGhost_Func_1 0xA89B42
#define fnWreckedShipGhost_Func_2 0xA89BAD
#define fnWreckedShipGhost_Func_4 0xA89C69
#define fnWreckedShipGhost_Func_5 0xA89C8A
#define fnWreckedShipGhost_Func_6 0xA89D13
#define fnWreckedShipGhost_Func_7 0xA89D36
#define fnYappingMaw_Instr_2 0xA8A0C7
#define fnYappingMaw_Instr_4 0xA8A0D9
#define fnYappingMaw_Instr_5 0xA8A0EB
#define fnYappingMaw_Instr_7 0xA8A0FD
#define fnYappingMaw_Instr_3 0xA8A10F
#define fnYappingMaw_Instr_6 0xA8A121
#define fnYappingMaw_Instr_1 0xA8A133
#define fnYappingMaw_Init 0xA8A148
#define fnYappingMaw_Main 0xA8A211
#define fnYappingMaw_Func_1 0xA8A235
#define fnYappingMaw_Func_2 0xA8A28C
#define fnYappingMaw_Func_8 0xA8A445
#define fnYappingMaw_Func_11 0xA8A68A
#define fnYappingMaw_Touch 0xA8A799
#define fnYappingMaw_Shot 0xA8A7BD
#define fnYappingMaw_Frozen 0xA8A835
#define fnKago_Init 0xA8AB46
#define fnKago_Main 0xA8AB75
#define fnKago_Func_1 0xA8AB7B
#define fnnullsub_306 0xA8AB81
#define fnKago_Shot 0xA8AB83
#define fnNorfairLavaMan_Instr_1 0xA8AE12
#define fnNorfairLavaMan_Instr_8 0xA8AE26
#define fnNorfairLavaMan_Instr_14 0xA8AE30
#define fnNorfairLavaMan_Instr_2 0xA8AE3A
#define fnNorfairLavaMan_Instr_7 0xA8AE45
#define fnNorfairLavaMan_Instr_10 0xA8AE50
#define fnNorfairLavaMan_Instr_12 0xA8AE5A
#define fnNorfairLavaMan_Instr_9 0xA8AE64
#define fnNorfairLavaMan_Instr_11 0xA8AE88
#define fnNorfairLavaMan_Instr_13 0xA8AE96
#define fnNorfairLavaMan_Instr_5 0xA8AEBA
#define fnNorfairLavaMan_Instr_15 0xA8AECA
#define fnNorfairLavaMan_Instr_4 0xA8AEE4
#define fnNorfairLavaMan_Instr_16 0xA8AEFE
#define fnNorfairLavaMan_Instr_6 0xA8AF18
#define fnNorfairLavaMan_Instr_3 0xA8AF44
#define fnNorfairLavaMan_Init 0xA8AF8B
#define fnNorfairLavaMan_Func_1 0xA8AF9D
#define fnNorfairLavaMan_Func_6 0xA8B0B2
#define fnNorfairLavaMan_Main 0xA8B10A
#define fnNorfairLavaMan_Func_7 0xA8B11A
#define fnNorfairLavaMan_Func_8 0xA8B175
#define fnsub_A8B193 0xA8B193
#define fnNorfairLavaMan_Func_9 0xA8B1B8
#define fnNorfairLavaMan_Func_10 0xA8B1DD
#define fnNorfairLavaMan_Func_11 0xA8B204
#define fnsub_A8B291 0xA8B291
#define fnNorfairLavaMan_Func_13 0xA8B295
#define fnNorfairLavaMan_Func_15 0xA8B30D
#define fnNorfairLavaMan_Func_16 0xA8B31F
#define fnNorfairLavaMan_Func_17 0xA8B356
#define fnNorfairLavaMan_Func_18 0xA8B3A7
#define fnNorfairLavaMan_Powerbomb 0xA8B400
#define fnNorfairLavaMan_Touch 0xA8B406
#define fnNorfairLavaMan_Shot 0xA8B40C
#define fnBeetom_Instr_1 0xA8B75E
#define fnBeetom_Func_1 0xA8B762
#define fnBeetom_Init 0xA8B776
#define fnBeetom_Func_2 0xA8B7EF
#define fnBeetom_Main 0xA8B80D
#define fnBeetom_Func_3 0xA8B814
#define fnBeetom_Func_4 0xA8B82F
#define fnBeetom_Func_5 0xA8B84F
#define fnBeetom_Func_6 0xA8B85F
#define fnBeetom_Func_7 0xA8B873
#define fnBeetom_Func_8 0xA8B887
#define fnBeetom_Func_9 0xA8B8A9
#define fnBeetom_Func_10 0xA8B8CB
#define fnBeetom_Func_11 0xA8B8ED
#define fnBeetom_Func_12 0xA8B90F
#define fnBeetom_Func_13 0xA8B952
#define fnBeetom_Func_14 0xA8B966
#define fnBeetom_Func_15 0xA8B97A
#define fnBeetom_Func_16 0xA8B9A2
#define fnBeetom_Func_17 0xA8B9B2
#define fnBeetom_Func_18 0xA8B9C1
#define fnBeetom_Func_19 0xA8BA24
#define fnBeetom_Func_20 0xA8BA84
#define fnBeetom_Func_21 0xA8BAB7
#define fnBeetom_Func_24 0xA8BB55
#define fnBeetom_Func_25 0xA8BB88
#define fnBeetom_Func_28 0xA8BC26
#define fnBeetom_Func_29 0xA8BC5A
#define fnBeetom_Func_32 0xA8BCF8
#define fnBeetom_Func_33 0xA8BD42
#define fnBeetom_Func_35 0xA8BD9D
#define fnBeetom_Func_36 0xA8BDC5
#define fnBeetom_Touch 0xA8BE2E
#define fnBeetom_Shot 0xA8BEAC
#define fnMaridiaFloater_Init 0xA8C1C9
#define fnMaridiaFloater_Main 0xA8C21C
#define fnMaridiaFloater_Func_1 0xA8C223
#define fnMaridiaFloater_Func_3 0xA8C283
#define fnMaridiaFloater_Func_4 0xA8C2A6
#define fnMaridiaFloater_Func_5 0xA8C2CF
#define fnMaridiaFloater_Func_6 0xA8C36B
#define fnMaridiaFloater_Func_7 0xA8C3E1
#define fnMaridiaFloater_Func_8 0xA8C469
#define fnMaridiaFloater_Func_9 0xA8C4DC
#define fnMaridiaFloater_Func_10 0xA8C500
#define fnMaridiaFloater_Func_11 0xA8C51D
#define fnnullsub_256 0xA8C568
#define fnMaridiaFloater_Func_12 0xA8C569
#define fnMaridiaFloater_Func_13 0xA8C59F
#define fnMaridiaFloater_Touch 0xA8C5BE
#define fnMaridiaFloater_Shot 0xA8C5EF
#define fnMaridiaFloater_Powerbomb 0xA8C63F
#define fnWreckedShipRobot_Init 0xA8CB77
#define fnWreckedShipRobotDeactivated_Init 0xA8CBCC
#define fnWreckedShipRobot_Main 0xA8CC36
#define fnnullsub_342 0xA8CC66
#define fnWreckedShipRobot_Func_1 0xA8CC67
#define fnWreckedShipRobot_Instr_4 0xA8CD09
#define fnWreckedShipRobot_Instr_9 0xA8CDA4
#define fnWreckedShipRobot_Instr_6 0xA8CDEA
#define fnWreckedShipRobot_Instr_8 0xA8CE85
#define fnWreckedShipRobot_Instr_7 0xA8CECB
#define fnWreckedShipRobot_Instr_15 0xA8CECF
#define fnWreckedShipRobot_Instr_18 0xA8CF6A
#define fnWreckedShipRobot_Instr_16 0xA8CFB0
#define fnWreckedShipRobot_Instr_17 0xA8D04B
#define fnWreckedShipRobot_Instr_3 0xA8D091
#define fnWreckedShipRobot_Instr_10 0xA8D0C2
#define fnWreckedShipRobot_Instr_14 0xA8D0C6
#define fnWreckedShipRobot_Instr_2 0xA8D0D2
#define fnWreckedShipRobot_Instr_13 0xA8D100
#define fnWreckedShipRobot_Instr_1 0xA8D107
#define fnWreckedShipRobot_Instr_12 0xA8D131
#define fnWreckedShipRobot_Instr_5 0xA8D13D
#define fnWreckedShipRobot_Instr_11 0xA8D16B
#define fnWreckedShipRobotDeactivated_Touch 0xA8D174
#define fnWreckedShipRobotDeactivated_Shot 0xA8D18D
#define fnWreckedShipRobot_Shot 0xA8D192
#define fnMaridiaPuffer_Init 0xA8D8C9
#define fnMaridiaPuffer_Main 0xA8D90B
#define fnMaridiaPuffer_Func_1 0xA8D92B
#define fnMaridiaPuffer_Func_2 0xA8D940
#define fnMaridiaPuffer_Func_3 0xA8D963
#define fnMaridiaPuffer_Func_4 0xA8D97C
#define fnMaridiaPuffer_Shot 0xA8DB14
#define fnWalkingLavaSeahorse_Init 0xA8DCCD
#define fnWalkingLavaSeahorse_Main 0xA8DD6B
#define fnWalkingLavaSeahorse_Func_3 0xA8DD71
#define fnWalkingLavaSeahorse_Func_4 0xA8DDC6
#define fnWalkingLavaSeahorse_Func_6 0xA8DE05
#define fnWalkingLavaSeahorse_Func_7 0xA8DE4B
#define fnnullsub_257 0xA8DECC
#define fnWalkingLavaSeahorse_Func_8 0xA8DECD
#define fnWalkingLavaSeahorse_Func_9 0xA8DEEC
#define fnWalkingLavaSeahorse_Instr_4 0xA8DF1C
#define fnWalkingLavaSeahorse_Instr_3 0xA8DF33
#define fnWalkingLavaSeahorse_Instr_5 0xA8DF39
#define fnWalkingLavaSeahorse_Instr_6 0xA8DF3F
#define fnWalkingLavaSeahorse_Instr_2 0xA8DF63
#define fnWalkingLavaSeahorse_Instr_1 0xA8DF71
#define fnWreckedShipOrbs_Init 0xA8E388
#define fnWreckedShipOrbs_Main 0xA8E3C3
#define fnWreckedShipOrbs_Func_3 0xA8E405
#define fnWreckedShipOrbs_Func_4 0xA8E424
#define fnWreckedShipOrbs_Func_5 0xA8E443
#define fnWreckedShipOrbs_Func_6 0xA8E462
#define fnWreckedShipSpark_Instr_2 0xA8E61D
#define fnWreckedShipSpark_Instr_1 0xA8E62A
#define fnWreckedShipSpark_Init 0xA8E637
#define fnWreckedShipSpark_Main 0xA8E68E
#define fnnullsub_259 0xA8E694
#define fnWreckedShipSpark_Func_1 0xA8E695
#define fnWreckedShipSpark_Func_2 0xA8E6B7
#define fnWreckedShipSpark_Func_3 0xA8E6DC
#define fnWreckedShipSpark_Shot 0xA8E70E
#define fnBlueBrinstarFaceBlock_Init 0xA8E82E
#define fnBlueBrinstarFaceBlock_Func_1 0xA8E86E
#define fnBlueBrinstarFaceBlock_Main 0xA8E8AE
#define fnBlueBrinstarFaceBlock_Shot 0xA8E91D
#define fnKiHunter_Init 0xA8F188
#define fnKiHunterWings_Init 0xA8F214
#define fnKiHunter_Main 0xA8F25C
#define fnKiHunterWings_Main 0xA8F262
#define fnKiHunter_Func_1 0xA8F268
#define fnKiHunter_Func_2 0xA8F3B8
#define fnKiHunter_Func_3 0xA8F4ED
#define fnKiHunter_Instr_1 0xA8F526
#define fnKiHunter_Func_4 0xA8F55A
#define fnKiHunter_Func_5 0xA8F58B
#define fnnullsub_346 0xA8F5E3
#define fnKiHunter_Instr_2 0xA8F5E4
#define fnKiHunter_Func_6 0xA8F5F0
#define fnKiHunter_Instr_3 0xA8F67F
#define fnKiHunter_Func_7 0xA8F68B
#define fnKiHunter_Func_8 0xA8F6B3
#define fnKiHunter_Instr_4 0xA8F6D2
#define fnKiHunter_Instr_5 0xA8F6D8
#define fnKiHunter_Func_9 0xA8F6F3
#define fnKiHunter_Shot 0xA8F701
#define fnKiHunter_Func_10 0xA8F7CF
#define fnKiHunter_Func_11 0xA8F7DB
#define fnKiHunter_Func_14 0xA8F8AD
#define fnEnemy_GrappleReact_CancelBeam_A9 0xA9800F
#define fnEnemy_NormalPowerBombAI_A9 0xA98037
#define fnEnemy_NormalFrozenAI_A9 0xA98041
#define fnnullsub_170_A9 0xA9804C
#define fnEnemyInstr_Sleep_A9 0xA9812F
#define fnMotherBrainsBody_Init 0xA98687
#define fnMotherBrainsBrain_Init 0xA98705
#define fnMotherBrainsBody_Hurt 0xA9873E
#define fnMotherBrainsBody_UnpauseHook 0xA98763
#define fnnullsub_264 0xA98786
#define fnMotherBrainsBody_Powerbomb 0xA98787
#define fnMotherBrainsBrain_Hurt 0xA9878B
#define fnMotherBrainsBrain_SetupBrainAndNeckToDraw 0xA987A2
#define fnMotherBrain_DrawBrainNeck_EnemyGfxDrawHook 0xA987C9
#define fnMotherBrainsBrain_SetupBrainToDraw 0xA987D0
#define fnMotherBrainsBrain_GfxDrawHook 0xA987DD
#define fnMotherBrainsBody_FirstPhase_DoubleRet 0xA987E1
#define fnMotherBrainBody_FakeDeath_Descent_0_Pause 0xA9881D
#define fnMotherBrainBody_FakeDeath_Descent_1 0xA98829
#define fnMotherBrainBody_FakeDeath_Descent_2 0xA9884D
#define fnMotherBrainBody_FakeDeath_Descent_3 0xA9886C
#define fnMotherBrainBody_FakeDeath_Descent_4 0xA98884
#define fnMotherBrainBody_FakeDeath_Descent_5 0xA988B2
#define fnMotherBrainBody_FakeDeath_Descent_6 0xA988D3
#define fnMotherBrainBody_0_Wait 0xA98949
#define fnMotherBrainBody_1_ClearBottomLeftTube 0xA9896E
#define fnMotherBrainBody_2_SpawnTopRightTubeFalling 0xA98983
#define fnMotherBrainBody_3_ClearCeilingBlock9 0xA989A0
#define fnMotherBrainBody_4_SpawnTopLeftTubeFalling 0xA989B5
#define fnMotherBrainBody_4_ClearCeilingBlock6 0xA989D2
#define fnMotherBrainBody_5_SpawnTubeFallingEnemy1 0xA989E7
#define fnMotherBrainBody_6_ClearBottomRightTube 0xA989FA
#define fnMotherBrainBody_7_SpawnTubeFallingEnemy2 0xA98A0F
#define fnMotherBrainBody_8_ClearBottomMiddleLeftTube 0xA98A22
#define fnMotherBrainBody_9_SpawnTopMiddleLeftFalling 0xA98A37
#define fnMotherBrainBody_10_ClearCeilingTubeColumn7 0xA98A54
#define fnMotherBrainBody_11_SpawnTopMiddleRightFalling 0xA98A69
#define fnMotherBrainBody_12_ClearCeilingTubeColumn8 0xA98A86
#define fnMotherBrainBody_13_SpawnTubeFallingEnemy3 0xA98A9B
#define fnMotherBrainBody_14_ClearBottomMiddleRightTube 0xA98AAE
#define fnMotherBrainBody_15_SpawnTubeFallingEnemy4 0xA98AC3
#define fnMotherBrainBody_16_ClearBottomMiddleTubes 0xA98AD6
#define fnnullsub_365 0xA98AE4
#define fnMotherBrainsTubesFalling_Init 0xA98B35
#define fnMotherBrainsTubesFalling_Main 0xA98B85
#define fnMotherBrainsTubesFalling_Main_NonMain 0xA98B88
#define fnMotherBrainsTubesFalling_WaitToFall 0xA98BCB
#define fnMotherBrainsTubesFalling_Falling 0xA98BD6
#define fnMotherBrainBody_FakeDeath_Ascent_0_DrawBG1Row23 0xA98C87
#define fnMotherBrainBody_FakeDeath_Ascent_1_DrawBG1Row45 0xA98C9E
#define fnMotherBrainBody_FakeDeath_Ascent_2_DrawBG1Row67 0xA98CB5
#define fnMotherBrainBody_FakeDeath_Ascent_3_DrawBG1Row89 0xA98CCC
#define fnMotherBrainBody_FakeDeath_Ascent_4_DrawBG1RowAB 0xA98CE3
#define fnMotherBrainBody_FakeDeath_Ascent_5_DrawBG1RowCD 0xA98CFA
#define fnMotherBrainBody_FakeDeath_Ascent_6_SetupPhase2Gfx 0xA98D11
#define fnMotherBrainBody_FakeDeath_Ascent_7_SetupPhase2Brain 0xA98D49
#define fnMotherBrainBody_FakeDeath_Ascent_8_Pause 0xA98D79
#define fnMotherBrainBody_FakeDeath_Ascent_9_PrepareRise 0xA98D8B
#define fnMotherBrainBody_FakeDeath_Ascent_10_LoadLegTiles 0xA98DB4
#define fnMotherBrainBody_FakeDeath_Ascent_11_ContinuePause 0xA98DC3
#define fnMotherBrainBody_FakeDeath_Ascent_12_StartMusic 0xA98DEC
#define fnMotherBrainBody_FakeDeath_Ascent_13_Raise 0xA98E4D
#define fnMotherBrainBody_FakeDeath_Ascent_14_WaitForUncouching 0xA98E95
#define fnMotherBrainBody_FakeDeath_Ascent_15_TransitionFromGrey 0xA98EAA
#define fnMotherBrainBody_2ndphase_16_ShakeHeadMenacingly 0xA98EF5
#define fnMotherBrainBody_2ndphase_17_BringHeadBackUp 0xA98F14
#define fnMotherBrainBody_2ndphase_18_FinishStretching 0xA98F33
#define fnMotherBrain_DrawBrain 0xA99357
#define fnMotherBrain_Instr_MoveBodyUp10Left4 0xA995B6
#define fnMotherBrain_Instr_MoveBodyUp16Left4 0xA995C0
#define fnMotherBrain_Instr_MoveBodyUp12Right2 0xA995CA
#define fnMotherBrain_Instr_MoveDown12Left4 0xA995DE
#define fnMotherBrain_Instr_MoveDown16Right2 0xA995E8
#define fnMotherBrain_Instr_MoveDown10Right2 0xA995F2
#define fnMotherBrain_Instr_MoveUp2Right1 0xA995FC
#define fnMotherBrain_Instr_MoveRight2 0xA9960C
#define fnMotherBrain_Instr_MoveUp1 0xA9961C
#define fnMotherBrain_Instr_MoveUp1Right3_Sfx 0xA99622
#define fnMotherBrain_Instr_Down2Right15 0xA99638
#define fnMotherBrain_Instr_Down4Right6 0xA99648
#define fnMotherBrain_Instr_Up4Left2 0xA99658
#define fnMotherBrain_Instr_Up2Left1_Sfx 0xA99668
#define fnMotherBrain_Instr_Up2Left1_Sfx2 0xA9967E
#define fnMotherBrain_Instr_MoveLeft2 0xA99694
#define fnMotherBrain_Instr_MoveDown1 0xA996A4
#define fnMotherBrain_Instr_MoveDown1Left3 0xA996AA
#define fnMotherBrain_Instr_MoveUp2Left15_Sfx 0xA996BA
#define fnMotherBrain_Instr_MoveUp4Left6 0xA996D0
#define fnMotherBrain_Instr_MoveDown4Right2 0xA996E0
#define fnMotherBrain_Instr_MoveDown2Right1 0xA996F0
#define fnMotherBrain_Instr_SetPose_Standing 0xA99700
#define fnMotherBrain_Instr_SetPose_Walking 0xA99708
#define fnMotherBrain_Instr_SetPose_Crouched 0xA99710
#define fnMotherBrain_Instr_SetPose_CrouchedTrans 0xA99718
#define fnMotherBrain_Instr_SetPose_DeathBeamMode 0xA99720
#define fnMotherBrain_Instr_SetPose_LeaningDown 0xA99728
#define fnMotherBrain_Instr_SpawnEprojToOffset 0xA99AC8
#define fnMotherBrain_Instr_SpawnDeathBeamEproj 0xA99AEF
#define fnMotherBrain_Instr_IncrBeamAttackPhase 0xA99B05
#define fnMotherBrain_Instr_Goto 0xA99B0F
#define fnMotherBrain_Instr_EnableNeckMovementGoto 0xA99B14
#define fnMotherBrain_Instr_DisableNeckMovement 0xA99B20
#define fnMotherBrain_Instr_QueueSfx2 0xA99B28
#define fnMotherBrain_Instr_QueueSfx3 0xA99B32
#define fnMotherBrain_Instr_SpawnDroolEproj 0xA99B3C
#define fnMotherBrain_Instr_SpawnPurpleBreath 0xA99B6D
#define fnMotherBrain_Instr_SetMainShakeTimer50 0xA99B77
#define fnMotherBrain_Instr_GotoEitherOr 0xA99C65
#define fnMotherBrain_Instr_MaybeGoto 0xA99CAD
#define fnMotherBrain_Instr_MaybeGoto2 0xA99D0D
#define fnMotherBrain_Instr_Goto2 0xA99D21
#define fnMotherBrain_Instr_QueueShitroidAttackSfx 0xA99DF7
#define fnMotherBrain_Instr_SpawnBlueRingEproj 0xA99E29
#define fnMotherBrain_Instr_AimRingsAtShitroid 0xA99E37
#define fnMotherBrain_Instr_AimRingsAtSamus 0xA99E5B
#define fnMotherBrain_Instr_AimRings 0xA99E77
#define fnMotherBrain_Instr_IncrShitroidAttackCtr 0xA99EA3
#define fnMotherBrain_Instr_SetShitroidAttackCtr0 0xA99EB5
#define fnMotherBrain_Instr_SpawnBombEproj 0xA99EBD
#define fnMotherBrain_Instr_SpawnLaserEproj 0xA99F46
#define fnMotherBrain_Instr_SpawnRainbowEproj 0xA99F84
#define fnMotherBrain_Instr_SetupFxForRainbowBeam 0xA99F8E
#define fnMotherBrain_Phase3_Death_0 0xA9AEE1
#define fnMotherBrain_Phase3_Death_1 0xA9AF12
#define fnMotherBrain_Phase3_Death_2 0xA9AF21
#define fnMotherBrain_Phase3_Death_3 0xA9AF54
#define fnMotherBrain_Phase3_Death_4 0xA9AF9D
#define fnMotherBrain_Phase3_Death_5 0xA9AFB6
#define fnMotherBrain_Phase3_Death_6 0xA9B013
#define fnMotherBrain_Phase3_Death_7 0xA9B115
#define fnMotherBrain_Phase3_Death_8 0xA9B12D
#define fnMotherBrain_Phase3_Death_9 0xA9B15E
#define fnMotherBrain_Phase3_Death_10 0xA9B173
#define fnMotherBrain_Phase3_Death_11 0xA9B189
#define fnMotherBrain_Phase3_Death_12 0xA9B1B8
#define fnMotherBrain_Phase3_Death_13 0xA9B1D5
#define fnMotherBrain_Phase3_Death_14_20framedelay 0xA9B211
#define fnMotherBrain_CorpseRottingFinished 0xA9B223
#define fnMotherBrain_Phase3_Death_15_LoadEscapeTimerTiles 0xA9B258
#define fnMotherBrain_Phase3_Death_16_StartEscape 0xA9B26D
#define fnMotherBrain_Phase3_Death_17_SpawnTimeBomb 0xA9B2D1
#define fnMotherBrain_Phase3_Death_18_TypesZebesText 0xA9B2E3
#define fnMotherBrain_Phase3_Death_19_EscapeDoorExploding 0xA9B2F9
#define fnMotherBrain_Phase3_Death_20_BlowUpEscapeDoor 0xA9B32A
#define fnMotherBrain_Phase3_Death_21_KeepEarthquakeGoing 0xA9B33C
#define fnMotherBrainsBody_Shot 0xA9B503
#define fnMotherBrainsBrain_Shot 0xA9B507
#define fnnullsub_47 0xA9B5C5
#define fnMotherBrainsBrain_Touch 0xA9B5C6
#define fnMotherBrain_Body_Phase2_Thinking 0xA9B605
#define fnMotherBrain_Body_Phase2_TryAttack 0xA9B64B
#define fnMotherBrain_FiringBomb_DecideOnWalking 0xA9B781
#define fnMotherBrain_FiringBomb_WalkingBackwards 0xA9B7AC
#define fnMotherBrain_FiringBomb_Crouch 0xA9B7C6
#define fnMotherBrain_FiringBomb_Fired 0xA9B7E8
#define fnMotherBrain_FiringBomb_Standup 0xA9B7F8
#define fnMotherBomb_FiringLaser_PositionHead 0xA9B80E
#define fnMotherBomb_FiringLaser_PositionHeadSlowlyFire 0xA9B839
#define fnMotherBomb_FiringLaser_FinishAttack 0xA9B863
#define fnMotherBomb_FiringDeathBeam 0xA9B87D
#define fnMotherBomb_FiringRainbowBeam_0 0xA9B8EB
#define fnMotherBomb_FiringRainbowBeam_1_StartCharge 0xA9B91A
#define fnMotherBomb_FiringRainbowBeam_2_RetractNeck 0xA9B92B
#define fnMotherBomb_FiringRainbowBeam_3_Wait 0xA9B93F
#define fnMotherBomb_FiringRainbowBeam_4_ExtendNeckDown 0xA9B951
#define fnMotherBomb_FiringRainbowBeam_5_StartFiring 0xA9B975
#define fnMotherBomb_FiringRainbowBeam_6_MoveSamusToWall 0xA9B9E5
#define fnMotherBomb_FiringRainbowBeam_7_DelayFrame 0xA9BA00
#define fnMotherBomb_FiringRainbowBeam_8_StartDrainSamus 0xA9BA27
#define fnMotherBomb_FiringRainbowBeam_9_DrainingSamus 0xA9BA3C
#define fnMotherBomb_FiringRainbowBeam_10_FinishFiringRainbow 0xA9BA5E
#define fnMotherBomb_FiringRainbowBeam_11_LetSamusFall 0xA9BAC4
#define fnMotherBomb_FiringRainbowBeam_12_WaitForSamusHitGround 0xA9BAD1
#define fnMotherBomb_FiringRainbowBeam_13_LowerHead 0xA9BADD
#define fnMotherBomb_FiringRainbowBeam_14_DecideNextAction 0xA9BB06
#define fnMotherBrain_Phase2Cut_0 0xA9BD45
#define fnMotherBrain_Phase2Cut_1 0xA9BD98
#define fnMotherBrain_Phase2Cut_2 0xA9BDA9
#define fnMotherBrain_Phase2Cut_3 0xA9BDC1
#define fnMotherBrain_Phase2Cut_4 0xA9BDD2
#define fnMotherBrain_Phase2Cut_5 0xA9BDED
#define fnnullsub_364 0xA9BE1A
#define fnMotherBrain_DrainedByShitroid_0 0xA9BE38
#define fnMotherBrain_DrainedByShitroid_1 0xA9BE5D
#define fnMotherBrain_DrainedByShitroid_2 0xA9BE96
#define fnMotherBrain_DrainedByShitroid_3 0xA9BF0E
#define fnMotherBrain_DrainedByShitroid_4 0xA9BF41
#define fnMotherBrain_DrainedByShitroid_5 0xA9BF56
#define fnMotherBrain_DrainedByShitroid_6 0xA9BF7D
#define fnMotherBrain_DrainedByShitroid_7 0xA9BF95
#define fnMotherBrain_PainfulWalkForwards 0xA9BFD0
#define fnMotherBrain_PainfulWalkingForwards 0xA9BFE8
#define fnMotherBrain_PainfulWalkBackwards 0xA9C004
#define fnMotherBrain_PainfulWalkingBackwards 0xA9C01C
#define fnMotherBrain_Phase2_Revive_0 0xA9C059
#define fnMotherBrain_Phase2_Revive_1 0xA9C066
#define fnMotherBrain_Phase2_Revive_2 0xA9C082
#define fnMotherBrain_Phase2_Revive_3 0xA9C08F
#define fnMotherBrain_Phase2_Revive_4 0xA9C0BA
#define fnMotherBrain_Phase2_Revive_5 0xA9C0E4
#define fnMotherBrain_Phase2_Revive_6 0xA9C0FB
#define fnMotherBrain_Phase2_Revive_7 0xA9C11E
#define fnMotherBrain_Phase2_Revive_8 0xA9C147
#define fnMotherBrain_Phase2_MurderShitroid_1 0xA9C15C
#define fnMotherBrain_Phase2_MurderShitroid_2 0xA9C182
#define fnnullsub_367 0xA9C18D
#define fnMotherBrain_Phase2_PrepareForFinalShitroid 0xA9C18E
#define fnMotherBrain_Phase2_ExecuteFinalkShitroid 0xA9C19A
#define fnnullsub_363 0xA9C1A6
#define fnMotherBrain_Phase3_Recover_MakeDistance 0xA9C1CF
#define fnMotherBrain_Phase3_Recover_SetupForFight 0xA9C1F0
#define fnMotherBrain_Phase3_Fighting_Main 0xA9C209
#define fnMotherBrain_Phase3_Fighting_Cooldown 0xA9C24E
#define fnMotherBrain_Phase3_Walk_TryToInchForward 0xA9C26A
#define fnMotherBrain_Phase3_Walk_RetreatQuickly 0xA9C2B3
#define fnMotherBrain_Phase3_Walk_RetreatSlowly 0xA9C2D2
#define fnMotherBrain_Phase3_Neck_Normal 0xA9C330
#define fnnullsub_369 0xA9C353
#define fnMotherBrain_Phase3_Neck_SetupRecoilRecovery 0xA9C354
#define fnMotherBrain_Phase3_Neck_RecoilRecovery 0xA9C37B
#define fnMotherBrain_Phase3_Neck_SetupHyperBeamRecoil 0xA9C395
#define fnMotherBrain_Phase3_Neck_HyperBeamRecoil 0xA9C3CD
#define fnShitroidInCutscene_Init 0xA9C710
#define fnShitroidInCutscene_Main 0xA9C779
#define fnShitroidInCutscene_DashOntoScreen 0xA9C7CC
#define fnShitroidInCutscene_CurveTowardsBrain 0xA9C7EC
#define fnShitroidInCutscene_GetIntoFace 0xA9C811
#define fnShitroidInCutscene_LatchOntoBrain 0xA9C851
#define fnShitroidInCutscene_SetMotherBrainToStumbleBack 0xA9C879
#define fnShitroidInCutscene_ActivateRainbowBeam 0xA9C889
#define fnShitroidInCutscene_BrainTurnsToCorpse 0xA9C8E2
#define fnShitroidInCutscene_StopDraining 0xA9C915
#define fnShitroidInCutscene_LetGoAndSpawnDust 0xA9C94B
#define fnShitroidInCutscene_MoveUpToCeiling 0xA9C959
#define fnShitroidInCutscene_MoveToSamus 0xA9C9C3
#define fnShitroidInCutscene_LatchOntoSamus 0xA9CA66
#define fnShitroidInCutscene_HealSamusToFullHealth 0xA9CA7A
#define fnnullsub_368 0xA9CABC
#define fnShitroidInCutscene_IdleUntilToNoHealth 0xA9CABD
#define fnShitroidInCutscene_ReleaseSamus 0xA9CB13
#define fnShitroidInCutscene_StareDownMotherBrain 0xA9CB2D
#define fnShitroidInCutscene_FlyOffScreen 0xA9CB56
#define fnShitroidInCutscene_MoveToFinalChargeStart 0xA9CB7B
#define fnShitroidInCutscene_InitiateFinalCharge 0xA9CBB3
#define fnShitroidInCutscene_FinalCharge 0xA9CBD8
#define fnShitroidInCutscene_ShitroidFinalBelow 0xA9CC3E
#define fnShitroidInCutscene_PlaySamusTheme 0xA9CC60
#define fnShitroidInCutscene_PrepareSamusHyperbeam 0xA9CC7F
#define fnnullsub_338 0xA9CC98
#define fnShitroidInCutscene_DeathSequence 0xA9CC99
#define fnShitroidInCutscene_UnloadShitroid 0xA9CCC0
#define fnShitroidInCutscene_LetSamusRainbowMore 0xA9CCDE
#define fnShitroidInCutscene_FinishCutscene 0xA9CCF0
#define fnSamusRainbowPaletteFunc_ActivateWhenEnemyLow 0xA9CD30
#define fnSamusRainbowPaletteFunc_GraduallySlowDown 0xA9CD4B
#define fnShitroidInCutscene_Touch 0xA9CF03
#define fnShitroid_Instr_1 0xA9CFB4
#define fnShitroid_Instr_2 0xA9CFCA
#define fnDeadTorizo_Init 0xA9D308
#define fnDeadTorizo_Main 0xA9D368
#define fnDeadTorizo_MainGfxHook 0xA9D39A
#define fnDeadTorizo_WaitForSamusColl 0xA9D3AD
#define fnnullsub_361 0xA9D3C7
#define fnDeadTorizo_PreRotDelay 0xA9D3C8
#define fnDeadTorizo_Rotting 0xA9D3E6
#define fnDeadTorizo_Powerbomb 0xA9D42A
#define fnDeadTorizo_Shot 0xA9D433
#define fnDeadTorizo_CorpseRottingFinished 0xA9D5BD
#define fnDeadSidehopper_Init 0xA9D7B6
#define fnDeadZoomer_Init 0xA9D849
#define fnDeadRipper_Init 0xA9D876
#define fnDeadSkree_Init 0xA9D89F
#define fnDeadSidehopper_Powerbomb 0xA9D8CC
#define fnDeadSidehopper_Main 0xA9D8DB
#define fnDeadSidehopper_Alive_WaitForActivate 0xA9D8E2
#define fnDeadSidehopper_Activated 0xA9D8F1
#define fnnullsub_362 0xA9D90F
#define fnDeadMonsters_Func_1 0xA9D910
#define fnDeadMonsters_Func_2 0xA9D91D
#define fnDeadMonsters_Func_5 0xA9DA08
#define fnnullsub_268 0xA9DA63
#define fnDeadSidehopper_WaitForSamusColl 0xA9DA64
#define fnDeadZoomer_WaitForSamusColl 0xA9DA69
#define fnDeadSkree_WaitForSamusColl 0xA9DA6E
#define fnDeadRipper_WaitForSamusColl 0xA9DA73
#define fnDeadSidehopper_PreRotDelay 0xA9DA8F
#define fnDeadZoomer_PreRotDelay 0xA9DA94
#define fnDeadRipper_PreRotDelay 0xA9DA99
#define fnDeadSkree_PreRotDelay 0xA9DA9E
#define fnDeadSidehopper_Rotting 0xA9DABA
#define fnDeadZoomer_Rotting 0xA9DAD0
#define fnDeadRipper_Rotting 0xA9DAE6
#define fnDeadSkree_Rotting 0xA9DAFC
#define fnCorpseRottingRotEntryFinishedHook 0xA9DC08
#define fnDeadZoomer_Powerbomb 0xA9DCED
#define fnDeadZoomer_Shot 0xA9DCF8
#define fnDeadRipper_Powerbomb 0xA9DCFD
#define fnDeadRipper_Shot 0xA9DD08
#define fnDeadSkree_Powerbomb 0xA9DD0D
#define fnDeadSkree_Shot 0xA9DD18
#define fnDeadSidehopper_Shot 0xA9DD1D
#define fnDeadSidehopper_Touch 0xA9DD44
#define fnTorizo_CorpseRottingInitFunc 0xA9DE18
#define fnSidehopper_CorpseRottingInitFunc_0 0xA9DEC1
#define fnSidehopper_CorpseRottingInitFunc_2 0xA9DF08
#define fnZoomer_CorpseRottingInitFunc_0 0xA9DF4F
#define fnZoomer_CorpseRottingInitFunc_2 0xA9DF6C
#define fnZoomer_CorpseRottingInitFunc_4 0xA9DF89
#define fnRipper_CorpseRottingInitFunc_0 0xA9DFA6
#define fnRipper_CorpseRottingInitFunc_2 0xA9DFC3
#define fnSkree_CorpseRottingInitFunc_0 0xA9DFE0
#define fnSkree_CorpseRottingInitFunc_2 0xA9E019
#define fnSkree_CorpseRottingInitFunc_4 0xA9E052
#define fnMotherBrain_CorpseRottingInitFunc 0xA9E08B
#define fnTorizo_CorpseRottingMoveFunc 0xA9E272
#define fnTorizo_CorpseRottingCopyFunc 0xA9E38B
#define fnSidehopper_CorpseRottingMoveFunc_0 0xA9E468
#define fnSidehopper_CorpseRottingCopyFunc_0 0xA9E4F5
#define fnSidehopper_CorpseRottingMoveFunc_2 0xA9E564
#define fnSidehopper_CorpseRottingCopyFunc_2 0xA9E5F6
#define fnZoomer_CorpseRottingMoveFunc_0 0xA9E66A
#define fnZoomer_CorpseRottingCopyFunc_0 0xA9E6B9
#define fnZoomer_CorpseRottingMoveFunc_2 0xA9E6F6
#define fnZoomer_CorpseRottingCopyFunc_2 0xA9E745
#define fnZoomer_CorpseRottingMoveFunc_4 0xA9E782
#define fnZoomer_CorpseRottingCopyFunc_4 0xA9E7D1
#define fnRipper_CorpseRottingMoveFunc_0 0xA9E80E
#define fnRipper_CorpseRottingCopyFunc_0 0xA9E85D
#define fnRipper_CorpseRottingMoveFunc_2 0xA9E89A
#define fnRipper_CorpseRottingCopyFunc_2 0xA9E8E9
#define fnSkree_CorpseRottingMoveFunc_0 0xA9E926
#define fnSkree_CorpseRottingCopyFunc_0 0xA9E95B
#define fnSkree_CorpseRottingMoveFunc_2 0xA9E984
#define fnSkree_CorpseRottingCopyFunc_2 0xA9E9B9
#define fnSkree_CorpseRottingMoveFunc_4 0xA9E9E2
#define fnSkree_CorpseRottingCopyFunc_4 0xA9EA17
#define fnMotherBrain_CorpseRottingMoveFunc 0xA9EA40
#define fnMotherBrain_CorpseRottingCopyFunc 0xA9EB0B
#define fnsub_A9ECD0 0xA9ECD0
#define fnShitroid_Func_1 0xA9EED1
#define fnShitroid_Func_2 0xA9EF06
#define fnShitroid_Init 0xA9EF37
#define fnShitroid_Powerbomb 0xA9EFBA
#define fnShitroid_Main 0xA9EFC5
#define fnShitroid_Func_3 0xA9EFDF
#define fnShitroid_Func_4 0xA9EFE6
#define fnShitroid_Func_5 0xA9F02B
#define fnShitroid_Func_6 0xA9F037
#define fnShitroid_Func_7 0xA9F049
#define fnShitroid_Func_8 0xA9F06D
#define fnShitroid_Func_9 0xA9F094
#define fnShitroid_Func_10 0xA9F0E6
#define fnShitroid_Func_11 0xA9F125
#define fnShitroid_Func_12 0xA9F138
#define fnShitroid_Func_13 0xA9F180
#define fnShitroid_Func_14 0xA9F1FA
#define fnShitroid_Func_15 0xA9F20E
#define fnShitroid_Func_16 0xA9F21B
#define fnShitroid_Func_17 0xA9F2A2
#define fnShitroid_Func_18 0xA9F2AE
#define fnShitroid_Func_19 0xA9F2C0
#define fnShitroid_Func_20 0xA9F2FB
#define fnShitroid_Func_21 0xA9F324
#define fnShitroid_Func_22 0xA9F360
#define fnShitroid_Func_23 0xA9F36D
#define fnShitroid_Func_24 0xA9F3A3
#define fnShitroid_Func_25 0xA9F3BE
#define fnShitroid_GraduallyAccelerateTowards0x8 0xA9F45F
#define fnShitroid_GraduallyAccelerateTowards0x10 0xA9F466
#define fnShitroid_HandleCutscenePalette 0xA9F683
#define fnShitroid_HandleCutscenePalette_LowHealth 0xA9F68F
#define fnShitroid_Touch 0xA9F789
#define fnShitroid_Shot 0xA9F842
#define fnShitroid_Instr_3 0xA9F920
#define fnShitroid_Instr_4 0xA9F936
#define fnShitroid_Instr_6 0xA9F990
#define fnShitroid_Instr_5 0xA9F994
#define fnEnemy_GrappleReact_CancelBeam_AA 0xAA800F
#define fnEnemy_NormalPowerBombAI_AA 0xAA8037
#define fnEnemy_NormalFrozenAI_AA 0xAA8041
#define fnnullsub_170_AA 0xAA804C
#define fnEnemy_SetAiPreInstr_AA 0xAA806B
#define fnEnemy_ClearAiPreInstr_AA 0xAA8074
#define fnnullsub_171_AA 0xAA807B
#define fnEnemyInstr_StopScript_AA 0xAA807C
#define fnEnemyInstr_Goto_AA 0xAA80ED
#define fnEnemyInstr_DecTimerAndGoto2_AA 0xAA8110
#define fnEnemyInstr_SetTimer_AA 0xAA8123
#define fnEnemyInstr_Sleep_AA 0xAA812F
#define fnEnemyInstr_WaitNframes_AA 0xAA813A
#define fnEnemyInstr_CopyToVram_AA 0xAA814B
#define fnTorizo_Instr_3 0xAAB09C
#define fnTorizo_Instr_31 0xAAB11D
#define fnTorizo_Instr_33 0xAAB1BE
#define fnTorizo_Instr_36 0xAAB224
#define fnTorizo_Instr_37 0xAAB22E
#define fnTorizo_Instr_35 0xAAB238
#define fnTorizo_Instr_38 0xAAB24D
#define fnTorizo_Instr_6 0xAAB271
#define fnTorizo_Instr_5 0xAAB94D
#define fnTorizo_Instr_9 0xAAB951
#define fnTorizo_Instr_7 0xAAC2C8
#define fnTorizo_Instr_2 0xAAC2C9
#define fnTorizo_Instr_8 0xAAC2D1
#define fnTorizo_Instr_25 0xAAC2D9
#define fnTorizo_Instr_22 0xAAC2ED
#define fnTorizo_Instr_19 0xAAC2F7
#define fnTorizo_Instr_32 0xAAC2FD
#define fnTorizo_Instr_30 0xAAC303
#define fnTorizo_Instr_34 0xAAC32F
#define fnTorizo_Instr_24 0xAAC34A
#define fnTorizo_Instr_12 0xAAC35B
#define fnTorizo_Instr_10 0xAAC36D
#define fnTorizo_Instr_11 0xAAC377
#define fnTorizo_Instr_29 0xAAC38A
#define fnTorizo_Instr_1 0xAAC3A0
#define fnTorizo_Instr_28 0xAAC3B6
#define fnTorizo_Instr_4 0xAAC3CC
#define fnTorizo_Instr_40 0xAAC41E
#define fnTorizo_Instr_16 0xAAC470
#define fnTorizo_Instr_27 0xAAC4E5
#define fnTorizo_Instr_23 0xAAC55A
#define fnTorizo_Instr_14 0xAAC567
#define fnTorizo_Instr_15 0xAAC58B
#define fnTorizo_Instr_26 0xAAC5A4
#define fnTorizo_Instr_18 0xAAC5CB
#define fnTorizo_Instr_20 0xAAC5E3
#define fnTorizo_Instr_44 0xAAC5F2
#define fnTorizo_Instr_21 0xAAC601
#define fnTorizo_Instr_17 0xAAC610
#define fnTorizo_Instr_13 0xAAC618
#define fnTorizo_Hurt 0xAAC67E
#define fnTorizo_Main 0xAAC6A4
#define fnnullsub_270 0xAAC6AB
#define fnTorizo_Func_3 0xAAC6BF
#define fnTorizo_Func_4 0xAAC6C6
#define fnTorizo_Func_1 0xAAC6FF
#define fnTorizo_Func_5 0xAAC752
#define fnTorizo_Func_6 0xAAC828
#define fnTorizo_Func_7 0xAAC82C
#define fnTorizo_Init 0xAAC87F
#define fnnullsub_344 0xAAC95E
#define fnGoldTorizo_Touch 0xAAC977
#define fnTorizo_Shot 0xAAC97C
#define fnnullsub_271 0xAAC9C1
#define fnTorizo_Func_8 0xAAC9C2
#define fnTorizo_Instr_39 0xAACACE
#define fnTorizo_Instr_41 0xAACADE
#define fnTorizo_Instr_42 0xAACAE2
#define fnTorizo_Instr_48 0xAACDD7
#define fnTorizo_Instr_57 0xAAD0E9
#define fnTorizo_Instr_58 0xAAD0F3
#define fnTorizo_Instr_59 0xAAD17B
#define fnTorizo_Instr_62 0xAAD187
#define fnTorizo_Instr_63 0xAAD1E7
#define fnGoldTorizo_Main 0xAAD369
#define fnTorizo_Instr_56 0xAAD38F
#define fnTorizo_Instr_60 0xAAD397
#define fnTorizo_Instr_46 0xAAD39F
#define fnGoldTorizo_Hurt 0xAAD3BA
#define fnTorizo_Instr_47 0xAAD3E0
#define fnTorizo_Instr_49 0xAAD3EA
#define fnTorizo_Instr_61 0xAAD436
#define fnTorizo_Instr_53 0xAAD445
#define fnTorizo_Instr_55 0xAAD474
#define fnTorizo_Instr_52 0xAAD49B
#define fnTorizo_Instr_50 0xAAD4BA
#define fnTorizo_Instr_43 0xAAD4F3
#define fnTorizo_Instr_51 0xAAD4FD
#define fnTorizo_Instr_45 0xAAD526
#define fnTorizo_Instr_54 0xAAD54D
#define fnTorizo_Func_9 0xAAD5C2
#define fnTorizo_Func_10 0xAAD5DF
#define fnTorizo_D5E6 0xAAD5E6
#define fnTorizo_D5ED 0xAAD5ED
#define fnTorizo_D5F1 0xAAD5F1
#define fnGoldTorizo_Shot 0xAAD667
#define fnnullsub_49 0xAAD7C7
#define fnTourianEntranceStatue_Init 0xAAD7C8
#define fnShaktool_Instr_2 0xAAD931
#define fnShaktool_Instr_3 0xAAD93F
#define fnShaktool_Instr_4 0xAAD94A
#define fnShaktool_Instr_5 0xAAD953
#define fnShaktool_Instr_6 0xAAD99F
#define fnShaktool_Instr_1 0xAAD9BA
#define fnShaktool_Hurt 0xAADCA3
#define fnnullsub_274 0xAADCAA
#define fnnullsub_275 0xAADCAB
#define fnShaktool_DCAC 0xAADCAC
#define fnShaktool_DCD7 0xAADCD7
#define fnShaktool_DD25 0xAADD25
#define fnShaktool_Init 0xAADE43
#define fnShaktool_Touch 0xAADF2F
#define fnShaktool_Shot 0xAADF34
#define fnShaktool_Instr_9 0xAAE429
#define fnShaktool_Instr_11 0xAAE436
#define fnShaktool_Instr_10 0xAAE43D
#define fnsub_AAE445 0xAAE445
#define fnShaktool_Instr_8 0xAAE57F
#define fnShaktool_Instr_13 0xAAE587
#define fnShaktool_Instr_12 0xAAE58F
#define fnShaktool_Instr_7 0xAAE5D8
#define fnShaktool_Instr_14 0xAAE6F0
#define fnN00bTubeCracks_Init 0xAAE716
#define fnChozoStatue_Init 0xAAE725
#define fnnullsub_276 0xAAE7A6
#define fnChozoStatue_Main 0xAAE7A7
#define fnShaktool_PreInstr_0 0xAAE7AE
#define fnnullsub_277 0xAAE7DA
#define fnnullsub_51 0xAAE7DB
#define fnnullsub_52 0xAAE7DC
#define fnEnemy_GrappleReact_CancelBeam_B2 0xB2800F
#define fnEnemy_NormalPowerBombAI_B2 0xB28037
#define fnEnemy_NormalFrozenAI_B2 0xB28041
#define fnnullsub_169_B2 0xB2804B
#define fnnullsub_170_B2 0xB2804C
#define fnEnemyInstr_Goto_B2 0xB280ED
#define fnEnemyInstr_DecTimerAndGoto2_B2 0xB28110
#define fnEnemyInstr_SetTimer_B2 0xB28123
#define fnEnemyInstr_Sleep_B2 0xB2812F
#define fnEnemyInstr_WaitNframes_B2 0xB2813A
#define fnSpacePirates_Powerbomb 0xB28767
#define fnSpacePirates_TouchAi 0xB2876C
#define fnSpacePirates_ShotAi 0xB28779
#define fnSpacePirates_Shot_LowerNorfairPirateVulnerable 0xB287C8
#define fnSpacePirates_Shot_LowerNorfairPirateInvincible 0xB2883E
#define fnWallSpacePirates_Instr_MovePixelsDownAndChangeDirFaceRight 0xB2EE40
#define fnWallSpacePirates_Instr_MovePixelsDownAndChangeDirFaceLeft 0xB2EE72
#define fnWallSpacePirates_Instr_RandomNewDirFaceR 0xB2EEA4
#define fnWallSpacePirates_Instr_RandomNewDirFaceL 0xB2EEBC
#define fnWallSpacePirates_Instr_PrepareWallJumpR 0xB2EED4
#define fnWallSpacePirates_Instr_PrepareWallJumpL 0xB2EEFD
#define fnWallSpacePirates_Instr_FireLaserL 0xB2EF2A
#define fnWallSpacePirates_Instr_FireLaserR 0xB2EF5D
#define fnWallSpacePirates_Instr_SetEnemyFunc 0xB2EF83
#define fnWallSpacePirates_Instr_PlaySpacePirateAttackSfx 0xB2EF93
#define fnWallSpacePirates_Init 0xB2EF9F
#define fnWallSpacePirates_Main 0xB2F02D
#define fnWallSpacePirates_Func_ClimbLWall 0xB2F034
#define fnnullsub_279 0xB2F04F
#define fnWallSpacePirates_Func_WallJumpR 0xB2F050
#define fnWallSpacePirates_Func_ClimbRWall 0xB2F0C8
#define fnnullsub_281 0xB2F0E3
#define fnWallSpacePirates_Func_WallJumpL 0xB2F0E4
#define fnNinjaSpacePirates_Instr_SetPaletteIndex 0xB2F536
#define fnNinjaSpacePirates_Instr_QueueSfx2_Max6 0xB2F546
#define fnNinjaSpacePirates_Instr_SpawnEprojPirateClaw 0xB2F564
#define fnNinjaSpacePirates_Instr_SetAIActive 0xB2F590
#define fnNinjaSpacePirates_Instr_ResetXSpeed 0xB2F5D6
#define fnNinjaSpacePirates_Init 0xB2F5DE
#define fnNinjaSpacePirates_Main 0xB2F6A2
#define fnNinjaSpacePirates_Func_Initial 0xB2F6A9
#define fnNinjaSpacePirates_Func_Active 0xB2F6E4
#define fnNinjaSpacePirates_Func_SpinJumpL_Rise 0xB2F817
#define fnNinjaSpacePirates_Func_SpinJumpL_Fall 0xB2F84C
#define fnNinjaSpacePirates_Func_SpinJumpR_Rise 0xB2F890
#define fnNinjaSpacePirates_Func_SpinJumpR_Fall 0xB2F8C5
#define fnNinjaSpacePirates_Func_DivekickReady 0xB2F909
#define fnNinjaSpacePirates_Instr_InitDivekickLJumpYSpeed 0xB2F969
#define fnNinjaSpacePirates_Func_DivekickL_Jump 0xB2F985
#define fnNinjaSpacePirates_Func_DivekickL_Divekick 0xB2F9C1
#define fnNinjaSpacePirates_Func_DivekickL_WalkToLeftPost 0xB2FA15
#define fnNinjaSpacePirates_Instr_InitDivekickRJumpYSpeed 0xB2FA3D
#define fnNinjaSpacePirates_Func_DivekickR_Jump 0xB2FA59
#define fnNinjaSpacePirates_Func_DivekickR_Divekick 0xB2FA95
#define fnNinjaSpacePirates_Func_DivekickR_WalkToRightPost 0xB2FAE9
#define fnWalkingSpacePirates_Instr_FireLaserLOffsetY 0xB2FC68
#define fnWalkingSpacePirates_Instr_FireLaserROffsetY 0xB2FC90
#define fnWalkingSpacePirates_Instr_SetEnemyFunc 0xB2FCB8
#define fnWalkingSpacePirates_Instr_ChooseDir_FireLaserIfClose 0xB2FCC8
#define fnWalkingSpacePirates_Init 0xB2FD02
#define fnWalkingSpacePirates_Main 0xB2FD32
#define fnWalkingSpacePirates_Func_WalkL 0xB2FD44
#define fnWalkingSpacePirates_Func_WalkR 0xB2FDCE
#define fnnullsub_282 0xB2FE4A
#define fnEnemy_GrappleReact_NoInteract_B3 0xB38000
#define fnEnemy_GrappleReact_KillEnemy_B3 0xB3800A
#define fnEnemy_GrappleReact_CancelBeam_B3 0xB3800F
#define fnEnemy_NormalTouchAI_B3 0xB38023
#define fnEnemy_NormalShotAI_B3 0xB3802D
#define fnEnemy_NormalPowerBombAI_B3 0xB38037
#define fnEnemy_NormalFrozenAI_B3 0xB38041
#define fnnullsub_170_B3 0xB3804C
#define fnEnemy_SetAiPreInstr_B3 0xB3806B
#define fnEnemy_ClearAiPreInstr_B3 0xB38074
#define fnnullsub_171_B3 0xB3807B
#define fnEnemyInstr_Goto_B3 0xB380ED
#define fnEnemyInstr_DecTimerAndGoto2_B3 0xB38110
#define fnEnemyInstr_SetTimer_B3 0xB38123
#define fnEnemyInstr_Sleep_B3 0xB3812F
#define fnUnusedSpinningTurtleEye_Init 0xB386FB
#define fnUnusedSpinningTurtleEye_Main 0xB3870E
#define fnBrinstarPipeBug_Init 0xB3883B
#define fnBrinstarPipeBug_Main 0xB3887A
#define fnBrinstarPipeBug_PreInstr_1 0xB38880
#define fnBrinstarPipeBug_PreInstr_2 0xB38890
#define fnBrinstarPipeBug_PreInstr_3 0xB388E3
#define fnBrinstarPipeBug_PreInstr_4 0xB3891C
#define fnBrinstarPipeBug_PreInstr_5 0xB3897E
#define fnNorfairPipeBug_Init 0xB38B61
#define fnNorfairPipeBug_Main 0xB38B9E
#define fnNorfairPipeBug_Func_1 0xB38BCD
#define fnNorfairPipeBug_Func_2 0xB38BFF
#define fnNorfairPipeBug_Func_4 0xB38CA6
#define fnNorfairPipeBug_Func_5 0xB38CFF
#define fnNorfairPipeBug_Func_6 0xB38D0C
#define fnNorfairPipeBug_Func_7 0xB38D4E
#define fnNorfairPipeBug_Func_8 0xB38D90
#define fnNorfairPipeBug_Func_9 0xB38DD2
#define fnNorfairPipeBug_Func_10 0xB38E14
#define fnNorfairPipeBug_Func_11 0xB38E35
#define fnNorfairPipeBug_Func_12 0xB38E5A
#define fnBrinstarYellowPipeBug_Init 0xB38F4C
#define fnBrinstarYellowPipeBug_Main 0xB38FAE
#define fnBrinstarYellowPipeBug_Func_1 0xB38FB5
#define fnBrinstarYellowPipeBug_Func_2 0xB38FF5
#define fnBrinstarYellowPipeBug_Func_3 0xB39028
#define fnBrinstarYellowPipeBug_Func_5 0xB390BD
#define fnBrinstarYellowPipeBug_Func_7 0xB3915A
#define fnBrinstarYellowPipeBug_Func_8 0xB391D8
#define fnBotwoon_Instr_1 0xB394C7
#define fnBotwoon_Instr_2 0xB394D7
#define fnBotwoon_Instr_3 0xB394E7
#define fnBotwoon_Instr_4 0xB394F7
#define fnBotwoon_Instr_5 0xB39507
#define fnBotwoon_Instr_6 0xB39517
#define fnBotwoon_Instr_7 0xB39527
#define fnBotwoon_Instr_8 0xB39537
#define fnBotwoon_Instr_9 0xB39547
#define fnBotwoon_Instr_10 0xB39557
#define fnBotwoon_Instr_SetSpitting 0xB39567
#define fnBotwoon_Instr_QueueSpitSfx 0xB39572
#define fnnullsub_30 0xB3957A
#define fnBotwoon_Init 0xB39583
#define fnBotwoon_Main 0xB39668
#define fnBotwoon_Func_1 0xB3967B
#define fnBotwoon_Func_2 0xB39696
#define fnBotwoon_Func_3 0xB396C6
#define fnBotwoon_Func_Initialize 0xB39878
#define fnBotwoon_Func_GoInHole 0xB3989D
#define fnBotwoon_Func_MoveAround 0xB399A4
#define fnBotwoon_Func_Spit 0xB399E4
#define fnBotwoon_Func_PreDeathDelay 0xB39A46
#define fnBotwoon_Func_FallToGround 0xB39A5E
#define fnBotwoon_Func_WaitForBodyToFall 0xB39ACA
#define fnBotwoon_Func_CrumbleWall 0xB39AF9
#define fnBotwoon_Func_MoveToTargetHole 0xB39BB7
#define fnBotwoon_Func_MoveHeadAround 0xB39DC0
#define fnBotwoon_Func_SetSpitAngle 0xB39E7D
#define fnBotwoon_Func_SpawnFiveSpitProjectiles 0xB39EE0
#define fnBotwoon_Func_SpawnThreeSpitProjectiles 0xB39F34
#define fnBotwoon_Func_CooldownSpit 0xB39F7A
#define fnBotwoon_Touch 0xB39FFF
#define fnBotwoon_Shot 0xB3A016
#define fnBotwoon_Powerbomb 0xB3A041
#define fnBotwoon_Func_StartMovementUsingData 0xB3E250
#define fnBotwoon_Func_MoveUsingData 0xB3E28C
#define fnEscapeEtecoon_Instr_1 0xB3E545
#define fnEscapeEtecoon_Instr_2 0xB3E610
#define fnEscapeEtecoon_Main 0xB3E655
#define fnEscapeEtecoon_E65C 0xB3E65C
#define fnEscapeEtecoon_E670 0xB3E670
#define fnEscapeEtecoon_E680 0xB3E680
#define fnEscapeEtecoon_Init 0xB3E6CB
#define fnEscapeDachora_Instr_2 0xB3EAA8
#define fnEscapeDachora_Instr_3 0xB3EAB8
#define fnEscapeDachora_Instr_1 0xB3EAC9
#define fnEscapeDachora_Instr_4 0xB3EAD7
#define fnEscapeDachora_Init 0xB3EAE5
#define fnnullsub_54 0xB3EB1A
#define fnSpriteObject_Instr_RepeatLast 0xB4BCF0
#define fnSpriteObject_Instr_Terminate 0xB4BD07
#define fnSpriteObject_Instr_Goto 0xB4BD12
#define fnlocret_828C81 0x828C81
#define fnlocret_8B9585 0x8B9585
#define FUNC16(x) ((fn##x) & 0xffff)
#define IS_FUNC(x) ((x) & 0x8000)