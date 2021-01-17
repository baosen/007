// This file contains the main game loop code.
#include "bondconstants.h"
#include "room_model_buffer.h"
#include <libultra.h>
#include <stddef.h>
#include <time.h>
#include <types.h>

void *boss_c_ptr_debug_notice_list_entry = NULL;
int debug_and_update_stage_flag = false;
LEVELID current_stage_num = LEVELID_TITLE;
size_t current_m_malloc_value = 0x234800, current_ma_malloc_value = 0x4B000;
int show_mem_use_flag = false, show_mem_bars_flag = false;
struct memallocstring {
  int id;
  void *string;
} memallocstringtable[] = {
    {LEVELID_DAM, "-ml0 -me0 -mgfx70  -mvtx50 -mt625 -ma275"},
    {LEVELID_FACILITY, "-ml0 -me0 -mgfx70  -mvtx50 -mt650 -ma160"},
    {LEVELID_RUNWAY, "-ml0 -me0 -mgfx100 -mvtx50 -mt610 -ma300"},
    {LEVELID_SURFACE, "-ml0 -me0 -mgfx70  -mvtx50 -mt600 -ma300"},
    {LEVELID_BUNKER1, "-ml0 -me0 -mgfx100 -mvtx50 -mt700 -ma150"},
    {LEVELID_SILO, "-ml0 -me0 -mgfx70  -mvtx50 -mt660 -ma150"},
    {LEVELID_FRIGATE, "-ml0 -me0 -mgfx70  -mvtx50 -mt750 -ma225"},
    {LEVELID_SURFACE2, "-ml0 -me0 -mgfx100 -mvtx50 -mt550 -ma350"},
    {LEVELID_BUNKER2, "-ml0 -me0 -mgfx100 -mvtx50 -mt725 -ma150"},
    {LEVELID_STATUE, "-ml0 -me0 -mgfx70  -mvtx50 -mt750 -ma220"},
    {LEVELID_ARCHIVES, "-ml0 -me0 -mgfx70  -mvtx50 -mt600 -ma250"},
    {LEVELID_STREETS, "-ml0 -me0 -mgfx60  -mvtx40 -mt635 -ma290"},
    {LEVELID_DEPOT, "-ml0 -me0 -mgfx60  -mvtx50 -mt710 -ma300"},
    {LEVELID_TRAIN, "-ml0 -me0 -mgfx100 -mvtx50 -mt600 -ma200"},
    {LEVELID_JUNGLE, "-ml0 -me0 -mgfx70  -mvtx50 -mt500 -ma200"},
    {LEVELID_CONTROL, "-ml0 -me0 -mgfx70  -mvtx50 -mt671 -ma200"},
    {LEVELID_CRADLE, "-ml0 -me0 -mgfx100 -mvtx50 -mt650 -ma250"},
    {LEVELID_CAVERNS, "-ml0 -me0 -mgfx100 -mvtx50 -mt530 -ma250"},
    {LEVELID_AZTEC, "-ml0 -me0 -mgfx60  -mvtx40 -mt855 -ma135"},
    {LEVELID_EGYPT, "-ml0 -me0 -mgfx100 -mvtx50 -mt600 -ma250"},
    {LEVELID_CITADEL, "-ml0 -me0 -mgfx100 -mvtx50 -mt650 -ma150"},
    {LEVELID_CUBA, "-ml0 -me0 -mgfx100 -mvtx50 -mt300 -ma300"},
    {LEVELID_TITLE, "-ml0 -me0 -mgfx80 -mvtx20 -mt646 -ma001"},
    {0x5B, "-ml0 -me0 -mgfx60 -mvtx20 -mt500 -ma001"},
    {0x63, "-ml0 -me0 -mgfx60 -mvtx20 -mt500 -ma001"},
    {LEVELID_TEMPLE, "-ml0 -me0 -mgfx130 -mvtx100 -mt390 -ma100"},
    {LEVELID_COMPLEX, "-ml0 -me0 -mgfx130 -mvtx100 -mt400 -ma100"},
    {LEVELID_LIBRARY, "-ml0 -me0 -mgfx130 -mvtx100 -mt400 -ma100"},
    {LEVELID_BASEMENT, "-ml0 -me0 -mgfx130 -mvtx100 -mt400 -ma100"},
    {LEVELID_STACK, "-ml0 -me0 -mgfx130 -mvtx100 -mt400 -ma100"},
    {LEVELID_CAVES, "-ml0 -me0 -mgfx130 -mvtx100 -mt400 -ma300"},
    {0x1AB, "-ml0 -me0 -mgfx130 -mvtx100 -mt550 -ma170"},
    {0x1A8, "-ml0 -me0 -mgfx80  -mvtx100 -mt550 -ma250"},
    {0x1B7, "-ml0 -me0 -mgfx130 -mvtx100 -mt440 -ma220"},
    {0x1B2, "-ml0 -me0 -mgfx90  -mvtx100 -mt550 -ma230"},
    {0x1B0, "-ml0 -me0 -mgfx110 -mvtx100 -mt350 -ma400"},
    {0, "-ml0 -me0 -mgfx100 -mvtx50 -mt700 -ma400"},
    {0},
    {0},
    {0}};
LEVELID loadedstage = LEVELID_NONE;
int debug_feature_flag = false;
int D_80024304 = 0x20000;
int D_80024308 = 0;
int D_8002430C = 0;
int D_80024310 = 0;
int D_80024314 = 0;
int D_80024318 = 0;
int D_8002431C = 0;
int D_80024320 = 0;
int taskgrab_ramdump_num = 1;

void initialize_mainthread(void) {
  void something_with_boss_c_debug(void);

  OSMesg bossmsg;
  OSTimer bosstimer;
  OSMesgQueue bossmq;

  unsigned int bufaddr, unused;
  int i;

  add_debug_notice_deb_c_debug();
  romCreateMesgQueue();
  establish_TLB_buffer_management_table();
  image_entries_load();
  something_with_memp_c_debug();
  something_with_mema_c_debug();
  something_with_bg_c_debug();
  init_vi_c_debug();
  init_video_settings();
  init_indy_if_not_ready();
  debug_and_update_stage_flag = rmon_debug_is_final_build();
  ob_c_debug_setup();
  something_with_rsp_c_debug();
  something_with_dyn_c_debug();
  something_with_joy_c_debug();
  osCreateMesgQueue(&bossmq, &bossmsg, 1);

  for (i = 0; i != 4; i++) {
#define OS_USEC_TO_CYCLES(n)                                                   \
  (((unsigned long long)(n) * (osClockRate)) / 1000000LL)
    osSetTimer(&bosstimer, OS_USEC_TO_CYCLES(100000), 0, &bossmq, &bossmsg);
    osRecvMesg(&bossmq, &bossmsg, 1);
    if (i == 1)
      test_controller_presence();
    else if (i >= 2)
      redirect_to_ramrom_replay_and_record_handlers_if_set();
  }

  if (check_token(1, "-level_") == 0)
    debug_and_update_stage_flag = 1;
  something_stan_c_debug_related();
  something_game_c_debug_related();
  if (debug_and_update_stage_flag != 0)
    strtok("          -ml0 -me0 -mgfx100 -mvtx50 -mt700 -ma400");
  if (check_token(1, "-m") != 0)
    current_m_malloc_value = strtol(check_token(1, "-m"), 0, 0) << 10;
  bufaddr = osVirtualToPhysical(&room_model_buffer) | 0x80000000;
  checkMemflagTokens(bufaddr, return_ptr_TLBallocatedblock() - bufaddr);
  mempResetBank(6);
  init_LnameX();
  something_with_lvl_c_debug();

  something_with_boss_c_debug();

  null_init_main_7f0acb70();
  null_init_main_0();

  default_player_perspective_and_height();
  initialize_count();

  null_init_main_1();

  displaylist_related();
  set_gu_scale();

  null_init_main_2();

  sub_GAME_7F000980();
  alloc_load_expand_ani_table();
  init_weapon_animation_groups_maybe();
  reset_counter_rand_body_head();

  null_init_main_3();

  sub_GAME_7F000B60();
  initGameData();
  sub_GAME_7F01D6E0();
  clear_ramrom_block_buffer_heading_ptrs();
}

// 1 ->"show mem use" debug memory display.
void enable_show_mem_use_flag(void) { show_mem_use_flag = true; }

// toggle "show mem bars".
void mem_bars_flag_toggle(void) { show_mem_bars_flag = show_mem_bars_flag ^ 1; }

// Loads primary resources and starts the main program infinite loop.
void start_game(void) {
  initialize_mainthread();
  initialize_rsp_buffers();
  setupaudio();
  for (;;)
    mainloop();
}

const char aLevel__0[] = "-level_";
const char aLevel__1[] = "-level_";
const char aHard[] = "-hard";
const char aHard_1[] = "-hard";
const char aHard_2[] = "-hard";
const char aMa[] = "-ma";
const char aMa_0[] = "-ma";
const char taskgrab[] = "u64.taskgrab.%d.core";
asm(R"
glabel mainloop
  addiu $sp, $sp, -0x1e0
  sw    $ra, 0x3c($sp)
  sw    $fp, 0x38($sp)
  sw    $s7, 0x34($sp)
  sw    $s6, 0x30($sp)
  sw    $s5, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  jal   reset_mem_bank_5
   sw    $zero, 0x1dc($sp)
  lui   $a1, %hi(aLevel__0)
  addiu $a1, %lo(aLevel__0) # addiu $a1, $a1, -0x6efc
  jal   check_token
   li    $a0, 1
  beqz  $v0, .L700060DC
   li    $a0, 1
  lui   $a1, %hi(aLevel__1)
  jal   check_token
   addiu $a1, %lo(aLevel__1) # addiu $a1, $a1, -0x6ef4
  lbu   $t7, ($v0)
  lbu   $t6, 1($v0)
  lui   $at, %hi(current_stage_num)
  sll   $t8, $t7, 2
  addu  $t8, $t8, $t7
  sll   $t8, $t8, 1
  addu  $t9, $t6, $t8
  addiu $t0, $t9, -0x210
  sw    $t0, %lo(current_stage_num)($at)
.L700060DC:
  lui   $t1, %hi(current_stage_num) 
  lw    $t1, %lo(current_stage_num)($t1)
  li    $at, 90
  beq   $t1, $at, .L70006160
   nop   
  jal   sub_GAME_7F01DF90
   nop   
  jal   set_selected_folder_num
   move  $a0, $zero
  jal   set_selected_difficulty
   move  $a0, $zero
  lui   $a0, %hi(current_stage_num)
  jal   set_solo_and_ptr_briefing
   lw    $a0, %lo(current_stage_num)($a0)
  lui   $a1, %hi(aHard)
  addiu $a1, %lo(aHard) # addiu $a1, $a1, -0x6eec
  jal   check_token
   li    $a0, 1
  beqz  $v0, .L70006160
   li    $a0, 1
  lui   $a1, %hi(aHard_1)
  jal   check_token
   addiu $a1, %lo(aHard_1) # addiu $a1, $a1, -0x6ee4
  lbu   $a0, ($v0)
  jal   set_selected_difficulty
   addiu $a0, $a0, -0x30
  lui   $a1, %hi(aHard_2)
  addiu $a1, %lo(aHard_2) # addiu $a1, $a1, -0x6edc
  jal   check_token
   li    $a0, 1
  lbu   $a0, ($v0)
  jal   set_difficulty
   addiu $a0, $a0, -0x30
.L70006160:
  jal   osGetCount
   nop   
  jal   increment_random_num
   move  $a0, $v0
  lui   $s6, %hi(taskgrab)
  lui   $s5, %hi(pPlayer)
  addiu $s5, %lo(pPlayer) # addiu $s5, $s5, -0x5f50
  addiu $s6, %lo(taskgrab) # addiu $s6, $s6, -0x6ecc
  addiu $s7, $sp, 0x58
  addiu $s4, $sp, 0x5c
  lw    $s3, 0x1a8($sp)
.L7000618C:
  lui   $t3, %hi(D_80024304) 
  sw    $zero, 0x1d4($sp)
  addiu $t3, %lo(D_80024304) # addiu $t3, $t3, 0x4304
  lw    $at, ($t3)
  lw    $t7, 4($t3)
  addiu $t2, $sp, 0x1b4
  sw    $at, ($t2)
  sw    $t7, 4($t2)
  lw    $t7, 0xc($t3)
  lw    $at, 8($t3)
  move  $fp, $zero
  sw    $t7, 0xc($t2)
  sw    $at, 8($t2)
  lw    $at, 0x10($t3)
  lw    $t7, 0x14($t3)
  move  $s1, $zero
  sw    $at, 0x10($t2)
  sw    $t7, 0x14($t2)
  lw    $t7, 0x1c($t3)
  lw    $at, 0x18($t3)
  sw    $t7, 0x1c($t2)
  sw    $at, 0x18($t2)
  jal   get_current_difficulty
   sw    $zero, 0x1ac($sp)
  lui   $a0, %hi(current_stage_num)
  lw    $a0, %lo(current_stage_num)($a0)
  jal   test_if_recording_demos_this_stage_load
   move  $a1, $v0
  lui   $t6, %hi(debug_and_update_stage_flag) 
  lw    $t6, %lo(debug_and_update_stage_flag)($t6)
  lui   $t8, %hi(current_stage_num) 
  beqz  $t6, .L700062EC
   nop   
  lw    $t8, %lo(current_stage_num)($t8)
  li    $at, 90
  li    $s0, -1
  beq   $t8, $at, .L70006294
   nop   
  jal   get_selected_num_players
   nop   
  slti  $at, $v0, 2
  bnez  $at, .L70006294
   lui   $a1, %hi(memallocstringtable)
  addiu $a1, %lo(memallocstringtable) # addiu $a1, $a1, 0x41bc
  lw    $t9, ($a1)
  move  $s0, $zero
  lui   $a0, %hi(current_stage_num)
  beqz  $t9, .L7000627C
   lui   $t0, %hi(memallocstringtable)
  lw    $a0, %lo(current_stage_num)($a0)
  addiu $v0, $t0, %lo(memallocstringtable)
  lw    $v1, ($v0)
  addiu $a0, $a0, 0x190
.L70006260:
  beql  $a0, $v1, .L70006280
   sll   $t1, $s0, 3
  lw    $v1, 8($v0)
  addiu $s0, $s0, 1
  addiu $v0, $v0, 8
  bnez  $v1, .L70006260
   nop   
.L7000627C:
  sll   $t1, $s0, 3
.L70006280:
  addu  $t5, $a1, $t1
  lw    $t4, ($t5)
  bnez  $t4, .L70006294
   nop   
  li    $s0, -1
.L70006294:
  lui   $a1, %hi(memallocstringtable)
  bgez  $s0, .L700062DC
   addiu $a1, %lo(memallocstringtable) # addiu $a1, $a1, 0x41bc
  lw    $t2, ($a1)
  move  $s0, $zero
  lui   $a0, %hi(current_stage_num)
  beqz  $t2, .L700062DC
   lui   $t3, %hi(memallocstringtable)
  addiu $v0, $t3, %lo(memallocstringtable)
  lw    $v1, ($v0)
  lw    $a0, %lo(current_stage_num)($a0)
.L700062C0:
  beql  $a0, $v1, .L700062E0
   sll   $t7, $s0, 3
  lw    $v1, 8($v0)
  addiu $s0, $s0, 1
  addiu $v0, $v0, 8
  bnez  $v1, .L700062C0
   nop   
.L700062DC:
  sll   $t7, $s0, 3
.L700062E0:
  addu  $t6, $a1, $t7
  jal   strtok
   lw    $a0, 4($t6)
.L700062EC:
  jal   mempResetBank
   li    $a0, 4
  jal   obBlankResourcesLoadedInBank
   li    $a0, 4
  lui   $a1, %hi(aMa)
  addiu $a1, %lo(aMa) # addiu $a1, $a1, -0x6ed4
  jal   check_token
   li    $a0, 1
  beqz  $v0, .L7000633C
   li    $a0, 1
  lui   $a1, %hi(aMa_0)
  jal   check_token
   addiu $a1, %lo(aMa_0) # addiu $a1, $a1, -0x6ed0
  move  $a0, $v0
  move  $a1, $zero
  jal   strtol
   move  $a2, $zero
  sll   $t8, $v0, 0xa
  lui   $at, %hi(current_ma_malloc_value)
  sw    $t8, %lo(current_ma_malloc_value)($at)
.L7000633C:
  lui   $a0, %hi(current_ma_malloc_value)
  lw    $a0, %lo(current_ma_malloc_value)($a0)
  jal   mempAllocBytesInBank
   li    $a1, 4
  lui   $a1, %hi(current_ma_malloc_value)
  lw    $a1, %lo(current_ma_malloc_value)($a1)
  jal   mempInitMallocTable
   move  $a0, $v0
  jal   reset_play_data_ptrs
   nop   
  lui   $t9, %hi(current_stage_num) 
  lw    $t9, %lo(current_stage_num)($t9)
  li    $at, 90
  beq   $t9, $at, .L70006398
   nop   
  jal   get_selected_num_players
   li    $s1, 1
  slti  $at, $v0, 2
  bnez  $at, .L70006398
   nop   
  jal   get_selected_num_players
   nop   
  move  $s1, $v0
.L70006398:
  jal   init_player_data_ptrs_construct_viewports
   move  $a0, $s1
  jal   set_vtx_gfx_mem_alloc
   nop   
  jal   test_controller_presence
   nop   
  lui   $a0, %hi(current_stage_num)
  jal   stage_load
   lw    $a0, %lo(current_stage_num)($a0)
  jal   init_both_video_buffers
   nop   
  jal   debug_text_related_2
   nop   
  jal   sub_GAME_7F0C0B4C
   nop   
  jal   video_related_2
   nop   
  lui   $a0, %hi(gfxFrameMsgQ)
  addiu $a0, %lo(gfxFrameMsgQ) # addiu $a0, $a0, -0x2660
  addiu $a1, $sp, 0x1d4
  jal   osRecvMesg
   move  $a2, $zero
  bnez  $v0, .L70006410
.L700063F4:
   lui   $a0, %hi(gfxFrameMsgQ)
  addiu $a0, %lo(gfxFrameMsgQ) # addiu $a0, $a0, -0x2660
  addiu $a1, $sp, 0x1d4
  jal   osRecvMesg
   move  $a2, $zero
  beqz  $v0, .L700063F4
   nop   
.L70006410:
  lui   $t0, %hi(loadedstage) 
  lw    $t0, %lo(loadedstage)($t0)
  bgez  $t0, .L700068B4
.L7000641C:
   lui   $a0, %hi(gfxFrameMsgQ)
  addiu $a0, %lo(gfxFrameMsgQ) # addiu $a0, $a0, -0x2660
  addiu $a1, $sp, 0x1d4
  jal   osRecvMesg
   li    $a2, 1
  lw    $t1, 0x1d4($sp)
  li    $at, 1
  lh    $v1, ($t1)
  beq   $v1, $at, .L70006464
   li    $at, 2
  beq   $v1, $at, .L70006890
   lui   $v0, %hi(loadedstage)
  li    $at, 5
  beq   $v1, $at, .L7000689C
   lui   $v0, %hi(loadedstage)
  lui   $v0, %hi(loadedstage)
  b     .L700068A4
   lw    $v0, %lo(loadedstage)($v0)
.L70006464:
  jal   osGetCount
   nop   
  lui   $t5, %hi(current_count) 
  lw    $t5, %lo(current_count)($t5)
  lui   $at, (0x0005EB61 >> 16) # lui $at, 5
  ori   $at, (0x0005EB61 & 0xFFFF) # ori $at, $at, 0xeb61
  subu  $v1, $v0, $t5
  sltu  $at, $v1, $at
  beqz  $at, .L70006498
   lui   $v0, %hi(loadedstage)
  lui   $v0, %hi(loadedstage)
  b     .L700068A4
   lw    $v0, %lo(loadedstage)($v0)
.L70006498:
  lw    $v0, %lo(loadedstage)($v0)
  sltiu $at, $fp, 2
  bgez  $v0, .L700068A4
   nop   
  beqz  $at, .L700068A4
   addiu $t4, $sp, 0x1b4
  jal   get_is_ramrom_flag
   sw    $t4, 0x48($sp)
  beqz  $v0, .L700064D0
   nop   
  jal   iterate_ramrom_entries_handle_camera_out
   nop   
  b     .L700064D8
   nop   
.L700064D0:
  jal   sub_GAME_7F0C0B4C
   nop   
.L700064D8:
  jal   video_DL_related_4
   nop   
  jal   video_related_2
   nop   
  jal   video_related_3
   lui   $a0, 2
  jal   redirect_to_ramrom_replay_and_record_handlers_if_set
   nop   
  jal   permit_stderr
   move  $a0, $zero
  jal   get_ptr_displaylist
   nop   
  lui   $t2, %hi(debug_feature_flag) 
  lw    $t2, %lo(debug_feature_flag)($t2)
  sw    $v0, 0x1a4($sp)
  move  $s3, $v0
  beqz  $t2, .L70006590
   nop   
  jal   get_cur_controller_horz_stick_pos
   move  $a0, $zero
  sll   $s0, $v0, 0x18
  sra   $t3, $s0, 0x18
  move  $s0, $t3
  jal   get_cur_controller_vert_stick_pos
   move  $a0, $zero
  sll   $s1, $v0, 0x18
  sra   $t7, $s1, 0x18
  move  $s1, $t7
  move  $a0, $zero
  jal   get_controller_buttons_held
   li    $a1, 65535
  andi  $s2, $v0, 0xffff
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 65535
  sll   $a0, $s0, 0x18
  sll   $a1, $s1, 0x18
  sra   $t8, $a1, 0x18
  sra   $t6, $a0, 0x18
  move  $a0, $t6
  move  $a1, $t8
  andi  $a2, $s2, 0xffff
  jal   debug_menu_processor
   andi  $a3, $v0, 0xffff
  lui   $at, %hi(debug_feature_flag)
  sw    $v0, %lo(debug_feature_flag)($at)
.L70006590:
  jal   manage_mp_game
   nop   
  jal   sub_GAME_7F09B41C
   nop   
  lui   $t9, %hi(current_stage_num) 
  lw    $t9, %lo(current_stage_num)($t9)
  li    $at, 90
  beq   $t9, $at, .L70006610
   nop   
  jal   getPlayerCount
   move  $s1, $zero
  blez  $v0, .L70006610
   nop   
.L700065C4:
  jal   sub_GAME_7F09B528
   move  $a0, $s1
  jal   set_cur_player
   move  $a0, $v0
  lw    $s0, ($s5)
  lh    $a0, 0x7f0($s0)
  jal   set_video2_width_height
   lh    $a1, 0x7f2($s0)
  lw    $s0, ($s5)
  lh    $a0, 0x7f4($s0)
  jal   set_video2_ulx_uly
   lh    $a1, 0x7f6($s0)
  jal   sub_GAME_7F0BF800
   nop   
  jal   getPlayerCount
   addiu $s1, $s1, 1
  slt   $at, $s1, $v0
  bnez  $at, .L700065C4
   nop   
.L70006610:
  jal   setup_level
   move  $a0, $s3
  jal   get_debug_VisCVG_flag
   move  $s3, $v0
  beqz  $v0, .L70006700
   li    $a3, -1
  move  $v0, $s3
  addiu $s3, $s3, 8
  lui   $t0, 0xe700
  move  $v1, $s3
  sw    $t0, ($v0)
  sw    $zero, 4($v0)
  addiu $s3, $s3, 8
  lui   $t1, (0xBA001402 >> 16) # lui $t1, 0xba00
  move  $a0, $s3
  ori   $t1, (0xBA001402 & 0xFFFF) # ori $t1, $t1, 0x1402
  addiu $s3, $s3, 8
  sw    $t1, ($v1)
  sw    $zero, 4($v1)
  move  $a1, $s3
  lui   $t5, 0xf900
  addiu $s3, $s3, 8
  sw    $t5, 0($a0)
  sw    $a3, 4($a0)
  move  $a2, $s3
  lui   $t4, 0xee00
  addiu $s3, $s3, 8
  sw    $t4, ($a1)
  sw    $a3, 4($a1)
  lui   $t2, (0xB9000201 >> 16) # lui $t2, 0xb900
  move  $v0, $s3
  ori   $t2, (0xB9000201 & 0xFFFF) # ori $t2, $t2, 0x201
  li    $t3, 4
  addiu $s3, $s3, 8
  lui   $t7, (0xB900031D >> 16) # lui $t7, 0xb900
  lui   $t6, (0x0FA54040 >> 16) # lui $t6, 0xfa5
  sw    $t3, 4($a2)
  sw    $t2, ($a2)
  ori   $t6, (0x0FA54040 & 0xFFFF) # ori $t6, $t6, 0x4040
  ori   $t7, (0xB900031D & 0xFFFF) # ori $t7, $t7, 0x31d
  move  $s0, $s3
  sw    $t7, ($v0)
  sw    $t6, 4($v0)
  jal   get_video2_settings_txtClipW
   addiu $s3, $s3, 8
  sll   $s1, $v0, 0x10
  sra   $t8, $s1, 0x10
  jal   get_video2_settings_txtClipH
   move  $s1, $t8
  addiu $t9, $v0, -1
  andi  $t0, $t9, 0x3ff
  addiu $t4, $s1, -1
  andi  $t2, $t4, 0x3ff
  sll   $t1, $t0, 2
  lui   $at, 0xf600
  or    $t5, $t1, $at
  sll   $t3, $t2, 0xe
  or    $t7, $t5, $t3
  sw    $t7, ($s0)
  sw    $zero, 4($s0)
.L70006700:
  jal   read_screen_display_block_and_write_chars
   move  $a0, $s3
  jal   get_memusage_display_flag
   move  $s3, $v0
  beqz  $v0, .L70006724
   nop   
  jal   display_speed_graph
   move  $a0, $s3
  move  $s3, $v0
.L70006724:
  lui   $t6, %hi(debug_feature_flag) 
  lw    $t6, %lo(debug_feature_flag)($t6)
  beql  $t6, $zero, .L7000674C
   move  $v0, $s3
  jal   display_debug_menu_text_onscreen
   nop   
  jal   print_debug_mcm_to_stdout
   move  $a0, $s3
  move  $s3, $v0
  move  $v0, $s3
.L7000674C:
  addiu $s3, $s3, 8
  lui   $t8, 0xe900
  sw    $t8, ($v0)
  sw    $zero, 4($v0)
  move  $v1, $s3
  lui   $t9, 0xb800
  sw    $t9, ($v1)
  sw    $zero, 4($v1)
  lui   $t0, %hi(show_mem_use_flag) 
  lw    $t0, %lo(show_mem_use_flag)($t0)
  addiu $s3, $s3, 8
  beqz  $t0, .L700067A8
   nop   
  jal   loop_all_mem_banks
   nop   
  jal   memaGenerateListsBeforeAfterMerge
   nop   
  jal   removed_debug_routine
   move  $a0, $s3
  jal   nullsub_41
   move  $a0, $zero
  lui   $at, %hi(show_mem_use_flag)
  sw    $zero, %lo(show_mem_use_flag)($at)
.L700067A8:
  lui   $t1, %hi(show_mem_bars_flag) 
  lw    $t1, %lo(show_mem_bars_flag)($t1)
  beqz  $t1, .L700067C0
   nop   
  jal   draw_membars
   move  $a0, $s3
.L700067C0:
  jal   allocate_something_in_mgfx
   move  $a0, $s3
  jal   allocate_something_in_mvtx
   nop   
  jal   video_related_8
   nop   
  jal   get_debug_taskgrab_val
   nop   
  beqz  $v0, .L70006854
   move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 49152
  beqz  $v0, .L70006854
   move  $a0, $zero
  jal   get_controller_buttons_held
   li    $a1, 49152
  li    $at, 49152
  bne   $v0, $at, .L70006854
.L70006808:
   lui   $a2, %hi(taskgrab_ramdump_num)
  lw    $a2, %lo(taskgrab_ramdump_num)($a2)
  move  $a0, $s4
  jal   sprintf
   move  $a1, $s6
  move  $a0, $s4
  jal   check_file_found_on_indy
   move  $a1, $s7
  beqz  $v0, .L70006844
   lui   $a2, %hi(taskgrab_ramdump_num)
  lw    $a2, %lo(taskgrab_ramdump_num)($a2)
  lui   $at, %hi(taskgrab_ramdump_num)
  addiu $a2, $a2, 1
  b     .L70006808
   sw    $a2, %lo(taskgrab_ramdump_num)($at)
.L70006844:
  move  $a0, $s4
  lui   $a1, 0x8000
  jal   indy_send_capture_data
   lui   $a2, 0x40
.L70006854:
  lw    $a0, 0x1a4($sp)
  move  $a1, $s3
  move  $a2, $zero
  jal   load_rsp_microcode
   lw    $a3, 0x48($sp)
  jal   mem_related_calls_sort_merge_entries
   addiu $fp, $fp, 1
  lw    $t4, 0x1ac($sp)
  lui   $a0, 1
  xori  $t2, $t4, 1
  jal   video_related_3
   sw    $t2, 0x1ac($sp)
  lui   $v0, %hi(loadedstage)
  b     .L700068A4
   lw    $v0, %lo(loadedstage)($v0)
.L70006890:
  addiu $fp, $fp, -1
  b     .L700068A4
   lw    $v0, %lo(loadedstage)($v0)
.L7000689C:
  li    $fp, 4
  lw    $v0, %lo(loadedstage)($v0)
.L700068A4:
  bltz  $v0, .L7000641C
   nop   
  bnez  $fp, .L7000641C
   nop   
.L700068B4:
  jal   unload_stage_text_data
   nop   
  jal   stop_demo_playback
   nop   
  jal   mempNullNextEntryInBank
   li    $a0, 4
  jal   obBlankResourcesLoadedInBank
   li    $a0, 4
  lui   $v0, %hi(loadedstage)
  addiu $v0, %lo(loadedstage) # addiu $v0, $v0, 0x42fc
  lw    $t5, ($v0)
  lw    $t7, 0x1dc($sp)
  lui   $at, %hi(current_stage_num)
  li    $t3, -1
  sw    $t5, %lo(current_stage_num)($at)
  beqz  $t7, .L7000618C
   sw    $t3, ($v0)
  jal   null_mem_bank_5
   sw    $s3, 0x1a8($sp)
  lw    $ra, 0x3c($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  lw    $s3, 0x24($sp)
  lw    $s4, 0x28($sp)
  lw    $s5, 0x2c($sp)
  lw    $s6, 0x30($sp)
  lw    $s7, 0x34($sp)
  lw    $fp, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x1e0
");

void run_title_stage(void) {
  void set_loaded_stage(LEVELID stage);
  set_loaded_stage(LEVELID_TITLE);
}

void set_loaded_stage(LEVELID stage) { loadedstage = stage; }

LEVELID get_stage_num() { return current_stage_num; }

// Return to title screen from stage.
void return_to_title_from_level_end(void) {
#ifdef VERSION_JP
  display_objective_status_text_on_status_change();
  FUN_7f057a40();
#endif
  if ((get_stage_num() != LEVELID_CUBA) && (check_objectives_complete() != 0))
    end_of_mission_briefing();
  run_title_stage();
}

// Returns if the debug menu has been enabled.
int get_debug_parse_flag(void) { return debug_feature_flag; }

// V0 = p->debug.notice.list entry for boss_c_debug using data at 800241A0.
void something_with_boss_c_debug(void) {
  set_debug_notice_list_entry(&boss_c_ptr_debug_notice_list_entry,
                              "boss_c_debug");
}
