


.section .text, "ax"    

glabel osSpTaskYielded
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  jal   __osSpGetStatus
   sw    $a0, 0x20($sp)
  sw    $v0, 0x1c($sp)
  lw    $t6, 0x1c($sp)
  andi  $t7, $t6, 0x100
  beqz  $t7, .L7000E370
   nop   
  li    $t8, 1
  b     .L7000E374
   sw    $t8, 0x18($sp)
.L7000E370:
  sw    $zero, 0x18($sp)
.L7000E374:
  lw    $t9, 0x1c($sp)
  andi  $t0, $t9, 0x80
  beqz  $t0, .L7000E3AC
   nop   
  lw    $t1, 0x20($sp)
  lw    $t3, 0x18($sp)
  li    $at, -3
  lw    $t2, 4($t1)
  or    $t4, $t2, $t3
  sw    $t4, 4($t1)
  lw    $t5, 0x20($sp)
  lw    $t6, 4($t5)
  and   $t7, $t6, $at
  sw    $t7, 4($t5)
.L7000E3AC:
  lw    $ra, 0x14($sp)
  lw    $v0, 0x18($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
