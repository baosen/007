char dword_CODE_bss_8007A100[0x40];
unsigned int *ptr_smoke_buf, *ptr_explosion_buf;
int max_casings;
unsigned int *ptr_ejected_casing_buf, *ptr_scorch_buf, *ptr_bullet_impact_buf;

int D_80040170 = 0;
int D_80040174 = 0;
float D_80040178 = 1.0;
unsigned int D_8004017C[] = {
    0x1003C,    0x630000,   0,          0x80808000, 0x3E99999A, 0xB40000,
    0x1E0003C,  0x2D003C,   0x3CA3D70A, 0x50506000, 0x3E99999A, 0xB40000,
    0x1E0003C,  0x320014,   0x3C23D70A, 0x80808000, 0x3E99999A, 0xB40000,
    0x280003C,  0x780064,   0x3C23D70A, 0xC0C0C000, 0x3E99999A, 0xB40000,
    0x280003C,  0x3C0050,   0x3CA3D70A, 0x40404000, 0x3E99999A, 0xB40000,
    0x302003C,  0x3200BE,   0x3E19999A, 0x40404000, 0x3E99999A, 0xB40000,
    0x384003C,  0x46012C,   0x3C23D70A, 0x40404000, 0x3E99999A, 0xB40000,
    0x3C003C,   0x8000F,    0x3CF5C28F, 0xFFFFFF00, 0x3E99999A, 0xB40000,
    0x140001,   0x6001E,    0x3CF5C28F, 0xFFFFFF00, 0x40000000, 0x1E0000,
    0x190001,   0x70010,    0x3CF5C28F, 0xE0E0E000, 0x40400000, 0x1E0000,
    0x384003C,  0x460384,   0x3C23D70A, 0x40404000, 0x3E99999A, 0xB40000,
    0x3DCCCCCD, 0x3DCCCCCD, 0,          0,          0x3DCCCCCD, 0,
    0,          0x10001,    0x3F800000, 0,          0x3DCCCCCD, 0,
    0,          0,          0,          0,          0x3F800000, 0x3F800000,
    0,          0,          0x3F800000, 0,          0,          0x1E0001,
    0x3F800000, 0xA0000,    0x40A00000, 0,          0x40000000, 0x40C00000,
    0x7000000,  0,          0x41A00000, 0x41A00000, 0,          0,
    0x41F00000, 0x42480000, 0x42480000, 0x500001,   0x40400000, 0x280000,
    0x40C00000, 0x40A00000, 0x3F333333, 0x40C00000, 0x2B50000,  0x3E000000,
    0x42480000, 0x42480000, 0,          0,          0x42480000, 0x42C80000,
    0x42C80000, 0x5A0001,   0x40800000, 0x320000,   0x40C00000, 0x41200000,
    0x3F800000, 0x40C00000, 0x2B60000,  0x3F000000, 0x42700000, 0x42A00000,
    0x3F800000, 0x3E99999A, 0x42C80000, 0x43160000, 0x438C0000, 0x780002,
    0x40A00000, 0x500000,   0x41000000, 0x41F00000, 0x40000000, 0x40C00000,
    0x1AC0000,  0x3F800000, 0x42700000, 0x42F00000, 0x3F800000, 0x3E99999A,
    0x43160000, 0x43480000, 0x439B0000, 0x780002,   0x40A00000, 0x500000,
    0x41000000, 0x41F00000, 0x40000000, 0x40C00000, 0x1AC0000,  0x40000000,
    0x41A00000, 0x41A00000, 0,          0,          0x41B00000, 0x42200000,
    0x42200000, 0x500001,   0x40400000, 0x280000,   0x40C00000, 0x40A00000,
    0x3F333333, 0x40C00000, 0x2B50000,  0x3F000000, 0x420C0000, 0x42200000,
    0,          0,          0x420C0000, 0x428C0000, 0x428C0000, 0x5A0001,
    0x40800000, 0x320000,   0x40C00000, 0x41200000, 0x3F800000, 0x40C00000,
    0x2B60000,  0x3F800000, 0x42480000, 0x42A00000, 0x3F800000, 0x3E99999A,
    0x42480000, 0x42C80000, 0x435C0000, 0x780002,   0x40A00000, 0x500000,
    0x41000000, 0x41F00000, 0x40000000, 0x40C00000, 0x1AC0000,  0x40000000,
    0x42700000, 0x42F00000, 0x3F800000, 0x3E99999A, 0x42480000, 0x43020000,
    0x43660000, 0x780002,   0x40A00000, 0x500000,   0x41000000, 0x41F00000,
    0x40000000, 0x40C00000, 0x1AC0000,  0x40000000, 0x42200000, 0x42200000,
    0x3ECCCCCD, 0x3E4CCCCD, 0x428C0000, 0x42C80000, 0x43340000, 0xAA0004,
    0x40A00000, 0x780000,   0x40C00000, 0x41F00000, 0x40200000, 0x40C00000,
    0x4AE0000,  0x3F800000, 0x42480000, 0x42480000, 0x3F19999A, 0x3ECCCCCD,
    0x42C80000, 0x43160000, 0x43820000, 0xB40001,   0x40800000, 0x960000,
    0x40C00000, 0x41F00000, 0x40400000, 0x40C00000, 0x4AC0000,  0x40000000,
    0x428C0000, 0x42700000, 0x3F800000, 0x3F19999A, 0x43160000, 0x43610000,
    0x43A00000, 0xB40002,   0x40A00000, 0x960000,   0x40C00000, 0x41F00000,
    0x40800000, 0x41400000, 0x5AC0000,  0x40800000, 0x42A00000, 0x42700000,
    0x40000000, 0x3F333333, 0x43480000, 0x43960000, 0x43F00000, 0xB40002,
    0x40A00000, 0xC80000,   0x40C00000, 0x41F00000, 0x40C00000, 0x41700000,
    0x6AD0000,  0x40800000, 0x42480000, 0x42480000, 0,          0,
    0x42F00000, 0x43480000, 0x43C80000, 0x960004,   0x40800000, 0x960000,
    0x40C00000, 0x41F00000, 0x40400000, 0x40C00000, 0x4AD0000,  0x40800000,
    0x3F800000, 0x3F800000, 0,          0,          0x3F800000, 0,
    0,          0x10001,    0x3F800000, 0x960000,   0x40C00000, 0x41F00000,
    0x40200000, 0x40C00000, 0x7AA0000,  0,          0x3F800000, 0x3F800000,
    0,          0,          0x3F800000, 0,          0,          0x10001,
    0x3F800000, 0x640000,   0x40C00000, 0x41F00000, 0x40200000, 0x40C00000,
    0x7AA0000,  0,          0x42A00000, 0x42700000, 0x41700000, 0x40A00000,
    0x44BB8000, 0x45098000, 0x45610000, 0x12C0001,  0x40000000, 0,
    0,          0,          0,          0,          0xAD0000,   0x40800000,
    0x42A00000, 0x42700000, 0x40400000, 0x3F800000, 0x43960000, 0x43E10000,
    0x44200000, 0x3C0001,   0x40000000, 0,          0,          0,
    0,          0,          0xAD0000,   0x40800000, 0x42B40000, 0x42960000,
    0x40200000, 0x3F5EB852, 0x437A0000, 0x43BB8000, 0x44160000, 0xB40002,
    0x40A00000, 0xC80000,   0x40C00000, 0x41F00000, 0x40C00000, 0x41700000,
    0x6AD0000,  0x40800000, 0x43200000, 0x42F00000, 0x40C00000, 0x40000000,
    0x44160000, 0x43E10000, 0x44200000, 0x3C0001,   0x40000000, 0,
    0,          0,          0,          0,          0xAD0000,   0x40800000,
    0x2000078,  0x2000120,  0x20001C8,  0x2000270,  0x2000318,  0x20003C0,
    0x2000468,  0x2000510,  0x20005B8,  0x2000660,  0x2000708,  0x20007B0,
    0x2000858,  0x2000900,  0x20009A8,  0,          0,          0};
unsigned int D_8004080C[] = {
    0x41200000, 0x41200000, 0x1020800, 0x40C00000, 0x40C00000, 0x1020800,
    0x41000000, 0x41000000, 0x20800,   0x41A00000, 0x41A00000, 0x1020800,
    0x40C00000, 0x40C00000, 0x1020800, 0x41000000, 0x41000000, 0x1020800,
    0x41400000, 0x41400000, 0x1020800, 0x40C00000, 0x40C00000, 0x1020800,
    0x41A00000, 0x41A00000, 0x1020800, 0x41A00000, 0x41A00000, 0x1020800,
    0x41A00000, 0x41A00000, 0x1020800, 0x41A00000, 0x41A00000, 0x1020800,
    0x41A00000, 0x41A00000, 0x1020800, 0x41C00000, 0x41C00000, 0x1020800,
    0x40C00000, 0x40C00000, 0x1020100, 0x40C00000, 0x40C00000, 0x1020100,
    0x41C00000, 0x41C00000, 0x2020800, 0x40C00000, 0x40C00000, 0x1020100,
    0x41000000, 0x41000000, 0x1020100, 0x41400000, 0x41400000, 0x1020100,
    0,          0,          0,         0};

unsigned int D_8004090C = 0xFFFFFFFF;
unsigned int D_80040910 = 0;
unsigned int D_80040914 = 0;
unsigned int D_80040918 = 0;
unsigned int D_8004091C = 0;
unsigned int D_80040920 = 0;
unsigned int D_80040924 = 0;
unsigned int D_80040928 = 0;
unsigned int D_8004092C = 0xDC;
unsigned int D_80040930 = 0;
unsigned int D_80040934 = 0;
unsigned int D_80040938 = 0;
unsigned int D_8004093C = 0xDC;

#ifdef VERSION_US
asm(R"
.late_rodata
glabel D_800576B0
.word 0x497423fe /*999999.88*/
glabel D_800576B4
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F09C250
  addiu $sp, $sp, -0x48
  sll   $t6, $a3, 0x10
  sra   $t7, $t6, 0x10
  lui   $t9, %hi(D_8004017C+0x108) 
  sw    $s1, 0x20($sp)
  addiu $t9, %lo(D_8004017C+0x108) # addiu $t9, $t9, 0x284
  sll   $t8, $t7, 6
  sw    $s3, 0x28($sp)
  sw    $a3, 0x54($sp)
  addu  $s1, $t8, $t9
  li    $at, 16
  move  $a3, $t7
  move  $s3, $a1
  sw    $ra, 0x2c($sp)
  sw    $s2, 0x24($sp)
  sw    $s0, 0x1c($sp)
  sw    $a0, 0x48($sp)
  sw    $a2, 0x50($sp)
  sw    $s1, 0x44($sp)
  beq   $t7, $at, .L7F09C2B8
   move  $t0, $zero
  li    $at, 1
  beq   $t7, $at, .L7F09C2B8
   li    $t6, 6
  lui   $at, %hi(D_80040170)
  sw    $t6, %lo(D_80040170)($at)
.L7F09C2B8:
  lui   $a0, %hi(ptr_explosion_buf)
  lw    $a0, %lo(ptr_explosion_buf)($a0)
  move  $v0, $zero
  move  $v1, $a0
.L7F09C2C8:
  lw    $t7, ($v1)
  bnezl $t7, .L7F09C2E0
   addiu $v0, $v0, 0x3e0
  b     .L7F09C2EC
   addu  $t0, $v0, $a0
  addiu $v0, $v0, 0x3e0
.L7F09C2E0:
  slti  $at, $v0, 0x1740
  bnez  $at, .L7F09C2C8
   addiu $v1, $v1, 0x3e0
.L7F09C2EC:
  beql  $t0, $zero, .L7F09C794
   lw    $ra, 0x2c($sp)
  sh    $a3, 0x56($sp)
  jal   remove_last_obj_pos_data_entry
   sw    $t0, 0x40($sp)
  lbu   $v1, 0x39($s1)
  lw    $t0, 0x40($sp)
  move  $a3, $v0
  blez  $v1, .L7F09C348
   lui   $a0, %hi(ptr_sfx_buf)
  sll   $a1, $v1, 0x10
  sra   $t8, $a1, 0x10
  move  $a1, $t8
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  move  $a2, $zero
  sw    $v0, 0x30($sp)
  jal   play_sfx_a1
   sw    $t0, 0x40($sp)
  move  $a0, $v0
  jal   sub_GAME_7F053A10
   move  $a1, $s3
  lw    $a3, 0x30($sp)
  lw    $t0, 0x40($sp)
.L7F09C348:
  beqz  $a3, .L7F09C790
   lw    $a2, 0x60($sp)
  lbu   $t6, 1($a3)
  li    $t9, 7
  sb    $t9, ($a3)
  ori   $t7, $t6, 2
  sb    $t7, 1($a3)
  sw    $t0, 4($a3)
  lw    $t8, 0x50($sp)
  li    $a1, 255
  move  $s0, $zero
  sw    $t8, 0x14($a3)
  lwc1  $f4, ($s3)
  li    $t6, 255
  swc1  $f4, 8($a3)
  lwc1  $f6, 4($s3)
  swc1  $f6, 0xc($a3)
  lwc1  $f8, 8($s3)
  swc1  $f8, 0x10($a3)
  lbu   $t9, ($a2)
  beq   $a1, $t9, .L7F09C3CC
   addu  $v1, $a3, $zero
  addu  $v0, $a2, $zero
  lbu   $a0, ($a2)
  li    $s2, 7
  sb    $a0, 0x2c($v1)
.L7F09C3B0:
  lbu   $a0, 1($v0)
  addiu $s0, $s0, 1
  addiu $v1, $v1, 1
  beq   $a1, $a0, .L7F09C3CC
   addiu $v0, $v0, 1
  bnel  $s0, $s2, .L7F09C3B0
   sb    $a0, 0x2c($v1)
.L7F09C3CC:
  addu  $t7, $a3, $s0
  sb    $t6, 0x2c($t7)
  lw    $t8, 0x64($sp)
  li    $s2, 7
  move  $s0, $zero
  beqz  $t8, .L7F09C3F4
   move  $a0, $a3
  lbu   $t9, 1($a3)
  ori   $t6, $t9, 8
  sb    $t6, 1($a3)
.L7F09C3F4:
  sw    $a3, 0x30($sp)
  jal   sub_GAME_7F03A4F0
   sw    $t0, 0x40($sp)
  jal   set_stateflag_0x04_for_posdata
   lw    $a0, 0x30($sp)
  lw    $t0, 0x40($sp)
  lw    $v0, 0x58($sp)
  lw    $a3, 0x30($sp)
  lw    $t1, 0x48($sp)
  lh    $t7, 0x56($sp)
  li    $t8, -1
  sh    $zero, 0x3c8($t0)
  sh    $t8, 0x3ca($t0)
  sb    $v0, 0x3cd($t0)
  sw    $a3, ($t0)
  sw    $t1, 4($t0)
  sb    $t7, 0x3cc($t0)
  lw    $t9, 0x5c($sp)
  lui   $at, %hi(D_800576B0)
  beqz  $v0, .L7F09C4F8
   sb    $t9, 0x3ce($t0)
  beql  $t1, $zero, .L7F09C4B0
   lwc1  $f6, ($s3)
  lw    $t6, 0x14($t1)
  beql  $t6, $zero, .L7F09C4B0
   lwc1  $f6, ($s3)
  lwc1  $f10, 8($t1)
  swc1  $f10, 0x3d0($t0)
  lw    $a2, 0x10($t1)
  lw    $a1, 8($t1)
  lw    $a0, 0x14($t1)
  jal   sub_GAME_7F0B2970
   sw    $t0, 0x40($sp)
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f16
  lw    $t0, 0x40($sp)
  lw    $t1, 0x48($sp)
  add.s $f18, $f0, $f16
  swc1  $f18, 0x3d4($t0)
  lwc1  $f4, 0x10($t1)
  swc1  $f4, 0x3d8($t0)
  jal   sub_GAME_7F0B2FD8
   lw    $a0, 0x14($t1)
  lw    $t0, 0x40($sp)
  b     .L7F09C500
   sh    $v0, 0x3dc($t0)
  lwc1  $f6, ($s3)
.L7F09C4B0:
  swc1  $f6, 0x3d0($t0)
  lw    $a2, 8($s3)
  lw    $a1, ($s3)
  sw    $t0, 0x40($sp)
  jal   sub_GAME_7F0B2970
   lw    $a0, 0x50($sp)
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f8
  lw    $t0, 0x40($sp)
  add.s $f10, $f0, $f8
  swc1  $f10, 0x3d4($t0)
  lwc1  $f16, 8($s3)
  swc1  $f16, 0x3d8($t0)
  jal   sub_GAME_7F0B2FD8
   lw    $a0, 0x50($sp)
  lw    $t0, 0x40($sp)
  b     .L7F09C500
   sh    $v0, 0x3dc($t0)
.L7F09C4F8:
  lwc1  $f18, %lo(D_800576B0)($at)
  swc1  $f18, 0x3d0($t0)
.L7F09C500:
  jal   get_random_value
   sw    $t0, 0x40($sp)
  mtc1  $v0, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F09C524
   cvt.s.w $f6, $f4
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F09C524:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f10
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f18
  mul.s $f16, $f6, $f10
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  lwc1  $f10, 0x10($s1)
  mul.s $f4, $f16, $f18
  add.s $f6, $f4, $f8
  mul.s $f16, $f6, $f10
  jal   get_random_value
   swc1  $f16, 0x3c($sp)
  mtc1  $v0, $f18
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F09C574
   cvt.s.w $f4, $f18
  mtc1  $at, $f8
  nop   
  add.s $f4, $f4, $f8
.L7F09C574:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f6
  lui   $at, %hi(D_800576B4)
  lwc1  $f16, %lo(D_800576B4)($at)
  mul.s $f10, $f4, $f6
  nop   
  mul.s $f12, $f10, $f16
  jal   cosf
   swc1  $f12, 0x38($sp)
  lwc1  $f18, 0x3c($sp)
  lw    $t0, 0x40($sp)
  mul.s $f8, $f0, $f18
  swc1  $f8, 0x14($t0)
  jal   sinf
   lwc1  $f12, 0x38($sp)
  lwc1  $f4, 0x3c($sp)
  lw    $t0, 0x40($sp)
  li    $t7, 1
  mul.s $f6, $f0, $f4
  sh    $t7, 0x1c($t0)
  swc1  $f6, 0x18($t0)
  lwc1  $f10, ($s3)
  swc1  $f10, 8($t0)
  lwc1  $f16, 4($s3)
  swc1  $f16, 0xc($t0)
  lwc1  $f18, 8($s3)
  swc1  $f18, 0x10($t0)
  lh    $t8, 0x24($s1)
  blez  $t8, .L7F09C620
   nop   
  lwc1  $f8, 0x28($s1)
.L7F09C5F0:
  lw    $a1, 0x2c($s1)
  lw    $a2, 0x30($s1)
  lw    $a3, 0x34($s1)
  move  $a0, $s3
  jal   sub_GAME_7F09F254
   swc1  $f8, 0x10($sp)
  lw    $t9, 0x44($sp)
  addiu $s0, $s0, 1
  lh    $t6, 0x24($t9)
  slt   $at, $s0, $t6
  bnezl $at, .L7F09C5F0
   lwc1  $f8, 0x28($s1)
.L7F09C620:
  jal   getPlayerCount
   nop   
  slti  $at, $v0, 2
  bnez  $at, .L7F09C790
   move  $a2, $zero
  lui   $t5, %hi(ptr_smoke_buf) 
  lui   $t3, %hi(D_8004017C) 
  addiu $t3, %lo(D_8004017C) # addiu $t3, $t3, 0x17c
  addiu $t5, %lo(ptr_smoke_buf) # addiu $t5, $t5, -0x5ec0
  li    $ra, 8160
  li    $t4, 24
  li    $t2, 9
  li    $t1, 8
  lw    $v1, ($t5)
.L7F09C658:
  addu  $a1, $v1, $a2
  lw    $t7, ($a1)
  addu  $a3, $a2, $v1
  beql  $t7, $zero, .L7F09C6AC
   lw    $t7, 0x198($a1)
  lh    $v0, 6($a3)
  beql  $s2, $v0, .L7F09C6AC
   lw    $t7, 0x198($a1)
  lh    $t0, 6($a3)
  beql  $t1, $t0, .L7F09C6AC
   lw    $t7, 0x198($a1)
  beql  $t2, $t0, .L7F09C6AC
   lw    $t7, 0x198($a1)
  multu $v0, $t4
  mflo  $t8
  addu  $t9, $t3, $t8
  lh    $t6, ($t9)
  sh    $t6, 4($a3)
  lw    $v1, ($t5)
  addu  $a1, $v1, $a2
  lw    $t7, 0x198($a1)
.L7F09C6AC:
  addu  $a0, $a2, $v1
  beql  $t7, $zero, .L7F09C6F8
   lw    $t7, 0x330($a1)
  lh    $v0, 0x19e($a0)
  addiu $a0, $a0, 0x198
  beql  $s2, $v0, .L7F09C6F8
   lw    $t7, 0x330($a1)
  beql  $t1, $v0, .L7F09C6F8
   lw    $t7, 0x330($a1)
  beql  $t2, $v0, .L7F09C6F8
   lw    $t7, 0x330($a1)
  multu $v0, $t4
  mflo  $t8
  addu  $t9, $t3, $t8
  lh    $t6, ($t9)
  sh    $t6, 4($a0)
  lw    $v1, ($t5)
  addu  $a1, $v1, $a2
  lw    $t7, 0x330($a1)
.L7F09C6F8:
  addu  $a0, $a2, $v1
  beql  $t7, $zero, .L7F09C744
   lw    $t7, 0x4c8($a1)
  lh    $v0, 0x336($a0)
  addiu $a0, $a0, 0x330
  beql  $s2, $v0, .L7F09C744
   lw    $t7, 0x4c8($a1)
  beql  $t1, $v0, .L7F09C744
   lw    $t7, 0x4c8($a1)
  beql  $t2, $v0, .L7F09C744
   lw    $t7, 0x4c8($a1)
  multu $v0, $t4
  mflo  $t8
  addu  $t9, $t3, $t8
  lh    $t6, ($t9)
  sh    $t6, 4($a0)
  lw    $v1, ($t5)
  addu  $a1, $v1, $a2
  lw    $t7, 0x4c8($a1)
.L7F09C744:
  addu  $a0, $a2, $v1
  beql  $t7, $zero, .L7F09C788
   addiu $a2, $a2, 0x660
  lh    $v0, 0x4ce($a0)
  addiu $a0, $a0, 0x4c8
  beql  $s2, $v0, .L7F09C788
   addiu $a2, $a2, 0x660
  beql  $t1, $v0, .L7F09C788
   addiu $a2, $a2, 0x660
  beql  $t2, $v0, .L7F09C788
   addiu $a2, $a2, 0x660
  multu $v0, $t4
  mflo  $t8
  addu  $t9, $t3, $t8
  lh    $t6, ($t9)
  sh    $t6, 4($a0)
  addiu $a2, $a2, 0x660
.L7F09C788:
  bnel  $a2, $ra, .L7F09C658
   lw    $v1, ($t5)
.L7F09C790:
  lw    $ra, 0x2c($sp)
.L7F09C794:
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  lw    $s2, 0x24($sp)
  lw    $s3, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x48
");

#ifdef VERSION_JP
asm(R"
.late_rodata
glabel D_800576B0
.word 0x497423fe /*999999.88*/
glabel D_800576B4
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F09C250
  addiu $sp, $sp, -0x50
  sw    $a3, 0x5c($sp)
  lh    $t6, 0x5e($sp)
  lui   $t0, %hi(ptr_explosion_buf) # $t0, 0x8008
  lw    $t0, %lo(ptr_explosion_buf)($t0)
  lui   $t8, %hi(D_8004017C+0x108) # $t8, 0x8004
  sw    $s1, 0x24($sp)
  addiu $t8, %lo(D_8004017C+0x108) # addiu $t8, $t8, 0x2b4
  sll   $t7, $t6, 6
  sw    $s4, 0x30($sp)
  sw    $s3, 0x2c($sp)
  addu  $s1, $t7, $t8
  move  $s3, $a1
  sw    $ra, 0x34($sp)
  sw    $s2, 0x28($sp)
  sw    $s0, 0x20($sp)
  sw    $a0, 0x50($sp)
  sw    $a2, 0x58($sp)
  sw    $s1, 0x4c($sp)
  move  $s4, $zero
  move  $v0, $zero
  move  $v1, $t0
.Ljp7F09CE48:
  lw    $t9, ($v1)
  bnezl $t9, .Ljp7F09CE60
   addiu $v0, $v0, 0x3e0
  b     .Ljp7F09CE6C
   addu  $s4, $v0, $t0
  addiu $v0, $v0, 0x3e0
.Ljp7F09CE60:
  slti  $at, $v0, 0x1740
  bnez  $at, .Ljp7F09CE48
   addiu $v1, $v1, 0x3e0
.Ljp7F09CE6C:
  beql  $s4, $zero, .Ljp7F09D300
   lw    $ra, 0x34($sp)
  jal   remove_last_obj_pos_data_entry
   nop   
  lh    $t6, 0x5e($sp)
  li    $at, 16
  move  $a3, $v0
  beq   $t6, $at, .Ljp7F09CEA4
   lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  li    $at, 1
  beq   $t6, $at, .Ljp7F09CEA4
   li    $t7, 6
  lui   $at, %hi(D_80040170) # $at, 0x8004
  sw    $t7, %lo(D_80040170)($at)
.Ljp7F09CEA4:
  lbu   $v0, 0x39($s1)
  move  $a2, $zero
  blez  $v0, .Ljp7F09CED8
   sll   $a1, $v0, 0x10
  sra   $t8, $a1, 0x10
  move  $a1, $t8
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   sw    $a3, 0x38($sp)
  move  $a0, $v0
  jal   sub_GAME_7F053A10
   move  $a1, $s3
  lw    $a3, 0x38($sp)
.Ljp7F09CED8:
  beqz  $a3, .Ljp7F09D2FC
   lw    $a2, 0x68($sp)
  lbu   $t6, 1($a3)
  li    $t9, 7
  sb    $t9, ($a3)
  ori   $t7, $t6, 2
  sb    $t7, 1($a3)
  sw    $s4, 4($a3)
  lw    $t8, 0x58($sp)
  li    $a1, 255
  move  $s0, $zero
  sw    $t8, 0x14($a3)
  lwc1  $f4, ($s3)
  li    $t6, 255
  swc1  $f4, 8($a3)
  lwc1  $f6, 4($s3)
  swc1  $f6, 0xc($a3)
  lwc1  $f8, 8($s3)
  swc1  $f8, 0x10($a3)
  lbu   $t9, ($a2)
  beq   $a1, $t9, .Ljp7F09CF5C
   addu  $v1, $a3, $zero
  addu  $v0, $a2, $zero
  lbu   $a0, ($a2)
  li    $s2, 7
  sb    $a0, 0x2c($v1)
.Ljp7F09CF40:
  lbu   $a0, 1($v0)
  addiu $s0, $s0, 1
  addiu $v1, $v1, 1
  beq   $a1, $a0, .Ljp7F09CF5C
   addiu $v0, $v0, 1
  bnel  $s0, $s2, .Ljp7F09CF40
   sb    $a0, 0x2c($v1)
.Ljp7F09CF5C:
  addu  $t7, $a3, $s0
  sb    $t6, 0x2c($t7)
  lw    $t8, 0x6c($sp)
  li    $s2, 7
  move  $s0, $zero
  beqz  $t8, .Ljp7F09CF84
   move  $a0, $a3
  lbu   $t9, 1($a3)
  ori   $t6, $t9, 8
  sb    $t6, 1($a3)
.Ljp7F09CF84:
  jal   sub_GAME_7F03A4F0
   sw    $a3, 0x38($sp)
  jal   set_stateflag_0x04_for_posdata
   lw    $a0, 0x38($sp)
  lw    $v0, 0x60($sp)
  lw    $a3, 0x38($sp)
  lw    $t0, 0x50($sp)
  lh    $t7, 0x5e($sp)
  li    $t8, -1
  sh    $zero, 0x3c8($s4)
  sh    $t8, 0x3ca($s4)
  sb    $v0, 0x3cd($s4)
  sw    $a3, ($s4)
  sw    $t0, 4($s4)
  sb    $t7, 0x3cc($s4)
  lw    $t9, 0x64($sp)
  lui   $at, %hi(D_800576B0) # $at, 0x8005
  beqz  $v0, .Ljp7F09D06C
   sb    $t9, 0x3ce($s4)
  beql  $t0, $zero, .Ljp7F09D02C
   lwc1  $f6, ($s3)
  lw    $t6, 0x14($t0)
  beql  $t6, $zero, .Ljp7F09D02C
   lwc1  $f6, ($s3)
  lwc1  $f10, 8($t0)
  swc1  $f10, 0x3d0($s4)
  lw    $a2, 0x10($t0)
  lw    $a1, 8($t0)
  jal   sub_GAME_7F0B2970
   lw    $a0, 0x14($t0)
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f16
  lw    $t0, 0x50($sp)
  add.s $f18, $f0, $f16
  swc1  $f18, 0x3d4($s4)
  lwc1  $f4, 0x10($t0)
  swc1  $f4, 0x3d8($s4)
  jal   sub_GAME_7F0B2FD8
   lw    $a0, 0x14($t0)
  b     .Ljp7F09D074
   sh    $v0, 0x3dc($s4)
  lwc1  $f6, ($s3)
.Ljp7F09D02C:
  swc1  $f6, 0x3d0($s4)
  lw    $a2, 8($s3)
  lw    $a1, ($s3)
  jal   sub_GAME_7F0B2970
   lw    $a0, 0x58($sp)
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f8
  nop   
  add.s $f10, $f0, $f8
  swc1  $f10, 0x3d4($s4)
  lwc1  $f16, 8($s3)
  swc1  $f16, 0x3d8($s4)
  jal   sub_GAME_7F0B2FD8
   lw    $a0, 0x58($sp)
  b     .Ljp7F09D074
   sh    $v0, 0x3dc($s4)
.Ljp7F09D06C:
  lwc1  $f18, %lo(D_800576B0)($at)
  swc1  $f18, 0x3d0($s4)
.Ljp7F09D074:
  jal   get_random_value
   nop   
  mtc1  $v0, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .Ljp7F09D098
   cvt.s.w $f6, $f4
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.Ljp7F09D098:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f10
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f18
  mul.s $f16, $f6, $f10
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  lwc1  $f10, 0x10($s1)
  mul.s $f4, $f16, $f18
  add.s $f6, $f4, $f8
  mul.s $f16, $f6, $f10
  jal   get_random_value
   swc1  $f16, 0x44($sp)
  mtc1  $v0, $f18
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .Ljp7F09D0E8
   cvt.s.w $f4, $f18
  mtc1  $at, $f8
  nop   
  add.s $f4, $f4, $f8
.Ljp7F09D0E8:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f6
  lui   $at, %hi(D_800576B4) # $at, 0x8005
  lwc1  $f16, %lo(D_800576B4)($at)
  mul.s $f10, $f4, $f6
  nop   
  mul.s $f12, $f10, $f16
  jal   cosf
   swc1  $f12, 0x40($sp)
  lwc1  $f18, 0x44($sp)
  mul.s $f8, $f0, $f18
  swc1  $f8, 0x14($s4)
  jal   sinf
   lwc1  $f12, 0x40($sp)
  lwc1  $f4, 0x44($sp)
  li    $t7, 1
  sh    $t7, 0x1c($s4)
  mul.s $f6, $f0, $f4
  swc1  $f6, 0x18($s4)
  lwc1  $f10, ($s3)
  swc1  $f10, 8($s4)
  lwc1  $f16, 4($s3)
  swc1  $f16, 0xc($s4)
  lwc1  $f18, 8($s3)
  swc1  $f18, 0x10($s4)
  lh    $t8, 0x24($s1)
  blez  $t8, .Ljp7F09D18C
   nop   
  lwc1  $f8, 0x28($s1)
.Ljp7F09D15C:
  lw    $a1, 0x2c($s1)
  lw    $a2, 0x30($s1)
  lw    $a3, 0x34($s1)
  move  $a0, $s3
  jal   sub_GAME_7F09F254
   swc1  $f8, 0x10($sp)
  lw    $t9, 0x4c($sp)
  addiu $s0, $s0, 1
  lh    $t6, 0x24($t9)
  slt   $at, $s0, $t6
  bnezl $at, .Ljp7F09D15C
   lwc1  $f8, 0x28($s1)
.Ljp7F09D18C:
  jal   getPlayerCount
   nop   
  slti  $at, $v0, 2
  bnez  $at, .Ljp7F09D2FC
   move  $a2, $zero
  lui   $t5, %hi(ptr_smoke_buf) # $t5, 0x8008
  lui   $t3, %hi(D_8004017C) # $t3, 0x8004
  addiu $t3, %lo(D_8004017C) # addiu $t3, $t3, 0x1ac
  addiu $t5, %lo(ptr_smoke_buf) # addiu $t5, $t5, -0x5e50
  li    $ra, 8160
  li    $t4, 24
  li    $t2, 9
  li    $t1, 8
  lw    $v1, ($t5)
.Ljp7F09D1C4:
  addu  $a1, $v1, $a2
  lw    $t7, ($a1)
  addu  $a3, $a2, $v1
  beql  $t7, $zero, .Ljp7F09D218
   lw    $t7, 0x198($a1)
  lh    $v0, 6($a3)
  beql  $s2, $v0, .Ljp7F09D218
   lw    $t7, 0x198($a1)
  lh    $t0, 6($a3)
  beql  $t1, $t0, .Ljp7F09D218
   lw    $t7, 0x198($a1)
  beql  $t2, $t0, .Ljp7F09D218
   lw    $t7, 0x198($a1)
  multu $v0, $t4
  mflo  $t8
  addu  $t9, $t3, $t8
  lh    $t6, ($t9)
  sh    $t6, 4($a3)
  lw    $v1, ($t5)
  addu  $a1, $v1, $a2
  lw    $t7, 0x198($a1)
.Ljp7F09D218:
  addu  $a0, $a2, $v1
  beql  $t7, $zero, .Ljp7F09D264
   lw    $t7, 0x330($a1)
  lh    $v0, 0x19e($a0)
  addiu $a0, $a0, 0x198
  beql  $s2, $v0, .Ljp7F09D264
   lw    $t7, 0x330($a1)
  beql  $t1, $v0, .Ljp7F09D264
   lw    $t7, 0x330($a1)
  beql  $t2, $v0, .Ljp7F09D264
   lw    $t7, 0x330($a1)
  multu $v0, $t4
  mflo  $t8
  addu  $t9, $t3, $t8
  lh    $t6, ($t9)
  sh    $t6, 4($a0)
  lw    $v1, ($t5)
  addu  $a1, $v1, $a2
  lw    $t7, 0x330($a1)
.Ljp7F09D264:
  addu  $a0, $a2, $v1
  beql  $t7, $zero, .Ljp7F09D2B0
   lw    $t7, 0x4c8($a1)
  lh    $v0, 0x336($a0)
  addiu $a0, $a0, 0x330
  beql  $s2, $v0, .Ljp7F09D2B0
   lw    $t7, 0x4c8($a1)
  beql  $t1, $v0, .Ljp7F09D2B0
   lw    $t7, 0x4c8($a1)
  beql  $t2, $v0, .Ljp7F09D2B0
   lw    $t7, 0x4c8($a1)
  multu $v0, $t4
  mflo  $t8
  addu  $t9, $t3, $t8
  lh    $t6, ($t9)
  sh    $t6, 4($a0)
  lw    $v1, ($t5)
  addu  $a1, $v1, $a2
  lw    $t7, 0x4c8($a1)
.Ljp7F09D2B0:
  addu  $a0, $a2, $v1
  beql  $t7, $zero, .Ljp7F09D2F4
   addiu $a2, $a2, 0x660
  lh    $v0, 0x4ce($a0)
  addiu $a0, $a0, 0x4c8
  beql  $s2, $v0, .Ljp7F09D2F4
   addiu $a2, $a2, 0x660
  beql  $t1, $v0, .Ljp7F09D2F4
   addiu $a2, $a2, 0x660
  beql  $t2, $v0, .Ljp7F09D2F4
   addiu $a2, $a2, 0x660
  multu $v0, $t4
  mflo  $t8
  addu  $t9, $t3, $t8
  lh    $t6, ($t9)
  sh    $t6, 4($a0)
  addiu $a2, $a2, 0x660
.Ljp7F09D2F4:
  bnel  $a2, $ra, .Ljp7F09D1C4
   lw    $v1, ($t5)
.Ljp7F09D2FC:
  lw    $ra, 0x34($sp)
.Ljp7F09D300:
  sltu  $v0, $zero, $s4
  lw    $s4, 0x30($sp)
  lw    $s0, 0x20($sp)
  lw    $s1, 0x24($sp)
  lw    $s2, 0x28($sp)
  lw    $s3, 0x2c($sp)
  jr    $ra
   addiu $sp, $sp, 0x50
");
#endif

#endif

void sub_GAME_7F09C7AC(void) {
  D_80040170 = 6;
  D_80040174 = 6;
}

#ifdef VERSION_US
asm(R"
.late_rodata
glabel D_800576B8
.word 0x3f4ccccd /*0.80000001*/
.text
glabel sub_GAME_7F09C7C4
  addiu $sp, $sp, -0x58
  lui   $t6, %hi(D_80040170) 
  lw    $t6, %lo(D_80040170)($t6)
  sw    $s2, 0x30($sp)
  sw    $s1, 0x2c($sp)
  move  $s1, $a0
  move  $s2, $a1
  sw    $ra, 0x3c($sp)
  sw    $s4, 0x38($sp)
  sw    $s3, 0x34($sp)
  sw    $s0, 0x28($sp)
  sdc1  $f22, 0x20($sp)
  sdc1  $f20, 0x18($sp)
  bnez  $t6, .L7F09C814
   sw    $a2, 0x60($sp)
  mtc1  $zero, $f12
  jal   video_related_9
   nop   
  b     .L7F09C9B4
   lw    $ra, 0x3c($sp)
.L7F09C814:
  lui   $at, %hi(D_800576B8)
  lwc1  $f20, %lo(D_800576B8)($at)
  jal   cosf
   mov.s $f12, $f20
  mov.s $f22, $f0
  jal   sinf
   mov.s $f12, $f20
  lwc1  $f4, ($s2)
  lwc1  $f8, 8($s2)
  mov.s $f12, $f20
  mul.s $f6, $f22, $f4
  nop   
  mul.s $f10, $f8, $f0
  sub.s $f16, $f6, $f10
  jal   sinf
   swc1  $f16, 0x44($sp)
  mov.s $f22, $f0
  jal   cosf
   mov.s $f12, $f20
  lwc1  $f18, 8($s2)
  lwc1  $f8, ($s2)
  li    $at, 0x41700000 # 15.000000
  mul.s $f4, $f18, $f0
  lui   $s2, %hi(D_8004017C+0x108)
  lui   $v0, %hi(ptr_explosion_buf)
  mul.s $f6, $f22, $f8
  lui   $s3, %hi(ptr_explosion_buf)
  mtc1  $zero, $f20
  mtc1  $at, $f22
  addiu $s3, %lo(ptr_explosion_buf) # addiu $s3, $s3, -0x5ebc
  lw    $v0, %lo(ptr_explosion_buf)($v0)
  addiu $s2, %lo(D_8004017C+0x108) # addiu $s2, $s2, 0x284
  add.s $f10, $f4, $f6
  move  $s0, $zero
  li    $s4, 5952
  swc1  $f10, 0x40($sp)
.L7F09C8A4:
  lw    $v1, ($v0)
  beql  $v1, $zero, .L7F09C914
   addiu $s0, $s0, 0x3e0
  lwc1  $f16, 8($v1)
  lwc1  $f18, ($s1)
  lwc1  $f8, 0xc($v1)
  lwc1  $f4, 4($s1)
  sub.s $f0, $f16, $f18
  lwc1  $f6, 0x10($v1)
  lwc1  $f10, 8($s1)
  sub.s $f2, $f8, $f4
  mul.s $f16, $f0, $f0
  sub.s $f14, $f6, $f10
  mul.s $f18, $f2, $f2
  add.s $f8, $f16, $f18
  mul.s $f4, $f14, $f14
  jal   sqrtf
   add.s $f12, $f8, $f4
  lw    $t7, ($s3)
  addu  $v0, $t7, $s0
  lb    $t8, 0x3cc($v0)
  sll   $t9, $t8, 6
  addu  $t0, $s2, $t9
  lwc1  $f6, 0x10($t0)
  div.s $f2, $f6, $f0
  mul.s $f10, $f2, $f22
  add.s $f20, $f20, $f10
  addiu $s0, $s0, 0x3e0
.L7F09C914:
  bne   $s0, $s4, .L7F09C8A4
   addiu $v0, $v0, 0x3e0
  lui   $v1, %hi(D_80040174)
  addiu $v1, %lo(D_80040174) # addiu $v1, $v1, 0x174
  lw    $v0, ($v1)
  li    $at, 0x3F800000 # 1.000000
  blez  $v0, .L7F09C944
   nop   
  mtc1  $at, $f16
  addiu $t1, $v0, -1
  sw    $t1, ($v1)
  add.s $f20, $f20, $f16
.L7F09C944:
  lui   $v0, %hi(D_80040170)
  addiu $v0, %lo(D_80040170) # addiu $v0, $v0, 0x170
  lw    $t2, ($v0)
  addiu $t3, $t2, -1
  andi  $t5, $t3, 2
  beqz  $t5, .L7F09C970
   sw    $t3, ($v0)
  lw    $v1, 0x60($sp)
  swc1  $f20, 4($v1)
  b     .L7F09C97C
   neg.s $f20, $f20
.L7F09C970:
  lw    $v1, 0x60($sp)
  neg.s $f18, $f20
  swc1  $f18, 4($v1)
.L7F09C97C:
  lwc1  $f8, 0x44($sp)
  mul.s $f4, $f20, $f8
  swc1  $f4, ($v1)
  lwc1  $f6, 0x40($sp)
  mul.s $f10, $f20, $f6
  swc1  $f10, 8($v1)
  lw    $t7, ($v0)
  mtc1  $t7, $f16
  nop   
  cvt.s.w $f18, $f16
  mul.s $f12, $f18, $f20
  jal   video_related_9
   nop   
  lw    $ra, 0x3c($sp)
.L7F09C9B4:
  ldc1  $f20, 0x18($sp)
  ldc1  $f22, 0x20($sp)
  lw    $s0, 0x28($sp)
  lw    $s1, 0x2c($sp)
  lw    $s2, 0x30($sp)
  lw    $s3, 0x34($sp)
  lw    $s4, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x58
");

#ifdef VERSION_JP
asm(R"
.late_rodata
glabel D_800576B8
.word 0x3f4ccccd /*0.80000001*/
.word 0x38d1b717
.text
glabel sub_GAME_7F09C7C4
  addiu $sp, $sp, -0x68
  lui   $t6, %hi(D_80040170) # $t6, 0x8004
  lw    $t6, %lo(D_80040170)($t6)
  sw    $s2, 0x40($sp)
  sw    $s1, 0x3c($sp)
  move  $s1, $a0
  move  $s2, $a1
  sw    $ra, 0x4c($sp)
  sw    $s4, 0x48($sp)
  sw    $s3, 0x44($sp)
  sw    $s0, 0x38($sp)
  sdc1  $f26, 0x30($sp)
  sdc1  $f24, 0x28($sp)
  sdc1  $f22, 0x20($sp)
  sdc1  $f20, 0x18($sp)
  bnez  $t6, .Ljp7F09D390
   sw    $a2, 0x70($sp)
  mtc1  $zero, $f12
  jal   video_related_9
   nop   
  b     .Ljp7F09D550
   lw    $ra, 0x4c($sp)
.Ljp7F09D390:
  lui   $at, %hi(D_800576B8) # $at, 0x8005
  lwc1  $f20, %lo(D_800576B8)($at)
  jal   cosf
   mov.s $f12, $f20
  mov.s $f24, $f0
  jal   sinf
   mov.s $f12, $f20
  lwc1  $f4, ($s2)
  lwc1  $f8, 8($s2)
  mov.s $f12, $f20
  mul.s $f6, $f24, $f4
  nop   
  mul.s $f10, $f8, $f0
  sub.s $f16, $f6, $f10
  jal   sinf
   swc1  $f16, 0x54($sp)
  mov.s $f24, $f0
  jal   cosf
   mov.s $f12, $f20
  lwc1  $f18, 8($s2)
  lwc1  $f8, ($s2)
  mtc1  $zero, $f22
  mul.s $f4, $f18, $f0
  li    $at, 0x41700000 # 15.000000
  mtc1  $at, $f26
  mul.s $f6, $f24, $f8
  lui   $at, %hi(D_800576B8+0x4) # $at, 0x8005
  lui   $s2, %hi(D_8004017C+0x108) # $s2, 0x8004
  lui   $v0, %hi(ptr_explosion_buf) # $v0, 0x8008
  lui   $s3, %hi(ptr_explosion_buf) # $s3, 0x8008
  addiu $s3, %lo(ptr_explosion_buf) # addiu $s3, $s3, -0x5e4c
  lw    $v0, %lo(ptr_explosion_buf)($v0)
  add.s $f10, $f4, $f6
  addiu $s2, %lo(D_8004017C+0x108) # addiu $s2, $s2, 0x2b4
  lwc1  $f24, %lo(D_800576B8+0x4)($at)
  move  $s0, $zero
  swc1  $f10, 0x50($sp)
  li    $s4, 5952
  mov.s $f20, $f22
.Ljp7F09D42C:
  lw    $v1, ($v0)
  beql  $v1, $zero, .Ljp7F09D4B0
   addiu $s0, $s0, 0x3e0
  lwc1  $f16, 8($v1)
  lwc1  $f18, ($s1)
  lwc1  $f8, 0xc($v1)
  lwc1  $f4, 4($s1)
  sub.s $f0, $f16, $f18
  lwc1  $f6, 0x10($v1)
  lwc1  $f10, 8($s1)
  sub.s $f2, $f8, $f4
  mul.s $f16, $f0, $f0
  sub.s $f14, $f6, $f10
  mul.s $f18, $f2, $f2
  add.s $f8, $f16, $f18
  mul.s $f4, $f14, $f14
  jal   sqrtf
   add.s $f12, $f8, $f4
  c.eq.s $f0, $f22
  mov.s $f2, $f0
  bc1fl .Ljp7F09D48C
   lw    $t7, ($s3)
  mov.s $f2, $f24
  lw    $t7, ($s3)
.Ljp7F09D48C:
  addu  $v0, $t7, $s0
  lb    $t8, 0x3cc($v0)
  sll   $t9, $t8, 6
  addu  $t0, $s2, $t9
  lwc1  $f6, 0x10($t0)
  div.s $f0, $f6, $f2
  mul.s $f10, $f0, $f26
  add.s $f20, $f20, $f10
  addiu $s0, $s0, 0x3e0
.Ljp7F09D4B0:
  bne   $s0, $s4, .Ljp7F09D42C
   addiu $v0, $v0, 0x3e0
  lui   $v1, %hi(D_80040174) # $v1, 0x8004
  addiu $v1, %lo(D_80040174) # addiu $v1, $v1, 0x1a4
  lw    $v0, ($v1)
  li    $at, 0x3F800000 # 1.000000
  blez  $v0, .Ljp7F09D4E0
   nop   
  mtc1  $at, $f16
  addiu $t1, $v0, -1
  sw    $t1, ($v1)
  add.s $f20, $f20, $f16
.Ljp7F09D4E0:
  lui   $v0, %hi(D_80040170) # $v0, 0x8004
  addiu $v0, %lo(D_80040170) # addiu $v0, $v0, 0x1a0
  lw    $t2, ($v0)
  addiu $t3, $t2, -1
  andi  $t5, $t3, 2
  beqz  $t5, .Ljp7F09D50C
   sw    $t3, ($v0)
  lw    $v1, 0x70($sp)
  swc1  $f20, 4($v1)
  b     .Ljp7F09D518
   neg.s $f20, $f20
.Ljp7F09D50C:
  lw    $v1, 0x70($sp)
  neg.s $f18, $f20
  swc1  $f18, 4($v1)
.Ljp7F09D518:
  lwc1  $f8, 0x54($sp)
  mul.s $f4, $f20, $f8
  swc1  $f4, ($v1)
  lwc1  $f6, 0x50($sp)
  mul.s $f10, $f20, $f6
  swc1  $f10, 8($v1)
  lw    $t7, ($v0)
  mtc1  $t7, $f16
  nop   
  cvt.s.w $f18, $f16
  mul.s $f12, $f18, $f20
  jal   video_related_9
   nop   
  lw    $ra, 0x4c($sp)
.Ljp7F09D550:
  ldc1  $f20, 0x18($sp)
  ldc1  $f22, 0x20($sp)
  ldc1  $f24, 0x28($sp)
  ldc1  $f26, 0x30($sp)
  lw    $s0, 0x38($sp)
  lw    $s1, 0x3c($sp)
  lw    $s2, 0x40($sp)
  lw    $s3, 0x44($sp)
  lw    $s4, 0x48($sp)
  jr    $ra
   addiu $sp, $sp, 0x68
");
#endif

#endif

asm(R"
glabel sub_GAME_7F09C9D8
  addiu $sp, $sp, -0x100
  sw    $ra, 0x6c($sp)
  sw    $s6, 0x68($sp)
  sw    $s5, 0x64($sp)
  sw    $s4, 0x60($sp)
  sw    $s3, 0x5c($sp)
  sw    $s2, 0x58($sp)
  sw    $s1, 0x54($sp)
  sw    $s0, 0x50($sp)
  sdc1  $f30, 0x48($sp)
  sdc1  $f28, 0x40($sp)
  sdc1  $f26, 0x38($sp)
  sdc1  $f24, 0x30($sp)
  sdc1  $f22, 0x28($sp)
  sdc1  $f20, 0x20($sp)
  sw    $a2, 0x108($sp)
  lw    $s2, 4($a0)
  lui   $t8, %hi(D_8004017C+0x108) 
  mtc1  $a1, $f28
  lb    $t6, 0x3cc($s2)
  lh    $t9, 0x3c8($s2)
  lh    $t0, 0x3ca($s2)
  addiu $t8, %lo(D_8004017C+0x108) # addiu $t8, $t8, 0x284
  sll   $t7, $t6, 6
  slt   $at, $t9, $t0
  move  $s1, $a0
  bnez  $at, .L7F09CEA8
   addu  $s6, $t7, $t8
  addiu $s0, $sp, 0xe0
  jal   sub_GAME_7F03CB8C
   move  $a1, $s0
  jal   sub_GAME_7F03E3FC
   move  $a0, $s0
  lui   $s3, %hi(ptr_list_object_lookup_indices)
  lw    $s3, %lo(ptr_list_object_lookup_indices)($s3)
  li    $s5, 3
  lh    $v0, ($s3)
  bltzl $v0, .L7F09CE98
   lh    $t1, 0x1c($s6)
  mtc1  $zero, $f30
  li    $s4, 1
  sll   $t1, $v0, 2
.L7F09CA80:
  subu  $t1, $t1, $v0
  sll   $t1, $t1, 2
  lw    $t3, 4($s2)
  addu  $t1, $t1, $v0
  lui   $t2, %hi(pos_data_entry) 
  addiu $t2, %lo(pos_data_entry) # addiu $t2, $t2, -0x63c8
  sll   $t1, $t1, 2
  addu  $s0, $t1, $t2
  beql  $s0, $t3, .L7F09CE88
   lh    $v0, 2($s3)
  lh    $t4, 2($s0)
  bnezl $t4, .L7F09CE88
   lh    $v0, 2($s3)
  lbu   $v0, ($s0)
  li    $at, 4
  beql  $s4, $v0, .L7F09CAD8
   lw    $v1, 4($s0)
  beq   $v0, $at, .L7F09CAD4
   li    $at, 2
  bne   $v0, $at, .L7F09CC7C
   nop   
.L7F09CAD4:
  lw    $v1, 4($s0)
.L7F09CAD8:
  lwc1  $f6, 8($s1)
  lwc1  $f10, 0xc($s1)
  lwc1  $f4, 0x58($v1)
  lwc1  $f8, 0x5c($v1)
  sub.s $f18, $f4, $f6
  lwc1  $f6, 0x10($s1)
  lwc1  $f4, 0x60($v1)
  sub.s $f20, $f8, $f10
  c.le.s $f18, $f28
  sub.s $f22, $f4, $f6
  bc1f  .L7F09CC74
   nop   
  neg.s $f0, $f28
  lwc1  $f8, 0x108($sp)
  c.le.s $f0, $f18
  nop   
  bc1f  .L7F09CC74
   nop   
  c.le.s $f20, $f8
  nop   
  bc1f  .L7F09CC74
   nop   
  neg.s $f10, $f8
  c.le.s $f10, $f20
  nop   
  bc1f  .L7F09CC74
   nop   
  c.le.s $f22, $f28
  nop   
  bc1f  .L7F09CC74
   nop   
  c.le.s $f0, $f22
  li    $at, 0x3F800000 # 1.000000
  bc1f  .L7F09CC74
   nop   
  div.s $f2, $f18, $f28
  lwc1  $f26, 0x3c($s6)
  div.s $f14, $f20, $f8
  mov.s $f0, $f2
  c.lt.s $f2, $f30
  div.s $f24, $f22, $f28
  mtc1  $at, $f22
  mov.s $f12, $f14
  bc1f  .L7F09CB90
   mov.s $f16, $f24
  neg.s $f0, $f2
.L7F09CB90:
  c.lt.s $f14, $f30
  sub.s $f20, $f22, $f0
  bc1fl .L7F09CBA8
   c.lt.s $f24, $f30
  neg.s $f12, $f14
  c.lt.s $f24, $f30
.L7F09CBA8:
  sub.s $f12, $f22, $f12
  bc1fl .L7F09CBBC
   c.lt.s $f12, $f20
  neg.s $f16, $f24
  c.lt.s $f12, $f20
.L7F09CBBC:
  sub.s $f16, $f22, $f16
  bc1fl .L7F09CBD0
   c.lt.s $f16, $f20
  mov.s $f20, $f12
  c.lt.s $f16, $f20
.L7F09CBD0:
  nop   
  bc1fl .L7F09CBE4
   lw    $t5, 0x64($v1)
  mov.s $f20, $f16
  lw    $t5, 0x64($v1)
.L7F09CBE4:
  mul.s $f20, $f20, $f26
  andi  $t6, $t5, 0x1000
  bnez  $t6, .L7F09CC74
   nop   
  lw    $t7, 0xc($v1)
  lui   $at, (0x00200400 >> 16) # lui $at, 0x20
  ori   $at, (0x00200400 & 0xFFFF) # ori $at, $at, 0x400
  and   $t8, $t7, $at
  bnez  $t8, .L7F09CC74
   nop   
  jal   get_random_value
   sw    $v1, 0xcc($sp)
  mtc1  $v0, $f4
  lw    $v1, 0xcc($sp)
  move  $a0, $s0
  bgez  $v0, .L7F09CC38
   cvt.s.w $f6, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f10
  nop   
  add.s $f6, $f6, $f10
.L7F09CC38:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f8
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f10
  mul.s $f4, $f6, $f8
  lb    $t9, 0x3ce($s2)
  addiu $a2, $v1, 0x58
  li    $a3, 29
  sw    $t9, 0x10($sp)
  mul.s $f6, $f4, $f10
  add.s $f8, $f6, $f22
  mul.s $f4, $f8, $f20
  mfc1  $a1, $f4
  jal   sub_GAME_7F04DEFC
   nop   
.L7F09CC74:
  b     .L7F09CE88
   lh    $v0, 2($s3)
.L7F09CC7C:
  beq   $s5, $v0, .L7F09CC8C
   li    $at, 6
  bnel  $v0, $at, .L7F09CE88
   lh    $v0, 2($s3)
.L7F09CC8C:
  lwc1  $f10, 8($s0)
  lwc1  $f6, 8($s1)
  lwc1  $f8, 0xc($s0)
  lwc1  $f4, 0xc($s1)
  sub.s $f22, $f10, $f6
  lwc1  $f6, 0x10($s1)
  lwc1  $f10, 0x10($s0)
  sub.s $f18, $f8, $f4
  c.le.s $f22, $f28
  sub.s $f24, $f10, $f6
  bc1fl .L7F09CE88
   lh    $v0, 2($s3)
  neg.s $f0, $f28
  lwc1  $f8, 0x108($sp)
  c.le.s $f0, $f22
  nop   
  bc1fl .L7F09CE88
   lh    $v0, 2($s3)
  c.le.s $f18, $f8
  nop   
  bc1fl .L7F09CE88
   lh    $v0, 2($s3)
  neg.s $f4, $f8
  c.le.s $f4, $f18
  nop   
  bc1fl .L7F09CE88
   lh    $v0, 2($s3)
  c.le.s $f24, $f28
  nop   
  bc1fl .L7F09CE88
   lh    $v0, 2($s3)
  c.le.s $f0, $f24
  li    $at, 0x3F800000 # 1.000000
  bc1fl .L7F09CE88
   lh    $v0, 2($s3)
  div.s $f2, $f22, $f28
  lwc1  $f26, 0x3c($s6)
  addiu $a1, $s1, 8
  move  $a3, $s4
  div.s $f14, $f18, $f8
  mov.s $f0, $f2
  c.lt.s $f2, $f30
  div.s $f20, $f24, $f28
  mov.s $f12, $f14
  bc1f  .L7F09CD48
   mov.s $f16, $f20
  neg.s $f0, $f2
.L7F09CD48:
  c.lt.s $f14, $f30
  mtc1  $at, $f2
  bc1fl .L7F09CD60
   c.lt.s $f20, $f30
  neg.s $f12, $f14
  c.lt.s $f20, $f30
.L7F09CD60:
  sub.s $f12, $f2, $f12
  bc1fl .L7F09CD74
   sub.s $f20, $f2, $f0
  neg.s $f16, $f20
  sub.s $f20, $f2, $f0
.L7F09CD74:
  sub.s $f16, $f2, $f16
  c.lt.s $f12, $f20
  nop   
  bc1fl .L7F09CD90
   c.lt.s $f16, $f20
  mov.s $f20, $f12
  c.lt.s $f16, $f20
.L7F09CD90:
  nop   
  bc1f  .L7F09CDA0
   nop   
  mov.s $f20, $f16
.L7F09CDA0:
  mul.s $f20, $f20, $f20
  nop   
  mul.s $f20, $f20, $f26
  bne   $s5, $v0, .L7F09CDC8
   nop   
  mfc1  $a2, $f20
  jal   sub_GAME_7F027804
   lw    $a0, 4($s0)
  b     .L7F09CE88
   lh    $v0, 2($s3)
.L7F09CDC8:
  c.eq.s $f22, $f30
  nop   
  bc1f  .L7F09CDE8
   nop   
  c.eq.s $f24, $f30
  nop   
  bc1t  .L7F09CE1C
   nop   
.L7F09CDE8:
  mul.s $f10, $f22, $f22
  nop   
  mul.s $f6, $f24, $f24
  jal   sqrtf
   add.s $f12, $f10, $f6
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  nop   
  div.s $f2, $f4, $f0
  mul.s $f22, $f22, $f2
  nop   
  mul.s $f24, $f24, $f2
  nop   
.L7F09CE1C:
  jal   get_cur_playernum
   nop   
  sw    $v0, 0x90($sp)
  jal   sub_GAME_7F09B15C
   move  $a0, $s0
  jal   set_cur_player
   move  $a0, $v0
  jal   getPlayerCount
   nop   
  bne   $v0, $s4, .L7F09CE54
   lui   $at, %hi(D_80040178)
  lwc1  $f8, %lo(D_80040178)($at)
  mul.s $f20, $f20, $f8
  nop   
.L7F09CE54:
  jal   get_intank_flag
   nop   
  bne   $v0, $s4, .L7F09CE68
   mov.s $f14, $f22
  add.s $f20, $f20, $f20
.L7F09CE68:
  mfc1  $a2, $f24
  lb    $a3, 0x3ce($s2)
  sw    $s4, 0x10($sp)
  jal   record_damage_kills
   mov.s $f12, $f20
  jal   set_cur_player
   lw    $a0, 0x90($sp)
  lh    $v0, 2($s3)
.L7F09CE88:
  addiu $s3, $s3, 2
  bgezl $v0, .L7F09CA80
   sll   $t1, $v0, 2
  lh    $t1, 0x1c($s6)
.L7F09CE98:
  lh    $t0, 0x3c8($s2)
  sra   $t2, $t1, 2
  addu  $t3, $t0, $t2
  sh    $t3, 0x3ca($s2)
.L7F09CEA8:
  lw    $ra, 0x6c($sp)
  ldc1  $f20, 0x20($sp)
  ldc1  $f22, 0x28($sp)
  ldc1  $f24, 0x30($sp)
  ldc1  $f26, 0x38($sp)
  ldc1  $f28, 0x40($sp)
  ldc1  $f30, 0x48($sp)
  lw    $s0, 0x50($sp)
  lw    $s1, 0x54($sp)
  lw    $s2, 0x58($sp)
  lw    $s3, 0x5c($sp)
  lw    $s4, 0x60($sp)
  lw    $s5, 0x64($sp)
  lw    $s6, 0x68($sp)
  jr    $ra
   addiu $sp, $sp, 0x100
");

asm(R"
.late_rodata
glabel D_800576BC
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F09CEE8
  addiu $sp, $sp, -0xc8
  sw    $ra, 0x6c($sp)
  sw    $s7, 0x68($sp)
  sw    $s6, 0x64($sp)
  sw    $s5, 0x60($sp)
  sw    $s4, 0x5c($sp)
  sw    $s3, 0x58($sp)
  sw    $s2, 0x54($sp)
  sw    $s1, 0x50($sp)
  sw    $s0, 0x4c($sp)
  sdc1  $f30, 0x40($sp)
  sdc1  $f28, 0x38($sp)
  sdc1  $f26, 0x30($sp)
  sdc1  $f24, 0x28($sp)
  sdc1  $f22, 0x20($sp)
  sdc1  $f20, 0x18($sp)
  lw    $s2, 4($a0)
  lui   $v0, %hi(clock_timer)
  lw    $v0, %lo(clock_timer)($v0)
  lb    $a1, 0x3cc($s2)
  lui   $t7, %hi(D_8004017C+0x108) 
  addiu $t7, %lo(D_8004017C+0x108) # addiu $t7, $t7, 0x284
  sll   $t6, $a1, 6
  move  $s3, $a0
  bnez  $v0, .L7F09CF58
   addu  $s5, $t6, $t7
  b     .L7F09D4A8
   move  $v0, $zero
.L7F09CF58:
  slti  $at, $v0, 0xf
  beql  $at, $zero, .L7F09CF7C
   lui   $at, 0x4170
  mtc1  $v0, $f4
  nop   
  cvt.s.w $f6, $f4
  b     .L7F09CF88
   swc1  $f6, 0xa0($sp)
  li    $at, 0x41700000 # 15.000000
.L7F09CF7C:
  mtc1  $at, $f8
  nop   
  swc1  $f8, 0xa0($sp)
.L7F09CF88:
  lh    $v1, 0x3c8($s2)
  slti  $at, $v1, 8
  bnezl $at, .L7F09D2E8
   lwc1  $f10, 0xa0($sp)
  lh    $v0, 0x1c($s5)
  slt   $at, $v1, $v0
  beql  $at, $zero, .L7F09D2E8
   lwc1  $f10, 0xa0($sp)
  mtc1  $v1, $f10
  lwc1  $f18, 8($s5)
  lwc1  $f8, 0xc($s5)
  cvt.s.w $f0, $f10
  lwc1  $f16, ($s5)
  lwc1  $f6, 4($s5)
  li    $s7, 14
  slti  $at, $v1, 0x20
  li    $s6, 1
  mul.s $f4, $f18, $f0
  nop   
  mul.s $f10, $f8, $f0
  add.s $f28, $f16, $f4
  bne   $s7, $a1, .L7F09D05C
   add.s $f30, $f6, $f10
  beqz  $at, .L7F09D018
   lwc1  $f16, 0xa0($sp)
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f18
  lwc1  $f8, 0xc($s3)
  mul.s $f4, $f18, $f16
  add.s $f6, $f8, $f4
  swc1  $f6, 0xc($s3)
  lh    $v1, 0x3c8($s2)
  lh    $v0, 0x1c($s5)
  mtc1  $v1, $f10
  nop   
  cvt.s.w $f0, $f10
.L7F09D018:
  slti  $at, $v1, 0x21
  bnez  $at, .L7F09D05C
   li    $at, 0x43960000 # 300.000000
  mtc1  $at, $f2
  li    $at, 0x40400000 # 3.000000
  mtc1  $at, $f18
  li    $at, 0x42200000 # 40.000000
  mtc1  $at, $f8
  mul.s $f16, $f0, $f18
  li    $at, 0x41A00000 # 20.000000
  mtc1  $at, $f30
  add.s $f28, $f16, $f8
  c.lt.s $f2, $f28
  nop   
  bc1f  .L7F09D05C
   nop   
  mov.s $f28, $f2
.L7F09D05C:
  lh    $t8, 0x1e($s5)
  mtc1  $v0, $f18
  move  $s4, $zero
  mtc1  $t8, $f4
  cvt.s.w $f16, $f18
  li    $at, 0x3F000000 # 0.500000
  cvt.s.w $f6, $f4
  mul.s $f10, $f6, $f0
  div.s $f8, $f10, $f16
  trunc.w.s $f4, $f8
  mfc1  $t0, $f4
  nop   
  addiu $t1, $t0, 1
  blez  $t1, .L7F09D218
   sw    $t1, 0x9c($sp)
  mtc1  $at, $f26
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f22
  li    $s1, 960
  move  $v0, $zero
.L7F09D0AC:
  move  $s0, $s2
.L7F09D0B0:
  lh    $t2, 0x1c($s0)
  addiu $v0, $v0, 0x18
  bnez  $t2, .L7F09D200
   nop   
  jal   get_random_value
   sh    $s6, 0x1c($s0)
  mtc1  $v0, $f6
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F09D0E4
   cvt.s.w $f18, $f6
  mtc1  $at, $f10
  nop   
  add.s $f18, $f18, $f10
.L7F09D0E4:
  mul.s $f16, $f18, $f22
  lwc1  $f6, 8($s3)
  sub.s $f8, $f16, $f26
  mul.s $f4, $f8, $f28
  add.s $f10, $f4, $f6
  jal   get_random_value
   swc1  $f10, 8($s0)
  mtc1  $v0, $f18
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F09D11C
   cvt.s.w $f16, $f18
  mtc1  $at, $f8
  nop   
  add.s $f16, $f16, $f8
.L7F09D11C:
  mul.s $f4, $f16, $f22
  lwc1  $f18, 0xc($s3)
  sub.s $f6, $f4, $f26
  mul.s $f10, $f6, $f30
  add.s $f8, $f10, $f18
  jal   get_random_value
   swc1  $f8, 0xc($s0)
  mtc1  $v0, $f16
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F09D154
   cvt.s.w $f4, $f16
  mtc1  $at, $f6
  nop   
  add.s $f4, $f4, $f6
.L7F09D154:
  mul.s $f10, $f4, $f22
  lwc1  $f16, 0x10($s3)
  sub.s $f18, $f10, $f26
  mul.s $f8, $f18, $f28
  add.s $f6, $f8, $f16
  jal   get_random_value
   swc1  $f6, 0x10($s0)
  mtc1  $v0, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F09D18C
   cvt.s.w $f10, $f4
  mtc1  $at, $f18
  nop   
  add.s $f10, $f10, $f18
.L7F09D18C:
  mul.s $f8, $f10, $f22
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  lwc1  $f18, 0x10($s5)
  mul.s $f16, $f8, $f26
  add.s $f4, $f16, $f6
  mul.s $f20, $f4, $f18
  jal   get_random_value
   nop   
  mtc1  $v0, $f10
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F09D1CC
   cvt.s.w $f8, $f10
  mtc1  $at, $f16
  nop   
  add.s $f8, $f8, $f16
.L7F09D1CC:
  mul.s $f6, $f8, $f22
  lui   $at, %hi(D_800576BC)
  lwc1  $f4, %lo(D_800576BC)($at)
  mul.s $f12, $f6, $f4
  jal   cosf
   mov.s $f24, $f12
  mul.s $f18, $f0, $f20
  mov.s $f12, $f24
  jal   sinf
   swc1  $f18, 0x14($s0)
  mul.s $f10, $f0, $f20
  b     .L7F09D208
   swc1  $f10, 0x18($s0)
.L7F09D200:
  bne   $v0, $s1, .L7F09D0B0
   addiu $s0, $s0, 0x18
.L7F09D208:
  lw    $t3, 0x9c($sp)
  addiu $s4, $s4, 1
  bnel  $s4, $t3, .L7F09D0AC
   move  $v0, $zero
.L7F09D218:
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f26
  li    $at, 0x3FC00000 # 1.500000
  mtc1  $at, $f8
  lwc1  $f16, 0x10($s5)
  lwc1  $f18, 8($s3)
  move  $a0, $s3
  mul.s $f0, $f16, $f8
  addiu $a1, $sp, 0x90
  addiu $a2, $sp, 0x84
  mul.s $f6, $f28, $f26
  add.s $f28, $f6, $f0
  mul.s $f4, $f30, $f26
  mfc1  $a3, $f28
  sub.s $f10, $f18, $f28
  add.s $f30, $f4, $f0
  swc1  $f10, 0x90($sp)
  lwc1  $f16, 0xc($s3)
  sub.s $f8, $f16, $f30
  swc1  $f8, 0x94($sp)
  lwc1  $f6, 0x10($s3)
  sub.s $f4, $f6, $f28
  swc1  $f4, 0x98($sp)
  lwc1  $f18, 8($s3)
  add.s $f10, $f18, $f28
  swc1  $f10, 0x84($sp)
  lwc1  $f16, 0xc($s3)
  add.s $f8, $f16, $f30
  swc1  $f8, 0x88($sp)
  lwc1  $f6, 0x10($s3)
  add.s $f4, $f6, $f28
  jal   sub_GAME_7F03E27C
   swc1  $f4, 0x8c($sp)
  lh    $t4, 0x3c8($s2)
  lwc1  $f0, 0x14($s5)
  lwc1  $f18, 0x18($s5)
  mtc1  $t4, $f16
  lh    $t5, 0x1c($s5)
  sub.s $f10, $f18, $f0
  move  $a0, $s3
  mtc1  $t5, $f4
  cvt.s.w $f8, $f16
  cvt.s.w $f18, $f4
  mul.s $f6, $f10, $f8
  div.s $f16, $f6, $f18
  add.s $f30, $f0, $f16
  mfc1  $a1, $f30
  mfc1  $a2, $f30
  jal   sub_GAME_7F09C9D8
   nop   
  lh    $v1, 0x3c8($s2)
  lwc1  $f10, 0xa0($sp)
.L7F09D2E8:
  li    $s6, 1
  li    $s7, 14
  trunc.w.s $f8, $f10
  move  $s4, $zero
  li    $at, 0x40800000 # 4.000000
  mfc1  $t7, $f8
  nop   
  blez  $t7, .L7F09D468
   sw    $t7, 0x70($sp)
  mtc1  $at, $f20
  li    $s1, 960
  addiu $t8, $v1, 1
.L7F09D318:
  sh    $t8, 0x3c8($s2)
  move  $v0, $zero
  move  $s0, $s2
.L7F09D324:
  lh    $v1, 0x1c($s0)
  addiu $v0, $v0, 0x18
  blez  $v1, .L7F09D338
   addiu $t9, $v1, 1
  sh    $t9, 0x1c($s0)
.L7F09D338:
  bne   $v0, $s1, .L7F09D324
   addiu $s0, $s0, 0x18
  lh    $v1, 0x3c8($s2)
  li    $at, 15
  bnel  $v1, $at, .L7F09D360
   lh    $v0, 0x1c($s5)
  lb    $t0, 0x3cc($s2)
  beql  $s7, $t0, .L7F09D37C
   lw    $v0, 4($s2)
  lh    $v0, 0x1c($s5)
.L7F09D360:
  addiu $t1, $v1, 0x14
  bnel  $v0, $t1, .L7F09D424
   sra   $t3, $v0, 1
  lb    $t2, 0x3cc($s2)
  beql  $s7, $t2, .L7F09D424
   sra   $t3, $v0, 1
  lw    $v0, 4($s2)
.L7F09D37C:
  addiu $a0, $s3, 8
  addiu $a3, $s3, 0x2c
  beql  $v0, $zero, .L7F09D400
   lbu   $t0, 1($s3)
  lw    $a1, 0x14($v0)
  beql  $a1, $zero, .L7F09D400
   lbu   $t0, 1($s3)
  lbu   $t3, ($v0)
  addiu $a3, $v0, 0x2c
  addiu $a0, $v0, 8
  bnel  $s6, $t3, .L7F09D3D8
   lbu   $t7, 1($s3)
  lbu   $t4, 1($s3)
  lw    $v1, 4($v0)
  lbu   $a2, 0x38($s5)
  andi  $t5, $t4, 8
  sltu  $t6, $zero, $t5
  sw    $t6, 0x10($sp)
  jal   sub_GAME_7F09E700
   addiu $a0, $v1, 0x58
  b     .L7F09D3F4
   lh    $v1, 0x3c8($s2)
  lbu   $t7, 1($s3)
.L7F09D3D8:
  lbu   $a2, 0x38($s5)
  addiu $a3, $v0, 0x2c
  andi  $t8, $t7, 8
  sltu  $t9, $zero, $t8
  jal   sub_GAME_7F09E700
   sw    $t9, 0x10($sp)
  lh    $v1, 0x3c8($s2)
.L7F09D3F4:
  b     .L7F09D420
   lh    $v0, 0x1c($s5)
  lbu   $t0, 1($s3)
.L7F09D400:
  lw    $a1, 0x14($s3)
  lbu   $a2, 0x38($s5)
  andi  $t1, $t0, 8
  sltu  $t2, $zero, $t1
  jal   sub_GAME_7F09E700
   sw    $t2, 0x10($sp)
  lh    $v1, 0x3c8($s2)
  lh    $v0, 0x1c($s5)
.L7F09D420:
  sra   $t3, $v0, 1
.L7F09D424:
  bnel  $t3, $v1, .L7F09D45C
   lw    $t5, 0x70($sp)
  lb    $t4, 0x3cd($s2)
  beql  $t4, $zero, .L7F09D45C
   lw    $t5, 0x70($sp)
  lwc1  $f4, 0x10($s5)
  addiu $a0, $s2, 0x3d0
  lh    $a2, 0x3dc($s2)
  mul.s $f6, $f4, $f20
  mfc1  $a1, $f6
  jal   sub_GAME_7F0A027C
   nop   
  lh    $v1, 0x3c8($s2)
  lw    $t5, 0x70($sp)
.L7F09D45C:
  addiu $s4, $s4, 1
  bnel  $s4, $t5, .L7F09D318
   addiu $t8, $v1, 1
.L7F09D468:
  li    $at, 0x41800000 # 16.000000
  mtc1  $at, $f18
  lwc1  $f16, 0x20($s5)
  lh    $t8, 0x1c($s5)
  move  $v0, $zero
  mul.s $f10, $f18, $f16
  trunc.w.s $f8, $f10
  mfc1  $t7, $f8
  nop   
  addu  $t9, $t8, $t7
  slt   $at, $v1, $t9
  bnez  $at, .L7F09D4A8
   nop   
  sw    $zero, ($s2)
  b     .L7F09D4A8
   li    $v0, 1
.L7F09D4A8:
  lw    $ra, 0x6c($sp)
  ldc1  $f20, 0x18($sp)
  ldc1  $f22, 0x20($sp)
  ldc1  $f24, 0x28($sp)
  ldc1  $f26, 0x30($sp)
  ldc1  $f28, 0x38($sp)
  ldc1  $f30, 0x40($sp)
  lw    $s0, 0x4c($sp)
  lw    $s1, 0x50($sp)
  lw    $s2, 0x54($sp)
  lw    $s3, 0x58($sp)
  lw    $s4, 0x5c($sp)
  lw    $s5, 0x60($sp)
  lw    $s6, 0x64($sp)
  lw    $s7, 0x68($sp)
  jr    $ra
   addiu $sp, $sp, 0xc8
");

asm(R"
glabel sub_GAME_7F09D4EC
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   get_BONDdata_field_10CC
   sw    $a0, 0x18($sp)
  lw    $a0, 0x18($sp)
  lwc1  $f4, 8($v0)
  lwc1  $f10, 0x18($v0)
  lwc1  $f6, 8($a0)
  lwc1  $f16, 0xc($a0)
  li    $at, 0x42C80000 # 100.000000
  mul.s $f8, $f4, $f6
  lwc1  $f6, 0x28($v0)
  mtc1  $at, $f2
  mul.s $f18, $f10, $f16
  lwc1  $f10, 0x10($a0)
  li    $at, 0x3F000000 # 0.500000
  lui   $t6, %hi(clock_timer) 
  mul.s $f16, $f6, $f10
  add.s $f4, $f8, $f18
  lwc1  $f18, 0x38($v0)
  move  $v0, $zero
  add.s $f8, $f4, $f16
  add.s $f6, $f18, $f8
  neg.s $f10, $f6
  swc1  $f10, 0x18($a0)
  lwc1  $f0, 0x18($a0)
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F09D57C
   sub.s $f18, $f0, $f2
  mtc1  $at, $f4
  nop   
  mul.s $f16, $f0, $f4
  b     .L7F09D580
   swc1  $f16, 0x18($a0)
  sub.s $f18, $f0, $f2
.L7F09D57C:
  swc1  $f18, 0x18($a0)
.L7F09D580:
  lw    $t6, %lo(clock_timer)($t6)
  lw    $ra, 0x14($sp)
  bnez  $t6, .L7F09D598
   nop   
  b     .L7F09D598
   move  $v0, $zero
.L7F09D598:
  jr    $ra
   addiu $sp, $sp, 0x18
");

asm(R"
glabel sub_GAME_7F09D5A0
  addiu $sp, $sp, -0x90
  sw    $s0, 0x1c($sp)
  sw    $ra, 0x3c($sp)
  sw    $s7, 0x38($sp)
  sw    $s6, 0x34($sp)
  sw    $s5, 0x30($sp)
  sw    $s4, 0x2c($sp)
  sw    $s3, 0x28($sp)
  sw    $s2, 0x24($sp)
  sw    $s1, 0x20($sp)
  lbu   $s1, 0x2c($a0)
  move  $s0, $a0
  lw    $s5, 4($a0)
  move  $s2, $a2
  move  $s4, $a1
  jal   sub_GAME_7F0BCA14
   move  $a0, $s1
  bnez  $s2, .L7F09D5F4
   move  $s6, $v0
  b     .L7F09D800
   move  $v0, $s4
.L7F09D5F4:
  move  $a0, $s0
  jal   sub_GAME_7F054A64
   addiu $a1, $sp, 0x70
  blez  $v0, .L7F09D62C
   nop   
  lwc1  $f4, 0x7c($sp)
  move  $a0, $s4
  lw    $a1, 0x70($sp)
  lw    $a2, 0x74($sp)
  lw    $a3, 0x78($sp)
  jal   sub_GAME_7F0B4FF4
   swc1  $f4, 0x10($sp)
  b     .L7F09D638
   move  $s4, $v0
.L7F09D62C:
  jal   sub_GAME_7F0B4FB4
   move  $a0, $s4
  move  $s4, $v0
.L7F09D638:
  move  $v0, $s4
  lui   $t7, (0x00013000 >> 16) # lui $t7, 1
  ori   $t7, (0x00013000 & 0xFFFF) # ori $t7, $t7, 0x3000
  addiu $s4, $s4, 8
  lui   $t6, 0xb600
  lui   $t8, (0x01030040 >> 16) # lui $t8, 0x103
  sw    $t6, ($v0)
  sw    $t7, 4($v0)
  ori   $t8, (0x01030040 & 0xFFFF) # ori $t8, $t8, 0x40
  move  $s0, $s4
  sw    $t8, ($s0)
  jal   get_BONDdata_field_10E0
   addiu $s4, $s4, 8
  jal   osVirtualToPhysical
   move  $a0, $v0
  sw    $v0, 4($s0)
  move  $a0, $s4
  jal   sub_GAME_7F0BC9C4
   move  $a1, $s1
  lui   $t9, (0xBC000806 >> 16) # lui $t9, 0xbc00
  ori   $t9, (0xBC000806 & 0xFFFF) # ori $t9, $t9, 0x806
  sw    $t9, ($v0)
  lui   $a0, %hi(pGlobalimagetable)
  lw    $a0, %lo(pGlobalimagetable)($a0)
  move  $s0, $v0
  jal   osVirtualToPhysical
   addiu $s4, $v0, 8
  lui   $s7, %hi(D_8004017C+0x680) 
  lui   $s3, %hi(D_8004017C+0x108)
  sw    $v0, 4($s0)
  addiu $s3, %lo(D_8004017C+0x108) # addiu $s3, $s3, 0x284
  addiu $s7, %lo(D_8004017C+0x680) # addiu $s7, $s7, 0x7fc
  li    $s2, 14
.L7F09D6BC:
  move  $v0, $s4
  lui   $t0, 0x600
  sw    $t0, ($v0)
  lw    $t1, ($s7)
  addiu $s4, $s4, 8
  move  $s1, $zero
  move  $s0, $s5
  sw    $t1, 4($v0)
.L7F09D6DC:
  lh    $v0, 0x1c($s0)
  blez  $v0, .L7F09D72C
   addiu $t2, $v0, -1
  mtc1  $t2, $f6
  lb    $t3, 0x3cc($s5)
  addiu $a0, $s0, 8
  cvt.s.w $f8, $f6
  sll   $t4, $t3, 6
  addu  $t5, $s3, $t4
  lwc1  $f10, 0x20($t5)
  move  $a1, $s4
  div.s $f16, $f8, $f10
  trunc.w.s $f18, $f16
  mfc1  $t7, $f18
  nop   
  bnel  $s2, $t7, .L7F09D730
   addiu $s1, $s1, 0x18
  jal   sub_GAME_7F09D82C
   move  $a2, $s6
  move  $s4, $v0
.L7F09D72C:
  addiu $s1, $s1, 0x18
.L7F09D730:
  slti  $at, $s1, 0x3c0
  bnez  $at, .L7F09D6DC
   addiu $s0, $s0, 0x18
  addiu $s2, $s2, -1
  bgez  $s2, .L7F09D6BC
   addiu $s7, $s7, -4
  lui   $t8, (0x01030040 >> 16) # lui $t8, 0x103
  ori   $t8, (0x01030040 & 0xFFFF) # ori $t8, $t8, 0x40
  move  $s2, $s4
  sw    $t8, ($s2)
  jal   get_BONDdata_field_10D8
   addiu $s4, $s4, 8
  jal   osVirtualToPhysical
   move  $a0, $v0
  sw    $v0, 4($s2)
  lb    $t9, 0x3cc($s5)
  li    $at, 0x41700000 # 15.000000
  mtc1  $at, $f6
  sll   $t0, $t9, 6
  addu  $t1, $s3, $t0
  lwc1  $f4, 0x20($t1)
  li    $v0, 960
  move  $s1, $zero
  mul.s $f8, $f4, $f6
  move  $s0, $s5
  trunc.w.s $f10, $f8
  mfc1  $v1, $f10
  nop   
.L7F09D7A0:
  lh    $t3, 0x1c($s0)
  addiu $s1, $s1, 0x60
  slt   $at, $v1, $t3
  beql  $at, $zero, .L7F09D7BC
   lh    $t4, 0x34($s0)
  sh    $zero, 0x1c($s0)
  lh    $t4, 0x34($s0)
.L7F09D7BC:
  slt   $at, $v1, $t4
  beql  $at, $zero, .L7F09D7D0
   lh    $t5, 0x4c($s0)
  sh    $zero, 0x34($s0)
  lh    $t5, 0x4c($s0)
.L7F09D7D0:
  slt   $at, $v1, $t5
  beql  $at, $zero, .L7F09D7E4
   lh    $t6, 0x64($s0)
  sh    $zero, 0x4c($s0)
  lh    $t6, 0x64($s0)
.L7F09D7E4:
  slt   $at, $v1, $t6
  beqz  $at, .L7F09D7F4
   nop   
  sh    $zero, 0x64($s0)
.L7F09D7F4:
  bne   $s1, $v0, .L7F09D7A0
   addiu $s0, $s0, 0x60
  move  $v0, $s4
.L7F09D800:
  lw    $ra, 0x3c($sp)
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  lw    $s2, 0x24($sp)
  lw    $s3, 0x28($sp)
  lw    $s4, 0x2c($sp)
  lw    $s5, 0x30($sp)
  lw    $s6, 0x34($sp)
  lw    $s7, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x90
");

asm(R"
glabel sub_GAME_7F09D82C
  addiu $sp, $sp, -0xb8
  lui   $t7, %hi(D_8004080C+0xF4) 
  sw    $ra, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  addiu $t7, %lo(D_8004080C+0xF4) # addiu $t7, $t7, 0x900
  lw    $at, ($t7)
  lw    $t0, 4($t7)
  addiu $t6, $sp, 0xa0
  sw    $at, ($t6)
  sw    $t0, 4($t6)
  lw    $t0, 0xc($t7)
  lw    $at, 8($t7)
  move  $s0, $a0
  move  $s1, $a2
  move  $s2, $a1
  sw    $t0, 0xc($t6)
  jal   sub_GAME_7F078444
   sw    $at, 8($t6)
  jal   get_BONDdata_position
   sw    $v0, 0x9c($sp)
  lwc1  $f4, ($s0)
  lwc1  $f6, ($v0)
  lwc1  $f8, 4($s0)
  lwc1  $f10, 4($v0)
  sub.s $f14, $f4, $f6
  lwc1  $f6, 8($v0)
  lwc1  $f4, 8($s0)
  sub.s $f16, $f8, $f10
  mul.s $f8, $f14, $f14
  swc1  $f14, 0x64($sp)
  sub.s $f18, $f4, $f6
  mul.s $f10, $f16, $f16
  swc1  $f16, 0x60($sp)
  sw    $v0, 0x98($sp)
  mul.s $f6, $f18, $f18
  swc1  $f18, 0x5c($sp)
  add.s $f4, $f8, $f10
  jal   sqrtf
   add.s $f12, $f4, $f6
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f8
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f10
  mul.s $f12, $f0, $f8
  mtc1  $zero, $f4
  lw    $v1, 0x9c($sp)
  lw    $a1, 0x98($sp)
  lwc1  $f14, 0x64($sp)
  lwc1  $f16, 0x60($sp)
  lwc1  $f18, 0x5c($sp)
  c.lt.s $f10, $f12
  nop   
  bc1f  .L7F09D914
   li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f12
  nop   
.L7F09D914:
  c.eq.s $f0, $f4
  nop   
  bc1fl .L7F09D934
   sub.s $f6, $f0, $f12
  mtc1  $zero, $f2
  b     .L7F09D93C
   lwc1  $f8, 0xc($s0)
  sub.s $f6, $f0, $f12
.L7F09D934:
  div.s $f2, $f6, $f0
  lwc1  $f8, 0xc($s0)
.L7F09D93C:
  lwc1  $f10, 0x10($s0)
  lwc1  $f4, ($a1)
  mul.s $f0, $f8, $f2
  li    $a0, 4
  mul.s $f12, $f10, $f2
  nop   
  mul.s $f6, $f14, $f2
  add.s $f8, $f4, $f6
  mul.s $f4, $f16, $f2
  swc1  $f8, 0x4c($sp)
  lwc1  $f10, 4($a1)
  add.s $f6, $f10, $f4
  mul.s $f10, $f18, $f2
  swc1  $f6, 0x48($sp)
  lwc1  $f8, 8($a1)
  swc1  $f12, 0x50($sp)
  swc1  $f0, 0x54($sp)
  add.s $f4, $f8, $f10
  sw    $v1, 0x9c($sp)
  jal   sub_GAME_7F0BD6C4
   swc1  $f4, 0x44($sp)
  addiu $a0, $sp, 0xa0
  lw    $at, ($a0)
  lw    $v1, 0x9c($sp)
  lwc1  $f0, 0x54($sp)
  lwc1  $f12, 0x50($sp)
  sw    $at, ($v0)
  lw    $t3, 4($a0)
  move  $s0, $v0
  sw    $t3, 4($v0)
  lw    $at, 8($a0)
  sw    $at, 8($v0)
  lw    $t3, 0xc($a0)
  sw    $t3, 0xc($v0)
  lw    $at, ($a0)
  sw    $at, 0x10($v0)
  lw    $t9, 4($a0)
  sw    $t9, 0x14($v0)
  lw    $at, 8($a0)
  sw    $at, 0x18($v0)
  lw    $t9, 0xc($a0)
  sw    $t9, 0x1c($v0)
  lw    $at, ($a0)
  sw    $at, 0x20($v0)
  lw    $t7, 4($a0)
  sw    $t7, 0x24($v0)
  lw    $at, 8($a0)
  sw    $at, 0x28($v0)
  lw    $t7, 0xc($a0)
  sw    $t7, 0x2c($v0)
  lw    $at, ($a0)
  sw    $at, 0x30($v0)
  lw    $t1, 4($a0)
  sw    $t1, 0x34($v0)
  lw    $at, 8($a0)
  sw    $at, 0x38($v0)
  lw    $t1, 0xc($a0)
  sw    $t1, 0x3c($v0)
  lw    $at, ($a0)
  sw    $at, 0x40($v0)
  lw    $t4, 4($a0)
  sw    $t4, 0x44($v0)
  lw    $at, 8($a0)
  sw    $at, 0x48($v0)
  lw    $t4, 0xc($a0)
  sw    $t4, 0x4c($v0)
  lwc1  $f6, ($v1)
  mul.s $f8, $f6, $f0
  swc1  $f8, 0x8c($sp)
  lwc1  $f10, 4($v1)
  mul.s $f4, $f10, $f0
  swc1  $f4, 0x90($sp)
  lwc1  $f6, 8($v1)
  mul.s $f8, $f6, $f0
  swc1  $f8, 0x94($sp)
  lwc1  $f10, ($v1)
  mul.s $f4, $f10, $f12
  swc1  $f4, 0x80($sp)
  lwc1  $f6, 4($v1)
  mul.s $f8, $f6, $f12
  swc1  $f8, 0x84($sp)
  lwc1  $f10, 8($v1)
  mul.s $f4, $f10, $f12
  swc1  $f4, 0x88($sp)
  lwc1  $f6, 0x10($v1)
  mul.s $f8, $f6, $f0
  swc1  $f8, 0x74($sp)
  lwc1  $f10, 0x14($v1)
  mul.s $f4, $f10, $f0
  swc1  $f4, 0x78($sp)
  lwc1  $f6, 0x18($v1)
  mul.s $f8, $f6, $f0
  swc1  $f8, 0x7c($sp)
  lwc1  $f10, 0x10($v1)
  mul.s $f4, $f10, $f12
  swc1  $f4, 0x68($sp)
  lwc1  $f6, 0x14($v1)
  mul.s $f8, $f6, $f12
  swc1  $f8, 0x6c($sp)
  lwc1  $f10, 0x18($v1)
  mul.s $f4, $f10, $f12
  jal   get_room_data_float1
   swc1  $f4, 0x70($sp)
  lwc1  $f6, 0x4c($sp)
  lwc1  $f8, 0x8c($sp)
  lwc1  $f4, 0x68($sp)
  sub.s $f10, $f6, $f8
  sub.s $f6, $f10, $f4
  lwc1  $f10, ($s1)
  mul.s $f8, $f6, $f0
  sub.s $f4, $f8, $f10
  trunc.w.s $f6, $f4
  mfc1  $t6, $f6
  jal   get_room_data_float1
   sh    $t6, ($s0)
  lwc1  $f8, 0x48($sp)
  lwc1  $f10, 0x90($sp)
  lwc1  $f6, 0x6c($sp)
  sub.s $f4, $f8, $f10
  sub.s $f8, $f4, $f6
  lwc1  $f4, 4($s1)
  mul.s $f10, $f8, $f0
  sub.s $f6, $f10, $f4
  trunc.w.s $f8, $f6
  mfc1  $t7, $f8
  jal   get_room_data_float1
   sh    $t7, 2($s0)
  lwc1  $f10, 0x44($sp)
  lwc1  $f4, 0x94($sp)
  lwc1  $f8, 0x70($sp)
  li    $t1, 1760
  sub.s $f6, $f10, $f4
  sub.s $f10, $f6, $f8
  lwc1  $f6, 8($s1)
  sh    $t1, 8($s0)
  sh    $zero, 0xa($s0)
  mul.s $f4, $f10, $f0
  sub.s $f8, $f4, $f6
  trunc.w.s $f10, $f8
  mfc1  $t0, $f10
  jal   get_room_data_float1
   sh    $t0, 4($s0)
  lwc1  $f4, 0x4c($sp)
  lwc1  $f6, 0x80($sp)
  lwc1  $f10, 0x74($sp)
  add.s $f8, $f4, $f6
  sub.s $f4, $f8, $f10
  lwc1  $f8, ($s1)
  mul.s $f6, $f4, $f0
  sub.s $f10, $f6, $f8
  trunc.w.s $f4, $f10
  mfc1  $t3, $f4
  jal   get_room_data_float1
   sh    $t3, 0x10($s0)
  lwc1  $f6, 0x48($sp)
  lwc1  $f8, 0x84($sp)
  lwc1  $f4, 0x78($sp)
  add.s $f10, $f6, $f8
  sub.s $f6, $f10, $f4
  lwc1  $f10, 4($s1)
  mul.s $f8, $f6, $f0
  sub.s $f4, $f8, $f10
  trunc.w.s $f6, $f4
  mfc1  $t9, $f6
  jal   get_room_data_float1
   sh    $t9, 0x12($s0)
  lwc1  $f8, 0x44($sp)
  lwc1  $f10, 0x88($sp)
  lwc1  $f6, 0x7c($sp)
  add.s $f4, $f8, $f10
  sub.s $f8, $f4, $f6
  lwc1  $f4, 8($s1)
  sh    $zero, 0x18($s0)
  sh    $zero, 0x1a($s0)
  mul.s $f10, $f8, $f0
  sub.s $f6, $f10, $f4
  trunc.w.s $f8, $f6
  mfc1  $t8, $f8
  jal   get_room_data_float1
   sh    $t8, 0x14($s0)
  lwc1  $f10, 0x4c($sp)
  lwc1  $f4, 0x8c($sp)
  lwc1  $f8, 0x68($sp)
  add.s $f6, $f10, $f4
  add.s $f10, $f6, $f8
  lwc1  $f6, ($s1)
  mul.s $f4, $f10, $f0
  sub.s $f8, $f4, $f6
  trunc.w.s $f10, $f8
  mfc1  $t2, $f10
  jal   get_room_data_float1
   sh    $t2, 0x20($s0)
  lwc1  $f4, 0x48($sp)
  lwc1  $f6, 0x90($sp)
  lwc1  $f10, 0x6c($sp)
  add.s $f8, $f4, $f6
  add.s $f4, $f8, $f10
  lwc1  $f8, 4($s1)
  mul.s $f6, $f4, $f0
  sub.s $f10, $f6, $f8
  trunc.w.s $f4, $f10
  mfc1  $t1, $f4
  jal   get_room_data_float1
   sh    $t1, 0x22($s0)
  lwc1  $f6, 0x44($sp)
  lwc1  $f8, 0x94($sp)
  lwc1  $f4, 0x70($sp)
  li    $t4, 1760
  add.s $f10, $f6, $f8
  add.s $f6, $f10, $f4
  lwc1  $f10, 8($s1)
  sh    $zero, 0x28($s0)
  sh    $t4, 0x2a($s0)
  mul.s $f8, $f6, $f0
  sub.s $f4, $f8, $f10
  trunc.w.s $f6, $f4
  mfc1  $t3, $f6
  jal   get_room_data_float1
   sh    $t3, 0x24($s0)
  lwc1  $f8, 0x4c($sp)
  lwc1  $f10, 0x80($sp)
  lwc1  $f6, 0x74($sp)
  sub.s $f4, $f8, $f10
  add.s $f8, $f4, $f6
  lwc1  $f4, ($s1)
  mul.s $f10, $f8, $f0
  sub.s $f6, $f10, $f4
  trunc.w.s $f8, $f6
  mfc1  $t6, $f8
  jal   get_room_data_float1
   sh    $t6, 0x30($s0)
  lwc1  $f10, 0x48($sp)
  lwc1  $f4, 0x84($sp)
  lwc1  $f8, 0x78($sp)
  sub.s $f6, $f10, $f4
  add.s $f10, $f6, $f8
  lwc1  $f6, 4($s1)
  mul.s $f4, $f10, $f0
  sub.s $f8, $f4, $f6
  trunc.w.s $f10, $f8
  mfc1  $t7, $f10
  jal   get_room_data_float1
   sh    $t7, 0x32($s0)
  lwc1  $f4, 0x44($sp)
  lwc1  $f6, 0x88($sp)
  lwc1  $f10, 0x7c($sp)
  li    $t1, 1760
  sub.s $f8, $f4, $f6
  li    $t5, 1760
  lui   $t3, (0x04300040 >> 16) # lui $t3, 0x430
  ori   $t3, (0x04300040 & 0xFFFF) # ori $t3, $t3, 0x40
  add.s $f4, $f8, $f10
  lwc1  $f8, 8($s1)
  sh    $t1, 0x38($s0)
  sh    $t5, 0x3a($s0)
  mul.s $f6, $f4, $f0
  move  $a1, $s2
  addiu $s2, $s2, 8
  move  $a0, $s0
  sub.s $f10, $f6, $f8
  trunc.w.s $f4, $f10
  mfc1  $t0, $f4
  nop   
  sh    $t0, 0x34($s0)
  sw    $t3, ($a1)
  jal   osVirtualToPhysical
   sw    $a1, 0x38($sp)
  lw    $a1, 0x38($sp)
  move  $v1, $s2
  lui   $t4, (0xB1000032 >> 16) # lui $t4, 0xb100
  sw    $v0, 4($a1)
  ori   $t4, (0xB1000032 & 0xFFFF) # ori $t4, $t4, 0x32
  li    $t9, 8208
  sw    $t9, 4($v1)
  sw    $t4, ($v1)
  lw    $ra, 0x24($sp)
  addiu $v0, $s2, 8
  lw    $s2, 0x20($sp)
  lw    $s1, 0x1c($sp)
  lw    $s0, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0xb8
");

asm(R"
.late_rodata
glabel D_800576C0
.word 0x46ea6000 /*30000.0*/
glabel D_800576C4
.word 0x46ea6000 /*30000.0*/
glabel D_800576C8
.word 0xc6ea6000 /*-30000.0*/
.text
glabel sub_GAME_7F09DDA4
  addiu $sp, $sp, -0xd8
  lui   $t7, %hi(D_80040910) 
  sw    $ra, 0x34($sp)
  sw    $s5, 0x30($sp)
  sw    $s4, 0x2c($sp)
  sw    $s3, 0x28($sp)
  sw    $s2, 0x24($sp)
  sw    $s1, 0x20($sp)
  sw    $s0, 0x1c($sp)
  sdc1  $f20, 0x10($sp)
  sw    $a2, 0xe0($sp)
  addiu $t7, %lo(D_80040910) # addiu $t7, $t7, 0x910
  lw    $at, ($t7)
  lw    $t0, 4($t7)
  addiu $t6, $sp, 0xc0
  sw    $at, ($t6)
  sw    $t0, 4($t6)
  lw    $t0, 0xc($t7)
  lw    $at, 8($t7)
  move  $s1, $a1
  move  $s2, $a0
  move  $s3, $a3
  sw    $t0, 0xc($t6)
  jal   sub_GAME_7F078444
   sw    $at, 8($t6)
  jal   get_BONDdata_position
   sw    $v0, 0xbc($sp)
  sw    $v0, 0x70($sp)
  lh    $t1, 6($s2)
  li    $s5, 24
  lui   $s4, %hi(D_8004017C)
  multu $t1, $s5
  addiu $s4, %lo(D_8004017C) # addiu $s4, $s4, 0x17c
  lh    $a1, 0x24($s1)
  lw    $v1, 0xbc($sp)
  li    $t8, 1
  mflo  $t2
  addu  $t3, $s4, $t2
  lh    $a0, 2($t3)
  slt   $at, $a0, $a1
  bnezl $at, .L7F09DEF8
   cfc1  $t9, $31
  mtc1  $a0, $f6
  lwc1  $f4, 0x20($s1)
  li    $t5, 1
  cvt.s.w $f8, $f6
  mtc1  $a1, $f6
  li    $at, 0x4F000000 # 2147483648.000000
  div.s $f10, $f4, $f8
  cvt.s.w $f4, $f6
  mul.s $f8, $f10, $f4
  cfc1  $t4, $31
  ctc1  $t5, $31
  nop   
  cvt.w.s $f6, $f8
  cfc1  $t5, $31
  nop   
  andi  $t5, $t5, 0x78
  beql  $t5, $zero, .L7F09DEDC
   mfc1  $t5, $f6
  mtc1  $at, $f6
  li    $t5, 1
  sub.s $f6, $f8, $f6
  ctc1  $t5, $31
  nop   
  cvt.w.s $f6, $f6
  cfc1  $t5, $31
  nop   
  andi  $t5, $t5, 0x78
  bnez  $t5, .L7F09DED0
   nop   
  mfc1  $t5, $f6
  lui   $at, 0x8000
  b     .L7F09DEE8
   or    $t5, $t5, $at
.L7F09DED0:
  b     .L7F09DEE8
   li    $t5, -1
  mfc1  $t5, $f6
.L7F09DEDC:
  nop   
  bltz  $t5, .L7F09DED0
   nop   
.L7F09DEE8:
  ctc1  $t4, $31
  b     .L7F09DF7C
   sb    $t5, 0x77($sp)
  cfc1  $t9, $31
.L7F09DEF8:
  ctc1  $t8, $31
  lwc1  $f10, 0x20($s1)
  li    $at, 0x4F000000 # 2147483648.000000
  cvt.w.s $f4, $f10
  cfc1  $t8, $31
  nop   
  andi  $t8, $t8, 0x78
  beql  $t8, $zero, .L7F09DF64
   mfc1  $t8, $f4
  mtc1  $at, $f4
  li    $t8, 1
  sub.s $f4, $f10, $f4
  ctc1  $t8, $31
  nop   
  cvt.w.s $f4, $f4
  cfc1  $t8, $31
  nop   
  andi  $t8, $t8, 0x78
  bnez  $t8, .L7F09DF58
   nop   
  mfc1  $t8, $f4
  lui   $at, 0x8000
  b     .L7F09DF70
   or    $t8, $t8, $at
.L7F09DF58:
  b     .L7F09DF70
   li    $t8, -1
  mfc1  $t8, $f4
.L7F09DF64:
  nop   
  bltz  $t8, .L7F09DF58
   nop   
.L7F09DF70:
  ctc1  $t9, $31
  sb    $t8, 0x77($sp)
  nop   
.L7F09DF7C:
  li    $a0, 4
  jal   sub_GAME_7F0BD6C4
   sw    $v1, 0xbc($sp)
  addiu $a0, $sp, 0xc0
  lw    $at, ($a0)
  move  $s0, $v0
  sw    $at, ($v0)
  lw    $t0, 4($a0)
  sw    $t0, 4($v0)
  lw    $at, 8($a0)
  sw    $at, 8($v0)
  lw    $t0, 0xc($a0)
  sw    $t0, 0xc($v0)
  lw    $at, ($a0)
  sw    $at, 0x10($v0)
  lw    $t3, 4($a0)
  sw    $t3, 0x14($v0)
  lw    $at, 8($a0)
  sw    $at, 0x18($v0)
  lw    $t3, 0xc($a0)
  sw    $t3, 0x1c($v0)
  lw    $at, ($a0)
  sw    $at, 0x20($v0)
  lw    $t9, 4($a0)
  sw    $t9, 0x24($v0)
  lw    $at, 8($a0)
  sw    $at, 0x28($v0)
  lw    $t9, 0xc($a0)
  sw    $t9, 0x2c($v0)
  lw    $at, ($a0)
  sw    $at, 0x30($v0)
  lw    $t6, 4($a0)
  sw    $t6, 0x34($v0)
  lw    $at, 8($a0)
  sw    $at, 0x38($v0)
  lw    $t6, 0xc($a0)
  sw    $t6, 0x3c($v0)
  jal   cosf
   lwc1  $f12, 0x10($s1)
  lwc1  $f8, 0xc($s1)
  lwc1  $f12, 0x10($s1)
  mul.s $f14, $f0, $f8
  jal   sinf
   swc1  $f14, 0x88($sp)
  lwc1  $f6, 0xc($s1)
  lwc1  $f12, 0x18($s1)
  mul.s $f16, $f0, $f6
  jal   sinf
   swc1  $f16, 0x84($sp)
  li    $at, 0x40E00000 # 7.000000
  mtc1  $at, $f10
  lwc1  $f8, ($s1)
  mul.s $f4, $f0, $f10
  add.s $f6, $f4, $f8
  swc1  $f6, 0x80($sp)
  lwc1  $f10, 4($s1)
  swc1  $f10, 0x7c($sp)
  jal   sinf
   lwc1  $f12, 0x1c($s1)
  li    $at, 0x40E00000 # 7.000000
  mtc1  $at, $f4
  lwc1  $f6, 8($s1)
  lw    $v0, 0x70($sp)
  mul.s $f8, $f0, $f4
  lwc1  $f4, 0x80($sp)
  add.s $f10, $f8, $f6
  lwc1  $f6, 0x7c($sp)
  swc1  $f10, 0x78($sp)
  lwc1  $f8, ($v0)
  sub.s $f20, $f4, $f8
  lwc1  $f4, 4($v0)
  lwc1  $f8, 8($v0)
  sub.s $f18, $f6, $f4
  mul.s $f6, $f20, $f20
  sub.s $f2, $f10, $f8
  mul.s $f4, $f18, $f18
  swc1  $f18, 0x68($sp)
  mul.s $f8, $f2, $f2
  swc1  $f2, 0x64($sp)
  add.s $f10, $f6, $f4
  jal   sqrtf
   add.s $f12, $f10, $f8
  lui    $at, %hi(D_800576C0)
  lwc1  $f6, %lo(D_800576C0)($at)
  lw    $v1, 0xbc($sp)
  lwc1  $f14, 0x88($sp)
  c.lt.s $f6, $f0
  lwc1  $f16, 0x84($sp)
  lwc1  $f18, 0x68($sp)
  li    $at, 0x3F000000 # 0.500000
  bc1fl .L7F09E0F8
   mtc1  $at, $f4
  b     .L7F09E6D8
   lw    $v0, 0xe0($sp)
  mtc1  $at, $f4
.L7F09E0F8:
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f10
  mul.s $f12, $f0, $f4
  mtc1  $zero, $f8
  li    $at, 0x42C80000 # 100.000000
  c.lt.s $f10, $f12
  nop   
  bc1fl .L7F09E128
   c.eq.s $f0, $f8
  mtc1  $at, $f12
  nop   
  c.eq.s $f0, $f8
.L7F09E128:
  nop   
  bc1fl .L7F09E144
   sub.s $f6, $f0, $f12
  mtc1  $zero, $f2
  b     .L7F09E148
   nop   
  sub.s $f6, $f0, $f12
.L7F09E144:
  div.s $f2, $f6, $f0
.L7F09E148:
  mul.s $f14, $f14, $f2
  lw    $v0, 0x70($sp)
  mul.s $f16, $f16, $f2
  lwc1  $f4, ($v0)
  mul.s $f10, $f20, $f2
  add.s $f8, $f4, $f10
  mul.s $f4, $f18, $f2
  swc1  $f8, 0x80($sp)
  lwc1  $f6, 4($v0)
  add.s $f10, $f6, $f4
  lwc1  $f6, 0x64($sp)
  mul.s $f4, $f6, $f2
  swc1  $f10, 0x7c($sp)
  lwc1  $f8, 8($v0)
  add.s $f10, $f8, $f4
  swc1  $f10, 0x78($sp)
  lwc1  $f6, ($v1)
  mul.s $f8, $f6, $f14
  swc1  $f8, 0xb0($sp)
  lwc1  $f4, 4($v1)
  mul.s $f10, $f4, $f14
  swc1  $f10, 0xb4($sp)
  lwc1  $f6, 8($v1)
  mul.s $f8, $f6, $f14
  swc1  $f8, 0xb8($sp)
  lwc1  $f4, ($v1)
  mul.s $f10, $f4, $f16
  swc1  $f10, 0xa4($sp)
  lwc1  $f6, 4($v1)
  mul.s $f8, $f6, $f16
  swc1  $f8, 0xa8($sp)
  lwc1  $f4, 8($v1)
  mul.s $f10, $f4, $f16
  swc1  $f10, 0xac($sp)
  lwc1  $f6, 0x10($v1)
  mul.s $f8, $f6, $f14
  swc1  $f8, 0x98($sp)
  lwc1  $f4, 0x14($v1)
  mul.s $f10, $f4, $f14
  swc1  $f10, 0x9c($sp)
  lwc1  $f6, 0x18($v1)
  mul.s $f8, $f6, $f14
  swc1  $f8, 0xa0($sp)
  lwc1  $f4, 0x10($v1)
  mul.s $f10, $f4, $f16
  swc1  $f10, 0x8c($sp)
  lwc1  $f6, 0x14($v1)
  mul.s $f8, $f6, $f16
  swc1  $f8, 0x90($sp)
  lwc1  $f4, 0x18($v1)
  mul.s $f10, $f4, $f16
  jal   get_room_data_float1
   swc1  $f10, 0x94($sp)
  lwc1  $f6, 0x80($sp)
  lwc1  $f8, 0xb0($sp)
  lwc1  $f10, 0x8c($sp)
  li    $at, 0x41200000 # 10.000000
  sub.s $f4, $f6, $f8
  mtc1  $at, $f20
  sub.s $f6, $f4, $f10
  lwc1  $f4, ($s3)
  mul.s $f8, $f6, $f0
  sub.s $f10, $f8, $f4
  mul.s $f2, $f10, $f20
  jal   get_room_data_float1
   swc1  $f2, 0x54($sp)
  lwc1  $f6, 0x7c($sp)
  lwc1  $f8, 0xb4($sp)
  lwc1  $f10, 0x90($sp)
  sub.s $f4, $f6, $f8
  sub.s $f6, $f4, $f10
  lwc1  $f4, 4($s3)
  mul.s $f8, $f6, $f0
  sub.s $f10, $f8, $f4
  mul.s $f12, $f10, $f20
  jal   get_room_data_float1
   swc1  $f12, 0x50($sp)
  lwc1  $f6, 0x78($sp)
  lwc1  $f8, 0xb8($sp)
  lwc1  $f10, 0x94($sp)
  lui   $at, %hi(D_800576C4)
  sub.s $f4, $f6, $f8
  lwc1  $f16, %lo(D_800576C4)($at)
  lwc1  $f2, 0x54($sp)
  lwc1  $f12, 0x50($sp)
  sub.s $f6, $f4, $f10
  lwc1  $f4, 8($s3)
  lui   $at, %hi(D_800576C8)
  c.lt.s $f16, $f2
  mul.s $f8, $f6, $f0
  sub.s $f10, $f8, $f4
  mul.s $f14, $f10, $f20
  bc1t  .L7F09E314
   nop   
  lwc1  $f0, %lo(D_800576C8)($at)
  c.lt.s $f2, $f0
  nop   
  bc1t  .L7F09E314
   nop   
  c.lt.s $f16, $f12
  nop   
  bc1t  .L7F09E314
   nop   
  c.lt.s $f12, $f0
  nop   
  bc1t  .L7F09E314
   nop   
  c.lt.s $f16, $f14
  nop   
  bc1t  .L7F09E314
   nop   
  c.lt.s $f14, $f0
  nop   
  bc1fl .L7F09E320
   trunc.w.s $f6, $f2
.L7F09E314:
  b     .L7F09E6D8
   lw    $v0, 0xe0($sp)
  trunc.w.s $f6, $f2
.L7F09E320:
  li    $t9, 1760
  sh    $t9, 8($s0)
  trunc.w.s $f8, $f12
  mfc1  $t2, $f6
  sh    $zero, 0xa($s0)
  trunc.w.s $f4, $f14
  mfc1  $t3, $f8
  sh    $t2, ($s0)
  mfc1  $t4, $f4
  sh    $t3, 2($s0)
  sh    $t4, 4($s0)
  lh    $t7, 6($s2)
  multu $t7, $s5
  mflo  $t8
  addu  $t6, $s4, $t8
  lbu   $t0, 0xc($t6)
  sb    $t0, 0xc($s0)
  lh    $t2, 6($s2)
  multu $t2, $s5
  mflo  $t1
  addu  $t3, $s4, $t1
  lbu   $t5, 0xd($t3)
  sb    $t5, 0xd($s0)
  lh    $t4, 6($s2)
  multu $t4, $s5
  mflo  $t9
  addu  $t7, $s4, $t9
  lbu   $t8, 0xe($t7)
  sb    $t8, 0xe($s0)
  lbu   $t6, 0x77($sp)
  jal   get_room_data_float1
   sb    $t6, 0xf($s0)
  lwc1  $f10, 0x80($sp)
  lwc1  $f6, 0xa4($sp)
  lwc1  $f4, 0x98($sp)
  add.s $f8, $f10, $f6
  sub.s $f10, $f8, $f4
  lwc1  $f8, ($s3)
  mul.s $f6, $f10, $f0
  sub.s $f4, $f6, $f8
  mul.s $f10, $f4, $f20
  trunc.w.s $f6, $f10
  mfc1  $t2, $f6
  jal   get_room_data_float1
   sh    $t2, 0x10($s0)
  lwc1  $f8, 0x7c($sp)
  lwc1  $f4, 0xa8($sp)
  lwc1  $f6, 0x9c($sp)
  add.s $f10, $f8, $f4
  sub.s $f8, $f10, $f6
  lwc1  $f10, 4($s3)
  mul.s $f4, $f8, $f0
  sub.s $f6, $f4, $f10
  mul.s $f8, $f6, $f20
  trunc.w.s $f4, $f8
  mfc1  $t3, $f4
  jal   get_room_data_float1
   sh    $t3, 0x12($s0)
  lwc1  $f10, 0x78($sp)
  lwc1  $f6, 0xac($sp)
  lwc1  $f4, 0xa0($sp)
  add.s $f8, $f10, $f6
  sub.s $f10, $f8, $f4
  lwc1  $f8, 8($s3)
  sh    $zero, 0x18($s0)
  sh    $zero, 0x1a($s0)
  mul.s $f6, $f10, $f0
  sub.s $f4, $f6, $f8
  mul.s $f10, $f4, $f20
  trunc.w.s $f6, $f10
  mfc1  $t4, $f6
  nop   
  sh    $t4, 0x14($s0)
  lh    $t9, 6($s2)
  multu $t9, $s5
  mflo  $t7
  addu  $t8, $s4, $t7
  lbu   $t6, 0xc($t8)
  sb    $t6, 0x1c($s0)
  lh    $t0, 6($s2)
  multu $t0, $s5
  mflo  $t2
  addu  $t1, $s4, $t2
  lbu   $t3, 0xd($t1)
  sb    $t3, 0x1d($s0)
  lh    $t5, 6($s2)
  multu $t5, $s5
  mflo  $t4
  addu  $t9, $s4, $t4
  lbu   $t7, 0xe($t9)
  sb    $t7, 0x1e($s0)
  lbu   $t8, 0x77($sp)
  jal   get_room_data_float1
   sb    $t8, 0x1f($s0)
  lwc1  $f8, 0x80($sp)
  lwc1  $f4, 0xb0($sp)
  lwc1  $f6, 0x8c($sp)
  add.s $f10, $f8, $f4
  add.s $f8, $f10, $f6
  lwc1  $f10, ($s3)
  mul.s $f4, $f8, $f0
  sub.s $f6, $f4, $f10
  mul.s $f8, $f6, $f20
  trunc.w.s $f4, $f8
  mfc1  $t0, $f4
  jal   get_room_data_float1
   sh    $t0, 0x20($s0)
  lwc1  $f10, 0x7c($sp)
  lwc1  $f6, 0xb4($sp)
  lwc1  $f4, 0x90($sp)
  add.s $f8, $f10, $f6
  add.s $f10, $f8, $f4
  lwc1  $f8, 4($s3)
  mul.s $f6, $f10, $f0
  sub.s $f4, $f6, $f8
  mul.s $f10, $f4, $f20
  trunc.w.s $f6, $f10
  mfc1  $t1, $f6
  jal   get_room_data_float1
   sh    $t1, 0x22($s0)
  lwc1  $f8, 0x78($sp)
  lwc1  $f4, 0xb8($sp)
  lwc1  $f6, 0x94($sp)
  li    $t4, 1760
  add.s $f10, $f8, $f4
  add.s $f8, $f10, $f6
  lwc1  $f10, 8($s3)
  sh    $zero, 0x28($s0)
  sh    $t4, 0x2a($s0)
  mul.s $f4, $f8, $f0
  sub.s $f6, $f4, $f10
  mul.s $f8, $f6, $f20
  trunc.w.s $f4, $f8
  mfc1  $t5, $f4
  nop   
  sh    $t5, 0x24($s0)
  lh    $t9, 6($s2)
  multu $t9, $s5
  mflo  $t7
  addu  $t8, $s4, $t7
  lbu   $t6, 0xc($t8)
  sb    $t6, 0x2c($s0)
  lh    $t0, 6($s2)
  multu $t0, $s5
  mflo  $t2
  addu  $t1, $s4, $t2
  lbu   $t3, 0xd($t1)
  sb    $t3, 0x2d($s0)
  lh    $t5, 6($s2)
  multu $t5, $s5
  mflo  $t4
  addu  $t9, $s4, $t4
  lbu   $t7, 0xe($t9)
  sb    $t7, 0x2e($s0)
  lbu   $t8, 0x77($sp)
  jal   get_room_data_float1
   sb    $t8, 0x2f($s0)
  lwc1  $f10, 0x80($sp)
  lwc1  $f6, 0xa4($sp)
  lwc1  $f4, 0x98($sp)
  sub.s $f8, $f10, $f6
  add.s $f10, $f8, $f4
  lwc1  $f8, ($s3)
  mul.s $f6, $f10, $f0
  sub.s $f4, $f6, $f8
  mul.s $f10, $f4, $f20
  trunc.w.s $f6, $f10
  mfc1  $t0, $f6
  jal   get_room_data_float1
   sh    $t0, 0x30($s0)
  lwc1  $f8, 0x7c($sp)
  lwc1  $f4, 0xa8($sp)
  lwc1  $f6, 0x9c($sp)
  sub.s $f10, $f8, $f4
  add.s $f8, $f10, $f6
  lwc1  $f10, 4($s3)
  mul.s $f4, $f8, $f0
  sub.s $f6, $f4, $f10
  mul.s $f8, $f6, $f20
  trunc.w.s $f4, $f8
  mfc1  $t1, $f4
  jal   get_room_data_float1
   sh    $t1, 0x32($s0)
  lwc1  $f10, 0x78($sp)
  lwc1  $f6, 0xac($sp)
  lwc1  $f4, 0xa0($sp)
  li    $t4, 1760
  sub.s $f8, $f10, $f6
  li    $t9, 1760
  move  $a0, $s0
  add.s $f10, $f8, $f4
  lwc1  $f8, 8($s3)
  sh    $t4, 0x38($s0)
  sh    $t9, 0x3a($s0)
  mul.s $f6, $f10, $f0
  sub.s $f4, $f6, $f8
  mul.s $f10, $f4, $f20
  trunc.w.s $f6, $f10
  mfc1  $t5, $f6
  nop   
  sh    $t5, 0x34($s0)
  lh    $t7, 6($s2)
  multu $t7, $s5
  mflo  $t8
  addu  $t6, $s4, $t8
  lbu   $t0, 0xc($t6)
  sb    $t0, 0x3c($s0)
  lh    $t2, 6($s2)
  multu $t2, $s5
  mflo  $t1
  addu  $t3, $s4, $t1
  lbu   $t5, 0xd($t3)
  lui   $t1, (0x04300040 >> 16) # lui $t1, 0x430
  ori   $t1, (0x04300040 & 0xFFFF) # ori $t1, $t1, 0x40
  sb    $t5, 0x3d($s0)
  lh    $t4, 6($s2)
  multu $t4, $s5
  mflo  $t9
  addu  $t7, $s4, $t9
  lbu   $t8, 0xe($t7)
  sb    $t8, 0x3e($s0)
  lbu   $t6, 0x77($sp)
  sb    $t6, 0x3f($s0)
  lw    $s1, 0xe0($sp)
  addiu $t2, $s1, 8
  sw    $t2, 0xe0($sp)
  jal   osVirtualToPhysical
   sw    $t1, ($s1)
  sw    $v0, 4($s1)
  lw    $t3, 0xe0($sp)
  lui   $t4, (0xB1000032 >> 16) # lui $t4, 0xb100
  ori   $t4, (0xB1000032 & 0xFFFF) # ori $t4, $t4, 0x32
  addiu $t5, $t3, 8
  sw    $t5, 0xe0($sp)
  li    $t9, 8208
  sw    $t9, 4($t3)
  sw    $t4, ($t3)
  lw    $v0, 0xe0($sp)
.L7F09E6D8:
  lw    $ra, 0x34($sp)
  ldc1  $f20, 0x10($sp)
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  lw    $s2, 0x24($sp)
  lw    $s3, 0x28($sp)
  lw    $s4, 0x2c($sp)
  lw    $s5, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0xd8
");

asm(R"
glabel sub_GAME_7F09E700
  addiu $sp, $sp, -0x30
  sw    $ra, 0x14($sp)
  sw    $a0, 0x30($sp)
  sw    $a1, 0x34($sp)
  sw    $a2, 0x38($sp)
  sw    $a3, 0x3c($sp)
  jal   getPlayerCount
   sw    $zero, 0x2c($sp)
  lui   $t3, %hi(D_8004017C) 
  lui   $a3, %hi(ptr_smoke_buf)
  lw    $t5, 0x2c($sp)
  addiu $a3, %lo(ptr_smoke_buf) # addiu $a3, $a3, -0x5ec0
  addiu $t3, %lo(D_8004017C) # addiu $t3, $t3, 0x17c
  move  $a0, $zero
  li    $t4, 24
  li    $t2, 9
  li    $t1, 8
  li    $t0, 7
  lw    $a1, ($a3)
.L7F09E74C:
  slti  $at, $v0, 2
  addu  $t6, $a1, $a0
  lw    $t7, ($t6)
  addu  $a2, $a0, $a1
  bnez  $t7, .L7F09E76C
   nop   
  b     .L7F09E7B0
   addu  $t5, $a0, $a1
.L7F09E76C:
  bnez  $at, .L7F09E7A4
   addiu $a0, $a0, 0x198
  lh    $v1, 6($a2)
  beql  $t0, $v1, .L7F09E7A8
   slti  $at, $a0, 0x1fe0
  beql  $t1, $v1, .L7F09E7A8
   slti  $at, $a0, 0x1fe0
  beql  $t2, $v1, .L7F09E7A8
   slti  $at, $a0, 0x1fe0
  multu $v1, $t4
  mflo  $t8
  addu  $t9, $t3, $t8
  lh    $t6, ($t9)
  sh    $t6, 4($a2)
.L7F09E7A4:
  slti  $at, $a0, 0x1fe0
.L7F09E7A8:
  bnezl $at, .L7F09E74C
   lw    $a1, ($a3)
.L7F09E7B0:
  beql  $t5, $zero, .L7F09E8A0
   lw    $ra, 0x14($sp)
  jal   remove_last_obj_pos_data_entry
   sw    $t5, 0x2c($sp)
  li    $t0, 7
  lw    $t5, 0x2c($sp)
  lw    $ra, 0x30($sp)
  beqz  $v0, .L7F09E89C
   sw    $v0, 0x1c($sp)
  lbu   $t8, 1($v0)
  lw    $t1, 0x3c($sp)
  li    $t7, 8
  ori   $t9, $t8, 2
  sb    $t7, ($v0)
  sb    $t9, 1($v0)
  sw    $t5, 4($v0)
  lw    $t6, 0x34($sp)
  li    $a3, 255
  move  $a2, $zero
  sw    $t6, 0x14($v0)
  lwc1  $f4, ($ra)
  addu  $a1, $v0, $zero
  li    $t8, 255
  swc1  $f4, 8($v0)
  lwc1  $f6, 4($ra)
  addu  $v1, $t1, $zero
  swc1  $f6, 0xc($v0)
  lwc1  $f8, 8($ra)
  swc1  $f8, 0x10($v0)
  lbu   $t7, ($t1)
  beq   $a3, $t7, .L7F09E850
   andi  $a0, $t7, 0xff
  sb    $a0, 0x2c($a1)
.L7F09E834:
  lbu   $a0, 1($v1)
  addiu $a2, $a2, 1
  addiu $v1, $v1, 1
  beq   $a3, $a0, .L7F09E850
   addiu $a1, $a1, 1
  bnel  $a2, $t0, .L7F09E834
   sb    $a0, 0x2c($a1)
.L7F09E850:
  addu  $t9, $v0, $a2
  sb    $t8, 0x2c($t9)
  lw    $t6, 0x40($sp)
  beql  $t6, $zero, .L7F09E874
   lw    $a0, 0x1c($sp)
  lbu   $t7, 1($v0)
  ori   $t8, $t7, 8
  sb    $t8, 1($v0)
  lw    $a0, 0x1c($sp)
.L7F09E874:
  jal   sub_GAME_7F03A4F0
   sw    $t5, 0x2c($sp)
  jal   set_stateflag_0x04_for_posdata
   lw    $a0, 0x1c($sp)
  lw    $t5, 0x2c($sp)
  lw    $t9, 0x1c($sp)
  sh    $zero, 4($t5)
  sw    $t9, ($t5)
  lh    $t6, 0x3a($sp)
  sh    $t6, 6($t5)
.L7F09E89C:
  lw    $ra, 0x14($sp)
.L7F09E8A0:
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_800576CC
.word 0x3e19999a /*0.15000001*/
glabel D_800576D0
.word 0x3e99999a /*0.30000001*/
glabel D_800576D4
.word 0x3c23d70a /*0.0099999998*/
glabel D_800576D8
.word 0x3ca3d70a /*0.02*/
glabel D_800576DC
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F09E8AC
  addiu $sp, $sp, -0xd0
  lui   $v0, %hi(clock_timer)
  lw    $v0, %lo(clock_timer)($v0)
  sw    $ra, 0x6c($sp)
  sw    $fp, 0x68($sp)
  sw    $s7, 0x64($sp)
  sw    $s6, 0x60($sp)
  sw    $s5, 0x5c($sp)
  sw    $s4, 0x58($sp)
  sw    $s3, 0x54($sp)
  sw    $s2, 0x50($sp)
  sw    $s1, 0x4c($sp)
  sw    $s0, 0x48($sp)
  sdc1  $f30, 0x40($sp)
  sdc1  $f28, 0x38($sp)
  sdc1  $f26, 0x30($sp)
  sdc1  $f24, 0x28($sp)
  sdc1  $f22, 0x20($sp)
  sdc1  $f20, 0x18($sp)
  move  $s7, $a0
  bnez  $v0, .L7F09E90C
   lw    $s3, 4($a0)
  b     .L7F09EF54
   move  $v0, $zero
.L7F09E90C:
  slti  $at, $v0, 0xf
  beql  $at, $zero, .L7F09E928
   lui   $at, 0x4170
  mtc1  $v0, $f4
  b     .L7F09E930
   cvt.s.w $f0, $f4
  li    $at, 0x41700000 # 15.000000
.L7F09E928:
  mtc1  $at, $f0
  nop   
.L7F09E930:
  trunc.w.s $f6, $f0
  lui   $s5, %hi(D_8004017C)
  addiu $s5, %lo(D_8004017C) # addiu $s5, $s5, 0x17c
  move  $fp, $zero
  mfc1  $t7, $f6
  lui   $at, %hi(D_800576CC)
  li    $s6, 24
  blez  $t7, .L7F09ED44
   sw    $t7, 0x8c($sp)
  lwc1  $f30, %lo(D_800576CC)($at)
  lui    $at, %hi(D_800576D0)
  lwc1  $f28, %lo(D_800576D0)($at)
  lui    $at, %hi(D_800576D4)
  lwc1  $f24, %lo(D_800576D4)($at)
  lui    $at, %hi(D_800576D8)
  lwc1  $f22, %lo(D_800576D8)($at)
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f20
  mtc1  $zero, $f26
  li    $s4, 400
  lh    $t9, 4($s3)
.L7F09E984:
  move  $v0, $zero
  move  $s2, $zero
  addiu $t0, $t9, 1
  sh    $t0, 4($s3)
  move  $s1, $s3
.L7F09E998:
  lwc1  $f8, 0x14($s1)
  c.eq.s $f26, $f8
  nop   
  bc1tl .L7F09EA98
   addiu $s2, $s2, 0x28
  addiu $s0, $s1, 8
  lwc1  $f10, 4($s0)
  lwc1  $f18, 0xc($s0)
  lwc1  $f6, 0x20($s0)
  add.s $f16, $f10, $f28
  lh    $t4, 0x24($s0)
  add.s $f4, $f18, $f30
  swc1  $f16, 4($s0)
  lwc1  $f16, 0x10($s0)
  lwc1  $f18, 0x14($s0)
  swc1  $f4, 0xc($s0)
  lh    $t1, 6($s3)
  add.s $f4, $f16, $f18
  addiu $t5, $t4, 1
  multu $t1, $s6
  mflo  $t2
  addu  $t3, $s5, $t2
  lwc1  $f8, 0x10($t3)
  sh    $t5, 0x24($s0)
  swc1  $f4, 0x10($s0)
  sub.s $f10, $f6, $f8
  jal   get_random_value
   swc1  $f10, 0x20($s0)
  mtc1  $v0, $f8
  lwc1  $f6, 0x18($s0)
  bgez  $v0, .L7F09EA28
   cvt.s.w $f10, $f8
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f16
  nop   
  add.s $f10, $f10, $f16
.L7F09EA28:
  mul.s $f18, $f10, $f20
  nop   
  mul.s $f4, $f18, $f24
  add.s $f8, $f22, $f4
  add.s $f16, $f6, $f8
  jal   get_random_value
   swc1  $f16, 0x18($s0)
  mtc1  $v0, $f18
  lwc1  $f10, 0x1c($s0)
  bgez  $v0, .L7F09EA64
   cvt.s.w $f4, $f18
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f6
  nop   
  add.s $f4, $f4, $f6
.L7F09EA64:
  mul.s $f8, $f4, $f20
  li    $at, 0x40800000 # 4.000000
  lwc1  $f4, 0x20($s0)
  mul.s $f16, $f8, $f24
  mtc1  $at, $f8
  nop   
  c.lt.s $f4, $f8
  add.s $f18, $f22, $f16
  add.s $f6, $f10, $f18
  bc1f  .L7F09EA94
   swc1  $f6, 0x1c($s0)
  swc1  $f26, 0xc($s0)
.L7F09EA94:
  addiu $s2, $s2, 0x28
.L7F09EA98:
  slti  $at, $s2, 0x190
  bnez  $at, .L7F09E998
   addiu $s1, $s1, 0x28
  lh    $t6, 6($s3)
  lh    $v1, 4($s3)
  multu $t6, $s6
  mflo  $t7
  addu  $a0, $s5, $t7
  lh    $t8, ($a0)
  slt   $at, $v1, $t8
  beql  $at, $zero, .L7F09ED38
   lw    $t3, 0x8c($sp)
  lh    $t9, 4($a0)
  move  $s2, $zero
  move  $s1, $s3
  div   $zero, $v1, $t9
  bnez  $t9, .L7F09EAE4
   nop   
  break 7
.L7F09EAE4:
  li    $at, -1
  bne   $t9, $at, .L7F09EAFC
   li    $at, 0x80000000 # -0.000000
  bne   $v1, $at, .L7F09EAFC
   nop   
  break 6
.L7F09EAFC:
  li    $at, 1
  mfhi  $t0
  bnel  $t0, $at, .L7F09ED38
   lw    $t3, 0x8c($sp)
.L7F09EB0C:
  lwc1  $f16, 0x14($s1)
  addiu $s2, $s2, 0x28
  c.eq.s $f26, $f16
  nop   
  bc1f  .L7F09ED2C
   nop   
  jal   get_random_value
   nop   
  mtc1  $v0, $f10
  addiu $s0, $s1, 8
  bgez  $v0, .L7F09EB4C
   cvt.s.w $f18, $f10
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f6
  nop   
  add.s $f18, $f18, $f6
.L7F09EB4C:
  lh    $t1, 6($s3)
  mul.s $f4, $f18, $f20
  li    $at, 0x3F000000 # 0.500000
  multu $t1, $s6
  mtc1  $at, $f8
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  mul.s $f16, $f4, $f8
  mflo  $t2
  addu  $t3, $s5, $t2
  lh    $t4, 6($t3)
  add.s $f6, $f16, $f10
  mtc1  $t4, $f18
  nop   
  cvt.s.w $f4, $f18
  mul.s $f8, $f6, $f4
  jal   get_random_value
   swc1  $f8, 0xc($s0)
  li    $at, 70
  divu  $zero, $v0, $at
  mfhi  $t5
  mtc1  $t5, $f16
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $t5, .L7F09EBBC
   cvt.s.w $f10, $f16
  mtc1  $at, $f18
  nop   
  add.s $f10, $f10, $f18
.L7F09EBBC:
  li    $at, 0x42DC0000 # 110.000000
  mtc1  $at, $f6
  sh    $zero, 0x24($s0)
  add.s $f4, $f10, $f6
  jal   get_random_value
   swc1  $f4, 0x20($s0)
  mtc1  $v0, $f8
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F09EBF0
   cvt.s.w $f16, $f8
  mtc1  $at, $f18
  nop   
  add.s $f16, $f16, $f18
.L7F09EBF0:
  mul.s $f10, $f16, $f20
  lui    $at, %hi(D_800576DC)
  lwc1  $f6, %lo(D_800576DC)($at)
  mul.s $f4, $f10, $f6
  jal   get_random_value
   swc1  $f4, 0x10($s0)
  mtc1  $v0, $f18
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f8
  bgez  $v0, .L7F09EC2C
   cvt.s.w $f16, $f18
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f10
  nop   
  add.s $f16, $f16, $f10
.L7F09EC2C:
  lh    $t6, 6($s3)
  mul.s $f6, $f16, $f20
  sub.s $f4, $f8, $f6
  multu $t6, $s6
  mflo  $t7
  addu  $t8, $s5, $t7
  lwc1  $f18, 8($t8)
  mul.s $f10, $f18, $f4
  swc1  $f10, 0x14($s0)
  lwc1  $f16, 8($s7)
  swc1  $f16, ($s0)
  lwc1  $f8, 0xc($s7)
  swc1  $f8, 4($s0)
  lwc1  $f6, 0x10($s7)
  jal   get_random_value
   swc1  $f6, 8($s0)
  mtc1  $v0, $f18
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F09EC88
   cvt.s.w $f4, $f18
  mtc1  $at, $f10
  nop   
  add.s $f4, $f4, $f10
.L7F09EC88:
  mul.s $f16, $f4, $f20
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f8
  nop   
  mul.s $f6, $f16, $f8
  jal   get_random_value
   swc1  $f6, 0x18($s0)
  mtc1  $v0, $f18
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F09ECC0
   cvt.s.w $f10, $f18
  mtc1  $at, $f4
  nop   
  add.s $f10, $f10, $f4
.L7F09ECC0:
  mul.s $f16, $f10, $f20
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f8
  nop   
  mul.s $f6, $f16, $f8
  swc1  $f6, 0x1c($s0)
  lh    $t9, 6($s3)
  lh    $v1, 4($s3)
  multu $t9, $s6
  mflo  $t0
  addu  $a0, $s5, $t0
  lh    $a1, ($a0)
  lh    $a2, 0x14($a0)
  subu  $t1, $a1, $a2
  slt   $at, $t1, $v1
  beql  $at, $zero, .L7F09ED38
   lw    $t3, 0x8c($sp)
  subu  $t2, $a1, $v1
  mtc1  $t2, $f18
  mtc1  $a2, $f10
  lwc1  $f6, 0x20($s0)
  cvt.s.w $f4, $f18
  cvt.s.w $f16, $f10
  div.s $f8, $f4, $f16
  mul.s $f18, $f6, $f8
  b     .L7F09ED34
   swc1  $f18, 0x20($s0)
.L7F09ED2C:
  bne   $s2, $s4, .L7F09EB0C
   addiu $s1, $s1, 0x28
.L7F09ED34:
  lw    $t3, 0x8c($sp)
.L7F09ED38:
  addiu $fp, $fp, 1
  bnel  $fp, $t3, .L7F09E984
   lh    $t9, 4($s3)
.L7F09ED44:
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  lwc1  $f10, 8($s7)
  mtc1  $at, $f8
  mtc1  $zero, $f26
  sub.s $f16, $f10, $f4
  mtc1  $at, $f4
  lui   $s5, %hi(D_8004017C)
  addiu $s5, %lo(D_8004017C) # addiu $s5, $s5, 0x17c
  swc1  $f16, 0xa8($sp)
  lwc1  $f6, 0xc($s7)
  li    $s6, 24
  move  $s2, $zero
  sub.s $f18, $f6, $f8
  mtc1  $at, $f8
  move  $s1, $s3
  addiu $s0, $sp, 0x9c
  swc1  $f18, 0xac($sp)
  lwc1  $f10, 0x10($s7)
  addiu $a2, $sp, 0xb4
  mov.s $f14, $f26
  sub.s $f16, $f10, $f4
  mtc1  $at, $f4
  swc1  $f16, 0xb0($sp)
  lwc1  $f6, 8($s7)
  add.s $f18, $f6, $f8
  mtc1  $at, $f8
  swc1  $f18, 0x9c($sp)
  lwc1  $f10, 0xc($s7)
  add.s $f16, $f10, $f4
  swc1  $f16, 0xa0($sp)
  lwc1  $f6, 0x10($s7)
  add.s $f18, $f6, $f8
  swc1  $f18, 0xa4($sp)
.L7F09EDCC:
  lwc1  $f10, 0x14($s1)
  addiu $s2, $s2, 0x28
  slti  $at, $s2, 0x190
  c.eq.s $f26, $f10
  move  $a0, $zero
  move  $a1, $s1
  addiu $v0, $sp, 0xa8
  bc1t  .L7F09EE44
   nop   
.L7F09EDF0:
  lwc1  $f4, 8($a1)
  lwc1  $f16, 0x14($s1)
  lwc1  $f6, ($v0)
  addiu $a1, $a1, 4
  sub.s $f0, $f4, $f16
  addu  $v1, $s0, $a0
  c.lt.s $f0, $f6
  nop   
  bc1fl .L7F09EE24
   lwc1  $f8, ($v1)
  b     .L7F09EE38
   swc1  $f0, ($v0)
  lwc1  $f8, ($v1)
.L7F09EE24:
  c.lt.s $f8, $f0
  nop   
  bc1fl .L7F09EE3C
   addiu $v0, $v0, 4
  swc1  $f0, ($v1)
.L7F09EE38:
  addiu $v0, $v0, 4
.L7F09EE3C:
  bne   $v0, $a2, .L7F09EDF0
   addiu $a0, $a0, 4
.L7F09EE44:
  bnez  $at, .L7F09EDCC
   addiu $s1, $s1, 0x28
  lwc1  $f0, 8($s7)
  lwc1  $f18, 0xa8($sp)
  lwc1  $f10, 0xb0($sp)
  lwc1  $f4, 0x9c($sp)
  sub.s $f2, $f0, $f18
  lwc1  $f16, 0xa4($sp)
  move  $a0, $s7
  addiu $a1, $sp, 0xa8
  c.lt.s $f26, $f2
  nop   
  bc1fl .L7F09EE84
   lwc1  $f2, 0x10($s7)
  mov.s $f14, $f2
  lwc1  $f2, 0x10($s7)
.L7F09EE84:
  sub.s $f12, $f2, $f10
  c.lt.s $f14, $f12
  nop   
  bc1fl .L7F09EEA0
   sub.s $f12, $f4, $f0
  mov.s $f14, $f12
  sub.s $f12, $f4, $f0
.L7F09EEA0:
  sub.s $f0, $f16, $f2
  c.lt.s $f14, $f12
  nop   
  bc1fl .L7F09EEBC
   c.lt.s $f14, $f0
  mov.s $f14, $f12
  c.lt.s $f14, $f0
.L7F09EEBC:
  nop   
  bc1fl .L7F09EED0
   mfc1  $a3, $f14
  mov.s $f14, $f0
  mfc1  $a3, $f14
.L7F09EED0:
  jal   sub_GAME_7F03E27C
   move  $a2, $s0
  lh    $t4, 6($s3)
  lh    $t8, 4($s3)
  move  $s2, $zero
  multu $t4, $s6
  move  $s1, $s3
  li    $v0, 400
  move  $v1, $zero
  mflo  $t5
  addu  $t6, $s5, $t5
  lh    $t7, 4($t6)
  slt   $at, $t7, $t8
  beqz  $at, .L7F09EF40
   nop   
  li    $v1, 1
.L7F09EF10:
  lwc1  $f6, 0x14($s1)
  addiu $s2, $s2, 0x28
  c.lt.s $f26, $f6
  nop   
  bc1f  .L7F09EF30
   nop   
  b     .L7F09EF40
   move  $v1, $zero
.L7F09EF30:
  bne   $s2, $v0, .L7F09EF10
   addiu $s1, $s1, 0x28
  b     .L7F09EF40
   nop   
.L7F09EF40:
  beqz  $v1, .L7F09EF54
   move  $v0, $zero
  sw    $zero, ($s3)
  b     .L7F09EF54
   li    $v0, 1
.L7F09EF54:
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
   addiu $sp, $sp, 0xd0
");

asm(R"
glabel sub_GAME_7F09EF9C
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   get_BONDdata_field_10CC
   sw    $a0, 0x18($sp)
  lw    $a0, 0x18($sp)
  lwc1  $f4, 8($v0)
  lwc1  $f10, 0x18($v0)
  lwc1  $f6, 8($a0)
  lwc1  $f16, 0xc($a0)
  li    $at, 0x42C80000 # 100.000000
  mul.s $f8, $f4, $f6
  lwc1  $f6, 0x28($v0)
  mtc1  $at, $f2
  mul.s $f18, $f10, $f16
  lwc1  $f10, 0x10($a0)
  li    $at, 0x3F000000 # 0.500000
  mul.s $f16, $f6, $f10
  add.s $f4, $f8, $f18
  lwc1  $f18, 0x38($v0)
  add.s $f8, $f4, $f16
  add.s $f6, $f18, $f8
  neg.s $f10, $f6
  swc1  $f10, 0x18($a0)
  lwc1  $f0, 0x18($a0)
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F09F024
   sub.s $f18, $f0, $f2
  mtc1  $at, $f4
  nop   
  mul.s $f16, $f0, $f4
  b     .L7F09F028
   swc1  $f16, 0x18($a0)
  sub.s $f18, $f0, $f2
.L7F09F024:
  swc1  $f18, 0x18($a0)
.L7F09F028:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  move  $v0, $zero
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F09F03C
  addiu $sp, $sp, -0x90
  sw    $s0, 0x24($sp)
  sw    $ra, 0x3c($sp)
  sw    $s5, 0x38($sp)
  sw    $s4, 0x34($sp)
  sw    $s3, 0x30($sp)
  sw    $s2, 0x2c($sp)
  sw    $s1, 0x28($sp)
  sdc1  $f20, 0x18($sp)
  lbu   $s1, 0x2c($a0)
  move  $s0, $a0
  lw    $s4, 4($a0)
  move  $s2, $a1
  move  $s3, $a2
  jal   sub_GAME_7F0BCA14
   move  $a0, $s1
  bnez  $s3, .L7F09F08C
   move  $s5, $v0
  b     .L7F09F22C
   move  $v0, $s2
.L7F09F08C:
  move  $a0, $s0
  jal   sub_GAME_7F054A64
   addiu $a1, $sp, 0x78
  blez  $v0, .L7F09F0C4
   nop   
  lwc1  $f4, 0x84($sp)
  move  $a0, $s2
  lw    $a1, 0x78($sp)
  lw    $a2, 0x7c($sp)
  lw    $a3, 0x80($sp)
  jal   sub_GAME_7F0B4FF4
   swc1  $f4, 0x10($sp)
  b     .L7F09F0D0
   move  $s2, $v0
.L7F09F0C4:
  jal   sub_GAME_7F0B4FB4
   move  $a0, $s2
  move  $s2, $v0
.L7F09F0D0:
  move  $v0, $s2
  lui   $t7, (0x00013000 >> 16) # lui $t7, 1
  ori   $t7, (0x00013000 & 0xFFFF) # ori $t7, $t7, 0x3000
  addiu $s2, $s2, 8
  lui   $t6, 0xb600
  lui   $t8, (0x01030040 >> 16) # lui $t8, 0x103
  sw    $t6, ($v0)
  sw    $t7, 4($v0)
  ori   $t8, (0x01030040 & 0xFFFF) # ori $t8, $t8, 0x40
  move  $s0, $s2
  sw    $t8, ($s0)
  jal   get_BONDdata_field_10E0
   addiu $s2, $s2, 8
  jal   osVirtualToPhysical
   move  $a0, $v0
  sw    $v0, 4($s0)
  move  $a0, $s2
  jal   sub_GAME_7F0BC9C4
   move  $a1, $s1
  lui   $t9, (0x01000040 >> 16) # lui $t9, 0x100
  ori   $t9, (0x01000040 & 0xFFFF) # ori $t9, $t9, 0x40
  lui   $a0, %hi(dword_CODE_bss_8007A100)
  addiu $a0, %lo(dword_CODE_bss_8007A100) # addiu $a0, $a0, -0x5f00
  sw    $t9, ($v0)
  move  $s0, $v0
  jal   osVirtualToPhysical
   addiu $s2, $v0, 8
  lui   $t0, (0xBC000806 >> 16) # lui $t0, 0xbc00
  sw    $v0, 4($s0)
  ori   $t0, (0xBC000806 & 0xFFFF) # ori $t0, $t0, 0x806
  move  $s3, $s2
  sw    $t0, ($s3)
  lui   $a0, %hi(pGlobalimagetable)
  lw    $a0, %lo(pGlobalimagetable)($a0)
  jal   osVirtualToPhysical
   addiu $s2, $s2, 8
  sw    $v0, 4($s3)
  move  $v1, $s2
  addiu $s2, $s2, 8
  lui   $t2, 0x200
  addiu $t2, $t2, 0
  lui   $t1, 0x600
  move  $a0, $s2
  sw    $t1, ($v1)
  sw    $t2, 4($v1)
  lui   $t3, (0xBA000602 >> 16) # lui $t3, 0xba00
  ori   $t3, (0xBA000602 & 0xFFFF) # ori $t3, $t3, 0x602
  li    $t4, 128
  mtc1  $zero, $f20
  sw    $t4, 4($a0)
  sw    $t3, ($a0)
  addiu $s2, $s2, 8
  li    $s3, 400
  move  $s1, $zero
  move  $s0, $s4
.L7F09F1AC:
  lwc1  $f6, 0x14($s0)
  move  $a0, $s4
  addiu $a1, $s0, 8
  c.lt.s $f20, $f6
  move  $a2, $s2
  bc1fl .L7F09F1DC
   swc1  $f20, 0x14($s0)
  jal   sub_GAME_7F09DDA4
   move  $a3, $s5
  b     .L7F09F1DC
   move  $s2, $v0
  swc1  $f20, 0x14($s0)
.L7F09F1DC:
  addiu $s1, $s1, 0x28
  bne   $s1, $s3, .L7F09F1AC
   addiu $s0, $s0, 0x28
  move  $v0, $s2
  lui   $t5, (0xBA000602 >> 16) # lui $t5, 0xba00
  ori   $t5, (0xBA000602 & 0xFFFF) # ori $t5, $t5, 0x602
  addiu $s2, $s2, 8
  li    $t6, 64
  lui   $t7, (0x01030040 >> 16) # lui $t7, 0x103
  sw    $t6, 4($v0)
  sw    $t5, ($v0)
  ori   $t7, (0x01030040 & 0xFFFF) # ori $t7, $t7, 0x40
  move  $s0, $s2
  sw    $t7, ($s0)
  jal   get_BONDdata_field_10D8
   addiu $s2, $s2, 8
  jal   osVirtualToPhysical
   move  $a0, $v0
  sw    $v0, 4($s0)
  move  $v0, $s2
.L7F09F22C:
  lw    $ra, 0x3c($sp)
  ldc1  $f20, 0x18($sp)
  lw    $s0, 0x24($sp)
  lw    $s1, 0x28($sp)
  lw    $s2, 0x2c($sp)
  lw    $s3, 0x30($sp)
  lw    $s4, 0x34($sp)
  lw    $s5, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x90
");

asm(R"
.late_rodata
glabel D_800576E0
.word 0x3f8f5c29 /*1.12*/
glabel D_800576E4
.word 0x3df5c28f /*0.12*/
glabel D_800576E8
.word 0x40c90fdb /*6.2831855*/
glabel D_800576EC
.word 0x3dcccccd /*0.1*/

.text
glabel sub_GAME_7F09F254
  addiu $sp, $sp, -0x50
  sw    $ra, 0x34($sp)
  sw    $s2, 0x30($sp)
  sw    $s1, 0x2c($sp)
  sw    $s0, 0x28($sp)
  sdc1  $f22, 0x20($sp)
  sdc1  $f20, 0x18($sp)
  sw    $a0, 0x50($sp)
  sw    $a1, 0x54($sp)
  sw    $a2, 0x58($sp)
  jal   get_random_value
   sw    $a3, 0x5c($sp)
  mtc1  $v0, $f4
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f22
  bgez  $v0, .L7F09F2A8
   cvt.s.w $f6, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F09F2A8:
  mul.s $f0, $f6, $f22
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f18
  add.s $f10, $f0, $f0
  jal   get_random_value
   sub.s $f20, $f10, $f18
  mtc1  $v0, $f4
  bgez  $v0, .L7F09F2DC
   cvt.s.w $f8, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f6
  nop   
  add.s $f8, $f8, $f6
.L7F09F2DC:
  mul.s $f10, $f8, $f22
  lui   $at, %hi(D_800576E0)
  lwc1  $f18, %lo(D_800576E0)($at)
  lui   $at, %hi(D_800576E4)
  lwc1  $f6, %lo(D_800576E4)($at)
  mul.s $f4, $f10, $f18
  sub.s $f12, $f4, $f6
  jal   get_random_value
   swc1  $f12, 0x48($sp)
  lui   $s2, %hi(D_8004017C+0x684)
  addiu $s2, %lo(D_8004017C+0x684) # addiu $s2, $s2, 0x800
  lw    $t8, ($s2)
  li    $s1, 120
  lui   $s0, %hi(ptr_ejected_casing_buf)
  multu $t8, $s1
  addiu $s0, %lo(ptr_ejected_casing_buf) # addiu $s0, $s0, -0x5eb4
  lw    $t7, ($s0)
  lw    $v1, 0x50($sp)
  lwc1  $f12, 0x48($sp)
  lwc1  $f14, 0x54($sp)
  lwc1  $f16, 0x58($sp)
  li    $t6, 1
  mul.s $f10, $f14, $f20
  mflo  $t9
  addu  $t0, $t7, $t9
  sw    $t6, ($t0)
  lw    $t2, ($s2)
  lwc1  $f8, ($v1)
  lw    $t1, ($s0)
  multu $t2, $s1
  add.s $f18, $f8, $f10
  mul.s $f6, $f14, $f12
  mtc1  $v0, $f10
  mflo  $t3
  addu  $t4, $t1, $t3
  swc1  $f18, 4($t4)
  lw    $t8, ($s2)
  lwc1  $f4, 4($v1)
  lw    $t5, ($s0)
  multu $t8, $s1
  add.s $f8, $f4, $f6
  cvt.s.w $f18, $f10
  mflo  $t7
  addu  $t9, $t5, $t7
  bgez  $v0, .L7F09F3A4
   swc1  $f8, 8($t9)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f4
  nop   
  add.s $f18, $f18, $f4
.L7F09F3A4:
  mul.s $f0, $f18, $f22
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  lw    $t0, ($s2)
  lwc1  $f10, 8($v1)
  lw    $t6, ($s0)
  multu $t0, $s1
  add.s $f6, $f0, $f0
  sub.s $f2, $f6, $f8
  mul.s $f4, $f14, $f2
  mflo  $t2
  addu  $t1, $t6, $t2
  mul.s $f6, $f20, $f16
  add.s $f18, $f10, $f4
  swc1  $f18, 0xc($t1)
  lw    $t4, ($s2)
  lw    $t3, ($s0)
  multu $t4, $s1
  mflo  $t8
  addu  $t5, $t3, $t8
  swc1  $f6, 0x1c($t5)
  lw    $t9, ($s2)
  lwc1  $f8, 0x5c($sp)
  lw    $t7, ($s0)
  multu $t9, $s1
  mul.s $f10, $f12, $f8
  nop   
  mul.s $f4, $f2, $f16
  mflo  $t0
  addu  $t6, $t7, $t0
  swc1  $f10, 0x20($t6)
  lw    $t1, ($s2)
  lw    $t2, ($s0)
  multu $t1, $s1
  mflo  $t4
  addu  $t3, $t2, $t4
  jal   get_random_value
   swc1  $f4, 0x24($t3)
  mtc1  $v0, $f18
  li    $at, 0x3F400000 # 0.750000
  mtc1  $at, $f20
  bgez  $v0, .L7F09F460
   cvt.s.w $f6, $f18
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F09F460:
  mul.s $f10, $f6, $f22
  lwc1  $f8, 0x60($sp)
  lw    $t7, ($s2)
  lw    $t9, ($s0)
  multu $t7, $s1
  mul.s $f4, $f10, $f20
  add.s $f18, $f4, $f20
  mflo  $t0
  addu  $t6, $t9, $t0
  mul.s $f6, $f18, $f8
  trunc.w.s $f10, $f6
  mfc1  $t5, $f10
  nop   
  sh    $t5, 0x38($t6)
  lw    $t2, ($s2)
  lw    $t1, ($s0)
  multu $t2, $s1
  mflo  $t4
  addu  $t3, $t1, $t4
  jal   get_random_value
   sh    $zero, 0x3a($t3)
  mtc1  $v0, $f4
  bgez  $v0, .L7F09F4D0
   cvt.s.w $f18, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f8
  nop   
  add.s $f18, $f18, $f8
.L7F09F4D0:
  mul.s $f6, $f18, $f22
  lwc1  $f8, 0x60($sp)
  lw    $t0, ($s2)
  lw    $t9, ($s0)
  multu $t0, $s1
  mul.s $f10, $f6, $f20
  add.s $f4, $f10, $f20
  mflo  $t5
  addu  $t6, $t9, $t5
  mul.s $f18, $f4, $f8
  trunc.w.s $f6, $f18
  mfc1  $t7, $f6
  jal   get_random_value
   sh    $t7, 0x3c($t6)
  mtc1  $v0, $f10
  bgez  $v0, .L7F09F524
   cvt.s.w $f4, $f10
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f8
  nop   
  add.s $f4, $f4, $f8
.L7F09F524:
  mul.s $f18, $f4, $f22
  lwc1  $f8, 0x60($sp)
  lw    $t3, ($s2)
  lw    $t4, ($s0)
  multu $t3, $s1
  mul.s $f6, $f18, $f20
  add.s $f10, $f6, $f20
  mflo  $t8
  addu  $t0, $t4, $t8
  mul.s $f4, $f10, $f8
  trunc.w.s $f18, $f4
  mfc1  $t1, $f18
  nop   
  sh    $t1, 0x48($t0)
  lw    $t5, ($s2)
  lw    $t9, ($s0)
  multu $t5, $s1
  mflo  $t7
  addu  $t6, $t9, $t7
  jal   get_random_value
   sh    $zero, 0x4a($t6)
  lwc1  $f0, 0x60($sp)
  mtc1  $v0, $f6
  neg.s $f0, $f0
  bgez  $v0, .L7F09F59C
   cvt.s.w $f10, $f6
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f8
  nop   
  add.s $f10, $f10, $f8
.L7F09F59C:
  mul.s $f4, $f10, $f22
  lw    $t8, ($s2)
  lw    $t4, ($s0)
  multu $t8, $s1
  mul.s $f18, $f4, $f20
  add.s $f6, $f18, $f20
  mflo  $t1
  addu  $t0, $t4, $t1
  mul.s $f8, $f6, $f0
  trunc.w.s $f10, $f8
  mfc1  $t3, $f10
  nop   
  sh    $t3, 0x4c($t0)
  jal   get_random_value
   swc1  $f0, 0x38($sp)
  mtc1  $v0, $f4
  bgez  $v0, .L7F09F5F4
   cvt.s.w $f18, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f6
  nop   
  add.s $f18, $f18, $f6
.L7F09F5F4:
  mul.s $f8, $f18, $f22
  lwc1  $f6, 0x38($sp)
  lw    $t6, ($s2)
  lw    $t7, ($s0)
  multu $t6, $s1
  mul.s $f10, $f8, $f20
  add.s $f4, $f10, $f20
  mflo  $t2
  addu  $t8, $t7, $t2
  mul.s $f18, $f4, $f6
  trunc.w.s $f8, $f18
  mfc1  $t9, $f8
  nop   
  sh    $t9, 0x58($t8)
  lw    $t1, ($s2)
  lw    $t4, ($s0)
  multu $t1, $s1
  mflo  $t3
  addu  $t0, $t4, $t3
  jal   get_random_value
   sh    $zero, 0x5a($t0)
  mtc1  $v0, $f10
  bgez  $v0, .L7F09F664
   cvt.s.w $f4, $f10
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f6
  nop   
  add.s $f4, $f4, $f6
.L7F09F664:
  mul.s $f18, $f4, $f22
  lwc1  $f6, 0x38($sp)
  lw    $t2, ($s2)
  lw    $t7, ($s0)
  multu $t2, $s1
  mul.s $f8, $f18, $f20
  add.s $f10, $f8, $f20
  mflo  $t9
  addu  $t8, $t7, $t9
  mul.s $f4, $f10, $f6
  trunc.w.s $f18, $f4
  mfc1  $t6, $f18
  jal   get_random_value
   sh    $t6, 0x5c($t8)
  mtc1  $v0, $f8
  bgez  $v0, .L7F09F6B8
   cvt.s.w $f10, $f8
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f6
  nop   
  add.s $f10, $f10, $f6
.L7F09F6B8:
  mul.s $f4, $f10, $f22
  lwc1  $f6, 0x38($sp)
  lw    $t0, ($s2)
  lw    $t3, ($s0)
  multu $t0, $s1
  mul.s $f18, $f4, $f20
  add.s $f8, $f18, $f20
  mflo  $t5
  addu  $t2, $t3, $t5
  mul.s $f10, $f8, $f6
  trunc.w.s $f4, $f10
  mfc1  $t4, $f4
  nop   
  sh    $t4, 0x68($t2)
  lw    $t9, ($s2)
  lw    $t7, ($s0)
  multu $t9, $s1
  mflo  $t6
  addu  $t8, $t7, $t6
  jal   get_random_value
   sh    $zero, 0x6a($t8)
  mtc1  $v0, $f18
  bgez  $v0, .L7F09F728
   cvt.s.w $f8, $f18
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f6
  nop   
  add.s $f8, $f8, $f6
.L7F09F728:
  mul.s $f10, $f8, $f22
  lwc1  $f6, 0x60($sp)
  lw    $t5, ($s2)
  lw    $t3, ($s0)
  multu $t5, $s1
  mul.s $f4, $f10, $f20
  add.s $f18, $f4, $f20
  mflo  $t4
  addu  $t2, $t3, $t4
  mul.s $f8, $f18, $f6
  trunc.w.s $f10, $f8
  mfc1  $t0, $f10
  jal   get_random_value
   sh    $t0, 0x6c($t2)
  andi  $a2, $v0, 3
  sll   $t6, $a2, 8
  jal   get_random_value
   sh    $t6, 0x42($sp)
  lw    $t1, ($s2)
  lh    $a2, 0x42($sp)
  lw    $t8, ($s0)
  multu $t1, $s1
  addiu $a0, $a2, 0xe0
  andi  $v1, $v0, 3
  sll   $t0, $v1, 8
  addiu $a1, $t0, 0xe0
  move  $v1, $t0
  mflo  $t5
  addu  $t3, $t8, $t5
  sh    $a0, 0x40($t3)
  lw    $t9, ($s2)
  lw    $t2, ($s0)
  multu $t9, $s1
  mflo  $t7
  addu  $t6, $t2, $t7
  sh    $a1, 0x42($t6)
  lw    $t8, ($s2)
  lw    $t1, ($s0)
  multu $t8, $s1
  mflo  $t5
  addu  $t3, $t1, $t5
  sh    $a0, 0x50($t3)
  lw    $t0, ($s2)
  lw    $t4, ($s0)
  multu $t0, $s1
  mflo  $t9
  addu  $t2, $t4, $t9
  sh    $v1, 0x52($t2)
  lw    $t6, ($s2)
  lw    $t7, ($s0)
  multu $t6, $s1
  mflo  $t8
  addu  $t1, $t7, $t8
  sh    $a2, 0x60($t1)
  lw    $t3, ($s2)
  lw    $t5, ($s0)
  multu $t3, $s1
  mflo  $t0
  addu  $t4, $t5, $t0
  sh    $v1, 0x62($t4)
  lw    $t2, ($s2)
  lw    $t9, ($s0)
  multu $t2, $s1
  mflo  $t6
  addu  $t7, $t9, $t6
  sh    $a2, 0x70($t7)
  lw    $t1, ($s2)
  lw    $t8, ($s0)
  multu $t1, $s1
  mflo  $t3
  addu  $t5, $t8, $t3
  jal   get_random_value
   sh    $a1, 0x72($t5)
  andi  $t0, $v0, 1
  beqz  $t0, .L7F09F9C0
   nop   
  jal   get_random_value
   nop   
  lw    $t6, ($s2)
  lw    $t9, ($s0)
  andi  $t4, $v0, 0x3f
  multu $t6, $s1
  li    $t2, 255
  subu  $v1, $t2, $t4
  mflo  $t7
  addu  $t1, $t9, $t7
  sb    $v1, 0x46($t1)
  lw    $t3, ($s2)
  lw    $t8, ($s0)
  multu $t3, $s1
  mflo  $t5
  addu  $t0, $t8, $t5
  sb    $v1, 0x45($t0)
  lw    $t4, ($s2)
  lw    $t2, ($s0)
  multu $t4, $s1
  mflo  $t6
  addu  $t9, $t2, $t6
  jal   get_random_value
   sb    $v1, 0x44($t9)
  lw    $t8, ($s2)
  lw    $t3, ($s0)
  andi  $t7, $v0, 0x3f
  multu $t8, $s1
  li    $t1, 255
  subu  $v1, $t1, $t7
  mflo  $t5
  addu  $t0, $t3, $t5
  sb    $v1, 0x56($t0)
  lw    $t2, ($s2)
  lw    $t4, ($s0)
  multu $t2, $s1
  mflo  $t6
  addu  $t9, $t4, $t6
  sb    $v1, 0x55($t9)
  lw    $t7, ($s2)
  lw    $t1, ($s0)
  multu $t7, $s1
  mflo  $t8
  addu  $t3, $t1, $t8
  jal   get_random_value
   sb    $v1, 0x54($t3)
  lw    $t4, ($s2)
  lw    $t2, ($s0)
  andi  $t5, $v0, 0x3f
  multu $t4, $s1
  li    $t0, 255
  subu  $v1, $t0, $t5
  mflo  $t6
  addu  $t9, $t2, $t6
  sb    $v1, 0x66($t9)
  lw    $t1, ($s2)
  lw    $t7, ($s0)
  multu $t1, $s1
  mflo  $t8
  addu  $t3, $t7, $t8
  sb    $v1, 0x65($t3)
  lw    $t5, ($s2)
  lw    $t0, ($s0)
  multu $t5, $s1
  mflo  $t4
  addu  $t2, $t0, $t4
  jal   get_random_value
   sb    $v1, 0x64($t2)
  lw    $t7, ($s2)
  lw    $t1, ($s0)
  andi  $t6, $v0, 0x3f
  multu $t7, $s1
  li    $t9, 255
  subu  $v1, $t9, $t6
  mflo  $t8
  addu  $t3, $t1, $t8
  sb    $v1, 0x76($t3)
  lw    $t0, ($s2)
  lw    $t5, ($s0)
  multu $t0, $s1
  mflo  $t4
  addu  $t2, $t5, $t4
  sb    $v1, 0x75($t2)
  lw    $t6, ($s2)
  lw    $t9, ($s0)
  multu $t6, $s1
  mflo  $t7
  addu  $t1, $t9, $t7
  b     .L7F09FB04
   sb    $v1, 0x74($t1)
.L7F09F9C0:
  jal   get_random_value
   nop   
  lw    $t3, ($s2)
  lw    $t8, ($s0)
  andi  $v1, $v0, 0x3f
  multu $t3, $s1
  mflo  $t0
  addu  $t5, $t8, $t0
  sb    $v1, 0x46($t5)
  lw    $t2, ($s2)
  lw    $t4, ($s0)
  multu $t2, $s1
  mflo  $t6
  addu  $t9, $t4, $t6
  sb    $v1, 0x45($t9)
  lw    $t1, ($s2)
  lw    $t7, ($s0)
  multu $t1, $s1
  mflo  $t3
  addu  $t8, $t7, $t3
  jal   get_random_value
   sb    $v1, 0x44($t8)
  lw    $t5, ($s2)
  lw    $t0, ($s0)
  andi  $v1, $v0, 0x3f
  multu $t5, $s1
  mflo  $t2
  addu  $t4, $t0, $t2
  sb    $v1, 0x56($t4)
  lw    $t9, ($s2)
  lw    $t6, ($s0)
  multu $t9, $s1
  mflo  $t1
  addu  $t7, $t6, $t1
  sb    $v1, 0x55($t7)
  lw    $t8, ($s2)
  lw    $t3, ($s0)
  multu $t8, $s1
  mflo  $t5
  addu  $t0, $t3, $t5
  jal   get_random_value
   sb    $v1, 0x54($t0)
  lw    $t4, ($s2)
  lw    $t2, ($s0)
  andi  $v1, $v0, 0x3f
  multu $t4, $s1
  mflo  $t9
  addu  $t6, $t2, $t9
  sb    $v1, 0x66($t6)
  lw    $t7, ($s2)
  lw    $t1, ($s0)
  multu $t7, $s1
  mflo  $t8
  addu  $t3, $t1, $t8
  sb    $v1, 0x65($t3)
  lw    $t0, ($s2)
  lw    $t5, ($s0)
  multu $t0, $s1
  mflo  $t4
  addu  $t2, $t5, $t4
  jal   get_random_value
   sb    $v1, 0x64($t2)
  lw    $t6, ($s2)
  lw    $t9, ($s0)
  andi  $v1, $v0, 0x3f
  multu $t6, $s1
  mflo  $t7
  addu  $t1, $t9, $t7
  sb    $v1, 0x76($t1)
  lw    $t3, ($s2)
  lw    $t8, ($s0)
  multu $t3, $s1
  mflo  $t0
  addu  $t5, $t8, $t0
  sb    $v1, 0x75($t5)
  lw    $t2, ($s2)
  lw    $t4, ($s0)
  multu $t2, $s1
  mflo  $t6
  addu  $t9, $t4, $t6
  sb    $v1, 0x74($t9)
.L7F09FB04:
  lw    $t1, ($s2)
  lw    $t7, ($s0)
  li    $v0, 220
  multu $t1, $s1
  mflo  $t3
  addu  $t8, $t7, $t3
  sb    $v0, 0x47($t8)
  lw    $t5, ($s2)
  lw    $t0, ($s0)
  multu $t5, $s1
  mflo  $t2
  addu  $t4, $t0, $t2
  sb    $v0, 0x57($t4)
  lw    $t9, ($s2)
  lw    $t6, ($s0)
  multu $t9, $s1
  mflo  $t1
  addu  $t7, $t6, $t1
  sb    $v0, 0x67($t7)
  lw    $t8, ($s2)
  lw    $t3, ($s0)
  multu $t8, $s1
  mflo  $t5
  addu  $t0, $t3, $t5
  jal   get_random_value
   sb    $v0, 0x77($t0)
  mtc1  $v0, $f4
  lui   $at, %hi(D_800576E8)
  lwc1  $f20, %lo(D_800576E8)($at)
  bgez  $v0, .L7F09FB90
   cvt.s.w $f18, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f6
  nop   
  add.s $f18, $f18, $f6
.L7F09FB90:
  lw    $t4, ($s2)
  mul.s $f8, $f18, $f22
  lw    $t2, ($s0)
  multu $t4, $s1
  mul.s $f10, $f8, $f20
  mflo  $t9
  addu  $t6, $t2, $t9
  jal   get_random_value
   swc1  $f10, 0x10($t6)
  mtc1  $v0, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F09FBD0
   cvt.s.w $f6, $f4
  mtc1  $at, $f18
  nop   
  add.s $f6, $f6, $f18
.L7F09FBD0:
  lw    $t7, ($s2)
  mul.s $f8, $f6, $f22
  lw    $t1, ($s0)
  multu $t7, $s1
  mul.s $f10, $f8, $f20
  mflo  $t8
  addu  $t3, $t1, $t8
  jal   get_random_value
   swc1  $f10, 0x14($t3)
  mtc1  $v0, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F09FC10
   cvt.s.w $f18, $f4
  mtc1  $at, $f6
  nop   
  add.s $f18, $f18, $f6
.L7F09FC10:
  lw    $t0, ($s2)
  mul.s $f8, $f18, $f22
  lw    $t5, ($s0)
  multu $t0, $s1
  mul.s $f10, $f8, $f20
  mflo  $t4
  addu  $t2, $t5, $t4
  jal   get_random_value
   swc1  $f10, 0x18($t2)
  mtc1  $v0, $f4
  lui   $at, %hi(D_800576EC)
  lwc1  $f20, %lo(D_800576EC)($at)
  bgez  $v0, .L7F09FC58
   cvt.s.w $f6, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f18
  nop   
  add.s $f6, $f6, $f18
.L7F09FC58:
  lw    $t6, ($s2)
  mul.s $f8, $f6, $f22
  lw    $t9, ($s0)
  multu $t6, $s1
  mul.s $f10, $f8, $f20
  mflo  $t7
  addu  $t1, $t9, $t7
  jal   get_random_value
   swc1  $f10, 0x28($t1)
  mtc1  $v0, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F09FC98
   cvt.s.w $f18, $f4
  mtc1  $at, $f6
  nop   
  add.s $f18, $f18, $f6
.L7F09FC98:
  lw    $t3, ($s2)
  mul.s $f8, $f18, $f22
  lw    $t8, ($s0)
  multu $t3, $s1
  mul.s $f10, $f8, $f20
  mflo  $t0
  addu  $t5, $t8, $t0
  jal   get_random_value
   swc1  $f10, 0x2c($t5)
  mtc1  $v0, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F09FCD8
   cvt.s.w $f6, $f4
  mtc1  $at, $f18
  nop   
  add.s $f6, $f6, $f18
.L7F09FCD8:
  lw    $t2, ($s2)
  mul.s $f8, $f6, $f22
  lw    $t4, ($s0)
  multu $t2, $s1
  lui   $t8, %hi(max_casings) 
  mul.s $f10, $f8, $f20
  mflo  $t6
  addu  $t9, $t4, $t6
  swc1  $f10, 0x30($t9)
  lw    $t7, ($s2)
  addiu $t1, $t7, 1
  sw    $t1, ($s2)
  lw    $t8, %lo(max_casings)($t8)
  slt   $at, $t1, $t8
  bnezl $at, .L7F09FD20
   lw    $ra, 0x34($sp)
  sw    $zero, ($s2)
  lw    $ra, 0x34($sp)
.L7F09FD20:
  ldc1  $f20, 0x18($sp)
  ldc1  $f22, 0x20($sp)
  lw    $s0, 0x28($sp)
  lw    $s1, 0x2c($sp)
  lw    $s2, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x50
");

asm(R"
.late_rodata
glabel D_800576F0
.word 0x46ea6000 /*30000.0*/
glabel D_800576F4
.word 0xc6ea6000 /*-30000.0*/
glabel D_800576F8
.word 0x3e4ccccd /*0.2*/
.text
glabel sub_GAME_7F09FD3C
  addiu $sp, $sp, -0x58
  lui   $v0, %hi(clock_timer)
  lw    $v0, %lo(clock_timer)($v0)
  sw    $ra, 0x54($sp)
  sw    $s4, 0x50($sp)
  slti  $at, $v0, 0xf
  sw    $s3, 0x4c($sp)
  sw    $s2, 0x48($sp)
  sw    $s1, 0x44($sp)
  sw    $s0, 0x40($sp)
  sdc1  $f28, 0x38($sp)
  sdc1  $f26, 0x30($sp)
  sdc1  $f24, 0x28($sp)
  sdc1  $f22, 0x20($sp)
  beqz  $at, .L7F09FD88
   sdc1  $f20, 0x18($sp)
  mtc1  $v0, $f4
  b     .L7F09FD94
   cvt.s.w $f24, $f4
.L7F09FD88:
  li    $at, 0x41700000 # 15.000000
  mtc1  $at, $f24
  nop   
.L7F09FD94:
  lui   $s4, %hi(max_casings)
  addiu $s4, %lo(max_casings) # addiu $s4, $s4, -0x5eb8
  lw    $t6, ($s4)
  move  $s2, $zero
  move  $s0, $zero
  blez  $t6, .L7F0A0000
   lui   $at, %hi(D_800576F0)
  lwc1  $f28, %lo(D_800576F0)($at)
  lui   $at, %hi(D_800576F4)
  lwc1  $f26, %lo(D_800576F4)($at)
  lui   $at, %hi(D_800576F8)
  lwc1  $f22, %lo(D_800576F8)($at)
  li    $at, 0xC0700000 # -3.750000
  lui   $s1, %hi(ptr_ejected_casing_buf)
  mtc1  $at, $f20
  addiu $s1, %lo(ptr_ejected_casing_buf) # addiu $s1, $s1, -0x5eb4
  li    $s3, 300
  lw    $t7, ($s1)
.L7F09FDDC:
  addu  $v0, $t7, $s0
  lw    $a1, ($v0)
  blezl $a1, .L7F09FFEC
   lw    $t9, ($s4)
  trunc.w.s $f6, $f24
  move  $v1, $zero
  mfc1  $a0, $f6
  nop   
  addu  $t9, $a1, $a0
  sw    $t9, ($v0)
  lw    $t0, ($s1)
  addu  $v0, $t0, $s0
  lwc1  $f10, 0x28($v0)
  lwc1  $f8, 0x10($v0)
  mul.s $f16, $f10, $f24
  add.s $f18, $f8, $f16
  swc1  $f18, 0x10($v0)
  lw    $t1, ($s1)
  addu  $v0, $t1, $s0
  lwc1  $f6, 0x2c($v0)
  lwc1  $f4, 0x14($v0)
  mul.s $f10, $f6, $f24
  add.s $f8, $f4, $f10
  swc1  $f8, 0x14($v0)
  lw    $t2, ($s1)
  addu  $v0, $t2, $s0
  lwc1  $f18, 0x30($v0)
  lwc1  $f16, 0x18($v0)
  mul.s $f6, $f18, $f24
  add.s $f4, $f16, $f6
  swc1  $f4, 0x18($v0)
  lw    $t3, ($s1)
  addu  $v0, $t3, $s0
  lwc1  $f8, 0x1c($v0)
  lwc1  $f10, 4($v0)
  mul.s $f18, $f8, $f24
  add.s $f16, $f10, $f18
  swc1  $f16, 4($v0)
  lw    $t4, ($s1)
  addu  $v0, $t4, $s0
  lwc1  $f4, 0x24($v0)
  lwc1  $f6, 0xc($v0)
  mul.s $f8, $f4, $f24
  add.s $f10, $f6, $f8
  blez  $a0, .L7F09FF6C
   swc1  $f10, 0xc($v0)
  andi  $v0, $a0, 1
  beql  $v0, $zero, .L7F09FEEC
   lw    $t7, ($s1)
  lw    $t5, ($s1)
  li    $v1, 1
  addu  $v0, $t5, $s0
  lwc1  $f18, 8($v0)
  lwc1  $f16, 0x20($v0)
  add.s $f4, $f18, $f16
  swc1  $f4, 8($v0)
  lw    $t6, ($s1)
  addu  $v0, $t6, $s0
  lwc1  $f0, 0x20($v0)
  c.lt.s $f20, $f0
  nop   
  bc1f  .L7F09FEE0
   nop   
  sub.s $f6, $f0, $f22
  swc1  $f6, 0x20($v0)
.L7F09FEE0:
  beql  $v1, $a0, .L7F09FF70
   lw    $t1, ($s1)
  lw    $t7, ($s1)
.L7F09FEEC:
  addiu $v1, $v1, 2
  addu  $v0, $t7, $s0
  lwc1  $f8, 8($v0)
  lwc1  $f10, 0x20($v0)
  add.s $f18, $f8, $f10
  swc1  $f18, 8($v0)
  lw    $t8, ($s1)
  addu  $v0, $t8, $s0
  lwc1  $f0, 0x20($v0)
  c.lt.s $f20, $f0
  nop   
  bc1fl .L7F09FF38
   lwc1  $f4, 8($v0)
  sub.s $f16, $f0, $f22
  swc1  $f16, 0x20($v0)
  lw    $t9, ($s1)
  addu  $v0, $t9, $s0
  lwc1  $f0, 0x20($v0)
  lwc1  $f4, 8($v0)
.L7F09FF38:
  add.s $f6, $f4, $f0
  swc1  $f6, 8($v0)
  lw    $t0, ($s1)
  addu  $v0, $t0, $s0
  lwc1  $f0, 0x20($v0)
  c.lt.s $f20, $f0
  nop   
  bc1f  .L7F09FF64
   nop   
  sub.s $f8, $f0, $f22
  swc1  $f8, 0x20($v0)
.L7F09FF64:
  bnel  $v1, $a0, .L7F09FEEC
   lw    $t7, ($s1)
.L7F09FF6C:
  lw    $t1, ($s1)
.L7F09FF70:
  addu  $v0, $t1, $s0
  lw    $t2, ($v0)
  slti  $at, $t2, 0x65
  bnezl $at, .L7F09FFC4
   lwc1  $f0, 8($v0)
  jal   get_random_value
   nop   
  andi  $t3, $v0, 0x1f
  beql  $t3, $zero, .L7F09FFB0
   lw    $t6, ($s1)
  lw    $t4, ($s1)
  addu  $v0, $t4, $s0
  lw    $t5, ($v0)
  bnel  $s3, $t5, .L7F09FFC4
   lwc1  $f0, 8($v0)
  lw    $t6, ($s1)
.L7F09FFB0:
  addu  $t7, $t6, $s0
  sw    $zero, ($t7)
  lw    $t8, ($s1)
  addu  $v0, $t8, $s0
  lwc1  $f0, 8($v0)
.L7F09FFC4:
  c.lt.s $f0, $f26
  nop   
  bc1tl .L7F09FFE8
   sw    $zero, ($v0)
  c.lt.s $f28, $f0
  nop   
  bc1fl .L7F09FFEC
   lw    $t9, ($s4)
  sw    $zero, ($v0)
.L7F09FFE8:
  lw    $t9, ($s4)
.L7F09FFEC:
  addiu $s2, $s2, 1
  addiu $s0, $s0, 0x78
  slt   $at, $s2, $t9
  bnezl $at, .L7F09FDDC
   lw    $t7, ($s1)
.L7F0A0000:
  lw    $ra, 0x54($sp)
  ldc1  $f20, 0x18($sp)
  ldc1  $f22, 0x20($sp)
  ldc1  $f24, 0x28($sp)
  ldc1  $f26, 0x30($sp)
  ldc1  $f28, 0x38($sp)
  lw    $s0, 0x40($sp)
  lw    $s1, 0x44($sp)
  lw    $s2, 0x48($sp)
  lw    $s3, 0x4c($sp)
  lw    $s4, 0x50($sp)
  jr    $ra
   addiu $sp, $sp, 0x58
");

asm(R"
.late_rodata
glabel D_800576FC
.word 0xc69c4000 /*-20000.0*/
glabel D_80057700
.word 0x469c4000 /*20000.0*/
.text
glabel sub_GAME_7F0A0034
  addiu $sp, $sp, -0xc0
  sw    $s0, 0x28($sp)
  sw    $ra, 0x4c($sp)
  sw    $fp, 0x48($sp)
  sw    $s7, 0x44($sp)
  sw    $s6, 0x40($sp)
  sw    $s5, 0x3c($sp)
  sw    $s4, 0x38($sp)
  sw    $s3, 0x34($sp)
  sw    $s2, 0x30($sp)
  sw    $s1, 0x2c($sp)
  sdc1  $f22, 0x20($sp)
  sdc1  $f20, 0x18($sp)
  lui   $t6, 0xb600
  li    $t7, 12288
  sw    $t7, 4($a0)
  sw    $t6, ($a0)
  addiu $s0, $a0, 8
  lui   $t8, (0xBC000806 >> 16) # lui $t8, 0xbc00
  ori   $t8, (0xBC000806 & 0xFFFF) # ori $t8, $t8, 0x806
  move  $s1, $s0
  sw    $t8, ($s1)
  lui   $a0, %hi(pGlobalimagetable)
  lw    $a0, %lo(pGlobalimagetable)($a0)
  jal   osVirtualToPhysical
   addiu $s0, $s0, 8
  move  $v1, $s0
  sw    $v0, 4($s1)
  lui   $t0, 0x200
  addiu $t0, $t0, 0xa50
  addiu $s0, $s0, 8
  lui   $t9, 0x600
  sw    $t9, ($v1)
  sw    $t0, 4($v1)
  move  $a0, $s0
  lui   $t1, (0xB900031D >> 16) # lui $t1, 0xb900
  lui   $t2, (0x005049D8 >> 16) # lui $t2, 0x50
  ori   $t2, (0x005049D8 & 0xFFFF) # ori $t2, $t2, 0x49d8
  ori   $t1, (0xB900031D & 0xFFFF) # ori $t1, $t1, 0x31d
  sw    $t1, ($a0)
  sw    $t2, 4($a0)
  lui   $t3, %hi(max_casings) 
  lw    $t3, %lo(max_casings)($t3)
  addiu $s0, $s0, 8
  move  $s5, $zero
  blez  $t3, .L7F0A0240
   move  $s3, $zero
  lui   $at, %hi(D_800576FC)
  lwc1  $f22, %lo(D_800576FC)($at)
  lui   $at, %hi(D_80057700)
  lui   $fp, (0x04300040 >> 16) # lui $fp, 0x430
  lui   $s7, (0x01020040 >> 16) # lui $s7, 0x102
  lui   $s6, %hi(ptr_ejected_casing_buf)
  addiu $s6, %lo(ptr_ejected_casing_buf) # addiu $s6, $s6, -0x5eb4
  ori   $s7, (0x01020040 & 0xFFFF) # ori $s7, $s7, 0x40
  ori   $fp, (0x04300040 & 0xFFFF) # ori $fp, $fp, 0x40
  lwc1  $f20, %lo(D_80057700)($at)
  addiu $s4, $sp, 0x80
  lw    $t4, ($s6)
.L7F0A0120:
  addu  $v0, $t4, $s3
  lw    $t5, ($v0)
  addiu $a0, $v0, 4
  addiu $a1, $v0, 0x10
  blez  $t5, .L7F0A0224
   nop   
  jal   sub_GAME_7F05892C
   move  $a2, $s4
  jal   get_BONDdata_field_10CC
   nop   
  move  $a0, $v0
  jal   sub_GAME_7F058098
   move  $a1, $s4
  lwc1  $f0, 0xb0($sp)
  c.lt.s $f0, $f20
  nop   
  bc1f  .L7F0A0224
   nop   
  c.lt.s $f22, $f0
  lwc1  $f0, 0xb4($sp)
  bc1f  .L7F0A0224
   nop   
  c.lt.s $f0, $f20
  nop   
  bc1f  .L7F0A0224
   nop   
  c.lt.s $f22, $f0
  lwc1  $f0, 0xb8($sp)
  bc1f  .L7F0A0224
   nop   
  c.lt.s $f0, $f20
  nop   
  bc1f  .L7F0A0224
   nop   
  c.lt.s $f22, $f0
  nop   
  bc1f  .L7F0A0224
   nop   
  jal   sub_GAME_7F0BD6E0
   nop   
  move  $s2, $v0
  move  $a0, $s4
  jal   sub_GAME_7F058C9C
   move  $a1, $v0
  move  $s1, $s0
  sw    $s7, ($s1)
  addiu $s0, $s0, 8
  jal   osVirtualToPhysical
   move  $a0, $s2
  sw    $v0, 4($s1)
  move  $s2, $s0
  sw    $fp, ($s2)
  lw    $t6, ($s6)
  addiu $s0, $s0, 8
  addu  $a0, $t6, $s3
  jal   osVirtualToPhysical
   addiu $a0, $a0, 0x38
  move  $v1, $s0
  sw    $v0, 4($s2)
  lui   $t7, (0xB1000032 >> 16) # lui $t7, 0xb100
  ori   $t7, (0xB1000032 & 0xFFFF) # ori $t7, $t7, 0x32
  li    $t8, 8208
  sw    $t8, 4($v1)
  sw    $t7, ($v1)
  addiu $s0, $s0, 8
.L7F0A0224:
  lui   $t9, %hi(max_casings) 
  lw    $t9, %lo(max_casings)($t9)
  addiu $s5, $s5, 1
  addiu $s3, $s3, 0x78
  slt   $at, $s5, $t9
  bnezl $at, .L7F0A0120
   lw    $t4, ($s6)
.L7F0A0240:
  lw    $ra, 0x4c($sp)
  move  $v0, $s0
  lw    $s0, 0x28($sp)
  ldc1  $f20, 0x18($sp)
  ldc1  $f22, 0x20($sp)
  lw    $s1, 0x2c($sp)
  lw    $s2, 0x30($sp)
  lw    $s3, 0x34($sp)
  lw    $s4, 0x38($sp)
  lw    $s5, 0x3c($sp)
  lw    $s6, 0x40($sp)
  lw    $s7, 0x44($sp)
  lw    $fp, 0x48($sp)
  jr    $ra
   addiu $sp, $sp, 0xc0
");

asm(R"
.late_rodata
glabel D_80057704
.word 0x40c90fdb /*6.2831855*/
glabel D_80057708
.word 0x3e4ccccd /*0.2*/
glabel D_8005770C
.word 0x3f4ccccd /*0.80000001*/
.text
glabel sub_GAME_7F0A027C
  addiu $sp, $sp, -0x68
  lui   $t6, %hi(D_80040920) 
  sw    $ra, 0x34($sp)
  sw    $s4, 0x30($sp)
  sw    $s3, 0x2c($sp)
  sw    $s2, 0x28($sp)
  sw    $s1, 0x24($sp)
  sw    $s0, 0x20($sp)
  sdc1  $f20, 0x18($sp)
  sw    $a2, 0x70($sp)
  addiu $t6, %lo(D_80040920) # addiu $t6, $t6, 0x920
  lw    $at, ($t6)
  addiu $s3, $sp, 0x58
  mtc1  $a1, $f20
  sw    $at, ($s3)
  lw    $t9, 4($t6)
  move  $s4, $a0
  sw    $t9, 4($s3)
  lw    $at, 8($t6)
  sw    $at, 8($s3)
  lw    $t9, 0xc($t6)
  jal   get_random_value
   sw    $t9, 0xc($s3)
  mtc1  $v0, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F0A02F4
   cvt.s.w $f6, $f4
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F0A02F4:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f10
  lui   $at, %hi(D_80057704)
  lwc1  $f18, %lo(D_80057704)($at)
  mul.s $f16, $f6, $f10
  nop   
  mul.s $f4, $f16, $f18
  jal   get_random_value
   swc1  $f4, 0x54($sp)
  li    $at, 80
  divu  $zero, $v0, $at
  mfhi  $t0
  li    $t1, 255
  subu  $t2, $t1, $t0
  sb    $t2, 0x4b($sp)
  jal   sub_GAME_7F0BCA14
   lh    $a0, 0x72($sp)
  jal   getPlayerCount
   move  $s0, $v0
  slti  $at, $v0, 2
  beqz  $at, .L7F0A0A90
   li    $at, 0x43480000 # 200.000000
  mtc1  $at, $f0
  nop   
  c.lt.s $f0, $f20
  nop   
  bc1f  .L7F0A0368
   nop   
  mov.s $f20, $f0
.L7F0A0368:
  jal   get_random_value
   nop   
  mtc1  $v0, $f8
  bgez  $v0, .L7F0A038C
   cvt.s.w $f6, $f8
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f10
  nop   
  add.s $f6, $f6, $f10
.L7F0A038C:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f16
  lui   $at, %hi(D_80057708)
  lwc1  $f4, %lo(D_80057708)($at)
  mul.s $f18, $f6, $f16
  lui   $at, %hi(D_8005770C)
  lwc1  $f10, %lo(D_8005770C)($at)
  mul.s $f8, $f4, $f18
  add.s $f6, $f10, $f8
  mul.s $f20, $f20, $f6
  jal   get_room_data_float1
   nop   
  lwc1  $f16, ($s4)
  lwc1  $f18, ($s0)
  mul.s $f4, $f16, $f0
  sub.s $f10, $f4, $f18
  jal   get_room_data_float1
   swc1  $f10, ($s4)
  lwc1  $f8, 4($s4)
  lwc1  $f16, 4($s0)
  mul.s $f6, $f8, $f0
  sub.s $f4, $f6, $f16
  jal   get_room_data_float1
   swc1  $f4, 4($s4)
  lwc1  $f18, 8($s4)
  lwc1  $f8, 8($s0)
  mul.s $f10, $f18, $f0
  sub.s $f6, $f10, $f8
  jal   get_room_data_float1
   swc1  $f6, 8($s4)
  mul.s $f20, $f20, $f0
  jal   cosf
   lwc1  $f12, 0x54($sp)
  mul.s $f16, $f0, $f20
  lwc1  $f12, 0x54($sp)
  jal   sinf
   swc1  $f16, 0x50($sp)
  lui   $s2, %hi(D_8004017C+0x688)
  addiu $s2, %lo(D_8004017C+0x688) # addiu $s2, $s2, 0x804
  lw    $t5, ($s2)
  li    $s1, 88
  mul.s $f2, $f0, $f20
  lui   $s0, %hi(ptr_scorch_buf)
  multu $t5, $s1
  addiu $s0, %lo(ptr_scorch_buf) # addiu $s0, $s0, -0x5eb0
  lw    $t4, ($s0)
  lh    $t3, 0x72($sp)
  swc1  $f2, 0x4c($sp)
  mflo  $t8
  addu  $t7, $t4, $t8
  sh    $t3, ($t7)
  lw    $t9, ($s2)
  lw    $t6, ($s0)
  lwc1  $f4, ($s4)
  multu $t9, $s1
  mflo  $t1
  addu  $t0, $t6, $t1
  swc1  $f4, 4($t0)
  lw    $t5, ($s2)
  lw    $t2, ($s0)
  lwc1  $f18, 4($s4)
  multu $t5, $s1
  mflo  $t4
  addu  $t8, $t2, $t4
  swc1  $f18, 8($t8)
  lw    $t7, ($s2)
  lw    $t3, ($s0)
  lwc1  $f10, 8($s4)
  multu $t7, $s1
  mflo  $t9
  addu  $t6, $t3, $t9
  swc1  $f10, 0xc($t6)
  lw    $t0, ($s2)
  lw    $t1, ($s0)
  multu $t0, $s1
  mflo  $t5
  addu  $t2, $t1, $t5
  swc1  $f20, 0x10($t2)
  lw    $t8, ($s2)
  lw    $t4, ($s0)
  lw    $at, ($s3)
  multu $t8, $s1
  mflo  $t7
  addu  $t3, $t4, $t7
  sw    $at, 0x18($t3)
  lw    $t6, 4($s3)
  sw    $t6, 0x1c($t3)
  lw    $at, 8($s3)
  sw    $at, 0x20($t3)
  lw    $t6, 0xc($s3)
  sw    $t6, 0x24($t3)
  lw    $t1, ($s2)
  lw    $t0, ($s0)
  lw    $at, ($s3)
  multu $t1, $s1
  mflo  $t5
  addu  $t2, $t0, $t5
  sw    $at, 0x28($t2)
  lw    $t4, 4($s3)
  sw    $t4, 0x2c($t2)
  lw    $at, 8($s3)
  sw    $at, 0x30($t2)
  lw    $t4, 0xc($s3)
  sw    $t4, 0x34($t2)
  lw    $t9, ($s2)
  lw    $t7, ($s0)
  lw    $at, ($s3)
  multu $t9, $s1
  mflo  $t3
  addu  $t6, $t7, $t3
  sw    $at, 0x38($t6)
  lw    $t0, 4($s3)
  sw    $t0, 0x3c($t6)
  lw    $at, 8($s3)
  sw    $at, 0x40($t6)
  lw    $t0, 0xc($s3)
  sw    $t0, 0x44($t6)
  lw    $t8, ($s2)
  lw    $t5, ($s0)
  lw    $at, ($s3)
  multu $t8, $s1
  mflo  $t2
  addu  $t4, $t5, $t2
  sw    $at, 0x48($t4)
  lw    $t7, 4($s3)
  sw    $t7, 0x4c($t4)
  lw    $at, 8($s3)
  sw    $at, 0x50($t4)
  lw    $t7, 0xc($s3)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f10
  sw    $t7, 0x54($t4)
  lw    $t0, ($s2)
  lwc1  $f6, 0x50($sp)
  lwc1  $f8, ($s4)
  multu $t0, $s1
  lw    $t6, ($s0)
  add.s $f16, $f8, $f6
  trunc.w.s $f4, $f16
  mfc1  $t1, $f4
  mflo  $t8
  addu  $t5, $t6, $t8
  sh    $t1, 0x18($t5)
  lw    $t7, ($s2)
  lwc1  $f18, 4($s4)
  lw    $t4, ($s0)
  multu $t7, $s1
  add.s $f8, $f18, $f10
  lui   $t6, %hi(genericimage) 
  trunc.w.s $f6, $f8
  mfc1  $t9, $f6
  mflo  $t3
  addu  $t0, $t4, $t3
  sh    $t9, 0x1a($t0)
  lw    $t5, ($s2)
  lwc1  $f16, 8($s4)
  lw    $t1, ($s0)
  multu $t5, $s1
  add.s $f4, $f16, $f2
  trunc.w.s $f18, $f4
  mfc1  $t8, $f18
  mflo  $t2
  addu  $t7, $t1, $t2
  sh    $t8, 0x1c($t7)
  lw    $t3, ($s2)
  lw    $t4, ($s0)
  multu $t3, $s1
  mflo  $t9
  addu  $t0, $t4, $t9
  sh    $zero, 0x20($t0)
  lw    $t8, ($s2)
  lw    $t6, %lo(genericimage)($t6)
  lw    $t2, ($s0)
  multu $t8, $s1
  lbu   $t5, 4($t6)
  sll   $t1, $t5, 5
  mflo  $t7
  addu  $t3, $t2, $t7
  jal   get_random_value
   sh    $t1, 0x22($t3)
  li    $at, 50
  divu  $zero, $v0, $at
  mfhi  $s3
  lw    $t9, ($s2)
  lw    $t4, ($s0)
  lwc1  $f20, 0x4c($sp)
  multu $t9, $s1
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f4
  mflo  $t0
  addu  $t6, $t4, $t0
  sb    $s3, 0x26($t6)
  lw    $t8, ($s2)
  lw    $t5, ($s0)
  multu $t8, $s1
  mflo  $t2
  addu  $t7, $t5, $t2
  sb    $s3, 0x25($t7)
  lw    $t3, ($s2)
  lw    $t1, ($s0)
  multu $t3, $s1
  mflo  $t9
  addu  $t4, $t1, $t9
  sb    $s3, 0x24($t4)
  lw    $t8, ($s2)
  lw    $t6, ($s0)
  lbu   $t0, 0x4b($sp)
  multu $t8, $s1
  mflo  $t5
  addu  $t2, $t6, $t5
  sb    $t0, 0x27($t2)
  lw    $t9, ($s2)
  lwc1  $f10, ($s4)
  lw    $t1, ($s0)
  multu $t9, $s1
  add.s $f8, $f10, $f20
  trunc.w.s $f6, $f8
  mfc1  $t3, $f6
  mflo  $t4
  addu  $t8, $t1, $t4
  sh    $t3, 0x28($t8)
  lw    $t2, ($s2)
  lwc1  $f16, 4($s4)
  lw    $t0, ($s0)
  multu $t2, $s1
  add.s $f18, $f16, $f4
  trunc.w.s $f10, $f18
  mfc1  $t5, $f10
  mflo  $t7
  addu  $t9, $t0, $t7
  sh    $t5, 0x2a($t9)
  lw    $t8, ($s2)
  lwc1  $f6, 0x50($sp)
  lwc1  $f8, 8($s4)
  multu $t8, $s1
  lw    $t3, ($s0)
  sub.s $f16, $f8, $f6
  trunc.w.s $f4, $f16
  mfc1  $t4, $f4
  mflo  $t6
  addu  $t2, $t3, $t6
  sh    $t4, 0x2c($t2)
  lw    $t7, ($s2)
  lw    $t0, ($s0)
  multu $t7, $s1
  mflo  $t5
  addu  $t9, $t0, $t5
  sh    $zero, 0x30($t9)
  lw    $t8, ($s2)
  lw    $t1, ($s0)
  multu $t8, $s1
  mflo  $t3
  addu  $t6, $t1, $t3
  jal   get_random_value
   sh    $zero, 0x32($t6)
  li    $at, 50
  divu  $zero, $v0, $at
  mfhi  $s3
  lw    $t2, ($s2)
  lw    $t4, ($s0)
  li    $at, 0x3F000000 # 0.500000
  multu $t2, $s1
  mtc1  $at, $f4
  mflo  $t7
  addu  $t0, $t4, $t7
  sb    $s3, 0x36($t0)
  lw    $t9, ($s2)
  lw    $t5, ($s0)
  multu $t9, $s1
  mflo  $t8
  addu  $t1, $t5, $t8
  sb    $s3, 0x35($t1)
  lw    $t6, ($s2)
  lw    $t3, ($s0)
  multu $t6, $s1
  mflo  $t2
  addu  $t4, $t3, $t2
  sb    $s3, 0x34($t4)
  lw    $t9, ($s2)
  lw    $t0, ($s0)
  lbu   $t7, 0x4b($sp)
  multu $t9, $s1
  mflo  $t5
  addu  $t8, $t0, $t5
  sb    $t7, 0x37($t8)
  lw    $t2, ($s2)
  lwc1  $f10, 0x50($sp)
  lwc1  $f18, ($s4)
  multu $t2, $s1
  lw    $t3, ($s0)
  sub.s $f8, $f18, $f10
  trunc.w.s $f6, $f8
  mfc1  $t6, $f6
  mflo  $t4
  addu  $t9, $t3, $t4
  sh    $t6, 0x38($t9)
  lw    $t8, ($s2)
  lwc1  $f16, 4($s4)
  lw    $t7, ($s0)
  multu $t8, $s1
  add.s $f18, $f16, $f4
  trunc.w.s $f10, $f18
  mfc1  $t5, $f10
  mflo  $t1
  addu  $t2, $t7, $t1
  sh    $t5, 0x3a($t2)
  lw    $t9, ($s2)
  lwc1  $f8, 8($s4)
  lw    $t6, ($s0)
  multu $t9, $s1
  sub.s $f6, $f8, $f20
  lui   $t7, %hi(genericimage) 
  trunc.w.s $f16, $f6
  mfc1  $t4, $f16
  mflo  $t0
  addu  $t8, $t6, $t0
  sh    $t4, 0x3c($t8)
  lw    $t3, ($s2)
  lw    $t7, %lo(genericimage)($t7)
  lw    $t2, ($s0)
  multu $t3, $s1
  lbu   $t1, 5($t7)
  sll   $t5, $t1, 5
  mflo  $t9
  addu  $t6, $t2, $t9
  sh    $t5, 0x40($t6)
  lw    $t4, ($s2)
  lw    $t0, ($s0)
  multu $t4, $s1
  mflo  $t8
  addu  $t7, $t0, $t8
  jal   get_random_value
   sh    $zero, 0x42($t7)
  li    $at, 50
  divu  $zero, $v0, $at
  mfhi  $s3
  lw    $t3, ($s2)
  lw    $t1, ($s0)
  li    $at, 0x3F000000 # 0.500000
  multu $t3, $s1
  mtc1  $at, $f6
  mflo  $t2
  addu  $t9, $t1, $t2
  sb    $s3, 0x46($t9)
  lw    $t6, ($s2)
  lw    $t5, ($s0)
  multu $t6, $s1
  mflo  $t4
  addu  $t0, $t5, $t4
  sb    $s3, 0x45($t0)
  lw    $t7, ($s2)
  lw    $t8, ($s0)
  multu $t7, $s1
  mflo  $t3
  addu  $t1, $t8, $t3
  sb    $s3, 0x44($t1)
  lw    $t6, ($s2)
  lw    $t9, ($s0)
  lbu   $t2, 0x4b($sp)
  multu $t6, $s1
  mflo  $t5
  addu  $t4, $t9, $t5
  sb    $t2, 0x47($t4)
  lw    $t3, ($s2)
  lwc1  $f4, ($s4)
  lw    $t8, ($s0)
  multu $t3, $s1
  sub.s $f18, $f4, $f20
  trunc.w.s $f10, $f18
  mfc1  $t7, $f10
  mflo  $t1
  addu  $t6, $t8, $t1
  sh    $t7, 0x48($t6)
  lw    $t4, ($s2)
  lwc1  $f8, 4($s4)
  lw    $t2, ($s0)
  multu $t4, $s1
  add.s $f16, $f8, $f6
  trunc.w.s $f4, $f16
  mfc1  $t5, $f4
  mflo  $t0
  addu  $t3, $t2, $t0
  sh    $t5, 0x4a($t3)
  lw    $t6, ($s2)
  lwc1  $f10, 0x50($sp)
  lwc1  $f18, 8($s4)
  multu $t6, $s1
  lw    $t7, ($s0)
  add.s $f8, $f18, $f10
  lui   $t2, %hi(genericimage) 
  trunc.w.s $f6, $f8
  mfc1  $t1, $f6
  mflo  $t9
  addu  $t4, $t7, $t9
  sh    $t1, 0x4c($t4)
  lw    $t8, ($s2)
  lw    $t2, %lo(genericimage)($t2)
  lw    $t3, ($s0)
  multu $t8, $s1
  lbu   $t0, 4($t2)
  lui   $t9, %hi(genericimage) 
  sll   $t5, $t0, 5
  mflo  $t6
  addu  $t7, $t3, $t6
  sh    $t5, 0x50($t7)
  lw    $t0, ($s2)
  lw    $t9, %lo(genericimage)($t9)
  lw    $t2, ($s0)
  multu $t0, $s1
  lbu   $t1, 5($t9)
  sll   $t4, $t1, 5
  mflo  $t8
  addu  $t3, $t2, $t8
  jal   get_random_value
   sh    $t4, 0x52($t3)
  li    $at, 50
  divu  $zero, $v0, $at
  mfhi  $s3
  lw    $t5, ($s2)
  lw    $t6, ($s0)
  multu $t5, $s1
  mflo  $t7
  addu  $t9, $t6, $t7
  sb    $s3, 0x56($t9)
  lw    $t0, ($s2)
  lw    $t1, ($s0)
  multu $t0, $s1
  mflo  $t2
  addu  $t8, $t1, $t2
  sb    $s3, 0x55($t8)
  lw    $t3, ($s2)
  lw    $t4, ($s0)
  multu $t3, $s1
  mflo  $t5
  addu  $t6, $t4, $t5
  sb    $s3, 0x54($t6)
  lw    $t0, ($s2)
  lw    $t9, ($s0)
  lbu   $t7, 0x4b($sp)
  multu $t0, $s1
  mflo  $t1
  addu  $t2, $t9, $t1
  sb    $t7, 0x57($t2)
  lw    $t8, ($s2)
  addiu $t3, $t8, 1
  slti  $at, $t3, 0x14
  bnez  $at, .L7F0A0A90
   sw    $t3, ($s2)
  sw    $zero, ($s2)
.L7F0A0A90:
  lw    $ra, 0x34($sp)
  ldc1  $f20, 0x18($sp)
  lw    $s0, 0x20($sp)
  lw    $s1, 0x24($sp)
  lw    $s2, 0x28($sp)
  lw    $s3, 0x2c($sp)
  lw    $s4, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x68
");

asm(R"
glabel sub_GAME_7F0A0AB4
  addiu $sp, $sp, -0x40
  sw    $ra, 0x3c($sp)
  sw    $s3, 0x28($sp)
  sw    $s7, 0x38($sp)
  sw    $s6, 0x34($sp)
  sw    $s5, 0x30($sp)
  sw    $s4, 0x2c($sp)
  sw    $s2, 0x24($sp)
  sw    $s1, 0x20($sp)
  sw    $s0, 0x1c($sp)
  sw    $a0, 0x40($sp)
  jal   getPlayerCount
   li    $s3, -1
  slti  $at, $v0, 2
  bnez  $at, .L7F0A0AFC
   lw    $t6, 0x40($sp)
  b     .L7F0A0C48
   lw    $v0, 0x40($sp)
.L7F0A0AFC:
  addiu $t7, $t6, 8
  sw    $t7, 0x40($sp)
  lui   $t8, 0xb700
  li    $t9, 8192
  sw    $t9, 4($t6)
  sw    $t8, ($t6)
  lw    $t1, 0x40($sp)
  lui   $t4, (0x00011000 >> 16) # lui $t4, 1
  ori   $t4, (0x00011000 & 0xFFFF) # ori $t4, $t4, 0x1000
  addiu $t2, $t1, 8
  sw    $t2, 0x40($sp)
  lui   $t3, 0xb600
  sw    $t3, ($t1)
  sw    $t4, 4($t1)
  lw    $t5, 0x40($sp)
  lui   $t7, (0xBA000602 >> 16) # lui $t7, 0xba00
  ori   $t7, (0xBA000602 & 0xFFFF) # ori $t7, $t7, 0x602
  addiu $t6, $t5, 8
  sw    $t6, 0x40($sp)
  li    $t8, 128
  li    $t9, 2
  lui   $a1, %hi(genericimage)
  sw    $t8, 4($t5)
  sw    $t7, ($t5)
  sw    $t9, 0x10($sp)
  lw    $a1, %lo(genericimage)($a1)
  addiu $a0, $sp, 0x40
  li    $a2, 4
  jal   likely_generate_DL_for_image_declaration
   li    $a3, 1
  lui   $s5, (0xB1000032 >> 16) # lui $s5, 0xb100
  lui   $s4, (0x04300040 >> 16) # lui $s4, 0x430
  lui   $s2, %hi(ptr_scorch_buf)
  addiu $s2, %lo(ptr_scorch_buf) # addiu $s2, $s2, -0x5eb0
  ori   $s4, (0x04300040 & 0xFFFF) # ori $s4, $s4, 0x40
  ori   $s5, (0xB1000032 & 0xFFFF) # ori $s5, $s5, 0x32
  move  $s0, $zero
  li    $s7, 1760
  li    $s6, 8208
  lw    $t1, ($s2)
.L7F0A0B9C:
  addu  $t2, $t1, $s0
  lh    $a1, ($t2)
  bltzl $a1, .L7F0A0C1C
   addiu $s0, $s0, 0x58
  jal   sub_GAME_7F0B5E50
   move  $a0, $a1
  beql  $v0, $zero, .L7F0A0C1C
   addiu $s0, $s0, 0x58
  lw    $t3, ($s2)
  lw    $a0, 0x40($sp)
  addu  $t4, $t3, $s0
  lh    $a1, ($t4)
  beql  $s3, $a1, .L7F0A0BE4
   lw    $s1, 0x40($sp)
  jal   sub_GAME_7F0BC9C4
   move  $s3, $a1
  sw    $v0, 0x40($sp)
  lw    $s1, 0x40($sp)
.L7F0A0BE4:
  addiu $t6, $s1, 8
  sw    $t6, 0x40($sp)
  sw    $s4, ($s1)
  lw    $t7, ($s2)
  addu  $a0, $t7, $s0
  jal   osVirtualToPhysical
   addiu $a0, $a0, 0x18
  sw    $v0, 4($s1)
  lw    $t8, 0x40($sp)
  addiu $t9, $t8, 8
  sw    $t9, 0x40($sp)
  sw    $s6, 4($t8)
  sw    $s5, ($t8)
  addiu $s0, $s0, 0x58
.L7F0A0C1C:
  bnel  $s0, $s7, .L7F0A0B9C
   lw    $t1, ($s2)
  lw    $t1, 0x40($sp)
  lui   $t3, (0xBA000602 >> 16) # lui $t3, 0xba00
  ori   $t3, (0xBA000602 & 0xFFFF) # ori $t3, $t3, 0x602
  addiu $t2, $t1, 8
  sw    $t2, 0x40($sp)
  li    $t4, 64
  sw    $t4, 4($t1)
  sw    $t3, ($t1)
  lw    $v0, 0x40($sp)
.L7F0A0C48:
  lw    $ra, 0x3c($sp)
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  lw    $s2, 0x24($sp)
  lw    $s3, 0x28($sp)
  lw    $s4, 0x2c($sp)
  lw    $s5, 0x30($sp)
  lw    $s6, 0x34($sp)
  lw    $s7, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x40
");

asm(R"
glabel sub_GAME_7F0A0C74
  mtc1  $zero, $f4
  li    $at, 0x3F000000 # 0.500000
  c.le.s $f4, $f12
  nop   
  bc1fl .L7F0A0CB0
   mtc1  $at, $f16
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f6
  nop   
  add.s $f8, $f12, $f6
  trunc.w.s $f10, $f8
  mfc1  $v0, $f10
  jr    $ra
   nop   

  mtc1  $at, $f16
.L7F0A0CB0:
  nop   
  sub.s $f18, $f12, $f16
  trunc.w.s $f4, $f18
  mfc1  $v0, $f4
  nop   
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0A0CCC
  sw    $a1, 4($sp)
  sll   $t6, $a1, 0x18
  lui   $a2, %hi(ptr_bullet_impact_buf)
  sra   $a1, $t6, 0x18
  addiu $a2, %lo(ptr_bullet_impact_buf) # addiu $a2, $a2, -0x5eac
  move  $v1, $zero
  li    $t0, 8000
  li    $a3, -1
  lw    $t8, ($a2)
.L7F0A0CF0:
  addu  $v0, $t8, $v1
  lw    $t9, 0x48($v0)
  bnel  $a0, $t9, .L7F0A0D1C
   lw    $t3, 0x98($v0)
  lb    $t1, 0x4d($v0)
  bnel  $a1, $t1, .L7F0A0D1C
   lw    $t3, 0x98($v0)
  sh    $a3, ($v0)
  lw    $t2, ($a2)
  addu  $v0, $t2, $v1
  lw    $t3, 0x98($v0)
.L7F0A0D1C:
  bnel  $a0, $t3, .L7F0A0D40
   lw    $t6, 0xe8($v0)
  lb    $t4, 0x9d($v0)
  bnel  $a1, $t4, .L7F0A0D40
   lw    $t6, 0xe8($v0)
  sh    $a3, 0x50($v0)
  lw    $t5, ($a2)
  addu  $v0, $t5, $v1
  lw    $t6, 0xe8($v0)
.L7F0A0D40:
  bnel  $a0, $t6, .L7F0A0D64
   lw    $t9, 0x138($v0)
  lb    $t7, 0xed($v0)
  bnel  $a1, $t7, .L7F0A0D64
   lw    $t9, 0x138($v0)
  sh    $a3, 0xa0($v0)
  lw    $t8, ($a2)
  addu  $v0, $t8, $v1
  lw    $t9, 0x138($v0)
.L7F0A0D64:
  addiu $v1, $v1, 0x140
  bne   $a0, $t9, .L7F0A0D80
   nop   
  lb    $t1, 0x13d($v0)
  bne   $a1, $t1, .L7F0A0D80
   nop   
  sh    $a3, 0xf0($v0)
.L7F0A0D80:
  bnel  $v1, $t0, .L7F0A0CF0
   lw    $t8, ($a2)
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0A0D90
  lui   $a3, %hi(D_8004080C)
  lui   $a1, %hi(ptr_bullet_impact_buf)
  addiu $a1, %lo(ptr_bullet_impact_buf) # addiu $a1, $a1, -0x5eac
  addiu $a3, %lo(D_8004080C) # addiu $a3, $a3, 0x80c
  move  $v1, $zero
  li    $t2, 8000
  li    $t1, -1
  li    $t0, 12
  li    $a2, 2
  lw    $t6, ($a1)
.L7F0A0DB8:
  addu  $v0, $t6, $v1
  lw    $t7, 0x48($v0)
  bnel  $a0, $t7, .L7F0A0DF4
   lw    $t6, 0x98($v0)
  lh    $t8, 2($v0)
  multu $t8, $t0
  mflo  $t9
  addu  $t3, $a3, $t9
  lbu   $t4, 9($t3)
  bnel  $a2, $t4, .L7F0A0DF4
   lw    $t6, 0x98($v0)
  sh    $t1, ($v0)
  lw    $t5, ($a1)
  addu  $v0, $t5, $v1
  lw    $t6, 0x98($v0)
.L7F0A0DF4:
  bnel  $a0, $t6, .L7F0A0E28
   lw    $t5, 0xe8($v0)
  lh    $t7, 0x52($v0)
  multu $t7, $t0
  mflo  $t8
  addu  $t9, $a3, $t8
  lbu   $t3, 9($t9)
  bnel  $a2, $t3, .L7F0A0E28
   lw    $t5, 0xe8($v0)
  sh    $t1, 0x50($v0)
  lw    $t4, ($a1)
  addu  $v0, $t4, $v1
  lw    $t5, 0xe8($v0)
.L7F0A0E28:
  bnel  $a0, $t5, .L7F0A0E5C
   lw    $t4, 0x138($v0)
  lh    $t6, 0xa2($v0)
  multu $t6, $t0
  mflo  $t7
  addu  $t8, $a3, $t7
  lbu   $t9, 9($t8)
  bnel  $a2, $t9, .L7F0A0E5C
   lw    $t4, 0x138($v0)
  sh    $t1, 0xa0($v0)
  lw    $t3, ($a1)
  addu  $v0, $t3, $v1
  lw    $t4, 0x138($v0)
.L7F0A0E5C:
  addiu $v1, $v1, 0x140
  bne   $a0, $t4, .L7F0A0E88
   nop   
  lh    $t5, 0xf2($v0)
  multu $t5, $t0
  mflo  $t6
  addu  $t7, $a3, $t6
  lbu   $t8, 9($t7)
  bne   $a2, $t8, .L7F0A0E88
   nop   
  sh    $t1, 0xf0($v0)
.L7F0A0E88:
  bnel  $v1, $t2, .L7F0A0DB8
   lw    $t6, ($a1)
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0A0E98
  li    $at, 0x437F0000 # 255.000000
  mtc1  $at, $f2
  li    $at, 0x41200000 # 10.000000
  lui   $a2, %hi(ptr_bullet_impact_buf)
  mtc1  $at, $f0
  addiu $a2, %lo(ptr_bullet_impact_buf) # addiu $a2, $a2, -0x5eac
  move  $v0, $zero
  li    $t0, 10
  li    $a3, 80
  mtc1  $v0, $f4
.L7F0A0EC0:
  li    $v1, 1
  multu $a0, $a3
  cvt.s.w $f6, $f4
  li    $at, 0x4F000000 # 2147483648.000000
  div.s $f8, $f6, $f0
  mflo  $a1
  mul.s $f10, $f8, $f2
  cfc1  $t6, $31
  ctc1  $v1, $31
  nop   
  cvt.w.s $f16, $f10
  cfc1  $v1, $31
  nop   
  andi  $v1, $v1, 0x78
  beql  $v1, $zero, .L7F0A0F48
   mfc1  $v1, $f16
  mtc1  $at, $f16
  li    $v1, 1
  sub.s $f16, $f10, $f16
  ctc1  $v1, $31
  nop   
  cvt.w.s $f16, $f16
  cfc1  $v1, $31
  nop   
  andi  $v1, $v1, 0x78
  bnez  $v1, .L7F0A0F3C
   nop   
  mfc1  $v1, $f16
  lui   $at, 0x8000
  b     .L7F0A0F54
   or    $v1, $v1, $at
.L7F0A0F3C:
  b     .L7F0A0F54
   li    $v1, -1
  mfc1  $v1, $f16
.L7F0A0F48:
  nop   
  bltz  $v1, .L7F0A0F3C
   nop   
.L7F0A0F54:
  lw    $t7, ($a2)
  ctc1  $t6, $31
  addiu $t6, $v0, 1
  addu  $t8, $t7, $a1
  sb    $v1, 0x47($t8)
  lw    $t9, ($a2)
  mtc1  $t6, $f18
  addiu $a0, $a0, 1
  addu  $t1, $t9, $a1
  sb    $v1, 0x37($t1)
  lw    $t2, ($a2)
  cvt.s.w $f4, $f18
  slti  $at, $a0, 0x64
  addu  $t3, $t2, $a1
  sb    $v1, 0x27($t3)
  lw    $t4, ($a2)
  addiu $v0, $v0, 2
  div.s $f6, $f4, $f0
  addu  $t5, $t4, $a1
  sb    $v1, 0x17($t5)
  bnez  $at, .L7F0A0FB4
   addiu $a1, $a1, 0x50
  move  $a0, $zero
  move  $a1, $zero
.L7F0A0FB4:
  mul.s $f8, $f6, $f2
  li    $v1, 1
  li    $at, 0x4F000000 # 2147483648.000000
  cfc1  $t7, $31
  ctc1  $v1, $31
  nop   
  cvt.w.s $f10, $f8
  cfc1  $v1, $31
  nop   
  andi  $v1, $v1, 0x78
  beql  $v1, $zero, .L7F0A102C
   mfc1  $v1, $f10
  mtc1  $at, $f10
  li    $v1, 1
  sub.s $f10, $f8, $f10
  ctc1  $v1, $31
  nop   
  cvt.w.s $f10, $f10
  cfc1  $v1, $31
  nop   
  andi  $v1, $v1, 0x78
  bnez  $v1, .L7F0A1020
   nop   
  mfc1  $v1, $f10
  lui   $at, 0x8000
  b     .L7F0A1038
   or    $v1, $v1, $at
.L7F0A1020:
  b     .L7F0A1038
   li    $v1, -1
  mfc1  $v1, $f10
.L7F0A102C:
  nop   
  bltz  $v1, .L7F0A1020
   nop   
.L7F0A1038:
  lw    $t8, ($a2)
  addiu $a0, $a0, 1
  slti  $at, $a0, 0x64
  addu  $t9, $t8, $a1
  sb    $v1, 0x47($t9)
  lw    $t1, ($a2)
  ctc1  $t7, $31
  addu  $t2, $t1, $a1
  sb    $v1, 0x37($t2)
  lw    $t3, ($a2)
  addu  $t4, $t3, $a1
  sb    $v1, 0x27($t4)
  lw    $t5, ($a2)
  addu  $t6, $t5, $a1
  bnez  $at, .L7F0A107C
   sb    $v1, 0x17($t6)
  move  $a0, $zero
.L7F0A107C:
  bnel  $v0, $t0, .L7F0A0EC0
   mtc1  $v0, $f4
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0A108C
  addiu $sp, $sp, -0xf0
  lui   $t6, %hi(D_80040930) 
  sw    $ra, 0x34($sp)
  sw    $s6, 0x30($sp)
  sw    $s5, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a2, 0xf8($sp)
  sw    $a3, 0xfc($sp)
  addiu $t6, %lo(D_80040930) # addiu $t6, $t6, 0x930
  lw    $at, ($t6)
  addiu $s5, $sp, 0xe0
  move  $s1, $a0
  sw    $at, ($s5)
  lw    $t9, 4($t6)
  move  $s0, $a1
  li    $a0, 15
  sw    $t9, 4($s5)
  lw    $at, 8($t6)
  sw    $at, 8($s5)
  lw    $t9, 0xc($t6)
  jal   cheatCheckIfOn
   sw    $t9, 0xc($s5)
  beqz  $v0, .L7F0A1104
   lui   $t2, %hi(D_8004080C) 
  li    $t0, 16
  sh    $t0, 0xfa($sp)
.L7F0A1104:
  lwc1  $f4, ($s1)
  lh    $s4, 0xfa($sp)
  addiu $t2, %lo(D_8004080C) # addiu $t2, $t2, 0x80c
  swc1  $f4, 0xa0($sp)
  lwc1  $f6, 4($s1)
  sll   $t1, $s4, 2
  subu  $t1, $t1, $s4
  swc1  $f6, 0xa4($sp)
  lwc1  $f8, 8($s1)
  sll   $s4, $t1, 2
  addu  $t3, $s4, $t2
  sw    $t3, 0x50($sp)
  swc1  $f8, 0xa8($sp)
  lwc1  $f10, ($t3)
  mtc1  $zero, $f16
  swc1  $f10, 0x9c($sp)
  lwc1  $f4, 4($t3)
  swc1  $f4, 0x98($sp)
  lwc1  $f14, ($s0)
  c.eq.s $f16, $f14
  nop   
  bc1f  .L7F0A1194
   nop   
  lwc1  $f6, 8($s0)
  li    $at, 0x3F800000 # 1.000000
  c.eq.s $f16, $f6
  nop   
  bc1f  .L7F0A1194
   nop   
  mtc1  $at, $f0
  swc1  $f16, 0xb8($sp)
  swc1  $f16, 0xb4($sp)
  swc1  $f16, 0xbc($sp)
  swc1  $f0, 0xb0($sp)
  b     .L7F0A1224
   swc1  $f0, 0xc4($sp)
.L7F0A1194:
  mul.s $f8, $f14, $f14
  lwc1  $f2, 4($s0)
  lwc1  $f0, 8($s0)
  mul.s $f10, $f2, $f2
  add.s $f4, $f8, $f10
  mul.s $f6, $f0, $f0
  jal   sqrtf
   add.s $f12, $f6, $f4
  lwc1  $f8, ($s0)
  lwc1  $f6, 8($s0)
  lwc1  $f10, 4($s0)
  div.s $f14, $f8, $f0
  div.s $f16, $f6, $f0
  swc1  $f14, 0xdc($sp)
  mul.s $f4, $f14, $f14
  div.s $f18, $f10, $f0
  swc1  $f16, 0xd4($sp)
  mul.s $f8, $f16, $f16
  add.s $f12, $f4, $f8
  jal   sqrtf
   swc1  $f18, 0xd8($sp)
  lwc1  $f14, 0xdc($sp)
  lwc1  $f16, 0xd4($sp)
  lwc1  $f18, 0xd8($sp)
  div.s $f2, $f14, $f0
  neg.s $f4, $f0
  swc1  $f4, 0xb4($sp)
  div.s $f12, $f16, $f0
  mtc1  $zero, $f16
  mul.s $f6, $f18, $f2
  neg.s $f10, $f2
  swc1  $f10, 0xbc($sp)
  swc1  $f6, 0xb8($sp)
  mul.s $f8, $f18, $f12
  swc1  $f12, 0xc4($sp)
  swc1  $f8, 0xb0($sp)
.L7F0A1224:
  lw    $v0, 0x100($sp)
  beqz  $v0, .L7F0A133C
   nop   
  lw    $s0, 4($v0)
  lwc1  $f10, 0xc4($sp)
  lb    $t7, 0x107($sp)
  lw    $t5, 0x14($s0)
  lwc1  $f6, 0xbc($sp)
  lwc1  $f4, 0xb8($sp)
  lw    $t8, 0xc($t5)
  swc1  $f10, 0x78($sp)
  lwc1  $f8, 0xb4($sp)
  lwc1  $f10, 0xb0($sp)
  sll   $t6, $t7, 6
  addu  $s1, $t8, $t6
  swc1  $f16, 0x7c($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0x78
  swc1  $f6, 0x80($sp)
  swc1  $f4, 0x6c($sp)
  swc1  $f8, 0x70($sp)
  jal   sub_GAME_7F0583D8
   swc1  $f10, 0x74($sp)
  move  $a0, $s1
  jal   sub_GAME_7F0583D8
   addiu $a1, $sp, 0x6c
  lwc1  $f0, 0x78($sp)
  lwc1  $f2, 0x7c($sp)
  lwc1  $f14, 0x80($sp)
  mul.s $f6, $f0, $f0
  nop   
  mul.s $f4, $f2, $f2
  add.s $f8, $f6, $f4
  mul.s $f10, $f14, $f14
  jal   sqrtf
   add.s $f12, $f10, $f8
  lwc1  $f2, 0x6c($sp)
  lwc1  $f14, 0x70($sp)
  lwc1  $f16, 0x74($sp)
  mul.s $f6, $f2, $f2
  swc1  $f0, 0x88($sp)
  mul.s $f4, $f14, $f14
  add.s $f10, $f6, $f4
  mul.s $f8, $f16, $f16
  jal   sqrtf
   add.s $f12, $f8, $f10
  lwc1  $f6, 0x9c($sp)
  lwc1  $f4, 0x88($sp)
  lwc1  $f10, 0x98($sp)
  lw    $t9, 0x50($sp)
  div.s $f8, $f6, $f4
  div.s $f6, $f10, $f0
  swc1  $f8, 0x9c($sp)
  swc1  $f6, 0x98($sp)
  lbu   $t0, 0xa($t9)
  slti  $at, $t0, 2
  beql  $at, $zero, .L7F0A1330
   lbu   $t4, 2($s0)
  lbu   $t1, 9($t9)
  li    $at, 2
  bnel  $t1, $at, .L7F0A1330
   lbu   $t4, 2($s0)
  lbu   $t2, 2($s0)
  ori   $t3, $t2, 2
  b     .L7F0A13B0
   sb    $t3, 2($s0)
  lbu   $t4, 2($s0)
.L7F0A1330:
  ori   $t5, $t4, 1
  b     .L7F0A13B0
   sb    $t5, 2($s0)
.L7F0A133C:
  jal   sub_GAME_7F0BCA14
   lh    $a0, 0xfe($sp)
  jal   get_room_data_float1
   move  $s0, $v0
  lwc1  $f4, 0xa0($sp)
  lwc1  $f10, ($s0)
  mul.s $f8, $f4, $f0
  sub.s $f6, $f8, $f10
  jal   get_room_data_float1
   swc1  $f6, 0xa0($sp)
  lwc1  $f4, 0xa4($sp)
  lwc1  $f10, 4($s0)
  mul.s $f8, $f4, $f0
  sub.s $f6, $f8, $f10
  jal   get_room_data_float1
   swc1  $f6, 0xa4($sp)
  lwc1  $f4, 0xa8($sp)
  lwc1  $f10, 8($s0)
  mul.s $f8, $f4, $f0
  sub.s $f6, $f8, $f10
  jal   get_room_data_float1
   swc1  $f6, 0xa8($sp)
  lwc1  $f4, 0x9c($sp)
  mul.s $f8, $f4, $f0
  jal   get_room_data_float1
   swc1  $f8, 0x9c($sp)
  lwc1  $f10, 0x98($sp)
  mul.s $f6, $f10, $f0
  swc1  $f6, 0x98($sp)
.L7F0A13B0:
  lui   $s2, %hi(D_8004017C+0x68C)
  addiu $s2, %lo(D_8004017C+0x68C) # addiu $s2, $s2, 0x808
  lw    $t6, ($s2)
  li    $s6, 80
  lui   $s3, %hi(ptr_bullet_impact_buf)
  multu $t6, $s6
  addiu $s3, %lo(ptr_bullet_impact_buf) # addiu $s3, $s3, -0x5eac
  lw    $t8, ($s3)
  lw    $t7, 0x100($sp)
  mflo  $t0
  addu  $t9, $t8, $t0
  sw    $t7, 0x48($t9)
  lw    $t3, ($s2)
  lw    $t2, ($s3)
  lb    $t1, 0x107($sp)
  multu $t3, $s6
  mflo  $t4
  addu  $t5, $t2, $t4
  sb    $t1, 0x4c($t5)
  lw    $t0, ($s2)
  lw    $t8, ($s3)
  lb    $t6, 0x10b($sp)
  multu $t0, $s6
  mflo  $t7
  addu  $t9, $t8, $t7
  sb    $t6, 0x4d($t9)
  lw    $t4, ($s2)
  lw    $t2, ($s3)
  lh    $t3, 0xfe($sp)
  multu $t4, $s6
  mflo  $t1
  addu  $t5, $t2, $t1
  sh    $t3, ($t5)
  lw    $t7, ($s2)
  lw    $t8, ($s3)
  lh    $t0, 0xfa($sp)
  multu $t7, $s6
  mflo  $t6
  addu  $t9, $t8, $t6
  sh    $t0, 2($t9)
  lw    $t2, ($s2)
  lw    $t4, ($s3)
  lw    $at, ($s5)
  multu $t2, $s6
  mflo  $t1
  addu  $t3, $t4, $t1
  sw    $at, 8($t3)
  lw    $t7, 4($s5)
  sw    $t7, 0xc($t3)
  lw    $at, 8($s5)
  sw    $at, 0x10($t3)
  lw    $t7, 0xc($s5)
  sw    $t7, 0x14($t3)
  lw    $t6, ($s2)
  lw    $t8, ($s3)
  lw    $at, ($s5)
  multu $t6, $s6
  mflo  $t0
  addu  $t9, $t8, $t0
  sw    $at, 0x18($t9)
  lw    $t4, 4($s5)
  sw    $t4, 0x1c($t9)
  lw    $at, 8($s5)
  sw    $at, 0x20($t9)
  lw    $t4, 0xc($s5)
  sw    $t4, 0x24($t9)
  lw    $t5, ($s2)
  lw    $t1, ($s3)
  lw    $at, ($s5)
  multu $t5, $s6
  mflo  $t3
  addu  $t7, $t1, $t3
  sw    $at, 0x28($t7)
  lw    $t8, 4($s5)
  sw    $t8, 0x2c($t7)
  lw    $at, 8($s5)
  sw    $at, 0x30($t7)
  lw    $t8, 0xc($s5)
  sw    $t8, 0x34($t7)
  lw    $t2, ($s2)
  lw    $t0, ($s3)
  lw    $at, ($s5)
  multu $t2, $s6
  mflo  $t9
  addu  $t4, $t0, $t9
  sw    $at, 0x38($t4)
  lw    $t1, 4($s5)
  sw    $t1, 0x3c($t4)
  lw    $at, 8($s5)
  sw    $at, 0x40($t4)
  lw    $t1, 0xc($s5)
  sw    $t1, 0x44($t4)
  lwc1  $f8, 0xc4($sp)
  lwc1  $f4, 0x9c($sp)
  lwc1  $f6, 0xb8($sp)
  lwc1  $f10, 0x98($sp)
  mul.s $f0, $f4, $f8
  lwc1  $f4, 0xa0($sp)
  mul.s $f2, $f10, $f6
  swc1  $f0, 0x4c($sp)
  sub.s $f8, $f4, $f0
  swc1  $f2, 0x48($sp)
  jal   sub_GAME_7F0A0C74
   sub.s $f12, $f8, $f2
  lw    $t6, ($s2)
  lw    $t3, ($s3)
  mtc1  $zero, $f8
  multu $t6, $s6
  mflo  $t7
  addu  $t8, $t3, $t7
  sh    $v0, 8($t8)
  lwc1  $f6, 0xb4($sp)
  lwc1  $f10, 0x98($sp)
  lwc1  $f4, 0xa4($sp)
  mul.s $f0, $f10, $f6
  sub.s $f10, $f4, $f8
  sub.s $f12, $f10, $f0
  jal   sub_GAME_7F0A0C74
   swc1  $f0, 0x44($sp)
  lw    $t0, ($s2)
  lw    $t2, ($s3)
  multu $t0, $s6
  mflo  $t9
  addu  $t5, $t2, $t9
  sh    $v0, 0xa($t5)
  lwc1  $f4, 0xbc($sp)
  lwc1  $f6, 0x9c($sp)
  lwc1  $f10, 0xb0($sp)
  lwc1  $f8, 0x98($sp)
  mul.s $f0, $f6, $f4
  lwc1  $f6, 0xa8($sp)
  mul.s $f2, $f8, $f10
  swc1  $f0, 0x40($sp)
  sub.s $f4, $f6, $f0
  swc1  $f2, 0x3c($sp)
  jal   sub_GAME_7F0A0C74
   sub.s $f12, $f4, $f2
  lw    $t1, ($s2)
  lw    $t4, ($s3)
  lui   $s0, %hi(impactimages)
  multu $t1, $s6
  addiu $s0, %lo(impactimages) # addiu $s0, $s0, -0x2f44
  mflo  $t6
  addu  $t3, $t4, $t6
  sh    $v0, 0xc($t3)
  lw    $t8, ($s2)
  lw    $t7, ($s3)
  multu $t8, $s6
  mflo  $t0
  addu  $t2, $t7, $t0
  sh    $zero, 0x10($t2)
  lw    $t3, ($s2)
  lw    $t9, ($s0)
  lw    $t6, ($s3)
  multu $t3, $s6
  addu  $t5, $t9, $s4
  lbu   $t1, 5($t5)
  sll   $t4, $t1, 5
  mflo  $t8
  addu  $t7, $t6, $t8
  sh    $t4, 0x12($t7)
  lwc1  $f10, 0x4c($sp)
  lwc1  $f8, 0xa0($sp)
  lwc1  $f4, 0x48($sp)
  sub.s $f6, $f8, $f10
  jal   sub_GAME_7F0A0C74
   add.s $f12, $f6, $f4
  lw    $t2, ($s2)
  lw    $t0, ($s3)
  mtc1  $zero, $f10
  multu $t2, $s6
  mflo  $t9
  addu  $t5, $t0, $t9
  sh    $v0, 0x18($t5)
  lwc1  $f8, 0xa4($sp)
  lwc1  $f4, 0x44($sp)
  sub.s $f6, $f8, $f10
  jal   sub_GAME_7F0A0C74
   add.s $f12, $f6, $f4
  lw    $t3, ($s2)
  lw    $t1, ($s3)
  multu $t3, $s6
  mflo  $t6
  addu  $t8, $t1, $t6
  sh    $v0, 0x1a($t8)
  lwc1  $f10, 0x40($sp)
  lwc1  $f8, 0xa8($sp)
  lwc1  $f4, 0x3c($sp)
  sub.s $f6, $f8, $f10
  jal   sub_GAME_7F0A0C74
   add.s $f12, $f6, $f4
  lw    $t7, ($s2)
  lw    $t4, ($s3)
  multu $t7, $s6
  mflo  $t2
  addu  $t0, $t4, $t2
  sh    $v0, 0x1c($t0)
  lw    $t5, ($s2)
  lw    $t9, ($s3)
  multu $t5, $s6
  mflo  $t3
  addu  $t1, $t9, $t3
  sh    $zero, 0x20($t1)
  lw    $t8, ($s2)
  lw    $t6, ($s3)
  multu $t8, $s6
  mflo  $t7
  addu  $t4, $t6, $t7
  sh    $zero, 0x22($t4)
  lwc1  $f10, 0x4c($sp)
  lwc1  $f8, 0xa0($sp)
  lwc1  $f4, 0x48($sp)
  add.s $f6, $f8, $f10
  jal   sub_GAME_7F0A0C74
   add.s $f12, $f6, $f4
  lw    $t0, ($s2)
  lw    $t2, ($s3)
  mtc1  $zero, $f10
  multu $t0, $s6
  mflo  $t5
  addu  $t9, $t2, $t5
  sh    $v0, 0x28($t9)
  lwc1  $f8, 0xa4($sp)
  lwc1  $f4, 0x44($sp)
  add.s $f6, $f8, $f10
  jal   sub_GAME_7F0A0C74
   add.s $f12, $f6, $f4
  lw    $t1, ($s2)
  lw    $t3, ($s3)
  multu $t1, $s6
  mflo  $t8
  addu  $t6, $t3, $t8
  sh    $v0, 0x2a($t6)
  lwc1  $f10, 0x40($sp)
  lwc1  $f8, 0xa8($sp)
  lwc1  $f4, 0x3c($sp)
  add.s $f6, $f8, $f10
  jal   sub_GAME_7F0A0C74
   add.s $f12, $f6, $f4
  lw    $t4, ($s2)
  lw    $t7, ($s3)
  multu $t4, $s6
  mflo  $t0
  addu  $t2, $t7, $t0
  sh    $v0, 0x2c($t2)
  lw    $t6, ($s2)
  lw    $t5, ($s0)
  lw    $t8, ($s3)
  multu $t6, $s6
  addu  $t9, $t5, $s4
  lbu   $t1, 4($t9)
  sll   $t3, $t1, 5
  mflo  $t4
  addu  $t7, $t8, $t4
  sh    $t3, 0x30($t7)
  lw    $t2, ($s2)
  lw    $t0, ($s3)
  multu $t2, $s6
  mflo  $t5
  addu  $t9, $t0, $t5
  sh    $zero, 0x32($t9)
  lwc1  $f10, 0x4c($sp)
  lwc1  $f8, 0xa0($sp)
  lwc1  $f4, 0x48($sp)
  add.s $f6, $f8, $f10
  jal   sub_GAME_7F0A0C74
   sub.s $f12, $f6, $f4
  lw    $t6, ($s2)
  lw    $t1, ($s3)
  mtc1  $zero, $f10
  multu $t6, $s6
  mflo  $t8
  addu  $t4, $t1, $t8
  sh    $v0, 0x38($t4)
  lwc1  $f8, 0xa4($sp)
  lwc1  $f4, 0x44($sp)
  add.s $f6, $f8, $f10
  jal   sub_GAME_7F0A0C74
   sub.s $f12, $f6, $f4
  lw    $t7, ($s2)
  lw    $t3, ($s3)
  multu $t7, $s6
  mflo  $t2
  addu  $t0, $t3, $t2
  sh    $v0, 0x3a($t0)
  lwc1  $f10, 0x40($sp)
  lwc1  $f8, 0xa8($sp)
  lwc1  $f4, 0x3c($sp)
  add.s $f6, $f8, $f10
  jal   sub_GAME_7F0A0C74
   sub.s $f12, $f6, $f4
  lw    $t9, ($s2)
  lw    $t5, ($s3)
  move  $s1, $zero
  multu $t9, $s6
  li    $s5, 40
  mflo  $t6
  addu  $t1, $t5, $t6
  sh    $v0, 0x3c($t1)
  lw    $t0, ($s2)
  lw    $t8, ($s0)
  lw    $t2, ($s3)
  multu $t0, $s6
  addu  $t4, $t8, $s4
  lbu   $t7, 4($t4)
  sll   $t3, $t7, 5
  mflo  $t9
  addu  $t5, $t2, $t9
  sh    $t3, 0x40($t5)
  lw    $t0, ($s2)
  lw    $t6, ($s0)
  lw    $t7, ($s3)
  multu $t0, $s6
  addu  $t1, $t6, $s4
  lbu   $t8, 5($t1)
  li    $s4, 255
  sll   $t4, $t8, 5
  mflo  $t2
  addu  $t9, $t7, $t2
  sh    $t4, 0x42($t9)
  lbu   $a0, 0x61($sp)
  lbu   $a1, 0x62($sp)
.L7F0A18B8:
  lw    $t3, 0x50($sp)
  li    $at, 1
  lbu   $v0, 8($t3)
  beqz  $v0, .L7F0A1914
   nop   
  beq   $v0, $at, .L7F0A18E4
   li    $at, 2
  beq   $v0, $at, .L7F0A1940
   nop   
  b     .L7F0A1998
   move  $s0, $zero
.L7F0A18E4:
  jal   get_random_value
   nop   
  divu  $zero, $v0, $s5
  mfhi  $t5
  subu  $v1, $s4, $t5
  bnez  $s5, .L7F0A1904
   nop   
  break 7
.L7F0A1904:
  andi  $a0, $v1, 0xff
  andi  $a1, $v1, 0xff
  b     .L7F0A1998
   andi  $s0, $v1, 0xff
.L7F0A1914:
  jal   get_random_value
   nop   
  divu  $zero, $v0, $s5
  mfhi  $v1
  andi  $a0, $v1, 0xff
  bnez  $s5, .L7F0A1934
   nop   
  break 7
.L7F0A1934:
  andi  $a1, $v1, 0xff
  b     .L7F0A1998
   andi  $s0, $v1, 0xff
.L7F0A1940:
  jal   get_random_value
   nop   
  andi  $t6, $v0, 1
  beqz  $t6, .L7F0A195C
   move  $s0, $zero
  b     .L7F0A195C
   andi  $s0, $s4, 0xff
.L7F0A195C:
  jal   get_random_value
   nop   
  andi  $t1, $v0, 1
  beqz  $t1, .L7F0A1978
   move  $a1, $zero
  b     .L7F0A1978
   andi  $a1, $s4, 0xff
.L7F0A1978:
  jal   get_random_value
   sb    $a1, 0x62($sp)
  andi  $t8, $v0, 1
  beqz  $t8, .L7F0A1994
   lbu   $a1, 0x62($sp)
  b     .L7F0A1998
   andi  $a0, $s4, 0xff
.L7F0A1994:
  move  $a0, $zero
.L7F0A1998:
  lw    $t7, ($s2)
  lw    $t0, ($s3)
  li    $at, 64
  sll   $t2, $t7, 2
  addu  $t2, $t2, $t7
  sll   $t2, $t2, 4
  addu  $t4, $t0, $t2
  addu  $t9, $t4, $s1
  sb    $s0, 0x14($t9)
  lw    $t5, ($s2)
  lw    $t3, ($s3)
  sll   $t6, $t5, 2
  addu  $t6, $t6, $t5
  sll   $t6, $t6, 4
  addu  $t1, $t3, $t6
  addu  $t8, $t1, $s1
  sb    $a1, 0x15($t8)
  lw    $t0, ($s2)
  lw    $t7, ($s3)
  sll   $t2, $t0, 2
  addu  $t2, $t2, $t0
  sll   $t2, $t2, 4
  addu  $t4, $t7, $t2
  addu  $t9, $t4, $s1
  sb    $a0, 0x16($t9)
  lw    $t3, ($s2)
  lw    $t5, ($s3)
  sll   $t6, $t3, 2
  addu  $t6, $t6, $t3
  sll   $t6, $t6, 4
  addu  $t1, $t5, $t6
  addu  $t8, $t1, $s1
  addiu $s1, $s1, 0x10
  bne   $s1, $at, .L7F0A18B8
   sb    $s4, 0x17($t8)
  lw    $t0, ($s2)
  sb    $a0, 0x61($sp)
  sb    $a1, 0x62($sp)
  addiu $a0, $t0, 1
  slti  $at, $a0, 0x64
  bnez  $at, .L7F0A1A48
   sw    $a0, ($s2)
  sw    $zero, ($s2)
  move  $a0, $zero
.L7F0A1A48:
  jal   sub_GAME_7F0A0E98
   nop   
  lw    $t9, ($s2)
  lw    $t4, ($s3)
  li    $t2, -1
  multu $t9, $s6
  mflo  $t3
  addu  $t5, $t4, $t3
  sh    $t2, ($t5)
  lw    $ra, 0x34($sp)
  lw    $s6, 0x30($sp)
  lw    $s5, 0x2c($sp)
  lw    $s4, 0x28($sp)
  lw    $s3, 0x24($sp)
  lw    $s2, 0x20($sp)
  lw    $s1, 0x1c($sp)
  lw    $s0, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0xf0
");

asm(R"
glabel sub_GAME_7F0A1A94
  addiu $sp, $sp, -0x60
  sw    $s6, 0x38($sp)
  sw    $s5, 0x34($sp)
  li    $t6, -1
  move  $s6, $a1
  sw    $ra, 0x44($sp)
  sw    $fp, 0x40($sp)
  sw    $s7, 0x3c($sp)
  sw    $s4, 0x30($sp)
  sw    $s3, 0x2c($sp)
  sw    $s2, 0x28($sp)
  sw    $s1, 0x24($sp)
  sw    $s0, 0x20($sp)
  sw    $a0, 0x60($sp)
  sw    $a2, 0x68($sp)
  li    $s5, -1
  sw    $zero, 0x50($sp)
  sw    $zero, 0x4c($sp)
  beqz  $a1, .L7F0A1AEC
   sw    $t6, 0x48($sp)
  lw    $t7, 4($a1)
  sw    $t7, 0x4c($sp)
.L7F0A1AEC:
  lw    $t8, 0x60($sp)
  lui   $t0, 0xb600
  li    $t1, 12288
  addiu $t9, $t8, 8
  sw    $t9, 0x60($sp)
  sw    $t1, 4($t8)
  sw    $t0, ($t8)
  lw    $t2, 0x60($sp)
  lui   $t4, (0xBA000602 >> 16) # lui $t4, 0xba00
  ori   $t4, (0xBA000602 & 0xFFFF) # ori $t4, $t4, 0x602
  addiu $t3, $t2, 8
  sw    $t3, 0x60($sp)
  li    $t5, 128
  lui   $fp, %hi(D_8004080C) 
  lui   $s7, %hi(ptr_bullet_impact_buf) 
  addiu $s7, %lo(ptr_bullet_impact_buf) # addiu $s7, $s7, -0x5eac
  addiu $fp, %lo(D_8004080C) # addiu $fp, $fp, 0x80c
  move  $s4, $zero
  sw    $t5, 4($t2)
  sw    $t4, ($t2)
  lw    $t6, ($s7)
.L7F0A1B40:
  addu  $v1, $t6, $s4
  lw    $t7, 0x48($v1)
  bnel  $s6, $t7, .L7F0A1CEC
   addiu $s4, $s4, 0x50
  lh    $a1, ($v1)
  bltzl $a1, .L7F0A1CEC
   addiu $s4, $s4, 0x50
  bnezl $s6, .L7F0A1B80
   lw    $t9, 0x68($sp)
  jal   sub_GAME_7F0B5E50
   move  $a0, $a1
  beql  $v0, $zero, .L7F0A1CEC
   addiu $s4, $s4, 0x50
  lw    $t8, ($s7)
  addu  $v1, $t8, $s4
  lw    $t9, 0x68($sp)
.L7F0A1B80:
  lh    $s3, 2($v1)
  li    $t4, 1
  beqz  $t9, .L7F0A1BC0
   sll   $s2, $s3, 2
  sll   $s2, $s3, 2
  subu  $s2, $s2, $s3
  sll   $s2, $s2, 2
  addu  $s0, $fp, $s2
  lbu   $v0, 0xa($s0)
  slti  $t0, $v0, 2
  beqz  $t0, .L7F0A1BEC
   move  $v0, $t0
  lbu   $v0, 9($s0)
  xori  $t1, $v0, 2
  b     .L7F0A1BEC
   sltiu $v0, $t1, 1
.L7F0A1BC0:
  subu  $s2, $s2, $s3
  sll   $s2, $s2, 2
  addu  $s0, $fp, $s2
  lbu   $v0, 0xa($s0)
  slti  $t2, $v0, 2
  xori  $v0, $t2, 1
  bnez  $v0, .L7F0A1BEC
   nop   
  lbu   $v0, 9($s0)
  xori  $t3, $v0, 2
  sltu  $v0, $zero, $t3
.L7F0A1BEC:
  beql  $v0, $zero, .L7F0A1CEC
   addiu $s4, $s4, 0x50
  beqz  $s6, .L7F0A1C48
   sw    $t4, 0x50($sp)
  lb    $v0, 0x4c($v1)
  lw    $t6, 0x4c($sp)
  lw    $s1, 0x60($sp)
  beq   $s5, $v0, .L7F0A1C6C
   sll   $t5, $v0, 6
  lw    $t7, 0x14($t6)
  sll   $s5, $v0, 0x10
  addiu $t1, $s1, 8
  lw    $t8, 0xc($t7)
  lui   $t2, (0x01020040 >> 16) # lui $t2, 0x102
  sra   $t9, $s5, 0x10
  ori   $t2, (0x01020040 & 0xFFFF) # ori $t2, $t2, 0x40
  sw    $t1, 0x60($sp)
  move  $s5, $t9
  sw    $t2, ($s1)
  jal   osVirtualToPhysical
   addu  $a0, $t5, $t8
  b     .L7F0A1C6C
   sw    $v0, 4($s1)
.L7F0A1C48:
  lh    $a1, ($v1)
  lw    $a0, 0x60($sp)
  beql  $s5, $a1, .L7F0A1C70
   lw    $t4, 0x48($sp)
  sll   $s5, $a1, 0x10
  sra   $t3, $s5, 0x10
  jal   sub_GAME_7F0BC9C4
   move  $s5, $t3
  sw    $v0, 0x60($sp)
.L7F0A1C6C:
  lw    $t4, 0x48($sp)
.L7F0A1C70:
  addiu $a0, $sp, 0x60
  lui   $t6, %hi(impactimages) 
  beq   $t4, $s3, .L7F0A1C9C
   li    $t7, 2
  lw    $t6, %lo(impactimages)($t6)
  lbu   $a2, 9($s0)
  lbu   $a3, 0xa($s0)
  sw    $t7, 0x10($sp)
  jal   likely_generate_DL_for_image_declaration
   addu  $a1, $s2, $t6
  sw    $s3, 0x48($sp)
.L7F0A1C9C:
  lw    $s0, 0x60($sp)
  lui   $t9, (0x04300040 >> 16) # lui $t9, 0x430
  ori   $t9, (0x04300040 & 0xFFFF) # ori $t9, $t9, 0x40
  addiu $t8, $s0, 8
  sw    $t8, 0x60($sp)
  sw    $t9, ($s0)
  lw    $t0, ($s7)
  addu  $a0, $t0, $s4
  jal   osVirtualToPhysical
   addiu $a0, $a0, 8
  sw    $v0, 4($s0)
  lw    $t1, 0x60($sp)
  lui   $t3, (0xB1000032 >> 16) # lui $t3, 0xb100
  ori   $t3, (0xB1000032 & 0xFFFF) # ori $t3, $t3, 0x32
  addiu $t2, $t1, 8
  sw    $t2, 0x60($sp)
  li    $t4, 8208
  sw    $t4, 4($t1)
  sw    $t3, ($t1)
  addiu $s4, $s4, 0x50
.L7F0A1CEC:
  li    $at, 8000
  bnel  $s4, $at, .L7F0A1B40
   lw    $t6, ($s7)
  beqz  $s6, .L7F0A1D24
   lw    $t6, 0x50($sp)
  bnez  $t6, .L7F0A1D24
   lw    $t7, 0x4c($sp)
  lw    $t8, 0x68($sp)
  lbu   $t5, 2($t7)
  li    $t9, 1
  sllv  $t0, $t9, $t8
  not   $t1, $t0
  and   $t2, $t5, $t1
  sb    $t2, 2($t7)
.L7F0A1D24:
  lw    $t3, 0x60($sp)
  lui   $t6, (0xBA000602 >> 16) # lui $t6, 0xba00
  ori   $t6, (0xBA000602 & 0xFFFF) # ori $t6, $t6, 0x602
  addiu $t4, $t3, 8
  sw    $t4, 0x60($sp)
  li    $t9, 64
  sw    $t9, 4($t3)
  sw    $t6, ($t3)
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
  lw    $v0, 0x60($sp)
  jr    $ra
   addiu $sp, $sp, 0x60
");

void sub_GAME_7F0A1D78(unsigned int *param_1) {
  sub_GAME_7F0A1A94(param_1, 0, 0);
}
