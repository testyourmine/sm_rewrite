#pragma once

#include "ida_types.h"
#include "types.h"

#define SPS_FACE_LEFT 0   // Spawn facing left
#define SPS_FACE_RIGHT 1  // Spawn facing right

#define SPS_JUMP_FAST 0       // Wall jump fast
#define SPS_JUMP_SLOW 0x8000  // Wall jump slow

#define SPS_FLINCH 0x8000  // Able to flinch


uint16 kSpacePirates_GoldPalette[] = {
  0x3800, 0x4bbe,  0x6b9,   0xea,   0x65, 0x173a,  0x276,  0x1f2,  0x14d, 0x5ebb, 0x3db3, 0x292e, 0x1486,  0x33b,  0x216,  0x113,
};

uint16 kSpacePirate_DivekickRandomDir_InstrListPtrs[] = {
     0x0, addr_kNinjaSpacePirates_Ilist_DivekickL_Jump, addr_kNinjaSpacePirates_Ilist_DivekickL_Jump, addr_kNinjaSpacePirates_Ilist_DivekickL_Jump,
     0x0, addr_kNinjaSpacePirates_Ilist_DivekickR_Jump, addr_kNinjaSpacePirates_Ilist_DivekickR_Jump, addr_kNinjaSpacePirates_Ilist_DivekickR_Jump,
};


