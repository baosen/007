


.section .text  
glabel osViSetYScale
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  swc1  $f12, 0x28($sp)
  jal   __osDisableInt
   sw    $s0, 0x18($sp)
  lui   $t6, %hi(__osViNext) 
  lw    $t6, %lo(__osViNext)($t6)
  lwc1  $f4, 0x28($sp)
  lui   $t7, %hi(__osViNext) 
  move  $s0, $v0
  swc1  $f4, 0x24($t6)
  lw    $t7, %lo(__osViNext)($t7)
  move  $a0, $s0
  lhu   $t8, ($t7)
  ori   $t9, $t8, 4
  jal   __osRestoreInt
   sh    $t9, ($t7)
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
