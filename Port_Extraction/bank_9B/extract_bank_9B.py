import sys
import os
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import common_data as rom

kUnchargedBeamTrailOffsets = []
kChargedBeamTrailOffsets = []
kSpazerSbaTrailOffsets = []
kDeathSequencePals_SuitOffset_1 = []
kDeathSequencePalette_ExplosionTabs = []
kDeathSequencePals_SuitOffset_2 = []
kDeathSequencePals_Suitless = []
kGrappleBlockDefaultConnectionPtrs = []
kGrappleBlockVerticalMovementConnectionPtrs = []
kGrappleBlockCrouchConnectionPtrs = []
kGrappleBeam_SpecialAngles = []
kGrappleBeam_SwingingData = []
kGrappleBeam_SwingingData2 = []
kGrappleBeam_SwingingData3 = []
kGrappleBeam_OriginX_NoRun = []
kGrappleBeam_OriginY_NoRun = []
kGrappleBeam_0x0d1a_offs_NoRun = []
kGrappleBeam_0x0d1c_offs_NoRun = []
kGrappleBeam_OriginX_Run = []
kGrappleBeam_OriginY_Run = []
kGrappleBeam_0x0d1a_offs_Run = []
kGrappleBeam_0x0d1c_offs_Run = []
kGrappleBeamFlareTileEndPtr = []
kGrappleBeamFlareTileBeginPtr = []
kGrappleBeamTilePtrs = []
kFlareAnimDelays_Main = []
kFlareLeftSpritemapOffsets = []
kFlareRightSpritemapOffsets = []
kGrappleToStandingSamusPoses = []
kGrappleToCrouchingSamusPoses = []
kGrappleBeam_Ext_Xvel = []
kGrappleBeam_Ext_Yvel = []
kGrappleBeam_Init_EndAngle = []

#Format is as follows: 
#rom.get_data(bank, starting address, ending address, "data type", array, "array name", hex bool, array bool, new line, new space)
#"hex bool" is whether you want the data in hexadecimal or in decimal format
#"array bool" is whether it's a single value or an array (will print [] if array, won't otherwise)
#"new line/space" is how many elements you want before you insert a new line/space, -1 is never
def get_9B():
    rom.get_data(0x9B, 0xA4B3, 0xA4CB, "uint16", kUnchargedBeamTrailOffsets, "kUnchargedBeamTrailOffsets", True, True, -1 , 1)
    rom.get_data(0x9B, 0xA4CB, 0xA4E3, "uint16", kChargedBeamTrailOffsets, "kChargedBeamTrailOffsets", True, True, -1, 1)
    rom.get_data(0x9B, 0xA4E3, 0xA4F7, "uint16", kSpazerSbaTrailOffsets, "kSpazerSbaTrailOffsets", True, True, -1, 1)
    rom.get_data(0x9B, 0xB5C8, 0xB5CE, "uint16", kDeathSequencePals_SuitOffset_1, "kDeathSequencePals_SuitOffset_1", True, True, -1, 1)
    rom.get_data(0x9B, 0xB823, 0xB835, "uint8", kDeathSequencePalette_ExplosionTabs, "kDeathSequencePalette_ExplosionTabs", False, True, 2, -1)
    rom.get_data(0x9B, 0xB6D2, 0xB6D8, "uint16", kDeathSequencePals_SuitOffset_2, "kDeathSequencePals_SuitOffset_2", True, True, -1, 1)
    rom.get_data(0x9B, 0xB80F, 0xB823, "uint16", kDeathSequencePals_Suitless, "kDeathSequencePals_Suitless", True, True, -1, 1)
    rom.get_data(0x9B, 0xC3C6, 0xC3EE, "uint16", kGrappleBlockDefaultConnectionPtrs, "kGrappleBlockDefaultConnectionPtrs", True, True, 2, 1)
    rom.get_data(0x9B, 0xC3EE, 0xC416, "uint16", kGrappleBlockVerticalMovementConnectionPtrs, "kGrappleBlockVerticalMovementConnectionPtrs", True, True, 2, 1)
    rom.get_data(0x9B, 0xC416, 0xC43E, "uint16", kGrappleBlockCrouchConnectionPtrs, "kGrappleBlockCrouchConnectionPtrs", True, True, 2, 1)
    rom.get_data(0x9B, 0xC43E, 0xC48E, "GrappleBeamSpecialAngles", kGrappleBeam_SpecialAngles, "kGrappleBeam_SpecialAngles", True, True, 1, -1)
    rom.get_data(0x9B, 0xC1C2, 0xC2C2, "uint8", kGrappleBeam_SwingingData, "kGrappleBeam_SwingingData", False, True, 16, 1)
    rom.get_data(0x9B, 0xC2C2, 0xC302, "uint8", kGrappleBeam_SwingingData2, "kGrappleBeam_SwingingData2", True, True, 32, 2)
    rom.get_data(0x9B, 0xC302, 0xC342, "uint8", kGrappleBeam_SwingingData3, "kGrappleBeam_SwingingData3", True, True, 32, 2)
    rom.get_data(0x9B, 0xC122, 0xC136, "uint16", kGrappleBeam_OriginX_NoRun, "kGrappleBeam_OriginX_NoRun", True, True, -1, 1)
    rom.get_data(0x9B, 0xC136, 0xC14A, "uint16", kGrappleBeam_OriginY_NoRun, "kGrappleBeam_OriginY_NoRun", True, True, -1, 1)
    rom.get_data(0x9B, 0xC14A, 0xC15E, "uint16", kGrappleBeam_0x0d1a_offs_NoRun, "kGrappleBeam_0x0d1a_offs_NoRun", True, True, -1, 1)
    rom.get_data(0x9B, 0xC15E, 0xC172, "uint16", kGrappleBeam_0x0d1c_offs_NoRun, "kGrappleBeam_0x0d1c_offs_NoRun", True, True, -1, 1)
    rom.get_data(0x9B, 0xC172, 0xC186, "uint16", kGrappleBeam_OriginX_Run, "kGrappleBeam_OriginX_Run", True, True, -1, 1)
    rom.get_data(0x9B, 0xC186, 0xC19A, "uint16", kGrappleBeam_OriginY_Run, "kGrappleBeam_OriginY_Run", True, True, -1, 1)
    rom.get_data(0x9B, 0xC19A, 0xC1AE, "uint16", kGrappleBeam_0x0d1a_offs_Run, "kGrappleBeam_0x0d1a_offs_Run", True, True, -1, 1)
    rom.get_data(0x9B, 0xC1AE, 0xC1C2, "uint16", kGrappleBeam_0x0d1c_offs_Run, "kGrappleBeam_0x0d1c_offs_Run", True, True, -1, 1)
    rom.get_data(0x9B, 0xC344, 0xC346, "uint16", kGrappleBeamFlareTileEndPtr, "kGrappleBeamFlareTileEndPtr", True, False, -1, -1)
    rom.get_data(0x9B, 0xC342, 0xC344, "uint16", kGrappleBeamFlareTileBeginPtr, "kGrappleBeamFlareTileBeginPtr", True, False, -1, -1)
    rom.get_data(0x9B, 0xC346, 0xC3C6, "uint16", kGrappleBeamTilePtrs, "kGrappleBeamTilePtrs", True, True, 16, 1)
    rom.get_data(0x90, 0xC487, 0xC4A7, "uint8", kFlareAnimDelays_Main, "kFlareAnimDelays_Main", False, True, 16, 1)
    rom.get_data(0x93, 0xA22B, 0xA231, "uint16", kFlareLeftSpritemapOffsets, "kFlareLeftSpritemapOffsets", False, True, -1, -1)
    rom.get_data(0x93, 0xA225, 0xA22B, "uint16", kFlareRightSpritemapOffsets, "kFlareRightSpritemapOffsets", False, True, -1, -1)
    rom.get_data(0x9C, 0xC9BA, 0xC9C4, "uint8", kGrappleToStandingSamusPoses, "kGrappleToStandingSamusPoses", True, True, -1, 1)
    rom.get_data(0x9B, 0xC9C4, 0xC9CE, "uint8", kGrappleToCrouchingSamusPoses, "kGrappleToCrouchingSamusPoses", True, True, -1, 1)
    rom.get_data(0x9B, 0xC0DB, 0xC0EF, "uint16", kGrappleBeam_Ext_Xvel, "kGrappleBeam_Ext_Xvel", True, True, -1, 1)
    rom.get_data(0x9B, 0xC0EF, 0xC103, "uint16", kGrappleBeam_Ext_Yvel, "kGrappleBeam_Ext_Yvel", True, True, -1, 1)
    rom.get_data(0x9B, 0xC104, 0xC118, "uint16", kGrappleBeam_Init_EndAngle, "kGrappleBeam_Init_EndAngle", True, True, -1, 1)
    return

get_9B()