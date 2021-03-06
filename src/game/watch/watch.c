#include "music.h"
#include "players.h"
#include "unk_0A1DA0.h"
#include <message.h>
#include <os_cont.h>
#include <stddef.h>
#include <thread.h>

char dword_CODE_bss_8007B0A0[0x40];
char dword_CODE_bss_8007B0E0[0x40];

int D_800409A0 = 4;
int D_800409A4 = 0;
int watch_soundrelated_maybe = 0;
int D_800409AC = 0;
int D_800409B0 = 0;
int D_800409B4 = 0;
int D_800409B8 = 0;
float D_800409BC = 0.0f;
int D_800409C0 = 0;
int D_800409C4 = 0;
float D_800409C8 = 0.0f;
float D_800409CC = 0.0f;
int D_800409D0 = -1;
float D_800409D4 = 0.0f;
int D_800409D8 = 8;
unsigned short D_800409DC[] = {
    0xAC09, 0xAC03, 0xAC02, 0xAC00, 0xAC01, 0xAC01, 0xAC06, 0xAC06, 0xAC04,
    0xAC05, 0xAC0A, 0xAC03, 0xAC02, 0xAC00, 0xAC01, 0xAC01, 0xAC05, 0xAC05,
    0xAC04, 0xAC06, 0xAC0B, 0xAC00, 0xAC02, 0xAC01, 0xAC03, 0xAC03, 0xAC06,
    0xAC06, 0xAC04, 0xAC05, 0xAC0C, 0xAC00, 0xAC02, 0xAC01, 0xAC03, 0xAC03,
    0xAC05, 0xAC05, 0xAC04, 0xAC06, 0xAC0D, 0xAC07, 0xAC07, 0xAC07, 0xAC07,
    0xAC07, 0xAC07, 0xAC07, 0xAC07, 0xAC07, 0xAC0E, 0xAC07, 0xAC07, 0xAC07,
    0xAC07, 0xAC07, 0xAC07, 0xAC07, 0xAC07, 0xAC07, 0xAC0F, 0xAC07, 0xAC07,
    0xAC07, 0xAC07, 0xAC07, 0xAC07, 0xAC07, 0xAC07, 0xAC07, 0xAC10, 0xAC07,
    0xAC07, 0xAC07, 0xAC07, 0xAC07, 0xAC07, 0xAC07, 0xAC07, 0xAC07};

unsigned short D_80040A7C[] = {0xAC11, 0xAC1C, 0xAC1B, 0};
unsigned int cur_player_look_vertical_inverted = 0;
unsigned short D_80040A88[] = {0xAC12, 0xAC1A, 0xAC19, 0};
unsigned int cur_player_autoaim_setting = 1;
unsigned short D_80040A94[] = {0xAC14, 0xAC1E, 0xAC1D, 0};
unsigned int cur_player_aim_control = 0;
unsigned short D_80040AA0[] = {0xAC15, 0xAC1A, 0xAC19, 0};
unsigned int cur_player_sight_onscreen = 1;
unsigned short D_80040AAC[] = {0xAC13, 0xAC1A, 0xAC19, 0};
unsigned int cur_player_lookahead_setting = 1;
unsigned short D_80040AB8[] = {0xAC16, 0xAC1A, 0xAC19, 0};
unsigned int cur_player_ammo_onscreen_setting = 1;
unsigned short D_80040AC4[] = {0xAC17, 0xAC1F, 0xAC20, 0xAC21};
unsigned int cur_player_screen_setting = 0;
unsigned short D_80040AD0[] = {0xAC18, 0xAC22, 0xAC23, 0};
unsigned int screen_ratio = 0;
unsigned int controlstick_lr_enabled = 0;
unsigned int D_80040AE0 = 0;
unsigned int D_80040AE4 = 0;
float D_80040AE8 = 0.0f;
float D_80040AEC = 0.0f;
float D_80040AF0 = 45.0f;
unsigned int D_80040AF4 = 0xFF00A0;
unsigned int D_80040AF8 = 0xA;
unsigned int D_80040AFC = 0xFF;
unsigned int D_80040B00 = 0xA;
unsigned int D_80040B04 = 0xE0;
unsigned int D_80040B08 = 0;
unsigned int D_80040B0C = 0xFFA0;
unsigned int D_80040B10 = 0xF800;
float D_80040B14 = 0.0f;
float D_80040B18 = 0.0f;
float D_80040B1C = 2.5f;
float D_80040B20 = 0.0f;
float D_80040B24 = 0.0f;
float D_80040B28 = 0.0f;
unsigned int D_80040B2C = 0;
float D_80040B30 = 0.0f;
float D_80040B34 = 0.0f;
float D_80040B38 = 0.0f;
unsigned int D_80040B3C = 0;
unsigned int D_80040B40 = 0;
unsigned int D_80040B44 = 0x10000;
unsigned int D_80040B48 = 0x32;
unsigned int D_80040B4C = 0x32;
unsigned int D_80040B50 = 0x32;
unsigned int D_80040B54 = 0x32;
unsigned short mTrack2Vol = 0x7FFF;
unsigned int D_80040B5C = 0;
unsigned int D_80040B60 = 0x43480000;
unsigned int D_80040B64 = 0xC3480000;
unsigned int D_80040B68 = 0;
unsigned int D_80040B6C = 0;
unsigned int D_80040B70 = 0;
unsigned int D_80040B74 = 0;
unsigned int D_80040B78 = 0;
unsigned int D_80040B7C = 0;
unsigned int D_80040B80 = 0;
unsigned int D_80040B84 = 0;
unsigned int D_80040B88 = 0;
unsigned int D_80040B8C = 0;
unsigned int D_80040B90 = 0;
unsigned int D_80040B94 = 0;
unsigned int D_80040B98 = 0;
unsigned int D_80040B9C = 0;
unsigned int D_80040BA0 = 0;
unsigned int D_80040BA4 = 0;
unsigned int D_80040BA8 = 0;
unsigned int D_80040BAC = 0;
unsigned int D_80040BB0 = 0;

unsigned int D_80040BB4[] = {
    0xC4610000, 0x43480000, 0xC2340000, 0x4432C000, 0x43480000, 0x43C48000,
    0xC45AC000, 0x43480000, 0xC3520000, 0x44610000, 0x43480000, 0xC3820000,
    0x44610000, 0x43480000, 0xC3200000, 0x44548000, 0x43480000, 0xC3520000,
    0x446D8000, 0x43480000, 0xC3520000, 0x44610000, 0x43480000, 0x43000000,
    0x44610000, 0x43480000, 0xC2340000, 0xC44D0000, 0x43480000, 0xC3C28000,
    0x444D0000, 0x43480000, 0xC3C28000, 0xC44F8000, 0x43480000, 0x429C0000,
    0,          0,          0,          0,          0,          0,
    0,          0,          0,          0,          0,          0,
    0,          0,          0,          0,          0x44FA0000, 0,
    0x44FA0000, 0x44FA0000, 0,          0x44FA0000, 0xC4160000, 0x43480000,
    0x43FA0000, 0x44FA0000, 0,          0x44FA0000, 0x44FA0000, 0,
    0x44FA0000, 0x44FA0000, 0,          0x44FA0000, 0x44FA0000, 0,
    0x44FA0000, 0x44FA0000, 0,          0x44FA0000, 0xC4160000, 0x43480000,
    0x43700000, 0xC4160000, 0x43480000, 0x42DC0000, 0x44FA0000, 0,
    0x44FA0000, 0x44FA0000, 0};

unsigned int D_80040D10[] = {0x44FA0000, 0xC4160000, 0x43480000};

unsigned int D_80040D1C = 0x43A00000;

unsigned int D_80040D20[] = {
    0,          0,          0,          0,          0,          0,
    0,          0,          0,          0,          0,          0,
    0,          0,          0,          0,          0x44FA0000, 0,
    0x44FA0000, 0x44FA0000, 0,          0x44FA0000, 0x44160000, 0x43480000,
    0x43FA0000, 0x44FA0000, 0,          0x44FA0000, 0x44FA0000, 0,
    0x44FA0000, 0x44FA0000, 0,          0x44FA0000, 0x44FA0000, 0,
    0x44FA0000, 0x44FA0000, 0,          0x44FA0000, 0x44160000, 0x43480000,
    0x43700000, 0x44160000, 0x43480000, 0x42DC0000, 0x44FA0000, 0,
    0x44FA0000, 0x44FA0000, 0};

unsigned int D_80040DEC[] = {0x44FA0000, 0x44160000, 0x43480000};
unsigned int D_80040DF8 = 0x43A00000;

int D_80040DFC[] = {0x34, 0x2F, 0x2D, 0x2A, 0x28, 0x25, 0x25,      0x28,
                    0x2A, 0x2D, 0x2F, 0x34, 0x37, 0x40, 0xFFFFFFFF};

int D_80040E38 = 0x4B;
int D_80040E3C = 0xFFFFFFFF;

int D_80040E40[] = {0x10E, 0x113, 0x116, 0x119, 0x11A, 0x11B, 0x11B,     0x11A,
                    0x119, 0x116, 0x113, 0x10E, 0x108, 0xFE,  0xFFFFFFFF};
int D_80040E7C = 0;

const char aDD[] = "%d, %d\n";
const char aDDDF[] = "%d, %d\n%d %f\n";
const char aA[] = "(A)\n";
const char aB[] = "(B)\n";
const char aZ[] = "(Z)\n";
const char aL[] = "(L)\n";
const char aR[] = "(R)\n";
const char aC[] = "(C)\n";
const char D_800577A8[] = "(+)\n";
const char aS_0[] = "(S)\n";
const char a3d[] = "(3D)\n";
const char D_800577C0[] = "\n";

const unsigned int D_800577C4[511] = {0};
const unsigned int D_80057FC0[288] = {0};

const char D_80058440[] = " \n";
const char D_80058444[] = " \n\n";
const char aC_2[] = "%c: ";
const char D_80058450[] = " \n";
const char D_80058454[] = " \n\n";

void nullsub_7F0A4860(void) {}

asm(R"
glabel init_watch_at_start_of_stage
  lui   $at, %hi(D_80040994)
  sw    $zero, %lo(D_80040994)($at)
  lui   $at, %hi(D_80040998)
  sw    $zero, %lo(D_80040998)($at)
  lui   $at, %hi(D_8004099C)
  sw    $zero, %lo(D_8004099C)($at)
  lui   $at, %hi(D_800409A0)
  li    $t6, 4
  sw    $t6, %lo(D_800409A0)($at)
  lui   $at, %hi(D_800409A4)
  sw    $zero, %lo(D_800409A4)($at)
  lui   $at, %hi(watch_soundrelated_maybe)
  sw    $zero, %lo(watch_soundrelated_maybe)($at)
  lui   $at, %hi(D_800409AC)
  sw    $zero, %lo(D_800409AC)($at)
  lui   $at, %hi(D_800409B0)
  sw    $zero, %lo(D_800409B0)($at)
  lui   $at, %hi(D_800409B4)
  sw    $zero, %lo(D_800409B4)($at)
  mtc1  $zero, $f0
  lui   $at, %hi(D_800409B8)
  sw    $zero, %lo(D_800409B8)($at)
  lui   $at, %hi(D_800409BC)
  swc1  $f0, %lo(D_800409BC)($at)
  lui   $at, %hi(D_800409C0)
  sw    $zero, %lo(D_800409C0)($at)
  lui   $at, %hi(D_800409C4)
  sw    $zero, %lo(D_800409C4)($at)
  lui   $at, %hi(D_800409C8)
  swc1  $f0, %lo(D_800409C8)($at)
  lui   $at, %hi(D_800409CC)
  lui   $t8, %hi(j_text_trigger) 
  swc1  $f0, %lo(D_800409CC)($at)
  lw    $t8, %lo(j_text_trigger)($t8)
  lui   $at, %hi(D_800409D0)
  li    $t7, -1
  sw    $t7, %lo(D_800409D0)($at)
  addiu $sp, $sp, -0x18
  lui   $at, %hi(D_800409D4)
  sw    $ra, 0x14($sp)
  beqz  $t8, .L7F0A4918
   swc1  $f0, %lo(D_800409D4)($at)
  b     .L7F0A4918
   nop   
.L7F0A4918:
  lui   $v0, %hi(pPlayer)
  addiu $v0, %lo(pPlayer) # addiu $v0, $v0, -0x5f50
  lw    $t9, ($v0)
  li    $a1, 1
  li    $t4, 8
  sw    $zero, 0x2a64($t9)
  lw    $t0, ($v0)
  lui   $at, %hi(D_800409D8)
  lui   $t5, (0x00FF00A0 >> 16) # lui $t5, 0xff
  sw    $zero, 0x2a5c($t0)
  lw    $t1, ($v0)
  ori   $t5, (0x00FF00A0 & 0xFFFF) # ori $t5, $t5, 0xa0
  li    $a2, 10
  sw    $zero, 0x2a58($t1)
  lw    $t2, ($v0)
  li    $t6, 255
  li    $t7, 224
  swc1  $f0, 0x2a60($t2)
  lw    $t3, ($v0)
  li    $t8, 65440
  li    $t9, 63488
  sw    $a1, 0x2a68($t3)
  sw    $t4, %lo(D_800409D8)($at)
  lui   $at, %hi(controlstick_lr_enabled)
  sw    $zero, %lo(controlstick_lr_enabled)($at)
  lui   $at, %hi(D_80040AE0)
  sw    $zero, %lo(D_80040AE0)($at)
  lui   $at, %hi(D_80040AE4)
  sw    $zero, %lo(D_80040AE4)($at)
  lui   $at, %hi(D_80040AE8)
  swc1  $f0, %lo(D_80040AE8)($at)
  lui   $at, %hi(D_80040AEC)
  swc1  $f0, %lo(D_80040AEC)($at)
  li    $at, 0x42340000 # 45.000000
  mtc1  $at, $f4
  lui   $at, %hi(D_80040AF0)
  li    $v1, 50
  swc1  $f4, %lo(D_80040AF0)($at)
  lui   $at, %hi(D_80040AF4)
  sw    $t5, %lo(D_80040AF4)($at)
  lui   $at, %hi(D_80040AF8)
  sw    $a2, %lo(D_80040AF8)($at)
  lui   $at, %hi(D_80040AFC)
  sw    $t6, %lo(D_80040AFC)($at)
  lui   $at, %hi(D_80040B00)
  sw    $a2, %lo(D_80040B00)($at)
  lui   $at, %hi(D_80040B04)
  sw    $t7, %lo(D_80040B04)($at)
  lui   $at, %hi(D_80040B08)
  sw    $zero, %lo(D_80040B08)($at)
  lui   $at, %hi(D_80040B0C)
  sw    $t8, %lo(D_80040B0C)($at)
  lui   $at, %hi(D_80040B10)
  sw    $t9, %lo(D_80040B10)($at)
  lui   $at, %hi(D_80040B14)
  swc1  $f0, %lo(D_80040B14)($at)
  lui   $at, %hi(D_80040B18)
  swc1  $f0, %lo(D_80040B18)($at)
  li    $at, 0x40200000 # 2.500000
  mtc1  $at, $f6
  lui   $at, %hi(D_80040B1C)
  swc1  $f6, %lo(D_80040B1C)($at)
  lui   $at, %hi(D_80040B20)
  swc1  $f0, %lo(D_80040B20)($at)
  lui   $at, %hi(D_80040B24)
  swc1  $f0, %lo(D_80040B24)($at)
  lui   $at, %hi(D_80040B28)
  swc1  $f0, %lo(D_80040B28)($at)
  lui   $at, %hi(D_80040B2C)
  sw    $zero, %lo(D_80040B2C)($at)
  lui   $at, %hi(D_80040B30)
  swc1  $f0, %lo(D_80040B30)($at)
  lui   $at, %hi(D_80040B34)
  swc1  $f0, %lo(D_80040B34)($at)
  lui   $at, %hi(D_80040B38)
  swc1  $f0, %lo(D_80040B38)($at)
  lui   $at, %hi(D_80040B3C)
  sw    $zero, %lo(D_80040B3C)($at)
  lui   $at, %hi(D_80040B40)
  sw    $zero, %lo(D_80040B40)($at)
  lui   $at, %hi(D_80040B44)
  sh    $a1, %lo(D_80040B44)($at)
  lui   $at, %hi(D_80040B48)
  sw    $v1, %lo(D_80040B48)($at)
  lui   $at, %hi(D_80040B4C)
  sw    $v1, %lo(D_80040B4C)($at)
  lui   $at, %hi(D_80040B50)
  sw    $v1, %lo(D_80040B50)($at)
  lui   $at, %hi(D_80040B54)
  jal   sub_GAME_7F01D500
   sw    $v1, %lo(D_80040B54)($at)
  lw    $ra, 0x14($sp)
  lui   $at, %hi(mission_failed_or_aborted)
  sw    $zero, %lo(mission_failed_or_aborted)($at)
  jr    $ra
   addiu $sp, $sp, 0x18
");

void controller_deadzone_related(void) {
  if (10 < get_cur_controller_horz_stick_pos('\0'))
    D_80040B50 = D_80040B50 + 1;
  if (get_cur_controller_horz_stick_pos('\0') < -10)
    D_80040B50 = D_80040B50 + -1;
  if (10 < get_cur_controller_vert_stick_pos('\0'))
    D_80040B54 = D_80040B54 + -1;
  if (get_cur_controller_vert_stick_pos('\0') < -10)
    D_80040B54 = D_80040B54 + 1;
}

asm(R"
glabel sub_GAME_7F0A4B40
  addiu $sp, $sp, -0x80
  sw    $s0, 0x38($sp)
  move  $s0, $a0
  sw    $ra, 0x44($sp)
  sw    $s2, 0x40($sp)
  sw    $s1, 0x3c($sp)
  jal   get_cur_controller_horz_stick_pos
   move  $a0, $zero
  slti  $at, $v0, 0xb
  bnez  $at, .L7F0A4B80
   move  $a0, $zero
  lui   $s2, %hi(D_80040B48)
  addiu $s2, %lo(D_80040B48) # addiu $s2, $s2, 0xb48
  lw    $t6, ($s2)
  addiu $t7, $t6, 1
  sw    $t7, ($s2)
.L7F0A4B80:
  lui   $s2, %hi(D_80040B48)
  jal   get_cur_controller_horz_stick_pos
   addiu $s2, %lo(D_80040B48) # addiu $s2, $s2, 0xb48
  slti  $at, $v0, -0xa
  beqz  $at, .L7F0A4BA4
   nop   
  lw    $t8, ($s2)
  addiu $t9, $t8, -1
  sw    $t9, ($s2)
.L7F0A4BA4:
  jal   get_cur_controller_vert_stick_pos
   move  $a0, $zero
  slti  $at, $v0, 0xb
  bnez  $at, .L7F0A4BCC
   move  $a0, $zero
  lui   $s1, %hi(D_80040B4C)
  addiu $s1, %lo(D_80040B4C) # addiu $s1, $s1, 0xb4c
  lw    $t2, ($s1)
  addiu $t3, $t2, -1
  sw    $t3, ($s1)
.L7F0A4BCC:
  lui   $s1, %hi(D_80040B4C)
  jal   get_cur_controller_vert_stick_pos
   addiu $s1, %lo(D_80040B4C) # addiu $s1, $s1, 0xb4c
  slti  $at, $v0, -0xa
  beqz  $at, .L7F0A4BF0
   move  $v0, $s0
  lw    $t4, ($s1)
  addiu $t5, $t4, 1
  sw    $t5, ($s1)
.L7F0A4BF0:
  addiu $s0, $s0, 8
  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
  lui   $t7, (0x00504240 >> 16) # lui $t7, 0x50
  ori   $t7, (0x00504240 & 0xFFFF) # ori $t7, $t7, 0x4240
  ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
  move  $v1, $s0
  sw    $t6, ($v0)
  sw    $t7, 4($v0)
  lui   $t8, (0xFCFFFFFF >> 16) # lui $t8, 0xfcff
  lui   $t9, (0xFFFDF6FB >> 16) # lui $t9, 0xfffd
  ori   $t9, (0xFFFDF6FB & 0xFFFF) # ori $t9, $t9, 0xf6fb
  ori   $t8, (0xFCFFFFFF & 0xFFFF) # ori $t8, $t8, 0xffff
  addiu $s0, $s0, 8
  sw    $t8, ($v1)
  sw    $t9, 4($v1)
  move  $t0, $s0
  lui   $t3, (0xFF0000FF >> 16) # lui $t3, 0xff00
  ori   $t3, (0xFF0000FF & 0xFFFF) # ori $t3, $t3, 0xff
  lui   $t2, 0xfa00
  sw    $t2, ($t0)
  sw    $t3, 4($t0)
  lw    $t4, ($s2)
  lw    $t9, ($s1)
  lui   $at, 0xf600
  addiu $t5, $t4, 1
  andi  $t6, $t5, 0x3ff
  addiu $t2, $t9, 1
  andi  $t3, $t2, 0x3ff
  sll   $t7, $t6, 0xe
  addiu $s0, $s0, 8
  or    $t8, $t7, $at
  sll   $t4, $t3, 2
  or    $t5, $t8, $t4
  move  $t1, $s0
  sw    $t5, ($t1)
  lw    $t2, ($s1)
  lw    $t6, ($s2)
  lui   $t5, %hi(ptrFirstFontTableSmall) 
  andi  $t3, $t2, 0x3ff
  andi  $t7, $t6, 0x3ff
  sll   $t9, $t7, 0xe
  sll   $t8, $t3, 2
  or    $t4, $t9, $t8
  sw    $t4, 4($t1)
  lui   $t6, %hi(ptrSecondFontTableSmall) 
  lw    $t5, %lo(ptrFirstFontTableSmall)($t5)
  lw    $t6, %lo(ptrSecondFontTableSmall)($t6)
  lui   $a1, %hi(aDD)
  addiu $s0, $s0, 8
  addiu $a1, %lo(aDD) # addiu $a1, $a1, 0x7760
  lw    $a3, ($s1)
  lw    $a2, ($s2)
  addiu $a0, $sp, 0x5c
  sw    $t5, 0x58($sp)
  jal   sprintf
   sw    $t6, 0x54($sp)
  jal   microcode_constructor
   move  $a0, $s0
  lw    $t7, 0x58($sp)
  move  $s0, $v0
  addiu $a0, $sp, 0x4c
  addiu $a1, $sp, 0x50
  addiu $a2, $sp, 0x5c
  lw    $a3, 0x54($sp)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t7, 0x10($sp)
  lw    $t2, 0x54($sp)
  lw    $t3, 0x58($sp)
  lw    $t8, 0x50($sp)
  lw    $t4, 0x4c($sp)
  lui   $t9, (0xFF0000FF >> 16) # lui $t9, 0xff00
  ori   $t9, (0xFF0000FF & 0xFFFF) # ori $t9, $t9, 0xff
  sw    $t9, 0x18($sp)
  move  $a0, $s0
  move  $a1, $s2
  move  $a2, $s1
  addiu $a3, $sp, 0x5c
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t2, 0x10($sp)
  sw    $t3, 0x14($sp)
  sw    $t8, 0x1c($sp)
  jal   en_text_write_stuff
   sw    $t4, 0x20($sp)
  lw    $t6, 0x54($sp)
  lw    $t5, ($s1)
  lw    $ra, 0x44($sp)
  lw    $t7, 0x890($t6)
  lw    $s0, 0x38($sp)
  lw    $s2, 0x40($sp)
  subu  $t2, $t5, $t7
  addiu $t3, $t2, 1
  sw    $t3, ($s1)
  lw    $s1, 0x3c($sp)
  jr    $ra
   addiu $sp, $sp, 0x80
");

unsigned int controllerCheckDualControllerTypesAllowed(void) {
  if (get_attached_controller_count() >= 2) {
    if (cur_player_get_control_type() >= 4) {
      return 1;
    }
  }
  return 0;
}

int cur_player_get_control_type(void) {
  return pPlayer->cur_player_control_type_0;
}

extern int j_text_trigger;

void cur_player_set_control_type(int type) {
  int langsize;

  pPlayer->cur_player_control_type_0 = type;
  pPlayer->cur_player_control_type_1 = type;
  pPlayer->cur_player_control_type_2 = (float)type;

  langsize = j_text_trigger ? 14 : 10;

  pPlayer->neg_vspacing_for_control_type_entry = -(langsize * type);
  pPlayer->has_set_control_type_data = 1;
}

unsigned int get_cur_player_look_vertical_inverted(void) {
  return cur_player_look_vertical_inverted;
}
void set_cur_player_look_vertical_inverted(unsigned int param_1) {
  cur_player_look_vertical_inverted = param_1;
}

unsigned int cur_player_get_autoaim(void) { return cur_player_autoaim_setting; }
void cur_player_set_autoaim(unsigned int uParm1) {
  cur_player_autoaim_setting = uParm1;
}

unsigned int cur_player_get_lookahead(void) {
  return cur_player_lookahead_setting;
}
void cur_player_set_lookahead(unsigned int uParm1) {
  cur_player_lookahead_setting = uParm1;
}

unsigned int cur_player_get_aim_control(void) { return cur_player_aim_control; }
void cur_player_set_aim_control(unsigned int uParm1) {
  cur_player_aim_control = uParm1;
}

unsigned int cur_player_get_sight_onscreen_control(void) {
  return cur_player_sight_onscreen;
}
void cur_player_set_sight_onscreen_control(unsigned int uParm1) {
  cur_player_sight_onscreen = uParm1;
}

unsigned int cur_player_get_ammo_onscreen_setting(void) {
  return cur_player_ammo_onscreen_setting;
}
void cur_player_set_ammo_onscreen_setting(unsigned int uParm1) {
  cur_player_ammo_onscreen_setting = uParm1;
}

unsigned int cur_player_get_screen_setting(void) {
  return cur_player_screen_setting;
}
void cur_player_set_screen_setting(unsigned int uParm1) {
  cur_player_screen_setting = uParm1;
}

unsigned int get_screen_ratio(void) { return screen_ratio; }
void set_screen_ratio(unsigned int uParm1) { screen_ratio = uParm1; }

void sub_GAME_7F0A4EF8(void) {
  if (watch_soundrelated_maybe == 1)
    watch_soundrelated_maybe = 0;
  else {
    watch_soundrelated_maybe = 1;
    play_sfx_a1(ptr_sfx_buf, 0x9F, 0);
  }
}

void sub_GAME_7F0A4F44(void) { watch_soundrelated_maybe = 0; }

unsigned int is_holding_greater_than_2E_left_on_stick(void) {
  return (get_cur_controller_horz_stick_pos('\0') < -0x2d);
}

unsigned int is_holding_greater_than_2E_right_on_stick(void) {
  return ((get_cur_controller_horz_stick_pos('\0') < 0x2e) ^ 1);
}

unsigned int get_controlstick_lr_enabled(void) {
  return controlstick_lr_enabled;
}

void set_controlstick_lr_disabled(void) { controlstick_lr_enabled = 0; }

int sub_GAME_7F0A4FB0(void) {
  return is_holding_greater_than_2E_left_on_stick() &&
         get_controlstick_lr_enabled();
}

int sub_GAME_7F0A4FEC(void) {
  return is_holding_greater_than_2E_right_on_stick() &&
         get_controlstick_lr_enabled();
}

unsigned int is_holding_greater_than_2E_up_on_stick(void) {
  return (get_cur_controller_vert_stick_pos('\0') < 0x2e) ^ 1;
}

unsigned int is_holding_greater_than_2E_down_on_stick(void) {
  return (get_cur_controller_vert_stick_pos('\0') < -0x2d);
}

unsigned int get_D_80040AE0(void) { return D_80040AE0; }

void set_D_80040AE0_0(void) { D_80040AE0 = 0; }

int sub_GAME_7F0A5088(void) {
  return is_holding_greater_than_2E_up_on_stick() && get_D_80040AE0();
}

int sub_GAME_7F0A50C4(void) {
  return is_holding_greater_than_2E_down_on_stick() && get_D_80040AE0();
}

unsigned int is_holding_less_than_10_up_on_stick(void) {
  return (get_cur_controller_vert_stick_pos('\0') < 0x10) ^ 1;
}

unsigned int is_holding_less_than_10_down_on_stick(void) {
  return (get_cur_controller_vert_stick_pos('\0') < -0xf);
}

unsigned int get_D_80040AE4(void) { return D_80040AE4; }

void set_D_80040AE4_0(void) { D_80040AE4 = 0; }

int sub_GAME_7F0A5160(void) {
  return is_holding_less_than_10_up_on_stick() && get_D_80040AE4() == 0;
}

int sub_GAME_7F0A519C(void) {
  return is_holding_less_than_10_down_on_stick() && get_D_80040AE4() == 0;
}

void sub_GAME_7F0A51D8(void) {
  D_80040B04 = 0x80;
  play_sfx_a1(ptr_sfx_buf, 0xec, NULL);
}

void sub_GAME_7F0A5210(void) {
  set_controlstick_lr_disabled();
  play_sfx_a1(ptr_sfx_buf, 0x9f, NULL);
  if ((D_80040B10 << 0x10) < get_random_value()) {
    sub_GAME_7F0A51D8();
  }
}

asm(R"
.late_rodata
glabel D_80058458
.word 0x40933333 /*4.5999999*/
glabel D_8005845C
.word 0x40933333 /*4.5999999*/
.text
glabel sub_GAME_7F0A526C
  lui   $t6, %hi(watch_soundrelated_maybe) 
  lw    $t6, %lo(watch_soundrelated_maybe)($t6)
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  bnez  $t6, .L7F0A5384
   lui   $t5, %hi(D_800409A4) 
  sw    $zero, 0x1c($sp)
  jal   get_debug_gunwatchpos_flag
   sw    $zero, 0x18($sp)
  bnez  $v0, .L7F0A52C4
   move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 34
  beqz  $v0, .L7F0A52B0
   move  $a0, $zero
  li    $t7, 1
  sw    $t7, 0x1c($sp)
.L7F0A52B0:
  jal   get_controller_buttons_pressed
   li    $a1, 17
  beqz  $v0, .L7F0A52C4
   li    $t8, 1
  sw    $t8, 0x18($sp)
.L7F0A52C4:
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 512
  bnezl $v0, .L7F0A52E8
   li    $t9, 1
  jal   sub_GAME_7F0A4FB0
   nop   
  beqz  $v0, .L7F0A52EC
   li    $t9, 1
.L7F0A52E8:
  sw    $t9, 0x1c($sp)
.L7F0A52EC:
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 256
  bnezl $v0, .L7F0A5310
   li    $t0, 1
  jal   sub_GAME_7F0A4FEC
   nop   
  beqz  $v0, .L7F0A5314
   li    $t0, 1
.L7F0A5310:
  sw    $t0, 0x18($sp)
.L7F0A5314:
  lw    $t1, 0x1c($sp)
  li    $t2, 4
  lui   $at, %hi(D_80040994)
  beql  $t1, $zero, .L7F0A534C
   lw    $t3, 0x18($sp)
  jal   sub_GAME_7F0A5210
   sw    $t2, %lo(D_80040994)($at)
  lui   $at, %hi(D_80058458)
  lwc1  $f12, %lo(D_80058458)($at)
  li    $at, 0x41700000 # 15.000000
  mtc1  $at, $f14
  jal   trigger_watch_zoom
   nop   
  lw    $t3, 0x18($sp)
.L7F0A534C:
  li    $t4, 1
  lui   $at, %hi(D_80040994)
  beql  $t3, $zero, .L7F0A53CC
   lw    $ra, 0x14($sp)
  jal   sub_GAME_7F0A5210
   sw    $t4, %lo(D_80040994)($at)
  lui   $at, %hi(D_8005845C)
  lwc1  $f12, %lo(D_8005845C)($at)
  li    $at, 0x41700000 # 15.000000
  mtc1  $at, $f14
  jal   trigger_watch_zoom
   nop   
  b     .L7F0A53CC
   lw    $ra, 0x14($sp)
.L7F0A5384:
  lw    $t5, %lo(D_800409A4)($t5)
  move  $a0, $zero
  beql  $t5, $zero, .L7F0A53CC
   lw    $ra, 0x14($sp)
  jal   get_controller_buttons_pressed
   li    $a1, 40960
  beqz  $v0, .L7F0A53C8
   lui   $at, %hi(D_800409A4)
  sw    $zero, %lo(D_800409A4)($at)
  jal   set_missionstate
   move  $a0, $zero
  jal   run_title_stage
   nop   
  li    $t6, 1
  lui   $at, %hi(mission_failed_or_aborted)
  jal   deleteCurrentSelectedFolder
   sw    $t6, %lo(mission_failed_or_aborted)($at)
.L7F0A53C8:
  lw    $ra, 0x14($sp)
.L7F0A53CC:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80058460
.word 0x40bccccd /*5.9000001*/
glabel D_80058464
.word 0x407ccccd /*3.95*/
.text
glabel sub_GAME_7F0A53D8
  lui   $t6, %hi(watch_soundrelated_maybe) 
  lw    $t6, %lo(watch_soundrelated_maybe)($t6)
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  bnezl $t6, .L7F0A54F8
   lw    $ra, 0x14($sp)
  sw    $zero, 0x1c($sp)
  jal   get_debug_gunwatchpos_flag
   sw    $zero, 0x18($sp)
  bnez  $v0, .L7F0A5430
   move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 34
  beqz  $v0, .L7F0A541C
   move  $a0, $zero
  li    $t7, 1
  sw    $t7, 0x1c($sp)
.L7F0A541C:
  jal   get_controller_buttons_pressed
   li    $a1, 17
  beqz  $v0, .L7F0A5430
   li    $t8, 1
  sw    $t8, 0x18($sp)
.L7F0A5430:
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 512
  bnezl $v0, .L7F0A5454
   li    $t9, 1
  jal   sub_GAME_7F0A4FB0
   nop   
  beqz  $v0, .L7F0A5458
   li    $t9, 1
.L7F0A5454:
  sw    $t9, 0x1c($sp)
.L7F0A5458:
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 256
  bnezl $v0, .L7F0A547C
   li    $t0, 1
  jal   sub_GAME_7F0A4FEC
   nop   
  beqz  $v0, .L7F0A5480
   li    $t0, 1
.L7F0A547C:
  sw    $t0, 0x18($sp)
.L7F0A5480:
  lw    $t1, 0x1c($sp)
  lui   $at, %hi(D_80040994)
  beql  $t1, $zero, .L7F0A54BC
   lw    $t2, 0x18($sp)
  jal   zero_D_800409A4
   sw    $zero, %lo(D_80040994)($at)
  jal   sub_GAME_7F0A5210
   nop   
  lui   $at, %hi(D_80058460)
  lwc1  $f12, %lo(D_80058460)($at)
  li    $at, 0x41700000 # 15.000000
  mtc1  $at, $f14
  jal   trigger_watch_zoom
   nop   
  lw    $t2, 0x18($sp)
.L7F0A54BC:
  li    $t3, 2
  lui   $at, %hi(D_80040994)
  beql  $t2, $zero, .L7F0A54F8
   lw    $ra, 0x14($sp)
  jal   set_controlstick_lr_disabled
   sw    $t3, %lo(D_80040994)($at)
  jal   sub_GAME_7F0A5210
   nop   
  lui   $at, %hi(D_80058464)
  lwc1  $f12, %lo(D_80058464)($at)
  li    $at, 0x41700000 # 15.000000
  mtc1  $at, $f14
  jal   trigger_watch_zoom
   nop   
  lw    $ra, 0x14($sp)
.L7F0A54F8:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80058468
.word 0x407ccccd /*3.95*/
.text
glabel sub_GAME_7F0A5504
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 546
  bnez  $v0, .L7F0A552C
   nop   
  jal   sub_GAME_7F0A4FB0
   nop   
  beqz  $v0, .L7F0A5554
.L7F0A552C:
   lui   $t6, %hi(watch_soundrelated_maybe) 
  lw    $t6, %lo(watch_soundrelated_maybe)($t6)
  li    $t7, 1
  lui   $at, %hi(D_80040994)
  bnezl $t6, .L7F0A5558
   move  $a0, $zero
  jal   set_controlstick_lr_disabled
   sw    $t7, %lo(D_80040994)($at)
  b     .L7F0A55B8
   lw    $ra, 0x14($sp)
.L7F0A5554:
  move  $a0, $zero
.L7F0A5558:
  jal   get_controller_buttons_pressed
   li    $a1, 273
  bnez  $v0, .L7F0A5574
   nop   
  jal   sub_GAME_7F0A4FEC
   nop   
  beqz  $v0, .L7F0A55B4
.L7F0A5574:
   lui   $t8, %hi(watch_soundrelated_maybe) 
  lw    $t8, %lo(watch_soundrelated_maybe)($t8)
  li    $t9, 2
  lui   $at, %hi(D_80040994)
  bnezl $t8, .L7F0A55B8
   lw    $ra, 0x14($sp)
  jal   zero_D_80040998
   sw    $t9, %lo(D_80040994)($at)
  jal   sub_GAME_7F0A5210
   nop   
  lui   $at, %hi(D_80058468)
  lwc1  $f12, %lo(D_80058468)($at)
  li    $at, 0x41700000 # 15.000000
  mtc1  $at, $f14
  jal   trigger_watch_zoom
   nop   
.L7F0A55B4:
  lw    $ra, 0x14($sp)
.L7F0A55B8:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_8005846C
.word 0x40933333 /*4.5999999*/
.text
glabel sub_GAME_7F0A55C4
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 546
  bnezl $v0, .L7F0A55F0
   move  $a0, $zero
  jal   sub_GAME_7F0A4FB0
   nop   
  beqz  $v0, .L7F0A563C
   move  $a0, $zero
.L7F0A55F0:
  jal   get_controller_buttons_held
   li    $a1, 8192
  bnez  $v0, .L7F0A563C
   lui   $t6, %hi(watch_soundrelated_maybe) 
  lw    $t6, %lo(watch_soundrelated_maybe)($t6)
  li    $t7, 1
  lui   $at, %hi(D_80040994)
  bnezl $t6, .L7F0A5640
   move  $a0, $zero
  jal   sub_GAME_7F0A5210
   sw    $t7, %lo(D_80040994)($at)
  lui   $at, %hi(D_8005846C)
  lwc1  $f12, %lo(D_8005846C)($at)
  li    $at, 0x41700000 # 15.000000
  mtc1  $at, $f14
  jal   trigger_watch_zoom
   nop   
  b     .L7F0A5698
   lw    $ra, 0x14($sp)
.L7F0A563C:
  move  $a0, $zero
.L7F0A5640:
  jal   get_controller_buttons_pressed
   li    $a1, 273
  bnezl $v0, .L7F0A5660
   move  $a0, $zero
  jal   sub_GAME_7F0A4FEC
   nop   
  beqz  $v0, .L7F0A5694
   move  $a0, $zero
.L7F0A5660:
  jal   get_controller_buttons_held
   li    $a1, 8192
  bnez  $v0, .L7F0A5694
   lui   $t8, %hi(watch_soundrelated_maybe) 
  lw    $t8, %lo(watch_soundrelated_maybe)($t8)
  li    $t9, 3
  lui   $at, %hi(D_80040994)
  bnezl $t8, .L7F0A5698
   lw    $ra, 0x14($sp)
  jal   zero_D_8004099C
   sw    $t9, %lo(D_80040994)($at)
  jal   set_controlstick_lr_disabled
   nop   
.L7F0A5694:
  lw    $ra, 0x14($sp)
.L7F0A5698:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80058470
.word 0x40933333 /*4.5999999*/

.text
glabel sub_GAME_7F0A56A4
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 546
  bnezl $v0, .L7F0A56D0
   move  $a0, $zero
  jal   sub_GAME_7F0A4FB0
   nop   
  beqz  $v0, .L7F0A570C
   move  $a0, $zero
.L7F0A56D0:
  jal   get_controller_buttons_held
   li    $a1, 8192
  bnez  $v0, .L7F0A570C
   lui   $t6, %hi(watch_soundrelated_maybe) 
  lw    $t6, %lo(watch_soundrelated_maybe)($t6)
  li    $t7, 2
  lui   $at, %hi(D_80040994)
  bnezl $t6, .L7F0A5710
   move  $a0, $zero
  jal   zero_D_80040998
   sw    $t7, %lo(D_80040994)($at)
  jal   set_controlstick_lr_disabled
   nop   
  b     .L7F0A5778
   lw    $ra, 0x14($sp)
.L7F0A570C:
  move  $a0, $zero
.L7F0A5710:
  jal   get_controller_buttons_pressed
   li    $a1, 273
  bnezl $v0, .L7F0A5730
   move  $a0, $zero
  jal   sub_GAME_7F0A4FEC
   nop   
  beqz  $v0, .L7F0A5774
   move  $a0, $zero
.L7F0A5730:
  jal   get_controller_buttons_held
   li    $a1, 8192
  bnez  $v0, .L7F0A5774
   lui   $t8, %hi(watch_soundrelated_maybe) 
  lw    $t8, %lo(watch_soundrelated_maybe)($t8)
  li    $t9, 4
  lui   $at, %hi(D_80040994)
  bnezl $t8, .L7F0A5778
   lw    $ra, 0x14($sp)
  jal   sub_GAME_7F0A5210
   sw    $t9, %lo(D_80040994)($at)
  lui   $at, %hi(D_80058470)
  lwc1  $f12, %lo(D_80058470)($at)
  li    $at, 0x41700000 # 15.000000
  mtc1  $at, $f14
  jal   trigger_watch_zoom
   nop   
.L7F0A5774:
  lw    $ra, 0x14($sp)
.L7F0A5778:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80058474
.word 0x407ccccd /*3.95*/
glabel D_80058478
.word 0x40bccccd /*5.9000001*/
.text
glabel sub_GAME_7F0A5784
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 546
  bnez  $v0, .L7F0A57AC
   nop   
  jal   sub_GAME_7F0A4FB0
   nop   
  beqz  $v0, .L7F0A57F4
.L7F0A57AC:
   lui   $t6, %hi(watch_soundrelated_maybe) 
  lw    $t6, %lo(watch_soundrelated_maybe)($t6)
  li    $t7, 3
  lui   $at, %hi(D_80040994)
  bnezl $t6, .L7F0A57F8
   move  $a0, $zero
  jal   zero_D_8004099C
   sw    $t7, %lo(D_80040994)($at)
  jal   sub_GAME_7F0A5210
   nop   
  lui   $at, %hi(D_80058474)
  lwc1  $f12, %lo(D_80058474)($at)
  li    $at, 0x41700000 # 15.000000
  mtc1  $at, $f14
  jal   trigger_watch_zoom
   nop   
  b     .L7F0A5854
   lw    $ra, 0x14($sp)
.L7F0A57F4:
  move  $a0, $zero
.L7F0A57F8:
  jal   get_controller_buttons_pressed
   li    $a1, 273
  bnez  $v0, .L7F0A5814
   nop   
  jal   sub_GAME_7F0A4FEC
   nop   
  beqz  $v0, .L7F0A5850
.L7F0A5814:
   lui   $t8, %hi(watch_soundrelated_maybe) 
  lw    $t8, %lo(watch_soundrelated_maybe)($t8)
  lui   $at, %hi(D_80040994)
  bnezl $t8, .L7F0A5854
   lw    $ra, 0x14($sp)
  jal   zero_D_800409A4
   sw    $zero, %lo(D_80040994)($at)
  jal   sub_GAME_7F0A5210
   nop   
  lui   $at, %hi(D_80058478)
  lwc1  $f12, %lo(D_80058478)($at)
  li    $at, 0x41700000 # 15.000000
  mtc1  $at, $f14
  jal   trigger_watch_zoom
   nop   
.L7F0A5850:
  lw    $ra, 0x14($sp)
.L7F0A5854:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

void sub_GAME_7F0A5860(void) {
  if ((get_controller_buttons_pressed('\0', U_CBUTTONS | U_JPAD) != 0) ||
      (sub_GAME_7F0A5088() != 0)) {
    if (watch_soundrelated_maybe == 0) {
      D_80040998 = 1;
      set_D_80040AE0_0();
      return;
    }
  }
  if ((get_controller_buttons_pressed('\0', D_CBUTTONS | D_JPAD) != 0) ||
      (sub_GAME_7F0A50C4() != 0)) {
    if (watch_soundrelated_maybe == 0) {
      D_80040998 = 1;
      set_D_80040AE0_0();
    }
  }
}

void sub_GAME_7F0A5900(void) {
  if ((get_controller_buttons_pressed('\0', U_CBUTTONS | U_JPAD) != 0) ||
      (sub_GAME_7F0A5088() != 0)) {
    if (watch_soundrelated_maybe == 0) {
      D_80040998 = 0;
      set_D_80040AE0_0();
      return;
    }
  }
  if ((get_controller_buttons_pressed('\0', D_CBUTTONS | D_JPAD) != 0) ||
      (sub_GAME_7F0A50C4() != 0)) {
    if (watch_soundrelated_maybe == 0) {
      D_80040998 = 0;
      set_D_80040AE0_0();
    }
  }
}

asm(R"
glabel sub_GAME_7F0A5998
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 2056
  bnez  $v0, .L7F0A59C4
   nop   
  jal   sub_GAME_7F0A5088
   nop   
  beqz  $v0, .L7F0A59EC
   move  $a0, $zero
.L7F0A59C4:
  lui   $v0, %hi(D_8004099C)
  addiu $v0, %lo(D_8004099C) # addiu $v0, $v0, 0x99c
  lw    $t6, ($v0)
  addiu $t7, $t6, -1
  jal   set_D_80040AE0_0
   sw    $t7, ($v0)
  jal   sub_GAME_7F0A4F44
   nop   
  b     .L7F0A5A28
   nop   
.L7F0A59EC:
  jal   get_controller_buttons_pressed
   li    $a1, 1028
  bnez  $v0, .L7F0A5A08
   nop   
  jal   sub_GAME_7F0A50C4
   nop   
  beqz  $v0, .L7F0A5A28
.L7F0A5A08:
   lui   $t8, %hi(D_8004099C) 
  lw    $t8, %lo(D_8004099C)($t8)
  lui   $at, %hi(D_8004099C)
  addiu $t9, $t8, 1
  jal   set_D_80040AE0_0
   sw    $t9, %lo(D_8004099C)($at)
  jal   sub_GAME_7F0A4F44
   nop   
.L7F0A5A28:
  lui   $v1, %hi(D_8004099C)
  addiu $v1, %lo(D_8004099C) # addiu $v1, $v1, 0x99c
  lw    $v0, ($v1)
  slti  $at, $v0, 0xa
  bnez  $at, .L7F0A5A48
   nop   
  b     .L7F0A5A54
   sw    $zero, ($v1)
.L7F0A5A48:
  bgez  $v0, .L7F0A5A54
   li    $t0, 9
  sw    $t0, ($v1)
.L7F0A5A54:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0A5A64
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 2056
  bnezl $v0, .L7F0A5A94
   li    $t6, 9
  jal   sub_GAME_7F0A5088
   nop   
  beqz  $v0, .L7F0A5AB0
   move  $a0, $zero
  li    $t6, 9
.L7F0A5A94:
  lui   $at, %hi(D_8004099C)
  jal   set_D_80040AE0_0
   sw    $t6, %lo(D_8004099C)($at)
  jal   sub_GAME_7F0A4F44
   nop   
  b     .L7F0A5AE8
   lw    $ra, 0x14($sp)
.L7F0A5AB0:
  jal   get_controller_buttons_pressed
   li    $a1, 1028
  bnezl $v0, .L7F0A5AD0
   li    $t7, 1
  jal   sub_GAME_7F0A50C4
   nop   
  beqz  $v0, .L7F0A5AE4
   li    $t7, 1
.L7F0A5AD0:
  lui   $at, %hi(D_8004099C)
  jal   set_D_80040AE0_0
   sw    $t7, %lo(D_8004099C)($at)
  jal   sub_GAME_7F0A4F44
   nop   
.L7F0A5AE4:
  lw    $ra, 0x14($sp)
.L7F0A5AE8:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0A5AF4
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 2056
  bnez  $v0, .L7F0A5B20
   nop   
  jal   sub_GAME_7F0A5088
   nop   
  beqz  $v0, .L7F0A5B3C
   move  $a0, $zero
.L7F0A5B20:
  lui   $at, %hi(D_8004099C)
  jal   set_D_80040AE0_0
   sw    $zero, %lo(D_8004099C)($at)
  jal   sub_GAME_7F0A4F44
   nop   
  b     .L7F0A5B74
   lw    $ra, 0x14($sp)
.L7F0A5B3C:
  jal   get_controller_buttons_pressed
   li    $a1, 1028
  bnezl $v0, .L7F0A5B5C
   li    $t6, 2
  jal   sub_GAME_7F0A50C4
   nop   
  beqz  $v0, .L7F0A5B70
   li    $t6, 2
.L7F0A5B5C:
  lui   $at, %hi(D_8004099C)
  jal   set_D_80040AE0_0
   sw    $t6, %lo(D_8004099C)($at)
  jal   sub_GAME_7F0A4F44
   nop   
.L7F0A5B70:
  lw    $ra, 0x14($sp)
.L7F0A5B74:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_8005847C
.word 0x3dcccccd /*0.1*/
glabel D_80058480
.word 0x3dcccccd /*0.1*/
glabel D_80058484
.word 0x3f0ccccd /*0.55000001*/
glabel D_80058488
.word 0x3dcccccd /*0.1*/
glabel D_8005848C
.word 0x3ee66666 /*0.44999999*/
glabel D_80058490
.word 0x3dcccccd /*0.1*/
.text
glabel sub_GAME_7F0A5B80
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  jal   count_total_items_in_inventory
   nop   
  jal   get_debug_gunwatchpos_flag
   sw    $v0, 0x1c($sp)
  bnez  $v0, .L7F0A5D38
   move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 2056
  bnez  $v0, .L7F0A5BC0
   nop   
  jal   get_cur_controller_vert_stick_pos
   move  $a0, $zero
  slti  $at, $v0, 0x47
  bnez  $at, .L7F0A5C08
.L7F0A5BC0:
   lui   $a2, %hi(D_800409BC)
  addiu $a2, %lo(D_800409BC) # addiu $a2, $a2, 0x9bc
  lwc1  $f0, ($a2)
  lui   $t8, %hi(watch_soundrelated_maybe) 
  trunc.w.s $f4, $f0
  mfc1  $t7, $f4
  nop   
  blezl $t7, .L7F0A5C8C
   move  $a0, $zero
  lw    $t8, %lo(watch_soundrelated_maybe)($t8)
  li    $at, 0x3F800000 # 1.000000
  bnezl $t8, .L7F0A5C8C
   move  $a0, $zero
  mtc1  $at, $f6
  nop   
  sub.s $f8, $f0, $f6
  b     .L7F0A5C88
   swc1  $f8, ($a2)
.L7F0A5C08:
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 1028
  bnez  $v0, .L7F0A5C38
   nop   
  jal   get_cur_controller_vert_stick_pos
   move  $a0, $zero
  slti  $at, $v0, -0x46
  bnez  $at, .L7F0A5C38
   nop   
  b     .L7F0A5C8C
   move  $a0, $zero
.L7F0A5C38:
  lui   $a2, %hi(D_800409BC)
  addiu $a2, %lo(D_800409BC) # addiu $a2, $a2, 0x9bc
  lwc1  $f0, ($a2)
  lw    $t3, 0x1c($sp)
  lui   $t5, %hi(watch_soundrelated_maybe) 
  trunc.w.s $f10, $f0
  addiu $t4, $t3, -1
  mfc1  $t2, $f10
  nop   
  slt   $at, $t2, $t4
  beql  $at, $zero, .L7F0A5C8C
   move  $a0, $zero
  lw    $t5, %lo(watch_soundrelated_maybe)($t5)
  li    $at, 0x3F800000 # 1.000000
  bnezl $t5, .L7F0A5C8C
   move  $a0, $zero
  mtc1  $at, $f16
  nop   
  add.s $f18, $f0, $f16
  swc1  $f18, ($a2)
.L7F0A5C88:
  move  $a0, $zero
.L7F0A5C8C:
  jal   get_controller_buttons_held
   li    $a1, 2056
  lui   $a2, %hi(D_800409BC)
  beqz  $v0, .L7F0A5CDC
   addiu $a2, %lo(D_800409BC) # addiu $a2, $a2, 0x9bc
  lwc1  $f0, ($a2)
  lui   $t8, %hi(watch_soundrelated_maybe) 
  trunc.w.s $f4, $f0
  mfc1  $t7, $f4
  nop   
  blez  $t7, .L7F0A5D38
   nop   
  lw    $t8, %lo(watch_soundrelated_maybe)($t8)
  lui   $at, %hi(D_8005847C)
  bnez  $t8, .L7F0A5D38
   nop   
  lwc1  $f6, %lo(D_8005847C)($at)
  sub.s $f8, $f0, $f6
  b     .L7F0A5D38
   swc1  $f8, ($a2)
.L7F0A5CDC:
  move  $a0, $zero
  jal   get_controller_buttons_held
   li    $a1, 1028
  lui   $a2, %hi(D_800409BC)
  beqz  $v0, .L7F0A5D38
   addiu $a2, %lo(D_800409BC) # addiu $a2, $a2, 0x9bc
  lwc1  $f0, ($a2)
  lw    $t2, 0x1c($sp)
  lui   $t5, %hi(watch_soundrelated_maybe) 
  trunc.w.s $f10, $f0
  addiu $t4, $t2, -1
  mfc1  $t3, $f10
  nop   
  slt   $at, $t3, $t4
  beqz  $at, .L7F0A5D38
   nop   
  lw    $t5, %lo(watch_soundrelated_maybe)($t5)
  lui   $at, %hi(D_80058480)
  bnez  $t5, .L7F0A5D38
   nop   
  lwc1  $f16, %lo(D_80058480)($at)
  add.s $f18, $f0, $f16
  swc1  $f18, ($a2)
.L7F0A5D38:
  jal   get_cur_controller_vert_stick_pos
   move  $a0, $zero
  slti  $at, $v0, 0x1f
  bnez  $at, .L7F0A5DB0
   nop   
  jal   get_cur_controller_vert_stick_pos
   move  $a0, $zero
  slti  $at, $v0, 0x46
  beqz  $at, .L7F0A5DB0
   lui   $t6, %hi(D_800409B8) 
  lw    $t6, %lo(D_800409B8)($t6)
  lui   $t7, %hi(watch_soundrelated_maybe) 
  blez  $t6, .L7F0A5DB0
   nop   
  lw    $t7, %lo(watch_soundrelated_maybe)($t7)
  bnez  $t7, .L7F0A5DB0
   nop   
  jal   get_cur_controller_vert_stick_pos
   move  $a0, $zero
  mtc1  $v0, $f4
  li    $at, 0x43960000 # 300.000000
  mtc1  $at, $f8
  cvt.s.w $f6, $f4
  lui   $a2, %hi(D_800409BC)
  addiu $a2, %lo(D_800409BC) # addiu $a2, $a2, 0x9bc
  lwc1  $f16, ($a2)
  div.s $f10, $f6, $f8
  sub.s $f18, $f16, $f10
  b     .L7F0A5E40
   swc1  $f18, ($a2)
.L7F0A5DB0:
  jal   get_cur_controller_vert_stick_pos
   move  $a0, $zero
  slti  $at, $v0, -0x1e
  beqz  $at, .L7F0A5E40
   nop   
  jal   get_cur_controller_vert_stick_pos
   move  $a0, $zero
  lui   $a2, %hi(D_800409BC)
  slti  $at, $v0, -0x45
  bnez  $at, .L7F0A5E40
   addiu $a2, %lo(D_800409BC) # addiu $a2, $a2, 0x9bc
  lwc1  $f4, ($a2)
  lw    $t2, 0x1c($sp)
  lui   $t4, %hi(watch_soundrelated_maybe) 
  trunc.w.s $f6, $f4
  addiu $t3, $t2, -1
  mfc1  $t9, $f6
  nop   
  slt   $at, $t9, $t3
  beqz  $at, .L7F0A5E40
   nop   
  lw    $t4, %lo(watch_soundrelated_maybe)($t4)
  bnez  $t4, .L7F0A5E40
   nop   
  jal   get_cur_controller_vert_stick_pos
   move  $a0, $zero
  mtc1  $v0, $f8
  li    $at, 0x43960000 # 300.000000
  mtc1  $at, $f10
  cvt.s.w $f16, $f8
  lui   $a2, %hi(D_800409BC)
  addiu $a2, %lo(D_800409BC) # addiu $a2, $a2, 0x9bc
  lwc1  $f4, ($a2)
  div.s $f18, $f16, $f10
  sub.s $f6, $f4, $f18
  swc1  $f6, ($a2)
.L7F0A5E40:
  jal   sub_GAME_7F0A5160
   nop   
  lui   $a2, %hi(D_800409BC)
  beqz  $v0, .L7F0A5E90
   addiu $a2, %lo(D_800409BC) # addiu $a2, $a2, 0x9bc
  lui   $t5, %hi(D_800409B8) 
  lw    $t5, %lo(D_800409B8)($t5)
  lui   $t6, %hi(watch_soundrelated_maybe) 
  blez  $t5, .L7F0A5E90
   nop   
  lw    $t6, %lo(watch_soundrelated_maybe)($t6)
  li    $at, 0x3F800000 # 1.000000
  bnez  $t6, .L7F0A5E90
   nop   
  lwc1  $f8, ($a2)
  mtc1  $at, $f16
  nop   
  sub.s $f10, $f8, $f16
  b     .L7F0A5EE8
   swc1  $f10, ($a2)
.L7F0A5E90:
  jal   sub_GAME_7F0A519C
   nop   
  lui   $a2, %hi(D_800409BC)
  beqz  $v0, .L7F0A5EE8
   addiu $a2, %lo(D_800409BC) # addiu $a2, $a2, 0x9bc
  lw    $t8, 0x1c($sp)
  lui   $t7, %hi(D_800409B8) 
  lw    $t7, %lo(D_800409B8)($t7)
  addiu $t2, $t8, -1
  lui   $t9, %hi(watch_soundrelated_maybe) 
  slt   $at, $t7, $t2
  beqz  $at, .L7F0A5EE8
   nop   
  lw    $t9, %lo(watch_soundrelated_maybe)($t9)
  li    $at, 0x3F800000 # 1.000000
  bnez  $t9, .L7F0A5EE8
   nop   
  lwc1  $f4, ($a2)
  mtc1  $at, $f18
  nop   
  add.s $f6, $f4, $f18
  swc1  $f6, ($a2)
.L7F0A5EE8:
  jal   is_holding_less_than_10_up_on_stick
   nop   
  lui   $a2, %hi(D_800409BC)
  bnez  $v0, .L7F0A5F10
   addiu $a2, %lo(D_800409BC) # addiu $a2, $a2, 0x9bc
  jal   is_holding_less_than_10_down_on_stick
   nop   
  lui   $a2, %hi(D_800409BC)
  beqz  $v0, .L7F0A5F20
   addiu $a2, %lo(D_800409BC) # addiu $a2, $a2, 0x9bc
.L7F0A5F10:
  li    $t3, 1
  lui   $at, %hi(D_80040AE4)
  b     .L7F0A5F28
   sw    $t3, %lo(D_80040AE4)($at)
.L7F0A5F20:
  lui    $at, %hi(D_80040AE4)
  sw    $zero, %lo(D_80040AE4)($at)
.L7F0A5F28:
  lw    $t4, 0x1c($sp)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f10
  mtc1  $t4, $f8
  lwc1  $f0, ($a2)
  li    $at, 0xBF000000 # -0.500000
  cvt.s.w $f16, $f8
  lui   $a1, %hi(D_800409B8)
  sub.s $f2, $f16, $f10
  c.lt.s $f2, $f0
  nop   
  bc1fl .L7F0A5F68
   mtc1  $at, $f2
  swc1  $f2, ($a2)
  lwc1  $f0, ($a2)
  mtc1  $at, $f2
.L7F0A5F68:
  nop   
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F0A5F88
   trunc.w.s $f4, $f0
  swc1  $f2, ($a2)
  lwc1  $f0, ($a2)
  trunc.w.s $f4, $f0
.L7F0A5F88:
  lui   $v0, %hi(j_text_trigger)
  lw    $v0, %lo(j_text_trigger)($v0)
  lui   $at, %hi(D_800409B8)
  mfc1  $t6, $f4
  beqz  $v0, .L7F0A5FA8
   sw    $t6, %lo(D_800409B8)($at)
  b     .L7F0A5FAC
   li    $a3, 14
.L7F0A5FA8:
  li    $a3, 12
.L7F0A5FAC:
  beql  $v0, $zero, .L7F0A5FC0
   li    $a0, 12
  b     .L7F0A5FC0
   li    $a0, 14
  li    $a0, 12
.L7F0A5FC0:
  lw    $a1, %lo(D_800409B8)($a1)
  lui   $t1, %hi(D_800409B0) 
  addiu $t1, %lo(D_800409B0) # addiu $t1, $t1, 0x9b0
  negu  $t7, $a1
  multu $t7, $a3
  lw    $v0, ($t1)
  sll   $t8, $a0, 1
  lui   $t0, %hi(D_800409B4) 
  addiu $t0, %lo(D_800409B4) # addiu $t0, $t0, 0x9b4
  mflo  $t2
  addu  $t9, $t8, $t2
  slt   $at, $t9, $v0
  sw    $t9, ($t0)
  beqz  $at, .L7F0A6024
   move  $v1, $t9
  subu  $t3, $v0, $t9
  li    $at, 3
  div   $zero, $t3, $at
  mflo  $t4
  subu  $t5, $v0, $t4
  addiu $t6, $t5, -1
  sw    $t6, ($t1)
  lui   $at, %hi(D_800409C0)
  b     .L7F0A6060
   sw    $zero, %lo(D_800409C0)($at)
.L7F0A6024:
  slt   $at, $v0, $v1
  beqz  $at, .L7F0A6054
   subu  $t7, $v1, $v0
  li    $at, 3
  div   $zero, $t7, $at
  mflo  $t8
  addu  $t2, $v0, $t8
  addiu $t9, $t2, 1
  sw    $t9, ($t1)
  lui   $at, %hi(D_800409C0)
  b     .L7F0A6060
   sw    $zero, %lo(D_800409C0)($at)
.L7F0A6054:
  li    $t3, 1
  lui   $at, %hi(D_800409C0)
  sw    $t3, %lo(D_800409C0)($at)
.L7F0A6060:
  mtc1  $a1, $f18
  lui   $at, %hi(D_80058484)
  lwc1  $f8, %lo(D_80058484)($at)
  cvt.s.w $f6, $f18
  add.s $f16, $f6, $f8
  c.lt.s $f16, $f0
  nop   
  bc1f  .L7F0A60B0
   move  $a0, $zero
  jal   get_controller_buttons_held
   li    $a1, 65535
  lui   $a2, %hi(D_800409BC)
  bnez  $v0, .L7F0A60B0
   addiu $a2, %lo(D_800409BC) # addiu $a2, $a2, 0x9bc
  lui   $at, %hi(D_80058488)
  lwc1  $f4, %lo(D_80058488)($at)
  lwc1  $f10, ($a2)
  sub.s $f18, $f10, $f4
  b     .L7F0A610C
   swc1  $f18, ($a2)
.L7F0A60B0:
  lui   $t4, %hi(D_800409B8) 
  lw    $t4, %lo(D_800409B8)($t4)
  lui   $at, %hi(D_8005848C)
  lwc1  $f16, %lo(D_8005848C)($at)
  mtc1  $t4, $f6
  lwc1  $f4, ($a2)
  move  $a0, $zero
  cvt.s.w $f8, $f6
  add.s $f10, $f8, $f16
  c.le.s $f4, $f10
  nop   
  bc1fl .L7F0A6110
   lw    $ra, 0x14($sp)
  jal   get_controller_buttons_held
   li    $a1, 65535
  lui   $a2, %hi(D_800409BC)
  bnez  $v0, .L7F0A610C
   addiu $a2, %lo(D_800409BC) # addiu $a2, $a2, 0x9bc
  lui   $at, %hi(D_80058490)
  lwc1  $f6, %lo(D_80058490)($at)
  lwc1  $f18, ($a2)
  add.s $f8, $f18, $f6
  swc1  $f8, ($a2)
.L7F0A610C:
  lw    $ra, 0x14($sp)
.L7F0A6110:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80058494
.word 0x3dcccccd /*0.1*/
glabel D_80058498
.word 0x3dcccccd /*0.1*/
glabel D_8005849C
.word 0x3f0ccccd /*0.55000001*/
glabel D_800584A0
.word 0x3dcccccd /*0.1*/
glabel D_800584A4
.word 0x3ee66666 /*0.44999999*/
glabel D_800584A8
.word 0x3dcccccd /*0.1*/
.text
glabel sub_GAME_7F0A611C
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  move  $s0, $a0
  sw    $a1, 0x24($sp)
  sw    $a2, 0x28($sp)
  jal   get_debug_gunwatchpos_flag
   sw    $a3, 0x2c($sp)
  bnez  $v0, .L7F0A6298
   move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 2056
  bnezl $v0, .L7F0A616C
   lwc1  $f0, ($s0)
  jal   get_cur_controller_vert_stick_pos
   move  $a0, $zero
  slti  $at, $v0, 0x47
  bnez  $at, .L7F0A61A0
   move  $a0, $zero
  lwc1  $f0, ($s0)
.L7F0A616C:
  lw    $t8, 0x3c($sp)
  trunc.w.s $f4, $f0
  mfc1  $t7, $f4
  nop   
  blezl $t7, .L7F0A6208
   move  $a0, $zero
  beqz  $t8, .L7F0A6204
   li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  nop   
  sub.s $f8, $f0, $f6
  b     .L7F0A6204
   swc1  $f8, ($s0)
.L7F0A61A0:
  jal   get_controller_buttons_pressed
   li    $a1, 1028
  bnezl $v0, .L7F0A61C8
   lwc1  $f0, ($s0)
  jal   get_cur_controller_vert_stick_pos
   move  $a0, $zero
  slti  $at, $v0, -0x46
  beql  $at, $zero, .L7F0A6208
   move  $a0, $zero
  lwc1  $f0, ($s0)
.L7F0A61C8:
  lw    $t1, 0x28($sp)
  lw    $t3, 0x3c($sp)
  trunc.w.s $f10, $f0
  addiu $t2, $t1, -1
  mfc1  $t0, $f10
  nop   
  slt   $at, $t0, $t2
  beql  $at, $zero, .L7F0A6208
   move  $a0, $zero
  beqz  $t3, .L7F0A6204
   li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f16
  nop   
  add.s $f18, $f0, $f16
  swc1  $f18, ($s0)
.L7F0A6204:
  move  $a0, $zero
.L7F0A6208:
  jal   get_controller_buttons_held
   li    $a1, 2056
  beqz  $v0, .L7F0A624C
   move  $a0, $zero
  lwc1  $f0, ($s0)
  lw    $t6, 0x3c($sp)
  trunc.w.s $f4, $f0
  mfc1  $t5, $f4
  nop   
  blez  $t5, .L7F0A6298
   nop   
  beqz  $t6, .L7F0A6298
   lui   $at, %hi(D_80058494)
  lwc1  $f6, %lo(D_80058494)($at)
  sub.s $f8, $f0, $f6
  b     .L7F0A6298
   swc1  $f8, ($s0)
.L7F0A624C:
  jal   get_controller_buttons_held
   li    $a1, 1028
  beqz  $v0, .L7F0A6298
   nop   
  lwc1  $f0, ($s0)
  lw    $t9, 0x28($sp)
  lw    $t0, 0x3c($sp)
  trunc.w.s $f10, $f0
  addiu $t1, $t9, -1
  mfc1  $t8, $f10
  nop   
  slt   $at, $t8, $t1
  beqz  $at, .L7F0A6298
   nop   
  beqz  $t0, .L7F0A6298
   lui   $at, %hi(D_80058498)
  lwc1  $f16, %lo(D_80058498)($at)
  add.s $f18, $f0, $f16
  swc1  $f18, ($s0)
.L7F0A6298:
  jal   get_cur_controller_vert_stick_pos
   move  $a0, $zero
  slti  $at, $v0, 0x1f
  bnez  $at, .L7F0A6304
   nop   
  jal   get_cur_controller_vert_stick_pos
   move  $a0, $zero
  slti  $at, $v0, 0x46
  beqz  $at, .L7F0A6304
   lw    $t2, 0x24($sp)
  lw    $t3, ($t2)
  lw    $t4, 0x3c($sp)
  blez  $t3, .L7F0A6304
   nop   
  beqz  $t4, .L7F0A6304
   nop   
  jal   get_cur_controller_vert_stick_pos
   move  $a0, $zero
  mtc1  $v0, $f4
  li    $at, 0x43960000 # 300.000000
  mtc1  $at, $f8
  cvt.s.w $f6, $f4
  lwc1  $f16, ($s0)
  div.s $f10, $f6, $f8
  sub.s $f18, $f16, $f10
  b     .L7F0A6384
   swc1  $f18, ($s0)
.L7F0A6304:
  jal   get_cur_controller_vert_stick_pos
   move  $a0, $zero
  slti  $at, $v0, -0x1e
  beqz  $at, .L7F0A6384
   nop   
  jal   get_cur_controller_vert_stick_pos
   move  $a0, $zero
  slti  $at, $v0, -0x45
  bnez  $at, .L7F0A6384
   nop   
  lwc1  $f4, ($s0)
  lw    $t7, 0x28($sp)
  lw    $t8, 0x3c($sp)
  trunc.w.s $f6, $f4
  addiu $t9, $t7, -1
  mfc1  $t6, $f6
  nop   
  slt   $at, $t6, $t9
  beqz  $at, .L7F0A6384
   nop   
  beqz  $t8, .L7F0A6384
   nop   
  jal   get_cur_controller_vert_stick_pos
   move  $a0, $zero
  mtc1  $v0, $f8
  li    $at, 0x43960000 # 300.000000
  mtc1  $at, $f10
  cvt.s.w $f16, $f8
  lwc1  $f4, ($s0)
  div.s $f18, $f16, $f10
  sub.s $f6, $f4, $f18
  swc1  $f6, ($s0)
.L7F0A6384:
  jal   sub_GAME_7F0A5160
   nop   
  beqz  $v0, .L7F0A63C4
   lw    $t1, 0x24($sp)
  lw    $t0, ($t1)
  lw    $t2, 0x3c($sp)
  blez  $t0, .L7F0A63C4
   nop   
  beqz  $t2, .L7F0A63C4
   li    $at, 0x3F800000 # 1.000000
  lwc1  $f8, ($s0)
  mtc1  $at, $f16
  nop   
  sub.s $f10, $f8, $f16
  b     .L7F0A640C
   swc1  $f10, ($s0)
.L7F0A63C4:
  jal   sub_GAME_7F0A519C
   nop   
  beqz  $v0, .L7F0A640C
   lw    $t3, 0x24($sp)
  lw    $t5, 0x28($sp)
  lw    $t4, ($t3)
  lw    $t6, 0x3c($sp)
  addiu $t7, $t5, -1
  slt   $at, $t4, $t7
  beqz  $at, .L7F0A640C
   nop   
  beqz  $t6, .L7F0A640C
   li    $at, 0x3F800000 # 1.000000
  lwc1  $f4, ($s0)
  mtc1  $at, $f18
  nop   
  add.s $f6, $f4, $f18
  swc1  $f6, ($s0)
.L7F0A640C:
  jal   is_holding_less_than_10_up_on_stick
   nop   
  bnezl $v0, .L7F0A6430
   li    $t9, 1
  jal   is_holding_less_than_10_down_on_stick
   nop   
  beqz  $v0, .L7F0A643C
   lui   $at, %hi(D_80040AE4)
  li    $t9, 1
.L7F0A6430:
  lui    $at, %hi(D_80040AE4)
  b     .L7F0A6440
   sw    $t9, %lo(D_80040AE4)($at)
.L7F0A643C:
  sw    $zero, %lo(D_80040AE4)($at)
.L7F0A6440:
  lw    $t8, 0x28($sp)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f10
  mtc1  $t8, $f8
  lwc1  $f0, ($s0)
  li    $at, 0xBF000000 # -0.500000
  cvt.s.w $f16, $f8
  sub.s $f2, $f16, $f10
  c.lt.s $f2, $f0
  nop   
  bc1fl .L7F0A647C
   mtc1  $at, $f2
  swc1  $f2, ($s0)
  lwc1  $f0, ($s0)
  mtc1  $at, $f2
.L7F0A647C:
  nop   
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F0A649C
   trunc.w.s $f4, $f0
  swc1  $f2, ($s0)
  lwc1  $f0, ($s0)
  trunc.w.s $f4, $f0
.L7F0A649C:
  lw    $a1, 0x40($sp)
  lw    $t2, 0x24($sp)
  lw    $a0, 0x30($sp)
  mfc1  $t0, $f4
  lw    $a2, 0x2c($sp)
  negu  $t3, $t0
  multu $t3, $a1
  sw    $t0, ($t2)
  lw    $t4, 0x38($sp)
  mflo  $t5
  nop   
  nop   
  multu $t4, $a1
  mflo  $t7
  addu  $t6, $t5, $t7
  sw    $t6, ($a0)
  lw    $v0, ($a2)
  move  $v1, $t6
  move  $a0, $zero
  slt   $at, $t6, $v0
  beqz  $at, .L7F0A6518
   subu  $t9, $v0, $t6
  li    $at, 3
  div   $zero, $t9, $at
  mflo  $t8
  subu  $t1, $v0, $t8
  addiu $t2, $t1, -1
  sw    $t2, ($a2)
  lw    $t0, 0x34($sp)
  b     .L7F0A6554
   sw    $zero, ($t0)
.L7F0A6518:
  slt   $at, $v0, $v1
  beqz  $at, .L7F0A654C
   lw    $t8, 0x34($sp)
  subu  $t3, $v1, $v0
  li    $at, 3
  div   $zero, $t3, $at
  mflo  $t4
  addu  $t5, $v0, $t4
  addiu $t7, $t5, 1
  sw    $t7, ($a2)
  lw    $t6, 0x34($sp)
  b     .L7F0A6554
   sw    $zero, ($t6)
.L7F0A654C:
  li    $t9, 1
  sw    $t9, ($t8)
.L7F0A6554:
  lw    $t1, 0x24($sp)
  lui   $at, %hi(D_8005849C)
  lwc1  $f8, %lo(D_8005849C)($at)
  lw    $t2, ($t1)
  lwc1  $f10, ($s0)
  mtc1  $t2, $f18
  nop   
  cvt.s.w $f6, $f18
  add.s $f16, $f6, $f8
  c.lt.s $f16, $f10
  nop   
  bc1fl .L7F0A65B0
   lw    $t0, 0x24($sp)
  jal   get_controller_buttons_held
   li    $a1, 65535
  bnez  $v0, .L7F0A65AC
   lui   $at, %hi(D_800584A0)
  lwc1  $f4, ($s0)
  lwc1  $f18, %lo(D_800584A0)($at)
  sub.s $f6, $f4, $f18
  b     .L7F0A6604
   swc1  $f6, ($s0)
.L7F0A65AC:
  lw    $t0, 0x24($sp)
.L7F0A65B0:
  lui   $at, %hi(D_800584A4)
  lwc1  $f10, %lo(D_800584A4)($at)
  lw    $t3, ($t0)
  lwc1  $f18, ($s0)
  move  $a0, $zero
  mtc1  $t3, $f8
  nop   
  cvt.s.w $f16, $f8
  add.s $f4, $f16, $f10
  c.le.s $f18, $f4
  nop   
  bc1fl .L7F0A6608
   lw    $ra, 0x1c($sp)
  jal   get_controller_buttons_held
   li    $a1, 65535
  bnez  $v0, .L7F0A6604
   lui   $at, %hi(D_800584A8)
  lwc1  $f6, ($s0)
  lwc1  $f8, %lo(D_800584A8)($at)
  add.s $f16, $f6, $f8
  swc1  $f16, ($s0)
.L7F0A6604:
  lw    $ra, 0x1c($sp)
.L7F0A6608:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

void sub_GAME_7F0A6618(void) {
  if ((get_controller_buttons_pressed('\0', U_CBUTTONS | U_JPAD) != 0) ||
      (sub_GAME_7F0A5088() != 0)) {
    D_800409A0 = 4;
    set_D_80040AE0_0();
    sub_GAME_7F0A4F44();
  } else {
  }
  if ((get_controller_buttons_pressed('\0', D_CBUTTONS | D_JPAD) != 0) ||
      (sub_GAME_7F0A50C4() != 0)) {
    D_800409A0 = 1;
    set_D_80040AE0_0();
    sub_GAME_7F0A4F44();
  } else {
  }
}

asm(R"
glabel sub_GAME_7F0A66A0
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 2056
  bnez  $v0, .L7F0A66CC
   nop   
  jal   sub_GAME_7F0A5088
   nop   
  beqz  $v0, .L7F0A66E8
   move  $a0, $zero
.L7F0A66CC:
  lui   $at, %hi(D_800409A0)
  jal   set_D_80040AE0_0
   sw    $zero, %lo(D_800409A0)($at)
  jal   sub_GAME_7F0A4F44
   nop   
  b     .L7F0A6720
   lw    $ra, 0x14($sp)
.L7F0A66E8:
  jal   get_controller_buttons_pressed
   li    $a1, 1028
  bnezl $v0, .L7F0A6708
   li    $t6, 2
  jal   sub_GAME_7F0A50C4
   nop   
  beqz  $v0, .L7F0A671C
   li    $t6, 2
.L7F0A6708:
  lui   $at, %hi(D_800409A0)
  jal   set_D_80040AE0_0
   sw    $t6, %lo(D_800409A0)($at)
  jal   sub_GAME_7F0A4F44
   nop   
.L7F0A671C:
  lw    $ra, 0x14($sp)
.L7F0A6720:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0A672C
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 2056
  bnezl $v0, .L7F0A675C
   li    $t6, 1
  jal   sub_GAME_7F0A5088
   nop   
  beqz  $v0, .L7F0A6778
   move  $a0, $zero
  li    $t6, 1
.L7F0A675C:
  lui   $at, %hi(D_800409A0)
  jal   set_D_80040AE0_0
   sw    $t6, %lo(D_800409A0)($at)
  jal   sub_GAME_7F0A4F44
   nop   
  b     .L7F0A67B0
   lw    $ra, 0x14($sp)
.L7F0A6778:
  jal   get_controller_buttons_pressed
   li    $a1, 1028
  bnezl $v0, .L7F0A6798
   li    $t7, 3
  jal   sub_GAME_7F0A50C4
   nop   
  beqz  $v0, .L7F0A67AC
   li    $t7, 3
.L7F0A6798:
  lui   $at, %hi(D_800409A0)
  jal   set_D_80040AE0_0
   sw    $t7, %lo(D_800409A0)($at)
  jal   sub_GAME_7F0A4F44
   nop   
.L7F0A67AC:
  lw    $ra, 0x14($sp)
.L7F0A67B0:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0A67BC
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 2056
  bnezl $v0, .L7F0A67EC
   li    $t6, 2
  jal   sub_GAME_7F0A5088
   nop   
  beqz  $v0, .L7F0A6808
   move  $a0, $zero
  li    $t6, 2
.L7F0A67EC:
  lui   $at, %hi(D_800409A0)
  jal   set_D_80040AE0_0
   sw    $t6, %lo(D_800409A0)($at)
  jal   sub_GAME_7F0A4F44
   nop   
  b     .L7F0A6840
   lw    $ra, 0x14($sp)
.L7F0A6808:
  jal   get_controller_buttons_pressed
   li    $a1, 1028
  bnezl $v0, .L7F0A6828
   li    $t7, 4
  jal   sub_GAME_7F0A50C4
   nop   
  beqz  $v0, .L7F0A683C
   li    $t7, 4
.L7F0A6828:
  lui   $at, %hi(D_800409A0)
  jal   set_D_80040AE0_0
   sw    $t7, %lo(D_800409A0)($at)
  jal   sub_GAME_7F0A4F44
   nop   
.L7F0A683C:
  lw    $ra, 0x14($sp)
.L7F0A6840:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0A684C
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 2056
  bnezl $v0, .L7F0A687C
   li    $t6, 3
  jal   sub_GAME_7F0A5088
   nop   
  beqz  $v0, .L7F0A6898
   move  $a0, $zero
  li    $t6, 3
.L7F0A687C:
  lui   $at, %hi(D_800409A0)
  jal   set_D_80040AE0_0
   sw    $t6, %lo(D_800409A0)($at)
  jal   sub_GAME_7F0A4F44
   nop   
  b     .L7F0A68CC
   lw    $ra, 0x14($sp)
.L7F0A6898:
  jal   get_controller_buttons_pressed
   li    $a1, 1028
  bnez  $v0, .L7F0A68B4
   nop   
  jal   sub_GAME_7F0A50C4
   nop   
  beqz  $v0, .L7F0A68C8
.L7F0A68B4:
   lui   $at, %hi(D_800409A0)
  jal   set_D_80040AE0_0
   sw    $zero, %lo(D_800409A0)($at)
  jal   sub_GAME_7F0A4F44
   nop   
.L7F0A68C8:
  lw    $ra, 0x14($sp)
.L7F0A68CC:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_800584AC
.word 0x48507100 /*213444.0*/
.text
glabel sub_GAME_7F0A68D8
  lui   $t1, %hi(D_80040B40) 
  addiu $t1, %lo(D_80040B40) # addiu $t1, $t1, 0xb40
  lw    $v0, ($t1)
  lui   $at, %hi(D_800584AC)
  lwc1  $f4, %lo(D_800584AC)($at)
  multu $v0, $v0
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  mflo  $t6
  mtc1  $t6, $f6
  nop   
  cvt.s.w $f8, $f6
  jal   sqrtf
   sub.s $f12, $f4, $f8
  trunc.w.s $f10, $f0
  lui   $t1, %hi(D_80040B40) 
  lui   $a3, %hi(D_80040B08)
  addiu $t1, %lo(D_80040B40) # addiu $t1, $t1, 0xb40
  mfc1  $a1, $f10
  lw    $a0, 0x18($sp)
  addiu $a3, %lo(D_80040B08) # addiu $a3, $a3, 0xb08
  move  $v1, $zero
  li    $t2, 8
  li    $t0, 3
  li    $a2, 160
  li    $v0, -1
.L7F0A6944:
  multu $a1, $v0
  sh    $zero, 2($a0)
  addiu $v0, $v0, 2
  addiu $a0, $a0, 0x10
  mflo  $t8
  sh    $t8, -0x10($a0)
  lw    $t9, ($t1)
  sh    $zero, -0xa($a0)
  sh    $zero, -8($a0)
  addu  $t3, $v1, $t9
  sh    $t3, -0xc($a0)
  sh    $zero, -6($a0)
  sb    $zero, -4($a0)
  sb    $a2, -3($a0)
  sb    $zero, -2($a0)
  lw    $t4, ($a3)
  bne   $v0, $t0, .L7F0A6944
   sb    $t4, -1($a0)
  addiu $v1, $v1, 4
  bnel  $v1, $t2, .L7F0A6944
   li    $v0, -1
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

void sub_GAME_7F0A69A8(void) {
  if (get_attached_controller_count() < 2)
    D_800409D8 = 4;
  else
    D_800409D8 = 8;
  sub_GAME_7F0A4F44();
  D_80040994 = 0; // watch_screen_index = 0;
  D_800409A0 = 4;
  D_800409C8 = 0.999f;
  D_800409CC = 0.9999f;
  calculate_equip_cur_item(); // calculate_equip_cur_item();
}

asm(R"
.late_rodata
glabel D_800584B8
.word 0x40490fdb /*3.1415927*/
glabel D_800584BC
.word 0x40c90fdb /*6.2831855*/
glabel D_800584C0
.word 0xc0490fdb /*-3.1415927*/
glabel D_800584C4
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F0A6A2C
  lui   $at, %hi(D_800584B8)
  lwc1  $f4, %lo(D_800584B8)($at)
  lui   $at, %hi(D_800584C0)
  c.lt.s $f4, $f12
  nop   
  bc1f  .L7F0A6A58
   nop   
  lui   $at, %hi(D_800584BC)
  lwc1  $f6, %lo(D_800584BC)($at)
  jr    $ra
   sub.s $f0, $f12, $f6

.L7F0A6A58:
  lwc1  $f8, %lo(D_800584C0)($at)
  lui   $at, %hi(D_800584C4)
  c.lt.s $f12, $f8
  nop   
  bc1f  .L7F0A6A78
   nop   
  lwc1  $f10, %lo(D_800584C4)($at)
  add.s $f12, $f12, $f10
.L7F0A6A78:
  jr    $ra
   mov.s $f0, $f12
");

#ifdef VERSION_US
asm(R"
.late_rodata
glabel D_800584C8
.word 0x40c90fdb /*6.2831855*/

/*D:800584CC*/
glabel jpt_800584CC
.word .L7F0A6E04
.word .L7F0A6ED0
.word .L7F0A6E14
.word .L7F0A6E60
.word .L7F0A6EC0

/*D:800584E0*/
glabel jpt_800584E0
.word .L7F0A6E88
.word .L7F0A6E98
.word .L7F0A6EA8
.word .L7F0A6EA8
.word .L7F0A6EA8
.word .L7F0A6EA8
.word .L7F0A6EA8
.word .L7F0A6EA8
.word .L7F0A6EA8
.word .L7F0A6EA8

.text
glabel sub_GAME_7F0A6A80
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 4096
  beqz  $v0, .L7F0A6AA4
   nop   
  jal   set_open_close_solo_watch_menu_to1
   nop   
.L7F0A6AA4:
  lui   $t6, %hi(controlstick_lr_enabled) 
  lw    $t6, %lo(controlstick_lr_enabled)($t6)
  bnez  $t6, .L7F0A6B4C
   nop   
  jal   get_cur_controller_horz_stick_pos
   move  $a0, $zero
  slti  $at, $v0, -0xa
  bnez  $at, .L7F0A6AE8
   nop   
  jal   get_cur_controller_horz_stick_pos
   move  $a0, $zero
  slti  $at, $v0, 0xb
  beqz  $at, .L7F0A6AE8
   li    $t7, 1
  lui   $at, %hi(controlstick_lr_enabled)
  b     .L7F0A6B4C
   sw    $t7, %lo(controlstick_lr_enabled)($at)
.L7F0A6AE8:
  jal   get_cur_controller_horz_stick_pos
   move  $a0, $zero
  slti  $at, $v0, 0xb
  beqz  $at, .L7F0A6B1C
   nop   
  jal   controller_7000C174
   move  $a0, $zero
  slti  $at, $v0, 0xb
  bnez  $at, .L7F0A6B1C
   li    $t8, 1
  lui   $at, %hi(controlstick_lr_enabled)
  b     .L7F0A6B4C
   sw    $t8, %lo(controlstick_lr_enabled)($at)
.L7F0A6B1C:
  jal   get_cur_controller_horz_stick_pos
   move  $a0, $zero
  slti  $at, $v0, -0xa
  bnez  $at, .L7F0A6B4C
   nop   
  jal   controller_7000C174
   move  $a0, $zero
  slti  $at, $v0, -0xa
  beqz  $at, .L7F0A6B4C
   li    $t9, 1
  lui   $at, %hi(controlstick_lr_enabled)
  sw    $t9, %lo(controlstick_lr_enabled)($at)
.L7F0A6B4C:
  lui   $t0, %hi(D_80040AE0) 
  lw    $t0, %lo(D_80040AE0)($t0)
  bnez  $t0, .L7F0A6BF4
   nop   
  jal   get_cur_controller_vert_stick_pos
   move  $a0, $zero
  slti  $at, $v0, -0xa
  bnez  $at, .L7F0A6B90
   nop   
  jal   get_cur_controller_vert_stick_pos
   move  $a0, $zero
  slti  $at, $v0, 0xb
  beqz  $at, .L7F0A6B90
   li    $t1, 1
  lui   $at, %hi(D_80040AE0)
  b     .L7F0A6BF4
   sw    $t1, %lo(D_80040AE0)($at)
.L7F0A6B90:
  jal   get_cur_controller_vert_stick_pos
   move  $a0, $zero
  slti  $at, $v0, 0xb
  beqz  $at, .L7F0A6BC4
   nop   
  jal   controller_7000C284
   move  $a0, $zero
  slti  $at, $v0, 0xb
  bnez  $at, .L7F0A6BC4
   li    $t2, 1
  lui   $at, %hi(D_80040AE0)
  b     .L7F0A6BF4
   sw    $t2, %lo(D_80040AE0)($at)
.L7F0A6BC4:
  jal   get_cur_controller_vert_stick_pos
   move  $a0, $zero
  slti  $at, $v0, -0xa
  bnez  $at, .L7F0A6BF4
   nop   
  jal   controller_7000C284
   move  $a0, $zero
  slti  $at, $v0, -0xa
  beqz  $at, .L7F0A6BF4
   li    $t3, 1
  lui   $at, %hi(D_80040AE0)
  sw    $t3, %lo(D_80040AE0)($at)
.L7F0A6BF4:
  lui   $v1, %hi(D_80040AF8)
  addiu $v1, %lo(D_80040AF8) # addiu $v1, $v1, 0xaf8
  lw    $v0, ($v1)
  bgez  $v0, .L7F0A6C20
   addiu $t6, $v0, -1
  lui   $a0, %hi(D_80040AF4)
  addiu $a0, %lo(D_80040AF4) # addiu $a0, $a0, 0xaf4
  lw    $t4, ($a0)
  lui   $at, 0xfff0
  addu  $t5, $t4, $at
  sw    $t5, ($a0)
.L7F0A6C20:
  lui   $a0, %hi(D_80040AF4)
  addiu $a0, %lo(D_80040AF4) # addiu $a0, $a0, 0xaf4
  lw    $t7, ($a0)
  lui   $at, (0x005F00A1 >> 16) # lui $at, 0x5f
  ori   $at, (0x005F00A1 & 0xFFFF) # ori $at, $at, 0xa1
  sltu  $at, $t7, $at
  beqz  $at, .L7F0A6C54
   sw    $t6, ($v1)
  lui   $t8, (0x00FF00A0 >> 16) # lui $t8, 0xff
  ori   $t8, (0x00FF00A0 & 0xFFFF) # ori $t8, $t8, 0xa0
  li    $t9, 15
  sw    $t8, ($a0)
  sw    $t9, ($v1)
.L7F0A6C54:
  lui   $v1, %hi(D_80040B00)
  addiu $v1, %lo(D_80040B00) # addiu $v1, $v1, 0xb00
  lw    $v0, ($v1)
  lui   $a0, %hi(D_80040AFC)
  addiu $a0, %lo(D_80040AFC) # addiu $a0, $a0, 0xafc
  bgez  $v0, .L7F0A6C7C
   lui   $t6, %hi(D_80048498) 
  lw    $t0, ($a0)
  addiu $t1, $t0, -0x10
  sw    $t1, ($a0)
.L7F0A6C7C:
  lui   $a0, %hi(D_80040AFC)
  addiu $a0, %lo(D_80040AFC) # addiu $a0, $a0, 0xafc
  lw    $t3, ($a0)
  addiu $t2, $v0, -1
  sw    $t2, ($v1)
  sltiu $at, $t3, 0x60
  beqz  $at, .L7F0A6CA8
   li    $t4, 255
  li    $t5, 15
  sw    $t4, ($a0)
  sw    $t5, ($v1)
.L7F0A6CA8:
  lw    $t6, %lo(D_80048498)($t6)
  lui   $at, %hi(D_80040B1C)
  lwc1  $f4, %lo(D_80040B1C)($at)
  mtc1  $t6, $f6
  lui   $at, %hi(D_800584C8)
  lwc1  $f16, %lo(D_800584C8)($at)
  cvt.s.w $f8, $f6
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f6
  lui   $v0, %hi(D_80040B14)
  addiu $v0, %lo(D_80040B14) # addiu $v0, $v0, 0xb14
  mul.s $f10, $f4, $f8
  lwc1  $f8, ($v0)
  mul.s $f18, $f10, $f16
  div.s $f4, $f18, $f6
  add.s $f10, $f8, $f4
  swc1  $f10, ($v0)
  jal   sub_GAME_7F0A6A2C
   lwc1  $f12, ($v0)
  lui   $v0, %hi(D_80040B14)
  addiu $v0, %lo(D_80040B14) # addiu $v0, $v0, 0xb14
  swc1  $f0, ($v0)
  lui   $t7, %hi(D_80040B0C) 
  lw    $t7, %lo(D_80040B0C)($t7)
  sll   $t8, $t7, 0x10
  jal   get_random_value
   sw    $t8, 0x1c($sp)
  lw    $t9, 0x1c($sp)
  sltu  $at, $t9, $v0
  beqz  $at, .L7F0A6D2C
   nop   
  jal   sub_GAME_7F0A51D8
   nop   
.L7F0A6D2C:
  lui   $a0, %hi(D_80040B04)
  addiu $a0, %lo(D_80040B04) # addiu $a0, $a0, 0xb04
  lw    $v1, ($a0)
  slti  $at, $v1, 0xe0
  beql  $at, $zero, .L7F0A6D68
   slti  $at, $v1, 0xe1
  jal   get_random_value
   nop   
  lui   $a0, %hi(D_80040B04)
  addiu $a0, %lo(D_80040B04) # addiu $a0, $a0, 0xb04
  lw    $t0, ($a0)
  srl   $t1, $v0, 0x1e
  addu  $v1, $t0, $t1
  sw    $v1, ($a0)
  slti  $at, $v1, 0xe1
.L7F0A6D68:
  bnez  $at, .L7F0A6D78
   li    $t0, 342
  li    $v1, 224
  sw    $v1, ($a0)
.L7F0A6D78:
  negu  $t4, $v1
  sll   $t5, $t4, 2
  lui   $a0, %hi(D_80040B40)
  addiu $t6, $t5, 0x380
  lui   $at, %hi(D_80040B08)
  addiu $a0, %lo(D_80040B40) # addiu $a0, $a0, 0xb40
  sw    $t6, %lo(D_80040B08)($at)
  lw    $t7, ($a0)
  addiu $v0, $t7, -4
  slti  $at, $v0, 0x157
  bnez  $at, .L7F0A6DB0
   sw    $v0, ($a0)
  li    $v0, -342
  sw    $v0, ($a0)
.L7F0A6DB0:
  slti  $at, $v0, -0x156
  beqz  $at, .L7F0A6DC0
   lui   $v0, %hi(D_80040B44)
  sw    $t0, ($a0)
.L7F0A6DC0:
  addiu $v0, %lo(D_80040B44) # addiu $v0, $v0, 0xb44
  lh    $t1, ($v0)
  lui   $t5, %hi(D_80040994) 
  addiu $t2, $t1, 1
  sh    $t2, ($v0)
  lh    $t3, ($v0)
  andi  $t4, $t3, 1
  sh    $t4, ($v0)
  lw    $t5, %lo(D_80040994)($t5)
  sltiu $at, $t5, 5
  beqz  $at, .L7F0A6ED8
   sll   $t5, $t5, 2
  lui   $at, %hi(jpt_800584CC)
  addu  $at, $at, $t5
  lw    $t5, %lo(jpt_800584CC)($at)
  jr    $t5
   nop   
.L7F0A6E04:
  jal   sub_GAME_7F0A526C
   nop   
  b     .L7F0A6EDC
   lw    $ra, 0x14($sp)
.L7F0A6E14:
  lui   $v0, %hi(D_80040998)
  lw    $v0, %lo(D_80040998)($v0)
  li    $at, 1
  beqz  $v0, .L7F0A6E38
   nop   
  beq   $v0, $at, .L7F0A6E48
   nop   
  b     .L7F0A6E50
   nop   
.L7F0A6E38:
  jal   sub_GAME_7F0A5860
   nop   
  b     .L7F0A6E50
   nop   
.L7F0A6E48:
  jal   sub_GAME_7F0A5900
   nop   
.L7F0A6E50:
  jal   sub_GAME_7F0A55C4
   nop   
  b     .L7F0A6EDC
   lw    $ra, 0x14($sp)
.L7F0A6E60:
  lui   $t6, %hi(D_8004099C) 
  lw    $t6, %lo(D_8004099C)($t6)
  sltiu $at, $t6, 0xa
  beqz  $at, .L7F0A6EB0
   sll   $t6, $t6, 2
  lui   $at, %hi(jpt_800584E0)
  addu  $at, $at, $t6
  lw    $t6, %lo(jpt_800584E0)($at)
  jr    $t6
   nop   
.L7F0A6E88:
  jal   sub_GAME_7F0A5A64
   nop   
  b     .L7F0A6EB0
   nop   
.L7F0A6E98:
  jal   sub_GAME_7F0A5AF4
   nop   
  b     .L7F0A6EB0
   nop   
.L7F0A6EA8:
  jal   sub_GAME_7F0A5998
   nop   
.L7F0A6EB0:
  jal   sub_GAME_7F0A56A4
   nop   
  b     .L7F0A6EDC
   lw    $ra, 0x14($sp)
.L7F0A6EC0:
  jal   sub_GAME_7F0A5784
   nop   
  b     .L7F0A6EDC
   lw    $ra, 0x14($sp)
.L7F0A6ED0:
  jal   sub_GAME_7F0A53D8
   nop   
.L7F0A6ED8:
  lw    $ra, 0x14($sp)
.L7F0A6EDC:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");
#endif

#ifdef VERSION_JP
asm(R"
.late_rodata
glabel D_800584C8
.word 0x40c90fdb /*6.2831855*/

glabel jpt_800584CC
.word .Ljp7F0A6E04
.word .Ljp7F0A6ED0
.word .Ljp7F0A6E14
.word .Ljp7F0A6E60
.word .Ljp7F0A6EC0

glabel jpt_800584E0
.word .Ljp7F0A6E88
.word .Ljp7F0A6E98
.word .Ljp7F0A6EA8
.word .Ljp7F0A6EA8
.word .Ljp7F0A6EA8
.word .Ljp7F0A6EA8
.word .Ljp7F0A6EA8
.word .Ljp7F0A6EA8
.word .Ljp7F0A6EA8
.word .Ljp7F0A6EA8

.text
glabel sub_GAME_7F0A6A80
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 4096
  beqz  $v0, .Ljp7F0A7644
   nop   
  jal   set_open_close_solo_watch_menu_to1
   nop   
.Ljp7F0A7644:
  lui   $t6, %hi(controlstick_lr_enabled) # $t6, 0x8004
  lw    $t6, %lo(controlstick_lr_enabled)($t6)
  bnez  $t6, .Ljp7F0A76EC
   nop   
  jal   get_cur_controller_horz_stick_pos
   move  $a0, $zero
  slti  $at, $v0, -0xa
  bnez  $at, .Ljp7F0A7688
   nop   
  jal   get_cur_controller_horz_stick_pos
   move  $a0, $zero
  slti  $at, $v0, 0xb
  beqz  $at, .Ljp7F0A7688
   li    $t7, 1
  lui   $at, %hi(controlstick_lr_enabled) # $at, 0x8004
  b     .Ljp7F0A76EC
   sw    $t7, %lo(controlstick_lr_enabled)($at)
.Ljp7F0A7688:
  jal   get_cur_controller_horz_stick_pos
   move  $a0, $zero
  slti  $at, $v0, 0xb
  beqz  $at, .Ljp7F0A76BC
   nop   
  jal   controller_7000C174
   move  $a0, $zero
  slti  $at, $v0, 0xb
  bnez  $at, .Ljp7F0A76BC
   li    $t8, 1
  lui   $at, %hi(controlstick_lr_enabled) # $at, 0x8004
  b     .Ljp7F0A76EC
   sw    $t8, %lo(controlstick_lr_enabled)($at)
.Ljp7F0A76BC:
  jal   get_cur_controller_horz_stick_pos
   move  $a0, $zero
  slti  $at, $v0, -0xa
  bnez  $at, .Ljp7F0A76EC
   nop   
  jal   controller_7000C174
   move  $a0, $zero
  slti  $at, $v0, -0xa
  beqz  $at, .Ljp7F0A76EC
   li    $t9, 1
  lui   $at, %hi(controlstick_lr_enabled) # $at, 0x8004
  sw    $t9, %lo(controlstick_lr_enabled)($at)
.Ljp7F0A76EC:
  lui   $t0, %hi(D_80040AE0) # $t0, 0x8004
  lw    $t0, %lo(D_80040AE0)($t0)
  bnez  $t0, .Ljp7F0A7794
   nop   
  jal   get_cur_controller_vert_stick_pos
   move  $a0, $zero
  slti  $at, $v0, -0xa
  bnez  $at, .Ljp7F0A7730
   nop   
  jal   get_cur_controller_vert_stick_pos
   move  $a0, $zero
  slti  $at, $v0, 0xb
  beqz  $at, .Ljp7F0A7730
   li    $t1, 1
  lui   $at, %hi(D_80040AE0) # $at, 0x8004
  b     .Ljp7F0A7794
   sw    $t1, %lo(D_80040AE0)($at)
.Ljp7F0A7730:
  jal   get_cur_controller_vert_stick_pos
   move  $a0, $zero
  slti  $at, $v0, 0xb
  beqz  $at, .Ljp7F0A7764
   nop   
  jal   controller_7000C284
   move  $a0, $zero
  slti  $at, $v0, 0xb
  bnez  $at, .Ljp7F0A7764
   li    $t2, 1
  lui   $at, %hi(D_80040AE0) # $at, 0x8004
  b     .Ljp7F0A7794
   sw    $t2, %lo(D_80040AE0)($at)
.Ljp7F0A7764:
  jal   get_cur_controller_vert_stick_pos
   move  $a0, $zero
  slti  $at, $v0, -0xa
  bnez  $at, .Ljp7F0A7794
   nop   
  jal   controller_7000C284
   move  $a0, $zero
  slti  $at, $v0, -0xa
  beqz  $at, .Ljp7F0A7794
   li    $t3, 1
  lui   $at, %hi(D_80040AE0) # $at, 0x8004
  sw    $t3, %lo(D_80040AE0)($at)
.Ljp7F0A7794:
  lui   $v1, %hi(D_80040AF8) # $v1, 0x8004
  addiu $v1, %lo(D_80040AF8) # addiu $v1, $v1, 0xb28
  lw    $v0, ($v1)
  bgez  $v0, .Ljp7F0A77C0
   addiu $t6, $v0, -1
  lui   $a0, %hi(D_80040AF4) # $a0, 0x8004
  addiu $a0, %lo(D_80040AF4) # addiu $a0, $a0, 0xb24
  lw    $t4, ($a0)
  lui   $at, 0xfff0
  addu  $t5, $t4, $at
  sw    $t5, ($a0)
.Ljp7F0A77C0:
  lui   $a0, %hi(D_80040AF4) # $a0, 0x8004
  addiu $a0, %lo(D_80040AF4) # addiu $a0, $a0, 0xb24
  lw    $t7, ($a0)
  lui   $at, (0x005F00A1 >> 16) # lui $at, 0x5f
  ori   $at, (0x005F00A1 & 0xFFFF) # ori $at, $at, 0xa1
  sltu  $at, $t7, $at
  beqz  $at, .Ljp7F0A77F4
   sw    $t6, ($v1)
  lui   $t8, (0x00FF00A0 >> 16) # lui $t8, 0xff
  ori   $t8, (0x00FF00A0 & 0xFFFF) # ori $t8, $t8, 0xa0
  li    $t9, 15
  sw    $t8, ($a0)
  sw    $t9, ($v1)
.Ljp7F0A77F4:
  lui   $v1, %hi(D_80040B00) # $v1, 0x8004
  addiu $v1, %lo(D_80040B00) # addiu $v1, $v1, 0xb30
  lw    $v0, ($v1)
  lui   $a0, %hi(D_80040AFC) # $a0, 0x8004
  addiu $a0, %lo(D_80040AFC) # addiu $a0, $a0, 0xb2c
  bgez  $v0, .Ljp7F0A781C
   li    $t4, 255
  lw    $t0, ($a0)
  addiu $t1, $t0, -0x10
  sw    $t1, ($a0)
.Ljp7F0A781C:
  lui   $a0, %hi(D_80040AFC) # $a0, 0x8004
  addiu $a0, %lo(D_80040AFC) # addiu $a0, $a0, 0xb2c
  lw    $t3, ($a0)
  addiu $t2, $v0, -1
  sw    $t2, ($v1)
  sltiu $at, $t3, 0x60
  beqz  $at, .Ljp7F0A7844
   li    $t5, 15
  sw    $t4, ($a0)
  sw    $t5, ($v1)
.Ljp7F0A7844:
  lui   $at, %hi(D_80040B1C) # $at, 0x8004
  lwc1  $f4, %lo(D_80040B1C)($at)
  lui   $at, %hi(0x800484D0) # $at, 0x8005  #JPHARDCODE FIXME
  lwc1  $f6, %lo(0x800484D0)($at) #JPHARDCODE FIXME
  lui   $at, %hi(D_800584C8) # $at, 0x8006
  lwc1  $f10, %lo(D_800584C8)($at)
  mul.s $f8, $f4, $f6
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f18
  lui   $v0, %hi(D_80040B14) # $v0, 0x8004
  addiu $v0, %lo(D_80040B14) # addiu $v0, $v0, 0xb44
  lwc1  $f6, ($v0)
  mul.s $f16, $f8, $f10
  div.s $f4, $f16, $f18
  add.s $f8, $f6, $f4
  swc1  $f8, ($v0)
  jal   sub_GAME_7F0A6A2C
   lwc1  $f12, ($v0)
  lui   $v0, %hi(D_80040B14) # $v0, 0x8004
  addiu $v0, %lo(D_80040B14) # addiu $v0, $v0, 0xb44
  swc1  $f0, ($v0)
  lui   $t6, %hi(D_80040B0C) # $t6, 0x8004
  lw    $t6, %lo(D_80040B0C)($t6)
  sll   $t7, $t6, 0x10
  jal   get_random_value
   sw    $t7, 0x1c($sp)
  lw    $t8, 0x1c($sp)
  sltu  $at, $t8, $v0
  beqz  $at, .Ljp7F0A78C4
   nop   
  jal   sub_GAME_7F0A51D8
   nop   
.Ljp7F0A78C4:
  lui   $a0, %hi(D_80040B04) # $a0, 0x8004
  addiu $a0, %lo(D_80040B04) # addiu $a0, $a0, 0xb34
  lw    $v1, ($a0)
  slti  $at, $v1, 0xe0
  beql  $at, $zero, .Ljp7F0A7900
   slti  $at, $v1, 0xe1
  jal   get_random_value
   nop   
  lui   $a0, %hi(D_80040B04) # $a0, 0x8004
  addiu $a0, %lo(D_80040B04) # addiu $a0, $a0, 0xb34
  lw    $t9, ($a0)
  srl   $t0, $v0, 0x1e
  addu  $v1, $t9, $t0
  sw    $v1, ($a0)
  slti  $at, $v1, 0xe1
.Ljp7F0A7900:
  bnez  $at, .Ljp7F0A7910
   li    $t9, 342
  li    $v1, 224
  sw    $v1, ($a0)
.Ljp7F0A7910:
  negu  $t3, $v1
  sll   $t4, $t3, 2
  lui   $a0, %hi(D_80040B40) # $a0, 0x8004
  addiu $t5, $t4, 0x380
  lui   $at, %hi(D_80040B08) # $at, 0x8004
  addiu $a0, %lo(D_80040B40) # addiu $a0, $a0, 0xb70
  sw    $t5, %lo(D_80040B08)($at)
  lw    $t6, ($a0)
  addiu $v0, $t6, -4
  slti  $at, $v0, 0x157
  bnez  $at, .Ljp7F0A7948
   sw    $v0, ($a0)
  li    $v0, -342
  sw    $v0, ($a0)
.Ljp7F0A7948:
  slti  $at, $v0, -0x156
  beqz  $at, .Ljp7F0A7958
   lui   $v0, %hi(D_80040B44) # $v0, 0x8004
  sw    $t9, ($a0)
.Ljp7F0A7958:
  addiu $v0, %lo(D_80040B44) # addiu $v0, $v0, 0xb74
  lh    $t0, ($v0)
  lui   $t4, %hi(D_80040994) # $t4, 0x8004
  addiu $t1, $t0, 1
  sh    $t1, ($v0)
  lh    $t2, ($v0)
  andi  $t3, $t2, 1
  sh    $t3, ($v0)
  lw    $t4, %lo(D_80040994)($t4)
  sltiu $at, $t4, 5
  beqz  $at, .Ljp7F0A7A70
   sll   $t4, $t4, 2
  lui   $at, %hi(jpt_800584CC)
  addu  $at, $at, $t4
  lw    $t4, %lo(jpt_800584CC)($at)
  jr    $t4
   nop   
.Ljp7F0A6E04:
  jal   sub_GAME_7F0A526C
   nop   
  b     .Ljp7F0A7A74
   lw    $ra, 0x14($sp)
.Ljp7F0A6E14:
  lui   $v0, %hi(D_80040998) # $v0, 0x8004
  lw    $v0, %lo(D_80040998)($v0)
  li    $at, 1
  beqz  $v0, .Ljp7F0A79D0
   nop   
  beq   $v0, $at, .Ljp7F0A79E0
   nop   
  b     .Ljp7F0A79E8
   nop   
.Ljp7F0A79D0:
  jal   sub_GAME_7F0A5860
   nop   
  b     .Ljp7F0A79E8
   nop   
.Ljp7F0A79E0:
  jal   sub_GAME_7F0A5900
   nop   
.Ljp7F0A79E8:
  jal   sub_GAME_7F0A55C4
   nop   
  b     .Ljp7F0A7A74
   lw    $ra, 0x14($sp)
.Ljp7F0A6E60:
  lui   $t5, %hi(D_8004099C) # $t5, 0x8004
  lw    $t5, %lo(D_8004099C)($t5)
  sltiu $at, $t5, 0xa
  beqz  $at, .Ljp7F0A7A48
   sll   $t5, $t5, 2
  lui   $at, %hi(jpt_800584E0)
  addu  $at, $at, $t5
  lw    $t5, %lo(jpt_800584E0)($at)
  jr    $t5
   nop   
.Ljp7F0A6E88:
  jal   sub_GAME_7F0A5A64
   nop   
  b     .Ljp7F0A7A48
   nop   
.Ljp7F0A6E98:
  jal   sub_GAME_7F0A5AF4
   nop   
  b     .Ljp7F0A7A48
   nop   
.Ljp7F0A6EA8:
  jal   sub_GAME_7F0A5998
   nop   
.Ljp7F0A7A48:
  jal   sub_GAME_7F0A56A4
   nop   
  b     .Ljp7F0A7A74
   lw    $ra, 0x14($sp)
.Ljp7F0A6EC0:
  jal   sub_GAME_7F0A5784
   nop   
  b     .Ljp7F0A7A74
   lw    $ra, 0x14($sp)
.Ljp7F0A6ED0:
  jal   sub_GAME_7F0A53D8
   nop   
.Ljp7F0A7A70:
  lw    $ra, 0x14($sp)
.Ljp7F0A7A74:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");
#endif

asm(R"
glabel sub_GAME_7F0A6EE8
  addiu $sp, $sp, -0x58
  sw    $ra, 0x14($sp)
  move  $v0, $a0
  addiu $v1, $a0, 8
  lui   $t6, 0xb700
  li    $t7, 8192
  sw    $t7, 4($v0)
  sw    $t6, ($v0)
  lui   $t8, (0xBA001402 >> 16) # lui $t8, 0xba00
  ori   $t8, (0xBA001402 & 0xFFFF) # ori $t8, $t8, 0x1402
  addiu $a1, $v1, 8
  sw    $t8, ($v1)
  sw    $zero, 4($v1)
  lui   $t9, (0xBA001701 >> 16) # lui $t9, 0xba00
  ori   $t9, (0xBA001701 & 0xFFFF) # ori $t9, $t9, 0x1701
  addiu $a2, $a1, 8
  lui   $t1, 0x80
  sw    $t1, 4($a1)
  sw    $t9, ($a1)
  lui   $t2, 0xed00
  sw    $t2, ($a2)
  addiu $a0, $a2, 8
  sw    $a0, 0x58($sp)
  jal   get_video2_settings_txtClipW
   sw    $a2, 0x48($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x1a($sp)
  mtc1  $v0, $f4
  lh    $t6, 0x1a($sp)
  li    $at, 0x40800000 # 4.000000
  cvt.s.w $f6, $f4
  mtc1  $t6, $f16
  mtc1  $at, $f0
  lw    $v1, 0x58($sp)
  lw    $t3, 0x48($sp)
  cvt.s.w $f18, $f16
  mul.s $f8, $f6, $f0
  addiu $a1, $v1, 8
  lui   $t6, (0xBA000E02 >> 16) # lui $t6, 0xba00
  ori   $t6, (0xBA000E02 & 0xFFFF) # ori $t6, $t6, 0xe02
  addiu $a2, $a1, 8
  mul.s $f4, $f18, $f0
  lui   $t7, (0xBA001102 >> 16) # lui $t7, 0xba00
  ori   $t7, (0xBA001102 & 0xFFFF) # ori $t7, $t7, 0x1102
  addiu $a3, $a2, 8
  addiu $t0, $a3, 8
  addiu $v0, $t0, 8
  trunc.w.s $f10, $f8
  addiu $a0, $v0, 8
  trunc.w.s $f6, $f4
  mfc1  $t4, $f10
  mfc1  $t8, $f6
  andi  $t5, $t4, 0xfff
  lui   $t4, (0xBA001001 >> 16) # lui $t4, 0xba00
  andi  $t9, $t8, 0xfff
  sll   $t1, $t9, 0xc
  or    $t2, $t5, $t1
  sw    $t2, 4($t3)
  ori   $t4, (0xBA001001 & 0xFFFF) # ori $t4, $t4, 0x1001
  sw    $t4, ($v1)
  sw    $zero, 4($v1)
  sw    $zero, 4($a1)
  sw    $t6, ($a1)
  sw    $zero, 4($a2)
  sw    $t7, ($a2)
  lui   $t8, (0xBA001301 >> 16) # lui $t8, 0xba00
  ori   $t8, (0xBA001301 & 0xFFFF) # ori $t8, $t8, 0x1301
  lui   $t9, 8
  sw    $t9, 4($a3)
  sw    $t8, ($a3)
  lui   $t5, (0xBA000C02 >> 16) # lui $t5, 0xba00
  ori   $t5, (0xBA000C02 & 0xFFFF) # ori $t5, $t5, 0xc02
  li    $t1, 8192
  sw    $t1, 4($t0)
  sw    $t5, ($t0)
  lui   $t2, (0xBA000903 >> 16) # lui $t2, 0xba00
  ori   $t2, (0xBA000903 & 0xFFFF) # ori $t2, $t2, 0x903
  li    $t3, 3072
  sw    $t3, 4($v0)
  sw    $t2, ($v0)
  lui   $t6, (0xFFFE793C >> 16) # lui $t6, 0xfffe
  lui   $t4, (0xFCFFFFFF >> 16) # lui $t4, 0xfcff
  ori   $t4, (0xFCFFFFFF & 0xFFFF) # ori $t4, $t4, 0xffff
  ori   $t6, (0xFFFE793C & 0xFFFF) # ori $t6, $t6, 0x793c
  addiu $a1, $a0, 8
  sw    $t6, 4($a0)
  sw    $t4, ($a0)
  lui   $t7, (0xBA000801 >> 16) # lui $t7, 0xba00
  ori   $t7, (0xBA000801 & 0xFFFF) # ori $t7, $t7, 0x801
  addiu $a2, $a1, 8
  sw    $t7, ($a1)
  sw    $zero, 4($a1)
  lui   $t8, (0xB9000002 >> 16) # lui $t8, 0xb900
  ori   $t8, (0xB9000002 & 0xFFFF) # ori $t8, $t8, 2
  addiu $a3, $a2, 8
  sw    $t8, ($a2)
  sw    $zero, 4($a2)
  lui   $t5, (0x0F0A4000 >> 16) # lui $t5, 0xf0a
  lui   $t9, (0xB900031D >> 16) # lui $t9, 0xb900
  ori   $t9, (0xB900031D & 0xFFFF) # ori $t9, $t9, 0x31d
  ori   $t5, (0x0F0A4000 & 0xFFFF) # ori $t5, $t5, 0x4000
  sw    $t5, 4($a3)
  sw    $t9, ($a3)
  addiu $v1, $a3, 8
  lui   $t1, (0xBA000602 >> 16) # lui $t1, 0xba00
  ori   $t1, (0xBA000602 & 0xFFFF) # ori $t1, $t1, 0x602
  sw    $t1, ($v1)
  sw    $zero, 4($v1)
  lw    $ra, 0x14($sp)
  addiu $v0, $v1, 8
  addiu $sp, $sp, 0x58
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0A70AC
  move  $v0, $zero
  move  $v1, $a1
  li    $a3, 112
  li    $a2, 32
.L7F0A70BC:
  addiu $v0, $v0, 1
  slti  $at, $v0, 0x14
  addiu $v1, $v1, 0x10
  sb    $a2, -4($v1)
  sb    $a3, -3($v1)
  bnez  $at, .L7F0A70BC
   sb    $a2, -2($v1)
  sll   $v1, $a0, 2
  addiu $a2, $v1, 3
  slt   $at, $a2, $v1
  bnez  $at, .L7F0A7144
   sll   $t6, $v1, 4
  sll   $t7, $a2, 4
  addu  $a0, $t7, $a1
  lui   $a2, %hi(watch_soundrelated_maybe)
  addu  $v1, $a1, $t6
  li    $a1, 240
  addiu $a2, %lo(watch_soundrelated_maybe) # addiu $a2, $a2, 0x9a8
  li    $t0, 160
  li    $a3, 48
  li    $v0, 80
  sb    $v0, 0xc($v1)
.L7F0A7114:
  sb    $a1, 0xd($v1)
  sb    $v0, 0xe($v1)
  lw    $t8, ($a2)
  beql  $t8, $zero, .L7F0A7138
   addiu $v1, $v1, 0x10
  sb    $a3, 0xc($v1)
  sb    $t0, 0xd($v1)
  sb    $a3, 0xe($v1)
  addiu $v1, $v1, 0x10
.L7F0A7138:
  sltu  $at, $a0, $v1
  beql  $at, $zero, .L7F0A7114
   sb    $v0, 0xc($v1)
.L7F0A7144:
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80058508
.word 0x3d4ccccd /*0.050000001*/
.text
glabel sub_GAME_7F0A714C
  addiu $sp, $sp, -0x50
  sw    $s0, 0x18($sp)
  move  $s0, $a0
  sw    $ra, 0x1c($sp)
  sw    $a1, 0x54($sp)
  sw    $a2, 0x58($sp)
  jal   sub_GAME_7F0BD6C4
   li    $a0, 30
  sw    $v0, 0x48($sp)
  jal   sub_GAME_7F0BD6C4
   li    $a0, 30
  sw    $v0, 0x44($sp)
  jal   sub_GAME_7F0BD714
   li    $a0, 248
  sw    $v0, 0x40($sp)
  jal   sub_GAME_7F0BD714
   li    $a0, 248
  sw    $v0, 0x3c($sp)
  move  $v1, $s0
  addiu $s0, $s0, 8
  lui   $t6, 0xe700
  sw    $t6, ($v1)
  move  $a0, $s0
  sw    $zero, 4($v1)
  addiu $s0, $s0, 8
  lui   $t7, (0xBA001402 >> 16) # lui $t7, 0xba00
  ori   $t7, (0xBA001402 & 0xFFFF) # ori $t7, $t7, 0x1402
  move  $a1, $s0
  sw    $t7, ($a0)
  sw    $zero, 4($a0)
  addiu $s0, $s0, 8
  lui   $t8, (0xB900031D >> 16) # lui $t8, 0xb900
  lui   $t9, (0x005041C8 >> 16) # lui $t9, 0x50
  ori   $t9, (0x005041C8 & 0xFFFF) # ori $t9, $t9, 0x41c8
  ori   $t8, (0xB900031D & 0xFFFF) # ori $t8, $t8, 0x31d
  move  $a2, $s0
  sw    $t8, ($a1)
  sw    $t9, 4($a1)
  addiu $s0, $s0, 8
  lui   $t2, (0xFCFFFFFF >> 16) # lui $t2, 0xfcff
  lui   $t3, (0xFFFE793C >> 16) # lui $t3, 0xfffe
  ori   $t3, (0xFFFE793C & 0xFFFF) # ori $t3, $t3, 0x793c
  ori   $t2, (0xFCFFFFFF & 0xFFFF) # ori $t2, $t2, 0xffff
  move  $a3, $s0
  sw    $t2, ($a2)
  sw    $t3, 4($a2)
  lui   $t5, (0xE6E6E600 >> 16) # lui $t5, 0xe6e6
  ori   $t5, (0xE6E6E600 & 0xFFFF) # ori $t5, $t5, 0xe600
  addiu $s0, $s0, 8
  lui   $t4, 0xfa00
  lui   $t6, (0x01020040 >> 16) # lui $t6, 0x102
  sw    $t4, ($a3)
  sw    $t5, 4($a3)
  ori   $t6, (0x01020040 & 0xFFFF) # ori $t6, $t6, 0x40
  move  $v0, $s0
  sw    $t6, ($v0)
  lw    $t7, 0x54($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f2
  sw    $t7, 4($v0)
  addiu $s0, $s0, 8
  jal   check_watch_page_transistion_running
   swc1  $f2, 0x20($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f12
  beqz  $v0, .L7F0A72B0
   lwc1  $f2, 0x20($sp)
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lwc1  $f4, 0x11cc($v0)
  lwc1  $f6, 0x11c8($v0)
  lwc1  $f10, 0x11bc($v0)
  lwc1  $f18, 0x11c0($v0)
  sub.s $f8, $f4, $f6
  mtc1  $zero, $f4
  mul.s $f16, $f10, $f8
  div.s $f2, $f16, $f18
  c.lt.s $f2, $f4
  nop   
  bc1fl .L7F0A7298
   c.lt.s $f12, $f2
  neg.s $f2, $f2
  c.lt.s $f12, $f2
.L7F0A7298:
  nop   
  bc1f  .L7F0A72A8
   nop   
  mov.s $f2, $f12
.L7F0A72A8:
  mul.s $f2, $f2, $f2
  nop   
.L7F0A72B0:
  lw    $t8, 0x58($sp)
  li    $at, 1
  lui   $t0, %hi(D_80040B04) 
  bne   $t8, $at, .L7F0A7300
   addiu $t0, %lo(D_80040B04) # addiu $t0, $t0, 0xb04
  lui   $at, %hi(D_80058508)
  lwc1  $f2, %lo(D_80058508)($at)
  li    $t9, 224
  sw    $t9, ($t0)
  lui   $t2, %hi(pPlayer) 
  lw    $t2, %lo(pPlayer)($t2)
  li    $at, 4
  lw    $v0, 0x1c8($t2)
  beq   $v0, $at, .L7F0A72F4
   li    $at, 6
  bnel  $v0, $at, .L7F0A7304
   lui   $at, 0x3e80
.L7F0A72F4:
  jal   sub_GAME_7F07E740
   nop   
  mov.s $f2, $f0
.L7F0A7300:
  li    $at, 0x3E800000 # 0.250000
.L7F0A7304:
  mtc1  $at, $f0
  lui   $a0, %hi(dword_CODE_bss_8007B0A0)
  addiu $a0, %lo(dword_CODE_bss_8007B0A0) # addiu $a0, $a0, -0x4f60
  mfc1  $a1, $f0
  mfc1  $a2, $f0
  mfc1  $a3, $f0
  jal   guScale
   swc1  $f2, 0x20($sp)
  lwc1  $f2, 0x20($sp)
  move  $v0, $s0
  lui   $t3, (0x01000040 >> 16) # lui $t3, 0x100
  lui   $t4, %hi(dword_CODE_bss_8007B0A0) 
  addiu $t4, %lo(dword_CODE_bss_8007B0A0) # addiu $t4, $t4, -0x4f60
  ori   $t3, (0x01000040 & 0xFFFF) # ori $t3, $t3, 0x40
  sw    $t3, ($v0)
  sw    $t4, 4($v0)
  lw    $t5, 0x58($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f12
  bnez  $t5, .L7F0A73C0
   addiu $s0, $s0, 8
  move  $v0, $s0
  addiu $s0, $s0, 8
  lui   $t6, 0xb600
  li    $t7, 12288
  sw    $t7, 4($v0)
  sw    $t6, ($v0)
  move  $v1, $s0
  lui   $t8, 0x600
  sw    $t8, ($v1)
  lui   $t9, %hi(pPlayer) 
  lw    $t9, %lo(pPlayer)($t9)
  lui   $at, (0x800019F8 >> 16) 
  ori   $at, (0x800019F8 & 0xFFFF) # ori $at, $at, 0x19f8
  addiu $s0, $s0, 8
  addu  $t2, $t9, $at
  sw    $t2, 4($v1)
  move  $a0, $s0
  lui   $t3, 0x600
  sw    $t3, ($a0)
  lui   $t4, %hi(pPlayer) 
  lw    $t4, %lo(pPlayer)($t4)
  lui   $at, (0x80002128 >> 16) 
  ori   $at, (0x80002128 & 0xFFFF) # ori $at, $at, 0x2128
  addu  $t5, $t4, $at
  sw    $t5, 4($a0)
  addiu $s0, $s0, 8
.L7F0A73C0:
  lui   $a0, %hi(dword_CODE_bss_8007B0E0)
  mfc1  $a1, $f12
  mfc1  $a2, $f12
  mfc1  $a3, $f2
  jal   guScale
   addiu $a0, %lo(dword_CODE_bss_8007B0E0) # addiu $a0, $a0, -0x4f20
  move  $v0, $s0
  lui   $t6, (0x01000040 >> 16) # lui $t6, 0x100
  lui   $t7, %hi(dword_CODE_bss_8007B0E0) 
  addiu $t7, %lo(dword_CODE_bss_8007B0E0) # addiu $t7, $t7, -0x4f20
  ori   $t6, (0x01000040 & 0xFFFF) # ori $t6, $t6, 0x40
  sw    $t6, ($v0)
  sw    $t7, 4($v0)
  lw    $t8, 0x58($sp)
  li    $at, 1
  addiu $s0, $s0, 8
  bne   $t8, $at, .L7F0A7470
   li    $a1, 30
  move  $v0, $s0
  addiu $s0, $s0, 8
  lui   $t9, 0xb600
  li    $t2, 12288
  sw    $t2, 4($v0)
  sw    $t9, ($v0)
  move  $v1, $s0
  lui   $t3, 0x600
  sw    $t3, ($v1)
  lui   $t4, %hi(pPlayer) 
  lw    $t4, %lo(pPlayer)($t4)
  lui   $at, (0x800019F8 >> 16) 
  ori   $at, (0x800019F8 & 0xFFFF) # ori $at, $at, 0x19f8
  addiu $s0, $s0, 8
  addu  $t5, $t4, $at
  sw    $t5, 4($v1)
  move  $a0, $s0
  lui   $t6, 0x600
  sw    $t6, ($a0)
  lui   $t7, %hi(pPlayer) 
  lw    $t7, %lo(pPlayer)($t7)
  lui   $at, (0x80002128 >> 16) 
  ori   $at, (0x80002128 & 0xFFFF) # ori $at, $at, 0x2128
  addu  $t8, $t7, $at
  sw    $t8, 4($a0)
  addiu $s0, $s0, 8
.L7F0A7470:
  lui   $a2, %hi(0x3F6B0004) # $a2, 0x3f6b
  ori   $a2, (0x3F6B851F & 0xFFFF) # ori $a2, $a2, 0x851f
  lw    $a0, 0x44($sp)
  jal   sub_GAME_7F0A33F8
   move  $a3, $zero
  lw    $a1, 0x44($sp)
  lui   $at, 0x8000
  lw    $a0, 0x3c($sp)
  li    $a2, 30
  move  $a3, $zero
  jal   sub_GAME_7F0A3978
   addu  $a1, $a1, $at
  move  $v1, $s0
  addiu $s0, $s0, 8
  lui   $t1, 0xe700
  move  $a0, $s0
  sw    $t1, ($v1)
  sw    $zero, 4($v1)
  addiu $s0, $s0, 8
  lui   $t9, (0xB900031D >> 16) # lui $t9, 0xb900
  lui   $t2, (0x00504240 >> 16) # lui $t2, 0x50
  ori   $t2, (0x00504240 & 0xFFFF) # ori $t2, $t2, 0x4240
  ori   $t9, (0xB900031D & 0xFFFF) # ori $t9, $t9, 0x31d
  move  $a1, $s0
  sw    $t9, ($a0)
  sw    $t2, 4($a0)
  addiu $s0, $s0, 8
  lui   $t3, (0xFCFFFFFF >> 16) # lui $t3, 0xfcff
  lui   $t4, (0xFFFDF6FB >> 16) # lui $t4, 0xfffd
  ori   $t4, (0xFFFDF6FB & 0xFFFF) # ori $t4, $t4, 0xf6fb
  ori   $t3, (0xFCFFFFFF & 0xFFFF) # ori $t3, $t3, 0xffff
  move  $a2, $s0
  sw    $t3, ($a1)
  sw    $t4, 4($a1)
  addiu $s0, $s0, 8
  lui   $t5, 0xfa00
  lui   $t6, 0xff
  sw    $t6, %lo(0x3F6B0004)($a2)
  sw    $t5, ($a2)
  move  $a3, $s0
  lui   $t7, 0x600
  sw    $t7, ($a3)
  lw    $t8, 0x3c($sp)
  lui   $at, 0x8000
  addiu $s0, $s0, 8
  addu  $t9, $t8, $at
  sw    $t9, 4($a3)
  move  $v0, $s0
  lui   $t0, %hi(D_80040B04) 
  addiu $t0, %lo(D_80040B04) # addiu $t0, $t0, 0xb04
  sw    $t1, ($v0)
  sw    $zero, 4($v0)
  lw    $t2, ($t0)
  addiu $s0, $s0, 8
  lw    $a0, 0x48($sp)
  slti  $at, $t2, 0xe0
  beqz  $at, .L7F0A75B8
   li    $a1, 30
  lui   $a2, (0x3F666666 >> 16) # lui $a2, 0x3f66
  ori   $a2, (0x3F666666 & 0xFFFF) # ori $a2, $a2, 0x6666
  lw    $a0, 0x48($sp)
  li    $a1, 30
  jal   sub_GAME_7F0A33F8
   move  $a3, $zero
  lw    $a1, 0x48($sp)
  lui   $at, 0x8000
  lw    $a0, 0x40($sp)
  li    $a2, 30
  move  $a3, $zero
  jal   sub_GAME_7F0A3978
   addu  $a1, $a1, $at
  move  $v1, $s0
  lui   $t3, (0xB900031D >> 16) # lui $t3, 0xb900
  lui   $t4, (0x0050004B >> 16) # lui $t4, 0x50
  lui   $t0, %hi(D_80040B04) 
  ori   $t4, (0x0050004B & 0xFFFF) # ori $t4, $t4, 0x4b
  ori   $t3, (0xB900031D & 0xFFFF) # ori $t3, $t3, 0x31d
  addiu $t0, %lo(D_80040B04) # addiu $t0, $t0, 0xb04
  sw    $t3, ($v1)
  sw    $t4, 4($v1)
  b     .L7F0A760C
   addiu $s0, $s0, 8
.L7F0A75B8:
  lui   $a2, %hi(0x3F660004) # $a2, 0x3f66
  ori   $a2, (0x3F666666 & 0xFFFF) # ori $a2, $a2, 0x6666
  jal   sub_GAME_7F0A33F8
   li    $a3, 1
  lw    $a1, 0x48($sp)
  lui   $at, 0x8000
  lw    $a0, 0x40($sp)
  li    $a2, 30
  li    $a3, 1
  jal   sub_GAME_7F0A3978
   addu  $a1, $a1, $at
  move  $v1, $s0
  lui   $t5, (0xB900031D >> 16) # lui $t5, 0xb900
  lui   $t6, (0x005041C8 >> 16) # lui $t6, 0x50
  lui   $t0, %hi(D_80040B04) 
  ori   $t6, (0x005041C8 & 0xFFFF) # ori $t6, $t6, 0x41c8
  ori   $t5, (0xB900031D & 0xFFFF) # ori $t5, $t5, 0x31d
  addiu $t0, %lo(D_80040B04) # addiu $t0, $t0, 0xb04
  sw    $t5, ($v1)
  sw    $t6, 4($v1)
  addiu $s0, $s0, 8
.L7F0A760C:
  move  $v0, $s0
  lui   $a3, (0xFFFE793C >> 16) # lui $a3, 0xfffe
  lui   $t7, (0xFCFFFFFF >> 16) # lui $t7, 0xfcff
  ori   $a3, (0xFFFE793C & 0xFFFF) # ori $a3, $a3, 0x793c
  ori   $t7, (0xFCFFFFFF & 0xFFFF) # ori $t7, $t7, 0xffff
  addiu $s0, $s0, 8
  sw    $t7, ($v0)
  sw    $a3, 4($v0)
  move  $v1, $s0
  lui   $t8, 0x600
  sw    $t8, ($v1)
  lw    $t9, 0x40($sp)
  addiu $s0, $s0, 8
  lui   $at, (0x80002858 >> 16) 
  move  $a0, $s0
  addu  $t2, $t9, $at
  sw    $t2, 4($v1)
  addiu $s0, $s0, 8
  lui   $t3, (0xB900031D >> 16) # lui $t3, 0xb900
  lui   $t4, (0x00504240 >> 16) # lui $t4, 0x50
  ori   $t4, (0x00504240 & 0xFFFF) # ori $t4, $t4, 0x4240
  ori   $t3, (0xB900031D & 0xFFFF) # ori $t3, $t3, 0x31d
  move  $a1, $s0
  sw    $t3, ($a0)
  sw    $t4, 4($a0)
  sw    $t7, ($a1)
  addiu $s0, $s0, 8
  sw    $a3, 4($a1)
  move  $a2, $s0
  lui   $t6, 0x600
  sw    $t6, ($a2)
  lui   $t7, %hi(pPlayer) 
  lw    $t7, %lo(pPlayer)($t7)
  ori   $at, (0x80002858 & 0xFFFF) # ori $at, $at, 0x2858
  addiu $s0, $s0, 8
  addu  $t8, $t7, $at
  sw    $t8, %lo(0x3F660004)($a2)
  lw    $t9, ($t0)
  lw    $a3, 0x48($sp)
  li    $a1, 30
  li    $a0, 2
  sb    $t9, 0xf($a3)
  lw    $a2, 0x44($sp)
  lw    $t2, ($t0)
  addiu $v0, $a3, 0x20
  sb    $t2, 0xf($a2)
  lw    $t3, ($t0)
  sb    $t3, 0x1f($a3)
  lw    $t4, ($t0)
  sb    $t4, 0x1f($a2)
  lw    $v1, 0x44($sp)
  addiu $v1, $v1, 0x20
.L7F0A76DC:
  lw    $t5, ($t0)
  addiu $a0, $a0, 4
  addiu $v0, $v0, 0x40
  sb    $t5, -0x31($v0)
  lw    $t6, ($t0)
  addiu $v1, $v1, 0x40
  sb    $t6, -0x31($v1)
  lw    $t7, ($t0)
  sb    $t7, -0x21($v0)
  lw    $t8, ($t0)
  sb    $t8, -0x21($v1)
  lw    $t9, ($t0)
  sb    $t9, -0x11($v0)
  lw    $t2, ($t0)
  sb    $t2, -0x11($v1)
  lw    $t3, ($t0)
  sb    $t3, -1($v0)
  lw    $t4, ($t0)
  bne   $a0, $a1, .L7F0A76DC
   sb    $t4, -1($v1)
  lw    $t5, ($t0)
  lui   $a0, %hi(pPlayer)
  slti  $at, $t5, 0xe0
  beql  $at, $zero, .L7F0A7798
   lw    $ra, 0x1c($sp)
  lw    $a0, %lo(pPlayer)($a0)
  jal   sub_GAME_7F0A68D8
   addiu $a0, $a0, 0x19b8
  move  $v0, $s0
  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
  lui   $t7, (0x005041C8 >> 16) # lui $t7, 0x50
  ori   $t7, (0x005041C8 & 0xFFFF) # ori $t7, $t7, 0x41c8
  ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
  addiu $s0, $s0, 8
  sw    $t6, ($v0)
  sw    $t7, 4($v0)
  move  $v1, $s0
  lui   $t8, 0x600
  sw    $t8, ($v1)
  lui   $t9, %hi(pPlayer) 
  lw    $t9, %lo(pPlayer)($t9)
  lui   $at, (0x80002998 >> 16) 
  ori   $at, (0x80002998 & 0xFFFF) # ori $at, $at, 0x2998
  addu  $t2, $t9, $at
  sw    $t2, 4($v1)
  addiu $s0, $s0, 8
  lw    $ra, 0x1c($sp)
.L7F0A7798:
  move  $v0, $s0
  lw    $s0, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x50
");

void sub_GAME_7F0A77A8(unsigned int param_1, unsigned int param_2) {
  sub_GAME_7F0A714C(param_1, param_2, 1);
}

asm(R"
glabel sub_GAME_7F0A77C8
  addiu $sp, $sp, -0x80
  lui   $t6, %hi(ptrFirstFontTableSmall) 
  lui   $t7, %hi(ptrSecondFontTableSmall) 
  lw    $t6, %lo(ptrFirstFontTableSmall)($t6)
  lw    $t7, %lo(ptrSecondFontTableSmall)($t7)
  sw    $s0, 0x38($sp)
  move  $s0, $a0
  sw    $ra, 0x3c($sp)
  li    $a0, 44068
  sw    $t6, 0x5c($sp)
  jal   get_textptr_for_textID
   sw    $t7, 0x58($sp)
  sw    $v0, 0x54($sp)
  jal   get_textptr_for_textID
   li    $a0, 44069
  sw    $v0, 0x50($sp)
  jal   get_textptr_for_textID
   li    $a0, 44070
  lui   $v1, %hi(j_text_trigger)
  lw    $v1, %lo(j_text_trigger)($v1)
  li    $t8, 81
  sw    $v0, 0x4c($sp)
  beqz  $v1, .L7F0A7830
   sw    $t8, 0x7c($sp)
  b     .L7F0A7834
   li    $v0, 15
.L7F0A7830:
  move  $v0, $zero
.L7F0A7834:
  addiu $t9, $v0, 0xbd
  beqz  $v1, .L7F0A7848
   sw    $t9, 0x78($sp)
  b     .L7F0A784C
   li    $v0, 10
.L7F0A7848:
  move  $v0, $zero
.L7F0A784C:
  addiu $t0, $v0, 0x88
  beqz  $v1, .L7F0A7860
   sw    $t0, 0x74($sp)
  b     .L7F0A7864
   li    $v0, 3
.L7F0A7860:
  move  $v0, $zero
.L7F0A7864:
  lui   $t1, %hi(watch_soundrelated_maybe) 
  lw    $t1, %lo(watch_soundrelated_maybe)($t1)
  addiu $v1, $v0, 0x4c
  sw    $v1, 0x6c($sp)
  sw    $v1, 0x70($sp)
  beqz  $t1, .L7F0A78F0
   sw    $v1, 0x68($sp)
  lui   $v1, %hi(D_800409A4)
  lw    $v1, %lo(D_800409A4)($v1)
  bnez  $v1, .L7F0A78C0
   nop   
  jal   get_cur_controller_horz_stick_pos
   move  $a0, $zero
  slti  $at, $v0, 0x2e
  beqz  $at, .L7F0A78B0
   move  $a0, $zero
  jal   get_controller_buttons_held
   li    $a1, 273
  beqz  $v0, .L7F0A78F0
.L7F0A78B0:
   li    $t2, 1
  lui   $at, %hi(D_800409A4)
  b     .L7F0A78F0
   sw    $t2, %lo(D_800409A4)($at)
.L7F0A78C0:
  beqz  $v1, .L7F0A78F0
   nop   
  jal   get_cur_controller_horz_stick_pos
   move  $a0, $zero
  slti  $at, $v0, -0x2d
  bnez  $at, .L7F0A78E8
   move  $a0, $zero
  jal   get_controller_buttons_held
   li    $a1, 546
  beqz  $v0, .L7F0A78F0
.L7F0A78E8:
   lui   $at, %hi(D_800409A4)
  sw    $zero, %lo(D_800409A4)($at)
.L7F0A78F0:
  lui   $t3, %hi(watch_soundrelated_maybe) 
  lw    $t3, %lo(watch_soundrelated_maybe)($t3)
  addiu $a0, $sp, 0x60
  addiu $a1, $sp, 0x64
  beqz  $t3, .L7F0A7AFC
   lw    $a2, 0x54($sp)
  lw    $t4, 0x5c($sp)
  addiu $a0, $sp, 0x60
  addiu $a1, $sp, 0x64
  lw    $a2, 0x54($sp)
  lw    $a3, 0x58($sp)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t4, 0x10($sp)
  lw    $t5, 0x58($sp)
  lw    $t6, 0x5c($sp)
  lw    $t8, 0x64($sp)
  lw    $t9, 0x60($sp)
  lui   $t7, (0xA0FFA0F0 >> 16) # lui $t7, 0xa0ff
  ori   $t7, (0xA0FFA0F0 & 0xFFFF) # ori $t7, $t7, 0xa0f0
  sw    $t7, 0x18($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x7c
  addiu $a2, $sp, 0x70
  lw    $a3, 0x54($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t5, 0x10($sp)
  sw    $t6, 0x14($sp)
  sw    $t8, 0x1c($sp)
  jal   en_text_write_stuff
   sw    $t9, 0x20($sp)
  lui   $v1, %hi(D_800409A4)
  lw    $v1, %lo(D_800409A4)($v1)
  move  $s0, $v0
  beqz  $v1, .L7F0A7A3C
   nop   
  jal   get_video2_settings_txtClipW
   nop   
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lw    $t0, 0x58($sp)
  lw    $t1, 0x5c($sp)
  lh    $t4, 0x44($sp)
  lui   $t3, (0x007000A0 >> 16) # lui $t3, 0x70
  ori   $t3, (0x007000A0 & 0xFFFF) # ori $t3, $t3, 0xa0
  li    $t2, -1
  sw    $t2, 0x18($sp)
  sw    $t3, 0x1c($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x78
  addiu $a2, $sp, 0x6c
  lw    $a3, 0x50($sp)
  sw    $v0, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $zero, 0x2c($sp)
  sw    $t0, 0x10($sp)
  sw    $t1, 0x14($sp)
  jal   jp_text_write_stuff
   sw    $t4, 0x20($sp)
  jal   get_video2_settings_txtClipW
   move  $s0, $v0
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lw    $t5, 0x58($sp)
  lw    $t6, 0x5c($sp)
  lh    $t8, 0x44($sp)
  lui   $t7, (0x00FF00B0 >> 16) # lui $t7, 0xff
  ori   $t7, (0x00FF00B0 & 0xFFFF) # ori $t7, $t7, 0xb0
  sw    $t7, 0x18($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x74
  addiu $a2, $sp, 0x68
  lw    $a3, 0x4c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t5, 0x10($sp)
  sw    $t6, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t8, 0x1c($sp)
  b     .L7F0A7C04
   move  $s0, $v0
.L7F0A7A3C:
  bnezl $v1, .L7F0A7C08
   lw    $ra, 0x3c($sp)
  jal   get_video2_settings_txtClipW
   nop   
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lw    $t9, 0x58($sp)
  lw    $t0, 0x5c($sp)
  lh    $t2, 0x44($sp)
  lui   $t1, (0x00FF00B0 >> 16) # lui $t1, 0xff
  ori   $t1, (0x00FF00B0 & 0xFFFF) # ori $t1, $t1, 0xb0
  sw    $t1, 0x18($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x78
  addiu $a2, $sp, 0x6c
  lw    $a3, 0x50($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t9, 0x10($sp)
  sw    $t0, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t2, 0x1c($sp)
  jal   get_video2_settings_txtClipW
   move  $s0, $v0
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lw    $t3, 0x58($sp)
  lw    $t4, 0x5c($sp)
  lh    $t7, 0x44($sp)
  lui   $t6, (0x007000A0 >> 16) # lui $t6, 0x70
  ori   $t6, (0x007000A0 & 0xFFFF) # ori $t6, $t6, 0xa0
  li    $t5, -1
  sw    $t5, 0x18($sp)
  sw    $t6, 0x1c($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x74
  addiu $a2, $sp, 0x68
  lw    $a3, 0x4c($sp)
  sw    $v0, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $zero, 0x2c($sp)
  sw    $t3, 0x10($sp)
  sw    $t4, 0x14($sp)
  jal   jp_text_write_stuff
   sw    $t7, 0x20($sp)
  b     .L7F0A7C04
   move  $s0, $v0
.L7F0A7AFC:
  lw    $t8, 0x5c($sp)
  lw    $a3, 0x58($sp)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t8, 0x10($sp)
  lw    $t9, 0x58($sp)
  lw    $t0, 0x5c($sp)
  lw    $t2, 0x64($sp)
  lw    $t3, 0x60($sp)
  lui   $t1, (0x00800080 >> 16) # lui $t1, 0x80
  ori   $t1, (0x00800080 & 0xFFFF) # ori $t1, $t1, 0x80
  sw    $t1, 0x18($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x7c
  addiu $a2, $sp, 0x70
  lw    $a3, 0x54($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t9, 0x10($sp)
  sw    $t0, 0x14($sp)
  sw    $t2, 0x1c($sp)
  jal   en_text_write_stuff
   sw    $t3, 0x20($sp)
  jal   get_video2_settings_txtClipW
   move  $s0, $v0
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lw    $t4, 0x58($sp)
  lw    $t5, 0x5c($sp)
  lh    $t7, 0x44($sp)
  lui   $t6, (0x00800080 >> 16) # lui $t6, 0x80
  ori   $t6, (0x00800080 & 0xFFFF) # ori $t6, $t6, 0x80
  sw    $t6, 0x18($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x78
  addiu $a2, $sp, 0x6c
  lw    $a3, 0x50($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t4, 0x10($sp)
  sw    $t5, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t7, 0x1c($sp)
  jal   get_video2_settings_txtClipW
   move  $s0, $v0
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lw    $t8, 0x58($sp)
  lw    $t9, 0x5c($sp)
  lh    $t1, 0x44($sp)
  lui   $t0, (0x00800080 >> 16) # lui $t0, 0x80
  ori   $t0, (0x00800080 & 0xFFFF) # ori $t0, $t0, 0x80
  sw    $t0, 0x18($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x74
  addiu $a2, $sp, 0x68
  lw    $a3, 0x4c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t8, 0x10($sp)
  sw    $t9, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t1, 0x1c($sp)
  move  $s0, $v0
.L7F0A7C04:
  lw    $ra, 0x3c($sp)
.L7F0A7C08:
  move  $v0, $s0
  lw    $s0, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x80
");

asm(R"
glabel sub_GAME_7F0A7C18
  addiu $sp, $sp, -0x70
  sw    $s2, 0x40($sp)
  move  $s2, $a0
  sw    $ra, 0x44($sp)
  sw    $s1, 0x3c($sp)
  sw    $s0, 0x38($sp)
  jal   get_textptr_for_textID
   li    $a0, 44071
  lui   $s0, %hi(ptrFirstFontTableSmall)
  lui   $s1, %hi(ptrSecondFontTableSmall)
  sw    $v0, 0x6c($sp)
  lw    $s0, %lo(ptrFirstFontTableSmall)($s0)
  jal   check_objectives_complete
   lw    $s1, %lo(ptrSecondFontTableSmall)($s1)
  beqz  $v0, .L7F0A7C74
   lui   $t7, %hi(D_80040AF4) 
  lui   $t6, (0x00FF00B0 >> 16) # lui $t6, 0xff
  ori   $t6, (0x00FF00B0 & 0xFFFF) # ori $t6, $t6, 0xb0
  sw    $t6, 0x4c($sp)
  jal   get_textptr_for_textID
   li    $a0, 44072
  b     .L7F0A7C88
   sw    $v0, 0x68($sp)
.L7F0A7C74:
  lw    $t7, %lo(D_80040AF4)($t7)
  li    $a0, 44073
  jal   get_textptr_for_textID
   sw    $t7, 0x4c($sp)
  sw    $v0, 0x68($sp)
.L7F0A7C88:
  jal   microcode_constructor
   move  $a0, $s2
  move  $s2, $v0
  addiu $a0, $sp, 0x5c
  addiu $a1, $sp, 0x58
  lw    $a2, 0x6c($sp)
  move  $a3, $s1
  sw    $s0, 0x10($sp)
  jal   sub_GAME_7F0AE98C
   sw    $zero, 0x14($sp)
  lw    $t1, 0x58($sp)
  lw    $t2, 0x5c($sp)
  lui   $t0, (0x00FF00B0 >> 16) # lui $t0, 0xff
  li    $t8, 81
  li    $t9, 65
  ori   $t0, (0x00FF00B0 & 0xFFFF) # ori $t0, $t0, 0xb0
  sw    $t8, 0x64($sp)
  sw    $t9, 0x60($sp)
  sw    $t0, 0x18($sp)
  move  $a0, $s2
  addiu $a1, $sp, 0x64
  addiu $a2, $sp, 0x60
  lw    $a3, 0x6c($sp)
  sw    $s1, 0x10($sp)
  sw    $s0, 0x14($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t1, 0x1c($sp)
  jal   en_text_write_stuff
   sw    $t2, 0x20($sp)
  lui   $t3, %hi(j_text_trigger) 
  lw    $t3, %lo(j_text_trigger)($t3)
  move  $s2, $v0
  lw    $t4, 0x64($sp)
  beqz  $t3, .L7F0A7D20
   lw    $t5, 0x58($sp)
  b     .L7F0A7D24
   li    $v0, 34
.L7F0A7D20:
  move  $v0, $zero
.L7F0A7D24:
  lw    $t9, 0x60($sp)
  lw    $t0, 0x5c($sp)
  addu  $t6, $t4, $t5
  addu  $t7, $t6, $v0
  addiu $t8, $t7, 4
  subu  $t1, $t9, $t0
  sw    $t8, 0x64($sp)
  sw    $t1, 0x60($sp)
  addiu $a0, $sp, 0x5c
  addiu $a1, $sp, 0x58
  lw    $a2, 0x68($sp)
  move  $a3, $s1
  sw    $s0, 0x10($sp)
  jal   sub_GAME_7F0AE98C
   sw    $zero, 0x14($sp)
  lw    $t2, 0x4c($sp)
  lw    $t3, 0x58($sp)
  lw    $t4, 0x5c($sp)
  move  $a0, $s2
  addiu $a1, $sp, 0x64
  addiu $a2, $sp, 0x60
  lw    $a3, 0x68($sp)
  sw    $s1, 0x10($sp)
  sw    $s0, 0x14($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t2, 0x18($sp)
  sw    $t3, 0x1c($sp)
  jal   en_text_write_stuff
   sw    $t4, 0x20($sp)
  jal   sub_GAME_7F0A77C8
   move  $a0, $v0
  lw    $ra, 0x44($sp)
  lw    $s0, 0x38($sp)
  lw    $s1, 0x3c($sp)
  lw    $s2, 0x40($sp)
  jr    $ra
   addiu $sp, $sp, 0x70
");

unsigned int sub_GAME_7F0A7DBC(unsigned int uParm1) { return uParm1; }

asm(R"
glabel sub_GAME_7F0A7DC4
  addiu $sp, $sp, -0x58
  sw    $ra, 0x34($sp)
  sw    $a0, 0x58($sp)
  jal   get_textptr_for_textID
   li    $a0, 44075
  lui   $t6, %hi(j_text_trigger) 
  lw    $t6, %lo(j_text_trigger)($t6)
  sw    $v0, 0x54($sp)
  li    $t8, 49
  beqz  $t6, .L7F0A7DF8
   lui   $t9, %hi(ptrFirstFontTableSmall) 
  b     .L7F0A7DFC
   li    $v0, -5
.L7F0A7DF8:
  move  $v0, $zero
.L7F0A7DFC:
  lui   $t0, %hi(ptrSecondFontTableSmall) 
  lw    $t9, %lo(ptrFirstFontTableSmall)($t9)
  lw    $t0, %lo(ptrSecondFontTableSmall)($t0)
  addiu $t7, $v0, 0x65
  sw    $t7, 0x50($sp)
  sw    $t8, 0x4c($sp)
  sw    $zero, 0x48($sp)
  sw    $zero, 0x44($sp)
  lw    $a0, 0x58($sp)
  sw    $t9, 0x40($sp)
  jal   microcode_constructor
   sw    $t0, 0x3c($sp)
  lw    $t1, 0x40($sp)
  sw    $v0, 0x58($sp)
  addiu $a0, $sp, 0x48
  addiu $a1, $sp, 0x44
  lw    $a2, 0x54($sp)
  lw    $a3, 0x3c($sp)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t1, 0x10($sp)
  lw    $t2, 0x3c($sp)
  lw    $t3, 0x40($sp)
  lw    $t5, 0x44($sp)
  lw    $t6, 0x48($sp)
  lui   $t4, (0x00FF00B0 >> 16) # lui $t4, 0xff
  ori   $t4, (0x00FF00B0 & 0xFFFF) # ori $t4, $t4, 0xb0
  sw    $t4, 0x18($sp)
  lw    $a0, 0x58($sp)
  addiu $a1, $sp, 0x50
  addiu $a2, $sp, 0x4c
  lw    $a3, 0x54($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t2, 0x10($sp)
  sw    $t3, 0x14($sp)
  sw    $t5, 0x1c($sp)
  jal   en_text_write_stuff
   sw    $t6, 0x20($sp)
  lw    $ra, 0x34($sp)
  addiu $sp, $sp, 0x58
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_8005850C
.word 0x3f7ae148 /*0.98000002*/
glabel D_80058510
.word 0x3f829cbc /*1.0204082*/
glabel D_80058514
.word 0x461c4000 /*10000.0*/
glabel D_80058518
.word 0x40c90fdb /*6.2831855*/
glabel D_8005851C
.word 0x40c90fdb /*6.2831855*/
glabel D_80058520
.word 0x3f7ae148 /*0.98000002*/
glabel D_80058524
.word 0x3f829cbc /*1.0204082*/
glabel D_80058528
.word 0x461c4000 /*10000.0*/
glabel D_8005852C
.word 0x40c90fdb /*6.2831855*/
glabel D_80058530
.word 0x40c90fdb /*6.2831855*/
.text
glabel debug_gun_watch_move_related
  addiu $sp, $sp, -0x118
  sw    $ra, 0x3c($sp)
  sw    $s0, 0x38($sp)
  jal   sub_GAME_7F0BD6E0
   move  $s0, $a0
  lui   $t6, %hi(ptrFirstFontTableSmall) 
  lui   $t7, %hi(ptrSecondFontTableSmall) 
  lw    $t6, %lo(ptrFirstFontTableSmall)($t6)
  lw    $t7, %lo(ptrSecondFontTableSmall)($t7)
  sw    $v0, 0x114($sp)
  sw    $zero, 0x84($sp)
  sw    $zero, 0x80($sp)
  sw    $t6, 0x7c($sp)
  jal   get_BONDdata_equipcuritem
   sw    $t7, 0x78($sp)
  sw    $v0, 0x74($sp)
  jal   get_weaponnum_by_inv_index
   move  $a0, $v0
  sw    $v0, 0x70($sp)
  jal   sub_GAME_7F08D7D8
   lw    $a0, 0x74($sp)
  swc1  $f0, 0x6c($sp)
  jal   sub_GAME_7F08D800
   lw    $a0, 0x74($sp)
  swc1  $f0, 0x68($sp)
  jal   sub_GAME_7F08D828
   lw    $a0, 0x74($sp)
  swc1  $f0, 0x64($sp)
  jal   sub_GAME_7F08D7B0
   lw    $a0, 0x74($sp)
  swc1  $f0, 0x60($sp)
  jal   sub_GAME_7F08D850
   lw    $a0, 0x74($sp)
  swc1  $f0, 0x5c($sp)
  jal   sub_GAME_7F08D878
   lw    $a0, 0x74($sp)
  swc1  $f0, 0x58($sp)
  jal   sub_GAME_7F08D5C8
   lw    $a0, 0x74($sp)
  sw    $v0, 0x54($sp)
  jal   sub_GAME_7F08D6BC
   lw    $a0, 0x74($sp)
  jal   get_debug_gunwatchpos_flag
   sw    $v0, 0x50($sp)
  beql  $v0, $zero, .L7F0A808C
   lui   $at, 0x4120
  jal   get_item_in_hand
   move  $a0, $zero
  sll   $t8, $v0, 3
  subu  $t8, $t8, $v0
  lui   $t9, %hi(gitem_structs) 
  addiu $t9, %lo(gitem_structs) # addiu $t9, $t9, 0x3924
  sll   $t8, $t8, 3
  addu  $v1, $t8, $t9
  sw    $v1, 0x4c($sp)
  move  $a0, $zero
  jal   get_controller_buttons_held
   li    $a1, 2
  beqz  $v0, .L7F0A7FAC
   lw    $v1, 0x4c($sp)
  li    $at, 0x40000000 # 2.000000
  mtc1  $at, $f6
  lwc1  $f4, 0x18($v1)
  sub.s $f8, $f4, $f6
  swc1  $f8, 0x18($v1)
.L7F0A7FAC:
  move  $a0, $zero
  li    $a1, 1
  jal   get_controller_buttons_held
   sw    $v1, 0x4c($sp)
  beqz  $v0, .L7F0A7FD8
   lw    $v1, 0x4c($sp)
  li    $at, 0x40000000 # 2.000000
  mtc1  $at, $f16
  lwc1  $f10, 0x18($v1)
  add.s $f18, $f10, $f16
  swc1  $f18, 0x18($v1)
.L7F0A7FD8:
  move  $a0, $zero
  li    $a1, 4
  jal   get_controller_buttons_held
   sw    $v1, 0x4c($sp)
  beqz  $v0, .L7F0A8004
   lw    $v1, 0x4c($sp)
  li    $at, 0x40000000 # 2.000000
  mtc1  $at, $f6
  lwc1  $f4, 0x14($v1)
  add.s $f8, $f4, $f6
  swc1  $f8, 0x14($v1)
.L7F0A8004:
  move  $a0, $zero
  li    $a1, 8
  jal   get_controller_buttons_held
   sw    $v1, 0x4c($sp)
  beqz  $v0, .L7F0A8030
   lw    $v1, 0x4c($sp)
  li    $at, 0x40000000 # 2.000000
  mtc1  $at, $f16
  lwc1  $f10, 0x14($v1)
  sub.s $f18, $f10, $f16
  swc1  $f18, 0x14($v1)
.L7F0A8030:
  move  $a0, $zero
  li    $a1, 32
  jal   get_controller_buttons_held
   sw    $v1, 0x4c($sp)
  beqz  $v0, .L7F0A805C
   lw    $v1, 0x4c($sp)
  lui   $at, %hi(D_8005850C)
  lwc1  $f6, %lo(D_8005850C)($at)
  lwc1  $f4, 0x1c($v1)
  mul.s $f8, $f4, $f6
  swc1  $f8, 0x1c($v1)
.L7F0A805C:
  move  $a0, $zero
  li    $a1, 16
  jal   get_controller_buttons_held
   sw    $v1, 0x4c($sp)
  beqz  $v0, .L7F0A8088
   lw    $v1, 0x4c($sp)
  lui   $at, %hi(D_80058510)
  lwc1  $f16, %lo(D_80058510)($at)
  lwc1  $f10, 0x1c($v1)
  mul.s $f18, $f10, $f16
  swc1  $f18, 0x1c($v1)
.L7F0A8088:
  li    $at, 0x41200000 # 10.000000
.L7F0A808C:
  mtc1  $at, $f4
  lui   $at, %hi(D_80058514)
  lwc1  $f6, %lo(D_80058514)($at)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  lui   $a3, (0x3FAAAAAB >> 16) # lui $a3, 0x3faa
  ori   $a3, (0x3FAAAAAB & 0xFFFF) # ori $a3, $a3, 0xaaab
  lw    $a0, 0x114($sp)
  addiu $a1, $sp, 0x112
  lw    $a2, 0x60($sp)
  swc1  $f4, 0x10($sp)
  swc1  $f6, 0x14($sp)
  jal   guPerspective
   swc1  $f8, 0x18($sp)
  lui   $t0, (0x01030040 >> 16) # lui $t0, 0x103
  ori   $t0, (0x01030040 & 0xFFFF) # ori $t0, $t0, 0x40
  move  $v1, $s0
  sw    $t0, ($v1)
  sw    $v1, 0x48($sp)
  lw    $a0, 0x114($sp)
  jal   osVirtualToPhysical
   addiu $s0, $s0, 8
  lw    $v1, 0x48($sp)
  lui   $at, %hi(D_80058518)
  addiu $a1, $sp, 0xd0
  sw    $v0, 4($v1)
  lwc1  $f16, %lo(D_80058518)($at)
  lwc1  $f10, 0x58($sp)
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f4
  mul.s $f18, $f10, $f16
  jal   sub_GAME_7F0585FC
   div.s $f12, $f18, $f4
  lui   $at, %hi(D_8005851C)
  lwc1  $f0, %lo(D_8005851C)($at)
  lwc1  $f6, 0x5c($sp)
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f10
  mul.s $f8, $f6, $f0
  addiu $a1, $sp, 0x90
  div.s $f16, $f8, $f10
  jal   sub_GAME_7F058688
   sub.s $f12, $f0, $f16
  addiu $a0, $sp, 0x90
  jal   matrix_4x4_multiply_in_place
   addiu $a1, $sp, 0xd0
  mtc1  $zero, $f0
  lwc1  $f2, 0x68($sp)
  lwc1  $f12, 0x6c($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f18
  mfc1  $a3, $f2
  mfc1  $a2, $f12
  addiu $a0, $sp, 0x90
  lw    $a1, 0x64($sp)
  swc1  $f2, 0x18($sp)
  swc1  $f0, 0x10($sp)
  swc1  $f0, 0x1c($sp)
  swc1  $f0, 0x24($sp)
  swc1  $f12, 0x14($sp)
  jal   sub_GAME_7F059694
   swc1  $f18, 0x20($sp)
  addiu $a0, $sp, 0x90
  jal   matrix_4x4_multiply_in_place
   addiu $a1, $sp, 0xd0
  jal   sub_GAME_7F0A6EE8
   move  $a0, $s0
  lui   $v1, %hi(D_80040B04)
  lw    $v1, %lo(D_80040B04)($v1)
  move  $s0, $v0
  move  $a0, $s0
  slti  $at, $v1, 0xe0
  beqz  $at, .L7F0A81DC
   lw    $a1, 0x70($sp)
  lui   $t1, (0x64DC6428 >> 16) # lui $t1, 0x64dc
  ori   $t1, (0x64DC6428 & 0xFFFF) # ori $t1, $t1, 0x6428
  sw    $t1, 0x10($sp)
  move  $a0, $v0
  lw    $a1, 0x70($sp)
  addiu $a2, $sp, 0xd0
  jal   set_enviro_fog_for_items_in_solo_watch_menu
   addiu $a3, $v1, 1
  b     .L7F0A81F8
   move  $s0, $v0
.L7F0A81DC:
  lui   $t2, (0x64DC6428 >> 16) # lui $t2, 0x64dc
  ori   $t2, (0x64DC6428 & 0xFFFF) # ori $t2, $t2, 0x6428
  sw    $t2, 0x10($sp)
  addiu $a2, $sp, 0xd0
  jal   set_enviro_fog_for_items_in_solo_watch_menu
   li    $a3, 255
  move  $s0, $v0
.L7F0A81F8:
  jal   sub_GAME_7F06A334
   move  $a0, $s0
  jal   microcode_constructor
   move  $a0, $v0
  lw    $t5, 0x7c($sp)
  li    $t3, 96
  li    $t4, 160
  move  $s0, $v0
  sw    $t3, 0x8c($sp)
  sw    $t4, 0x88($sp)
  addiu $a0, $sp, 0x84
  addiu $a1, $sp, 0x80
  lw    $a2, 0x54($sp)
  lw    $a3, 0x78($sp)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t5, 0x10($sp)
  lw    $t6, 0x78($sp)
  lw    $t7, 0x7c($sp)
  lw    $t9, 0x80($sp)
  lw    $t0, 0x84($sp)
  lui   $t8, (0x00FF00B0 >> 16) # lui $t8, 0xff
  ori   $t8, (0x00FF00B0 & 0xFFFF) # ori $t8, $t8, 0xb0
  sw    $t8, 0x18($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x8c
  addiu $a2, $sp, 0x88
  lw    $a3, 0x54($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t6, 0x10($sp)
  sw    $t7, 0x14($sp)
  sw    $t9, 0x1c($sp)
  jal   en_text_write_stuff
   sw    $t0, 0x20($sp)
  lw    $t2, 0x7c($sp)
  li    $t1, 170
  move  $s0, $v0
  sw    $t1, 0x88($sp)
  addiu $a0, $sp, 0x84
  addiu $a1, $sp, 0x80
  lw    $a2, 0x50($sp)
  lw    $a3, 0x78($sp)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t2, 0x10($sp)
  lw    $t3, 0x78($sp)
  lw    $t4, 0x7c($sp)
  lw    $t6, 0x80($sp)
  lw    $t7, 0x84($sp)
  lui   $t5, (0x00FF00B0 >> 16) # lui $t5, 0xff
  ori   $t5, (0x00FF00B0 & 0xFFFF) # ori $t5, $t5, 0xb0
  sw    $t5, 0x18($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x8c
  addiu $a2, $sp, 0x88
  lw    $a3, 0x50($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t3, 0x10($sp)
  sw    $t4, 0x14($sp)
  sw    $t6, 0x1c($sp)
  jal   en_text_write_stuff
   sw    $t7, 0x20($sp)
  lw    $ra, 0x3c($sp)
  lw    $s0, 0x38($sp)
  addiu $sp, $sp, 0x118
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0A830C
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  jal   sub_GAME_7F0A714C
   move  $a2, $zero
  jal   check_watch_page_transistion_running
   move  $s0, $v0
  li    $at, 1
  beq   $v0, $at, .L7F0A835C
   nop   
  jal   sub_GAME_7F0A7DC4
   move  $a0, $s0
  jal   sub_GAME_7F0A7C18
   move  $a0, $v0
  jal   sub_GAME_7F0A7DBC
   move  $a0, $v0
  jal   debug_gun_watch_move_related
   move  $a0, $v0
  b     .L7F0A8364
   move  $s0, $v0
.L7F0A835C:
  jal   check_watch_page_transistion_running
   nop   
.L7F0A8364:
  lw    $ra, 0x1c($sp)
  move  $v0, $s0
  lw    $s0, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x20
");

asm(R"
glabel sub_GAME_7F0A8378
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 40960
  bnez  $v0, .L7F0A83C4
   move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 4096
  beql  $v0, $zero, .L7F0A8418
   lw    $ra, 0x14($sp)
  jal   get_item_in_hand
   move  $a0, $zero
  lui   $a0, %hi(D_800409B8)
  lw    $a0, %lo(D_800409B8)($a0)
  jal   get_weaponnum_by_inv_index
   sw    $v0, 0x1c($sp)
  lw    $t6, 0x1c($sp)
  beq   $v0, $t6, .L7F0A8414
.L7F0A83C4:
   lui   $a0, %hi(D_800409B8)
  jal   get_weaponnum_by_inv_index
   lw    $a0, %lo(D_800409B8)($a0)
  move  $a0, $zero
  jal   remove_hands_item
   move  $a1, $v0
  li    $a0, 1
  jal   remove_hands_item
   move  $a1, $zero
  lui   $a0, %hi(D_800409B8)
  jal   set_BONDdata_equipcuritem
   lw    $a0, %lo(D_800409B8)($a0)
  li    $t7, 10
  lui   $at, %hi(D_800409C4)
  lui   $a0, %hi(ptr_sfx_buf)
  sw    $t7, %lo(D_800409C4)($at)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 159
  jal   play_sfx_a1
   move  $a2, $zero
.L7F0A8414:
  lw    $ra, 0x14($sp)
.L7F0A8418:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

#ifdef VERSION_US
asm(R"
glabel debug_gun_watch_move_related2
  addiu $sp, $sp, -0x928
  sw    $ra, 0x3c($sp)
  sw    $s0, 0x38($sp)
  jal   sub_GAME_7F0A714C
   move  $a2, $zero
  jal   check_watch_page_transistion_running
   sw    $v0, 0x928($sp)
  li    $at, 1
  beql  $v0, $at, .L7F0A8B00
   lw    $ra, 0x3c($sp)
  jal   sub_GAME_7F0BD6E0
   nop   
  lui   $a0, %hi(D_800409B8)
  sw    $v0, 0x924($sp)
  jal   sub_GAME_7F08D528
   lw    $a0, %lo(D_800409B8)($a0)
  lui   $a0, %hi(D_800409B8)
  swc1  $f0, 0x894($sp)
  jal   sub_GAME_7F08D550
   lw    $a0, %lo(D_800409B8)($a0)
  lui   $a0, %hi(D_800409B8)
  swc1  $f0, 0x890($sp)
  jal   sub_GAME_7F08D578
   lw    $a0, %lo(D_800409B8)($a0)
  lui   $a0, %hi(D_800409B8)
  swc1  $f0, 0x88c($sp)
  jal   sub_GAME_7F08D5A0
   lw    $a0, %lo(D_800409B8)($a0)
  lui   $a0, %hi(D_800409B8)
  swc1  $f0, 0x888($sp)
  jal   get_weaponnum_by_inv_index
   lw    $a0, %lo(D_800409B8)($a0)
  lui   $a0, %hi(D_800409B8)
  sw    $v0, 0x884($sp)
  jal   sub_GAME_7F08D850
   lw    $a0, %lo(D_800409B8)($a0)
  lui   $a0, %hi(D_800409B8)
  swc1  $f0, 0x880($sp)
  jal   sub_GAME_7F08D878
   lw    $a0, %lo(D_800409B8)($a0)
  jal   get_debug_gunwatchpos_flag
   swc1  $f0, 0x87c($sp)
  beql  $v0, $zero, .L7F0A85D0
   lui   $at, 0x4120
  jal   get_item_in_hand
   move  $a0, $zero
  sll   $t6, $v0, 3
  subu  $t6, $t6, $v0
  lui   $t7, %hi(gitem_structs) 
  addiu $t7, %lo(gitem_structs) # addiu $t7, $t7, 0x3924
  sll   $t6, $t6, 3
  addu  $s0, $t6, $t7
  move  $a0, $zero
  jal   get_controller_buttons_held
   li    $a1, 2
  beqz  $v0, .L7F0A851C
   move  $a0, $zero
  li    $at, 0x40000000 # 2.000000
  mtc1  $at, $f6
  lwc1  $f4, 0x2c($s0)
  sub.s $f8, $f4, $f6
  swc1  $f8, 0x2c($s0)
.L7F0A851C:
  jal   get_controller_buttons_held
   li    $a1, 1
  beqz  $v0, .L7F0A8540
   move  $a0, $zero
  li    $at, 0x40000000 # 2.000000
  mtc1  $at, $f16
  lwc1  $f10, 0x2c($s0)
  add.s $f18, $f10, $f16
  swc1  $f18, 0x2c($s0)
.L7F0A8540:
  jal   get_controller_buttons_held
   li    $a1, 4
  beqz  $v0, .L7F0A8564
   move  $a0, $zero
  li    $at, 0x40000000 # 2.000000
  mtc1  $at, $f6
  lwc1  $f4, 0x30($s0)
  add.s $f8, $f4, $f6
  swc1  $f8, 0x30($s0)
.L7F0A8564:
  jal   get_controller_buttons_held
   li    $a1, 8
  beqz  $v0, .L7F0A8588
   move  $a0, $zero
  li    $at, 0x40000000 # 2.000000
  mtc1  $at, $f16
  lwc1  $f10, 0x30($s0)
  sub.s $f18, $f10, $f16
  swc1  $f18, 0x30($s0)
.L7F0A8588:
  jal   get_controller_buttons_held
   li    $a1, 32
  beqz  $v0, .L7F0A85AC
   move  $a0, $zero
  lui   $at, %hi(D_80058520)
  lwc1  $f6, %lo(D_80058520)($at)
  lwc1  $f4, 0x34($s0)
  mul.s $f8, $f4, $f6
  swc1  $f8, 0x34($s0)
.L7F0A85AC:
  jal   get_controller_buttons_held
   li    $a1, 16
  beqz  $v0, .L7F0A85CC
   lui   $at, %hi(D_80058524)
  lwc1  $f10, 0x34($s0)
  lwc1  $f16, %lo(D_80058524)($at)
  mul.s $f18, $f10, $f16
  swc1  $f18, 0x34($s0)
.L7F0A85CC:
  li    $at, 0x41200000 # 10.000000
.L7F0A85D0:
  mtc1  $at, $f4
  lui   $at, %hi(D_80058528)
  lwc1  $f6, %lo(D_80058528)($at)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  lui   $a3, (0x3FAAAAAB >> 16) # lui $a3, 0x3faa
  ori   $a3, (0x3FAAAAAB & 0xFFFF) # ori $a3, $a3, 0xaaab
  lw    $a0, 0x924($sp)
  addiu $a1, $sp, 0x922
  lw    $a2, 0x894($sp)
  swc1  $f4, 0x10($sp)
  swc1  $f6, 0x14($sp)
  jal   guPerspective
   swc1  $f8, 0x18($sp)
  lw    $v0, 0x928($sp)
  lui   $t8, (0x01030040 >> 16) # lui $t8, 0x103
  ori   $t8, (0x01030040 & 0xFFFF) # ori $t8, $t8, 0x40
  move  $s0, $v0
  sw    $t8, ($s0)
  addiu $v0, $v0, 8
  sw    $v0, 0x928($sp)
  jal   osVirtualToPhysical
   lw    $a0, 0x924($sp)
  sw    $v0, 4($s0)
  lui   $at, %hi(D_8005852C)
  lwc1  $f16, %lo(D_8005852C)($at)
  lwc1  $f10, 0x87c($sp)
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f4
  mul.s $f18, $f10, $f16
  addiu $a1, $sp, 0x8e0
  jal   sub_GAME_7F0585FC
   div.s $f12, $f18, $f4
  lui   $at, %hi(D_80058530)
  lwc1  $f0, %lo(D_80058530)($at)
  lwc1  $f6, 0x880($sp)
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f10
  mul.s $f8, $f6, $f0
  addiu $s0, $sp, 0x8a0
  move  $a1, $s0
  div.s $f16, $f8, $f10
  jal   sub_GAME_7F058688
   sub.s $f12, $f0, $f16
  move  $a0, $s0
  jal   matrix_4x4_multiply_in_place
   addiu $a1, $sp, 0x8e0
  lui   $at, %hi(D_80040B14)
  jal   cosf
   lwc1  $f12, %lo(D_80040B14)($at)
  lwc1  $f18, 0x888($sp)
  lui   $at, %hi(D_80040B14)
  lwc1  $f12, %lo(D_80040B14)($at)
  mul.s $f4, $f0, $f18
  jal   sinf
   swc1  $f4, 0x89c($sp)
  lwc1  $f6, 0x888($sp)
  lwc1  $f14, 0x890($sp)
  mtc1  $zero, $f2
  mul.s $f8, $f0, $f6
  lwc1  $f12, 0x88c($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f16
  mfc1  $a2, $f12
  move  $a0, $s0
  lw    $a1, 0x89c($sp)
  add.s $f10, $f8, $f14
  swc1  $f14, 0x18($sp)
  swc1  $f2, 0x10($sp)
  swc1  $f2, 0x1c($sp)
  mfc1  $a3, $f10
  swc1  $f2, 0x24($sp)
  swc1  $f12, 0x14($sp)
  jal   sub_GAME_7F059694
   swc1  $f16, 0x20($sp)
  move  $a0, $s0
  jal   matrix_4x4_multiply_in_place
   addiu $a1, $sp, 0x8e0
  jal   sub_GAME_7F0A6EE8
   lw    $a0, 0x928($sp)
  lui   $t9, (0xA0FFA03C >> 16) # lui $t9, 0xa0ff
  ori   $t9, (0xA0FFA03C & 0xFFFF) # ori $t9, $t9, 0xa03c
  sw    $t9, 0x10($sp)
  move  $a0, $v0
  lw    $a1, 0x884($sp)
  addiu $a2, $sp, 0x8e0
  jal   set_enviro_fog_for_items_in_solo_watch_menu
   li    $a3, 64
  lui   $t1, %hi(ptrFirstFontTableSmall) 
  lui   $t2, %hi(ptrSecondFontTableSmall) 
  lw    $t1, %lo(ptrFirstFontTableSmall)($t1)
  lw    $t2, %lo(ptrSecondFontTableSmall)($t2)
  sw    $v0, 0x928($sp)
  sw    $zero, 0x860($sp)
  sw    $zero, 0x85c($sp)
  sb    $zero, 0x84($sp)
  move  $s0, $zero
  sw    $t1, 0x858($sp)
  jal   count_total_items_in_inventory
   sw    $t2, 0x854($sp)
  blez  $v0, .L7F0A8790
   nop   
.L7F0A8768:
  jal   sub_GAME_7F08D340
   move  $a0, $s0
  addiu $a0, $sp, 0x84
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  jal   count_total_items_in_inventory
   addiu $s0, $s0, 1
  slt   $at, $s0, $v0
  bnez  $at, .L7F0A8768
   nop   
.L7F0A8790:
  lui   $v1, %hi(D_800409C4)
  addiu $v1, %lo(D_800409C4) # addiu $v1, $v1, 0x9c4
  lw    $v0, ($v1)
  blez  $v0, .L7F0A87A8
   addiu $t3, $v0, -1
  sw    $t3, ($v1)
.L7F0A87A8:
  jal   sub_GAME_7F0A5B80
   nop   
  lui   $t6, %hi(j_text_trigger) 
  lw    $t6, %lo(j_text_trigger)($t6)
  li    $t4, 78
  li    $t5, 140
  sw    $t4, 0x870($sp)
  beqz  $t6, .L7F0A87D4
   sw    $t5, 0x86c($sp)
  b     .L7F0A87D8
   li    $v0, 14
.L7F0A87D4:
  li    $v0, 12
.L7F0A87D8:
  sll   $s0, $v0, 1
  addiu $s0, $s0, 0x8d
  jal   microcode_constructor
   lw    $a0, 0x928($sp)
  lui   $t7, %hi(j_text_trigger) 
  lw    $t7, %lo(j_text_trigger)($t7)
  sw    $v0, 0x928($sp)
  addiu $a0, $sp, 0x860
  beqz  $t7, .L7F0A8808
   addiu $a1, $sp, 0x85c
  b     .L7F0A880C
   li    $v0, 14
.L7F0A8808:
  li    $v0, 12
.L7F0A880C:
  lw    $t8, 0x858($sp)
  addiu $a2, $sp, 0x84
  lw    $a3, 0x854($sp)
  sw    $v0, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t8, 0x10($sp)
  lui   $t9, %hi(j_text_trigger) 
  lw    $t9, %lo(j_text_trigger)($t9)
  lw    $a0, 0x928($sp)
  li    $a1, 78
  beqz  $t9, .L7F0A8844
   li    $a2, 140
  b     .L7F0A8848
   li    $v0, 14
.L7F0A8844:
  li    $v0, 12
.L7F0A8848:
  sll   $t1, $v0, 2
  lw    $a3, 0x85c($sp)
  addu  $t1, $t1, $v0
  addiu $t2, $t1, 0x8c
  sw    $t2, 0x10($sp)
  sw    $zero, 0x14($sp)
  jal   microcode_constructor_related_to_menus
   addiu $a3, $a3, 0x4e
  lui   $v1, %hi(j_text_trigger)
  lw    $v1, %lo(j_text_trigger)($v1)
  move  $a0, $v0
  addiu $a1, $sp, 0x870
  beqz  $v1, .L7F0A8888
   addiu $a2, $sp, 0x86c
  b     .L7F0A888C
   li    $t0, 14
.L7F0A8888:
  li    $t0, 12
.L7F0A888C:
  beqz  $v1, .L7F0A889C
   addiu $a3, $sp, 0x84
  b     .L7F0A88A0
   li    $v0, 14
.L7F0A889C:
  li    $v0, 12
.L7F0A88A0:
  lw    $t6, 0x85c($sp)
  lui   $t9, %hi(D_800409B0) 
  lw    $t9, %lo(D_800409B0)($t9)
  lw    $t3, 0x854($sp)
  lw    $t4, 0x858($sp)
  lui   $t5, (0x00AA00B0 >> 16) # lui $t5, 0xaa
  sll   $t8, $t0, 2
  addu  $t8, $t8, $t0
  ori   $t5, (0x00AA00B0 & 0xFFFF) # ori $t5, $t5, 0xb0
  addiu $t7, $t6, 1
  sw    $t7, 0x1c($sp)
  sw    $t5, 0x18($sp)
  sw    $t8, 0x20($sp)
  sw    $v0, 0x28($sp)
  sw    $t9, 0x24($sp)
  sw    $t3, 0x10($sp)
  jal   en_text_write_stuff
   sw    $t4, 0x14($sp)
  lui   $t1, %hi(j_text_trigger) 
  lw    $t1, %lo(j_text_trigger)($t1)
  move  $a0, $v0
  li    $a1, 75
  beqz  $t1, .L7F0A8908
   move  $a2, $s0
  b     .L7F0A890C
   li    $v0, 14
.L7F0A8908:
  li    $v0, 12
.L7F0A890C:
  lw    $a3, 0x85c($sp)
  addu  $t2, $v0, $s0
  lui   $t4, (0x00800050 >> 16) # lui $t4, 0x80
  ori   $t4, (0x00800050 & 0xFFFF) # ori $t4, $t4, 0x50
  addiu $t3, $t2, -2
  sw    $t3, 0x10($sp)
  sw    $t4, 0x14($sp)
  jal   microcode_constructor_related_to_menus
   addiu $a3, $a3, 0x52
  lui   $t5, %hi(ptrSecondFontTableSmall) 
  lw    $t5, %lo(ptrSecondFontTableSmall)($t5)
  lui   $s0, %hi(ptrFirstFontTableSmall)
  lui   $a0, %hi(D_800409B8)
  sw    $v0, 0x928($sp)
  lw    $s0, %lo(ptrFirstFontTableSmall)($s0)
  lw    $a0, %lo(D_800409B8)($a0)
  jal   sub_GAME_7F08D340
   sw    $t5, 0x58($sp)
  lui   $at, %hi(D_800409BC)
  lwc1  $f18, %lo(D_800409BC)($at)
  lui   $t6, %hi(D_800409B8) 
  lw    $t6, %lo(D_800409B8)($t6)
  cvt.d.s $f4, $f18
  lui   $a1, %hi(aDDDF)
  lui   $a2, %hi(D_800409B0)
  lui   $a3, %hi(D_800409B4)
  sw    $v0, 0x4c($sp)
  lw    $a3, %lo(D_800409B4)($a3)
  lw    $a2, %lo(D_800409B0)($a2)
  addiu $a1, %lo(aDDDF) # addiu $a1, $a1, 0x7768
  sdc1  $f4, 0x18($sp)
  addiu $a0, $sp, 0x60
  jal   sprintf
   sw    $t6, 0x10($sp)
  jal   microcode_constructor
   lw    $a0, 0x928($sp)
  sw    $v0, 0x928($sp)
  addiu $a0, $sp, 0x50
  addiu $a1, $sp, 0x54
  addiu $a2, $sp, 0x60
  lw    $a3, 0x58($sp)
  sw    $s0, 0x10($sp)
  jal   sub_GAME_7F0AE98C
   sw    $zero, 0x14($sp)
  lui   $t7, %hi(D_800409C0) 
  lw    $t7, %lo(D_800409C0)($t7)
  lui   $t8, %hi(j_text_trigger) 
  addiu $a0, $sp, 0x50
  beqz  $t7, .L7F0A8AFC
   addiu $a1, $sp, 0x54
  lw    $t8, %lo(j_text_trigger)($t8)
  lw    $a2, 0x4c($sp)
  lw    $a3, 0x58($sp)
  beqz  $t8, .L7F0A89F0
   li    $v0, 12
  b     .L7F0A89F0
   li    $v0, 14
.L7F0A89F0:
  sw    $s0, 0x10($sp)
  jal   sub_GAME_7F0AE98C
   sw    $v0, 0x14($sp)
  lui   $v1, %hi(j_text_trigger)
  lw    $v1, %lo(j_text_trigger)($v1)
  li    $t9, 78
  sw    $t9, 0x870($sp)
  beqz  $v1, .L7F0A8A1C
   lui   $t3, %hi(D_800409C4) 
  b     .L7F0A8A20
   li    $v0, 14
.L7F0A8A1C:
  li    $v0, 12
.L7F0A8A20:
  lw    $t3, %lo(D_800409C4)($t3)
  sll   $t1, $v0, 1
  addiu $t2, $t1, 0x8c
  bnez  $t3, .L7F0A8A90
   sw    $t2, 0x86c($sp)
  beqz  $v1, .L7F0A8A44
   lw    $a0, 0x928($sp)
  b     .L7F0A8A48
   li    $v0, 14
.L7F0A8A44:
  li    $v0, 12
.L7F0A8A48:
  lw    $t4, 0x58($sp)
  lw    $t6, 0x54($sp)
  lui   $t5, (0xA0FFA0F0 >> 16) # lui $t5, 0xa0ff
  ori   $t5, (0xA0FFA0F0 & 0xFFFF) # ori $t5, $t5, 0xa0f0
  li    $t7, 100
  sw    $t7, 0x20($sp)
  sw    $t5, 0x18($sp)
  addiu $a1, $sp, 0x870
  addiu $a2, $sp, 0x86c
  lw    $a3, 0x4c($sp)
  sw    $s0, 0x14($sp)
  sw    $zero, 0x24($sp)
  sw    $v0, 0x28($sp)
  sw    $t4, 0x10($sp)
  jal   en_text_write_stuff
   sw    $t6, 0x1c($sp)
  b     .L7F0A8AF4
   sw    $v0, 0x928($sp)
.L7F0A8A90:
  beqz  $v1, .L7F0A8AA0
   lw    $a0, 0x928($sp)
  b     .L7F0A8AA4
   li    $v0, 14
.L7F0A8AA0:
  li    $v0, 12
.L7F0A8AA4:
  lw    $t2, 0x54($sp)
  lw    $t8, 0x58($sp)
  lui   $t1, (0x007000A0 >> 16) # lui $t1, 0x70
  ori   $t1, (0x007000A0 & 0xFFFF) # ori $t1, $t1, 0xa0
  li    $t9, -1
  li    $t4, 100
  addiu $t3, $t2, 1
  sw    $t3, 0x20($sp)
  sw    $t4, 0x24($sp)
  sw    $t9, 0x18($sp)
  sw    $t1, 0x1c($sp)
  addiu $a1, $sp, 0x870
  addiu $a2, $sp, 0x86c
  lw    $a3, 0x4c($sp)
  sw    $s0, 0x14($sp)
  sw    $zero, 0x28($sp)
  sw    $v0, 0x2c($sp)
  jal   jp_text_write_stuff
   sw    $t8, 0x10($sp)
  sw    $v0, 0x928($sp)
.L7F0A8AF4:
  jal   sub_GAME_7F0A8378
   nop   
.L7F0A8AFC:
  lw    $ra, 0x3c($sp)
.L7F0A8B00:
  lw    $v0, 0x928($sp)
  lw    $s0, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x928
");
#endif

#ifdef VERSION_JP
asm(R"
glabel debug_gun_watch_move_related2
  addiu $sp, $sp, -0x930
  sw    $ra, 0x3c($sp)
  sw    $s0, 0x38($sp)
  jal   sub_GAME_7F0A714C
   move  $a2, $zero
  jal   check_watch_page_transistion_running
   sw    $v0, 0x930($sp)
  li    $at, 1
  beql  $v0, $at, .Ljp7F0A96C0
   lw    $ra, 0x3c($sp)
  jal   sub_GAME_7F0BD6E0
   nop   
  lui   $a0, %hi(D_800409B8) # $a0, 0x8004
  sw    $v0, 0x92c($sp)
  jal   sub_GAME_7F08D528
   lw    $a0, %lo(D_800409B8)($a0)
  lui   $a0, %hi(D_800409B8) # $a0, 0x8004
  swc1  $f0, 0x89c($sp)
  jal   sub_GAME_7F08D550
   lw    $a0, %lo(D_800409B8)($a0)
  lui   $a0, %hi(D_800409B8) # $a0, 0x8004
  swc1  $f0, 0x898($sp)
  jal   sub_GAME_7F08D578
   lw    $a0, %lo(D_800409B8)($a0)
  lui   $a0, %hi(D_800409B8) # $a0, 0x8004
  swc1  $f0, 0x894($sp)
  jal   sub_GAME_7F08D5A0
   lw    $a0, %lo(D_800409B8)($a0)
  lui   $a0, %hi(D_800409B8) # $a0, 0x8004
  swc1  $f0, 0x890($sp)
  jal   get_weaponnum_by_inv_index
   lw    $a0, %lo(D_800409B8)($a0)
  lui   $a0, %hi(D_800409B8) # $a0, 0x8004
  sw    $v0, 0x88c($sp)
  jal   sub_GAME_7F08D850
   lw    $a0, %lo(D_800409B8)($a0)
  lui   $a0, %hi(D_800409B8) # $a0, 0x8004
  swc1  $f0, 0x888($sp)
  jal   sub_GAME_7F08D878
   lw    $a0, %lo(D_800409B8)($a0)
  jal   get_debug_gunwatchpos_flag
   swc1  $f0, 0x884($sp)
  beql  $v0, $zero, .Ljp7F0A9168
   lui   $at, 0x4120
  jal   get_item_in_hand
   move  $a0, $zero
  sll   $t6, $v0, 3
  subu  $t6, $t6, $v0
  lui   $t7, %hi(gitem_structs) # $t7, 0x8003
  addiu $t7, %lo(gitem_structs) # addiu $t7, $t7, 0x3964
  sll   $t6, $t6, 3
  addu  $s0, $t6, $t7
  move  $a0, $zero
  jal   get_controller_buttons_held
   li    $a1, 2
  beqz  $v0, .Ljp7F0A90B4
   move  $a0, $zero
  li    $at, 0x40000000 # 2.000000
  mtc1  $at, $f6
  lwc1  $f4, 0x2c($s0)
  sub.s $f8, $f4, $f6
  swc1  $f8, 0x2c($s0)
.Ljp7F0A90B4:
  jal   get_controller_buttons_held
   li    $a1, 1
  beqz  $v0, .Ljp7F0A90D8
   move  $a0, $zero
  li    $at, 0x40000000 # 2.000000
  mtc1  $at, $f16
  lwc1  $f10, 0x2c($s0)
  add.s $f18, $f10, $f16
  swc1  $f18, 0x2c($s0)
.Ljp7F0A90D8:
  jal   get_controller_buttons_held
   li    $a1, 4
  beqz  $v0, .Ljp7F0A90FC
   move  $a0, $zero
  li    $at, 0x40000000 # 2.000000
  mtc1  $at, $f6
  lwc1  $f4, 0x30($s0)
  add.s $f8, $f4, $f6
  swc1  $f8, 0x30($s0)
.Ljp7F0A90FC:
  jal   get_controller_buttons_held
   li    $a1, 8
  beqz  $v0, .Ljp7F0A9120
   move  $a0, $zero
  li    $at, 0x40000000 # 2.000000
  mtc1  $at, $f16
  lwc1  $f10, 0x30($s0)
  sub.s $f18, $f10, $f16
  swc1  $f18, 0x30($s0)
.Ljp7F0A9120:
  jal   get_controller_buttons_held
   li    $a1, 32
  beqz  $v0, .Ljp7F0A9144
   move  $a0, $zero
  lui   $at, %hi(D_80058520) # $at, 0x8006
  lwc1  $f6, %lo(D_80058520)($at)
  lwc1  $f4, 0x34($s0)
  mul.s $f8, $f4, $f6
  swc1  $f8, 0x34($s0)
.Ljp7F0A9144:
  jal   get_controller_buttons_held
   li    $a1, 16
  beqz  $v0, .Ljp7F0A9164
   lui   $at, %hi(D_80058524) # $at, 0x8006
  lwc1  $f10, 0x34($s0)
  lwc1  $f16, %lo(D_80058524)($at)
  mul.s $f18, $f10, $f16
  swc1  $f18, 0x34($s0)
.Ljp7F0A9164:
  li    $at, 0x41200000 # 10.000000
.Ljp7F0A9168:
  mtc1  $at, $f4
  lui   $at, %hi(D_80058528) # $at, 0x8006
  lwc1  $f6, %lo(D_80058528)($at)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  lui   $a3, (0x3FAAAAAB >> 16) # lui $a3, 0x3faa
  ori   $a3, (0x3FAAAAAB & 0xFFFF) # ori $a3, $a3, 0xaaab
  lw    $a0, 0x92c($sp)
  addiu $a1, $sp, 0x92a
  lw    $a2, 0x89c($sp)
  swc1  $f4, 0x10($sp)
  swc1  $f6, 0x14($sp)
  jal   guPerspective
   swc1  $f8, 0x18($sp)
  lw    $v0, 0x930($sp)
  lui   $t8, (0x01030040 >> 16) # lui $t8, 0x103
  ori   $t8, (0x01030040 & 0xFFFF) # ori $t8, $t8, 0x40
  move  $s0, $v0
  sw    $t8, ($s0)
  addiu $v0, $v0, 8
  sw    $v0, 0x930($sp)
  jal   osVirtualToPhysical
   lw    $a0, 0x92c($sp)
  sw    $v0, 4($s0)
  lui   $at, %hi(D_8005852C) # $at, 0x8006
  lwc1  $f16, %lo(D_8005852C)($at)
  lwc1  $f10, 0x884($sp)
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f4
  mul.s $f18, $f10, $f16
  addiu $a1, $sp, 0x8e8
  jal   sub_GAME_7F0585FC
   div.s $f12, $f18, $f4
  lui   $at, %hi(D_80058530) # $at, 0x8006
  lwc1  $f0, %lo(D_80058530)($at)
  lwc1  $f6, 0x888($sp)
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f10
  mul.s $f8, $f6, $f0
  addiu $s0, $sp, 0x8a8
  move  $a1, $s0
  div.s $f16, $f8, $f10
  jal   sub_GAME_7F058688
   sub.s $f12, $f0, $f16
  move  $a0, $s0
  jal   matrix_4x4_multiply_in_place
   addiu $a1, $sp, 0x8e8
  lui   $at, %hi(D_80040B14) # $at, 0x8004
  jal   cosf
   lwc1  $f12, %lo(D_80040B14)($at)
  lwc1  $f18, 0x890($sp)
  lui   $at, %hi(D_80040B14) # $at, 0x8004
  lwc1  $f12, %lo(D_80040B14)($at)
  mul.s $f4, $f0, $f18
  jal   sinf
   swc1  $f4, 0x8a4($sp)
  lwc1  $f6, 0x890($sp)
  lwc1  $f14, 0x898($sp)
  mtc1  $zero, $f2
  mul.s $f8, $f0, $f6
  lwc1  $f12, 0x894($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f16
  mfc1  $a2, $f12
  move  $a0, $s0
  lw    $a1, 0x8a4($sp)
  add.s $f10, $f8, $f14
  swc1  $f14, 0x18($sp)
  swc1  $f2, 0x10($sp)
  swc1  $f2, 0x1c($sp)
  mfc1  $a3, $f10
  swc1  $f2, 0x24($sp)
  swc1  $f12, 0x14($sp)
  jal   sub_GAME_7F059694
   swc1  $f16, 0x20($sp)
  move  $a0, $s0
  jal   matrix_4x4_multiply_in_place
   addiu $a1, $sp, 0x8e8
  jal   sub_GAME_7F0A6EE8
   lw    $a0, 0x930($sp)
  lui   $t9, (0xA0FFA03C >> 16) # lui $t9, 0xa0ff
  ori   $t9, (0xA0FFA03C & 0xFFFF) # ori $t9, $t9, 0xa03c
  sw    $t9, 0x10($sp)
  move  $a0, $v0
  lw    $a1, 0x88c($sp)
  addiu $a2, $sp, 0x8e8
  jal   set_enviro_fog_for_items_in_solo_watch_menu
   li    $a3, 64
  lui   $t3, %hi(j_text_trigger) # $t3, 0x8005
  lw    $t3, %lo(j_text_trigger)($t3)
  lui   $t1, %hi(ptrFirstFontTableSmall) # $t1, 0x8004
  lui   $t2, %hi(ptrSecondFontTableSmall) # $t2, 0x8004
  lw    $t1, %lo(ptrFirstFontTableSmall)($t1)
  lw    $t2, %lo(ptrSecondFontTableSmall)($t2)
  sw    $v0, 0x930($sp)
  sw    $zero, 0x868($sp)
  sw    $zero, 0x864($sp)
  sw    $t1, 0x860($sp)
  beqz  $t3, .Ljp7F0A9304
   sw    $t2, 0x85c($sp)
  li    $t4, 130
  b     .Ljp7F0A930C
   sw    $t4, 0x84($sp)
.Ljp7F0A9304:
  li    $t5, 140
  sw    $t5, 0x84($sp)
.Ljp7F0A930C:
  sb    $zero, 0x8c($sp)
  jal   count_total_items_in_inventory
   move  $s0, $zero
  blez  $v0, .Ljp7F0A9348
   nop   
.Ljp7F0A9320:
  jal   sub_GAME_7F08D340
   move  $a0, $s0
  addiu $a0, $sp, 0x8c
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  jal   count_total_items_in_inventory
   addiu $s0, $s0, 1
  slt   $at, $s0, $v0
  bnez  $at, .Ljp7F0A9320
   nop   
.Ljp7F0A9348:
  lui   $v1, %hi(D_800409C4) # $v1, 0x8004
  addiu $v1, %lo(D_800409C4) # addiu $v1, $v1, 0x9f4
  lw    $v0, ($v1)
  blez  $v0, .Ljp7F0A9360
   addiu $t6, $v0, -1
  sw    $t6, ($v1)
.Ljp7F0A9360:
  jal   sub_GAME_7F0A5B80
   nop   
  lui   $t8, %hi(j_text_trigger) # $t8, 0x8005
  lw    $t8, %lo(j_text_trigger)($t8)
  lw    $v1, 0x84($sp)
  li    $t7, 78
  sw    $t7, 0x878($sp)
  beqz  $t8, .Ljp7F0A938C
   sw    $v1, 0x874($sp)
  b     .Ljp7F0A9390
   li    $v0, 14
.Ljp7F0A938C:
  li    $v0, 12
.Ljp7F0A9390:
  sll   $t9, $v0, 1
  addu  $s0, $t9, $v1
  addiu $s0, $s0, 1
  jal   microcode_constructor
   lw    $a0, 0x930($sp)
  lui   $t1, %hi(j_text_trigger) # $t1, 0x8005
  lw    $t1, %lo(j_text_trigger)($t1)
  sw    $v0, 0x930($sp)
  addiu $a0, $sp, 0x868
  beqz  $t1, .Ljp7F0A93C4
   addiu $a1, $sp, 0x864
  b     .Ljp7F0A93C8
   li    $v0, 14
.Ljp7F0A93C4:
  li    $v0, 12
.Ljp7F0A93C8:
  lw    $t2, 0x860($sp)
  addiu $a2, $sp, 0x8c
  lw    $a3, 0x85c($sp)
  sw    $v0, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t2, 0x10($sp)
  lui   $t3, %hi(j_text_trigger) # $t3, 0x8005
  lw    $t3, %lo(j_text_trigger)($t3)
  lw    $a2, 0x84($sp)
  lw    $a0, 0x930($sp)
  beqz  $t3, .Ljp7F0A9400
   li    $a1, 78
  b     .Ljp7F0A9404
   li    $v0, 14
.Ljp7F0A9400:
  li    $v0, 12
.Ljp7F0A9404:
  sll   $t4, $v0, 2
  lw    $a3, 0x864($sp)
  addu  $t4, $t4, $v0
  addu  $t5, $t4, $a2
  sw    $t5, 0x10($sp)
  sw    $zero, 0x14($sp)
  jal   microcode_constructor_related_to_menus
   addiu $a3, $a3, 0x4e
  lui   $v1, %hi(j_text_trigger) # $v1, 0x8005
  lw    $v1, %lo(j_text_trigger)($v1)
  move  $a0, $v0
  addiu $a1, $sp, 0x878
  beqz  $v1, .Ljp7F0A9444
   addiu $a2, $sp, 0x874
  b     .Ljp7F0A9448
   li    $t0, 14
.Ljp7F0A9444:
  li    $t0, 12
.Ljp7F0A9448:
  beqz  $v1, .Ljp7F0A9458
   addiu $a3, $sp, 0x8c
  b     .Ljp7F0A945C
   li    $v0, 14
.Ljp7F0A9458:
  li    $v0, 12
.Ljp7F0A945C:
  lw    $t9, 0x864($sp)
  lui   $t3, %hi(D_800409B0) # $t3, 0x8004
  lw    $t3, %lo(D_800409B0)($t3)
  lw    $t6, 0x85c($sp)
  lw    $t7, 0x860($sp)
  lui   $t8, (0x00AA00B0 >> 16) # lui $t8, 0xaa
  sll   $t2, $t0, 2
  addu  $t2, $t2, $t0
  ori   $t8, (0x00AA00B0 & 0xFFFF) # ori $t8, $t8, 0xb0
  addiu $t1, $t9, 1
  sw    $t1, 0x1c($sp)
  sw    $t8, 0x18($sp)
  sw    $t2, 0x20($sp)
  sw    $v0, 0x28($sp)
  sw    $t3, 0x24($sp)
  sw    $t6, 0x10($sp)
  jal   en_text_write_stuff
   sw    $t7, 0x14($sp)
  lui   $t4, %hi(j_text_trigger) # $t4, 0x8005
  lw    $t4, %lo(j_text_trigger)($t4)
  move  $a0, $v0
  li    $a1, 75
  beqz  $t4, .Ljp7F0A94C4
   move  $a2, $s0
  b     .Ljp7F0A94C8
   li    $v0, 14
.Ljp7F0A94C4:
  li    $v0, 12
.Ljp7F0A94C8:
  lw    $a3, 0x864($sp)
  addu  $t5, $v0, $s0
  lui   $t7, (0x00800050 >> 16) # lui $t7, 0x80
  ori   $t7, (0x00800050 & 0xFFFF) # ori $t7, $t7, 0x50
  addiu $t6, $t5, -2
  sw    $t6, 0x10($sp)
  sw    $t7, 0x14($sp)
  jal   microcode_constructor_related_to_menus
   addiu $a3, $a3, 0x52
  lui   $t8, %hi(ptrSecondFontTableSmall) # $t8, 0x8004
  lw    $t8, %lo(ptrSecondFontTableSmall)($t8)
  lui   $s0, %hi(ptrFirstFontTableSmall) # $s0, 0x8004
  lui   $a0, %hi(D_800409B8) # $a0, 0x8004
  sw    $v0, 0x930($sp)
  lw    $s0, %lo(ptrFirstFontTableSmall)($s0)
  lw    $a0, %lo(D_800409B8)($a0)
  jal   sub_GAME_7F08D340
   sw    $t8, 0x5c($sp)
  lui   $at, %hi(D_800409BC) # $at, 0x8004
  lwc1  $f18, %lo(D_800409BC)($at)
  lui   $t9, %hi(D_800409B8) # $t9, 0x8004
  lw    $t9, %lo(D_800409B8)($t9)
  cvt.d.s $f4, $f18
  lui   $a1, %hi(aDDDF) # $a1, 0x8005
  lui   $a2, %hi(D_800409B0) # $a2, 0x8004
  lui   $a3, %hi(D_800409B4) # $a3, 0x8004
  sw    $v0, 0x50($sp)
  lw    $a3, %lo(D_800409B4)($a3)
  lw    $a2, %lo(D_800409B0)($a2)
  addiu $a1, %lo(aDDDF) # addiu $a1, $a1, 0x77a8
  sdc1  $f4, 0x18($sp)
  addiu $a0, $sp, 0x64
  jal   sprintf
   sw    $t9, 0x10($sp)
  jal   microcode_constructor
   lw    $a0, 0x930($sp)
  sw    $v0, 0x930($sp)
  addiu $a0, $sp, 0x54
  addiu $a1, $sp, 0x58
  addiu $a2, $sp, 0x64
  lw    $a3, 0x5c($sp)
  sw    $s0, 0x10($sp)
  jal   sub_GAME_7F0AE98C
   sw    $zero, 0x14($sp)
  lui   $t1, %hi(D_800409C0) # $t1, 0x8004
  lw    $t1, %lo(D_800409C0)($t1)
  lui   $t2, %hi(j_text_trigger) # $t2, 0x8005
  addiu $a0, $sp, 0x54
  beqz  $t1, .Ljp7F0A96BC
   addiu $a1, $sp, 0x58
  lw    $t2, %lo(j_text_trigger)($t2)
  lw    $a2, 0x50($sp)
  lw    $a3, 0x5c($sp)
  beqz  $t2, .Ljp7F0A95AC
   li    $v0, 12
  b     .Ljp7F0A95AC
   li    $v0, 14
.Ljp7F0A95AC:
  sw    $s0, 0x10($sp)
  jal   sub_GAME_7F0AE98C
   sw    $v0, 0x14($sp)
  lui   $v1, %hi(j_text_trigger) # $v1, 0x8005
  lw    $v1, %lo(j_text_trigger)($v1)
  li    $t3, 78
  sw    $t3, 0x878($sp)
  beqz  $v1, .Ljp7F0A95D8
   lw    $t5, 0x84($sp)
  b     .Ljp7F0A95DC
   li    $v0, 14
.Ljp7F0A95D8:
  li    $v0, 12
.Ljp7F0A95DC:
  lui   $t7, %hi(D_800409C4) # $t7, 0x8004
  lw    $t7, %lo(D_800409C4)($t7)
  sll   $t4, $v0, 1
  addu  $t6, $t4, $t5
  bnez  $t7, .Ljp7F0A9650
   sw    $t6, 0x874($sp)
  beqz  $v1, .Ljp7F0A9604
   lw    $a0, 0x930($sp)
  b     .Ljp7F0A9608
   li    $v0, 14
.Ljp7F0A9604:
  li    $v0, 12
.Ljp7F0A9608:
  lw    $t8, 0x5c($sp)
  lw    $t1, 0x58($sp)
  lui   $t9, (0xA0FFA0F0 >> 16) # lui $t9, 0xa0ff
  ori   $t9, (0xA0FFA0F0 & 0xFFFF) # ori $t9, $t9, 0xa0f0
  li    $t2, 100
  sw    $t2, 0x20($sp)
  sw    $t9, 0x18($sp)
  addiu $a1, $sp, 0x878
  addiu $a2, $sp, 0x874
  lw    $a3, 0x50($sp)
  sw    $s0, 0x14($sp)
  sw    $zero, 0x24($sp)
  sw    $v0, 0x28($sp)
  sw    $t8, 0x10($sp)
  jal   en_text_write_stuff
   sw    $t1, 0x1c($sp)
  b     .Ljp7F0A96B4
   sw    $v0, 0x930($sp)
.Ljp7F0A9650:
  beqz  $v1, .Ljp7F0A9660
   lw    $a0, 0x930($sp)
  b     .Ljp7F0A9664
   li    $v0, 14
.Ljp7F0A9660:
  li    $v0, 12
.Ljp7F0A9664:
  lw    $t6, 0x58($sp)
  lw    $t3, 0x5c($sp)
  lui   $t5, (0x007000A0 >> 16) # lui $t5, 0x70
  ori   $t5, (0x007000A0 & 0xFFFF) # ori $t5, $t5, 0xa0
  li    $t4, -1
  li    $t8, 100
  addiu $t7, $t6, 1
  sw    $t7, 0x20($sp)
  sw    $t8, 0x24($sp)
  sw    $t4, 0x18($sp)
  sw    $t5, 0x1c($sp)
  addiu $a1, $sp, 0x878
  addiu $a2, $sp, 0x874
  lw    $a3, 0x50($sp)
  sw    $s0, 0x14($sp)
  sw    $zero, 0x28($sp)
  sw    $v0, 0x2c($sp)
  jal   jp_text_write_stuff
   sw    $t3, 0x10($sp)
  sw    $v0, 0x930($sp)
.Ljp7F0A96B4:
  jal   sub_GAME_7F0A8378
   nop   
.Ljp7F0A96BC:
  lw    $ra, 0x3c($sp)
.Ljp7F0A96C0:
  lw    $v0, 0x930($sp)
  lw    $s0, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x930
");
#endif

asm(R"
glabel sub_GAME_7F0A8B10
  addiu $sp, $sp, -0x78
  sw    $s0, 0x38($sp)
  lui   $t6, %hi(ptrFirstFontTableSmall) 
  lui   $t7, %hi(ptrSecondFontTableSmall) 
  lw    $t6, %lo(ptrFirstFontTableSmall)($t6)
  lw    $t7, %lo(ptrSecondFontTableSmall)($t7)
  move  $s0, $a0
  sw    $ra, 0x3c($sp)
  lui   $a0, %hi(D_800409B8)
  sw    $a1, 0x7c($sp)
  sw    $zero, 0x58($sp)
  sw    $zero, 0x54($sp)
  lw    $a0, %lo(D_800409B8)($a0)
  sw    $t6, 0x50($sp)
  jal   sub_GAME_7F08D434
   sw    $t7, 0x4c($sp)
  sw    $v0, 0x48($sp)
  move  $a0, $s0
  lw    $a1, 0x7c($sp)
  jal   sub_GAME_7F0A714C
   move  $a2, $zero
  jal   check_watch_page_transistion_running
   move  $s0, $v0
  li    $at, 1
  beq   $v0, $at, .L7F0A8D2C
   lui   $v1, %hi(D_800409C4)
  addiu $v1, %lo(D_800409C4) # addiu $v1, $v1, 0x9c4
  lw    $v0, ($v1)
  blez  $v0, .L7F0A8B8C
   addiu $t8, $v0, -1
  sw    $t8, ($v1)
.L7F0A8B8C:
  jal   sub_GAME_7F0A5B80
   nop   
  jal   microcode_constructor
   move  $a0, $s0
  lw    $t9, 0x50($sp)
  move  $s0, $v0
  addiu $a0, $sp, 0x58
  addiu $a1, $sp, 0x54
  lw    $a2, 0x48($sp)
  lw    $a3, 0x4c($sp)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t9, 0x10($sp)
  lw    $t0, 0x54($sp)
  li    $t1, 170
  lw    $t4, 0x5c($sp)
  subu  $a1, $t1, $t0
  bgez  $a1, .L7F0A8BE0
   sra   $t2, $a1, 1
  addiu $at, $a1, 1
  sra   $t2, $at, 1
.L7F0A8BE0:
  lui   $t5, (0x00800050 >> 16) # lui $t5, 0x80
  addiu $a1, $t2, 0x4b
  li    $t3, 30
  ori   $t5, (0x00800050 & 0xFFFF) # ori $t5, $t5, 0x50
  sw    $t3, 0x6c($sp)
  sw    $t5, 0x14($sp)
  sw    $a1, 0x70($sp)
  move  $a0, $s0
  li    $a2, 30
  lw    $a3, 0x60($sp)
  jal   microcode_constructor_related_to_menus
   sw    $t4, 0x10($sp)
  lui   $t6, %hi(D_800409C0) 
  lw    $t6, %lo(D_800409C0)($t6)
  move  $s0, $v0
  move  $a0, $s0
  beqz  $t6, .L7F0A8CE8
   addiu $a1, $sp, 0x70
  jal   sub_GAME_7F0A8378
   nop   
  lui   $t7, %hi(D_800409C4) 
  lw    $t7, %lo(D_800409C4)($t7)
  move  $a0, $s0
  addiu $a1, $sp, 0x70
  bnez  $t7, .L7F0A8C98
   addiu $a2, $sp, 0x6c
  lw    $t8, 0x4c($sp)
  lw    $t9, 0x50($sp)
  lw    $t0, 0x54($sp)
  lui   $t1, (0xA0FFA0F0 >> 16) # lui $t1, 0xa0ff
  ori   $t1, (0xA0FFA0F0 & 0xFFFF) # ori $t1, $t1, 0xa0f0
  li    $t2, 100
  sw    $t2, 0x20($sp)
  sw    $t1, 0x18($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x70
  addiu $a2, $sp, 0x6c
  lw    $a3, 0x48($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t8, 0x10($sp)
  sw    $t9, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t0, 0x1c($sp)
  b     .L7F0A8D2C
   move  $s0, $v0
.L7F0A8C98:
  lw    $t7, 0x54($sp)
  lw    $t3, 0x4c($sp)
  lw    $t4, 0x50($sp)
  lui   $t6, (0x007000A0 >> 16) # lui $t6, 0x70
  ori   $t6, (0x007000A0 & 0xFFFF) # ori $t6, $t6, 0xa0
  li    $t5, -1
  li    $t9, 100
  addiu $t8, $t7, 1
  sw    $t8, 0x20($sp)
  sw    $t9, 0x24($sp)
  sw    $t5, 0x18($sp)
  sw    $t6, 0x1c($sp)
  lw    $a3, 0x48($sp)
  sw    $zero, 0x28($sp)
  sw    $zero, 0x2c($sp)
  sw    $t3, 0x10($sp)
  jal   jp_text_write_stuff
   sw    $t4, 0x14($sp)
  b     .L7F0A8D2C
   move  $s0, $v0
.L7F0A8CE8:
  lw    $t1, 0x4c($sp)
  lw    $t0, 0x50($sp)
  lw    $t3, 0x54($sp)
  lui   $t2, (0x00AA00B0 >> 16) # lui $t2, 0xaa
  ori   $t2, (0x00AA00B0 & 0xFFFF) # ori $t2, $t2, 0xb0
  li    $t4, 100
  sw    $t4, 0x20($sp)
  sw    $t2, 0x18($sp)
  addiu $a2, $sp, 0x6c
  lw    $a3, 0x48($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t1, 0x10($sp)
  sw    $t0, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t3, 0x1c($sp)
  move  $s0, $v0
.L7F0A8D2C:
  lw    $ra, 0x3c($sp)
  move  $v0, $s0
  lw    $s0, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x78
");

asm(R"
.late_rodata
glabel D_80058534
.word 0x3f99999a /*1.2*/
.text
glabel sub_GAME_7F0A8D40
  mtc1  $a2, $f4
  lui   $at, %hi(D_80058534)
  mtc1  $a1, $f12
  lwc1  $f8, %lo(D_80058534)($at)
  cvt.s.w $f6, $f4
  lh    $t6, 0x20($a0)
  lh    $t7, 0x40($a0)
  move  $a1, $zero
  move  $a3, $a0
  sub.s $f10, $f8, $f12
  li    $t1, 224
  li    $t0, 64
  li    $v1, 32
  mul.s $f16, $f6, $f10
  subu  $v0, $t6, $t7
  trunc.w.s $f18, $f16
  mfc1  $a2, $f18
  nop   
.L7F0A8D88:
  addiu $a1, $a1, 1
  slti  $at, $a1, 4
  addiu $a3, $a3, 0x10
  sb    $v1, -4($a3)
  sb    $t0, -3($a3)
  sb    $v1, -2($a3)
  bnez  $at, .L7F0A8D88
   sb    $t1, -1($a3)
  li    $at, 0x42C00000 # 96.000000
  mtc1  $at, $f14
  li    $at, 0x42400000 # 48.000000
  mtc1  $at, $f2
  li    $a1, 4
  addiu $a3, $a0, 0x40
  li    $t0, 12
.L7F0A8DC4:
  slti  $at, $a1, 0xa
  beqz  $at, .L7F0A8E5C
   addu  $t2, $v0, $a2
  mul.s $f4, $f2, $f12
  slti  $at, $a1, 6
  mul.s $f6, $f14, $f12
  trunc.w.s $f8, $f4
  trunc.w.s $f10, $f6
  mfc1  $v1, $f8
  mfc1  $t3, $f10
  addiu $v1, $v1, 0x40
  sb    $v1, 0xc($a3)
  addiu $t4, $t3, 0x80
  sb    $t4, 0xd($a3)
  bnez  $at, .L7F0A8EB4
   sb    $v1, 0xe($a3)
  mtc1  $a2, $f16
  mtc1  $v0, $f8
  lh    $t5, 0x40($a0)
  cvt.s.w $f0, $f16
  mtc1  $t5, $f18
  cvt.s.w $f6, $f8
  cvt.s.w $f4, $f18
  add.s $f10, $f6, $f0
  mul.s $f16, $f10, $f12
  add.s $f18, $f4, $f16
  sub.s $f8, $f18, $f0
  trunc.w.s $f6, $f8
  mfc1  $t7, $f6
  nop   
  sh    $t7, ($a3)
  lh    $t8, ($a3)
  lh    $v1, 0x40($a0)
  slt   $at, $t8, $v1
  beql  $at, $zero, .L7F0A8EB8
   addiu $a1, $a1, 1
  b     .L7F0A8EB4
   sh    $v1, ($a3)
.L7F0A8E5C:
  mtc1  $t2, $f16
  lh    $t9, 0x40($a0)
  cvt.s.w $f18, $f16
  mtc1  $t9, $f10
  nop   
  cvt.s.w $f4, $f10
  mul.s $f8, $f18, $f12
  mtc1  $a2, $f10
  nop   
  cvt.s.w $f16, $f10
  add.s $f6, $f4, $f8
  add.s $f18, $f6, $f16
  trunc.w.s $f4, $f18
  mfc1  $t4, $f4
  nop   
  sh    $t4, ($a3)
  lh    $t5, ($a3)
  lh    $v1, 0x20($a0)
  slt   $at, $v1, $t5
  beql  $at, $zero, .L7F0A8EB8
   addiu $a1, $a1, 1
  sh    $v1, ($a3)
.L7F0A8EB4:
  addiu $a1, $a1, 1
.L7F0A8EB8:
  bne   $a1, $t0, .L7F0A8DC4
   addiu $a3, $a3, 0x10
  lh    $v0, 0xa0($a0)
  sh    $v0, 0x10($a0)
  jr    $ra
   sh    $v0, ($a0)
");

asm(R"
glabel sub_GAME_7F0A8ED0
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a0, 0x20($sp)
  jal   get_cur_controller_horz_stick_pos
   move  $a0, $zero
  lw    $t6, 0x20($sp)
  move  $a0, $zero
  li    $a1, 273
  lhu   $v1, ($t6)
  sw    $v0, 0x1c($sp)
  jal   get_controller_buttons_held
   sw    $v1, 0x18($sp)
  lw    $v1, 0x18($sp)
  lw    $a2, 0x1c($sp)
  beqz  $v0, .L7F0A8F18
   lw    $a3, 0x20($sp)
  b     .L7F0A8F40
   addiu $v1, $v1, 0x400
.L7F0A8F18:
  move  $a0, $zero
  li    $a1, 546
  sw    $v1, 0x18($sp)
  jal   get_controller_buttons_held
   sw    $a2, 0x1c($sp)
  lw    $v1, 0x18($sp)
  lw    $a2, 0x1c($sp)
  beqz  $v0, .L7F0A8F40
   lw    $a3, 0x20($sp)
  addiu $v1, $v1, -0x400
.L7F0A8F40:
  slti  $at, $a2, 0x47
  bnez  $at, .L7F0A8F54
   li    $t3, 32767
  b     .L7F0A8F64
   li    $a2, 70
.L7F0A8F54:
  slti  $at, $a2, -0x46
  beql  $at, $zero, .L7F0A8F68
   slti  $at, $a2, 8
  li    $a2, -70
.L7F0A8F64:
  slti  $at, $a2, 8
.L7F0A8F68:
  bnez  $at, .L7F0A8F8C
   sll   $t7, $a2, 0xb
  addiu $t8, $t7, -0x3800
  li    $at, 70
  div   $zero, $t8, $at
  mflo  $t9
  addu  $v1, $v1, $t9
  b     .L7F0A8FB4
   li    $at, 32768
.L7F0A8F8C:
  slti  $at, $a2, -7
  beqz  $at, .L7F0A8FB0
   sll   $t0, $a2, 0xb
  addiu $t1, $t0, 0x3800
  li    $at, 70
  div   $zero, $t1, $at
  mflo  $t2
  addu  $v1, $v1, $t2
  nop   
.L7F0A8FB0:
  li    $at, 32768
.L7F0A8FB4:
  slt   $at, $v1, $at
  bnez  $at, .L7F0A8FC8
   nop   
  b     .L7F0A8FDC
   sh    $t3, ($a3)
.L7F0A8FC8:
  bgezl $v1, .L7F0A8FDC
   sh    $v1, ($a3)
  b     .L7F0A8FDC
   sh    $zero, ($a3)
  sh    $v1, ($a3)
.L7F0A8FDC:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80058538
.word 0x46fffe00 /*32767.0*/
.text
glabel sub_GAME_7F0A8FEC
  addiu $sp, $sp, -0x48
  sw    $s0, 0x28($sp)
  move  $s0, $a0
  sw    $ra, 0x2c($sp)
  jal   sub_GAME_7F0BD6C4
   li    $a0, 12
  jal   sfx_c_700091C8
   sw    $v0, 0x3c($sp)
  lui   $t6, %hi(watch_soundrelated_maybe) 
  lw    $t6, %lo(watch_soundrelated_maybe)($t6)
  sh    $v0, 0x46($sp)
  lui   $t7, %hi(D_8004099C) 
  beql  $t6, $zero, .L7F0A9040
   lhu   $t8, 0x46($sp)
  lw    $t7, %lo(D_8004099C)($t7)
  li    $at, 1
  bnel  $t7, $at, .L7F0A9040
   lhu   $t8, 0x46($sp)
  jal   sub_GAME_7F0A8ED0
   addiu $a0, $sp, 0x46
  lhu   $t8, 0x46($sp)
.L7F0A9040:
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t8, $f4
  bgez  $t8, .L7F0A905C
   cvt.s.w $f6, $f4
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F0A905C:
  lui   $at, %hi(D_80058538)
  lwc1  $f10, %lo(D_80058538)($at)
  move  $a0, $t8
  div.s $f16, $f6, $f10
  jal   sfx_c_700091E8
   swc1  $f16, 0x40($sp)
  move  $v0, $s0
  lui   $t9, (0xB900031D >> 16) # lui $t9, 0xb900
  lui   $t0, (0x00504240 >> 16) # lui $t0, 0x50
  ori   $t0, (0x00504240 & 0xFFFF) # ori $t0, $t0, 0x4240
  ori   $t9, (0xB900031D & 0xFFFF) # ori $t9, $t9, 0x31d
  sw    $t9, ($v0)
  sw    $t0, 4($v0)
  lw    $a1, 0x3c($sp)
  lui   $at, 0x8000
  addiu $a0, $s0, 8
  jal   sub_GAME_7F0A3B40
   addu  $a1, $a1, $at
  li    $t1, 20
  li    $t2, -299
  li    $t3, -205
  move  $s0, $v0
  sw    $t3, 0x18($sp)
  sw    $t2, 0x14($sp)
  sw    $t1, 0x10($sp)
  lw    $a0, 0x3c($sp)
  move  $a1, $zero
  move  $a2, $zero
  jal   sub_GAME_7F0A3AB8
   li    $a3, 600
  lui   $at, 0x8000
  sw    $v0, 0x38($sp)
  addu  $a1, $v0, $at
  jal   sub_GAME_7F0A3B40
   move  $a0, $s0
  li    $t4, 20
  li    $t5, -299
  li    $t6, -205
  move  $s0, $v0
  sw    $t6, 0x18($sp)
  sw    $t5, 0x14($sp)
  sw    $t4, 0x10($sp)
  lw    $a0, 0x38($sp)
  move  $a1, $zero
  move  $a2, $zero
  jal   sub_GAME_7F0A3AB8
   li    $a3, 600
  lui   $at, 0x8000
  sw    $v0, 0x38($sp)
  addu  $a1, $v0, $at
  jal   sub_GAME_7F0A3B40
   move  $a0, $s0
  li    $t7, 20
  li    $t8, -299
  li    $t9, -205
  move  $s0, $v0
  sw    $t9, 0x18($sp)
  sw    $t8, 0x14($sp)
  sw    $t7, 0x10($sp)
  lw    $a0, 0x38($sp)
  move  $a1, $zero
  move  $a2, $zero
  jal   sub_GAME_7F0A3AB8
   li    $a3, 600
  lw    $a0, 0x3c($sp)
  lw    $a1, 0x40($sp)
  jal   sub_GAME_7F0A8D40
   li    $a2, 30
  lw    $ra, 0x2c($sp)
  move  $v0, $s0
  lw    $s0, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x48
");

void call_sfx_c_700091C8(void) { sfx_c_700091C8(); }

asm(R"
glabel sub_GAME_7F0A91A0
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  andi  $t6, $a0, 0xffff
  jal   sfx_c_700091E8
   move  $a0, $t6
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_8005853C
.word 0x46fffe00 /*32767.0*/
.text
glabel sub_GAME_7F0A91C8
  addiu $sp, $sp, -0x48
  sw    $s0, 0x28($sp)
  move  $s0, $a0
  sw    $ra, 0x2c($sp)
  jal   sub_GAME_7F0BD6C4
   li    $a0, 12
  jal   sub_GAME_7F0A9358
   sw    $v0, 0x3c($sp)
  lui   $t6, %hi(watch_soundrelated_maybe) 
  lw    $t6, %lo(watch_soundrelated_maybe)($t6)
  sh    $v0, 0x46($sp)
  lui   $t7, %hi(D_8004099C) 
  beql  $t6, $zero, .L7F0A9218
   lhu   $t8, 0x46($sp)
  lw    $t7, %lo(D_8004099C)($t7)
  bnezl $t7, .L7F0A9218
   lhu   $t8, 0x46($sp)
  jal   sub_GAME_7F0A8ED0
   addiu $a0, $sp, 0x46
  lhu   $t8, 0x46($sp)
.L7F0A9218:
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t8, $f4
  bgez  $t8, .L7F0A9234
   cvt.s.w $f6, $f4
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F0A9234:
  lui   $at, %hi(D_8005853C)
  lwc1  $f10, %lo(D_8005853C)($at)
  move  $a0, $t8
  div.s $f16, $f6, $f10
  jal   sub_GAME_7F0A9364
   swc1  $f16, 0x40($sp)
  move  $v0, $s0
  lui   $t9, (0xB900031D >> 16) # lui $t9, 0xb900
  lui   $t0, (0x00504240 >> 16) # lui $t0, 0x50
  ori   $t0, (0x00504240 & 0xFFFF) # ori $t0, $t0, 0x4240
  ori   $t9, (0xB900031D & 0xFFFF) # ori $t9, $t9, 0x31d
  sw    $t9, ($v0)
  sw    $t0, 4($v0)
  lw    $a1, 0x3c($sp)
  lui   $at, 0x8000
  addiu $a0, $s0, 8
  jal   sub_GAME_7F0A3B40
   addu  $a1, $a1, $at
  li    $t1, 20
  li    $t2, -299
  li    $t3, -275
  move  $s0, $v0
  sw    $t3, 0x18($sp)
  sw    $t2, 0x14($sp)
  sw    $t1, 0x10($sp)
  lw    $a0, 0x3c($sp)
  move  $a1, $zero
  move  $a2, $zero
  jal   sub_GAME_7F0A3AB8
   li    $a3, 600
  lui   $at, 0x8000
  sw    $v0, 0x38($sp)
  addu  $a1, $v0, $at
  jal   sub_GAME_7F0A3B40
   move  $a0, $s0
  li    $t4, 20
  li    $t5, -299
  li    $t6, -275
  move  $s0, $v0
  sw    $t6, 0x18($sp)
  sw    $t5, 0x14($sp)
  sw    $t4, 0x10($sp)
  lw    $a0, 0x38($sp)
  move  $a1, $zero
  move  $a2, $zero
  jal   sub_GAME_7F0A3AB8
   li    $a3, 600
  lui   $at, 0x8000
  sw    $v0, 0x38($sp)
  addu  $a1, $v0, $at
  jal   sub_GAME_7F0A3B40
   move  $a0, $s0
  li    $t7, 20
  li    $t8, -299
  li    $t9, -275
  move  $s0, $v0
  sw    $t9, 0x18($sp)
  sw    $t8, 0x14($sp)
  sw    $t7, 0x10($sp)
  lw    $a0, 0x38($sp)
  move  $a1, $zero
  move  $a2, $zero
  jal   sub_GAME_7F0A3AB8
   li    $a3, 600
  lw    $a0, 0x3c($sp)
  lw    $a1, 0x40($sp)
  jal   sub_GAME_7F0A8D40
   li    $a2, 30
  lw    $ra, 0x2c($sp)
  move  $v0, $s0
  lw    $s0, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x48
");

unsigned short sub_GAME_7F0A9358(void) { return mTrack2Vol; }

asm(R"
glabel sub_GAME_7F0A9364
  addiu $sp, $sp, -0x18
  lui   $v0, %hi(mTrack2Vol)
  addiu $v0, %lo(mTrack2Vol) # addiu $v0, $v0, 0xb58
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  move  $a1, $a0
  sh    $a1, ($v0)
  jal   musicTrack2Vol
   andi  $a0, $a1, 0xffff
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0A9398
  addiu $sp, $sp, -0x68
  sw    $a3, 0x74($sp)
  lui   $v0, %hi(ptrFirstFontTableSmall)
  lw    $v0, %lo(ptrFirstFontTableSmall)($v0)
  lui   $a3, %hi(ptrSecondFontTableSmall)
  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
  sw    $s0, 0x38($sp)
  move  $s0, $a0
  sw    $ra, 0x3c($sp)
  sw    $a1, 0x6c($sp)
  sw    $a2, 0x70($sp)
  li    $t6, 10
  sw    $t6, 0x14($sp)
  lw    $a2, 0x74($sp)
  addiu $a1, $sp, 0x58
  addiu $a0, $sp, 0x54
  sw    $v0, 0x10($sp)
  sw    $v0, 0x50($sp)
  jal   sub_GAME_7F0AE98C
   sw    $a3, 0x4c($sp)
  lw    $t7, 0x84($sp)
  lw    $v0, 0x6c($sp)
  lw    $t4, 0x58($sp)
  beqz  $t7, .L7F0A9418
   lw    $t5, 0x70($sp)
  lw    $t8, 0x58($sp)
  bgez  $t8, .L7F0A9410
   sra   $t9, $t8, 1
  addiu $at, $t8, 1
  sra   $t9, $at, 1
.L7F0A9410:
  b     .L7F0A9434
   subu  $t1, $v0, $t9
.L7F0A9418:
  lw    $t2, 0x90($sp)
  lw    $t3, 0x58($sp)
  move  $t1, $v0
  beqz  $t2, .L7F0A9434
   nop   
  b     .L7F0A9434
   subu  $t1, $v0, $t3
.L7F0A9434:
  lui   $t7, %hi(D_80040B04) 
  lw    $t7, %lo(D_80040B04)($t7)
  lw    $t6, 0x54($sp)
  addu  $v1, $t1, $t4
  slti  $at, $t7, 0xe0
  sw    $t1, 0x64($sp)
  beqz  $at, .L7F0A9478
   addu  $t0, $t5, $t6
  move  $v0, $s0
  lui   $t8, (0xB900031D >> 16) # lui $t8, 0xb900
  lui   $t9, (0x0050004B >> 16) # lui $t9, 0x50
  ori   $t9, (0x0050004B & 0xFFFF) # ori $t9, $t9, 0x4b
  ori   $t8, (0xB900031D & 0xFFFF) # ori $t8, $t8, 0x31d
  sw    $t8, ($v0)
  sw    $t9, 4($v0)
  b     .L7F0A9498
   addiu $s0, $s0, 8
.L7F0A9478:
  move  $v0, $s0
  lui   $t2, (0xB900031D >> 16) # lui $t2, 0xb900
  lui   $t3, (0x005041C8 >> 16) # lui $t3, 0x50
  ori   $t3, (0x005041C8 & 0xFFFF) # ori $t3, $t3, 0x41c8
  ori   $t2, (0xB900031D & 0xFFFF) # ori $t2, $t2, 0x31d
  sw    $t2, ($v0)
  sw    $t3, 4($v0)
  addiu $s0, $s0, 8
.L7F0A9498:
  lw    $t4, 0x88($sp)
  lw    $t1, 0x64($sp)
  move  $a0, $s0
  beqz  $t4, .L7F0A94DC
   addiu $a1, $t1, -1
  lw    $t5, 0x70($sp)
  lw    $t6, 0x7c($sp)
  lw    $t8, 0x8c($sp)
  addiu $t7, $t0, 1
  addu  $a2, $t5, $t6
  addiu $a2, $a2, 1
  sw    $t7, 0x10($sp)
  addiu $a3, $v1, 1
  sw    $t1, 0x64($sp)
  jal   microcode_constructor_related_to_menus
   sw    $t8, 0x14($sp)
  move  $s0, $v0
.L7F0A94DC:
  move  $v0, $s0
  lui   $t9, (0xB900031D >> 16) # lui $t9, 0xb900
  lui   $t2, (0x005041C8 >> 16) # lui $t2, 0x50
  ori   $t2, (0x005041C8 & 0xFFFF) # ori $t2, $t2, 0x41c8
  ori   $t9, (0xB900031D & 0xFFFF) # ori $t9, $t9, 0x31d
  sw    $t9, ($v0)
  sw    $t2, 4($v0)
  lw    $t3, 0x7c($sp)
  addiu $s0, $s0, 8
  move  $a0, $s0
  bnez  $t3, .L7F0A9550
   addiu $a1, $sp, 0x64
  lw    $t4, 0x4c($sp)
  lw    $t5, 0x50($sp)
  lw    $t6, 0x78($sp)
  lw    $t7, 0x58($sp)
  lw    $t8, 0x54($sp)
  li    $t9, 10
  sw    $t9, 0x28($sp)
  addiu $a2, $sp, 0x70
  lw    $a3, 0x74($sp)
  sw    $zero, 0x24($sp)
  sw    $t4, 0x10($sp)
  sw    $t5, 0x14($sp)
  sw    $t6, 0x18($sp)
  sw    $t7, 0x1c($sp)
  jal   en_text_write_stuff
   sw    $t8, 0x20($sp)
  move  $s0, $v0
.L7F0A9550:
  lw    $t2, 0x7c($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x64
  beqz  $t2, .L7F0A95B0
   addiu $a2, $sp, 0x70
  lw    $t7, 0x58($sp)
  lw    $t3, 0x4c($sp)
  lw    $t4, 0x50($sp)
  lw    $t5, 0x78($sp)
  lw    $t6, 0x80($sp)
  lw    $t9, 0x54($sp)
  li    $t2, 10
  addiu $t8, $t7, 1
  sw    $t8, 0x20($sp)
  sw    $t2, 0x2c($sp)
  lw    $a3, 0x74($sp)
  sw    $zero, 0x28($sp)
  sw    $t3, 0x10($sp)
  sw    $t4, 0x14($sp)
  sw    $t5, 0x18($sp)
  sw    $t6, 0x1c($sp)
  jal   jp_text_write_stuff
   sw    $t9, 0x24($sp)
  move  $s0, $v0
.L7F0A95B0:
  lw    $ra, 0x3c($sp)
  move  $v0, $s0
  lw    $s0, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x68
");

asm(R"
glabel sub_GAME_7F0A95C4
  c.lt.s $f12, $f14
  sw    $a2, 8($sp)
  bc1fl .L7F0A95EC
   c.lt.s $f14, $f12
  sub.s $f4, $f14, $f12
  lwc1  $f6, 8($sp)
  div.s $f8, $f4, $f6
  jr    $ra
   add.s $f0, $f12, $f8

  c.lt.s $f14, $f12
.L7F0A95EC:
  nop   
  bc1f  .L7F0A9608
   nop   
  sub.s $f10, $f12, $f14
  lwc1  $f16, 8($sp)
  div.s $f18, $f10, $f16
  sub.s $f12, $f12, $f18
.L7F0A9608:
  jr    $ra
   mov.s $f0, $f12
");

asm(R"
.late_rodata
glabel D_80058540
.word 0x3dcccccd /*0.1*/
glabel D_80058544
.word 0xbdcccccd /*-0.1*/
.text
glabel sub_GAME_7F0A9610
  lui   $at, %hi(D_80058540)
  lwc1  $f2, %lo(D_80058540)($at)
  lui   $at, %hi(D_80040B24)
  lwc1  $f0, %lo(D_80040B24)($at)
  lui   $at, %hi(D_80058544)
  move  $v0, $zero
  c.lt.s $f0, $f2
  nop   
  bc1f  .L7F0A967C
   nop   
  lwc1  $f12, %lo(D_80058544)($at)
  lui   $at, %hi(D_80040B20)
  c.lt.s $f12, $f0
  nop   
  bc1f  .L7F0A967C
   nop   
  lwc1  $f0, %lo(D_80040B20)($at)
  c.lt.s $f0, $f2
  nop   
  bc1f  .L7F0A967C
   nop   
  c.lt.s $f12, $f0
  nop   
  bc1f  .L7F0A967C
   nop   
  jr    $ra
   li    $v0, 1

.L7F0A967C:
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80058548
.word 0x3e4ccccd /*0.2*/
glabel D_8005854C
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F0A9684
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  sw    $a2, 0x20($sp)
  sw    $a3, 0x24($sp)
  lb    $a0, 0x1b($sp)
  jal   get_cur_controller_horz_stick_pos
   sw    $a1, 0x1c($sp)
  slti  $at, $v0, 0xa
  beqz  $at, .L7F0A96C8
   lw    $a1, 0x1c($sp)
  lb    $a0, 0x1b($sp)
  jal   get_cur_controller_horz_stick_pos
   sw    $a1, 0x1c($sp)
  slti  $at, $v0, -9
  beqz  $at, .L7F0A96F0
   lw    $a1, 0x1c($sp)
.L7F0A96C8:
  lui   $t6, %hi(watch_soundrelated_maybe) 
  lw    $t6, %lo(watch_soundrelated_maybe)($t6)
  lui   $t7, %hi(D_80040998) 
  beql  $t6, $zero, .L7F0A96F4
   lw    $v0, ($a1)
  lw    $t7, %lo(D_80040998)($t7)
  li    $at, 1
  move  $v0, $zero
  beql  $t7, $at, .L7F0A9710
   sw    $zero, ($a1)
.L7F0A96F0:
  lw    $v0, ($a1)
.L7F0A96F4:
  slti  $at, $v0, 0x64
  beqz  $at, .L7F0A9710
   addiu $t8, $v0, 1
  sw    $t8, ($a1)
  b     .L7F0A9710
   move  $v0, $t8
  sw    $zero, ($a1)
.L7F0A9710:
  slti  $at, $v0, 0x64
  bnez  $at, .L7F0A9750
   lui   $t2, %hi(watch_soundrelated_maybe) 
  lw    $t0, 0x24($sp)
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f8
  lwc1  $f4, ($t0)
  lw    $t9, 0x20($sp)
  lui   $a2, 0x4080
  neg.s $f6, $f4
  lwc1  $f12, ($t9)
  jal   sub_GAME_7F0A95C4
   div.s $f14, $f6, $f8
  lw    $t1, 0x20($sp)
  b     .L7F0A97C0
   swc1  $f0, ($t1)
.L7F0A9750:
  lw    $t2, %lo(watch_soundrelated_maybe)($t2)
  lui   $t3, %hi(D_80040998) 
  beql  $t2, $zero, .L7F0A97C4
   lw    $ra, 0x14($sp)
  lw    $t3, %lo(D_80040998)($t3)
  li    $at, 1
  bnel  $t3, $at, .L7F0A97C4
   lw    $ra, 0x14($sp)
  jal   get_cur_controller_horz_stick_pos
   lb    $a0, 0x1b($sp)
  mtc1  $v0, $f10
  lui   $at, %hi(D_80058548)
  lwc1  $f4, %lo(D_80058548)($at)
  cvt.s.w $f16, $f10
  lui   $at, %hi(D_8005854C)
  lwc1  $f8, %lo(D_8005854C)($at)
  li    $at, 0x43B40000 # 360.000000
  lw    $t4, 0x20($sp)
  lui   $a2, 0x4080
  neg.s $f18, $f16
  mtc1  $at, $f16
  mul.s $f6, $f18, $f4
  lwc1  $f12, ($t4)
  mul.s $f10, $f6, $f8
  jal   sub_GAME_7F0A95C4
   div.s $f14, $f10, $f16
  lw    $t5, 0x20($sp)
  swc1  $f0, ($t5)
.L7F0A97C0:
  lw    $ra, 0x14($sp)
.L7F0A97C4:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0A97D0
  addiu $sp, $sp, -0x850
  lui   $a2, %hi(D_800409D8)
  lw    $a2, %lo(D_800409D8)($a2)
  lui   $t6, %hi(ptrFirstFontTableSmall) 
  lui   $t7, %hi(ptrSecondFontTableSmall) 
  lw    $t6, %lo(ptrFirstFontTableSmall)($t6)
  lw    $t7, %lo(ptrSecondFontTableSmall)($t7)
  sw    $s0, 0x34($sp)
  sw    $ra, 0x3c($sp)
  sw    $s1, 0x38($sp)
  sw    $a0, 0x850($sp)
  sw    $zero, 0x60($sp)
  sw    $zero, 0x5c($sp)
  sb    $zero, 0x74($sp)
  move  $s0, $zero
  sw    $t6, 0x58($sp)
  blez  $a2, .L7F0A9850
   sw    $t7, 0x54($sp)
  lui   $s1, %hi(D_800409DC)
  addiu $s1, %lo(D_800409DC) # addiu $s1, $s1, 0x9dc
.L7F0A9820:
  jal   get_textptr_for_textID
   lhu   $a0, ($s1)
  addiu $a0, $sp, 0x74
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  lui   $a2, %hi(D_800409D8)
  lw    $a2, %lo(D_800409D8)($a2)
  addiu $s0, $s0, 1
  addiu $s1, $s1, 0x14
  slt   $at, $s0, $a2
  bnez  $at, .L7F0A9820
   nop   
.L7F0A9850:
  lui   $t8, %hi(watch_soundrelated_maybe) 
  lw    $t8, %lo(watch_soundrelated_maybe)($t8)
  lui   $t9, %hi(D_80040998) 
  beqz  $t8, .L7F0A98C4
   nop   
  lw    $t9, %lo(D_80040998)($t9)
  lui   $s1, %hi(j_text_trigger)
  addiu $s1, %lo(j_text_trigger) # addiu $s1, $s1, -0x7b30
  bnez  $t9, .L7F0A98C4
   lui   $v1, %hi(pPlayer)
  lw    $t0, ($s1)
  li    $t3, 1
  li    $v0, 10
  beqz  $t0, .L7F0A9894
   nop   
  b     .L7F0A9894
   li    $v0, 14
.L7F0A9894:
  lw    $v1, %lo(pPlayer)($v1)
  sw    $zero, 0x18($sp)
  sw    $t3, 0x1c($sp)
  addiu $t1, $v1, 0x2a5c
  addiu $t2, $v1, 0x2a68
  sw    $t2, 0x14($sp)
  sw    $t1, 0x10($sp)
  sw    $v0, 0x20($sp)
  addiu $a0, $v1, 0x2a60
  addiu $a1, $v1, 0x2a58
  jal   sub_GAME_7F0A611C
   addiu $a3, $v1, 0x2a64
.L7F0A98C4:
  lui   $s1, %hi(j_text_trigger)
  addiu $s1, %lo(j_text_trigger) # addiu $s1, $s1, -0x7b30
  lw    $v0, ($s1)
  li    $t4, 170
  li    $t5, 26
  sw    $t4, 0x70($sp)
  beqz  $v0, .L7F0A98EC
   sw    $t5, 0x6c($sp)
  b     .L7F0A98F0
   li    $v0, 14
.L7F0A98EC:
  li    $v0, 10
.L7F0A98F0:
  lw    $t6, 0x58($sp)
  addiu $a0, $sp, 0x60
  addiu $a1, $sp, 0x5c
  addiu $a2, $sp, 0x74
  lw    $a3, 0x54($sp)
  sw    $v0, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t6, 0x10($sp)
  lw    $v0, ($s1)
  lw    $a0, 0x850($sp)
  addiu $a1, $sp, 0x70
  beqz  $v0, .L7F0A992C
   addiu $a2, $sp, 0x6c
  b     .L7F0A9930
   li    $s0, 14
.L7F0A992C:
  li    $s0, 10
.L7F0A9930:
  beqz  $v0, .L7F0A9940
   addiu $a3, $sp, 0x74
  b     .L7F0A9944
   li    $v0, 14
.L7F0A9940:
  li    $v0, 10
.L7F0A9944:
  lw    $t7, 0x54($sp)
  lw    $t8, 0x58($sp)
  lw    $t0, 0x5c($sp)
  lui   $t1, %hi(pPlayer) 
  lw    $t1, %lo(pPlayer)($t1)
  lui   $t9, (0x00AA00B0 >> 16) # lui $t9, 0xaa
  ori   $t9, (0x00AA00B0 & 0xFFFF) # ori $t9, $t9, 0xb0
  sw    $t9, 0x18($sp)
  sw    $s0, 0x20($sp)
  sw    $t7, 0x10($sp)
  sw    $t8, 0x14($sp)
  sw    $t0, 0x1c($sp)
  lw    $t2, 0x2a64($t1)
  sw    $v0, 0x28($sp)
  jal   en_text_write_stuff
   sw    $t2, 0x24($sp)
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  sw    $v0, 0x850($sp)
  lw    $t3, 0x2a68($v1)
  beql  $t3, $zero, .L7F0A9AA4
   lw    $ra, 0x3c($sp)
  lw    $t4, 0x2a58($v1)
  lui   $a0, %hi(D_800409DC)
  sll   $t5, $t4, 2
  addu  $t5, $t5, $t4
  sll   $t5, $t5, 2
  addu  $a0, $a0, $t5
  jal   get_textptr_for_textID
   lhu   $a0, %lo(D_800409DC)($a0)
  lw    $t6, ($s1)
  move  $s0, $v0
  addiu $a0, $sp, 0x60
  beqz  $t6, .L7F0A99D8
   addiu $a1, $sp, 0x5c
  b     .L7F0A99DC
   li    $v0, 14
.L7F0A99D8:
  li    $v0, 10
.L7F0A99DC:
  lw    $t7, 0x58($sp)
  move  $a2, $s0
  lw    $a3, 0x54($sp)
  sw    $v0, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t7, 0x10($sp)
  lw    $t9, ($s1)
  li    $t8, 170
  sw    $t8, 0x70($sp)
  beqz  $t9, .L7F0A9A10
   lui   $t1, %hi(pPlayer) 
  b     .L7F0A9A10
   nop   
.L7F0A9A10:
  lw    $t1, %lo(pPlayer)($t1)
  li    $t0, 26
  sw    $t0, 0x6c($sp)
  lw    $t2, 0x2a58($t1)
  lui   $a0, %hi(D_800409DC)
  sll   $t3, $t2, 2
  addu  $t3, $t3, $t2
  sll   $t3, $t3, 2
  addu  $a0, $a0, $t3
  jal   get_textptr_for_textID
   lhu   $a0, %lo(D_800409DC)($a0)
  lw    $t4, ($s1)
  move  $s0, $v0
  lw    $a0, 0x850($sp)
  beqz  $t4, .L7F0A9A58
   addiu $a1, $sp, 0x70
  b     .L7F0A9A5C
   li    $v0, 14
.L7F0A9A58:
  li    $v0, 10
.L7F0A9A5C:
  lw    $t5, 0x54($sp)
  lw    $t6, 0x58($sp)
  lw    $t8, 0x5c($sp)
  lui   $t7, (0xA0FFA0F0 >> 16) # lui $t7, 0xa0ff
  ori   $t7, (0xA0FFA0F0 & 0xFFFF) # ori $t7, $t7, 0xa0f0
  li    $t9, 100
  sw    $t9, 0x20($sp)
  sw    $t7, 0x18($sp)
  addiu $a2, $sp, 0x6c
  move  $a3, $s0
  sw    $zero, 0x24($sp)
  sw    $v0, 0x28($sp)
  sw    $t5, 0x10($sp)
  sw    $t6, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t8, 0x1c($sp)
  sw    $v0, 0x850($sp)
  lw    $ra, 0x3c($sp)
.L7F0A9AA4:
  lw    $v0, 0x850($sp)
  lw    $s0, 0x34($sp)
  lw    $s1, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x850
");

asm(R"
glabel sub_GAME_7F0A9AB8
  lui   $t6, %hi(cur_player_look_vertical_inverted) 
  lw    $t6, %lo(cur_player_look_vertical_inverted)($t6)
  addiu $sp, $sp, -0xb0
  sw    $s0, 0x38($sp)
  li    $at, 1
  move  $s0, $a0
  bne   $t6, $at, .L7F0A9AF4
   sw    $ra, 0x3c($sp)
  jal   get_textptr_for_textID
   li    $a0, 44077
  sw    $v0, 0xac($sp)
  jal   get_textptr_for_textID
   li    $a0, 44076
  b     .L7F0A9B0C
   sw    $v0, 0xa8($sp)
.L7F0A9AF4:
  jal   get_textptr_for_textID
   li    $a0, 44076
  sw    $v0, 0xac($sp)
  jal   get_textptr_for_textID
   li    $a0, 44077
  sw    $v0, 0xa8($sp)
.L7F0A9B0C:
  lui   $t8, %hi(aA) 
  addiu $t8, %lo(aA) # addiu $t8, $t8, 0x7778
  lw    $at, ($t8)
  addiu $t7, $sp, 0xa0
  lui   $t3, %hi(aB) 
  sw    $at, ($t7)
  lbu   $at, 4($t8)
  addiu $t3, %lo(aB) # addiu $t3, $t3, 0x7780
  addiu $t2, $sp, 0x98
  sb    $at, 4($t7)
  lw    $at, ($t3)
  lui   $t9, %hi(aZ) 
  addiu $t9, %lo(aZ) # addiu $t9, $t9, 0x7788
  sw    $at, ($t2)
  lbu   $at, 4($t3)
  addiu $t0, $sp, 0x90
  lui   $t4, %hi(aL) 
  sb    $at, 4($t2)
  lw    $at, ($t9)
  addiu $t4, %lo(aL) # addiu $t4, $t4, 0x7790
  addiu $t5, $sp, 0x88
  sw    $at, ($t0)
  lbu   $at, 4($t9)
  lui   $t7, %hi(aR) 
  addiu $t7, %lo(aR) # addiu $t7, $t7, 0x7798
  sb    $at, 4($t0)
  lw    $at, ($t4)
  addiu $t8, $sp, 0x80
  lui   $t2, %hi(aC) 
  sw    $at, ($t5)
  lbu   $at, 4($t4)
  addiu $t2, %lo(aC) # addiu $t2, $t2, 0x77a0
  addiu $t3, $sp, 0x78
  sb    $at, 4($t5)
  lw    $at, ($t7)
  lui   $t0, %hi(D_800577A8) 
  addiu $t0, %lo(D_800577A8) # addiu $t0, $t0, 0x77a8
  sw    $at, ($t8)
  lbu   $at, 4($t7)
  addiu $t9, $sp, 0x70
  lui   $t5, %hi(aS_0) 
  sb    $at, 4($t8)
  lw    $at, ($t2)
  addiu $t5, %lo(aS_0) # addiu $t5, $t5, 0x77b0
  addiu $t4, $sp, 0x68
  sw    $at, ($t3)
  lbu   $at, 4($t2)
  lui   $t8, %hi(a3d) 
  addiu $t8, %lo(a3d) # addiu $t8, $t8, 0x77b8
  sb    $at, 4($t3)
  lw    $at, ($t0)
  addiu $t7, $sp, 0x60
  move  $a0, $s0
  sw    $at, ($t9)
  lbu   $at, 4($t0)
  sb    $at, 4($t9)
  lw    $at, ($t5)
  sw    $at, ($t4)
  lbu   $at, 4($t5)
  sb    $at, 4($t4)
  lw    $at, ($t8)
  sw    $at, ($t7)
  lhu   $at, 4($t8)
  sh    $at, 4($t7)
  jal   microcode_constructor
   sw    $zero, 0x50($sp)
  move  $s0, $v0
  move  $a0, $zero
  jal   get_controller_buttons_held
   li    $a1, 32
  beqz  $v0, .L7F0A9CD8
   lui   $t2, %hi(pPlayer) 
  lw    $t2, %lo(pPlayer)($t2)
  lui   $a0, %hi(D_800409DC+8)
  lw    $t3, 0x2a58($t2)
  sll   $t4, $t3, 2
  addu  $t4, $t4, $t3
  sll   $t4, $t4, 2
  addu  $a0, $a0, $t4
  jal   get_textptr_for_textID
   lhu   $a0, %lo(D_800409DC+8)($a0)
  lui   $t0, (0x007000A0 >> 16) # lui $t0, 0x70
  lui   $t9, (0x003000B0 >> 16) # lui $t9, 0x30
  ori   $t9, (0x003000B0 & 0xFFFF) # ori $t9, $t9, 0xb0
  ori   $t0, (0x007000A0 & 0xFFFF) # ori $t0, $t0, 0xa0
  li    $t5, -1
  li    $t6, 1
  sw    $t6, 0x14($sp)
  sw    $t5, 0x10($sp)
  sw    $t0, 0x18($sp)
  sw    $t9, 0x24($sp)
  move  $a0, $s0
  li    $a1, 50
  li    $a2, 82
  move  $a3, $v0
  sw    $zero, 0x1c($sp)
  sw    $zero, 0x20($sp)
  jal   sub_GAME_7F0A9398
   sw    $zero, 0x28($sp)
  lui   $t7, %hi(pPlayer) 
  lw    $t7, %lo(pPlayer)($t7)
  lui   $t2, %hi(D_800409DC+9)
  li    $at, 44033
  lw    $t8, 0x2a58($t7)
  move  $s0, $v0
  li    $t3, 1
  sll   $t1, $t8, 2
  addu  $t1, $t1, $t8
  sll   $t1, $t1, 2
  addu  $t2, $t2, $t1
  lhu   $t2, %lo(D_800409DC+8)($t2)
  bne   $t2, $at, .L7F0A9D48
   nop   
  b     .L7F0A9D48
   sw    $t3, 0x50($sp)
.L7F0A9CD8:
  lui   $t4, %hi(pPlayer) 
  lw    $t4, %lo(pPlayer)($t4)
  lui   $a0, %hi(D_800409DC+8)
  lw    $t5, 0x2a58($t4)
  sll   $t6, $t5, 2
  addu  $t6, $t6, $t5
  sll   $t6, $t6, 2
  addu  $a0, $a0, $t6
  jal   get_textptr_for_textID
   lhu   $a0, %lo(D_800409DC+8)($a0)
  lui   $t0, (0x00AA00B0 >> 16) # lui $t0, 0xaa
  lui   $t7, (0x003000B0 >> 16) # lui $t7, 0x30
  ori   $t7, (0x003000B0 & 0xFFFF) # ori $t7, $t7, 0xb0
  ori   $t0, (0x00AA00B0 & 0xFFFF) # ori $t0, $t0, 0xb0
  li    $t9, -1
  sw    $t9, 0x18($sp)
  sw    $t0, 0x10($sp)
  sw    $t7, 0x24($sp)
  move  $a0, $s0
  li    $a1, 50
  li    $a2, 82
  move  $a3, $v0
  sw    $zero, 0x14($sp)
  sw    $zero, 0x1c($sp)
  sw    $zero, 0x20($sp)
  jal   sub_GAME_7F0A9398
   sw    $zero, 0x28($sp)
  move  $s0, $v0
.L7F0A9D48:
  lui   $t1, %hi(D_80040998) 
  lw    $t1, %lo(D_80040998)($t1)
  li    $t8, 107
  li    $at, 1
  bne   $t1, $at, .L7F0A9D84
   sw    $t8, 0x4c($sp)
  lui   $t2, %hi(watch_soundrelated_maybe) 
  lw    $t2, %lo(watch_soundrelated_maybe)($t2)
  move  $a0, $zero
  beqz  $t2, .L7F0A9D84
   nop   
  jal   get_controller_buttons_held
   li    $a1, 3840
  bnez  $v0, .L7F0A9DF8
   move  $a0, $zero
.L7F0A9D84:
  lui   $t3, %hi(pPlayer) 
  lw    $t3, %lo(pPlayer)($t3)
  lui   $a0, %hi(D_800409DC+14)
  lw    $t4, 0x2a58($t3)
  sll   $t5, $t4, 2
  addu  $t5, $t5, $t4
  sll   $t5, $t5, 2
  addu  $a0, $a0, $t5
  jal   get_textptr_for_textID
   lhu   $a0, %lo(D_800409DC+14)($a0)
  lui   $t6, (0x00AA00B0 >> 16) # lui $t6, 0xaa
  lui   $t9, (0x003000B0 >> 16) # lui $t9, 0x30
  ori   $t9, (0x003000B0 & 0xFFFF) # ori $t9, $t9, 0xb0
  ori   $t6, (0x00AA00B0 & 0xFFFF) # ori $t6, $t6, 0xb0
  li    $t0, -1
  sw    $t0, 0x18($sp)
  sw    $t6, 0x10($sp)
  sw    $t9, 0x24($sp)
  move  $a0, $s0
  li    $a1, 50
  lw    $a2, 0x4c($sp)
  move  $a3, $v0
  sw    $zero, 0x14($sp)
  sw    $zero, 0x1c($sp)
  sw    $zero, 0x20($sp)
  jal   sub_GAME_7F0A9398
   sw    $zero, 0x28($sp)
  b     .L7F0A9F38
   move  $s0, $v0
.L7F0A9DF8:
  jal   get_controller_buttons_held
   li    $a1, 2048
  beqz  $v0, .L7F0A9E54
   move  $a0, $zero
  lui   $t7, %hi(pPlayer) 
  lw    $t7, %lo(pPlayer)($t7)
  lui   $t2, %hi(D_800409DC+14)
  li    $at, 44037
  lw    $t8, 0x2a58($t7)
  lw    $a3, 0xac($sp)
  sll   $t1, $t8, 2
  addu  $t1, $t1, $t8
  sll   $t1, $t1, 2
  addu  $t2, $t2, $t1
  lhu   $t2, %lo(D_800409DC+14)($t2)
  bne   $t2, $at, .L7F0A9E4C
   nop   
  jal   get_textptr_for_textID
   li    $a0, 44080
  b     .L7F0A9E4C
   move  $a3, $v0
.L7F0A9E4C:
  b     .L7F0A9EEC
   sw    $a3, 0x58($sp)
.L7F0A9E54:
  jal   get_controller_buttons_held
   li    $a1, 1024
  beqz  $v0, .L7F0A9EB0
   move  $a0, $zero
  lui   $t3, %hi(pPlayer) 
  lw    $t3, %lo(pPlayer)($t3)
  lui   $t6, %hi(D_800409DC+14)
  li    $at, 44037
  lw    $t4, 0x2a58($t3)
  lw    $a3, 0xa8($sp)
  sll   $t5, $t4, 2
  addu  $t5, $t5, $t4
  sll   $t5, $t5, 2
  addu  $t6, $t6, $t5
  lhu   $t6, %lo(D_800409DC+14)($t6)
  bne   $t6, $at, .L7F0A9EA8
   nop   
  jal   get_textptr_for_textID
   li    $a0, 44081
  b     .L7F0A9EA8
   move  $a3, $v0
.L7F0A9EA8:
  b     .L7F0A9EEC
   sw    $a3, 0x58($sp)
.L7F0A9EB0:
  jal   get_controller_buttons_held
   li    $a1, 512
  beqz  $v0, .L7F0A9ED0
   move  $a0, $zero
  jal   get_textptr_for_textID
   li    $a0, 44079
  b     .L7F0A9EEC
   sw    $v0, 0x58($sp)
.L7F0A9ED0:
  jal   get_controller_buttons_held
   li    $a1, 256
  beql  $v0, $zero, .L7F0A9EF0
   lui   $t7, 0x70
  jal   get_textptr_for_textID
   li    $a0, 44078
  sw    $v0, 0x58($sp)
.L7F0A9EEC:
  lui   $t7, (0x007000A0 >> 16) # lui $t7, 0x70
.L7F0A9EF0:
  lui   $t8, (0x003000B0 >> 16) # lui $t8, 0x30
  ori   $t8, (0x003000B0 & 0xFFFF) # ori $t8, $t8, 0xb0
  ori   $t7, (0x007000A0 & 0xFFFF) # ori $t7, $t7, 0xa0
  li    $t0, -1
  li    $t9, 1
  lw    $a3, 0x58($sp)
  sw    $t9, 0x14($sp)
  sw    $t0, 0x10($sp)
  sw    $t7, 0x18($sp)
  sw    $t8, 0x24($sp)
  move  $a0, $s0
  li    $a1, 50
  lw    $a2, 0x4c($sp)
  sw    $zero, 0x1c($sp)
  sw    $zero, 0x20($sp)
  jal   sub_GAME_7F0A9398
   sw    $zero, 0x28($sp)
  move  $s0, $v0
.L7F0A9F38:
  lw    $t1, 0x4c($sp)
  lui   $t3, %hi(pPlayer) 
  lw    $t3, %lo(pPlayer)($t3)
  addiu $t2, $t1, 0x19
  sw    $t2, 0x4c($sp)
  lw    $t4, 0x2a58($t3)
  lui   $a0, %hi(D_800409DC+16)
  sll   $t5, $t4, 2
  addu  $t5, $t5, $t4
  sll   $t5, $t5, 2
  addu  $a0, $a0, $t5
  jal   get_textptr_for_textID
   lhu   $a0, %lo(D_800409DC+16)($a0)
  lui   $t6, (0x00AA00B0 >> 16) # lui $t6, 0xaa
  lui   $t9, (0x003000B0 >> 16) # lui $t9, 0x30
  ori   $t9, (0x003000B0 & 0xFFFF) # ori $t9, $t9, 0xb0
  ori   $t6, (0x00AA00B0 & 0xFFFF) # ori $t6, $t6, 0xb0
  li    $t0, -1
  sw    $t0, 0x18($sp)
  sw    $t6, 0x10($sp)
  sw    $t9, 0x24($sp)
  move  $a0, $s0
  li    $a1, 50
  lw    $a2, 0x4c($sp)
  move  $a3, $v0
  sw    $zero, 0x14($sp)
  sw    $zero, 0x1c($sp)
  sw    $zero, 0x20($sp)
  jal   sub_GAME_7F0A9398
   sw    $zero, 0x28($sp)
  lw    $t7, 0x4c($sp)
  move  $s0, $v0
  move  $a0, $zero
  addiu $t8, $t7, 0x19
  sw    $t8, 0x4c($sp)
  jal   get_controller_buttons_held
   li    $a1, 8192
  beqz  $v0, .L7F0AA084
   lui   $t3, %hi(pPlayer)
  lui   $t1, %hi(pPlayer) 
  lw    $t1, %lo(pPlayer)($t1)
  lui   $a0, %hi(D_800409DC+0x6)
  lw    $t2, 0x2a58($t1)
  sll   $t3, $t2, 2
  addu  $t3, $t3, $t2
  sll   $t3, $t3, 2
  addu  $a0, $a0, $t3
  jal   get_textptr_for_textID
   lhu   $a0, %lo(D_800409DC+0x6)($a0)
  lui   $t6, (0x007000A0 >> 16) # lui $t6, 0x70
  lui   $t0, (0x003000B0 >> 16) # lui $t0, 0x30
  ori   $t0, (0x003000B0 & 0xFFFF) # ori $t0, $t0, 0xb0
  ori   $t6, (0x007000A0 & 0xFFFF) # ori $t6, $t6, 0xa0
  li    $t4, -1
  li    $t5, 1
  sw    $t5, 0x14($sp)
  sw    $t4, 0x10($sp)
  sw    $t6, 0x18($sp)
  sw    $t0, 0x24($sp)
  move  $a0, $s0
  li    $a1, 50
  lw    $a2, 0x4c($sp)
  move  $a3, $v0
  sw    $zero, 0x1c($sp)
  sw    $zero, 0x20($sp)
  jal   sub_GAME_7F0A9398
   sw    $zero, 0x28($sp)
  lui   $t9, %hi(pPlayer) 
  lw    $t9, %lo(pPlayer)($t9)
  lui   $t1, %hi(D_800409DC+6)
  li    $at, 44033
  lw    $t7, 0x2a58($t9)
  move  $s0, $v0
  li    $t2, 1
  sll   $t8, $t7, 2
  addu  $t8, $t8, $t7
  sll   $t8, $t8, 2
  addu  $t1, $t1, $t8
  lhu   $t1, %lo(D_800409DC+6)($t1)
  bnel  $t1, $at, .L7F0AA0F4
   lw    $t7, 0x4c($sp)
  b     .L7F0AA0F0
   sw    $t2, 0x50($sp)
.L7F0AA084:
  lw    $t3, %lo(pPlayer)($t3)
  lui   $a0, %hi(D_800409DC+6)
  lw    $t4, 0x2a58($t3)
  sll   $t5, $t4, 2
  addu  $t5, $t5, $t4
  sll   $t5, $t5, 2
  addu  $a0, $a0, $t5
  jal   get_textptr_for_textID
   lhu   $a0, %lo(D_800409DC+6)($a0)
  lui   $t6, (0x00AA00B0 >> 16) # lui $t6, 0xaa
  lui   $t9, (0x003000B0 >> 16) # lui $t9, 0x30
  ori   $t9, (0x003000B0 & 0xFFFF) # ori $t9, $t9, 0xb0
  ori   $t6, (0x00AA00B0 & 0xFFFF) # ori $t6, $t6, 0xb0
  li    $t0, -1
  sw    $t0, 0x18($sp)
  sw    $t6, 0x10($sp)
  sw    $t9, 0x24($sp)
  move  $a0, $s0
  li    $a1, 50
  lw    $a2, 0x4c($sp)
  move  $a3, $v0
  sw    $zero, 0x14($sp)
  sw    $zero, 0x1c($sp)
  sw    $zero, 0x20($sp)
  jal   sub_GAME_7F0A9398
   sw    $zero, 0x28($sp)
  move  $s0, $v0
.L7F0AA0F0:
  lw    $t7, 0x4c($sp)
.L7F0AA0F4:
  move  $a0, $zero
  li    $a1, 16
  addiu $t8, $t7, -0x4b
  jal   get_controller_buttons_held
   sw    $t8, 0x4c($sp)
  beqz  $v0, .L7F0AA1C4
   lui   $t4, %hi(pPlayer) 
  lui   $t1, %hi(pPlayer) 
  lw    $t1, %lo(pPlayer)($t1)
  lui   $a0, %hi(D_800409DC+10)
  lw    $t2, 0x2a58($t1)
  sll   $t3, $t2, 2
  addu  $t3, $t3, $t2
  sll   $t3, $t3, 2
  addu  $a0, $a0, $t3
  jal   get_textptr_for_textID
   lhu   $a0, %lo(D_800409DC+10)($a0)
  lui   $t6, (0x007000A0 >> 16) # lui $t6, 0x70
  lui   $t0, (0x003000B0 >> 16) # lui $t0, 0x30
  ori   $t0, (0x003000B0 & 0xFFFF) # ori $t0, $t0, 0xb0
  ori   $t6, (0x007000A0 & 0xFFFF) # ori $t6, $t6, 0xa0
  li    $t4, -1
  li    $t5, 1
  li    $t9, 1
  sw    $t9, 0x28($sp)
  sw    $t5, 0x14($sp)
  sw    $t4, 0x10($sp)
  sw    $t6, 0x18($sp)
  sw    $t0, 0x24($sp)
  move  $a0, $s0
  li    $a1, 270
  lw    $a2, 0x4c($sp)
  move  $a3, $v0
  sw    $zero, 0x1c($sp)
  jal   sub_GAME_7F0A9398
   sw    $zero, 0x20($sp)
  lui   $t7, %hi(pPlayer) 
  lw    $t7, %lo(pPlayer)($t7)
  lui   $t2, %hi(D_800409DC+10)
  li    $at, 44033
  lw    $t8, 0x2a58($t7)
  move  $s0, $v0
  li    $t3, 1
  sll   $t1, $t8, 2
  addu  $t1, $t1, $t8
  sll   $t1, $t1, 2
  addu  $t2, $t2, $t1
  lhu   $t2, %lo(D_800409DC+10)($t2)
  bnel  $t2, $at, .L7F0AA238
   lw    $t1, 0x4c($sp)
  b     .L7F0AA234
   sw    $t3, 0x50($sp)
.L7F0AA1C4:
  lw    $t4, %lo(pPlayer)($t4)
  lui   $a0, %hi(D_800409DC+10)
  lw    $t5, 0x2a58($t4)
  sll   $t6, $t5, 2
  addu  $t6, $t6, $t5
  sll   $t6, $t6, 2
  addu  $a0, $a0, $t6
  jal   get_textptr_for_textID
   lhu   $a0, %lo(D_800409DC+10)($a0)
  lui   $t0, (0x00AA00B0 >> 16) # lui $t0, 0xaa
  lui   $t7, (0x003000B0 >> 16) # lui $t7, 0x30
  ori   $t7, (0x003000B0 & 0xFFFF) # ori $t7, $t7, 0xb0
  ori   $t0, (0x00AA00B0 & 0xFFFF) # ori $t0, $t0, 0xb0
  li    $t9, -1
  li    $t8, 1
  sw    $t8, 0x28($sp)
  sw    $t9, 0x18($sp)
  sw    $t0, 0x10($sp)
  sw    $t7, 0x24($sp)
  move  $a0, $s0
  li    $a1, 270
  lw    $a2, 0x4c($sp)
  move  $a3, $v0
  sw    $zero, 0x14($sp)
  sw    $zero, 0x1c($sp)
  jal   sub_GAME_7F0A9398
   sw    $zero, 0x20($sp)
  move  $s0, $v0
.L7F0AA234:
  lw    $t1, 0x4c($sp)
.L7F0AA238:
  lui   $t3, %hi(D_80040998) 
  lw    $t3, %lo(D_80040998)($t3)
  li    $at, 1
  addiu $t2, $t1, 0x19
  bne   $t3, $at, .L7F0AA274
   sw    $t2, 0x4c($sp)
  lui   $t4, %hi(watch_soundrelated_maybe) 
  lw    $t4, %lo(watch_soundrelated_maybe)($t4)
  move  $a0, $zero
  beqz  $t4, .L7F0AA274
   nop   
  jal   get_controller_buttons_held
   li    $a1, 15
  bnez  $v0, .L7F0AA2EC
   move  $a0, $zero
.L7F0AA274:
  lui   $t5, %hi(pPlayer) 
  lw    $t5, %lo(pPlayer)($t5)
  lui   $a0, %hi(D_800409DC+12)
  lw    $t6, 0x2a58($t5)
  sll   $t0, $t6, 2
  addu  $t0, $t0, $t6
  sll   $t0, $t0, 2
  addu  $a0, $a0, $t0
  jal   get_textptr_for_textID
   lhu   $a0, %lo(D_800409DC+12)($a0)
  lui   $t9, (0x00AA00B0 >> 16) # lui $t9, 0xaa
  lui   $t8, (0x003000B0 >> 16) # lui $t8, 0x30
  ori   $t8, (0x003000B0 & 0xFFFF) # ori $t8, $t8, 0xb0
  ori   $t9, (0x00AA00B0 & 0xFFFF) # ori $t9, $t9, 0xb0
  li    $t7, -1
  li    $t1, 1
  sw    $t1, 0x28($sp)
  sw    $t7, 0x18($sp)
  sw    $t9, 0x10($sp)
  sw    $t8, 0x24($sp)
  move  $a0, $s0
  li    $a1, 270
  lw    $a2, 0x4c($sp)
  move  $a3, $v0
  sw    $zero, 0x14($sp)
  sw    $zero, 0x1c($sp)
  jal   sub_GAME_7F0A9398
   sw    $zero, 0x20($sp)
  b     .L7F0AA4C0
   move  $s0, $v0
.L7F0AA2EC:
  jal   get_controller_buttons_held
   li    $a1, 15
  addiu $t2, $v0, -1
  and   $t3, $v0, $t2
  bnez  $t3, .L7F0AA450
   lui   $t0, %hi(pPlayer)
  move  $a0, $zero
  jal   get_controller_buttons_held
   li    $a1, 8
  beqz  $v0, .L7F0AA364
   move  $a0, $zero
  lui   $t4, %hi(pPlayer) 
  lw    $t4, %lo(pPlayer)($t4)
  lui   $t0, %hi(D_800409DC+12)
  li    $at, 44037
  lw    $t5, 0x2a58($t4)
  lw    $a3, 0xac($sp)
  sll   $t6, $t5, 2
  addu  $t6, $t6, $t5
  sll   $t6, $t6, 2
  addu  $t0, $t0, $t6
  lhu   $t0, %lo(D_800409DC+12)($t0)
  bne   $t0, $at, .L7F0AA35C
   nop   
  jal   get_textptr_for_textID
   li    $a0, 44080
  b     .L7F0AA35C
   move  $a3, $v0
.L7F0AA35C:
  b     .L7F0AA3FC
   sw    $a3, 0x5c($sp)
.L7F0AA364:
  jal   get_controller_buttons_held
   li    $a1, 4
  beqz  $v0, .L7F0AA3C0
   move  $a0, $zero
  lui   $t9, %hi(pPlayer) 
  lw    $t9, %lo(pPlayer)($t9)
  lui   $t1, %hi(D_800409DC+12)
  li    $at, 44037
  lw    $t7, 0x2a58($t9)
  lw    $a3, 0xa8($sp)
  sll   $t8, $t7, 2
  addu  $t8, $t8, $t7
  sll   $t8, $t8, 2
  addu  $t1, $t1, $t8
  lhu   $t1, %lo(D_800409DC+12)($t1)
  bne   $t1, $at, .L7F0AA3B8
   nop   
  jal   get_textptr_for_textID
   li    $a0, 44081
  b     .L7F0AA3B8
   move  $a3, $v0
.L7F0AA3B8:
  b     .L7F0AA3FC
   sw    $a3, 0x5c($sp)
.L7F0AA3C0:
  jal   get_controller_buttons_held
   li    $a1, 2
  beqz  $v0, .L7F0AA3E0
   move  $a0, $zero
  jal   get_textptr_for_textID
   li    $a0, 44079
  b     .L7F0AA3FC
   sw    $v0, 0x5c($sp)
.L7F0AA3E0:
  jal   get_controller_buttons_held
   li    $a1, 1
  beql  $v0, $zero, .L7F0AA400
   lui   $t4, 0x70
  jal   get_textptr_for_textID
   li    $a0, 44078
  sw    $v0, 0x5c($sp)
.L7F0AA3FC:
  lui   $t4, (0x007000A0 >> 16) # lui $t4, 0x70
.L7F0AA400:
  lui   $t5, (0x003000B0 >> 16) # lui $t5, 0x30
  ori   $t5, (0x003000B0 & 0xFFFF) # ori $t5, $t5, 0xb0
  ori   $t4, (0x007000A0 & 0xFFFF) # ori $t4, $t4, 0xa0
  li    $t2, -1
  li    $t3, 1
  li    $t6, 1
  lw    $a3, 0x5c($sp)
  sw    $t6, 0x28($sp)
  sw    $t3, 0x14($sp)
  sw    $t2, 0x10($sp)
  sw    $t4, 0x18($sp)
  sw    $t5, 0x24($sp)
  move  $a0, $s0
  li    $a1, 270
  lw    $a2, 0x4c($sp)
  sw    $zero, 0x1c($sp)
  jal   sub_GAME_7F0A9398
   sw    $zero, 0x20($sp)
  b     .L7F0AA4C0
   move  $s0, $v0
.L7F0AA450:
  lw    $t0, %lo(pPlayer)($t0)
  lui   $a0, %hi(D_800409DC+12)
  lw    $t9, 0x2a58($t0)
  sll   $t7, $t9, 2
  addu  $t7, $t7, $t9
  sll   $t7, $t7, 2
  addu  $a0, $a0, $t7
  jal   get_textptr_for_textID
   lhu   $a0, %lo(D_800409DC+12)($a0)
  lui   $t8, (0x00AA00B0 >> 16) # lui $t8, 0xaa
  lui   $t2, (0x003000B0 >> 16) # lui $t2, 0x30
  ori   $t2, (0x003000B0 & 0xFFFF) # ori $t2, $t2, 0xb0
  ori   $t8, (0x00AA00B0 & 0xFFFF) # ori $t8, $t8, 0xb0
  li    $t1, -1
  li    $t3, 1
  sw    $t3, 0x28($sp)
  sw    $t1, 0x18($sp)
  sw    $t8, 0x10($sp)
  sw    $t2, 0x24($sp)
  move  $a0, $s0
  li    $a1, 270
  lw    $a2, 0x4c($sp)
  move  $a3, $v0
  sw    $zero, 0x14($sp)
  sw    $zero, 0x1c($sp)
  jal   sub_GAME_7F0A9398
   sw    $zero, 0x20($sp)
  move  $s0, $v0
.L7F0AA4C0:
  lw    $t4, 0x4c($sp)
  move  $a0, $zero
  li    $a1, 16384
  addiu $t5, $t4, 0x19
  jal   get_controller_buttons_held
   sw    $t5, 0x4c($sp)
  beqz  $v0, .L7F0AA55C
   lui   $t4, %hi(pPlayer) 
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  lui   $a0, %hi(D_800409DC+4)
  lw    $t0, 0x2a58($t6)
  sll   $t9, $t0, 2
  addu  $t9, $t9, $t0
  sll   $t9, $t9, 2
  addu  $a0, $a0, $t9
  jal   get_textptr_for_textID
   lhu   $a0, %lo(D_800409DC+4)($a0)
  lui   $t1, (0x007000A0 >> 16) # lui $t1, 0x70
  lui   $t2, (0x003000B0 >> 16) # lui $t2, 0x30
  ori   $t2, (0x003000B0 & 0xFFFF) # ori $t2, $t2, 0xb0
  ori   $t1, (0x007000A0 & 0xFFFF) # ori $t1, $t1, 0xa0
  li    $t7, -1
  li    $t8, 1
  li    $t3, 1
  sw    $t3, 0x28($sp)
  sw    $t8, 0x14($sp)
  sw    $t7, 0x10($sp)
  sw    $t1, 0x18($sp)
  sw    $t2, 0x24($sp)
  move  $a0, $s0
  li    $a1, 270
  lw    $a2, 0x4c($sp)
  move  $a3, $v0
  sw    $zero, 0x1c($sp)
  jal   sub_GAME_7F0A9398
   sw    $zero, 0x20($sp)
  b     .L7F0AA5CC
   move  $s0, $v0
.L7F0AA55C:
  lw    $t4, %lo(pPlayer)($t4)
  lui   $a0, %hi(D_800409DC+4)
  lw    $t5, 0x2a58($t4)
  sll   $t6, $t5, 2
  addu  $t6, $t6, $t5
  sll   $t6, $t6, 2
  addu  $a0, $a0, $t6
  jal   get_textptr_for_textID
   lhu   $a0, %lo(D_800409DC+4)($a0)
  lui   $t0, (0x00AA00B0 >> 16) # lui $t0, 0xaa
  lui   $t7, (0x003000B0 >> 16) # lui $t7, 0x30
  ori   $t7, (0x003000B0 & 0xFFFF) # ori $t7, $t7, 0xb0
  ori   $t0, (0x00AA00B0 & 0xFFFF) # ori $t0, $t0, 0xb0
  li    $t9, -1
  li    $t8, 1
  sw    $t8, 0x28($sp)
  sw    $t9, 0x18($sp)
  sw    $t0, 0x10($sp)
  sw    $t7, 0x24($sp)
  move  $a0, $s0
  li    $a1, 270
  lw    $a2, 0x4c($sp)
  move  $a3, $v0
  sw    $zero, 0x14($sp)
  sw    $zero, 0x1c($sp)
  jal   sub_GAME_7F0A9398
   sw    $zero, 0x20($sp)
  move  $s0, $v0
.L7F0AA5CC:
  lw    $t1, 0x4c($sp)
  move  $a0, $zero
  li    $a1, 32768
  addiu $t2, $t1, 0x19
  jal   get_controller_buttons_held
   sw    $t2, 0x4c($sp)
  beqz  $v0, .L7F0AA668
   lui   $t1, %hi(pPlayer) 
  lui   $t3, %hi(pPlayer) 
  lw    $t3, %lo(pPlayer)($t3)
  lui   $a0, %hi(D_800409DC+2)
  lw    $t4, 0x2a58($t3)
  sll   $t5, $t4, 2
  addu  $t5, $t5, $t4
  sll   $t5, $t5, 2
  addu  $a0, $a0, $t5
  jal   get_textptr_for_textID
   lhu   $a0, %lo(D_800409DC+2)($a0)
  lui   $t9, (0x007000A0 >> 16) # lui $t9, 0x70
  lui   $t7, (0x003000B0 >> 16) # lui $t7, 0x30
  ori   $t7, (0x003000B0 & 0xFFFF) # ori $t7, $t7, 0xb0
  ori   $t9, (0x007000A0 & 0xFFFF) # ori $t9, $t9, 0xa0
  li    $t6, -1
  li    $t0, 1
  li    $t8, 1
  sw    $t8, 0x28($sp)
  sw    $t0, 0x14($sp)
  sw    $t6, 0x10($sp)
  sw    $t9, 0x18($sp)
  sw    $t7, 0x24($sp)
  move  $a0, $s0
  li    $a1, 270
  lw    $a2, 0x4c($sp)
  move  $a3, $v0
  sw    $zero, 0x1c($sp)
  jal   sub_GAME_7F0A9398
   sw    $zero, 0x20($sp)
  b     .L7F0AA6D8
   move  $s0, $v0
.L7F0AA668:
  lw    $t1, %lo(pPlayer)($t1)
  lui   $a0, %hi(D_800409DC+2)
  lw    $t2, 0x2a58($t1)
  sll   $t3, $t2, 2
  addu  $t3, $t3, $t2
  sll   $t3, $t3, 2
  addu  $a0, $a0, $t3
  jal   get_textptr_for_textID
   lhu   $a0, %lo(D_800409DC+2)($a0)
  lui   $t4, (0x00AA00B0 >> 16) # lui $t4, 0xaa
  lui   $t6, (0x003000B0 >> 16) # lui $t6, 0x30
  ori   $t6, (0x003000B0 & 0xFFFF) # ori $t6, $t6, 0xb0
  ori   $t4, (0x00AA00B0 & 0xFFFF) # ori $t4, $t4, 0xb0
  li    $t5, -1
  li    $t0, 1
  sw    $t0, 0x28($sp)
  sw    $t5, 0x18($sp)
  sw    $t4, 0x10($sp)
  sw    $t6, 0x24($sp)
  move  $a0, $s0
  li    $a1, 270
  lw    $a2, 0x4c($sp)
  move  $a3, $v0
  sw    $zero, 0x14($sp)
  sw    $zero, 0x1c($sp)
  jal   sub_GAME_7F0A9398
   sw    $zero, 0x20($sp)
  move  $s0, $v0
.L7F0AA6D8:
  lw    $t9, 0x50($sp)
  lui   $t4, %hi(pPlayer) 
  beqz  $t9, .L7F0AA744
   nop   
  jal   get_textptr_for_textID
   li    $a0, 44040
  lui   $t1, (0x007000A0 >> 16) # lui $t1, 0x70
  lui   $t2, (0x003000B0 >> 16) # lui $t2, 0x30
  ori   $t2, (0x003000B0 & 0xFFFF) # ori $t2, $t2, 0xb0
  ori   $t1, (0x007000A0 & 0xFFFF) # ori $t1, $t1, 0xa0
  li    $t7, -1
  li    $t8, 1
  li    $t3, 1
  sw    $t3, 0x28($sp)
  sw    $t8, 0x14($sp)
  sw    $t7, 0x10($sp)
  sw    $t1, 0x18($sp)
  sw    $t2, 0x24($sp)
  move  $a0, $s0
  li    $a1, 250
  li    $a2, 195
  move  $a3, $v0
  sw    $zero, 0x1c($sp)
  jal   sub_GAME_7F0A9398
   sw    $zero, 0x20($sp)
  b     .L7F0AA7B4
   move  $s0, $v0
.L7F0AA744:
  lw    $t4, %lo(pPlayer)($t4)
  lui   $a0, %hi(D_800409DC+18)
  lw    $t5, 0x2a58($t4)
  sll   $t6, $t5, 2
  addu  $t6, $t6, $t5
  sll   $t6, $t6, 2
  addu  $a0, $a0, $t6
  jal   get_textptr_for_textID
   lhu   $a0, %lo(D_800409DC+18)($a0)
  lui   $t0, (0x00AA00B0 >> 16) # lui $t0, 0xaa
  lui   $t7, (0x003000B0 >> 16) # lui $t7, 0x30
  ori   $t7, (0x003000B0 & 0xFFFF) # ori $t7, $t7, 0xb0
  ori   $t0, (0x00AA00B0 & 0xFFFF) # ori $t0, $t0, 0xb0
  li    $t9, -1
  li    $t8, 1
  sw    $t8, 0x28($sp)
  sw    $t9, 0x18($sp)
  sw    $t0, 0x10($sp)
  sw    $t7, 0x24($sp)
  move  $a0, $s0
  li    $a1, 250
  li    $a2, 195
  move  $a3, $v0
  sw    $zero, 0x14($sp)
  sw    $zero, 0x1c($sp)
  jal   sub_GAME_7F0A9398
   sw    $zero, 0x20($sp)
  move  $s0, $v0
.L7F0AA7B4:
  lw    $ra, 0x3c($sp)
  move  $v0, $s0
  lw    $s0, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0xb0
");

asm(R"
glabel sub_GAME_7F0AA7C8
  addiu $sp, $sp, -0x48
  sw    $ra, 0x3c($sp)
  jal   microcode_constructor
   sw    $s0, 0x38($sp)
  move  $s0, $v0
  move  $a0, $zero
  jal   get_controller_buttons_held
   li    $a1, 32768
  beqz  $v0, .L7F0AA848
   nop   
  jal   get_textptr_for_textID
   li    $a0, 44035
  lui   $t8, (0x007000A0 >> 16) # lui $t8, 0x70
  lui   $t9, (0x003000B0 >> 16) # lui $t9, 0x30
  ori   $t9, (0x003000B0 & 0xFFFF) # ori $t9, $t9, 0xb0
  ori   $t8, (0x007000A0 & 0xFFFF) # ori $t8, $t8, 0xa0
  li    $t6, -1
  li    $t7, 1
  sw    $t7, 0x14($sp)
  sw    $t6, 0x10($sp)
  sw    $t8, 0x18($sp)
  sw    $t9, 0x24($sp)
  move  $a0, $s0
  li    $a1, 90
  li    $a2, 167
  move  $a3, $v0
  sw    $zero, 0x1c($sp)
  sw    $zero, 0x20($sp)
  jal   sub_GAME_7F0A9398
   sw    $zero, 0x28($sp)
  b     .L7F0AA898
   move  $s0, $v0
.L7F0AA848:
  jal   get_textptr_for_textID
   li    $a0, 44035
  lui   $t0, (0x00AA00B0 >> 16) # lui $t0, 0xaa
  lui   $t2, (0x003000B0 >> 16) # lui $t2, 0x30
  ori   $t2, (0x003000B0 & 0xFFFF) # ori $t2, $t2, 0xb0
  ori   $t0, (0x00AA00B0 & 0xFFFF) # ori $t0, $t0, 0xb0
  li    $t1, -1
  sw    $t1, 0x18($sp)
  sw    $t0, 0x10($sp)
  sw    $t2, 0x24($sp)
  move  $a0, $s0
  li    $a1, 90
  li    $a2, 167
  move  $a3, $v0
  sw    $zero, 0x14($sp)
  sw    $zero, 0x1c($sp)
  sw    $zero, 0x20($sp)
  jal   sub_GAME_7F0A9398
   sw    $zero, 0x28($sp)
  move  $s0, $v0
.L7F0AA898:
  move  $a0, $zero
  jal   get_controller_buttons_held
   li    $a1, 16384
  beqz  $v0, .L7F0AA904
   nop   
  jal   get_textptr_for_textID
   li    $a0, 44034
  lui   $t5, (0x007000A0 >> 16) # lui $t5, 0x70
  lui   $t6, (0x003000B0 >> 16) # lui $t6, 0x30
  ori   $t6, (0x003000B0 & 0xFFFF) # ori $t6, $t6, 0xb0
  ori   $t5, (0x007000A0 & 0xFFFF) # ori $t5, $t5, 0xa0
  li    $t3, -1
  li    $t4, 1
  sw    $t4, 0x14($sp)
  sw    $t3, 0x10($sp)
  sw    $t5, 0x18($sp)
  sw    $t6, 0x24($sp)
  move  $a0, $s0
  li    $a1, 90
  li    $a2, 149
  move  $a3, $v0
  sw    $zero, 0x1c($sp)
  sw    $zero, 0x20($sp)
  jal   sub_GAME_7F0A9398
   sw    $zero, 0x28($sp)
  b     .L7F0AA954
   move  $s0, $v0
.L7F0AA904:
  jal   get_textptr_for_textID
   li    $a0, 44034
  lui   $t7, (0x00AA00B0 >> 16) # lui $t7, 0xaa
  lui   $t9, (0x003000B0 >> 16) # lui $t9, 0x30
  ori   $t9, (0x003000B0 & 0xFFFF) # ori $t9, $t9, 0xb0
  ori   $t7, (0x00AA00B0 & 0xFFFF) # ori $t7, $t7, 0xb0
  li    $t8, -1
  sw    $t8, 0x18($sp)
  sw    $t7, 0x10($sp)
  sw    $t9, 0x24($sp)
  move  $a0, $s0
  li    $a1, 90
  li    $a2, 149
  move  $a3, $v0
  sw    $zero, 0x14($sp)
  sw    $zero, 0x1c($sp)
  sw    $zero, 0x20($sp)
  jal   sub_GAME_7F0A9398
   sw    $zero, 0x28($sp)
  move  $s0, $v0
.L7F0AA954:
  lui   $t0, %hi(pPlayer) 
  lw    $t0, %lo(pPlayer)($t0)
  li    $at, 4
  lw    $v0, 0x2a58($t0)
  beq   $v0, $at, .L7F0AA974
   li    $at, 5
  bne   $v0, $at, .L7F0AA984
   nop   
.L7F0AA974:
  jal   get_textptr_for_textID
   li    $a0, 44032
  b     .L7F0AA990
   move  $a3, $v0
.L7F0AA984:
  jal   get_textptr_for_textID
   li    $a0, 44033
  move  $a3, $v0
.L7F0AA990:
  move  $a0, $zero
  li    $a1, 8192
  jal   get_controller_buttons_held
   sw    $a3, 0x44($sp)
  beqz  $v0, .L7F0AA9F4
   lw    $a3, 0x44($sp)
  lui   $t3, (0x007000A0 >> 16) # lui $t3, 0x70
  lui   $t4, (0x003000B0 >> 16) # lui $t4, 0x30
  ori   $t4, (0x003000B0 & 0xFFFF) # ori $t4, $t4, 0xb0
  ori   $t3, (0x007000A0 & 0xFFFF) # ori $t3, $t3, 0xa0
  li    $t1, -1
  li    $t2, 1
  sw    $t2, 0x14($sp)
  sw    $t1, 0x10($sp)
  sw    $t3, 0x18($sp)
  sw    $t4, 0x24($sp)
  move  $a0, $s0
  li    $a1, 90
  li    $a2, 185
  sw    $zero, 0x1c($sp)
  sw    $zero, 0x20($sp)
  jal   sub_GAME_7F0A9398
   sw    $zero, 0x28($sp)
  b     .L7F0AAA38
   move  $s0, $v0
.L7F0AA9F4:
  lui   $t5, (0x00AA00B0 >> 16) # lui $t5, 0xaa
  lui   $t7, (0x003000B0 >> 16) # lui $t7, 0x30
  ori   $t7, (0x003000B0 & 0xFFFF) # ori $t7, $t7, 0xb0
  ori   $t5, (0x00AA00B0 & 0xFFFF) # ori $t5, $t5, 0xb0
  li    $t6, -1
  sw    $t6, 0x18($sp)
  sw    $t5, 0x10($sp)
  sw    $t7, 0x24($sp)
  move  $a0, $s0
  li    $a1, 90
  li    $a2, 185
  sw    $zero, 0x14($sp)
  sw    $zero, 0x1c($sp)
  sw    $zero, 0x20($sp)
  jal   sub_GAME_7F0A9398
   sw    $zero, 0x28($sp)
  move  $s0, $v0
.L7F0AAA38:
  lui   $t8, %hi(pPlayer) 
  lw    $t8, %lo(pPlayer)($t8)
  li    $at, 4
  lw    $v0, 0x2a58($t8)
  beq   $v0, $at, .L7F0AAA58
   li    $at, 6
  bne   $v0, $at, .L7F0AAA68
   nop   
.L7F0AAA58:
  jal   get_textptr_for_textID
   li    $a0, 44037
  b     .L7F0AAA74
   move  $a3, $v0
.L7F0AAA68:
  jal   get_textptr_for_textID
   li    $a0, 44038
  move  $a3, $v0
.L7F0AAA74:
  lui   $t9, (0x00AA00B0 >> 16) # lui $t9, 0xaa
  lui   $t1, (0x003000B0 >> 16) # lui $t1, 0x30
  ori   $t1, (0x003000B0 & 0xFFFF) # ori $t1, $t1, 0xb0
  ori   $t9, (0x00AA00B0 & 0xFFFF) # ori $t9, $t9, 0xb0
  li    $t0, -1
  sw    $t0, 0x18($sp)
  sw    $t9, 0x10($sp)
  sw    $t1, 0x24($sp)
  move  $a0, $s0
  li    $a1, 90
  li    $a2, 203
  sw    $zero, 0x14($sp)
  sw    $zero, 0x1c($sp)
  sw    $zero, 0x20($sp)
  jal   sub_GAME_7F0A9398
   sw    $zero, 0x28($sp)
  move  $s0, $v0
  li    $a0, 1
  jal   get_controller_buttons_held
   li    $a1, 32768
  beqz  $v0, .L7F0AAB28
   nop   
  jal   get_textptr_for_textID
   li    $a0, 44035
  lui   $t4, (0x007000A0 >> 16) # lui $t4, 0x70
  lui   $t5, (0x003000B0 >> 16) # lui $t5, 0x30
  ori   $t5, (0x003000B0 & 0xFFFF) # ori $t5, $t5, 0xb0
  ori   $t4, (0x007000A0 & 0xFFFF) # ori $t4, $t4, 0xa0
  li    $t2, -1
  li    $t3, 1
  li    $t6, 1
  sw    $t6, 0x28($sp)
  sw    $t3, 0x14($sp)
  sw    $t2, 0x10($sp)
  sw    $t4, 0x18($sp)
  sw    $t5, 0x24($sp)
  move  $a0, $s0
  li    $a1, 230
  li    $a2, 167
  move  $a3, $v0
  sw    $zero, 0x1c($sp)
  jal   sub_GAME_7F0A9398
   sw    $zero, 0x20($sp)
  b     .L7F0AAB7C
   move  $s0, $v0
.L7F0AAB28:
  jal   get_textptr_for_textID
   li    $a0, 44035
  lui   $t7, (0x00AA00B0 >> 16) # lui $t7, 0xaa
  lui   $t9, (0x003000B0 >> 16) # lui $t9, 0x30
  ori   $t9, (0x003000B0 & 0xFFFF) # ori $t9, $t9, 0xb0
  ori   $t7, (0x00AA00B0 & 0xFFFF) # ori $t7, $t7, 0xb0
  li    $t8, -1
  li    $t0, 1
  sw    $t0, 0x28($sp)
  sw    $t8, 0x18($sp)
  sw    $t7, 0x10($sp)
  sw    $t9, 0x24($sp)
  move  $a0, $s0
  li    $a1, 230
  li    $a2, 167
  move  $a3, $v0
  sw    $zero, 0x14($sp)
  sw    $zero, 0x1c($sp)
  jal   sub_GAME_7F0A9398
   sw    $zero, 0x20($sp)
  move  $s0, $v0
.L7F0AAB7C:
  li    $a0, 1
  jal   get_controller_buttons_held
   li    $a1, 16384
  beqz  $v0, .L7F0AABEC
   nop   
  jal   get_textptr_for_textID
   li    $a0, 44034
  lui   $t3, (0x007000A0 >> 16) # lui $t3, 0x70
  lui   $t4, (0x003000B0 >> 16) # lui $t4, 0x30
  ori   $t4, (0x003000B0 & 0xFFFF) # ori $t4, $t4, 0xb0
  ori   $t3, (0x007000A0 & 0xFFFF) # ori $t3, $t3, 0xa0
  li    $t1, -1
  li    $t2, 1
  li    $t5, 1
  sw    $t5, 0x28($sp)
  sw    $t2, 0x14($sp)
  sw    $t1, 0x10($sp)
  sw    $t3, 0x18($sp)
  sw    $t4, 0x24($sp)
  move  $a0, $s0
  li    $a1, 230
  li    $a2, 149
  move  $a3, $v0
  sw    $zero, 0x1c($sp)
  jal   sub_GAME_7F0A9398
   sw    $zero, 0x20($sp)
  b     .L7F0AAC40
   move  $s0, $v0
.L7F0AABEC:
  jal   get_textptr_for_textID
   li    $a0, 44034
  lui   $t6, (0x00AA00B0 >> 16) # lui $t6, 0xaa
  lui   $t8, (0x003000B0 >> 16) # lui $t8, 0x30
  ori   $t8, (0x003000B0 & 0xFFFF) # ori $t8, $t8, 0xb0
  ori   $t6, (0x00AA00B0 & 0xFFFF) # ori $t6, $t6, 0xb0
  li    $t7, -1
  li    $t9, 1
  sw    $t9, 0x28($sp)
  sw    $t7, 0x18($sp)
  sw    $t6, 0x10($sp)
  sw    $t8, 0x24($sp)
  move  $a0, $s0
  li    $a1, 230
  li    $a2, 149
  move  $a3, $v0
  sw    $zero, 0x14($sp)
  sw    $zero, 0x1c($sp)
  jal   sub_GAME_7F0A9398
   sw    $zero, 0x20($sp)
  move  $s0, $v0
.L7F0AAC40:
  lui   $t0, %hi(pPlayer) 
  lw    $t0, %lo(pPlayer)($t0)
  li    $at, 4
  lw    $v0, 0x2a58($t0)
  beq   $v0, $at, .L7F0AAC60
   li    $at, 5
  bne   $v0, $at, .L7F0AAC70
   nop   
.L7F0AAC60:
  jal   get_textptr_for_textID
   li    $a0, 44033
  b     .L7F0AAC7C
   move  $a3, $v0
.L7F0AAC70:
  jal   get_textptr_for_textID
   li    $a0, 44032
  move  $a3, $v0
.L7F0AAC7C:
  li    $a0, 1
  li    $a1, 8192
  jal   get_controller_buttons_held
   sw    $a3, 0x44($sp)
  beqz  $v0, .L7F0AACE4
   lw    $a3, 0x44($sp)
  lui   $t3, (0x007000A0 >> 16) # lui $t3, 0x70
  lui   $t4, (0x003000B0 >> 16) # lui $t4, 0x30
  ori   $t4, (0x003000B0 & 0xFFFF) # ori $t4, $t4, 0xb0
  ori   $t3, (0x007000A0 & 0xFFFF) # ori $t3, $t3, 0xa0
  li    $t1, -1
  li    $t2, 1
  li    $t5, 1
  sw    $t5, 0x28($sp)
  sw    $t2, 0x14($sp)
  sw    $t1, 0x10($sp)
  sw    $t3, 0x18($sp)
  sw    $t4, 0x24($sp)
  move  $a0, $s0
  li    $a1, 230
  li    $a2, 185
  sw    $zero, 0x1c($sp)
  jal   sub_GAME_7F0A9398
   sw    $zero, 0x20($sp)
  b     .L7F0AAD2C
   move  $s0, $v0
.L7F0AACE4:
  lui   $t6, (0x00AA00B0 >> 16) # lui $t6, 0xaa
  lui   $t8, (0x003000B0 >> 16) # lui $t8, 0x30
  ori   $t8, (0x003000B0 & 0xFFFF) # ori $t8, $t8, 0xb0
  ori   $t6, (0x00AA00B0 & 0xFFFF) # ori $t6, $t6, 0xb0
  li    $t7, -1
  li    $t9, 1
  sw    $t9, 0x28($sp)
  sw    $t7, 0x18($sp)
  sw    $t6, 0x10($sp)
  sw    $t8, 0x24($sp)
  move  $a0, $s0
  li    $a1, 230
  li    $a2, 185
  sw    $zero, 0x14($sp)
  sw    $zero, 0x1c($sp)
  jal   sub_GAME_7F0A9398
   sw    $zero, 0x20($sp)
  move  $s0, $v0
.L7F0AAD2C:
  lui   $t0, %hi(pPlayer) 
  lw    $t0, %lo(pPlayer)($t0)
  li    $at, 4
  lw    $v0, 0x2a58($t0)
  beq   $v0, $at, .L7F0AAD4C
   li    $at, 6
  bne   $v0, $at, .L7F0AAD5C
   nop   
.L7F0AAD4C:
  jal   get_textptr_for_textID
   li    $a0, 44038
  b     .L7F0AAD68
   move  $a3, $v0
.L7F0AAD5C:
  jal   get_textptr_for_textID
   li    $a0, 44037
  move  $a3, $v0
.L7F0AAD68:
  lui   $t1, (0x00AA00B0 >> 16) # lui $t1, 0xaa
  lui   $t3, (0x003000B0 >> 16) # lui $t3, 0x30
  ori   $t3, (0x003000B0 & 0xFFFF) # ori $t3, $t3, 0xb0
  ori   $t1, (0x00AA00B0 & 0xFFFF) # ori $t1, $t1, 0xb0
  li    $t2, -1
  li    $t4, 1
  sw    $t4, 0x28($sp)
  sw    $t2, 0x18($sp)
  sw    $t1, 0x10($sp)
  sw    $t3, 0x24($sp)
  move  $a0, $s0
  li    $a1, 230
  li    $a2, 203
  sw    $zero, 0x14($sp)
  sw    $zero, 0x1c($sp)
  jal   sub_GAME_7F0A9398
   sw    $zero, 0x20($sp)
  lw    $ra, 0x3c($sp)
  lw    $s0, 0x38($sp)
  addiu $sp, $sp, 0x48
  jr    $ra
   nop   
");

#ifdef VERSION_US
asm(R"
.late_rodata
glabel D_80058550
.word 0x40c90fdb /*6.2831855*/
glabel D_80058554
.word 0x3f490fdb /*0.78539819*/
glabel D_80058558
.word 0x43f78000 /*495.0*/
glabel D_8005855C
.word 0x453b8000  /*3000.0*/
glabel D_80058560
.word 0x40c90fdb /*6.2831855*/
glabel D_80058564
.word 0x3f490fdb /*0.78539819*/
glabel D_80058568
.word 0xc3fc8000 /*-505.0*/
glabel D_8005856C
.word 0x453b8000  /*3000.0*/
.text
glabel sub_GAME_7F0AADC0
  addiu $sp, $sp, -0x540
  sw    $ra, 0x34($sp)
  sw    $s0, 0x30($sp)
  jal   sub_GAME_7F0BD6E0
   move  $s0, $a0
  lui   $t7, %hi(D_80040B5C) 
  sw    $v0, 0x53c($sp)
  addiu $t7, %lo(D_80040B5C) # addiu $t7, $t7, 0xb5c
  lw    $at, ($t7)
  addiu $t6, $sp, 0x370
  lw    $t0, 4($t7)
  sw    $at, ($t6)
  lw    $at, 8($t7)
  lui   $t3, %hi(D_80040B68) 
  sw    $t0, 4($t6)
  sw    $at, 8($t6)
  li    $t1, 1
  addiu $t3, %lo(D_80040B68) # addiu $t3, $t3, 0xb68
  sb    $zero, 0x2e3($sp)
  sb    $t1, 0x2e2($sp)
  addiu $t9, $t3, 0xd8
  addiu $t2, $sp, 0x204
.L7F0AAE18:
  lw    $at, ($t3)
  addiu $t3, $t3, 0xc
  addiu $t2, $t2, 0xc
  sw    $at, -0xc($t2)
  lw    $at, -8($t3)
  sw    $at, -8($t2)
  lw    $at, -4($t3)
  bne   $t3, $t9, .L7F0AAE18
   sw    $at, -4($t2)
  lw    $at, ($t3)
  lui   $t6, %hi(D_80040BB4+0x90) 
  addiu $t6, %lo(D_80040BB4+0x90) # addiu $t6, $t6, 0xc44
  addiu $t1, $t6, 0xd8
  addiu $t8, $sp, 0x128
  sw    $at, ($t2)
.L7F0AAE54:
  lw    $at, ($t6)
  addiu $t6, $t6, 0xc
  addiu $t8, $t8, 0xc
  sw    $at, -0xc($t8)
  lw    $at, -8($t6)
  sw    $at, -8($t8)
  lw    $at, -4($t6)
  bne   $t6, $t1, .L7F0AAE54
   sw    $at, -4($t8)
  lw    $at, ($t6)
  lui   $t4, %hi(D_80040D20) 
  addiu $t4, %lo(D_80040D20) # addiu $t4, $t4, 0xd20
  addiu $t2, $t4, 0xd8
  addiu $t5, $sp, 0x4c
  sw    $at, ($t8)
.L7F0AAE90:
  lw    $at, ($t4)
  addiu $t4, $t4, 0xc
  addiu $t5, $t5, 0xc
  sw    $at, -0xc($t5)
  lw    $at, -8($t4)
  sw    $at, -8($t5)
  lw    $at, -4($t4)
  bne   $t4, $t2, .L7F0AAE90
   sw    $at, -4($t5)
  lw    $at, ($t4)
  lui   $a1, %hi(D_80040B2C)
  lui   $a2, %hi(D_80040B28)
  lui   $a3, %hi(D_80040B24)
  addiu $a3, %lo(D_80040B24) # addiu $a3, $a3, 0xb24
  addiu $a2, %lo(D_80040B28) # addiu $a2, $a2, 0xb28
  addiu $a1, %lo(D_80040B2C) # addiu $a1, $a1, 0xb2c
  move  $a0, $zero
  jal   sub_GAME_7F0A9684
   sw    $at, ($t5)
  jal   matrix_4x4_set_identity
   addiu $a0, $sp, 0x4fc
  lui   $t0, %hi(D_80048498) 
  lw    $t0, %lo(D_80048498)($t0)
  lui   $at, %hi(D_80040B28)
  lwc1  $f4, %lo(D_80040B28)($at)
  mtc1  $t0, $f6
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f16
  cvt.s.w $f8, $f6
  lui   $v0, %hi(D_80040B24)
  addiu $v0, %lo(D_80040B24) # addiu $v0, $v0, 0xb24
  lwc1  $f6, ($v0)
  mul.s $f10, $f4, $f8
  nop   
  mul.s $f18, $f10, $f16
  add.s $f4, $f6, $f18
  swc1  $f4, ($v0)
  jal   sub_GAME_7F0A6A2C
   lwc1  $f12, ($v0)
  lui   $at, %hi(D_80040B24)
  swc1  $f0, %lo(D_80040B24)($at)
  lwc1  $f12, %lo(D_80040B24)($at)
  jal   sub_GAME_7F058688
   addiu $a1, $sp, 0x4bc
  lui   $t7, %hi(watch_soundrelated_maybe) 
  lw    $t7, %lo(watch_soundrelated_maybe)($t7)
  beqz  $t7, .L7F0AAFA4
   lui   $t1, %hi(D_80040998) 
  lw    $t1, %lo(D_80040998)($t1)
  li    $at, 1
  bne   $t1, $at, .L7F0AAFA4
   nop   
  jal   get_cur_controller_vert_stick_pos
   move  $a0, $zero
  mtc1  $v0, $f8
  lui   $at, %hi(D_80040B20)
  lwc1  $f12, %lo(D_80040B20)($at)
  cvt.s.w $f10, $f8
  lui   $at, %hi(D_80058550)
  lwc1  $f16, %lo(D_80058550)($at)
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f18
  lui   $a2, 0x4080
  mul.s $f6, $f10, $f16
  jal   sub_GAME_7F0A95C4
   div.s $f14, $f6, $f18
  lui   $at, %hi(D_80040B20)
  b     .L7F0AAFC0
   swc1  $f0, %lo(D_80040B20)($at)
.L7F0AAFA4:
  lui   $at, %hi(D_80040B20)
  mtc1  $zero, $f14
  lwc1  $f12, %lo(D_80040B20)($at)
  jal   sub_GAME_7F0A95C4
   lui   $a2, 0x4080
  lui   $at, %hi(D_80040B20)
  swc1  $f0, %lo(D_80040B20)($at)
.L7F0AAFC0:
  lui   $at, %hi(D_80040B20)
  lwc1  $f4, %lo(D_80040B20)($at)
  lui   $at, %hi(D_80058554)
  lwc1  $f10, %lo(D_80058554)($at)
  neg.s $f8, $f4
  addiu $a1, $sp, 0x47c
  jal   sub_GAME_7F058570
   sub.s $f12, $f8, $f10
  addiu $a0, $sp, 0x4fc
  addiu $a1, $sp, 0x4bc
  jal   matrix_4x4_multiply
   addiu $a2, $sp, 0x43c
  addiu $a0, $sp, 0x43c
  addiu $a1, $sp, 0x47c
  jal   matrix_4x4_multiply
   addiu $a2, $sp, 0x3fc
  addiu $a0, $sp, 0x370
  jal   init_something_copy_posdata_to_it
   addiu $a1, $sp, 0x43c
  addiu $a0, $sp, 0x43c
  addiu $a1, $sp, 0x3fc
  jal   matrix_4x4_multiply
   addiu $a2, $sp, 0x3bc
  jal   controllerCheckDualControllerTypesAllowed
   nop   
  beqz  $v0, .L7F0AB088
   lui   $at, 0xc0a0
  lui    $at, %hi(D_80058558)
  lwc1  $f0, %lo(D_80058558)($at)
  li    $at, 0x42000000 # 32.000000
  mtc1  $at, $f12
  mtc1  $zero, $f2
  li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f16
  addiu $t6, $sp, 0x128
  lui   $a2, (0x451C4000 >> 16) # lui $a2, 0x451c
  mfc1  $a1, $f0
  mfc1  $a3, $f12
  sw    $t6, 0x2e8($sp)
  ori   $a2, (0x451C4000 & 0xFFFF) # ori $a2, $a2, 0x4000
  addiu $a0, $sp, 0x32c
  swc1  $f0, 0x10($sp)
  swc1  $f12, 0x18($sp)
  swc1  $f2, 0x14($sp)
  swc1  $f2, 0x1c($sp)
  swc1  $f2, 0x20($sp)
  jal   sub_GAME_7F059694
   swc1  $f16, 0x24($sp)
  b     .L7F0AB0E0
   addiu $a0, $sp, 0x32c
.L7F0AB088:
  mtc1  $at, $f0
  li    $at, 0xC3280000 # -168.000000
  mtc1  $at, $f2
  li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f8
  mtc1  $zero, $f6
  mtc1  $zero, $f18
  mtc1  $zero, $f4
  addiu $t8, $sp, 0x204
  mfc1  $a1, $f0
  mfc1  $a3, $f2
  sw    $t8, 0x2e8($sp)
  addiu $a0, $sp, 0x32c
  lui   $a2, 0x44fa
  swc1  $f0, 0x10($sp)
  swc1  $f2, 0x18($sp)
  swc1  $f8, 0x24($sp)
  swc1  $f6, 0x14($sp)
  swc1  $f18, 0x1c($sp)
  jal   sub_GAME_7F059694
   swc1  $f4, 0x20($sp)
  addiu $a0, $sp, 0x32c
.L7F0AB0E0:
  addiu $a1, $sp, 0x3bc
  jal   matrix_4x4_multiply
   addiu $a2, $sp, 0x37c
  li    $at, 0x447A0000 # 1000.000000
  mtc1  $at, $f10
  lui   $at, %hi(D_8005855C)
  lwc1  $f16, %lo(D_8005855C)($at)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  lui   $a3, (0x3FAAAAAB >> 16) # lui $a3, 0x3faa
  ori   $a3, (0x3FAAAAAB & 0xFFFF) # ori $a3, $a3, 0xaaab
  lw    $a0, 0x53c($sp)
  addiu $a1, $sp, 0x36e
  lui   $a2, 0x424a
  swc1  $f10, 0x10($sp)
  swc1  $f16, 0x14($sp)
  jal   guPerspective
   swc1  $f6, 0x18($sp)
  lui   $t3, (0x01030040 >> 16) # lui $t3, 0x103
  ori   $t3, (0x01030040 & 0xFFFF) # ori $t3, $t3, 0x40
  move  $v1, $s0
  sw    $t3, ($v1)
  sw    $v1, 0x48($sp)
  lw    $a0, 0x53c($sp)
  jal   osVirtualToPhysical
   addiu $s0, $s0, 8
  lw    $v1, 0x48($sp)
  move  $a0, $s0
  jal   sub_GAME_7F0A6EE8
   sw    $v0, 4($v1)
  lui   $v1, %hi(D_80040B04)
  lw    $v1, %lo(D_80040B04)($v1)
  move  $s0, $v0
  move  $a0, $s0
  slti  $at, $v1, 0xe0
  beqz  $at, .L7F0AB1A0
   addiu $a1, $sp, 0x37c
  lw    $t9, 0x2e8($sp)
  addiu $t2, $sp, 0x2e3
  sw    $t2, 0x14($sp)
  move  $a0, $v0
  addiu $a1, $sp, 0x37c
  addiu $a2, $v1, -6
  li    $a3, 1
  jal   sub_GAME_7F06359C
   sw    $t9, 0x10($sp)
  b     .L7F0AB1B8
   move  $s0, $v0
.L7F0AB1A0:
  addiu $t4, $sp, 0x2e3
  sw    $t4, 0x10($sp)
  li    $a2, 1
  jal   sub_GAME_7F064364
   lw    $a3, 0x2e8($sp)
  move  $s0, $v0
.L7F0AB1B8:
  jal   controllerCheckDualControllerTypesAllowed
   nop   
  beqz  $v0, .L7F0AB44C
   li    $a0, 1
  lui   $a1, %hi(D_80040B3C)
  lui   $a2, %hi(D_80040B38)
  lui   $a3, %hi(D_80040B34)
  addiu $a3, %lo(D_80040B34) # addiu $a3, $a3, 0xb34
  addiu $a2, %lo(D_80040B38) # addiu $a2, $a2, 0xb38
  jal   sub_GAME_7F0A9684
   addiu $a1, %lo(D_80040B3C) # addiu $a1, $a1, 0xb3c
  jal   matrix_4x4_set_identity
   addiu $a0, $sp, 0x4fc
  lui   $t5, %hi(D_80048498) 
  lw    $t5, %lo(D_80048498)($t5)
  lui   $at, %hi(D_80040B38)
  lwc1  $f18, %lo(D_80040B38)($at)
  mtc1  $t5, $f4
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f16
  cvt.s.w $f8, $f4
  lui   $v0, %hi(D_80040B34)
  addiu $v0, %lo(D_80040B34) # addiu $v0, $v0, 0xb34
  lwc1  $f4, ($v0)
  mul.s $f10, $f18, $f8
  nop   
  mul.s $f6, $f10, $f16
  add.s $f18, $f4, $f6
  swc1  $f18, ($v0)
  jal   sub_GAME_7F0A6A2C
   lwc1  $f12, ($v0)
  lui   $at, %hi(D_80040B34)
  swc1  $f0, %lo(D_80040B34)($at)
  lwc1  $f12, %lo(D_80040B34)($at)
  jal   sub_GAME_7F058688
   addiu $a1, $sp, 0x4bc
  lui   $t0, %hi(watch_soundrelated_maybe) 
  lw    $t0, %lo(watch_soundrelated_maybe)($t0)
  beqz  $t0, .L7F0AB2AC
   lui   $t7, %hi(D_80040998) 
  lw    $t7, %lo(D_80040998)($t7)
  li    $at, 1
  bne   $t7, $at, .L7F0AB2AC
   nop   
  jal   get_cur_controller_vert_stick_pos
   li    $a0, 1
  mtc1  $v0, $f8
  lui   $at, %hi(D_80040B30)
  lwc1  $f12, %lo(D_80040B30)($at)
  cvt.s.w $f10, $f8
  lui   $at, %hi(D_80058560)
  lwc1  $f16, %lo(D_80058560)($at)
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f6
  lui   $a2, 0x4080
  mul.s $f4, $f10, $f16
  jal   sub_GAME_7F0A95C4
   div.s $f14, $f4, $f6
  lui   $at, %hi(D_80040B30)
  b     .L7F0AB2C8
   swc1  $f0, %lo(D_80040B30)($at)
.L7F0AB2AC:
  lui   $at, %hi(D_80040B30)
  mtc1  $zero, $f14
  lwc1  $f12, %lo(D_80040B30)($at)
  jal   sub_GAME_7F0A95C4
   lui   $a2, 0x4080
  lui   $at, %hi(D_80040B30)
  swc1  $f0, %lo(D_80040B30)($at)
.L7F0AB2C8:
  lui   $at, %hi(D_80040B30)
  lwc1  $f18, %lo(D_80040B30)($at)
  lui   $at, %hi(D_80058564)
  lwc1  $f10, %lo(D_80058564)($at)
  neg.s $f8, $f18
  addiu $a1, $sp, 0x47c
  jal   sub_GAME_7F058570
   sub.s $f12, $f8, $f10
  addiu $a0, $sp, 0x4fc
  addiu $a1, $sp, 0x4bc
  jal   matrix_4x4_multiply
   addiu $a2, $sp, 0x43c
  addiu $a0, $sp, 0x43c
  addiu $a1, $sp, 0x47c
  jal   matrix_4x4_multiply
   addiu $a2, $sp, 0x3fc
  addiu $a0, $sp, 0x370
  jal   init_something_copy_posdata_to_it
   addiu $a1, $sp, 0x43c
  addiu $a0, $sp, 0x43c
  addiu $a1, $sp, 0x3fc
  jal   matrix_4x4_multiply
   addiu $a2, $sp, 0x3bc
  lui   $at, %hi(D_80058568)
  lwc1  $f0, %lo(D_80058568)($at)
  li    $at, 0x42000000 # 32.000000
  mtc1  $zero, $f2
  mtc1  $at, $f16
  li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f4
  lui   $a2, (0x451C4000 >> 16) # lui $a2, 0x451c
  mfc1  $a1, $f0
  ori   $a2, (0x451C4000 & 0xFFFF) # ori $a2, $a2, 0x4000
  addiu $a0, $sp, 0x2ec
  lui   $a3, 0x4200
  swc1  $f0, 0x10($sp)
  swc1  $f2, 0x14($sp)
  swc1  $f2, 0x1c($sp)
  swc1  $f2, 0x20($sp)
  swc1  $f16, 0x18($sp)
  jal   sub_GAME_7F059694
   swc1  $f4, 0x24($sp)
  addiu $a0, $sp, 0x2ec
  addiu $a1, $sp, 0x3bc
  jal   matrix_4x4_multiply
   addiu $a2, $sp, 0x37c
  li    $at, 0x447A0000 # 1000.000000
  mtc1  $at, $f6
  lui   $at, %hi(D_8005856C)
  lwc1  $f18, %lo(D_8005856C)($at)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  lui   $a3, (0x3FAAAAAB >> 16) # lui $a3, 0x3faa
  ori   $a3, (0x3FAAAAAB & 0xFFFF) # ori $a3, $a3, 0xaaab
  lw    $a0, 0x53c($sp)
  addiu $a1, $sp, 0x36e
  lui   $a2, 0x424a
  swc1  $f6, 0x10($sp)
  swc1  $f18, 0x14($sp)
  jal   guPerspective
   swc1  $f8, 0x18($sp)
  lui   $t1, (0x01030040 >> 16) # lui $t1, 0x103
  ori   $t1, (0x01030040 & 0xFFFF) # ori $t1, $t1, 0x40
  move  $v1, $s0
  sw    $t1, ($v1)
  sw    $v1, 0x44($sp)
  lw    $a0, 0x53c($sp)
  jal   osVirtualToPhysical
   addiu $s0, $s0, 8
  lw    $v1, 0x44($sp)
  move  $a0, $s0
  jal   sub_GAME_7F0A6EE8
   sw    $v0, 4($v1)
  lui   $v1, %hi(D_80040B04)
  lw    $v1, %lo(D_80040B04)($v1)
  move  $s0, $v0
  move  $a0, $s0
  slti  $at, $v1, 0xe0
  beqz  $at, .L7F0AB434
   addiu $a1, $sp, 0x37c
  addiu $t6, $sp, 0x4c
  addiu $t8, $sp, 0x2e2
  sw    $t8, 0x14($sp)
  sw    $t6, 0x10($sp)
  move  $a0, $v0
  addiu $a1, $sp, 0x37c
  addiu $a2, $v1, -6
  jal   sub_GAME_7F06359C
   li    $a3, 1
  b     .L7F0AB44C
   move  $s0, $v0
.L7F0AB434:
  addiu $t3, $sp, 0x2e2
  sw    $t3, 0x10($sp)
  li    $a2, 1
  jal   sub_GAME_7F064364
   addiu $a3, $sp, 0x4c
  move  $s0, $v0
.L7F0AB44C:
  jal   controllerCheckDualControllerTypesAllowed
   nop   
  beqz  $v0, .L7F0AB46C
   nop   
  jal   sub_GAME_7F0AA7C8
   move  $a0, $s0
  b     .L7F0AB478
   move  $s0, $v0
.L7F0AB46C:
  jal   sub_GAME_7F0A9AB8
   move  $a0, $s0
  move  $s0, $v0
.L7F0AB478:
  lw    $ra, 0x34($sp)
  move  $v0, $s0
  lw    $s0, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x540
");
#endif

#ifdef VERSION_JP
asm(R"
.late_rodata
glabel D_80058550
.word 0x40c90fdb /*6.2831855*/
glabel D_80058554
.word 0x3f490fdb /*0.78539819*/
glabel D_80058558
.word 0x43f78000 /*495.0*/
glabel D_8005855C
.word 0x453b8000  /*3000.0*/
glabel D_80058560
.word 0x40c90fdb /*6.2831855*/
glabel D_80058564
.word 0x3f490fdb /*0.78539819*/
glabel D_80058568
.word 0xc3fc8000 /*-505.0*/
glabel D_8005856C
.word 0x453b8000  /*3000.0*/
.text
glabel sub_GAME_7F0AADC0
  addiu $sp, $sp, -0x540
  sw    $ra, 0x34($sp)
  sw    $s0, 0x30($sp)
  jal   sub_GAME_7F0BD6E0
   move  $s0, $a0
  lui   $t7, %hi(D_80040B5C) # $t7, 0x8004
  sw    $v0, 0x53c($sp)
  addiu $t7, %lo(D_80040B5C) # addiu $t7, $t7, 0xb8c
  lw    $at, ($t7)
  addiu $t6, $sp, 0x370
  lw    $t0, 4($t7)
  sw    $at, ($t6)
  lw    $at, 8($t7)
  lui   $t3, %hi(D_80040B68) # $t3, 0x8004
  sw    $t0, 4($t6)
  sw    $at, 8($t6)
  li    $t1, 1
  addiu $t3, %lo(D_80040B68) # addiu $t3, $t3, 0xb98
  sb    $zero, 0x2e3($sp)
  sb    $t1, 0x2e2($sp)
  addiu $t9, $t3, 0xd8
  addiu $t2, $sp, 0x204
.Ljp7F0AB9D8:
  lw    $at, ($t3)
  addiu $t3, $t3, 0xc
  addiu $t2, $t2, 0xc
  sw    $at, -0xc($t2)
  lw    $at, -8($t3)
  sw    $at, -8($t2)
  lw    $at, -4($t3)
  bne   $t3, $t9, .Ljp7F0AB9D8
   sw    $at, -4($t2)
  lw    $at, ($t3)
  lui   $t6, %hi(D_80040BB4+0x90) # $t6, 0x8004
  addiu $t6, %lo(D_80040BB4+0x90) # addiu $t6, $t6, 0xc74
  addiu $t1, $t6, 0xd8
  addiu $t8, $sp, 0x128
  sw    $at, ($t2)
.Ljp7F0ABA14:
  lw    $at, ($t6)
  addiu $t6, $t6, 0xc
  addiu $t8, $t8, 0xc
  sw    $at, -0xc($t8)
  lw    $at, -8($t6)
  sw    $at, -8($t8)
  lw    $at, -4($t6)
  bne   $t6, $t1, .Ljp7F0ABA14
   sw    $at, -4($t8)
  lw    $at, ($t6)
  lui   $t4, %hi(D_80040D20) # $t4, 0x8004
  addiu $t4, %lo(D_80040D20) # addiu $t4, $t4, 0xd50
  addiu $t2, $t4, 0xd8
  addiu $t5, $sp, 0x4c
  sw    $at, ($t8)
.Ljp7F0ABA50:
  lw    $at, ($t4)
  addiu $t4, $t4, 0xc
  addiu $t5, $t5, 0xc
  sw    $at, -0xc($t5)
  lw    $at, -8($t4)
  sw    $at, -8($t5)
  lw    $at, -4($t4)
  bne   $t4, $t2, .Ljp7F0ABA50
   sw    $at, -4($t5)
  lw    $at, ($t4)
  lui   $a1, %hi(D_80040B2C) # $a1, 0x8004
  lui   $a2, %hi(D_80040B28) # $a2, 0x8004
  lui   $a3, %hi(D_80040B24) # $a3, 0x8004
  addiu $a3, %lo(D_80040B24) # addiu $a3, $a3, 0xb54
  addiu $a2, %lo(D_80040B28) # addiu $a2, $a2, 0xb58
  addiu $a1, %lo(D_80040B2C) # addiu $a1, $a1, 0xb5c
  move  $a0, $zero
  jal   sub_GAME_7F0A9684
   sw    $at, ($t5)
  jal   matrix_4x4_set_identity
   addiu $a0, $sp, 0x4fc
  lui   $at, %hi(D_80040B28) # $at, 0x8004
  lwc1  $f4, %lo(D_80040B28)($at)
  lui   $at, %hi(jpD_800484D0) # $at, 0x8005
  lwc1  $f6, %lo(jpD_800484D0)($at)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f10
  mul.s $f8, $f4, $f6
  lui   $v0, %hi(D_80040B24) # $v0, 0x8004
  addiu $v0, %lo(D_80040B24) # addiu $v0, $v0, 0xb54
  lwc1  $f18, ($v0)
  mul.s $f16, $f8, $f10
  add.s $f4, $f18, $f16
  swc1  $f4, ($v0)
  jal   sub_GAME_7F0A6A2C
   lwc1  $f12, ($v0)
  lui   $at, %hi(D_80040B24) # $at, 0x8004
  swc1  $f0, %lo(D_80040B24)($at)
  lwc1  $f12, %lo(D_80040B24)($at)
  jal   sub_GAME_7F058688
   addiu $a1, $sp, 0x4bc
  lui   $t0, %hi(watch_soundrelated_maybe) # $t0, 0x8004
  lw    $t0, %lo(watch_soundrelated_maybe)($t0)
  beqz  $t0, .Ljp7F0ABB58
   lui   $t7, %hi(D_80040998) # $t7, 0x8004
  lw    $t7, %lo(D_80040998)($t7)
  li    $at, 1
  bne   $t7, $at, .Ljp7F0ABB58
   nop   
  jal   get_cur_controller_vert_stick_pos
   move  $a0, $zero
  mtc1  $v0, $f6
  lui   $at, %hi(D_80040B20) # $at, 0x8004
  lwc1  $f12, %lo(D_80040B20)($at)
  cvt.s.w $f8, $f6
  lui   $at, %hi(D_80058550) # $at, 0x8006
  lwc1  $f10, %lo(D_80058550)($at)
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f16
  lui   $a2, 0x4080
  mul.s $f18, $f8, $f10
  jal   sub_GAME_7F0A95C4
   div.s $f14, $f18, $f16
  lui   $at, %hi(D_80040B20) # $at, 0x8004
  b     .Ljp7F0ABB74
   swc1  $f0, %lo(D_80040B20)($at)
.Ljp7F0ABB58:
  lui   $at, %hi(D_80040B20) # $at, 0x8004
  mtc1  $zero, $f14
  lwc1  $f12, %lo(D_80040B20)($at)
  jal   sub_GAME_7F0A95C4
   lui   $a2, 0x4080
  lui   $at, %hi(D_80040B20) # $at, 0x8004
  swc1  $f0, %lo(D_80040B20)($at)
.Ljp7F0ABB74:
  lui   $at, %hi(D_80040B20) # $at, 0x8004
  lwc1  $f4, %lo(D_80040B20)($at)
  lui   $at, %hi(D_80058554) # $at, 0x8006
  lwc1  $f8, %lo(D_80058554)($at)
  neg.s $f6, $f4
  addiu $a1, $sp, 0x47c
  jal   sub_GAME_7F058570
   sub.s $f12, $f6, $f8
  addiu $a0, $sp, 0x4fc
  addiu $a1, $sp, 0x4bc
  jal   matrix_4x4_multiply
   addiu $a2, $sp, 0x43c
  addiu $a0, $sp, 0x43c
  addiu $a1, $sp, 0x47c
  jal   matrix_4x4_multiply
   addiu $a2, $sp, 0x3fc
  addiu $a0, $sp, 0x370
  jal   init_something_copy_posdata_to_it
   addiu $a1, $sp, 0x43c
  addiu $a0, $sp, 0x43c
  addiu $a1, $sp, 0x3fc
  jal   matrix_4x4_multiply
   addiu $a2, $sp, 0x3bc
  jal   controllerCheckDualControllerTypesAllowed
   nop   
  beqz  $v0, .Ljp7F0ABC3C
   lui   $at, 0xc0a0
  lui    $at, %hi(D_80058558)
  lwc1  $f0, %lo(D_80058558)($at)
  li    $at, 0x42000000 # 32.000000
  mtc1  $at, $f12
  mtc1  $zero, $f2
  li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f10
  addiu $t1, $sp, 0x128
  lui   $a2, (0x451C4000 >> 16) # lui $a2, 0x451c
  mfc1  $a1, $f0
  mfc1  $a3, $f12
  sw    $t1, 0x2e8($sp)
  ori   $a2, (0x451C4000 & 0xFFFF) # ori $a2, $a2, 0x4000
  addiu $a0, $sp, 0x32c
  swc1  $f0, 0x10($sp)
  swc1  $f12, 0x18($sp)
  swc1  $f2, 0x14($sp)
  swc1  $f2, 0x1c($sp)
  swc1  $f2, 0x20($sp)
  jal   sub_GAME_7F059694
   swc1  $f10, 0x24($sp)
  b     .Ljp7F0ABC94
   addiu $a0, $sp, 0x32c
.Ljp7F0ABC3C:
  mtc1  $at, $f0
  li    $at, 0xC3280000 # -168.000000
  mtc1  $at, $f2
  li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f6
  mtc1  $zero, $f18
  mtc1  $zero, $f16
  mtc1  $zero, $f4
  addiu $t6, $sp, 0x204
  mfc1  $a1, $f0
  mfc1  $a3, $f2
  sw    $t6, 0x2e8($sp)
  addiu $a0, $sp, 0x32c
  lui   $a2, 0x44fa
  swc1  $f0, 0x10($sp)
  swc1  $f2, 0x18($sp)
  swc1  $f6, 0x24($sp)
  swc1  $f18, 0x14($sp)
  swc1  $f16, 0x1c($sp)
  jal   sub_GAME_7F059694
   swc1  $f4, 0x20($sp)
  addiu $a0, $sp, 0x32c
.Ljp7F0ABC94:
  addiu $a1, $sp, 0x3bc
  jal   matrix_4x4_multiply
   addiu $a2, $sp, 0x37c
  li    $at, 0x447A0000 # 1000.000000
  mtc1  $at, $f8
  lui   $at, %hi(D_8005855C) # $at, 0x8006
  lwc1  $f10, %lo(D_8005855C)($at)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f18
  lui   $a3, (0x3FAAAAAB >> 16) # lui $a3, 0x3faa
  ori   $a3, (0x3FAAAAAB & 0xFFFF) # ori $a3, $a3, 0xaaab
  lw    $a0, 0x53c($sp)
  addiu $a1, $sp, 0x36e
  lui   $a2, 0x424a
  swc1  $f8, 0x10($sp)
  swc1  $f10, 0x14($sp)
  jal   guPerspective
   swc1  $f18, 0x18($sp)
  lui   $t8, (0x01030040 >> 16) # lui $t8, 0x103
  ori   $t8, (0x01030040 & 0xFFFF) # ori $t8, $t8, 0x40
  move  $v1, $s0
  sw    $t8, ($v1)
  sw    $v1, 0x48($sp)
  lw    $a0, 0x53c($sp)
  jal   osVirtualToPhysical
   addiu $s0, $s0, 8
  lw    $v1, 0x48($sp)
  move  $a0, $s0
  jal   sub_GAME_7F0A6EE8
   sw    $v0, 4($v1)
  lui   $v1, %hi(D_80040B04) # $v1, 0x8004
  lw    $v1, %lo(D_80040B04)($v1)
  move  $s0, $v0
  move  $a0, $s0
  slti  $at, $v1, 0xe0
  beqz  $at, .Ljp7F0ABD54
   addiu $a1, $sp, 0x37c
  lw    $t3, 0x2e8($sp)
  addiu $t9, $sp, 0x2e3
  sw    $t9, 0x14($sp)
  move  $a0, $v0
  addiu $a1, $sp, 0x37c
  addiu $a2, $v1, -6
  li    $a3, 1
  jal   sub_GAME_7F06359C
   sw    $t3, 0x10($sp)
  b     .Ljp7F0ABD6C
   move  $s0, $v0
.Ljp7F0ABD54:
  addiu $t2, $sp, 0x2e3
  sw    $t2, 0x10($sp)
  li    $a2, 1
  jal   sub_GAME_7F064364
   lw    $a3, 0x2e8($sp)
  move  $s0, $v0
.Ljp7F0ABD6C:
  jal   controllerCheckDualControllerTypesAllowed
   nop   
  beqz  $v0, .Ljp7F0ABFF4
   li    $a0, 1
  lui   $a1, %hi(D_80040B3C) # $a1, 0x8004
  lui   $a2, %hi(D_80040B38) # $a2, 0x8004
  lui   $a3, %hi(D_80040B34) # $a3, 0x8004
  addiu $a3, %lo(D_80040B34) # addiu $a3, $a3, 0xb64
  addiu $a2, %lo(D_80040B38) # addiu $a2, $a2, 0xb68
  jal   sub_GAME_7F0A9684
   addiu $a1, %lo(D_80040B3C) # addiu $a1, $a1, 0xb6c
  jal   matrix_4x4_set_identity
   addiu $a0, $sp, 0x4fc
  lui   $at, %hi(D_80040B38) # $at, 0x8004
  lwc1  $f16, %lo(D_80040B38)($at)
  lui   $at, %hi(jpD_800484D0) # $at, 0x8005
  lwc1  $f4, %lo(jpD_800484D0)($at)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f8
  mul.s $f6, $f16, $f4
  lui   $v0, %hi(D_80040B34) # $v0, 0x8004
  addiu $v0, %lo(D_80040B34) # addiu $v0, $v0, 0xb64
  lwc1  $f18, ($v0)
  mul.s $f10, $f6, $f8
  add.s $f16, $f18, $f10
  swc1  $f16, ($v0)
  jal   sub_GAME_7F0A6A2C
   lwc1  $f12, ($v0)
  lui   $at, %hi(D_80040B34) # $at, 0x8004
  swc1  $f0, %lo(D_80040B34)($at)
  lwc1  $f12, %lo(D_80040B34)($at)
  jal   sub_GAME_7F058688
   addiu $a1, $sp, 0x4bc
  lui   $t4, %hi(watch_soundrelated_maybe) # $t4, 0x8004
  lw    $t4, %lo(watch_soundrelated_maybe)($t4)
  beqz  $t4, .Ljp7F0ABE54
   lui   $t5, %hi(D_80040998) # $t5, 0x8004
  lw    $t5, %lo(D_80040998)($t5)
  li    $at, 1
  bne   $t5, $at, .Ljp7F0ABE54
   nop   
  jal   get_cur_controller_vert_stick_pos
   li    $a0, 1
  mtc1  $v0, $f4
  lui   $at, %hi(D_80040B30) # $at, 0x8004
  lwc1  $f12, %lo(D_80040B30)($at)
  cvt.s.w $f6, $f4
  lui   $at, %hi(D_80058560) # $at, 0x8006
  lwc1  $f8, %lo(D_80058560)($at)
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f10
  lui   $a2, 0x4080
  mul.s $f18, $f6, $f8
  jal   sub_GAME_7F0A95C4
   div.s $f14, $f18, $f10
  lui   $at, %hi(D_80040B30) # $at, 0x8004
  b     .Ljp7F0ABE70
   swc1  $f0, %lo(D_80040B30)($at)
.Ljp7F0ABE54:
  lui   $at, %hi(D_80040B30) # $at, 0x8004
  mtc1  $zero, $f14
  lwc1  $f12, %lo(D_80040B30)($at)
  jal   sub_GAME_7F0A95C4
   lui   $a2, 0x4080
  lui   $at, %hi(D_80040B30) # $at, 0x8004
  swc1  $f0, %lo(D_80040B30)($at)
.Ljp7F0ABE70:
  lui   $at, %hi(D_80040B30) # $at, 0x8004
  lwc1  $f16, %lo(D_80040B30)($at)
  lui   $at, %hi(D_80058564) # $at, 0x8006
  lwc1  $f6, %lo(D_80058564)($at)
  neg.s $f4, $f16
  addiu $a1, $sp, 0x47c
  jal   sub_GAME_7F058570
   sub.s $f12, $f4, $f6
  addiu $a0, $sp, 0x4fc
  addiu $a1, $sp, 0x4bc
  jal   matrix_4x4_multiply
   addiu $a2, $sp, 0x43c
  addiu $a0, $sp, 0x43c
  addiu $a1, $sp, 0x47c
  jal   matrix_4x4_multiply
   addiu $a2, $sp, 0x3fc
  addiu $a0, $sp, 0x370
  jal   init_something_copy_posdata_to_it
   addiu $a1, $sp, 0x43c
  addiu $a0, $sp, 0x43c
  addiu $a1, $sp, 0x3fc
  jal   matrix_4x4_multiply
   addiu $a2, $sp, 0x3bc
  lui   $at, %hi(D_80058568) # $at, 0x8006
  lwc1  $f0, %lo(D_80058568)($at)
  li    $at, 0x42000000 # 32.000000
  mtc1  $zero, $f2
  mtc1  $at, $f8
  li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f18
  lui   $a2, (0x451C4000 >> 16) # lui $a2, 0x451c
  mfc1  $a1, $f0
  ori   $a2, (0x451C4000 & 0xFFFF) # ori $a2, $a2, 0x4000
  addiu $a0, $sp, 0x2ec
  lui   $a3, 0x4200
  swc1  $f0, 0x10($sp)
  swc1  $f2, 0x14($sp)
  swc1  $f2, 0x1c($sp)
  swc1  $f2, 0x20($sp)
  swc1  $f8, 0x18($sp)
  jal   sub_GAME_7F059694
   swc1  $f18, 0x24($sp)
  addiu $a0, $sp, 0x2ec
  addiu $a1, $sp, 0x3bc
  jal   matrix_4x4_multiply
   addiu $a2, $sp, 0x37c
  li    $at, 0x447A0000 # 1000.000000
  mtc1  $at, $f10
  lui   $at, %hi(D_8005856C) # $at, 0x8006
  lwc1  $f16, %lo(D_8005856C)($at)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  lui   $a3, (0x3FAAAAAB >> 16) # lui $a3, 0x3faa
  ori   $a3, (0x3FAAAAAB & 0xFFFF) # ori $a3, $a3, 0xaaab
  lw    $a0, 0x53c($sp)
  addiu $a1, $sp, 0x36e
  lui   $a2, 0x424a
  swc1  $f10, 0x10($sp)
  swc1  $f16, 0x14($sp)
  jal   guPerspective
   swc1  $f4, 0x18($sp)
  lui   $t0, (0x01030040 >> 16) # lui $t0, 0x103
  ori   $t0, (0x01030040 & 0xFFFF) # ori $t0, $t0, 0x40
  move  $v1, $s0
  sw    $t0, ($v1)
  sw    $v1, 0x44($sp)
  lw    $a0, 0x53c($sp)
  jal   osVirtualToPhysical
   addiu $s0, $s0, 8
  lw    $v1, 0x44($sp)
  move  $a0, $s0
  jal   sub_GAME_7F0A6EE8
   sw    $v0, 4($v1)
  lui   $v1, %hi(D_80040B04) # $v1, 0x8004
  lw    $v1, %lo(D_80040B04)($v1)
  move  $s0, $v0
  move  $a0, $s0
  slti  $at, $v1, 0xe0
  beqz  $at, .Ljp7F0ABFDC
   addiu $a1, $sp, 0x37c
  addiu $t7, $sp, 0x4c
  addiu $t1, $sp, 0x2e2
  sw    $t1, 0x14($sp)
  sw    $t7, 0x10($sp)
  move  $a0, $v0
  addiu $a1, $sp, 0x37c
  addiu $a2, $v1, -6
  jal   sub_GAME_7F06359C
   li    $a3, 1
  b     .Ljp7F0ABFF4
   move  $s0, $v0
.Ljp7F0ABFDC:
  addiu $t6, $sp, 0x2e2
  sw    $t6, 0x10($sp)
  li    $a2, 1
  jal   sub_GAME_7F064364
   addiu $a3, $sp, 0x4c
  move  $s0, $v0
.Ljp7F0ABFF4:
  jal   controllerCheckDualControllerTypesAllowed
   nop   
  beqz  $v0, .Ljp7F0AC014
   nop   
  jal   sub_GAME_7F0AA7C8
   move  $a0, $s0
  b     .Ljp7F0AC020
   move  $s0, $v0
.Ljp7F0AC014:
  jal   sub_GAME_7F0A9AB8
   move  $a0, $s0
  move  $s0, $v0
.Ljp7F0AC020:
  lw    $ra, 0x34($sp)
  move  $v0, $s0
  lw    $s0, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x540
");
#endif

void zero_D_80040998(void) { D_80040998 = 0; }

void zero_D_8004099C(void) { D_8004099C = 0; }

void zero_D_800409A4(void) { D_800409A4 = 0; }

unsigned int return_arg0_7F0AB4B0(unsigned int uParm1) { return uParm1; }

asm(R"
glabel sub_GAME_7F0AB4B8
  addiu $sp, $sp, -0x68
  sw    $ra, 0x44($sp)
  sw    $s2, 0x40($sp)
  sw    $s1, 0x3c($sp)
  sw    $s0, 0x38($sp)
  jal   sub_GAME_7F0A714C
   move  $a2, $zero
  jal   check_watch_page_transistion_running
   move  $s0, $v0
  li    $at, 1
  beql  $v0, $at, .L7F0AB78C
   lw    $ra, 0x44($sp)
  jal   sub_GAME_7F0AADC0
   move  $a0, $s0
  lui   $t6, %hi(ptrFirstFontTableSmall) 
  lui   $t7, %hi(ptrSecondFontTableSmall) 
  lw    $t6, %lo(ptrFirstFontTableSmall)($t6)
  lw    $t7, %lo(ptrSecondFontTableSmall)($t7)
  move  $a0, $v0
  sw    $t6, 0x4c($sp)
  jal   microcode_constructor
   sw    $t7, 0x48($sp)
  move  $s0, $v0
  jal   get_textptr_for_textID
   li    $a0, 44082
  lui   $t0, %hi(D_80040998) 
  lw    $t0, %lo(D_80040998)($t0)
  li    $t8, 64
  li    $t9, 26
  lui   $s1, (0x00FF00B0 >> 16) # lui $s1, 0xff
  move  $s2, $v0
  sw    $t8, 0x5c($sp)
  sw    $t9, 0x58($sp)
  bnez  $t0, .L7F0AB560
   ori   $s1, (0x00FF00B0 & 0xFFFF) # ori $s1, $s1, 0xb0
  lui   $t1, %hi(watch_soundrelated_maybe) 
  lw    $t1, %lo(watch_soundrelated_maybe)($t1)
  lui   $s1, (0xA0FFA0F0 >> 16) # lui $s1, 0xa0ff
  ori   $s1, (0xA0FFA0F0 & 0xFFFF) # ori $s1, $s1, 0xa0f0
  beql  $t1, $zero, .L7F0AB564
   lw    $t2, 0x4c($sp)
  li    $s1, -1
.L7F0AB560:
  lw    $t2, 0x4c($sp)
.L7F0AB564:
  addiu $a0, $sp, 0x50
  addiu $a1, $sp, 0x54
  move  $a2, $s2
  lw    $a3, 0x48($sp)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t2, 0x10($sp)
  lui   $t3, %hi(watch_soundrelated_maybe) 
  lw    $t3, %lo(watch_soundrelated_maybe)($t3)
  lui   $t4, %hi(D_80040998) 
  move  $a0, $s0
  beqz  $t3, .L7F0AB600
   addiu $a1, $sp, 0x5c
  lw    $t4, %lo(D_80040998)($t4)
  addiu $a2, $sp, 0x58
  move  $a3, $s2
  bnez  $t4, .L7F0AB600
   lw    $t5, 0x48($sp)
  lw    $t8, 0x54($sp)
  lw    $t6, 0x4c($sp)
  lw    $t0, 0x50($sp)
  sw    $s1, 0x18($sp)
  lui   $t7, (0x007000A0 >> 16) # lui $t7, 0x70
  ori   $t7, (0x007000A0 & 0xFFFF) # ori $t7, $t7, 0xa0
  lui   $s1, (0x00FF00B0 >> 16) # lui $s1, 0xff
  addiu $t9, $t8, 1
  sw    $t9, 0x20($sp)
  ori   $s1, (0x00FF00B0 & 0xFFFF) # ori $s1, $s1, 0xb0
  sw    $t7, 0x1c($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x5c
  sw    $t5, 0x10($sp)
  sw    $zero, 0x28($sp)
  sw    $zero, 0x2c($sp)
  sw    $t6, 0x14($sp)
  jal   jp_text_write_stuff
   sw    $t0, 0x24($sp)
  b     .L7F0AB644
   move  $s0, $v0
.L7F0AB600:
  lw    $t1, 0x48($sp)
  lw    $t2, 0x4c($sp)
  lw    $t3, 0x54($sp)
  lw    $t4, 0x50($sp)
  sw    $s1, 0x18($sp)
  lui   $s1, (0x00FF00B0 >> 16) # lui $s1, 0xff
  ori   $s1, (0x00FF00B0 & 0xFFFF) # ori $s1, $s1, 0xb0
  addiu $a2, $sp, 0x58
  move  $a3, $s2
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t1, 0x10($sp)
  sw    $t2, 0x14($sp)
  sw    $t3, 0x1c($sp)
  jal   en_text_write_stuff
   sw    $t4, 0x20($sp)
  move  $s0, $v0
.L7F0AB644:
  jal   sub_GAME_7F0A97D0
   move  $a0, $s0
  move  $s0, $v0
  jal   get_textptr_for_textID
   li    $a0, 44083
  jal   controllerCheckDualControllerTypesAllowed
   move  $s2, $v0
  beqz  $v0, .L7F0AB674
   nop   
  jal   get_textptr_for_textID
   li    $a0, 44084
  move  $s2, $v0
.L7F0AB674:
  lui   $t7, %hi(D_80040998) 
  lw    $t7, %lo(D_80040998)($t7)
  li    $t5, 64
  li    $t6, 43
  li    $at, 1
  sw    $t5, 0x5c($sp)
  bne   $t7, $at, .L7F0AB6B0
   sw    $t6, 0x58($sp)
  lui   $t8, %hi(watch_soundrelated_maybe) 
  lw    $t8, %lo(watch_soundrelated_maybe)($t8)
  lui   $s1, (0xA0FFA0F0 >> 16) # lui $s1, 0xa0ff
  ori   $s1, (0xA0FFA0F0 & 0xFFFF) # ori $s1, $s1, 0xa0f0
  beql  $t8, $zero, .L7F0AB6B4
   lw    $t9, 0x4c($sp)
  li    $s1, -1
.L7F0AB6B0:
  lw    $t9, 0x4c($sp)
.L7F0AB6B4:
  addiu $a0, $sp, 0x50
  addiu $a1, $sp, 0x54
  move  $a2, $s2
  lw    $a3, 0x48($sp)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t9, 0x10($sp)
  lui   $t0, %hi(watch_soundrelated_maybe) 
  lw    $t0, %lo(watch_soundrelated_maybe)($t0)
  lui   $t1, %hi(D_80040998) 
  move  $a0, $s0
  beqz  $t0, .L7F0AB74C
   addiu $a1, $sp, 0x5c
  lw    $t1, %lo(D_80040998)($t1)
  li    $at, 1
  addiu $a2, $sp, 0x58
  bne   $t1, $at, .L7F0AB74C
   move  $a3, $s2
  lw    $t5, 0x54($sp)
  lw    $t2, 0x48($sp)
  lw    $t3, 0x4c($sp)
  lw    $t7, 0x50($sp)
  lui   $t4, (0x007000A0 >> 16) # lui $t4, 0x70
  ori   $t4, (0x007000A0 & 0xFFFF) # ori $t4, $t4, 0xa0
  addiu $t6, $t5, 1
  sw    $t6, 0x20($sp)
  sw    $t4, 0x1c($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x5c
  sw    $s1, 0x18($sp)
  sw    $zero, 0x28($sp)
  sw    $zero, 0x2c($sp)
  sw    $t2, 0x10($sp)
  sw    $t3, 0x14($sp)
  jal   jp_text_write_stuff
   sw    $t7, 0x24($sp)
  b     .L7F0AB788
   move  $s0, $v0
.L7F0AB74C:
  lw    $t8, 0x48($sp)
  lw    $t9, 0x4c($sp)
  lw    $t0, 0x54($sp)
  lw    $t1, 0x50($sp)
  addiu $a2, $sp, 0x58
  move  $a3, $s2
  sw    $s1, 0x18($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t8, 0x10($sp)
  sw    $t9, 0x14($sp)
  sw    $t0, 0x1c($sp)
  jal   en_text_write_stuff
   sw    $t1, 0x20($sp)
  move  $s0, $v0
.L7F0AB788:
  lw    $ra, 0x44($sp)
.L7F0AB78C:
  move  $v0, $s0
  lw    $s0, 0x38($sp)
  lw    $s1, 0x3c($sp)
  lw    $s2, 0x40($sp)
  jr    $ra
   addiu $sp, $sp, 0x68
");

void set_pparam1toparam2_disablejoylr_playsfx(unsigned int *param_1,
                                              unsigned int param_2) {
  *param_1 = param_2;
  set_controlstick_lr_disabled();
  play_sfx_a1(ptr_sfx_buf, 0x2b, NULL);
}

asm(R"
glabel sub_GAME_7F0AB7D8
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 546
  bnez  $v0, .L7F0AB804
   nop   
  jal   sub_GAME_7F0A4FB0
   nop   
  beqz  $v0, .L7F0AB86C
.L7F0AB804:
   lui   $t6, %hi(watch_soundrelated_maybe) 
  lw    $t6, %lo(watch_soundrelated_maybe)($t6)
  lw    $t7, 0x18($sp)
  lui   $t9, %hi(D_80040A7C) 
  beqz  $t6, .L7F0AB86C
   sll   $t8, $t7, 2
  subu  $t8, $t8, $t7
  sll   $t8, $t8, 2
  addiu $t9, %lo(D_80040A7C) # addiu $t9, $t9, 0xa7c
  addu  $v0, $t8, $t9
  lw    $v1, 8($v0)
  li    $at, 1
  addiu $a0, $v0, 8
  bnel  $v1, $at, .L7F0AB854
   li    $at, 2
  jal   set_pparam1toparam2_disablejoylr_playsfx
   move  $a1, $zero
  b     .L7F0AB8FC
   lw    $ra, 0x14($sp)
  li    $at, 2
.L7F0AB854:
  bne   $v1, $at, .L7F0AB8F8
   addiu $a0, $v0, 8
  jal   set_pparam1toparam2_disablejoylr_playsfx
   li    $a1, 1
  b     .L7F0AB8FC
   lw    $ra, 0x14($sp)
.L7F0AB86C:
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 273
  bnez  $v0, .L7F0AB88C
   nop   
  jal   sub_GAME_7F0A4FEC
   nop   
  beqz  $v0, .L7F0AB8F8
.L7F0AB88C:
   lui   $t0, %hi(watch_soundrelated_maybe) 
  lw    $t0, %lo(watch_soundrelated_maybe)($t0)
  lw    $t1, 0x18($sp)
  lui   $t3, %hi(D_80040A7C) 
  beqz  $t0, .L7F0AB8F8
   sll   $t2, $t1, 2
  subu  $t2, $t2, $t1
  sll   $t2, $t2, 2
  addiu $t3, %lo(D_80040A7C) # addiu $t3, $t3, 0xa7c
  addu  $v0, $t2, $t3
  lw    $v1, 8($v0)
  addiu $a0, $v0, 8
  li    $at, 1
  bnez  $v1, .L7F0AB8D8
   nop   
  jal   set_pparam1toparam2_disablejoylr_playsfx
   li    $a1, 1
  b     .L7F0AB8FC
   lw    $ra, 0x14($sp)
.L7F0AB8D8:
  bnel  $v1, $at, .L7F0AB8FC
   lw    $ra, 0x14($sp)
  lhu   $t4, 6($v0)
  addiu $a0, $v0, 8
  beql  $t4, $zero, .L7F0AB8FC
   lw    $ra, 0x14($sp)
  jal   set_pparam1toparam2_disablejoylr_playsfx
   li    $a1, 2
.L7F0AB8F8:
  lw    $ra, 0x14($sp)
.L7F0AB8FC:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0AB908
  lui   $v1, %hi(j_text_trigger)
  lw    $v1, %lo(j_text_trigger)($v1)
  addiu $sp, $sp, -0x60
  lui   $v0, 0x80
  ori   $t2, $v0, 0x80
  sw    $ra, 0x34($sp)
  sw    $a0, 0x60($sp)
  sw    $a1, 0x64($sp)
  move  $t1, $t2
  beqz  $v1, .L7F0AB93C
   sw    $t2, 0x54($sp)
  b     .L7F0AB940
   li    $a1, 170
.L7F0AB93C:
  li    $a1, 180
.L7F0AB940:
  beqz  $v1, .L7F0AB954
   li    $t7, 225
  li    $t6, 220
  b     .L7F0AB958
   sw    $t6, 0x4c($sp)
.L7F0AB954:
  sw    $t7, 0x4c($sp)
.L7F0AB958:
  beqz  $a3, .L7F0AB990
   sll   $t3, $a2, 2
  li    $v1, 1
  beq   $a3, $v1, .L7F0AB9E8
   sll   $t6, $a2, 2
  li    $at, 2
  beq   $a3, $at, .L7F0ABA3C
   sll   $t8, $a2, 2
  subu  $t8, $t8, $a2
  lui   $t9, %hi(D_80040A7C) 
  addiu $t9, %lo(D_80040A7C) # addiu $t9, $t9, 0xa7c
  sll   $t8, $t8, 2
  b     .L7F0ABAB8
   addu  $t0, $t8, $t9
.L7F0AB990:
  subu  $t3, $t3, $a2
  lui   $t4, %hi(D_80040A7C) 
  addiu $t4, %lo(D_80040A7C) # addiu $t4, $t4, 0xa7c
  sll   $t3, $t3, 2
  addu  $t0, $t3, $t4
  lw    $v0, 8($t0)
  li    $v1, 1
  bnez  $v0, .L7F0AB9C0
   nop   
  lui   $t1, (0x00FF00B0 >> 16) # lui $t1, 0xff
  b     .L7F0ABAB8
   ori   $t1, (0x00FF00B0 & 0xFFFF) # ori $t1, $t1, 0xb0
.L7F0AB9C0:
  bne   $v1, $v0, .L7F0AB9D4
   li    $at, 2
  lui   $t2, (0x00FF00B0 >> 16) # lui $t2, 0xff
  b     .L7F0ABAB8
   ori   $t2, (0x00FF00B0 & 0xFFFF) # ori $t2, $t2, 0xb0
.L7F0AB9D4:
  bne   $v0, $at, .L7F0ABAB8
   lui   $t5, (0x00FF00B0 >> 16) # lui $t5, 0xff
  ori   $t5, (0x00FF00B0 & 0xFFFF) # ori $t5, $t5, 0xb0
  b     .L7F0ABAB8
   sw    $t5, 0x54($sp)
.L7F0AB9E8:
  subu  $t6, $t6, $a2
  lui   $t7, %hi(D_80040A7C) 
  addiu $t7, %lo(D_80040A7C) # addiu $t7, $t7, 0xa7c
  sll   $t6, $t6, 2
  addu  $t0, $t6, $t7
  lw    $v0, 8($t0)
  bnez  $v0, .L7F0ABA14
   nop   
  lui   $t1, (0x00FF00B0 >> 16) # lui $t1, 0xff
  b     .L7F0ABAB8
   ori   $t1, (0x00FF00B0 & 0xFFFF) # ori $t1, $t1, 0xb0
.L7F0ABA14:
  bne   $v1, $v0, .L7F0ABA28
   li    $at, 2
  lui   $t2, (0x00FF00B0 >> 16) # lui $t2, 0xff
  b     .L7F0ABAB8
   ori   $t2, (0x00FF00B0 & 0xFFFF) # ori $t2, $t2, 0xb0
.L7F0ABA28:
  bne   $v0, $at, .L7F0ABAB8
   lui   $t8, (0x00FF00B0 >> 16) # lui $t8, 0xff
  ori   $t8, (0x00FF00B0 & 0xFFFF) # ori $t8, $t8, 0xb0
  b     .L7F0ABAB8
   sw    $t8, 0x54($sp)
.L7F0ABA3C:
  move  $a0, $a2
  sw    $a1, 0x50($sp)
  sw    $a2, 0x68($sp)
  sw    $t1, 0x5c($sp)
  jal   sub_GAME_7F0AB7D8
   sw    $t2, 0x58($sp)
  lw    $a2, 0x68($sp)
  lui   $t3, %hi(D_80040A7C) 
  addiu $t3, %lo(D_80040A7C) # addiu $t3, $t3, 0xa7c
  sll   $t9, $a2, 2
  subu  $t9, $t9, $a2
  sll   $t9, $t9, 2
  addu  $t0, $t9, $t3
  lw    $v0, 8($t0)
  li    $v1, 1
  lw    $a1, 0x50($sp)
  lw    $t1, 0x5c($sp)
  bnez  $v0, .L7F0ABA94
   lw    $t2, 0x58($sp)
  lui   $t1, (0xA0FFA0F0 >> 16) # lui $t1, 0xa0ff
  b     .L7F0ABAB8
   ori   $t1, (0xA0FFA0F0 & 0xFFFF) # ori $t1, $t1, 0xa0f0
.L7F0ABA94:
  bne   $v1, $v0, .L7F0ABAA8
   li    $at, 2
  lui   $t2, (0xA0FFA0F0 >> 16) # lui $t2, 0xa0ff
  b     .L7F0ABAB8
   ori   $t2, (0xA0FFA0F0 & 0xFFFF) # ori $t2, $t2, 0xa0f0
.L7F0ABAA8:
  bne   $v0, $at, .L7F0ABAB8
   lui   $t4, (0xA0FFA0F0 >> 16) # lui $t4, 0xa0ff
  ori   $t4, (0xA0FFA0F0 & 0xFFFF) # ori $t4, $t4, 0xa0f0
  sw    $t4, 0x54($sp)
.L7F0ABAB8:
  lhu   $t5, 6($t0)
  bnez  $t5, .L7F0ABAF4
   lui   $v1, %hi(j_text_trigger)
  lw    $v1, %lo(j_text_trigger)($v1)
  li    $a1, 200
  li    $t7, 250
  beqz  $v1, .L7F0ABAE0
   li    $t6, 250
  b     .L7F0ABAE0
   li    $a1, 190
.L7F0ABAE0:
  beql  $v1, $zero, .L7F0ABAF4
   sw    $t7, 0x4c($sp)
  b     .L7F0ABAF4
   sw    $t6, 0x4c($sp)
  sw    $t7, 0x4c($sp)
.L7F0ABAF4:
  lhu   $a0, 2($t0)
  sw    $a1, 0x50($sp)
  sw    $t0, 0x3c($sp)
  sw    $t1, 0x5c($sp)
  jal   get_textptr_for_textID
   sw    $t2, 0x58($sp)
  lw    $t1, 0x5c($sp)
  lui   $t3, (0x003000B0 >> 16) # lui $t3, 0x30
  ori   $t3, (0x003000B0 & 0xFFFF) # ori $t3, $t3, 0xb0
  li    $t8, -1
  li    $t9, 1
  sw    $t9, 0x1c($sp)
  sw    $t8, 0x18($sp)
  sw    $t3, 0x24($sp)
  lw    $a1, 0x50($sp)
  lw    $a0, 0x60($sp)
  lw    $a2, 0x64($sp)
  move  $a3, $v0
  sw    $zero, 0x14($sp)
  sw    $zero, 0x20($sp)
  sw    $zero, 0x28($sp)
  jal   sub_GAME_7F0A9398
   sw    $t1, 0x10($sp)
  lw    $t0, 0x3c($sp)
  sw    $v0, 0x60($sp)
  jal   get_textptr_for_textID
   lhu   $a0, 4($t0)
  lw    $t2, 0x58($sp)
  lui   $t6, (0x003000B0 >> 16) # lui $t6, 0x30
  ori   $t6, (0x003000B0 & 0xFFFF) # ori $t6, $t6, 0xb0
  li    $t4, -1
  li    $t5, 1
  sw    $t5, 0x1c($sp)
  sw    $t4, 0x18($sp)
  sw    $t6, 0x24($sp)
  lw    $a0, 0x60($sp)
  lw    $a1, 0x4c($sp)
  lw    $a2, 0x64($sp)
  move  $a3, $v0
  sw    $zero, 0x14($sp)
  sw    $zero, 0x20($sp)
  sw    $zero, 0x28($sp)
  jal   sub_GAME_7F0A9398
   sw    $t2, 0x10($sp)
  lw    $t0, 0x3c($sp)
  sw    $v0, 0x60($sp)
  lhu   $v1, 6($t0)
  beql  $v1, $zero, .L7F0ABC0C
   lw    $ra, 0x34($sp)
  jal   get_textptr_for_textID
   move  $a0, $v1
  lw    $t7, 0x54($sp)
  lui   $t3, (0x003000B0 >> 16) # lui $t3, 0x30
  ori   $t3, (0x003000B0 & 0xFFFF) # ori $t3, $t3, 0xb0
  li    $t8, -1
  li    $t9, 1
  sw    $t9, 0x1c($sp)
  sw    $t8, 0x18($sp)
  sw    $t3, 0x24($sp)
  lw    $a0, 0x60($sp)
  li    $a1, 270
  lw    $a2, 0x64($sp)
  move  $a3, $v0
  sw    $zero, 0x14($sp)
  sw    $zero, 0x20($sp)
  sw    $zero, 0x28($sp)
  jal   sub_GAME_7F0A9398
   sw    $t7, 0x10($sp)
  sw    $v0, 0x60($sp)
  lw    $ra, 0x34($sp)
.L7F0ABC0C:
  lw    $v0, 0x60($sp)
  addiu $sp, $sp, 0x60
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0ABC1C
  addiu $sp, $sp, -0x60
  sw    $ra, 0x5c($sp)
  sw    $fp, 0x58($sp)
  sw    $s7, 0x54($sp)
  sw    $s6, 0x50($sp)
  sw    $s5, 0x4c($sp)
  sw    $s4, 0x48($sp)
  sw    $s3, 0x44($sp)
  sw    $s2, 0x40($sp)
  sw    $s1, 0x3c($sp)
  jal   microcode_constructor
   sw    $s0, 0x38($sp)
  lui   $s3, %hi(D_80040A7C)
  lui   $s7, (0x007000A0 >> 16) # lui $s7, 0x70
  lui   $s6, %hi(watch_soundrelated_maybe)
  lui   $s5, %hi(D_8004099C)
  lui   $s4, (0x003000B0 >> 16) # lui $s4, 0x30
  move  $s2, $v0
  ori   $s4, (0x003000B0 & 0xFFFF) # ori $s4, $s4, 0xb0
  addiu $s5, %lo(D_8004099C) # addiu $s5, $s5, 0x99c
  addiu $s6, %lo(watch_soundrelated_maybe) # addiu $s6, $s6, 0x9a8
  ori   $s7, (0x007000A0 & 0xFFFF) # ori $s7, $s7, 0xa0
  addiu $s3, %lo(D_80040A7C) # addiu $s3, $s3, 0xa7c
  move  $s1, $zero
  li    $s0, 80
  li    $fp, 8
.L7F0ABC84:
  lw    $t7, ($s5)
  addiu $t6, $s1, 2
  bne   $t6, $t7, .L7F0ABD5C
   nop   
  lw    $t8, ($s6)
  beqz  $t8, .L7F0ABCFC
   nop   
  jal   get_textptr_for_textID
   lhu   $a0, ($s3)
  li    $t9, -1
  li    $t0, 1
  sw    $t0, 0x14($sp)
  sw    $t9, 0x10($sp)
  move  $a0, $s2
  li    $a1, 64
  move  $a2, $s0
  move  $a3, $v0
  sw    $s7, 0x18($sp)
  sw    $zero, 0x1c($sp)
  sw    $zero, 0x20($sp)
  sw    $s4, 0x24($sp)
  jal   sub_GAME_7F0A9398
   sw    $zero, 0x28($sp)
  move  $a0, $v0
  move  $a1, $s0
  move  $a2, $s1
  jal   sub_GAME_7F0AB908
   li    $a3, 2
  b     .L7F0ABDB8
   move  $s2, $v0
.L7F0ABCFC:
  jal   get_textptr_for_textID
   lhu   $a0, ($s3)
  lui   $t1, (0xA0FFA0F0 >> 16) # lui $t1, 0xa0ff
  ori   $t1, (0xA0FFA0F0 & 0xFFFF) # ori $t1, $t1, 0xa0f0
  li    $t2, -1
  sw    $t2, 0x18($sp)
  sw    $t1, 0x10($sp)
  move  $a0, $s2
  li    $a1, 64
  move  $a2, $s0
  move  $a3, $v0
  sw    $zero, 0x14($sp)
  sw    $zero, 0x1c($sp)
  sw    $zero, 0x20($sp)
  sw    $s4, 0x24($sp)
  jal   sub_GAME_7F0A9398
   sw    $zero, 0x28($sp)
  move  $a0, $v0
  move  $a1, $s0
  move  $a2, $s1
  jal   sub_GAME_7F0AB908
   li    $a3, 1
  b     .L7F0ABDB8
   move  $s2, $v0
.L7F0ABD5C:
  jal   get_textptr_for_textID
   lhu   $a0, ($s3)
  lui   $t3, (0x00FF00B0 >> 16) # lui $t3, 0xff
  ori   $t3, (0x00FF00B0 & 0xFFFF) # ori $t3, $t3, 0xb0
  li    $t4, -1
  sw    $t4, 0x18($sp)
  sw    $t3, 0x10($sp)
  move  $a0, $s2
  li    $a1, 64
  move  $a2, $s0
  move  $a3, $v0
  sw    $zero, 0x14($sp)
  sw    $zero, 0x1c($sp)
  sw    $zero, 0x20($sp)
  sw    $s4, 0x24($sp)
  jal   sub_GAME_7F0A9398
   sw    $zero, 0x28($sp)
  move  $a0, $v0
  move  $a1, $s0
  move  $a2, $s1
  jal   sub_GAME_7F0AB908
   move  $a3, $zero
  move  $s2, $v0
.L7F0ABDB8:
  addiu $s1, $s1, 1
  addiu $s3, $s3, 0xc
  bne   $s1, $fp, .L7F0ABC84
   addiu $s0, $s0, 0xf
  lw    $ra, 0x5c($sp)
  move  $v0, $s2
  lw    $s2, 0x40($sp)
  lw    $s0, 0x38($sp)
  lw    $s1, 0x3c($sp)
  lw    $s3, 0x44($sp)
  lw    $s4, 0x48($sp)
  lw    $s5, 0x4c($sp)
  lw    $s6, 0x50($sp)
  lw    $s7, 0x54($sp)
  lw    $fp, 0x58($sp)
  jr    $ra
   addiu $sp, $sp, 0x60
");

asm(R"
glabel sub_GAME_7F0ABDFC
  addiu $sp, $sp, -0x60
  sw    $ra, 0x3c($sp)
  sw    $s0, 0x38($sp)
  jal   sub_GAME_7F0A714C
   move  $a2, $zero
  jal   check_watch_page_transistion_running
   move  $s0, $v0
  li    $at, 1
  beql  $v0, $at, .L7F0AC0D8
   lw    $ra, 0x3c($sp)
  jal   sub_GAME_7F0A91C8
   move  $a0, $s0
  jal   sub_GAME_7F0A8FEC
   move  $a0, $v0
  lui   $t6, %hi(ptrFirstFontTableSmall) 
  lui   $t7, %hi(ptrSecondFontTableSmall) 
  lw    $t6, %lo(ptrFirstFontTableSmall)($t6)
  lw    $t7, %lo(ptrSecondFontTableSmall)($t7)
  move  $a0, $v0
  sw    $t6, 0x44($sp)
  jal   microcode_constructor
   sw    $t7, 0x40($sp)
  move  $s0, $v0
  jal   get_textptr_for_textID
   li    $a0, 44085
  lui   $t0, %hi(D_8004099C) 
  lw    $t0, %lo(D_8004099C)($t0)
  li    $t8, 64
  li    $t9, 37
  lui   $v1, (0x00FF00B0 >> 16) # lui $v1, 0xff
  move  $a2, $v0
  sw    $t8, 0x54($sp)
  sw    $t9, 0x50($sp)
  bnez  $t0, .L7F0ABEA4
   ori   $v1, (0x00FF00B0 & 0xFFFF) # ori $v1, $v1, 0xb0
  lui   $t1, %hi(watch_soundrelated_maybe) 
  lw    $t1, %lo(watch_soundrelated_maybe)($t1)
  lui   $v1, (0xA0FFA0F0 >> 16) # lui $v1, 0xa0ff
  ori   $v1, (0xA0FFA0F0 & 0xFFFF) # ori $v1, $v1, 0xa0f0
  beql  $t1, $zero, .L7F0ABEA8
   lw    $t2, 0x44($sp)
  li    $v1, -1
.L7F0ABEA4:
  lw    $t2, 0x44($sp)
.L7F0ABEA8:
  addiu $a0, $sp, 0x48
  addiu $a1, $sp, 0x4c
  lw    $a3, 0x40($sp)
  sw    $zero, 0x14($sp)
  sw    $v1, 0x5c($sp)
  sw    $a2, 0x58($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t2, 0x10($sp)
  lui   $t3, %hi(watch_soundrelated_maybe) 
  lw    $t3, %lo(watch_soundrelated_maybe)($t3)
  lw    $v1, 0x5c($sp)
  lw    $a3, 0x58($sp)
  beqz  $t3, .L7F0ABF4C
   lui   $t4, %hi(D_8004099C) 
  lw    $t4, %lo(D_8004099C)($t4)
  move  $a0, $s0
  addiu $a1, $sp, 0x54
  bnez  $t4, .L7F0ABF4C
   addiu $a2, $sp, 0x50
  lw    $t8, 0x4c($sp)
  sw    $v1, 0x18($sp)
  lw    $t5, 0x40($sp)
  lw    $t6, 0x44($sp)
  lw    $t0, 0x48($sp)
  lui   $v1, (0x00FF00B0 >> 16) # lui $v1, 0xff
  lui   $t7, (0x007000A0 >> 16) # lui $t7, 0x70
  ori   $t7, (0x007000A0 & 0xFFFF) # ori $t7, $t7, 0xa0
  ori   $v1, (0x00FF00B0 & 0xFFFF) # ori $v1, $v1, 0xb0
  addiu $t9, $t8, 1
  sw    $t9, 0x20($sp)
  sw    $v1, 0x5c($sp)
  sw    $t7, 0x1c($sp)
  sw    $zero, 0x28($sp)
  sw    $zero, 0x2c($sp)
  sw    $t5, 0x10($sp)
  sw    $t6, 0x14($sp)
  jal   jp_text_write_stuff
   sw    $t0, 0x24($sp)
  lw    $v1, 0x5c($sp)
  b     .L7F0ABF9C
   move  $s0, $v0
.L7F0ABF4C:
  sw    $v1, 0x18($sp)
  lw    $t1, 0x40($sp)
  lw    $t2, 0x44($sp)
  lw    $t3, 0x4c($sp)
  lw    $t4, 0x48($sp)
  lui   $v1, (0x00FF00B0 >> 16) # lui $v1, 0xff
  ori   $v1, (0x00FF00B0 & 0xFFFF) # ori $v1, $v1, 0xb0
  sw    $v1, 0x5c($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x54
  addiu $a2, $sp, 0x50
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t1, 0x10($sp)
  sw    $t2, 0x14($sp)
  sw    $t3, 0x1c($sp)
  jal   en_text_write_stuff
   sw    $t4, 0x20($sp)
  lw    $v1, 0x5c($sp)
  move  $s0, $v0
.L7F0ABF9C:
  li    $a0, 44086
  jal   get_textptr_for_textID
   sw    $v1, 0x5c($sp)
  lui   $t7, %hi(D_8004099C) 
  lw    $t7, %lo(D_8004099C)($t7)
  li    $t5, 64
  li    $t6, 59
  li    $at, 1
  lw    $v1, 0x5c($sp)
  move  $a2, $v0
  sw    $t5, 0x54($sp)
  bne   $t7, $at, .L7F0ABFEC
   sw    $t6, 0x50($sp)
  lui   $t8, %hi(watch_soundrelated_maybe) 
  lw    $t8, %lo(watch_soundrelated_maybe)($t8)
  lui   $v1, (0xA0FFA0F0 >> 16) # lui $v1, 0xa0ff
  ori   $v1, (0xA0FFA0F0 & 0xFFFF) # ori $v1, $v1, 0xa0f0
  beql  $t8, $zero, .L7F0ABFF0
   lw    $t9, 0x44($sp)
  li    $v1, -1
.L7F0ABFEC:
  lw    $t9, 0x44($sp)
.L7F0ABFF0:
  addiu $a0, $sp, 0x48
  addiu $a1, $sp, 0x4c
  lw    $a3, 0x40($sp)
  sw    $zero, 0x14($sp)
  sw    $v1, 0x5c($sp)
  sw    $a2, 0x58($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t9, 0x10($sp)
  lui   $t0, %hi(watch_soundrelated_maybe) 
  lw    $t0, %lo(watch_soundrelated_maybe)($t0)
  lw    $v1, 0x5c($sp)
  lw    $a3, 0x58($sp)
  beqz  $t0, .L7F0AC088
   lui   $t1, %hi(D_8004099C) 
  lw    $t1, %lo(D_8004099C)($t1)
  li    $at, 1
  move  $a0, $s0
  bne   $t1, $at, .L7F0AC088
   addiu $a1, $sp, 0x54
  lw    $t5, 0x4c($sp)
  lw    $t2, 0x40($sp)
  lw    $t3, 0x44($sp)
  lw    $t7, 0x48($sp)
  lui   $t4, (0x007000A0 >> 16) # lui $t4, 0x70
  ori   $t4, (0x007000A0 & 0xFFFF) # ori $t4, $t4, 0xa0
  addiu $t6, $t5, 1
  sw    $t6, 0x20($sp)
  sw    $t4, 0x1c($sp)
  addiu $a2, $sp, 0x50
  sw    $v1, 0x18($sp)
  sw    $zero, 0x28($sp)
  sw    $zero, 0x2c($sp)
  sw    $t2, 0x10($sp)
  sw    $t3, 0x14($sp)
  jal   jp_text_write_stuff
   sw    $t7, 0x24($sp)
  b     .L7F0AC0C8
   move  $s0, $v0
.L7F0AC088:
  lw    $t8, 0x40($sp)
  lw    $t9, 0x44($sp)
  lw    $t0, 0x4c($sp)
  lw    $t1, 0x48($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x54
  addiu $a2, $sp, 0x50
  sw    $v1, 0x18($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t8, 0x10($sp)
  sw    $t9, 0x14($sp)
  sw    $t0, 0x1c($sp)
  jal   en_text_write_stuff
   sw    $t1, 0x20($sp)
  move  $s0, $v0
.L7F0AC0C8:
  jal   sub_GAME_7F0ABC1C
   move  $a0, $s0
  move  $s0, $v0
  lw    $ra, 0x3c($sp)
.L7F0AC0D8:
  move  $v0, $s0
  lw    $s0, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x60
");

asm(R"
glabel sub_GAME_7F0AC0E8
  lbu   $v0, ($a0)
  move  $v1, $zero
  li    $a1, 10
  beqz  $v0, .L7F0AC118
   nop   
.L7F0AC0FC:
  bnel  $a1, $v0, .L7F0AC10C
   lbu   $v0, 1($a0)
  addiu $v1, $v1, 1
  lbu   $v0, 1($a0)
.L7F0AC10C:
  addiu $a0, $a0, 1
  bnez  $v0, .L7F0AC0FC
   nop   
.L7F0AC118:
  jr    $ra
   move  $v0, $v1
");

asm(R"
glabel sub_GAME_7F0AC120
  lbu   $v0, ($a0)
  move  $v1, $a0
  li    $a1, 10
  beqz  $v0, .L7F0AC160
   nop   
.L7F0AC134:
  bnel  $a1, $v0, .L7F0AC154
   lbu   $v0, 1($a0)
  lbu   $t6, 1($a0)
  addiu $a0, $a0, 1
  beql  $t6, $zero, .L7F0AC154
   lbu   $v0, 1($a0)
  move  $v1, $a0
  lbu   $v0, 1($a0)
.L7F0AC154:
  addiu $a0, $a0, 1
  bnez  $v0, .L7F0AC134
   nop   
.L7F0AC160:
  jr    $ra
   move  $v0, $v1
");

asm(R"
.late_rodata
/*D:80058570*/
glabel jpt_80058570
.word .L7F0AC3B8
.word .L7F0AC400
.word .L7F0AC448
.word .L7F0AC490
.word .L7F0AC4D8

.text
glabel sub_GAME_7F0AC168
  addiu $sp, $sp, -0xde8
  sw    $ra, 0x5c($sp)
  sw    $fp, 0x58($sp)
  sw    $s7, 0x54($sp)
  sw    $s6, 0x50($sp)
  sw    $s5, 0x4c($sp)
  sw    $s4, 0x48($sp)
  sw    $s3, 0x44($sp)
  sw    $s2, 0x40($sp)
  sw    $s1, 0x3c($sp)
  sw    $s0, 0x38($sp)
  jal   sub_GAME_7F0A714C
   move  $a2, $zero
  jal   check_watch_page_transistion_running
   sw    $v0, 0xde8($sp)
  li    $at, 1
  beq   $v0, $at, .L7F0AC9F4
   addiu $t6, $sp, 0xdac
  lui   $t7, %hi(D_80040DFC) 
  addiu $t7, %lo(D_80040DFC) # addiu $t7, $t7, 0xdfc
  addiu $t9, $t7, 0x3c
.L7F0AC1BC:
  lw    $at, ($t7)
  addiu $t7, $t7, 0xc
  addiu $t6, $t6, 0xc
  sw    $at, -0xc($t6)
  lw    $at, -8($t7)
  sw    $at, -8($t6)
  lw    $at, -4($t7)
  bne   $t7, $t9, .L7F0AC1BC
   sw    $at, -4($t6)
  lui   $t1, %hi(D_80040E38) 
  addiu $t1, %lo(D_80040E38) # addiu $t1, $t1, 0xe38
  lw    $at, ($t1)
  lw    $t3, 4($t1)
  addiu $t0, $sp, 0xda4
  lui   $t5, %hi(D_80040E40) 
  addiu $t5, %lo(D_80040E40) # addiu $t5, $t5, 0xe40
  addiu $t9, $t5, 0x3c
  addiu $t4, $sp, 0xd68
  sw    $at, ($t0)
  sw    $t3, 4($t0)
.L7F0AC20C:
  lw    $at, ($t5)
  addiu $t5, $t5, 0xc
  addiu $t4, $t4, 0xc
  sw    $at, -0xc($t4)
  lw    $at, -8($t5)
  sw    $at, -8($t4)
  lw    $at, -4($t5)
  bne   $t5, $t9, .L7F0AC20C
   sw    $at, -4($t4)
  lui   $t7, %hi(ptrFirstFontTableSmall) 
  lui   $t6, %hi(ptrSecondFontTableSmall) 
  lw    $t7, %lo(ptrFirstFontTableSmall)($t7)
  lw    $t6, %lo(ptrSecondFontTableSmall)($t6)
  lui   $t0, %hi(D_800577C0) 
  addiu $t0, %lo(D_800577C0) # addiu $t0, $t0, 0x77c0
  sw    $zero, 0xd54($sp)
  sw    $zero, 0xd50($sp)
  addiu $t8, $t0, 0xbb8
  addiu $t2, $sp, 0x190
  sw    $t7, 0xd4c($sp)
  sw    $t6, 0xd48($sp)
.L7F0AC260:
  lw    $at, ($t0)
  addiu $t0, $t0, 0xc
  addiu $t2, $t2, 0xc
  sw    $at, -0xc($t2)
  lw    $at, -8($t0)
  sw    $at, -8($t2)
  lw    $at, -4($t0)
  bne   $t0, $t8, .L7F0AC260
   sw    $at, -4($t2)
  jal   get_textptr_for_textID
   li    $a0, 44072
  sw    $v0, 0x16c($sp)
  jal   get_textptr_for_textID
   li    $a0, 44073
  sw    $v0, 0x168($sp)
  jal   get_textptr_for_textID
   li    $a0, 44087
  sw    $v0, 0x164($sp)
  jal   get_ptr_text_for_watch_breifing_page
   move  $a0, $zero
  move  $s0, $v0
  jal   microcode_constructor
   lw    $a0, 0xde8($sp)
  lw    $t9, 0xd4c($sp)
  sw    $v0, 0xde8($sp)
  addiu $a0, $sp, 0xd54
  addiu $a1, $sp, 0xd50
  move  $a2, $s0
  lw    $a3, 0xd48($sp)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t9, 0x10($sp)
  lw    $v0, 0xd50($sp)
  li    $t5, 170
  lw    $t3, 0xd54($sp)
  subu  $v1, $t5, $v0
  bgez  $v1, .L7F0AC300
   sra   $t4, $v1, 1
  addiu $at, $v1, 1
  sra   $t4, $at, 1
.L7F0AC300:
  addiu $v1, $t4, 0x4b
  li    $t7, 30
  addiu $t8, $sp, 0xd58
  addu  $t6, $v1, $v0
  addiu $t1, $t3, 0x1e
  sw    $t7, 0xd60($sp)
  sw    $t6, 0xd5c($sp)
  sw    $t1, 0xd58($sp)
  sw    $t8, 0x10($sp)
  sw    $v1, 0xd64($sp)
  lw    $a0, 0xde8($sp)
  addiu $a1, $sp, 0xd64
  addiu $a2, $sp, 0xd60
  jal   draw_blackbox_to_screen
   addiu $a3, $sp, 0xd5c
  lw    $t0, 0xd48($sp)
  lw    $t2, 0xd4c($sp)
  lw    $t5, 0xd50($sp)
  lw    $t4, 0xd54($sp)
  lui   $t9, (0xA0FFA0F0 >> 16) # lui $t9, 0xa0ff
  ori   $t9, (0xA0FFA0F0 & 0xFFFF) # ori $t9, $t9, 0xa0f0
  sw    $t9, 0x18($sp)
  move  $a0, $v0
  addiu $a1, $sp, 0xd64
  addiu $a2, $sp, 0xd60
  move  $a3, $s0
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t0, 0x10($sp)
  sw    $t2, 0x14($sp)
  sw    $t5, 0x1c($sp)
  jal   en_text_write_stuff
   sw    $t4, 0x20($sp)
  lui   $t7, %hi(D_800409A0) 
  lw    $t7, %lo(D_800409A0)($t7)
  li    $v1, 65
  sw    $v0, 0xde8($sp)
  sltiu $at, $t7, 5
  beqz  $at, .L7F0AC8EC
   sw    $v1, 0xd64($sp)
  sll   $t7, $t7, 2
  lui   $at, %hi(jpt_80058570)
  addu  $at, $at, $t7
  lw    $t7, %lo(jpt_80058570)($at)
  jr    $t7
   nop   
.L7F0AC3B8:
  jal   get_textptr_for_textID
   li    $a0, 44088
  addiu $a0, $sp, 0x170
  jal   sprintf
   move  $a1, $v0
  jal   get_ptr_text_for_watch_breifing_page
   li    $a0, 1
  lw    $t6, 0xd4c($sp)
  li    $a0, 210
  move  $a1, $v0
  addiu $a2, $sp, 0x190
  lw    $a3, 0xd48($sp)
  jal   sub_GAME_7F0AEB64
   sw    $t6, 0x10($sp)
  jal   sub_GAME_7F0A6618
   nop   
  b     .L7F0AC8F0
   lw    $t2, 0xd4c($sp)
.L7F0AC400:
  jal   get_textptr_for_textID
   li    $a0, 44089
  addiu $a0, $sp, 0x170
  jal   sprintf
   move  $a1, $v0
  jal   get_ptr_text_for_watch_breifing_page
   li    $a0, 2
  lw    $t3, 0xd4c($sp)
  li    $a0, 210
  move  $a1, $v0
  addiu $a2, $sp, 0x190
  lw    $a3, 0xd48($sp)
  jal   sub_GAME_7F0AEB64
   sw    $t3, 0x10($sp)
  jal   sub_GAME_7F0A66A0
   nop   
  b     .L7F0AC8F0
   lw    $t2, 0xd4c($sp)
.L7F0AC448:
  jal   get_textptr_for_textID
   li    $a0, 44090
  addiu $a0, $sp, 0x170
  jal   sprintf
   move  $a1, $v0
  jal   get_ptr_text_for_watch_breifing_page
   li    $a0, 3
  lw    $t1, 0xd4c($sp)
  li    $a0, 210
  move  $a1, $v0
  addiu $a2, $sp, 0x190
  lw    $a3, 0xd48($sp)
  jal   sub_GAME_7F0AEB64
   sw    $t1, 0x10($sp)
  jal   sub_GAME_7F0A672C
   nop   
  b     .L7F0AC8F0
   lw    $t2, 0xd4c($sp)
.L7F0AC490:
  jal   get_textptr_for_textID
   li    $a0, 44091
  addiu $a0, $sp, 0x170
  jal   sprintf
   move  $a1, $v0
  jal   get_ptr_text_for_watch_breifing_page
   li    $a0, 4
  lw    $t8, 0xd4c($sp)
  li    $a0, 210
  move  $a1, $v0
  addiu $a2, $sp, 0x190
  lw    $a3, 0xd48($sp)
  jal   sub_GAME_7F0AEB64
   sw    $t8, 0x10($sp)
  jal   sub_GAME_7F0A67BC
   nop   
  b     .L7F0AC8F0
   lw    $t2, 0xd4c($sp)
.L7F0AC4D8:
  lui   $t0, %hi(D_80057FC0+0x3B8) 
  addiu $s1, $sp, 0x88
  addiu $t0, %lo(D_80057FC0+0x3B8) # addiu $t0, $t0, -0x7c88
  addiu $t5, $t0, 0xc0
  move  $t4, $s1
.L7F0AC4EC:
  lw    $at, ($t0)
  addiu $t0, $t0, 0xc
  addiu $t4, $t4, 0xc
  sw    $at, -0xc($t4)
  lw    $at, -8($t0)
  sw    $at, -8($t4)
  lw    $at, -4($t0)
  bne   $t0, $t5, .L7F0AC4EC
   sw    $at, -4($t4)
  lw    $at, ($t0)
  lui   $t7, %hi(j_text_trigger) 
  li    $s2, 1
  sw    $at, ($t4)
  lw    $t5, 4($t0)
  move  $s3, $zero
  li    $a0, 5
  sw    $t5, 4($t4)
  lw    $t7, %lo(j_text_trigger)($t7)
  sw    $zero, 0x74($sp)
  beqz  $t7, .L7F0AC548
   nop   
  b     .L7F0AC548
   li    $a0, 1
.L7F0AC548:
  jal   setTextOverlapCorrection
   nop   
  jal   get_textptr_for_textID
   li    $a0, 44092
  addiu $a0, $sp, 0x170
  jal   sprintf
   move  $a1, $v0
  jal   add_objective
   move  $fp, $zero
  blez  $v0, .L7F0AC8DC
   lui   $s7, %hi(D_80058454) 
  lui   $s6, %hi(D_80058450)
  lui   $s5, %hi(D_80058444)
  lui   $s4, %hi(D_80058440)
  addiu $s4, %lo(D_80058440) # addiu $s4, $s4, -0x7bc0
  addiu $s5, %lo(D_80058444) # addiu $s5, $s5, -0x7bbc
  addiu $s6, %lo(D_80058450) # addiu $s6, $s6, -0x7bb0
  addiu $s7, %lo(D_80058454) # addiu $s7, $s7, -0x7bac
.L7F0AC590:
  jal   get_difficulty_for_objective
   move  $a0, $fp
  jal   get_current_difficulty
   sw    $v0, 0x68($sp)
  lw    $a0, 0x68($sp)
  slt   $at, $v0, $a0
  bnez  $at, .L7F0AC8C8
   move  $a0, $fp
  jal   get_text_for_objective
   move  $s0, $zero
  sw    $v0, 0x78($sp)
  blez  $s2, .L7F0AC5E0
   sb    $zero, 0x88($sp)
  move  $a0, $s1
.L7F0AC5C8:
  jal   string_append_from_obseg_textbank
   move  $a1, $s4
  addiu $s0, $s0, 1
  bnel  $s0, $s2, .L7F0AC5C8
   move  $a0, $s1
  move  $s0, $zero
.L7F0AC5E0:
  blez  $s3, .L7F0AC600
   move  $a0, $s1
.L7F0AC5E8:
  jal   string_append_from_obseg_textbank
   move  $a1, $s5
  addiu $s0, $s0, 1
  bnel  $s0, $s3, .L7F0AC5E8
   move  $a0, $s1
  move  $s0, $zero
.L7F0AC600:
  jal   strlen
   move  $a0, $s1
  lw    $a2, 0x74($sp)
  addu  $a0, $v0, $s1
  lui   $a1, %hi(aC_2)
  sw    $a0, 0x6c($sp)
  addiu $a1, %lo(aC_2) # addiu $a1, $a1, -0x7bb8
  jal   sprintf
   addiu $a2, $a2, 0x61
  move  $a0, $s1
  jal   string_append_from_obseg_textbank
   lw    $a1, 0x78($sp)
  lui   $t6, %hi(j_text_trigger) 
  lw    $t6, %lo(j_text_trigger)($t6)
  lw    $t3, 0xd60($sp)
  li    $a0, 5
  beqz  $t6, .L7F0AC650
   li    $t8, 60
  b     .L7F0AC650
   li    $a0, 1
.L7F0AC650:
  addu  $t1, $a0, $t3
  sw    $t1, 0x154($sp)
  jal   get_video2_settings_txtClipW
   sw    $t8, 0x150($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x64($sp)
  lw    $t9, 0xd48($sp)
  lw    $t2, 0xd4c($sp)
  lh    $t0, 0x64($sp)
  lui   $t5, (0x00FF00B0 >> 16) # lui $t5, 0xff
  ori   $t5, (0x00FF00B0 & 0xFFFF) # ori $t5, $t5, 0xb0
  li    $t4, 10
  sw    $t4, 0x28($sp)
  sw    $t5, 0x18($sp)
  lw    $a0, 0xde8($sp)
  addiu $a1, $sp, 0x150
  addiu $a2, $sp, 0x154
  move  $a3, $s1
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $t9, 0x10($sp)
  sw    $t2, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t0, 0x1c($sp)
  sw    $v0, 0xde8($sp)
  jal   sub_GAME_7F0AC0E8
   lw    $a0, 0x6c($sp)
  addu  $s2, $s2, $v0
  jal   sub_GAME_7F0AC120
   lw    $a0, 0x6c($sp)
  lw    $t7, 0xd4c($sp)
  li    $t6, 10
  sw    $t6, 0x14($sp)
  addiu $a0, $sp, 0xd54
  addiu $a1, $sp, 0xd50
  move  $a2, $v0
  lw    $a3, 0xd48($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t7, 0x10($sp)
  jal   get_video2_settings_txtClipW
   nop   
  lw    $t1, 0xd50($sp)
  bgez  $v0, .L7F0AC708
   sra   $t3, $v0, 1
  addiu $at, $v0, 1
  sra   $t3, $at, 1
.L7F0AC708:
  addiu $t8, $t1, 0x3c
  slt   $at, $t8, $t3
  beqz  $at, .L7F0AC71C
   nop   
  addiu $s2, $s2, -1
.L7F0AC71C:
  blez  $s2, .L7F0AC740
   sb    $zero, 0x88($sp)
  move  $a0, $s1
.L7F0AC728:
  jal   string_append_from_obseg_textbank
   move  $a1, $s6
  addiu $s0, $s0, 1
  bnel  $s0, $s2, .L7F0AC728
   move  $a0, $s1
  move  $s0, $zero
.L7F0AC740:
  blez  $s3, .L7F0AC75C
   move  $a0, $s1
.L7F0AC748:
  jal   string_append_from_obseg_textbank
   move  $a1, $s7
  addiu $s0, $s0, 1
  bnel  $s0, $s3, .L7F0AC748
   move  $a0, $s1
.L7F0AC75C:
  jal   get_status_of_objective
   move  $a0, $fp
  beqz  $v0, .L7F0AC78C
   move  $a0, $s1
  li    $at, 1
  beq   $v0, $at, .L7F0AC7B4
   move  $a0, $s1
  li    $at, 2
  beq   $v0, $at, .L7F0AC7D0
   move  $a0, $s1
  b     .L7F0AC804
   lw    $t1, 0xd4c($sp)
.L7F0AC78C:
  jal   string_append_from_obseg_textbank
   lw    $a1, 0x168($sp)
  lui   $t9, %hi(D_80040AFC) 
  lw    $t9, %lo(D_80040AFC)($t9)
  lui   $at, (0x400040FF >> 16) # lui $at, 0x4000
  ori   $at, (0x400040FF & 0xFFFF) # ori $at, $at, 0x40ff
  sll   $t2, $t9, 0x10
  or    $t5, $t2, $at
  b     .L7F0AC800
   sw    $t5, 0x84($sp)
.L7F0AC7B4:
  lui   $t0, (0xA0FFA0F0 >> 16) # lui $t0, 0xa0ff
  ori   $t0, (0xA0FFA0F0 & 0xFFFF) # ori $t0, $t0, 0xa0f0
  sw    $t0, 0x84($sp)
  jal   string_append_from_obseg_textbank
   lw    $a1, 0x16c($sp)
  b     .L7F0AC804
   lw    $t1, 0xd4c($sp)
.L7F0AC7D0:
  jal   string_append_from_obseg_textbank
   lw    $a1, 0x164($sp)
  lui   $t4, %hi(j_text_trigger) 
  lw    $t4, %lo(j_text_trigger)($t4)
  lui   $t6, (0x00FF00B0 >> 16) # lui $t6, 0xff
  lui   $t7, (0xA0FFA0F0 >> 16) # lui $t7, 0xa0ff
  beqz  $t4, .L7F0AC7FC
   ori   $t6, (0x00FF00B0 & 0xFFFF) # ori $t6, $t6, 0xb0
  ori   $t7, (0xA0FFA0F0 & 0xFFFF) # ori $t7, $t7, 0xa0f0
  b     .L7F0AC800
   sw    $t7, 0x84($sp)
.L7F0AC7FC:
  sw    $t6, 0x84($sp)
.L7F0AC800:
  lw    $t1, 0xd4c($sp)
.L7F0AC804:
  li    $t3, 10
  sw    $t3, 0x14($sp)
  addiu $a0, $sp, 0xd54
  addiu $a1, $sp, 0xd50
  move  $a2, $s1
  lw    $a3, 0xd48($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t1, 0x10($sp)
  lui   $v0, %hi(j_text_trigger)
  lw    $v0, %lo(j_text_trigger)($v0)
  lw    $t8, 0xd60($sp)
  li    $a0, 5
  beqz  $v0, .L7F0AC844
   li    $t4, 175
  b     .L7F0AC844
   li    $a0, 1
.L7F0AC844:
  addu  $t9, $a0, $t8
  beqz  $v0, .L7F0AC864
   sw    $t9, 0x154($sp)
  lw    $t2, 0xd50($sp)
  li    $t5, 245
  subu  $t0, $t5, $t2
  b     .L7F0AC868
   sw    $t0, 0x150($sp)
.L7F0AC864:
  sw    $t4, 0x150($sp)
.L7F0AC868:
  jal   get_video2_settings_txtClipH
   nop   
  lw    $t7, 0xd48($sp)
  lw    $t6, 0xd4c($sp)
  lw    $t1, 0x84($sp)
  li    $t3, 210
  li    $t8, 10
  sw    $t8, 0x28($sp)
  sw    $t3, 0x1c($sp)
  lw    $a0, 0xde8($sp)
  addiu $a1, $sp, 0x150
  addiu $a2, $sp, 0x154
  move  $a3, $s1
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $t7, 0x10($sp)
  sw    $t6, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t1, 0x18($sp)
  lw    $t9, 0x74($sp)
  sw    $v0, 0xde8($sp)
  addiu $s3, $s3, 1
  addiu $t5, $t9, 1
  sw    $t5, 0x74($sp)
.L7F0AC8C8:
  jal   add_objective
   addiu $fp, $fp, 1
  slt   $at, $fp, $v0
  bnez  $at, .L7F0AC590
   nop   
.L7F0AC8DC:
  jal   setTextOverlapCorrection
   li    $a0, -1
  jal   sub_GAME_7F0A684C
   nop   
.L7F0AC8EC:
  lw    $t2, 0xd4c($sp)
.L7F0AC8F0:
  li    $t0, 10
  sw    $t0, 0x14($sp)
  addiu $a0, $sp, 0xd54
  addiu $a1, $sp, 0xd50
  addiu $a2, $sp, 0x170
  lw    $a3, 0xd48($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t2, 0x10($sp)
  lw    $t4, 0xd48($sp)
  lw    $t7, 0xd4c($sp)
  lui   $t6, (0xA0FFA0F0 >> 16) # lui $t6, 0xa0ff
  ori   $t6, (0xA0FFA0F0 & 0xFFFF) # ori $t6, $t6, 0xa0f0
  li    $t1, 210
  li    $t3, 130
  li    $t8, 10
  sw    $t8, 0x28($sp)
  sw    $t3, 0x20($sp)
  sw    $t1, 0x1c($sp)
  sw    $t6, 0x18($sp)
  lw    $a0, 0xde8($sp)
  addiu $a1, $sp, 0xd64
  addiu $a2, $sp, 0xd60
  addiu $a3, $sp, 0x170
  sw    $zero, 0x24($sp)
  sw    $t4, 0x10($sp)
  jal   en_text_write_stuff
   sw    $t7, 0x14($sp)
  lw    $t9, 0xd60($sp)
  lw    $t2, 0xd4c($sp)
  li    $v1, 60
  li    $t0, 10
  addiu $t5, $t9, 5
  sw    $v0, 0xde8($sp)
  sw    $t5, 0xd60($sp)
  sw    $t0, 0x14($sp)
  sw    $v1, 0xd64($sp)
  addiu $a0, $sp, 0xd54
  addiu $a1, $sp, 0xd50
  addiu $a2, $sp, 0x190
  lw    $a3, 0xd48($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t2, 0x10($sp)
  jal   get_video2_settings_txtClipW
   nop   
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x64($sp)
  lw    $t4, 0xd48($sp)
  lw    $t7, 0xd4c($sp)
  lh    $t1, 0x64($sp)
  lui   $t6, (0x00FF00B0 >> 16) # lui $t6, 0xff
  ori   $t6, (0x00FF00B0 & 0xFFFF) # ori $t6, $t6, 0xb0
  li    $t3, 10
  sw    $t3, 0x28($sp)
  sw    $t6, 0x18($sp)
  lw    $a0, 0xde8($sp)
  addiu $a1, $sp, 0xd64
  addiu $a2, $sp, 0xd60
  addiu $a3, $sp, 0x190
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $t4, 0x10($sp)
  sw    $t7, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t1, 0x1c($sp)
  sw    $v0, 0xde8($sp)
.L7F0AC9F4:
  lw    $ra, 0x5c($sp)
  lw    $v0, 0xde8($sp)
  lw    $s0, 0x38($sp)
  lw    $s1, 0x3c($sp)
  lw    $s2, 0x40($sp)
  lw    $s3, 0x44($sp)
  lw    $s4, 0x48($sp)
  lw    $s5, 0x4c($sp)
  lw    $s6, 0x50($sp)
  lw    $s7, 0x54($sp)
  lw    $fp, 0x58($sp)
  jr    $ra
   addiu $sp, $sp, 0xde8
");

asm(R"
.late_rodata
/*D:80058584*/
glabel jpt_80058584
.word .L7F0ACAD0
.word .L7F0ACAE4
.word .L7F0ACAF8
.word .L7F0ACB0C
.word .L7F0ACB20
.text
glabel sub_GAME_7F0ACA28
  addiu $sp, $sp, -0x20
  sw    $a1, 0x24($sp)
  sw    $s0, 0x18($sp)
  lui   $a1, %hi(pPlayer)
  lw    $a1, %lo(pPlayer)($a1)
  move  $s0, $a0
  sw    $ra, 0x1c($sp)
  lui   $a0, %hi(D_80040994)
  sw    $a2, 0x28($sp)
  lw    $a0, %lo(D_80040994)($a0)
  jal   sub_GAME_7F0A70AC
   addiu $a1, $a1, 0x1878
  lw    $v0, 0x28($sp)
  li    $at, 1
  bne   $v0, $at, .L7F0ACB34
   nop   
  jal   set_BONDdata_paused_flag
   move  $a0, $zero
  jal   sub_GAME_7F0BD8FC
   move  $a0, $zero
  lui   $t6, %hi(D_80040994) 
  lw    $t6, %lo(D_80040994)($t6)
  li    $at, 1
  move  $a0, $zero
  beq   $t6, $at, .L7F0ACAA8
   nop   
  jal   get_controller_buttons_pressed
   li    $a1, 40960
  beqz  $v0, .L7F0ACAA8
   nop   
  jal   sub_GAME_7F0A4EF8
   nop   
.L7F0ACAA8:
  lui   $t7, %hi(D_80040994) 
  lw    $t7, %lo(D_80040994)($t7)
  sltiu $at, $t7, 5
  beqz  $at, .L7F0ACB5C
   sll   $t7, $t7, 2
  lui   $at, %hi(jpt_80058584)
  addu  $at, $at, $t7
  lw    $t7, %lo(jpt_80058584)($at)
  jr    $t7
   nop   
.L7F0ACAD0:
  move  $a0, $s0
  jal   sub_GAME_7F0A830C
   lw    $a1, 0x24($sp)
  b     .L7F0ACB5C
   move  $s0, $v0
.L7F0ACAE4:
  move  $a0, $s0
  jal   debug_gun_watch_move_related2
   lw    $a1, 0x24($sp)
  b     .L7F0ACB5C
   move  $s0, $v0
.L7F0ACAF8:
  move  $a0, $s0
  jal   sub_GAME_7F0AB4B8
   lw    $a1, 0x24($sp)
  b     .L7F0ACB5C
   move  $s0, $v0
.L7F0ACB0C:
  move  $a0, $s0
  jal   sub_GAME_7F0ABDFC
   lw    $a1, 0x24($sp)
  b     .L7F0ACB5C
   move  $s0, $v0
.L7F0ACB20:
  move  $a0, $s0
  jal   sub_GAME_7F0AC168
   lw    $a1, 0x24($sp)
  b     .L7F0ACB5C
   move  $s0, $v0
.L7F0ACB34:
  bnezl $v0, .L7F0ACB60
   lw    $ra, 0x1c($sp)
  jal   sub_GAME_7F0BD8FC
   li    $a0, 1
  jal   set_BONDdata_paused_flag
   li    $a0, 1
  move  $a0, $s0
  jal   sub_GAME_7F0A77A8
   lw    $a1, 0x24($sp)
  move  $s0, $v0
.L7F0ACB5C:
  lw    $ra, 0x1c($sp)
.L7F0ACB60:
  move  $v0, $s0
  lw    $s0, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x20
");
