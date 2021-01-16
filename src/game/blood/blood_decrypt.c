asm(R"
glabel decrypt_bleeding_animation_data
  addiu $sp, $sp, -0x18
  sw    $s3, 0x14($sp)
  sw    $s2, 0x10($sp)
  sw    $s1, 0xc($sp)
  sw    $s0, 8($sp)
  sw    $a1, 0x1c($sp)
  sw    $a2, 0x20($sp)
  lbu   $v0, ($a0)
  lw    $t7, 0x28($sp)
  move  $s0, $a3
  andi  $s1, $a2, 0xff
  andi  $t1, $a1, 0xff
  addiu $a0, $a0, 1
  li    $s2, 255
  li    $s3, 255
  sb    $v0, ($t7)
  lbu   $a1, ($a0)
.L7F01CB24:
  addiu $a0, $a0, 1
  andi  $a2, $s3, 0xff
  bne   $s2, $a1, .L7F01CBDC
   andi  $t8, $a1, 0x1f
  lbu   $v1, ($a0)
  move  $a3, $zero
  addiu $a0, $a0, 1
  beq   $s2, $v1, .L7F01CB9C
   move  $a1, $v1
.L7F01CB48:
  addu  $a3, $a3, $a1
  addiu $v1, $v1, -1
  andi  $t8, $a3, 0xff
  andi  $t9, $v1, 0xff
  slt   $t0, $zero, $a1
  move  $a3, $t8
  beqz  $t0, .L7F01CB84
   move  $v1, $t9
.L7F01CB68:
  slt   $t0, $zero, $v1
  addiu $v1, $v1, -1
  andi  $t6, $v1, 0xff
  move  $v1, $t6
  sb    $a2, ($s0)
  bnez  $t0, .L7F01CB68
   addiu $s0, $s0, 1
.L7F01CB84:
  lbu   $v1, ($a0)
  xori  $t7, $a2, 0xff
  andi  $a2, $t7, 0xff
  addiu $a0, $a0, 1
  bne   $s2, $v1, .L7F01CB48
   move  $a1, $v1
.L7F01CB9C:
  slt   $t0, $a3, $t1
  addiu $a3, $a3, 1
  andi  $t9, $a3, 0xff
  beqz  $t0, .L7F01CBCC
   move  $a3, $t9
.L7F01CBB0:
  slt   $t0, $a3, $t1
  addiu $a3, $a3, 1
  andi  $t6, $a3, 0xff
  move  $a3, $t6
  sb    $a2, ($s0)
  bnez  $t0, .L7F01CBB0
   addiu $s0, $s0, 1
.L7F01CBCC:
  addiu $s1, $s1, -1
  andi  $t7, $s1, 0xff
  b     .L7F01CC70
   move  $s1, $t7
.L7F01CBDC:
  addu  $a3, $v0, $t8
  sra   $v1, $a1, 5
  andi  $t9, $a3, 0xff
  addiu $v1, $v1, 1
  andi  $t6, $v1, 0xff
  subu  $a2, $t1, $t9
  subu  $s1, $s1, $t6
  andi  $t8, $a2, 0xff
  andi  $t7, $s1, 0xff
  move  $v1, $t6
  move  $s1, $t7
  slt   $t4, $zero, $t8
  addiu $t5, $t8, -1
  slt   $t2, $zero, $t9
  addiu $t3, $t9, -1
.L7F01CC18:
  beqz  $t2, .L7F01CC3C
   andi  $a2, $t3, 0xff
.L7F01CC20:
  slt   $t0, $zero, $a2
  addiu $a2, $a2, -1
  andi  $t9, $a2, 0xff
  move  $a2, $t9
  sb    $s3, ($s0)
  bnez  $t0, .L7F01CC20
   addiu $s0, $s0, 1
.L7F01CC3C:
  beqz  $t4, .L7F01CC60
   andi  $a2, $t5, 0xff
.L7F01CC44:
  slt   $t0, $zero, $a2
  addiu $a2, $a2, -1
  andi  $t6, $a2, 0xff
  move  $a2, $t6
  sb    $zero, ($s0)
  bnez  $t0, .L7F01CC44
   addiu $s0, $s0, 1
.L7F01CC60:
  addiu $v1, $v1, -1
  andi  $t7, $v1, 0xff
  bgtz  $t7, .L7F01CC18
   move  $v1, $t7
.L7F01CC70:
  bgtzl $s1, .L7F01CB24
   lbu   $a1, ($a0)
  lw    $s0, 8($sp)
  lw    $s1, 0xc($sp)
  lw    $s2, 0x10($sp)
  lw    $s3, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   move  $v0, $a0
");

asm(R"
glabel sub_GAME_7F01CC94
  sw    $a1, 4($sp)
  andi  $t6, $a1, 0xffff
  addiu $a1, $t6, -1
  andi  $t7, $a1, 0xffff
  slt   $v0, $zero, $t6
  beqz  $v0, .L7F01CCE4
   move  $a1, $t7
.L7F01CCB0:
  lbu   $t8, 1($a0)
  lbu   $t0, ($a0)
  slt   $v0, $zero, $a1
  addiu $a1, $a1, -1
  sra   $t9, $t8, 4
  andi  $t1, $t0, 0xf0
  or    $t2, $t9, $t1
  andi  $t3, $a1, 0xffff
  sb    $t2, ($a2)
  addiu $a2, $a2, 1
  move  $a1, $t3
  bnez  $v0, .L7F01CCB0
   addiu $a0, $a0, 2
.L7F01CCE4:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F01CCEC
  addiu $sp, $sp, -0x28
  andi  $t7, $a2, 0xff
  sw    $fp, 0x24($sp)
  sw    $s7, 0x20($sp)
  sw    $s6, 0x1c($sp)
  sw    $s5, 0x18($sp)
  sw    $s4, 0x14($sp)
  sw    $s3, 0x10($sp)
  sw    $s2, 0xc($sp)
  sw    $s1, 8($sp)
  sw    $s0, 4($sp)
  sw    $a1, 0x2c($sp)
  sw    $a2, 0x30($sp)
  andi  $t6, $a1, 0xff
  move  $v1, $t7
  blez  $t7, .L7F01CEC0
   move  $v0, $zero
  move  $a2, $t6
  lbu   $t2, 0x3b($sp)
.L7F01CD38:
  blez  $a2, .L7F01CEA8
   move  $a1, $zero
  multu $v0, $a2
  move  $t3, $t2
  subu  $t4, $v0, $t2
  addiu $s0, $v1, -1
  addu  $s1, $v0, $t2
  mflo  $fp
  nop   
  nop   
  move  $t0, $zero
.L7F01CD64:
  bgez  $t4, .L7F01CD74
   move  $t1, $zero
  b     .L7F01CD80
   move  $t5, $zero
.L7F01CD74:
  sll   $t5, $t4, 0x10
  sra   $t8, $t5, 0x10
  move  $t5, $t8
.L7F01CD80:
  slt   $at, $s0, $s1
  beqz  $at, .L7F01CD94
   move  $s2, $s1
  b     .L7F01CD94
   move  $s2, $s0
.L7F01CD94:
  slt   $at, $s2, $t5
  bnezl $at, .L7F01CE68
   srl   $t9, $t0, 1
  subu  $s3, $a1, $t3
  addiu $s5, $a2, -1
  addu  $s6, $a1, $t3
.L7F01CDAC:
  bgez  $s3, .L7F01CDBC
   slt   $at, $s5, $s6
  b     .L7F01CDC8
   move  $s4, $zero
.L7F01CDBC:
  sll   $s4, $s3, 0x10
  sra   $t9, $s4, 0x10
  move  $s4, $t9
.L7F01CDC8:
  beqz  $at, .L7F01CDD8
   move  $s2, $s6
  b     .L7F01CDD8
   move  $s2, $s5
.L7F01CDD8:
  slt   $at, $s2, $s4
  bnezl $at, .L7F01CE38
   addiu $t5, $t5, 1
  multu $t5, $a2
  mflo  $s7
  nop   
  nop   
  addu  $t6, $a0, $s4
.L7F01CDF8:
  addu  $t7, $t6, $s7
  lbu   $t8, ($t7)
  addiu $s4, $s4, 1
  sll   $t9, $s4, 0x10
  slt   $at, $s5, $s6
  sra   $s4, $t9, 0x10
  addiu $t0, $t0, 1
  beqz  $at, .L7F01CE24
   addu  $t1, $t1, $t8
  b     .L7F01CE28
   move  $s2, $s5
.L7F01CE24:
  move  $s2, $s6
.L7F01CE28:
  slt   $at, $s2, $s4
  beql  $at, $zero, .L7F01CDF8
   addu  $t6, $a0, $s4
  addiu $t5, $t5, 1
.L7F01CE38:
  sll   $t7, $t5, 0x10
  sra   $t8, $t7, 0x10
  slt   $at, $s0, $s1
  beqz  $at, .L7F01CE54
   move  $t5, $t8
  b     .L7F01CE58
   move  $s2, $s0
.L7F01CE54:
  move  $s2, $s1
.L7F01CE58:
  slt   $at, $s2, $t5
  beqz  $at, .L7F01CDAC
   nop   
  srl   $t9, $t0, 1
.L7F01CE68:
  addu  $t6, $t9, $t1
  divu  $zero, $t6, $t0
  addu  $t8, $a3, $a1
  addiu $a1, $a1, 1
  sll   $t6, $a1, 0x10
  addu  $t9, $t8, $fp
  sra   $t8, $t6, 0x10
  slt   $at, $t8, $a2
  mflo  $t7
  move  $a1, $t8
  bnez  $t0, .L7F01CE9C
   nop   
  break 7
.L7F01CE9C:
  sb    $t7, ($t9)
  bnezl $at, .L7F01CD64
   move  $t0, $zero
.L7F01CEA8:
  addiu $v0, $v0, 1
  sll   $t7, $v0, 0x10
  sra   $v0, $t7, 0x10
  slt   $at, $v0, $v1
  bnez  $at, .L7F01CD38
   nop   
.L7F01CEC0:
  lw    $s0, 4($sp)
  lw    $s1, 8($sp)
  lw    $s2, 0xc($sp)
  lw    $s3, 0x10($sp)
  lw    $s4, 0x14($sp)
  lw    $s5, 0x18($sp)
  lw    $s6, 0x1c($sp)
  lw    $s7, 0x20($sp)
  lw    $fp, 0x24($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
glabel sub_GAME_7F01CEEC
  addiu $v1, $a1, -1
  slti  $at, $v1, 2
  addiu $a0, $a0, 0x61
  addiu $a2, $a2, 0x61
  bnez  $at, .L7F01D024
   li    $v0, 1
  li    $a3, 95
.L7F01CF08:
  lbu   $t6, -0x60($a0)
  lbu   $t7, -1($a0)
  lbu   $t9, ($a0)
  lbu   $t1, -0x61($a0)
  addu  $t8, $t6, $t7
  addu  $t0, $t8, $t9
  addu  $t2, $t0, $t1
  addiu $t3, $t2, 2
  sra   $t4, $t3, 2
  sb    $t4, ($a2)
  lbu   $t6, ($a0)
  lbu   $t5, -0x5f($a0)
  lbu   $t8, 1($a0)
  lbu   $t0, -0x60($a0)
  addu  $t7, $t5, $t6
  addu  $t9, $t7, $t8
  addu  $t1, $t9, $t0
  addiu $t2, $t1, 2
  sra   $t3, $t2, 2
  sb    $t3, 1($a2)
  li    $a1, 3
  addiu $a2, $a2, 2
  addiu $a0, $a0, 2
.L7F01CF64:
  lbu   $t4, -0x60($a0)
  lbu   $t5, -1($a0)
  lbu   $t7, ($a0)
  lbu   $t9, -0x61($a0)
  addu  $t6, $t4, $t5
  addu  $t8, $t6, $t7
  addu  $t0, $t8, $t9
  addiu $t1, $t0, 2
  sra   $t2, $t1, 2
  sb    $t2, ($a2)
  lbu   $t3, -0x5f($a0)
  lbu   $t4, ($a0)
  lbu   $t6, 1($a0)
  lbu   $t8, -0x60($a0)
  addu  $t5, $t3, $t4
  addu  $t7, $t5, $t6
  addu  $t9, $t7, $t8
  addiu $t0, $t9, 2
  sra   $t1, $t0, 2
  sb    $t1, 1($a2)
  lbu   $t2, -0x5e($a0)
  lbu   $t3, 1($a0)
  lbu   $t5, 2($a0)
  lbu   $t7, -0x5f($a0)
  addu  $t4, $t2, $t3
  addu  $t6, $t4, $t5
  addu  $t8, $t6, $t7
  addiu $t9, $t8, 2
  sra   $t0, $t9, 2
  sb    $t0, 2($a2)
  lbu   $t2, 2($a0)
  lbu   $t1, -0x5d($a0)
  lbu   $t4, 3($a0)
  lbu   $t6, -0x5e($a0)
  addu  $t3, $t1, $t2
  addu  $t5, $t3, $t4
  addu  $t7, $t5, $t6
  addiu $t8, $t7, 2
  sra   $t9, $t8, 2
  addiu $a1, $a1, 4
  sb    $t9, 3($a2)
  addiu $a2, $a2, 4
  bne   $a1, $a3, .L7F01CF64
   addiu $a0, $a0, 4
  addiu $v0, $v0, 1
  addiu $a2, $a2, 2
  bne   $v0, $v1, .L7F01CF08
   addiu $a0, $a0, 2
.L7F01D024:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F01D02C
  addiu $v1, $a1, -1
  slti  $at, $v1, 2
  addiu $a0, $a0, 0x61
  addiu $a2, $a2, 0x61
  bnez  $at, .L7F01D164
   li    $v0, 1
  li    $a3, 95
.L7F01D048:
  lbu   $t6, 0x60($a0)
  lbu   $t7, 1($a0)
  lbu   $t9, ($a0)
  lbu   $t1, 0x61($a0)
  addu  $t8, $t6, $t7
  addu  $t0, $t8, $t9
  addu  $t2, $t0, $t1
  addiu $t3, $t2, 2
  sra   $t4, $t3, 2
  sb    $t4, ($a2)
  lbu   $t6, 2($a0)
  lbu   $t5, 0x61($a0)
  lbu   $t8, 1($a0)
  lbu   $t0, 0x62($a0)
  addu  $t7, $t5, $t6
  addu  $t9, $t7, $t8
  addu  $t1, $t9, $t0
  addiu $t2, $t1, 2
  sra   $t3, $t2, 2
  sb    $t3, 1($a2)
  li    $a1, 3
  addiu $a2, $a2, 2
  addiu $a0, $a0, 2
.L7F01D0A4:
  lbu   $t4, 0x60($a0)
  lbu   $t5, 1($a0)
  lbu   $t7, ($a0)
  lbu   $t9, 0x61($a0)
  addu  $t6, $t4, $t5
  addu  $t8, $t6, $t7
  addu  $t0, $t8, $t9
  addiu $t1, $t0, 2
  sra   $t2, $t1, 2
  sb    $t2, ($a2)
  lbu   $t4, 2($a0)
  lbu   $t3, 0x61($a0)
  lbu   $t6, 1($a0)
  lbu   $t8, 0x62($a0)
  addu  $t5, $t3, $t4
  addu  $t7, $t5, $t6
  addu  $t9, $t7, $t8
  addiu $t0, $t9, 2
  sra   $t1, $t0, 2
  sb    $t1, 1($a2)
  lbu   $t3, 3($a0)
  lbu   $t2, 0x62($a0)
  lbu   $t5, 2($a0)
  lbu   $t7, 0x63($a0)
  addu  $t4, $t2, $t3
  addu  $t6, $t4, $t5
  addu  $t8, $t6, $t7
  addiu $t9, $t8, 2
  sra   $t0, $t9, 2
  sb    $t0, 2($a2)
  lbu   $t2, 4($a0)
  lbu   $t1, 0x63($a0)
  lbu   $t4, 3($a0)
  lbu   $t6, 0x64($a0)
  addu  $t3, $t1, $t2
  addu  $t5, $t3, $t4
  addu  $t7, $t5, $t6
  addiu $t8, $t7, 2
  sra   $t9, $t8, 2
  addiu $a1, $a1, 4
  sb    $t9, 3($a2)
  addiu $a2, $a2, 4
  bne   $a1, $a3, .L7F01D0A4
   addiu $a0, $a0, 4
  addiu $v0, $v0, 1
  addiu $a2, $a2, 2
  bne   $v0, $v1, .L7F01D048
   addiu $a0, $a0, 2
.L7F01D164:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F01D16C
  multu $a1, $a2
  move  $v1, $a0
  move  $t0, $a3
  addu  $t2, $a0, $a1
  mflo  $v0
  addu  $t1, $a0, $v0
  nop   
.L7F01D188:
  move  $a0, $t2
.L7F01D18C:
  lbu   $t6, ($v1)
  addiu $v1, $v1, 1
  sltu  $at, $v1, $a0
  sb    $t6, ($t0)
  addiu $t2, $t2, 1
  bnez  $at, .L7F01D18C
   addu  $t0, $t0, $a2
  subu  $t0, $t0, $v0
  sltu  $at, $v1, $t1
  bnez  $at, .L7F01D188
   addiu $t0, $t0, 1
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F01D1C0
  addiu $sp, $sp, -0x10
  li    $t4, 255
  lbu   $t0, ($a0)
  addiu $a0, $a0, 1
.L7F01D1D0:
  lbu   $t1, ($a0)
  addiu $a0, $a0, 1
  bne   $t1, $t4, .L7F01D244
   li    $t3, 255
  lbu   $t1, ($a0)
  li    $t2, 0
  beq   $t1, $t4, .L7F01D21C
   addiu $a0, $a0, 1
.L7F01D1F0:
  addu  $t2, $t2, $t1
  blez  $t1, .L7F01D20C
   addiu $t1, $t1, -1
.L7F01D1FC:
  sb    $t3, ($a3)
  addiu $a3, $a3, 1
  bgtz  $t1, .L7F01D1FC
   addiu $t1, $t1, -1
.L7F01D20C:
  lbu   $t1, ($a0)
  xori  $t3, $t3, 0xff
  bne   $t1, $t4, .L7F01D1F0
   addiu $a0, $a0, 1
.L7F01D21C:
  slt   $at, $t2, $a1
  beqz  $at, .L7F01D23C
   addiu $t2, $t2, 1
.L7F01D228:
  sb    $t3, ($a3)
  addiu $a3, $a3, 1
  slt   $at, $t2, $a1
  bnez  $at, .L7F01D228
   addiu $t2, $t2, 1
.L7F01D23C:
  j     func_7F01D29C
   addiu $a2, $a2, -1

.L7F01D244:
  andi  $t2, $t1, 0x1f
  addu  $t2, $t2, $t0
  srl   $t1, $t1, 5
  addiu $t1, $t1, 1
  subu  $a2, $a2, $t1
.L7F01D258:
  move  $t3, $t2
  blez  $t3, .L7F01D274
   addiu $t3, $t3, -1
.L7F01D264:
  sb    $t4, ($a3)
  addiu $a3, $a3, 1
  bgtz  $t3, .L7F01D264
   addiu $t3, $t3, -1
.L7F01D274:
  subu  $t3, $a1, $t2
  blez  $t3, .L7F01D290
   addiu $t3, $t3, -1
.L7F01D280:
  sb    $zero, ($a3)
  addiu $a3, $a3, 1
  bgtz  $t3, .L7F01D280
   addiu $t3, $t3, -1
.L7F01D290:
  addiu $t1, $t1, -1
  bgtz  $t1, .L7F01D258
   nop   
glabel func_7F01D29C
  bgtz  $a2, .L7F01D1D0
   move  $v0, $a0
  jr    $ra
   addiu $sp, $sp, 0x10
");
