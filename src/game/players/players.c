// Probably a module that handles players.
#include "players.h"
#include "lvl.h"

int copyof_stagenum, dword_CODE_bss_80079E94;
char dword_CODE_bss_80079E98[0x48];
unsigned int *players_p1, *players_p2, *players_p3, *players_p4;

player_statistics player1_player_data, player2_player_data, player3_player_data,
    player4_player_data;

Player *pPlayer;

player_statistics *pPlayersPerm;

int player_num, random_byte, dword_CODE_bss_8007A0C0, dword_CODE_bss_8007A0C4,
    dword_CODE_bss_8007A0C8, dword_CODE_bss_8007A0CC;

asm(R"
glabel sub_GAME_7F093880
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  swc1  $f12, 0x28($sp)
  swc1  $f14, 0x2c($sp)
  jal   sub_GAME_7F078444
   sw    $a2, 0x30($sp)
  jal   getPlayer_c_screenleft
   sw    $v0, 0x24($sp)
  lwc1  $f4, 0x28($sp)
  add.s $f6, $f0, $f4
  jal   getPlayer_c_screentop
   swc1  $f6, 0x1c($sp)
  jal   get_ptr_currentdata
   swc1  $f0, 0x18($sp)
  lwc1  $f8, 0x2c($sp)
  lwc1  $f10, 0x18($sp)
  lwc1  $f18, 0x38($v0)
  addiu $a0, $sp, 0x1c
  add.s $f16, $f8, $f10
  lw    $a1, 0x30($sp)
  lui   $a2, 0x42c8
  add.s $f4, $f18, $f16
  jal   sub_GAME_7F077EEC
   swc1  $f4, 0x20($sp)
  lw    $a0, 0x24($sp)
  jal   sub_GAME_7F0583D8
   lw    $a1, 0x30($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80057520
.word 0x38d1b717 /*0.000099999997*/
glabel D_80057524
.word 0x3c23d70a /*0.0099999998*/
glabel D_80057528
.word 0x48927c00 /*300000.0*/

.text
glabel sub_GAME_7F0938FC
  addiu $sp, $sp, -0x38
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x14($sp)
  move  $s0, $a0
  sw    $s1, 0x18($sp)
  sw    $a1, 0x3c($sp)
  jal   get_BONDdata_position
   sw    $a2, 0x40($sp)
  lwc1  $f0, 8($s0)
  lwc1  $f14, ($s0)
  lui   $at, %hi(D_80057520)
  mul.s $f4, $f0, $f0
  lwc1  $f10, %lo(D_80057520)($at)
  move  $s1, $v0
  mul.s $f6, $f14, $f14
  add.s $f8, $f4, $f6
  jal   sqrtf
   add.s $f12, $f8, $f10
  lwc1  $f2, 4($s0)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f14
  add.s $f4, $f2, $f2
  lui   $at, %hi(D_80057524)
  move  $v0, $zero
  div.s $f12, $f4, $f0
  c.lt.s $f14, $f12
  nop   
  bc1fl .L7F093978
   sub.s $f6, $f14, $f12
  mov.s $f12, $f14
  sub.s $f6, $f14, $f12
.L7F093978:
  lw    $t6, 0x40($sp)
  mtc1  $zero, $f0
  swc1  $f6, ($t6)
  lwc1  $f2, 4($s0)
  c.eq.s $f0, $f2
  nop   
  bc1fl .L7F0939A4
   mov.s $f16, $f2
  b     .L7F0939A4
   lwc1  $f16, %lo(D_80057524)($at)
  mov.s $f16, $f2
.L7F0939A4:
  c.lt.s $f0, $f16
  nop   
  bc1f  .L7F093A64
   nop   
  jal   get_ptr_currentdata
   swc1  $f16, 0x24($sp)
  lwc1  $f8, 0xc($v0)
  lwc1  $f10, 4($s1)
  lwc1  $f16, 0x24($sp)
  lwc1  $f0, 8($s0)
  sub.s $f4, $f8, $f10
  lwc1  $f14, ($s0)
  mul.s $f6, $f0, $f0
  nop   
  mul.s $f8, $f14, $f14
  div.s $f2, $f4, $f16
  add.s $f12, $f6, $f8
  jal   sqrtf
   swc1  $f2, 0x2c($sp)
  lwc1  $f2, 0x2c($sp)
  lui   $at, %hi(D_80057528)
  lwc1  $f18, %lo(D_80057528)($at)
  mul.s $f12, $f0, $f2
  lwc1  $f16, 0x24($sp)
  c.lt.s $f18, $f12
  nop   
  bc1fl .L7F093A24
   lwc1  $f4, ($s0)
  div.s $f10, $f18, $f12
  mul.s $f2, $f2, $f10
  nop   
  lwc1  $f4, ($s0)
.L7F093A24:
  lwc1  $f8, ($s1)
  lw    $v1, 0x3c($sp)
  mul.s $f6, $f4, $f2
  li    $v0, 1
  add.s $f10, $f6, $f8
  mul.s $f6, $f2, $f16
  swc1  $f10, ($v1)
  lwc1  $f4, 4($s1)
  add.s $f8, $f4, $f6
  swc1  $f8, 4($v1)
  lwc1  $f10, 8($s0)
  lwc1  $f6, 8($s1)
  mul.s $f4, $f10, $f2
  add.s $f8, $f4, $f6
  b     .L7F093A64
   swc1  $f8, 8($v1)
.L7F093A64:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x38
");

asm(R"
.late_rodata
glabel D_8005752C
.word 0x38d1b717 /*0.000099999997*/
glabel D_80057530
.word 0xbc23d70a /*-0.01*/
glabel D_80057534
.word 0x48927c00 /*300000.0*/

.text
glabel sub_GAME_7F093A78
  addiu $sp, $sp, -0x38
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x14($sp)
  move  $s0, $a0
  sw    $s1, 0x18($sp)
  sw    $a1, 0x3c($sp)
  jal   get_BONDdata_position
   sw    $a2, 0x40($sp)
  lwc1  $f0, 8($s0)
  lwc1  $f14, ($s0)
  lui   $at, %hi(D_8005752C)
  mul.s $f4, $f0, $f0
  lwc1  $f10, %lo(D_8005752C)($at)
  move  $s1, $v0
  mul.s $f6, $f14, $f14
  add.s $f8, $f4, $f6
  jal   sqrtf
   add.s $f12, $f8, $f10
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f12
  li    $at, 0xC0000000 # -2.000000
  mtc1  $at, $f4
  lwc1  $f6, 4($s0)
  lui   $at, %hi(D_80057530)
  move  $v0, $zero
  mul.s $f8, $f4, $f6
  div.s $f2, $f8, $f0
  c.lt.s $f12, $f2
  nop   
  bc1fl .L7F093AFC
   sub.s $f10, $f12, $f2
  mov.s $f2, $f12
  sub.s $f10, $f12, $f2
.L7F093AFC:
  lw    $t6, 0x40($sp)
  mtc1  $zero, $f14
  swc1  $f10, ($t6)
  lwc1  $f0, 4($s0)
  c.eq.s $f14, $f0
  nop   
  bc1fl .L7F093B28
   mov.s $f16, $f0
  b     .L7F093B28
   lwc1  $f16, %lo(D_80057530)($at)
  mov.s $f16, $f0
.L7F093B28:
  c.lt.s $f16, $f14
  nop   
  bc1f  .L7F093BE8
   nop   
  jal   get_ptr_currentdata
   swc1  $f16, 0x24($sp)
  lwc1  $f4, 0x24($v0)
  lwc1  $f6, 4($s1)
  lwc1  $f16, 0x24($sp)
  lwc1  $f0, 8($s0)
  sub.s $f8, $f4, $f6
  lwc1  $f14, ($s0)
  mul.s $f10, $f0, $f0
  nop   
  mul.s $f4, $f14, $f14
  div.s $f2, $f8, $f16
  add.s $f12, $f10, $f4
  jal   sqrtf
   swc1  $f2, 0x2c($sp)
  lwc1  $f2, 0x2c($sp)
  lui   $at, %hi(D_80057534)
  lwc1  $f18, %lo(D_80057534)($at)
  mul.s $f12, $f0, $f2
  lwc1  $f16, 0x24($sp)
  c.lt.s $f18, $f12
  nop   
  bc1fl .L7F093BA8
   lwc1  $f8, ($s0)
  div.s $f6, $f18, $f12
  mul.s $f2, $f2, $f6
  nop   
  lwc1  $f8, ($s0)
.L7F093BA8:
  lwc1  $f4, ($s1)
  lw    $v1, 0x3c($sp)
  mul.s $f10, $f8, $f2
  li    $v0, 1
  add.s $f6, $f10, $f4
  mul.s $f10, $f2, $f16
  swc1  $f6, ($v1)
  lwc1  $f8, 4($s1)
  add.s $f4, $f8, $f10
  swc1  $f4, 4($v1)
  lwc1  $f6, 8($s0)
  lwc1  $f10, 8($s1)
  mul.s $f8, $f6, $f2
  add.s $f4, $f8, $f10
  b     .L7F093BE8
   swc1  $f4, 8($v1)
.L7F093BE8:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x38
");

asm(R"
glabel sub_GAME_7F093BFC
  lwc1  $f2, 4($a0)
  lwc1  $f4, 4($a1)
  lwc1  $f12, ($a0)
  lwc1  $f8, ($a1)
  sub.s $f6, $f2, $f4
  mtc1  $zero, $f4
  sub.s $f10, $f8, $f12
  swc1  $f4, 4($a2)
  div.s $f0, $f2, $f6
  mul.s $f16, $f10, $f0
  add.s $f18, $f16, $f12
  swc1  $f18, ($a2)
  lwc1  $f6, 8($a1)
  lwc1  $f14, 8($a0)
  sub.s $f8, $f6, $f14
  mul.s $f10, $f8, $f0
  add.s $f16, $f10, $f14
  jr    $ra
   swc1  $f16, 8($a2)
");

float sub_GAME_7F093C48(float arg0, float arg1, float arg2) {
  if (arg0 < arg1)
    return arg1;
  if (arg2 < arg0)
    return arg2;
  return arg0;
}

float addpoint5tofloat(float arg0) { return (float)(int)(arg0 + 0.5f); }

asm(R"
glabel sub_GAME_7F093CB0
  addiu $sp, $sp, -0x30
  sw    $ra, 0x14($sp)
  sw    $a0, 0x30($sp)
  jal   get_ptr_currentdata
   sw    $a1, 0x34($sp)
  lbu   $t6, 8($v0)
  mtc1  $t6, $f4
  bgez  $t6, .L7F093CE4
   cvt.s.w $f6, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F093CE4:
  jal   get_ptr_currentdata
   swc1  $f6, 0x2c($sp)
  lbu   $t7, 9($v0)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t7, $f10
  bgez  $t7, .L7F093D0C
   cvt.s.w $f16, $f10
  mtc1  $at, $f18
  nop   
  add.s $f16, $f16, $f18
.L7F093D0C:
  jal   get_ptr_currentdata
   swc1  $f16, 0x28($sp)
  lbu   $t8, 0xa($v0)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t8, $f4
  bgez  $t8, .L7F093D34
   cvt.s.w $f8, $f4
  mtc1  $at, $f6
  nop   
  add.s $f8, $f8, $f6
.L7F093D34:
  jal   get_ptr_currentdata
   swc1  $f8, 0x24($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f2
  li    $at, 0x437F0000 # 255.000000
  mtc1  $at, $f16
  lwc1  $f12, 0x2c($sp)
  lwc1  $f18, 0x14($v0)
  lwc1  $f10, 0x34($sp)
  div.s $f4, $f12, $f16
  li    $t0, 1
  li    $at, 0x4F000000 # 2147483648.000000
  lw    $t1, 0x30($sp)
  sub.s $f0, $f2, $f10
  sub.s $f6, $f2, $f4
  mul.s $f8, $f18, $f6
  nop   
  mul.s $f10, $f8, $f0
  add.s $f16, $f10, $f12
  cfc1  $t9, $31
  ctc1  $t0, $31
  nop   
  cvt.w.s $f4, $f16
  cfc1  $t0, $31
  nop   
  andi  $t0, $t0, 0x78
  beqz  $t0, .L7F093DE8
   nop   
  mtc1  $at, $f4
  li    $t0, 1
  sub.s $f4, $f16, $f4
  ctc1  $t0, $31
  nop   
  cvt.w.s $f4, $f4
  cfc1  $t0, $31
  nop   
  andi  $t0, $t0, 0x78
  bnez  $t0, .L7F093DE0
   nop   
  mfc1  $t0, $f4
  lui   $at, 0x8000
  b     .L7F093DF8
   or    $t0, $t0, $at
.L7F093DE0:
  b     .L7F093DF8
   li    $t0, -1
.L7F093DE8:
  mfc1  $t0, $f4
  nop   
  bltz  $t0, .L7F093DE0
   nop   
.L7F093DF8:
  ctc1  $t9, $31
  sb    $t0, 0x14($t1)
  jal   get_ptr_currentdata
   swc1  $f0, 0x1c($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f18
  li    $at, 0x437F0000 # 255.000000
  mtc1  $at, $f6
  lwc1  $f0, 0x28($sp)
  lwc1  $f16, 0x18($v0)
  li    $t3, 1
  div.s $f8, $f0, $f6
  lwc1  $f6, 0x1c($sp)
  li    $at, 0x4F000000 # 2147483648.000000
  lw    $t4, 0x30($sp)
  sub.s $f10, $f18, $f8
  mul.s $f4, $f16, $f10
  nop   
  mul.s $f18, $f4, $f6
  add.s $f8, $f18, $f0
  cfc1  $t2, $31
  ctc1  $t3, $31
  nop   
  cvt.w.s $f16, $f8
  cfc1  $t3, $31
  nop   
  andi  $t3, $t3, 0x78
  beqz  $t3, .L7F093EB0
   nop   
  mtc1  $at, $f16
  li    $t3, 1
  sub.s $f16, $f8, $f16
  ctc1  $t3, $31
  nop   
  cvt.w.s $f16, $f16
  cfc1  $t3, $31
  nop   
  andi  $t3, $t3, 0x78
  bnez  $t3, .L7F093EA8
   nop   
  mfc1  $t3, $f16
  lui   $at, 0x8000
  b     .L7F093EC0
   or    $t3, $t3, $at
.L7F093EA8:
  b     .L7F093EC0
   li    $t3, -1
.L7F093EB0:
  mfc1  $t3, $f16
  nop   
  bltz  $t3, .L7F093EA8
   nop   
.L7F093EC0:
  ctc1  $t2, $31
  jal   get_ptr_currentdata
   sb    $t3, 0x15($t4)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  li    $at, 0x437F0000 # 255.000000
  mtc1  $at, $f4
  lwc1  $f0, 0x24($sp)
  lwc1  $f8, 0x1c($v0)
  li    $t6, 1
  div.s $f6, $f0, $f4
  lwc1  $f4, 0x1c($sp)
  li    $at, 0x4F000000 # 2147483648.000000
  lw    $t7, 0x30($sp)
  li    $t8, 255
  sub.s $f18, $f10, $f6
  mul.s $f16, $f8, $f18
  nop   
  mul.s $f10, $f16, $f4
  add.s $f6, $f10, $f0
  cfc1  $t5, $31
  ctc1  $t6, $31
  nop   
  cvt.w.s $f8, $f6
  cfc1  $t6, $31
  nop   
  andi  $t6, $t6, 0x78
  beqz  $t6, .L7F093F78
   nop   
  mtc1  $at, $f8
  li    $t6, 1
  sub.s $f8, $f6, $f8
  ctc1  $t6, $31
  nop   
  cvt.w.s $f8, $f8
  cfc1  $t6, $31
  nop   
  andi  $t6, $t6, 0x78
  bnez  $t6, .L7F093F70
   nop   
  mfc1  $t6, $f8
  lui   $at, 0x8000
  b     .L7F093F88
   or    $t6, $t6, $at
.L7F093F70:
  b     .L7F093F88
   li    $t6, -1
.L7F093F78:
  mfc1  $t6, $f8
  nop   
  bltz  $t6, .L7F093F70
   nop   
.L7F093F88:
  sb    $t6, 0x16($t7)
  sb    $t8, 0x17($t7)
  lw    $ra, 0x14($sp)
  ctc1  $t5, $31
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F093FA4
  addiu $sp, $sp, -0x30
  sw    $ra, 0x14($sp)
  sw    $a0, 0x30($sp)
  jal   get_ptr_currentdata
   sw    $a1, 0x34($sp)
  lbu   $t6, 8($v0)
  mtc1  $t6, $f4
  bgez  $t6, .L7F093FD8
   cvt.s.w $f6, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F093FD8:
  jal   get_ptr_currentdata
   swc1  $f6, 0x2c($sp)
  lbu   $t7, 9($v0)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t7, $f10
  bgez  $t7, .L7F094000
   cvt.s.w $f16, $f10
  mtc1  $at, $f18
  nop   
  add.s $f16, $f16, $f18
.L7F094000:
  jal   get_ptr_currentdata
   swc1  $f16, 0x28($sp)
  lbu   $t8, 0xa($v0)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t8, $f4
  bgez  $t8, .L7F094028
   cvt.s.w $f8, $f4
  mtc1  $at, $f6
  nop   
  add.s $f8, $f8, $f6
.L7F094028:
  jal   get_ptr_currentdata
   swc1  $f8, 0x24($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f2
  li    $at, 0x437F0000 # 255.000000
  mtc1  $at, $f16
  lwc1  $f12, 0x2c($sp)
  lwc1  $f18, 0x2c($v0)
  lwc1  $f10, 0x34($sp)
  div.s $f4, $f12, $f16
  li    $t0, 1
  li    $at, 0x4F000000 # 2147483648.000000
  lw    $t1, 0x30($sp)
  sub.s $f0, $f2, $f10
  sub.s $f6, $f2, $f4
  mul.s $f8, $f18, $f6
  nop   
  mul.s $f10, $f8, $f0
  add.s $f16, $f10, $f12
  cfc1  $t9, $31
  ctc1  $t0, $31
  nop   
  cvt.w.s $f4, $f16
  cfc1  $t0, $31
  nop   
  andi  $t0, $t0, 0x78
  beqz  $t0, .L7F0940DC
   nop   
  mtc1  $at, $f4
  li    $t0, 1
  sub.s $f4, $f16, $f4
  ctc1  $t0, $31
  nop   
  cvt.w.s $f4, $f4
  cfc1  $t0, $31
  nop   
  andi  $t0, $t0, 0x78
  bnez  $t0, .L7F0940D4
   nop   
  mfc1  $t0, $f4
  lui   $at, 0x8000
  b     .L7F0940EC
   or    $t0, $t0, $at
.L7F0940D4:
  b     .L7F0940EC
   li    $t0, -1
.L7F0940DC:
  mfc1  $t0, $f4
  nop   
  bltz  $t0, .L7F0940D4
   nop   
.L7F0940EC:
  ctc1  $t9, $31
  sb    $t0, 0x14($t1)
  jal   get_ptr_currentdata
   swc1  $f0, 0x1c($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f18
  li    $at, 0x437F0000 # 255.000000
  mtc1  $at, $f6
  lwc1  $f0, 0x28($sp)
  lwc1  $f16, 0x30($v0)
  li    $t3, 1
  div.s $f8, $f0, $f6
  lwc1  $f6, 0x1c($sp)
  li    $at, 0x4F000000 # 2147483648.000000
  lw    $t4, 0x30($sp)
  sub.s $f10, $f18, $f8
  mul.s $f4, $f16, $f10
  nop   
  mul.s $f18, $f4, $f6
  add.s $f8, $f18, $f0
  cfc1  $t2, $31
  ctc1  $t3, $31
  nop   
  cvt.w.s $f16, $f8
  cfc1  $t3, $31
  nop   
  andi  $t3, $t3, 0x78
  beqz  $t3, .L7F0941A4
   nop   
  mtc1  $at, $f16
  li    $t3, 1
  sub.s $f16, $f8, $f16
  ctc1  $t3, $31
  nop   
  cvt.w.s $f16, $f16
  cfc1  $t3, $31
  nop   
  andi  $t3, $t3, 0x78
  bnez  $t3, .L7F09419C
   nop   
  mfc1  $t3, $f16
  lui   $at, 0x8000
  b     .L7F0941B4
   or    $t3, $t3, $at
.L7F09419C:
  b     .L7F0941B4
   li    $t3, -1
.L7F0941A4:
  mfc1  $t3, $f16
  nop   
  bltz  $t3, .L7F09419C
   nop   
.L7F0941B4:
  ctc1  $t2, $31
  jal   get_ptr_currentdata
   sb    $t3, 0x15($t4)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  li    $at, 0x437F0000 # 255.000000
  mtc1  $at, $f4
  lwc1  $f0, 0x24($sp)
  lwc1  $f8, 0x34($v0)
  li    $t6, 1
  div.s $f6, $f0, $f4
  lwc1  $f4, 0x1c($sp)
  li    $at, 0x4F000000 # 2147483648.000000
  lw    $t7, 0x30($sp)
  li    $t8, 255
  sub.s $f18, $f10, $f6
  mul.s $f16, $f8, $f18
  nop   
  mul.s $f10, $f16, $f4
  add.s $f6, $f10, $f0
  cfc1  $t5, $31
  ctc1  $t6, $31
  nop   
  cvt.w.s $f8, $f6
  cfc1  $t6, $31
  nop   
  andi  $t6, $t6, 0x78
  beqz  $t6, .L7F09426C
   nop   
  mtc1  $at, $f8
  li    $t6, 1
  sub.s $f8, $f6, $f8
  ctc1  $t6, $31
  nop   
  cvt.w.s $f8, $f8
  cfc1  $t6, $31
  nop   
  andi  $t6, $t6, 0x78
  bnez  $t6, .L7F094264
   nop   
  mfc1  $t6, $f8
  lui   $at, 0x8000
  b     .L7F09427C
   or    $t6, $t6, $at
.L7F094264:
  b     .L7F09427C
   li    $t6, -1
.L7F09426C:
  mfc1  $t6, $f8
  nop   
  bltz  $t6, .L7F094264
   nop   
.L7F09427C:
  sb    $t6, 0x16($t7)
  sb    $t8, 0x17($t7)
  lw    $ra, 0x14($sp)
  ctc1  $t5, $31
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80057538
.word 0x46ffffcd /*32767.9*/
glabel D_8005753C
.word 0xc6ffffcd /*-32767.9*/
glabel D_80057540
.word 0x3dcccccd /*0.1*/

.text
glabel sub_GAME_7F094298
  lui   $at, %hi(D_80057538)
  lwc1  $f0, %lo(D_80057538)($at)
  mtc1  $zero, $f4
  lui   $at, %hi(D_8005753C)
  c.lt.s $f0, $f12
  nop   
  bc1f  .L7F0942BC
   nop   
  mov.s $f12, $f0
.L7F0942BC:
  lwc1  $f0, %lo(D_8005753C)($at)
  li    $at, 0x47800000 # 65536.000000
  c.lt.s $f12, $f0
  nop   
  bc1fl .L7F0942DC
   c.lt.s $f12, $f4
  mov.s $f12, $f0
  c.lt.s $f12, $f4
.L7F0942DC:
  nop   
  bc1fl .L7F094394
   mtc1  $at, $f16
  li    $at, 0xC7800000 # -65536.000000
  mtc1  $at, $f6
  li    $v1, 1
  li    $at, 0x4F000000 # 2147483648.000000
  mul.s $f8, $f12, $f6
  cfc1  $t6, $31
  ctc1  $v1, $31
  nop   
  cvt.w.s $f10, $f8
  cfc1  $v1, $31
  nop   
  andi  $v1, $v1, 0x78
  beql  $v1, $zero, .L7F094378
   mfc1  $v1, $f10
  mtc1  $at, $f10
  li    $v1, 1
  sub.s $f10, $f8, $f10
  ctc1  $v1, $31
  nop   
  cvt.w.s $f10, $f10
  cfc1  $v1, $31
  nop   
  andi  $v1, $v1, 0x78
  bnezl $v1, .L7F094368
   li    $v1, -1
  mfc1  $v1, $f10
  lui   $at, 0x8000
  ctc1  $t6, $31
  or    $v1, $v1, $at
  jr    $ra
   negu  $v0, $v1

  li    $v1, -1
.L7F094368:
  ctc1  $t6, $31
  jr    $ra
   negu  $v0, $v1

  mfc1  $v1, $f10
.L7F094378:
  nop   
  bltzl $v1, .L7F094368
   li    $v1, -1
  ctc1  $t6, $31
  jr    $ra
   negu  $v0, $v1

  mtc1  $at, $f16
.L7F094394:
  li    $v1, 1
  li    $at, 0x4F000000 # 2147483648.000000
  mul.s $f18, $f16, $f12
  cfc1  $t7, $31
  ctc1  $v1, $31
  nop   
  cvt.w.s $f4, $f18
  cfc1  $v1, $31
  nop   
  andi  $v1, $v1, 0x78
  beql  $v1, $zero, .L7F09440C
   mfc1  $v1, $f4
  mtc1  $at, $f4
  li    $v1, 1
  sub.s $f4, $f18, $f4
  ctc1  $v1, $31
  nop   
  cvt.w.s $f4, $f4
  cfc1  $v1, $31
  nop   
  andi  $v1, $v1, 0x78
  bnez  $v1, .L7F094400
   nop   
  mfc1  $v1, $f4
  lui   $at, 0x8000
  b     .L7F094418
   or    $v1, $v1, $at
.L7F094400:
  b     .L7F094418
   li    $v1, -1
  mfc1  $v1, $f4
.L7F09440C:
  nop   
  bltz  $v1, .L7F094400
   nop   
.L7F094418:
  ctc1  $t7, $31
  nop   
  nop   
  jr    $ra
   move  $v0, $v1
");

extern float D_8003FD94[];

void store_stagenum_to_copyof_stagenum(int stagenum) {
  copyof_stagenum = stagenum;
}

void sub_GAME_7F094438(void) {
  D_8003FD94[0] = (clock_timer + D_8003FD94[0]);
  if (D_8003FD94[0] > 4096.0f)
    D_8003FD94[0] -= 4096.0f;
}

asm(R"
.late_rodata
/*D:80057544*/
glabel jpt_80057544
.word .L7F094A48
.word .L7F095284
.word .L7F0953CC
.word .L7F094B4C
.word .L7F095514
.word .L7F094E60
.word .L7F0957A4
.word .L7F0951BC
.word .L7F09565C
.word .L7F0957A4
.word .L7F094D5C
.word .L7F0950F4
.word .L7F094C50
.word .L7F09502C
.word .L7F094F64
.word .L7F094A40

glabel D_80057584
.word 0x477fff00 /*65535.0*/
glabel D_80057588
.word 0x449fe000 /*1279.0*/
glabel D_8005758C
.word 0x446fc000 /*959.0*/

/*D:80057590*/
glabel jpt_80057590
.word .L7F095E14
.word .L7F09643C
.word .L7F09652C
.word .L7F096094
.word .L7F09661C
.word .L7F0961CC
.word .L7F096E20
.word .L7F096C98
.word .L7F09670C
.word .L7F096E20
.word .L7F096304
.word .L7F096B10
.word .L7F095F58
.word .L7F096984
.word .L7F0967FC
.word .L7F095E1C

glabel D_800575D0
.word 0x477fff00 /*65535.0*/
glabel D_800575D4
.word 0x46fffe00 /*32767.0*/
glabel D_800575D8
.word 0x46fffe00 /*32767.0*/
glabel D_800575DC
.word 0x43ff8000 /*511.0*/
glabel D_800575E0
.word 0xc57fa000 /*-4090.0*/
glabel D_800575E4
.word 0xc57fa000 /*-4090.0*/

.text
glabel sub_GAME_7F094488
  addiu $sp, $sp, -0x6b0
  sw    $ra, 0x4c($sp)
  sw    $s1, 0x48($sp)
  sw    $s0, 0x44($sp)
  sdc1  $f28, 0x38($sp)
  sdc1  $f26, 0x30($sp)
  sdc1  $f24, 0x28($sp)
  sdc1  $f22, 0x20($sp)
  sdc1  $f20, 0x18($sp)
  jal   get_room_data_float1
   sw    $a0, 0x6b0($sp)
  li    $at, 0x41F00000 # 30.000000
  mtc1  $at, $f4
  sw    $zero, 0x430($sp)
  jal   get_ptr_currentdata
   div.s $f24, $f0, $f4
  jal   get_ptr_currentdata
   move  $s0, $v0
  lbu   $t6, 0xb($v0)
  lw    $a0, 0x6b0($sp)
  bnezl $t6, .L7F0946C8
   lbu   $a1, 8($s0)
  jal   getPlayerCount
   nop   
  li    $at, 1
  bne   $v0, $at, .L7F0945DC
   lui   $t0, %hi(pPlayer) 
  lw    $t7, 0x6b0($sp)
  lui   $t9, (0xBA001402 >> 16) # lui $t9, 0xba00
  ori   $t9, (0xBA001402 & 0xFFFF) # ori $t9, $t9, 0x1402
  addiu $t8, $t7, 8
  sw    $t8, 0x6b0($sp)
  lui   $t2, 0x30
  sw    $t2, 4($t7)
  sw    $t9, ($t7)
  lbu   $a3, 0xa($s0)
  lbu   $a2, 9($s0)
  lbu   $a1, 8($s0)
  jal   set_setfillcolor
   lw    $a0, 0x6b0($sp)
  addiu $t3, $v0, 8
  sw    $t3, 0x6b0($sp)
  jal   get_video2_settings_width
   move  $s1, $v0
  jal   get_video2_settings_ulx
   sh    $v0, 0x7a($sp)
  jal   get_video2_settings_uly
   sh    $v0, 0x7c($sp)
  sll   $s0, $v0, 0x10
  sra   $t4, $s0, 0x10
  jal   get_video2_settings_height
   move  $s0, $t4
  lh    $t5, 0x7c($sp)
  lh    $t6, 0x7a($sp)
  addu  $t3, $v0, $s0
  addiu $t4, $t3, -1
  addu  $t7, $t5, $t6
  addiu $t8, $t7, -1
  andi  $t5, $t4, 0x3ff
  sll   $t6, $t5, 2
  andi  $t9, $t8, 0x3ff
  lui   $at, 0xf600
  or    $t7, $t6, $at
  sll   $t2, $t9, 0xe
  or    $t8, $t7, $t2
  jal   get_video2_settings_ulx
   sw    $t8, ($s1)
  sll   $s0, $v0, 0x10
  sra   $t9, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t9
  andi  $t3, $v0, 0x3ff
  andi  $t5, $s0, 0x3ff
  sll   $t6, $t5, 0xe
  sll   $t4, $t3, 2
  or    $t7, $t4, $t6
  sw    $t7, 4($s1)
  lw    $t2, 0x6b0($sp)
  lui   $t9, 0xe700
  addiu $t8, $t2, 8
  sw    $t8, 0x6b0($sp)
  sw    $zero, 4($t2)
  sw    $t9, ($t2)
  b     .L7F097360
   lw    $v0, 0x6b0($sp)
.L7F0945DC:
  lw    $t3, 0x6b0($sp)
  lui   $t1, 0xe700
  lui   $t7, (0xBA001402 >> 16) # lui $t7, 0xba00
  addiu $t5, $t3, 8
  sw    $t5, 0x6b0($sp)
  sw    $zero, 4($t3)
  sw    $t1, ($t3)
  lw    $t4, 0x6b0($sp)
  ori   $t7, (0xBA001402 & 0xFFFF) # ori $t7, $t7, 0x1402
  lui   $t2, 0x30
  addiu $t6, $t4, 8
  sw    $t6, 0x6b0($sp)
  sw    $t2, 4($t4)
  sw    $t7, ($t4)
  lw    $t8, 0x6b0($sp)
  lui   $t3, (0xB900031D >> 16) # lui $t3, 0xb900
  ori   $t3, (0xB900031D & 0xFFFF) # ori $t3, $t3, 0x31d
  addiu $t9, $t8, 8
  sw    $t9, 0x6b0($sp)
  sw    $zero, 4($t8)
  sw    $t3, ($t8)
  lw    $a2, 0x6b0($sp)
  addiu $t0, %lo(pPlayer) # addiu $t0, $t0, -0x5f50
  lw    $v0, ($t0)
  addiu $t4, $a2, 8
  sw    $t4, 0x6b0($sp)
  lh    $t6, 0x7f4($v0)
  lh    $t7, 0x7f0($v0)
  lh    $t4, 0x7f6($v0)
  lui   $at, 0xf600
  addu  $t2, $t6, $t7
  lh    $t6, 0x7f2($v0)
  addiu $t8, $t2, -1
  andi  $t9, $t8, 0x3ff
  addu  $t7, $t4, $t6
  addiu $t2, $t7, -1
  sll   $t3, $t9, 0xe
  andi  $t8, $t2, 0x3ff
  sll   $t9, $t8, 2
  or    $t5, $t3, $at
  or    $t3, $t5, $t9
  sw    $t3, ($a2)
  lw    $v0, ($t0)
  lh    $t4, 0x7f4($v0)
  lh    $t2, 0x7f6($v0)
  andi  $t6, $t4, 0x3ff
  andi  $t8, $t2, 0x3ff
  sll   $t5, $t8, 2
  sll   $t7, $t6, 0xe
  or    $t9, $t7, $t5
  sw    $t9, 4($a2)
  lw    $t3, 0x6b0($sp)
  addiu $t4, $t3, 8
  sw    $t4, 0x6b0($sp)
  sw    $zero, 4($t3)
  sw    $t1, ($t3)
  b     .L7F097360
   lw    $v0, 0x6b0($sp)
  lbu   $a1, 8($s0)
.L7F0946C8:
  lbu   $a2, 9($s0)
  jal   set_setfillcolor
   lbu   $a3, 0xa($s0)
  mtc1  $zero, $f12
  addiu $s1, $sp, 0x6a4
  sw    $v0, 0x6b0($sp)
  move  $a2, $s1
  jal   sub_GAME_7F093880
   mov.s $f14, $f12
  jal   getPlayer_c_screenwidth
   nop   
  lui   $at, %hi(D_80057540)
  lwc1  $f28, %lo(D_80057540)($at)
  mtc1  $zero, $f14
  addiu $a2, $sp, 0x698
  jal   sub_GAME_7F093880
   sub.s $f12, $f0, $f28
  jal   getPlayer_c_screenheight
   nop   
  mtc1  $zero, $f12
  sub.s $f14, $f0, $f28
  jal   sub_GAME_7F093880
   addiu $a2, $sp, 0x68c
  jal   getPlayer_c_screenwidth
   nop   
  jal   getPlayer_c_screenheight
   mov.s $f22, $f0
  sub.s $f12, $f22, $f28
  addiu $a2, $sp, 0x680
  jal   sub_GAME_7F093880
   sub.s $f14, $f0, $f28
  move  $a0, $s1
  addiu $a1, $sp, 0x644
  jal   sub_GAME_7F0938FC
   addiu $a2, $sp, 0x58c
  sw    $v0, 0x538($sp)
  addiu $a0, $sp, 0x698
  addiu $a1, $sp, 0x638
  jal   sub_GAME_7F0938FC
   addiu $a2, $sp, 0x588
  sw    $v0, 0x534($sp)
  addiu $a0, $sp, 0x68c
  addiu $a1, $sp, 0x62c
  jal   sub_GAME_7F0938FC
   addiu $a2, $sp, 0x584
  sw    $v0, 0x530($sp)
  addiu $a0, $sp, 0x680
  addiu $a1, $sp, 0x620
  jal   sub_GAME_7F0938FC
   addiu $a2, $sp, 0x580
  sw    $v0, 0x52c($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0x5e4
  jal   sub_GAME_7F093A78
   addiu $a2, $sp, 0x56c
  addiu $a0, $sp, 0x698
  addiu $a1, $sp, 0x5d8
  jal   sub_GAME_7F093A78
   addiu $a2, $sp, 0x568
  addiu $a0, $sp, 0x68c
  addiu $a1, $sp, 0x5cc
  jal   sub_GAME_7F093A78
   addiu $a2, $sp, 0x564
  addiu $a0, $sp, 0x680
  addiu $a1, $sp, 0x5c0
  jal   sub_GAME_7F093A78
   addiu $a2, $sp, 0x560
  lw    $t6, 0x538($sp)
  lw    $t2, 0x530($sp)
  beql  $t6, $t2, .L7F09485C
   mtc1  $zero, $f4
  jal   getPlayer_c_screentop
   nop   
  jal   getPlayer_c_screenheight
   mov.s $f22, $f0
  lwc1  $f2, 0x6a8($sp)
  lwc1  $f16, 0x690($sp)
  addiu $s0, $sp, 0x65c
  mtc1  $zero, $f12
  sub.s $f6, $f2, $f16
  move  $a2, $s0
  div.s $f8, $f2, $f6
  mul.s $f10, $f8, $f0
  add.s $f14, $f10, $f22
  jal   sub_GAME_7F093880
   swc1  $f14, 0x54c($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0x68c
  jal   sub_GAME_7F093BFC
   move  $a2, $s0
  move  $a0, $s0
  addiu $a1, $sp, 0x5fc
  jal   sub_GAME_7F0938FC
   addiu $a2, $sp, 0x574
  move  $a0, $s0
  addiu $a1, $sp, 0x59c
  jal   sub_GAME_7F093A78
   addiu $a2, $sp, 0x554
  b     .L7F094868
   lw    $t8, 0x534($sp)
  mtc1  $zero, $f4
.L7F09485C:
  nop   
  swc1  $f4, 0x54c($sp)
  lw    $t8, 0x534($sp)
.L7F094868:
  lw    $t7, 0x52c($sp)
  beql  $t8, $t7, .L7F0948F4
   mtc1  $zero, $f8
  jal   getPlayer_c_screentop
   nop   
  jal   getPlayer_c_screenheight
   mov.s $f22, $f0
  lwc1  $f16, 0x69c($sp)
  lwc1  $f6, 0x684($sp)
  sub.s $f8, $f16, $f6
  div.s $f10, $f16, $f8
  mul.s $f4, $f10, $f0
  add.s $f6, $f4, $f22
  jal   getPlayer_c_screenwidth
   swc1  $f6, 0x548($sp)
  addiu $s0, $sp, 0x650
  move  $a2, $s0
  sub.s $f12, $f0, $f28
  jal   sub_GAME_7F093880
   lwc1  $f14, 0x548($sp)
  addiu $a0, $sp, 0x698
  addiu $a1, $sp, 0x680
  jal   sub_GAME_7F093BFC
   move  $a2, $s0
  move  $a0, $s0
  addiu $a1, $sp, 0x5f0
  jal   sub_GAME_7F0938FC
   addiu $a2, $sp, 0x570
  move  $a0, $s0
  addiu $a1, $sp, 0x590
  jal   sub_GAME_7F093A78
   addiu $a2, $sp, 0x550
  b     .L7F094900
   lw    $t5, 0x538($sp)
  mtc1  $zero, $f8
.L7F0948F4:
  nop   
  swc1  $f8, 0x548($sp)
  lw    $t5, 0x538($sp)
.L7F094900:
  lw    $t9, 0x534($sp)
  beql  $t5, $t9, .L7F094978
   lw    $t3, 0x530($sp)
  jal   getPlayer_c_screenleft
   nop   
  jal   getPlayer_c_screenwidth
   mov.s $f22, $f0
  lwc1  $f2, 0x6a8($sp)
  lwc1  $f16, 0x69c($sp)
  addiu $s0, $sp, 0x674
  mtc1  $zero, $f14
  sub.s $f10, $f2, $f16
  move  $a2, $s0
  div.s $f4, $f2, $f10
  mul.s $f6, $f4, $f0
  jal   sub_GAME_7F093880
   add.s $f12, $f6, $f22
  move  $a0, $s1
  addiu $a1, $sp, 0x698
  jal   sub_GAME_7F093BFC
   move  $a2, $s0
  move  $a0, $s0
  addiu $a1, $sp, 0x614
  jal   sub_GAME_7F0938FC
   addiu $a2, $sp, 0x57c
  move  $a0, $s0
  addiu $a1, $sp, 0x5b4
  jal   sub_GAME_7F093A78
   addiu $a2, $sp, 0x55c
  lw    $t3, 0x530($sp)
.L7F094978:
  lw    $t4, 0x52c($sp)
  beql  $t3, $t4, .L7F0949F8
   lw    $t6, 0x538($sp)
  jal   getPlayer_c_screenleft
   nop   
  jal   getPlayer_c_screenwidth
   mov.s $f22, $f0
  lwc1  $f16, 0x690($sp)
  lwc1  $f8, 0x684($sp)
  sub.s $f10, $f16, $f8
  div.s $f4, $f16, $f10
  mul.s $f6, $f4, $f0
  jal   getPlayer_c_screenheight
   add.s $f20, $f6, $f22
  addiu $s0, $sp, 0x668
  move  $a2, $s0
  mov.s $f12, $f20
  jal   sub_GAME_7F093880
   sub.s $f14, $f0, $f28
  addiu $a0, $sp, 0x68c
  addiu $a1, $sp, 0x680
  jal   sub_GAME_7F093BFC
   move  $a2, $s0
  move  $a0, $s0
  addiu $a1, $sp, 0x608
  jal   sub_GAME_7F0938FC
   addiu $a2, $sp, 0x578
  move  $a0, $s0
  addiu $a1, $sp, 0x5a8
  jal   sub_GAME_7F093A78
   addiu $a2, $sp, 0x558
  lw    $t6, 0x538($sp)
.L7F0949F8:
  lw    $t8, 0x534($sp)
  lw    $t9, 0x530($sp)
  sll   $t2, $t6, 3
  lw    $t6, 0x52c($sp)
  sll   $t7, $t8, 2
  or    $t5, $t2, $t7
  sll   $t3, $t9, 1
  or    $t4, $t5, $t3
  or    $t8, $t4, $t6
  sltiu $at, $t8, 0x10
  beqz  $at, .L7F0957A4
   sw    $t8, 0x5c($sp)
  sll   $t2, $t8, 2
  lui   $at, %hi(jpt_80057544)
  addu  $at, $at, $t2
  lw    $t2, %lo(jpt_80057544)($at)
.L7F094A38:
  jr    $t2
   nop   
.L7F094A40:
  b     .L7F0957AC
   move  $s1, $zero
.L7F094A48:
  lwc1  $f2, 0x5e4($sp)
  lwc1  $f10, 0x5e8($sp)
  lwc1  $f12, 0x5ec($sp)
  mul.s $f8, $f2, $f24
  lwc1  $f14, 0x5d8($sp)
  lwc1  $f16, 0x5e0($sp)
  mul.s $f4, $f10, $f24
  lwc1  $f10, 0x5dc($sp)
  lwc1  $f18, 0x5cc($sp)
  mul.s $f6, $f12, $f24
  swc1  $f8, 0x43c($sp)
  lwc1  $f20, 0x5d4($sp)
  mul.s $f8, $f14, $f24
  swc1  $f4, 0x440($sp)
  lwc1  $f22, 0x5c0($sp)
  mul.s $f4, $f10, $f24
  swc1  $f6, 0x444($sp)
  lwc1  $f10, 0x5d0($sp)
  mul.s $f6, $f16, $f24
  swc1  $f8, 0x454($sp)
  lwc1  $f26, 0x5c8($sp)
  mul.s $f8, $f18, $f24
  swc1  $f4, 0x458($sp)
  lui   $at, %hi(D_8003FD94)
  mul.s $f4, $f10, $f24
  swc1  $f6, 0x45c($sp)
  lwc1  $f10, 0x5c4($sp)
  mul.s $f6, $f20, $f24
  swc1  $f8, 0x46c($sp)
  lwc1  $f0, %lo(D_8003FD94)($at)
  mul.s $f8, $f22, $f24
  swc1  $f4, 0x470($sp)
  li    $s1, 4
  mul.s $f4, $f10, $f24
  swc1  $f6, 0x474($sp)
  add.s $f10, $f16, $f0
  mul.s $f6, $f26, $f24
  swc1  $f8, 0x484($sp)
  add.s $f8, $f12, $f0
  swc1  $f10, 0x464($sp)
  swc1  $f4, 0x488($sp)
  add.s $f4, $f20, $f0
  swc1  $f8, 0x44c($sp)
  swc1  $f6, 0x48c($sp)
  add.s $f6, $f26, $f0
  swc1  $f4, 0x47c($sp)
  addiu $a0, $sp, 0x43c
  lw    $a1, 0x56c($sp)
  swc1  $f6, 0x494($sp)
  swc1  $f2, 0x448($sp)
  swc1  $f14, 0x460($sp)
  swc1  $f18, 0x478($sp)
  jal   sub_GAME_7F093FA4
   swc1  $f22, 0x490($sp)
  addiu $a0, $sp, 0x454
  jal   sub_GAME_7F093FA4
   lw    $a1, 0x568($sp)
  addiu $a0, $sp, 0x46c
  jal   sub_GAME_7F093FA4
   lw    $a1, 0x564($sp)
  addiu $a0, $sp, 0x484
  jal   sub_GAME_7F093FA4
   lw    $a1, 0x560($sp)
  b     .L7F0957AC
   nop   
.L7F094B4C:
  lwc1  $f2, 0x5e4($sp)
  lwc1  $f10, 0x5e8($sp)
  lwc1  $f12, 0x5ec($sp)
  mul.s $f8, $f2, $f24
  lwc1  $f14, 0x5d8($sp)
  lwc1  $f16, 0x5e0($sp)
  mul.s $f4, $f10, $f24
  lwc1  $f10, 0x5dc($sp)
  lwc1  $f18, 0x59c($sp)
  mul.s $f6, $f12, $f24
  swc1  $f8, 0x43c($sp)
  lwc1  $f20, 0x5a4($sp)
  mul.s $f8, $f14, $f24
  swc1  $f4, 0x440($sp)
  lwc1  $f22, 0x590($sp)
  mul.s $f4, $f10, $f24
  swc1  $f6, 0x444($sp)
  lwc1  $f10, 0x5a0($sp)
  mul.s $f6, $f16, $f24
  swc1  $f8, 0x454($sp)
  lwc1  $f26, 0x598($sp)
  mul.s $f8, $f18, $f24
  swc1  $f4, 0x458($sp)
  lui   $at, %hi(D_8003FD94)
  mul.s $f4, $f10, $f24
  swc1  $f6, 0x45c($sp)
  lwc1  $f10, 0x594($sp)
  mul.s $f6, $f20, $f24
  swc1  $f8, 0x46c($sp)
  lwc1  $f0, %lo(D_8003FD94)($at)
  mul.s $f8, $f22, $f24
  swc1  $f4, 0x470($sp)
  li    $s1, 4
  mul.s $f4, $f10, $f24
  swc1  $f6, 0x474($sp)
  add.s $f10, $f16, $f0
  mul.s $f6, $f26, $f24
  swc1  $f8, 0x484($sp)
  add.s $f8, $f12, $f0
  swc1  $f10, 0x464($sp)
  swc1  $f4, 0x488($sp)
  add.s $f4, $f20, $f0
  swc1  $f8, 0x44c($sp)
  swc1  $f6, 0x48c($sp)
  add.s $f6, $f26, $f0
  swc1  $f4, 0x47c($sp)
  addiu $a0, $sp, 0x43c
  lw    $a1, 0x56c($sp)
  swc1  $f6, 0x494($sp)
  swc1  $f2, 0x448($sp)
  swc1  $f14, 0x460($sp)
  swc1  $f18, 0x478($sp)
  jal   sub_GAME_7F093FA4
   swc1  $f22, 0x490($sp)
  addiu $a0, $sp, 0x454
  jal   sub_GAME_7F093FA4
   lw    $a1, 0x568($sp)
  addiu $a0, $sp, 0x46c
  jal   sub_GAME_7F093FA4
   lw    $a1, 0x554($sp)
  addiu $a0, $sp, 0x484
  jal   sub_GAME_7F093FA4
   lw    $a1, 0x550($sp)
  b     .L7F0957AC
   nop   
.L7F094C50:
  lwc1  $f22, 0x5c0($sp)
  lwc1  $f10, 0x5c4($sp)
  lwc1  $f26, 0x5c8($sp)
  mul.s $f8, $f22, $f24
  lwc1  $f18, 0x5cc($sp)
  lwc1  $f20, 0x5d4($sp)
  mul.s $f4, $f10, $f24
  lwc1  $f10, 0x5d0($sp)
  lwc1  $f14, 0x590($sp)
  mul.s $f6, $f26, $f24
  swc1  $f8, 0x43c($sp)
  lwc1  $f16, 0x598($sp)
  mul.s $f8, $f18, $f24
  swc1  $f4, 0x440($sp)
  lwc1  $f2, 0x59c($sp)
  mul.s $f4, $f10, $f24
  swc1  $f6, 0x444($sp)
  lwc1  $f10, 0x594($sp)
  mul.s $f6, $f20, $f24
  swc1  $f8, 0x454($sp)
  lwc1  $f12, 0x5a4($sp)
  mul.s $f8, $f14, $f24
  swc1  $f4, 0x458($sp)
  lui   $at, %hi(D_8003FD94)
  mul.s $f4, $f10, $f24
  swc1  $f6, 0x45c($sp)
  lwc1  $f10, 0x5a0($sp)
  mul.s $f6, $f16, $f24
  swc1  $f8, 0x46c($sp)
  lwc1  $f0, %lo(D_8003FD94)($at)
  mul.s $f8, $f2, $f24
  swc1  $f4, 0x470($sp)
  li    $t7, 1
  mul.s $f4, $f10, $f24
  swc1  $f6, 0x474($sp)
  add.s $f10, $f20, $f0
  mul.s $f6, $f12, $f24
  swc1  $f8, 0x484($sp)
  add.s $f8, $f26, $f0
  li    $s1, 4
  swc1  $f4, 0x488($sp)
  add.s $f4, $f16, $f0
  sw    $t7, 0x430($sp)
  swc1  $f6, 0x48c($sp)
  add.s $f6, $f12, $f0
  swc1  $f8, 0x44c($sp)
  swc1  $f10, 0x464($sp)
  swc1  $f4, 0x47c($sp)
  swc1  $f6, 0x494($sp)
  addiu $a0, $sp, 0x43c
  lw    $a1, 0x560($sp)
  swc1  $f22, 0x448($sp)
  swc1  $f18, 0x460($sp)
  swc1  $f14, 0x478($sp)
  jal   sub_GAME_7F093FA4
   swc1  $f2, 0x490($sp)
  addiu $a0, $sp, 0x454
  jal   sub_GAME_7F093FA4
   lw    $a1, 0x564($sp)
  addiu $a0, $sp, 0x46c
  jal   sub_GAME_7F093FA4
   lw    $a1, 0x550($sp)
  addiu $a0, $sp, 0x484
  jal   sub_GAME_7F093FA4
   lw    $a1, 0x554($sp)
  b     .L7F0957AC
   nop   
.L7F094D5C:
  lwc1  $f14, 0x5d8($sp)
  lwc1  $f10, 0x5dc($sp)
  lwc1  $f16, 0x5e0($sp)
  mul.s $f8, $f14, $f24
  lwc1  $f22, 0x5c0($sp)
  lwc1  $f26, 0x5c8($sp)
  mul.s $f4, $f10, $f24
  lwc1  $f10, 0x5c4($sp)
  lwc1  $f2, 0x5b4($sp)
  mul.s $f6, $f16, $f24
  swc1  $f8, 0x43c($sp)
  lwc1  $f12, 0x5bc($sp)
  mul.s $f8, $f22, $f24
  swc1  $f4, 0x440($sp)
  lwc1  $f18, 0x5a8($sp)
  mul.s $f4, $f10, $f24
  swc1  $f6, 0x444($sp)
  lwc1  $f10, 0x5b8($sp)
  mul.s $f6, $f26, $f24
  swc1  $f8, 0x454($sp)
  lwc1  $f20, 0x5b0($sp)
  mul.s $f8, $f2, $f24
  swc1  $f4, 0x458($sp)
  lui   $at, %hi(D_8003FD94)
  mul.s $f4, $f10, $f24
  swc1  $f6, 0x45c($sp)
  lwc1  $f10, 0x5ac($sp)
  mul.s $f6, $f12, $f24
  swc1  $f8, 0x46c($sp)
  lwc1  $f0, %lo(D_8003FD94)($at)
  mul.s $f8, $f18, $f24
  swc1  $f4, 0x470($sp)
  li    $s1, 4
  mul.s $f4, $f10, $f24
  swc1  $f6, 0x474($sp)
  add.s $f10, $f26, $f0
  mul.s $f6, $f20, $f24
  swc1  $f8, 0x484($sp)
  add.s $f8, $f16, $f0
  swc1  $f10, 0x464($sp)
  swc1  $f4, 0x488($sp)
  add.s $f4, $f12, $f0
  swc1  $f8, 0x44c($sp)
  swc1  $f6, 0x48c($sp)
  add.s $f6, $f20, $f0
  swc1  $f4, 0x47c($sp)
  addiu $a0, $sp, 0x43c
  lw    $a1, 0x568($sp)
  swc1  $f6, 0x494($sp)
  swc1  $f14, 0x448($sp)
  swc1  $f22, 0x460($sp)
  swc1  $f2, 0x478($sp)
  jal   sub_GAME_7F093FA4
   swc1  $f18, 0x490($sp)
  addiu $a0, $sp, 0x454
  jal   sub_GAME_7F093FA4
   lw    $a1, 0x560($sp)
  addiu $a0, $sp, 0x46c
  jal   sub_GAME_7F093FA4
   lw    $a1, 0x55c($sp)
  addiu $a0, $sp, 0x484
  jal   sub_GAME_7F093FA4
   lw    $a1, 0x558($sp)
  b     .L7F0957AC
   nop   
.L7F094E60:
  lwc1  $f18, 0x5cc($sp)
  lwc1  $f10, 0x5d0($sp)
  lwc1  $f20, 0x5d4($sp)
  mul.s $f8, $f18, $f24
  lwc1  $f2, 0x5e4($sp)
  lwc1  $f12, 0x5ec($sp)
  mul.s $f4, $f10, $f24
  lwc1  $f10, 0x5e8($sp)
  lwc1  $f22, 0x5a8($sp)
  mul.s $f6, $f20, $f24
  swc1  $f8, 0x43c($sp)
  lwc1  $f26, 0x5b0($sp)
  mul.s $f8, $f2, $f24
  swc1  $f4, 0x440($sp)
  lwc1  $f14, 0x5b4($sp)
  mul.s $f4, $f10, $f24
  swc1  $f6, 0x444($sp)
  lwc1  $f10, 0x5ac($sp)
  mul.s $f6, $f12, $f24
  swc1  $f8, 0x454($sp)
  lwc1  $f16, 0x5bc($sp)
  mul.s $f8, $f22, $f24
  swc1  $f4, 0x458($sp)
  lui   $at, %hi(D_8003FD94)
  mul.s $f4, $f10, $f24
  swc1  $f6, 0x45c($sp)
  lwc1  $f10, 0x5b8($sp)
  mul.s $f6, $f26, $f24
  swc1  $f8, 0x46c($sp)
  lwc1  $f0, %lo(D_8003FD94)($at)
  mul.s $f8, $f14, $f24
  swc1  $f4, 0x470($sp)
  li    $s1, 4
  mul.s $f4, $f10, $f24
  swc1  $f6, 0x474($sp)
  add.s $f10, $f12, $f0
  mul.s $f6, $f16, $f24
  swc1  $f8, 0x484($sp)
  add.s $f8, $f20, $f0
  swc1  $f10, 0x464($sp)
  swc1  $f4, 0x488($sp)
  add.s $f4, $f26, $f0
  swc1  $f8, 0x44c($sp)
  swc1  $f6, 0x48c($sp)
  add.s $f6, $f16, $f0
  swc1  $f4, 0x47c($sp)
  addiu $a0, $sp, 0x43c
  lw    $a1, 0x564($sp)
  swc1  $f6, 0x494($sp)
  swc1  $f18, 0x448($sp)
  swc1  $f2, 0x460($sp)
  swc1  $f22, 0x478($sp)
  jal   sub_GAME_7F093FA4
   swc1  $f14, 0x490($sp)
  addiu $a0, $sp, 0x454
  jal   sub_GAME_7F093FA4
   lw    $a1, 0x56c($sp)
  addiu $a0, $sp, 0x46c
  jal   sub_GAME_7F093FA4
   lw    $a1, 0x558($sp)
  addiu $a0, $sp, 0x484
  jal   sub_GAME_7F093FA4
   lw    $a1, 0x55c($sp)
  b     .L7F0957AC
   nop   
.L7F094F64:
  lwc1  $f22, 0x5c0($sp)
  lwc1  $f10, 0x5c4($sp)
  lwc1  $f26, 0x5c8($sp)
  mul.s $f8, $f22, $f24
  lwc1  $f14, 0x5a8($sp)
  lwc1  $f16, 0x5b0($sp)
  mul.s $f4, $f10, $f24
  lwc1  $f10, 0x5ac($sp)
  lwc1  $f2, 0x590($sp)
  mul.s $f6, $f26, $f24
  swc1  $f8, 0x43c($sp)
  lwc1  $f12, 0x598($sp)
  mul.s $f8, $f14, $f24
  swc1  $f4, 0x440($sp)
  lui   $at, %hi(D_8003FD94)
  mul.s $f4, $f10, $f24
  swc1  $f6, 0x444($sp)
  lwc1  $f10, 0x594($sp)
  mul.s $f6, $f16, $f24
  swc1  $f8, 0x454($sp)
  lwc1  $f0, %lo(D_8003FD94)($at)
  mul.s $f8, $f2, $f24
  swc1  $f4, 0x458($sp)
  li    $s1, 3
  mul.s $f4, $f10, $f24
  swc1  $f6, 0x45c($sp)
  add.s $f10, $f16, $f0
  mul.s $f6, $f12, $f24
  swc1  $f8, 0x46c($sp)
  add.s $f8, $f26, $f0
  swc1  $f10, 0x464($sp)
  swc1  $f4, 0x470($sp)
  add.s $f4, $f12, $f0
  swc1  $f8, 0x44c($sp)
  swc1  $f6, 0x474($sp)
  addiu $a0, $sp, 0x43c
  swc1  $f4, 0x47c($sp)
  lw    $a1, 0x560($sp)
  swc1  $f22, 0x448($sp)
  swc1  $f14, 0x460($sp)
  jal   sub_GAME_7F093FA4
   swc1  $f2, 0x478($sp)
  addiu $a0, $sp, 0x454
  jal   sub_GAME_7F093FA4
   lw    $a1, 0x558($sp)
  addiu $a0, $sp, 0x46c
  jal   sub_GAME_7F093FA4
   lw    $a1, 0x550($sp)
  b     .L7F0957AC
   nop   
.L7F09502C:
  lwc1  $f18, 0x5cc($sp)
  lwc1  $f8, 0x5d0($sp)
  lwc1  $f20, 0x5d4($sp)
  mul.s $f6, $f18, $f24
  lwc1  $f2, 0x59c($sp)
  lwc1  $f12, 0x5a4($sp)
  mul.s $f10, $f8, $f24
  lwc1  $f8, 0x5a0($sp)
  lwc1  $f14, 0x5a8($sp)
  mul.s $f4, $f20, $f24
  swc1  $f6, 0x43c($sp)
  lwc1  $f16, 0x5b0($sp)
  mul.s $f6, $f2, $f24
  swc1  $f10, 0x440($sp)
  lui   $at, %hi(D_8003FD94)
  mul.s $f10, $f8, $f24
  swc1  $f4, 0x444($sp)
  lwc1  $f8, 0x5ac($sp)
  mul.s $f4, $f12, $f24
  swc1  $f6, 0x454($sp)
  lwc1  $f0, %lo(D_8003FD94)($at)
  mul.s $f6, $f14, $f24
  swc1  $f10, 0x458($sp)
  li    $s1, 3
  mul.s $f10, $f8, $f24
  swc1  $f4, 0x45c($sp)
  add.s $f8, $f12, $f0
  mul.s $f4, $f16, $f24
  swc1  $f6, 0x46c($sp)
  add.s $f6, $f20, $f0
  swc1  $f8, 0x464($sp)
  swc1  $f10, 0x470($sp)
  add.s $f10, $f16, $f0
  swc1  $f6, 0x44c($sp)
  swc1  $f4, 0x474($sp)
  addiu $a0, $sp, 0x43c
  swc1  $f10, 0x47c($sp)
  lw    $a1, 0x564($sp)
  swc1  $f18, 0x448($sp)
  swc1  $f2, 0x460($sp)
  jal   sub_GAME_7F093FA4
   swc1  $f14, 0x478($sp)
  addiu $a0, $sp, 0x454
  jal   sub_GAME_7F093FA4
   lw    $a1, 0x554($sp)
  addiu $a0, $sp, 0x46c
  jal   sub_GAME_7F093FA4
   lw    $a1, 0x558($sp)
  b     .L7F0957AC
   nop   
.L7F0950F4:
  lwc1  $f14, 0x5d8($sp)
  lwc1  $f6, 0x5dc($sp)
  lwc1  $f16, 0x5e0($sp)
  mul.s $f4, $f14, $f24
  lwc1  $f18, 0x590($sp)
  lwc1  $f20, 0x598($sp)
  mul.s $f8, $f6, $f24
  lwc1  $f6, 0x594($sp)
  lwc1  $f2, 0x5b4($sp)
  mul.s $f10, $f16, $f24
  swc1  $f4, 0x43c($sp)
  lwc1  $f12, 0x5bc($sp)
  mul.s $f4, $f18, $f24
  swc1  $f8, 0x440($sp)
  lui   $at, %hi(D_8003FD94)
  mul.s $f8, $f6, $f24
  swc1  $f10, 0x444($sp)
  lwc1  $f6, 0x5b8($sp)
  mul.s $f10, $f20, $f24
  swc1  $f4, 0x454($sp)
  lwc1  $f0, %lo(D_8003FD94)($at)
  mul.s $f4, $f2, $f24
  swc1  $f8, 0x458($sp)
  li    $s1, 3
  mul.s $f8, $f6, $f24
  swc1  $f10, 0x45c($sp)
  add.s $f6, $f20, $f0
  mul.s $f10, $f12, $f24
  swc1  $f4, 0x46c($sp)
  add.s $f4, $f16, $f0
  swc1  $f6, 0x464($sp)
  swc1  $f8, 0x470($sp)
  add.s $f8, $f12, $f0
  swc1  $f4, 0x44c($sp)
  swc1  $f10, 0x474($sp)
  addiu $a0, $sp, 0x43c
  swc1  $f8, 0x47c($sp)
  lw    $a1, 0x568($sp)
  swc1  $f14, 0x448($sp)
  swc1  $f18, 0x460($sp)
  jal   sub_GAME_7F093FA4
   swc1  $f2, 0x478($sp)
  addiu $a0, $sp, 0x454
  jal   sub_GAME_7F093FA4
   lw    $a1, 0x550($sp)
  addiu $a0, $sp, 0x46c
  jal   sub_GAME_7F093FA4
   lw    $a1, 0x55c($sp)
  b     .L7F0957AC
   nop   
.L7F0951BC:
  lwc1  $f2, 0x5e4($sp)
  lwc1  $f4, 0x5e8($sp)
  lwc1  $f12, 0x5ec($sp)
  mul.s $f10, $f2, $f24
  lwc1  $f14, 0x5b4($sp)
  lwc1  $f16, 0x5bc($sp)
  mul.s $f6, $f4, $f24
  lwc1  $f4, 0x5b8($sp)
  lwc1  $f18, 0x59c($sp)
  mul.s $f8, $f12, $f24
  swc1  $f10, 0x43c($sp)
  lwc1  $f20, 0x5a4($sp)
  mul.s $f10, $f14, $f24
  swc1  $f6, 0x440($sp)
  lui   $at, %hi(D_8003FD94)
  mul.s $f6, $f4, $f24
  swc1  $f8, 0x444($sp)
  lwc1  $f4, 0x5a0($sp)
  mul.s $f8, $f16, $f24
  swc1  $f10, 0x454($sp)
  lwc1  $f0, %lo(D_8003FD94)($at)
  mul.s $f10, $f18, $f24
  swc1  $f6, 0x458($sp)
  li    $s1, 3
  mul.s $f6, $f4, $f24
  swc1  $f8, 0x45c($sp)
  add.s $f4, $f16, $f0
  mul.s $f8, $f20, $f24
  swc1  $f10, 0x46c($sp)
  add.s $f10, $f12, $f0
  swc1  $f4, 0x464($sp)
  swc1  $f6, 0x470($sp)
  add.s $f6, $f20, $f0
  swc1  $f10, 0x44c($sp)
  swc1  $f8, 0x474($sp)
  addiu $a0, $sp, 0x43c
  swc1  $f6, 0x47c($sp)
  lw    $a1, 0x56c($sp)
  swc1  $f2, 0x448($sp)
  swc1  $f14, 0x460($sp)
  jal   sub_GAME_7F093FA4
   swc1  $f18, 0x478($sp)
  addiu $a0, $sp, 0x454
  jal   sub_GAME_7F093FA4
   lw    $a1, 0x55c($sp)
  addiu $a0, $sp, 0x46c
  jal   sub_GAME_7F093FA4
   lw    $a1, 0x554($sp)
  b     .L7F0957AC
   nop   
.L7F095284:
  lwc1  $f18, 0x5cc($sp)
  lwc1  $f10, 0x5d0($sp)
  lwc1  $f20, 0x5d4($sp)
  mul.s $f8, $f18, $f24
  lwc1  $f2, 0x5e4($sp)
  lwc1  $f12, 0x5ec($sp)
  mul.s $f4, $f10, $f24
  lwc1  $f10, 0x5e8($sp)
  lwc1  $f14, 0x5d8($sp)
  mul.s $f6, $f20, $f24
  swc1  $f8, 0x43c($sp)
  lwc1  $f16, 0x5e0($sp)
  mul.s $f8, $f2, $f24
  swc1  $f4, 0x440($sp)
  lwc1  $f22, 0x590($sp)
  mul.s $f4, $f10, $f24
  swc1  $f6, 0x444($sp)
  lwc1  $f10, 0x5dc($sp)
  mul.s $f6, $f12, $f24
  swc1  $f8, 0x454($sp)
  lwc1  $f26, 0x598($sp)
  mul.s $f8, $f14, $f24
  swc1  $f4, 0x458($sp)
  lui   $at, %hi(D_8003FD94)
  mul.s $f4, $f10, $f24
  swc1  $f6, 0x45c($sp)
  lwc1  $f10, 0x594($sp)
  mul.s $f6, $f16, $f24
  swc1  $f8, 0x46c($sp)
  lwc1  $f0, %lo(D_8003FD94)($at)
  mul.s $f8, $f22, $f24
  swc1  $f4, 0x470($sp)
  li    $s1, 5
  mul.s $f4, $f10, $f24
  swc1  $f6, 0x474($sp)
  addiu $a0, $sp, 0x43c
  mul.s $f6, $f26, $f24
  swc1  $f8, 0x484($sp)
  lwc1  $f8, 0x5a8($sp)
  lw    $a1, 0x564($sp)
  swc1  $f4, 0x488($sp)
  mul.s $f10, $f8, $f24
  lwc1  $f4, 0x5ac($sp)
  swc1  $f6, 0x48c($sp)
  lwc1  $f8, 0x5b0($sp)
  mul.s $f6, $f4, $f24
  add.s $f4, $f20, $f0
  swc1  $f18, 0x448($sp)
  swc1  $f10, 0x49c($sp)
  mul.s $f10, $f8, $f24
  add.s $f8, $f16, $f0
  swc1  $f4, 0x44c($sp)
  swc1  $f6, 0x4a0($sp)
  lwc1  $f4, 0x5a8($sp)
  add.s $f6, $f12, $f0
  swc1  $f8, 0x47c($sp)
  swc1  $f10, 0x4a4($sp)
  add.s $f10, $f26, $f0
  swc1  $f6, 0x464($sp)
  lwc1  $f6, 0x5b0($sp)
  swc1  $f2, 0x460($sp)
  swc1  $f10, 0x494($sp)
  add.s $f8, $f6, $f0
  swc1  $f14, 0x478($sp)
  swc1  $f22, 0x490($sp)
  swc1  $f4, 0x4a8($sp)
  jal   sub_GAME_7F093FA4
   swc1  $f8, 0x4ac($sp)
  addiu $a0, $sp, 0x454
  jal   sub_GAME_7F093FA4
   lw    $a1, 0x56c($sp)
  addiu $a0, $sp, 0x46c
  jal   sub_GAME_7F093FA4
   lw    $a1, 0x568($sp)
  addiu $a0, $sp, 0x484
  jal   sub_GAME_7F093FA4
   lw    $a1, 0x550($sp)
  addiu $a0, $sp, 0x49c
  jal   sub_GAME_7F093FA4
   lw    $a1, 0x558($sp)
  b     .L7F0957AC
   nop   
.L7F0953CC:
  lwc1  $f26, 0x5e4($sp)
  lwc1  $f22, 0x5ec($sp)
  lwc1  $f20, 0x5d8($sp)
  mul.s $f18, $f26, $f24
  lwc1  $f16, 0x5e0($sp)
  lwc1  $f14, 0x5c0($sp)
  mul.s $f12, $f22, $f24
  lwc1  $f10, 0x59c($sp)
  lwc1  $f8, 0x5e8($sp)
  mul.s $f6, $f20, $f24
  lwc1  $f4, 0x5c8($sp)
  lwc1  $f2, 0x5a4($sp)
  mul.s $f8, $f8, $f24
  lwc1  $f0, 0x5dc($sp)
  lui   $at, %hi(D_8003FD94)
  swc1  $f18, 0x43c($sp)
  mul.s $f0, $f0, $f24
  lwc1  $f18, 0x5c4($sp)
  swc1  $f12, 0x444($sp)
  mul.s $f12, $f16, $f24
  swc1  $f8, 0x440($sp)
  lwc1  $f8, 0x5a8($sp)
  mul.s $f18, $f18, $f24
  swc1  $f6, 0x454($sp)
  lwc1  $f6, 0x5ac($sp)
  mul.s $f8, $f8, $f24
  swc1  $f0, 0x458($sp)
  lwc1  $f0, 0x5b0($sp)
  li    $s1, 5
  swc1  $f12, 0x45c($sp)
  mul.s $f12, $f14, $f24
  swc1  $f18, 0x470($sp)
  lwc1  $f18, 0x5a0($sp)
  mul.s $f0, $f0, $f24
  swc1  $f8, 0x484($sp)
  lwc1  $f8, %lo(D_8003FD94)($at)
  mul.s $f18, $f18, $f24
  swc1  $f12, 0x46c($sp)
  add.s $f12, $f4, $f8
  mul.s $f4, $f4, $f24
  swc1  $f0, 0x48c($sp)
  add.s $f0, $f2, $f8
  mul.s $f6, $f6, $f24
  swc1  $f18, 0x4a0($sp)
  add.s $f16, $f16, $f8
  mul.s $f2, $f2, $f24
  lwc1  $f18, 0x5b0($sp)
  swc1  $f4, 0x474($sp)
  mul.s $f4, $f10, $f24
  swc1  $f6, 0x488($sp)
  add.s $f22, $f22, $f8
  lwc1  $f6, 0x5a8($sp)
  swc1  $f2, 0x4a4($sp)
  add.s $f8, $f18, $f8
  swc1  $f26, 0x448($sp)
  swc1  $f4, 0x49c($sp)
  swc1  $f22, 0x44c($sp)
  swc1  $f20, 0x460($sp)
  swc1  $f16, 0x464($sp)
  swc1  $f14, 0x478($sp)
  swc1  $f12, 0x47c($sp)
  swc1  $f6, 0x490($sp)
  swc1  $f8, 0x494($sp)
  swc1  $f10, 0x4a8($sp)
  swc1  $f0, 0x4ac($sp)
  addiu $a0, $sp, 0x43c
  jal   sub_GAME_7F093FA4
   lw    $a1, 0x56c($sp)
  addiu $a0, $sp, 0x454
  jal   sub_GAME_7F093FA4
   lw    $a1, 0x568($sp)
  addiu $a0, $sp, 0x46c
  jal   sub_GAME_7F093FA4
   lw    $a1, 0x560($sp)
  addiu $a0, $sp, 0x484
  jal   sub_GAME_7F093FA4
   lw    $a1, 0x558($sp)
  addiu $a0, $sp, 0x49c
  jal   sub_GAME_7F093FA4
   lw    $a1, 0x554($sp)
  b     .L7F0957AC
   nop   
.L7F095514:
  lwc1  $f22, 0x5c0($sp)
  lwc1  $f6, 0x5c4($sp)
  lwc1  $f26, 0x5c8($sp)
  mul.s $f4, $f22, $f24
  lwc1  $f18, 0x5cc($sp)
  lwc1  $f20, 0x5d4($sp)
  mul.s $f8, $f6, $f24
  lwc1  $f6, 0x5d0($sp)
  lwc1  $f2, 0x5e4($sp)
  mul.s $f10, $f26, $f24
  swc1  $f4, 0x43c($sp)
  lwc1  $f12, 0x5ec($sp)
  mul.s $f4, $f18, $f24
  swc1  $f8, 0x440($sp)
  lwc1  $f14, 0x5b4($sp)
  mul.s $f8, $f6, $f24
  swc1  $f10, 0x444($sp)
  lwc1  $f6, 0x5e8($sp)
  mul.s $f10, $f20, $f24
  swc1  $f4, 0x454($sp)
  lwc1  $f16, 0x5bc($sp)
  mul.s $f4, $f2, $f24
  swc1  $f8, 0x458($sp)
  lui   $at, %hi(D_8003FD94)
  mul.s $f8, $f6, $f24
  swc1  $f10, 0x45c($sp)
  lwc1  $f6, 0x5b8($sp)
  mul.s $f10, $f12, $f24
  swc1  $f4, 0x46c($sp)
  lwc1  $f0, %lo(D_8003FD94)($at)
  mul.s $f4, $f14, $f24
  swc1  $f8, 0x470($sp)
  li    $s1, 5
  mul.s $f8, $f6, $f24
  swc1  $f10, 0x474($sp)
  addiu $a0, $sp, 0x43c
  mul.s $f10, $f16, $f24
  swc1  $f4, 0x484($sp)
  lwc1  $f4, 0x590($sp)
  lw    $a1, 0x560($sp)
  swc1  $f8, 0x488($sp)
  mul.s $f6, $f4, $f24
  lwc1  $f8, 0x594($sp)
  swc1  $f10, 0x48c($sp)
  lwc1  $f4, 0x598($sp)
  mul.s $f10, $f8, $f24
  add.s $f8, $f26, $f0
  swc1  $f22, 0x448($sp)
  swc1  $f6, 0x49c($sp)
  mul.s $f6, $f4, $f24
  add.s $f4, $f12, $f0
  swc1  $f8, 0x44c($sp)
  swc1  $f10, 0x4a0($sp)
  lwc1  $f8, 0x590($sp)
  add.s $f10, $f20, $f0
  swc1  $f4, 0x47c($sp)
  swc1  $f6, 0x4a4($sp)
  add.s $f6, $f16, $f0
  swc1  $f10, 0x464($sp)
  lwc1  $f10, 0x598($sp)
  swc1  $f18, 0x460($sp)
  swc1  $f6, 0x494($sp)
  add.s $f4, $f10, $f0
  swc1  $f2, 0x478($sp)
  swc1  $f14, 0x490($sp)
  swc1  $f8, 0x4a8($sp)
  jal   sub_GAME_7F093FA4
   swc1  $f4, 0x4ac($sp)
  addiu $a0, $sp, 0x454
  jal   sub_GAME_7F093FA4
   lw    $a1, 0x564($sp)
  addiu $a0, $sp, 0x46c
  jal   sub_GAME_7F093FA4
   lw    $a1, 0x56c($sp)
  addiu $a0, $sp, 0x484
  jal   sub_GAME_7F093FA4
   lw    $a1, 0x55c($sp)
  addiu $a0, $sp, 0x49c
  jal   sub_GAME_7F093FA4
   lw    $a1, 0x550($sp)
  b     .L7F0957AC
   nop   
.L7F09565C:
  lwc1  $f14, 0x5d8($sp)
  lwc1  $f8, 0x5dc($sp)
  lwc1  $f16, 0x5e0($sp)
  mul.s $f6, $f14, $f24
  lwc1  $f22, 0x5c0($sp)
  lwc1  $f26, 0x5c8($sp)
  mul.s $f10, $f8, $f24
  lwc1  $f8, 0x5c4($sp)
  lwc1  $f18, 0x5cc($sp)
  mul.s $f4, $f16, $f24
  swc1  $f6, 0x43c($sp)
  lwc1  $f20, 0x5d4($sp)
  mul.s $f6, $f22, $f24
  swc1  $f10, 0x440($sp)
  lwc1  $f2, 0x59c($sp)
  mul.s $f10, $f8, $f24
  swc1  $f4, 0x444($sp)
  lwc1  $f8, 0x5d0($sp)
  mul.s $f4, $f26, $f24
  swc1  $f6, 0x454($sp)
  lwc1  $f12, 0x5a4($sp)
  mul.s $f6, $f18, $f24
  swc1  $f10, 0x458($sp)
  lui   $at, %hi(D_8003FD94)
  mul.s $f10, $f8, $f24
  swc1  $f4, 0x45c($sp)
  lwc1  $f8, 0x5a0($sp)
  mul.s $f4, $f20, $f24
  swc1  $f6, 0x46c($sp)
  lwc1  $f0, %lo(D_8003FD94)($at)
  mul.s $f6, $f2, $f24
  swc1  $f10, 0x470($sp)
  li    $s1, 5
  mul.s $f10, $f8, $f24
  swc1  $f4, 0x474($sp)
  addiu $a0, $sp, 0x43c
  mul.s $f4, $f12, $f24
  swc1  $f6, 0x484($sp)
  lwc1  $f6, 0x5b4($sp)
  lw    $a1, 0x568($sp)
  swc1  $f10, 0x488($sp)
  mul.s $f8, $f6, $f24
  lwc1  $f10, 0x5b8($sp)
  swc1  $f4, 0x48c($sp)
  lwc1  $f6, 0x5bc($sp)
  mul.s $f4, $f10, $f24
  add.s $f10, $f16, $f0
  swc1  $f14, 0x448($sp)
  swc1  $f8, 0x49c($sp)
  mul.s $f8, $f6, $f24
  add.s $f6, $f20, $f0
  swc1  $f10, 0x44c($sp)
  swc1  $f4, 0x4a0($sp)
  lwc1  $f10, 0x5b4($sp)
  add.s $f4, $f26, $f0
  swc1  $f6, 0x47c($sp)
  swc1  $f8, 0x4a4($sp)
  add.s $f8, $f12, $f0
  swc1  $f4, 0x464($sp)
  lwc1  $f4, 0x5bc($sp)
  swc1  $f22, 0x460($sp)
  swc1  $f8, 0x494($sp)
  add.s $f6, $f4, $f0
  swc1  $f18, 0x478($sp)
  swc1  $f2, 0x490($sp)
  swc1  $f10, 0x4a8($sp)
  jal   sub_GAME_7F093FA4
   swc1  $f6, 0x4ac($sp)
  addiu $a0, $sp, 0x454
  jal   sub_GAME_7F093FA4
   lw    $a1, 0x560($sp)
  addiu $a0, $sp, 0x46c
  jal   sub_GAME_7F093FA4
   lw    $a1, 0x564($sp)
  addiu $a0, $sp, 0x484
  jal   sub_GAME_7F093FA4
   lw    $a1, 0x554($sp)
  addiu $a0, $sp, 0x49c
  jal   sub_GAME_7F093FA4
   lw    $a1, 0x55c($sp)
  b     .L7F0957AC
   nop   
def_7F094A38:
.L7F0957A4:
  b     .L7F097360
   lw    $v0, 0x6b0($sp)
.L7F0957AC:
  blezl $s1, .L7F095DE8
   lw    $t2, 0x5c($sp)
  jal   get_BONDdata_field_10DC
   nop   
  jal   get_BONDdata_field_10CC
   move  $s0, $v0
  move  $a0, $s0
  move  $a1, $v0
  jal   matrix_4x4_multiply
   addiu $a2, $sp, 0x3cc
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  lui   $a0, %hi(dword_CODE_bss_80079E98)
  addiu $a0, %lo(dword_CODE_bss_80079E98) # addiu $a0, $a0, -0x6168
  div.s $f0, $f8, $f24
  mfc1  $a1, $f0
  mfc1  $a2, $f0
  mfc1  $a3, $f0
  jal   guScaleF
   nop   
  lui   $a1, %hi(dword_CODE_bss_80079E98)
  addiu $a1, %lo(dword_CODE_bss_80079E98) # addiu $a1, $a1, -0x6168
  addiu $a0, $sp, 0x3cc
  jal   matrix_4x4_multiply
   addiu $a2, $sp, 0x38c
  blez  $s1, .L7F09594C
   sw    $zero, 0x270($sp)
  li    $at, 0x40800000 # 4.000000
  addiu $a0, $sp, 0x43c
  mtc1  $at, $f26
  sw    $a0, 0x58($sp)
  addiu $s0, $sp, 0x274
.L7F09582C:
  lui   $at, %hi(D_80057584)
  lwc1  $f0, %lo(D_80057584)($at)
  lw    $a0, 0x58($sp)
  addiu $a1, $sp, 0x38c
  mfc1  $a3, $f0
  li    $a2, 130
  sw    $s0, 0x14($sp)
  jal   sub_GAME_7F097388
   swc1  $f0, 0x10($sp)
  jal   getPlayer_c_screenleft
   nop   
  jal   getPlayer_c_screenleft
   mov.s $f20, $f0
  jal   getPlayer_c_screenwidth
   mov.s $f22, $f0
  add.s $f10, $f0, $f22
  mul.s $f14, $f20, $f26
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  mul.s $f4, $f10, $f26
  lwc1  $f12, 0x28($s0)
  sub.s $f8, $f4, $f6
  mfc1  $a2, $f8
  jal   sub_GAME_7F093C48
   nop   
  jal   getPlayer_c_screentop
   swc1  $f0, 0x28($s0)
  jal   getPlayer_c_screentop
   mov.s $f20, $f0
  jal   getPlayer_c_screenheight
   mov.s $f22, $f0
  add.s $f10, $f0, $f22
  mul.s $f14, $f20, $f26
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  mul.s $f4, $f10, $f26
  lwc1  $f12, 0x2c($s0)
  sub.s $f8, $f4, $f6
  mfc1  $a2, $f8
  jal   sub_GAME_7F093C48
   nop   
  jal   getPlayer_c_screentop
   swc1  $f0, 0x2c($s0)
  mul.s $f10, $f0, $f26
  lwc1  $f6, 0x2c($s0)
  add.s $f4, $f10, $f26
  c.lt.s $f4, $f6
  nop   
  bc1fl .L7F095930
   lw    $t9, 0x58($sp)
  jal   getPlayer_c_screentop
   nop   
  jal   getPlayer_c_screenheight
   mov.s $f20, $f0
  add.s $f8, $f0, $f20
  lwc1  $f2, 0x2c($s0)
  mul.s $f10, $f8, $f26
  sub.s $f4, $f10, $f26
  c.lt.s $f2, $f4
  nop   
  bc1fl .L7F095930
   lw    $t9, 0x58($sp)
  sub.s $f6, $f2, $f26
  swc1  $f6, 0x2c($s0)
  lw    $t9, 0x58($sp)
.L7F095930:
  lw    $v0, 0x270($sp)
  addiu $s0, $s0, 0x38
  addiu $t5, $t9, 0x18
  addiu $v0, $v0, 1
  sw    $v0, 0x270($sp)
  bne   $v0, $s1, .L7F09582C
   sw    $t5, 0x58($sp)
.L7F09594C:
  jal   get_ptr_currentdata
   nop   
  lbu   $t3, 0x20($v0)
  lw    $t6, 0x6b0($sp)
  lui   $t7, 0xe700
  bnez  $t3, .L7F095BFC
   addiu $t2, $t6, 8
  lui   $at, %hi(D_80057588)
  lwc1  $f18, %lo(D_80057588)($at)
  lui   $at, %hi(D_8005758C)
  lwc1  $f20, %lo(D_8005758C)($at)
  mtc1  $zero, $f16
  move  $v1, $zero
  mov.s $f2, $f18
  mov.s $f14, $f20
  blez  $s1, .L7F095ADC
   mov.s $f12, $f16
  andi  $v0, $s1, 1
  beqz  $v0, .L7F0959FC
   lwc1  $f0, 0x29c($sp)
  c.lt.s $f0, $f18
  mtc1  $zero, $f8
  mtc1  $zero, $f10
  li    $v1, 1
  bc1fl .L7F0959BC
   c.lt.s $f8, $f0
  mov.s $f2, $f0
  c.lt.s $f8, $f0
.L7F0959BC:
  nop   
  bc1fl .L7F0959D0
   lwc1  $f0, 0x2a0($sp)
  mov.s $f12, $f0
  lwc1  $f0, 0x2a0($sp)
.L7F0959D0:
  c.lt.s $f0, $f20
  nop   
  bc1fl .L7F0959E8
   c.lt.s $f10, $f0
  mov.s $f14, $f0
  c.lt.s $f10, $f0
.L7F0959E8:
  nop   
  bc1f  .L7F0959F8
   nop   
  mov.s $f16, $f0
.L7F0959F8:
  beq   $v1, $s1, .L7F095ADC
.L7F0959FC:
   sll   $t4, $v1, 3
  sll   $t8, $s1, 3
  subu  $t8, $t8, $s1
  subu  $t4, $t4, $v1
  addiu $t6, $sp, 0x274
  sll   $t4, $t4, 3
  sll   $t8, $t8, 3
  addu  $a0, $t8, $t6
  addu  $v0, $t4, $t6
  lwc1  $f0, 0x28($v0)
.L7F095A24:
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F095A3C
   c.lt.s $f12, $f0
  mov.s $f2, $f0
  c.lt.s $f12, $f0
.L7F095A3C:
  nop   
  bc1fl .L7F095A50
   lwc1  $f0, 0x2c($v0)
  mov.s $f12, $f0
  lwc1  $f0, 0x2c($v0)
.L7F095A50:
  c.lt.s $f0, $f14
  nop   
  bc1fl .L7F095A68
   c.lt.s $f16, $f0
  mov.s $f14, $f0
  c.lt.s $f16, $f0
.L7F095A68:
  nop   
  bc1fl .L7F095A7C
   lwc1  $f0, 0x60($v0)
  mov.s $f16, $f0
  lwc1  $f0, 0x60($v0)
.L7F095A7C:
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F095A94
   c.lt.s $f12, $f0
  mov.s $f2, $f0
  c.lt.s $f12, $f0
.L7F095A94:
  nop   
  bc1fl .L7F095AA8
   lwc1  $f0, 0x64($v0)
  mov.s $f12, $f0
  lwc1  $f0, 0x64($v0)
.L7F095AA8:
  addiu $v0, $v0, 0x70
  c.lt.s $f0, $f14
  nop   
  bc1fl .L7F095AC4
   c.lt.s $f16, $f0
  mov.s $f14, $f0
  c.lt.s $f16, $f0
.L7F095AC4:
  nop   
  bc1f  .L7F095AD4
   nop   
  mov.s $f16, $f0
.L7F095AD4:
  bnel  $v0, $a0, .L7F095A24
   lwc1  $f0, 0x28($v0)
.L7F095ADC:
  lw    $t2, 0x6b0($sp)
  lui   $t9, 0xe700
  li    $at, 0x3E800000 # 0.250000
  addiu $t7, $t2, 8
  sw    $t7, 0x6b0($sp)
  sw    $zero, 4($t2)
  sw    $t9, ($t2)
  lw    $t5, 0x6b0($sp)
  mtc1  $at, $f0
  lui   $t4, (0xBA001402 >> 16) # lui $t4, 0xba00
  addiu $t3, $t5, 8
  sw    $t3, 0x6b0($sp)
  ori   $t4, (0xBA001402 & 0xFFFF) # ori $t4, $t4, 0x1402
  lui   $t8, 0x30
  mul.s $f4, $f12, $f0
  sw    $t8, 4($t5)
  sw    $t4, ($t5)
  lw    $t6, 0x6b0($sp)
  mul.s $f8, $f16, $f0
  lui   $t7, (0xB900031D >> 16) # lui $t7, 0xb900
  addiu $t2, $t6, 8
  sw    $t2, 0x6b0($sp)
  ori   $t7, (0xB900031D & 0xFFFF) # ori $t7, $t7, 0x31d
  sw    $t7, ($t6)
  sw    $zero, 4($t6)
  trunc.w.s $f6, $f4
  lw    $t9, 0x6b0($sp)
  mul.s $f4, $f2, $f0
  trunc.w.s $f10, $f8
  addiu $t5, $t9, 8
  mul.s $f8, $f14, $f0
  lui   $a3, (0xBA001301 >> 16) # lui $a3, 0xba00
  sw    $t5, 0x6b0($sp)
  ori   $a3, (0xBA001301 & 0xFFFF) # ori $a3, $a3, 0x1301
  sw    $a3, ($t9)
  sw    $zero, 4($t9)
  lw    $a2, 0x6b0($sp)
  mfc1  $t6, $f6
  mfc1  $t3, $f10
  addiu $t4, $a2, 8
  andi  $t2, $t6, 0x3ff
  trunc.w.s $f10, $f8
  sll   $t7, $t2, 0xe
  sw    $t4, 0x6b0($sp)
  trunc.w.s $f6, $f4
  lui   $at, 0xf600
  or    $t9, $t7, $at
  andi  $t4, $t3, 0x3ff
  sll   $t8, $t4, 2
  or    $t6, $t9, $t8
  mfc1  $t9, $f10
  mfc1  $t7, $f6
  sw    $t6, ($a2)
  andi  $t8, $t9, 0x3ff
  andi  $t5, $t7, 0x3ff
  sll   $t3, $t5, 0xe
  sll   $t6, $t8, 2
  or    $t2, $t3, $t6
  sw    $t2, 4($a2)
  lw    $t7, 0x6b0($sp)
  lui   $t4, 0xe700
  lui   $t3, 8
  addiu $t5, $t7, 8
  sw    $t5, 0x6b0($sp)
  sw    $zero, 4($t7)
  sw    $t4, ($t7)
  lw    $t9, 0x6b0($sp)
  addiu $t8, $t9, 8
  sw    $t8, 0x6b0($sp)
  sw    $t3, 4($t9)
  b     .L7F095DE4
   sw    $a3, ($t9)
.L7F095BFC:
  sw    $t2, 0x6b0($sp)
  sw    $zero, 4($t6)
  jal   get_ptr_currentdata
   sw    $t7, ($t6)
  lh    $t5, 0x28($v0)
  lui   $t9, %hi(skywaterimages) 
  lw    $t9, %lo(skywaterimages)($t9)
  sll   $t4, $t5, 2
  subu  $t4, $t4, $t5
  sll   $t4, $t4, 2
  li    $t8, 2
  sw    $t8, 0x10($sp)
  addiu $a0, $sp, 0x6b0
  li    $a2, 1
  move  $a3, $zero
  jal   likely_generate_DL_for_image_declaration
   addu  $a1, $t4, $t9
  lw    $a0, 0x6b0($sp)
  jal   sub_GAME_7F09343C
   move  $a1, $zero
  addiu $t3, $v0, 8
  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
  lui   $t2, (0x0F0A4000 >> 16) # lui $t2, 0xf0a
  ori   $t2, (0x0F0A4000 & 0xFFFF) # ori $t2, $t2, 0x4000
  ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
  sw    $t3, 0x6b0($sp)
  li    $at, 4
  sw    $t2, 4($v0)
  bne   $s1, $at, .L7F095D18
   sw    $t6, ($v0)
  li    $at, 0x43020000 # 130.000000
  mtc1  $at, $f4
  addiu $s0, $sp, 0x274
  addiu $s1, $sp, 0x31c
  li    $t7, 1
  sw    $t7, 0x14($sp)
  move  $a3, $s1
  move  $a1, $s0
  lw    $a0, 0x6b0($sp)
  addiu $a2, $sp, 0x2ac
  jal   sub_GAME_7F097818
   swc1  $f4, 0x10($sp)
  lw    $t5, 0x430($sp)
  move  $a0, $v0
  move  $a1, $s1
  beqz  $t5, .L7F095CF0
   addiu $a2, $sp, 0x2e4
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f2
  lwc1  $f6, 0x2d8($sp)
  lwc1  $f0, 0x2a0($sp)
  lwc1  $f10, 0x310($sp)
  add.s $f8, $f6, $f2
  lwc1  $f6, 0x348($sp)
  add.s $f0, $f0, $f2
  swc1  $f8, 0x2d8($sp)
  add.s $f4, $f10, $f2
  swc1  $f0, 0x2a0($sp)
  add.s $f8, $f6, $f2
  swc1  $f4, 0x310($sp)
  swc1  $f8, 0x348($sp)
.L7F095CF0:
  li    $at, 0x43020000 # 130.000000
  mtc1  $at, $f10
  li    $t4, 1
  sw    $t4, 0x14($sp)
  move  $a3, $s0
  sw    $a0, 0x6b0($sp)
  jal   sub_GAME_7F097818
   swc1  $f10, 0x10($sp)
  b     .L7F095DE4
   sw    $v0, 0x6b0($sp)
.L7F095D18:
  li    $at, 5
  bne   $s1, $at, .L7F095DB0
   addiu $s0, $sp, 0x274
  li    $at, 0x43020000 # 130.000000
  mtc1  $at, $f4
  li    $t9, 1
  sw    $t9, 0x14($sp)
  lw    $a0, 0x6b0($sp)
  move  $a1, $s0
  addiu $a2, $sp, 0x2ac
  addiu $a3, $sp, 0x2e4
  jal   sub_GAME_7F097818
   swc1  $f4, 0x10($sp)
  li    $at, 0x43020000 # 130.000000
  mtc1  $at, $f6
  addiu $s1, $sp, 0x31c
  li    $t8, 1
  sw    $v0, 0x6b0($sp)
  sw    $t8, 0x14($sp)
  move  $a3, $s1
  move  $a0, $v0
  move  $a1, $s0
  addiu $a2, $sp, 0x2e4
  jal   sub_GAME_7F097818
   swc1  $f6, 0x10($sp)
  li    $at, 0x43020000 # 130.000000
  mtc1  $at, $f8
  li    $t3, 1
  sw    $v0, 0x6b0($sp)
  sw    $t3, 0x14($sp)
  move  $a0, $v0
  move  $a1, $s0
  move  $a2, $s1
  addiu $a3, $sp, 0x354
  jal   sub_GAME_7F097818
   swc1  $f8, 0x10($sp)
  b     .L7F095DE4
   sw    $v0, 0x6b0($sp)
.L7F095DB0:
  li    $at, 3
  bne   $s1, $at, .L7F095DE4
   addiu $a1, $sp, 0x274
  li    $at, 0x43020000 # 130.000000
  mtc1  $at, $f10
  li    $t6, 1
  sw    $t6, 0x14($sp)
  lw    $a0, 0x6b0($sp)
  addiu $a2, $sp, 0x2ac
  addiu $a3, $sp, 0x2e4
  jal   sub_GAME_7F097818
   swc1  $f10, 0x10($sp)
  sw    $v0, 0x6b0($sp)
.L7F095DE4:
  lw    $t2, 0x5c($sp)
.L7F095DE8:
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f26
  sltiu $at, $t2, 0x10
  beqz  $at, .L7F096E20
   lw    $v1, 0x6b0($sp)
  sll   $t2, $t2, 2
  lui   $at, %hi(jpt_80057590)
  addu  $at, $at, $t2
  lw    $t2, %lo(jpt_80057590)($at)
.L7F095E0C:
  jr    $t2
   nop   
.L7F095E14:
  b     .L7F097360
   move  $v0, $v1
.L7F095E1C:
  lwc1  $f2, 0x644($sp)
  lwc1  $f6, 0x648($sp)
  lwc1  $f12, 0x64c($sp)
  mul.s $f4, $f2, $f24
  lwc1  $f14, 0x638($sp)
  lwc1  $f16, 0x640($sp)
  mul.s $f8, $f6, $f24
  lwc1  $f6, 0x63c($sp)
  lwc1  $f18, 0x62c($sp)
  mul.s $f10, $f12, $f24
  swc1  $f4, 0x4b4($sp)
  lwc1  $f20, 0x634($sp)
  mul.s $f4, $f14, $f24
  swc1  $f8, 0x4b8($sp)
  lwc1  $f22, 0x620($sp)
  mul.s $f8, $f6, $f24
  swc1  $f10, 0x4bc($sp)
  lwc1  $f6, 0x630($sp)
  mul.s $f10, $f16, $f24
  swc1  $f4, 0x4cc($sp)
  lui   $at, %hi(D_8003FD94)
  mul.s $f4, $f18, $f24
  swc1  $f8, 0x4d0($sp)
  lwc1  $f0, %lo(D_8003FD94)($at)
  mul.s $f8, $f6, $f24
  swc1  $f10, 0x4d4($sp)
  lwc1  $f6, 0x624($sp)
  mul.s $f10, $f20, $f24
  swc1  $f4, 0x4e4($sp)
  li    $at, 0x3F800000 # 1.000000
  mul.s $f4, $f22, $f24
  swc1  $f8, 0x4e8($sp)
  li    $s1, 4
  mul.s $f8, $f6, $f24
  swc1  $f10, 0x4ec($sp)
  lwc1  $f10, 0x628($sp)
  addiu $a0, $sp, 0x4b4
  swc1  $f4, 0x4fc($sp)
  mul.s $f4, $f10, $f24
  lw    $a1, 0x58c($sp)
  swc1  $f8, 0x500($sp)
  mul.s $f6, $f2, $f28
  nop   
  mul.s $f8, $f12, $f28
  swc1  $f4, 0x504($sp)
  mul.s $f4, $f14, $f28
  swc1  $f6, 0x4c0($sp)
  mul.s $f6, $f16, $f28
  add.s $f10, $f8, $f0
  swc1  $f4, 0x4d8($sp)
  swc1  $f10, 0x4c4($sp)
  mul.s $f10, $f18, $f28
  add.s $f8, $f6, $f0
  mul.s $f4, $f20, $f28
  swc1  $f8, 0x4dc($sp)
  mul.s $f8, $f22, $f28
  swc1  $f10, 0x4f0($sp)
  lwc1  $f10, 0x628($sp)
  add.s $f6, $f4, $f0
  mul.s $f4, $f10, $f28
  swc1  $f8, 0x508($sp)
  mtc1  $at, $f8
  swc1  $f6, 0x4f4($sp)
  div.s $f10, $f8, $f24
  add.s $f6, $f4, $f0
  swc1  $f6, 0x50c($sp)
  jal   sub_GAME_7F093CB0
   swc1  $f10, 0x58($sp)
  addiu $a0, $sp, 0x4cc
  jal   sub_GAME_7F093CB0
   lw    $a1, 0x588($sp)
  addiu $a0, $sp, 0x4e4
  jal   sub_GAME_7F093CB0
   lw    $a1, 0x584($sp)
  addiu $a0, $sp, 0x4fc
  jal   sub_GAME_7F093CB0
   lw    $a1, 0x580($sp)
  b     .L7F096E2C
   lw    $t7, 0x6b0($sp)
.L7F095F58:
  lwc1  $f2, 0x644($sp)
  lwc1  $f6, 0x648($sp)
  lwc1  $f12, 0x64c($sp)
  mul.s $f4, $f2, $f24
  lwc1  $f14, 0x638($sp)
  lwc1  $f16, 0x640($sp)
  mul.s $f8, $f6, $f24
  lwc1  $f6, 0x63c($sp)
  lwc1  $f18, 0x5fc($sp)
  mul.s $f10, $f12, $f24
  swc1  $f4, 0x4b4($sp)
  lwc1  $f20, 0x604($sp)
  mul.s $f4, $f14, $f24
  swc1  $f8, 0x4b8($sp)
  lwc1  $f22, 0x5f0($sp)
  mul.s $f8, $f6, $f24
  swc1  $f10, 0x4bc($sp)
  lwc1  $f6, 0x600($sp)
  mul.s $f10, $f16, $f24
  swc1  $f4, 0x4cc($sp)
  lui   $at, %hi(D_8003FD94)
  mul.s $f4, $f18, $f24
  swc1  $f8, 0x4d0($sp)
  lwc1  $f0, %lo(D_8003FD94)($at)
  mul.s $f8, $f6, $f24
  swc1  $f10, 0x4d4($sp)
  lwc1  $f6, 0x5f4($sp)
  mul.s $f10, $f20, $f24
  swc1  $f4, 0x4e4($sp)
  li    $at, 0x3F800000 # 1.000000
  mul.s $f4, $f22, $f24
  swc1  $f8, 0x4e8($sp)
  li    $s1, 4
  mul.s $f8, $f6, $f24
  swc1  $f10, 0x4ec($sp)
  lwc1  $f10, 0x5f8($sp)
  addiu $a0, $sp, 0x4b4
  swc1  $f4, 0x4fc($sp)
  mul.s $f4, $f10, $f24
  lw    $a1, 0x58c($sp)
  swc1  $f8, 0x500($sp)
  mul.s $f6, $f2, $f28
  nop   
  mul.s $f8, $f12, $f28
  swc1  $f4, 0x504($sp)
  mul.s $f4, $f14, $f28
  swc1  $f6, 0x4c0($sp)
  mul.s $f6, $f16, $f28
  add.s $f10, $f8, $f0
  swc1  $f4, 0x4d8($sp)
  swc1  $f10, 0x4c4($sp)
  mul.s $f10, $f18, $f28
  add.s $f8, $f6, $f0
  mul.s $f4, $f20, $f28
  swc1  $f8, 0x4dc($sp)
  mul.s $f8, $f22, $f28
  swc1  $f10, 0x4f0($sp)
  lwc1  $f10, 0x5f8($sp)
  add.s $f6, $f4, $f0
  mul.s $f4, $f10, $f28
  swc1  $f8, 0x508($sp)
  mtc1  $at, $f8
  swc1  $f6, 0x4f4($sp)
  div.s $f10, $f8, $f24
  add.s $f6, $f4, $f0
  swc1  $f6, 0x50c($sp)
  jal   sub_GAME_7F093CB0
   swc1  $f10, 0x58($sp)
  addiu $a0, $sp, 0x4cc
  jal   sub_GAME_7F093CB0
   lw    $a1, 0x588($sp)
  addiu $a0, $sp, 0x4e4
  jal   sub_GAME_7F093CB0
   lw    $a1, 0x574($sp)
  addiu $a0, $sp, 0x4fc
  jal   sub_GAME_7F093CB0
   lw    $a1, 0x570($sp)
  b     .L7F096E2C
   lw    $t7, 0x6b0($sp)
.L7F096094:
  lwc1  $f22, 0x620($sp)
  lwc1  $f6, 0x624($sp)
  lwc1  $f2, 0x628($sp)
  mul.s $f4, $f22, $f24
  lwc1  $f18, 0x62c($sp)
  lwc1  $f20, 0x634($sp)
  mul.s $f8, $f6, $f24
  lwc1  $f6, 0x630($sp)
  lwc1  $f16, 0x5f0($sp)
  mul.s $f10, $f2, $f24
  swc1  $f4, 0x4b4($sp)
  lwc1  $f12, 0x5fc($sp)
  mul.s $f4, $f18, $f24
  swc1  $f8, 0x4b8($sp)
  lwc1  $f14, 0x604($sp)
  mul.s $f8, $f6, $f24
  swc1  $f10, 0x4bc($sp)
  lwc1  $f6, 0x5f4($sp)
  mul.s $f10, $f20, $f24
  swc1  $f4, 0x4cc($sp)
  lui   $at, %hi(D_8003FD94)
  mul.s $f4, $f16, $f24
  swc1  $f8, 0x4d0($sp)
  lwc1  $f0, %lo(D_8003FD94)($at)
  mul.s $f8, $f6, $f24
  swc1  $f10, 0x4d4($sp)
  lwc1  $f10, 0x5f8($sp)
  li    $at, 0x3F800000 # 1.000000
  swc1  $f4, 0x4e4($sp)
  mul.s $f4, $f10, $f24
  li    $s1, 4
  swc1  $f8, 0x4e8($sp)
  mul.s $f6, $f12, $f24
  lwc1  $f8, 0x600($sp)
  addiu $a0, $sp, 0x4b4
  lw    $a1, 0x580($sp)
  mul.s $f10, $f8, $f24
  swc1  $f4, 0x4ec($sp)
  mul.s $f4, $f14, $f24
  swc1  $f6, 0x4fc($sp)
  mul.s $f6, $f22, $f28
  swc1  $f10, 0x500($sp)
  mul.s $f8, $f2, $f28
  swc1  $f4, 0x504($sp)
  mul.s $f4, $f18, $f28
  swc1  $f6, 0x4c0($sp)
  mul.s $f6, $f20, $f28
  add.s $f10, $f8, $f0
  swc1  $f4, 0x4d8($sp)
  lwc1  $f4, 0x5f8($sp)
  swc1  $f10, 0x4c4($sp)
  mul.s $f10, $f16, $f28
  add.s $f8, $f6, $f0
  mul.s $f6, $f4, $f28
  swc1  $f8, 0x4dc($sp)
  swc1  $f10, 0x4f0($sp)
  mul.s $f10, $f12, $f28
  add.s $f8, $f6, $f0
  mul.s $f4, $f14, $f28
  swc1  $f8, 0x4f4($sp)
  mtc1  $at, $f8
  swc1  $f10, 0x508($sp)
  div.s $f10, $f8, $f24
  add.s $f6, $f4, $f0
  swc1  $f6, 0x50c($sp)
  jal   sub_GAME_7F093CB0
   swc1  $f10, 0x58($sp)
  addiu $a0, $sp, 0x4cc
  jal   sub_GAME_7F093CB0
   lw    $a1, 0x584($sp)
  addiu $a0, $sp, 0x4e4
  jal   sub_GAME_7F093CB0
   lw    $a1, 0x570($sp)
  addiu $a0, $sp, 0x4fc
  jal   sub_GAME_7F093CB0
   lw    $a1, 0x574($sp)
  b     .L7F096E2C
   lw    $t7, 0x6b0($sp)
.L7F0961CC:
  lwc1  $f14, 0x638($sp)
  lwc1  $f6, 0x63c($sp)
  lwc1  $f16, 0x640($sp)
  mul.s $f4, $f14, $f24
  lwc1  $f22, 0x620($sp)
  lwc1  $f2, 0x628($sp)
  mul.s $f8, $f6, $f24
  lwc1  $f6, 0x624($sp)
  lwc1  $f20, 0x614($sp)
  mul.s $f10, $f16, $f24
  swc1  $f4, 0x4b4($sp)
  lwc1  $f12, 0x608($sp)
  mul.s $f4, $f22, $f24
  swc1  $f8, 0x4b8($sp)
  lwc1  $f18, 0x610($sp)
  mul.s $f8, $f6, $f24
  swc1  $f10, 0x4bc($sp)
  lwc1  $f6, 0x618($sp)
  mul.s $f10, $f2, $f24
  swc1  $f4, 0x4cc($sp)
  lui   $at, %hi(D_8003FD94)
  mul.s $f4, $f20, $f24
  swc1  $f8, 0x4d0($sp)
  lwc1  $f0, %lo(D_8003FD94)($at)
  mul.s $f8, $f6, $f24
  swc1  $f10, 0x4d4($sp)
  lwc1  $f10, 0x61c($sp)
  li    $at, 0x3F800000 # 1.000000
  swc1  $f4, 0x4e4($sp)
  mul.s $f4, $f10, $f24
  li    $s1, 4
  swc1  $f8, 0x4e8($sp)
  mul.s $f6, $f12, $f24
  lwc1  $f8, 0x60c($sp)
  addiu $a0, $sp, 0x4b4
  lw    $a1, 0x588($sp)
  mul.s $f10, $f8, $f24
  swc1  $f4, 0x4ec($sp)
  mul.s $f4, $f18, $f24
  swc1  $f6, 0x4fc($sp)
  mul.s $f6, $f14, $f28
  swc1  $f10, 0x500($sp)
  mul.s $f8, $f16, $f28
  swc1  $f4, 0x504($sp)
  mul.s $f4, $f22, $f28
  swc1  $f6, 0x4c0($sp)
  mul.s $f6, $f2, $f28
  add.s $f10, $f8, $f0
  swc1  $f4, 0x4d8($sp)
  lwc1  $f4, 0x61c($sp)
  swc1  $f10, 0x4c4($sp)
  mul.s $f10, $f20, $f28
  add.s $f8, $f6, $f0
  mul.s $f6, $f4, $f28
  swc1  $f8, 0x4dc($sp)
  swc1  $f10, 0x4f0($sp)
  mul.s $f10, $f12, $f28
  add.s $f8, $f6, $f0
  mul.s $f4, $f18, $f28
  swc1  $f8, 0x4f4($sp)
  mtc1  $at, $f8
  swc1  $f10, 0x508($sp)
  div.s $f10, $f8, $f24
  add.s $f6, $f4, $f0
  swc1  $f6, 0x50c($sp)
  jal   sub_GAME_7F093CB0
   swc1  $f10, 0x58($sp)
  addiu $a0, $sp, 0x4cc
  jal   sub_GAME_7F093CB0
   lw    $a1, 0x580($sp)
  addiu $a0, $sp, 0x4e4
  jal   sub_GAME_7F093CB0
   lw    $a1, 0x57c($sp)
  addiu $a0, $sp, 0x4fc
  jal   sub_GAME_7F093CB0
   lw    $a1, 0x578($sp)
  b     .L7F096E2C
   lw    $t7, 0x6b0($sp)
.L7F096304:
  lwc1  $f18, 0x62c($sp)
  lwc1  $f6, 0x630($sp)
  lwc1  $f20, 0x634($sp)
  mul.s $f4, $f18, $f24
  lwc1  $f2, 0x644($sp)
  lwc1  $f12, 0x64c($sp)
  mul.s $f8, $f6, $f24
  lwc1  $f6, 0x648($sp)
  lwc1  $f22, 0x608($sp)
  mul.s $f10, $f20, $f24
  swc1  $f4, 0x4b4($sp)
  lwc1  $f14, 0x614($sp)
  mul.s $f4, $f2, $f24
  swc1  $f8, 0x4b8($sp)
  lwc1  $f16, 0x61c($sp)
  mul.s $f8, $f6, $f24
  swc1  $f10, 0x4bc($sp)
  lwc1  $f6, 0x60c($sp)
  mul.s $f10, $f12, $f24
  swc1  $f4, 0x4cc($sp)
  lui   $at, %hi(D_8003FD94)
  mul.s $f4, $f22, $f24
  swc1  $f8, 0x4d0($sp)
  lwc1  $f0, %lo(D_8003FD94)($at)
  mul.s $f8, $f6, $f24
  swc1  $f10, 0x4d4($sp)
  lwc1  $f10, 0x610($sp)
  li    $at, 0x3F800000 # 1.000000
  swc1  $f4, 0x4e4($sp)
  mul.s $f4, $f10, $f24
  li    $s1, 4
  swc1  $f8, 0x4e8($sp)
  mul.s $f6, $f14, $f24
  lwc1  $f8, 0x618($sp)
  addiu $a0, $sp, 0x4b4
  lw    $a1, 0x584($sp)
  mul.s $f10, $f8, $f24
  swc1  $f4, 0x4ec($sp)
  mul.s $f4, $f16, $f24
  swc1  $f6, 0x4fc($sp)
  mul.s $f6, $f18, $f28
  swc1  $f10, 0x500($sp)
  mul.s $f8, $f20, $f28
  swc1  $f4, 0x504($sp)
  mul.s $f4, $f2, $f28
  swc1  $f6, 0x4c0($sp)
  mul.s $f6, $f12, $f28
  add.s $f10, $f8, $f0
  swc1  $f4, 0x4d8($sp)
  lwc1  $f4, 0x610($sp)
  swc1  $f10, 0x4c4($sp)
  mul.s $f10, $f22, $f28
  add.s $f8, $f6, $f0
  mul.s $f6, $f4, $f28
  swc1  $f8, 0x4dc($sp)
  swc1  $f10, 0x4f0($sp)
  mul.s $f10, $f14, $f28
  add.s $f8, $f6, $f0
  mul.s $f4, $f16, $f28
  swc1  $f8, 0x4f4($sp)
  mtc1  $at, $f8
  swc1  $f10, 0x508($sp)
  div.s $f10, $f8, $f24
  add.s $f6, $f4, $f0
  swc1  $f6, 0x50c($sp)
  jal   sub_GAME_7F093CB0
   swc1  $f10, 0x58($sp)
  addiu $a0, $sp, 0x4cc
  jal   sub_GAME_7F093CB0
   lw    $a1, 0x58c($sp)
  addiu $a0, $sp, 0x4e4
  jal   sub_GAME_7F093CB0
   lw    $a1, 0x578($sp)
  addiu $a0, $sp, 0x4fc
  jal   sub_GAME_7F093CB0
   lw    $a1, 0x57c($sp)
  b     .L7F096E2C
   lw    $t7, 0x6b0($sp)
.L7F09643C:
  lwc1  $f22, 0x620($sp)
  lwc1  $f6, 0x624($sp)
  lwc1  $f2, 0x628($sp)
  mul.s $f4, $f22, $f24
  lwc1  $f14, 0x608($sp)
  lwc1  $f18, 0x610($sp)
  mul.s $f8, $f6, $f24
  lwc1  $f6, 0x60c($sp)
  lwc1  $f16, 0x5f0($sp)
  mul.s $f10, $f2, $f24
  swc1  $f4, 0x4b4($sp)
  lwc1  $f12, 0x5f8($sp)
  mul.s $f4, $f14, $f24
  swc1  $f8, 0x4b8($sp)
  lui   $at, %hi(D_8003FD94)
  mul.s $f8, $f6, $f24
  swc1  $f10, 0x4bc($sp)
  lwc1  $f6, 0x5f4($sp)
  mul.s $f10, $f18, $f24
  swc1  $f4, 0x4cc($sp)
  lwc1  $f0, %lo(D_8003FD94)($at)
  mul.s $f4, $f16, $f24
  swc1  $f8, 0x4d0($sp)
  li    $at, 0x3F800000 # 1.000000
  mul.s $f8, $f6, $f24
  swc1  $f10, 0x4d4($sp)
  li    $s1, 3
  mul.s $f10, $f12, $f24
  swc1  $f4, 0x4e4($sp)
  addiu $a0, $sp, 0x4b4
  mul.s $f4, $f22, $f28
  swc1  $f8, 0x4e8($sp)
  lw    $a1, 0x580($sp)
  mul.s $f6, $f2, $f28
  swc1  $f10, 0x4ec($sp)
  mul.s $f10, $f14, $f28
  swc1  $f4, 0x4c0($sp)
  mul.s $f4, $f18, $f28
  add.s $f8, $f6, $f0
  swc1  $f10, 0x4d8($sp)
  swc1  $f8, 0x4c4($sp)
  mul.s $f8, $f16, $f28
  add.s $f6, $f4, $f0
  mul.s $f10, $f12, $f28
  swc1  $f6, 0x4dc($sp)
  mtc1  $at, $f6
  swc1  $f8, 0x4f0($sp)
  div.s $f8, $f6, $f24
  add.s $f4, $f10, $f0
  swc1  $f4, 0x4f4($sp)
  jal   sub_GAME_7F093CB0
   swc1  $f8, 0x58($sp)
  addiu $a0, $sp, 0x4cc
  jal   sub_GAME_7F093CB0
   lw    $a1, 0x578($sp)
  addiu $a0, $sp, 0x4e4
  jal   sub_GAME_7F093CB0
   lw    $a1, 0x570($sp)
  b     .L7F096E2C
   lw    $t7, 0x6b0($sp)
.L7F09652C:
  lwc1  $f18, 0x62c($sp)
  lwc1  $f4, 0x630($sp)
  lwc1  $f20, 0x634($sp)
  mul.s $f10, $f18, $f24
  lwc1  $f12, 0x5fc($sp)
  lwc1  $f14, 0x604($sp)
  mul.s $f6, $f4, $f24
  lwc1  $f4, 0x600($sp)
  lwc1  $f2, 0x608($sp)
  mul.s $f8, $f20, $f24
  swc1  $f10, 0x4b4($sp)
  lwc1  $f16, 0x610($sp)
  mul.s $f10, $f12, $f24
  swc1  $f6, 0x4b8($sp)
  lui   $at, %hi(D_8003FD94)
  mul.s $f6, $f4, $f24
  swc1  $f8, 0x4bc($sp)
  lwc1  $f4, 0x60c($sp)
  mul.s $f8, $f14, $f24
  swc1  $f10, 0x4cc($sp)
  lwc1  $f0, %lo(D_8003FD94)($at)
  mul.s $f10, $f2, $f24
  swc1  $f6, 0x4d0($sp)
  li    $at, 0x3F800000 # 1.000000
  mul.s $f6, $f4, $f24
  swc1  $f8, 0x4d4($sp)
  li    $s1, 3
  mul.s $f8, $f16, $f24
  swc1  $f10, 0x4e4($sp)
  addiu $a0, $sp, 0x4b4
  mul.s $f10, $f18, $f28
  swc1  $f6, 0x4e8($sp)
  lw    $a1, 0x584($sp)
  mul.s $f4, $f20, $f28
  swc1  $f8, 0x4ec($sp)
  mul.s $f8, $f12, $f28
  swc1  $f10, 0x4c0($sp)
  mul.s $f10, $f14, $f28
  add.s $f6, $f4, $f0
  swc1  $f8, 0x4d8($sp)
  swc1  $f6, 0x4c4($sp)
  mul.s $f6, $f2, $f28
  add.s $f4, $f10, $f0
  mul.s $f8, $f16, $f28
  swc1  $f4, 0x4dc($sp)
  mtc1  $at, $f4
  swc1  $f6, 0x4f0($sp)
  div.s $f6, $f4, $f24
  add.s $f10, $f8, $f0
  swc1  $f10, 0x4f4($sp)
  jal   sub_GAME_7F093CB0
   swc1  $f6, 0x58($sp)
  addiu $a0, $sp, 0x4cc
  jal   sub_GAME_7F093CB0
   lw    $a1, 0x574($sp)
  addiu $a0, $sp, 0x4e4
  jal   sub_GAME_7F093CB0
   lw    $a1, 0x578($sp)
  b     .L7F096E2C
   lw    $t7, 0x6b0($sp)
.L7F09661C:
  lwc1  $f14, 0x638($sp)
  lwc1  $f10, 0x63c($sp)
  lwc1  $f16, 0x640($sp)
  mul.s $f8, $f14, $f24
  lwc1  $f2, 0x5f0($sp)
  lwc1  $f12, 0x5f8($sp)
  mul.s $f4, $f10, $f24
  lwc1  $f10, 0x5f4($sp)
  lwc1  $f20, 0x614($sp)
  mul.s $f6, $f16, $f24
  swc1  $f8, 0x4b4($sp)
  lwc1  $f18, 0x61c($sp)
  mul.s $f8, $f2, $f24
  swc1  $f4, 0x4b8($sp)
  lui   $at, %hi(D_8003FD94)
  mul.s $f4, $f10, $f24
  swc1  $f6, 0x4bc($sp)
  lwc1  $f10, 0x618($sp)
  mul.s $f6, $f12, $f24
  swc1  $f8, 0x4cc($sp)
  lwc1  $f0, %lo(D_8003FD94)($at)
  mul.s $f8, $f20, $f24
  swc1  $f4, 0x4d0($sp)
  li    $at, 0x3F800000 # 1.000000
  mul.s $f4, $f10, $f24
  swc1  $f6, 0x4d4($sp)
  li    $s1, 3
  mul.s $f6, $f18, $f24
  swc1  $f8, 0x4e4($sp)
  addiu $a0, $sp, 0x4b4
  mul.s $f8, $f14, $f28
  swc1  $f4, 0x4e8($sp)
  lw    $a1, 0x588($sp)
  mul.s $f10, $f16, $f28
  swc1  $f6, 0x4ec($sp)
  mul.s $f6, $f2, $f28
  swc1  $f8, 0x4c0($sp)
  mul.s $f8, $f12, $f28
  add.s $f4, $f10, $f0
  swc1  $f6, 0x4d8($sp)
  swc1  $f4, 0x4c4($sp)
  mul.s $f4, $f20, $f28
  add.s $f10, $f8, $f0
  mul.s $f6, $f18, $f28
  swc1  $f10, 0x4dc($sp)
  mtc1  $at, $f10
  swc1  $f4, 0x4f0($sp)
  div.s $f4, $f10, $f24
  add.s $f8, $f6, $f0
  swc1  $f8, 0x4f4($sp)
  jal   sub_GAME_7F093CB0
   swc1  $f4, 0x58($sp)
  addiu $a0, $sp, 0x4cc
  jal   sub_GAME_7F093CB0
   lw    $a1, 0x570($sp)
  addiu $a0, $sp, 0x4e4
  jal   sub_GAME_7F093CB0
   lw    $a1, 0x57c($sp)
  b     .L7F096E2C
   lw    $t7, 0x6b0($sp)
.L7F09670C:
  lwc1  $f2, 0x644($sp)
  lwc1  $f8, 0x648($sp)
  lwc1  $f12, 0x64c($sp)
  mul.s $f6, $f2, $f24
  lwc1  $f18, 0x614($sp)
  lwc1  $f20, 0x61c($sp)
  mul.s $f10, $f8, $f24
  lwc1  $f8, 0x618($sp)
  lwc1  $f14, 0x5fc($sp)
  mul.s $f4, $f12, $f24
  swc1  $f6, 0x4b4($sp)
  lwc1  $f16, 0x604($sp)
  mul.s $f6, $f18, $f24
  swc1  $f10, 0x4b8($sp)
  lui   $at, %hi(D_8003FD94)
  mul.s $f10, $f8, $f24
  swc1  $f4, 0x4bc($sp)
  lwc1  $f8, 0x600($sp)
  mul.s $f4, $f20, $f24
  swc1  $f6, 0x4cc($sp)
  lwc1  $f0, %lo(D_8003FD94)($at)
  mul.s $f6, $f14, $f24
  swc1  $f10, 0x4d0($sp)
  li    $at, 0x3F800000 # 1.000000
  mul.s $f10, $f8, $f24
  swc1  $f4, 0x4d4($sp)
  li    $s1, 3
  mul.s $f4, $f16, $f24
  swc1  $f6, 0x4e4($sp)
  addiu $a0, $sp, 0x4b4
  mul.s $f6, $f2, $f28
  swc1  $f10, 0x4e8($sp)
  lw    $a1, 0x58c($sp)
  mul.s $f8, $f12, $f28
  swc1  $f4, 0x4ec($sp)
  mul.s $f4, $f18, $f28
  swc1  $f6, 0x4c0($sp)
  mul.s $f6, $f20, $f28
  add.s $f10, $f8, $f0
  swc1  $f4, 0x4d8($sp)
  swc1  $f10, 0x4c4($sp)
  mul.s $f10, $f14, $f28
  add.s $f8, $f6, $f0
  mul.s $f4, $f16, $f28
  swc1  $f8, 0x4dc($sp)
  mtc1  $at, $f8
  swc1  $f10, 0x4f0($sp)
  div.s $f10, $f8, $f24
  add.s $f6, $f4, $f0
  swc1  $f6, 0x4f4($sp)
  jal   sub_GAME_7F093CB0
   swc1  $f10, 0x58($sp)
  addiu $a0, $sp, 0x4cc
  jal   sub_GAME_7F093CB0
   lw    $a1, 0x57c($sp)
  addiu $a0, $sp, 0x4e4
  jal   sub_GAME_7F093CB0
   lw    $a1, 0x574($sp)
  b     .L7F096E2C
   lw    $t7, 0x6b0($sp)
.L7F0967FC:
  lwc1  $f18, 0x62c($sp)
  lwc1  $f6, 0x630($sp)
  lwc1  $f20, 0x634($sp)
  mul.s $f4, $f18, $f24
  lwc1  $f2, 0x644($sp)
  lwc1  $f12, 0x64c($sp)
  mul.s $f8, $f6, $f24
  lwc1  $f6, 0x648($sp)
  lwc1  $f14, 0x638($sp)
  mul.s $f10, $f20, $f24
  swc1  $f4, 0x4b4($sp)
  lwc1  $f16, 0x640($sp)
  mul.s $f4, $f2, $f24
  swc1  $f8, 0x4b8($sp)
  lwc1  $f22, 0x5f0($sp)
  mul.s $f8, $f6, $f24
  swc1  $f10, 0x4bc($sp)
  lwc1  $f6, 0x63c($sp)
  mul.s $f10, $f12, $f24
  swc1  $f4, 0x4cc($sp)
  lui   $at, %hi(D_8003FD94)
  mul.s $f4, $f14, $f24
  swc1  $f8, 0x4d0($sp)
  lwc1  $f0, %lo(D_8003FD94)($at)
  mul.s $f8, $f6, $f24
  swc1  $f10, 0x4d4($sp)
  lwc1  $f6, 0x5f4($sp)
  mul.s $f10, $f16, $f24
  swc1  $f4, 0x4e4($sp)
  li    $at, 0x3F800000 # 1.000000
  mul.s $f4, $f22, $f24
  swc1  $f8, 0x4e8($sp)
  li    $s1, 5
  mul.s $f8, $f6, $f24
  swc1  $f10, 0x4ec($sp)
  lwc1  $f10, 0x5f8($sp)
  lwc1  $f6, 0x608($sp)
  swc1  $f4, 0x4fc($sp)
  mul.s $f4, $f10, $f24
  lwc1  $f10, 0x60c($sp)
  swc1  $f8, 0x500($sp)
  mul.s $f8, $f6, $f24
  lwc1  $f6, 0x610($sp)
  addiu $a0, $sp, 0x4b4
  lw    $a1, 0x584($sp)
  swc1  $f4, 0x504($sp)
  mul.s $f4, $f10, $f24
  swc1  $f8, 0x514($sp)
  mul.s $f8, $f6, $f24
  nop   
  mul.s $f10, $f18, $f28
  swc1  $f4, 0x518($sp)
  mul.s $f4, $f20, $f28
  swc1  $f8, 0x51c($sp)
  mul.s $f8, $f2, $f28
  swc1  $f10, 0x4c0($sp)
  mul.s $f10, $f12, $f28
  add.s $f6, $f4, $f0
  swc1  $f8, 0x4d8($sp)
  swc1  $f6, 0x4c4($sp)
  mul.s $f6, $f14, $f28
  add.s $f4, $f10, $f0
  mul.s $f8, $f16, $f28
  swc1  $f4, 0x4dc($sp)
  mul.s $f4, $f22, $f28
  swc1  $f6, 0x4f0($sp)
  lwc1  $f6, 0x5f8($sp)
  add.s $f10, $f8, $f0
  mul.s $f8, $f6, $f28
  swc1  $f4, 0x508($sp)
  lwc1  $f4, 0x608($sp)
  swc1  $f10, 0x4f4($sp)
  mul.s $f6, $f4, $f28
  add.s $f10, $f8, $f0
  lwc1  $f8, 0x610($sp)
  swc1  $f10, 0x50c($sp)
  swc1  $f6, 0x520($sp)
  mtc1  $at, $f6
  mul.s $f10, $f8, $f28
  div.s $f8, $f6, $f24
  add.s $f4, $f10, $f0
  swc1  $f4, 0x524($sp)
  jal   sub_GAME_7F093CB0
   swc1  $f8, 0x58($sp)
  addiu $a0, $sp, 0x4cc
  jal   sub_GAME_7F093CB0
   lw    $a1, 0x58c($sp)
  addiu $a0, $sp, 0x4e4
  jal   sub_GAME_7F093CB0
   lw    $a1, 0x588($sp)
  addiu $a0, $sp, 0x4fc
  jal   sub_GAME_7F093CB0
   lw    $a1, 0x570($sp)
  addiu $a0, $sp, 0x514
  jal   sub_GAME_7F093CB0
   lw    $a1, 0x578($sp)
  b     .L7F096E2C
   lw    $t7, 0x6b0($sp)
.L7F096984:
  lwc1  $f2, 0x644($sp)
  lwc1  $f4, 0x648($sp)
  lwc1  $f12, 0x64c($sp)
  mul.s $f10, $f2, $f24
  lwc1  $f14, 0x638($sp)
  lwc1  $f16, 0x640($sp)
  mul.s $f6, $f4, $f24
  lwc1  $f4, 0x63c($sp)
  lwc1  $f22, 0x620($sp)
  mul.s $f8, $f12, $f24
  swc1  $f10, 0x4b4($sp)
  lwc1  $f18, 0x5fc($sp)
  mul.s $f10, $f14, $f24
  swc1  $f6, 0x4b8($sp)
  lwc1  $f20, 0x604($sp)
  mul.s $f6, $f4, $f24
  swc1  $f8, 0x4bc($sp)
  lwc1  $f4, 0x624($sp)
  mul.s $f8, $f16, $f24
  swc1  $f10, 0x4cc($sp)
  lui   $at, %hi(D_8003FD94)
  mul.s $f10, $f22, $f24
  swc1  $f6, 0x4d0($sp)
  lwc1  $f0, %lo(D_8003FD94)($at)
  mul.s $f6, $f4, $f24
  swc1  $f8, 0x4d4($sp)
  lwc1  $f8, 0x628($sp)
  lwc1  $f4, 0x608($sp)
  swc1  $f10, 0x4e4($sp)
  mul.s $f10, $f8, $f24
  lwc1  $f8, 0x60c($sp)
  swc1  $f6, 0x4e8($sp)
  mul.s $f6, $f4, $f24
  lwc1  $f4, 0x610($sp)
  li    $at, 0x3F800000 # 1.000000
  li    $s1, 5
  swc1  $f10, 0x4ec($sp)
  mul.s $f10, $f8, $f24
  addiu $a0, $sp, 0x4b4
  swc1  $f6, 0x4fc($sp)
  mul.s $f6, $f4, $f24
  lw    $a1, 0x58c($sp)
  mul.s $f8, $f18, $f24
  swc1  $f10, 0x500($sp)
  lwc1  $f10, 0x600($sp)
  swc1  $f6, 0x504($sp)
  mul.s $f4, $f10, $f24
  swc1  $f8, 0x514($sp)
  mul.s $f6, $f20, $f24
  nop   
  mul.s $f8, $f2, $f28
  swc1  $f4, 0x518($sp)
  mul.s $f10, $f12, $f28
  swc1  $f6, 0x51c($sp)
  mul.s $f6, $f14, $f28
  swc1  $f8, 0x4c0($sp)
  mul.s $f8, $f16, $f28
  add.s $f4, $f10, $f0
  swc1  $f6, 0x4d8($sp)
  lwc1  $f6, 0x628($sp)
  swc1  $f4, 0x4c4($sp)
  mul.s $f4, $f22, $f28
  add.s $f10, $f8, $f0
  mul.s $f8, $f6, $f28
  swc1  $f10, 0x4dc($sp)
  swc1  $f4, 0x4f0($sp)
  lwc1  $f4, 0x608($sp)
  add.s $f10, $f8, $f0
  mul.s $f6, $f4, $f28
  lwc1  $f8, 0x610($sp)
  swc1  $f10, 0x4f4($sp)
  mul.s $f10, $f8, $f28
  swc1  $f6, 0x508($sp)
  mul.s $f6, $f18, $f28
  add.s $f4, $f10, $f0
  mul.s $f8, $f20, $f28
  swc1  $f6, 0x520($sp)
  swc1  $f4, 0x50c($sp)
  mtc1  $at, $f4
  nop   
  div.s $f6, $f4, $f24
  add.s $f10, $f8, $f0
  swc1  $f10, 0x524($sp)
  jal   sub_GAME_7F093CB0
   swc1  $f6, 0x58($sp)
  addiu $a0, $sp, 0x4cc
  jal   sub_GAME_7F093CB0
   lw    $a1, 0x588($sp)
  addiu $a0, $sp, 0x4e4
  jal   sub_GAME_7F093CB0
   lw    $a1, 0x580($sp)
  addiu $a0, $sp, 0x4fc
  jal   sub_GAME_7F093CB0
   lw    $a1, 0x578($sp)
  addiu $a0, $sp, 0x514
  jal   sub_GAME_7F093CB0
   lw    $a1, 0x574($sp)
  b     .L7F096E2C
   lw    $t7, 0x6b0($sp)
.L7F096B10:
  lwc1  $f22, 0x620($sp)
  lwc1  $f10, 0x624($sp)
  lwc1  $f6, 0x628($sp)
  mul.s $f8, $f22, $f24
  lwc1  $f18, 0x62c($sp)
  lwc1  $f20, 0x634($sp)
  mul.s $f4, $f10, $f24
  lwc1  $f2, 0x644($sp)
  lwc1  $f12, 0x64c($sp)
  lwc1  $f14, 0x614($sp)
  swc1  $f8, 0x4b4($sp)
  mul.s $f8, $f6, $f24
  lwc1  $f16, 0x61c($sp)
  swc1  $f4, 0x4b8($sp)
  mul.s $f10, $f18, $f24
  lwc1  $f4, 0x630($sp)
  lui   $at, %hi(D_8003FD94)
  lwc1  $f0, %lo(D_8003FD94)($at)
  swc1  $f8, 0x4bc($sp)
  mul.s $f8, $f4, $f24
  li    $at, 0x3F800000 # 1.000000
  swc1  $f10, 0x4cc($sp)
  mul.s $f10, $f20, $f24
  li    $s1, 5
  addiu $a0, $sp, 0x4b4
  mul.s $f4, $f2, $f24
  swc1  $f8, 0x4d0($sp)
  lwc1  $f8, 0x648($sp)
  lw    $a1, 0x580($sp)
  swc1  $f10, 0x4d4($sp)
  mul.s $f10, $f8, $f24
  swc1  $f4, 0x4e4($sp)
  mul.s $f4, $f12, $f24
  swc1  $f10, 0x4e8($sp)
  mul.s $f8, $f14, $f24
  lwc1  $f10, 0x618($sp)
  swc1  $f4, 0x4ec($sp)
  mul.s $f4, $f10, $f24
  lwc1  $f10, 0x5f0($sp)
  swc1  $f8, 0x4fc($sp)
  mul.s $f8, $f16, $f24
  swc1  $f4, 0x500($sp)
  mul.s $f4, $f10, $f24
  swc1  $f8, 0x504($sp)
  lwc1  $f8, 0x5f4($sp)
  mul.s $f10, $f8, $f24
  swc1  $f4, 0x514($sp)
  lwc1  $f4, 0x5f8($sp)
  mul.s $f8, $f4, $f24
  swc1  $f10, 0x518($sp)
  mul.s $f10, $f22, $f28
  nop   
  mul.s $f4, $f6, $f28
  swc1  $f8, 0x51c($sp)
  swc1  $f10, 0x4c0($sp)
  mul.s $f10, $f18, $f28
  add.s $f8, $f4, $f0
  mul.s $f6, $f20, $f28
  swc1  $f8, 0x4c4($sp)
  mul.s $f8, $f2, $f28
  swc1  $f10, 0x4d8($sp)
  mul.s $f10, $f12, $f28
  add.s $f4, $f6, $f0
  swc1  $f8, 0x4f0($sp)
  swc1  $f4, 0x4dc($sp)
  mul.s $f4, $f14, $f28
  add.s $f6, $f10, $f0
  mul.s $f8, $f16, $f28
  swc1  $f6, 0x4f4($sp)
  lwc1  $f6, 0x5f0($sp)
  swc1  $f4, 0x508($sp)
  mul.s $f4, $f6, $f28
  add.s $f10, $f8, $f0
  lwc1  $f8, 0x5f8($sp)
  swc1  $f10, 0x50c($sp)
  mul.s $f10, $f8, $f28
  swc1  $f4, 0x520($sp)
  mtc1  $at, $f4
  nop   
  div.s $f8, $f4, $f24
  add.s $f6, $f10, $f0
  swc1  $f6, 0x524($sp)
  jal   sub_GAME_7F093CB0
   swc1  $f8, 0x58($sp)
  addiu $a0, $sp, 0x4cc
  jal   sub_GAME_7F093CB0
   lw    $a1, 0x584($sp)
  addiu $a0, $sp, 0x4e4
  jal   sub_GAME_7F093CB0
   lw    $a1, 0x58c($sp)
  addiu $a0, $sp, 0x4fc
  jal   sub_GAME_7F093CB0
   lw    $a1, 0x57c($sp)
  addiu $a0, $sp, 0x514
  jal   sub_GAME_7F093CB0
   lw    $a1, 0x570($sp)
  b     .L7F096E2C
   lw    $t7, 0x6b0($sp)
.L7F096C98:
  lwc1  $f14, 0x638($sp)
  lwc1  $f6, 0x63c($sp)
  lwc1  $f16, 0x640($sp)
  mul.s $f10, $f14, $f24
  lwc1  $f22, 0x620($sp)
  lwc1  $f2, 0x628($sp)
  mul.s $f4, $f6, $f24
  lwc1  $f6, 0x624($sp)
  lwc1  $f18, 0x62c($sp)
  mul.s $f8, $f16, $f24
  swc1  $f10, 0x4b4($sp)
  lwc1  $f20, 0x634($sp)
  mul.s $f10, $f22, $f24
  swc1  $f4, 0x4b8($sp)
  lwc1  $f12, 0x5fc($sp)
  mul.s $f4, $f6, $f24
  swc1  $f8, 0x4bc($sp)
  lwc1  $f6, 0x630($sp)
  mul.s $f8, $f2, $f24
  swc1  $f10, 0x4cc($sp)
  lui   $at, %hi(D_8003FD94)
  mul.s $f10, $f18, $f24
  swc1  $f4, 0x4d0($sp)
  lwc1  $f0, %lo(D_8003FD94)($at)
  mul.s $f4, $f6, $f24
  swc1  $f8, 0x4d4($sp)
  lwc1  $f6, 0x600($sp)
  mul.s $f8, $f20, $f24
  swc1  $f10, 0x4e4($sp)
  li    $at, 0x3F800000 # 1.000000
  mul.s $f10, $f12, $f24
  swc1  $f4, 0x4e8($sp)
  li    $s1, 5
  mul.s $f4, $f6, $f24
  swc1  $f8, 0x4ec($sp)
  lwc1  $f8, 0x604($sp)
  lwc1  $f6, 0x614($sp)
  swc1  $f10, 0x4fc($sp)
  mul.s $f10, $f8, $f24
  lwc1  $f8, 0x618($sp)
  swc1  $f4, 0x500($sp)
  mul.s $f4, $f6, $f24
  lwc1  $f6, 0x61c($sp)
  addiu $a0, $sp, 0x4b4
  lw    $a1, 0x588($sp)
  swc1  $f10, 0x504($sp)
  mul.s $f10, $f8, $f24
  swc1  $f4, 0x514($sp)
  mul.s $f4, $f6, $f24
  nop   
  mul.s $f8, $f14, $f28
  swc1  $f10, 0x518($sp)
  mul.s $f10, $f16, $f28
  swc1  $f4, 0x51c($sp)
  mul.s $f4, $f22, $f28
  swc1  $f8, 0x4c0($sp)
  mul.s $f8, $f2, $f28
  add.s $f6, $f10, $f0
  swc1  $f4, 0x4d8($sp)
  swc1  $f6, 0x4c4($sp)
  mul.s $f6, $f18, $f28
  add.s $f10, $f8, $f0
  mul.s $f4, $f20, $f28
  swc1  $f10, 0x4dc($sp)
  mul.s $f10, $f12, $f28
  swc1  $f6, 0x4f0($sp)
  lwc1  $f6, 0x604($sp)
  add.s $f8, $f4, $f0
  mul.s $f4, $f6, $f28
  swc1  $f10, 0x508($sp)
  lwc1  $f10, 0x614($sp)
  swc1  $f8, 0x4f4($sp)
  mul.s $f6, $f10, $f28
  add.s $f8, $f4, $f0
  lwc1  $f4, 0x61c($sp)
  swc1  $f8, 0x50c($sp)
  swc1  $f6, 0x520($sp)
  mtc1  $at, $f6
  mul.s $f8, $f4, $f28
  div.s $f4, $f6, $f24
  add.s $f10, $f8, $f0
  swc1  $f10, 0x524($sp)
  jal   sub_GAME_7F093CB0
   swc1  $f4, 0x58($sp)
  addiu $a0, $sp, 0x4cc
  jal   sub_GAME_7F093CB0
   lw    $a1, 0x580($sp)
  addiu $a0, $sp, 0x4e4
  jal   sub_GAME_7F093CB0
   lw    $a1, 0x584($sp)
  addiu $a0, $sp, 0x4fc
  jal   sub_GAME_7F093CB0
   lw    $a1, 0x574($sp)
  addiu $a0, $sp, 0x514
  jal   sub_GAME_7F093CB0
   lw    $a1, 0x57c($sp)
  b     .L7F096E2C
   lw    $t7, 0x6b0($sp)
def_7F095E0C:
.L7F096E20:
  b     .L7F097360
   move  $v0, $v1
  lw    $t7, 0x6b0($sp)
.L7F096E2C:
  lui   $t4, 0xe700
  addiu $t5, $t7, 8
  sw    $t5, 0x6b0($sp)
  sw    $zero, 4($t7)
  jal   get_ptr_currentdata
   sw    $t4, ($t7)
  lh    $t9, 0x10($v0)
  lui   $t3, %hi(skywaterimages) 
  lw    $t3, %lo(skywaterimages)($t3)
  sll   $t8, $t9, 2
  subu  $t8, $t8, $t9
  sll   $t8, $t8, 2
  li    $t6, 2
  sw    $t6, 0x10($sp)
  addiu $a0, $sp, 0x6b0
  li    $a2, 1
  move  $a3, $zero
  jal   likely_generate_DL_for_image_declaration
   addu  $a1, $t8, $t3
  lw    $t2, 0x6b0($sp)
  lui   $t5, 0xfb00
  addiu $t7, $t2, 8
  sw    $t7, 0x6b0($sp)
  sw    $t5, ($t2)
  jal   get_ptr_currentdata
   sw    $t2, 0x228($sp)
  jal   get_ptr_currentdata
   move  $s0, $v0
  jal   get_ptr_currentdata
   sw    $v0, 0x6c($sp)
  lw    $t3, 0x6c($sp)
  lbu   $t9, 0xa($v0)
  lbu   $t2, 8($t3)
  sll   $t8, $t9, 8
  lbu   $t9, 9($s0)
  sll   $t7, $t2, 0x18
  or    $t5, $t8, $t7
  lw    $t8, 0x228($sp)
  sll   $t3, $t9, 0x10
  or    $t6, $t5, $t3
  ori   $t2, $t6, 0xff
  sw    $t2, 4($t8)
  lw    $t7, 0x6b0($sp)
  lui   $t5, (0x55FEF97C >> 16) # lui $t5, 0x55fe
  lui   $t9, (0xFC40FE81 >> 16) # lui $t9, 0xfc40
  addiu $t4, $t7, 8
  sw    $t4, 0x6b0($sp)
  ori   $t9, (0xFC40FE81 & 0xFFFF) # ori $t9, $t9, 0xfe81
  ori   $t5, (0x55FEF97C & 0xFFFF) # ori $t5, $t5, 0xf97c
  sw    $t5, 4($t7)
  jal   get_BONDdata_field_10DC
   sw    $t9, ($t7)
  jal   get_BONDdata_field_10CC
   move  $s0, $v0
  move  $a0, $s0
  move  $a1, $v0
  jal   matrix_4x4_multiply
   addiu $a2, $sp, 0x1e4
  lwc1  $f8, 0x58($sp)
  lui   $a0, %hi(dword_CODE_bss_80079E98)
  addiu $a0, %lo(dword_CODE_bss_80079E98) # addiu $a0, $a0, -0x6168
  mfc1  $a1, $f8
  mfc1  $a2, $f8
  mfc1  $a3, $f8
  jal   guScaleF
   nop   
  lui   $a1, %hi(dword_CODE_bss_80079E98)
  addiu $a1, %lo(dword_CODE_bss_80079E98) # addiu $a1, $a1, -0x6168
  addiu $a0, $sp, 0x1e4
  jal   matrix_4x4_multiply
   addiu $a2, $sp, 0x1a4
  blez  $s1, .L7F097024
   sw    $zero, 0x88($sp)
  addiu $a0, $sp, 0x4b4
  sw    $a0, 0x58($sp)
  addiu $s0, $sp, 0x8c
.L7F096F5C:
  lui   $at, %hi(D_800575D0)
  lwc1  $f0, %lo(D_800575D0)($at)
  lw    $a0, 0x58($sp)
  addiu $a1, $sp, 0x1a4
  mfc1  $a3, $f0
  li    $a2, 130
  sw    $s0, 0x14($sp)
  jal   sub_GAME_7F097388
   swc1  $f0, 0x10($sp)
  jal   getPlayer_c_screenleft
   nop   
  jal   getPlayer_c_screenleft
   mov.s $f20, $f0
  jal   getPlayer_c_screenwidth
   mov.s $f22, $f0
  add.s $f10, $f0, $f22
  mul.s $f14, $f20, $f26
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  mul.s $f6, $f10, $f26
  lwc1  $f12, 0x28($s0)
  sub.s $f8, $f6, $f4
  mfc1  $a2, $f8
  jal   sub_GAME_7F093C48
   nop   
  jal   getPlayer_c_screentop
   swc1  $f0, 0x28($s0)
  jal   getPlayer_c_screentop
   mov.s $f20, $f0
  jal   getPlayer_c_screenheight
   mov.s $f22, $f0
  add.s $f10, $f0, $f22
  mul.s $f14, $f20, $f26
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  mul.s $f6, $f10, $f26
  lwc1  $f12, 0x2c($s0)
  sub.s $f8, $f6, $f4
  mfc1  $a2, $f8
  jal   sub_GAME_7F093C48
   nop   
  lw    $v0, 0x88($sp)
  swc1  $f0, 0x2c($s0)
  lw    $t3, 0x58($sp)
  addiu $v0, $v0, 1
  sw    $v0, 0x88($sp)
  addiu $t6, $t3, 0x18
  sw    $t6, 0x58($sp)
  bne   $v0, $s1, .L7F096F5C
   addiu $s0, $s0, 0x38
.L7F097024:
  li    $at, 4
  bne   $s1, $at, .L7F097290
   lw    $t2, 0x5c($sp)
  li    $at, 12
  bne   $t2, $at, .L7F097230
   addiu $s0, $sp, 0x8c
  lwc1  $f10, 0x548($sp)
  lwc1  $f6, 0x54c($sp)
  lwc1  $f8, 0xf0($sp)
  c.lt.s $f10, $f6
  lwc1  $f10, 0xb8($sp)
  bc1fl .L7F097148
   add.s $f6, $f10, $f26
  add.s $f10, $f8, $f26
  lwc1  $f4, 0x160($sp)
  addiu $a1, $sp, 0x8c
  lw    $a0, 0x6b0($sp)
  c.le.s $f10, $f4
  addiu $a2, $sp, 0xc4
  addiu $a3, $sp, 0xfc
  li    $at, 0x43020000 # 130.000000
  bc1f  .L7F09712C
   li    $t8, 1
  jal   getPlayer_c_screenleft
   nop   
  mul.s $f6, $f0, $f26
  jal   getPlayer_c_screentop
   swc1  $f6, 0xb4($sp)
  mul.s $f8, $f0, $f26
  jal   getPlayer_c_screenleft
   swc1  $f8, 0xb8($sp)
  jal   getPlayer_c_screenwidth
   mov.s $f20, $f0
  add.s $f4, $f0, $f20
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  mul.s $f10, $f4, $f26
  sub.s $f8, $f10, $f6
  jal   getPlayer_c_screentop
   swc1  $f8, 0xec($sp)
  mul.s $f4, $f0, $f26
  jal   getPlayer_c_screenleft
   swc1  $f4, 0xf0($sp)
  mul.s $f10, $f0, $f26
  jal   getPlayer_c_screenleft
   swc1  $f10, 0x124($sp)
  jal   getPlayer_c_screenwidth
   mov.s $f20, $f0
  add.s $f6, $f0, $f20
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  li    $at, 0x43020000 # 130.000000
  mul.s $f8, $f6, $f26
  mtc1  $at, $f6
  addiu $s1, $sp, 0x134
  addiu $a1, $sp, 0x8c
  sw    $s1, 0x10($sp)
  lw    $a0, 0x6b0($sp)
  addiu $a2, $sp, 0xc4
  sub.s $f10, $f8, $f4
  addiu $a3, $sp, 0xfc
  swc1  $f6, 0x14($sp)
  jal   sub_GAME_7F098A2C
   swc1  $f10, 0x15c($sp)
  b     .L7F09735C
   sw    $v0, 0x6b0($sp)
.L7F09712C:
  mtc1  $at, $f8
  sw    $t8, 0x14($sp)
  jal   sub_GAME_7F097818
   swc1  $f8, 0x10($sp)
  b     .L7F09735C
   sw    $v0, 0x6b0($sp)
  add.s $f6, $f10, $f26
.L7F097148:
  lwc1  $f4, 0x128($sp)
  addiu $a2, $sp, 0x8c
  addiu $a3, $sp, 0x134
  c.le.s $f6, $f4
  lw    $a0, 0x6b0($sp)
  addiu $a1, $sp, 0xc4
  li    $at, 0x43020000 # 130.000000
  bc1f  .L7F097218
   li    $t4, 1
  jal   getPlayer_c_screenleft
   nop   
  mul.s $f8, $f0, $f26
  jal   getPlayer_c_screentop
   swc1  $f8, 0xb4($sp)
  mul.s $f10, $f0, $f26
  jal   getPlayer_c_screenleft
   swc1  $f10, 0xb8($sp)
  jal   getPlayer_c_screenwidth
   mov.s $f20, $f0
  add.s $f4, $f0, $f20
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  mul.s $f6, $f4, $f26
  sub.s $f10, $f6, $f8
  jal   getPlayer_c_screentop
   swc1  $f10, 0xec($sp)
  mul.s $f4, $f0, $f26
  jal   getPlayer_c_screenleft
   swc1  $f4, 0xf0($sp)
  mul.s $f6, $f0, $f26
  jal   getPlayer_c_screenleft
   swc1  $f6, 0x124($sp)
  jal   getPlayer_c_screenwidth
   mov.s $f20, $f0
  add.s $f8, $f0, $f20
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  li    $at, 0x43020000 # 130.000000
  mul.s $f10, $f8, $f26
  mtc1  $at, $f8
  addiu $t7, $sp, 0xfc
  addiu $a2, $sp, 0x8c
  addiu $a3, $sp, 0x134
  sw    $t7, 0x10($sp)
  lw    $a0, 0x6b0($sp)
  sub.s $f6, $f10, $f4
  addiu $a1, $sp, 0xc4
  swc1  $f8, 0x14($sp)
  jal   sub_GAME_7F098A2C
   swc1  $f6, 0x15c($sp)
  b     .L7F09735C
   sw    $v0, 0x6b0($sp)
.L7F097218:
  mtc1  $at, $f10
  sw    $t4, 0x14($sp)
  jal   sub_GAME_7F097818
   swc1  $f10, 0x10($sp)
  b     .L7F09735C
   sw    $v0, 0x6b0($sp)
.L7F097230:
  li    $at, 0x43020000 # 130.000000
  mtc1  $at, $f4
  addiu $s1, $sp, 0x134
  li    $t9, 1
  sw    $t9, 0x14($sp)
  move  $a3, $s1
  lw    $a0, 0x6b0($sp)
  move  $a1, $s0
  addiu $a2, $sp, 0xc4
  jal   sub_GAME_7F097818
   swc1  $f4, 0x10($sp)
  li    $at, 0x43020000 # 130.000000
  mtc1  $at, $f6
  li    $t5, 1
  sw    $v0, 0x6b0($sp)
  sw    $t5, 0x14($sp)
  move  $a0, $v0
  move  $a1, $s1
  addiu $a2, $sp, 0xfc
  move  $a3, $s0
  jal   sub_GAME_7F097818
   swc1  $f6, 0x10($sp)
  b     .L7F09735C
   sw    $v0, 0x6b0($sp)
.L7F097290:
  li    $at, 5
  bne   $s1, $at, .L7F097328
   addiu $s0, $sp, 0x8c
  li    $at, 0x43020000 # 130.000000
  mtc1  $at, $f8
  li    $t3, 1
  sw    $t3, 0x14($sp)
  lw    $a0, 0x6b0($sp)
  move  $a1, $s0
  addiu $a2, $sp, 0xc4
  addiu $a3, $sp, 0xfc
  jal   sub_GAME_7F097818
   swc1  $f8, 0x10($sp)
  li    $at, 0x43020000 # 130.000000
  mtc1  $at, $f10
  addiu $s1, $sp, 0x134
  li    $t6, 1
  sw    $v0, 0x6b0($sp)
  sw    $t6, 0x14($sp)
  move  $a3, $s1
  move  $a0, $v0
  move  $a1, $s0
  addiu $a2, $sp, 0xfc
  jal   sub_GAME_7F097818
   swc1  $f10, 0x10($sp)
  li    $at, 0x43020000 # 130.000000
  mtc1  $at, $f4
  li    $t2, 1
  sw    $v0, 0x6b0($sp)
  sw    $t2, 0x14($sp)
  move  $a0, $v0
  move  $a1, $s0
  move  $a2, $s1
  addiu $a3, $sp, 0x16c
  jal   sub_GAME_7F097818
   swc1  $f4, 0x10($sp)
  b     .L7F09735C
   sw    $v0, 0x6b0($sp)
.L7F097328:
  li    $at, 3
  bne   $s1, $at, .L7F09735C
   addiu $a1, $sp, 0x8c
  li    $at, 0x43020000 # 130.000000
  mtc1  $at, $f6
  li    $t8, 1
  sw    $t8, 0x14($sp)
  lw    $a0, 0x6b0($sp)
  addiu $a2, $sp, 0xc4
  addiu $a3, $sp, 0xfc
  jal   sub_GAME_7F097818
   swc1  $f6, 0x10($sp)
  sw    $v0, 0x6b0($sp)
.L7F09735C:
  lw    $v0, 0x6b0($sp)
.L7F097360:
  lw    $ra, 0x4c($sp)
  ldc1  $f20, 0x18($sp)
  ldc1  $f22, 0x20($sp)
  ldc1  $f24, 0x28($sp)
  ldc1  $f26, 0x30($sp)
  ldc1  $f28, 0x38($sp)
  lw    $s0, 0x44($sp)
  lw    $s1, 0x48($sp)
  jr    $ra
   addiu $sp, $sp, 0x6b0
");

asm(R"
glabel sub_GAME_7F097388
  addiu $sp, $sp, -0x78
  andi  $t6, $a2, 0xffff
  mtc1  $t6, $f4
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f12
  sw    $s0, 0x20($sp)
  mtc1  $a3, $f14
  move  $s0, $a0
  sw    $ra, 0x24($sp)
  sdc1  $f20, 0x18($sp)
  sw    $a2, 0x80($sp)
  bgez  $t6, .L7F0973CC
   cvt.s.w $f6, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F0973CC:
  lwc1  $f10, ($s0)
  lwc1  $f18, ($a1)
  div.s $f0, $f6, $f12
  lwc1  $f6, 0x10($a1)
  lwc1  $f8, 4($s0)
  mtc1  $zero, $f16
  mul.s $f4, $f10, $f18
  nop   
  mul.s $f10, $f8, $f6
  lwc1  $f6, 0x20($a1)
  lwc1  $f8, 8($s0)
  add.s $f18, $f4, $f10
  mul.s $f4, $f8, $f6
  lwc1  $f8, 0x30($a1)
  mov.s $f2, $f0
  add.s $f10, $f18, $f4
  add.s $f6, $f8, $f10
  swc1  $f6, 0x68($sp)
  lwc1  $f18, ($s0)
  lwc1  $f4, 4($a1)
  lwc1  $f10, 4($s0)
  lwc1  $f6, 0x14($a1)
  mul.s $f8, $f18, $f4
  nop   
  mul.s $f18, $f10, $f6
  lwc1  $f6, 0x24($a1)
  lwc1  $f10, 8($s0)
  add.s $f4, $f8, $f18
  mul.s $f8, $f10, $f6
  lwc1  $f10, 0x34($a1)
  add.s $f18, $f4, $f8
  add.s $f6, $f10, $f18
  swc1  $f6, 0x6c($sp)
  lwc1  $f4, ($s0)
  lwc1  $f8, 8($a1)
  lwc1  $f18, 4($s0)
  lwc1  $f6, 0x18($a1)
  mul.s $f10, $f4, $f8
  nop   
  mul.s $f4, $f18, $f6
  lwc1  $f6, 0x28($a1)
  lwc1  $f18, 8($s0)
  add.s $f8, $f10, $f4
  mul.s $f10, $f18, $f6
  lwc1  $f18, 0x38($a1)
  add.s $f4, $f8, $f10
  add.s $f6, $f18, $f4
  swc1  $f6, 0x70($sp)
  lwc1  $f10, 0xc($a1)
  lwc1  $f8, ($s0)
  lwc1  $f6, 0x1c($a1)
  lwc1  $f4, 4($s0)
  mul.s $f18, $f8, $f10
  nop   
  mul.s $f8, $f4, $f6
  lwc1  $f6, 0x2c($a1)
  lwc1  $f4, 8($s0)
  add.s $f10, $f18, $f8
  mul.s $f18, $f4, $f6
  lwc1  $f4, 0x3c($a1)
  add.s $f8, $f10, $f18
  div.s $f18, $f14, $f12
  add.s $f6, $f4, $f8
  swc1  $f6, 0x74($sp)
  lwc1  $f10, 0xc($s0)
  lwc1  $f6, 0x88($sp)
  mul.s $f4, $f10, $f18
  div.s $f10, $f6, $f12
  swc1  $f4, 0x60($sp)
  lwc1  $f8, 0x10($s0)
  lwc1  $f4, 0x74($sp)
  c.eq.s $f16, $f4
  mul.s $f18, $f8, $f10
  swc1  $f18, 0x64($sp)
  bc1f  .L7F097508
   lwc1  $f18, 0x68($sp)
  lui   $at, %hi(D_800575D4)
  b     .L7F09751C
   lwc1  $f20, %lo(D_800575D4)($at)
.L7F097508:
  lwc1  $f8, 0x74($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  mul.s $f10, $f8, $f0
  div.s $f20, $f6, $f10
.L7F09751C:
  c.lt.s $f20, $f16
  mov.s $f0, $f20
  bc1f  .L7F097530
   lui   $at, %hi(D_800575D8)
  lwc1  $f0, %lo(D_800575D8)($at)
.L7F097530:
  mul.s $f4, $f18, $f0
  lwc1  $f6, 0x6c($sp)
  mul.s $f8, $f4, $f2
  lwc1  $f4, 0x70($sp)
  mul.s $f10, $f6, $f0
  swc1  $f8, 0x48($sp)
  mul.s $f18, $f10, $f2
  lwc1  $f10, 0x74($sp)
  mul.s $f8, $f4, $f0
  swc1  $f18, 0x4c($sp)
  mul.s $f6, $f8, $f2
  nop   
  mul.s $f18, $f10, $f0
  swc1  $f6, 0x50($sp)
  mul.s $f4, $f18, $f2
  jal   getPlayer_c_screenwidth
   swc1  $f4, 0x54($sp)
  jal   getPlayer_c_screenwidth
   swc1  $f0, 0x2c($sp)
  jal   getPlayer_c_screenleft
   swc1  $f0, 0x30($sp)
  li    $at, 0x40000000 # 2.000000
  mtc1  $at, $f2
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f8
  lwc1  $f10, 0x30($sp)
  mul.s $f6, $f0, $f8
  lwc1  $f8, 0x48($sp)
  mul.s $f18, $f10, $f2
  lwc1  $f10, 0x2c($sp)
  add.s $f4, $f6, $f18
  mul.s $f6, $f10, $f2
  nop   
  mul.s $f18, $f8, $f6
  add.s $f10, $f4, $f18
  jal   getPlayer_c_screenheight
   swc1  $f10, 0x38($sp)
  jal   getPlayer_c_screenheight
   swc1  $f0, 0x2c($sp)
  jal   getPlayer_c_screentop
   swc1  $f0, 0x30($sp)
  lui   $at, %hi(D_800575DC)
  lwc1  $f2, %lo(D_800575DC)($at)
  li    $at, 0x40000000 # 2.000000
  mtc1  $at, $f16
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f8
  lwc1  $f4, 0x30($sp)
  lui   $at, %hi(D_800575E0)
  mul.s $f6, $f0, $f8
  lwc1  $f8, 0x4c($sp)
  lui   $a2, (0x457FA000 >> 16) # lui $a2, 0x457f
  mul.s $f18, $f4, $f16
  neg.s $f4, $f8
  ori   $a2, (0x457FA000 & 0xFFFF) # ori $a2, $a2, 0xa000
  lwc1  $f14, %lo(D_800575E0)($at)
  lwc1  $f12, 0x38($sp)
  add.s $f10, $f6, $f18
  lwc1  $f6, 0x2c($sp)
  mul.s $f18, $f6, $f16
  nop   
  mul.s $f8, $f4, $f18
  lwc1  $f4, 0x50($sp)
  mul.s $f18, $f4, $f2
  add.s $f6, $f10, $f8
  lwc1  $f8, 0x54($sp)
  add.s $f10, $f18, $f2
  swc1  $f6, 0x3c($sp)
  mtc1  $zero, $f6
  swc1  $f10, 0x40($sp)
  mul.s $f4, $f8, $f6
  jal   sub_GAME_7F093C48
   swc1  $f4, 0x44($sp)
  lui   $at, %hi(D_800575E4)
  lui   $a2, (0x457FA000 >> 16) # lui $a2, 0x457f
  swc1  $f0, 0x38($sp)
  ori   $a2, (0x457FA000 & 0xFFFF) # ori $a2, $a2, 0xa000
  lwc1  $f14, %lo(D_800575E4)($at)
  jal   sub_GAME_7F093C48
   lwc1  $f12, 0x3c($sp)
  mtc1  $zero, $f14
  lui   $a2, (0x46FFFE00 >> 16) # lui $a2, 0x46ff
  swc1  $f0, 0x3c($sp)
  ori   $a2, (0x46FFFE00 & 0xFFFF) # ori $a2, $a2, 0xfe00
  jal   sub_GAME_7F093C48
   lwc1  $f12, 0x40($sp)
  mtc1  $zero, $f14
  lui   $a2, (0x46FFFE00 >> 16) # lui $a2, 0x46ff
  swc1  $f0, 0x40($sp)
  ori   $a2, (0x46FFFE00 & 0xFFFF) # ori $a2, $a2, 0xfe00
  jal   sub_GAME_7F093C48
   lwc1  $f12, 0x44($sp)
  lw    $v1, 0x8c($sp)
  lwc1  $f18, 0x68($sp)
  swc1  $f0, 0x44($sp)
  swc1  $f18, ($v1)
  lwc1  $f10, 0x6c($sp)
  swc1  $f10, 4($v1)
  lwc1  $f8, 0x70($sp)
  swc1  $f8, 8($v1)
  lwc1  $f6, 0x74($sp)
  swc1  $f6, 0xc($v1)
  lwc1  $f4, 0x60($sp)
  swc1  $f4, 0x20($v1)
  lwc1  $f18, 0x64($sp)
  swc1  $f18, 0x24($v1)
  lwc1  $f10, 0x38($sp)
  jal   get_ptr_currentdata
   swc1  $f10, 0x28($v1)
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f6
  lwc1  $f8, 0x38($v0)
  lwc1  $f18, 0x3c($sp)
  lw    $v1, 0x8c($sp)
  mul.s $f4, $f8, $f6
  li    $at, 0x4F800000 # 4294967296.000000
  sub.s $f10, $f18, $f4
  swc1  $f10, 0x2c($v1)
  lwc1  $f8, 0x40($sp)
  swc1  $f20, 0x34($v1)
  swc1  $f8, 0x30($v1)
  lbu   $t7, 0x14($s0)
  mtc1  $t7, $f6
  bgez  $t7, .L7F097730
   cvt.s.w $f18, $f6
  mtc1  $at, $f4
  nop   
  add.s $f18, $f18, $f4
.L7F097730:
  swc1  $f18, 0x10($v1)
  lbu   $t8, 0x15($s0)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t8, $f10
  bgez  $t8, .L7F097754
   cvt.s.w $f8, $f10
  mtc1  $at, $f6
  nop   
  add.s $f8, $f8, $f6
.L7F097754:
  swc1  $f8, 0x14($v1)
  lbu   $t9, 0x16($s0)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t9, $f4
  bgez  $t9, .L7F097778
   cvt.s.w $f18, $f4
  mtc1  $at, $f10
  nop   
  add.s $f18, $f18, $f10
.L7F097778:
  swc1  $f18, 0x18($v1)
  lbu   $t0, 0x17($s0)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t0, $f6
  bgez  $t0, .L7F09779C
   cvt.s.w $f8, $f6
  mtc1  $at, $f4
  nop   
  add.s $f8, $f8, $f4
.L7F09779C:
  swc1  $f8, 0x1c($v1)
  lw    $ra, 0x24($sp)
  lw    $s0, 0x20($sp)
  ldc1  $f20, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x78
");

asm(R"
glabel sub_GAME_7F0977B4
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lwc1  $f6, 0x28($a1)
  lwc1  $f4, 0x28($a0)
  lwc1  $f10, 0x2c($a1)
  lwc1  $f8, 0x2c($a0)
  sub.s $f0, $f4, $f6
  sub.s $f2, $f8, $f10
  mul.s $f16, $f0, $f0
  nop   
  mul.s $f18, $f2, $f2
  jal   sqrtf
   add.s $f12, $f16, $f18
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  c.lt.s $f0, $f4
  move  $v1, $zero
  bc1f  .L7F097810
   nop   
  b     .L7F097810
   li    $v1, 1
.L7F097810:
  jr    $ra
   move  $v0, $v1
");

asm(R"
.late_rodata
glabel D_800575E8
.word 0xc4eac000 /*-1878.0*/
glabel D_800575EC
.word 0xc4eac000 /*-1878.0*/
glabel D_800575F0
.word 0xc4eac000 /*-1878.0*/
glabel D_800575F4
.word 0x46fffe00 /*32767.0*/
.text
glabel sub_GAME_7F097818
  addiu $sp, $sp, -0x488
  sw    $s0, 0x20($sp)
  move  $s0, $a0
  sw    $ra, 0x24($sp)
  sw    $a1, 0x48c($sp)
  move  $a0, $a1
  sdc1  $f20, 0x18($sp)
  move  $a1, $a2
  sw    $a2, 0x490($sp)
  jal   sub_GAME_7F0977B4
   sw    $a3, 0x494($sp)
  lw    $a2, 0x490($sp)
  bnez  $v0, .L7F097898
   lw    $a3, 0x494($sp)
  move  $a0, $a2
  move  $a1, $a3
  sw    $a2, 0x490($sp)
  jal   sub_GAME_7F0977B4
   sw    $a3, 0x494($sp)
  lw    $t7, 0x48c($sp)
  lw    $a2, 0x490($sp)
  bnez  $v0, .L7F097898
   lw    $a3, 0x494($sp)
  move  $a0, $a3
  move  $a1, $t7
  sw    $a2, 0x490($sp)
  jal   sub_GAME_7F0977B4
   sw    $a3, 0x494($sp)
  lw    $v1, 0x48c($sp)
  lw    $a2, 0x490($sp)
  beqz  $v0, .L7F0978A0
   lw    $a3, 0x494($sp)
.L7F097898:
  b     .L7F098A18
   move  $v0, $s0
.L7F0978A0:
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f4
  lwc1  $f8, 0x498($sp)
  mtc1  $zero, $f20
  div.s $f6, $f8, $f4
  swc1  $f6, 0x378($sp)
  lwc1  $f8, 0x2c($a2)
  lwc1  $f10, 0x28($a2)
  lwc1  $f0, 0x28($v1)
  swc1  $f8, 0x5c($sp)
  lwc1  $f6, 0x28($a3)
  sub.s $f12, $f10, $f0
  lwc1  $f14, 0x2c($v1)
  lwc1  $f4, 0x5c($sp)
  sub.s $f10, $f6, $f0
  sub.s $f16, $f4, $f14
  swc1  $f10, 0x46c($sp)
  lwc1  $f8, 0x2c($a3)
  lwc1  $f6, 0x46c($sp)
  swc1  $f8, 0x54($sp)
  lwc1  $f4, 0x54($sp)
  mul.s $f10, $f6, $f16
  mtc1  $at, $f6
  sub.s $f18, $f4, $f14
  mul.s $f8, $f12, $f18
  sub.s $f4, $f10, $f8
  lwc1  $f8, 0x5c($sp)
  div.s $f2, $f4, $f6
  c.eq.s $f20, $f2
  swc1  $f2, 0x444($sp)
  bc1fl .L7F09792C
   c.lt.s $f8, $f14
  b     .L7F098A18
   move  $v0, $s0
  c.lt.s $f8, $f14
.L7F09792C:
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  move  $t1, $v1
  move  $t0, $a2
  move  $t3, $a3
  bc1f  .L7F097968
   div.s $f16, $f10, $f2
  li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f12
  move  $t0, $v1
  move  $t1, $a2
  mul.s $f14, $f2, $f12
  swc1  $f14, 0x444($sp)
  mul.s $f16, $f16, $f12
  nop   
.L7F097968:
  lwc1  $f0, 0x2c($t0)
  lwc1  $f4, 0x54($sp)
  li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f12
  c.lt.s $f4, $f0
  lwc1  $f14, 0x444($sp)
  li    $at, 0x3E800000 # 0.250000
  bc1fl .L7F0979A4
   swc1  $f14, 0x444($sp)
  mul.s $f14, $f14, $f12
  move  $t3, $t0
  move  $t0, $a3
  mul.s $f16, $f16, $f12
  lwc1  $f0, 0x2c($a3)
  swc1  $f14, 0x444($sp)
.L7F0979A4:
  swc1  $f16, 0x440($sp)
  lwc1  $f6, 0x2c($t1)
  c.lt.s $f0, $f6
  mtc1  $at, $f0
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f2
  bc1f  .L7F0979E0
   li    $at, 0x3E800000 # 0.250000
  mul.s $f14, $f14, $f12
  move  $v0, $t0
  move  $t0, $t1
  mul.s $f16, $f16, $f12
  move  $t1, $v0
  swc1  $f14, 0x444($sp)
  swc1  $f16, 0x440($sp)
.L7F0979E0:
  lwc1  $f10, 0x28($t0)
  mtc1  $at, $f8
  swc1  $f20, 0x424($sp)
  lui   $a2, (0x44EAA000 >> 16) # lui $a2, 0x44ea
  mul.s $f4, $f10, $f8
  mtc1  $at, $f10
  ori   $a2, (0x44EAA000 & 0xFFFF) # ori $a2, $a2, 0xa000
  swc1  $f4, 0x420($sp)
  lwc1  $f6, 0x28($t1)
  swc1  $f20, 0x42c($sp)
  mul.s $f8, $f6, $f10
  mtc1  $at, $f6
  lui   $at, %hi(D_800575E8)
  swc1  $f8, 0x428($sp)
  lwc1  $f4, 0x28($t1)
  swc1  $f20, 0x434($sp)
  swc1  $f20, 0x43c($sp)
  mul.s $f10, $f4, $f6
  swc1  $f20, 0x438($sp)
  swc1  $f10, 0x430($sp)
  lwc1  $f8, 0x28($t3)
  swc1  $f8, 0x448($sp)
  lwc1  $f4, 0x2c($t3)
  swc1  $f4, 0x44c($sp)
  lwc1  $f6, 0x28($t0)
  swc1  $f6, 0x450($sp)
  lwc1  $f10, 0x2c($t0)
  lwc1  $f6, 0x450($sp)
  swc1  $f10, 0x454($sp)
  lwc1  $f8, 0x28($t1)
  swc1  $f8, 0x458($sp)
  lwc1  $f10, 0x458($sp)
  lwc1  $f4, 0x2c($t1)
  swc1  $f6, 0x28($sp)
  sub.s $f8, $f6, $f10
  swc1  $f4, 0x45c($sp)
  lwc1  $f4, 0x454($sp)
  lwc1  $f6, 0x45c($sp)
  swc1  $f8, 0x474($sp)
  swc1  $f8, 0x30($sp)
  swc1  $f10, 0x2c($sp)
  lwc1  $f8, 0x2c($sp)
  sub.s $f16, $f4, $f6
  swc1  $f4, 0x2c($sp)
  lwc1  $f4, 0x44c($sp)
  lwc1  $f10, 0x448($sp)
  swc1  $f20, 0x3fc($sp)
  sub.s $f18, $f4, $f6
  lwc1  $f6, 0x28($sp)
  swc1  $f20, 0x3f8($sp)
  sub.s $f8, $f10, $f8
  swc1  $f20, 0x3dc($sp)
  swc1  $f20, 0x3d8($sp)
  sub.s $f12, $f10, $f6
  lwc1  $f10, 0x2c($sp)
  swc1  $f8, 0x46c($sp)
  swc1  $f20, 0x3a0($sp)
  mul.s $f6, $f12, $f0
  sub.s $f14, $f4, $f10
  lwc1  $f10, 0x30($sp)
  swc1  $f12, 0x464($sp)
  swc1  $f20, 0x3a8($sp)
  mul.s $f4, $f14, $f0
  swc1  $f14, 0x460($sp)
  swc1  $f6, 0x3e0($sp)
  mul.s $f6, $f10, $f0
  swc1  $f20, 0x3b0($sp)
  swc1  $f20, 0x3bc($sp)
  swc1  $f20, 0x3b8($sp)
  swc1  $f4, 0x3e4($sp)
  mul.s $f4, $f16, $f0
  swc1  $f20, 0x380($sp)
  swc1  $f6, 0x3e8($sp)
  mul.s $f6, $f8, $f0
  swc1  $f20, 0x388($sp)
  swc1  $f20, 0x390($sp)
  swc1  $f20, 0x39c($sp)
  swc1  $f4, 0x3ec($sp)
  mul.s $f4, $f18, $f0
  lwc1  $f0, 0x460($sp)
  swc1  $f6, 0x3f0($sp)
  mul.s $f6, $f12, $f2
  swc1  $f20, 0x398($sp)
  sw    $t3, 0x47c($sp)
  sw    $t1, 0x484($sp)
  swc1  $f4, 0x3f4($sp)
  mul.s $f4, $f14, $f2
  lwc1  $f14, %lo(D_800575E8)($at)
  swc1  $f6, 0x3c0($sp)
  mul.s $f6, $f10, $f2
  sw    $t0, 0x480($sp)
  swc1  $f4, 0x3c4($sp)
  mul.s $f4, $f16, $f2
  swc1  $f6, 0x3c8($sp)
  mul.s $f6, $f8, $f2
  swc1  $f4, 0x3cc($sp)
  mul.s $f4, $f18, $f2
  swc1  $f6, 0x3d0($sp)
  div.s $f6, $f2, $f0
  swc1  $f4, 0x3d4($sp)
  div.s $f4, $f2, $f16
  swc1  $f6, 0x3a4($sp)
  div.s $f6, $f2, $f18
  swc1  $f4, 0x3ac($sp)
  lwc1  $f4, 0x464($sp)
  div.s $f12, $f4, $f0
  swc1  $f6, 0x3b4($sp)
  div.s $f4, $f8, $f18
  swc1  $f12, 0x384($sp)
  div.s $f6, $f10, $f16
  swc1  $f4, 0x394($sp)
  jal   sub_GAME_7F093C48
   swc1  $f6, 0x38c($sp)
  lui   $at, %hi(D_800575EC)
  lui   $a2, (0x44EAA000 >> 16) # lui $a2, 0x44ea
  swc1  $f0, 0x384($sp)
  ori   $a2, (0x44EAA000 & 0xFFFF) # ori $a2, $a2, 0xa000
  lwc1  $f14, %lo(D_800575EC)($at)
  jal   sub_GAME_7F093C48
   lwc1  $f12, 0x38c($sp)
  lui   $at, %hi(D_800575F0)
  lui   $a2, (0x44EAA000 >> 16) # lui $a2, 0x44ea
  swc1  $f0, 0x38c($sp)
  ori   $a2, (0x44EAA000 & 0xFFFF) # ori $a2, $a2, 0xa000
  lwc1  $f14, %lo(D_800575F0)($at)
  jal   sub_GAME_7F093C48
   lwc1  $f12, 0x394($sp)
  lw    $t1, 0x484($sp)
  swc1  $f0, 0x394($sp)
  li    $at, 0x3E800000 # 0.250000
  mtc1  $at, $f6
  lwc1  $f10, 0x2c($t1)
  li    $at, 0x46000000 # 8192.000000
  mul.s $f2, $f10, $f6
  trunc.w.s $f8, $f2
  mfc1  $t9, $f8
  lwc1  $f8, 0x38c($sp)
  mtc1  $t9, $f4
  nop   
  cvt.s.w $f10, $f4
  mtc1  $at, $f4
  nop   
  mul.s $f12, $f8, $f4
  sub.s $f6, $f2, $f10
  jal   addpoint5tofloat
   swc1  $f6, 0x37c($sp)
  li    $at, 0x39000000 # 0.000122
  mtc1  $at, $f10
  lwc1  $f8, 0x37c($sp)
  li    $at, 0x46000000 # 8192.000000
  mul.s $f6, $f0, $f10
  lwc1  $f10, 0x428($sp)
  mul.s $f4, $f6, $f8
  lwc1  $f8, 0x394($sp)
  sub.s $f6, $f10, $f4
  mtc1  $at, $f10
  nop   
  mul.s $f12, $f8, $f10
  jal   addpoint5tofloat
   swc1  $f6, 0x408($sp)
  li    $at, 0x39000000 # 0.000122
  mtc1  $at, $f4
  lwc1  $f8, 0x37c($sp)
  lui   $a3, 0xb400
  mul.s $f6, $f0, $f4
  lwc1  $f4, 0x430($sp)
  lw    $t0, 0x480($sp)
  lw    $t1, 0x484($sp)
  lw    $t3, 0x47c($sp)
  move  $a1, $s0
  addiu $s0, $s0, 8
  mul.s $f10, $f6, $f8
  lui   $a2, 0xc800
  move  $v1, $zero
  sub.s $f6, $f4, $f10
  swc1  $f6, 0x410($sp)
  sw    $a3, ($a1)
  lw    $t8, 0x49c($sp)
  lwc1  $f8, 0x444($sp)
  beqz  $t8, .L7F097CBC
   nop   
  b     .L7F097CBC
   lui   $a2, 0xce00
.L7F097CBC:
  c.lt.s $f8, $f20
  nop   
  bc1f  .L7F097CD4
   nop   
  b     .L7F097CD4
   lui   $v1, 0x80
.L7F097CD4:
  lwc1  $f4, 0x2c($t3)
  or    $t7, $v1, $a2
  move  $v0, $s0
  trunc.w.s $f10, $f4
  lui   $t6, 0xb200
  addiu $s0, $s0, 8
  move  $a0, $s0
  mfc1  $t9, $f10
  li    $at, 0x3E800000 # 0.250000
  addiu $s0, $s0, 8
  or    $t8, $t7, $t9
  sw    $t8, 4($a1)
  sw    $t6, ($v0)
  lwc1  $f6, 0x2c($t0)
  lwc1  $f4, 0x2c($t1)
  trunc.w.s $f8, $f6
  trunc.w.s $f10, $f4
  mfc1  $t9, $f8
  mtc1  $at, $f8
  mfc1  $t7, $f10
  sll   $t8, $t9, 0x10
  or    $t9, $t8, $t7
  sw    $t9, 4($v0)
  sw    $a3, ($a0)
  lwc1  $f6, 0x28($t0)
  sw    $t3, 0x47c($sp)
  sw    $t1, 0x484($sp)
  mul.s $f12, $f6, $f8
  sw    $t0, 0x480($sp)
  jal   sub_GAME_7F094298
   sw    $a0, 0x180($sp)
  lw    $a0, 0x180($sp)
  move  $v1, $s0
  lui   $t6, 0xb200
  sw    $v0, 4($a0)
  sw    $t6, ($v1)
  sw    $v1, 0x17c($sp)
  lwc1  $f12, 0x384($sp)
  jal   sub_GAME_7F094298
   addiu $s0, $s0, 8
  lw    $v1, 0x17c($sp)
  move  $a0, $s0
  lui   $t8, 0xb400
  sw    $v0, 4($v1)
  sw    $t8, ($a0)
  sw    $a0, 0x178($sp)
  lwc1  $f12, 0x410($sp)
  jal   sub_GAME_7F094298
   addiu $s0, $s0, 8
  lw    $a0, 0x178($sp)
  move  $v1, $s0
  lui   $t7, 0xb200
  sw    $v0, 4($a0)
  sw    $t7, ($v1)
  sw    $v1, 0x174($sp)
  lwc1  $f12, 0x394($sp)
  jal   sub_GAME_7F094298
   addiu $s0, $s0, 8
  lw    $v1, 0x174($sp)
  move  $a0, $s0
  lui   $t9, 0xb400
  sw    $v0, 4($v1)
  sw    $t9, ($a0)
  sw    $a0, 0x170($sp)
  lwc1  $f12, 0x408($sp)
  jal   sub_GAME_7F094298
   addiu $s0, $s0, 8
  lw    $a0, 0x170($sp)
  move  $v1, $s0
  lui   $t6, 0xb200
  sw    $v0, 4($a0)
  sw    $t6, ($v1)
  sw    $v1, 0x16c($sp)
  lwc1  $f12, 0x38c($sp)
  jal   sub_GAME_7F094298
   addiu $s0, $s0, 8
  lw    $v1, 0x16c($sp)
  lw    $t0, 0x480($sp)
  lw    $t1, 0x484($sp)
  lw    $t3, 0x47c($sp)
  sw    $v0, 4($v1)
  lw    $t8, 0x49c($sp)
  lwc1  $f0, 0x378($sp)
  lui    $at, %hi(D_800575F4)
  bnezl $t8, .L7F097E38
   lwc1  $f4, 0xc($t1)
  b     .L7F098A18
   move  $v0, $s0
  lwc1  $f4, 0xc($t1)
.L7F097E38:
  mul.s $f10, $f4, $f0
  swc1  $f10, 0x36c($sp)
  lwc1  $f6, 0xc($t0)
  lwc1  $f18, 0x36c($sp)
  mul.s $f8, $f6, $f0
  swc1  $f8, 0x370($sp)
  lwc1  $f4, 0xc($t3)
  lwc1  $f6, 0x370($sp)
  mul.s $f10, $f4, $f0
  c.lt.s $f6, $f18
  swc1  $f10, 0x374($sp)
  bc1f  .L7F097E70
   lwc1  $f0, 0x374($sp)
  mov.s $f18, $f6
.L7F097E70:
  c.lt.s $f0, $f18
  nop   
  bc1f  .L7F097E84
   nop   
  mov.s $f18, $f0
.L7F097E84:
  lwc1  $f0, %lo(D_800575F4)($at)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f2
  lwc1  $f8, 0x34($t1)
  mul.s $f18, $f18, $f2
  nop   
  mul.s $f4, $f8, $f18
  swc1  $f4, 0x35c($sp)
  lwc1  $f10, 0x34($t0)
  mul.s $f6, $f10, $f18
  lwc1  $f10, 0x35c($sp)
  swc1  $f6, 0x360($sp)
  lwc1  $f8, 0x34($t3)
  mul.s $f4, $f8, $f18
  swc1  $f4, 0x364($sp)
  lwc1  $f6, 0x20($t1)
  mul.s $f8, $f10, $f6
  swc1  $f8, 0x338($sp)
  lwc1  $f4, 0x24($t1)
  c.le.s $f20, $f8
  mul.s $f6, $f10, $f4
  nop   
  mul.s $f4, $f10, $f0
  swc1  $f6, 0x33c($sp)
  lwc1  $f6, 0x360($sp)
  swc1  $f4, 0x340($sp)
  lwc1  $f10, 0x20($t0)
  mul.s $f4, $f6, $f10
  swc1  $f4, 0x344($sp)
  lwc1  $f10, 0x24($t0)
  mul.s $f4, $f6, $f10
  nop   
  mul.s $f10, $f6, $f0
  swc1  $f4, 0x348($sp)
  lwc1  $f4, 0x364($sp)
  swc1  $f10, 0x34c($sp)
  lwc1  $f6, 0x20($t3)
  mul.s $f10, $f4, $f6
  swc1  $f10, 0x350($sp)
  lwc1  $f6, 0x24($t3)
  mul.s $f10, $f4, $f6
  nop   
  mul.s $f6, $f4, $f0
  lwc1  $f0, 0x33c($sp)
  swc1  $f10, 0x354($sp)
  bc1f  .L7F097F48
   swc1  $f6, 0x358($sp)
  b     .L7F097F50
   mov.s $f14, $f8
.L7F097F48:
  lwc1  $f14, 0x338($sp)
  neg.s $f14, $f14
.L7F097F50:
  c.le.s $f20, $f0
  nop   
  bc1fl .L7F097F6C
   neg.s $f16, $f0
  b     .L7F097F6C
   mov.s $f16, $f0
  neg.s $f16, $f0
.L7F097F6C:
  lwc1  $f0, 0x344($sp)
  c.le.s $f20, $f0
  nop   
  bc1fl .L7F097F8C
   neg.s $f12, $f0
  b     .L7F097F8C
   mov.s $f12, $f0
  neg.s $f12, $f0
.L7F097F8C:
  c.lt.s $f14, $f12
  nop   
  bc1fl .L7F097FBC
   lwc1  $f0, 0x348($sp)
  c.le.s $f20, $f0
  nop   
  bc1fl .L7F097FB8
   neg.s $f14, $f0
  b     .L7F097FB8
   mov.s $f14, $f0
  neg.s $f14, $f0
.L7F097FB8:
  lwc1  $f0, 0x348($sp)
.L7F097FBC:
  c.le.s $f20, $f0
  nop   
  bc1fl .L7F097FD8
   neg.s $f12, $f0
  b     .L7F097FD8
   mov.s $f12, $f0
  neg.s $f12, $f0
.L7F097FD8:
  c.lt.s $f16, $f12
  swc1  $f18, 0x368($sp)
  bc1fl .L7F098010
   lwc1  $f0, 0x350($sp)
  c.le.s $f20, $f0
  nop   
  bc1fl .L7F098008
   neg.s $f16, $f0
  mov.s $f16, $f0
  b     .L7F09800C
   swc1  $f18, 0x368($sp)
  neg.s $f16, $f0
.L7F098008:
  swc1  $f18, 0x368($sp)
.L7F09800C:
  lwc1  $f0, 0x350($sp)
.L7F098010:
  c.le.s $f20, $f0
  nop   
  bc1fl .L7F09802C
   neg.s $f12, $f0
  b     .L7F09802C
   mov.s $f12, $f0
  neg.s $f12, $f0
.L7F09802C:
  c.lt.s $f14, $f12
  swc1  $f14, 0x330($sp)
  bc1fl .L7F098060
   lwc1  $f0, 0x354($sp)
  c.le.s $f20, $f0
  nop   
  bc1fl .L7F098058
   neg.s $f14, $f0
  b     .L7F09805C
   swc1  $f0, 0x330($sp)
  neg.s $f14, $f0
.L7F098058:
  swc1  $f14, 0x330($sp)
.L7F09805C:
  lwc1  $f0, 0x354($sp)
.L7F098060:
  c.le.s $f20, $f0
  nop   
  bc1fl .L7F09807C
   neg.s $f12, $f0
  b     .L7F09807C
   mov.s $f12, $f0
  neg.s $f12, $f0
.L7F09807C:
  c.lt.s $f16, $f12
  swc1  $f16, 0x334($sp)
  bc1fl .L7F0980B0
   lwc1  $f10, 0x10($t1)
  c.le.s $f20, $f0
  nop   
  bc1fl .L7F0980A8
   neg.s $f16, $f0
  b     .L7F0980AC
   swc1  $f0, 0x334($sp)
  neg.s $f16, $f0
.L7F0980A8:
  swc1  $f16, 0x334($sp)
.L7F0980AC:
  lwc1  $f10, 0x10($t1)
.L7F0980B0:
  addiu $a0, $sp, 0x2b0
  addiu $a2, $sp, 0x2f0
  add.s $f4, $f10, $f2
  addiu $v0, $sp, 0x310
  addiu $v1, $sp, 0x290
  addiu $a1, $sp, 0x2d0
  swc1  $f4, 0x310($sp)
  lwc1  $f6, 0x14($t1)
  addiu $a3, $sp, 0x2f0
  add.s $f8, $f6, $f2
  swc1  $f8, 0x314($sp)
  lwc1  $f10, 0x18($t1)
  add.s $f4, $f10, $f2
  swc1  $f4, 0x318($sp)
  lwc1  $f6, 0x1c($t1)
  add.s $f8, $f6, $f2
  swc1  $f8, 0x31c($sp)
  lwc1  $f10, 0x10($t0)
  add.s $f4, $f10, $f2
  swc1  $f4, 0x2f0($sp)
  lwc1  $f6, 0x14($t0)
  add.s $f8, $f6, $f2
  swc1  $f8, 0x2f4($sp)
  lwc1  $f10, 0x18($t0)
  add.s $f4, $f10, $f2
  swc1  $f4, 0x2f8($sp)
  lwc1  $f6, 0x1c($t0)
  add.s $f8, $f6, $f2
  swc1  $f8, 0x2fc($sp)
  lwc1  $f10, 0x10($t3)
  add.s $f4, $f10, $f2
  swc1  $f4, 0x2d0($sp)
  lwc1  $f6, 0x14($t3)
  add.s $f8, $f6, $f2
  swc1  $f8, 0x2d4($sp)
  lwc1  $f10, 0x18($t3)
  add.s $f4, $f10, $f2
  lwc1  $f10, 0x338($sp)
  swc1  $f4, 0x2d8($sp)
  lwc1  $f6, 0x1c($t3)
  swc1  $f10, 0x320($sp)
  lwc1  $f4, 0x33c($sp)
  add.s $f8, $f6, $f2
  lwc1  $f6, 0x340($sp)
  lwc1  $f10, 0x348($sp)
  swc1  $f4, 0x324($sp)
  swc1  $f8, 0x2dc($sp)
  lwc1  $f8, 0x344($sp)
  swc1  $f6, 0x328($sp)
  swc1  $f10, 0x304($sp)
  swc1  $f8, 0x300($sp)
  lwc1  $f4, 0x34c($sp)
  lwc1  $f8, 0x354($sp)
  lwc1  $f10, 0x358($sp)
  lwc1  $f6, 0x350($sp)
  swc1  $f4, 0x308($sp)
  swc1  $f8, 0x2e4($sp)
  swc1  $f10, 0x2e8($sp)
  swc1  $f6, 0x2e0($sp)
  lwc1  $f4, 0x30($t1)
  addiu $t1, $sp, 0x230
  swc1  $f4, 0x32c($sp)
  lwc1  $f6, 0x30($t0)
  addiu $t0, $sp, 0x230
  swc1  $f6, 0x30c($sp)
  lwc1  $f8, 0x30($t3)
  swc1  $f8, 0x2ec($sp)
.L7F0981BC:
  lwc1  $f0, ($v0)
  lwc1  $f10, ($a2)
  lwc1  $f6, ($a1)
  addiu $a1, $a1, 4
  sub.s $f4, $f10, $f0
  sltu  $at, $a1, $a3
  addiu $a0, $a0, 4
  sub.s $f8, $f6, $f0
  addiu $a2, $a2, 4
  addiu $v0, $v0, 4
  addiu $v1, $v1, 4
  swc1  $f4, -4($a0)
  bnez  $at, .L7F0981BC
   swc1  $f8, -4($v1)
  addiu $a0, $sp, 0x2b0
  addiu $v0, $sp, 0x310
  addiu $v1, $sp, 0x290
  addiu $a3, $sp, 0x250
  addiu $a1, $sp, 0x270
  addiu $a2, $sp, 0x210
  lwc1  $f18, 0x3c8($sp)
.L7F098210:
  lwc1  $f0, ($v1)
  lwc1  $f10, 0x3cc($sp)
  lwc1  $f2, ($a0)
  lwc1  $f6, 0x3d4($sp)
  mul.s $f4, $f0, $f10
  li    $at, 0x47800000 # 65536.000000
  addiu $a2, $a2, 4
  mul.s $f8, $f6, $f2
  mtc1  $at, $f6
  addiu $a0, $a0, 4
  addiu $v0, $v0, 4
  addiu $v1, $v1, 4
  addiu $a3, $a3, 4
  addiu $a1, $a1, 4
  sub.s $f10, $f4, $f8
  addiu $t0, $t0, 4
  div.s $f12, $f10, $f6
  swc1  $f12, -4($a3)
  lwc1  $f4, 0x3d0($sp)
  mul.s $f8, $f2, $f4
  mtc1  $at, $f4
  sltu  $at, $a2, $t1
  mul.s $f10, $f18, $f0
  sub.s $f6, $f8, $f10
  div.s $f8, $f6, $f4
  swc1  $f8, -4($a1)
  lwc1  $f10, 0x440($sp)
  lwc1  $f4, -4($a1)
  mul.s $f6, $f12, $f10
  swc1  $f6, -4($v1)
  lwc1  $f8, 0x440($sp)
  lwc1  $f6, -4($v1)
  mul.s $f14, $f4, $f8
  lwc1  $f8, -4($v0)
  swc1  $f14, -4($a0)
  lwc1  $f10, 0x394($sp)
  mul.s $f4, $f10, $f6
  add.s $f16, $f4, $f14
  swc1  $f16, -4($t0)
  lwc1  $f10, 0x37c($sp)
  mul.s $f6, $f16, $f10
  sub.s $f4, $f8, $f6
  bnez  $at, .L7F098210
   swc1  $f4, -4($a2)
  jal   sub_GAME_7F094298
   lwc1  $f12, 0x210($sp)
  sw    $v0, 0x168($sp)
  jal   sub_GAME_7F094298
   lwc1  $f12, 0x214($sp)
  sw    $v0, 0x164($sp)
  jal   sub_GAME_7F094298
   lwc1  $f12, 0x218($sp)
  sw    $v0, 0x160($sp)
  jal   sub_GAME_7F094298
   lwc1  $f12, 0x21c($sp)
  sw    $v0, 0x15c($sp)
  jal   sub_GAME_7F094298
   lwc1  $f12, 0x290($sp)
  sw    $v0, 0x158($sp)
  jal   sub_GAME_7F094298
   lwc1  $f12, 0x294($sp)
  sw    $v0, 0x154($sp)
  jal   sub_GAME_7F094298
   lwc1  $f12, 0x298($sp)
  sw    $v0, 0x150($sp)
  jal   sub_GAME_7F094298
   lwc1  $f12, 0x29c($sp)
  sw    $v0, 0x14c($sp)
  jal   sub_GAME_7F094298
   lwc1  $f12, 0x2b0($sp)
  sw    $v0, 0x138($sp)
  jal   sub_GAME_7F094298
   lwc1  $f12, 0x2b4($sp)
  sw    $v0, 0x134($sp)
  jal   sub_GAME_7F094298
   lwc1  $f12, 0x2b8($sp)
  sw    $v0, 0x130($sp)
  jal   sub_GAME_7F094298
   lwc1  $f12, 0x2bc($sp)
  sw    $v0, 0x12c($sp)
  jal   sub_GAME_7F094298
   lwc1  $f12, 0x230($sp)
  sw    $v0, 0x148($sp)
  jal   sub_GAME_7F094298
   lwc1  $f12, 0x234($sp)
  sw    $v0, 0x144($sp)
  jal   sub_GAME_7F094298
   lwc1  $f12, 0x238($sp)
  lwc1  $f12, 0x23c($sp)
  jal   sub_GAME_7F094298
   sw    $v0, 0x140($sp)
  lw    $t4, 0x140($sp)
  lw    $t5, 0x15c($sp)
  lw    $ra, 0x168($sp)
  lui   $t0, 0xb400
  move  $v1, $s0
  sw    $t0, ($v1)
  lw    $t9, 0x164($sp)
  lui   $t1, 0xffff
  and   $t7, $ra, $t1
  and   $t6, $t9, $t1
  srl   $t8, $t6, 0x10
  or    $t9, $t7, $t8
  addiu $s0, $s0, 8
  lui   $t2, 0xb200
  sw    $t9, 4($v1)
  move  $a0, $s0
  sw    $t2, ($a0)
  lw    $t6, 0x160($sp)
  and   $t8, $t5, $t1
  srl   $t9, $t8, 0x10
  and   $t7, $t6, $t1
  or    $t6, $t7, $t9
  addiu $s0, $s0, 8
  sw    $t6, 4($a0)
  move  $a1, $s0
  sw    $t0, ($a1)
  lw    $t9, 0x154($sp)
  lw    $t8, 0x158($sp)
  addiu $s0, $s0, 8
  and   $t6, $t9, $t1
  and   $t7, $t8, $t1
  srl   $t8, $t6, 0x10
  or    $t9, $t7, $t8
  sw    $t9, 4($a1)
  lw    $t3, 0x14c($sp)
  move  $a2, $s0
  sw    $t2, ($a2)
  lw    $t6, 0x150($sp)
  and   $t8, $t3, $t1
  srl   $t9, $t8, 0x10
  and   $t7, $t6, $t1
  or    $t6, $t7, $t9
  addiu $s0, $s0, 8
  sw    $t6, 4($a2)
  move  $v1, $s0
  sw    $t0, ($v1)
  lw    $t9, 0x164($sp)
  sll   $t7, $ra, 0x10
  addiu $s0, $s0, 8
  andi  $t6, $t9, 0xffff
  or    $t8, $t7, $t6
  sw    $t8, 4($v1)
  move  $a0, $s0
  sw    $t2, ($a0)
  lw    $t7, 0x160($sp)
  andi  $t8, $t5, 0xffff
  addiu $s0, $s0, 8
  sll   $t6, $t7, 0x10
  or    $t9, $t6, $t8
  sw    $t9, 4($a0)
  move  $a3, $s0
  sw    $t0, ($a3)
  lw    $t9, 0x154($sp)
  lw    $t6, 0x158($sp)
  lw    $t0, 0x148($sp)
  andi  $t7, $t9, 0xffff
  sll   $t8, $t6, 0x10
  lw    $a2, 0x144($sp)
  or    $t6, $t8, $t7
  addiu $s0, $s0, 8
  sw    $t6, 4($a3)
  move  $v1, $s0
  sw    $t2, ($v1)
  lw    $t8, 0x150($sp)
  andi  $t6, $t3, 0xffff
  addiu $s0, $s0, 8
  sll   $t7, $t8, 0x10
  or    $t9, $t7, $t6
  sw    $t9, 4($v1)
  lui   $t8, 0xb400
  move  $a0, $s0
  and   $t6, $a2, $t1
  srl   $t9, $t6, 0x10
  sw    $t8, ($a0)
  and   $t7, $t0, $t1
  or    $t8, $t7, $t9
  addiu $s0, $s0, 8
  sw    $t8, 4($a0)
  move  $a1, $s0
  and   $t7, $v0, $t1
  srl   $t9, $t7, 0x10
  and   $t6, $t4, $t1
  or    $t8, $t6, $t9
  sw    $t8, 4($a1)
  sw    $t2, ($a1)
  addiu $s0, $s0, 8
  lw    $t5, 0x130($sp)
  lui   $a3, %hi(0xB4000004) # $a3, 0xb400
  move  $v1, $s0
  sw    $a3, ($v1)
  lw    $t9, 0x134($sp)
  lw    $t7, 0x138($sp)
  addiu $s0, $s0, 8
  and   $t8, $t9, $t1
  and   $t6, $t7, $t1
  srl   $t7, $t8, 0x10
  or    $t9, $t6, $t7
  sw    $t9, 4($v1)
  lui   $t8, 0xb200
  move  $a0, $s0
  sw    $t8, ($a0)
  lw    $t7, 0x12c($sp)
  and   $t6, $t5, $t1
  addiu $s0, $s0, 8
  and   $t9, $t7, $t1
  srl   $t8, $t9, 0x10
  or    $t7, $t6, $t8
  sw    $t7, 4($a0)
  move  $a1, $s0
  sll   $t6, $t0, 0x10
  andi  $t8, $a2, 0xffff
  or    $t7, $t6, $t8
  addiu $s0, $s0, 8
  sw    $t7, 4($a1)
  sw    $a3, ($a1)
  move  $t3, $s0
  andi  $t8, $v0, 0xffff
  sll   $t6, $t4, 0x10
  or    $t7, $t6, $t8
  addiu $s0, $s0, 8
  lui   $ra, 0xb200
  sw    $ra, ($t3)
  sw    $t7, 4($t3)
  move  $a3, $s0
  lui   $t9, 0xb400
  sw    $t9, ($a3)
  lw    $t9, 0x134($sp)
  lw    $t8, 0x138($sp)
  addiu $s0, $s0, 8
  andi  $t6, $t9, 0xffff
  sll   $t7, $t8, 0x10
  or    $t8, $t7, $t6
  sw    $t8, %lo(0xB4000004)($a3)
  move  $t0, $s0
  sw    $ra, ($t0)
  lw    $t6, 0x12c($sp)
  sll   $t7, $t5, 0x10
  li    $at, 0x3D000000 # 0.031250
  andi  $t8, $t6, 0xffff
  or    $t9, $t7, $t8
  sw    $t9, 4($t0)
  mtc1  $at, $f14
  lwc1  $f10, 0x330($sp)
  lwc1  $f6, 0x334($sp)
  addiu $s0, $s0, 8
  mul.s $f8, $f10, $f14
  lwc1  $f10, 0x368($sp)
  li    $at, 0x40000000 # 2.000000
  mul.s $f4, $f6, $f14
  addiu $v0, $sp, 0x1d0
  addiu $a1, $sp, 0x1b0
  addiu $a2, $sp, 0x1d0
  swc1  $f8, 0x200($sp)
  mul.s $f8, $f10, $f14
  addiu $a0, $sp, 0x2b0
  swc1  $f4, 0x204($sp)
  addiu $v1, $sp, 0x290
  swc1  $f8, 0x208($sp)
.L7F09861C:
  lwc1  $f0, ($v1)
  c.le.s $f20, $f0
  nop   
  bc1fl .L7F09863C
   neg.s $f12, $f0
  b     .L7F09863C
   mov.s $f12, $f0
  neg.s $f12, $f0
.L7F09863C:
  lwc1  $f2, ($a0)
  mul.s $f6, $f12, $f14
  c.le.s $f20, $f2
  nop   
  bc1f  .L7F09865C
   swc1  $f6, ($a2)
  b     .L7F098660
   mov.s $f12, $f2
.L7F09865C:
  neg.s $f12, $f2
.L7F098660:
  mul.s $f4, $f12, $f14
  addiu $a1, $a1, 4
  addiu $a0, $a0, 4
  addiu $v1, $v1, 4
  addiu $a2, $a2, 4
  bne   $a1, $v0, .L7F09861C
   swc1  $f4, -4($a1)
  mtc1  $at, $f2
  lwc1  $f8, 0x1e0($sp)
  lwc1  $f10, 0x200($sp)
  li    $at, 0x3F800000 # 1.000000
  mul.s $f6, $f2, $f8
  lwc1  $f8, 0x1c0($sp)
  add.s $f4, $f10, $f6
  lwc1  $f6, 0x1e4($sp)
  lwc1  $f10, 0x204($sp)
  add.s $f0, $f8, $f4
  mul.s $f8, $f2, $f6
  lwc1  $f6, 0x1c4($sp)
  add.s $f4, $f10, $f8
  lwc1  $f8, 0x1e8($sp)
  lwc1  $f10, 0x208($sp)
  add.s $f12, $f6, $f4
  mul.s $f6, $f2, $f8
  mtc1  $at, $f2
  lwc1  $f8, 0x1c8($sp)
  c.lt.s $f0, $f12
  li    $at, 0x3A800000 # 0.000977
  swc1  $f12, 0x1a4($sp)
  add.s $f4, $f10, $f6
  mtc1  $at, $f10
  bc1f  .L7F0986EC
   add.s $f14, $f8, $f4
  mov.s $f0, $f12
  swc1  $f12, 0x1a4($sp)
.L7F0986EC:
  c.lt.s $f0, $f14
  swc1  $f14, 0x1a8($sp)
  bc1f  .L7F098704
   nop   
  mov.s $f0, $f14
  swc1  $f14, 0x1a8($sp)
.L7F098704:
  mul.s $f0, $f0, $f10
  c.lt.s $f2, $f0
  nop   
  bc1fl .L7F098728
   swc1  $f0, 0x1a0($sp)
  div.s $f20, $f2, $f0
  b     .L7F09872C
   swc1  $f0, 0x1a0($sp)
  swc1  $f0, 0x1a0($sp)
.L7F098728:
  mov.s $f20, $f2
.L7F09872C:
  lwc1  $f6, 0x220($sp)
  swc1  $f20, 0x190($sp)
  mul.s $f12, $f20, $f6
  jal   sub_GAME_7F094298
   nop   
  lwc1  $f20, 0x190($sp)
  lwc1  $f8, 0x224($sp)
  sw    $v0, 0xe8($sp)
  mul.s $f12, $f20, $f8
  jal   sub_GAME_7F094298
   nop   
  lwc1  $f20, 0x190($sp)
  lwc1  $f4, 0x228($sp)
  sw    $v0, 0xe4($sp)
  mul.s $f12, $f20, $f4
  jal   sub_GAME_7F094298
   nop   
  lwc1  $f20, 0x190($sp)
  lwc1  $f10, 0x2a0($sp)
  sw    $v0, 0xe0($sp)
  mul.s $f12, $f20, $f10
  jal   sub_GAME_7F094298
   nop   
  lwc1  $f20, 0x190($sp)
  lwc1  $f6, 0x2a4($sp)
  sw    $v0, 0xd8($sp)
  mul.s $f12, $f20, $f6
  jal   sub_GAME_7F094298
   nop   
  lwc1  $f20, 0x190($sp)
  lwc1  $f8, 0x2a8($sp)
  sw    $v0, 0xd4($sp)
  mul.s $f12, $f20, $f8
  jal   sub_GAME_7F094298
   nop   
  lwc1  $f20, 0x190($sp)
  lwc1  $f4, 0x2c0($sp)
  sw    $v0, 0xd0($sp)
  mul.s $f12, $f20, $f4
  jal   sub_GAME_7F094298
   nop   
  lwc1  $f20, 0x190($sp)
  lwc1  $f10, 0x2c4($sp)
  sw    $v0, 0xb8($sp)
  mul.s $f12, $f20, $f10
  jal   sub_GAME_7F094298
   nop   
  lwc1  $f20, 0x190($sp)
  lwc1  $f6, 0x2c8($sp)
  sw    $v0, 0xb4($sp)
  mul.s $f12, $f20, $f6
  jal   sub_GAME_7F094298
   nop   
  lwc1  $f20, 0x190($sp)
  lwc1  $f8, 0x240($sp)
  sw    $v0, 0xb0($sp)
  mul.s $f12, $f20, $f8
  jal   sub_GAME_7F094298
   nop   
  lwc1  $f20, 0x190($sp)
  lwc1  $f4, 0x244($sp)
  sw    $v0, 0xc8($sp)
  mul.s $f12, $f20, $f4
  jal   sub_GAME_7F094298
   nop   
  lwc1  $f20, 0x190($sp)
  lwc1  $f10, 0x248($sp)
  sw    $v0, 0xc4($sp)
  mul.s $f12, $f20, $f10
  jal   sub_GAME_7F094298
   nop   
  lw    $t5, 0xe4($sp)
  lw    $t4, 0xe8($sp)
  lui   $t1, 0xffff
  lw    $a2, 0xc4($sp)
  lw    $ra, 0xe0($sp)
  lui   $t6, 0xb400
  and   $t8, $t5, $t1
  srl   $t9, $t8, 0x10
  sw    $t6, ($s0)
  and   $t7, $t4, $t1
  or    $t6, $t7, $t9
  addiu $a0, $s0, 8
  sw    $t6, 4($s0)
  lui   $t8, 0xb200
  and   $t7, $ra, $t1
  sw    $t7, 4($a0)
  sw    $t8, ($a0)
  addiu $a1, $a0, 8
  lui   $t9, 0xb400
  sw    $t9, ($a1)
  lw    $t7, 0xd4($sp)
  lw    $t6, 0xd8($sp)
  addiu $a3, $a1, 8
  and   $t9, $t7, $t1
  and   $t8, $t6, $t1
  srl   $t6, $t9, 0x10
  or    $t7, $t8, $t6
  sw    $t7, 4($a1)
  lw    $t3, 0xd0($sp)
  lui   $t9, 0xb200
  sw    $t9, ($a3)
  and   $t8, $t3, $t1
  sw    $t8, 4($a3)
  addiu $v1, $a3, 8
  lui   $t6, 0xb400
  sw    $t6, ($v1)
  andi  $t8, $t5, 0xffff
  sll   $t9, $t4, 0x10
  or    $t6, $t9, $t8
  sw    $t6, 4($v1)
  addiu $s0, $v1, 8
  lui   $t7, 0xb200
  sll   $t8, $ra, 0x10
  sw    $t8, 4($s0)
  sw    $t7, ($s0)
  addiu $t0, $s0, 8
  lui   $t6, 0xb400
  sw    $t6, ($t0)
  lw    $t6, 0xd4($sp)
  lw    $t9, 0xd8($sp)
  lw    $a3, 0xc8($sp)
  andi  $t7, $t6, 0xffff
  sll   $t8, $t9, 0x10
  or    $t9, $t8, $t7
  sw    $t9, 4($t0)
  addiu $v1, $t0, 8
  lui   $t6, 0xb200
  sll   $t7, $t3, 0x10
  sw    $t7, 4($v1)
  sw    $t6, ($v1)
  addiu $a0, $v1, 8
  lui   $t9, 0xb400
  and   $t8, $a2, $t1
  srl   $t7, $t8, 0x10
  sw    $t9, ($a0)
  and   $t6, $a3, $t1
  or    $t9, $t6, $t7
  sw    $t9, 4($a0)
  addiu $a1, $a0, 8
  and   $t6, $v0, $t1
  lui   $t8, 0xb200
  sw    $t8, ($a1)
  sw    $t6, 4($a1)
  lw    $t0, 0xb4($sp)
  lw    $t4, 0xb8($sp)
  move  $t2, $v0
  addiu $s0, $a1, 8
  lw    $t3, 0xb0($sp)
  move  $v0, $s0
  lui   $t7, 0xb400
  and   $t8, $t0, $t1
  srl   $t6, $t8, 0x10
  sw    $t7, ($v0)
  and   $t9, $t4, $t1
  or    $t7, $t9, $t6
  sw    $t7, 4($v0)
  addiu $v1, $s0, 8
  lui   $t8, 0xb200
  and   $t9, $t3, $t1
  sw    $t9, 4($v1)
  sw    $t8, ($v1)
  addiu $s0, $v1, 8
  lui   $t6, 0xb400
  sw    $t6, ($s0)
  andi  $t9, $a2, 0xffff
  sll   $t8, $a3, 0x10
  or    $t6, $t8, $t9
  sw    $t6, 4($s0)
  addiu $a1, $s0, 8
  sll   $t9, $t2, 0x10
  sw    $t9, 4($a1)
  lui   $t7, 0xb200
  sw    $t7, ($a1)
  addiu $v1, $a1, 8
  lui   $t6, 0xb400
  sw    $t6, ($v1)
  andi  $t9, $t0, 0xffff
  sll   $t8, $t4, 0x10
  or    $t6, $t8, $t9
  addiu $a0, $v1, 8
  sw    $t6, 4($v1)
  lui   $t7, 0xb300
  sll   $t9, $t3, 0x10
  sw    $t9, 4($a0)
  sw    $t7, ($a0)
  addiu $v0, $a0, 8
.L7F098A18:
  lw    $ra, 0x24($sp)
  ldc1  $f20, 0x18($sp)
  lw    $s0, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x488
");

asm(R"
.late_rodata
glabel D_800575F8
.word 0xc4eac000 /*-1878.0*/
glabel D_800575FC
.word 0xc4eac000 /*-1878.0*/
glabel D_80057600
.word 0xc4eac000 /*-1878.0*/
glabel D_80057604
.word 0xc4eac000 /*-1878.0*/
glabel D_80057608
.word 0x44eaa000 /*1877.0*/
glabel D_8005760C
.word 0x46fffe00 /*32767.0*/
.text
glabel sub_GAME_7F098A2C
  addiu $sp, $sp, -0x4d0
  sw    $s0, 0x20($sp)
  move  $s0, $a0
  sw    $ra, 0x24($sp)
  sw    $a1, 0x4d4($sp)
  move  $a0, $a1
  sdc1  $f20, 0x18($sp)
  sw    $a2, 0x4d8($sp)
  sw    $a3, 0x4dc($sp)
  jal   sub_GAME_7F0977B4
   move  $a1, $a2
  bnez  $v0, .L7F098AB0
   lw    $a0, 0x4d8($sp)
  jal   sub_GAME_7F0977B4
   lw    $a1, 0x4dc($sp)
  bnez  $v0, .L7F098AB0
   lw    $a0, 0x4dc($sp)
  jal   sub_GAME_7F0977B4
   lw    $a1, 0x4d4($sp)
  bnez  $v0, .L7F098AB0
   lw    $a0, 0x4e0($sp)
  jal   sub_GAME_7F0977B4
   lw    $a1, 0x4d4($sp)
  bnez  $v0, .L7F098AB0
   lw    $a0, 0x4e0($sp)
  jal   sub_GAME_7F0977B4
   lw    $a1, 0x4d8($sp)
  bnez  $v0, .L7F098AB0
   lw    $a0, 0x4e0($sp)
  jal   sub_GAME_7F0977B4
   lw    $a1, 0x4dc($sp)
  beqz  $v0, .L7F098AB8
   lwc1  $f4, 0x4e4($sp)
.L7F098AB0:
  b     .L7F09A2CC
   move  $v0, $s0
.L7F098AB8:
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f6
  lw    $v1, 0x4d4($sp)
  lw    $a0, 0x4dc($sp)
  div.s $f8, $f4, $f6
  lw    $t1, 0x4d8($sp)
  move  $a3, $v1
  move  $t0, $a0
  move  $a1, $t1
  swc1  $f8, 0x3c0($sp)
  lwc1  $f12, 0x28($v1)
  lwc1  $f4, 0x28($a0)
  lwc1  $f0, 0x2c($v1)
  lwc1  $f14, 0x2c($t1)
  sub.s $f6, $f4, $f12
  lwc1  $f10, 0x28($t1)
  sub.s $f2, $f14, $f0
  swc1  $f6, 0x4b0($sp)
  lwc1  $f20, 0x2c($a0)
  lwc1  $f8, 0x4b0($sp)
  sub.s $f18, $f10, $f12
  mul.s $f10, $f8, $f2
  sub.s $f16, $f20, $f0
  mtc1  $at, $f8
  li    $at, 0x3F800000 # 1.000000
  mul.s $f4, $f18, $f16
  c.lt.s $f14, $f0
  sub.s $f6, $f10, $f4
  mtc1  $at, $f4
  div.s $f10, $f6, $f8
  div.s $f6, $f4, $f10
  swc1  $f10, 0x54($sp)
  swc1  $f10, 0x488($sp)
  swc1  $f6, 0x50($sp)
  bc1f  .L7F098B6C
   swc1  $f6, 0x484($sp)
  li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f2
  move  $a1, $v1
  move  $a3, $t1
  mul.s $f12, $f10, $f2
  nop   
  mul.s $f14, $f6, $f2
  swc1  $f12, 0x488($sp)
  swc1  $f14, 0x484($sp)
.L7F098B6C:
  lwc1  $f0, 0x2c($a1)
  li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f2
  c.lt.s $f20, $f0
  lwc1  $f12, 0x488($sp)
  lwc1  $f14, 0x484($sp)
  li    $at, 0x40800000 # 4.000000
  bc1fl .L7F098BA4
   swc1  $f14, 0x484($sp)
  move  $t0, $a1
  mul.s $f14, $f14, $f2
  move  $a1, $a0
  lwc1  $f0, 0x2c($a0)
  swc1  $f14, 0x484($sp)
.L7F098BA4:
  lwc1  $f8, 0x2c($a3)
  c.lt.s $f0, $f8
  mtc1  $at, $f0
  li    $at, 0x3E800000 # 0.250000
  mtc1  $at, $f10
  bc1fl .L7F098BD8
   lwc1  $f4, 0x28($a1)
  mul.s $f14, $f14, $f2
  move  $v0, $a1
  move  $a1, $a3
  move  $a3, $v0
  swc1  $f14, 0x484($sp)
  lwc1  $f4, 0x28($a1)
.L7F098BD8:
  mtc1  $zero, $f20
  lui   $a2, (0x44EAA000 >> 16) # lui $a2, 0x44ea
  mul.s $f6, $f4, $f10
  swc1  $f20, 0x468($sp)
  mtc1  $at, $f4
  ori   $a2, (0x44EAA000 & 0xFFFF) # ori $a2, $a2, 0xa000
  swc1  $f6, 0x464($sp)
  lwc1  $f8, 0x28($a3)
  swc1  $f20, 0x470($sp)
  mul.s $f10, $f8, $f4
  mtc1  $at, $f8
  swc1  $f10, 0x46c($sp)
  lwc1  $f6, 0x28($a3)
  swc1  $f20, 0x478($sp)
  swc1  $f20, 0x480($sp)
  mul.s $f4, $f6, $f8
  swc1  $f20, 0x47c($sp)
  swc1  $f4, 0x474($sp)
  lwc1  $f10, 0x28($t0)
  swc1  $f10, 0x48c($sp)
  lwc1  $f6, 0x2c($t0)
  swc1  $f6, 0x490($sp)
  lwc1  $f8, 0x28($a1)
  swc1  $f8, 0x494($sp)
  lwc1  $f4, 0x2c($a1)
  lwc1  $f8, 0x494($sp)
  swc1  $f4, 0x498($sp)
  lwc1  $f10, 0x28($a3)
  swc1  $f10, 0x49c($sp)
  lwc1  $f6, 0x2c($a3)
  lwc1  $f10, 0x498($sp)
  lwc1  $f4, 0x49c($sp)
  swc1  $f6, 0x4a0($sp)
  lwc1  $f6, 0x4a0($sp)
  swc1  $f10, 0x2c($sp)
  swc1  $f8, 0x28($sp)
  sub.s $f2, $f10, $f6
  lwc1  $f10, 0x490($sp)
  sw    $t0, 0x4c4($sp)
  sub.s $f18, $f8, $f4
  lwc1  $f8, 0x48c($sp)
  sw    $a3, 0x4cc($sp)
  sub.s $f16, $f10, $f6
  lwc1  $f6, 0x28($sp)
  sw    $a1, 0x4c8($sp)
  sub.s $f4, $f8, $f4
  swc1  $f20, 0x440($sp)
  swc1  $f20, 0x43c($sp)
  sub.s $f12, $f8, $f6
  lwc1  $f8, 0x2c($sp)
  mtc1  $at, $f6
  swc1  $f4, 0x4b0($sp)
  sub.s $f14, $f10, $f8
  mul.s $f10, $f12, $f6
  mtc1  $at, $f8
  swc1  $f12, 0x4a8($sp)
  swc1  $f14, 0x4a4($sp)
  mul.s $f6, $f14, $f8
  swc1  $f20, 0x420($sp)
  swc1  $f20, 0x41c($sp)
  swc1  $f10, 0x424($sp)
  mtc1  $at, $f10
  swc1  $f20, 0x3e4($sp)
  swc1  $f20, 0x3ec($sp)
  mul.s $f8, $f18, $f10
  swc1  $f6, 0x428($sp)
  mtc1  $at, $f6
  swc1  $f20, 0x3f4($sp)
  swc1  $f20, 0x400($sp)
  mul.s $f10, $f2, $f6
  swc1  $f20, 0x3fc($sp)
  swc1  $f8, 0x42c($sp)
  mtc1  $at, $f8
  swc1  $f20, 0x3c4($sp)
  swc1  $f20, 0x3cc($sp)
  mul.s $f6, $f4, $f8
  swc1  $f10, 0x430($sp)
  mtc1  $at, $f10
  lui   $at, %hi(D_800575F8)
  swc1  $f20, 0x3d4($sp)
  mul.s $f8, $f16, $f10
  swc1  $f20, 0x3e0($sp)
  swc1  $f6, 0x434($sp)
  mul.s $f6, $f12, $f0
  swc1  $f20, 0x3dc($sp)
  mul.s $f10, $f14, $f0
  swc1  $f8, 0x438($sp)
  lwc1  $f14, %lo(D_800575F8)($at)
  mul.s $f8, $f18, $f0
  swc1  $f6, 0x404($sp)
  mul.s $f6, $f2, $f0
  swc1  $f10, 0x408($sp)
  mul.s $f10, $f4, $f0
  swc1  $f8, 0x40c($sp)
  mul.s $f8, $f16, $f0
  swc1  $f6, 0x410($sp)
  lwc1  $f6, 0x4a4($sp)
  swc1  $f10, 0x414($sp)
  div.s $f10, $f0, $f6
  swc1  $f8, 0x418($sp)
  div.s $f8, $f0, $f2
  swc1  $f10, 0x3e8($sp)
  div.s $f10, $f0, $f16
  swc1  $f8, 0x3f0($sp)
  lwc1  $f8, 0x4a8($sp)
  div.s $f12, $f8, $f6
  swc1  $f10, 0x3f8($sp)
  div.s $f10, $f18, $f2
  swc1  $f12, 0x3c8($sp)
  div.s $f8, $f4, $f16
  swc1  $f10, 0x3d0($sp)
  jal   sub_GAME_7F093C48
   swc1  $f8, 0x3d8($sp)
  lui   $at, %hi(D_800575FC)
  lui   $a2, (0x44EAA000 >> 16) # lui $a2, 0x44ea
  swc1  $f0, 0x3c8($sp)
  ori   $a2, (0x44EAA000 & 0xFFFF) # ori $a2, $a2, 0xa000
  lwc1  $f14, %lo(D_800575FC)($at)
  jal   sub_GAME_7F093C48
   lwc1  $f12, 0x3d0($sp)
  lui   $at, %hi(D_80057600)
  lui   $a2, (0x44EAA000 >> 16) # lui $a2, 0x44ea
  swc1  $f0, 0x3d0($sp)
  ori   $a2, (0x44EAA000 & 0xFFFF) # ori $a2, $a2, 0xa000
  lwc1  $f14, %lo(D_80057600)($at)
  jal   sub_GAME_7F093C48
   lwc1  $f12, 0x3d8($sp)
  lwc1  $f6, 0x46c($sp)
  lwc1  $f10, 0x474($sp)
  lw    $t6, 0x4d4($sp)
  lw    $t8, 0x4d8($sp)
  swc1  $f0, 0x3d8($sp)
  swc1  $f6, 0x44c($sp)
  swc1  $f10, 0x454($sp)
  lwc1  $f4, 0x28($t6)
  lwc1  $f8, 0x28($t8)
  c.lt.s $f4, $f8
  nop   
  bc1fl .L7F099008
   lw    $t6, 0x4dc($sp)
  lw    $t9, 0x4dc($sp)
  lw    $t7, 0x4e0($sp)
  li    $at, 0x3F800000 # 1.000000
  lwc1  $f6, 0x2c($t9)
  lwc1  $f10, 0x2c($t7)
  mtc1  $at, $f8
  sub.s $f4, $f6, $f10
  c.lt.s $f4, $f8
  nop   
  bc1f  .L7F098E40
   lui    $at, %hi(D_80057604)
  lwc1  $f6, %lo(D_80057604)($at)
  b     .L7F098E7C
   swc1  $f6, 0x1bc($sp)
.L7F098E40:
  jal   getPlayer_c_screenwidth
   nop   
  lw    $t6, 0x4dc($sp)
  lw    $t8, 0x4e0($sp)
  li    $at, 0x3E800000 # 0.250000
  lwc1  $f10, 0x2c($t6)
  lwc1  $f4, 0x2c($t8)
  mtc1  $at, $f6
  sub.s $f8, $f10, $f4
  mtc1  $at, $f4
  mul.s $f10, $f8, $f6
  sub.s $f8, $f0, $f4
  neg.s $f6, $f8
  div.s $f4, $f6, $f10
  swc1  $f4, 0x1bc($sp)
.L7F098E7C:
  lui   $a1, 0xb400
  move  $v0, $s0
  sw    $a1, ($v0)
  lw    $t9, 0x4dc($sp)
  lui   $at, 0xce80
  addiu $s0, $s0, 8
  lwc1  $f8, 0x2c($t9)
  lui   $t9, 0xb200
  move  $v1, $s0
  trunc.w.s $f6, $f8
  addiu $s0, $s0, 8
  move  $a0, $s0
  addiu $s0, $s0, 8
  mfc1  $t6, $f6
  nop   
  or    $t8, $t6, $at
  sw    $t8, 4($v0)
  sw    $t9, ($v1)
  lw    $t7, 0x4e0($sp)
  lwc1  $f10, 0x2c($t7)
  lw    $t7, 0x4d4($sp)
  trunc.w.s $f4, $f10
  lwc1  $f8, 0x2c($t7)
  trunc.w.s $f6, $f8
  mfc1  $t8, $f4
  nop   
  sll   $t9, $t8, 0x10
  mfc1  $t8, $f6
  nop   
  or    $t7, $t9, $t8
  sw    $t7, 4($v1)
  sw    $a1, ($a0)
  jal   getPlayer_c_screenleft
   sw    $a0, 0x1b0($sp)
  jal   getPlayer_c_screenwidth
   swc1  $f0, 0x5c($sp)
  lwc1  $f10, 0x5c($sp)
  li    $at, 0x3E800000 # 0.250000
  mtc1  $at, $f8
  add.s $f4, $f0, $f10
  jal   sub_GAME_7F094298
   sub.s $f12, $f4, $f8
  lw    $t6, 0x1b0($sp)
  move  $v1, $s0
  lui   $t9, 0xb200
  sw    $v0, 4($t6)
  sw    $t9, ($v1)
  sw    $v1, 0x1ac($sp)
  lwc1  $f12, 0x1bc($sp)
  jal   sub_GAME_7F094298
   addiu $s0, $s0, 8
  lw    $v1, 0x1ac($sp)
  move  $a0, $s0
  lui   $t8, 0xb400
  sw    $v0, 4($v1)
  sw    $t8, ($a0)
  sw    $a0, 0x1a8($sp)
  jal   getPlayer_c_screenleft
   addiu $s0, $s0, 8
  jal   sub_GAME_7F094298
   mov.s $f12, $f0
  lw    $t7, 0x1a8($sp)
  move  $v1, $s0
  lui   $t6, 0xb200
  sw    $v0, 4($t7)
  sw    $t6, ($v1)
  sw    $v1, 0x1a4($sp)
  addiu $s0, $s0, 8
  jal   sub_GAME_7F094298
   mov.s $f12, $f20
  lw    $v1, 0x1a4($sp)
  move  $a0, $s0
  lui   $t9, 0xb400
  sw    $v0, 4($v1)
  sw    $t9, ($a0)
  sw    $a0, 0x1a0($sp)
  jal   getPlayer_c_screenleft
   addiu $s0, $s0, 8
  jal   getPlayer_c_screenwidth
   swc1  $f0, 0x5c($sp)
  lwc1  $f6, 0x5c($sp)
  li    $at, 0x3E800000 # 0.250000
  mtc1  $at, $f4
  add.s $f10, $f0, $f6
  jal   sub_GAME_7F094298
   sub.s $f12, $f10, $f4
  lw    $t8, 0x1a0($sp)
  move  $v1, $s0
  lui   $t7, 0xb200
  sw    $v0, 4($t8)
  sw    $t7, ($v1)
  sw    $v1, 0x19c($sp)
  addiu $s0, $s0, 8
  jal   sub_GAME_7F094298
   mov.s $f12, $f20
  lw    $v1, 0x19c($sp)
  b     .L7F0991E0
   sw    $v0, 4($v1)
  lw    $t6, 0x4dc($sp)
.L7F099008:
  lw    $t9, 0x4e0($sp)
  li    $at, 0x3F800000 # 1.000000
  lwc1  $f8, 0x2c($t6)
  lwc1  $f6, 0x2c($t9)
  mtc1  $at, $f4
  sub.s $f10, $f8, $f6
  c.lt.s $f10, $f4
  nop   
  bc1f  .L7F099038
   lui    $at, %hi(D_80057608)
  b     .L7F09906C
   lwc1  $f14, %lo(D_80057608)($at)
.L7F099038:
  jal   getPlayer_c_screenwidth
   nop   
  lw    $t8, 0x4dc($sp)
  lw    $t7, 0x4e0($sp)
  li    $at, 0x3E800000 # 0.250000
  lwc1  $f8, 0x2c($t8)
  lwc1  $f6, 0x2c($t7)
  mtc1  $at, $f4
  sub.s $f10, $f8, $f6
  mtc1  $at, $f6
  mul.s $f8, $f10, $f4
  sub.s $f10, $f0, $f6
  div.s $f14, $f10, $f8
.L7F09906C:
  move  $v0, $s0
  lui   $t6, 0xb400
  sw    $t6, ($v0)
  lw    $t9, 0x4dc($sp)
  lui   $at, 0xce00
  addiu $s0, $s0, 8
  lwc1  $f4, 0x2c($t9)
  lui   $t9, 0xb200
  move  $v1, $s0
  trunc.w.s $f6, $f4
  addiu $s0, $s0, 8
  move  $a0, $s0
  addiu $s0, $s0, 8
  mfc1  $t7, $f6
  nop   
  or    $t6, $t7, $at
  sw    $t6, 4($v0)
  sw    $t9, ($v1)
  lw    $t8, 0x4e0($sp)
  lui   $t7, 0xb400
  lwc1  $f10, 0x2c($t8)
  lw    $t8, 0x4d4($sp)
  trunc.w.s $f8, $f10
  lwc1  $f4, 0x2c($t8)
  trunc.w.s $f6, $f4
  mfc1  $t6, $f8
  nop   
  sll   $t9, $t6, 0x10
  mfc1  $t6, $f6
  nop   
  or    $t8, $t9, $t6
  sw    $t8, 4($v1)
  sw    $t7, ($a0)
  swc1  $f14, 0x198($sp)
  jal   getPlayer_c_screenleft
   sw    $a0, 0x18c($sp)
  jal   sub_GAME_7F094298
   mov.s $f12, $f0
  lw    $t9, 0x18c($sp)
  lwc1  $f12, 0x198($sp)
  move  $v1, $s0
  lui   $t6, 0xb200
  sw    $v0, 4($t9)
  sw    $t6, ($v1)
  sw    $v1, 0x188($sp)
  jal   sub_GAME_7F094298
   addiu $s0, $s0, 8
  lw    $v1, 0x188($sp)
  move  $a0, $s0
  lui   $t8, 0xb400
  sw    $v0, 4($v1)
  sw    $t8, ($a0)
  sw    $a0, 0x184($sp)
  jal   getPlayer_c_screenleft
   addiu $s0, $s0, 8
  jal   getPlayer_c_screenwidth
   swc1  $f0, 0x5c($sp)
  lwc1  $f10, 0x5c($sp)
  li    $at, 0x3E800000 # 0.250000
  mtc1  $at, $f4
  add.s $f8, $f0, $f10
  jal   sub_GAME_7F094298
   sub.s $f12, $f8, $f4
  lw    $t7, 0x184($sp)
  move  $v1, $s0
  lui   $t9, 0xb200
  sw    $v0, 4($t7)
  sw    $t9, ($v1)
  sw    $v1, 0x180($sp)
  addiu $s0, $s0, 8
  jal   sub_GAME_7F094298
   mov.s $f12, $f20
  lw    $v1, 0x180($sp)
  move  $a0, $s0
  lui   $t6, 0xb400
  sw    $v0, 4($v1)
  sw    $t6, ($a0)
  sw    $a0, 0x17c($sp)
  jal   getPlayer_c_screenleft
   addiu $s0, $s0, 8
  jal   sub_GAME_7F094298
   mov.s $f12, $f0
  lw    $t8, 0x17c($sp)
  move  $v1, $s0
  lui   $t7, 0xb200
  sw    $v0, 4($t8)
  sw    $t7, ($v1)
  sw    $v1, 0x178($sp)
  addiu $s0, $s0, 8
  jal   sub_GAME_7F094298
   mov.s $f12, $f20
  lw    $v1, 0x178($sp)
  sw    $v0, 4($v1)
.L7F0991E0:
  lw    $t0, 0x4cc($sp)
  lwc1  $f0, 0x3c0($sp)
  lw    $a3, 0x4c8($sp)
  lwc1  $f6, 0xc($t0)
  lw    $t1, 0x4c4($sp)
  lw    $t3, 0x4e0($sp)
  mul.s $f10, $f6, $f0
  lui    $at, %hi(D_8005760C)
  swc1  $f10, 0x3b0($sp)
  lwc1  $f8, 0xc($a3)
  lwc1  $f16, 0x3b0($sp)
  mul.s $f4, $f8, $f0
  swc1  $f4, 0x3b4($sp)
  lwc1  $f6, 0xc($t1)
  mul.s $f10, $f6, $f0
  lwc1  $f6, 0x3b4($sp)
  c.lt.s $f6, $f16
  swc1  $f10, 0x3b8($sp)
  lwc1  $f8, 0xc($t3)
  mul.s $f4, $f8, $f0
  lwc1  $f0, 0x3b8($sp)
  bc1f  .L7F099240
   swc1  $f4, 0x3bc($sp)
  mov.s $f16, $f6
.L7F099240:
  c.lt.s $f0, $f16
  nop   
  bc1fl .L7F099258
   lwc1  $f0, 0x3bc($sp)
  mov.s $f16, $f0
  lwc1  $f0, 0x3bc($sp)
.L7F099258:
  c.lt.s $f0, $f16
  nop   
  bc1f  .L7F09926C
   nop   
  mov.s $f16, $f0
.L7F09926C:
  lwc1  $f0, %lo(D_8005760C)($at)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f10
  lwc1  $f8, 0x34($t0)
  mul.s $f16, $f16, $f10
  nop   
  mul.s $f4, $f8, $f16
  swc1  $f4, 0x39c($sp)
  lwc1  $f6, 0x34($a3)
  mul.s $f10, $f6, $f16
  swc1  $f10, 0x3a0($sp)
  lwc1  $f8, 0x34($t1)
  mul.s $f4, $f8, $f16
  lwc1  $f8, 0x39c($sp)
  swc1  $f4, 0x3a4($sp)
  lwc1  $f6, 0x34($t3)
  mul.s $f10, $f6, $f16
  swc1  $f10, 0x3a8($sp)
  lwc1  $f4, 0x20($t0)
  mul.s $f6, $f8, $f4
  swc1  $f6, 0x36c($sp)
  lwc1  $f10, 0x24($t0)
  c.le.s $f20, $f6
  mul.s $f4, $f8, $f10
  nop   
  mul.s $f10, $f8, $f0
  swc1  $f4, 0x370($sp)
  lwc1  $f4, 0x3a0($sp)
  swc1  $f10, 0x374($sp)
  lwc1  $f8, 0x20($a3)
  mul.s $f10, $f4, $f8
  swc1  $f10, 0x378($sp)
  lwc1  $f8, 0x24($a3)
  mul.s $f10, $f4, $f8
  nop   
  mul.s $f8, $f4, $f0
  swc1  $f10, 0x37c($sp)
  lwc1  $f10, 0x3a4($sp)
  swc1  $f8, 0x380($sp)
  lwc1  $f4, 0x20($t1)
  mul.s $f8, $f10, $f4
  swc1  $f8, 0x384($sp)
  lwc1  $f4, 0x24($t1)
  mul.s $f8, $f10, $f4
  nop   
  mul.s $f4, $f10, $f0
  swc1  $f8, 0x388($sp)
  lwc1  $f8, 0x3a8($sp)
  swc1  $f4, 0x38c($sp)
  lwc1  $f10, 0x20($t3)
  mul.s $f4, $f8, $f10
  lwc1  $f8, 0x3a8($sp)
  swc1  $f4, 0x390($sp)
  lwc1  $f10, 0x24($t3)
  mul.s $f4, $f8, $f10
  lwc1  $f8, 0x3a8($sp)
  mul.s $f10, $f8, $f0
  lwc1  $f0, 0x370($sp)
  swc1  $f4, 0x394($sp)
  bc1f  .L7F099368
   swc1  $f10, 0x398($sp)
  b     .L7F099370
   mov.s $f2, $f6
.L7F099368:
  lwc1  $f2, 0x36c($sp)
  neg.s $f2, $f2
.L7F099370:
  c.le.s $f20, $f0
  nop   
  bc1fl .L7F09938C
   neg.s $f14, $f0
  b     .L7F09938C
   mov.s $f14, $f0
  neg.s $f14, $f0
.L7F09938C:
  lwc1  $f0, 0x378($sp)
  c.le.s $f20, $f0
  nop   
  bc1fl .L7F0993AC
   neg.s $f12, $f0
  b     .L7F0993AC
   mov.s $f12, $f0
  neg.s $f12, $f0
.L7F0993AC:
  c.lt.s $f2, $f12
  nop   
  bc1fl .L7F0993DC
   lwc1  $f0, 0x37c($sp)
  c.le.s $f20, $f0
  nop   
  bc1fl .L7F0993D8
   neg.s $f2, $f0
  b     .L7F0993D8
   mov.s $f2, $f0
  neg.s $f2, $f0
.L7F0993D8:
  lwc1  $f0, 0x37c($sp)
.L7F0993DC:
  c.le.s $f20, $f0
  nop   
  bc1fl .L7F0993F8
   neg.s $f12, $f0
  b     .L7F0993F8
   mov.s $f12, $f0
  neg.s $f12, $f0
.L7F0993F8:
  c.lt.s $f14, $f12
  swc1  $f16, 0x3ac($sp)
  bc1fl .L7F099430
   lwc1  $f0, 0x384($sp)
  c.le.s $f20, $f0
  nop   
  bc1fl .L7F099428
   neg.s $f14, $f0
  mov.s $f14, $f0
  b     .L7F09942C
   swc1  $f16, 0x3ac($sp)
  neg.s $f14, $f0
.L7F099428:
  swc1  $f16, 0x3ac($sp)
.L7F09942C:
  lwc1  $f0, 0x384($sp)
.L7F099430:
  c.le.s $f20, $f0
  nop   
  bc1fl .L7F09944C
   neg.s $f12, $f0
  b     .L7F09944C
   mov.s $f12, $f0
  neg.s $f12, $f0
.L7F09944C:
  c.lt.s $f2, $f12
  nop   
  bc1fl .L7F09947C
   lwc1  $f0, 0x388($sp)
  c.le.s $f20, $f0
  nop   
  bc1fl .L7F099478
   neg.s $f2, $f0
  b     .L7F099478
   mov.s $f2, $f0
  neg.s $f2, $f0
.L7F099478:
  lwc1  $f0, 0x388($sp)
.L7F09947C:
  c.le.s $f20, $f0
  nop   
  bc1fl .L7F099498
   neg.s $f12, $f0
  b     .L7F099498
   mov.s $f12, $f0
  neg.s $f12, $f0
.L7F099498:
  c.lt.s $f14, $f12
  nop   
  bc1fl .L7F0994C8
   lwc1  $f0, 0x390($sp)
  c.le.s $f20, $f0
  nop   
  bc1fl .L7F0994C4
   neg.s $f14, $f0
  b     .L7F0994C4
   mov.s $f14, $f0
  neg.s $f14, $f0
.L7F0994C4:
  lwc1  $f0, 0x390($sp)
.L7F0994C8:
  c.le.s $f20, $f0
  nop   
  bc1fl .L7F0994E4
   neg.s $f12, $f0
  b     .L7F0994E4
   mov.s $f12, $f0
  neg.s $f12, $f0
.L7F0994E4:
  c.lt.s $f2, $f12
  swc1  $f2, 0x364($sp)
  bc1fl .L7F099518
   lwc1  $f0, 0x394($sp)
  c.le.s $f20, $f0
  nop   
  bc1fl .L7F099510
   neg.s $f2, $f0
  b     .L7F099514
   swc1  $f0, 0x364($sp)
  neg.s $f2, $f0
.L7F099510:
  swc1  $f2, 0x364($sp)
.L7F099514:
  lwc1  $f0, 0x394($sp)
.L7F099518:
  c.le.s $f20, $f0
  nop   
  bc1fl .L7F099534
   neg.s $f12, $f0
  b     .L7F099534
   mov.s $f12, $f0
  neg.s $f12, $f0
.L7F099534:
  c.lt.s $f14, $f12
  swc1  $f14, 0x368($sp)
  bc1fl .L7F099568
   lwc1  $f4, 0x36c($sp)
  c.le.s $f20, $f0
  nop   
  bc1fl .L7F099560
   neg.s $f14, $f0
  b     .L7F099564
   swc1  $f0, 0x368($sp)
  neg.s $f14, $f0
.L7F099560:
  swc1  $f14, 0x368($sp)
.L7F099564:
  lwc1  $f4, 0x36c($sp)
.L7F099568:
  lwc1  $f8, 0x370($sp)
  lwc1  $f10, 0x374($sp)
  swc1  $f4, 0x354($sp)
  lwc1  $f4, 0x37c($sp)
  lwc1  $f6, 0x378($sp)
  swc1  $f8, 0x358($sp)
  swc1  $f10, 0x35c($sp)
  swc1  $f4, 0x338($sp)
  swc1  $f6, 0x334($sp)
  lwc1  $f8, 0x380($sp)
  lwc1  $f6, 0x388($sp)
  lwc1  $f4, 0x38c($sp)
  lwc1  $f10, 0x384($sp)
  swc1  $f8, 0x33c($sp)
  swc1  $f6, 0x318($sp)
  swc1  $f4, 0x31c($sp)
  swc1  $f10, 0x314($sp)
  lwc1  $f8, 0x30($t0)
  addiu $v1, $sp, 0x2f4
  addiu $a2, $sp, 0x334
  swc1  $f8, 0x360($sp)
  lwc1  $f10, 0x30($a3)
  addiu $a3, $sp, 0x324
  addiu $v0, $sp, 0x354
  swc1  $f10, 0x340($sp)
  lwc1  $f6, 0x30($t1)
  addiu $a0, $sp, 0x2d4
  addiu $a1, $sp, 0x314
  swc1  $f6, 0x320($sp)
.L7F0995DC:
  lwc1  $f0, ($v0)
  lwc1  $f4, ($a2)
  lwc1  $f10, ($a1)
  addiu $a1, $a1, 4
  sub.s $f8, $f4, $f0
  sltu  $at, $a1, $a3
  addiu $v1, $v1, 4
  sub.s $f6, $f10, $f0
  addiu $a2, $a2, 4
  addiu $v0, $v0, 4
  addiu $a0, $a0, 4
  swc1  $f8, -4($v1)
  bnez  $at, .L7F0995DC
   swc1  $f6, -4($a0)
  addiu $v1, $sp, 0x2f4
  addiu $v0, $sp, 0x354
  addiu $a0, $sp, 0x2d4
  addiu $a3, $sp, 0x294
  addiu $a1, $sp, 0x2b4
  addiu $t0, $sp, 0x274
  addiu $a2, $sp, 0x254
  lwc1  $f18, 0x410($sp)
  lwc1  $f16, 0x40c($sp)
  addiu $t1, $sp, 0x264
.L7F09963C:
  lwc1  $f0, ($a0)
  lwc1  $f2, ($v1)
  lwc1  $f8, 0x418($sp)
  mul.s $f4, $f0, $f18
  li    $at, 0x47800000 # 65536.000000
  addiu $a2, $a2, 4
  mul.s $f10, $f8, $f2
  mtc1  $at, $f8
  addiu $v1, $v1, 4
  addiu $v0, $v0, 4
  addiu $a0, $a0, 4
  addiu $a3, $a3, 4
  addiu $a1, $a1, 4
  sub.s $f6, $f4, $f10
  addiu $t0, $t0, 4
  div.s $f12, $f6, $f8
  swc1  $f12, -4($a3)
  lwc1  $f4, 0x414($sp)
  mul.s $f10, $f2, $f4
  mtc1  $at, $f4
  sltu  $at, $a2, $t1
  mul.s $f6, $f16, $f0
  sub.s $f8, $f10, $f6
  div.s $f10, $f8, $f4
  swc1  $f10, -4($a1)
  lwc1  $f6, 0x484($sp)
  lwc1  $f4, -4($a1)
  mul.s $f8, $f12, $f6
  lwc1  $f6, -4($v0)
  swc1  $f8, -4($a0)
  lwc1  $f10, 0x484($sp)
  swc1  $f6, -4($a2)
  mul.s $f14, $f4, $f10
  swc1  $f14, -4($v1)
  bnez  $at, .L7F09963C
   swc1  $f14, -4($t0)
  lw    $v1, 0x4dc($sp)
  lwc1  $f8, 0x2c($t3)
  lw    $v0, 0x4d4($sp)
  lwc1  $f4, 0x2c($v1)
  lwc1  $f6, 0x10($v1)
  lwc1  $f14, 0x10($v0)
  div.s $f0, $f8, $f4
  lwc1  $f10, 0x10($t3)
  li    $at, 0x47800000 # 65536.000000
  li    $t6, 1
  sub.s $f8, $f14, $f6
  mul.s $f4, $f8, $f0
  add.s $f6, $f10, $f4
  swc1  $f6, 0x170($sp)
  lwc1  $f10, 0x14($v1)
  lwc1  $f2, 0x14($v0)
  lwc1  $f8, 0x14($t3)
  sub.s $f4, $f2, $f10
  mul.s $f6, $f4, $f0
  add.s $f10, $f8, $f6
  swc1  $f10, 0x16c($sp)
  lwc1  $f8, 0x18($v1)
  lwc1  $f16, 0x18($v0)
  lwc1  $f4, 0x18($t3)
  sub.s $f6, $f16, $f8
  mul.s $f10, $f6, $f0
  add.s $f8, $f4, $f10
  swc1  $f8, 0x168($sp)
  lwc1  $f4, 0x1c($v1)
  lwc1  $f18, 0x1c($v0)
  lwc1  $f6, 0x1c($t3)
  sub.s $f10, $f18, $f4
  mul.s $f8, $f10, $f0
  mtc1  $at, $f10
  add.s $f4, $f6, $f8
  mul.s $f6, $f14, $f10
  swc1  $f4, 0x164($sp)
  cfc1  $t9, $31
  ctc1  $t6, $31
  nop   
  cvt.w.s $f8, $f6
  cfc1  $t6, $31
  nop   
  andi  $t6, $t6, 0x78
  beqz  $t6, .L7F0997C8
   li    $at, 0x4F000000 # 2147483648.000000
  mtc1  $at, $f8
  li    $t6, 1
  sub.s $f8, $f6, $f8
  ctc1  $t6, $31
  nop   
  cvt.w.s $f8, $f8
  cfc1  $t6, $31
  nop   
  andi  $t6, $t6, 0x78
  bnez  $t6, .L7F0997C0
   nop   
  mfc1  $t6, $f8
  lui   $at, 0x8000
  b     .L7F0997D8
   or    $t6, $t6, $at
.L7F0997C0:
  b     .L7F0997D8
   li    $t6, -1
.L7F0997C8:
  mfc1  $t6, $f8
  nop   
  bltz  $t6, .L7F0997C0
   nop   
.L7F0997D8:
  li    $at, 0x47800000 # 65536.000000
  ctc1  $t9, $31
  mtc1  $at, $f4
  li    $t7, 1
  sw    $t6, 0x160($sp)
  mul.s $f10, $f2, $f4
  cfc1  $t8, $31
  ctc1  $t7, $31
  nop   
  cvt.w.s $f6, $f10
  cfc1  $t7, $31
  nop   
  andi  $t7, $t7, 0x78
  beqz  $t7, .L7F099858
   li    $at, 0x4F000000 # 2147483648.000000
  mtc1  $at, $f6
  li    $t7, 1
  sub.s $f6, $f10, $f6
  ctc1  $t7, $31
  nop   
  cvt.w.s $f6, $f6
  cfc1  $t7, $31
  nop   
  andi  $t7, $t7, 0x78
  bnez  $t7, .L7F099850
   nop   
  mfc1  $t7, $f6
  lui   $at, 0x8000
  b     .L7F099868
   or    $t7, $t7, $at
.L7F099850:
  b     .L7F099868
   li    $t7, -1
.L7F099858:
  mfc1  $t7, $f6
  nop   
  bltz  $t7, .L7F099850
   nop   
.L7F099868:
  li    $at, 0x47800000 # 65536.000000
  ctc1  $t8, $31
  mtc1  $at, $f8
  li    $t6, 1
  sw    $t7, 0x15c($sp)
  mul.s $f4, $f16, $f8
  cfc1  $t9, $31
  ctc1  $t6, $31
  nop   
  cvt.w.s $f10, $f4
  cfc1  $t6, $31
  nop   
  andi  $t6, $t6, 0x78
  beqz  $t6, .L7F0998E8
   li    $at, 0x4F000000 # 2147483648.000000
  mtc1  $at, $f10
  li    $t6, 1
  sub.s $f10, $f4, $f10
  ctc1  $t6, $31
  nop   
  cvt.w.s $f10, $f10
  cfc1  $t6, $31
  nop   
  andi  $t6, $t6, 0x78
  bnez  $t6, .L7F0998E0
   nop   
  mfc1  $t6, $f10
  lui   $at, 0x8000
  b     .L7F0998F8
   or    $t6, $t6, $at
.L7F0998E0:
  b     .L7F0998F8
   li    $t6, -1
.L7F0998E8:
  mfc1  $t6, $f10
  nop   
  bltz  $t6, .L7F0998E0
   nop   
.L7F0998F8:
  li    $at, 0x47800000 # 65536.000000
  ctc1  $t9, $31
  mtc1  $at, $f6
  li    $t7, 1
  sw    $t6, 0x158($sp)
  mul.s $f8, $f18, $f6
  cfc1  $t8, $31
  ctc1  $t7, $31
  nop   
  cvt.w.s $f4, $f8
  cfc1  $t7, $31
  nop   
  andi  $t7, $t7, 0x78
  beqz  $t7, .L7F099978
   li    $at, 0x4F000000 # 2147483648.000000
  mtc1  $at, $f4
  li    $t7, 1
  sub.s $f4, $f8, $f4
  ctc1  $t7, $31
  nop   
  cvt.w.s $f4, $f4
  cfc1  $t7, $31
  nop   
  andi  $t7, $t7, 0x78
  bnez  $t7, .L7F099970
   nop   
  mfc1  $t7, $f4
  lui   $at, 0x8000
  b     .L7F099988
   or    $t7, $t7, $at
.L7F099970:
  b     .L7F099988
   li    $t7, -1
.L7F099978:
  mfc1  $t7, $f4
  nop   
  bltz  $t7, .L7F099970
   nop   
.L7F099988:
  lw    $t9, 0x4d8($sp)
  sw    $t7, 0x154($sp)
  ctc1  $t8, $31
  lwc1  $f6, 0x28($v0)
  lwc1  $f10, 0x28($t9)
  li    $at, 0x3E800000 # 0.250000
  mtc1  $at, $f4
  sub.s $f8, $f10, $f6
  lwc1  $f6, 0x170($sp)
  mul.s $f10, $f8, $f4
  sub.s $f8, $f6, $f14
  jal   sub_GAME_7F094298
   div.s $f12, $f8, $f10
  lw    $v1, 0x4d4($sp)
  sw    $v0, 0x150($sp)
  lwc1  $f4, 0x16c($sp)
  lwc1  $f6, 0x14($v1)
  lw    $t6, 0x4d8($sp)
  li    $at, 0x3E800000 # 0.250000
  sub.s $f8, $f4, $f6
  lwc1  $f4, 0x28($v1)
  lwc1  $f10, 0x28($t6)
  sub.s $f6, $f10, $f4
  mtc1  $at, $f10
  nop   
  mul.s $f4, $f6, $f10
  jal   sub_GAME_7F094298
   div.s $f12, $f8, $f4
  lw    $v1, 0x4d4($sp)
  sw    $v0, 0x14c($sp)
  lwc1  $f6, 0x168($sp)
  lwc1  $f10, 0x18($v1)
  lw    $t8, 0x4d8($sp)
  li    $at, 0x3E800000 # 0.250000
  sub.s $f8, $f6, $f10
  lwc1  $f6, 0x28($v1)
  lwc1  $f4, 0x28($t8)
  sub.s $f10, $f4, $f6
  mtc1  $at, $f4
  nop   
  mul.s $f6, $f10, $f4
  jal   sub_GAME_7F094298
   div.s $f12, $f8, $f6
  lw    $v1, 0x4d4($sp)
  sw    $v0, 0x148($sp)
  lwc1  $f10, 0x164($sp)
  lwc1  $f4, 0x1c($v1)
  lw    $t7, 0x4d8($sp)
  li    $at, 0x3E800000 # 0.250000
  sub.s $f8, $f10, $f4
  lwc1  $f10, 0x28($v1)
  lwc1  $f6, 0x28($t7)
  sub.s $f4, $f6, $f10
  mtc1  $at, $f6
  nop   
  mul.s $f10, $f4, $f6
  jal   sub_GAME_7F094298
   div.s $f12, $f8, $f10
  lw    $v1, 0x4dc($sp)
  lw    $t9, 0x4d4($sp)
  sw    $v0, 0x144($sp)
  lwc1  $f4, 0x10($v1)
  lwc1  $f6, 0x10($t9)
  lwc1  $f10, 0x2c($v1)
  li    $at, 0x3E800000 # 0.250000
  sub.s $f8, $f4, $f6
  lwc1  $f4, 0x2c($t9)
  sub.s $f6, $f10, $f4
  mtc1  $at, $f10
  nop   
  mul.s $f4, $f6, $f10
  jal   sub_GAME_7F094298
   div.s $f12, $f8, $f4
  lw    $v1, 0x4dc($sp)
  lw    $t6, 0x4d4($sp)
  sw    $v0, 0x130($sp)
  sw    $v0, 0x140($sp)
  lwc1  $f6, 0x14($v1)
  lwc1  $f10, 0x14($t6)
  lwc1  $f4, 0x2c($v1)
  li    $at, 0x3E800000 # 0.250000
  sub.s $f8, $f6, $f10
  lwc1  $f6, 0x2c($t6)
  sub.s $f10, $f4, $f6
  mtc1  $at, $f4
  nop   
  mul.s $f6, $f10, $f4
  jal   sub_GAME_7F094298
   div.s $f12, $f8, $f6
  lw    $t8, 0x4dc($sp)
  lw    $t7, 0x4d4($sp)
  sw    $v0, 0x12c($sp)
  sw    $v0, 0x13c($sp)
  lwc1  $f10, 0x18($t8)
  lwc1  $f4, 0x18($t7)
  lwc1  $f6, 0x2c($t8)
  li    $at, 0x3E800000 # 0.250000
  sub.s $f8, $f10, $f4
  lwc1  $f10, 0x2c($t7)
  sub.s $f4, $f6, $f10
  mtc1  $at, $f6
  nop   
  mul.s $f10, $f4, $f6
  jal   sub_GAME_7F094298
   div.s $f12, $f8, $f10
  lw    $t9, 0x4dc($sp)
  lw    $t6, 0x4d4($sp)
  li    $at, 0x3E800000 # 0.250000
  lwc1  $f4, 0x1c($t9)
  lwc1  $f6, 0x1c($t6)
  lwc1  $f10, 0x2c($t9)
  sub.s $f8, $f4, $f6
  lwc1  $f4, 0x2c($t6)
  sw    $v0, 0x138($sp)
  sw    $v0, 0x128($sp)
  sub.s $f6, $f10, $f4
  mtc1  $at, $f10
  nop   
  mul.s $f4, $f6, $f10
  jal   sub_GAME_7F094298
   div.s $f12, $f8, $f4
  lw    $t3, 0x15c($sp)
  lw    $t2, 0x160($sp)
  lui   $t1, 0xffff
  move  $v1, $s0
  and   $t7, $t3, $t1
  lw    $t4, 0x128($sp)
  lw    $t5, 0x138($sp)
  lw    $ra, 0x158($sp)
  srl   $t9, $t7, 0x10
  and   $t8, $t2, $t1
  lui   $t0, 0xb400
  or    $t6, $t8, $t9
  addiu $s0, $s0, 8
  sw    $t6, 4($v1)
  sw    $t0, ($v1)
  move  $a0, $s0
  lui   $t7, 0xb200
  sw    $t7, ($a0)
  lw    $t9, 0x154($sp)
  and   $t8, $ra, $t1
  addiu $s0, $s0, 8
  and   $t6, $t9, $t1
  srl   $t7, $t6, 0x10
  or    $t9, $t8, $t7
  sw    $t9, 4($a0)
  move  $a1, $s0
  sw    $t0, ($a1)
  lw    $t7, 0x14c($sp)
  lw    $t6, 0x150($sp)
  addiu $s0, $s0, 8
  and   $t9, $t7, $t1
  and   $t8, $t6, $t1
  srl   $t6, $t9, 0x10
  or    $t7, $t8, $t6
  sw    $t7, 4($a1)
  lui   $a1, %hi(0xB2000004) # $a1, 0xb200
  move  $a2, $s0
  sw    $a1, ($a2)
  lw    $t6, 0x144($sp)
  lw    $t9, 0x148($sp)
  addiu $s0, $s0, 8
  and   $t7, $t6, $t1
  and   $t8, $t9, $t1
  srl   $t9, $t7, 0x10
  or    $t6, $t8, $t9
  sw    $t6, 4($a2)
  move  $v1, $s0
  andi  $t9, $t3, 0xffff
  sll   $t8, $t2, 0x10
  or    $t6, $t8, $t9
  addiu $s0, $s0, 8
  sw    $t6, 4($v1)
  sw    $t0, ($v1)
  move  $a0, $s0
  sw    $a1, ($a0)
  lw    $t9, 0x154($sp)
  sll   $t8, $ra, 0x10
  addiu $s0, $s0, 8
  andi  $t6, $t9, 0xffff
  or    $t7, $t8, $t6
  sw    $t7, 4($a0)
  move  $a3, $s0
  sw    $t0, ($a3)
  lw    $t7, 0x14c($sp)
  lw    $t8, 0x150($sp)
  lw    $t2, 0x140($sp)
  andi  $t9, $t7, 0xffff
  sll   $t6, $t8, 0x10
  lw    $t0, 0x13c($sp)
  or    $t8, $t6, $t9
  addiu $s0, $s0, 8
  sw    $t8, 4($a3)
  move  $v1, $s0
  lui   $t7, 0xb200
  sw    $t7, ($v1)
  lw    $t7, 0x144($sp)
  lw    $t9, 0x148($sp)
  addiu $s0, $s0, 8
  andi  $t6, $t7, 0xffff
  sll   $t8, $t9, 0x10
  or    $t9, $t8, $t6
  and   $t8, $t0, $t1
  sw    $t9, 4($v1)
  srl   $t6, $t8, 0x10
  and   $t7, $t2, $t1
  or    $t9, $t7, $t6
  move  $a0, $s0
  addiu $s0, $s0, 8
  lui   $ra, 0xb400
  sw    $t9, 4($a0)
  move  $a1, $s0
  and   $a2, $v0, $t1
  sw    $ra, ($a0)
  srl   $t7, $a2, 0x10
  and   $t6, $t5, $t1
  or    $t9, $t6, $t7
  addiu $s0, $s0, 8
  lui   $t8, 0xb200
  sw    $t8, ($a1)
  sw    $t9, %lo(0xB2000004)($a1)
  move  $v1, $s0
  sw    $ra, ($v1)
  lw    $t6, 0x12c($sp)
  lw    $t8, 0x130($sp)
  move  $a2, $t7
  and   $t9, $t6, $t1
  and   $t7, $t8, $t1
  srl   $t8, $t9, 0x10
  or    $t6, $t7, $t8
  addiu $s0, $s0, 8
  move  $a0, $s0
  and   $t7, $t4, $t1
  sw    $t6, 4($v1)
  or    $t8, $t7, $a2
  lui   $t9, 0xb200
  sw    $t9, ($a0)
  addiu $s0, $s0, 8
  sw    $t8, 4($a0)
  move  $a1, $s0
  sll   $t9, $t2, 0x10
  andi  $t7, $t0, 0xffff
  or    $t8, $t9, $t7
  addiu $s0, $s0, 8
  sw    $t8, %lo(0xB2000004)($a1)
  sw    $ra, ($a1)
  move  $t3, $s0
  andi  $t7, $v0, 0xffff
  sll   $t9, $t5, 0x10
  or    $t8, $t9, $t7
  addiu $s0, $s0, 8
  lui   $ra, 0xb200
  sw    $ra, ($t3)
  sw    $t8, 4($t3)
  move  $a3, $s0
  lui   $t6, 0xb400
  sw    $t6, ($a3)
  lw    $t6, 0x12c($sp)
  lw    $t7, 0x130($sp)
  addiu $s0, $s0, 8
  andi  $t9, $t6, 0xffff
  sll   $t8, $t7, 0x10
  or    $t7, $t8, $t9
  sw    $t7, 4($a3)
  andi  $t9, $v0, 0xffff
  move  $t0, $s0
  sll   $t8, $t4, 0x10
  or    $t7, $t8, $t9
  li    $at, 0x3D000000 # 0.031250
  sw    $t7, 4($t0)
  sw    $ra, ($t0)
  mtc1  $at, $f14
  lwc1  $f6, 0x364($sp)
  lwc1  $f8, 0x368($sp)
  addiu $s0, $s0, 8
  mul.s $f10, $f6, $f14
  lwc1  $f6, 0x3ac($sp)
  li    $at, 0x40000000 # 2.000000
  mul.s $f4, $f8, $f14
  addiu $v0, $sp, 0x204
  addiu $a1, $sp, 0x1f4
  addiu $a0, $sp, 0x2d4
  swc1  $f10, 0x234($sp)
  mul.s $f10, $f6, $f14
  addiu $a2, $sp, 0x214
  swc1  $f4, 0x238($sp)
  addiu $v1, $sp, 0x2f4
  swc1  $f10, 0x23c($sp)
.L7F099E08:
  lwc1  $f0, ($a0)
  c.le.s $f20, $f0
  nop   
  bc1fl .L7F099E28
   neg.s $f12, $f0
  b     .L7F099E28
   mov.s $f12, $f0
  neg.s $f12, $f0
.L7F099E28:
  lwc1  $f2, ($v1)
  mul.s $f8, $f12, $f14
  c.le.s $f20, $f2
  nop   
  bc1f  .L7F099E48
   swc1  $f8, ($a2)
  b     .L7F099E4C
   mov.s $f12, $f2
.L7F099E48:
  neg.s $f12, $f2
.L7F099E4C:
  mul.s $f4, $f12, $f14
  addiu $a1, $a1, 4
  addiu $v1, $v1, 4
  addiu $a0, $a0, 4
  addiu $a2, $a2, 4
  bne   $a1, $v0, .L7F099E08
   swc1  $f4, -4($a1)
  mtc1  $at, $f2
  lwc1  $f10, 0x214($sp)
  lwc1  $f6, 0x234($sp)
  li    $at, 0x3A800000 # 0.000977
  mul.s $f8, $f2, $f10
  lwc1  $f10, 0x1f4($sp)
  add.s $f4, $f6, $f8
  lwc1  $f8, 0x218($sp)
  lwc1  $f6, 0x238($sp)
  add.s $f0, $f10, $f4
  mul.s $f10, $f2, $f8
  lwc1  $f8, 0x1f8($sp)
  add.s $f4, $f6, $f10
  lwc1  $f10, 0x21c($sp)
  lwc1  $f6, 0x23c($sp)
  add.s $f12, $f8, $f4
  mul.s $f8, $f2, $f10
  lwc1  $f10, 0x1fc($sp)
  c.lt.s $f0, $f12
  swc1  $f12, 0x1d8($sp)
  add.s $f4, $f6, $f8
  mtc1  $at, $f6
  bc1f  .L7F099ED0
   add.s $f14, $f10, $f4
  mov.s $f0, $f12
  swc1  $f12, 0x1d8($sp)
.L7F099ED0:
  c.lt.s $f0, $f14
  swc1  $f14, 0x1dc($sp)
  bc1f  .L7F099EE8
   nop   
  mov.s $f0, $f14
  swc1  $f14, 0x1dc($sp)
.L7F099EE8:
  mul.s $f0, $f0, $f6
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  nop   
  c.lt.s $f8, $f0
  nop   
  bc1f  .L7F099F18
   li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  swc1  $f0, 0x1d4($sp)
  b     .L7F099F24
   div.s $f20, $f10, $f0
.L7F099F18:
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f20
  swc1  $f0, 0x1d4($sp)
.L7F099F24:
  lwc1  $f4, 0x254($sp)
  swc1  $f20, 0x1c4($sp)
  mul.s $f12, $f20, $f4
  jal   sub_GAME_7F094298
   nop   
  lwc1  $f20, 0x1c4($sp)
  lwc1  $f6, 0x258($sp)
  sw    $v0, 0xe0($sp)
  mul.s $f12, $f20, $f6
  jal   sub_GAME_7F094298
   nop   
  lwc1  $f20, 0x1c4($sp)
  lwc1  $f8, 0x25c($sp)
  sw    $v0, 0xdc($sp)
  mul.s $f12, $f20, $f8
  jal   sub_GAME_7F094298
   nop   
  lwc1  $f20, 0x1c4($sp)
  lwc1  $f10, 0x260($sp)
  sw    $v0, 0xd8($sp)
  mul.s $f12, $f20, $f10
  jal   sub_GAME_7F094298
   nop   
  lwc1  $f20, 0x1c4($sp)
  lwc1  $f4, 0x2d4($sp)
  sw    $v0, 0xd4($sp)
  mul.s $f12, $f20, $f4
  jal   sub_GAME_7F094298
   nop   
  lwc1  $f20, 0x1c4($sp)
  lwc1  $f6, 0x2d8($sp)
  sw    $v0, 0xd0($sp)
  mul.s $f12, $f20, $f6
  jal   sub_GAME_7F094298
   nop   
  lwc1  $f20, 0x1c4($sp)
  lwc1  $f8, 0x2dc($sp)
  sw    $v0, 0xcc($sp)
  mul.s $f12, $f20, $f8
  jal   sub_GAME_7F094298
   nop   
  lwc1  $f20, 0x1c4($sp)
  lwc1  $f10, 0x2e0($sp)
  sw    $v0, 0xc8($sp)
  mul.s $f12, $f20, $f10
  jal   sub_GAME_7F094298
   nop   
  lwc1  $f20, 0x1c4($sp)
  lwc1  $f4, 0x2f4($sp)
  sw    $v0, 0xc4($sp)
  mul.s $f12, $f20, $f4
  jal   sub_GAME_7F094298
   nop   
  lwc1  $f20, 0x1c4($sp)
  lwc1  $f6, 0x2f8($sp)
  sw    $v0, 0xb0($sp)
  mul.s $f12, $f20, $f6
  jal   sub_GAME_7F094298
   nop   
  lwc1  $f20, 0x1c4($sp)
  lwc1  $f8, 0x2fc($sp)
  sw    $v0, 0xac($sp)
  mul.s $f12, $f20, $f8
  jal   sub_GAME_7F094298
   nop   
  lwc1  $f20, 0x1c4($sp)
  lwc1  $f10, 0x300($sp)
  sw    $v0, 0xa8($sp)
  mul.s $f12, $f20, $f10
  jal   sub_GAME_7F094298
   nop   
  lwc1  $f20, 0x1c4($sp)
  lwc1  $f4, 0x274($sp)
  sw    $v0, 0xa4($sp)
  mul.s $f12, $f20, $f4
  jal   sub_GAME_7F094298
   nop   
  lwc1  $f20, 0x1c4($sp)
  lwc1  $f6, 0x278($sp)
  sw    $v0, 0xc0($sp)
  mul.s $f12, $f20, $f6
  jal   sub_GAME_7F094298
   nop   
  lwc1  $f20, 0x1c4($sp)
  lwc1  $f8, 0x27c($sp)
  sw    $v0, 0xbc($sp)
  mul.s $f12, $f20, $f8
  jal   sub_GAME_7F094298
   nop   
  lwc1  $f20, 0x1c4($sp)
  lwc1  $f10, 0x280($sp)
  sw    $v0, 0xb8($sp)
  mul.s $f12, $f20, $f10
  jal   sub_GAME_7F094298
   nop   
  lw    $t0, 0xb8($sp)
  lw    $t3, 0xd4($sp)
  lw    $ra, 0xe0($sp)
  lui   $t5, 0xb400
  sw    $t5, ($s0)
  lw    $t8, 0xdc($sp)
  lui   $t1, 0xffff
  and   $t6, $ra, $t1
  and   $t9, $t8, $t1
  srl   $t7, $t9, 0x10
  or    $t8, $t6, $t7
  sw    $t8, 4($s0)
  addiu $a0, $s0, 8
  lui   $t9, 0xb200
  sw    $t9, ($a0)
  lw    $t6, 0xd8($sp)
  and   $t8, $t3, $t1
  srl   $t9, $t8, 0x10
  and   $t7, $t6, $t1
  or    $t6, $t7, $t9
  sw    $t6, 4($a0)
  addiu $a1, $a0, 8
  sw    $t5, ($a1)
  lw    $t9, 0xcc($sp)
  lw    $t8, 0xd0($sp)
  addiu $a2, $a1, 8
  and   $t6, $t9, $t1
  and   $t7, $t8, $t1
  srl   $t8, $t6, 0x10
  or    $t9, $t7, $t8
  sw    $t9, 4($a1)
  lw    $t4, 0xc4($sp)
  lui   $t6, 0xb200
  sw    $t6, ($a2)
  lw    $t7, 0xc8($sp)
  and   $t9, $t4, $t1
  srl   $t6, $t9, 0x10
  and   $t8, $t7, $t1
  or    $t7, $t8, $t6
  sw    $t7, 4($a2)
  addiu $v1, $a2, 8
  sw    $t5, ($v1)
  lw    $t6, 0xdc($sp)
  sll   $t8, $ra, 0x10
  addiu $s0, $v1, 8
  andi  $t7, $t6, 0xffff
  or    $t9, $t8, $t7
  sw    $t9, 4($v1)
  lui   $t6, 0xb200
  sw    $t6, ($s0)
  lw    $t7, 0xd8($sp)
  andi  $t6, $t3, 0xffff
  addiu $a3, $s0, 8
  sll   $t9, $t7, 0x10
  or    $t8, $t9, $t6
  sw    $t8, 4($s0)
  sw    $t5, ($a3)
  lw    $t8, 0xcc($sp)
  lw    $t9, 0xd0($sp)
  lw    $t3, 0xc0($sp)
  andi  $t7, $t8, 0xffff
  sll   $t6, $t9, 0x10
  lw    $a2, 0xbc($sp)
  or    $t9, $t6, $t7
  sw    $t9, 4($a3)
  lui   $t5, 0xb200
  addiu $v1, $a3, 8
  sw    $t5, ($v1)
  lw    $t6, 0xc8($sp)
  andi  $t9, $t4, 0xffff
  addiu $a0, $v1, 8
  sll   $t7, $t6, 0x10
  or    $t8, $t7, $t9
  sw    $t8, 4($v1)
  lui   $t6, 0xb400
  and   $t9, $a2, $t1
  srl   $t8, $t9, 0x10
  sw    $t6, ($a0)
  and   $t7, $t3, $t1
  or    $t6, $t7, $t8
  and   $t7, $v0, $t1
  sw    $t6, 4($a0)
  srl   $t8, $t7, 0x10
  and   $t9, $t0, $t1
  addiu $a1, $a0, 8
  or    $t6, $t9, $t8
  sw    $t6, 4($a1)
  sw    $t5, ($a1)
  lw    $ra, 0xac($sp)
  lw    $t5, 0xb0($sp)
  move  $t2, $v0
  addiu $s0, $a1, 8
  lw    $t4, 0xa8($sp)
  lw    $a3, 0xa4($sp)
  move  $v0, $s0
  lui   $t7, 0xb400
  and   $t8, $ra, $t1
  srl   $t6, $t8, 0x10
  sw    $t7, ($v0)
  and   $t9, $t5, $t1
  or    $t7, $t9, $t6
  sw    $t7, 4($v0)
  addiu $v1, $s0, 8
  lui   $t8, 0xb200
  and   $t6, $a3, $t1
  srl   $t7, $t6, 0x10
  sw    $t8, ($v1)
  and   $t9, $t4, $t1
  or    $t8, $t9, $t7
  sw    $t8, 4($v1)
  addiu $s0, $v1, 8
  lui   $t6, 0xb400
  sw    $t6, ($s0)
  sll   $t7, $t3, 0x10
  andi  $t8, $a2, 0xffff
  or    $t6, $t7, $t8
  sw    $t6, 4($s0)
  addiu $a1, $s0, 8
  lui   $t9, 0xb200
  sw    $t9, ($a1)
  andi  $t6, $t2, 0xffff
  sll   $t8, $t0, 0x10
  or    $t9, $t8, $t6
  sw    $t9, 4($a1)
  addiu $v1, $a1, 8
  lui   $t7, 0xb400
  sw    $t7, ($v1)
  andi  $t9, $ra, 0xffff
  sll   $t6, $t5, 0x10
  or    $t7, $t6, $t9
  sw    $t7, 4($v1)
  addiu $a0, $v1, 8
  lui   $t8, 0xb300
  sw    $t8, ($a0)
  sll   $t9, $t4, 0x10
  andi  $t7, $a3, 0xffff
  or    $t8, $t9, $t7
  sw    $t8, 4($a0)
  addiu $v0, $a0, 8
.L7F09A2CC:
  lw    $ra, 0x24($sp)
  ldc1  $f20, 0x18($sp)
  lw    $s0, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x4d0
");

asm(R"
glabel default_player_perspective_and_height
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f0
  lui   $at, %hi(player1_player_data+0x64)
  swc1  $f0, %lo(player1_player_data+0x64)($at)
  lui   $at, %hi(player1_player_data+0x5c)
  swc1  $f0, %lo(player1_player_data+0x5c)($at)
  lui   $at, %hi(player2_player_data+0x64)
  swc1  $f0, %lo(player2_player_data+0x64)($at)
  lui   $at, %hi(player2_player_data+0x5C)
  swc1  $f0, %lo(player2_player_data+0x5C)($at)
  lui   $at, %hi(player3_player_data+0x64)
  swc1  $f0, %lo(player3_player_data+0x64)($at)
  lui   $at, %hi(player3_player_data+0x5C)
  swc1  $f0, %lo(player3_player_data+0x5C)($at)
  lui   $at, %hi(player4_player_data+0x64)
  swc1  $f0, %lo(player4_player_data+0x64)($at)
  lui   $at, %hi(player4_player_data+92)
  jr    $ra
   swc1  $f0, %lo(player4_player_data+92)($at)
");

asm(R"
glabel reset_play_data_ptrs
  lui   $v0, %hi(players_p1)
  addiu $v0, %lo(players_p1) # addiu $v0, $v0, -0x6120
  sw    $zero, ($v0)
  sw    $zero, 4($v0)
  sw    $zero, 8($v0)
  sw    $zero, 0xc($v0)
  lui   $at, %hi(pPlayer)
  sw    $zero, %lo(pPlayer)($at)
  lui   $at, %hi(pPlayersPerm)
  sw    $zero, %lo(pPlayersPerm)($at)
  lui   $at, %hi(player_num)
  sw    $zero, %lo(player_num)($at)
  lui   $v1, %hi(dword_CODE_bss_8007A0C0)
  lui   $at, %hi(random_byte)
  addiu $v1, %lo(dword_CODE_bss_8007A0C0) # addiu $v1, $v1, -0x5f40
  sw    $zero, %lo(random_byte)($at)
  li    $t6, 1
  li    $t7, 2
  li    $t8, 3
  sw    $zero, ($v1)
  sw    $t6, 4($v1)
  sw    $t7, 8($v1)
  jr    $ra
   sw    $t8, 0xc($v1)
");

asm(R"
glabel init_player_data_ptrs_construct_viewports
  lui   $v0, %hi(players_p1)
  addiu $v0, %lo(players_p1) # addiu $v0, $v0, -0x6120
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  move  $s1, $a0
  sw    $s0, 0x14($sp)
  sw    $zero, ($v0)
  sw    $zero, 4($v0)
  sw    $zero, 8($v0)
  jal   get_random_value
   sw    $zero, 0xc($v0)
  andi  $t6, $v0, 0xff
  lui   $at, %hi(random_byte)
  blez  $s1, .L7F09A3F8
   sw    $t6, %lo(random_byte)($at)
  blez  $s1, .L7F09A3E8
   move  $s0, $zero
.L7F09A3D4:
  jal   initBONDdataforPlayer
   move  $a0, $s0
  addiu $s0, $s0, 1
  bne   $s0, $s1, .L7F09A3D4
   nop   
.L7F09A3E8:
  jal   set_cur_player
   move  $a0, $zero
  b     .L7F09A454
   lw    $ra, 0x1c($sp)
.L7F09A3F8:
  jal   initBONDdataforPlayer
   move  $a0, $zero
  jal   set_cur_player
   move  $a0, $zero
  jal   get_video2_settings_width
   nop   
  sll   $s0, $v0, 0x10
  sra   $t7, $s0, 0x10
  jal   get_video2_settings_height
   move  $s0, $t7
  move  $a0, $s0
  jal   set_cur_player_screen_size
   move  $a1, $v0
  jal   get_video2_settings_ulx
   nop   
  sll   $s0, $v0, 0x10
  sra   $t8, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t8
  move  $a0, $s0
  jal   set_cur_player_viewport_size
   move  $a1, $v0
  lw    $ra, 0x1c($sp)
.L7F09A454:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x20
");

int getPlayerCount(void) {
  int count = 0;
  if (players_p1)
    count = 1;
  if (players_p2)
    count += 1;
  if (players_p3)
    count += 1;
  if (players_p4)
    count += 1;
  return count;
}

#ifdef VERSION_US
asm(R"
.late_rodata
glabel D_80057610
.word 0xc3652ee0 /*-229.18311*/
glabel D_80057614
.word 0x411ffffe /*9.9999981*/
glabel D_80057618
.word 0x3f6e147b /*0.93000001*/
glabel D_8005761C
.word 0x4164924b /*14.285716*/
glabel D_80057620
.word 0x3f666666 /*0.89999998*/
glabel D_80057624
.word 0xc0490fdb /*-3.1415927*/
glabel D_80057628
.word 0x3faaaaab /*1.3333334*/
.text
glabel initBONDdataforPlayer
  addiu $sp, $sp, -0x3d0
  lui   $t7, %hi(D_8003FD94+0xC) 
  addiu $t7, %lo(D_8003FD94+0xC) # addiu $t7, $t7, -0x260
  sw    $ra, 0x14($sp)
  sw    $a0, 0x3d0($sp)
  addiu $t3, $t7, 0x3a8
  addiu $t6, $sp, 0x24
.L7F09A4D8:
  lw    $at, ($t7)
  addiu $t7, $t7, 0xc
  addiu $t6, $t6, 0xc
  sw    $at, -0xc($t6)
  lw    $at, -8($t7)
  sw    $at, -8($t6)
  lw    $at, -4($t7)
  bne   $t7, $t3, .L7F09A4D8
   sw    $at, -4($t6)
  li    $a0, 10880
  jal   mempAllocBytesInBank
   li    $a1, 4
  lw    $t4, 0x3d0($sp)
  lui   $t9, %hi(players_p1) 
  addiu $t9, %lo(players_p1) # addiu $t9, $t9, -0x6120
  sll   $t5, $t4, 2
  addu  $v1, $t5, $t9
  sw    $v0, ($v1)
  sw    $zero, ($v0)
  mtc1  $zero, $f0
  lw    $t8, ($v1)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f2
  swc1  $f0, 4($t8)
  lw    $t3, ($v1)
  li    $a0, 2
  li    $t0, 1
  swc1  $f0, 8($t3)
  lw    $t7, ($v1)
  li    $t1, -1
  li    $at, 0xC0800000 # -4.000000
  swc1  $f0, 0xc($t7)
  lw    $t6, ($v1)
  mtc1  $at, $f4
  lui   $at, %hi(D_80057610)
  swc1  $f0, 0x10($t6)
  lw    $t4, ($v1)
  li    $v0, 255
  addiu $t2, $sp, 0x24
  swc1  $f0, 0x14($t4)
  lw    $t5, ($v1)
  swc1  $f2, 0x18($t5)
  lw    $t9, ($v1)
  swc1  $f0, 0x1c($t9)
  lw    $t8, ($v1)
  swc1  $f2, 0x20($t8)
  lw    $t3, ($v1)
  swc1  $f0, 0x24($t3)
  lw    $t7, ($v1)
  swc1  $f0, 0x28($t7)
  lw    $t6, ($v1)
  swc1  $f0, 0x2c($t6)
  lw    $t4, ($v1)
  swc1  $f0, 0x30($t4)
  lw    $t5, ($v1)
  sw    $zero, 0x34($t5)
  lw    $t9, ($v1)
  swc1  $f0, 0x38($t9)
  lw    $t8, ($v1)
  swc1  $f0, 0x3c($t8)
  lw    $t3, ($v1)
  swc1  $f0, 0x40($t3)
  lw    $t7, ($v1)
  swc1  $f0, 0x44($t7)
  lw    $t6, ($v1)
  swc1  $f0, 0x48($t6)
  lw    $t4, ($v1)
  swc1  $f0, 0x4c($t4)
  lw    $t5, ($v1)
  swc1  $f0, 0x50($t5)
  lw    $t9, ($v1)
  swc1  $f0, 0x54($t9)
  lw    $t8, ($v1)
  swc1  $f0, 0x58($t8)
  lw    $t3, ($v1)
  swc1  $f0, 0x6c($t3)
  lw    $t7, ($v1)
  swc1  $f0, 0x70($t7)
  lw    $t6, ($v1)
  swc1  $f0, 0x74($t6)
  lw    $t4, ($v1)
  swc1  $f0, 0x78($t4)
  lw    $t5, ($v1)
  swc1  $f0, 0x7c($t5)
  lw    $t9, ($v1)
  swc1  $f0, 0x80($t9)
  lw    $t8, ($v1)
  swc1  $f0, 0x84($t8)
  lw    $t3, ($v1)
  swc1  $f0, 0x88($t3)
  lw    $t7, ($v1)
  sw    $zero, 0x8c($t7)
  lw    $t6, ($v1)
  swc1  $f0, 0x90($t6)
  lw    $t4, ($v1)
  sw    $zero, 0x94($t4)
  lw    $t5, ($v1)
  swc1  $f0, 0x98($t5)
  lw    $t9, ($v1)
  swc1  $f0, 0x1274($t9)
  lw    $t8, ($v1)
  swc1  $f0, 0x1278($t8)
  lw    $t3, ($v1)
  swc1  $f0, 0x127c($t3)
  lw    $t7, ($v1)
  sw    $a0, 0x9c($t7)
  lw    $t6, ($v1)
  sw    $a0, 0x29fc($t6)
  lw    $t4, ($v1)
  swc1  $f0, 0xa0($t4)
  lw    $t5, ($v1)
  swc1  $f0, 0xa4($t5)
  lw    $t9, ($v1)
  sw    $zero, 0xa8($t9)
  lw    $t8, ($v1)
  sw    $t0, 0xac($t8)
  lw    $t3, ($v1)
  sw    $zero, 0xd0($t3)
  lw    $t7, ($v1)
  sw    $zero, 0xd4($t7)
  lw    $t6, ($v1)
  sw    $zero, 0xd8($t6)
  lw    $t4, ($v1)
  swc1  $f2, 0xdc($t4)
  lw    $t5, ($v1)
  swc1  $f0, 0xe0($t5)
  lw    $t9, ($v1)
  swc1  $f2, 0xe4($t9)
  lw    $t8, ($v1)
  swc1  $f0, 0xe8($t8)
  lw    $t3, ($v1)
  swc1  $f2, 0xec($t3)
  lw    $t7, ($v1)
  swc1  $f0, 0xf0($t7)
  lw    $t6, ($v1)
  sw    $t1, 0xf4($t6)
  lw    $t4, ($v1)
  sw    $t1, 0xf8($t4)
  lw    $t5, ($v1)
  sw    $zero, 0x104($t5)
  lw    $t9, ($v1)
  sw    $zero, 0x108($t9)
  lw    $t8, ($v1)
  sw    $zero, 0x10c($t8)
  lw    $t3, ($v1)
  sw    $zero, 0x110($t3)
  lw    $t7, ($v1)
  sw    $t0, 0x114($t7)
  lw    $t6, ($v1)
  sw    $t0, 0x118($t6)
  lw    $t4, ($v1)
  sw    $zero, 0x11c($t4)
  lw    $t5, ($v1)
  sw    $t0, 0x120($t5)
  lw    $t9, ($v1)
  sw    $zero, 0x124($t9)
  lw    $t8, ($v1)
  sw    $t0, 0x128($t8)
  lw    $t3, ($v1)
  swc1  $f0, 0x12c($t3)
  lw    $t7, ($v1)
  sw    $zero, 0x130($t7)
  lw    $t6, ($v1)
  sw    $t1, 0x134($t6)
  lw    $t4, ($v1)
  sw    $t0, 0x138($t4)
  lw    $t5, ($v1)
  swc1  $f0, 0x13c($t5)
  lw    $t9, ($v1)
  sw    $zero, 0x140($t9)
  lw    $t8, ($v1)
  sw    $t1, 0x144($t8)
  lw    $t3, ($v1)
  swc1  $f0, 0x148($t3)
  lw    $t7, ($v1)
  swc1  $f0, 0x14c($t7)
  lw    $t6, ($v1)
  swc1  $f2, 0x150($t6)
  lw    $t4, ($v1)
  swc1  $f0, 0x154($t4)
  lw    $t5, ($v1)
  swc1  $f4, 0x158($t5)
  lw    $t9, ($v1)
  lwc1  $f6, %lo(D_80057610)($at)
  li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f12
  swc1  $f6, 0x15c($t9)
  lw    $t8, ($v1)
  li    $at, 0xC1C80000 # -25.000000
  mtc1  $at, $f8
  swc1  $f0, 0x160($t8)
  lw    $t3, ($v1)
  lui   $at, %hi(D_80057614)
  swc1  $f2, 0x164($t3)
  lw    $t7, ($v1)
  swc1  $f0, 0x168($t7)
  lw    $t6, ($v1)
  swc1  $f0, 0x16c($t6)
  lw    $t4, ($v1)
  swc1  $f0, 0x170($t4)
  lw    $t5, ($v1)
  swc1  $f0, 0x174($t5)
  lw    $t9, ($v1)
  swc1  $f0, 0x2a4c($t9)
  lw    $t8, ($v1)
  swc1  $f2, 0x178($t8)
  lw    $t3, ($v1)
  swc1  $f0, 0x180($t3)
  lw    $t7, ($v1)
  swc1  $f0, 0x184($t7)
  lw    $t6, ($v1)
  swc1  $f0, 0x188($t6)
  lw    $t4, ($v1)
  swc1  $f12, 0x18c($t4)
  lw    $t5, ($v1)
  swc1  $f12, 0x190($t5)
  lw    $t9, ($v1)
  swc1  $f0, 0x194($t9)
  lw    $t8, ($v1)
  swc1  $f0, 0x198($t8)
  lw    $t3, ($v1)
  swc1  $f0, 0x19c($t3)
  lw    $t7, ($v1)
  sw    $zero, 0x1a0($t7)
  lw    $t6, ($v1)
  sw    $zero, 0x1c0($t6)
  lw    $t4, ($v1)
  sw    $zero, 0x1c4($t4)
  lw    $t5, ($v1)
  sw    $zero, 0x1c8($t5)
  lw    $t9, ($v1)
  sw    $t0, 0x1cc($t9)
  lw    $t8, ($v1)
  sw    $zero, 0x1d0($t8)
  lw    $t3, ($v1)
  swc1  $f0, 0x1d4($t3)
  lw    $t7, ($v1)
  swc1  $f0, 0x1d8($t7)
  lw    $t6, ($v1)
  swc1  $f8, 0x1dc($t6)
  lw    $t4, ($v1)
  swc1  $f0, 0x1e0($t4)
  lw    $t5, ($v1)
  swc1  $f2, 0x1e4($t5)
  lw    $t9, ($v1)
  swc1  $f0, 0x1e8($t9)
  lw    $t8, ($v1)
  swc1  $f0, 0x1ec($t8)
  lw    $t3, ($v1)
  swc1  $f0, 0x1f0($t3)
  lw    $t7, ($v1)
  swc1  $f2, 0x1f4($t7)
  lw    $t6, ($v1)
  sw    $zero, 0x200($t6)
  lw    $t4, ($v1)
  swc1  $f0, 0x204($t4)
  lw    $t5, ($v1)
  swc1  $f0, 0x208($t5)
  lw    $t9, ($v1)
  swc1  $f0, 0x20c($t9)
  lw    $t8, ($v1)
  swc1  $f0, 0x210($t8)
  lw    $t3, ($v1)
  swc1  $f0, 0x214($t3)
  lw    $t7, ($v1)
  sw    $zero, 0x218($t7)
  lw    $t6, ($v1)
  sw    $t0, 0x21c($t6)
  lw    $t4, ($v1)
  sw    $zero, 0x220($t4)
  lw    $t5, ($v1)
  swc1  $f0, 0x224($t5)
  lw    $t9, ($v1)
  sh    $zero, 0x3b4($t9)
  lw    $t8, ($v1)
  sh    $zero, 0x3b6($t8)
  lw    $t3, ($v1)
  swc1  $f0, 0x3b8($t3)
  lw    $t7, ($v1)
  swc1  $f0, 0x3bc($t7)
  lw    $t6, ($v1)
  lwc1  $f10, %lo(D_80057614)($at)
  swc1  $f10, 0x3c0($t6)
  lw    $t4, ($v1)
  swc1  $f0, 0x3c4($t4)
  lw    $t5, ($v1)
  swc1  $f0, 0x3c8($t5)
  lw    $t9, ($v1)
  swc1  $f2, 0x3cc($t9)
  lw    $t8, ($v1)
  sw    $v0, 0x3d0($t8)
  lw    $t3, ($v1)
  sw    $v0, 0x3d4($t3)
  lw    $t7, ($v1)
  lui   $at, %hi(D_80057618)
  li    $a3, 32
  sw    $v0, 0x3d8($t7)
  lw    $t6, ($v1)
  li    $a2, 511
  li    $a1, 480
  swc1  $f0, 0x3dc($t6)
  lw    $t4, ($v1)
  swc1  $f12, 0x3e0($t4)
  lw    $t5, ($v1)
  swc1  $f12, 0x3e4($t5)
  lw    $t9, ($v1)
  sw    $v0, 0x3e8($t9)
  lw    $t8, ($v1)
  sw    $v0, 0x3ec($t8)
  lw    $t3, ($v1)
  sw    $v0, 0x3f0($t3)
  lw    $t7, ($v1)
  sw    $v0, 0x3f4($t7)
  lw    $t6, ($v1)
  sw    $v0, 0x3f8($t6)
  lw    $t4, ($v1)
  sw    $v0, 0x3fc($t4)
  lw    $t5, ($v1)
  move  $v0, $zero
  swc1  $f0, 0x400($t5)
  lw    $t9, ($v1)
  swc1  $f0, 0x404($t9)
  lw    $t8, ($v1)
  sw    $zero, 0x41c($t8)
  lw    $t3, ($v1)
  sw    $t0, 0x420($t3)
  lw    $t7, ($v1)
  sw    $zero, 0x424($t7)
  lw    $t6, ($v1)
  sw    $zero, 0x428($t6)
  lw    $t4, ($v1)
  sw    $a0, 0x42c($t4)
  lw    $t5, ($v1)
  li    $a0, 640
  sw    $zero, 0x430($t5)
  lw    $t9, ($v1)
  sw    $t0, 0x4dc($t9)
  lw    $t8, ($v1)
  sw    $t0, 0x4e0($t8)
  lw    $t3, ($v1)
  sw    $t0, 0x4e4($t3)
  lw    $t7, ($v1)
  sw    $zero, 0x4e8($t7)
  lw    $t6, ($v1)
  lwc1  $f18, %lo(D_80057618)($at)
  lui   $at, %hi(D_8005761C)
  swc1  $f18, 0x4ec($t6)
  lw    $t4, ($v1)
  sw    $zero, 0x4f0($t4)
  lw    $t5, ($v1)
  swc1  $f2, 0x4f4($t5)
  lw    $t9, ($v1)
  swc1  $f2, 0x4f8($t9)
  lw    $t8, ($v1)
  swc1  $f0, 0x4fc($t8)
  lw    $t3, ($v1)
  swc1  $f0, 0x500($t3)
  lw    $t7, ($v1)
  swc1  $f0, 0x504($t7)
  lw    $t6, ($v1)
  lwc1  $f12, %lo(D_8005761C)($at)
  swc1  $f0, 0x508($t6)
  lw    $t4, ($v1)
  swc1  $f0, 0x50c($t4)
  lw    $t5, ($v1)
  swc1  $f2, 0x510($t5)
  lw    $t9, ($v1)
  swc1  $f0, 0x514($t9)
  lw    $t8, ($v1)
  swc1  $f2, 0x518($t8)
  lw    $t3, ($v1)
  swc1  $f0, 0x51c($t3)
  lw    $t7, ($v1)
  swc1  $f0, 0x520($t7)
  lw    $t6, ($v1)
  swc1  $f0, 0x524($t6)
  lw    $t4, ($v1)
  swc1  $f0, 0x528($t4)
  lw    $t5, ($v1)
  swc1  $f0, 0x52c($t5)
  lw    $t9, ($v1)
  swc1  $f0, 0x530($t9)
  lw    $t8, ($v1)
  swc1  $f12, 0x534($t8)
  lw    $t3, ($v1)
  swc1  $f0, 0x538($t3)
  lw    $t7, ($v1)
  swc1  $f12, 0x53c($t7)
  lw    $t6, ($v1)
  swc1  $f0, 0x540($t6)
  lw    $t4, ($v1)
  swc1  $f0, 0x544($t4)
  lw    $t5, ($v1)
  swc1  $f0, 0x548($t5)
  lw    $t9, ($v1)
  swc1  $f0, 0x54c($t9)
  lw    $t8, ($v1)
  swc1  $f0, 0x550($t8)
  lw    $t3, ($v1)
  swc1  $f0, 0x554($t3)
  lw    $t7, ($v1)
  swc1  $f0, 0x558($t7)
  lw    $t6, ($v1)
  swc1  $f0, 0x55c($t6)
  lw    $t4, ($v1)
  swc1  $f0, 0x560($t4)
  lw    $t5, ($v1)
  swc1  $f0, 0x564($t5)
  lw    $t9, ($v1)
  swc1  $f0, 0x568($t9)
  lw    $t8, ($v1)
  swc1  $f2, 0x56c($t8)
  lw    $t3, ($v1)
  swc1  $f0, 0x570($t3)
  lw    $t7, ($v1)
  swc1  $f0, 0x574($t7)
  lw    $t6, ($v1)
  swc1  $f2, 0x578($t6)
  lw    $t4, ($v1)
  swc1  $f0, 0x57c($t4)
  lw    $t5, ($v1)
  swc1  $f2, 0x580($t5)
  lw    $t9, ($v1)
  swc1  $f0, 0x584($t9)
  lw    $t8, ($v1)
  swc1  $f0, 0x588($t8)
  lw    $t3, ($v1)
  swc1  $f2, 0x58c($t3)
  lw    $t7, ($v1)
  swc1  $f0, 0x590($t7)
  lw    $t6, ($v1)
  sw    $zero, 0x594($t6)
.L7F09AB98:
  lw    $t4, ($v1)
  addu  $t5, $t4, $v0
  sh    $a0, 0x7d0($t5)
  lw    $t9, ($v1)
  addu  $t8, $t9, $v0
  sh    $a1, 0x7d2($t8)
  lw    $t3, ($v1)
  addu  $t7, $t3, $v0
  sh    $a2, 0x7d4($t7)
  lw    $t6, ($v1)
  addu  $t4, $t6, $v0
  sh    $zero, 0x7d6($t4)
  lw    $t5, ($v1)
  addu  $t9, $t5, $v0
  sh    $a0, 0x7d8($t9)
  lw    $t8, ($v1)
  addu  $t3, $t8, $v0
  sh    $a1, 0x7da($t3)
  lw    $t7, ($v1)
  addu  $t6, $t7, $v0
  sh    $a2, 0x7dc($t6)
  lw    $t4, ($v1)
  addu  $t5, $t4, $v0
  addiu $v0, $v0, 0x10
  bne   $v0, $a3, .L7F09AB98
   sh    $zero, 0x7de($t5)
  lw    $t9, ($v1)
  li    $v0, 100
  sh    $v0, 0x7f0($t9)
  lw    $t8, ($v1)
  sh    $v0, 0x7f2($t8)
  lw    $t3, ($v1)
  sh    $zero, 0x7f4($t3)
  lw    $t7, ($v1)
  sh    $zero, 0x7f6($t7)
  lw    $t6, ($v1)
  sw    $zero, 0x7f8($t6)
  lw    $t4, ($v1)
  sw    $zero, 0x7fc($t4)
  lw    $t5, ($v1)
  sw    $zero, 0x800($t5)
  lw    $t9, ($v1)
  sw    $zero, 0x804($t9)
  lw    $t8, ($v1)
  sw    $t1, 0x2a44($t8)
  lw    $t3, ($v1)
  move  $t8, $t2
  sw    $t1, 0x2a48($t3)
  lw    $t7, ($v1)
  addiu $t3, $t2, 0x3a8
  sw    $zero, 0x2a50($t7)
  lw    $t6, ($v1)
  move  $t7, $t2
  sw    $zero, 0x2a54($t6)
  lw    $t4, ($v1)
  sw    $zero, 0x808($t4)
  lw    $t5, ($v1)
  sw    $zero, 0x80c($t5)
  lw    $t9, ($v1)
.L7F09AC84:
  lw    $at, ($t7)
  addiu $t7, $t7, 0xc
  addiu $t9, $t9, 0xc
  sw    $at, 0x864($t9)
  lw    $at, -8($t7)
  sw    $at, 0x868($t9)
  lw    $at, -4($t7)
  bne   $t7, $t3, .L7F09AC84
   sw    $at, 0x86c($t9)
  lw    $t6, ($v1)
  addiu $t5, $t2, 0x3a8
.L7F09ACB0:
  lw    $at, ($t8)
  addiu $t8, $t8, 0xc
  addiu $t6, $t6, 0xc
  sw    $at, 0xc0c($t6)
  lw    $at, -8($t8)
  sw    $at, 0xc10($t6)
  lw    $at, -4($t8)
  bne   $t8, $t5, .L7F09ACB0
   sw    $at, 0xc14($t6)
  lw    $t3, ($v1)
  lui   $at, %hi(D_80057620)
  li    $v0, 255
  swc1  $f2, 0xfc0($t3)
  lw    $t7, ($v1)
  li    $a0, 7
  swc1  $f2, 0xfc4($t7)
  lw    $t9, ($v1)
  sw    $zero, 0xfc8($t9)
  lw    $t4, ($v1)
  sw    $zero, 0xfcc($t4)
  lw    $t5, ($v1)
  lwc1  $f12, %lo(D_80057620)($at)
  li    $at, 0x42700000 # 60.000000
  sw    $zero, 0xfd0($t5)
  lw    $t8, ($v1)
  sw    $zero, 0xfd4($t8)
  lw    $t6, ($v1)
  sw    $zero, 0xfd8($t6)
  lw    $t3, ($v1)
  sb    $v0, 0xfdc($t3)
  lw    $t7, ($v1)
  sb    $v0, 0xfdd($t7)
  lw    $t9, ($v1)
  sb    $v0, 0xfde($t9)
  lw    $t4, ($v1)
  lui   $v0, %hi(random_byte)
  addiu $v0, %lo(random_byte) # addiu $v0, $v0, -0x5f44
  sb    $zero, 0xfdf($t4)
  lw    $t5, ($v1)
  sw    $t0, 0xfe0($t5)
  lw    $t8, ($v1)
  sw    $zero, 0xfe4($t8)
  lw    $t6, ($v1)
  swc1  $f0, 0xfe8($t6)
  lw    $t3, ($v1)
  swc1  $f0, 0xfec($t3)
  lw    $t7, ($v1)
  swc1  $f0, 0xff0($t7)
  lw    $t9, ($v1)
  swc1  $f0, 0xff4($t9)
  lw    $t4, ($v1)
  swc1  $f12, 0xff8($t4)
  lw    $t5, ($v1)
  swc1  $f0, 0xffc($t5)
  lw    $t8, ($v1)
  swc1  $f0, 0x1000($t8)
  lw    $t6, ($v1)
  swc1  $f0, 0x1004($t6)
  lw    $t3, ($v1)
  swc1  $f0, 0x1008($t3)
  lw    $t7, ($v1)
  swc1  $f12, 0x100c($t7)
  mtc1  $at, $f12
  lw    $t9, ($v1)
  li    $at, 0x43A00000 # 320.000000
  mtc1  $at, $f14
  li    $at, 0x43700000 # 240.000000
  mtc1  $at, $f16
  swc1  $f0, 0x1010($t9)
  lui   $at, %hi(D_80057624)
  lwc1  $f4, %lo(D_80057624)($at)
  lw    $t4, ($v1)
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f6
  swc1  $f4, 0x1014($t4)
  lw    $t5, ($v1)
  li    $at, 0x42380000 # 46.000000
  mtc1  $at, $f8
  swc1  $f0, 0x1018($t5)
  lw    $t8, ($v1)
  li    $at, 0x43200000 # 160.000000
  mtc1  $at, $f10
  sw    $zero, 0x105c($t8)
  lw    $t6, ($v1)
  li    $at, 0x42F00000 # 120.000000
  mtc1  $at, $f18
  sw    $zero, 0x1060($t6)
  lw    $t3, ($v1)
  lui   $at, %hi(D_80057628)
  sw    $zero, 0x1064($t3)
  lw    $t7, ($v1)
  swc1  $f0, 0x106c($t7)
  lw    $t9, ($v1)
  swc1  $f0, 0x1070($t9)
  lw    $t4, ($v1)
  swc1  $f0, 0x1074($t4)
  lw    $t5, ($v1)
  sw    $zero, 0x1078($t5)
  lw    $t8, ($v1)
  swc1  $f0, 0x107c($t8)
  lw    $t6, ($v1)
  swc1  $f0, 0x1080($t6)
  lw    $t3, ($v1)
  swc1  $f12, 0x1084($t3)
  lw    $t7, ($v1)
  swc1  $f12, 0x1088($t7)
  lw    $t9, ($v1)
  sw    $t1, 0x108c($t9)
  lw    $t4, ($v1)
  swc1  $f14, 0x1090($t4)
  lw    $t5, ($v1)
  swc1  $f16, 0x1094($t5)
  lw    $t8, ($v1)
  swc1  $f0, 0x1098($t8)
  lw    $t6, ($v1)
  swc1  $f0, 0x109c($t6)
  lw    $t3, ($v1)
  swc1  $f6, 0x10a0($t3)
  lw    $t7, ($v1)
  swc1  $f8, 0x10a4($t7)
  lw    $t9, ($v1)
  swc1  $f2, 0x10a8($t9)
  lw    $t4, ($v1)
  swc1  $f10, 0x10ac($t4)
  lw    $t5, ($v1)
  swc1  $f18, 0x10b0($t5)
  lw    $t8, ($v1)
  swc1  $f2, 0x10b4($t8)
  lw    $t6, ($v1)
  swc1  $f2, 0x10b8($t6)
  lw    $t3, ($v1)
  swc1  $f2, 0x10bc($t3)
  lw    $t7, ($v1)
  swc1  $f2, 0x10c0($t7)
  lw    $t9, ($v1)
  sw    $zero, 0x10c4($t9)
  lw    $t4, ($v1)
  sw    $zero, 0x10c8($t4)
  lw    $t5, ($v1)
  sw    $zero, 0x10cc($t5)
  lw    $t8, ($v1)
  sw    $zero, 0x10d0($t8)
  lw    $t6, ($v1)
  sw    $zero, 0x10d4($t6)
  lw    $t3, ($v1)
  sw    $zero, 0x10d8($t3)
  lw    $t7, ($v1)
  sw    $zero, 0x10dc($t7)
  lw    $t9, ($v1)
  sw    $zero, 0x10e0($t9)
  lw    $t4, ($v1)
  lui   $t9, 1
  sw    $zero, 0x10e4($t4)
  lw    $t5, ($v1)
  sw    $zero, 0x10e8($t5)
  lw    $t8, ($v1)
  sw    $zero, 0x10ec($t8)
  lw    $t6, ($v1)
  swc1  $f2, 0x10f0($t6)
  lw    $t3, ($v1)
  swc1  $f2, 0x10f4($t3)
  lw    $t7, ($v1)
  swc1  $f2, 0x10f8($t7)
  lw    $t4, ($v1)
  sw    $t9, 0x10fc($t4)
  lw    $t5, ($v1)
  swc1  $f0, 0x1118($t5)
  lw    $t8, ($v1)
  swc1  $f0, 0x111c($t8)
  lw    $t6, ($v1)
  swc1  $f14, 0x1120($t6)
  lw    $t3, ($v1)
  swc1  $f16, 0x1124($t3)
  lw    $t7, ($v1)
  sw    $zero, 0x1128($t7)
  lw    $t9, ($v1)
  sw    $zero, 0x11b0($t9)
  lw    $t4, ($v1)
  sw    $zero, 0x11b4($t4)
  lw    $t5, ($v1)
  sw    $zero, 0x11b8($t5)
  lw    $t8, ($v1)
  swc1  $f0, 0x11bc($t8)
  lw    $t6, ($v1)
  swc1  $f0, 0x11c0($t6)
  lw    $t3, ($v1)
  swc1  $f12, 0x11c4($t3)
  lw    $t7, ($v1)
  swc1  $f12, 0x11c8($t7)
  lw    $t9, ($v1)
  swc1  $f12, 0x11cc($t9)
  lw    $t4, ($v1)
  swc1  $f12, 0x11d0($t4)
  lw    $t5, ($v1)
  lwc1  $f4, %lo(D_80057628)($at)
  lui   $at, %hi(invisible_to_guards_flag)
  swc1  $f4, 0x11d4($t5)
  lw    $t8, ($v1)
  sw    $zero, 0x11d8($t8)
  lw    $t6, ($v1)
  sw    $t1, 0x11dc($t6)
  lw    $t3, ($v1)
  sw    $zero, 0x11e0($t3)
  lw    $t7, ($v1)
  sw    $zero, 0x11e4($t7)
  lw    $t9, ($v1)
  sw    $zero, 0x11e8($t9)
  lw    $t4, ($v1)
  sw    $zero, 0x11ec($t4)
  lw    $t5, ($v1)
  sw    $zero, 0x11f0($t5)
  lw    $t8, ($v1)
  sw    $zero, 0x11f4($t8)
  lw    $t6, ($v1)
  swc1  $f0, 0x1280($t6)
  lw    $t3, ($v1)
  sw    $zero, 0x1284($t3)
  lw    $t7, ($v1)
  swc1  $f0, 0x1288($t7)
  lw    $t9, ($v1)
  sb    $zero, 0x12b6($t9)
  lw    $t4, ($v1)
  sw    $a0, 0x29b8($t4)
  lw    $t5, ($v1)
  swc1  $f2, 0x29bc($t5)
  lw    $t8, ($v1)
  swc1  $f0, 0x29c0($t8)
  lw    $t6, ($v1)
  sw    $zero, 0x29c4($t6)
  lw    $t3, ($v1)
  sw    $a0, 0x29d4($t3)
  lw    $t7, ($v1)
  sw    $zero, 0x29d8($t7)
  lw    $t4, ($v1)
  lw    $t9, ($v0)
  sw    $t9, 0x29e0($t4)
  lw    $t5, ($v0)
  lw    $t6, ($v1)
  addiu $t8, $t5, 1
  sw    $t8, ($v0)
  sw    $t1, 0x29e4($t6)
  lw    $t3, ($v1)
  sw    $t1, 0x29e8($t3)
  lw    $t7, ($v1)
  sw    $t1, 0x29ec($t7)
  lw    $t9, ($v1)
  sw    $t1, 0x29f0($t9)
  lw    $t4, ($v1)
  sw    $zero, 0x2a00($t4)
  lw    $t5, ($v1)
  sw    $zero, 0x2a30($t5)
  lw    $t8, ($v1)
  sw    $zero, 0x2a34($t8)
  lw    $t6, ($v1)
  sw    $t0, 0x2a38($t6)
  lw    $t3, ($v1)
  swc1  $f2, 0x2a3c($t3)
  lw    $t7, ($v1)
  swc1  $f2, 0x2a40($t7)
  lw    $t9, ($v1)
  sw    $zero, 0x2a58($t9)
  lw    $t4, ($v1)
  sw    $zero, 0x2a5c($t4)
  lw    $t5, ($v1)
  swc1  $f0, 0x2a60($t5)
  lw    $t8, ($v1)
  sw    $zero, 0x2a64($t8)
  lw    $t6, ($v1)
  sw    $t0, 0x2a68($t6)
  lw    $t3, ($v1)
  sw    $zero, 0x2a6c($t3)
  lw    $t7, ($v1)
  sw    $zero, 0x2a70($t7)
  lw    $ra, 0x14($sp)
  sw    $t0, %lo(invisible_to_guards_flag)($at)
  lui   $at, %hi(obj_collision_flag)
  sw    $t0, %lo(obj_collision_flag)($at)
  jr    $ra
   addiu $sp, $sp, 0x3d0
");
#endif

#ifdef VERSION_JP
asm(R"
.late_rodata
glabel D_80057610
.word 0xc3652ee0 /*-229.18311*/
glabel D_80057614
.word 0x411ffffe /*9.9999981*/
glabel D_80057618
.word 0x3f6e147b /*0.93000001*/
glabel D_8005761C
.word 0x4164924b /*14.285716*/
glabel D_80057620
.word 0x3f666666 /*0.89999998*/
glabel D_80057624
.word 0xc0490fdb /*-3.1415927*/
glabel D_80057628
.word 0x3faaaaab /*1.3333334*/
.text
glabel initBONDdataforPlayer
  addiu $sp, $sp, -0x3d0
  lui   $t7, %hi(D_8003FD94+0xC) # $t7, 0x8004
  addiu $t7, %lo(D_8003FD94+0xC) # addiu $t7, $t7, -0x230
  sw    $ra, 0x14($sp)
  sw    $a0, 0x3d0($sp)
  addiu $t3, $t7, 0x3a8
  addiu $t6, $sp, 0x24
.L7F09B078:
  lw    $at, ($t7)
  addiu $t7, $t7, 0xc
  addiu $t6, $t6, 0xc
  sw    $at, -0xc($t6)
  lw    $at, -8($t7)
  sw    $at, -8($t6)
  lw    $at, -4($t7)
  bne   $t7, $t3, .L7F09B078
   sw    $at, -4($t6)
  li    $a0, 10880
  jal   mempAllocBytesInBank
   li    $a1, 4
  lw    $t4, 0x3d0($sp)
  lui   $t9, %hi(players_p1) # $t9, 0x8008
  addiu $t9, %lo(players_p1) # addiu $t9, $t9, -0x60b0
  sll   $t5, $t4, 2
  addu  $v1, $t5, $t9
  sw    $v0, ($v1)
  sw    $zero, ($v0)
  mtc1  $zero, $f0
  lw    $t8, ($v1)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f2
  swc1  $f0, 4($t8)
  lw    $t3, ($v1)
  li    $a0, 2
  li    $t0, 1
  swc1  $f0, 8($t3)
  lw    $t7, ($v1)
  li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f12
  swc1  $f0, 0xc($t7)
  lw    $t6, ($v1)
  li    $t1, -1
  li    $at, 0xC0800000 # -4.000000
  swc1  $f0, 0x10($t6)
  lw    $t4, ($v1)
  mtc1  $at, $f4
  lui   $at, %hi(D_80057610)
  swc1  $f0, 0x14($t4)
  lw    $t5, ($v1)
  li    $v0, 255
  addiu $t2, $sp, 0x24
  swc1  $f2, 0x18($t5)
  lw    $t9, ($v1)
  swc1  $f0, 0x1c($t9)
  lw    $t8, ($v1)
  swc1  $f2, 0x20($t8)
  lw    $t3, ($v1)
  swc1  $f0, 0x24($t3)
  lw    $t7, ($v1)
  swc1  $f0, 0x28($t7)
  lw    $t6, ($v1)
  swc1  $f0, 0x2c($t6)
  lw    $t4, ($v1)
  swc1  $f0, 0x30($t4)
  lw    $t5, ($v1)
  sw    $zero, 0x34($t5)
  lw    $t9, ($v1)
  swc1  $f0, 0x38($t9)
  lw    $t8, ($v1)
  swc1  $f0, 0x3c($t8)
  lw    $t3, ($v1)
  swc1  $f0, 0x40($t3)
  lw    $t7, ($v1)
  swc1  $f0, 0x44($t7)
  lw    $t6, ($v1)
  swc1  $f0, 0x48($t6)
  lw    $t4, ($v1)
  swc1  $f0, 0x4c($t4)
  lw    $t5, ($v1)
  swc1  $f0, 0x50($t5)
  lw    $t9, ($v1)
  swc1  $f0, 0x54($t9)
  lw    $t8, ($v1)
  swc1  $f0, 0x58($t8)
  lw    $t3, ($v1)
  swc1  $f0, 0x6c($t3)
  lw    $t7, ($v1)
  swc1  $f0, 0x70($t7)
  lw    $t6, ($v1)
  swc1  $f0, 0x74($t6)
  lw    $t4, ($v1)
  swc1  $f0, 0x78($t4)
  lw    $t5, ($v1)
  swc1  $f0, 0x7c($t5)
  lw    $t9, ($v1)
  swc1  $f0, 0x80($t9)
  lw    $t8, ($v1)
  swc1  $f0, 0x84($t8)
  lw    $t3, ($v1)
  swc1  $f0, 0x88($t3)
  lw    $t7, ($v1)
  sw    $zero, 0x8c($t7)
  lw    $t6, ($v1)
  swc1  $f0, 0x90($t6)
  lw    $t4, ($v1)
  sw    $zero, 0x94($t4)
  lw    $t5, ($v1)
  swc1  $f0, 0x98($t5)
  lw    $t9, ($v1)
  swc1  $f0, 0x1274($t9)
  lw    $t8, ($v1)
  swc1  $f0, 0x1278($t8)
  lw    $t3, ($v1)
  swc1  $f0, 0x127c($t3)
  lw    $t7, ($v1)
  sw    $a0, 0x9c($t7)
  lw    $t6, ($v1)
  sw    $a0, 0x29fc($t6)
  lw    $t4, ($v1)
  swc1  $f0, 0xa0($t4)
  lw    $t5, ($v1)
  swc1  $f0, 0xa4($t5)
  lw    $t9, ($v1)
  sw    $zero, 0xa8($t9)
  lw    $t8, ($v1)
  sw    $t0, 0xac($t8)
  lw    $t3, ($v1)
  sw    $zero, 0xd0($t3)
  lw    $t7, ($v1)
  sw    $zero, 0xd4($t7)
  lw    $t6, ($v1)
  sw    $zero, 0xd8($t6)
  lw    $t4, ($v1)
  swc1  $f2, 0xdc($t4)
  lw    $t5, ($v1)
  swc1  $f0, 0xe0($t5)
  lw    $t9, ($v1)
  swc1  $f2, 0xe4($t9)
  lw    $t8, ($v1)
  swc1  $f0, 0xe8($t8)
  lw    $t3, ($v1)
  swc1  $f2, 0xec($t3)
  lw    $t7, ($v1)
  swc1  $f0, 0xf0($t7)
  lw    $t6, ($v1)
  swc1  $f12, 0xf4($t6)
  lw    $t4, ($v1)
  swc1  $f12, 0xf8($t4)
  lw    $t5, ($v1)
  sw    $zero, 0x104($t5)
  lw    $t9, ($v1)
  sw    $zero, 0x108($t9)
  lw    $t8, ($v1)
  sw    $zero, 0x10c($t8)
  lw    $t3, ($v1)
  sw    $zero, 0x110($t3)
  lw    $t7, ($v1)
  sw    $t0, 0x114($t7)
  lw    $t6, ($v1)
  sw    $t0, 0x118($t6)
  lw    $t4, ($v1)
  sw    $zero, 0x11c($t4)
  lw    $t5, ($v1)
  sw    $t0, 0x120($t5)
  lw    $t9, ($v1)
  sw    $zero, 0x124($t9)
  lw    $t8, ($v1)
  sw    $t0, 0x128($t8)
  lw    $t3, ($v1)
  swc1  $f0, 0x12c($t3)
  lw    $t7, ($v1)
  sw    $zero, 0x130($t7)
  lw    $t6, ($v1)
  sw    $t1, 0x134($t6)
  lw    $t4, ($v1)
  sw    $t0, 0x138($t4)
  lw    $t5, ($v1)
  swc1  $f0, 0x13c($t5)
  lw    $t9, ($v1)
  sw    $zero, 0x140($t9)
  lw    $t8, ($v1)
  sw    $t1, 0x144($t8)
  lw    $t3, ($v1)
  swc1  $f0, 0x148($t3)
  lw    $t7, ($v1)
  swc1  $f0, 0x14c($t7)
  lw    $t6, ($v1)
  swc1  $f2, 0x150($t6)
  lw    $t4, ($v1)
  swc1  $f0, 0x154($t4)
  lw    $t5, ($v1)
  swc1  $f4, 0x158($t5)
  lw    $t9, ($v1)
  lwc1  $f6, %lo(D_80057610)($at)
  li    $at, 0xC1C80000 # -25.000000
  mtc1  $at, $f8
  swc1  $f6, 0x15c($t9)
  lw    $t8, ($v1)
  lui   $at, %hi(D_80057614) # $at, 0x8005
  swc1  $f0, 0x160($t8)
  lw    $t3, ($v1)
  swc1  $f2, 0x164($t3)
  lw    $t7, ($v1)
  swc1  $f0, 0x168($t7)
  lw    $t6, ($v1)
  swc1  $f0, 0x16c($t6)
  lw    $t4, ($v1)
  swc1  $f0, 0x170($t4)
  lw    $t5, ($v1)
  swc1  $f0, 0x174($t5)
  lw    $t9, ($v1)
  swc1  $f0, 0x2a4c($t9)
  lw    $t8, ($v1)
  swc1  $f2, 0x178($t8)
  lw    $t3, ($v1)
  swc1  $f0, 0x180($t3)
  lw    $t7, ($v1)
  swc1  $f0, 0x184($t7)
  lw    $t6, ($v1)
  swc1  $f0, 0x188($t6)
  lw    $t4, ($v1)
  swc1  $f12, 0x18c($t4)
  lw    $t5, ($v1)
  swc1  $f12, 0x190($t5)
  lw    $t9, ($v1)
  swc1  $f0, 0x194($t9)
  lw    $t8, ($v1)
  swc1  $f0, 0x198($t8)
  lw    $t3, ($v1)
  swc1  $f0, 0x19c($t3)
  lw    $t7, ($v1)
  sw    $zero, 0x1a0($t7)
  lw    $t6, ($v1)
  sw    $zero, 0x1c0($t6)
  lw    $t4, ($v1)
  sw    $zero, 0x1c4($t4)
  lw    $t5, ($v1)
  sw    $zero, 0x1c8($t5)
  lw    $t9, ($v1)
  sw    $t0, 0x1cc($t9)
  lw    $t8, ($v1)
  sw    $zero, 0x1d0($t8)
  lw    $t3, ($v1)
  swc1  $f0, 0x1d4($t3)
  lw    $t7, ($v1)
  swc1  $f0, 0x1d8($t7)
  lw    $t6, ($v1)
  swc1  $f8, 0x1dc($t6)
  lw    $t4, ($v1)
  swc1  $f0, 0x1e0($t4)
  lw    $t5, ($v1)
  swc1  $f2, 0x1e4($t5)
  lw    $t9, ($v1)
  swc1  $f0, 0x1e8($t9)
  lw    $t8, ($v1)
  swc1  $f0, 0x1ec($t8)
  lw    $t3, ($v1)
  swc1  $f0, 0x1f0($t3)
  lw    $t7, ($v1)
  swc1  $f2, 0x1f4($t7)
  lw    $t6, ($v1)
  sw    $zero, 0x200($t6)
  lw    $t4, ($v1)
  swc1  $f0, 0x204($t4)
  lw    $t5, ($v1)
  swc1  $f0, 0x208($t5)
  lw    $t9, ($v1)
  swc1  $f0, 0x20c($t9)
  lw    $t8, ($v1)
  swc1  $f0, 0x210($t8)
  lw    $t3, ($v1)
  swc1  $f0, 0x214($t3)
  lw    $t7, ($v1)
  sw    $zero, 0x218($t7)
  lw    $t6, ($v1)
  sw    $t0, 0x21c($t6)
  lw    $t4, ($v1)
  sw    $zero, 0x220($t4)
  lw    $t5, ($v1)
  swc1  $f0, 0x224($t5)
  lw    $t9, ($v1)
  sh    $zero, 0x3b4($t9)
  lw    $t8, ($v1)
  sh    $zero, 0x3b6($t8)
  lw    $t3, ($v1)
  swc1  $f0, 0x3b8($t3)
  lw    $t7, ($v1)
  swc1  $f0, 0x3bc($t7)
  lw    $t6, ($v1)
  lwc1  $f10, %lo(D_80057614)($at)
  swc1  $f10, 0x3c0($t6)
  lw    $t4, ($v1)
  swc1  $f0, 0x3c4($t4)
  lw    $t5, ($v1)
  swc1  $f0, 0x3c8($t5)
  lw    $t9, ($v1)
  swc1  $f2, 0x3cc($t9)
  lw    $t8, ($v1)
  sw    $v0, 0x3d0($t8)
  lw    $t3, ($v1)
  sw    $v0, 0x3d4($t3)
  lw    $t7, ($v1)
  lui   $at, %hi(D_80057618) # $at, 0x8005
  li    $a3, 32
  sw    $v0, 0x3d8($t7)
  lw    $t6, ($v1)
  li    $a2, 511
  li    $a1, 480
  swc1  $f0, 0x3dc($t6)
  lw    $t4, ($v1)
  swc1  $f12, 0x3e0($t4)
  lw    $t5, ($v1)
  swc1  $f12, 0x3e4($t5)
  lw    $t9, ($v1)
  sw    $v0, 0x3e8($t9)
  lw    $t8, ($v1)
  sw    $v0, 0x3ec($t8)
  lw    $t3, ($v1)
  sw    $v0, 0x3f0($t3)
  lw    $t7, ($v1)
  sw    $v0, 0x3f4($t7)
  lw    $t6, ($v1)
  sw    $v0, 0x3f8($t6)
  lw    $t4, ($v1)
  sw    $v0, 0x3fc($t4)
  lw    $t5, ($v1)
  move  $v0, $zero
  swc1  $f0, 0x400($t5)
  lw    $t9, ($v1)
  swc1  $f0, 0x404($t9)
  lw    $t8, ($v1)
  sw    $zero, 0x41c($t8)
  lw    $t3, ($v1)
  sw    $t0, 0x420($t3)
  lw    $t7, ($v1)
  sw    $zero, 0x424($t7)
  lw    $t6, ($v1)
  sw    $zero, 0x428($t6)
  lw    $t4, ($v1)
  sw    $a0, 0x42c($t4)
  lw    $t5, ($v1)
  li    $a0, 640
  sw    $zero, 0x430($t5)
  lw    $t9, ($v1)
  sw    $t0, 0x4dc($t9)
  lw    $t8, ($v1)
  sw    $t0, 0x4e0($t8)
  lw    $t3, ($v1)
  sw    $t0, 0x4e4($t3)
  lw    $t7, ($v1)
  sw    $zero, 0x4e8($t7)
  lw    $t6, ($v1)
  lwc1  $f18, %lo(D_80057618)($at)
  lui   $at, %hi(D_8005761C) # $at, 0x8005
  swc1  $f18, 0x4ec($t6)
  lw    $t4, ($v1)
  sw    $zero, 0x4f0($t4)
  lw    $t5, ($v1)
  swc1  $f2, 0x4f4($t5)
  lw    $t9, ($v1)
  swc1  $f2, 0x4f8($t9)
  lw    $t8, ($v1)
  swc1  $f0, 0x4fc($t8)
  lw    $t3, ($v1)
  swc1  $f0, 0x500($t3)
  lw    $t7, ($v1)
  swc1  $f0, 0x504($t7)
  lw    $t6, ($v1)
  lwc1  $f12, %lo(D_8005761C)($at)
  swc1  $f0, 0x508($t6)
  lw    $t4, ($v1)
  swc1  $f0, 0x50c($t4)
  lw    $t5, ($v1)
  swc1  $f2, 0x510($t5)
  lw    $t9, ($v1)
  swc1  $f0, 0x514($t9)
  lw    $t8, ($v1)
  swc1  $f2, 0x518($t8)
  lw    $t3, ($v1)
  swc1  $f0, 0x51c($t3)
  lw    $t7, ($v1)
  swc1  $f0, 0x520($t7)
  lw    $t6, ($v1)
  swc1  $f0, 0x524($t6)
  lw    $t4, ($v1)
  swc1  $f0, 0x528($t4)
  lw    $t5, ($v1)
  swc1  $f0, 0x52c($t5)
  lw    $t9, ($v1)
  swc1  $f0, 0x530($t9)
  lw    $t8, ($v1)
  swc1  $f12, 0x534($t8)
  lw    $t3, ($v1)
  swc1  $f0, 0x538($t3)
  lw    $t7, ($v1)
  swc1  $f12, 0x53c($t7)
  lw    $t6, ($v1)
  swc1  $f0, 0x540($t6)
  lw    $t4, ($v1)
  swc1  $f0, 0x544($t4)
  lw    $t5, ($v1)
  swc1  $f0, 0x548($t5)
  lw    $t9, ($v1)
  swc1  $f0, 0x54c($t9)
  lw    $t8, ($v1)
  swc1  $f0, 0x550($t8)
  lw    $t3, ($v1)
  swc1  $f0, 0x554($t3)
  lw    $t7, ($v1)
  swc1  $f0, 0x558($t7)
  lw    $t6, ($v1)
  swc1  $f0, 0x55c($t6)
  lw    $t4, ($v1)
  swc1  $f0, 0x560($t4)
  lw    $t5, ($v1)
  swc1  $f0, 0x564($t5)
  lw    $t9, ($v1)
  swc1  $f0, 0x568($t9)
  lw    $t8, ($v1)
  swc1  $f2, 0x56c($t8)
  lw    $t3, ($v1)
  swc1  $f0, 0x570($t3)
  lw    $t7, ($v1)
  swc1  $f0, 0x574($t7)
  lw    $t6, ($v1)
  swc1  $f2, 0x578($t6)
  lw    $t4, ($v1)
  swc1  $f0, 0x57c($t4)
  lw    $t5, ($v1)
  swc1  $f2, 0x580($t5)
  lw    $t9, ($v1)
  swc1  $f0, 0x584($t9)
  lw    $t8, ($v1)
  swc1  $f0, 0x588($t8)
  lw    $t3, ($v1)
  swc1  $f2, 0x58c($t3)
  lw    $t7, ($v1)
  swc1  $f0, 0x590($t7)
  lw    $t6, ($v1)
  sw    $zero, 0x594($t6)
.L7F09B738:
  lw    $t4, ($v1)
  addu  $t5, $t4, $v0
  sh    $a0, 0x7d0($t5)
  lw    $t9, ($v1)
  addu  $t8, $t9, $v0
  sh    $a1, 0x7d2($t8)
  lw    $t3, ($v1)
  addu  $t7, $t3, $v0
  sh    $a2, 0x7d4($t7)
  lw    $t6, ($v1)
  addu  $t4, $t6, $v0
  sh    $zero, 0x7d6($t4)
  lw    $t5, ($v1)
  addu  $t9, $t5, $v0
  sh    $a0, 0x7d8($t9)
  lw    $t8, ($v1)
  addu  $t3, $t8, $v0
  sh    $a1, 0x7da($t3)
  lw    $t7, ($v1)
  addu  $t6, $t7, $v0
  sh    $a2, 0x7dc($t6)
  lw    $t4, ($v1)
  addu  $t5, $t4, $v0
  addiu $v0, $v0, 0x10
  bne   $v0, $a3, .L7F09B738
   sh    $zero, 0x7de($t5)
  lw    $t9, ($v1)
  li    $v0, 100
  sh    $v0, 0x7f0($t9)
  lw    $t8, ($v1)
  sh    $v0, 0x7f2($t8)
  lw    $t3, ($v1)
  sh    $zero, 0x7f4($t3)
  lw    $t7, ($v1)
  sh    $zero, 0x7f6($t7)
  lw    $t6, ($v1)
  sw    $zero, 0x7f8($t6)
  lw    $t4, ($v1)
  sw    $zero, 0x7fc($t4)
  lw    $t5, ($v1)
  sw    $zero, 0x800($t5)
  lw    $t9, ($v1)
  sw    $zero, 0x804($t9)
  lw    $t8, ($v1)
  sw    $t1, 0x2a44($t8)
  lw    $t3, ($v1)
  move  $t8, $t2
  sw    $t1, 0x2a48($t3)
  lw    $t7, ($v1)
  addiu $t3, $t2, 0x3a8
  sw    $zero, 0x2a50($t7)
  lw    $t6, ($v1)
  move  $t7, $t2
  sw    $zero, 0x2a54($t6)
  lw    $t4, ($v1)
  sw    $zero, 0x808($t4)
  lw    $t5, ($v1)
  sw    $zero, 0x80c($t5)
  lw    $t9, ($v1)
.L7F09B824:
  lw    $at, ($t7)
  addiu $t7, $t7, 0xc
  addiu $t9, $t9, 0xc
  sw    $at, 0x864($t9)
  lw    $at, -8($t7)
  sw    $at, 0x868($t9)
  lw    $at, -4($t7)
  bne   $t7, $t3, .L7F09B824
   sw    $at, 0x86c($t9)
  lw    $t6, ($v1)
  addiu $t5, $t2, 0x3a8
.L7F09B850:
  lw    $at, ($t8)
  addiu $t8, $t8, 0xc
  addiu $t6, $t6, 0xc
  sw    $at, 0xc0c($t6)
  lw    $at, -8($t8)
  sw    $at, 0xc10($t6)
  lw    $at, -4($t8)
  bne   $t8, $t5, .L7F09B850
   sw    $at, 0xc14($t6)
  lw    $t3, ($v1)
  lui   $at, %hi(D_80057620) # $at, 0x8005
  li    $v0, 255
  swc1  $f2, 0xfc0($t3)
  lw    $t7, ($v1)
  li    $a0, 7
  swc1  $f2, 0xfc4($t7)
  lw    $t9, ($v1)
  sw    $zero, 0xfc8($t9)
  lw    $t4, ($v1)
  sw    $zero, 0xfcc($t4)
  lw    $t5, ($v1)
  lwc1  $f12, %lo(D_80057620)($at)
  li    $at, 0x42700000 # 60.000000
  sw    $zero, 0xfd0($t5)
  lw    $t8, ($v1)
  sw    $zero, 0xfd4($t8)
  lw    $t6, ($v1)
  sw    $zero, 0xfd8($t6)
  lw    $t3, ($v1)
  sb    $v0, 0xfdc($t3)
  lw    $t7, ($v1)
  sb    $v0, 0xfdd($t7)
  lw    $t9, ($v1)
  sb    $v0, 0xfde($t9)
  lw    $t4, ($v1)
  lui   $v0, %hi(random_byte) # $v0, 0x8008
  addiu $v0, %lo(random_byte) # addiu $v0, $v0, -0x5ed4
  sb    $zero, 0xfdf($t4)
  lw    $t5, ($v1)
  sw    $t0, 0xfe0($t5)
  lw    $t8, ($v1)
  sw    $zero, 0xfe4($t8)
  lw    $t6, ($v1)
  swc1  $f0, 0xfe8($t6)
  lw    $t3, ($v1)
  swc1  $f0, 0xfec($t3)
  lw    $t7, ($v1)
  swc1  $f0, 0xff0($t7)
  lw    $t9, ($v1)
  swc1  $f0, 0xff4($t9)
  lw    $t4, ($v1)
  swc1  $f12, 0xff8($t4)
  lw    $t5, ($v1)
  swc1  $f0, 0xffc($t5)
  lw    $t8, ($v1)
  swc1  $f0, 0x1000($t8)
  lw    $t6, ($v1)
  swc1  $f0, 0x1004($t6)
  lw    $t3, ($v1)
  swc1  $f0, 0x1008($t3)
  lw    $t7, ($v1)
  swc1  $f12, 0x100c($t7)
  mtc1  $at, $f12
  lw    $t9, ($v1)
  li    $at, 0x43A00000 # 320.000000
  mtc1  $at, $f14
  li    $at, 0x43700000 # 240.000000
  mtc1  $at, $f16
  swc1  $f0, 0x1010($t9)
  lui   $at, %hi(D_80057624) # $at, 0x8005
  lwc1  $f4, %lo(D_80057624)($at)
  lw    $t4, ($v1)
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f6
  swc1  $f4, 0x1014($t4)
  lw    $t5, ($v1)
  li    $at, 0x42380000 # 46.000000
  mtc1  $at, $f8
  swc1  $f0, 0x1018($t5)
  lw    $t8, ($v1)
  li    $at, 0x43200000 # 160.000000
  mtc1  $at, $f10
  sw    $zero, 0x105c($t8)
  lw    $t6, ($v1)
  li    $at, 0x42F00000 # 120.000000
  mtc1  $at, $f18
  sw    $zero, 0x1060($t6)
  lw    $t3, ($v1)
  lui   $at, %hi(D_80057628) # $at, 0x8005
  sw    $zero, 0x1064($t3)
  lw    $t7, ($v1)
  swc1  $f0, 0x106c($t7)
  lw    $t9, ($v1)
  swc1  $f0, 0x1070($t9)
  lw    $t4, ($v1)
  swc1  $f0, 0x1074($t4)
  lw    $t5, ($v1)
  sw    $zero, 0x1078($t5)
  lw    $t8, ($v1)
  swc1  $f0, 0x107c($t8)
  lw    $t6, ($v1)
  swc1  $f0, 0x1080($t6)
  lw    $t3, ($v1)
  swc1  $f12, 0x1084($t3)
  lw    $t7, ($v1)
  swc1  $f12, 0x1088($t7)
  lw    $t9, ($v1)
  sw    $t1, 0x108c($t9)
  lw    $t4, ($v1)
  swc1  $f14, 0x1090($t4)
  lw    $t5, ($v1)
  swc1  $f16, 0x1094($t5)
  lw    $t8, ($v1)
  swc1  $f0, 0x1098($t8)
  lw    $t6, ($v1)
  swc1  $f0, 0x109c($t6)
  lw    $t3, ($v1)
  swc1  $f6, 0x10a0($t3)
  lw    $t7, ($v1)
  swc1  $f8, 0x10a4($t7)
  lw    $t9, ($v1)
  swc1  $f2, 0x10a8($t9)
  lw    $t4, ($v1)
  swc1  $f10, 0x10ac($t4)
  lw    $t5, ($v1)
  swc1  $f18, 0x10b0($t5)
  lw    $t8, ($v1)
  swc1  $f2, 0x10b4($t8)
  lw    $t6, ($v1)
  swc1  $f2, 0x10b8($t6)
  lw    $t3, ($v1)
  swc1  $f2, 0x10bc($t3)
  lw    $t7, ($v1)
  swc1  $f2, 0x10c0($t7)
  lw    $t9, ($v1)
  sw    $zero, 0x10c4($t9)
  lw    $t4, ($v1)
  sw    $zero, 0x10c8($t4)
  lw    $t5, ($v1)
  sw    $zero, 0x10cc($t5)
  lw    $t8, ($v1)
  sw    $zero, 0x10d0($t8)
  lw    $t6, ($v1)
  sw    $zero, 0x10d4($t6)
  lw    $t3, ($v1)
  sw    $zero, 0x10d8($t3)
  lw    $t7, ($v1)
  sw    $zero, 0x10dc($t7)
  lw    $t9, ($v1)
  sw    $zero, 0x10e0($t9)
  lw    $t4, ($v1)
  lui   $t9, 1
  sw    $zero, 0x10e4($t4)
  lw    $t5, ($v1)
  sw    $zero, 0x10e8($t5)
  lw    $t8, ($v1)
  sw    $zero, 0x10ec($t8)
  lw    $t6, ($v1)
  swc1  $f2, 0x10f0($t6)
  lw    $t3, ($v1)
  swc1  $f2, 0x10f4($t3)
  lw    $t7, ($v1)
  swc1  $f2, 0x10f8($t7)
  lw    $t4, ($v1)
  sw    $t9, 0x10fc($t4)
  lw    $t5, ($v1)
  swc1  $f0, 0x1118($t5)
  lw    $t8, ($v1)
  swc1  $f0, 0x111c($t8)
  lw    $t6, ($v1)
  swc1  $f14, 0x1120($t6)
  lw    $t3, ($v1)
  swc1  $f16, 0x1124($t3)
  lw    $t7, ($v1)
  sw    $zero, 0x1128($t7)
  lw    $t9, ($v1)
  sw    $zero, 0x11b0($t9)
  lw    $t4, ($v1)
  sw    $zero, 0x11b4($t4)
  lw    $t5, ($v1)
  sw    $zero, 0x11b8($t5)
  lw    $t8, ($v1)
  swc1  $f0, 0x11bc($t8)
  lw    $t6, ($v1)
  swc1  $f0, 0x11c0($t6)
  lw    $t3, ($v1)
  swc1  $f12, 0x11c4($t3)
  lw    $t7, ($v1)
  swc1  $f12, 0x11c8($t7)
  lw    $t9, ($v1)
  swc1  $f12, 0x11cc($t9)
  lw    $t4, ($v1)
  swc1  $f12, 0x11d0($t4)
  lw    $t5, ($v1)
  lwc1  $f4, %lo(D_80057628)($at)
  lui   $at, %hi(invisible_to_guards_flag) # $at, 0x8003
  swc1  $f4, 0x11d4($t5)
  lw    $t8, ($v1)
  sw    $zero, 0x11d8($t8)
  lw    $t6, ($v1)
  sw    $t1, 0x11dc($t6)
  lw    $t3, ($v1)
  sw    $zero, 0x11e0($t3)
  lw    $t7, ($v1)
  sw    $zero, 0x11e4($t7)
  lw    $t9, ($v1)
  sw    $zero, 0x11e8($t9)
  lw    $t4, ($v1)
  sw    $zero, 0x11ec($t4)
  lw    $t5, ($v1)
  sw    $zero, 0x11f0($t5)
  lw    $t8, ($v1)
  sw    $zero, 0x11f4($t8)
  lw    $t6, ($v1)
  swc1  $f0, 0x1280($t6)
  lw    $t3, ($v1)
  sw    $zero, 0x1284($t3)
  lw    $t7, ($v1)
  swc1  $f0, 0x1288($t7)
  lw    $t9, ($v1)
  sb    $zero, 0x12b6($t9)
  lw    $t4, ($v1)
  sw    $a0, 0x29b8($t4)
  lw    $t5, ($v1)
  swc1  $f2, 0x29bc($t5)
  lw    $t8, ($v1)
  swc1  $f0, 0x29c0($t8)
  lw    $t6, ($v1)
  sw    $zero, 0x29c4($t6)
  lw    $t3, ($v1)
  sw    $a0, 0x29d4($t3)
  lw    $t7, ($v1)
  sw    $zero, 0x29d8($t7)
  lw    $t4, ($v1)
  lw    $t9, ($v0)
  sw    $t9, 0x29e0($t4)
  lw    $t5, ($v0)
  lw    $t6, ($v1)
  addiu $t8, $t5, 1
  sw    $t8, ($v0)
  sw    $t1, 0x29e4($t6)
  lw    $t3, ($v1)
  sw    $t1, 0x29e8($t3)
  lw    $t7, ($v1)
  sw    $t1, 0x29ec($t7)
  lw    $t9, ($v1)
  sw    $t1, 0x29f0($t9)
  lw    $t4, ($v1)
  sw    $zero, 0x2a00($t4)
  lw    $t5, ($v1)
  sw    $zero, 0x2a30($t5)
  lw    $t8, ($v1)
  sw    $zero, 0x2a34($t8)
  lw    $t6, ($v1)
  sw    $t0, 0x2a38($t6)
  lw    $t3, ($v1)
  swc1  $f2, 0x2a3c($t3)
  lw    $t7, ($v1)
  swc1  $f2, 0x2a40($t7)
  lw    $t9, ($v1)
  sw    $zero, 0x2a58($t9)
  lw    $t4, ($v1)
  sw    $zero, 0x2a5c($t4)
  lw    $t5, ($v1)
  swc1  $f0, 0x2a60($t5)
  lw    $t8, ($v1)
  sw    $zero, 0x2a64($t8)
  lw    $t6, ($v1)
  sw    $t0, 0x2a68($t6)
  lw    $t3, ($v1)
  sw    $zero, 0x2a6c($t3)
  lw    $t7, ($v1)
  sw    $zero, 0x2a70($t7)
  lw    $ra, 0x14($sp)
  sw    $t0, %lo(invisible_to_guards_flag)($at)
  lui   $at, %hi(obj_collision_flag) # $at, 0x8003
  sw    $t0, %lo(obj_collision_flag)($at)
  jr    $ra
   addiu $sp, $sp, 0x3d0  
");
#endif

asm(R"
glabel set_cur_player
  sll   $t6, $a0, 2
  lui   $t7, %hi(players_p1)
  addu  $t7, $t7, $t6
  lw    $t7, %lo(players_p1)($t7)
  lui   $at, %hi(player_num)
  sw    $a0, %lo(player_num)($at)
  sll   $t8, $a0, 3
  lui   $at, %hi(pPlayer)
  subu  $t8, $t8, $a0
  lui   $t9, %hi(player1_player_data) 
  addiu $t9, %lo(player1_player_data) # addiu $t9, $t9, -0x6110
  sll   $t8, $t8, 4
  sw    $t7, %lo(pPlayer)($at)
  lui   $at, %hi(pPlayersPerm)
  addu  $t0, $t8, $t9
  jr    $ra
   sw    $t0, %lo(pPlayersPerm)($at)
");

int get_cur_playernum(void) { return player_num; }

asm(R"
glabel sub_GAME_7F09B15C
  addiu $sp, $sp, -0x28
  sw    $ra, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  move  $s2, $a0
  sw    $s0, 0x18($sp)
  jal   getPlayerCount
   move  $s1, $zero
  blez  $v0, .L7F09B1C0
   sll   $t6, $s1, 2
  lui   $t7, %hi(players_p1) 
  addiu $t7, %lo(players_p1) # addiu $t7, $t7, -0x6120
  addu  $s0, $t6, $t7
  lw    $t8, ($s0)
.L7F09B194:
  addiu $s0, $s0, 4
  lw    $t9, 0xa8($t8)
  bne   $s2, $t9, .L7F09B1AC
   nop   
  b     .L7F09B1C4
   move  $v0, $s1
.L7F09B1AC:
  jal   getPlayerCount
   addiu $s1, $s1, 1
  slt   $at, $s1, $v0
  bnezl $at, .L7F09B194
   lw    $t8, ($s0)
.L7F09B1C0:
  li    $v0, -1
.L7F09B1C4:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

void set_cur_player_screen_size(unsigned int width, unsigned int height) {
  pPlayer->viewx = width;
  pPlayer->viewy = height;
}

void set_cur_player_viewport_size(unsigned int ulx, unsigned int uly) {
  pPlayer->viewleft = ulx;
  pPlayer->viewtop = uly;
}

void set_cur_player_fovy(float fovy) { pPlayer->fovy = fovy; }

void set_cur_player_aspect(float aspect) { pPlayer->aspect = aspect; }

float get_cur_player_fovy(void) { return pPlayer->fovy; }

asm(R"
.late_rodata
glabel jpt_weapon_multi
.word weapon_multi_none
.word weapon_multi_none
.word weapon_multi_hunting_knife
.word weapon_multi_throwing_knife
.word weapon_multi_pp7
.word weapon_multi_pp7_silent
.word weapon_multi_dd44
.word weapon_multi_klobb
.word weapon_multi_kf7
.word weapon_multi_zmg
.word weapon_multi_d5k
.word weapon_multi_d5k_silent
.word weapon_multi_phantom
.word weapon_multi_ar33
.word weapon_multi_rcp90
.word weapon_multi_shotgun
.word weapon_multi_auto_shot
.word weapon_multi_sniper
.word weapon_multi_cougar
.word weapon_multi_goldengun
.word weapon_multi_pp7_special1
.word weapon_multi_pp7_special2
.word weapon_multi_moonraker

.text
glabel sub_GAME_7F09B244
  slti  $at, $a0, 0x20
  bnez  $at, .L7F09B264
   li    $v1, -1
  li    $at, 88
  beql  $a0, $at, .L7F09B360
   li    $v1, 333
  jr    $ra
   move  $v0, $v1

.L7F09B264:
  sltiu $at, $a0, 0x20
  beqz  $at, .L7F09B360
   sll   $t6, $a0, 2
  lui   $at, %hi(jpt_weapon_multi)
  addu  $at, $at, $t6
  lw    $t6, %lo(jpt_weapon_multi)($at)
  jr    $t6
   nop   
weapon_multi_hunting_knife:
  jr    $ra
   li    $v0, 186

weapon_multi_pp7:
  jr    $ra
   li    $v0, 191

weapon_multi_klobb:
  jr    $ra
   li    $v0, 193

weapon_multi_kf7:
  jr    $ra
   li    $v0, 184

weapon_multi_zmg:
  jr    $ra
   li    $v0, 195

weapon_multi_d5k:
  jr    $ra
   li    $v0, 189

weapon_multi_phantom:
  jr    $ra
   li    $v0, 194

weapon_multi_ar33:
  jr    $ra
   li    $v0, 188

weapon_multi_rcp90:
  jr    $ra
   li    $v0, 197

weapon_multi_shotgun:
  jr    $ra
   li    $v0, 192

weapon_multi_grenade_laun:
  jr    $ra
   li    $v0, 185

weapon_multi_hand:
  jr    $ra
   li    $v0, 196

weapon_multi_remote:
  jr    $ra
   li    $v0, 199

weapon_multi_prox:
  jr    $ra
   li    $v0, 200

weapon_multi_timed:
  jr    $ra
   li    $v0, 201

weapon_multi_cougar:
  jr    $ra
   li    $v0, 190

weapon_multi_moonraker:
  jr    $ra
   li    $v0, 187

weapon_multi_sniper:
  jr    $ra
   li    $v0, 210

weapon_multi_d5k_silent:
  jr    $ra
   li    $v0, 206

weapon_multi_dd44:
  jr    $ra
   li    $v0, 205

weapon_multi_pp7_silent:
  jr    $ra
   li    $v0, 204

weapon_multi_throwing_knife:
  jr    $ra
   li    $v0, 209

weapon_multi_auto_shot:
  jr    $ra
   li    $v0, 207

weapon_multi_rocket_launch:
  jr    $ra
   li    $v0, 211

weapon_multi_goldengun:
  jr    $ra
   li    $v0, 208

weapon_multi_pp7_special1:
  jr    $ra
   li    $v0, 191

weapon_multi_pp7_special2:
  jr    $ra
   li    $v0, 191

  li    $v1, 333
weapon_multi_none:
.L7F09B360:
  jr    $ra
   move  $v0, $v1
");

asm(R"
.late_rodata
.word weapon_multi_none
.word weapon_multi_grenade_laun
.word weapon_multi_rocket_launch

.text
glabel sub_GAME_7F09B368
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lw    $t7, 0xa8($t6)
  move  $a1, $a0
  jal   set_0x4_in_runtime_flags_for_item_in_guards_hand
   lw    $a0, 4($t7)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
.late_rodata
.word weapon_multi_hand
.word weapon_multi_timed
.word weapon_multi_prox
.word weapon_multi_remote
.word weapon_multi_none
.word weapon_multi_none

.text
glabel sub_GAME_7F09B398
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  addiu $sp, $sp, -0x38
  sw    $ra, 0x1c($sp)
  lw    $t7, 0xa8($t6)
  sll   $v1, $a0, 2
  lw    $v0, 4($t7)
  addu  $t8, $v0, $v1
  lw    $t9, 0x160($t8)
  bnezl $t9, .L7F09B410
   lw    $ra, 0x1c($sp)
  sw    $v0, 0x34($sp)
  jal   get_item_in_hand
   sw    $v1, 0x24($sp)
  sw    $v0, 0x30($sp)
  jal   sub_GAME_7F09B244
   move  $a0, $v0
  lw    $v1, 0x24($sp)
  bltz  $v0, .L7F09B40C
   move  $a1, $v0
  bnez  $v1, .L7F09B3F8
   lw    $a0, 0x34($sp)
  b     .L7F09B3FC
   move  $a3, $zero
.L7F09B3F8:
  lui   $a3, 0x1000
.L7F09B3FC:
  lw    $a2, 0x30($sp)
  sw    $zero, 0x10($sp)
  jal   something_with_generating_object
   sw    $zero, 0x14($sp)
.L7F09B40C:
  lw    $ra, 0x1c($sp)
.L7F09B410:
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F09B41C
  addiu $sp, $sp, -0x30
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  lui   $s1, %hi(dword_CODE_bss_8007A0C0)
  sw    $ra, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  addiu $s1, %lo(dword_CODE_bss_8007A0C0) # addiu $s1, $s1, -0x5f40
  move  $s0, $zero
.L7F09B444:
  sw    $s0, ($s1)
  addiu $s0, $s0, 1
  slti  $at, $s0, 4
  bnez  $at, .L7F09B444
   addiu $s1, $s1, 4
  lui   $t6, %hi(dword_CODE_bss_8007A0C0)
  addiu $s2, $t6, %lo(dword_CODE_bss_8007A0C0)
  move  $s1, $s2
  move  $s0, $zero
  li    $s4, 3
  li    $s3, 4
.L7F09B470:
  jal   get_random_value
   nop   
  subu  $t7, $s3, $s0
  divu  $zero, $v0, $t7
  mfhi  $t8
  sll   $t9, $t8, 2
  addu  $v1, $s2, $t9
  lw    $t0, ($v1)
  lw    $a0, ($s1)
  addiu $s0, $s0, 1
  bnez  $t7, .L7F09B4A4
   nop   
  break 7
.L7F09B4A4:
  sw    $t0, ($s1)
  addiu $s2, $s2, 4
  addiu $s1, $s1, 4
  bne   $s0, $s4, .L7F09B470
   sw    $a0, ($v1)
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  lw    $s3, 0x24($sp)
  lw    $s4, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x30
");

asm(R"
glabel sub_GAME_7F09B4D8
  lui   $a1, %hi(dword_CODE_bss_8007A0C0)
  lui   $a3, %hi(dword_CODE_bss_8007A0D0)
  lui   $a2, %hi(players_p1)
  move  $v1, $zero
  addiu $a2, %lo(players_p1) # addiu $a2, $a2, -0x6120
  addiu $a3, %lo(dword_CODE_bss_8007A0D0) # addiu $a3, $a3, -0x5f30
  addiu $a1, %lo(dword_CODE_bss_8007A0C0) # addiu $a1, $a1, -0x5f40
  lw    $v0, ($a1)
.L7F09B4F8:
  addiu $a1, $a1, 4
  beq   $a0, $v0, .L7F09B520
   sll   $t6, $v0, 2
  addu  $t7, $a2, $t6
  lw    $t8, ($t7)
  beqz  $t8, .L7F09B518
   nop   
  addiu $v1, $v1, 1
.L7F09B518:
  bnel  $a1, $a3, .L7F09B4F8
   lw    $v0, ($a1)
.L7F09B520:
  jr    $ra
   move  $v0, $v1
");

int sub_GAME_7F09B528(int param_1) {
  if ((&players_p1)[dword_CODE_bss_8007A0C0] != 0) {
    if (param_1 == 0) {
      return dword_CODE_bss_8007A0C0;
    }
    param_1 = param_1 + -1;
  }
  if ((&players_p1)[dword_CODE_bss_8007A0C4] != 0) {
    if (param_1 == 0) {
      return dword_CODE_bss_8007A0C4;
    }
    param_1 = param_1 + -1;
  }
  if ((&players_p1)[dword_CODE_bss_8007A0C8] != 0) {
    if (param_1 == 0) {
      return dword_CODE_bss_8007A0C8;
    }
    param_1 = param_1 + -1;
  }
  if (((&players_p1)[dword_CODE_bss_8007A0CC] != 0) && (param_1 == 0)) {
    return dword_CODE_bss_8007A0CC;
  }
  return 0;
}
