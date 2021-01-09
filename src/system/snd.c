// This file contains code to play sound effects (sfx).
#include "music.h"

int sfx_unused = 0;
int D_800243E4 = 0;
int D_800243E8 = 0;
int D_800243EC = 0;
void *D_800243F0 = &D_80063B50;
int D_800243F4 = 0;
char bootswitch_sound = 0;
float F32_800243FC = 1.0;

asm(R"
glabel sfx_c_70007B20
  addiu $sp, $sp, -0x50
  sw    $s2, 0x28($sp)
  lui   $s2, %hi(D_800243F0)
  addiu $s2, %lo(D_800243F0) # addiu $s2, $s2, 0x43f0
  sw    $ra, 0x2c($sp)
  sw    $s1, 0x24($sp)
  sw    $s0, 0x20($sp)
  lw    $t6, 8($a0)
  lw    $t7, ($s2)
  li    $t9, 33000
  move  $s1, $a0
  sw    $t6, 0x44($t7)
  lw    $t8, ($s2)
  move  $a0, $zero
  move  $a1, $zero
  sw    $zero, 0x3c($t8)
  lw    $t0, ($s2)
  li    $a3, 1
  sw    $t9, 0x48($t0)
  lw    $t1, ($s1)
  lw    $a2, 0xc($s1)
  sll   $t2, $t1, 6
  jal   alHeapDBAlloc
   sw    $t2, 0x10($sp)
  lw    $t3, ($s2)
  move  $a0, $zero
  move  $a1, $zero
  sw    $v0, 0x40($t3)
  lw    $t4, 4($s1)
  lw    $a2, 0xc($s1)
  li    $a3, 1
  sll   $t5, $t4, 3
  subu  $t5, $t5, $t4
  sll   $t5, $t5, 2
  jal   alHeapDBAlloc
   sw    $t5, 0x10($sp)
  lw    $a0, ($s2)
  move  $a1, $v0
  lw    $a2, 4($s1)
  jal   alEvtqNew
   addiu $a0, $a0, 0x14
  lw    $t6, ($s2)
  lui   $at, %hi(D_800243EC)
  li    $s0, 1
  lw    $t7, 0x40($t6)
  sw    $t7, %lo(D_800243EC)($at)
  lw    $t8, ($s1)
  sltiu $at, $t8, 2
  bnezl $at, .L70007C18
   lw    $a2, 0xc($s1)
  lw    $t9, ($s2)
.L70007BEC:
  sll   $t0, $s0, 6
  lw    $v0, 0x40($t9)
  addu  $a0, $t0, $v0
  jal   alLink
   addiu $a1, $a0, -0x40
  lw    $t1, ($s1)
  addiu $s0, $s0, 1
  sltu  $at, $s0, $t1
  bnezl $at, .L70007BEC
   lw    $t9, ($s2)
  lw    $a2, 0xc($s1)
.L70007C18:
  li    $t2, 7
  sw    $t2, 0x10($sp)
  move  $a0, $zero
  move  $a1, $zero
  jal   alHeapDBAlloc
   li    $a3, 2
  lui   $v1, %hi(D_80063BA4)
  addiu $v1, %lo(D_80063BA4) # addiu $v1, $v1, 0x3ba4
  sw    $v0, ($v1)
  lw    $a2, 0xc($s1)
  li    $t3, 7
  sw    $t3, 0x10($sp)
  move  $a0, $zero
  move  $a1, $zero
  jal   alHeapDBAlloc
   li    $a3, 2
  lui   $v1, %hi(D_80063BA4)
  addiu $v1, %lo(D_80063BA4) # addiu $v1, $v1, 0x3ba4
  lw    $t4, ($v1)
  lui   $a0, %hi(D_80063BA8)
  addiu $a0, %lo(D_80063BA8) # addiu $a0, $a0, 0x3ba8
  sw    $v0, ($a0)
  li    $a1, 32767
  sh    $a1, ($t4)
  lw    $t5, ($v1)
  lw    $t7, ($a0)
  li    $s0, 3
  lh    $t6, ($t5)
  sll   $v0, $s0, 1
  sh    $t6, ($t7)
  lw    $t8, ($v1)
  sh    $a1, 2($t8)
  lw    $t9, ($v1)
  lw    $t1, ($a0)
  lh    $t0, 2($t9)
  sh    $t0, 2($t1)
  lw    $t2, ($v1)
  sh    $a1, 4($t2)
  lw    $t3, ($v1)
  lw    $t5, ($a0)
  lh    $t4, 4($t3)
  sh    $t4, 4($t5)
  lw    $t6, ($v1)
  addu  $t7, $t6, $v0
  sh    $a1, ($t7)
  lw    $t8, ($v1)
  lw    $t1, ($a0)
  addu  $t9, $t8, $v0
  lh    $t0, ($t9)
  addu  $t2, $t1, $v0
  sh    $t0, ($t2)
  lw    $t3, ($v1)
  addu  $t4, $t3, $v0
  sh    $a1, 2($t4)
  lw    $t5, ($v1)
  lw    $t8, ($a0)
  addu  $t6, $t5, $v0
  lh    $t7, 2($t6)
  addu  $t9, $t8, $v0
  sh    $t7, 2($t9)
  lw    $t1, ($v1)
  addu  $t0, $t1, $v0
  sh    $a1, 4($t0)
  lw    $t2, ($v1)
  lw    $t5, ($a0)
  addu  $t3, $t2, $v0
  lh    $t4, 4($t3)
  addu  $t6, $t5, $v0
  lui   $t5, %hi(alGlobals) 
  sh    $t4, 4($t6)
  lw    $t8, ($v1)
  addu  $t7, $t8, $v0
  sh    $a1, 6($t7)
  lw    $t9, ($v1)
  lw    $t2, ($a0)
  lui   $t8, %hi(sfx_c_70007DDC) # $t8, 0x7000
  addu  $t1, $t9, $v0
  lh    $t0, 6($t1)
  addu  $t3, $t2, $v0
  addiu $t8, %lo(sfx_c_70007DDC) # addiu $t8, $t8, 0x7ddc
  sh    $t0, 6($t3)
  lw    $t4, ($s2)
  lw    $t5, %lo(alGlobals)($t5)
  sw    $t5, 0x38($t4)
  lw    $t6, ($s2)
  sw    $zero, ($t6)
  lw    $t7, ($s2)
  sw    $t8, 8($t7)
  lw    $s0, ($s2)
  sw    $s0, 4($s0)
  lw    $s0, ($s2)
  lw    $a0, 0x38($s0)
  jal   alSynAddPlayer
   move  $a1, $s0
  lw    $s0, ($s2)
  li    $t9, 32
  sh    $t9, 0x38($sp)
  addiu $a1, $sp, 0x38
  lw    $a2, 0x48($s0)
  jal   alEvtqPostEvent
   addiu $a0, $s0, 0x14
  lw    $s0, ($s2)
  addiu $a0, $s0, 0x14
  jal   alEvtqNextEvent
   addiu $a1, $s0, 0x28
  lw    $t1, ($s2)
  sw    $v0, 0x4c($t1)
  lw    $ra, 0x2c($sp)
  lw    $s2, 0x28($sp)
  lw    $s1, 0x24($sp)
  lw    $s0, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x50
");

asm(R"
glabel sfx_c_70007DDC
  addiu $sp, $sp, -0x50
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  move  $s0, $a0
  sw    $ra, 0x2c($sp)
  addiu $s1, $a0, 0x28
  addiu $s2, $a0, 0x14
  li    $s3, 32
  addiu $s4, $sp, 0x3c
.L70007E0C:
  lh    $t6, 0x28($s0)
  li    $t7, 32
  move  $a1, $s4
  bne   $s3, $t6, .L70007E38
   move  $a0, $s0
  sh    $t7, 0x3c($sp)
  lw    $a2, 0x48($s0)
  jal   alEvtqPostEvent
   move  $a0, $s2
  b     .L70007E44
   move  $a0, $s2
.L70007E38:
  jal   sfx_c_70007E80
   move  $a1, $s1
  move  $a0, $s2
.L70007E44:
  jal   alEvtqNextEvent
   move  $a1, $s1
  beqz  $v0, .L70007E0C
   sw    $v0, 0x4c($s0)
  lw    $t8, 0x50($s0)
  addu  $t9, $t8, $v0
  sw    $t9, 0x50($s0)
  lw    $ra, 0x2c($sp)
  lw    $s4, 0x28($sp)
  lw    $s3, 0x24($sp)
  lw    $s2, 0x20($sp)
  lw    $s1, 0x1c($sp)
  lw    $s0, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x50
");

/**
 *     accepts: A0=???, A1=???
 *     uses TLB pointer table at 80029160
 *     70007FBC	entry 0
 *     70008388	entry 1
 *     7000847C	entry 3
 *     700084F0	entry F
 *     700085C8	entry 7
 *     700088D4	default: entries 2,4,5,6,8,9,A,B,C,D,E
 */
asm(R"
glabel sfx_c_70007E80
  addiu $sp, $sp, -0xd0
  sw    $fp, 0x38($sp)
  sw    $s7, 0x34($sp)
  sw    $s5, 0x2c($sp)
  sw    $s1, 0x1c($sp)
  li    $t6, 1
  move  $s5, $a1
  move  $s7, $a0
  sw    $ra, 0x3c($sp)
  sw    $s6, 0x30($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s0, 0x18($sp)
  sw    $t6, 0x80($sp)
  sw    $zero, 0x7c($sp)
  sw    $zero, 0x74($sp)
  lw    $s1, 0x78($sp)
  li    $fp, 1
  lw    $t7, 0x74($sp)
.L70007ED0:
  beql  $t7, $zero, .L70007EF4
   lw    $s1, 4($s5)
  sw    $s1, 0xa0($sp)
  lhu   $t8, ($s5)
  sh    $t8, 0x9c($sp)
  lw    $t9, 8($s5)
  addiu $s5, $sp, 0x9c
  sw    $t9, 0xa4($sp)
  lw    $s1, 4($s5)
.L70007EF4:
  lw    $s2, 8($s1)
  bnez  $s2, .L70007F10
   addiu $a0, $sp, 0x72
  jal   sfx_c_70008AF0
   addiu $a1, $sp, 0x70
  b     .L7000891C
   lw    $ra, 0x3c($sp)
.L70007F10:
  lw    $t0, ($s1)
  lw    $s6, 4($s2)
  sw    $t0, 0x74($sp)
  lhu   $v1, ($s5)
  slti  $at, $v1, 0x101
  bnez  $at, .L70007F58
   move  $v0, $v1
  li    $at, 512
  beq   $v0, $at, .L700088A8
   li    $at, 1024
  beq   $v0, $at, .L70008388
   li    $at, 2048
  beq   $v0, $at, .L70008690
   li    $at, 4096
  beql  $v0, $at, .L7000838C
   li    $at, 4096
  b     .L700088D8
   andi  $v0, $v1, 0x2d1
.L70007F58:
  slti  $at, $v0, 0x41
  bnez  $at, .L70007F7C
   li    $at, 128
  beq   $v0, $at, .L70008890
   li    $at, 256
  beql  $v0, $at, .L7000854C
   lbu   $t6, 0x3f($s1)
  b     .L700088D8
   andi  $v0, $v1, 0x2d1
.L70007F7C:
  slti  $at, $v0, 0x11
  bnez  $at, .L70007F9C
   addiu $t1, $v0, -1
  li    $at, 64
  beql  $v0, $at, .L70008770
   lbu   $t9, 0x3e($s1)
  b     .L700088D8
   andi  $v0, $v1, 0x2d1
.L70007F9C:
  sltiu $at, $t1, 0x10
  beqz  $at, .L700088D4
   sll   $t1, $t1, 2
  lui   $at, %hi(jpt_80029160)
  addu  $at, $at, $t1
  lw    $t1, %lo(jpt_80029160)($at) # lw    $t1, -0x6ea0($at)
  jr    $t1
   nop
glabel .L70007FBC
  lbu   $v0, 0x3f($s1)
  li    $at, 5
  lui   $t3, %hi(D_800243F4) 
  beq   $v0, $at, .L70007FD8
   li    $at, 4
  bnel  $v0, $at, .L7000891C
   lw    $ra, 0x3c($sp)
.L70007FD8:
  sh    $zero, 0xca($sp)
  lbu   $t2, 0x36($s1)
  sb    $zero, 0xcc($sp)
  lh    $t3, %lo(D_800243F4)($t3)
  sh    $t2, 0xc8($sp)
  lw    $t4, 0x44($s7)
  addiu $a1, $s1, 0xc
  addiu $a2, $sp, 0xc8
  slt   $s0, $t3, $t4
  xori  $s0, $s0, 1
  beqz  $s0, .L70008018
   nop   
  lbu   $v1, 0x3e($s1)
  andi  $t5, $v1, 0x10
  beql  $t5, $zero, .L7000802C
   lw    $t6, 0x7c($sp)
.L70008018:
  jal   alSynAllocVoice
   lw    $a0, 0x38($s7)
  sw    $v0, 0x7c($sp)
  lbu   $v1, 0x3e($s1)
  lw    $t6, 0x7c($sp)
.L7000802C:
  addiu $s3, $s1, 0xc
  ori   $t7, $v1, 4
  bnez  $t6, .L7000814C
   move  $a1, $s3
  andi  $t7, $v1, 0x12
  bnez  $t7, .L70008054
   li    $t9, 4
  lw    $t8, 0x38($s1)
  blez  $t8, .L7000807C
   nop   
.L70008054:
  lw    $t0, 0x38($s1)
  sb    $t9, 0x3f($s1)
  addiu $a0, $s7, 0x14
  addiu $t1, $t0, -1
  sw    $t1, 0x38($s1)
  move  $a1, $s5
  jal   alEvtqPostEvent
   li    $a2, 33333
  b     .L7000891C
   lw    $ra, 0x3c($sp)
.L7000807C:
  beqz  $s0, .L7000813C
   lui   $v0, %hi(D_800243E8)
  lw    $v0, %lo(D_800243E8)($v0)
  addiu $s4, $sp, 0x5c
  li    $s3, 3
  li    $s2, 3
  lbu   $v1, 0x3e($v0)
.L70008098:
  andi  $t2, $v1, 0x12
  bnez  $t2, .L700080F8
   andi  $t3, $v1, 4
  beqz  $t3, .L700080F8
   nop   
  lbu   $t4, 0x3f($v0)
  li    $t5, 128
  addiu $a0, $s7, 0x14
  beq   $s2, $t4, .L700080F8
   move  $a1, $s4
  sh    $t5, 0x5c($sp)
  sw    $v0, 0x60($sp)
  sb    $s3, 0x3f($v0)
  move  $s0, $zero
  sw    $v0, 0x6c($sp)
  jal   alEvtqPostEvent
   li    $a2, 1000
  lw    $v0, 0x6c($sp)
  lw    $a0, 0x38($s7)
  move  $a2, $zero
  li    $a3, 1000
  jal   alSynSetVol
   addiu $a1, $v0, 0xc
  lw    $v0, 0x6c($sp)
.L700080F8:
  beqz  $s0, .L70008108
   lw    $v0, 4($v0)
  bnezl $v0, .L70008098
   lbu   $v1, 0x3e($v0)
.L70008108:
  bnez  $s0, .L7000812C
   li    $t6, 2
  sw    $t6, 0x38($s1)
  addiu $a0, $s7, 0x14
  move  $a1, $s5
  jal   alEvtqPostEvent
   li    $a2, 1001
  b     .L7000891C
   lw    $ra, 0x3c($sp)
.L7000812C:
  jal   sfx_c_70008948
   move  $a0, $s1
  b     .L7000891C
   lw    $ra, 0x3c($sp)
.L7000813C:
  jal   sfx_c_70008948
   move  $a0, $s1
  b     .L7000891C
   lw    $ra, 0x3c($sp)
.L7000814C:
  sb    $t7, 0x3e($s1)
  lw    $a2, 8($s2)
  lw    $a0, 0x38($s7)
  jal   alSynStartVoice
   addiu $s4, $s7, 0x14
  li    $t8, 1
  sb    $t8, 0x3f($s1)
  lui   $t9, %hi(D_800243F4) 
  lh    $t9, %lo(D_800243F4)($t9)
  lui   $at, %hi(D_800243F4)
  lui   $t3, %hi(D_80063BA4) 
  addiu $t0, $t9, 1
  sh    $t0, %lo(D_800243F4)($at)
  lw    $v0, ($s2)
  lh    $t0, 0x34($s1)
  lbu   $t2, 0xd($s2)
  lbu   $t9, 0xc($v0)
  lw    $t1, ($v0)
  lbu   $t4, 2($s6)
  multu $t9, $t0
  mtc1  $t1, $f4
  andi  $t5, $t4, 0x3f
  li    $at, 16129
  lw    $t3, %lo(D_80063BA4)($t3)
  sll   $t6, $t5, 1
  cvt.s.w $f6, $f4
  addu  $t7, $t3, $t6
  lh    $t8, ($t7)
  lwc1  $f8, 0x2c($s1)
  mflo  $t1
  lwc1  $f16, 0x28($s1)
  div.s $f10, $f6, $f8
  multu $t1, $t2
  move  $a1, $s3
  move  $a2, $zero
  move  $a3, $zero
  mflo  $t4
  nop   
  nop   
  div   $zero, $t4, $at
  mflo  $t5
  li    $at, 32767
  div.s $f18, $f10, $f16
  multu $t8, $t5
  mflo  $a0
  nop   
  nop   
  div   $zero, $a0, $at
  trunc.w.s $f4, $f18
  mflo  $t3
  addiu $a0, $t3, -1
  move  $v1, $a0
  mfc1  $s0, $f4
  bgez  $a0, .L70008230
   nop   
  b     .L70008230
   move  $v1, $zero
.L70008230:
  lw    $a0, 0x38($s7)
  jal   alSynSetVol
   sw    $v1, 0x90($sp)
  lw    $v1, 0x90($sp)
  lw    $a0, 0x38($s7)
  move  $a1, $s3
  sll   $a2, $v1, 0x10
  sra   $t6, $a2, 0x10
  move  $a2, $t6
  jal   alSynSetVol
   move  $a3, $s0
  lbu   $t7, 0x3c($s1)
  lbu   $t9, 0xc($s2)
  move  $v0, $zero
  li    $a2, 127
  addu  $v1, $t7, $t9
  addiu $v1, $v1, -0x40
  blez  $v1, .L70008284
   move  $a1, $s3
  b     .L70008284
   move  $v0, $v1
.L70008284:
  slti  $at, $v0, 0x7f
  beqz  $at, .L700082A8
   nop   
  blez  $v1, .L700082A0
   move  $v0, $zero
  b     .L700082A8
   andi  $a2, $v1, 0xff
.L700082A0:
  b     .L700082A8
   andi  $a2, $v0, 0xff
.L700082A8:
  jal   alSynSetPan
   lw    $a0, 0x38($s7)
  lwc1  $f6, 0x2c($s1)
  lwc1  $f8, 0x28($s1)
  lw    $a0, 0x38($s7)
  move  $a1, $s3
  mul.s $f10, $f6, $f8
  mfc1  $a2, $f10
  jal   alSynSetPitch
   nop   
  lbu   $t1, 3($s6)
  lbu   $t0, 0x3d($s1)
  move  $a1, $s3
  andi  $t2, $t1, 0xf
  addu  $v1, $t0, $t2
  sll   $t4, $v1, 3
  bgez  $t4, .L700082F8
   move  $v1, $t4
  b     .L700082FC
   move  $v0, $zero
.L700082F8:
  move  $v0, $v1
.L700082FC:
  slti  $at, $v0, 0x80
  bnez  $at, .L70008310
   nop   
  b     .L70008324
   li    $v1, 127
.L70008310:
  bgez  $v1, .L70008320
   move  $v0, $v1
  b     .L70008320
   move  $v0, $zero
.L70008320:
  move  $v1, $v0
.L70008324:
  lw    $a0, 0x38($s7)
  jal   alSynSetFXMix
   andi  $a2, $v1, 0xff
  li    $t8, 64
  sh    $t8, 0xac($sp)
  sw    $s1, 0xb0($sp)
  lw    $t5, ($s2)
  lwc1  $f4, 0x2c($s1)
  lwc1  $f8, 0x28($s1)
  lw    $t3, ($t5)
  move  $a0, $s4
  addiu $a1, $sp, 0xac
  mtc1  $t3, $f16
  nop   
  cvt.s.w $f18, $f16
  div.s $f6, $f18, $f4
  div.s $f10, $f6, $f8
  trunc.w.s $f16, $f10
  mfc1  $a2, $f16
  jal   alEvtqPostEvent
   nop   
  lhu   $v0, ($s5)
  andi  $t7, $v0, 0x2d1
  b     .L700088D8
   move  $v0, $t7
glabel .L70008388
  li    $at, 4096
.L7000838C:
  bnel  $v1, $at, .L700083A8
   lbu   $v0, 0x3f($s1)
  lbu   $t9, 0x3e($s1)
  andi  $t1, $t9, 2
  beqz  $t1, .L70008474
   nop   
  lbu   $v0, 0x3f($s1)
.L700083A8:
  addiu $s4, $s7, 0x14
  move  $a0, $s4
  beq   $v0, $fp, .L700083D4
   move  $a1, $s1
  li    $at, 4
  beq   $v0, $at, .L70008454
   li    $at, 5
  beq   $v0, $at, .L70008454
   nop   
  b     .L70008464
   li    $at, 2
.L700083D4:
  jal   sfx_c_70008A30
   li    $a2, 64
  lw    $t0, ($s2)
  lwc1  $f6, 0x28($s1)
  lwc1  $f10, 0x2c($s1)
  lw    $t2, 8($t0)
  lw    $a0, 0x38($s7)
  addiu $a1, $s1, 0xc
  mtc1  $t2, $f18
  move  $a2, $zero
  cvt.s.w $f4, $f18
  div.s $f8, $f4, $f6
  div.s $f16, $f8, $f10
  trunc.w.s $f18, $f16
  mfc1  $s0, $f18
  jal   alSynSetVol
   move  $a3, $s0
  beqz  $s0, .L70008444
   li    $t8, 128
  sh    $t8, 0xac($sp)
  sw    $s1, 0xb0($sp)
  move  $a0, $s4
  addiu $a1, $sp, 0xac
  jal   alEvtqPostEvent
   move  $a2, $s0
  li    $t5, 2
  b     .L7000844C
   sb    $t5, 0x3f($s1)
.L70008444:
  jal   sfx_c_70008948
   move  $a0, $s1
.L7000844C:
  b     .L70008460
   lhu   $v1, ($s5)
.L70008454:
  jal   sfx_c_70008948
   move  $a0, $s1
  lhu   $v1, ($s5)
.L70008460:
  li    $at, 2
.L70008464:
  bne   $v1, $at, .L70008474
   li    $t3, 4096
  sh    $t3, ($s5)
  andi  $v1, $t3, 0xffff
.L70008474:
  b     .L700088D8
   andi  $v0, $v1, 0x2d1
glabel .L7000847C
  lbu   $t7, 0x3f($s1)
  lw    $t6, 8($s5)
  addiu $a1, $s1, 0xc
  bne   $fp, $t7, .L700084E0
   sb    $t6, 0x3c($s1)
  lbu   $t1, 0xc($s2)
  andi  $t9, $t6, 0xff
  move  $v0, $zero
  addu  $v1, $t9, $t1
  addiu $v1, $v1, -0x40
  blez  $v1, .L700084B4
   li    $a2, 127
  b     .L700084B4
   move  $v0, $v1
.L700084B4:
  slti  $at, $v0, 0x7f
  beqz  $at, .L700084D8
   nop   
  blez  $v1, .L700084D0
   move  $v0, $zero
  b     .L700084D8
   andi  $a2, $v1, 0xff
.L700084D0:
  b     .L700084D8
   andi  $a2, $v0, 0xff
.L700084D8:
  jal   alSynSetPan
   lw    $a0, 0x38($s7)
.L700084E0:
  lhu   $v0, ($s5)
  andi  $t0, $v0, 0x2d1
  b     .L700088D8
   move  $v0, $t0
glabel .L700084F0
  lbu   $t2, 0x3f($s1)
  lwc1  $f4, 8($s5)
  bne   $fp, $t2, .L70008538
   swc1  $f4, 0x2c($s1)
  lwc1  $f6, 0x2c($s1)
  lwc1  $f8, 0x28($s1)
  lw    $a0, 0x38($s7)
  addiu $a1, $s1, 0xc
  mul.s $f10, $f6, $f8
  mfc1  $a2, $f10
  jal   alSynSetPitch
   nop   
  lbu   $t4, 0x3e($s1)
  andi  $t8, $t4, 0x20
  beql  $t8, $zero, .L7000853C
   lhu   $v0, ($s5)
  jal   sfx_c_700089C4
   move  $a0, $s1
.L70008538:
  lhu   $v0, ($s5)
.L7000853C:
  andi  $t5, $v0, 0x2d1
  b     .L700088D8
   move  $v0, $t5
  lbu   $t6, 0x3f($s1)
.L7000854C:
  lw    $t3, 8($s5)
  addiu $a1, $s1, 0xc
  bne   $fp, $t6, .L700085B8
   sb    $t3, 0x3d($s1)
  lbu   $t9, 3($s6)
  andi  $t7, $t3, 0xff
  andi  $t1, $t9, 0xf
  addu  $v1, $t7, $t1
  sll   $t0, $v1, 3
  bgez  $t0, .L70008580
   move  $v1, $t0
  b     .L70008584
   move  $v0, $zero
.L70008580:
  move  $v0, $v1
.L70008584:
  slti  $at, $v0, 0x80
  bnez  $at, .L70008598
   nop   
  b     .L700085AC
   li    $v1, 127
.L70008598:
  bgez  $v1, .L700085A8
   move  $v0, $v1
  b     .L700085A8
   move  $v0, $zero
.L700085A8:
  move  $v1, $v0
.L700085AC:
  lw    $a0, 0x38($s7)
  jal   alSynSetFXMix
   andi  $a2, $v1, 0xff
.L700085B8:
  lhu   $v0, ($s5)
  andi  $t2, $v0, 0x2d1
  b     .L700088D8
   move  $v0, $t2
glabel .L700085C8
  lbu   $t8, 0x3f($s1)
  lw    $t4, 8($s5)
  addiu $a1, $s1, 0xc
  bne   $fp, $t8, .L70008680
   sh    $t4, 0x34($s1)
  lw    $t0, ($s2)
  lh    $t4, 0x34($s1)
  lbu   $t3, 2($s6)
  lbu   $t2, 0xd($t0)
  li    $at, 16129
  andi  $t6, $t3, 0x3f
  multu $t2, $t4
  lbu   $t3, 0xd($s2)
  sll   $t9, $t6, 1
  lui   $t5, %hi(D_80063BA4) 
  lw    $t5, %lo(D_80063BA4)($t5)
  li    $a3, 1000
  addu  $t7, $t5, $t9
  lh    $t1, ($t7)
  mflo  $t8
  nop   
  nop   
  multu $t8, $t3
  mflo  $t6
  nop   
  nop   
  div   $zero, $t6, $at
  mflo  $t5
  li    $at, 32767
  nop   
  multu $t1, $t5
  mflo  $a0
  nop   
  nop   
  div   $zero, $a0, $at
  mflo  $t9
  addiu $a0, $t9, -1
  bgez  $a0, .L7000866C
   move  $v1, $a0
  b     .L7000866C
   move  $v1, $zero
.L7000866C:
  sll   $a2, $v1, 0x10
  sra   $t7, $a2, 0x10
  move  $a2, $t7
  jal   alSynSetVol
   lw    $a0, 0x38($s7)
.L70008680:
  lhu   $v0, ($s5)
  andi  $t0, $v0, 0x2d1
  b     .L700088D8
   move  $v0, $t0
.L70008690:
  lbu   $t2, 0x3f($s1)
  addiu $a1, $s1, 0xc
  bne   $fp, $t2, .L70008764
   nop   
  lw    $v0, ($s2)
  lh    $t2, 0x34($s1)
  lbu   $t8, 0xd($s2)
  lbu   $t0, 0xd($v0)
  lw    $t4, 8($v0)
  lbu   $t6, 2($s6)
  multu $t0, $t2
  mtc1  $t4, $f16
  andi  $t1, $t6, 0x3f
  li    $at, 16129
  lui   $t3, %hi(D_80063BA4) 
  lw    $t3, %lo(D_80063BA4)($t3)
  sll   $t5, $t1, 1
  cvt.s.w $f18, $f16
  addu  $t9, $t3, $t5
  lh    $t7, ($t9)
  mflo  $t4
  lwc1  $f4, 0x28($s1)
  lwc1  $f8, 0x2c($s1)
  multu $t4, $t8
  div.s $f6, $f18, $f4
  mflo  $t6
  nop   
  nop   
  div   $zero, $t6, $at
  mflo  $t1
  li    $at, 32767
  div.s $f10, $f6, $f8
  multu $t7, $t1
  mflo  $a0
  nop   
  nop   
  div   $zero, $a0, $at
  trunc.w.s $f16, $f10
  mflo  $t3
  addiu $a0, $t3, -1
  move  $v1, $a0
  mfc1  $s0, $f16
  bgez  $a0, .L70008748
   nop   
  b     .L70008748
   move  $v1, $zero
.L70008748:
  sll   $a2, $v1, 0x10
  sra   $t5, $a2, 0x10
  move  $a2, $t5
  lw    $a0, 0x38($s7)
  jal   alSynSetVol
   move  $a3, $s0
  lhu   $v1, ($s5)
.L70008764:
  b     .L700088D8
   andi  $v0, $v1, 0x2d1
  lbu   $t9, 0x3e($s1)
.L70008770:
  andi  $t0, $t9, 2
  bnezl $t0, .L70008884
   lhu   $v0, ($s5)
  lw    $v0, ($s2)
  lh    $t5, 0x34($s1)
  lbu   $t0, 0xd($s2)
  lbu   $t3, 0xd($v0)
  lbu   $t4, 2($s6)
  li    $at, 16129
  multu $t3, $t5
  andi  $t8, $t4, 0x3f
  lui   $t2, %hi(D_80063BA4) 
  lw    $t2, %lo(D_80063BA4)($t2)
  sll   $t6, $t8, 1
  addiu $s4, $s7, 0x14
  addu  $t7, $t2, $t6
  lh    $t1, ($t7)
  mflo  $t9
  nop   
  nop   
  multu $t9, $t0
  mflo  $t4
  nop   
  nop   
  div   $zero, $t4, $at
  mflo  $t8
  li    $at, 32767
  nop   
  multu $t1, $t8
  mflo  $a0
  nop   
  nop   
  div   $zero, $a0, $at
  mflo  $t2
  addiu $a0, $t2, -1
  bgez  $a0, .L7000880C
   move  $v1, $a0
  b     .L7000880C
   move  $v1, $zero
.L7000880C:
  lw    $t6, 4($v0)
  lwc1  $f6, 0x28($s1)
  lwc1  $f10, 0x2c($s1)
  mtc1  $t6, $f18
  sll   $a2, $v1, 0x10
  sra   $t3, $a2, 0x10
  cvt.s.w $f4, $f18
  move  $a2, $t3
  lw    $a0, 0x38($s7)
  addiu $a1, $s1, 0xc
  div.s $f8, $f4, $f6
  div.s $f16, $f8, $f10
  trunc.w.s $f18, $f16
  mfc1  $s0, $f18
  jal   alSynSetVol
   move  $a3, $s0
  li    $t5, 2
  sh    $t5, 0xac($sp)
  sw    $s1, 0xb0($sp)
  move  $a0, $s4
  addiu $a1, $sp, 0xac
  jal   alEvtqPostEvent
   move  $a2, $s0
  lbu   $t9, 0x3e($s1)
  andi  $t0, $t9, 0x20
  beql  $t0, $zero, .L70008884
   lhu   $v0, ($s5)
  jal   sfx_c_700089C4
   move  $a0, $s1
  lhu   $v0, ($s5)
.L70008884:
  andi  $t4, $v0, 0x2d1
  b     .L700088D8
   move  $v0, $t4
.L70008890:
  jal   sfx_c_70008948
   move  $a0, $s1
  lhu   $v0, ($s5)
  andi  $t1, $v0, 0x2d1
  b     .L700088D8
   move  $v0, $t1
.L700088A8:
  lbu   $t8, 0x3e($s1)
  andi  $t2, $t8, 0x10
  beqz  $t2, .L700088CC
   nop   
  lw    $a0, 0xc($s5)
  lh    $a1, 0xa($s5)
  jal   play_sfx_a1
   lw    $a2, 0x30($s1)
  lhu   $v1, ($s5)
.L700088CC:
  b     .L700088D8
   andi  $v0, $v1, 0x2d1
glabel .L700088D4
  andi  $v0, $v1, 0x2d1
.L700088D8:
  lw    $v1, 0x74($sp)
  beqz  $v1, .L700088F8
   move  $s1, $v1
  bnezl $v0, .L700088FC
   lw    $t3, 0x80($sp)
  lbu   $t6, 0x3e($v1)
  andi  $t7, $t6, 1
  sw    $t7, 0x80($sp)
.L700088F8:
  lw    $t3, 0x80($sp)
.L700088FC:
  bnezl $t3, .L7000891C
   lw    $ra, 0x3c($sp)
  beql  $v1, $zero, .L7000891C
   lw    $ra, 0x3c($sp)
  beql  $v0, $zero, .L70007ED0
   lw    $t7, 0x74($sp)
  sw    $s1, 0x78($sp)
  lw    $ra, 0x3c($sp)
.L7000891C:
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
   addiu $sp, $sp, 0xd0

.late_rodata
glabel jpt_80029160
 .word .L70007FBC
 .word .L70008388
 .word .L700088D4
 .word .L7000847C
 .word .L700088D4
 .word .L700088D4
 .word .L700088D4
 .word .L700085C8
 .word .L700088D4
 .word .L700088D4
 .word .L700088D4
 .word .L700088D4
 .word .L700088D4
 .word .L700088D4
 .word .L700088D4
 .word .L700084F0
 
");

asm(R"
glabel sfx_c_70008948
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a0, 0x20($sp)
  lbu   $t7, 0x3e($a0)
  move  $t6, $a0
  lui   $t9, %hi(D_800243F0) 
  andi  $t8, $t7, 4
  beqz  $t8, .L70008994
   nop   
  lw    $t9, %lo(D_800243F0)($t9)
  addiu $a1, $t6, 0xc
  lw    $a0, 0x38($t9)
  jal   alSynStopVoice
   sw    $a1, 0x1c($sp)
  lui   $t0, %hi(D_800243F0) 
  lw    $t0, %lo(D_800243F0)($t0)
  lw    $a1, 0x1c($sp)
  jal   alSynFreeVoice
   lw    $a0, 0x38($t0)
.L70008994:
  jal   sfx_c_70008D04
   lw    $a0, 0x20($sp)
  lui   $a0, %hi(D_800243F0)
  lw    $a0, %lo(D_800243F0)($a0)
  lw    $a1, 0x20($sp)
  li    $a2, 65535
  jal   sfx_c_70008A30
   addiu $a0, $a0, 0x14
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

// 95C4	700089C4
asm(R"
glabel sfx_c_700089C4
  addiu $sp, $sp, -0x30
  sw    $ra, 0x14($sp)
  lw    $t6, 8($a0)
  move  $a3, $a0
  lw    $t7, 4($t6)
  lb    $a0, 5($t7)
  jal   alCents2Ratio
   sw    $a3, 0x30($sp)
  lw    $a3, 0x30($sp)
  lui   $a0, %hi(D_800243F0)
  lw    $a0, %lo(D_800243F0)($a0)
  lwc1  $f4, 0x2c($a3)
  li    $t8, 16
  sh    $t8, 0x20($sp)
  mul.s $f6, $f0, $f4
  addiu $a1, $sp, 0x20
  li    $a2, 33333
  sw    $a3, 0x24($sp)
  addiu $a0, $a0, 0x14
  swc1  $f6, 0x1c($sp)
  lw    $t9, 0x1c($sp)
  jal   alEvtqPostEvent
   sw    $t9, 0x28($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
glabel sfx_c_70008A30
  addiu $sp, $sp, -0x48
  sw    $s2, 0x20($sp)
  move  $s2, $a0
  sw    $ra, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  move  $s3, $a1
  andi  $s4, $a2, 0xffff
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a2, 0x50($sp)
  jal   osSetIntMask
   li    $a0, 1
  sw    $v0, 0x30($sp)
  lw    $s0, 8($s2)
  beqz  $s0, .L70008AC8
   nop   
.L70008A74:
  lw    $t6, 0x10($s0)
  lw    $s1, ($s0)
  bne   $s3, $t6, .L70008AC0
   nop   
  lhu   $t7, 0xc($s0)
  and   $t8, $t7, $s4
  beqz  $t8, .L70008AC0
   nop   
  beqz  $s1, .L70008AAC
   nop   
  lw    $t9, 8($s1)
  lw    $t0, 8($s0)
  addu  $t1, $t9, $t0
  sw    $t1, 8($s1)
.L70008AAC:
  jal   alUnlink
   move  $a0, $s0
  move  $a0, $s0
  jal   alLink
   move  $a1, $s2
.L70008AC0:
  bnez  $s1, .L70008A74
   move  $s0, $s1
.L70008AC8:
  jal   osSetIntMask
   lw    $a0, 0x30($sp)
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  lw    $s3, 0x24($sp)
  lw    $s4, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x48
");

asm(R"
glabel sfx_c_70008AF0
  lui   $t0, %hi(D_800243E4) 
  addiu $t0, %lo(D_800243E4) # addiu $t0, $t0, 0x43e4
  lw    $v0, ($t0)
  sw    $a0, ($sp)
  lw    $v1, 8($t0)
  lw    $a2, 4($t0)
  beqz  $v0, .L70008B24
   move  $a3, $zero
.L70008B10:
  lw    $v0, ($v0)
  addiu $a3, $a3, 1
  andi  $t6, $a3, 0xffff
  bnez  $v0, .L70008B10
   move  $a3, $t6
.L70008B24:
  beqz  $v1, .L70008B40
   move  $a0, $zero
.L70008B2C:
  lw    $v1, ($v1)
  addiu $a0, $a0, 1
  andi  $t7, $a0, 0xffff
  bnez  $v1, .L70008B2C
   move  $a0, $t7
.L70008B40:
  beqz  $a2, .L70008B5C
   move  $v1, $zero
.L70008B48:
  lw    $a2, 4($a2)
  addiu $v1, $v1, 1
  andi  $t8, $v1, 0xffff
  bnez  $a2, .L70008B48
   move  $v1, $t8
.L70008B5C:
  lw    $t9, ($sp)
  move  $v0, $v1
  sh    $a0, ($t9)
  jr    $ra
   sh    $a3, ($a1)
");

// A0=sound data offset?, A1=sample address?
asm(R"
glabel sfx_c_70008B70
  addiu $sp, $sp, -0x38
  lui   $v1, %hi(D_800243E4)
  addiu $v1, %lo(D_800243E4) # addiu $v1, $v1, 0x43e4
  sw    $s0, 0x18($sp)
  lw    $s0, 8($v1)
  sw    $ra, 0x1c($sp)
  sw    $a0, 0x38($sp)
  sw    $a1, 0x3c($sp)
  beqz  $s0, .L70008CF0
   lw    $a2, 4($a1)
  li    $a0, 1
  jal   osSetIntMask
   sw    $a2, 0x30($sp)
  sw    $v0, 0x28($sp)
  lw    $t7, ($s0)
  lui   $v1, %hi(D_800243E4)
  addiu $v1, %lo(D_800243E4) # addiu $v1, $v1, 0x43e4
  move  $a0, $s0
  jal   alUnlink
   sw    $t7, 8($v1)
  lui   $v1, %hi(D_800243E4)
  addiu $v1, %lo(D_800243E4) # addiu $v1, $v1, 0x43e4
  lw    $v0, ($v1)
  lw    $a2, 0x30($sp)
  beql  $v0, $zero, .L70008BF4
   sw    $zero, 4($s0)
  sw    $v0, ($s0)
  sw    $zero, 4($s0)
  lw    $t8, ($v1)
  sw    $s0, 4($t8)
  b     .L70008C00
   sw    $s0, ($v1)
  sw    $zero, 4($s0)
.L70008BF4:
  sw    $zero, ($s0)
  sw    $s0, ($v1)
  sw    $s0, 4($v1)
.L70008C00:
  lw    $a0, 0x28($sp)
  jal   osSetIntMask
   sw    $a2, 0x30($sp)
  lw    $a0, 0x3c($sp)
  lw    $a2, 0x30($sp)
  li    $at, 0x3F800000 # 1.000000
  lw    $t9, ($a0)
  mtc1  $at, $f4
  li    $t1, 5
  lw    $v1, 4($t9)
  li    $t2, 2
  sb    $t1, 0x3f($s0)
  addiu $t0, $v1, 1
  sltiu $t0, $t0, 1
  addiu $a1, $t0, 0x40
  sb    $a1, 0x36($s0)
  sw    $t2, 0x38($s0)
  sw    $a0, 8($s0)
  swc1  $f4, 0x2c($s0)
  lbu   $t3, 3($a2)
  sw    $zero, 0x30($s0)
  andi  $t5, $t3, 0xf0
  andi  $t6, $t5, 0x20
  beqz  $t6, .L70008C94
   sb    $t5, 0x3e($s0)
  lbu   $a0, 4($a2)
  sw    $a1, 0x24($sp)
  sll   $t7, $a0, 2
  subu  $t7, $t7, $a0
  sll   $t7, $t7, 3
  addu  $t7, $t7, $a0
  sll   $t7, $t7, 2
  jal   alCents2Ratio
   addiu $a0, $t7, -0x1770
  lw    $a1, 0x24($sp)
  b     .L70008CC8
   swc1  $f0, 0x28($s0)
.L70008C94:
  lbu   $t8, 4($a2)
  lb    $t0, 5($a2)
  sw    $a1, 0x24($sp)
  sll   $t9, $t8, 2
  subu  $t9, $t9, $t8
  sll   $t9, $t9, 3
  addu  $t9, $t9, $t8
  sll   $t9, $t9, 2
  addu  $a0, $t9, $t0
  jal   alCents2Ratio
   addiu $a0, $a0, -0x1770
  lw    $a1, 0x24($sp)
  swc1  $f0, 0x28($s0)
.L70008CC8:
  li    $at, 64
  beq   $a1, $at, .L70008CE0
   li    $t3, 64
  lbu   $t1, 0x3e($s0)
  ori   $t2, $t1, 2
  sb    $t2, 0x3e($s0)
.L70008CE0:
  li    $t4, 32767
  sb    $zero, 0x3d($s0)
  sb    $t3, 0x3c($s0)
  sh    $t4, 0x34($s0)
.L70008CF0:
  lw    $ra, 0x1c($sp)
  move  $v0, $s0
  lw    $s0, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x38
");

asm(R"
glabel sfx_c_70008D04
  lui   $v0, %hi(D_800243E4)
  addiu $v0, %lo(D_800243E4) # addiu $v0, $v0, 0x43e4
  lw    $t6, ($v0)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  bnel  $a0, $t6, .L70008D2C
   lw    $t8, 4($v0)
  lw    $t7, ($a0)
  sw    $t7, ($v0)
  lw    $t8, 4($v0)
.L70008D2C:
  bne   $a0, $t8, .L70008D3C
   nop   
  lw    $t9, 4($a0)
  sw    $t9, 4($v0)
.L70008D3C:
  jal   alUnlink
   sw    $a0, 0x18($sp)
  lui   $v0, %hi(D_800243E4)
  addiu $v0, %lo(D_800243E4) # addiu $v0, $v0, 0x43e4
  lw    $v1, 8($v0)
  lw    $a0, 0x18($sp)
  beql  $v1, $zero, .L70008D78
   sw    $zero, 4($a0)
  sw    $v1, ($a0)
  sw    $zero, 4($a0)
  lw    $t0, 8($v0)
  sw    $a0, 4($t0)
  b     .L70008D80
   sw    $a0, 8($v0)
  sw    $zero, 4($a0)
.L70008D78:
  sw    $zero, ($a0)
  sw    $a0, 8($v0)
.L70008D80:
  lbu   $t1, 0x3e($a0)
  lui   $v0, %hi(D_800243F4)
  addiu $v0, %lo(D_800243F4) # addiu $v0, $v0, 0x43f4
  andi  $t2, $t1, 4
  beql  $t2, $zero, .L70008DA8
   lw    $v0, 0x30($a0)
  lh    $t3, ($v0)
  addiu $t4, $t3, -1
  sh    $t4, ($v0)
  lw    $v0, 0x30($a0)
.L70008DA8:
  sb    $zero, 0x3f($a0)
  beql  $v0, $zero, .L70008DCC
   lw    $ra, 0x14($sp)
  lw    $t5, ($v0)
  bnel  $a0, $t5, .L70008DC8
   sw    $zero, 0x30($a0)
  sw    $zero, ($v0)
  sw    $zero, 0x30($a0)
.L70008DC8:
  lw    $ra, 0x14($sp)
.L70008DCC:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

/**
 *     A1->A0+0x36.  value is set in sound effect buffer?
 *     accepts: A0=p->SE buffer?, A1=value truncated to byte
 */
asm(R"
glabel sfx_c_70008DD8
  sw    $a1, 4($sp)
  beqz  $a0, .L70008DE8
   andi  $t6, $a1, 0xff
  sb    $t6, 0x36($a0)
.L70008DE8:
  jr    $ra
   nop   
");

/**
 *     V0= true if SE playing flag set [A0+0x3F]
 *     value is set only when sound defaults have been set
 *     accepts: A0=p->SE buffer
 */
asm(R"
glabel sfxGetArg0Unk3F
  beqz  $a0, .L70008E00
   move  $v0, $zero
  jr    $ra
   lbu   $v0, 0x3f($a0)

.L70008E00:
  jr    $ra
   nop   
");

/**
 *     sets sound effect; used by sound effect routines
 *     accepts: A0=p->SE buffer, A1=SE #, A2=p->data
 *          data:	0x0	4	p->SE entry
 *              0x4	4	target volume
 *              0x8	4	audible range (timer)
 *              0xC	4	initial volume
 *              0x10	4	p->preset emitting sound
 *              0x14	4	p->object emitting sound
 */
asm(R"
glabel play_sfx_a1
  addiu $sp, $sp, -0x80
  lui   $t7, %hi(bootswitch_sound) 
  lb    $t7, %lo(bootswitch_sound)($t7)
  sw    $s1, 0x1c($sp)
  sll   $s1, $a1, 0x10
  sra   $t6, $s1, 0x10
  sw    $fp, 0x38($sp)
  sw    $s7, 0x34($sp)
  sw    $s4, 0x28($sp)
  move  $fp, $a0
  move  $s1, $t6
  sw    $ra, 0x3c($sp)
  sw    $s6, 0x30($sp)
  sw    $s5, 0x2c($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s0, 0x18($sp)
  sw    $a1, 0x84($sp)
  sw    $a2, 0x88($sp)
  move  $s7, $zero
  sh    $zero, 0x6e($sp)
  beqz  $t7, .L70008E6C
   move  $s4, $zero
  b     .L70008FF0
   move  $v0, $zero
.L70008E6C:
  bnez  $s1, .L70008E7C
   addiu $s6, $sp, 0x50
  b     .L70008FF0
   move  $v0, $zero
.L70008E7C:
  lui   $s5, %hi(D_800243F0)
  addiu $s5, %lo(D_800243F0) # addiu $s5, $s5, 0x43f0
  lw    $s3, 0x64($sp)
  lw    $t8, 0xc($fp)
.L70008E8C:
  sll   $t9, $s1, 2
  move  $a0, $fp
  addu  $t0, $t8, $t9
  lw    $s2, 0xc($t0)
  jal   sfx_c_70008B70
   move  $a1, $s2
  beqz  $v0, .L70008F48
   move  $s0, $v0
  lw    $t1, ($s5)
  li    $t2, 1
  move  $a1, $s6
  sw    $v0, 0x3c($t1)
  sh    $t2, 0x50($sp)
  sw    $v0, 0x54($sp)
  lw    $t3, 4($s2)
  lbu   $t5, 0x3e($v0)
  lbu   $s3, 1($t3)
  andi  $t6, $t5, 0x10
  sll   $t4, $s3, 6
  addu  $t4, $t4, $s3
  sll   $t4, $t4, 3
  addu  $t4, $t4, $s3
  sll   $t4, $t4, 2
  subu  $t4, $t4, $s3
  sll   $t4, $t4, 2
  addu  $t4, $t4, $s3
  sll   $t4, $t4, 2
  addu  $t4, $t4, $s3
  beqz  $t6, .L70008F34
   move  $s3, $t4
  lbu   $t7, 0x3e($v0)
  move  $a1, $s6
  addiu $a2, $s4, 1
  andi  $t8, $t7, 0xffef
  sb    $t8, 0x3e($v0)
  lw    $a0, ($s5)
  jal   alEvtqPostEvent
   addiu $a0, $a0, 0x14
  addiu $t9, $s3, 1
  sw    $t9, 0x68($sp)
  b     .L70008F44
   sh    $s1, 0x6e($sp)
.L70008F34:
  lw    $a0, ($s5)
  addiu $a2, $s3, 1
  jal   alEvtqPostEvent
   addiu $a0, $a0, 0x14
.L70008F44:
  move  $s7, $s0
.L70008F48:
  lw    $v0, 4($s2)
  addu  $s4, $s4, $s3
  lbu   $t1, 2($v0)
  lbu   $t0, ($v0)
  andi  $t2, $t1, 0xc0
  sll   $t3, $t2, 2
  addu  $s1, $t0, $t3
  sll   $t4, $s1, 0x10
  sra   $s1, $t4, 0x10
  beqz  $s1, .L70008F80
   nop   
  bnezl $s0, .L70008E8C
   lw    $t8, 0xc($fp)
  sw    $s3, 0x64($sp)
.L70008F80:
  beql  $s7, $zero, .L70008FE0
   lw    $t4, 0x88($sp)
  lbu   $t6, 0x3e($s7)
  li    $t0, 512
  addiu $a1, $sp, 0x40
  ori   $t7, $t6, 1
  sb    $t7, 0x3e($s7)
  lw    $t8, 0x88($sp)
  ori   $t2, $t7, 0x10
  sw    $t8, 0x30($s7)
  lh    $t9, 0x6e($sp)
  beql  $t9, $zero, .L70008FE0
   lw    $t4, 0x88($sp)
  sb    $t2, 0x3e($s7)
  lh    $t3, 0x6e($sp)
  lw    $a0, ($s5)
  sh    $t0, 0x40($sp)
  sw    $s7, 0x44($sp)
  sw    $fp, 0x4c($sp)
  lw    $a2, 0x68($sp)
  sw    $t3, 0x48($sp)
  jal   alEvtqPostEvent
   addiu $a0, $a0, 0x14
  lw    $t4, 0x88($sp)
.L70008FE0:
  move  $v0, $s7
  beqz  $t4, .L70008FF0
   nop   
  sw    $s7, ($t4)
.L70008FF0:
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
   addiu $sp, $sp, 0x80
");

/**
 *     deactivates sound effect
 *     accepts: A0=p->SE buffer
 */
asm(R"
glabel sfxDeactivate
  addiu $sp, $sp, -0x28
  li    $t6, 1024
  sw    $ra, 0x14($sp)
  sh    $t6, 0x18($sp)
  beqz  $a0, .L7000905C
   sw    $a0, 0x1c($sp)
  lbu   $t7, 0x3e($a0)
  addiu $a1, $sp, 0x18
  move  $a2, $zero
  andi  $t8, $t7, 0xffef
  sb    $t8, 0x3e($a0)
  lui   $a0, %hi(D_800243F0)
  lw    $a0, %lo(D_800243F0)($a0)
  jal   alEvtqPostEvent
   addiu $a0, $a0, 0x14
.L7000905C:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel sfx_c_7000906C
  addiu $sp, $sp, -0x50
  sw    $s2, 0x20($sp)
  andi  $s2, $a0, 0xff
  sw    $ra, 0x2c($sp)
  sw    $a0, 0x50($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  jal   osSetIntMask
   li    $a0, 1
  lui   $s0, %hi(D_800243E4)
  lw    $s0, %lo(D_800243E4)($s0)
  sw    $v0, 0x4c($sp)
  move  $s1, $s2
  beqz  $s0, .L700090FC
   addiu $s4, $sp, 0x3c
  lui   $s3, %hi(D_800243F0)
  addiu $s3, %lo(D_800243F0) # addiu $s3, $s3, 0x43f0
  li    $s2, -17
  li    $t6, 1024
.L700090C0:
  sh    $t6, 0x3c($sp)
  sw    $s0, 0x40($sp)
  lbu   $v0, 0x3e($s0)
  move  $a1, $s4
  and   $t7, $v0, $s1
  bne   $s1, $t7, .L700090F0
   and   $t8, $v0, $s2
  sb    $t8, 0x3e($s0)
  lw    $a0, ($s3)
  move  $a2, $zero
  jal   alEvtqPostEvent
   addiu $a0, $a0, 0x14
.L700090F0:
  lw    $s0, ($s0)
  bnezl $s0, .L700090C0
   li    $t6, 1024
.L700090FC:
  jal   osSetIntMask
   lw    $a0, 0x4c($sp)
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  lw    $s3, 0x24($sp)
  lw    $s4, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x50
");

void sfx_c_70009124(void) { sfx_c_7000906C(1); }

void sfx_c_70009144(void) { sfx_c_7000906C(0x11); }

void sfx_c_70009164(void) { sfx_c_7000906C(3); }

asm(R"
glabel sfx_c_70009184
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  sw    $a1, 0x2c($sp)
  sh    $a1, 0x18($sp)
  sw    $a0, 0x1c($sp)
  beqz  $a0, .L700091B8
   sw    $a2, 0x20($sp)
  lui   $a0, %hi(D_800243F0)
  lw    $a0, %lo(D_800243F0)($a0)
  addiu $a1, $sp, 0x18
  move  $a2, $zero
  jal   alEvtqPostEvent
   addiu $a0, $a0, 0x14
.L700091B8:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

int sfx_c_700091C8(void) { return sfx_c_70009264(0); }

asm(R"
glabel sfx_c_700091E8
  addiu $sp, $sp, -0x20
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  andi  $s1, $a0, 0xffff
  sw    $ra, 0x1c($sp)
  sw    $a0, 0x20($sp)
  move  $s0, $zero
.L70009204:
  andi  $a0, $s0, 0xff
  jal   sfx_c_70009284
   andi  $a1, $s1, 0xffff
  addiu $s0, $s0, 1
  andi  $t6, $s0, 0xff
  slti  $at, $t6, 7
  bnez  $at, .L70009204
   move  $s0, $t6
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x20
");

void sfx_c_70009238(float arg0) {
  F32_800243FC = arg0;
  sfx_c_700091E8((sfx_c_700091C8() & 0xffff));
}

asm(R"
glabel sfx_c_70009264
  lui   $t7, %hi(D_80063BA8) 
  lw    $t7, %lo(D_80063BA8)($t7)
  andi  $t6, $a0, 0xff
  sll   $t8, $t6, 1
  sw    $a0, ($sp)
  addu  $t9, $t7, $t8
  jr    $ra
   lhu   $v0, ($t9)
");

asm(R"
glabel sfx_c_70009284
  addiu $sp, $sp, -0x48
  lui   $t7, %hi(D_80063BA8) 
  lw    $t7, %lo(D_80063BA8)($t7)
  sw    $s3, 0x20($sp)
  andi  $s3, $a0, 0xff
  sw    $s0, 0x14($sp)
  andi  $t6, $a1, 0xffff
  mtc1  $t6, $f4
  lui   $s0, %hi(D_800243E4)
  sll   $v0, $s3, 1
  sw    $ra, 0x24($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $a0, 0x48($sp)
  sw    $a1, 0x4c($sp)
  lw    $s0, %lo(D_800243E4)($s0)
  addu  $t8, $t7, $v0
  sh    $t6, ($t8)
  bgez  $t6, .L700092E4
   cvt.s.w $f6, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L700092E4:
  lui   $at, %hi(F32_800243FC)
  lwc1  $f10, %lo(F32_800243FC)($at)
  lui   $t1, %hi(D_80063BA4) 
  lw    $t1, %lo(D_80063BA4)($t1)
  mul.s $f16, $f6, $f10
  lui   $s1, %hi(D_800243F0)
  addu  $t2, $t1, $v0
  addiu $s1, %lo(D_800243F0) # addiu $s1, $s1, 0x43f0
  addiu $s2, $sp, 0x30
  trunc.w.s $f18, $f16
  mfc1  $t0, $f18
  beqz  $s0, .L70009364
   sh    $t0, ($t2)
  lw    $v0, 8($s0)
.L7000931C:
  beql  $v0, $zero, .L7000935C
   lw    $s0, ($s0)
  lw    $t3, 4($v0)
  li    $t6, 2048
  move  $a1, $s2
  lbu   $t4, 2($t3)
  move  $a2, $zero
  andi  $t5, $t4, 0x3f
  bnel  $s3, $t5, .L7000935C
   lw    $s0, ($s0)
  lw    $a0, ($s1)
  sh    $t6, 0x30($sp)
  sw    $s0, 0x34($sp)
  jal   alEvtqPostEvent
   addiu $a0, $a0, 0x14
  lw    $s0, ($s0)
.L7000935C:
  bnezl $s0, .L7000931C
   lw    $v0, 8($s0)
.L70009364:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x48
");
