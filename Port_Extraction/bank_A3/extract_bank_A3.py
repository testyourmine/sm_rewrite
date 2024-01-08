import sys
import os
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import common_data as rom

kWaver_InstrListPtrs = []
kMetalee_InstrListPtrs = []
kFireFlea_Tab0 = []
kElevator_ControllerInputs = []
kEnemyInit_Crab_InstrListPtrs = []
kEnemyInit_Slug_InstrListPtrs = []
kRoach_InstrListPtrs = []
kRoach_FuncPtrs = []
kSidehopper_InstrListPtrs0 = []
kSidehopper_InstrListPtrs1 = []
kSidehopper_InstrListPtrs2 = []
kSidehopper_InstrListPtrs3 = []
kSidehopper_FuncPtrs = []
kSidehopper_Tab0 = []
kSidehopper_Tab1 = []
kSidehopper_Tab2 = []
kSidehopper_Tab3 = []
kSidehopper_Tab4 = []
kSidehopper_Tab5 = []
kMaridiaRefillCandy_XPositionIndices = []
kMaridiaRefillCandy_InstrListPtrs = []
kEnemyInit_NorfairSlowFireball_InstrListPtrs = []
kEnemyInit_Bang_Tab0 = []
kBang_ShotDirectionIndices = []
kBang_ShotSoundIndices = []
kEnemyInit_Bang_Tab1 = []
kBang_InstrListPtrs = []
kSkree_InstrListPtrs = []
kMaridiaSnail_Tab0 = []
kMaridiaSnail_Tab1 = []
kMaridiaSnail_Tab2 = []
kMaridiaSnail_Tab3 = []
kMaridiaSnail_FuncPtrs = []
kMaridiaSnail_InstrListPtrs0 = []
kMaridiaSnail_InstrListPtrs1 = []
kMaridiaSnail_InstrListPtrs2 = []
kMaridiaSnail_Tab4 = []
kMaridiaSnail_InstrListPtrs3 = []
kReflec_GlowColorsIndices = []
kReflec_InstrListPtrs0 = []
kReflec_ShootDirectionsIndices = []
kReflec_InstrListPtrs1 = []
kEnemyInit_WreckedShipOrangeZoomer_InstrListPtrs = []
kCommonZoomer_SpeedIndices = []
kCommonZoomer_InstrListPtrs0 = []
kCommonZoomer_InstrListPtrs1 = []
kCommonZoomer_InstrListPtrs2 = []
kCommonZoomer_InstrListPtrs3 = []
kCommonZoomer_InstrListPtrs4 = []
kCommonZoomer_Tab0 = []
kMetroid_CrySoundsIndices = []
kMetroid_SpeedIndices = []

#Format is as follows: 
#rom.get_data(bank, starting address, ending address, "data type", array, "array name", hex bool, array bool, new line, new space)
#"hex bool" is whether you want the data in hexadecimal or in decimal format
#"array bool" is whether it's a single value or an array (will print [] if array, won't otherwise)
#"new line/space" is how many elements you want before you insert a new line/space, -1 is never
def get_A3():
    rom.get_data(0xA3, 0x86DB, 0x86E3, "uint16", kWaver_InstrListPtrs, "kWaver_InstrListPtrs", True, True, -1, 1)
    rom.get_data(0xA3, 0x894E, 0x8956, "uint16", kMetalee_InstrListPtrs, "kMetalee_InstrListPtrs", True, True, -1, 1)
    rom.get_data(0xA3, 0x8D1D, 0x8D2D, "uint16", kFireFlea_Tab0, "kFireFlea_Tab0", False, True, -1, 1)
    rom.get_data(0xA3, 0x94E2, 0x94E6, "uint16", kElevator_ControllerInputs, "kElevator_ControllerInputs", True, True, -1, 1)
    rom.get_data(0xA3, 0x96DB, 0x96E3, "uint16", kEnemyInit_Crab_InstrListPtrs, "kEnemyInit_Crab_InstrListPtrs", True, True, -1, 1)
    rom.get_data(0xA3, 0x992B, 0x993B, "uint16", kEnemyInit_Slug_InstrListPtrs, "kEnemyInit_Slug_InstrListPtrs", True, True, -1, 1)
    rom.get_data(0xA3, 0xA111, 0xA121, "uint16", kRoach_InstrListPtrs, "kRoach_InstrListPtrs", True, True, -1, 1)
    rom.get_data(0xA3, 0xA121, 0xA12F, "uint16", kRoach_FuncPtrs, "kRoach_FuncPtrs", True, True, -1, 1)
    rom.get_data(0xA3, 0xAAC2, 0xAACA, "uint16", kSidehopper_InstrListPtrs0, "kSidehopper_InstrListPtrs0", True, True, -1, 1)
    rom.get_data(0xA3, 0xAACA, 0xAAD2, "uint16", kSidehopper_InstrListPtrs1, "kSidehopper_InstrListPtrs1", True, True, -1, 1)
    rom.get_data(0xA3, 0xAAD2, 0xAADA, "uint16", kSidehopper_InstrListPtrs2, "kSidehopper_InstrListPtrs2", True, True, -1, 1)
    rom.get_data(0xA3, 0xAADA, 0xAAE2, "uint16", kSidehopper_InstrListPtrs3, "kSidehopper_InstrListPtrs3", True, True, -1, 1)
    rom.get_data(0xA3, 0xAAE2, 0xAAE6, "uint16", kSidehopper_FuncPtrs, "kSidehopper_FuncPtrs", True, True, -1, 1)
    rom.get_data(0xA3, 0xAAE6, 0xAAEA, "uint16", kSidehopper_Tab0, "kSidehopper_Tab0", False, True, -1, 1)
    rom.get_data(0xA3, 0xAAEA, 0xAAEE, "uint16", kSidehopper_Tab1, "kSidehopper_Tab1", False, True, -1, 1)
    rom.get_data(0xA3, 0xAAEE, 0xAAF2, "uint16", kSidehopper_Tab2, "kSidehopper_Tab2", True, True, -1, 1)
    rom.get_data(0xA3, 0xAAF2, 0xAAF6, "uint16", kSidehopper_Tab3, "kSidehopper_Tab3", False, True, -1, 1)
    rom.get_data(0xA3, 0xAAF6, 0xAAFA, "uint16", kSidehopper_Tab4, "kSidehopper_Tab4", False, True, -1, 1)
    rom.get_data(0xA3, 0xAAFA, 0xAAFE, "uint16", kSidehopper_Tab5, "kSidehopper_Tab5", True, True, -1, 1)
    rom.get_data(0xA3, 0xB415, 0xB429, "uint16", kMaridiaRefillCandy_XPositionIndices, "kMaridiaRefillCandy_XPositionIndices", True, True, -1, 2)
    rom.get_data(0xA3, 0xB40D, 0xB415, "uint16", kMaridiaRefillCandy_InstrListPtrs, "kMaridiaRefillCandy_InstrListPtrs", True, True, -1, 1)
    rom.get_data(0xA3, 0xB667, 0xB66F, "uint16", kEnemyInit_NorfairSlowFireball_InstrListPtrs, "kEnemyInit_NorfairSlowFireball_InstrListPtrs", True, True, -1, 1)
    rom.get_data(0xA3, 0xBA84, 0xBA94, "uint16", kEnemyInit_Bang_Tab0, "kEnemyInit_Bang_Tab0", True, True, -1, 1)
    rom.get_data(0xA3, 0xBA94, 0xBAA8, "uint16", kBang_ShotDirectionIndices, "kBang_ShotDirectionIndices", True, True, -1, 1)
    rom.get_data(0xA3, 0xBC4A, 0xBC6A, "uint16", kBang_ShotSoundIndices, "kBang_ShotSoundIndices", False, True, -1, 1)
    rom.get_data(0xA3, 0xBC6A, 0xBC9E, "uint16", kEnemyInit_Bang_Tab1, "kEnemyInit_Bang_Tab1", False, True, 13, 1)
    rom.get_data(0xA3, 0xB722, 0xB75E, "uint16", kBang_InstrListPtrs, "kBang_InstrListPtrs", True, True, 5, 1)
    rom.get_data(0xA3, 0xC69C, 0xC6A4, "uint16", kSkree_InstrListPtrs, "kSkree_InstrListPtrs", True, True, -1, 1)
    rom.get_data(0xA3, 0xCD42, 0xCD82, "MaridiaSnailData2", kMaridiaSnail_Tab0, "kMaridiaSnail_Tab0", True, True, 1, 1)
    rom.get_data(0xA3, 0xCD82, 0xCDC2, "uint16", kMaridiaSnail_Tab1, "kMaridiaSnail_Tab1", True, True, 4, 1)
    rom.get_data(0xA3, 0xCDC2, 0xCDD2, "uint16", kMaridiaSnail_Tab2, "kMaridiaSnail_Tab2", False, True, -1, 1)
    rom.get_data(0xA3, 0xCCA2, 0xCCE2, "uint16", kMaridiaSnail_Tab3, "kMaridiaSnail_Tab3", True, True, 16, 1)
    rom.get_data(0xA3, 0xCDD2, 0xCDE2, "uint16", kMaridiaSnail_FuncPtrs, "kMaridiaSnail_FuncPtrs", True, True, -1, 1)
    rom.get_data(0xA3, 0xD1AB, 0xD1B3, "uint16", kMaridiaSnail_InstrListPtrs0, "kMaridiaSnail_InstrListPtrs0", True, True, -1, 2)
    rom.get_data(0xA3, 0xD30D, 0xD315, "uint16", kMaridiaSnail_InstrListPtrs1, "kMaridiaSnail_InstrListPtrs1", True, True, -1, 2)
    rom.get_data(0xA3, 0xD50F, 0xD517, "uint16", kMaridiaSnail_InstrListPtrs2, "kMaridiaSnail_InstrListPtrs2", True, True, -1, 2)
    rom.get_data(0xA3, 0xD517, 0xD557, "uint16", kMaridiaSnail_Tab4, "kMaridiaSnail_Tab4", True, True, 6, 2)
    rom.get_data(0xA3, 0xD5A4, 0xD5AC, "uint16", kMaridiaSnail_InstrListPtrs3, "kMaridiaSnail_InstrListPtrs3", True, True, -1, 2)
    rom.get_data(0xA3, 0xDABC, 0xDB0C, "uint16", kReflec_GlowColorsIndices, "kReflec_GlowColorsIndices", True, True, 4, 1)
    rom.get_data(0xA3, 0xDC0B, 0xDC1B, "uint16", kReflec_InstrListPtrs0, "kReflec_InstrListPtrs0", True, True, -1, 1)
    rom.get_data(0xA3, 0xDCAE, 0xDD2E, "uint16", kReflec_ShootDirectionsIndices, "kReflec_ShootDirectionsIndices", True, True, 16, 1)
    rom.get_data(0xA3, 0xDCA6, 0xDCAE, "uint16", kReflec_InstrListPtrs1, "kReflec_InstrListPtrs1", True, True, -1, 1)
    rom.get_data(0xA3, 0xE03B, 0xE043, "uint16", kEnemyInit_WreckedShipOrangeZoomer_InstrListPtrs, "kEnemyInit_WreckedShipOrangeZoomer_InstrListPtrs", True, True, -1, 1)
    rom.get_data(0xA3, 0xE5F0, 0xE630, "uint16", kCommonZoomer_SpeedIndices, "kCommonZoomer_SpeedIndices", True, True, 16, 1)
    rom.get_data(0xA3, 0xE2CC, 0xE2D4, "uint16", kCommonZoomer_InstrListPtrs0, "kCommonZoomer_InstrListPtrs0", True, True, -1, 1)
    rom.get_data(0xA3, 0xE630, 0xE63C, "uint16", kCommonZoomer_InstrListPtrs1, "kCommonZoomer_InstrListPtrs1", True, True, -1, 1)
    rom.get_data(0xA3, 0xE63C, 0xE648, "uint16", kCommonZoomer_InstrListPtrs2, "kCommonZoomer_InstrListPtrs2", True, True, -1, 1)
    rom.get_data(0xA3, 0xE648, 0xE654, "uint16", kCommonZoomer_InstrListPtrs3, "kCommonZoomer_InstrListPtrs3", True, True, -1, 1)
    rom.get_data(0xA3, 0xE654, 0xE660, "uint16", kCommonZoomer_InstrListPtrs4, "kCommonZoomer_InstrListPtrs4", True, True, -1, 1)
    rom.get_data(0xA3, 0xE931, 0xE9AF, "uint16", kCommonZoomer_Tab0, "kCommonZoomer_Tab0", True, True, 16, 1)
    rom.get_data(0xA3, 0xEAD6, 0xEAE6, "uint16", kMetroid_CrySoundsIndices, "kMetroid_CrySoundsIndices", False, True, -1, 1)
    rom.get_data(0xA3, 0xEA3F, 0xEA47, "uint16", kMetroid_SpeedIndices, "kMetroid_SpeedIndices", True, True, -1, 1)
    return

get_A3()
