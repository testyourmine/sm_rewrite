import sys
import os
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import common_data as rom

kProjectileData_UnchargedBeams = []
kProjectileData_ChargedBeams = []
kProjectileData_NonBeams = []
kShinesparkEchoSpazer_ProjectileData = []
kRunInstrForSuperMissile = []
kProjInstrList_SuperMissileExplosion = []
kProjInstrList_MissileExplosion = []
kProjInstrList_BeamExplosion = []
kProjInstrList_BombExplosion = []
kProjectileData_SBA = []

#Format is as follows: 
#rom.get_data(bank, starting address, ending address, "data type", array, "array name", hex bool, array bool, new line, new space)
#"hex bool" is whether you want the data in hexadecimal or in decimal format
#"array bool" is whether it's a single value or an array (will print [] if array, won't otherwise)
#"new line/space" is how many elements you want before you insert a new line/space, -1 is never
def get_93():
    rom.get_data(0x93, 0x83C1, 0x83D9, "uint16", kProjectileData_UnchargedBeams, "kProjectileData_UnchargedBeams", True, True, -1, 1)
    rom.get_data(0x93, 0x83D9, 0x83F1, "uint16", kProjectileData_ChargedBeams, "kProjectileData_ChargedBeams", True, True, -1, 1)
    rom.get_data(0x93, 0x83F1, 0x8403, "uint16", kProjectileData_NonBeams, "kProjectileData_NonBeams", True, True, -1, 1)
    rom.get_data(0x93, 0x8403, 0x8413, "uint16", kShinesparkEchoSpazer_ProjectileData, "kShinesparkEchoSpazer_ProjectileData", True, True, -1, 1)
    rom.get_data(0x93, 0x842B, 0x8431, "uint16", kRunInstrForSuperMissile, "kRunInstrForSuperMissile", True, True, -1, 1)
    rom.get_data(0x93, 0x8691, 0x8695, "ProjectileDamagesAndInstrPtr", kProjInstrList_SuperMissileExplosion, "kProjInstrList_SuperMissileExplosion", True, False, -1, -1)
    rom.get_data(0x93, 0x867D, 0x8681, "ProjectileDamagesAndInstrPtr", kProjInstrList_MissileExplosion, "kProjInstrList_MissileExplosion", True, False, -1, -1)
    rom.get_data(0x93, 0x8679, 0x867D, "ProjectileDamagesAndInstrPtr", kProjInstrList_BeamExplosion, "kProjInstrList_BeamExplosion", True, False, -1, -1)
    rom.get_data(0x93, 0x8681, 0x8685, "ProjectileDamagesAndInstrPtr", kProjInstrList_BombExplosion, "kProjInstrList_BombExplosion", True, False, -1, 1)
    rom.get_data(0x93, 0x8413, 0x842B, "uint16", kProjectileData_SBA, "kProjectileData_SBA", True, True, -1, 1)
    return

get_93()