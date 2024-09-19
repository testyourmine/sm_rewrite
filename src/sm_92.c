// Samus animations

#include "ida_types.h"
#include "variables.h"
#include "funcs.h"
#include "sm_92.h"


/**
* @brief Sets the tile definition entry for the current Samus animation
*/
void SetSamusTilesDefsForCurAnim(void) {  // 0x928000
  uint16 anim_def_ptr = kSamus_AnimationDefinitionPtrs[samus_pose] + samus_anim_frame * sizeof(SamusTileAnimationDefs);
  SamusTileAnimationDefs *AD = get_SamusTileAnimationDefs(anim_def_ptr);
  uint16 tile_def_entry = sizeof(SamusTileAnimationTileDefs);
  nmi_copy_samus_top_half_src = kSamus_TileDefs_TopHalf[AD->top_half_idx] + AD->top_half_pos * tile_def_entry;
  nmi_copy_samus_top_half_ready_flag = true;
  // The index will never be 0xFF, so this condition is always true
  if (AD->bottom_half_idx != 0xFF) {
    nmi_copy_samus_bottom_half_src = kSamus_TileDefs_BottomHalf[AD->bottom_half_idx] + AD->bottom_half_pos * tile_def_entry;
    nmi_copy_samus_bottom_half_ready_flag = true;
  }
}

/**
* @brief Start the fanfare and set the last different and previous poses when done
* @return 0 if fanfare is playing, 1 if the fanfare is finished
*/
uint8 PlaySamusFanfare(void) {  // 0x92ED24
  if (samus_fanfare_timer == 0) {
    QueueMusic_DelayedY(kMusic_SamusFanfare, 14);
  }
  else if (samus_fanfare_timer == 5) {
    PlayRoomMusicTrackAfterAFrames(6*60);
  }

  if (samus_fanfare_timer + 1 < 6*60) {
    ++samus_fanfare_timer;
    return 0;
  }
  else {
    samus_last_different_pose = samus_prev_pose;
    samus_last_different_pose_x_dir = samus_prev_pose_x_dir;
    samus_last_different_pose_movement_type = samus_prev_movement_type;
    samus_prev_pose = samus_pose;
    samus_prev_pose_x_dir = samus_pose_x_dir;
    samus_prev_movement_type = samus_movement_type;
    samus_fanfare_timer = 0;
    return 1;
  }
}

void Unused_DebugSamusTileViewer(void) {  // 0x92ED7A
  DrawSamusSpritemap(0x182, 0x40, 0x40);
  DrawSamusSpritemap(0x183, 0xC0, 0x40);
  DrawSamusSpritemap(0x184, 0x80, 0x60);
  DrawSamusSpritemap(0x185, 0x80, 0x50);
}

/**
* @brief Draw Samus suit exploding during game over animation
*/
void DrawSamusSuitExploding(void) {  // 0x92EDBE
  uint16 samus_spritemap_idx;
  if (samus_pose_x_dir == kSamusXDir_FaceLeft)
    samus_spritemap_idx = samus_death_anim_index + 2085;
  else
    samus_spritemap_idx = samus_death_anim_index + 2076;
  DrawSamusSpritemap(samus_spritemap_idx, samus_x_pos, samus_y_pos);
}
