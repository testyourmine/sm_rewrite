#pragma once

#define kProjectileData_UnchargedBeams ((uint16*)RomFixedPtr(0x9383c1))
#define kProjectileData_ChargedBeams ((uint16*)RomFixedPtr(0x9383d9))
#define kProjectileData_NonBeams ((uint16*)RomFixedPtr(0x9383f1))
#define kShinesparkEchoSpazer_ProjectileData ((uint16*)RomFixedPtr(0x938403))
#define kRunInstrForSuperMissile ((uint16*)RomFixedPtr(0x93842b))
#define kProjInstrList_SuperMissileExplosion (*(ProjectileDamagesAndInstrPtr*)RomFixedPtr(0x938691))
#define kProjInstrList_BeamExplosion (*(ProjectileDamagesAndInstrPtr*)RomFixedPtr(0x938679))
#define kProjInstrList_BombExplosion (*(ProjectileDamagesAndInstrPtr*)RomFixedPtr(0x938681))
#define kProjectileData_SBA ((uint16*)RomFixedPtr(0x938413))
