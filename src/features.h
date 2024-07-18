#ifndef SM_FEATURES_H_
#define SM_FEATURES_H_

#include "types.h"

// Special RAM locations that are unused but I use for compat things.
enum {
    kRam_Features0 = 0x64c,
};

// Enum values for kRam_Features0
enum {
    kFeatures0_AmmoRechargeStation = 1,
    kFeatures0_ShinesparkControl = 2,
    kFeatures0_ChainSpark = 4,
    kFeatures0_LowHealthBeep = 8,
    kFeatures0_PowerBombReveal = 16,
    kFeatures0_InstantPickups = 32,

    //kFeatures0_ = 64,
    //kFeatures0_SkipIntroOnKeypress = 128,
    //kFeatures0_ = 256,
    //kFeatures0_ = 512,
    //kFeatures0_ = 1024,
    //kFeatures0_ = 2048,
    //kFeatures0_ = 4096,
    //kFeatures0_ = 8192,
    //kFeatures0_ = 16384,
    //kFeatures0_ = 32768,
    //kFeatures0_ = 65536,
};

#define enhanced_features0 (*(uint32*)(g_ram+0x64c))

extern uint32 g_wanted_sm_features;

#endif  // SM_FEATURES_H_