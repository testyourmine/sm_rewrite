#pragma once

// Cinematic stuff
#define mode7_transform_angle (*(uint16*)(g_ram+0x198D))
#define mode7_transform_zoom (*(uint16*)(g_ram+0x198F))
#define mode7_x_subpos (*(uint16*)(g_ram+0x1991))
#define mode7_x_pos (*(uint16*)(g_ram+0x1993))
#define mode7_y_subpos (*(uint16*)(g_ram+0x1995))
#define mode7_y_pos (*(uint16*)(g_ram+0x1997))
#define mode7_x_subspeed (*(uint16*)(g_ram+0x1999))
#define mode7_x_speed (*(uint16*)(g_ram+0x199B))
#define mode7_y_subspeed (*(uint16*)(g_ram+0x199D))
#define mode7_y_speed (*(uint16*)(g_ram+0x199F))
#define mode7_obj_instr_ptr ((uint16*)(g_ram+0x19A1))
#define mode7_obj_preinstr_func ((uint16*)(g_ram+0x19A5))
#define mode7_obj_instr_timer ((uint16*)(g_ram+0x19A9))
#define mode7_obj_goto_timer ((uint16*)(g_ram+0x19AD))
#define mode7_cur_index (*(uint16*)(g_ram+0x19B1))
#define mode7_spawn_param (*(uint16*)(g_ram+0x19B3))
#define cinematicbg_indir_inst_ptr ((uint16*)(g_ram+0x19B5))
#define cinematicbg_instr_ptr ((uint16*)(g_ram+0x19CD))
#define cinematicbg_preinstr ((uint16*)(g_ram+0x19D5))
#define cinematicbg_instr_timer ((uint16*)(g_ram+0x19DD))
#define cinematicbg_goto_timer ((uint16*)(g_ram+0x19E5))
#define cinematicbg_var2 (*(uint16*)(g_ram+0x19ED))
#define cinematic_enable_objs (*(uint16*)(g_ram+0x19F1))
#define cinematic_enable_bg_tilemap (*(uint16*)(g_ram+0x19F3))
#define cinematicbg_vram_addr (*(uint16*)(g_ram+0x19F5))
#define cinematic_var21 (*(uint16*)(g_ram+0x19F7))
#define cinematic_var22 (*(uint16*)(g_ram+0x19F9))
#define cinematic_var23 (*(uint16*)(g_ram+0x19FB))
#define cinematic_var24 (*(uint16*)(g_ram+0x19FD))
#define cinematic_var25 (*(uint16*)(g_ram+0x19FF))
#define cinematic_var26 (*(uint16*)(g_ram+0x1A01))
#define eproj_pre_instr ((uint16*)(g_ram+0x1A03))
#define cinematic_var20 (*(uint16*)(g_ram+0x1A37))
#define cinematic_var19 (*(uint16*)(g_ram+0x1A47))
#define cinematic_func_timer (*(uint16*)(g_ram+0x1A49))
#define cinematic_var13 (*(uint16*)(g_ram+0x1A4B))
#define cinematic_var14 (*(uint16*)(g_ram+0x1A4D))
#define cinematic_var17 (*(uint16*)(g_ram+0x1A4F))
#define cinematic_frame_counter (*(uint16*)(g_ram+0x1A51))
#define cinematic_var18 (*(uint16*)(g_ram+0x1A53))
#define cinematic_samus_display_flag (*(uint16*)(g_ram+0x1A57))
#define cinematic_obj_index (*(uint16*)(g_ram+0x1A59))
#define cinematicspr_whattodraw ((uint16*)(g_ram+0x1A5D))
#define cinematicbg_x_pos ((uint16*)(g_ram+0x1A7D))
#define cinematicbg_y_pos ((uint16*)(g_ram+0x1A9D))
#define cinematicbg_palette_index ((uint16*)(g_ram+0x1ABD))
#define cinematicspr_arr6 ((uint16*)(g_ram+0x1ADD))
#define cinematicspr_arr7 ((uint16*)(g_ram+0x1AFD))
#define cinematicspr_instr_ptr ((uint16*)(g_ram+0x1B1D))
#define cinematicspr_preinstr_func ((uint16*)(g_ram+0x1B3D))
#define cinematicspr_instr_timer ((uint16*)(g_ram+0x1B5D))
#define cinematicspr_goto_timer ((uint16*)(g_ram+0x1B7D))
#define cinematic_spawn_param (*(uint16*)(g_ram+0x1B9D))
#define cinematic_intro_end_counter (*(uint16*)(g_ram+0x1B9F))
#define cinematicbg_text_click_flag (*(uint16*)(g_ram+0x1BA1))
#define cinematic_jp_text_timer (*(uint16*)(g_ram+0x1BA3))

// Main menu stuff
#define menu_selection_missile_anim_timer (*(uint16*)(g_ram+0x198D))
#define menu_selection_file_copy_arrow_palette_timer (*(uint16*)(g_ram+0x198F))
#define menu_selection_slot_samus_helmet_anim_timer ((uint16*)(g_ram+0x1991))
#define menu_selection_slot_a_samus_helmet_anim_timer (*(uint16*)(g_ram+0x1991))
#define menu_selection_slot_b_samus_helmet_anim_timer (*(uint16*)(g_ram+0x1993))
#define menu_selection_slot_c_samus_helmet_anim_timer (*(uint16*)(g_ram+0x1995))
#define menu_selection_missile_anim_frame (*(uint16*)(g_ram+0x1997))

#define menu_selection_slot_samus_helmet_anim_frame ((uint16*)(g_ram+0x199B))
#define menu_selection_slot_a_samus_helmet_anim_frame (*(uint16*)(g_ram+0x199B))
#define menu_selection_slot_b_samus_helmet_anim_frame (*(uint16*)(g_ram+0x199D))
#define menu_selection_slot_c_samus_helmet_anim_frame (*(uint16*)(g_ram+0x199F))
#define menu_selection_missile_x_pos (*(uint16*)(g_ram+0x19A1))

#define menu_selection_slot_samus_helmet_x_pos ((uint16*)(g_ram+0x19A5))
#define menu_selection_slot_a_samus_helmet_x_pos (*(uint16*)(g_ram+0x19A5))
#define menu_selection_slot_b_samus_helmet_x_pos (*(uint16*)(g_ram+0x19A7))
#define menu_selection_slot_c_samus_helmet_x_pos (*(uint16*)(g_ram+0x19A9))
#define menu_selection_missile_y_pos (*(uint16*)(g_ram+0x19AB))

#define menu_selection_slot_samus_helmet_y_pos ((uint16*)(g_ram+0x19AF))
#define menu_selection_slot_a_samus_helmet_y_pos (*(uint16*)(g_ram+0x19AF))
#define menu_selection_slot_b_samus_helmet_y_pos (*(uint16*)(g_ram+0x19B1))
#define menu_selection_slot_c_samus_helmet_y_pos (*(uint16*)(g_ram+0x19B3))
#define menu_selection_file_copy_clear_select (*(uint16*)(g_ram+0x19B5))
#define menu_selection_file_copy_source_clear_slot (*(uint16*)(g_ram+0x19B7))
#define menu_selection_file_destination_slot (*(uint16*)(g_ram+0x19B9))

// Game options menu stuff
#define optionsmenu_index (*(uint16*)(g_ram+0x1A8F))
#define optionsmenu_init_param (*(uint16*)(g_ram+0x1A93))
#define optionsmenu_cur_data ((uint16*)(g_ram+0x1A9D))
#define optionsmenu_x_pos ((uint16*)(g_ram+0x1AAD))
#define optionsmenu_y_pos ((uint16*)(g_ram+0x1ABD))
#define optionsmenu_palette_index ((uint16*)(g_ram+0x1ACD))
#define UNUSED_optionsmenu_var0 ((uint16*)(g_ram+0x1ADD))
#define UNUSED_optionsmenu_var1 ((uint16*)(g_ram+0x1AED))
#define optionsmenu_instr_ptr ((uint16*)(g_ram+0x1AFD))
#define optionsmenu_preinstr_func ((uint16*)(g_ram+0x1B0D))
#define optionsmenu_instr_timer ((uint16*)(g_ram+0x1B1D))
#define optionsmenu_goto_timer ((uint16*)(g_ram+0x1B2D))
#define optionsmenu_input_bindings ((uint16*)(g_ram+0x1B3D))
