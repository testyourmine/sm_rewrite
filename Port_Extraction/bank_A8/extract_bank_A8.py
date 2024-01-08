import sys
import os
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import common_data as rom

kEnemyInit_MorphBallEye_InstrListPtrs = []
kYappingMaw_Constants = []
kYappingMaw_Constant0 = []
kYappingMaw_Constant1 = []
kYappingMaw_Constant2 = []
kYappingMaw_Constant3 = []
kYappingMaw_Constant4 = []
kYappingMaw_Constant5 = []
kYappingMaw_Constant6 = []
kYappingMaw_Constant7 = []
kYappingMaw_Constant8 = []
kYappingMaw_Constant9 = []
kYappingMaw_Constant10 = []
kYappingMaw_Constant11 = []
kYappingMaw_InstrListPtrs = []
kNorfairLavaMan_Palette = []
kNorfairLavaMan_Tab2 = []
kNorfairLavaMan_Tab0 = []
kNorfairLavaMan_Tab1 = []
kBeetom_SamusNotInProximityFuncPtrs = []
kMaridiaFloater_InstrListPtrs = []
kEnemyInit_WreckedShipRobotDeactivated_InstrListPtrs = []
kEnemyInit_WreckedShipOrbs_InstrListPtrs = []
kEnemyInit_WreckedShipSpark_InstrListPtrs = []
kEnemyInit_WreckedShipSpark_FuncPtrs = []
kBlueBrinstarFaceBlock_GlowPalette = []
kKiHunter_InstrListPtrs = []

#Format is as follows: 
#rom.get_data(bank, starting address, ending address, "data type", array, "array name", hex bool, array bool, new line, new space)
#"hex bool" is whether you want the data in hexadecimal or in decimal format
#"array bool" is whether it's a single value or an array (will print [] if array, won't otherwise)
#"new line/space" is how many elements you want before you insert a new line/space, -1 is never
def get_A8():
    rom.get_data(0xA8, 0x90DA, 0x90E2, "uint16", kEnemyInit_MorphBallEye_InstrListPtrs, "kEnemyInit_MorphBallEye_InstrListPtrs", True, True, -1, 1)
    rom.get_data(0xA8, 0xA0A7, 0xA0C7, "uint16", kYappingMaw_Constants, "kYappingMaw_Constants", True, True, -1, 1)
    rom.get_data(0xA8, 0xA0A7, 0xA0A9, "uint16", kYappingMaw_Constant0, "kYappingMaw_Constant0", True, False, -1, 1)
    rom.get_data(0xA8, 0xA0A9, 0xA0AB, "uint16", kYappingMaw_Constant1, "kYappingMaw_Constant1", True, False, -1, 1)
    rom.get_data(0xA8, 0xA0AB, 0xA0AD, "uint16", kYappingMaw_Constant2, "kYappingMaw_Constant2", True, False, -1, 1)
    rom.get_data(0xA8, 0xA0AD, 0xA0AF, "uint16", kYappingMaw_Constant3, "kYappingMaw_Constant3", True, False, -1, 1)
    rom.get_data(0xA8, 0xA0B3, 0xA0B5, "uint16", kYappingMaw_Constant4, "kYappingMaw_Constant4", True, False, -1, 1)
    rom.get_data(0xA8, 0xA0B5, 0xA0B7, "uint16", kYappingMaw_Constant5, "kYappingMaw_Constant5", True, False, -1, 1)
    rom.get_data(0xA8, 0xA0B7, 0xA0B9, "uint16", kYappingMaw_Constant6, "kYappingMaw_Constant6", True, False, -1, 1)
    rom.get_data(0xA8, 0xA0B9, 0xA0BB, "uint16", kYappingMaw_Constant7, "kYappingMaw_Constant7", True, False, -1, 1)
    rom.get_data(0xA8, 0xA0BB, 0xA0BD, "uint16", kYappingMaw_Constant8, "kYappingMaw_Constant8", True, False, -1, 1)
    rom.get_data(0xA8, 0xA0BD, 0xA0BF, "uint16", kYappingMaw_Constant9, "kYappingMaw_Constant9", True, False, -1, 1)
    rom.get_data(0xA8, 0xA0C3, 0xA0C5, "uint16", kYappingMaw_Constant10, "kYappingMaw_Constant10", True, False, -1, 1)
    rom.get_data(0xA8, 0xA0C5, 0xA0C7, "uint16", kYappingMaw_Constant11, "kYappingMaw_Constant11", True, False, -1, 1)
    rom.get_data(0xA8, 0xA097, 0xA0A7, "uint16", kYappingMaw_InstrListPtrs, "kYappingMaw_InstrListPtrs", True, True, -1, 1)
    rom.get_data(0xA8, 0xAC1C, 0xAC9C, "uint16", kNorfairLavaMan_Palette, "kNorfairLavaMan_Palette", True, True, 16, 1)
    rom.get_data(0xA8, 0xAF79, 0xAF8B, "uint16", kNorfairLavaMan_Tab2, "kNorfairLavaMan_Tab2", False, True, -1, 1)
    rom.get_data(0xA8, 0xAF55, 0xAF67, "uint16", kNorfairLavaMan_Tab0, "kNorfairLavaMan_Tab0", False, True, -1, 1)
    rom.get_data(0xA8, 0xAF67, 0xAF79, "uint16", kNorfairLavaMan_Tab1, "kNorfairLavaMan_Tab1", True, True, -1, 1)
    rom.get_data(0xA8, 0xB74E, 0xB75E, "uint16", kBeetom_SamusNotInProximityFuncPtrs, "kBeetom_SamusNotInProximityFuncPtrs", True, True, 2, 1)
    rom.get_data(0xA8, 0xC599, 0xC59F, "uint16", kMaridiaFloater_InstrListPtrs, "kMaridiaFloater_InstrListPtrs", True, True, -1, 1)
    rom.get_data(0xA8, 0xCC30, 0xCC36, "uint16", kEnemyInit_WreckedShipRobotDeactivated_InstrListPtrs, "kEnemyInit_WreckedShipRobotDeactivated_InstrListPtrs", True, True, -1, 1)
    rom.get_data(0xA8, 0xE380, 0xE388, "uint16", kEnemyInit_WreckedShipOrbs_InstrListPtrs, "kEnemyInit_WreckedShipOrbs_InstrListPtrs", True, True, -1, 1)
    rom.get_data(0xA8, 0xE682, 0xE688, "uint16", kEnemyInit_WreckedShipSpark_InstrListPtrs, "kEnemyInit_WreckedShipSpark_InstrListPtrs", True, True, -1, 1)
    rom.get_data(0xA8, 0xE688, 0xE68E, "uint16", kEnemyInit_WreckedShipSpark_FuncPtrs, "kEnemyInit_WreckedShipSpark_FuncPtrs", True, True, -1, 1)
    rom.get_data(0xA8, 0xE7CC, 0xE80C, "uint16", kBlueBrinstarFaceBlock_GlowPalette, "kBlueBrinstarFaceBlock_GlowPalette", True, True, 4, 1)
    rom.get_data(0xA8, 0xF3B0, 0xF3B8, "uint16", kKiHunter_InstrListPtrs, "kKiHunter_InstrListPtrs", True, True, -1, 2)
    return

get_A8()