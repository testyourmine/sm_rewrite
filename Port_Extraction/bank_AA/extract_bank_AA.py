import sys
import os
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import common_data as rom

kEnemyInit_Torizo_InstrListPtrs = []
kEnemyInit_TourianEntranceStatue_InstrListPtrs = []
kEnemyInit_TourianEntranceStatue_PaletteTab0 = []
kEnemyInit_TourianEntranceStatue_PaletteTab1 = []
kShaktool_InstrListPtrs0 = []
kShaktool_InstrListPtrs1 = []
kSine = []
kCosine = []
kNegativeSine = []
kNegativeCosine_0 = []
kNegativeCosine = []
kShaktool_InstrListPtrs2 = []
kEnemyInit_Shaktool_PropertiesIndices = []
kEnemyInit_Shaktool_RamOffsetIndices = []
kEnemyInit_Shaktool_InitialAnglesIndices = []
kEnemyInit_Shaktool_FuncPtrs = []
kEnemyInit_Shaktool_ZeroIndices = []
kEnemyInit_Shaktool_LayerControlIndices = []
kShaktool_XDirectionIndices = []
kShaktool_SamusXPositionIndices = []
kShaktool_SamusYPositionIndices = []
kN00bTubeCracks_Palette2 = []
kEnemyInit_ChozoStatue_InstrListPtrs = []

#Format is as follows: 
#rom.get_data(bank, starting address, ending address, "data type", array, "array name", hex bool, array bool, new line, new space)
#"hex bool" is whether you want the data in hexadecimal or in decimal format
#"array bool" is whether it's a single value or an array (will print [] if array, won't otherwise)
#"new line/space" is how many elements you want before you insert a new line/space, -1 is never
def get_AA():
    rom.get_data(0xAA, 0xC967, 0xC96B, "uint16", kEnemyInit_Torizo_InstrListPtrs, "kEnemyInit_Torizo_InstrListPtrs", True, True, -1, 1)
    rom.get_data(0xAA, 0xD810, 0xD816, "uint16", kEnemyInit_TourianEntranceStatue_InstrListPtrs, "kEnemyInit_TourianEntranceStatue_InstrListPtrs", True, True, -1, 1)
    rom.get_data(0xAA, 0xD765, 0xD785, "uint16", kEnemyInit_TourianEntranceStatue_PaletteTab0, "kEnemyInit_TourianEntranceStatue_PaletteTab0", True, True, -1, 1)
    rom.get_data(0xAA, 0xD785, 0xD7A5, "uint16", kEnemyInit_TourianEntranceStatue_PaletteTab1, "kEnemyInit_TourianEntranceStatue_PaletteTab1", True, True, -1, 1)
    rom.get_data(0xAA, 0xDF13, 0xDF21, "uint16", kShaktool_InstrListPtrs0, "kShaktool_InstrListPtrs0", True, True, -1, 1)
    rom.get_data(0xAA, 0xDF21, 0xDF2F, "uint16", kShaktool_InstrListPtrs1, "kShaktool_InstrListPtrs1", True, True, -1, 1)
    rom.get_data(0xAA, 0xE0BD, 0xE13D, "uint16", kSine, "kSine", True, True, 16, 1)
    rom.get_data(0xAA, 0xE13D, 0xE1BD, "uint16", kCosine, "kCosine", True, True, 16, 1)
    rom.get_data(0xAA, 0xE1BD, 0xE23D, "uint16", kNegativeSine, "kNegativeSine", True, True, 16, 1)
    rom.get_data(0xAA, 0xE23D, 0xE2BD, "uint16", kNegativeCosine_0, "kNegativeCosine_0", True, True, 16, 1)
    rom.get_data(0xAA, 0xE03D, 0xE0BD, "uint16", kNegativeCosine, "kNegativeCosine", True, True, 16, 1)
    rom.get_data(0xAA, 0xDD15, 0xDD25, "uint16", kShaktool_InstrListPtrs2, "kShaktool_InstrListPtrs2", True, True, -1, 1)
    rom.get_data(0xAA, 0xDE95, 0xDEA3, "uint16", kEnemyInit_Shaktool_PropertiesIndices, "kEnemyInit_Shaktool_PropertiesIndices", True, True, -1, 1)
    rom.get_data(0xAA, 0xDEA3, 0xDEB1, "uint16", kEnemyInit_Shaktool_RamOffsetIndices, "kEnemyInit_Shaktool_RamOffsetIndices", True, True, -1, 1)
    rom.get_data(0xAA, 0xDEB1, 0xDEBF, "uint16", kEnemyInit_Shaktool_InitialAnglesIndices, "kEnemyInit_Shaktool_InitialAnglesIndices", True, True, -1, 1)
    rom.get_data(0xAA, 0xDEDB, 0xDEE9, "uint16", kEnemyInit_Shaktool_FuncPtrs, "kEnemyInit_Shaktool_FuncPtrs", True, True, -1, 1)
    rom.get_data(0xAA, 0xDEF7, 0xDF05, "uint16", kEnemyInit_Shaktool_ZeroIndices, "kEnemyInit_Shaktool_ZeroIndices", False, True, -1, 1)
    rom.get_data(0xAA, 0xDECD, 0xDEDB, "uint16", kEnemyInit_Shaktool_LayerControlIndices, "kEnemyInit_Shaktool_LayerControlIndices", False, True, -1, 1)
    rom.get_data(0xAA, 0xE630, 0xE670, "uint16", kShaktool_XDirectionIndices, "kShaktool_XDirectionIndices", True, True, 16, 1)
    rom.get_data(0xAA, 0xE670, 0xE6B0, "uint16", kShaktool_SamusXPositionIndices, "kShaktool_SamusXPositionIndices", True, True, 16, 1)
    rom.get_data(0xAA, 0xE6B0, 0xE6F0, "uint16", kShaktool_SamusYPositionIndices, "kShaktool_SamusYPositionIndices", True, True, 16, 1)
    rom.get_data(0xAA, 0xE2DD, 0xE31D, "uint16", kN00bTubeCracks_Palette2, "kN00bTubeCracks_Palette2", True, True, -1, 1)
    rom.get_data(0xAA, 0xE7A2, 0xE7A6, "uint16", kEnemyInit_ChozoStatue_InstrListPtrs, "kEnemyInit_ChozoStatue_InstrListPtrs", True, True, -1, 1)
    return

get_AA()