#include "bondtypes.h" // game structs and types
#include "music.h"

int stop_play_flag, is_gameover_flag, dword_CODE_bss_8008C708,
    dword_CODE_bss_8008C70C, time_trigger_alt_gameover_msg,
    dword_CODE_bss_8008C714, is_paused, who_paused;

unsigned short loaded_text_index[] = {
    TEXT(LMPMENU, 0),   TEXT(LMPMENU, 1),   TEXT(LMPMENU, 2),
    TEXT(LMPMENU, 3),   TEXT(LMPMENU, 4),   TEXT(LMPMENU, 5),
    TEXT(LMPMENU, 6),   TEXT(LMPMENU, 7),   TEXT(LMPMENU, 8),
    TEXT(LMPMENU, 9),   TEXT(LMPMENU, 0xA), TEXT(LMPMENU, 0xB),
    TEXT(LMPMENU, 0xC), TEXT(LMPMENU, 0xD), TEXT(LMPMENU, 0xE),
    TEXT(LMPMENU, 0xF), TEXT(LMPMENU, 0x10)};

const char ascii_MP_watch_menu_percentd[] = "%d";
const char ascii_MP_watch_menu_BLANK[] = "";
const char ascii_MP_watch_menu_left_chevron[] = "<";
const char ascii_MP_watch_menu_right_chevron[] = ">";
const char ascii_pnum_KILLS[] = "%s%d %s";
const char ascii_pnum_LOSSES[] = "%s%d %s";

asm(R"
.late_rodata
glabel jpt_MP_menu_page_adv_right
.word page_adv_right_yes
.word page_adv_right_yes
.word page_adv_right_yes
.word page_adv_right_gameover
.word page_adv_right_yes
.word page_adv_right_no
.word page_adv_right_no
.word page_adv_right_no

.text
glabel check_can_advance_right_on_mpmenu
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  move  $v0, $zero
  lw    $t7, 0x29c8($t6)
  sltiu $at, $t7, 8
  beqz  $at, .L7F0C1E84
   sll   $t7, $t7, 2
  lui   $at, %hi(jpt_MP_menu_page_adv_right)
  addu  $at, $at, $t7
  lw    $t7, %lo(jpt_MP_menu_page_adv_right)($at)
  jr    $t7
   nop   
page_adv_right_yes:
  jr    $ra
   li    $v0, 1

page_adv_right_no:
  jr    $ra
   move  $v0, $zero

page_adv_right_gameover:
  lui   $t8, %hi(is_gameover_flag) 
  lw    $t8, %lo(is_gameover_flag)($t8)
  li    $v1, 1
  beqz  $t8, .L7F0C1E7C
   nop   
  jr    $ra
   move  $v0, $zero

.L7F0C1E7C:
  jr    $ra
   move  $v0, $v1

.L7F0C1E84:
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel jpt_MP_menu_page_adv_left
.word page_adv_left_no
.word page_adv_left_gameover
.word page_adv_left_yes
.word page_adv_left_yes
.word page_adv_left_yes
.word page_adv_left_yes
.word page_adv_left_no
.word page_adv_left_no

.text
glabel check_can_advance_left_on_mpmenu
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  move  $v0, $zero
  lw    $t7, 0x29c8($t6)
  sltiu $at, $t7, 8
  beqz  $at, .L7F0C1EF0
   sll   $t7, $t7, 2
  lui   $at, %hi(jpt_MP_menu_page_adv_left)
  addu  $at, $at, $t7
  lw    $t7, %lo(jpt_MP_menu_page_adv_left)($at)
  jr    $t7
   nop   
page_adv_left_yes:
  jr    $ra
   li    $v0, 1

page_adv_left_no:
  jr    $ra
   move  $v0, $zero

page_adv_left_gameover:
  lui   $t8, %hi(is_gameover_flag) 
  lw    $t8, %lo(is_gameover_flag)($t8)
  move  $v1, $zero
  beqz  $t8, .L7F0C1EE8
   nop   
  jr    $ra
   li    $v0, 1

.L7F0C1EE8:
  jr    $ra
   move  $v0, $v1

def_7F0C1EB4:
.L7F0C1EF0:
  jr    $ra
   nop   
");

asm(R"
glabel check_if_player_is_pressing_anything_right
  addiu $sp, $sp, -0x20
  sll   $a0, $a0, 0x18
  sw    $ra, 0x14($sp)
  sra   $t6, $a0, 0x18
  move  $a0, $t6
  sw    $t6, 0x18($sp)
  li    $a1, -2
  jal   get_controller_3dstick_L_R
   li    $a2, 1
  lw    $a0, 0x18($sp)
  sw    $v0, 0x1c($sp)
  jal   get_controller_buttons_pressed
   li    $a1, 257
  bnez  $v0, .L7F0C1F58
   lw    $ra, 0x14($sp)
  lw    $t7, 0x1c($sp)
  lui   $t8, %hi(pPlayer) 
  move  $v0, $zero
  blez  $t7, .L7F0C1F60
   nop   
  lw    $t8, %lo(pPlayer)($t8)
  lw    $t9, 0x29d0($t8)
  beqz  $t9, .L7F0C1F60
   nop   
.L7F0C1F58:
  b     .L7F0C1F60
   li    $v0, 1
.L7F0C1F60:
  jr    $ra
   addiu $sp, $sp, 0x20
");

asm(R"
glabel check_if_player_is_pressing_anything_left
  addiu $sp, $sp, -0x20
  sll   $a0, $a0, 0x18
  sw    $ra, 0x14($sp)
  sra   $t6, $a0, 0x18
  move  $a0, $t6
  sw    $t6, 0x18($sp)
  li    $a1, -2
  jal   get_controller_3dstick_L_R
   li    $a2, 1
  lw    $a0, 0x18($sp)
  sw    $v0, 0x1c($sp)
  jal   get_controller_buttons_pressed
   li    $a1, 514
  bnez  $v0, .L7F0C1FCC
   lw    $ra, 0x14($sp)
  lw    $t7, 0x1c($sp)
  lui   $t8, %hi(pPlayer) 
  move  $v0, $zero
  slti  $at, $t7, -1
  beqz  $at, .L7F0C1FD4
   nop   
  lw    $t8, %lo(pPlayer)($t8)
  lw    $t9, 0x29d0($t8)
  beqz  $t9, .L7F0C1FD4
   nop   
.L7F0C1FCC:
  b     .L7F0C1FD4
   li    $v0, 1
.L7F0C1FD4:
  jr    $ra
   addiu $sp, $sp, 0x20
");

void play_watch_sfx_beep(void) { play_sfx_a1(ptr_sfx_buf, 0x9f, 0); }

void unpause_game(void) {
  stop_play_flag = 0;
  is_gameover_flag = 0;
  is_paused = 0;
}

asm(R"
glabel sub_GAME_7F0C2024
  addiu $sp, $sp, -0x20
  slt   $at, $a1, $a2
  sw    $ra, 0x14($sp)
  bnez  $at, .L7F0C2064
   sw    $a0, 0x20($sp)
  bnel  $a2, $a1, .L7F0C2074
   move  $a0, $zero
  sw    $a1, 0x24($sp)
  sw    $a2, 0x28($sp)
  jal   get_random_value
   sw    $a3, 0x2c($sp)
  andi  $t6, $v0, 1
  lw    $a1, 0x24($sp)
  lw    $a2, 0x28($sp)
  beqz  $t6, .L7F0C2070
   lw    $a3, 0x2c($sp)
.L7F0C2064:
  li    $a0, 1
  b     .L7F0C2078
   move  $v1, $a2
.L7F0C2070:
  move  $a0, $zero
.L7F0C2074:
  move  $v1, $a1
.L7F0C2078:
  lw    $t7, 0x20($sp)
  slti  $at, $t7, 3
  bnez  $at, .L7F0C2100
   slt   $at, $v1, $a3
  bnezl $at, .L7F0C20C0
   li    $a0, 2
  bnel  $a3, $v1, .L7F0C20C8
   lw    $t9, 0x20($sp)
  sw    $v1, 0x1c($sp)
  sw    $a0, 0x18($sp)
  jal   get_random_value
   sw    $a3, 0x2c($sp)
  andi  $t8, $v0, 1
  lw    $v1, 0x1c($sp)
  lw    $a0, 0x18($sp)
  beqz  $t8, .L7F0C20C4
   lw    $a3, 0x2c($sp)
  li    $a0, 2
.L7F0C20C0:
  move  $v1, $a3
.L7F0C20C4:
  lw    $t9, 0x20($sp)
.L7F0C20C8:
  lw    $v0, 0x30($sp)
  slti  $at, $t9, 4
  bnez  $at, .L7F0C2100
   slt   $at, $v1, $v0
  bnezl $at, .L7F0C2100
   li    $a0, 3
  bnel  $v0, $v1, .L7F0C2104
   lw    $ra, 0x14($sp)
  jal   get_random_value
   sw    $a0, 0x18($sp)
  andi  $t0, $v0, 1
  beqz  $t0, .L7F0C2100
   lw    $a0, 0x18($sp)
  li    $a0, 3
.L7F0C2100:
  lw    $ra, 0x14($sp)
.L7F0C2104:
  addiu $sp, $sp, 0x20
  move  $v0, $a0
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0C2114
  addiu $sp, $sp, -0x20
  slt   $at, $a2, $a1
  sw    $ra, 0x14($sp)
  bnez  $at, .L7F0C2154
   sw    $a0, 0x20($sp)
  bnel  $a2, $a1, .L7F0C2164
   move  $a0, $zero
  sw    $a1, 0x24($sp)
  sw    $a2, 0x28($sp)
  jal   get_random_value
   sw    $a3, 0x2c($sp)
  andi  $t6, $v0, 1
  lw    $a1, 0x24($sp)
  lw    $a2, 0x28($sp)
  beqz  $t6, .L7F0C2160
   lw    $a3, 0x2c($sp)
.L7F0C2154:
  li    $a0, 1
  b     .L7F0C2168
   move  $v1, $a2
.L7F0C2160:
  move  $a0, $zero
.L7F0C2164:
  move  $v1, $a1
.L7F0C2168:
  lw    $t7, 0x20($sp)
  slti  $at, $t7, 3
  bnez  $at, .L7F0C21F0
   slt   $at, $a3, $v1
  bnezl $at, .L7F0C21B0
   li    $a0, 2
  bnel  $a3, $v1, .L7F0C21B8
   lw    $t9, 0x20($sp)
  sw    $v1, 0x1c($sp)
  sw    $a0, 0x18($sp)
  jal   get_random_value
   sw    $a3, 0x2c($sp)
  andi  $t8, $v0, 1
  lw    $v1, 0x1c($sp)
  lw    $a0, 0x18($sp)
  beqz  $t8, .L7F0C21B4
   lw    $a3, 0x2c($sp)
  li    $a0, 2
.L7F0C21B0:
  move  $v1, $a3
.L7F0C21B4:
  lw    $t9, 0x20($sp)
.L7F0C21B8:
  lw    $v0, 0x30($sp)
  slti  $at, $t9, 4
  bnez  $at, .L7F0C21F0
   slt   $at, $v0, $v1
  bnezl $at, .L7F0C21F0
   li    $a0, 3
  bnel  $v0, $v1, .L7F0C21F4
   lw    $ra, 0x14($sp)
  jal   get_random_value
   sw    $a0, 0x18($sp)
  andi  $t0, $v0, 1
  beqz  $t0, .L7F0C21F0
   lw    $a0, 0x18($sp)
  li    $a0, 3
.L7F0C21F0:
  lw    $ra, 0x14($sp)
.L7F0C21F4:
  addiu $sp, $sp, 0x20
  move  $v0, $a0
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0C2204
  mtc1  $a1, $f12
  mtc1  $a2, $f14
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  c.lt.s $f12, $f14
  sw    $a0, 0x20($sp)
  sw    $a3, 0x2c($sp)
  bc1tl .L7F0C2258
   trunc.w.s $f4, $f14
  c.eq.s $f14, $f12
  nop   
  bc1fl .L7F0C226C
   trunc.w.s $f6, $f12
  swc1  $f12, 0x24($sp)
  jal   get_random_value
   swc1  $f14, 0x28($sp)
  andi  $t6, $v0, 1
  lwc1  $f12, 0x24($sp)
  beqz  $t6, .L7F0C2268
   lwc1  $f14, 0x28($sp)
  trunc.w.s $f4, $f14
.L7F0C2258:
  li    $a0, 1
  mfc1  $v1, $f4
  b     .L7F0C227C
   lw    $t9, 0x20($sp)
.L7F0C2268:
  trunc.w.s $f6, $f12
.L7F0C226C:
  move  $a0, $zero
  mfc1  $v1, $f6
  nop   
  lw    $t9, 0x20($sp)
.L7F0C227C:
  slti  $at, $t9, 3
  bnezl $at, .L7F0C233C
   lw    $ra, 0x14($sp)
  mtc1  $v1, $f8
  lwc1  $f10, 0x2c($sp)
  cvt.s.w $f0, $f8
  c.lt.s $f0, $f10
  nop   
  bc1tl .L7F0C22D4
   lwc1  $f16, 0x2c($sp)
  c.eq.s $f10, $f0
  nop   
  bc1fl .L7F0C22E8
   lw    $t2, 0x20($sp)
  sw    $v1, 0x1c($sp)
  jal   get_random_value
   sw    $a0, 0x18($sp)
  andi  $t0, $v0, 1
  lw    $v1, 0x1c($sp)
  beqz  $t0, .L7F0C22E4
   lw    $a0, 0x18($sp)
  lwc1  $f16, 0x2c($sp)
.L7F0C22D4:
  li    $a0, 2
  trunc.w.s $f18, $f16
  mfc1  $v1, $f18
  nop   
.L7F0C22E4:
  lw    $t2, 0x20($sp)
.L7F0C22E8:
  slti  $at, $t2, 4
  bnezl $at, .L7F0C233C
   lw    $ra, 0x14($sp)
  mtc1  $v1, $f4
  lwc1  $f2, 0x30($sp)
  cvt.s.w $f0, $f4
  c.lt.s $f0, $f2
  nop   
  bc1tl .L7F0C2338
   li    $a0, 3
  c.eq.s $f2, $f0
  nop   
  bc1fl .L7F0C233C
   lw    $ra, 0x14($sp)
  jal   get_random_value
   sw    $a0, 0x18($sp)
  andi  $t3, $v0, 1
  beqz  $t3, .L7F0C2338
   lw    $a0, 0x18($sp)
  li    $a0, 3
.L7F0C2338:
  lw    $ra, 0x14($sp)
.L7F0C233C:
  addiu $sp, $sp, 0x20
  move  $v0, $a0
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0C234C
  mtc1  $a1, $f12
  mtc1  $a2, $f14
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  c.lt.s $f14, $f12
  sw    $a0, 0x20($sp)
  sw    $a3, 0x2c($sp)
  bc1tl .L7F0C23A0
   trunc.w.s $f4, $f14
  c.eq.s $f14, $f12
  nop   
  bc1fl .L7F0C23B4
   trunc.w.s $f6, $f12
  swc1  $f12, 0x24($sp)
  jal   get_random_value
   swc1  $f14, 0x28($sp)
  andi  $t6, $v0, 1
  lwc1  $f12, 0x24($sp)
  beqz  $t6, .L7F0C23B0
   lwc1  $f14, 0x28($sp)
  trunc.w.s $f4, $f14
.L7F0C23A0:
  li    $a0, 1
  mfc1  $v1, $f4
  b     .L7F0C23C4
   lw    $t9, 0x20($sp)
.L7F0C23B0:
  trunc.w.s $f6, $f12
.L7F0C23B4:
  move  $a0, $zero
  mfc1  $v1, $f6
  nop   
  lw    $t9, 0x20($sp)
.L7F0C23C4:
  slti  $at, $t9, 3
  bnezl $at, .L7F0C2484
   lw    $ra, 0x14($sp)
  mtc1  $v1, $f8
  lwc1  $f10, 0x2c($sp)
  cvt.s.w $f0, $f8
  c.lt.s $f10, $f0
  nop   
  bc1tl .L7F0C241C
   lwc1  $f16, 0x2c($sp)
  c.eq.s $f10, $f0
  nop   
  bc1fl .L7F0C2430
   lw    $t2, 0x20($sp)
  sw    $v1, 0x1c($sp)
  jal   get_random_value
   sw    $a0, 0x18($sp)
  andi  $t0, $v0, 1
  lw    $v1, 0x1c($sp)
  beqz  $t0, .L7F0C242C
   lw    $a0, 0x18($sp)
  lwc1  $f16, 0x2c($sp)
.L7F0C241C:
  li    $a0, 2
  trunc.w.s $f18, $f16
  mfc1  $v1, $f18
  nop   
.L7F0C242C:
  lw    $t2, 0x20($sp)
.L7F0C2430:
  slti  $at, $t2, 4
  bnezl $at, .L7F0C2484
   lw    $ra, 0x14($sp)
  mtc1  $v1, $f4
  lwc1  $f2, 0x30($sp)
  cvt.s.w $f0, $f4
  c.lt.s $f2, $f0
  nop   
  bc1tl .L7F0C2480
   li    $a0, 3
  c.eq.s $f2, $f0
  nop   
  bc1fl .L7F0C2484
   lw    $ra, 0x14($sp)
  jal   get_random_value
   sw    $a0, 0x18($sp)
  andi  $t3, $v0, 1
  beqz  $t3, .L7F0C2480
   lw    $a0, 0x18($sp)
  li    $a0, 3
.L7F0C2480:
  lw    $ra, 0x14($sp)
.L7F0C2484:
  addiu $sp, $sp, 0x20
  move  $v0, $a0
  jr    $ra
   nop   
");

void pauseAndLockControls(void) {
  set_controls_locked_flag(1);
  is_paused = 1;
}

asm(R"
glabel sub_GAME_7F0C24BC
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   getPlayerCount
   nop   
  li    $at, 1
  bne   $v0, $at, .L7F0C24E0
   lw    $ra, 0x14($sp)
  b     .L7F0C2518
   li    $v0, 1
.L7F0C24E0:
  lui   $t6, %hi(stop_play_flag) 
  lw    $t6, %lo(stop_play_flag)($t6)
  lui   $t7, %hi(pPlayer) 
  beqz  $t6, .L7F0C24FC
   nop   
  b     .L7F0C2518
   move  $v0, $zero
.L7F0C24FC:
  lw    $t7, %lo(pPlayer)($t7)
  li    $v0, 1
  lw    $t8, 0x29c4($t7)
  beqz  $t8, .L7F0C2518
   nop   
  b     .L7F0C2518
   move  $v0, $zero
.L7F0C2518:
  jr    $ra
   addiu $sp, $sp, 0x18
");

void set_stopplay_flag(void) { stop_play_flag = 1; }

asm(R"
.late_rodata
glabel D_8005BC80
.word 0x4852f000 /*216000.0*/
glabel D_8005BC84
.word 0x47c35000 /*100000.0*/

.text
glabel sub_GAME_7F0C2530
  addiu $sp, $sp, -0x168
  sw    $ra, 0x44($sp)
  sw    $s1, 0x24($sp)
  move  $s1, $a0
  sw    $fp, 0x40($sp)
  sw    $s7, 0x3c($sp)
  sw    $s6, 0x38($sp)
  sw    $s5, 0x34($sp)
  sw    $s4, 0x30($sp)
  sw    $s3, 0x2c($sp)
  sw    $s2, 0x28($sp)
  jal   getPlayerCount
   sw    $s0, 0x20($sp)
  jal   get_mission_timer
   move  $fp, $v0
  jal   sfx_c_70009124
   move  $s0, $v0
  jal   set_missionstate
   move  $a0, $zero
  jal   sub_GAME_7F0C0BF0
   nop   
  jal   musicTrack1Vol
   andi  $a0, $v0, 0xffff
  lui   $at, %hi(music1_playing)
  sw    $zero, %lo(music1_playing)($at)
  jal   musicTrack1Play
   li    $a0, 44
  jal   pauseAndLockControls
   nop   
  beqz  $s1, .L7F0C25BC
   li    $t8, 1
  li    $t6, 300
  lui   $at, %hi(is_gameover_flag)
  b     .L7F0C25C8
   sw    $t6, %lo(is_gameover_flag)($at)
.L7F0C25BC:
  li    $t7, 1
  lui   $at, %hi(is_gameover_flag)
  sw    $t7, %lo(is_gameover_flag)($at)
.L7F0C25C8:
  lui   $at, %hi(time_trigger_alt_gameover_msg)
  sw    $t8, %lo(time_trigger_alt_gameover_msg)($at)
  lui   $at, %hi(dword_CODE_bss_8008C714)
  li    $t9, 20
  sw    $t9, %lo(dword_CODE_bss_8008C714)($at)
  lui   $at, %hi(dword_CODE_bss_8008C708)
  sw    $zero, %lo(dword_CODE_bss_8008C708)($at)
  lui   $at, %hi(dword_CODE_bss_8008C70C)
  jal   get_cur_playernum
   sw    $zero, %lo(dword_CODE_bss_8008C70C)($at)
  sw    $v0, 0x150($sp)
  blez  $fp, .L7F0C27D8
   move  $s6, $zero
  addiu $t0, $s0, 1
  mtc1  $t0, $f4
  lui   $at, %hi(D_8005BC80)
  lwc1  $f8, %lo(D_8005BC80)($at)
  cvt.s.w $f6, $f4
  lui   $s4, %hi(player1_player_data)
  lui   $s5, %hi(pPlayer)
  addiu $s5, %lo(pPlayer) # addiu $s5, $s5, -0x5f50
  addiu $s4, %lo(player1_player_data) # addiu $s4, $s4, -0x6110
  addiu $s2, $sp, 0x6c
  div.s $f10, $f6, $f8
  li    $s7, 3
  swc1  $f10, 0x48($sp)
.L7F0C2630:
  move  $a0, $s6
  jal   set_cur_player
   move  $s1, $zero
  lw    $t2, ($s5)
  li    $t1, 1
  addiu $a0, $sp, 0x154
  sw    $t1, 0x29c4($t2)
  lw    $t3, ($s5)
  addiu $a1, $sp, 0x158
  sw    $s7, 0x29c8($t3)
  lw    $t4, ($s5)
  sw    $zero, 0x2a10($t4)
  lw    $t5, ($s5)
  jal   sub_GAME_7F08DB08
   sw    $zero, 0x2a14($t5)
  lw    $a0, 0x154($sp)
  jal   store_favorite_weapon_current_player
   lw    $a1, 0x158($sp)
  jal   get_curplayer_shot_register
   move  $a0, $zero
  sw    $v0, ($s2)
  jal   get_curplayer_shot_register
   li    $a0, 1
  sw    $v0, 4($s2)
  sw    $zero, 8($s2)
  sw    $zero, 0xc($s2)
  jal   get_selected_num_players
   sw    $zero, 0x10($s2)
  blez  $v0, .L7F0C2730
   sll   $t6, $s1, 3
  sll   $t0, $s6, 3
  subu  $t0, $t0, $s6
  subu  $t6, $t6, $s1
  lui   $t9, %hi(player1_player_data) 
  addiu $t9, %lo(player1_player_data) # addiu $t9, $t9, -0x6110
  sll   $t6, $t6, 4
  sll   $t0, $t0, 4
  sll   $t7, $s6, 2
  sll   $t1, $s1, 2
  addu  $t2, $t0, $t1
  addu  $t8, $t6, $t7
  addu  $s3, $t8, $t9
  addu  $s0, $t2, $t9
  lw    $t3, 0xc($s2)
.L7F0C26E0:
  lw    $t4, 0x24($s3)
  addiu $s3, $s3, 0x70
  addu  $t5, $t3, $t4
  bne   $s6, $s1, .L7F0C2708
   sw    $t5, 0xc($s2)
  lw    $t6, 0x10($s2)
  lw    $t7, 0x24($s0)
  addu  $t8, $t6, $t7
  b     .L7F0C2718
   sw    $t8, 0x10($s2)
.L7F0C2708:
  lw    $t0, 8($s2)
  lw    $t1, 0x24($s0)
  addu  $t2, $t0, $t1
  sw    $t2, 8($s2)
.L7F0C2718:
  addiu $s1, $s1, 1
  jal   get_selected_num_players
   addiu $s0, $s0, 4
  slt   $at, $s1, $v0
  bnezl $at, .L7F0C26E0
   lw    $t3, 0xc($s2)
.L7F0C2730:
  lw    $t9, 8($s2)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f2
  mtc1  $t9, $f16
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f4
  cvt.s.w $f18, $f16
  lw    $t3, ($s2)
  lw    $t4, 0xc($s2)
  lw    $t5, 0x3c($s4)
  mtc1  $t3, $f6
  lw    $t6, 0x34($s4)
  mul.s $f0, $f18, $f4
  mtc1  $t4, $f18
  lui   $at, %hi(D_8005BC84)
  sw    $t5, 0x1c($s2)
  sw    $t6, 0x20($s2)
  lw    $t7, 0x4c($s4)
  cvt.s.w $f8, $f6
  lw    $t8, 0x50($s4)
  addiu $s6, $s6, 1
  addiu $s2, $s2, 0x38
  addiu $s4, $s4, 0x70
  cvt.s.w $f4, $f18
  add.s $f10, $f8, $f2
  add.s $f6, $f4, $f2
  div.s $f16, $f0, $f10
  lwc1  $f10, -0x38($s4)
  div.s $f8, $f0, $f6
  swc1  $f16, -0x24($s2)
  swc1  $f8, -0x20($s2)
  lwc1  $f16, %lo(D_8005BC84)($at)
  lwc1  $f4, 0x48($sp)
  lwc1  $f8, -0x30($s4)
  div.s $f18, $f10, $f16
  sw    $zero, -0xc($s2)
  sw    $t7, -8($s2)
  sw    $t8, -4($s2)
  swc1  $f8, -0x10($s2)
  div.s $f6, $f18, $f4
  bne   $s6, $fp, .L7F0C2630
   swc1  $f6, -0x14($s2)
.L7F0C27D8:
  li    $s7, 3
  jal   set_cur_player
   lw    $a0, 0x150($sp)
  lw    $t0, 0x124($sp)
  move  $a0, $fp
  lw    $a1, 0x7c($sp)
  lw    $a2, 0xb4($sp)
  lw    $a3, 0xec($sp)
  jal   sub_GAME_7F0C2024
   sw    $t0, 0x10($sp)
  li    $s3, 56
  multu $v0, $s3
  addiu $s1, $sp, 0x6c
  move  $a0, $fp
  mflo  $t1
  addu  $s0, $s1, $t1
  lw    $t2, 0x10($s0)
  blezl $t2, .L7F0C2834
   lw    $t4, 0x114($sp)
  lw    $t9, 0x2c($s0)
  ori   $t3, $t9, 1
  sw    $t3, 0x2c($s0)
  lw    $t4, 0x114($sp)
.L7F0C2834:
  lw    $a1, 0x6c($sp)
  lw    $a2, 0xa4($sp)
  lw    $a3, 0xdc($sp)
  jal   sub_GAME_7F0C2114
   sw    $t4, 0x10($sp)
  multu $v0, $s3
  move  $a0, $fp
  mflo  $t5
  addu  $s0, $s1, $t5
  lw    $t6, ($s0)
  slti  $at, $t6, 0x64
  beql  $at, $zero, .L7F0C2878
   lwc1  $f10, 0x13c($sp)
  lw    $t7, 0x2c($s0)
  ori   $t8, $t7, 2
  sw    $t8, 0x2c($s0)
  lwc1  $f10, 0x13c($sp)
.L7F0C2878:
  lw    $a1, 0x94($sp)
  lw    $a2, 0xcc($sp)
  lw    $a3, 0x104($sp)
  jal   sub_GAME_7F0C234C
   swc1  $f10, 0x10($sp)
  multu $v0, $s3
  li    $at, 0x40000000 # 2.000000
  mtc1  $at, $f16
  move  $a0, $fp
  mflo  $t0
  addu  $s0, $s1, $t0
  lwc1  $f18, 0x28($s0)
  c.le.s $f18, $f16
  nop   
  bc1fl .L7F0C28C8
   lwc1  $f4, 0x13c($sp)
  lw    $t1, 0x2c($s0)
  ori   $t2, $t1, 4
  sw    $t2, 0x2c($s0)
  lwc1  $f4, 0x13c($sp)
.L7F0C28C8:
  lw    $a1, 0x94($sp)
  lw    $a2, 0xcc($sp)
  lw    $a3, 0x104($sp)
  jal   sub_GAME_7F0C2204
   swc1  $f4, 0x10($sp)
  multu $v0, $s3
  li    $at, 0x40C00000 # 6.000000
  mtc1  $at, $f6
  move  $a0, $fp
  mflo  $t9
  addu  $s0, $s1, $t9
  lwc1  $f8, 0x28($s0)
  c.lt.s $f6, $f8
  nop   
  bc1fl .L7F0C2918
   lw    $t5, 0x118($sp)
  lw    $t3, 0x2c($s0)
  ori   $t4, $t3, 8
  sw    $t4, 0x2c($s0)
  lw    $t5, 0x118($sp)
.L7F0C2918:
  lw    $a1, 0x70($sp)
  lw    $a2, 0xa8($sp)
  lw    $a3, 0xe0($sp)
  jal   sub_GAME_7F0C2024
   sw    $t5, 0x10($sp)
  multu $v0, $s3
  move  $a0, $fp
  mflo  $t6
  addu  $s0, $s1, $t6
  lw    $t7, 4($s0)
  blezl $t7, .L7F0C2958
   lwc1  $f10, 0x128($sp)
  lw    $t8, 0x2c($s0)
  ori   $t0, $t8, 0x10
  sw    $t0, 0x2c($s0)
  lwc1  $f10, 0x128($sp)
.L7F0C2958:
  lw    $a1, 0x80($sp)
  lw    $a2, 0xb8($sp)
  lw    $a3, 0xf0($sp)
  jal   sub_GAME_7F0C2204
   swc1  $f10, 0x10($sp)
  multu $v0, $s3
  mtc1  $zero, $f16
  move  $a0, $fp
  mflo  $t1
  addu  $s0, $s1, $t1
  lwc1  $f18, 0x14($s0)
  c.lt.s $f16, $f18
  nop   
  bc1fl .L7F0C29A4
   lwc1  $f4, 0x12c($sp)
  lw    $t2, 0x2c($s0)
  ori   $t9, $t2, 0x20
  sw    $t9, 0x2c($s0)
  lwc1  $f4, 0x12c($sp)
.L7F0C29A4:
  lw    $a1, 0x84($sp)
  lw    $a2, 0xbc($sp)
  lw    $a3, 0xf4($sp)
  jal   sub_GAME_7F0C2204
   swc1  $f4, 0x10($sp)
  multu $v0, $s3
  mtc1  $zero, $f6
  move  $a0, $fp
  mflo  $t3
  addu  $s0, $s1, $t3
  lwc1  $f8, 0x18($s0)
  c.lt.s $f6, $f8
  nop   
  bc1fl .L7F0C29F0
   lwc1  $f10, 0x12c($sp)
  lw    $t4, 0x2c($s0)
  ori   $t5, $t4, 0x40
  sw    $t5, 0x2c($s0)
  lwc1  $f10, 0x12c($sp)
.L7F0C29F0:
  lw    $a1, 0x84($sp)
  lw    $a2, 0xbc($sp)
  lw    $a3, 0xf4($sp)
  jal   sub_GAME_7F0C234C
   swc1  $f10, 0x10($sp)
  multu $v0, $s3
  move  $a0, $fp
  mflo  $t6
  addu  $s0, $s1, $t6
  lw    $t7, 0x2c($s0)
  ori   $t8, $t7, 0x80
  sw    $t8, 0x2c($s0)
  lw    $t0, 0x134($sp)
  lw    $a3, 0xfc($sp)
  lw    $a2, 0xc4($sp)
  lw    $a1, 0x8c($sp)
  jal   sub_GAME_7F0C2114
   sw    $t0, 0x10($sp)
  multu $v0, $s3
  move  $a0, $fp
  mflo  $t1
  addu  $s0, $s1, $t1
  lw    $t2, 0x2c($s0)
  ori   $t9, $t2, 0x100
  sw    $t9, 0x2c($s0)
  lwc1  $f16, 0x138($sp)
  lw    $a3, 0x100($sp)
  lw    $a2, 0xc8($sp)
  lw    $a1, 0x90($sp)
  jal   sub_GAME_7F0C2204
   swc1  $f16, 0x10($sp)
  multu $v0, $s3
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f18
  move  $a0, $fp
  mflo  $t3
  addu  $s0, $s1, $t3
  lwc1  $f4, 0x24($s0)
  c.lt.s $f18, $f4
  nop   
  bc1fl .L7F0C2AA8
   lw    $t6, 0x130($sp)
  lw    $t4, 0x2c($s0)
  ori   $t5, $t4, 0x200
  sw    $t5, 0x2c($s0)
  lw    $t6, 0x130($sp)
.L7F0C2AA8:
  lw    $a1, 0x88($sp)
  lw    $a2, 0xc0($sp)
  lw    $a3, 0xf8($sp)
  jal   sub_GAME_7F0C2114
   sw    $t6, 0x10($sp)
  multu $v0, $s3
  move  $a0, $fp
  mflo  $t7
  addu  $s0, $s1, $t7
  lw    $t8, 0x2c($s0)
  ori   $t0, $t8, 0x400
  sw    $t0, 0x2c($s0)
  lw    $t1, 0x130($sp)
  lw    $a3, 0xf8($sp)
  lw    $a2, 0xc0($sp)
  lw    $a1, 0x88($sp)
  jal   sub_GAME_7F0C2024
   sw    $t1, 0x10($sp)
  multu $v0, $s3
  move  $a0, $fp
  mflo  $t2
  addu  $s0, $s1, $t2
  lw    $t9, 0x1c($s0)
  blezl $t9, .L7F0C2B24
   lw    $t5, 0x144($sp)
  lw    $v1, 0x2c($s0)
  andi  $t3, $v1, 0x400
  bnez  $t3, .L7F0C2B20
   ori   $t4, $v1, 0x800
  sw    $t4, 0x2c($s0)
.L7F0C2B20:
  lw    $t5, 0x144($sp)
.L7F0C2B24:
  lw    $a1, 0x9c($sp)
  lw    $a2, 0xd4($sp)
  lw    $a3, 0x10c($sp)
  jal   sub_GAME_7F0C2024
   sw    $t5, 0x10($sp)
  multu $v0, $s3
  move  $a0, $fp
  mflo  $t6
  addu  $s0, $s1, $t6
  lw    $t7, 0x30($s0)
  blezl $t7, .L7F0C2B64
   lw    $t1, 0x148($sp)
  lw    $t8, 0x2c($s0)
  ori   $t0, $t8, 0x2000
  sw    $t0, 0x2c($s0)
  lw    $t1, 0x148($sp)
.L7F0C2B64:
  lw    $a1, 0xa0($sp)
  lw    $a2, 0xd8($sp)
  lw    $a3, 0x110($sp)
  jal   sub_GAME_7F0C2114
   sw    $t1, 0x10($sp)
  multu $v0, $s3
  andi  $v0, $fp, 1
  mflo  $t2
  addu  $s0, $s1, $t2
  lw    $t9, 0x34($s0)
  blez  $t9, .L7F0C2BA0
   nop   
  lw    $t3, 0x2c($s0)
  ori   $t4, $t3, 0x1000
  sw    $t4, 0x2c($s0)
.L7F0C2BA0:
  blez  $fp, .L7F0C2D0C
   move  $s6, $zero
  beqz  $v0, .L7F0C2C04
   lui   $t9, %hi(player1_player_data) 
  lui   $v0, %hi(player1_player_data + 0x58)
  lw    $v0, %lo(player1_player_data + 0x58)($v0)
  li    $v1, 4
  li    $s6, 1
  bne   $v1, $v0, .L7F0C2BD8
   lw    $t5, 0x98($sp)
  lui   $a0, 1
  or    $t6, $t5, $a0
  b     .L7F0C2C00
   sw    $t6, 0x98($sp)
.L7F0C2BD8:
  bne   $s7, $v0, .L7F0C2BF0
   li    $a1, 2
  lw    $t7, 0x98($sp)
  ori   $t8, $t7, 0x8000
  b     .L7F0C2C00
   sw    $t8, 0x98($sp)
.L7F0C2BF0:
  bne   $a1, $v0, .L7F0C2C00
   lw    $t0, 0x98($sp)
  ori   $t1, $t0, 0x4000
  sw    $t1, 0x98($sp)
.L7F0C2C00:
  beq   $s6, $fp, .L7F0C2D08
.L7F0C2C04:
   sll   $t2, $s6, 3
  subu  $t2, $t2, $s6
  sll   $t2, $t2, 4
  addiu $t9, %lo(player1_player_data) # addiu $t9, $t9, -0x6110
  addu  $s4, $t2, $t9
  li    $v1, 4
  lui   $a0, 1
  li    $a1, 2
.L7F0C2C24:
  lw    $v0, 0x58($s4)
  bne   $v1, $v0, .L7F0C2C4C
   nop   
  multu $s6, $s3
  mflo  $t3
  addu  $s2, $s1, $t3
  lw    $t4, 0x2c($s2)
  or    $t5, $t4, $a0
  b     .L7F0C2C90
   sw    $t5, 0x2c($s2)
.L7F0C2C4C:
  bne   $s7, $v0, .L7F0C2C70
   nop   
  multu $s6, $s3
  mflo  $t6
  addu  $s2, $s1, $t6
  lw    $t7, 0x2c($s2)
  ori   $t8, $t7, 0x8000
  b     .L7F0C2C90
   sw    $t8, 0x2c($s2)
.L7F0C2C70:
  bnel  $a1, $v0, .L7F0C2C94
   lw    $v0, 0xc8($s4)
  multu $s6, $s3
  mflo  $t0
  addu  $s2, $s1, $t0
  lw    $t1, 0x2c($s2)
  ori   $t2, $t1, 0x4000
  sw    $t2, 0x2c($s2)
.L7F0C2C90:
  lw    $v0, 0xc8($s4)
.L7F0C2C94:
  bne   $v1, $v0, .L7F0C2CB8
   nop   
  multu $s6, $s3
  mflo  $t9
  addu  $s2, $s1, $t9
  lw    $t3, 0x64($s2)
  or    $t4, $t3, $a0
  b     .L7F0C2CFC
   sw    $t4, 0x64($s2)
.L7F0C2CB8:
  bne   $s7, $v0, .L7F0C2CDC
   nop   
  multu $s6, $s3
  mflo  $t5
  addu  $s2, $s1, $t5
  lw    $t6, 0x64($s2)
  ori   $t7, $t6, 0x8000
  b     .L7F0C2CFC
   sw    $t7, 0x64($s2)
.L7F0C2CDC:
  bnel  $a1, $v0, .L7F0C2D00
   addiu $s6, $s6, 2
  multu $s6, $s3
  mflo  $t8
  addu  $s2, $s1, $t8
  lw    $t0, 0x64($s2)
  ori   $t1, $t0, 0x4000
  sw    $t1, 0x64($s2)
.L7F0C2CFC:
  addiu $s6, $s6, 2
.L7F0C2D00:
  bne   $s6, $fp, .L7F0C2C24
   addiu $s4, $s4, 0xe0
.L7F0C2D08:
  move  $s6, $zero
.L7F0C2D0C:
  blez  $fp, .L7F0C2E50
   lui   $s4, %hi(loaded_text_index)
  addiu $s4, %lo(loaded_text_index) # addiu $s4, $s4, -0x79c0
  addiu $s2, $sp, 0x6c
  li    $s5, 17
.L7F0C2D20:
  move  $s3, $zero
  li    $a1, 16
  lw    $s0, 0x2c($s2)
.L7F0C2D2C:
  li    $t2, 1
  sllv  $v0, $t2, $a1
  and   $t9, $s0, $v0
  beqz  $t9, .L7F0C2D78
   not   $t3, $v0
  sll   $t5, $a1, 1
  lui   $t8, %hi(ptr_BONDdata_p1) 
  and   $t4, $s0, $t3
  addiu $t8, %lo(ptr_BONDdata_p1) # addiu $t8, $t8, -0x6120
  addu  $t6, $s4, $t5
  sll   $t7, $s6, 2
  sw    $t4, 0x2c($s2)
  addu  $s1, $t7, $t8
  lhu   $a0, ($t6)
  jal   get_textptr_for_textID
   li    $s3, 1
  lw    $t0, ($s1)
  sw    $v0, 0x2a10($t0)
  lw    $s0, 0x2c($s2)
.L7F0C2D78:
  bnez  $s0, .L7F0C2D84
   nop   
  li    $s3, 1
.L7F0C2D84:
  jal   get_random_value
   nop   
  divu  $zero, $v0, $s5
  mfhi  $a1
  bnez  $s5, .L7F0C2DA0
   nop   
  break 7
.L7F0C2DA0:
  beql  $s3, $zero, .L7F0C2D2C
   lw    $s0, 0x2c($s2)
  slti  $at, $s3, 2
  beql  $at, $zero, .L7F0C2E48
   addiu $s6, $s6, 1
.L7F0C2DB4:
  jal   get_random_value
   nop   
  divu  $zero, $v0, $s5
  lw    $s0, 0x2c($s2)
  mfhi  $v1
  li    $t1, 1
  sllv  $t2, $t1, $v1
  bnez  $s5, .L7F0C2DDC
   nop   
  break 7
.L7F0C2DDC:
  and   $t9, $s0, $t2
  beqz  $t9, .L7F0C2E2C
   move  $a1, $v1
  li    $t3, 1
  sllv  $t4, $t3, $v1
  not   $t5, $t4
  sll   $t7, $v1, 1
  lui   $t1, %hi(ptr_BONDdata_p1) 
  and   $t6, $s0, $t5
  addiu $t1, %lo(ptr_BONDdata_p1) # addiu $t1, $t1, -0x6120
  addu  $t8, $s4, $t7
  sll   $t0, $s6, 2
  sw    $t6, 0x2c($s2)
  addu  $s1, $t0, $t1
  lhu   $a0, ($t8)
  jal   get_textptr_for_textID
   li    $s3, 2
  lw    $t2, ($s1)
  sw    $v0, 0x2a14($t2)
  lw    $s0, 0x2c($s2)
.L7F0C2E2C:
  bnezl $s0, .L7F0C2E3C
   slti  $at, $s3, 2
  li    $s3, 2
  slti  $at, $s3, 2
.L7F0C2E3C:
  bnez  $at, .L7F0C2DB4
   nop   
  addiu $s6, $s6, 1
.L7F0C2E48:
  bne   $s6, $fp, .L7F0C2D20
   addiu $s2, $s2, 0x38
.L7F0C2E50:
  lw    $ra, 0x44($sp)
  lw    $s0, 0x20($sp)
  lw    $s1, 0x24($sp)
  lw    $s2, 0x28($sp)
  lw    $s3, 0x2c($sp)
  lw    $s4, 0x30($sp)
  lw    $s5, 0x34($sp)
  lw    $s6, 0x38($sp)
  lw    $s7, 0x3c($sp)
  lw    $fp, 0x40($sp)
  jr    $ra
   addiu $sp, $sp, 0x168
");

asm(R"
glabel sub_GAME_7F0C2E80
  addiu $sp, $sp, -0x38
  sw    $ra, 0x14($sp)
  jal   get_cur_playernum
   nop   
  jal   getPlayerCount
   sw    $v0, 0x34($sp)
  lb    $a0, 0x37($sp)
  li    $a1, -2
  li    $a2, 1
  sw    $v0, 0x30($sp)
  jal   get_controller_3dstick_L_R
   sw    $a0, 0x18($sp)
  sw    $v0, 0x2c($sp)
  jal   sub_GAME_7F09B4D8
   lw    $a0, 0x34($sp)
  bnez  $v0, .L7F0C2EF8
   lw    $t0, 0x30($sp)
  lui   $a1, %hi(is_gameover_flag)
  addiu $a1, %lo(is_gameover_flag) # addiu $a1, $a1, -0x38fc
  lw    $v0, ($a1)
  lui   $t6, %hi(D_80048498) 
  slti  $at, $v0, 2
  bnez  $at, .L7F0C2EF8
   nop   
  lw    $t6, %lo(D_80048498)($t6)
  li    $t9, 1
  subu  $t7, $v0, $t6
  bgtz  $t7, .L7F0C2EF8
   sw    $t7, ($a1)
  sw    $t9, ($a1)
.L7F0C2EF8:
  lui   $a1, %hi(is_gameover_flag)
  li    $at, 1
  beq   $t0, $at, .L7F0C3590
   addiu $a1, %lo(is_gameover_flag) # addiu $a1, $a1, -0x38fc
  lui   $a3, %hi(pPlayer)
  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
  lw    $v1, ($a3)
  lw    $v0, ($a1)
  lw    $t1, 0xd8($v1)
  slti  $at, $v0, 2
  beqz  $t1, .L7F0C2F40
   nop   
  bnez  $v0, .L7F0C2F40
   nop   
  sw    $zero, 0x29c4($v1)
  lw    $t2, ($a3)
  b     .L7F0C3590
   sw    $zero, 0x2a00($t2)
.L7F0C2F40:
  beqz  $at, .L7F0C3590
   lw    $a0, 0x34($sp)
  jal   sub_GAME_7F09B4D8
   sw    $t0, 0x30($sp)
  lui   $a3, %hi(pPlayer)
  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
  bnez  $v0, .L7F0C2FE0
   lw    $t0, 0x30($sp)
  lui   $a0, %hi(dword_CODE_bss_8008C70C)
  addiu $a0, %lo(dword_CODE_bss_8008C70C) # addiu $a0, $a0, -0x38f4
  lui   $a1, %hi(dword_CODE_bss_8008C714)
  lui   $v0, %hi(D_80048498)
  lw    $v0, %lo(D_80048498)($v0)
  lw    $t3, ($a0)
  addiu $a1, %lo(dword_CODE_bss_8008C714) # addiu $a1, $a1, -0x38ec
  lw    $t5, ($a1)
  addu  $t4, $t3, $v0
  slti  $at, $t4, 0x14
  addu  $t6, $t5, $v0
  sw    $t4, ($a0)
  bnez  $at, .L7F0C2FB4
   sw    $t6, ($a1)
  lui   $a2, %hi(dword_CODE_bss_8008C708)
  addiu $a2, %lo(dword_CODE_bss_8008C708) # addiu $a2, $a2, -0x38f8
  lw    $v0, ($a2)
  addiu $t7, $t4, -0x14
  sw    $t7, ($a0)
  sltiu $t8, $v0, 1
  sw    $t8, ($a2)
.L7F0C2FB4:
  lw    $v1, ($a1)
  lui   $a0, %hi(time_trigger_alt_gameover_msg)
  addiu $a0, %lo(time_trigger_alt_gameover_msg) # addiu $a0, $a0, -0x38f0
  slti  $at, $v1, 0x78
  bnez  $at, .L7F0C2FE0
   nop   
  lw    $v0, ($a0)
  addiu $t9, $v1, -0x78
  sw    $t9, ($a1)
  sltiu $t1, $v0, 1
  sw    $t1, ($a0)
.L7F0C2FE0:
  lui   $v0, %hi(pPlayersPerm)
  lw    $v0, %lo(pPlayersPerm)($v0)
  lw    $t2, ($a3)
  lw    $t3, 0x54($v0)
  lw    $v1, 0x29f8($t2)
  slt   $at, $t3, $v1
  beqz  $at, .L7F0C3004
   nop   
  sw    $v1, 0x54($v0)
.L7F0C3004:
  jal   get_mission_timer
   sw    $t0, 0x30($sp)
  lui   $a3, %hi(pPlayer)
  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
  lw    $v1, ($a3)
  lui   $t4, %hi(pPlayersPerm) 
  lw    $t4, %lo(pPlayersPerm)($t4)
  lw    $t6, 0x29f4($v1)
  lw    $t0, 0x30($sp)
  lw    $t5, 0x4c($t4)
  subu  $t7, $v0, $t6
  slt   $at, $t5, $t7
  beql  $at, $zero, .L7F0C3070
   lw    $t3, 0x29c4($v1)
  jal   get_mission_timer
   sw    $t0, 0x30($sp)
  lui   $a3, %hi(pPlayer)
  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
  lw    $t8, ($a3)
  lui   $t2, %hi(pPlayersPerm) 
  lw    $t2, %lo(pPlayersPerm)($t2)
  lw    $t9, 0x29f4($t8)
  lw    $t0, 0x30($sp)
  subu  $t1, $v0, $t9
  sw    $t1, 0x4c($t2)
  lw    $v1, ($a3)
  lw    $t3, 0x29c4($v1)
.L7F0C3070:
  lb    $a0, 0x1b($sp)
  beqz  $t3, .L7F0C3534
   nop   
  lw    $a0, 0x34($sp)
  jal   check_if_player_is_pressing_anything_right
   sw    $t0, 0x30($sp)
  beqz  $v0, .L7F0C30C4
   lw    $t0, 0x30($sp)
  jal   check_can_advance_right_on_mpmenu
   sw    $t0, 0x30($sp)
  beqz  $v0, .L7F0C30C4
   lw    $t0, 0x30($sp)
  jal   play_watch_sfx_beep
   nop   
  lui   $a3, %hi(pPlayer)
  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
  lw    $v1, ($a3)
  lw    $t4, 0x29c8($v1)
  addiu $t6, $t4, 1
  b     .L7F0C3508
   sw    $t6, 0x29c8($v1)
.L7F0C30C4:
  lw    $a0, 0x34($sp)
  jal   check_if_player_is_pressing_anything_left
   sw    $t0, 0x30($sp)
  beqz  $v0, .L7F0C310C
   lw    $t0, 0x30($sp)
  jal   check_can_advance_left_on_mpmenu
   sw    $t0, 0x30($sp)
  beqz  $v0, .L7F0C310C
   lw    $t0, 0x30($sp)
  jal   play_watch_sfx_beep
   nop   
  lui   $a3, %hi(pPlayer)
  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
  lw    $v1, ($a3)
  lw    $t5, 0x29c8($v1)
  addiu $t7, $t5, -1
  b     .L7F0C3508
   sw    $t7, 0x29c8($v1)
.L7F0C310C:
  lw    $a0, 0x34($sp)
  jal   check_if_player_is_pressing_anything_right
   sw    $t0, 0x30($sp)
  lui   $a3, %hi(pPlayer)
  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
  beqz  $v0, .L7F0C315C
   lw    $t0, 0x30($sp)
  lw    $t8, ($a3)
  li    $at, 6
  lw    $t9, 0x29c8($t8)
  bnel  $t9, $at, .L7F0C3160
   lw    $a0, 0x34($sp)
  jal   play_watch_sfx_beep
   nop   
  lui   $a3, %hi(pPlayer)
  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
  lw    $t2, ($a3)
  li    $t1, 1
  b     .L7F0C3508
   sw    $t1, 0x29cc($t2)
.L7F0C315C:
  lw    $a0, 0x34($sp)
.L7F0C3160:
  jal   check_if_player_is_pressing_anything_left
   sw    $t0, 0x30($sp)
  lui   $a3, %hi(pPlayer)
  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
  beqz  $v0, .L7F0C31A8
   lw    $t0, 0x30($sp)
  lw    $t3, ($a3)
  li    $at, 6
  lw    $t4, 0x29c8($t3)
  bnel  $t4, $at, .L7F0C31AC
   lb    $a0, 0x1b($sp)
  jal   play_watch_sfx_beep
   nop   
  lui   $a3, %hi(pPlayer)
  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
  lw    $t6, ($a3)
  b     .L7F0C3508
   sw    $zero, 0x29cc($t6)
.L7F0C31A8:
  lb    $a0, 0x1b($sp)
.L7F0C31AC:
  li    $a1, 32768
  jal   get_controller_buttons_pressed
   sw    $t0, 0x30($sp)
  lui   $a3, %hi(pPlayer)
  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
  beqz  $v0, .L7F0C324C
   lw    $t0, 0x30($sp)
  lw    $t5, ($a3)
  li    $at, 4
  lw    $t7, 0x29c8($t5)
  bnel  $t7, $at, .L7F0C3250
   lw    $t2, ($a3)
  jal   play_watch_sfx_beep
   nop   
  lui   $v1, %hi(is_paused)
  addiu $v1, %lo(is_paused) # addiu $v1, $v1, -0x38e8
  lw    $t8, ($v1)
  li    $t9, 1
  bnez  $t8, .L7F0C321C
   nop   
  jal   get_cur_playernum
   sw    $t9, ($v1)
  lui   $at, %hi(who_paused)
  sw    $v0, %lo(who_paused)($at)
  jal   set_controls_locked_flag
   li    $a0, 1
  b     .L7F0C350C
   lw    $v0, 0x2c($sp)
.L7F0C321C:
  jal   get_cur_playernum
   nop   
  lui   $t1, %hi(who_paused) 
  lw    $t1, %lo(who_paused)($t1)
  lui   $v1, %hi(is_paused)
  addiu $v1, %lo(is_paused) # addiu $v1, $v1, -0x38e8
  bne   $v0, $t1, .L7F0C3508
   move  $a0, $zero
  jal   set_controls_locked_flag
   sw    $zero, ($v1)
  b     .L7F0C350C
   lw    $v0, 0x2c($sp)
.L7F0C324C:
  lw    $t2, ($a3)
.L7F0C3250:
  li    $a2, 7
  lb    $a0, 0x1b($sp)
  lw    $t3, 0x29c8($t2)
  li    $a1, 36864
  bne   $a2, $t3, .L7F0C32A8
   nop   
  lb    $a0, 0x1b($sp)
  jal   get_controller_buttons_pressed
   li    $a1, 16384
  beql  $v0, $zero, .L7F0C350C
   lw    $v0, 0x2c($sp)
  jal   play_watch_sfx_beep
   nop   
  lui   $a3, %hi(pPlayer)
  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
  lw    $t6, ($a3)
  li    $t4, 1
  li    $t5, 3
  sw    $t4, 0x29c4($t6)
  lw    $t7, ($a3)
  b     .L7F0C3508
   sw    $t5, 0x29c8($t7)
.L7F0C32A8:
  jal   get_controller_buttons_pressed
   sw    $t0, 0x30($sp)
  lui   $a3, %hi(pPlayer)
  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
  beqz  $v0, .L7F0C32F4
   lw    $t0, 0x30($sp)
  lw    $v1, ($a3)
  li    $at, 5
  lw    $v0, 0x29c8($v1)
  beq   $v0, $at, .L7F0C32D8
   li    $at, 6
  bne   $v0, $at, .L7F0C330C
.L7F0C32D8:
   li    $at, 6
  bnel  $v0, $at, .L7F0C32F8
   lb    $a0, 0x1b($sp)
  lw    $t8, 0x29cc($v1)
  li    $at, 1
  bne   $t8, $at, .L7F0C330C
   nop   
.L7F0C32F4:
  lb    $a0, 0x1b($sp)
.L7F0C32F8:
  li    $a1, 16384
  jal   get_controller_buttons_pressed
   sw    $t0, 0x30($sp)
  beqz  $v0, .L7F0C3450
   lw    $t0, 0x30($sp)
.L7F0C330C:
  jal   play_watch_sfx_beep
   sw    $t0, 0x30($sp)
  lui   $t9, %hi(is_gameover_flag) 
  lw    $t9, %lo(is_gameover_flag)($t9)
  lui   $a3, %hi(pPlayer)
  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
  li    $a2, 7
  beqz  $t9, .L7F0C3410
   lw    $t0, 0x30($sp)
  lw    $t1, ($a3)
  move  $v1, $zero
  move  $a0, $zero
  blez  $t0, .L7F0C33F8
   sw    $a2, 0x29c8($t1)
  andi  $a3, $t0, 3
  beqz  $a3, .L7F0C3384
   move  $a1, $a3
  lui   $t3, %hi(ptr_BONDdata_p1) 
  addiu $t3, %lo(ptr_BONDdata_p1) # addiu $t3, $t3, -0x6120
  sll   $t2, $zero, 2
  addu  $v0, $t2, $t3
.L7F0C3360:
  lw    $t4, ($v0)
  addiu $a0, $a0, 1
  lw    $t6, 0x29c8($t4)
  bne   $a2, $t6, .L7F0C3378
   nop   
  addiu $v1, $v1, 1
.L7F0C3378:
  bne   $a1, $a0, .L7F0C3360
   addiu $v0, $v0, 4
  beq   $a0, $t0, .L7F0C33F8
.L7F0C3384:
   lui   $t7, %hi(ptr_BONDdata_p1) 
  addiu $t7, %lo(ptr_BONDdata_p1) # addiu $t7, $t7, -0x6120
  sll   $t5, $a0, 2
  sll   $t8, $t0, 2
  addu  $a1, $t8, $t7
  addu  $v0, $t5, $t7
  lw    $t9, ($v0)
.L7F0C33A0:
  lw    $t1, 0x29c8($t9)
  bnel  $a2, $t1, .L7F0C33B4
   lw    $t2, 4($v0)
  addiu $v1, $v1, 1
  lw    $t2, 4($v0)
.L7F0C33B4:
  lw    $t3, 0x29c8($t2)
  bnel  $a2, $t3, .L7F0C33C8
   lw    $t4, 8($v0)
  addiu $v1, $v1, 1
  lw    $t4, 8($v0)
.L7F0C33C8:
  lw    $t6, 0x29c8($t4)
  bnel  $a2, $t6, .L7F0C33DC
   lw    $t5, 0xc($v0)
  addiu $v1, $v1, 1
  lw    $t5, 0xc($v0)
.L7F0C33DC:
  addiu $v0, $v0, 0x10
  lw    $t8, 0x29c8($t5)
  bne   $a2, $t8, .L7F0C33F0
   nop   
  addiu $v1, $v1, 1
.L7F0C33F0:
  bnel  $v0, $a1, .L7F0C33A0
   lw    $t9, ($v0)
.L7F0C33F8:
  bnel  $v1, $t0, .L7F0C350C
   lw    $v0, 0x2c($sp)
  jal   set_loaded_stage
   li    $a0, 90
  b     .L7F0C350C
   lw    $v0, 0x2c($sp)
.L7F0C3410:
  lw    $t7, ($a3)
  li    $t9, 60
  sw    $zero, 0x29c4($t7)
  lw    $t1, ($a3)
  jal   get_cur_playernum
   sw    $t9, 0x2a00($t1)
  lui   $t2, %hi(who_paused) 
  lw    $t2, %lo(who_paused)($t2)
  lui   $v1, %hi(is_paused)
  addiu $v1, %lo(is_paused) # addiu $v1, $v1, -0x38e8
  bne   $v0, $t2, .L7F0C3508
   move  $a0, $zero
  jal   set_controls_locked_flag
   sw    $zero, ($v1)
  b     .L7F0C350C
   lw    $v0, 0x2c($sp)
.L7F0C3450:
  lb    $a0, 0x1b($sp)
  jal   get_controller_buttons_pressed
   li    $a1, 36864
  lui   $a3, %hi(pPlayer)
  beqz  $v0, .L7F0C34A4
   addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
  lw    $t3, ($a3)
  li    $at, 5
  lw    $t4, 0x29c8($t3)
  bnel  $t4, $at, .L7F0C34A8
   lb    $a0, 0x1b($sp)
  jal   play_watch_sfx_beep
   nop   
  lui   $a3, %hi(pPlayer)
  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
  lw    $t5, ($a3)
  li    $t6, 6
  sw    $t6, 0x29c8($t5)
  lw    $t8, ($a3)
  b     .L7F0C3508
   sw    $zero, 0x29cc($t8)
.L7F0C34A4:
  lb    $a0, 0x1b($sp)
.L7F0C34A8:
  jal   get_controller_buttons_pressed
   li    $a1, 36864
  lui   $a3, %hi(pPlayer)
  beqz  $v0, .L7F0C3508
   addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
  lw    $v1, ($a3)
  li    $at, 6
  lw    $t7, 0x29c8($v1)
  bnel  $t7, $at, .L7F0C350C
   lw    $v0, 0x2c($sp)
  lw    $t9, 0x29cc($v1)
  li    $at, 1
  bnel  $t9, $at, .L7F0C350C
   lw    $v0, 0x2c($sp)
  jal   play_watch_sfx_beep
   nop   
  lui   $a3, %hi(pPlayer)
  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
  lw    $t1, ($a3)
  move  $a0, $zero
  sw    $zero, 0x29c4($t1)
  lw    $t2, ($a3)
  jal   sub_GAME_7F0C2530
   sw    $zero, 0x2a00($t2)
.L7F0C3508:
  lw    $v0, 0x2c($sp)
.L7F0C350C:
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  beqz  $v0, .L7F0C3520
   li    $at, -1
  bne   $v0, $at, .L7F0C352C
.L7F0C3520:
   li    $t3, 1
  b     .L7F0C3590
   sw    $t3, 0x29d0($v1)
.L7F0C352C:
  b     .L7F0C3590
   sw    $zero, 0x29d0($v1)
.L7F0C3534:
  jal   get_controller_buttons_pressed
   li    $a1, 4096
  beql  $v0, $zero, .L7F0C3594
   lw    $ra, 0x14($sp)
  jal   play_watch_sfx_beep
   nop   
  lui   $a3, %hi(pPlayer)
  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
  lw    $t6, ($a3)
  li    $t4, 1
  li    $t5, 3
  sw    $t4, 0x29c4($t6)
  lw    $t8, ($a3)
  li    $t7, 1
  sw    $t5, 0x29c8($t8)
  lw    $t9, ($a3)
  sw    $t7, 0x29d0($t9)
  lw    $v1, ($a3)
  lwc1  $f4, 0xdc($v1)
  swc1  $f4, 0xec($v1)
  lw    $v1, ($a3)
  lwc1  $f6, 0xe0($v1)
  swc1  $f6, 0xf0($v1)
.L7F0C3590:
  lw    $ra, 0x14($sp)
.L7F0C3594:
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   
");

asm(R"
.late_rodata
/*D:8005BC88*/
glabel jpt_MP_overlays_scoring_scenario_0
.word green_text_normal
.word green_text_highlighted
.word red_text_normal
.word red_text_highlighted
.word blue_text_normal
.word blue_text_highlighted

.text
glabel display_text_for_playerdata_on_MP_menu
  addiu $sp, $sp, -0x60
  sw    $s0, 0x34($sp)
  move  $s0, $a1
  sw    $s1, 0x38($sp)
  move  $s1, $a0
  sw    $ra, 0x3c($sp)
  sw    $a2, 0x68($sp)
  lui   $a1, %hi(ascii_MP_watch_menu_percentd)
  addiu $a1, %lo(ascii_MP_watch_menu_percentd) # addiu $a1, $a1, -0x43e0
  move  $a2, $a3
  jal   sprintf
   addiu $a0, $sp, 0x48
  lui   $t6, %hi(ptrFirstFontTableSmall) 
  lw    $t6, %lo(ptrFirstFontTableSmall)($t6)
  lui   $a3, %hi(ptrSecondFontTableSmall)
  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
  addiu $a0, $sp, 0x50
  addiu $a1, $sp, 0x54
  addiu $a2, $sp, 0x48
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t6, 0x10($sp)
  lw    $t7, 0x54($sp)
  lw    $t1, 0x70($sp)
  lw    $t0, 0x68($sp)
  sra   $t8, $t7, 1
  subu  $t9, $s0, $t8
  sltiu $at, $t1, 6
  sw    $t9, 0x5c($sp)
  beqz  $at, .L7F0C38C0
   sw    $t0, 0x58($sp)
  sll   $t1, $t1, 2
  lui   $at, %hi(jpt_MP_overlays_scoring_scenario_0)
  addu  $at, $at, $t1
  lw    $t1, %lo(jpt_MP_overlays_scoring_scenario_0)($at)
  jr    $t1
   nop   
green_text_normal:
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s0, $v0, 0x10
  sra   $t2, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t2
  lui   $t3, %hi(ptrSecondFontTableSmall) 
  lui   $t4, %hi(ptrFirstFontTableSmall) 
  lw    $t4, %lo(ptrFirstFontTableSmall)($t4)
  lw    $t3, %lo(ptrSecondFontTableSmall)($t3)
  lui   $t5, (0x00FF00B0 >> 16) # lui $t5, 0xff
  ori   $t5, (0x00FF00B0 & 0xFFFF) # ori $t5, $t5, 0xb0
  sw    $t5, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0x5c
  addiu $a2, $sp, 0x58
  addiu $a3, $sp, 0x48
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t4, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t3, 0x10($sp)
  b     .L7F0C38C0
   move  $s1, $v0
green_text_highlighted:
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s0, $v0, 0x10
  sra   $t6, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t6
  lui   $t7, %hi(ptrSecondFontTableSmall) 
  lui   $t8, %hi(ptrFirstFontTableSmall) 
  lw    $t8, %lo(ptrFirstFontTableSmall)($t8)
  lw    $t7, %lo(ptrSecondFontTableSmall)($t7)
  lui   $t9, (0xA0FFA0F0 >> 16) # lui $t9, 0xa0ff
  lui   $t0, (0x007000A0 >> 16) # lui $t0, 0x70
  ori   $t0, (0x007000A0 & 0xFFFF) # ori $t0, $t0, 0xa0
  ori   $t9, (0xA0FFA0F0 & 0xFFFF) # ori $t9, $t9, 0xa0f0
  sw    $t9, 0x18($sp)
  sw    $t0, 0x1c($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0x5c
  addiu $a2, $sp, 0x58
  addiu $a3, $sp, 0x48
  sw    $s0, 0x20($sp)
  sw    $v0, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $zero, 0x2c($sp)
  sw    $t8, 0x14($sp)
  jal   jp_text_write_stuff
   sw    $t7, 0x10($sp)
  b     .L7F0C38C0
   move  $s1, $v0
red_text_normal:
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s0, $v0, 0x10
  sra   $t1, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t1
  lui   $t2, %hi(ptrSecondFontTableSmall) 
  lui   $t3, %hi(ptrFirstFontTableSmall) 
  lw    $t3, %lo(ptrFirstFontTableSmall)($t3)
  lw    $t2, %lo(ptrSecondFontTableSmall)($t2)
  lui   $t4, (0xFF4040B0 >> 16) # lui $t4, 0xff40
  ori   $t4, (0xFF4040B0 & 0xFFFF) # ori $t4, $t4, 0x40b0
  sw    $t4, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0x5c
  addiu $a2, $sp, 0x58
  addiu $a3, $sp, 0x48
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t3, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t2, 0x10($sp)
  b     .L7F0C38C0
   move  $s1, $v0
red_text_highlighted:
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s0, $v0, 0x10
  sra   $t5, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t5
  lui   $t6, %hi(ptrSecondFontTableSmall) 
  lui   $t7, %hi(ptrFirstFontTableSmall) 
  lw    $t7, %lo(ptrFirstFontTableSmall)($t7)
  lw    $t6, %lo(ptrSecondFontTableSmall)($t6)
  lui   $t8, (0xFFA0A0F0 >> 16) # lui $t8, 0xffa0
  lui   $t9, (0x700000A0 >> 16) # lui $t9, 0x7000
  ori   $t9, (0x700000A0 & 0xFFFF) # ori $t9, $t9, 0xa0
  ori   $t8, (0xFFA0A0F0 & 0xFFFF) # ori $t8, $t8, 0xa0f0
  sw    $t8, 0x18($sp)
  sw    $t9, 0x1c($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0x5c
  addiu $a2, $sp, 0x58
  addiu $a3, $sp, 0x48
  sw    $s0, 0x20($sp)
  sw    $v0, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $zero, 0x2c($sp)
  sw    $t7, 0x14($sp)
  jal   jp_text_write_stuff
   sw    $t6, 0x10($sp)
  b     .L7F0C38C0
   move  $s1, $v0
blue_text_normal:
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s0, $v0, 0x10
  sra   $t0, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t0
  lui   $t1, %hi(ptrSecondFontTableSmall) 
  lui   $t2, %hi(ptrFirstFontTableSmall) 
  lw    $t2, %lo(ptrFirstFontTableSmall)($t2)
  lw    $t1, %lo(ptrSecondFontTableSmall)($t1)
  lui   $t3, (0x4040FFB0 >> 16) # lui $t3, 0x4040
  ori   $t3, (0x4040FFB0 & 0xFFFF) # ori $t3, $t3, 0xffb0
  sw    $t3, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0x5c
  addiu $a2, $sp, 0x58
  addiu $a3, $sp, 0x48
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t2, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t1, 0x10($sp)
  b     .L7F0C38C0
   move  $s1, $v0
blue_text_highlighted:
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s0, $v0, 0x10
  sra   $t4, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t4
  lui   $t5, %hi(ptrSecondFontTableSmall) 
  lui   $t6, %hi(ptrFirstFontTableSmall) 
  lw    $t6, %lo(ptrFirstFontTableSmall)($t6)
  lw    $t5, %lo(ptrSecondFontTableSmall)($t5)
  lui   $t7, (0xA0A0FFF0 >> 16) # lui $t7, 0xa0a0
  ori   $t7, (0xA0A0FFF0 & 0xFFFF) # ori $t7, $t7, 0xfff0
  li    $t8, 28832
  sw    $t8, 0x1c($sp)
  sw    $t7, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0x5c
  addiu $a2, $sp, 0x58
  addiu $a3, $sp, 0x48
  sw    $s0, 0x20($sp)
  sw    $v0, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $zero, 0x2c($sp)
  sw    $t6, 0x14($sp)
  jal   jp_text_write_stuff
   sw    $t5, 0x10($sp)
  move  $s1, $v0
def_7F0C362C:
.L7F0C38C0:
  lw    $ra, 0x3c($sp)
  move  $v0, $s1
  lw    $s1, 0x38($sp)
  lw    $s0, 0x34($sp)
  jr    $ra
   addiu $sp, $sp, 0x60
");

asm(R"
.late_rodata
/*D:8005BCA0*/
glabel jpt_MP_overlays_scoring
.word num_player_kills
.word num_deaths
.word time_with_flag
.word num_player_kills
.word num_player_kills
.word team_player_kills
.word team_player_kills
.word team_player_kills

.text
glabel get_points_for_mp_player
  sll   $t6, $a0, 3
  lui   $v1, %hi(player1_player_data)
  subu  $t6, $t6, $a0
  addiu $v1, %lo(player1_player_data) # addiu $v1, $v1, -0x6110
  sll   $t6, $t6, 4
  addiu $sp, $sp, -0x38
  addu  $t3, $v1, $t6
  lbu   $a3, 0x69($t3)
  sw    $ra, 0x14($sp)
  sw    $t3, 0x18($sp)
  sw    $a0, 0x38($sp)
  jal   getPlayerCount
   sw    $a3, 0x34($sp)
  sw    $zero, 0x24($sp)
  jal   get_scenario
   sw    $v0, 0x30($sp)
  lui   $v1, %hi(player1_player_data)
  sltiu $at, $v0, 8
  addiu $v1, %lo(player1_player_data) # addiu $v1, $v1, -0x6110
  lw    $a0, 0x24($sp)
  lw    $a1, 0x38($sp)
  lw    $a3, 0x34($sp)
  lw    $t2, 0x30($sp)
  beqz  $at, .L7F0C3C80
   lw    $t3, 0x18($sp)
  sll   $t7, $v0, 2
  lui   $at, %hi(jpt_MP_overlays_scoring)
  addu  $at, $at, $t7
  lw    $t7, %lo(jpt_MP_overlays_scoring)($at)
  jr    $t7
   nop   
num_player_kills:
  blez  $t2, .L7F0C3AF8
   move  $t1, $zero
  andi  $t0, $t2, 3
  beqz  $t0, .L7F0C39C0
   move  $v0, $t0
.L7F0C3968:
  beq   $t1, $a1, .L7F0C3994
   sll   $t8, $t1, 3
  sll   $t8, $a1, 3
  subu  $t8, $t8, $a1
  sll   $t8, $t8, 4
  addu  $t9, $v1, $t8
  sll   $t5, $t1, 2
  addu  $t6, $t9, $t5
  lw    $t7, 0x24($t6)
  b     .L7F0C39B0
   addu  $a0, $a0, $t7
.L7F0C3994:
  subu  $t8, $t8, $t1
  sll   $t8, $t8, 4
  addu  $t9, $v1, $t8
  sll   $t5, $a1, 2
  addu  $t6, $t9, $t5
  lw    $t7, 0x24($t6)
  subu  $a0, $a0, $t7
.L7F0C39B0:
  addiu $t1, $t1, 1
  bne   $v0, $t1, .L7F0C3968
   nop   
  beq   $t1, $t2, .L7F0C3AF8
.L7F0C39C0:
   addiu $v0, $a1, -1
  addiu $a2, $a1, -2
  addiu $a3, $a1, -3
.L7F0C39CC:
  beq   $t1, $a1, .L7F0C39F8
   sll   $t8, $t1, 3
  sll   $t8, $a1, 3
  subu  $t8, $t8, $a1
  sll   $t8, $t8, 4
  addu  $t9, $v1, $t8
  sll   $t5, $t1, 2
  addu  $t6, $t9, $t5
  lw    $t7, 0x24($t6)
  b     .L7F0C3A14
   addu  $a0, $a0, $t7
.L7F0C39F8:
  subu  $t8, $t8, $t1
  sll   $t8, $t8, 4
  addu  $t9, $v1, $t8
  sll   $t5, $a1, 2
  addu  $t6, $t9, $t5
  lw    $t7, 0x24($t6)
  subu  $a0, $a0, $t7
.L7F0C3A14:
  beq   $t1, $v0, .L7F0C3A40
   sll   $t8, $t1, 3
  sll   $t8, $a1, 3
  subu  $t8, $t8, $a1
  sll   $t8, $t8, 4
  addu  $t9, $v1, $t8
  sll   $t5, $t1, 2
  addu  $t6, $t9, $t5
  lw    $t7, 0x28($t6)
  b     .L7F0C3A5C
   addu  $a0, $a0, $t7
.L7F0C3A40:
  subu  $t8, $t8, $t1
  sll   $t8, $t8, 4
  addu  $t9, $v1, $t8
  sll   $t5, $a1, 2
  addu  $t6, $t9, $t5
  lw    $t7, 0x94($t6)
  subu  $a0, $a0, $t7
.L7F0C3A5C:
  beq   $t1, $a2, .L7F0C3A88
   sll   $t8, $t1, 3
  sll   $t8, $a1, 3
  subu  $t8, $t8, $a1
  sll   $t8, $t8, 4
  addu  $t9, $v1, $t8
  sll   $t5, $t1, 2
  addu  $t6, $t9, $t5
  lw    $t7, 0x2c($t6)
  b     .L7F0C3AA4
   addu  $a0, $a0, $t7
.L7F0C3A88:
  subu  $t8, $t8, $t1
  sll   $t8, $t8, 4
  addu  $t9, $v1, $t8
  sll   $t5, $a1, 2
  addu  $t6, $t9, $t5
  lw    $t7, 0x104($t6)
  subu  $a0, $a0, $t7
.L7F0C3AA4:
  beq   $t1, $a3, .L7F0C3AD0
   sll   $t8, $t1, 3
  sll   $t8, $a1, 3
  subu  $t8, $t8, $a1
  sll   $t8, $t8, 4
  addu  $t9, $v1, $t8
  sll   $t5, $t1, 2
  addu  $t6, $t9, $t5
  lw    $t7, 0x30($t6)
  b     .L7F0C3AEC
   addu  $a0, $a0, $t7
.L7F0C3AD0:
  subu  $t8, $t8, $t1
  sll   $t8, $t8, 4
  addu  $t9, $v1, $t8
  sll   $t5, $a1, 2
  addu  $t6, $t9, $t5
  lw    $t7, 0x174($t6)
  subu  $a0, $a0, $t7
.L7F0C3AEC:
  addiu $t1, $t1, 4
  bne   $t1, $t2, .L7F0C39CC
   nop   
.L7F0C3AF8:
  lw    $t8, 0x20($t3)
  addiu $t9, $t2, -2
  multu $t8, $t9
  mflo  $t5
  addu  $a0, $a0, $t5
  b     .L7F0C3C84
   lw    $ra, 0x14($sp)
num_deaths:
  lbu   $t6, 0x68($t3)
  li    $t7, 4
  b     .L7F0C3C80
   subu  $a0, $t7, $t6
time_with_flag:
  b     .L7F0C3C80
   lw    $a0, 0x60($t3)
team_player_kills:
  blez  $t2, .L7F0C3C80
   move  $t1, $zero
  lui   $t4, %hi(player1_player_data) 
  addiu $t4, %lo(player1_player_data) # addiu $t4, $t4, -0x6110
.L7F0C3B3C:
  lbu   $t8, 0x69($t4)
  bnel  $a3, $t8, .L7F0C3C78
   addiu $t1, $t1, 1
  blez  $t2, .L7F0C3C74
   move  $a1, $zero
  sll   $t9, $t1, 3
  subu  $t9, $t9, $t1
  lui   $t5, %hi(player1_player_data) 
  addiu $t5, %lo(player1_player_data) # addiu $t5, $t5, -0x6110
  sll   $t9, $t9, 4
  andi  $t0, $t2, 3
  beqz  $t0, .L7F0C3BC0
   addu  $t3, $t9, $t5
  sll   $t7, $zero, 3
  subu  $t7, $t7, $zero
  sll   $t7, $t7, 4
  sll   $t6, $zero, 2
  addu  $v0, $t3, $t6
  addu  $v1, $t7, $t5
  move  $a2, $t0
.L7F0C3B8C:
  lbu   $t8, 0x69($v1)
  addiu $a1, $a1, 1
  addiu $v1, $v1, 0x70
  beql  $a3, $t8, .L7F0C3BB0
   lw    $t7, 0x24($v0)
  lw    $t9, 0x24($v0)
  b     .L7F0C3BB4
   addu  $a0, $a0, $t9
  lw    $t7, 0x24($v0)
.L7F0C3BB0:
  subu  $a0, $a0, $t7
.L7F0C3BB4:
  bne   $a2, $a1, .L7F0C3B8C
   addiu $v0, $v0, 4
  beq   $a1, $t2, .L7F0C3C74
.L7F0C3BC0:
   sll   $t5, $a1, 3
  subu  $t5, $t5, $a1
  lui   $t6, %hi(player1_player_data) 
  addiu $t6, %lo(player1_player_data) # addiu $t6, $t6, -0x6110
  sll   $t5, $t5, 4
  sll   $a2, $a1, 2
  addu  $v0, $t3, $a2
  addu  $v1, $t5, $t6
  sll   $t0, $t2, 2
.L7F0C3BE4:
  lbu   $t8, 0x69($v1)
  addiu $a2, $a2, 0x10
  beql  $a3, $t8, .L7F0C3C04
   lw    $t7, 0x24($v0)
  lw    $t9, 0x24($v0)
  b     .L7F0C3C08
   addu  $a0, $a0, $t9
  lw    $t7, 0x24($v0)
.L7F0C3C04:
  subu  $a0, $a0, $t7
.L7F0C3C08:
  lbu   $t5, 0xd9($v1)
  beql  $a3, $t5, .L7F0C3C24
   lw    $t8, 0x28($v0)
  lw    $t6, 0x28($v0)
  b     .L7F0C3C28
   addu  $a0, $a0, $t6
  lw    $t8, 0x28($v0)
.L7F0C3C24:
  subu  $a0, $a0, $t8
.L7F0C3C28:
  lbu   $t9, 0x149($v1)
  beql  $a3, $t9, .L7F0C3C44
   lw    $t5, 0x2c($v0)
  lw    $t7, 0x2c($v0)
  b     .L7F0C3C48
   addu  $a0, $a0, $t7
  lw    $t5, 0x2c($v0)
.L7F0C3C44:
  subu  $a0, $a0, $t5
.L7F0C3C48:
  lbu   $t6, 0x1b9($v1)
  addiu $v1, $v1, 0x1c0
  beql  $a3, $t6, .L7F0C3C68
   lw    $t9, 0x30($v0)
  lw    $t8, 0x30($v0)
  b     .L7F0C3C6C
   addu  $a0, $a0, $t8
  lw    $t9, 0x30($v0)
.L7F0C3C68:
  subu  $a0, $a0, $t9
.L7F0C3C6C:
  bne   $a2, $t0, .L7F0C3BE4
   addiu $v0, $v0, 0x10
.L7F0C3C74:
  addiu $t1, $t1, 1
.L7F0C3C78:
  bne   $t1, $t2, .L7F0C3B3C
   addiu $t4, $t4, 0x70
def_7F0C394C:
.L7F0C3C80:
  lw    $ra, 0x14($sp)
.L7F0C3C84:
  addiu $sp, $sp, 0x38
  move  $v0, $a0
  jr    $ra
   nop   
");

asm(R"
glabel write_playerrank_to_buffer
  addiu $sp, $sp, -0x80
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a0, 0x80($sp)
  jal   get_scenario
   sw    $a1, 0x84($sp)
  jal   getPlayerCount
   sw    $v0, 0x7c($sp)
  move  $t3, $v0
  blez  $v0, .L7F0C3D08
   move  $s0, $zero
  addiu $v1, $sp, 0x68
  addiu $a1, $sp, 0x58
.L7F0C3CC8:
  move  $a0, $s0
  sw    $v1, 0x38($sp)
  sw    $a1, 0x3c($sp)
  jal   get_points_for_mp_player
   sw    $t3, 0x78($sp)
  lw    $a1, 0x3c($sp)
  lw    $t3, 0x78($sp)
  lw    $v1, 0x38($sp)
  sw    $s0, ($a1)
  addiu $s0, $s0, 1
  slt   $at, $s0, $t3
  addiu $a1, $a1, 4
  addiu $v1, $v1, 4
  bnez  $at, .L7F0C3CC8
   sw    $v0, -4($v1)
  move  $s0, $zero
.L7F0C3D08:
  blez  $t3, .L7F0C3E08
   move  $t2, $zero
  addiu $t4, $t3, -1
  addiu $t0, $sp, 0x58
  lw    $a1, 0x68($sp)
  lw    $a0, 0x6c($sp)
.L7F0C3D20:
  blez  $t4, .L7F0C3DF4
   addiu $t2, $t2, 1
  addiu $v0, $t3, -1
  andi  $t6, $v0, 1
  beqz  $t6, .L7F0C3D60
   slt   $at, $a1, $a0
  beqz  $at, .L7F0C3D5C
   li    $s0, 1
  move  $v0, $a0
  move  $a0, $a1
  move  $a1, $v0
  lw    $v0, 0x5c($sp)
  lw    $t7, 0x58($sp)
  sw    $v0, 0x58($sp)
  sw    $t7, 0x5c($sp)
.L7F0C3D5C:
  beq   $s0, $t4, .L7F0C3DF0
.L7F0C3D60:
   addiu $t8, $sp, 0x68
  sll   $a3, $s0, 2
  sll   $t9, $t4, 2
  addu  $t1, $t9, $t8
  addu  $v1, $a3, $t8
  sw    $a0, 0x6c($sp)
  sw    $a1, 0x68($sp)
.L7F0C3D7C:
  lw    $a2, ($v1)
  lw    $a0, 4($v1)
  addu  $a1, $t0, $a3
  slt   $at, $a2, $a0
  beql  $at, $zero, .L7F0C3DB4
   lw    $a2, 8($v1)
  lw    $v0, 4($a1)
  lw    $t5, ($a1)
  sw    $a0, ($v1)
  sw    $a2, 4($v1)
  move  $a0, $a2
  sw    $v0, ($a1)
  sw    $t5, 4($a1)
  lw    $a2, 8($v1)
.L7F0C3DB4:
  addu  $a1, $t0, $a3
  slt   $at, $a0, $a2
  beql  $at, $zero, .L7F0C3DE0
   addiu $v1, $v1, 8
  lw    $v0, 8($a1)
  lw    $t6, 4($a1)
  sw    $a0, 8($v1)
  sw    $a2, 4($v1)
  sw    $v0, 4($a1)
  sw    $t6, 8($a1)
  addiu $v1, $v1, 8
.L7F0C3DE0:
  lw    $a0, 0x6c($sp)
  lw    $a1, 0x68($sp)
  bne   $v1, $t1, .L7F0C3D7C
   addiu $a3, $a3, 8
.L7F0C3DF0:
  move  $s0, $zero
.L7F0C3DF4:
  bne   $t2, $t3, .L7F0C3D20
   nop   
  sw    $a1, 0x68($sp)
  sw    $a0, 0x6c($sp)
  move  $t2, $zero
.L7F0C3E08:
  blez  $t3, .L7F0C3E2C
   addiu $a1, $sp, 0x58
  lw    $v0, 0x84($sp)
.L7F0C3E14:
  lw    $t7, ($a1)
  beq   $v0, $t7, .L7F0C3E2C
   nop   
  addiu $s0, $s0, 1
  bne   $s0, $t3, .L7F0C3E14
   addiu $a1, $a1, 4
.L7F0C3E2C:
  bltz  $s0, .L7F0C3E5C
   sll   $t9, $s0, 2
  addiu $v0, $sp, 0x68
  addu  $t5, $t9, $v0
  lw    $a2, ($t5)
.L7F0C3E40:
  lw    $t6, ($v0)
  addiu $t7, $s0, 1
  beq   $t6, $a2, .L7F0C3E5C
   nop   
  addiu $t2, $t2, 1
  bne   $t7, $t2, .L7F0C3E40
   addiu $v0, $v0, 4
.L7F0C3E5C:
  beqz  $t2, .L7F0C3E88
   li    $at, 1
  beq   $t2, $at, .L7F0C3EA4
   li    $at, 2
  beq   $t2, $at, .L7F0C3EC0
   lw    $v0, 0x7c($sp)
  li    $at, 3
  beq   $t2, $at, .L7F0C3F0C
   lw    $t9, 0x7c($sp)
  b     .L7F0C3F4C
   lw    $ra, 0x1c($sp)
.L7F0C3E88:
  jal   get_textptr_for_textID
   li    $a0, 40977
  lw    $a0, 0x80($sp)
  jal   sprintf
   move  $a1, $v0
  b     .L7F0C3F4C
   lw    $ra, 0x1c($sp)
.L7F0C3EA4:
  jal   get_textptr_for_textID
   li    $a0, 40978
  lw    $a0, 0x80($sp)
  jal   sprintf
   move  $a1, $v0
  b     .L7F0C3F4C
   lw    $ra, 0x1c($sp)
.L7F0C3EC0:
  li    $at, 5
  beq   $v0, $at, .L7F0C3EF0
   li    $at, 7
  beq   $v0, $at, .L7F0C3EF0
   nop   
  jal   get_textptr_for_textID
   li    $a0, 40979
  lw    $a0, 0x80($sp)
  jal   sprintf
   move  $a1, $v0
  b     .L7F0C3F4C
   lw    $ra, 0x1c($sp)
.L7F0C3EF0:
  jal   get_textptr_for_textID
   li    $a0, 40978
  lw    $a0, 0x80($sp)
  jal   sprintf
   move  $a1, $v0
  b     .L7F0C3F4C
   lw    $ra, 0x1c($sp)
.L7F0C3F0C:
  li    $at, 6
  beq   $t9, $at, .L7F0C3F34
   nop   
  jal   get_textptr_for_textID
   li    $a0, 40980
  lw    $a0, 0x80($sp)
  jal   sprintf
   move  $a1, $v0
  b     .L7F0C3F4C
   lw    $ra, 0x1c($sp)
.L7F0C3F34:
  jal   get_textptr_for_textID
   li    $a0, 40978
  lw    $a0, 0x80($sp)
  jal   sprintf
   move  $a1, $v0
  lw    $ra, 0x1c($sp)
.L7F0C3F4C:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x80
  jr    $ra
   nop   
");

asm(R"
.late_rodata
/*D:8005BCC0*/
glabel jpt_MP_overlays_scoring_scenario_1
.word not_yolt
.word yolt
.word not_yolt
.word not_yolt
.word not_yolt
.word not_yolt
.word not_yolt
.word not_yolt
.text
glabel true_if_displaying_rank_in_mp
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   get_scenario
   sw    $a0, 0x18($sp)
  sltiu $at, $v0, 8
  beqz  $at, .L7F0C3FB4
   sll   $t6, $v0, 2
  lui   $at, %hi(jpt_MP_overlays_scoring_scenario_1)
  addu  $at, $at, $t6
  lw    $t6, %lo(jpt_MP_overlays_scoring_scenario_1)($at)
  jr    $t6
   nop   
not_yolt:
  b     .L7F0C3FBC
   li    $v0, 1
yolt:
  lw    $t7, 0x18($sp)
  li    $v1, 1
  beqz  $t7, .L7F0C3FAC
   nop   
  b     .L7F0C3FBC
   move  $v0, $zero
.L7F0C3FAC:
  b     .L7F0C3FBC
   move  $v0, $v1
def_7F0C3F84:
.L7F0C3FB4:
  b     .L7F0C3FB4
   nop   
.L7F0C3FBC:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
.late_rodata
/*D:8005BCE0*/
glabel jpt_MP_overlays_scoring_scenario_2
.word not_yolt_tld
.word yolt_tld
.word yolt_tld
.word not_yolt_tld
.word not_yolt_tld
.word not_yolt_tld
.word not_yolt_tld
/*.word not_yolt_tld*/
.text
glabel true_if_displaying_score_in_mp
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   get_scenario
   sw    $a0, 0x18($sp)
  sltiu $at, $v0, 8
  beqz  $at, .L7F0C400C
   sll   $t6, $v0, 2
  lui   $at, %hi(jpt_MP_overlays_scoring_scenario_2)
  addu  $at, $at, $t6
  lw    $t6, %lo(jpt_MP_overlays_scoring_scenario_2)($at)
  jr    $t6
   nop   
not_yolt_tld:
  b     .L7F0C4014
   li    $v0, 1
yolt_tld:
  b     .L7F0C4014
   move  $v0, $zero
def_7F0C3FF4:
.L7F0C400C:
  b     .L7F0C400C
   nop   
.L7F0C4014:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

#ifdef VERSION_US
asm(R"
.late_rodata
/*jtbl hacks*/
.word not_yolt_tld

/*D:8005BD00*/
glabel jpt_MP_menu_window_text
.word text_play
.word text_play
.word text_play
.word text_play
.word text_pause_unpause
.word text_exit
.word text_exit
.word text_blank

.text
glabel mp_watch_menu_display
  addiu $sp, $sp, -0xd8
  sw    $ra, 0x3c($sp)
  sw    $s1, 0x38($sp)
  move  $s1, $a0
  jal   get_cur_playernum
   sw    $s0, 0x34($sp)
  jal   getPlayerCount
   sw    $v0, 0xd4($sp)
  li    $at, 1
  move  $t0, $v0
  bne   $v0, $at, .L7F0C405C
   move  $s0, $zero
  b     .L7F0C6034
   move  $v0, $s1
.L7F0C405C:
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  move  $a0, $s1
  lw    $t6, 0x29c4($v1)
  beql  $t6, $zero, .L7F0C5E24
   lw    $t6, 0xd8($v1)
  jal   microcode_constructor
   sw    $t0, 0xd0($sp)
  lw    $t7, 0xd0($sp)
  li    $at, 2
  move  $s1, $v0
  bne   $t7, $at, .L7F0C409C
   lui   $t9, %hi(pPlayer) 
  li    $t8, 80
  b     .L7F0C40A0
   sw    $t8, 0xa8($sp)
.L7F0C409C:
  sw    $zero, 0xa8($sp)
.L7F0C40A0:
  lw    $t9, %lo(pPlayer)($t9)
  lw    $t1, 0x29c8($t9)
  sltiu $at, $t1, 8
  beqz  $at, .L7F0C4190
   sll   $t1, $t1, 2
  lui   $at, %hi(jpt_MP_menu_window_text)
  addu  $at, $at, $t1
  lw    $t1, %lo(jpt_MP_menu_window_text)($at)
  jr    $t1
   nop   
text_play:
  lui   $t2, %hi(is_gameover_flag) 
  lw    $t2, %lo(is_gameover_flag)($t2)
  lui   $t3, %hi(time_trigger_alt_gameover_msg) 
  bnez  $t2, .L7F0C40EC
   nop   
  jal   get_textptr_for_textID
   li    $a0, 40981
  b     .L7F0C4190
   sw    $v0, 0xa4($sp)
.L7F0C40EC:
  lw    $t3, %lo(time_trigger_alt_gameover_msg)($t3)
  beqz  $t3, .L7F0C4108
   nop   
  jal   get_textptr_for_textID
   li    $a0, 40982
  b     .L7F0C4190
   sw    $v0, 0xa4($sp)
.L7F0C4108:
  jal   get_textptr_for_textID
   li    $a0, 40983
  b     .L7F0C4190
   sw    $v0, 0xa4($sp)
text_blank:
  lui   $t4, %hi(ascii_MP_watch_menu_BLANK) 
  addiu $t4, %lo(ascii_MP_watch_menu_BLANK) # addiu $t4, $t4, -0x43dc
  b     .L7F0C4190
   sw    $t4, 0xa4($sp)
text_pause_unpause:
  lui   $t5, %hi(is_paused) 
  lw    $t5, %lo(is_paused)($t5)
  beqz  $t5, .L7F0C4160
   nop   
  jal   get_textptr_for_textID
   li    $a0, 40984
  jal   get_cur_playernum
   sw    $v0, 0xa4($sp)
  lui   $t6, %hi(who_paused) 
  lw    $t6, %lo(who_paused)($t6)
  bne   $v0, $t6, .L7F0C4190
   nop   
  b     .L7F0C4190
   li    $s0, 1
.L7F0C4160:
  jal   get_textptr_for_textID
   li    $a0, 40985
  b     .L7F0C4190
   sw    $v0, 0xa4($sp)
text_exit:
  jal   get_textptr_for_textID
   li    $a0, 40986
  jal   get_video2_settings_ulx
   sw    $v0, 0xa4($sp)
  lw    $t7, 0xa8($sp)
  addu  $a0, $v0, $t7
  addiu $a0, $a0, 0x41
  sw    $a0, 0xcc($sp)
def_7F0C40C0:
.L7F0C4190:
  lui   $t8, %hi(ptrFirstFontTableSmall) 
  lw    $t8, %lo(ptrFirstFontTableSmall)($t8)
  lui   $a3, %hi(ptrSecondFontTableSmall)
  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
  addiu $a0, $sp, 0xbc
  addiu $a1, $sp, 0xc0
  lw    $a2, 0xa4($sp)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t8, 0x10($sp)
  jal   get_video2_settings_ulx
   nop   
  lw    $t9, 0xa8($sp)
  lw    $t2, 0xc0($sp)
  addu  $t1, $v0, $t9
  sra   $t3, $t2, 1
  subu  $a0, $t1, $t3
  addiu $a0, $a0, 0x50
  jal   get_video2_settings_uly
   sw    $a0, 0xcc($sp)
  lw    $t4, 0xbc($sp)
  sra   $t5, $t4, 1
  subu  $t6, $v0, $t5
  addiu $t7, $t6, 0x16
  beqz  $s0, .L7F0C426C
   sw    $t7, 0xc8($sp)
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s0, $v0, 0x10
  sra   $t8, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t8
  lui   $t9, %hi(ptrSecondFontTableSmall) 
  lui   $t2, %hi(ptrFirstFontTableSmall) 
  lw    $t2, %lo(ptrFirstFontTableSmall)($t2)
  lw    $t9, %lo(ptrSecondFontTableSmall)($t9)
  lui   $t1, (0xA0FFA0F0 >> 16) # lui $t1, 0xa0ff
  lui   $t3, (0x007000A0 >> 16) # lui $t3, 0x70
  ori   $t3, (0x007000A0 & 0xFFFF) # ori $t3, $t3, 0xa0
  ori   $t1, (0xA0FFA0F0 & 0xFFFF) # ori $t1, $t1, 0xa0f0
  sw    $t1, 0x18($sp)
  sw    $t3, 0x1c($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xcc
  addiu $a2, $sp, 0xc8
  lw    $a3, 0xa4($sp)
  sw    $s0, 0x20($sp)
  sw    $v0, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $zero, 0x2c($sp)
  sw    $t2, 0x14($sp)
  jal   jp_text_write_stuff
   sw    $t9, 0x10($sp)
  b     .L7F0C42D0
   move  $s1, $v0
.L7F0C426C:
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s0, $v0, 0x10
  sra   $t4, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t4
  lui   $t5, %hi(ptrSecondFontTableSmall) 
  lui   $t6, %hi(ptrFirstFontTableSmall) 
  lw    $t6, %lo(ptrFirstFontTableSmall)($t6)
  lw    $t5, %lo(ptrSecondFontTableSmall)($t5)
  lui   $t7, (0x00FF00B0 >> 16) # lui $t7, 0xff
  ori   $t7, (0x00FF00B0 & 0xFFFF) # ori $t7, $t7, 0xb0
  sw    $t7, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xcc
  addiu $a2, $sp, 0xc8
  lw    $a3, 0xa4($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t6, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t5, 0x10($sp)
  move  $s1, $v0
.L7F0C42D0:
  jal   check_can_advance_left_on_mpmenu
   nop   
  beqz  $v0, .L7F0C4434
   nop   
  jal   get_video2_settings_ulx
   nop   
  lui   $v1, %hi(is_gameover_flag)
  lw    $v1, %lo(is_gameover_flag)($v1)
  sll   $t9, $v0, 0x10
  li    $t8, 10
  beql  $v1, $zero, .L7F0C430C
   sw    $zero, 0x50($sp)
  b     .L7F0C430C
   sw    $t8, 0x50($sp)
  sw    $zero, 0x50($sp)
.L7F0C430C:
  lw    $t1, 0xa8($sp)
  lw    $t4, 0x50($sp)
  sra   $t2, $t9, 0x10
  addu  $t3, $t2, $t1
  subu  $a0, $t3, $t4
  addiu $a0, $a0, 0x28
  beqz  $v1, .L7F0C4334
   sw    $a0, 0xcc($sp)
  addiu $a0, $a0, -8
  sw    $a0, 0xcc($sp)
.L7F0C4334:
  jal   get_video2_settings_uly
   nop   
  lui   $t6, %hi(dword_CODE_bss_8008C708) 
  lw    $t6, %lo(dword_CODE_bss_8008C708)($t6)
  addiu $t5, $v0, 0x16
  sw    $t5, 0xc8($sp)
  bnez  $t6, .L7F0C43C0
   nop   
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s0, $v0, 0x10
  sra   $t7, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t7
  lui   $t8, %hi(ptrSecondFontTableSmall) 
  lui   $t9, %hi(ptrFirstFontTableSmall) 
  lw    $t9, %lo(ptrFirstFontTableSmall)($t9)
  lw    $t8, %lo(ptrSecondFontTableSmall)($t8)
  lui   $t2, (0x00FF00B0 >> 16) # lui $t2, 0xff
  ori   $t2, (0x00FF00B0 & 0xFFFF) # ori $t2, $t2, 0xb0
  lui   $a3, %hi(ascii_MP_watch_menu_left_chevron)
  addiu $a3, %lo(ascii_MP_watch_menu_left_chevron) # addiu $a3, $a3, -0x43d8
  sw    $t2, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xcc
  addiu $a2, $sp, 0xc8
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t9, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t8, 0x10($sp)
  b     .L7F0C4434
   move  $s1, $v0
.L7F0C43C0:
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s0, $v0, 0x10
  sra   $t1, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t1
  lui   $t3, %hi(ptrSecondFontTableSmall) 
  lui   $t4, %hi(ptrFirstFontTableSmall) 
  lw    $t4, %lo(ptrFirstFontTableSmall)($t4)
  lw    $t3, %lo(ptrSecondFontTableSmall)($t3)
  lui   $t5, (0xA0FFA0F0 >> 16) # lui $t5, 0xa0ff
  lui   $t6, (0x007000A0 >> 16) # lui $t6, 0x70
  ori   $t6, (0x007000A0 & 0xFFFF) # ori $t6, $t6, 0xa0
  ori   $t5, (0xA0FFA0F0 & 0xFFFF) # ori $t5, $t5, 0xa0f0
  lui   $a3, %hi(ascii_MP_watch_menu_left_chevron)
  addiu $a3, %lo(ascii_MP_watch_menu_left_chevron) # addiu $a3, $a3, -0x43d8
  sw    $t5, 0x18($sp)
  sw    $t6, 0x1c($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xcc
  addiu $a2, $sp, 0xc8
  sw    $s0, 0x20($sp)
  sw    $v0, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $zero, 0x2c($sp)
  sw    $t4, 0x14($sp)
  jal   jp_text_write_stuff
   sw    $t3, 0x10($sp)
  move  $s1, $v0
.L7F0C4434:
  jal   check_can_advance_right_on_mpmenu
   nop   
  beqz  $v0, .L7F0C4598
   nop   
  jal   get_video2_settings_ulx
   nop   
  lui   $v1, %hi(is_gameover_flag)
  lw    $v1, %lo(is_gameover_flag)($v1)
  sll   $t9, $v0, 0x10
  li    $t7, 10
  beql  $v1, $zero, .L7F0C4470
   sw    $zero, 0x50($sp)
  b     .L7F0C4470
   sw    $t7, 0x50($sp)
  sw    $zero, 0x50($sp)
.L7F0C4470:
  lw    $t8, 0x50($sp)
  lw    $t3, 0xa8($sp)
  sra   $t2, $t9, 0x10
  addu  $t1, $t8, $t2
  addu  $a0, $t1, $t3
  addiu $a0, $a0, 0x70
  beqz  $v1, .L7F0C4498
   sw    $a0, 0xcc($sp)
  addiu $a0, $a0, 8
  sw    $a0, 0xcc($sp)
.L7F0C4498:
  jal   get_video2_settings_uly
   nop   
  lui   $t5, %hi(dword_CODE_bss_8008C708) 
  lw    $t5, %lo(dword_CODE_bss_8008C708)($t5)
  addiu $t4, $v0, 0x16
  sw    $t4, 0xc8($sp)
  bnez  $t5, .L7F0C4524
   nop   
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s0, $v0, 0x10
  sra   $t6, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t6
  lui   $t7, %hi(ptrSecondFontTableSmall) 
  lui   $t9, %hi(ptrFirstFontTableSmall) 
  lw    $t9, %lo(ptrFirstFontTableSmall)($t9)
  lw    $t7, %lo(ptrSecondFontTableSmall)($t7)
  lui   $t8, (0x00FF00B0 >> 16) # lui $t8, 0xff
  ori   $t8, (0x00FF00B0 & 0xFFFF) # ori $t8, $t8, 0xb0
  lui   $a3, %hi(ascii_MP_watch_menu_right_chevron)
  addiu $a3, %lo(ascii_MP_watch_menu_right_chevron) # addiu $a3, $a3, -0x43d4
  sw    $t8, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xcc
  addiu $a2, $sp, 0xc8
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t9, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t7, 0x10($sp)
  b     .L7F0C4598
   move  $s1, $v0
.L7F0C4524:
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s0, $v0, 0x10
  sra   $t2, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t2
  lui   $t1, %hi(ptrSecondFontTableSmall) 
  lui   $t3, %hi(ptrFirstFontTableSmall) 
  lw    $t3, %lo(ptrFirstFontTableSmall)($t3)
  lw    $t1, %lo(ptrSecondFontTableSmall)($t1)
  lui   $t4, (0xA0FFA0F0 >> 16) # lui $t4, 0xa0ff
  lui   $t5, (0x007000A0 >> 16) # lui $t5, 0x70
  ori   $t5, (0x007000A0 & 0xFFFF) # ori $t5, $t5, 0xa0
  ori   $t4, (0xA0FFA0F0 & 0xFFFF) # ori $t4, $t4, 0xa0f0
  lui   $a3, %hi(ascii_MP_watch_menu_right_chevron)
  addiu $a3, %lo(ascii_MP_watch_menu_right_chevron) # addiu $a3, $a3, -0x43d4
  sw    $t4, 0x18($sp)
  sw    $t5, 0x1c($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xcc
  addiu $a2, $sp, 0xc8
  sw    $s0, 0x20($sp)
  sw    $v0, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $zero, 0x2c($sp)
  sw    $t3, 0x14($sp)
  jal   jp_text_write_stuff
   sw    $t1, 0x10($sp)
  move  $s1, $v0
.L7F0C4598:
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  li    $at, 3
  lw    $t6, 0xd0($sp)
  lw    $v0, 0x29c8($v1)
  beq   $v0, $at, .L7F0C45BC
   li    $at, 4
  bnel  $v0, $at, .L7F0C4C60
   li    $at, 2
.L7F0C45BC:
  blez  $t6, .L7F0C45F4
   move  $a0, $zero
  addiu $v1, $sp, 0x94
  sw    $v1, 0x44($sp)
.L7F0C45CC:
  jal   get_points_for_mp_player
   sw    $a0, 0x90($sp)
  lw    $v1, 0x44($sp)
  lw    $a0, 0x90($sp)
  sw    $v0, ($v1)
  lw    $t7, 0xd0($sp)
  addiu $a0, $a0, 1
  addiu $v1, $v1, 4
  bnel  $a0, $t7, .L7F0C45CC
   sw    $v1, 0x44($sp)
.L7F0C45F4:
  lui   $a0, %hi(is_gameover_flag)
  lw    $a0, %lo(is_gameover_flag)($a0)
  sltiu $t9, $a0, 1
  beqz  $t9, .L7F0C4618
   move  $a0, $t9
  lui   $a0, %hi(stop_play_flag)
  lw    $a0, %lo(stop_play_flag)($a0)
  sltiu $t8, $a0, 1
  move  $a0, $t8
.L7F0C4618:
  jal   true_if_displaying_rank_in_mp
   nop   
  beqz  $v0, .L7F0C46F4
   addiu $a0, $sp, 0xac
  jal   write_playerrank_to_buffer
   lw    $a1, 0xd4($sp)
  lui   $t2, %hi(ptrFirstFontTableSmall) 
  lw    $t2, %lo(ptrFirstFontTableSmall)($t2)
  lui   $a3, %hi(ptrSecondFontTableSmall)
  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
  addiu $a0, $sp, 0xbc
  addiu $a1, $sp, 0xc0
  addiu $a2, $sp, 0xac
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t2, 0x10($sp)
  jal   get_video2_settings_ulx
   nop   
  lw    $t1, 0xa8($sp)
  lw    $t4, 0xc0($sp)
  addu  $t3, $v0, $t1
  sra   $t5, $t4, 1
  subu  $a0, $t3, $t5
  addiu $a0, $a0, 0x50
  jal   get_video2_settings_uly
   sw    $a0, 0xcc($sp)
  lw    $t6, 0xbc($sp)
  sra   $t7, $t6, 1
  subu  $t9, $v0, $t7
  addiu $t8, $t9, 0x25
  jal   get_video2_settings_txtClipW
   sw    $t8, 0xc8($sp)
  sll   $s0, $v0, 0x10
  sra   $t2, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t2
  lui   $t1, %hi(ptrSecondFontTableSmall) 
  lui   $t4, %hi(ptrFirstFontTableSmall) 
  lw    $t4, %lo(ptrFirstFontTableSmall)($t4)
  lw    $t1, %lo(ptrSecondFontTableSmall)($t1)
  lui   $t3, (0x00FF00B0 >> 16) # lui $t3, 0xff
  ori   $t3, (0x00FF00B0 & 0xFFFF) # ori $t3, $t3, 0xb0
  sw    $t3, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xcc
  addiu $a2, $sp, 0xc8
  addiu $a3, $sp, 0xac
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t4, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t1, 0x10($sp)
  move  $s1, $v0
.L7F0C46F4:
  lui   $a0, %hi(is_gameover_flag)
  lw    $a0, %lo(is_gameover_flag)($a0)
  sltiu $t5, $a0, 1
  beqz  $t5, .L7F0C4718
   move  $a0, $t5
  lui   $a0, %hi(stop_play_flag)
  lw    $a0, %lo(stop_play_flag)($a0)
  sltiu $t6, $a0, 1
  move  $a0, $t6
.L7F0C4718:
  jal   true_if_displaying_score_in_mp
   nop   
  beqz  $v0, .L7F0C4C50
   nop   
  jal   get_scenario
   nop   
  sw    $v0, 0x80($sp)
  jal   get_textptr_for_textID
   li    $a0, 40987
  lui   $t7, %hi(ptrFirstFontTableSmall) 
  lw    $t7, %lo(ptrFirstFontTableSmall)($t7)
  lui   $a3, %hi(ptrSecondFontTableSmall)
  sw    $v0, 0xa4($sp)
  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
  addiu $a0, $sp, 0xbc
  addiu $a1, $sp, 0xc0
  move  $a2, $v0
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t7, 0x10($sp)
  jal   get_video2_settings_ulx
   nop   
  lw    $t9, 0xa8($sp)
  lw    $t2, 0xc0($sp)
  addu  $t8, $v0, $t9
  sra   $t1, $t2, 1
  subu  $a0, $t8, $t1
  addiu $a0, $a0, 0x50
  jal   get_video2_settings_uly
   sw    $a0, 0xcc($sp)
  lw    $t4, 0xbc($sp)
  sra   $t3, $t4, 1
  subu  $t5, $v0, $t3
  addiu $t6, $t5, 0x35
  jal   get_video2_settings_txtClipW
   sw    $t6, 0xc8($sp)
  sll   $s0, $v0, 0x10
  sra   $t7, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t7
  lui   $t9, %hi(ptrSecondFontTableSmall) 
  lui   $t2, %hi(ptrFirstFontTableSmall) 
  lw    $t2, %lo(ptrFirstFontTableSmall)($t2)
  lw    $t9, %lo(ptrSecondFontTableSmall)($t9)
  lui   $t8, (0x00FF00B0 >> 16) # lui $t8, 0xff
  ori   $t8, (0x00FF00B0 & 0xFFFF) # ori $t8, $t8, 0xb0
  sw    $t8, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xcc
  addiu $a2, $sp, 0xc8
  lw    $a3, 0xa4($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t2, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t9, 0x10($sp)
  lw    $v1, 0x80($sp)
  li    $at, 5
  move  $s1, $v0
  beq   $v1, $at, .L7F0C4834
   lw    $t1, 0xd4($sp)
  li    $at, 6
  beq   $v1, $at, .L7F0C4834
   li    $at, 7
  beq   $v1, $at, .L7F0C4834
   li    $at, 2
  beq   $v1, $at, .L7F0C4834
   li    $at, 3
  bne   $v1, $at, .L7F0C4888
.L7F0C4834:
   sll   $t4, $t1, 3
  subu  $t4, $t4, $t1
  sll   $t4, $t4, 4
  lui   $t3, %hi(player1_player_data+105)
  addu  $t3, $t3, $t4
  lbu   $t3, %lo(player1_player_data+105)($t3)
  li    $t9, 5
  li    $t2, 4
  bnez  $t3, .L7F0C4878
   li    $t8, 2
  li    $t5, 3
  li    $t6, 2
  li    $t7, 4
  sw    $t5, 0x8c($sp)
  sw    $t6, 0x88($sp)
  b     .L7F0C4898
   sw    $t7, 0x84($sp)
.L7F0C4878:
  sw    $t9, 0x8c($sp)
  sw    $t2, 0x88($sp)
  b     .L7F0C4898
   sw    $t8, 0x84($sp)
.L7F0C4888:
  li    $t1, 1
  sw    $t1, 0x8c($sp)
  sw    $zero, 0x88($sp)
  sw    $zero, 0x84($sp)
.L7F0C4898:
  lw    $t4, 0xd0($sp)
  li    $at, 2
  bne   $t4, $at, .L7F0C49DC
   nop   
  jal   get_video2_settings_ulx
   nop   
  sll   $s0, $v0, 0x10
  sra   $t3, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t3
  lw    $t0, 0xd4($sp)
  sll   $v1, $v0, 0x10
  sra   $t5, $v1, 0x10
  bnez  $t0, .L7F0C48E0
   move  $v1, $t5
  lw    $t6, 0x8c($sp)
  b     .L7F0C4918
   sw    $t6, 0x50($sp)
.L7F0C48E0:
  sll   $t9, $t0, 3
  subu  $t9, $t9, $t0
  sll   $t9, $t9, 4
  lui   $t2, %hi(player1_player_data + 0x69)
  addu  $t2, $t2, $t9
  lui   $t7, %hi(player1_player_data + 0x69) 
  lbu   $t7, %lo(player1_player_data + 0x69)($t7)
  lbu   $t2, %lo(player1_player_data + 0x69)($t2)
  lw    $a2, 0x84($sp)
  bne   $t7, $t2, .L7F0C4914
   nop   
  b     .L7F0C4914
   lw    $a2, 0x88($sp)
.L7F0C4914:
  sw    $a2, 0x50($sp)
.L7F0C4918:
  lw    $t8, 0xa8($sp)
  lw    $t1, 0x50($sp)
  move  $a0, $s1
  addu  $a1, $s0, $t8
  addiu $a1, $a1, 0x50
  addiu $a2, $v1, 0x46
  lw    $a3, 0x94($sp)
  jal   display_text_for_playerdata_on_MP_menu
   sw    $t1, 0x10($sp)
  jal   get_video2_settings_ulx
   move  $s1, $v0
  sll   $s0, $v0, 0x10
  sra   $t4, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t4
  lw    $a0, 0xd4($sp)
  sll   $v1, $v0, 0x10
  sra   $t3, $v1, 0x10
  li    $at, 1
  bne   $a0, $at, .L7F0C4978
   move  $v1, $t3
  lw    $t5, 0x8c($sp)
  b     .L7F0C49B0
   sw    $t5, 0x50($sp)
.L7F0C4978:
  sll   $t9, $a0, 3
  subu  $t9, $t9, $a0
  lui   $v0, %hi(player1_player_data)
  addiu $v0, %lo(player1_player_data) # addiu $v0, $v0, -0x6110
  sll   $t9, $t9, 4
  addu  $t7, $v0, $t9
  lbu   $t2, 0x69($t7)
  lbu   $t6, 0xd9($v0)
  lw    $a2, 0x84($sp)
  bne   $t6, $t2, .L7F0C49AC
   nop   
  b     .L7F0C49AC
   lw    $a2, 0x88($sp)
.L7F0C49AC:
  sw    $a2, 0x50($sp)
.L7F0C49B0:
  lw    $t8, 0xa8($sp)
  lw    $t1, 0x50($sp)
  move  $a0, $s1
  addu  $a1, $s0, $t8
  addiu $a1, $a1, 0x50
  addiu $a2, $v1, 0x56
  lw    $a3, 0x98($sp)
  jal   display_text_for_playerdata_on_MP_menu
   sw    $t1, 0x10($sp)
  b     .L7F0C4C50
   move  $s1, $v0
.L7F0C49DC:
  jal   get_video2_settings_ulx
   nop   
  sll   $s0, $v0, 0x10
  sra   $t4, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t4
  lw    $t0, 0xd4($sp)
  sll   $v1, $v0, 0x10
  sra   $t3, $v1, 0x10
  bnez  $t0, .L7F0C4A14
   move  $v1, $t3
  lw    $t5, 0x8c($sp)
  b     .L7F0C4A4C
   sw    $t5, 0x50($sp)
.L7F0C4A14:
  sll   $t7, $t0, 3
  subu  $t7, $t7, $t0
  sll   $t7, $t7, 4
  lui   $t6, %hi(player1_player_data + 0x69)
  addu  $t6, $t6, $t7
  lui   $t9, %hi(player1_player_data + 0x69) 
  lbu   $t9, %lo(player1_player_data + 0x69)($t9)
  lbu   $t6, %lo(player1_player_data + 0x69)($t6)
  lw    $a2, 0x84($sp)
  bne   $t9, $t6, .L7F0C4A48
   nop   
  b     .L7F0C4A48
   lw    $a2, 0x88($sp)
.L7F0C4A48:
  sw    $a2, 0x50($sp)
.L7F0C4A4C:
  lw    $t2, 0xa8($sp)
  lw    $t8, 0x50($sp)
  move  $a0, $s1
  addu  $a1, $s0, $t2
  addiu $a1, $a1, 0x40
  addiu $a2, $v1, 0x46
  lw    $a3, 0x94($sp)
  jal   display_text_for_playerdata_on_MP_menu
   sw    $t8, 0x10($sp)
  jal   get_video2_settings_ulx
   move  $s1, $v0
  sll   $s0, $v0, 0x10
  sra   $t1, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t1
  lw    $t0, 0xd4($sp)
  sll   $v1, $v0, 0x10
  sra   $t4, $v1, 0x10
  li    $at, 1
  bne   $t0, $at, .L7F0C4AAC
   move  $v1, $t4
  lw    $t3, 0x8c($sp)
  b     .L7F0C4AE4
   sw    $t3, 0x50($sp)
.L7F0C4AAC:
  sll   $t7, $t0, 3
  subu  $t7, $t7, $t0
  sll   $t7, $t7, 4
  lui   $t9, %hi(player1_player_data + 0x69)
  addu  $t9, $t9, $t7
  lui   $t5, %hi(player2_player_data + 0x69) 
  lbu   $t5, %lo(player2_player_data + 0x69)($t5)
  lbu   $t9, %lo(player1_player_data + 0x69)($t9)
  lw    $a2, 0x84($sp)
  bne   $t5, $t9, .L7F0C4AE0
   nop   
  b     .L7F0C4AE0
   lw    $a2, 0x88($sp)
.L7F0C4AE0:
  sw    $a2, 0x50($sp)
.L7F0C4AE4:
  lw    $t6, 0xa8($sp)
  lw    $t2, 0x50($sp)
  move  $a0, $s1
  addu  $a1, $s0, $t6
  addiu $a1, $a1, 0x60
  addiu $a2, $v1, 0x46
  lw    $a3, 0x98($sp)
  jal   display_text_for_playerdata_on_MP_menu
   sw    $t2, 0x10($sp)
  jal   get_video2_settings_ulx
   move  $s1, $v0
  sll   $s0, $v0, 0x10
  sra   $t8, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t8
  lw    $t0, 0xd4($sp)
  sll   $v1, $v0, 0x10
  sra   $t1, $v1, 0x10
  li    $at, 2
  bne   $t0, $at, .L7F0C4B44
   move  $v1, $t1
  lw    $t4, 0x8c($sp)
  b     .L7F0C4B7C
   sw    $t4, 0x50($sp)
.L7F0C4B44:
  sll   $t7, $t0, 3
  subu  $t7, $t7, $t0
  sll   $t7, $t7, 4
  lui   $t5, %hi(player1_player_data + 0x69)
  addu  $t5, $t5, $t7
  lui   $t3, %hi(player3_player_data + 0x69) 
  lbu   $t3, %lo(player3_player_data + 0x69)($t3)
  lbu   $t5, %lo(player1_player_data + 0x69)($t5)
  lw    $a2, 0x84($sp)
  bne   $t3, $t5, .L7F0C4B78
   nop   
  b     .L7F0C4B78
   lw    $a2, 0x88($sp)
.L7F0C4B78:
  sw    $a2, 0x50($sp)
.L7F0C4B7C:
  lw    $t9, 0xa8($sp)
  lw    $t6, 0x50($sp)
  move  $a0, $s1
  addu  $a1, $s0, $t9
  addiu $a1, $a1, 0x40
  addiu $a2, $v1, 0x56
  lw    $a3, 0x9c($sp)
  jal   display_text_for_playerdata_on_MP_menu
   sw    $t6, 0x10($sp)
  lw    $t2, 0xd0($sp)
  li    $at, 4
  move  $s1, $v0
  bne   $t2, $at, .L7F0C4C50
   nop   
  jal   get_video2_settings_ulx
   nop   
  sll   $s0, $v0, 0x10
  sra   $t8, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t8
  lw    $a0, 0xd4($sp)
  sll   $v1, $v0, 0x10
  sra   $t1, $v1, 0x10
  li    $at, 3
  bne   $a0, $at, .L7F0C4BF0
   move  $v1, $t1
  lw    $t4, 0x8c($sp)
  b     .L7F0C4C28
   sw    $t4, 0x50($sp)
.L7F0C4BF0:
  sll   $t3, $a0, 3
  subu  $t3, $t3, $a0
  lui   $v0, %hi(player1_player_data)
  addiu $v0, %lo(player1_player_data) # addiu $v0, $v0, -0x6110
  sll   $t3, $t3, 4
  addu  $t5, $v0, $t3
  lbu   $t9, 0x69($t5)
  lbu   $t7, 0x1b9($v0)
  lw    $a2, 0x84($sp)
  bne   $t7, $t9, .L7F0C4C24
   nop   
  b     .L7F0C4C24
   lw    $a2, 0x88($sp)
.L7F0C4C24:
  sw    $a2, 0x50($sp)
.L7F0C4C28:
  lw    $t6, 0xa8($sp)
  lw    $t2, 0x50($sp)
  move  $a0, $s1
  addu  $a1, $s0, $t6
  addiu $a1, $a1, 0x60
  addiu $a2, $v1, 0x56
  lw    $a3, 0xa0($sp)
  jal   display_text_for_playerdata_on_MP_menu
   sw    $t2, 0x10($sp)
  move  $s1, $v0
.L7F0C4C50:
  lui   $v1, %hi(pPlayer)
  b     .L7F0C5B44
   lw    $v1, %lo(pPlayer)($v1)
  li    $at, 2
.L7F0C4C60:
  bne   $v0, $at, .L7F0C50D4
   lui   $a0, %hi(is_gameover_flag)
  lw    $a0, %lo(is_gameover_flag)($a0)
  sltiu $t8, $a0, 1
  beqz  $t8, .L7F0C4C88
   move  $a0, $t8
  lui   $a0, %hi(stop_play_flag)
  lw    $a0, %lo(stop_play_flag)($a0)
  sltiu $t1, $a0, 1
  move  $a0, $t1
.L7F0C4C88:
  jal   true_if_displaying_rank_in_mp
   nop   
  beqz  $v0, .L7F0C4D64
   addiu $a0, $sp, 0xac
  jal   write_playerrank_to_buffer
   lw    $a1, 0xd4($sp)
  lui   $t4, %hi(ptrFirstFontTableSmall) 
  lw    $t4, %lo(ptrFirstFontTableSmall)($t4)
  lui   $a3, %hi(ptrSecondFontTableSmall)
  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
  addiu $a0, $sp, 0xbc
  addiu $a1, $sp, 0xc0
  addiu $a2, $sp, 0xac
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t4, 0x10($sp)
  jal   get_video2_settings_ulx
   nop   
  lw    $t3, 0xa8($sp)
  lw    $t7, 0xc0($sp)
  addu  $t5, $v0, $t3
  sra   $t9, $t7, 1
  subu  $a0, $t5, $t9
  addiu $a0, $a0, 0x50
  jal   get_video2_settings_uly
   sw    $a0, 0xcc($sp)
  lw    $t6, 0xbc($sp)
  sra   $t2, $t6, 1
  subu  $t8, $v0, $t2
  addiu $t1, $t8, 0x25
  jal   get_video2_settings_txtClipW
   sw    $t1, 0xc8($sp)
  sll   $s0, $v0, 0x10
  sra   $t4, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t4
  lui   $t3, %hi(ptrSecondFontTableSmall) 
  lui   $t7, %hi(ptrFirstFontTableSmall) 
  lw    $t7, %lo(ptrFirstFontTableSmall)($t7)
  lw    $t3, %lo(ptrSecondFontTableSmall)($t3)
  lui   $t5, (0x00FF00B0 >> 16) # lui $t5, 0xff
  ori   $t5, (0x00FF00B0 & 0xFFFF) # ori $t5, $t5, 0xb0
  sw    $t5, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xcc
  addiu $a2, $sp, 0xc8
  addiu $a3, $sp, 0xac
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t7, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t3, 0x10($sp)
  move  $s1, $v0
.L7F0C4D64:
  jal   get_textptr_for_textID
   li    $a0, 40988
  li    $a0, 40989
  jal   get_textptr_for_textID
   sw    $v0, 0x4c($sp)
  lw    $a3, 0xd4($sp)
  lui   $a1, %hi(ascii_pnum_KILLS)
  addiu $a1, %lo(ascii_pnum_KILLS) # addiu $a1, $a1, -0x43d0
  lw    $a2, 0x4c($sp)
  addiu $a0, $sp, 0xac
  sw    $v0, 0x10($sp)
  jal   sprintf
   addiu $a3, $a3, 1
  lui   $t9, %hi(ptrFirstFontTableSmall) 
  lw    $t9, %lo(ptrFirstFontTableSmall)($t9)
  lui   $a3, %hi(ptrSecondFontTableSmall)
  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
  addiu $a0, $sp, 0xbc
  addiu $a1, $sp, 0xc0
  addiu $a2, $sp, 0xac
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t9, 0x10($sp)
  jal   get_video2_settings_ulx
   nop   
  lw    $t6, 0xa8($sp)
  lw    $t8, 0xc0($sp)
  addu  $t2, $v0, $t6
  sra   $t1, $t8, 1
  subu  $a0, $t2, $t1
  addiu $a0, $a0, 0x50
  jal   get_video2_settings_uly
   sw    $a0, 0xcc($sp)
  lw    $t4, 0xbc($sp)
  sra   $t3, $t4, 1
  subu  $t7, $v0, $t3
  addiu $t5, $t7, 0x35
  jal   get_video2_settings_txtClipW
   sw    $t5, 0xc8($sp)
  sll   $s0, $v0, 0x10
  sra   $t9, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t9
  lui   $t6, %hi(ptrSecondFontTableSmall) 
  lui   $t8, %hi(ptrFirstFontTableSmall) 
  lw    $t8, %lo(ptrFirstFontTableSmall)($t8)
  lw    $t6, %lo(ptrSecondFontTableSmall)($t6)
  lui   $t2, (0x00FF00B0 >> 16) # lui $t2, 0xff
  ori   $t2, (0x00FF00B0 & 0xFFFF) # ori $t2, $t2, 0xb0
  sw    $t2, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xcc
  addiu $a2, $sp, 0xc8
  addiu $a3, $sp, 0xac
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t8, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t6, 0x10($sp)
  lw    $t1, 0xd0($sp)
  move  $s1, $v0
  li    $at, 2
  bne   $t1, $at, .L7F0C4F34
   lw    $v0, 0xd4($sp)
  lw    $v0, 0xd4($sp)
  beql  $v0, $zero, .L7F0C4ED4
   li    $at, 1
  jal   get_video2_settings_ulx
   nop   
  sll   $s0, $v0, 0x10
  sra   $t4, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t4
  lw    $t7, 0xd4($sp)
  lw    $t3, 0xa8($sp)
  lui   $a3, %hi(player1_player_data+36)
  sll   $t5, $t7, 3
  subu  $t5, $t5, $t7
  sll   $t5, $t5, 4
  addu  $a3, $a3, $t5
  addu  $a1, $s0, $t3
  addiu $a1, $a1, 0x50
  lw    $a3, %lo(player1_player_data+36)($a3)
  move  $a0, $s1
  addiu $a2, $v0, 0x46
  jal   display_text_for_playerdata_on_MP_menu
   sw    $zero, 0x10($sp)
  move  $s1, $v0
  lw    $v0, 0xd4($sp)
  li    $at, 1
.L7F0C4ED4:
  beq   $v0, $at, .L7F0C50C8
   sll   $t9, $v0, 3
  subu  $t9, $t9, $v0
  lui   $t6, %hi(player1_player_data) 
  addiu $t6, %lo(player1_player_data) # addiu $t6, $t6, -0x6110
  sll   $t9, $t9, 4
  addu  $t8, $t9, $t6
  jal   get_video2_settings_ulx
   sw    $t8, 0x44($sp)
  sll   $s0, $v0, 0x10
  sra   $t2, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t2
  lw    $t1, 0xa8($sp)
  lw    $t4, 0x44($sp)
  move  $a0, $s1
  addu  $a1, $s0, $t1
  lw    $a3, 0x28($t4)
  sw    $zero, 0x10($sp)
  addiu $a1, $a1, 0x50
  jal   display_text_for_playerdata_on_MP_menu
   addiu $a2, $v0, 0x56
  b     .L7F0C50C8
   move  $s1, $v0
.L7F0C4F34:
  beql  $v0, $zero, .L7F0C4F98
   li    $at, 1
  jal   get_video2_settings_ulx
   nop   
  sll   $s0, $v0, 0x10
  sra   $t3, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t3
  lw    $t5, 0xd4($sp)
  lw    $t7, 0xa8($sp)
  lui   $a3, %hi(player1_player_data+36)
  sll   $t9, $t5, 3
  subu  $t9, $t9, $t5
  sll   $t9, $t9, 4
  addu  $a3, $a3, $t9
  addu  $a1, $s0, $t7
  addiu $a1, $a1, 0x40
  lw    $a3, %lo(player1_player_data+36)($a3)
  move  $a0, $s1
  addiu $a2, $v0, 0x46
  jal   display_text_for_playerdata_on_MP_menu
   sw    $zero, 0x10($sp)
  move  $s1, $v0
  lw    $v0, 0xd4($sp)
  li    $at, 1
.L7F0C4F98:
  beq   $v0, $at, .L7F0C4FF8
   sll   $t6, $v0, 3
  subu  $t6, $t6, $v0
  lui   $t8, %hi(player1_player_data) 
  addiu $t8, %lo(player1_player_data) # addiu $t8, $t8, -0x6110
  sll   $t6, $t6, 4
  addu  $t2, $t6, $t8
  jal   get_video2_settings_ulx
   sw    $t2, 0x44($sp)
  sll   $s0, $v0, 0x10
  sra   $t1, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t1
  lw    $t4, 0xa8($sp)
  lw    $t3, 0x44($sp)
  move  $a0, $s1
  addu  $a1, $s0, $t4
  lw    $a3, 0x28($t3)
  sw    $zero, 0x10($sp)
  addiu $a1, $a1, 0x60
  jal   display_text_for_playerdata_on_MP_menu
   addiu $a2, $v0, 0x46
  move  $s1, $v0
  lw    $v0, 0xd4($sp)
.L7F0C4FF8:
  li    $at, 2
  beq   $v0, $at, .L7F0C505C
   sll   $t7, $v0, 3
  subu  $t7, $t7, $v0
  lui   $t5, %hi(player1_player_data) 
  addiu $t5, %lo(player1_player_data) # addiu $t5, $t5, -0x6110
  sll   $t7, $t7, 4
  addu  $t9, $t7, $t5
  jal   get_video2_settings_ulx
   sw    $t9, 0x44($sp)
  sll   $s0, $v0, 0x10
  sra   $t6, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t6
  lw    $t8, 0xa8($sp)
  lw    $t2, 0x44($sp)
  move  $a0, $s1
  addu  $a1, $s0, $t8
  lw    $a3, 0x2c($t2)
  sw    $zero, 0x10($sp)
  addiu $a1, $a1, 0x40
  jal   display_text_for_playerdata_on_MP_menu
   addiu $a2, $v0, 0x56
  move  $s1, $v0
  lw    $v0, 0xd4($sp)
.L7F0C505C:
  lw    $t1, 0xd0($sp)
  li    $at, 4
  bne   $t1, $at, .L7F0C50C8
   li    $at, 3
  beq   $v0, $at, .L7F0C50C8
   sll   $t4, $v0, 3
  subu  $t4, $t4, $v0
  lui   $t3, %hi(player1_player_data) 
  addiu $t3, %lo(player1_player_data) # addiu $t3, $t3, -0x6110
  sll   $t4, $t4, 4
  addu  $t7, $t4, $t3
  jal   get_video2_settings_ulx
   sw    $t7, 0x44($sp)
  sll   $s0, $v0, 0x10
  sra   $t5, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t5
  lw    $t9, 0xa8($sp)
  lw    $t6, 0x44($sp)
  move  $a0, $s1
  addu  $a1, $s0, $t9
  lw    $a3, 0x30($t6)
  sw    $zero, 0x10($sp)
  addiu $a1, $a1, 0x60
  jal   display_text_for_playerdata_on_MP_menu
   addiu $a2, $v0, 0x56
  move  $s1, $v0
.L7F0C50C8:
  lui   $v1, %hi(pPlayer)
  b     .L7F0C5B44
   lw    $v1, %lo(pPlayer)($v1)
.L7F0C50D4:
  li    $at, 1
  bne   $v0, $at, .L7F0C5780
   lui   $a0, %hi(is_gameover_flag)
  lw    $a0, %lo(is_gameover_flag)($a0)
  sltiu $t8, $a0, 1
  beqz  $t8, .L7F0C5100
   move  $a0, $t8
  lui   $a0, %hi(stop_play_flag)
  lw    $a0, %lo(stop_play_flag)($a0)
  sltiu $t2, $a0, 1
  move  $a0, $t2
.L7F0C5100:
  jal   true_if_displaying_rank_in_mp
   nop   
  beqz  $v0, .L7F0C51DC
   addiu $a0, $sp, 0xac
  jal   write_playerrank_to_buffer
   lw    $a1, 0xd4($sp)
  lui   $t1, %hi(ptrFirstFontTableSmall) 
  lw    $t1, %lo(ptrFirstFontTableSmall)($t1)
  lui   $a3, %hi(ptrSecondFontTableSmall)
  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
  addiu $a0, $sp, 0xbc
  addiu $a1, $sp, 0xc0
  addiu $a2, $sp, 0xac
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t1, 0x10($sp)
  jal   get_video2_settings_ulx
   nop   
  lw    $t4, 0xa8($sp)
  lw    $t7, 0xc0($sp)
  addu  $t3, $v0, $t4
  sra   $t5, $t7, 1
  subu  $a0, $t3, $t5
  addiu $a0, $a0, 0x50
  jal   get_video2_settings_uly
   sw    $a0, 0xcc($sp)
  lw    $t9, 0xbc($sp)
  sra   $t6, $t9, 1
  subu  $t8, $v0, $t6
  addiu $t2, $t8, 0x25
  jal   get_video2_settings_txtClipW
   sw    $t2, 0xc8($sp)
  sll   $s0, $v0, 0x10
  sra   $t1, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t1
  lui   $t4, %hi(ptrSecondFontTableSmall) 
  lui   $t7, %hi(ptrFirstFontTableSmall) 
  lw    $t7, %lo(ptrFirstFontTableSmall)($t7)
  lw    $t4, %lo(ptrSecondFontTableSmall)($t4)
  lui   $t3, (0x00FF00B0 >> 16) # lui $t3, 0xff
  ori   $t3, (0x00FF00B0 & 0xFFFF) # ori $t3, $t3, 0xb0
  sw    $t3, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xcc
  addiu $a2, $sp, 0xc8
  addiu $a3, $sp, 0xac
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t7, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t4, 0x10($sp)
  move  $s1, $v0
.L7F0C51DC:
  jal   get_textptr_for_textID
   li    $a0, 40988
  li    $a0, 40990
  jal   get_textptr_for_textID
   sw    $v0, 0x4c($sp)
  lw    $a3, 0xd4($sp)
  lui   $a1, %hi(ascii_pnum_LOSSES)
  addiu $a1, %lo(ascii_pnum_LOSSES) # addiu $a1, $a1, -0x43c8
  lw    $a2, 0x4c($sp)
  addiu $a0, $sp, 0xac
  sw    $v0, 0x10($sp)
  jal   sprintf
   addiu $a3, $a3, 1
  lui   $t5, %hi(ptrFirstFontTableSmall) 
  lw    $t5, %lo(ptrFirstFontTableSmall)($t5)
  lui   $a3, %hi(ptrSecondFontTableSmall)
  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
  addiu $a0, $sp, 0xbc
  addiu $a1, $sp, 0xc0
  addiu $a2, $sp, 0xac
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t5, 0x10($sp)
  jal   get_video2_settings_ulx
   nop   
  lw    $t9, 0xa8($sp)
  lw    $t8, 0xc0($sp)
  addu  $t6, $v0, $t9
  sra   $t2, $t8, 1
  subu  $a0, $t6, $t2
  addiu $a0, $a0, 0x50
  jal   get_video2_settings_uly
   sw    $a0, 0xcc($sp)
  lw    $t1, 0xbc($sp)
  sra   $t4, $t1, 1
  subu  $t7, $v0, $t4
  addiu $t3, $t7, 0x35
  jal   get_video2_settings_txtClipW
   sw    $t3, 0xc8($sp)
  sll   $s0, $v0, 0x10
  sra   $t5, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t5
  lui   $t9, %hi(ptrSecondFontTableSmall) 
  lui   $t8, %hi(ptrFirstFontTableSmall) 
  lw    $t8, %lo(ptrFirstFontTableSmall)($t8)
  lw    $t9, %lo(ptrSecondFontTableSmall)($t9)
  lui   $t6, (0xFF4040B0 >> 16) # lui $t6, 0xff40
  ori   $t6, (0xFF4040B0 & 0xFFFF) # ori $t6, $t6, 0x40b0
  sw    $t6, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xcc
  addiu $a2, $sp, 0xc8
  addiu $a3, $sp, 0xac
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t8, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t9, 0x10($sp)
  lw    $t2, 0xd0($sp)
  li    $at, 2
  move  $s1, $v0
  bne   $t2, $at, .L7F0C5468
   lw    $t8, 0xd4($sp)
  lw    $v0, 0xd4($sp)
  lui   $t5, %hi(player1_player_data + 0x24) 
  beqz  $v0, .L7F0C5348
   nop   
  jal   get_video2_settings_ulx
   nop   
  sll   $s0, $v0, 0x10
  sra   $t1, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t1
  lw    $t7, 0xd4($sp)
  lw    $t4, 0xa8($sp)
  lui   $a3, %hi(player1_player_data+36)
  sll   $t3, $t7, 2
  addu  $a3, $a3, $t3
  addu  $a1, $s0, $t4
  addiu $a1, $a1, 0x50
  lw    $a3, %lo(player1_player_data+36)($a3)
  move  $a0, $s1
  addiu $a2, $v0, 0x46
  jal   display_text_for_playerdata_on_MP_menu
   sw    $zero, 0x10($sp)
  move  $s1, $v0
  b     .L7F0C53A8
   lw    $v0, 0xd4($sp)
.L7F0C5348:
  lw    $t5, %lo(player1_player_data + 0x24)($t5)
  blezl $t5, .L7F0C53AC
   li    $at, 1
  jal   get_video2_settings_ulx
   nop   
  sll   $s0, $v0, 0x10
  sra   $t9, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t9
  lw    $t6, 0xd4($sp)
  lw    $t8, 0xa8($sp)
  lui   $a3, %hi(player1_player_data+36)
  sll   $t2, $t6, 2
  addu  $a3, $a3, $t2
  li    $t1, 3
  addu  $a1, $s0, $t8
  addiu $a1, $a1, 0x50
  sw    $t1, 0x10($sp)
  lw    $a3, %lo(player1_player_data+36)($a3)
  move  $a0, $s1
  jal   display_text_for_playerdata_on_MP_menu
   addiu $a2, $v0, 0x46
  move  $s1, $v0
  lw    $v0, 0xd4($sp)
.L7F0C53A8:
  li    $at, 1
.L7F0C53AC:
  beq   $v0, $at, .L7F0C5408
   lui   $t6, %hi(player2_player_data + 0x28) 
  lui   $t7, %hi(player1_player_data) 
  addiu $t7, %lo(player1_player_data) # addiu $t7, $t7, -0x6110
  sll   $t4, $v0, 2
  addu  $t3, $t4, $t7
  jal   get_video2_settings_ulx
   sw    $t3, 0x44($sp)
  sll   $s0, $v0, 0x10
  sra   $t5, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t5
  lw    $t9, 0xa8($sp)
  lw    $t8, 0x44($sp)
  move  $a0, $s1
  addu  $a1, $s0, $t9
  lw    $a3, 0x94($t8)
  sw    $zero, 0x10($sp)
  addiu $a1, $a1, 0x50
  jal   display_text_for_playerdata_on_MP_menu
   addiu $a2, $v0, 0x56
  b     .L7F0C5774
   move  $s1, $v0
.L7F0C5408:
  lw    $t6, %lo(player2_player_data + 0x28)($t6)
  lui   $t1, %hi(player1_player_data) 
  addiu $t1, %lo(player1_player_data) # addiu $t1, $t1, -0x6110
  blez  $t6, .L7F0C5774
   sll   $t2, $v0, 2
  addu  $t4, $t2, $t1
  jal   get_video2_settings_ulx
   sw    $t4, 0x44($sp)
  sll   $s0, $v0, 0x10
  sra   $t7, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t7
  lw    $t3, 0xa8($sp)
  lw    $t5, 0x44($sp)
  li    $t9, 3
  addu  $a1, $s0, $t3
  lw    $a3, 0x94($t5)
  sw    $t9, 0x10($sp)
  addiu $a1, $a1, 0x50
  move  $a0, $s1
  jal   display_text_for_playerdata_on_MP_menu
   addiu $a2, $v0, 0x56
  b     .L7F0C5774
   move  $s1, $v0
.L7F0C5468:
  beqz  $t8, .L7F0C54C0
   lui   $t7, %hi(player1_player_data + 0x24) 
  jal   get_video2_settings_ulx
   nop   
  sll   $s0, $v0, 0x10
  sra   $t6, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t6
  lw    $t1, 0xd4($sp)
  lw    $t2, 0xa8($sp)
  lui   $a3, %hi(player1_player_data+36)
  sll   $t4, $t1, 2
  addu  $a3, $a3, $t4
  addu  $a1, $s0, $t2
  addiu $a1, $a1, 0x40
  lw    $a3, %lo(player1_player_data+36)($a3)
  move  $a0, $s1
  addiu $a2, $v0, 0x46
  jal   display_text_for_playerdata_on_MP_menu
   sw    $zero, 0x10($sp)
  b     .L7F0C551C
   move  $s1, $v0
.L7F0C54C0:
  lw    $t7, %lo(player1_player_data + 0x24)($t7)
  blezl $t7, .L7F0C5520
   lw    $t2, 0xd4($sp)
  jal   get_video2_settings_ulx
   nop   
  sll   $s0, $v0, 0x10
  sra   $t3, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t3
  lw    $t9, 0xd4($sp)
  lw    $t5, 0xa8($sp)
  lui   $a3, %hi(player1_player_data+36)
  sll   $t8, $t9, 2
  addu  $a3, $a3, $t8
  li    $t6, 3
  addu  $a1, $s0, $t5
  addiu $a1, $a1, 0x40
  sw    $t6, 0x10($sp)
  lw    $a3, %lo(player1_player_data+36)($a3)
  move  $a0, $s1
  jal   display_text_for_playerdata_on_MP_menu
   addiu $a2, $v0, 0x46
  move  $s1, $v0
.L7F0C551C:
  lw    $t2, 0xd4($sp)
.L7F0C5520:
  li    $at, 1
  lui   $t8, %hi(player2_player_data + 0x28) 
  beq   $t2, $at, .L7F0C5580
   sll   $t1, $t2, 2
  lui   $t4, %hi(player1_player_data) 
  addiu $t4, %lo(player1_player_data) # addiu $t4, $t4, -0x6110
  addu  $t7, $t1, $t4
  jal   get_video2_settings_ulx
   sw    $t7, 0x44($sp)
  sll   $s0, $v0, 0x10
  sra   $t3, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t3
  lw    $t5, 0xa8($sp)
  lw    $t9, 0x44($sp)
  move  $a0, $s1
  addu  $a1, $s0, $t5
  lw    $a3, 0x94($t9)
  sw    $zero, 0x10($sp)
  addiu $a1, $a1, 0x60
  jal   display_text_for_playerdata_on_MP_menu
   addiu $a2, $v0, 0x46
  b     .L7F0C55E0
   move  $s1, $v0
.L7F0C5580:
  lw    $t8, %lo(player2_player_data + 0x28)($t8)
  lw    $t6, 0xd4($sp)
  lui   $t1, %hi(player1_player_data) 
  blez  $t8, .L7F0C55E0
   sll   $t2, $t6, 2
  addiu $t1, %lo(player1_player_data) # addiu $t1, $t1, -0x6110
  addu  $t4, $t2, $t1
  jal   get_video2_settings_ulx
   sw    $t4, 0x44($sp)
  sll   $s0, $v0, 0x10
  sra   $t7, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t7
  lw    $t3, 0xa8($sp)
  lw    $t5, 0x44($sp)
  li    $t9, 3
  addu  $a1, $s0, $t3
  lw    $a3, 0x94($t5)
  sw    $t9, 0x10($sp)
  addiu $a1, $a1, 0x60
  move  $a0, $s1
  jal   display_text_for_playerdata_on_MP_menu
   addiu $a2, $v0, 0x46
  move  $s1, $v0
.L7F0C55E0:
  lw    $t8, 0xd4($sp)
  li    $at, 2
  lui   $t5, %hi(player3_player_data + 0x2C) 
  beq   $t8, $at, .L7F0C5644
   sll   $t6, $t8, 2
  lui   $t2, %hi(player1_player_data) 
  addiu $t2, %lo(player1_player_data) # addiu $t2, $t2, -0x6110
  addu  $t1, $t6, $t2
  jal   get_video2_settings_ulx
   sw    $t1, 0x44($sp)
  sll   $s0, $v0, 0x10
  sra   $t4, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t4
  lw    $t7, 0xa8($sp)
  lw    $t3, 0x44($sp)
  move  $a0, $s1
  addu  $a1, $s0, $t7
  lw    $a3, 0x104($t3)
  sw    $zero, 0x10($sp)
  addiu $a1, $a1, 0x40
  jal   display_text_for_playerdata_on_MP_menu
   addiu $a2, $v0, 0x56
  b     .L7F0C56A4
   move  $s1, $v0
.L7F0C5644:
  lw    $t5, %lo(player3_player_data + 0x2C)($t5)
  lw    $t9, 0xd4($sp)
  lui   $t6, %hi(player1_player_data) 
  blez  $t5, .L7F0C56A4
   sll   $t8, $t9, 2
  addiu $t6, %lo(player1_player_data) # addiu $t6, $t6, -0x6110
  addu  $t2, $t8, $t6
  jal   get_video2_settings_ulx
   sw    $t2, 0x44($sp)
  sll   $s0, $v0, 0x10
  sra   $t1, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t1
  lw    $t4, 0xa8($sp)
  lw    $t7, 0x44($sp)
  li    $t3, 3
  addu  $a1, $s0, $t4
  lw    $a3, 0x104($t7)
  sw    $t3, 0x10($sp)
  addiu $a1, $a1, 0x40
  move  $a0, $s1
  jal   display_text_for_playerdata_on_MP_menu
   addiu $a2, $v0, 0x56
  move  $s1, $v0
.L7F0C56A4:
  lw    $t5, 0xd0($sp)
  li    $at, 4
  lw    $t9, 0xd4($sp)
  bne   $t5, $at, .L7F0C5774
   li    $at, 3
  beq   $t9, $at, .L7F0C5714
   lui   $t3, %hi(player3_player_data + 0x30) 
  lui   $t6, %hi(player1_player_data) 
  addiu $t6, %lo(player1_player_data) # addiu $t6, $t6, -0x6110
  sll   $t8, $t9, 2
  addu  $t2, $t8, $t6
  jal   get_video2_settings_ulx
   sw    $t2, 0x44($sp)
  sll   $s0, $v0, 0x10
  sra   $t1, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t1
  lw    $t4, 0xa8($sp)
  lw    $t7, 0x44($sp)
  move  $a0, $s1
  addu  $a1, $s0, $t4
  lw    $a3, 0x174($t7)
  sw    $zero, 0x10($sp)
  addiu $a1, $a1, 0x60
  jal   display_text_for_playerdata_on_MP_menu
   addiu $a2, $v0, 0x56
  b     .L7F0C5774
   move  $s1, $v0
.L7F0C5714:
  lw    $t3, %lo(player4_player_data+0x30)($t3)
  lw    $t5, 0xd4($sp)
  lui   $t8, %hi(player1_player_data) 
  blez  $t3, .L7F0C5774
   sll   $t9, $t5, 2
  addiu $t8, %lo(player1_player_data) # addiu $t8, $t8, -0x6110
  addu  $t6, $t9, $t8
  jal   get_video2_settings_ulx
   sw    $t6, 0x44($sp)
  sll   $s0, $v0, 0x10
  sra   $t2, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t2
  lw    $t1, 0xa8($sp)
  lw    $t4, 0x44($sp)
  li    $t7, 3
  addu  $a1, $s0, $t1
  lw    $a3, 0x174($t4)
  sw    $t7, 0x10($sp)
  addiu $a1, $a1, 0x60
  move  $a0, $s1
  jal   display_text_for_playerdata_on_MP_menu
   addiu $a2, $v0, 0x56
  move  $s1, $v0
.L7F0C5774:
  lui   $v1, %hi(pPlayer)
  b     .L7F0C5B44
   lw    $v1, %lo(pPlayer)($v1)
.L7F0C5780:
  bnezl $v0, .L7F0C5B48
   lw    $t7, 0x29c8($v1)
  lw    $t5, 0xd0($sp)
  lw    $t3, 0xa8($sp)
  slti  $at, $t5, 3
  bnez  $at, .L7F0C57C0
   sw    $t3, 0x74($sp)
  lw    $t9, 0xd4($sp)
  lw    $t2, 0xa8($sp)
  addiu $t6, $t3, -7
  andi  $t8, $t9, 1
  beqz  $t8, .L7F0C57BC
   addiu $t1, $t2, 7
  b     .L7F0C57C0
   sw    $t6, 0x74($sp)
.L7F0C57BC:
  sw    $t1, 0x74($sp)
.L7F0C57C0:
  jal   get_textptr_for_textID
   li    $a0, 40991
  lui   $t4, %hi(ptrFirstFontTableSmall) 
  lw    $t4, %lo(ptrFirstFontTableSmall)($t4)
  lui   $a3, %hi(ptrSecondFontTableSmall)
  sw    $v0, 0xa4($sp)
  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
  addiu $a0, $sp, 0x7c
  addiu $a1, $sp, 0x78
  move  $a2, $v0
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t4, 0x10($sp)
  jal   get_video2_settings_ulx
   nop   
  lw    $t7, 0x74($sp)
  lw    $t9, 0x78($sp)
  addu  $t5, $v0, $t7
  sra   $t8, $t9, 1
  subu  $a0, $t5, $t8
  addiu $a0, $a0, 0x50
  jal   get_video2_settings_uly
   sw    $a0, 0xcc($sp)
  lw    $t3, 0x7c($sp)
  sra   $t6, $t3, 1
  subu  $t2, $v0, $t6
  addiu $t1, $t2, 0x25
  jal   get_video2_settings_txtClipW
   sw    $t1, 0xc8($sp)
  sll   $s0, $v0, 0x10
  sra   $t4, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t4
  lui   $t7, %hi(ptrSecondFontTableSmall) 
  lui   $t9, %hi(ptrFirstFontTableSmall) 
  lw    $t9, %lo(ptrFirstFontTableSmall)($t9)
  lw    $t7, %lo(ptrSecondFontTableSmall)($t7)
  lui   $t5, (0x00FF00B0 >> 16) # lui $t5, 0xff
  ori   $t5, (0x00FF00B0 & 0xFFFF) # ori $t5, $t5, 0xb0
  sw    $t5, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xcc
  addiu $a2, $sp, 0xc8
  lw    $a3, 0xa4($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t9, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t7, 0x10($sp)
  move  $s1, $v0
  lw    $a0, 0xd4($sp)
  jal   getplayerfavoredweapon
   move  $a1, $zero
  lui   $t8, %hi(ptrFirstFontTableSmall) 
  lw    $t8, %lo(ptrFirstFontTableSmall)($t8)
  lui   $a3, %hi(ptrSecondFontTableSmall)
  sw    $v0, 0xa4($sp)
  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
  addiu $a0, $sp, 0x7c
  addiu $a1, $sp, 0x78
  move  $a2, $v0
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t8, 0x10($sp)
  jal   get_video2_settings_ulx
   nop   
  lw    $t3, 0x74($sp)
  lw    $t2, 0x78($sp)
  addu  $t6, $v0, $t3
  sra   $t1, $t2, 1
  subu  $a0, $t6, $t1
  addiu $a0, $a0, 0x50
  jal   get_video2_settings_uly
   sw    $a0, 0xcc($sp)
  lui   $t7, %hi(j_text_trigger) 
  lw    $t7, %lo(j_text_trigger)($t7)
  sll   $v1, $v0, 0x10
  sra   $t4, $v1, 0x10
  beqz  $t7, .L7F0C5910
   move  $v1, $t4
  b     .L7F0C5914
   li    $a0, 4
.L7F0C5910:
  move  $a0, $zero
.L7F0C5914:
  lw    $t5, 0x7c($sp)
  addu  $t9, $a0, $v1
  sra   $t8, $t5, 1
  subu  $t3, $t9, $t8
  addiu $t2, $t3, 0x35
  jal   get_video2_settings_txtClipW
   sw    $t2, 0xc8($sp)
  sll   $s0, $v0, 0x10
  sra   $t6, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t6
  lui   $t1, %hi(ptrSecondFontTableSmall) 
  lui   $t4, %hi(ptrFirstFontTableSmall) 
  lw    $t4, %lo(ptrFirstFontTableSmall)($t4)
  lw    $t1, %lo(ptrSecondFontTableSmall)($t1)
  lui   $t7, (0x00FF00B0 >> 16) # lui $t7, 0xff
  ori   $t7, (0x00FF00B0 & 0xFFFF) # ori $t7, $t7, 0xb0
  sw    $t7, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xcc
  addiu $a2, $sp, 0xc8
  lw    $a3, 0xa4($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t4, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t1, 0x10($sp)
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  move  $s1, $v0
  addiu $a0, $sp, 0x7c
  lw    $t0, 0x2a10($v1)
  addiu $a1, $sp, 0x78
  lui   $a3, %hi(ptrSecondFontTableSmall)
  beqz  $t0, .L7F0C5A6C
   move  $a2, $t0
  lui   $t5, %hi(ptrFirstFontTableSmall) 
  lw    $t5, %lo(ptrFirstFontTableSmall)($t5)
  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
  sw    $zero, 0x14($sp)
  sw    $t0, 0xa4($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t5, 0x10($sp)
  jal   get_video2_settings_ulx
   nop   
  lw    $t9, 0x74($sp)
  lw    $t3, 0x78($sp)
  addu  $t8, $v0, $t9
  sra   $t2, $t3, 1
  subu  $a0, $t8, $t2
  addiu $a0, $a0, 0x50
  jal   get_video2_settings_uly
   sw    $a0, 0xcc($sp)
  lw    $t6, 0x7c($sp)
  sra   $t1, $t6, 1
  subu  $t4, $v0, $t1
  addiu $t7, $t4, 0x4b
  jal   get_video2_settings_txtClipW
   sw    $t7, 0xc8($sp)
  sll   $s0, $v0, 0x10
  sra   $t5, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t5
  lui   $t9, %hi(ptrSecondFontTableSmall) 
  lui   $t3, %hi(ptrFirstFontTableSmall) 
  lw    $t3, %lo(ptrFirstFontTableSmall)($t3)
  lw    $t9, %lo(ptrSecondFontTableSmall)($t9)
  lui   $t8, (0x00FF00B0 >> 16) # lui $t8, 0xff
  ori   $t8, (0x00FF00B0 & 0xFFFF) # ori $t8, $t8, 0xb0
  sw    $t8, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xcc
  addiu $a2, $sp, 0xc8
  lw    $a3, 0xa4($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t3, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t9, 0x10($sp)
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  move  $s1, $v0
.L7F0C5A6C:
  lw    $v0, 0x2a14($v1)
  addiu $a0, $sp, 0x7c
  addiu $a1, $sp, 0x78
  beqz  $v0, .L7F0C5B44
   move  $a2, $v0
  lui   $t2, %hi(ptrFirstFontTableSmall) 
  lw    $t2, %lo(ptrFirstFontTableSmall)($t2)
  lui   $a3, %hi(ptrSecondFontTableSmall)
  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
  sw    $zero, 0x14($sp)
  sw    $v0, 0xa4($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t2, 0x10($sp)
  jal   get_video2_settings_ulx
   nop   
  lw    $t6, 0x74($sp)
  lw    $t4, 0x78($sp)
  addu  $t1, $v0, $t6
  sra   $t7, $t4, 1
  subu  $a0, $t1, $t7
  addiu $a0, $a0, 0x50
  jal   get_video2_settings_uly
   sw    $a0, 0xcc($sp)
  lw    $t5, 0x7c($sp)
  sra   $t9, $t5, 1
  subu  $t3, $v0, $t9
  addiu $t8, $t3, 0x58
  jal   get_video2_settings_txtClipW
   sw    $t8, 0xc8($sp)
  sll   $s0, $v0, 0x10
  sra   $t2, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t2
  lui   $t6, %hi(ptrSecondFontTableSmall) 
  lui   $t4, %hi(ptrFirstFontTableSmall) 
  lw    $t4, %lo(ptrFirstFontTableSmall)($t4)
  lw    $t6, %lo(ptrSecondFontTableSmall)($t6)
  lui   $t1, (0x00FF00B0 >> 16) # lui $t1, 0xff
  ori   $t1, (0x00FF00B0 & 0xFFFF) # ori $t1, $t1, 0xb0
  sw    $t1, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xcc
  addiu $a2, $sp, 0xc8
  lw    $a3, 0xa4($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t4, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t6, 0x10($sp)
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  move  $s1, $v0
.L7F0C5B44:
  lw    $t7, 0x29c8($v1)
.L7F0C5B48:
  li    $at, 6
  bne   $t7, $at, .L7F0C5E10
   nop   
  jal   get_textptr_for_textID
   li    $a0, 40992
  lui   $t5, %hi(ptrFirstFontTableSmall) 
  lw    $t5, %lo(ptrFirstFontTableSmall)($t5)
  lui   $a3, %hi(ptrSecondFontTableSmall)
  sw    $v0, 0xa4($sp)
  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
  addiu $a0, $sp, 0xbc
  addiu $a1, $sp, 0xc0
  move  $a2, $v0
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t5, 0x10($sp)
  jal   get_video2_settings_ulx
   nop   
  lw    $t9, 0xa8($sp)
  lw    $t8, 0xc0($sp)
  addu  $t3, $v0, $t9
  sra   $t2, $t8, 1
  subu  $a0, $t3, $t2
  addiu $a0, $a0, 0x36
  jal   get_video2_settings_uly
   sw    $a0, 0xcc($sp)
  lw    $t6, 0xbc($sp)
  lui   $t5, %hi(pPlayer) 
  lw    $t5, %lo(pPlayer)($t5)
  sra   $t4, $t6, 1
  subu  $t1, $v0, $t4
  addiu $t7, $t1, 0x36
  sw    $t7, 0xc8($sp)
  lw    $t9, 0x29cc($t5)
  bnez  $t9, .L7F0C5C4C
   nop   
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s0, $v0, 0x10
  sra   $t8, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t8
  lui   $t3, %hi(ptrSecondFontTableSmall) 
  lui   $t2, %hi(ptrFirstFontTableSmall) 
  lw    $t2, %lo(ptrFirstFontTableSmall)($t2)
  lw    $t3, %lo(ptrSecondFontTableSmall)($t3)
  lui   $t6, (0xA0FFA0F0 >> 16) # lui $t6, 0xa0ff
  lui   $t4, (0x007000A0 >> 16) # lui $t4, 0x70
  ori   $t4, (0x007000A0 & 0xFFFF) # ori $t4, $t4, 0xa0
  ori   $t6, (0xA0FFA0F0 & 0xFFFF) # ori $t6, $t6, 0xa0f0
  sw    $t6, 0x18($sp)
  sw    $t4, 0x1c($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xcc
  addiu $a2, $sp, 0xc8
  lw    $a3, 0xa4($sp)
  sw    $s0, 0x20($sp)
  sw    $v0, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $zero, 0x2c($sp)
  sw    $t2, 0x14($sp)
  jal   jp_text_write_stuff
   sw    $t3, 0x10($sp)
  b     .L7F0C5CB0
   move  $s1, $v0
.L7F0C5C4C:
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s0, $v0, 0x10
  sra   $t1, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t1
  lui   $t7, %hi(ptrSecondFontTableSmall) 
  lui   $t5, %hi(ptrFirstFontTableSmall) 
  lw    $t5, %lo(ptrFirstFontTableSmall)($t5)
  lw    $t7, %lo(ptrSecondFontTableSmall)($t7)
  lui   $t9, (0x00FF00B0 >> 16) # lui $t9, 0xff
  ori   $t9, (0x00FF00B0 & 0xFFFF) # ori $t9, $t9, 0xb0
  sw    $t9, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xcc
  addiu $a2, $sp, 0xc8
  lw    $a3, 0xa4($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t5, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t7, 0x10($sp)
  move  $s1, $v0
.L7F0C5CB0:
  jal   get_textptr_for_textID
   li    $a0, 40993
  lui   $t8, %hi(ptrFirstFontTableSmall) 
  lw    $t8, %lo(ptrFirstFontTableSmall)($t8)
  lui   $a3, %hi(ptrSecondFontTableSmall)
  sw    $v0, 0xa4($sp)
  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
  addiu $a0, $sp, 0xbc
  addiu $a1, $sp, 0xc0
  move  $a2, $v0
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t8, 0x10($sp)
  jal   get_video2_settings_ulx
   nop   
  lw    $t3, 0xa8($sp)
  lw    $t6, 0xc0($sp)
  addu  $t2, $v0, $t3
  sra   $t4, $t6, 1
  subu  $a0, $t2, $t4
  addiu $a0, $a0, 0x68
  jal   get_video2_settings_uly
   sw    $a0, 0xcc($sp)
  lw    $t1, 0xbc($sp)
  lui   $t8, %hi(pPlayer) 
  lw    $t8, %lo(pPlayer)($t8)
  sra   $t7, $t1, 1
  subu  $t5, $v0, $t7
  addiu $t9, $t5, 0x36
  sw    $t9, 0xc8($sp)
  lw    $t3, 0x29cc($t8)
  li    $at, 1
  bne   $t3, $at, .L7F0C5DAC
   nop   
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s0, $v0, 0x10
  sra   $t6, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t6
  lui   $t2, %hi(ptrSecondFontTableSmall) 
  lui   $t4, %hi(ptrFirstFontTableSmall) 
  lw    $t4, %lo(ptrFirstFontTableSmall)($t4)
  lw    $t2, %lo(ptrSecondFontTableSmall)($t2)
  lui   $t1, (0xA0FFA0F0 >> 16) # lui $t1, 0xa0ff
  lui   $t7, (0x007000A0 >> 16) # lui $t7, 0x70
  ori   $t7, (0x007000A0 & 0xFFFF) # ori $t7, $t7, 0xa0
  ori   $t1, (0xA0FFA0F0 & 0xFFFF) # ori $t1, $t1, 0xa0f0
  sw    $t1, 0x18($sp)
  sw    $t7, 0x1c($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xcc
  addiu $a2, $sp, 0xc8
  lw    $a3, 0xa4($sp)
  sw    $s0, 0x20($sp)
  sw    $v0, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $zero, 0x2c($sp)
  sw    $t4, 0x14($sp)
  jal   jp_text_write_stuff
   sw    $t2, 0x10($sp)
  b     .L7F0C5E10
   move  $s1, $v0
.L7F0C5DAC:
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s0, $v0, 0x10
  sra   $t5, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t5
  lui   $t9, %hi(ptrSecondFontTableSmall) 
  lui   $t8, %hi(ptrFirstFontTableSmall) 
  lw    $t8, %lo(ptrFirstFontTableSmall)($t8)
  lw    $t9, %lo(ptrSecondFontTableSmall)($t9)
  lui   $t3, (0x00FF00B0 >> 16) # lui $t3, 0xff
  ori   $t3, (0x00FF00B0 & 0xFFFF) # ori $t3, $t3, 0xb0
  sw    $t3, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xcc
  addiu $a2, $sp, 0xc8
  lw    $a3, 0xa4($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t8, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t9, 0x10($sp)
  move  $s1, $v0
.L7F0C5E10:
  jal   combiner_bayer_lod_perspective
   move  $a0, $s1
  b     .L7F0C6030
   move  $s1, $v0
  lw    $t6, 0xd8($v1)
.L7F0C5E24:
  beql  $t6, $zero, .L7F0C6034
   move  $v0, $s1
  lw    $t2, 0x428($v1)
  beql  $t2, $zero, .L7F0C6034
   move  $v0, $s1
  lw    $t4, 0x424($v1)
  lui   $t1, %hi(stop_play_flag) 
  beql  $t4, $zero, .L7F0C6034
   move  $v0, $s1
  lw    $t1, %lo(stop_play_flag)($t1)
  lui   $t7, %hi(is_gameover_flag) 
  bnezl $t1, .L7F0C6034
   move  $v0, $s1
  lw    $t7, %lo(is_gameover_flag)($t7)
  move  $a0, $zero
  bnezl $t7, .L7F0C6034
   move  $v0, $s1
  blez  $v0, .L7F0C5F0C
   move  $a1, $zero
  andi  $a3, $v0, 3
  beqz  $a3, .L7F0C5EBC
   move  $a2, $a3
  lw    $t9, 0xd4($sp)
  sll   $t5, $zero, 3
  subu  $t5, $t5, $zero
  sll   $t5, $t5, 4
  lui   $t6, %hi(player1_player_data) 
  sll   $t8, $t9, 2
  addu  $t3, $t5, $t8
  addiu $t6, %lo(player1_player_data) # addiu $t6, $t6, -0x6110
  addu  $v1, $t3, $t6
.L7F0C5EA0:
  lw    $t2, 0x24($v1)
  addiu $a1, $a1, 1
  addiu $v1, $v1, 0x70
  bne   $a2, $a1, .L7F0C5EA0
   addu  $a0, $a0, $t2
  beq   $a1, $v0, .L7F0C5F0C
   nop   
.L7F0C5EBC:
  lw    $t1, 0xd4($sp)
  sll   $t4, $a1, 3
  subu  $t4, $t4, $a1
  sll   $t4, $t4, 4
  lui   $t5, %hi(player1_player_data) 
  sll   $t7, $t1, 2
  addu  $t9, $t4, $t7
  addiu $t5, %lo(player1_player_data) # addiu $t5, $t5, -0x6110
  addu  $v1, $t9, $t5
.L7F0C5EE0:
  lw    $t8, 0x24($v1)
  lw    $t3, 0x94($v1)
  lw    $t6, 0x104($v1)
  addu  $a0, $a0, $t8
  lw    $t2, 0x174($v1)
  addu  $a0, $a0, $t3
  addiu $a1, $a1, 4
  addu  $a0, $a0, $t6
  addiu $v1, $v1, 0x1c0
  bne   $a1, $t0, .L7F0C5EE0
   addu  $a0, $a0, $t2
.L7F0C5F0C:
  jal   get_scenario
   sw    $a0, 0x58($sp)
  li    $at, 1
  bne   $v0, $at, .L7F0C5F2C
   lw    $a0, 0x58($sp)
  slti  $at, $a0, 2
  beql  $at, $zero, .L7F0C6034
   move  $v0, $s1
.L7F0C5F2C:
  jal   sub_GAME_7F0B4FB4
   move  $a0, $s1
  jal   microcode_constructor
   move  $a0, $v0
  move  $s1, $v0
  jal   get_textptr_for_textID
   li    $a0, 40994
  lui   $t1, %hi(ptrFirstFontTableSmall) 
  lw    $t1, %lo(ptrFirstFontTableSmall)($t1)
  lui   $a3, %hi(ptrSecondFontTableSmall)
  sw    $v0, 0x60($sp)
  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
  addiu $a0, $sp, 0x64
  addiu $a1, $sp, 0x68
  move  $a2, $v0
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t1, 0x10($sp)
  jal   get_video2_settings_ulx
   nop   
  jal   get_video2_settings_width
   sh    $v0, 0x56($sp)
  lh    $v1, 0x56($sp)
  lw    $t5, 0x68($sp)
  sra   $t7, $v0, 1
  addu  $t9, $t7, $v1
  sra   $t8, $t5, 1
  subu  $t3, $t9, $t8
  jal   get_video2_settings_uly
   sw    $t3, 0x70($sp)
  jal   get_video2_settings_height
   sh    $v0, 0x56($sp)
  lh    $v1, 0x56($sp)
  lw    $t4, 0x64($sp)
  sra   $t2, $v0, 1
  addu  $t1, $t2, $v1
  sra   $t7, $t4, 1
  subu  $t5, $t1, $t7
  jal   get_video2_settings_txtClipW
   sw    $t5, 0x6c($sp)
  sll   $s0, $v0, 0x10
  sra   $t9, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t9
  lui   $t8, %hi(ptrSecondFontTableSmall) 
  lui   $t3, %hi(ptrFirstFontTableSmall) 
  lw    $t3, %lo(ptrFirstFontTableSmall)($t3)
  lw    $t8, %lo(ptrSecondFontTableSmall)($t8)
  lui   $t6, (0x00FF00B0 >> 16) # lui $t6, 0xff
  ori   $t6, (0x00FF00B0 & 0xFFFF) # ori $t6, $t6, 0xb0
  sw    $t6, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0x70
  addiu $a2, $sp, 0x6c
  lw    $a3, 0x60($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t3, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t8, 0x10($sp)
  jal   combiner_bayer_lod_perspective
   move  $a0, $v0
  move  $s1, $v0
.L7F0C6030:
  move  $v0, $s1
.L7F0C6034:
  lw    $ra, 0x3c($sp)
  lw    $s0, 0x34($sp)
  lw    $s1, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0xd8
");
#endif

#ifdef VERSION_JP
asm(R"
.late_rodata
/*jtbl hacks*/
.word not_yolt_tld

/*D:8005BD00*/
glabel jpt_MP_menu_window_text
.word text_play
.word text_play
.word text_play
.word text_play
.word text_pause_unpause
.word text_exit
.word text_exit
.word text_blank

.text
glabel mp_watch_menu_display
  addiu $sp, $sp, -0xd8
  sw    $ra, 0x3c($sp)
  sw    $s1, 0x38($sp)
  move  $s1, $a0
  jal   get_cur_playernum
   sw    $s0, 0x34($sp)
  jal   getPlayerCount
   sw    $v0, 0xd4($sp)
  li    $at, 1
  move  $t0, $v0
  bne   $v0, $at, .Ljp7F0C4D0C
   move  $s0, $zero
  b     .Ljp7F0C6D18
   move  $v0, $s1
.Ljp7F0C4D0C:
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  lw    $v1, %lo(pPlayer)($v1)
  move  $a0, $s1
  lw    $t6, 0x29c4($v1)
  beql  $t6, $zero, .Ljp7F0C6AD4
   lw    $t4, 0xd8($v1)
  jal   microcode_constructor
   sw    $t0, 0xd0($sp)
  lw    $t7, 0xd0($sp)
  li    $at, 2
  move  $s1, $v0
  bne   $t7, $at, .Ljp7F0C4D4C
   lui   $t9, %hi(pPlayer) # $t9, 0x8008
  li    $t8, 80
  b     .Ljp7F0C4D50
   sw    $t8, 0xa8($sp)
.Ljp7F0C4D4C:
  sw    $zero, 0xa8($sp)
.Ljp7F0C4D50:
  lw    $t9, %lo(pPlayer)($t9)
  lw    $t3, 0x29c8($t9)
  sltiu $at, $t3, 8
  beqz  $at, .Ljp7F0C4E40
   sll   $t3, $t3, 2
  lui   $at, %hi(jpt_MP_menu_window_text)
  addu  $at, $at, $t3
  lw    $t3, %lo(jpt_MP_menu_window_text)($at)
  jr    $t3
   nop   
text_play:
  lui   $t4, %hi(is_gameover_flag) # $t4, 0x8009
  lw    $t4, %lo(is_gameover_flag)($t4)
  lui   $t5, %hi(time_trigger_alt_gameover_msg) # $t5, 0x8009
  bnez  $t4, .Ljp7F0C4D9C
   nop   
  jal   get_textptr_for_textID
   li    $a0, 40981
  b     .Ljp7F0C4E40
   sw    $v0, 0xa4($sp)
.Ljp7F0C4D9C:
  lw    $t5, %lo(time_trigger_alt_gameover_msg)($t5)
  beqz  $t5, .Ljp7F0C4DB8
   nop   
  jal   get_textptr_for_textID
   li    $a0, 40982
  b     .Ljp7F0C4E40
   sw    $v0, 0xa4($sp)
.Ljp7F0C4DB8:
  jal   get_textptr_for_textID
   li    $a0, 40983
  b     .Ljp7F0C4E40
   sw    $v0, 0xa4($sp)
text_blank:
  lui   $t6, %hi(ascii_MP_watch_menu_BLANK) # $t6, 0x8006
  addiu $t6, %lo(ascii_MP_watch_menu_BLANK) # addiu $t6, $t6, -0x439c
  b     .Ljp7F0C4E40
   sw    $t6, 0xa4($sp)
text_pause_unpause:
  lui   $t7, %hi(is_paused) # $t7, 0x8009
  lw    $t7, %lo(is_paused)($t7)
  beqz  $t7, .Ljp7F0C4E10
   nop   
  jal   get_textptr_for_textID
   li    $a0, 40984
  jal   get_cur_playernum
   sw    $v0, 0xa4($sp)
  lui   $t8, %hi(who_paused) # $t8, 0x8009
  lw    $t8, %lo(who_paused)($t8)
  bne   $v0, $t8, .Ljp7F0C4E40
   nop   
  b     .Ljp7F0C4E40
   li    $s0, 1
.Ljp7F0C4E10:
  jal   get_textptr_for_textID
   li    $a0, 40985
  b     .Ljp7F0C4E40
   sw    $v0, 0xa4($sp)
text_exit:
  jal   get_textptr_for_textID
   li    $a0, 40986
  jal   get_video2_settings_ulx
   sw    $v0, 0xa4($sp)
  lw    $t9, 0xa8($sp)
  addu  $a0, $v0, $t9
  addiu $a0, $a0, 0x41
  sw    $a0, 0xcc($sp)
def_7F0C40C0:
.Ljp7F0C4E40:
  lui   $t3, %hi(ptrFirstFontTableSmall) # $t3, 0x8004
  lw    $t3, %lo(ptrFirstFontTableSmall)($t3)
  lui   $a3, %hi(ptrSecondFontTableSmall) # $a3, 0x8004
  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
  addiu $a0, $sp, 0xbc
  addiu $a1, $sp, 0xc0
  lw    $a2, 0xa4($sp)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t3, 0x10($sp)
  jal   get_video2_settings_ulx
   nop   
  lw    $t4, 0xa8($sp)
  lw    $t6, 0xc0($sp)
  addu  $t5, $v0, $t4
  sra   $t7, $t6, 1
  subu  $a0, $t5, $t7
  addiu $a0, $a0, 0x50
  jal   get_video2_settings_uly
   sw    $a0, 0xcc($sp)
  lw    $t8, 0xbc($sp)
  sra   $t9, $t8, 1
  subu  $t3, $v0, $t9
  addiu $t4, $t3, 0x16
  beqz  $s0, .Ljp7F0C4F1C
   sw    $t4, 0xc8($sp)
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s0, $v0, 0x10
  sra   $t6, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t6
  lui   $t5, %hi(ptrSecondFontTableSmall) # $t5, 0x8004
  lui   $t7, %hi(ptrFirstFontTableSmall) # $t7, 0x8004
  lw    $t7, %lo(ptrFirstFontTableSmall)($t7)
  lw    $t5, %lo(ptrSecondFontTableSmall)($t5)
  lui   $t8, (0xA0FFA0F0 >> 16) # lui $t8, 0xa0ff
  lui   $t9, (0x007000A0 >> 16) # lui $t9, 0x70
  ori   $t9, (0x007000A0 & 0xFFFF) # ori $t9, $t9, 0xa0
  ori   $t8, (0xA0FFA0F0 & 0xFFFF) # ori $t8, $t8, 0xa0f0
  sw    $t8, 0x18($sp)
  sw    $t9, 0x1c($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xcc
  addiu $a2, $sp, 0xc8
  lw    $a3, 0xa4($sp)
  sw    $s0, 0x20($sp)
  sw    $v0, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $zero, 0x2c($sp)
  sw    $t7, 0x14($sp)
  jal   jp_text_write_stuff
   sw    $t5, 0x10($sp)
  b     .Ljp7F0C4F80
   move  $s1, $v0
.Ljp7F0C4F1C:
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s0, $v0, 0x10
  sra   $t3, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t3
  lui   $t4, %hi(ptrSecondFontTableSmall) # $t4, 0x8004
  lui   $t6, %hi(ptrFirstFontTableSmall) # $t6, 0x8004
  lw    $t6, %lo(ptrFirstFontTableSmall)($t6)
  lw    $t4, %lo(ptrSecondFontTableSmall)($t4)
  lui   $t5, (0x00FF00B0 >> 16) # lui $t5, 0xff
  ori   $t5, (0x00FF00B0 & 0xFFFF) # ori $t5, $t5, 0xb0
  sw    $t5, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xcc
  addiu $a2, $sp, 0xc8
  lw    $a3, 0xa4($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t6, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t4, 0x10($sp)
  move  $s1, $v0
.Ljp7F0C4F80:
  jal   check_can_advance_left_on_mpmenu
   nop   
  beqz  $v0, .Ljp7F0C50E4
   nop   
  jal   get_video2_settings_ulx
   nop   
  lui   $v1, %hi(is_gameover_flag) # $v1, 0x8009
  lw    $v1, %lo(is_gameover_flag)($v1)
  sll   $t8, $v0, 0x10
  li    $t7, 10
  beql  $v1, $zero, .Ljp7F0C4FBC
   sw    $zero, 0x50($sp)
  b     .Ljp7F0C4FBC
   sw    $t7, 0x50($sp)
  sw    $zero, 0x50($sp)
.Ljp7F0C4FBC:
  lw    $t3, 0xa8($sp)
  lw    $t6, 0x50($sp)
  sra   $t9, $t8, 0x10
  addu  $t4, $t9, $t3
  subu  $a0, $t4, $t6
  addiu $a0, $a0, 0x28
  beqz  $v1, .Ljp7F0C4FE4
   sw    $a0, 0xcc($sp)
  addiu $a0, $a0, -8
  sw    $a0, 0xcc($sp)
.Ljp7F0C4FE4:
  jal   get_video2_settings_uly
   nop   
  lui   $t7, %hi(dword_CODE_bss_8008C708) # $t7, 0x8009
  lw    $t7, %lo(dword_CODE_bss_8008C708)($t7)
  addiu $t5, $v0, 0x16
  sw    $t5, 0xc8($sp)
  bnez  $t7, .Ljp7F0C5070
   nop   
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s0, $v0, 0x10
  sra   $t8, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t8
  lui   $t9, %hi(ptrSecondFontTableSmall) # $t9, 0x8004
  lui   $t3, %hi(ptrFirstFontTableSmall) # $t3, 0x8004
  lw    $t3, %lo(ptrFirstFontTableSmall)($t3)
  lw    $t9, %lo(ptrSecondFontTableSmall)($t9)
  lui   $t4, (0x00FF00B0 >> 16) # lui $t4, 0xff
  ori   $t4, (0x00FF00B0 & 0xFFFF) # ori $t4, $t4, 0xb0
  lui   $a3, %hi(ascii_MP_watch_menu_left_chevron) # $a3, 0x8006
  addiu $a3, %lo(ascii_MP_watch_menu_left_chevron) # addiu $a3, $a3, -0x4398
  sw    $t4, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xcc
  addiu $a2, $sp, 0xc8
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t3, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t9, 0x10($sp)
  b     .Ljp7F0C50E4
   move  $s1, $v0
.Ljp7F0C5070:
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s0, $v0, 0x10
  sra   $t6, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t6
  lui   $t5, %hi(ptrSecondFontTableSmall) # $t5, 0x8004
  lui   $t7, %hi(ptrFirstFontTableSmall) # $t7, 0x8004
  lw    $t7, %lo(ptrFirstFontTableSmall)($t7)
  lw    $t5, %lo(ptrSecondFontTableSmall)($t5)
  lui   $t8, (0xA0FFA0F0 >> 16) # lui $t8, 0xa0ff
  lui   $t9, (0x007000A0 >> 16) # lui $t9, 0x70
  ori   $t9, (0x007000A0 & 0xFFFF) # ori $t9, $t9, 0xa0
  ori   $t8, (0xA0FFA0F0 & 0xFFFF) # ori $t8, $t8, 0xa0f0
  lui   $a3, %hi(ascii_MP_watch_menu_left_chevron) # $a3, 0x8006
  addiu $a3, %lo(ascii_MP_watch_menu_left_chevron) # addiu $a3, $a3, -0x4398
  sw    $t8, 0x18($sp)
  sw    $t9, 0x1c($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xcc
  addiu $a2, $sp, 0xc8
  sw    $s0, 0x20($sp)
  sw    $v0, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $zero, 0x2c($sp)
  sw    $t7, 0x14($sp)
  jal   jp_text_write_stuff
   sw    $t5, 0x10($sp)
  move  $s1, $v0
.Ljp7F0C50E4:
  jal   check_can_advance_right_on_mpmenu
   nop   
  beqz  $v0, .Ljp7F0C5248
   nop   
  jal   get_video2_settings_ulx
   nop   
  lui   $v1, %hi(is_gameover_flag) # $v1, 0x8009
  lw    $v1, %lo(is_gameover_flag)($v1)
  sll   $t6, $v0, 0x10
  li    $t3, 10
  beql  $v1, $zero, .Ljp7F0C5120
   sw    $zero, 0x50($sp)
  b     .Ljp7F0C5120
   sw    $t3, 0x50($sp)
  sw    $zero, 0x50($sp)
.Ljp7F0C5120:
  lw    $t4, 0x50($sp)
  lw    $t8, 0xa8($sp)
  sra   $t5, $t6, 0x10
  addu  $t7, $t4, $t5
  addu  $a0, $t7, $t8
  addiu $a0, $a0, 0x70
  beqz  $v1, .Ljp7F0C5148
   sw    $a0, 0xcc($sp)
  addiu $a0, $a0, 8
  sw    $a0, 0xcc($sp)
.Ljp7F0C5148:
  jal   get_video2_settings_uly
   nop   
  lui   $t3, %hi(dword_CODE_bss_8008C708) # $t3, 0x8009
  lw    $t3, %lo(dword_CODE_bss_8008C708)($t3)
  addiu $t9, $v0, 0x16
  sw    $t9, 0xc8($sp)
  bnez  $t3, .Ljp7F0C51D4
   nop   
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s0, $v0, 0x10
  sra   $t6, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t6
  lui   $t4, %hi(ptrSecondFontTableSmall) # $t4, 0x8004
  lui   $t5, %hi(ptrFirstFontTableSmall) # $t5, 0x8004
  lw    $t5, %lo(ptrFirstFontTableSmall)($t5)
  lw    $t4, %lo(ptrSecondFontTableSmall)($t4)
  lui   $t7, (0x00FF00B0 >> 16) # lui $t7, 0xff
  ori   $t7, (0x00FF00B0 & 0xFFFF) # ori $t7, $t7, 0xb0
  lui   $a3, %hi(ascii_MP_watch_menu_right_chevron) # $a3, 0x8006
  addiu $a3, %lo(ascii_MP_watch_menu_right_chevron) # addiu $a3, $a3, -0x4394
  sw    $t7, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xcc
  addiu $a2, $sp, 0xc8
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t5, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t4, 0x10($sp)
  b     .Ljp7F0C5248
   move  $s1, $v0
.Ljp7F0C51D4:
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s0, $v0, 0x10
  sra   $t8, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t8
  lui   $t9, %hi(ptrSecondFontTableSmall) # $t9, 0x8004
  lui   $t3, %hi(ptrFirstFontTableSmall) # $t3, 0x8004
  lw    $t3, %lo(ptrFirstFontTableSmall)($t3)
  lw    $t9, %lo(ptrSecondFontTableSmall)($t9)
  lui   $t6, (0xA0FFA0F0 >> 16) # lui $t6, 0xa0ff
  lui   $t4, (0x007000A0 >> 16) # lui $t4, 0x70
  ori   $t4, (0x007000A0 & 0xFFFF) # ori $t4, $t4, 0xa0
  ori   $t6, (0xA0FFA0F0 & 0xFFFF) # ori $t6, $t6, 0xa0f0
  lui   $a3, %hi(ascii_MP_watch_menu_right_chevron) # $a3, 0x8006
  addiu $a3, %lo(ascii_MP_watch_menu_right_chevron) # addiu $a3, $a3, -0x4394
  sw    $t6, 0x18($sp)
  sw    $t4, 0x1c($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xcc
  addiu $a2, $sp, 0xc8
  sw    $s0, 0x20($sp)
  sw    $v0, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $zero, 0x2c($sp)
  sw    $t3, 0x14($sp)
  jal   jp_text_write_stuff
   sw    $t9, 0x10($sp)
  move  $s1, $v0
.Ljp7F0C5248:
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  lw    $v1, %lo(pPlayer)($v1)
  li    $at, 3
  lw    $t5, 0xd0($sp)
  lw    $v0, 0x29c8($v1)
  beq   $v0, $at, .Ljp7F0C526C
   li    $at, 4
  bnel  $v0, $at, .Ljp7F0C5910
   li    $at, 2
.Ljp7F0C526C:
  blez  $t5, .Ljp7F0C52A4
   move  $a0, $zero
  addiu $v1, $sp, 0x94
  sw    $v1, 0x44($sp)
.Ljp7F0C527C:
  jal   get_points_for_mp_player
   sw    $a0, 0x90($sp)
  lw    $v1, 0x44($sp)
  lw    $a0, 0x90($sp)
  sw    $v0, ($v1)
  lw    $t7, 0xd0($sp)
  addiu $a0, $a0, 1
  addiu $v1, $v1, 4
  bnel  $a0, $t7, .Ljp7F0C527C
   sw    $v1, 0x44($sp)
.Ljp7F0C52A4:
  lui   $a0, %hi(is_gameover_flag) # $a0, 0x8009
  lw    $a0, %lo(is_gameover_flag)($a0)
  sltiu $t8, $a0, 1
  beqz  $t8, .Ljp7F0C52C8
   move  $a0, $t8
  lui   $a0, %hi(stop_play_flag) # $a0, 0x8009
  lw    $a0, %lo(stop_play_flag)($a0)
  sltiu $t9, $a0, 1
  move  $a0, $t9
.Ljp7F0C52C8:
  jal   true_if_displaying_rank_in_mp
   nop   
  beqz  $v0, .Ljp7F0C53A4
   addiu $a0, $sp, 0xac
  jal   write_playerrank_to_buffer
   lw    $a1, 0xd4($sp)
  lui   $t3, %hi(ptrFirstFontTableSmall) # $t3, 0x8004
  lw    $t3, %lo(ptrFirstFontTableSmall)($t3)
  lui   $a3, %hi(ptrSecondFontTableSmall) # $a3, 0x8004
  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
  addiu $a0, $sp, 0xbc
  addiu $a1, $sp, 0xc0
  addiu $a2, $sp, 0xac
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t3, 0x10($sp)
  jal   get_video2_settings_ulx
   nop   
  lw    $t6, 0xa8($sp)
  lw    $t5, 0xc0($sp)
  addu  $t4, $v0, $t6
  sra   $t7, $t5, 1
  subu  $a0, $t4, $t7
  addiu $a0, $a0, 0x50
  jal   get_video2_settings_uly
   sw    $a0, 0xcc($sp)
  lw    $t8, 0xbc($sp)
  sra   $t9, $t8, 1
  subu  $t3, $v0, $t9
  addiu $t6, $t3, 0x25
  jal   get_video2_settings_txtClipW
   sw    $t6, 0xc8($sp)
  sll   $s0, $v0, 0x10
  sra   $t5, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t5
  lui   $t4, %hi(ptrSecondFontTableSmall) # $t4, 0x8004
  lui   $t7, %hi(ptrFirstFontTableSmall) # $t7, 0x8004
  lw    $t7, %lo(ptrFirstFontTableSmall)($t7)
  lw    $t4, %lo(ptrSecondFontTableSmall)($t4)
  lui   $t8, (0x00FF00B0 >> 16) # lui $t8, 0xff
  ori   $t8, (0x00FF00B0 & 0xFFFF) # ori $t8, $t8, 0xb0
  sw    $t8, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xcc
  addiu $a2, $sp, 0xc8
  addiu $a3, $sp, 0xac
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t7, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t4, 0x10($sp)
  move  $s1, $v0
.Ljp7F0C53A4:
  lui   $a0, %hi(is_gameover_flag) # $a0, 0x8009
  lw    $a0, %lo(is_gameover_flag)($a0)
  sltiu $t9, $a0, 1
  beqz  $t9, .Ljp7F0C53C8
   move  $a0, $t9
  lui   $a0, %hi(stop_play_flag) # $a0, 0x8009
  lw    $a0, %lo(stop_play_flag)($a0)
  sltiu $t3, $a0, 1
  move  $a0, $t3
.Ljp7F0C53C8:
  jal   true_if_displaying_score_in_mp
   nop   
  beqz  $v0, .Ljp7F0C5900
   nop   
  jal   get_scenario
   nop   
  sw    $v0, 0x80($sp)
  jal   get_textptr_for_textID
   li    $a0, 40987
  lui   $t6, %hi(ptrFirstFontTableSmall) # $t6, 0x8004
  lw    $t6, %lo(ptrFirstFontTableSmall)($t6)
  lui   $a3, %hi(ptrSecondFontTableSmall) # $a3, 0x8004
  sw    $v0, 0xa4($sp)
  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
  addiu $a0, $sp, 0xbc
  addiu $a1, $sp, 0xc0
  move  $a2, $v0
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t6, 0x10($sp)
  jal   get_video2_settings_ulx
   nop   
  lw    $t5, 0xa8($sp)
  lw    $t7, 0xc0($sp)
  addu  $t4, $v0, $t5
  sra   $t8, $t7, 1
  subu  $a0, $t4, $t8
  addiu $a0, $a0, 0x50
  jal   get_video2_settings_uly
   sw    $a0, 0xcc($sp)
  lw    $t9, 0xbc($sp)
  sra   $t3, $t9, 1
  subu  $t6, $v0, $t3
  addiu $t5, $t6, 0x35
  jal   get_video2_settings_txtClipW
   sw    $t5, 0xc8($sp)
  sll   $s0, $v0, 0x10
  sra   $t7, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t7
  lui   $t4, %hi(ptrSecondFontTableSmall) # $t4, 0x8004
  lui   $t8, %hi(ptrFirstFontTableSmall) # $t8, 0x8004
  lw    $t8, %lo(ptrFirstFontTableSmall)($t8)
  lw    $t4, %lo(ptrSecondFontTableSmall)($t4)
  lui   $t9, (0x00FF00B0 >> 16) # lui $t9, 0xff
  ori   $t9, (0x00FF00B0 & 0xFFFF) # ori $t9, $t9, 0xb0
  sw    $t9, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xcc
  addiu $a2, $sp, 0xc8
  lw    $a3, 0xa4($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t8, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t4, 0x10($sp)
  lw    $v1, 0x80($sp)
  li    $at, 5
  move  $s1, $v0
  beq   $v1, $at, .Ljp7F0C54E8
   lw    $t3, 0xd4($sp)
  li    $at, 6
  beq   $v1, $at, .Ljp7F0C54E8
   li    $at, 7
  beq   $v1, $at, .Ljp7F0C54E8
   li    $at, 2
  beq   $v1, $at, .Ljp7F0C54E8
   li    $at, 3
  bne   $v1, $at, .Ljp7F0C553C
   li    $t5, 1
.Ljp7F0C54E8:
  sll   $t6, $t3, 3
  subu  $t6, $t6, $t3
  sll   $t6, $t6, 4
  lui   $t5, %hi(player1_player_data+105)
  addu  $t5, $t5, $t6
  lbu   $t5, %lo(player1_player_data+105)($t5)
  li    $t9, 5
  li    $t3, 4
  bnez  $t5, .Ljp7F0C552C
   li    $t6, 2
  li    $t7, 3
  li    $t4, 2
  li    $t8, 4
  sw    $t7, 0x8c($sp)
  sw    $t4, 0x88($sp)
  b     .Ljp7F0C5548
   sw    $t8, 0x84($sp)
.Ljp7F0C552C:
  sw    $t9, 0x8c($sp)
  sw    $t3, 0x88($sp)
  b     .Ljp7F0C5548
   sw    $t6, 0x84($sp)
.Ljp7F0C553C:
  sw    $t5, 0x8c($sp)
  sw    $zero, 0x88($sp)
  sw    $zero, 0x84($sp)
.Ljp7F0C5548:
  lw    $t7, 0xd0($sp)
  li    $at, 2
  bne   $t7, $at, .Ljp7F0C568C
   nop   
  jal   get_video2_settings_ulx
   nop   
  sll   $s0, $v0, 0x10
  sra   $t4, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t4
  lw    $v1, 0xd4($sp)
  sll   $t0, $v0, 0x10
  sra   $t8, $t0, 0x10
  bnez  $v1, .Ljp7F0C5590
   move  $t0, $t8
  lw    $t9, 0x8c($sp)
  b     .Ljp7F0C55C8
   sw    $t9, 0x50($sp)
.Ljp7F0C5590:
  sll   $t6, $v1, 3
  subu  $t6, $t6, $v1
  sll   $t6, $t6, 4
  lui   $t5, %hi(player1_player_data + 0x69)
  addu  $t5, $t5, $t6
  lui   $t3, %hi(player1_player_data + 0x69) # $t3, 0x8008
  lbu   $t3, %lo(player1_player_data + 0x69)($t3)
  lbu   $t5, %lo(player1_player_data + 0x69)($t5)
  lw    $a2, 0x84($sp)
  bne   $t3, $t5, .Ljp7F0C55C4
   nop   
  b     .Ljp7F0C55C4
   lw    $a2, 0x88($sp)
.Ljp7F0C55C4:
  sw    $a2, 0x50($sp)
.Ljp7F0C55C8:
  lw    $t7, 0xa8($sp)
  lw    $t4, 0x50($sp)
  move  $a0, $s1
  addu  $a1, $s0, $t7
  addiu $a1, $a1, 0x50
  addiu $a2, $t0, 0x46
  lw    $a3, 0x94($sp)
  jal   display_text_for_playerdata_on_MP_menu
   sw    $t4, 0x10($sp)
  jal   get_video2_settings_ulx
   move  $s1, $v0
  sll   $s0, $v0, 0x10
  sra   $t8, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t8
  lw    $v1, 0xd4($sp)
  sll   $t0, $v0, 0x10
  sra   $t9, $t0, 0x10
  li    $at, 1
  bne   $v1, $at, .Ljp7F0C5628
   move  $t0, $t9
  lw    $t6, 0x8c($sp)
  b     .Ljp7F0C5660
   sw    $t6, 0x50($sp)
.Ljp7F0C5628:
  sll   $t5, $v1, 3
  subu  $t5, $t5, $v1
  lui   $v0, %hi(player1_player_data) # $v0, 0x8008
  addiu $v0, %lo(player1_player_data) # addiu $v0, $v0, -0x60a0
  sll   $t5, $t5, 4
  addu  $t7, $v0, $t5
  lbu   $t4, 0x69($t7)
  lbu   $t3, 0xd9($v0)
  lw    $a2, 0x84($sp)
  bne   $t3, $t4, .Ljp7F0C565C
   nop   
  b     .Ljp7F0C565C
   lw    $a2, 0x88($sp)
.Ljp7F0C565C:
  sw    $a2, 0x50($sp)
.Ljp7F0C5660:
  lw    $t8, 0xa8($sp)
  lw    $t9, 0x50($sp)
  move  $a0, $s1
  addu  $a1, $s0, $t8
  addiu $a1, $a1, 0x50
  addiu $a2, $t0, 0x56
  lw    $a3, 0x98($sp)
  jal   display_text_for_playerdata_on_MP_menu
   sw    $t9, 0x10($sp)
  b     .Ljp7F0C5900
   move  $s1, $v0
.Ljp7F0C568C:
  jal   get_video2_settings_ulx
   nop   
  sll   $s0, $v0, 0x10
  sra   $t6, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t6
  lw    $v1, 0xd4($sp)
  sll   $t0, $v0, 0x10
  sra   $t5, $t0, 0x10
  bnez  $v1, .Ljp7F0C56C4
   move  $t0, $t5
  lw    $t7, 0x8c($sp)
  b     .Ljp7F0C56FC
   sw    $t7, 0x50($sp)
.Ljp7F0C56C4:
  sll   $t4, $v1, 3
  subu  $t4, $t4, $v1
  sll   $t4, $t4, 4
  lui   $t8, %hi(player1_player_data + 0x69)
  addu  $t8, $t8, $t4
  lui   $t3, %hi(player1_player_data + 0x69) # $t3, 0x8008
  lbu   $t3, %lo(player1_player_data + 0x69)($t3)
  lbu   $t8, %lo(player1_player_data + 0x69)($t8)
  lw    $a2, 0x84($sp)
  bne   $t3, $t8, .Ljp7F0C56F8
   nop   
  b     .Ljp7F0C56F8
   lw    $a2, 0x88($sp)
.Ljp7F0C56F8:
  sw    $a2, 0x50($sp)
.Ljp7F0C56FC:
  lw    $t9, 0xa8($sp)
  lw    $t6, 0x50($sp)
  move  $a0, $s1
  addu  $a1, $s0, $t9
  addiu $a1, $a1, 0x40
  addiu $a2, $t0, 0x46
  lw    $a3, 0x94($sp)
  jal   display_text_for_playerdata_on_MP_menu
   sw    $t6, 0x10($sp)
  jal   get_video2_settings_ulx
   move  $s1, $v0
  sll   $s0, $v0, 0x10
  sra   $t5, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t5
  lw    $v1, 0xd4($sp)
  sll   $t0, $v0, 0x10
  sra   $t7, $t0, 0x10
  li    $at, 1
  bne   $v1, $at, .Ljp7F0C575C
   move  $t0, $t7
  lw    $t4, 0x8c($sp)
  b     .Ljp7F0C5794
   sw    $t4, 0x50($sp)
.Ljp7F0C575C:
  sll   $t8, $v1, 3
  subu  $t8, $t8, $v1
  sll   $t8, $t8, 4
  lui   $t9, %hi(player1_player_data + 0x69)
  addu  $t9, $t9, $t8
  lui   $t3, %hi(player2_player_data + 0x69) # $t3, 0x8008
  lbu   $t3, %lo(player2_player_data + 0x69)($t3)
  lbu   $t9, %lo(player1_player_data + 0x69)($t9)
  lw    $a2, 0x84($sp)
  bne   $t3, $t9, .Ljp7F0C5790
   nop   
  b     .Ljp7F0C5790
   lw    $a2, 0x88($sp)
.Ljp7F0C5790:
  sw    $a2, 0x50($sp)
.Ljp7F0C5794:
  lw    $t6, 0xa8($sp)
  lw    $t5, 0x50($sp)
  move  $a0, $s1
  addu  $a1, $s0, $t6
  addiu $a1, $a1, 0x60
  addiu $a2, $t0, 0x46
  lw    $a3, 0x98($sp)
  jal   display_text_for_playerdata_on_MP_menu
   sw    $t5, 0x10($sp)
  jal   get_video2_settings_ulx
   move  $s1, $v0
  sll   $s0, $v0, 0x10
  sra   $t7, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t7
  lw    $v1, 0xd4($sp)
  sll   $t0, $v0, 0x10
  sra   $t4, $t0, 0x10
  li    $at, 2
  bne   $v1, $at, .Ljp7F0C57F4
   move  $t0, $t4
  lw    $t8, 0x8c($sp)
  b     .Ljp7F0C582C
   sw    $t8, 0x50($sp)
.Ljp7F0C57F4:
  sll   $t9, $v1, 3
  subu  $t9, $t9, $v1
  sll   $t9, $t9, 4
  lui   $t6, %hi(player1_player_data + 0x69)
  addu  $t6, $t6, $t9
  lui   $t3, %hi(player3_player_data + 0x69) # $t3, 0x8008
  lbu   $t3, %lo(player3_player_data + 0x69)($t3)
  lbu   $t6, %lo(player1_player_data + 0x69)($t6)
  lw    $a2, 0x84($sp)
  bne   $t3, $t6, .Ljp7F0C5828
   nop   
  b     .Ljp7F0C5828
   lw    $a2, 0x88($sp)
.Ljp7F0C5828:
  sw    $a2, 0x50($sp)
.Ljp7F0C582C:
  lw    $t5, 0xa8($sp)
  lw    $t7, 0x50($sp)
  move  $a0, $s1
  addu  $a1, $s0, $t5
  addiu $a1, $a1, 0x40
  addiu $a2, $t0, 0x56
  lw    $a3, 0x9c($sp)
  jal   display_text_for_playerdata_on_MP_menu
   sw    $t7, 0x10($sp)
  lw    $t4, 0xd0($sp)
  li    $at, 4
  move  $s1, $v0
  bne   $t4, $at, .Ljp7F0C5900
   nop   
  jal   get_video2_settings_ulx
   nop   
  sll   $s0, $v0, 0x10
  sra   $t8, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t8
  lw    $v1, 0xd4($sp)
  sll   $t0, $v0, 0x10
  sra   $t9, $t0, 0x10
  li    $at, 3
  bne   $v1, $at, .Ljp7F0C58A0
   move  $t0, $t9
  lw    $t3, 0x8c($sp)
  b     .Ljp7F0C58D8
   sw    $t3, 0x50($sp)
.Ljp7F0C58A0:
  sll   $t5, $v1, 3
  subu  $t5, $t5, $v1
  lui   $v0, %hi(player1_player_data) # $v0, 0x8008
  addiu $v0, %lo(player1_player_data) # addiu $v0, $v0, -0x60a0
  sll   $t5, $t5, 4
  addu  $t7, $v0, $t5
  lbu   $t4, 0x69($t7)
  lbu   $t6, 0x1b9($v0)
  lw    $a2, 0x84($sp)
  bne   $t6, $t4, .Ljp7F0C58D4
   nop   
  b     .Ljp7F0C58D4
   lw    $a2, 0x88($sp)
.Ljp7F0C58D4:
  sw    $a2, 0x50($sp)
.Ljp7F0C58D8:
  lw    $t8, 0xa8($sp)
  lw    $t9, 0x50($sp)
  move  $a0, $s1
  addu  $a1, $s0, $t8
  addiu $a1, $a1, 0x60
  addiu $a2, $t0, 0x56
  lw    $a3, 0xa0($sp)
  jal   display_text_for_playerdata_on_MP_menu
   sw    $t9, 0x10($sp)
  move  $s1, $v0
.Ljp7F0C5900:
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  b     .Ljp7F0C67F4
   lw    $v1, %lo(pPlayer)($v1)
  li    $at, 2
.Ljp7F0C5910:
  bne   $v0, $at, .Ljp7F0C5D84
   lui   $a0, %hi(is_gameover_flag) # $a0, 0x8009
  lw    $a0, %lo(is_gameover_flag)($a0)
  sltiu $t3, $a0, 1
  beqz  $t3, .Ljp7F0C5938
   move  $a0, $t3
  lui   $a0, %hi(stop_play_flag) # $a0, 0x8009
  lw    $a0, %lo(stop_play_flag)($a0)
  sltiu $t5, $a0, 1
  move  $a0, $t5
.Ljp7F0C5938:
  jal   true_if_displaying_rank_in_mp
   nop   
  beqz  $v0, .Ljp7F0C5A14
   addiu $a0, $sp, 0xac
  jal   write_playerrank_to_buffer
   lw    $a1, 0xd4($sp)
  lui   $t7, %hi(ptrFirstFontTableSmall) # $t7, 0x8004
  lw    $t7, %lo(ptrFirstFontTableSmall)($t7)
  lui   $a3, %hi(ptrSecondFontTableSmall) # $a3, 0x8004
  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
  addiu $a0, $sp, 0xbc
  addiu $a1, $sp, 0xc0
  addiu $a2, $sp, 0xac
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t7, 0x10($sp)
  jal   get_video2_settings_ulx
   nop   
  lw    $t6, 0xa8($sp)
  lw    $t8, 0xc0($sp)
  addu  $t4, $v0, $t6
  sra   $t9, $t8, 1
  subu  $a0, $t4, $t9
  addiu $a0, $a0, 0x50
  jal   get_video2_settings_uly
   sw    $a0, 0xcc($sp)
  lw    $t3, 0xbc($sp)
  sra   $t5, $t3, 1
  subu  $t7, $v0, $t5
  addiu $t6, $t7, 0x25
  jal   get_video2_settings_txtClipW
   sw    $t6, 0xc8($sp)
  sll   $s0, $v0, 0x10
  sra   $t8, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t8
  lui   $t4, %hi(ptrSecondFontTableSmall) # $t4, 0x8004
  lui   $t9, %hi(ptrFirstFontTableSmall) # $t9, 0x8004
  lw    $t9, %lo(ptrFirstFontTableSmall)($t9)
  lw    $t4, %lo(ptrSecondFontTableSmall)($t4)
  lui   $t3, (0x00FF00B0 >> 16) # lui $t3, 0xff
  ori   $t3, (0x00FF00B0 & 0xFFFF) # ori $t3, $t3, 0xb0
  sw    $t3, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xcc
  addiu $a2, $sp, 0xc8
  addiu $a3, $sp, 0xac
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t9, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t4, 0x10($sp)
  move  $s1, $v0
.Ljp7F0C5A14:
  jal   get_textptr_for_textID
   li    $a0, 40988
  li    $a0, 40989
  jal   get_textptr_for_textID
   sw    $v0, 0x4c($sp)
  lw    $a3, 0xd4($sp)
  lui   $a1, %hi(ascii_pnum_KILLS) # $a1, 0x8006
  addiu $a1, %lo(ascii_pnum_KILLS) # addiu $a1, $a1, -0x4390
  lw    $a2, 0x4c($sp)
  addiu $a0, $sp, 0xac
  sw    $v0, 0x10($sp)
  jal   sprintf
   addiu $a3, $a3, 1
  lui   $t5, %hi(ptrFirstFontTableSmall) # $t5, 0x8004
  lw    $t5, %lo(ptrFirstFontTableSmall)($t5)
  lui   $a3, %hi(ptrSecondFontTableSmall) # $a3, 0x8004
  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
  addiu $a0, $sp, 0xbc
  addiu $a1, $sp, 0xc0
  addiu $a2, $sp, 0xac
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t5, 0x10($sp)
  jal   get_video2_settings_ulx
   nop   
  lw    $t7, 0xa8($sp)
  lw    $t8, 0xc0($sp)
  addu  $t6, $v0, $t7
  sra   $t4, $t8, 1
  subu  $a0, $t6, $t4
  addiu $a0, $a0, 0x50
  jal   get_video2_settings_uly
   sw    $a0, 0xcc($sp)
  lw    $t9, 0xbc($sp)
  sra   $t3, $t9, 1
  subu  $t5, $v0, $t3
  addiu $t7, $t5, 0x35
  jal   get_video2_settings_txtClipW
   sw    $t7, 0xc8($sp)
  sll   $s0, $v0, 0x10
  sra   $t8, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t8
  lui   $t6, %hi(ptrSecondFontTableSmall) # $t6, 0x8004
  lui   $t4, %hi(ptrFirstFontTableSmall) # $t4, 0x8004
  lw    $t4, %lo(ptrFirstFontTableSmall)($t4)
  lw    $t6, %lo(ptrSecondFontTableSmall)($t6)
  lui   $t9, (0x00FF00B0 >> 16) # lui $t9, 0xff
  ori   $t9, (0x00FF00B0 & 0xFFFF) # ori $t9, $t9, 0xb0
  sw    $t9, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xcc
  addiu $a2, $sp, 0xc8
  addiu $a3, $sp, 0xac
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t4, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t6, 0x10($sp)
  lw    $t3, 0xd0($sp)
  move  $s1, $v0
  li    $at, 2
  bne   $t3, $at, .Ljp7F0C5BE4
   lw    $v0, 0xd4($sp)
  lw    $v0, 0xd4($sp)
  beql  $v0, $zero, .Ljp7F0C5B84
   li    $at, 1
  jal   get_video2_settings_ulx
   nop   
  sll   $s0, $v0, 0x10
  sra   $t5, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t5
  lw    $t8, 0xd4($sp)
  lw    $t7, 0xa8($sp)
  lui   $a3, %hi(player1_player_data+36)
  sll   $t6, $t8, 3
  subu  $t6, $t6, $t8
  sll   $t6, $t6, 4
  addu  $a3, $a3, $t6
  addu  $a1, $s0, $t7
  addiu $a1, $a1, 0x50
  lw    $a3, %lo(player1_player_data+36)($a3)
  move  $a0, $s1
  addiu $a2, $v0, 0x46
  jal   display_text_for_playerdata_on_MP_menu
   sw    $zero, 0x10($sp)
  move  $s1, $v0
  lw    $v0, 0xd4($sp)
  li    $at, 1
.Ljp7F0C5B84:
  beq   $v0, $at, .Ljp7F0C5D78
   sll   $t4, $v0, 3
  subu  $t4, $t4, $v0
  lui   $t9, %hi(player1_player_data) # $t9, 0x8008
  addiu $t9, %lo(player1_player_data) # addiu $t9, $t9, -0x60a0
  sll   $t4, $t4, 4
  addu  $t3, $t4, $t9
  jal   get_video2_settings_ulx
   sw    $t3, 0x44($sp)
  sll   $s0, $v0, 0x10
  sra   $t5, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t5
  lw    $t7, 0xa8($sp)
  lw    $t8, 0x44($sp)
  move  $a0, $s1
  addu  $a1, $s0, $t7
  lw    $a3, 0x28($t8)
  sw    $zero, 0x10($sp)
  addiu $a1, $a1, 0x50
  jal   display_text_for_playerdata_on_MP_menu
   addiu $a2, $v0, 0x56
  b     .Ljp7F0C5D78
   move  $s1, $v0
.Ljp7F0C5BE4:
  beql  $v0, $zero, .Ljp7F0C5C48
   li    $at, 1
  jal   get_video2_settings_ulx
   nop   
  sll   $s0, $v0, 0x10
  sra   $t6, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t6
  lw    $t9, 0xd4($sp)
  lw    $t4, 0xa8($sp)
  lui   $a3, %hi(player1_player_data+36)
  sll   $t3, $t9, 3
  subu  $t3, $t3, $t9
  sll   $t3, $t3, 4
  addu  $a3, $a3, $t3
  addu  $a1, $s0, $t4
  addiu $a1, $a1, 0x40
  lw    $a3, %lo(player1_player_data+36)($a3)
  move  $a0, $s1
  addiu $a2, $v0, 0x46
  jal   display_text_for_playerdata_on_MP_menu
   sw    $zero, 0x10($sp)
  move  $s1, $v0
  lw    $v0, 0xd4($sp)
  li    $at, 1
.Ljp7F0C5C48:
  beq   $v0, $at, .Ljp7F0C5CA8
   sll   $t5, $v0, 3
  subu  $t5, $t5, $v0
  lui   $t7, %hi(player1_player_data) # $t7, 0x8008
  addiu $t7, %lo(player1_player_data) # addiu $t7, $t7, -0x60a0
  sll   $t5, $t5, 4
  addu  $t8, $t5, $t7
  jal   get_video2_settings_ulx
   sw    $t8, 0x44($sp)
  sll   $s0, $v0, 0x10
  sra   $t6, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t6
  lw    $t4, 0xa8($sp)
  lw    $t9, 0x44($sp)
  move  $a0, $s1
  addu  $a1, $s0, $t4
  lw    $a3, 0x28($t9)
  sw    $zero, 0x10($sp)
  addiu $a1, $a1, 0x60
  jal   display_text_for_playerdata_on_MP_menu
   addiu $a2, $v0, 0x46
  move  $s1, $v0
  lw    $v0, 0xd4($sp)
.Ljp7F0C5CA8:
  li    $at, 2
  beq   $v0, $at, .Ljp7F0C5D0C
   sll   $t3, $v0, 3
  subu  $t3, $t3, $v0
  lui   $t5, %hi(player1_player_data) # $t5, 0x8008
  addiu $t5, %lo(player1_player_data) # addiu $t5, $t5, -0x60a0
  sll   $t3, $t3, 4
  addu  $t7, $t3, $t5
  jal   get_video2_settings_ulx
   sw    $t7, 0x44($sp)
  sll   $s0, $v0, 0x10
  sra   $t8, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t8
  lw    $t6, 0xa8($sp)
  lw    $t4, 0x44($sp)
  move  $a0, $s1
  addu  $a1, $s0, $t6
  lw    $a3, 0x2c($t4)
  sw    $zero, 0x10($sp)
  addiu $a1, $a1, 0x40
  jal   display_text_for_playerdata_on_MP_menu
   addiu $a2, $v0, 0x56
  move  $s1, $v0
  lw    $v0, 0xd4($sp)
.Ljp7F0C5D0C:
  lw    $t9, 0xd0($sp)
  li    $at, 4
  bne   $t9, $at, .Ljp7F0C5D78
   li    $at, 3
  beq   $v0, $at, .Ljp7F0C5D78
   sll   $t3, $v0, 3
  subu  $t3, $t3, $v0
  lui   $t5, %hi(player1_player_data) # $t5, 0x8008
  addiu $t5, %lo(player1_player_data) # addiu $t5, $t5, -0x60a0
  sll   $t3, $t3, 4
  addu  $t7, $t3, $t5
  jal   get_video2_settings_ulx
   sw    $t7, 0x44($sp)
  sll   $s0, $v0, 0x10
  sra   $t8, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t8
  lw    $t6, 0xa8($sp)
  lw    $t4, 0x44($sp)
  move  $a0, $s1
  addu  $a1, $s0, $t6
  lw    $a3, 0x30($t4)
  sw    $zero, 0x10($sp)
  addiu $a1, $a1, 0x60
  jal   display_text_for_playerdata_on_MP_menu
   addiu $a2, $v0, 0x56
  move  $s1, $v0
.Ljp7F0C5D78:
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  b     .Ljp7F0C67F4
   lw    $v1, %lo(pPlayer)($v1)
.Ljp7F0C5D84:
  li    $at, 1
  bne   $v0, $at, .Ljp7F0C6430
   lui   $a0, %hi(is_gameover_flag) # $a0, 0x8009
  lw    $a0, %lo(is_gameover_flag)($a0)
  sltiu $t9, $a0, 1
  beqz  $t9, .Ljp7F0C5DB0
   move  $a0, $t9
  lui   $a0, %hi(stop_play_flag) # $a0, 0x8009
  lw    $a0, %lo(stop_play_flag)($a0)
  sltiu $t3, $a0, 1
  move  $a0, $t3
.Ljp7F0C5DB0:
  jal   true_if_displaying_rank_in_mp
   nop   
  beqz  $v0, .Ljp7F0C5E8C
   addiu $a0, $sp, 0xac
  jal   write_playerrank_to_buffer
   lw    $a1, 0xd4($sp)
  lui   $t5, %hi(ptrFirstFontTableSmall) # $t5, 0x8004
  lw    $t5, %lo(ptrFirstFontTableSmall)($t5)
  lui   $a3, %hi(ptrSecondFontTableSmall) # $a3, 0x8004
  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
  addiu $a0, $sp, 0xbc
  addiu $a1, $sp, 0xc0
  addiu $a2, $sp, 0xac
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t5, 0x10($sp)
  jal   get_video2_settings_ulx
   nop   
  lw    $t7, 0xa8($sp)
  lw    $t6, 0xc0($sp)
  addu  $t8, $v0, $t7
  sra   $t4, $t6, 1
  subu  $a0, $t8, $t4
  addiu $a0, $a0, 0x50
  jal   get_video2_settings_uly
   sw    $a0, 0xcc($sp)
  lw    $t9, 0xbc($sp)
  sra   $t3, $t9, 1
  subu  $t5, $v0, $t3
  addiu $t7, $t5, 0x25
  jal   get_video2_settings_txtClipW
   sw    $t7, 0xc8($sp)
  sll   $s0, $v0, 0x10
  sra   $t6, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t6
  lui   $t8, %hi(ptrSecondFontTableSmall) # $t8, 0x8004
  lui   $t4, %hi(ptrFirstFontTableSmall) # $t4, 0x8004
  lw    $t4, %lo(ptrFirstFontTableSmall)($t4)
  lw    $t8, %lo(ptrSecondFontTableSmall)($t8)
  lui   $t9, (0x00FF00B0 >> 16) # lui $t9, 0xff
  ori   $t9, (0x00FF00B0 & 0xFFFF) # ori $t9, $t9, 0xb0
  sw    $t9, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xcc
  addiu $a2, $sp, 0xc8
  addiu $a3, $sp, 0xac
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t4, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t8, 0x10($sp)
  move  $s1, $v0
.Ljp7F0C5E8C:
  jal   get_textptr_for_textID
   li    $a0, 40988
  li    $a0, 40990
  jal   get_textptr_for_textID
   sw    $v0, 0x4c($sp)
  lw    $a3, 0xd4($sp)
  lui   $a1, %hi(ascii_pnum_LOSSES) # $a1, 0x8006
  addiu $a1, %lo(ascii_pnum_LOSSES) # addiu $a1, $a1, -0x4388
  lw    $a2, 0x4c($sp)
  addiu $a0, $sp, 0xac
  sw    $v0, 0x10($sp)
  jal   sprintf
   addiu $a3, $a3, 1
  lui   $t3, %hi(ptrFirstFontTableSmall) # $t3, 0x8004
  lw    $t3, %lo(ptrFirstFontTableSmall)($t3)
  lui   $a3, %hi(ptrSecondFontTableSmall) # $a3, 0x8004
  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
  addiu $a0, $sp, 0xbc
  addiu $a1, $sp, 0xc0
  addiu $a2, $sp, 0xac
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t3, 0x10($sp)
  jal   get_video2_settings_ulx
   nop   
  lw    $t5, 0xa8($sp)
  lw    $t6, 0xc0($sp)
  addu  $t7, $v0, $t5
  sra   $t8, $t6, 1
  subu  $a0, $t7, $t8
  addiu $a0, $a0, 0x50
  jal   get_video2_settings_uly
   sw    $a0, 0xcc($sp)
  lw    $t4, 0xbc($sp)
  sra   $t9, $t4, 1
  subu  $t3, $v0, $t9
  addiu $t5, $t3, 0x35
  jal   get_video2_settings_txtClipW
   sw    $t5, 0xc8($sp)
  sll   $s0, $v0, 0x10
  sra   $t6, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t6
  lui   $t7, %hi(ptrSecondFontTableSmall) # $t7, 0x8004
  lui   $t8, %hi(ptrFirstFontTableSmall) # $t8, 0x8004
  lw    $t8, %lo(ptrFirstFontTableSmall)($t8)
  lw    $t7, %lo(ptrSecondFontTableSmall)($t7)
  lui   $t4, (0xFF4040B0 >> 16) # lui $t4, 0xff40
  ori   $t4, (0xFF4040B0 & 0xFFFF) # ori $t4, $t4, 0x40b0
  sw    $t4, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xcc
  addiu $a2, $sp, 0xc8
  addiu $a3, $sp, 0xac
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t8, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t7, 0x10($sp)
  lw    $t9, 0xd0($sp)
  li    $at, 2
  move  $s1, $v0
  bne   $t9, $at, .Ljp7F0C6118
   lw    $t7, 0xd4($sp)
  lw    $v0, 0xd4($sp)
  lui   $t8, %hi(player1_player_data + 0x24) # $t8, 0x8008
  beqz  $v0, .Ljp7F0C5FF8
   nop   
  jal   get_video2_settings_ulx
   nop   
  sll   $s0, $v0, 0x10
  sra   $t3, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t3
  lw    $t6, 0xd4($sp)
  lw    $t5, 0xa8($sp)
  lui   $a3, %hi(player1_player_data+36)
  sll   $t7, $t6, 2
  addu  $a3, $a3, $t7
  addu  $a1, $s0, $t5
  addiu $a1, $a1, 0x50
  lw    $a3, %lo(player1_player_data+36)($a3)
  move  $a0, $s1
  addiu $a2, $v0, 0x46
  jal   display_text_for_playerdata_on_MP_menu
   sw    $zero, 0x10($sp)
  move  $s1, $v0
  b     .Ljp7F0C6058
   lw    $v0, 0xd4($sp)
.Ljp7F0C5FF8:
  lw    $t8, %lo(player1_player_data + 0x24)($t8)
  blezl $t8, .Ljp7F0C605C
   li    $at, 1
  jal   get_video2_settings_ulx
   nop   
  sll   $s0, $v0, 0x10
  sra   $t4, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t4
  lw    $t3, 0xd4($sp)
  lw    $t9, 0xa8($sp)
  lui   $a3, %hi(player1_player_data+36)
  sll   $t5, $t3, 2
  addu  $a3, $a3, $t5
  li    $t6, 3
  addu  $a1, $s0, $t9
  addiu $a1, $a1, 0x50
  sw    $t6, 0x10($sp)
  lw    $a3, %lo(player1_player_data+36)($a3)
  move  $a0, $s1
  jal   display_text_for_playerdata_on_MP_menu
   addiu $a2, $v0, 0x46
  move  $s1, $v0
  lw    $v0, 0xd4($sp)
.Ljp7F0C6058:
  li    $at, 1
.Ljp7F0C605C:
  beq   $v0, $at, .Ljp7F0C60B8
   lui   $t6, %hi(player2_player_data + 0x28) # $t6, 0x8008
  lui   $t8, %hi(player1_player_data) # $t8, 0x8008
  addiu $t8, %lo(player1_player_data) # addiu $t8, $t8, -0x60a0
  sll   $t7, $v0, 2
  addu  $t4, $t7, $t8
  jal   get_video2_settings_ulx
   sw    $t4, 0x44($sp)
  sll   $s0, $v0, 0x10
  sra   $t9, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t9
  lw    $t3, 0xa8($sp)
  lw    $t5, 0x44($sp)
  move  $a0, $s1
  addu  $a1, $s0, $t3
  lw    $a3, 0x94($t5)
  sw    $zero, 0x10($sp)
  addiu $a1, $a1, 0x50
  jal   display_text_for_playerdata_on_MP_menu
   addiu $a2, $v0, 0x56
  b     .Ljp7F0C6424
   move  $s1, $v0
.Ljp7F0C60B8:
  lw    $t6, %lo(player2_player_data + 0x28)($t6)
  lui   $t8, %hi(player1_player_data) # $t8, 0x8008
  addiu $t8, %lo(player1_player_data) # addiu $t8, $t8, -0x60a0
  blez  $t6, .Ljp7F0C6424
   sll   $t7, $v0, 2
  addu  $t4, $t7, $t8
  jal   get_video2_settings_ulx
   sw    $t4, 0x44($sp)
  sll   $s0, $v0, 0x10
  sra   $t9, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t9
  lw    $t3, 0xa8($sp)
  lw    $t5, 0x44($sp)
  li    $t6, 3
  addu  $a1, $s0, $t3
  lw    $a3, 0x94($t5)
  sw    $t6, 0x10($sp)
  addiu $a1, $a1, 0x50
  move  $a0, $s1
  jal   display_text_for_playerdata_on_MP_menu
   addiu $a2, $v0, 0x56
  b     .Ljp7F0C6424
   move  $s1, $v0
.Ljp7F0C6118:
  beqz  $t7, .Ljp7F0C6170
   lui   $t5, %hi(player1_player_data + 0x24) # $t5, 0x8008
  jal   get_video2_settings_ulx
   nop   
  sll   $s0, $v0, 0x10
  sra   $t8, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t8
  lw    $t9, 0xd4($sp)
  lw    $t4, 0xa8($sp)
  lui   $a3, %hi(player1_player_data+36)
  sll   $t3, $t9, 2
  addu  $a3, $a3, $t3
  addu  $a1, $s0, $t4
  addiu $a1, $a1, 0x40
  lw    $a3, %lo(player1_player_data+36)($a3)
  move  $a0, $s1
  addiu $a2, $v0, 0x46
  jal   display_text_for_playerdata_on_MP_menu
   sw    $zero, 0x10($sp)
  b     .Ljp7F0C61CC
   move  $s1, $v0
.Ljp7F0C6170:
  lw    $t5, %lo(player1_player_data + 0x24)($t5)
  blezl $t5, .Ljp7F0C61D0
   lw    $t3, 0xd4($sp)
  jal   get_video2_settings_ulx
   nop   
  sll   $s0, $v0, 0x10
  sra   $t6, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t6
  lw    $t8, 0xd4($sp)
  lw    $t7, 0xa8($sp)
  lui   $a3, %hi(player1_player_data+36)
  sll   $t4, $t8, 2
  addu  $a3, $a3, $t4
  li    $t9, 3
  addu  $a1, $s0, $t7
  addiu $a1, $a1, 0x40
  sw    $t9, 0x10($sp)
  lw    $a3, %lo(player1_player_data+36)($a3)
  move  $a0, $s1
  jal   display_text_for_playerdata_on_MP_menu
   addiu $a2, $v0, 0x46
  move  $s1, $v0
.Ljp7F0C61CC:
  lw    $t3, 0xd4($sp)
.Ljp7F0C61D0:
  li    $at, 1
  lui   $t6, %hi(player1_player_data) # $t6, 0x8008
  beq   $t3, $at, .Ljp7F0C622C
   sll   $t5, $t3, 2
  addiu $t6, %lo(player1_player_data) # addiu $t6, $t6, -0x60a0
  addu  $t7, $t5, $t6
  jal   get_video2_settings_ulx
   sw    $t7, 0x44($sp)
  sll   $s0, $v0, 0x10
  sra   $t8, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t8
  lw    $t4, 0xa8($sp)
  lw    $t9, 0x44($sp)
  move  $a0, $s1
  addu  $a1, $s0, $t4
  lw    $a3, 0x94($t9)
  sw    $zero, 0x10($sp)
  addiu $a1, $a1, 0x60
  jal   display_text_for_playerdata_on_MP_menu
   addiu $a2, $v0, 0x46
  b     .Ljp7F0C6290
   move  $s1, $v0
.Ljp7F0C622C:
  lui   $t3, %hi(player2_player_data + 0x28) # $t3, 0x8008
  lw    $t3, %lo(player2_player_data + 0x28)($t3)
  lw    $t5, 0xd4($sp)
  lui   $t7, %hi(player1_player_data) # $t7, 0x8008
  blez  $t3, .Ljp7F0C6290
   sll   $t6, $t5, 2
  addiu $t7, %lo(player1_player_data) # addiu $t7, $t7, -0x60a0
  addu  $t8, $t6, $t7
  jal   get_video2_settings_ulx
   sw    $t8, 0x44($sp)
  sll   $s0, $v0, 0x10
  sra   $t4, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t4
  lw    $t9, 0xa8($sp)
  lw    $t3, 0x44($sp)
  li    $t5, 3
  addu  $a1, $s0, $t9
  lw    $a3, 0x94($t3)
  sw    $t5, 0x10($sp)
  addiu $a1, $a1, 0x60
  move  $a0, $s1
  jal   display_text_for_playerdata_on_MP_menu
   addiu $a2, $v0, 0x46
  move  $s1, $v0
.Ljp7F0C6290:
  lw    $t6, 0xd4($sp)
  li    $at, 2
  lui   $t8, %hi(player1_player_data) # $t8, 0x8008
  beq   $t6, $at, .Ljp7F0C62F0
   sll   $t7, $t6, 2
  addiu $t8, %lo(player1_player_data) # addiu $t8, $t8, -0x60a0
  addu  $t4, $t7, $t8
  jal   get_video2_settings_ulx
   sw    $t4, 0x44($sp)
  sll   $s0, $v0, 0x10
  sra   $t9, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t9
  lw    $t3, 0xa8($sp)
  lw    $t5, 0x44($sp)
  move  $a0, $s1
  addu  $a1, $s0, $t3
  lw    $a3, 0x104($t5)
  sw    $zero, 0x10($sp)
  addiu $a1, $a1, 0x40
  jal   display_text_for_playerdata_on_MP_menu
   addiu $a2, $v0, 0x56
  b     .Ljp7F0C6354
   move  $s1, $v0
.Ljp7F0C62F0:
  lui   $t6, %hi(player3_player_data + 0x2C) # $t6, 0x8008
  lw    $t6, %lo(player3_player_data + 0x2C)($t6)
  lw    $t7, 0xd4($sp)
  lui   $t4, %hi(player1_player_data) # $t4, 0x8008
  blez  $t6, .Ljp7F0C6354
   sll   $t8, $t7, 2
  addiu $t4, %lo(player1_player_data) # addiu $t4, $t4, -0x60a0
  addu  $t9, $t8, $t4
  jal   get_video2_settings_ulx
   sw    $t9, 0x44($sp)
  sll   $s0, $v0, 0x10
  sra   $t3, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t3
  lw    $t5, 0xa8($sp)
  lw    $t6, 0x44($sp)
  li    $t7, 3
  addu  $a1, $s0, $t5
  lw    $a3, 0x104($t6)
  sw    $t7, 0x10($sp)
  addiu $a1, $a1, 0x40
  move  $a0, $s1
  jal   display_text_for_playerdata_on_MP_menu
   addiu $a2, $v0, 0x56
  move  $s1, $v0
.Ljp7F0C6354:
  lw    $t8, 0xd0($sp)
  li    $at, 4
  lw    $t4, 0xd4($sp)
  bne   $t8, $at, .Ljp7F0C6424
   li    $at, 3
  beq   $t4, $at, .Ljp7F0C63C0
   sll   $t9, $t4, 2
  lui   $t3, %hi(player1_player_data) # $t3, 0x8008
  addiu $t3, %lo(player1_player_data) # addiu $t3, $t3, -0x60a0
  addu  $t5, $t9, $t3
  jal   get_video2_settings_ulx
   sw    $t5, 0x44($sp)
  sll   $s0, $v0, 0x10
  sra   $t6, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t6
  lw    $t7, 0xa8($sp)
  lw    $t8, 0x44($sp)
  move  $a0, $s1
  addu  $a1, $s0, $t7
  lw    $a3, 0x174($t8)
  sw    $zero, 0x10($sp)
  addiu $a1, $a1, 0x60
  jal   display_text_for_playerdata_on_MP_menu
   addiu $a2, $v0, 0x56
  b     .Ljp7F0C6424
   move  $s1, $v0
.Ljp7F0C63C0:
  lui   $t4, %hi(player4_player_data+0x30) # $t4, 0x8008
  lw    $t4, %lo(player4_player_data+0x30)($t4)
  lw    $t9, 0xd4($sp)
  lui   $t5, %hi(player1_player_data) # $t5, 0x8008
  blez  $t4, .Ljp7F0C6424
   sll   $t3, $t9, 2
  addiu $t5, %lo(player1_player_data) # addiu $t5, $t5, -0x60a0
  addu  $t6, $t3, $t5
  jal   get_video2_settings_ulx
   sw    $t6, 0x44($sp)
  sll   $s0, $v0, 0x10
  sra   $t7, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t7
  lw    $t8, 0xa8($sp)
  lw    $t4, 0x44($sp)
  li    $t9, 3
  addu  $a1, $s0, $t8
  lw    $a3, 0x174($t4)
  sw    $t9, 0x10($sp)
  addiu $a1, $a1, 0x60
  move  $a0, $s1
  jal   display_text_for_playerdata_on_MP_menu
   addiu $a2, $v0, 0x56
  move  $s1, $v0
.Ljp7F0C6424:
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  b     .Ljp7F0C67F4
   lw    $v1, %lo(pPlayer)($v1)
.Ljp7F0C6430:
  bnezl $v0, .Ljp7F0C67F8
   lw    $t5, 0x29c8($v1)
  lw    $t5, 0xd0($sp)
  lw    $t3, 0xa8($sp)
  slti  $at, $t5, 3
  bnez  $at, .Ljp7F0C6470
   sw    $t3, 0x74($sp)
  lw    $t6, 0xd4($sp)
  lw    $t4, 0xa8($sp)
  addiu $t8, $t3, -7
  andi  $t7, $t6, 1
  beqz  $t7, .Ljp7F0C646C
   addiu $t9, $t4, 7
  b     .Ljp7F0C6470
   sw    $t8, 0x74($sp)
.Ljp7F0C646C:
  sw    $t9, 0x74($sp)
.Ljp7F0C6470:
  jal   get_textptr_for_textID
   li    $a0, 40991
  lui   $t5, %hi(ptrFirstFontTableSmall) # $t5, 0x8004
  lw    $t5, %lo(ptrFirstFontTableSmall)($t5)
  lui   $a3, %hi(ptrSecondFontTableSmall) # $a3, 0x8004
  sw    $v0, 0xa4($sp)
  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
  addiu $a0, $sp, 0x7c
  addiu $a1, $sp, 0x78
  move  $a2, $v0
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t5, 0x10($sp)
  jal   get_video2_settings_ulx
   nop   
  lw    $t6, 0x74($sp)
  lw    $t3, 0x78($sp)
  addu  $t7, $v0, $t6
  sra   $t8, $t3, 1
  subu  $a0, $t7, $t8
  addiu $a0, $a0, 0x50
  jal   get_video2_settings_uly
   sw    $a0, 0xcc($sp)
  lw    $t4, 0x7c($sp)
  sra   $t9, $t4, 1
  subu  $t5, $v0, $t9
  addiu $t6, $t5, 0x25
  jal   get_video2_settings_txtClipW
   sw    $t6, 0xc8($sp)
  sll   $s0, $v0, 0x10
  sra   $t3, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t3
  lui   $t7, %hi(ptrSecondFontTableSmall) # $t7, 0x8004
  lui   $t8, %hi(ptrFirstFontTableSmall) # $t8, 0x8004
  lw    $t8, %lo(ptrFirstFontTableSmall)($t8)
  lw    $t7, %lo(ptrSecondFontTableSmall)($t7)
  lui   $t4, (0x00FF00B0 >> 16) # lui $t4, 0xff
  ori   $t4, (0x00FF00B0 & 0xFFFF) # ori $t4, $t4, 0xb0
  sw    $t4, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xcc
  addiu $a2, $sp, 0xc8
  lw    $a3, 0xa4($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t8, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t7, 0x10($sp)
  move  $s1, $v0
  lw    $a0, 0xd4($sp)
  jal   getplayerfavoredweapon
   move  $a1, $zero
  lui   $t9, %hi(ptrFirstFontTableSmall) # $t9, 0x8004
  lw    $t9, %lo(ptrFirstFontTableSmall)($t9)
  lui   $a3, %hi(ptrSecondFontTableSmall) # $a3, 0x8004
  sw    $v0, 0xa4($sp)
  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
  addiu $a0, $sp, 0x7c
  addiu $a1, $sp, 0x78
  move  $a2, $v0
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t9, 0x10($sp)
  jal   get_video2_settings_ulx
   nop   
  lw    $t5, 0x74($sp)
  lw    $t3, 0x78($sp)
  addu  $t6, $v0, $t5
  sra   $t7, $t3, 1
  subu  $a0, $t6, $t7
  addiu $a0, $a0, 0x50
  jal   get_video2_settings_uly
   sw    $a0, 0xcc($sp)
  lui   $t4, %hi(j_text_trigger) # $t4, 0x8005
  lw    $t4, %lo(j_text_trigger)($t4)
  sll   $t0, $v0, 0x10
  sra   $t8, $t0, 0x10
  beqz  $t4, .Ljp7F0C65C0
   move  $t0, $t8
  b     .Ljp7F0C65C4
   li    $a0, 4
.Ljp7F0C65C0:
  move  $a0, $zero
.Ljp7F0C65C4:
  lw    $t5, 0x7c($sp)
  addu  $t9, $a0, $t0
  sra   $t3, $t5, 1
  subu  $t6, $t9, $t3
  addiu $t7, $t6, 0x35
  jal   get_video2_settings_txtClipW
   sw    $t7, 0xc8($sp)
  sll   $s0, $v0, 0x10
  sra   $t8, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t8
  lui   $t4, %hi(ptrSecondFontTableSmall) # $t4, 0x8004
  lui   $t5, %hi(ptrFirstFontTableSmall) # $t5, 0x8004
  lw    $t5, %lo(ptrFirstFontTableSmall)($t5)
  lw    $t4, %lo(ptrSecondFontTableSmall)($t4)
  lui   $t9, (0x00FF00B0 >> 16) # lui $t9, 0xff
  ori   $t9, (0x00FF00B0 & 0xFFFF) # ori $t9, $t9, 0xb0
  sw    $t9, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xcc
  addiu $a2, $sp, 0xc8
  lw    $a3, 0xa4($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t5, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t4, 0x10($sp)
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  lw    $v1, %lo(pPlayer)($v1)
  move  $s1, $v0
  addiu $a0, $sp, 0x7c
  lw    $t0, 0x2a10($v1)
  addiu $a1, $sp, 0x78
  lui   $a3, %hi(ptrSecondFontTableSmall) # $a3, 0x8004
  beqz  $t0, .Ljp7F0C671C
   move  $a2, $t0
  lui   $t3, %hi(ptrFirstFontTableSmall) # $t3, 0x8004
  lw    $t3, %lo(ptrFirstFontTableSmall)($t3)
  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
  sw    $zero, 0x14($sp)
  sw    $t0, 0xa4($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t3, 0x10($sp)
  jal   get_video2_settings_ulx
   nop   
  lw    $t6, 0x74($sp)
  lw    $t8, 0x78($sp)
  addu  $t7, $v0, $t6
  sra   $t4, $t8, 1
  subu  $a0, $t7, $t4
  addiu $a0, $a0, 0x50
  jal   get_video2_settings_uly
   sw    $a0, 0xcc($sp)
  lw    $t5, 0x7c($sp)
  sra   $t9, $t5, 1
  subu  $t3, $v0, $t9
  addiu $t6, $t3, 0x4b
  jal   get_video2_settings_txtClipW
   sw    $t6, 0xc8($sp)
  sll   $s0, $v0, 0x10
  sra   $t8, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t8
  lui   $t7, %hi(ptrSecondFontTableSmall) # $t7, 0x8004
  lui   $t4, %hi(ptrFirstFontTableSmall) # $t4, 0x8004
  lw    $t4, %lo(ptrFirstFontTableSmall)($t4)
  lw    $t7, %lo(ptrSecondFontTableSmall)($t7)
  lui   $t5, (0x00FF00B0 >> 16) # lui $t5, 0xff
  ori   $t5, (0x00FF00B0 & 0xFFFF) # ori $t5, $t5, 0xb0
  sw    $t5, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xcc
  addiu $a2, $sp, 0xc8
  lw    $a3, 0xa4($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t4, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t7, 0x10($sp)
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  lw    $v1, %lo(pPlayer)($v1)
  move  $s1, $v0
.Ljp7F0C671C:
  lw    $v0, 0x2a14($v1)
  addiu $a0, $sp, 0x7c
  addiu $a1, $sp, 0x78
  beqz  $v0, .Ljp7F0C67F4
   move  $a2, $v0
  lui   $t9, %hi(ptrFirstFontTableSmall) # $t9, 0x8004
  lw    $t9, %lo(ptrFirstFontTableSmall)($t9)
  lui   $a3, %hi(ptrSecondFontTableSmall) # $a3, 0x8004
  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
  sw    $zero, 0x14($sp)
  sw    $v0, 0xa4($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t9, 0x10($sp)
  jal   get_video2_settings_ulx
   nop   
  lw    $t3, 0x74($sp)
  lw    $t8, 0x78($sp)
  addu  $t6, $v0, $t3
  sra   $t7, $t8, 1
  subu  $a0, $t6, $t7
  addiu $a0, $a0, 0x50
  jal   get_video2_settings_uly
   sw    $a0, 0xcc($sp)
  lw    $t4, 0x7c($sp)
  sra   $t5, $t4, 1
  subu  $t9, $v0, $t5
  addiu $t3, $t9, 0x58
  jal   get_video2_settings_txtClipW
   sw    $t3, 0xc8($sp)
  sll   $s0, $v0, 0x10
  sra   $t8, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t8
  lui   $t6, %hi(ptrSecondFontTableSmall) # $t6, 0x8004
  lui   $t7, %hi(ptrFirstFontTableSmall) # $t7, 0x8004
  lw    $t7, %lo(ptrFirstFontTableSmall)($t7)
  lw    $t6, %lo(ptrSecondFontTableSmall)($t6)
  lui   $t4, (0x00FF00B0 >> 16) # lui $t4, 0xff
  ori   $t4, (0x00FF00B0 & 0xFFFF) # ori $t4, $t4, 0xb0
  sw    $t4, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xcc
  addiu $a2, $sp, 0xc8
  lw    $a3, 0xa4($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t7, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t6, 0x10($sp)
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  lw    $v1, %lo(pPlayer)($v1)
  move  $s1, $v0
.Ljp7F0C67F4:
  lw    $t5, 0x29c8($v1)
.Ljp7F0C67F8:
  li    $at, 6
  bne   $t5, $at, .Ljp7F0C6AC0
   nop   
  jal   get_textptr_for_textID
   li    $a0, 40992
  lui   $t9, %hi(ptrFirstFontTableSmall) # $t9, 0x8004
  lw    $t9, %lo(ptrFirstFontTableSmall)($t9)
  lui   $a3, %hi(ptrSecondFontTableSmall) # $a3, 0x8004
  sw    $v0, 0xa4($sp)
  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
  addiu $a0, $sp, 0xbc
  addiu $a1, $sp, 0xc0
  move  $a2, $v0
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t9, 0x10($sp)
  jal   get_video2_settings_ulx
   nop   
  lw    $t3, 0xa8($sp)
  lw    $t6, 0xc0($sp)
  addu  $t8, $v0, $t3
  sra   $t7, $t6, 1
  subu  $a0, $t8, $t7
  addiu $a0, $a0, 0x36
  jal   get_video2_settings_uly
   sw    $a0, 0xcc($sp)
  lw    $t4, 0xbc($sp)
  lui   $t6, %hi(pPlayer) # $t6, 0x8008
  lw    $t6, %lo(pPlayer)($t6)
  sra   $t5, $t4, 1
  subu  $t9, $v0, $t5
  addiu $t3, $t9, 0x36
  sw    $t3, 0xc8($sp)
  lw    $t8, 0x29cc($t6)
  bnez  $t8, .Ljp7F0C68FC
   nop   
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s0, $v0, 0x10
  sra   $t7, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t7
  lui   $t4, %hi(ptrSecondFontTableSmall) # $t4, 0x8004
  lui   $t5, %hi(ptrFirstFontTableSmall) # $t5, 0x8004
  lw    $t5, %lo(ptrFirstFontTableSmall)($t5)
  lw    $t4, %lo(ptrSecondFontTableSmall)($t4)
  lui   $t9, (0xA0FFA0F0 >> 16) # lui $t9, 0xa0ff
  lui   $t3, (0x007000A0 >> 16) # lui $t3, 0x70
  ori   $t3, (0x007000A0 & 0xFFFF) # ori $t3, $t3, 0xa0
  ori   $t9, (0xA0FFA0F0 & 0xFFFF) # ori $t9, $t9, 0xa0f0
  sw    $t9, 0x18($sp)
  sw    $t3, 0x1c($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xcc
  addiu $a2, $sp, 0xc8
  lw    $a3, 0xa4($sp)
  sw    $s0, 0x20($sp)
  sw    $v0, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $zero, 0x2c($sp)
  sw    $t5, 0x14($sp)
  jal   jp_text_write_stuff
   sw    $t4, 0x10($sp)
  b     .Ljp7F0C6960
   move  $s1, $v0
.Ljp7F0C68FC:
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s0, $v0, 0x10
  sra   $t6, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t6
  lui   $t8, %hi(ptrSecondFontTableSmall) # $t8, 0x8004
  lui   $t7, %hi(ptrFirstFontTableSmall) # $t7, 0x8004
  lw    $t7, %lo(ptrFirstFontTableSmall)($t7)
  lw    $t8, %lo(ptrSecondFontTableSmall)($t8)
  lui   $t4, (0x00FF00B0 >> 16) # lui $t4, 0xff
  ori   $t4, (0x00FF00B0 & 0xFFFF) # ori $t4, $t4, 0xb0
  sw    $t4, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xcc
  addiu $a2, $sp, 0xc8
  lw    $a3, 0xa4($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t7, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t8, 0x10($sp)
  move  $s1, $v0
.Ljp7F0C6960:
  jal   get_textptr_for_textID
   li    $a0, 40993
  lui   $t5, %hi(ptrFirstFontTableSmall) # $t5, 0x8004
  lw    $t5, %lo(ptrFirstFontTableSmall)($t5)
  lui   $a3, %hi(ptrSecondFontTableSmall) # $a3, 0x8004
  sw    $v0, 0xa4($sp)
  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
  addiu $a0, $sp, 0xbc
  addiu $a1, $sp, 0xc0
  move  $a2, $v0
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t5, 0x10($sp)
  jal   get_video2_settings_ulx
   nop   
  lw    $t9, 0xa8($sp)
  lw    $t6, 0xc0($sp)
  addu  $t3, $v0, $t9
  sra   $t8, $t6, 1
  subu  $a0, $t3, $t8
  addiu $a0, $a0, 0x68
  jal   get_video2_settings_uly
   sw    $a0, 0xcc($sp)
  lw    $t7, 0xbc($sp)
  lui   $t6, %hi(pPlayer) # $t6, 0x8008
  lw    $t6, %lo(pPlayer)($t6)
  sra   $t4, $t7, 1
  subu  $t5, $v0, $t4
  addiu $t9, $t5, 0x36
  sw    $t9, 0xc8($sp)
  lw    $t3, 0x29cc($t6)
  li    $at, 1
  bne   $t3, $at, .Ljp7F0C6A5C
   nop   
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s0, $v0, 0x10
  sra   $t8, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t8
  lui   $t7, %hi(ptrSecondFontTableSmall) # $t7, 0x8004
  lui   $t4, %hi(ptrFirstFontTableSmall) # $t4, 0x8004
  lw    $t4, %lo(ptrFirstFontTableSmall)($t4)
  lw    $t7, %lo(ptrSecondFontTableSmall)($t7)
  lui   $t5, (0xA0FFA0F0 >> 16) # lui $t5, 0xa0ff
  lui   $t9, (0x007000A0 >> 16) # lui $t9, 0x70
  ori   $t9, (0x007000A0 & 0xFFFF) # ori $t9, $t9, 0xa0
  ori   $t5, (0xA0FFA0F0 & 0xFFFF) # ori $t5, $t5, 0xa0f0
  sw    $t5, 0x18($sp)
  sw    $t9, 0x1c($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xcc
  addiu $a2, $sp, 0xc8
  lw    $a3, 0xa4($sp)
  sw    $s0, 0x20($sp)
  sw    $v0, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $zero, 0x2c($sp)
  sw    $t4, 0x14($sp)
  jal   jp_text_write_stuff
   sw    $t7, 0x10($sp)
  b     .Ljp7F0C6AC0
   move  $s1, $v0
.Ljp7F0C6A5C:
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s0, $v0, 0x10
  sra   $t6, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t6
  lui   $t3, %hi(ptrSecondFontTableSmall) # $t3, 0x8004
  lui   $t8, %hi(ptrFirstFontTableSmall) # $t8, 0x8004
  lw    $t8, %lo(ptrFirstFontTableSmall)($t8)
  lw    $t3, %lo(ptrSecondFontTableSmall)($t3)
  lui   $t7, (0x00FF00B0 >> 16) # lui $t7, 0xff
  ori   $t7, (0x00FF00B0 & 0xFFFF) # ori $t7, $t7, 0xb0
  sw    $t7, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xcc
  addiu $a2, $sp, 0xc8
  lw    $a3, 0xa4($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t8, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t3, 0x10($sp)
  move  $s1, $v0
.Ljp7F0C6AC0:
  jal   combiner_bayer_lod_perspective
   move  $a0, $s1
  b     .Ljp7F0C6D14
   move  $s1, $v0
  lw    $t4, 0xd8($v1)
.Ljp7F0C6AD4:
  beql  $t4, $zero, .Ljp7F0C6D18
   move  $v0, $s1
  lw    $t5, 0x428($v1)
  beql  $t5, $zero, .Ljp7F0C6D18
   move  $v0, $s1
  lw    $t9, 0x424($v1)
  lui   $t6, %hi(stop_play_flag) # $t6, 0x8009
  beql  $t9, $zero, .Ljp7F0C6D18
   move  $v0, $s1
  lw    $t6, %lo(stop_play_flag)($t6)
  lui   $t3, %hi(is_gameover_flag) # $t3, 0x8009
  bnezl $t6, .Ljp7F0C6D18
   move  $v0, $s1
  lw    $t3, %lo(is_gameover_flag)($t3)
  move  $a0, $zero
  bnezl $t3, .Ljp7F0C6D18
   move  $v0, $s1
  blez  $v0, .Ljp7F0C6BBC
   move  $a1, $zero
  andi  $a3, $v0, 3
  beqz  $a3, .Ljp7F0C6B6C
   move  $a2, $a3
  lw    $t7, 0xd4($sp)
  sll   $t8, $zero, 3
  subu  $t8, $t8, $zero
  sll   $t8, $t8, 4
  lui   $t9, %hi(player1_player_data) # $t9, 0x8008
  sll   $t4, $t7, 2
  addu  $t5, $t8, $t4
  addiu $t9, %lo(player1_player_data) # addiu $t9, $t9, -0x60a0
  addu  $v1, $t5, $t9
.Ljp7F0C6B50:
  lw    $t6, 0x24($v1)
  addiu $a1, $a1, 1
  addiu $v1, $v1, 0x70
  bne   $a2, $a1, .Ljp7F0C6B50
   addu  $a0, $a0, $t6
  beq   $a1, $v0, .Ljp7F0C6BBC
   nop   
.Ljp7F0C6B6C:
  lw    $t7, 0xd4($sp)
  sll   $t3, $a1, 3
  subu  $t3, $t3, $a1
  sll   $t3, $t3, 4
  lui   $t5, %hi(player1_player_data) # $t5, 0x8008
  sll   $t8, $t7, 2
  addu  $t4, $t3, $t8
  addiu $t5, %lo(player1_player_data) # addiu $t5, $t5, -0x60a0
  addu  $v1, $t4, $t5
.Ljp7F0C6B90:
  lw    $t9, 0x24($v1)
  lw    $t6, 0x94($v1)
  lw    $t7, 0x104($v1)
  addu  $a0, $a0, $t9
  lw    $t3, 0x174($v1)
  addu  $a0, $a0, $t6
  addiu $a1, $a1, 4
  addu  $a0, $a0, $t7
  addiu $v1, $v1, 0x1c0
  bne   $a1, $t0, .Ljp7F0C6B90
   addu  $a0, $a0, $t3
.Ljp7F0C6BBC:
  jal   get_scenario
   sw    $a0, 0x58($sp)
  li    $at, 1
  bne   $v0, $at, .Ljp7F0C6BDC
   lw    $a0, 0x58($sp)
  slti  $at, $a0, 2
  beql  $at, $zero, .Ljp7F0C6D18
   move  $v0, $s1
.Ljp7F0C6BDC:
  jal   sub_GAME_7F0B4FB4
   move  $a0, $s1
  jal   microcode_constructor
   move  $a0, $v0
  move  $s1, $v0
  jal   get_textptr_for_textID
   li    $a0, 40994
  lui   $t8, %hi(ptrFirstFontTableSmall) # $t8, 0x8004
  lw    $t8, %lo(ptrFirstFontTableSmall)($t8)
  lui   $a3, %hi(ptrSecondFontTableSmall) # $a3, 0x8004
  sw    $v0, 0x60($sp)
  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
  addiu $a0, $sp, 0x64
  addiu $a1, $sp, 0x68
  move  $a2, $v0
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t8, 0x10($sp)
  jal   get_video2_settings_ulx
   nop   
  jal   get_video2_settings_width
   sh    $v0, 0x56($sp)
  lh    $t0, 0x56($sp)
  lw    $t6, 0x68($sp)
  sra   $t5, $v0, 1
  addu  $t9, $t5, $t0
  sra   $t7, $t6, 1
  subu  $t2, $t9, $t7
  jal   get_video2_settings_uly
   sw    $t2, 0x70($sp)
  jal   get_video2_settings_height
   sh    $v0, 0x56($sp)
  lh    $t0, 0x56($sp)
  lw    $t1, 0x64($sp)
  sra   $t8, $v0, 1
  lw    $t2, 0x70($sp)
  lw    $t6, 0x68($sp)
  addu  $t4, $t8, $t0
  sra   $t5, $t1, 1
  subu  $v1, $t4, $t5
  addu  $t9, $v1, $t1
  addiu $t7, $t9, 1
  addu  $a3, $t2, $t6
  addiu $a3, $a3, 1
  sw    $t7, 0x10($sp)
  addiu $a2, $v1, -1
  sw    $v1, 0x6c($sp)
  move  $a0, $s1
  sw    $zero, 0x14($sp)
  jal   microcode_constructor_related_to_menus
   addiu $a1, $t2, -1
  jal   get_video2_settings_txtClipW
   move  $s1, $v0
  sll   $s0, $v0, 0x10
  sra   $t3, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t3
  lui   $t8, %hi(ptrSecondFontTableSmall) # $t8, 0x8004
  lui   $t4, %hi(ptrFirstFontTableSmall) # $t4, 0x8004
  lw    $t4, %lo(ptrFirstFontTableSmall)($t4)
  lw    $t8, %lo(ptrSecondFontTableSmall)($t8)
  lui   $t5, (0x00FF00B0 >> 16) # lui $t5, 0xff
  ori   $t5, (0x00FF00B0 & 0xFFFF) # ori $t5, $t5, 0xb0
  sw    $t5, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0x70
  addiu $a2, $sp, 0x6c
  lw    $a3, 0x60($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t4, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t8, 0x10($sp)
  jal   combiner_bayer_lod_perspective
   move  $a0, $v0
  move  $s1, $v0
.Ljp7F0C6D14:
  move  $v0, $s1
.Ljp7F0C6D18:
  lw    $ra, 0x3c($sp)
  lw    $s0, 0x34($sp)
  lw    $s1, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0xd8
");
#endif

asm(R"
glabel sub_GAME_7F0C6048
  lui   $t6, %hi(is_gameover_flag) 
  lw    $t6, %lo(is_gameover_flag)($t6)
  lui   $v0, %hi(pPlayer)
  beqz  $t6, .L7F0C6064
   nop   
  jr    $ra
   move  $v0, $zero

.L7F0C6064:
  lw    $v0, %lo(pPlayer)($v0)
  lw    $t8, 0x2a00($v0)
  lw    $t7, 0x29c4($v0)
  slt   $t9, $zero, $t8
  or    $v1, $t7, $t9
  jr    $ra
   move  $v0, $v1
");

int checkGamePaused(void) { return is_paused; }
