


.section .text 
glabel alSynSetFXMix
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  sw    $a2, 0x20($sp)
  lw    $t6, 8($a1)
  beql  $t6, $zero, .L70013678
   lw    $ra, 0x14($sp)
  jal   __allocParam
   sw    $a1, 0x1c($sp)
  lw    $a3, 0x1c($sp)
  beqz  $v0, .L70013674
   move  $a2, $v0
  lw    $t7, 0x18($sp)
  lw    $t9, 8($a3)
  li    $t2, 16
  lw    $t8, 0x1c($t7)
  lw    $t0, 0xd8($t9)
  sh    $t2, 8($v0)
  addu  $t1, $t8, $t0
  sw    $t1, 4($v0)
  lbu   $v1, 0x23($sp)
  bgez  $v1, .L70013654
   negu  $t3, $v1
  b     .L70013658
   sw    $t3, 0xc($v0)
.L70013654:
  sw    $v1, 0xc($v0)
.L70013658:
  sw    $zero, ($a2)
  lw    $t4, 8($a3)
  li    $a1, 3
  lw    $a0, 0xc($t4)
  lw    $t9, 8($a0)
  jalr  $t9
  nop   
.L70013674:
  lw    $ra, 0x14($sp)
.L70013678:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
