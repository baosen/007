


.section .text 
glabel osSendMesg
  addiu $sp, $sp, -0x38
  sw    $ra, 0x24($sp)
  sw    $a0, 0x38($sp)
  sw    $a1, 0x3c($sp)
  sw    $a2, 0x40($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  jal   __osDisableInt
   sw    $s0, 0x18($sp)
  lw    $t6, 0x38($sp)
  move  $s0, $v0
  lw    $t7, 8($t6)
  lw    $t8, 0x10($t6)
  slt   $at, $t7, $t8
  bnez  $at, .L7000DFAC
   nop   
.L7000DF50:
  lw    $t9, 0x40($sp)
  li    $at, 1
  bne   $t9, $at, .L7000DF84
   nop   
  lui   $t1, %hi(__osRunningThread) 
  lw    $t1, %lo(__osRunningThread)($t1)
  li    $t0, 8
  sh    $t0, 0x10($t1)
  lw    $a0, 0x38($sp)
  jal   __osEnqueueAndYield
   addiu $a0, $a0, 4
  b     .L7000DF94
   nop   
.L7000DF84:
  jal   __osRestoreInt
   move  $a0, $s0
  b     .L7000E044
   li    $v0, -1
.L7000DF94:
  lw    $t2, 0x38($sp)
  lw    $t3, 8($t2)
  lw    $t4, 0x10($t2)
  slt   $at, $t3, $t4
  beqz  $at, .L7000DF50
   nop   
.L7000DFAC:
  lw    $t5, 0x38($sp)
  lw    $t0, 0x3c($sp)
  lw    $t6, 0xc($t5)
  lw    $t7, 8($t5)
  lw    $t9, 0x10($t5)
  lw    $t1, 0x14($t5)
  addu  $t8, $t6, $t7
  div   $zero, $t8, $t9
  mfhi  $s1
  sll   $t2, $s1, 2
  addu  $t3, $t1, $t2
  sw    $t0, ($t3)
  lw    $t4, 0x38($sp)
  bnez  $t9, .L7000DFEC
   nop   
  break 7
.L7000DFEC:
  li    $at, -1
  bne   $t9, $at, .L7000E004
   lui   $at, 0x8000
  bne   $t8, $at, .L7000E004
   nop   
  break 6
.L7000E004:
  lw    $t6, 8($t4)
  addiu $t7, $t6, 1
  sw    $t7, 8($t4)
  lw    $t8, 0x38($sp)
  lw    $t9, ($t8)
  lw    $t5, ($t9)
  beqz  $t5, .L7000E038
   nop   
  jal   __osPopThread
   move  $a0, $t8
  move  $s2, $v0
  jal   osStartThread
   move  $a0, $s2
.L7000E038:
  jal   __osRestoreInt
   move  $a0, $s0
  move  $v0, $zero
.L7000E044:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x38
