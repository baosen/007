


.section .text   

glabel osViGetCurrentFramebuffer
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  jal   __osDisableInt
   sw    $s0, 0x18($sp)
  lui   $t6, %hi(__osViCurr) 
  lw    $t6, %lo(__osViCurr)($t6)
  move  $s0, $v0
  move  $a0, $s0
  lw    $t7, 4($t6)
  jal   __osRestoreInt
   sw    $t7, 0x20($sp)
  lw    $ra, 0x1c($sp)
  lw    $v0, 0x20($sp)
  lw    $s0, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
