int D_80032430 = 1;
int D_80032434 = 2;

asm(R"
.late_rodata
glabel D_80053740
.word 0x38c90fdb /*0.000095873802*/
glabel D_80053744
.word 0xbf7fff58 /*-0.99998999*/

.text
glabel sub_GAME_7F05B1E0
  addiu $sp, $sp, -0x48
  sw    $ra, 0x2c($sp)
  sw    $s0, 0x28($sp)
  sdc1  $f22, 0x20($sp)
  sdc1  $f20, 0x18($sp)
  sw    $a1, 0x4c($sp)
  lhu   $t6, ($a0)
  lui   $at, %hi(D_80053740)
  lwc1  $f20, %lo(D_80053740)($at)
  mtc1  $t6, $f4
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f22
  move  $s0, $a0
  bgez  $t6, .L7F05B22C
   cvt.s.w $f6, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F05B22C:
  mul.s $f10, $f6, $f20
  nop   
  mul.s $f12, $f10, $f22
  jal   cosf
   nop   
  swc1  $f0, 0x44($sp)
  lhu   $t7, ($s0)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t7, $f4
  bgez  $t7, .L7F05B264
   cvt.s.w $f8, $f4
  mtc1  $at, $f6
  nop   
  add.s $f8, $f8, $f6
.L7F05B264:
  mul.s $f10, $f8, $f20
  nop   
  mul.s $f12, $f10, $f22
  jal   sinf
   nop   
  swc1  $f0, 0x40($sp)
  lhu   $t8, 2($s0)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t8, $f4
  bgez  $t8, .L7F05B29C
   cvt.s.w $f6, $f4
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F05B29C:
  mul.s $f10, $f6, $f20
  nop   
  mul.s $f12, $f10, $f22
  jal   cosf
   nop   
  swc1  $f0, 0x3c($sp)
  lhu   $t9, 2($s0)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t9, $f4
  bgez  $t9, .L7F05B2D4
   cvt.s.w $f8, $f4
  mtc1  $at, $f6
  nop   
  add.s $f8, $f8, $f6
.L7F05B2D4:
  mul.s $f10, $f8, $f20
  nop   
  mul.s $f12, $f10, $f22
  jal   sinf
   nop   
  swc1  $f0, 0x38($sp)
  lhu   $t0, 4($s0)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t0, $f4
  bgez  $t0, .L7F05B30C
   cvt.s.w $f6, $f4
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F05B30C:
  mul.s $f10, $f6, $f20
  nop   
  mul.s $f12, $f10, $f22
  jal   cosf
   nop   
  lhu   $t1, 4($s0)
  mov.s $f18, $f0
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t1, $f4
  bgez  $t1, .L7F05B344
   cvt.s.w $f8, $f4
  mtc1  $at, $f6
  nop   
  add.s $f8, $f8, $f6
.L7F05B344:
  mul.s $f10, $f8, $f20
  swc1  $f18, 0x34($sp)
  mul.s $f12, $f10, $f22
  jal   sinf
   nop   
  lwc1  $f22, 0x3c($sp)
  lwc1  $f4, 0x44($sp)
  lwc1  $f20, 0x40($sp)
  lwc1  $f6, 0x38($sp)
  mul.s $f2, $f4, $f22
  lwc1  $f18, 0x34($sp)
  lw    $v0, 0x4c($sp)
  mul.s $f16, $f20, $f6
  nop   
  mul.s $f8, $f2, $f18
  nop   
  mul.s $f10, $f16, $f0
  add.s $f4, $f8, $f10
  mul.s $f14, $f20, $f22
  swc1  $f4, ($v0)
  lwc1  $f8, 0x38($sp)
  lwc1  $f6, 0x44($sp)
  mul.s $f12, $f6, $f8
  nop   
  mul.s $f10, $f14, $f18
  nop   
  mul.s $f4, $f12, $f0
  sub.s $f6, $f10, $f4
  mul.s $f8, $f12, $f18
  nop   
  mul.s $f10, $f14, $f0
  swc1  $f6, 4($v0)
  mul.s $f6, $f2, $f0
  add.s $f4, $f8, $f10
  mul.s $f8, $f16, $f18
  swc1  $f4, 8($v0)
  sub.s $f10, $f6, $f8
  swc1  $f10, 0xc($v0)
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x28($sp)
  ldc1  $f22, 0x20($sp)
  ldc1  $f20, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x48
");

asm(R"
glabel sub_GAME_7F05B3F4
  addiu $sp, $sp, -0x40
  sdc1  $f20, 0x18($sp)
  sw    $ra, 0x24($sp)
  sw    $s0, 0x20($sp)
  sw    $a1, 0x44($sp)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f20
  lwc1  $f4, ($a0)
  move  $s0, $a0
  mul.s $f12, $f4, $f20
  jal   cosf
   nop   
  swc1  $f0, 0x3c($sp)
  lwc1  $f6, ($s0)
  mul.s $f12, $f6, $f20
  jal   sinf
   nop   
  swc1  $f0, 0x38($sp)
  lwc1  $f8, 4($s0)
  mul.s $f12, $f8, $f20
  jal   cosf
   nop   
  swc1  $f0, 0x34($sp)
  lwc1  $f10, 4($s0)
  mul.s $f12, $f10, $f20
  jal   sinf
   nop   
  swc1  $f0, 0x30($sp)
  lwc1  $f4, 8($s0)
  mul.s $f12, $f4, $f20
  jal   cosf
   nop   
  lwc1  $f6, 8($s0)
  swc1  $f0, 0x2c($sp)
  mul.s $f12, $f6, $f20
  jal   sinf
   nop   
  lwc1  $f8, 0x3c($sp)
  lwc1  $f10, 0x34($sp)
  lwc1  $f20, 0x38($sp)
  lwc1  $f4, 0x30($sp)
  mul.s $f2, $f8, $f10
  lwc1  $f18, 0x2c($sp)
  lw    $v0, 0x44($sp)
  mul.s $f16, $f20, $f4
  nop   
  mul.s $f6, $f2, $f18
  nop   
  mul.s $f8, $f16, $f0
  add.s $f10, $f6, $f8
  swc1  $f10, ($v0)
  lwc1  $f4, 0x34($sp)
  lwc1  $f8, 0x30($sp)
  lwc1  $f6, 0x3c($sp)
  mul.s $f14, $f20, $f4
  nop   
  mul.s $f12, $f6, $f8
  nop   
  mul.s $f10, $f14, $f18
  nop   
  mul.s $f4, $f12, $f0
  sub.s $f6, $f10, $f4
  mul.s $f8, $f12, $f18
  nop   
  mul.s $f10, $f14, $f0
  swc1  $f6, 4($v0)
  mul.s $f6, $f2, $f0
  add.s $f4, $f8, $f10
  mul.s $f8, $f16, $f18
  swc1  $f4, 8($v0)
  sub.s $f10, $f6, $f8
  swc1  $f10, 0xc($v0)
  lw    $ra, 0x24($sp)
  lw    $s0, 0x20($sp)
  ldc1  $f20, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x40
");

asm(R"
glabel sub_GAME_7F05B528
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f4
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  mul.s $f12, $f12, $f4
  sw    $a1, 0x24($sp)
  jal   cosf
   swc1  $f12, 0x1c($sp)
  lw    $v0, 0x24($sp)
  lwc1  $f12, 0x1c($sp)
  jal   sinf
   swc1  $f0, ($v0)
  lw    $v0, 0x24($sp)
  mtc1  $zero, $f2
  swc1  $f0, 4($v0)
  swc1  $f2, 8($v0)
  swc1  $f2, 0xc($v0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F05B57C
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f4
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  mul.s $f12, $f12, $f4
  sw    $a1, 0x24($sp)
  jal   cosf
   swc1  $f12, 0x1c($sp)
  lw    $v0, 0x24($sp)
  mtc1  $zero, $f6
  lwc1  $f12, 0x1c($sp)
  swc1  $f0, ($v0)
  jal   sinf
   swc1  $f6, 4($v0)
  lw    $v0, 0x24($sp)
  mtc1  $zero, $f8
  swc1  $f0, 8($v0)
  swc1  $f8, 0xc($v0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F05B5D4
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f4
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  mul.s $f12, $f12, $f4
  sw    $a1, 0x24($sp)
  jal   cosf
   swc1  $f12, 0x1c($sp)
  lw    $v0, 0x24($sp)
  mtc1  $zero, $f2
  lwc1  $f12, 0x1c($sp)
  swc1  $f0, ($v0)
  swc1  $f2, 4($v0)
  jal   sinf
   swc1  $f2, 8($v0)
  lw    $v0, 0x24($sp)
  swc1  $f0, 0xc($v0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F05B628
  addiu $sp, $sp, -0x48
  sdc1  $f20, 8($sp)
  lwc1  $f20, ($a0)
  lwc1  $f0, 4($a0)
  lwc1  $f2, 8($a0)
  mul.s $f4, $f20, $f20
  lwc1  $f12, 0xc($a0)
  li    $at, 0x40000000 # 2.000000
  mul.s $f6, $f0, $f0
  add.s $f8, $f4, $f6
  mul.s $f10, $f2, $f2
  add.s $f4, $f8, $f10
  mul.s $f6, $f12, $f12
  mtc1  $at, $f10
  li    $at, 0x3F800000 # 1.000000
  add.s $f8, $f6, $f4
  div.s $f6, $f10, $f8
  mul.s $f18, $f0, $f6
  swc1  $f6, 0x44($sp)
  mul.s $f16, $f2, $f6
  nop   
  mul.s $f14, $f12, $f6
  nop   
  mul.s $f4, $f20, $f18
  nop   
  mul.s $f10, $f20, $f16
  nop   
  mul.s $f8, $f20, $f14
  swc1  $f4, 0x34($sp)
  mul.s $f6, $f0, $f18
  swc1  $f10, 0x30($sp)
  mul.s $f4, $f0, $f16
  swc1  $f8, 0x2c($sp)
  mul.s $f10, $f0, $f14
  swc1  $f6, 0x28($sp)
  mtc1  $zero, $f0
  mul.s $f8, $f2, $f16
  swc1  $f4, 0x24($sp)
  mtc1  $at, $f16
  mul.s $f6, $f2, $f14
  swc1  $f10, 0x20($sp)
  mul.s $f4, $f12, $f14
  swc1  $f8, 0x1c($sp)
  lwc1  $f10, 0x1c($sp)
  swc1  $f6, 0x18($sp)
  swc1  $f4, 0x14($sp)
  lwc1  $f8, 0x14($sp)
  mtc1  $at, $f4
  add.s $f6, $f10, $f8
  sub.s $f10, $f4, $f6
  swc1  $f10, ($a1)
  lwc1  $f4, 0x2c($sp)
  lwc1  $f8, 0x24($sp)
  add.s $f6, $f8, $f4
  swc1  $f6, 4($a1)
  lwc1  $f8, 0x30($sp)
  lwc1  $f10, 0x20($sp)
  sub.s $f4, $f10, $f8
  swc1  $f4, 8($a1)
  lwc1  $f10, 0x2c($sp)
  lwc1  $f6, 0x24($sp)
  lwc1  $f14, 0x18($sp)
  lwc1  $f12, 0x28($sp)
  sub.s $f8, $f6, $f10
  lwc1  $f2, 0x34($sp)
  swc1  $f8, 0x10($a1)
  lwc1  $f4, 0x14($sp)
  add.s $f8, $f14, $f2
  add.s $f6, $f12, $f4
  swc1  $f8, 0x18($a1)
  sub.s $f8, $f14, $f2
  sub.s $f10, $f16, $f6
  swc1  $f10, 0x14($a1)
  lwc1  $f6, 0x30($sp)
  lwc1  $f4, 0x20($sp)
  swc1  $f8, 0x24($a1)
  add.s $f10, $f4, $f6
  swc1  $f10, 0x20($a1)
  lwc1  $f4, 0x1c($sp)
  swc1  $f0, 0x30($a1)
  swc1  $f0, 0x34($a1)
  add.s $f6, $f12, $f4
  swc1  $f0, 0x38($a1)
  swc1  $f0, 0xc($a1)
  swc1  $f0, 0x1c($a1)
  sub.s $f10, $f16, $f6
  swc1  $f0, 0x2c($a1)
  swc1  $f16, 0x3c($a1)
  swc1  $f10, 0x28($a1)
  ldc1  $f20, 8($sp)
  jr    $ra
   addiu $sp, $sp, 0x48
");

asm(R"
glabel sub_GAME_7F05B798
  addiu $sp, $sp, -0x60
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  lwc1  $f6, 0x14($a0)
  lwc1  $f4, ($a0)
  lwc1  $f10, 0x28($a0)
  li    $at, 0x3F800000 # 1.000000
  add.s $f8, $f4, $f6
  mtc1  $at, $f2
  mtc1  $zero, $f18
  lui   $t6, %hi(D_80032430) 
  add.s $f16, $f10, $f8
  move  $s0, $a1
  addiu $t6, %lo(D_80032430) # addiu $t6, $t6, 0x2430
  add.s $f12, $f16, $f2
  c.lt.s $f18, $f12
  nop   
  bc1fl .L7F05B848
   lw    $at, ($t6)
  jal   sqrtf
   sw    $a0, 0x60($sp)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f12
  lw    $a0, 0x60($sp)
  div.s $f2, $f12, $f0
  mul.s $f4, $f0, $f12
  swc1  $f4, ($s0)
  lwc1  $f10, 0x24($a0)
  lwc1  $f6, 0x18($a0)
  sub.s $f8, $f6, $f10
  mul.s $f16, $f8, $f2
  swc1  $f16, 4($s0)
  lwc1  $f4, 8($a0)
  lwc1  $f18, 0x20($a0)
  sub.s $f6, $f18, $f4
  mul.s $f10, $f6, $f2
  swc1  $f10, 8($s0)
  lwc1  $f16, 0x10($a0)
  lwc1  $f8, 4($a0)
  sub.s $f18, $f8, $f16
  mul.s $f4, $f18, $f2
  b     .L7F05B9A0
   swc1  $f4, 0xc($s0)
  lw    $at, ($t6)
.L7F05B848:
  addiu $t3, $sp, 0x40
  move  $a1, $zero
  sw    $at, ($t3)
  lw    $t8, 4($t6)
  sw    $t8, 4($t3)
  lw    $at, 8($t6)
  sw    $at, 8($t3)
  lwc1  $f10, 0x14($a0)
  lwc1  $f6, ($a0)
  c.lt.s $f6, $f10
  nop   
  bc1fl .L7F05B884
   sll   $t9, $a1, 4
  li    $a1, 1
  sll   $t9, $a1, 4
.L7F05B884:
  addu  $v1, $a0, $t9
  sll   $v0, $a1, 2
  addu  $t4, $v1, $v0
  lwc1  $f0, ($t4)
  lwc1  $f8, 0x28($a0)
  c.lt.s $f0, $f8
  nop   
  bc1fl .L7F05B8B8
   addu  $t5, $t3, $v0
  addiu $v1, $a0, 0x20
  lwc1  $f0, 8($v1)
  li    $v0, 8
  addu  $t5, $t3, $v0
.L7F05B8B8:
  lw    $a1, ($t5)
  sll   $a3, $a1, 2
  addu  $t7, $t3, $a3
  sll   $t6, $a1, 4
  lw    $a2, ($t7)
  addu  $t1, $a0, $t6
  addu  $t9, $t1, $a3
  lwc1  $f16, ($t9)
  sll   $t8, $a2, 4
  addu  $t2, $a0, $t8
  sll   $t0, $a2, 2
  sub.s $f18, $f0, $f16
  addu  $t4, $t2, $t0
  lwc1  $f4, ($t4)
  sw    $t2, 0x24($sp)
  sw    $t1, 0x28($sp)
  sub.s $f6, $f18, $f4
  sw    $t0, 0x20($sp)
  sw    $a3, 0x2c($sp)
  sw    $v1, 0x38($sp)
  add.s $f12, $f6, $f2
  jal   sqrtf
   sw    $v0, 0x34($sp)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f12
  lw    $v0, 0x34($sp)
  lw    $a3, 0x2c($sp)
  div.s $f2, $f12, $f0
  lw    $t0, 0x20($sp)
  lw    $t1, 0x28($sp)
  lw    $t2, 0x24($sp)
  mul.s $f10, $f0, $f12
  lw    $v1, 0x38($sp)
  addu  $t5, $s0, $v0
  addu  $t7, $t1, $t0
  addu  $t6, $t2, $a3
  addu  $t8, $t1, $v0
  addu  $t9, $v1, $a3
  swc1  $f10, 4($t5)
  lwc1  $f8, ($t7)
  lwc1  $f16, ($t6)
  addu  $t4, $s0, $a3
  addu  $t5, $t2, $v0
  addu  $t7, $v1, $t0
  addu  $t6, $s0, $t0
  sub.s $f18, $f8, $f16
  mul.s $f4, $f18, $f2
  swc1  $f4, ($s0)
  lwc1  $f10, ($t9)
  lwc1  $f6, ($t8)
  add.s $f8, $f6, $f10
  mul.s $f16, $f8, $f2
  swc1  $f16, 4($t4)
  lwc1  $f4, ($t7)
  lwc1  $f18, ($t5)
  add.s $f6, $f18, $f4
  mul.s $f10, $f6, $f2
  swc1  $f10, 4($t6)
.L7F05B9A0:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x60
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F05B9B4
  addiu $sp, $sp, -0x18
  move  $a3, $a0
  sw    $ra, 0x14($sp)
  sw    $a1, 0x1c($sp)
  move  $a0, $a1
  move  $a1, $a2
  sw    $a3, 0x18($sp)
  jal   sub_GAME_7F05B628
   sw    $a2, 0x20($sp)
  lw    $a3, 0x18($sp)
  lw    $a2, 0x20($sp)
  lwc1  $f4, ($a3)
  swc1  $f4, 0x30($a2)
  lwc1  $f6, 4($a3)
  swc1  $f6, 0x34($a2)
  lwc1  $f8, 8($a3)
  swc1  $f8, 0x38($a2)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80053748
.word 0x3f7fff58 /*0.99998999*/
glabel D_8005374C
.word 0xbf7fff58 /*-0.99998999*/
.text
glabel sub_GAME_7F05BA08
  addiu $sp, $sp, -0x30
  sw    $ra, 0x14($sp)
  lwc1  $f6, 4($a1)
  lwc1  $f4, 4($a0)
  lwc1  $f16, ($a1)
  lwc1  $f2, ($a0)
  mul.s $f8, $f4, $f6
  lwc1  $f6, 8($a1)
  lwc1  $f4, 8($a0)
  mul.s $f10, $f2, $f16
  lui   $at, %hi(D_80053744)
  mtc1  $a2, $f14
  add.s $f18, $f10, $f8
  mul.s $f10, $f4, $f6
  lwc1  $f6, 0xc($a0)
  lwc1  $f4, 0xc($a1)
  add.s $f8, $f18, $f10
  mul.s $f18, $f4, $f6
  lwc1  $f10, %lo(D_80053744)($at)
  lui    $at, %hi(D_80053748)
  add.s $f12, $f18, $f8
  c.lt.s $f12, $f10
  nop   
  bc1f  .L7F05BAE8
   nop   
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  nop   
  sub.s $f0, $f4, $f14
  mul.s $f6, $f0, $f2
  nop   
  mul.s $f18, $f16, $f14
  sub.s $f8, $f6, $f18
  swc1  $f8, ($a3)
  lwc1  $f10, 4($a0)
  lwc1  $f6, 4($a1)
  mul.s $f4, $f0, $f10
  nop   
  mul.s $f18, $f6, $f14
  sub.s $f8, $f4, $f18
  swc1  $f8, 4($a3)
  lwc1  $f10, 8($a0)
  lwc1  $f4, 8($a1)
  mul.s $f6, $f0, $f10
  nop   
  mul.s $f18, $f4, $f14
  sub.s $f8, $f6, $f18
  swc1  $f8, 8($a3)
  lwc1  $f10, 0xc($a0)
  lwc1  $f6, 0xc($a1)
  mul.s $f4, $f0, $f10
  nop   
  mul.s $f18, $f6, $f14
  sub.s $f8, $f4, $f18
  b     .L7F05BC58
   swc1  $f8, 0xc($a3)
.L7F05BAE8:
  lwc1  $f10, %lo(D_80053748)($at)
  li    $at, 0x3F800000 # 1.000000
  c.le.s $f12, $f10
  nop   
  bc1fl .L7F05BBF0
   mtc1  $at, $f4
  sw    $a0, 0x30($sp)
  sw    $a1, 0x34($sp)
  sw    $a3, 0x3c($sp)
  jal   sub_GAME_7F05ACB0
   swc1  $f14, 0x38($sp)
  li    $at, 0x3F800000 # 1.000000
  lwc1  $f14, 0x38($sp)
  mtc1  $at, $f6
  mov.s $f12, $f0
  sub.s $f4, $f6, $f14
  mul.s $f18, $f4, $f0
  nop   
  mul.s $f8, $f14, $f0
  swc1  $f18, 0x24($sp)
  jal   sinf
   swc1  $f8, 0x20($sp)
  swc1  $f0, 0x1c($sp)
  jal   sinf
   lwc1  $f12, 0x24($sp)
  lwc1  $f10, 0x1c($sp)
  lwc1  $f12, 0x20($sp)
  div.s $f14, $f0, $f10
  jal   sinf
   swc1  $f14, 0x18($sp)
  lwc1  $f6, 0x1c($sp)
  lw    $a1, 0x34($sp)
  lw    $a0, 0x30($sp)
  div.s $f2, $f0, $f6
  lwc1  $f4, ($a1)
  lwc1  $f14, 0x18($sp)
  lwc1  $f8, ($a0)
  lw    $a3, 0x3c($sp)
  mul.s $f18, $f4, $f2
  nop   
  mul.s $f10, $f14, $f8
  add.s $f6, $f18, $f10
  swc1  $f6, ($a3)
  lwc1  $f4, 4($a1)
  lwc1  $f18, 4($a0)
  mul.s $f8, $f4, $f2
  nop   
  mul.s $f10, $f14, $f18
  add.s $f6, $f8, $f10
  swc1  $f6, 4($a3)
  lwc1  $f4, 8($a1)
  lwc1  $f8, 8($a0)
  mul.s $f18, $f4, $f2
  nop   
  mul.s $f10, $f14, $f8
  add.s $f6, $f18, $f10
  swc1  $f6, 8($a3)
  lwc1  $f4, 0xc($a1)
  lwc1  $f18, 0xc($a0)
  mul.s $f8, $f4, $f2
  nop   
  mul.s $f10, $f14, $f18
  add.s $f6, $f8, $f10
  b     .L7F05BC58
   swc1  $f6, 0xc($a3)
  mtc1  $at, $f4
.L7F05BBF0:
  mul.s $f18, $f16, $f14
  sub.s $f0, $f4, $f14
  mul.s $f8, $f0, $f2
  add.s $f10, $f18, $f8
  swc1  $f10, ($a3)
  lwc1  $f6, 4($a1)
  lwc1  $f18, 4($a0)
  mul.s $f4, $f6, $f14
  nop   
  mul.s $f8, $f0, $f18
  add.s $f10, $f4, $f8
  swc1  $f10, 4($a3)
  lwc1  $f6, 8($a1)
  lwc1  $f4, 8($a0)
  mul.s $f18, $f6, $f14
  nop   
  mul.s $f8, $f0, $f4
  add.s $f10, $f18, $f8
  swc1  $f10, 8($a3)
  lwc1  $f6, 0xc($a1)
  lwc1  $f18, 0xc($a0)
  mul.s $f4, $f6, $f14
  nop   
  mul.s $f8, $f0, $f18
  add.s $f10, $f4, $f8
  swc1  $f10, 0xc($a3)
.L7F05BC58:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80053750
.word 0x3f7fff58 /*0.99998999*/
.text
glabel sub_GAME_7F05BC68
  addiu $sp, $sp, -0x38
  sw    $ra, 0x14($sp)
  lwc1  $f0, ($a0)
  mtc1  $zero, $f4
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f2
  c.lt.s $f0, $f4
  mtc1  $a1, $f14
  lui   $at, %hi(D_8005374C)
  mov.s $f12, $f0
  bc1f  .L7F05BCA0
   mov.s $f16, $f2
  neg.s $f12, $f12
  neg.s $f16, $f2
.L7F05BCA0:
  lwc1  $f6, %lo(D_8005374C)($at)
  lui   $at, %hi(D_80053750)
  c.lt.s $f12, $f6
  nop   
  bc1f  .L7F05BCF8
   nop   
  sub.s $f10, $f2, $f14
  mul.s $f8, $f0, $f14
  nop   
  mul.s $f18, $f10, $f16
  sub.s $f4, $f8, $f18
  swc1  $f4, ($a2)
  lwc1  $f6, 4($a0)
  mul.s $f10, $f6, $f14
  swc1  $f10, 4($a2)
  lwc1  $f8, 8($a0)
  mul.s $f18, $f8, $f14
  swc1  $f18, 8($a2)
  lwc1  $f4, 0xc($a0)
  mul.s $f6, $f4, $f14
  b     .L7F05BE00
   swc1  $f6, 0xc($a2)
.L7F05BCF8:
  lwc1  $f10, %lo(D_80053750)($at)
  c.le.s $f12, $f10
  nop   
  bc1fl .L7F05BDC8
   sub.s $f8, $f2, $f14
  sw    $a0, 0x38($sp)
  sw    $a2, 0x40($sp)
  swc1  $f14, 0x3c($sp)
  jal   sub_GAME_7F05ACB0
   swc1  $f16, 0x30($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f2
  lwc1  $f14, 0x3c($sp)
  mov.s $f12, $f0
  sub.s $f18, $f2, $f14
  mul.s $f8, $f14, $f0
  nop   
  mul.s $f4, $f18, $f0
  swc1  $f8, 0x28($sp)
  jal   sinf
   swc1  $f4, 0x24($sp)
  swc1  $f0, 0x20($sp)
  jal   sinf
   lwc1  $f12, 0x28($sp)
  lwc1  $f6, 0x20($sp)
  lwc1  $f12, 0x24($sp)
  div.s $f2, $f0, $f6
  jal   sinf
   swc1  $f2, 0x1c($sp)
  lwc1  $f18, 0x20($sp)
  lw    $a0, 0x38($sp)
  lwc1  $f2, 0x1c($sp)
  div.s $f4, $f0, $f18
  lwc1  $f10, ($a0)
  lwc1  $f16, 0x30($sp)
  lw    $a2, 0x40($sp)
  mul.s $f8, $f10, $f2
  nop   
  mul.s $f6, $f4, $f16
  add.s $f10, $f8, $f6
  swc1  $f10, ($a2)
  lwc1  $f18, 4($a0)
  mul.s $f4, $f18, $f2
  swc1  $f4, 4($a2)
  lwc1  $f8, 8($a0)
  mul.s $f6, $f8, $f2
  swc1  $f6, 8($a2)
  lwc1  $f10, 0xc($a0)
  mul.s $f18, $f10, $f2
  b     .L7F05BE00
   swc1  $f18, 0xc($a2)
  sub.s $f8, $f2, $f14
.L7F05BDC8:
  mul.s $f4, $f0, $f14
  nop   
  mul.s $f6, $f8, $f16
  add.s $f10, $f4, $f6
  swc1  $f10, ($a2)
  lwc1  $f18, 4($a0)
  mul.s $f8, $f18, $f14
  swc1  $f8, 4($a2)
  lwc1  $f4, 8($a0)
  mul.s $f6, $f4, $f14
  swc1  $f6, 8($a2)
  lwc1  $f10, 0xc($a0)
  mul.s $f18, $f10, $f14
  swc1  $f18, 0xc($a2)
.L7F05BE00:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F05BE10
  lwc1  $f12, ($a1)
  lwc1  $f4, ($a0)
  lwc1  $f14, 4($a1)
  lwc1  $f8, 4($a0)
  mul.s $f6, $f4, $f12
  lwc1  $f4, 8($a0)
  lwc1  $f16, 8($a1)
  mul.s $f10, $f8, $f14
  lwc1  $f2, 0xc($a1)
  mul.s $f8, $f4, $f16
  add.s $f18, $f6, $f10
  lwc1  $f10, 0xc($a0)
  mul.s $f4, $f2, $f10
  add.s $f6, $f18, $f8
  mtc1  $zero, $f18
  add.s $f0, $f4, $f6
  c.lt.s $f0, $f18
  nop   
  bc1f  .L7F05BE80
   nop   
  neg.s $f8, $f12
  neg.s $f10, $f14
  neg.s $f4, $f16
  neg.s $f6, $f2
  swc1  $f8, ($a1)
  swc1  $f10, 4($a1)
  swc1  $f4, 8($a1)
  swc1  $f6, 0xc($a1)
.L7F05BE80:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F05BE88
  lwc1  $f4, ($a0)
  lwc1  $f6, ($a1)
  lwc1  $f10, 4($a0)
  lwc1  $f16, 4($a1)
  mul.s $f8, $f4, $f6
  lwc1  $f6, 8($a0)
  mul.s $f18, $f10, $f16
  lwc1  $f10, 8($a1)
  mul.s $f16, $f6, $f10
  lwc1  $f6, 0xc($a0)
  sub.s $f4, $f8, $f18
  lwc1  $f18, 0xc($a1)
  mul.s $f10, $f18, $f6
  sub.s $f8, $f4, $f16
  sub.s $f4, $f8, $f10
  swc1  $f4, ($a2)
  lwc1  $f18, 4($a1)
  lwc1  $f16, ($a0)
  lwc1  $f10, 4($a0)
  lwc1  $f8, ($a1)
  mul.s $f6, $f16, $f18
  lwc1  $f18, 8($a0)
  mul.s $f4, $f8, $f10
  lwc1  $f8, 0xc($a1)
  mul.s $f10, $f18, $f8
  lwc1  $f18, 0xc($a0)
  add.s $f16, $f6, $f4
  lwc1  $f4, 8($a1)
  mul.s $f8, $f4, $f18
  add.s $f6, $f16, $f10
  sub.s $f16, $f6, $f8
  swc1  $f16, 4($a2)
  lwc1  $f4, 8($a1)
  lwc1  $f10, ($a0)
  lwc1  $f8, 8($a0)
  lwc1  $f6, ($a1)
  mul.s $f18, $f10, $f4
  lwc1  $f4, 0xc($a0)
  mul.s $f16, $f6, $f8
  lwc1  $f6, 4($a1)
  mul.s $f8, $f4, $f6
  lwc1  $f4, 4($a0)
  add.s $f10, $f18, $f16
  lwc1  $f16, 0xc($a1)
  mul.s $f6, $f16, $f4
  add.s $f18, $f10, $f8
  sub.s $f10, $f18, $f6
  swc1  $f10, 8($a2)
  lwc1  $f16, 0xc($a1)
  lwc1  $f8, ($a0)
  lwc1  $f6, 0xc($a0)
  lwc1  $f18, ($a1)
  mul.s $f4, $f8, $f16
  lwc1  $f16, 4($a0)
  mul.s $f10, $f18, $f6
  lwc1  $f18, 8($a1)
  mul.s $f6, $f16, $f18
  lwc1  $f16, 8($a0)
  add.s $f8, $f4, $f10
  lwc1  $f10, 4($a1)
  mul.s $f18, $f10, $f16
  add.s $f4, $f8, $f6
  sub.s $f8, $f4, $f18
  jr    $ra
   swc1  $f8, 0xc($a2)
");

asm(R"
glabel sub_GAME_7F05BF8C
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  addiu $a2, $sp, 0x18
  jal   sub_GAME_7F05BE88
   sw    $a1, 0x2c($sp)
  lw    $a1, 0x2c($sp)
  lwc1  $f4, 0x18($sp)
  swc1  $f4, ($a1)
  lwc1  $f6, 0x1c($sp)
  swc1  $f6, 4($a1)
  lwc1  $f8, 0x20($sp)
  swc1  $f8, 8($a1)
  lwc1  $f10, 0x24($sp)
  swc1  $f10, 0xc($a1)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F05BFD4
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  lwc1  $f12, ($a0)
  sw    $a1, 0x24($sp)
  jal   sub_GAME_7F05ACB0
   sw    $a0, 0x20($sp)
  swc1  $f0, 0x1c($sp)
  jal   sinf
   mov.s $f12, $f0
  mtc1  $zero, $f12
  lw    $a0, 0x20($sp)
  lw    $a1, 0x24($sp)
  c.eq.s $f0, $f12
  nop   
  bc1fl .L7F05C02C
   swc1  $f12, ($a1)
  swc1  $f12, ($a1)
  swc1  $f12, 4($a1)
  swc1  $f12, 8($a1)
  b     .L7F05C058
   swc1  $f12, 0xc($a1)
  swc1  $f12, ($a1)
.L7F05C02C:
  lwc1  $f4, 0x1c($sp)
  lwc1  $f6, 4($a0)
  div.s $f2, $f4, $f0
  mul.s $f8, $f6, $f2
  swc1  $f8, 4($a1)
  lwc1  $f10, 8($a0)
  mul.s $f16, $f10, $f2
  swc1  $f16, 8($a1)
  lwc1  $f18, 0xc($a0)
  mul.s $f4, $f18, $f2
  swc1  $f4, 0xc($a1)
.L7F05C058:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F05C068
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  lwc1  $f2, 4($a0)
  lwc1  $f14, 8($a0)
  lwc1  $f0, 0xc($a0)
  mul.s $f4, $f2, $f2
  sw    $a1, 0x2c($sp)
  sw    $a0, 0x28($sp)
  mul.s $f6, $f14, $f14
  add.s $f8, $f4, $f6
  mul.s $f10, $f0, $f0
  jal   sqrtf
   add.s $f12, $f10, $f8
  mtc1  $zero, $f2
  lw    $a0, 0x28($sp)
  lw    $a1, 0x2c($sp)
  c.eq.s $f0, $f2
  mov.s $f12, $f0
  li    $at, 0x3F800000 # 1.000000
  bc1fl .L7F05C0D8
   sw    $a0, 0x28($sp)
  mtc1  $at, $f16
  swc1  $f2, 4($a1)
  swc1  $f2, 8($a1)
  swc1  $f2, 0xc($a1)
  b     .L7F05C128
   swc1  $f16, ($a1)
  sw    $a0, 0x28($sp)
.L7F05C0D8:
  sw    $a1, 0x2c($sp)
  jal   sinf
   swc1  $f12, 0x20($sp)
  lwc1  $f12, 0x20($sp)
  div.s $f2, $f0, $f12
  jal   cosf
   swc1  $f2, 0x1c($sp)
  lw    $a1, 0x2c($sp)
  lw    $a0, 0x28($sp)
  lwc1  $f2, 0x1c($sp)
  swc1  $f0, ($a1)
  lwc1  $f18, 4($a0)
  mul.s $f4, $f18, $f2
  swc1  $f4, 4($a1)
  lwc1  $f6, 8($a0)
  mul.s $f10, $f6, $f2
  swc1  $f10, 8($a1)
  lwc1  $f8, 0xc($a0)
  mul.s $f16, $f8, $f2
  swc1  $f16, 0xc($a1)
.L7F05C128:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F05C138
  addiu $sp, $sp, -0x70
  sw    $s0, 0x18($sp)
  move  $s0, $a1
  sw    $ra, 0x1c($sp)
  sw    $a0, 0x70($sp)
  sw    $a2, 0x78($sp)
  sw    $a3, 0x7c($sp)
  lwc1  $f4, ($s0)
  move  $a1, $a0
  addiu $a0, $sp, 0x60
  swc1  $f4, 0x60($sp)
  lwc1  $f6, 4($s0)
  addiu $a2, $sp, 0x50
  neg.s $f8, $f6
  swc1  $f8, 0x64($sp)
  lwc1  $f10, 8($s0)
  neg.s $f16, $f10
  swc1  $f16, 0x68($sp)
  lwc1  $f18, 0xc($s0)
  neg.s $f4, $f18
  jal   sub_GAME_7F05BE88
   swc1  $f4, 0x6c($sp)
  addiu $a0, $sp, 0x60
  lw    $a1, 0x78($sp)
  jal   sub_GAME_7F05BE88
   addiu $a2, $sp, 0x40
  addiu $a0, $sp, 0x50
  jal   sub_GAME_7F05BFD4
   addiu $a1, $sp, 0x30
  addiu $a0, $sp, 0x40
  jal   sub_GAME_7F05BFD4
   addiu $a1, $sp, 0x20
  lwc1  $f6, 0x20($sp)
  lwc1  $f8, 0x30($sp)
  lwc1  $f4, 0x24($sp)
  li    $at, 0x3E800000 # 0.250000
  add.s $f10, $f6, $f8
  lwc1  $f6, 0x34($sp)
  mtc1  $at, $f0
  addiu $a0, $sp, 0x30
  add.s $f8, $f4, $f6
  lwc1  $f4, 0x38($sp)
  addiu $a1, $sp, 0x50
  neg.s $f16, $f10
  neg.s $f10, $f8
  mul.s $f18, $f16, $f0
  swc1  $f18, 0x30($sp)
  mul.s $f16, $f10, $f0
  lwc1  $f18, 0x28($sp)
  add.s $f6, $f18, $f4
  lwc1  $f18, 0x3c($sp)
  swc1  $f16, 0x34($sp)
  lwc1  $f16, 0x2c($sp)
  neg.s $f8, $f6
  add.s $f4, $f16, $f18
  mul.s $f10, $f8, $f0
  neg.s $f6, $f4
  mul.s $f8, $f6, $f0
  swc1  $f10, 0x38($sp)
  jal   sub_GAME_7F05C068
   swc1  $f8, 0x3c($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x50
  jal   sub_GAME_7F05BE88
   lw    $a2, 0x7c($sp)
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x70
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F05C250
  addiu $sp, $sp, -0x40
  sw    $ra, 0x14($sp)
  sw    $a1, 0x44($sp)
  sw    $a0, 0x40($sp)
  sw    $a2, 0x48($sp)
  sw    $a3, 0x4c($sp)
  jal   sub_GAME_7F05BE10
   move  $a1, $a3
  lw    $a0, 0x40($sp)
  lw    $a1, 0x4c($sp)
  lw    $a2, 0x50($sp)
  jal   sub_GAME_7F05BA08
   addiu $a3, $sp, 0x30
  lw    $a0, 0x44($sp)
  jal   sub_GAME_7F05BE10
   lw    $a1, 0x48($sp)
  lw    $a0, 0x44($sp)
  lw    $a1, 0x48($sp)
  lw    $a2, 0x50($sp)
  jal   sub_GAME_7F05BA08
   addiu $a3, $sp, 0x20
  addiu $a0, $sp, 0x30
  jal   sub_GAME_7F05BE10
   addiu $a1, $sp, 0x20
  lwc1  $f0, 0x50($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  add.s $f4, $f0, $f0
  addiu $a0, $sp, 0x30
  addiu $a1, $sp, 0x20
  sub.s $f8, $f6, $f0
  lw    $a3, 0x54($sp)
  mul.s $f10, $f4, $f8
  mfc1  $a2, $f10
  jal   sub_GAME_7F05BA08
   nop   
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x40
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F05C2F0
  addiu $sp, $sp, -0x40
  sw    $ra, 0x1c($sp)
  sw    $a3, 0x4c($sp)
  sw    $a1, 0x44($sp)
  sw    $a2, 0x48($sp)
  jal   sub_GAME_7F05C138
   addiu $a3, $sp, 0x30
  lw    $a0, 0x44($sp)
  lw    $a1, 0x48($sp)
  lw    $a2, 0x4c($sp)
  jal   sub_GAME_7F05C138
   addiu $a3, $sp, 0x20
  lwc1  $f4, 0x50($sp)
  lw    $t6, 0x54($sp)
  lw    $a0, 0x44($sp)
  addiu $a1, $sp, 0x30
  addiu $a2, $sp, 0x20
  lw    $a3, 0x48($sp)
  swc1  $f4, 0x10($sp)
  jal   sub_GAME_7F05C250
   sw    $t6, 0x14($sp)
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x40
  jr    $ra
   nop   
");
