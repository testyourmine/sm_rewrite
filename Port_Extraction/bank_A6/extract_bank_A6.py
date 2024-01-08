import sys
import os
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import common_data as rom

kCeresRidley_Tab0 = []
kCeresRidley_Tab0 = []
kCeresRidley_PaletteTab0 = []
kCeresRidley_PaletteTab1 = []
kCeresRidley_PalettePtrs0 = []
kCeresRidley_FuncPtrs0 = []
kCeresRidley_Tab1 = []
kCeresRidley_GetawayYVelocityIndices = []
kCeresRidley_GetawayXVelocityIndices = []
kCeresRidley_Mode7TransferPtrs0 = []
kCeresRidley_Mode7TransferPtrs1 = []
kRidley_FlyToXPositionTab0 = []
kRidley_FlyToXPositionTab1 = []
kRidley_FlyToXPositionTab2 = []
kRidley_HoldingSamusXPositionTab0 = []
kRidley_HoldingSamusYPositionTab0 = []
kRidley_Ptrs0 = []
kRidley_Ptrs1 = []
kRidley_Tab0 = []
kRidley_Tab1 = []
kRidley_Tab2 = []
kRidley_Tab3 = []
kRidley_Bg1AndBg2Palette6 = []
kRidley_InstrListPtrs0 = []
kRidley_XPositionIndices0 = []
kRidley_InstrListPtrs1 = []
kRidley_XPositionIndices1 = []
kRidley_InstrListPtrs2 = []
kRidley_XPositionIndices2 = []
kRidley_InstrListPtrs3 = []
kRidley_XPositionIndices3 = []
kRidley_InstrListPtrs4 = []
kRidley_XPositionIndices4 = []
kRidley_InstrListPtrs5 = []
kRidleysExplosion_Tab0 = []
kRidley_MinTailAngleIndices0 = []
kRidley_MaxTailAngleIndices0 = []
kRidley_TilemapPtrs0 = []
kRidley_SpritemapPtrs0 = []
kEnemyInit_CeresSteam_InstrListPtrs = []
kEnemyInit_CeresSteam_FuncPtrs = []
kEnemyInit_CeresDoors_FuncPtrs = []
kEnemyInit_CeresDoors_InstrListPtrs = []
kCeresDoor_RandomXYPositionIndices = []
kCeresDoor_Mode7TransferPtrs = []
kEnemyInit_Zebetites_DestroyedIndices = []
kEnemyInit_Zebetites_HeightIndices = []
kEnemyInit_Zebetites_InstrListPtrs = []
kEnemyInit_Zebetites_XPositionIndices = []
kEnemyInit_Zebetites_YPositionIndices0 = []
kEnemyInit_Zebetites_YPositionIndices1 = []
kZebetites_BigZebetiteInstrListPtrs = []
kZebetites_SmallZebetitePairInstrListPtrs = []


#Format is as follows: 
#rom.get_data(bank, starting address, ending address, "data type", array, "array name", hex bool, array bool, new line, new space)
#"hex bool" is whether you want the data in hexadecimal or in decimal format
#"array bool" is whether it's a single value or an array (will print [] if array, won't otherwise)
#"new line/space" is how many elements you want before you insert a new line/space, -1 is never
def get_A6():
    rom.get_data(0xA6, 0xE269, 0xE2AA, "uint8", kCeresRidley_Tab0, "kCeresRidley_Tab0", False, True, 16, 1)
    rom.get_data(0xA6, 0xE2AA, 0xE30A, "uint16", kCeresRidley_PaletteTab0, "kCeresRidley_PaletteTab0", True, True, 3, 1)
    rom.get_data(0xA6, 0xE30A, 0xE46A, "uint16", kCeresRidley_PaletteTab1, "kCeresRidley_PaletteTab1", True, True, 11, 1)
    rom.get_data(0xA6, 0xA4EB, 0xA50B, "uint16", kCeresRidley_PalettePtrs0, "kCeresRidley_PalettePtrs0", True, True, -1, 1)
    rom.get_data(0xA6, 0xA743, 0xA763, "uint16", kCeresRidley_FuncPtrs0, "kCeresRidley_FuncPtrs0", True, True, -1, 1)
    rom.get_data(0xA6, 0xAE4D, 0xAF2F, "uint16", kCeresRidley_Tab1, "kCeresRidley_Tab1", True, True, 16, 1)
    rom.get_data(0xA6, 0xAF2F, 0xB00F, "uint16", kCeresRidley_GetawayYVelocityIndices, "kCeresRidley_GetawayYVelocityIndices", True, True, 16, 1)
    rom.get_data(0xA6, 0xB00F, 0xB0EF, "uint16", kCeresRidley_GetawayXVelocityIndices, "kCeresRidley_GetawayXVelocityIndices", True, True, 16, 1)
    rom.get_data(0xA6, 0xACDA, 0xACE2, "uint16", kCeresRidley_Mode7TransferPtrs0, "kCeresRidley_Mode7TransferPtrs0", True, True, -1, 1)
    rom.get_data(0xA6, 0xAD45, 0xAD49, "uint16", kCeresRidley_Mode7TransferPtrs1, "kCeresRidley_Mode7TransferPtrs1", True, True, -1, 1)
    rom.get_data(0xA6, 0xB60D, 0xB613, "uint16", kRidley_FlyToXPositionTab0, "kRidley_FlyToXPositionTab0", True, True, -1, 1)
    rom.get_data(0xA6, 0xB63B, 0xB641, "uint16", kRidley_FlyToXPositionTab1, "kRidley_FlyToXPositionTab1", True, True, -1, 1)
    rom.get_data(0xA6, 0xB6C8, 0xB6CE, "uint16", kRidley_FlyToXPositionTab2, "kRidley_FlyToXPositionTab2", True, True, -1, 1)
    rom.get_data(0xA6, 0xB9D5, 0xB9DB, "uint16", kRidley_HoldingSamusXPositionTab0, "kRidley_HoldingSamusXPositionTab0", True, True, -1, 1)
    rom.get_data(0xA6, 0xB9DB, 0xB9E1, "uint16", kRidley_HoldingSamusYPositionTab0, "kRidley_HoldingSamusYPositionTab0", True, True, -1, 1)
    rom.get_data(0xA6, 0xB965, 0xB96D, "uint16", kRidley_Ptrs0, "kRidley_Ptrs0", True, True, -1, 1)
    rom.get_data(0xA6, 0xB96D, 0xB975, "uint16", kRidley_Ptrs1, "kRidley_Ptrs1", True, True, -1, 1)
    rom.get_data(0xA6, 0xB94D, 0xB959, "uint16", kRidley_Tab0, "kRidley_Tab0", False, True, -1, 1)
    rom.get_data(0xA6, 0xB959, 0xB965, "uint16", kRidley_Tab1, "kRidley_Tab1", False, True, -1, 1)
    rom.get_data(0xA6, 0xBB48, 0xBB4E, "uint16", kRidley_Tab2, "kRidley_Tab2", True, True, -1, 1)
    rom.get_data(0xA6, 0xBB4E, 0xBB56, "uint16", kRidley_Tab3, "kRidley_Tab3", False, True, -1, 1)
    rom.get_data(0xA6, 0xC1DF, 0xC23F, "uint16", kRidley_Bg1AndBg2Palette6, "kRidley_Bg1AndBg2Palette6", True, True, 3, 1)
    rom.get_data(0xA6, 0xC7BA, 0xC7DA, "uint16", kRidley_InstrListPtrs0, "kRidley_InstrListPtrs0", True, True, -1, 1)
    rom.get_data(0xA6, 0xC804, 0xC808, "uint16", kRidley_XPositionIndices0, "kRidley_XPositionIndices0", False, True, -1, 1)
    rom.get_data(0xA6, 0xC808, 0xC80C, "uint16", kRidley_InstrListPtrs1, "kRidley_InstrListPtrs1", True, True, -1, 1)
    rom.get_data(0xA6, 0xC836, 0xC83A, "uint16", kRidley_XPositionIndices1, "kRidley_XPositionIndices1", True, True, -1, 1)
    rom.get_data(0xA6, 0xC83A, 0xC83E, "uint16", kRidley_InstrListPtrs2, "kRidley_InstrListPtrs2", True, True, -1, 1)
    rom.get_data(0xA6, 0xC868, 0xC86C, "uint16", kRidley_XPositionIndices2, "kRidley_XPositionIndices2", True, True, -1, 1)
    rom.get_data(0xA6, 0xC86C, 0xC870, "uint16", kRidley_InstrListPtrs3, "kRidley_InstrListPtrs3", True, True, -1, 1)
    rom.get_data(0xA6, 0xC89A, 0xC89E, "uint16", kRidley_XPositionIndices3, "kRidley_XPositionIndices3", True, True, -1, 1)
    rom.get_data(0xA6, 0xC89E, 0xC8A2, "uint16", kRidley_InstrListPtrs4, "kRidley_InstrListPtrs4", True, True, -1, 1)
    rom.get_data(0xA6, 0xC8CC, 0xC8D0, "uint16", kRidley_XPositionIndices4, "kRidley_XPositionIndices4", True, True, -1, 1)
    rom.get_data(0xA6, 0xC8D0, 0xC8D4, "uint16", kRidley_InstrListPtrs5, "kRidley_InstrListPtrs5", True, True, -1, 1)
    rom.get_data(0xA6, 0xC6CE, 0xC6E6, "uint16", kRidleysExplosion_Tab0, "kRidleysExplosion_Tab0", False, True, -1, 1)
    rom.get_data(0xA6, 0xCC12, 0xCC18, "uint16", kRidley_MinTailAngleIndices0, "kRidley_MinTailAngleIndices0", True, True, -1, 1)
    rom.get_data(0xA6, 0xCC18, 0xCC1E, "uint16", kRidley_MaxTailAngleIndices0, "kRidley_MaxTailAngleIndices0", True, True, -1, 1)
    rom.get_data(0xA6, 0xDB02, 0xDB2A, "uint16", kRidley_TilemapPtrs0, "kRidley_TilemapPtrs0", True, True, 10, 1)
    rom.get_data(0xA6, 0xDCBA, 0xDCDA, "uint16", kRidley_SpritemapPtrs0, "kRidley_SpritemapPtrs0", True, True, -1, 1)
    rom.get_data(0xA6, 0xEFF5, 0xF001, "uint16", kEnemyInit_CeresSteam_InstrListPtrs, "kEnemyInit_CeresSteam_InstrListPtrs", True, True, -1, 1)
    rom.get_data(0xA6, 0xF001, 0xF00D, "uint16", kEnemyInit_CeresSteam_FuncPtrs, "kEnemyInit_CeresSteam_FuncPtrs", True, True, -1, 1)
    rom.get_data(0xA6, 0xF72B, 0xF739, "uint16", kEnemyInit_CeresDoors_FuncPtrs, "kEnemyInit_CeresDoors_FuncPtrs", True, True, -1, 1)
    rom.get_data(0xA6, 0xF52C, 0xF53A, "uint16", kEnemyInit_CeresDoors_InstrListPtrs, "kEnemyInit_CeresDoors_InstrListPtrs", True, True, -1, 1)
    rom.get_data(0xA6, 0xF840, 0xF850, "uint16", kCeresDoor_RandomXYPositionIndices, "kCeresDoor_RandomXYPositionIndices", True, True, -1, 2)
    rom.get_data(0xA6, 0xF900, 0xF904, "uint16", kCeresDoor_Mode7TransferPtrs, "kCeresDoor_Mode7TransferPtrs", True, True, -1, 1)
    rom.get_data(0xA6, 0xFC03, 0xFC0B, "uint16", kEnemyInit_Zebetites_DestroyedIndices, "kEnemyInit_Zebetites_DestroyedIndices", True, True, -1, 1)
    rom.get_data(0xA6, 0xFC0B, 0xFC13, "uint16", kEnemyInit_Zebetites_HeightIndices, "kEnemyInit_Zebetites_HeightIndices", False, True, -1, 1)
    rom.get_data(0xA6, 0xFC13, 0xFC1B, "uint16", kEnemyInit_Zebetites_InstrListPtrs, "kEnemyInit_Zebetites_InstrListPtrs", True, True, -1, 1)
    rom.get_data(0xA6, 0xFC1B, 0xFC23, "uint16", kEnemyInit_Zebetites_XPositionIndices, "kEnemyInit_Zebetites_XPositionIndices", False, True, -1, 1)
    rom.get_data(0xA6, 0xFC23, 0xFC2B, "uint16", kEnemyInit_Zebetites_YPositionIndices0, "kEnemyInit_Zebetites_YPositionIndices0", False, True, -1, 1)
    rom.get_data(0xA6, 0xFC2B, 0xFC33, "uint16", kEnemyInit_Zebetites_YPositionIndices1, "kEnemyInit_Zebetites_YPositionIndices1", False, True, -1, 1)
    rom.get_data(0xA6, 0xFD4A, 0xFD54, "uint16", kZebetites_BigZebetiteInstrListPtrs, "kZebetites_BigZebetiteInstrListPtrs", True, True, -1, 1)
    rom.get_data(0xA6, 0xFD54, 0xFD5E, "uint16", kZebetites_SmallZebetitePairInstrListPtrs, "kZebetites_SmallZebetitePairInstrListPtrs", True, True, -1, 1)
    return

get_A6()