unsigned int D_80036AD0 = 0x4144;
unsigned int D_80036AD4 = 0x41180000;
unsigned int D_80036AD8 = 0x41D80000;
unsigned int D_80036ADC = 0;
unsigned int D_80036AE0 = 0;

unsigned int D_80036AE4 = 0x3FC00000;
unsigned int D_80036AE8 = 0x4070;
unsigned int D_80036AEC = 0x40F00000;
unsigned int D_80036AF0 = 0x41880000;
unsigned int D_80036AF4 = 0;
unsigned int D_80036AF8 = 0x3FC00000;
unsigned int D_80036AFC = 0x42C80000;

unsigned int D_80036B00 = 0;
unsigned int D_80036B04 = 0;
unsigned int D_80036B08 = 0;
unsigned int D_80036B0C = 0;
unsigned int D_80036B10 = 0;
float D_80036B14 = 1.0;
unsigned int D_80036B18 = 0;
float D_80036B1C = 1.0;
unsigned int D_80036B20 = 0;
unsigned int D_80036B24 = 0;
unsigned int D_80036B28 = 1;
unsigned int D_80036B2C = 3;
unsigned int D_80036B30[12] = {0};
unsigned int D_80036B60 = 0;
unsigned int D_80036B64 = 0;
unsigned int D_80036B68 = 0;
unsigned int D_80036B6C = 0;

asm(R"
glabel sub_GAME_7F08DBB0
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  lb    $v0, 0x5bc($v1)
  sltiu $t6, $v0, 1
  jr    $ra
   sb    $t6, 0x5bc($v1)
");

asm(R"
.late_rodata
glabel D_800552E0
.word 0x3ca3d70a /*0.02*/
glabel D_800552E4
.word 0x3ca3d70a /*0.02*/
glabel D_800552E8
.word 0x3c23d70a /*0.0099999998*/
glabel D_800552EC
.word 0xbc23d70a  /*-0.0099999998*/
glabel D_800552F0
.word 0xbc23d70a  /*-0.0099999998*/
glabel D_800552F4
.word 0x3c23d70a /*0.0099999998*/

.text
glabel sub_GAME_7F08DBC8
  addiu $sp, $sp, -0x30
  sw    $ra, 0x2c($sp)
  sw    $s2, 0x28($sp)
  sw    $s1, 0x24($sp)
  sw    $s0, 0x20($sp)
  jal   get_random_value
   sdc1  $f20, 0x18($sp)
  mtc1  $v0, $f4
  lui   $s1, %hi(pPlayer)
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f20
  addiu $s1, %lo(pPlayer) # addiu $s1, $s1, -0x5f50
  lw    $s0, ($s1)
  li    $s2, 12
  bgez  $v0, .L7F08DC18
   cvt.s.w $f6, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F08DC18:
  mul.s $f10, $f6, $f20
  lw    $t6, 0x594($s0)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f16
  multu $t6, $s2
  lui   $at, %hi(D_800552E0)
  lwc1  $f4, %lo(D_800552E0)($at)
  sub.s $f18, $f10, $f16
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  mul.s $f8, $f18, $f4
  mflo  $t7
  addu  $t8, $s0, $t7
  swc1  $f8, 0x564($t8)
  lw    $s0, ($s1)
  lw    $t9, 0x594($s0)
  multu $t9, $s2
  mflo  $t0
  addu  $t1, $s0, $t0
  jal   get_random_value
   swc1  $f6, 0x56c($t1)
  mtc1  $v0, $f10
  lw    $s0, ($s1)
  bgez  $v0, .L7F08DC8C
   cvt.s.w $f16, $f10
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f18
  nop   
  add.s $f16, $f16, $f18
.L7F08DC8C:
  mul.s $f4, $f16, $f20
  lw    $t2, 0x594($s0)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f8
  multu $t2, $s2
  lui   $at, %hi(D_800552E4)
  lwc1  $f10, %lo(D_800552E4)($at)
  sub.s $f6, $f4, $f8
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f16
  mul.s $f18, $f6, $f10
  mflo  $t3
  addu  $t4, $s0, $t3
  swc1  $f18, 0x57c($t4)
  lw    $s0, ($s1)
  lw    $t5, 0x594($s0)
  multu $t5, $s2
  mflo  $t6
  addu  $t7, $s0, $t6
  swc1  $f16, 0x580($t7)
  lw    $t8, ($s1)
  lw    $t9, 0x594($t8)
  beqz  $t9, .L7F08DD84
   nop   
  jal   get_random_value
   nop   
  mtc1  $v0, $f4
  lw    $s0, ($s1)
  bgez  $v0, .L7F08DD14
   cvt.s.w $f8, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f6
  nop   
  add.s $f8, $f8, $f6
.L7F08DD14:
  lw    $t0, 0x594($s0)
  mul.s $f10, $f8, $f20
  lui   $at, %hi(D_800552E8)
  multu $t0, $s2
  lwc1  $f18, %lo(D_800552E8)($at)
  mul.s $f16, $f10, $f18
  mflo  $t1
  addu  $t2, $s0, $t1
  jal   get_random_value
   swc1  $f16, 0x568($t2)
  mtc1  $v0, $f4
  lw    $s0, ($s1)
  bgez  $v0, .L7F08DD5C
   cvt.s.w $f6, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F08DD5C:
  lw    $t3, 0x594($s0)
  mul.s $f10, $f6, $f20
  lui   $at, %hi(D_800552EC)
  multu $t3, $s2
  lwc1  $f18, %lo(D_800552EC)($at)
  mul.s $f16, $f10, $f18
  mflo  $t4
  addu  $t5, $s0, $t4
  b     .L7F08DE18
   swc1  $f16, 0x584($t5)
.L7F08DD84:
  jal   get_random_value
   nop   
  mtc1  $v0, $f4
  lw    $s0, ($s1)
  bgez  $v0, .L7F08DDAC
   cvt.s.w $f8, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f6
  nop   
  add.s $f8, $f8, $f6
.L7F08DDAC:
  lw    $t6, 0x594($s0)
  mul.s $f10, $f8, $f20
  lui   $at, %hi(D_800552F0)
  multu $t6, $s2
  lwc1  $f18, %lo(D_800552F0)($at)
  mul.s $f16, $f10, $f18
  mflo  $t7
  addu  $t8, $s0, $t7
  jal   get_random_value
   swc1  $f16, 0x568($t8)
  mtc1  $v0, $f4
  lw    $s0, ($s1)
  bgez  $v0, .L7F08DDF4
   cvt.s.w $f6, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F08DDF4:
  lw    $t9, 0x594($s0)
  mul.s $f10, $f6, $f20
  lui   $at, %hi(D_800552F4)
  multu $t9, $s2
  lwc1  $f18, %lo(D_800552F4)($at)
  mul.s $f16, $f10, $f18
  mflo  $t0
  addu  $t1, $s0, $t0
  swc1  $f16, 0x584($t1)
.L7F08DE18:
  lw    $s0, ($s1)
  li    $t3, 1
  lw    $t2, 0x594($s0)
  subu  $t4, $t3, $t2
  sw    $t4, 0x594($s0)
  lw    $ra, 0x2c($sp)
  lw    $s2, 0x28($sp)
  lw    $s1, 0x24($sp)
  lw    $s0, 0x20($sp)
  ldc1  $f20, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x30
");

asm(R"
.late_rodata
glabel D_800552F8
.word 0x3d8f5c28 /*0.069999993*/
glabel master_player_perspective
.word 0x3d8f5c28 /*0.069999993*/
glabel D_80055300
.word 0x3f6e147b /*0.93000001*/
.text
glabel sub_GAME_7F08DE48
  lui   $a1, %hi(pPlayer)
  addiu $a1, %lo(pPlayer) # addiu $a1, $a1, -0x5f50
  lw    $v0, ($a1)
  lui   $a2, %hi(clock_timer)
  addiu $a2, %lo(clock_timer) # addiu $a2, $a2, -0x7c8c
  lw    $t6, 0x4dc($v0)
  beql  $t6, $zero, .L7F08DE9C
   lw    $t0, ($a2)
  mtc1  $zero, $f0
  lui   $at, %hi(D_800552F8)
  lwc1  $f2, %lo(D_800552F8)($at)
  swc1  $f0, 0x520($v0)
  lwc1  $f4, 4($a0)
  lw    $t7, ($a1)
  div.s $f6, $f4, $f2
  swc1  $f6, 0x524($t7)
  lw    $t8, ($a1)
  swc1  $f0, 0x528($t8)
  lw    $t9, ($a1)
  sw    $zero, 0x4dc($t9)
  lw    $t0, ($a2)
.L7F08DE9C:
  lui   $at, %hi(master_player_perspective)
  lwc1  $f2, %lo(master_player_perspective)($at)
  blez  $t0, .L7F08DF10
   move  $v1, $zero
  lui   $at, %hi(D_80055300)
  lwc1  $f0, %lo(D_80055300)($at)
  lw    $v0, ($a1)
.L7F08DEB8:
  lwc1  $f8, ($a0)
  addiu $v1, $v1, 1
  lwc1  $f10, 0x520($v0)
  mul.s $f16, $f0, $f10
  add.s $f18, $f8, $f16
  swc1  $f18, 0x520($v0)
  lw    $v0, ($a1)
  lwc1  $f4, 4($a0)
  lwc1  $f6, 0x524($v0)
  mul.s $f10, $f0, $f6
  add.s $f8, $f4, $f10
  swc1  $f8, 0x524($v0)
  lw    $v0, ($a1)
  lwc1  $f16, 8($a0)
  lwc1  $f18, 0x528($v0)
  mul.s $f6, $f0, $f18
  add.s $f4, $f16, $f6
  swc1  $f4, 0x528($v0)
  lw    $t1, ($a2)
  slt   $at, $v1, $t1
  bnezl $at, .L7F08DEB8
   lw    $v0, ($a1)
.L7F08DF10:
  lw    $v0, ($a1)
  lwc1  $f10, 0x520($v0)
  mul.s $f8, $f10, $f2
  swc1  $f8, 0x4fc($v0)
  lw    $v0, ($a1)
  lwc1  $f18, 0x524($v0)
  mul.s $f16, $f18, $f2
  swc1  $f16, 0x500($v0)
  lw    $v0, ($a1)
  lwc1  $f6, 0x528($v0)
  mul.s $f4, $f6, $f2
  jr    $ra
   swc1  $f4, 0x504($v0)
");

asm(R"
glabel sub_GAME_7F08DF44
  lui   $a2, %hi(pPlayer)
  addiu $a2, %lo(pPlayer) # addiu $a2, $a2, -0x5f50
  lw    $v0, ($a2)
  lui   $a3, %hi(clock_timer)
  li    $at, 0x3F800000 # 1.000000
  lw    $t6, 0x4e0($v0)
  addiu $a3, %lo(clock_timer) # addiu $a3, $a3, -0x7c8c
  beql  $t6, $zero, .L7F08E004
   lw    $t8, ($a3)
  mtc1  $at, $f0
  lwc1  $f6, 0x4ec($v0)
  lwc1  $f4, ($a0)
  sub.s $f8, $f0, $f6
  div.s $f10, $f4, $f8
  swc1  $f10, 0x52c($v0)
  lw    $v0, ($a2)
  lwc1  $f16, 4($a0)
  lwc1  $f18, 0x4ec($v0)
  sub.s $f6, $f0, $f18
  div.s $f4, $f16, $f6
  swc1  $f4, 0x530($v0)
  lw    $v0, ($a2)
  lwc1  $f8, 8($a0)
  lwc1  $f10, 0x4ec($v0)
  sub.s $f18, $f0, $f10
  div.s $f16, $f8, $f18
  swc1  $f16, 0x534($v0)
  lw    $v0, ($a2)
  lwc1  $f6, ($a1)
  lwc1  $f4, 0x4ec($v0)
  sub.s $f10, $f0, $f4
  div.s $f8, $f6, $f10
  swc1  $f8, 0x538($v0)
  lw    $v0, ($a2)
  lwc1  $f18, 4($a1)
  lwc1  $f16, 0x4ec($v0)
  sub.s $f4, $f0, $f16
  div.s $f6, $f18, $f4
  swc1  $f6, 0x53c($v0)
  lw    $v0, ($a2)
  lwc1  $f10, 8($a1)
  lwc1  $f8, 0x4ec($v0)
  sub.s $f16, $f0, $f8
  div.s $f18, $f10, $f16
  swc1  $f18, 0x540($v0)
  lw    $t7, ($a2)
  sw    $zero, 0x4e0($t7)
  lw    $t8, ($a3)
.L7F08E004:
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f0
  blez  $t8, .L7F08E0D0
   move  $v1, $zero
  lw    $v0, ($a2)
.L7F08E018:
  lwc1  $f10, ($a0)
  addiu $v1, $v1, 1
  lwc1  $f4, 0x4ec($v0)
  lwc1  $f6, 0x52c($v0)
  mul.s $f8, $f4, $f6
  add.s $f16, $f10, $f8
  swc1  $f16, 0x52c($v0)
  lw    $v0, ($a2)
  lwc1  $f10, 4($a0)
  lwc1  $f18, 0x4ec($v0)
  lwc1  $f4, 0x530($v0)
  mul.s $f6, $f18, $f4
  add.s $f8, $f10, $f6
  swc1  $f8, 0x530($v0)
  lw    $v0, ($a2)
  lwc1  $f10, 8($a0)
  lwc1  $f16, 0x4ec($v0)
  lwc1  $f18, 0x534($v0)
  mul.s $f4, $f16, $f18
  add.s $f6, $f10, $f4
  swc1  $f6, 0x534($v0)
  lw    $v0, ($a2)
  lwc1  $f10, ($a1)
  lwc1  $f8, 0x4ec($v0)
  lwc1  $f16, 0x538($v0)
  mul.s $f18, $f8, $f16
  add.s $f4, $f10, $f18
  swc1  $f4, 0x538($v0)
  lw    $v0, ($a2)
  lwc1  $f10, 4($a1)
  lwc1  $f6, 0x4ec($v0)
  lwc1  $f8, 0x53c($v0)
  mul.s $f16, $f6, $f8
  add.s $f18, $f10, $f16
  swc1  $f18, 0x53c($v0)
  lw    $v0, ($a2)
  lwc1  $f10, 8($a1)
  lwc1  $f4, 0x4ec($v0)
  lwc1  $f6, 0x540($v0)
  mul.s $f8, $f4, $f6
  add.s $f16, $f10, $f8
  swc1  $f16, 0x540($v0)
  lw    $t9, ($a3)
  slt   $at, $v1, $t9
  bnezl $at, .L7F08E018
   lw    $v0, ($a2)
.L7F08E0D0:
  lw    $v0, ($a2)
  lwc1  $f4, 0x4ec($v0)
  lwc1  $f18, 0x52c($v0)
  sub.s $f6, $f0, $f4
  mul.s $f10, $f18, $f6
  swc1  $f10, 0x508($v0)
  lw    $v0, ($a2)
  lwc1  $f16, 0x4ec($v0)
  lwc1  $f8, 0x530($v0)
  sub.s $f4, $f0, $f16
  mul.s $f18, $f8, $f4
  swc1  $f18, 0x50c($v0)
  lw    $v0, ($a2)
  lwc1  $f10, 0x4ec($v0)
  lwc1  $f6, 0x534($v0)
  sub.s $f16, $f0, $f10
  mul.s $f8, $f6, $f16
  swc1  $f8, 0x510($v0)
  lw    $v0, ($a2)
  lwc1  $f18, 0x4ec($v0)
  lwc1  $f4, 0x538($v0)
  sub.s $f10, $f0, $f18
  mul.s $f6, $f4, $f10
  swc1  $f6, 0x514($v0)
  lw    $v0, ($a2)
  lwc1  $f8, 0x4ec($v0)
  lwc1  $f16, 0x53c($v0)
  sub.s $f18, $f0, $f8
  mul.s $f4, $f16, $f18
  swc1  $f4, 0x518($v0)
  lw    $v0, ($a2)
  lwc1  $f6, 0x4ec($v0)
  lwc1  $f10, 0x540($v0)
  sub.s $f8, $f0, $f6
  mul.s $f16, $f10, $f8
  jr    $ra
   swc1  $f16, 0x51c($v0)
");

asm(R"
glabel sub_GAME_7F08E164
  lui   $v1, %hi(pPlayer)
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $v0, ($v1)
  li    $at, 0x3F800000 # 1.000000
  lwc1  $f0, 0x4ec($v0)
  c.eq.s $f12, $f0
  nop   
  bc1t  .L7F08E238
   nop   
  mtc1  $at, $f14
  lwc1  $f4, 0x52c($v0)
  sub.s $f6, $f14, $f0
  sub.s $f2, $f14, $f12
  mul.s $f8, $f4, $f6
  div.s $f10, $f8, $f2
  swc1  $f10, 0x52c($v0)
  lw    $v0, ($v1)
  lwc1  $f18, 0x4ec($v0)
  lwc1  $f16, 0x530($v0)
  sub.s $f4, $f14, $f18
  mul.s $f6, $f16, $f4
  div.s $f8, $f6, $f2
  swc1  $f8, 0x530($v0)
  lw    $v0, ($v1)
  lwc1  $f18, 0x4ec($v0)
  lwc1  $f10, 0x534($v0)
  sub.s $f16, $f14, $f18
  mul.s $f4, $f10, $f16
  div.s $f6, $f4, $f2
  swc1  $f6, 0x534($v0)
  lw    $v0, ($v1)
  lwc1  $f18, 0x4ec($v0)
  lwc1  $f8, 0x538($v0)
  sub.s $f10, $f14, $f18
  mul.s $f16, $f8, $f10
  div.s $f4, $f16, $f2
  swc1  $f4, 0x538($v0)
  lw    $v0, ($v1)
  lwc1  $f18, 0x4ec($v0)
  lwc1  $f6, 0x53c($v0)
  sub.s $f8, $f14, $f18
  mul.s $f10, $f6, $f8
  div.s $f16, $f10, $f2
  swc1  $f16, 0x53c($v0)
  lw    $v0, ($v1)
  lwc1  $f18, 0x4ec($v0)
  lwc1  $f4, 0x540($v0)
  sub.s $f6, $f14, $f18
  mul.s $f8, $f4, $f6
  div.s $f10, $f8, $f2
  swc1  $f10, 0x540($v0)
  lw    $t6, ($v1)
  swc1  $f12, 0x4ec($t6)
.L7F08E238:
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80055304
.word 0x3f333333 /*0.69999999*/
glabel D_80055308
.word 0x3dcccccd /*0.1*/
glabel D_8005530C
.word 0x3f19999a /*0.60000002*/
glabel D_80055310
.word 0x3f199999 /*0.59999996*/
glabel D_80055314
.word 0x3ecccccd /*0.40000001*/
glabel D_80055318
.word 0x3ecccccd /*0.40000001*/
glabel D_8005531C
.word 0x3f666666 /*0.89999998*/
glabel D_80055320
.word 0x3f6e147b /*0.93000001*/
glabel D_80055324
.word 0x3f7d70a4 /*0.99000001*/
glabel D_80055328
.word 0x3f59999a /*0.85000002*/
glabel D_8005532C
.word 0x3f7d70a4 /*0.99000001*/
glabel D_80055330
.word 0x3c088889 /*0.0083333338*/
glabel D_80055334
.word 0x3cccccce /*0.025000002*/

.text
glabel sub_GAME_7F08E240
  addiu $sp, $sp, -0xe8
  lui   $t7, %hi(D_80036B00) 
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  swc1  $f12, 0xe8($sp)
  swc1  $f14, 0xec($sp)
  addiu $t7, %lo(D_80036B00) # addiu $t7, $t7, 0x6b00
  lw    $at, ($t7)
  addiu $t6, $sp, 0xdc
  lw    $t0, 4($t7)
  sw    $at, ($t6)
  lw    $at, 8($t7)
  lui   $t2, %hi(D_80036B0C) 
  addiu $t2, %lo(D_80036B0C) # addiu $t2, $t2, 0x6b0c
  sw    $t0, 4($t6)
  sw    $at, 8($t6)
  lw    $at, ($t2)
  addiu $t1, $sp, 0xd0
  lw    $t5, 4($t2)
  sw    $at, ($t1)
  lw    $at, 8($t2)
  lui   $t8, %hi(D_80036B18) 
  addiu $t8, %lo(D_80036B18) # addiu $t8, $t8, 0x6b18
  sw    $t5, 4($t1)
  sw    $at, 8($t1)
  lw    $at, ($t8)
  addiu $t9, $sp, 0xc4
  lw    $t0, 4($t8)
  sw    $at, ($t9)
  lw    $at, 8($t8)
  lui   $s0, %hi(pPlayer)
  addiu $s0, %lo(pPlayer) # addiu $s0, $s0, -0x5f50
  sw    $t0, 4($t9)
  sw    $at, 8($t9)
  lw    $a0, ($s0)
  jal   sub_GAME_7F06F618
   addiu $a0, $a0, 0x598
  lw    $v0, ($s0)
  swc1  $f0, 0xc0($sp)
  lui   $t1, %hi(D_80036B24) 
  lw    $v1, 0x4e8($v0)
  addiu $t1, %lo(D_80036B24) # addiu $t1, $t1, 0x6b24
  addiu $t5, $t1, 0x3c
  bnez  $v1, .L7F08E380
   addiu $t3, $sp, 0x80
  lui   $at, %hi(D_80055304)
  lwc1  $f4, %lo(D_80055304)($at)
  lui   $at, %hi(D_80055308)
  c.lt.s $f4, $f0
  nop   
  bc1f  .L7F08E320
   nop   
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  b     .L7F08E370
   swc1  $f6, 0x4f4($v0)
.L7F08E320:
  lwc1  $f2, %lo(D_80055308)($at)
  lui   $at, %hi(D_80055318)
  c.lt.s $f2, $f0
  nop   
  bc1f  .L7F08E368
   nop   
  sub.s $f8, $f0, $f2
  lui   $at, %hi(D_8005530C)
  lwc1  $f10, %lo(D_8005530C)($at)
  lui   $at, %hi(D_80055310)
  lwc1  $f18, %lo(D_80055310)($at)
  mul.s $f16, $f8, $f10
  lui   $at, %hi(D_80055318)
  lwc1  $f6, %lo(D_80055314)($at)
  div.s $f4, $f16, $f18
  add.s $f8, $f4, $f6
  b     .L7F08E370
   swc1  $f8, 0x4f4($v0)
.L7F08E368:
  lwc1  $f10, %lo(D_80055318)($at)
  swc1  $f10, 0x4f4($v0)
.L7F08E370:
  lw    $v0, ($s0)
  lwc1  $f16, 0x4f4($v0)
  b     .L7F08E3C4
   swc1  $f16, 0x4f8($v0)
.L7F08E380:
  li    $at, 1
  bne   $v1, $at, .L7F08E3A8
   lui   $at, %hi(D_8005531C)
  lwc1  $f18, %lo(D_8005531C)($at)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f4
  swc1  $f18, 0x4f4($v0)
  lw    $t4, ($s0)
  b     .L7F08E3C4
   swc1  $f4, 0x4f8($t4)
.L7F08E3A8:
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  nop   
  swc1  $f6, 0x4f4($v0)
  lw    $v0, ($s0)
  lwc1  $f8, 0x4f4($v0)
  swc1  $f8, 0x4f8($v0)
.L7F08E3C4:
  lw    $at, ($t1)
  addiu $t1, $t1, 0xc
  addiu $t3, $t3, 0xc
  sw    $at, -0xc($t3)
  lw    $at, -8($t1)
  sw    $at, -8($t3)
  lw    $at, -4($t1)
  bne   $t1, $t5, .L7F08E3C4
   sw    $at, -4($t3)
  lw    $at, ($t1)
  lui   $t6, %hi(D_80036B64) 
  addiu $t6, %lo(D_80036B64) # addiu $t6, $t6, 0x6b64
  sw    $at, ($t3)
  lw    $at, ($t6)
  addiu $t7, $sp, 0x34
  lw    $t8, 4($t6)
  sw    $at, ($t7)
  lw    $at, 8($t6)
  sw    $t8, 4($t7)
  jal   sub_GAME_7F0701E0
   sw    $at, 8($t7)
  lw    $t0, ($s0)
  sw    $v0, 0x30($sp)
  move  $a0, $zero
  jal   sub_GAME_7F0701D4
   sw    $zero, 0x4e4($t0)
  lw    $a0, ($s0)
  lui   $a1, %hi(clock_timer)
  lw    $a1, %lo(clock_timer)($a1)
  li    $a2, 1
  jal   sub_GAME_7F070AEC
   addiu $a0, $a0, 0x598
  jal   sub_GAME_7F0701D4
   lw    $a0, 0x30($sp)
  lw    $a0, ($s0)
  jal   subcalcpos
   addiu $a0, $a0, 0x598
  jal   reset_array_of_0x10_floats
   addiu $a0, $sp, 0x40
  lw    $v0, ($s0)
  addiu $t4, $sp, 0x40
  sw    $t4, 0x80($sp)
  addiu $t2, $v0, 0x6d0
  sw    $t2, 0x90($sp)
  addiu $a0, $sp, 0x80
  jal   subcalcmatrices
   addiu $a1, $v0, 0x598
  lw    $v0, ($s0)
  addiu $a1, $sp, 0x34
  lwc1  $f10, 0x554($v0)
  swc1  $f10, 0x544($v0)
  lw    $v0, ($s0)
  lwc1  $f16, 0x558($v0)
  swc1  $f16, 0x548($v0)
  lw    $v0, ($s0)
  lwc1  $f18, 0x55c($v0)
  swc1  $f18, 0x54c($v0)
  lw    $a0, ($s0)
  jal   getsuboffset
   addiu $a0, $a0, 0x598
  lw    $v0, ($s0)
  lwc1  $f4, 0x34($sp)
  lwc1  $f10, 0x3c($sp)
  lwc1  $f6, 0x700($v0)
  addiu $a1, $sp, 0x34
  addiu $a0, $v0, 0x598
  sub.s $f8, $f4, $f6
  swc1  $f8, 0x34($sp)
  lwc1  $f16, 0x708($v0)
  sub.s $f18, $f10, $f16
  jal   setsuboffset
   swc1  $f18, 0x3c($sp)
  mtc1  $zero, $f0
  lwc1  $f4, 0xc0($sp)
  c.lt.s $f0, $f4
  nop   
  bc1fl .L7F08E6BC
   lw    $v0, ($s0)
  lw    $v0, ($s0)
  lwc1  $f8, 0xec($sp)
  lui   $a0, %hi(clock_timer)
  lwc1  $f6, 0x700($v0)
  addiu $a0, %lo(clock_timer) # addiu $a0, $a0, -0x7c8c
  lui   $v1, %hi(global_timer_delta)
  add.s $f10, $f6, $f8
  swc1  $f10, 0x700($v0)
  lw    $v0, ($s0)
  lwc1  $f18, 0xe8($sp)
  lwc1  $f16, 0x708($v0)
  mul.s $f4, $f16, $f18
  swc1  $f4, 0x708($v0)
  lw    $t5, ($a0)
  blezl $t5, .L7F08E56C
   lw    $v0, ($s0)
  lw    $v0, ($s0)
  addiu $v1, %lo(global_timer_delta) # addiu $v1, $v1, -0x7c88
  lwc1  $f8, ($v1)
  lwc1  $f6, 0x700($v0)
  div.s $f10, $f6, $f8
  swc1  $f10, 0x700($v0)
  lw    $v0, ($s0)
  lwc1  $f18, ($v1)
  lwc1  $f16, 0x708($v0)
  div.s $f4, $f16, $f18
  swc1  $f4, 0x708($v0)
  lw    $v0, ($s0)
.L7F08E56C:
  lwc1  $f6, 0x700($v0)
  lwc1  $f8, 0x4f4($v0)
  mul.s $f10, $f6, $f8
  swc1  $f10, 0xdc($sp)
  lwc1  $f16, 0x704($v0)
  lwc1  $f0, 0x550($v0)
  lwc1  $f4, 0x4f4($v0)
  sub.s $f18, $f16, $f0
  mul.s $f6, $f18, $f4
  add.s $f8, $f6, $f0
  swc1  $f8, 0xe0($sp)
  lwc1  $f16, 0x4f4($v0)
  lwc1  $f10, 0x708($v0)
  mul.s $f18, $f10, $f16
  swc1  $f18, 0xe4($sp)
  lw    $t1, 0x4e8($v0)
  bltzl $t1, .L7F08E678
   lwc1  $f16, 0x6f0($v0)
  lwc1  $f4, 0x6f0($v0)
  lwc1  $f6, 0x4f8($v0)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f0
  mul.s $f8, $f4, $f6
  lw    $t9, ($a0)
  swc1  $f8, 0xd0($sp)
  lwc1  $f16, 0x4f4($v0)
  lwc1  $f10, 0x6f4($v0)
  mul.s $f18, $f10, $f16
  swc1  $f18, 0xd4($sp)
  lwc1  $f4, 0x6f8($v0)
  lwc1  $f8, 0x4f4($v0)
  sub.s $f6, $f4, $f0
  mul.s $f10, $f6, $f8
  add.s $f16, $f10, $f0
  swc1  $f16, 0xd8($sp)
  lwc1  $f4, 0x4f4($v0)
  lwc1  $f18, 0x6e0($v0)
  mul.s $f6, $f18, $f4
  swc1  $f6, 0xc4($sp)
  lwc1  $f8, 0x6e4($v0)
  lwc1  $f16, 0x4f4($v0)
  sub.s $f10, $f8, $f0
  mul.s $f18, $f10, $f16
  add.s $f4, $f18, $f0
  swc1  $f4, 0xc8($sp)
  lwc1  $f8, 0x4f4($v0)
  lwc1  $f6, 0x6e8($v0)
  mul.s $f10, $f6, $f8
  swc1  $f10, 0xcc($sp)
  lw    $t3, 0x4f0($v0)
  addu  $t7, $t3, $t9
  sw    $t7, 0x4f0($v0)
  lw    $t6, ($s0)
  lw    $t8, 0x4f0($t6)
  slti  $at, $t8, 0x3d
  bnez  $at, .L7F08E660
   lui   $at, %hi(D_80055320)
  jal   sub_GAME_7F08E164
   lwc1  $f12, %lo(D_80055320)($at)
  b     .L7F08E894
   nop   
.L7F08E660:
  lui   $at, %hi(D_80055324)
  jal   sub_GAME_7F08E164
   lwc1  $f12, %lo(D_80055324)($at)
  b     .L7F08E894
   nop   
  lwc1  $f16, 0x6f0($v0)
.L7F08E678:
  lui   $at, %hi(D_80055328)
  lwc1  $f12, %lo(D_80055328)($at)
  swc1  $f16, 0xd0($sp)
  lwc1  $f18, 0x6f4($v0)
  swc1  $f18, 0xd4($sp)
  lwc1  $f4, 0x6f8($v0)
  swc1  $f4, 0xd8($sp)
  lwc1  $f6, 0x6e0($v0)
  swc1  $f6, 0xc4($sp)
  lwc1  $f8, 0x6e4($v0)
  swc1  $f8, 0xc8($sp)
  lwc1  $f10, 0x6e8($v0)
  jal   sub_GAME_7F08E164
   swc1  $f10, 0xcc($sp)
  b     .L7F08E894
   nop   
  lw    $v0, ($s0)
.L7F08E6BC:
  lui   $at, %hi(D_8005532C)
  lwc1  $f16, 0x554($v0)
  swc1  $f16, 0x544($v0)
  lw    $v0, ($s0)
  lwc1  $f18, 0x558($v0)
  swc1  $f18, 0x548($v0)
  lw    $v0, ($s0)
  lwc1  $f4, 0x55c($v0)
  swc1  $f4, 0x54c($v0)
  lw    $v0, ($s0)
  swc1  $f0, 0xdc($sp)
  lwc1  $f6, 0x550($v0)
  swc1  $f0, 0xe4($sp)
  swc1  $f6, 0xe0($sp)
  sw    $zero, 0x4f0($v0)
  jal   sub_GAME_7F08E164
   lwc1  $f12, %lo(D_8005532C)($at)
  jal   get_BONDdata_bondfadefracnew
   nop   
  lui   $at, %hi(D_80055330)
  lwc1  $f8, %lo(D_80055330)($at)
  lui   $at, %hi(D_80055334)
  lwc1  $f10, %lo(D_80055334)($at)
  lui   $v1, %hi(global_timer_delta)
  addiu $v1, %lo(global_timer_delta) # addiu $v1, $v1, -0x7c88
  mul.s $f16, $f10, $f0
  lwc1  $f4, ($v1)
  lw    $v0, ($s0)
  li    $at, 0x3F800000 # 1.000000
  lwc1  $f10, 0x560($v0)
  add.s $f18, $f8, $f16
  mtc1  $at, $f16
  mul.s $f6, $f18, $f4
  add.s $f8, $f10, $f6
  swc1  $f8, 0x560($v0)
  lw    $v0, ($s0)
  lwc1  $f2, 0x560($v0)
  c.le.s $f16, $f2
  nop   
  bc1fl .L7F08E78C
   lw    $v1, 0x594($v0)
  jal   sub_GAME_7F08DBC8
   nop   
  lw    $v0, ($s0)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  lwc1  $f18, 0x560($v0)
  sub.s $f10, $f18, $f4
  swc1  $f10, 0x560($v0)
  lw    $v0, ($s0)
  lwc1  $f2, 0x560($v0)
  lw    $v1, 0x594($v0)
.L7F08E78C:
  mfc1  $a2, $f2
  addiu $a3, $sp, 0xd0
  sll   $t0, $v1, 2
  subu  $t0, $t0, $v1
  sll   $v1, $t0, 2
  negu  $t4, $v1
  addu  $a1, $v0, $t4
  addu  $a0, $v0, $v1
  addiu $a0, $a0, 0x564
  jal   sub_GAME_7F05AE00
   addiu $a1, $a1, 0x570
  jal   get_BONDdata_bondfadefracnew
   nop   
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  li    $at, 0x40A00000 # 5.000000
  mtc1  $at, $f8
  lwc1  $f4, 0xd0($sp)
  mul.s $f16, $f8, $f0
  add.s $f18, $f6, $f16
  mul.s $f10, $f4, $f18
  jal   get_BONDdata_bondfadefracnew
   swc1  $f10, 0xd0($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  li    $at, 0x40A00000 # 5.000000
  mtc1  $at, $f6
  lwc1  $f18, 0xd4($sp)
  lw    $v0, ($s0)
  mul.s $f16, $f6, $f0
  addiu $a3, $sp, 0xc4
  add.s $f4, $f8, $f16
  mul.s $f10, $f18, $f4
  swc1  $f10, 0xd4($sp)
  lw    $v1, 0x594($v0)
  lw    $a2, 0x560($v0)
  sll   $t2, $v1, 2
  subu  $t2, $t2, $v1
  sll   $v1, $t2, 2
  negu  $t5, $v1
  addu  $a1, $v0, $t5
  addu  $a0, $v0, $v1
  addiu $a0, $a0, 0x57c
  jal   sub_GAME_7F05AE00
   addiu $a1, $a1, 0x588
  jal   get_BONDdata_bondfadefracnew
   nop   
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  li    $at, 0x40A00000 # 5.000000
  mtc1  $at, $f8
  lwc1  $f4, 0xc4($sp)
  mul.s $f16, $f8, $f0
  add.s $f18, $f6, $f16
  mul.s $f10, $f4, $f18
  jal   get_BONDdata_bondfadefracnew
   swc1  $f10, 0xc4($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  li    $at, 0x40A00000 # 5.000000
  mtc1  $at, $f6
  lwc1  $f18, 0xcc($sp)
  mul.s $f16, $f6, $f0
  add.s $f4, $f8, $f16
  mul.s $f10, $f18, $f4
  swc1  $f10, 0xcc($sp)
.L7F08E894:
  jal   sub_GAME_7F08DE48
   addiu $a0, $sp, 0xdc
  addiu $a0, $sp, 0xd0
  jal   sub_GAME_7F08DF44
   addiu $a1, $sp, 0xc4
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0xe8
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F08E8BC
  lui   $a1, %hi(D_80036AD0)
  addiu $a1, %lo(D_80036AD0) # addiu $a1, $a1, 0x6ad0
  lwc1  $f4, 0x24($a1)
  addiu $sp, $sp, -0x30
  sw    $s0, 0x20($sp)
  lui   $s0, %hi(D_80036AD0)
  mul.s $f12, $f12, $f4
  sw    $ra, 0x24($sp)
  addiu $s0, %lo(D_80036AD0) # addiu $s0, $s0, 0x6ad0
  move  $v0, $zero
  li    $v1, 2
.L7F08E8E8:
  lwc1  $f0, 0xc($s0)
  lwc1  $f6, 0x14($s0)
  mul.s $f8, $f0, $f6
  c.le.s $f12, $f8
  nop   
  bc1f  .L7F08EA28
   lui   $t0, %hi(pPlayer) 
  lw    $t0, %lo(pPlayer)($t0)
  lui   $t8, %hi(ptr_animation_table) 
  li    $at, 0x3F000000 # 0.500000
  lw    $a0, 0x4e8($t0)
  beql  $v0, $a0, .L7F08EA00
   div.s $f12, $f12, $f0
  mtc1  $zero, $f14
  bltz  $a0, .L7F08E960
   sll   $t6, $a0, 2
  subu  $t6, $t6, $a0
  sll   $t6, $t6, 3
  addu  $v1, $a1, $t6
  lwc1  $f0, 4($v1)
  lwc1  $f18, 8($v1)
  lwc1  $f10, 0x5c0($t0)
  lwc1  $f2, 4($s0)
  sub.s $f4, $f18, $f0
  lwc1  $f6, 8($s0)
  sub.s $f16, $f10, $f0
  sub.s $f8, $f6, $f2
  div.s $f14, $f16, $f4
  mul.s $f10, $f8, $f14
  add.s $f14, $f10, $f2
.L7F08E960:
  mtc1  $at, $f18
  li    $at, 0x41400000 # 12.000000
  lb    $a2, 0x5bc($t0)
  mtc1  $at, $f16
  lw    $t7, ($s0)
  lw    $t8, %lo(ptr_animation_table)($t8)
  mfc1  $a3, $f14
  swc1  $f12, 0x30($sp)
  sw    $v0, 0x2c($sp)
  addiu $a0, $t0, 0x598
  swc1  $f18, 0x10($sp)
  swc1  $f16, 0x14($sp)
  jal   sub_GAME_7F06FCA8
   addu  $a1, $t7, $t8
  lui   $a0, %hi(pPlayer)
  lw    $a0, %lo(pPlayer)($a0)
  lw    $a1, 4($s0)
  li    $a2, 0
  jal   sub_GAME_7F06FDCC
   addiu $a0, $a0, 0x598
  lui   $a0, %hi(pPlayer)
  lw    $a0, %lo(pPlayer)($a0)
  lw    $a1, 8($s0)
  jal   sub_GAME_7F06FDE8
   addiu $a0, $a0, 0x598
  lui   $a0, %hi(pPlayer)
  lw    $a0, %lo(pPlayer)($a0)
  lui   $a1, %hi(sub_GAME_7F08DBB0) # $a1, 0x7f09
  addiu $a1, %lo(sub_GAME_7F08DBB0) # addiu $a1, $a1, -0x2450
  jal   sub_GAME_7F06FE3C
   addiu $a0, $a0, 0x598
  lui   $t9, %hi(pPlayer) 
  lw    $v0, 0x2c($sp)
  lw    $t9, %lo(pPlayer)($t9)
  lwc1  $f12, 0x30($sp)
  lui   $t0, %hi(pPlayer) 
  sw    $v0, 0x4e8($t9)
  lw    $t0, %lo(pPlayer)($t0)
  lwc1  $f0, 0xc($s0)
  div.s $f12, $f12, $f0
.L7F08EA00:
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f4
  addiu $a0, $t0, 0x598
  li    $a2, 0
  mul.s $f6, $f12, $f4
  mfc1  $a1, $f6
  jal   sub_GAME_7F06FE4C
   nop   
  b     .L7F08EA38
   lw    $ra, 0x24($sp)
.L7F08EA28:
  addiu $v0, $v0, 1
  bne   $v0, $v1, .L7F08E8E8
   addiu $s0, $s0, 0x18
  lw    $ra, 0x24($sp)
.L7F08EA38:
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F08EA48
  li    $at, 0x3F000000 # 0.500000
  mtc1  $a3, $f14
  mtc1  $at, $f4
  addiu $sp, $sp, -0x20
  sw    $a1, 0x24($sp)
  mul.s $f6, $f14, $f4
  mtc1  $a2, $f12
  move  $a1, $a0
  sw    $a0, 0x20($sp)
  lui   $a0, %hi(pPlayer)
  li    $at, 0x41400000 # 12.000000
  mtc1  $at, $f8
  lw    $a0, %lo(pPlayer)($a0)
  sw    $ra, 0x1c($sp)
  mfc1  $a3, $f12
  lw    $a2, 0x24($sp)
  swc1  $f6, 0x10($sp)
  addiu $a0, $a0, 0x598
  jal   sub_GAME_7F06FCA8
   swc1  $f8, 0x14($sp)
  lui   $t7, %hi(pPlayer) 
  lw    $t7, %lo(pPlayer)($t7)
  li    $t6, -1
  sw    $t6, 0x4e8($t7)
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F08EAB8
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f4
  lui   $a0, %hi(pPlayer)
  lw    $a0, %lo(pPlayer)($a0)
  mul.s $f6, $f12, $f4
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  li    $a2, 0
  addiu $a0, $a0, 0x598
  mfc1  $a1, $f6
  jal   sub_GAME_7F06FE4C
   nop   
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80055338
.word 0x3c4cccce /*0.012500001*/
glabel D_8005533C
.word 0x3b888889 /*0.0041666669*/
.text
glabel sub_GAME_7F08EAF8
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  lw    $t7, 0x4e8($t6)
  bltzl $t7, .L7F08EBBC
   mtc1  $zero, $f0
  jal   get_BONDdata_bondfadefracnew
   nop   
  lui   $at, %hi(D_80055338)
  lwc1  $f4, %lo(D_80055338)($at)
  lui   $at, %hi(D_8005533C)
  lwc1  $f8, %lo(D_8005533C)($at)
  mul.s $f6, $f0, $f4
  lui   $a0, %hi(pPlayer)
  lw    $a0, %lo(pPlayer)($a0)
  addiu $a0, $a0, 0x598
  add.s $f2, $f6, $f8
  jal   sub_GAME_7F06F618
   swc1  $f2, 0x1c($sp)
  mtc1  $zero, $f10
  lwc1  $f2, 0x1c($sp)
  lui   $t8, %hi(pPlayer) 
  c.lt.s $f10, $f0
  nop   
  bc1f  .L7F08EBB0
   nop   
  lw    $t8, %lo(pPlayer)($t8)
  lui   $t1, %hi(D_80036AD0) 
  addiu $t1, %lo(D_80036AD0) # addiu $t1, $t1, 0x6ad0
  lw    $t9, 0x4e8($t8)
  sll   $t0, $t9, 2
  subu  $t0, $t0, $t9
  sll   $t0, $t0, 3
  addu  $v0, $t0, $t1
  lwc1  $f16, 8($v0)
  lwc1  $f18, 4($v0)
  sub.s $f4, $f16, $f18
  div.s $f12, $f0, $f4
  c.lt.s $f12, $f2
  nop   
  bc1f  .L7F08EBA8
   nop   
  mov.s $f12, $f2
.L7F08EBA8:
  b     .L7F08EBC0
   mov.s $f0, $f12
.L7F08EBB0:
  b     .L7F08EBC0
   mov.s $f0, $f2
  mtc1  $zero, $f0
.L7F08EBBC:
  nop   
.L7F08EBC0:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F08EBD0
  lui   $v0, %hi(ptr_setup_path_tbl)
  lw    $v0, %lo(ptr_setup_path_tbl)($v0)
  addiu $sp, $sp, -0x10
  sdc1  $f20, 8($sp)
  sw    $a1, 0x14($sp)
  move  $a3, $a0
  beqz  $v0, .L7F08EC7C
   move  $v1, $zero
  lw    $t6, ($v0)
  li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f0
  bltz  $t6, .L7F08EC7C
   move  $a0, $v0
  lui   $a2, %hi(ptr_0xxxpresets)
  lwc1  $f12, 8($a3)
  lwc1  $f16, ($a3)
  mtc1  $zero, $f20
  li    $a3, 44
  lw    $a2, %lo(ptr_0xxxpresets)($a2)
  lw    $a1, ($v0)
.L7F08EC20:
  multu $a1, $a3
  c.lt.s $f0, $f20
  mflo  $t7
  addu  $v0, $t7, $a2
  lwc1  $f4, 8($v0)
  lwc1  $f6, ($v0)
  sub.s $f14, $f12, $f4
  sub.s $f18, $f16, $f6
  mul.s $f8, $f14, $f14
  nop   
  mul.s $f10, $f18, $f18
  bc1t  .L7F08EC64
   add.s $f2, $f8, $f10
  c.lt.s $f2, $f0
  nop   
  bc1fl .L7F08EC70
   lw    $a1, 0x10($a0)
.L7F08EC64:
  mov.s $f0, $f2
  move  $v1, $a0
  lw    $a1, 0x10($a0)
.L7F08EC70:
  addiu $a0, $a0, 0x10
  bgez  $a1, .L7F08EC20
   nop   
.L7F08EC7C:
  ldc1  $f20, 8($sp)
  addiu $sp, $sp, 0x10
  jr    $ra
   move  $v0, $v1
");

asm(R"
glabel sub_GAME_7F08EC8C
  sw    $a1, 4($sp)
  lw    $v0, 4($a2)
  move  $a3, $a0
  move  $v1, $a2
  beqz  $v0, .L7F08ED58
   nop   
  lw    $t6, ($a2)
  li    $t2, 44
  lui   $t3, %hi(ptr_setup_path_tbl) 
  multu $t6, $t2
  addiu $t3, %lo(ptr_setup_path_tbl) # addiu $t3, $t3, 0x5d00
  lw    $a1, 0x18($t3)
  lwc1  $f2, 8($a3)
  lwc1  $f14, ($a3)
  lw    $t1, ($v0)
  lw    $t0, ($t3)
  mflo  $t7
  addu  $a0, $t7, $a1
  lwc1  $f4, 8($a0)
  lwc1  $f6, ($a0)
  sub.s $f12, $f2, $f4
  sub.s $f16, $f14, $f6
  mul.s $f8, $f12, $f12
  nop   
  mul.s $f10, $f16, $f16
  bltz  $t1, .L7F08ED58
   add.s $f0, $f8, $f10
  sll   $t8, $t1, 4
.L7F08ECFC:
  addu  $a2, $t8, $t0
  lw    $t9, ($a2)
  multu $t9, $t2
  mflo  $t4
  addu  $a0, $t4, $a1
  lwc1  $f4, 8($a0)
  lwc1  $f6, ($a0)
  sub.s $f12, $f2, $f4
  sub.s $f16, $f14, $f6
  mul.s $f8, $f12, $f12
  nop   
  mul.s $f10, $f16, $f16
  add.s $f18, $f8, $f10
  c.lt.s $f18, $f0
  nop   
  bc1f  .L7F08ED48
   nop   
  mov.s $f0, $f18
  move  $v1, $a2
.L7F08ED48:
  lw    $t1, 4($v0)
  addiu $v0, $v0, 4
  bgezl $t1, .L7F08ECFC
   sll   $t8, $t1, 4
.L7F08ED58:
  jr    $ra
   move  $v0, $v1
");

asm(R"
glabel sub_GAME_7F08ED60
  lw    $v1, ($a0)
  lui   $v0, %hi(ptr_setup_path_link)
  move  $a2, $a1
  bltz  $v1, .L7F08EDA8
   lw    $v0, %lo(ptr_setup_path_link)($v0)
  li    $a3, 12
.L7F08ED78:
  multu $v1, $a3
  mflo  $t6
  addu  $a1, $t6, $v0
  lw    $t7, 8($a1)
  bnel  $a2, $t7, .L7F08ED9C
   lw    $v1, 4($a0)
  jr    $ra
   move  $v0, $a1

  lw    $v1, 4($a0)
.L7F08ED9C:
  addiu $a0, $a0, 4
  bgez  $v1, .L7F08ED78
   nop   
.L7F08EDA8:
  move  $v0, $zero
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F08EDB4
  lw    $v1, ($a0)
  lui   $v0, %hi(ptr_setup_path_link)
  move  $a2, $a1
  bltz  $v1, .L7F08EDF8
   lw    $v0, %lo(ptr_setup_path_link)($v0)
  li    $a3, 12
.L7F08EDCC:
  multu $v1, $a3
  mflo  $t6
  addu  $a1, $t6, $v0
  lw    $t7, 8($a1)
  bgezl $t7, .L7F08EDEC
   lw    $v1, 4($a0)
  sw    $a2, 8($a1)
  lw    $v1, 4($a0)
.L7F08EDEC:
  addiu $a0, $a0, 4
  bgez  $v1, .L7F08EDCC
   nop   
.L7F08EDF8:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F08EE00
  addiu $sp, $sp, -0x28
  sw    $ra, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  lw    $a2, ($a0)
  move  $s0, $a0
  move  $s1, $a1
  beqz  $a2, .L7F08EE54
   move  $s2, $zero
  lw    $t6, 8($s0)
.L7F08EE2C:
  move  $a0, $a2
  addiu $a1, $s1, 1
  bnel  $s1, $t6, .L7F08EE48
   lw    $a2, 0xc($s0)
  jal   sub_GAME_7F08EDB4
   li    $s2, 1
  lw    $a2, 0xc($s0)
.L7F08EE48:
  addiu $s0, $s0, 0xc
  bnezl $a2, .L7F08EE2C
   lw    $t6, 8($s0)
.L7F08EE54:
  lw    $ra, 0x24($sp)
  move  $v0, $s2
  lw    $s2, 0x20($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
glabel sub_GAME_7F08EE70
  addiu $sp, $sp, -0x28
  sw    $ra, 0x24($sp)
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  lw    $t6, ($a2)
  move  $s1, $a2
  move  $s2, $a3
  move  $s3, $a1
  li    $t0, 1
  beqz  $t6, .L7F08EEBC
   move  $v0, $a2
  li    $v1, -1
  lw    $t7, 0xc($v0)
.L7F08EEAC:
  addiu $v0, $v0, 0xc
  sw    $v1, -4($v0)
  bnezl $t7, .L7F08EEAC
   lw    $t7, 0xc($v0)
.L7F08EEBC:
  sw    $zero, 8($a0)
  bnez  $s2, .L7F08EED0
   move  $s0, $zero
  lw    $t8, 8($s3)
  bgez  $t8, .L7F08EEFC
.L7F08EED0:
   move  $a0, $s1
.L7F08EED4:
  jal   sub_GAME_7F08EE00
   move  $a1, $s0
  addiu $s0, $s0, 1
  bnez  $s2, .L7F08EEF4
   move  $t0, $v0
  lw    $t9, 8($s3)
  bgezl $t9, .L7F08EF00
   lw    $ra, 0x24($sp)
.L7F08EEF4:
  bnezl $t0, .L7F08EED4
   move  $a0, $s1
.L7F08EEFC:
  lw    $ra, 0x24($sp)
.L7F08EF00:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   move  $v0, $t0
");

asm(R"
glabel sub_GAME_7F08EF1C
  addiu $sp, $sp, -0x30
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  sw    $a1, 0x34($sp)
  jal   sub_GAME_7F08EE70
   move  $a3, $zero
  lw    $a1, 0x34($sp)
  beqz  $v0, .L7F08EF88
   sw    $v0, 0x24($sp)
  lw    $s0, 8($a1)
  move  $s1, $a1
  addiu $s0, $s0, -1
  bltzl $s0, .L7F08EF80
   lw    $t8, 8($s1)
.L7F08EF58:
  lw    $t6, 8($s1)
  lw    $a0, ($s1)
  move  $a1, $s0
  addiu $t7, $t6, 0x2710
  jal   sub_GAME_7F08ED60
   sw    $t7, 8($s1)
  addiu $s0, $s0, -1
  bgez  $s0, .L7F08EF58
   move  $s1, $v0
  lw    $t8, 8($s1)
.L7F08EF80:
  addiu $t9, $t8, 0x2710
  sw    $t9, 8($s1)
.L7F08EF88:
  lw    $ra, 0x1c($sp)
  lw    $v0, 0x24($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x30
");

asm(R"
glabel sub_GAME_7F08EFA0
  addiu $sp, $sp, -0x30
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s1, 0x1c($sp)
  slti  $at, $a3, 2
  move  $s3, $a3
  move  $s4, $a1
  sw    $ra, 0x2c($sp)
  sw    $s2, 0x20($sp)
  sw    $s0, 0x18($sp)
  sw    $a2, 0x38($sp)
  bnez  $at, .L7F08F058
   move  $s1, $a2
  lui   $a2, %hi(ptr_setup_path_link)
  lw    $a2, %lo(ptr_setup_path_link)($a2)
  beql  $a2, $zero, .L7F08F05C
   sw    $zero, ($s1)
  jal   sub_GAME_7F08EF1C
   sw    $a0, 0x30($sp)
  beqz  $v0, .L7F08F058
   lw    $a0, 0x30($sp)
  lw    $v0, 0x38($sp)
  move  $s2, $a0
  addiu $s3, $s3, 0x270f
  sw    $a0, ($v0)
  lw    $t6, 8($s4)
  li    $s0, 10001
  addiu $s1, $v0, 4
  slti  $at, $t6, 0x2711
  bnez  $at, .L7F08F058
   slti  $at, $s3, 0x2712
  bnezl $at, .L7F08F05C
   sw    $zero, ($s1)
  lw    $a0, ($s2)
.L7F08F028:
  jal   sub_GAME_7F08ED60
   move  $a1, $s0
  sw    $v0, ($s1)
  lw    $t7, 8($s4)
  addiu $s0, $s0, 1
  move  $s2, $v0
  slt   $at, $t7, $s0
  bnez  $at, .L7F08F058
   addiu $s1, $s1, 4
  slt   $at, $s0, $s3
  bnezl $at, .L7F08F028
   lw    $a0, ($s2)
.L7F08F058:
  sw    $zero, ($s1)
.L7F08F05C:
  lw    $t8, 0x38($sp)
  addiu $s1, $s1, 4
  lw    $ra, 0x2c($sp)
  subu  $v0, $s1, $t8
  sra   $t9, $v0, 2
  lw    $s1, 0x1c($sp)
  lw    $s4, 0x28($sp)
  lw    $s3, 0x24($sp)
  lw    $s2, 0x20($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   move  $v0, $t9
");

asm(R"
glabel sub_GAME_7F08F090
  lw    $v1, ($a0)
  lui   $v0, %hi(ptr_setup_path_tbl)
  move  $a3, $a1
  bltz  $v1, .L7F08F0DC
   lw    $v0, %lo(ptr_setup_path_tbl)($v0)
  sll   $t6, $v1, 4
.L7F08F0A8:
  addu  $a1, $t6, $v0
  lw    $t7, 8($a1)
  bnel  $a2, $t7, .L7F08F0D0
   lw    $v1, 4($a0)
  lw    $t8, 0xc($a1)
  bnel  $a3, $t8, .L7F08F0D0
   lw    $v1, 4($a0)
  jr    $ra
   move  $v0, $a1

  lw    $v1, 4($a0)
.L7F08F0D0:
  addiu $a0, $a0, 4
  bgezl $v1, .L7F08F0A8
   sll   $t6, $v1, 4
.L7F08F0DC:
  move  $v0, $zero
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F08F0E8
  lw    $v1, ($a0)
  lui   $v0, %hi(ptr_setup_path_tbl)
  move  $a3, $a1
  bltz  $v1, .L7F08F130
   lw    $v0, %lo(ptr_setup_path_tbl)($v0)
  sll   $t6, $v1, 4
.L7F08F100:
  addu  $a1, $t6, $v0
  lw    $t7, 8($a1)
  bnel  $a2, $t7, .L7F08F124
   lw    $v1, 4($a0)
  lw    $t8, 0xc($a1)
  bgezl $t8, .L7F08F124
   lw    $v1, 4($a0)
  sw    $a3, 0xc($a1)
  lw    $v1, 4($a0)
.L7F08F124:
  addiu $a0, $a0, 4
  bgezl $v1, .L7F08F100
   sll   $t6, $v1, 4
.L7F08F130:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F08F138
  addiu $sp, $sp, -0x30
  sw    $ra, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  lw    $v0, ($a0)
  lui   $s3, %hi(ptr_setup_path_tbl)
  move  $s0, $a0
  move  $s1, $a1
  move  $s4, $a2
  move  $s2, $zero
  bltz  $v0, .L7F08F1B4
   lw    $s3, %lo(ptr_setup_path_tbl)($s3)
  sll   $t6, $v0, 4
.L7F08F178:
  addu  $v1, $t6, $s3
  lw    $t7, 0xc($v1)
  bnel  $s1, $t7, .L7F08F1A8
   lw    $v0, 4($s0)
  lw    $a0, 4($v1)
  addiu $a1, $s1, 1
  move  $a2, $s4
  beql  $a0, $zero, .L7F08F1A8
   lw    $v0, 4($s0)
  jal   sub_GAME_7F08F0E8
   li    $s2, 1
  lw    $v0, 4($s0)
.L7F08F1A8:
  addiu $s0, $s0, 4
  bgezl $v0, .L7F08F178
   sll   $t6, $v0, 4
.L7F08F1B4:
  lw    $ra, 0x2c($sp)
  move  $v0, $s2
  lw    $s2, 0x20($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s3, 0x24($sp)
  lw    $s4, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x30
");

asm(R"
glabel sub_GAME_7F08F1D8
  addiu $sp, $sp, -0x30
  sw    $ra, 0x2c($sp)
  sw    $s5, 0x28($sp)
  sw    $s4, 0x24($sp)
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  lw    $t6, 8($a0)
  li    $s5, 12
  lui   $v0, %hi(ptr_setup_path_tbl)
  multu $t6, $s5
  addiu $v0, %lo(ptr_setup_path_tbl) # addiu $v0, $v0, 0x5d00
  lw    $s1, 4($v0)
  move  $s2, $a0
  move  $s3, $a2
  move  $s4, $a1
  lw    $t0, ($v0)
  li    $a0, -1
  move  $s0, $zero
  mflo  $t7
  addu  $t8, $s1, $t7
  lw    $v1, 4($t8)
  lw    $a3, ($v1)
  bltz  $a3, .L7F08F258
   sll   $t9, $a3, 4
.L7F08F240:
  addu  $v0, $t9, $t0
  sw    $a0, 0xc($v0)
  lw    $a3, 4($v1)
  addiu $v1, $v1, 4
  bgezl $a3, .L7F08F240
   sll   $t9, $a3, 4
.L7F08F258:
  bnez  $s3, .L7F08F26C
   sw    $zero, 0xc($s2)
  lw    $t1, 0xc($s4)
  bgezl $t1, .L7F08F2AC
   lw    $ra, 0x2c($sp)
.L7F08F26C:
  lw    $a2, 8($s2)
.L7F08F270:
  move  $a1, $s0
  multu $a2, $s5
  mflo  $t2
  addu  $t3, $s1, $t2
  jal   sub_GAME_7F08F138
   lw    $a0, 4($t3)
  addiu $s0, $s0, 1
  bnez  $s3, .L7F08F2A0
   move  $v1, $v0
  lw    $t4, 0xc($s4)
  bgezl $t4, .L7F08F2AC
   lw    $ra, 0x2c($sp)
.L7F08F2A0:
  bnezl $v1, .L7F08F270
   lw    $a2, 8($s2)
  lw    $ra, 0x2c($sp)
.L7F08F2AC:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  lw    $s4, 0x24($sp)
  lw    $s5, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x30
");

asm(R"
glabel sub_GAME_7F08F2CC
  addiu $sp, $sp, -0x28
  sw    $ra, 0x24($sp)
  sw    $s2, 0x20($sp)
  move  $s2, $a0
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a1, 0x2c($sp)
  jal   sub_GAME_7F08F1D8
   move  $a2, $zero
  lw    $s1, 0x2c($sp)
  lw    $s0, 0xc($s1)
  addiu $s0, $s0, -1
  bltzl $s0, .L7F08F330
   lw    $t8, 0xc($s1)
.L7F08F304:
  lw    $t6, 0xc($s1)
  lw    $a0, 4($s1)
  move  $a1, $s0
  addiu $t7, $t6, 0x2710
  sw    $t7, 0xc($s1)
  jal   sub_GAME_7F08F090
   lw    $a2, 8($s2)
  addiu $s0, $s0, -1
  bgez  $s0, .L7F08F304
   move  $s1, $v0
  lw    $t8, 0xc($s1)
.L7F08F330:
  addiu $t9, $t8, 0x2710
  sw    $t9, 0xc($s1)
  lw    $ra, 0x24($sp)
  lw    $s2, 0x20($sp)
  lw    $s1, 0x1c($sp)
  lw    $s0, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
glabel sub_GAME_7F08F350
  addiu $sp, $sp, -0x30
  sw    $s5, 0x28($sp)
  sw    $s4, 0x24($sp)
  sw    $s3, 0x20($sp)
  sw    $s1, 0x18($sp)
  slti  $at, $a3, 2
  move  $s3, $a3
  move  $s4, $a0
  move  $s5, $a1
  sw    $ra, 0x2c($sp)
  sw    $s2, 0x1c($sp)
  sw    $s0, 0x14($sp)
  sw    $a2, 0x38($sp)
  bnez  $at, .L7F08F3FC
   move  $s1, $a2
  jal   sub_GAME_7F08F2CC
   nop   
  lw    $v0, 0x38($sp)
  move  $s2, $s4
  addiu $s3, $s3, 0x270f
  sw    $s4, ($v0)
  lw    $t6, 0xc($s5)
  li    $s0, 10001
  addiu $s1, $v0, 4
  slti  $at, $t6, 0x2711
  bnez  $at, .L7F08F3FC
   slti  $at, $s3, 0x2712
  bnezl $at, .L7F08F400
   sw    $zero, ($s1)
  lw    $a0, 4($s2)
.L7F08F3C8:
  move  $a1, $s0
  jal   sub_GAME_7F08F090
   lw    $a2, 8($s4)
  sw    $v0, ($s1)
  lw    $t7, 0xc($s5)
  addiu $s0, $s0, 1
  move  $s2, $v0
  slt   $at, $t7, $s0
  bnez  $at, .L7F08F3FC
   addiu $s1, $s1, 4
  slt   $at, $s0, $s3
  bnezl $at, .L7F08F3C8
   lw    $a0, 4($s2)
.L7F08F3FC:
  sw    $zero, ($s1)
.L7F08F400:
  lw    $t8, 0x38($sp)
  addiu $s1, $s1, 4
  lw    $ra, 0x2c($sp)
  subu  $v0, $s1, $t8
  sra   $t9, $v0, 2
  lw    $s1, 0x18($sp)
  lw    $s5, 0x28($sp)
  lw    $s4, 0x24($sp)
  lw    $s3, 0x20($sp)
  lw    $s2, 0x1c($sp)
  lw    $s0, 0x14($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   move  $v0, $t9
");

asm(R"
glabel sub_GAME_7F08F438
  addiu $sp, $sp, -8
  sw    $s0, 4($sp)
  sw    $a2, 0x10($sp)
  sw    $a3, 0x14($sp)
  lw    $t0, 4($a0)
  lui   $t2, %hi(ptr_setup_path_tbl) 
  addiu $t2, %lo(ptr_setup_path_tbl) # addiu $t2, $t2, 0x5d00
  lw    $t1, ($t0)
  move  $s0, $a1
  lw    $v0, ($t2)
  bltz  $t1, .L7F08F4D4
   lw    $v1, 4($t2)
  li    $t2, 12
  sll   $t6, $t1, 4
.L7F08F470:
  addu  $a0, $t6, $v0
  lw    $a1, 4($a0)
  lw    $a2, ($a1)
  bltz  $a2, .L7F08F4C4
   sll   $t7, $a2, 4
.L7F08F484:
  addu  $a3, $t7, $v0
  lw    $t8, 8($a3)
  multu $t8, $t2
  mflo  $t9
  addu  $t3, $t9, $v1
  bnel  $s0, $t3, .L7F08F4B8
   lw    $a2, 4($a1)
  lw    $t4, 0x10($sp)
  sw    $a0, ($t4)
  lw    $t5, 0x14($sp)
  b     .L7F08F4E4
   sw    $a3, ($t5)
  lw    $a2, 4($a1)
.L7F08F4B8:
  addiu $a1, $a1, 4
  bgezl $a2, .L7F08F484
   sll   $t7, $a2, 4
.L7F08F4C4:
  lw    $t1, 4($t0)
  addiu $t0, $t0, 4
  bgezl $t1, .L7F08F470
   sll   $t6, $t1, 4
.L7F08F4D4:
  lw    $t6, 0x14($sp)
  sw    $zero, ($t6)
  lw    $t7, 0x10($sp)
  sw    $zero, ($t7)
.L7F08F4E4:
  lw    $s0, 4($sp)
  jr    $ra
   addiu $sp, $sp, 8
");

asm(R"
glabel sub_GAME_7F08F4F0
  addiu $sp, $sp, -0x70
  sw    $s0, 0x18($sp)
  lui   $s0, %hi(ptr_setup_path_link)
  lw    $s0, %lo(ptr_setup_path_link)($s0)
  sw    $s6, 0x30($sp)
  sw    $s4, 0x28($sp)
  sw    $s1, 0x1c($sp)
  move  $s1, $a3
  move  $s6, $a0
  sw    $ra, 0x3c($sp)
  sw    $fp, 0x38($sp)
  sw    $s7, 0x34($sp)
  sw    $s5, 0x2c($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $a1, 0x74($sp)
  sw    $a2, 0x78($sp)
  beqz  $s0, .L7F08F634
   move  $s4, $a2
  lw    $t6, 8($a0)
  li    $v0, 12
  lw    $t9, 8($a1)
  multu $t6, $v0
  move  $a2, $s0
  mflo  $t7
  addu  $s3, $t7, $s0
  move  $a0, $s3
  multu $t9, $v0
  mflo  $t0
  addu  $fp, $t0, $s0
  jal   sub_GAME_7F08EF1C
   move  $a1, $fp
  beql  $v0, $zero, .L7F08F638
   sw    $zero, ($s4)
  lw    $s0, 8($s3)
  lw    $t1, 8($fp)
  move  $s5, $s6
  addiu $s0, $s0, 1
  slt   $at, $t1, $s0
  bnez  $at, .L7F08F614
   move  $s2, $s3
  slti  $at, $s1, 2
  bnez  $at, .L7F08F614
   addiu $s7, $sp, 0x44
  addiu $s6, $sp, 0x48
  lw    $a0, ($s2)
.L7F08F5A8:
  jal   sub_GAME_7F08ED60
   move  $a1, $s0
  move  $s3, $v0
  move  $a0, $s2
  move  $a1, $v0
  move  $a2, $s6
  jal   sub_GAME_7F08F438
   move  $a3, $s7
  move  $a0, $s5
  lw    $a1, 0x48($sp)
  move  $a2, $s4
  jal   sub_GAME_7F08F350
   move  $a3, $s1
  lw    $t4, 8($fp)
  addiu $s0, $s0, 1
  addiu $t2, $v0, -1
  subu  $s1, $s1, $v0
  sll   $t3, $t2, 2
  slt   $at, $t4, $s0
  addiu $s1, $s1, 1
  addu  $s4, $s4, $t3
  lw    $s5, 0x44($sp)
  bnez  $at, .L7F08F614
   move  $s2, $s3
  slti  $at, $s1, 2
  beql  $at, $zero, .L7F08F5A8
   lw    $a0, ($s2)
.L7F08F614:
  move  $a0, $s5
  lw    $a1, 0x74($sp)
  move  $a2, $s4
  jal   sub_GAME_7F08F350
   move  $a3, $s1
  addiu $t5, $v0, -1
  sll   $t6, $t5, 2
  addu  $s4, $s4, $t6
.L7F08F634:
  sw    $zero, ($s4)
.L7F08F638:
  lw    $t7, 0x78($sp)
  addiu $s4, $s4, 4
  lw    $ra, 0x3c($sp)
  subu  $v0, $s4, $t7
  sra   $t8, $v0, 2
  lw    $s4, 0x28($sp)
  lw    $fp, 0x38($sp)
  lw    $s7, 0x34($sp)
  lw    $s6, 0x30($sp)
  lw    $s5, 0x2c($sp)
  lw    $s3, 0x24($sp)
  lw    $s2, 0x20($sp)
  lw    $s1, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x70
  jr    $ra
   move  $v0, $t8
");

asm(R"
glabel sub_GAME_7F08F67C
  lui   $v0, %hi(ptr_setup_path_tbl)
  lw    $v0, %lo(ptr_setup_path_tbl)($v0)
  li    $v1, -1
  lw    $t6, ($v0)
  bltz  $t6, .L7F08F6A8
   nop   
  lw    $t7, 0x10($v0)
.L7F08F698:
  sw    $v1, 0xc($v0)
  addiu $v0, $v0, 0x10
  bgezl $t7, .L7F08F698
   lw    $t7, 0x10($v0)
.L7F08F6A8:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F08F6B0
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  lw    $t6, ($a0)
  move  $a3, $a1
  move  $t1, $zero
  bltz  $t6, .L7F08F6E0
   move  $v0, $a0
  lw    $t7, 4($v0)
.L7F08F6D0:
  addiu $t1, $t1, 1
  addiu $v0, $v0, 4
  bgezl $t7, .L7F08F6D0
   lw    $t7, 4($v0)
.L7F08F6E0:
  sw    $a0, 0x20($sp)
  sw    $a3, 0x24($sp)
  jal   get_random_value
   sw    $t1, 0x1c($sp)
  lw    $t1, 0x1c($sp)
  lw    $a3, 0x24($sp)
  lw    $t4, 0x20($sp)
  divu  $zero, $v0, $t1
  mfhi  $t3
  slt   $at, $t3, $t1
  bnez  $t1, .L7F08F714
   nop   
  break 7
.L7F08F714:
  move  $t2, $t3
  beqz  $at, .L7F08F80C
   move  $a2, $t3
  subu  $v1, $t1, $t3
  andi  $t8, $v1, 3
  beqz  $t8, .L7F08F770
   addu  $t0, $t8, $t3
  sll   $t9, $a2, 2
  lui   $a1, %hi(ptr_setup_path_tbl)
  lw    $a1, %lo(ptr_setup_path_tbl)($a1)
  addu  $v0, $t4, $t9
.L7F08F740:
  lw    $t5, ($v0)
  addiu $a2, $a2, 1
  sll   $t6, $t5, 4
  addu  $a0, $t6, $a1
  lw    $t7, 0xc($a0)
  bne   $a3, $t7, .L7F08F764
   nop   
  b     .L7F08F8F8
   move  $v0, $a0
.L7F08F764:
  bne   $t0, $a2, .L7F08F740
   addiu $v0, $v0, 4
  beq   $a2, $t1, .L7F08F80C
.L7F08F770:
   sll   $t8, $a2, 2
  lui   $a1, %hi(ptr_setup_path_tbl)
  lw    $a1, %lo(ptr_setup_path_tbl)($a1)
  addu  $v0, $t4, $t8
.L7F08F780:
  lw    $t9, ($v0)
  addiu $a2, $a2, 4
  sll   $t5, $t9, 4
  addu  $a0, $t5, $a1
  lw    $t6, 0xc($a0)
  bnel  $a3, $t6, .L7F08F7A8
   lw    $t7, 4($v0)
  b     .L7F08F8F8
   move  $v0, $a0
  lw    $t7, 4($v0)
.L7F08F7A8:
  sll   $t8, $t7, 4
  addu  $v1, $t8, $a1
  lw    $t9, 0xc($v1)
  bnel  $a3, $t9, .L7F08F7C8
   lw    $t5, 8($v0)
  b     .L7F08F8F8
   move  $v0, $v1
  lw    $t5, 8($v0)
.L7F08F7C8:
  sll   $t6, $t5, 4
  addu  $v1, $t6, $a1
  lw    $t7, 0xc($v1)
  bnel  $a3, $t7, .L7F08F7E8
   lw    $t8, 0xc($v0)
  b     .L7F08F8F8
   move  $v0, $v1
  lw    $t8, 0xc($v0)
.L7F08F7E8:
  sll   $t9, $t8, 4
  addu  $v1, $t9, $a1
  lw    $t5, 0xc($v1)
  bne   $a3, $t5, .L7F08F804
   nop   
  b     .L7F08F8F8
   move  $v0, $v1
.L7F08F804:
  bne   $a2, $t1, .L7F08F780
   addiu $v0, $v0, 0x10
.L7F08F80C:
  blez  $t3, .L7F08F8F4
   move  $a2, $zero
  lui   $a1, %hi(ptr_setup_path_tbl)
  andi  $v1, $t3, 3
  beqz  $v1, .L7F08F860
   lw    $a1, %lo(ptr_setup_path_tbl)($a1)
  sll   $t6, $zero, 2
  addu  $v0, $t4, $t6
  move  $t0, $v1
.L7F08F830:
  lw    $t7, ($v0)
  addiu $a2, $a2, 1
  sll   $t8, $t7, 4
  addu  $a0, $t8, $a1
  lw    $t9, 0xc($a0)
  bne   $a3, $t9, .L7F08F854
   nop   
  b     .L7F08F8F8
   move  $v0, $a0
.L7F08F854:
  bne   $t0, $a2, .L7F08F830
   addiu $v0, $v0, 4
  beq   $a2, $t3, .L7F08F8F4
.L7F08F860:
   sll   $t5, $a2, 2
  addu  $v0, $t4, $t5
.L7F08F868:
  lw    $t6, ($v0)
  addiu $a2, $a2, 4
  sll   $t7, $t6, 4
  addu  $a0, $t7, $a1
  lw    $t8, 0xc($a0)
  bnel  $a3, $t8, .L7F08F890
   lw    $t9, 4($v0)
  b     .L7F08F8F8
   move  $v0, $a0
  lw    $t9, 4($v0)
.L7F08F890:
  sll   $t5, $t9, 4
  addu  $v1, $t5, $a1
  lw    $t6, 0xc($v1)
  bnel  $a3, $t6, .L7F08F8B0
   lw    $t7, 8($v0)
  b     .L7F08F8F8
   move  $v0, $v1
  lw    $t7, 8($v0)
.L7F08F8B0:
  sll   $t8, $t7, 4
  addu  $v1, $t8, $a1
  lw    $t9, 0xc($v1)
  bnel  $a3, $t9, .L7F08F8D0
   lw    $t5, 0xc($v0)
  b     .L7F08F8F8
   move  $v0, $v1
  lw    $t5, 0xc($v0)
.L7F08F8D0:
  sll   $t6, $t5, 4
  addu  $v1, $t6, $a1
  lw    $t7, 0xc($v1)
  bne   $a3, $t7, .L7F08F8EC
   nop   
  b     .L7F08F8F8
   move  $v0, $v1
.L7F08F8EC:
  bne   $a2, $t2, .L7F08F868
   addiu $v0, $v0, 0x10
.L7F08F8F4:
  move  $v0, $zero
.L7F08F8F8:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F08F908
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  lw    $t6, ($a0)
  move  $s0, $a1
  move  $t1, $zero
  bltz  $t6, .L7F08F93C
   move  $v0, $a0
  lw    $t7, 4($v0)
.L7F08F92C:
  addiu $t1, $t1, 1
  addiu $v0, $v0, 4
  bgezl $t7, .L7F08F92C
   lw    $t7, 4($v0)
.L7F08F93C:
  sw    $a0, 0x28($sp)
  jal   get_random_value
   sw    $t1, 0x24($sp)
  lw    $t1, 0x24($sp)
  lw    $t4, 0x28($sp)
  lw    $ra, 0x1c($sp)
  divu  $zero, $v0, $t1
  mfhi  $t3
  slt   $at, $t3, $t1
  bnez  $t1, .L7F08F96C
   nop   
  break 7
.L7F08F96C:
  move  $t2, $t3
  beqz  $at, .L7F08FA80
   move  $a2, $t3
  subu  $v1, $t1, $t3
  andi  $t8, $v1, 3
  beqz  $t8, .L7F08F9D0
   addu  $t0, $t8, $t3
  sll   $t9, $a2, 2
  lui   $a1, %hi(ptr_setup_path_link)
  lw    $a1, %lo(ptr_setup_path_link)($a1)
  addu  $v0, $t4, $t9
  li    $a3, 12
.L7F08F99C:
  lw    $t5, ($v0)
  addiu $a2, $a2, 1
  multu $t5, $a3
  mflo  $t6
  addu  $a0, $t6, $a1
  lw    $t7, 8($a0)
  bne   $s0, $t7, .L7F08F9C4
   nop   
  b     .L7F08FB84
   move  $v0, $a0
.L7F08F9C4:
  bne   $t0, $a2, .L7F08F99C
   addiu $v0, $v0, 4
  beq   $a2, $t1, .L7F08FA80
.L7F08F9D0:
   sll   $t8, $a2, 2
  lui   $a1, %hi(ptr_setup_path_link)
  lw    $a1, %lo(ptr_setup_path_link)($a1)
  addu  $v0, $t4, $t8
  li    $a3, 12
.L7F08F9E4:
  lw    $t9, ($v0)
  addiu $a2, $a2, 4
  multu $t9, $a3
  mflo  $t5
  addu  $a0, $t5, $a1
  lw    $t6, 8($a0)
  bnel  $s0, $t6, .L7F08FA10
   lw    $t7, 4($v0)
  b     .L7F08FB84
   move  $v0, $a0
  lw    $t7, 4($v0)
.L7F08FA10:
  multu $t7, $a3
  mflo  $t8
  addu  $v1, $t8, $a1
  lw    $t9, 8($v1)
  bnel  $s0, $t9, .L7F08FA34
   lw    $t5, 8($v0)
  b     .L7F08FB84
   move  $v0, $v1
  lw    $t5, 8($v0)
.L7F08FA34:
  multu $t5, $a3
  mflo  $t6
  addu  $v1, $t6, $a1
  lw    $t7, 8($v1)
  bnel  $s0, $t7, .L7F08FA58
   lw    $t8, 0xc($v0)
  b     .L7F08FB84
   move  $v0, $v1
  lw    $t8, 0xc($v0)
.L7F08FA58:
  multu $t8, $a3
  mflo  $t9
  addu  $v1, $t9, $a1
  lw    $t5, 8($v1)
  bne   $s0, $t5, .L7F08FA78
   nop   
  b     .L7F08FB84
   move  $v0, $v1
.L7F08FA78:
  bne   $a2, $t1, .L7F08F9E4
   addiu $v0, $v0, 0x10
.L7F08FA80:
  li    $a3, 12
  blez  $t3, .L7F08FB80
   move  $a2, $zero
  lui   $a1, %hi(ptr_setup_path_link)
  andi  $v1, $t3, 3
  beqz  $v1, .L7F08FADC
   lw    $a1, %lo(ptr_setup_path_link)($a1)
  sll   $t6, $zero, 2
  addu  $v0, $t4, $t6
  move  $t0, $v1
.L7F08FAA8:
  lw    $t7, ($v0)
  addiu $a2, $a2, 1
  multu $t7, $a3
  mflo  $t8
  addu  $a0, $t8, $a1
  lw    $t9, 8($a0)
  bne   $s0, $t9, .L7F08FAD0
   nop   
  b     .L7F08FB84
   move  $v0, $a0
.L7F08FAD0:
  bne   $t0, $a2, .L7F08FAA8
   addiu $v0, $v0, 4
  beq   $a2, $t3, .L7F08FB80
.L7F08FADC:
   sll   $t5, $a2, 2
  addu  $v0, $t4, $t5
.L7F08FAE4:
  lw    $t6, ($v0)
  addiu $a2, $a2, 4
  multu $t6, $a3
  mflo  $t7
  addu  $a0, $t7, $a1
  lw    $t8, 8($a0)
  bnel  $s0, $t8, .L7F08FB10
   lw    $t9, 4($v0)
  b     .L7F08FB84
   move  $v0, $a0
  lw    $t9, 4($v0)
.L7F08FB10:
  multu $t9, $a3
  mflo  $t5
  addu  $v1, $t5, $a1
  lw    $t6, 8($v1)
  bnel  $s0, $t6, .L7F08FB34
   lw    $t7, 8($v0)
  b     .L7F08FB84
   move  $v0, $v1
  lw    $t7, 8($v0)
.L7F08FB34:
  multu $t7, $a3
  mflo  $t8
  addu  $v1, $t8, $a1
  lw    $t9, 8($v1)
  bnel  $s0, $t9, .L7F08FB58
   lw    $t5, 0xc($v0)
  b     .L7F08FB84
   move  $v0, $v1
  lw    $t5, 0xc($v0)
.L7F08FB58:
  multu $t5, $a3
  mflo  $t6
  addu  $v1, $t6, $a1
  lw    $t7, 8($v1)
  bne   $s0, $t7, .L7F08FB78
   nop   
  b     .L7F08FB84
   move  $v0, $v1
.L7F08FB78:
  bne   $a2, $t2, .L7F08FAE4
   addiu $v0, $v0, 0x10
.L7F08FB80:
  move  $v0, $zero
.L7F08FB84:
  lw    $s0, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
glabel sub_GAME_7F08FB90
  lui   $a2, %hi(ptr_setup_path_link)
  lw    $a2, %lo(ptr_setup_path_link)($a2)
  addiu $sp, $sp, -0x58
  sw    $s1, 0x18($sp)
  move  $s1, $a0
  sw    $ra, 0x1c($sp)
  beqz  $a2, .L7F08FD04
   sw    $s0, 0x14($sp)
  lw    $t6, 8($a0)
  li    $v0, 12
  lw    $t8, 8($a1)
  multu $t6, $v0
  move  $a3, $zero
  mflo  $t7
  addu  $s0, $t7, $a2
  nop   
  multu $t8, $v0
  mflo  $t9
  addu  $a0, $t9, $a2
  bne   $s0, $a0, .L7F08FC38
   nop   
  jal   sub_GAME_7F08F67C
   sw    $a1, 0x5c($sp)
  lw    $a0, 0x5c($sp)
  move  $a1, $s1
  jal   sub_GAME_7F08F1D8
   li    $a2, 1
  lw    $a0, 4($s1)
  jal   sub_GAME_7F08F6B0
   li    $a1, -1
  beql  $v0, $zero, .L7F08FC1C
   lw    $a1, 0xc($s1)
  b     .L7F08FD0C
   lw    $ra, 0x1c($sp)
  lw    $a1, 0xc($s1)
.L7F08FC1C:
  lw    $a0, 4($s1)
  jal   sub_GAME_7F08F6B0
   addiu $a1, $a1, 1
  beql  $v0, $zero, .L7F08FD08
   move  $v0, $zero
  b     .L7F08FD0C
   lw    $ra, 0x1c($sp)
.L7F08FC38:
  jal   sub_GAME_7F08EE70
   move  $a1, $s0
  lw    $t0, 8($s0)
  li    $a1, -1
  bltzl $t0, .L7F08FD08
   move  $v0, $zero
  jal   sub_GAME_7F08F908
   lw    $a0, ($s0)
  beqz  $v0, .L7F08FCA8
   move  $a1, $v0
  move  $a0, $s0
  addiu $a2, $sp, 0x40
  jal   sub_GAME_7F08F438
   addiu $a3, $sp, 0x3c
  lw    $a1, 0x40($sp)
  move  $a0, $s1
  addiu $a2, $sp, 0x30
  bne   $a1, $s1, .L7F08FC8C
   nop   
  b     .L7F08FD08
   lw    $v0, 0x3c($sp)
.L7F08FC8C:
  jal   sub_GAME_7F08F350
   li    $a3, 3
  slti  $at, $v0, 3
  bnezl $at, .L7F08FD08
   move  $v0, $zero
  b     .L7F08FD08
   lw    $v0, 0x34($sp)
.L7F08FCA8:
  lw    $a1, 8($s0)
  lw    $a0, ($s0)
  jal   sub_GAME_7F08ED60
   addiu $a1, $a1, -1
  beqz  $v0, .L7F08FD04
   move  $a1, $v0
  move  $a0, $s0
  addiu $a2, $sp, 0x28
  jal   sub_GAME_7F08F438
   addiu $a3, $sp, 0x24
  lw    $a0, 0x28($sp)
  move  $a1, $s1
  jal   sub_GAME_7F08F1D8
   li    $a2, 1
  lw    $a1, 0xc($s1)
  lw    $a0, 4($s1)
  lw    $a2, 8($s1)
  jal   sub_GAME_7F08F090
   addiu $a1, $a1, 1
  beql  $v0, $zero, .L7F08FD08
   move  $v0, $zero
  b     .L7F08FD0C
   lw    $ra, 0x1c($sp)
.L7F08FD04:
  move  $v0, $zero
.L7F08FD08:
  lw    $ra, 0x1c($sp)
.L7F08FD0C:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x58
");

asm(R"
glabel sub_GAME_7F08FD1C
  lui   $t0, %hi(ptr_setup_path_tbl) 
  lw    $t0, %lo(ptr_setup_path_tbl)($t0)
  addiu $sp, $sp, -0xf8
  sw    $ra, 0x14($sp)
  beql  $t0, $zero, .L7F08FDEC
   lw    $ra, 0x14($sp)
  lw    $t6, ($t0)
  move  $v1, $zero
  move  $v0, $t0
  bltzl $t6, .L7F08FD60
   sw    $v1, 0xf0($sp)
  lw    $t7, 0x10($v0)
.L7F08FD4C:
  addiu $v0, $v0, 0x10
  addiu $v1, $v1, 1
  bgezl $t7, .L7F08FD4C
   lw    $t7, 0x10($v0)
  sw    $v1, 0xf0($sp)
.L7F08FD60:
  jal   get_random_value
   sw    $t0, 0xf4($sp)
  lw    $v1, 0xf0($sp)
  lw    $t0, 0xf4($sp)
  divu  $zero, $v0, $v1
  mfhi  $t8
  sll   $t9, $t8, 4
  bnez  $v1, .L7F08FD88
   nop   
  break 7
.L7F08FD88:
  addu  $t1, $t9, $t0
  jal   get_random_value
   sw    $t1, 0xe8($sp)
  lw    $v1, 0xf0($sp)
  lw    $t0, 0xf4($sp)
  lw    $a0, 0xe8($sp)
  divu  $zero, $v0, $v1
  mfhi  $t2
  sll   $t3, $t2, 4
  bnez  $v1, .L7F08FDB8
   nop   
  break 7
.L7F08FDB8:
  addiu $a2, $sp, 0x1c
  li    $a3, 50
  jal   sub_GAME_7F08F4F0
   addu  $a1, $t3, $t0
  beqz  $v0, .L7F08FDE8
   lw    $t4, 0x1c($sp)
  beqz  $t4, .L7F08FDE8
   addiu $v0, $sp, 0x1c
  lw    $t5, 4($v0)
.L7F08FDDC:
  addiu $v0, $v0, 4
  bnezl $t5, .L7F08FDDC
   lw    $t5, 4($v0)
.L7F08FDE8:
  lw    $ra, 0x14($sp)
.L7F08FDEC:
  addiu $sp, $sp, 0xf8
  jr    $ra
   nop   
");
