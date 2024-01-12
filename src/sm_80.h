#pragma once


//#define kMusicPointers (*(LongPtr*)RomFixedPtr(0x8fe7e1))
//#define kTimerDigitsSpritemapPtr ((uint16*)RomFixedPtr(0x809fd4))
//#define kLoadStationLists ((uint16*)RomFixedPtr(0x80c4b5))
//#define kAreaElevatorBitsPtr ((uint16*)RomFixedPtr(0x80cd46))

LongPtr kMusicPointers[] = {
  0x8000, 0xcf, 0xe20d, 0xd0, 0xb62a, 0xd1, 0x88ca, 0xd2, 0xd9b6, 0xd2, 0x933c, 0xd3, 0xe812, 0xd3, 0xb86c, 0xd4, 0xf420, 0xd4, 0xc844, 0xd5, 0x98b7, 0xd6, 0xef9d, 0xd6, 0xbf73, 0xd7, 0x99b2, 0xd8, 0xea8b, 0xd8, 0xb67b, 0xd9, 0xf5dd, 0xd9, 0xb650, 0xda, 0xd63b, 0xda, 0xa40f, 0xdb, 0xdf4f, 0xdb, 0xaf6c, 0xdc, 0xfac7, 0xdc, 0xb104, 0xdd, 0x81c1, 0xde,
};

uint16 kTimerDigitsSpritemapPtr[] = {
  0x9fe8, 0x9ff4, 0xa000, 0xa00c, 0xa018, 0xa024, 0xa030, 0xa03c, 0xa048, 0xa054,
};

//uint16 kLoadStationLists[] = {
  //0xc4c5, 0xc5cf, 0xc6d9, 0xc81b, 0xc917, 0xca2f, 0xcb2b, 0xcc19,
//};

//uint16 kAreaElevatorBitsPtr[] = {
//  0xcd52, 0xcd66, 0xcd76, 0xcd8a, 0xcd82, 0xcd86,
//};


static const uint16 kHudTilemaps[32] = {  
  0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f,
  0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c1d, 0x2c1d, 0x2c1d, 0x2c1d, 0x2c1d, 0x2c1c,
};

static const uint16 kHudTilemaps_Row1to3[96] = {
  0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f,
  0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c12, 0x2c12, 0x2c23, 0x2c12, 0x2c12, 0x2c1e,
  0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f,
  0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2822, 0x2822, 0x2823, 0x2813, 0x2c14, 0x2c1e,
  0x2c0f, 0x2c0b, 0x2c0c, 0x2c0d, 0x2c32, 0x2c0f, 0x2c09, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f,
  0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c0f, 0x2c12, 0x2c12, 0xa824, 0x2815, 0x2c16, 0x2c1e,
};

static const uint16 kHudTilemaps_AutoReserve[6] = { 
  0x3c33, 0x3c46,
  0x3c47, 0x3c48,
  0xbc33, 0xbc46,
};

static const uint16 kHudTilemaps_EmptyAutoReserve[6] ={
  0x2c33, 0x2c46,
  0x2c47, 0x2c48,
  0xac33, 0xac46,
};

static const uint16 kHudTilemaps_Missiles[6] = {
  0x344b, 0x3449, 0x744b,
  0x344c, 0x344a, 0x744c,
};

static const uint16 kHudTilemaps_SuperMissiles[4] = {
  0x3434, 0x7434,
  0x3435, 0x7435,
};

static const uint16 kHudTilemaps_PowerBombs[4] = {
  0x3436, 0x7436,
  0x3437, 0x7437,
};

static const uint16 kHudTilemaps_Grapple[4] = {
  0x3438, 0x7438,
  0x3439, 0x7439,
};

static const uint16 kHudTilemaps_Xray[4] = {
  0x343a, 0x743a,
  0x343b, 0x743b,
};

static const uint16 kDigitTilesetsHealth[10] = {
  0x2c09, 0x2c00, 0x2c01, 0x2c02, 0x2c03, 0x2c04, 0x2c05, 0x2c06, 0x2c07, 0x2c08,
};

static const uint16 kDigitTilesetsWeapon[10] = {
  0x2c09, 0x2c00, 0x2c01, 0x2c02, 0x2c03, 0x2c04, 0x2c05, 0x2c06, 0x2c07, 0x2c08,
};

uint16 loadstationlist_ptrs[] = {
  0xc4c5, 0xc5cf, 0xc6d9, 0xc81b, 0xc917, 0xca2f, 0xcb2b, 0xcc19,
};

const LoadStationList kLoadStationLists[9][23] = {
  [0] = {
    [0] = {
      .room_ptr_ = 0x91f8, .door_ptr = 0x896a, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0x40, .samus_x_offset =    0x0,
    },
    [1] = {
      .room_ptr_ = 0x93d5, .door_ptr = 0x899a, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x98, .samus_x_offset = 0xffe0,
    },
    [2] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [3] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [4] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [5] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [6] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [7] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [8] = {
      .room_ptr_ = 0x94cc, .door_ptr = 0x8aba, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0xa8, .samus_x_offset =    0x0,
    },
    [9] = {
      .room_ptr_ = 0x962a, .door_ptr = 0x8a42, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0xa8, .samus_x_offset =    0x0,
    },
    [10] = {
      .room_ptr_ = 0x97b5, .door_ptr = 0x8b86, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x88, .samus_x_offset =    0x0,
    },
    [11] = {
      .room_ptr_ = 0x9938, .door_ptr = 0x8c22, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x88, .samus_x_offset =    0x0,
    },
    [12] = {
      .room_ptr_ = 0xa66a, .door_ptr = 0x91f2, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =  0x100, .samus_y_offset =   0x98, .samus_x_offset =    0x0,
    },
    [13] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [14] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [15] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [16] = {
      .room_ptr_ = 0x91f8, .door_ptr = 0x896a, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0x40, .samus_x_offset =    0x0,
    },
    [17] = {
      .room_ptr_ = 0x94fd, .door_ptr = 0x8a7e, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =  0x400, .samus_y_offset =   0x95, .samus_x_offset =    0x0,
    },
    [18] = {
      .room_ptr_ = 0x91f8, .door_ptr = 0x88fe, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =    0x0, .samus_y_offset =   0x80, .samus_x_offset =    0x0,
    },
  },
  [1] = {
    [0] = {
      .room_ptr_ = 0xa184, .door_ptr = 0x8df6, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x98, .samus_x_offset = 0xffe0,
    },
    [1] = {
      .room_ptr_ = 0xa201, .door_ptr = 0x8d12, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x98, .samus_x_offset = 0xffe0,
    },
    [2] = {
      .room_ptr_ = 0xa22a, .door_ptr = 0x8f52, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x98, .samus_x_offset = 0xffe0,
    },
    [3] = {
      .room_ptr_ = 0xa70b, .door_ptr = 0x9186, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x98, .samus_x_offset =    0x0,
    },
    [4] = {
      .room_ptr_ = 0xa734, .door_ptr = 0x90d2, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x98, .samus_x_offset =    0x0,
    },
    [5] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [6] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [7] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [8] = {
      .room_ptr_ = 0x9ad9, .door_ptr = 0x8d42, .door_bts =    0x1,
      .screen_x_pos =    0x0, .screen_y_pos =  0x200, .samus_y_offset =   0xa8, .samus_x_offset =    0x0,
    },
    [9] = {
      .room_ptr_ = 0x9e9f, .door_ptr = 0x8e86, .door_bts =    0x0,
      .screen_x_pos =  0x500, .screen_y_pos =  0x200, .samus_y_offset =   0xa8, .samus_x_offset =    0x0,
    },
    [10] = {
      .room_ptr_ = 0xa322, .door_ptr = 0x908a, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =  0x200, .samus_y_offset =   0xa8, .samus_x_offset =    0x0,
    },
    [11] = {
      .room_ptr_ = 0xa6a1, .door_ptr = 0xa384, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x88, .samus_x_offset =    0x0,
    },
    [12] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [13] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [14] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [15] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [16] = {
      .room_ptr_ = 0x9ad9, .door_ptr = 0x8d42, .door_bts =    0x1,
      .screen_x_pos =    0x0, .screen_y_pos =  0x200, .samus_y_offset =   0xa8, .samus_x_offset =    0x0,
    },
    [17] = {
      .room_ptr_ = 0xa56b, .door_ptr = 0x91ce, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =  0x100, .samus_y_offset =   0x80, .samus_x_offset =    0x0,
    },
    [18] = {
      .room_ptr_ = 0x9d19, .door_ptr = 0x8e62, .door_bts =    0x0,
      .screen_x_pos =  0x300, .screen_y_pos =    0x0, .samus_y_offset =   0x80, .samus_x_offset =    0x0,
    },
  },
  [2] = {
    [0] = {
      .room_ptr_ = 0xaab5, .door_ptr = 0x9456, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x98, .samus_x_offset =    0x0,
    },
    [1] = {
      .room_ptr_ = 0xb0dd, .door_ptr = 0x959a, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x98, .samus_x_offset = 0xffe0,
    },
    [2] = {
      .room_ptr_ = 0xb167, .door_ptr = 0x97da, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x98, .samus_x_offset =    0x0,
    },
    [3] = {
      .room_ptr_ = 0xb192, .door_ptr = 0x93ba, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x98, .samus_x_offset =    0x0,
    },
    [4] = {
      .room_ptr_ = 0xb1bb, .door_ptr = 0x9702, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x98, .samus_x_offset = 0xffe0,
    },
    [5] = {
      .room_ptr_ = 0xb741, .door_ptr = 0x9a0e, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x98, .samus_x_offset =    0x0,
    },
    [6] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [7] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [8] = {
      .room_ptr_ = 0xa7de, .door_ptr = 0x92a6, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =  0x200, .samus_y_offset =   0xa8, .samus_x_offset =    0x0,
    },
    [9] = {
      .room_ptr_ = 0xaf3f, .door_ptr = 0x96de, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x88, .samus_x_offset =    0x0,
    },
    [10] = {
      .room_ptr_ = 0xb236, .door_ptr = 0x9846, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x200, .samus_y_offset =   0x88, .samus_x_offset =    0x0,
    },
    [11] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [12] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [13] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [14] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [15] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [16] = {
      .room_ptr_ = 0xa7de, .door_ptr = 0x932a, .door_bts =    0x2,
      .screen_x_pos =    0x0, .screen_y_pos =  0x200, .samus_y_offset =   0xa8, .samus_x_offset =    0x0,
    },
    [17] = {
      .room_ptr_ = 0xa923, .door_ptr = 0x93ea, .door_bts =    0x1,
      .screen_x_pos =  0xc00, .screen_y_pos =  0x200, .samus_y_offset =   0xa0, .samus_x_offset =    0x0,
    },
    [18] = {
      .room_ptr_ = 0xb37a, .door_ptr = 0x995a, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0xa0, .samus_x_offset =    0x0,
    },
    [19] = {
      .room_ptr_ = 0xaa82, .door_ptr = 0x946e, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0xb5, .samus_x_offset =    0x0,
    },
    [20] = {
      .room_ptr_ = 0xb236, .door_ptr = 0x9846, .door_bts =    0x1,
      .screen_x_pos =  0x500, .screen_y_pos =  0x200, .samus_y_offset =   0x35, .samus_x_offset =    0x0,
    },
    [21] = {
      .room_ptr_ = 0xb283, .door_ptr = 0x98a6, .door_bts =    0x0,
      .screen_x_pos =  0x200, .screen_y_pos =  0x200, .samus_y_offset =    0x0, .samus_x_offset =    0x0,
    },
    [22] = {
      .room_ptr_ = 0xb283, .door_ptr = 0x983a, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x80, .samus_x_offset =    0x0,
    },
  },
  [3] = {
    [0] = {
      .room_ptr_ = 0xce8a, .door_ptr = 0xa240, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x98, .samus_x_offset =    0x0,
    },
    [1] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [2] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [3] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [4] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [5] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [6] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [7] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [8] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [9] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [10] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [11] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [12] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [13] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [14] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [15] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [16] = {
      .room_ptr_ = 0xca08, .door_ptr = 0xa1f8, .door_bts =    0x1,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x80, .samus_x_offset =    0x0,
    },
    [17] = {
      .room_ptr_ = 0xcc6f, .door_ptr = 0xa2b8, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =    0x0, .samus_y_offset =   0x80, .samus_x_offset =    0x0,
    },
  },
  [4] = {
    [0] = {
      .room_ptr_ = 0xced2, .door_ptr = 0xa354, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x98, .samus_x_offset =    0x0,
    },
    [1] = {
      .room_ptr_ = 0xd3df, .door_ptr = 0xa588, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x98, .samus_x_offset =    0x0,
    },
    [2] = {
      .room_ptr_ = 0xd765, .door_ptr = 0xa744, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x98, .samus_x_offset = 0xffe0,
    },
    [3] = {
      .room_ptr_ = 0xd81a, .door_ptr = 0xa7ec, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x98, .samus_x_offset =    0x0,
    },
    [4] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [5] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [6] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [7] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [8] = {
      .room_ptr_ = 0xd30b, .door_ptr = 0xa570, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =  0x200, .samus_y_offset =   0xa8, .samus_x_offset =    0x0,
    },
    [9] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [10] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [11] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [12] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [13] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [14] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [15] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [16] = {
      .room_ptr_ = 0xd1dd, .door_ptr = 0xa4a4, .door_bts =    0x1,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0xd0, .samus_x_offset =    0x0,
    },
    [17] = {
      .room_ptr_ = 0xd78f, .door_ptr = 0xa81c, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =  0x200, .samus_y_offset =   0x80, .samus_x_offset =    0x0,
    },
    [18] = {
      .room_ptr_ = 0xd617, .door_ptr = 0xa72c, .door_bts =    0x0,
      .screen_x_pos =  0x300, .screen_y_pos =    0x0, .samus_y_offset =   0x80, .samus_x_offset =    0x0,
    },
    [19] = {
      .room_ptr_ = 0xd48e, .door_ptr = 0xa648, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =  0x100, .samus_y_offset =   0x80, .samus_x_offset =    0x0,
    },
  },
  [5] = {
    [0] = {
      .room_ptr_ = 0xde23, .door_ptr = 0xaabc, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x98, .samus_x_offset = 0xffe0,
    },
    [1] = {
      .room_ptr_ = 0xdf1b, .door_ptr = 0xa99c, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x98, .samus_x_offset =    0x0,
    },
    [2] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [3] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [4] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [5] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [6] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [7] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [8] = {
      .room_ptr_ = 0xdaae, .door_ptr = 0xa9a8, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =  0x200, .samus_y_offset =   0xa8, .samus_x_offset =    0x0,
    },
    [9] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [10] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [11] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [12] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [13] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [14] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [15] = {
      .room_ptr_ =    0x0, .door_ptr =    0x0, .door_bts =    0x0,
      .screen_x_pos =  0x400, .screen_y_pos =  0x400, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [16] = {
      .room_ptr_ = 0xddf3, .door_ptr = 0xaaa4, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =  0x200, .samus_y_offset =   0x80, .samus_x_offset =    0x0,
    },
    [17] = {
      .room_ptr_ = 0xddf3, .door_ptr = 0xaa38, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x80, .samus_x_offset =    0x0,
    },
  },
  [6] = {
    [0] = {
      .room_ptr_ = 0xdf45, .door_ptr = 0xab58, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x48, .samus_x_offset =    0x0,
    },
    [1] = {
      .room_ptr_ = 0xdf45, .door_ptr = 0xab58, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x40, .samus_x_offset =    0x0,
    },
    [2] = {
      .room_ptr_ = 0xdf45, .door_ptr = 0xab58, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x40, .samus_x_offset =    0x0,
    },
    [3] = {
      .room_ptr_ = 0xdf45, .door_ptr = 0xab58, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x40, .samus_x_offset =    0x0,
    },
    [4] = {
      .room_ptr_ = 0xdf45, .door_ptr = 0xab58, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x40, .samus_x_offset =    0x0,
    },
    [5] = {
      .room_ptr_ = 0xdf45, .door_ptr = 0xab58, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x40, .samus_x_offset =    0x0,
    },
    [6] = {
      .room_ptr_ = 0xdf45, .door_ptr = 0xab58, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x40, .samus_x_offset =    0x0,
    },
    [7] = {
      .room_ptr_ = 0xdf45, .door_ptr = 0xab58, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x40, .samus_x_offset =    0x0,
    },
    [8] = {
      .room_ptr_ = 0xdf45, .door_ptr = 0xab58, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x40, .samus_x_offset =    0x0,
    },
    [9] = {
      .room_ptr_ = 0xdf45, .door_ptr = 0xab58, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x40, .samus_x_offset =    0x0,
    },
    [10] = {
      .room_ptr_ = 0xdf45, .door_ptr = 0xab58, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x40, .samus_x_offset =    0x0,
    },
    [11] = {
      .room_ptr_ = 0xdf45, .door_ptr = 0xab58, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x40, .samus_x_offset =    0x0,
    },
    [12] = {
      .room_ptr_ = 0xdf45, .door_ptr = 0xab58, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x40, .samus_x_offset =    0x0,
    },
    [13] = {
      .room_ptr_ = 0xdf45, .door_ptr = 0xab58, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x40, .samus_x_offset =    0x0,
    },
    [14] = {
      .room_ptr_ = 0xdf45, .door_ptr = 0xab58, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x40, .samus_x_offset =    0x0,
    },
    [15] = {
      .room_ptr_ = 0xdf45, .door_ptr = 0xab58, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x40, .samus_x_offset =    0x0,
    },
    [16] = {
      .room_ptr_ = 0xdf45, .door_ptr = 0xab58, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0x40, .samus_x_offset =    0x0,
    },
  },
  [7] = {
    [0] = {
      .room_ptr_ = 0xe82c, .door_ptr = 0xabc4, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [1] = {
      .room_ptr_ = 0xe82c, .door_ptr = 0xabc4, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [2] = {
      .room_ptr_ = 0xe82c, .door_ptr = 0xabc4, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [3] = {
      .room_ptr_ = 0xe82c, .door_ptr = 0xabc4, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [4] = {
      .room_ptr_ = 0xe82c, .door_ptr = 0xabc4, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [5] = {
      .room_ptr_ = 0xe82c, .door_ptr = 0xabc4, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [6] = {
      .room_ptr_ = 0xe82c, .door_ptr = 0xabc4, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [7] = {
      .room_ptr_ = 0xe82c, .door_ptr = 0xabc4, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [8] = {
      .room_ptr_ = 0xe82c, .door_ptr = 0xabc4, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [9] = {
      .room_ptr_ = 0xe82c, .door_ptr = 0xabc4, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [10] = {
      .room_ptr_ = 0xe82c, .door_ptr = 0xabc4, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [11] = {
      .room_ptr_ = 0xe82c, .door_ptr = 0xabc4, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [12] = {
      .room_ptr_ = 0xe82c, .door_ptr = 0xabc4, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [13] = {
      .room_ptr_ = 0xe82c, .door_ptr = 0xabc4, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [14] = {
      .room_ptr_ = 0xe82c, .door_ptr = 0xabc4, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [15] = {
      .room_ptr_ = 0xe82c, .door_ptr = 0xabc4, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
    [16] = {
      .room_ptr_ = 0xe82c, .door_ptr = 0xabc4, .door_bts =    0x0,
      .screen_x_pos =    0x0, .screen_y_pos =    0x0, .samus_y_offset =   0xb0, .samus_x_offset =    0x0,
    },
  },
};

const ElevatorsUsedConf kAreaElevatorBits[6][5] = {
  [0] = {
    [0] = {
      .source_area =  1, .source_bit =  1, .dest_area =  9, .dest_bit =  1,
    },
    [1] = {
      .source_area =  1, .source_bit =  2, .dest_area =  3, .dest_bit =  4,
    },
    [2] = {
      .source_area =  1, .source_bit =  4, .dest_area =  3, .dest_bit =  2,
    },
    [3] = {
      .source_area =  1, .source_bit =  8, .dest_area =  3, .dest_bit =  1,
    },
    [4] = {
      .source_area =  1, .source_bit = 16, .dest_area = 11, .dest_bit =  1,
    },
  },
  [1] = {
    [0] = {
      .source_area =  3, .source_bit =  1, .dest_area =  1, .dest_bit =  8,
    },
    [1] = {
      .source_area =  3, .source_bit =  2, .dest_area =  1, .dest_bit =  4,
    },
    [2] = {
      .source_area =  3, .source_bit =  4, .dest_area =  1, .dest_bit =  2,
    },
    [3] = {
      .source_area =  3, .source_bit =  8, .dest_area =  5, .dest_bit =  1,
    },
  },
  [2] = {
    [0] = {
      .source_area =  5, .source_bit =  1, .dest_area =  3, .dest_bit =  8,
    },
    [1] = {
      .source_area =  5, .source_bit =  2, .dest_area =  5, .dest_bit =  4,
    },
    [2] = {
      .source_area =  5, .source_bit =  4, .dest_area =  5, .dest_bit =  2,
    },
  },
  [3] = {
    [0] = {
      .source_area =  0, .source_bit =  0, .dest_area =  0, .dest_bit =  0,
    },
  },
  [4] = {
    [0] = {
      .source_area =  9, .source_bit =  1, .dest_area =  1, .dest_bit =  1,
    },
  },
  [5] = {
    [0] = {
      .source_area = 11, .source_bit =  1, .dest_area =  1, .dest_bit = 16,
    },
  },
};
