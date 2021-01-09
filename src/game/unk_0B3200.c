asm(R"
glabel sub_GAME_7F0B3200
  lwc1  $f14, ($a2)
  lwc1  $f6, ($a3)
  lwc1  $f8, 4($a0)
  lwc1  $f2, 4($a2)
  lwc1  $f4, 4($a3)
  lwc1  $f18, ($a0)
  addiu $sp, $sp, -0x20
  sub.s $f12, $f6, $f14
  swc1  $f8, ($sp)
  lwc1  $f6, ($sp)
  sub.s $f0, $f2, $f4
  li    $at, 0x3F800000 # 1.000000
  sub.s $f10, $f14, $f18
  sub.s $f8, $f2, $f6
  mul.s $f4, $f10, $f0
  nop   
  mul.s $f10, $f8, $f12
  lwc1  $f8, 4($a1)
  add.s $f16, $f4, $f10
  sub.s $f4, $f8, $f6
  lwc1  $f8, ($a1)
  sub.s $f6, $f8, $f18
  mul.s $f10, $f4, $f12
  nop   
  mul.s $f4, $f6, $f0
  mtc1  $zero, $f6
  add.s $f8, $f4, $f10
  c.eq.s $f8, $f6
  swc1  $f8, 0x10($sp)
  lwc1  $f4, 0x10($sp)
  bc1f  .L7F0B328C
   nop   
  mtc1  $at, $f0
  b     .L7F0B32D0
   nop   
.L7F0B328C:
  div.s $f16, $f16, $f4
  mtc1  $zero, $f10
  lui   $at, 0x3f80
  c.lt.s $f16, $f10
  nop   
  bc1tl .L7F0B32C0
   li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  nop   
  c.lt.s $f8, $f16
  nop   
  bc1f  .L7F0B32CC
   li    $at, 0x3F800000 # 1.000000
.L7F0B32C0:
  mtc1  $at, $f0
  b     .L7F0B32D0
   nop   
.L7F0B32CC:
  mov.s $f0, $f16
.L7F0B32D0:
  jr    $ra
   addiu $sp, $sp, 0x20
");

asm(R"
.late_rodata
glabel D_800585E0
.word 0x7f7fffff /*3.4028235e38*/
glabel D_800585E4
.word 0x7f7fffff /*3.4028235e38*/
.text
glabel sub_GAME_7F0B32D8
  addiu $sp, $sp, -0x30
  sw    $ra, 0x1c($sp)
  sdc1  $f20, 0x10($sp)
  lwc1  $f10, 8($a0)
  lwc1  $f8, 4($a2)
  lwc1  $f6, 4($a0)
  lwc1  $f4, ($a2)
  sub.s $f12, $f8, $f10
  lwc1  $f14, ($a1)
  lwc1  $f16, 4($a1)
  sub.s $f0, $f4, $f6
  mul.s $f4, $f14, $f12
  lwc1  $f18, ($a0)
  lui   $at, %hi(D_800585E0)
  mul.s $f6, $f0, $f16
  sub.s $f20, $f4, $f6
  mul.s $f8, $f14, $f0
  nop   
  mul.s $f10, $f12, $f16
  sub.s $f4, $f18, $f20
  add.s $f6, $f18, $f20
  add.s $f2, $f8, $f10
  mul.s $f8, $f4, $f6
  mtc1  $zero, $f10
  nop   
  c.lt.s $f8, $f10
  swc1  $f8, 0x24($sp)
  lwc1  $f12, 0x24($sp)
  bc1f  .L7F0B3358
   nop   
  b     .L7F0B33C8
   lwc1  $f0, %lo(D_800585E0)($at)
.L7F0B3358:
  sw    $a0, 0x30($sp)
  jal   sqrtf
   swc1  $f2, 0x2c($sp)
  lwc1  $f2, 0x2c($sp)
  mtc1  $zero, $f12
  lw    $a0, 0x30($sp)
  sub.s $f2, $f2, $f0
  c.lt.s $f2, $f12
  nop   
  bc1fl .L7F0B33C8
   mov.s $f0, $f2
  lwc1  $f18, ($a0)
  lui   $at, %hi(D_800585E4)
  mul.s $f4, $f18, $f18
  nop   
  mul.s $f6, $f2, $f2
  nop   
  mul.s $f8, $f20, $f20
  add.s $f10, $f6, $f8
  c.le.s $f10, $f4
  nop   
  bc1f  .L7F0B33BC
   nop   
  b     .L7F0B33C8
   mov.s $f0, $f12
.L7F0B33BC:
  b     .L7F0B33C8
   lwc1  $f0, %lo(D_800585E4)($at)
  mov.s $f0, $f2
.L7F0B33C8:
  lw    $ra, 0x1c($sp)
  ldc1  $f20, 0x10($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B33DC
  addiu $sp, $sp, -0xb0
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a2, 0xb8($sp)
  lwc1  $f0, ($a3)
  lwc1  $f2, 4($a3)
  move  $s0, $a1
  mul.s $f4, $f0, $f0
  sw    $a3, 0xbc($sp)
  sw    $a0, 0xb0($sp)
  mul.s $f10, $f2, $f2
  jal   sqrtf
   add.s $f12, $f4, $f10
  mtc1  $zero, $f6
  lw    $a0, 0xb0($sp)
  lw    $a3, 0xbc($sp)
  c.eq.s $f0, $f6
  mov.s $f14, $f0
  li    $at, 0x3F800000 # 1.000000
  bc1fl .L7F0B3444
   mtc1  $at, $f8
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f0
  b     .L7F0B37AC
   lw    $ra, 0x1c($sp)
  mtc1  $at, $f8
.L7F0B3444:
  lwc1  $f4, ($a3)
  lw    $v0, 0xb8($sp)
  div.s $f16, $f8, $f14
  mul.s $f10, $f4, $f16
  swc1  $f10, 0xa0($sp)
  lwc1  $f6, 4($a3)
  mul.s $f8, $f6, $f16
  swc1  $f8, 0xa4($sp)
  lwc1  $f10, ($s0)
  lwc1  $f4, ($v0)
  lwc1  $f8, 4($s0)
  lwc1  $f6, 4($v0)
  sub.s $f0, $f4, $f10
  swc1  $f16, 0x44($sp)
  swc1  $f14, 0xac($sp)
  sub.s $f2, $f6, $f8
  mul.s $f4, $f0, $f0
  swc1  $f0, 0x98($sp)
  sw    $a3, 0xbc($sp)
  mul.s $f10, $f2, $f2
  swc1  $f2, 0x9c($sp)
  sw    $a0, 0xb0($sp)
  jal   sqrtf
   add.s $f12, $f4, $f10
  mtc1  $zero, $f6
  lw    $a0, 0xb0($sp)
  lw    $a3, 0xbc($sp)
  c.eq.s $f0, $f6
  li    $at, 0x3F800000 # 1.000000
  addiu $a1, $sp, 0xa0
  bc1t  .L7F0B369C
   nop   
  mtc1  $at, $f8
  lwc1  $f4, 0x9c($sp)
  lwc1  $f6, 0x98($sp)
  div.s $f18, $f8, $f0
  move  $v0, $s0
  neg.s $f8, $f6
  mul.s $f10, $f4, $f18
  nop   
  mul.s $f4, $f8, $f18
  swc1  $f10, 0x2c($sp)
  swc1  $f10, 0x88($sp)
  swc1  $f4, 0x28($sp)
  swc1  $f4, 0x8c($sp)
  lwc1  $f6, ($a0)
  swc1  $f6, 0x38($sp)
  lwc1  $f8, 0x38($sp)
  lwc1  $f6, 4($a0)
  mul.s $f14, $f8, $f10
  swc1  $f6, 0x34($sp)
  lwc1  $f10, 8($a0)
  mul.s $f16, $f8, $f4
  lwc1  $f2, ($s0)
  lwc1  $f8, 0x34($sp)
  swc1  $f10, 0x30($sp)
  lwc1  $f10, 0x30($sp)
  sub.s $f4, $f8, $f2
  lwc1  $f12, 4($s0)
  sub.s $f8, $f10, $f12
  mul.s $f6, $f4, $f14
  nop   
  mul.s $f4, $f16, $f8
  mtc1  $zero, $f8
  add.s $f10, $f6, $f4
  c.lt.s $f10, $f8
  nop   
  bc1f  .L7F0B3560
   nop   
  neg.s $f14, $f14
  neg.s $f16, $f16
.L7F0B3560:
  add.s $f6, $f2, $f14
  lw    $v1, 0xb8($sp)
  add.s $f4, $f12, $f16
  swc1  $f6, 0x78($sp)
  swc1  $f4, 0x7c($sp)
  lwc1  $f10, ($v1)
  add.s $f8, $f10, $f14
  swc1  $f8, 0x70($sp)
  lwc1  $f6, 4($v1)
  add.s $f4, $f6, $f16
  lwc1  $f16, 0x2c($sp)
  swc1  $f4, 0x74($sp)
  lwc1  $f10, 4($a3)
  lwc1  $f4, 0x78($sp)
  swc1  $f10, 0x48($sp)
  lwc1  $f8, ($a3)
  lwc1  $f6, 0x48($sp)
  swc1  $f8, 0x4c($sp)
  mul.s $f10, $f6, $f4
  lwc1  $f4, 0x4c($sp)
  lwc1  $f8, 0x7c($sp)
  swc1  $f4, 0x20($sp)
  mul.s $f8, $f8, $f4
  lwc1  $f4, 0x30($sp)
  sub.s $f10, $f10, $f8
  lwc1  $f8, 0x34($sp)
  swc1  $f10, 0x68($sp)
  swc1  $f10, 0x24($sp)
  mul.s $f8, $f8, $f6
  lwc1  $f10, 0x20($sp)
  mul.s $f4, $f4, $f10
  sub.s $f14, $f8, $f4
  lwc1  $f4, 0x70($sp)
  mul.s $f6, $f6, $f4
  lwc1  $f4, 0x74($sp)
  swc1  $f14, 0x6c($sp)
  mul.s $f4, $f4, $f10
  lwc1  $f10, 0x24($sp)
  mov.s $f12, $f10
  sub.s $f18, $f6, $f4
  lwc1  $f6, 0x28($sp)
  c.lt.s $f18, $f10
  nop   
  bc1fl .L7F0B3638
   c.eq.s $f18, $f12
  neg.s $f16, $f16
  neg.s $f4, $f6
  mov.s $f12, $f18
  move  $s0, $v1
  mov.s $f18, $f10
  move  $v1, $v0
  swc1  $f4, 0x8c($sp)
  swc1  $f16, 0x88($sp)
  c.eq.s $f18, $f12
.L7F0B3638:
  lwc1  $f16, 0x88($sp)
  move  $a2, $s0
  bc1fl .L7F0B368C
   c.lt.s $f18, $f14
  addiu $a1, $sp, 0xa0
  sw    $v1, 0xb8($sp)
  jal   sub_GAME_7F0B32D8
   sw    $a0, 0xb0($sp)
  lw    $a0, 0xb0($sp)
  addiu $a1, $sp, 0xa0
  lw    $a2, 0xb8($sp)
  jal   sub_GAME_7F0B32D8
   swc1  $f0, 0x60($sp)
  lwc1  $f2, 0x60($sp)
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F0B375C
   lwc1  $f8, 0xac($sp)
  b     .L7F0B3758
   mov.s $f2, $f0
  c.lt.s $f18, $f14
.L7F0B368C:
  nop   
  bc1fl .L7F0B36B0
   c.lt.s $f14, $f12
  sw    $v1, 0xb8($sp)
.L7F0B369C:
  jal   sub_GAME_7F0B32D8
   lw    $a2, 0xb8($sp)
  b     .L7F0B3758
   mov.s $f2, $f0
  c.lt.s $f14, $f12
.L7F0B36B0:
  addiu $a1, $sp, 0xa0
  lwc1  $f8, 0x30($sp)
  bc1fl .L7F0B36D4
   lwc1  $f12, 4($s0)
  jal   sub_GAME_7F0B32D8
   move  $a2, $s0
  b     .L7F0B3758
   mov.s $f2, $f0
  lwc1  $f12, 4($s0)
.L7F0B36D4:
  lwc1  $f10, 0x8c($sp)
  lwc1  $f2, ($s0)
  sub.s $f6, $f8, $f12
  swc1  $f10, 0x24($sp)
  li    $at, 0x3F800000 # 1.000000
  mul.s $f4, $f10, $f6
  lwc1  $f6, 0x34($sp)
  sub.s $f10, $f6, $f2
  mul.s $f10, $f10, $f16
  add.s $f0, $f10, $f4
  lwc1  $f10, 0x4c($sp)
  add.s $f4, $f6, $f10
  sub.s $f6, $f4, $f2
  lwc1  $f4, 0x48($sp)
  mul.s $f10, $f6, $f16
  add.s $f6, $f8, $f4
  lwc1  $f4, 0x24($sp)
  sub.s $f8, $f6, $f12
  mul.s $f6, $f4, $f8
  lwc1  $f4, 0x38($sp)
  add.s $f14, $f10, $f6
  c.eq.s $f0, $f14
  nop   
  bc1fl .L7F0B3748
   sub.s $f8, $f0, $f4
  mtc1  $at, $f0
  b     .L7F0B37AC
   lw    $ra, 0x1c($sp)
  sub.s $f8, $f0, $f4
.L7F0B3748:
  lwc1  $f10, 0xac($sp)
  sub.s $f4, $f0, $f14
  mul.s $f6, $f8, $f10
  div.s $f2, $f6, $f4
.L7F0B3758:
  lwc1  $f8, 0xac($sp)
.L7F0B375C:
  li    $at, 0x3F800000 # 1.000000
  c.lt.s $f8, $f2
  nop   
  bc1fl .L7F0B3780
   mtc1  $zero, $f10
  mtc1  $at, $f0
  b     .L7F0B37AC
   lw    $ra, 0x1c($sp)
  mtc1  $zero, $f10
.L7F0B3780:
  lwc1  $f6, 0x44($sp)
  c.lt.s $f2, $f10
  nop   
  bc1f  .L7F0B37A0
   nop   
  mtc1  $zero, $f0
  b     .L7F0B37AC
   lw    $ra, 0x1c($sp)
.L7F0B37A0:
  mul.s $f0, $f2, $f6
  nop   
  lw    $ra, 0x1c($sp)
.L7F0B37AC:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0xb0
  jr    $ra
   nop   
");
