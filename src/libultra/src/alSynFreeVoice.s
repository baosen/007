


.section .text, "ax"  
glabel alSynFreeVoice
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lw    $a2, 8($a1)
  move  $t0, $a0
  move  $a3, $a1
  beql  $a2, $zero, .L700137B4
   lw    $ra, 0x14($sp)
  lw    $t6, 0xd8($a2)
  beql  $t6, $zero, .L7001379C
   move  $a0, $t0
  sw    $a1, 0x1c($sp)
  jal   __allocParam
   sw    $a0, 0x18($sp)
  lw    $a3, 0x1c($sp)
  lw    $t0, 0x18($sp)
  beqz  $v0, .L700137B0
   move  $a2, $v0
  lw    $t8, 8($a3)
  lw    $t7, 0x1c($t0)
  li    $a1, 3
  lw    $t9, 0xd8($t8)
  sh    $zero, 8($v0)
  addu  $t1, $t7, $t9
  sw    $t1, 4($v0)
  lw    $t2, 8($a3)
  sw    $t2, 0xc($v0)
  lw    $t3, 8($a3)
  lw    $a0, 0xc($t3)
  sw    $a3, 0x1c($sp)
  lw    $t9, 8($a0)
  jalr  $t9
  nop   
  b     .L700137AC
   lw    $a3, 0x1c($sp)
  move  $a0, $t0
.L7001379C:
  move  $a1, $a2
  jal   _freePVoice
   sw    $a3, 0x1c($sp)
  lw    $a3, 0x1c($sp)
.L700137AC:
  sw    $zero, 8($a3)
.L700137B0:
  lw    $ra, 0x14($sp)
.L700137B4:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
