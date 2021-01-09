


.section .text, "ax" 
glabel osPiStartDma
  addiu $sp, $sp, -0x28
  lui   $t6, %hi(__osPiDevMgr) 
  lw    $t6, %lo(__osPiDevMgr)($t6)
  sw    $ra, 0x1c($sp)
  sw    $a0, 0x28($sp)
  sw    $a1, 0x2c($sp)
  sw    $a2, 0x30($sp)
  sw    $a3, 0x34($sp)
  sw    $s1, 0x18($sp)
  bnez  $t6, .L7000F6D4
   sw    $s0, 0x14($sp)
  b     .L7000F798
   li    $v0, -1
.L7000F6D4:
  lw    $t7, 0x30($sp)
  bnez  $t7, .L7000F6F0
   nop   
  lw    $t9, 0x28($sp)
  li    $t8, 11
  b     .L7000F6FC
   sh    $t8, ($t9)
.L7000F6F0:
  lw    $t1, 0x28($sp)
  li    $t0, 12
  sh    $t0, ($t1)
.L7000F6FC:
  lw    $t2, 0x2c($sp)
  lw    $t3, 0x28($sp)
  li    $at, 1
  sb    $t2, 2($t3)
  lw    $t5, 0x28($sp)
  lw    $t4, 0x40($sp)
  sw    $t4, 4($t5)
  lw    $t7, 0x28($sp)
  lw    $t6, 0x38($sp)
  sw    $t6, 8($t7)
  lw    $t9, 0x28($sp)
  lw    $t8, 0x34($sp)
  sw    $t8, 0xc($t9)
  lw    $t1, 0x28($sp)
  lw    $t0, 0x3c($sp)
  sw    $t0, 0x10($t1)
  lw    $t2, 0x28($sp)
  sw    $zero, 0x14($t2)
  lw    $t3, 0x2c($sp)
  bne   $t3, $at, .L7000F774
   nop   
  jal   osPiGetCmdQueue
   nop   
  move  $s1, $v0
  move  $a0, $s1
  lw    $a1, 0x28($sp)
  jal   osJamMesg
   move  $a2, $zero
  b     .L7000F794
   move  $s0, $v0
.L7000F774:
  jal   osPiGetCmdQueue
   nop   
  move  $s1, $v0
  move  $a0, $s1
  lw    $a1, 0x28($sp)
  jal   osSendMesg
   move  $a2, $zero
  move  $s0, $v0
.L7000F794:
  move  $v0, $s0
.L7000F798:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
