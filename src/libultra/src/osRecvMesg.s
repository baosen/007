


.section .text  
glabel osRecvMesg
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  sw    $a0, 0x28($sp)
  sw    $a1, 0x2c($sp)
  sw    $a2, 0x30($sp)
  sw    $s1, 0x18($sp)
  jal   __osDisableInt
   sw    $s0, 0x14($sp)
  lw    $t6, 0x28($sp)
  move  $s0, $v0
  lw    $t7, 8($t6)
  bnez  $t7, .L7000DE48
   nop   
.L7000DE04:
  lw    $t8, 0x30($sp)
  bnez  $t8, .L7000DE20
   nop   
  jal   __osRestoreInt
   move  $a0, $s0
  b     .L7000DEF4
   li    $v0, -1
.L7000DE20:
  lui   $t0, %hi(__osRunningThread) 
  lw    $t0, %lo(__osRunningThread)($t0)
  li    $t9, 8
  sh    $t9, 0x10($t0)
  jal   __osEnqueueAndYield
   lw    $a0, 0x28($sp)
  lw    $t1, 0x28($sp)
  lw    $t2, 8($t1)
  beqz  $t2, .L7000DE04
   nop   
.L7000DE48:
  lw    $t3, 0x2c($sp)
  beqz  $t3, .L7000DE70
   nop   
  lw    $t4, 0x28($sp)
  lw    $t6, 0xc($t4)
  lw    $t5, 0x14($t4)
  sll   $t7, $t6, 2
  addu  $t8, $t5, $t7
  lw    $t9, ($t8)
  sw    $t9, ($t3)
.L7000DE70:
  lw    $t0, 0x28($sp)
  lw    $t1, 0xc($t0)
  lw    $t4, 0x10($t0)
  addiu $t2, $t1, 1
  div   $zero, $t2, $t4
  mfhi  $t6
  sw    $t6, 0xc($t0)
  lw    $t5, 0x28($sp)
  bnez  $t4, .L7000DE9C
   nop   
  break 7
.L7000DE9C:
  li    $at, -1
  bne   $t4, $at, .L7000DEB4
   lui   $at, 0x8000
  bne   $t2, $at, .L7000DEB4
   nop   
  break 6
.L7000DEB4:
  lw    $t7, 8($t5)
  addiu $t8, $t7, -1
  sw    $t8, 8($t5)
  lw    $t9, 0x28($sp)
  lw    $t3, 4($t9)
  lw    $t1, ($t3)
  beqz  $t1, .L7000DEE8
   nop   
  jal   __osPopThread
   addiu $a0, $t9, 4
  move  $s1, $v0
  jal   osStartThread
   move  $a0, $s1
.L7000DEE8:
  jal   __osRestoreInt
   move  $a0, $s0
  move  $v0, $zero
.L7000DEF4:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
