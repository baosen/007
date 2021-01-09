unsigned int dword_CODE_bss_8007A160;
unsigned int dword_CODE_bss_8007A164;
unsigned int dword_CODE_bss_8007A168;
unsigned int dword_CODE_bss_8007A16C;
unsigned char dword_CODE_bss_8007A170[0x370];
unsigned char dword_CODE_bss_8007A4E0[0xBB8];
unsigned char dword_CODE_bss_8007B098[8];

unsigned int D_80040940[8] = {0};

unsigned int D_80040960[] = {0xFFFFFFFF, 0xFFFFC8FF, 0xFF0000FF, 0xFFFFFFFF,
                             0xFFFFFFFF, 0xFFFFFFFF, 0,          0};

unsigned int D_80040980 = 0;
unsigned int D_80040984 = 0;
unsigned int D_80040988 = 0;
unsigned int D_8004098C = 0;
unsigned int D_80040990 = 0;
unsigned int D_80040994 = 0;
unsigned int D_80040998 = 0;
unsigned int D_8004099C = 0;

asm(R"
.late_rodata
glabel D_80057710
.word 0x3dcccccd /*0.1*/
glabel D_80057714
.word 0x3f333333 /*0.69999999*/
.text
glabel sub_GAME_7F0A1DA0
  addiu $sp, $sp, -0xe0
  sw    $ra, 0x5c($sp)
  sw    $s5, 0x58($sp)
  sw    $s4, 0x54($sp)
  sw    $s3, 0x50($sp)
  sw    $s2, 0x4c($sp)
  sw    $s1, 0x48($sp)
  sw    $s0, 0x44($sp)
  sdc1  $f30, 0x38($sp)
  sdc1  $f28, 0x30($sp)
  sdc1  $f26, 0x28($sp)
  sdc1  $f24, 0x20($sp)
  sdc1  $f22, 0x18($sp)
  sdc1  $f20, 0x10($sp)
  lwc1  $f4, ($a1)
  move  $s0, $a2
  move  $s1, $a0
  swc1  $f4, 0x90($sp)
  lwc1  $f6, 4($a1)
  lwc1  $f10, 0x90($sp)
  move  $s2, $a3
  swc1  $f6, 0x94($sp)
  mul.s $f16, $f10, $f10
  lwc1  $f8, 8($a1)
  lwc1  $f18, 0x94($sp)
  swc1  $f8, 0x98($sp)
  mul.s $f4, $f18, $f18
  lwc1  $f8, 0x98($sp)
  mul.s $f10, $f8, $f8
  add.s $f6, $f16, $f4
  jal   sqrtf
   add.s $f12, $f10, $f6
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f26
  lwc1  $f18, 0x90($sp)
  lwc1  $f4, 0x94($sp)
  div.s $f20, $f26, $f0
  lwc1  $f10, 0x98($sp)
  lwc1  $f22, 0xf0($sp)
  lwc1  $f28, 0xf4($sp)
  mul.s $f16, $f18, $f20
  nop   
  mul.s $f8, $f4, $f20
  nop   
  mul.s $f6, $f10, $f20
  swc1  $f16, 0x90($sp)
  mul.s $f22, $f22, $f0
  swc1  $f8, 0x94($sp)
  mul.s $f28, $f28, $f0
  swc1  $f6, 0x98($sp)
  lwc1  $f18, ($s0)
  swc1  $f18, 0x84($sp)
  lwc1  $f16, 4($s0)
  lwc1  $f8, 0x84($sp)
  swc1  $f16, 0x88($sp)
  mul.s $f10, $f8, $f8
  lwc1  $f4, 8($s0)
  lwc1  $f6, 0x88($sp)
  swc1  $f4, 0x8c($sp)
  mul.s $f18, $f6, $f6
  lwc1  $f4, 0x8c($sp)
  mul.s $f8, $f4, $f4
  add.s $f16, $f10, $f18
  jal   sqrtf
   add.s $f12, $f8, $f16
  div.s $f20, $f26, $f0
  lwc1  $f6, 0x84($sp)
  lwc1  $f18, 0x88($sp)
  lwc1  $f8, 0x8c($sp)
  lwc1  $f24, 0xf8($sp)
  mul.s $f10, $f6, $f20
  lwc1  $f6, 0xfc($sp)
  mul.s $f4, $f18, $f20
  nop   
  mul.s $f16, $f8, $f20
  swc1  $f10, 0x84($sp)
  mul.s $f24, $f24, $f0
  swc1  $f4, 0x88($sp)
  mul.s $f10, $f6, $f0
  swc1  $f16, 0x8c($sp)
  swc1  $f10, 0xfc($sp)
  lwc1  $f14, 8($s2)
  jal   convert_angle_using_inverse
   lwc1  $f12, ($s2)
  lwc1  $f18, 0xfc($sp)
  lui   $t6, %hi(dword_CODE_bss_8007A160) 
  lw    $t6, %lo(dword_CODE_bss_8007A160)($t6)
  sub.s $f20, $f28, $f22
  mov.s $f30, $f0
  sub.s $f26, $f18, $f24
  mul.s $f4, $f20, $f26
  bgez  $t6, .L7F0A1F1C
   sra   $t7, $t6, 1
  addiu $at, $t6, 1
  sra   $t7, $at, 1
.L7F0A1F1C:
  mtc1  $t7, $f8
  nop   
  cvt.s.w $f16, $f8
  jal   sqrtf
   div.s $f12, $f4, $f16
  trunc.w.s $f6, $f0
  lwc1  $f8, 0x90($sp)
  swc1  $f0, 0xb0($sp)
  lwc1  $f18, ($s1)
  mfc1  $v0, $f6
  lwc1  $f6, 0x84($sp)
  lui   $a0, %hi(ptr_sfx_buf)
  sra   $t9, $v0, 1
  mtc1  $t9, $f10
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 71
  cvt.s.w $f14, $f10
  move  $a2, $zero
  move  $s0, $v0
  move  $s2, $v0
  add.s $f12, $f22, $f14
  add.s $f2, $f24, $f14
  mul.s $f4, $f12, $f8
  add.s $f16, $f18, $f4
  mul.s $f10, $f6, $f2
  lwc1  $f4, 0x94($sp)
  mul.s $f6, $f12, $f4
  add.s $f8, $f10, $f16
  lwc1  $f16, 0x88($sp)
  swc1  $f8, 0x9c($sp)
  mul.s $f8, $f16, $f2
  lwc1  $f18, 4($s1)
  add.s $f10, $f18, $f6
  lwc1  $f6, 0x98($sp)
  add.s $f4, $f8, $f10
  mul.s $f16, $f12, $f6
  lwc1  $f10, 0x8c($sp)
  swc1  $f4, 0xa0($sp)
  mul.s $f4, $f10, $f2
  lwc1  $f18, 8($s1)
  add.s $f8, $f18, $f16
  add.s $f6, $f4, $f8
  jal   play_sfx_a1
   swc1  $f6, 0xa4($sp)
  move  $a0, $v0
  jal   sub_GAME_7F053A10
   move  $a1, $s1
  mtc1  $s2, $f4
  mtc1  $s0, $f18
  move  $s3, $zero
  cvt.s.w $f8, $f4
  lui   $at, %hi(D_80057710)
  cvt.s.w $f22, $f18
  swc1  $f8, 0x68($sp)
  lwc1  $f6, 0x68($sp)
  div.s $f18, $f26, $f6
  div.s $f16, $f20, $f22
  trunc.w.s $f10, $f16
  trunc.w.s $f16, $f18
  mfc1  $s4, $f10
  mfc1  $s5, $f16
  move  $s1, $s4
  blezl $s5, .L7F0A2128
   lw    $ra, 0x5c($sp)
  lwc1  $f28, %lo(D_80057710)($at)
  lui   $at, %hi(D_80057714)
  lwc1  $f26, %lo(D_80057714)($at)
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f24
  addiu $s2, $sp, 0xc0
.L7F0A2034:
  blez  $s4, .L7F0A2114
   move  $s0, $zero
  mtc1  $s3, $f10
  lwc1  $f8, 0x68($sp)
  cvt.s.w $f4, $f10
  mul.s $f20, $f4, $f8
  nop   
  mtc1  $s0, $f6
.L7F0A2054:
  lwc1  $f10, 0x90($sp)
  lwc1  $f16, 0x9c($sp)
  cvt.s.w $f18, $f6
  lwc1  $f6, 0x84($sp)
  mul.s $f0, $f18, $f22
  nop   
  mul.s $f4, $f0, $f10
  add.s $f8, $f16, $f4
  mul.s $f18, $f6, $f20
  lwc1  $f4, 0x94($sp)
  lwc1  $f16, 0xa0($sp)
  mul.s $f6, $f0, $f4
  add.s $f10, $f18, $f8
  lwc1  $f8, 0x88($sp)
  add.s $f18, $f16, $f6
  swc1  $f10, 0xc0($sp)
  mul.s $f10, $f8, $f20
  lwc1  $f6, 0x98($sp)
  lwc1  $f16, 0xa4($sp)
  mul.s $f8, $f0, $f6
  add.s $f4, $f10, $f18
  lwc1  $f18, 0x8c($sp)
  add.s $f10, $f16, $f8
  swc1  $f4, 0xc4($sp)
  mul.s $f4, $f18, $f20
  add.s $f6, $f4, $f10
  jal   get_random_value
   swc1  $f6, 0xc8($sp)
  mtc1  $v0, $f16
  mfc1  $a1, $f30
  move  $a0, $s2
  bgez  $v0, .L7F0A20E8
   cvt.s.w $f8, $f16
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f18
  nop   
  add.s $f8, $f8, $f18
.L7F0A20E8:
  mul.s $f4, $f8, $f24
  lwc1  $f16, 0xb0($sp)
  mul.s $f10, $f4, $f26
  add.s $f6, $f10, $f28
  mul.s $f18, $f6, $f16
  mfc1  $a2, $f18
  jal   sub_GAME_7F0A2160
   nop   
  addiu $s0, $s0, 1
  bnel  $s0, $s1, .L7F0A2054
   mtc1  $s0, $f6
.L7F0A2114:
  addiu $s3, $s3, 1
  slt   $at, $s3, $s5
  bnez  $at, .L7F0A2034
   nop   
  lw    $ra, 0x5c($sp)
.L7F0A2128:
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
   addiu $sp, $sp, 0xe0
");

asm(R"
.late_rodata
glabel D_80057718
.word 0x3f8f5c29 /*1.12*/
glabel D_8005771C
.word 0x3df5c28f /*0.12*/
glabel D_80057720
.word 0x40c90fdb /*6.2831855*/
glabel D_80057724
.word 0x3dcccccd /*0.1*/
.text
glabel sub_GAME_7F0A2160
  addiu $sp, $sp, -0x58
  sw    $ra, 0x3c($sp)
  sw    $s2, 0x38($sp)
  sw    $s1, 0x34($sp)
  sw    $s0, 0x30($sp)
  sdc1  $f24, 0x28($sp)
  sdc1  $f22, 0x20($sp)
  sdc1  $f20, 0x18($sp)
  sw    $a0, 0x58($sp)
  sw    $a1, 0x5c($sp)
  jal   get_random_value
   sw    $a2, 0x60($sp)
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f20
  mtc1  $v0, $f4
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f22
  bgez  $v0, .L7F0A21BC
   cvt.s.w $f6, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F0A21BC:
  mul.s $f0, $f6, $f20
  add.s $f10, $f0, $f0
  jal   get_random_value
   sub.s $f24, $f10, $f22
  mtc1  $v0, $f16
  bgez  $v0, .L7F0A21E8
   cvt.s.w $f18, $f16
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f4
  nop   
  add.s $f18, $f18, $f4
.L7F0A21E8:
  mul.s $f8, $f18, $f20
  lui   $at, %hi(D_80057718)
  lwc1  $f6, %lo(D_80057718)($at)
  lui   $at, %hi(D_8005771C)
  lwc1  $f16, %lo(D_8005771C)($at)
  mul.s $f10, $f8, $f6
  sub.s $f4, $f10, $f16
  jal   get_random_value
   swc1  $f4, 0x50($sp)
  lui   $s0, %hi(D_80040940)
  addiu $s0, %lo(D_80040940) # addiu $s0, $s0, 0x940
  lw    $t8, ($s0)
  li    $s2, 104
  lui   $s1, %hi(dword_CODE_bss_8007A164)
  multu $t8, $s2
  addiu $s1, %lo(dword_CODE_bss_8007A164) # addiu $s1, $s1, -0x5e9c
  lw    $t7, ($s1)
  lw    $v1, 0x58($sp)
  li    $t6, 1
  li    $at, 0x3FC00000 # 1.500000
  mtc1  $at, $f2
  li    $at, 0x40400000 # 3.000000
  mtc1  $at, $f4
  mul.s $f10, $f24, $f2
  mflo  $t9
  addu  $t0, $t7, $t9
  sw    $t6, ($t0)
  lw    $t2, ($s0)
  lw    $t1, ($s1)
  lwc1  $f18, ($v1)
  multu $t2, $s2
  mflo  $t3
  addu  $t4, $t1, $t3
  swc1  $f18, 4($t4)
  lw    $t8, ($s0)
  lw    $t5, ($s1)
  lwc1  $f8, 4($v1)
  multu $t8, $s2
  mflo  $t7
  addu  $t9, $t5, $t7
  swc1  $f8, 8($t9)
  lw    $t0, ($s0)
  lw    $t6, ($s1)
  lwc1  $f6, 8($v1)
  multu $t0, $s2
  mtc1  $v0, $f8
  mflo  $t2
  addu  $t1, $t6, $t2
  swc1  $f6, 0xc($t1)
  lw    $t4, ($s0)
  lw    $t3, ($s1)
  cvt.s.w $f6, $f8
  multu $t4, $s2
  mflo  $t8
  addu  $t5, $t3, $t8
  swc1  $f10, 0x1c($t5)
  lw    $t9, ($s0)
  lwc1  $f16, 0x50($sp)
  lw    $t7, ($s1)
  multu $t9, $s2
  mul.s $f18, $f16, $f4
  mflo  $t0
  addu  $t6, $t7, $t0
  bgez  $v0, .L7F0A22FC
   swc1  $f18, 0x20($t6)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f10
  nop   
  add.s $f6, $f6, $f10
.L7F0A22FC:
  mul.s $f0, $f6, $f20
  lw    $t1, ($s0)
  lw    $t2, ($s1)
  multu $t1, $s2
  add.s $f16, $f0, $f0
  sub.s $f4, $f16, $f22
  mflo  $t4
  mul.s $f18, $f4, $f2
  addu  $t3, $t2, $t4
  jal   get_random_value
   swc1  $f18, 0x24($t3)
  mtc1  $v0, $f8
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f24
  bgez  $v0, .L7F0A234C
   cvt.s.w $f10, $f8
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f6
  nop   
  add.s $f10, $f10, $f6
.L7F0A234C:
  mul.s $f16, $f10, $f20
  lwc1  $f8, 0x60($sp)
  lw    $t7, ($s0)
  lw    $t9, ($s1)
  multu $t7, $s2
  mul.s $f4, $f16, $f24
  add.s $f18, $f4, $f22
  mflo  $t0
  addu  $t6, $t9, $t0
  mul.s $f6, $f18, $f8
  trunc.w.s $f10, $f6
  mfc1  $t5, $f10
  jal   get_random_value
   sh    $t5, 0x38($t6)
  mtc1  $v0, $f16
  bgez  $v0, .L7F0A23A0
   cvt.s.w $f4, $f16
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f18
  nop   
  add.s $f4, $f4, $f18
.L7F0A23A0:
  mul.s $f8, $f4, $f20
  lwc1  $f16, 0x60($sp)
  lw    $t3, ($s0)
  lw    $t4, ($s1)
  multu $t3, $s2
  mul.s $f6, $f8, $f24
  add.s $f10, $f6, $f22
  mflo  $t8
  addu  $t7, $t4, $t8
  mul.s $f18, $f10, $f16
  trunc.w.s $f4, $f18
  mfc1  $t2, $f4
  nop   
  sh    $t2, 0x3a($t7)
  lw    $t0, ($s0)
  lw    $t9, ($s1)
  multu $t0, $s2
  mflo  $t5
  addu  $t6, $t9, $t5
  jal   get_random_value
   sh    $zero, 0x3c($t6)
  mtc1  $v0, $f8
  bgez  $v0, .L7F0A2410
   cvt.s.w $f6, $f8
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f10
  nop   
  add.s $f6, $f6, $f10
.L7F0A2410:
  mul.s $f16, $f6, $f20
  lwc1  $f8, 0x60($sp)
  lw    $t8, ($s0)
  lw    $t4, ($s1)
  multu $t8, $s2
  mul.s $f18, $f16, $f24
  add.s $f4, $f18, $f22
  mflo  $t2
  addu  $t7, $t4, $t2
  mul.s $f10, $f4, $f8
  trunc.w.s $f6, $f10
  mfc1  $t3, $f6
  jal   get_random_value
   sh    $t3, 0x48($t7)
  lwc1  $f0, 0x60($sp)
  mtc1  $v0, $f16
  neg.s $f0, $f0
  bgez  $v0, .L7F0A246C
   cvt.s.w $f18, $f16
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f4
  nop   
  add.s $f18, $f18, $f4
.L7F0A246C:
  mul.s $f8, $f18, $f20
  lw    $t6, ($s0)
  lw    $t5, ($s1)
  multu $t6, $s2
  mul.s $f10, $f8, $f24
  add.s $f6, $f10, $f22
  mflo  $t1
  addu  $t8, $t5, $t1
  mul.s $f16, $f6, $f0
  trunc.w.s $f4, $f16
  mfc1  $t9, $f4
  nop   
  sh    $t9, 0x4a($t8)
  lw    $t2, ($s0)
  lw    $t4, ($s1)
  multu $t2, $s2
  mflo  $t3
  addu  $t7, $t4, $t3
  sh    $zero, 0x4c($t7)
  jal   get_random_value
   swc1  $f0, 0x44($sp)
  mtc1  $v0, $f18
  bgez  $v0, .L7F0A24DC
   cvt.s.w $f8, $f18
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f10
  nop   
  add.s $f8, $f8, $f10
.L7F0A24DC:
  mul.s $f6, $f8, $f20
  lwc1  $f18, 0x44($sp)
  lw    $t1, ($s0)
  lw    $t5, ($s1)
  multu $t1, $s2
  mul.s $f16, $f6, $f24
  add.s $f4, $f16, $f22
  mflo  $t9
  addu  $t8, $t5, $t9
  mul.s $f10, $f4, $f18
  trunc.w.s $f8, $f10
  mfc1  $t6, $f8
  jal   get_random_value
   sh    $t6, 0x58($t8)
  mtc1  $v0, $f6
  li    $a1, 5
  li    $a2, 126
  li    $a3, 251
  bgez  $v0, .L7F0A253C
   cvt.s.w $f16, $f6
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f4
  nop   
  add.s $f16, $f16, $f4
.L7F0A253C:
  mul.s $f18, $f16, $f20
  lwc1  $f6, 0x44($sp)
  lw    $t7, ($s0)
  lw    $t3, ($s1)
  multu $t7, $s2
  mul.s $f10, $f18, $f24
  add.s $f8, $f10, $f22
  mflo  $t0
  addu  $t1, $t3, $t0
  mtc1  $zero, $f10
  mul.s $f4, $f8, $f6
  trunc.w.s $f16, $f4
  mfc1  $t4, $f16
  nop   
  sh    $t4, 0x5a($t1)
  lw    $t9, ($s0)
  lw    $t5, ($s1)
  multu $t9, $s2
  mflo  $t6
  addu  $t8, $t5, $t6
  sh    $zero, 0x5c($t8)
  lw    $t7, ($s0)
  lw    $t2, ($s1)
  multu $t7, $s2
  mflo  $t3
  addu  $t0, $t2, $t3
  sh    $zero, 0x40($t0)
  lw    $t1, ($s0)
  lw    $t4, ($s1)
  multu $t1, $s2
  mflo  $t9
  addu  $t5, $t4, $t9
  sh    $zero, 0x42($t5)
  lw    $t8, ($s0)
  lw    $t6, ($s1)
  multu $t8, $s2
  mflo  $t7
  addu  $t2, $t6, $t7
  sh    $zero, 0x50($t2)
  lw    $t0, ($s0)
  lw    $t3, ($s1)
  multu $t0, $s2
  mflo  $t1
  addu  $t4, $t3, $t1
  sh    $zero, 0x52($t4)
  lw    $t5, ($s0)
  lw    $t9, ($s1)
  multu $t5, $s2
  mflo  $t8
  addu  $t6, $t9, $t8
  sh    $zero, 0x60($t6)
  lw    $t2, ($s0)
  lw    $t7, ($s1)
  multu $t2, $s2
  mflo  $t0
  addu  $t3, $t7, $t0
  sh    $zero, 0x62($t3)
  lw    $t4, ($s0)
  lw    $t1, ($s1)
  multu $t4, $s2
  mflo  $t5
  addu  $t9, $t1, $t5
  sb    $a1, 0x44($t9)
  lw    $t6, ($s0)
  lw    $t8, ($s1)
  multu $t6, $s2
  mflo  $t2
  addu  $t7, $t8, $t2
  sb    $a1, 0x45($t7)
  lw    $t3, ($s0)
  lw    $t0, ($s1)
  multu $t3, $s2
  mflo  $t4
  addu  $t1, $t0, $t4
  sb    $a2, 0x46($t1)
  lw    $t9, ($s0)
  lw    $t5, ($s1)
  multu $t9, $s2
  mflo  $t6
  addu  $t8, $t5, $t6
  sb    $a1, 0x54($t8)
  lw    $t7, ($s0)
  lw    $t2, ($s1)
  multu $t7, $s2
  mflo  $t3
  addu  $t0, $t2, $t3
  sb    $a3, 0x55($t0)
  lw    $t1, ($s0)
  lw    $t4, ($s1)
  multu $t1, $s2
  mflo  $t9
  addu  $t5, $t4, $t9
  sb    $a2, 0x56($t5)
  lw    $t8, ($s0)
  lw    $t6, ($s1)
  multu $t8, $s2
  mflo  $t7
  addu  $t2, $t6, $t7
  sb    $a3, 0x64($t2)
  lw    $t0, ($s0)
  lw    $t3, ($s1)
  li    $t7, 255
  multu $t0, $s2
  mflo  $t1
  addu  $t4, $t3, $t1
  sb    $a3, 0x65($t4)
  lw    $t5, ($s0)
  lw    $t9, ($s1)
  multu $t5, $s2
  mflo  $t8
  addu  $t6, $t9, $t8
  sb    $a2, 0x66($t6)
  lw    $t0, ($s0)
  lw    $t2, ($s1)
  multu $t0, $s2
  mflo  $t3
  addu  $t1, $t2, $t3
  sb    $t7, 0x67($t1)
  lw    $t5, ($s0)
  lw    $t4, ($s1)
  multu $t5, $s2
  mflo  $t9
  addu  $v1, $t4, $t9
  lbu   $a0, 0x67($v1)
  sb    $a0, 0x57($v1)
  lw    $t6, ($s0)
  lw    $t8, ($s1)
  multu $t6, $s2
  mflo  $t0
  addu  $t2, $t8, $t0
  sb    $a0, 0x47($t2)
  lw    $t7, ($s0)
  lw    $t3, ($s1)
  lwc1  $f18, 0x5c($sp)
  multu $t7, $s2
  mflo  $t1
  addu  $t5, $t3, $t1
  swc1  $f18, 0x10($t5)
  lw    $t9, ($s0)
  lw    $t4, ($s1)
  multu $t9, $s2
  mflo  $t6
  addu  $t8, $t4, $t6
  jal   get_random_value
   swc1  $f10, 0x14($t8)
  mtc1  $v0, $f8
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F0A279C
   cvt.s.w $f6, $f8
  mtc1  $at, $f4
  nop   
  add.s $f6, $f6, $f4
.L7F0A279C:
  lw    $t2, ($s0)
  mul.s $f16, $f6, $f20
  lui   $at, %hi(D_80057720)
  multu $t2, $s2
  lwc1  $f18, %lo(D_80057720)($at)
  lw    $t0, ($s1)
  mul.s $f10, $f16, $f18
  mflo  $t7
  addu  $t3, $t0, $t7
  jal   get_random_value
   swc1  $f10, 0x18($t3)
  mtc1  $v0, $f8
  lui   $at, %hi(D_80057724)
  lwc1  $f22, %lo(D_80057724)($at)
  bgez  $v0, .L7F0A27EC
   cvt.s.w $f4, $f8
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f6
  nop   
  add.s $f4, $f4, $f6
.L7F0A27EC:
  lw    $t5, ($s0)
  mul.s $f16, $f4, $f20
  lw    $t1, ($s1)
  multu $t5, $s2
  mul.s $f18, $f16, $f22
  mflo  $t9
  addu  $t4, $t1, $t9
  jal   get_random_value
   swc1  $f18, 0x28($t4)
  mtc1  $v0, $f10
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F0A282C
   cvt.s.w $f8, $f10
  mtc1  $at, $f6
  nop   
  add.s $f8, $f8, $f6
.L7F0A282C:
  lw    $t8, ($s0)
  mul.s $f4, $f8, $f20
  lw    $t6, ($s1)
  multu $t8, $s2
  mul.s $f16, $f4, $f22
  mflo  $t2
  addu  $t0, $t6, $t2
  jal   get_random_value
   swc1  $f16, 0x2c($t0)
  mtc1  $v0, $f18
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F0A286C
   cvt.s.w $f10, $f18
  mtc1  $at, $f6
  nop   
  add.s $f10, $f10, $f6
.L7F0A286C:
  lw    $t3, ($s0)
  mul.s $f8, $f10, $f20
  lw    $t7, ($s1)
  multu $t3, $s2
  lui   $t6, %hi(dword_CODE_bss_8007A160) 
  mul.s $f4, $f8, $f22
  mflo  $t5
  addu  $t1, $t7, $t5
  swc1  $f4, 0x30($t1)
  lw    $t9, ($s0)
  addiu $t4, $t9, 1
  sw    $t4, ($s0)
  lw    $t6, %lo(dword_CODE_bss_8007A160)($t6)
  slt   $at, $t4, $t6
  bnezl $at, .L7F0A28B4
   lw    $ra, 0x3c($sp)
  sw    $zero, ($s0)
  lw    $ra, 0x3c($sp)
.L7F0A28B4:
  ldc1  $f20, 0x18($sp)
  ldc1  $f22, 0x20($sp)
  ldc1  $f24, 0x28($sp)
  lw    $s0, 0x30($sp)
  lw    $s1, 0x34($sp)
  lw    $s2, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x58
");

asm(R"
.late_rodata
glabel D_80057728
.word 0x46ea6000 /*30000.0*/
glabel D_8005772C
.word 0xc6ea6000 /*-30000.0*/
glabel D_80057730
.word 0x3dcccccd /*0.1*/
glabel D_80057734
.word 0x00000000 /*0.0*/
glabel D_80057738
.word 0x00000000 /*0.0*/
glabel D_8005773C
.word 0x00000000 /*0.0*/
.text
glabel sub_GAME_7F0A28D4
  lui   $v0, %hi(clock_timer)
  lw    $v0, %lo(clock_timer)($v0)
  lui   $t0, %hi(dword_CODE_bss_8007A160) 
  addiu $t0, %lo(dword_CODE_bss_8007A160) # addiu $t0, $t0, -0x5ea0
  slti  $at, $v0, 0xf
  beqz  $at, .L7F0A28FC
   move  $v1, $zero
  mtc1  $v0, $f4
  b     .L7F0A2908
   cvt.s.w $f0, $f4
.L7F0A28FC:
  li    $at, 0x41700000 # 15.000000
  mtc1  $at, $f0
  nop   
.L7F0A2908:
  lw    $t6, ($t0)
  move  $v0, $zero
  lui   $at, %hi(D_80057728)
  blez  $t6, .L7F0A2C3C
   lui   $t1, %hi(dword_CODE_bss_8007A164) 
  lwc1  $f16, %lo(D_80057728)($at)
  lui   $at, %hi(D_8005772C)
  lwc1  $f14, %lo(D_8005772C)($at)
  lui   $at, %hi(D_80057730)
  lwc1  $f12, %lo(D_80057730)($at)
  addiu $t1, %lo(dword_CODE_bss_8007A164) # addiu $t1, $t1, -0x5e9c
  lw    $t7, ($t1)
.L7F0A2938:
  addu  $a0, $t7, $v1
  lw    $a1, ($a0)
  blezl $a1, .L7F0A2C28
   lw    $t4, ($t0)
  trunc.w.s $f6, $f0
  move  $a3, $zero
  mfc1  $a2, $f6
  nop   
  addu  $t9, $a1, $a2
  sw    $t9, ($a0)
  lw    $t2, ($t1)
  addu  $a0, $t2, $v1
  lwc1  $f10, 0x28($a0)
  lwc1  $f8, 0x10($a0)
  mul.s $f18, $f10, $f0
  add.s $f4, $f8, $f18
  swc1  $f4, 0x10($a0)
  lw    $t3, ($t1)
  addu  $a0, $t3, $v1
  lwc1  $f10, 0x2c($a0)
  lwc1  $f6, 0x14($a0)
  mul.s $f8, $f10, $f0
  add.s $f18, $f6, $f8
  swc1  $f18, 0x14($a0)
  lw    $t4, ($t1)
  addu  $a0, $t4, $v1
  lwc1  $f10, 0x30($a0)
  lwc1  $f4, 0x18($a0)
  mul.s $f6, $f10, $f0
  add.s $f8, $f4, $f6
  swc1  $f8, 0x18($a0)
  lw    $t5, ($t1)
  addu  $a0, $t5, $v1
  lwc1  $f10, 0x1c($a0)
  lwc1  $f18, 4($a0)
  mul.s $f4, $f10, $f0
  add.s $f6, $f18, $f4
  swc1  $f6, 4($a0)
  lw    $t6, ($t1)
  addu  $a0, $t6, $v1
  lwc1  $f10, 0x24($a0)
  lwc1  $f8, 0xc($a0)
  mul.s $f18, $f10, $f0
  add.s $f4, $f8, $f18
  blez  $a2, .L7F0A2BD8
   swc1  $f4, 0xc($a0)
  andi  $a0, $a2, 3
  beqz  $a0, .L7F0A2A68
   move  $a1, $a0
  addiu $a3, $a3, 1
  beq   $a1, $a3, .L7F0A2A3C
   lw    $t7, ($t1)
.L7F0A2A08:
  addu  $a0, $t7, $v1
  lwc1  $f18, 8($a0)
  lwc1  $f10, 0x20($a0)
  addiu $a3, $a3, 1
  add.s $f10, $f18, $f10
  swc1  $f10, 8($a0)
  lw    $t8, ($t1)
  addu  $a0, $t8, $v1
  lwc1  $f10, 0x20($a0)
  sub.s $f10, $f10, $f12
  swc1  $f10, 0x20($a0)
  bne   $a1, $a3, .L7F0A2A08
   lw    $t7, ($t1)
.L7F0A2A3C:
  addu  $a0, $t7, $v1
  lwc1  $f18, 8($a0)
  lwc1  $f10, 0x20($a0)
  add.s $f10, $f18, $f10
  swc1  $f10, 8($a0)
  lw    $t8, ($t1)
  addu  $a0, $t8, $v1
  lwc1  $f10, 0x20($a0)
  sub.s $f10, $f10, $f12
  swc1  $f10, 0x20($a0)
  beq   $a3, $a2, .L7F0A2BD8
.L7F0A2A68:
   addiu $a3, $a3, 4
  beq   $a3, $a2, .L7F0A2B2C
   lw    $t9, ($t1)
.L7F0A2A74:
  addu  $a0, $t9, $v1
  lwc1  $f18, 8($a0)
  lwc1  $f10, 0x20($a0)
  addiu $a3, $a3, 4
  add.s $f10, $f18, $f10
  swc1  $f10, 8($a0)
  lw    $t2, ($t1)
  addu  $a0, $t2, $v1
  lwc1  $f10, 0x20($a0)
  sub.s $f10, $f10, $f12
  swc1  $f10, 0x20($a0)
  lw    $t3, ($t1)
  addu  $a0, $t3, $v1
  lwc1  $f10, 8($a0)
  lwc1  $f18, 0x20($a0)
  add.s $f18, $f10, $f18
  swc1  $f18, 8($a0)
  lw    $t4, ($t1)
  addu  $a0, $t4, $v1
  lwc1  $f18, 0x20($a0)
  sub.s $f18, $f18, $f12
  swc1  $f18, 0x20($a0)
  lw    $t5, ($t1)
  addu  $a0, $t5, $v1
  lwc1  $f18, 8($a0)
  lwc1  $f10, 0x20($a0)
  add.s $f10, $f18, $f10
  swc1  $f10, 8($a0)
  lw    $t6, ($t1)
  addu  $a0, $t6, $v1
  lwc1  $f10, 0x20($a0)
  sub.s $f10, $f10, $f12
  swc1  $f10, 0x20($a0)
  lw    $t7, ($t1)
  addu  $a0, $t7, $v1
  lwc1  $f10, 8($a0)
  lwc1  $f18, 0x20($a0)
  add.s $f18, $f10, $f18
  swc1  $f18, 8($a0)
  lw    $t8, ($t1)
  addu  $a0, $t8, $v1
  lwc1  $f18, 0x20($a0)
  sub.s $f18, $f18, $f12
  swc1  $f18, 0x20($a0)
  bne   $a3, $a2, .L7F0A2A74
   lw    $t9, ($t1)
.L7F0A2B2C:
  addu  $a0, $t9, $v1
  lwc1  $f18, 8($a0)
  lwc1  $f10, 0x20($a0)
  add.s $f10, $f18, $f10
  swc1  $f10, 8($a0)
  lw    $t2, ($t1)
  addu  $a0, $t2, $v1
  lwc1  $f10, 0x20($a0)
  sub.s $f10, $f10, $f12
  swc1  $f10, 0x20($a0)
  lw    $t3, ($t1)
  addu  $a0, $t3, $v1
  lwc1  $f10, 8($a0)
  lwc1  $f18, 0x20($a0)
  add.s $f18, $f10, $f18
  swc1  $f18, 8($a0)
  lw    $t4, ($t1)
  addu  $a0, $t4, $v1
  lwc1  $f18, 0x20($a0)
  sub.s $f18, $f18, $f12
  swc1  $f18, 0x20($a0)
  lw    $t5, ($t1)
  addu  $a0, $t5, $v1
  lwc1  $f18, 8($a0)
  lwc1  $f10, 0x20($a0)
  add.s $f10, $f18, $f10
  swc1  $f10, 8($a0)
  lw    $t6, ($t1)
  addu  $a0, $t6, $v1
  lwc1  $f10, 0x20($a0)
  sub.s $f10, $f10, $f12
  swc1  $f10, 0x20($a0)
  lw    $t7, ($t1)
  addu  $a0, $t7, $v1
  lwc1  $f10, 8($a0)
  lwc1  $f18, 0x20($a0)
  add.s $f18, $f10, $f18
  swc1  $f18, 8($a0)
  lw    $t8, ($t1)
  addu  $a0, $t8, $v1
  lwc1  $f18, 0x20($a0)
  sub.s $f18, $f18, $f12
  swc1  $f18, 0x20($a0)
.L7F0A2BD8:
  lw    $t9, ($t1)
  addu  $a0, $t9, $v1
  lw    $t2, ($a0)
  slti  $at, $t2, 0x96
  bnezl $at, .L7F0A2C00
   lwc1  $f2, 8($a0)
  sw    $zero, ($a0)
  lw    $t3, ($t1)
  addu  $a0, $t3, $v1
  lwc1  $f2, 8($a0)
.L7F0A2C00:
  c.lt.s $f2, $f14
  nop   
  bc1tl .L7F0A2C24
   sw    $zero, ($a0)
  c.lt.s $f16, $f2
  nop   
  bc1fl .L7F0A2C28
   lw    $t4, ($t0)
  sw    $zero, ($a0)
.L7F0A2C24:
  lw    $t4, ($t0)
.L7F0A2C28:
  addiu $v0, $v0, 1
  addiu $v1, $v1, 0x68
  slt   $at, $v0, $t4
  bnezl $at, .L7F0A2938
   lw    $t7, ($t1)
.L7F0A2C3C:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0A2C44
  addiu $sp, $sp, -0xd0
  lui   $a1, %hi(glassoverlayimage)
  lw    $a1, %lo(glassoverlayimage)($a1)
  sw    $ra, 0x44($sp)
  sw    $a0, 0xd0($sp)
  li    $t6, 2
  sw    $fp, 0x40($sp)
  sw    $s7, 0x3c($sp)
  sw    $s6, 0x38($sp)
  sw    $s5, 0x34($sp)
  sw    $s4, 0x30($sp)
  sw    $s3, 0x2c($sp)
  sw    $s2, 0x28($sp)
  sw    $s1, 0x24($sp)
  sw    $s0, 0x20($sp)
  sw    $t6, 0x10($sp)
  addiu $a0, $sp, 0xd0
  li    $a2, 2
  li    $a3, 1
  jal   likely_generate_DL_for_image_declaration
   addiu $a1, $a1, 0xc
  lw    $t7, 0xd0($sp)
  lui   $t9, (0xBB001001 >> 16) # lui $t9, 0xbb00
  lui   $t0, (0x0D800D80 >> 16) # lui $t0, 0xd80
  addiu $t8, $t7, 8
  sw    $t8, 0xd0($sp)
  ori   $t0, (0x0D800D80 & 0xFFFF) # ori $t0, $t0, 0xd80
  ori   $t9, (0xBB001001 & 0xFFFF) # ori $t9, $t9, 0x1001
  sw    $t9, ($t7)
  sw    $t0, 4($t7)
  lw    $t1, 0xd0($sp)
  lui   $t3, (0xBA001402 >> 16) # lui $t3, 0xba00
  ori   $t3, (0xBA001402 & 0xFFFF) # ori $t3, $t3, 0x1402
  addiu $t2, $t1, 8
  sw    $t2, 0xd0($sp)
  lui   $t4, 0x10
  sw    $t4, 4($t1)
  sw    $t3, ($t1)
  lw    $t5, 0xd0($sp)
  lui   $t7, (0xBA001001 >> 16) # lui $t7, 0xba00
  ori   $t7, (0xBA001001 & 0xFFFF) # ori $t7, $t7, 0x1001
  addiu $t6, $t5, 8
  sw    $t6, 0xd0($sp)
  lui   $t8, 1
  sw    $t8, 4($t5)
  sw    $t7, ($t5)
  lw    $t9, 0xd0($sp)
  lui   $t1, 0xb600
  li    $t2, 12288
  addiu $t0, $t9, 8
  sw    $t0, 0xd0($sp)
  sw    $t2, 4($t9)
  sw    $t1, ($t9)
  lw    $t3, 0xd0($sp)
  lui   $t5, (0xBA000C02 >> 16) # lui $t5, 0xba00
  ori   $t5, (0xBA000C02 & 0xFFFF) # ori $t5, $t5, 0xc02
  addiu $t4, $t3, 8
  sw    $t4, 0xd0($sp)
  li    $t6, 8192
  sw    $t6, 4($t3)
  sw    $t5, ($t3)
  lw    $t7, 0xd0($sp)
  lui   $t9, 0xb700
  lui   $t0, 6
  addiu $t8, $t7, 8
  sw    $t8, 0xd0($sp)
  sw    $t0, 4($t7)
  sw    $t9, ($t7)
  lw    $s0, 0xd0($sp)
  lui   $t3, (0x01030040 >> 16) # lui $t3, 0x103
  ori   $t3, (0x01030040 & 0xFFFF) # ori $t3, $t3, 0x40
  addiu $t2, $s0, 8
  sw    $t2, 0xd0($sp)
  jal   get_BONDdata_field_10E0
   sw    $t3, ($s0)
  jal   osVirtualToPhysical
   move  $a0, $v0
  sw    $v0, 4($s0)
  lui   $a0, %hi(dword_CODE_bss_8007A160)
  lw    $a0, %lo(dword_CODE_bss_8007A160)($a0)
  move  $s0, $zero
  move  $s4, $zero
  blez  $a0, .L7F0A2EA0
   lui   $s7, (0x04200030 >> 16) # lui $s7, 0x420
  lui   $s6, %hi(pPlayer)
  lui   $s3, %hi(dword_CODE_bss_8007A164)
  addiu $s3, %lo(dword_CODE_bss_8007A164) # addiu $s3, $s3, -0x5e9c
  addiu $s6, %lo(pPlayer) # addiu $s6, $s6, -0x5f50
  lui   $fp, 0xbf00
  ori   $s7, (0x04200030 & 0xFFFF) # ori $s7, $s7, 0x30
  addiu $s5, $sp, 0x90
.L7F0A2DB0:
  lw    $t4, ($s3)
  addu  $t5, $t4, $s0
  lw    $t6, ($t5)
  blezl $t6, .L7F0A2E94
   addiu $s4, $s4, 1
  jal   sub_GAME_7F0BD6E0
   nop   
  lw    $t7, ($s3)
  move  $s1, $v0
  move  $a2, $s5
  addu  $v1, $t7, $s0
  addiu $a0, $v1, 4
  jal   sub_GAME_7F05892C
   addiu $a1, $v1, 0x10
  lw    $v0, ($s6)
  lwc1  $f4, 0xc0($sp)
  lwc1  $f10, 0xc4($sp)
  lwc1  $f6, 0x38($v0)
  move  $a0, $s5
  move  $a1, $s1
  sub.s $f8, $f4, $f6
  lwc1  $f4, 0xc8($sp)
  swc1  $f8, 0xc0($sp)
  lwc1  $f16, 0x3c($v0)
  sub.s $f18, $f10, $f16
  swc1  $f18, 0xc4($sp)
  lwc1  $f6, 0x40($v0)
  sub.s $f8, $f4, $f6
  jal   sub_GAME_7F058C9C
   swc1  $f8, 0xc8($sp)
  lw    $s2, 0xd0($sp)
  lui   $t0, (0x01020040 >> 16) # lui $t0, 0x102
  ori   $t0, (0x01020040 & 0xFFFF) # ori $t0, $t0, 0x40
  addiu $t9, $s2, 8
  sw    $t9, 0xd0($sp)
  move  $a0, $s1
  jal   osVirtualToPhysical
   sw    $t0, ($s2)
  sw    $v0, 4($s2)
  lw    $s1, 0xd0($sp)
  addiu $t2, $s1, 8
  sw    $t2, 0xd0($sp)
  sw    $s7, ($s1)
  lw    $t3, ($s3)
  addu  $a0, $t3, $s0
  jal   osVirtualToPhysical
   addiu $a0, $a0, 0x38
  sw    $v0, 4($s1)
  lw    $t4, 0xd0($sp)
  li    $t6, 2580
  lui   $a0, %hi(dword_CODE_bss_8007A160)
  addiu $t5, $t4, 8
  sw    $t5, 0xd0($sp)
  sw    $t6, 4($t4)
  sw    $fp, ($t4)
  lw    $a0, %lo(dword_CODE_bss_8007A160)($a0)
  addiu $s4, $s4, 1
.L7F0A2E94:
  slt   $at, $s4, $a0
  bnez  $at, .L7F0A2DB0
   addiu $s0, $s0, 0x68
.L7F0A2EA0:
  lw    $t7, 0xd0($sp)
  lui   $t9, 0xb600
  lui   $t0, 6
  addiu $t8, $t7, 8
  sw    $t8, 0xd0($sp)
  sw    $t0, 4($t7)
  sw    $t9, ($t7)
  lw    $s0, 0xd0($sp)
  lui   $t3, (0x01030040 >> 16) # lui $t3, 0x103
  ori   $t3, (0x01030040 & 0xFFFF) # ori $t3, $t3, 0x40
  addiu $t2, $s0, 8
  sw    $t2, 0xd0($sp)
  jal   get_BONDdata_field_10D8
   sw    $t3, ($s0)
  sw    $v0, 4($s0)
  lw    $s1, 0xd0($sp)
  lui   $t6, (0x01020040 >> 16) # lui $t6, 0x102
  ori   $t6, (0x01020040 & 0xFFFF) # ori $t6, $t6, 0x40
  addiu $t5, $s1, 8
  sw    $t5, 0xd0($sp)
  jal   get_BONDdata_field_10C8
   sw    $t6, ($s1)
  sw    $v0, 4($s1)
  lw    $ra, 0x44($sp)
  lw    $fp, 0x40($sp)
  lw    $s7, 0x3c($sp)
  lw    $s6, 0x38($sp)
  lw    $s5, 0x34($sp)
  lw    $s4, 0x30($sp)
  lw    $s3, 0x2c($sp)
  lw    $s2, 0x28($sp)
  lw    $s1, 0x24($sp)
  lw    $s0, 0x20($sp)
  lw    $v0, 0xd0($sp)
  jr    $ra
   addiu $sp, $sp, 0xd0
");

asm(R"
.late_rodata
glabel D_80057740
.word 0x4061d000, 0x00000000 /*142.5*/
glabel D_80057748
.word 0x40490fdb /*3.1415927*/
.text
glabel sub_GAME_7F0A2F30
  addiu $sp, $sp, -0x98
  sw    $s6, 0x60($sp)
  move  $s6, $a2
  mtc1  $s6, $f6
  li    $at, 0x41000000 # 8.000000
  mtc1  $at, $f4
  cvt.s.w $f8, $f6
  sdc1  $f30, 0x40($sp)
  li    $at, 0x43020000 # 130.000000
  sdc1  $f22, 0x20($sp)
  mtc1  $at, $f30
  mtc1  $a3, $f22
  sdc1  $f28, 0x38($sp)
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f28
  sdc1  $f26, 0x30($sp)
  li    $at, 0x42FE0000 # 127.000000
  sw    $fp, 0x68($sp)
  sw    $s7, 0x64($sp)
  sw    $s5, 0x5c($sp)
  sw    $s3, 0x54($sp)
  sw    $s2, 0x50($sp)
  sw    $s0, 0x48($sp)
  mtc1  $at, $f26
  mul.s $f22, $f22, $f4
  move  $s0, $a0
  sw    $ra, 0x6c($sp)
  sw    $s4, 0x58($sp)
  sw    $s1, 0x4c($sp)
  sdc1  $f24, 0x28($sp)
  sdc1  $f20, 0x18($sp)
  sw    $a1, 0x9c($sp)
  move  $s2, $zero
  li    $s3, 255
  li    $s5, 48
  li    $s7, 6
  li    $fp, 2
  swc1  $f8, 0x74($sp)
  sw    $zero, 0x80($sp)
.L7F0A2FCC:
  lw    $v0, 0x80($sp)
  lui    $at, %hi(D_80057740)
  ldc1  $f10, %lo(D_80057740)($at)
  mtc1  $v0, $f16
  lui    $at, %hi(D_80057748)
  move  $s4, $zero
  cvt.d.w $f18, $f16
  sub.d $f4, $f10, $f18
  lwc1  $f10, %lo(D_80057748)($at)
  li    $at, 0x40000000 # 2.000000
  trunc.w.d $f6, $f4
  mtc1  $at, $f4
  li    $at, 0x43B40000 # 360.000000
  mfc1  $t7, $f6
  nop   
  mtc1  $t7, $f8
  nop   
  cvt.s.w $f16, $f8
  mtc1  $at, $f8
  mul.s $f18, $f16, $f10
  nop   
  mul.s $f6, $f18, $f4
  div.s $f24, $f6, $f8
.L7F0A3028:
  jal   sinf
   mov.s $f12, $f24
  mul.s $f10, $f0, $f28
  subu  $t8, $s7, $s4
  mtc1  $t8, $f16
  li    $at, 0x40A00000 # 5.000000
  mtc1  $at, $f6
  mov.s $f12, $f24
  cvt.s.w $f20, $f16
  mul.s $f18, $f10, $f30
  lwc1  $f16, 0x74($sp)
  mul.s $f4, $f18, $f20
  div.s $f8, $f4, $f6
  mul.s $f10, $f8, $f16
  trunc.w.s $f18, $f10
  mfc1  $s1, $f18
  nop   
  sll   $t0, $s1, 0x10
  jal   cosf
   sra   $s1, $t0, 0x10
  mul.s $f4, $f0, $f28
  li    $at, 0x40A00000 # 5.000000
  mtc1  $at, $f16
  addiu $t2, $s1, 1
  sh    $t2, ($s0)
  sh    $zero, 2($s0)
  sh    $zero, 6($s0)
  mul.s $f6, $f4, $f30
  sh    $zero, 8($s0)
  sh    $zero, 0xa($s0)
  sb    $s3, 0xc($s0)
  sb    $s3, 0xd($s0)
  sb    $s3, 0xe($s0)
  mul.s $f8, $f6, $f20
  div.s $f10, $f8, $f16
  trunc.w.s $f18, $f10
  mfc1  $t6, $f18
  nop   
  negu  $t7, $t6
  blez  $s6, .L7F0A3114
   sh    $t7, 4($s0)
  jal   cosf
   mov.s $f12, $f24
  li    $at, 0x42C00000 # 96.000000
  mtc1  $at, $f2
  mov.s $f12, $f24
  mul.s $f4, $f0, $f2
  sub.s $f6, $f2, $f4
  trunc.w.s $f8, $f6
  mfc1  $t9, $f8
  jal   cosf
   sb    $t9, 0xc($s0)
  mul.s $f16, $f0, $f26
  sb    $s3, 0xe($s0)
  sub.s $f10, $f26, $f16
  trunc.w.s $f18, $f10
  mfc1  $t1, $f18
  b     .L7F0A3164
   sb    $t1, 0xd($s0)
.L7F0A3114:
  bgezl $s6, .L7F0A3168
   slti  $at, $s2, 0xa
  jal   cosf
   mov.s $f12, $f24
  mul.s $f4, $f0, $f26
  mov.s $f12, $f24
  sub.s $f6, $f26, $f4
  trunc.w.s $f8, $f6
  mfc1  $t3, $f8
  jal   cosf
   sb    $t3, 0xd($s0)
  li    $at, 0x42000000 # 32.000000
  mtc1  $at, $f10
  mtc1  $at, $f16
  mul.s $f18, $f0, $f10
  sub.s $f4, $f16, $f18
  trunc.w.s $f6, $f4
  mfc1  $t5, $f6
  nop   
  sb    $t5, 0xe($s0)
.L7F0A3164:
  slti  $at, $s2, 0xa
.L7F0A3168:
  beqz  $at, .L7F0A31F4
   addiu $s4, $s4, 1
  trunc.w.s $f8, $f22
  mfc1  $v0, $f8
  nop   
  sll   $v1, $v0, 1
  addiu $v1, $v1, -1
  slt   $at, $v1, $s2
  bnezl $at, .L7F0A319C
   add.s $f10, $f22, $f22
  b     .L7F0A32C8
   sb    $s3, 0xf($s0)
  add.s $f10, $f22, $f22
.L7F0A319C:
  trunc.w.s $f16, $f10
  mfc1  $t8, $f16
  nop   
  slt   $at, $s2, $t8
  beqz  $at, .L7F0A31EC
   slt   $at, $v1, $s2
  beqz  $at, .L7F0A31EC
   nop   
  mtc1  $v0, $f18
  li    $at, 0x434F0000 # 207.000000
  mtc1  $at, $f8
  cvt.s.w $f4, $f18
  sub.s $f6, $f22, $f4
  mul.s $f10, $f6, $f8
  trunc.w.s $f16, $f10
  mfc1  $t0, $f16
  nop   
  addiu $t1, $t0, 0x30
  b     .L7F0A32C8
   sb    $t1, 0xf($s0)
.L7F0A31EC:
  b     .L7F0A32C8
   sb    $s5, 0xf($s0)
.L7F0A31F4:
  slti  $at, $s2, 0xa
  bnez  $at, .L7F0A32C8
   li    $at, 0x40A00000 # 5.000000
  mtc1  $at, $f18
  mtc1  $s2, $f8
  li    $at, 0x41100000 # 9.000000
  sub.s $f0, $f22, $f18
  mtc1  $at, $f4
  li    $at, 0x3F000000 # 0.500000
  cvt.s.w $f10, $f8
  mul.s $f2, $f0, $f28
  add.s $f6, $f4, $f2
  c.le.s $f10, $f6
  nop   
  bc1fl .L7F0A3240
   mtc1  $at, $f16
  b     .L7F0A32C8
   sb    $s3, 0xf($s0)
  mtc1  $at, $f16
.L7F0A3240:
  nop   
  add.s $f18, $f2, $f16
  trunc.w.s $f4, $f18
  mfc1  $t3, $f4
  nop   
  addiu $t4, $t3, 9
  slt   $at, $t4, $s2
  bnezl $at, .L7F0A32C8
   sb    $s5, 0xf($s0)
  trunc.w.s $f8, $f0
  mfc1  $t6, $f8
  nop   
  sll   $t7, $t6, 1
  addiu $t8, $t7, 8
  slt   $at, $t8, $s2
  beql  $at, $zero, .L7F0A32C8
   sb    $s5, 0xf($s0)
  trunc.w.s $f6, $f22
  li    $at, 0x434F0000 # 207.000000
  mtc1  $at, $f4
  mfc1  $t0, $f6
  nop   
  mtc1  $t0, $f10
  nop   
  cvt.s.w $f16, $f10
  sub.s $f18, $f22, $f16
  mul.s $f8, $f18, $f4
  trunc.w.s $f6, $f8
  mfc1  $t2, $f6
  nop   
  addiu $t3, $t2, 0x30
  b     .L7F0A32C8
   sb    $t3, 0xf($s0)
  sb    $s5, 0xf($s0)
.L7F0A32C8:
  bne   $s4, $fp, .L7F0A3028
   addiu $s0, $s0, 0x10
  lw    $t4, 0x80($sp)
  addiu $s2, $s2, 1
  li    $at, 23
  addiu $t5, $t4, 5
  bne   $s2, $at, .L7F0A2FCC
   sw    $t5, 0x80($sp)
  lw    $ra, 0x6c($sp)
  ldc1  $f20, 0x18($sp)
  ldc1  $f22, 0x20($sp)
  ldc1  $f24, 0x28($sp)
  ldc1  $f26, 0x30($sp)
  ldc1  $f28, 0x38($sp)
  ldc1  $f30, 0x40($sp)
  lw    $s0, 0x48($sp)
  lw    $s1, 0x4c($sp)
  lw    $s2, 0x50($sp)
  lw    $s3, 0x54($sp)
  lw    $s4, 0x58($sp)
  lw    $s5, 0x5c($sp)
  lw    $s6, 0x60($sp)
  lw    $s7, 0x64($sp)
  lw    $fp, 0x68($sp)
  jr    $ra
   addiu $sp, $sp, 0x98
");

asm(R"
glabel sub_GAME_7F0A3330
  move  $a3, $a0
  move  $v0, $zero
  bgez  $a2, .L7F0A3348
   sra   $v1, $a2, 1
  addiu $at, $a2, 1
  sra   $v1, $at, 1
.L7F0A3348:
  addiu $v1, $v1, -2
  bltz  $v1, .L7F0A33E8
   lui   $t3, 0xb800
  lui   $t0, (0xB1000032 >> 16) # lui $t0, 0xb100
  lui   $a2, (0x04300040 >> 16) # lui $a2, 0x430
  ori   $a2, (0x04300040 & 0xFFFF) # ori $a2, $a2, 0x40
  ori   $t0, (0xB1000032 & 0xFFFF) # ori $t0, $t0, 0x32
  li    $t1, 8464
.L7F0A3368:
  move  $a0, $a3
  slti  $at, $v0, 9
  sw    $a2, ($a0)
  sw    $a1, 4($a0)
  bnez  $at, .L7F0A33B0
   addiu $a3, $a3, 8
  addiu $t6, $v0, 3
  bgez  $t6, .L7F0A3398
   andi  $t7, $t6, 3
  beqz  $t7, .L7F0A3398
   nop   
  addiu $t7, $t7, -4
.L7F0A3398:
  beqz  $t7, .L7F0A33D0
   move  $a0, $a3
  addiu $a3, $a3, 8
  sw    $t0, ($a0)
  b     .L7F0A33D0
   sw    $t1, 4($a0)
.L7F0A33B0:
  slti  $at, $v0, 9
  beqz  $at, .L7F0A33D0
   andi  $t8, $v0, 1
  bnez  $t8, .L7F0A33D0
   move  $a0, $a3
  addiu $a3, $a3, 8
  sw    $t0, ($a0)
  sw    $t1, 4($a0)
.L7F0A33D0:
  addiu $v0, $v0, 1
  sll   $t9, $v0, 0x18
  sra   $v0, $t9, 0x18
  slt   $at, $v1, $v0
  beqz  $at, .L7F0A3368
   addiu $a1, $a1, 0x20
.L7F0A33E8:
  addiu $v0, $a3, 8
  sw    $t3, ($a3)
  jr    $ra
   sw    $zero, 4($a3)
");

asm(R"
.late_rodata
glabel D_8005774C
.word 0x40490fdb /*3.1415927*/
.text
glabel sub_GAME_7F0A33F8
  addiu $sp, $sp, -0x80
  sdc1  $f30, 0x38($sp)
  mtc1  $a2, $f30
  sw    $s6, 0x5c($sp)
  sw    $s0, 0x44($sp)
  move  $s0, $a0
  move  $s6, $a1
  sw    $ra, 0x64($sp)
  sw    $s7, 0x60($sp)
  sw    $s5, 0x58($sp)
  sw    $s4, 0x54($sp)
  sw    $s3, 0x50($sp)
  sw    $s2, 0x4c($sp)
  sw    $s1, 0x48($sp)
  sdc1  $f28, 0x30($sp)
  sdc1  $f26, 0x28($sp)
  sdc1  $f24, 0x20($sp)
  sdc1  $f22, 0x18($sp)
  beqz  $a3, .L7F0A3480
   sdc1  $f20, 0x10($sp)
  li    $s5, 176
  li    $t6, 1
  li    $t7, 44
  sh    $t6, ($a0)
  sh    $zero, 2($a0)
  sh    $zero, 4($a0)
  sh    $zero, 6($a0)
  sh    $zero, 8($a0)
  sh    $zero, 0xa($a0)
  sb    $zero, 0xc($a0)
  sb    $t7, 0xd($a0)
  sb    $zero, 0xe($a0)
  sb    $s5, 0xf($a0)
  addiu $s0, $a0, 0x10
.L7F0A3480:
  addiu $s7, $s6, -7
  slti  $at, $s7, 7
  li    $s5, 176
  bnez  $at, .L7F0A3934
   li    $s1, 7
  mtc1  $s6, $f4
  li    $at, 0x41A00000 # 20.000000
  mtc1  $at, $f28
  cvt.s.w $f0, $f4
  li    $at, 0x42300000 # 44.000000
  mtc1  $at, $f26
  li    $at, 0x44020000 # 520.000000
  mtc1  $at, $f24
  mtc1  $zero, $f22
  swc1  $f0, 0x6c($sp)
  li    $s3, 255
  mtc1  $s1, $f6
.L7F0A34C4:
  lui   $at, %hi(D_8005774C)
  lwc1  $f10, %lo(D_8005774C)($at)
  cvt.s.w $f8, $f6
  lwc1  $f0, 0x6c($sp)
  mul.s $f16, $f8, $f10
  div.s $f20, $f16, $f0
  jal   sinf
   mov.s $f12, $f20
  mul.s $f18, $f0, $f24
  mov.s $f12, $f20
  mul.s $f4, $f18, $f30
  trunc.w.s $f6, $f4
  mfc1  $s2, $f6
  nop   
  sll   $t9, $s2, 0x10
  jal   cosf
   sra   $s2, $t9, 0x10
  mul.s $f8, $f0, $f24
  addiu $t3, $s2, 1
  sh    $t3, ($s0)
  sh    $zero, 2($s0)
  sh    $zero, 6($s0)
  sh    $zero, 8($s0)
  sh    $zero, 0xa($s0)
  mul.s $f10, $f8, $f30
  mov.s $f12, $f20
  trunc.w.s $f16, $f10
  mfc1  $t5, $f16
  nop   
  sll   $s4, $t5, 0x10
  sra   $t2, $s4, 0x10
  negu  $t6, $t5
  move  $s4, $t2
  jal   cosf
   sh    $t6, 4($s0)
  mul.s $f18, $f0, $f22
  li    $t8, 1
  li    $at, 0x4F000000 # 2147483648.000000
  sub.s $f4, $f22, $f18
  cfc1  $t7, $31
  ctc1  $t8, $31
  nop   
  cvt.w.s $f6, $f4
  cfc1  $t8, $31
  nop   
  andi  $t8, $t8, 0x78
  beql  $t8, $zero, .L7F0A35CC
   mfc1  $t8, $f6
  mtc1  $at, $f6
  li    $t8, 1
  sub.s $f6, $f4, $f6
  ctc1  $t8, $31
  nop   
  cvt.w.s $f6, $f6
  cfc1  $t8, $31
  nop   
  andi  $t8, $t8, 0x78
  bnez  $t8, .L7F0A35C0
   nop   
  mfc1  $t8, $f6
  lui   $at, 0x8000
  b     .L7F0A35D8
   or    $t8, $t8, $at
.L7F0A35C0:
  b     .L7F0A35D8
   li    $t8, -1
  mfc1  $t8, $f6
.L7F0A35CC:
  nop   
  bltz  $t8, .L7F0A35C0
   nop   
.L7F0A35D8:
  ctc1  $t7, $31
  sb    $t8, 0xc($s0)
  jal   cosf
   mov.s $f12, $f20
  mul.s $f8, $f0, $f28
  li    $t0, 1
  li    $at, 0x4F000000 # 2147483648.000000
  sub.s $f10, $f26, $f8
  cfc1  $t9, $31
  ctc1  $t0, $31
  nop   
  cvt.w.s $f16, $f10
  cfc1  $t0, $31
  nop   
  andi  $t0, $t0, 0x78
  beql  $t0, $zero, .L7F0A3664
   mfc1  $t0, $f16
  mtc1  $at, $f16
  li    $t0, 1
  sub.s $f16, $f10, $f16
  ctc1  $t0, $31
  nop   
  cvt.w.s $f16, $f16
  cfc1  $t0, $31
  nop   
  andi  $t0, $t0, 0x78
  bnez  $t0, .L7F0A3658
   nop   
  mfc1  $t0, $f16
  lui   $at, 0x8000
  b     .L7F0A3670
   or    $t0, $t0, $at
.L7F0A3658:
  b     .L7F0A3670
   li    $t0, -1
  mfc1  $t0, $f16
.L7F0A3664:
  nop   
  bltz  $t0, .L7F0A3658
   nop   
.L7F0A3670:
  ctc1  $t9, $31
  sb    $t0, 0xd($s0)
  jal   cosf
   mov.s $f12, $f20
  mul.s $f18, $f0, $f22
  li    $t2, 1
  li    $at, 0x4F000000 # 2147483648.000000
  sub.s $f4, $f22, $f18
  cfc1  $t1, $31
  ctc1  $t2, $31
  nop   
  cvt.w.s $f6, $f4
  cfc1  $t2, $31
  nop   
  andi  $t2, $t2, 0x78
  beql  $t2, $zero, .L7F0A36FC
   mfc1  $t2, $f6
  mtc1  $at, $f6
  li    $t2, 1
  sub.s $f6, $f4, $f6
  ctc1  $t2, $31
  nop   
  cvt.w.s $f6, $f6
  cfc1  $t2, $31
  nop   
  andi  $t2, $t2, 0x78
  bnez  $t2, .L7F0A36F0
   nop   
  mfc1  $t2, $f6
  lui   $at, 0x8000
  b     .L7F0A3708
   or    $t2, $t2, $at
.L7F0A36F0:
  b     .L7F0A3708
   li    $t2, -1
  mfc1  $t2, $f6
.L7F0A36FC:
  nop   
  bltz  $t2, .L7F0A36F0
   nop   
.L7F0A3708:
  ctc1  $t1, $31
  sb    $t2, 0xe($s0)
  sb    $s5, 0xf($s0)
  beqz  $s1, .L7F0A3924
   addiu $s0, $s0, 0x10
  slt   $at, $s1, $s6
  beqz  $at, .L7F0A3924
   li    $t3, 1
  subu  $t4, $t3, $s2
  negu  $t5, $s4
  sh    $t4, ($s0)
  sh    $zero, 2($s0)
  sh    $t5, 4($s0)
  sh    $zero, 6($s0)
  sh    $zero, 8($s0)
  sh    $zero, 0xa($s0)
  sb    $s3, 0xc($s0)
  sb    $s3, 0xd($s0)
  sb    $s3, 0xe($s0)
  jal   cosf
   mov.s $f12, $f20
  mul.s $f8, $f0, $f22
  li    $t7, 1
  li    $at, 0x4F000000 # 2147483648.000000
  sub.s $f10, $f22, $f8
  cfc1  $t6, $31
  ctc1  $t7, $31
  nop   
  cvt.w.s $f16, $f10
  cfc1  $t7, $31
  nop   
  andi  $t7, $t7, 0x78
  beql  $t7, $zero, .L7F0A37D8
   mfc1  $t7, $f16
  mtc1  $at, $f16
  li    $t7, 1
  sub.s $f16, $f10, $f16
  ctc1  $t7, $31
  nop   
  cvt.w.s $f16, $f16
  cfc1  $t7, $31
  nop   
  andi  $t7, $t7, 0x78
  bnez  $t7, .L7F0A37CC
   nop   
  mfc1  $t7, $f16
  lui   $at, 0x8000
  b     .L7F0A37E4
   or    $t7, $t7, $at
.L7F0A37CC:
  b     .L7F0A37E4
   li    $t7, -1
  mfc1  $t7, $f16
.L7F0A37D8:
  nop   
  bltz  $t7, .L7F0A37CC
   nop   
.L7F0A37E4:
  ctc1  $t6, $31
  sb    $t7, 0xc($s0)
  jal   cosf
   mov.s $f12, $f20
  mul.s $f18, $f0, $f28
  li    $t9, 1
  li    $at, 0x4F000000 # 2147483648.000000
  sub.s $f4, $f26, $f18
  cfc1  $t8, $31
  ctc1  $t9, $31
  nop   
  cvt.w.s $f6, $f4
  cfc1  $t9, $31
  nop   
  andi  $t9, $t9, 0x78
  beql  $t9, $zero, .L7F0A3870
   mfc1  $t9, $f6
  mtc1  $at, $f6
  li    $t9, 1
  sub.s $f6, $f4, $f6
  ctc1  $t9, $31
  nop   
  cvt.w.s $f6, $f6
  cfc1  $t9, $31
  nop   
  andi  $t9, $t9, 0x78
  bnez  $t9, .L7F0A3864
   nop   
  mfc1  $t9, $f6
  lui   $at, 0x8000
  b     .L7F0A387C
   or    $t9, $t9, $at
.L7F0A3864:
  b     .L7F0A387C
   li    $t9, -1
  mfc1  $t9, $f6
.L7F0A3870:
  nop   
  bltz  $t9, .L7F0A3864
   nop   
.L7F0A387C:
  ctc1  $t8, $31
  sb    $t9, 0xd($s0)
  jal   cosf
   mov.s $f12, $f20
  mul.s $f8, $f0, $f22
  li    $t1, 1
  li    $at, 0x4F000000 # 2147483648.000000
  sub.s $f10, $f22, $f8
  cfc1  $t0, $31
  ctc1  $t1, $31
  nop   
  cvt.w.s $f16, $f10
  cfc1  $t1, $31
  nop   
  andi  $t1, $t1, 0x78
  beql  $t1, $zero, .L7F0A3908
   mfc1  $t1, $f16
  mtc1  $at, $f16
  li    $t1, 1
  sub.s $f16, $f10, $f16
  ctc1  $t1, $31
  nop   
  cvt.w.s $f16, $f16
  cfc1  $t1, $31
  nop   
  andi  $t1, $t1, 0x78
  bnez  $t1, .L7F0A38FC
   nop   
  mfc1  $t1, $f16
  lui   $at, 0x8000
  b     .L7F0A3914
   or    $t1, $t1, $at
.L7F0A38FC:
  b     .L7F0A3914
   li    $t1, -1
  mfc1  $t1, $f16
.L7F0A3908:
  nop   
  bltz  $t1, .L7F0A38FC
   nop   
.L7F0A3914:
  ctc1  $t0, $31
  sb    $t1, 0xe($s0)
  sb    $s5, 0xf($s0)
  addiu $s0, $s0, 0x10
.L7F0A3924:
  addiu $s1, $s1, 2
  slt   $at, $s7, $s1
  beql  $at, $zero, .L7F0A34C4
   mtc1  $s1, $f6
.L7F0A3934:
  lw    $ra, 0x64($sp)
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
  lw    $s6, 0x5c($sp)
  lw    $s7, 0x60($sp)
  jr    $ra
   addiu $sp, $sp, 0x80
");

asm(R"
glabel sub_GAME_7F0A3978
  beqz  $a3, .L7F0A3A54
   sw    $a2, 8($sp)
  move  $v0, $a1
  move  $a2, $a0
  lui   $t1, (0x04300040 >> 16) # lui $t1, 0x430
  addiu $a1, $a1, 0x10
  addiu $a0, $a0, 8
  ori   $t1, (0x04300040 & 0xFFFF) # ori $t1, $t1, 0x40
  addiu $t6, $a1, 0xe0
  move  $a3, $a0
  lui   $t2, (0x04040010 >> 16) # lui $t2, 0x404
  sw    $t6, 4($a2)
  sw    $t1, ($a2)
  addiu $a0, $a0, 8
  ori   $t2, (0x04040010 & 0xFFFF) # ori $t2, $t2, 0x10
  move  $t0, $a0
  sw    $t2, ($a3)
  sw    $v0, 4($a3)
  lui   $t7, (0xB1000003 >> 16) # lui $t7, 0xb100
  ori   $t7, (0xB1000003 & 0xFFFF) # ori $t7, $t7, 3
  li    $t8, 66
  lui   $t3, (0xB1000042 >> 16) # lui $t3, 0xb100
  li    $v1, 7
  sw    $t8, 4($t0)
  sw    $t7, ($t0)
  addiu $a0, $a0, 8
  ori   $t3, (0xB1000042 & 0xFFFF) # ori $t3, $t3, 0x42
  li    $t4, 12608
.L7F0A39E8:
  move  $a2, $a0
  move  $t9, $v1
  sll   $t5, $t9, 5
  addiu $a0, $a0, 8
  addu  $t6, $t5, $a1
  move  $a3, $a0
  addiu $v1, $v1, -1
  sw    $t6, 4($a2)
  sw    $t1, ($a2)
  addiu $a0, $a0, 8
  sll   $t7, $v1, 0x18
  move  $t0, $a0
  sra   $v1, $t7, 0x18
  sw    $v0, 4($a3)
  sw    $t2, ($a3)
  sw    $t4, 4($t0)
  sw    $t3, ($t0)
  bgez  $v1, .L7F0A39E8
   addiu $a0, $a0, 8
  move  $v0, $a0
  lui   $t9, (0xB1000004 >> 16) # lui $t9, 0xb100
  ori   $t9, (0xB1000004 & 0xFFFF) # ori $t9, $t9, 4
  li    $t5, 16
  sw    $t5, 4($v0)
  sw    $t9, ($v0)
  b     .L7F0A3AA4
   addiu $a0, $a0, 8
.L7F0A3A54:
  lui   $t1, (0x04300040 >> 16) # lui $t1, 0x430
  lui   $a3, (0xB1000032 >> 16) # lui $a3, 0xb100
  ori   $a3, (0xB1000032 & 0xFFFF) # ori $a3, $a3, 0x32
  ori   $t1, (0x04300040 & 0xFFFF) # ori $t1, $t1, 0x40
  move  $v1, $zero
  li    $t0, 8464
.L7F0A3A6C:
  addiu $v1, $v1, 1
  move  $v0, $a0
  sll   $t6, $v1, 0x18
  addiu $a0, $a0, 8
  sra   $v1, $t6, 0x18
  sw    $a1, 4($v0)
  move  $a2, $a0
  slti  $at, $v1, 8
  sw    $t1, ($v0)
  sw    $t0, 4($a2)
  sw    $a3, ($a2)
  addiu $a0, $a0, 8
  bnez  $at, .L7F0A3A6C
   addiu $a1, $a1, 0x20
.L7F0A3AA4:
  lui   $t8, 0xb800
  sw    $t8, ($a0)
  addiu $v0, $a0, 8
  jr    $ra
   sw    $zero, 4($a0)
");

asm(R"
glabel sub_GAME_7F0A3AB8
  addiu $sp, $sp, -8
  lw    $t6, 0x1c($sp)
  sw    $s0, 4($sp)
  li    $s0, 2
  addu  $t0, $a1, $t6
  lw    $a1, 0x18($sp)
  lw    $t1, 0x20($sp)
  move  $v0, $zero
  li    $t5, 240
  li    $t4, 112
  li    $t3, 32
.L7F0A3AE4:
  move  $v1, $zero
  addu  $t2, $a2, $t1
.L7F0A3AEC:
  addiu $v1, $v1, 1
  sh    $t2, 4($a0)
  addu  $t2, $t2, $a1
  sh    $t0, ($a0)
  sh    $zero, 2($a0)
  sh    $zero, 6($a0)
  sh    $zero, 8($a0)
  sh    $zero, 0xa($a0)
  sb    $t3, 0xc($a0)
  sb    $t4, 0xd($a0)
  sb    $t3, 0xe($a0)
  sb    $t5, 0xf($a0)
  bne   $v1, $s0, .L7F0A3AEC
   addiu $a0, $a0, 0x10
  addiu $v0, $v0, 1
  bne   $v0, $s0, .L7F0A3AE4
   addu  $t0, $t0, $a3
  lw    $s0, 4($sp)
  addiu $sp, $sp, 8
  jr    $ra
   move  $v0, $a0
");

asm(R"
glabel sub_GAME_7F0A3B40
  lui   $t6, (0x04300040 >> 16) # lui $t6, 0x430
  ori   $t6, (0x04300040 & 0xFFFF) # ori $t6, $t6, 0x40
  addiu $a2, $a0, 8
  lui   $t7, (0xB1000032 >> 16) # lui $t7, 0xb100
  sw    $t6, ($a0)
  sw    $a1, 4($a0)
  ori   $t7, (0xB1000032 & 0xFFFF) # ori $t7, $t7, 0x32
  li    $t8, 8464
  sw    $t8, 4($a2)
  sw    $t7, ($a2)
  jr    $ra
   addiu $v0, $a2, 8
");

asm(R"
glabel sub_GAME_7F0A3B70
  lui   $t7, %hi(D_80040960) 
  addiu $t7, %lo(D_80040960) # addiu $t7, $t7, 0x960
  sll   $t6, $a0, 2
  addu  $v0, $t6, $t7
  lbu   $t8, ($v0)
  sb    $t8, ($a1)
  lbu   $t9, 1($v0)
  sb    $t9, 1($a1)
  lbu   $t0, 2($v0)
  sb    $t0, 2($a1)
  lbu   $t1, 3($v0)
  jr    $ra
   sb    $t1, 3($a1)
");

asm(R"
glabel sub_GAME_7F0A3BA4
  lbu   $t8, ($a1)
  lui   $t7, %hi(D_80040960) 
  addiu $t7, %lo(D_80040960) # addiu $t7, $t7, 0x960
  sll   $t6, $a0, 2
  addu  $v0, $t6, $t7
  sb    $t8, ($v0)
  lbu   $t9, 1($a1)
  sb    $t9, 1($v0)
  lbu   $t0, 2($a1)
  sb    $t0, 2($v0)
  lbu   $t1, 3($a1)
  jr    $ra
   sb    $t1, 3($v0)
");

asm(R"
glabel sub_GAME_7F0A3BD8
  lui   $v0, %hi(dword_CODE_bss_8007A170)
  lui   $v1, %hi(dword_CODE_bss_8007A4E0)
  addiu $v1, %lo(dword_CODE_bss_8007A4E0) # addiu $v1, $v1, -0x5b20
  addiu $v0, %lo(dword_CODE_bss_8007A170) # addiu $v0, $v0, -0x5e90
.L7F0A3BE8:
  addiu $v0, $v0, 0x2c
  sltu  $at, $v0, $v1
  sw    $zero, -0x20($v0)
  sh    $zero, -0x28($v0)
  bnez  $at, .L7F0A3BE8
   sw    $zero, -0x2c($v0)
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80057750
.word 0x40c90fdb /*6.2831855*/
glabel D_80057754
.word 0x3fb501e2 /*1.41412*/
.text
glabel sub_GAME_7F0A3C08
  addiu $sp, $sp, -0x30
  sdc1  $f20, 0x18($sp)
  mtc1  $a3, $f20
  sw    $ra, 0x24($sp)
  sw    $s0, 0x20($sp)
  move  $s0, $a0
  sw    $a1, 0x34($sp)
  jal   get_random_value
   sw    $a2, 0x38($sp)
  mtc1  $v0, $f4
  lw    $a1, 0x34($sp)
  lw    $a2, 0x38($sp)
  bgez  $v0, .L7F0A3C50
   cvt.s.w $f6, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F0A3C50:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f10
  lui   $at, %hi(D_80057750)
  lwc1  $f18, %lo(D_80057750)($at)
  mul.s $f16, $f6, $f10
  li    $at, 4
  li    $t7, 1
  mul.s $f4, $f16, $f18
  swc1  $f4, 0x2c($sp)
  sw    $zero, ($s0)
  lh    $t6, 0x42($sp)
  bne   $a2, $at, .L7F0A3CA4
   sh    $t6, 6($s0)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  sh    $t7, 4($s0)
  lui   $t8, %hi(flareimage2) 
  swc1  $f8, 8($s0)
  lw    $t8, %lo(flareimage2)($t8)
  b     .L7F0A3D44
   sw    $t8, 0xc($s0)
.L7F0A3CA4:
  li    $at, 1
  bne   $a2, $at, .L7F0A3CD0
   li    $t9, 11
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f6
  sh    $t9, 4($s0)
  lui   $t0, %hi(explosion_smokeimages) 
  swc1  $f6, 8($s0)
  lw    $t0, %lo(explosion_smokeimages)($t0)
  b     .L7F0A3D44
   sw    $t0, 0xc($s0)
.L7F0A3CD0:
  li    $at, 3
  bne   $a2, $at, .L7F0A3CFC
   li    $t1, 9
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f10
  sh    $t1, 4($s0)
  lui   $t2, %hi(scattered_explosions) 
  swc1  $f10, 8($s0)
  lw    $t2, %lo(scattered_explosions)($t2)
  b     .L7F0A3D44
   sw    $t2, 0xc($s0)
.L7F0A3CFC:
  li    $at, 6
  bne   $a2, $at, .L7F0A3D28
   li    $t5, 11
  mtc1  $zero, $f16
  li    $t3, 100
  sh    $t3, 4($s0)
  lui   $t4, %hi(flareimage2) 
  swc1  $f16, 8($s0)
  lw    $t4, %lo(flareimage2)($t4)
  b     .L7F0A3D44
   sw    $t4, 0xc($s0)
.L7F0A3D28:
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f18
  sh    $t5, 4($s0)
  lui   $t6, %hi(explosion_smokeimages) 
  swc1  $f18, 8($s0)
  lw    $t6, %lo(explosion_smokeimages)($t6)
  sw    $t6, 0xc($s0)
.L7F0A3D44:
  lui   $t8, %hi(D_80040960) 
  addiu $t8, %lo(D_80040960) # addiu $t8, $t8, 0x960
  sll   $t7, $a2, 2
  addu  $v0, $t7, $t8
  lbu   $t9, ($v0)
  sb    $t9, 0x28($s0)
  lbu   $t0, 1($v0)
  sb    $t0, 0x29($s0)
  lbu   $t1, 2($v0)
  sb    $t1, 0x2a($s0)
  lbu   $t2, 3($v0)
  sb    $t2, 0x2b($s0)
  lwc1  $f4, ($a1)
  swc1  $f4, 0x10($s0)
  lwc1  $f8, 4($a1)
  swc1  $f8, 0x14($s0)
  lwc1  $f6, 8($a1)
  jal   get_random_value
   swc1  $f6, 0x18($s0)
  mtc1  $v0, $f10
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F0A3DAC
   cvt.s.w $f16, $f10
  mtc1  $at, $f18
  nop   
  add.s $f16, $f16, $f18
.L7F0A3DAC:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f4
  li    $at, 0x3E800000 # 0.250000
  mtc1  $at, $f6
  mul.s $f8, $f16, $f4
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f18
  lui   $at, %hi(D_80057754)
  lwc1  $f4, %lo(D_80057754)($at)
  mul.s $f10, $f8, $f6
  add.s $f16, $f18, $f10
  mul.s $f20, $f20, $f16
  nop   
  mul.s $f20, $f20, $f4
  swc1  $f20, 0x24($s0)
  jal   cosf
   lwc1  $f12, 0x2c($sp)
  mul.s $f8, $f0, $f20
  swc1  $f8, 0x1c($s0)
  jal   sinf
   lwc1  $f12, 0x2c($sp)
  mul.s $f6, $f0, $f20
  swc1  $f6, 0x20($s0)
  lw    $ra, 0x24($sp)
  lw    $s0, 0x20($sp)
  ldc1  $f20, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x30
");

asm(R"
glabel sub_GAME_7F0A3E1C
  addiu $sp, $sp, -0x28
  sw    $s0, 0x20($sp)
  mtc1  $a2, $f12
  lui   $s0, %hi(dword_CODE_bss_8007A170)
  lui   $v0, %hi(dword_CODE_bss_8007A4E0)
  move  $a2, $a1
  sw    $ra, 0x24($sp)
  sw    $a0, 0x28($sp)
  sw    $a1, 0x2c($sp)
  sw    $a3, 0x34($sp)
  addiu $v0, %lo(dword_CODE_bss_8007A4E0) # addiu $v0, $v0, -0x5b20
  addiu $s0, %lo(dword_CODE_bss_8007A170) # addiu $s0, $s0, -0x5e90
  lh    $t6, 4($s0)
.L7F0A3E50:
  bnezl $t6, .L7F0A3E7C
   addiu $s0, $s0, 0x2c
  lh    $t7, 0x36($sp)
  mfc1  $a3, $f12
  move  $a0, $s0
  lw    $a1, 0x28($sp)
  jal   sub_GAME_7F0A3C08
   sw    $t7, 0x10($sp)
  b     .L7F0A3E8C
   move  $v0, $s0
  addiu $s0, $s0, 0x2c
.L7F0A3E7C:
  sltu  $at, $s0, $v0
  bnezl $at, .L7F0A3E50
   lh    $t6, 4($s0)
  move  $v0, $zero
.L7F0A3E8C:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0A3EA0
  lui   $v0, %hi(dword_CODE_bss_8007A170)
  lui   $v1, %hi(dword_CODE_bss_8007A4E0)
  lui   $a1, %hi(clock_timer)
  addiu $v1, %lo(dword_CODE_bss_8007A4E0) # addiu $v1, $v1, -0x5b20
  addiu $v0, %lo(dword_CODE_bss_8007A170) # addiu $v0, $v0, -0x5e90
  addiu $a1, %lo(clock_timer) # addiu $a1, $a1, -0x7c8c
  lh    $t6, 4($v0)
.L7F0A3EBC:
  blezl $t6, .L7F0A3EF0
   addiu $v0, $v0, 0x2c
  lw    $t7, ($v0)
  lw    $t8, ($a1)
  addu  $t9, $t7, $t8
  bltz  $t9, .L7F0A3EEC
   sw    $t9, ($v0)
  lh    $t0, 4($v0)
  slt   $at, $t9, $t0
  bnezl $at, .L7F0A3EF0
   addiu $v0, $v0, 0x2c
  sh    $zero, 4($v0)
.L7F0A3EEC:
  addiu $v0, $v0, 0x2c
.L7F0A3EF0:
  sltu  $at, $v0, $v1
  bnezl $at, .L7F0A3EBC
   lh    $t6, 4($v0)
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0A3F04
  addiu $sp, $sp, -0xb8
  sw    $ra, 0x2c($sp)
  sw    $s2, 0x28($sp)
  sw    $s1, 0x24($sp)
  sw    $s0, 0x20($sp)
  sw    $a1, 0xbc($sp)
  sw    $a2, 0xc0($sp)
  lh    $t6, 4($a0)
  move  $s0, $a0
  blezl $t6, .L7F0A4514
   lw    $ra, 0x2c($sp)
  lw    $t7, ($a0)
  addiu $a0, $a0, 0x10
  bltzl $t7, .L7F0A4514
   lw    $ra, 0x2c($sp)
  jal   sub_GAME_7F078A58
   lw    $a1, 0x24($s0)
  beqz  $v0, .L7F0A4510
   lui   $t9, %hi(D_80040980) 
  addiu $t9, %lo(D_80040980) # addiu $t9, $t9, 0x980
  lw    $at, ($t9)
  lw    $t1, 4($t9)
  addiu $t8, $sp, 0xa8
  sw    $at, ($t8)
  sw    $t1, 4($t8)
  lw    $t1, 0xc($t9)
  lw    $at, 8($t9)
  sw    $t1, 0xc($t8)
  jal   sub_GAME_7F078444
   sw    $at, 8($t8)
  lw    $t2, 0xbc($sp)
  li    $a0, 4
  lw    $t3, ($t2)
  sw    $v0, 0xa4($sp)
  jal   sub_GAME_7F0BD6C4
   sw    $t3, 0xa0($sp)
  lh    $a0, 6($s0)
  move  $s1, $v0
  jal   sub_GAME_7F0BCA14
   sw    $a0, 0x58($sp)
  lbu   $t4, 0x28($s0)
  lw    $v1, 0xa4($sp)
  move  $s2, $v0
  sb    $t4, 0xb4($sp)
  lbu   $t5, 0x29($s0)
  addiu $v0, $sp, 0xa8
  sb    $t5, 0xb5($sp)
  lbu   $t6, 0x2a($s0)
  sb    $t6, 0xb6($sp)
  lbu   $t7, 0x2b($s0)
  sb    $t7, 0xb7($sp)
  lw    $t0, ($s0)
  lwc1  $f8, 8($s0)
  mtc1  $t0, $f4
  nop   
  cvt.s.w $f6, $f4
  mul.s $f10, $f6, $f8
  trunc.w.s $f16, $f10
  mfc1  $t9, $f16
  nop   
  sw    $t9, 0x5c($sp)
  lwc1  $f18, 0x10($s0)
  swc1  $f18, 0x90($sp)
  lwc1  $f4, 0x14($s0)
  swc1  $f4, 0x94($sp)
  lwc1  $f6, 0x18($s0)
  swc1  $f6, 0x98($sp)
  lwc1  $f10, 0x1c($s0)
  lwc1  $f8, ($v1)
  mul.s $f16, $f8, $f10
  swc1  $f16, 0x84($sp)
  lwc1  $f4, 0x1c($s0)
  lwc1  $f18, 4($v1)
  mul.s $f6, $f18, $f4
  swc1  $f6, 0x88($sp)
  lwc1  $f10, 0x1c($s0)
  lwc1  $f8, 8($v1)
  mul.s $f16, $f8, $f10
  swc1  $f16, 0x8c($sp)
  lwc1  $f4, 0x20($s0)
  lwc1  $f18, ($v1)
  mul.s $f6, $f18, $f4
  swc1  $f6, 0x78($sp)
  lwc1  $f10, 0x20($s0)
  lwc1  $f8, 4($v1)
  mul.s $f16, $f8, $f10
  swc1  $f16, 0x7c($sp)
  lwc1  $f4, 0x20($s0)
  lwc1  $f18, 8($v1)
  mul.s $f6, $f18, $f4
  swc1  $f6, 0x80($sp)
  lwc1  $f10, 0x1c($s0)
  lwc1  $f8, 0x10($v1)
  mul.s $f16, $f8, $f10
  swc1  $f16, 0x6c($sp)
  lwc1  $f4, 0x1c($s0)
  lwc1  $f18, 0x14($v1)
  mul.s $f6, $f18, $f4
  swc1  $f6, 0x70($sp)
  lwc1  $f10, 0x1c($s0)
  lwc1  $f8, 0x18($v1)
  mul.s $f16, $f8, $f10
  swc1  $f16, 0x74($sp)
  lwc1  $f4, 0x20($s0)
  lwc1  $f18, 0x10($v1)
  mul.s $f6, $f18, $f4
  swc1  $f6, 0x60($sp)
  lwc1  $f10, 0x20($s0)
  lwc1  $f8, 0x14($v1)
  mul.s $f16, $f8, $f10
  swc1  $f16, 0x64($sp)
  lwc1  $f4, 0x20($s0)
  lwc1  $f18, 0x18($v1)
  mul.s $f6, $f18, $f4
  swc1  $f6, 0x68($sp)
  lw    $at, ($v0)
  sw    $at, ($s1)
  lw    $t3, 4($v0)
  sw    $t3, 4($s1)
  lw    $at, 8($v0)
  sw    $at, 8($s1)
  lw    $t3, 0xc($v0)
  sw    $t3, 0xc($s1)
  lw    $at, ($v0)
  sw    $at, 0x10($s1)
  lw    $t6, 4($v0)
  sw    $t6, 0x14($s1)
  lw    $at, 8($v0)
  sw    $at, 0x18($s1)
  lw    $t6, 0xc($v0)
  sw    $t6, 0x1c($s1)
  lw    $at, ($v0)
  sw    $at, 0x20($s1)
  lw    $t8, 4($v0)
  sw    $t8, 0x24($s1)
  lw    $at, 8($v0)
  sw    $at, 0x28($s1)
  lw    $t8, 0xc($v0)
  sw    $t8, 0x2c($s1)
  lw    $at, ($v0)
  sw    $at, 0x30($s1)
  lw    $t1, 4($v0)
  sw    $t1, 0x34($s1)
  lw    $at, 8($v0)
  sw    $at, 0x38($s1)
  lw    $t1, 0xc($v0)
  jal   get_room_data_float1
   sw    $t1, 0x3c($s1)
  lwc1  $f8, 0x90($sp)
  lwc1  $f10, 0x84($sp)
  lwc1  $f18, 0x60($sp)
  sub.s $f16, $f8, $f10
  lwc1  $f8, ($s2)
  sub.s $f4, $f16, $f18
  mul.s $f6, $f4, $f0
  sub.s $f10, $f6, $f8
  trunc.w.s $f16, $f10
  mfc1  $t5, $f16
  jal   get_room_data_float1
   sh    $t5, ($s1)
  lwc1  $f18, 0x94($sp)
  lwc1  $f4, 0x88($sp)
  lwc1  $f8, 0x64($sp)
  sub.s $f6, $f18, $f4
  lwc1  $f18, 4($s2)
  sub.s $f10, $f6, $f8
  mul.s $f16, $f10, $f0
  sub.s $f4, $f16, $f18
  trunc.w.s $f6, $f4
  mfc1  $t6, $f6
  jal   get_room_data_float1
   sh    $t6, 2($s1)
  lwc1  $f8, 0x98($sp)
  lwc1  $f10, 0x8c($sp)
  lwc1  $f18, 0x68($sp)
  sub.s $f16, $f8, $f10
  lwc1  $f8, 8($s2)
  sub.s $f4, $f16, $f18
  mul.s $f6, $f4, $f0
  sub.s $f10, $f6, $f8
  trunc.w.s $f16, $f10
  mfc1  $t7, $f16
  nop   
  sh    $t7, 4($s1)
  lw    $v0, 0x5c($sp)
  lw    $t2, 0xc($s0)
  sll   $t8, $v0, 2
  subu  $t8, $t8, $v0
  sll   $t8, $t8, 2
  addu  $t9, $t2, $t8
  lbu   $t1, 4($t9)
  sh    $zero, 0xa($s1)
  sll   $t3, $t1, 5
  sh    $t3, 8($s1)
  jal   get_room_data_float1
   sw    $t8, 0x34($sp)
  lwc1  $f18, 0x90($sp)
  lwc1  $f4, 0x78($sp)
  lwc1  $f8, 0x6c($sp)
  add.s $f6, $f18, $f4
  lwc1  $f18, ($s2)
  sub.s $f10, $f6, $f8
  mul.s $f16, $f10, $f0
  sub.s $f4, $f16, $f18
  trunc.w.s $f6, $f4
  mfc1  $t4, $f6
  jal   get_room_data_float1
   sh    $t4, 0x10($s1)
  lwc1  $f8, 0x94($sp)
  lwc1  $f10, 0x7c($sp)
  lwc1  $f18, 0x70($sp)
  add.s $f16, $f8, $f10
  lwc1  $f8, 4($s2)
  sub.s $f4, $f16, $f18
  mul.s $f6, $f4, $f0
  sub.s $f10, $f6, $f8
  trunc.w.s $f16, $f10
  mfc1  $t0, $f16
  jal   get_room_data_float1
   sh    $t0, 0x12($s1)
  lwc1  $f18, 0x98($sp)
  lwc1  $f4, 0x80($sp)
  lwc1  $f8, 0x74($sp)
  add.s $f6, $f18, $f4
  lwc1  $f18, 8($s2)
  sh    $zero, 0x18($s1)
  sh    $zero, 0x1a($s1)
  sub.s $f10, $f6, $f8
  mul.s $f16, $f10, $f0
  sub.s $f4, $f16, $f18
  trunc.w.s $f6, $f4
  mfc1  $t8, $f6
  jal   get_room_data_float1
   sh    $t8, 0x14($s1)
  lwc1  $f8, 0x90($sp)
  lwc1  $f10, 0x84($sp)
  lwc1  $f18, 0x60($sp)
  add.s $f16, $f8, $f10
  lwc1  $f8, ($s2)
  add.s $f4, $f16, $f18
  mul.s $f6, $f4, $f0
  sub.s $f10, $f6, $f8
  trunc.w.s $f16, $f10
  mfc1  $t9, $f16
  jal   get_room_data_float1
   sh    $t9, 0x20($s1)
  lwc1  $f18, 0x94($sp)
  lwc1  $f4, 0x88($sp)
  lwc1  $f8, 0x64($sp)
  add.s $f6, $f18, $f4
  lwc1  $f18, 4($s2)
  add.s $f10, $f6, $f8
  mul.s $f16, $f10, $f0
  sub.s $f4, $f16, $f18
  trunc.w.s $f6, $f4
  mfc1  $t3, $f6
  jal   get_room_data_float1
   sh    $t3, 0x22($s1)
  lwc1  $f8, 0x98($sp)
  lwc1  $f10, 0x8c($sp)
  lwc1  $f18, 0x68($sp)
  add.s $f16, $f8, $f10
  lwc1  $f8, 8($s2)
  sh    $zero, 0x28($s1)
  add.s $f4, $f16, $f18
  mul.s $f6, $f4, $f0
  sub.s $f10, $f6, $f8
  trunc.w.s $f16, $f10
  mfc1  $t4, $f16
  nop   
  sh    $t4, 0x24($s1)
  lw    $t0, 0x34($sp)
  lw    $t6, 0xc($s0)
  addu  $t7, $t6, $t0
  lbu   $t8, 5($t7)
  sll   $t2, $t8, 5
  jal   get_room_data_float1
   sh    $t2, 0x2a($s1)
  lwc1  $f18, 0x90($sp)
  lwc1  $f4, 0x78($sp)
  lwc1  $f8, 0x6c($sp)
  sub.s $f6, $f18, $f4
  lwc1  $f18, ($s2)
  add.s $f10, $f6, $f8
  mul.s $f16, $f10, $f0
  sub.s $f4, $f16, $f18
  trunc.w.s $f6, $f4
  mfc1  $t1, $f6
  jal   get_room_data_float1
   sh    $t1, 0x30($s1)
  lwc1  $f8, 0x94($sp)
  lwc1  $f10, 0x7c($sp)
  lwc1  $f18, 0x70($sp)
  sub.s $f16, $f8, $f10
  lwc1  $f8, 4($s2)
  add.s $f4, $f16, $f18
  mul.s $f6, $f4, $f0
  sub.s $f10, $f6, $f8
  trunc.w.s $f16, $f10
  mfc1  $t5, $f16
  jal   get_room_data_float1
   sh    $t5, 0x32($s1)
  lwc1  $f18, 0x98($sp)
  lwc1  $f4, 0x80($sp)
  lwc1  $f8, 0x74($sp)
  lw    $a0, 0x34($sp)
  sub.s $f6, $f18, $f4
  lwc1  $f18, 8($s2)
  add.s $f10, $f6, $f8
  mul.s $f16, $f10, $f0
  sub.s $f4, $f16, $f18
  trunc.w.s $f6, $f4
  mfc1  $t6, $f6
  nop   
  sh    $t6, 0x34($s1)
  lw    $t0, 0xc($s0)
  addu  $t7, $t0, $a0
  lbu   $t8, 4($t7)
  li    $t7, 8192
  lui   $t0, 0xb700
  sll   $t2, $t8, 5
  sh    $t2, 0x38($s1)
  lw    $t9, 0xc($s0)
  addu  $t1, $t9, $a0
  lbu   $t3, 5($t1)
  lui   $t9, (0x01030040 >> 16) # lui $t9, 0x103
  ori   $t9, (0x01030040 & 0xFFFF) # ori $t9, $t9, 0x40
  sll   $t5, $t3, 5
  sh    $t5, 0x3a($s1)
  lw    $t4, 0xa0($sp)
  addiu $t6, $t4, 8
  sw    $t6, 0xa0($sp)
  sw    $t7, 4($t4)
  sw    $t0, ($t4)
  lw    $t8, 0xa0($sp)
  addiu $t2, $t8, 8
  sw    $t2, 0xa0($sp)
  sw    $t9, ($t8)
  jal   get_BONDdata_field_10E0
   sw    $t8, 0x4c($sp)
  jal   osVirtualToPhysical
   move  $a0, $v0
  lw    $t1, 0x4c($sp)
  sw    $v0, 4($t1)
  lw    $a1, 0x58($sp)
  jal   sub_GAME_7F0BC9C4
   lw    $a0, 0xa0($sp)
  sw    $v0, 0xa0($sp)
  lw    $t3, 0xc($s0)
  lw    $t5, 0x34($sp)
  li    $t4, 2
  sw    $t4, 0x10($sp)
  addiu $a0, $sp, 0xa0
  li    $a2, 4
  lw    $a3, 0xc0($sp)
  jal   likely_generate_DL_for_image_declaration
   addu  $a1, $t3, $t5
  lw    $s0, 0xa0($sp)
  lui   $t7, (0x04300040 >> 16) # lui $t7, 0x430
  ori   $t7, (0x04300040 & 0xFFFF) # ori $t7, $t7, 0x40
  addiu $t0, $s0, 8
  sw    $t0, 0xa0($sp)
  move  $a0, $s1
  jal   osVirtualToPhysical
   sw    $t7, ($s0)
  sw    $v0, 4($s0)
  lw    $t8, 0xa0($sp)
  lui   $t9, (0xB1000032 >> 16) # lui $t9, 0xb100
  ori   $t9, (0xB1000032 & 0xFFFF) # ori $t9, $t9, 0x32
  addiu $t2, $t8, 8
  sw    $t2, 0xa0($sp)
  li    $t1, 8208
  sw    $t1, 4($t8)
  sw    $t9, ($t8)
  lw    $s1, 0xa0($sp)
  lui   $t4, (0x01030040 >> 16) # lui $t4, 0x103
  ori   $t4, (0x01030040 & 0xFFFF) # ori $t4, $t4, 0x40
  addiu $t5, $s1, 8
  sw    $t5, 0xa0($sp)
  jal   get_BONDdata_field_10D8
   sw    $t4, ($s1)
  jal   osVirtualToPhysical
   move  $a0, $v0
  sw    $v0, 4($s1)
  lw    $t0, 0xbc($sp)
  lw    $t6, 0xa0($sp)
  sw    $t6, ($t0)
.L7F0A4510:
  lw    $ra, 0x2c($sp)
.L7F0A4514:
  lw    $s0, 0x20($sp)
  lw    $s1, 0x24($sp)
  lw    $s2, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0xb8
");

asm(R"
glabel sub_GAME_7F0A4528
  addiu $sp, $sp, -0x28
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  lui   $s0, %hi(dword_CODE_bss_8007A170)
  lui   $s1, %hi(dword_CODE_bss_8007A4E0)
  move  $s2, $a0
  move  $s3, $a1
  sw    $ra, 0x24($sp)
  addiu $s1, %lo(dword_CODE_bss_8007A4E0) # addiu $s1, $s1, -0x5b20
  addiu $s0, %lo(dword_CODE_bss_8007A170) # addiu $s0, $s0, -0x5e90
  move  $a0, $s0
.L7F0A455C:
  move  $a1, $s2
  jal   sub_GAME_7F0A3F04
   move  $a2, $s3
  addiu $s0, $s0, 0x2c
  sltu  $at, $s0, $s1
  bnezl $at, .L7F0A455C
   move  $a0, $s0
  lw    $ra, 0x24($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
glabel sub_GAME_7F0A4594
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  lwc1  $f4, 0x10($a0)
  swc1  $f4, 0x1c($sp)
  lwc1  $f6, 0x14($a0)
  swc1  $f6, 0x20($sp)
  lwc1  $f8, 0x18($a0)
  jal   get_BONDdata_field_10CC
   swc1  $f8, 0x24($sp)
  move  $a0, $v0
  jal   sub_GAME_7F058474
   addiu $a1, $sp, 0x1c
  lw    $ra, 0x14($sp)
  lwc1  $f0, 0x24($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   neg.s $f0, $f0
");

asm(R"
glabel sub_GAME_7F0A45D8
  lui   $v0, %hi(dword_CODE_bss_8007A4E0)
  lui   $v1, %hi(dword_CODE_bss_8007B098)
  addiu $v1, %lo(dword_CODE_bss_8007B098) # addiu $v1, $v1, -0x4f68
  addiu $v0, %lo(dword_CODE_bss_8007A4E0) # addiu $v0, $v0, -0x5b20
.L7F0A45E8:
  addiu $v0, $v0, 0x3c
  sltu  $at, $v0, $v1
  bnez  $at, .L7F0A45E8
   sh    $zero, -0x38($v0)
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0A4600
  addiu $sp, $sp, -0x28
  sw    $s0, 0x20($sp)
  lui   $s0, %hi(dword_CODE_bss_8007A4E0)
  lui   $v0, %hi(dword_CODE_bss_8007B098)
  mtc1  $a3, $f12
  sw    $ra, 0x24($sp)
  sw    $a0, 0x28($sp)
  sw    $a1, 0x2c($sp)
  addiu $v0, %lo(dword_CODE_bss_8007B098) # addiu $v0, $v0, -0x4f68
  addiu $s0, %lo(dword_CODE_bss_8007A4E0) # addiu $s0, $s0, -0x5b20
  lh    $t6, 4($s0)
.L7F0A462C:
  bnezl $t6, .L7F0A467C
   addiu $s0, $s0, 0x3c
  lh    $t7, 0x3e($sp)
  mfc1  $a3, $f12
  move  $a0, $s0
  lw    $a1, 0x28($sp)
  jal   sub_GAME_7F0A3C08
   sw    $t7, 0x10($sp)
  lw    $v1, 0x2c($sp)
  move  $v0, $s0
  lwc1  $f4, ($v1)
  swc1  $f4, 0x2c($s0)
  lwc1  $f6, 4($v1)
  swc1  $f6, 0x30($s0)
  lwc1  $f8, 8($v1)
  swc1  $f8, 0x34($s0)
  lwc1  $f10, 0x38($sp)
  b     .L7F0A468C
   swc1  $f10, 0x38($s0)
  addiu $s0, $s0, 0x3c
.L7F0A467C:
  sltu  $at, $s0, $v0
  bnezl $at, .L7F0A462C
   lh    $t6, 4($s0)
  move  $v0, $zero
.L7F0A468C:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0A46A0
  addiu $sp, $sp, -0x28
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  lui   $s0, %hi(dword_CODE_bss_8007A4E0)
  lui   $s3, %hi(dword_CODE_bss_8007B098)
  lui   $s1, %hi(clock_timer)
  lui   $s2, %hi(global_timer_delta)
  sw    $ra, 0x24($sp)
  addiu $s3, %lo(dword_CODE_bss_8007B098) # addiu $s3, $s3, -0x4f68
  addiu $s0, %lo(dword_CODE_bss_8007A4E0) # addiu $s0, $s0, -0x5b20
  addiu $s2, %lo(global_timer_delta) # addiu $s2, $s2, -0x7c88
  addiu $s1, %lo(clock_timer) # addiu $s1, $s1, -0x7c8c
  lh    $t6, 4($s0)
.L7F0A46DC:
  blezl $t6, .L7F0A4740
   addiu $s0, $s0, 0x3c
  lw    $t7, ($s0)
  lw    $t8, ($s1)
  addu  $t9, $t7, $t8
  bltz  $t9, .L7F0A473C
   sw    $t9, ($s0)
  lh    $t0, 4($s0)
  addiu $a0, $s0, 0x10
  addiu $a1, $s0, 0x2c
  slt   $at, $t9, $t0
  beql  $at, $zero, .L7F0A473C
   sh    $zero, 4($s0)
  jal   sub_GAME_7F057D88
   lw    $a2, ($s2)
  lwc1  $f4, 0x14($s0)
  lwc1  $f6, 0x38($s0)
  c.lt.s $f4, $f6
  nop   
  bc1fl .L7F0A4740
   addiu $s0, $s0, 0x3c
  b     .L7F0A473C
   sh    $zero, 4($s0)
  sh    $zero, 4($s0)
.L7F0A473C:
  addiu $s0, $s0, 0x3c
.L7F0A4740:
  sltu  $at, $s0, $s3
  bnezl $at, .L7F0A46DC
   lh    $t6, 4($s0)
  lw    $ra, 0x24($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
glabel sub_GAME_7F0A4768
  addiu $sp, $sp, -0x28
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  lui   $s0, %hi(dword_CODE_bss_8007A4E0)
  lui   $s1, %hi(dword_CODE_bss_8007B098)
  move  $s2, $a0
  move  $s3, $a1
  sw    $ra, 0x24($sp)
  addiu $s1, %lo(dword_CODE_bss_8007B098) # addiu $s1, $s1, -0x4f68
  addiu $s0, %lo(dword_CODE_bss_8007A4E0) # addiu $s0, $s0, -0x5b20
  move  $a0, $s0
.L7F0A479C:
  move  $a1, $s2
  jal   sub_GAME_7F0A3F04
   move  $a2, $s3
  addiu $s0, $s0, 0x3c
  sltu  $at, $s0, $s1
  bnezl $at, .L7F0A479C
   move  $a0, $s0
  lw    $ra, 0x24($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

void sub_GAME_7F0A47D4(void) {
  sub_GAME_7F0A3BD8();
  sub_GAME_7F0A45D8();
}

void sub_GAME_7F0A47FC(void) {
  sub_GAME_7F0A3EA0();
  sub_GAME_7F0A46A0();
}

asm(R"
glabel sub_GAME_7F0A4824
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  jal   sub_GAME_7F0A4528
   sw    $a1, 0x1c($sp)
  lw    $a0, 0x18($sp)
  jal   sub_GAME_7F0A4768
   lw    $a1, 0x1c($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");
