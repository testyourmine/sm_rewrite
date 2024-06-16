#pragma once

#include "types.h"

//#define kMotherBrain_HealthBasedPalettes_Brain ((uint16*)RomFixedPtr(0xade6a2))
//#define kMotherBrain_HealthBasedPalettes_BackLeg ((uint16*)RomFixedPtr(0xade742))
//#define kMotherBrain_FadePalToBlack ((uint16*)RomFixedPtr(0xade9e8))
//#define kMotherBrain_TransitionToFromGrey_Incr ((uint16*)RomFixedPtr(0xaded8a))
//#define kMotherBrain_TransitionToFromGrey_Decr ((uint16*)RomFixedPtr(0xaded9c))
//#define kMotherBrain_FadeToGray_Drained ((uint16*)RomFixedPtr(0xadef87))
//#define kMotherBrain_FadeToGray_RealDeath ((uint16*)RomFixedPtr(0xadf107))
//#define kMotherBrain_Phase3_TurnLightsBackOn ((uint16*)RomFixedPtr(0xadf273))

uint16 kMotherBrain_HealthBasedPalettes_Brain[] = {
  0xe6ac, 0xe6ca, 0xe6e8, 0xe706, 0xe724,
};

uint16 kMotherBrain_HealthBasedPalettes_BackLeg[] = {
  0xe74c, 0xe76a, 0xe788, 0xe7a6, 0xe7c4,
};

uint16 kMotherBrain_FadePalToBlack[] = {
  0xea0a, 0xea42, 0xea7a, 0xeab2, 0xeaea, 0xeb22, 0xeb5a, 0xeb92, 0xebca, 0xec02, 0xec3a, 0xec72, 0xecaa, 0xece2, 0xed1a, 0xed52, 
     0x0,
};

uint16 kMotherBrain_TransitionToFromGrey_Incr[] = {
  0xedae, 0xedd4, 0xedfa, 0xee20, 0xee46, 0xee6c, 0xee92, 0xeeb8,    0x0,
};

uint16 kMotherBrain_TransitionToFromGrey_Decr[] = {
  0xeeb8, 0xee92, 0xee6c, 0xee46, 0xee20, 0xedfa, 0xedd4, 0xedae,    0x0,
};

uint16 kMotherBrain_FadeToGray_Drained[] = {
  0xef99, 0xefc3, 0xefed, 0xf017, 0xf041, 0xf06b, 0xf095, 0xf0bf,    0x0,
};

uint16 kMotherBrain_FadeToGray_RealDeath[] = {
  0xf119, 0xf137, 0xf155, 0xf173, 0xf191, 0xf1af, 0xf1cd, 0xf1eb,    0x0,
};

uint16 kMotherBrain_Phase3_TurnLightsBackOn[] = {
  0xf3d3, 0xf39b, 0xf363, 0xf32b, 0xf2f3, 0xf2bb, 0xf283,    0x0,
};


