asm(R"
.late_rodata
glabel PI_80051D00
.word 0x40490FDB /*3.1415927*/

.text
glabel sub_GAME_7F01BAE0
  addiu $sp, $sp, -0x60
  sw    $s5, 0x58($sp)
  sw    $s2, 0x4c($sp)
  sw    $s0, 0x44($sp)
  move  $s0, $a0
  move  $s5, $a1
  sw    $ra, 0x5c($sp)
  sw    $s4, 0x54($sp)
  sw    $s3, 0x50($sp)
  sw    $s1, 0x48($sp)
  sdc1  $f30, 0x38($sp)
  sdc1  $f28, 0x30($sp)
  sdc1  $f26, 0x28($sp)
  sdc1  $f24, 0x20($sp)
  sdc1  $f22, 0x18($sp)
  sdc1  $f20, 0x10($sp)
  bltz  $a1, .L7F01BFBC
   move  $s2, $zero
  li    $at, 0x42800000 # 64.000000
  mtc1  $at, $f30
  lui   $at, %hi(PI_80051D00)
  lwc1  $f28, %lo(PI_80051D00)($at)
  li    $at, 0xC2DE0000 # -111.000000
  mtc1  $s5, $f4
  mtc1  $at, $f24
  li    $at, 0x430F0000 # 143.000000
  mtc1  $at, $f22
  li    $s1, 255
  cvt.s.w $f26, $f4
  mtc1  $s2, $f6
.L7F01BB58:
  nop   
  cvt.s.w $f8, $f6
  mul.s $f10, $f8, $f28
  div.s $f20, $f10, $f26
  jal   sinf
   mov.s $f12, $f20
  mul.s $f16, $f0, $f30
  mov.s $f12, $f20
  trunc.w.s $f18, $f16
  mfc1  $s3, $f18
  nop   
  sll   $t7, $s3, 0x10
  jal   cosf
   sra   $s3, $t7, 0x10
  li    $at, 0xC2800000 # -64.000000
  mtc1  $at, $f4
  sh    $s3, ($s0)
  sh    $zero, 4($s0)
  mul.s $f6, $f0, $f4
  sh    $zero, 6($s0)
  sh    $zero, 8($s0)
  sh    $zero, 0xa($s0)
  sb    $s1, 0xc($s0)
  sb    $s1, 0xd($s0)
  sb    $s1, 0xe($s0)
  trunc.w.s $f8, $f6
  mov.s $f12, $f20
  mfc1  $v0, $f8
  nop   
  sll   $s4, $v0, 0x10
  sra   $t0, $s4, 0x10
  move  $s4, $t0
  jal   cosf
   sh    $v0, 2($s0)
  mul.s $f10, $f0, $f24
  li    $t2, 1
  li    $at, 0x4F000000 # 2147483648.000000
  sub.s $f16, $f22, $f10
  cfc1  $t1, $31
  ctc1  $t2, $31
  nop   
  cvt.w.s $f18, $f16
  cfc1  $t2, $31
  nop   
  andi  $t2, $t2, 0x78
  beql  $t2, $zero, .L7F01BC5C
   mfc1  $t2, $f18
  mtc1  $at, $f18
  li    $t2, 1
  sub.s $f18, $f16, $f18
  ctc1  $t2, $31
  nop   
  cvt.w.s $f18, $f18
  cfc1  $t2, $31
  nop   
  andi  $t2, $t2, 0x78
  bnez  $t2, .L7F01BC50
   nop   
  mfc1  $t2, $f18
  lui   $at, 0x8000
  b     .L7F01BC68
   or    $t2, $t2, $at
.L7F01BC50:
  b     .L7F01BC68
   li    $t2, -1
  mfc1  $t2, $f18
.L7F01BC5C:
  nop   
  bltz  $t2, .L7F01BC50
   nop   
.L7F01BC68:
  ctc1  $t1, $31
  sb    $t2, 0xc($s0)
  jal   cosf
   mov.s $f12, $f20
  mul.s $f4, $f0, $f24
  li    $t4, 1
  li    $at, 0x4F000000 # 2147483648.000000
  sub.s $f6, $f22, $f4
  cfc1  $t3, $31
  ctc1  $t4, $31
  nop   
  cvt.w.s $f8, $f6
  cfc1  $t4, $31
  nop   
  andi  $t4, $t4, 0x78
  beql  $t4, $zero, .L7F01BCF4
   mfc1  $t4, $f8
  mtc1  $at, $f8
  li    $t4, 1
  sub.s $f8, $f6, $f8
  ctc1  $t4, $31
  nop   
  cvt.w.s $f8, $f8
  cfc1  $t4, $31
  nop   
  andi  $t4, $t4, 0x78
  bnez  $t4, .L7F01BCE8
   nop   
  mfc1  $t4, $f8
  lui   $at, 0x8000
  b     .L7F01BD00
   or    $t4, $t4, $at
.L7F01BCE8:
  b     .L7F01BD00
   li    $t4, -1
  mfc1  $t4, $f8
.L7F01BCF4:
  nop   
  bltz  $t4, .L7F01BCE8
   nop   
.L7F01BD00:
  ctc1  $t3, $31
  sb    $t4, 0xd($s0)
  jal   cosf
   mov.s $f12, $f20
  mul.s $f10, $f0, $f24
  li    $t6, 1
  li    $at, 0x4F000000 # 2147483648.000000
  sub.s $f16, $f22, $f10
  cfc1  $t5, $31
  ctc1  $t6, $31
  nop   
  cvt.w.s $f18, $f16
  cfc1  $t6, $31
  nop   
  andi  $t6, $t6, 0x78
  beql  $t6, $zero, .L7F01BD8C
   mfc1  $t6, $f18
  mtc1  $at, $f18
  li    $t6, 1
  sub.s $f18, $f16, $f18
  ctc1  $t6, $31
  nop   
  cvt.w.s $f18, $f18
  cfc1  $t6, $31
  nop   
  andi  $t6, $t6, 0x78
  bnez  $t6, .L7F01BD80
   nop   
  mfc1  $t6, $f18
  lui   $at, 0x8000
  b     .L7F01BD98
   or    $t6, $t6, $at
.L7F01BD80:
  b     .L7F01BD98
   li    $t6, -1
  mfc1  $t6, $f18
.L7F01BD8C:
  nop   
  bltz  $t6, .L7F01BD80
   nop   
.L7F01BD98:
  ctc1  $t5, $31
  sb    $t6, 0xe($s0)
  sb    $zero, 0xf($s0)
  beqz  $s2, .L7F01BFAC
   addiu $s0, $s0, 0x10
  slt   $at, $s2, $s5
  beqz  $at, .L7F01BFAC
   negu  $t7, $s3
  sh    $t7, ($s0)
  sh    $s4, 2($s0)
  sh    $zero, 4($s0)
  sh    $zero, 6($s0)
  sh    $zero, 8($s0)
  sh    $zero, 0xa($s0)
  sb    $s1, 0xc($s0)
  sb    $s1, 0xd($s0)
  sb    $s1, 0xe($s0)
  jal   cosf
   mov.s $f12, $f20
  mul.s $f4, $f0, $f24
  li    $t9, 1
  li    $at, 0x4F000000 # 2147483648.000000
  sub.s $f6, $f22, $f4
  cfc1  $t8, $31
  ctc1  $t9, $31
  nop   
  cvt.w.s $f8, $f6
  cfc1  $t9, $31
  nop   
  andi  $t9, $t9, 0x78
  beql  $t9, $zero, .L7F01BE60
   mfc1  $t9, $f8
  mtc1  $at, $f8
  li    $t9, 1
  sub.s $f8, $f6, $f8
  ctc1  $t9, $31
  nop   
  cvt.w.s $f8, $f8
  cfc1  $t9, $31
  nop   
  andi  $t9, $t9, 0x78
  bnez  $t9, .L7F01BE54
   nop   
  mfc1  $t9, $f8
  lui   $at, 0x8000
  b     .L7F01BE6C
   or    $t9, $t9, $at
.L7F01BE54:
  b     .L7F01BE6C
   li    $t9, -1
  mfc1  $t9, $f8
.L7F01BE60:
  nop   
  bltz  $t9, .L7F01BE54
   nop   
.L7F01BE6C:
  ctc1  $t8, $31
  sb    $t9, 0xc($s0)
  jal   cosf
   mov.s $f12, $f20
  mul.s $f10, $f0, $f24
  li    $t1, 1
  li    $at, 0x4F000000 # 2147483648.000000
  sub.s $f16, $f22, $f10
  cfc1  $t0, $31
  ctc1  $t1, $31
  nop   
  cvt.w.s $f18, $f16
  cfc1  $t1, $31
  nop   
  andi  $t1, $t1, 0x78
  beql  $t1, $zero, .L7F01BEF8
   mfc1  $t1, $f18
  mtc1  $at, $f18
  li    $t1, 1
  sub.s $f18, $f16, $f18
  ctc1  $t1, $31
  nop   
  cvt.w.s $f18, $f18
  cfc1  $t1, $31
  nop   
  andi  $t1, $t1, 0x78
  bnez  $t1, .L7F01BEEC
   nop   
  mfc1  $t1, $f18
  lui   $at, 0x8000
  b     .L7F01BF04
   or    $t1, $t1, $at
.L7F01BEEC:
  b     .L7F01BF04
   li    $t1, -1
  mfc1  $t1, $f18
.L7F01BEF8:
  nop   
  bltz  $t1, .L7F01BEEC
   nop   
.L7F01BF04:
  ctc1  $t0, $31
  sb    $t1, 0xd($s0)
  jal   cosf
   mov.s $f12, $f20
  mul.s $f4, $f0, $f24
  li    $t3, 1
  li    $at, 0x4F000000 # 2147483648.000000
  sub.s $f6, $f22, $f4
  cfc1  $t2, $31
  ctc1  $t3, $31
  nop   
  cvt.w.s $f8, $f6
  cfc1  $t3, $31
  nop   
  andi  $t3, $t3, 0x78
  beql  $t3, $zero, .L7F01BF90
   mfc1  $t3, $f8
  mtc1  $at, $f8
  li    $t3, 1
  sub.s $f8, $f6, $f8
  ctc1  $t3, $31
  nop   
  cvt.w.s $f8, $f8
  cfc1  $t3, $31
  nop   
  andi  $t3, $t3, 0x78
  bnez  $t3, .L7F01BF84
   nop   
  mfc1  $t3, $f8
  lui   $at, 0x8000
  b     .L7F01BF9C
   or    $t3, $t3, $at
.L7F01BF84:
  b     .L7F01BF9C
   li    $t3, -1
  mfc1  $t3, $f8
.L7F01BF90:
  nop   
  bltz  $t3, .L7F01BF84
   nop   
.L7F01BF9C:
  ctc1  $t2, $31
  sb    $t3, 0xe($s0)
  sb    $zero, 0xf($s0)
  addiu $s0, $s0, 0x10
.L7F01BFAC:
  addiu $s2, $s2, 2
  slt   $at, $s5, $s2
  beql  $at, $zero, .L7F01BB58
   mtc1  $s2, $f6
.L7F01BFBC:
  lw    $ra, 0x5c($sp)
  ldc1  $f20, 0x10($sp)
  ldc1  $f22, 0x18($sp)
  ldc1  $f24, 0x20($sp)
  ldc1  $f26, 0x28($sp)
  ldc1  $f28, 0x30($sp)
  ldc1  $f30, 0x38($sp)
  lw    $s0, 0x44($sp)
  lw    $s1, 0x48($sp)
  lw    $s2, 0x4c($sp)
  lw    $s3, 0x50($sp)
  lw    $s4, 0x54($sp)
  lw    $s5, 0x58($sp)
  jr    $ra
   addiu $sp, $sp, 0x60
");

asm(R"
glabel sub_GAME_7F01BFF8
  li    $t2, 10
  lui   $t1, 0xbf00
  lui   $t0, 0x400
  slti  $at, $a2, 0x11
.L7F01C008:
  bnez  $at, .L7F01C018
   move  $v1, $a0
  b     .L7F01C024
   li    $v0, 16
.L7F01C018:
  sll   $v0, $a2, 0x18
  sra   $t6, $v0, 0x18
  move  $v0, $t6
.L7F01C024:
  addiu $t7, $v0, -1
  sll   $t8, $t7, 4
  andi  $t9, $t8, 0xff
  sll   $t5, $v0, 4
  sll   $t3, $t9, 0x10
  or    $t4, $t3, $t0
  andi  $t6, $t5, 0xffff
  addiu $v0, $v0, -3
  or    $t7, $t4, $t6
  sw    $a1, 4($v1)
  sll   $t8, $v0, 0x18
  sw    $t7, ($v1)
  addiu $a0, $a0, 8
  addiu $a1, $a1, 0xe0
  sra   $v0, $t8, 0x18
.L7F01C060:
  multu $v0, $t2
  addiu $v0, $v0, -1
  move  $v1, $a0
  sw    $t1, ($v1)
  addiu $a0, $a0, 8
  mflo  $a3
  addiu $t4, $a3, 0xa
  andi  $t6, $t4, 0xff
  andi  $t3, $a3, 0xff
  sll   $t5, $t3, 0x10
  sll   $t7, $t6, 8
  addiu $t9, $a3, 0x14
  andi  $t3, $t9, 0xff
  or    $t8, $t5, $t7
  sll   $t6, $v0, 0x18
  sra   $v0, $t6, 0x18
  or    $t4, $t8, $t3
  bgez  $v0, .L7F01C060
   sw    $t4, 4($v1)
  addiu $a2, $a2, -0xe
  slti  $at, $a2, 3
  beql  $at, $zero, .L7F01C008
   slti  $at, $a2, 0x11
  lui   $t7, 0xb800
  sw    $t7, ($a0)
  addiu $v0, $a0, 8
  jr    $ra
   sw    $zero, 4($a0)
");
