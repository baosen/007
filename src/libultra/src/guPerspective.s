


.section .text   
glabel guPerspectiveF
  addiu $sp, $sp, -0x30
  mtc1  $a2, $f14
  sw    $ra, 0x14($sp)
  sw    $a3, 0x3c($sp)
  sw    $a0, 0x30($sp)
  sw    $a1, 0x34($sp)
  jal   guMtxIdentF
   swc1  $f14, 0x38($sp)
  lwc1  $f14, 0x38($sp)
  lui    $at, %hi(F64_80029430) #0x80030000
  ldc1  $f6, %lo(F64_80029430)($at) # -0x6bd0($at)
  cvt.d.s $f4, $f14
  li    $at, 0x40000000 # 2.000000
  mul.d $f8, $f4, $f6
  mtc1  $at, $f10
  cvt.s.d $f14, $f8
  div.s $f12, $f14, $f10
  jal   cosf
   swc1  $f12, 0x1c($sp)
  lwc1  $f12, 0x1c($sp)
  jal   sinf
   swc1  $f0, 0x20($sp)
  lwc1  $f4, 0x20($sp)
  lwc1  $f6, 0x3c($sp)
  lwc1  $f14, 0x40($sp)
  div.s $f2, $f4, $f0
  lwc1  $f16, 0x44($sp)
  li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f4
  add.s $f18, $f14, $f16
  lw    $v0, 0x30($sp)
  li    $at, 0x40000000 # 2.000000
  sub.s $f12, $f14, $f16
  lw    $a1, 0x34($sp)
  swc1  $f4, 0x2c($v0)
  move  $v1, $zero
  li    $a0, 4
  div.s $f10, $f18, $f12
  swc1  $f2, 0x14($v0)
  div.s $f8, $f2, $f6
  mtc1  $at, $f6
  swc1  $f10, 0x28($v0)
  swc1  $f8, ($v0)
  mul.s $f8, $f6, $f14
  mtc1  $zero, $f6
  nop   
  swc1  $f6, 0x3c($v0)
  mul.s $f10, $f8, $f16
  div.s $f4, $f10, $f12
  swc1  $f4, 0x38($v0)
  lwc1  $f0, 0x48($sp)
  lwc1  $f6, ($v0)
  addiu $v1, $v1, 1
  lwc1  $f16, 4($v0)
  mul.s $f10, $f6, $f0
  lwc1  $f12, 8($v0)
  beq   $v1, $a0, .L7000FDA4
   lwc1  $f14, 0xc($v0)
.L7000FD68:
  mul.s $f8, $f16, $f0
  lwc1  $f6, 0x10($v0)
  lwc1  $f16, 0x14($v0)
  mul.s $f4, $f12, $f0
  lwc1  $f12, 0x18($v0)
  addiu $v1, $v1, 1
  mul.s $f2, $f14, $f0
  lwc1  $f14, 0x1c($v0)
  swc1  $f10, ($v0)
  mul.s $f10, $f6, $f0
  swc1  $f8, 4($v0)
  swc1  $f4, 8($v0)
  addiu $v0, $v0, 0x10
  bne   $v1, $a0, .L7000FD68
   swc1  $f2, -4($v0)
.L7000FDA4:
  mul.s $f8, $f16, $f0
  addiu $v0, $v0, 0x10
  swc1  $f10, -0x10($v0)
  mul.s $f4, $f12, $f0
  nop   
  mul.s $f2, $f14, $f0
  swc1  $f8, -0xc($v0)
  swc1  $f4, -8($v0)
  swc1  $f2, -4($v0)
  beqz  $a1, .L7000FEA0
   li    $at, 0x40000000 # 2.000000
  mtc1  $at, $f9
  mtc1  $zero, $f8
  cvt.d.s $f0, $f18
  li    $t6, 65535
  c.le.d $f0, $f8
  li    $at, 0x41000000 # 8.000000
  bc1fl .L7000FDFC
   mtc1  $at, $f11
  b     .L7000FEA0
   sh    $t6, ($a1)
  mtc1  $at, $f11
.L7000FDFC:
  mtc1  $zero, $f10
  li    $t8, 1
  li    $at, 0x41E00000 # 28.000000
  div.d $f4, $f10, $f0
  li    $t0, 1
  cfc1  $t7, $31
  ctc1  $t8, $31
  nop   
  cvt.w.d $f6, $f4
  cfc1  $t8, $31
  nop   
  andi  $t8, $t8, 0x78
  beql  $t8, $zero, .L7000FE80
   mfc1  $t8, $f6
  mtc1  $at, $f7
  mtc1  $zero, $f6
  li    $t8, 1
  sub.d $f6, $f4, $f6
  ctc1  $t8, $31
  nop   
  cvt.w.d $f6, $f6
  cfc1  $t8, $31
  nop   
  andi  $t8, $t8, 0x78
  bnez  $t8, .L7000FE74
   nop   
  mfc1  $t8, $f6
  lui   $at, 0x8000
  b     .L7000FE8C
   or    $t8, $t8, $at
.L7000FE74:
  b     .L7000FE8C
   li    $t8, -1
  mfc1  $t8, $f6
.L7000FE80:
  nop   
  bltz  $t8, .L7000FE74
   nop   
.L7000FE8C:
  ctc1  $t7, $31
  andi  $t9, $t8, 0xffff
  bgtz  $t9, .L7000FEA0
   sh    $t8, ($a1)
  sh    $t0, ($a1)
.L7000FEA0:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   

glabel guPerspective
  addiu $sp, $sp, -0x68
  mtc1  $a2, $f12
  mtc1  $a3, $f14
  lwc1  $f4, 0x78($sp)
  lwc1  $f6, 0x7c($sp)
  lwc1  $f8, 0x80($sp)
  sw    $ra, 0x24($sp)
  sw    $a0, 0x68($sp)
  mfc1  $a2, $f12
  mfc1  $a3, $f14
  addiu $a0, $sp, 0x28
  swc1  $f4, 0x10($sp)
  swc1  $f6, 0x14($sp)
  jal   guPerspectiveF
   swc1  $f8, 0x18($sp)
  addiu $a0, $sp, 0x28
  jal   guMtxF2L
   lw    $a1, 0x68($sp)
  lw    $ra, 0x24($sp)
  addiu $sp, $sp, 0x68
  jr    $ra
   nop   

