.section .text 

glabel osStartThread
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  sw    $a0, 0x28($sp)
  sw    $s1, 0x18($sp)
  jal   __osDisableInt
   sw    $s0, 0x14($sp)
  lw    $t6, 0x28($sp)
  li    $at, 1
  move  $s0, $v0
  lhu   $s1, 0x10($t6)
  beq   $s1, $at, .L7000D5DC
   li    $at, 8
  bne   $s1, $at, .L7000D65C
   nop   
  lw    $t8, 0x28($sp)
  li    $t7, 2
  lui   $a0, %hi(__osRunQueue)
  sh    $t7, 0x10($t8)
  lw    $a1, 0x28($sp)
  jal   __osEnqueueThread
   addiu $a0, %lo(__osRunQueue) # addiu $a0, $a0, 0x7728
  b     .L7000D65C
   nop   
.L7000D5DC:
  lw    $t9, 0x28($sp)
  lw    $t0, 8($t9)
  beqz  $t0, .L7000D5FC
   nop   
  lui   $t1, %hi(__osRunQueue) 
  addiu $t1, %lo(__osRunQueue) # addiu $t1, $t1, 0x7728
  bne   $t0, $t1, .L7000D620
   nop   
.L7000D5FC:
  lw    $t3, 0x28($sp)
  li    $t2, 2
  lui   $a0, %hi(__osRunQueue)
  sh    $t2, 0x10($t3)
  lw    $a1, 0x28($sp)
  jal   __osEnqueueThread
   addiu $a0, %lo(__osRunQueue) # addiu $a0, $a0, 0x7728
  b     .L7000D65C
   nop   
.L7000D620:
  lw    $t5, 0x28($sp)
  li    $t4, 8
  sh    $t4, 0x10($t5)
  lw    $t6, 0x28($sp)
  lw    $a0, 8($t6)
  jal   __osEnqueueThread
   move  $a1, $t6
  lw    $t7, 0x28($sp)
  jal   __osPopThread
   lw    $a0, 8($t7)
  move  $s1, $v0
  lui   $a0, %hi(__osRunQueue)
  addiu $a0, %lo(__osRunQueue) # addiu $a0, $a0, 0x7728
  jal   __osEnqueueThread
   move  $a1, $s1
.L7000D65C:
  lui   $t8, %hi(__osRunningThread) 
  lw    $t8, %lo(__osRunningThread)($t8)
  bnez  $t8, .L7000D67C
   nop   
  jal   __osDispatchThread
   nop   
  b     .L7000D6B4
   nop   
.L7000D67C:
  lui   $t9, %hi(__osRunningThread) 
  lui   $t1, %hi(__osRunQueue) 
  lw    $t1, %lo(__osRunQueue)($t1)
  lw    $t9, %lo(__osRunningThread)($t9)
  lw    $t2, 4($t1)
  lw    $t0, 4($t9)
  slt   $at, $t0, $t2
  beqz  $at, .L7000D6B4
   nop   
  li    $t3, 2
  lui   $a0, %hi(__osRunQueue)
  sh    $t3, 0x10($t9)
  jal   __osEnqueueAndYield
   addiu $a0, %lo(__osRunQueue) # addiu $a0, $a0, 0x7728
.L7000D6B4:
  jal   __osRestoreInt
   move  $a0, $s0
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
