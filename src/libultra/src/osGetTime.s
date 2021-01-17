.section .text
glabel osGetTime
  addiu $sp, $sp, -0x38
  sw    $ra, 0x1c($sp)
  jal   __osDisableInt
   sw    $s0, 0x18($sp)
  jal   osGetCount
   move  $s0, $v0
  sw    $v0, 0x34($sp)
  lui   $t7, %hi(__osBaseCounter) 
  lw    $t7, %lo(__osBaseCounter)($t7)
  lw    $t6, 0x34($sp)
  lui   $t0, %hi(__osCurrentTime) 
  lui   $t1, %hi(__osCurrentTime+4) 
  lw    $t1, %lo(__osCurrentTime+4)($t1)
  lw    $t0, %lo(__osCurrentTime)($t0)
  subu  $t8, $t6, $t7
  sw    $t8, 0x30($sp)
  move  $a0, $s0
  sw    $t1, 0x2c($sp)
  jal   __osRestoreInt
   sw    $t0, 0x28($sp)
  lw    $t9, 0x30($sp)
  lw    $t5, 0x2c($sp)
  lw    $ra, 0x1c($sp)
  move  $t3, $t9
  addu  $v1, $t3, $t5
  lw    $t4, 0x28($sp)
  li    $t2, 0
  sltu  $at, $v1, $t5
  addu  $v0, $at, $t2
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x38
  jr    $ra
   addu  $v0, $v0, $t4
