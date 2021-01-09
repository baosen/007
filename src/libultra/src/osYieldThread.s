

.section .text, "ax" 
glabel osYieldThread
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  jal   __osDisableInt
   sw    $s0, 0x18($sp)
  lui   $t7, %hi(__osRunningThread) 
  lw    $t7, %lo(__osRunningThread)($t7)
  li    $t6, 2
  lui   $a0, %hi(__osRunQueue)
  move  $s0, $v0
  addiu $a0, %lo(__osRunQueue) # addiu $a0, $a0, 0x7728
  jal   __osEnqueueAndYield
   sh    $t6, 0x10($t7)
  jal   __osRestoreInt
   move  $a0, $s0
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
