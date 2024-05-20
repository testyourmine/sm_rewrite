#pragma once

// Clockwise
#define ROTATE_CW 0
// Counterclockwise
#define ROTATE_CCW 0x8000

extern uint16 kFxTypeTilemapPtrs[23];  // 0x83ABF0

extern Func_V* const kFxTypeFuncPtrs[23];  // 0x83AC18

extern uint16 kAreaPalFxLists[8][8];  // 0x83AC46

extern uint16 kAreaAnimtilesLists[8][8];  // 0x83AC56

static uint16 kPaletteBlends[] = {  // 0x89AA02
	   0x0,  0xe3f,  0xd7f,    0x0, 0x6318, 0x6318,    0x0, 0x6318, 0x6318,    0x0, 0x6318, 0x6318,    0x0, 0x6318, 0x6318,    0x0, 
	0x3800, 0x314a, 0x20c6,  0x820, 0x6318, 0x6318,    0x0, 0x6318, 0x6318,    0x0, 0x6318, 0x6318,    0x0, 0x6318, 0x6318,    0x0, 
	0x3800,  0x400, 0x1c63,    0x0, 0x28e3, 0x1c60,    0x0, 0x2485, 0x3d88,    0x0,  0x880,  0x420,    0x0, 0x28e3, 0x1c60,    0x0, 
	0x3800, 0x20a5, 0x1c84, 0x1024, 0x1087, 0x14a8,  0x844, 0x6318, 0x6318,    0x0, 0x6318, 0x6318,    0x0, 0x6318, 0x6318,    0x0, 
	0x3800, 0x6318, 0x6318,    0x0, 0x6318, 0x6318,    0x0, 0x6318, 0x6318,    0x0, 0x6318, 0x6318,    0x0, 0x6318, 0x6318,    0x0, 
	0x3800, 0x6318, 0x6318,    0x0, 0x6318, 0x6318,    0x0, 0x6318, 0x6318,    0x0, 0x6318, 0x6318,    0x0, 0x6318, 0x6318,    0x0, 
	0x3800, 0x6318, 0x6318,    0x0, 0x6318, 0x6318,    0x0, 0x6318, 0x6318,    0x0, 0x6318, 0x6318,    0x0, 0x6318, 0x6318,    0x0, 
	0x3800,  0x400, 0x18a2,    0x0,   0x20,  0xc62,    0x0,  0x400, 0x1c45,    0x0, 0x6318, 0x6318,    0x0, 0x6318, 0x6318,    0x0,
};

static RotationMatrix kCeresElevatorShaftMode7TransformationMatrix[69] = {  // 0x89AD5F
  [0]  = { .timer = 60, .sin_t = -34, .cos_t = 254 },
  [1]  = { .timer = 26, .sin_t = -33, .cos_t = 254 },
  [2]  = { .timer = 24, .sin_t = -32, .cos_t = 254 },
  [3]  = { .timer = 22, .sin_t = -31, .cos_t = 254 },
  [4]  = { .timer = 20, .sin_t = -30, .cos_t = 254 },
  [5]  = { .timer = 18, .sin_t = -29, .cos_t = 254 },
  [6]  = { .timer = 16, .sin_t = -28, .cos_t = 254 },
  [7]  = { .timer = 14, .sin_t = -27, .cos_t = 255 },
  [8]  = { .timer = 12, .sin_t = -26, .cos_t = 255 },
  [9]  = { .timer = 11, .sin_t = -25, .cos_t = 255 },
  [10] = { .timer = 10, .sin_t = -24, .cos_t = 255 },
  [11] = { .timer =  9, .sin_t = -23, .cos_t = 255 },
  [12] = { .timer =  8, .sin_t = -22, .cos_t = 255 },
  [13] = { .timer =  7, .sin_t = -21, .cos_t = 255 },
  [14] = { .timer =  7, .sin_t = -20, .cos_t = 255 },
  [15] = { .timer =  6, .sin_t = -19, .cos_t = 255 },
  [16] = { .timer =  6, .sin_t = -18, .cos_t = 255 },
  [17] = { .timer =  5, .sin_t = -17, .cos_t = 255 },
  [18] = { .timer =  5, .sin_t = -16, .cos_t = 256 },
  [19] = { .timer =  4, .sin_t = -15, .cos_t = 256 },
  [20] = { .timer =  4, .sin_t = -14, .cos_t = 256 },
  [21] = { .timer =  4, .sin_t = -13, .cos_t = 256 },
  [22] = { .timer =  3, .sin_t = -12, .cos_t = 256 },
  [23] = { .timer =  3, .sin_t = -11, .cos_t = 256 },
  [24] = { .timer =  3, .sin_t = -10, .cos_t = 256 },
  [25] = { .timer =  3, .sin_t =  -9, .cos_t = 256 },
  [26] = { .timer =  2, .sin_t =  -8, .cos_t = 256 },
  [27] = { .timer =  2, .sin_t =  -7, .cos_t = 256 },
  [28] = { .timer =  2, .sin_t =  -6, .cos_t = 256 },
  [29] = { .timer =  2, .sin_t =  -5, .cos_t = 256 },
  [30] = { .timer =  1, .sin_t =  -4, .cos_t = 256 },
  [31] = { .timer =  1, .sin_t =  -3, .cos_t = 256 },
  [32] = { .timer =  1, .sin_t =  -2, .cos_t = 256 },
  [33] = { .timer =  1, .sin_t =  -1, .cos_t = 256 },
  [34] = { .timer =  1, .sin_t =   0, .cos_t = 256 },
  [35] = { .timer =  1, .sin_t =   1, .cos_t = 256 },
  [36] = { .timer =  1, .sin_t =   2, .cos_t = 256 },
  [37] = { .timer =  1, .sin_t =   3, .cos_t = 256 },
  [38] = { .timer =  1, .sin_t =   4, .cos_t = 256 },
  [39] = { .timer =  2, .sin_t =   5, .cos_t = 256 },
  [40] = { .timer =  2, .sin_t =   6, .cos_t = 256 },
  [41] = { .timer =  2, .sin_t =   7, .cos_t = 256 },
  [42] = { .timer =  2, .sin_t =   8, .cos_t = 256 },
  [43] = { .timer =  3, .sin_t =   9, .cos_t = 256 },
  [44] = { .timer =  3, .sin_t =  10, .cos_t = 256 },
  [45] = { .timer =  3, .sin_t =  11, .cos_t = 256 },
  [46] = { .timer =  3, .sin_t =  12, .cos_t = 256 },
  [47] = { .timer =  4, .sin_t =  13, .cos_t = 256 },
  [48] = { .timer =  4, .sin_t =  14, .cos_t = 256 },
  [49] = { .timer =  4, .sin_t =  15, .cos_t = 256 },
  [50] = { .timer =  5, .sin_t =  16, .cos_t = 256 },
  [51] = { .timer =  5, .sin_t =  17, .cos_t = 255 },
  [52] = { .timer =  6, .sin_t =  18, .cos_t = 255 },
  [53] = { .timer =  6, .sin_t =  19, .cos_t = 255 },
  [54] = { .timer =  7, .sin_t =  20, .cos_t = 255 },
  [55] = { .timer =  7, .sin_t =  21, .cos_t = 255 },
  [56] = { .timer =  8, .sin_t =  22, .cos_t = 255 },
  [57] = { .timer =  9, .sin_t =  23, .cos_t = 255 },
  [58] = { .timer = 10, .sin_t =  24, .cos_t = 255 },
  [59] = { .timer = 11, .sin_t =  25, .cos_t = 255 },
  [60] = { .timer = 12, .sin_t =  26, .cos_t = 255 },
  [61] = { .timer = 14, .sin_t =  27, .cos_t = 255 },
  [62] = { .timer = 16, .sin_t =  28, .cos_t = 254 },
  [63] = { .timer = 18, .sin_t =  29, .cos_t = 254 },
  [64] = { .timer = 20, .sin_t =  30, .cos_t = 254 },
  [65] = { .timer = 22, .sin_t =  31, .cos_t = 254 },
  [66] = { .timer = 24, .sin_t =  32, .cos_t = 254 },
  [67] = { .timer = 26, .sin_t =  33, .cos_t = 254 },
  [68] = { .timer = 60, .sin_t =  34, .cos_t = 254 },
};
