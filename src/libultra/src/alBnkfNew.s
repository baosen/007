.section .text
  jr    $ra
  nop   
  jr    $ra
  nop   

glabel ultra_70010D80
  lbu   $t6, 3($a0)
  bnez  $t6, .L70010E64
   nop   
  lh    $t7, 0xe($a0)
  li    $t1, 1
  sb    $t1, 3($a0)
  blez  $t7, .L70010E64
   move  $v0, $zero
  move  $v1, $a0
  li    $t2, 1
  lw    $t8, 0x10($v1)
.L70010DAC:
  addu  $t9, $t8, $a1
  sw    $t9, 0x10($v1)
  lbu   $t6, 0xe($t9)
  move  $a2, $t9
  bnezl $t6, .L70010E50
   lh    $t8, 0xe($a0)
  lw    $t7, ($t9)
  sb    $t1, 0xe($t9)
  addu  $t8, $t7, $a1
  sw    $t8, ($t9)
  lw    $t9, 4($t9)
  lw    $t7, 8($a2)
  addu  $t6, $t9, $a1
  addu  $t8, $t7, $a1
  sw    $t6, 4($a2)
  sw    $t8, 8($a2)
  lbu   $t9, 9($t8)
  move  $t0, $t8
  bnezl $t9, .L70010E50
   lh    $t8, 0xe($a0)
  lw    $t6, ($t8)
  lbu   $a2, 8($t8)
  sb    $t1, 9($t8)
  addu  $t7, $t6, $a3
  bnez  $a2, .L70010E34
   sw    $t7, ($t8)
  lw    $t8, 0x10($t8)
  lw    $a2, 0xc($t0)
  addu  $t9, $t8, $a1
  beqz  $a2, .L70010E4C
   sw    $t9, 0x10($t0)
  addu  $t6, $a2, $a1
  b     .L70010E4C
   sw    $t6, 0xc($t0)
.L70010E34:
  bnel  $t2, $a2, .L70010E50
   lh    $t8, 0xe($a0)
  lw    $a2, 0xc($t0)
  beqz  $a2, .L70010E4C
   addu  $t7, $a2, $a1
  sw    $t7, 0xc($t0)
.L70010E4C:
  lh    $t8, 0xe($a0)
.L70010E50:
  addiu $v0, $v0, 1
  addiu $v1, $v1, 4
  slt   $at, $v0, $t8
  bnezl $at, .L70010DAC
  lw    $t8, 0x10($v1)

.L70010E64:
  jr    $ra
  nop   
  jr    $ra
  nop   

glabel alBnkfNew
  addiu $sp, $sp, -0x30
  sw    $ra, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  lh    $t6, ($a0)
  li    $at, 16945
  move  $s0, $a0
  bne   $t6, $at, .L70010F58
   move  $s1, $a1
  lh    $t7, 2($a0)
  move  $s3, $zero
  move  $s2, $a0
  blez  $t7, .L70010F58
   li    $s4, 1
  lw    $t8, 4($s2)
.L70010EBC:
  addu  $t9, $t8, $s0
  beqz  $t9, .L70010F40
   sw    $t9, 4($s2)
  lbu   $t6, 2($t9)
  move  $t5, $t9
  bnezl $t6, .L70010F44
   lh    $t8, 2($s0)
  lw    $v0, 8($t9)
  sb    $s4, 2($t9)
  move  $t4, $zero
  beqz  $v0, .L70010EFC
   addu  $a0, $v0, $s0
  sw    $a0, 8($t9)
  move  $a1, $s0
  jal   ultra_70010D80
   move  $a3, $s1
.L70010EFC:
  lh    $t8, ($t5)
  move  $t3, $t5
  blezl $t8, .L70010F44
   lh    $t8, 2($s0)
  lw    $t9, 0xc($t3)
.L70010F10:
  move  $a1, $s0
  addu  $a0, $t9, $s0
  beqz  $a0, .L70010F28
   sw    $a0, 0xc($t3)
  jal   ultra_70010D80
   move  $a3, $s1
.L70010F28:
  lh    $t7, ($t5)
  addiu $t4, $t4, 1
  addiu $t3, $t3, 4
  slt   $at, $t4, $t7
  bnezl $at, .L70010F10
   lw    $t9, 0xc($t3)
.L70010F40:
  lh    $t8, 2($s0)
.L70010F44:
  addiu $s3, $s3, 1
  addiu $s2, $s2, 4
  slt   $at, $s3, $t8
  bnezl $at, .L70010EBC
   lw    $t8, 4($s2)
.L70010F58:
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  lw    $s3, 0x24($sp)
  lw    $s4, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x30

glabel alSeqFileNew
  lh    $t6, 2($a0)
  move  $v0, $zero
  move  $v1, $a0
  blez  $t6, .L70010FB0
   nop   
  lw    $t7, 4($v1)
.L70010F90:
  addiu $v0, $v0, 1
  addiu $v1, $v1, 8
  addu  $t8, $t7, $a1
  sw    $t8, -4($v1)
  lh    $t9, 2($a0)
  slt   $at, $v0, $t9
  bnezl $at, .L70010F90
   lw    $t7, 4($v1)
.L70010FB0:
  jr    $ra
   nop   
