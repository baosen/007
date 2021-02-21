float D_8004EAF0 = 0.0;
float D_8004EAF4 = 0.0;

asm(R"
glabel sub_GAME_7F0D1AC0
  mtc1  $zero, $f4
  lui   $t0, %hi(D_8004EAF4) 
  addiu $t0, %lo(D_8004EAF4) # addiu $t0, $t0, -0x150c
  swc1  $f4, ($t0)
  lwc1  $f6, ($t0)
  lui   $at, %hi(D_8004EAF0)
  move  $v0, $a0
  lui   $t6, (0xBA000C02 >> 16) # lui $t6, 0xba00
  swc1  $f6, %lo(D_8004EAF0)($at)
  ori   $t6, (0xBA000C02 & 0xFFFF) # ori $t6, $t6, 0xc02
  addiu $v1, $a0, 8
  sw    $t6, ($v0)
  sw    $zero, 4($v0)
  lui   $t7, (0xBA000602 >> 16) # lui $t7, 0xba00
  ori   $t7, (0xBA000602 & 0xFFFF) # ori $t7, $t7, 0x602
  addiu $a1, $v1, 8
  li    $t8, 192
  sw    $t8, 4($v1)
  sw    $t7, ($v1)
  lui   $t9, 0xb600
  li    $t1, 1
  sw    $t1, 4($a1)
  sw    $t9, ($a1)
  addiu $a0, $a1, 8
  addiu $a3, $a0, 8
  lui   $t2, 0xe700
  sw    $t2, ($a0)
  sw    $zero, 4($a0)
  lui   $t3, (0xBA001301 >> 16) # lui $t3, 0xba00
  ori   $t3, (0xBA001301 & 0xFFFF) # ori $t3, $t3, 0x1301
  addiu $v1, $a3, 8
  sw    $t3, ($a3)
  sw    $zero, 4($a3)
  lui   $t4, (0xBA001402 >> 16) # lui $t4, 0xba00
  ori   $t4, (0xBA001402 & 0xFFFF) # ori $t4, $t4, 0x1402
  addiu $a1, $v1, 8
  lui   $t5, 0x30
  sw    $t5, 4($v1)
  sw    $t4, ($v1)
  lui   $t7, (0x0F0A4000 >> 16) # lui $t7, 0xf0a
  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
  ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
  ori   $t7, (0x0F0A4000 & 0xFFFF) # ori $t7, $t7, 0x4000
  addiu $a2, $a1, 8
  lui   $t8, (0xBA001701 >> 16) # lui $t8, 0xba00
  sw    $t7, 4($a1)
  sw    $t6, ($a1)
  ori   $t8, (0xBA001701 & 0xFFFF) # ori $t8, $t8, 0x1701
  lui   $t9, 0x80
  sw    $t9, 4($a2)
  sw    $t8, ($a2)
  jr    $ra
   addiu $v0, $a2, 8
");

asm(R"
glabel sub_GAME_7F0D1B94
  mtc1  $a1, $f12
  addiu $sp, $sp, -0x28
  lw    $t6, 0x38($sp)
  sw    $ra, 0x24($sp)
  li    $t7, 2
  li    $t8, 1
  mfc1  $a1, $f12
  sw    $t8, 0x18($sp)
  sw    $t7, 0x14($sp)
  jal   sub_GAME_7F0D1BD0
   sw    $t6, 0x10($sp)
  lw    $ra, 0x24($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0D1BD0
  mtc1  $a1, $f12
  mtc1  $zero, $f4
  addiu $sp, $sp, -0x10
  sw    $s2, 0xc($sp)
  c.lt.s $f4, $f12
  sw    $s1, 8($sp)
  sw    $s0, 4($sp)
  sw    $a2, 0x18($sp)
  bc1f  .L7F0D1DB4
   sw    $a3, 0x1c($sp)
  lui   $a1, %hi(D_8004EAF4)
  addiu $a1, %lo(D_8004EAF4) # addiu $a1, $a1, -0x150c
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f14
  lwc1  $f0, ($a1)
  li    $at, 0x435B0000 # 219.000000
  mtc1  $at, $f10
  div.s $f6, $f0, $f14
  move  $t0, $a0
  lui   $t8, 0xf700
  sw    $t8, ($t0)
  mul.s $f16, $f0, $f10
  add.s $f2, $f0, $f12
  lw    $t9, 0x18($sp)
  lw    $t8, 0x1c($sp)
  addiu $a0, $a0, 8
  sll   $t6, $t9, 8
  andi  $t7, $t6, 0xf800
  sll   $t9, $t8, 3
  andi  $t6, $t9, 0x7c0
  lw    $t9, 0x20($sp)
  or    $t8, $t7, $t6
  sra   $t7, $t9, 2
  andi  $t6, $t7, 0x3e
  or    $t1, $t8, $t6
  ori   $t9, $t1, 1
  sll   $t7, $t9, 0x10
  or    $t8, $t7, $t9
  div.s $f18, $f16, $f14
  sw    $t8, 4($t0)
  trunc.w.s $f8, $f6
  mfc1  $a2, $f8
  nop   
  move  $v0, $a2
  div.s $f6, $f2, $f14
  trunc.w.s $f4, $f18
  mfc1  $a3, $f4
  trunc.w.s $f8, $f6
  mfc1  $v1, $f8
  nop   
  slt   $at, $v1, $a2
  bnez  $at, .L7F0D1DA8
   slti  $at, $a2, 3
  beqz  $at, .L7F0D1DA8
   li    $at, 0x435B0000 # 219.000000
  mtc1  $at, $f10
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f18
  mul.s $f16, $f2, $f10
  sll   $t0, $v0, 3
  subu  $t0, $t0, $v0
  sll   $t0, $t0, 3
  subu  $t0, $t0, $v0
  sll   $t0, $t0, 2
  subu  $t0, $t0, $v0
  div.s $f4, $f16, $f18
  subu  $t1, $a3, $t0
  addiu $t1, $t1, 0x32
  li    $s2, 7
  lui   $s1, 0xf600
  lw    $t5, 0x28($sp)
  lw    $t4, 0x24($sp)
  trunc.w.s $f6, $f4
  mfc1  $a2, $f6
  nop   
  subu  $t3, $a2, $t0
.L7F0D1D00:
  addiu $t3, $t3, 0x32
  slti  $at, $t1, 0x32
  move  $a3, $t1
  beqz  $at, .L7F0D1D18
   move  $t2, $t3
  li    $a3, 50
.L7F0D1D18:
  slti  $at, $t3, 0x10e
  bnez  $at, .L7F0D1D28
   addiu $t0, $t0, 0xdb
  li    $t2, 269
.L7F0D1D28:
  slt   $at, $t2, $a3
  bnezl $at, .L7F0D1D90
   addiu $v0, $v0, 1
  multu $v0, $s2
  andi  $t7, $t2, 0x3ff
  sll   $t8, $t7, 0xe
  addu  $t9, $t4, $t5
  or    $t6, $t8, $s1
  move  $t3, $a0
  addiu $a0, $a0, 8
  mflo  $s0
  addu  $t7, $t9, $s0
  addiu $t8, $t7, 0x11
  andi  $t9, $t8, 0x3ff
  sll   $t7, $t9, 2
  or    $t8, $t6, $t7
  sw    $t8, ($t3)
  addu  $t7, $t5, $s0
  andi  $t9, $a3, 0x3ff
  sll   $t6, $t9, 0xe
  addiu $t8, $t7, 0x12
  andi  $t9, $t8, 0x3ff
  sll   $t7, $t9, 2
  or    $t8, $t6, $t7
  sw    $t8, 4($t3)
  addiu $v0, $v0, 1
.L7F0D1D90:
  slt   $at, $v1, $v0
  bnez  $at, .L7F0D1DA8
   addiu $t1, $t1, -0xdb
  slti  $at, $v0, 3
  bnezl $at, .L7F0D1D00
   subu  $t3, $a2, $t0
.L7F0D1DA8:
  lwc1  $f8, ($a1)
  add.s $f10, $f8, $f12
  swc1  $f10, ($a1)
.L7F0D1DB4:
  lw    $s0, 4($sp)
  lw    $s1, 8($sp)
  lw    $s2, 0xc($sp)
  addiu $sp, $sp, 0x10
  jr    $ra
   move  $v0, $a0
");

void sub_GAME_7F0D1DCC(float arg0) {
  if (0.0f < arg0) {
    D_8004EAF4 = (float)(D_8004EAF4 + arg0);
  }
}

asm(R"
glabel sub_GAME_7F0D1DFC
  lui   $at, %hi(D_8004EAF0)
  mtc1  $a1, $f12
  lwc1  $f4, %lo(D_8004EAF0)($at)
  lui   $at, %hi(D_8004EAF4)
  lwc1  $f8, %lo(D_8004EAF4)($at)
  add.s $f6, $f4, $f12
  addiu $sp, $sp, -0x20
  lw    $t6, 0x30($sp)
  sw    $ra, 0x1c($sp)
  sub.s $f10, $f6, $f8
  sw    $t6, 0x10($sp)
  mfc1  $a1, $f10
  jal   sub_GAME_7F0D1B94
   nop   
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0D1E44
  lui   $at, %hi(D_8004EAF0)
  mtc1  $a1, $f12
  lwc1  $f4, %lo(D_8004EAF0)($at)
  lui   $at, %hi(D_8004EAF4)
  lwc1  $f8, %lo(D_8004EAF4)($at)
  add.s $f6, $f4, $f12
  addiu $sp, $sp, -0x28
  lw    $t6, 0x38($sp)
  lw    $t7, 0x3c($sp)
  sub.s $f10, $f6, $f8
  lw    $t8, 0x40($sp)
  sw    $ra, 0x24($sp)
  sw    $t6, 0x10($sp)
  mfc1  $a1, $f10
  sw    $t7, 0x14($sp)
  jal   sub_GAME_7F0D1BD0
   sw    $t8, 0x18($sp)
  lw    $ra, 0x24($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0D1E98
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f0
  lui   $at, %hi(D_8004EAF4)
  lwc1  $f4, %lo(D_8004EAF4)($at)
  addiu $sp, $sp, -0x30
  sw    $ra, 0x2c($sp)
  div.s $f6, $f4, $f0
  sw    $fp, 0x28($sp)
  sw    $s7, 0x24($sp)
  sw    $s6, 0x20($sp)
  sw    $s5, 0x1c($sp)
  sw    $s4, 0x18($sp)
  sw    $s3, 0x14($sp)
  sw    $s2, 0x10($sp)
  sw    $s1, 0xc($sp)
  sw    $s0, 8($sp)
  move  $v0, $a0
  lui   $t7, 0xf700
  sw    $t7, ($v0)
  sll   $t6, $a2, 3
  andi  $t7, $t6, 0x7c0
  sll   $t8, $a1, 8
  andi  $t9, $t8, 0xf800
  or    $t8, $t9, $t7
  sra   $t6, $a3, 2
  andi  $t9, $t6, 0x3e
  or    $v1, $t8, $t9
  ori   $t7, $v1, 1
  sll   $t6, $t7, 0x10
  trunc.w.s $f8, $f6
  or    $t8, $t6, $t7
  sw    $t8, 4($v0)
  addiu $a0, $a0, 8
  mfc1  $t0, $f8
  nop   
  bltzl $t0, .L7F0D22F0
   lw    $ra, 0x2c($sp)
  mtc1  $zero, $f10
  li    $at, 0x435B0000 # 219.000000
  mtc1  $at, $f18
  cvt.s.w $f16, $f10
  li    $t8, 1
  mtc1  $t8, $f10
  lui   $at, 0xf600
  li    $t8, 2
  sll   $s0, $zero, 3
  mul.s $f4, $f16, $f18
  subu  $s0, $s0, $zero
  sll   $t1, $t0, 3
  subu  $t1, $t1, $t0
  addiu $t1, $t1, 0x12
  addiu $v1, $s0, 0x15
  cvt.s.w $f16, $f10
  mtc1  $t8, $f10
  addiu $v0, $s0, 0x12
  li    $ra, 39
  li    $fp, 11
  div.s $f6, $f4, $f0
  lui   $s7, 0xf600
  trunc.w.s $f8, $f6
  mfc1  $a1, $f8
  nop   
  addiu $a1, $a1, 0x32
  andi  $t7, $a1, 0x3ff
  sll   $a1, $t7, 0xe
  or    $t2, $a1, $at
  li    $at, 0x435B0000 # 219.000000
  mtc1  $at, $f18
  lui   $at, 0xf600
  mul.s $f4, $f16, $f18
  cvt.s.w $f16, $f10
  div.s $f6, $f4, $f0
  trunc.w.s $f8, $f6
  mfc1  $a2, $f8
  nop   
  addiu $a2, $a2, 0x32
  andi  $t7, $a2, 0x3ff
  sll   $a2, $t7, 0xe
  or    $t3, $a2, $at
  li    $at, 0x435B0000 # 219.000000
  mtc1  $at, $f18
  lui   $at, 0xf600
  mul.s $f4, $f16, $f18
  div.s $f6, $f4, $f0
  trunc.w.s $f8, $f6
  mfc1  $a3, $f8
  nop   
  addiu $a3, $a3, 0x32
  andi  $t7, $a3, 0x3ff
  sll   $a3, $t7, 0xe
  or    $t4, $a3, $at
  li    $at, 0x435B0000 # 219.000000
  mtc1  $at, $f2
  nop   
  move  $s0, $a0
.L7F0D2014:
  andi  $s2, $v1, 0x3ff
  andi  $s3, $v0, 0x3ff
  sll   $t7, $s3, 2
  sll   $t8, $s2, 2
  or    $t9, $t2, $t8
  or    $t6, $a1, $t7
  sw    $t6, 4($s0)
  sw    $t9, ($s0)
  addiu $a0, $a0, 8
  move  $s0, $a0
  move  $s2, $t8
  or    $t8, $t3, $t8
  or    $t9, $a2, $t7
  sw    $t9, 4($s0)
  sw    $t8, ($s0)
  addiu $a0, $a0, 8
  move  $s0, $a0
  move  $s3, $t7
  or    $t6, $a3, $s3
  or    $t7, $t4, $s2
  sw    $t7, ($s0)
  sw    $t6, 4($s0)
  addiu $a0, $a0, 8
  li    $t5, 3
  mtc1  $t5, $f14
  addiu $fp, $fp, -4
  cvt.s.w $f14, $f14
  mul.s $f14, $f14, $f2
  div.s $f14, $f14, $f0
  trunc.w.s $f14, $f14
  mfc1  $s1, $f14
  nop   
  addiu $s1, $s1, 0x32
  andi  $t9, $s1, 0x3ff
  sll   $t7, $t9, 0xe
  or    $t6, $t7, $s7
  or    $t9, $t7, $s3
  addiu $t7, $t5, 1
  mtc1  $t7, $f14
  nop   
  cvt.s.w $f14, $f14
  mul.s $f18, $f14, $f2
  beql  $t5, $fp, .L7F0D21F4
   div.s $f16, $f18, $f0
  div.s $f16, $f18, $f0
.L7F0D20C8:
  move  $s0, $a0
  or    $t8, $t6, $s2
  sw    $t8, ($s0)
  sw    $t9, 4($s0)
  addiu $a0, $a0, 8
  move  $s0, $a0
  addiu $a0, $a0, 8
  trunc.w.s $f16, $f16
  mfc1  $s4, $f16
  nop   
  addiu $s4, $s4, 0x32
  andi  $t8, $s4, 0x3ff
  sll   $t9, $t8, 0xe
  or    $t7, $t9, $s7
  or    $t8, $t9, $s3
  addiu $t9, $t5, 2
  mtc1  $t9, $f16
  or    $t6, $t7, $s2
  sw    $t6, ($s0)
  cvt.s.w $f16, $f16
  sw    $t8, 4($s0)
  move  $s0, $a0
  addiu $a0, $a0, 8
  mul.s $f16, $f16, $f2
  div.s $f16, $f16, $f0
  trunc.w.s $f16, $f16
  mfc1  $s5, $f16
  nop   
  addiu $s5, $s5, 0x32
  andi  $t6, $s5, 0x3ff
  sll   $t8, $t6, 0xe
  or    $t9, $t8, $s7
  or    $t6, $t8, $s3
  addiu $t8, $t5, 3
  mtc1  $t8, $f16
  addiu $t5, $t5, 4
  mtc1  $t5, $f14
  cvt.s.w $f16, $f16
  or    $t7, $t9, $s2
  sw    $t7, ($s0)
  sw    $t6, 4($s0)
  move  $s0, $a0
  addiu $a0, $a0, 8
  mul.s $f16, $f16, $f2
  div.s $f16, $f16, $f0
  trunc.w.s $f16, $f16
  cvt.s.w $f14, $f14
  mfc1  $s6, $f16
  nop   
  addiu $s6, $s6, 0x32
  andi  $t7, $s6, 0x3ff
  mul.s $f14, $f14, $f2
  sll   $t6, $t7, 0xe
  or    $t8, $t6, $s7
  or    $t9, $t8, $s2
  sw    $t9, ($s0)
  or    $t7, $t6, $s3
  sw    $t7, 4($s0)
  div.s $f14, $f14, $f0
  trunc.w.s $f14, $f14
  mfc1  $s1, $f14
  nop   
  addiu $s1, $s1, 0x32
  andi  $t9, $s1, 0x3ff
  sll   $t7, $t9, 0xe
  or    $t6, $t7, $s7
  or    $t9, $t7, $s3
  addiu $t7, $t5, 1
  mtc1  $t7, $f14
  nop   
  cvt.s.w $f14, $f14
  mul.s $f18, $f14, $f2
  bnel  $t5, $fp, .L7F0D20C8
   div.s $f16, $f18, $f0
  div.s $f16, $f18, $f0
.L7F0D21F4:
  move  $s0, $a0
  or    $t8, $t6, $s2
  sw    $t8, ($s0)
  sw    $t9, 4($s0)
  addiu $a0, $a0, 8
  move  $s0, $a0
  addiu $a0, $a0, 8
  addiu $fp, $fp, 4
  trunc.w.s $f16, $f16
  mfc1  $s4, $f16
  nop   
  addiu $s4, $s4, 0x32
  andi  $t8, $s4, 0x3ff
  sll   $t9, $t8, 0xe
  or    $t7, $t9, $s7
  or    $t8, $t9, $s3
  addiu $t9, $t5, 2
  mtc1  $t9, $f16
  or    $t6, $t7, $s2
  sw    $t6, ($s0)
  cvt.s.w $f16, $f16
  sw    $t8, 4($s0)
  move  $s0, $a0
  addiu $a0, $a0, 8
  mul.s $f16, $f16, $f2
  div.s $f16, $f16, $f0
  trunc.w.s $f16, $f16
  mfc1  $s5, $f16
  nop   
  addiu $s5, $s5, 0x32
  andi  $t6, $s5, 0x3ff
  sll   $t8, $t6, 0xe
  or    $t9, $t8, $s7
  or    $t6, $t8, $s3
  addiu $t8, $t5, 3
  mtc1  $t8, $f16
  or    $t7, $t9, $s2
  sw    $t7, ($s0)
  cvt.s.w $f16, $f16
  sw    $t6, 4($s0)
  move  $s0, $a0
  addiu $a0, $a0, 8
  addiu $t5, $t5, 4
  mul.s $f16, $f16, $f2
  div.s $f16, $f16, $f0
  trunc.w.s $f16, $f16
  mfc1  $s6, $f16
  nop   
  addiu $s6, $s6, 0x32
  andi  $t7, $s6, 0x3ff
  sll   $t6, $t7, 0xe
  or    $t8, $t6, $s7
  or    $t9, $t8, $s2
  or    $t7, $t6, $s3
  sw    $t7, 4($s0)
  sw    $t9, ($s0)
  addiu $v0, $v0, 7
  slt   $at, $t1, $v0
  bnez  $at, .L7F0D22EC
   addiu $v1, $v1, 7
  bnel  $v0, $ra, .L7F0D2014
   move  $s0, $a0
.L7F0D22EC:
  lw    $ra, 0x2c($sp)
.L7F0D22F0:
  lw    $s0, 8($sp)
  lw    $s1, 0xc($sp)
  lw    $s2, 0x10($sp)
  lw    $s3, 0x14($sp)
  lw    $s4, 0x18($sp)
  lw    $s5, 0x1c($sp)
  lw    $s6, 0x20($sp)
  lw    $s7, 0x24($sp)
  lw    $fp, 0x28($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   move  $v0, $a0
");

asm(R"
glabel sub_GAME_7F0D2320
  lui   $v1, %hi(D_8004EAF4)
  addiu $v1, %lo(D_8004EAF4) # addiu $v1, $v1, -0x150c
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f6
  lwc1  $f4, ($v1)
  lui   $at, %hi(D_8004EAF0)
  div.s $f8, $f4, $f6
  trunc.w.s $f10, $f8
  mfc1  $v0, $f10
  nop   
  sll   $t7, $v0, 2
  addu  $t7, $t7, $v0
  sll   $t7, $t7, 1
  addiu $v0, $t7, 0xa
  mtc1  $v0, $f16
  nop   
  cvt.s.w $f18, $f16
  swc1  $f18, ($v1)
  lwc1  $f4, ($v1)
  jr    $ra
   swc1  $f4, %lo(D_8004EAF0)($at)
");
