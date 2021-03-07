


.section .text 

glabel osCreateThread
  addiu $sp, $sp, -0x28
  sw    $a0, 0x28($sp)
  sw    $a1, 0x2c($sp)
  lw    $t6, 0x2c($sp)
  lw    $t7, 0x28($sp)
  sw    $ra, 0x1c($sp)
  sw    $a2, 0x30($sp)
  sw    $a3, 0x34($sp)
  sw    $s0, 0x18($sp)
  sw    $t6, 0x14($t7)
  lw    $t9, 0x28($sp)
  lw    $t8, 0x3c($sp)
  sw    $t8, 4($t9)
  lw    $t0, 0x28($sp)
  sw    $zero, ($t0)
  lw    $t1, 0x28($sp)
  sw    $zero, 8($t1)
  lw    $t3, 0x28($sp)
  lw    $t2, 0x30($sp)
  sw    $t2, 0x11c($t3)
  lw    $t4, 0x34($sp)
  lw    $t5, 0x28($sp)
  move  $t7, $t4
  sra   $t6, $t4, 0x1f
  sw    $t6, 0x38($t5)
  sw    $t7, 0x3c($t5)
  lw    $t8, 0x38($sp)
  lw    $t9, 0x28($sp)
  lui   $t4, %hi(__osCleanupThread) # $t4, 0x7001
  move  $t1, $t8
  sltiu $at, $t1, 0x10
  sra   $t0, $t8, 0x1f
  subu  $t2, $t0, $at
  addiu $t3, $t1, -0x10
  sw    $t3, 0xf4($t9)
  sw    $t2, 0xf0($t9)
  lw    $t5, 0x28($sp)
  addiu $t4, %lo(__osCleanupThread) # addiu $t4, $t4, 0xa80
  move  $t7, $t4
  sra   $t6, $t4, 0x1f
  sw    $t6, 0x100($t5)
  sw    $t7, 0x104($t5)
  lw    $t1, 0x28($sp)
  lui   $t8, (0x003FFF01 >> 16) # lui $t8, 0x3f
  ori   $t8, (0x003FFF01 & 0xFFFF) # ori $t8, $t8, 0xff01
  sw    $t8, 0x20($sp)
  li    $t0, 65283
  sw    $t0, 0x118($t1)
  lw    $t2, 0x20($sp)
  lw    $t4, 0x28($sp)
  lui   $at, 0x3f
  and   $t3, $t2, $at
  srl   $t9, $t3, 0x10
  sw    $t9, 0x128($t4)
  lw    $t7, 0x28($sp)
  lui   $t6, (0x01000800 >> 16) # lui $t6, 0x100
  ori   $t6, (0x01000800 & 0xFFFF) # ori $t6, $t6, 0x800
  sw    $t6, 0x12c($t7)
  lw    $t5, 0x28($sp)
  li    $t8, 1
  sw    $zero, 0x18($t5)
  lw    $t0, 0x28($sp)
  sh    $t8, 0x10($t0)
  lw    $t1, 0x28($sp)
  jal   __osDisableInt
   sh    $zero, 0x12($t1)
  lui   $t2, %hi(__osActiveQueue) 
  lw    $t2, %lo(__osActiveQueue)($t2)
  lw    $t3, 0x28($sp)
  move  $s0, $v0
  lui   $at, %hi(__osActiveQueue)
  sw    $t2, 0xc($t3)
  lw    $t9, 0x28($sp)
  move  $a0, $s0
  jal   __osRestoreInt
   sw    $t9, %lo(__osActiveQueue)($at)
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
