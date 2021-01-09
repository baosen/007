asm(R"
glabel sub_GAME_7F01B0E0
  lhu   $v0, ($a0)
  lhu   $v1, 2($a0)
  addiu $a3, $a0, 0xa
  multu $v0, $v1
  mflo  $a2
  nop   
  nop   
  lbu   $v0, ($a3)
.L7F01B100:
  lbu   $v1, 1($a3)
  addiu $a3, $a3, 2
  subu  $a2, $a2, $v0
  addiu $v0, $v0, -1
.L7F01B110:
  slt   $a0, $zero, $v0
  addiu $v0, $v0, -1
  sb    $v1, ($a1)
  bnez  $a0, .L7F01B110
   addiu $a1, $a1, 1
  bgtzl $a2, .L7F01B100
   lbu   $v0, ($a3)
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F01B134
  addiu $sp, $sp, -8
  sw    $s0, 4($sp)
  lhu   $v0, ($a0)
  lhu   $v1, 2($a0)
  move  $s0, $a1
  addiu $a3, $a0, 0xa
  multu $v0, $v1
  mflo  $a2
  nop   
  nop   
  lbu   $a0, 2($a3)
.L7F01B160:
  lbu   $a1, 3($a3)
  lbu   $v1, 1($a3)
  sra   $t8, $a0, 3
  sra   $t6, $a1, 3
  lbu   $v0, ($a3)
  sll   $t7, $t6, 0xb
  sll   $t9, $t8, 6
  sra   $t2, $v1, 3
  sll   $t3, $t2, 1
  or    $t1, $t7, $t9
  or    $t0, $t1, $t3
  ori   $t4, $t0, 1
  subu  $a2, $a2, $v0
  addiu $a3, $a3, 4
  move  $t0, $t4
  addiu $v0, $v0, -1
.L7F01B1A0:
  slt   $v1, $zero, $v0
  addiu $v0, $v0, -1
  sh    $t0, ($s0)
  bnez  $v1, .L7F01B1A0
   addiu $s0, $s0, 2
  bgtzl $a2, .L7F01B160
   lbu   $a0, 2($a3)
  lw    $s0, 4($sp)
  jr    $ra
   addiu $sp, $sp, 8
");

asm(R"
glabel sub_GAME_7F01B1C8
  lhu   $v1, ($a0)
  lhu   $a2, 2($a0)
  move  $v0, $a1
  addiu $t0, $a0, 0xa
  multu $v1, $a2
  li    $t2, 255
  mflo  $a3
  nop   
  nop   
  lbu   $v1, ($t0)
.L7F01B1F0:
  lbu   $a0, 1($t0)
  lbu   $a1, 2($t0)
  subu  $a3, $a3, $v1
  lbu   $a2, 3($t0)
  addiu $t0, $t0, 4
  addiu $v1, $v1, -1
.L7F01B208:
  slt   $t1, $zero, $v1
  sb    $a2, ($v0)
  sb    $a1, 1($v0)
  sb    $a0, 2($v0)
  sb    $t2, 3($v0)
  addiu $v1, $v1, -1
  bnez  $t1, .L7F01B208
   addiu $v0, $v0, 4
  bgtzl $a3, .L7F01B1F0
   lbu   $v1, ($t0)
  jr    $ra
   nop   
");
