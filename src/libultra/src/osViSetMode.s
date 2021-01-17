.section .text
glabel osViSetMode
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  sw    $a0, 0x28($sp)
  jal   __osDisableInt
   sw    $s0, 0x18($sp)
  lui   $t7, %hi(__osViNext) 
  lw    $t7, %lo(__osViNext)($t7)
  lw    $t6, 0x28($sp)
  lui   $t9, %hi(__osViNext) 
  li    $t8, 1
  sw    $t6, 8($t7)
  lw    $t9, %lo(__osViNext)($t9)
  lui   $t0, %hi(__osViNext) 
  move  $s0, $v0
  sh    $t8, ($t9)
  lw    $t0, %lo(__osViNext)($t0)
  move  $a0, $s0
  lw    $t1, 8($t0)
  lw    $t2, 4($t1)
  jal   __osRestoreInt
   sw    $t2, 0xc($t0)
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
