int D_8002BB00 = 0;
int D_8002BB04 = 0;
int D_8002BB08 = 0;
float D_8002BB0C = 255.0;
float D_8002BB10 = 255.0;
float D_8002BB14 = 255.0;
int D_8002BB18 = 0;
int D_8002BB1C = 0;
int D_8002BB20 = 0;
int D_8002BB24 = 0;
int D_8002BB28 = 0;
int D_8002BB2C = 0;

asm(R"
.late_rodata
glabel D_80051CF0
.word 0x43958000

.text
glabel sub_GAME_7F01B240
  addiu $sp, $sp, -0x48
  sw    $s2, 0x28($sp)
  sw    $ra, 0x44($sp)
  sw    $fp, 0x40($sp)
  sw    $s7, 0x3c($sp)
  sw    $s6, 0x38($sp)
  sw    $s5, 0x34($sp)
  sw    $s4, 0x30($sp)
  sw    $s3, 0x2c($sp)
  sw    $s1, 0x24($sp)
  sw    $s0, 0x20($sp)
  sdc1  $f24, 0x18($sp)
  sdc1  $f22, 0x10($sp)
  sdc1  $f20, 8($sp)
  lw    $s2, 0x58($sp)
  lw    $t6, ($a3)
  lw    $t7, 4($a3)
  lw    $t9, ($s2)
  mtc1  $t6, $f4
  lw    $t6, 4($s2)
  mtc1  $t7, $f6
  mtc1  $t9, $f10
  cvt.s.w $f0, $f4
  lw    $t7, 8($s2)
  mtc1  $t6, $f4
  lw    $t8, 8($a3)
  lui   $at, %hi(D_8002BB0C)
  cvt.s.w $f2, $f6
  mtc1  $t7, $f6
  mtc1  $t8, $f8
  lui   $s4, (0x07080200 >> 16) # lui $s4, 0x708
  lui   $s7, (0x070DB026 >> 16) # lui $s7, 0x70d
  cvt.s.w $f14, $f10
  lui   $ra, (0xF5886E00 >> 16) # lui $ra, 0xf588
  lui   $t5, (0x04000400 >> 16) # lui $t5, 0x400
  lui   $t2, (0xE46DF000 >> 16) # lui $t2, 0xe46d
  move  $s0, $a1
  cvt.s.w $f16, $f4
  swc1  $f14, %lo(D_8002BB0C)($at)
  lui   $at, %hi(D_8002BB10)
  move  $s1, $a2
  move  $t0, $zero
  cvt.s.w $f18, $f6
  swc1  $f16, %lo(D_8002BB10)($at)
  lui   $at, %hi(D_8002BB14)
  ori   $t2, (0xE46DF000 & 0xFFFF) # ori $t2, $t2, 0xf000
  ori   $t5, (0x04000400 & 0xFFFF) # ori $t5, $t5, 0x400
  cvt.s.w $f12, $f8
  swc1  $f18, %lo(D_8002BB14)($at)
  lui   $at, %hi(D_80051CF0)
  ori   $ra, (0xF5886E00 & 0xFFFF) # ori $ra, $ra, 0x6e00
  ori   $s7, (0x070DB026 & 0xFFFF) # ori $s7, $s7, 0xb026
  sub.s $f22, $f16, $f2
  lwc1  $f16, %lo(D_80051CF0)($at)
  ori   $s4, (0x07080200 & 0xFFFF) # ori $s4, $s4, 0x200
  sub.s $f24, $f18, $f12
  lui   $s2, 0xfd90
  lui   $s3, 0xf590
  sub.s $f20, $f14, $f0
  lui   $s5, 0xe600
  lui   $s6, 0xf300
  lui   $fp, 0xe700
  li    $t1, 1
  lui   $t4, 0xb300
  lui   $t3, 0xb400
.L7F01B344:
  mtc1  $t0, $f8
  move  $v0, $a0
  addiu $a0, $a0, 8
  cvt.s.w $f14, $f8
  move  $v1, $a0
  sw    $s2, ($v0)
  sw    $s0, 4($v0)
  addiu $a0, $a0, 8
  move  $a1, $a0
  mul.s $f10, $f20, $f14
  sw    $s4, 4($v1)
  sw    $s3, ($v1)
  addiu $a0, $a0, 8
  move  $a2, $a0
  addiu $a0, $a0, 8
  sw    $s5, ($a1)
  div.s $f4, $f10, $f16
  sw    $zero, 4($a1)
  move  $a3, $a0
  addiu $a0, $a0, 8
  sw    $s7, 4($a2)
  sw    $s6, ($a2)
  move  $v0, $a0
  sw    $zero, 4($a3)
  sw    $fp, ($a3)
  lui   $t8, (0x00080200 >> 16) # lui $t8, 8
  ori   $t8, (0x00080200 & 0xFFFF) # ori $t8, $t8, 0x200
  addiu $a0, $a0, 8
  move  $v1, $a0
  sw    $t8, 4($v0)
  sw    $ra, ($v0)
  lui   $t9, 0xf200
  sw    $t9, ($v1)
  li    $t9, 1
  addiu $a0, $a0, 8
  lui   $t6, (0x006DC000 >> 16) # lui $t6, 0x6d
  ori   $t6, (0x006DC000 & 0xFFFF) # ori $t6, $t6, 0xc000
  move  $a1, $a0
  sw    $t6, 4($v1)
  add.s $f6, $f4, $f0
  addiu $a0, $a0, 8
  lui   $t7, 0xfa00
  sw    $t7, ($a1)
  cfc1  $t8, $31
  ctc1  $t9, $31
  li    $at, 0x4F000000 # 2147483648.000000
  move  $v0, $a0
  cvt.w.s $f8, $f6
  cfc1  $t9, $31
  nop   
  andi  $t9, $t9, 0x78
  beql  $t9, $zero, .L7F01B460
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
  bnez  $t9, .L7F01B454
   nop   
  mfc1  $t9, $f8
  lui   $at, 0x8000
  b     .L7F01B46C
   or    $t9, $t9, $at
.L7F01B454:
  b     .L7F01B46C
   li    $t9, -1
  mfc1  $t9, $f8
.L7F01B460:
  nop   
  bltz  $t9, .L7F01B454
   nop   
.L7F01B46C:
  ctc1  $t8, $31
  move  $t6, $t9
  li    $t9, 1
  mul.s $f10, $f22, $f14
  sll   $t7, $t6, 0x18
  li    $at, 0x4F000000 # 2147483648.000000
  div.s $f4, $f10, $f16
  add.s $f6, $f2, $f4
  cfc1  $t8, $31
  ctc1  $t9, $31
  nop   
  cvt.w.s $f8, $f6
  cfc1  $t9, $31
  nop   
  andi  $t9, $t9, 0x78
  beql  $t9, $zero, .L7F01B4F8
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
  bnez  $t9, .L7F01B4EC
   nop   
  mfc1  $t9, $f8
  lui   $at, 0x8000
  b     .L7F01B504
   or    $t9, $t9, $at
.L7F01B4EC:
  b     .L7F01B504
   li    $t9, -1
  mfc1  $t9, $f8
.L7F01B4F8:
  nop   
  bltz  $t9, .L7F01B4EC
   nop   
.L7F01B504:
  ctc1  $t8, $31
  andi  $t6, $t9, 0xff
  sll   $t8, $t6, 0x10
  mul.s $f10, $f24, $f14
  or    $t9, $t7, $t8
  li    $t7, 1
  li    $at, 0x4F000000 # 2147483648.000000
  div.s $f4, $f10, $f16
  add.s $f6, $f12, $f4
  cfc1  $t6, $31
  ctc1  $t7, $31
  nop   
  cvt.w.s $f8, $f6
  cfc1  $t7, $31
  nop   
  andi  $t7, $t7, 0x78
  beql  $t7, $zero, .L7F01B594
   mfc1  $t7, $f8
  mtc1  $at, $f8
  li    $t7, 1
  sub.s $f8, $f6, $f8
  ctc1  $t7, $31
  nop   
  cvt.w.s $f8, $f8
  cfc1  $t7, $31
  nop   
  andi  $t7, $t7, 0x78
  bnez  $t7, .L7F01B588
   nop   
  mfc1  $t7, $f8
  lui   $at, 0x8000
  b     .L7F01B5A0
   or    $t7, $t7, $at
.L7F01B588:
  b     .L7F01B5A0
   li    $t7, -1
  mfc1  $t7, $f8
.L7F01B594:
  nop   
  bltz  $t7, .L7F01B588
   nop   
.L7F01B5A0:
  ctc1  $t6, $31
  andi  $t8, $t7, 0xff
  sll   $t6, $t8, 8
  or    $t7, $t9, $t6
  ori   $t8, $t7, 0xff
  bgez  $s1, .L7F01B618
   sw    $t8, 4($a1)
  addiu $t9, $t0, 0x11
  sll   $t6, $t9, 2
  addiu $t7, $t6, -1
  andi  $t8, $t7, 0xfff
  addiu $t6, $t0, 0x10
  sll   $t7, $t6, 2
  or    $t9, $t8, $t2
  move  $v0, $a0
  addiu $a0, $a0, 8
  andi  $t8, $t7, 0xfff
  sw    $t8, 4($v0)
  move  $v1, $a0
  addiu $a0, $a0, 8
  negu  $t7, $s1
  sw    $t9, ($v0)
  sll   $t8, $t7, 0x15
  move  $a1, $a0
  sw    $t8, 4($v1)
  sw    $t3, ($v1)
  sw    $t5, 4($a1)
  sw    $t4, ($a1)
  b     .L7F01B674
   addiu $a0, $a0, 8
.L7F01B618:
  addiu $t9, $t0, 0x11
  sll   $t6, $t9, 2
  addiu $t7, $t6, -1
  andi  $t8, $t7, 0xfff
  or    $t9, $t8, $t2
  sll   $t6, $s1, 2
  andi  $t7, $t6, 0xfff
  sw    $t9, ($v0)
  addiu $t9, $t0, 0x10
  sll   $t6, $t9, 2
  sll   $t8, $t7, 0xc
  andi  $t7, $t6, 0xfff
  addiu $a0, $a0, 8
  move  $v1, $a0
  or    $t9, $t8, $t7
  sw    $t9, 4($v0)
  addiu $a0, $a0, 8
  move  $a1, $a0
  sw    $zero, 4($v1)
  sw    $t3, ($v1)
  sw    $t5, 4($a1)
  sw    $t4, ($a1)
  addiu $a0, $a0, 8
.L7F01B674:
  move  $t0, $t1
  addiu $t1, $t1, 1
  slti  $at, $t1, 0x12c
  bnez  $at, .L7F01B344
   addiu $s0, $s0, 0x1b8
  lui   $at, %hi(D_8002BB08)
  swc1  $f12, %lo(D_8002BB08)($at)
  lw    $ra, 0x44($sp)
  lui   $at, %hi(D_8002BB04)
  swc1  $f2, %lo(D_8002BB04)($at)
  lui   $at, %hi(D_8002BB00)
  ldc1  $f20, 8($sp)
  ldc1  $f22, 0x10($sp)
  ldc1  $f24, 0x18($sp)
  lw    $s0, 0x20($sp)
  lw    $s1, 0x24($sp)
  lw    $s2, 0x28($sp)
  lw    $s3, 0x2c($sp)
  lw    $s4, 0x30($sp)
  lw    $s5, 0x34($sp)
  lw    $s6, 0x38($sp)
  lw    $s7, 0x3c($sp)
  lw    $fp, 0x40($sp)
  swc1  $f0, %lo(D_8002BB00)($at)
  addiu $sp, $sp, 0x48
  jr    $ra
   move  $v0, $a0
");

asm(R"
glabel sub_GAME_7F01B6E0
  mtc1  $a2, $f4
  addiu $sp, $sp, -0x48
  lui   $at, %hi(D_8002BB2C)
  cvt.s.w $f14, $f4
  sw    $ra, 0x44($sp)
  sw    $fp, 0x40($sp)
  sw    $s6, 0x38($sp)
  sw    $s3, 0x2c($sp)
  sw    $s7, 0x3c($sp)
  swc1  $f14, %lo(D_8002BB2C)($at)
  lwc1  $f6, %lo(D_8002BB2C)($at)
  mov.s $f16, $f14
  lui   $at, %hi(D_8002BB24)
  swc1  $f16, %lo(D_8002BB24)($at)
  lui   $at, %hi(D_8002BB28)
  swc1  $f14, %lo(D_8002BB28)($at)
  li    $at, 0x43590000 # 217.000000
  sw    $s5, 0x34($sp)
  sw    $s4, 0x30($sp)
  sw    $s2, 0x28($sp)
  sw    $s1, 0x24($sp)
  sw    $s0, 0x20($sp)
  sdc1  $f24, 0x18($sp)
  sdc1  $f22, 0x10($sp)
  sdc1  $f20, 8($sp)
  lui   $s3, (0x07080200 >> 16) # lui $s3, 0x708
  lui   $s6, (0x0713F01A >> 16) # lui $s6, 0x713
  lui   $fp, (0xF510A000 >> 16) # lui $fp, 0xf510
  lui   $ra, (0x00080200 >> 16) # lui $ra, 8
  lui   $t5, (0x04000400 >> 16) # lui $t5, 0x400
  lui   $t2, (0xE44FF000 >> 16) # lui $t2, 0xe44f
  mtc1  $at, $f16
  move  $s0, $a1
  move  $a3, $zero
  mov.s $f0, $f14
  mov.s $f12, $f14
  ori   $t2, (0xE44FF000 & 0xFFFF) # ori $t2, $t2, 0xf000
  ori   $t5, (0x04000400 & 0xFFFF) # ori $t5, $t5, 0x400
  ori   $ra, (0x00080200 & 0xFFFF) # ori $ra, $ra, 0x200
  ori   $fp, (0xF510A000 & 0xFFFF) # ori $fp, $fp, 0xa000
  ori   $s6, (0x0713F01A & 0xFFFF) # ori $s6, $s6, 0xf01a
  ori   $s3, (0x07080200 & 0xFFFF) # ori $s3, $s3, 0x200
  sub.s $f20, $f14, $f14
  lui   $s1, 0xfd10
  lui   $s2, 0xf510
  sub.s $f22, $f14, $f14
  lui   $s4, 0xe600
  lui   $s5, 0xf300
  lui   $s7, 0xe700
  li    $t1, 1
  lui   $t4, 0xb300
  lui   $t3, 0xb400
  sub.s $f24, $f6, $f14
.L7F01B7B4:
  mtc1  $a3, $f8
  move  $v0, $a0
  addiu $a0, $a0, 8
  cvt.s.w $f2, $f8
  move  $v1, $a0
  sw    $s1, ($v0)
  sw    $s0, 4($v0)
  addiu $a0, $a0, 8
  move  $a1, $a0
  mul.s $f10, $f20, $f2
  sw    $s3, 4($v1)
  sw    $s2, ($v1)
  addiu $a0, $a0, 8
  move  $a2, $a0
  addiu $a0, $a0, 8
  sw    $s4, ($a1)
  div.s $f4, $f10, $f16
  sw    $zero, 4($a1)
  move  $t0, $a0
  addiu $a0, $a0, 8
  sw    $s6, 4($a2)
  sw    $s5, ($a2)
  move  $v0, $a0
  sw    $zero, 4($t0)
  sw    $s7, ($t0)
  addiu $a0, $a0, 8
  move  $v1, $a0
  sw    $ra, 4($v0)
  sw    $fp, ($v0)
  lui   $t6, 0xf200
  sw    $t6, ($v1)
  li    $t6, 1
  addiu $a0, $a0, 8
  move  $a1, $a0
  lui   $t7, (0x004FC000 >> 16) # lui $t7, 0x4f
  addiu $a0, $a0, 8
  ori   $t7, (0x004FC000 & 0xFFFF) # ori $t7, $t7, 0xc000
  move  $v0, $a0
  sw    $t7, 4($v1)
  add.s $f6, $f4, $f0
  addiu $a0, $a0, 8
  lui   $t8, 0xfa00
  move  $v1, $a0
  cfc1  $t9, $31
  ctc1  $t6, $31
  sw    $t8, ($a1)
  li    $at, 0x4F000000 # 2147483648.000000
  cvt.w.s $f8, $f6
  addiu $a0, $a0, 8
  addiu $s0, $s0, 0x280
  cfc1  $t6, $31
  nop   
  andi  $t6, $t6, 0x78
  beql  $t6, $zero, .L7F01B8D8
   mfc1  $t6, $f8
  mtc1  $at, $f8
  li    $t6, 1
  sub.s $f8, $f6, $f8
  ctc1  $t6, $31
  nop   
  cvt.w.s $f8, $f8
  cfc1  $t6, $31
  nop   
  andi  $t6, $t6, 0x78
  bnez  $t6, .L7F01B8CC
   nop   
  mfc1  $t6, $f8
  lui   $at, 0x8000
  b     .L7F01B8E4
   or    $t6, $t6, $at
.L7F01B8CC:
  b     .L7F01B8E4
   li    $t6, -1
  mfc1  $t6, $f8
.L7F01B8D8:
  nop   
  bltz  $t6, .L7F01B8CC
   nop   
.L7F01B8E4:
  ctc1  $t9, $31
  move  $t7, $t6
  li    $t6, 1
  mul.s $f10, $f22, $f2
  sll   $t8, $t7, 0x18
  li    $at, 0x4F000000 # 2147483648.000000
  div.s $f4, $f10, $f16
  add.s $f6, $f12, $f4
  cfc1  $t9, $31
  ctc1  $t6, $31
  nop   
  cvt.w.s $f8, $f6
  cfc1  $t6, $31
  nop   
  andi  $t6, $t6, 0x78
  beql  $t6, $zero, .L7F01B970
   mfc1  $t6, $f8
  mtc1  $at, $f8
  li    $t6, 1
  sub.s $f8, $f6, $f8
  ctc1  $t6, $31
  nop   
  cvt.w.s $f8, $f8
  cfc1  $t6, $31
  nop   
  andi  $t6, $t6, 0x78
  bnez  $t6, .L7F01B964
   nop   
  mfc1  $t6, $f8
  lui   $at, 0x8000
  b     .L7F01B97C
   or    $t6, $t6, $at
.L7F01B964:
  b     .L7F01B97C
   li    $t6, -1
  mfc1  $t6, $f8
.L7F01B970:
  nop   
  bltz  $t6, .L7F01B964
   nop   
.L7F01B97C:
  ctc1  $t9, $31
  andi  $t7, $t6, 0xff
  sll   $t9, $t7, 0x10
  mul.s $f10, $f24, $f2
  or    $t6, $t8, $t9
  li    $t8, 1
  li    $at, 0x4F000000 # 2147483648.000000
  div.s $f4, $f10, $f16
  add.s $f6, $f14, $f4
  cfc1  $t7, $31
  ctc1  $t8, $31
  nop   
  cvt.w.s $f8, $f6
  cfc1  $t8, $31
  nop   
  andi  $t8, $t8, 0x78
  beql  $t8, $zero, .L7F01BA0C
   mfc1  $t8, $f8
  mtc1  $at, $f8
  li    $t8, 1
  sub.s $f8, $f6, $f8
  ctc1  $t8, $31
  nop   
  cvt.w.s $f8, $f8
  cfc1  $t8, $31
  nop   
  andi  $t8, $t8, 0x78
  bnez  $t8, .L7F01BA00
   nop   
  mfc1  $t8, $f8
  lui   $at, 0x8000
  b     .L7F01BA18
   or    $t8, $t8, $at
.L7F01BA00:
  b     .L7F01BA18
   li    $t8, -1
  mfc1  $t8, $f8
.L7F01BA0C:
  nop   
  bltz  $t8, .L7F01BA00
   nop   
.L7F01BA18:
  ctc1  $t7, $31
  andi  $t9, $t8, 0xff
  sll   $t7, $t9, 8
  or    $t8, $t6, $t7
  ori   $t9, $t8, 0xff
  addiu $t6, $a3, 0xd
  sll   $t7, $t6, 2
  sw    $t9, 4($a1)
  addiu $t8, $t7, -1
  andi  $t9, $t8, 0xfff
  addiu $t7, $a3, 0xc
  sll   $t8, $t7, 2
  or    $t6, $t9, $t2
  andi  $t9, $t8, 0xfff
  sw    $t9, 4($v0)
  sw    $t6, ($v0)
  move  $a3, $t1
  move  $a1, $a0
  addiu $t1, $t1, 1
  sw    $zero, 4($v1)
  sw    $t3, ($v1)
  slti  $at, $t1, 0xda
  sw    $t5, 4($a1)
  sw    $t4, ($a1)
  bnez  $at, .L7F01B7B4
   addiu $a0, $a0, 8
  lui   $at, %hi(D_8002BB20)
  swc1  $f14, %lo(D_8002BB20)($at)
  lw    $ra, 0x44($sp)
  lui   $at, %hi(D_8002BB1C)
  swc1  $f12, %lo(D_8002BB1C)($at)
  lui   $at, %hi(D_8002BB18)
  ldc1  $f20, 8($sp)
  ldc1  $f22, 0x10($sp)
  ldc1  $f24, 0x18($sp)
  lw    $s0, 0x20($sp)
  lw    $s1, 0x24($sp)
  lw    $s2, 0x28($sp)
  lw    $s3, 0x2c($sp)
  lw    $s4, 0x30($sp)
  lw    $s5, 0x34($sp)
  lw    $s6, 0x38($sp)
  lw    $s7, 0x3c($sp)
  lw    $fp, 0x40($sp)
  swc1  $f0, %lo(D_8002BB18)($at)
  addiu $sp, $sp, 0x48
  jr    $ra
   move  $v0, $a0
");
