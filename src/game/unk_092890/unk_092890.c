asm(R"
glabel sub_GAME_7F092890
  addiu $sp, $sp, -0x158
  sdc1  $f30, 0x30($sp)
  sdc1  $f28, 0x28($sp)
  sdc1  $f26, 0x20($sp)
  sdc1  $f24, 0x18($sp)
  sdc1  $f22, 0x10($sp)
  sdc1  $f20, 8($sp)
  lwc1  $f4, ($a3)
  lw    $t1, 0x170($sp)
  lw    $t2, 0x16c($sp)
  cvt.d.s $f8, $f4
  sdc1  $f8, 0x90($sp)
  lwc1  $f10, 4($a3)
  cvt.d.s $f6, $f10
  sdc1  $f6, 0x98($sp)
  lwc1  $f4, 8($a3)
  cvt.d.s $f8, $f4
  sdc1  $f8, 0xa0($sp)
  lwc1  $f10, ($t1)
  cvt.d.s $f6, $f10
  sdc1  $f6, 0x78($sp)
  lwc1  $f4, 4($t1)
  cvt.d.s $f8, $f4
  sdc1  $f8, 0x80($sp)
  lwc1  $f10, 8($t1)
  cvt.d.s $f4, $f10
  sdc1  $f4, 0x88($sp)
  lwc1  $f10, ($t2)
  cvt.d.s $f10, $f10
  sdc1  $f10, 0x60($sp)
  lwc1  $f10, 4($t2)
  cvt.d.s $f10, $f10
  sdc1  $f10, 0x68($sp)
  lwc1  $f10, 8($t2)
  cvt.d.s $f10, $f10
  sdc1  $f10, 0x70($sp)
  lh    $t4, ($a0)
  lh    $t3, ($a1)
  subu  $t5, $t3, $t4
  mtc1  $t5, $f10
  nop   
  cvt.d.w $f10, $f10
  sdc1  $f10, 0x140($sp)
  lh    $t6, ($a2)
  lh    $t7, ($a1)
  sdc1  $f6, 0x38($sp)
  subu  $t8, $t6, $t7
  mtc1  $t8, $f6
  nop   
  cvt.d.w $f6, $f6
  sdc1  $f6, 0x128($sp)
  lh    $t0, 2($a0)
  lh    $t9, 2($a1)
  sdc1  $f8, 0x40($sp)
  subu  $t1, $t9, $t0
  mtc1  $t1, $f8
  nop   
  cvt.d.w $f8, $f8
  sdc1  $f8, 0x148($sp)
  lh    $t2, 2($a2)
  lh    $t3, 2($a1)
  subu  $t4, $t2, $t3
  mtc1  $t4, $f8
  nop   
  cvt.d.w $f8, $f8
  sdc1  $f8, 0x130($sp)
  lh    $t6, 4($a0)
  lh    $t5, 4($a1)
  subu  $t7, $t5, $t6
  mtc1  $t7, $f8
  nop   
  cvt.d.w $f8, $f8
  sdc1  $f8, 0x150($sp)
  lh    $t8, 4($a2)
  lh    $t9, 4($a1)
  subu  $t0, $t8, $t9
  mtc1  $t0, $f8
  nop   
  cvt.d.w $f8, $f8
  sdc1  $f8, 0x138($sp)
  lh    $t2, ($a0)
  lh    $t1, ($a2)
  subu  $t3, $t1, $t2
  mtc1  $t3, $f8
  nop   
  cvt.d.w $f8, $f8
  sdc1  $f8, 0x110($sp)
  lh    $t5, 2($a0)
  lh    $t4, 2($a2)
  subu  $t6, $t4, $t5
  mtc1  $t6, $f8
  nop   
  cvt.d.w $f8, $f8
  sdc1  $f8, 0x118($sp)
  lh    $t8, 4($a0)
  lh    $t7, 4($a2)
  sdc1  $f4, 0x48($sp)
  ldc1  $f4, 0x138($sp)
  subu  $t9, $t7, $t8
  mtc1  $t9, $f8
  nop   
  cvt.d.w $f8, $f8
  sdc1  $f8, 0x120($sp)
  ldc1  $f8, 0x148($sp)
  mul.d $f18, $f8, $f4
  ldc1  $f4, 0x130($sp)
  ldc1  $f8, 0x150($sp)
  mul.d $f20, $f8, $f4
  ldc1  $f4, 0x138($sp)
  mul.d $f22, $f8, $f6
  ldc1  $f8, 0x130($sp)
  mul.d $f24, $f10, $f4
  ldc1  $f4, 0x148($sp)
  sub.d $f12, $f18, $f20
  mul.d $f26, $f10, $f8
  nop   
  mul.d $f28, $f4, $f6
  ldc1  $f4, 0x90($sp)
  sub.d $f14, $f22, $f24
  sub.d $f16, $f26, $f28
  sdc1  $f16, 0xf8($sp)
  lh    $t0, ($a0)
  lh    $t1, 2($a0)
  lh    $t2, 4($a0)
  mtc1  $t0, $f10
  sdc1  $f14, 0x100($sp)
  sdc1  $f12, 0x108($sp)
  cvt.d.w $f8, $f10
  add.d $f6, $f8, $f4
  mtc1  $t1, $f8
  nop   
  cvt.d.w $f4, $f8
  mul.d $f10, $f12, $f6
  ldc1  $f6, 0x98($sp)
  add.d $f8, $f4, $f6
  mul.d $f4, $f14, $f8
  ldc1  $f8, 0xa0($sp)
  add.d $f6, $f10, $f4
  mtc1  $t2, $f10
  nop   
  cvt.d.w $f4, $f10
  add.d $f10, $f8, $f4
  ldc1  $f8, 0x48($sp)
  mul.d $f4, $f10, $f16
  add.d $f10, $f4, $f6
  mul.d $f6, $f8, $f16
  ldc1  $f4, 0x40($sp)
  sdc1  $f10, 0xf0($sp)
  ldc1  $f10, 0x38($sp)
  mul.d $f8, $f12, $f10
  nop   
  mul.d $f10, $f14, $f4
  add.d $f4, $f8, $f10
  mtc1  $zero, $f8
  mtc1  $zero, $f9
  add.d $f0, $f6, $f4
  ldc1  $f6, 0x60($sp)
  c.eq.d $f0, $f8
  nop   
  bc1f  .L7F092B1C
   nop   
  b     .L7F092E2C
   move  $v0, $zero
.L7F092B1C:
  mul.d $f4, $f12, $f6
  ldc1  $f10, 0xf0($sp)
  sdc1  $f6, 0x48($sp)
  sub.d $f30, $f28, $f26
  move  $v0, $zero
  sub.d $f8, $f10, $f4
  ldc1  $f10, 0x68($sp)
  mul.d $f4, $f14, $f10
  sdc1  $f10, 0x40($sp)
  sub.d $f8, $f8, $f4
  ldc1  $f4, 0x70($sp)
  mul.d $f6, $f4, $f16
  sdc1  $f4, 0x38($sp)
  ldc1  $f4, 0x80($sp)
  sub.d $f8, $f8, $f6
  ldc1  $f6, 0x78($sp)
  mul.d $f10, $f12, $f6
  sdc1  $f8, 0x50($sp)
  sdc1  $f6, 0x58($sp)
  mul.d $f8, $f14, $f4
  ldc1  $f14, 0x148($sp)
  add.d $f10, $f10, $f8
  ldc1  $f8, 0x88($sp)
  mul.d $f6, $f8, $f16
  mtc1  $zero, $f16
  mtc1  $zero, $f17
  add.d $f6, $f6, $f10
  ldc1  $f10, 0x50($sp)
  div.d $f2, $f10, $f6
  ldc1  $f10, 0x58($sp)
  mul.d $f6, $f10, $f2
  ldc1  $f10, 0x48($sp)
  add.d $f6, $f6, $f10
  mul.d $f10, $f4, $f2
  ldc1  $f4, 0x40($sp)
  sdc1  $f6, 0xc8($sp)
  add.d $f10, $f10, $f4
  mul.d $f4, $f8, $f2
  ldc1  $f8, 0x38($sp)
  sdc1  $f10, 0xd0($sp)
  add.d $f4, $f4, $f8
  ldc1  $f8, 0x90($sp)
  sdc1  $f4, 0xd8($sp)
  lh    $t3, ($a0)
  sdc1  $f10, 0x58($sp)
  mtc1  $t3, $f10
  nop   
  cvt.d.w $f10, $f10
  add.d $f8, $f8, $f10
  sub.d $f10, $f6, $f8
  ldc1  $f8, 0x98($sp)
  ldc1  $f6, 0x58($sp)
  sdc1  $f10, 0xb0($sp)
  lh    $t4, 2($a0)
  mtc1  $t4, $f10
  nop   
  cvt.d.w $f10, $f10
  add.d $f8, $f8, $f10
  sub.d $f10, $f6, $f8
  ldc1  $f6, 0xa0($sp)
  sdc1  $f10, 0xb8($sp)
  lh    $t5, 4($a0)
  mtc1  $t5, $f8
  nop   
  cvt.d.w $f10, $f8
  add.d $f8, $f6, $f10
  mtc1  $zero, $f10
  mtc1  $zero, $f11
  sub.d $f6, $f4, $f8
  ldc1  $f4, 0xb0($sp)
  c.eq.d $f30, $f10
  sdc1  $f6, 0xc0($sp)
  ldc1  $f6, 0xb8($sp)
  bc1tl .L7F092C64
   sub.d $f12, $f20, $f18
  mul.d $f8, $f4, $f14
  ldc1  $f12, 0x140($sp)
  mul.d $f10, $f12, $f6
  sub.d $f4, $f8, $f10
  b     .L7F092CCC
   div.d $f2, $f4, $f30
  sub.d $f12, $f20, $f18
.L7F092C64:
  mtc1  $zero, $f7
  mtc1  $zero, $f6
  ldc1  $f8, 0xb8($sp)
  ldc1  $f4, 0xb0($sp)
  c.eq.d $f12, $f6
  ldc1  $f6, 0x150($sp)
  ldc1  $f10, 0xc0($sp)
  bc1t  .L7F092CB0
   nop   
  ldc1  $f10, 0x150($sp)
  ldc1  $f14, 0x148($sp)
  ldc1  $f6, 0xc0($sp)
  mul.d $f4, $f8, $f10
  nop   
  mul.d $f8, $f14, $f6
  sub.d $f10, $f4, $f8
  div.d $f2, $f10, $f12
  b     .L7F092CCC
   ldc1  $f12, 0x140($sp)
.L7F092CB0:
  mul.d $f8, $f6, $f4
  ldc1  $f12, 0x140($sp)
  sub.d $f0, $f24, $f22
  ldc1  $f14, 0x148($sp)
  mul.d $f6, $f10, $f12
  sub.d $f4, $f6, $f8
  div.d $f2, $f4, $f0
.L7F092CCC:
  c.eq.d $f16, $f12
  ldc1  $f6, 0x110($sp)
  bc1tl .L7F092CF4
   c.eq.d $f16, $f14
  mul.d $f8, $f2, $f6
  ldc1  $f10, 0xb0($sp)
  sub.d $f4, $f10, $f8
  b     .L7F092D2C
   div.d $f0, $f4, $f12
  c.eq.d $f16, $f14
.L7F092CF4:
  ldc1  $f10, 0x118($sp)
  ldc1  $f6, 0x120($sp)
  bc1t  .L7F092D18
   nop   
  mul.d $f8, $f2, $f10
  ldc1  $f6, 0xb8($sp)
  sub.d $f4, $f6, $f8
  b     .L7F092D2C
   div.d $f0, $f4, $f14
.L7F092D18:
  mul.d $f8, $f2, $f6
  ldc1  $f10, 0xc0($sp)
  ldc1  $f6, 0x150($sp)
  sub.d $f4, $f10, $f8
  div.d $f0, $f4, $f6
.L7F092D2C:
  c.le.d $f16, $f0
  nop   
  bc1f  .L7F092E2C
   nop   
  c.le.d $f16, $f2
  li    $at, 0x3FF00000 # 1.875000
  bc1f  .L7F092E2C
   nop   
  add.d $f8, $f0, $f2
  mtc1  $at, $f11
  mtc1  $zero, $f10
  nop   
  c.le.d $f8, $f10
  nop   
  bc1f  .L7F092E2C
   nop   
  lw    $v0, 0x168($sp)
  ldc1  $f4, 0xc8($sp)
  lwc1  $f6, ($v0)
  cvt.d.s $f10, $f6
  ldc1  $f6, 0x78($sp)
  sub.d $f8, $f4, $f10
  mul.d $f10, $f6, $f8
  lwc1  $f8, 4($v0)
  ldc1  $f6, 0xd0($sp)
  cvt.d.s $f8, $f8
  sub.d $f6, $f6, $f8
  ldc1  $f8, 0x80($sp)
  mul.d $f8, $f8, $f6
  add.d $f6, $f10, $f8
  lwc1  $f8, 8($v0)
  ldc1  $f10, 0xd8($sp)
  cvt.d.s $f8, $f8
  sub.d $f10, $f10, $f8
  ldc1  $f8, 0x88($sp)
  mul.d $f10, $f10, $f8
  add.d $f8, $f10, $f6
  c.le.d $f16, $f8
  nop   
  bc1f  .L7F092E24
   nop   
  cvt.s.d $f10, $f4
  lw    $v1, 0x174($sp)
  li    $v0, 1
  swc1  $f10, ($v1)
  ldc1  $f6, 0xd0($sp)
  cvt.s.d $f8, $f6
  swc1  $f8, 4($v1)
  ldc1  $f4, 0xd8($sp)
  cvt.s.d $f10, $f4
  swc1  $f10, 8($v1)
  ldc1  $f6, 0x108($sp)
  cvt.s.d $f8, $f6
  swc1  $f8, 0xc($v1)
  ldc1  $f4, 0x100($sp)
  cvt.s.d $f10, $f4
  swc1  $f10, 0x10($v1)
  ldc1  $f6, 0xf8($sp)
  sh    $zero, 0x2a($v1)
  cvt.s.d $f8, $f6
  b     .L7F092E2C
   swc1  $f8, 0x14($v1)
.L7F092E24:
  b     .L7F092E2C
   move  $v0, $zero
.L7F092E2C:
  ldc1  $f20, 8($sp)
  ldc1  $f22, 0x10($sp)
  ldc1  $f24, 0x18($sp)
  ldc1  $f26, 0x20($sp)
  ldc1  $f28, 0x28($sp)
  ldc1  $f30, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x158
");
