


.section .text, "ax"
glabel alCSPSetSeq
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  li    $t6, 13
  sw    $a1, 0x1c($sp)
  sh    $t6, 0x18($sp)
  addiu $a1, $sp, 0x18
  addiu $a0, $a0, 0x48
  jal   alEvtqPostEvent
   move  $a2, $zero
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
