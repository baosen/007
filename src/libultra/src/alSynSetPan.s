


.section .text 
glabel alSynSetPan
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  sw    $a2, 0x20($sp)
  lw    $t6, 8($a1)
  beql  $t6, $zero, .L70013548
   lw    $ra, 0x14($sp)
  jal   __allocParam
   sw    $a1, 0x1c($sp)
  lw    $a3, 0x1c($sp)
  beqz  $v0, .L70013544
   move  $a2, $v0
  lw    $t7, 0x18($sp)
  lw    $t9, 8($a3)
  li    $t2, 12
  lw    $t8, 0x1c($t7)
  lw    $t0, 0xd8($t9)
  sh    $t2, 8($v0)
  li    $a1, 3
  addu  $t1, $t8, $t0
  sw    $t1, 4($v0)
  lbu   $t3, 0x23($sp)
  sw    $zero, ($v0)
  sw    $t3, 0xc($v0)
  lw    $t4, 8($a3)
  lw    $a0, 0xc($t4)
  lw    $t9, 8($a0)
  jalr  $t9
  nop   
.L70013544:
  lw    $ra, 0x14($sp)
.L70013548:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
