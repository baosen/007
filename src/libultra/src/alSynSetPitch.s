


.section .text 
glabel alSynSetPitch
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  sw    $a2, 0x20($sp)
  lw    $t6, 8($a1)
  beql  $t6, $zero, .L700135D8
   lw    $ra, 0x14($sp)
  jal   __allocParam
   sw    $a1, 0x1c($sp)
  lw    $a3, 0x1c($sp)
  beqz  $v0, .L700135D4
   move  $a2, $v0
  lw    $t7, 0x18($sp)
  lw    $t9, 8($a3)
  li    $t2, 7
  lw    $t8, 0x1c($t7)
  lw    $t0, 0xd8($t9)
  sh    $t2, 8($v0)
  li    $a1, 3
  addu  $t1, $t8, $t0
  sw    $t1, 4($v0)
  lwc1  $f4, 0x20($sp)
  sw    $zero, ($v0)
  swc1  $f4, 0xc($v0)
  lw    $t3, 8($a3)
  lw    $a0, 0xc($t3)
  lw    $t9, 8($a0)
  jalr  $t9
  nop   
.L700135D4:
  lw    $ra, 0x14($sp)
.L700135D8:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
