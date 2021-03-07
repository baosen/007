


.section .text 

glabel osViSwapBuffer
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  jal   __osDisableInt
   sw    $a0, 0x20($sp)
  lui   $t7, %hi(__osViNext) 
  lw    $t7, %lo(__osViNext)($t7)
  lw    $t6, 0x20($sp)
  sw    $v0, 0x1c($sp)
  lui   $t8, %hi(__osViNext) 
  sw    $t6, 4($t7)
  lw    $t8, %lo(__osViNext)($t8)
  lhu   $t9, ($t8)
  ori   $t0, $t9, 0x10
  sh    $t0, ($t8)
  jal   __osRestoreInt
   lw    $a0, 0x1c($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
