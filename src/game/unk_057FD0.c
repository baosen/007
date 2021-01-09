float flt_CODE_bss_80075DA0;

float D_80032310 = 65536.0;
float D_80032314 = 65536.0;

asm(R"
glabel reset_array_of_0x10_floats
  mtc1  $zero, $f2
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f0
  swc1  $f2, 4($a0)
  swc1  $f2, 8($a0)
  swc1  $f2, 0xc($a0)
  swc1  $f2, 0x10($a0)
  swc1  $f2, 0x18($a0)
  swc1  $f2, 0x1c($a0)
  swc1  $f2, 0x20($a0)
  swc1  $f2, 0x24($a0)
  swc1  $f2, 0x2c($a0)
  swc1  $f2, 0x30($a0)
  swc1  $f2, 0x34($a0)
  swc1  $f2, 0x38($a0)
  swc1  $f0, ($a0)
  swc1  $f0, 0x14($a0)
  swc1  $f0, 0x28($a0)
  jr    $ra
   swc1  $f0, 0x3c($a0)
");

asm(R"
glabel sub_GAME_7F058020
  move  $a2, $a0
  li    $a0, 4
  move  $v0, $zero
  move  $v1, $a1
.L7F058030:
  lwc1  $f4, ($a2)
  addiu $v0, $v0, 1
  addiu $v1, $v1, 0x10
  swc1  $f4, -0x10($v1)
  lwc1  $f6, 4($a2)
  addiu $a2, $a2, 0x10
  swc1  $f6, -0xc($v1)
  lwc1  $f8, -8($a2)
  swc1  $f8, -8($v1)
  lwc1  $f10, -4($a2)
  bne   $v0, $a0, .L7F058030
   swc1  $f10, -4($v1)
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F058068
  addiu $sp, $sp, -0x58
  sw    $ra, 0x14($sp)
  sw    $a1, 0x5c($sp)
  jal   sub_GAME_7F0580C8
   addiu $a2, $sp, 0x18
  addiu $a0, $sp, 0x18
  jal   sub_GAME_7F058020
   lw    $a1, 0x5c($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x58
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F058098
  addiu $sp, $sp, -0x58
  sw    $ra, 0x14($sp)
  sw    $a1, 0x5c($sp)
  jal   sub_GAME_7F05818C
   addiu $a2, $sp, 0x18
  addiu $a0, $sp, 0x18
  jal   sub_GAME_7F058020
   lw    $a1, 0x5c($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x58
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0580C8
  move  $v1, $zero
  move  $t0, $a0
  li    $t2, 16
  li    $t1, 4
.L7F0580D8:
  move  $v0, $zero
  addu  $a0, $a2, $v1
  move  $a3, $a1
.L7F0580E4:
  lwc1  $f18, ($t0)
  lwc1  $f16, ($a3)
  lwc1  $f14, 0x10($t0)
  lwc1  $f12, 4($a3)
  mul.s $f16, $f18, $f16
  lwc1  $f18, 0x20($t0)
  lwc1  $f10, 8($a3)
  mul.s $f12, $f14, $f12
  lwc1  $f14, 0xc($a3)
  lwc1  $f8, 0x30($t0)
  mul.s $f10, $f18, $f10
  addiu $v0, $v0, 2
  addiu $a0, $a0, 0x20
  mul.s $f8, $f14, $f8
  addiu $a3, $a3, 0x20
  add.s $f12, $f16, $f12
  add.s $f10, $f12, $f10
  add.s $f10, $f8, $f10
  swc1  $f10, -0x20($a0)
  lwc1  $f10, ($t0)
  lwc1  $f8, -0x10($a3)
  lwc1  $f12, 0x10($t0)
  lwc1  $f16, -0xc($a3)
  mul.s $f8, $f10, $f8
  lwc1  $f10, 0x20($t0)
  lwc1  $f14, -8($a3)
  mul.s $f16, $f12, $f16
  lwc1  $f12, -4($a3)
  lwc1  $f18, 0x30($t0)
  mul.s $f14, $f10, $f14
  nop   
  mul.s $f18, $f12, $f18
  add.s $f16, $f8, $f16
  add.s $f14, $f16, $f14
  add.s $f14, $f18, $f14
  bne   $v0, $t1, .L7F0580E4
   swc1  $f14, -0x10($a0)
  addiu $v1, $v1, 4
  bne   $v1, $t2, .L7F0580D8
   addiu $t0, $t0, 4
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F05818C
  move  $v1, $zero
  move  $t0, $a0
  li    $t4, 12
  li    $t3, 4
  li    $t2, 2
  li    $t1, 3
.L7F0581A4:
  move  $v0, $zero
  addu  $a0, $a2, $v1
  move  $a3, $a1
.L7F0581B0:
  lwc1  $f4, ($t0)
  lwc1  $f6, ($a3)
  lwc1  $f10, 0x10($t0)
  lwc1  $f16, 4($a3)
  mul.s $f8, $f4, $f6
  lwc1  $f6, 8($a3)
  mul.s $f18, $f10, $f16
  lwc1  $f10, 0x20($t0)
  mul.s $f16, $f6, $f10
  add.s $f4, $f8, $f18
  add.s $f8, $f16, $f4
  bne   $v0, $t1, .L7F0581F4
   swc1  $f8, ($a0)
  lwc1  $f18, ($a0)
  lwc1  $f6, 0x30($t0)
  add.s $f10, $f18, $f6
  swc1  $f10, ($a0)
.L7F0581F4:
  lwc1  $f16, ($t0)
  lwc1  $f4, 0x10($a3)
  lwc1  $f18, 0x10($t0)
  lwc1  $f6, 0x14($a3)
  mul.s $f8, $f16, $f4
  lwc1  $f4, 0x18($a3)
  addiu $a3, $a3, 0x20
  mul.s $f10, $f18, $f6
  lwc1  $f18, 0x20($t0)
  mul.s $f6, $f4, $f18
  add.s $f16, $f8, $f10
  add.s $f8, $f6, $f16
  bne   $v0, $t2, .L7F05823C
   swc1  $f8, 0x10($a0)
  lwc1  $f10, 0x10($a0)
  lwc1  $f4, 0x30($t0)
  add.s $f18, $f10, $f4
  swc1  $f18, 0x10($a0)
.L7F05823C:
  addiu $v0, $v0, 2
  bne   $v0, $t3, .L7F0581B0
   addiu $a0, $a0, 0x20
  addiu $v1, $v1, 4
  bne   $v1, $t4, .L7F0581A4
   addiu $t0, $t0, 4
  mtc1  $zero, $f0
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  swc1  $f0, 0xc($a2)
  swc1  $f0, 0x1c($a2)
  swc1  $f0, 0x2c($a2)
  jr    $ra
   swc1  $f6, 0x3c($a2)
");

asm(R"
glabel sub_GAME_7F058274
  lwc1  $f4, ($a1)
  lwc1  $f6, ($a0)
  mul.s $f8, $f4, $f6
  swc1  $f8, ($a2)
  lwc1  $f16, ($a0)
  lwc1  $f10, 0x10($a1)
  mul.s $f18, $f10, $f16
  swc1  $f18, 0x10($a2)
  lwc1  $f6, ($a0)
  lwc1  $f4, 0x20($a1)
  mul.s $f8, $f4, $f6
  swc1  $f8, 0x20($a2)
  lwc1  $f16, ($a0)
  lwc1  $f10, 0x30($a1)
  mul.s $f18, $f10, $f16
  swc1  $f18, 0x30($a2)
  lwc1  $f6, 0x14($a0)
  lwc1  $f4, 4($a1)
  mul.s $f8, $f4, $f6
  swc1  $f8, 4($a2)
  lwc1  $f16, 0x14($a0)
  lwc1  $f10, 0x14($a1)
  mul.s $f18, $f10, $f16
  swc1  $f18, 0x14($a2)
  lwc1  $f6, 0x14($a0)
  lwc1  $f4, 0x24($a1)
  mul.s $f8, $f4, $f6
  swc1  $f8, 0x24($a2)
  lwc1  $f16, 0x14($a0)
  lwc1  $f10, 0x34($a1)
  mul.s $f18, $f10, $f16
  swc1  $f18, 0x34($a2)
  lwc1  $f4, 8($a1)
  lwc1  $f6, 0x28($a0)
  mul.s $f8, $f4, $f6
  swc1  $f8, 8($a2)
  lwc1  $f10, 0x18($a1)
  lwc1  $f16, 0x28($a0)
  mul.s $f18, $f10, $f16
  swc1  $f18, 0x18($a2)
  lwc1  $f4, 0x28($a1)
  lwc1  $f6, 0x28($a0)
  mul.s $f8, $f4, $f6
  swc1  $f8, 0x28($a2)
  lwc1  $f16, 0x38($a1)
  lwc1  $f10, 0x28($a0)
  lwc1  $f4, 0x38($a0)
  mul.s $f18, $f10, $f16
  add.s $f6, $f4, $f18
  swc1  $f6, 0x38($a2)
  lwc1  $f10, 0x2c($a0)
  lwc1  $f8, 8($a1)
  mul.s $f16, $f8, $f10
  swc1  $f16, 0xc($a2)
  lwc1  $f18, 0x2c($a0)
  lwc1  $f4, 0x18($a1)
  mul.s $f6, $f4, $f18
  swc1  $f6, 0x1c($a2)
  lwc1  $f10, 0x2c($a0)
  lwc1  $f8, 0x28($a1)
  mul.s $f16, $f8, $f10
  swc1  $f16, 0x2c($a2)
  lwc1  $f18, 0x2c($a0)
  lwc1  $f4, 0x38($a1)
  mul.s $f6, $f4, $f18
  jr    $ra
   swc1  $f6, 0x3c($a2)
");

asm(R"
glabel sub_GAME_7F058380
  move  $a3, $a0
  li    $a0, 3
  move  $v0, $zero
  move  $v1, $a2
.L7F058390:
  lwc1  $f18, ($a3)
  lwc1  $f16, ($a1)
  lwc1  $f14, 0x10($a3)
  lwc1  $f12, 4($a1)
  mul.s $f16, $f18, $f16
  lwc1  $f18, 8($a1)
  lwc1  $f10, 0x20($a3)
  mul.s $f12, $f14, $f12
  addiu $v0, $v0, 1
  addiu $v1, $v1, 4
  mul.s $f10, $f18, $f10
  addiu $a3, $a3, 4
  add.s $f12, $f16, $f12
  add.s $f12, $f10, $f12
  bne   $v0, $a0, .L7F058390
   swc1  $f12, -4($v1)
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0583D8
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  addiu $a2, $sp, 0x1c
  jal   sub_GAME_7F058380
   sw    $a1, 0x2c($sp)
  lw    $a1, 0x2c($sp)
  lwc1  $f4, 0x1c($sp)
  swc1  $f4, ($a1)
  lwc1  $f6, 0x20($sp)
  swc1  $f6, 4($a1)
  lwc1  $f8, 0x24($sp)
  swc1  $f8, 8($a1)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F058418
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  jal   sub_GAME_7F058380
   sw    $a2, 0x20($sp)
  lw    $a0, 0x18($sp)
  lw    $a2, 0x20($sp)
  lwc1  $f6, 0x30($a0)
  lwc1  $f4, ($a2)
  lwc1  $f10, 4($a2)
  add.s $f8, $f4, $f6
  lwc1  $f4, 8($a2)
  swc1  $f8, ($a2)
  lwc1  $f16, 0x34($a0)
  add.s $f18, $f10, $f16
  swc1  $f18, 4($a2)
  lwc1  $f6, 0x38($a0)
  add.s $f8, $f4, $f6
  swc1  $f8, 8($a2)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F058474
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  jal   sub_GAME_7F0583D8
   sw    $a1, 0x1c($sp)
  lw    $a0, 0x18($sp)
  lw    $a1, 0x1c($sp)
  lwc1  $f6, 0x30($a0)
  lwc1  $f4, ($a1)
  lwc1  $f10, 4($a1)
  add.s $f8, $f4, $f6
  lwc1  $f4, 8($a1)
  swc1  $f8, ($a1)
  lwc1  $f16, 0x34($a0)
  add.s $f18, $f10, $f16
  swc1  $f18, 4($a1)
  lwc1  $f6, 0x38($a0)
  add.s $f8, $f4, $f6
  swc1  $f8, 8($a1)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0584D0
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a1, 0x24($sp)
  sw    $a0, 0x20($sp)
  lwc1  $f12, 0x24($sp)
  jal   cosf
   sw    $a2, 0x28($sp)
  lwc1  $f12, 0x24($sp)
  jal   sinf
   swc1  $f0, 0x1c($sp)
  lw    $a2, 0x28($sp)
  lw    $v0, 0x20($sp)
  lwc1  $f14, 0x1c($sp)
  mtc1  $zero, $f2
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f12
  neg.s $f4, $f0
  swc1  $f0, 0x20($a2)
  swc1  $f4, 8($a2)
  swc1  $f14, ($a2)
  swc1  $f14, 0x28($a2)
  swc1  $f2, 4($a2)
  swc1  $f2, 0xc($a2)
  swc1  $f2, 0x10($a2)
  swc1  $f2, 0x18($a2)
  swc1  $f2, 0x1c($a2)
  swc1  $f2, 0x24($a2)
  swc1  $f2, 0x2c($a2)
  swc1  $f12, 0x14($a2)
  lwc1  $f6, ($v0)
  swc1  $f6, 0x30($a2)
  lwc1  $f8, 4($v0)
  swc1  $f8, 0x34($a2)
  lwc1  $f10, 8($v0)
  swc1  $f12, 0x3c($a2)
  swc1  $f10, 0x38($a2)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F058570
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  swc1  $f12, 0x20($sp)
  lwc1  $f12, 0x20($sp)
  jal   cosf
   sw    $a1, 0x24($sp)
  lwc1  $f12, 0x20($sp)
  jal   sinf
   swc1  $f0, 0x1c($sp)
  lw    $a1, 0x24($sp)
  lwc1  $f14, 0x1c($sp)
  mtc1  $zero, $f2
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f12
  neg.s $f4, $f0
  swc1  $f0, 0x18($a1)
  swc1  $f4, 0x24($a1)
  swc1  $f14, 0x14($a1)
  swc1  $f14, 0x28($a1)
  swc1  $f2, 4($a1)
  swc1  $f2, 8($a1)
  swc1  $f2, 0xc($a1)
  swc1  $f2, 0x10($a1)
  swc1  $f2, 0x1c($a1)
  swc1  $f2, 0x20($a1)
  swc1  $f2, 0x2c($a1)
  swc1  $f2, 0x30($a1)
  swc1  $f2, 0x34($a1)
  swc1  $f2, 0x38($a1)
  swc1  $f12, ($a1)
  swc1  $f12, 0x3c($a1)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0585FC
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  swc1  $f12, 0x20($sp)
  lwc1  $f12, 0x20($sp)
  jal   cosf
   sw    $a1, 0x24($sp)
  lwc1  $f12, 0x20($sp)
  jal   sinf
   swc1  $f0, 0x1c($sp)
  lw    $a1, 0x24($sp)
  lwc1  $f14, 0x1c($sp)
  mtc1  $zero, $f2
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f12
  neg.s $f4, $f0
  swc1  $f0, 0x20($a1)
  swc1  $f4, 8($a1)
  swc1  $f14, ($a1)
  swc1  $f14, 0x28($a1)
  swc1  $f2, 4($a1)
  swc1  $f2, 0xc($a1)
  swc1  $f2, 0x10($a1)
  swc1  $f2, 0x18($a1)
  swc1  $f2, 0x1c($a1)
  swc1  $f2, 0x24($a1)
  swc1  $f2, 0x2c($a1)
  swc1  $f2, 0x30($a1)
  swc1  $f2, 0x34($a1)
  swc1  $f2, 0x38($a1)
  swc1  $f12, 0x14($a1)
  swc1  $f12, 0x3c($a1)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F058688
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  swc1  $f12, 0x20($sp)
  lwc1  $f12, 0x20($sp)
  jal   cosf
   sw    $a1, 0x24($sp)
  lwc1  $f12, 0x20($sp)
  jal   sinf
   swc1  $f0, 0x1c($sp)
  lw    $a1, 0x24($sp)
  lwc1  $f14, 0x1c($sp)
  mtc1  $zero, $f2
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f12
  neg.s $f4, $f0
  swc1  $f0, 4($a1)
  swc1  $f4, 0x10($a1)
  swc1  $f14, ($a1)
  swc1  $f14, 0x14($a1)
  swc1  $f2, 8($a1)
  swc1  $f2, 0xc($a1)
  swc1  $f2, 0x18($a1)
  swc1  $f2, 0x1c($a1)
  swc1  $f2, 0x20($a1)
  swc1  $f2, 0x24($a1)
  swc1  $f2, 0x2c($a1)
  swc1  $f2, 0x30($a1)
  swc1  $f2, 0x34($a1)
  swc1  $f2, 0x38($a1)
  swc1  $f12, 0x28($a1)
  swc1  $f12, 0x3c($a1)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F058714
  addiu $sp, $sp, -0x58
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  move  $s0, $a1
  move  $s1, $a0
  jal   cosf
   lwc1  $f12, ($a0)
  swc1  $f0, 0x54($sp)
  jal   sinf
   lwc1  $f12, ($s1)
  swc1  $f0, 0x50($sp)
  jal   cosf
   lwc1  $f12, 4($s1)
  lwc1  $f12, 4($s1)
  jal   sinf
   swc1  $f0, 0x4c($sp)
  lwc1  $f12, 8($s1)
  jal   cosf
   swc1  $f0, 0x48($sp)
  lwc1  $f12, 8($s1)
  jal   sinf
   swc1  $f0, 0x44($sp)
  lwc1  $f14, 0x4c($sp)
  lwc1  $f16, 0x44($sp)
  lwc1  $f2, 0x48($sp)
  mtc1  $zero, $f12
  mul.s $f4, $f14, $f16
  neg.s $f8, $f2
  swc1  $f12, 0xc($s0)
  mul.s $f6, $f14, $f0
  swc1  $f8, 8($s0)
  li    $at, 0x3F800000 # 1.000000
  swc1  $f4, ($s0)
  swc1  $f6, 4($s0)
  lwc1  $f10, 0x50($sp)
  lwc1  $f6, 0x54($sp)
  mul.s $f4, $f10, $f16
  nop   
  mul.s $f8, $f6, $f0
  nop   
  mul.s $f10, $f4, $f2
  swc1  $f4, 0x24($sp)
  swc1  $f8, 0x28($sp)
  sub.s $f6, $f10, $f8
  swc1  $f6, 0x10($s0)
  lwc1  $f4, 0x50($sp)
  lwc1  $f10, 0x54($sp)
  mul.s $f18, $f4, $f0
  nop   
  mul.s $f8, $f10, $f16
  nop   
  mul.s $f6, $f18, $f2
  swc1  $f8, 0x20($sp)
  add.s $f4, $f6, $f8
  swc1  $f4, 0x14($s0)
  lwc1  $f10, 0x50($sp)
  swc1  $f12, 0x1c($s0)
  mul.s $f6, $f10, $f14
  swc1  $f6, 0x18($s0)
  lwc1  $f8, 0x20($sp)
  mul.s $f4, $f8, $f2
  add.s $f10, $f4, $f18
  swc1  $f10, 0x20($s0)
  lwc1  $f6, 0x28($sp)
  lwc1  $f4, 0x24($sp)
  mul.s $f8, $f6, $f2
  sub.s $f10, $f8, $f4
  mtc1  $at, $f4
  swc1  $f10, 0x24($s0)
  lwc1  $f6, 0x54($sp)
  swc1  $f12, 0x2c($s0)
  swc1  $f12, 0x30($s0)
  mul.s $f8, $f6, $f14
  swc1  $f12, 0x34($s0)
  swc1  $f12, 0x38($s0)
  swc1  $f4, 0x3c($s0)
  swc1  $f8, 0x28($s0)
  lw    $ra, 0x1c($sp)
  lw    $s1, 0x18($sp)
  lw    $s0, 0x14($sp)
  jr    $ra
   addiu $sp, $sp, 0x58
");

asm(R"
glabel sub_GAME_7F058860
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  lwc1  $f0, 0x18($a0)
  lwc1  $f2, 0x28($a0)
  move  $s0, $a0
  mul.s $f4, $f0, $f0
  move  $s1, $a1
  mul.s $f6, $f2, $f2
  jal   sqrtf
   add.s $f12, $f4, $f6
  li    $at, 0x36000000 # 0.000002
  mtc1  $at, $f8
  swc1  $f0, 0x24($sp)
  c.lt.s $f8, $f0
  nop   
  bc1fl .L7F0588E8
   mtc1  $zero, $f10
  lwc1  $f12, 0x18($s0)
  jal   convert_angle_using_inverse
   lwc1  $f14, 0x28($s0)
  swc1  $f0, ($s1)
  lwc1  $f12, 8($s0)
  lwc1  $f14, 0x24($sp)
  jal   convert_angle_using_inverse
   neg.s $f12, $f12
  swc1  $f0, 4($s1)
  lwc1  $f14, ($s0)
  jal   convert_angle_using_inverse
   lwc1  $f12, 4($s0)
  b     .L7F058918
   swc1  $f0, 8($s1)
  mtc1  $zero, $f10
.L7F0588E8:
  nop   
  swc1  $f10, ($s1)
  lwc1  $f12, 8($s0)
  lwc1  $f14, 0x24($sp)
  jal   convert_angle_using_inverse
   neg.s $f12, $f12
  swc1  $f0, 4($s1)
  lwc1  $f12, 0x10($s0)
  lwc1  $f14, 0x14($s0)
  jal   convert_angle_using_inverse
   neg.s $f12, $f12
  swc1  $f0, 8($s1)
.L7F058918:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
glabel sub_GAME_7F05892C
  addiu $sp, $sp, -0x18
  sw    $a0, 0x18($sp)
  sw    $ra, 0x14($sp)
  move  $a0, $a1
  sw    $a2, 0x20($sp)
  jal   sub_GAME_7F058714
   move  $a1, $a2
  lw    $a0, 0x18($sp)
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   lw    $a1, 0x20($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel init_something_copy_posdata_to_it
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  sw    $a1, 0x1c($sp)
  jal   reset_array_of_0x10_floats
   move  $a0, $a1
  lw    $a0, 0x18($sp)
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   lw    $a1, 0x1c($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel copies_first_3_floats_from_a0_to_a1_plus_0x30
  lwc1  $f4, ($a0)
  swc1  $f4, 0x30($a1)
  lwc1  $f6, 4($a0)
  swc1  $f6, 0x34($a1)
  lwc1  $f8, 8($a0)
  jr    $ra
   swc1  $f8, 0x38($a1)
");

asm(R"
glabel sub_GAME_7F0589B4
  lwc1  $f4, ($a1)
  lwc1  $f8, 4($a1)
  lwc1  $f16, 8($a1)
  mul.s $f6, $f4, $f12
  nop   
  mul.s $f10, $f8, $f12
  nop   
  mul.s $f18, $f16, $f12
  swc1  $f6, ($a1)
  swc1  $f10, 4($a1)
  jr    $ra
   swc1  $f18, 8($a1)
");

asm(R"
glabel sub_GAME_7F0589E4
  lwc1  $f4, 0x10($a1)
  lwc1  $f8, 0x14($a1)
  lwc1  $f16, 0x18($a1)
  mul.s $f6, $f4, $f12
  nop   
  mul.s $f10, $f8, $f12
  nop   
  mul.s $f18, $f16, $f12
  swc1  $f6, 0x10($a1)
  swc1  $f10, 0x14($a1)
  jr    $ra
   swc1  $f18, 0x18($a1)
");

asm(R"
glabel sub_GAME_7F058A14
  lwc1  $f4, 0x20($a1)
  lwc1  $f8, 0x24($a1)
  lwc1  $f16, 0x28($a1)
  mul.s $f6, $f4, $f12
  lwc1  $f4, 0x2c($a1)
  mul.s $f10, $f8, $f12
  nop   
  mul.s $f18, $f16, $f12
  swc1  $f6, 0x20($a1)
  mul.s $f6, $f4, $f12
  swc1  $f10, 0x24($a1)
  swc1  $f18, 0x28($a1)
  jr    $ra
   swc1  $f6, 0x2c($a1)
");

asm(R"
glabel sub_GAME_7F058A4C
  lwc1  $f4, 0x20($a1)
  lwc1  $f8, 0x24($a1)
  lwc1  $f16, 0x28($a1)
  mul.s $f6, $f4, $f12
  nop   
  mul.s $f10, $f8, $f12
  nop   
  mul.s $f18, $f16, $f12
  swc1  $f6, 0x20($a1)
  swc1  $f10, 0x24($a1)
  jr    $ra
   swc1  $f18, 0x28($a1)
");

asm(R"
glabel matrix_multiply_A1_by_F12
  lwc1  $f4, ($a1)
  lwc1  $f8, 4($a1)
  lwc1  $f16, 8($a1)
  mul.s $f6, $f4, $f12
  lwc1  $f4, 0xc($a1)
  mul.s $f10, $f8, $f12
  lwc1  $f8, 0x10($a1)
  mul.s $f18, $f16, $f12
  swc1  $f6, ($a1)
  lwc1  $f16, 0x14($a1)
  mul.s $f6, $f4, $f12
  swc1  $f10, 4($a1)
  lwc1  $f4, 0x18($a1)
  mul.s $f10, $f8, $f12
  swc1  $f18, 8($a1)
  lwc1  $f8, 0x1c($a1)
  mul.s $f18, $f16, $f12
  swc1  $f6, 0xc($a1)
  lwc1  $f16, 0x20($a1)
  mul.s $f6, $f4, $f12
  swc1  $f10, 0x10($a1)
  lwc1  $f4, 0x24($a1)
  mul.s $f10, $f8, $f12
  swc1  $f18, 0x14($a1)
  lwc1  $f8, 0x28($a1)
  mul.s $f18, $f16, $f12
  swc1  $f6, 0x18($a1)
  lwc1  $f16, 0x2c($a1)
  mul.s $f6, $f4, $f12
  swc1  $f10, 0x1c($a1)
  mul.s $f10, $f8, $f12
  swc1  $f18, 0x20($a1)
  mul.s $f18, $f16, $f12
  swc1  $f6, 0x24($a1)
  swc1  $f10, 0x28($a1)
  jr    $ra
   swc1  $f18, 0x2c($a1)
");

asm(R"
glabel sub_GAME_7F058B10
  lwc1  $f4, ($a1)
  lwc1  $f8, 4($a1)
  lwc1  $f16, 8($a1)
  mul.s $f6, $f4, $f12
  lwc1  $f4, 0x10($a1)
  mul.s $f10, $f8, $f12
  lwc1  $f8, 0x14($a1)
  mul.s $f18, $f16, $f12
  swc1  $f6, ($a1)
  lwc1  $f16, 0x18($a1)
  mul.s $f6, $f4, $f12
  swc1  $f10, 4($a1)
  lwc1  $f4, 0x20($a1)
  mul.s $f10, $f8, $f12
  swc1  $f18, 8($a1)
  lwc1  $f8, 0x24($a1)
  mul.s $f18, $f16, $f12
  swc1  $f6, 0x10($a1)
  lwc1  $f16, 0x28($a1)
  mul.s $f6, $f4, $f12
  swc1  $f10, 0x14($a1)
  mul.s $f10, $f8, $f12
  swc1  $f18, 0x18($a1)
  mul.s $f18, $f16, $f12
  swc1  $f6, 0x20($a1)
  swc1  $f10, 0x24($a1)
  jr    $ra
   swc1  $f18, 0x28($a1)
");

asm(R"
glabel sub_GAME_7F058B80
  lwc1  $f4, 8($a1)
  lwc1  $f8, 0x18($a1)
  lwc1  $f16, 0x28($a1)
  mul.s $f6, $f4, $f12
  lwc1  $f4, 0x38($a1)
  mul.s $f10, $f8, $f12
  nop   
  mul.s $f18, $f16, $f12
  swc1  $f6, 8($a1)
  mul.s $f6, $f4, $f12
  swc1  $f10, 0x18($a1)
  swc1  $f18, 0x28($a1)
  jr    $ra
   swc1  $f6, 0x38($a1)
");

asm(R"
glabel sub_GAME_7F058BB8
  lwc1  $f4, ($a1)
  lwc1  $f8, 0x10($a1)
  lwc1  $f16, 0x20($a1)
  mul.s $f6, $f4, $f12
  lwc1  $f4, 0x30($a1)
  mul.s $f10, $f8, $f12
  lwc1  $f8, 4($a1)
  mul.s $f18, $f16, $f12
  swc1  $f6, ($a1)
  lwc1  $f16, 0x14($a1)
  mul.s $f6, $f4, $f12
  swc1  $f10, 0x10($a1)
  lwc1  $f4, 0x24($a1)
  mul.s $f10, $f8, $f12
  swc1  $f18, 0x20($a1)
  lwc1  $f8, 0x34($a1)
  mul.s $f18, $f16, $f12
  swc1  $f6, 0x30($a1)
  lwc1  $f16, 8($a1)
  mul.s $f6, $f4, $f12
  swc1  $f10, 4($a1)
  lwc1  $f4, 0x18($a1)
  mul.s $f10, $f8, $f12
  swc1  $f18, 0x14($a1)
  lwc1  $f8, 0x28($a1)
  mul.s $f18, $f16, $f12
  swc1  $f6, 0x24($a1)
  lwc1  $f16, 0x38($a1)
  mul.s $f6, $f4, $f12
  swc1  $f10, 0x34($a1)
  mul.s $f10, $f8, $f12
  swc1  $f18, 8($a1)
  mul.s $f18, $f16, $f12
  swc1  $f6, 0x18($a1)
  swc1  $f10, 0x28($a1)
  jr    $ra
   swc1  $f18, 0x38($a1)
");

asm(R"
glabel sub_GAME_7F058C4C
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f4
  lui   $at, %hi(D_80032310)
  mul.s $f6, $f4, $f12
  jr    $ra
   swc1  $f6, %lo(D_80032310)($at)
");

asm(R"
glabel sub_GAME_7F058C64
  lui   $v0, %hi(D_80032310)
  addiu $v0, %lo(D_80032310) # addiu $v0, $v0, 0x2310
  lwc1  $f4, ($v0)
  lui   $at, %hi(flt_CODE_bss_80075DA0)
  swc1  $f4, %lo(flt_CODE_bss_80075DA0)($at)
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f6
  jr    $ra
   swc1  $f6, ($v0)
");

void sub_GAME_7F058C88(void) { D_80032310 = flt_CODE_bss_80075DA0; }

asm(R"
glabel sub_GAME_7F058C9C
  addiu $sp, $sp, -0x18
  sw    $s1, 0xc($sp)
  sw    $s3, 0x14($sp)
  sw    $s2, 0x10($sp)
  lui   $s1, %hi(D_80032310)
  sw    $s0, 8($sp)
  addiu $s1, %lo(D_80032310) # addiu $s1, $s1, 0x2310
  lui   $s2, 0xffff
  li    $s3, 8
  move  $v0, $zero
  move  $t3, $a1
.L7F058CC8:
  lwc1  $f18, ($s1)
  sll   $t7, $v0, 3
  addu  $t2, $a0, $t7
  lwc1  $f16, ($t2)
  lwc1  $f14, 4($t2)
  andi  $t9, $v0, 1
  mul.s $f16, $f18, $f16
  sll   $t6, $t9, 2
  addu  $t7, $s1, $t6
  lwc1  $f18, ($t7)
  addiu $a3, $v0, 1
  addiu $t0, $v0, 2
  mul.s $f14, $f18, $f14
  trunc.w.s $f16, $f16
  addiu $t1, $v0, 3
  addiu $v0, $v0, 4
  addiu $t3, $t3, 0x10
  mfc1  $v1, $f16
  trunc.w.s $f14, $f14
  and   $t9, $v1, $s2
  sll   $t8, $v1, 0x10
  mfc1  $a2, $f14
  nop   
  srl   $t6, $a2, 0x10
  or    $t7, $t9, $t6
  sw    $t7, -0x10($t3)
  andi  $t9, $a2, 0xffff
  or    $t6, $t8, $t9
  sw    $t6, 0x10($t3)
  lwc1  $f14, ($s1)
  sll   $t8, $a3, 3
  addu  $t4, $a0, $t8
  lwc1  $f16, ($t4)
  lwc1  $f18, 4($t4)
  andi  $t6, $a3, 1
  mul.s $f16, $f14, $f16
  sll   $t7, $t6, 2
  addu  $t8, $s1, $t7
  lwc1  $f14, ($t8)
  mul.s $f18, $f14, $f18
  trunc.w.s $f16, $f16
  mfc1  $v1, $f16
  trunc.w.s $f18, $f18
  and   $t6, $v1, $s2
  sll   $t9, $v1, 0x10
  mfc1  $a2, $f18
  nop   
  srl   $t7, $a2, 0x10
  or    $t8, $t6, $t7
  sw    $t8, -0xc($t3)
  andi  $t6, $a2, 0xffff
  or    $t7, $t9, $t6
  sw    $t7, 0x14($t3)
  lwc1  $f18, ($s1)
  sll   $t9, $t0, 3
  addu  $t5, $a0, $t9
  lwc1  $f16, ($t5)
  lwc1  $f14, 4($t5)
  andi  $t7, $t0, 1
  mul.s $f16, $f18, $f16
  sll   $t8, $t7, 2
  addu  $t9, $s1, $t8
  lwc1  $f18, ($t9)
  mul.s $f14, $f18, $f14
  trunc.w.s $f16, $f16
  mfc1  $v1, $f16
  trunc.w.s $f14, $f14
  and   $t7, $v1, $s2
  sll   $t6, $v1, 0x10
  mfc1  $a2, $f14
  nop   
  srl   $t8, $a2, 0x10
  or    $t9, $t7, $t8
  andi  $t7, $a2, 0xffff
  sw    $t9, -8($t3)
  or    $t8, $t6, $t7
  sw    $t8, 0x18($t3)
  lwc1  $f14, ($s1)
  sll   $t6, $t1, 3
  addu  $s0, $a0, $t6
  lwc1  $f16, ($s0)
  lwc1  $f18, 4($s0)
  andi  $t8, $t1, 1
  mul.s $f16, $f14, $f16
  sll   $t9, $t8, 2
  addu  $t6, $s1, $t9
  lwc1  $f14, ($t6)
  mul.s $f18, $f14, $f18
  trunc.w.s $f16, $f16
  mfc1  $v1, $f16
  trunc.w.s $f18, $f18
  and   $t8, $v1, $s2
  sll   $t7, $v1, 0x10
  mfc1  $a2, $f18
  nop   
  srl   $t9, $a2, 0x10
  or    $t6, $t8, $t9
  andi  $t8, $a2, 0xffff
  or    $t9, $t7, $t8
  sw    $t6, -4($t3)
  bne   $v0, $s3, .L7F058CC8
   sw    $t9, 0x1c($t3)
  lw    $s0, 8($sp)
  lw    $s1, 0xc($sp)
  lw    $s2, 0x10($sp)
  lw    $s3, 0x14($sp)
  jr    $ra
   addiu $sp, $sp, 0x18
");

asm(R"
glabel sub_GAME_7F058E78
  addiu $sp, $sp, -0x18
  sw    $s2, 0x10($sp)
  sw    $s3, 0x14($sp)
  sw    $s1, 0xc($sp)
  lui   $s2, %hi(D_80032310)
  sw    $s0, 8($sp)
  addiu $s2, %lo(D_80032310) # addiu $s2, $s2, 0x2310
  lui   $s1, 0xffff
  li    $s3, 8
  move  $v0, $zero
  move  $t2, $a0
.L7F058EA4:
  lw    $v1, ($t2)
  lw    $a2, 0x20($t2)
  lwc1  $f8, ($s2)
  and   $t8, $v1, $s1
  srl   $t9, $a2, 0x10
  or    $t6, $t8, $t9
  mtc1  $t6, $f4
  sll   $t7, $v0, 3
  addu  $t3, $a1, $t7
  cvt.s.w $f6, $f4
  sll   $t7, $v1, 0x10
  andi  $t8, $a2, 0xffff
  or    $t9, $t7, $t8
  mtc1  $t9, $f16
  andi  $t6, $v0, 1
  div.s $f10, $f6, $f8
  sll   $t7, $t6, 2
  addu  $t8, $s2, $t7
  addiu $a3, $v0, 1
  cvt.s.w $f18, $f16
  sll   $t6, $a3, 3
  addu  $t4, $a1, $t6
  addiu $t0, $v0, 2
  addiu $t1, $v0, 3
  addiu $v0, $v0, 4
  addiu $t2, $t2, 0x10
  swc1  $f10, ($t3)
  lwc1  $f4, ($t8)
  div.s $f6, $f18, $f4
  swc1  $f6, 4($t3)
  lw    $a2, 0x14($t2)
  lw    $v1, -0xc($t2)
  lwc1  $f16, ($s2)
  srl   $t8, $a2, 0x10
  and   $t7, $v1, $s1
  or    $t9, $t7, $t8
  mtc1  $t9, $f8
  andi  $t7, $a2, 0xffff
  sll   $t6, $v1, 0x10
  cvt.s.w $f10, $f8
  or    $t8, $t6, $t7
  mtc1  $t8, $f4
  andi  $t9, $a3, 1
  sll   $t6, $t9, 2
  cvt.s.w $f6, $f4
  addu  $t7, $s2, $t6
  sll   $t9, $t0, 3
  addu  $t5, $a1, $t9
  div.s $f18, $f10, $f16
  swc1  $f18, ($t4)
  lwc1  $f8, ($t7)
  div.s $f10, $f6, $f8
  swc1  $f10, 4($t4)
  lw    $a2, 0x18($t2)
  lw    $v1, -8($t2)
  lwc1  $f4, ($s2)
  srl   $t7, $a2, 0x10
  and   $t6, $v1, $s1
  or    $t8, $t6, $t7
  mtc1  $t8, $f16
  andi  $t6, $a2, 0xffff
  sll   $t9, $v1, 0x10
  cvt.s.w $f18, $f16
  or    $t7, $t9, $t6
  mtc1  $t7, $f8
  andi  $t8, $t0, 1
  sll   $t9, $t8, 2
  cvt.s.w $f10, $f8
  addu  $t6, $s2, $t9
  sll   $t8, $t1, 3
  addu  $s0, $a1, $t8
  div.s $f6, $f18, $f4
  swc1  $f6, ($t5)
  lwc1  $f16, ($t6)
  div.s $f18, $f10, $f16
  swc1  $f18, 4($t5)
  lw    $a2, 0x1c($t2)
  lw    $v1, -4($t2)
  lwc1  $f8, ($s2)
  srl   $t6, $a2, 0x10
  and   $t9, $v1, $s1
  or    $t7, $t9, $t6
  mtc1  $t7, $f4
  andi  $t9, $a2, 0xffff
  sll   $t8, $v1, 0x10
  cvt.s.w $f6, $f4
  or    $t6, $t8, $t9
  mtc1  $t6, $f16
  andi  $t7, $t1, 1
  sll   $t8, $t7, 2
  cvt.s.w $f18, $f16
  addu  $t9, $s2, $t8
  div.s $f10, $f6, $f8
  swc1  $f10, ($s0)
  lwc1  $f4, ($t9)
  div.s $f6, $f18, $f4
  bne   $v0, $s3, .L7F058EA4
   swc1  $f6, 4($s0)
  lw    $s0, 8($sp)
  lw    $s1, 0xc($sp)
  lw    $s2, 0x10($sp)
  lw    $s3, 0x14($sp)
  jr    $ra
   addiu $sp, $sp, 0x18
");

asm(R"
glabel sub_GAME_7F059044
  li    $at, 0x47800000 # 65536.000000
  move  $a2, $a0
  mtc1  $at, $f0
  li    $a0, 4
  move  $v0, $zero
  move  $v1, $a1
  lwc1  $f16, ($a2)
  addiu $v0, $v0, 1
  mul.s $f18, $f16, $f0
  beql  $v0, $a0, .L7F0590E8
   trunc.w.s $f16, $f18
  trunc.w.s $f16, $f18
.L7F059074:
  addiu $v0, $v0, 1
  addiu $v1, $v1, 0x10
  addiu $a2, $a2, 0x10
  mfc1  $t7, $f16
  nop   
  sw    $t7, -0x10($v1)
  lwc1  $f16, -0xc($a2)
  mul.s $f16, $f16, $f0
  trunc.w.s $f16, $f16
  mfc1  $t9, $f16
  nop   
  sw    $t9, -0xc($v1)
  lwc1  $f16, -8($a2)
  mul.s $f16, $f16, $f0
  trunc.w.s $f16, $f16
  mfc1  $t1, $f16
  nop   
  sw    $t1, -8($v1)
  lwc1  $f16, -4($a2)
  mul.s $f16, $f16, $f0
  trunc.w.s $f16, $f16
  mfc1  $t3, $f16
  nop   
  sw    $t3, -4($v1)
  lwc1  $f16, ($a2)
  mul.s $f18, $f16, $f0
  bnel  $v0, $a0, .L7F059074
   trunc.w.s $f16, $f18
  trunc.w.s $f16, $f18
.L7F0590E8:
  addiu $v1, $v1, 0x10
  addiu $a2, $a2, 0x10
  mfc1  $t7, $f16
  nop   
  sw    $t7, -0x10($v1)
  lwc1  $f16, -0xc($a2)
  mul.s $f16, $f16, $f0
  trunc.w.s $f16, $f16
  mfc1  $t9, $f16
  nop   
  sw    $t9, -0xc($v1)
  lwc1  $f16, -8($a2)
  mul.s $f16, $f16, $f0
  trunc.w.s $f16, $f16
  mfc1  $t1, $f16
  nop   
  sw    $t1, -8($v1)
  lwc1  $f16, -4($a2)
  mul.s $f16, $f16, $f0
  trunc.w.s $f16, $f16
  mfc1  $t3, $f16
  nop   
  sw    $t3, -4($v1)
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F05914C
  li    $at, 0x47800000 # 65536.000000
  move  $a2, $a0
  mtc1  $at, $f0
  li    $a0, 4
  move  $v0, $zero
  move  $v1, $a1
  addiu $v0, $v0, 1
  beq   $v0, $a0, .L7F0591DC
   lw    $t6, ($a2)
.L7F059170:
  mtc1  $t6, $f18
  addiu $v0, $v0, 1
  addiu $v1, $v1, 0x10
  cvt.s.w $f18, $f18
  addiu $a2, $a2, 0x10
  div.s $f18, $f18, $f0
  swc1  $f18, -0x10($v1)
  lw    $t7, -0xc($a2)
  mtc1  $t7, $f18
  nop   
  cvt.s.w $f18, $f18
  div.s $f18, $f18, $f0
  swc1  $f18, -0xc($v1)
  lw    $t8, -8($a2)
  mtc1  $t8, $f18
  nop   
  cvt.s.w $f18, $f18
  div.s $f18, $f18, $f0
  swc1  $f18, -8($v1)
  lw    $t9, -4($a2)
  mtc1  $t9, $f18
  nop   
  cvt.s.w $f18, $f18
  div.s $f18, $f18, $f0
  swc1  $f18, -4($v1)
  bne   $v0, $a0, .L7F059170
   lw    $t6, ($a2)
.L7F0591DC:
  mtc1  $t6, $f18
  addiu $v1, $v1, 0x10
  addiu $a2, $a2, 0x10
  cvt.s.w $f18, $f18
  div.s $f18, $f18, $f0
  swc1  $f18, -0x10($v1)
  lw    $t7, -0xc($a2)
  mtc1  $t7, $f18
  nop   
  cvt.s.w $f18, $f18
  div.s $f18, $f18, $f0
  swc1  $f18, -0xc($v1)
  lw    $t8, -8($a2)
  mtc1  $t8, $f18
  nop   
  cvt.s.w $f18, $f18
  div.s $f18, $f18, $f0
  swc1  $f18, -8($v1)
  lw    $t9, -4($a2)
  mtc1  $t9, $f18
  nop   
  cvt.s.w $f18, $f18
  div.s $f18, $f18, $f0
  swc1  $f18, -4($v1)
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F059244
  move  $v0, $zero
  move  $t0, $a1
  li    $t5, 8
  lui   $t4, 0xffff
.L7F059254:
  sll   $t7, $v0, 3
  addu  $a3, $a0, $t7
  lw    $v1, ($a3)
  lw    $a2, 4($a3)
  addiu $t0, $t0, 0x10
  and   $t8, $v1, $t4
  srl   $t9, $a2, 0x10
  or    $t6, $t8, $t9
  sll   $t7, $v1, 0x10
  andi  $t8, $a2, 0xffff
  or    $t9, $t7, $t8
  addiu $t7, $v0, 1
  sll   $t8, $t7, 3
  addu  $t1, $a0, $t8
  sw    $t6, -0x10($t0)
  sw    $t9, 0x10($t0)
  lw    $a2, 4($t1)
  lw    $v1, ($t1)
  srl   $t6, $a2, 0x10
  and   $t9, $v1, $t4
  or    $t7, $t9, $t6
  andi  $t9, $a2, 0xffff
  sll   $t8, $v1, 0x10
  or    $t6, $t8, $t9
  addiu $t8, $v0, 2
  sll   $t9, $t8, 3
  addu  $t2, $a0, $t9
  sw    $t6, 0x14($t0)
  sw    $t7, -0xc($t0)
  lw    $a2, 4($t2)
  lw    $v1, ($t2)
  srl   $t7, $a2, 0x10
  and   $t6, $v1, $t4
  or    $t8, $t6, $t7
  andi  $t6, $a2, 0xffff
  sll   $t9, $v1, 0x10
  or    $t7, $t9, $t6
  addiu $t9, $v0, 3
  sll   $t6, $t9, 3
  addu  $t3, $a0, $t6
  sw    $t7, 0x18($t0)
  sw    $t8, -8($t0)
  lw    $a2, 4($t3)
  lw    $v1, ($t3)
  addiu $v0, $v0, 4
  srl   $t8, $a2, 0x10
  and   $t7, $v1, $t4
  or    $t9, $t7, $t8
  andi  $t7, $a2, 0xffff
  sll   $t6, $v1, 0x10
  or    $t8, $t6, $t7
  sw    $t8, 0x1c($t0)
  bne   $v0, $t5, .L7F059254
   sw    $t9, -4($t0)
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F059334
  move  $v0, $zero
  move  $a3, $a0
  li    $t5, 8
  lui   $t4, 0xffff
.L7F059344:
  lw    $v1, ($a3)
  lw    $a2, 0x20($a3)
  sll   $t7, $v0, 3
  and   $t8, $v1, $t4
  srl   $t9, $a2, 0x10
  or    $t6, $t8, $t9
  addu  $t0, $a1, $t7
  sll   $t7, $v1, 0x10
  andi  $t8, $a2, 0xffff
  or    $t9, $t7, $t8
  sw    $t6, ($t0)
  sw    $t9, 4($t0)
  lw    $a2, 0x24($a3)
  lw    $v1, 4($a3)
  addiu $t7, $v0, 1
  sll   $t8, $t7, 3
  srl   $t6, $a2, 0x10
  and   $t9, $v1, $t4
  or    $t7, $t9, $t6
  addu  $t1, $a1, $t8
  andi  $t9, $a2, 0xffff
  sll   $t8, $v1, 0x10
  or    $t6, $t8, $t9
  sw    $t6, 4($t1)
  sw    $t7, ($t1)
  lw    $a2, 0x28($a3)
  lw    $v1, 8($a3)
  addiu $t8, $v0, 2
  sll   $t9, $t8, 3
  srl   $t7, $a2, 0x10
  and   $t6, $v1, $t4
  or    $t8, $t6, $t7
  addu  $t2, $a1, $t9
  andi  $t6, $a2, 0xffff
  sll   $t9, $v1, 0x10
  or    $t7, $t9, $t6
  sw    $t7, 4($t2)
  sw    $t8, ($t2)
  lw    $a2, 0x2c($a3)
  lw    $v1, 0xc($a3)
  addiu $t9, $v0, 3
  sll   $t6, $t9, 3
  srl   $t8, $a2, 0x10
  and   $t7, $v1, $t4
  or    $t9, $t7, $t8
  addu  $t3, $a1, $t6
  andi  $t7, $a2, 0xffff
  sll   $t6, $v1, 0x10
  or    $t8, $t6, $t7
  addiu $v0, $v0, 4
  sw    $t8, 4($t3)
  sw    $t9, ($t3)
  bne   $v0, $t5, .L7F059344
   addiu $a3, $a3, 0x10
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F059424
  addiu $sp, $sp, -0x48
  sdc1  $f20, 0x10($sp)
  lwc1  $f20, 0x58($sp)
  sdc1  $f22, 0x18($sp)
  lwc1  $f22, 0x5c($sp)
  mul.s $f4, $f20, $f20
  sdc1  $f24, 0x20($sp)
  lwc1  $f24, 0x60($sp)
  mul.s $f6, $f22, $f22
  sw    $ra, 0x44($sp)
  sdc1  $f30, 0x38($sp)
  mul.s $f10, $f24, $f24
  sdc1  $f28, 0x30($sp)
  sdc1  $f26, 0x28($sp)
  sw    $a1, 0x4c($sp)
  sw    $a2, 0x50($sp)
  add.s $f8, $f4, $f6
  sw    $a3, 0x54($sp)
  sw    $a0, 0x48($sp)
  jal   sqrtf
   add.s $f12, $f8, $f10
  li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f4
  lwc1  $f6, 0x68($sp)
  lwc1  $f10, 0x6c($sp)
  div.s $f2, $f4, $f0
  mul.s $f20, $f20, $f2
  nop   
  mul.s $f22, $f22, $f2
  nop   
  mul.s $f24, $f24, $f2
  nop   
  mul.s $f8, $f6, $f24
  nop   
  mul.s $f4, $f10, $f22
  sub.s $f26, $f8, $f4
  mul.s $f8, $f10, $f20
  lwc1  $f4, 0x64($sp)
  mul.s $f10, $f4, $f24
  sub.s $f28, $f8, $f10
  mul.s $f8, $f4, $f22
  nop   
  mul.s $f10, $f6, $f20
  sub.s $f30, $f8, $f10
  mul.s $f4, $f26, $f26
  nop   
  mul.s $f6, $f28, $f28
  add.s $f8, $f4, $f6
  mul.s $f10, $f30, $f30
  jal   sqrtf
   add.s $f12, $f8, $f10
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  nop   
  div.s $f2, $f4, $f0
  mul.s $f26, $f26, $f2
  nop   
  mul.s $f28, $f28, $f2
  nop   
  mul.s $f30, $f30, $f2
  nop   
  mul.s $f6, $f22, $f30
  nop   
  mul.s $f8, $f24, $f28
  nop   
  mul.s $f10, $f24, $f26
  nop   
  mul.s $f4, $f20, $f30
  sub.s $f14, $f6, $f8
  mul.s $f6, $f20, $f28
  nop   
  mul.s $f8, $f22, $f26
  swc1  $f14, 0x64($sp)
  sub.s $f16, $f10, $f4
  mul.s $f10, $f14, $f14
  nop   
  mul.s $f4, $f16, $f16
  swc1  $f16, 0x68($sp)
  sub.s $f18, $f6, $f8
  mul.s $f8, $f18, $f18
  add.s $f6, $f10, $f4
  swc1  $f18, 0x6c($sp)
  jal   sqrtf
   add.s $f12, $f6, $f8
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  lwc1  $f14, 0x64($sp)
  lwc1  $f12, 0x68($sp)
  div.s $f2, $f10, $f0
  lwc1  $f4, 0x6c($sp)
  lw    $a0, 0x48($sp)
  mul.s $f14, $f14, $f2
  nop   
  mul.s $f12, $f12, $f2
  nop   
  mul.s $f6, $f4, $f2
  swc1  $f6, 0x6c($sp)
  swc1  $f26, ($a0)
  swc1  $f28, 0x10($a0)
  swc1  $f30, 0x20($a0)
  lwc1  $f8, 0x4c($sp)
  lwc1  $f4, 0x50($sp)
  mul.s $f10, $f8, $f26
  nop   
  mul.s $f6, $f4, $f28
  lwc1  $f4, 0x54($sp)
  swc1  $f14, 4($a0)
  swc1  $f12, 0x14($a0)
  add.s $f8, $f10, $f6
  mul.s $f10, $f4, $f30
  add.s $f6, $f8, $f10
  neg.s $f4, $f6
  swc1  $f4, 0x30($a0)
  swc1  $f14, 0x64($sp)
  lwc1  $f14, 0x6c($sp)
  swc1  $f12, 0x68($sp)
  lwc1  $f12, 0x4c($sp)
  lwc1  $f2, 0x50($sp)
  lwc1  $f0, 0x54($sp)
  swc1  $f14, 0x24($a0)
  lwc1  $f8, 0x64($sp)
  lwc1  $f6, 0x68($sp)
  swc1  $f20, 8($a0)
  mul.s $f10, $f12, $f8
  swc1  $f22, 0x18($a0)
  swc1  $f24, 0x28($a0)
  mul.s $f4, $f2, $f6
  add.s $f8, $f10, $f4
  mul.s $f6, $f0, $f14
  add.s $f10, $f8, $f6
  mul.s $f8, $f12, $f20
  nop   
  mul.s $f6, $f2, $f22
  neg.s $f4, $f10
  swc1  $f4, 0x34($a0)
  mul.s $f4, $f0, $f24
  mtc1  $zero, $f0
  nop   
  swc1  $f0, 0xc($a0)
  add.s $f10, $f8, $f6
  swc1  $f0, 0x1c($a0)
  swc1  $f0, 0x2c($a0)
  add.s $f8, $f10, $f4
  mtc1  $at, $f10
  neg.s $f6, $f8
  swc1  $f10, 0x3c($a0)
  swc1  $f6, 0x38($a0)
  lw    $ra, 0x44($sp)
  ldc1  $f30, 0x38($sp)
  ldc1  $f28, 0x30($sp)
  ldc1  $f26, 0x28($sp)
  ldc1  $f24, 0x20($sp)
  ldc1  $f22, 0x18($sp)
  ldc1  $f20, 0x10($sp)
  jr    $ra
   addiu $sp, $sp, 0x48
");

asm(R"
glabel sub_GAME_7F059694
  addiu $sp, $sp, -0x30
  mtc1  $a1, $f12
  mtc1  $a2, $f14
  lwc1  $f6, 0x40($sp)
  lwc1  $f10, 0x44($sp)
  sw    $a3, 0x3c($sp)
  sub.s $f8, $f6, $f12
  lwc1  $f4, 0x3c($sp)
  lwc1  $f18, 0x48($sp)
  sub.s $f16, $f10, $f14
  swc1  $f8, 0x10($sp)
  lwc1  $f8, 0x4c($sp)
  sub.s $f6, $f18, $f4
  swc1  $f16, 0x14($sp)
  lwc1  $f16, 0x54($sp)
  lwc1  $f10, 0x50($sp)
  sw    $ra, 0x2c($sp)
  mfc1  $a1, $f12
  mfc1  $a2, $f14
  mfc1  $a3, $f4
  swc1  $f6, 0x18($sp)
  swc1  $f8, 0x1c($sp)
  swc1  $f16, 0x24($sp)
  jal   sub_GAME_7F059424
   swc1  $f10, 0x20($sp)
  lw    $ra, 0x2c($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F059708
  addiu $sp, $sp, -0x48
  sdc1  $f20, 0x10($sp)
  lwc1  $f20, 0x58($sp)
  sdc1  $f22, 0x18($sp)
  lwc1  $f22, 0x5c($sp)
  mul.s $f4, $f20, $f20
  sdc1  $f24, 0x20($sp)
  lwc1  $f24, 0x60($sp)
  mul.s $f6, $f22, $f22
  sw    $ra, 0x44($sp)
  sdc1  $f30, 0x38($sp)
  mul.s $f10, $f24, $f24
  sdc1  $f28, 0x30($sp)
  sdc1  $f26, 0x28($sp)
  sw    $a1, 0x4c($sp)
  sw    $a2, 0x50($sp)
  add.s $f8, $f4, $f6
  sw    $a3, 0x54($sp)
  sw    $a0, 0x48($sp)
  jal   sqrtf
   add.s $f12, $f8, $f10
  li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f4
  lwc1  $f6, 0x68($sp)
  lwc1  $f10, 0x6c($sp)
  div.s $f2, $f4, $f0
  mul.s $f20, $f20, $f2
  nop   
  mul.s $f22, $f22, $f2
  nop   
  mul.s $f24, $f24, $f2
  nop   
  mul.s $f8, $f6, $f24
  nop   
  mul.s $f4, $f10, $f22
  sub.s $f26, $f8, $f4
  mul.s $f8, $f10, $f20
  lwc1  $f4, 0x64($sp)
  mul.s $f10, $f4, $f24
  sub.s $f28, $f8, $f10
  mul.s $f8, $f4, $f22
  nop   
  mul.s $f10, $f6, $f20
  sub.s $f30, $f8, $f10
  mul.s $f4, $f26, $f26
  nop   
  mul.s $f6, $f28, $f28
  add.s $f8, $f4, $f6
  mul.s $f10, $f30, $f30
  jal   sqrtf
   add.s $f12, $f8, $f10
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  nop   
  div.s $f2, $f4, $f0
  mul.s $f26, $f26, $f2
  nop   
  mul.s $f28, $f28, $f2
  nop   
  mul.s $f30, $f30, $f2
  nop   
  mul.s $f6, $f22, $f30
  nop   
  mul.s $f8, $f24, $f28
  nop   
  mul.s $f10, $f24, $f26
  nop   
  mul.s $f4, $f20, $f30
  sub.s $f14, $f6, $f8
  mul.s $f6, $f20, $f28
  nop   
  mul.s $f8, $f22, $f26
  swc1  $f14, 0x64($sp)
  sub.s $f16, $f10, $f4
  mul.s $f10, $f14, $f14
  nop   
  mul.s $f4, $f16, $f16
  swc1  $f16, 0x68($sp)
  sub.s $f18, $f6, $f8
  mul.s $f8, $f18, $f18
  add.s $f6, $f10, $f4
  swc1  $f18, 0x6c($sp)
  jal   sqrtf
   add.s $f12, $f6, $f8
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  lwc1  $f14, 0x64($sp)
  lwc1  $f12, 0x68($sp)
  div.s $f2, $f10, $f0
  lwc1  $f4, 0x6c($sp)
  lw    $a0, 0x48($sp)
  mtc1  $zero, $f0
  mul.s $f14, $f14, $f2
  nop   
  mul.s $f12, $f12, $f2
  nop   
  mul.s $f6, $f4, $f2
  swc1  $f6, 0x6c($sp)
  swc1  $f26, ($a0)
  swc1  $f14, 0x10($a0)
  swc1  $f20, 0x20($a0)
  lwc1  $f8, 0x4c($sp)
  swc1  $f28, 4($a0)
  swc1  $f12, 0x14($a0)
  swc1  $f22, 0x24($a0)
  swc1  $f8, 0x30($a0)
  lwc1  $f10, 0x50($sp)
  swc1  $f30, 8($a0)
  mtc1  $at, $f8
  swc1  $f10, 0x34($a0)
  lwc1  $f4, 0x6c($sp)
  swc1  $f24, 0x28($a0)
  swc1  $f4, 0x18($a0)
  lwc1  $f6, 0x54($sp)
  swc1  $f0, 0xc($a0)
  swc1  $f0, 0x1c($a0)
  swc1  $f0, 0x2c($a0)
  swc1  $f8, 0x3c($a0)
  swc1  $f6, 0x38($a0)
  lw    $ra, 0x44($sp)
  ldc1  $f30, 0x38($sp)
  ldc1  $f28, 0x30($sp)
  ldc1  $f26, 0x28($sp)
  ldc1  $f24, 0x20($sp)
  ldc1  $f22, 0x18($sp)
  ldc1  $f20, 0x10($sp)
  jr    $ra
   addiu $sp, $sp, 0x48
");

asm(R"
glabel sub_GAME_7F059908
  addiu $sp, $sp, -0x30
  mtc1  $a1, $f12
  mtc1  $a2, $f14
  lwc1  $f6, 0x40($sp)
  lwc1  $f10, 0x44($sp)
  sw    $a3, 0x3c($sp)
  sub.s $f8, $f6, $f12
  lwc1  $f4, 0x3c($sp)
  lwc1  $f18, 0x48($sp)
  sub.s $f16, $f10, $f14
  swc1  $f8, 0x10($sp)
  lwc1  $f8, 0x4c($sp)
  sub.s $f6, $f18, $f4
  swc1  $f16, 0x14($sp)
  lwc1  $f16, 0x54($sp)
  lwc1  $f10, 0x50($sp)
  sw    $ra, 0x2c($sp)
  mfc1  $a1, $f12
  mfc1  $a2, $f14
  mfc1  $a3, $f4
  swc1  $f6, 0x18($sp)
  swc1  $f8, 0x1c($sp)
  swc1  $f16, 0x24($sp)
  jal   sub_GAME_7F059708
   swc1  $f10, 0x20($sp)
  lw    $ra, 0x2c($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F05997C
  add.s $f0, $f12, $f14
  li    $at, 0x40000000 # 2.000000
  mtc1  $at, $f4
  li    $at, 0x48000000 # 131072.000000
  c.le.s $f0, $f4
  nop   
  bc1fl .L7F0599A8
   mtc1  $at, $f6
  jr    $ra
   li    $v0, 65535

  mtc1  $at, $f6
.L7F0599A8:
  li    $v0, 1
  li    $at, 0x4F000000 # 2147483648.000000
  div.s $f8, $f6, $f0
  cfc1  $t6, $31
  ctc1  $v0, $31
  nop   
  cvt.w.s $f10, $f8
  cfc1  $v0, $31
  nop   
  andi  $v0, $v0, 0x78
  beql  $v0, $zero, .L7F059A20
   mfc1  $v0, $f10
  mtc1  $at, $f10
  li    $v0, 1
  sub.s $f10, $f8, $f10
  ctc1  $v0, $31
  nop   
  cvt.w.s $f10, $f10
  cfc1  $v0, $31
  nop   
  andi  $v0, $v0, 0x78
  bnez  $v0, .L7F059A14
   nop   
  mfc1  $v0, $f10
  lui   $at, 0x8000
  b     .L7F059A2C
   or    $v0, $v0, $at
.L7F059A14:
  b     .L7F059A2C
   li    $v0, -1
  mfc1  $v0, $f10
.L7F059A20:
  nop   
  bltz  $v0, .L7F059A14
   nop   
.L7F059A2C:
  ctc1  $t6, $31
  andi  $t7, $v0, 0xffff
  bgtz  $t7, .L7F059A40
   andi  $v1, $v0, 0xffff
  li    $v1, 1
.L7F059A40:
  jr    $ra
   move  $v0, $v1
");

asm(R"
glabel sub_GAME_7F059A48
  li    $at, 0x3F000000 # 0.500000
  mtc1  $a2, $f14
  mtc1  $at, $f4
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  mul.s $f12, $f14, $f4
  sw    $a1, 0x2c($sp)
  sw    $a3, 0x34($sp)
  sw    $a0, 0x28($sp)
  jal   cosf
   swc1  $f12, 0x1c($sp)
  lwc1  $f12, 0x1c($sp)
  jal   sinf
   swc1  $f0, 0x20($sp)
  lwc1  $f8, 0x20($sp)
  lwc1  $f10, 0x34($sp)
  li    $at, 0x47800000 # 65536.000000
  div.s $f12, $f8, $f0
  lwc1  $f14, 0x40($sp)
  mtc1  $at, $f6
  lw    $a0, 0x28($sp)
  mtc1  $zero, $f2
  mul.s $f14, $f14, $f6
  swc1  $f2, 0x10($a0)
  swc1  $f2, 0x20($a0)
  swc1  $f2, 0x30($a0)
  swc1  $f2, 4($a0)
  swc1  $f2, 0x24($a0)
  swc1  $f2, 0x34($a0)
  swc1  $f2, 8($a0)
  swc1  $f2, 0x18($a0)
  div.s $f18, $f12, $f10
  mul.s $f4, $f18, $f14
  nop   
  mul.s $f6, $f12, $f14
  swc1  $f4, ($a0)
  swc1  $f6, 0x14($a0)
  lwc1  $f8, 0x38($sp)
  lwc1  $f10, 0x3c($sp)
  sub.s $f16, $f8, $f10
  add.s $f18, $f8, $f10
  div.s $f4, $f18, $f16
  mul.s $f6, $f4, $f14
  swc1  $f6, 0x28($a0)
  lwc1  $f8, 0x38($sp)
  lwc1  $f18, 0x3c($sp)
  swc1  $f2, 0xc($a0)
  add.s $f10, $f8, $f8
  swc1  $f2, 0x1c($a0)
  swc1  $f2, 0x3c($a0)
  mul.s $f4, $f10, $f18
  neg.s $f10, $f14
  swc1  $f10, 0x2c($a0)
  div.s $f6, $f4, $f16
  mul.s $f8, $f6, $f14
  swc1  $f8, 0x38($a0)
  lw    $t6, 0x2c($sp)
  lwc1  $f12, 0x38($sp)
  beqz  $t6, .L7F059B48
   nop   
  jal   sub_GAME_7F05997C
   lwc1  $f14, 0x3c($sp)
  lw    $t7, 0x2c($sp)
  sh    $v0, ($t7)
.L7F059B48:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F059B58
  addiu $sp, $sp, -0x48
  sw    $s0, 0x20($sp)
  sdc1  $f20, 0x18($sp)
  mtc1  $a1, $f20
  move  $s0, $a0
  sw    $ra, 0x24($sp)
  sw    $a2, 0x50($sp)
  sw    $a3, 0x54($sp)
  addiu $a2, $sp, 0x58
  addiu $a0, $sp, 0x50
  jal   guNormalize
   addiu $a1, $sp, 0x54
  jal   sinf
   mov.s $f12, $f20
  swc1  $f0, 0x44($sp)
  jal   cosf
   mov.s $f12, $f20
  lwc1  $f2, 0x50($sp)
  lwc1  $f14, 0x58($sp)
  swc1  $f0, 0x40($sp)
  mul.s $f4, $f2, $f2
  nop   
  mul.s $f6, $f14, $f14
  jal   sqrtf
   add.s $f12, $f4, $f6
  mtc1  $zero, $f20
  lwc1  $f8, 0x50($sp)
  lwc1  $f10, 0x40($sp)
  c.eq.s $f0, $f20
  lwc1  $f4, 0x44($sp)
  bc1t  .L7F059CCC
   nop   
  mul.s $f12, $f8, $f10
  li    $at, 0x3F800000 # 1.000000
  lwc1  $f6, 0x58($sp)
  mul.s $f14, $f8, $f4
  mtc1  $at, $f8
  mul.s $f16, $f6, $f10
  nop   
  mul.s $f18, $f6, $f4
  lwc1  $f6, 0x54($sp)
  swc1  $f14, 0x30($sp)
  mul.s $f4, $f6, $f14
  swc1  $f16, 0x2c($sp)
  neg.s $f10, $f16
  div.s $f2, $f8, $f0
  sub.s $f8, $f10, $f4
  mul.s $f6, $f8, $f2
  swc1  $f2, 0x38($sp)
  swc1  $f6, ($s0)
  lwc1  $f10, 0x44($sp)
  mul.s $f4, $f10, $f0
  swc1  $f4, 0x10($s0)
  lwc1  $f8, 0x54($sp)
  swc1  $f20, 0x30($s0)
  mul.s $f6, $f8, $f18
  sub.s $f10, $f12, $f6
  mul.s $f4, $f10, $f2
  swc1  $f4, 0x20($s0)
  lwc1  $f8, 0x54($sp)
  mul.s $f6, $f8, $f12
  sub.s $f10, $f18, $f6
  mul.s $f4, $f10, $f2
  swc1  $f4, 4($s0)
  lwc1  $f8, 0x40($sp)
  mul.s $f6, $f8, $f0
  swc1  $f6, 0x14($s0)
  lwc1  $f10, 0x54($sp)
  lwc1  $f4, 0x2c($sp)
  lwc1  $f6, 0x30($sp)
  mul.s $f8, $f10, $f4
  neg.s $f10, $f6
  lwc1  $f6, 0x38($sp)
  swc1  $f20, 0x34($s0)
  sub.s $f4, $f10, $f8
  mul.s $f10, $f4, $f6
  swc1  $f10, 0x24($s0)
  lwc1  $f8, 0x50($sp)
  neg.s $f4, $f8
  swc1  $f4, 8($s0)
  lwc1  $f6, 0x54($sp)
  neg.s $f10, $f6
  mtc1  $at, $f6
  swc1  $f10, 0x18($s0)
  lwc1  $f8, 0x58($sp)
  swc1  $f20, 0x38($s0)
  swc1  $f20, 0xc($s0)
  neg.s $f4, $f8
  swc1  $f20, 0x1c($s0)
  swc1  $f4, 0x28($s0)
  swc1  $f20, 0x2c($s0)
  b     .L7F059CD4
   swc1  $f6, 0x3c($s0)
.L7F059CCC:
  jal   reset_array_of_0x10_floats
   move  $a0, $s0
.L7F059CD4:
  lw    $ra, 0x24($sp)
  ldc1  $f20, 0x18($sp)
  lw    $s0, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x48
");

asm(R"
.late_rodata
glabel D_800536F0
.word 0x42652ee0 /*57.295776*/
.text
glabel sub_GAME_7F059CE8
  lui   $at, %hi(D_800536F0)
  mtc1  $a1, $f12
  lwc1  $f4, %lo(D_800536F0)($at)
  mtc1  $a2, $f14
  addiu $sp, $sp, -0x20
  mul.s $f12, $f12, $f4
  lwc1  $f6, 0x30($sp)
  sw    $ra, 0x1c($sp)
  mfc1  $a2, $f14
  sw    $a3, 0x2c($sp)
  swc1  $f6, 0x10($sp)
  mfc1  $a1, $f12
  jal   guAlignF
   nop   
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

void sub_GAME_7F059D30(unsigned int arg0) {}

asm(R"
glabel sub_GAME_7F059D38
  lwc1  $f4, ($a0)
  mtc1  $zero, $f0
  li    $at, 0x3F800000 # 1.000000
  swc1  $f4, ($a1)
  lwc1  $f6, 0x10($a0)
  swc1  $f6, 4($a1)
  lwc1  $f8, 0x20($a0)
  swc1  $f8, 8($a1)
  lwc1  $f10, 4($a0)
  swc1  $f10, 0x10($a1)
  lwc1  $f16, 0x14($a0)
  mtc1  $at, $f10
  swc1  $f16, 0x14($a1)
  lwc1  $f18, 0x24($a0)
  swc1  $f18, 0x18($a1)
  lwc1  $f4, 8($a0)
  swc1  $f4, 0x20($a1)
  lwc1  $f6, 0x18($a0)
  swc1  $f6, 0x24($a1)
  lwc1  $f8, 0x28($a0)
  swc1  $f0, 0x30($a1)
  swc1  $f0, 0x34($a1)
  swc1  $f0, 0x38($a1)
  swc1  $f0, 0xc($a1)
  swc1  $f0, 0x1c($a1)
  swc1  $f0, 0x2c($a1)
  swc1  $f10, 0x3c($a1)
  jr    $ra
   swc1  $f8, 0x28($a1)
");

asm(R"
glabel sub_GAME_7F059DAC
  lwc1  $f12, ($a0)
  lwc1  $f14, 0x10($a0)
  lwc1  $f2, 0x20($a0)
  mul.s $f4, $f12, $f12
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f16
  mul.s $f6, $f14, $f14
  add.s $f8, $f4, $f6
  mul.s $f10, $f2, $f2
  mtc1  $zero, $f2
  add.s $f0, $f10, $f8
  div.s $f0, $f16, $f0
  mul.s $f18, $f12, $f0
  swc1  $f18, ($a1)
  lwc1  $f4, 0x10($a0)
  mul.s $f6, $f4, $f0
  swc1  $f6, 4($a1)
  lwc1  $f10, 0x20($a0)
  mul.s $f8, $f10, $f0
  swc1  $f8, 8($a1)
  lwc1  $f18, 4($a0)
  mul.s $f4, $f18, $f0
  swc1  $f4, 0x10($a1)
  lwc1  $f6, 0x14($a0)
  mul.s $f10, $f6, $f0
  swc1  $f10, 0x14($a1)
  lwc1  $f8, 0x24($a0)
  mul.s $f18, $f8, $f0
  swc1  $f18, 0x18($a1)
  lwc1  $f4, 8($a0)
  mul.s $f6, $f4, $f0
  swc1  $f6, 0x20($a1)
  lwc1  $f10, 0x18($a0)
  mul.s $f8, $f10, $f0
  swc1  $f8, 0x24($a1)
  lwc1  $f18, 0x28($a0)
  swc1  $f16, 0x3c($a1)
  swc1  $f2, 0x30($a1)
  mul.s $f4, $f18, $f0
  swc1  $f2, 0x34($a1)
  swc1  $f2, 0x38($a1)
  swc1  $f2, 0xc($a1)
  swc1  $f2, 0x1c($a1)
  swc1  $f2, 0x2c($a1)
  jr    $ra
   swc1  $f4, 0x28($a1)
");

asm(R"
glabel sub_GAME_7F059E64
  lwc1  $f12, ($a0)
  lwc1  $f14, 0x10($a0)
  lwc1  $f2, 0x20($a0)
  mul.s $f4, $f12, $f12
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f16
  mul.s $f6, $f14, $f14
  add.s $f8, $f4, $f6
  mul.s $f10, $f2, $f2
  add.s $f0, $f10, $f8
  div.s $f0, $f16, $f0
  mul.s $f18, $f12, $f0
  swc1  $f18, ($a1)
  lwc1  $f4, 0x10($a0)
  mul.s $f6, $f4, $f0
  swc1  $f6, 4($a1)
  lwc1  $f10, 0x20($a0)
  mul.s $f8, $f10, $f0
  swc1  $f8, 8($a1)
  lwc1  $f18, 4($a0)
  mul.s $f4, $f18, $f0
  swc1  $f4, 0x10($a1)
  lwc1  $f6, 0x14($a0)
  mul.s $f10, $f6, $f0
  swc1  $f10, 0x14($a1)
  lwc1  $f8, 0x24($a0)
  mul.s $f18, $f8, $f0
  swc1  $f18, 0x18($a1)
  lwc1  $f4, 8($a0)
  mul.s $f6, $f4, $f0
  swc1  $f6, 0x20($a1)
  lwc1  $f10, 0x18($a0)
  lwc1  $f6, ($a1)
  mul.s $f8, $f10, $f0
  swc1  $f8, 0x24($a1)
  lwc1  $f18, 0x28($a0)
  mul.s $f4, $f18, $f0
  lwc1  $f18, 0x10($a1)
  mtc1  $zero, $f0
  swc1  $f4, 0x28($a1)
  lwc1  $f10, 0x30($a0)
  lwc1  $f4, 0x34($a0)
  mul.s $f8, $f6, $f10
  nop   
  mul.s $f6, $f18, $f4
  lwc1  $f4, 0x20($a1)
  lwc1  $f18, 0x38($a0)
  add.s $f10, $f8, $f6
  mul.s $f8, $f18, $f4
  lwc1  $f4, 4($a1)
  add.s $f6, $f8, $f10
  neg.s $f18, $f6
  lwc1  $f6, 0x14($a1)
  swc1  $f18, 0x30($a1)
  lwc1  $f8, 0x30($a0)
  lwc1  $f18, 0x34($a0)
  mul.s $f10, $f4, $f8
  nop   
  mul.s $f4, $f6, $f18
  lwc1  $f18, 0x24($a1)
  lwc1  $f6, 0x38($a0)
  add.s $f8, $f10, $f4
  mul.s $f10, $f6, $f18
  lwc1  $f18, 8($a1)
  add.s $f4, $f10, $f8
  neg.s $f6, $f4
  lwc1  $f4, 0x18($a1)
  swc1  $f6, 0x34($a1)
  lwc1  $f10, 0x30($a0)
  lwc1  $f6, 0x34($a0)
  mul.s $f8, $f18, $f10
  nop   
  mul.s $f18, $f4, $f6
  lwc1  $f6, 0x28($a1)
  lwc1  $f4, 0x38($a0)
  swc1  $f16, 0x3c($a1)
  swc1  $f0, 0xc($a1)
  swc1  $f0, 0x1c($a1)
  swc1  $f0, 0x2c($a1)
  add.s $f10, $f8, $f18
  mul.s $f8, $f4, $f6
  add.s $f18, $f8, $f10
  neg.s $f4, $f18
  jr    $ra
   swc1  $f4, 0x38($a1)
");

asm(R"
glabel sub_GAME_7F059FB8
  lwc1  $f2, ($a0)
  lwc1  $f12, 0x14($a0)
  lwc1  $f14, 0x28($a0)
  lwc1  $f16, 4($a0)
  mul.s $f4, $f2, $f12
  lwc1  $f18, 0x18($a0)
  lwc1  $f10, 0x20($a0)
  addiu $sp, $sp, -0x30
  li    $at, 0x3F800000 # 1.000000
  swc1  $f10, 0x10($sp)
  lwc1  $f8, 0x10($sp)
  mul.s $f0, $f4, $f14
  lwc1  $f10, 8($a0)
  mul.s $f6, $f16, $f18
  swc1  $f10, 0xc($sp)
  lwc1  $f10, 0xc($sp)
  mul.s $f4, $f6, $f8
  lwc1  $f6, 0x10($a0)
  swc1  $f6, 8($sp)
  lwc1  $f6, 8($sp)
  add.s $f0, $f0, $f4
  lwc1  $f4, 0x24($a0)
  swc1  $f8, ($sp)
  swc1  $f4, 0x1c($sp)
  mul.s $f4, $f10, $f6
  lwc1  $f8, 0x1c($sp)
  mul.s $f4, $f4, $f8
  add.s $f0, $f0, $f4
  mul.s $f4, $f10, $f12
  lwc1  $f10, ($sp)
  mul.s $f4, $f4, $f10
  nop   
  mul.s $f10, $f16, $f6
  sub.s $f0, $f0, $f4
  mul.s $f4, $f10, $f14
  nop   
  mul.s $f6, $f2, $f18
  mtc1  $at, $f2
  sub.s $f0, $f0, $f4
  mul.s $f10, $f6, $f8
  sub.s $f0, $f0, $f10
  mul.s $f4, $f12, $f14
  nop   
  mul.s $f6, $f8, $f18
  div.s $f0, $f2, $f0
  sub.s $f10, $f4, $f6
  mul.s $f8, $f10, $f0
  swc1  $f8, ($a1)
  lwc1  $f4, 0x18($a0)
  lwc1  $f6, 0x20($a0)
  lwc1  $f8, 0x28($a0)
  mul.s $f10, $f4, $f6
  lwc1  $f4, 0x10($a0)
  mul.s $f6, $f8, $f4
  sub.s $f8, $f10, $f6
  mul.s $f4, $f8, $f0
  swc1  $f4, 0x10($a1)
  lwc1  $f10, 0x10($a0)
  lwc1  $f6, 0x24($a0)
  lwc1  $f4, 0x20($a0)
  mul.s $f8, $f10, $f6
  lwc1  $f10, 0x14($a0)
  mul.s $f6, $f4, $f10
  sub.s $f4, $f8, $f6
  mul.s $f10, $f4, $f0
  swc1  $f10, 0x20($a1)
  lwc1  $f8, 8($a0)
  lwc1  $f6, 0x24($a0)
  lwc1  $f10, 0x28($a0)
  mul.s $f4, $f8, $f6
  lwc1  $f8, 4($a0)
  mul.s $f6, $f10, $f8
  sub.s $f10, $f4, $f6
  mul.s $f8, $f10, $f0
  swc1  $f8, 4($a1)
  lwc1  $f4, ($a0)
  lwc1  $f6, 0x28($a0)
  lwc1  $f8, 0x20($a0)
  mul.s $f10, $f4, $f6
  lwc1  $f4, 8($a0)
  mul.s $f6, $f8, $f4
  sub.s $f8, $f10, $f6
  mul.s $f4, $f8, $f0
  swc1  $f4, 0x14($a1)
  lwc1  $f10, 4($a0)
  lwc1  $f6, 0x20($a0)
  lwc1  $f4, 0x24($a0)
  mul.s $f8, $f10, $f6
  lwc1  $f10, ($a0)
  mul.s $f6, $f4, $f10
  sub.s $f4, $f8, $f6
  mul.s $f10, $f4, $f0
  swc1  $f10, 0x24($a1)
  lwc1  $f8, 4($a0)
  lwc1  $f6, 0x18($a0)
  lwc1  $f10, 0x14($a0)
  mul.s $f4, $f8, $f6
  lwc1  $f8, 8($a0)
  mul.s $f6, $f10, $f8
  sub.s $f10, $f4, $f6
  mul.s $f8, $f10, $f0
  swc1  $f8, 8($a1)
  lwc1  $f6, 0x10($a0)
  lwc1  $f4, 8($a0)
  lwc1  $f8, 0x18($a0)
  mul.s $f10, $f4, $f6
  lwc1  $f4, ($a0)
  mul.s $f6, $f8, $f4
  sub.s $f8, $f10, $f6
  mul.s $f4, $f8, $f0
  swc1  $f4, 0x18($a1)
  lwc1  $f6, 0x14($a0)
  lwc1  $f10, ($a0)
  lwc1  $f4, 0x10($a0)
  mul.s $f8, $f10, $f6
  lwc1  $f10, 4($a0)
  mul.s $f6, $f4, $f10
  sub.s $f4, $f8, $f6
  lwc1  $f6, ($a1)
  mul.s $f10, $f4, $f0
  mtc1  $zero, $f0
  swc1  $f10, 0x28($a1)
  lwc1  $f8, 0x30($a0)
  lwc1  $f10, 0x34($a0)
  mul.s $f4, $f8, $f6
  lwc1  $f8, 0x10($a1)
  mul.s $f6, $f10, $f8
  lwc1  $f8, 0x20($a1)
  add.s $f10, $f4, $f6
  lwc1  $f4, 0x38($a0)
  mul.s $f6, $f8, $f4
  add.s $f8, $f6, $f10
  lwc1  $f10, 4($a1)
  neg.s $f4, $f8
  swc1  $f4, 0x30($a1)
  lwc1  $f6, 0x30($a0)
  lwc1  $f4, 0x34($a0)
  mul.s $f8, $f6, $f10
  lwc1  $f6, 0x14($a1)
  mul.s $f10, $f4, $f6
  lwc1  $f6, 0x24($a1)
  add.s $f4, $f8, $f10
  lwc1  $f8, 0x38($a0)
  mul.s $f10, $f6, $f8
  add.s $f6, $f10, $f4
  lwc1  $f4, 8($a1)
  neg.s $f8, $f6
  swc1  $f8, 0x34($a1)
  lwc1  $f10, 0x30($a0)
  lwc1  $f8, 0x34($a0)
  mul.s $f6, $f10, $f4
  lwc1  $f10, 0x18($a1)
  mul.s $f4, $f8, $f10
  lwc1  $f10, 0x28($a1)
  add.s $f8, $f6, $f4
  lwc1  $f6, 0x38($a0)
  addiu $sp, $sp, 0x30
  swc1  $f2, 0x3c($a1)
  mul.s $f4, $f10, $f6
  swc1  $f0, 0xc($a1)
  swc1  $f0, 0x1c($a1)
  swc1  $f0, 0x2c($a1)
  add.s $f10, $f4, $f8
  neg.s $f6, $f10
  jr    $ra
   swc1  $f6, 0x38($a1)
");

asm(R"
glabel sub_GAME_7F05A250
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  jal   sub_GAME_7F05A310
   sw    $a1, 0x1c($sp)
  jal   sub_GAME_7F05A774
   lw    $a0, 0x18($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  move  $v1, $zero
  lw    $v0, 0x1c($sp)
  li    $a0, 4
  div.s $f2, $f4, $f0
  lwc1  $f8, ($v0)
  addiu $v1, $v1, 1
  lwc1  $f14, 4($v0)
  mul.s $f16, $f8, $f2
  lwc1  $f12, 8($v0)
  beq   $v1, $a0, .L7F05A2DC
   lwc1  $f18, 0xc($v0)
.L7F05A2A0:
  mul.s $f10, $f14, $f2
  lwc1  $f8, 0x10($v0)
  lwc1  $f14, 0x14($v0)
  mul.s $f6, $f12, $f2
  lwc1  $f12, 0x18($v0)
  addiu $v1, $v1, 1
  mul.s $f4, $f18, $f2
  lwc1  $f18, 0x1c($v0)
  swc1  $f16, ($v0)
  mul.s $f16, $f8, $f2
  swc1  $f10, 4($v0)
  swc1  $f6, 8($v0)
  addiu $v0, $v0, 0x10
  bne   $v1, $a0, .L7F05A2A0
   swc1  $f4, -4($v0)
.L7F05A2DC:
  mul.s $f10, $f14, $f2
  addiu $v0, $v0, 0x10
  swc1  $f16, -0x10($v0)
  mul.s $f6, $f12, $f2
  nop   
  mul.s $f4, $f18, $f2
  swc1  $f10, -0xc($v0)
  swc1  $f6, -8($v0)
  swc1  $f4, -4($v0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F05A310
  addiu $sp, $sp, -0xa8
  sw    $ra, 0x64($sp)
  sw    $s0, 0x60($sp)
  sdc1  $f30, 0x58($sp)
  sdc1  $f28, 0x50($sp)
  sdc1  $f26, 0x48($sp)
  sdc1  $f24, 0x40($sp)
  sdc1  $f22, 0x38($sp)
  sdc1  $f20, 0x30($sp)
  lwc1  $f4, 8($a0)
  lwc1  $f30, 4($a0)
  lwc1  $f28, ($a0)
  swc1  $f4, 0x84($sp)
  lwc1  $f6, 0xc($a0)
  move  $s0, $a1
  swc1  $f6, 0x74($sp)
  lwc1  $f8, 0x10($a0)
  swc1  $f8, 0xa0($sp)
  lwc1  $f10, 0x20($a0)
  lwc1  $f12, 0x14($a0)
  lwc1  $f2, 0x1c($a0)
  lwc1  $f0, 0x18($a0)
  swc1  $f10, 0x9c($sp)
  lwc1  $f22, 0x34($a0)
  lwc1  $f14, 0x24($a0)
  lwc1  $f18, 0x2c($a0)
  lwc1  $f16, 0x28($a0)
  lwc1  $f26, 0x3c($a0)
  lwc1  $f24, 0x38($a0)
  lwc1  $f20, 0x30($a0)
  mfc1  $a3, $f0
  mfc1  $a2, $f22
  swc1  $f12, 0x90($sp)
  swc1  $f2, 0x70($sp)
  swc1  $f2, 0x18($sp)
  swc1  $f0, 0x80($sp)
  swc1  $f14, 0x8c($sp)
  swc1  $f18, 0x6c($sp)
  swc1  $f18, 0x1c($sp)
  swc1  $f16, 0x7c($sp)
  swc1  $f16, 0x10($sp)
  swc1  $f26, 0x20($sp)
  jal   sub_GAME_7F05A928
   swc1  $f24, 0x14($sp)
  swc1  $f0, ($s0)
  lwc1  $f8, 0x6c($sp)
  lwc1  $f6, 0x70($sp)
  lwc1  $f4, 0x7c($sp)
  mfc1  $a2, $f20
  swc1  $f26, 0x20($sp)
  swc1  $f24, 0x14($sp)
  lw    $a3, 0x80($sp)
  lwc1  $f14, 0x9c($sp)
  lwc1  $f12, 0xa0($sp)
  swc1  $f8, 0x1c($sp)
  swc1  $f6, 0x18($sp)
  jal   sub_GAME_7F05A928
   swc1  $f4, 0x10($sp)
  neg.s $f10, $f0
  mfc1  $a2, $f20
  swc1  $f10, 0x10($s0)
  lwc1  $f8, 0x6c($sp)
  lwc1  $f6, 0x70($sp)
  lwc1  $f4, 0x8c($sp)
  swc1  $f26, 0x20($sp)
  swc1  $f22, 0x14($sp)
  lw    $a3, 0x90($sp)
  lwc1  $f14, 0x9c($sp)
  lwc1  $f12, 0xa0($sp)
  swc1  $f8, 0x1c($sp)
  swc1  $f6, 0x18($sp)
  jal   sub_GAME_7F05A928
   swc1  $f4, 0x10($sp)
  swc1  $f0, 0x20($s0)
  lwc1  $f6, 0x7c($sp)
  lwc1  $f4, 0x80($sp)
  lwc1  $f10, 0x8c($sp)
  mfc1  $a2, $f20
  swc1  $f24, 0x20($sp)
  swc1  $f22, 0x14($sp)
  lw    $a3, 0x90($sp)
  lwc1  $f14, 0x9c($sp)
  lwc1  $f12, 0xa0($sp)
  swc1  $f6, 0x1c($sp)
  swc1  $f4, 0x18($sp)
  jal   sub_GAME_7F05A928
   swc1  $f10, 0x10($sp)
  neg.s $f8, $f0
  mfc1  $a2, $f22
  swc1  $f8, 0x30($s0)
  lwc1  $f6, 0x6c($sp)
  lwc1  $f4, 0x74($sp)
  lwc1  $f10, 0x7c($sp)
  swc1  $f26, 0x20($sp)
  swc1  $f24, 0x14($sp)
  lw    $a3, 0x84($sp)
  lwc1  $f14, 0x8c($sp)
  mov.s $f12, $f30
  swc1  $f6, 0x1c($sp)
  swc1  $f4, 0x18($sp)
  jal   sub_GAME_7F05A928
   swc1  $f10, 0x10($sp)
  neg.s $f8, $f0
  mfc1  $a2, $f20
  swc1  $f8, 4($s0)
  lwc1  $f6, 0x6c($sp)
  lwc1  $f4, 0x74($sp)
  lwc1  $f10, 0x7c($sp)
  swc1  $f26, 0x20($sp)
  swc1  $f24, 0x14($sp)
  lw    $a3, 0x84($sp)
  lwc1  $f14, 0x9c($sp)
  mov.s $f12, $f28
  swc1  $f6, 0x1c($sp)
  swc1  $f4, 0x18($sp)
  jal   sub_GAME_7F05A928
   swc1  $f10, 0x10($sp)
  swc1  $f0, 0x14($s0)
  lwc1  $f4, 0x6c($sp)
  lwc1  $f10, 0x74($sp)
  lwc1  $f8, 0x8c($sp)
  mfc1  $a2, $f20
  mfc1  $a3, $f30
  swc1  $f26, 0x20($sp)
  swc1  $f22, 0x14($sp)
  lwc1  $f14, 0x9c($sp)
  mov.s $f12, $f28
  swc1  $f4, 0x1c($sp)
  swc1  $f10, 0x18($sp)
  jal   sub_GAME_7F05A928
   swc1  $f8, 0x10($sp)
  neg.s $f6, $f0
  mfc1  $a2, $f20
  swc1  $f6, 0x24($s0)
  lwc1  $f4, 0x7c($sp)
  lwc1  $f10, 0x84($sp)
  lwc1  $f8, 0x8c($sp)
  mfc1  $a3, $f30
  swc1  $f24, 0x20($sp)
  swc1  $f22, 0x14($sp)
  lwc1  $f14, 0x9c($sp)
  mov.s $f12, $f28
  swc1  $f4, 0x1c($sp)
  swc1  $f10, 0x18($sp)
  jal   sub_GAME_7F05A928
   swc1  $f8, 0x10($sp)
  swc1  $f0, 0x34($s0)
  lwc1  $f10, 0x70($sp)
  lwc1  $f8, 0x74($sp)
  lwc1  $f6, 0x80($sp)
  mfc1  $a2, $f22
  swc1  $f26, 0x20($sp)
  swc1  $f24, 0x14($sp)
  lw    $a3, 0x84($sp)
  lwc1  $f14, 0x90($sp)
  mov.s $f12, $f30
  swc1  $f10, 0x1c($sp)
  swc1  $f8, 0x18($sp)
  jal   sub_GAME_7F05A928
   swc1  $f6, 0x10($sp)
  swc1  $f0, 8($s0)
  lwc1  $f8, 0x70($sp)
  lwc1  $f6, 0x74($sp)
  lwc1  $f4, 0x80($sp)
  mfc1  $a2, $f20
  swc1  $f26, 0x20($sp)
  swc1  $f24, 0x14($sp)
  lw    $a3, 0x84($sp)
  lwc1  $f14, 0xa0($sp)
  mov.s $f12, $f28
  swc1  $f8, 0x1c($sp)
  swc1  $f6, 0x18($sp)
  jal   sub_GAME_7F05A928
   swc1  $f4, 0x10($sp)
  neg.s $f10, $f0
  mfc1  $a2, $f20
  swc1  $f10, 0x18($s0)
  lwc1  $f8, 0x70($sp)
  lwc1  $f6, 0x74($sp)
  lwc1  $f4, 0x90($sp)
  mfc1  $a3, $f30
  swc1  $f26, 0x20($sp)
  swc1  $f22, 0x14($sp)
  lwc1  $f14, 0xa0($sp)
  mov.s $f12, $f28
  swc1  $f8, 0x1c($sp)
  swc1  $f6, 0x18($sp)
  jal   sub_GAME_7F05A928
   swc1  $f4, 0x10($sp)
  swc1  $f0, 0x28($s0)
  lwc1  $f6, 0x80($sp)
  lwc1  $f4, 0x84($sp)
  lwc1  $f10, 0x90($sp)
  mfc1  $a2, $f20
  mfc1  $a3, $f30
  swc1  $f24, 0x20($sp)
  swc1  $f22, 0x14($sp)
  lwc1  $f14, 0xa0($sp)
  mov.s $f12, $f28
  swc1  $f6, 0x1c($sp)
  swc1  $f4, 0x18($sp)
  jal   sub_GAME_7F05A928
   swc1  $f10, 0x10($sp)
  neg.s $f8, $f0
  mov.s $f12, $f30
  swc1  $f8, 0x38($s0)
  lwc1  $f10, 0x80($sp)
  lwc1  $f8, 0x70($sp)
  lwc1  $f6, 0x74($sp)
  swc1  $f10, 0x10($sp)
  lwc1  $f10, 0x6c($sp)
  lwc1  $f4, 0x7c($sp)
  lw    $a3, 0x84($sp)
  lw    $a2, 0x8c($sp)
  lwc1  $f14, 0x90($sp)
  swc1  $f8, 0x1c($sp)
  swc1  $f6, 0x18($sp)
  swc1  $f10, 0x20($sp)
  jal   sub_GAME_7F05A928
   swc1  $f4, 0x14($sp)
  neg.s $f4, $f0
  mov.s $f12, $f28
  swc1  $f4, 0xc($s0)
  lwc1  $f6, 0x80($sp)
  lwc1  $f4, 0x70($sp)
  lwc1  $f10, 0x74($sp)
  swc1  $f6, 0x10($sp)
  lwc1  $f6, 0x6c($sp)
  lwc1  $f8, 0x7c($sp)
  lw    $a3, 0x84($sp)
  lw    $a2, 0x9c($sp)
  lwc1  $f14, 0xa0($sp)
  swc1  $f4, 0x1c($sp)
  swc1  $f10, 0x18($sp)
  swc1  $f6, 0x20($sp)
  jal   sub_GAME_7F05A928
   swc1  $f8, 0x14($sp)
  swc1  $f0, 0x1c($s0)
  lwc1  $f8, 0x90($sp)
  lwc1  $f6, 0x70($sp)
  lwc1  $f4, 0x74($sp)
  swc1  $f8, 0x10($sp)
  lwc1  $f8, 0x6c($sp)
  lwc1  $f10, 0x8c($sp)
  mfc1  $a3, $f30
  lw    $a2, 0x9c($sp)
  lwc1  $f14, 0xa0($sp)
  mov.s $f12, $f28
  swc1  $f6, 0x1c($sp)
  swc1  $f4, 0x18($sp)
  swc1  $f8, 0x20($sp)
  jal   sub_GAME_7F05A928
   swc1  $f10, 0x14($sp)
  neg.s $f10, $f0
  mfc1  $a3, $f30
  swc1  $f10, 0x2c($s0)
  lwc1  $f4, 0x90($sp)
  lwc1  $f10, 0x80($sp)
  lwc1  $f8, 0x84($sp)
  swc1  $f4, 0x10($sp)
  lwc1  $f4, 0x7c($sp)
  lwc1  $f6, 0x8c($sp)
  lw    $a2, 0x9c($sp)
  lwc1  $f14, 0xa0($sp)
  mov.s $f12, $f28
  swc1  $f10, 0x1c($sp)
  swc1  $f8, 0x18($sp)
  swc1  $f4, 0x20($sp)
  jal   sub_GAME_7F05A928
   swc1  $f6, 0x14($sp)
  swc1  $f0, 0x3c($s0)
  lw    $ra, 0x64($sp)
  lw    $s0, 0x60($sp)
  ldc1  $f30, 0x58($sp)
  ldc1  $f28, 0x50($sp)
  ldc1  $f26, 0x48($sp)
  ldc1  $f24, 0x40($sp)
  ldc1  $f22, 0x38($sp)
  ldc1  $f20, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0xa8
");

asm(R"
glabel sub_GAME_7F05A774
  addiu $sp, $sp, -0x80
  sw    $ra, 0x2c($sp)
  lwc1  $f4, ($a0)
  swc1  $f4, 0x78($sp)
  lwc1  $f6, 4($a0)
  swc1  $f6, 0x68($sp)
  lwc1  $f8, 8($a0)
  swc1  $f8, 0x58($sp)
  lwc1  $f10, 0xc($a0)
  swc1  $f10, 0x48($sp)
  lwc1  $f4, 0x18($a0)
  lwc1  $f0, 0x14($a0)
  lwc1  $f12, 0x10($a0)
  swc1  $f4, 0x54($sp)
  lwc1  $f6, 0x28($a0)
  lwc1  $f2, 0x1c($a0)
  lwc1  $f16, 0x24($a0)
  lwc1  $f14, 0x20($a0)
  swc1  $f6, 0x50($sp)
  lwc1  $f8, 0x30($a0)
  lwc1  $f18, 0x2c($a0)
  mfc1  $a3, $f0
  swc1  $f8, 0x6c($sp)
  lwc1  $f10, 0x34($a0)
  lw    $a2, 0x6c($sp)
  swc1  $f10, 0x5c($sp)
  lwc1  $f4, 0x38($a0)
  lwc1  $f8, 0x5c($sp)
  swc1  $f4, 0x4c($sp)
  lwc1  $f6, 0x3c($a0)
  swc1  $f0, 0x64($sp)
  swc1  $f12, 0x74($sp)
  swc1  $f6, 0x3c($sp)
  lwc1  $f10, 0x3c($sp)
  swc1  $f2, 0x44($sp)
  swc1  $f2, 0x18($sp)
  swc1  $f16, 0x60($sp)
  swc1  $f16, 0x10($sp)
  swc1  $f14, 0x70($sp)
  swc1  $f18, 0x40($sp)
  swc1  $f18, 0x1c($sp)
  swc1  $f8, 0x14($sp)
  jal   sub_GAME_7F05A928
   swc1  $f10, 0x20($sp)
  lwc1  $f4, 0x50($sp)
  lwc1  $f6, 0x4c($sp)
  lwc1  $f8, 0x44($sp)
  swc1  $f4, 0x10($sp)
  lwc1  $f4, 0x3c($sp)
  lwc1  $f10, 0x40($sp)
  swc1  $f0, 0x30($sp)
  lwc1  $f12, 0x74($sp)
  lwc1  $f14, 0x70($sp)
  lw    $a2, 0x6c($sp)
  lw    $a3, 0x54($sp)
  swc1  $f6, 0x14($sp)
  swc1  $f8, 0x18($sp)
  swc1  $f4, 0x20($sp)
  jal   sub_GAME_7F05A928
   swc1  $f10, 0x1c($sp)
  lwc1  $f6, 0x50($sp)
  lwc1  $f8, 0x4c($sp)
  lwc1  $f10, 0x44($sp)
  swc1  $f6, 0x10($sp)
  lwc1  $f6, 0x3c($sp)
  lwc1  $f4, 0x40($sp)
  swc1  $f0, 0x34($sp)
  lwc1  $f12, 0x64($sp)
  lwc1  $f14, 0x60($sp)
  lw    $a2, 0x5c($sp)
  lw    $a3, 0x54($sp)
  swc1  $f8, 0x14($sp)
  swc1  $f10, 0x18($sp)
  swc1  $f6, 0x20($sp)
  jal   sub_GAME_7F05A928
   swc1  $f4, 0x1c($sp)
  lwc1  $f8, 0x60($sp)
  lwc1  $f10, 0x5c($sp)
  lwc1  $f4, 0x54($sp)
  swc1  $f8, 0x10($sp)
  lwc1  $f8, 0x4c($sp)
  lwc1  $f6, 0x50($sp)
  swc1  $f0, 0x38($sp)
  lwc1  $f12, 0x74($sp)
  lwc1  $f14, 0x70($sp)
  lw    $a2, 0x6c($sp)
  lw    $a3, 0x64($sp)
  swc1  $f10, 0x14($sp)
  swc1  $f4, 0x18($sp)
  swc1  $f8, 0x20($sp)
  jal   sub_GAME_7F05A928
   swc1  $f6, 0x1c($sp)
  lwc1  $f10, 0x78($sp)
  lwc1  $f4, 0x38($sp)
  lwc1  $f8, 0x68($sp)
  lw    $ra, 0x2c($sp)
  mul.s $f6, $f10, $f4
  lwc1  $f10, 0x34($sp)
  mul.s $f4, $f8, $f10
  lwc1  $f10, 0x58($sp)
  sub.s $f8, $f6, $f4
  lwc1  $f6, 0x30($sp)
  mul.s $f4, $f10, $f6
  lwc1  $f6, 0x48($sp)
  addiu $sp, $sp, 0x80
  add.s $f10, $f8, $f4
  mul.s $f8, $f0, $f6
  jr    $ra
   sub.s $f0, $f10, $f8
");

asm(R"
glabel sub_GAME_7F05A928
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  swc1  $f12, 0x28($sp)
  swc1  $f14, 0x2c($sp)
  sw    $a2, 0x30($sp)
  sw    $a3, 0x34($sp)
  lw    $a3, 0x48($sp)
  lwc1  $f14, 0x30($sp)
  lw    $a2, 0x44($sp)
  jal   sub_GAME_7F05A9B8
   lwc1  $f12, 0x2c($sp)
  swc1  $f0, 0x1c($sp)
  lwc1  $f12, 0x38($sp)
  lwc1  $f14, 0x3c($sp)
  lw    $a2, 0x44($sp)
  jal   sub_GAME_7F05A9B8
   lw    $a3, 0x48($sp)
  swc1  $f0, 0x20($sp)
  lwc1  $f12, 0x2c($sp)
  lwc1  $f14, 0x30($sp)
  lw    $a2, 0x38($sp)
  jal   sub_GAME_7F05A9B8
   lw    $a3, 0x3c($sp)
  lwc1  $f4, 0x28($sp)
  lwc1  $f6, 0x20($sp)
  lwc1  $f10, 0x34($sp)
  lwc1  $f16, 0x1c($sp)
  mul.s $f8, $f4, $f6
  lwc1  $f6, 0x40($sp)
  lw    $ra, 0x14($sp)
  mul.s $f18, $f10, $f16
  addiu $sp, $sp, 0x28
  mul.s $f10, $f0, $f6
  sub.s $f4, $f8, $f18
  jr    $ra
   add.s $f0, $f10, $f4
");

asm(R"
glabel sub_GAME_7F05A9B8
  sw    $a3, 0xc($sp)
  lwc1  $f4, 0xc($sp)
  sw    $a2, 8($sp)
  lwc1  $f8, 8($sp)
  mul.s $f6, $f12, $f4
  nop   
  mul.s $f10, $f14, $f8
  jr    $ra
   sub.s $f0, $f6, $f10
");
