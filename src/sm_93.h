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

//uint16 kProjectileData_UnchargedBeams[] = {
//  0x8431, 0x84b5, 0x849f, 0x84e1, 0x8447, 0x84f7, 0x845d, 0x8473, 0x84cb, 0x850d, 0x8523, 0x8489,
//};
//
//uint16 kProjectileData_ChargedBeams[] = {
//  0x8539, 0x85d3, 0x85a7, 0x85e9, 0x854f, 0x85ff, 0x8565, 0x857b, 0x85bd, 0x862b, 0x8615, 0x8591,
//};
//
//uint16 kProjectileData_NonBeams[] = {
//  0x8641, 0x8641, 0x8657, 0x8671, 0x8641, 0x8675, 0x8641, 0x8679, 0x867d,
//};
//
//uint16 kProjectileData_ShinesparkEchoSpazerSba[] = {
//     0x0,    0x0, 0x86ab, 0x8695, 0x86ab, 0x86d7,    0x0, 0x86c1,
//};
//
//uint16 kRunInstrForSuperMissile[] = {
//     0x0,    0x0, 0x866d,
//};
//
//ProjectileDamagesAndInstrPtr kProjInstrList_SuperMissileExplosion = {    0x8, 0xa0c1, };
//
//ProjectileDamagesAndInstrPtr kProjInstrList_MissileExplosion = {    0x8, 0xa039, };
//
//ProjectileDamagesAndInstrPtr kProjInstrList_BeamExplosion = {    0x8, 0xa007, };
//
//ProjectileDamagesAndInstrPtr kProjInstrList_BombExplosion = {    0x0, 0xa06b, };
//
//uint16 kProjectileData_SBA[] = {
//     0x0, 0x8689,    0x0,    0x0, 0x868d, 0x868d,    0x0,    0x0, 0x8685, 0x8685,    0x0,    0x0,
//};



ProjectileDataTable kProjectileData_UnchargedBeams[] = {
  [0] = { .damage =  20, .up_face_right = 0x86db, .up_right = 0x86e7, .right = 0x86f3, .down_right = 0x86ff, .down_face_right = 0x870b, .down_face_left = 0x870b, .down_left = 0x8717, .left = 0x8723, .up_left = 0x872f, .up_face_left = 0x86db },
  [1] = { .damage =  50, .up_face_right = 0x873b, .up_right = 0x87c7, .right = 0x884b, .down_right = 0x88cf, .down_face_right = 0x8743, .down_face_left = 0x8743, .down_left = 0x87c7, .left = 0x884b, .up_left = 0x88cf, .up_face_left = 0x873b },
  [2] = { .damage =  30, .up_face_right = 0x8953, .up_right = 0x8953, .right = 0x8953, .down_right = 0x8953, .down_face_right = 0x8953, .down_face_left = 0x8953, .down_left = 0x8953, .left = 0x8953, .up_left = 0x8953, .up_face_left = 0x8953 },
  [3] = { .damage =  60, .up_face_right = 0x873b, .up_right = 0x87c7, .right = 0x884b, .down_right = 0x88cf, .down_face_right = 0x8743, .down_face_left = 0x8743, .down_left = 0x87c7, .left = 0x884b, .up_left = 0x88cf, .up_face_left = 0x873b },
  [4] = { .damage =  40, .up_face_right = 0x8977, .up_right = 0x8993, .right = 0x89af, .down_right = 0x89cb, .down_face_right = 0x89e7, .down_face_left = 0x89e7, .down_left = 0x8a03, .left = 0x8a1f, .up_left = 0x8a3b, .up_face_left = 0x8977 },
  [5] = { .damage =  70, .up_face_right = 0x8a57, .up_right = 0x8aab, .right = 0x8aff, .down_right = 0x8b53, .down_face_right = 0x8ba7, .down_face_left = 0x8ba7, .down_left = 0x8bfb, .left = 0x8c4f, .up_left = 0x8ca3, .up_face_left = 0x8a57 },
  [6] = { .damage =  60, .up_face_right = 0x8977, .up_right = 0x8993, .right = 0x89af, .down_right = 0x89cb, .down_face_right = 0x89e7, .down_face_left = 0x89e7, .down_left = 0x8a03, .left = 0x8a1f, .up_left = 0x8a3b, .up_face_left = 0x8977 },
  [7] = { .damage = 100, .up_face_right = 0x8a57, .up_right = 0x8aab, .right = 0x8aff, .down_right = 0x8b53, .down_face_right = 0x8ba7, .down_face_left = 0x8ba7, .down_left = 0x8bfb, .left = 0x8c4f, .up_left = 0x8ca3, .up_face_left = 0x8a57 },
  [8] = { .damage = 150, .up_face_right = 0x8cf7, .up_right = 0x8d0b, .right = 0x8d1f, .down_right = 0x8d33, .down_face_right = 0x8cf7, .down_face_left = 0x8cf7, .down_left = 0x8d0b, .left = 0x8d1f, .up_left = 0x8d33, .up_face_left = 0x8cf7 },
  [9] = { .damage = 250, .up_face_right = 0x8d4f, .up_right = 0x8d9b, .right = 0x8ddf, .down_right = 0x8e33, .down_face_right = 0x8d4f, .down_face_left = 0x8d4f, .down_left = 0x8d9b, .left = 0x8ddf, .up_left = 0x8e33, .up_face_left = 0x8d4f },
  [10] = { .damage = 200, .up_face_right = 0x8cf7, .up_right = 0x8d0b, .right = 0x8d1f, .down_right = 0x8d33, .down_face_right = 0x8cf7, .down_face_left = 0x8cf7, .down_left = 0x8d0b, .left = 0x8d1f, .up_left = 0x8d33, .up_face_left = 0x8cf7 },
  [11] = { .damage = 300, .up_face_right = 0x8d47, .up_right = 0x8d93, .right = 0x8ddf, .down_right = 0x8e2b, .down_face_right = 0x8d47, .down_face_left = 0x8d47, .down_left = 0x8d93, .left = 0x8ddf, .up_left = 0x8e2b, .up_face_left = 0x8d47 },
};

ProjectileDataTable kProjectileData_ChargedBeams[] = {
  [0] = { .damage =  60, .up_face_right = 0x8e77, .up_right = 0x8e8b, .right = 0x8e9f, .down_right = 0x8eb3, .down_face_right = 0x8ec7, .down_face_left = 0x8ec7, .down_left = 0x8edb, .left = 0x8eef, .up_left = 0x8f03, .up_face_left = 0x8e77 },
  [1] = { .damage = 150, .up_face_right = 0x8f17, .up_right = 0x8fa3, .right = 0x9027, .down_right = 0x90ab, .down_face_right = 0x8f1f, .down_face_left = 0x8f1f, .down_left = 0x8fa3, .left = 0x9027, .up_left = 0x90ab, .up_face_left = 0x8f17 },
  [2] = { .damage =  90, .up_face_right = 0x912f, .up_right = 0x912f, .right = 0x912f, .down_right = 0x912f, .down_face_right = 0x912f, .down_face_left = 0x912f, .down_left = 0x912f, .left = 0x912f, .up_left = 0x912f, .up_face_left = 0x912f },
  [3] = { .damage = 180, .up_face_right = 0x9153, .up_right = 0x91df, .right = 0x9263, .down_right = 0x92e7, .down_face_right = 0x915b, .down_face_left = 0x915b, .down_left = 0x91df, .left = 0x9263, .up_left = 0x92e7, .up_face_left = 0x9153 },
  [4] = { .damage = 120, .up_face_right = 0x936b, .up_right = 0x93bf, .right = 0x9413, .down_right = 0x9467, .down_face_right = 0x936b, .down_face_left = 0x936b, .down_left = 0x93bf, .left = 0x9413, .up_left = 0x9467, .up_face_left = 0x936b },
  [5] = { .damage = 210, .up_face_right = 0x94bb, .up_right = 0x957f, .right = 0x9643, .down_right = 0x9707, .down_face_right = 0x97cb, .down_face_left = 0x97cb, .down_left = 0x988f, .left = 0x9953, .up_left = 0x9a17, .up_face_left = 0x94bb },
  [6] = { .damage = 180, .up_face_right = 0x936b, .up_right = 0x93bf, .right = 0x9413, .down_right = 0x9467, .down_face_right = 0x936b, .down_face_left = 0x936b, .down_left = 0x93bf, .left = 0x9413, .up_left = 0x9467, .up_face_left = 0x936b },
  [7] = { .damage = 300, .up_face_right = 0x94bb, .up_right = 0x957f, .right = 0x9643, .down_right = 0x9707, .down_face_right = 0x97cb, .down_face_left = 0x97cb, .down_left = 0x988f, .left = 0x9953, .up_left = 0x9a17, .up_face_left = 0x94bb },
  [8] = { .damage = 450, .up_face_right = 0x9adb, .up_right = 0x9b1f, .right = 0x9b63, .down_right = 0x9ba7, .down_face_right = 0x9adb, .down_face_left = 0x9adb, .down_left = 0x9b1f, .left = 0x9b63, .up_left = 0x9ba7, .up_face_left = 0x9adb },
  [9] = { .damage = 750, .up_face_right = 0x9beb, .up_right = 0x9c9f, .right = 0x9d53, .down_right = 0x9e07, .down_face_right = 0x9beb, .down_face_left = 0x9beb, .down_left = 0x9c9f, .left = 0x9d53, .up_left = 0x9e07, .up_face_left = 0x9beb },
  [10] = { .damage = 600, .up_face_right = 0x9adb, .up_right = 0x9b1f, .right = 0x9b63, .down_right = 0x9ba7, .down_face_right = 0x9adb, .down_face_left = 0x9adb, .down_left = 0x9b1f, .left = 0x9b63, .up_left = 0x9ba7, .up_face_left = 0x9adb },
  [11] = { .damage = 900, .up_face_right = 0x9beb, .up_right = 0x9c9f, .right = 0x9d53, .down_right = 0x9e07, .down_face_right = 0x9beb, .down_face_left = 0x9beb, .down_left = 0x9c9f, .left = 0x9d53, .up_left = 0x9e07, .up_face_left = 0x9beb },
};

ProjectileDataTable kProjectileData_NonBeams[] = {
  [0] = { .damage = 100, .up_face_right = 0x9ebb, .up_right = 0x9ec7, .right = 0x9ed3, .down_right = 0x9edf, .down_face_right = 0x9eeb, .down_face_left = 0x9eeb, .down_left = 0x9ef7, .left = 0x9f03, .up_left = 0x9f0f, .up_face_left = 0x9ebb },
  [1] = { .damage = 100, .up_face_right = 0x9ebb, .up_right = 0x9ec7, .right = 0x9ed3, .down_right = 0x9edf, .down_face_right = 0x9eeb, .down_face_left = 0x9eeb, .down_left = 0x9ef7, .left = 0x9f03, .up_left = 0x9f0f, .up_face_left = 0x9ebb },
  [2] = { .damage = 300, .up_face_right = 0x9f1b, .up_right = 0x9f27, .right = 0x9f33, .down_right = 0x9f3f, .down_face_right = 0x9f4b, .down_face_left = 0x9f4b, .down_left = 0x9f57, .left = 0x9f63, .up_left = 0x9f6f, .up_face_left = 0x9f1b },
  [3] = { .damage = 200, .instr_ptrs[0] = 0x9f87 },
  [4] = { .damage = 100, .up_face_right = 0x9ebb, .up_right = 0x9ec7, .right = 0x9ed3, .down_right = 0x9edf, .down_face_right = 0x9eeb, .down_face_left = 0x9eeb, .down_left = 0x9ef7, .left = 0x9f03, .up_left = 0x9f0f, .up_face_left = 0x9ebb },
  [5] = { .damage =  30, .instr_ptrs[0] = 0x9fbf },
  [6] = { .damage = 100, .up_face_right = 0x9ebb, .up_right = 0x9ec7, .right = 0x9ed3, .down_right = 0x9edf, .down_face_right = 0x9eeb, .down_face_left = 0x9eeb, .down_left = 0x9ef7, .left = 0x9f03, .up_left = 0x9f0f, .up_face_left = 0x9ebb },
  [7] = { .damage =   8, .instr_ptrs[0] = 0xa007 },
  [8] = { .damage =   8, .instr_ptrs[0] = 0xa039 },
};

ProjectileDataTable kProjectileData_ShinesparkEchoSpazerSba[] = {
  [0] = { 0 },
  [1] = { 0 },
  [2] = { .damage = 300, .up_face_right = 0xa13d, .up_right = 0xa13d, .right = 0xa13d, .down_right = 0xa13d, .down_face_right = 0xa13d, .down_face_left = 0xa13d, .down_left = 0xa13d, .left = 0xa13d, .up_left = 0xa13d, .up_face_left = 0xa13d },
  [3] = { .damage = 61440, .up_face_right = 0xa0f3, .up_right = 0xa0f3, .right = 0xa0f3, .down_right = 0xa0f3, .down_face_right = 0xa0f3, .down_face_left = 0xa0f3, .down_left = 0xa0f3, .left = 0xa0f3, .up_left = 0xa0f3, .up_face_left = 0xa0f3 },
  [4] = { .damage = 300, .up_face_right = 0xa13d, .up_right = 0xa13d, .right = 0xa13d, .down_right = 0xa13d, .down_face_right = 0xa13d, .down_face_left = 0xa13d, .down_left = 0xa13d, .left = 0xa13d, .up_left = 0xa13d, .up_face_left = 0xa13d },
  [5] = { .damage =   0, .instr_ptrs[0] = 0xa16d },
  [6] = { 0 },
  [7] = { .damage = 4096, .up_face_right = 0xa119, .up_right = 0xa119, .right = 0xa119, .down_right = 0xa119, .down_face_right = 0xa119, .down_face_left = 0xa119, .down_left = 0xa119, .left = 0xa119, .up_left = 0xa119, .up_face_left = 0xa119 },
};

ProjectileDataTable kRunInstrForSuperMissile[] = {
  [0] = { 0 },
  [1] = { 0 },
  [2] = { .damage = 300, .instr_ptrs[0] = 0x9f7b },
};

ProjectileDamagesAndInstrPtr kProjInstrList_SuperMissileExplosion = {
  .damage =   8, .instr_ptr = 0xa0c1
};

ProjectileDamagesAndInstrPtr kProjInstrList_MissileExplosion = {
  .damage =   8, .instr_ptr = 0xa039
};

ProjectileDamagesAndInstrPtr kProjInstrList_BeamExplosion = {
  .damage =   8, .instr_ptr = 0xa007
};

ProjectileDamagesAndInstrPtr kProjInstrList_BombExplosion = {
  .damage =   0, .instr_ptr = 0xa06b
};

ProjectileDataTable kProjectileData_SBA[] = {
  [0] = { 0 },
  [1] = { .damage = 300, .instr_ptrs[0] = 0xa159 },
  [2] = { 0 },
  [3] = { 0 },
  [4] = { .damage = 300, .instr_ptrs[0] = 0x8977 },
  [5] = { .damage = 300, .instr_ptrs[0] = 0x8977 },
  [6] = { 0 },
  [7] = { 0 },
  [8] = { .damage = 300, .instr_ptrs[0] = 0xa095 },
  [9] = { .damage = 300, .instr_ptrs[0] = 0xa095 },
  [10] = { 0 },
  [11] = { 0 },
};


ProjectileInstr get_ProjectileInstr(uint16 instr_ptr) {
  switch (instr_ptr) {
    case 0x86db: return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xa25b, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case 0x86e3: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x86db };
    case 0x86e7: return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xa262, .x_radius =  8, .y_radius =  4, .trail_frame =  0 };
    case 0x86ef: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x86e7 };
    case 0x86f3: return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xa269, .x_radius =  8, .y_radius =  4, .trail_frame =  0 };
    case 0x86fb: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x86f3 };
    case 0x86ff: return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xa270, .x_radius =  8, .y_radius =  4, .trail_frame =  0 };
    case 0x8707: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x86ff };
    case 0x870b: return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xa277, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case 0x8713: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x870b };
    case 0x8717: return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xa27e, .x_radius =  8, .y_radius =  4, .trail_frame =  0 };
    case 0x871f: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x8717 };
    case 0x8723: return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xa24d, .x_radius =  8, .y_radius =  4, .trail_frame =  0 };
    case 0x872b: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x8723 };
    case 0x872f: return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xa254, .x_radius =  8, .y_radius =  4, .trail_frame =  0 };
    case 0x8737: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x872f };
    case 0x873b: return (ProjectileInstr){ .timer =  4, .spritemap_ptr = 0xa117, .x_radius = 12, .y_radius =  4, .trail_frame =  0 };
    case 0x8743: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae65, .x_radius = 12, .y_radius =  4, .trail_frame =  0 };
    case 0x874b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaedc, .x_radius = 12, .y_radius =  4, .trail_frame =  1 };
    case 0x8753: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaee3, .x_radius = 12, .y_radius =  4, .trail_frame =  2 };
    case 0x875b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaeea, .x_radius = 16, .y_radius =  4, .trail_frame =  3 };
    case 0x8763: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaef1, .x_radius = 20, .y_radius =  4, .trail_frame =  4 };
    case 0x876b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaeea, .x_radius = 16, .y_radius =  4, .trail_frame =  5 };
    case 0x8773: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaee3, .x_radius = 12, .y_radius =  4, .trail_frame =  6 };
    case 0x877b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaedc, .x_radius = 12, .y_radius =  4, .trail_frame =  7 };
    case 0x8783: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae65, .x_radius = 12, .y_radius =  4, .trail_frame =  8 };
    case 0x878b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaef8, .x_radius = 12, .y_radius =  4, .trail_frame =  9 };
    case 0x8793: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaeff, .x_radius = 12, .y_radius =  4, .trail_frame = 10 };
    case 0x879b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf06, .x_radius = 16, .y_radius =  4, .trail_frame = 11 };
    case 0x87a3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf0d, .x_radius = 20, .y_radius =  4, .trail_frame = 12 };
    case 0x87ab: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf06, .x_radius = 16, .y_radius =  4, .trail_frame = 13 };
    case 0x87b3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaeff, .x_radius = 12, .y_radius =  4, .trail_frame = 14 };
    case 0x87bb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaef8, .x_radius = 12, .y_radius =  4, .trail_frame = 15 };
    case 0x87c3: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x8743 };
    case 0x87c7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae65, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x87cf: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf14, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case 0x87d7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf1b, .x_radius =  8, .y_radius =  8, .trail_frame =  2 };
    case 0x87df: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf22, .x_radius = 10, .y_radius = 10, .trail_frame =  3 };
    case 0x87e7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf29, .x_radius = 12, .y_radius = 12, .trail_frame =  4 };
    case 0x87ef: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf22, .x_radius = 10, .y_radius = 10, .trail_frame =  5 };
    case 0x87f7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf1b, .x_radius =  8, .y_radius =  8, .trail_frame =  6 };
    case 0x87ff: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf14, .x_radius =  6, .y_radius =  6, .trail_frame =  7 };
    case 0x8807: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae65, .x_radius =  4, .y_radius =  4, .trail_frame =  8 };
    case 0x880f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf30, .x_radius =  6, .y_radius =  6, .trail_frame =  9 };
    case 0x8817: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf37, .x_radius =  8, .y_radius =  8, .trail_frame = 10 };
    case 0x881f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf3e, .x_radius = 10, .y_radius = 10, .trail_frame = 11 };
    case 0x8827: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf45, .x_radius = 12, .y_radius = 12, .trail_frame = 12 };
    case 0x882f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf3e, .x_radius = 10, .y_radius = 10, .trail_frame = 13 };
    case 0x8837: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf37, .x_radius =  8, .y_radius =  8, .trail_frame = 14 };
    case 0x883f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf30, .x_radius =  8, .y_radius =  8, .trail_frame = 15 };
    case 0x8847: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x87c7 };
    case 0x884b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae65, .x_radius =  4, .y_radius = 12, .trail_frame =  0 };
    case 0x8853: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae6c, .x_radius =  4, .y_radius = 12, .trail_frame =  1 };
    case 0x885b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae73, .x_radius =  4, .y_radius = 12, .trail_frame =  2 };
    case 0x8863: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae7a, .x_radius =  4, .y_radius = 16, .trail_frame =  3 };
    case 0x886b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae81, .x_radius =  4, .y_radius = 20, .trail_frame =  4 };
    case 0x8873: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae7a, .x_radius =  4, .y_radius = 16, .trail_frame =  5 };
    case 0x887b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae73, .x_radius =  4, .y_radius = 12, .trail_frame =  6 };
    case 0x8883: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae6c, .x_radius =  4, .y_radius = 12, .trail_frame =  7 };
    case 0x888b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae65, .x_radius =  4, .y_radius = 12, .trail_frame =  8 };
    case 0x8893: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae88, .x_radius =  4, .y_radius = 12, .trail_frame =  9 };
    case 0x889b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae8f, .x_radius =  4, .y_radius = 12, .trail_frame = 10 };
    case 0x88a3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae96, .x_radius =  4, .y_radius = 16, .trail_frame = 11 };
    case 0x88ab: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae9d, .x_radius =  4, .y_radius = 20, .trail_frame = 12 };
    case 0x88b3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae96, .x_radius =  4, .y_radius = 16, .trail_frame = 13 };
    case 0x88bb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae8f, .x_radius =  4, .y_radius = 12, .trail_frame = 14 };
    case 0x88c3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae88, .x_radius =  4, .y_radius = 12, .trail_frame = 15 };
    case 0x88cb: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x884b };
    case 0x88cf: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae65, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x88d7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaea4, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case 0x88df: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaeab, .x_radius =  8, .y_radius =  8, .trail_frame =  2 };
    case 0x88e7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaeb2, .x_radius = 10, .y_radius = 10, .trail_frame =  3 };
    case 0x88ef: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaeb9, .x_radius = 12, .y_radius = 12, .trail_frame =  4 };
    case 0x88f7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaeb2, .x_radius = 10, .y_radius = 10, .trail_frame =  5 };
    case 0x88ff: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaeab, .x_radius =  8, .y_radius =  8, .trail_frame =  6 };
    case 0x8907: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaea4, .x_radius =  6, .y_radius =  6, .trail_frame =  7 };
    case 0x890f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xae65, .x_radius =  4, .y_radius =  4, .trail_frame =  8 };
    case 0x8917: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaec0, .x_radius =  6, .y_radius =  6, .trail_frame =  9 };
    case 0x891f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaec7, .x_radius =  8, .y_radius =  8, .trail_frame = 10 };
    case 0x8927: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaece, .x_radius = 10, .y_radius = 10, .trail_frame = 11 };
    case 0x892f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaed5, .x_radius = 12, .y_radius = 12, .trail_frame = 12 };
    case 0x8937: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaece, .x_radius = 10, .y_radius = 10, .trail_frame = 13 };
    case 0x893f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaec7, .x_radius =  8, .y_radius =  8, .trail_frame = 14 };
    case 0x8947: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaec0, .x_radius =  8, .y_radius =  8, .trail_frame = 15 };
    case 0x894f: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x88cf };
    case 0x8953: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xedf6, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x895b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xedfd, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case 0x8963: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xee04, .x_radius =  8, .y_radius =  8, .trail_frame =  2 };
    case 0x896b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xee0b, .x_radius =  8, .y_radius =  8, .trail_frame =  3 };
    case 0x8973: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x8953 };
    case 0x8977: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd796, .x_radius = 12, .y_radius =  8, .trail_frame =  0 };
    case 0x897f: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd7c2, .x_radius = 12, .y_radius =  8, .trail_frame =  1 };
    case 0x8987: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd822, .x_radius = 20, .y_radius =  8, .trail_frame =  2 };
    case 0x898f: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x8987 };
    case 0x8993: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd10e, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x899b: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd124, .x_radius = 12, .y_radius = 12, .trail_frame =  1 };
    case 0x89a3: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd1de, .x_radius = 16, .y_radius = 16, .trail_frame =  2 };
    case 0x89ab: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x89a3 };
    case 0x89af: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd842, .x_radius =  8, .y_radius = 12, .trail_frame =  0 };
    case 0x89b7: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd86e, .x_radius =  8, .y_radius = 12, .trail_frame =  1 };
    case 0x89bf: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd8ce, .x_radius =  8, .y_radius = 20, .trail_frame =  2 };
    case 0x89c7: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x89bf };
    case 0x89cb: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd25a, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x89d3: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd270, .x_radius = 12, .y_radius = 12, .trail_frame =  1 };
    case 0x89db: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd32a, .x_radius = 16, .y_radius = 16, .trail_frame =  2 };
    case 0x89e3: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x89db };
    case 0x89e7: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd63e, .x_radius = 12, .y_radius =  8, .trail_frame =  0 };
    case 0x89ef: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd66a, .x_radius = 12, .y_radius =  8, .trail_frame =  1 };
    case 0x89f7: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd6ca, .x_radius = 20, .y_radius =  8, .trail_frame =  2 };
    case 0x89ff: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x89f7 };
    case 0x8a03: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd3a6, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x8a0b: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd3bc, .x_radius = 12, .y_radius = 12, .trail_frame =  1 };
    case 0x8a13: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd476, .x_radius = 16, .y_radius = 16, .trail_frame =  2 };
    case 0x8a1b: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x8a13 };
    case 0x8a1f: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd6ea, .x_radius =  8, .y_radius = 12, .trail_frame =  0 };
    case 0x8a27: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd716, .x_radius =  8, .y_radius = 12, .trail_frame =  1 };
    case 0x8a2f: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd776, .x_radius =  8, .y_radius = 20, .trail_frame =  2 };
    case 0x8a37: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x8a2f };
    case 0x8a3b: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd4f2, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x8a43: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd508, .x_radius = 12, .y_radius = 12, .trail_frame =  1 };
    case 0x8a4b: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd5c2, .x_radius = 16, .y_radius = 16, .trail_frame =  2 };
    case 0x8a53: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x8a4b };
    case 0x8a57: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd796, .x_radius = 12, .y_radius =  8, .trail_frame =  0 };
    case 0x8a5f: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd7a2, .x_radius = 12, .y_radius =  8, .trail_frame =  1 };
    case 0x8a67: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd7c2, .x_radius = 12, .y_radius =  8, .trail_frame =  2 };
    case 0x8a6f: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd7e2, .x_radius = 17, .y_radius =  8, .trail_frame =  3 };
    case 0x8a77: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd802, .x_radius = 19, .y_radius =  8, .trail_frame =  4 };
    case 0x8a7f: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd822, .x_radius = 20, .y_radius =  8, .trail_frame =  5 };
    case 0x8a87: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd802, .x_radius = 19, .y_radius =  8, .trail_frame =  6 };
    case 0x8a8f: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd7e2, .x_radius = 17, .y_radius =  8, .trail_frame =  7 };
    case 0x8a97: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd7c2, .x_radius = 12, .y_radius =  8, .trail_frame =  8 };
    case 0x8a9f: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd7a2, .x_radius = 12, .y_radius =  8, .trail_frame =  9 };
    case 0x8aa7: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x8a57 };
    case 0x8aab: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd10e, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x8ab3: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd21c, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case 0x8abb: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd124, .x_radius = 12, .y_radius = 12, .trail_frame =  2 };
    case 0x8ac3: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd162, .x_radius = 16, .y_radius = 16, .trail_frame =  3 };
    case 0x8acb: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd1a0, .x_radius = 16, .y_radius = 16, .trail_frame =  4 };
    case 0x8ad3: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd1de, .x_radius = 16, .y_radius = 16, .trail_frame =  5 };
    case 0x8adb: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd1a0, .x_radius = 16, .y_radius = 16, .trail_frame =  6 };
    case 0x8ae3: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd162, .x_radius = 16, .y_radius = 16, .trail_frame =  7 };
    case 0x8aeb: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd124, .x_radius = 12, .y_radius = 12, .trail_frame =  8 };
    case 0x8af3: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd21c, .x_radius =  8, .y_radius =  8, .trail_frame =  9 };
    case 0x8afb: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x8aab };
    case 0x8aff: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd842, .x_radius =  8, .y_radius = 12, .trail_frame =  0 };
    case 0x8b07: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd84e, .x_radius =  8, .y_radius = 12, .trail_frame =  1 };
    case 0x8b0f: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd86e, .x_radius =  8, .y_radius = 12, .trail_frame =  2 };
    case 0x8b17: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd88e, .x_radius =  8, .y_radius = 17, .trail_frame =  3 };
    case 0x8b1f: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd8ae, .x_radius =  8, .y_radius = 19, .trail_frame =  4 };
    case 0x8b27: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd8ce, .x_radius =  8, .y_radius = 20, .trail_frame =  5 };
    case 0x8b2f: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd8ae, .x_radius =  8, .y_radius = 19, .trail_frame =  6 };
    case 0x8b37: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd88e, .x_radius =  8, .y_radius = 17, .trail_frame =  7 };
    case 0x8b3f: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd86e, .x_radius =  8, .y_radius = 12, .trail_frame =  8 };
    case 0x8b47: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd84e, .x_radius =  8, .y_radius = 12, .trail_frame =  9 };
    case 0x8b4f: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x8aff };
    case 0x8b53: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd25a, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x8b5b: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd368, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case 0x8b63: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd270, .x_radius = 12, .y_radius = 12, .trail_frame =  2 };
    case 0x8b6b: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd2ae, .x_radius = 16, .y_radius = 16, .trail_frame =  3 };
    case 0x8b73: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd2ec, .x_radius = 16, .y_radius = 16, .trail_frame =  4 };
    case 0x8b7b: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd32a, .x_radius = 16, .y_radius = 16, .trail_frame =  5 };
    case 0x8b83: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd2ec, .x_radius = 16, .y_radius = 16, .trail_frame =  6 };
    case 0x8b8b: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd2ae, .x_radius = 16, .y_radius = 16, .trail_frame =  7 };
    case 0x8b93: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd270, .x_radius = 12, .y_radius = 12, .trail_frame =  8 };
    case 0x8b9b: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd368, .x_radius =  8, .y_radius =  8, .trail_frame =  9 };
    case 0x8ba3: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x8b53 };
    case 0x8ba7: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd63e, .x_radius = 12, .y_radius =  8, .trail_frame =  0 };
    case 0x8baf: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd64a, .x_radius = 12, .y_radius =  8, .trail_frame =  1 };
    case 0x8bb7: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd66a, .x_radius = 12, .y_radius =  8, .trail_frame =  2 };
    case 0x8bbf: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd68a, .x_radius = 17, .y_radius =  8, .trail_frame =  3 };
    case 0x8bc7: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd6aa, .x_radius = 19, .y_radius =  8, .trail_frame =  4 };
    case 0x8bcf: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd6ca, .x_radius = 20, .y_radius =  8, .trail_frame =  5 };
    case 0x8bd7: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd6aa, .x_radius = 19, .y_radius =  8, .trail_frame =  6 };
    case 0x8bdf: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd68a, .x_radius = 17, .y_radius =  8, .trail_frame =  7 };
    case 0x8be7: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd66a, .x_radius = 12, .y_radius =  8, .trail_frame =  8 };
    case 0x8bef: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd64a, .x_radius = 12, .y_radius =  8, .trail_frame =  9 };
    case 0x8bf7: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x8ba7 };
    case 0x8bfb: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd3a6, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x8c03: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd3bc, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case 0x8c0b: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd3fa, .x_radius = 12, .y_radius = 12, .trail_frame =  2 };
    case 0x8c13: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd438, .x_radius = 16, .y_radius = 16, .trail_frame =  3 };
    case 0x8c1b: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd476, .x_radius = 16, .y_radius = 16, .trail_frame =  4 };
    case 0x8c23: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd476, .x_radius = 16, .y_radius = 16, .trail_frame =  5 };
    case 0x8c2b: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd476, .x_radius = 16, .y_radius = 16, .trail_frame =  6 };
    case 0x8c33: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd438, .x_radius = 16, .y_radius = 16, .trail_frame =  7 };
    case 0x8c3b: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd3fa, .x_radius = 12, .y_radius = 12, .trail_frame =  8 };
    case 0x8c43: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd3bc, .x_radius =  8, .y_radius =  8, .trail_frame =  9 };
    case 0x8c4b: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x8bfb };
    case 0x8c4f: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd6ea, .x_radius =  8, .y_radius = 12, .trail_frame =  0 };
    case 0x8c57: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd6f6, .x_radius =  8, .y_radius = 12, .trail_frame =  1 };
    case 0x8c5f: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd716, .x_radius =  8, .y_radius = 12, .trail_frame =  2 };
    case 0x8c67: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd736, .x_radius =  8, .y_radius = 17, .trail_frame =  3 };
    case 0x8c6f: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd756, .x_radius =  8, .y_radius = 19, .trail_frame =  4 };
    case 0x8c77: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd776, .x_radius =  8, .y_radius = 20, .trail_frame =  5 };
    case 0x8c7f: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd756, .x_radius =  8, .y_radius = 19, .trail_frame =  6 };
    case 0x8c87: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd736, .x_radius =  8, .y_radius = 17, .trail_frame =  7 };
    case 0x8c8f: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd716, .x_radius =  8, .y_radius = 12, .trail_frame =  8 };
    case 0x8c97: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd6f6, .x_radius =  8, .y_radius = 12, .trail_frame =  9 };
    case 0x8c9f: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x8c4f };
    case 0x8ca3: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd4f2, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x8cab: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd600, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case 0x8cb3: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd508, .x_radius = 12, .y_radius = 12, .trail_frame =  2 };
    case 0x8cbb: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd546, .x_radius = 16, .y_radius = 16, .trail_frame =  3 };
    case 0x8cc3: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd584, .x_radius = 16, .y_radius = 16, .trail_frame =  4 };
    case 0x8ccb: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd5c2, .x_radius = 16, .y_radius = 16, .trail_frame =  5 };
    case 0x8cd3: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd584, .x_radius = 16, .y_radius = 16, .trail_frame =  6 };
    case 0x8cdb: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd546, .x_radius = 16, .y_radius = 16, .trail_frame =  7 };
    case 0x8ce3: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd508, .x_radius = 12, .y_radius = 12, .trail_frame =  8 };
    case 0x8ceb: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xd600, .x_radius =  8, .y_radius =  8, .trail_frame =  9 };
    case 0x8cf3: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x8ca3 };
    case 0x8cf7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf194, .x_radius =  8, .y_radius = 16, .trail_frame =  0 };
    case 0x8cff: return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xa3b3, .x_radius =  8, .y_radius = 16, .trail_frame =  1 };
    case 0x8d07: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x8cff };
    case 0x8d0b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf2ce, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x8d13: return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xa3c9, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case 0x8d1b: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x8d13 };
    case 0x8d1f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf0fa, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x8d27: return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xa37d, .x_radius = 16, .y_radius =  8, .trail_frame =  1 };
    case 0x8d2f: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x8d27 };
    case 0x8d33: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf22e, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x8d3b: return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xa393, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case 0x8d43: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x8d3b };
    case 0x8d47: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf194, .x_radius = 12, .y_radius = 16, .trail_frame =  0 };
    case 0x8d4f: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xc0f1, .x_radius = 12, .y_radius = 16, .trail_frame =  1 };
    case 0x8d57: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xc107, .x_radius = 12, .y_radius = 16, .trail_frame =  2 };
    case 0x8d5f: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xc131, .x_radius = 17, .y_radius = 16, .trail_frame =  3 };
    case 0x8d67: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xc15b, .x_radius = 19, .y_radius = 16, .trail_frame =  4 };
    case 0x8d6f: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xc185, .x_radius = 20, .y_radius = 16, .trail_frame =  5 };
    case 0x8d77: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xc15b, .x_radius = 19, .y_radius = 16, .trail_frame =  6 };
    case 0x8d7f: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xc131, .x_radius = 17, .y_radius = 16, .trail_frame =  7 };
    case 0x8d87: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xc107, .x_radius = 12, .y_radius = 16, .trail_frame =  8 };
    case 0x8d8f: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x8d4f };
    case 0x8d93: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf2ce, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x8d9b: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xce2a, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case 0x8da3: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xce4a, .x_radius = 12, .y_radius = 12, .trail_frame =  2 };
    case 0x8dab: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xce88, .x_radius = 16, .y_radius = 16, .trail_frame =  3 };
    case 0x8db3: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xcec6, .x_radius = 16, .y_radius = 16, .trail_frame =  4 };
    case 0x8dbb: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xcf04, .x_radius = 20, .y_radius = 20, .trail_frame =  5 };
    case 0x8dc3: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xcec6, .x_radius = 16, .y_radius = 16, .trail_frame =  6 };
    case 0x8dcb: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xce88, .x_radius = 16, .y_radius = 16, .trail_frame =  7 };
    case 0x8dd3: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xce4a, .x_radius = 12, .y_radius = 12, .trail_frame =  8 };
    case 0x8ddb: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x8d9b };
    case 0x8ddf: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf0fa, .x_radius =  8, .y_radius = 12, .trail_frame =  0 };
    case 0x8de7: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xbc0a, .x_radius = 16, .y_radius = 12, .trail_frame =  1 };
    case 0x8def: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xbc20, .x_radius = 16, .y_radius = 12, .trail_frame =  2 };
    case 0x8df7: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xbc4a, .x_radius = 16, .y_radius = 17, .trail_frame =  3 };
    case 0x8dff: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xbc74, .x_radius = 16, .y_radius = 19, .trail_frame =  4 };
    case 0x8e07: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xbc9e, .x_radius = 16, .y_radius = 20, .trail_frame =  5 };
    case 0x8e0f: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xbc74, .x_radius = 16, .y_radius = 19, .trail_frame =  6 };
    case 0x8e17: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xbc4a, .x_radius = 16, .y_radius = 17, .trail_frame =  7 };
    case 0x8e1f: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xbc20, .x_radius = 16, .y_radius = 12, .trail_frame =  8 };
    case 0x8e27: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x8de7 };
    case 0x8e2b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf22e, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x8e33: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xbe0d, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case 0x8e3b: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xbe2d, .x_radius = 12, .y_radius = 12, .trail_frame =  2 };
    case 0x8e43: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xbe6b, .x_radius = 16, .y_radius = 16, .trail_frame =  3 };
    case 0x8e4b: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xbea9, .x_radius = 16, .y_radius = 16, .trail_frame =  4 };
    case 0x8e53: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xbee7, .x_radius = 20, .y_radius = 20, .trail_frame =  5 };
    case 0x8e5b: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xbea9, .x_radius = 16, .y_radius = 16, .trail_frame =  6 };
    case 0x8e63: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xbe6b, .x_radius = 16, .y_radius = 16, .trail_frame =  7 };
    case 0x8e6b: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xbe2d, .x_radius = 12, .y_radius = 12, .trail_frame =  8 };
    case 0x8e73: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x8e33 };
    case 0x8e77: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xec6a, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x8e7f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xed1a, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case 0x8e87: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x8e77 };
    case 0x8e8b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xec80, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x8e93: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xed30, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case 0x8e9b: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x8e8b };
    case 0x8e9f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xec96, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x8ea7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xed46, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case 0x8eaf: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x8e9f };
    case 0x8eb3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xecac, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x8ebb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xed5c, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case 0x8ec3: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x8eb3 };
    case 0x8ec7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xecc2, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x8ecf: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xed72, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case 0x8ed7: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x8ec7 };
    case 0x8edb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xecd8, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x8ee3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xed88, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case 0x8eeb: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x8edb };
    case 0x8eef: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xec3e, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x8ef7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xecee, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case 0x8eff: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x8eef };
    case 0x8f03: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xec54, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x8f0b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xed04, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case 0x8f13: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x8f03 };
    case 0x8f17: return (ProjectileInstr){ .timer =  3, .spritemap_ptr = 0xa117, .x_radius = 12, .y_radius =  8, .trail_frame =  0 };
    case 0x8f1f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf4c, .x_radius = 12, .y_radius =  8, .trail_frame =  0 };
    case 0x8f27: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf62, .x_radius = 12, .y_radius =  8, .trail_frame =  1 };
    case 0x8f2f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb394, .x_radius = 16, .y_radius =  8, .trail_frame =  2 };
    case 0x8f37: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb3be, .x_radius = 16, .y_radius =  8, .trail_frame =  3 };
    case 0x8f3f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb3e8, .x_radius = 20, .y_radius =  8, .trail_frame =  4 };
    case 0x8f47: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb412, .x_radius = 20, .y_radius =  8, .trail_frame =  5 };
    case 0x8f4f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb43c, .x_radius = 23, .y_radius =  8, .trail_frame =  6 };
    case 0x8f57: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb466, .x_radius = 23, .y_radius =  8, .trail_frame =  7 };
    case 0x8f5f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb490, .x_radius = 24, .y_radius =  8, .trail_frame =  8 };
    case 0x8f67: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb4ba, .x_radius = 24, .y_radius =  8, .trail_frame =  9 };
    case 0x8f6f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb43c, .x_radius = 23, .y_radius =  8, .trail_frame = 10 };
    case 0x8f77: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb466, .x_radius = 23, .y_radius =  8, .trail_frame = 11 };
    case 0x8f7f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb3e8, .x_radius = 20, .y_radius =  8, .trail_frame = 12 };
    case 0x8f87: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb412, .x_radius = 20, .y_radius =  8, .trail_frame = 13 };
    case 0x8f8f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb3be, .x_radius = 16, .y_radius =  8, .trail_frame = 14 };
    case 0x8f97: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb394, .x_radius = 16, .y_radius =  8, .trail_frame = 15 };
    case 0x8f9f: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x8f1f };
    case 0x8fa3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf4c, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x8fab: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf62, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case 0x8fb3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb218, .x_radius = 12, .y_radius = 12, .trail_frame =  2 };
    case 0x8fbb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb242, .x_radius = 12, .y_radius = 12, .trail_frame =  3 };
    case 0x8fc3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb26c, .x_radius = 16, .y_radius = 16, .trail_frame =  4 };
    case 0x8fcb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb296, .x_radius = 16, .y_radius = 16, .trail_frame =  5 };
    case 0x8fd3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb2c0, .x_radius = 17, .y_radius = 17, .trail_frame =  6 };
    case 0x8fdb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb2ea, .x_radius = 17, .y_radius = 17, .trail_frame =  7 };
    case 0x8fe3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb314, .x_radius = 18, .y_radius = 18, .trail_frame =  8 };
    case 0x8feb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb33e, .x_radius = 18, .y_radius = 18, .trail_frame =  9 };
    case 0x8ff3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb2c0, .x_radius = 17, .y_radius = 17, .trail_frame = 10 };
    case 0x8ffb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb2ea, .x_radius = 17, .y_radius = 17, .trail_frame = 11 };
    case 0x9003: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb26c, .x_radius = 16, .y_radius = 16, .trail_frame = 12 };
    case 0x900b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb296, .x_radius = 16, .y_radius = 16, .trail_frame = 13 };
    case 0x9013: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb218, .x_radius = 12, .y_radius = 12, .trail_frame = 14 };
    case 0x901b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb242, .x_radius = 12, .y_radius = 12, .trail_frame = 15 };
    case 0x9023: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x8fa3 };
    case 0x9027: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf4c, .x_radius =  8, .y_radius = 12, .trail_frame =  0 };
    case 0x902f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf62, .x_radius =  8, .y_radius = 12, .trail_frame =  1 };
    case 0x9037: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf78, .x_radius =  8, .y_radius = 16, .trail_frame =  2 };
    case 0x903f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xafa2, .x_radius =  8, .y_radius = 16, .trail_frame =  3 };
    case 0x9047: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xafcc, .x_radius =  8, .y_radius = 20, .trail_frame =  4 };
    case 0x904f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaff6, .x_radius =  8, .y_radius = 20, .trail_frame =  5 };
    case 0x9057: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb020, .x_radius =  8, .y_radius = 23, .trail_frame =  6 };
    case 0x905f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb04a, .x_radius =  8, .y_radius = 23, .trail_frame =  7 };
    case 0x9067: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb074, .x_radius =  8, .y_radius = 24, .trail_frame =  8 };
    case 0x906f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb09e, .x_radius =  8, .y_radius = 24, .trail_frame =  9 };
    case 0x9077: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb020, .x_radius =  8, .y_radius = 23, .trail_frame = 10 };
    case 0x907f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb04a, .x_radius =  8, .y_radius = 23, .trail_frame = 11 };
    case 0x9087: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xafcc, .x_radius =  8, .y_radius = 20, .trail_frame = 12 };
    case 0x908f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaff6, .x_radius =  8, .y_radius = 20, .trail_frame = 13 };
    case 0x9097: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xafa2, .x_radius =  8, .y_radius = 16, .trail_frame = 14 };
    case 0x909f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf78, .x_radius =  8, .y_radius = 16, .trail_frame = 15 };
    case 0x90a7: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x9027 };
    case 0x90ab: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf4c, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x90b3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaf62, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case 0x90bb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb0c8, .x_radius = 12, .y_radius = 12, .trail_frame =  2 };
    case 0x90c3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb0f2, .x_radius = 12, .y_radius = 12, .trail_frame =  3 };
    case 0x90cb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb11c, .x_radius = 16, .y_radius = 16, .trail_frame =  4 };
    case 0x90d3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb146, .x_radius = 16, .y_radius = 16, .trail_frame =  5 };
    case 0x90db: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb170, .x_radius = 17, .y_radius = 17, .trail_frame =  6 };
    case 0x90e3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb19a, .x_radius = 17, .y_radius = 17, .trail_frame =  7 };
    case 0x90eb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb1c4, .x_radius = 18, .y_radius = 18, .trail_frame =  8 };
    case 0x90f3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb1ee, .x_radius = 18, .y_radius = 18, .trail_frame =  9 };
    case 0x90fb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb170, .x_radius = 17, .y_radius = 17, .trail_frame = 10 };
    case 0x9103: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb19a, .x_radius = 17, .y_radius = 17, .trail_frame = 11 };
    case 0x910b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb11c, .x_radius = 16, .y_radius = 16, .trail_frame = 12 };
    case 0x9113: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb146, .x_radius = 16, .y_radius = 16, .trail_frame = 13 };
    case 0x911b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb0c8, .x_radius = 12, .y_radius = 12, .trail_frame = 14 };
    case 0x9123: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb0f2, .x_radius = 12, .y_radius = 12, .trail_frame = 15 };
    case 0x912b: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x90ab };
    case 0x912f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xed9e, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x9137: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xedb4, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case 0x913f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xedca, .x_radius =  8, .y_radius =  8, .trail_frame =  2 };
    case 0x9147: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xede0, .x_radius =  8, .y_radius =  8, .trail_frame =  3 };
    case 0x914f: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x912f };
    case 0x9153: return (ProjectileInstr){ .timer =  3, .spritemap_ptr = 0xa117, .x_radius = 12, .y_radius =  8, .trail_frame =  0 };
    case 0x915b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb672, .x_radius = 12, .y_radius =  8, .trail_frame =  0 };
    case 0x9163: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb688, .x_radius = 12, .y_radius =  8, .trail_frame =  1 };
    case 0x916b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbaba, .x_radius = 16, .y_radius =  8, .trail_frame =  2 };
    case 0x9173: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbae4, .x_radius = 16, .y_radius =  8, .trail_frame =  3 };
    case 0x917b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbb0e, .x_radius = 20, .y_radius =  8, .trail_frame =  4 };
    case 0x9183: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbb38, .x_radius = 20, .y_radius =  8, .trail_frame =  5 };
    case 0x918b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbb62, .x_radius = 23, .y_radius =  8, .trail_frame =  6 };
    case 0x9193: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbb8c, .x_radius = 23, .y_radius =  8, .trail_frame =  7 };
    case 0x919b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbbb6, .x_radius = 24, .y_radius =  8, .trail_frame =  8 };
    case 0x91a3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbbe0, .x_radius = 24, .y_radius =  8, .trail_frame =  9 };
    case 0x91ab: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbb62, .x_radius = 23, .y_radius =  8, .trail_frame = 10 };
    case 0x91b3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbb8c, .x_radius = 23, .y_radius =  8, .trail_frame = 11 };
    case 0x91bb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbb0e, .x_radius = 20, .y_radius =  8, .trail_frame = 12 };
    case 0x91c3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbb38, .x_radius = 20, .y_radius =  8, .trail_frame = 13 };
    case 0x91cb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbae4, .x_radius = 16, .y_radius =  8, .trail_frame = 14 };
    case 0x91d3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbaba, .x_radius = 16, .y_radius =  8, .trail_frame = 15 };
    case 0x91db: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x915b };
    case 0x91df: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb672, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x91e7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb688, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case 0x91ef: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb93e, .x_radius = 12, .y_radius = 12, .trail_frame =  2 };
    case 0x91f7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb968, .x_radius = 12, .y_radius = 12, .trail_frame =  3 };
    case 0x91ff: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb992, .x_radius = 16, .y_radius = 16, .trail_frame =  4 };
    case 0x9207: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb9bc, .x_radius = 16, .y_radius = 16, .trail_frame =  5 };
    case 0x920f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb9e6, .x_radius = 17, .y_radius = 17, .trail_frame =  6 };
    case 0x9217: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xba10, .x_radius = 17, .y_radius = 17, .trail_frame =  7 };
    case 0x921f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xba3a, .x_radius = 18, .y_radius = 18, .trail_frame =  8 };
    case 0x9227: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xba64, .x_radius = 18, .y_radius = 18, .trail_frame =  9 };
    case 0x922f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb9e6, .x_radius = 17, .y_radius = 17, .trail_frame = 10 };
    case 0x9237: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xba10, .x_radius = 17, .y_radius = 17, .trail_frame = 11 };
    case 0x923f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb992, .x_radius = 16, .y_radius = 16, .trail_frame = 12 };
    case 0x9247: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb9bc, .x_radius = 16, .y_radius = 16, .trail_frame = 13 };
    case 0x924f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb93e, .x_radius = 12, .y_radius = 12, .trail_frame = 14 };
    case 0x9257: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb968, .x_radius = 12, .y_radius = 12, .trail_frame = 15 };
    case 0x925f: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x91df };
    case 0x9263: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb672, .x_radius =  8, .y_radius = 12, .trail_frame =  0 };
    case 0x926b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb688, .x_radius =  8, .y_radius = 12, .trail_frame =  1 };
    case 0x9273: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb69e, .x_radius =  8, .y_radius = 16, .trail_frame =  2 };
    case 0x927b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb6c8, .x_radius =  8, .y_radius = 16, .trail_frame =  3 };
    case 0x9283: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb6f2, .x_radius =  8, .y_radius = 20, .trail_frame =  4 };
    case 0x928b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb71c, .x_radius =  8, .y_radius = 20, .trail_frame =  5 };
    case 0x9293: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb746, .x_radius =  8, .y_radius = 23, .trail_frame =  6 };
    case 0x929b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb770, .x_radius =  8, .y_radius = 23, .trail_frame =  7 };
    case 0x92a3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb79a, .x_radius =  8, .y_radius = 24, .trail_frame =  8 };
    case 0x92ab: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb7c4, .x_radius =  8, .y_radius = 24, .trail_frame =  9 };
    case 0x92b3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb746, .x_radius =  8, .y_radius = 23, .trail_frame = 10 };
    case 0x92bb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb770, .x_radius =  8, .y_radius = 23, .trail_frame = 11 };
    case 0x92c3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb6f2, .x_radius =  8, .y_radius = 20, .trail_frame = 12 };
    case 0x92cb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb71c, .x_radius =  8, .y_radius = 20, .trail_frame = 13 };
    case 0x92d3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb6c8, .x_radius =  8, .y_radius = 16, .trail_frame = 14 };
    case 0x92db: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb69e, .x_radius =  8, .y_radius = 16, .trail_frame = 15 };
    case 0x92e3: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x9263 };
    case 0x92e7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb672, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x92ef: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb688, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case 0x92f7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb7ee, .x_radius = 12, .y_radius = 12, .trail_frame =  2 };
    case 0x92ff: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb818, .x_radius = 12, .y_radius = 12, .trail_frame =  3 };
    case 0x9307: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb842, .x_radius = 16, .y_radius = 16, .trail_frame =  4 };
    case 0x930f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb86c, .x_radius = 16, .y_radius = 16, .trail_frame =  5 };
    case 0x9317: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb896, .x_radius = 17, .y_radius = 17, .trail_frame =  6 };
    case 0x931f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb8c0, .x_radius = 17, .y_radius = 17, .trail_frame =  7 };
    case 0x9327: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb8ea, .x_radius = 18, .y_radius = 18, .trail_frame =  8 };
    case 0x932f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb914, .x_radius = 18, .y_radius = 18, .trail_frame =  9 };
    case 0x9337: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb896, .x_radius = 17, .y_radius = 17, .trail_frame = 10 };
    case 0x933f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb8c0, .x_radius = 17, .y_radius = 17, .trail_frame = 11 };
    case 0x9347: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb842, .x_radius = 16, .y_radius = 16, .trail_frame = 12 };
    case 0x934f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb86c, .x_radius = 16, .y_radius = 16, .trail_frame = 13 };
    case 0x9357: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb7ee, .x_radius = 12, .y_radius = 12, .trail_frame = 14 };
    case 0x935f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xb818, .x_radius = 12, .y_radius = 12, .trail_frame = 15 };
    case 0x9367: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x92e7 };
    case 0x936b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xee8e, .x_radius = 12, .y_radius =  8, .trail_frame =  0 };
    case 0x9373: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf07e, .x_radius = 12, .y_radius =  8, .trail_frame =  1 };
    case 0x937b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xee95, .x_radius = 12, .y_radius =  8, .trail_frame =  2 };
    case 0x9383: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf085, .x_radius = 12, .y_radius =  8, .trail_frame =  3 };
    case 0x938b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe9a6, .x_radius = 12, .y_radius = 16, .trail_frame =  4 };
    case 0x9393: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xda3a, .x_radius = 12, .y_radius = 16, .trail_frame =  5 };
    case 0x939b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe9fa, .x_radius = 12, .y_radius = 16, .trail_frame =  6 };
    case 0x93a3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xda8e, .x_radius = 12, .y_radius = 16, .trail_frame =  7 };
    case 0x93ab: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xeab4, .x_radius = 20, .y_radius = 16, .trail_frame =  8 };
    case 0x93b3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdb48, .x_radius = 20, .y_radius = 16, .trail_frame =  9 };
    case 0x93bb: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x93ab };
    case 0x93bf: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xeec8, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x93c7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf0b8, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case 0x93cf: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xeed4, .x_radius =  8, .y_radius =  8, .trail_frame =  2 };
    case 0x93d7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf0c4, .x_radius =  8, .y_radius =  8, .trail_frame =  3 };
    case 0x93df: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdf5e, .x_radius = 12, .y_radius = 12, .trail_frame =  4 };
    case 0x93e7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdd72, .x_radius = 12, .y_radius = 12, .trail_frame =  5 };
    case 0x93ef: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdf7e, .x_radius = 16, .y_radius = 16, .trail_frame =  6 };
    case 0x93f7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xddee, .x_radius = 16, .y_radius = 16, .trail_frame =  7 };
    case 0x93ff: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe092, .x_radius = 20, .y_radius = 20, .trail_frame =  8 };
    case 0x9407: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdf02, .x_radius = 20, .y_radius = 20, .trail_frame =  9 };
    case 0x940f: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x93ff };
    case 0x9413: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xef0a, .x_radius =  8, .y_radius = 12, .trail_frame =  0 };
    case 0x941b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf002, .x_radius =  8, .y_radius = 12, .trail_frame =  1 };
    case 0x9423: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xef11, .x_radius =  8, .y_radius = 12, .trail_frame =  2 };
    case 0x942b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf009, .x_radius =  8, .y_radius = 12, .trail_frame =  3 };
    case 0x9433: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe85a, .x_radius = 16, .y_radius = 12, .trail_frame =  4 };
    case 0x943b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd8ee, .x_radius = 16, .y_radius = 12, .trail_frame =  5 };
    case 0x9443: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe8ae, .x_radius = 16, .y_radius = 12, .trail_frame =  6 };
    case 0x944b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd942, .x_radius = 16, .y_radius = 12, .trail_frame =  7 };
    case 0x9453: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe968, .x_radius = 16, .y_radius = 20, .trail_frame =  8 };
    case 0x945b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd9fc, .x_radius = 16, .y_radius = 20, .trail_frame =  9 };
    case 0x9463: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x9453 };
    case 0x9467: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xef44, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x946f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf03c, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case 0x9477: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xef50, .x_radius =  8, .y_radius =  8, .trail_frame =  2 };
    case 0x947f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf048, .x_radius =  8, .y_radius =  8, .trail_frame =  3 };
    case 0x9487: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe14a, .x_radius = 12, .y_radius = 12, .trail_frame =  4 };
    case 0x948f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdb86, .x_radius = 12, .y_radius = 12, .trail_frame =  5 };
    case 0x9497: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe16a, .x_radius = 16, .y_radius = 16, .trail_frame =  6 };
    case 0x949f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdc02, .x_radius = 16, .y_radius = 16, .trail_frame =  7 };
    case 0x94a7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe27e, .x_radius = 20, .y_radius = 20, .trail_frame =  8 };
    case 0x94af: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdd16, .x_radius = 20, .y_radius = 20, .trail_frame =  9 };
    case 0x94b7: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x94a7 };
    case 0x94bb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xee8e, .x_radius = 12, .y_radius =  8, .trail_frame =  0 };
    case 0x94c3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf07e, .x_radius = 12, .y_radius =  8, .trail_frame =  1 };
    case 0x94cb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xee95, .x_radius = 12, .y_radius =  8, .trail_frame =  2 };
    case 0x94d3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf085, .x_radius = 12, .y_radius =  8, .trail_frame =  3 };
    case 0x94db: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe9a6, .x_radius = 12, .y_radius = 16, .trail_frame =  4 };
    case 0x94e3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xda3a, .x_radius = 12, .y_radius = 16, .trail_frame =  5 };
    case 0x94eb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe9bc, .x_radius = 12, .y_radius = 16, .trail_frame =  6 };
    case 0x94f3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xda50, .x_radius = 12, .y_radius = 16, .trail_frame =  7 };
    case 0x94fb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe9fa, .x_radius = 12, .y_radius = 16, .trail_frame =  8 };
    case 0x9503: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xda8e, .x_radius = 12, .y_radius = 16, .trail_frame =  9 };
    case 0x950b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xea38, .x_radius = 16, .y_radius = 16, .trail_frame = 10 };
    case 0x9513: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdacc, .x_radius = 16, .y_radius = 16, .trail_frame = 11 };
    case 0x951b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xea76, .x_radius = 18, .y_radius = 16, .trail_frame = 12 };
    case 0x9523: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdb0a, .x_radius = 18, .y_radius = 16, .trail_frame = 13 };
    case 0x952b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xeab4, .x_radius = 20, .y_radius = 16, .trail_frame = 14 };
    case 0x9533: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdb48, .x_radius = 20, .y_radius = 16, .trail_frame = 15 };
    case 0x953b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xea76, .x_radius = 18, .y_radius = 16, .trail_frame = 16 };
    case 0x9543: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdb0a, .x_radius = 18, .y_radius = 16, .trail_frame = 17 };
    case 0x954b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xea38, .x_radius = 16, .y_radius = 16, .trail_frame = 18 };
    case 0x9553: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdacc, .x_radius = 16, .y_radius = 16, .trail_frame = 19 };
    case 0x955b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe9fa, .x_radius = 12, .y_radius = 16, .trail_frame = 20 };
    case 0x9563: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xda8e, .x_radius = 12, .y_radius = 16, .trail_frame = 21 };
    case 0x956b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe9bc, .x_radius =  8, .y_radius = 16, .trail_frame = 22 };
    case 0x9573: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xda50, .x_radius =  8, .y_radius = 16, .trail_frame = 23 };
    case 0x957b: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x94db };
    case 0x957f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xeec8, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x9587: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf0b8, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case 0x958f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xeed4, .x_radius =  8, .y_radius =  8, .trail_frame =  2 };
    case 0x9597: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf0c4, .x_radius =  8, .y_radius =  8, .trail_frame =  3 };
    case 0x959f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdf5e, .x_radius = 12, .y_radius = 12, .trail_frame =  4 };
    case 0x95a7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdd72, .x_radius = 12, .y_radius = 12, .trail_frame =  5 };
    case 0x95af: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe0ee, .x_radius = 12, .y_radius = 12, .trail_frame =  6 };
    case 0x95b7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdd92, .x_radius = 12, .y_radius = 12, .trail_frame =  7 };
    case 0x95bf: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdf7e, .x_radius = 16, .y_radius = 16, .trail_frame =  8 };
    case 0x95c7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xddee, .x_radius = 16, .y_radius = 16, .trail_frame =  9 };
    case 0x95cf: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdfda, .x_radius = 16, .y_radius = 16, .trail_frame = 10 };
    case 0x95d7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xde4a, .x_radius = 16, .y_radius = 16, .trail_frame = 11 };
    case 0x95df: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe036, .x_radius = 16, .y_radius = 16, .trail_frame = 12 };
    case 0x95e7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdea6, .x_radius = 16, .y_radius = 16, .trail_frame = 13 };
    case 0x95ef: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe092, .x_radius = 20, .y_radius = 20, .trail_frame = 14 };
    case 0x95f7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdf02, .x_radius = 20, .y_radius = 20, .trail_frame = 15 };
    case 0x95ff: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe036, .x_radius = 16, .y_radius = 16, .trail_frame = 16 };
    case 0x9607: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdea6, .x_radius = 16, .y_radius = 16, .trail_frame = 17 };
    case 0x960f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdfda, .x_radius = 16, .y_radius = 16, .trail_frame = 18 };
    case 0x9617: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xde4a, .x_radius = 16, .y_radius = 16, .trail_frame = 19 };
    case 0x961f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdf7e, .x_radius = 16, .y_radius = 16, .trail_frame = 20 };
    case 0x9627: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xddee, .x_radius = 16, .y_radius = 16, .trail_frame = 21 };
    case 0x962f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe0ee, .x_radius = 12, .y_radius = 12, .trail_frame = 22 };
    case 0x9637: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdd92, .x_radius = 12, .y_radius = 12, .trail_frame = 23 };
    case 0x963f: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x959f };
    case 0x9643: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xef0a, .x_radius =  8, .y_radius = 12, .trail_frame =  0 };
    case 0x964b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf002, .x_radius =  8, .y_radius = 12, .trail_frame =  1 };
    case 0x9653: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xef11, .x_radius =  8, .y_radius = 12, .trail_frame =  2 };
    case 0x965b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf009, .x_radius =  8, .y_radius = 12, .trail_frame =  3 };
    case 0x9663: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xeaf2, .x_radius = 16, .y_radius = 12, .trail_frame =  4 };
    case 0x966b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd8ee, .x_radius = 16, .y_radius = 12, .trail_frame =  5 };
    case 0x9673: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xeb08, .x_radius = 16, .y_radius = 12, .trail_frame =  6 };
    case 0x967b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd904, .x_radius = 16, .y_radius = 12, .trail_frame =  7 };
    case 0x9683: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xeb46, .x_radius = 16, .y_radius = 12, .trail_frame =  8 };
    case 0x968b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd942, .x_radius = 16, .y_radius = 12, .trail_frame =  9 };
    case 0x9693: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xeb84, .x_radius = 16, .y_radius = 16, .trail_frame = 10 };
    case 0x969b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd980, .x_radius = 16, .y_radius = 16, .trail_frame = 11 };
    case 0x96a3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xebc2, .x_radius = 16, .y_radius = 18, .trail_frame = 12 };
    case 0x96ab: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd9be, .x_radius = 16, .y_radius = 18, .trail_frame = 13 };
    case 0x96b3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xec00, .x_radius = 16, .y_radius = 20, .trail_frame = 14 };
    case 0x96bb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd9fc, .x_radius = 16, .y_radius = 20, .trail_frame = 15 };
    case 0x96c3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xebc2, .x_radius = 16, .y_radius = 18, .trail_frame = 16 };
    case 0x96cb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd9be, .x_radius = 16, .y_radius = 18, .trail_frame = 17 };
    case 0x96d3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xeb84, .x_radius = 16, .y_radius = 16, .trail_frame = 18 };
    case 0x96db: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd980, .x_radius = 16, .y_radius = 16, .trail_frame = 19 };
    case 0x96e3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xeb46, .x_radius = 16, .y_radius = 12, .trail_frame = 20 };
    case 0x96eb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd942, .x_radius = 16, .y_radius = 12, .trail_frame = 21 };
    case 0x96f3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xeb08, .x_radius = 16, .y_radius =  8, .trail_frame = 22 };
    case 0x96fb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd904, .x_radius = 16, .y_radius =  8, .trail_frame = 23 };
    case 0x9703: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x9663 };
    case 0x9707: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xef44, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x970f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf03c, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case 0x9717: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xef50, .x_radius =  8, .y_radius =  8, .trail_frame =  2 };
    case 0x971f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf048, .x_radius =  8, .y_radius =  8, .trail_frame =  3 };
    case 0x9727: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe14a, .x_radius = 12, .y_radius = 12, .trail_frame =  4 };
    case 0x972f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdb86, .x_radius = 12, .y_radius = 12, .trail_frame =  5 };
    case 0x9737: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe2da, .x_radius = 12, .y_radius = 12, .trail_frame =  6 };
    case 0x973f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdba6, .x_radius = 12, .y_radius = 12, .trail_frame =  7 };
    case 0x9747: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe16a, .x_radius = 16, .y_radius = 16, .trail_frame =  8 };
    case 0x974f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdc02, .x_radius = 16, .y_radius = 16, .trail_frame =  9 };
    case 0x9757: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe1c6, .x_radius = 16, .y_radius = 16, .trail_frame = 10 };
    case 0x975f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdc5e, .x_radius = 16, .y_radius = 16, .trail_frame = 11 };
    case 0x9767: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe222, .x_radius = 16, .y_radius = 16, .trail_frame = 12 };
    case 0x976f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdcba, .x_radius = 16, .y_radius = 16, .trail_frame = 13 };
    case 0x9777: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe27e, .x_radius = 20, .y_radius = 20, .trail_frame = 14 };
    case 0x977f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdd16, .x_radius = 20, .y_radius = 20, .trail_frame = 15 };
    case 0x9787: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe222, .x_radius = 16, .y_radius = 16, .trail_frame = 16 };
    case 0x978f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdcba, .x_radius = 16, .y_radius = 16, .trail_frame = 17 };
    case 0x9797: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe1c6, .x_radius = 16, .y_radius = 16, .trail_frame = 18 };
    case 0x979f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdc5e, .x_radius = 16, .y_radius = 16, .trail_frame = 19 };
    case 0x97a7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe16a, .x_radius = 16, .y_radius = 16, .trail_frame = 20 };
    case 0x97af: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdc02, .x_radius = 16, .y_radius = 16, .trail_frame = 21 };
    case 0x97b7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe2da, .x_radius = 12, .y_radius = 12, .trail_frame = 22 };
    case 0x97bf: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdba6, .x_radius = 12, .y_radius = 12, .trail_frame = 23 };
    case 0x97c7: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x9727 };
    case 0x97cb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xef86, .x_radius = 12, .y_radius =  8, .trail_frame =  0 };
    case 0x97d3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf07e, .x_radius = 12, .y_radius =  8, .trail_frame =  1 };
    case 0x97db: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xef8d, .x_radius = 12, .y_radius =  8, .trail_frame =  2 };
    case 0x97e3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf085, .x_radius = 12, .y_radius =  8, .trail_frame =  3 };
    case 0x97eb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe70e, .x_radius = 12, .y_radius = 16, .trail_frame =  4 };
    case 0x97f3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xda3a, .x_radius = 12, .y_radius = 16, .trail_frame =  5 };
    case 0x97fb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe724, .x_radius = 12, .y_radius = 16, .trail_frame =  6 };
    case 0x9803: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xda50, .x_radius = 12, .y_radius = 16, .trail_frame =  7 };
    case 0x980b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe762, .x_radius = 12, .y_radius = 16, .trail_frame =  8 };
    case 0x9813: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xda8e, .x_radius = 12, .y_radius = 16, .trail_frame =  9 };
    case 0x981b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe7a0, .x_radius = 16, .y_radius = 16, .trail_frame = 10 };
    case 0x9823: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdacc, .x_radius = 16, .y_radius = 16, .trail_frame = 11 };
    case 0x982b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe7de, .x_radius = 18, .y_radius = 16, .trail_frame = 12 };
    case 0x9833: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdb0a, .x_radius = 18, .y_radius = 16, .trail_frame = 13 };
    case 0x983b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe81c, .x_radius = 20, .y_radius = 16, .trail_frame = 14 };
    case 0x9843: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdb48, .x_radius = 20, .y_radius = 16, .trail_frame = 15 };
    case 0x984b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe7de, .x_radius = 18, .y_radius = 16, .trail_frame = 16 };
    case 0x9853: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdb0a, .x_radius = 18, .y_radius = 16, .trail_frame = 17 };
    case 0x985b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe7a0, .x_radius = 16, .y_radius = 16, .trail_frame = 18 };
    case 0x9863: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdacc, .x_radius = 16, .y_radius = 16, .trail_frame = 19 };
    case 0x986b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe762, .x_radius = 12, .y_radius = 16, .trail_frame = 20 };
    case 0x9873: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xda8e, .x_radius = 12, .y_radius = 16, .trail_frame = 21 };
    case 0x987b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe724, .x_radius =  8, .y_radius = 16, .trail_frame = 22 };
    case 0x9883: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xda50, .x_radius =  8, .y_radius = 16, .trail_frame = 23 };
    case 0x988b: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x97eb };
    case 0x988f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xeec8, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x9897: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf0b8, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case 0x989f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xeed4, .x_radius =  8, .y_radius =  8, .trail_frame =  2 };
    case 0x98a7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf0c4, .x_radius =  8, .y_radius =  8, .trail_frame =  3 };
    case 0x98af: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe336, .x_radius = 12, .y_radius = 12, .trail_frame =  4 };
    case 0x98b7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdd72, .x_radius = 12, .y_radius = 12, .trail_frame =  5 };
    case 0x98bf: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe4c6, .x_radius = 12, .y_radius = 12, .trail_frame =  6 };
    case 0x98c7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdd92, .x_radius = 12, .y_radius = 12, .trail_frame =  7 };
    case 0x98cf: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe356, .x_radius = 16, .y_radius = 16, .trail_frame =  8 };
    case 0x98d7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xddee, .x_radius = 16, .y_radius = 16, .trail_frame =  9 };
    case 0x98df: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe3b2, .x_radius = 16, .y_radius = 16, .trail_frame = 10 };
    case 0x98e7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xde4a, .x_radius = 16, .y_radius = 16, .trail_frame = 11 };
    case 0x98ef: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe40e, .x_radius = 16, .y_radius = 16, .trail_frame = 12 };
    case 0x98f7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdea6, .x_radius = 16, .y_radius = 16, .trail_frame = 13 };
    case 0x98ff: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe46a, .x_radius = 20, .y_radius = 20, .trail_frame = 14 };
    case 0x9907: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdf02, .x_radius = 20, .y_radius = 20, .trail_frame = 15 };
    case 0x990f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe40e, .x_radius = 16, .y_radius = 16, .trail_frame = 16 };
    case 0x9917: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdea6, .x_radius = 16, .y_radius = 16, .trail_frame = 17 };
    case 0x991f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe3b2, .x_radius = 16, .y_radius = 16, .trail_frame = 18 };
    case 0x9927: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xde4a, .x_radius = 16, .y_radius = 16, .trail_frame = 19 };
    case 0x992f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe356, .x_radius = 16, .y_radius = 16, .trail_frame = 20 };
    case 0x9937: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xddee, .x_radius = 16, .y_radius = 16, .trail_frame = 21 };
    case 0x993f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe4c6, .x_radius = 12, .y_radius = 12, .trail_frame = 22 };
    case 0x9947: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdd92, .x_radius = 12, .y_radius = 12, .trail_frame = 23 };
    case 0x994f: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x98af };
    case 0x9953: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xee12, .x_radius =  8, .y_radius = 12, .trail_frame =  0 };
    case 0x995b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf002, .x_radius =  8, .y_radius = 12, .trail_frame =  1 };
    case 0x9963: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xee19, .x_radius =  8, .y_radius = 12, .trail_frame =  2 };
    case 0x996b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf009, .x_radius =  8, .y_radius = 12, .trail_frame =  3 };
    case 0x9973: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe85a, .x_radius = 16, .y_radius = 12, .trail_frame =  4 };
    case 0x997b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd8ee, .x_radius = 16, .y_radius = 12, .trail_frame =  5 };
    case 0x9983: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe870, .x_radius = 16, .y_radius = 12, .trail_frame =  6 };
    case 0x998b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd904, .x_radius = 16, .y_radius = 12, .trail_frame =  7 };
    case 0x9993: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe8ae, .x_radius = 16, .y_radius = 12, .trail_frame =  8 };
    case 0x999b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd942, .x_radius = 16, .y_radius = 12, .trail_frame =  9 };
    case 0x99a3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe8ec, .x_radius = 16, .y_radius = 16, .trail_frame = 10 };
    case 0x99ab: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd980, .x_radius = 16, .y_radius = 16, .trail_frame = 11 };
    case 0x99b3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe92a, .x_radius = 16, .y_radius = 18, .trail_frame = 12 };
    case 0x99bb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd9be, .x_radius = 16, .y_radius = 18, .trail_frame = 13 };
    case 0x99c3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe968, .x_radius = 16, .y_radius = 20, .trail_frame = 14 };
    case 0x99cb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd9fc, .x_radius = 16, .y_radius = 20, .trail_frame = 15 };
    case 0x99d3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe92a, .x_radius = 16, .y_radius = 18, .trail_frame = 16 };
    case 0x99db: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd9be, .x_radius = 16, .y_radius = 18, .trail_frame = 17 };
    case 0x99e3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe8ec, .x_radius = 16, .y_radius = 16, .trail_frame = 18 };
    case 0x99eb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd980, .x_radius = 16, .y_radius = 16, .trail_frame = 19 };
    case 0x99f3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe8ae, .x_radius = 16, .y_radius = 12, .trail_frame = 20 };
    case 0x99fb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd942, .x_radius = 16, .y_radius = 12, .trail_frame = 21 };
    case 0x9a03: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe870, .x_radius = 16, .y_radius =  8, .trail_frame = 22 };
    case 0x9a0b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd904, .x_radius = 16, .y_radius =  8, .trail_frame = 23 };
    case 0x9a13: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x9973 };
    case 0x9a17: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xee4c, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x9a1f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf03c, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case 0x9a27: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xee58, .x_radius =  8, .y_radius =  8, .trail_frame =  2 };
    case 0x9a2f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf048, .x_radius =  8, .y_radius =  8, .trail_frame =  3 };
    case 0x9a37: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe522, .x_radius = 12, .y_radius = 12, .trail_frame =  4 };
    case 0x9a3f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdb86, .x_radius = 12, .y_radius = 12, .trail_frame =  5 };
    case 0x9a47: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe6b2, .x_radius = 12, .y_radius = 12, .trail_frame =  6 };
    case 0x9a4f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdba6, .x_radius = 12, .y_radius = 12, .trail_frame =  7 };
    case 0x9a57: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe542, .x_radius = 16, .y_radius = 16, .trail_frame =  8 };
    case 0x9a5f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdc02, .x_radius = 16, .y_radius = 16, .trail_frame =  9 };
    case 0x9a67: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe59e, .x_radius = 16, .y_radius = 16, .trail_frame = 10 };
    case 0x9a6f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdc5e, .x_radius = 16, .y_radius = 16, .trail_frame = 11 };
    case 0x9a77: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe5fa, .x_radius = 16, .y_radius = 16, .trail_frame = 12 };
    case 0x9a7f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdcba, .x_radius = 16, .y_radius = 16, .trail_frame = 13 };
    case 0x9a87: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe656, .x_radius = 20, .y_radius = 20, .trail_frame = 14 };
    case 0x9a8f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdd16, .x_radius = 20, .y_radius = 20, .trail_frame = 15 };
    case 0x9a97: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe5fa, .x_radius = 16, .y_radius = 16, .trail_frame = 16 };
    case 0x9a9f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdcba, .x_radius = 16, .y_radius = 16, .trail_frame = 17 };
    case 0x9aa7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe59e, .x_radius = 16, .y_radius = 16, .trail_frame = 18 };
    case 0x9aaf: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdc5e, .x_radius = 16, .y_radius = 16, .trail_frame = 19 };
    case 0x9ab7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe542, .x_radius = 16, .y_radius = 16, .trail_frame = 20 };
    case 0x9abf: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdc02, .x_radius = 16, .y_radius = 16, .trail_frame = 21 };
    case 0x9ac7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xe6b2, .x_radius = 12, .y_radius = 12, .trail_frame = 22 };
    case 0x9acf: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xdba6, .x_radius = 12, .y_radius = 12, .trail_frame = 23 };
    case 0x9ad7: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x9a37 };
    case 0x9adb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf194, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x9ae3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf408, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case 0x9aeb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf1a7, .x_radius =  8, .y_radius = 16, .trail_frame =  2 };
    case 0x9af3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf41b, .x_radius =  8, .y_radius = 16, .trail_frame =  3 };
    case 0x9afb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf1e9, .x_radius =  8, .y_radius = 24, .trail_frame =  4 };
    case 0x9b03: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf45d, .x_radius =  8, .y_radius = 24, .trail_frame =  5 };
    case 0x9b0b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf209, .x_radius =  8, .y_radius = 28, .trail_frame =  6 };
    case 0x9b13: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf47d, .x_radius =  8, .y_radius = 28, .trail_frame =  7 };
    case 0x9b1b: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x9b0b };
    case 0x9b1f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf2ce, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x9b27: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf542, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case 0x9b2f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf2da, .x_radius = 12, .y_radius = 12, .trail_frame =  2 };
    case 0x9b37: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf54e, .x_radius = 12, .y_radius = 12, .trail_frame =  3 };
    case 0x9b3f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf310, .x_radius = 16, .y_radius = 16, .trail_frame =  4 };
    case 0x9b47: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf584, .x_radius = 16, .y_radius = 16, .trail_frame =  5 };
    case 0x9b4f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf33a, .x_radius = 20, .y_radius = 20, .trail_frame =  6 };
    case 0x9b57: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf5ae, .x_radius = 20, .y_radius = 20, .trail_frame =  7 };
    case 0x9b5f: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x9b4f };
    case 0x9b63: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf0fa, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x9b6b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf36e, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case 0x9b73: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf10d, .x_radius = 16, .y_radius =  8, .trail_frame =  2 };
    case 0x9b7b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf381, .x_radius = 16, .y_radius =  8, .trail_frame =  3 };
    case 0x9b83: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf14f, .x_radius = 24, .y_radius =  8, .trail_frame =  4 };
    case 0x9b8b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf3c3, .x_radius = 24, .y_radius =  8, .trail_frame =  5 };
    case 0x9b93: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf16f, .x_radius = 28, .y_radius =  8, .trail_frame =  6 };
    case 0x9b9b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf3e3, .x_radius = 28, .y_radius =  8, .trail_frame =  7 };
    case 0x9ba3: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x9b93 };
    case 0x9ba7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf22e, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x9baf: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf4a2, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case 0x9bb7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf23a, .x_radius = 12, .y_radius = 12, .trail_frame =  2 };
    case 0x9bbf: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf4ae, .x_radius = 12, .y_radius = 12, .trail_frame =  3 };
    case 0x9bc7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf270, .x_radius = 16, .y_radius = 16, .trail_frame =  4 };
    case 0x9bcf: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf4e4, .x_radius = 16, .y_radius = 16, .trail_frame =  5 };
    case 0x9bd7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf29a, .x_radius = 20, .y_radius = 20, .trail_frame =  6 };
    case 0x9bdf: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf50e, .x_radius = 20, .y_radius = 20, .trail_frame =  7 };
    case 0x9be7: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x9bd7 };
    case 0x9beb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf194, .x_radius = 12, .y_radius =  8, .trail_frame =  0 };
    case 0x9bf3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf408, .x_radius = 12, .y_radius =  8, .trail_frame =  1 };
    case 0x9bfb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf1a7, .x_radius = 12, .y_radius =  8, .trail_frame =  2 };
    case 0x9c03: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf41b, .x_radius = 12, .y_radius =  8, .trail_frame =  3 };
    case 0x9c0b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf1e9, .x_radius = 12, .y_radius = 24, .trail_frame =  4 };
    case 0x9c13: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf45d, .x_radius = 12, .y_radius = 24, .trail_frame =  5 };
    case 0x9c1b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc1af, .x_radius = 12, .y_radius = 30, .trail_frame =  6 };
    case 0x9c23: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc94d, .x_radius = 12, .y_radius = 30, .trail_frame =  7 };
    case 0x9c2b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc1d4, .x_radius = 12, .y_radius = 30, .trail_frame =  8 };
    case 0x9c33: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc972, .x_radius = 12, .y_radius = 30, .trail_frame =  9 };
    case 0x9c3b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc21c, .x_radius = 17, .y_radius = 30, .trail_frame = 10 };
    case 0x9c43: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc9ba, .x_radius = 17, .y_radius = 30, .trail_frame = 11 };
    case 0x9c4b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc264, .x_radius = 19, .y_radius = 30, .trail_frame = 12 };
    case 0x9c53: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xca02, .x_radius = 19, .y_radius = 30, .trail_frame = 13 };
    case 0x9c5b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc2ac, .x_radius = 20, .y_radius = 30, .trail_frame = 14 };
    case 0x9c63: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xca4a, .x_radius = 20, .y_radius = 30, .trail_frame = 15 };
    case 0x9c6b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc264, .x_radius = 19, .y_radius = 30, .trail_frame = 16 };
    case 0x9c73: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xca02, .x_radius = 19, .y_radius = 30, .trail_frame = 17 };
    case 0x9c7b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc21c, .x_radius = 17, .y_radius = 30, .trail_frame = 18 };
    case 0x9c83: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc9ba, .x_radius = 17, .y_radius = 30, .trail_frame = 19 };
    case 0x9c8b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc1d4, .x_radius = 12, .y_radius = 30, .trail_frame = 20 };
    case 0x9c93: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc972, .x_radius = 12, .y_radius = 30, .trail_frame = 21 };
    case 0x9c9b: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x9c1b };
    case 0x9c9f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf2ce, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x9ca7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf542, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case 0x9caf: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf2da, .x_radius =  8, .y_radius =  8, .trail_frame =  2 };
    case 0x9cb7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf54e, .x_radius =  8, .y_radius =  8, .trail_frame =  3 };
    case 0x9cbf: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf310, .x_radius = 12, .y_radius = 12, .trail_frame =  4 };
    case 0x9cc7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf584, .x_radius = 12, .y_radius = 12, .trail_frame =  5 };
    case 0x9ccf: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xcf42, .x_radius = 12, .y_radius = 12, .trail_frame =  6 };
    case 0x9cd7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xcc04, .x_radius = 12, .y_radius = 12, .trail_frame =  7 };
    case 0x9cdf: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xcf76, .x_radius = 16, .y_radius = 16, .trail_frame =  8 };
    case 0x9ce7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xcc42, .x_radius = 16, .y_radius = 16, .trail_frame =  9 };
    case 0x9cef: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xcfdc, .x_radius = 17, .y_radius = 17, .trail_frame = 10 };
    case 0x9cf7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xccbc, .x_radius = 17, .y_radius = 17, .trail_frame = 11 };
    case 0x9cff: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd042, .x_radius = 20, .y_radius = 20, .trail_frame = 12 };
    case 0x9d07: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xcd36, .x_radius = 20, .y_radius = 20, .trail_frame = 13 };
    case 0x9d0f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd0a8, .x_radius = 24, .y_radius = 24, .trail_frame = 14 };
    case 0x9d17: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xcdb0, .x_radius = 24, .y_radius = 24, .trail_frame = 15 };
    case 0x9d1f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xd042, .x_radius = 20, .y_radius = 20, .trail_frame = 16 };
    case 0x9d27: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xcd36, .x_radius = 20, .y_radius = 20, .trail_frame = 17 };
    case 0x9d2f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xcfdc, .x_radius = 17, .y_radius = 17, .trail_frame = 18 };
    case 0x9d37: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xccbc, .x_radius = 17, .y_radius = 17, .trail_frame = 19 };
    case 0x9d3f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xcf76, .x_radius = 16, .y_radius = 16, .trail_frame = 20 };
    case 0x9d47: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xcc42, .x_radius = 16, .y_radius = 16, .trail_frame = 21 };
    case 0x9d4f: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x9ccf };
    case 0x9d53: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf0fa, .x_radius =  8, .y_radius = 12, .trail_frame =  0 };
    case 0x9d5b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf36e, .x_radius =  8, .y_radius = 12, .trail_frame =  1 };
    case 0x9d63: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf10d, .x_radius =  8, .y_radius = 12, .trail_frame =  2 };
    case 0x9d6b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf381, .x_radius =  8, .y_radius = 12, .trail_frame =  3 };
    case 0x9d73: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf14f, .x_radius = 24, .y_radius = 12, .trail_frame =  4 };
    case 0x9d7b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf3c3, .x_radius = 24, .y_radius = 12, .trail_frame =  5 };
    case 0x9d83: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbcc8, .x_radius = 28, .y_radius = 12, .trail_frame =  6 };
    case 0x9d8b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc3b2, .x_radius = 28, .y_radius = 12, .trail_frame =  7 };
    case 0x9d93: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbced, .x_radius = 28, .y_radius = 12, .trail_frame =  8 };
    case 0x9d9b: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc3d7, .x_radius = 28, .y_radius = 12, .trail_frame =  9 };
    case 0x9da3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbd35, .x_radius = 28, .y_radius = 17, .trail_frame = 10 };
    case 0x9dab: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc41f, .x_radius = 28, .y_radius = 17, .trail_frame = 11 };
    case 0x9db3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbd7d, .x_radius = 28, .y_radius = 19, .trail_frame = 12 };
    case 0x9dbb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc467, .x_radius = 28, .y_radius = 19, .trail_frame = 13 };
    case 0x9dc3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbdc5, .x_radius = 28, .y_radius = 20, .trail_frame = 14 };
    case 0x9dcb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc4af, .x_radius = 28, .y_radius = 20, .trail_frame = 15 };
    case 0x9dd3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbd7d, .x_radius = 28, .y_radius = 19, .trail_frame = 16 };
    case 0x9ddb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc467, .x_radius = 28, .y_radius = 19, .trail_frame = 17 };
    case 0x9de3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbd35, .x_radius = 28, .y_radius = 17, .trail_frame = 18 };
    case 0x9deb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc41f, .x_radius = 28, .y_radius = 17, .trail_frame = 19 };
    case 0x9df3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbced, .x_radius = 28, .y_radius = 12, .trail_frame = 20 };
    case 0x9dfb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc3d7, .x_radius = 28, .y_radius = 12, .trail_frame = 21 };
    case 0x9e03: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x9d83 };
    case 0x9e07: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf22e, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x9e0f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf4a2, .x_radius =  8, .y_radius =  8, .trail_frame =  1 };
    case 0x9e17: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf23a, .x_radius =  8, .y_radius =  8, .trail_frame =  2 };
    case 0x9e1f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf4ae, .x_radius =  8, .y_radius =  8, .trail_frame =  3 };
    case 0x9e27: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf270, .x_radius = 12, .y_radius = 12, .trail_frame =  4 };
    case 0x9e2f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xf4e4, .x_radius = 12, .y_radius = 12, .trail_frame =  5 };
    case 0x9e37: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbf25, .x_radius = 12, .y_radius = 12, .trail_frame =  6 };
    case 0x9e3f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc669, .x_radius = 12, .y_radius = 12, .trail_frame =  7 };
    case 0x9e47: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbf59, .x_radius = 16, .y_radius = 16, .trail_frame =  8 };
    case 0x9e4f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc6a7, .x_radius = 16, .y_radius = 16, .trail_frame =  9 };
    case 0x9e57: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbfbf, .x_radius = 17, .y_radius = 17, .trail_frame = 10 };
    case 0x9e5f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc721, .x_radius = 17, .y_radius = 17, .trail_frame = 11 };
    case 0x9e67: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc025, .x_radius = 20, .y_radius = 20, .trail_frame = 12 };
    case 0x9e6f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc79b, .x_radius = 20, .y_radius = 20, .trail_frame = 13 };
    case 0x9e77: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc08b, .x_radius = 24, .y_radius = 24, .trail_frame = 14 };
    case 0x9e7f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc815, .x_radius = 24, .y_radius = 24, .trail_frame = 15 };
    case 0x9e87: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc025, .x_radius = 20, .y_radius = 20, .trail_frame = 16 };
    case 0x9e8f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc79b, .x_radius = 20, .y_radius = 20, .trail_frame = 17 };
    case 0x9e97: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbfbf, .x_radius = 17, .y_radius = 17, .trail_frame = 18 };
    case 0x9e9f: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc721, .x_radius = 17, .y_radius = 17, .trail_frame = 19 };
    case 0x9ea7: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xbf59, .x_radius = 16, .y_radius = 16, .trail_frame = 20 };
    case 0x9eaf: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xc6a7, .x_radius = 16, .y_radius = 16, .trail_frame = 21 };
    case 0x9eb7: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x9e37 };
    case 0x9ebb: return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xad7e, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case 0x9ec3: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x9ebb };
    case 0x9ec7: return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xad8a, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case 0x9ecf: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x9ec7 };
    case 0x9ed3: return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xad9b, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case 0x9edb: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x9ed3 };
    case 0x9edf: return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xada7, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case 0x9ee7: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x9edf };
    case 0x9eeb: return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xadb8, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case 0x9ef3: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x9eeb };
    case 0x9ef7: return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xadc4, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case 0x9eff: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x9ef7 };
    case 0x9f03: return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xad61, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case 0x9f0b: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x9f03 };
    case 0x9f0f: return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xad6d, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case 0x9f17: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x9f0f };
    case 0x9f1b: return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xadf2, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x9f23: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x9f1b };
    case 0x9f27: return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xadfe, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x9f2f: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x9f27 };
    case 0x9f33: return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xae0f, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x9f3b: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x9f33 };
    case 0x9f3f: return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xae1b, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x9f47: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x9f3f };
    case 0x9f4b: return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xae2c, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x9f53: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x9f4b };
    case 0x9f57: return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xae38, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x9f5f: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x9f57 };
    case 0x9f63: return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xadd5, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x9f6b: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x9f63 };
    case 0x9f6f: return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xade1, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x9f77: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x9f6f };
    case 0x9f7b: return (ProjectileInstr){ .timer = 15, .spritemap_ptr = 0xa117, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0x9f83: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x9f7b };
    case 0x9f87: return (ProjectileInstr){ .timer =  5, .spritemap_ptr = 0xab97, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case 0x9f8f: return (ProjectileInstr){ .timer =  5, .spritemap_ptr = 0xab9e, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case 0x9f97: return (ProjectileInstr){ .timer =  5, .spritemap_ptr = 0xaba5, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case 0x9f9f: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x9f87 };
    case 0x9fa3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xab97, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case 0x9fab: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xab9e, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case 0x9fb3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xaba5, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case 0x9fbb: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x9fa3 };
    case 0x9fbf: return (ProjectileInstr){ .timer =  5, .spritemap_ptr = 0xad45, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case 0x9fc7: return (ProjectileInstr){ .timer =  5, .spritemap_ptr = 0xad4c, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case 0x9fcf: return (ProjectileInstr){ .timer =  5, .spritemap_ptr = 0xad53, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case 0x9fd7: return (ProjectileInstr){ .timer =  5, .spritemap_ptr = 0xad5a, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case 0x9fdf: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x9fbf };
    case 0x9fe3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xad45, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case 0x9feb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xad4c, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case 0x9ff3: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xad53, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case 0x9ffb: return (ProjectileInstr){ .timer =  1, .spritemap_ptr = 0xad5a, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case 0xa003: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0x9fe3 };
    case 0xa007: return (ProjectileInstr){ .timer =  3, .spritemap_ptr = 0xabb3, .x_radius =  0, .y_radius =  0, .trail_frame =  0 };
    case 0xa00f: return (ProjectileInstr){ .timer =  3, .spritemap_ptr = 0xabba, .x_radius =  0, .y_radius =  0, .trail_frame =  0 };
    case 0xa017: return (ProjectileInstr){ .timer =  3, .spritemap_ptr = 0xabc1, .x_radius =  0, .y_radius =  0, .trail_frame =  0 };
    case 0xa01f: return (ProjectileInstr){ .timer =  3, .spritemap_ptr = 0xabd7, .x_radius =  0, .y_radius =  0, .trail_frame =  0 };
    case 0xa027: return (ProjectileInstr){ .timer =  3, .spritemap_ptr = 0xabed, .x_radius =  0, .y_radius =  0, .trail_frame =  0 };
    case 0xa02f: return (ProjectileInstr){ .timer =  3, .spritemap_ptr = 0xac03, .x_radius =  0, .y_radius =  0, .trail_frame =  0 };
    case 0xa037: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Delete) };
    case 0xa039: return (ProjectileInstr){ .timer =  3, .spritemap_ptr = 0xa7c9, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0xa041: return (ProjectileInstr){ .timer =  3, .spritemap_ptr = 0xa7d0, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0xa049: return (ProjectileInstr){ .timer =  3, .spritemap_ptr = 0xa7e6, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0xa051: return (ProjectileInstr){ .timer =  3, .spritemap_ptr = 0xa7fc, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0xa059: return (ProjectileInstr){ .timer =  3, .spritemap_ptr = 0xa812, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0xa061: return (ProjectileInstr){ .timer =  3, .spritemap_ptr = 0xa828, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0xa069: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Delete) };
    case 0xa06b: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa83e, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0xa073: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa854, .x_radius = 12, .y_radius = 12, .trail_frame =  0 };
    case 0xa07b: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa86a, .x_radius = 16, .y_radius = 16, .trail_frame =  0 };
    case 0xa083: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa880, .x_radius = 16, .y_radius = 16, .trail_frame =  0 };
    case 0xa08b: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa896, .x_radius = 16, .y_radius = 16, .trail_frame =  0 };
    case 0xa093: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Delete) };
    case 0xa095: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa83e, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0xa09d: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa854, .x_radius = 12, .y_radius = 12, .trail_frame =  0 };
    case 0xa0a5: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa86a, .x_radius = 16, .y_radius = 16, .trail_frame =  0 };
    case 0xa0ad: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa880, .x_radius = 16, .y_radius = 16, .trail_frame =  0 };
    case 0xa0b5: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa896, .x_radius = 16, .y_radius = 16, .trail_frame =  0 };
    case 0xa0bd: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0xa095 };
    case 0xa0c1: return (ProjectileInstr){ .timer =  5, .spritemap_ptr = 0xaa84, .x_radius =  8, .y_radius =  8, .trail_frame =  0 };
    case 0xa0c9: return (ProjectileInstr){ .timer =  5, .spritemap_ptr = 0xaa9a, .x_radius = 12, .y_radius = 12, .trail_frame =  0 };
    case 0xa0d1: return (ProjectileInstr){ .timer =  5, .spritemap_ptr = 0xaab0, .x_radius = 16, .y_radius = 16, .trail_frame =  0 };
    case 0xa0d9: return (ProjectileInstr){ .timer =  5, .spritemap_ptr = 0xaac6, .x_radius = 16, .y_radius = 16, .trail_frame =  0 };
    case 0xa0e1: return (ProjectileInstr){ .timer =  5, .spritemap_ptr = 0xab04, .x_radius = 16, .y_radius = 16, .trail_frame =  0 };
    case 0xa0e9: return (ProjectileInstr){ .timer =  5, .spritemap_ptr = 0xab2e, .x_radius = 16, .y_radius = 16, .trail_frame =  0 };
    case 0xa0f1: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Delete) };
    case 0xa0f3: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa117, .x_radius = 16, .y_radius = 32, .trail_frame =  0 };
    case 0xa0fb: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa117, .x_radius = 16, .y_radius = 32, .trail_frame =  1 };
    case 0xa103: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa117, .x_radius = 16, .y_radius = 32, .trail_frame =  2 };
    case 0xa10b: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa117, .x_radius = 16, .y_radius = 32, .trail_frame =  3 };
    case 0xa113: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0xa0f3 };
    case 0xa119: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa117, .x_radius = 32, .y_radius = 32, .trail_frame =  0 };
    case 0xa121: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa117, .x_radius = 32, .y_radius = 32, .trail_frame =  1 };
    case 0xa129: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa117, .x_radius = 32, .y_radius = 32, .trail_frame =  2 };
    case 0xa131: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa117, .x_radius = 32, .y_radius = 32, .trail_frame =  3 };
    case 0xa139: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0xa119 };
    case 0xa13d: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa117, .x_radius =  4, .y_radius =  8, .trail_frame =  0 };
    case 0xa145: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa117, .x_radius = 12, .y_radius =  8, .trail_frame =  1 };
    case 0xa14d: return (ProjectileInstr){ .timer =  2, .spritemap_ptr = 0xa117, .x_radius = 20, .y_radius =  8, .trail_frame =  2 };
    case 0xa155: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0xa14d };
    case 0xa159: return (ProjectileInstr){ .timer =  8, .spritemap_ptr = 0xaf4c, .x_radius =  4, .y_radius =  4, .trail_frame =  0 };
    case 0xa161: return (ProjectileInstr){ .timer =  8, .spritemap_ptr = 0xaf62, .x_radius =  4, .y_radius =  4, .trail_frame =  1 };
    case 0xa169: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0xa159 };
    case 0xa16d: return (ProjectileInstr){ .timer =  3, .spritemap_ptr = 0xabb3, .x_radius =  0, .y_radius =  0, .trail_frame =  0 };
    case 0xa175: return (ProjectileInstr){ .timer =  3, .spritemap_ptr = 0xabba, .x_radius =  0, .y_radius =  0, .trail_frame =  0 };
    case 0xa17d: return (ProjectileInstr){ .timer =  3, .spritemap_ptr = 0xabc1, .x_radius =  0, .y_radius =  0, .trail_frame =  0 };
    case 0xa185: return (ProjectileInstr){ .timer =  3, .spritemap_ptr = 0xabd7, .x_radius =  0, .y_radius =  0, .trail_frame =  0 };
    case 0xa18d: return (ProjectileInstr){ .timer =  3, .spritemap_ptr = 0xabed, .x_radius =  0, .y_radius =  0, .trail_frame =  0 };
    case 0xa195: return (ProjectileInstr){ .timer =  3, .spritemap_ptr = 0xac03, .x_radius =  0, .y_radius =  0, .trail_frame =  0 };
    case 0xa19d: return (ProjectileInstr){ .func_ptr = FUNC16(Proj93Instr_Goto), .instr_list_ptr = 0xa16d };
    default: return (ProjectileInstr){ Unreachable() };
  }
}


