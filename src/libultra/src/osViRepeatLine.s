


.section .text, "ax"  
glabel osViRepeatLine
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  sw    $a0, 0x28($sp)
  jal   __osDisableInt
   sw    $s0, 0x18($sp)
  lbu   $t6, 0x2b($sp)
  move  $s0, $v0
  beqz  $t6, .L7000E29C
   nop   
  lui   $t7, %hi(__osViNext) 
  lw    $t7, %lo(__osViNext)($t7)
  lhu   $t8, ($t7)
  ori   $t9, $t8, 0x40
  b     .L7000E2B4
   sh    $t9, ($t7)
.L7000E29C:
  lui   $t0, %hi(__osViNext) 
  lw    $t0, %lo(__osViNext)($t0)
  li    $at, -65
  lhu   $t1, ($t0)
  and   $t2, $t1, $at
  sh    $t2, ($t0)
.L7000E2B4:
  jal   __osRestoreInt
   move  $a0, $s0
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
