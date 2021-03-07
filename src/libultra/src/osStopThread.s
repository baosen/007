.section .text 

glabel osStopThread
  addiu $sp, $sp, -0x38
  sw    $ra, 0x24($sp)
  sw    $a0, 0x38($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  jal   __osDisableInt
   sw    $s0, 0x18($sp)
  lw    $t6, 0x38($sp)
  move  $s0, $v0
  bnez  $t6, .L7000D774
   nop   
  b     .L7000D77C
   li    $s1, 4
.L7000D774:
  lw    $t7, 0x38($sp)
  lhu   $s1, 0x10($t7)
.L7000D77C:
  move  $s2, $s1
  li    $at, 2
  beq   $s2, $at, .L7000D7C4
   li    $at, 4
  beq   $s2, $at, .L7000D7A4
   li    $at, 8
  beq   $s2, $at, .L7000D7C4
   nop   
  b     .L7000D7E0
   nop   
.L7000D7A4:
  lui   $t9, %hi(__osRunningThread) 
  lw    $t9, %lo(__osRunningThread)($t9)
  li    $t8, 1
  move  $a0, $zero
  jal   __osEnqueueAndYield
   sh    $t8, 0x10($t9)
  b     .L7000D7E0
   nop   
.L7000D7C4:
  lw    $t1, 0x38($sp)
  li    $t0, 1
  sh    $t0, 0x10($t1)
  lw    $t2, 0x38($sp)
  lw    $a0, 8($t2)
  jal   __osDequeueThread
   move  $a1, $t2
.L7000D7E0:
  jal   __osRestoreInt
   move  $a0, $s0
  lw    $ra, 0x24($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x38
