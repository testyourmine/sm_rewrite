import sys
import os
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import common_data as rom

kMusicPointers = []
kTimerDigitsSpritemapPtr = []
kLoadStationLists = []
kAreaElevatorBitsPtr = []

#Format is as follows: 
#rom.get_data(bank, starting address, ending address, "data type", array, "array name", hex bool, array bool, new line, new space)
#"hex bool" is whether you want the data in hexadecimal or in decimal format
#"array bool" is whether it's a single value or an array (will print [] if array, won't otherwise)
#"new line/space" is how many elements you want before you insert a new line/space, -1 is never
def get_80():
  rom.get_data(0x8F, 0xE7E1, 0xE82C, "LongPtr", kMusicPointers, "kMusicPointers", True, True, -1, 1)
  rom.get_data(0x80, 0x9FD4, 0x9FE8, "uint16", kTimerDigitsSpritemapPtr, "kTimerDigitsSpritemapPtr", True, True, -1, 1)
  rom.get_data(0x80, 0xC4B5, 0xC4C5, "uint16", kLoadStationLists, "kLoadStationLists", True, True, -1, 1)
  rom.get_data(0x80, 0xCD46, 0xCD52, "uint16", kAreaElevatorBitsPtr, "kAreaElevatorBitsPtr", True, True, -1, 1)
  return

get_80()