


.section .text 
glabel alSynSetVol
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a1, 0x24($sp)
  sw    $a2, 0x28($sp)
  sw    $a3, 0x2c($sp)
  lw    $t7, 8($a1)
  beql  $t7, $zero, .L70013430
   lw    $ra, 0x14($sp)
  jal   __allocParam
   sw    $a0, 0x20($sp)
  beqz  $v0, .L7001342C
   lw    $a0, 0x20($sp)
  lw    $t9, 0x24($sp)
  lw    $t8, 0x1c($a0)
  li    $t3, 11
  lw    $t0, 8($t9)
  lw    $t1, 0xd8($t0)
  sh    $t3, 8($v0)
  addu  $t2, $t8, $t1
  sw    $t2, 4($v0)
  lh    $t4, 0x2a($sp)
  sw    $t4, 0xc($v0)
  sw    $v0, 0x1c($sp)
  jal   _timeToSamples
   lw    $a1, 0x2c($sp)
  lw    $a2, 0x1c($sp)
  li    $a1, 3
  sw    $v0, 0x10($a2)
  sw    $zero, ($a2)
  lw    $t5, 0x24($sp)
  lw    $t6, 8($t5)
  lw    $a0, 0xc($t6)
  lw    $t9, 8($a0)
  jalr  $t9
  nop   
.L7001342C:
  lw    $ra, 0x14($sp)
.L70013430:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
