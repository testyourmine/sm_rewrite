import sys
import os
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import common_data as rom

kMotherBrain_HealthBasedPalettes_Brain = []
kMotherBrain_HealthBasedPalettes_BackLeg = []
kMotherBrain_FadePalToBlack = []
kMotherBrain_TransitionToFromGrey_Incr = []
kMotherBrain_TransitionToFromGrey_Decr = []
kMotherBrain_FadeToGray_Drained = []
kMotherBrain_FadeToGray_RealDeath = []
kMotherBrain_Phase3_TurnLightsBackOn = []

#Format is as follows: 
#rom.get_data(bank, starting address, ending address, "data type", array, "array name", hex bool, array bool, new line, new space)
#"hex bool" is whether you want the data in hexadecimal or in decimal format
#"array bool" is whether it's a single value or an array (will print [] if array, won't otherwise)
#"new line/space" is how many elements you want before you insert a new line/space, -1 is never
def get_AD():
    rom.get_data(0xAD, 0xE6A2, 0xE6AC, "uint16", kMotherBrain_HealthBasedPalettes_Brain, "kMotherBrain_HealthBasedPalettes_Brain", True, True, -1, 1)
    rom.get_data(0xAD, 0xE742, 0xE74C, "uint16", kMotherBrain_HealthBasedPalettes_BackLeg, "kMotherBrain_HealthBasedPalettes_BackLeg", True, True, -1, 1)
    rom.get_data(0xAD, 0xE9E8, 0xEA0A, "uint16", kMotherBrain_FadePalToBlack, "kMotherBrain_FadePalToBlack", True, True, 16, 1)
    rom.get_data(0xAD, 0xED8A, 0xED9C, "uint16", kMotherBrain_TransitionToFromGrey_Incr, "kMotherBrain_TransitionToFromGrey_Incr", True, True, -1, 1)
    rom.get_data(0xAD, 0xED9C, 0xEDAE, "uint16", kMotherBrain_TransitionToFromGrey_Decr, "kMotherBrain_TransitionToFromGrey_Decr", True, True, -1, 1)
    rom.get_data(0xAD, 0xEF87, 0xEF99, "uint16", kMotherBrain_FadeToGray_Drained, "kMotherBrain_FadeToGray_Drained", True, True, -1, 1)
    rom.get_data(0xAD, 0xF107, 0xF119, "uint16", kMotherBrain_FadeToGray_RealDeath, "kMotherBrain_FadeToGray_RealDeath", True, True, -1, 1)
    rom.get_data(0xAD, 0xF273, 0xF283, "uint16", kMotherBrain_Phase3_TurnLightsBackOn, "kMotherBrain_Phase3_TurnLightsBackOn", True, True, -1, 1)
    return

get_AD()