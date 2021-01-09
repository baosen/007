


.section .text, "ax" 
glabel _allocatePVoice
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  sw    $a2, 0x30($sp)
  lw    $a3, 0x14($a0)
  sll   $t6, $a2, 0x10
  sra   $a2, $t6, 0x10
  move  $t0, $a0
  beqz  $a3, .L700131C4
   move  $v1, $zero
  sw    $a3, ($a1)
  sw    $t0, 0x28($sp)
  sw    $a3, 0x24($sp)
  sw    $zero, 0x1c($sp)
  jal   alUnlink
   move  $a0, $a3
  lw    $t0, 0x28($sp)
  lw    $a0, 0x24($sp)
  jal   alLink
   addiu $a1, $t0, 0xc
  b     .L70013244
   lw    $v1, 0x1c($sp)
.L700131C4:
  lw    $a3, 4($t0)
  beqz  $a3, .L700131FC
   move  $a0, $a3
  sw    $a3, ($a1)
  sw    $t0, 0x28($sp)
  sw    $a3, 0x24($sp)
  jal   alUnlink
   sw    $v1, 0x1c($sp)
  lw    $t0, 0x28($sp)
  lw    $a0, 0x24($sp)
  jal   alLink
   addiu $a1, $t0, 0xc
  b     .L70013244
   lw    $v1, 0x1c($sp)
.L700131FC:
  lw    $a3, 0xc($t0)
  beql  $a3, $zero, .L70013248
   lw    $ra, 0x14($sp)
  lw    $t8, 8($a3)
.L7001320C:
  lh    $t9, 0x16($t8)
  slt   $at, $a2, $t9
  bnezl $at, .L7001323C
   lw    $a3, ($a3)
  lw    $t1, 0xd8($a3)
  bnezl $t1, .L7001323C
   lw    $a3, ($a3)
  sw    $a3, ($a1)
  lw    $t2, 8($a3)
  li    $v1, 1
  lh    $a2, 0x16($t2)
  lw    $a3, ($a3)
.L7001323C:
  bnezl $a3, .L7001320C
   lw    $t8, 8($a3)
.L70013244:
  lw    $ra, 0x14($sp)
.L70013248:
  addiu $sp, $sp, 0x28
  move  $v0, $v1
  jr    $ra
   nop   

glabel alSynAllocVoice
  addiu $sp, $sp, -0x30
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a0, 0x30($sp)
  sw    $zero, 0x2c($sp)
  lh    $t6, ($a2)
  move  $s0, $a1
  sh    $t6, 0x16($a1)
  lbu   $t7, 4($a2)
  sw    $zero, 0xc($a1)
  sh    $t7, 0x1a($a1)
  lh    $t8, 2($a2)
  sh    $zero, 0x14($a1)
  sw    $zero, 8($a1)
  sh    $t8, 0x18($a1)
  lh    $a2, ($a2)
  lw    $a0, 0x30($sp)
  jal   _allocatePVoice
   addiu $a1, $sp, 0x2c
  lw    $t9, 0x2c($sp)
  beql  $t9, $zero, .L70013380
   lw    $v0, 0x2c($sp)
  beqz  $v0, .L70013364
   lw    $a0, 0xc($t9)
  li    $t0, 512
  sw    $t0, 0xd8($t9)
  lw    $t1, 0x2c($sp)
  lw    $t2, 8($t1)
  sw    $zero, 8($t2)
  jal   __allocParam
   sw    $a0, 0x28($sp)
  lw    $t3, 0x30($sp)
  lw    $a0, 0x28($sp)
  li    $t5, 11
  lw    $t4, 0x1c($t3)
  sh    $t5, 8($v0)
  sw    $zero, 0xc($v0)
  sw    $t4, 4($v0)
  lw    $t6, 0x2c($sp)
  li    $a1, 3
  move  $a2, $v0
  lw    $t7, 0xd8($t6)
  addiu $t8, $t7, -0x40
  sw    $t8, 0x10($v0)
  lw    $t9, 8($a0)
  jalr  $t9
  nop   
  jal   __allocParam
   nop   
  lw    $a0, 0x28($sp)
  beqz  $v0, .L7001336C
   move  $a2, $v0
  lw    $t0, 0x30($sp)
  lw    $t2, 0x2c($sp)
  li    $t5, 15
  lw    $t1, 0x1c($t0)
  lw    $t3, 0xd8($t2)
  sh    $t5, 8($v0)
  sw    $zero, ($v0)
  addu  $t4, $t1, $t3
  sw    $t4, 4($v0)
  lw    $t9, 8($a0)
  li    $a1, 3
  jalr  $t9
  nop   
  b     .L70013370
   lw    $t7, 0x2c($sp)
.L70013364:
  lw    $t6, 0x2c($sp)
  sw    $zero, 0xd8($t6)
.L7001336C:
  lw    $t7, 0x2c($sp)
.L70013370:
  sw    $s0, 8($t7)
  lw    $t8, 0x2c($sp)
  sw    $t8, 8($s0)
  lw    $v0, 0x2c($sp)
.L70013380:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  sltu  $t0, $zero, $v0
  move  $v0, $t0
  jr    $ra
   addiu $sp, $sp, 0x30
