unsigned int D_80032300 = 0;
unsigned int D_80032304 = 0;
unsigned int D_80032308 = 0;

asm(R"
.late_rodata
glabel D_80053690
.word 0x40c90fdb /*6.2831855*/
glabel D_80053694
.word 0x3dc90fdb /*0.098174773*/
glabel D_80053698
.word 0x40c90fdb /*6.2831855*/
glabel D_8005369C
.word 0x3dc90fdb /*0.098174773*/
glabel D_800536A0
.word 0x40c90fdb /*6.2831855*/
glabel D_800536A4
.word 0x3dc90fdb /*0.098174773*/

.text
glabel sub_GAME_7F057AC0
  addiu $sp, $sp, -0x28
  lui   $t7, %hi(D_80032300) 
  sw    $ra, 0x14($sp)
  sw    $a0, 0x28($sp)
  addiu $t7, %lo(D_80032300) # addiu $t7, $t7, 0x2300
  lw    $at, ($t7)
  addiu $t6, $sp, 0x1c
  lw    $t0, 4($t7)
  sw    $at, ($t6)
  lw    $at, 8($t7)
  sw    $t0, 4($t6)
  jal   get_random_value
   sw    $at, 8($t6)
  mtc1  $v0, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F057B10
   cvt.s.w $f6, $f4
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F057B10:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f10
  lui   $at, %hi(D_80053690)
  lwc1  $f18, %lo(D_80053690)($at)
  mul.s $f16, $f6, $f10
  li    $at, 0x3D000000 # 0.031250
  mtc1  $at, $f8
  lui   $at, %hi(D_80053694)
  lwc1  $f10, %lo(D_80053694)($at)
  mul.s $f4, $f16, $f18
  nop   
  mul.s $f6, $f4, $f8
  sub.s $f16, $f6, $f10
  jal   get_random_value
   swc1  $f16, 0x1c($sp)
  mtc1  $v0, $f18
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F057B68
   cvt.s.w $f4, $f18
  mtc1  $at, $f8
  nop   
  add.s $f4, $f4, $f8
.L7F057B68:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f6
  lui   $at, %hi(D_80053698)
  lwc1  $f16, %lo(D_80053698)($at)
  mul.s $f10, $f4, $f6
  li    $at, 0x3D000000 # 0.031250
  mtc1  $at, $f8
  lui   $at, %hi(D_8005369C)
  lwc1  $f6, %lo(D_8005369C)($at)
  mul.s $f18, $f10, $f16
  nop   
  mul.s $f4, $f18, $f8
  sub.s $f10, $f4, $f6
  jal   get_random_value
   swc1  $f10, 0x20($sp)
  mtc1  $v0, $f16
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F057BC0
   cvt.s.w $f18, $f16
  mtc1  $at, $f8
  nop   
  add.s $f18, $f18, $f8
.L7F057BC0:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f4
  lui   $at, %hi(D_800536A0)
  lwc1  $f10, %lo(D_800536A0)($at)
  mul.s $f6, $f18, $f4
  li    $at, 0x3D000000 # 0.031250
  mtc1  $at, $f8
  lui   $at, %hi(D_800536A4)
  lwc1  $f4, %lo(D_800536A4)($at)
  addiu $a0, $sp, 0x1c
  lw    $a1, 0x28($sp)
  mul.s $f16, $f6, $f10
  nop   
  mul.s $f18, $f16, $f8
  sub.s $f6, $f18, $f4
  jal   sub_GAME_7F058714
   swc1  $f6, 0x24($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_800536A8
.word 0x3fd55555 /*1.6666666*/
glabel D_800536AC
.word 0x40555555 /*3.3333333*/
glabel D_800536B0
.word 0x3fd55555 /*1.6666666*/
glabel D_800536B4
.word 0x3fd55555 /*1.6666666*/
glabel D_800536B8
.word 0x40555555 /*3.3333333*/
.text
glabel sub_GAME_7F057C14
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  jal   get_random_value
   sw    $a1, 0x1c($sp)
  mtc1  $v0, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F057C44
   cvt.s.w $f6, $f4
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F057C44:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f10
  lui   $at, %hi(D_800536A8)
  lwc1  $f18, %lo(D_800536A8)($at)
  mul.s $f16, $f6, $f10
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f8
  lui   $at, %hi(D_800536AC)
  lwc1  $f10, %lo(D_800536AC)($at)
  lw    $t6, 0x18($sp)
  mul.s $f4, $f16, $f18
  nop   
  mul.s $f6, $f4, $f8
  sub.s $f16, $f6, $f10
  jal   get_random_value
   swc1  $f16, ($t6)
  mtc1  $v0, $f18
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F057CA0
   cvt.s.w $f4, $f18
  mtc1  $at, $f8
  nop   
  add.s $f4, $f4, $f8
.L7F057CA0:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f6
  lui   $at, %hi(D_800536B0)
  lwc1  $f16, %lo(D_800536B0)($at)
  mul.s $f10, $f4, $f6
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f8
  lw    $t7, 0x18($sp)
  mul.s $f18, $f10, $f16
  nop   
  mul.s $f4, $f18, $f8
  jal   get_random_value
   swc1  $f4, 4($t7)
  mtc1  $v0, $f6
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F057CF0
   cvt.s.w $f10, $f6
  mtc1  $at, $f16
  nop   
  add.s $f10, $f10, $f16
.L7F057CF0:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f18
  lui   $at, %hi(D_800536B4)
  lwc1  $f4, %lo(D_800536B4)($at)
  mul.s $f8, $f10, $f18
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f16
  lui   $at, %hi(D_800536B8)
  lwc1  $f18, %lo(D_800536B8)($at)
  lw    $t8, 0x18($sp)
  mul.s $f6, $f8, $f4
  nop   
  mul.s $f10, $f6, $f16
  sub.s $f8, $f10, $f18
  swc1  $f8, 8($t8)
  jal   sub_GAME_7F057AC0
   lw    $a0, 0x1c($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel npc_gravity_modifier
.word 0x3e8e38e4 /*0.27777779*/
.text
glabel sub_GAME_7F057D44
  lui   $at, %hi(npc_gravity_modifier)
  mtc1  $a2, $f12
  lwc1  $f4, %lo(npc_gravity_modifier)($at)
  lwc1  $f2, ($a1)
  li    $at, 0x3F000000 # 0.500000
  mul.s $f6, $f12, $f4
  mtc1  $at, $f16
  lwc1  $f4, ($a0)
  sub.s $f0, $f2, $f6
  add.s $f8, $f2, $f0
  mul.s $f10, $f12, $f8
  nop   
  mul.s $f18, $f10, $f16
  add.s $f6, $f4, $f18
  swc1  $f6, ($a0)
  jr    $ra
   swc1  $f0, ($a1)
");

asm(R"
glabel sub_GAME_7F057D88
  mtc1  $a2, $f12
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a1, 0x1c($sp)
  move  $a3, $a0
  mfc1  $a2, $f12
  sw    $a3, 0x18($sp)
  addiu $a0, $a0, 4
  addiu $a1, $a1, 4
  jal   sub_GAME_7F057D44
   swc1  $f12, 0x20($sp)
  lw    $v0, 0x1c($sp)
  lwc1  $f12, 0x20($sp)
  lw    $a3, 0x18($sp)
  lwc1  $f6, ($v0)
  lwc1  $f4, ($a3)
  mul.s $f8, $f12, $f6
  lwc1  $f16, 8($a3)
  add.s $f10, $f4, $f8
  swc1  $f10, ($a3)
  lwc1  $f18, 8($v0)
  mul.s $f6, $f12, $f18
  add.s $f4, $f16, $f6
  swc1  $f4, 8($a3)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F057DF8
  addiu $sp, $sp, -0x28
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  move  $s1, $a2
  move  $s2, $a1
  move  $s3, $a0
  sw    $ra, 0x24($sp)
  blez  $a2, .L7F057E3C
   move  $s0, $zero
  move  $a0, $s2
.L7F057E28:
  jal   matrix_4x4_multiply_homogeneous_in_place
   move  $a1, $s3
  addiu $s0, $s0, 1
  bnel  $s0, $s1, .L7F057E28
   move  $a0, $s2
.L7F057E3C:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
glabel sub_GAME_7F057E58
  addiu $sp, $sp, -0x18
  lw    $t6, 0x28($sp)
  sw    $a2, 0x20($sp)
  sw    $ra, 0x14($sp)
  mtc1  $t6, $f4
  sw    $a3, 0x24($sp)
  cvt.s.w $f4, $f4
  mfc1  $a2, $f4
  jal   sub_GAME_7F057D88
   nop   
  lw    $a0, 0x20($sp)
  lw    $a1, 0x24($sp)
  jal   sub_GAME_7F057DF8
   lw    $a2, 0x28($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");
