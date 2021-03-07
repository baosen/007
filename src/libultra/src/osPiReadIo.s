


.section .text  
glabel osPiReadIo
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  sw    $a0, 0x28($sp)
  sw    $a1, 0x2c($sp)
  jal   __osPiGetAccess
   sw    $s0, 0x18($sp)
  lw    $a0, 0x28($sp)
  jal   osPiRawReadIo
   lw    $a1, 0x2c($sp)
  jal   __osPiRelAccess
   move  $s0, $v0
  lw    $ra, 0x1c($sp)
  move  $v0, $s0
  lw    $s0, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
