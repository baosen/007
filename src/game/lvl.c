#include "bondtypes.h"
#include "mainmenu.h"

unsigned int *ptr_jfont_DL;
int dword_CODE_bss_8008C264;
int dword_CODE_bss_8008C268;
int dword_CODE_bss_8008C26C;
char ramrom_data_target[0x380];
int record_slot_num;
int *address_demo_loaded;
int dword_CODE_bss_8008C5F8;

int lvl_c_debug_notice_list = 0;
int current_stage_to_load = 0;
float D_80048368 = 1.0;
int musictrack1_playing = 0;
int controls_locked_flag = 0;
int clock_timer = 0;

#ifdef VERSION_US
float global_timer_delta = 0;
int global_timer = 0;
int D_80048380 = 0;
#endif

#ifdef VERSION_JP
unsigned int jp_global_timer_delta = 0;
int global_timer = 0;
int D_80048380 = 0;
float global_timer_delta = 0;
#endif

int difficulty_0 = 0;
int D_80048388 = 0;
int D_8004838C = 0;
int D_80048390 = 0;
int D_80048394 = 0;
int mp_time = 0x8CA0;
int mp_point = 0xA;
int D_800483A0 = 0;
float cur_mp_sec = 0.0;
int D_800483A8 = 0;
float cur_mp_min = 0.0;
int D_800483B0 = 0;
float stage_time_sec = 0;
int D_800483B8 = 0;
float poweron_time_sec = 0;
int D_800483C0 = 1;
int D_800483C4 = 0xFFFFFFFF;
int D_800483C8 = 0;
int D_800483CC = 0;
int D_800483D0 = 0;
int D_800483D4 = 0;
int D_800483D8 = 0;
int D_800483DC = 0;
int D_800483E0 = 0;
int D_800483E4 = 0;

const char aLv_c_debug[] = "lv_c_debug";
const char aStanshow_[] = "-stanshow_";
const char aStanshow__5[] = "-stanshow_";
const char aStanshow__0[] = "-stanshow_";
const char aStanshow__1[] = "-stanshow_";
const char aStanshow__2[] = "-stanshow_";
const char aStanshow__3[] = "-stanshow_";
#ifndef VERSION_JP
const char aOneMinuteLeft[] = "One minute left";
#endif
const char aSetdetailDDDDDDDDD[] = "setdetail %d %d %d %d %d %d %d %d %d";

int sub_GAME_7F0BD8F0(void) { return D_800483C0; }

void sub_GAME_7F0BD8FC(int arg0) { D_800483C0 = arg0; }

asm(R"
glabel something_with_lvl_c_debug
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  lui   $a0, %hi(lvl_c_debug_notice_list)
  lui   $a1, %hi(aLv_c_debug)
  addiu $a1, %lo(aLv_c_debug) # addiu $a1, $a1, -0x4950
  jal   get_ptr_debug_notice_list_entry
   addiu $a0, %lo(lvl_c_debug_notice_list) # addiu $a0, $a0, -0x7ca0
  lui   $t7, %hi(_jfontdlSegmentEnd) # $t7, 0x11
  lui   $t8, %hi(_jfontdlSegmentStart) # $t8, 0x11
  addiu $t8, %lo(_jfontdlSegmentStart) # addiu $t8, $t8, 0x7880
  addiu $t7, %lo(_jfontdlSegmentEnd) # addiu $t7, $t7, 0x7940
  li    $t6, 1
  lui   $at, %hi(lvl_c_debug_notice_list)
  subu  $a2, $t7, $t8
  sw    $t6, %lo(lvl_c_debug_notice_list)($at)
  move  $a0, $a2
  sw    $a2, 0x18($sp)
  jal   mempAllocBytesInBank
   li    $a1, 6
  lui   $v1, %hi(ptr_jfont_DL)
  addiu $v1, %lo(ptr_jfont_DL) # addiu $v1, $v1, -0x3da0
  lui   $a1, %hi(_jfontdlSegmentStart) # $a1, 0x11
  sw    $v0, ($v1)
  lw    $a2, 0x18($sp)
  addiu $a1, %lo(_jfontdlSegmentStart) # addiu $a1, $a1, 0x7880
  jal   romCopy
   move  $a0, $v0
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

void playrandommusictrack1(void) {
  musictrack1_playing = (unsigned int)get_random_value() % 0x3d + M_INTRO;
  musicTrack1Play(musictrack1_playing);
}

void playmusictrack1(MUSIC_TRACKS track) {
  musictrack1_playing = track;
  musicTrack1Play(musictrack1_playing);
}

void music_append_play_solo_death_short(void) {
  musictrack1_playing = (musictrack1_playing + M_SHORT_SOLO_DEATH) % 0x3f;
  if (musictrack1_playing == M_NONE) {
    musictrack1_playing = M_SHORT_SOLO_DEATH;
  }
  musicTrack1Play(musictrack1_playing);
}

void music_append_play_endtheme(void) {
  musictrack1_playing = (musictrack1_playing + M_END_SOMETHING) % 0x3f;
  if (musictrack1_playing == M_NONE) {
    musictrack1_playing = M_END_SOMETHING;
  }
  musicTrack1Play(musictrack1_playing);
}

void sub_GAME_7F0BDA84(void) {
  playmusictrack1(getmusictrack_or_randomtrack(current_stage_to_load));
}

#ifdef VERSION_US
asm(R"
glabel stage_load
  lui   $at, %hi(current_stage_to_load)
  sw    $a0, %lo(current_stage_to_load)($at)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f12
  li    $v0, 1
  lui   $at, %hi(D_800483C0)
  addiu $sp, $sp, -0x38
  sw    $v0, %lo(D_800483C0)($at)
  sw    $s1, 0x24($sp)
  lui   $at, %hi(controls_locked_flag)
  lui   $s1, %hi(clock_timer)
  sw    $zero, %lo(controls_locked_flag)($at)
  addiu $s1, %lo(clock_timer) # addiu $s1, $s1, -0x7c8c
  sw    $v0, ($s1)
  lui   $at, %hi(global_timer_delta)
  swc1  $f12, %lo(global_timer_delta)($at)
  lui   $at, %hi(D_80048380)
  sw    $zero, %lo(D_80048380)($at)
  lui   $at, %hi(global_timer)
  sw    $zero, %lo(global_timer)($at)

  lui   $at, %hi(D_80048388)
  sw    $zero, %lo(D_80048388)($at)
  lui   $at, %hi(D_8004838C)
  sw    $zero, %lo(D_8004838C)($at)
  sw    $s0, 0x20($sp)
  lui   $at, %hi(D_80048390)
  mtc1  $zero, $f0
  lui   $s0, %hi(D_80048394)
  sw    $zero, %lo(D_80048390)($at)
  addiu $s0, %lo(D_80048394) # addiu $s0, $s0, -0x7c6c

  sw    $zero, ($s0)
  lui   $at, %hi(cur_mp_sec)
  swc1  $f0, %lo(cur_mp_sec)($at)
  lui   $at, %hi(D_800483B0)
  sw    $zero, %lo(D_800483B0)($at)
  lui   $at, %hi(stage_time_sec)
  swc1  $f0, %lo(stage_time_sec)($at)
  sw    $ra, 0x34($sp)
  lui   $at, %hi(D_800483A0)
  sw    $s4, 0x30($sp)
  sw    $s3, 0x2c($sp)
  sw    $s2, 0x28($sp)
  sdc1  $f20, 0x18($sp)
  sw    $a0, 0x38($sp)
  jal   sfx_c_70009238
   sw    $zero, %lo(D_800483A0)($at)
  jal   musicTrack1Vol
   li    $a0, 32767
  jal   musicTrack2Vol
   li    $a0, 32767
  jal   musicTrack3Vol
   li    $a0, 32767
  jal   sub_GAME_7F0C1364
   nop   
  jal   set_contents_of_80036078
   li    $a0, 1
  jal   set_mt_tex_alloc
   nop   
  jal   sub_GAME_7F0A47D4
   nop   
  jal   load_prepare_global_image_bank
   nop   
  jal   load_font_tables
   nop   
  lw    $t7, 0x38($sp)
  li    $at, 90
  bne   $t7, $at, .L7F0BDBD0
   nop   
  jal   init_menus_or_reset
   nop   
  b     .L7F0BDD98
   nop   
.L7F0BDBD0:
  lui   $a0, %hi(current_stage_to_load)
  lw    $a0, %lo(current_stage_to_load)($a0)
  lui    $at, %hi(newcheatunlocked) # -0.000000
  sw    $zero, %lo(newcheatunlocked)($at)
  li    $at, 90
  beq   $a0, $at, .L7F0BDC58
   nop   
  lw    $t8, ($s0)
  bnez  $t8, .L7F0BDC58
   nop   
  lw    $t9, ($s1)
  lui   $t0, %hi(append_cheat_sp) 
  blez  $t9, .L7F0BDC58
   nop   
  lw    $t0, %lo(append_cheat_sp)($t0)
  lui   $s1, %hi(CHEAT_AVAILABLE_EXTRA_CHARS)
  addiu $s1, %lo(CHEAT_AVAILABLE_EXTRA_CHARS) # addiu $s1, $s1, -0x695f
  beqz  $t0, .L7F0BDC58
   li    $s0, 1
  li    $s2, 75
.L7F0BDC20:
  lbu   $t1, ($s1)
  beql  $t1, $zero, .L7F0BDC48
   addiu $s0, $s0, 1
  jal   is_cheat_index_equal_to_1C
   move  $a0, $s0
  beql  $v0, $zero, .L7F0BDC48
   addiu $s0, $s0, 1
  jal   turn_on_cheat_for_players
   move  $a0, $s0
  addiu $s0, $s0, 1
.L7F0BDC48:
  bne   $s0, $s2, .L7F0BDC20
   addiu $s1, $s1, 1
  lui   $a0, %hi(current_stage_to_load)
  lw    $a0, %lo(current_stage_to_load)($a0)
.L7F0BDC58:
  jal   load_bg_file
   nop   
  lui   $a0, %hi(current_stage_to_load)
  jal   store_stagenum_to_copyof_stagenum
   lw    $a0, %lo(current_stage_to_load)($a0)
  jal   init_watch_at_start_of_stage
   nop   
  jal   sub_GAME_7F0C11FC
   lw    $a0, 0x38($sp)
  lui   $t2, %hi(player1_player_data)
  li    $at, 0x43480000 # 200.000000
  addiu $s2, $t2, %lo(player1_player_data)
  mtc1  $at, $f20
  move  $s4, $s2
  li    $s3, 4
.L7F0BDC94:
  jal   getPlayerCount
   nop   
  li    $at, 1
  bne   $v0, $at, .L7F0BDCC8
   move  $s0, $zero
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  mtc1  $at, $f6
  sb    $zero, 0x6a($s4)
  sb    $zero, 0x6b($s4)
  swc1  $f4, 0x5c($s4)
  b     .L7F0BDD34
   swc1  $f6, 0x64($s4)
.L7F0BDCC8:
  lui   $s1, %hi(player1_player_data)
  addiu $s1, %lo(player1_player_data) # addiu $s1, $s1, -0x6110
.L7F0BDCD0:
  jal   get_scenario
   nop   
  bne   $v0, $s3, .L7F0BDCE8
   nop   
  b     .L7F0BDCF4
   swc1  $f20, 0x5c($s1)
.L7F0BDCE8:
  jal   get_player_mp_handicap
   move  $a0, $s0
  swc1  $f0, 0x5c($s1)
.L7F0BDCF4:
  jal   get_player_mp_char_height
   move  $a0, $s0
  addiu $s0, $s0, 1
  addiu $s1, $s1, 0x70
  bne   $s0, $s3, .L7F0BDCD0
   swc1  $f0, -0xc($s1)
  jal   get_mp_timelimit
   nop   
  jal   set_mp_time
   move  $a0, $v0
  jal   get_mp_pointlimit
   nop   
  jal   set_mp_point
   move  $a0, $v0
  jal   copy_aim_settings_to_playerdata
   nop   
.L7F0BDD34:
  mtc1  $zero, $f8
  mtc1  $zero, $f10
  lui   $v0, (0x7FFFFFFF >> 16) # lui $v0, 0x7fff
  ori   $v0, (0x7FFFFFFF & 0xFFFF) # ori $v0, $v0, 0xffff
  sw    $zero, 0x34($s4)
  sw    $zero, 0x3c($s4)
  sw    $v0, 0x44($s4)
  sw    $zero, 0x48($s4)
  sw    $zero, 0x54($s4)
  sw    $zero, 0x58($s4)
  sw    $zero, 0x4c($s4)
  sw    $v0, 0x50($s4)
  sb    $zero, 0x68($s4)
  sw    $zero, 0x60($s4)
  swc1  $f8, 0x38($s4)
  swc1  $f10, 0x40($s4)
  lui   $t3, %hi(pPlayer) 
  addiu $t3, %lo(pPlayer) # addiu $t3, $t3, -0x5f50
  addiu $s2, $s2, 0x70
  addiu $s4, $s4, 0x70
  sw    $zero, -0x40($s2)
  sw    $zero, -0x44($s2)
  sw    $zero, -0x48($s2)
  bne   $s2, $t3, .L7F0BDC94
   sw    $zero, -0x4c($s2)
.L7F0BDD98:
  jal   something_with_stage_objectives
   nop   
  jal   unpause_game
   nop   
  jal   sub_GAME_7F09B820
   nop   
  jal   sub_GAME_7F005450
   nop   
  jal   zero_contents_of_80036070_74
   nop   
  jal   init_load_objpos_table
   nop   
  jal   reinit_between_menus
   nop   
  jal   init_sound_effects_registers
   nop   
  jal   init_guards
   nop   
  jal   set_new_rand_head_bodies
   lw    $a0, 0x38($sp)
  jal   proplvreset2
   lw    $a0, 0x38($sp)
  jal   alloc_explosion_smoke_casing_scorch_impact_buffers
   nop   
  jal   sub_GAME_7F007180
   nop   
  jal   sub_GAME_7F007290
   nop   
  jal   sub_GAME_7F0072B0
   nop   
  lui   $t4, %hi(current_stage_to_load) 
  lw    $t4, %lo(current_stage_to_load)($t4)
  li    $at, 90
  bne   $t4, $at, .L7F0BDE34
   nop   
  jal   disable_onscreen_cheat_text
   nop   
  b     .L7F0BDEB0
   nop   
.L7F0BDE34:
  jal   init_path_table_links
   nop   
  jal   something_with_ejected_cartridges
   nop   
  jal   getPlayerCount
   move  $s0, $zero
  blez  $v0, .L7F0BDEA8
   nop   
.L7F0BDE54:
  jal   set_cur_player
   move  $a0, $s0
  jal   sub_GAME_7F0061F0
   nop   
  jal   init_player_BONDdata_stats
   nop   
  jal   init_player_BONDdata
   nop   
  jal   load_camera_intro_type_values
   nop   
  jal   sub_GAME_7F0798B8
   nop   
  jal   sets_a_bunch_of_BONDdata_values_to_default
   nop   
  jal   disable_onscreen_cheat_text
   nop   
  jal   getPlayerCount
   addiu $s0, $s0, 1
  slt   $at, $s0, $v0
  bnez  $at, .L7F0BDE54
   nop   
.L7F0BDEA8:
  jal   set_cur_player
   move  $a0, $zero
.L7F0BDEB0:
  jal   set_contents_of_80036078
   move  $a0, $zero
  jal   zbufDeallocate
   nop   
  jal   setVideoWidthHeightToMode
   li    $a0, 1
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f16
  lui   $at, %hi(D_80048368)
  move  $a0, $zero
  jal   set_controls_locked_flag
   swc1  $f16, %lo(D_80048368)($at)
  lw    $ra, 0x34($sp)
  ldc1  $f20, 0x18($sp)
  lw    $s0, 0x20($sp)
  lw    $s1, 0x24($sp)
  lw    $s2, 0x28($sp)
  lw    $s3, 0x2c($sp)
  lw    $s4, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x38
");
#endif

#ifdef VERSION_JP
asm(R"
glabel stage_load
  lui   $at, %hi(current_stage_to_load) # $at, 0x8005
  sw    $a0, %lo(current_stage_to_load)($at)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f12
  li    $v0, 1
  lui   $at, %hi(D_800483C0) # $at, 0x8005
  addiu $sp, $sp, -0x38
  sw    $v0, %lo(D_800483C0)($at)
  sw    $s1, 0x24($sp)
  lui   $at, %hi(controls_locked_flag) # $at, 0x8005
  lui   $s1, %hi(clock_timer) # $s1, 0x8005
  sw    $zero, %lo(controls_locked_flag)($at)
  addiu $s1, %lo(clock_timer) # addiu $s1, $s1, -0x7c5c
  sw    $v0, ($s1)
  lui   $at, %hi(jp_global_timer_delta) # $at, 0x8005
  swc1  $f12, %lo(jp_global_timer_delta)($at)
  lui   $at, %hi(D_80048380) # $at, 0x8005
  sw    $zero, %lo(D_80048380)($at)
  lui   $at, %hi(global_timer) # $at, 0x8005
  sw    $zero, %lo(global_timer)($at)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4

  lui   $at, %hi(0x800483B4) # $at, 0x8005
  sw    $s0, 0x20($sp)
  swc1  $f4, %lo(0x800483B4)($at)
  lui   $at, %hi(D_80048388) # $at, 0x8005
  sw    $zero, %lo(D_80048388)($at)
  lui   $at, %hi(D_8004838C) # $at, 0x8005
  sw    $zero, %lo(D_8004838C)($at)
  lui   $at, %hi(D_80048390) # $at, 0x8005
  mtc1  $zero, $f0
  lui   $s0, %hi(D_80048394) # $s0, 0x8005
  sw    $zero, %lo(D_80048390)($at)
  addiu $s0, %lo(D_80048394) # addiu $s0, $s0, -0x7c38

  sw    $zero, ($s0)
  lui   $at, %hi(cur_mp_sec) # $at, 0x8005
  swc1  $f0, %lo(cur_mp_sec)($at)
  lui   $at, %hi(D_800483B0) # $at, 0x8005
  sw    $zero, %lo(D_800483B0)($at)
  lui   $at, %hi(stage_time_sec) # $at, 0x8005
  swc1  $f0, %lo(stage_time_sec)($at)
  sw    $ra, 0x34($sp)
  lui   $at, %hi(D_800483A0) # $at, 0x8005
  sw    $s4, 0x30($sp)
  sw    $s3, 0x2c($sp)
  sw    $s2, 0x28($sp)
  sdc1  $f20, 0x18($sp)
  sw    $a0, 0x38($sp)
  jal   sfx_c_70009238
   sw    $zero, %lo(D_800483A0)($at)
  jal   musicTrack1Vol
   li    $a0, 32767
  jal   musicTrack2Vol
   li    $a0, 32767
  jal   musicTrack3Vol
   li    $a0, 32767
  jal   sub_GAME_7F0C1364
   nop   
  jal   set_contents_of_80036078
   li    $a0, 1
  jal   set_mt_tex_alloc
   nop   
  jal   sub_GAME_7F0A47D4
   nop   
  jal   load_prepare_global_image_bank
   nop   
  jal   load_font_tables
   nop   
  lw    $t7, 0x38($sp)
  li    $at, 90
  bne   $t7, $at, .Ljp7F0BE790
   nop   
  jal   init_menus_or_reset
   nop   
  b     .Ljp7F0BE958
   nop   
.Ljp7F0BE790:
  lui   $a0, %hi(current_stage_to_load) # $a0, 0x8005
  lw    $a0, %lo(current_stage_to_load)($a0)
  lui    $at, %hi(newcheatunlocked)
  sw    $zero, %lo(newcheatunlocked)($at)
  li    $at, 90
  beq   $a0, $at, .Ljp7F0BE818
   nop   
  lw    $t8, ($s0)
  bnez  $t8, .Ljp7F0BE818
   nop   
  lw    $t9, ($s1)
  lui   $t0, %hi(append_cheat_sp) # $t0, 0x8003
  blez  $t9, .Ljp7F0BE818
   nop   
  lw    $t0, %lo(append_cheat_sp)($t0)
  lui   $s1, %hi(CHEAT_AVAILABLE_EXTRA_CHARS) # $s1, 0x8007
  addiu $s1, %lo(CHEAT_AVAILABLE_EXTRA_CHARS) # addiu $s1, $s1, -0x691f
  beqz  $t0, .Ljp7F0BE818
   li    $s0, 1
  li    $s2, 75
.Ljp7F0BE7E0:
  lbu   $t1, ($s1)
  beql  $t1, $zero, .Ljp7F0BE808
   addiu $s0, $s0, 1
  jal   is_cheat_index_equal_to_1C
   move  $a0, $s0
  beql  $v0, $zero, .Ljp7F0BE808
   addiu $s0, $s0, 1
  jal   turn_on_cheat_for_players
   move  $a0, $s0
  addiu $s0, $s0, 1
.Ljp7F0BE808:
  bne   $s0, $s2, .Ljp7F0BE7E0
   addiu $s1, $s1, 1
  lui   $a0, %hi(current_stage_to_load) # $a0, 0x8005
  lw    $a0, %lo(current_stage_to_load)($a0)
.Ljp7F0BE818:
  jal   load_bg_file
   nop   
  lui   $a0, %hi(current_stage_to_load) # $a0, 0x8005
  jal   store_stagenum_to_copyof_stagenum
   lw    $a0, %lo(current_stage_to_load)($a0)
  jal   init_watch_at_start_of_stage
   nop   
  jal   sub_GAME_7F0C11FC
   lw    $a0, 0x38($sp)
  lui   $t2, %hi(player1_player_data)
  li    $at, 0x43480000 # 200.000000
  addiu $s2, $t2, %lo(player1_player_data)
  mtc1  $at, $f20
  move  $s4, $s2
  li    $s3, 4
.Ljp7F0BE854:
  jal   getPlayerCount
   nop   
  li    $at, 1
  bne   $v0, $at, .Ljp7F0BE888
   move  $s0, $zero
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  mtc1  $at, $f8
  sb    $zero, 0x6a($s4)
  sb    $zero, 0x6b($s4)
  swc1  $f6, 0x5c($s4)
  b     .Ljp7F0BE8F4
   swc1  $f8, 0x64($s4)
.Ljp7F0BE888:
  lui   $s1, %hi(player1_player_data) # $s1, 0x8008
  addiu $s1, %lo(player1_player_data) # addiu $s1, $s1, -0x60a0
.Ljp7F0BE890:
  jal   get_scenario
   nop   
  bne   $v0, $s3, .Ljp7F0BE8A8
   nop   
  b     .Ljp7F0BE8B4
   swc1  $f20, 0x5c($s1)
.Ljp7F0BE8A8:
  jal   get_player_mp_handicap
   move  $a0, $s0
  swc1  $f0, 0x5c($s1)
.Ljp7F0BE8B4:
  jal   get_player_mp_char_height
   move  $a0, $s0
  addiu $s0, $s0, 1
  addiu $s1, $s1, 0x70
  bne   $s0, $s3, .Ljp7F0BE890
   swc1  $f0, -0xc($s1)
  jal   get_mp_timelimit
   nop   
  jal   set_mp_time
   move  $a0, $v0
  jal   get_mp_pointlimit
   nop   
  jal   set_mp_point
   move  $a0, $v0
  jal   copy_aim_settings_to_playerdata
   nop   
.Ljp7F0BE8F4:
  mtc1  $zero, $f10
  mtc1  $zero, $f16
  lui   $v0, (0x7FFFFFFF >> 16) # lui $v0, 0x7fff
  ori   $v0, (0x7FFFFFFF & 0xFFFF) # ori $v0, $v0, 0xffff
  sw    $zero, 0x34($s4)
  sw    $zero, 0x3c($s4)
  sw    $v0, 0x44($s4)
  sw    $zero, 0x48($s4)
  sw    $zero, 0x54($s4)
  sw    $zero, 0x58($s4)
  sw    $zero, 0x4c($s4)
  sw    $v0, 0x50($s4)
  sb    $zero, 0x68($s4)
  sw    $zero, 0x60($s4)
  swc1  $f10, 0x38($s4)
  swc1  $f16, 0x40($s4)
  lui   $t3, %hi(pPlayer) # $t3, 0x8008
  addiu $t3, %lo(pPlayer) # addiu $t3, $t3, -0x5ee0
  addiu $s2, $s2, 0x70
  addiu $s4, $s4, 0x70
  sw    $zero, -0x40($s2)
  sw    $zero, -0x44($s2)
  sw    $zero, -0x48($s2)
  bne   $s2, $t3, .Ljp7F0BE854
   sw    $zero, -0x4c($s2)
.Ljp7F0BE958:
  jal   something_with_stage_objectives
   nop   
  jal   unpause_game
   nop   
  jal   sub_GAME_7F09B820
   nop   
  jal   sub_GAME_7F005450
   nop   
  jal   zero_contents_of_80036070_74
   nop   
  jal   init_load_objpos_table
   nop   
  jal   reinit_between_menus
   nop   
  jal   init_sound_effects_registers
   nop   
  jal   init_guards
   nop   
  jal   set_new_rand_head_bodies
   lw    $a0, 0x38($sp)
  jal   proplvreset2
   lw    $a0, 0x38($sp)
  jal   alloc_explosion_smoke_casing_scorch_impact_buffers
   nop   
  jal   sub_GAME_7F007180
   nop   
  jal   sub_GAME_7F007290
   nop   
  jal   sub_GAME_7F0072B0
   nop   
  lui   $t4, %hi(current_stage_to_load) # $t4, 0x8005
  lw    $t4, %lo(current_stage_to_load)($t4)
  li    $at, 90
  bne   $t4, $at, .Ljp7F0BE9F4
   nop   
  jal   disable_onscreen_cheat_text
   nop   
  b     .Ljp7F0BEA70
   nop   
.Ljp7F0BE9F4:
  jal   init_path_table_links
   nop   
  jal   something_with_ejected_cartridges
   nop   
  jal   getPlayerCount
   move  $s0, $zero
  blez  $v0, .Ljp7F0BEA68
   nop   
.Ljp7F0BEA14:
  jal   set_cur_player
   move  $a0, $s0
  jal   sub_GAME_7F0061F0
   nop   
  jal   init_player_BONDdata_stats
   nop   
  jal   init_player_BONDdata
   nop   
  jal   load_camera_intro_type_values
   nop   
  jal   sub_GAME_7F0798B8
   nop   
  jal   sets_a_bunch_of_BONDdata_values_to_default
   nop   
  jal   disable_onscreen_cheat_text
   nop   
  jal   getPlayerCount
   addiu $s0, $s0, 1
  slt   $at, $s0, $v0
  bnez  $at, .Ljp7F0BEA14
   nop   
.Ljp7F0BEA68:
  jal   set_cur_player
   move  $a0, $zero
.Ljp7F0BEA70:
  jal   set_contents_of_80036078
   move  $a0, $zero
  jal   zbufDeallocate
   nop   
  jal   setVideoWidthHeightToMode
   li    $a0, 1
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f18
  lui   $at, %hi(D_80048368) # $at, 0x8005
  move  $a0, $zero
  jal   set_controls_locked_flag
   swc1  $f18, %lo(D_80048368)($at)
  lw    $ra, 0x34($sp)
  ldc1  $f20, 0x18($sp)
  lw    $s0, 0x20($sp)
  lw    $s1, 0x24($sp)
  lw    $s2, 0x28($sp)
  lw    $s3, 0x2c($sp)
  lw    $s4, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x38
");
#endif

int sub_GAME_7F0BDF04(void) { return current_stage_to_load; }

asm(R"
glabel sub_GAME_7F0BDF10
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  beqz  $a0, .L7F0BE00C
   sw    $zero, 0x20($sp)
  lui   $a1, %hi(D_800483CC)
  lw    $a1, %lo(D_800483CC)($a1)
  jal   sub_GAME_7F0B9DE4
   li    $a2, -1
  lui   $t6, %hi(D_800483D4) 
  lw    $t6, %lo(D_800483D4)($t6)
  lui   $t7, %hi(D_800483D8) 
  lw    $t7, %lo(D_800483D8)($t7)
  lui   $at, %hi(D_800483D0)
  lui   $t8, %hi(D_800483DC) 
  sw    $t6, %lo(D_800483D0)($at)
  lw    $t8, %lo(D_800483DC)($t8)
  lui   $at, %hi(D_800483D4)
  sw    $t7, %lo(D_800483D4)($at)
  lui   $v1, %hi(D_800483E0)
  lui   $at, %hi(D_800483D8)
  lw    $v1, %lo(D_800483E0)($v1)
  sw    $t8, %lo(D_800483D8)($at)
  lui   $at, %hi(D_800483DC)
  sw    $v0, 0x28($sp)
  move  $a0, $zero
  li    $a1, 32768
  jal   get_controller_buttons_held
   sw    $v1, %lo(D_800483DC)($at)
  andi  $s0, $v0, 0xffff
  li    $a0, 1
  jal   get_controller_buttons_held
   li    $a1, 32768
  lui   $t9, %hi(D_800483DC) 
  lw    $t9, %lo(D_800483DC)($t9)
  or    $v1, $v0, $s0
  lui   $t3, %hi(D_800483D0) 
  beq   $t9, $v1, .L7F0BDFC0
   lui   $t4, %hi(D_800483D4) 
  lui   $v0, %hi(D_800483C0)
  addiu $v0, %lo(D_800483C0) # addiu $v0, $v0, -0x7c40
  lw    $t1, ($v0)
  xori  $t2, $t1, 1
  sw    $t2, ($v0)
.L7F0BDFC0:
  lw    $t3, %lo(D_800483D0)($t3)
  lw    $t4, %lo(D_800483D4)($t4)
  lui   $v0, %hi(D_800483C0)
  addiu $v0, %lo(D_800483C0) # addiu $v0, $v0, -0x7c40
  beq   $t3, $t4, .L7F0BDFE4
   lui   $at, %hi(D_800483E0)
  lw    $t6, ($v0)
  xori  $t7, $t6, 1
  sw    $t7, ($v0)
.L7F0BDFE4:
  beqz  $v1, .L7F0BDFF8
   sw    $v1, %lo(D_800483E0)($at)
  lui   $a0, %hi(D_800483CC)
  b     .L7F0BDFFC
   lw    $a0, %lo(D_800483CC)($a0)
.L7F0BDFF8:
  li    $a0, -1
.L7F0BDFFC:
  jal   sub_GAME_7F0B9DF4
   nop   
  b     .L7F0BE2F8
   lw    $v0, 0x28($sp)
.L7F0BE00C:
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 512
  andi  $s0, $v0, 0xffff
  li    $a0, 1
  jal   get_controller_buttons_pressed
   li    $a1, 512
  or    $t8, $v0, $s0
  beqz  $t8, .L7F0BE05C
   li    $a1, 256
  lui   $a0, %hi(D_800483CC)
  lw    $a0, %lo(D_800483CC)($a0)
  li    $t9, 1
  lui   $at, %hi(D_800483CC)
  addiu $a0, $a0, -1
  sw    $a0, %lo(D_800483CC)($at)
  bgez  $a0, .L7F0BE05C
   sw    $t9, 0x20($sp)
  lui   $at, %hi(D_800483CC)
  sw    $zero, %lo(D_800483CC)($at)
.L7F0BE05C:
  jal   get_controller_buttons_pressed
   move  $a0, $zero
  andi  $s0, $v0, 0xffff
  li    $a0, 1
  jal   get_controller_buttons_pressed
   li    $a1, 256
  or    $t0, $v0, $s0
  beqz  $t0, .L7F0BE09C
   li    $a1, 16
  lui   $a0, %hi(D_800483CC)
  lw    $a0, %lo(D_800483CC)($a0)
  li    $t1, 1
  lui   $at, %hi(D_800483CC)
  addiu $a0, $a0, 1
  sw    $a0, %lo(D_800483CC)($at)
  sw    $t1, 0x20($sp)
.L7F0BE09C:
  jal   get_controller_buttons_held
   move  $a0, $zero
  andi  $s0, $v0, 0xffff
  li    $a0, 1
  jal   get_controller_buttons_held
   li    $a1, 16
  or    $t2, $v0, $s0
  beqz  $t2, .L7F0BE104
   move  $a0, $zero
  jal   get_controller_buttons_held
   li    $a1, 32
  andi  $s0, $v0, 0xffff
  li    $a0, 1
  jal   get_controller_buttons_held
   li    $a1, 32
  or    $t3, $v0, $s0
  beqz  $t3, .L7F0BE104
   move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 1024
  beqz  $v0, .L7F0BE2F4
   lui   $a0, %hi(D_800483CC)
  jal   sub_GAME_7F0B9B64
   lw    $a0, %lo(D_800483CC)($a0)
  b     .L7F0BE2F8
   move  $v0, $zero
.L7F0BE104:
  move  $a0, $zero
  jal   get_controller_buttons_held
   li    $a1, 16
  andi  $s0, $v0, 0xffff
  li    $a0, 1
  jal   get_controller_buttons_held
   li    $a1, 16
  or    $t4, $v0, $s0
  beqz  $t4, .L7F0BE1CC
   move  $a0, $zero
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 1024
  andi  $s0, $v0, 0xffff
  li    $a0, 1
  jal   get_controller_buttons_pressed
   li    $a1, 1024
  or    $t5, $v0, $s0
  beqz  $t5, .L7F0BE178
   lui   $a0, %hi(D_800483CC)
  jal   sub_GAME_7F0B9AE4
   lw    $a0, %lo(D_800483CC)($a0)
  bnez  $v0, .L7F0BE178
   lui   $a0, %hi(D_800483CC)
  li    $t6, 1
  sw    $t6, 0x20($sp)
  lw    $a0, %lo(D_800483CC)($a0)
  jal   sub_GAME_7F0B9DBC
   move  $a1, $zero
.L7F0BE178:
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 2048
  andi  $s0, $v0, 0xffff
  li    $a0, 1
  jal   get_controller_buttons_pressed
   li    $a1, 2048
  or    $t7, $v0, $s0
  beqz  $t7, .L7F0BE2F4
   lui   $a0, %hi(D_800483CC)
  jal   sub_GAME_7F0B9AE4
   lw    $a0, %lo(D_800483CC)($a0)
  beqz  $v0, .L7F0BE2F4
   lui   $a0, %hi(D_800483CC)
  li    $t8, 1
  sw    $t8, 0x20($sp)
  lw    $a0, %lo(D_800483CC)($a0)
  jal   sub_GAME_7F0B9DBC
   li    $a1, 1
  b     .L7F0BE2F8
   move  $v0, $zero
.L7F0BE1CC:
  jal   get_controller_buttons_held
   li    $a1, 32
  andi  $s0, $v0, 0xffff
  li    $a0, 1
  jal   get_controller_buttons_held
   li    $a1, 32
  or    $t9, $v0, $s0
  beqz  $t9, .L7F0BE288
   move  $a0, $zero
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 1024
  andi  $s0, $v0, 0xffff
  li    $a0, 1
  jal   get_controller_buttons_pressed
   li    $a1, 1024
  or    $t0, $v0, $s0
  beqz  $t0, .L7F0BE238
   lui   $a0, %hi(D_800483CC)
  jal   sub_GAME_7F0B9B04
   lw    $a0, %lo(D_800483CC)($a0)
  beqz  $v0, .L7F0BE238
   lui   $a0, %hi(D_800483CC)
  li    $t1, 1
  sw    $t1, 0x20($sp)
  jal   sub_GAME_7F0B9B44
   lw    $a0, %lo(D_800483CC)($a0)
.L7F0BE238:
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 2048
  andi  $s0, $v0, 0xffff
  li    $a0, 1
  jal   get_controller_buttons_pressed
   li    $a1, 2048
  or    $t2, $v0, $s0
  beqz  $t2, .L7F0BE2F4
   lui   $a0, %hi(D_800483CC)
  jal   sub_GAME_7F0B9B04
   lw    $a0, %lo(D_800483CC)($a0)
  bnez  $v0, .L7F0BE2F4
   lui   $a0, %hi(D_800483CC)
  li    $t3, 1
  sw    $t3, 0x20($sp)
  jal   sub_GAME_7F0B9B24
   lw    $a0, %lo(D_800483CC)($a0)
  b     .L7F0BE2F8
   move  $v0, $zero
.L7F0BE288:
  jal   get_controller_buttons_pressed
   li    $a1, 1024
  andi  $s0, $v0, 0xffff
  li    $a0, 1
  jal   get_controller_buttons_pressed
   li    $a1, 1024
  or    $t4, $v0, $s0
  beqz  $t4, .L7F0BE2BC
   lui   $a0, %hi(D_800483CC)
  li    $t5, 1
  sw    $t5, 0x20($sp)
  jal   sub_GAME_7F0B9A7C
   lw    $a0, %lo(D_800483CC)($a0)
.L7F0BE2BC:
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 2048
  andi  $s0, $v0, 0xffff
  li    $a0, 1
  jal   get_controller_buttons_pressed
   li    $a1, 2048
  or    $t6, $v0, $s0
  beqz  $t6, .L7F0BE2F4
   lui   $a0, %hi(D_800483CC)
  li    $t7, 1
  sw    $t7, 0x20($sp)
  jal   sub_GAME_7F0B9A2C
   lw    $a0, %lo(D_800483CC)($a0)
.L7F0BE2F4:
  move  $v0, $zero
.L7F0BE2F8:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

#ifdef VERSION_US
asm(R"
glabel sub_GAME_7F0BE30C
  addiu $sp, $sp, -0x60
  sw    $a0, 0x60($sp)
  addiu $t7, $a0, 8
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  sw    $t7, 0x60($sp)
  lui   $t8, (0xBC000006 >> 16) # lui $t8, 0xbc00
  ori   $t8, (0xBC000006 & 0xFFFF) # ori $t8, $t8, 6
  sw    $t8, ($a0)
  sw    $zero, 4($a0)
  lw    $s0, 0x60($sp)
  lui   $t2, (0xBC000406 >> 16) # lui $t2, 0xbc00
  ori   $t2, (0xBC000406 & 0xFFFF) # ori $t2, $t2, 0x406
  addiu $t1, $s0, 8
  sw    $t1, 0x60($sp)
  lui   $a0, %hi(ptr_jfont_DL)
  sw    $t2, ($s0)
  jal   osVirtualToPhysical
   lw    $a0, %lo(ptr_jfont_DL)($a0)
  sw    $v0, 4($s0)
  lw    $t3, 0x60($sp)
  lui   $t5, 0x100
  lui   $a1, 0x600
  addiu $t4, $t3, 8
  sw    $t4, 0x60($sp)
  addiu $t5, $t5, 0x40
  sw    $t5, 4($t3)
  sw    $a1, ($t3)
  lw    $t6, 0x60($sp)
  lui   $t8, 0x100
  addiu $t8, $t8, 0x20
  addiu $t7, $t6, 8
  sw    $t7, 0x60($sp)
  lui   $t9, %hi(current_stage_to_load) 
  sw    $t8, 4($t6)
  sw    $a1, ($t6)
  lw    $t9, %lo(current_stage_to_load)($t9)
  li    $at, 90
  bne   $t9, $at, .L7F0BE440
   nop   
  jal   video_related_10
   lw    $a0, 0x60($sp)
  sw    $v0, 0x60($sp)
  jal   video_related_F
   move  $a0, $v0
  addiu $t1, $v0, 8
  sw    $t1, 0x60($sp)
  lui   $t2, 0xed00
  sw    $t2, ($v0)
  jal   get_video2_settings_txtClipW
   move  $s0, $v0
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x22($sp)
  lh    $s1, 0x22($sp)
  mtc1  $v0, $f4
  li    $at, 0x40800000 # 4.000000
  mtc1  $s1, $f16
  cvt.s.w $f6, $f4
  mtc1  $at, $f0
  cvt.s.w $f18, $f16
  mul.s $f8, $f6, $f0
  nop   
  mul.s $f4, $f18, $f0
  trunc.w.s $f10, $f8
  trunc.w.s $f6, $f4
  mfc1  $t4, $f10
  mfc1  $t7, $f6
  andi  $t5, $t4, 0xfff
  andi  $t8, $t7, 0xfff
  sll   $t9, $t8, 0xc
  or    $t1, $t5, $t9
  sw    $t1, 4($s0)
  jal   menu_jump_constructor_handler
   lw    $a0, 0x60($sp)
  b     .L7F0BE844
   sw    $v0, 0x60($sp)
.L7F0BE440:
  jal   getPlayerCount
   nop   
  lw    $t2, 0x60($sp)
  sw    $v0, 0x44($sp)
  lui   $t4, (0xBC000404 >> 16) # lui $t4, 0xbc00
  addiu $t3, $t2, 8
  sw    $t3, 0x60($sp)
  li    $a3, 2
  ori   $t4, (0xBC000404 & 0xFFFF) # ori $t4, $t4, 0x404
  sw    $t4, ($t2)
  sw    $a3, 4($t2)
  lw    $t6, 0x60($sp)
  lui   $t8, (0xBC000C04 >> 16) # lui $t8, 0xbc00
  ori   $t8, (0xBC000C04 & 0xFFFF) # ori $t8, $t8, 0xc04
  addiu $t7, $t6, 8
  sw    $t7, 0x60($sp)
  sw    $a3, 4($t6)
  sw    $t8, ($t6)
  lw    $t5, 0x60($sp)
  lui   $t1, (0xBC001404 >> 16) # lui $t1, 0xbc00
  li    $t0, 65534
  addiu $t9, $t5, 8
  sw    $t9, 0x60($sp)
  ori   $t1, (0xBC001404 & 0xFFFF) # ori $t1, $t1, 0x1404
  sw    $t1, ($t5)
  sw    $t0, 4($t5)
  lw    $t2, 0x60($sp)
  lui   $t4, (0xBC001C04 >> 16) # lui $t4, 0xbc00
  ori   $t4, (0xBC001C04 & 0xFFFF) # ori $t4, $t4, 0x1c04
  addiu $t3, $t2, 8
  sw    $t3, 0x60($sp)
  move  $s1, $zero
  sw    $t0, 4($t2)
  blez  $v0, .L7F0BE844
   sw    $t4, ($t2)
  lui   $s0, %hi(pPlayer)
  addiu $s0, %lo(pPlayer) # addiu $s0, $s0, -0x5f50
.L7F0BE4D4:
  jal   sub_GAME_7F09B528
   move  $a0, $s1
  jal   set_cur_player
   move  $a0, $v0
  lw    $v0, ($s0)
  lh    $a0, 0x7f0($v0)
  jal   set_video2_width_height
   lh    $a1, 0x7f2($v0)
  lw    $v0, ($s0)
  lh    $a0, 0x7f4($v0)
  jal   set_video2_ulx_uly
   lh    $a1, 0x7f6($v0)
  lw    $t6, ($s0)
  jal   setvideo_far
   lwc1  $f12, 0x11d0($t6)
  lw    $t7, ($s0)
  jal   video_related_21
   lwc1  $f12, 0x11d4($t7)
  jal   video_related_10
   lw    $a0, 0x60($sp)
  sw    $v0, 0x60($sp)
  jal   video_related_F
   move  $a0, $v0
  jal   get_debug_render_raster
   sw    $v0, 0x60($sp)
  bnez  $v0, .L7F0BE54C
   nop   
  jal   sub_GAME_7F091580
   lw    $a0, 0x60($sp)
  sw    $v0, 0x60($sp)
.L7F0BE54C:
  jal   get_debug_render_raster
   nop   
  li    $at, 1
  bne   $v0, $at, .L7F0BE56C
   nop   
  jal   sub_GAME_7F0B2D48
   lw    $a0, 0x60($sp)
  sw    $v0, 0x60($sp)
.L7F0BE56C:
  jal   get_debug_render_raster
   nop   
  li    $at, 2
  bne   $v0, $at, .L7F0BE58C
   nop   
  jal   sub_GAME_7F087A08
   lw    $a0, 0x60($sp)
  sw    $v0, 0x60($sp)
.L7F0BE58C:
  jal   setupscreensfornumplayers
   lw    $a0, 0x60($sp)
  sw    $v0, 0x60($sp)
  jal   sub_GAME_7F094488
   move  $a0, $v0
  jal   sub_GAME_7F0B4884
   sw    $v0, 0x60($sp)
  jal   determing_type_of_object_and_detection
   nop   
  jal   sub_GAME_7F03A240
   nop   
  jal   sub_GAME_7F03D78C
   nop   
  jal   sub_GAME_7F03C294
   nop   
  jal   sub_GAME_7F089F38
   nop   
  beqz  $v0, .L7F0BE5F8
   nop   
  jal   sub_GAME_7F03C4F0
   nop   
  beqz  $v0, .L7F0BE5F8
   nop   
  jal   attempt_reload_item_in_hand
   move  $a0, $zero
  jal   attempt_reload_item_in_hand
   li    $a0, 1
.L7F0BE5F8:
  jal   sub_GAME_7F03D0D4
   nop   
  jal   sub_GAME_7F0B4E40
   lw    $a0, 0x60($sp)
  jal   get_debug_portal_flag
   sw    $v0, 0x60($sp)
  beqz  $v0, .L7F0BE624
   nop   
  jal   sub_GAME_7F0BDF10
   lw    $a0, 0x60($sp)
  sw    $v0, 0x60($sp)
.L7F0BE624:
  jal   get_turbo_mode_flag
   nop   
  beqz  $v0, .L7F0BE640
   nop   
  jal   sub_GAME_7F0B303C
   lw    $a0, 0x60($sp)
  sw    $v0, 0x60($sp)
.L7F0BE640:
  jal   get_debug_stanhit_flag
   nop   
  beqz  $v0, .L7F0BE668
   nop   
  jal   sub_GAME_7F0B3034
   lw    $a0, 0x60($sp)
  sw    $v0, 0x60($sp)
  jal   write_stan_tiles_in_yellow
   move  $a0, $v0
  sw    $v0, 0x60($sp)
.L7F0BE668:
  jal   get_debug_stanregion_flag
   nop   
  beqz  $v0, .L7F0BE694
   nop   
  jal   sub_GAME_7F0B3034
   lw    $a0, 0x60($sp)
  sw    $v0, 0x60($sp)
  move  $a0, $v0
  jal   sub_GAME_7F0B312C
   li    $a1, -32704
  sw    $v0, 0x60($sp)
.L7F0BE694:
  lui   $a1, %hi(aStanshow_)
  addiu $a1, %lo(aStanshow_) # addiu $a1, $a1, -0x4944
  jal   check_token
   li    $a0, 1
  beqz  $v0, .L7F0BE6EC
   li    $a0, 1
  lui   $a1, %hi(aStanshow__5)
  jal   check_token
   addiu $a1, %lo(aStanshow__5) # addiu $a1, $a1, -0x4938
  jal   stanMatchTileName
   move  $a0, $v0
  beqz  $v0, .L7F0BE6EC
   lw    $a0, 0x60($sp)
  jal   sub_GAME_7F0B3034
   sw    $v0, 0x30($sp)
  lui   $a2, (0xFF0000FF >> 16) # lui $a2, 0xff00
  lw    $a1, 0x30($sp)
  sw    $v0, 0x60($sp)
  ori   $a2, (0xFF0000FF & 0xFFFF) # ori $a2, $a2, 0xff
  jal   sub_GAME_7F0B3024
   move  $a0, $v0
  sw    $v0, 0x60($sp)
.L7F0BE6EC:
  lui   $a1, %hi(aStanshow__0)
  addiu $a1, %lo(aStanshow__0) # addiu $a1, $a1, -0x492c
  jal   check_token
   li    $a0, 2
  beqz  $v0, .L7F0BE744
   li    $a0, 2
  lui   $a1, %hi(aStanshow__1)
  jal   check_token
   addiu $a1, %lo(aStanshow__1) # addiu $a1, $a1, -0x4920
  jal   stanMatchTileName
   move  $a0, $v0
  beqz  $v0, .L7F0BE744
   lw    $a0, 0x60($sp)
  jal   sub_GAME_7F0B3034
   sw    $v0, 0x2c($sp)
  lui   $a2, (0x00FF00FF >> 16) # lui $a2, 0xff
  lw    $a1, 0x2c($sp)
  sw    $v0, 0x60($sp)
  ori   $a2, (0x00FF00FF & 0xFFFF) # ori $a2, $a2, 0xff
  jal   sub_GAME_7F0B3024
   move  $a0, $v0
  sw    $v0, 0x60($sp)
.L7F0BE744:
  lui   $a1, %hi(aStanshow__2)
  addiu $a1, %lo(aStanshow__2) # addiu $a1, $a1, -0x4914
  jal   check_token
   li    $a0, 3
  beqz  $v0, .L7F0BE798
   li    $a0, 3
  lui   $a1, %hi(aStanshow__3)
  jal   check_token
   addiu $a1, %lo(aStanshow__3) # addiu $a1, $a1, -0x4908
  jal   stanMatchTileName
   move  $a0, $v0
  beqz  $v0, .L7F0BE798
   lw    $a0, 0x60($sp)
  jal   sub_GAME_7F0B3034
   sw    $v0, 0x28($sp)
  lw    $a1, 0x28($sp)
  sw    $v0, 0x60($sp)
  move  $a0, $v0
  jal   sub_GAME_7F0B3024
   li    $a2, 65535
  sw    $v0, 0x60($sp)
.L7F0BE798:
  jal   get_debug_limit_controller_input
   nop   
  xori  $a0, $v0, 8
  jal   sub_GAME_7F022E24
   sltiu $a0, $a0, 1
  jal   sub_GAME_7F049B58
   lw    $a0, 0x60($sp)
  sw    $v0, 0x60($sp)
  addiu $a0, $sp, 0x60
  jal   sub_GAME_7F0A4824
   li    $a1, 1
  jal   sub_GAME_7F0A2C44
   lw    $a0, 0x60($sp)
  sw    $v0, 0x60($sp)
  jal   sub_GAME_7F0A0034
   move  $a0, $v0
  sw    $v0, 0x60($sp)
  jal   cheatCheckIfOn
   li    $a0, 11
  beqz  $v0, .L7F0BE7F4
   nop   
  jal   set_max_ammo_for_cur_player
   nop   
.L7F0BE7F4:
  jal   get_debug_render_raster
   nop   
  li    $at, 2
  bne   $v0, $at, .L7F0BE818
   nop   
  jal   maybe_mp_interface
   lw    $a0, 0x60($sp)
  b     .L7F0BE824
   sw    $v0, 0x60($sp)
.L7F0BE818:
  jal   sub_GAME_7F08BCB8
   lw    $a0, 0x60($sp)
  sw    $v0, 0x60($sp)
.L7F0BE824:
  jal   mp_watch_menu_display
   lw    $a0, 0x60($sp)
  lw    $t8, 0x44($sp)
  addiu $s1, $s1, 1
  sw    $v0, 0x60($sp)
  slt   $at, $s1, $t8
  bnez  $at, .L7F0BE4D4
   nop   
.L7F0BE844:
  lw    $s0, 0x60($sp)
  lui   $t1, 0xed00
  addiu $t9, $s0, 8
  sw    $t9, 0x60($sp)
  jal   get_video2_settings_txtClipW
   sw    $t1, ($s0)
  sll   $s1, $v0, 0x10
  sra   $t2, $s1, 0x10
  jal   get_video2_settings_txtClipH
   move  $s1, $t2
  mtc1  $v0, $f8
  mtc1  $s1, $f6
  li    $at, 0x40800000 # 4.000000
  cvt.s.w $f10, $f8
  mtc1  $at, $f16
  cvt.s.w $f8, $f6
  mul.s $f18, $f10, $f16
  mtc1  $at, $f10
  nop   
  mul.s $f16, $f8, $f10
  trunc.w.s $f4, $f18
  trunc.w.s $f18, $f16
  mfc1  $t4, $f4
  mfc1  $t8, $f18
  andi  $t6, $t4, 0xfff
  andi  $t5, $t8, 0xfff
  sll   $t9, $t5, 0xc
  or    $t1, $t6, $t9
  sw    $t1, 4($s0)
  lw    $ra, 0x1c($sp)
  lw    $s1, 0x18($sp)
  lw    $s0, 0x14($sp)
  lw    $v0, 0x60($sp)
  jr    $ra
   addiu $sp, $sp, 0x60
");
#endif

#ifdef VERSION_JP
asm(R"
glabel sub_GAME_7F0BE30C
  addiu $sp, $sp, -0x60
  sw    $a0, 0x60($sp)
  addiu $t7, $a0, 8
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  sw    $t7, 0x60($sp)
  lui   $t8, (0xBC000006 >> 16) # lui $t8, 0xbc00
  ori   $t8, (0xBC000006 & 0xFFFF) # ori $t8, $t8, 6
  sw    $t8, ($a0)
  sw    $zero, 4($a0)
  lw    $s0, 0x60($sp)
  lui   $t2, (0xBC000406 >> 16) # lui $t2, 0xbc00
  ori   $t2, (0xBC000406 & 0xFFFF) # ori $t2, $t2, 0x406
  addiu $t1, $s0, 8
  sw    $t1, 0x60($sp)
  lui   $a0, %hi(ptr_jfont_DL) # $a0, 0x8009
  sw    $t2, ($s0)
  jal   osVirtualToPhysical
   lw    $a0, %lo(ptr_jfont_DL)($a0)
  sw    $v0, 4($s0)
  lw    $t3, 0x60($sp)
  lui   $t5, 0x100
  lui   $a1, 0x600
  addiu $t4, $t3, 8
  sw    $t4, 0x60($sp)
  addiu $t5, $t5, 0x40
  sw    $t5, 4($t3)
  sw    $a1, ($t3)
  lw    $t6, 0x60($sp)
  lui   $t8, 0x100
  addiu $t8, $t8, 0x20
  addiu $t7, $t6, 8
  sw    $t7, 0x60($sp)
  lui   $t9, %hi(current_stage_to_load) # $t9, 0x8005
  sw    $t8, 4($t6)
  sw    $a1, ($t6)
  lw    $t9, %lo(current_stage_to_load)($t9)
  li    $at, 90
  bne   $t9, $at, .Ljp7F0BF000
   nop   
  jal   video_related_10
   lw    $a0, 0x60($sp)
  sw    $v0, 0x60($sp)
  jal   video_related_F
   move  $a0, $v0
  addiu $t1, $v0, 8
  sw    $t1, 0x60($sp)
  lui   $t2, 0xed00
  sw    $t2, ($v0)
  jal   get_video2_settings_txtClipW
   move  $s0, $v0
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x22($sp)
  lh    $s1, 0x22($sp)
  mtc1  $v0, $f4
  li    $at, 0x40800000 # 4.000000
  mtc1  $s1, $f16
  cvt.s.w $f6, $f4
  mtc1  $at, $f0
  cvt.s.w $f18, $f16
  mul.s $f8, $f6, $f0
  nop   
  mul.s $f4, $f18, $f0
  trunc.w.s $f10, $f8
  trunc.w.s $f6, $f4
  mfc1  $t4, $f10
  mfc1  $t7, $f6
  andi  $t5, $t4, 0xfff
  andi  $t8, $t7, 0xfff
  sll   $t9, $t8, 0xc
  or    $t1, $t5, $t9
  sw    $t1, 4($s0)
  jal   menu_jump_constructor_handler
   lw    $a0, 0x60($sp)
  b     .Ljp7F0BF428
   sw    $v0, 0x60($sp)
.Ljp7F0BF000:
  jal   getPlayerCount
   nop   
  lw    $t2, 0x60($sp)
  sw    $v0, 0x44($sp)
  lui   $t4, (0xBC000404 >> 16) # lui $t4, 0xbc00
  addiu $t3, $t2, 8
  sw    $t3, 0x60($sp)
  li    $a3, 2
  ori   $t4, (0xBC000404 & 0xFFFF) # ori $t4, $t4, 0x404
  sw    $t4, ($t2)
  sw    $a3, 4($t2)
  lw    $t6, 0x60($sp)
  lui   $t8, (0xBC000C04 >> 16) # lui $t8, 0xbc00
  ori   $t8, (0xBC000C04 & 0xFFFF) # ori $t8, $t8, 0xc04
  addiu $t7, $t6, 8
  sw    $t7, 0x60($sp)
  sw    $a3, 4($t6)
  sw    $t8, ($t6)
  lw    $t5, 0x60($sp)
  lui   $t1, (0xBC001404 >> 16) # lui $t1, 0xbc00
  li    $t0, 65534
  addiu $t9, $t5, 8
  sw    $t9, 0x60($sp)
  ori   $t1, (0xBC001404 & 0xFFFF) # ori $t1, $t1, 0x1404
  sw    $t1, ($t5)
  sw    $t0, 4($t5)
  lw    $t2, 0x60($sp)
  lui   $t4, (0xBC001C04 >> 16) # lui $t4, 0xbc00
  ori   $t4, (0xBC001C04 & 0xFFFF) # ori $t4, $t4, 0x1c04
  addiu $t3, $t2, 8
  sw    $t3, 0x60($sp)
  move  $s1, $zero
  sw    $t0, 4($t2)
  blez  $v0, .Ljp7F0BF428
   sw    $t4, ($t2)
  lui   $s0, %hi(pPlayer) # $s0, 0x8008
  addiu $s0, %lo(pPlayer) # addiu $s0, $s0, -0x5ee0
.Ljp7F0BF094:
  jal   sub_GAME_7F09B528
   move  $a0, $s1
  jal   set_cur_player
   move  $a0, $v0
  lw    $v0, ($s0)
  lh    $a0, 0x7f0($v0)
  jal   set_video2_width_height
   lh    $a1, 0x7f2($v0)
  lw    $v0, ($s0)
  lh    $a0, 0x7f4($v0)
  jal   set_video2_ulx_uly
   lh    $a1, 0x7f6($v0)
  lw    $t6, ($s0)
  jal   setvideo_far
   lwc1  $f12, 0x11d0($t6)
  lw    $t7, ($s0)
  jal   video_related_21
   lwc1  $f12, 0x11d4($t7)
  jal   video_related_10
   lw    $a0, 0x60($sp)
  sw    $v0, 0x60($sp)
  jal   video_related_F
   move  $a0, $v0
  jal   get_debug_render_raster
   sw    $v0, 0x60($sp)
  bnez  $v0, .Ljp7F0BF10C
   nop   
  jal   sub_GAME_7F091580
   lw    $a0, 0x60($sp)
  sw    $v0, 0x60($sp)
.Ljp7F0BF10C:
  jal   get_debug_render_raster
   nop   
  li    $at, 1
  bne   $v0, $at, .Ljp7F0BF12C
   nop   
  jal   sub_GAME_7F0B2D48
   lw    $a0, 0x60($sp)
  sw    $v0, 0x60($sp)
.Ljp7F0BF12C:
  jal   get_debug_render_raster
   nop   
  li    $at, 2
  bne   $v0, $at, .Ljp7F0BF14C
   nop   
  jal   sub_GAME_7F087A08
   lw    $a0, 0x60($sp)
  sw    $v0, 0x60($sp)
.Ljp7F0BF14C:
  jal   setupscreensfornumplayers
   lw    $a0, 0x60($sp)
  sw    $v0, 0x60($sp)
  jal   sub_GAME_7F094488
   move  $a0, $v0
  jal   sub_GAME_7F0B4884
   sw    $v0, 0x60($sp)
  jal   determing_type_of_object_and_detection
   nop   
  jal   sub_GAME_7F03A240
   nop   
  jal   sub_GAME_7F03D78C
   nop   
  jal   sub_GAME_7F03C294
   nop   
  jal   sub_GAME_7F089F38
   nop   
  beqz  $v0, .Ljp7F0BF1B8
   nop   
  jal   sub_GAME_7F03C4F0
   nop   
  beqz  $v0, .Ljp7F0BF1B8
   nop   
  jal   attempt_reload_item_in_hand
   move  $a0, $zero
  jal   attempt_reload_item_in_hand
   li    $a0, 1
.Ljp7F0BF1B8:
  jal   sub_GAME_7F03D0D4
   nop   
  jal   sub_GAME_7F0B4E40
   lw    $a0, 0x60($sp)
  jal   get_debug_portal_flag
   sw    $v0, 0x60($sp)
  beqz  $v0, .Ljp7F0BF1E4
   nop   
  jal   sub_GAME_7F0BDF10
   lw    $a0, 0x60($sp)
  sw    $v0, 0x60($sp)
.Ljp7F0BF1E4:
  jal   get_turbo_mode_flag
   nop   
  beqz  $v0, .Ljp7F0BF200
   nop   
  jal   sub_GAME_7F0B303C
   lw    $a0, 0x60($sp)
  sw    $v0, 0x60($sp)
.Ljp7F0BF200:
  jal   get_debug_stanhit_flag
   nop   
  beqz  $v0, .Ljp7F0BF228
   nop   
  jal   sub_GAME_7F0B3034
   lw    $a0, 0x60($sp)
  sw    $v0, 0x60($sp)
  jal   write_stan_tiles_in_yellow
   move  $a0, $v0
  sw    $v0, 0x60($sp)
.Ljp7F0BF228:
  jal   get_debug_stanregion_flag
   nop   
  beqz  $v0, .Ljp7F0BF254
   nop   
  jal   sub_GAME_7F0B3034
   lw    $a0, 0x60($sp)
  sw    $v0, 0x60($sp)
  move  $a0, $v0
  jal   sub_GAME_7F0B312C
   li    $a1, -32704
  sw    $v0, 0x60($sp)
.Ljp7F0BF254:
  lui   $a1, %hi(aStanshow_) # $a1, 0x8006
  addiu $a1, %lo(aStanshow_) # addiu $a1, $a1, -0x4904
  jal   check_token
   li    $a0, 1
  beqz  $v0, .Ljp7F0BF2AC
   li    $a0, 1
  lui   $a1, %hi(aStanshow__5) # $a1, 0x8006
  jal   check_token
   addiu $a1, %lo(aStanshow__5) # addiu $a1, $a1, -0x48f8
  jal   stanMatchTileName
   move  $a0, $v0
  beqz  $v0, .Ljp7F0BF2AC
   lw    $a0, 0x60($sp)
  jal   sub_GAME_7F0B3034
   sw    $v0, 0x30($sp)
  lui   $a2, (0xFF0000FF >> 16) # lui $a2, 0xff00
  lw    $a1, 0x30($sp)
  sw    $v0, 0x60($sp)
  ori   $a2, (0xFF0000FF & 0xFFFF) # ori $a2, $a2, 0xff
  jal   sub_GAME_7F0B3024
   move  $a0, $v0
  sw    $v0, 0x60($sp)
.Ljp7F0BF2AC:
  lui   $a1, %hi(aStanshow__0) # $a1, 0x8006
  addiu $a1, %lo(aStanshow__0) # addiu $a1, $a1, -0x48ec
  jal   check_token
   li    $a0, 2
  beqz  $v0, .Ljp7F0BF304
   li    $a0, 2
  lui   $a1, %hi(aStanshow__1) # $a1, 0x8006
  jal   check_token
   addiu $a1, %lo(aStanshow__1) # addiu $a1, $a1, -0x48e0
  jal   stanMatchTileName
   move  $a0, $v0
  beqz  $v0, .Ljp7F0BF304
   lw    $a0, 0x60($sp)
  jal   sub_GAME_7F0B3034
   sw    $v0, 0x2c($sp)
  lui   $a2, (0x00FF00FF >> 16) # lui $a2, 0xff
  lw    $a1, 0x2c($sp)
  sw    $v0, 0x60($sp)
  ori   $a2, (0x00FF00FF & 0xFFFF) # ori $a2, $a2, 0xff
  jal   sub_GAME_7F0B3024
   move  $a0, $v0
  sw    $v0, 0x60($sp)
.Ljp7F0BF304:
  lui   $a1, %hi(aStanshow__2) # $a1, 0x8006
  addiu $a1, %lo(aStanshow__2) # addiu $a1, $a1, -0x48d4
  jal   check_token
   li    $a0, 3
  beqz  $v0, .Ljp7F0BF358
   li    $a0, 3
  lui   $a1, %hi(aStanshow__3) # $a1, 0x8006
  jal   check_token
   addiu $a1, %lo(aStanshow__3) # addiu $a1, $a1, -0x48c8
  jal   stanMatchTileName
   move  $a0, $v0
  beqz  $v0, .Ljp7F0BF358
   lw    $a0, 0x60($sp)
  jal   sub_GAME_7F0B3034
   sw    $v0, 0x28($sp)
  lw    $a1, 0x28($sp)
  sw    $v0, 0x60($sp)
  move  $a0, $v0
  jal   sub_GAME_7F0B3024
   li    $a2, 65535
  sw    $v0, 0x60($sp)
.Ljp7F0BF358:
  jal   get_debug_limit_controller_input
   nop   
  xori  $a0, $v0, 8
  jal   sub_GAME_7F022E24
   sltiu $a0, $a0, 1
  jal   sub_GAME_7F049B58
   lw    $a0, 0x60($sp)
  sw    $v0, 0x60($sp)
  addiu $a0, $sp, 0x60
  jal   sub_GAME_7F0A4824
   li    $a1, 1
  jal   sub_GAME_7F0A2C44
   lw    $a0, 0x60($sp)
  sw    $v0, 0x60($sp)
  jal   sub_GAME_7F0A0034
   move  $a0, $v0
  sw    $v0, 0x60($sp)
  jal   cheatCheckIfOn
   li    $a0, 11
  beqz  $v0, .Ljp7F0BF3D8
   nop   
  jal   get_item_in_hand
   move  $a0, $zero
  li    $at, 23
  bne   $v0, $at, .Ljp7F0BF3D0
   nop   
  lw    $t8, ($s0)
  lw    $t5, 0xfcc($t8)
  bnez  $t5, .Ljp7F0BF3D8
   nop   
.Ljp7F0BF3D0:
  jal   set_max_ammo_for_cur_player
   nop   
.Ljp7F0BF3D8:
  jal   get_debug_render_raster
   nop   
  li    $at, 2
  bne   $v0, $at, .Ljp7F0BF3FC
   nop   
  jal   maybe_mp_interface
   lw    $a0, 0x60($sp)
  b     .Ljp7F0BF408
   sw    $v0, 0x60($sp)
.Ljp7F0BF3FC:
  jal   sub_GAME_7F08BCB8
   lw    $a0, 0x60($sp)
  sw    $v0, 0x60($sp)
.Ljp7F0BF408:
  jal   mp_watch_menu_display
   lw    $a0, 0x60($sp)
  lw    $t9, 0x44($sp)
  addiu $s1, $s1, 1
  sw    $v0, 0x60($sp)
  slt   $at, $s1, $t9
  bnez  $at, .Ljp7F0BF094
   nop   
.Ljp7F0BF428:
  lw    $s0, 0x60($sp)
  lui   $t3, 0xed00
  addiu $t2, $s0, 8
  sw    $t2, 0x60($sp)
  jal   get_video2_settings_txtClipW
   sw    $t3, ($s0)
  sll   $s1, $v0, 0x10
  sra   $t4, $s1, 0x10
  jal   get_video2_settings_txtClipH
   move  $s1, $t4
  mtc1  $v0, $f8
  mtc1  $s1, $f6
  li    $at, 0x40800000 # 4.000000
  cvt.s.w $f10, $f8
  mtc1  $at, $f16
  cvt.s.w $f8, $f6
  mul.s $f18, $f10, $f16
  mtc1  $at, $f10
  nop   
  mul.s $f16, $f8, $f10
  trunc.w.s $f4, $f18
  trunc.w.s $f18, $f16
  mfc1  $t7, $f4
  mfc1  $t9, $f18
  andi  $t8, $t7, 0xfff
  andi  $t1, $t9, 0xfff
  sll   $t2, $t1, 0xc
  or    $t3, $t8, $t2
  sw    $t3, 4($s0)
  lw    $ra, 0x1c($sp)
  lw    $s1, 0x18($sp)
  lw    $s0, 0x14($sp)
  lw    $v0, 0x60($sp)
  jr    $ra
   addiu $sp, $sp, 0x60
");
#endif

#ifdef VERSION_US
asm(R"
.late_rodata
glabel D_8005B73C
.word 0x3f19999a /*0.60000002*/
glabel D_8005B740
.word 0x3ef33334 /*0.47500002*/
glabel D_8005B744
.word 0x3f19999a /*0.60000002*/
glabel D_8005B748
.word 0x3e4ccccd /*0.2*/
glabel D_8005B74C
.word 0x3e4ccccd /*0.2*/
.text
glabel sub_GAME_7F0BE8D0
  lui   $v0, %hi(difficulty_0)
  lw    $v0, %lo(difficulty_0)($v0)
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  bnez  $v0, .L7F0BEA04
   li    $at, 1
  jal   get_BONDdata_watch_health
   nop   
  jal   get_BONDdata_watch_armor
   swc1  $f0, 0x1c($sp)
  lwc1  $f4, 0x1c($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f12
  add.s $f14, $f0, $f4
  li    $at, 0x3E000000 # 0.125000
  mtc1  $at, $f16
  lui   $at, %hi(D_8005B73C)
  c.le.s $f14, $f16
  nop   
  bc1f  .L7F0BE934
   nop   
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f12
  b     .L7F0BE96C
   lui   $at, 0x4000
.L7F0BE934:
  lwc1  $f6, %lo(D_8005B73C)($at)
  lui   $at, 0x3f00
  c.le.s $f14, $f6
  nop   
  bc1fl .L7F0BE96C
   li    $at, 0x40000000 # 2.000000
  sub.s $f8, $f14, $f16
  mtc1  $at, $f18
  lui   $at, %hi(D_8005B740)
  lwc1  $f4, %lo(D_8005B740)($at)
  mul.s $f10, $f8, $f18
  div.s $f6, $f10, $f4
  add.s $f12, $f6, $f18
  li    $at, 0x40000000 # 2.000000
.L7F0BE96C:
  mtc1  $at, $f2
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f18
  lui   $at, %hi(D_80030B14)
  swc1  $f2, %lo(D_80030B14)($at)
  mul.s $f0, $f18, $f12
  lui   $at, %hi(D_80030B18)
  swc1  $f2, %lo(D_80030B18)($at)
  lui   $at, %hi(D_80030B1C)
  swc1  $f0, %lo(D_80030B1C)($at)
  lui   $at, %hi(D_80030B20)
  swc1  $f0, %lo(D_80030B20)($at)
  lui   $at, %hi(D_80030B24)
  swc1  $f2, %lo(D_80030B24)($at)
  lui   $at, %hi(D_8005B744)
  lwc1  $f8, %lo(D_8005B744)($at)
  lui   $at, %hi(ai_accuracy_modifier)
  swc1  $f8, %lo(ai_accuracy_modifier)($at)
  lui   $at, %hi(ai_damage_modifier)
  swc1  $f0, %lo(ai_damage_modifier)($at)
  lui   $at, %hi(ai_health_modifier)
  swc1  $f2, %lo(ai_health_modifier)($at)
  li    $at, 0x3E800000 # 0.250000
  mtc1  $at, $f10
  lui   $at, %hi(D_80040178)
  mul.s $f4, $f10, $f12
  swc1  $f4, %lo(D_80040178)($at)
  li    $at, 0x3FC00000 # 1.500000
  mtc1  $at, $f6
  lui   $at, %hi(difficulty)
  swc1  $f6, %lo(difficulty)($at)
  lui   $at, %hi(solo_ammo_multiplier)
  swc1  $f2, %lo(solo_ammo_multiplier)($at)
  lui   $at, %hi(D_8005B748)
  lwc1  $f8, %lo(D_8005B748)($at)
  lui   $at, %hi(ai_reaction_speed)
  b     .L7F0BEB78
   swc1  $f8, %lo(ai_reaction_speed)($at)
.L7F0BEA04:
  bne   $v0, $at, .L7F0BEA8C
   li    $at, 0x3F400000 # 0.750000
  mtc1  $at, $f0
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f2
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f18
  lui   $at, %hi(D_80030B14)
  swc1  $f2, %lo(D_80030B14)($at)
  lui   $at, %hi(D_80030B18)
  swc1  $f2, %lo(D_80030B18)($at)
  lui   $at, %hi(D_80030B1C)
  swc1  $f0, %lo(D_80030B1C)($at)
  lui   $at, %hi(D_80030B20)
  swc1  $f0, %lo(D_80030B20)($at)
  lui   $at, %hi(D_80030B24)
  swc1  $f2, %lo(D_80030B24)($at)
  lui   $at, %hi(ai_accuracy_modifier)
  swc1  $f0, %lo(ai_accuracy_modifier)($at)
  lui   $at, %hi(ai_damage_modifier)
  swc1  $f0, %lo(ai_damage_modifier)($at)
  lui   $at, %hi(ai_health_modifier)
  swc1  $f2, %lo(ai_health_modifier)($at)
  lui   $at, %hi(D_80040178)
  swc1  $f0, %lo(D_80040178)($at)
  lui   $at, %hi(difficulty)
  swc1  $f0, %lo(difficulty)($at)
  li    $at, 0x3FC00000 # 1.500000
  mtc1  $at, $f10
  lui   $at, %hi(solo_ammo_multiplier)
  swc1  $f10, %lo(solo_ammo_multiplier)($at)
  lui   $at, %hi(ai_reaction_speed)
  b     .L7F0BEB78
   swc1  $f18, %lo(ai_reaction_speed)($at)
.L7F0BEA8C:
  li    $at, 2
  bne   $v0, $at, .L7F0BEB08
   li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f2
  lui   $at, %hi(D_80030B14)
  swc1  $f2, %lo(D_80030B14)($at)
  lui   $at, %hi(D_80030B18)
  swc1  $f2, %lo(D_80030B18)($at)
  lui   $at, %hi(D_80030B1C)
  swc1  $f2, %lo(D_80030B1C)($at)
  lui   $at, %hi(D_80030B20)
  swc1  $f2, %lo(D_80030B20)($at)
  lui   $at, %hi(D_80030B24)
  swc1  $f2, %lo(D_80030B24)($at)
  lui   $at, %hi(ai_accuracy_modifier)
  swc1  $f2, %lo(ai_accuracy_modifier)($at)
  lui   $at, %hi(ai_damage_modifier)
  swc1  $f2, %lo(ai_damage_modifier)($at)
  lui   $at, %hi(ai_health_modifier)
  swc1  $f2, %lo(ai_health_modifier)($at)
  lui   $at, %hi(D_80040178)
  swc1  $f2, %lo(D_80040178)($at)
  lui   $at, %hi(D_8005B74C)
  lwc1  $f4, %lo(D_8005B74C)($at)
  lui   $at, %hi(difficulty)
  swc1  $f4, %lo(difficulty)($at)
  lui   $at, %hi(solo_ammo_multiplier)
  swc1  $f2, %lo(solo_ammo_multiplier)($at)
  lui   $at, %hi(ai_reaction_speed)
  b     .L7F0BEB78
   swc1  $f2, %lo(ai_reaction_speed)($at)
.L7F0BEB08:
  li    $at, 3
  bne   $v0, $at, .L7F0BEB78
   li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f2
  lui   $at, %hi(D_80030B14)
  swc1  $f2, %lo(D_80030B14)($at)
  lui   $at, %hi(D_80030B18)
  swc1  $f2, %lo(D_80030B18)($at)
  lui   $at, %hi(D_80030B1C)
  swc1  $f2, %lo(D_80030B1C)($at)
  lui   $at, %hi(D_80030B20)
  swc1  $f2, %lo(D_80030B20)($at)
  lui   $at, %hi(D_80030B24)
  swc1  $f2, %lo(D_80030B24)($at)
  lui   $at, %hi(ai_accuracy_modifier)
  swc1  $f2, %lo(ai_accuracy_modifier)($at)
  lui   $at, %hi(ai_damage_modifier)
  swc1  $f2, %lo(ai_damage_modifier)($at)
  lui   $at, %hi(ai_health_modifier)
  swc1  $f2, %lo(ai_health_modifier)($at)
  lui   $at, %hi(D_80040178)
  swc1  $f2, %lo(D_80040178)($at)
  lui   $at, %hi(difficulty)
  swc1  $f2, %lo(difficulty)($at)
  lui   $at, %hi(solo_ammo_multiplier)
  swc1  $f2, %lo(solo_ammo_multiplier)($at)
  lui   $at, %hi(ai_reaction_speed)
  swc1  $f2, %lo(ai_reaction_speed)($at)
.L7F0BEB78:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");
#endif

#ifdef VERSION_JP
asm(R"
.late_rodata
glabel D_8005B73C
.word 0x3f19999a /*0.60000002*/
glabel D_8005B740
.word 0x3ef33334 /*0.47500002*/
glabel D_8005B744
.word 0x3f19999a /*0.60000002*/
glabel D_8005B748
.word 0x3e4ccccd /*0.2*/
glabel D_8005B74C
.word 0x3f8ccccd 
glabel jpD_8005B780
.word 0x3e4ccccd /*0.2*/
.text
glabel sub_GAME_7F0BE8D0
  lui   $v0, %hi(difficulty_0) # $v0, 0x8005
  lw    $v0, %lo(difficulty_0)($v0)
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  bnez  $v0, .Ljp7F0BF5E8
   li    $at, 1
  jal   get_BONDdata_watch_health
   nop   
  jal   get_BONDdata_watch_armor
   swc1  $f0, 0x1c($sp)
  lwc1  $f4, 0x1c($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f12
  add.s $f14, $f0, $f4
  li    $at, 0x3E000000 # 0.125000
  mtc1  $at, $f16
  lui   $at, %hi(D_8005B73C)
  c.le.s $f14, $f16
  nop   
  bc1f  .Ljp7F0BF518
   nop   
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f12
  b     .Ljp7F0BF550
   lui   $at, 0x4000
.Ljp7F0BF518:
  lwc1  $f6, %lo(D_8005B73C)($at)
  lui   $at, 0x3f00
  c.le.s $f14, $f6
  nop   
  bc1fl .Ljp7F0BF550
   li    $at, 0x40000000 # 2.000000
  sub.s $f8, $f14, $f16
  mtc1  $at, $f18
  lui   $at, %hi(D_8005B740) # $at, 0x8006
  lwc1  $f4, %lo(D_8005B740)($at)
  mul.s $f10, $f8, $f18
  div.s $f6, $f10, $f4
  add.s $f12, $f6, $f18
  li    $at, 0x40000000 # 2.000000
.Ljp7F0BF550:
  mtc1  $at, $f2
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f18
  lui   $at, %hi(D_80030B14) # $at, 0x8003
  swc1  $f2, %lo(D_80030B14)($at)
  mul.s $f0, $f18, $f12
  lui   $at, %hi(D_80030B18) # $at, 0x8003
  swc1  $f2, %lo(D_80030B18)($at)
  lui   $at, %hi(D_80030B1C) # $at, 0x8003
  swc1  $f0, %lo(D_80030B1C)($at)
  lui   $at, %hi(D_80030B20) # $at, 0x8003
  swc1  $f0, %lo(D_80030B20)($at)
  lui   $at, %hi(D_80030B24) # $at, 0x8003
  swc1  $f2, %lo(D_80030B24)($at)
  lui   $at, %hi(D_8005B744) # $at, 0x8006
  lwc1  $f8, %lo(D_8005B744)($at)
  lui   $at, %hi(ai_accuracy_modifier) # $at, 0x8003
  swc1  $f8, %lo(ai_accuracy_modifier)($at)
  lui   $at, %hi(ai_damage_modifier) # $at, 0x8003
  swc1  $f0, %lo(ai_damage_modifier)($at)
  lui   $at, %hi(ai_health_modifier) # $at, 0x8003
  swc1  $f2, %lo(ai_health_modifier)($at)
  li    $at, 0x3E800000 # 0.250000
  mtc1  $at, $f10
  lui   $at, %hi(D_80040178) # $at, 0x8004
  mul.s $f4, $f10, $f12
  swc1  $f4, %lo(D_80040178)($at)
  li    $at, 0x3FC00000 # 1.500000
  mtc1  $at, $f6
  lui   $at, %hi(difficulty) # $at, 0x8003
  swc1  $f6, %lo(difficulty)($at)
  lui   $at, %hi(solo_ammo_multiplier) # $at, 0x8003
  swc1  $f2, %lo(solo_ammo_multiplier)($at)
  lui   $at, %hi(D_8005B748) # $at, 0x8006
  lwc1  $f8, %lo(D_8005B748)($at)
  lui   $at, %hi(ai_reaction_speed) # $at, 0x8003
  b     .Ljp7F0BF79C
   swc1  $f8, %lo(ai_reaction_speed)($at)
.Ljp7F0BF5E8:
  bne   $v0, $at, .Ljp7F0BF690
   lui   $t6, %hi(j_text_trigger) # $t6, 0x8005
  li    $at, 0x3F400000 # 0.750000
  mtc1  $at, $f0
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f2
  lui   $at, %hi(D_80030B14) # $at, 0x8003
  lw    $t6, %lo(j_text_trigger)($t6)
  swc1  $f2, %lo(D_80030B14)($at)
  lui   $at, %hi(D_80030B18) # $at, 0x8003
  swc1  $f2, %lo(D_80030B18)($at)
  lui   $at, %hi(D_80030B1C) # $at, 0x8003
  swc1  $f0, %lo(D_80030B1C)($at)
  lui   $at, %hi(D_80030B20) # $at, 0x8003
  swc1  $f0, %lo(D_80030B20)($at)
  lui   $at, %hi(D_80030B24) # $at, 0x8003
  swc1  $f2, %lo(D_80030B24)($at)
  lui   $at, %hi(ai_accuracy_modifier) # $at, 0x8003
  swc1  $f0, %lo(ai_accuracy_modifier)($at)
  lui   $at, %hi(ai_damage_modifier) # $at, 0x8003
  swc1  $f0, %lo(ai_damage_modifier)($at)
  lui   $at, %hi(ai_health_modifier) # $at, 0x8003
  swc1  $f2, %lo(ai_health_modifier)($at)
  lui   $at, %hi(D_80040178) # $at, 0x8004
  beqz  $t6, .Ljp7F0BF664
   swc1  $f0, %lo(D_80040178)($at)
  lui   $at, %hi(D_8005B74C) # $at, 0x8006
  lwc1  $f10, %lo(D_8005B74C)($at)
  lui   $at, %hi(difficulty) # $at, 0x8003
  b     .Ljp7F0BF66C
   swc1  $f10, %lo(difficulty)($at)
.Ljp7F0BF664:
  lui   $at, %hi(difficulty) # $at, 0x8003
  swc1  $f0, %lo(difficulty)($at)
.Ljp7F0BF66C:
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f18
  li    $at, 0x3FC00000 # 1.500000
  mtc1  $at, $f4
  lui   $at, %hi(solo_ammo_multiplier) # $at, 0x8003
  swc1  $f4, %lo(solo_ammo_multiplier)($at)
  lui   $at, %hi(ai_reaction_speed) # $at, 0x8003
  b     .Ljp7F0BF79C
   swc1  $f18, %lo(ai_reaction_speed)($at)
.Ljp7F0BF690:
  li    $at, 2
  bne   $v0, $at, .Ljp7F0BF72C
   lui   $t7, %hi(j_text_trigger) # $t7, 0x8005
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f2
  lui   $at, %hi(D_80030B14) # $at, 0x8003
  lw    $t7, %lo(j_text_trigger)($t7)
  swc1  $f2, %lo(D_80030B14)($at)
  lui   $at, %hi(D_80030B18) # $at, 0x8003
  swc1  $f2, %lo(D_80030B18)($at)
  lui   $at, %hi(D_80030B1C) # $at, 0x8003
  swc1  $f2, %lo(D_80030B1C)($at)
  lui   $at, %hi(D_80030B20) # $at, 0x8003
  swc1  $f2, %lo(D_80030B20)($at)
  lui   $at, %hi(D_80030B24) # $at, 0x8003
  swc1  $f2, %lo(D_80030B24)($at)
  lui   $at, %hi(ai_accuracy_modifier) # $at, 0x8003
  swc1  $f2, %lo(ai_accuracy_modifier)($at)
  lui   $at, %hi(ai_damage_modifier) # $at, 0x8003
  swc1  $f2, %lo(ai_damage_modifier)($at)
  lui   $at, %hi(ai_health_modifier) # $at, 0x8003
  swc1  $f2, %lo(ai_health_modifier)($at)
  lui   $at, %hi(D_80040178) # $at, 0x8004
  beqz  $t7, .Ljp7F0BF708
   swc1  $f2, %lo(D_80040178)($at)
  li    $at, 0x3F400000 # 0.750000
  mtc1  $at, $f0
  lui   $at, %hi(difficulty) # $at, 0x8003
  b     .Ljp7F0BF718
   swc1  $f0, %lo(difficulty)($at)
.Ljp7F0BF708:
  lui   $at, %hi(jpD_8005B780) # $at, 0x8006
  lwc1  $f6, %lo(jpD_8005B780)($at)
  lui   $at, %hi(difficulty) # $at, 0x8003
  swc1  $f6, %lo(difficulty)($at)
.Ljp7F0BF718:
  lui   $at, %hi(solo_ammo_multiplier) # $at, 0x8003
  swc1  $f2, %lo(solo_ammo_multiplier)($at)
  lui   $at, %hi(ai_reaction_speed) # $at, 0x8003
  b     .Ljp7F0BF79C
   swc1  $f2, %lo(ai_reaction_speed)($at)
.Ljp7F0BF72C:
  li    $at, 3
  bne   $v0, $at, .Ljp7F0BF79C
   li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f2
  lui   $at, %hi(D_80030B14) # $at, 0x8003
  swc1  $f2, %lo(D_80030B14)($at)
  lui   $at, %hi(D_80030B18) # $at, 0x8003
  swc1  $f2, %lo(D_80030B18)($at)
  lui   $at, %hi(D_80030B1C) # $at, 0x8003
  swc1  $f2, %lo(D_80030B1C)($at)
  lui   $at, %hi(D_80030B20) # $at, 0x8003
  swc1  $f2, %lo(D_80030B20)($at)
  lui   $at, %hi(D_80030B24) # $at, 0x8003
  swc1  $f2, %lo(D_80030B24)($at)
  lui   $at, %hi(ai_accuracy_modifier) # $at, 0x8003
  swc1  $f2, %lo(ai_accuracy_modifier)($at)
  lui   $at, %hi(ai_damage_modifier) # $at, 0x8003
  swc1  $f2, %lo(ai_damage_modifier)($at)
  lui   $at, %hi(ai_health_modifier) # $at, 0x8003
  swc1  $f2, %lo(ai_health_modifier)($at)
  lui   $at, %hi(D_80040178) # $at, 0x8004
  swc1  $f2, %lo(D_80040178)($at)
  lui   $at, %hi(difficulty) # $at, 0x8003
  swc1  $f2, %lo(difficulty)($at)
  lui   $at, %hi(solo_ammo_multiplier) # $at, 0x8003
  swc1  $f2, %lo(solo_ammo_multiplier)($at)
  lui   $at, %hi(ai_reaction_speed) # $at, 0x8003
  swc1  $f2, %lo(ai_reaction_speed)($at)
.Ljp7F0BF79C:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");
#endif

#ifdef VERSION_US
asm(R"
glabel manage_mp_game
  addiu $sp, $sp, -0x198
  sw    $ra, 0x14($sp)
  jal   mp_tlb_related
   nop   
  lui   $t6, %hi(controls_locked_flag) 
  lw    $t6, %lo(controls_locked_flag)($t6)
  lui   $at, %hi(clock_timer)
  beqz  $t6, .L7F0BEBB4
   nop   
  b     .L7F0BEBF0
   sw    $zero, %lo(clock_timer)($at)
.L7F0BEBB4:
  jal   checkGamePaused
   nop   
  beqz  $v0, .L7F0BEBD0
   lui   $t7, %hi(D_80048498) 
  lui   $at, %hi(clock_timer)
  b     .L7F0BEBF0
   sw    $zero, %lo(clock_timer)($at)
.L7F0BEBD0:
  lw    $t7, %lo(D_80048498)($t7)
  lui   $v0, %hi(D_80048380)
  lui   $at, %hi(clock_timer)
  addiu $v0, %lo(D_80048380) # addiu $v0, $v0, -0x7c80
  sw    $t7, %lo(clock_timer)($at)
  lw    $t8, ($v0)
  addiu $t9, $t8, 1
  sw    $t9, ($v0)
.L7F0BEBF0:
  lui   $v0, %hi(clock_timer)
  lw    $v0, %lo(clock_timer)($v0)
  lui   $v1, %hi(global_timer)
  lui   $at, %hi(global_timer_delta)
  mtc1  $v0, $f4
  addiu $v1, %lo(global_timer) # addiu $v1, $v1, -0x7c84
  lui   $t8, %hi(current_stage_to_load) 
  cvt.s.w $f6, $f4
  lui   $t9, %hi(D_80048394) 
  swc1  $f6, %lo(global_timer_delta)($at)
  lw    $t6, ($v1)
  li    $at, 90
  addu  $t7, $t6, $v0
  sw    $t7, ($v1)
  lw    $t8, %lo(current_stage_to_load)($t8)
  beq   $t8, $at, .L7F0BECA4
   nop   
  lw    $t9, %lo(D_80048394)($t9)
  bnez  $t9, .L7F0BECA4
   nop   
  blez  $v0, .L7F0BECA4
   lui   $t6, %hi(append_cheat_sp) 
  lw    $t6, %lo(append_cheat_sp)($t6)
  lui   $v1, %hi(CHEAT_AVAILABLE_EXTRA_CHARS)
  addiu $v1, %lo(CHEAT_AVAILABLE_EXTRA_CHARS) # addiu $v1, $v1, -0x695f
  beqz  $t6, .L7F0BECA4
   li    $a0, 1
.L7F0BEC5C:
  lbu   $t7, ($v1)
  beql  $t7, $zero, .L7F0BEC98
   addiu $a0, $a0, 1
  sw    $v1, 0x1c($sp)
  jal   is_cheat_index_equal_to_1C
   sw    $a0, 0x194($sp)
  lw    $v1, 0x1c($sp)
  bnez  $v0, .L7F0BEC94
   lw    $a0, 0x194($sp)
  sw    $v1, 0x1c($sp)
  jal   turn_on_cheat_for_players
   sw    $a0, 0x194($sp)
  lw    $v1, 0x1c($sp)
  lw    $a0, 0x194($sp)
.L7F0BEC94:
  addiu $a0, $a0, 1
.L7F0BEC98:
  li    $at, 75
  bne   $a0, $at, .L7F0BEC5C
   addiu $v1, $v1, 1
.L7F0BECA4:
  jal   getPlayerCount
   nop   
  slti  $at, $v0, 2
  bnez  $at, .L7F0BF1E0
   lui   $t8, %hi(current_stage_to_load) 
  lw    $t8, %lo(current_stage_to_load)($t8)
  li    $at, 90
  beq   $t8, $at, .L7F0BF1E0
   nop   
  jal   get_mission_state
   nop   
  li    $at, 6
  bne   $v0, $at, .L7F0BED7C
   nop   
  sw    $zero, 0x190($sp)
  sw    $zero, 0x18c($sp)
  jal   getPlayerCount
   sw    $zero, 0x188($sp)
  lw    $v1, 0x190($sp)
  lw    $a1, 0x18c($sp)
  blez  $v0, .L7F0BED64
   lw    $a2, 0x188($sp)
  lui   $t6, %hi(ptr_BONDdata_p1) 
  addiu $t6, %lo(ptr_BONDdata_p1) # addiu $t6, $t6, -0x6120
  sll   $t9, $v1, 2
  addu  $a0, $t9, $t6
.L7F0BED0C:
  lw    $v0, ($a0)
  addiu $v1, $v1, 1
  addiu $a0, $a0, 4
  lw    $t7, 0xd8($v0)
  beql  $t7, $zero, .L7F0BED3C
   sw    $v1, 0x190($sp)
  lw    $t8, 0x424($v0)
  addiu $a1, $a1, 1
  beql  $t8, $zero, .L7F0BED3C
   sw    $v1, 0x190($sp)
  addiu $a2, $a2, 1
  sw    $v1, 0x190($sp)
.L7F0BED3C:
  sw    $a0, 0x1c($sp)
  sw    $a1, 0x18c($sp)
  jal   getPlayerCount
   sw    $a2, 0x188($sp)
  lw    $v1, 0x190($sp)
  lw    $a0, 0x1c($sp)
  lw    $a1, 0x18c($sp)
  slt   $at, $v1, $v0
  bnez  $at, .L7F0BED0C
   lw    $a2, 0x188($sp)
.L7F0BED64:
  blez  $a1, .L7F0BED7C
   nop   
  bne   $a1, $a2, .L7F0BED7C
   nop   
  jal   set_missionstate
   li    $a0, 1
.L7F0BED7C:
  lui   $v1, %hi(mp_time)
  lw    $v1, %lo(mp_time)($v1)
  lui   $v0, %hi(D_80048394)
  lui   $t9, %hi(clock_timer) 
  blez  $v1, .L7F0BEEB4
   nop   
  lw    $v0, %lo(D_80048394)($v0)
  lw    $t9, %lo(clock_timer)($t9)
  addiu $a0, $v1, -0xe10
  slt   $at, $v0, $a0
  addu  $t6, $t9, $v0
  sw    $t6, 0x180($sp)
  beqz  $at, .L7F0BEE04
   sw    $v0, 0x184($sp)
  slt   $at, $t6, $a0
  bnez  $at, .L7F0BEE04
   nop   
  jal   getPlayerCount
   sw    $zero, 0x17c($sp)
  blez  $v0, .L7F0BEE04
   nop   
.L7F0BEDD0:
  jal   set_cur_player
   lw    $a0, 0x17c($sp)
  lui   $a0, %hi(aOneMinuteLeft)
  jal   display_string_in_lower_left_corner
   addiu $a0, %lo(aOneMinuteLeft) # addiu $a0, $a0, -0x48fc
  lw    $t7, 0x17c($sp)
  addiu $t8, $t7, 1
  jal   getPlayerCount
   sw    $t8, 0x17c($sp)
  lw    $t9, 0x17c($sp)
  slt   $at, $t9, $v0
  bnez  $at, .L7F0BEDD0
   nop   
.L7F0BEE04:
  lui   $t7, %hi(mp_time) 
  lw    $t7, %lo(mp_time)($t7)
  lw    $t6, 0x180($sp)
  lui   $t9, %hi(D_800483A0) 
  addiu $t8, $t7, -0x258
  slt   $at, $t6, $t8
  bnez  $at, .L7F0BEE54
   nop   
  lw    $t9, %lo(D_800483A0)($t9)
  bnez  $t9, .L7F0BEE54
   nop   
  jal   get_controls_locked_flag
   nop   
  bnez  $v0, .L7F0BEE54
   lui   $a0, %hi(ptr_sfx_buf)
  lui   $a2, %hi(D_800483A0)
  addiu $a2, %lo(D_800483A0) # addiu $a2, $a2, -0x7c60
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   li    $a1, 161
.L7F0BEE54:
  jal   get_controls_locked_flag
   nop   
  beqz  $v0, .L7F0BEE88
   lui   $a0, %hi(D_800483A0)
  lw    $a0, %lo(D_800483A0)($a0)
  beqz  $a0, .L7F0BEE88
   nop   
  jal   sfxGetArg0Unk3F
   nop   
  beqz  $v0, .L7F0BEE88
   lui   $a0, %hi(D_800483A0)
  jal   sfxDeactivate
   lw    $a0, %lo(D_800483A0)($a0)
.L7F0BEE88:
  lui   $v1, %hi(mp_time)
  lw    $v1, %lo(mp_time)($v1)
  lw    $t7, 0x184($sp)
  lw    $t6, 0x180($sp)
  slt   $at, $t7, $v1
  beqz  $at, .L7F0BEEB4
   slt   $at, $t6, $v1
  bnez  $at, .L7F0BEEB4
   nop   
  jal   sub_GAME_7F0C2530
   move  $a0, $zero
.L7F0BEEB4:
  lui   $t8, %hi(mp_point) 
  lw    $t8, %lo(mp_point)($t8)
  lui   $t9, %hi(clock_timer) 
  blez  $t8, .L7F0BEFB8
   nop   
  lw    $t9, %lo(clock_timer)($t9)
  beqz  $t9, .L7F0BEFB8
   nop   
  jal   getPlayerCount
   nop   
  move  $a3, $v0
  move  $a1, $zero
  move  $a2, $zero
  blez  $v0, .L7F0BEF90
   move  $a0, $zero
  lui   $v1, %hi(ptr_BONDdata_p1)
  mtc1  $zero, $f0
  addiu $v1, %lo(ptr_BONDdata_p1) # addiu $v1, $v1, -0x6120
.L7F0BEEFC:
  lw    $v0, ($v1)
  lw    $t7, 0xd8($v0)
  beql  $t7, $zero, .L7F0BEF40
   sw    $v1, 0x1c($sp)
  lw    $t6, 0x424($v0)
  beql  $t6, $zero, .L7F0BEF3C
   addiu $a1, $a1, 1
  lw    $t8, 0x428($v0)
  beql  $t8, $zero, .L7F0BEF3C
   addiu $a1, $a1, 1
  lwc1  $f8, 0x3e4($v0)
  c.le.s $f0, $f8
  nop   
  bc1fl .L7F0BEF40
   sw    $v1, 0x1c($sp)
  addiu $a1, $a1, 1
.L7F0BEF3C:
  sw    $v1, 0x1c($sp)
.L7F0BEF40:
  sw    $a0, 0x174($sp)
  sw    $a1, 0x170($sp)
  sw    $a2, 0x16c($sp)
  jal   get_points_for_mp_player
   sw    $a3, 0x178($sp)
  lui   $t9, %hi(mp_point) 
  lw    $t9, %lo(mp_point)($t9)
  mtc1  $zero, $f0
  lw    $v1, 0x1c($sp)
  slt   $at, $v0, $t9
  lw    $a0, 0x174($sp)
  lw    $a1, 0x170($sp)
  lw    $a2, 0x16c($sp)
  bnez  $at, .L7F0BEF80
   lw    $a3, 0x178($sp)
  addiu $a2, $a2, 1
.L7F0BEF80:
  addiu $a0, $a0, 1
  slt   $at, $a0, $a3
  bnez  $at, .L7F0BEEFC
   addiu $v1, $v1, 4
.L7F0BEF90:
  blez  $a2, .L7F0BEFB8
   nop   
  bnez  $a1, .L7F0BEFB0
   nop   
  jal   sub_GAME_7F0C2530
   move  $a0, $zero
  b     .L7F0BEFB8
   nop   
.L7F0BEFB0:
  jal   set_stopplay_flag
   nop   
.L7F0BEFB8:
  jal   get_scenario
   nop   
  li    $at, 1
  bne   $v0, $at, .L7F0BF1E0
   lui   $t7, %hi(clock_timer) 
  lw    $t7, %lo(clock_timer)($t7)
  beqz  $t7, .L7F0BF1E0
   nop   
  jal   getPlayerCount
   nop   
  mtc1  $zero, $f0
  move  $t2, $v0
  move  $t5, $zero
  move  $ra, $zero
  blez  $v0, .L7F0BF1AC
   move  $t4, $zero
  move  $a1, $zero
.L7F0BEFFC:
  move  $a2, $zero
  blez  $v0, .L7F0BF124
   move  $a3, $zero
  andi  $t1, $v0, 3
  beqz  $t1, .L7F0BF074
   sll   $t3, $t4, 2
  lui   $t8, %hi(ptr_BONDdata_p1) 
  addiu $t8, %lo(ptr_BONDdata_p1) # addiu $t8, $t8, -0x6120
  sll   $t6, $zero, 2
  sll   $t9, $zero, 3
  subu  $t9, $t9, $zero
  addu  $v1, $t6, $t8
  lui   $t6, %hi(player1_player_data) 
  sll   $t9, $t9, 4
  addu  $t7, $t9, $t3
  addiu $t6, %lo(player1_player_data) # addiu $t6, $t6, -0x6110
  addu  $a0, $t7, $t6
  move  $t0, $t1
.L7F0BF044:
  lw    $t8, ($v1)
  addiu $a3, $a3, 1
  addiu $v1, $v1, 4
  lw    $t9, 0xd8($t8)
  bnezl $t9, .L7F0BF064
   lw    $t7, 0x24($a0)
  addiu $a2, $a2, 1
  lw    $t7, 0x24($a0)
.L7F0BF064:
  addiu $a0, $a0, 0x70
  bne   $t0, $a3, .L7F0BF044
   addu  $a1, $a1, $t7
  beq   $a3, $v0, .L7F0BF124
.L7F0BF074:
   lui   $t8, %hi(ptr_BONDdata_p1) 
  sll   $t9, $a3, 3
  subu  $t9, $t9, $a3
  addiu $t8, %lo(ptr_BONDdata_p1) # addiu $t8, $t8, -0x6120
  sll   $t6, $a3, 2
  addu  $v1, $t6, $t8
  sll   $t9, $t9, 4
  addu  $t7, $t9, $t3
  lui   $t6, %hi(player1_player_data) 
  addiu $t6, %lo(player1_player_data) # addiu $t6, $t6, -0x6110
  sll   $t9, $t2, 2
  addu  $t0, $t9, $t8
  addu  $a0, $t7, $t6
.L7F0BF0A8:
  lw    $t7, ($v1)
  lw    $t6, 0xd8($t7)
  bnezl $t6, .L7F0BF0C0
   lw    $t8, 4($v1)
  addiu $a2, $a2, 1
  lw    $t8, 4($v1)
.L7F0BF0C0:
  lw    $t9, 0x24($a0)
  lw    $t7, 0xd8($t8)
  addu  $a1, $a1, $t9
  bnezl $t7, .L7F0BF0DC
   lw    $t9, 8($v1)
  addiu $a2, $a2, 1
  lw    $t9, 8($v1)
.L7F0BF0DC:
  lw    $t6, 0x94($a0)
  lw    $t8, 0xd8($t9)
  addu  $a1, $a1, $t6
  bnezl $t8, .L7F0BF0F8
   lw    $t6, 0xc($v1)
  addiu $a2, $a2, 1
  lw    $t6, 0xc($v1)
.L7F0BF0F8:
  lw    $t7, 0x104($a0)
  addiu $v1, $v1, 0x10
  lw    $t9, 0xd8($t6)
  addu  $a1, $a1, $t7
  bnezl $t9, .L7F0BF118
   lw    $t8, 0x174($a0)
  addiu $a2, $a2, 1
  lw    $t8, 0x174($a0)
.L7F0BF118:
  addiu $a0, $a0, 0x1c0
  bne   $v1, $t0, .L7F0BF0A8
   addu  $a1, $a1, $t8
.L7F0BF124:
  slti  $at, $a1, 2
  bnez  $at, .L7F0BF19C
   sll   $t7, $t4, 3
  subu  $t7, $t7, $t4
  lui   $t6, %hi(player1_player_data) 
  addiu $t6, %lo(player1_player_data) # addiu $t6, $t6, -0x6110
  sll   $t7, $t7, 4
  addu  $v1, $t7, $t6
  lbu   $t7, 0x68($v1)
  lui   $t8, %hi(ptr_BONDdata_p1) 
  addiu $t8, %lo(ptr_BONDdata_p1) # addiu $t8, $t8, -0x6120
  sll   $t9, $t4, 2
  bnez  $t7, .L7F0BF164
   addu  $a0, $t9, $t8
  addiu $t6, $a2, 1
  sb    $t6, 0x68($v1)
.L7F0BF164:
  lw    $v1, ($a0)
  addiu $t5, $t5, 1
  lw    $t9, 0x424($v1)
  beql  $t9, $zero, .L7F0BF1A0
   addiu $t4, $t4, 1
  lw    $t8, 0x428($v1)
  beql  $t8, $zero, .L7F0BF1A0
   addiu $t4, $t4, 1
  lwc1  $f10, 0x3e4($v1)
  c.lt.s $f10, $f0
  nop   
  bc1fl .L7F0BF1A0
   addiu $t4, $t4, 1
  addiu $ra, $ra, 1
.L7F0BF19C:
  addiu $t4, $t4, 1
.L7F0BF1A0:
  slt   $at, $t4, $t2
  bnezl $at, .L7F0BEFFC
   move  $a1, $zero
.L7F0BF1AC:
  addiu $v1, $v0, -1
  slt   $at, $ra, $v1
  bnezl $at, .L7F0BF1D0
   slt   $at, $t5, $v1
  jal   sub_GAME_7F0C2530
   move  $a0, $zero
  b     .L7F0BF1E0
   nop   
  slt   $at, $t5, $v1
.L7F0BF1D0:
  bnez  $at, .L7F0BF1E0
   nop   
  jal   set_stopplay_flag
   nop   
.L7F0BF1E0:
  lui   $v0, %hi(clock_timer)
  lui   $t7, %hi(D_80048394) 
  lw    $t7, %lo(D_80048394)($t7)
  lw    $v0, %lo(clock_timer)($v0)
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f0
  addu  $t6, $t7, $v0
  mtc1  $t6, $f16
  lui   $at, %hi(D_80048394)
  sw    $t6, %lo(D_80048394)($at)
  cvt.s.w $f18, $f16
  lui   $v1, %hi(D_800483A8)
  lui   $at, %hi(cur_mp_sec)
  addiu $v1, %lo(D_800483A8) # addiu $v1, $v1, -0x7c58
  move  $a0, $zero
  li    $a1, 65535
  div.s $f4, $f18, $f0
  swc1  $f4, %lo(cur_mp_sec)($at)
  lw    $t9, ($v1)
  lui   $at, %hi(cur_mp_min)
  addu  $t7, $t9, $v0
  mtc1  $t7, $f6
  sw    $t7, ($v1)
  cvt.s.w $f8, $f6
  div.s $f10, $f8, $f0
  jal   get_controller_buttons_pressed
   swc1  $f10, %lo(cur_mp_min)($at)
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f0
  beqz  $v0, .L7F0BF27C
   lui   $v1, %hi(D_80048390)
  lui   $v1, %hi(D_80048390)
  lui   $at, %hi(D_80048388)
  addiu $v1, %lo(D_80048390) # addiu $v1, $v1, -0x7c70
  sw    $zero, %lo(D_80048388)($at)
  sw    $zero, ($v1)
  lui   $v0, %hi(clock_timer)
  b     .L7F0BF2A8
   lw    $v0, %lo(clock_timer)($v0)
.L7F0BF27C:
  addiu $v1, $v1, %lo(D_80048390)
  lui   $v0, %hi(clock_timer)
  lw    $v0, %lo(clock_timer)($v0)
  lw    $t6, ($v1)
  li    $t7, 1
  addu  $t9, $t6, $v0
  slti  $at, $t9, 0x708
  bnez  $at, .L7F0BF2A8
   sw    $t9, ($v1)
  lui   $at, %hi(D_80048388)
  sw    $t7, %lo(D_80048388)($at)
.L7F0BF2A8:
  lui   $t6, %hi(D_80048388) 
  lw    $t6, %lo(D_80048388)($t6)
  lui   $v1, %hi(D_8004838C)
  addiu $v1, %lo(D_8004838C) # addiu $v1, $v1, -0x7c74
  beqz  $t6, .L7F0BF2D0
   nop   
  lw    $t9, ($v1)
  addu  $t8, $t9, $v0
  b     .L7F0BF320
   sw    $t8, ($v1)
.L7F0BF2D0:
  lui   $v1, %hi(D_800483B0)
  addiu $v1, %lo(D_800483B0) # addiu $v1, $v1, -0x7c50
  lw    $t7, ($v1)
  lui   $a0, %hi(D_800483B8)
  lui   $at, %hi(stage_time_sec)
  addu  $t9, $t7, $v0
  mtc1  $t9, $f16
  sw    $t9, ($v1)
  addiu $a0, %lo(D_800483B8) # addiu $a0, $a0, -0x7c48
  cvt.s.w $f18, $f16
  div.s $f4, $f18, $f0
  swc1  $f4, %lo(stage_time_sec)($at)
  lw    $t8, ($a0)
  lui   $at, %hi(poweron_time_sec)
  addu  $t6, $t8, $v0
  mtc1  $t6, $f6
  sw    $t6, ($a0)
  cvt.s.w $f8, $f6
  div.s $f10, $f8, $f0
  swc1  $f10, %lo(poweron_time_sec)($at)
.L7F0BF320:
  jal   set_video2_settings_offset_24
   li    $a0, 1
  lui   $t9, %hi(current_stage_to_load) 
  lw    $t9, %lo(current_stage_to_load)($t9)
  li    $at, 90
  bne   $t9, $at, .L7F0BF35C
   nop   
  jal   cheat_buttons_mp_related
   nop   
  jal   menu_init
   nop   
  jal   something_with_LnameJ
   nop   
  b     .L7F0BF5FC
   nop   
.L7F0BF35C:
  jal   sub_GAME_7F09BBBC
   nop   
  jal   sub_GAME_7F0BE8D0
   nop   
  jal   sub_GAME_7F0BC7D4
   nop   
  jal   sub_GAME_7F092E50
   nop   
  jal   sub_GAME_7F094438
   nop   
  jal   sub_GAME_7F0A47FC
   nop   
  jal   sub_GAME_7F068E6C
   nop   
  jal   sub_GAME_7F0A28D4
   nop   
  jal   sub_GAME_7F09FD3C
   nop   
  jal   handle_mp_respawn_and_some_things
   nop   
  jal   reset_all_music_slots
   nop   
  jal   something_with_LnameJ
   nop   
  jal   get_debug_joy2detailedit_flag
   nop   
  beqz  $v0, .L7F0BF4FC
   lui   $a2, %hi(D_800483C8)
  addiu $a2, %lo(D_800483C8) # addiu $a2, $a2, -0x7c38
  lw    $t8, ($a2)
  li    $a0, 12288
  bnez  $t8, .L7F0BF4FC
   nop   
  jal   mempAllocBytesInBank
   li    $a1, 4
  lui   $a2, %hi(D_800483C8)
  addiu $a2, %lo(D_800483C8) # addiu $a2, $a2, -0x7c38
  beqz  $v0, .L7F0BF4FC
   sw    $v0, ($a2)
  move  $v1, $zero
  li    $a1, 12000
  li    $a0, 255
.L7F0BF404:
  lw    $t6, ($a2)
  addu  $t9, $t6, $v1
  sb    $a0, ($t9)
  lw    $t8, ($a2)
  addu  $v0, $t8, $v1
  lbu   $t7, 1($v0)
  andi  $t6, $t7, 0xff1f
  ori   $t9, $t6, 0x20
  sb    $t9, 1($v0)
  lw    $t8, ($a2)
  addu  $v0, $t8, $v1
  lbu   $t7, 1($v0)
  andi  $t6, $t7, 0xffe3
  ori   $t9, $t6, 4
  sb    $t9, 1($v0)
  lw    $t8, ($a2)
  addu  $t7, $t8, $v1
  sb    $a0, 4($t7)
  lw    $t6, ($a2)
  addu  $v0, $t6, $v1
  lbu   $t9, 5($v0)
  andi  $t8, $t9, 0xff1f
  ori   $t7, $t8, 0x20
  sb    $t7, 5($v0)
  lw    $t6, ($a2)
  addu  $v0, $t6, $v1
  lbu   $t9, 5($v0)
  andi  $t8, $t9, 0xffe3
  ori   $t7, $t8, 4
  sb    $t7, 5($v0)
  lw    $t6, ($a2)
  addu  $t9, $t6, $v1
  sb    $a0, 8($t9)
  lw    $t8, ($a2)
  addu  $v0, $t8, $v1
  lbu   $t7, 9($v0)
  andi  $t6, $t7, 0xff1f
  ori   $t9, $t6, 0x20
  sb    $t9, 9($v0)
  lw    $t8, ($a2)
  addu  $v0, $t8, $v1
  lbu   $t7, 9($v0)
  andi  $t6, $t7, 0xffe3
  ori   $t9, $t6, 4
  sb    $t9, 9($v0)
  lw    $t8, ($a2)
  addu  $t7, $t8, $v1
  sb    $a0, 0xc($t7)
  lw    $t6, ($a2)
  addu  $v0, $t6, $v1
  lbu   $t9, 0xd($v0)
  andi  $t8, $t9, 0xff1f
  ori   $t7, $t8, 0x20
  sb    $t7, 0xd($v0)
  lw    $t6, ($a2)
  addu  $v0, $t6, $v1
  lbu   $t9, 0xd($v0)
  addiu $v1, $v1, 0x10
  andi  $t8, $t9, 0xffe3
  ori   $t7, $t8, 4
  bne   $v1, $a1, .L7F0BF404
   sb    $t7, 0xd($v0)
.L7F0BF4FC:
  jal   get_debug_portal_flag
   nop   
  beqz  $v0, .L7F0BF514
   nop   
  jal   sub_GAME_7F0BDF10
   move  $a0, $zero
.L7F0BF514:
  jal   get_debug_limit_controller_input
   nop   
  li    $at, 4
  beq   $v0, $at, .L7F0BF53C
   move  $a0, $zero
  li    $at, 8
  beq   $v0, $at, .L7F0BF598
   move  $a0, $zero
  b     .L7F0BF5FC
   nop   
.L7F0BF53C:
  jal   get_controller_buttons_pressed
   li    $a1, 2
  beql  $v0, $zero, .L7F0BF568
   move  $a0, $zero
  jal   sub_GAME_7F0AF630
   li    $a0, -1
  move  $a0, $zero
  move  $a1, $zero
  jal   sub_GAME_7F0B2D38
   move  $a2, $zero
  move  $a0, $zero
.L7F0BF568:
  jal   get_controller_buttons_pressed
   li    $a1, 1
  beqz  $v0, .L7F0BF5FC
   nop   
  jal   sub_GAME_7F0AF630
   li    $a0, 1
  move  $a0, $zero
  move  $a1, $zero
  jal   sub_GAME_7F0B2D38
   move  $a2, $zero
  b     .L7F0BF5FC
   nop   
.L7F0BF598:
  jal   get_controller_buttons_pressed
   li    $a1, 2
  beql  $v0, $zero, .L7F0BF5B4
   move  $a0, $zero
  jal   sub_GAME_7F022E30
   nop   
  move  $a0, $zero
.L7F0BF5B4:
  jal   get_controller_buttons_pressed
   li    $a1, 1
  beql  $v0, $zero, .L7F0BF5D0
   move  $a0, $zero
  jal   sub_GAME_7F022E90
   nop   
  move  $a0, $zero
.L7F0BF5D0:
  jal   get_controller_buttons_pressed
   li    $a1, 32
  beql  $v0, $zero, .L7F0BF5EC
   move  $a0, $zero
  jal   sub_GAME_7F022EC8
   nop   
  move  $a0, $zero
.L7F0BF5EC:
  jal   get_controller_buttons_held
   li    $a1, 16
  jal   sub_GAME_7F022EE0
   sltu  $a0, $zero, $v0
.L7F0BF5FC:
  jal   get_debug_limit_controller_input
   nop   
  li    $at, 12
  beq   $v0, $at, .L7F0BF6C4
   move  $a0, $zero
  li    $at, 13
  beq   $v0, $at, .L7F0BF738
   move  $a0, $zero
  li    $at, 56
  bnel  $v0, $at, .L7F0BF7F4
   lw    $ra, 0x14($sp)
  jal   get_D_8002329C
   nop   
  jal   get_D_800232A0
   sw    $v0, 0x30($sp)
  sw    $v0, 0x2c($sp)
  move  $a0, $zero
  jal   get_controller_buttons_held
   li    $a1, 4
  beqz  $v0, .L7F0BF65C
   move  $a0, $zero
  lw    $t6, 0x2c($sp)
  addiu $t9, $t6, 1
  sw    $t9, 0x2c($sp)
.L7F0BF65C:
  jal   get_controller_buttons_held
   li    $a1, 8
  beqz  $v0, .L7F0BF678
   move  $a0, $zero
  lw    $t8, 0x2c($sp)
  addiu $t7, $t8, -1
  sw    $t7, 0x2c($sp)
.L7F0BF678:
  jal   get_controller_buttons_held
   li    $a1, 1
  beqz  $v0, .L7F0BF694
   move  $a0, $zero
  lw    $t6, 0x30($sp)
  addiu $t9, $t6, 1
  sw    $t9, 0x30($sp)
.L7F0BF694:
  jal   get_controller_buttons_held
   li    $a1, 2
  beqz  $v0, .L7F0BF6AC
   lw    $t8, 0x30($sp)
  addiu $t7, $t8, -1
  sw    $t7, 0x30($sp)
.L7F0BF6AC:
  jal   set_D_8002329C
   lw    $a0, 0x30($sp)
  jal   set_D_800232A0
   lw    $a0, 0x2c($sp)
  b     .L7F0BF7F4
   lw    $ra, 0x14($sp)
.L7F0BF6C4:
  jal   get_controller_buttons_pressed
   li    $a1, 514
  beql  $v0, $zero, .L7F0BF6E0
   move  $a0, $zero
  jal   music_append_play_endtheme
   nop   
  move  $a0, $zero
.L7F0BF6E0:
  jal   get_controller_buttons_pressed
   li    $a1, 257
  beql  $v0, $zero, .L7F0BF6FC
   move  $a0, $zero
  jal   music_append_play_solo_death_short
   nop   
  move  $a0, $zero
.L7F0BF6FC:
  jal   get_controller_buttons_pressed
   li    $a1, 1024
  beql  $v0, $zero, .L7F0BF718
   move  $a0, $zero
  jal   musicTrack1Stop
   nop   
  move  $a0, $zero
.L7F0BF718:
  jal   get_controller_buttons_pressed
   li    $a1, 16384
  beql  $v0, $zero, .L7F0BF7F4
   lw    $ra, 0x14($sp)
  jal   musicTrack1Tempo
   nop   
  b     .L7F0BF7F4
   lw    $ra, 0x14($sp)
.L7F0BF738:
  jal   get_controller_buttons_pressed
   li    $a1, 1570
  beqz  $v0, .L7F0BF770
   lui   $a1, 0x8005
  lh    $a1, %lo(D_800483E4)($a1)
  lui   $a0, %hi(ptr_sfx_buf)
  lui   $at, %hi(D_800483E4)
  addiu $a1, $a1, -1
  sll   $t6, $a1, 0x10
  sra   $a1, $t6, 0x10
  sh    $a1, %lo(D_800483E4)($at)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   move  $a2, $zero
.L7F0BF770:
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 2321
  beqz  $v0, .L7F0BF7AC
   lui   $a1, 0x8005
  lh    $a1, %lo(D_800483E4)($a1)
  lui   $a0, %hi(ptr_sfx_buf)
  lui   $at, %hi(D_800483E4)
   addiu $a1, $a1, 1
  sll   $t8, $a1, 0x10
  sra   $a1, $t8, 0x10
  sh    $a1, %lo(D_800483E4)($at)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   move  $a2, $zero
.L7F0BF7AC:
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 4
  beql  $v0, $zero, .L7F0BF7CC
   move  $a0, $zero
  jal   sfx_c_70009124
   nop   
  move  $a0, $zero
.L7F0BF7CC:
  jal   get_controller_buttons_pressed
   li    $a1, 8
  beqz  $v0, .L7F0BF7F0
   lui   $a1, %hi(D_800483E4)
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  lh    $a1, %lo(D_800483E4)($a1)
  jal   play_sfx_a1
   move  $a2, $zero
.L7F0BF7F0:
  lw    $ra, 0x14($sp)
.L7F0BF7F4:
  addiu $sp, $sp, 0x198
  jr    $ra
   nop   
");
#endif

#ifdef VERSION_JP
asm(R"
glabel manage_mp_game
  addiu $sp, $sp, -0x198
  sw    $ra, 0x14($sp)
  jal   mp_tlb_related
   nop   
  lui   $t6, %hi(controls_locked_flag) # $t6, 0x8005
  lw    $t6, %lo(controls_locked_flag)($t6)
  lui   $at, %hi(clock_timer) # $at, 0x8005
  beqz  $t6, .Ljp7F0BF7D8
   nop   
  b     .Ljp7F0BF814
   sw    $zero, %lo(clock_timer)($at)
.Ljp7F0BF7D8:
  jal   checkGamePaused
   nop   
  beqz  $v0, .Ljp7F0BF7F4
   lui   $t7, %hi(D_80048498) # $t7, 0x8005
  lui   $at, %hi(clock_timer) # $at, 0x8005
  b     .Ljp7F0BF814
   sw    $zero, %lo(clock_timer)($at)
.Ljp7F0BF7F4:
  lw    $t7, %lo(D_80048498)($t7)
  lui   $v0, %hi(D_80048380) # $v0, 0x8005
  lui   $at, %hi(clock_timer) # $at, 0x8005
  addiu $v0, %lo(D_80048380) # addiu $v0, $v0, -0x7c50
  sw    $t7, %lo(clock_timer)($at)
  lw    $t8, ($v0)
  addiu $t9, $t8, 1
  sw    $t9, ($v0)
.Ljp7F0BF814:
  lui   $v0, %hi(clock_timer) # $v0, 0x8005
  lw    $v0, %lo(clock_timer)($v0)
  lui   $v1, %hi(jp_global_timer_delta) # $v1, 0x8005
  addiu $v1, %lo(jp_global_timer_delta) # addiu $v1, $v1, -0x7c58
  mtc1  $v0, $f4
  lui   $a0, %hi(global_timer) # $a0, 0x8005
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  cvt.s.w $f6, $f4
  addiu $a0, %lo(global_timer) # addiu $a0, $a0, -0x7c54
  lui   $t8, %hi(current_stage_to_load) # $t8, 0x8005
  lui   $t9, %hi(D_80048394) # $t9, 0x8005
  swc1  $f6, ($v1)
  lwc1  $f8, ($v1)
  swc1  $f8, %lo(global_timer_delta)($at)
  lw    $t6, ($a0)
  li    $at, 90
  addu  $t7, $t6, $v0
  sw    $t7, ($a0)
  lw    $t8, %lo(current_stage_to_load)($t8)
  beq   $t8, $at, .Ljp7F0BF8D8
   nop   
  lw    $t9, %lo(D_80048394)($t9)
  bnez  $t9, .Ljp7F0BF8D8
   nop   
  blez  $v0, .Ljp7F0BF8D8
   lui   $t6, %hi(append_cheat_sp) # $t6, 0x8003
  lw    $t6, %lo(append_cheat_sp)($t6)
  lui   $v1, %hi(CHEAT_AVAILABLE_EXTRA_CHARS) # $v1, 0x8007
  addiu $v1, %lo(CHEAT_AVAILABLE_EXTRA_CHARS) # addiu $v1, $v1, -0x691f
  beqz  $t6, .Ljp7F0BF8D8
   li    $a0, 1
.Ljp7F0BF890:
  lbu   $t7, ($v1)
  beql  $t7, $zero, .Ljp7F0BF8CC
   addiu $a0, $a0, 1
  sw    $v1, 0x1c($sp)
  jal   is_cheat_index_equal_to_1C
   sw    $a0, 0x194($sp)
  lw    $v1, 0x1c($sp)
  bnez  $v0, .Ljp7F0BF8C8
   lw    $a0, 0x194($sp)
  sw    $v1, 0x1c($sp)
  jal   turn_on_cheat_for_players
   sw    $a0, 0x194($sp)
  lw    $v1, 0x1c($sp)
  lw    $a0, 0x194($sp)
.Ljp7F0BF8C8:
  addiu $a0, $a0, 1
.Ljp7F0BF8CC:
  li    $at, 75
  bne   $a0, $at, .Ljp7F0BF890
   addiu $v1, $v1, 1
.Ljp7F0BF8D8:
  jal   getPlayerCount
   nop   
  slti  $at, $v0, 2
  bnez  $at, .Ljp7F0BFE18
   lui   $t8, %hi(current_stage_to_load) # $t8, 0x8005
  lw    $t8, %lo(current_stage_to_load)($t8)
  li    $at, 90
  beq   $t8, $at, .Ljp7F0BFE18
   nop   
  jal   get_mission_state
   nop   
  li    $at, 6
  bne   $v0, $at, .Ljp7F0BF9B0
   nop   
  sw    $zero, 0x190($sp)
  sw    $zero, 0x18c($sp)
  jal   getPlayerCount
   sw    $zero, 0x188($sp)
  lw    $v1, 0x190($sp)
  lw    $a1, 0x18c($sp)
  blez  $v0, .Ljp7F0BF998
   lw    $a2, 0x188($sp)
  lui   $t6, %hi(ptr_BONDdata_p1) # $t6, 0x8008
  addiu $t6, %lo(ptr_BONDdata_p1) # addiu $t6, $t6, -0x60b0
  sll   $t9, $v1, 2
  addu  $a0, $t9, $t6
.Ljp7F0BF940:
  lw    $v0, ($a0)
  addiu $v1, $v1, 1
  addiu $a0, $a0, 4
  lw    $t7, 0xd8($v0)
  beql  $t7, $zero, .Ljp7F0BF970
   sw    $v1, 0x190($sp)
  lw    $t8, 0x424($v0)
  addiu $a1, $a1, 1
  beql  $t8, $zero, .Ljp7F0BF970
   sw    $v1, 0x190($sp)
  addiu $a2, $a2, 1
  sw    $v1, 0x190($sp)
.Ljp7F0BF970:
  sw    $a0, 0x1c($sp)
  sw    $a1, 0x18c($sp)
  jal   getPlayerCount
   sw    $a2, 0x188($sp)
  lw    $v1, 0x190($sp)
  lw    $a0, 0x1c($sp)
  lw    $a1, 0x18c($sp)
  slt   $at, $v1, $v0
  bnez  $at, .Ljp7F0BF940
   lw    $a2, 0x188($sp)
.Ljp7F0BF998:
  blez  $a1, .Ljp7F0BF9B0
   nop   
  bne   $a1, $a2, .Ljp7F0BF9B0
   nop   
  jal   set_missionstate
   li    $a0, 1
.Ljp7F0BF9B0:
  lui   $v1, %hi(mp_time) # $v1, 0x8005
  lw    $v1, %lo(mp_time)($v1)
  lui   $v0, %hi(D_80048394) # $v0, 0x8005
  lui   $t9, %hi(clock_timer) # $t9, 0x8005
  blez  $v1, .Ljp7F0BFAEC
   nop   
  lw    $v0, %lo(D_80048394)($v0)
  lw    $t9, %lo(clock_timer)($t9)
  addiu $a0, $v1, -0xe10
  slt   $at, $v0, $a0
  addu  $t6, $t9, $v0
  sw    $t6, 0x180($sp)
  beqz  $at, .Ljp7F0BFA3C
   sw    $v0, 0x184($sp)
  slt   $at, $t6, $a0
  bnez  $at, .Ljp7F0BFA3C
   nop   
  jal   getPlayerCount
   sw    $zero, 0x17c($sp)
  blez  $v0, .Ljp7F0BFA3C
   nop   
.Ljp7F0BFA04:
  jal   set_cur_player
   lw    $a0, 0x17c($sp)
  jal   get_textptr_for_textID
   li    $a0, 45124
  jal   jp_display_string_in_lower_left_corner
   move  $a0, $v0
  lw    $t7, 0x17c($sp)
  addiu $t8, $t7, 1
  jal   getPlayerCount
   sw    $t8, 0x17c($sp)
  lw    $t9, 0x17c($sp)
  slt   $at, $t9, $v0
  bnez  $at, .Ljp7F0BFA04
   nop   
.Ljp7F0BFA3C:
  lui   $t7, %hi(mp_time) # $t7, 0x8005
  lw    $t7, %lo(mp_time)($t7)
  lw    $t6, 0x180($sp)
  lui   $t9, %hi(D_800483A0) # $t9, 0x8005
  addiu $t8, $t7, -0x258
  slt   $at, $t6, $t8
  bnez  $at, .Ljp7F0BFA8C
   nop   
  lw    $t9, %lo(D_800483A0)($t9)
  bnez  $t9, .Ljp7F0BFA8C
   nop   
  jal   get_controls_locked_flag
   nop   
  bnez  $v0, .Ljp7F0BFA8C
   lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  lui   $a2, %hi(D_800483A0) # $a2, 0x8005
  addiu $a2, %lo(D_800483A0) # addiu $a2, $a2, -0x7c2c
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   li    $a1, 161
.Ljp7F0BFA8C:
  jal   get_controls_locked_flag
   nop   
  beqz  $v0, .Ljp7F0BFAC0
   lui   $a0, %hi(D_800483A0) # $a0, 0x8005
  lw    $a0, %lo(D_800483A0)($a0)
  beqz  $a0, .Ljp7F0BFAC0
   nop   
  jal   sfxGetArg0Unk3F
   nop   
  beqz  $v0, .Ljp7F0BFAC0
   lui   $a0, %hi(D_800483A0) # $a0, 0x8005
  jal   sfxDeactivate
   lw    $a0, %lo(D_800483A0)($a0)
.Ljp7F0BFAC0:
  lui   $v1, %hi(mp_time) # $v1, 0x8005
  lw    $v1, %lo(mp_time)($v1)
  lw    $t7, 0x184($sp)
  lw    $t6, 0x180($sp)
  slt   $at, $t7, $v1
  beqz  $at, .Ljp7F0BFAEC
   slt   $at, $t6, $v1
  bnez  $at, .Ljp7F0BFAEC
   nop   
  jal   sub_GAME_7F0C2530
   move  $a0, $zero
.Ljp7F0BFAEC:
  lui   $t8, %hi(mp_point) # $t8, 0x8005
  lw    $t8, %lo(mp_point)($t8)
  lui   $t9, %hi(clock_timer) # $t9, 0x8005
  blez  $t8, .Ljp7F0BFBF0
   nop   
  lw    $t9, %lo(clock_timer)($t9)
  beqz  $t9, .Ljp7F0BFBF0
   nop   
  jal   getPlayerCount
   nop   
  move  $a3, $v0
  move  $a1, $zero
  move  $a2, $zero
  blez  $v0, .Ljp7F0BFBC8
   move  $a0, $zero
  lui   $v1, %hi(ptr_BONDdata_p1) # $v1, 0x8008
  mtc1  $zero, $f0
  addiu $v1, %lo(ptr_BONDdata_p1) # addiu $v1, $v1, -0x60b0
.Ljp7F0BFB34:
  lw    $v0, ($v1)
  lw    $t7, 0xd8($v0)
  beql  $t7, $zero, .Ljp7F0BFB78
   sw    $v1, 0x1c($sp)
  lw    $t6, 0x424($v0)
  beql  $t6, $zero, .Ljp7F0BFB74
   addiu $a1, $a1, 1
  lw    $t8, 0x428($v0)
  beql  $t8, $zero, .Ljp7F0BFB74
   addiu $a1, $a1, 1
  lwc1  $f10, 0x3e4($v0)
  c.le.s $f0, $f10
  nop   
  bc1fl .Ljp7F0BFB78
   sw    $v1, 0x1c($sp)
  addiu $a1, $a1, 1
.Ljp7F0BFB74:
  sw    $v1, 0x1c($sp)
.Ljp7F0BFB78:
  sw    $a0, 0x174($sp)
  sw    $a1, 0x170($sp)
  sw    $a2, 0x16c($sp)
  jal   get_points_for_mp_player
   sw    $a3, 0x178($sp)
  lui   $t9, %hi(mp_point) # $t9, 0x8005
  lw    $t9, %lo(mp_point)($t9)
  mtc1  $zero, $f0
  lw    $v1, 0x1c($sp)
  slt   $at, $v0, $t9
  lw    $a0, 0x174($sp)
  lw    $a1, 0x170($sp)
  lw    $a2, 0x16c($sp)
  bnez  $at, .Ljp7F0BFBB8
   lw    $a3, 0x178($sp)
  addiu $a2, $a2, 1
.Ljp7F0BFBB8:
  addiu $a0, $a0, 1
  slt   $at, $a0, $a3
  bnez  $at, .Ljp7F0BFB34
   addiu $v1, $v1, 4
.Ljp7F0BFBC8:
  blez  $a2, .Ljp7F0BFBF0
   nop   
  bnez  $a1, .Ljp7F0BFBE8
   nop   
  jal   sub_GAME_7F0C2530
   move  $a0, $zero
  b     .Ljp7F0BFBF0
   nop   
.Ljp7F0BFBE8:
  jal   set_stopplay_flag
   nop   
.Ljp7F0BFBF0:
  jal   get_scenario
   nop   
  li    $at, 1
  bne   $v0, $at, .Ljp7F0BFE18
   lui   $t7, %hi(clock_timer) # $t7, 0x8005
  lw    $t7, %lo(clock_timer)($t7)
  beqz  $t7, .Ljp7F0BFE18
   nop   
  jal   getPlayerCount
   nop   
  mtc1  $zero, $f0
  move  $t2, $v0
  move  $t5, $zero
  move  $ra, $zero
  blez  $v0, .Ljp7F0BFDE4
   move  $t4, $zero
  move  $a1, $zero
.Ljp7F0BFC34:
  move  $a2, $zero
  blez  $v0, .Ljp7F0BFD5C
   move  $a3, $zero
  andi  $t1, $v0, 3
  beqz  $t1, .Ljp7F0BFCAC
   sll   $t3, $t4, 2
  lui   $t8, %hi(ptr_BONDdata_p1) # $t8, 0x8008
  addiu $t8, %lo(ptr_BONDdata_p1) # addiu $t8, $t8, -0x60b0
  sll   $t6, $zero, 2
  sll   $t9, $zero, 3
  subu  $t9, $t9, $zero
  addu  $v1, $t6, $t8
  lui   $t6, %hi(player1_player_data) # $t6, 0x8008
  sll   $t9, $t9, 4
  addu  $t7, $t9, $t3
  addiu $t6, %lo(player1_player_data) # addiu $t6, $t6, -0x60a0
  addu  $a0, $t7, $t6
  move  $t0, $t1
.Ljp7F0BFC7C:
  lw    $t8, ($v1)
  addiu $a3, $a3, 1
  addiu $v1, $v1, 4
  lw    $t9, 0xd8($t8)
  bnezl $t9, .Ljp7F0BFC9C
   lw    $t7, 0x24($a0)
  addiu $a2, $a2, 1
  lw    $t7, 0x24($a0)
.Ljp7F0BFC9C:
  addiu $a0, $a0, 0x70
  bne   $t0, $a3, .Ljp7F0BFC7C
   addu  $a1, $a1, $t7
  beq   $a3, $v0, .Ljp7F0BFD5C
.Ljp7F0BFCAC:
   lui   $t8, %hi(ptr_BONDdata_p1) # $t8, 0x8008
  sll   $t9, $a3, 3
  subu  $t9, $t9, $a3
  addiu $t8, %lo(ptr_BONDdata_p1) # addiu $t8, $t8, -0x60b0
  sll   $t6, $a3, 2
  addu  $v1, $t6, $t8
  sll   $t9, $t9, 4
  addu  $t7, $t9, $t3
  lui   $t6, %hi(player1_player_data) # $t6, 0x8008
  addiu $t6, %lo(player1_player_data) # addiu $t6, $t6, -0x60a0
  sll   $t9, $t2, 2
  addu  $t0, $t9, $t8
  addu  $a0, $t7, $t6
.Ljp7F0BFCE0:
  lw    $t7, ($v1)
  lw    $t6, 0xd8($t7)
  bnezl $t6, .Ljp7F0BFCF8
   lw    $t8, 4($v1)
  addiu $a2, $a2, 1
  lw    $t8, 4($v1)
.Ljp7F0BFCF8:
  lw    $t9, 0x24($a0)
  lw    $t7, 0xd8($t8)
  addu  $a1, $a1, $t9
  bnezl $t7, .Ljp7F0BFD14
   lw    $t9, 8($v1)
  addiu $a2, $a2, 1
  lw    $t9, 8($v1)
.Ljp7F0BFD14:
  lw    $t6, 0x94($a0)
  lw    $t8, 0xd8($t9)
  addu  $a1, $a1, $t6
  bnezl $t8, .Ljp7F0BFD30
   lw    $t6, 0xc($v1)
  addiu $a2, $a2, 1
  lw    $t6, 0xc($v1)
.Ljp7F0BFD30:
  lw    $t7, 0x104($a0)
  addiu $v1, $v1, 0x10
  lw    $t9, 0xd8($t6)
  addu  $a1, $a1, $t7
  bnezl $t9, .Ljp7F0BFD50
   lw    $t8, 0x174($a0)
  addiu $a2, $a2, 1
  lw    $t8, 0x174($a0)
.Ljp7F0BFD50:
  addiu $a0, $a0, 0x1c0
  bne   $v1, $t0, .Ljp7F0BFCE0
   addu  $a1, $a1, $t8
.Ljp7F0BFD5C:
  slti  $at, $a1, 2
  bnez  $at, .Ljp7F0BFDD4
   sll   $t7, $t4, 3
  subu  $t7, $t7, $t4
  lui   $t6, %hi(player1_player_data) # $t6, 0x8008
  addiu $t6, %lo(player1_player_data) # addiu $t6, $t6, -0x60a0
  sll   $t7, $t7, 4
  addu  $v1, $t7, $t6
  lbu   $t7, 0x68($v1)
  lui   $t8, %hi(ptr_BONDdata_p1) # $t8, 0x8008
  addiu $t8, %lo(ptr_BONDdata_p1) # addiu $t8, $t8, -0x60b0
  sll   $t9, $t4, 2
  bnez  $t7, .Ljp7F0BFD9C
   addu  $a0, $t9, $t8
  addiu $t6, $a2, 1
  sb    $t6, 0x68($v1)
.Ljp7F0BFD9C:
  lw    $v1, ($a0)
  addiu $t5, $t5, 1
  lw    $t9, 0x424($v1)
  beql  $t9, $zero, .Ljp7F0BFDD8
   addiu $t4, $t4, 1
  lw    $t8, 0x428($v1)
  beql  $t8, $zero, .Ljp7F0BFDD8
   addiu $t4, $t4, 1
  lwc1  $f16, 0x3e4($v1)
  c.lt.s $f16, $f0
  nop   
  bc1fl .Ljp7F0BFDD8
   addiu $t4, $t4, 1
  addiu $ra, $ra, 1
.Ljp7F0BFDD4:
  addiu $t4, $t4, 1
.Ljp7F0BFDD8:
  slt   $at, $t4, $t2
  bnezl $at, .Ljp7F0BFC34
   move  $a1, $zero
.Ljp7F0BFDE4:
  addiu $v1, $v0, -1
  slt   $at, $ra, $v1
  bnezl $at, .Ljp7F0BFE08
   slt   $at, $t5, $v1
  jal   sub_GAME_7F0C2530
   move  $a0, $zero
  b     .Ljp7F0BFE18
   nop   
  slt   $at, $t5, $v1
.Ljp7F0BFE08:
  bnez  $at, .Ljp7F0BFE18
   nop   
  jal   set_stopplay_flag
   nop   
.Ljp7F0BFE18:
  lui   $v0, %hi(clock_timer) # $v0, 0x8005
  lui   $t7, %hi(D_80048394) # $t7, 0x8005
  lw    $t7, %lo(D_80048394)($t7)
  lw    $v0, %lo(clock_timer)($v0)
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f0
  addu  $t6, $t7, $v0
  mtc1  $t6, $f18
  lui   $at, %hi(D_80048394) # $at, 0x8005
  sw    $t6, %lo(D_80048394)($at)
  cvt.s.w $f4, $f18
  lui   $v1, %hi(D_800483A8) # $v1, 0x8005
  lui   $at, %hi(cur_mp_sec) # $at, 0x8005
  addiu $v1, %lo(D_800483A8) # addiu $v1, $v1, -0x7c24
  move  $a0, $zero
  li    $a1, 65535
  div.s $f6, $f4, $f0
  swc1  $f6, %lo(cur_mp_sec)($at)
  lw    $t9, ($v1)
  lui   $at, %hi(cur_mp_min) # $at, 0x8005
  addu  $t7, $t9, $v0
  mtc1  $t7, $f8
  sw    $t7, ($v1)
  cvt.s.w $f10, $f8
  div.s $f16, $f10, $f0
  jal   get_controller_buttons_pressed
   swc1  $f16, %lo(cur_mp_min)($at)
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f0
  beqz  $v0, .Ljp7F0BFEB4
   lui   $v1, %hi(D_80048390)
  lui   $v1, %hi(D_80048390) # $v1, 0x8005
  lui   $at, %hi(D_80048388) # $at, 0x8005
  addiu $v1, %lo(D_80048390) # addiu $v1, $v1, -0x7c3c
  sw    $zero, %lo(D_80048388)($at)
  sw    $zero, ($v1)
  lui   $v0, %hi(clock_timer) # $v0, 0x8005
  b     .Ljp7F0BFEE0
   lw    $v0, %lo(clock_timer)($v0)
.Ljp7F0BFEB4:
  addiu $v1, $v1, %lo(D_80048390)
  lui   $v0, %hi(clock_timer) # $v0, 0x8005
  lw    $v0, %lo(clock_timer)($v0)
  lw    $t6, ($v1)
  li    $t7, 1
  addu  $t9, $t6, $v0
  slti  $at, $t9, 0x708
  bnez  $at, .Ljp7F0BFEE0
   sw    $t9, ($v1)
  lui   $at, %hi(D_80048388) # $at, 0x8005
  sw    $t7, %lo(D_80048388)($at)
.Ljp7F0BFEE0:
  lui   $t6, %hi(D_80048388) # $t6, 0x8005
  lw    $t6, %lo(D_80048388)($t6)
  lui   $v1, %hi(D_8004838C) # $v1, 0x8005
  addiu $v1, %lo(D_8004838C) # addiu $v1, $v1, -0x7c40
  beqz  $t6, .Ljp7F0BFF08
   nop   
  lw    $t9, ($v1)
  addu  $t8, $t9, $v0
  b     .Ljp7F0BFF58
   sw    $t8, ($v1)
.Ljp7F0BFF08:
  lui   $v1, %hi(D_800483B0) # $v1, 0x8005
  addiu $v1, %lo(D_800483B0) # addiu $v1, $v1, -0x7c1c
  lw    $t7, ($v1)
  lui   $a0, %hi(D_800483B8) # $a0, 0x8005
  lui   $at, %hi(stage_time_sec) # $at, 0x8005
  addu  $t9, $t7, $v0
  mtc1  $t9, $f18
  sw    $t9, ($v1)
  addiu $a0, %lo(D_800483B8) # addiu $a0, $a0, -0x7c14
  cvt.s.w $f4, $f18
  div.s $f6, $f4, $f0
  swc1  $f6, %lo(stage_time_sec)($at)
  lw    $t8, ($a0)
  lui   $at, %hi(poweron_time_sec) # $at, 0x8005
  addu  $t6, $t8, $v0
  mtc1  $t6, $f8
  sw    $t6, ($a0)
  cvt.s.w $f10, $f8
  div.s $f16, $f10, $f0
  swc1  $f16, %lo(poweron_time_sec)($at)
.Ljp7F0BFF58:
  jal   set_video2_settings_offset_24
   li    $a0, 1
  lui   $t9, %hi(current_stage_to_load) # $t9, 0x8005
  lw    $t9, %lo(current_stage_to_load)($t9)
  li    $at, 90
  bne   $t9, $at, .Ljp7F0BFF94
   nop   
  jal   cheat_buttons_mp_related
   nop   
  jal   menu_init
   nop   
  jal   something_with_LnameJ
   nop   
  b     .Ljp7F0C0234
   nop   
.Ljp7F0BFF94:
  jal   sub_GAME_7F09BBBC
   nop   
  jal   sub_GAME_7F0BE8D0
   nop   
  jal   sub_GAME_7F0BC7D4
   nop   
  jal   sub_GAME_7F092E50
   nop   
  jal   sub_GAME_7F094438
   nop   
  jal   sub_GAME_7F0A47FC
   nop   
  jal   sub_GAME_7F068E6C
   nop   
  jal   sub_GAME_7F0A28D4
   nop   
  jal   sub_GAME_7F09FD3C
   nop   
  jal   handle_mp_respawn_and_some_things
   nop   
  jal   reset_all_music_slots
   nop   
  jal   something_with_LnameJ
   nop   
  jal   get_debug_joy2detailedit_flag
   nop   
  beqz  $v0, .Ljp7F0C0134
   lui   $a2, %hi(D_800483C8) # $a2, 0x8005
  addiu $a2, %lo(D_800483C8) # addiu $a2, $a2, -0x7c04
  lw    $t8, ($a2)
  li    $a0, 12288
  bnez  $t8, .Ljp7F0C0134
   nop   
  jal   mempAllocBytesInBank
   li    $a1, 4
  lui   $a2, %hi(D_800483C8) # $a2, 0x8005
  addiu $a2, %lo(D_800483C8) # addiu $a2, $a2, -0x7c04
  beqz  $v0, .Ljp7F0C0134
   sw    $v0, ($a2)
  move  $v1, $zero
  li    $a1, 12000
  li    $a0, 255
.Ljp7F0C003C:
  lw    $t6, ($a2)
  addu  $t9, $t6, $v1
  sb    $a0, ($t9)
  lw    $t8, ($a2)
  addu  $v0, $t8, $v1
  lbu   $t7, 1($v0)
  andi  $t6, $t7, 0xff1f
  ori   $t9, $t6, 0x20
  sb    $t9, 1($v0)
  lw    $t8, ($a2)
  addu  $v0, $t8, $v1
  lbu   $t7, 1($v0)
  andi  $t6, $t7, 0xffe3
  ori   $t9, $t6, 4
  sb    $t9, 1($v0)
  lw    $t8, ($a2)
  addu  $t7, $t8, $v1
  sb    $a0, 4($t7)
  lw    $t6, ($a2)
  addu  $v0, $t6, $v1
  lbu   $t9, 5($v0)
  andi  $t8, $t9, 0xff1f
  ori   $t7, $t8, 0x20
  sb    $t7, 5($v0)
  lw    $t6, ($a2)
  addu  $v0, $t6, $v1
  lbu   $t9, 5($v0)
  andi  $t8, $t9, 0xffe3
  ori   $t7, $t8, 4
  sb    $t7, 5($v0)
  lw    $t6, ($a2)
  addu  $t9, $t6, $v1
  sb    $a0, 8($t9)
  lw    $t8, ($a2)
  addu  $v0, $t8, $v1
  lbu   $t7, 9($v0)
  andi  $t6, $t7, 0xff1f
  ori   $t9, $t6, 0x20
  sb    $t9, 9($v0)
  lw    $t8, ($a2)
  addu  $v0, $t8, $v1
  lbu   $t7, 9($v0)
  andi  $t6, $t7, 0xffe3
  ori   $t9, $t6, 4
  sb    $t9, 9($v0)
  lw    $t8, ($a2)
  addu  $t7, $t8, $v1
  sb    $a0, 0xc($t7)
  lw    $t6, ($a2)
  addu  $v0, $t6, $v1
  lbu   $t9, 0xd($v0)
  andi  $t8, $t9, 0xff1f
  ori   $t7, $t8, 0x20
  sb    $t7, 0xd($v0)
  lw    $t6, ($a2)
  addu  $v0, $t6, $v1
  lbu   $t9, 0xd($v0)
  addiu $v1, $v1, 0x10
  andi  $t8, $t9, 0xffe3
  ori   $t7, $t8, 4
  bne   $v1, $a1, .Ljp7F0C003C
   sb    $t7, 0xd($v0)
.Ljp7F0C0134:
  jal   get_debug_portal_flag
   nop   
  beqz  $v0, .Ljp7F0C014C
   nop   
  jal   sub_GAME_7F0BDF10
   move  $a0, $zero
.Ljp7F0C014C:
  jal   get_debug_limit_controller_input
   nop   
  li    $at, 4
  beq   $v0, $at, .Ljp7F0C0174
   move  $a0, $zero
  li    $at, 8
  beq   $v0, $at, .Ljp7F0C01D0
   move  $a0, $zero
  b     .Ljp7F0C0234
   nop   
.Ljp7F0C0174:
  jal   get_controller_buttons_pressed
   li    $a1, 2
  beql  $v0, $zero, .Ljp7F0C01A0
   move  $a0, $zero
  jal   sub_GAME_7F0AF630
   li    $a0, -1
  move  $a0, $zero
  move  $a1, $zero
  jal   sub_GAME_7F0B2D38
   move  $a2, $zero
  move  $a0, $zero
.Ljp7F0C01A0:
  jal   get_controller_buttons_pressed
   li    $a1, 1
  beqz  $v0, .Ljp7F0C0234
   nop   
  jal   sub_GAME_7F0AF630
   li    $a0, 1
  move  $a0, $zero
  move  $a1, $zero
  jal   sub_GAME_7F0B2D38
   move  $a2, $zero
  b     .Ljp7F0C0234
   nop   
.Ljp7F0C01D0:
  jal   get_controller_buttons_pressed
   li    $a1, 2
  beql  $v0, $zero, .Ljp7F0C01EC
   move  $a0, $zero
  jal   sub_GAME_7F022E30
   nop   
  move  $a0, $zero
.Ljp7F0C01EC:
  jal   get_controller_buttons_pressed
   li    $a1, 1
  beql  $v0, $zero, .Ljp7F0C0208
   move  $a0, $zero
  jal   sub_GAME_7F022E90
   nop   
  move  $a0, $zero
.Ljp7F0C0208:
  jal   get_controller_buttons_pressed
   li    $a1, 32
  beql  $v0, $zero, .Ljp7F0C0224
   move  $a0, $zero
  jal   sub_GAME_7F022EC8
   nop   
  move  $a0, $zero
.Ljp7F0C0224:
  jal   get_controller_buttons_held
   li    $a1, 16
  jal   sub_GAME_7F022EE0
   sltu  $a0, $zero, $v0
.Ljp7F0C0234:
  jal   get_debug_limit_controller_input
   nop   
  li    $at, 12
  beq   $v0, $at, .Ljp7F0C02FC
   move  $a0, $zero
  li    $at, 13
  beq   $v0, $at, .Ljp7F0C0370
   move  $a0, $zero
  li    $at, 56
  bnel  $v0, $at, .Ljp7F0C042C
   lw    $ra, 0x14($sp)
  jal   get_D_8002329C
   nop   
  jal   get_D_800232A0
   sw    $v0, 0x30($sp)
  sw    $v0, 0x2c($sp)
  move  $a0, $zero
  jal   get_controller_buttons_held
   li    $a1, 4
  beqz  $v0, .Ljp7F0C0294
   move  $a0, $zero
  lw    $t6, 0x2c($sp)
  addiu $t9, $t6, 1
  sw    $t9, 0x2c($sp)
.Ljp7F0C0294:
  jal   get_controller_buttons_held
   li    $a1, 8
  beqz  $v0, .Ljp7F0C02B0
   move  $a0, $zero
  lw    $t8, 0x2c($sp)
  addiu $t7, $t8, -1
  sw    $t7, 0x2c($sp)
.Ljp7F0C02B0:
  jal   get_controller_buttons_held
   li    $a1, 1
  beqz  $v0, .Ljp7F0C02CC
   move  $a0, $zero
  lw    $t6, 0x30($sp)
  addiu $t9, $t6, 1
  sw    $t9, 0x30($sp)
.Ljp7F0C02CC:
  jal   get_controller_buttons_held
   li    $a1, 2
  beqz  $v0, .Ljp7F0C02E4
   lw    $t8, 0x30($sp)
  addiu $t7, $t8, -1
  sw    $t7, 0x30($sp)
.Ljp7F0C02E4:
  jal   set_D_8002329C
   lw    $a0, 0x30($sp)
  jal   set_D_800232A0
   lw    $a0, 0x2c($sp)
  b     .Ljp7F0C042C
   lw    $ra, 0x14($sp)
.Ljp7F0C02FC:
  jal   get_controller_buttons_pressed
   li    $a1, 514
  beql  $v0, $zero, .Ljp7F0C0318
   move  $a0, $zero
  jal   music_append_play_endtheme
   nop   
  move  $a0, $zero
.Ljp7F0C0318:
  jal   get_controller_buttons_pressed
   li    $a1, 257
  beql  $v0, $zero, .Ljp7F0C0334
   move  $a0, $zero
  jal   music_append_play_solo_death_short
   nop   
  move  $a0, $zero
.Ljp7F0C0334:
  jal   get_controller_buttons_pressed
   li    $a1, 1024
  beql  $v0, $zero, .Ljp7F0C0350
   move  $a0, $zero
  jal   musicTrack1Stop
   nop   
  move  $a0, $zero
.Ljp7F0C0350:
  jal   get_controller_buttons_pressed
   li    $a1, 16384
  beql  $v0, $zero, .Ljp7F0C042C
   lw    $ra, 0x14($sp)
  jal   musicTrack1Tempo
   nop   
  b     .Ljp7F0C042C
   lw    $ra, 0x14($sp)
.Ljp7F0C0370:
  jal   get_controller_buttons_pressed
   li    $a1, 1570
  beqz  $v0, .Ljp7F0C03A8
   lui   $a1, 0x8005
  lh    $a1, %lo(D_800483E4)($a1)
  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  lui   $at, %hi(D_800483E4) # $at, 0x8005
  addiu $a1, $a1, -1
  sll   $t6, $a1, 0x10
  sra   $a1, $t6, 0x10
  sh    $a1, %lo(D_800483E4)($at)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   move  $a2, $zero
.Ljp7F0C03A8:
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 2321
  beqz  $v0, .Ljp7F0C03E4
   lui   $a1, 0x8005
  lh    $a1, %lo(D_800483E4)($a1)
  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  lui   $at, %hi(D_800483E4) # $at, 0x8005
  addiu $a1, $a1, 1
  sll   $t8, $a1, 0x10
  sra   $a1, $t8, 0x10
  sh    $a1, %lo(D_800483E4)($at)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   move  $a2, $zero
.Ljp7F0C03E4:
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 4
  beql  $v0, $zero, .Ljp7F0C0404
   move  $a0, $zero
  jal   sfx_c_70009124
   nop   
  move  $a0, $zero
.Ljp7F0C0404:
  jal   get_controller_buttons_pressed
   li    $a1, 8
  beqz  $v0, .Ljp7F0C0428
   lui   $a1, %hi(D_800483E4) # $a1, 0x8005
  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  lh    $a1, %lo(D_800483E4)($a1)
  jal   play_sfx_a1
   move  $a2, $zero
.Ljp7F0C0428:
  lw    $ra, 0x14($sp)
.Ljp7F0C042C:
  addiu $sp, $sp, 0x198
  jr    $ra
   nop   
");
#endif

asm(R"
glabel sub_GAME_7F0BF800
  addiu $sp, $sp, -0x30
  sw    $ra, 0x14($sp)
  jal   get_cur_playernum
   nop   
  jal   cheat_buttons_mp_related
   sb    $v0, 0x2f($sp)
  jal   get_debug_freeze_processing
   nop   
  beqz  $v0, .L7F0BF840
   li    $at, 1
  beq   $v0, $at, .L7F0BF8E0
   li    $at, 2
  beq   $v0, $at, .L7F0BF964
   nop   
  b     .L7F0BF9E8
   nop   
.L7F0BF840:
  jal   get_debug_limit_controller_input
   nop   
  beqz  $v0, .L7F0BF870
   nop   
  jal   get_debug_limit_controller_input
   nop   
  li    $at, 59
  bne   $v0, $at, .L7F0BF8AC
   lui   $t6, %hi(D_80036ABC) 
  lw    $t6, %lo(D_80036ABC)($t6)
  bgez  $t6, .L7F0BF8AC
   nop   
.L7F0BF870:
  jal   get_cur_controller_horz_stick_pos
   lb    $a0, 0x2f($sp)
  sb    $v0, 0x18($sp)
  jal   get_cur_controller_vert_stick_pos
   lb    $a0, 0x2f($sp)
  sb    $v0, 0x19($sp)
  lb    $a0, 0x2f($sp)
  jal   get_controller_buttons_held
   li    $a1, 65535
  lb    $a0, 0x18($sp)
  lb    $a1, 0x19($sp)
  jal   sub_GAME_7F091080
   andi  $a2, $v0, 0xffff
  b     .L7F0BF9E8
   nop   
.L7F0BF8AC:
  jal   get_cur_controller_horz_stick_pos
   lb    $a0, 0x2f($sp)
  sb    $v0, 0x18($sp)
  jal   get_cur_controller_vert_stick_pos
   lb    $a0, 0x2f($sp)
  sll   $a1, $v0, 0x18
  sra   $t7, $a1, 0x18
  move  $a1, $t7
  lb    $a0, 0x18($sp)
  jal   sub_GAME_7F091080
   move  $a2, $zero
  b     .L7F0BF9E8
   nop   
.L7F0BF8E0:
  jal   get_debug_limit_controller_input
   nop   
  li    $at, 1
  bne   $v0, $at, .L7F0BF930
   nop   
  jal   get_cur_controller_horz_stick_pos
   lb    $a0, 0x2f($sp)
  sb    $v0, 0x18($sp)
  jal   get_cur_controller_vert_stick_pos
   lb    $a0, 0x2f($sp)
  sb    $v0, 0x19($sp)
  lb    $a0, 0x2f($sp)
  jal   get_controller_buttons_held
   li    $a1, 65535
  lb    $a0, 0x18($sp)
  lb    $a1, 0x19($sp)
  jal   sub_GAME_7F0B2D38
   andi  $a2, $v0, 0xffff
  b     .L7F0BF9E8
   nop   
.L7F0BF930:
  jal   get_cur_controller_horz_stick_pos
   lb    $a0, 0x2f($sp)
  sb    $v0, 0x18($sp)
  jal   get_cur_controller_vert_stick_pos
   lb    $a0, 0x2f($sp)
  sll   $a1, $v0, 0x18
  sra   $t8, $a1, 0x18
  move  $a1, $t8
  lb    $a0, 0x18($sp)
  jal   sub_GAME_7F0B2D38
   move  $a2, $zero
  b     .L7F0BF9E8
   nop   
.L7F0BF964:
  jal   get_debug_limit_controller_input
   nop   
  li    $at, 2
  bne   $v0, $at, .L7F0BF9B4
   nop   
  jal   get_cur_controller_horz_stick_pos
   lb    $a0, 0x2f($sp)
  sb    $v0, 0x18($sp)
  jal   get_cur_controller_vert_stick_pos
   lb    $a0, 0x2f($sp)
  sb    $v0, 0x19($sp)
  lb    $a0, 0x2f($sp)
  jal   get_controller_buttons_held
   li    $a1, 65535
  lb    $a0, 0x18($sp)
  lb    $a1, 0x19($sp)
  jal   possibly_reset_viewport_options_for_player
   andi  $a2, $v0, 0xffff
  b     .L7F0BF9E0
   nop   
.L7F0BF9B4:
  jal   get_cur_controller_horz_stick_pos
   lb    $a0, 0x2f($sp)
  sb    $v0, 0x18($sp)
  jal   get_cur_controller_vert_stick_pos
   lb    $a0, 0x2f($sp)
  sll   $a1, $v0, 0x18
  sra   $t9, $a1, 0x18
  move  $a1, $t9
  lb    $a0, 0x18($sp)
  jal   possibly_reset_viewport_options_for_player
   move  $a2, $zero
.L7F0BF9E0:
  jal   sub_GAME_7F0C2E80
   nop   
.L7F0BF9E8:
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lw    $v1, 0xa8($v0)
  lwc1  $f6, 0x408($v0)
  lwc1  $f10, 0x410($v0)
  lwc1  $f4, 8($v1)
  lwc1  $f8, 0x10($v1)
  sub.s $f0, $f4, $f6
  sub.s $f2, $f8, $f10
  mul.s $f16, $f0, $f0
  nop   
  mul.s $f18, $f2, $f2
  jal   sqrtf
   add.s $f12, $f16, $f18
  lui   $v0, %hi(pPlayersPerm)
  lw    $v0, %lo(pPlayersPerm)($v0)
  lwc1  $f4, 0x38($v0)
  add.s $f6, $f4, $f0
  jal   get_scenario
   swc1  $f6, 0x38($v0)
  li    $at, 2
  bne   $v0, $at, .L7F0BFAD0
   nop   
  jal   bondinvIsAliveWithFlag
   nop   
  beqz  $v0, .L7F0BFAC0
   nop   
  jal   get_item_in_hand
   move  $a0, $zero
  li    $at, 88
  beq   $v0, $at, .L7F0BFA90
   move  $a0, $zero
  jal   draw_item_in_hand_has_more_ammo
   li    $a1, 88
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  li    $at, 2
  li    $t1, 5
  lw    $t0, 0x894($v0)
  bne   $t0, $at, .L7F0BFA90
   nop   
  sw    $t1, 0x894($v0)
.L7F0BFA90:
  lui   $v1, %hi(pPlayersPerm)
  addiu $v1, %lo(pPlayersPerm) # addiu $v1, $v1, -0x5f4c
  lw    $v0, ($v1)
  lui   $t3, %hi(clock_timer) 
  lw    $t3, %lo(clock_timer)($t3)
  lw    $t2, 0x60($v0)
  li    $t5, 1
  addu  $t4, $t2, $t3
  sw    $t4, 0x60($v0)
  lw    $t6, ($v1)
  b     .L7F0BFB10
   sb    $t5, 0x69($t6)
.L7F0BFAC0:
  lui   $t7, %hi(pPlayersPerm) 
  lw    $t7, %lo(pPlayersPerm)($t7)
  b     .L7F0BFB10
   sb    $zero, 0x69($t7)
.L7F0BFAD0:
  jal   get_scenario
   nop   
  li    $at, 3
  bnel  $v0, $at, .L7F0BFB14
   lw    $ra, 0x14($sp)
  jal   checkforgoldengun
   nop   
  beqz  $v0, .L7F0BFB08
   lui   $t0, %hi(pPlayersPerm) 
  lui   $t9, %hi(pPlayersPerm) 
  lw    $t9, %lo(pPlayersPerm)($t9)
  li    $t8, 1
  b     .L7F0BFB10
   sb    $t8, 0x69($t9)
.L7F0BFB08:
  lw    $t0, %lo(pPlayersPerm)($t0)
  sb    $zero, 0x69($t0)
.L7F0BFB10:
  lw    $ra, 0x14($sp)
.L7F0BFB14:
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

void unload_stage_text_data(void) {
  if (D_800483A0 != 0) {
    if (sfxGetArg0Unk3F(D_800483A0) != 0) {
      sfxDeactivate(D_800483A0);
    }
  }
  if (current_stage_to_load != 0x5a) {
    blank_text_bank(get_textbank_number_for_stagenum(current_stage_to_load));
    sub_GAME_7F007770();
  }
  cheatDisableAllCheats();
  cleanupGuardData();
  cleanupObjectSounds();
  cleanupExplosions();
  sub_GAME_7F007920();
  cleanup_REMOVED_();
  cleanupAlarms();
  cleanupObjects(current_stage_to_load);
  cleanupObjectives();
  cleanupSFXRelated();
  cleanupplayersoundrelated();
  sub_GAME_7F0C1268();
  sub_GAME_7F0B47E0();
}

void set_controls_locked_flag(int arg0) {
#ifdef VERSION_JP
  if ((arg0 != 0) && (controls_locked_flag == 0)) {
    reset_cont_rumble_detect();
  }
#endif
  controls_locked_flag = arg0;
}

int get_controls_locked_flag(void) { return controls_locked_flag; }

DIFFICULTY get_current_difficulty(void) { return difficulty_0; }

void set_difficulty(int arg0) { difficulty_0 = arg0; }

void set_mp_time(int arg0) { mp_time = arg0; }

void set_mp_point(int arg0) { mp_point = arg0; }

float get_cur_mp_sec(void) { return cur_mp_sec; }

float get_cur_mp_min(void) { return cur_mp_min; }

float get_stage_time_sec(void) { return stage_time_sec; }

float get_poweron_time_sec(void) { return poweron_time_sec; }
