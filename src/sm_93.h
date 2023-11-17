#pragma once

//#define kProjectileData_UnchargedBeams ((uint16*)RomFixedPtr(0x9383c1))
//#define kProjectileData_ChargedBeams ((uint16*)RomFixedPtr(0x9383d9))
//#define kProjectileData_NonBeams ((uint16*)RomFixedPtr(0x9383f1))
//#define kShinesparkEchoSpazer_ProjectileData ((uint16*)RomFixedPtr(0x938403))
//#define kRunInstrForSuperMissile ((uint16*)RomFixedPtr(0x93842b))
//#define kProjInstrList_SuperMissileExplosion (*(ProjectileDamagesAndInstrPtr*)RomFixedPtr(0x938691))
//#define kProjInstrList_MissileExplosion (*(ProjectileDamagesAndInstrPtr*)RomFixedPtr(0x93867D))
//#define kProjInstrList_BeamExplosion (*(ProjectileDamagesAndInstrPtr*)RomFixedPtr(0x938679))
//#define kProjInstrList_BombExplosion (*(ProjectileDamagesAndInstrPtr*)RomFixedPtr(0x938681))
//#define kProjectileData_SBA ((uint16*)RomFixedPtr(0x938413))

uint16 kProjectileData_UnchargedBeams[] = {
  0x8431, 0x84b5, 0x849f, 0x84e1, 0x8447, 0x84f7, 0x845d, 0x8473, 0x84cb, 0x850d, 0x8523, 0x8489,
};

uint16 kProjectileData_ChargedBeams[] = {
  0x8539, 0x85d3, 0x85a7, 0x85e9, 0x854f, 0x85ff, 0x8565, 0x857b, 0x85bd, 0x862b, 0x8615, 0x8591,
};

uint16 kProjectileData_NonBeams[] = {
  0x8641, 0x8641, 0x8657, 0x8671, 0x8641, 0x8675, 0x8641, 0x8679, 0x867d,
};

uint16 kShinesparkEchoSpazer_ProjectileData[] = {
     0x0,    0x0, 0x86ab, 0x8695, 0x86ab, 0x86d7,    0x0, 0x86c1,
};

uint16 kRunInstrForSuperMissile[] = {
     0x0,    0x0, 0x866d,
};

ProjectileDamagesAndInstrPtr kProjInstrList_SuperMissileExplosion = {    0x8, 0xa0c1, };

ProjectileDamagesAndInstrPtr kProjInstrList_MissileExplosion = {    0x8, 0xa039, };

ProjectileDamagesAndInstrPtr kProjInstrList_BeamExplosion = {    0x8, 0xa007, };

ProjectileDamagesAndInstrPtr kProjInstrList_BombExplosion = {    0x0, 0xa06b, };

uint16 kProjectileData_SBA[] = {
     0x0, 0x8689,    0x0,    0x0, 0x868d, 0x868d,    0x0,    0x0, 0x8685, 0x8685,    0x0,    0x0,
};
