


.section .text
glabel alSynAddPlayer
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  move  $a2, $a0
  sw    $a2, 0x18($sp)
  li    $a0, 1
  jal   osSetIntMask
   sw    $a1, 0x1c($sp)
  lw    $a2, 0x18($sp)
  lw    $a1, 0x1c($sp)
  move  $a0, $v0
  lw    $t6, 0x20($a2)
  sw    $t6, 0x10($a1)
  lw    $t7, ($a2)
  sw    $t7, ($a1)
  jal   osSetIntMask
   sw    $a1, ($a2)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop 
