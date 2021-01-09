


.section .text, "ax"

glabel alCSPSetVol
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  sw    $a1, 0x2c($sp)
  move  $t6, $a1
  li    $t7, 10
  sh    $t7, 0x18($sp)
  sh    $t6, 0x1c($sp)
  addiu $a1, $sp, 0x18
  addiu $a0, $a0, 0x48
  jal   alEvtqPostEvent
   move  $a2, $zero
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
