import sys
import os
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import common_data as rom


#Pointers to code
kPowerBombExplosionFreeSpace = []
kPowerBombExplosionShapeTopOffset = []
kPowerBombExplosionColors = []
kPowerBombPreExplosionColors = []
kBG3XscrollWave = []
kHdmaScrollEntrys = []
kLavaAcidBG2YScrollLongWave = []
kLavaAcidBG2YScrollShortWave = []
kBG3RainXvels = []
kSuitPickupLightBeamCurveWidths = []
kRainbowBeamHdmaValues = []
kMorphBallEyeBeamHdmaValues = []


#Format is as follows: 
#rom.get_data(bank, starting address, ending address, "data type", array, "array name", hex bool, array bool, new line, new space)
#"hex bool" is whether you want the data in hexadecimal or in decimal format
#"array bool" is whether it's a single value or an array (will print [] if array, won't otherwise)
#"new line/space" is how many elements you want before you insert a new line/space, -1 is never
def get88():
  rom.get_data(0x88, 0xA206, 0xA286, "uint8", kPowerBombExplosionFreeSpace, "kPowerBombExplosionFreeSpace", True, True, 16, 1)
  rom.get_data(0x88, 0xA286, 0xA2A6, "uint8", kPowerBombExplosionShapeTopOffset, "kPowerBombExplosionShapeTopOffset", True, True, 16, 1)
  rom.get_data(0x88, 0x8D85, 0x8DE5, "uint8", kPowerBombExplosionColors, "kPowerBombExplosionColors", True, True, 3, 3)
  rom.get_data(0x88, 0x9079, 0x90A9, "uint8", kPowerBombPreExplosionColors, "kPowerBombPreExplosionColors", True, True, 3, 3)
  rom.get_data(0x88, 0xA938, 0xAD18, "uint16", kBG3XscrollWave, "kBG3XscrollWave", True, True, 16, 1)
  rom.get_data(0x88, 0xAEC1, 0xAF7B, "HdmaScrollEntry", kHdmaScrollEntrys, "kHdmaScrollEntrys", True, True, 1, -1)
  rom.get_data(0x88, 0xB589, 0xB5A9, "uint16", kLavaAcidBG2YScrollLongWave, "kLavaAcidBG2YScrollLongWave", True, True, 8, 1)
  rom.get_data(0x88, 0xB60A, 0xB62A, "uint16", kLavaAcidBG2YScrollShortWave, "kLavaAcidBG2YScrollShortWave", True, True, 8, 1)
  rom.get_data(0x88, 0xD992, 0xD99A, "uint16", kBG3RainXvels, "kBG3RainXvels", True, True, 4, 1)
  rom.get_data(0x88, 0xE3C9, 0xE449, "uint8", kSuitPickupLightBeamCurveWidths, "kSuitPickupLightBeamCurveWidths", False, True, 16, 1)
  rom.get_data(0x88, 0xE833, 0xE8D9, "uint16", kRainbowBeamHdmaValues, "kRainbowBeamHdmaValues", True, True, 8, 1)
  rom.get_data(0x88, 0xEA8B, 0xEACB, "uint8", kMorphBallEyeBeamHdmaValues, "kMorphBallEyeBeamHdmaValues", False, True, 4, 1)
  return

get88()