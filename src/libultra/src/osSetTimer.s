.section .text 

glabel osSetTimer
  addiu $sp, $sp, -0x20
  sw    $a0, 0x20($sp)
  lw    $t6, 0x20($sp)
  sw    $ra, 0x14($sp)
  sw    $a2, 0x28($sp)
  sw    $a3, 0x2c($sp)
  sw    $zero, ($t6)
  lw    $t7, 0x20($sp)
  sw    $zero, 4($t7)
  lw    $t0, 0x20($sp)
  lw    $t9, 0x34($sp)
  lw    $t8, 0x30($sp)
  sw    $t9, 0xc($t0)
  sw    $t8, 8($t0)
  lw    $t2, 0x28($sp)
  lw    $t3, 0x2c($sp)
  bnez  $t2, .L70010CA0
   nop   
  beqz  $t3, .L70010CB0
   nop   
.L70010CA0:
  lw    $t1, 0x20($sp)
  sw    $t2, 0x10($t1)
  b     .L70010CC4
   sw    $t3, 0x14($t1)
.L70010CB0:
  lw    $t6, 0x20($sp)
  lw    $t4, 0x30($sp)
  lw    $t5, 0x34($sp)
  sw    $t4, 0x10($t6)
  sw    $t5, 0x14($t6)
.L70010CC4:
  lw    $t7, 0x38($sp)
  lw    $t8, 0x20($sp)
  sw    $t7, 0x18($t8)
  lw    $t0, 0x20($sp)
  lw    $t9, 0x3c($sp)
  sw    $t9, 0x1c($t0)
  jal   __osInsertTimer
   lw    $a0, 0x20($sp)
  lui   $t2, %hi(__osTimerList) 
  lw    $t2, %lo(__osTimerList)($t2)
  sw    $v0, 0x18($sp)
  sw    $v1, 0x1c($sp)
  lw    $t1, 0x20($sp)
  lw    $t3, ($t2)
  bne   $t3, $t1, .L70010D10
   nop   
  lw    $a0, 0x18($sp)
  jal   __osSetTimerIntr
   lw    $a1, 0x1c($sp)
.L70010D10:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  move  $v0, $zero
  jr    $ra
   nop   
