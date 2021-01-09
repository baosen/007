asm(R"
glabel sub_GAME_7F05AE00
  lwc1  $f0, ($a0)
  lwc1  $f4, ($a1)
  mtc1  $a2, $f12
  sub.s $f6, $f4, $f0
  mul.s $f8, $f6, $f12
  add.s $f10, $f8, $f0
  swc1  $f10, ($a3)
  lwc1  $f16, 4($a1)
  lwc1  $f2, 4($a0)
  sub.s $f18, $f16, $f2
  mul.s $f4, $f18, $f12
  add.s $f6, $f4, $f2
  swc1  $f6, 4($a3)
  lwc1  $f8, 8($a1)
  lwc1  $f14, 8($a0)
  sub.s $f10, $f8, $f14
  mul.s $f16, $f10, $f12
  add.s $f18, $f16, $f14
  jr    $ra
   swc1  $f18, 8($a3)
");

asm(R"
glabel sub_GAME_7F05AE50
  lwc1  $f4, 0x10($sp)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f18
  mul.s $f2, $f4, $f4
  li    $at, 0x3FC00000 # 1.500000
  mtc1  $at, $f6
  li    $at, 0x40200000 # 2.500000
  mtc1  $at, $f10
  li    $at, 0x3F800000 # 1.000000
  sw    $a2, 8($sp)
  mul.s $f16, $f2, $f4
  sw    $a3, 0xc($sp)
  mul.s $f8, $f6, $f16
  nop   
  mul.s $f6, $f10, $f2
  sub.s $f10, $f8, $f6
  mtc1  $at, $f8
  li    $at, 0xBFC00000 # -1.500000
  add.s $f6, $f10, $f8
  add.s $f8, $f4, $f16
  mul.s $f10, $f14, $f6
  nop   
  mul.s $f6, $f8, $f18
  sub.s $f8, $f2, $f6
  mul.s $f6, $f12, $f8
  add.s $f8, $f6, $f10
  mtc1  $at, $f6
  nop   
  mul.s $f10, $f6, $f16
  add.s $f6, $f2, $f2
  add.s $f10, $f10, $f6
  mul.s $f6, $f18, $f4
  add.s $f4, $f10, $f6
  lwc1  $f10, 8($sp)
  mul.s $f6, $f10, $f4
  lwc1  $f4, 0xc($sp)
  add.s $f10, $f8, $f6
  sub.s $f8, $f16, $f2
  mul.s $f6, $f8, $f18
  nop   
  mul.s $f8, $f4, $f6
  jr    $ra
   add.s $f0, $f10, $f8
");

asm(R"
glabel sub_GAME_7F05AEFC
  addiu $sp, $sp, -0x28
  lwc1  $f12, 0x38($sp)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f6
  mul.s $f0, $f12, $f12
  lw    $t6, 0x3c($sp)
  mul.s $f2, $f0, $f12
  sub.s $f4, $f2, $f0
  add.s $f10, $f12, $f2
  mul.s $f8, $f4, $f6
  mtc1  $at, $f4
  li    $at, 0x3FC00000 # 1.500000
  mul.s $f6, $f10, $f4
  mtc1  $at, $f10
  li    $at, 0x40200000 # 2.500000
  swc1  $f8, ($sp)
  mul.s $f4, $f10, $f2
  sub.s $f14, $f0, $f6
  mtc1  $at, $f6
  li    $at, 0x3F800000 # 1.000000
  mul.s $f10, $f6, $f0
  sub.s $f6, $f4, $f10
  mtc1  $at, $f4
  li    $at, 0xBFC00000 # -1.500000
  mtc1  $at, $f10
  add.s $f16, $f6, $f4
  li    $at, 0x3F000000 # 0.500000
  mul.s $f6, $f10, $f2
  add.s $f4, $f0, $f0
  add.s $f10, $f6, $f4
  mtc1  $at, $f6
  nop   
  mul.s $f4, $f6, $f12
  lwc1  $f6, ($a3)
  add.s $f18, $f10, $f4
  mul.s $f10, $f6, $f8
  lwc1  $f4, ($a0)
  mul.s $f6, $f14, $f4
  lwc1  $f4, ($a1)
  mul.s $f4, $f16, $f4
  add.s $f6, $f6, $f4
  lwc1  $f4, ($a2)
  mul.s $f4, $f18, $f4
  add.s $f6, $f6, $f4
  add.s $f4, $f10, $f6
  swc1  $f4, ($t6)
  lwc1  $f10, 4($a3)
  lwc1  $f4, 4($a0)
  mul.s $f6, $f10, $f8
  nop   
  mul.s $f10, $f14, $f4
  lwc1  $f4, 4($a1)
  mul.s $f4, $f16, $f4
  add.s $f10, $f10, $f4
  lwc1  $f4, 4($a2)
  mul.s $f4, $f18, $f4
  add.s $f10, $f10, $f4
  add.s $f4, $f6, $f10
  swc1  $f4, 4($t6)
  lwc1  $f6, 8($a3)
  lwc1  $f4, 8($a0)
  mul.s $f10, $f6, $f8
  lwc1  $f8, 8($a1)
  mul.s $f6, $f14, $f4
  nop   
  mul.s $f4, $f16, $f8
  add.s $f8, $f6, $f4
  lwc1  $f6, 8($a2)
  addiu $sp, $sp, 0x28
  mul.s $f4, $f18, $f6
  add.s $f6, $f8, $f4
  add.s $f8, $f10, $f6
  jr    $ra
   swc1  $f8, 8($t6)
");

asm(R"
glabel sub_GAME_7F05B024
  addiu $sp, $sp, -0x28
  lwc1  $f12, 0x38($sp)
  lwc1  $f14, 0x3c($sp)
  li    $at, 0x40000000 # 2.000000
  mul.s $f0, $f12, $f12
  lw    $t6, 0x40($sp)
  mul.s $f2, $f0, $f12
  add.s $f8, $f0, $f0
  sub.s $f4, $f2, $f0
  add.s $f10, $f12, $f2
  mul.s $f6, $f4, $f14
  sub.s $f4, $f8, $f10
  mtc1  $at, $f8
  li    $at, 0x40400000 # 3.000000
  swc1  $f6, ($sp)
  sub.s $f10, $f8, $f14
  mul.s $f16, $f4, $f14
  mtc1  $at, $f8
  li    $at, 0x3F800000 # 1.000000
  mul.s $f4, $f10, $f2
  sub.s $f10, $f14, $f8
  mul.s $f8, $f0, $f10
  add.s $f10, $f4, $f8
  mtc1  $at, $f4
  li    $at, 0x40400000 # 3.000000
  mtc1  $at, $f8
  add.s $f18, $f10, $f4
  li    $at, 0x40000000 # 2.000000
  add.s $f10, $f14, $f14
  sub.s $f4, $f8, $f10
  mtc1  $at, $f10
  mul.s $f8, $f0, $f4
  sub.s $f4, $f14, $f10
  mul.s $f10, $f4, $f2
  add.s $f4, $f10, $f8
  mul.s $f10, $f12, $f14
  add.s $f8, $f4, $f10
  swc1  $f8, 8($sp)
  lwc1  $f4, ($a0)
  mul.s $f10, $f16, $f4
  lwc1  $f4, ($a1)
  mul.s $f4, $f18, $f4
  add.s $f10, $f10, $f4
  lwc1  $f4, ($a2)
  mul.s $f4, $f8, $f4
  add.s $f10, $f10, $f4
  lwc1  $f4, ($a3)
  mul.s $f4, $f4, $f6
  add.s $f4, $f4, $f10
  swc1  $f4, ($t6)
  lwc1  $f10, 4($a0)
  mul.s $f4, $f16, $f10
  lwc1  $f10, 4($a1)
  mul.s $f10, $f18, $f10
  add.s $f4, $f4, $f10
  lwc1  $f10, 4($a2)
  mul.s $f10, $f8, $f10
  add.s $f4, $f4, $f10
  lwc1  $f10, 4($a3)
  mul.s $f10, $f10, $f6
  add.s $f10, $f10, $f4
  swc1  $f10, 4($t6)
  lwc1  $f4, 8($a0)
  mul.s $f10, $f16, $f4
  lwc1  $f4, 8($a1)
  mul.s $f4, $f18, $f4
  add.s $f10, $f10, $f4
  lwc1  $f4, 8($a2)
  mul.s $f8, $f8, $f4
  add.s $f4, $f10, $f8
  lwc1  $f10, 8($a3)
  addiu $sp, $sp, 0x28
  mul.s $f8, $f10, $f6
  add.s $f10, $f8, $f4
  jr    $ra
   swc1  $f10, 8($t6)
");

asm(R"
glabel sub_GAME_7F05B154
  lwc1  $f4, 0x10($sp)
  li    $at, 0x40400000 # 3.000000
  mtc1  $at, $f8
  mul.s $f2, $f4, $f4
  li    $at, 0x3F800000 # 1.000000
  sw    $a2, 8($sp)
  sw    $a3, 0xc($sp)
  mul.s $f16, $f2, $f4
  add.s $f6, $f16, $f16
  mul.s $f10, $f8, $f2
  sub.s $f8, $f6, $f10
  mtc1  $at, $f6
  nop   
  add.s $f18, $f8, $f6
  mtc1  $at, $f8
  nop   
  sub.s $f6, $f8, $f18
  mul.s $f10, $f12, $f18
  nop   
  mul.s $f8, $f14, $f6
  add.s $f6, $f10, $f8
  add.s $f10, $f2, $f2
  sub.s $f8, $f16, $f10
  add.s $f10, $f8, $f4
  lwc1  $f8, 8($sp)
  mul.s $f4, $f8, $f10
  lwc1  $f10, 0xc($sp)
  add.s $f8, $f6, $f4
  sub.s $f6, $f16, $f2
  mul.s $f4, $f10, $f6
  jr    $ra
   add.s $f0, $f8, $f4
");
