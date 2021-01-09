


.section .text, "ax" 
 
glabel osViSetEvent
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  sw    $a0, 0x28($sp)
  sw    $a1, 0x2c($sp)
  sw    $a2, 0x30($sp)
  jal   __osDisableInt
   sw    $s0, 0x18($sp)
  lui   $t7, %hi(__osViNext) 
  lw    $t7, %lo(__osViNext)($t7)
  lw    $t6, 0x28($sp)
  lui   $t9, %hi(__osViNext) 
  lui   $t1, %hi(__osViNext) 
  sw    $t6, 0x10($t7)
  lw    $t9, %lo(__osViNext)($t9)
  lw    $t8, 0x2c($sp)
  move  $s0, $v0
  move  $a0, $s0
  sw    $t8, 0x14($t9)
  lw    $t1, %lo(__osViNext)($t1)
  lw    $t0, 0x30($sp)
  jal   __osRestoreInt
   sh    $t0, 2($t1)
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   

 