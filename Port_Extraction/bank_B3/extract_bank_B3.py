import sys
import os
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import common_data as rom

kBrinstarRedPipeBug_InstrListPtrs = []
kBrinstarGreenPipeBug_InstrListPtrs = []
kBotwoon_HoleHitboxes = []
kBotwoon_SpeedTable = []
kBotwoon_9675PtrsUNUSED = []
kBotwoonHealthThresForPalChange = []
kBotwoonHealthBasedPalette = []
kBotwoon_MouthClosedDirectionInstrListPtrs = []
kBotwoon_SpitDirectionInstrListPtrs = []
kEscapeEtecoon_XPositions = []
kEscapeEtecoon_YPositions = []
kEscapeEtecoon_InstrListPtrs = []
kEscapeEtecoon_FuncPtrs = []
kEscapeEtecoon_XVelocities = []

#Format is as follows: 
#rom.get_data(bank, starting address, ending address, "data type", array, "array name", hex bool, array bool, new line, new space)
#"hex bool" is whether you want the data in hexadecimal or in decimal format
#"array bool" is whether it's a single value or an array (will print [] if array, won't otherwise)
#"new line/space" is how many elements you want before you insert a new line/space, -1 is never
def get_B3():
    rom.get_data(0xB3, 0x882B, 0x8833, "uint16", kBrinstarRedPipeBug_InstrListPtrs, "kBrinstarRedPipeBug_InstrListPtrs", True, True, -1, 1)
    rom.get_data(0xB3, 0x8833, 0x883B, "uint16", kBrinstarGreenPipeBug_InstrListPtrs, "kBrinstarGreenPipeBug_InstrListPtrs", True, True, -1, 1)
    rom.get_data(0xB3, 0x949B, 0x94BB, "uint16", kBotwoon_HoleHitboxes, "kBotwoon_HoleHitboxes", True, True, 4, 1)
    rom.get_data(0xB3, 0x94BB, 0x94C7, "uint16", kBotwoon_SpeedTable, "kBotwoon_SpeedTable", False, True, 2, 1)
    rom.get_data(0xB3, 0x9675, 0x967B, "uint16", kBotwoon_9675PtrsUNUSED, "kBotwoon_9675PtrsUNUSED", True, True, -1, 1)
    rom.get_data(0xB3, 0x981B, 0x982B, "uint16", kBotwoonHealthThresForPalChange, "kBotwoonHealthThresForPalChange", True, True, -1, 1)
    rom.get_data(0xB3, 0x971B, 0x981B, "uint16", kBotwoonHealthBasedPalette, "kBotwoonHealthBasedPalette", True, True, 16, 1)
    rom.get_data(0xB3, 0x946B, 0x949B, "uint16", kBotwoon_MouthClosedDirectionInstrListPtrs, "kBotwoon_MouthClosedDirectionInstrListPtrs", True, True, 8, 1)
    rom.get_data(0xB3, 0x948B, 0x949B, "uint16", kBotwoon_SpitDirectionInstrListPtrs, "kBotwoon_SpitDirectionInstrListPtrs", True, True, -1, 1)
    rom.get_data(0xB3, 0xE718, 0xE71E, "uint16", kEscapeEtecoon_XPositions, "kEscapeEtecoon_XPositions", False, True, -1, 1)
    rom.get_data(0xB3, 0xE71E, 0xE724, "uint16", kEscapeEtecoon_YPositions, "kEscapeEtecoon_YPositions", False, True, -1, 1)
    rom.get_data(0xB3, 0xE72A, 0xE730, "uint16", kEscapeEtecoon_InstrListPtrs, "kEscapeEtecoon_InstrListPtrs", True, True, -1, 1)
    rom.get_data(0xB3, 0xE724, 0xE72A, "uint16", kEscapeEtecoon_FuncPtrs, "kEscapeEtecoon_FuncPtrs", True, True, -1, 1)
    rom.get_data(0xB3, 0xE730, 0xE736, "uint16", kEscapeEtecoon_XVelocities, "kEscapeEtecoon_XVelocities", True, True, -1, 1)
    return

get_B3()