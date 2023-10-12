#pragma once

#define kEnemyLayerToQueuePtr ((uint16*)RomFixedPtr(0xa0b133))
#define kStandardSpriteTiles ((uint16*)RomFixedPtr(0x9ad200))
#define kSine8bit ((uint8*)RomFixedPtr(0xa0b143))
#define kEquationForQuarterCircle ((uint16*)RomFixedPtr(0xa0b7ee))
#define kEnemyDestroySpikeBtsOffset ((uint16*)RomFixedPtr(0xa0c2da))
#define CHECK_locret_A0C434(Ek) (byte_A0C435[Ek] & 0x80 ? -1 : 0)
#define kEnemyXYSlopeOffsetMultiplicationIndices ((uint16*)RomFixedPtr(0xa0c49f))
#define kAlignYPos_Tab0 ((uint8*)RomFixedPtr(0x948b2b))
