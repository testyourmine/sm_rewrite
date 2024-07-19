#ifndef SM_FEATURES_H_
#define SM_FEATURES_H_

#include "types.h"

// Special RAM locations that are unused but I use for compat things.
enum {
    kRam_Features0 = 0x1886,
};

// Enum values for kRam_Features0
enum {
    kFeatures0_AmmoRechargeStation = 0x1,
    kFeatures0_ShinesparkControl = 0x2,
    kFeatures0_ChainSpark = 0x4,
    kFeatures0_PowerBombReveal = 0x8,
    kFeatures0_InstantPickups = 0x10,
    
    //kFeatures0_ = 0x20,
    //kFeatures0_ = 0x40,
    //kFeatures0_SkipIntroOnKeypress = 0x80,
    //kFeatures0_ = 0x100,
    //kFeatures0_ = 0x200,
    //kFeatures0_ = 0x400,
    //kFeatures0_ = 0x800,
    //kFeatures0_ = 0x1000,
    //kFeatures0_ = 0x2000,
    //kFeatures0_ = 0x4000,
    //kFeatures0_ = 0x8000,
    //kFeatures0_ = 0x10000,
};

#define enhanced_features0 (*(uint32*)(g_ram+0x1886))

extern uint32 g_wanted_sm_features;

#endif  // SM_FEATURES_H_