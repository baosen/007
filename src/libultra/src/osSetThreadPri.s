


.section .text 

glabel osSetThreadPri
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  sw    $a0, 0x28($sp)
  sw    $a1, 0x2c($sp)
  jal   __osDisableInt
   sw    $s0, 0x18($sp)
  lw    $t6, 0x28($sp)
  move  $s0, $v0
  bnez  $t6, .L7000D834
   nop   
  lui   $t7, %hi(__osRunningThread) 
  lw    $t7, %lo(__osRunningThread)($t7)
  sw    $t7, 0x28($sp)
.L7000D834:
  lw    $t8, 0x28($sp)
  lw    $t0, 0x2c($sp)
  lw    $t9, 4($t8)
  beq   $t9, $t0, .L7000D8C4
   nop   
  sw    $t0, 4($t8)
  lui   $t2, %hi(__osRunningThread) 
  lw    $t2, %lo(__osRunningThread)($t2)
  lw    $t1, 0x28($sp)
  beq   $t1, $t2, .L7000D88C
   nop   
  lhu   $t3, 0x10($t1)
  li    $at, 1
  beq   $t3, $at, .L7000D88C
   nop   
  lw    $a0, 8($t1)
  jal   __osDequeueThread
   move  $a1, $t1
  lw    $t4, 0x28($sp)
  lw    $a0, 8($t4)
  jal   __osEnqueueThread
   move  $a1, $t4
.L7000D88C:
  lui   $t5, %hi(__osRunningThread) 
  lui   $t7, %hi(__osRunQueue) 
  lw    $t7, %lo(__osRunQueue)($t7)
  lw    $t5, %lo(__osRunningThread)($t5)
  lw    $t9, 4($t7)
  lw    $t6, 4($t5)
  slt   $at, $t6, $t9
  beqz  $at, .L7000D8C4
   nop   
  li    $t0, 2
  lui   $a0, %hi(__osRunQueue)
  sh    $t0, 0x10($t5)
  jal   __osEnqueueAndYield
   addiu $a0, %lo(__osRunQueue) # addiu $a0, $a0, 0x7728
.L7000D8C4:
  jal   __osRestoreInt
   move  $a0, $s0
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
