#include "bond.h"
#include "players.h"

extern int camera_8003642C;
extern int D_80036444;
extern int in_tank_flag;
extern int cameramode;
extern int invisible_to_guards_flag;
extern int obj_collision_flag;
extern float D_800364CC;

void nullsub_75(void) {}

void set_BONDdata_screensize(float width, float height) {
  pPlayer->c_screenwidth = width;
  pPlayer->c_screenheight = height;
  pPlayer->c_halfwidth = width * 0.5f;
  pPlayer->c_halfheight = height * 0.5f;
}

void *set_ulx_uly(float ulx, float uly) {
  pPlayer->c_screenleft = ulx;
  pPlayer->c_screentop = uly;
}

void sub_GAME_7F077C30(float arg0, float arg1, float arg2) {
  pPlayer->c_perspnear = arg0;
  pPlayer->c_perspfovy = arg1;
  pPlayer->c_perspaspect = arg2;
}

asm(R"
.late_rodata
glabel D_80054FA0
.word 0x40490fdb /*3.1415927*/
glabel D_80054FA4
.word 0x3f060a92 /*0.52359879*/
glabel D_80054FA8
.word 0x3f060a92 /*0.52359879*/

.text
glabel sub_GAME_7F077C5C
  addiu $sp, $sp, -0x40
  sw    $s0, 0x20($sp)
  lui   $s0, %hi(pPlayer)
  addiu $s0, %lo(pPlayer) # addiu $s0, $s0, -0x5f50
  lw    $t6, ($s0)
  sdc1  $f20, 0x18($sp)
  sw    $ra, 0x24($sp)
  lui   $at, %hi(D_80054FA0)
  lwc1  $f20, %lo(D_80054FA0)($at)
  lwc1  $f4, 0x10a4($t6)
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f8
  mul.s $f6, $f4, $f20
  jal   sinf
   div.s $f12, $f6, $f8
  lw    $t7, ($s0)
  swc1  $f0, 0x2c($sp)
  li    $at, 0x43B40000 # 360.000000
  lwc1  $f10, 0x10a4($t7)
  mtc1  $at, $f4
  mul.s $f18, $f10, $f20
  jal   cosf
   div.s $f12, $f18, $f4
  lw    $v0, ($s0)
  lwc1  $f6, 0x2c($sp)
  li    $at, 0x3F800000 # 1.000000
  lwc1  $f8, 0x10b0($v0)
  mtc1  $at, $f20
  lui   $at, %hi(D_80054FA4)
  mul.s $f10, $f0, $f8
  div.s $f18, $f6, $f10
  swc1  $f18, 0x10b8($v0)
  lw    $v0, ($s0)
  lwc1  $f4, 0x10b8($v0)
  lwc1  $f8, 0x10a8($v0)
  lwc1  $f10, 0x10b0($v0)
  mul.s $f6, $f4, $f8
  lwc1  $f4, 0x10ac($v0)
  mul.s $f18, $f6, $f10
  div.s $f8, $f18, $f4
  swc1  $f8, 0x10b4($v0)
  lw    $v0, ($s0)
  lwc1  $f6, 0x10b4($v0)
  div.s $f10, $f20, $f6
  swc1  $f10, 0x10bc($v0)
  lw    $v0, ($s0)
  lwc1  $f18, 0x10b8($v0)
  div.s $f4, $f20, $f18
  swc1  $f4, 0x10c0($v0)
  lw    $v0, ($s0)
  lwc1  $f8, 0x10b8($v0)
  swc1  $f8, 0x10f4($v0)
  jal   sinf
   lwc1  $f12, %lo(D_80054FA4)($at)
  lui   $at, %hi(D_80054FA8)
  lwc1  $f12, %lo(D_80054FA8)($at)
  jal   cosf
   swc1  $f0, 0x2c($sp)
  li    $at, 0x42F00000 # 120.000000
  mtc1  $at, $f10
  lwc1  $f6, 0x2c($sp)
  lw    $t8, ($s0)
  mul.s $f18, $f0, $f10
  li    $at, 0x47800000 # 65536.000000
  li    $t9, -1
  li    $t1, 1
  div.s $f4, $f6, $f18
  swc1  $f4, 0x10f0($t8)
  lw    $v0, ($s0)
  mtc1  $at, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  lwc1  $f8, 0x10f4($v0)
  lwc1  $f10, 0x10f0($v0)
  div.s $f6, $f8, $f10
  mtc1  $at, $f8
  swc1  $f6, 0x10f8($v0)
  lw    $v0, ($s0)
  lwc1  $f18, 0x10f8($v0)
  mul.s $f2, $f18, $f4
  c.lt.s $f8, $f2
  nop   
  bc1fl .L7F077DB4
   cfc1  $t0, $31
  b     .L7F077E34
   sw    $t9, 0x10fc($v0)
  cfc1  $t0, $31
.L7F077DB4:
  ctc1  $t1, $31
  li    $at, 0x4F000000 # 2147483648.000000
  cvt.w.s $f10, $f2
  cfc1  $t1, $31
  nop   
  andi  $t1, $t1, 0x78
  beql  $t1, $zero, .L7F077E1C
   mfc1  $t1, $f10
  mtc1  $at, $f10
  li    $t1, 1
  sub.s $f10, $f2, $f10
  ctc1  $t1, $31
  nop   
  cvt.w.s $f10, $f10
  cfc1  $t1, $31
  nop   
  andi  $t1, $t1, 0x78
  bnez  $t1, .L7F077E10
   nop   
  mfc1  $t1, $f10
  lui   $at, 0x8000
  b     .L7F077E28
   or    $t1, $t1, $at
.L7F077E10:
  b     .L7F077E28
   li    $t1, -1
  mfc1  $t1, $f10
.L7F077E1C:
  nop   
  bltz  $t1, .L7F077E10
   nop   
.L7F077E28:
  ctc1  $t0, $31
  sw    $t1, 0x10fc($v0)
  nop   
.L7F077E34:
  lw    $v0, ($s0)
  lwc1  $f6, 0x10b0($v0)
  lwc1  $f18, 0x10b8($v0)
  mul.s $f14, $f6, $f18
  nop   
  mul.s $f4, $f14, $f14
  swc1  $f14, 0x30($sp)
  jal   sqrtf
   add.s $f12, $f4, $f20
  div.s $f2, $f20, $f0
  mtc1  $zero, $f8
  lw    $t2, ($s0)
  lwc1  $f14, 0x30($sp)
  swc1  $f8, 0x1100($t2)
  lw    $t3, ($s0)
  mul.s $f10, $f14, $f2
  swc1  $f2, 0x1104($t3)
  lw    $t4, ($s0)
  swc1  $f10, 0x1108($t4)
  lw    $v0, ($s0)
  lwc1  $f6, 0x10ac($v0)
  lwc1  $f4, 0x10b4($v0)
  neg.s $f18, $f6
  mul.s $f16, $f18, $f4
  nop   
  mul.s $f8, $f16, $f16
  swc1  $f16, 0x34($sp)
  jal   sqrtf
   add.s $f12, $f8, $f20
  div.s $f2, $f20, $f0
  lwc1  $f16, 0x34($sp)
  lw    $t5, ($s0)
  mtc1  $zero, $f6
  neg.s $f18, $f16
  neg.s $f10, $f2
  mul.s $f4, $f18, $f2
  swc1  $f10, 0x110c($t5)
  lw    $t6, ($s0)
  swc1  $f6, 0x1110($t6)
  lw    $t7, ($s0)
  swc1  $f4, 0x1114($t7)
  lw    $ra, 0x24($sp)
  lw    $s0, 0x20($sp)
  ldc1  $f20, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x40
");

asm(R"
glabel sub_GAME_7F077EEC
  addiu $sp, $sp, -0x28
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  sw    $ra, 0x14($sp)
  sw    $a2, 0x30($sp)
  lwc1  $f4, 4($a0)
  lwc1  $f6, 0x109c($v0)
  lwc1  $f10, 0x10b0($v0)
  li    $at, 0xBF800000 # -1.000000
  sub.s $f8, $f4, $f6
  lwc1  $f6, ($a0)
  lwc1  $f4, 0x10b8($v0)
  mtc1  $at, $f0
  sub.s $f18, $f10, $f8
  lwc1  $f10, 0x1098($v0)
  mul.s $f14, $f18, $f4
  sub.s $f8, $f6, $f10
  lwc1  $f18, 0x10ac($v0)
  lwc1  $f6, 0x10b4($v0)
  sw    $a1, 0x2c($sp)
  sub.s $f4, $f8, $f18
  swc1  $f14, 0x1c($sp)
  mul.s $f16, $f4, $f6
  nop   
  mul.s $f10, $f16, $f16
  swc1  $f16, 0x20($sp)
  mul.s $f8, $f14, $f14
  add.s $f18, $f10, $f8
  mul.s $f4, $f0, $f0
  jal   sqrtf
   add.s $f12, $f18, $f4
  lwc1  $f6, 0x30($sp)
  lwc1  $f16, 0x20($sp)
  lwc1  $f14, 0x1c($sp)
  div.s $f2, $f6, $f0
  li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f18
  lw    $a1, 0x2c($sp)
  mul.s $f10, $f16, $f2
  nop   
  mul.s $f8, $f14, $f2
  nop   
  mul.s $f4, $f18, $f2
  swc1  $f10, ($a1)
  swc1  $f8, 4($a1)
  swc1  $f4, 8($a1)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F077FB4
  mtc1  $a1, $f12
  lwc1  $f4, 4($a0)
  lui   $v0, %hi(pPlayer)
  addiu $v0, %lo(pPlayer) # addiu $v0, $v0, -0x5f50
  mul.s $f6, $f4, $f12
  lw    $t6, ($v0)
  lwc1  $f8, 0x10b8($t6)
  mul.s $f10, $f6, $f8
  swc1  $f10, 4($a2)
  lwc1  $f16, ($a0)
  lw    $t7, ($v0)
  mul.s $f18, $f16, $f12
  lwc1  $f4, 0x10b4($t7)
  mul.s $f6, $f18, $f4
  jr    $ra
   swc1  $f6, ($a2)
");

asm(R"
glabel sub_GAME_7F077FF4
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  lwc1  $f6, 8($a0)
  lwc1  $f8, 4($a0)
  lui   $v1, %hi(pPlayer)
  div.s $f0, $f4, $f6
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $v0, ($v1)
  lwc1  $f16, 0x10c0($v0)
  lwc1  $f4, 0x109c($v0)
  lwc1  $f6, 0x10b0($v0)
  mul.s $f10, $f8, $f0
  add.s $f8, $f4, $f6
  mul.s $f18, $f10, $f16
  add.s $f10, $f18, $f8
  swc1  $f10, 4($a1)
  lwc1  $f18, ($a0)
  lw    $v0, ($v1)
  mul.s $f8, $f18, $f0
  lwc1  $f16, 0x1098($v0)
  lwc1  $f4, 0x10ac($v0)
  lwc1  $f10, 0x10bc($v0)
  add.s $f6, $f16, $f4
  mul.s $f16, $f8, $f10
  sub.s $f4, $f6, $f16
  jr    $ra
   swc1  $f4, ($a1)
");

asm(R"
.late_rodata
glabel D_80054FAC
.word 0xe0ad78ec /*-1.0e20*/
.text
glabel sub_GAME_7F078060
  lwc1  $f0, 8($a0)
  mtc1  $zero, $f4
  li    $at, 0x3F800000 # 1.000000
  c.eq.s $f4, $f0
  nop   
  bc1fl .L7F07808C
   mtc1  $at, $f6
  lui    $at, %hi(D_80054FAC)
  b     .L7F078094
   lwc1  $f2, %lo(D_80054FAC)($at)
  mtc1  $at, $f6
.L7F07808C:
  nop   
  div.s $f2, $f6, $f0
.L7F078094:
  lwc1  $f8, 4($a0)
  lui   $v1, %hi(pPlayer)
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  mul.s $f10, $f8, $f2
  lw    $v0, ($v1)
  lwc1  $f16, 0x10c0($v0)
  lwc1  $f4, 0x109c($v0)
  lwc1  $f6, 0x10b0($v0)
  mul.s $f18, $f10, $f16
  add.s $f8, $f4, $f6
  add.s $f10, $f18, $f8
  swc1  $f10, 4($a1)
  lwc1  $f18, ($a0)
  lw    $v0, ($v1)
  mul.s $f8, $f18, $f2
  lwc1  $f16, 0x1098($v0)
  lwc1  $f4, 0x10ac($v0)
  lwc1  $f10, 0x10bc($v0)
  add.s $f6, $f16, $f4
  mul.s $f16, $f8, $f10
  sub.s $f4, $f6, $f16
  jr    $ra
   swc1  $f4, ($a1)
");

asm(R"
glabel sub_GAME_7F0780F0
  li    $at, 0x3F800000 # 1.000000
  mtc1  $a1, $f12
  mtc1  $at, $f4
  lwc1  $f6, 4($a0)
  lui   $v0, %hi(pPlayer)
  div.s $f0, $f4, $f12
  addiu $v0, %lo(pPlayer) # addiu $v0, $v0, -0x5f50
  lw    $t6, ($v0)
  lwc1  $f10, 0x10c0($t6)
  mul.s $f8, $f6, $f0
  nop   
  mul.s $f16, $f8, $f10
  swc1  $f16, 4($a2)
  lwc1  $f18, ($a0)
  lw    $t7, ($v0)
  mul.s $f4, $f18, $f0
  lwc1  $f6, 0x10bc($t7)
  mul.s $f8, $f4, $f6
  jr    $ra
   swc1  $f8, ($a2)
");

asm(R"
.late_rodata
glabel D_80054FB0
.word 0x40490fdb /*3.1415927*/

.text
glabel sub_GAME_7F078140
  lui    $at, %hi(D_80054FB0)
  mtc1  $a3, $f14
  lwc1  $f4, %lo(D_80054FB0)($at)
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f8
  mul.s $f6, $f14, $f4
  addiu $sp, $sp, -0x38
  sw    $ra, 0x14($sp)
  sw    $a0, 0x38($sp)
  sw    $a1, 0x3c($sp)
  sw    $a2, 0x40($sp)
  div.s $f12, $f6, $f8
  jal   sinf
   swc1  $f12, 0x18($sp)
  lwc1  $f12, 0x18($sp)
  jal   cosf
   swc1  $f0, 0x1c($sp)
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lwc1  $f10, 0x1c($sp)
  lwc1  $f6, 0x48($sp)
  lwc1  $f2, 0x10b0($v0)
  lw    $v1, 0x38($sp)
  lwc1  $f16, 0x10ac($v0)
  mul.s $f4, $f0, $f2
  li    $at, 0xBF800000 # -1.000000
  div.s $f14, $f10, $f4
  lwc1  $f4, 4($v1)
  mul.s $f8, $f14, $f6
  lwc1  $f6, 0x109c($v0)
  mul.s $f10, $f8, $f2
  sub.s $f8, $f4, $f6
  div.s $f18, $f10, $f16
  sub.s $f10, $f2, $f8
  mul.s $f4, $f10, $f14
  swc1  $f4, 0x2c($sp)
  lwc1  $f8, 0x1098($v0)
  lwc1  $f6, ($v1)
  sub.s $f10, $f6, $f8
  sub.s $f6, $f10, $f16
  mul.s $f8, $f6, $f18
  nop   
  mul.s $f10, $f8, $f8
  swc1  $f8, 0x30($sp)
  mul.s $f6, $f4, $f4
  mtc1  $at, $f4
  add.s $f8, $f10, $f6
  mtc1  $at, $f10
  nop   
  mul.s $f6, $f4, $f10
  jal   sqrtf
   add.s $f12, $f8, $f6
  lwc1  $f4, 0x40($sp)
  lwc1  $f10, 0x30($sp)
  lw    $v0, 0x3c($sp)
  div.s $f2, $f4, $f0
  li    $at, 0xBF800000 # -1.000000
  mul.s $f8, $f10, $f2
  mtc1  $at, $f10
  swc1  $f8, ($v0)
  lwc1  $f6, 0x2c($sp)
  mul.s $f4, $f6, $f2
  nop   
  mul.s $f8, $f10, $f2
  swc1  $f4, 4($v0)
  swc1  $f8, 8($v0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80054FB4
.word 0x40490fdb /*3.1415927*/
glabel D_80054FB8
.word 0
glabel D_80054FBC
.word 0

glabel a8s
/*"%8s"*/
.word 0x25387300

glabel aX4_0f
/*"x %4.0f"*/
.word 0x78202534
.word 0x2E306600 

glabel aY4_0f
/*"y %4.0f"*/
.word 0x79202534
.word 0x2E306600 

glabel aZ4_0f
/*"z %4.0f"*/
.word 0x7A202534
.word 0x2E306600 

glabel aS3d
/*"%s %3d"*/
.word 0x25732025
.word 0x33640000

.text
glabel sub_GAME_7F078258
  lui   $at, %hi(D_80054FB4)
  mtc1  $a2, $f14
  lwc1  $f4, %lo(D_80054FB4)($at)
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f8
  mul.s $f6, $f14, $f4
  addiu $sp, $sp, -0x30
  sw    $ra, 0x14($sp)
  sw    $a0, 0x30($sp)
  sw    $a1, 0x34($sp)
  sw    $a3, 0x3c($sp)
  div.s $f12, $f6, $f8
  jal   cosf
   swc1  $f12, 0x1c($sp)
  lwc1  $f12, 0x1c($sp)
  jal   sinf
   swc1  $f0, 0x20($sp)
  lui   $v1, %hi(pPlayer)
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $v0, ($v1)
  lw    $a0, 0x30($sp)
  lwc1  $f10, 0x20($sp)
  lwc1  $f2, 0x10b0($v0)
  lwc1  $f18, 8($a0)
  lwc1  $f6, 0x10ac($v0)
  mul.s $f16, $f10, $f2
  lwc1  $f10, 0x3c($sp)
  lw    $a1, 0x34($sp)
  mul.s $f4, $f18, $f0
  div.s $f12, $f16, $f4
  lwc1  $f16, 4($a0)
  mul.s $f8, $f6, $f12
  lwc1  $f6, 0x109c($v0)
  mul.s $f18, $f10, $f2
  add.s $f10, $f6, $f2
  mul.s $f4, $f16, $f12
  div.s $f14, $f8, $f18
  add.s $f8, $f4, $f10
  swc1  $f8, 4($a1)
  lw    $v0, ($v1)
  lwc1  $f4, ($a0)
  lwc1  $f18, 0x1098($v0)
  lwc1  $f16, 0x10ac($v0)
  add.s $f6, $f18, $f16
  mul.s $f10, $f4, $f14
  sub.s $f8, $f6, $f10
  swc1  $f8, ($a1)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

void set_BONDdata_field_10C4(int arg0) {
  pPlayer->field_10C4 = arg0;
}

int get_BONDdata_field_10C4(void) {
  return pPlayer->field_10C4;
}

void set_BONDdata_field_10C8(int arg0) {
  pPlayer->field_10C8 = arg0;
}

int get_BONDdata_field_10C8(void) {
  return pPlayer->field_10C8;
}

void set_BONDdata_field_10D8(int arg0) {
  pPlayer->field_10D8 = arg0;
}

int get_BONDdata_field_10D8(void) {
  return pPlayer->field_10D8;
}

void set_BONDdata_field_10E0(int arg0) {
  pPlayer->field_10E0 = arg0;
}

int get_BONDdata_field_10E0(void) {
  return pPlayer->field_10E0;
}

void *copy_BONDdata_field_10CC_to_10E8_set_10CC(int arg0) {
  pPlayer->field_10E8 = (int)pPlayer->field_10CC;
  pPlayer->field_10CC = arg0;
}

int get_BONDdata_field_10CC(void) {
  return pPlayer->field_10CC;
}

void set_BONDdata_field_10DC(int arg0) {
  pPlayer->field_10DC = arg0;
}

int get_BONDdata_field_10DC(void) {
  return pPlayer->field_10DC;
}

int sub_GAME_7F0783F4(void) {
  return pPlayer->field_10E8;
}

void sub_GAME_7F078404(int arg0) {
  pPlayer->field_10D0 = arg0;
}

int sub_GAME_7F078414(void) {
  return pPlayer->field_10D0;
}

void sub_GAME_7F078424(int arg0) {
  pPlayer->field_10EC = pPlayer->field_10D4;
  pPlayer->field_10D4 = arg0;
}

int sub_GAME_7F078444(void) {
  return pPlayer->field_10D4;
}

int sub_GAME_7F078454(void) {
  return pPlayer->field_10EC;
}

void sub_GAME_7F078464(int arg0) {
  pPlayer->field_10E4 = arg0;
}

int sub_GAME_7F078474(void) {
  return pPlayer->field_10E4;
}

float getPlayer_c_lodscalez(void) 
{
  return pPlayer->c_lodscalez;
}

unsigned int getPlayer_c_lodscalezu32(void)
{
  return pPlayer->c_lodscalezu32;
}

float getPlayer_c_screenwidth(void)
{
  return pPlayer->c_screenwidth;
}

float getPlayer_c_screenheight(void)
{
  return pPlayer->c_screenheight;
}

float getPlayer_c_screenleft(void)
{
  return pPlayer->c_screenleft;
}

float getPlayer_c_screentop(void)
{
  return pPlayer->c_screentop;
}

float getPlayer_c_perspfovy(void)
{
  return pPlayer->c_perspfovy;
}

float getPlayer_c_perspaspect(void)
{
  return pPlayer->c_perspaspect;
}

asm(R"
glabel sub_GAME_7F078504
  lui   $v0, %hi(pPlayer)
  addiu $v0, %lo(pPlayer) # addiu $v0, $v0, -0x5f50
  lw    $t6, ($v0)
  lwc1  $f4, 0x1100($t6)
  swc1  $f4, ($a0)
  lw    $t7, ($v0)
  lwc1  $f6, 0x1104($t7)
  swc1  $f6, 4($a0)
  lw    $t8, ($v0)
  lwc1  $f8, 0x1108($t8)
  jr    $ra
   swc1  $f8, 8($a0)
");

asm(R"
glabel sub_GAME_7F078534
  lui   $v0, %hi(pPlayer)
  addiu $v0, %lo(pPlayer) # addiu $v0, $v0, -0x5f50
  lw    $t6, ($v0)
  lwc1  $f4, 0x1100($t6)
  swc1  $f4, ($a0)
  lw    $t7, ($v0)
  lwc1  $f6, 0x1104($t7)
  neg.s $f8, $f6
  swc1  $f8, 4($a0)
  lw    $t8, ($v0)
  lwc1  $f10, 0x1108($t8)
  jr    $ra
   swc1  $f10, 8($a0)
");

asm(R"
glabel sub_GAME_7F078568
  lui   $v0, %hi(pPlayer)
  addiu $v0, %lo(pPlayer) # addiu $v0, $v0, -0x5f50
  lw    $t6, ($v0)
  lwc1  $f4, 0x110c($t6)
  swc1  $f4, ($a0)
  lw    $t7, ($v0)
  lwc1  $f6, 0x1110($t7)
  swc1  $f6, 4($a0)
  lw    $t8, ($v0)
  lwc1  $f8, 0x1114($t8)
  jr    $ra
   swc1  $f8, 8($a0)
");

asm(R"
glabel sub_GAME_7F078598
  lui   $v0, %hi(pPlayer)
  addiu $v0, %lo(pPlayer) # addiu $v0, $v0, -0x5f50
  lw    $t6, ($v0)
  lwc1  $f4, 0x110c($t6)
  neg.s $f6, $f4
  swc1  $f6, ($a0)
  lw    $t7, ($v0)
  lwc1  $f8, 0x1110($t7)
  swc1  $f8, 4($a0)
  lw    $t8, ($v0)
  lwc1  $f10, 0x1114($t8)
  jr    $ra
   swc1  $f10, 8($a0)
");

float getPlayer_c_perspnear(void)
{
  return pPlayer->c_perspnear;
}

asm(R"
glabel sub_GAME_7F0785DC
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  addiu $sp, $sp, -0x30
  sw    $ra, 0x1c($sp)
  sdc1  $f20, 0x10($sp)
  lwc1  $f6, 0x10b8($v1)
  lwc1  $f4, 0x10b0($v1)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  mul.s $f2, $f4, $f6
  nop   
  mul.s $f8, $f2, $f2
  swc1  $f2, 0x24($sp)
  jal   sqrtf
   add.s $f12, $f8, $f10
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  lwc1  $f2, 0x24($sp)
  lui   $v1, %hi(pPlayer)
  div.s $f20, $f4, $f0
  lw    $v1, %lo(pPlayer)($v1)
  lui   $a0, %hi(flt_CODE_bss_80079940)
  addiu $a0, %lo(flt_CODE_bss_80079940) # addiu $a0, $a0, -0x66c0
  lw    $v0, 0x10d4($v1)
  lui   $at, %hi(flt_CODE_bss_8007994C)
  lui   $a1, %hi(flt_CODE_bss_80079950)
  lwc1  $f6, 0x20($v0)
  lwc1  $f10, 0x10($v0)
  addiu $a1, %lo(flt_CODE_bss_80079950) # addiu $a1, $a1, -0x66b0
  mul.s $f2, $f2, $f20
  neg.s $f16, $f20
  neg.s $f18, $f16
  mul.s $f8, $f6, $f2
  nop   
  mul.s $f4, $f18, $f10
  add.s $f6, $f8, $f4
  swc1  $f6, ($a0)
  lw    $v0, 0x10d4($v1)
  lwc1  $f10, 0x24($v0)
  lwc1  $f4, 0x14($v0)
  mul.s $f8, $f10, $f2
  nop   
  mul.s $f6, $f18, $f4
  add.s $f10, $f8, $f6
  swc1  $f10, 4($a0)
  lw    $v0, 0x10d4($v1)
  lwc1  $f4, 0x28($v0)
  lwc1  $f6, 0x18($v0)
  mul.s $f8, $f4, $f2
  nop   
  mul.s $f10, $f18, $f6
  lwc1  $f6, ($a0)
  add.s $f4, $f8, $f10
  swc1  $f4, 8($a0)
  lw    $v0, 0x10d4($v1)
  lwc1  $f4, 4($a0)
  lwc1  $f8, 0x30($v0)
  mul.s $f10, $f6, $f8
  lwc1  $f6, 0x34($v0)
  mul.s $f8, $f4, $f6
  lwc1  $f6, 0x38($v0)
  add.s $f4, $f10, $f8
  lwc1  $f10, 8($a0)
  mul.s $f8, $f6, $f10
  add.s $f6, $f8, $f4
  swc1  $f6, %lo(flt_CODE_bss_8007994C)($at)
  lw    $v0, 0x10d4($v1)
  lui   $at, %hi(flt_CODE_bss_8007995C)
  lwc1  $f10, 0x20($v0)
  lwc1  $f4, 0x10($v0)
  mul.s $f8, $f10, $f2
  nop   
  mul.s $f6, $f16, $f4
  add.s $f10, $f8, $f6
  swc1  $f10, ($a1)
  lw    $v0, 0x10d4($v1)
  lwc1  $f4, 0x24($v0)
  lwc1  $f6, 0x14($v0)
  mul.s $f8, $f4, $f2
  nop   
  mul.s $f10, $f16, $f6
  add.s $f4, $f8, $f10
  swc1  $f4, 4($a1)
  lw    $v0, 0x10d4($v1)
  lwc1  $f6, 0x28($v0)
  lwc1  $f10, 0x18($v0)
  mul.s $f8, $f6, $f2
  nop   
  mul.s $f4, $f16, $f10
  lwc1  $f10, ($a1)
  add.s $f6, $f8, $f4
  swc1  $f6, 8($a1)
  lw    $v0, 0x10d4($v1)
  lwc1  $f6, 4($a1)
  lwc1  $f8, 0x30($v0)
  mul.s $f4, $f10, $f8
  lwc1  $f10, 0x34($v0)
  mul.s $f8, $f6, $f10
  lwc1  $f10, 0x38($v0)
  add.s $f6, $f4, $f8
  lwc1  $f4, 8($a1)
  mul.s $f8, $f10, $f4
  add.s $f10, $f8, $f6
  swc1  $f10, %lo(flt_CODE_bss_8007995C)($at)
  lwc1  $f4, 0x10ac($v1)
  lwc1  $f6, 0x10b4($v1)
  li    $at, 0x3F800000 # 1.000000
  neg.s $f8, $f4
  mtc1  $at, $f4
  mul.s $f14, $f8, $f6
  nop   
  mul.s $f10, $f14, $f14
  swc1  $f14, 0x28($sp)
  jal   sqrtf
   add.s $f12, $f10, $f4
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  div.s $f20, $f8, $f0
  lwc1  $f14, 0x28($sp)
  lw    $v0, 0x10d4($v1)
  lui   $a0, %hi(flt_CODE_bss_80079960)
  addiu $a0, %lo(flt_CODE_bss_80079960) # addiu $a0, $a0, -0x66a0
  lwc1  $f6, ($v0)
  lwc1  $f4, 0x20($v0)
  lui   $at, %hi(flt_CODE_bss_8007996C)
  lui   $a1, %hi(flt_CODE_bss_80079970)
  addiu $a1, %lo(flt_CODE_bss_80079970) # addiu $a1, $a1, -0x6690
  lw    $ra, 0x1c($sp)
  mul.s $f14, $f14, $f20
  neg.s $f16, $f20
  ldc1  $f20, 0x10($sp)
  mul.s $f10, $f16, $f6
  neg.s $f18, $f16
  mul.s $f8, $f4, $f14
  sub.s $f6, $f10, $f8
  swc1  $f6, ($a0)
  lw    $v0, 0x10d4($v1)
  lwc1  $f4, 4($v0)
  lwc1  $f8, 0x24($v0)
  mul.s $f10, $f16, $f4
  nop   
  mul.s $f6, $f8, $f14
  sub.s $f4, $f10, $f6
  swc1  $f4, 4($a0)
  lw    $v0, 0x10d4($v1)
  lwc1  $f8, 8($v0)
  lwc1  $f6, 0x28($v0)
  mul.s $f10, $f16, $f8
  nop   
  mul.s $f4, $f6, $f14
  lwc1  $f6, ($a0)
  sub.s $f8, $f10, $f4
  swc1  $f8, 8($a0)
  lw    $v0, 0x10d4($v1)
  lwc1  $f8, 4($a0)
  lwc1  $f10, 0x30($v0)
  mul.s $f4, $f6, $f10
  lwc1  $f6, 0x34($v0)
  mul.s $f10, $f8, $f6
  lwc1  $f6, 0x38($v0)
  add.s $f8, $f4, $f10
  lwc1  $f4, 8($a0)
  mul.s $f10, $f6, $f4
  add.s $f6, $f10, $f8
  swc1  $f6, %lo(flt_CODE_bss_8007996C)($at)
  lw    $v0, 0x10d4($v1)
  lui   $at, %hi(flt_CODE_bss_8007997C)
  lwc1  $f4, ($v0)
  lwc1  $f8, 0x20($v0)
  mul.s $f10, $f18, $f4
  nop   
  mul.s $f6, $f8, $f14
  sub.s $f4, $f10, $f6
  swc1  $f4, ($a1)
  lw    $v0, 0x10d4($v1)
  lwc1  $f8, 4($v0)
  lwc1  $f6, 0x24($v0)
  mul.s $f10, $f18, $f8
  nop   
  mul.s $f4, $f6, $f14
  sub.s $f8, $f10, $f4
  swc1  $f8, 4($a1)
  lw    $v0, 0x10d4($v1)
  lwc1  $f6, 8($v0)
  lwc1  $f4, 0x28($v0)
  mul.s $f10, $f18, $f6
  nop   
  mul.s $f8, $f4, $f14
  lwc1  $f4, ($a1)
  sub.s $f6, $f10, $f8
  swc1  $f6, 8($a1)
  lw    $v0, 0x10d4($v1)
  lwc1  $f6, 4($a1)
  lwc1  $f10, 0x30($v0)
  mul.s $f8, $f4, $f10
  lwc1  $f4, 0x34($v0)
  mul.s $f10, $f6, $f4
  lwc1  $f4, 0x38($v0)
  add.s $f6, $f8, $f10
  lwc1  $f8, 8($a1)
  mul.s $f10, $f4, $f8
  add.s $f4, $f10, $f6
  swc1  $f4, %lo(flt_CODE_bss_8007997C)($at)
  lw    $v0, 0x10d4($v1)
  lui   $at, %hi(flt_CODE_bss_80079980)
  lwc1  $f8, 0x20($v0)
  lwc1  $f10, 0x30($v0)
  lwc1  $f4, 0x24($v0)
  mul.s $f6, $f8, $f10
  lwc1  $f8, 0x34($v0)
  mul.s $f10, $f4, $f8
  lwc1  $f8, 0x38($v0)
  add.s $f4, $f6, $f10
  lwc1  $f6, 0x28($v0)
  addiu $sp, $sp, 0x30
  mul.s $f10, $f8, $f6
  add.s $f8, $f10, $f4
  jr    $ra
   swc1  $f8, %lo(flt_CODE_bss_80079980)($at)
");

asm(R"
glabel sub_GAME_7F078950
  lui   $v0, %hi(flt_CODE_bss_80079940)
  addiu $v0, %lo(flt_CODE_bss_80079940) # addiu $v0, $v0, -0x66c0
  lwc1  $f4, ($v0)
  lui   $at, %hi(flt_CODE_bss_8007994C)
  swc1  $f4, ($a0)
  lwc1  $f6, 4($v0)
  swc1  $f6, 4($a0)
  lwc1  $f8, 8($v0)
  swc1  $f8, 8($a0)
  lwc1  $f10, %lo(flt_CODE_bss_8007994C)($at)
  jr    $ra
   swc1  $f10, ($a1)
");

asm(R"
glabel sub_GAME_7F078980
  lui   $v0, %hi(flt_CODE_bss_80079950)
  addiu $v0, %lo(flt_CODE_bss_80079950) # addiu $v0, $v0, -0x66b0
  lwc1  $f4, ($v0)
  lui   $at, %hi(flt_CODE_bss_8007995C)
  swc1  $f4, ($a0)
  lwc1  $f6, 4($v0)
  swc1  $f6, 4($a0)
  lwc1  $f8, 8($v0)
  swc1  $f8, 8($a0)
  lwc1  $f10, %lo(flt_CODE_bss_8007995C)($at)
  jr    $ra
   swc1  $f10, ($a1)
");

asm(R"
glabel sub_GAME_7F0789B0
  lui   $v0, %hi(flt_CODE_bss_80079960)
  addiu $v0, %lo(flt_CODE_bss_80079960) # addiu $v0, $v0, -0x66a0
  lwc1  $f4, ($v0)
  lui   $at, %hi(flt_CODE_bss_8007996C)
  swc1  $f4, ($a0)
  lwc1  $f6, 4($v0)
  swc1  $f6, 4($a0)
  lwc1  $f8, 8($v0)
  swc1  $f8, 8($a0)
  lwc1  $f10, %lo(flt_CODE_bss_8007996C)($at)
  jr    $ra
   swc1  $f10, ($a1)
");

asm(R"
glabel sub_GAME_7F0789E0
  lui   $v0, %hi(flt_CODE_bss_80079970)
  addiu $v0, %lo(flt_CODE_bss_80079970) # addiu $v0, $v0, -0x6690
  lwc1  $f4, ($v0)
  lui   $at, %hi(flt_CODE_bss_8007997C)
  swc1  $f4, ($a0)
  lwc1  $f6, 4($v0)
  swc1  $f6, 4($a0)
  lwc1  $f8, 8($v0)
  swc1  $f8, 8($a0)
  lwc1  $f10, %lo(flt_CODE_bss_8007997C)($at)
  jr    $ra
   swc1  $f10, ($a1)
");

asm(R"
glabel sub_GAME_7F078A10
  lui   $v0, %hi(pPlayer)
  addiu $v0, %lo(pPlayer) # addiu $v0, $v0, -0x5f50
  lw    $t6, ($v0)
  lui   $at, %hi(flt_CODE_bss_80079980)
  lw    $t7, 0x10d4($t6)
  lwc1  $f4, 0x20($t7)
  swc1  $f4, ($a0)
  lw    $t8, ($v0)
  lw    $t9, 0x10d4($t8)
  lwc1  $f6, 0x24($t9)
  swc1  $f6, 4($a0)
  lw    $t0, ($v0)
  lw    $t1, 0x10d4($t0)
  lwc1  $f8, 0x28($t1)
  swc1  $f8, 8($a0)
  lwc1  $f10, %lo(flt_CODE_bss_80079980)($at)
  jr    $ra
   swc1  $f10, ($a1)
");

asm(R"
glabel sub_GAME_7F078A58
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  lwc1  $f2, ($a0)
  lwc1  $f14, 4($a0)
  lw    $v0, 0x10d4($t6)
  lwc1  $f0, 8($a0)
  lui   $at, %hi(flt_CODE_bss_80079980)
  lwc1  $f8, 0x20($v0)
  lwc1  $f16, 0x24($v0)
  mtc1  $a1, $f12
  mul.s $f10, $f8, $f2
  lwc1  $f8, 0x28($v0)
  lwc1  $f4, %lo(flt_CODE_bss_80079980)($at)
  mul.s $f18, $f16, $f14
  lui   $v0, %hi(flt_CODE_bss_80079960)
  add.s $f6, $f4, $f12
  mul.s $f16, $f0, $f8
  addiu $v0, %lo(flt_CODE_bss_80079960) # addiu $v0, $v0, -0x66a0
  add.s $f4, $f10, $f18
  add.s $f10, $f16, $f4
  c.lt.s $f6, $f10
  nop   
  bc1fl .L7F078AC4
   lwc1  $f16, ($v0)
  jr    $ra
   move  $v0, $zero

  lwc1  $f16, ($v0)
.L7F078AC4:
  lwc1  $f6, 4($v0)
  lui   $at, %hi(flt_CODE_bss_8007996C)
  mul.s $f4, $f16, $f2
  lwc1  $f16, 8($v0)
  lwc1  $f18, %lo(flt_CODE_bss_8007996C)($at)
  mul.s $f10, $f6, $f14
  lui   $v0, %hi(flt_CODE_bss_80079970)
  add.s $f8, $f18, $f12
  mul.s $f6, $f0, $f16
  addiu $v0, %lo(flt_CODE_bss_80079970) # addiu $v0, $v0, -0x6690
  add.s $f18, $f4, $f10
  add.s $f4, $f6, $f18
  c.lt.s $f8, $f4
  nop   
  bc1fl .L7F078B10
   lwc1  $f6, ($v0)
  jr    $ra
   move  $v0, $zero

  lwc1  $f6, ($v0)
.L7F078B10:
  lwc1  $f8, 4($v0)
  lui   $at, %hi(flt_CODE_bss_8007997C)
  mul.s $f18, $f6, $f2
  lwc1  $f6, 8($v0)
  lwc1  $f10, %lo(flt_CODE_bss_8007997C)($at)
  mul.s $f4, $f8, $f14
  lui   $v0, %hi(flt_CODE_bss_80079940)
  add.s $f16, $f10, $f12
  mul.s $f8, $f0, $f6
  addiu $v0, %lo(flt_CODE_bss_80079940) # addiu $v0, $v0, -0x66c0
  add.s $f10, $f18, $f4
  add.s $f18, $f8, $f10
  c.lt.s $f16, $f18
  nop   
  bc1fl .L7F078B5C
   lwc1  $f8, ($v0)
  jr    $ra
   move  $v0, $zero

  lwc1  $f8, ($v0)
.L7F078B5C:
  lwc1  $f16, 4($v0)
  lui   $at, %hi(flt_CODE_bss_8007994C)
  mul.s $f10, $f8, $f2
  lwc1  $f8, 8($v0)
  lwc1  $f4, %lo(flt_CODE_bss_8007994C)($at)
  mul.s $f18, $f16, $f14
  lui   $v0, %hi(flt_CODE_bss_80079950)
  add.s $f6, $f4, $f12
  mul.s $f16, $f0, $f8
  addiu $v0, %lo(flt_CODE_bss_80079950) # addiu $v0, $v0, -0x66b0
  add.s $f4, $f10, $f18
  add.s $f10, $f16, $f4
  c.lt.s $f6, $f10
  nop   
  bc1fl .L7F078BA8
   lwc1  $f16, ($v0)
  jr    $ra
   move  $v0, $zero

  lwc1  $f16, ($v0)
.L7F078BA8:
  lwc1  $f6, 4($v0)
  lui   $at, %hi(flt_CODE_bss_8007995C)
  mul.s $f4, $f16, $f2
  lwc1  $f16, 8($v0)
  lwc1  $f18, %lo(flt_CODE_bss_8007995C)($at)
  mul.s $f10, $f6, $f14
  li    $v0, 1
  add.s $f8, $f18, $f12
  mul.s $f6, $f0, $f16
  add.s $f18, $f4, $f10
  add.s $f4, $f6, $f18
  c.lt.s $f8, $f4
  nop   
  bc1f  .L7F078BEC
   nop   
  jr    $ra
   move  $v0, $zero

.L7F078BEC:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F078BF4
  addiu $sp, $sp, -0x80
  sw    $s0, 0x28($sp)
  lui   $s0, %hi(pPlayer)
  lw    $s0, %lo(pPlayer)($s0)
  sw    $ra, 0x2c($sp)
  sdc1  $f22, 0x20($sp)
  sdc1  $f20, 0x18($sp)
  sw    $a2, 0x88($sp)
  lw    $v0, 0x10d4($s0)
  lui   $at, %hi(flt_CODE_bss_80079980)
  mtc1  $a1, $f22
  lwc1  $f4, %lo(flt_CODE_bss_80079980)($at)
  lwc1  $f10, ($a0)
  lwc1  $f8, 0x20($v0)
  add.s $f6, $f4, $f22
  lwc1  $f4, 0x24($v0)
  mul.s $f18, $f8, $f10
  lwc1  $f8, 4($a0)
  lw    $t6, 0x88($sp)
  mul.s $f10, $f4, $f8
  lwc1  $f8, 8($a0)
  add.s $f4, $f18, $f10
  lwc1  $f18, 0x28($v0)
  mul.s $f10, $f8, $f18
  add.s $f8, $f10, $f4
  c.lt.s $f6, $f8
  nop   
  bc1fl .L7F078C74
   lwc1  $f18, ($t6)
  b     .L7F0790D8
   move  $v0, $zero
  lwc1  $f18, ($t6)
.L7F078C74:
  lwc1  $f10, 0x1098($s0)
  lwc1  $f6, 0x10ac($s0)
  li    $at, 0x3F800000 # 1.000000
  sub.s $f4, $f18, $f10
  lwc1  $f18, 0x10b4($s0)
  mtc1  $at, $f20
  sw    $a0, 0x80($sp)
  sub.s $f8, $f4, $f6
  mul.s $f2, $f8, $f18
  nop   
  mul.s $f10, $f2, $f2
  swc1  $f2, 0x38($sp)
  jal   sqrtf
   add.s $f12, $f10, $f20
  div.s $f12, $f20, $f0
  lui   $s0, %hi(pPlayer)
  lw    $s0, %lo(pPlayer)($s0)
  lwc1  $f2, 0x38($sp)
  lw    $a0, 0x80($sp)
  lw    $v0, 0x10d4($s0)
  lw    $t7, 0x88($sp)
  lwc1  $f4, ($v0)
  lwc1  $f8, 0x20($v0)
  mul.s $f2, $f2, $f12
  neg.s $f14, $f12
  mul.s $f6, $f14, $f4
  nop   
  mul.s $f18, $f8, $f2
  sub.s $f10, $f6, $f18
  swc1  $f10, 0x54($sp)
  lw    $v0, 0x10d4($s0)
  lwc1  $f4, 4($v0)
  lwc1  $f6, 0x24($v0)
  mul.s $f8, $f14, $f4
  nop   
  mul.s $f18, $f6, $f2
  sub.s $f4, $f8, $f18
  swc1  $f4, 0x58($sp)
  lw    $v0, 0x10d4($s0)
  lwc1  $f6, 8($v0)
  lwc1  $f18, 0x28($v0)
  mul.s $f8, $f14, $f6
  nop   
  mul.s $f6, $f18, $f2
  sub.s $f18, $f8, $f6
  swc1  $f18, 0x5c($sp)
  lw    $v0, 0x10d4($s0)
  lwc1  $f8, 0x30($v0)
  mul.s $f6, $f10, $f8
  lwc1  $f8, 0x34($v0)
  mul.s $f8, $f4, $f8
  add.s $f6, $f6, $f8
  lwc1  $f8, 0x38($v0)
  mul.s $f8, $f8, $f18
  add.s $f16, $f8, $f6
  lwc1  $f6, ($a0)
  mul.s $f10, $f10, $f6
  lwc1  $f6, 4($a0)
  add.s $f8, $f16, $f22
  mul.s $f4, $f4, $f6
  add.s $f6, $f10, $f4
  lwc1  $f10, 8($a0)
  mul.s $f4, $f10, $f18
  add.s $f10, $f4, $f6
  c.lt.s $f8, $f10
  nop   
  bc1f  .L7F078D8C
   nop   
  b     .L7F0790D8
   move  $v0, $zero
.L7F078D8C:
  lwc1  $f18, 8($t7)
  lwc1  $f4, 0x1098($s0)
  lwc1  $f8, 0x10ac($s0)
  sub.s $f6, $f18, $f4
  lwc1  $f4, 0x10b4($s0)
  sw    $a0, 0x80($sp)
  sub.s $f10, $f6, $f8
  neg.s $f18, $f10
  mul.s $f2, $f18, $f4
  nop   
  mul.s $f6, $f2, $f2
  swc1  $f2, 0x38($sp)
  jal   sqrtf
   add.s $f12, $f6, $f20
  div.s $f12, $f20, $f0
  lui   $s0, %hi(pPlayer)
  lw    $s0, %lo(pPlayer)($s0)
  lwc1  $f2, 0x38($sp)
  lw    $a0, 0x80($sp)
  lw    $v0, 0x10d4($s0)
  lw    $t8, 0x88($sp)
  lwc1  $f8, ($v0)
  lwc1  $f18, 0x20($v0)
  mul.s $f2, $f2, $f12
  neg.s $f14, $f12
  neg.s $f14, $f14
  mul.s $f10, $f14, $f8
  nop   
  mul.s $f4, $f18, $f2
  sub.s $f6, $f10, $f4
  swc1  $f6, 0x44($sp)
  lw    $v0, 0x10d4($s0)
  lwc1  $f8, 4($v0)
  lwc1  $f10, 0x24($v0)
  mul.s $f18, $f14, $f8
  nop   
  mul.s $f4, $f10, $f2
  sub.s $f8, $f18, $f4
  swc1  $f8, 0x48($sp)
  lw    $v0, 0x10d4($s0)
  lwc1  $f10, 8($v0)
  lwc1  $f4, 0x28($v0)
  mul.s $f18, $f14, $f10
  nop   
  mul.s $f10, $f4, $f2
  sub.s $f4, $f18, $f10
  swc1  $f4, 0x4c($sp)
  lw    $v0, 0x10d4($s0)
  lwc1  $f18, 0x30($v0)
  mul.s $f10, $f6, $f18
  lwc1  $f18, 0x34($v0)
  mul.s $f18, $f8, $f18
  add.s $f10, $f10, $f18
  lwc1  $f18, 0x38($v0)
  mul.s $f18, $f18, $f4
  add.s $f16, $f18, $f10
  lwc1  $f10, ($a0)
  mul.s $f6, $f6, $f10
  lwc1  $f10, 4($a0)
  add.s $f18, $f16, $f22
  mul.s $f8, $f8, $f10
  add.s $f10, $f6, $f8
  lwc1  $f6, 8($a0)
  mul.s $f8, $f6, $f4
  add.s $f6, $f8, $f10
  c.lt.s $f18, $f6
  nop   
  bc1f  .L7F078EA8
   nop   
  b     .L7F0790D8
   move  $v0, $zero
.L7F078EA8:
  lwc1  $f4, 4($t8)
  lwc1  $f8, 0x109c($s0)
  lwc1  $f18, 0x10b0($s0)
  sub.s $f10, $f4, $f8
  lwc1  $f4, 0x10b8($s0)
  sw    $a0, 0x80($sp)
  sub.s $f6, $f18, $f10
  mul.s $f2, $f6, $f4
  nop   
  mul.s $f8, $f2, $f2
  swc1  $f2, 0x34($sp)
  jal   sqrtf
   add.s $f12, $f8, $f20
  div.s $f12, $f20, $f0
  lwc1  $f2, 0x34($sp)
  lui   $s0, %hi(pPlayer)
  lw    $s0, %lo(pPlayer)($s0)
  lw    $a0, 0x80($sp)
  lw    $t9, 0x88($sp)
  lw    $v0, 0x10d4($s0)
  lwc1  $f18, 0x20($v0)
  lwc1  $f6, 0x10($v0)
  mul.s $f2, $f2, $f12
  neg.s $f14, $f12
  neg.s $f14, $f14
  mul.s $f10, $f18, $f2
  nop   
  mul.s $f4, $f14, $f6
  add.s $f8, $f10, $f4
  swc1  $f8, 0x74($sp)
  lw    $v0, 0x10d4($s0)
  lwc1  $f18, 0x24($v0)
  lwc1  $f10, 0x14($v0)
  mul.s $f6, $f18, $f2
  nop   
  mul.s $f4, $f14, $f10
  add.s $f18, $f6, $f4
  swc1  $f18, 0x78($sp)
  lw    $v0, 0x10d4($s0)
  lwc1  $f10, 0x28($v0)
  lwc1  $f4, 0x18($v0)
  mul.s $f6, $f10, $f2
  nop   
  mul.s $f10, $f14, $f4
  add.s $f4, $f6, $f10
  swc1  $f4, 0x7c($sp)
  lw    $v0, 0x10d4($s0)
  lwc1  $f6, 0x30($v0)
  mul.s $f10, $f8, $f6
  lwc1  $f6, 0x34($v0)
  mul.s $f6, $f18, $f6
  add.s $f10, $f10, $f6
  lwc1  $f6, 0x38($v0)
  mul.s $f6, $f6, $f4
  add.s $f16, $f6, $f10
  lwc1  $f10, ($a0)
  mul.s $f8, $f8, $f10
  lwc1  $f10, 4($a0)
  add.s $f6, $f16, $f22
  mul.s $f18, $f18, $f10
  add.s $f10, $f8, $f18
  lwc1  $f8, 8($a0)
  mul.s $f18, $f8, $f4
  add.s $f8, $f18, $f10
  c.lt.s $f6, $f8
  nop   
  bc1f  .L7F078FC0
   nop   
  b     .L7F0790D8
   move  $v0, $zero
.L7F078FC0:
  lwc1  $f4, 0xc($t9)
  lwc1  $f18, 0x109c($s0)
  lwc1  $f6, 0x10b0($s0)
  sub.s $f10, $f4, $f18
  lwc1  $f18, 0x10b8($s0)
  sw    $a0, 0x80($sp)
  sub.s $f8, $f6, $f10
  neg.s $f4, $f8
  mul.s $f2, $f4, $f18
  nop   
  mul.s $f6, $f2, $f2
  swc1  $f2, 0x34($sp)
  jal   sqrtf
   add.s $f12, $f6, $f20
  div.s $f12, $f20, $f0
  lwc1  $f2, 0x34($sp)
  lui   $s0, %hi(pPlayer)
  lw    $s0, %lo(pPlayer)($s0)
  lw    $a0, 0x80($sp)
  lw    $v0, 0x10d4($s0)
  lwc1  $f10, 0x20($v0)
  lwc1  $f4, 0x10($v0)
  mul.s $f2, $f2, $f12
  neg.s $f14, $f12
  mul.s $f8, $f10, $f2
  nop   
  mul.s $f18, $f14, $f4
  add.s $f6, $f8, $f18
  swc1  $f6, 0x64($sp)
  lw    $v0, 0x10d4($s0)
  lwc1  $f10, 0x24($v0)
  lwc1  $f8, 0x14($v0)
  mul.s $f4, $f10, $f2
  nop   
  mul.s $f18, $f14, $f8
  add.s $f10, $f4, $f18
  swc1  $f10, 0x68($sp)
  lw    $v0, 0x10d4($s0)
  lwc1  $f8, 0x28($v0)
  lwc1  $f18, 0x18($v0)
  mul.s $f4, $f8, $f2
  nop   
  mul.s $f8, $f14, $f18
  add.s $f18, $f4, $f8
  swc1  $f18, 0x6c($sp)
  lw    $v0, 0x10d4($s0)
  lwc1  $f4, 0x30($v0)
  mul.s $f8, $f6, $f4
  lwc1  $f4, 0x34($v0)
  mul.s $f4, $f10, $f4
  add.s $f8, $f8, $f4
  lwc1  $f4, 0x38($v0)
  li    $v0, 1
  mul.s $f4, $f4, $f18
  add.s $f16, $f4, $f8
  lwc1  $f8, ($a0)
  mul.s $f6, $f6, $f8
  lwc1  $f8, 4($a0)
  add.s $f4, $f16, $f22
  mul.s $f10, $f10, $f8
  add.s $f8, $f6, $f10
  lwc1  $f6, 8($a0)
  mul.s $f10, $f6, $f18
  add.s $f6, $f10, $f8
  c.lt.s $f4, $f6
  nop   
  bc1f  .L7F0790D8
   nop   
  b     .L7F0790D8
   move  $v0, $zero
.L7F0790D8:
  lw    $ra, 0x2c($sp)
  ldc1  $f20, 0x18($sp)
  ldc1  $f22, 0x20($sp)
  lw    $s0, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x80
");

asm(R"
glabel sub_GAME_7F0790F0
  addiu $sp, $sp, -0x60
  sw    $ra, 0x44($sp)
  sw    $fp, 0x40($sp)
  sw    $s7, 0x3c($sp)
  sw    $s6, 0x38($sp)
  sw    $s5, 0x34($sp)
  sw    $s4, 0x30($sp)
  sw    $s3, 0x2c($sp)
  sw    $s2, 0x28($sp)
  sw    $s1, 0x24($sp)
  sw    $s0, 0x20($sp)
  jal   get_cur_playernum
   sdc1  $f20, 0x18($sp)
  jal   getPlayerCount
   move  $s6, $v0
  lui   $t6, %hi(dword_CODE_bss_80079C68) 
  lw    $t6, %lo(dword_CODE_bss_80079C68)($t6)
  move  $s2, $v0
  li    $s1, 1
  blez  $t6, .L7F07925C
   move  $s7, $zero
  li    $at, 0x447A0000 # 1000.000000
  lui   $fp, %hi(pPlayer) 
  lui   $s5, %hi(dword_CODE_bss_80079C28)
  lui   $s4, %hi(players_p1)
  mtc1  $at, $f20
  addiu $s4, %lo(players_p1) # addiu $s4, $s4, -0x6120
  addiu $s5, %lo(dword_CODE_bss_80079C28) # addiu $s5, $s5, -0x63d8
  addiu $fp, %lo(pPlayer) # addiu $fp, $fp, -0x5f50
  lw    $v0, ($fp)
.L7F079168:
  lui   $t1, %hi(dword_CODE_bss_80079C68) 
  addiu $s7, $s7, 1
  lw    $t7, 0x29e0($v0)
  move  $s1, $zero
  move  $s0, $zero
  addiu $t8, $t7, 1
  sw    $t8, 0x29e0($v0)
  lw    $t9, ($fp)
  lw    $t1, %lo(dword_CODE_bss_80079C68)($t1)
  lw    $t0, 0x29e0($t9)
  div   $zero, $t0, $t1
  mfhi  $s3
  bnez  $t1, .L7F0791A4
   nop   
  break 7
.L7F0791A4:
  li    $at, -1
  bne   $t1, $at, .L7F0791BC
   lui   $at, 0x8000
  bne   $t0, $at, .L7F0791BC
   nop   
  break 6
.L7F0791BC:
  blez  $s2, .L7F07923C
   nop   
.L7F0791C4:
  beql  $s0, $s6, .L7F079234
   addiu $s0, $s0, 1
  sll   $t2, $s0, 2
  addu  $t3, $s4, $t2
  lw    $t4, ($t3)
  lw    $v0, 0xa8($t4)
  beql  $v0, $zero, .L7F079234
   addiu $s0, $s0, 1
  sll   $t5, $s3, 2
  addu  $t6, $s5, $t5
  lw    $v1, ($t6)
  lwc1  $f4, 8($v0)
  lwc1  $f8, 0x10($v0)
  lwc1  $f6, ($v1)
  lwc1  $f10, 8($v1)
  sub.s $f0, $f4, $f6
  sub.s $f2, $f8, $f10
  mul.s $f16, $f0, $f0
  nop   
  mul.s $f18, $f2, $f2
  jal   sqrtf
   add.s $f12, $f16, $f18
  c.lt.s $f0, $f20
  nop   
  bc1fl .L7F079234
   addiu $s0, $s0, 1
  li    $s1, 1
  addiu $s0, $s0, 1
.L7F079234:
  bne   $s0, $s2, .L7F0791C4
   nop   
.L7F07923C:
  beqz  $s1, .L7F07925C
   sw    $s3, 0x4c($sp)
  lui   $t7, %hi(dword_CODE_bss_80079C68) 
  lw    $t7, %lo(dword_CODE_bss_80079C68)($t7)
  slt   $at, $s7, $t7
  bnezl $at, .L7F079168
   lw    $v0, ($fp)
  sw    $s3, 0x4c($sp)
.L7F07925C:
  lui   $s4, %hi(players_p1)
  lui   $s5, %hi(dword_CODE_bss_80079C28)
  lui   $fp, %hi(pPlayer) 
  addiu $fp, %lo(pPlayer) # addiu $fp, $fp, -0x5f50
  addiu $s5, %lo(dword_CODE_bss_80079C28) # addiu $s5, $s5, -0x63d8
  addiu $s4, %lo(players_p1) # addiu $s4, $s4, -0x6120
  beqz  $s1, .L7F079388
   lw    $s3, 0x4c($sp)
  lui   $t8, %hi(dword_CODE_bss_80079C68) 
  lw    $t8, %lo(dword_CODE_bss_80079C68)($t8)
  slt   $at, $s7, $t8
  beqz  $at, .L7F079388
   li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f20
  nop   
  lw    $v0, ($fp)
.L7F07929C:
  lui   $t3, %hi(dword_CODE_bss_80079C68) 
  addiu $s7, $s7, 1
  lw    $t9, 0x29e0($v0)
  move  $s1, $zero
  move  $s0, $zero
  addiu $t0, $t9, 1
  sw    $t0, 0x29e0($v0)
  lw    $t1, ($fp)
  lw    $t3, %lo(dword_CODE_bss_80079C68)($t3)
  lw    $t2, 0x29e0($t1)
  div   $zero, $t2, $t3
  mfhi  $s3
  bnez  $t3, .L7F0792D8
   nop   
  break 7
.L7F0792D8:
  li    $at, -1
  bne   $t3, $at, .L7F0792F0
   lui   $at, 0x8000
  bne   $t2, $at, .L7F0792F0
   nop   
  break 6
.L7F0792F0:
  blez  $s2, .L7F079370
   nop   
.L7F0792F8:
  beql  $s0, $s6, .L7F079368
   addiu $s0, $s0, 1
  sll   $t4, $s0, 2
  addu  $t5, $s4, $t4
  lw    $t6, ($t5)
  lw    $v0, 0xa8($t6)
  beql  $v0, $zero, .L7F079368
   addiu $s0, $s0, 1
  sll   $t7, $s3, 2
  addu  $t8, $s5, $t7
  lw    $v1, ($t8)
  lwc1  $f4, 8($v0)
  lwc1  $f8, 0x10($v0)
  lwc1  $f6, ($v1)
  lwc1  $f10, 8($v1)
  sub.s $f0, $f4, $f6
  sub.s $f2, $f8, $f10
  mul.s $f16, $f0, $f0
  nop   
  mul.s $f18, $f2, $f2
  jal   sqrtf
   add.s $f12, $f16, $f18
  c.lt.s $f0, $f20
  nop   
  bc1fl .L7F079368
   addiu $s0, $s0, 1
  li    $s1, 1
  addiu $s0, $s0, 1
.L7F079368:
  bne   $s0, $s2, .L7F0792F8
   nop   
.L7F079370:
  beqz  $s1, .L7F079388
   lui   $t9, %hi(dword_CODE_bss_80079C68) 
  lw    $t9, %lo(dword_CODE_bss_80079C68)($t9)
  slt   $at, $s7, $t9
  bnezl $at, .L7F07929C
   lw    $v0, ($fp)
.L7F079388:
  beql  $s1, $zero, .L7F0793B8
   lw    $ra, 0x44($sp)
  jal   get_random_value
   nop   
  lui   $t0, %hi(dword_CODE_bss_80079C68) 
  lw    $t0, %lo(dword_CODE_bss_80079C68)($t0)
  divu  $zero, $v0, $t0
  mfhi  $s3
  bnez  $t0, .L7F0793B4
   nop   
  break 7
.L7F0793B4:
  lw    $ra, 0x44($sp)
.L7F0793B8:
  move  $v0, $s3
  lw    $s3, 0x2c($sp)
  ldc1  $f20, 0x18($sp)
  lw    $s0, 0x20($sp)
  lw    $s1, 0x24($sp)
  lw    $s2, 0x28($sp)
  lw    $s4, 0x30($sp)
  lw    $s5, 0x34($sp)
  lw    $s6, 0x38($sp)
  lw    $s7, 0x3c($sp)
  lw    $fp, 0x40($sp)
  jr    $ra
   addiu $sp, $sp, 0x60
");

#ifdef VERSION_US
asm(R"
glabel init_player_BONDdata
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   getPlayerCount
   nop   
  slti  $at, $v0, 2
  bnez  $at, .L7F07943C
   nop   
  jal   get_cur_playernum
   nop   
  jal   get_player_control_style
   move  $a0, $v0
  lui   $v1, %hi(pPlayer)
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $t6, ($v1)
  jal   get_cur_playernum
   sw    $v0, 0x430($t6)
  jal   get_player_control_style
   move  $a0, $v0
  jal   cur_player_set_control_type
   move  $a0, $v0
.L7F07943C:
  lui   $v1, %hi(pPlayer)
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  mtc1  $zero, $f0
  lw    $t7, ($v1)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f2
  swc1  $f0, 0x38($t7)
  lw    $t8, ($v1)
  li    $a3, 2
  li    $a1, 1
  swc1  $f0, 0x3c($t8)
  lw    $t9, ($v1)
  li    $a2, -1
  li    $at, 0xC0800000 # -4.000000
  swc1  $f0, 0x40($t9)
  lw    $t0, ($v1)
  mtc1  $at, $f4
  li    $at, 0x43B40000 # 360.000000
  swc1  $f0, 0x44($t0)
  lw    $t1, ($v1)
  swc1  $f0, 0x48($t1)
  lw    $t2, ($v1)
  swc1  $f0, 0x4c($t2)
  lw    $t3, ($v1)
  swc1  $f0, 0x50($t3)
  lw    $t4, ($v1)
  swc1  $f0, 0x54($t4)
  lw    $t5, ($v1)
  swc1  $f0, 0x58($t5)
  lw    $t6, ($v1)
  sw    $zero, ($t6)
  lw    $t7, ($v1)
  swc1  $f0, 4($t7)
  lw    $t8, ($v1)
  swc1  $f0, 8($t8)
  lw    $t9, ($v1)
  swc1  $f0, 0xc($t9)
  lw    $t0, ($v1)
  swc1  $f0, 0x10($t0)
  lw    $t1, ($v1)
  swc1  $f0, 0x14($t1)
  lw    $t2, ($v1)
  swc1  $f2, 0x18($t2)
  lw    $t3, ($v1)
  swc1  $f0, 0x1c($t3)
  lw    $t4, ($v1)
  swc1  $f2, 0x20($t4)
  lw    $t5, ($v1)
  swc1  $f0, 0x24($t5)
  lw    $t6, ($v1)
  swc1  $f0, 0x28($t6)
  lw    $t7, ($v1)
  swc1  $f0, 0x2c($t7)
  lw    $t8, ($v1)
  swc1  $f0, 0x30($t8)
  lw    $t9, ($v1)
  sw    $zero, 0x34($t9)
  lw    $t0, ($v1)
  swc1  $f0, 0x3c4($t0)
  lw    $t1, ($v1)
  swc1  $f0, 0x3c8($t1)
  lw    $t2, ($v1)
  swc1  $f2, 0x3cc($t2)
  lw    $t3, ($v1)
  swc1  $f0, 0x84($t3)
  lw    $t4, ($v1)
  swc1  $f0, 0x88($t4)
  lw    $t5, ($v1)
  sw    $zero, 0x8c($t5)
  lw    $t6, ($v1)
  swc1  $f0, 0x90($t6)
  lw    $t7, ($v1)
  sw    $zero, 0x94($t7)
  lw    $t8, ($v1)
  swc1  $f0, 0x98($t8)
  lw    $t9, ($v1)
  swc1  $f0, 0x1274($t9)
  lw    $t0, ($v1)
  swc1  $f0, 0x1278($t0)
  lw    $t1, ($v1)
  swc1  $f0, 0x127c($t1)
  lw    $t2, ($v1)
  sw    $a3, 0x9c($t2)
  lw    $t3, ($v1)
  sw    $a3, 0x29fc($t3)
  lw    $t4, ($v1)
  swc1  $f0, 0xa0($t4)
  lw    $t5, ($v1)
  swc1  $f0, 0xa4($t5)
  lw    $t6, ($v1)
  sw    $a1, 0xac($t6)
  lw    $t7, ($v1)
  sw    $zero, 0xd0($t7)
  lw    $t8, ($v1)
  sw    $zero, 0xd8($t8)
  lw    $t9, ($v1)
  swc1  $f2, 0xdc($t9)
  lw    $t0, ($v1)
  swc1  $f0, 0xe0($t0)
  lw    $t1, ($v1)
  swc1  $f2, 0xe4($t1)
  lw    $t2, ($v1)
  swc1  $f0, 0xe8($t2)
  lw    $t3, ($v1)
  swc1  $f2, 0xec($t3)
  lw    $t4, ($v1)
  swc1  $f0, 0xf0($t4)
  lw    $t5, ($v1)
  sw    $a2, 0xf4($t5)
  lw    $t6, ($v1)
  sw    $a2, 0xf8($t6)
  lw    $t7, ($v1)
  sw    $zero, 0x1c0($t7)
  lw    $t8, ($v1)
  sw    $zero, 0x1c4($t8)
  lw    $t9, ($v1)
  sw    $zero, 0x1c8($t9)
  lw    $t0, ($v1)
  sw    $a1, 0x1cc($t0)
  lw    $t1, ($v1)
  sw    $zero, 0x1d0($t1)
  lw    $t2, ($v1)
  sw    $zero, 0x1a0($t2)
  lw    $t3, ($v1)
  swc1  $f0, 0x19c($t3)
  lw    $t4, ($v1)
  swc1  $f0, 0x14c($t4)
  lw    $t5, ($v1)
  swc1  $f2, 0x150($t5)
  lw    $t6, ($v1)
  swc1  $f0, 0x154($t6)
  lw    $t7, ($v1)
  swc1  $f4, 0x158($t7)
  lw    $a0, ($v1)
  lwc1  $f6, 0x158($a0)
  swc1  $f6, 0x15c($a0)
  lw    $a0, ($v1)
  lwc1  $f12, 0x15c($a0)
  c.lt.s $f12, $f0
  nop   
  bc1fl .L7F07968C
   swc1  $f0, 0x160($a0)
  mtc1  $at, $f8
  nop   
  add.s $f10, $f12, $f8
  swc1  $f10, 0x15c($a0)
  lw    $a0, ($v1)
  swc1  $f0, 0x160($a0)
.L7F07968C:
  lw    $t8, ($v1)
  li    $v0, 255
  li    $at, 0xBF800000 # -1.000000
  swc1  $f2, 0x164($t8)
  lw    $t9, ($v1)
  mtc1  $at, $f12
  li    $at, 0x41700000 # 15.000000
  swc1  $f0, 0x168($t9)
  lw    $t0, ($v1)
  mtc1  $at, $f16
  swc1  $f0, 0x16c($t0)
  lw    $t1, ($v1)
  swc1  $f0, 0x170($t1)
  lw    $t2, ($v1)
  swc1  $f0, 0x174($t2)
  lw    $t3, ($v1)
  swc1  $f0, 0x2a4c($t3)
  lw    $t4, ($v1)
  swc1  $f2, 0x178($t4)
  lw    $t5, ($v1)
  sw    $zero, 0x17c($t5)
  lw    $t6, ($v1)
  swc1  $f0, 0x180($t6)
  lw    $t7, ($v1)
  swc1  $f0, 0x184($t7)
  lw    $t8, ($v1)
  swc1  $f0, 0x188($t8)
  lw    $t9, ($v1)
  sw    $zero, 0x104($t9)
  lw    $t0, ($v1)
  sw    $zero, 0x108($t0)
  lw    $t1, ($v1)
  sw    $zero, 0x10c($t1)
  lw    $t2, ($v1)
  sw    $zero, 0x110($t2)
  lw    $t3, ($v1)
  sw    $a1, 0x114($t3)
  lw    $t4, ($v1)
  sw    $a1, 0x118($t4)
  lw    $t5, ($v1)
  sw    $zero, 0x11c($t5)
  lw    $t6, ($v1)
  sw    $a1, 0x120($t6)
  lw    $t7, ($v1)
  sw    $zero, 0x124($t7)
  lw    $t8, ($v1)
  sw    $a1, 0x128($t8)
  lw    $t9, ($v1)
  swc1  $f0, 0x12c($t9)
  lw    $t0, ($v1)
  sw    $zero, 0x130($t0)
  lw    $t1, ($v1)
  sw    $a2, 0x134($t1)
  lw    $t2, ($v1)
  sw    $a1, 0x138($t2)
  lw    $t3, ($v1)
  swc1  $f0, 0x13c($t3)
  lw    $t4, ($v1)
  sw    $zero, 0x140($t4)
  lw    $t5, ($v1)
  sw    $a2, 0x144($t5)
  lw    $t6, ($v1)
  sw    $v0, 0x3d0($t6)
  lw    $t7, ($v1)
  sw    $v0, 0x3d4($t7)
  lw    $t8, ($v1)
  sw    $v0, 0x3d8($t8)
  lw    $t9, ($v1)
  swc1  $f0, 0x3dc($t9)
  lw    $t0, ($v1)
  swc1  $f12, 0x3e0($t0)
  lw    $t1, ($v1)
  swc1  $f12, 0x3e4($t1)
  lw    $t2, ($v1)
  sw    $v0, 0x3e8($t2)
  lw    $t3, ($v1)
  sw    $v0, 0x3ec($t3)
  lw    $t4, ($v1)
  sw    $v0, 0x3f0($t4)
  lw    $t5, ($v1)
  sw    $v0, 0x3f4($t5)
  lw    $t6, ($v1)
  sw    $v0, 0x3f8($t6)
  lw    $t7, ($v1)
  sw    $v0, 0x3fc($t7)
  lw    $t8, ($v1)
  swc1  $f0, 0x400($t8)
  lw    $t9, ($v1)
  swc1  $f0, 0x404($t9)
  lw    $t0, ($v1)
  swc1  $f12, 0x18c($t0)
  lw    $t1, ($v1)
  swc1  $f12, 0x190($t1)
  lw    $t2, ($v1)
  swc1  $f0, 0x194($t2)
  lw    $t3, ($v1)
  swc1  $f0, 0x198($t3)
  lw    $t4, ($v1)
  sw    $a3, 0x42c($t4)
  lw    $t5, ($v1)
  sw    $zero, 0x430($t5)
  lw    $t6, ($v1)
  swc1  $f0, 0x204($t6)
  lw    $t7, ($v1)
  swc1  $f0, 0x208($t7)
  lw    $t8, ($v1)
  swc1  $f0, 0x20c($t8)
  lw    $t9, ($v1)
  swc1  $f0, 0x210($t9)
  lw    $t0, ($v1)
  swc1  $f0, 0x214($t0)
  lw    $t1, ($v1)
  sw    $zero, 0x218($t1)
  lw    $t2, ($v1)
  sw    $zero, 0x220($t2)
  lw    $t3, ($v1)
  swc1  $f0, 0x224($t3)
  lw    $t4, ($v1)
  sw    $zero, 0x200($t4)
  lw    $t5, ($v1)
  sh    $zero, 0x3b4($t5)
  lw    $t6, ($v1)
  sh    $zero, 0x3b6($t6)
  lw    $t7, ($v1)
  swc1  $f16, 0x29c0($t7)
  lw    $t8, ($v1)
  sh    $a2, 0x2a04($t8)
  lw    $t9, ($v1)
  swc1  $f0, 0x2a08($t9)
  lw    $t0, ($v1)
  swc1  $f0, 0x2a0c($t0)
  lw    $t1, ($v1)
  sw    $zero, 0x2a6c($t1)
  lw    $t2, ($v1)
  sw    $zero, 0x2a70($t2)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");
#endif

#ifdef VERSION_JP
asm(R"
glabel init_player_BONDdata
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   getPlayerCount
   nop   
  slti  $at, $v0, 2
  bnez  $at, .L7F079A2C
   nop   
  jal   get_cur_playernum
   nop   
  jal   get_player_control_style
   move  $a0, $v0
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5ee0
  lw    $t6, ($v1)
  jal   get_cur_playernum
   sw    $v0, 0x430($t6)
  jal   get_player_control_style
   move  $a0, $v0
  jal   cur_player_set_control_type
   move  $a0, $v0
.L7F079A2C:
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5ee0
  mtc1  $zero, $f0
  lw    $t7, ($v1)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f2
  swc1  $f0, 0x38($t7)
  lw    $t8, ($v1)
  li    $a3, 2
  li    $a1, 1
  swc1  $f0, 0x3c($t8)
  lw    $t9, ($v1)
  li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f12
  swc1  $f0, 0x40($t9)
  lw    $t0, ($v1)
  li    $at, 0xC0800000 # -4.000000
  mtc1  $at, $f4
  swc1  $f0, 0x44($t0)
  lw    $t1, ($v1)
  li    $at, 0x43B40000 # 360.000000
  swc1  $f0, 0x48($t1)
  lw    $t2, ($v1)
  swc1  $f0, 0x4c($t2)
  lw    $t3, ($v1)
  swc1  $f0, 0x50($t3)
  lw    $t4, ($v1)
  swc1  $f0, 0x54($t4)
  lw    $t5, ($v1)
  swc1  $f0, 0x58($t5)
  lw    $t6, ($v1)
  sw    $zero, ($t6)
  lw    $t7, ($v1)
  swc1  $f0, 4($t7)
  lw    $t8, ($v1)
  swc1  $f0, 8($t8)
  lw    $t9, ($v1)
  swc1  $f0, 0xc($t9)
  lw    $t0, ($v1)
  swc1  $f0, 0x10($t0)
  lw    $t1, ($v1)
  swc1  $f0, 0x14($t1)
  lw    $t2, ($v1)
  swc1  $f2, 0x18($t2)
  lw    $t3, ($v1)
  swc1  $f0, 0x1c($t3)
  lw    $t4, ($v1)
  swc1  $f2, 0x20($t4)
  lw    $t5, ($v1)
  swc1  $f0, 0x24($t5)
  lw    $t6, ($v1)
  swc1  $f0, 0x28($t6)
  lw    $t7, ($v1)
  swc1  $f0, 0x2c($t7)
  lw    $t8, ($v1)
  swc1  $f0, 0x30($t8)
  lw    $t9, ($v1)
  sw    $zero, 0x34($t9)
  lw    $t0, ($v1)
  swc1  $f0, 0x3c4($t0)
  lw    $t1, ($v1)
  swc1  $f0, 0x3c8($t1)
  lw    $t2, ($v1)
  swc1  $f2, 0x3cc($t2)
  lw    $t3, ($v1)
  swc1  $f0, 0x84($t3)
  lw    $t4, ($v1)
  swc1  $f0, 0x88($t4)
  lw    $t5, ($v1)
  sw    $zero, 0x8c($t5)
  lw    $t6, ($v1)
  swc1  $f0, 0x90($t6)
  lw    $t7, ($v1)
  sw    $zero, 0x94($t7)
  lw    $t8, ($v1)
  swc1  $f0, 0x98($t8)
  lw    $t9, ($v1)
  swc1  $f0, 0x1274($t9)
  lw    $t0, ($v1)
  swc1  $f0, 0x1278($t0)
  lw    $t1, ($v1)
  swc1  $f0, 0x127c($t1)
  lw    $t2, ($v1)
  sw    $a3, 0x9c($t2)
  lw    $t3, ($v1)
  sw    $a3, 0x29fc($t3)
  lw    $t4, ($v1)
  swc1  $f0, 0xa0($t4)
  lw    $t5, ($v1)
  swc1  $f0, 0xa4($t5)
  lw    $t6, ($v1)
  sw    $a1, 0xac($t6)
  lw    $t7, ($v1)
  sw    $zero, 0xd0($t7)
  lw    $t8, ($v1)
  sw    $zero, 0xd8($t8)
  lw    $t9, ($v1)
  swc1  $f2, 0xdc($t9)
  lw    $t0, ($v1)
  swc1  $f0, 0xe0($t0)
  lw    $t1, ($v1)
  swc1  $f2, 0xe4($t1)
  lw    $t2, ($v1)
  swc1  $f0, 0xe8($t2)
  lw    $t3, ($v1)
  swc1  $f2, 0xec($t3)
  lw    $t4, ($v1)
  swc1  $f0, 0xf0($t4)
  lw    $t5, ($v1)
  swc1  $f12, 0xf4($t5)
  lw    $t6, ($v1)
  swc1  $f12, 0xf8($t6)
  lw    $t7, ($v1)
  sw    $zero, 0x1c0($t7)
  lw    $t8, ($v1)
  sw    $zero, 0x1c4($t8)
  lw    $t9, ($v1)
  sw    $zero, 0x1c8($t9)
  lw    $t0, ($v1)
  sw    $a1, 0x1cc($t0)
  lw    $t1, ($v1)
  sw    $zero, 0x1d0($t1)
  lw    $t2, ($v1)
  sw    $zero, 0x1a0($t2)
  lw    $t3, ($v1)
  swc1  $f0, 0x19c($t3)
  lw    $t4, ($v1)
  swc1  $f0, 0x14c($t4)
  lw    $t5, ($v1)
  swc1  $f2, 0x150($t5)
  lw    $t6, ($v1)
  swc1  $f0, 0x154($t6)
  lw    $t7, ($v1)
  swc1  $f4, 0x158($t7)
  lw    $a0, ($v1)
  lwc1  $f6, 0x158($a0)
  swc1  $f6, 0x15c($a0)
  lw    $a0, ($v1)
  lwc1  $f14, 0x15c($a0)
  c.lt.s $f14, $f0
  nop   
  bc1fl .L7F079C80
   swc1  $f0, 0x160($a0)
  mtc1  $at, $f8
  nop   
  add.s $f10, $f14, $f8
  swc1  $f10, 0x15c($a0)
  lw    $a0, ($v1)
  swc1  $f0, 0x160($a0)
.L7F079C80:
  lw    $t8, ($v1)
  li    $a2, -1
  li    $v0, 255
  swc1  $f2, 0x164($t8)
  lw    $t9, ($v1)
  li    $at, 0x41700000 # 15.000000
  mtc1  $at, $f16
  swc1  $f0, 0x168($t9)
  lw    $t0, ($v1)
  swc1  $f0, 0x16c($t0)
  lw    $t1, ($v1)
  swc1  $f0, 0x170($t1)
  lw    $t2, ($v1)
  swc1  $f0, 0x174($t2)
  lw    $t3, ($v1)
  swc1  $f0, 0x2a4c($t3)
  lw    $t4, ($v1)
  swc1  $f2, 0x178($t4)
  lw    $t5, ($v1)
  sw    $zero, 0x17c($t5)
  lw    $t6, ($v1)
  swc1  $f0, 0x180($t6)
  lw    $t7, ($v1)
  swc1  $f0, 0x184($t7)
  lw    $t8, ($v1)
  swc1  $f0, 0x188($t8)
  lw    $t9, ($v1)
  sw    $zero, 0x104($t9)
  lw    $t0, ($v1)
  sw    $zero, 0x108($t0)
  lw    $t1, ($v1)
  sw    $zero, 0x10c($t1)
  lw    $t2, ($v1)
  sw    $zero, 0x110($t2)
  lw    $t3, ($v1)
  sw    $a1, 0x114($t3)
  lw    $t4, ($v1)
  sw    $a1, 0x118($t4)
  lw    $t5, ($v1)
  sw    $zero, 0x11c($t5)
  lw    $t6, ($v1)
  sw    $a1, 0x120($t6)
  lw    $t7, ($v1)
  sw    $zero, 0x124($t7)
  lw    $t8, ($v1)
  sw    $a1, 0x128($t8)
  lw    $t9, ($v1)
  swc1  $f0, 0x12c($t9)
  lw    $t0, ($v1)
  sw    $zero, 0x130($t0)
  lw    $t1, ($v1)
  sw    $a2, 0x134($t1)
  lw    $t2, ($v1)
  sw    $a1, 0x138($t2)
  lw    $t3, ($v1)
  swc1  $f0, 0x13c($t3)
  lw    $t4, ($v1)
  sw    $zero, 0x140($t4)
  lw    $t5, ($v1)
  sw    $a2, 0x144($t5)
  lw    $t6, ($v1)
  sw    $v0, 0x3d0($t6)
  lw    $t7, ($v1)
  sw    $v0, 0x3d4($t7)
  lw    $t8, ($v1)
  sw    $v0, 0x3d8($t8)
  lw    $t9, ($v1)
  swc1  $f0, 0x3dc($t9)
  lw    $t0, ($v1)
  swc1  $f12, 0x3e0($t0)
  lw    $t1, ($v1)
  swc1  $f12, 0x3e4($t1)
  lw    $t2, ($v1)
  sw    $v0, 0x3e8($t2)
  lw    $t3, ($v1)
  sw    $v0, 0x3ec($t3)
  lw    $t4, ($v1)
  sw    $v0, 0x3f0($t4)
  lw    $t5, ($v1)
  sw    $v0, 0x3f4($t5)
  lw    $t6, ($v1)
  sw    $v0, 0x3f8($t6)
  lw    $t7, ($v1)
  sw    $v0, 0x3fc($t7)
  lw    $t8, ($v1)
  swc1  $f0, 0x400($t8)
  lw    $t9, ($v1)
  swc1  $f0, 0x404($t9)
  lw    $t0, ($v1)
  swc1  $f12, 0x18c($t0)
  lw    $t1, ($v1)
  swc1  $f12, 0x190($t1)
  lw    $t2, ($v1)
  swc1  $f0, 0x194($t2)
  lw    $t3, ($v1)
  swc1  $f0, 0x198($t3)
  lw    $t4, ($v1)
  sw    $a3, 0x42c($t4)
  lw    $t5, ($v1)
  sw    $zero, 0x430($t5)
  lw    $t6, ($v1)
  swc1  $f0, 0x204($t6)
  lw    $t7, ($v1)
  swc1  $f0, 0x208($t7)
  lw    $t8, ($v1)
  swc1  $f0, 0x20c($t8)
  lw    $t9, ($v1)
  swc1  $f0, 0x210($t9)
  lw    $t0, ($v1)
  swc1  $f0, 0x214($t0)
  lw    $t1, ($v1)
  sw    $zero, 0x218($t1)
  lw    $t2, ($v1)
  sw    $zero, 0x220($t2)
  lw    $t3, ($v1)
  swc1  $f0, 0x224($t3)
  lw    $t4, ($v1)
  sw    $zero, 0x200($t4)
  lw    $t5, ($v1)
  sh    $zero, 0x3b4($t5)
  lw    $t6, ($v1)
  sh    $zero, 0x3b6($t6)
  lw    $t7, ($v1)
  swc1  $f16, 0x29c0($t7)
  lw    $t8, ($v1)
  sh    $a2, 0x2a04($t8)
  lw    $t9, ($v1)
  swc1  $f0, 0x2a08($t9)
  lw    $t0, ($v1)
  swc1  $f0, 0x2a0c($t0)
  lw    $t1, ($v1)
  sw    $zero, 0x2a6c($t1)
  lw    $t2, ($v1)
  sw    $zero, 0x2a70($t2)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");
#endif

asm(R"
glabel sub_GAME_7F0798B8
  lui   $t6, %hi(pPlayersPerm) 
  lw    $t6, %lo(pPlayersPerm)($t6)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  li    $at, 0x43390000 # 185.000000
  mtc1  $at, $f6
  lwc1  $f4, 0x64($t6)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  mul.s $f8, $f4, $f6
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f18
  lui   $v0, %hi(pPlayer)
  addiu $v0, %lo(pPlayer) # addiu $v0, $v0, -0x5f50
  lw    $t7, ($v0)
  mul.s $f16, $f8, $f10
  sub.s $f4, $f16, $f18
  swc1  $f4, 0x29bc($t7)
  lw    $t8, ($v0)
  jal   get_mission_timer
   sw    $zero, 0x29f8($t8)
  lui   $v1, %hi(pPlayer)
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $t9, ($v1)
  li    $a0, 1
  sw    $v0, 0x29f4($t9)
  lw    $t0, ($v1)
  jal   add_item_to_inventory
   sw    $zero, 0x2a00($t0)
  jal   getPlayerCount
   nop   
  slti  $at, $v0, 2
  bnez  $at, .L7F079978
   li    $a0, 1
  lui   $a1, %hi(starting_left_weapon)
  jal   draw_item_in_hand_has_more_ammo
   lw    $a1, %lo(starting_left_weapon)($a1)
  lui   $a1, %hi(starting_right_weapon)
  lw    $a1, %lo(starting_right_weapon)($a1)
  jal   draw_item_in_hand_has_more_ammo
   move  $a0, $zero
  lui   $t1, %hi(pPlayer) 
  lw    $t1, %lo(pPlayer)($t1)
  lw    $t2, 0xd4($t1)
  bnezl $t2, .L7F07997C
   lw    $ra, 0x14($sp)
  jal   solo_char_load
   nop   
.L7F079978:
  lw    $ra, 0x14($sp)
.L7F07997C:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F079988
  mtc1  $a0, $f4
  li    $at, 0x42960000 # 75.000000
  mtc1  $at, $f8
  cvt.s.w $f6, $f4
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  mul.s $f10, $f6, $f8
  jr    $ra
   swc1  $f10, 0x1274($t6)
");

void change_crouch_position(int position)
{
  pPlayer->crouchposition = pPlayer->crouchposition + position;
  if (pPlayer->crouchposition < 0) {
    pPlayer->crouchposition = 0;
    return;
  }
  if (2 < pPlayer->crouchposition)
    pPlayer->crouchposition = 2;
}

asm(R"
glabel sub_GAME_7F0799F0
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lw    $v1, 0x9c($v0)
  lw    $a0, 0x29fc($v0)
  slt   $at, $v1, $a0
  beqz  $at, .L7F079A14
   move  $a1, $a0
  jr    $ra
   move  $v0, $v1

.L7F079A14:
  jr    $ra
   move  $v0, $a1
");

asm(R"
glabel sub_GAME_7F079A1C
  sll   $t6, $a0, 2
  lui   $v0, %hi(players_p1)
  addu  $v0, $v0, $t6
  lw    $v0, %lo(players_p1)($v0)
  lw    $v1, 0x9c($v0)
  lw    $a1, 0x29fc($v0)
  slt   $at, $v1, $a1
  beqz  $at, .L7F079A48
   move  $a0, $a1
  jr    $ra
   move  $v0, $v1

.L7F079A48:
  jr    $ra
   move  $v0, $a0
");

asm(R"
glabel setptrBONDdata
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  jr    $ra
   sw    $a0, ($t6)
");

asm(R"
glabel sub_GAME_7F079A60
  addiu $sp, $sp, -0x38
  lui   $v1, %hi(pPlayer)
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $v0, ($v1)
  sw    $ra, 0x24($sp)
  sw    $s0, 0x20($sp)
  sw    $a1, 0x3c($sp)
  sw    $a2, 0x40($sp)
  sw    $a3, 0x44($sp)
  lwc1  $f4, ($a0)
  lwc1  $f6, 4($v0)
  move  $s0, $a0
  lw    $t9, 0x44($sp)
  c.eq.s $f4, $f6
  nop   
  bc1fl .L7F079B74
   lw    $v0, 0x48($sp)
  lwc1  $f8, 4($a0)
  lwc1  $f10, 8($v0)
  c.eq.s $f8, $f10
  nop   
  bc1fl .L7F079B74
   lw    $v0, 0x48($sp)
  lwc1  $f16, 8($a0)
  lwc1  $f18, 0xc($v0)
  c.eq.s $f16, $f18
  nop   
  bc1fl .L7F079B74
   lw    $v0, 0x48($sp)
  lwc1  $f4, ($a1)
  lwc1  $f6, 0x10($v0)
  c.eq.s $f4, $f6
  nop   
  bc1fl .L7F079B74
   lw    $v0, 0x48($sp)
  lwc1  $f8, 4($a1)
  lwc1  $f10, 0x14($v0)
  c.eq.s $f8, $f10
  nop   
  bc1fl .L7F079B74
   lw    $v0, 0x48($sp)
  lwc1  $f16, 8($a1)
  lwc1  $f18, 0x18($v0)
  c.eq.s $f16, $f18
  nop   
  bc1fl .L7F079B74
   lw    $v0, 0x48($sp)
  lwc1  $f4, ($a2)
  lwc1  $f6, 0x1c($v0)
  c.eq.s $f4, $f6
  nop   
  bc1fl .L7F079B74
   lw    $v0, 0x48($sp)
  lwc1  $f8, 4($a2)
  lwc1  $f10, 0x20($v0)
  c.eq.s $f8, $f10
  nop   
  bc1fl .L7F079B74
   lw    $v0, 0x48($sp)
  lwc1  $f16, 8($a2)
  lwc1  $f18, 0x24($v0)
  c.eq.s $f16, $f18
  nop   
  bc1fl .L7F079B74
   lw    $v0, 0x48($sp)
  lw    $t8, 0x34($v0)
  bnezl $t8, .L7F079CE0
   lw    $ra, 0x24($sp)
  lw    $v0, 0x48($sp)
.L7F079B74:
  sw    $t9, 0x34($sp)
  lwc1  $f4, 8($s0)
  lw    $a3, ($s0)
  lw    $a2, 8($v0)
  lw    $a1, ($v0)
  addiu $a0, $sp, 0x34
  jal   sub_GAME_7F0B0BE4
   swc1  $f4, 0x10($sp)
  lui   $v1, %hi(pPlayer)
  beqz  $v0, .L7F079BC8
   addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $a0, 0x34($sp)
  lw    $a1, ($s0)
  jal   sub_GAME_7F0B0518
   lw    $a2, 8($s0)
  lui   $v1, %hi(pPlayer)
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $t2, ($v1)
  lw    $t1, 0x34($sp)
  b     .L7F079C2C
   sw    $t1, 0x34($t2)
.L7F079BC8:
  lw    $v0, ($v1)
  addiu $a0, $sp, 0x30
  lw    $t7, 0x34($sp)
  lw    $t0, 0x34($v0)
  beql  $t0, $zero, .L7F079C2C
   sw    $t7, 0x34($v0)
  sw    $t0, 0x30($sp)
  lwc1  $f6, 8($s0)
  lw    $a3, ($s0)
  lw    $a2, 0xc($v0)
  lw    $a1, 4($v0)
  jal   sub_GAME_7F0B0BE4
   swc1  $f6, 0x10($sp)
  lui   $v1, %hi(pPlayer)
  beqz  $v0, .L7F079C18
   addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $t3, 0x30($sp)
  lw    $t4, ($v1)
  b     .L7F079C2C
   sw    $t3, 0x34($t4)
.L7F079C18:
  lw    $t5, 0x34($sp)
  lw    $t6, ($v1)
  b     .L7F079C2C
   sw    $t5, 0x34($t6)
  sw    $t7, 0x34($v0)
.L7F079C2C:
  lwc1  $f8, ($s0)
  lw    $t8, ($v1)
  lw    $a3, 0x3c($sp)
  lw    $t0, 0x40($sp)
  swc1  $f8, 4($t8)
  lw    $t9, ($v1)
  lwc1  $f10, 4($s0)
  swc1  $f10, 8($t9)
  lw    $t1, ($v1)
  lwc1  $f16, 8($s0)
  swc1  $f16, 0xc($t1)
  lw    $t2, ($v1)
  lwc1  $f18, ($a3)
  swc1  $f18, 0x10($t2)
  lw    $t3, ($v1)
  lwc1  $f4, 4($a3)
  swc1  $f4, 0x14($t3)
  lw    $t4, ($v1)
  lwc1  $f6, 8($a3)
  swc1  $f6, 0x18($t4)
  lw    $t5, ($v1)
  lwc1  $f8, ($t0)
  swc1  $f8, 0x1c($t5)
  lw    $t6, ($v1)
  lwc1  $f10, 4($t0)
  swc1  $f10, 0x20($t6)
  lw    $t7, ($v1)
  lwc1  $f16, 8($t0)
  swc1  $f16, 0x24($t7)
  lw    $v0, ($v1)
  lwc1  $f18, 4($v0)
  swc1  $f18, 0x28($v0)
  lw    $v0, ($v1)
  lwc1  $f4, 0xc($v0)
  swc1  $f4, 0x30($v0)
  lw    $v0, ($v1)
  lw    $a0, 0x34($v0)
  lw    $a1, 4($v0)
  jal   sub_GAME_7F0B2970
   lw    $a2, 0xc($v0)
  lui   $v1, %hi(pPlayer)
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $t8, ($v1)
  swc1  $f0, 0x2c($t8)
  lw    $ra, 0x24($sp)
.L7F079CE0:
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   
");

#ifdef VERSION_US
asm(R"
.late_rodata
glabel jpt_bondcuff
.word .L7F079EA4
.word cuff_1_brosnan
.word cuff_2_jungle
.word cuff_3_boiler
.word cuff_4_snowsuit
.word cuff_5_connery
.word cuff_6_moore
.word cuff_7_dalton
.word cuff_8_variable_bond_head

glabel jpt_bondhead
.word .L7F079F84
.word brosnan_tux_head_set
.word jungle_head_set
.word boiler_bond_head_set
.word .L7F079F84
.word connery_head_set
.word moore_head_set
.word dalton_head_set
.word variable_body_head

glabel D_8005502C
.word 0x3f7851ec /*0.97000003*/

.text
glabel solo_char_load
  addiu $sp, $sp, -0x118
  sw    $ra, 0x1c($sp)
  jal   get_curplay_horizontal_rotation_in_degrees
   nop   
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  swc1  $f0, 0x114($sp)
  lw    $t7, 0xa8($t6)
  lw    $v0, 4($t7)
  bnezl $v0, .L7F07A440
   lw    $t7, 0x1c($v0)
  jal   getPlayerWeaponBufferForHand
   move  $a0, $zero
  sw    $v0, 0xf0($sp)
  jal   getPlayerWeaponBufferForHand
   li    $a0, 1
  sw    $v0, 0xec($sp)
  sw    $zero, 0xe8($sp)
  jal   getSizeBufferWeaponInHand
   move  $a0, $zero
  sw    $v0, 0xe4($sp)
  jal   getSizeBufferWeaponInHand
   li    $a0, 1
  lui   $t9, %hi(dummy_08_pp7_obj) 
  addiu $t9, %lo(dummy_08_pp7_obj) # addiu $t9, $t9, 0x65ac
  sw    $v0, 0xe0($sp)
  addiu $t4, $t9, 0x84
  addiu $t8, $sp, 0x54
.L7F079D60:
  lw    $at, ($t9)
  addiu $t9, $t9, 0xc
  addiu $t8, $t8, 0xc
  sw    $at, -0xc($t8)
  lw    $at, -8($t9)
  sw    $at, -8($t8)
  lw    $at, -4($t9)
  bne   $t9, $t4, .L7F079D60
   sw    $at, -4($t8)
  lw    $at, ($t9)
  move  $a0, $zero
  jal   return_ammo_in_hand
   sw    $at, ($t8)
  li    $t5, 23
  li    $t6, 75
  lui   $a0, %hi(pPlayer)
  sw    $v0, 0x48($sp)
  sw    $t5, 0x44($sp)
  sw    $t6, 0x40($sp)
  sw    $zero, 0x38($sp)
  jal   sub_GAME_7F07DE64
   lw    $a0, %lo(pPlayer)($a0)
  jal   getPlayerCount
   nop   
  li    $at, 1
  bne   $v0, $at, .L7F079F60
   nop   
  jal   getSelectedFolderBond
   nop   
  lui   $t7, %hi(pPlayer) 
  lw    $t7, %lo(pPlayer)($t7)
  lw    $v1, 0x41c($t7)
  sltiu $at, $v1, 9
  beqz  $at, .L7F079EA4
   sll   $t3, $v1, 2
  lui   $at, %hi(jpt_bondcuff)
  addu  $at, $at, $t3
  lw    $t3, %lo(jpt_bondcuff)($at)
  jr    $t3
   nop   
cuff_3_boiler:
  li    $t2, 22
  b     .L7F079EA4
   sw    $t2, 0x44($sp)
cuff_2_jungle:
  li    $t4, 24
  b     .L7F079EA4
   sw    $t4, 0x44($sp)
cuff_4_snowsuit:
  li    $t9, 25
  b     .L7F079EA4
   sw    $t9, 0x44($sp)
cuff_1_brosnan:
  li    $t8, 5
  b     .L7F079EA4
   sw    $t8, 0x44($sp)
cuff_5_connery:
  li    $t5, 5
  b     .L7F079EA4
   sw    $t5, 0x44($sp)
cuff_6_moore:
  li    $t6, 5
  b     .L7F079EA4
   sw    $t6, 0x44($sp)
cuff_7_dalton:
  li    $t7, 5
  b     .L7F079EA4
   sw    $t7, 0x44($sp)
cuff_8_variable_bond_head:
  beqz  $v0, .L7F079E88
   li    $t3, 5
  li    $at, 1
  beq   $v0, $at, .L7F079E90
   li    $t2, 5
  li    $at, 2
  beq   $v0, $at, .L7F079E98
   li    $t4, 5
  li    $at, 3
  beq   $v0, $at, .L7F079EA0
   li    $t9, 5
  b     .L7F079EA4
   nop   
.L7F079E88:
  b     .L7F079EA4
   sw    $t3, 0x44($sp)
.L7F079E90:
  b     .L7F079EA4
   sw    $t2, 0x44($sp)
.L7F079E98:
  b     .L7F079EA4
   sw    $t4, 0x44($sp)
.L7F079EA0:
  sw    $t9, 0x44($sp)
.L7F079EA4:
  beqz  $v0, .L7F079ED8
   sltiu $at, $v1, 9
  li    $at, 1
  beq   $v0, $at, .L7F079F48
   li    $t8, 78
  li    $at, 2
  beq   $v0, $at, .L7F079F50
   li    $t5, 78
  li    $at, 3
  beq   $v0, $at, .L7F079F58
   li    $t6, 78
  b     .L7F079F84
   nop   
.L7F079ED8:
  beqz  $at, .L7F079F84
   sll   $t8, $v1, 2
  lui   $at, %hi(jpt_bondhead)
  addu  $at, $at, $t8
  lw    $t8, %lo(jpt_bondhead)($at)
  jr    $t8
   nop   
boiler_bond_head_set:
  li    $t5, 74
  b     .L7F079F84
   sw    $t5, 0x40($sp)
jungle_head_set:
  li    $t6, 76
  b     .L7F079F84
   sw    $t6, 0x40($sp)
brosnan_tux_head_set:
  li    $t7, 78
  b     .L7F079F84
   sw    $t7, 0x40($sp)
connery_head_set:
  li    $t3, 78
  b     .L7F079F84
   sw    $t3, 0x40($sp)
moore_head_set:
  li    $t2, 78
  b     .L7F079F84
   sw    $t2, 0x40($sp)
dalton_head_set:
  li    $t4, 78
  b     .L7F079F84
   sw    $t4, 0x40($sp)
variable_body_head:
  li    $t9, 78
  b     .L7F079F84
   sw    $t9, 0x40($sp)
.L7F079F48:
  b     .L7F079F84
   sw    $t8, 0x40($sp)
.L7F079F50:
  b     .L7F079F84
   sw    $t5, 0x40($sp)
.L7F079F58:
  b     .L7F079F84
   sw    $t6, 0x40($sp)
.L7F079F60:
  jal   get_cur_playernum
   nop   
  jal   get_player_mp_char_head
   move  $a0, $v0
  jal   get_cur_playernum
   sw    $v0, 0x40($sp)
  jal   get_player_mp_char_body
   move  $a0, $v0
  sw    $v0, 0x44($sp)
.L7F079F84:
  lui   $t7, %hi(cameramode) 
  lw    $t7, %lo(cameramode)($t7)
  li    $at, 3
  bne   $t7, $at, .L7F079FA0
   lui   $t3, %hi(starting_right_weapon) 
  lw    $t3, %lo(starting_right_weapon)($t3)
  sw    $t3, 0x48($sp)
.L7F079FA0:
  jal   getPlayerCount
   nop   
  li    $at, 1
  bne   $v0, $at, .L7F07A1BC
   lw    $t7, 0x44($sp)
  jal   remove_item_in_hand
   li    $a0, 1
  jal   remove_item_in_hand
   move  $a0, $zero
  addiu $a0, $sp, 0x100
  lw    $a1, 0xec($sp)
  jal   sub_GAME_7F0CBAF4
   lw    $a2, 0xe0($sp)
  jal   get_ptr_itemheader_in_hand
   move  $a0, $zero
  lw    $t2, 0x44($sp)
  lui   $t9, %hi(c_item_entries) 
  addiu $t9, %lo(c_item_entries) # addiu $t9, $t9, -0x21f0
  sll   $t4, $t2, 2
  addu  $t4, $t4, $t2
  sll   $t4, $t4, 2
  addu  $v1, $t4, $t9
  lw    $t8, ($v1)
  sw    $v0, 0xfc($sp)
  addiu $t3, $sp, 0x100
  lw    $at, ($t8)
  move  $a0, $v0
  sw    $at, ($v0)
  lw    $t7, 4($t8)
  sw    $t7, 4($v0)
  lw    $at, 8($t8)
  sw    $at, 8($v0)
  lw    $t7, 0xc($t8)
  sw    $t7, 0xc($v0)
  lw    $at, 0x10($t8)
  sw    $at, 0x10($v0)
  lw    $t7, 0x14($t8)
  sw    $t7, 0x14($v0)
  lw    $at, 0x18($t8)
  sw    $at, 0x18($v0)
  lw    $t7, 0x1c($t8)
  sw    $t7, 0x1c($v0)
  sw    $v1, 0x28($sp)
  sw    $t3, 0x10($sp)
  lw    $a3, 0xe4($sp)
  lw    $a2, 0xf0($sp)
  jal   load_object_fill_header
   lw    $a1, 4($v1)
  lw    $v1, 0x28($sp)
  jal   get_pc_buffer_remaining_value
   lw    $a0, 4($v1)
  lw    $t5, 0x40($sp)
  lui   $t7, %hi(c_item_entries) 
  addiu $t7, %lo(c_item_entries) # addiu $t7, $t7, -0x21f0
  sll   $t8, $t5, 2
  addu  $t8, $t8, $t5
  sll   $t8, $t8, 2
  addu  $v1, $t8, $t7
  lw    $t3, ($v1)
  addiu $t0, $v0, 0x3f
  lw    $t1, 0xf0($sp)
  ori   $t2, $t0, 0x3f
  lw    $at, ($t3)
  xori  $t4, $t2, 0x3f
  addiu $t0, $t4, 0x5f
  ori   $t9, $t0, 0x3f
  addu  $a0, $t1, $t4
  xori  $t0, $t9, 0x3f
  sw    $at, ($a0)
  lw    $t9, 4($t3)
  addiu $t5, $sp, 0x100
  addu  $a2, $t1, $t0
  sw    $t9, 4($a0)
  lw    $at, 8($t3)
  sw    $at, 8($a0)
  lw    $t9, 0xc($t3)
  sw    $t9, 0xc($a0)
  lw    $at, 0x10($t3)
  sw    $at, 0x10($a0)
  lw    $t9, 0x14($t3)
  sw    $t9, 0x14($a0)
  lw    $at, 0x18($t3)
  sw    $at, 0x18($a0)
  lw    $t9, 0x1c($t3)
  sw    $t9, 0x1c($a0)
  lw    $t6, 0xe4($sp)
  sw    $t0, 0xe8($sp)
  sw    $a0, 0xf8($sp)
  sw    $v1, 0x28($sp)
  sw    $t5, 0x10($sp)
  lw    $a1, 4($v1)
  jal   load_object_fill_header
   subu  $a3, $t6, $t0
  lw    $v1, 0x28($sp)
  jal   get_pc_buffer_remaining_value
   lw    $a0, 4($v1)
  lw    $v1, 0xe8($sp)
  lw    $t4, 0xf0($sp)
  lw    $a0, 0xfc($sp)
  addu  $v1, $v0, $v1
  addiu $v1, $v1, 0x3f
  ori   $t8, $v1, 0x3f
  xori  $t7, $t8, 0x3f
  addiu $v1, $t7, 0xfb
  ori   $t3, $v1, 0x3f
  xori  $t9, $t3, 0x3f
  addu  $t2, $t4, $t7
  sw    $t2, 0x38($sp)
  jal   set_objuse_flag_compute_grp_nums_set_obj_loaded
   sw    $t9, 0xe8($sp)
  jal   set_objuse_flag_compute_grp_nums_set_obj_loaded
   lw    $a0, 0xf8($sp)
  lw    $a1, 0xfc($sp)
  lw    $t7, 0xf8($sp)
  lw    $v1, 0xe8($sp)
  lh    $t8, 0x14($a1)
  lh    $t4, 0x14($t7)
  lw    $t6, 0xf0($sp)
  lw    $a0, 0x38($sp)
  addu  $v0, $t8, $t4
  addiu $v0, $v0, 0xa
  sll   $t2, $v0, 2
  addu  $a2, $t6, $v1
  addu  $v1, $t2, $v1
  addiu $v1, $v1, 0x3f
  ori   $t3, $v1, 0x3f
  xori  $t9, $t3, 0x3f
  sw    $t9, 0xe8($sp)
  jal   sub_GAME_7F075FAC
   sw    $v0, 0x30($sp)
  lw    $v0, 0x30($sp)
  lw    $t6, 0x38($sp)
  sh    $v0, 2($t6)
  b     .L7F07A234
   lw    $a3, 0xf8($sp)
.L7F07A1BC:
  sll   $t8, $t7, 2
  addu  $t8, $t8, $t7
  lui   $t4, %hi(c_item_entries) 
  addiu $t4, %lo(c_item_entries) # addiu $t4, $t4, -0x21f0
  sll   $t8, $t8, 2
  addu  $v1, $t8, $t4
  lw    $t2, ($v1)
  sw    $t2, 0xfc($sp)
  lw    $t9, ($t2)
  move  $a0, $t2
  bnezl $t9, .L7F07A1F8
   lw    $t5, 0x40($sp)
  jal   load_object_into_memory
   lw    $a1, 4($v1)
  lw    $t5, 0x40($sp)
.L7F07A1F8:
  lui   $t7, %hi(c_item_entries) 
  addiu $t7, %lo(c_item_entries) # addiu $t7, $t7, -0x21f0
  sll   $t6, $t5, 2
  addu  $t6, $t6, $t5
  sll   $t6, $t6, 2
  addu  $v1, $t6, $t7
  lw    $a3, ($v1)
  lw    $t8, ($a3)
  move  $a0, $a3
  bnezl $t8, .L7F07A238
   lw    $t4, 0x38($sp)
  lw    $a1, 4($v1)
  jal   load_object_into_memory
   sw    $a3, 0xf8($sp)
  lw    $a3, 0xf8($sp)
.L7F07A234:
  lw    $t4, 0x38($sp)
.L7F07A238:
  lw    $a0, 0x44($sp)
  lw    $a1, 0x40($sp)
  lw    $a2, 0xfc($sp)
  sw    $zero, 0x10($sp)
  jal   maybe_load_models_for_guards
   sw    $t4, 0x14($sp)
  lui   $v1, %hi(pPlayer)
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $t2, ($v1)
  lui   $at, %hi(D_8005502C)
  sw    $v0, 0xd4($t2)
  lw    $t9, ($v1)
  lwc1  $f6, %lo(D_8005502C)($at)
  lw    $a0, 0xd4($t9)
  lwc1  $f4, 0x14($a0)
  mul.s $f8, $f4, $f6
  mfc1  $a1, $f8
  jal   set_obj_instance_controller_scale
   nop   
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  lw    $a3, 0x114($sp)
  lw    $a0, 0xa8($v1)
  lw    $a1, 0xd4($v1)
  lw    $t3, 0x14($a0)
  sw    $zero, 0x14($sp)
  addiu $a2, $a0, 8
  jal   init_GUARDdata_with_set_values
   sw    $t3, 0x10($sp)
  lui   $a3, %hi(pPlayer)
  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
  lw    $t6, ($a3)
  li    $t5, 6
  lw    $t7, 0xa8($t6)
  sb    $t5, ($t7)
  lw    $t8, ($a3)
  lw    $t4, 0xa8($t8)
  lw    $a2, 4($t4)
  lw    $t2, 0x14($a2)
  ori   $t9, $t2, 1
  sw    $t9, 0x14($a2)
  lw    $v1, ($a3)
  lw    $a1, 0xa8($v1)
  lw    $a0, 0xd4($v1)
  sw    $a2, 0x110($sp)
  jal   setsuboffset
   addiu $a1, $a1, 8
  lui   $t3, %hi(pPlayer) 
  lw    $t3, %lo(pPlayer)($t3)
  lw    $a1, 0x114($sp)
  jal   setsubroty
   lw    $a0, 0xd4($t3)
  jal   sub_GAME_7F09B244
   lw    $a0, 0x48($sp)
  bltz  $v0, .L7F07A428
   sw    $v0, 0x4c($sp)
  jal   getPlayerCount
   nop   
  li    $at, 1
  bne   $v0, $at, .L7F07A3FC
   lw    $t6, 0xf0($sp)
  lw    $v0, 0xe8($sp)
  li    $a0, 1
  addu  $t5, $t6, $v0
  addiu $v0, $v0, 0xc7
  ori   $t7, $v0, 0x3f
  xori  $t8, $t7, 0x3f
  sw    $t5, 0xdc($sp)
  jal   get_ptr_itemheader_in_hand
   sw    $t8, 0xe8($sp)
  lw    $t4, 0x4c($sp)
  lui   $t9, %hi(PitemZ_entries) 
  addiu $t9, %lo(PitemZ_entries) # addiu $t9, $t9, -0x5dd8
  sll   $t2, $t4, 2
  subu  $t2, $t2, $t4
  sll   $t2, $t2, 2
  addu  $v1, $t2, $t9
  lw    $t3, ($v1)
  sw    $v0, 0xf4($sp)
  addiu $t5, $sp, 0x100
  lw    $at, ($t3)
  move  $a0, $v0
  sw    $at, ($v0)
  lw    $t7, 4($t3)
  sw    $t7, 4($v0)
  lw    $at, 8($t3)
  sw    $at, 8($v0)
  lw    $t7, 0xc($t3)
  sw    $t7, 0xc($v0)
  lw    $at, 0x10($t3)
  sw    $at, 0x10($v0)
  lw    $t7, 0x14($t3)
  sw    $t7, 0x14($v0)
  lw    $at, 0x18($t3)
  sw    $at, 0x18($v0)
  lw    $t7, 0x1c($t3)
  sw    $t7, 0x1c($v0)
  lw    $t4, 0xe8($sp)
  lw    $t2, 0xe4($sp)
  lw    $t8, 0xf0($sp)
  sw    $v1, 0x28($sp)
  sw    $t5, 0x10($sp)
  lw    $a1, 4($v1)
  subu  $a3, $t2, $t4
  jal   load_object_fill_header
   addu  $a2, $t8, $t4
  lw    $v1, 0x28($sp)
  jal   get_pc_buffer_remaining_value
   lw    $a0, 4($v1)
  jal   set_objuse_flag_compute_grp_nums_set_obj_loaded
   lw    $a0, 0xf4($sp)
  b     .L7F07A408
   lw    $t6, 0xdc($sp)
.L7F07A3FC:
  sw    $zero, 0xdc($sp)
  sw    $zero, 0xf4($sp)
  lw    $t6, 0xdc($sp)
.L7F07A408:
  lw    $t3, 0xf4($sp)
  lw    $a0, 0x110($sp)
  lw    $a1, 0x4c($sp)
  lw    $a2, 0x48($sp)
  move  $a3, $zero
  sw    $t6, 0x10($sp)
  jal   something_with_generating_object
   sw    $t3, 0x14($sp)
.L7F07A428:
  lw    $a0, 0x110($sp)
  jal   sub_GAME_7F023A94
   li    $a1, 0
  b     .L7F07A494
   lw    $ra, 0x1c($sp)
  lw    $t7, 0x1c($v0)
.L7F07A440:
  move  $a0, $v0
  lw    $t8, 0x20($t7)
  bnezl $t8, .L7F07A494
   lw    $ra, 0x1c($sp)
  lw    $t4, 0x14($v0)
  li    $a1, 0
  ori   $t2, $t4, 1
  jal   sub_GAME_7F023A94
   sw    $t2, 0x14($v0)
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  lw    $a1, 0xa8($v1)
  lw    $a0, 0xd4($v1)
  jal   setsuboffset
   addiu $a1, $a1, 8
  lui   $t9, %hi(pPlayer) 
  lw    $t9, %lo(pPlayer)($t9)
  lw    $a1, 0x114($sp)
  jal   setsubroty
   lw    $a0, 0xd4($t9)
  lw    $ra, 0x1c($sp)
.L7F07A494:
  addiu $sp, $sp, 0x118
  jr    $ra
   nop   
");
#endif

#ifdef VERSION_JP
asm(R"
.late_rodata
glabel jpt_bondcuff
.word .Ljp7F07A494
.word cuff_1_brosnan
.word cuff_2_jungle
.word cuff_3_boiler
.word cuff_4_snowsuit
.word cuff_5_connery
.word cuff_6_moore
.word cuff_7_dalton
.word cuff_8_variable_bond_head

glabel jpt_bondhead
.word .Ljp7F07A574
.word brosnan_tux_head_set
.word jungle_head_set
.word boiler_bond_head_set
.word .Ljp7F07A574
.word connery_head_set
.word moore_head_set
.word dalton_head_set
.word variable_body_head

glabel D_8005502C
.word 0x3f7851ec /*0.97000003*/

.text
glabel solo_char_load
  addiu $sp, $sp, -0x118
  sw    $ra, 0x1c($sp)
  jal   get_curplay_horizontal_rotation_in_degrees
   nop   
  lui   $t6, %hi(pPlayer) # $t6, 0x8008
  lw    $t6, %lo(pPlayer)($t6)
  swc1  $f0, 0x114($sp)
  lw    $t7, 0xa8($t6)
  lw    $v0, 4($t7)
  bnezl $v0, .Ljp7F07AA60
   lw    $t9, 0x1c($v0)
  jal   getPlayerWeaponBufferForHand
   move  $a0, $zero
  sw    $v0, 0xf0($sp)
  jal   getPlayerWeaponBufferForHand
   li    $a0, 1
  sw    $v0, 0xec($sp)
  sw    $zero, 0xe8($sp)
  jal   getSizeBufferWeaponInHand
   move  $a0, $zero
  sw    $v0, 0xe4($sp)
  jal   getSizeBufferWeaponInHand
   li    $a0, 1
  lui   $t9, %hi(dummy_08_pp7_obj) # $t9, 0x8003
  addiu $t9, %lo(dummy_08_pp7_obj) # addiu $t9, $t9, 0x65ec
  sw    $v0, 0xe0($sp)
  addiu $t4, $t9, 0x84
  addiu $t8, $sp, 0x54
.Ljp7F07A350:
  lw    $at, ($t9)
  addiu $t9, $t9, 0xc
  addiu $t8, $t8, 0xc
  sw    $at, -0xc($t8)
  lw    $at, -8($t9)
  sw    $at, -8($t8)
  lw    $at, -4($t9)
  bne   $t9, $t4, .Ljp7F07A350
   sw    $at, -4($t8)
  lw    $at, ($t9)
  move  $a0, $zero
  jal   return_ammo_in_hand
   sw    $at, ($t8)
  li    $t5, 23
  li    $t6, 75
  lui   $a0, %hi(pPlayer) # $a0, 0x8008
  sw    $v0, 0x48($sp)
  sw    $t5, 0x44($sp)
  sw    $t6, 0x40($sp)
  sw    $zero, 0x38($sp)
  jal   sub_GAME_7F07DE64
   lw    $a0, %lo(pPlayer)($a0)
  jal   getPlayerCount
   nop   
  li    $at, 1
  bne   $v0, $at, .Ljp7F07A550
   nop   
  jal   getSelectedFolderBond
   nop   
  lui   $t7, %hi(pPlayer) # $t7, 0x8008
  lw    $t7, %lo(pPlayer)($t7)
  lw    $v1, 0x41c($t7)
  sltiu $at, $v1, 9
  beqz  $at, .Ljp7F07A494
   sll   $t3, $v1, 2
  lui   $at, %hi(jpt_bondcuff)
  addu  $at, $at, $t3
  lw    $t3, %lo(jpt_bondcuff)($at)
  jr    $t3
   nop   
cuff_3_boiler:
  li    $t2, 22
  b     .Ljp7F07A494
   sw    $t2, 0x44($sp)
cuff_2_jungle:
  li    $t4, 24
  b     .Ljp7F07A494
   sw    $t4, 0x44($sp)
cuff_4_snowsuit:
  li    $t9, 25
  b     .Ljp7F07A494
   sw    $t9, 0x44($sp)
cuff_1_brosnan:
  li    $t8, 5
  b     .Ljp7F07A494
   sw    $t8, 0x44($sp)
cuff_5_connery:
  li    $t5, 5
  b     .Ljp7F07A494
   sw    $t5, 0x44($sp)
cuff_6_moore:
  li    $t6, 5
  b     .Ljp7F07A494
   sw    $t6, 0x44($sp)
cuff_7_dalton:
  li    $t7, 5
  b     .Ljp7F07A494
   sw    $t7, 0x44($sp)
cuff_8_variable_bond_head:
  beqz  $v0, .Ljp7F07A478
   li    $t3, 5
  li    $at, 1
  beq   $v0, $at, .Ljp7F07A480
   li    $t2, 5
  li    $at, 2
  beq   $v0, $at, .Ljp7F07A488
   li    $t4, 5
  li    $at, 3
  beq   $v0, $at, .Ljp7F07A490
   li    $t9, 5
  b     .Ljp7F07A494
   nop   
.Ljp7F07A478:
  b     .Ljp7F07A494
   sw    $t3, 0x44($sp)
.Ljp7F07A480:
  b     .Ljp7F07A494
   sw    $t2, 0x44($sp)
.Ljp7F07A488:
  b     .Ljp7F07A494
   sw    $t4, 0x44($sp)
.Ljp7F07A490:
  sw    $t9, 0x44($sp)
.Ljp7F07A494:
  beqz  $v0, .Ljp7F07A4C8
   sltiu $at, $v1, 9
  li    $at, 1
  beq   $v0, $at, .Ljp7F07A538
   li    $t8, 78
  li    $at, 2
  beq   $v0, $at, .Ljp7F07A540
   li    $t5, 78
  li    $at, 3
  beq   $v0, $at, .Ljp7F07A548
   li    $t6, 78
  b     .Ljp7F07A574
   nop   
.Ljp7F07A4C8:
  beqz  $at, .Ljp7F07A574
   sll   $t8, $v1, 2
  lui   $at, %hi(jpt_bondhead)
  addu  $at, $at, $t8
  lw    $t8, %lo(jpt_bondhead)($at)
  jr    $t8
   nop   
boiler_bond_head_set:
  li    $t5, 74
  b     .Ljp7F07A574
   sw    $t5, 0x40($sp)
jungle_head_set:
  li    $t6, 76
  b     .Ljp7F07A574
   sw    $t6, 0x40($sp)
brosnan_tux_head_set:
  li    $t7, 78
  b     .Ljp7F07A574
   sw    $t7, 0x40($sp)
connery_head_set:
  li    $t3, 78
  b     .Ljp7F07A574
   sw    $t3, 0x40($sp)
moore_head_set:
  li    $t2, 78
  b     .Ljp7F07A574
   sw    $t2, 0x40($sp)
dalton_head_set:
  li    $t4, 78
  b     .Ljp7F07A574
   sw    $t4, 0x40($sp)
variable_body_head:
  li    $t9, 78
  b     .Ljp7F07A574
   sw    $t9, 0x40($sp)
.Ljp7F07A538:
  b     .Ljp7F07A574
   sw    $t8, 0x40($sp)
.Ljp7F07A540:
  b     .Ljp7F07A574
   sw    $t5, 0x40($sp)
.Ljp7F07A548:
  b     .Ljp7F07A574
   sw    $t6, 0x40($sp)
.Ljp7F07A550:
  jal   get_cur_playernum
   nop   
  jal   get_player_mp_char_head
   move  $a0, $v0
  jal   get_cur_playernum
   sw    $v0, 0x40($sp)
  jal   get_player_mp_char_body
   move  $a0, $v0
  sw    $v0, 0x44($sp)
.Ljp7F07A574:
  lui   $t7, %hi(cameramode) # $t7, 0x8003
  lw    $t7, %lo(cameramode)($t7)
  li    $at, 3
  bne   $t7, $at, .Ljp7F07A590
   lui   $t3, %hi(starting_right_weapon) # $t3, 0x8008
  lw    $t3, %lo(starting_right_weapon)($t3)
  sw    $t3, 0x48($sp)
.Ljp7F07A590:
  jal   getPlayerCount
   nop   
  li    $at, 1
  bne   $v0, $at, .Ljp7F07A7A8
   lw    $t7, 0x44($sp)
  jal   remove_item_in_hand
   li    $a0, 1
  jal   remove_item_in_hand
   move  $a0, $zero
  addiu $a0, $sp, 0x100
  lw    $a1, 0xec($sp)
  jal   sub_GAME_7F0CBAF4
   lw    $a2, 0xe0($sp)
  jal   get_ptr_itemheader_in_hand
   move  $a0, $zero
  lw    $t2, 0x44($sp)
  lui   $t9, %hi(c_item_entries) # $t9, 0x8004
  addiu $t9, %lo(c_item_entries) # addiu $t9, $t9, -0x21c0
  sll   $t4, $t2, 2
  addu  $t4, $t4, $t2
  sll   $t4, $t4, 2
  addu  $v1, $t4, $t9
  lw    $t8, ($v1)
  sw    $v0, 0xfc($sp)
  addiu $t3, $sp, 0x100
  lw    $at, ($t8)
  move  $a0, $v0
  sw    $at, ($v0)
  lw    $t7, 4($t8)
  sw    $t7, 4($v0)
  lw    $at, 8($t8)
  sw    $at, 8($v0)
  lw    $t7, 0xc($t8)
  sw    $t7, 0xc($v0)
  lw    $at, 0x10($t8)
  sw    $at, 0x10($v0)
  lw    $t7, 0x14($t8)
  sw    $t7, 0x14($v0)
  lw    $at, 0x18($t8)
  sw    $at, 0x18($v0)
  lw    $t7, 0x1c($t8)
  sw    $t7, 0x1c($v0)
  sw    $v1, 0x28($sp)
  sw    $t3, 0x10($sp)
  lw    $a3, 0xe4($sp)
  lw    $a2, 0xf0($sp)
  jal   load_object_fill_header
   lw    $a1, 4($v1)
  lw    $v1, 0x28($sp)
  jal   get_pc_buffer_remaining_value
   lw    $a0, 4($v1)
  lw    $t5, 0x40($sp)
  lui   $t7, %hi(c_item_entries) # $t7, 0x8004
  addiu $t7, %lo(c_item_entries) # addiu $t7, $t7, -0x21c0
  sll   $t8, $t5, 2
  addu  $t8, $t8, $t5
  sll   $t8, $t8, 2
  addu  $v1, $t8, $t7
  lw    $t3, ($v1)
  addiu $t0, $v0, 0x3f
  lw    $t1, 0xf0($sp)
  ori   $t2, $t0, 0x3f
  lw    $at, ($t3)
  xori  $t4, $t2, 0x3f
  addiu $t0, $t4, 0x5f
  ori   $t9, $t0, 0x3f
  addu  $a0, $t1, $t4
  xori  $t0, $t9, 0x3f
  sw    $at, ($a0)
  lw    $t9, 4($t3)
  addiu $t5, $sp, 0x100
  addu  $a2, $t1, $t0
  sw    $t9, 4($a0)
  lw    $at, 8($t3)
  sw    $at, 8($a0)
  lw    $t9, 0xc($t3)
  sw    $t9, 0xc($a0)
  lw    $at, 0x10($t3)
  sw    $at, 0x10($a0)
  lw    $t9, 0x14($t3)
  sw    $t9, 0x14($a0)
  lw    $at, 0x18($t3)
  sw    $at, 0x18($a0)
  lw    $t9, 0x1c($t3)
  sw    $t9, 0x1c($a0)
  lw    $t6, 0xe4($sp)
  sw    $t0, 0xe8($sp)
  sw    $a0, 0xf8($sp)
  sw    $v1, 0x28($sp)
  sw    $t5, 0x10($sp)
  lw    $a1, 4($v1)
  jal   load_object_fill_header
   subu  $a3, $t6, $t0
  lw    $v1, 0x28($sp)
  jal   get_pc_buffer_remaining_value
   lw    $a0, 4($v1)
  lw    $v1, 0xe8($sp)
  lw    $t4, 0xf0($sp)
  lw    $a0, 0xfc($sp)
  addu  $v1, $v0, $v1
  addiu $v1, $v1, 0x3f
  ori   $t8, $v1, 0x3f
  xori  $t7, $t8, 0x3f
  addiu $v1, $t7, 0xfb
  ori   $t3, $v1, 0x3f
  xori  $t9, $t3, 0x3f
  addu  $t2, $t4, $t7
  sw    $t2, 0x38($sp)
  jal   set_objuse_flag_compute_grp_nums_set_obj_loaded
   sw    $t9, 0xe8($sp)
  jal   set_objuse_flag_compute_grp_nums_set_obj_loaded
   lw    $a0, 0xf8($sp)
  lw    $a1, 0xfc($sp)
  lw    $t7, 0xf8($sp)
  lw    $v1, 0xe8($sp)
  lh    $t8, 0x14($a1)
  lh    $t4, 0x14($t7)
  lw    $t6, 0xf0($sp)
  lw    $a0, 0x38($sp)
  addu  $v0, $t8, $t4
  addiu $v0, $v0, 0xa
  sll   $t2, $v0, 2
  addu  $a2, $t6, $v1
  addu  $v1, $t2, $v1
  addiu $v1, $v1, 0x3f
  ori   $t3, $v1, 0x3f
  xori  $t9, $t3, 0x3f
  sw    $t9, 0xe8($sp)
  jal   sub_GAME_7F075FAC
   sw    $v0, 0x30($sp)
  lw    $v0, 0x30($sp)
  lw    $t6, 0x38($sp)
  b     .Ljp7F07A83C
   sh    $v0, 2($t6)
.Ljp7F07A7A8:
  sll   $t8, $t7, 2
  addu  $t8, $t8, $t7
  lui   $t4, %hi(c_item_entries) # $t4, 0x8004
  addiu $t4, %lo(c_item_entries) # addiu $t4, $t4, -0x21c0
  sll   $t8, $t8, 2
  addu  $v1, $t8, $t4
  lw    $t2, ($v1)
  sw    $t2, 0xfc($sp)
  lw    $t9, ($t2)
  move  $a0, $t2
  bnezl $t9, .Ljp7F07A7EC
   lbu   $t5, 0x11($v1)
  lw    $a1, 4($v1)
  jal   load_object_into_memory
   sw    $v1, 0x28($sp)
  lw    $v1, 0x28($sp)
  lbu   $t5, 0x11($v1)
.Ljp7F07A7EC:
  lw    $t7, 0x40($sp)
  lui   $t4, %hi(c_item_entries) # $t4, 0x8004
  beqz  $t5, .Ljp7F07A80C
   sll   $t8, $t7, 2
  li    $t6, -1
  sw    $t6, 0x40($sp)
  b     .Ljp7F07A83C
   sw    $zero, 0xf8($sp)
.Ljp7F07A80C:
  addu  $t8, $t8, $t7
  sll   $t8, $t8, 2
  addiu $t4, %lo(c_item_entries) # addiu $t4, $t4, -0x21c0
  addu  $v1, $t8, $t4
  lw    $a0, ($v1)
  sw    $a0, 0xf8($sp)
  lw    $t2, ($a0)
  bnezl $t2, .Ljp7F07A840
   lw    $t9, 0x38($sp)
  lw    $a1, 4($v1)
  jal   load_object_into_memory
   sw    $a0, 0xf8($sp)
.Ljp7F07A83C:
  lw    $t9, 0x38($sp)
.Ljp7F07A840:
  lw    $a0, 0x44($sp)
  lw    $a1, 0x40($sp)
  lw    $a2, 0xfc($sp)
  lw    $a3, 0xf8($sp)
  sw    $zero, 0x10($sp)
  jal   maybe_load_models_for_guards
   sw    $t9, 0x14($sp)
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5ee0
  lw    $t3, ($v1)
  lui   $at, %hi(D_8005502C) # $at, 0x8005
  sw    $v0, 0xd4($t3)
  lw    $t5, ($v1)
  lwc1  $f6, %lo(D_8005502C)($at)
  lw    $a0, 0xd4($t5)
  lwc1  $f4, 0x14($a0)
  mul.s $f8, $f4, $f6
  mfc1  $a1, $f8
  jal   set_obj_instance_controller_scale
   nop   
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  lw    $v1, %lo(pPlayer)($v1)
  lw    $a3, 0x114($sp)
  lw    $a0, 0xa8($v1)
  lw    $a1, 0xd4($v1)
  lw    $t6, 0x14($a0)
  sw    $zero, 0x14($sp)
  addiu $a2, $a0, 8
  jal   init_GUARDdata_with_set_values
   sw    $t6, 0x10($sp)
  lui   $a3, %hi(pPlayer) # $a3, 0x8008
  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5ee0
  lw    $t8, ($a3)
  li    $t7, 6
  lw    $t4, 0xa8($t8)
  sb    $t7, ($t4)
  lw    $t2, ($a3)
  lw    $t9, 0xa8($t2)
  lw    $a2, 4($t9)
  lw    $t3, 0x14($a2)
  ori   $t5, $t3, 1
  sw    $t5, 0x14($a2)
  lw    $v1, ($a3)
  lw    $a1, 0xa8($v1)
  lw    $a0, 0xd4($v1)
  sw    $a2, 0x110($sp)
  jal   setsuboffset
   addiu $a1, $a1, 8
  lui   $t6, %hi(pPlayer) # $t6, 0x8008
  lw    $t6, %lo(pPlayer)($t6)
  lw    $a1, 0x114($sp)
  jal   setsubroty
   lw    $a0, 0xd4($t6)
  lw    $v0, 0x110($sp)
  lw    $t8, 0x40($sp)
  sb    $t8, 6($v0)
  lw    $t7, 0x44($sp)
  sb    $t7, 0xf($v0)
  jal   sub_GAME_7F09B244
   lw    $a0, 0x48($sp)
  bltz  $v0, .Ljp7F07AA48
   sw    $v0, 0x4c($sp)
  jal   getPlayerCount
   nop   
  li    $at, 1
  bne   $v0, $at, .Ljp7F07AA1C
   lw    $t4, 0xf0($sp)
  lw    $v0, 0xe8($sp)
  li    $a0, 1
  addu  $t2, $t4, $v0
  addiu $v0, $v0, 0xc7
  ori   $t9, $v0, 0x3f
  xori  $t3, $t9, 0x3f
  sw    $t2, 0xdc($sp)
  jal   get_ptr_itemheader_in_hand
   sw    $t3, 0xe8($sp)
  lw    $t5, 0x4c($sp)
  lui   $t8, %hi(PitemZ_entries) # $t8, 0x8004
  addiu $t8, %lo(PitemZ_entries) # addiu $t8, $t8, -0x5da8
  sll   $t6, $t5, 2
  subu  $t6, $t6, $t5
  sll   $t6, $t6, 2
  addu  $v1, $t6, $t8
  lw    $t7, ($v1)
  sw    $v0, 0xf4($sp)
  addiu $t2, $sp, 0x100
  lw    $at, ($t7)
  move  $a0, $v0
  sw    $at, ($v0)
  lw    $t9, 4($t7)
  sw    $t9, 4($v0)
  lw    $at, 8($t7)
  sw    $at, 8($v0)
  lw    $t9, 0xc($t7)
  sw    $t9, 0xc($v0)
  lw    $at, 0x10($t7)
  sw    $at, 0x10($v0)
  lw    $t9, 0x14($t7)
  sw    $t9, 0x14($v0)
  lw    $at, 0x18($t7)
  sw    $at, 0x18($v0)
  lw    $t9, 0x1c($t7)
  sw    $t9, 0x1c($v0)
  lw    $t5, 0xe8($sp)
  lw    $t6, 0xe4($sp)
  lw    $t3, 0xf0($sp)
  sw    $v1, 0x28($sp)
  sw    $t2, 0x10($sp)
  lw    $a1, 4($v1)
  subu  $a3, $t6, $t5
  jal   load_object_fill_header
   addu  $a2, $t3, $t5
  lw    $v1, 0x28($sp)
  jal   get_pc_buffer_remaining_value
   lw    $a0, 4($v1)
  jal   set_objuse_flag_compute_grp_nums_set_obj_loaded
   lw    $a0, 0xf4($sp)
  b     .Ljp7F07AA28
   lw    $t4, 0xdc($sp)
.Ljp7F07AA1C:
  sw    $zero, 0xdc($sp)
  sw    $zero, 0xf4($sp)
  lw    $t4, 0xdc($sp)
.Ljp7F07AA28:
  lw    $t7, 0xf4($sp)
  lw    $a0, 0x110($sp)
  lw    $a1, 0x4c($sp)
  lw    $a2, 0x48($sp)
  move  $a3, $zero
  sw    $t4, 0x10($sp)
  jal   something_with_generating_object
   sw    $t7, 0x14($sp)
.Ljp7F07AA48:
  lw    $a0, 0x110($sp)
  jal   sub_GAME_7F023A94
   li    $a1, 0
  b     .Ljp7F07AAB4
   lw    $ra, 0x1c($sp)
  lw    $t9, 0x1c($v0)
.Ljp7F07AA60:
  move  $a0, $v0
  lw    $t3, 0x20($t9)
  bnezl $t3, .Ljp7F07AAB4
   lw    $ra, 0x1c($sp)
  lw    $t5, 0x14($v0)
  li    $a1, 0
  ori   $t6, $t5, 1
  jal   sub_GAME_7F023A94
   sw    $t6, 0x14($v0)
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  lw    $v1, %lo(pPlayer)($v1)
  lw    $a1, 0xa8($v1)
  lw    $a0, 0xd4($v1)
  jal   setsuboffset
   addiu $a1, $a1, 8
  lui   $t8, %hi(pPlayer) # $t8, 0x8008
  lw    $t8, %lo(pPlayer)($t8)
  lw    $a1, 0x114($sp)
  jal   setsubroty
   lw    $a0, 0xd4($t8)
  lw    $ra, 0x1c($sp)
.Ljp7F07AAB4:
  addiu $sp, $sp, 0x118
  jr    $ra
   nop    
");
#endif

asm(R"
glabel maybe_solo_intro_camera_handler
  lui   $v1, %hi(pPlayer)
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $t6, ($v1)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lw    $t7, 0xa8($t6)
  lw    $t8, 4($t7)
  beql  $t8, $zero, .L7F07A51C
   lw    $ra, 0x14($sp)
  jal   getPlayerCount
   nop   
  lui   $v1, %hi(pPlayer)
  li    $at, 1
  bne   $v0, $at, .L7F07A518
   addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $t9, ($v1)
  jal   disable_sounds_attached_to_player_then_something
   lw    $a0, 0xa8($t9)
  lui   $v1, %hi(pPlayer)
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $t0, ($v1)
  li    $t3, 1
  lui   $at, %hi(camera_80036424)
  lw    $t1, 0xa8($t0)
  sw    $zero, 4($t1)
  lw    $t2, ($v1)
  sw    $zero, 0xd4($t2)
  sw    $t3, %lo(camera_80036424)($at)
  jal   sub_GAME_7F07DE9C
   lw    $a0, ($v1)
.L7F07A518:
  lw    $ra, 0x14($sp)
.L7F07A51C:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

int get_camera_mode(void) {
  return cameramode;
}

asm(R"
.late_rodata
glabel D_80055030
.word 0x40c90fdb /*6.2831855*/
glabel D_80055034
.word 0x44bb8000 /*1500.0*/
glabel D_80055038
.word 0x40c90fdb /*6.2831855*/
glabel D_8005503C
.word 0x3ec90fdb /*0.39269909*/
glabel D_80055040
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F07A534
  addiu $sp, $sp, -0xe0
  lui   $at, %hi(dword_CODE_bss_800799F4)
  sw    $a0, %lo(dword_CODE_bss_800799F4)($at)
  sdc1  $f30, 0x58($sp)
  li    $at, 0x3F800000 # 1.000000
  sw    $s1, 0x64($sp)
  sdc1  $f26, 0x48($sp)
  mtc1  $at, $f30
  sw    $s7, 0x7c($sp)
  sw    $s6, 0x78($sp)
  sw    $s5, 0x74($sp)
  sw    $s4, 0x70($sp)
  sw    $s3, 0x6c($sp)
  sw    $s2, 0x68($sp)
  sdc1  $f20, 0x30($sp)
  lui   $at, %hi(D_80055030)
  lui   $s1, %hi(flt_CODE_bss_800799E8)
  mtc1  $zero, $f26
  move  $s2, $a1
  move  $s3, $a3
  move  $s4, $a2
  sw    $ra, 0x84($sp)
  sw    $fp, 0x80($sp)
  sw    $s0, 0x60($sp)
  sdc1  $f28, 0x50($sp)
  sdc1  $f24, 0x40($sp)
  sdc1  $f22, 0x38($sp)
  move  $s6, $zero
  sw    $zero, 0xd8($sp)
  addiu $s1, %lo(flt_CODE_bss_800799E8) # addiu $s1, $s1, -0x6618
  lwc1  $f20, %lo(D_80055030)($at)
  addiu $s5, $sp, 0xc8
  lw    $s7, 0xf0($sp)
.L7F07A5B8:
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  lui   $at, %hi(D_80055034)
  lwc1  $f4, %lo(D_80055034)($at)
  lwc1  $f28, 0x4b0($t6)
  move  $fp, $zero
  add.s $f6, $f4, $f28
  jal   get_random_value
   swc1  $f6, 0xd0($sp)
  mtc1  $v0, $f8
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F07A5F8
   cvt.s.w $f10, $f8
  mtc1  $at, $f16
  nop   
  add.s $f10, $f10, $f16
.L7F07A5F8:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f18
  nop   
  mul.s $f4, $f10, $f18
  nop   
  mul.s $f12, $f4, $f20
  bnez  $s6, .L7F07A948
   nop   
  swc1  $f12, 0xcc($sp)
.L7F07A61C:
  lui   $at, %hi(D_80055038)
  lwc1  $f20, %lo(D_80055038)($at)
  lui   $at, %hi(D_8005503C)
  lwc1  $f12, 0xcc($sp)
  lwc1  $f6, %lo(D_8005503C)($at)
  add.s $f12, $f12, $f6
  c.le.s $f20, $f12
  nop   
  bc1f  .L7F07A648
   nop   
  sub.s $f12, $f12, $f20
.L7F07A648:
  jal   sinf
   swc1  $f12, 0xcc($sp)
  swc1  $f0, 0xbc($sp)
  swc1  $f26, 0xc0($sp)
  jal   cosf
   lwc1  $f12, 0xcc($sp)
  lwc1  $f8, 0xbc($sp)
  lwc1  $f16, 0xd0($sp)
  swc1  $f0, 0xc4($sp)
  lwc1  $f18, ($s2)
  mul.s $f10, $f8, $f16
  lwc1  $f8, 0xc4($sp)
  add.s $f4, $f10, $f18
  mul.s $f10, $f8, $f16
  swc1  $f4, 0xb0($sp)
  lwc1  $f6, 4($s2)
  swc1  $f6, 0xb4($sp)
  lwc1  $f18, 8($s2)
  add.s $f4, $f10, $f18
  jal   sub_GAME_7F0B1CC4
   swc1  $f4, 0xb8($sp)
  sw    $s7, 0xc8($sp)
  move  $a0, $s4
  jal   sub_GAME_7F03D058
   move  $a1, $zero
  lw    $a1, ($s3)
  lw    $a2, 8($s3)
  lwc1  $f6, 0xb8($sp)
  li    $t7, 19
  sw    $t7, 0x14($sp)
  swc1  $f30, 0x24($sp)
  swc1  $f26, 0x20($sp)
  swc1  $f30, 0x1c($sp)
  swc1  $f26, 0x18($sp)
  move  $a0, $s5
  lw    $a3, 0xb0($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f6, 0x10($sp)
  move  $s0, $v0
  move  $a0, $s4
  jal   sub_GAME_7F03D058
   li    $a1, 1
  bnez  $s0, .L7F07A734
   move  $a0, $s3
  addiu $a1, $sp, 0xbc
  jal   sub_GAME_7F026298
   addiu $a2, $sp, 0xb0
  lwc1  $f8, 0xb0($sp)
  lwc1  $f16, ($s3)
  lwc1  $f10, 0xb8($sp)
  lwc1  $f18, 8($s3)
  sub.s $f0, $f8, $f16
  sub.s $f2, $f10, $f18
  mul.s $f4, $f0, $f0
  nop   
  mul.s $f6, $f2, $f2
  jal   sqrtf
   add.s $f12, $f4, $f6
  swc1  $f0, 0xd0($sp)
.L7F07A734:
  lwc1  $f8, 0xd0($sp)
  lwc1  $f10, 0xf4($sp)
  sub.s $f16, $f8, $f28
  c.le.s $f10, $f16
  swc1  $f16, 0xd0($sp)
  bc1fl .L7F07A934
   addiu $fp, $fp, 1
  c.lt.s $f26, $f30
  mov.s $f24, $f30
  bc1fl .L7F07A934
   addiu $fp, $fp, 1
  bnezl $s6, .L7F07A934
   addiu $fp, $fp, 1
  sub.s $f18, $f16, $f10
  swc1  $f18, 0x90($sp)
.L7F07A770:
  jal   get_random_value
   nop   
  mtc1  $v0, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F07A794
   cvt.s.w $f6, $f4
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F07A794:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f16
  lwc1  $f18, 0x90($sp)
  move  $a0, $s4
  mul.s $f10, $f6, $f16
  lwc1  $f6, 0xf4($sp)
  lwc1  $f16, 0xbc($sp)
  move  $a1, $zero
  mul.s $f4, $f10, $f18
  lwc1  $f18, ($s2)
  mul.s $f8, $f4, $f24
  add.s $f0, $f8, $f6
  lwc1  $f6, 0xc4($sp)
  mul.s $f10, $f16, $f0
  add.s $f4, $f10, $f18
  mul.s $f16, $f6, $f0
  swc1  $f4, ($s1)
  lwc1  $f8, 4($s2)
  swc1  $f8, 4($s1)
  lwc1  $f10, 8($s2)
  sw    $s7, 0xc8($sp)
  add.s $f18, $f16, $f10
  jal   sub_GAME_7F03D058
   swc1  $f18, 8($s1)
  lw    $a1, ($s3)
  lw    $a2, 8($s3)
  lwc1  $f4, 8($s1)
  li    $t8, 19
  sw    $t8, 0x14($sp)
  swc1  $f30, 0x24($sp)
  swc1  $f26, 0x20($sp)
  swc1  $f30, 0x1c($sp)
  swc1  $f26, 0x18($sp)
  move  $a0, $s5
  lw    $a3, ($s1)
  jal   sub_GAME_7F0B0E24
   swc1  $f4, 0x10($sp)
  move  $s0, $v0
  move  $a0, $s4
  jal   sub_GAME_7F03D058
   li    $a1, 1
  beqz  $s0, .L7F07A908
   move  $a0, $s5
  mfc1  $a3, $f28
  li    $t9, 31
  sw    $t9, 0x10($sp)
  lw    $a1, ($s1)
  lw    $a2, 8($s1)
  swc1  $f26, 0x14($sp)
  jal   sub_GAME_7F0B18B8
   swc1  $f30, 0x18($sp)
  bgez  $v0, .L7F07A908
   lw    $a0, 0xc8($sp)
  li    $at, 0x43390000 # 185.000000
  mtc1  $at, $f8
  lw    $a1, ($s1)
  lw    $a2, 8($s1)
  jal   sub_GAME_7F0B2970
   sub.s $f22, $f8, $f28
  jal   get_random_value
   mov.s $f20, $f0
  mtc1  $v0, $f6
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F07A8A4
   cvt.s.w $f16, $f6
  mtc1  $at, $f10
  nop   
  add.s $f16, $f16, $f10
.L7F07A8A4:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f18
  add.s $f6, $f20, $f28
  li    $at, 0xC47A0000 # -1000.000000
  mul.s $f4, $f16, $f18
  nop   
  mul.s $f8, $f4, $f22
  mtc1  $at, $f4
  li    $at, 0x447A0000 # 1000.000000
  add.s $f10, $f8, $f6
  swc1  $f10, 4($s1)
  lwc1  $f18, 4($s2)
  lwc1  $f16, 4($s1)
  sub.s $f0, $f16, $f18
  c.lt.s $f4, $f0
  nop   
  bc1f  .L7F07A908
   nop   
  mtc1  $at, $f8
  nop   
  c.lt.s $f0, $f8
  nop   
  bc1fl .L7F07A90C
   lui   $at, 0x3e80
  li    $s6, 1
.L7F07A908:
  li    $at, 0x3E800000 # 0.250000
.L7F07A90C:
  mtc1  $at, $f6
  nop   
  sub.s $f24, $f24, $f6
  c.lt.s $f26, $f24
  nop   
  bc1fl .L7F07A934
   addiu $fp, $fp, 1
  beqz  $s6, .L7F07A770
   nop   
  addiu $fp, $fp, 1
.L7F07A934:
  slti  $at, $fp, 0x10
  beql  $at, $zero, .L7F07A94C
   lw    $v0, 0xd8($sp)
  beqz  $s6, .L7F07A61C
   nop   
.L7F07A948:
  lw    $v0, 0xd8($sp)
.L7F07A94C:
  lui   $at, %hi(D_80055040)
  lwc1  $f20, %lo(D_80055040)($at)
  addiu $v0, $v0, 1
  slti  $at, $v0, 0x81
  beql  $at, $zero, .L7F07A970
   lw    $ra, 0x84($sp)
  beqz  $s6, .L7F07A5B8
   sw    $v0, 0xd8($sp)
  lw    $ra, 0x84($sp)
.L7F07A970:
  move  $v0, $s6
  lw    $s6, 0x78($sp)
  ldc1  $f20, 0x30($sp)
  ldc1  $f22, 0x38($sp)
  ldc1  $f24, 0x40($sp)
  ldc1  $f26, 0x48($sp)
  ldc1  $f28, 0x50($sp)
  ldc1  $f30, 0x58($sp)
  lw    $s0, 0x60($sp)
  lw    $s1, 0x64($sp)
  lw    $s2, 0x68($sp)
  lw    $s3, 0x6c($sp)
  lw    $s4, 0x70($sp)
  lw    $s5, 0x74($sp)
  lw    $s7, 0x7c($sp)
  lw    $fp, 0x80($sp)
  jr    $ra
   addiu $sp, $sp, 0xe0
");

asm(R"
glabel set_camera_mode
  addiu $sp, $sp, -0x88
  sw    $s0, 0x28($sp)
  lui   $s0, %hi(cameramode)
  addiu $s0, %lo(cameramode) # addiu $s0, $s0, 0x6494
  sw    $a0, ($s0)
  lui   $at, %hi(enable_move_after_cinema)
  sw    $zero, %lo(enable_move_after_cinema)($at)
  lw    $v0, ($s0)
  li    $v1, 1
  sw    $ra, 0x2c($sp)
  bne   $v1, $v0, .L7F07AA80
   li    $at, 2
  lui   $t6, %hi(ptr_random06cam_entry) 
  lw    $t6, %lo(ptr_random06cam_entry)($t6)
  beqz  $t6, .L7F07AA70
   nop   
  jal   get_recording_ramrom_flag
   nop   
  bnez  $v0, .L7F07AA70
   nop   
  jal   get_is_ramrom_flag
   nop   
  bnez  $v0, .L7F07AA70
   lui   $at, %hi(D_800364A4)
  mtc1  $zero, $f4
  move  $a0, $zero
  move  $a1, $zero
  move  $a2, $zero
  lui   $a3, 0x3f80
  jal   set_rgba_tint
   swc1  $f4, %lo(D_800364A4)($at)
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f12
  mtc1  $zero, $f14
  jal   fade_to_over_seconds
   nop   
  jal   get_stage_num
   nop   
  move  $a0, $v0
  jal   load_enviroment
   li    $a1, 1
  lui   $s0, %hi(pPlayer)
  addiu $s0, %lo(pPlayer) # addiu $s0, $s0, -0x5f50
  lw    $t7, ($s0)
  b     .L7F07B190
   sw    $zero, 0x34($t7)
.L7F07AA70:
  jal   set_camera_mode
   li    $a0, 3
  b     .L7F07B194
   lw    $ra, 0x2c($sp)
.L7F07AA80:
  bne   $v0, $at, .L7F07AAB8
   move  $a0, $zero
  move  $a1, $zero
  move  $a2, $zero
  jal   set_rgba_tint
   li    $a3, 0
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f12
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f14
  jal   fade_to_over_seconds
   nop   
  b     .L7F07B194
   lw    $ra, 0x2c($sp)
.L7F07AAB8:
  li    $at, 9
  bnel  $v0, $at, .L7F07AB14
   li    $at, 3
  mtc1  $zero, $f0
  lui   $at, %hi(flt_CODE_bss_80079E04)
  swc1  $f0, %lo(flt_CODE_bss_80079E04)($at)
  li    $at, 0xC2B40000 # -90.000000
  mtc1  $at, $f6
  lui   $at, %hi(flt_CODE_bss_80079E08)
  swc1  $f6, %lo(flt_CODE_bss_80079E08)($at)
  lui   $at, %hi(flt_CODE_bss_80079E0C)
  swc1  $f0, %lo(flt_CODE_bss_80079E0C)($at)
  li    $at, 0x42A00000 # 80.000000
  mtc1  $at, $f8
  lui   $at, %hi(flt_CODE_bss_80079E10)
  jal   get_stage_num
   swc1  $f8, %lo(flt_CODE_bss_80079E10)($at)
  move  $a0, $v0
  jal   load_enviroment
   move  $a1, $zero
  b     .L7F07B194
   lw    $ra, 0x2c($sp)
  li    $at, 3
.L7F07AB14:
  bne   $v0, $at, .L7F07AC7C
   move  $a0, $zero
  lui   $at, %hi(D_8003649C)
  sw    $zero, %lo(D_8003649C)($at)
  move  $a1, $zero
  move  $a2, $zero
  jal   set_rgba_tint
   lui   $a3, 0x3f80
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f12
  mtc1  $zero, $f14
  jal   fade_to_over_seconds
   nop   
  jal   get_stage_num
   nop   
  move  $a0, $v0
  jal   load_enviroment
   move  $a1, $zero
  lui   $t8, %hi(D_800364AC) 
  lw    $t8, %lo(D_800364AC)($t8)
  beqz  $t8, .L7F07AC6C
   nop   
  jal   get_recording_ramrom_flag
   nop   
  bnez  $v0, .L7F07AC6C
   nop   
  jal   get_is_ramrom_flag
   nop   
  bnez  $v0, .L7F07AC6C
   nop   
  mtc1  $zero, $f12
  lui   $at, %hi(D_800364A4)
  li    $t9, 1
  swc1  $f12, %lo(D_800364A4)($at)
  lui   $at, %hi(D_800364A8)
  sw    $t9, %lo(D_800364A8)($at)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f14
  jal   set_curplayer_fade
   nop   
  jal   solo_char_load
   nop   
  lui   $t0, %hi(D_80036514) 
  lw    $t0, %lo(D_80036514)($t0)
  lui   $t2, %hi(stage_intro_anim_table) 
  lui   $s0, %hi(pPlayer)
  addiu $t2, %lo(stage_intro_anim_table) # addiu $t2, $t2, 0x6518
  sll   $t1, $t0, 4
  addiu $s0, %lo(pPlayer) # addiu $s0, $s0, -0x5f50
  addu  $v0, $t1, $t2
  lw    $t5, ($s0)
  lwc1  $f0, 4($v0)
  lui   $t4, %hi(ptr_animation_table) 
  lw    $t4, %lo(ptr_animation_table)($t4)
  lw    $t3, ($v0)
  lwc1  $f12, 8($v0)
  lwc1  $f2, 0xc($v0)
  mtc1  $zero, $f10
  lw    $a0, 0xd4($t5)
  mfc1  $a3, $f0
  move  $a2, $zero
  addu  $a1, $t3, $t4
  swc1  $f12, 0x78($sp)
  swc1  $f2, 0x10($sp)
  jal   sub_GAME_7F06FCA8
   swc1  $f10, 0x14($sp)
  lwc1  $f12, 0x78($sp)
  mtc1  $zero, $f16
  nop   
  c.lt.s $f16, $f12
  nop   
  bc1fl .L7F07AC4C
   lw    $t7, ($s0)
  lw    $t6, ($s0)
  mfc1  $a1, $f12
  jal   sub_GAME_7F06FDE8
   lw    $a0, 0xd4($t6)
  lw    $t7, ($s0)
.L7F07AC4C:
  li    $t9, 23
  lw    $t8, 0xa8($t7)
  lw    $v0, 4($t8)
  sb    $t9, 7($v0)
  sb    $zero, 8($v0)
  lw    $t0, ($s0)
  b     .L7F07B190
   sw    $zero, 0x34($t0)
.L7F07AC6C:
  jal   set_camera_mode
   li    $a0, 4
  b     .L7F07B194
   lw    $ra, 0x2c($sp)
.L7F07AC7C:
  li    $at, 4
  bnel  $v0, $at, .L7F07AD6C
   li    $at, 5
  jal   get_stage_num
   nop   
  li    $at, 54
  bne   $v0, $at, .L7F07ACCC
   lui   $t1, %hi(D_8003649C) 
  move  $a0, $zero
  move  $a1, $zero
  move  $a2, $zero
  jal   set_rgba_tint
   lui   $a3, 0x3f80
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f14
  mtc1  $zero, $f12
  jal   fade_to_over_seconds
   nop   
  b     .L7F07ACFC
   nop   
.L7F07ACCC:
  lw    $t1, %lo(D_8003649C)($t1)
  move  $a0, $zero
  move  $a1, $zero
  beqz  $t1, .L7F07ACFC
   move  $a2, $zero
  jal   set_rgba_tint
   lui   $a3, 0x3f80
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f12
  mtc1  $zero, $f14
  jal   fade_to_over_seconds
   nop   
.L7F07ACFC:
  jal   getPlayerCount
   nop   
  slti  $at, $v0, 2
  bnez  $at, .L7F07AD24
   nop   
  jal   get_stage_num
   nop   
  move  $a0, $v0
  jal   load_enviroment
   move  $a1, $zero
.L7F07AD24:
  lui   $s0, %hi(pPlayer)
  addiu $s0, %lo(pPlayer) # addiu $s0, $s0, -0x5f50
  lw    $t2, ($s0)
  lui   $s0, %hi(starting_right_weapon)
  addiu $s0, %lo(starting_right_weapon) # addiu $s0, $s0, -0x6620
  lw    $t3, 0x1c8($t2)
  li    $a0, 1
  bnez  $t3, .L7F07AD5C
   nop   
  jal   draw_item_in_hand_has_more_ammo
   lw    $a1, 4($s0)
  move  $a0, $zero
  jal   draw_item_in_hand_has_more_ammo
   lw    $a1, ($s0)
.L7F07AD5C:
  lui   $at, %hi(stop_time_flag)
  b     .L7F07B190
   sw    $zero, %lo(stop_time_flag)($at)
  li    $at, 5
.L7F07AD6C:
  bne   $v0, $at, .L7F07B0A0
   move  $a0, $zero
  mtc1  $zero, $f18
  lui   $at, %hi(D_800364A4)
  move  $a1, $zero
  swc1  $f18, %lo(D_800364A4)($at)
  lui   $at, %hi(D_800364A8)
  sw    $v1, %lo(D_800364A8)($at)
  move  $a2, $zero
  jal   set_rgba_tint
   lui   $a3, 0x3f80
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f12
  mtc1  $zero, $f14
  jal   fade_to_over_seconds
   nop   
  lui   $v0, %hi(D_8003648C)
  lw    $v0, %lo(D_8003648C)($v0)
  lui   $s0, %hi(pPlayer)
  lui   $t4, %hi(ptr_playerstank) 
  beqz  $v0, .L7F07ADDC
   addiu $s0, %lo(pPlayer) # addiu $s0, $s0, -0x5f50
  lw    $t4, %lo(ptr_playerstank)($t4)
  beqz  $t4, .L7F07ADDC
   nop   
  lui   $s0, %hi(pPlayer)
  b     .L7F07AF48
   addiu $s0, %lo(pPlayer) # addiu $s0, $s0, -0x5f50
.L7F07ADDC:
  lui   $at, %hi(in_tank_flag)
  sw    $zero, %lo(in_tank_flag)($at)
  lw    $t9, ($s0)
  move  $t8, $t9
  addiu $t7, $t9, 0x54
.L7F07ADF0:
  lw    $at, 0x434($t8)
  addiu $t8, $t8, 0xc
  addiu $t9, $t9, 0xc
  sw    $at, 0x47c($t9)
  lw    $at, 0x42c($t8)
  sw    $at, 0x480($t9)
  lw    $at, 0x430($t8)
  bne   $t8, $t7, .L7F07ADF0
   sw    $at, 0x484($t9)
  lw    $v0, ($s0)
  lwc1  $f4, 0x414($v0)
  swc1  $f4, 0x148($v0)
  lw    $v0, ($s0)
  lwc1  $f6, 0x418($v0)
  swc1  $f6, 0x158($v0)
  lw    $v0, ($s0)
  lwc1  $f8, 0x48c($v0)
  lw    $t0, 0xa8($v0)
  swc1  $f8, 8($t0)
  lw    $v0, ($s0)
  lwc1  $f10, 0x490($v0)
  lw    $t1, 0xa8($v0)
  swc1  $f10, 0xc($t1)
  lw    $v0, ($s0)
  lwc1  $f16, 0x494($v0)
  lw    $t2, 0xa8($v0)
  swc1  $f16, 0x10($t2)
  lw    $v0, ($s0)
  lw    $t3, 0x488($v0)
  lw    $t4, 0xa8($v0)
  jal   sub_GAME_7F081790
   sw    $t3, 0x14($t4)
  mtc1  $zero, $f12
  nop   
  mfc1  $a2, $f12
  jal   sub_GAME_7F080B34
   mov.s $f14, $f12
  jal   sub_GAME_7F081478
   nop   
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f14
  mtc1  $zero, $f12
  jal   set_curplayer_fade
   nop   
  jal   solo_char_load
   nop   
  lw    $a0, ($s0)
  jal   sub_GAME_7F06F5AC
   addiu $a0, $a0, 0x598
  lw    $a0, ($s0)
  sw    $v0, 0x38($sp)
  jal   sub_GAME_7F06F5B4
   addiu $a0, $a0, 0x598
  mtc1  $zero, $f0
  lw    $t6, ($s0)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f18
  lw    $a0, 0xd4($t6)
  mfc1  $a3, $f0
  lw    $a1, 0x38($sp)
  move  $a2, $v0
  swc1  $f0, 0x14($sp)
  jal   sub_GAME_7F06FCA8
   swc1  $f18, 0x10($sp)
  lw    $t5, ($s0)
  li    $t8, 24
  lw    $t7, 0xa8($t5)
  lw    $v1, 4($t7)
  lw    $t9, 0x14($v1)
  sb    $t8, 7($v1)
  sb    $zero, 8($v1)
  ori   $t0, $t9, 1
  sw    $t0, 0x14($v1)
  lw    $v0, ($s0)
  lw    $a1, 0xa8($v0)
  lw    $a0, 0xd4($v0)
  jal   setsuboffset
   addiu $a1, $a1, 8
  jal   get_curplay_horizontal_rotation_in_degrees
   nop   
  lw    $t1, ($s0)
  mfc1  $a1, $f0
  jal   setsubroty
   lw    $a0, 0xd4($t1)
  lui   $v0, %hi(D_8003648C)
  lw    $v0, %lo(D_8003648C)($v0)
.L7F07AF48:
  beqz  $v0, .L7F07AFA8
   addiu $a1, $sp, 0x58
  lui   $a0, %hi(ptr_playerstank)
  lw    $a0, %lo(ptr_playerstank)($a0)
  beql  $a0, $zero, .L7F07AFAC
   lw    $v0, ($s0)
  sw    $a0, 0x64($sp)
  lwc1  $f4, 8($a0)
  li    $at, 0x43FA0000 # 500.000000
  mtc1  $at, $f0
  swc1  $f4, 0x58($sp)
  lwc1  $f6, 0xc($a0)
  move  $a2, $a0
  swc1  $f6, 0x5c($sp)
  lwc1  $f8, 0x10($a0)
  swc1  $f8, 0x60($sp)
  lwc1  $f10, 8($a0)
  swc1  $f10, 0x48($sp)
  lwc1  $f16, 0xc($a0)
  swc1  $f16, 0x4c($sp)
  lwc1  $f18, 0x10($a0)
  swc1  $f18, 0x50($sp)
  b     .L7F07AFF4
   lw    $v1, 0x14($a0)
.L7F07AFA8:
  lw    $v0, ($s0)
.L7F07AFAC:
  li    $at, 0x43480000 # 200.000000
  mtc1  $at, $f0
  lw    $t2, 0xa8($v0)
  sw    $t2, 0x64($sp)
  lwc1  $f4, 0x3c4($v0)
  swc1  $f4, 0x58($sp)
  lwc1  $f6, 0x3c8($v0)
  swc1  $f6, 0x5c($sp)
  lwc1  $f8, 0x3cc($v0)
  swc1  $f8, 0x60($sp)
  lwc1  $f10, 0x48c($v0)
  lw    $a2, 0xa8($v0)
  swc1  $f10, 0x48($sp)
  lwc1  $f16, 0x490($v0)
  swc1  $f16, 0x4c($sp)
  lwc1  $f18, 0x494($v0)
  swc1  $f18, 0x50($sp)
  lw    $v1, 0x488($v0)
.L7F07AFF4:
  lw    $a0, 0x64($sp)
  addiu $a3, $sp, 0x48
  sw    $v1, 0x10($sp)
  jal   sub_GAME_7F07A534
   swc1  $f0, 0x14($sp)
  beqz  $v0, .L7F07B090
   lui   $t3, %hi(D_80036510) 
  lw    $t3, %lo(D_80036510)($t3)
  bnez  $t3, .L7F07B034
   nop   
  jal   musicTrack1Play
   li    $a0, 44
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f12
  jal   sfx_c_70009238
   nop   
.L7F07B034:
  lui   $t4, %hi(D_8003648C) 
  lw    $t4, %lo(D_8003648C)($t4)
  lui   $t6, %hi(ptr_playerstank) 
  beql  $t4, $zero, .L7F07B194
   lw    $ra, 0x2c($sp)
  lw    $t6, %lo(ptr_playerstank)($t6)
  beql  $t6, $zero, .L7F07B194
   lw    $ra, 0x2c($sp)
  jal   get_cur_playernum
   nop   
  lui   $a0, %hi(ptr_playerstank)
  lw    $a0, %lo(ptr_playerstank)($a0)
  li    $a3, 13
  lw    $a2, 0x14($a0)
  addiu $t5, $a0, 0x2c
  sw    $t5, 0x18($sp)
  sw    $zero, 0x1c($sp)
  sw    $v0, 0x14($sp)
  sw    $zero, 0x10($sp)
  jal   sub_GAME_7F09C250
   addiu $a1, $a0, 8
  b     .L7F07B194
   lw    $ra, 0x2c($sp)
.L7F07B090:
  jal   run_title_stage
   nop   
  b     .L7F07B194
   lw    $ra, 0x2c($sp)
.L7F07B0A0:
  li    $at, 6
  bne   $v0, $at, .L7F07B0DC
   move  $a0, $zero
  move  $a1, $zero
  move  $a2, $zero
  jal   set_rgba_tint
   li    $a3, 0
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f12
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f14
  jal   fade_to_over_seconds
   nop   
  b     .L7F07B194
   lw    $ra, 0x2c($sp)
.L7F07B0DC:
  li    $at, 7
  bnel  $v0, $at, .L7F07B108
   li    $at, 8
  jal   solo_char_load
   nop   
  lui   $s0, %hi(pPlayer)
  addiu $s0, %lo(pPlayer) # addiu $s0, $s0, -0x5f50
  lw    $t7, ($s0)
  b     .L7F07B190
   sw    $zero, 0x34($t7)
  li    $at, 8
.L7F07B108:
  bnel  $v0, $at, .L7F07B128
   li    $at, 10
  jal   maybe_solo_intro_camera_handler
   nop   
  li    $t8, 4
  b     .L7F07B190
   sw    $t8, ($s0)
  li    $at, 10
.L7F07B128:
  bnel  $v0, $at, .L7F07B194
   lw    $ra, 0x2c($sp)
  jal   getPlayerCount
   move  $s0, $zero
  blez  $v0, .L7F07B188
   nop   
.L7F07B140:
  jal   set_cur_player
   move  $a0, $s0
  move  $a0, $zero
  move  $a1, $zero
  move  $a2, $zero
  jal   set_rgba_tint
   li    $a3, 0
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f12
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f14
  jal   fade_to_over_seconds
   nop   
  jal   getPlayerCount
   addiu $s0, $s0, 1
  slt   $at, $s0, $v0
  bnez  $at, .L7F07B140
   nop   
.L7F07B188:
  jal   set_cur_player
   move  $a0, $zero
.L7F07B190:
  lw    $ra, 0x2c($sp)
.L7F07B194:
  lw    $s0, 0x28($sp)
  addiu $sp, $sp, 0x88
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F07B1A4
  lui   $v1, %hi(cameramode)
  addiu $v1, %lo(cameramode) # addiu $v1, $v1, 0x6494
  lw    $v0, ($v1)
  sw    $zero, ($v1)
  lui   $at, %hi(enable_move_after_cinema)
  sw    $zero, %lo(enable_move_after_cinema)($at)
  addiu $sp, $sp, -0x18
  li    $at, 1
  bne   $v0, $at, .L7F07B1DC
   sw    $ra, 0x14($sp)
  jal   set_camera_mode
   li    $a0, 2
  b     .L7F07B294
   lw    $ra, 0x14($sp)
.L7F07B1DC:
  li    $at, 2
  bnel  $v0, $at, .L7F07B204
   li    $at, 9
  jal   reset_intro_camera_message_dialogs_for_BONDdata
   nop   
  jal   set_camera_mode
   li    $a0, 3
  b     .L7F07B294
   lw    $ra, 0x14($sp)
  li    $at, 9
.L7F07B204:
  beq   $v0, $at, .L7F07B290
   li    $at, 3
  bnel  $v0, $at, .L7F07B244
   li    $at, 4
  jal   maybe_solo_intro_camera_handler
   nop   
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f14
  mtc1  $zero, $f12
  jal   set_curplayer_fade
   nop   
  jal   set_camera_mode
   li    $a0, 4
  b     .L7F07B294
   lw    $ra, 0x14($sp)
  li    $at, 4
.L7F07B244:
  beq   $v0, $at, .L7F07B290
   li    $at, 5
  bnel  $v0, $at, .L7F07B268
   li    $at, 6
  jal   set_camera_mode
   li    $a0, 6
  b     .L7F07B294
   lw    $ra, 0x14($sp)
  li    $at, 6
.L7F07B268:
  bne   $v0, $at, .L7F07B290
   lui   $v0, %hi(D_80036510)
  addiu $v0, %lo(D_80036510) # addiu $v0, $v0, 0x6510
  lw    $t6, ($v0)
  addiu $t7, $t6, 1
  slti  $at, $t7, 3
  beqz  $at, .L7F07B290
   sw    $t7, ($v0)
  jal   set_camera_mode
   li    $a0, 5
.L7F07B290:
  lw    $ra, 0x14($sp)
.L7F07B294:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F07B2A0
  lui   $t0, %hi(D_800364AC) 
  lw    $t0, %lo(D_800364AC)($t0)
  addiu $sp, $sp, -0x90
  sll   $t4, $a0, 5
  sw    $ra, 0x2c($sp)
  sw    $s0, 0x28($sp)
  sw    $a2, 0x98($sp)
  addu  $t3, $t0, $t4
  mtc1  $zero, $f2
  lwc1  $f0, 0x18($t3)
  move  $s0, $a3
  mtc1  $a1, $f12
  c.lt.s $f2, $f0
  sll   $t6, $a0, 5
  addiu $a1, $sp, 0x54
  li    $a2, -1
  bc1f  .L7F07B2EC
   addu  $a3, $t6, $t0
  div.s $f2, $f12, $f0
.L7F07B2EC:
  lui   $t1, %hi(pPlayer) 
  addiu $t1, %lo(pPlayer) # addiu $t1, $t1, -0x5f50
  li    $t2, 3
.L7F07B2F8:
  sll   $t7, $a2, 5
  addu  $a0, $t7, $a3
  move  $v0, $a3
  bgez  $a2, .L7F07B328
   move  $v1, $a0
  sltu  $at, $a0, $t0
  beqz  $at, .L7F07B320
   nop   
  b     .L7F07B354
   move  $v0, $t0
.L7F07B320:
  b     .L7F07B354
   move  $v0, $v1
.L7F07B328:
  sltu  $at, $v0, $a0
  beql  $at, $zero, .L7F07B358
   lw    $t5, 4($v0)
  lw    $t8, 0x24($v0)
.L7F07B338:
  andi  $t9, $t8, 1
  bnezl $t9, .L7F07B358
   lw    $t5, 4($v0)
  addiu $v0, $v0, 0x20
  sltu  $at, $v0, $v1
  bnezl $at, .L7F07B338
   lw    $t8, 0x24($v0)
.L7F07B354:
  lw    $t5, 4($v0)
.L7F07B358:
  addiu $a2, $a2, 1
  andi  $t6, $t5, 2
  beql  $t6, $zero, .L7F07B3C4
   lwc1  $f16, 8($v0)
  lw    $v1, ($t1)
  lwc1  $f6, 8($v0)
  lwc1  $f10, 0x10($v0)
  lwc1  $f4, 0x4a0($v1)
  lwc1  $f16, 0x498($v1)
  mul.s $f8, $f4, $f6
  nop   
  mul.s $f18, $f10, $f16
  add.s $f4, $f8, $f18
  swc1  $f4, 0xc($a1)
  lwc1  $f6, 0xc($v0)
  swc1  $f6, 0x10($a1)
  lwc1  $f10, 0x10($v0)
  lwc1  $f16, 0x4a0($v1)
  lwc1  $f4, 8($v0)
  lwc1  $f18, 0x498($v1)
  mul.s $f8, $f10, $f16
  nop   
  mul.s $f6, $f18, $f4
  sub.s $f10, $f8, $f6
  b     .L7F07B3D8
   swc1  $f10, 0x14($a1)
  lwc1  $f16, 8($v0)
.L7F07B3C4:
  swc1  $f16, 0xc($a1)
  lwc1  $f18, 0xc($v0)
  swc1  $f18, 0x10($a1)
  lwc1  $f4, 0x10($v0)
  swc1  $f4, 0x14($a1)
.L7F07B3D8:
  bne   $a2, $t2, .L7F07B2F8
   addiu $a1, $a1, 0xc
  lwc1  $f0, 0x14($t3)
  lw    $t7, 0x98($sp)
  swc1  $f2, 0x58($sp)
  sw    $t4, 0x40($sp)
  swc1  $f2, 0x10($sp)
  addiu $a0, $sp, 0x60
  addiu $a1, $sp, 0x6c
  addiu $a2, $sp, 0x78
  addiu $a3, $sp, 0x84
  swc1  $f0, 0x14($sp)
  jal   sub_GAME_7F05B024
   sw    $t7, 0x18($sp)
  lui   $t1, %hi(pPlayer) 
  addiu $t1, %lo(pPlayer) # addiu $t1, $t1, -0x5f50
  lw    $v0, 0x98($sp)
  lw    $t8, ($t1)
  lw    $t4, 0x40($sp)
  lwc1  $f8, ($v0)
  lwc1  $f6, 0x3c4($t8)
  lwc1  $f2, 0x58($sp)
  lwc1  $f16, 4($v0)
  add.s $f10, $f8, $f6
  lwc1  $f8, 8($v0)
  mtc1  $zero, $f14
  swc1  $f10, ($v0)
  lw    $t9, ($t1)
  lwc1  $f18, 0x3c8($t9)
  lui   $t9, %hi(D_800364AC) 
  add.s $f4, $f16, $f18
  swc1  $f4, 4($v0)
  lw    $t5, ($t1)
  lwc1  $f6, 0x3cc($t5)
  add.s $f10, $f8, $f6
  swc1  $f10, 8($v0)
  lw    $t6, ($t1)
  lwc1  $f16, 0x3c4($t6)
  swc1  $f16, ($s0)
  lw    $t7, ($t1)
  lwc1  $f18, 0x3c8($t7)
  swc1  $f18, 4($s0)
  lw    $t8, ($t1)
  lwc1  $f4, 0x3cc($t8)
  swc1  $f4, 8($s0)
  lw    $t9, %lo(D_800364AC)($t9)
  addu  $t3, $t9, $t4
  lw    $t5, 4($t3)
  andi  $t6, $t5, 4
  bnezl $t6, .L7F07B4D8
   lw    $t9, 0x24($t3)
  lw    $t7, 0x24($t3)
  li    $at, 0x3F800000 # 1.000000
  andi  $t8, $t7, 4
  bnezl $t8, .L7F07B4CC
   mtc1  $at, $f8
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f0
  b     .L7F07B4F4
   lw    $t6, ($t1)
  mtc1  $at, $f8
.L7F07B4CC:
  b     .L7F07B4F0
   sub.s $f0, $f8, $f2
  lw    $t9, 0x24($t3)
.L7F07B4D8:
  andi  $t5, $t9, 4
  beql  $t5, $zero, .L7F07B4F0
   mov.s $f0, $f2
  b     .L7F07B4F0
   mov.s $f0, $f14
  mov.s $f0, $f2
.L7F07B4F0:
  lw    $t6, ($t1)
.L7F07B4F4:
  li    $at, 0x42200000 # 40.000000
  mtc1  $at, $f2
  lwc1  $f10, 0x4c0($t6)
  lwc1  $f6, ($s0)
  lwc1  $f8, 4($s0)
  mul.s $f16, $f10, $f2
  nop   
  mul.s $f18, $f16, $f0
  add.s $f4, $f6, $f18
  swc1  $f4, ($s0)
  lw    $t7, ($t1)
  lwc1  $f4, 8($s0)
  lwc1  $f10, 0x4c4($t7)
  mul.s $f16, $f10, $f2
  nop   
  mul.s $f6, $f16, $f0
  add.s $f18, $f8, $f6
  swc1  $f18, 4($s0)
  lw    $t8, ($t1)
  lwc1  $f10, 0x4c8($t8)
  mul.s $f16, $f10, $f2
  nop   
  mul.s $f8, $f16, $f0
  add.s $f6, $f4, $f8
  swc1  $f6, 8($s0)
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x28($sp)
  addiu $sp, $sp, 0x90
  jr    $ra
   nop   
");

#ifdef VERSION_US
asm(R"
.late_rodata
glabel D_80055044
.word 0x43338000 /*179.5*/
glabel D_80055048
.word 0x3dcccccd /*0.1*/
glabel D_8005504C
.word 0x3c75c28f /*0.015*/
glabel D_80055050
.word 0x40490fdb /*3.1415927*/
glabel D_80055054
.word 0x3da3d70a /*0.079999998*/
glabel D_80055058
.word 0x3da3d70a /*0.079999998*/
glabel D_8005505C
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F07B56C
  addiu $sp, $sp, -0x40
  lui   $v0, %hi(cameramode)
  lw    $v0, %lo(cameramode)($v0)
  li    $t3, 1
  sw    $ra, 0x14($sp)
  sw    $a0, 0x40($sp)
  sw    $a1, 0x44($sp)
  sw    $a2, 0x48($sp)
  beq   $t3, $v0, .L7F07B5A0
   sw    $a3, 0x4c($sp)
  li    $a1, 2
  bne   $a1, $v0, .L7F07B858
   li    $at, 9
.L7F07B5A0:
  bne   $t3, $v0, .L7F07B708
   lui   $t1, %hi(pPlayer) 
  lui   $t2, %hi(D_800364A4) 
  addiu $t2, %lo(D_800364A4) # addiu $t2, $t2, 0x64a4
  li    $at, 0x42F00000 # 120.000000
  mtc1  $at, $f0
  lwc1  $f2, ($t2)
  lui   $at, %hi(global_timer_delta)
  c.lt.s $f2, $f0
  nop   
  bc1f  .L7F07B61C
   nop   
  lwc1  $f4, %lo(global_timer_delta)($at)
  lui   $a0, %hi(ptrSecondFontTableLarge)
  lui   $a1, %hi(ptrFirstFontTableLarge)
  add.s $f6, $f2, $f4
  c.le.s $f0, $f6
  nop   
  bc1f  .L7F07B61C
   nop   
  lw    $a0, %lo(ptrSecondFontTableLarge)($a0)
  jal   sub_GAME_7F08A3B4
   lw    $a1, %lo(ptrFirstFontTableLarge)($a1)
  lui   $t6, %hi(ptr_random06cam_entry) 
  lw    $t6, %lo(ptr_random06cam_entry)($t6)
  jal   display_string_in_lower_left_corner
   lw    $a0, 0x1c($t6)
  lui   $t2, %hi(D_800364A4) 
  addiu $t2, %lo(D_800364A4) # addiu $t2, $t2, 0x64a4
  lwc1  $f2, ($t2)
  li    $t3, 1
.L7F07B61C:
  lui   $t7, %hi(ptr_random06cam_entry) 
  lw    $t7, %lo(ptr_random06cam_entry)($t7)
  lui   $at, %hi(global_timer_delta)
  lwc1  $f8, %lo(global_timer_delta)($at)
  lw    $a0, 0x20($t7)
  li    $at, 0x43960000 # 300.000000
  add.s $f0, $f2, $f8
  beql  $a0, $zero, .L7F07B6B8
   mtc1  $at, $f12
  li    $at, 0x43960000 # 300.000000
  mtc1  $at, $f12
  nop   
  c.lt.s $f2, $f12
  nop   
  bc1fl .L7F07B694
   lui   $at, 0x43f0
  c.le.s $f12, $f0
  nop   
  bc1fl .L7F07B694
   lui   $at, 0x43f0
  jal   display_string_in_lower_left_corner
   nop   
  lui   $t2, %hi(D_800364A4) 
  addiu $t2, %lo(D_800364A4) # addiu $t2, $t2, 0x64a4
  lui   $at, %hi(global_timer_delta)
  lwc1  $f10, %lo(global_timer_delta)($at)
  lwc1  $f2, ($t2)
  li    $t3, 1
  add.s $f0, $f2, $f10
  li    $at, 0x43F00000 # 480.000000
.L7F07B694:
  mtc1  $at, $f4
  lui    $at, %hi(enable_move_after_cinema)
  c.lt.s $f4, $f2
  nop   
  bc1f  .L7F07B6D0
   nop   
  b     .L7F07B6D0
   sw    $t3, %lo(enable_move_after_cinema)($at)
  mtc1  $at, $f12
.L7F07B6B8:
  lui   $at, %hi(enable_move_after_cinema)
  c.lt.s $f12, $f2
  nop   
  bc1f  .L7F07B6D0
   nop   
  sw    $t3, %lo(enable_move_after_cinema)($at)
.L7F07B6D0:
  jal   get_controls_locked_flag
   swc1  $f0, ($t2)
  bnez  $v0, .L7F07B730
   li    $t3, 1
  lhu   $t9, 0x46($sp)
  lhu   $t8, 0x42($sp)
  lui   $at, %hi(enable_move_after_cinema)
  not   $t4, $t9
  and   $t5, $t8, $t4
  andi  $t6, $t5, 0xf030
  beqz  $t6, .L7F07B730
   nop   
  b     .L7F07B730
   sw    $t3, %lo(enable_move_after_cinema)($at)
.L7F07B708:
  addiu $t1, %lo(pPlayer) # addiu $t1, $t1, -0x5f50
  lw    $t7, ($t1)
  mtc1  $zero, $f14
  lui   $at, %hi(enable_move_after_cinema)
  lwc1  $f6, 0x3e4($t7)
  c.lt.s $f6, $f14
  nop   
  bc1f  .L7F07B730
   nop   
  sw    $t3, %lo(enable_move_after_cinema)($at)
.L7F07B730:
  lui   $v0, %hi(ptr_random06cam_entry)
  addiu $v0, %lo(ptr_random06cam_entry) # addiu $v0, $v0, 0x64c0
  lw    $t9, ($v0)
  lw    $t8, 0x48($sp)
  lwc1  $f8, 4($t9)
  swc1  $f8, ($t8)
  lw    $t4, ($v0)
  lwc1  $f10, 8($t4)
  swc1  $f10, 4($t8)
  lw    $t5, ($v0)
  lwc1  $f4, 0xc($t5)
  swc1  $f4, 8($t8)
  lw    $t6, ($v0)
  jal   cosf
   lwc1  $f12, 0x14($t6)
  lui   $t7, %hi(ptr_random06cam_entry) 
  lw    $t7, %lo(ptr_random06cam_entry)($t7)
  swc1  $f0, 0x1c($sp)
  jal   sinf
   lwc1  $f12, 0x10($t7)
  lwc1  $f6, 0x1c($sp)
  lw    $t9, 0x48($sp)
  lw    $t4, 0x4c($sp)
  mul.s $f8, $f0, $f6
  lwc1  $f10, ($t9)
  lui   $t5, %hi(ptr_random06cam_entry) 
  add.s $f4, $f8, $f10
  swc1  $f4, ($t4)
  lw    $t5, %lo(ptr_random06cam_entry)($t5)
  jal   sinf
   lwc1  $f12, 0x14($t5)
  lw    $t8, 0x48($sp)
  lw    $t6, 0x4c($sp)
  lui   $t7, %hi(ptr_random06cam_entry) 
  lwc1  $f6, 4($t8)
  add.s $f8, $f0, $f6
  swc1  $f8, 4($t6)
  lw    $t7, %lo(ptr_random06cam_entry)($t7)
  jal   cosf
   lwc1  $f12, 0x14($t7)
  lui   $t9, %hi(ptr_random06cam_entry) 
  lw    $t9, %lo(ptr_random06cam_entry)($t9)
  swc1  $f0, 0x1c($sp)
  jal   cosf
   lwc1  $f12, 0x10($t9)
  lwc1  $f4, 0x1c($sp)
  lw    $t4, 0x48($sp)
  lw    $t5, 0x4c($sp)
  mul.s $f6, $f0, $f4
  lwc1  $f10, 8($t4)
  lw    $v1, 0x58($sp)
  lui   $t8, %hi(ptr_random06cam_entry) 
  lui   $t9, %hi(ptr_0xxxpresets) 
  sub.s $f8, $f10, $f6
  swc1  $f8, 8($t5)
  lw    $t8, %lo(ptr_random06cam_entry)($t8)
  lw    $t9, %lo(ptr_0xxxpresets)($t9)
  lw    $t5, 0x54($sp)
  lw    $t6, 0x18($t8)
  sll   $t7, $t6, 2
  subu  $t7, $t7, $t6
  sll   $t7, $t7, 2
  subu  $t7, $t7, $t6
  sll   $t7, $t7, 2
  addu  $v0, $t7, $t9
  lw    $t4, 0x28($v0)
  sw    $t4, ($t5)
  lwc1  $f4, ($v0)
  swc1  $f4, ($v1)
  lwc1  $f10, 4($v0)
  swc1  $f10, 4($v1)
  lwc1  $f6, 8($v0)
  b     .L7F07C530
   swc1  $f6, 8($v1)
.L7F07B858:
  bnel  $v0, $at, .L7F07BB28
   li    $at, 3
  jal   get_cur_playernum
   nop   
  jal   sub_GAME_7F09B4D8
   move  $a0, $v0
  bnez  $v0, .L7F07B9C4
   lui   $t1, %hi(pPlayer) 
  lui   $a3, %hi(clock_timer)
  lw    $a3, %lo(clock_timer)($a3)
  move  $v1, $zero
  lui   $at, %hi(flt_CODE_bss_80079E08)
  blez  $a3, .L7F07B9C4
   lui   $a2, %hi(flt_CODE_bss_80079E04)
  lwc1  $f12, %lo(flt_CODE_bss_80079E08)($at)
  lui   $at, %hi(D_80055044)
  lwc1  $f18, %lo(D_80055044)($at)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f16
  lui    $at, %hi(D_80055048)
  lui   $a1, %hi(flt_CODE_bss_80079E0C)
  lui   $a0, %hi(flt_CODE_bss_80079E08)
  lui   $v0, %hi(flt_CODE_bss_80079E10)
  addiu $v0, %lo(flt_CODE_bss_80079E10) # addiu $v0, $v0, -0x61f0
  addiu $a0, %lo(flt_CODE_bss_80079E08) # addiu $a0, $a0, -0x61f8
  addiu $a1, %lo(flt_CODE_bss_80079E0C) # addiu $a1, $a1, -0x61f4
  lwc1  $f14, %lo(D_80055048)($at)
  addiu $a2, %lo(flt_CODE_bss_80079E04) # addiu $a2, $a2, -0x61fc
  c.lt.s $f12, $f18
.L7F07B8CC:
  addiu $v1, $v1, 1
  li    $at, 0x43340000 # 180.000000
  bc1fl .L7F07B934
   mtc1  $at, $f4
  li    $at, 0xC1A00000 # -20.000000
  mtc1  $at, $f8
  li    $at, 0x42DC0000 # 110.000000
  mtc1  $at, $f10
  c.lt.s $f12, $f8
  lwc1  $f0, ($a2)
  bc1fl .L7F07B90C
   c.lt.s $f10, $f12
  add.s $f4, $f0, $f14
  swc1  $f4, ($a2)
  lwc1  $f0, ($a2)
  c.lt.s $f10, $f12
.L7F07B90C:
  nop   
  bc1fl .L7F07B928
   add.s $f8, $f12, $f0
  sub.s $f6, $f0, $f14
  swc1  $f6, ($a2)
  lwc1  $f0, ($a2)
  add.s $f8, $f12, $f0
.L7F07B928:
  b     .L7F07B93C
   swc1  $f8, ($a0)
  mtc1  $at, $f4
.L7F07B934:
  nop   
  swc1  $f4, ($a0)
.L7F07B93C:
  li    $at, 0x42A00000 # 80.000000
  mtc1  $at, $f10
  lwc1  $f12, ($a0)
  li    $at, 0x42700000 # 60.000000
  c.lt.s $f10, $f12
  nop   
  bc1fl .L7F07B9BC
   slt   $at, $v1, $a3
  lwc1  $f0, ($v0)
  mtc1  $at, $f6
  lwc1  $f2, ($a1)
  lui   $at, %hi(D_8005504C)
  c.lt.s $f6, $f0
  nop   
  bc1f  .L7F07B988
   nop   
  sub.s $f8, $f2, $f14
  b     .L7F07B994
   swc1  $f8, ($a1)
.L7F07B988:
  lwc1  $f4, %lo(D_8005504C)($at)
  add.s $f10, $f2, $f4
  swc1  $f10, ($a1)
.L7F07B994:
  lwc1  $f6, ($a1)
  add.s $f8, $f0, $f6
  swc1  $f8, ($v0)
  lwc1  $f4, ($v0)
  c.lt.s $f4, $f16
  nop   
  bc1fl .L7F07B9BC
   slt   $at, $v1, $a3
  swc1  $f16, ($v0)
  slt   $at, $v1, $a3
.L7F07B9BC:
  bnezl $at, .L7F07B8CC
   c.lt.s $f12, $f18
.L7F07B9C4:
  addiu $t1, %lo(pPlayer) # addiu $t1, $t1, -0x5f50
  lw    $t8, ($t1)
  lui   $a0, %hi(flt_CODE_bss_80079E08)
  addiu $a0, %lo(flt_CODE_bss_80079E08) # addiu $a0, $a0, -0x61f8
  lwc1  $f10, ($a0)
  lwc1  $f6, 0x148($t8)
  lui   $at, %hi(D_80055050)
  lwc1  $f4, %lo(D_80055050)($at)
  sub.s $f8, $f10, $f6
  li    $at, 0x43340000 # 180.000000
  mtc1  $at, $f6
  mul.s $f10, $f8, $f4
  div.s $f12, $f10, $f6
  jal   sinf
   swc1  $f12, 0x38($sp)
  lui   $v0, %hi(flt_CODE_bss_80079E10)
  addiu $v0, %lo(flt_CODE_bss_80079E10) # addiu $v0, $v0, -0x61f0
  lwc1  $f8, ($v0)
  lui   $t1, %hi(pPlayer) 
  addiu $t1, %lo(pPlayer) # addiu $t1, $t1, -0x5f50
  mul.s $f4, $f0, $f8
  lw    $t6, ($t1)
  lw    $v1, 0x48($sp)
  lwc1  $f12, 0x38($sp)
  lwc1  $f10, 0x4b4($t6)
  lui   $at, %hi(D_80055054)
  add.s $f6, $f4, $f10
  swc1  $f6, ($v1)
  lwc1  $f4, %lo(D_80055054)($at)
  lwc1  $f8, ($v0)
  lw    $t7, ($t1)
  mul.s $f10, $f8, $f4
  lwc1  $f6, 0x4b8($t7)
  add.s $f8, $f6, $f10
  jal   cosf
   swc1  $f8, 4($v1)
  lui   $v0, %hi(flt_CODE_bss_80079E10)
  addiu $v0, %lo(flt_CODE_bss_80079E10) # addiu $v0, $v0, -0x61f0
  lwc1  $f4, ($v0)
  lui   $t1, %hi(pPlayer) 
  addiu $t1, %lo(pPlayer) # addiu $t1, $t1, -0x5f50
  mul.s $f6, $f0, $f4
  lw    $t9, ($t1)
  lw    $t4, 0x48($sp)
  lw    $v1, 0x58($sp)
  lwc1  $f10, 0x4bc($t9)
  lw    $a0, 0x4c($sp)
  lui   $at, %hi(D_80055058)
  add.s $f8, $f6, $f10
  li    $t3, 1
  swc1  $f8, 8($t4)
  lw    $t5, ($t1)
  lwc1  $f4, 0x4b4($t5)
  swc1  $f4, ($a0)
  lw    $t8, ($t1)
  lwc1  $f6, 0x4b8($t8)
  swc1  $f6, 4($a0)
  lw    $t6, ($t1)
  lwc1  $f10, 0x4bc($t6)
  swc1  $f10, 8($a0)
  lw    $t7, ($t1)
  lw    $t5, 0x54($sp)
  lw    $t9, 0xa8($t7)
  lw    $t4, 0x14($t9)
  sw    $t4, ($t5)
  lw    $t8, ($t1)
  lwc1  $f8, 0x4b4($t8)
  swc1  $f8, ($v1)
  lwc1  $f4, ($v0)
  lwc1  $f6, %lo(D_80055058)($at)
  lw    $t6, ($t1)
  li    $at, 0x40A00000 # 5.000000
  mul.s $f10, $f4, $f6
  lwc1  $f8, 0x4b8($t6)
  add.s $f4, $f8, $f10
  mtc1  $at, $f10
  lui   $at, %hi(enable_move_after_cinema)
  swc1  $f4, 4($v1)
  lw    $t7, ($t1)
  lwc1  $f6, 0x4bc($t7)
  swc1  $f6, 8($v1)
  lwc1  $f8, ($v0)
  c.lt.s $f8, $f10
  nop   
  bc1fl .L7F07C534
   lw    $ra, 0x14($sp)
  b     .L7F07C530
   sw    $t3, %lo(enable_move_after_cinema)($at)
  li    $at, 3
.L7F07BB28:
  bne   $v0, $at, .L7F07BE58
   li    $v1, 5
  lui   $t2, %hi(D_800364A4) 
  addiu $t2, %lo(D_800364A4) # addiu $t2, $t2, 0x64a4
  lui   $at, %hi(global_timer_delta)
  lwc1  $f18, %lo(global_timer_delta)($at)
  lwc1  $f4, ($t2)
  lui   $t0, %hi(D_800364A8) 
  addiu $t0, %lo(D_800364A8) # addiu $t0, $t0, 0x64a8
  add.s $f6, $f4, $f18
  lw    $v1, ($t0)
  lui   $a0, %hi(D_800364AC)
  lui   $at, %hi(enable_move_after_cinema)
  swc1  $f6, ($t2)
  lw    $a0, %lo(D_800364AC)($a0)
  sll   $t9, $v1, 5
  lwc1  $f2, ($t2)
  addu  $v0, $a0, $t9
  lwc1  $f0, 0x18($v0)
  c.le.s $f0, $f2
  nop   
  bc1fl .L7F07BBE4
   addiu $a1, $v1, 1
  lw    $t4, 0x64($v0)
.L7F07BB88:
  andi  $t5, $t4, 1
  bnezl $t5, .L7F07BBAC
   swc1  $f0, ($t2)
  sub.s $f8, $f2, $f0
  addiu $t8, $v1, 1
  sw    $t8, ($t0)
  b     .L7F07BBBC
   swc1  $f8, ($t2)
  swc1  $f0, ($t2)
.L7F07BBAC:
  sw    $t3, %lo(enable_move_after_cinema)($at)
  lwc1  $f0, 0x18($v0)
  b     .L7F07BBE0
   lwc1  $f2, ($t2)
.L7F07BBBC:
  lw    $v1, ($t0)
  lwc1  $f2, ($t2)
  sll   $t6, $v1, 5
  addu  $v0, $a0, $t6
  lwc1  $f0, 0x18($v0)
  c.le.s $f0, $f2
  nop   
  bc1tl .L7F07BB88
   lw    $t4, 0x64($v0)
.L7F07BBE0:
  addiu $a1, $v1, 1
.L7F07BBE4:
  sll   $t7, $a1, 5
  addu  $v0, $a0, $t7
  lw    $t9, 0x44($v0)
  sub.s $f10, $f0, $f2
  mtc1  $zero, $f14
  andi  $t4, $t9, 1
  bnez  $t4, .L7F07BC1C
   add.s $f16, $f14, $f10
.L7F07BC04:
  lw    $t5, 0x64($v0)
  lwc1  $f4, 0x18($v0)
  addiu $v0, $v0, 0x20
  andi  $t8, $t5, 1
  beqz  $t8, .L7F07BC04
   add.s $f16, $f16, $f4
.L7F07BC1C:
  li    $at, 0x41F00000 # 30.000000
  mtc1  $at, $f12
  nop   
  c.lt.s $f16, $f12
  nop   
  bc1f  .L7F07BC68
   nop   
  add.s $f6, $f16, $f18
  c.le.s $f12, $f6
  nop   
  bc1f  .L7F07BC68
   nop   
  jal   set_curplayer_fade
   swc1  $f16, 0x30($sp)
  lui   $t0, %hi(D_800364A8) 
  lui   $t2, %hi(D_800364A4) 
  addiu $t2, %lo(D_800364A4) # addiu $t2, $t2, 0x64a4
  addiu $t0, %lo(D_800364A8) # addiu $t0, $t0, 0x64a8
  lwc1  $f16, 0x30($sp)
.L7F07BC68:
  lui   $t6, %hi(D_8003649C) 
  lw    $t6, %lo(D_8003649C)($t6)
  beql  $t6, $zero, .L7F07BCA8
   lui   $at, 0x4270
  jal   check_if_fade_to_black_complete
   swc1  $f16, 0x30($sp)
  lui   $t0, %hi(D_800364A8) 
  lui   $t2, %hi(D_800364A4) 
  addiu $t2, %lo(D_800364A4) # addiu $t2, $t2, 0x64a4
  addiu $t0, %lo(D_800364A8) # addiu $t0, $t0, 0x64a8
  li    $t3, 1
  beqz  $v0, .L7F07BCA4
   lwc1  $f16, 0x30($sp)
  lui   $at, %hi(enable_move_after_cinema)
  sw    $t3, %lo(enable_move_after_cinema)($at)
.L7F07BCA4:
  li    $at, 0x42700000 # 60.000000
.L7F07BCA8:
  mtc1  $at, $f8
  lui   $t7, %hi(D_8003649C) 
  c.lt.s $f8, $f16
  nop   
  bc1fl .L7F07BD94
   lw    $a0, ($t0)
  lw    $t7, %lo(D_8003649C)($t7)
  bnezl $t7, .L7F07BD94
   lw    $a0, ($t0)
  jal   get_controls_locked_flag
   nop   
  lui   $t0, %hi(D_800364A8) 
  lui   $t2, %hi(D_800364A4) 
  addiu $t2, %lo(D_800364A4) # addiu $t2, $t2, 0x64a4
  addiu $t0, %lo(D_800364A8) # addiu $t0, $t0, 0x64a8
  bnez  $v0, .L7F07BD90
   li    $t3, 1
  lhu   $t4, 0x46($sp)
  lhu   $t9, 0x42($sp)
  lui   $t1, %hi(pPlayer) 
  not   $t5, $t4
  and   $t8, $t9, $t5
  andi  $t6, $t8, 0xf030
  beqz  $t6, .L7F07BD90
   addiu $t1, %lo(pPlayer) # addiu $t1, $t1, -0x5f50
  lui   $at, %hi(D_8003649C)
  sw    $t3, %lo(D_8003649C)($at)
  lw    $t7, ($t1)
  move  $a0, $zero
  move  $a1, $zero
  move  $a2, $zero
  jal   set_rgba_tint
   lw    $a3, 0x3dc($t7)
  jal   check_if_fade_to_black_complete
   nop   
  lui   $t1, %hi(pPlayer) 
  beqz  $v0, .L7F07BD6C
   addiu $t1, %lo(pPlayer) # addiu $t1, $t1, -0x5f50
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f12
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f14
  jal   fade_to_over_seconds
   nop   
  lui   $t0, %hi(D_800364A8) 
  lui   $t2, %hi(D_800364A4) 
  addiu $t2, %lo(D_800364A4) # addiu $t2, $t2, 0x64a4
  b     .L7F07BD90
   addiu $t0, %lo(D_800364A8) # addiu $t0, $t0, 0x64a8
.L7F07BD6C:
  lw    $t4, ($t1)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f14
  jal   fade_to_over_seconds
   lwc1  $f12, 0x3e0($t4)
  lui   $t0, %hi(D_800364A8) 
  lui   $t2, %hi(D_800364A4) 
  addiu $t2, %lo(D_800364A4) # addiu $t2, $t2, 0x64a4
  addiu $t0, %lo(D_800364A8) # addiu $t0, $t0, 0x64a8
.L7F07BD90:
  lw    $a0, ($t0)
.L7F07BD94:
  lw    $a1, ($t2)
  lw    $a2, 0x48($sp)
  jal   sub_GAME_7F07B2A0
   lw    $a3, 0x4c($sp)
  lui   $t0, %hi(D_800364A8) 
  addiu $t0, %lo(D_800364A8) # addiu $t0, $t0, 0x64a8
  lw    $t5, ($t0)
  lui   $t9, %hi(D_800364AC) 
  lw    $t9, %lo(D_800364AC)($t9)
  sll   $t8, $t5, 5
  lui   $t1, %hi(pPlayer) 
  addu  $t6, $t9, $t8
  lw    $a0, 0x1c($t6)
  addiu $t1, %lo(pPlayer) # addiu $t1, $t1, -0x5f50
  lui   $t4, %hi(ptr_0xxxpresets) 
  bltz  $a0, .L7F07BE1C
   sll   $t7, $a0, 2
  subu  $t7, $t7, $a0
  lw    $t4, %lo(ptr_0xxxpresets)($t4)
  sll   $t7, $t7, 2
  subu  $t7, $t7, $a0
  sll   $t7, $t7, 2
  addu  $v0, $t7, $t4
  lw    $t5, 0x28($v0)
  lw    $t9, 0x54($sp)
  lw    $v1, 0x58($sp)
  sw    $t5, ($t9)
  lwc1  $f10, ($v0)
  swc1  $f10, ($v1)
  lwc1  $f4, 4($v0)
  swc1  $f4, 4($v1)
  lwc1  $f6, 8($v0)
  b     .L7F07C530
   swc1  $f6, 8($v1)
.L7F07BE1C:
  lw    $t8, ($t1)
  lw    $t7, 0x54($sp)
  lw    $v1, 0x58($sp)
  lw    $t6, 0x488($t8)
  sw    $t6, ($t7)
  lw    $t4, ($t1)
  lwc1  $f8, 0x48c($t4)
  swc1  $f8, ($v1)
  lw    $t5, ($t1)
  lwc1  $f10, 0x490($t5)
  swc1  $f10, 4($v1)
  lw    $t9, ($t1)
  lwc1  $f4, 0x494($t9)
  b     .L7F07C530
   swc1  $f4, 8($v1)
.L7F07BE58:
  beq   $v1, $v0, .L7F07BE68
   li    $at, 6
  bnel  $v0, $at, .L7F07C0D4
   li    $at, 7
.L7F07BE68:
  bne   $v1, $v0, .L7F07BF68
   lui   $t2, %hi(D_800364A4) 
  addiu $t2, %lo(D_800364A4) # addiu $t2, $t2, 0x64a4
  lui   $at, %hi(global_timer_delta)
  lwc1  $f8, %lo(global_timer_delta)($at)
  lwc1  $f6, ($t2)
  lui   $t1, %hi(pPlayer) 
  addiu $t1, %lo(pPlayer) # addiu $t1, $t1, -0x5f50
  add.s $f10, $f6, $f8
  lw    $t8, ($t1)
  lui   $at, 0x4334
  swc1  $f10, ($t2)
  lw    $a0, 0xd4($t8)
  beql  $a0, $zero, .L7F07BEF4
   lwc1  $f6, ($t2)
  jal   sub_GAME_7F06F5BC
   nop   
  lui   $t1, %hi(pPlayer) 
  addiu $t1, %lo(pPlayer) # addiu $t1, $t1, -0x5f50
  lw    $t6, ($t1)
  swc1  $f0, 0x1c($sp)
  jal   sub_GAME_7F06F5C4
   lw    $a0, 0xd4($t6)
  lwc1  $f4, 0x1c($sp)
  lui   $t1, %hi(pPlayer) 
  addiu $t1, %lo(pPlayer) # addiu $t1, $t1, -0x5f50
  c.le.s $f0, $f4
  li    $t3, 1
  lui    $at, %hi(enable_move_after_cinema)
  bc1f  .L7F07BEE8
   nop   
  sw    $t3, %lo(enable_move_after_cinema)($at)
.L7F07BEE8:
  b     .L7F07BF10
   li    $a1, 2
  lwc1  $f6, ($t2)
.L7F07BEF4:
  mtc1  $at, $f8
  lui   $at, %hi(enable_move_after_cinema)
  c.le.s $f8, $f6
  nop   
  bc1fl .L7F07BF14
   lhu   $t4, 0x46($sp)
  sw    $t3, %lo(enable_move_after_cinema)($at)
.L7F07BF10:
  lhu   $t4, 0x46($sp)
.L7F07BF14:
  lhu   $t7, 0x42($sp)
  not   $t5, $t4
  and   $t9, $t7, $t5
  andi  $t8, $t9, 0xf000
  beqz  $t8, .L7F07C000
   nop   
  lw    $v0, ($t1)
  lw    $t6, 0xd8($v0)
  beqz  $t6, .L7F07C000
   nop   
  lw    $t4, 0x424($v0)
  beqz  $t4, .L7F07C000
   nop   
  lw    $t7, 0x428($v0)
  lui   $at, %hi(enable_move_after_cinema)
  beqz  $t7, .L7F07C000
   nop   
  sw    $t3, %lo(enable_move_after_cinema)($at)
  lui   $at, %hi(D_80036510)
  b     .L7F07C000
   sw    $a1, %lo(D_80036510)($at)
.L7F07BF68:
  li    $at, 6
  bne   $v0, $at, .L7F07C000
   lui   $t2, %hi(D_800364A4) 
  addiu $t2, %lo(D_800364A4) # addiu $t2, $t2, 0x64a4
  lui   $at, %hi(global_timer_delta)
  lwc1  $f4, %lo(global_timer_delta)($at)
  lwc1  $f10, ($t2)
  lui   $t1, %hi(pPlayer) 
  addiu $t1, %lo(pPlayer) # addiu $t1, $t1, -0x5f50
  add.s $f6, $f10, $f4
  lw    $v0, ($t1)
  mtc1  $zero, $f14
  lui   $at, %hi(enable_move_after_cinema)
  swc1  $f6, ($t2)
  lwc1  $f8, 0x3e4($v0)
  c.lt.s $f8, $f14
  nop   
  bc1fl .L7F07BFBC
   lhu   $t9, 0x46($sp)
  sw    $t3, %lo(enable_move_after_cinema)($at)
  lhu   $t9, 0x46($sp)
.L7F07BFBC:
  lhu   $t5, 0x42($sp)
  not   $t8, $t9
  and   $t6, $t5, $t8
  andi  $t4, $t6, 0xf000
  beqz  $t4, .L7F07C000
   nop   
  lw    $t7, 0xd8($v0)
  beqz  $t7, .L7F07C000
   nop   
  lw    $t9, 0x424($v0)
  beqz  $t9, .L7F07C000
   nop   
  lw    $t5, 0x428($v0)
  lui   $at, %hi(D_80036510)
  beqz  $t5, .L7F07C000
   nop   
  sw    $a1, %lo(D_80036510)($at)
.L7F07C000:
  lui   $v1, %hi(flt_CODE_bss_800799E8)
  addiu $v1, %lo(flt_CODE_bss_800799E8) # addiu $v1, $v1, -0x6618
  lwc1  $f10, ($v1)
  lw    $t8, 0x48($sp)
  lui   $t1, %hi(pPlayer) 
  addiu $t1, %lo(pPlayer) # addiu $t1, $t1, -0x5f50
  swc1  $f10, ($t8)
  lwc1  $f4, 4($v1)
  lui   $a1, %hi(dword_CODE_bss_800799F4)
  addiu $a1, %lo(dword_CODE_bss_800799F4) # addiu $a1, $a1, -0x660c
  swc1  $f4, 4($t8)
  lwc1  $f6, 8($v1)
  swc1  $f6, 8($t8)
  lw    $v0, ($t1)
  lw    $a0, ($a1)
  lw    $t6, 0xa8($v0)
  bnel  $a0, $t6, .L7F07C074
   lwc1  $f6, 8($a0)
  lwc1  $f8, 0x3c4($v0)
  lw    $t4, 0x4c($sp)
  swc1  $f8, ($t4)
  lw    $t7, ($t1)
  lwc1  $f10, 0x3c8($t7)
  swc1  $f10, 4($t4)
  lw    $t9, ($t1)
  lwc1  $f4, 0x3cc($t9)
  b     .L7F07C094
   swc1  $f4, 8($t4)
  lwc1  $f6, 8($a0)
.L7F07C074:
  lw    $t5, 0x4c($sp)
  swc1  $f6, ($t5)
  lw    $t8, ($a1)
  lwc1  $f8, 0xc($t8)
  swc1  $f8, 4($t5)
  lw    $t6, ($a1)
  lwc1  $f10, 0x10($t6)
  swc1  $f10, 8($t5)
.L7F07C094:
  lw    $t7, ($t1)
  lw    $t4, 0x54($sp)
  lw    $v1, 0x58($sp)
  lw    $t9, 0x488($t7)
  sw    $t9, ($t4)
  lw    $t8, ($t1)
  lwc1  $f4, 0x48c($t8)
  swc1  $f4, ($v1)
  lw    $t6, ($t1)
  lwc1  $f6, 0x490($t6)
  swc1  $f6, 4($v1)
  lw    $t5, ($t1)
  lwc1  $f8, 0x494($t5)
  b     .L7F07C530
   swc1  $f8, 8($v1)
  li    $at, 7
.L7F07C0D4:
  bne   $v0, $at, .L7F07C530
   lui   $v0, %hi(dword_CODE_bss_800799F8)
  addiu $v0, %lo(dword_CODE_bss_800799F8) # addiu $v0, $v0, -0x6608
  lw    $a0, ($v0)
  lw    $t7, 0x48($sp)
  beqz  $a0, .L7F07C17C
   nop   
  lwc1  $f10, ($a0)
  lw    $v1, 0x58($sp)
  lui   $t1, %hi(pPlayer) 
  swc1  $f10, ($t7)
  lw    $t9, ($v0)
  addiu $t1, %lo(pPlayer) # addiu $t1, $t1, -0x5f50
  lwc1  $f4, 4($t9)
  swc1  $f4, 4($t7)
  lw    $t4, ($v0)
  lwc1  $f6, 8($t4)
  swc1  $f6, 8($t7)
  lw    $t8, ($t1)
  lw    $t6, 0x4c($sp)
  lwc1  $f8, 0x3c4($t8)
  swc1  $f8, ($t6)
  lw    $t5, ($t1)
  lwc1  $f10, 0x3c8($t5)
  swc1  $f10, 4($t6)
  lw    $t9, ($t1)
  lwc1  $f4, 0x3cc($t9)
  swc1  $f4, 8($t6)
  lw    $t4, ($v0)
  lw    $t8, 0x54($sp)
  lw    $t7, 0x28($t4)
  sw    $t7, ($t8)
  lw    $t5, ($v0)
  lwc1  $f6, ($t5)
  swc1  $f6, ($v1)
  lw    $t9, ($v0)
  lwc1  $f8, 4($t9)
  swc1  $f8, 4($v1)
  lw    $t6, ($v0)
  lwc1  $f10, 8($t6)
  b     .L7F07C530
   swc1  $f10, 8($v1)
.L7F07C17C:
  lui   $a1, %hi(dword_CODE_bss_800799FC)
  addiu $a1, %lo(dword_CODE_bss_800799FC) # addiu $a1, $a1, -0x6604
  lw    $a0, ($a1)
  beqz  $a0, .L7F07C318
   nop   
  lw    $v1, 0x18($a0)
  lui   $t5, %hi(ptr_2xxxpresets) 
  lw    $t9, 0x48($sp)
  slti  $at, $v1, 0x2710
  beqz  $at, .L7F07C1CC
   sll   $t8, $v1, 4
  sll   $t4, $v1, 2
  subu  $t4, $t4, $v1
  sll   $t4, $t4, 2
  lui   $t7, %hi(ptr_0xxxpresets) 
  lw    $t7, %lo(ptr_0xxxpresets)($t7)
  subu  $t4, $t4, $v1
  sll   $t4, $t4, 2
  b     .L7F07C1E8
   addu  $v0, $t4, $t7
.L7F07C1CC:
  lw    $t5, %lo(ptr_2xxxpresets)($t5)
  addu  $t8, $t8, $v1
  sll   $t8, $t8, 2
  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
  addu  $v0, $t8, $t5
  addu  $v0, $v0, $at
.L7F07C1E8:
  lwc1  $f4, 4($a0)
  lw    $v1, 0x58($sp)
  lui   $t5, %hi(dword_CODE_bss_80079A18) 
  swc1  $f4, ($t9)
  lw    $t6, ($a1)
  lui   $t1, %hi(pPlayer) 
  addiu $t1, %lo(pPlayer) # addiu $t1, $t1, -0x5f50
  lwc1  $f6, 8($t6)
  swc1  $f6, 4($t9)
  lw    $t4, ($a1)
  lwc1  $f8, 0xc($t4)
  swc1  $f8, 8($t9)
  lw    $t8, 0x54($sp)
  lw    $t7, 0x28($v0)
  sw    $t7, ($t8)
  lwc1  $f10, ($v0)
  swc1  $f10, ($v1)
  lwc1  $f4, 4($v0)
  swc1  $f4, 4($v1)
  lwc1  $f6, 8($v0)
  swc1  $f6, 8($v1)
  lw    $t5, %lo(dword_CODE_bss_80079A18)($t5)
  bnel  $t3, $t5, .L7F07C278
   lw    $t8, ($a1)
  lw    $t6, ($t1)
  lw    $t4, 0x4c($sp)
  lwc1  $f8, 0x3c4($t6)
  swc1  $f8, ($t4)
  lw    $t9, ($t1)
  lwc1  $f10, 0x3c8($t9)
  swc1  $f10, 4($t4)
  lw    $t7, ($t1)
  lwc1  $f4, 0x3cc($t7)
  b     .L7F07C530
   swc1  $f4, 8($t4)
  lw    $t8, ($a1)
.L7F07C278:
  jal   cosf
   lwc1  $f12, 0x14($t8)
  lui   $t5, %hi(dword_CODE_bss_800799FC) 
  lw    $t5, %lo(dword_CODE_bss_800799FC)($t5)
  swc1  $f0, 0x1c($sp)
  jal   sinf
   lwc1  $f12, 0x10($t5)
  lwc1  $f6, 0x1c($sp)
  lw    $t6, 0x48($sp)
  lw    $t9, 0x4c($sp)
  mul.s $f8, $f0, $f6
  lwc1  $f10, ($t6)
  lui   $t7, %hi(dword_CODE_bss_800799FC) 
  add.s $f4, $f8, $f10
  swc1  $f4, ($t9)
  lw    $t7, %lo(dword_CODE_bss_800799FC)($t7)
  jal   sinf
   lwc1  $f12, 0x14($t7)
  lw    $t4, 0x48($sp)
  lw    $t8, 0x4c($sp)
  lui   $t5, %hi(dword_CODE_bss_800799FC) 
  lwc1  $f6, 4($t4)
  add.s $f8, $f0, $f6
  swc1  $f8, 4($t8)
  lw    $t5, %lo(dword_CODE_bss_800799FC)($t5)
  jal   cosf
   lwc1  $f12, 0x14($t5)
  lui   $t6, %hi(dword_CODE_bss_800799FC) 
  lw    $t6, %lo(dword_CODE_bss_800799FC)($t6)
  swc1  $f0, 0x1c($sp)
  jal   cosf
   lwc1  $f12, 0x10($t6)
  lwc1  $f4, 0x1c($sp)
  lw    $t9, 0x48($sp)
  lw    $t7, 0x4c($sp)
  mul.s $f6, $f0, $f4
  lwc1  $f10, 8($t9)
  sub.s $f8, $f10, $f6
  b     .L7F07C530
   swc1  $f8, 8($t7)
.L7F07C318:
  lui   $v0, %hi(dword_CODE_bss_80079A14)
  lw    $v0, %lo(dword_CODE_bss_80079A14)($v0)
  lui   $t6, %hi(ptr_2xxxpresets) 
  lw    $t7, 0x54($sp)
  slti  $at, $v0, 0x2710
  beqz  $at, .L7F07C358
   sll   $t5, $v0, 4
  sll   $t4, $v0, 2
  subu  $t4, $t4, $v0
  sll   $t4, $t4, 2
  lui   $t8, %hi(ptr_0xxxpresets) 
  lw    $t8, %lo(ptr_0xxxpresets)($t8)
  subu  $t4, $t4, $v0
  sll   $t4, $t4, 2
  b     .L7F07C374
   addu  $a0, $t4, $t8
.L7F07C358:
  lw    $t6, %lo(ptr_2xxxpresets)($t6)
  addu  $t5, $t5, $v0
  sll   $t5, $t5, 2
  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
  addu  $a0, $t5, $t6
  addu  $a0, $a0, $at
.L7F07C374:
  lw    $t9, 0x28($a0)
  lw    $v1, 0x58($sp)
  lui   $v0, %hi(flt_CODE_bss_80079A00)
  sw    $t9, ($t7)
  lwc1  $f4, ($a0)
  addiu $v0, %lo(flt_CODE_bss_80079A00) # addiu $v0, $v0, -0x6600
  swc1  $f4, ($v1)
  lwc1  $f10, 4($a0)
  swc1  $f10, 4($v1)
  lwc1  $f6, 8($a0)
  swc1  $f6, 8($v1)
  sw    $a0, 0x20($sp)
  jal   cosf
   lwc1  $f12, ($v0)
  lw    $a0, 0x20($sp)
  lw    $t4, 0x4c($sp)
  lui   $at, %hi(flt_CODE_bss_80079A10)
  lwc1  $f8, ($a0)
  lui   $v0, %hi(flt_CODE_bss_80079A00)
  addiu $v0, %lo(flt_CODE_bss_80079A00) # addiu $v0, $v0, -0x6600
  swc1  $f8, ($t4)
  lwc1  $f10, %lo(flt_CODE_bss_80079A10)($at)
  lwc1  $f4, 4($a0)
  add.s $f6, $f4, $f10
  swc1  $f6, 4($t4)
  jal   sinf
   lwc1  $f12, ($v0)
  lw    $a0, 0x20($sp)
  lw    $t8, 0x4c($sp)
  lui   $v0, %hi(flt_CODE_bss_80079A00)
  lwc1  $f8, 8($a0)
  addiu $v0, %lo(flt_CODE_bss_80079A00) # addiu $v0, $v0, -0x6600
  swc1  $f8, 8($t8)
  jal   sinf
   lwc1  $f12, ($v0)
  lui   $v0, %hi(flt_CODE_bss_80079A00)
  addiu $v0, %lo(flt_CODE_bss_80079A00) # addiu $v0, $v0, -0x6600
  lwc1  $f12, ($v0)
  jal   cosf
   swc1  $f0, 0x1c($sp)
  lui   $at, %hi(flt_CODE_bss_80079A08)
  lwc1  $f10, %lo(flt_CODE_bss_80079A08)($at)
  lwc1  $f4, 0x1c($sp)
  lw    $a0, 0x20($sp)
  lw    $t5, 0x48($sp)
  mul.s $f6, $f4, $f10
  lwc1  $f8, ($a0)
  lui   $at, %hi(flt_CODE_bss_80079A10)
  lui   $v0, %hi(flt_CODE_bss_80079A00)
  addiu $v0, %lo(flt_CODE_bss_80079A00) # addiu $v0, $v0, -0x6600
  add.s $f4, $f8, $f6
  swc1  $f4, ($t5)
  lwc1  $f8, %lo(flt_CODE_bss_80079A10)($at)
  lwc1  $f10, 4($a0)
  lui   $at, %hi(flt_CODE_bss_80079A0C)
  lwc1  $f4, %lo(flt_CODE_bss_80079A0C)($at)
  add.s $f6, $f10, $f8
  add.s $f10, $f6, $f4
  swc1  $f10, 4($t5)
  jal   cosf
   lwc1  $f12, ($v0)
  lui   $v0, %hi(flt_CODE_bss_80079A00)
  addiu $v0, %lo(flt_CODE_bss_80079A00) # addiu $v0, $v0, -0x6600
  lwc1  $f12, ($v0)
  jal   sinf
   swc1  $f0, 0x1c($sp)
  lui   $at, %hi(D_8005505C)
  lwc1  $f12, %lo(D_8005505C)($at)
  lui   $at, %hi(flt_CODE_bss_80079A08)
  lwc1  $f6, %lo(flt_CODE_bss_80079A08)($at)
  lwc1  $f8, 0x1c($sp)
  lw    $a0, 0x20($sp)
  lw    $t6, 0x48($sp)
  mul.s $f4, $f8, $f6
  lwc1  $f10, 8($a0)
  lui   $at, %hi(flt_CODE_bss_80079A04)
  lui   $v0, %hi(flt_CODE_bss_80079A00)
  addiu $v0, %lo(flt_CODE_bss_80079A00) # addiu $v0, $v0, -0x6600
  mtc1  $zero, $f14
  add.s $f8, $f10, $f4
  swc1  $f8, 8($t6)
  lwc1  $f6, %lo(flt_CODE_bss_80079A04)($at)
  lui   $at, %hi(global_timer_delta)
  lwc1  $f10, %lo(global_timer_delta)($at)
  lwc1  $f8, ($v0)
  mul.s $f4, $f6, $f10
  add.s $f6, $f8, $f4
  swc1  $f6, ($v0)
  lwc1  $f2, ($v0)
  c.le.s $f12, $f2
  nop   
  bc1fl .L7F07C508
   c.lt.s $f2, $f14
  sub.s $f10, $f2, $f12
.L7F07C4EC:
  swc1  $f10, ($v0)
  lwc1  $f2, ($v0)
  c.le.s $f12, $f2
  nop   
  bc1tl .L7F07C4EC
   sub.s $f10, $f2, $f12
  c.lt.s $f2, $f14
.L7F07C508:
  nop   
  bc1fl .L7F07C534
   lw    $ra, 0x14($sp)
  add.s $f8, $f2, $f12
.L7F07C518:
  swc1  $f8, ($v0)
  lwc1  $f2, ($v0)
  c.lt.s $f2, $f14
  nop   
  bc1tl .L7F07C518
   add.s $f8, $f2, $f12
.L7F07C530:
  lw    $ra, 0x14($sp)
.L7F07C534:
  addiu $sp, $sp, 0x40
  jr    $ra
   nop   
");
#endif

#ifdef VERSION_JP
asm(R"
.late_rodata
glabel D_80055044
.word 0x43338000 /*179.5*/
glabel D_80055048
.word 0x3dcccccd /*0.1*/
glabel D_8005504C
.word 0x3c75c28f /*0.015*/
glabel D_80055050
.word 0x40490fdb /*3.1415927*/
glabel D_80055054
.word 0x3da3d70a /*0.079999998*/
glabel D_80055058
.word 0x3da3d70a /*0.079999998*/
glabel D_8005505C
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F07B56C
  addiu $sp, $sp, -0x40
  lui   $v0, %hi(cameramode) # $v0, 0x8003
  lw    $v0, %lo(cameramode)($v0)
  li    $t3, 1
  sw    $ra, 0x14($sp)
  sw    $a0, 0x40($sp)
  sw    $a1, 0x44($sp)
  sw    $a2, 0x48($sp)
  beq   $t3, $v0, .Ljp7F07BBC0
   sw    $a3, 0x4c($sp)
  li    $a1, 2
  bne   $a1, $v0, .Ljp7F07BE7C
   li    $at, 9
.Ljp7F07BBC0:
  bne   $t3, $v0, .Ljp7F07BD2C
   lui   $t1, %hi(pPlayer) # $t1, 0x8008
  lui   $t2, %hi(D_800364A4) # $t2, 0x8003
  addiu $t2, %lo(D_800364A4) # addiu $t2, $t2, 0x64e4
  li    $at, 0x42F00000 # 120.000000
  mtc1  $at, $f0
  lwc1  $f2, ($t2)
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  c.lt.s $f2, $f0
  nop   
  bc1f  .Ljp7F07BC38
   nop   
  lwc1  $f4, %lo(global_timer_delta)($at)
  lui   $t6, %hi(ptr_random06cam_entry) # $t6, 0x8003
  lui   $a1, %hi(ptrSecondFontTableLarge) # $a1, 0x8004
  add.s $f6, $f2, $f4
  lui   $a2, %hi(ptrFirstFontTableLarge) # $a2, 0x8004
  c.le.s $f0, $f6
  nop   
  bc1f  .Ljp7F07BC38
   nop   
  lw    $t6, %lo(ptr_random06cam_entry)($t6)
  lw    $a1, %lo(ptrSecondFontTableLarge)($a1)
  lw    $a2, %lo(ptrFirstFontTableLarge)($a2)
  jal   display_string_in_lower_left_corner
   lw    $a0, 0x1c($t6)
  lui   $t2, %hi(D_800364A4) # $t2, 0x8003
  addiu $t2, %lo(D_800364A4) # addiu $t2, $t2, 0x64e4
  lwc1  $f2, ($t2)
  li    $t3, 1
.Ljp7F07BC38:
  lui   $t7, %hi(ptr_random06cam_entry) # $t7, 0x8003
  lw    $t7, %lo(ptr_random06cam_entry)($t7)
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  lwc1  $f8, %lo(global_timer_delta)($at)
  lw    $a0, 0x20($t7)
  li    $at, 0x43960000 # 300.000000
  add.s $f0, $f2, $f8
  beql  $a0, $zero, .Ljp7F07BCDC
   mtc1  $at, $f12
  li    $at, 0x43960000 # 300.000000
  mtc1  $at, $f12
  nop   
  c.lt.s $f2, $f12
  nop   
  bc1fl .Ljp7F07BCB8
   lui   $at, 0x43f0
  c.le.s $f12, $f0
  lui   $a1, %hi(ptrSecondFontTableLarge) # $a1, 0x8004
  lui   $a2, %hi(ptrFirstFontTableLarge) # $a2, 0x8004
  bc1fl .Ljp7F07BCB8
   lui   $at, 0x43f0
  lw    $a1, %lo(ptrSecondFontTableLarge)($a1)
  jal   display_string_in_lower_left_corner
   lw    $a2, %lo(ptrFirstFontTableLarge)($a2)
  lui   $t2, %hi(D_800364A4) # $t2, 0x8003
  addiu $t2, %lo(D_800364A4) # addiu $t2, $t2, 0x64e4
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  lwc1  $f10, %lo(global_timer_delta)($at)
  lwc1  $f2, ($t2)
  li    $t3, 1
  add.s $f0, $f2, $f10
  li    $at, 0x43F00000 # 480.000000
.Ljp7F07BCB8:
  mtc1  $at, $f4
  lui   $at, %hi(enable_move_after_cinema) # $at, 0x8003
  c.lt.s $f4, $f2
  nop   
  bc1f  .Ljp7F07BCF4
   nop   
  b     .Ljp7F07BCF4
   sw    $t3, %lo(enable_move_after_cinema)($at)
  mtc1  $at, $f12
.Ljp7F07BCDC:
  lui   $at, %hi(enable_move_after_cinema) # $at, 0x8003
  c.lt.s $f12, $f2
  nop   
  bc1f  .Ljp7F07BCF4
   nop   
  sw    $t3, %lo(enable_move_after_cinema)($at)
.Ljp7F07BCF4:
  jal   get_controls_locked_flag
   swc1  $f0, ($t2)
  bnez  $v0, .Ljp7F07BD54
   li    $t3, 1
  lhu   $t9, 0x46($sp)
  lhu   $t8, 0x42($sp)
  lui   $at, %hi(enable_move_after_cinema) # $at, 0x8003
  not   $t4, $t9
  and   $t5, $t8, $t4
  andi  $t6, $t5, 0xf030
  beqz  $t6, .Ljp7F07BD54
   nop   
  b     .Ljp7F07BD54
   sw    $t3, %lo(enable_move_after_cinema)($at)
.Ljp7F07BD2C:
  addiu $t1, %lo(pPlayer) # addiu $t1, $t1, -0x5ee0
  lw    $t7, ($t1)
  mtc1  $zero, $f14
  lui   $at, %hi(enable_move_after_cinema) # $at, 0x8003
  lwc1  $f6, 0x3e4($t7)
  c.lt.s $f6, $f14
  nop   
  bc1f  .Ljp7F07BD54
   nop   
  sw    $t3, %lo(enable_move_after_cinema)($at)
.Ljp7F07BD54:
  lui   $v0, %hi(ptr_random06cam_entry) # $v0, 0x8003
  addiu $v0, %lo(ptr_random06cam_entry) # addiu $v0, $v0, 0x6500
  lw    $t9, ($v0)
  lw    $t8, 0x48($sp)
  lwc1  $f8, 4($t9)
  swc1  $f8, ($t8)
  lw    $t4, ($v0)
  lwc1  $f10, 8($t4)
  swc1  $f10, 4($t8)
  lw    $t5, ($v0)
  lwc1  $f4, 0xc($t5)
  swc1  $f4, 8($t8)
  lw    $t6, ($v0)
  jal   cosf
   lwc1  $f12, 0x14($t6)
  lui   $t7, %hi(ptr_random06cam_entry) # $t7, 0x8003
  lw    $t7, %lo(ptr_random06cam_entry)($t7)
  swc1  $f0, 0x1c($sp)
  jal   sinf
   lwc1  $f12, 0x10($t7)
  lwc1  $f6, 0x1c($sp)
  lw    $t9, 0x48($sp)
  lw    $t4, 0x4c($sp)
  mul.s $f8, $f0, $f6
  lwc1  $f10, ($t9)
  lui   $t5, %hi(ptr_random06cam_entry) # $t5, 0x8003
  add.s $f4, $f8, $f10
  swc1  $f4, ($t4)
  lw    $t5, %lo(ptr_random06cam_entry)($t5)
  jal   sinf
   lwc1  $f12, 0x14($t5)
  lw    $t8, 0x48($sp)
  lw    $t6, 0x4c($sp)
  lui   $t7, %hi(ptr_random06cam_entry) # $t7, 0x8003
  lwc1  $f6, 4($t8)
  add.s $f8, $f0, $f6
  swc1  $f8, 4($t6)
  lw    $t7, %lo(ptr_random06cam_entry)($t7)
  jal   cosf
   lwc1  $f12, 0x14($t7)
  lui   $t9, %hi(ptr_random06cam_entry) # $t9, 0x8003
  lw    $t9, %lo(ptr_random06cam_entry)($t9)
  swc1  $f0, 0x1c($sp)
  jal   cosf
   lwc1  $f12, 0x10($t9)
  lwc1  $f4, 0x1c($sp)
  lw    $t4, 0x48($sp)
  lw    $t5, 0x4c($sp)
  mul.s $f6, $f0, $f4
  lwc1  $f10, 8($t4)
  lw    $v1, 0x58($sp)
  lui   $t8, %hi(ptr_random06cam_entry) # $t8, 0x8003
  lui   $t9, %hi(ptr_0xxxpresets) # $t9, 0x8007
  sub.s $f8, $f10, $f6
  swc1  $f8, 8($t5)
  lw    $t8, %lo(ptr_random06cam_entry)($t8)
  lw    $t9, %lo(ptr_0xxxpresets)($t9)
  lw    $t5, 0x54($sp)
  lw    $t6, 0x18($t8)
  sll   $t7, $t6, 2
  subu  $t7, $t7, $t6
  sll   $t7, $t7, 2
  subu  $t7, $t7, $t6
  sll   $t7, $t7, 2
  addu  $v0, $t7, $t9
  lw    $t4, 0x28($v0)
  sw    $t4, ($t5)
  lwc1  $f4, ($v0)
  swc1  $f4, ($v1)
  lwc1  $f10, 4($v0)
  swc1  $f10, 4($v1)
  lwc1  $f6, 8($v0)
  b     .Ljp7F07CB54
   swc1  $f6, 8($v1)
.Ljp7F07BE7C:
  bnel  $v0, $at, .Ljp7F07C14C
   li    $at, 3
  jal   get_cur_playernum
   nop   
  jal   sub_GAME_7F09B4D8
   move  $a0, $v0
  bnez  $v0, .Ljp7F07BFE8
   lui   $t1, %hi(pPlayer) # $t1, 0x8008
  lui   $a3, %hi(clock_timer) # $a3, 0x8005
  lw    $a3, %lo(clock_timer)($a3)
  move  $v1, $zero
  lui   $at, %hi(flt_CODE_bss_80079E08) # $at, 0x8008
  blez  $a3, .Ljp7F07BFE8
   lui   $a2, %hi(flt_CODE_bss_80079E04) # $a2, 0x8008
  lwc1  $f12, %lo(flt_CODE_bss_80079E08)($at)
  lui   $at, %hi(D_80055044) # $at, 0x8005
  lwc1  $f18, %lo(D_80055044)($at)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f16
  lui    $at, %hi(D_80055048)
  lui   $a1, %hi(flt_CODE_bss_80079E0C) # $a1, 0x8008
  lui   $a0, %hi(flt_CODE_bss_80079E08) # $a0, 0x8008
  lui   $v0, %hi(flt_CODE_bss_80079E10) # $v0, 0x8008
  addiu $v0, %lo(flt_CODE_bss_80079E10) # addiu $v0, $v0, -0x6180
  addiu $a0, %lo(flt_CODE_bss_80079E08) # addiu $a0, $a0, -0x6188
  addiu $a1, %lo(flt_CODE_bss_80079E0C) # addiu $a1, $a1, -0x6184
  lwc1  $f14, %lo(D_80055048)($at)
  addiu $a2, %lo(flt_CODE_bss_80079E04) # addiu $a2, $a2, -0x618c
  c.lt.s $f12, $f18
.Ljp7F07BEF0:
  addiu $v1, $v1, 1
  li    $at, 0x43340000 # 180.000000
  bc1fl .Ljp7F07BF58
   mtc1  $at, $f4
  li    $at, 0xC1A00000 # -20.000000
  mtc1  $at, $f8
  li    $at, 0x42DC0000 # 110.000000
  mtc1  $at, $f10
  c.lt.s $f12, $f8
  lwc1  $f0, ($a2)
  bc1fl .Ljp7F07BF30
   c.lt.s $f10, $f12
  add.s $f4, $f0, $f14
  swc1  $f4, ($a2)
  lwc1  $f0, ($a2)
  c.lt.s $f10, $f12
.Ljp7F07BF30:
  nop   
  bc1fl .Ljp7F07BF4C
   add.s $f8, $f12, $f0
  sub.s $f6, $f0, $f14
  swc1  $f6, ($a2)
  lwc1  $f0, ($a2)
  add.s $f8, $f12, $f0
.Ljp7F07BF4C:
  b     .Ljp7F07BF60
   swc1  $f8, ($a0)
  mtc1  $at, $f4
.Ljp7F07BF58:
  nop   
  swc1  $f4, ($a0)
.Ljp7F07BF60:
  li    $at, 0x42A00000 # 80.000000
  mtc1  $at, $f10
  lwc1  $f12, ($a0)
  li    $at, 0x42700000 # 60.000000
  c.lt.s $f10, $f12
  nop   
  bc1fl .Ljp7F07BFE0
   slt   $at, $v1, $a3
  lwc1  $f0, ($v0)
  mtc1  $at, $f6
  lwc1  $f2, ($a1)
  lui   $at, %hi(D_8005504C) # $at, 0x8005
  c.lt.s $f6, $f0
  nop   
  bc1f  .Ljp7F07BFAC
   nop   
  sub.s $f8, $f2, $f14
  b     .Ljp7F07BFB8
   swc1  $f8, ($a1)
.Ljp7F07BFAC:
  lwc1  $f4, %lo(D_8005504C)($at)
  add.s $f10, $f2, $f4
  swc1  $f10, ($a1)
.Ljp7F07BFB8:
  lwc1  $f6, ($a1)
  add.s $f8, $f0, $f6
  swc1  $f8, ($v0)
  lwc1  $f4, ($v0)
  c.lt.s $f4, $f16
  nop   
  bc1fl .Ljp7F07BFE0
   slt   $at, $v1, $a3
  swc1  $f16, ($v0)
  slt   $at, $v1, $a3
.Ljp7F07BFE0:
  bnezl $at, .Ljp7F07BEF0
   c.lt.s $f12, $f18
.Ljp7F07BFE8:
  addiu $t1, %lo(pPlayer) # addiu $t1, $t1, -0x5ee0
  lw    $t8, ($t1)
  lui   $a0, %hi(flt_CODE_bss_80079E08) # $a0, 0x8008
  addiu $a0, %lo(flt_CODE_bss_80079E08) # addiu $a0, $a0, -0x6188
  lwc1  $f10, ($a0)
  lwc1  $f6, 0x148($t8)
  lui   $at, %hi(D_80055050) # $at, 0x8005
  lwc1  $f4, %lo(D_80055050)($at)
  sub.s $f8, $f10, $f6
  li    $at, 0x43340000 # 180.000000
  mtc1  $at, $f6
  mul.s $f10, $f8, $f4
  div.s $f12, $f10, $f6
  jal   sinf
   swc1  $f12, 0x38($sp)
  lui   $v0, %hi(flt_CODE_bss_80079E10) # $v0, 0x8008
  addiu $v0, %lo(flt_CODE_bss_80079E10) # addiu $v0, $v0, -0x6180
  lwc1  $f8, ($v0)
  lui   $t1, %hi(pPlayer) # $t1, 0x8008
  addiu $t1, %lo(pPlayer) # addiu $t1, $t1, -0x5ee0
  mul.s $f4, $f0, $f8
  lw    $t6, ($t1)
  lw    $v1, 0x48($sp)
  lwc1  $f12, 0x38($sp)
  lwc1  $f10, 0x4b4($t6)
  lui   $at, %hi(D_80055054) # $at, 0x8005
  add.s $f6, $f4, $f10
  swc1  $f6, ($v1)
  lwc1  $f4, %lo(D_80055054)($at)
  lwc1  $f8, ($v0)
  lw    $t7, ($t1)
  mul.s $f10, $f8, $f4
  lwc1  $f6, 0x4b8($t7)
  add.s $f8, $f6, $f10
  jal   cosf
   swc1  $f8, 4($v1)
  lui   $v0, %hi(flt_CODE_bss_80079E10) # $v0, 0x8008
  addiu $v0, %lo(flt_CODE_bss_80079E10) # addiu $v0, $v0, -0x6180
  lwc1  $f4, ($v0)
  lui   $t1, %hi(pPlayer) # $t1, 0x8008
  addiu $t1, %lo(pPlayer) # addiu $t1, $t1, -0x5ee0
  mul.s $f6, $f0, $f4
  lw    $t9, ($t1)
  lw    $t4, 0x48($sp)
  lw    $v1, 0x58($sp)
  lwc1  $f10, 0x4bc($t9)
  lw    $a0, 0x4c($sp)
  lui   $at, %hi(D_80055058) # $at, 0x8005
  add.s $f8, $f6, $f10
  li    $t3, 1
  swc1  $f8, 8($t4)
  lw    $t5, ($t1)
  lwc1  $f4, 0x4b4($t5)
  swc1  $f4, ($a0)
  lw    $t8, ($t1)
  lwc1  $f6, 0x4b8($t8)
  swc1  $f6, 4($a0)
  lw    $t6, ($t1)
  lwc1  $f10, 0x4bc($t6)
  swc1  $f10, 8($a0)
  lw    $t7, ($t1)
  lw    $t5, 0x54($sp)
  lw    $t9, 0xa8($t7)
  lw    $t4, 0x14($t9)
  sw    $t4, ($t5)
  lw    $t8, ($t1)
  lwc1  $f8, 0x4b4($t8)
  swc1  $f8, ($v1)
  lwc1  $f4, ($v0)
  lwc1  $f6, %lo(D_80055058)($at)
  lw    $t6, ($t1)
  li    $at, 0x40A00000 # 5.000000
  mul.s $f10, $f4, $f6
  lwc1  $f8, 0x4b8($t6)
  add.s $f4, $f8, $f10
  mtc1  $at, $f10
  lui   $at, %hi(enable_move_after_cinema) # $at, 0x8003
  swc1  $f4, 4($v1)
  lw    $t7, ($t1)
  lwc1  $f6, 0x4bc($t7)
  swc1  $f6, 8($v1)
  lwc1  $f8, ($v0)
  c.lt.s $f8, $f10
  nop   
  bc1fl .Ljp7F07CB58
   lw    $ra, 0x14($sp)
  b     .Ljp7F07CB54
   sw    $t3, %lo(enable_move_after_cinema)($at)
  li    $at, 3
.Ljp7F07C14C:
  bne   $v0, $at, .Ljp7F07C47C
   li    $v1, 5
  lui   $t2, %hi(D_800364A4) # $t2, 0x8003
  addiu $t2, %lo(D_800364A4) # addiu $t2, $t2, 0x64e4
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  lwc1  $f18, %lo(global_timer_delta)($at)
  lwc1  $f4, ($t2)
  lui   $t0, %hi(D_800364A8) # $t0, 0x8003
  addiu $t0, %lo(D_800364A8) # addiu $t0, $t0, 0x64e8
  add.s $f6, $f4, $f18
  lw    $v1, ($t0)
  lui   $a0, %hi(D_800364AC) # $a0, 0x8003
  lui   $at, %hi(enable_move_after_cinema) # $at, 0x8003
  swc1  $f6, ($t2)
  lw    $a0, %lo(D_800364AC)($a0)
  sll   $t9, $v1, 5
  lwc1  $f2, ($t2)
  addu  $v0, $a0, $t9
  lwc1  $f0, 0x18($v0)
  c.le.s $f0, $f2
  nop   
  bc1fl .Ljp7F07C208
   addiu $a1, $v1, 1
  lw    $t4, 0x64($v0)
.Ljp7F07C1AC:
  andi  $t5, $t4, 1
  bnezl $t5, .Ljp7F07C1D0
   swc1  $f0, ($t2)
  sub.s $f8, $f2, $f0
  addiu $t8, $v1, 1
  sw    $t8, ($t0)
  b     .Ljp7F07C1E0
   swc1  $f8, ($t2)
  swc1  $f0, ($t2)
.Ljp7F07C1D0:
  sw    $t3, %lo(enable_move_after_cinema)($at)
  lwc1  $f0, 0x18($v0)
  b     .Ljp7F07C204
   lwc1  $f2, ($t2)
.Ljp7F07C1E0:
  lw    $v1, ($t0)
  lwc1  $f2, ($t2)
  sll   $t6, $v1, 5
  addu  $v0, $a0, $t6
  lwc1  $f0, 0x18($v0)
  c.le.s $f0, $f2
  nop   
  bc1tl .Ljp7F07C1AC
   lw    $t4, 0x64($v0)
.Ljp7F07C204:
  addiu $a1, $v1, 1
.Ljp7F07C208:
  sll   $t7, $a1, 5
  addu  $v0, $a0, $t7
  lw    $t9, 0x44($v0)
  sub.s $f10, $f0, $f2
  mtc1  $zero, $f14
  andi  $t4, $t9, 1
  bnez  $t4, .Ljp7F07C240
   add.s $f16, $f14, $f10
.Ljp7F07C228:
  lw    $t5, 0x64($v0)
  lwc1  $f4, 0x18($v0)
  addiu $v0, $v0, 0x20
  andi  $t8, $t5, 1
  beqz  $t8, .Ljp7F07C228
   add.s $f16, $f16, $f4
.Ljp7F07C240:
  li    $at, 0x41F00000 # 30.000000
  mtc1  $at, $f12
  nop   
  c.lt.s $f16, $f12
  nop   
  bc1f  .Ljp7F07C28C
   nop   
  add.s $f6, $f16, $f18
  c.le.s $f12, $f6
  nop   
  bc1f  .Ljp7F07C28C
   nop   
  jal   set_curplayer_fade
   swc1  $f16, 0x30($sp)
  lui   $t0, %hi(D_800364A8) # $t0, 0x8003
  lui   $t2, %hi(D_800364A4) # $t2, 0x8003
  addiu $t2, %lo(D_800364A4) # addiu $t2, $t2, 0x64e4
  addiu $t0, %lo(D_800364A8) # addiu $t0, $t0, 0x64e8
  lwc1  $f16, 0x30($sp)
.Ljp7F07C28C:
  lui   $t6, %hi(D_8003649C) # $t6, 0x8003
  lw    $t6, %lo(D_8003649C)($t6)
  beql  $t6, $zero, .Ljp7F07C2CC
   lui   $at, 0x4270
  jal   check_if_fade_to_black_complete
   swc1  $f16, 0x30($sp)
  lui   $t0, %hi(D_800364A8) # $t0, 0x8003
  lui   $t2, %hi(D_800364A4) # $t2, 0x8003
  addiu $t2, %lo(D_800364A4) # addiu $t2, $t2, 0x64e4
  addiu $t0, %lo(D_800364A8) # addiu $t0, $t0, 0x64e8
  li    $t3, 1
  beqz  $v0, .Ljp7F07C2C8
   lwc1  $f16, 0x30($sp)
  lui   $at, %hi(enable_move_after_cinema) # $at, 0x8003
  sw    $t3, %lo(enable_move_after_cinema)($at)
.Ljp7F07C2C8:
  li    $at, 0x42700000 # 60.000000
.Ljp7F07C2CC:
  mtc1  $at, $f8
  lui   $t7, %hi(D_8003649C) # $t7, 0x8003
  c.lt.s $f8, $f16
  nop   
  bc1fl .Ljp7F07C3B8
   lw    $a0, ($t0)
  lw    $t7, %lo(D_8003649C)($t7)
  bnezl $t7, .Ljp7F07C3B8
   lw    $a0, ($t0)
  jal   get_controls_locked_flag
   nop   
  lui   $t0, %hi(D_800364A8) # $t0, 0x8003
  lui   $t2, %hi(D_800364A4) # $t2, 0x8003
  addiu $t2, %lo(D_800364A4) # addiu $t2, $t2, 0x64e4
  addiu $t0, %lo(D_800364A8) # addiu $t0, $t0, 0x64e8
  bnez  $v0, .Ljp7F07C3B4
   li    $t3, 1
  lhu   $t4, 0x46($sp)
  lhu   $t9, 0x42($sp)
  lui   $t1, %hi(pPlayer) # $t1, 0x8008
  not   $t5, $t4
  and   $t8, $t9, $t5
  andi  $t6, $t8, 0xf030
  beqz  $t6, .Ljp7F07C3B4
   addiu $t1, %lo(pPlayer) # addiu $t1, $t1, -0x5ee0
  lui   $at, %hi(D_8003649C) # $at, 0x8003
  sw    $t3, %lo(D_8003649C)($at)
  lw    $t7, ($t1)
  move  $a0, $zero
  move  $a1, $zero
  move  $a2, $zero
  jal   set_rgba_tint
   lw    $a3, 0x3dc($t7)
  jal   check_if_fade_to_black_complete
   nop   
  lui   $t1, %hi(pPlayer) # $t1, 0x8008
  beqz  $v0, .Ljp7F07C390
   addiu $t1, %lo(pPlayer) # addiu $t1, $t1, -0x5ee0
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f12
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f14
  jal   fade_to_over_seconds
   nop   
  lui   $t0, %hi(D_800364A8) # $t0, 0x8003
  lui   $t2, %hi(D_800364A4) # $t2, 0x8003
  addiu $t2, %lo(D_800364A4) # addiu $t2, $t2, 0x64e4
  b     .Ljp7F07C3B4
   addiu $t0, %lo(D_800364A8) # addiu $t0, $t0, 0x64e8
.Ljp7F07C390:
  lw    $t4, ($t1)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f14
  jal   fade_to_over_seconds
   lwc1  $f12, 0x3e0($t4)
  lui   $t0, %hi(D_800364A8) # $t0, 0x8003
  lui   $t2, %hi(D_800364A4) # $t2, 0x8003
  addiu $t2, %lo(D_800364A4) # addiu $t2, $t2, 0x64e4
  addiu $t0, %lo(D_800364A8) # addiu $t0, $t0, 0x64e8
.Ljp7F07C3B4:
  lw    $a0, ($t0)
.Ljp7F07C3B8:
  lw    $a1, ($t2)
  lw    $a2, 0x48($sp)
  jal   sub_GAME_7F07B2A0
   lw    $a3, 0x4c($sp)
  lui   $t0, %hi(D_800364A8) # $t0, 0x8003
  addiu $t0, %lo(D_800364A8) # addiu $t0, $t0, 0x64e8
  lw    $t5, ($t0)
  lui   $t9, %hi(D_800364AC) # $t9, 0x8003
  lw    $t9, %lo(D_800364AC)($t9)
  sll   $t8, $t5, 5
  lui   $t1, %hi(pPlayer) # $t1, 0x8008
  addu  $t6, $t9, $t8
  lw    $a0, 0x1c($t6)
  addiu $t1, %lo(pPlayer) # addiu $t1, $t1, -0x5ee0
  lui   $t4, %hi(ptr_0xxxpresets) # $t4, 0x8007
  bltz  $a0, .Ljp7F07C440
   sll   $t7, $a0, 2
  subu  $t7, $t7, $a0
  lw    $t4, %lo(ptr_0xxxpresets)($t4)
  sll   $t7, $t7, 2
  subu  $t7, $t7, $a0
  sll   $t7, $t7, 2
  addu  $v0, $t7, $t4
  lw    $t5, 0x28($v0)
  lw    $t9, 0x54($sp)
  lw    $v1, 0x58($sp)
  sw    $t5, ($t9)
  lwc1  $f10, ($v0)
  swc1  $f10, ($v1)
  lwc1  $f4, 4($v0)
  swc1  $f4, 4($v1)
  lwc1  $f6, 8($v0)
  b     .Ljp7F07CB54
   swc1  $f6, 8($v1)
.Ljp7F07C440:
  lw    $t8, ($t1)
  lw    $t7, 0x54($sp)
  lw    $v1, 0x58($sp)
  lw    $t6, 0x488($t8)
  sw    $t6, ($t7)
  lw    $t4, ($t1)
  lwc1  $f8, 0x48c($t4)
  swc1  $f8, ($v1)
  lw    $t5, ($t1)
  lwc1  $f10, 0x490($t5)
  swc1  $f10, 4($v1)
  lw    $t9, ($t1)
  lwc1  $f4, 0x494($t9)
  b     .Ljp7F07CB54
   swc1  $f4, 8($v1)
.Ljp7F07C47C:
  beq   $v1, $v0, .Ljp7F07C48C
   li    $at, 6
  bnel  $v0, $at, .Ljp7F07C6F8
   li    $at, 7
.Ljp7F07C48C:
  bne   $v1, $v0, .Ljp7F07C58C
   lui   $t2, %hi(D_800364A4) # $t2, 0x8003
  addiu $t2, %lo(D_800364A4) # addiu $t2, $t2, 0x64e4
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  lwc1  $f8, %lo(global_timer_delta)($at)
  lwc1  $f6, ($t2)
  lui   $t1, %hi(pPlayer) # $t1, 0x8008
  addiu $t1, %lo(pPlayer) # addiu $t1, $t1, -0x5ee0
  add.s $f10, $f6, $f8
  lw    $t8, ($t1)
  lui   $at, 0x4334
  swc1  $f10, ($t2)
  lw    $a0, 0xd4($t8)
  beql  $a0, $zero, .Ljp7F07C518
   lwc1  $f6, ($t2)
  jal   sub_GAME_7F06F5BC
   nop   
  lui   $t1, %hi(pPlayer) # $t1, 0x8008
  addiu $t1, %lo(pPlayer) # addiu $t1, $t1, -0x5ee0
  lw    $t6, ($t1)
  swc1  $f0, 0x1c($sp)
  jal   sub_GAME_7F06F5C4
   lw    $a0, 0xd4($t6)
  lwc1  $f4, 0x1c($sp)
  lui   $t1, %hi(pPlayer) # $t1, 0x8008
  addiu $t1, %lo(pPlayer) # addiu $t1, $t1, -0x5ee0
  c.le.s $f0, $f4
  li    $t3, 1
  lui    $at, %hi(enable_move_after_cinema)
  bc1f  .Ljp7F07C50C
   nop   
  sw    $t3, %lo(enable_move_after_cinema)($at)
.Ljp7F07C50C:
  b     .Ljp7F07C534
   li    $a1, 2
  lwc1  $f6, ($t2)
.Ljp7F07C518:
  mtc1  $at, $f8
  lui   $at, %hi(enable_move_after_cinema) # $at, 0x8003
  c.le.s $f8, $f6
  nop   
  bc1fl .Ljp7F07C538
   lhu   $t4, 0x46($sp)
  sw    $t3, %lo(enable_move_after_cinema)($at)
.Ljp7F07C534:
  lhu   $t4, 0x46($sp)
.Ljp7F07C538:
  lhu   $t7, 0x42($sp)
  not   $t5, $t4
  and   $t9, $t7, $t5
  andi  $t8, $t9, 0xf000
  beqz  $t8, .Ljp7F07C624
   nop   
  lw    $v0, ($t1)
  lw    $t6, 0xd8($v0)
  beqz  $t6, .Ljp7F07C624
   nop   
  lw    $t4, 0x424($v0)
  beqz  $t4, .Ljp7F07C624
   nop   
  lw    $t7, 0x428($v0)
  lui   $at, %hi(enable_move_after_cinema) # $at, 0x8003
  beqz  $t7, .Ljp7F07C624
   nop   
  sw    $t3, %lo(enable_move_after_cinema)($at)
  lui   $at, %hi(D_80036510) # $at, 0x8003
  b     .Ljp7F07C624
   sw    $a1, %lo(D_80036510)($at)
.Ljp7F07C58C:
  li    $at, 6
  bne   $v0, $at, .Ljp7F07C624
   lui   $t2, %hi(D_800364A4) # $t2, 0x8003
  addiu $t2, %lo(D_800364A4) # addiu $t2, $t2, 0x64e4
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  lwc1  $f4, %lo(global_timer_delta)($at)
  lwc1  $f10, ($t2)
  lui   $t1, %hi(pPlayer) # $t1, 0x8008
  addiu $t1, %lo(pPlayer) # addiu $t1, $t1, -0x5ee0
  add.s $f6, $f10, $f4
  lw    $v0, ($t1)
  mtc1  $zero, $f14
  lui   $at, %hi(enable_move_after_cinema) # $at, 0x8003
  swc1  $f6, ($t2)
  lwc1  $f8, 0x3e4($v0)
  c.lt.s $f8, $f14
  nop   
  bc1fl .Ljp7F07C5E0
   lhu   $t9, 0x46($sp)
  sw    $t3, %lo(enable_move_after_cinema)($at)
  lhu   $t9, 0x46($sp)
.Ljp7F07C5E0:
  lhu   $t5, 0x42($sp)
  not   $t8, $t9
  and   $t6, $t5, $t8
  andi  $t4, $t6, 0xf000
  beqz  $t4, .Ljp7F07C624
   nop   
  lw    $t7, 0xd8($v0)
  beqz  $t7, .Ljp7F07C624
   nop   
  lw    $t9, 0x424($v0)
  beqz  $t9, .Ljp7F07C624
   nop   
  lw    $t5, 0x428($v0)
  lui   $at, %hi(D_80036510) # $at, 0x8003
  beqz  $t5, .Ljp7F07C624
   nop   
  sw    $a1, %lo(D_80036510)($at)
.Ljp7F07C624:
  lui   $v1, %hi(flt_CODE_bss_800799E8) # $v1, 0x8008
  addiu $v1, %lo(flt_CODE_bss_800799E8) # addiu $v1, $v1, -0x65d8
  lwc1  $f10, ($v1)
  lw    $t8, 0x48($sp)
  lui   $t1, %hi(pPlayer) # $t1, 0x8008
  addiu $t1, %lo(pPlayer) # addiu $t1, $t1, -0x5ee0
  swc1  $f10, ($t8)
  lwc1  $f4, 4($v1)
  lui   $a1, %hi(dword_CODE_bss_800799F4) # $a1, 0x8008
  addiu $a1, %lo(dword_CODE_bss_800799F4) # addiu $a1, $a1, -0x65cc
  swc1  $f4, 4($t8)
  lwc1  $f6, 8($v1)
  swc1  $f6, 8($t8)
  lw    $v0, ($t1)
  lw    $a0, ($a1)
  lw    $t6, 0xa8($v0)
  bnel  $a0, $t6, .Ljp7F07C698
   lwc1  $f6, 8($a0)
  lwc1  $f8, 0x3c4($v0)
  lw    $t4, 0x4c($sp)
  swc1  $f8, ($t4)
  lw    $t7, ($t1)
  lwc1  $f10, 0x3c8($t7)
  swc1  $f10, 4($t4)
  lw    $t9, ($t1)
  lwc1  $f4, 0x3cc($t9)
  b     .Ljp7F07C6B8
   swc1  $f4, 8($t4)
  lwc1  $f6, 8($a0)
.Ljp7F07C698:
  lw    $t5, 0x4c($sp)
  swc1  $f6, ($t5)
  lw    $t8, ($a1)
  lwc1  $f8, 0xc($t8)
  swc1  $f8, 4($t5)
  lw    $t6, ($a1)
  lwc1  $f10, 0x10($t6)
  swc1  $f10, 8($t5)
.Ljp7F07C6B8:
  lw    $t7, ($t1)
  lw    $t4, 0x54($sp)
  lw    $v1, 0x58($sp)
  lw    $t9, 0x488($t7)
  sw    $t9, ($t4)
  lw    $t8, ($t1)
  lwc1  $f4, 0x48c($t8)
  swc1  $f4, ($v1)
  lw    $t6, ($t1)
  lwc1  $f6, 0x490($t6)
  swc1  $f6, 4($v1)
  lw    $t5, ($t1)
  lwc1  $f8, 0x494($t5)
  b     .Ljp7F07CB54
   swc1  $f8, 8($v1)
  li    $at, 7
.Ljp7F07C6F8:
  bne   $v0, $at, .Ljp7F07CB54
   lui   $v0, %hi(dword_CODE_bss_800799F8) # $v0, 0x8008
  addiu $v0, %lo(dword_CODE_bss_800799F8) # addiu $v0, $v0, -0x65c8
  lw    $a0, ($v0)
  lw    $t7, 0x48($sp)
  beqz  $a0, .Ljp7F07C7A0
   nop   
  lwc1  $f10, ($a0)
  lw    $v1, 0x58($sp)
  lui   $t1, %hi(pPlayer) # $t1, 0x8008
  swc1  $f10, ($t7)
  lw    $t9, ($v0)
  addiu $t1, %lo(pPlayer) # addiu $t1, $t1, -0x5ee0
  lwc1  $f4, 4($t9)
  swc1  $f4, 4($t7)
  lw    $t4, ($v0)
  lwc1  $f6, 8($t4)
  swc1  $f6, 8($t7)
  lw    $t8, ($t1)
  lw    $t6, 0x4c($sp)
  lwc1  $f8, 0x3c4($t8)
  swc1  $f8, ($t6)
  lw    $t5, ($t1)
  lwc1  $f10, 0x3c8($t5)
  swc1  $f10, 4($t6)
  lw    $t9, ($t1)
  lwc1  $f4, 0x3cc($t9)
  swc1  $f4, 8($t6)
  lw    $t4, ($v0)
  lw    $t8, 0x54($sp)
  lw    $t7, 0x28($t4)
  sw    $t7, ($t8)
  lw    $t5, ($v0)
  lwc1  $f6, ($t5)
  swc1  $f6, ($v1)
  lw    $t9, ($v0)
  lwc1  $f8, 4($t9)
  swc1  $f8, 4($v1)
  lw    $t6, ($v0)
  lwc1  $f10, 8($t6)
  b     .Ljp7F07CB54
   swc1  $f10, 8($v1)
.Ljp7F07C7A0:
  lui   $a1, %hi(dword_CODE_bss_800799FC) # $a1, 0x8008
  addiu $a1, %lo(dword_CODE_bss_800799FC) # addiu $a1, $a1, -0x65c4
  lw    $a0, ($a1)
  beqz  $a0, .Ljp7F07C93C
   nop   
  lw    $v1, 0x18($a0)
  lui   $t5, %hi(ptr_2xxxpresets) # $t5, 0x8007
  lw    $t9, 0x48($sp)
  slti  $at, $v1, 0x2710
  beqz  $at, .Ljp7F07C7F0
   sll   $t8, $v1, 4
  sll   $t4, $v1, 2
  subu  $t4, $t4, $v1
  sll   $t4, $t4, 2
  lui   $t7, %hi(ptr_0xxxpresets) # $t7, 0x8007
  lw    $t7, %lo(ptr_0xxxpresets)($t7)
  subu  $t4, $t4, $v1
  sll   $t4, $t4, 2
  b     .Ljp7F07C80C
   addu  $v0, $t4, $t7
.Ljp7F07C7F0:
  lw    $t5, %lo(ptr_2xxxpresets)($t5)
  addu  $t8, $t8, $v1
  sll   $t8, $t8, 2
  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
  addu  $v0, $t8, $t5
  addu  $v0, $v0, $at
.Ljp7F07C80C:
  lwc1  $f4, 4($a0)
  lw    $v1, 0x58($sp)
  lui   $t5, %hi(dword_CODE_bss_80079A18) # $t5, 0x8008
  swc1  $f4, ($t9)
  lw    $t6, ($a1)
  lui   $t1, %hi(pPlayer) # $t1, 0x8008
  addiu $t1, %lo(pPlayer) # addiu $t1, $t1, -0x5ee0
  lwc1  $f6, 8($t6)
  swc1  $f6, 4($t9)
  lw    $t4, ($a1)
  lwc1  $f8, 0xc($t4)
  swc1  $f8, 8($t9)
  lw    $t8, 0x54($sp)
  lw    $t7, 0x28($v0)
  sw    $t7, ($t8)
  lwc1  $f10, ($v0)
  swc1  $f10, ($v1)
  lwc1  $f4, 4($v0)
  swc1  $f4, 4($v1)
  lwc1  $f6, 8($v0)
  swc1  $f6, 8($v1)
  lw    $t5, %lo(dword_CODE_bss_80079A18)($t5)
  bnel  $t3, $t5, .Ljp7F07C89C
   lw    $t8, ($a1)
  lw    $t6, ($t1)
  lw    $t4, 0x4c($sp)
  lwc1  $f8, 0x3c4($t6)
  swc1  $f8, ($t4)
  lw    $t9, ($t1)
  lwc1  $f10, 0x3c8($t9)
  swc1  $f10, 4($t4)
  lw    $t7, ($t1)
  lwc1  $f4, 0x3cc($t7)
  b     .Ljp7F07CB54
   swc1  $f4, 8($t4)
  lw    $t8, ($a1)
.Ljp7F07C89C:
  jal   cosf
   lwc1  $f12, 0x14($t8)
  lui   $t5, %hi(dword_CODE_bss_800799FC) # $t5, 0x8008
  lw    $t5, %lo(dword_CODE_bss_800799FC)($t5)
  swc1  $f0, 0x1c($sp)
  jal   sinf
   lwc1  $f12, 0x10($t5)
  lwc1  $f6, 0x1c($sp)
  lw    $t6, 0x48($sp)
  lw    $t9, 0x4c($sp)
  mul.s $f8, $f0, $f6
  lwc1  $f10, ($t6)
  lui   $t7, %hi(dword_CODE_bss_800799FC) # $t7, 0x8008
  add.s $f4, $f8, $f10
  swc1  $f4, ($t9)
  lw    $t7, %lo(dword_CODE_bss_800799FC)($t7)
  jal   sinf
   lwc1  $f12, 0x14($t7)
  lw    $t4, 0x48($sp)
  lw    $t8, 0x4c($sp)
  lui   $t5, %hi(dword_CODE_bss_800799FC) # $t5, 0x8008
  lwc1  $f6, 4($t4)
  add.s $f8, $f0, $f6
  swc1  $f8, 4($t8)
  lw    $t5, %lo(dword_CODE_bss_800799FC)($t5)
  jal   cosf
   lwc1  $f12, 0x14($t5)
  lui   $t6, %hi(dword_CODE_bss_800799FC) # $t6, 0x8008
  lw    $t6, %lo(dword_CODE_bss_800799FC)($t6)
  swc1  $f0, 0x1c($sp)
  jal   cosf
   lwc1  $f12, 0x10($t6)
  lwc1  $f4, 0x1c($sp)
  lw    $t9, 0x48($sp)
  lw    $t7, 0x4c($sp)
  mul.s $f6, $f0, $f4
  lwc1  $f10, 8($t9)
  sub.s $f8, $f10, $f6
  b     .Ljp7F07CB54
   swc1  $f8, 8($t7)
.Ljp7F07C93C:
  lui   $v0, %hi(dword_CODE_bss_80079A14) # $v0, 0x8008
  lw    $v0, %lo(dword_CODE_bss_80079A14)($v0)
  lui   $t6, %hi(ptr_2xxxpresets) # $t6, 0x8007
  lw    $t7, 0x54($sp)
  slti  $at, $v0, 0x2710
  beqz  $at, .Ljp7F07C97C
   sll   $t5, $v0, 4
  sll   $t4, $v0, 2
  subu  $t4, $t4, $v0
  sll   $t4, $t4, 2
  lui   $t8, %hi(ptr_0xxxpresets) # $t8, 0x8007
  lw    $t8, %lo(ptr_0xxxpresets)($t8)
  subu  $t4, $t4, $v0
  sll   $t4, $t4, 2
  b     .Ljp7F07C998
   addu  $a0, $t4, $t8
.Ljp7F07C97C:
  lw    $t6, %lo(ptr_2xxxpresets)($t6)
  addu  $t5, $t5, $v0
  sll   $t5, $t5, 2
  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
  addu  $a0, $t5, $t6
  addu  $a0, $a0, $at
.Ljp7F07C998:
  lw    $t9, 0x28($a0)
  lw    $v1, 0x58($sp)
  lui   $v0, %hi(flt_CODE_bss_80079A00) # $v0, 0x8008
  sw    $t9, ($t7)
  lwc1  $f4, ($a0)
  addiu $v0, %lo(flt_CODE_bss_80079A00) # addiu $v0, $v0, -0x65c0
  swc1  $f4, ($v1)
  lwc1  $f10, 4($a0)
  swc1  $f10, 4($v1)
  lwc1  $f6, 8($a0)
  swc1  $f6, 8($v1)
  sw    $a0, 0x20($sp)
  jal   cosf
   lwc1  $f12, ($v0)
  lw    $a0, 0x20($sp)
  lw    $t4, 0x4c($sp)
  lui   $at, %hi(flt_CODE_bss_80079A10) # $at, 0x8008
  lwc1  $f8, ($a0)
  lui   $v0, %hi(flt_CODE_bss_80079A00) # $v0, 0x8008
  addiu $v0, %lo(flt_CODE_bss_80079A00) # addiu $v0, $v0, -0x65c0
  swc1  $f8, ($t4)
  lwc1  $f10, %lo(flt_CODE_bss_80079A10)($at)
  lwc1  $f4, 4($a0)
  add.s $f6, $f4, $f10
  swc1  $f6, 4($t4)
  jal   sinf
   lwc1  $f12, ($v0)
  lw    $a0, 0x20($sp)
  lw    $t8, 0x4c($sp)
  lui   $v0, %hi(flt_CODE_bss_80079A00) # $v0, 0x8008
  lwc1  $f8, 8($a0)
  addiu $v0, %lo(flt_CODE_bss_80079A00) # addiu $v0, $v0, -0x65c0
  swc1  $f8, 8($t8)
  jal   sinf
   lwc1  $f12, ($v0)
  lui   $v0, %hi(flt_CODE_bss_80079A00) # $v0, 0x8008
  addiu $v0, %lo(flt_CODE_bss_80079A00) # addiu $v0, $v0, -0x65c0
  lwc1  $f12, ($v0)
  jal   cosf
   swc1  $f0, 0x1c($sp)
  lui   $at, %hi(flt_CODE_bss_80079A08) # $at, 0x8008
  lwc1  $f10, %lo(flt_CODE_bss_80079A08)($at)
  lwc1  $f4, 0x1c($sp)
  lw    $a0, 0x20($sp)
  lw    $t5, 0x48($sp)
  mul.s $f6, $f4, $f10
  lwc1  $f8, ($a0)
  lui   $at, %hi(flt_CODE_bss_80079A10) # $at, 0x8008
  lui   $v0, %hi(flt_CODE_bss_80079A00) # $v0, 0x8008
  addiu $v0, %lo(flt_CODE_bss_80079A00) # addiu $v0, $v0, -0x65c0
  add.s $f4, $f8, $f6
  swc1  $f4, ($t5)
  lwc1  $f8, %lo(flt_CODE_bss_80079A10)($at)
  lwc1  $f10, 4($a0)
  lui   $at, %hi(flt_CODE_bss_80079A0C) # $at, 0x8008
  lwc1  $f4, %lo(flt_CODE_bss_80079A0C)($at)
  add.s $f6, $f10, $f8
  add.s $f10, $f6, $f4
  swc1  $f10, 4($t5)
  jal   cosf
   lwc1  $f12, ($v0)
  lui   $v0, %hi(flt_CODE_bss_80079A00) # $v0, 0x8008
  addiu $v0, %lo(flt_CODE_bss_80079A00) # addiu $v0, $v0, -0x65c0
  lwc1  $f12, ($v0)
  jal   sinf
   swc1  $f0, 0x1c($sp)
  lui   $at, %hi(D_8005505C) # $at, 0x8005
  lwc1  $f12, %lo(D_8005505C)($at)
  lui   $at, %hi(flt_CODE_bss_80079A08) # $at, 0x8008
  lwc1  $f6, %lo(flt_CODE_bss_80079A08)($at)
  lwc1  $f8, 0x1c($sp)
  lw    $a0, 0x20($sp)
  lw    $t6, 0x48($sp)
  mul.s $f4, $f8, $f6
  lwc1  $f10, 8($a0)
  lui   $at, %hi(flt_CODE_bss_80079A04) # $at, 0x8008
  lui   $v0, %hi(flt_CODE_bss_80079A00) # $v0, 0x8008
  addiu $v0, %lo(flt_CODE_bss_80079A00) # addiu $v0, $v0, -0x65c0
  mtc1  $zero, $f14
  add.s $f8, $f10, $f4
  swc1  $f8, 8($t6)
  lwc1  $f6, %lo(flt_CODE_bss_80079A04)($at)
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  lwc1  $f10, %lo(global_timer_delta)($at)
  lwc1  $f8, ($v0)
  mul.s $f4, $f6, $f10
  add.s $f6, $f8, $f4
  swc1  $f6, ($v0)
  lwc1  $f2, ($v0)
  c.le.s $f12, $f2
  nop   
  bc1fl .Ljp7F07CB2C
   c.lt.s $f2, $f14
  sub.s $f10, $f2, $f12
.Ljp7F07CB10:
  swc1  $f10, ($v0)
  lwc1  $f2, ($v0)
  c.le.s $f12, $f2
  nop   
  bc1tl .Ljp7F07CB10
   sub.s $f10, $f2, $f12
  c.lt.s $f2, $f14
.Ljp7F07CB2C:
  nop   
  bc1fl .Ljp7F07CB58
   lw    $ra, 0x14($sp)
  add.s $f8, $f2, $f12
.Ljp7F07CB3C:
  swc1  $f8, ($v0)
  lwc1  $f2, ($v0)
  c.lt.s $f2, $f14
  nop   
  bc1tl .Ljp7F07CB3C
   add.s $f8, $f2, $f12
.Ljp7F07CB54:
  lw    $ra, 0x14($sp)
.Ljp7F07CB58:
  addiu $sp, $sp, 0x40
  jr    $ra
   nop   
");
#endif

void sub_GAME_7F07C540(int arg0)
{
  pPlayer->field_42C = arg0;
}

void set_BONDdata_lookahead_setting(int arg0)
{
  pPlayer->automovecentreenabled = arg0;
}

int get_BONDdata_lookahead_setting(void)
{
  return pPlayer->automovecentreenabled;
}

void set_BONDdata_autoaim_y(int param_1)
{
  pPlayer->autoyaimenabled = param_1;
}

asm(R"
glabel get_BONDdata_autoaim_y
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   getPlayerCount
   nop   
  li    $at, 1
  bne   $v0, $at, .L7F07C5AC
   lw    $ra, 0x14($sp)
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  b     .L7F07C5B8
   lw    $v0, 0x128($t6)
.L7F07C5AC:
  lui   $t7, %hi(pPlayersPerm) 
  lw    $t7, %lo(pPlayersPerm)($t7)
  lbu   $v0, 0x6a($t7)
.L7F07C5B8:
  jr    $ra
   addiu $sp, $sp, 0x18
");

int redirect_get_BONDdata_autoaim_y(void) {
  return get_BONDdata_autoaim_y();
}

int get_BONDdata_is_aiming(void) {
  return pPlayer->insightaimmode;
}

asm(R"
glabel sub_GAME_7F07C5F0
  mtc1  $a1, $f12
  lui   $a1, %hi(pPlayer)
  addiu $a1, %lo(pPlayer) # addiu $a1, $a1, -0x5f50
  lw    $v0, ($a1)
  lui   $t6, %hi(clock_timer) 
  lw    $v1, 0x134($v0)
  bltzl $v1, .L7F07C624
   lw    $t8, 0x130($v0)
  lw    $t6, %lo(clock_timer)($t6)
  subu  $t7, $v1, $t6
  sw    $t7, 0x134($v0)
  lw    $v0, ($a1)
  lw    $t8, 0x130($v0)
.L7F07C624:
  beql  $a0, $t8, .L7F07C650
   swc1  $f12, 0x12c($v0)
  lw    $t9, 0x134($v0)
  li    $t0, 30
  bgez  $t9, .L7F07C650
   nop   
  sw    $t0, 0x134($v0)
  lw    $t1, ($a1)
  sw    $a0, 0x130($t1)
  lw    $v0, ($a1)
  swc1  $f12, 0x12c($v0)
.L7F07C650:
  jr    $ra
   nop   
");

void set_BONDdata_autoaim_x(int param_1) {
  pPlayer->autoxaimenabled = param_1;
  return;
}

asm(R"
glabel get_BONDdata_autoaim_x
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   getPlayerCount
   nop   
  li    $at, 1
  bne   $v0, $at, .L7F07C694
   lw    $ra, 0x14($sp)
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  b     .L7F07C6A0
   lw    $v0, 0x138($t6)
.L7F07C694:
  lui   $t7, %hi(pPlayersPerm) 
  lw    $t7, %lo(pPlayersPerm)($t7)
  lbu   $v0, 0x6a($t7)
.L7F07C6A0:
  jr    $ra
   addiu $sp, $sp, 0x18
");

int redirect_get_BONDdata_autoaim_x(void) {
  return get_BONDdata_autoaim_x();
}

asm(R"
glabel sub_GAME_7F07C6C8
  mtc1  $a1, $f12
  lui   $a1, %hi(pPlayer)
  addiu $a1, %lo(pPlayer) # addiu $a1, $a1, -0x5f50
  lw    $v0, ($a1)
  lui   $t6, %hi(clock_timer) 
  lw    $v1, 0x144($v0)
  bltzl $v1, .L7F07C6FC
   lw    $t8, 0x140($v0)
  lw    $t6, %lo(clock_timer)($t6)
  subu  $t7, $v1, $t6
  sw    $t7, 0x144($v0)
  lw    $v0, ($a1)
  lw    $t8, 0x140($v0)
.L7F07C6FC:
  beql  $a0, $t8, .L7F07C728
   swc1  $f12, 0x13c($v0)
  lw    $t9, 0x144($v0)
  li    $t0, 30
  bgez  $t9, .L7F07C728
   nop   
  sw    $t0, 0x144($v0)
  lw    $t1, ($a1)
  sw    $a0, 0x140($t1)
  lw    $v0, ($a1)
  swc1  $f12, 0x13c($v0)
.L7F07C728:
  jr    $ra
   nop   
");

asm(R"
glabel change_player_pos_to_target
  lwc1  $f4, ($a1)
  mtc1  $zero, $f16
  li    $at, 0x3F800000 # 1.000000
  swc1  $f4, 4($a0)
  lwc1  $f6, 4($a1)
  mtc1  $at, $f14
  lwc1  $f0, 4($a0)
  swc1  $f6, 8($a0)
  lwc1  $f8, 8($a1)
  lwc1  $f2, 8($a0)
  li    $at, 0x41F00000 # 30.000000
  swc1  $f8, 0xc($a0)
  lwc1  $f12, 0xc($a0)
  mtc1  $at, $f10
  sw    $a2, ($a0)
  sw    $a2, 0x50($a0)
  swc1  $f16, 0x3c($a0)
  swc1  $f16, 0x40($a0)
  swc1  $f16, 0x44($a0)
  swc1  $f16, 0x4c($a0)
  swc1  $f16, 0x10($a0)
  swc1  $f16, 0x14($a0)
  swc1  $f0, 0x2c($a0)
  swc1  $f0, 0x1c($a0)
  swc1  $f14, 0x38($a0)
  swc1  $f14, 0x48($a0)
  swc1  $f14, 0x18($a0)
  swc1  $f2, 0x30($a0)
  swc1  $f2, 0x20($a0)
  swc1  $f12, 0x34($a0)
  swc1  $f12, 0x24($a0)
  jr    $ra
   swc1  $f10, 0x28($a0)
");

asm(R"
.late_rodata
glabel D_80055060
.word 0x40c90fdb /*6.2831855*/

.text
glabel sub_GAME_7F07C7B4
  lui   $a0, %hi(ptr_playerstank)
  lw    $a0, %lo(ptr_playerstank)($a0)
  addiu $sp, $sp, -0x70
  sw    $ra, 0x14($sp)
  beql  $a0, $zero, .L7F07C87C
   lw    $ra, 0x14($sp)
  lw    $v1, 4($a0)
  lui   $at, %hi(D_80055060)
  lwc1  $f4, %lo(D_80055060)($at)
  lw    $t6, 0x14($v1)
  lui   $at, %hi(D_80036474)
  lwc1  $f6, %lo(D_80036474)($at)
  lw    $t7, 8($t6)
  addiu $a1, $sp, 0x24
  sub.s $f12, $f4, $f6
  lw    $v0, 8($t7)
  lw    $t8, 8($v0)
  lw    $t9, 4($v0)
  lw    $a2, 4($t8)
  lw    $a3, 4($t9)
  sw    $a2, 0x68($sp)
  jal   sub_GAME_7F0585FC
   sw    $a3, 0x64($sp)
  lw    $a2, 0x68($sp)
  lui   $a1, %hi(flt_CODE_bss_800799A8)
  addiu $a1, %lo(flt_CODE_bss_800799A8) # addiu $a1, $a1, -0x6658
  lwc1  $f8, ($a2)
  addiu $a0, $sp, 0x24
  swc1  $f8, ($a1)
  lwc1  $f10, 4($a2)
  swc1  $f10, 4($a1)
  lwc1  $f16, 8($a2)
  jal   sub_GAME_7F0583D8
   swc1  $f16, 8($a1)
  lw    $a3, 0x64($sp)
  lui   $a1, %hi(flt_CODE_bss_800799A8)
  addiu $a1, %lo(flt_CODE_bss_800799A8) # addiu $a1, $a1, -0x6658
  lwc1  $f18, ($a1)
  lwc1  $f4, ($a3)
  lwc1  $f8, 4($a1)
  add.s $f6, $f18, $f4
  lwc1  $f18, 8($a1)
  swc1  $f6, ($a1)
  lwc1  $f10, 4($a3)
  add.s $f16, $f8, $f10
  swc1  $f16, 4($a1)
  lwc1  $f4, 8($a3)
  add.s $f6, $f18, $f4
  swc1  $f6, 8($a1)
  lw    $ra, 0x14($sp)
.L7F07C87C:
  addiu $sp, $sp, 0x70
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F07C888
  addiu $sp, $sp, -0x50
  lui   $t6, %hi(ptr_playerstank) 
  lw    $t6, %lo(ptr_playerstank)($t6)
  sw    $a2, 0x58($sp)
  move  $a2, $a0
  sw    $ra, 0x14($sp)
  sw    $a0, 0x50($sp)
  lw    $a0, 4($t6)
  sw    $a2, 0x50($sp)
  sw    $a1, 0x54($sp)
  jal   sub_GAME_7F040078
   sw    $a0, 0x4c($sp)
  lui   $v1, %hi(flt_CODE_bss_800799A8)
  addiu $v1, %lo(flt_CODE_bss_800799A8) # addiu $v1, $v1, -0x6658
  lwc1  $f0, ($v1)
  lwc1  $f4, 4($v0)
  lwc1  $f2, 8($v1)
  lwc1  $f12, 0x58($sp)
  sub.s $f6, $f4, $f0
  swc1  $f6, 0x44($sp)
  lwc1  $f8, 8($v0)
  sub.s $f10, $f8, $f0
  swc1  $f10, 0x40($sp)
  lwc1  $f4, 0x14($v0)
  sub.s $f6, $f4, $f2
  swc1  $f6, 0x3c($sp)
  lwc1  $f8, 0x18($v0)
  sub.s $f10, $f8, $f2
  jal   cosf
   swc1  $f10, 0x38($sp)
  lw    $t7, 0x4c($sp)
  lwc1  $f12, 0x58($sp)
  lw    $t8, 0x14($t7)
  lwc1  $f4, 0x14($t8)
  mul.s $f14, $f0, $f4
  jal   sinf
   swc1  $f14, 0x34($sp)
  lw    $t9, 0x4c($sp)
  lwc1  $f8, 0x3c($sp)
  lw    $a1, 0x54($sp)
  lw    $t0, 0x14($t9)
  neg.s $f10, $f8
  lwc1  $f14, 0x34($sp)
  lwc1  $f6, 0x14($t0)
  lwc1  $f4, 0x44($sp)
  lw    $a2, 0x50($sp)
  mul.s $f12, $f0, $f6
  lwc1  $f6, ($a1)
  mul.s $f2, $f10, $f12
  add.s $f8, $f6, $f2
  mul.s $f16, $f4, $f14
  add.s $f10, $f8, $f16
  swc1  $f10, ($a2)
  lwc1  $f4, 0x3c($sp)
  lwc1  $f6, 0x44($sp)
  mul.s $f18, $f4, $f14
  nop   
  mul.s $f8, $f6, $f12
  swc1  $f8, 0x24($sp)
  lwc1  $f10, 8($a1)
  add.s $f4, $f10, $f18
  add.s $f6, $f4, $f8
  swc1  $f6, 4($a2)
  lwc1  $f10, 0x40($sp)
  mul.s $f4, $f10, $f14
  swc1  $f4, 0x20($sp)
  lwc1  $f8, ($a1)
  add.s $f6, $f8, $f2
  add.s $f10, $f6, $f4
  swc1  $f10, 8($a2)
  lwc1  $f8, 0x40($sp)
  lwc1  $f6, 8($a1)
  mul.s $f0, $f8, $f12
  add.s $f4, $f6, $f18
  add.s $f10, $f4, $f0
  swc1  $f10, 0xc($a2)
  lwc1  $f8, 0x38($sp)
  lwc1  $f4, ($a1)
  neg.s $f6, $f8
  lwc1  $f8, 0x20($sp)
  mul.s $f2, $f6, $f12
  add.s $f10, $f4, $f2
  add.s $f6, $f10, $f8
  swc1  $f6, 0x10($a2)
  lwc1  $f4, 0x38($sp)
  mul.s $f10, $f4, $f14
  swc1  $f10, 0x1c($sp)
  lwc1  $f8, 8($a1)
  add.s $f6, $f8, $f10
  add.s $f4, $f6, $f0
  swc1  $f4, 0x14($a2)
  lwc1  $f8, ($a1)
  add.s $f10, $f8, $f2
  add.s $f6, $f10, $f16
  swc1  $f6, 0x18($a2)
  lwc1  $f8, 0x1c($sp)
  lwc1  $f4, 8($a1)
  lwc1  $f6, 0x24($sp)
  add.s $f10, $f4, $f8
  add.s $f4, $f10, $f6
  swc1  $f4, 0x1c($a2)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x50
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F07CA2C
  addiu $sp, $sp, -0x30
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f2
  mtc1  $zero, $f0
  lwc1  $f4, 0x40($sp)
  lw    $t6, 0x44($sp)
  sw    $ra, 0x2c($sp)
  sw    $a1, 0x34($sp)
  sw    $a2, 0x38($sp)
  sw    $a3, 0x3c($sp)
  swc1  $f2, 0x1c($sp)
  swc1  $f2, 0x24($sp)
  swc1  $f4, 0x10($sp)
  swc1  $f0, 0x18($sp)
  swc1  $f0, 0x20($sp)
  jal   sub_GAME_7F0B0E24
   sw    $t6, 0x14($sp)
  mtc1  $zero, $f0
  bnez  $v0, .L7F07CAB4
   move  $a0, $v0
  lw    $v1, 0x48($sp)
  lwc1  $f6, 0x34($sp)
  beql  $v1, $zero, .L7F07CAB8
   lw    $ra, 0x2c($sp)
  lw    $v0, 0x4c($sp)
  swc1  $f6, ($v1)
  swc1  $f0, 4($v1)
  lwc1  $f8, 0x38($sp)
  swc1  $f8, 8($v1)
  lwc1  $f10, 0x3c($sp)
  swc1  $f0, 4($v0)
  swc1  $f10, ($v0)
  lwc1  $f16, 0x40($sp)
  swc1  $f16, 8($v0)
.L7F07CAB4:
  lw    $ra, 0x2c($sp)
.L7F07CAB8:
  addiu $sp, $sp, 0x30
  move  $v0, $a0
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80055064
.word 0x40c90fdb /*6.2831855*/

.text
glabel sub_GAME_7F07CAC8
  addiu $sp, $sp, -0xc0
  sw    $ra, 0x24($sp)
  sw    $a0, 0xc0($sp)
  sw    $a1, 0xc4($sp)
  sw    $a1, 0xbc($sp)
  sw    $a2, 0xc8($sp)
  sw    $a3, 0xcc($sp)
  sw    $zero, 0x94($sp)
  lw    $a1, 0xc0($sp)
  jal   sub_GAME_7F07C888
   addiu $a0, $sp, 0x98
  lui   $a0, %hi(ptr_playerstank)
  lw    $a0, %lo(ptr_playerstank)($a0)
  beql  $a0, $zero, .L7F07CB10
   lw    $v0, 0xc0($sp)
  jal   sub_GAME_7F03D058
   move  $a1, $zero
  lw    $v0, 0xc0($sp)
.L7F07CB10:
  lwc1  $f4, 0x9c($sp)
  lw    $t8, 0xcc($sp)
  lw    $a1, ($v0)
  lw    $a2, 8($v0)
  lw    $t9, 0xd0($sp)
  li    $t7, 531
  sw    $t7, 0x14($sp)
  addiu $a0, $sp, 0xbc
  lw    $a3, 0x98($sp)
  swc1  $f4, 0x10($sp)
  sw    $t8, 0x18($sp)
  jal   sub_GAME_7F07CA2C
   sw    $t9, 0x1c($sp)
  beqz  $v0, .L7F07CD7C
   addiu $a0, $sp, 0xbc
  lwc1  $f6, 0xa4($sp)
  lw    $t2, 0xcc($sp)
  lw    $t3, 0xd0($sp)
  li    $t1, 531
  sw    $t1, 0x14($sp)
  lw    $a1, 0x98($sp)
  lw    $a2, 0x9c($sp)
  lw    $a3, 0xa0($sp)
  swc1  $f6, 0x10($sp)
  sw    $t2, 0x18($sp)
  jal   sub_GAME_7F07CA2C
   sw    $t3, 0x1c($sp)
  beqz  $v0, .L7F07CD7C
   addiu $a0, $sp, 0xbc
  lwc1  $f8, 0xac($sp)
  lw    $t5, 0xcc($sp)
  lw    $t6, 0xd0($sp)
  li    $t4, 531
  sw    $t4, 0x14($sp)
  lw    $a1, 0xa0($sp)
  lw    $a2, 0xa4($sp)
  lw    $a3, 0xa8($sp)
  swc1  $f8, 0x10($sp)
  sw    $t5, 0x18($sp)
  jal   sub_GAME_7F07CA2C
   sw    $t6, 0x1c($sp)
  beqz  $v0, .L7F07CD7C
   addiu $a0, $sp, 0xbc
  lwc1  $f10, 0xb4($sp)
  lw    $t8, 0xcc($sp)
  lw    $t9, 0xd0($sp)
  li    $t7, 531
  sw    $t7, 0x14($sp)
  lw    $a1, 0xa8($sp)
  lw    $a2, 0xac($sp)
  lw    $a3, 0xb0($sp)
  swc1  $f10, 0x10($sp)
  sw    $t8, 0x18($sp)
  jal   sub_GAME_7F07CA2C
   sw    $t9, 0x1c($sp)
  beqz  $v0, .L7F07CD7C
   addiu $a0, $sp, 0xbc
  lwc1  $f16, 0x9c($sp)
  lw    $t2, 0xcc($sp)
  lw    $t3, 0xd0($sp)
  li    $t1, 531
  sw    $t1, 0x14($sp)
  lw    $a1, 0xb0($sp)
  lw    $a2, 0xb4($sp)
  lw    $a3, 0x98($sp)
  swc1  $f16, 0x10($sp)
  sw    $t2, 0x18($sp)
  jal   sub_GAME_7F07CA2C
   sw    $t3, 0x1c($sp)
  beqz  $v0, .L7F07CD7C
   lui   $a0, %hi(ptr_playerstank)
  lw    $a0, %lo(ptr_playerstank)($a0)
  li    $t4, 1
  sw    $t4, 0x94($sp)
  beqz  $a0, .L7F07CD7C
   nop   
  lw    $a3, 4($a0)
  mtc1  $zero, $f12
  lui   $at, %hi(D_80055064)
  lw    $t0, 0x14($a3)
  lwc1  $f2, %lo(D_80055064)($at)
  lui   $at, %hi(D_80036474)
  lw    $t5, 8($t0)
  lw    $v0, 8($t5)
  lw    $t6, 0xc($v0)
  lw    $t7, 0x10($v0)
  lw    $t8, 8($v0)
  lw    $v1, 4($t6)
  lw    $a1, 4($t7)
  lw    $a2, 4($t8)
  lwc1  $f4, ($v1)
  lwc1  $f18, ($a1)
  lwc1  $f8, ($a2)
  swc1  $f12, 0x78($sp)
  add.s $f6, $f18, $f4
  sub.s $f10, $f6, $f8
  swc1  $f10, 0x74($sp)
  lwc1  $f18, 8($v1)
  lwc1  $f16, 8($a1)
  lwc1  $f10, 0xc8($sp)
  lwc1  $f6, 8($a2)
  add.s $f4, $f16, $f18
  lwc1  $f16, %lo(D_80036474)($at)
  addiu $a1, $sp, 0x34
  add.s $f0, $f10, $f16
  sub.s $f8, $f4, $f6
  c.le.s $f2, $f0
  swc1  $f8, 0x7c($sp)
  bc1fl .L7F07CCD0
   c.lt.s $f0, $f12
  sub.s $f0, $f0, $f2
  c.lt.s $f0, $f12
.L7F07CCD0:
  nop   
  bc1fl .L7F07CCE4
   sub.s $f12, $f2, $f0
  add.s $f0, $f0, $f2
  sub.s $f12, $f2, $f0
.L7F07CCE4:
  jal   sub_GAME_7F0585FC
   sw    $t0, 0x8c($sp)
  addiu $a0, $sp, 0x34
  jal   sub_GAME_7F0583D8
   addiu $a1, $sp, 0x74
  lw    $t0, 0x8c($sp)
  lwc1  $f18, 0x74($sp)
  lwc1  $f8, 0x7c($sp)
  lwc1  $f4, 0x14($t0)
  lw    $v0, 0xc0($sp)
  lw    $t9, 0xc4($sp)
  mul.s $f6, $f18, $f4
  lw    $t2, 0xcc($sp)
  lw    $t3, 0xd0($sp)
  li    $t1, 531
  addiu $a0, $sp, 0xbc
  swc1  $f6, 0x74($sp)
  lwc1  $f10, 0x14($t0)
  mul.s $f16, $f8, $f10
  swc1  $f16, 0x7c($sp)
  lwc1  $f18, ($v0)
  add.s $f4, $f6, $f18
  swc1  $f4, 0x74($sp)
  lwc1  $f8, 8($v0)
  sw    $t9, 0xbc($sp)
  mfc1  $a3, $f4
  add.s $f10, $f16, $f8
  swc1  $f10, 0x7c($sp)
  lw    $a2, 8($v0)
  lw    $a1, ($v0)
  sw    $t1, 0x14($sp)
  swc1  $f10, 0x10($sp)
  sw    $t2, 0x18($sp)
  jal   sub_GAME_7F07CA2C
   sw    $t3, 0x1c($sp)
  bnez  $v0, .L7F07CD7C
   nop   
  sw    $zero, 0x94($sp)
.L7F07CD7C:
  lui   $a0, %hi(ptr_playerstank)
  lw    $a0, %lo(ptr_playerstank)($a0)
  beql  $a0, $zero, .L7F07CD98
   lw    $ra, 0x24($sp)
  jal   sub_GAME_7F03D058
   li    $a1, 1
  lw    $ra, 0x24($sp)
.L7F07CD98:
  lw    $v0, 0x94($sp)
  addiu $sp, $sp, 0xc0
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F07CDA8
  mtc1  $a2, $f12
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  mfc1  $a2, $f12
  sw    $zero, 0x10($sp)
  jal   sub_GAME_7F07CAC8
   move  $a3, $zero
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F07CDD4
  addiu $sp, $sp, -0x40
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  sw    $ra, 0x2c($sp)
  sw    $a0, 0x40($sp)
  sw    $a1, 0x44($sp)
  sw    $a2, 0x48($sp)
  lw    $t6, 0x488($v0)
  lw    $t7, 0x40($sp)
  li    $at, 0x3F800000 # 1.000000
  sw    $t6, 0x3c($sp)
  lwc1  $f4, 8($t7)
  lw    $a2, 0x494($v0)
  lw    $a1, 0x48c($v0)
  lw    $a3, ($t7)
  mtc1  $at, $f2
  mtc1  $zero, $f0
  sw    $zero, 0x14($sp)
  addiu $a0, $sp, 0x3c
  swc1  $f4, 0x10($sp)
  swc1  $f2, 0x1c($sp)
  swc1  $f2, 0x24($sp)
  swc1  $f0, 0x18($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f0, 0x20($sp)
  beqz  $v0, .L7F07CE64
   lw    $a0, 0x40($sp)
  lw    $a1, 0x3c($sp)
  jal   sub_GAME_7F07CDA8
   lw    $a2, 0x44($sp)
  beqz  $v0, .L7F07CE64
   lw    $t8, 0x3c($sp)
  lw    $t9, 0x48($sp)
  li    $v0, 1
  b     .L7F07CE68
   sw    $t8, ($t9)
.L7F07CE64:
  move  $v0, $zero
.L7F07CE68:
  lw    $ra, 0x2c($sp)
  addiu $sp, $sp, 0x40
  jr    $ra
   nop   
");

int get_intank_flag(void) {
  return in_tank_flag;
}

asm(R"
glabel get_ptr_for_players_tank
  lui   $t6, %hi(in_tank_flag) 
  lw    $t6, %lo(in_tank_flag)($t6)
  li    $at, 1
  move  $v0, $zero
  bne   $t6, $at, .L7F07CEA8
   nop   
  lui   $v0, %hi(ptr_playerstank)
  jr    $ra
   lw    $v0, %lo(ptr_playerstank)($v0)

.L7F07CEA8:
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80055068
.word 0x40c90fdb /*6.2831855*/

.text
glabel sub_GAME_7F07CEB0
  lui   $at, %hi(D_80055068)
  lwc1  $f0, %lo(D_80055068)($at)
  lui   $at, %hi(D_80036464)
  lwc1  $f4, %lo(D_80036464)($at)
  lui   $at, %hi(D_80036474)
  lwc1  $f6, %lo(D_80036474)($at)
  addiu $sp, $sp, -0x20
  mtc1  $zero, $f8
  add.s $f14, $f4, $f6
  sw    $ra, 0x14($sp)
  sw    $a0, 0x20($sp)
  c.le.s $f0, $f14
  nop   
  bc1fl .L7F07CEF4
   c.lt.s $f14, $f8
  sub.s $f14, $f14, $f0
  c.lt.s $f14, $f8
.L7F07CEF4:
  nop   
  bc1fl .L7F07CF08
   mov.s $f12, $f14
  add.s $f14, $f14, $f0
  mov.s $f12, $f14
.L7F07CF08:
  jal   sinf
   swc1  $f14, 0x1c($sp)
  lui   $at, %hi(D_8003646C)
  lwc1  $f12, %lo(D_8003646C)($at)
  jal   cosf
   swc1  $f0, 0x18($sp)
  lwc1  $f10, 0x18($sp)
  lw    $t6, 0x20($sp)
  lui   $at, %hi(D_8003646C)
  neg.s $f16, $f10
  mul.s $f18, $f0, $f16
  swc1  $f18, ($t6)
  jal   sinf
   lwc1  $f12, %lo(D_8003646C)($at)
  lw    $t7, 0x20($sp)
  lwc1  $f12, 0x1c($sp)
  jal   cosf
   swc1  $f0, 4($t7)
  lui   $at, %hi(D_8003646C)
  lwc1  $f12, %lo(D_8003646C)($at)
  jal   cosf
   swc1  $f0, 0x18($sp)
  lwc1  $f4, 0x18($sp)
  lw    $t8, 0x20($sp)
  mul.s $f6, $f0, $f4
  swc1  $f6, 8($t8)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F07CF80
  lui   $at, %hi(D_8003646C)
  jr    $ra
   lwc1  $f0, %lo(D_8003646C)($at)
");

asm(R"
glabel cal_player_collision
  lui   $t6, %hi(in_tank_flag) 
  lw    $t6, %lo(in_tank_flag)($t6)
  addiu $sp, $sp, -0x98
  li    $at, 1
  sw    $ra, 0x2c($sp)
  sw    $a0, 0x98($sp)
  sw    $a1, 0x9c($sp)
  bne   $t6, $at, .L7F07CFD8
   sw    $zero, 0x94($sp)
  lui   $t7, %hi(dword_CODE_bss_800799B8) 
  lw    $t7, %lo(dword_CODE_bss_800799B8)($t7)
  lui   $a1, %hi(D_80036464)
  lw    $a2, 0x9c($sp)
  beqz  $t7, .L7F07CFD8
   nop   
  jal   sub_GAME_7F07CDD4
   lw    $a1, %lo(D_80036464)($a1)
  b     .L7F07D220
   sw    $v0, 0x94($sp)
.L7F07CFD8:
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  lui   $t9, %hi(obj_collision_flag) 
  lw    $t9, %lo(obj_collision_flag)($t9)
  lw    $t8, 0x488($v1)
  addiu $a1, $sp, 0x80
  beqz  $t9, .L7F07D004
   sw    $t8, 0x90($sp)
  li    $t0, 31
  b     .L7F07D008
   sw    $t0, 0x8c($sp)
.L7F07D004:
  sw    $zero, 0x8c($sp)
.L7F07D008:
  lw    $a0, 0xa8($v1)
  addiu $a2, $sp, 0x88
  jal   sub_GAME_7F08A274
   addiu $a3, $sp, 0x84
  lui   $a0, %hi(D_8003644C)
  lw    $a0, %lo(D_8003644C)($a0)
  beqz  $a0, .L7F07D030
   nop   
  jal   sub_GAME_7F03D058
   move  $a1, $zero
.L7F07D030:
  lui   $t1, %hi(pPlayer) 
  lw    $t1, %lo(pPlayer)($t1)
  move  $a1, $zero
  jal   sub_GAME_7F03D058
   lw    $a0, 0xa8($t1)
  lw    $v0, 0x98($sp)
  addiu $t2, $sp, 0x3c
  addiu $a0, $sp, 0x90
  lw    $a1, ($v0)
  lw    $a2, 8($v0)
  sw    $t2, 0x10($sp)
  jal   sub_GAME_7F0B2314
   lw    $a3, 0x80($sp)
  sw    $v0, 0x7c($sp)
  jal   sub_GAME_7F0B239C
   addiu $a0, $sp, 0x3c
  beqz  $v0, .L7F07D084
   addiu $a0, $sp, 0x90
  lui   $t3, %hi(pPlayer) 
  lw    $t3, %lo(pPlayer)($t3)
  sw    $zero, 0x29fc($t3)
.L7F07D084:
  lui   $v1, %hi(pPlayer)
  lw    $v0, 0x98($sp)
  lw    $v1, %lo(pPlayer)($v1)
  li    $at, 0x3F800000 # 1.000000
  lwc1  $f4, 8($v0)
  lw    $a3, ($v0)
  lw    $a1, 0x48c($v1)
  lw    $a2, 0x494($v1)
  mtc1  $at, $f16
  lw    $t4, 0x8c($sp)
  lwc1  $f6, 0x88($sp)
  lwc1  $f8, 0x84($sp)
  mtc1  $zero, $f10
  swc1  $f4, 0x10($sp)
  sw    $t4, 0x14($sp)
  swc1  $f16, 0x24($sp)
  swc1  $f6, 0x18($sp)
  swc1  $f8, 0x1c($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f10, 0x20($sp)
  beqz  $v0, .L7F07D1AC
   addiu $a0, $sp, 0x90
  lw    $v0, 0x98($sp)
  lw    $t5, 0x8c($sp)
  lwc1  $f18, 0x88($sp)
  lwc1  $f4, 0x84($sp)
  lw    $a1, ($v0)
  lw    $a2, 8($v0)
  lw    $a3, 0x80($sp)
  sw    $t5, 0x10($sp)
  swc1  $f18, 0x14($sp)
  jal   sub_GAME_7F0B18B8
   swc1  $f4, 0x18($sp)
  bgez  $v0, .L7F07D1AC
   lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  li    $at, 0xC2C80000 # -100.000000
  mtc1  $at, $f6
  lwc1  $f8, 0xa0($v1)
  lw    $t6, 0x7c($sp)
  c.eq.s $f6, $f8
  nop   
  bc1t  .L7F07D13C
   nop   
  bgez  $t6, .L7F07D1B4
   nop   
.L7F07D13C:
  jal   sub_GAME_7F0B23A4
   addiu $a0, $sp, 0x3c
  bnez  $v0, .L7F07D18C
   addiu $a0, $sp, 0x90
  lui   $t8, %hi(pPlayer) 
  lw    $t8, %lo(pPlayer)($t8)
  li    $at, 0x432F0000 # 175.000000
  mtc1  $at, $f16
  lwc1  $f10, 0x490($t8)
  lw    $t7, 0x98($sp)
  lw    $a3, 0x80($sp)
  add.s $f18, $f10, $f16
  lw    $a1, ($t7)
  lw    $a2, 8($t7)
  jal   sub_GAME_7F0B26B8
   swc1  $f18, 0x10($sp)
  bltz  $v0, .L7F07D18C
   lui   $v1, %hi(pPlayer)
  b     .L7F07D1B4
   lw    $v1, %lo(pPlayer)($v1)
.L7F07D18C:
  lw    $t9, 0x90($sp)
  lw    $t0, 0x9c($sp)
  li    $t1, 1
  lui   $v1, %hi(pPlayer)
  sw    $t9, ($t0)
  lw    $v1, %lo(pPlayer)($v1)
  b     .L7F07D1FC
   sw    $t1, 0x94($sp)
.L7F07D1AC:
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
.L7F07D1B4:
  lui   $t2, %hi(ptr_playerstank) 
  lw    $t2, %lo(ptr_playerstank)($t2)
  lui   $v0, %hi(dword_CODE_bss_8007BA04)
  bnezl $t2, .L7F07D200
   lw    $a0, 0xa8($v1)
  lw    $v0, %lo(dword_CODE_bss_8007BA04)($v0)
  beql  $v0, $zero, .L7F07D200
   lw    $a0, 0xa8($v1)
  lbu   $t3, ($v0)
  li    $at, 1
  bnel  $t3, $at, .L7F07D200
   lw    $a0, 0xa8($v1)
  lw    $a0, 4($v0)
  li    $at, 45
  lbu   $t4, 3($a0)
  bne   $t4, $at, .L7F07D1FC
   lui   $at, %hi(D_8003644C)
  sw    $v0, %lo(D_8003644C)($at)
.L7F07D1FC:
  lw    $a0, 0xa8($v1)
.L7F07D200:
  jal   sub_GAME_7F03D058
   li    $a1, 1
  lui   $a0, %hi(D_8003644C)
  lw    $a0, %lo(D_8003644C)($a0)
  beql  $a0, $zero, .L7F07D224
   lw    $ra, 0x2c($sp)
  jal   sub_GAME_7F03D058
   li    $a1, 1
.L7F07D220:
  lw    $ra, 0x2c($sp)
.L7F07D224:
  lw    $v0, 0x94($sp)
  addiu $sp, $sp, 0x98
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F07D234
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a0, 0x20($sp)
  sw    $a1, 0x24($sp)
  jal   sub_GAME_7F0B1CC4
   sw    $a2, 0x28($sp)
  lw    $a0, 0x20($sp)
  jal   cal_player_collision
   addiu $a1, $sp, 0x1c
  beqz  $v0, .L7F07D294
   lw    $a0, 0x20($sp)
  lui   $v1, %hi(pPlayer)
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $t7, ($v1)
  lw    $t6, 0x1c($sp)
  li    $v0, 1
  sw    $t6, 0x488($t7)
  lw    $t8, ($v1)
  lwc1  $f4, ($a0)
  swc1  $f4, 0x48c($t8)
  lw    $t9, ($v1)
  lwc1  $f6, 8($a0)
  b     .L7F07D2A4
   swc1  $f6, 0x494($t9)
.L7F07D294:
  lw    $a0, 0x24($sp)
  jal   sub_GAME_7F0B28B0
   lw    $a1, 0x28($sp)
  move  $v0, $zero
.L7F07D2A4:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F07D2B4
  addiu $sp, $sp, -0x80
  sw    $s0, 0x18($sp)
  lui   $s0, %hi(pPlayer)
  addiu $s0, %lo(pPlayer) # addiu $s0, $s0, -0x5f50
  lw    $t6, ($s0)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  move  $s1, $a1
  move  $s2, $a2
  sw    $ra, 0x24($sp)
  sw    $a0, 0x80($sp)
  sw    $a3, 0x8c($sp)
  addiu $a3, $sp, 0x74
  addiu $a2, $sp, 0x78
  addiu $a1, $sp, 0x30
  jal   sub_GAME_7F08A274
   lw    $a0, 0xa8($t6)
  lw    $v1, 0x80($sp)
  lw    $v0, ($s0)
  addiu $a0, $sp, 0x50
  lwc1  $f4, ($v1)
  lwc1  $f6, 0x48c($v0)
  addiu $a1, $sp, 0x48
  addiu $a2, $sp, 0x40
  sub.s $f8, $f4, $f6
  lwc1  $f4, 0x30($sp)
  addiu $a3, $sp, 0x38
  swc1  $f8, 0x5c($sp)
  lwc1  $f10, 8($v1)
  lwc1  $f16, 0x494($v0)
  swc1  $f4, 0x50($sp)
  sub.s $f18, $f10, $f16
  swc1  $f18, 0x64($sp)
  lwc1  $f6, 0x48c($v0)
  swc1  $f6, 0x54($sp)
  lwc1  $f8, 0x494($v0)
  lwc1  $f6, 0x5c($sp)
  swc1  $f8, 0x58($sp)
  lwc1  $f10, ($s1)
  lwc1  $f8, 0x64($sp)
  swc1  $f10, 0x48($sp)
  lwc1  $f16, 8($s1)
  swc1  $f16, 0x4c($sp)
  lwc1  $f18, ($s2)
  swc1  $f18, 0x40($sp)
  lwc1  $f4, 8($s2)
  swc1  $f6, 0x38($sp)
  swc1  $f8, 0x3c($sp)
  jal   sub_GAME_7F0B33DC
   swc1  $f4, 0x44($sp)
  lwc1  $f10, 0x5c($sp)
  li    $at, 0x3E800000 # 0.250000
  mtc1  $at, $f2
  mul.s $f16, $f10, $f0
  lwc1  $f8, 0x64($sp)
  lw    $v0, ($s0)
  addiu $a0, $sp, 0x68
  addiu $a1, $sp, 0x7c
  lwc1  $f4, 0x48c($v0)
  mul.s $f18, $f16, $f2
  nop   
  mul.s $f10, $f8, $f0
  add.s $f6, $f18, $f4
  mul.s $f16, $f10, $f2
  swc1  $f6, 0x68($sp)
  lwc1  $f18, 0x494($v0)
  add.s $f4, $f16, $f18
  jal   cal_player_collision
   swc1  $f4, 0x70($sp)
  beqz  $v0, .L7F07D3F8
   lw    $t7, 0x7c($sp)
  lw    $t8, ($s0)
  li    $v0, 1
  sw    $t7, 0x488($t8)
  lw    $t9, ($s0)
  lwc1  $f6, 0x68($sp)
  swc1  $f6, 0x48c($t9)
  lw    $t0, ($s0)
  lwc1  $f8, 0x70($sp)
  b     .L7F07D4A8
   swc1  $f8, 0x494($t0)
.L7F07D3F8:
  lw    $s0, 0x90($sp)
  lw    $a0, 0x8c($sp)
  jal   sub_GAME_7F0B28B0
   move  $a1, $s0
  lw    $v1, 0x8c($sp)
  lwc1  $f16, ($s1)
  lwc1  $f10, ($v1)
  c.eq.s $f10, $f16
  nop   
  bc1f  .L7F07D4A0
   nop   
  lwc1  $f18, 4($v1)
  lwc1  $f4, 4($s1)
  c.eq.s $f18, $f4
  nop   
  bc1f  .L7F07D4A0
   nop   
  lwc1  $f6, 8($v1)
  lwc1  $f8, 8($s1)
  c.eq.s $f6, $f8
  nop   
  bc1f  .L7F07D4A0
   nop   
  lwc1  $f10, ($s0)
  lwc1  $f16, ($s2)
  c.eq.s $f10, $f16
  nop   
  bc1f  .L7F07D4A0
   nop   
  lwc1  $f18, 4($s0)
  lwc1  $f4, 4($s2)
  c.eq.s $f18, $f4
  nop   
  bc1f  .L7F07D4A0
   nop   
  lwc1  $f6, 8($s0)
  lwc1  $f8, 8($s2)
  li    $v0, -1
  c.eq.s $f6, $f8
  nop   
  bc1t  .L7F07D4A8
   nop   
.L7F07D4A0:
  b     .L7F07D4A8
   move  $v0, $zero
.L7F07D4A8:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x80
");

asm(R"
glabel sub_GAME_7F07D4C0
  lui   $v1, %hi(pPlayer)
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $v0, ($v1)
  addiu $sp, $sp, -0x50
  sw    $ra, 0x14($sp)
  lwc1  $f4, ($a0)
  lwc1  $f6, 0x48c($v0)
  sub.s $f8, $f4, $f6
  swc1  $f8, 0x44($sp)
  lwc1  $f10, 8($a0)
  lwc1  $f16, 0x494($v0)
  sub.s $f18, $f10, $f16
  swc1  $f18, 0x4c($sp)
  lwc1  $f2, ($a2)
  lwc1  $f0, ($a1)
  c.eq.s $f0, $f2
  nop   
  bc1fl .L7F07D52C
   sub.s $f8, $f2, $f0
  lwc1  $f4, 8($a1)
  lwc1  $f6, 8($a2)
  li    $v0, -1
  c.eq.s $f4, $f6
  nop   
  bc1t  .L7F07D60C
   nop   
  sub.s $f8, $f2, $f0
.L7F07D52C:
  swc1  $f8, 0x34($sp)
  lwc1  $f16, 8($a1)
  lwc1  $f10, 8($a2)
  lwc1  $f8, 0x34($sp)
  sub.s $f18, $f10, $f16
  swc1  $f18, 0x3c($sp)
  lwc1  $f4, 0x3c($sp)
  mul.s $f6, $f4, $f4
  nop   
  mul.s $f10, $f8, $f8
  jal   sqrtf
   add.s $f12, $f6, $f10
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f16
  lwc1  $f18, 0x34($sp)
  lwc1  $f8, 0x3c($sp)
  div.s $f2, $f16, $f0
  lwc1  $f10, 0x4c($sp)
  lui   $v1, %hi(pPlayer)
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $v0, ($v1)
  addiu $a0, $sp, 0x28
  addiu $a1, $sp, 0x24
  mul.s $f4, $f18, $f2
  lwc1  $f18, 0x44($sp)
  mul.s $f6, $f8, $f2
  swc1  $f4, 0x34($sp)
  mul.s $f16, $f6, $f10
  swc1  $f6, 0x3c($sp)
  mul.s $f8, $f18, $f4
  lwc1  $f18, 0x48c($v0)
  add.s $f12, $f16, $f8
  mul.s $f10, $f4, $f12
  add.s $f16, $f10, $f18
  mul.s $f8, $f6, $f12
  swc1  $f16, 0x28($sp)
  lwc1  $f4, 0x494($v0)
  add.s $f10, $f8, $f4
  jal   cal_player_collision
   swc1  $f10, 0x30($sp)
  lui   $v1, %hi(pPlayer)
  beqz  $v0, .L7F07D604
   addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $t6, 0x24($sp)
  lw    $t7, ($v1)
  li    $v0, 1
  sw    $t6, 0x488($t7)
  lw    $t8, ($v1)
  lwc1  $f18, 0x28($sp)
  swc1  $f18, 0x48c($t8)
  lw    $t9, ($v1)
  lwc1  $f16, 0x30($sp)
  b     .L7F07D60C
   swc1  $f16, 0x494($t9)
.L7F07D604:
  b     .L7F07D60C
   move  $v0, $zero
.L7F07D60C:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x50
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F07D61C
  addiu $sp, $sp, -0x68
  sw    $s3, 0x20($sp)
  lui   $s3, %hi(pPlayer)
  addiu $s3, %lo(pPlayer) # addiu $s3, $s3, -0x5f50
  lw    $t6, ($s3)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  move  $s0, $a0
  move  $s1, $a1
  move  $s2, $a2
  sw    $ra, 0x24($sp)
  addiu $a2, $sp, 0x40
  addiu $a1, $sp, 0x30
  addiu $a3, $sp, 0x3c
  jal   sub_GAME_7F08A274
   lw    $a0, 0xa8($t6)
  lw    $v0, ($s3)
  lwc1  $f4, ($s0)
  lwc1  $f6, 0x48c($v0)
  sub.s $f8, $f4, $f6
  swc1  $f8, 0x5c($sp)
  lwc1  $f10, 8($s0)
  lwc1  $f16, 0x494($v0)
  sub.s $f18, $f10, $f16
  swc1  $f18, 0x64($sp)
  lwc1  $f6, ($s0)
  lwc1  $f4, ($s1)
  sub.s $f8, $f4, $f6
  lwc1  $f4, 0x30($sp)
  swc1  $f8, 0x50($sp)
  lwc1  $f16, 8($s0)
  lwc1  $f10, 8($s1)
  mul.s $f0, $f4, $f4
  sub.s $f18, $f10, $f16
  lwc1  $f10, 0x50($sp)
  swc1  $f18, 0x58($sp)
  lwc1  $f6, 0x58($sp)
  mul.s $f8, $f6, $f6
  nop   
  mul.s $f16, $f10, $f10
  add.s $f18, $f8, $f16
  c.le.s $f18, $f0
  nop   
  bc1f  .L7F07D7E0
   nop   
  lwc1  $f4, ($s1)
  lwc1  $f6, 0x48c($v0)
  c.eq.s $f4, $f6
  nop   
  bc1fl .L7F07D708
   lwc1  $f16, 8($s1)
  lwc1  $f10, 8($s1)
  lwc1  $f8, 0x494($v0)
  c.eq.s $f10, $f8
  nop   
  bc1tl .L7F07D938
   move  $v0, $zero
  lwc1  $f16, 8($s1)
.L7F07D708:
  lwc1  $f18, 0x494($v0)
  sub.s $f4, $f16, $f18
  neg.s $f6, $f4
  swc1  $f6, 0x50($sp)
  lwc1  $f8, 0x48c($v0)
  lwc1  $f10, ($s1)
  mul.s $f18, $f6, $f6
  sub.s $f16, $f10, $f8
  swc1  $f16, 0x58($sp)
  lwc1  $f4, 0x58($sp)
  mul.s $f10, $f4, $f4
  jal   sqrtf
   add.s $f12, $f10, $f18
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  lwc1  $f16, 0x50($sp)
  lwc1  $f4, 0x58($sp)
  div.s $f2, $f8, $f0
  lwc1  $f18, 0x64($sp)
  lw    $v0, ($s3)
  addiu $a0, $sp, 0x44
  addiu $a1, $sp, 0x34
  mul.s $f6, $f16, $f2
  lwc1  $f16, 0x5c($sp)
  mul.s $f10, $f4, $f2
  swc1  $f6, 0x50($sp)
  mul.s $f8, $f10, $f18
  swc1  $f10, 0x58($sp)
  mul.s $f4, $f16, $f6
  add.s $f12, $f8, $f4
  mul.s $f18, $f6, $f12
  nop   
  mul.s $f16, $f10, $f12
  swc1  $f18, 0x50($sp)
  swc1  $f16, 0x58($sp)
  lwc1  $f8, 0x48c($v0)
  add.s $f4, $f18, $f8
  swc1  $f4, 0x44($sp)
  lwc1  $f6, 0x494($v0)
  add.s $f10, $f16, $f6
  jal   cal_player_collision
   swc1  $f10, 0x4c($sp)
  beqz  $v0, .L7F07D934
   lw    $t7, 0x34($sp)
  lw    $t8, ($s3)
  li    $v0, 1
  sw    $t7, 0x488($t8)
  lw    $t9, ($s3)
  lwc1  $f18, 0x44($sp)
  swc1  $f18, 0x48c($t9)
  lw    $t0, ($s3)
  lwc1  $f8, 0x4c($sp)
  b     .L7F07D938
   swc1  $f8, 0x494($t0)
.L7F07D7E0:
  lwc1  $f4, ($s2)
  lwc1  $f16, ($s0)
  sub.s $f6, $f4, $f16
  swc1  $f6, 0x50($sp)
  lwc1  $f18, 8($s0)
  lwc1  $f10, 8($s2)
  lwc1  $f6, 0x50($sp)
  sub.s $f8, $f10, $f18
  swc1  $f8, 0x58($sp)
  lwc1  $f4, 0x58($sp)
  mul.s $f16, $f4, $f4
  nop   
  mul.s $f10, $f6, $f6
  add.s $f18, $f16, $f10
  c.le.s $f18, $f0
  nop   
  bc1f  .L7F07D934
   nop   
  lwc1  $f8, ($s2)
  lwc1  $f4, 0x48c($v0)
  c.eq.s $f8, $f4
  nop   
  bc1fl .L7F07D85C
   lwc1  $f10, 8($s2)
  lwc1  $f6, 8($s2)
  lwc1  $f16, 0x494($v0)
  c.eq.s $f6, $f16
  nop   
  bc1tl .L7F07D938
   move  $v0, $zero
  lwc1  $f10, 8($s2)
.L7F07D85C:
  lwc1  $f18, 0x494($v0)
  sub.s $f8, $f10, $f18
  neg.s $f4, $f8
  swc1  $f4, 0x50($sp)
  lwc1  $f16, 0x48c($v0)
  lwc1  $f6, ($s2)
  mul.s $f18, $f4, $f4
  sub.s $f10, $f6, $f16
  swc1  $f10, 0x58($sp)
  lwc1  $f8, 0x58($sp)
  mul.s $f6, $f8, $f8
  jal   sqrtf
   add.s $f12, $f6, $f18
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f16
  lwc1  $f10, 0x50($sp)
  lwc1  $f8, 0x58($sp)
  div.s $f2, $f16, $f0
  lwc1  $f18, 0x64($sp)
  lw    $v0, ($s3)
  addiu $a0, $sp, 0x44
  addiu $a1, $sp, 0x34
  mul.s $f4, $f10, $f2
  lwc1  $f10, 0x5c($sp)
  mul.s $f6, $f8, $f2
  swc1  $f4, 0x50($sp)
  mul.s $f16, $f6, $f18
  swc1  $f6, 0x58($sp)
  mul.s $f8, $f10, $f4
  add.s $f12, $f16, $f8
  mul.s $f18, $f4, $f12
  nop   
  mul.s $f10, $f6, $f12
  swc1  $f18, 0x50($sp)
  swc1  $f10, 0x58($sp)
  lwc1  $f16, 0x48c($v0)
  add.s $f8, $f18, $f16
  swc1  $f8, 0x44($sp)
  lwc1  $f4, 0x494($v0)
  add.s $f6, $f10, $f4
  jal   cal_player_collision
   swc1  $f6, 0x4c($sp)
  beqz  $v0, .L7F07D934
   lw    $t1, 0x34($sp)
  lw    $t2, ($s3)
  li    $v0, 1
  sw    $t1, 0x488($t2)
  lw    $t3, ($s3)
  lwc1  $f18, 0x44($sp)
  swc1  $f18, 0x48c($t3)
  lw    $t4, ($s3)
  lwc1  $f16, 0x4c($sp)
  b     .L7F07D938
   swc1  $f16, 0x494($t4)
.L7F07D934:
  move  $v0, $zero
.L7F07D938:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x68
");

asm(R"
glabel sub_GAME_7F07D954
  mtc1  $a0, $f0
  jr    $ra
   sw    $a0, ($sp)
");

asm(R"
glabel sub_GAME_7F07D960
  lui   $v1, %hi(pPlayer)
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  addiu $sp, $sp, -0xc0
  lw    $v0, ($v1)
  sw    $ra, 0x24($sp)
  sw    $s0, 0x20($sp)
  sw    $a1, 0xc4($sp)
  lwc1  $f4, 0x48c($v0)
  lui   $at, %hi(D_80036480)
  li    $t6, 2
  swc1  $f4, 0x408($v0)
  lw    $v0, ($v1)
  lui   $a3, %hi(D_8003644C)
  addiu $a1, $sp, 0x98
  lwc1  $f6, 0x490($v0)
  swc1  $f6, 0x40c($v0)
  lw    $v0, ($v1)
  lwc1  $f8, 0x494($v0)
  swc1  $f8, 0x410($v0)
  lw    $v0, ($v1)
  lwc1  $f10, ($a0)
  lwc1  $f16, 0x48c($v0)
  add.s $f18, $f10, $f16
  swc1  $f18, 0xb4($sp)
  lwc1  $f4, 8($a0)
  lwc1  $f6, 0x494($v0)
  sw    $zero, %lo(D_80036480)($at)
  add.s $f8, $f4, $f6
  swc1  $f8, 0xbc($sp)
  sw    $t6, 0x29fc($v0)
  lw    $a3, %lo(D_8003644C)($a3)
  beqz  $a3, .L7F07DBF0
   move  $a0, $a3
  jal   sub_GAME_7F03CCB0
   addiu $a2, $sp, 0x94
  lui   $t7, %hi(in_tank_flag) 
  lw    $t7, %lo(in_tank_flag)($t7)
  li    $at, 1
  lui   $a0, %hi(pPlayer)
  beq   $t7, $at, .L7F07DA3C
   lw    $a1, 0x98($sp)
  lw    $a0, %lo(pPlayer)($a0)
  lw    $a2, 0x94($sp)
  jal   sub_GAME_7F03CCD8
   addiu $a0, $a0, 0x48c
  bnez  $v0, .L7F07DA3C
   lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lw    $a2, 0x98($sp)
  lw    $a3, 0x94($sp)
  addiu $a0, $v0, 0x48c
  jal   sub_GAME_7F044718
   lw    $a1, 0x4b0($v0)
  beqz  $v0, .L7F07DBC8
   lui   $a1, %hi(ptr_playerstank)
.L7F07DA3C:
  lui   $a3, %hi(D_8003644C)
  lw    $a3, %lo(D_8003644C)($a3)
  lui   $a1, %hi(ptr_playerstank)
  addiu $a1, %lo(ptr_playerstank) # addiu $a1, $a1, 0x6450
  lw    $v0, 4($a3)
  lui   $t5, %hi(in_tank_flag) 
  li    $at, 1
  lw    $t8, 0x14($v0)
  move  $s0, $v0
  lw    $t9, 8($t8)
  lw    $a0, 8($t9)
  lw    $t2, 0x14($a0)
  lw    $t3, 0x18($a0)
  lui   $a0, %hi(pPlayer)
  lw    $v1, 4($t2)
  lw    $t1, 4($t3)
  sw    $a3, ($a1)
  lwc1  $f16, 0xc($v1)
  lwc1  $f10, 0x10($v1)
  lw    $t4, 0x14($v0)
  lw    $t5, %lo(in_tank_flag)($t5)
  sub.s $f18, $f10, $f16
  lwc1  $f0, 0x14($t4)
  addiu $a1, $v0, 0x84
  mul.s $f2, $f18, $f0
  beql  $t5, $at, .L7F07DAD8
   lwc1  $f4, 0x10($t1)
  lw    $a0, %lo(pPlayer)($a0)
  lw    $a2, 0x80($v0)
  swc1  $f2, 0x80($sp)
  sw    $t1, 0x84($sp)
  jal   sub_GAME_7F03CCD8
   addiu $a0, $a0, 0x48c
  lw    $t1, 0x84($sp)
  beqz  $v0, .L7F07DAF4
   lwc1  $f2, 0x80($sp)
  lw    $t6, 0x14($s0)
  lwc1  $f0, 0x14($t6)
  lwc1  $f4, 0x10($t1)
.L7F07DAD8:
  lwc1  $f6, 0xc($t1)
  li    $t7, 1
  lui   $at, %hi(D_80036480)
  sub.s $f8, $f4, $f6
  sw    $t7, %lo(D_80036480)($at)
  mul.s $f10, $f8, $f0
  add.s $f2, $f2, $f10
.L7F07DAF4:
  lui   $v1, %hi(in_tank_flag)
  lw    $v1, %lo(in_tank_flag)($v1)
  lui   $v0, %hi(D_80036454)
  addiu $v0, %lo(D_80036454) # addiu $v0, $v0, 0x6454
  bnez  $v1, .L7F07DB58
   nop   
  lwc1  $f0, ($v0)
  li    $at, 0x41A00000 # 20.000000
  c.lt.s $f0, $f2
  nop   
  bc1f  .L7F07DB58
   nop   
  mtc1  $at, $f16
  lui   $at, %hi(global_timer_delta)
  lwc1  $f18, %lo(global_timer_delta)($at)
  mul.s $f4, $f16, $f18
  add.s $f6, $f0, $f4
  swc1  $f6, ($v0)
  lwc1  $f8, ($v0)
  c.lt.s $f2, $f8
  nop   
  bc1fl .L7F07DE54
   lw    $ra, 0x24($sp)
  b     .L7F07DB64
   swc1  $f2, ($v0)
.L7F07DB58:
  lui   $v0, %hi(D_80036454)
  addiu $v0, %lo(D_80036454) # addiu $v0, $v0, 0x6454
  swc1  $f2, ($v0)
.L7F07DB64:
  li    $at, 1
  bne   $v1, $at, .L7F07DBF0
   lui   $t8, %hi(dword_CODE_bss_800799B8) 
  lw    $t8, %lo(dword_CODE_bss_800799B8)($t8)
  lui   $at, 0xc214
  bnezl $t8, .L7F07DBB4
   lwc1  $f16, ($v0)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  lui    $at, %hi(flt_CODE_bss_800799C0)
  lwc1  $f16, %lo(flt_CODE_bss_800799C0)($at)
  li    $at, 0xC2140000 # -37.000000
  mtc1  $at, $f4
  sub.s $f18, $f10, $f16
  lwc1  $f8, ($v0)
  mul.s $f6, $f4, $f18
  add.s $f10, $f8, $f6
  b     .L7F07DBF0
   swc1  $f10, ($v0)
  lwc1  $f16, ($v0)
.L7F07DBB4:
  mtc1  $at, $f4
  nop   
  add.s $f18, $f16, $f4
  b     .L7F07DBF0
   swc1  $f18, ($v0)
.L7F07DBC8:
  addiu $a1, $a1, %lo(ptr_playerstank)
  lw    $t9, ($a1)
  lui   $v0, %hi(D_80036454)
  addiu $v0, %lo(D_80036454) # addiu $v0, $v0, 0x6454
  beqz  $t9, .L7F07DBF0
   lui   $at, %hi(D_8003644C)
  mtc1  $zero, $f8
  sw    $zero, %lo(D_8003644C)($at)
  sw    $zero, ($a1)
  swc1  $f8, ($v0)
.L7F07DBF0:
  addiu $s0, $sp, 0xb4
  move  $a0, $s0
  addiu $a1, $sp, 0xa8
  jal   sub_GAME_7F07D234
   addiu $a2, $sp, 0x9c
  bnez  $v0, .L7F07DCE4
   move  $a0, $s0
  addiu $t2, $sp, 0x68
  sw    $t2, 0x10($sp)
  addiu $a1, $sp, 0xa8
  addiu $a2, $sp, 0x9c
  jal   sub_GAME_7F07D2B4
   addiu $a3, $sp, 0x74
  bgtz  $v0, .L7F07DC34
   lw    $t3, 0xc4($sp)
  bgez  $v0, .L7F07DC6C
   nop   
.L7F07DC34:
  beqz  $t3, .L7F07DCE4
   move  $a0, $s0
  addiu $a1, $sp, 0xa8
  jal   sub_GAME_7F07D4C0
   addiu $a2, $sp, 0x9c
  bgtz  $v0, .L7F07DCE4
   move  $a0, $s0
  addiu $a1, $sp, 0xa8
  jal   sub_GAME_7F07D61C
   addiu $a2, $sp, 0x9c
  bnez  $v0, .L7F07DCE4
   nop   
  b     .L7F07DCE4
   nop   
.L7F07DC6C:
  bnez  $v0, .L7F07DCE4
   move  $a0, $s0
  addiu $t4, $sp, 0x4c
  sw    $t4, 0x10($sp)
  addiu $a1, $sp, 0x74
  addiu $a2, $sp, 0x68
  jal   sub_GAME_7F07D2B4
   addiu $a3, $sp, 0x58
  lw    $t5, 0xc4($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x74
  beqz  $t5, .L7F07DCE4
   nop   
  jal   sub_GAME_7F07D4C0
   addiu $a2, $sp, 0x68
  bgtz  $v0, .L7F07DCE4
   move  $a0, $s0
  addiu $a1, $sp, 0xa8
  jal   sub_GAME_7F07D4C0
   addiu $a2, $sp, 0x9c
  bgtz  $v0, .L7F07DCE4
   move  $a0, $s0
  addiu $a1, $sp, 0x74
  jal   sub_GAME_7F07D61C
   addiu $a2, $sp, 0x68
  bnez  $v0, .L7F07DCE4
   move  $a0, $s0
  addiu $a1, $sp, 0xa8
  jal   sub_GAME_7F07D61C
   addiu $a2, $sp, 0x9c
.L7F07DCE4:
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lw    $a0, 0x488($v0)
  lw    $a1, 0x48c($v0)
  jal   sub_GAME_7F0B0518
   lw    $a2, 0x494($v0)
  bnez  $v0, .L7F07DE28
   lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  move  $t0, $zero
  lw    $s0, 0x488($t6)
  lh    $a2, 6($s0)
.L7F07DD14:
  move  $v1, $zero
  move  $a0, $zero
  sra   $t7, $a2, 0xc
  andi  $t8, $t7, 0xf
  blez  $t8, .L7F07DD5C
   move  $v0, $s0
  move  $v1, $zero
  sll   $a1, $t8, 3
.L7F07DD34:
  lhu   $t9, 0xe($v0)
  addiu $v1, $v1, 8
  slt   $at, $v1, $a1
  sra   $t2, $t9, 4
  beqz  $t2, .L7F07DD50
   nop   
  addiu $a0, $a0, 1
.L7F07DD50:
  bnez  $at, .L7F07DD34
   addiu $v0, $v0, 8
  move  $v1, $zero
.L7F07DD5C:
  sw    $v1, 0x44($sp)
  sw    $a0, 0x3c($sp)
  jal   get_random_value
   sw    $t0, 0x48($sp)
  lw    $a0, 0x3c($sp)
  lh    $a2, 6($s0)
  lw    $v1, 0x44($sp)
  divu  $zero, $v0, $a0
  sra   $t3, $a2, 0xc
  mfhi  $a3
  andi  $t4, $t3, 0xf
  lw    $t0, 0x48($sp)
  bnez  $a0, .L7F07DD98
   nop   
  break 7
.L7F07DD98:
  move  $a0, $zero
  blez  $t4, .L7F07DDE4
   move  $a2, $t4
  move  $v0, $s0
.L7F07DDA8:
  lhu   $a1, 0xe($v0)
  addiu $v1, $v1, 1
  slt   $at, $v1, $a2
  sra   $t5, $a1, 4
  beqz  $t5, .L7F07DDDC
   nop   
  bne   $a0, $a3, .L7F07DDD8
   lui   $t7, %hi(base_ptr_connection_vals) 
  lw    $t7, %lo(base_ptr_connection_vals)($t7)
  sll   $t6, $a1, 3
  b     .L7F07DDE4
   addu  $s0, $t6, $t7
.L7F07DDD8:
  addiu $a0, $a0, 1
.L7F07DDDC:
  bnez  $at, .L7F07DDA8
   addiu $v0, $v0, 8
.L7F07DDE4:
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  move  $a0, $s0
  lw    $a1, 0x48c($v0)
  lw    $a2, 0x494($v0)
  jal   sub_GAME_7F0B0518
   sw    $t0, 0x48($sp)
  beqz  $v0, .L7F07DE18
   lw    $t0, 0x48($sp)
  lui   $t8, %hi(pPlayer) 
  lw    $t8, %lo(pPlayer)($t8)
  b     .L7F07DE28
   sw    $s0, 0x488($t8)
.L7F07DE18:
  addiu $t0, $t0, 1
  li    $at, 5
  bnel  $t0, $at, .L7F07DD14
   lh    $a2, 6($s0)
.L7F07DE28:
  lui   $a0, %hi(pPlayer)
  jal   sub_GAME_7F07DE9C
   lw    $a0, %lo(pPlayer)($a0)
  lui   $t9, %hi(pPlayer) 
  lw    $t9, %lo(pPlayer)($t9)
  lw    $v0, 0x488($t9)
  beql  $v0, $zero, .L7F07DE54
   lw    $ra, 0x24($sp)
  jal   sub_GAME_7F057744
   lbu   $a0, 3($v0)
  lw    $ra, 0x24($sp)
.L7F07DE54:
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0xc0
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F07DE64
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  move  $a2, $a0
  lh    $a1, 0x2a04($a2)
  lw    $a0, 0xa8($a0)
  jal   sub_GAME_7F03DE94
   sw    $a2, 0x18($sp)
  lw    $a2, 0x18($sp)
  li    $t6, -1
  sh    $t6, 0x2a04($a2)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F07DE9C
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F07DE64
   sw    $a0, 0x18($sp)
  lw    $a2, 0x18($sp)
  lw    $a0, 0xa8($a2)
  lw    $a1, 4($a0)
  beql  $a1, $zero, .L7F07DED4
   lw    $v0, 0x488($a2)
  jal   sub_GAME_7F020D94
   move  $a0, $a1
  b     .L7F07DEF0
   lw    $ra, 0x14($sp)
  lw    $v0, 0x488($a2)
.L7F07DED4:
  beql  $v0, $zero, .L7F07DEF0
   lw    $ra, 0x14($sp)
  lbu   $t6, 3($v0)
  sh    $t6, 0x2a04($a2)
  jal   sub_GAME_7F03DD9C
   lh    $a1, 0x2a04($a2)
  lw    $ra, 0x14($sp)
.L7F07DEF0:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F07DEFC
  lui   $v1, %hi(pPlayer)
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $v0, ($v1)
  mtc1  $zero, $f6
  lwc1  $f4, 0x158($v0)
  swc1  $f4, 0x204($v0)
  lw    $t6, ($v1)
  swc1  $f6, 0x210($t6)
  lw    $t7, ($v1)
  jr    $ra
   sw    $zero, 0x218($t7)
");


asm(R"
glabel sub_GAME_7F07DF28
  beqz  $a0, .L7F07DF58
   lui   $v1, %hi(pPlayer)
  lui   $v1, %hi(pPlayer)
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $v0, ($v1)
  li    $at, 0xC2200000 # -40.000000
  mtc1  $at, $f6
  lwc1  $f4, 0x158($v0)
  swc1  $f4, 0x208($v0)
  lw    $t6, ($v1)
  b     .L7F07DF74
   swc1  $f6, 0x20c($t6)
.L7F07DF58:
  addiu $v1, $v1, %lo(pPlayer)
  lw    $v0, ($v1)
  lwc1  $f8, 0x204($v0)
  swc1  $f8, 0x208($v0)
  lw    $v0, ($v1)
  lwc1  $f10, 0x158($v0)
  swc1  $f10, 0x20c($v0)
.L7F07DF74:
  lw    $v0, ($v1)
  mtc1  $zero, $f12
  li    $at, 0x42700000 # 60.000000
  lwc1  $f16, 0x208($v0)
  lwc1  $f18, 0x20c($v0)
  mtc1  $at, $f14
  sub.s $f0, $f16, $f18
  c.lt.s $f0, $f12
  nop   
  bc1fl .L7F07DFA8
   c.le.s $f14, $f0
  neg.s $f0, $f0
  c.le.s $f14, $f0
.L7F07DFA8:
  nop   
  bc1fl .L7F07DFE0
   c.le.s $f0, $f12
  sub.s $f4, $f0, $f14
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f8
  mul.s $f6, $f4, $f14
  nop   
  mul.s $f10, $f6, $f8
  div.s $f16, $f10, $f14
  add.s $f2, $f16, $f14
  jr    $ra
   mov.s $f0, $f2

  c.le.s $f0, $f12
.L7F07DFE0:
  li    $at, 0x42700000 # 60.000000
  bc1fl .L7F07DFFC
   mtc1  $at, $f12
  mov.s $f2, $f12
  jr    $ra
   mov.s $f0, $f12

  mtc1  $at, $f12
.L7F07DFFC:
  nop   
  mul.s $f18, $f0, $f12
  div.s $f2, $f18, $f12
  jr    $ra
   mov.s $f0, $f2
");

void sub_GAME_7F07E010(float arg0) {
  pPlayer->field_210 = 0.0f;
  pPlayer->field_214 = arg0;
  pPlayer->field_218 = 1;
}

void sub_GAME_7F07E03C(float arg0) {
  pPlayer->field_210 = 0.0f;
  pPlayer->field_214 = arg0;
  pPlayer->field_218 = 2;
}

asm(R"
glabel sub_GAME_7F07E068
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  lw    $v1, 0x218($t6)
  sltu  $v0, $zero, $v1
  beqz  $v0, .L7F07E088
   nop   
  xori  $v0, $v1, 3
  sltu  $v0, $zero, $v0
.L7F07E088:
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_8005506C
.word 0x40c90fdb /*6.2831855*/
glabel D_80055070
.word 0x40c90fdb /*6.2831855*/
glabel D_80055074
.word 0xbf333333 /*-0.69999999*/
glabel D_80055078
.word 0x3f333333 /*0.69999999*/

.text
glabel sub_GAME_7F07E090
  lui   $a0, %hi(pPlayer)
  addiu $a0, %lo(pPlayer) # addiu $a0, $a0, -0x5f50
  lw    $v0, ($a0)
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  lwc1  $f2, 0x158($v0)
  li    $at, 1
  swc1  $f2, 0x1c($sp)
  lw    $v1, 0x218($v0)
  bne   $v1, $at, .L7F07E17C
   lui   $at, %hi(global_timer_delta)
  lwc1  $f4, %lo(global_timer_delta)($at)
  lui   $at, %hi(watch_transition_time)
  lwc1  $f6, %lo(watch_transition_time)($at)
  lwc1  $f10, 0x210($v0)
  mul.s $f8, $f4, $f6
  add.s $f16, $f10, $f8
  swc1  $f16, 0x210($v0)
  lw    $v0, ($a0)
  lwc1  $f0, 0x210($v0)
  lwc1  $f2, 0x214($v0)
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F07E160
   lwc1  $f16, 0x20c($v0)
  div.s $f14, $f0, $f2
  lui   $at, %hi(D_8005506C)
  lwc1  $f18, %lo(D_8005506C)($at)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f6
  mul.s $f4, $f14, $f18
  nop   
  mul.s $f12, $f4, $f6
  jal   cosf
   nop   
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  lui   $a0, %hi(pPlayer)
  addiu $a0, %lo(pPlayer) # addiu $a0, $a0, -0x5f50
  sub.s $f8, $f10, $f0
  lw    $v0, ($a0)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f16
  lwc1  $f2, 0x208($v0)
  lwc1  $f4, 0x20c($v0)
  mul.s $f18, $f8, $f16
  sub.s $f6, $f4, $f2
  mul.s $f10, $f6, $f18
  add.s $f8, $f2, $f10
  b     .L7F07E170
   swc1  $f8, 0x158($v0)
  lwc1  $f16, 0x20c($v0)
.L7F07E160:
  li    $t6, 3
  swc1  $f16, 0x158($v0)
  lw    $t7, ($a0)
  sw    $t6, 0x218($t7)
.L7F07E170:
  lw    $v0, ($a0)
  b     .L7F07E248
   lwc1  $f2, 0x158($v0)
.L7F07E17C:
  li    $at, 2
  bne   $v1, $at, .L7F07E248
   lui   $at, %hi(global_timer_delta)
  lwc1  $f4, %lo(global_timer_delta)($at)
  lui   $at, %hi(watch_transition_time)
  lwc1  $f6, %lo(watch_transition_time)($at)
  lwc1  $f10, 0x210($v0)
  mul.s $f18, $f4, $f6
  add.s $f8, $f10, $f18
  swc1  $f8, 0x210($v0)
  lw    $v0, ($a0)
  lwc1  $f0, 0x210($v0)
  lwc1  $f2, 0x214($v0)
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F07E234
   lwc1  $f8, 0x208($v0)
  div.s $f14, $f0, $f2
  lui    $at, %hi(D_80055070)
  lwc1  $f16, %lo(D_80055070)($at)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f6
  mul.s $f4, $f14, $f16
  nop   
  mul.s $f12, $f4, $f6
  jal   cosf
   nop   
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  lui   $a0, %hi(pPlayer)
  addiu $a0, %lo(pPlayer) # addiu $a0, $a0, -0x5f50
  sub.s $f18, $f10, $f0
  lw    $v0, ($a0)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f8
  lwc1  $f12, 0x20c($v0)
  lwc1  $f4, 0x208($v0)
  mul.s $f16, $f18, $f8
  sub.s $f6, $f4, $f12
  mul.s $f10, $f6, $f16
  add.s $f18, $f12, $f10
  swc1  $f18, 0x158($v0)
  lw    $v0, ($a0)
  b     .L7F07E248
   lwc1  $f2, 0x158($v0)
  lwc1  $f8, 0x208($v0)
.L7F07E234:
  swc1  $f8, 0x158($v0)
  lw    $t8, ($a0)
  sw    $zero, 0x218($t8)
  lw    $v0, ($a0)
  lwc1  $f2, 0x158($v0)
.L7F07E248:
  li    $at, 0xC3340000 # -180.000000
  mtc1  $at, $f4
  li    $at, 0x43340000 # 180.000000
  lui   $t9, %hi(clock_timer) 
  c.lt.s $f2, $f4
  nop   
  bc1fl .L7F07E284
   mtc1  $at, $f16
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f12
  nop   
  add.s $f6, $f2, $f12
  b     .L7F07E2A8
   swc1  $f6, 0x158($v0)
  mtc1  $at, $f16
.L7F07E284:
  li    $at, 0x43B40000 # 360.000000
  c.le.s $f16, $f2
  nop   
  bc1f  .L7F07E2A8
   nop   
  mtc1  $at, $f12
  nop   
  sub.s $f10, $f2, $f12
  swc1  $f10, 0x158($v0)
.L7F07E2A8:
  lw    $t9, %lo(clock_timer)($t9)
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f12
  blez  $t9, .L7F07E378
   li    $at, 0x43340000 # 180.000000
  lw    $v0, ($a0)
  lwc1  $f8, 0x1c($sp)
  mtc1  $zero, $f6
  lwc1  $f18, 0x158($v0)
  mtc1  $at, $f10
  lui   $at, %hi(D_80055074)
  sub.s $f4, $f18, $f8
  swc1  $f4, 0x160($v0)
  lw    $v0, ($a0)
  lwc1  $f0, 0x160($v0)
  c.lt.s $f0, $f6
  nop   
  bc1fl .L7F07E308
   c.lt.s $f10, $f0
  add.s $f16, $f0, $f12
  swc1  $f16, 0x160($v0)
  lw    $v0, ($a0)
  lwc1  $f0, 0x160($v0)
  c.lt.s $f10, $f0
.L7F07E308:
  nop   
  bc1f  .L7F07E324
   nop   
  sub.s $f18, $f0, $f12
  swc1  $f18, 0x160($v0)
  lw    $v0, ($a0)
  lwc1  $f0, 0x160($v0)
.L7F07E324:
  lwc1  $f12, %lo(D_80055074)($at)
  lui   $at, %hi(global_timer_delta)
  lwc1  $f2, %lo(global_timer_delta)($at)
  lui   $at, %hi(D_80055078)
  add.s $f8, $f2, $f2
  div.s $f4, $f0, $f8
  swc1  $f4, 0x160($v0)
  lw    $v0, ($a0)
  lwc1  $f0, 0x160($v0)
  c.lt.s $f0, $f12
  nop   
  bc1f  .L7F07E360
   nop   
  b     .L7F07E378
   swc1  $f12, 0x160($v0)
.L7F07E360:
  lwc1  $f2, %lo(D_80055078)($at)
  c.lt.s $f2, $f0
  nop   
  bc1fl .L7F07E37C
   lw    $ra, 0x14($sp)
  swc1  $f2, 0x160($v0)
.L7F07E378:
  lw    $ra, 0x14($sp)
.L7F07E37C:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F07E388
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  li    $at, 1
  lw    $v1, 0x218($v0)
  bnel  $v1, $at, .L7F07E3B4
   li    $at, 2
  lwc1  $f4, 0x210($v0)
  lwc1  $f6, 0x214($v0)
  jr    $ra
   div.s $f0, $f4, $f6

  li    $at, 2
.L7F07E3B4:
  bnel  $v1, $at, .L7F07E3DC
   li    $at, 3
  lwc1  $f8, 0x210($v0)
  lwc1  $f10, 0x214($v0)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f18
  div.s $f16, $f8, $f10
  jr    $ra
   sub.s $f0, $f18, $f16

  li    $at, 3
.L7F07E3DC:
  bne   $v1, $at, .L7F07E3F0
   li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f0
  jr    $ra
   nop   

.L7F07E3F0:
  mtc1  $zero, $f0
  nop   
  jr    $ra
   nop   
");

void trigger_watch_zoom(float final,float time)
{
  pPlayer->zoomintime = 0.00000000;
  pPlayer->zoomintimemax = time;
  pPlayer->zoominfovyold = pPlayer->zoominfovy;
  pPlayer->zoominfovynew = final;
}

asm(R"
glabel sub_GAME_7F07E438
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lwc1  $f4, 0x11bc($v0)
  lwc1  $f6, 0x11c0($v0)
  c.lt.s $f4, $f6
  nop   
  bc1fl .L7F07E464
   lwc1  $f0, 0x11c4($v0)
  jr    $ra
   lwc1  $f0, 0x11cc($v0)

  lwc1  $f0, 0x11c4($v0)
.L7F07E464:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F07E46C
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F07E438
   swc1  $f12, 0x18($sp)
  lwc1  $f12, 0x18($sp)
  lui   $t6, %hi(pPlayer) 
  c.eq.s $f0, $f12
  nop   
  bc1tl .L7F07E4F8
   lw    $ra, 0x14($sp)
  lw    $t6, %lo(pPlayer)($t6)
  li    $at, 0x41700000 # 15.000000
  lwc1  $f0, 0x11c4($t6)
  c.lt.s $f12, $f0
  nop   
  bc1fl .L7F07E4DC
   sub.s $f16, $f12, $f0
  sub.s $f4, $f0, $f12
  li    $at, 0x41700000 # 15.000000
  mtc1  $at, $f6
  li    $at, 0x41F00000 # 30.000000
  mtc1  $at, $f10
  mul.s $f8, $f4, $f6
  jal   trigger_watch_zoom
   div.s $f14, $f8, $f10
  b     .L7F07E4F8
   lw    $ra, 0x14($sp)
  sub.s $f16, $f12, $f0
.L7F07E4DC:
  mtc1  $at, $f18
  li    $at, 0x41F00000 # 30.000000
  mtc1  $at, $f6
  mul.s $f4, $f16, $f18
  jal   trigger_watch_zoom
   div.s $f14, $f4, $f6
  lw    $ra, 0x14($sp)
.L7F07E4F8:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F07E504
  addiu $sp, $sp, -0x18
  li    $at, 0x42700000 # 60.000000
  sw    $ra, 0x14($sp)
  mtc1  $at, $f12
  jal   sub_GAME_7F07E46C
   nop   
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel final
.word 0x40bccccd /*5.9000001*/
glabel D_80055080
.word 0xc2586666 /*-54.099998*/
glabel D_80055084
.word 0xc2586666 /*-54.099998*/

.text
glabel zoom_to_watch_on_open
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lui   $at, %hi(final)
  lwc1  $f12, %lo(final)($at)
  lwc1  $f4, 0x11c4($t6)
  li    $at, 0x42340000 # 45.000000
  mtc1  $at, $f8
  sub.s $f6, $f12, $f4
  lui   $at, %hi(D_80055080)
  lwc1  $f16, %lo(D_80055080)($at)
  mtc1  $zero, $f18
  mul.s $f10, $f6, $f8
  div.s $f14, $f10, $f16
  c.lt.s $f14, $f18
  nop   
  bc1f  .L7F07E57C
   nop   
  neg.s $f14, $f14
.L7F07E57C:
  jal   trigger_watch_zoom
   nop   
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel zoom_from_watch_on_exit
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f12
  lwc1  $f4, 0x11c4($t6)
  li    $at, 0x42340000 # 45.000000
  mtc1  $at, $f8
  sub.s $f6, $f12, $f4
  lui   $at, %hi(D_80055084)
  lwc1  $f16, %lo(D_80055084)($at)
  mtc1  $zero, $f18
  mul.s $f10, $f6, $f8
  div.s $f14, $f10, $f16
  c.lt.s $f14, $f18
  nop   
  bc1f  .L7F07E5E4
   nop   
  neg.s $f14, $f14
.L7F07E5E4:
  jal   trigger_watch_zoom
   nop   
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel check_watch_page_transistion_running
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  move  $v0, $zero
  lwc1  $f4, 0x11bc($v1)
  lwc1  $f6, 0x11c0($v1)
  c.lt.s $f4, $f6
  nop   
  bc1f  .L7F07E624
   nop   
  li    $v0, 1
.L7F07E624:
  jr    $ra
   nop   
");

#ifdef VERSION_US
asm(R"
glabel sub_GAME_7F07E62C
  lui   $a0, %hi(pPlayer)
  addiu $a0, %lo(pPlayer) # addiu $a0, $a0, -0x5f50
  lw    $v0, ($a0)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lwc1  $f0, 0x11c0($v0)
  lwc1  $f12, 0x11bc($v0)
  c.lt.s $f12, $f0
  nop   
  bc1fl .L7F07E704
   swc1  $f0, 0x11bc($v0)
  lw    $v1, 0x1c8($v0)
  li    $at, 5
  lui   $t6, %hi(D_80048498) 
  beq   $v1, $at, .L7F07E674
   li    $at, 12
  bne   $v1, $at, .L7F07E690
   lui   $t7, %hi(D_80048498) 
.L7F07E674:
  lw    $t6, %lo(D_80048498)($t6)
  mtc1  $t6, $f4
  nop   
  cvt.s.w $f6, $f4
  add.s $f8, $f12, $f6
  b     .L7F07E6B4
   swc1  $f8, 0x11bc($v0)
.L7F07E690:
  lw    $t7, %lo(D_80048498)($t7)
  lui   $at, %hi(watch_transition_time)
  lwc1  $f18, %lo(watch_transition_time)($at)
  mtc1  $t7, $f10
  nop   
  cvt.s.w $f16, $f10
  mul.s $f4, $f16, $f18
  add.s $f6, $f12, $f4
  swc1  $f6, 0x11bc($v0)
.L7F07E6B4:
  lw    $v0, ($a0)
  lwc1  $f0, 0x11c0($v0)
  lwc1  $f12, 0x11bc($v0)
  c.lt.s $f0, $f12
  nop   
  bc1fl .L7F07E6E4
   lwc1  $f2, 0x11c8($v0)
  swc1  $f0, 0x11bc($v0)
  lw    $v0, ($a0)
  lwc1  $f12, 0x11bc($v0)
  lwc1  $f0, 0x11c0($v0)
  lwc1  $f2, 0x11c8($v0)
.L7F07E6E4:
  lwc1  $f8, 0x11cc($v0)
  sub.s $f10, $f8, $f2
  mul.s $f16, $f12, $f10
  div.s $f18, $f16, $f0
  add.s $f4, $f2, $f18
  b     .L7F07E710
   swc1  $f4, 0x11c4($v0)
  swc1  $f0, 0x11bc($v0)
.L7F07E704:
  lw    $v0, ($a0)
  lwc1  $f6, 0x11cc($v0)
  swc1  $f6, 0x11c4($v0)
.L7F07E710:
  lw    $t8, ($a0)
  jal   set_cur_player_fovy
   lwc1  $f12, 0x11c4($t8)
  lui   $a0, %hi(pPlayer)
  addiu $a0, %lo(pPlayer) # addiu $a0, $a0, -0x5f50
  lw    $t9, ($a0)
  jal   setvideo_far
   lwc1  $f12, 0x11c4($t9)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");
#endif

#ifdef VERSION_JP
asm(R"
glabel sub_GAME_7F07E62C
  lui   $a0, %hi(pPlayer) # $a0, 0x8008
  addiu $a0, %lo(pPlayer) # addiu $a0, $a0, -0x5ee0
  lw    $v0, ($a0)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lwc1  $f0, 0x11c0($v0)
  lwc1  $f12, 0x11bc($v0)
  c.lt.s $f12, $f0
  nop   
  bc1fl .Ljp7F07ED10
   swc1  $f0, 0x11bc($v0)
  lw    $v1, 0x1c8($v0)
  li    $at, 5
  beq   $v1, $at, .Ljp7F07EC90
   li    $at, 12
  bne   $v1, $at, .Ljp7F07ECA4
.Ljp7F07EC90:
   lui   $at, %hi(jpD_800484D0) # $at, 0x8005
  lwc1  $f4, %lo(jpD_800484D0)($at)
  add.s $f6, $f12, $f4
  b     .Ljp7F07ECC0
   swc1  $f6, 0x11bc($v0)
.Ljp7F07ECA4:
  lui   $at, %hi(jpD_800484D0) # $at, 0x8005
  lwc1  $f8, %lo(jpD_800484D0)($at)
  lui   $at, %hi(watch_transition_time) # $at, 0x8003
  lwc1  $f10, %lo(watch_transition_time)($at)
  mul.s $f16, $f8, $f10
  add.s $f18, $f12, $f16
  swc1  $f18, 0x11bc($v0)
.Ljp7F07ECC0:
  lw    $v0, ($a0)
  lwc1  $f0, 0x11c0($v0)
  lwc1  $f12, 0x11bc($v0)
  c.lt.s $f0, $f12
  nop   
  bc1fl .Ljp7F07ECF0
   lwc1  $f2, 0x11c8($v0)
  swc1  $f0, 0x11bc($v0)
  lw    $v0, ($a0)
  lwc1  $f12, 0x11bc($v0)
  lwc1  $f0, 0x11c0($v0)
  lwc1  $f2, 0x11c8($v0)
.Ljp7F07ECF0:
  lwc1  $f4, 0x11cc($v0)
  sub.s $f6, $f4, $f2
  mul.s $f8, $f12, $f6
  div.s $f10, $f8, $f0
  add.s $f16, $f2, $f10
  b     .Ljp7F07ED1C
   swc1  $f16, 0x11c4($v0)
  swc1  $f0, 0x11bc($v0)
.Ljp7F07ED10:
  lw    $v0, ($a0)
  lwc1  $f18, 0x11cc($v0)
  swc1  $f18, 0x11c4($v0)
.Ljp7F07ED1C:
  lw    $t6, ($a0)
  jal   set_cur_player_fovy
   lwc1  $f12, 0x11c4($t6)
  lui   $a0, %hi(pPlayer) # $a0, 0x8008
  addiu $a0, %lo(pPlayer) # addiu $a0, $a0, -0x5ee0
  lw    $t7, ($a0)
  jal   setvideo_far
   lwc1  $f12, 0x11c4($t7)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");
#endif

asm(R"
glabel sub_GAME_7F07E740
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  li    $at, 4
  lw    $v1, 0x1c8($v0)
  bne   $v1, $at, .L7F07E774
   li    $at, 0x42340000 # 45.000000
  mtc1  $at, $f2
  lwc1  $f4, 0x11c0($v0)
  lwc1  $f8, 0x11bc($v0)
  sub.s $f6, $f2, $f4
  add.s $f10, $f6, $f8
  jr    $ra
   div.s $f0, $f10, $f2

.L7F07E774:
  li    $at, 6
  bnel  $v1, $at, .L7F07E7A0
   li    $at, 5
  lwc1  $f16, 0x11c0($v0)
  lwc1  $f18, 0x11bc($v0)
  li    $at, 0x42340000 # 45.000000
  mtc1  $at, $f2
  sub.s $f4, $f16, $f18
  jr    $ra
   div.s $f0, $f4, $f2

  li    $at, 5
.L7F07E7A0:
  beq   $v1, $at, .L7F07E7AC
   li    $at, 12
  bne   $v1, $at, .L7F07E7BC
.L7F07E7AC:
   li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f0
  jr    $ra
   nop   

.L7F07E7BC:
  mtc1  $zero, $f0
  nop   
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80055088
.word 0x3dccccce /*0.10000001*/

.text
glabel sub_GAME_7F07E7CC
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  jal   get_ptr_itemheader_in_hand
   li    $a0, 1
  sw    $v0, 0x24($sp)
  jal   set_objuse_flag_compute_grp_nums_set_obj_loaded
   move  $a0, $v0
  lw    $t6, 0x24($sp)
  lh    $t7, 0x14($t6)
  slti  $at, $t7, 0x33
  bnez  $at, .L7F07E804
   nop   
  jal   return_null
   nop   
.L7F07E804:
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lw    $a1, 0x24($sp)
  addiu $a0, $v0, 0x230
  jal   sub_GAME_7F075FAC
   addiu $a2, $v0, 0x2ec
  lui   $at, %hi(c_item_entries+0x33C)
  lwc1  $f4, %lo(c_item_entries+0x33C)($at)
  lui   $at, %hi(D_80055088)
  lwc1  $f6, %lo(D_80055088)($at)
  lui   $a0, %hi(pPlayer)
  lw    $a0, %lo(pPlayer)($a0)
  mul.s $f8, $f4, $f6
  addiu $a0, $a0, 0x230
  mfc1  $a1, $f8
  jal   set_obj_instance_controller_scale
   nop   
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f10
  lui   $at, %hi(watch_transition_time)
  lwc1  $f16, %lo(watch_transition_time)($at)
  mtc1  $zero, $f0
  lui   $a0, %hi(pPlayer)
  mul.s $f18, $f10, $f16
  lui   $t8, %hi(ptr_animation_table) 
  lw    $t8, %lo(ptr_animation_table)($t8)
  lw    $a0, %lo(pPlayer)($a0)
  lui   $t9, %hi(0x000042C8) # $t9, 0
  addiu $t9, %lo(0x000042C8) # addiu $t9, $t9, 0x42c8
  mfc1  $a3, $f0
  swc1  $f18, 0x10($sp)
  move  $a2, $zero
  swc1  $f0, 0x14($sp)
  addu  $a1, $t8, $t9
  jal   sub_GAME_7F06FCA8
   addiu $a0, $a0, 0x230
  lui   $t0, %hi(pPlayer) 
  lw    $t0, %lo(pPlayer)($t0)
  sw    $zero, 0x220($t0)
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F07E8B0
  lui   $v1, %hi(pPlayer)
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $v0, ($v1)
  li    $at, 0x41A00000 # 20.000000
  lw    $t6, 0x220($v0)
  bnezl $t6, .L7F07E8E8
   mtc1  $at, $f8
  li    $at, 0x41A00000 # 20.000000
  mtc1  $at, $f4
  nop   
  div.s $f6, $f4, $f12
  b     .L7F07E8F8
   swc1  $f6, 0x22c($v0)
  mtc1  $at, $f8
.L7F07E8E8:
  lwc1  $f10, 0x258($v0)
  sub.s $f16, $f8, $f10
  div.s $f18, $f16, $f12
  swc1  $f18, 0x22c($v0)
.L7F07E8F8:
  lw    $t8, ($v1)
  li    $t7, 1
  sw    $t7, 0x220($t8)
  lw    $t9, ($v1)
  jr    $ra
   swc1  $f12, 0x228($t9)
");

asm(R"
glabel sub_GAME_7F07E910
  lui   $v1, %hi(pPlayer)
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $v0, ($v1)
  li    $at, 3
  lw    $t6, 0x220($v0)
  bne   $t6, $at, .L7F07E940
   li    $at, 0x41A00000 # 20.000000
  mtc1  $at, $f4
  nop   
  div.s $f6, $f4, $f12
  b     .L7F07E94C
   swc1  $f6, 0x22c($v0)
.L7F07E940:
  lwc1  $f8, 0x258($v0)
  div.s $f10, $f8, $f12
  swc1  $f10, 0x22c($v0)
.L7F07E94C:
  lw    $t8, ($v1)
  li    $t7, 2
  sw    $t7, 0x220($t8)
  lw    $t9, ($v1)
  jr    $ra
   swc1  $f12, 0x228($t9)
");

asm(R"
glabel sub_GAME_7F07E964
  lui   $a0, %hi(pPlayer)
  addiu $a0, %lo(pPlayer) # addiu $a0, $a0, -0x5f50
  lw    $v0, ($a0)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lw    $v1, 0x220($v0)
  li    $a1, 3
  beql  $v1, $zero, .L7F07EA6C
   lw    $ra, 0x14($sp)
  beq   $a1, $v1, .L7F07EA68
   li    $at, 1
  bne   $v1, $at, .L7F07E9F4
   li    $at, 0x41A00000 # 20.000000
  mtc1  $at, $f0
  lui   $at, %hi(global_timer_delta)
  lwc1  $f4, %lo(global_timer_delta)($at)
  lui   $at, %hi(watch_transition_time)
  lwc1  $f6, %lo(watch_transition_time)($at)
  lwc1  $f10, 0x22c($v0)
  lwc1  $f18, 0x224($v0)
  mul.s $f8, $f4, $f6
  nop   
  mul.s $f16, $f8, $f10
  add.s $f4, $f18, $f16
  swc1  $f4, 0x224($v0)
  lw    $v0, ($a0)
  lwc1  $f6, 0x224($v0)
  c.lt.s $f0, $f6
  nop   
  bc1f  .L7F07EA50
   nop   
  swc1  $f0, 0x224($v0)
  lw    $t6, ($a0)
  sw    $a1, 0x220($t6)
  b     .L7F07EA50
   lw    $v0, ($a0)
.L7F07E9F4:
  li    $at, 2
  bne   $v1, $at, .L7F07EA50
   lui   $at, %hi(global_timer_delta)
  lwc1  $f8, %lo(global_timer_delta)($at)
  lui   $at, %hi(watch_transition_time)
  lwc1  $f10, %lo(watch_transition_time)($at)
  lwc1  $f16, 0x22c($v0)
  lwc1  $f6, 0x224($v0)
  mul.s $f18, $f8, $f10
  mtc1  $zero, $f0
  mul.s $f4, $f18, $f16
  sub.s $f8, $f6, $f4
  swc1  $f8, 0x224($v0)
  lw    $v0, ($a0)
  lwc1  $f10, 0x224($v0)
  c.lt.s $f10, $f0
  nop   
  bc1fl .L7F07EA54
   mtc1  $zero, $f0
  swc1  $f0, 0x224($v0)
  lw    $t7, ($a0)
  sw    $zero, 0x220($t7)
  lw    $v0, ($a0)
.L7F07EA50:
  mtc1  $zero, $f0
.L7F07EA54:
  addiu $a0, $v0, 0x230
  lw    $a1, 0x224($v0)
  mfc1  $a2, $f0
  jal   sub_GAME_7F070090
   nop   
.L7F07EA68:
  lw    $ra, 0x14($sp)
.L7F07EA6C:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F07EA78
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  li    $at, 1
  lw    $v1, 0x220($v0)
  beq   $v1, $at, .L7F07EA94
   li    $at, 2
  bne   $v1, $at, .L7F07EAA8
.L7F07EA94:
   li    $at, 0x41A00000 # 20.000000
  mtc1  $at, $f6
  lwc1  $f4, 0x224($v0)
  jr    $ra
   div.s $f0, $f4, $f6

.L7F07EAA8:
  li    $at, 3
  bne   $v1, $at, .L7F07EAC0
   li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f0
  jr    $ra
   nop   

.L7F07EAC0:
  mtc1  $zero, $f0
  nop   
  jr    $ra
   nop   
");

void set_BONDdata_paused_flag(int arg0) {
  pPlayer->paused_flag = arg0;
}

int get_BONDdata_paused_flag(void) {
  return pPlayer->paused_flag;
}

asm(R"
glabel sub_GAME_7F07EAF0
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  jal   deactivate_alarm_sound_effect
   sw    $s0, 0x14($sp)
  jal   check_deactivate_gas_sound
   nop   
  move  $s1, $zero
.L7F07EB10:
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  addu  $s0, $t6, $s1
  lw    $a0, 0xa44($s0)
  addiu $s0, $s0, 0x870
  beql  $a0, $zero, .L7F07EB48
   addiu $s1, $s1, 0x3a8
  jal   sfxGetArg0Unk3F
   nop   
  beql  $v0, $zero, .L7F07EB48
   addiu $s1, $s1, 0x3a8
  jal   sfxDeactivate
   lw    $a0, 0x1d4($s0)
  addiu $s1, $s1, 0x3a8
.L7F07EB48:
  slti  $at, $s1, 0x750
  bnez  $at, .L7F07EB10
   nop   
  lui   $s0, %hi(SFX_80036458)
  lui   $s1, %hi(D_80036460)
  addiu $s1, %lo(D_80036460) # addiu $s1, $s1, 0x6460
  addiu $s0, %lo(SFX_80036458) # addiu $s0, $s0, 0x6458
  lw    $a0, ($s0)
.L7F07EB68:
  beql  $a0, $zero, .L7F07EB8C
   addiu $s0, $s0, 4
  jal   sfxGetArg0Unk3F
   nop   
  beql  $v0, $zero, .L7F07EB8C
   addiu $s0, $s0, 4
  jal   sfxDeactivate
   lw    $a0, ($s0)
  addiu $s0, $s0, 4
.L7F07EB8C:
  bnel  $s0, $s1, .L7F07EB68
   lw    $a0, ($s0)
  jal   get_ptr_obj_pos_list_current_entry
   nop   
  beqz  $v0, .L7F07EC40
   move  $s1, $v0
  lbu   $v0, ($s1)
.L7F07EBA8:
  li    $at, 2
  beq   $v0, $at, .L7F07EC34
   li    $at, 1
  bnel  $v0, $at, .L7F07EC38
   lw    $s1, 0x24($s1)
  lw    $v1, 4($s1)
  li    $at, 39
  lbu   $a0, 3($v1)
  bnel  $a0, $at, .L7F07EC04
   li    $at, 40
  lw    $a0, 0xac($v1)
  move  $s0, $v1
  beql  $a0, $zero, .L7F07EC38
   lw    $s1, 0x24($s1)
  jal   sfxGetArg0Unk3F
   nop   
  beql  $v0, $zero, .L7F07EC38
   lw    $s1, 0x24($s1)
  jal   sfxDeactivate
   lw    $a0, 0xac($s0)
  b     .L7F07EC38
   lw    $s1, 0x24($s1)
  li    $at, 40
.L7F07EC04:
  bnel  $a0, $at, .L7F07EC38
   lw    $s1, 0x24($s1)
  lw    $a0, 0xb0($v1)
  move  $s0, $v1
  beql  $a0, $zero, .L7F07EC38
   lw    $s1, 0x24($s1)
  jal   sfxGetArg0Unk3F
   nop   
  beql  $v0, $zero, .L7F07EC38
   lw    $s1, 0x24($s1)
  jal   sfxDeactivate
   lw    $a0, 0xb0($s0)
.L7F07EC34:
  lw    $s1, 0x24($s1)
.L7F07EC38:
  bnezl $s1, .L7F07EBA8
   lbu   $v0, ($s1)
.L7F07EC40:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x20
");

#ifdef VERSION_US
asm(R"
glabel sub_GAME_7F07EC54
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  addiu $sp, $sp, -0x40
  sw    $ra, 0x14($sp)
  lw    $v0, 0x1c8($t6)
  beql  $v0, $zero, .L7F07F80C
   li    $at, 5
  jal   get_item_in_hand
   move  $a0, $zero
  xori  $v1, $v0, 0x1e
  sltiu $v1, $v1, 1
  bnez  $v1, .L7F07EC9C
   sw    $v1, 0x1c($sp)
  jal   get_item_in_hand
   move  $a0, $zero
  xori  $t7, $v0, 0x17
  sltiu $t7, $t7, 1
  sw    $t7, 0x1c($sp)
.L7F07EC9C:
  lw    $t8, 0x1c($sp)
  li    $a1, 17
  lui   $v1, %hi(pPlayer)
  beqz  $t8, .L7F07ECB4
   sw    $t8, 0x3c($sp)
  li    $a1, 35
.L7F07ECB4:
  lw    $v1, %lo(pPlayer)($v1)
  lui   $t0, %hi(clock_timer) 
  lw    $t0, %lo(clock_timer)($t0)
  lw    $t9, 0x1c4($v1)
  lui   $t4, %hi(pPlayer) 
  li    $at, 1
  addu  $t1, $t9, $t0
  sw    $t1, 0x1c4($v1)
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  lw    $t2, 0x1c0($v1)
  addiu $t3, $t2, 1
  sw    $t3, 0x1c0($v1)
  lw    $t4, %lo(pPlayer)($t4)
  lui   $v1, %hi(pPlayer)
  sw    $zero, 0x200($t4)
  lw    $v1, %lo(pPlayer)($v1)
  lw    $t5, 0x1c8($v1)
  bne   $t5, $at, .L7F07EDE8
   nop   
  sw    $zero, 0x200($v1)
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  li    $at, 1
  li    $a0, 1
  lw    $v0, 0x1c0($t6)
  bnel  $v0, $at, .L7F07ED38
   li    $at, 2
  jal   draw_item_in_hand
   li    $a1, 84
  b     .L7F07EDE8
   nop   
  li    $at, 2
.L7F07ED38:
  bne   $v0, $at, .L7F07ED60
   li    $a0, 1
  lw    $t7, 0x1c($sp)
  move  $a0, $zero
  beqz  $t7, .L7F07EDE8
   nop   
  jal   draw_item_in_hand
   move  $a1, $zero
  b     .L7F07EDE8
   nop   
.L7F07ED60:
  jal   return_ammo_in_hand
   sw    $a1, 0x38($sp)
  li    $at, 84
  bne   $v0, $at, .L7F07EDE8
   nop   
  jal   sub_GAME_7F05CEBC
   li    $a0, 1
  beqz  $v0, .L7F07EDE8
   lw    $t8, 0x1c($sp)
  beqz  $t8, .L7F07EDA8
   nop   
  jal   return_ammo_in_hand
   move  $a0, $zero
  bnez  $v0, .L7F07EDE8
   nop   
  jal   sub_GAME_7F05CEBC
   move  $a0, $zero
  beqz  $v0, .L7F07EDE8
.L7F07EDA8:
   lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  lw    $t0, 0x38($sp)
  li    $t1, 2
  lw    $t9, 0x1c4($v1)
  lui   $t3, %hi(pPlayer) 
  slt   $at, $t9, $t0
  bnez  $at, .L7F07EDE8
   nop   
  sw    $t1, 0x1c8($v1)
  lw    $t3, %lo(pPlayer)($t3)
  li    $t2, 1
  lui   $t4, %hi(pPlayer) 
  sw    $t2, 0x1c0($t3)
  lw    $t4, %lo(pPlayer)($t4)
  sw    $zero, 0x1c4($t4)
.L7F07EDE8:
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  li    $at, 2
  lw    $t5, 0x1c8($v1)
  bnel  $t5, $at, .L7F07EF08
   lw    $v0, 0x1c8($v1)
  sw    $zero, 0x200($v1)
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  li    $at, 1
  li    $a0, 8
  lw    $t6, 0x1c0($v1)
  bnel  $t6, $at, .L7F07EEB4
   lwc1  $f4, 0x214($v1)
  jal   set_unset_bitflags
   move  $a1, $zero
  li    $a0, 4
  jal   set_unset_ammo_on_screen_setting
   move  $a1, $zero
  jal   set_flags_in_BONDdata_stationary_intro_cam
   li    $a0, 1
  jal   sub_GAME_7F08A944
   li    $a0, 1
  li    $a0, 4
  jal   set_unset_clock_lock_bits
   move  $a1, $zero
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  li    $at, 2
  lw    $a0, 0x218($v1)
  beqz  $a0, .L7F07EE78
   nop   
  beq   $a0, $at, .L7F07EE78
   li    $at, 3
  bnel  $a0, $at, .L7F07EEB4
   lwc1  $f4, 0x214($v1)
.L7F07EE78:
  jal   sub_GAME_7F07DF28
   li    $a0, 1
  li    $at, 0x41F00000 # 30.000000
  mtc1  $at, $f2
  mov.s $f12, $f0
  c.lt.s $f0, $f2
  nop   
  bc1f  .L7F07EEA0
   nop   
  mov.s $f12, $f2
.L7F07EEA0:
  jal   sub_GAME_7F07E010
   nop   
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  lwc1  $f4, 0x214($v1)
.L7F07EEB4:
  lwc1  $f6, 0x210($v1)
  li    $at, 0x41F00000 # 30.000000
  mtc1  $at, $f10
  sub.s $f8, $f4, $f6
  li    $t7, 3
  lui   $t9, %hi(pPlayer) 
  c.lt.s $f8, $f10
  nop   
  bc1fl .L7F07EF08
   lw    $v0, 0x1c8($v1)
  sw    $t7, 0x1c8($v1)
  lw    $t9, %lo(pPlayer)($t9)
  li    $t8, 1
  lui   $t0, %hi(pPlayer) 
  sw    $t8, 0x1c0($t9)
  lw    $t0, %lo(pPlayer)($t0)
  jal   sub_GAME_7F07E7CC
   sw    $zero, 0x1c4($t0)
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  lw    $v0, 0x1c8($v1)
.L7F07EF08:
  li    $at, 3
  bnel  $v0, $at, .L7F07F074
   li    $at, 4
  lw    $t1, 0x1c0($v1)
  li    $at, 1
  bnel  $t1, $at, .L7F07EFF8
   lw    $v0, 0x220($v1)
  lw    $v0, 0x220($v1)
  li    $at, 0x42200000 # 40.000000
  mtc1  $at, $f14
  beqz  $v0, .L7F07EF68
   lw    $a0, 0x218($v1)
  li    $at, 3
  beq   $v0, $at, .L7F07EF68
   li    $at, 0x41A00000 # 20.000000
  mtc1  $at, $f16
  lwc1  $f18, 0x258($v1)
  li    $at, 0x42200000 # 40.000000
  mtc1  $at, $f6
  sub.s $f4, $f16, $f18
  li    $at, 0x41A00000 # 20.000000
  mtc1  $at, $f10
  mul.s $f8, $f4, $f6
  div.s $f14, $f8, $f10
.L7F07EF68:
  beqz  $a0, .L7F07EF7C
   li    $at, 2
  beq   $a0, $at, .L7F07EF7C
   li    $at, 3
  bne   $a0, $at, .L7F07EFE4
.L7F07EF7C:
   li    $a0, 1
  jal   sub_GAME_7F07DF28
   swc1  $f14, 0x30($sp)
  li    $at, 0x41200000 # 10.000000
  lwc1  $f14, 0x30($sp)
  mtc1  $at, $f16
  mov.s $f12, $f0
  sub.s $f2, $f14, $f16
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F07EFB4
   swc1  $f12, 0x2c($sp)
  mov.s $f12, $f2
  swc1  $f12, 0x2c($sp)
.L7F07EFB4:
  jal   sub_GAME_7F07E010
   swc1  $f14, 0x30($sp)
  li    $at, 0x41200000 # 10.000000
  lwc1  $f12, 0x2c($sp)
  mtc1  $at, $f18
  lwc1  $f14, 0x30($sp)
  add.s $f0, $f12, $f18
  c.lt.s $f14, $f0
  nop   
  bc1f  .L7F07EFE4
   nop   
  mov.s $f14, $f0
.L7F07EFE4:
  jal   sub_GAME_7F07E8B0
   mov.s $f12, $f14
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  lw    $v0, 0x220($v1)
.L7F07EFF8:
  li    $at, 3
  beqz  $v0, .L7F07F00C
   nop   
  bnel  $v0, $at, .L7F07F028
   li    $t2, 1
.L7F07F00C:
  jal   sub_GAME_7F07E068
   nop   
  beqz  $v0, .L7F07F03C
   lui   $t4, %hi(pPlayer) 
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  li    $t2, 1
.L7F07F028:
  sw    $t2, 0x200($v1)
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  b     .L7F07F070
   lw    $v0, 0x1c8($v1)
.L7F07F03C:
  lw    $t4, %lo(pPlayer)($t4)
  li    $t3, 4
  lui   $t6, %hi(pPlayer) 
  sw    $t3, 0x1c8($t4)
  lw    $t6, %lo(pPlayer)($t6)
  li    $t5, 1
  lui   $t7, %hi(pPlayer) 
  sw    $t5, 0x1c0($t6)
  lw    $t7, %lo(pPlayer)($t7)
  lui   $v1, %hi(pPlayer)
  sw    $zero, 0x1c4($t7)
  lw    $v1, %lo(pPlayer)($v1)
  lw    $v0, 0x1c8($v1)
.L7F07F070:
  li    $at, 4
.L7F07F074:
  bnel  $v0, $at, .L7F07F134
   li    $at, 5
  lw    $t8, 0x1c0($v1)
  li    $at, 1
  bne   $t8, $at, .L7F07F0B4
   nop   
  lw    $t9, 0x21c($v1)
  lui   $a0, %hi(ptr_sfx_buf)
  li    $a1, 237
  beqz  $t9, .L7F07F0B4
   move  $a2, $zero
  jal   play_sfx_a1
   lw    $a0, %lo(ptr_sfx_buf)($a0)
  lui   $t0, %hi(pPlayer) 
  lw    $t0, %lo(pPlayer)($t0)
  sw    $zero, 0x21c($t0)
.L7F07F0B4:
  jal   zoom_to_watch_on_open
   nop   
  jal   check_watch_page_transistion_running
   nop   
  beqz  $v0, .L7F07F0EC
   lui   $t4, %hi(pPlayer) 
  lui   $t2, %hi(pPlayer) 
  lw    $t2, %lo(pPlayer)($t2)
  li    $t1, 1
  lui   $v1, %hi(pPlayer)
  sw    $t1, 0x200($t2)
  lw    $v1, %lo(pPlayer)($v1)
  b     .L7F07F130
   lw    $v0, 0x1c8($v1)
.L7F07F0EC:
  lw    $t4, %lo(pPlayer)($t4)
  li    $t3, 5
  lui   $t6, %hi(pPlayer) 
  sw    $t3, 0x1c8($t4)
  lw    $t6, %lo(pPlayer)($t6)
  li    $t5, 1
  lui   $t7, %hi(pPlayer) 
  sw    $t5, 0x1c0($t6)
  lw    $t7, %lo(pPlayer)($t7)
  lui   $t9, %hi(pPlayer) 
  li    $t8, 1
  sw    $zero, 0x1c4($t7)
  lw    $t9, %lo(pPlayer)($t9)
  lui   $v1, %hi(pPlayer)
  sw    $t8, 0x21c($t9)
  lw    $v1, %lo(pPlayer)($v1)
  lw    $v0, 0x1c8($v1)
.L7F07F130:
  li    $at, 5
.L7F07F134:
  bnel  $v0, $at, .L7F07F174
   li    $at, 12
  lw    $t0, 0x1c0($v1)
  li    $at, 1
  bnel  $t0, $at, .L7F07F160
   li    $t1, 1
  jal   sub_GAME_7F0C1310
   nop   
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  li    $t1, 1
.L7F07F160:
  sw    $t1, 0x200($v1)
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  lw    $v0, 0x1c8($v1)
  li    $at, 12
.L7F07F174:
  bne   $v0, $at, .L7F07F1D8
   li    $t2, 1
  sw    $t2, 0x200($v1)
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  li    $t4, 6
  li    $t5, 1
  lw    $t3, 0x1c0($v1)
  lui   $t6, %hi(pPlayer) 
  slti  $at, $t3, 3
  bnezl $at, .L7F07F1DC
   lw    $v0, 0x1c8($v1)
  sw    $t4, 0x1c8($v1)
  lw    $t6, %lo(pPlayer)($t6)
  lui   $t7, %hi(pPlayer) 
  lui   $a0, %hi(ptr_sfx_buf)
  sw    $t5, 0x1c0($t6)
  lw    $t7, %lo(pPlayer)($t7)
  li    $a1, 238
  move  $a2, $zero
  sw    $zero, 0x1c4($t7)
  jal   play_sfx_a1
   lw    $a0, %lo(ptr_sfx_buf)($a0)
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
.L7F07F1D8:
  lw    $v0, 0x1c8($v1)
.L7F07F1DC:
  li    $at, 6
  bnel  $v0, $at, .L7F07F2A0
   li    $at, 7
  lw    $t8, 0x1c0($v1)
  li    $at, 1
  bne   $t8, $at, .L7F07F228
   nop   
  jal   zoom_from_watch_on_exit
   nop   
  lw    $t9, 0x1c($sp)
  move  $a0, $zero
  beqz  $t9, .L7F07F220
   nop   
  jal   draw_item_in_hand
   move  $a1, $zero
  b     .L7F07F228
   nop   
.L7F07F220:
  jal   sub_GAME_7F05DAE4
   move  $a0, $zero
.L7F07F228:
  jal   check_watch_page_transistion_running
   nop   
  beqz  $v0, .L7F07F258
   lui   $t3, %hi(pPlayer) 
  lui   $t1, %hi(pPlayer) 
  lw    $t1, %lo(pPlayer)($t1)
  li    $t0, 1
  lui   $v1, %hi(pPlayer)
  sw    $t0, 0x200($t1)
  lw    $v1, %lo(pPlayer)($v1)
  b     .L7F07F29C
   lw    $v0, 0x1c8($v1)
.L7F07F258:
  lw    $t3, %lo(pPlayer)($t3)
  li    $t2, 7
  lui   $t5, %hi(pPlayer) 
  sw    $t2, 0x1c8($t3)
  lw    $t5, %lo(pPlayer)($t5)
  li    $t4, 1
  lui   $t6, %hi(pPlayer) 
  sw    $t4, 0x1c0($t5)
  lw    $t6, %lo(pPlayer)($t6)
  lui   $t8, %hi(pPlayer) 
  li    $t7, 1
  sw    $zero, 0x1c4($t6)
  lw    $t8, %lo(pPlayer)($t8)
  lui   $v1, %hi(pPlayer)
  sw    $t7, 0x21c($t8)
  lw    $v1, %lo(pPlayer)($v1)
  lw    $v0, 0x1c8($v1)
.L7F07F29C:
  li    $at, 7
.L7F07F2A0:
  bnel  $v0, $at, .L7F07F3A0
   li    $at, 8
  lw    $t9, 0x1c0($v1)
  li    $at, 1
  bne   $t9, $at, .L7F07F344
   li    $at, 0x42200000 # 40.000000
  mtc1  $at, $f14
  move  $a0, $zero
  jal   sub_GAME_7F07DF28
   swc1  $f14, 0x28($sp)
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  lwc1  $f14, 0x28($sp)
  mov.s $f12, $f0
  lw    $v0, 0x220($v1)
  li    $at, 3
  beql  $v0, $zero, .L7F07F30C
   lui   $at, 0x41a0
  beq   $v0, $at, .L7F07F308
   li    $at, 0x42200000 # 40.000000
  mtc1  $at, $f6
  lwc1  $f4, 0x258($v1)
  li    $at, 0x41A00000 # 20.000000
  mtc1  $at, $f10
  mul.s $f8, $f4, $f6
  div.s $f14, $f8, $f10
.L7F07F308:
  li    $at, 0x41A00000 # 20.000000
.L7F07F30C:
  mtc1  $at, $f16
  nop   
  add.s $f2, $f14, $f16
  c.lt.s $f0, $f2
  nop   
  bc1f  .L7F07F32C
   nop   
  mov.s $f12, $f2
.L7F07F32C:
  jal   sub_GAME_7F07E03C
   swc1  $f14, 0x28($sp)
  jal   sub_GAME_7F07E910
   lwc1  $f12, 0x28($sp)
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
.L7F07F344:
  lw    $v0, 0x220($v1)
  li    $at, 3
  li    $t1, 8
  beqz  $v0, .L7F07F374
   lui   $t3, %hi(pPlayer) 
  beq   $v0, $at, .L7F07F374
   li    $t0, 1
  sw    $t0, 0x200($v1)
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  b     .L7F07F39C
   lw    $v0, 0x1c8($v1)
.L7F07F374:
  sw    $t1, 0x1c8($v1)
  lw    $t3, %lo(pPlayer)($t3)
  li    $t2, 1
  lui   $t4, %hi(pPlayer) 
  sw    $t2, 0x1c0($t3)
  lw    $t4, %lo(pPlayer)($t4)
  lui   $v1, %hi(pPlayer)
  sw    $zero, 0x1c4($t4)
  lw    $v1, %lo(pPlayer)($v1)
  lw    $v0, 0x1c8($v1)
.L7F07F39C:
  li    $at, 8
.L7F07F3A0:
  bne   $v0, $at, .L7F07F548
   lui   $t5, %hi(pPlayer) 
  sw    $zero, 0x200($v1)
  lw    $t5, %lo(pPlayer)($t5)
  li    $at, 1
  lw    $t6, 0x1c0($t5)
  bne   $t6, $at, .L7F07F45C
   nop   
  jal   return_ammo_in_hand
   li    $a0, 1
  sw    $v0, 0x1c($sp)
  jal   get_item_in_hand
   li    $a0, 1
  lw    $t7, 0x1c($sp)
  beql  $v0, $t7, .L7F07F408
   lw    $t8, 0x3c($sp)
  jal   sub_GAME_7F05CEBC
   li    $a0, 1
  beql  $v0, $zero, .L7F07F408
   lw    $t8, 0x3c($sp)
  jal   get_item_in_hand
   li    $a0, 1
  li    $a0, 1
  jal   draw_item_in_hand
   move  $a1, $v0
  lw    $t8, 0x3c($sp)
.L7F07F408:
  beqz  $t8, .L7F07F548
   nop   
  jal   return_ammo_in_hand
   move  $a0, $zero
  sw    $v0, 0x1c($sp)
  jal   get_item_in_hand
   move  $a0, $zero
  lw    $t9, 0x1c($sp)
  beq   $v0, $t9, .L7F07F548
   nop   
  jal   sub_GAME_7F05CEBC
   move  $a0, $zero
  beqz  $v0, .L7F07F548
   nop   
  jal   get_item_in_hand
   move  $a0, $zero
  move  $a0, $zero
  jal   draw_item_in_hand
   move  $a1, $v0
  b     .L7F07F548
   nop   
.L7F07F45C:
  jal   sub_GAME_7F07E068
   nop   
  bnez  $v0, .L7F07F548
   nop   
  jal   return_ammo_in_hand
   li    $a0, 1
  sw    $v0, 0x1c($sp)
  jal   get_item_in_hand
   li    $a0, 1
  lw    $t0, 0x1c($sp)
  bne   $v0, $t0, .L7F07F548
   nop   
  jal   sub_GAME_7F05CEBC
   li    $a0, 1
  beqz  $v0, .L7F07F548
   lw    $t1, 0x3c($sp)
  beqz  $t1, .L7F07F4D4
   nop   
  jal   return_ammo_in_hand
   move  $a0, $zero
  sw    $v0, 0x18($sp)
  jal   get_item_in_hand
   move  $a0, $zero
  lw    $t2, 0x18($sp)
  bne   $v0, $t2, .L7F07F548
   nop   
  jal   sub_GAME_7F05CEBC
   move  $a0, $zero
  beqz  $v0, .L7F07F548
   nop   
.L7F07F4D4:
  jal   sub_GAME_7F05DAE4
   li    $a0, 1
  lw    $t3, 0x3c($sp)
  beql  $t3, $zero, .L7F07F4F4
   li    $a0, 8
  jal   sub_GAME_7F05DAE4
   move  $a0, $zero
  li    $a0, 8
.L7F07F4F4:
  jal   set_unset_bitflags
   li    $a1, 1
  li    $a0, 4
  jal   set_unset_ammo_on_screen_setting
   li    $a1, 1
  jal   unset_flags_in_BONDdata_stationary_intro_cam
   li    $a0, 1
  jal   sub_GAME_7F08A928
   li    $a0, 1
  li    $a0, 4
  jal   set_unset_clock_lock_bits
   li    $a1, 1
  lui   $t4, %hi(pPlayer) 
  lw    $t4, %lo(pPlayer)($t4)
  lui   $t5, %hi(pPlayer) 
  lui   $t6, %hi(pPlayer) 
  sw    $zero, 0x1c8($t4)
  lw    $t5, %lo(pPlayer)($t5)
  sw    $zero, 0x1c0($t5)
  lw    $t6, %lo(pPlayer)($t6)
  sw    $zero, 0x1c4($t6)
.L7F07F548:
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  li    $at, 9
  li    $a0, 1
  lw    $t7, 0x1c8($v1)
  bne   $t7, $at, .L7F07F5EC
   nop   
  jal   get_item_in_hand
   sw    $zero, 0x200($v1)
  sw    $v0, 0x1c($sp)
  jal   return_ammo_in_hand
   li    $a0, 1
  lw    $t8, 0x1c($sp)
  beq   $v0, $t8, .L7F07F5EC
   nop   
  jal   sub_GAME_7F05CEBC
   li    $a0, 1
  beqz  $v0, .L7F07F5EC
   lw    $t9, 0x3c($sp)
  beqz  $t9, .L7F07F5C8
   nop   
  jal   get_item_in_hand
   move  $a0, $zero
  sw    $v0, 0x18($sp)
  jal   return_ammo_in_hand
   move  $a0, $zero
  lw    $t0, 0x18($sp)
  beq   $v0, $t0, .L7F07F5EC
   nop   
  jal   sub_GAME_7F05CEBC
   move  $a0, $zero
  beqz  $v0, .L7F07F5EC
.L7F07F5C8:
   lui   $v0, %hi(pPlayer)
  addiu $v0, %lo(pPlayer) # addiu $v0, $v0, -0x5f50
  lw    $t2, ($v0)
  li    $t1, 8
  sw    $t1, 0x1c8($t2)
  lw    $t3, ($v0)
  sw    $zero, 0x1c0($t3)
  lw    $t4, ($v0)
  sw    $zero, 0x1c4($t4)
.L7F07F5EC:
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  li    $at, 10
  lui   $t6, %hi(pPlayer) 
  lw    $t5, 0x1c8($v1)
  bne   $t5, $at, .L7F07F6B8
   nop   
  sw    $zero, 0x200($v1)
  lw    $t6, %lo(pPlayer)($t6)
  li    $at, 1
  lw    $t7, 0x1c0($t6)
  bne   $t7, $at, .L7F07F630
   nop   
  jal   sub_GAME_7F07DF28
   move  $a0, $zero
  jal   sub_GAME_7F07E03C
   mov.s $f12, $f0
.L7F07F630:
  jal   get_item_in_hand
   li    $a0, 1
  sw    $v0, 0x1c($sp)
  jal   return_ammo_in_hand
   li    $a0, 1
  lw    $t8, 0x1c($sp)
  beq   $v0, $t8, .L7F07F6B8
   nop   
  jal   sub_GAME_7F05CEBC
   li    $a0, 1
  beqz  $v0, .L7F07F6B8
   lw    $t9, 0x3c($sp)
  beqz  $t9, .L7F07F694
   nop   
  jal   get_item_in_hand
   move  $a0, $zero
  sw    $v0, 0x18($sp)
  jal   return_ammo_in_hand
   move  $a0, $zero
  lw    $t0, 0x18($sp)
  beq   $v0, $t0, .L7F07F6B8
   nop   
  jal   sub_GAME_7F05CEBC
   move  $a0, $zero
  beqz  $v0, .L7F07F6B8
.L7F07F694:
   lui   $v0, %hi(pPlayer)
  addiu $v0, %lo(pPlayer) # addiu $v0, $v0, -0x5f50
  lw    $t2, ($v0)
  li    $t1, 8
  sw    $t1, 0x1c8($t2)
  lw    $t3, ($v0)
  sw    $zero, 0x1c0($t3)
  lw    $t4, ($v0)
  sw    $zero, 0x1c4($t4)
.L7F07F6B8:
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  li    $at, 11
  li    $a0, 1
  lw    $t5, 0x1c8($v1)
  bne   $t5, $at, .L7F07F760
   nop   
  jal   get_item_in_hand
   sw    $zero, 0x200($v1)
  sw    $v0, 0x1c($sp)
  jal   return_ammo_in_hand
   li    $a0, 1
  lw    $t6, 0x1c($sp)
  bne   $v0, $t6, .L7F07F760
   nop   
  jal   sub_GAME_7F05CEBC
   li    $a0, 1
  beqz  $v0, .L7F07F760
   lw    $t7, 0x3c($sp)
  beqz  $t7, .L7F07F738
   nop   
  jal   get_item_in_hand
   move  $a0, $zero
  sw    $v0, 0x18($sp)
  jal   return_ammo_in_hand
   move  $a0, $zero
  lw    $t8, 0x18($sp)
  bne   $v0, $t8, .L7F07F760
   nop   
  jal   sub_GAME_7F05CEBC
   move  $a0, $zero
  beqz  $v0, .L7F07F760
.L7F07F738:
   lui   $t0, %hi(pPlayer) 
  lw    $t0, %lo(pPlayer)($t0)
  li    $t9, 1
  lui   $t1, %hi(pPlayer) 
  sw    $t9, 0x1c8($t0)
  lw    $t1, %lo(pPlayer)($t1)
  lui   $t2, %hi(pPlayer) 
  sw    $zero, 0x1c0($t1)
  lw    $t2, %lo(pPlayer)($t2)
  sw    $zero, 0x1c4($t2)
.L7F07F760:
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  li    $at, 13
  li    $a0, 1
  lw    $t3, 0x1c8($v1)
  bne   $t3, $at, .L7F07F7E4
   nop   
  jal   sub_GAME_7F05CEBC
   sw    $zero, 0x200($v1)
  beqz  $v0, .L7F07F7E4
   nop   
  jal   sub_GAME_7F05CEBC
   move  $a0, $zero
  beqz  $v0, .L7F07F7E4
   lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  li    $at, 5
  lw    $v0, 0xc3c($v1)
  beq   $v0, $at, .L7F07F7E4
   li    $at, 6
  beq   $v0, $at, .L7F07F7E4
   li    $at, 7
  beq   $v0, $at, .L7F07F7E4
   li    $at, 8
  beq   $v0, $at, .L7F07F7E4
   li    $t4, 1
  sw    $t4, 0x1c8($v1)
  lui   $t5, %hi(pPlayer) 
  lw    $t5, %lo(pPlayer)($t5)
  lui   $t6, %hi(pPlayer) 
  sw    $zero, 0x1c0($t5)
  lw    $t6, %lo(pPlayer)($t6)
  sw    $zero, 0x1c4($t6)
.L7F07F7E4:
  jal   sub_GAME_7F07E090
   nop   
  jal   sub_GAME_7F07E964
   nop   
  jal   sub_GAME_7F07E62C
   nop   
  lui   $t7, %hi(pPlayer) 
  lw    $t7, %lo(pPlayer)($t7)
  lw    $v0, 0x1c8($t7)
  li    $at, 5
.L7F07F80C:
  bnel  $v0, $at, .L7F07F830
   li    $at, 12
  jal   set_controls_locked_flag
   li    $a0, 1
  jal   sub_GAME_7F0A6A80
   nop   
  b     .L7F07F854
   lw    $ra, 0x14($sp)
  li    $at, 12
.L7F07F830:
  bne   $v0, $at, .L7F07F848
   nop   
  jal   set_controls_locked_flag
   li    $a0, 1
  b     .L7F07F854
   lw    $ra, 0x14($sp)
.L7F07F848:
  jal   set_controls_locked_flag
   move  $a0, $zero
  lw    $ra, 0x14($sp)
.L7F07F854:
  addiu $sp, $sp, 0x40
  jr    $ra
   nop   
");
#endif

#ifdef VERSION_JP
asm(R"
glabel sub_GAME_7F07EC54
  lui   $t6, %hi(pPlayer) # $t6, 0x8008
  lw    $t6, %lo(pPlayer)($t6)
  addiu $sp, $sp, -0x40
  sw    $ra, 0x14($sp)
  lw    $v0, 0x1c8($t6)
  beql  $v0, $zero, .Ljp7F07FE1C
   li    $at, 5
  jal   get_item_in_hand
   move  $a0, $zero
  xori  $v1, $v0, 0x1e
  sltiu $v1, $v1, 1
  bnez  $v1, .Ljp7F07F2A8
   sw    $v1, 0x1c($sp)
  jal   get_item_in_hand
   move  $a0, $zero
  xori  $t7, $v0, 0x17
  sltiu $t7, $t7, 1
  sw    $t7, 0x1c($sp)
.Ljp7F07F2A8:
  lw    $t8, 0x1c($sp)
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  beqz  $t8, .Ljp7F07F2C4
   sw    $t8, 0x3c($sp)
  li    $t9, 35
  b     .Ljp7F07F2CC
   sw    $t9, 0x38($sp)
.Ljp7F07F2C4:
  li    $t0, 17
  sw    $t0, 0x38($sp)
.Ljp7F07F2CC:
  lw    $v1, %lo(pPlayer)($v1)
  lui   $t2, %hi(clock_timer) # $t2, 0x8005
  lw    $t2, %lo(clock_timer)($t2)
  lw    $t1, 0x1c4($v1)
  lui   $t6, %hi(pPlayer) # $t6, 0x8008
  li    $at, 1
  addu  $t3, $t1, $t2
  sw    $t3, 0x1c4($v1)
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  lw    $v1, %lo(pPlayer)($v1)
  lw    $t4, 0x1c0($v1)
  addiu $t5, $t4, 1
  sw    $t5, 0x1c0($v1)
  lw    $t6, %lo(pPlayer)($t6)
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  sw    $zero, 0x200($t6)
  lw    $v1, %lo(pPlayer)($v1)
  lw    $t7, 0x1c8($v1)
  bne   $t7, $at, .Ljp7F07F3F8
   nop   
  sw    $zero, 0x200($v1)
  lui   $t8, %hi(pPlayer) # $t8, 0x8008
  lw    $t8, %lo(pPlayer)($t8)
  li    $at, 1
  li    $a0, 1
  lw    $v0, 0x1c0($t8)
  bnel  $v0, $at, .Ljp7F07F350
   li    $at, 2
  jal   draw_item_in_hand
   li    $a1, 84
  b     .Ljp7F07F3F8
   nop   
  li    $at, 2
.Ljp7F07F350:
  bne   $v0, $at, .Ljp7F07F370
   lw    $t9, 0x1c($sp)
  beqz  $t9, .Ljp7F07F3F8
   move  $a0, $zero
  jal   draw_item_in_hand
   move  $a1, $zero
  b     .Ljp7F07F3F8
   nop   
.Ljp7F07F370:
  jal   return_ammo_in_hand
   li    $a0, 1
  li    $at, 84
  bne   $v0, $at, .Ljp7F07F3F8
   nop   
  jal   sub_GAME_7F05CEBC
   li    $a0, 1
  beqz  $v0, .Ljp7F07F3F8
   lw    $t0, 0x1c($sp)
  beqz  $t0, .Ljp7F07F3B8
   nop   
  jal   return_ammo_in_hand
   move  $a0, $zero
  bnez  $v0, .Ljp7F07F3F8
   nop   
  jal   sub_GAME_7F05CEBC
   move  $a0, $zero
  beqz  $v0, .Ljp7F07F3F8
.Ljp7F07F3B8:
   lui   $v1, %hi(pPlayer) # $v1, 0x8008
  lw    $v1, %lo(pPlayer)($v1)
  lw    $t2, 0x38($sp)
  li    $t3, 2
  lw    $t1, 0x1c4($v1)
  lui   $t5, %hi(pPlayer) # $t5, 0x8008
  slt   $at, $t1, $t2
  bnez  $at, .Ljp7F07F3F8
   nop   
  sw    $t3, 0x1c8($v1)
  lw    $t5, %lo(pPlayer)($t5)
  li    $t4, 1
  lui   $t6, %hi(pPlayer) # $t6, 0x8008
  sw    $t4, 0x1c0($t5)
  lw    $t6, %lo(pPlayer)($t6)
  sw    $zero, 0x1c4($t6)
.Ljp7F07F3F8:
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  lw    $v1, %lo(pPlayer)($v1)
  li    $at, 2
  lw    $t7, 0x1c8($v1)
  bnel  $t7, $at, .Ljp7F07F518
   lw    $v0, 0x1c8($v1)
  sw    $zero, 0x200($v1)
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  lw    $v1, %lo(pPlayer)($v1)
  li    $at, 1
  li    $a0, 8
  lw    $t8, 0x1c0($v1)
  bnel  $t8, $at, .Ljp7F07F4C4
   lwc1  $f4, 0x214($v1)
  jal   set_unset_bitflags
   move  $a1, $zero
  li    $a0, 4
  jal   set_unset_ammo_on_screen_setting
   move  $a1, $zero
  jal   set_flags_in_BONDdata_stationary_intro_cam
   li    $a0, 1
  jal   sub_GAME_7F08A944
   li    $a0, 1
  li    $a0, 4
  jal   set_unset_clock_lock_bits
   move  $a1, $zero
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  lw    $v1, %lo(pPlayer)($v1)
  li    $at, 2
  lw    $a0, 0x218($v1)
  beqz  $a0, .Ljp7F07F488
   nop   
  beq   $a0, $at, .Ljp7F07F488
   li    $at, 3
  bnel  $a0, $at, .Ljp7F07F4C4
   lwc1  $f4, 0x214($v1)
.Ljp7F07F488:
  jal   sub_GAME_7F07DF28
   li    $a0, 1
  li    $at, 0x41F00000 # 30.000000
  mtc1  $at, $f2
  mov.s $f12, $f0
  c.lt.s $f0, $f2
  nop   
  bc1f  .Ljp7F07F4B0
   nop   
  mov.s $f12, $f2
.Ljp7F07F4B0:
  jal   sub_GAME_7F07E010
   nop   
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  lw    $v1, %lo(pPlayer)($v1)
  lwc1  $f4, 0x214($v1)
.Ljp7F07F4C4:
  lwc1  $f6, 0x210($v1)
  li    $at, 0x41F00000 # 30.000000
  mtc1  $at, $f10
  sub.s $f8, $f4, $f6
  li    $t9, 3
  lui   $t1, %hi(pPlayer) # $t1, 0x8008
  c.lt.s $f8, $f10
  nop   
  bc1fl .Ljp7F07F518
   lw    $v0, 0x1c8($v1)
  sw    $t9, 0x1c8($v1)
  lw    $t1, %lo(pPlayer)($t1)
  li    $t0, 1
  lui   $t2, %hi(pPlayer) # $t2, 0x8008
  sw    $t0, 0x1c0($t1)
  lw    $t2, %lo(pPlayer)($t2)
  jal   sub_GAME_7F07E7CC
   sw    $zero, 0x1c4($t2)
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  lw    $v1, %lo(pPlayer)($v1)
  lw    $v0, 0x1c8($v1)
.Ljp7F07F518:
  li    $at, 3
  bnel  $v0, $at, .Ljp7F07F684
   li    $at, 4
  lw    $t3, 0x1c0($v1)
  li    $at, 1
  bnel  $t3, $at, .Ljp7F07F608
   lw    $v0, 0x220($v1)
  lw    $v0, 0x220($v1)
  li    $at, 0x42200000 # 40.000000
  mtc1  $at, $f14
  beqz  $v0, .Ljp7F07F578
   lw    $a0, 0x218($v1)
  li    $at, 3
  beq   $v0, $at, .Ljp7F07F578
   li    $at, 0x41A00000 # 20.000000
  mtc1  $at, $f16
  lwc1  $f18, 0x258($v1)
  li    $at, 0x42200000 # 40.000000
  mtc1  $at, $f6
  sub.s $f4, $f16, $f18
  li    $at, 0x41A00000 # 20.000000
  mtc1  $at, $f10
  mul.s $f8, $f4, $f6
  div.s $f14, $f8, $f10
.Ljp7F07F578:
  beqz  $a0, .Ljp7F07F58C
   li    $at, 2
  beq   $a0, $at, .Ljp7F07F58C
   li    $at, 3
  bne   $a0, $at, .Ljp7F07F5F4
.Ljp7F07F58C:
   li    $a0, 1
  jal   sub_GAME_7F07DF28
   swc1  $f14, 0x30($sp)
  li    $at, 0x41200000 # 10.000000
  lwc1  $f14, 0x30($sp)
  mtc1  $at, $f16
  mov.s $f12, $f0
  sub.s $f2, $f14, $f16
  c.lt.s $f0, $f2
  nop   
  bc1fl .Ljp7F07F5C4
   swc1  $f12, 0x2c($sp)
  mov.s $f12, $f2
  swc1  $f12, 0x2c($sp)
.Ljp7F07F5C4:
  jal   sub_GAME_7F07E010
   swc1  $f14, 0x30($sp)
  li    $at, 0x41200000 # 10.000000
  lwc1  $f12, 0x2c($sp)
  mtc1  $at, $f18
  lwc1  $f14, 0x30($sp)
  add.s $f0, $f12, $f18
  c.lt.s $f14, $f0
  nop   
  bc1f  .Ljp7F07F5F4
   nop   
  mov.s $f14, $f0
.Ljp7F07F5F4:
  jal   sub_GAME_7F07E8B0
   mov.s $f12, $f14
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  lw    $v1, %lo(pPlayer)($v1)
  lw    $v0, 0x220($v1)
.Ljp7F07F608:
  li    $at, 3
  beqz  $v0, .Ljp7F07F61C
   nop   
  bnel  $v0, $at, .Ljp7F07F638
   li    $t4, 1
.Ljp7F07F61C:
  jal   sub_GAME_7F07E068
   nop   
  beqz  $v0, .Ljp7F07F64C
   lui   $t6, %hi(pPlayer) # $t6, 0x8008
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  lw    $v1, %lo(pPlayer)($v1)
  li    $t4, 1
.Ljp7F07F638:
  sw    $t4, 0x200($v1)
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  lw    $v1, %lo(pPlayer)($v1)
  b     .Ljp7F07F680
   lw    $v0, 0x1c8($v1)
.Ljp7F07F64C:
  lw    $t6, %lo(pPlayer)($t6)
  li    $t5, 4
  lui   $t8, %hi(pPlayer) # $t8, 0x8008
  sw    $t5, 0x1c8($t6)
  lw    $t8, %lo(pPlayer)($t8)
  li    $t7, 1
  lui   $t9, %hi(pPlayer) # $t9, 0x8008
  sw    $t7, 0x1c0($t8)
  lw    $t9, %lo(pPlayer)($t9)
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  sw    $zero, 0x1c4($t9)
  lw    $v1, %lo(pPlayer)($v1)
  lw    $v0, 0x1c8($v1)
.Ljp7F07F680:
  li    $at, 4
.Ljp7F07F684:
  bnel  $v0, $at, .Ljp7F07F744
   li    $at, 5
  lw    $t0, 0x1c0($v1)
  li    $at, 1
  bne   $t0, $at, .Ljp7F07F6C4
   nop   
  lw    $t1, 0x21c($v1)
  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  li    $a1, 237
  beqz  $t1, .Ljp7F07F6C4
   move  $a2, $zero
  jal   play_sfx_a1
   lw    $a0, %lo(ptr_sfx_buf)($a0)
  lui   $t2, %hi(pPlayer) # $t2, 0x8008
  lw    $t2, %lo(pPlayer)($t2)
  sw    $zero, 0x21c($t2)
.Ljp7F07F6C4:
  jal   zoom_to_watch_on_open
   nop   
  jal   check_watch_page_transistion_running
   nop   
  beqz  $v0, .Ljp7F07F6FC
   lui   $t6, %hi(pPlayer) # $t6, 0x8008
  lui   $t4, %hi(pPlayer) # $t4, 0x8008
  lw    $t4, %lo(pPlayer)($t4)
  li    $t3, 1
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  sw    $t3, 0x200($t4)
  lw    $v1, %lo(pPlayer)($v1)
  b     .Ljp7F07F740
   lw    $v0, 0x1c8($v1)
.Ljp7F07F6FC:
  lw    $t6, %lo(pPlayer)($t6)
  li    $t5, 5
  lui   $t8, %hi(pPlayer) # $t8, 0x8008
  sw    $t5, 0x1c8($t6)
  lw    $t8, %lo(pPlayer)($t8)
  li    $t7, 1
  lui   $t9, %hi(pPlayer) # $t9, 0x8008
  sw    $t7, 0x1c0($t8)
  lw    $t9, %lo(pPlayer)($t9)
  lui   $t1, %hi(pPlayer) # $t1, 0x8008
  li    $t0, 1
  sw    $zero, 0x1c4($t9)
  lw    $t1, %lo(pPlayer)($t1)
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  sw    $t0, 0x21c($t1)
  lw    $v1, %lo(pPlayer)($v1)
  lw    $v0, 0x1c8($v1)
.Ljp7F07F740:
  li    $at, 5
.Ljp7F07F744:
  bnel  $v0, $at, .Ljp7F07F784
   li    $at, 12
  lw    $t2, 0x1c0($v1)
  li    $at, 1
  bnel  $t2, $at, .Ljp7F07F770
   li    $t3, 1
  jal   sub_GAME_7F0C1310
   nop   
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  lw    $v1, %lo(pPlayer)($v1)
  li    $t3, 1
.Ljp7F07F770:
  sw    $t3, 0x200($v1)
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  lw    $v1, %lo(pPlayer)($v1)
  lw    $v0, 0x1c8($v1)
  li    $at, 12
.Ljp7F07F784:
  bne   $v0, $at, .Ljp7F07F7E8
   li    $t4, 1
  sw    $t4, 0x200($v1)
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  lw    $v1, %lo(pPlayer)($v1)
  li    $t6, 6
  li    $t7, 1
  lw    $t5, 0x1c0($v1)
  lui   $t8, %hi(pPlayer) # $t8, 0x8008
  slti  $at, $t5, 3
  bnezl $at, .Ljp7F07F7EC
   lw    $v0, 0x1c8($v1)
  sw    $t6, 0x1c8($v1)
  lw    $t8, %lo(pPlayer)($t8)
  lui   $t9, %hi(pPlayer) # $t9, 0x8008
  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  sw    $t7, 0x1c0($t8)
  lw    $t9, %lo(pPlayer)($t9)
  li    $a1, 238
  move  $a2, $zero
  sw    $zero, 0x1c4($t9)
  jal   play_sfx_a1
   lw    $a0, %lo(ptr_sfx_buf)($a0)
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  lw    $v1, %lo(pPlayer)($v1)
.Ljp7F07F7E8:
  lw    $v0, 0x1c8($v1)
.Ljp7F07F7EC:
  li    $at, 6
  bnel  $v0, $at, .Ljp7F07F8B0
   li    $at, 7
  lw    $t0, 0x1c0($v1)
  li    $at, 1
  bne   $t0, $at, .Ljp7F07F838
   nop   
  jal   zoom_from_watch_on_exit
   nop   
  lw    $t1, 0x1c($sp)
  move  $a0, $zero
  beqz  $t1, .Ljp7F07F830
   nop   
  jal   draw_item_in_hand
   move  $a1, $zero
  b     .Ljp7F07F838
   nop   
.Ljp7F07F830:
  jal   sub_GAME_7F05DAE4
   move  $a0, $zero
.Ljp7F07F838:
  jal   check_watch_page_transistion_running
   nop   
  beqz  $v0, .Ljp7F07F868
   lui   $t5, %hi(pPlayer) # $t5, 0x8008
  lui   $t3, %hi(pPlayer) # $t3, 0x8008
  lw    $t3, %lo(pPlayer)($t3)
  li    $t2, 1
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  sw    $t2, 0x200($t3)
  lw    $v1, %lo(pPlayer)($v1)
  b     .Ljp7F07F8AC
   lw    $v0, 0x1c8($v1)
.Ljp7F07F868:
  lw    $t5, %lo(pPlayer)($t5)
  li    $t4, 7
  lui   $t7, %hi(pPlayer) # $t7, 0x8008
  sw    $t4, 0x1c8($t5)
  lw    $t7, %lo(pPlayer)($t7)
  li    $t6, 1
  lui   $t8, %hi(pPlayer) # $t8, 0x8008
  sw    $t6, 0x1c0($t7)
  lw    $t8, %lo(pPlayer)($t8)
  lui   $t0, %hi(pPlayer) # $t0, 0x8008
  li    $t9, 1
  sw    $zero, 0x1c4($t8)
  lw    $t0, %lo(pPlayer)($t0)
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  sw    $t9, 0x21c($t0)
  lw    $v1, %lo(pPlayer)($v1)
  lw    $v0, 0x1c8($v1)
.Ljp7F07F8AC:
  li    $at, 7
.Ljp7F07F8B0:
  bnel  $v0, $at, .Ljp7F07F9B0
   li    $at, 8
  lw    $t1, 0x1c0($v1)
  li    $at, 1
  bne   $t1, $at, .Ljp7F07F954
   li    $at, 0x42200000 # 40.000000
  mtc1  $at, $f14
  move  $a0, $zero
  jal   sub_GAME_7F07DF28
   swc1  $f14, 0x28($sp)
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  lw    $v1, %lo(pPlayer)($v1)
  lwc1  $f14, 0x28($sp)
  mov.s $f12, $f0
  lw    $v0, 0x220($v1)
  li    $at, 3
  beql  $v0, $zero, .Ljp7F07F91C
   lui   $at, 0x41a0
  beq   $v0, $at, .Ljp7F07F918
   li    $at, 0x42200000 # 40.000000
  mtc1  $at, $f6
  lwc1  $f4, 0x258($v1)
  li    $at, 0x41A00000 # 20.000000
  mtc1  $at, $f10
  mul.s $f8, $f4, $f6
  div.s $f14, $f8, $f10
.Ljp7F07F918:
  li    $at, 0x41A00000 # 20.000000
.Ljp7F07F91C:
  mtc1  $at, $f16
  nop   
  add.s $f2, $f14, $f16
  c.lt.s $f0, $f2
  nop   
  bc1f  .Ljp7F07F93C
   nop   
  mov.s $f12, $f2
.Ljp7F07F93C:
  jal   sub_GAME_7F07E03C
   swc1  $f14, 0x28($sp)
  jal   sub_GAME_7F07E910
   lwc1  $f12, 0x28($sp)
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  lw    $v1, %lo(pPlayer)($v1)
.Ljp7F07F954:
  lw    $v0, 0x220($v1)
  li    $at, 3
  li    $t3, 8
  beqz  $v0, .Ljp7F07F984
   lui   $t5, %hi(pPlayer) # $t5, 0x8008
  beq   $v0, $at, .Ljp7F07F984
   li    $t2, 1
  sw    $t2, 0x200($v1)
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  lw    $v1, %lo(pPlayer)($v1)
  b     .Ljp7F07F9AC
   lw    $v0, 0x1c8($v1)
.Ljp7F07F984:
  sw    $t3, 0x1c8($v1)
  lw    $t5, %lo(pPlayer)($t5)
  li    $t4, 1
  lui   $t6, %hi(pPlayer) # $t6, 0x8008
  sw    $t4, 0x1c0($t5)
  lw    $t6, %lo(pPlayer)($t6)
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  sw    $zero, 0x1c4($t6)
  lw    $v1, %lo(pPlayer)($v1)
  lw    $v0, 0x1c8($v1)
.Ljp7F07F9AC:
  li    $at, 8
.Ljp7F07F9B0:
  bne   $v0, $at, .Ljp7F07FB58
   lui   $t7, %hi(pPlayer) # $t7, 0x8008
  sw    $zero, 0x200($v1)
  lw    $t7, %lo(pPlayer)($t7)
  li    $at, 1
  lw    $t8, 0x1c0($t7)
  bne   $t8, $at, .Ljp7F07FA6C
   nop   
  jal   return_ammo_in_hand
   li    $a0, 1
  sw    $v0, 0x1c($sp)
  jal   get_item_in_hand
   li    $a0, 1
  lw    $t9, 0x1c($sp)
  beql  $v0, $t9, .Ljp7F07FA18
   lw    $t0, 0x3c($sp)
  jal   sub_GAME_7F05CEBC
   li    $a0, 1
  beql  $v0, $zero, .Ljp7F07FA18
   lw    $t0, 0x3c($sp)
  jal   get_item_in_hand
   li    $a0, 1
  li    $a0, 1
  jal   draw_item_in_hand
   move  $a1, $v0
  lw    $t0, 0x3c($sp)
.Ljp7F07FA18:
  beqz  $t0, .Ljp7F07FB58
   nop   
  jal   return_ammo_in_hand
   move  $a0, $zero
  sw    $v0, 0x1c($sp)
  jal   get_item_in_hand
   move  $a0, $zero
  lw    $t1, 0x1c($sp)
  beq   $v0, $t1, .Ljp7F07FB58
   nop   
  jal   sub_GAME_7F05CEBC
   move  $a0, $zero
  beqz  $v0, .Ljp7F07FB58
   nop   
  jal   get_item_in_hand
   move  $a0, $zero
  move  $a0, $zero
  jal   draw_item_in_hand
   move  $a1, $v0
  b     .Ljp7F07FB58
   nop   
.Ljp7F07FA6C:
  jal   sub_GAME_7F07E068
   nop   
  bnez  $v0, .Ljp7F07FB58
   nop   
  jal   return_ammo_in_hand
   li    $a0, 1
  sw    $v0, 0x1c($sp)
  jal   get_item_in_hand
   li    $a0, 1
  lw    $t2, 0x1c($sp)
  bne   $v0, $t2, .Ljp7F07FB58
   nop   
  jal   sub_GAME_7F05CEBC
   li    $a0, 1
  beqz  $v0, .Ljp7F07FB58
   lw    $t3, 0x3c($sp)
  beqz  $t3, .Ljp7F07FAE4
   nop   
  jal   return_ammo_in_hand
   move  $a0, $zero
  sw    $v0, 0x18($sp)
  jal   get_item_in_hand
   move  $a0, $zero
  lw    $t4, 0x18($sp)
  bne   $v0, $t4, .Ljp7F07FB58
   nop   
  jal   sub_GAME_7F05CEBC
   move  $a0, $zero
  beqz  $v0, .Ljp7F07FB58
   nop   
.Ljp7F07FAE4:
  jal   sub_GAME_7F05DAE4
   li    $a0, 1
  lw    $t5, 0x3c($sp)
  beql  $t5, $zero, .Ljp7F07FB04
   li    $a0, 8
  jal   sub_GAME_7F05DAE4
   move  $a0, $zero
  li    $a0, 8
.Ljp7F07FB04:
  jal   set_unset_bitflags
   li    $a1, 1
  li    $a0, 4
  jal   set_unset_ammo_on_screen_setting
   li    $a1, 1
  jal   unset_flags_in_BONDdata_stationary_intro_cam
   li    $a0, 1
  jal   sub_GAME_7F08A928
   li    $a0, 1
  li    $a0, 4
  jal   set_unset_clock_lock_bits
   li    $a1, 1
  lui   $t6, %hi(pPlayer) # $t6, 0x8008
  lw    $t6, %lo(pPlayer)($t6)
  lui   $t7, %hi(pPlayer) # $t7, 0x8008
  lui   $t8, %hi(pPlayer) # $t8, 0x8008
  sw    $zero, 0x1c8($t6)
  lw    $t7, %lo(pPlayer)($t7)
  sw    $zero, 0x1c0($t7)
  lw    $t8, %lo(pPlayer)($t8)
  sw    $zero, 0x1c4($t8)
.Ljp7F07FB58:
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  lw    $v1, %lo(pPlayer)($v1)
  li    $at, 9
  li    $a0, 1
  lw    $t9, 0x1c8($v1)
  bne   $t9, $at, .Ljp7F07FBFC
   nop   
  jal   get_item_in_hand
   sw    $zero, 0x200($v1)
  sw    $v0, 0x1c($sp)
  jal   return_ammo_in_hand
   li    $a0, 1
  lw    $t0, 0x1c($sp)
  beq   $v0, $t0, .Ljp7F07FBFC
   nop   
  jal   sub_GAME_7F05CEBC
   li    $a0, 1
  beqz  $v0, .Ljp7F07FBFC
   lw    $t1, 0x3c($sp)
  beqz  $t1, .Ljp7F07FBD8
   nop   
  jal   get_item_in_hand
   move  $a0, $zero
  sw    $v0, 0x18($sp)
  jal   return_ammo_in_hand
   move  $a0, $zero
  lw    $t2, 0x18($sp)
  beq   $v0, $t2, .Ljp7F07FBFC
   nop   
  jal   sub_GAME_7F05CEBC
   move  $a0, $zero
  beqz  $v0, .Ljp7F07FBFC
.Ljp7F07FBD8:
   lui   $v0, %hi(pPlayer) # $v0, 0x8008
  addiu $v0, %lo(pPlayer) # addiu $v0, $v0, -0x5ee0
  lw    $t4, ($v0)
  li    $t3, 8
  sw    $t3, 0x1c8($t4)
  lw    $t5, ($v0)
  sw    $zero, 0x1c0($t5)
  lw    $t6, ($v0)
  sw    $zero, 0x1c4($t6)
.Ljp7F07FBFC:
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  lw    $v1, %lo(pPlayer)($v1)
  li    $at, 10
  lui   $t8, %hi(pPlayer) # $t8, 0x8008
  lw    $t7, 0x1c8($v1)
  bne   $t7, $at, .Ljp7F07FCC8
   nop   
  sw    $zero, 0x200($v1)
  lw    $t8, %lo(pPlayer)($t8)
  li    $at, 1
  lw    $t9, 0x1c0($t8)
  bne   $t9, $at, .Ljp7F07FC40
   nop   
  jal   sub_GAME_7F07DF28
   move  $a0, $zero
  jal   sub_GAME_7F07E03C
   mov.s $f12, $f0
.Ljp7F07FC40:
  jal   get_item_in_hand
   li    $a0, 1
  sw    $v0, 0x1c($sp)
  jal   return_ammo_in_hand
   li    $a0, 1
  lw    $t0, 0x1c($sp)
  beq   $v0, $t0, .Ljp7F07FCC8
   nop   
  jal   sub_GAME_7F05CEBC
   li    $a0, 1
  beqz  $v0, .Ljp7F07FCC8
   lw    $t1, 0x3c($sp)
  beqz  $t1, .Ljp7F07FCA4
   nop   
  jal   get_item_in_hand
   move  $a0, $zero
  sw    $v0, 0x18($sp)
  jal   return_ammo_in_hand
   move  $a0, $zero
  lw    $t2, 0x18($sp)
  beq   $v0, $t2, .Ljp7F07FCC8
   nop   
  jal   sub_GAME_7F05CEBC
   move  $a0, $zero
  beqz  $v0, .Ljp7F07FCC8
.Ljp7F07FCA4:
   lui   $v0, %hi(pPlayer) # $v0, 0x8008
  addiu $v0, %lo(pPlayer) # addiu $v0, $v0, -0x5ee0
  lw    $t4, ($v0)
  li    $t3, 8
  sw    $t3, 0x1c8($t4)
  lw    $t5, ($v0)
  sw    $zero, 0x1c0($t5)
  lw    $t6, ($v0)
  sw    $zero, 0x1c4($t6)
.Ljp7F07FCC8:
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  lw    $v1, %lo(pPlayer)($v1)
  li    $at, 11
  li    $a0, 1
  lw    $t7, 0x1c8($v1)
  bne   $t7, $at, .Ljp7F07FD70
   nop   
  jal   get_item_in_hand
   sw    $zero, 0x200($v1)
  sw    $v0, 0x1c($sp)
  jal   return_ammo_in_hand
   li    $a0, 1
  lw    $t8, 0x1c($sp)
  bne   $v0, $t8, .Ljp7F07FD70
   nop   
  jal   sub_GAME_7F05CEBC
   li    $a0, 1
  beqz  $v0, .Ljp7F07FD70
   lw    $t9, 0x3c($sp)
  beqz  $t9, .Ljp7F07FD48
   nop   
  jal   get_item_in_hand
   move  $a0, $zero
  sw    $v0, 0x18($sp)
  jal   return_ammo_in_hand
   move  $a0, $zero
  lw    $t0, 0x18($sp)
  bne   $v0, $t0, .Ljp7F07FD70
   nop   
  jal   sub_GAME_7F05CEBC
   move  $a0, $zero
  beqz  $v0, .Ljp7F07FD70
.Ljp7F07FD48:
   lui   $t2, %hi(pPlayer) # $t2, 0x8008
  lw    $t2, %lo(pPlayer)($t2)
  li    $t1, 1
  lui   $t3, %hi(pPlayer) # $t3, 0x8008
  sw    $t1, 0x1c8($t2)
  lw    $t3, %lo(pPlayer)($t3)
  lui   $t4, %hi(pPlayer) # $t4, 0x8008
  sw    $zero, 0x1c0($t3)
  lw    $t4, %lo(pPlayer)($t4)
  sw    $zero, 0x1c4($t4)
.Ljp7F07FD70:
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  lw    $v1, %lo(pPlayer)($v1)
  li    $at, 13
  li    $a0, 1
  lw    $t5, 0x1c8($v1)
  bne   $t5, $at, .Ljp7F07FDF4
   nop   
  jal   sub_GAME_7F05CEBC
   sw    $zero, 0x200($v1)
  beqz  $v0, .Ljp7F07FDF4
   nop   
  jal   sub_GAME_7F05CEBC
   move  $a0, $zero
  beqz  $v0, .Ljp7F07FDF4
   lui   $v1, %hi(pPlayer) # $v1, 0x8008
  lw    $v1, %lo(pPlayer)($v1)
  li    $at, 5
  lw    $v0, 0xc3c($v1)
  beq   $v0, $at, .Ljp7F07FDF4
   li    $at, 6
  beq   $v0, $at, .Ljp7F07FDF4
   li    $at, 7
  beq   $v0, $at, .Ljp7F07FDF4
   li    $at, 8
  beq   $v0, $at, .Ljp7F07FDF4
   li    $t6, 1
  sw    $t6, 0x1c8($v1)
  lui   $t7, %hi(pPlayer) # $t7, 0x8008
  lw    $t7, %lo(pPlayer)($t7)
  lui   $t8, %hi(pPlayer) # $t8, 0x8008
  sw    $zero, 0x1c0($t7)
  lw    $t8, %lo(pPlayer)($t8)
  sw    $zero, 0x1c4($t8)
.Ljp7F07FDF4:
  jal   sub_GAME_7F07E090
   nop   
  jal   sub_GAME_7F07E964
   nop   
  jal   sub_GAME_7F07E62C
   nop   
  lui   $t9, %hi(pPlayer) # $t9, 0x8008
  lw    $t9, %lo(pPlayer)($t9)
  lw    $v0, 0x1c8($t9)
  li    $at, 5
.Ljp7F07FE1C:
  bnel  $v0, $at, .Ljp7F07FE40
   li    $at, 12
  jal   set_controls_locked_flag
   li    $a0, 1
  jal   sub_GAME_7F0A6A80
   nop   
  b     .Ljp7F07FE64
   lw    $ra, 0x14($sp)
  li    $at, 12
.Ljp7F07FE40:
  bne   $v0, $at, .Ljp7F07FE58
   nop   
  jal   set_controls_locked_flag
   li    $a0, 1
  b     .Ljp7F07FE64
   lw    $ra, 0x14($sp)
.Ljp7F07FE58:
  jal   set_controls_locked_flag
   move  $a0, $zero
  lw    $ra, 0x14($sp)
.Ljp7F07FE64:
  addiu $sp, $sp, 0x40
  jr    $ra
   nop   
");
#endif

void set_open_close_solo_watch_menu_to1(void) {
  pPlayer->open_close_solo_watch_menu = 1;
}

asm(R"
.late_rodata
glabel D_8005508C
.word 0x3fd9999a /*1.7*/
glabel D_80055090
.word 0x3f8ccccd /*1.1*/

.text
glabel trigger_solo_watch_menu
  addiu $sp, $sp, -0x40
  sw    $s4, 0x38($sp)
  lui   $s4, %hi(pPlayer)
  addiu $s4, %lo(pPlayer) # addiu $s4, $s4, -0x5f50
  lw    $v1, ($s4)
  sw    $ra, 0x3c($sp)
  sw    $s3, 0x34($sp)
  sw    $s2, 0x30($sp)
  sw    $s1, 0x2c($sp)
  sw    $s0, 0x28($sp)
  lw    $v0, 0x1c8($v1)
  li    $a1, 1
  bnez  $v0, .L7F07FAA8
   nop   
  bnez  $a0, .L7F07FCA4
   lui   $v0, %hi(watch_transition_time)
  lui   $at, %hi(D_8005508C)
  lwc1  $f0, %lo(D_8005508C)($at)
  addiu $v0, %lo(watch_transition_time) # addiu $v0, $v0, 0x65a8
  lui   $at, %hi(D_80055090)
  lwc1  $f6, %lo(D_80055090)($at)
  lwc1  $f4, ($v0)
  mul.s $f8, $f4, $f6
  swc1  $f8, ($v0)
  lwc1  $f10, ($v0)
  c.lt.s $f0, $f10
  nop   
  bc1f  .L7F07F8EC
   nop   
  swc1  $f0, ($v0)
.L7F07F8EC:
  jal   sub_GAME_7F05CEBC
   li    $a0, 1
  beql  $v0, $zero, .L7F07F944
   lw    $t7, ($s4)
  jal   sub_GAME_7F05CEBC
   move  $a0, $zero
  beql  $v0, $zero, .L7F07F944
   lw    $t7, ($s4)
  lw    $v1, ($s4)
  li    $at, 5
  lw    $v0, 0xc3c($v1)
  beq   $v0, $at, .L7F07F940
   li    $at, 6
  beq   $v0, $at, .L7F07F940
   li    $at, 7
  beq   $v0, $at, .L7F07F940
   li    $a2, 8
  beq   $a2, $v0, .L7F07F940
   li    $a1, 1
  b     .L7F07F94C
   sw    $a1, 0x1c8($v1)
.L7F07F940:
  lw    $t7, ($s4)
.L7F07F944:
  li    $t6, 13
  sw    $t6, 0x1c8($t7)
.L7F07F94C:
  lw    $t8, ($s4)
  sw    $zero, 0x1c0($t8)
  lw    $t9, ($s4)
  jal   sub_GAME_7F07DEFC
   sw    $zero, 0x1c4($t9)
  jal   sub_GAME_7F07E504
   nop   
  jal   get_BONDdata_watch_armor
   nop   
  lw    $a0, ($s4)
  mfc1  $a3, $f0
  li    $a1, 46
  li    $a2, 1
  jal   sub_GAME_7F0A2F30
   addiu $a0, $a0, 0x12b8
  lw    $v1, ($s4)
  lui   $at, (0x800012B8 >> 16) 
  ori   $at, (0x800012B8 & 0xFFFF) # ori $at, $at, 0x12b8
  li    $a2, 46
  addu  $a1, $v1, $at
  jal   sub_GAME_7F0A3330
   addiu $a0, $v1, 0x19f8
  jal   get_BONDdata_watch_health
   nop   
  lw    $a0, ($s4)
  mfc1  $a3, $f0
  li    $a1, 46
  li    $a2, -1
  jal   sub_GAME_7F0A2F30
   addiu $a0, $a0, 0x1598
  lw    $v1, ($s4)
  lui   $at, (0x80001598 >> 16) 
  ori   $at, (0x80001598 & 0xFFFF) # ori $at, $at, 0x1598
  li    $a2, 46
  addu  $a1, $v1, $at
  jal   sub_GAME_7F0A3330
   addiu $a0, $v1, 0x2128
  jal   sub_GAME_7F0A69A8
   nop   
  lw    $v1, ($s4)
  move  $s0, $zero
  addiu $s3, $v1, 0x2858
  addiu $s1, $v1, 0x1878
.L7F07F9F8:
  li    $t0, 20
  li    $t1, -299
  li    $t2, 310
  move  $s2, $s1
  sw    $t2, 0x18($sp)
  sw    $t1, 0x14($sp)
  sw    $t0, 0x10($sp)
  move  $a0, $s1
  move  $a1, $s0
  move  $a2, $zero
  jal   sub_GAME_7F0A3AB8
   li    $a3, 100
  lui   $at, 0x8000
  move  $s1, $v0
  addu  $a1, $s2, $at
  jal   sub_GAME_7F0A3B40
   move  $a0, $s3
  addiu $s0, $s0, 0x7d
  li    $at, 625
  bne   $s0, $at, .L7F07F9F8
   move  $s3, $v0
  lui   $s0, 0xb800
  sw    $s0, ($v0)
  sw    $zero, 4($v0)
  lw    $v1, ($s4)
  li    $t3, 20
  li    $t4, -460
  addiu $a0, $v1, 0x19b8
  move  $s2, $a0
  sw    $t4, 0x14($sp)
  sw    $t3, 0x10($sp)
  sw    $zero, 0x18($sp)
  move  $a1, $zero
  move  $a2, $zero
  li    $a3, 920
  jal   sub_GAME_7F0A3AB8
   addiu $s3, $v1, 0x2998
  lui   $at, 0x8000
  addu  $a1, $s2, $at
  jal   sub_GAME_7F0A3B40
   move  $a0, $s3
  sw    $s0, ($v0)
  b     .L7F07FCA4
   sw    $zero, 4($v0)
.L7F07FAA8:
  bne   $a1, $v0, .L7F07FACC
   li    $at, 2
  li    $t5, 9
  sw    $t5, 0x1c8($v1)
  lw    $t6, ($s4)
  sw    $zero, 0x1c0($t6)
  lw    $t7, ($s4)
  b     .L7F07FCA4
   sw    $zero, 0x1c4($t7)
.L7F07FACC:
  bne   $v0, $at, .L7F07FAF0
   li    $a2, 3
  li    $t8, 10
  sw    $t8, 0x1c8($v1)
  lw    $t9, ($s4)
  sw    $zero, 0x1c0($t9)
  lw    $t0, ($s4)
  b     .L7F07FCA4
   sw    $zero, 0x1c4($t0)
.L7F07FAF0:
  bne   $a2, $v0, .L7F07FB14
   li    $a3, 4
  li    $t1, 7
  sw    $t1, 0x1c8($v1)
  lw    $t2, ($s4)
  sw    $zero, 0x1c0($t2)
  lw    $t3, ($s4)
  b     .L7F07FCA4
   sw    $zero, 0x1c4($t3)
.L7F07FB14:
  bne   $a3, $v0, .L7F07FB38
   li    $at, 5
  li    $t4, 6
  sw    $t4, 0x1c8($v1)
  lw    $t5, ($s4)
  sw    $zero, 0x1c0($t5)
  lw    $t6, ($s4)
  b     .L7F07FCA4
   sw    $zero, 0x1c4($t6)
.L7F07FB38:
  bnel  $v0, $at, .L7F07FB7C
   li    $at, 12
  jal   deleteCurrentSelectedFolder
   nop   
  jal   sub_GAME_7F0C1340
   nop   
  lw    $t8, ($s4)
  li    $t7, 12
  sw    $t7, 0x1c8($t8)
  lw    $t9, ($s4)
  sw    $zero, 0x1c0($t9)
  lw    $t0, ($s4)
  sw    $zero, 0x1c4($t0)
  lw    $t1, ($s4)
  b     .L7F07FCA4
   sw    $zero, 0x1d0($t1)
  li    $at, 12
.L7F07FB7C:
  beq   $v0, $at, .L7F07FCA4
   li    $at, 6
  bnel  $v0, $at, .L7F07FBB8
   li    $at, 7
  bnezl $a0, .L7F07FCA8
   lw    $ra, 0x3c($sp)
  sw    $a3, 0x1c8($v1)
  lw    $t2, ($s4)
  sw    $zero, 0x1c0($t2)
  lw    $t3, ($s4)
  jal   sub_GAME_7F0A69A8
   sw    $zero, 0x1c4($t3)
  b     .L7F07FCA8
   lw    $ra, 0x3c($sp)
  li    $at, 7
.L7F07FBB8:
  bnel  $v0, $at, .L7F07FBEC
   li    $a2, 8
  bnezl $a0, .L7F07FCA8
   lw    $ra, 0x3c($sp)
  sw    $a2, 0x1c8($v1)
  lw    $t4, ($s4)
  sw    $zero, 0x1c0($t4)
  lw    $t5, ($s4)
  jal   sub_GAME_7F0A69A8
   sw    $zero, 0x1c4($t5)
  b     .L7F07FCA8
   lw    $ra, 0x3c($sp)
  li    $a2, 8
.L7F07FBEC:
  bne   $a2, $v0, .L7F07FC1C
   li    $at, 9
  bnez  $a0, .L7F07FCA4
   li    $t6, 11
  sw    $t6, 0x1c8($v1)
  lw    $t7, ($s4)
  sw    $zero, 0x1c0($t7)
  lw    $t8, ($s4)
  jal   sub_GAME_7F0A69A8
   sw    $zero, 0x1c4($t8)
  b     .L7F07FCA8
   lw    $ra, 0x3c($sp)
.L7F07FC1C:
  bnel  $v0, $at, .L7F07FC48
   li    $at, 10
  bnezl $a0, .L7F07FCA8
   lw    $ra, 0x3c($sp)
  sw    $a1, 0x1c8($v1)
  lw    $t9, ($s4)
  sw    $zero, 0x1c0($t9)
  lw    $t0, ($s4)
  b     .L7F07FCA4
   sw    $zero, 0x1c4($t0)
  li    $at, 10
.L7F07FC48:
  bnel  $v0, $at, .L7F07FC74
   li    $at, 11
  bnezl $a0, .L7F07FCA8
   lw    $ra, 0x3c($sp)
  sw    $a1, 0x1c8($v1)
  lw    $t1, ($s4)
  sw    $zero, 0x1c0($t1)
  lw    $t2, ($s4)
  b     .L7F07FCA4
   sw    $zero, 0x1c4($t2)
  li    $at, 11
.L7F07FC74:
  bnel  $v0, $at, .L7F07FC98
   li    $at, 13
  sw    $a2, 0x1c8($v1)
  lw    $t3, ($s4)
  sw    $zero, 0x1c0($t3)
  lw    $t4, ($s4)
  b     .L7F07FCA4
   sw    $zero, 0x1c4($t4)
  li    $at, 13
.L7F07FC98:
  bnel  $v0, $at, .L7F07FCA8
   lw    $ra, 0x3c($sp)
  sw    $zero, 0x1c8($v1)
.L7F07FCA4:
  lw    $ra, 0x3c($sp)
.L7F07FCA8:
  lw    $s0, 0x28($sp)
  lw    $s1, 0x2c($sp)
  lw    $s2, 0x30($sp)
  lw    $s3, 0x34($sp)
  lw    $s4, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x40
");

asm(R"
glabel sub_GAME_7F07FCC4
  li    $at, -1
  bne   $a0, $at, .L7F07FD20
   lui   $v1, %hi(pPlayer)
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $v0, ($v1)
  li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f2
  lui   $at, %hi(global_timer_delta)
  lwc1  $f6, %lo(global_timer_delta)($at)
  lwc1  $f4, 0x170($v0)
  sub.s $f8, $f4, $f6
  swc1  $f8, 0x170($v0)
  lw    $v0, ($v1)
  lwc1  $f0, 0x170($v0)
  c.lt.s $f0, $f2
  nop   
  bc1f  .L7F07FE14
   nop   
  swc1  $f2, 0x170($v0)
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  b     .L7F07FE14
   lwc1  $f0, 0x170($v0)
.L7F07FD20:
  li    $at, 1
  bne   $a0, $at, .L7F07FD80
   lui   $v1, %hi(pPlayer)
  lui   $v1, %hi(pPlayer)
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $v0, ($v1)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f2
  lui   $at, %hi(global_timer_delta)
  lwc1  $f16, %lo(global_timer_delta)($at)
  lwc1  $f10, 0x170($v0)
  add.s $f18, $f10, $f16
  swc1  $f18, 0x170($v0)
  lw    $v0, ($v1)
  lwc1  $f0, 0x170($v0)
  c.lt.s $f2, $f0
  nop   
  bc1f  .L7F07FE14
   nop   
  swc1  $f2, 0x170($v0)
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  b     .L7F07FE14
   lwc1  $f0, 0x170($v0)
.L7F07FD80:
  addiu $v1, $v1, %lo(pPlayer)
  lw    $v0, ($v1)
  mtc1  $zero, $f2
  lui   $at, %hi(global_timer_delta)
  lwc1  $f0, 0x170($v0)
  c.lt.s $f2, $f0
  nop   
  bc1f  .L7F07FDE0
   nop   
  lui   $at, %hi(global_timer_delta)
  lwc1  $f4, %lo(global_timer_delta)($at)
  sub.s $f6, $f0, $f4
  swc1  $f6, 0x170($v0)
  lw    $v0, ($v1)
  lwc1  $f0, 0x170($v0)
  c.lt.s $f0, $f2
  nop   
  bc1f  .L7F07FE14
   nop   
  swc1  $f2, 0x170($v0)
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  b     .L7F07FE14
   lwc1  $f0, 0x170($v0)
.L7F07FDE0:
  lwc1  $f8, %lo(global_timer_delta)($at)
  add.s $f10, $f0, $f8
  swc1  $f10, 0x170($v0)
  lw    $v0, ($v1)
  lwc1  $f0, 0x170($v0)
  c.lt.s $f2, $f0
  nop   
  bc1f  .L7F07FE14
   nop   
  swc1  $f2, 0x170($v0)
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lwc1  $f0, 0x170($v0)
.L7F07FE14:
  jr    $ra
   swc1  $f0, 0x16c($v0)
");

asm(R"
glabel sub_GAME_7F07FE1C
  li    $at, 1
  bne   $a0, $at, .L7F07FE78
   lui   $v1, %hi(pPlayer)
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $v0, ($v1)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f2
  lui   $at, %hi(global_timer_delta)
  lwc1  $f6, %lo(global_timer_delta)($at)
  lwc1  $f4, 0x2a4c($v0)
  add.s $f8, $f4, $f6
  swc1  $f8, 0x2a4c($v0)
  lw    $v0, ($v1)
  lwc1  $f0, 0x2a4c($v0)
  c.lt.s $f2, $f0
  nop   
  bc1f  .L7F07FF6C
   nop   
  swc1  $f2, 0x2a4c($v0)
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  b     .L7F07FF6C
   lwc1  $f0, 0x2a4c($v0)
.L7F07FE78:
  li    $at, -1
  bne   $a0, $at, .L7F07FED8
   lui   $v1, %hi(pPlayer)
  lui   $v1, %hi(pPlayer)
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $v0, ($v1)
  li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f2
  lui   $at, %hi(global_timer_delta)
  lwc1  $f16, %lo(global_timer_delta)($at)
  lwc1  $f10, 0x2a4c($v0)
  sub.s $f18, $f10, $f16
  swc1  $f18, 0x2a4c($v0)
  lw    $v0, ($v1)
  lwc1  $f0, 0x2a4c($v0)
  c.lt.s $f0, $f2
  nop   
  bc1f  .L7F07FF6C
   nop   
  swc1  $f2, 0x2a4c($v0)
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  b     .L7F07FF6C
   lwc1  $f0, 0x2a4c($v0)
.L7F07FED8:
  addiu $v1, $v1, %lo(pPlayer)
  lw    $v0, ($v1)
  mtc1  $zero, $f2
  lui   $at, %hi(global_timer_delta)
  lwc1  $f0, 0x2a4c($v0)
  c.lt.s $f2, $f0
  nop   
  bc1f  .L7F07FF38
   nop   
  lui   $at, %hi(global_timer_delta)
  lwc1  $f4, %lo(global_timer_delta)($at)
  sub.s $f6, $f0, $f4
  swc1  $f6, 0x2a4c($v0)
  lw    $v0, ($v1)
  lwc1  $f0, 0x2a4c($v0)
  c.lt.s $f0, $f2
  nop   
  bc1f  .L7F07FF6C
   nop   
  swc1  $f2, 0x2a4c($v0)
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  b     .L7F07FF6C
   lwc1  $f0, 0x2a4c($v0)
.L7F07FF38:
  lwc1  $f8, %lo(global_timer_delta)($at)
  add.s $f10, $f0, $f8
  swc1  $f10, 0x2a4c($v0)
  lw    $v0, ($v1)
  lwc1  $f0, 0x2a4c($v0)
  c.lt.s $f2, $f0
  nop   
  bc1f  .L7F07FF6C
   nop   
  swc1  $f2, 0x2a4c($v0)
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lwc1  $f0, 0x2a4c($v0)
.L7F07FF6C:
  jr    $ra
   swc1  $f0, 0x174($v0)
");

asm(R"
.late_rodata
glabel D_80055094
.word 0xbf333333 /*-0.69999999*/
glabel D_80055098
.word 0x3f333333 /*0.69999999*/

.text
glabel sub_GAME_7F07FF74
  mtc1  $zero, $f2
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  c.lt.s $f2, $f12
  nop   
  bc1fl .L7F07FFC0
   c.lt.s $f12, $f2
  jal   video_related_23
   swc1  $f12, 0x18($sp)
  lwc1  $f12, 0x18($sp)
  lui   $at, %hi(D_80055094)
  lwc1  $f6, %lo(D_80055094)($at)
  mul.s $f4, $f0, $f12
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f10
  mul.s $f8, $f4, $f6
  b     .L7F080000
   div.s $f0, $f8, $f10
  c.lt.s $f12, $f2
.L7F07FFC0:
  nop   
  bc1fl .L7F080000
   mov.s $f0, $f2
  jal   video_related_23
   swc1  $f12, 0x18($sp)
  lwc1  $f12, 0x18($sp)
  lui   $at, %hi(D_80055098)
  lwc1  $f4, %lo(D_80055098)($at)
  neg.s $f16, $f12
  li    $at, 0x42700000 # 60.000000
  mul.s $f18, $f0, $f16
  mtc1  $at, $f8
  mul.s $f6, $f18, $f4
  b     .L7F080000
   div.s $f0, $f6, $f8
  mov.s $f0, $f2
.L7F080000:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_8005509C
.word 0x3d4ccccd /*0.050000001*/
glabel D_800550A0
.word 0x3c4ccccd /*0.0125*/
glabel D_800550A4
.word 0x3d4ccccd /*0.050000001*/
glabel D_800550A8
.word 0x3c4ccccd /*0.0125*/
glabel D_800550AC
.word 0x3d4ccccd /*0.050000001*/
glabel D_800550B0
.word 0x3d4ccccd /*0.050000001*/

.text
glabel sub_GAME_7F080010
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  jal   video_related_23
   swc1  $f12, 0x20($sp)
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f4
  lwc1  $f12, 0x20($sp)
  div.s $f14, $f0, $f4
  jal   sub_GAME_7F07FF74
   swc1  $f14, 0x1c($sp)
  lwc1  $f2, 0x20($sp)
  mtc1  $zero, $f12
  lui   $v1, %hi(pPlayer)
  lwc1  $f14, 0x1c($sp)
  c.lt.s $f12, $f2
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  bc1fl .L7F0800E0
   c.lt.s $f2, $f12
  lw    $v0, ($v1)
  lui   $at, %hi(D_800550A0)
  lwc1  $f2, 0x160($v0)
  c.lt.s $f12, $f2
  nop   
  bc1f  .L7F08009C
   nop   
  lui   $at, %hi(D_8005509C)
  lwc1  $f6, %lo(D_8005509C)($at)
  lui   $at, %hi(global_timer_delta)
  lwc1  $f8, %lo(global_timer_delta)($at)
  mul.s $f10, $f6, $f8
  nop   
  mul.s $f16, $f10, $f14
  sub.s $f18, $f2, $f16
  b     .L7F0800BC
   swc1  $f18, 0x160($v0)
.L7F08009C:
  lwc1  $f4, %lo(D_800550A0)($at)
  lui   $at, %hi(global_timer_delta)
  lwc1  $f6, %lo(global_timer_delta)($at)
  mul.s $f8, $f4, $f6
  nop   
  mul.s $f10, $f8, $f14
  sub.s $f16, $f2, $f10
  swc1  $f16, 0x160($v0)
.L7F0800BC:
  lw    $v0, ($v1)
  lwc1  $f18, 0x160($v0)
  c.lt.s $f18, $f0
  nop   
  bc1fl .L7F08021C
   lw    $ra, 0x14($sp)
  b     .L7F080218
   swc1  $f0, 0x160($v0)
  c.lt.s $f2, $f12
.L7F0800E0:
  lui   $v1, %hi(pPlayer)
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  bc1fl .L7F080180
   lw    $v0, ($v1)
  lui   $v1, %hi(pPlayer)
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $v0, ($v1)
  lui   $at, %hi(D_800550A8)
  lwc1  $f2, 0x160($v0)
  c.lt.s $f2, $f12
  nop   
  bc1f  .L7F08013C
   nop   
  lui   $at, %hi(D_800550A4)
  lwc1  $f4, %lo(D_800550A4)($at)
  lui   $at, %hi(D_800550A8)
  lwc1  $f6, %lo(global_timer_delta)($at)
  mul.s $f8, $f4, $f6
  nop   
  mul.s $f10, $f8, $f14
  add.s $f16, $f2, $f10
  b     .L7F08015C
   swc1  $f16, 0x160($v0)
.L7F08013C:
  lwc1  $f18, %lo(D_800550A8)($at)
  lui   $at, %hi(global_timer_delta)
  lwc1  $f4, %lo(global_timer_delta)($at)
  mul.s $f6, $f18, $f4
  nop   
  mul.s $f8, $f6, $f14
  add.s $f10, $f2, $f8
  swc1  $f10, 0x160($v0)
.L7F08015C:
  lw    $v0, ($v1)
  lwc1  $f16, 0x160($v0)
  c.lt.s $f0, $f16
  nop   
  bc1fl .L7F08021C
   lw    $ra, 0x14($sp)
  b     .L7F080218
   swc1  $f0, 0x160($v0)
  lw    $v0, ($v1)
.L7F080180:
  lui   $at, %hi(D_800550B0)
  lwc1  $f2, 0x160($v0)
  c.lt.s $f0, $f2
  nop   
  bc1f  .L7F0801DC
   nop   
  lui   $at, %hi(D_800550AC)
  lwc1  $f18, %lo(D_800550AC)($at)
  lui   $at, %hi(D_800550B0)
  lwc1  $f4, %lo(global_timer_delta)($at)
  mul.s $f6, $f18, $f4
  nop   
  mul.s $f8, $f6, $f14
  sub.s $f10, $f2, $f8
  swc1  $f10, 0x160($v0)
  lw    $v0, ($v1)
  lwc1  $f16, 0x160($v0)
  c.lt.s $f16, $f0
  nop   
  bc1f  .L7F080218
   nop   
  b     .L7F080218
   swc1  $f0, 0x160($v0)
.L7F0801DC:
  lwc1  $f18, %lo(D_800550B0)($at)
  lui   $at, %hi(global_timer_delta)
  lwc1  $f4, %lo(global_timer_delta)($at)
  mul.s $f6, $f18, $f4
  nop   
  mul.s $f8, $f6, $f14
  add.s $f10, $f2, $f8
  swc1  $f10, 0x160($v0)
  lw    $v0, ($v1)
  lwc1  $f16, 0x160($v0)
  c.lt.s $f0, $f16
  nop   
  bc1f  .L7F080218
   nop   
  swc1  $f0, 0x160($v0)
.L7F080218:
  lw    $ra, 0x14($sp)
.L7F08021C:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_800550B4
.word 0xbf333333 /*-0.69999999*/
glabel D_800550B8
.word 0x3f333333 /*0.69999999*/

.text
glabel sub_GAME_7F080228
  mtc1  $zero, $f2
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  c.lt.s $f2, $f12
  nop   
  bc1fl .L7F080274
   c.lt.s $f12, $f2
  jal   video_related_23
   swc1  $f12, 0x18($sp)
  lwc1  $f12, 0x18($sp)
  lui   $at, %hi(D_800550B4)
  lwc1  $f6, %lo(D_800550B4)($at)
  mul.s $f4, $f0, $f12
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f10
  mul.s $f8, $f4, $f6
  b     .L7F0802B4
   div.s $f0, $f8, $f10
  c.lt.s $f12, $f2
.L7F080274:
  nop   
  bc1fl .L7F0802B4
   mov.s $f0, $f2
  jal   video_related_23
   swc1  $f12, 0x18($sp)
  lwc1  $f12, 0x18($sp)
  lui   $at, %hi(D_800550B8)
  lwc1  $f4, %lo(D_800550B8)($at)
  neg.s $f16, $f12
  li    $at, 0x42700000 # 60.000000
  mul.s $f18, $f0, $f16
  mtc1  $at, $f8
  mul.s $f6, $f18, $f4
  b     .L7F0802B4
   div.s $f0, $f6, $f8
  mov.s $f0, $f2
.L7F0802B4:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_800550BC
.word 0x3d4ccccd /*0.050000001*/
glabel D_800550C0
.word 0x3c4ccccd /*0.0125*/
glabel D_800550C4
.word 0x3d4ccccd /*0.050000001*/
glabel D_800550C8
.word 0x3c4ccccd /*0.0125*/
glabel D_800550CC
.word 0x3d4ccccd /*0.050000001*/
glabel D_800550D0
.word 0x3d4ccccd /*0.050000001*/

.text
glabel sub_GAME_7F0802C4
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  jal   video_related_23
   swc1  $f12, 0x20($sp)
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f4
  lwc1  $f12, 0x20($sp)
  div.s $f14, $f0, $f4
  jal   sub_GAME_7F080228
   swc1  $f14, 0x1c($sp)
  lwc1  $f2, 0x20($sp)
  mtc1  $zero, $f12
  lui   $v1, %hi(pPlayer)
  lwc1  $f14, 0x1c($sp)
  c.lt.s $f12, $f2
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  bc1fl .L7F080394
   c.lt.s $f2, $f12
  lw    $v0, ($v1)
  lui   $at, %hi(D_800550C0)
  lwc1  $f2, 0x14c($v0)
  c.lt.s $f12, $f2
  nop   
  bc1f  .L7F080350
   nop   
  lui   $at, %hi(D_800550BC)
  lwc1  $f6, %lo(D_800550BC)($at)
  lui   $at, %hi(D_800550C0)
  lwc1  $f8, %lo(global_timer_delta)($at)
  mul.s $f10, $f6, $f8
  nop   
  mul.s $f16, $f10, $f14
  sub.s $f18, $f2, $f16
  b     .L7F080370
   swc1  $f18, 0x14c($v0)
.L7F080350:
  lwc1  $f4, %lo(D_800550C0)($at)
  lui   $at, %hi(global_timer_delta)
  lwc1  $f6, %lo(global_timer_delta)($at)
  mul.s $f8, $f4, $f6
  nop   
  mul.s $f10, $f8, $f14
  sub.s $f16, $f2, $f10
  swc1  $f16, 0x14c($v0)
.L7F080370:
  lw    $v0, ($v1)
  lwc1  $f18, 0x14c($v0)
  c.lt.s $f18, $f0
  nop   
  bc1fl .L7F0804D4
   lw    $ra, 0x14($sp)
  b     .L7F0804D0
   swc1  $f0, 0x14c($v0)
  c.lt.s $f2, $f12
.L7F080394:
  lui   $v1, %hi(pPlayer)
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  bc1fl .L7F080438
   lw    $v0, ($v1)
  lui   $v1, %hi(pPlayer)
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $v0, ($v1)
  mtc1  $zero, $f4
  lui   $at, %hi(D_800550C8)
  lwc1  $f2, 0x14c($v0)
  c.lt.s $f2, $f4
  nop   
  bc1f  .L7F0803F4
   nop   
  lui   $at, %hi(D_800550C4)
  lwc1  $f6, %lo(D_800550C4)($at)
  lui   $at, %hi(D_800550C8)
  lwc1  $f8, %lo(global_timer_delta)($at)
  mul.s $f10, $f6, $f8
  nop   
  mul.s $f16, $f10, $f14
  add.s $f18, $f2, $f16
  b     .L7F080414
   swc1  $f18, 0x14c($v0)
.L7F0803F4:
  lwc1  $f4, %lo(D_800550C8)($at)
  lui   $at, %hi(global_timer_delta)
  lwc1  $f6, %lo(global_timer_delta)($at)
  mul.s $f8, $f4, $f6
  nop   
  mul.s $f10, $f8, $f14
  add.s $f16, $f2, $f10
  swc1  $f16, 0x14c($v0)
.L7F080414:
  lw    $v0, ($v1)
  lwc1  $f18, 0x14c($v0)
  c.lt.s $f0, $f18
  nop   
  bc1fl .L7F0804D4
   lw    $ra, 0x14($sp)
  b     .L7F0804D0
   swc1  $f0, 0x14c($v0)
  lw    $v0, ($v1)
.L7F080438:
  lui   $at, %hi(D_800550D0)
  lwc1  $f2, 0x14c($v0)
  c.lt.s $f0, $f2
  nop   
  bc1f  .L7F080494
   nop   
  lui   $at, %hi(D_800550CC)
  lwc1  $f4, %lo(D_800550CC)($at)
  lui   $at, %hi(D_800550D0)
  lwc1  $f6, %lo(global_timer_delta)($at)
  mul.s $f8, $f4, $f6
  nop   
  mul.s $f10, $f8, $f14
  sub.s $f16, $f2, $f10
  swc1  $f16, 0x14c($v0)
  lw    $v0, ($v1)
  lwc1  $f18, 0x14c($v0)
  c.lt.s $f18, $f0
  nop   
  bc1f  .L7F0804D0
   nop   
  b     .L7F0804D0
   swc1  $f0, 0x14c($v0)
.L7F080494:
  lwc1  $f4, %lo(D_800550D0)($at)
  lui   $at, %hi(global_timer_delta)
  lwc1  $f6, %lo(global_timer_delta)($at)
  mul.s $f8, $f4, $f6
  nop   
  mul.s $f10, $f8, $f14
  add.s $f16, $f2, $f10
  swc1  $f16, 0x14c($v0)
  lw    $v0, ($v1)
  lwc1  $f18, 0x14c($v0)
  c.lt.s $f0, $f18
  nop   
  bc1f  .L7F0804D0
   nop   
  swc1  $f0, 0x14c($v0)
.L7F0804D0:
  lw    $ra, 0x14($sp)
.L7F0804D4:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0804E0
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  addiu $sp, $sp, -0x80
  sw    $s0, 0x18($sp)
  lui   $t6, %hi(camera_80036430) 
  lw    $t6, %lo(camera_80036430)($t6)
  sw    $ra, 0x1c($sp)
  move  $s0, $a0
  lwc1  $f0, 0x3dc($v0)
  lw    $a3, 0x3d0($v0)
  lw    $t0, 0x3d4($v0)
  bnez  $t6, .L7F080520
   lw    $t1, 0x3d8($v0)
  lui   $t7, %hi(camera_80036434) 
  lw    $t7, %lo(camera_80036434)($t7)
  beqz  $t7, .L7F080534
.L7F080520:
   li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f0
  move  $t1, $zero
  move  $t0, $zero
  move  $a3, $zero
.L7F080534:
  mtc1  $zero, $f4
  lui   $t9, (0xBA001402 >> 16) # lui $t9, 0xba00
  lui   $t2, (0xBA000602 >> 16) # lui $t2, 0xba00
  c.lt.s $f4, $f0
  move  $v0, $s0
  lui   $t8, 0xe700
  ori   $t9, (0xBA001402 & 0xFFFF) # ori $t9, $t9, 0x1402
  bc1f  .L7F08079C
   ori   $t2, (0xBA000602 & 0xFFFF) # ori $t2, $t2, 0x602
  addiu $s0, $s0, 8
  move  $v1, $s0
  sw    $t8, ($v0)
  sw    $zero, 4($v0)
  addiu $s0, $s0, 8
  move  $a0, $s0
  sw    $zero, 4($v1)
  sw    $t9, ($v1)
  addiu $s0, $s0, 8
  li    $t3, 192
  sw    $t3, 4($a0)
  sw    $t2, ($a0)
  move  $a1, $s0
  lui   $t4, (0xBA001301 >> 16) # lui $t4, 0xba00
  ori   $t4, (0xBA001301 & 0xFFFF) # ori $t4, $t4, 0x1301
  addiu $s0, $s0, 8
  sw    $t4, ($a1)
  move  $a2, $s0
  lui   $t5, (0xB9000002 >> 16) # lui $t5, 0xb900
  sw    $zero, 4($a1)
  ori   $t5, (0xB9000002 & 0xFFFF) # ori $t5, $t5, 2
  addiu $s0, $s0, 8
  li    $at, 0x437F0000 # 255.000000
  mtc1  $at, $f6
  sw    $t5, ($a2)
  move  $v0, $s0
  lui   $t6, (0xBA001001 >> 16) # lui $t6, 0xba00
  sw    $zero, 4($a2)
  ori   $t6, (0xBA001001 & 0xFFFF) # ori $t6, $t6, 0x1001
  addiu $s0, $s0, 8
  sw    $t6, ($v0)
  move  $v1, $s0
  mul.s $f8, $f0, $f6
  sw    $zero, 4($v0)
  lui   $t7, (0xBA000C02 >> 16) # lui $t7, 0xba00
  ori   $t7, (0xBA000C02 & 0xFFFF) # ori $t7, $t7, 0xc02
  addiu $s0, $s0, 8
  li    $t8, 8192
  sw    $t8, 4($v1)
  sw    $t7, ($v1)
  move  $a0, $s0
  addiu $s0, $s0, 8
  li    $t2, 3072
  lui   $t9, (0xBA000903 >> 16) # lui $t9, 0xba00
  ori   $t9, (0xBA000903 & 0xFFFF) # ori $t9, $t9, 0x903
  sw    $t2, 4($a0)
  move  $a1, $s0
  lui   $t3, (0xBA000E02 >> 16) # lui $t3, 0xba00
  sw    $t9, ($a0)
  ori   $t3, (0xBA000E02 & 0xFFFF) # ori $t3, $t3, 0xe02
  addiu $s0, $s0, 8
  sw    $t3, ($a1)
  move  $a2, $s0
  lui   $t4, (0xB900031D >> 16) # lui $t4, 0xb900
  trunc.w.s $f10, $f8
  sw    $zero, 4($a1)
  ori   $t4, (0xB900031D & 0xFFFF) # ori $t4, $t4, 0x31d
  addiu $s0, $s0, 8
  lui   $t5, (0x00504340 >> 16) # lui $t5, 0x50
  ori   $t5, (0x00504340 & 0xFFFF) # ori $t5, $t5, 0x4340
  sw    $t4, ($a2)
  move  $v0, $s0
  sw    $t5, 4($a2)
  lui   $t7, (0xFFFDF6FB >> 16) # lui $t7, 0xfffd
  lui   $t6, (0xFCFFFFFF >> 16) # lui $t6, 0xfcff
  andi  $t3, $t0, 0xff
  ori   $t6, (0xFCFFFFFF & 0xFFFF) # ori $t6, $t6, 0xffff
  ori   $t7, (0xFFFDF6FB & 0xFFFF) # ori $t7, $t7, 0xf6fb
  sll   $t4, $t3, 0x10
  mfc1  $t3, $f10
  sw    $t7, 4($v0)
  sw    $t6, ($v0)
  addiu $s0, $s0, 8
  sll   $t2, $a3, 0x18
  or    $t5, $t2, $t4
  move  $v1, $s0
  andi  $t6, $t1, 0xff
  lui   $t8, 0xfa00
  sw    $t8, ($v1)
  sll   $t7, $t6, 8
  or    $t8, $t5, $t7
  andi  $t2, $t3, 0xff
  or    $t4, $t8, $t2
  sw    $t4, 4($v1)
  addiu $s0, $s0, 8
  sw    $s0, 0x3c($sp)
  jal   get_video2_settings_width
   addiu $s0, $s0, 8
  jal   get_video2_settings_ulx
   sh    $v0, 0x26($sp)
  jal   get_video2_settings_uly
   sh    $v0, 0x28($sp)
  jal   get_video2_settings_height
   sh    $v0, 0x2a($sp)
  lh    $t6, 0x28($sp)
  lh    $t5, 0x26($sp)
  lh    $t8, 0x2a($sp)
  lui   $at, 0xf600
  addu  $t7, $t6, $t5
  addu  $t2, $v0, $t8
  andi  $t4, $t2, 0x3ff
  andi  $t9, $t7, 0x3ff
  sll   $t3, $t9, 0xe
  sll   $t6, $t4, 2
  lw    $t9, 0x3c($sp)
  or    $t5, $t6, $at
  or    $t7, $t5, $t3
  jal   get_video2_settings_ulx
   sw    $t7, ($t9)
  jal   get_video2_settings_uly
   sh    $v0, 0x2a($sp)
  lh    $t4, 0x2a($sp)
  lw    $t7, 0x3c($sp)
  andi  $t8, $v0, 0x3ff
  andi  $t6, $t4, 0x3ff
  sll   $t5, $t6, 0xe
  sll   $t2, $t8, 2
  or    $t3, $t2, $t5
  move  $v1, $s0
  sw    $t3, 4($t7)
  addiu $s0, $s0, 8
  lui   $t9, 0xe700
  move  $a0, $s0
  sw    $t9, ($v1)
  sw    $zero, 4($v1)
  addiu $s0, $s0, 8
  lui   $t8, (0xBA000602 >> 16) # lui $t8, 0xba00
  ori   $t8, (0xBA000602 & 0xFFFF) # ori $t8, $t8, 0x602
  li    $t4, 64
  move  $a1, $s0
  sw    $t4, 4($a0)
  sw    $t8, ($a0)
  addiu $s0, $s0, 8
  lui   $t6, (0xBA001301 >> 16) # lui $t6, 0xba00
  ori   $t6, (0xBA001301 & 0xFFFF) # ori $t6, $t6, 0x1301
  lui   $t2, 8
  move  $a2, $s0
  sw    $t2, 4($a1)
  sw    $t6, ($a1)
  lui   $t5, (0xBA001001 >> 16) # lui $t5, 0xba00
  ori   $t5, (0xBA001001 & 0xFFFF) # ori $t5, $t5, 0x1001
  lui   $t3, 1
  sw    $t3, 4($a2)
  sw    $t5, ($a2)
  addiu $s0, $s0, 8
.L7F08079C:
  lw    $ra, 0x1c($sp)
  move  $v0, $s0
  lw    $s0, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x80
");

void set_rgba_tint(int arg0, int arg1, int arg2, float arg3) {
  pPlayer->tint_red = arg0;
  pPlayer->tint_green = arg1;
  pPlayer->tint_blue = arg2;
  pPlayer->tint_alpha = arg3;
}

asm(R"
glabel sub_GAME_7F0807E0
  lui   $v1, %hi(pPlayer)
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $t6, ($v1)
  mtc1  $zero, $f4
  nop   
  swc1  $f4, 0x3e0($t6)
  lw    $t7, ($v1)
  swc1  $f12, 0x3e4($t7)
  lw    $v0, ($v1)
  lw    $t8, 0x3d0($v0)
  sw    $t8, 0x3e8($v0)
  lw    $t9, ($v1)
  sw    $a1, 0x3ec($t9)
  lw    $v0, ($v1)
  lw    $t0, 0x3d4($v0)
  sw    $t0, 0x3f0($v0)
  lw    $t1, ($v1)
  sw    $a2, 0x3f4($t1)
  lw    $v0, ($v1)
  lw    $t2, 0x3d8($v0)
  sw    $t2, 0x3f8($v0)
  lw    $t3, ($v1)
  sw    $a3, 0x3fc($t3)
  lw    $v0, ($v1)
  lwc1  $f6, 0x3dc($v0)
  swc1  $f6, 0x400($v0)
  lw    $t4, ($v1)
  lwc1  $f8, 0x10($sp)
  jr    $ra
   swc1  $f8, 0x404($t4)
");

asm(R"
glabel fade_to_over_seconds
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  lw    $a3, 0x3d8($v0)
  lw    $a2, 0x3d4($v0)
  lw    $a1, 0x3d0($v0)
  jal   sub_GAME_7F0807E0
   swc1  $f14, 0x10($sp)
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel check_if_fade_to_black_complete
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  mtc1  $zero, $f6
  move  $v0, $zero
  lwc1  $f4, 0x3e4($t6)
  c.lt.s $f4, $f6
  nop   
  bc1f  .L7F0808B4
   nop   
  li    $v0, 1
.L7F0808B4:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0808BC
  lui   $a2, %hi(pPlayer)
  addiu $a2, %lo(pPlayer) # addiu $a2, $a2, -0x5f50
  lw    $v0, ($a2)
  mtc1  $zero, $f6
  lui   $at, %hi(global_timer_delta)
  lwc1  $f4, 0x3e4($v0)
  c.le.s $f6, $f4
  nop   
  bc1f  .L7F080A08
   nop   
  lwc1  $f8, 0x3e0($v0)
  lwc1  $f10, %lo(global_timer_delta)($at)
  add.s $f16, $f8, $f10
  swc1  $f16, 0x3e0($v0)
  lw    $v0, ($a2)
  lwc1  $f2, 0x3e0($v0)
  lwc1  $f0, 0x3e4($v0)
  c.lt.s $f2, $f0
  nop   
  bc1fl .L7F0809D0
   lwc1  $f10, 0x404($v0)
  div.s $f12, $f2, $f0
  lwc1  $f14, 0x400($v0)
  lwc1  $f18, 0x404($v0)
  sub.s $f4, $f18, $f14
  mul.s $f6, $f4, $f12
  add.s $f8, $f14, $f6
  swc1  $f8, 0x3dc($v0)
  lw    $v0, ($a2)
  lw    $v1, 0x3e8($v0)
  lw    $t6, 0x3ec($v0)
  subu  $t7, $t6, $v1
  mtc1  $t7, $f10
  nop   
  cvt.s.w $f16, $f10
  mul.s $f18, $f16, $f12
  trunc.w.s $f4, $f18
  mfc1  $t9, $f4
  nop   
  addu  $t0, $v1, $t9
  sw    $t0, 0x3d0($v0)
  lw    $v0, ($a2)
  lw    $a0, 0x3f0($v0)
  lw    $t1, 0x3f4($v0)
  subu  $t2, $t1, $a0
  mtc1  $t2, $f6
  nop   
  cvt.s.w $f8, $f6
  mul.s $f10, $f8, $f12
  trunc.w.s $f16, $f10
  mfc1  $t4, $f16
  nop   
  addu  $t5, $a0, $t4
  sw    $t5, 0x3d4($v0)
  lw    $v0, ($a2)
  lw    $a1, 0x3f8($v0)
  lw    $t6, 0x3fc($v0)
  subu  $t7, $t6, $a1
  mtc1  $t7, $f18
  nop   
  cvt.s.w $f4, $f18
  mul.s $f6, $f4, $f12
  trunc.w.s $f8, $f6
  mfc1  $t9, $f8
  nop   
  addu  $t0, $a1, $t9
  jr    $ra
   sw    $t0, 0x3d8($v0)

  lwc1  $f10, 0x404($v0)
.L7F0809D0:
  li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f16
  swc1  $f10, 0x3dc($v0)
  lw    $v0, ($a2)
  lw    $t1, 0x3ec($v0)
  sw    $t1, 0x3d0($v0)
  lw    $v0, ($a2)
  lw    $t2, 0x3f4($v0)
  sw    $t2, 0x3d4($v0)
  lw    $v0, ($a2)
  lw    $t3, 0x3fc($v0)
  sw    $t3, 0x3d8($v0)
  lw    $t4, ($a2)
  swc1  $f16, 0x3e4($t4)
.L7F080A08:
  jr    $ra
   nop   
");

asm(R"
glabel set_curplayer_fade
  lui   $a0, %hi(pPlayer)
  addiu $a0, %lo(pPlayer) # addiu $a0, $a0, -0x5f50
  lw    $v1, ($a0)
  lw    $t6, 0xa8($v1)
  lw    $v0, 4($t6)
  beqz  $v0, .L7F080A78
   nop   
  mtc1  $zero, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  swc1  $f4, 0x18c($v1)
  lw    $t7, ($a0)
  swc1  $f12, 0x190($t7)
  lbu   $t8, 0xc($v0)
  mtc1  $t8, $f6
  bgez  $t8, .L7F080A5C
   cvt.s.w $f8, $f6
  mtc1  $at, $f10
  nop   
  add.s $f8, $f8, $f10
.L7F080A5C:
  li    $at, 0x437F0000 # 255.000000
  mtc1  $at, $f16
  lw    $t9, ($a0)
  div.s $f18, $f8, $f16
  swc1  $f18, 0x194($t9)
  lw    $t0, ($a0)
  swc1  $f14, 0x198($t0)
.L7F080A78:
  jr    $ra
   nop   
");

asm(R"
glabel update_curplayer_fade
  lui   $a0, %hi(pPlayer)
  addiu $a0, %lo(pPlayer) # addiu $a0, $a0, -0x5f50
  lw    $v0, ($a0)
  mtc1  $zero, $f6
  lui    $at, %hi(global_timer_delta)
  lwc1  $f4, 0x190($v0)
  c.le.s $f6, $f4
  nop   
  bc1f  .L7F080B2C
   nop   
  lwc1  $f8, 0x18c($v0)
  lwc1  $f10, %lo(global_timer_delta)($at)
  lw    $t6, 0xa8($v0)
  li    $at, 0xBF800000 # -1.000000
  add.s $f16, $f8, $f10
  lw    $v1, 4($t6)
  swc1  $f16, 0x18c($v0)
  lw    $v0, ($a0)
  lwc1  $f2, 0x18c($v0)
  lwc1  $f0, 0x190($v0)
  c.lt.s $f2, $f0
  nop   
  bc1fl .L7F080B00
   mtc1  $at, $f10
  lwc1  $f14, 0x194($v0)
  lwc1  $f18, 0x198($v0)
  sub.s $f4, $f18, $f14
  mul.s $f6, $f4, $f2
  div.s $f8, $f6, $f0
  b     .L7F080B08
   add.s $f12, $f14, $f8
  mtc1  $at, $f10
.L7F080B00:
  lwc1  $f12, 0x198($v0)
  swc1  $f10, 0x190($v0)
.L7F080B08:
  beqz  $v1, .L7F080B2C
   li    $at, 0x437F0000 # 255.000000
  mtc1  $at, $f16
  nop   
  mul.s $f18, $f12, $f16
  trunc.w.s $f4, $f18
  mfc1  $t8, $f4
  nop   
  sb    $t8, 0xc($v1)
.L7F080B2C:
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel firstperson_weapon_movement_restrictor
.word 0x3c8efa35 /*0.017453292*/
glabel D_800550D8
.word 0x3c8efa35 /*0.017453292*/

.text
glabel sub_GAME_7F080B34
  addiu $sp, $sp, -0xd0
  sw    $s0, 0x38($sp)
  lui   $s0, %hi(pPlayer)
  sdc1  $f20, 0x30($sp)
  mtc1  $zero, $f20
  addiu $s0, %lo(pPlayer) # addiu $s0, $s0, -0x5f50
  lw    $v0, ($s0)
  sw    $ra, 0x3c($sp)
  sw    $a2, 0xd8($sp)
  swc1  $f20, 0xcc($sp)
  lw    $t6, 0xd8($v0)
  bnezl $t6, .L7F080BB4
   lw    $t7, 0x420($v0)
  swc1  $f12, 0xd0($sp)
  jal   sub_GAME_7F08E8BC
   swc1  $f14, 0xd4($sp)
  lwc1  $f12, 0xd0($sp)
  lwc1  $f14, 0xd4($sp)
  c.eq.s $f12, $f20
  nop   
  bc1tl .L7F080B9C
   c.eq.s $f14, $f20
  div.s $f4, $f14, $f12
  b     .L7F080C34
   swc1  $f4, 0xcc($sp)
  c.eq.s $f14, $f20
.L7F080B9C:
  nop   
  bc1fl .L7F080C38
   lwc1  $f12, 0xcc($sp)
  b     .L7F080C38
   lwc1  $f12, 0xcc($sp)
  lw    $t7, 0x420($v0)
.L7F080BB4:
  beql  $t7, $zero, .L7F080C24
   lui   $at, 0x3f00
  jal   get_random_value
   nop   
  jal   get_random_value
   sw    $v0, 0x44($sp)
  lui   $t9, %hi(D_8003650C) 
  lw    $t9, %lo(D_8003650C)($t9)
  lw    $t8, 0x44($sp)
  lui   $t2, %hi(D_800364D8)
  lui   $t3, %hi(ptr_animation_table) 
  divu  $zero, $t8, $t9
  mfhi  $t0
  sll   $t1, $t0, 2
  addu  $t2, $t2, $t1
  lw    $t2, %lo(D_800364D8)($t2)
  lw    $t3, %lo(ptr_animation_table)($t3)
  mfc1  $a2, $f20
  bnez  $t9, .L7F080C08
   nop   
  break 7
.L7F080C08:
  andi  $a1, $v0, 1
  lui   $a3, 0x3f80
  jal   sub_GAME_7F08EA48
   addu  $a0, $t2, $t3
  lw    $t4, ($s0)
  sw    $zero, 0x420($t4)
  li    $at, 0x3F000000 # 0.500000
.L7F080C24:
  mtc1  $at, $f12
  jal   sub_GAME_7F08EAB8
   nop   
  swc1  $f20, 0xd8($sp)
.L7F080C34:
  lwc1  $f12, 0xcc($sp)
.L7F080C38:
  jal   sub_GAME_7F08E240
   lwc1  $f14, 0xd8($sp)
  lw    $t5, ($s0)
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f6
  lwc1  $f8, 0x15c($t5)
  lui   $at, %hi(firstperson_weapon_movement_restrictor)
  lwc1  $f16, %lo(firstperson_weapon_movement_restrictor)($at)
  sub.s $f10, $f6, $f8
  addiu $a1, $sp, 0x8c
  mul.s $f12, $f10, $f16
  jal   sub_GAME_7F058570
   nop   
  lw    $v0, ($s0)
  mfc1  $a1, $f20
  mfc1  $a2, $f20
  lwc1  $f18, 0x508($v0)
  mfc1  $a3, $f20
  addiu $a0, $sp, 0x4c
  neg.s $f4, $f18
  swc1  $f4, 0x10($sp)
  lwc1  $f6, 0x50c($v0)
  neg.s $f8, $f6
  swc1  $f8, 0x14($sp)
  lwc1  $f10, 0x510($v0)
  neg.s $f16, $f10
  swc1  $f16, 0x18($sp)
  lwc1  $f18, 0x514($v0)
  swc1  $f18, 0x1c($sp)
  lwc1  $f4, 0x518($v0)
  swc1  $f4, 0x20($sp)
  lwc1  $f6, 0x51c($v0)
  jal   sub_GAME_7F059908
   swc1  $f6, 0x24($sp)
  addiu $a0, $sp, 0x4c
  jal   matrix_4x4_multiply_in_place
   addiu $a1, $sp, 0x8c
  lw    $t6, ($s0)
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f8
  lwc1  $f10, 0x148($t6)
  lui   $at, %hi(D_800550D8)
  lwc1  $f18, %lo(D_800550D8)($at)
  sub.s $f16, $f8, $f10
  addiu $a1, $sp, 0x4c
  mul.s $f12, $f16, $f18
  jal   sub_GAME_7F0585FC
   nop   
  addiu $a0, $sp, 0x4c
  jal   matrix_4x4_multiply_in_place
   addiu $a1, $sp, 0x8c
  lwc1  $f4, 0xac($sp)
  lw    $t7, ($s0)
  swc1  $f4, 0x4c0($t7)
  lw    $t8, ($s0)
  lwc1  $f6, 0xb0($sp)
  swc1  $f6, 0x4c4($t8)
  lw    $t9, ($s0)
  lwc1  $f8, 0xb4($sp)
  swc1  $f8, 0x4c8($t9)
  lw    $t0, ($s0)
  lwc1  $f10, 0x9c($sp)
  swc1  $f10, 0x4cc($t0)
  lw    $t1, ($s0)
  lwc1  $f16, 0xa0($sp)
  swc1  $f16, 0x4d0($t1)
  lw    $t2, ($s0)
  lwc1  $f18, 0xa4($sp)
  swc1  $f18, 0x4d4($t2)
  lw    $ra, 0x3c($sp)
  lw    $s0, 0x38($sp)
  ldc1  $f20, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0xd0
");

asm(R"
glabel sub_GAME_7F080D60
  lui   $a3, %hi(ptr_playerstank)
  lw    $a3, %lo(ptr_playerstank)($a3)
  addiu $sp, $sp, -0x18
  mtc1  $a1, $f12
  mtc1  $a2, $f14
  beqz  $a3, .L7F080DA4
   sw    $ra, 0x14($sp)
  lw    $v1, 4($a3)
  lw    $v0, 0x10($v1)
  lw    $a0, 0x14($v0)
  lw    $a1, 8($v0)
  jal   sub_GAME_7F0B2970
   lw    $a2, 0x10($v0)
  lui   $at, %hi(D_80036454)
  lwc1  $f4, %lo(D_80036454)($at)
  b     .L7F080DE4
   add.s $f2, $f0, $f4
.L7F080DA4:
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lw    $t6, 0x2a6c($v0)
  beql  $t6, $zero, .L7F080DD4
   mfc1  $a1, $f12
  mfc1  $a1, $f12
  mfc1  $a2, $f14
  jal   sub_GAME_7F0B2970
   lw    $a0, 0x2a70($v0)
  b     .L7F080DE4
   mov.s $f2, $f0
  mfc1  $a1, $f12
.L7F080DD4:
  mfc1  $a2, $f14
  jal   sub_GAME_7F0B2970
   nop   
  mov.s $f2, $f0
.L7F080DE4:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  mov.s $f0, $f2
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_800550DC
.word 0x3e2e147c /*0.17000002*/
glabel D_800550E0
.word 0x3f547ae1 /*0.82999998*/
glabel D_800550E4
.word 0x3e2e147c /*0.17000002*/
glabel D_800550E8
.word 0x3f547ae1 /*0.82999998*/
glabel D_800550EC
.word 0x3fb1c71d /*1.388889*/
glabel player_gravity_modifier
.word 0x3e8e38e4 /*0.27777779*/
glabel player_view_gravity_modifier
.word 0x3e8e38e4 /*0.27777779*/
glabel D_800550F8
.word 0xc1555555 /*-13.333333*/
glabel D_800550FC
.word 0x41055555 /*8.333333*/
glabel D_80055100
.word 0x3f4ccccd /*0.80000001*/
glabel D_80055104
.word 0x3e4ccccc /*0.19999999*/

.text
glabel sub_GAME_7F080DF8
  lui   $t6, %hi(in_tank_flag) 
  lw    $t6, %lo(in_tank_flag)($t6)
  addiu $sp, $sp, -0x70
  mtc1  $a1, $f12
  li    $at, 1
  sw    $ra, 0x24($sp)
  bne   $t6, $at, .L7F080EC4
   sw    $s0, 0x20($sp)
  lui   $t0, %hi(pPlayer) 
  addiu $t0, %lo(pPlayer) # addiu $t0, $t0, -0x5f50
  lw    $s0, ($t0)
  lw    $a0, 0x488($s0)
  lw    $a1, 0x48c($s0)
  jal   sub_GAME_7F080D60
   lw    $a2, 0x494($s0)
  lui   $t0, %hi(pPlayer) 
  addiu $t0, %lo(pPlayer) # addiu $t0, $t0, -0x5f50
  lw    $t7, ($t0)
  lui   $at, %hi(D_800550DC)
  lwc1  $f2, %lo(D_800550DC)($at)
  swc1  $f0, 0x74($t7)
  lw    $s0, ($t0)
  lui   $a3, %hi(clock_timer)
  addiu $a3, %lo(clock_timer) # addiu $a3, $a3, -0x7c8c
  lwc1  $f4, 0x70($s0)
  lui   $at, %hi(D_800550E0)
  move  $v1, $zero
  div.s $f6, $f4, $f2
  swc1  $f6, 0x6c($s0)
  lw    $t8, ($a3)
  blezl $t8, .L7F080EB0
   lw    $s0, ($t0)
  lwc1  $f0, %lo(D_800550E0)($at)
  lw    $s0, ($t0)
.L7F080E80:
  addiu $v1, $v1, 1
  lwc1  $f8, 0x6c($s0)
  lwc1  $f4, 0x74($s0)
  mul.s $f10, $f8, $f0
  add.s $f6, $f10, $f4
  swc1  $f6, 0x6c($s0)
  lw    $t9, ($a3)
  slt   $at, $v1, $t9
  bnezl $at, .L7F080E80
   lw    $s0, ($t0)
  move  $v1, $zero
  lw    $s0, ($t0)
.L7F080EB0:
  mtc1  $zero, $f16
  lwc1  $f8, 0x6c($s0)
  mul.s $f10, $f8, $f2
  b     .L7F081398
   swc1  $f10, 0x70($s0)
.L7F080EC4:
  beqz  $a0, .L7F080F20
   lui   $t0, %hi(pPlayer) 
  addiu $t0, %lo(pPlayer) # addiu $t0, $t0, -0x5f50
  lw    $s0, ($t0)
  lwc1  $f4, 0x74($s0)
  add.s $f6, $f4, $f12
  swc1  $f6, 0x74($s0)
  lw    $s0, ($t0)
  lw    $a0, 0x488($s0)
  lw    $a1, 0x48c($s0)
  jal   sub_GAME_7F080D60
   lw    $a2, 0x494($s0)
  lui   $t0, %hi(pPlayer) 
  addiu $t0, %lo(pPlayer) # addiu $t0, $t0, -0x5f50
  lw    $s0, ($t0)
  lwc1  $f8, 0x74($s0)
  c.lt.s $f8, $f0
  nop   
  bc1fl .L7F080FE0
   lw    $t4, 0x2a6c($s0)
  swc1  $f0, 0x74($s0)
  b     .L7F080FDC
   lw    $s0, ($t0)
.L7F080F20:
  lui   $t0, %hi(pPlayer) 
  addiu $t0, %lo(pPlayer) # addiu $t0, $t0, -0x5f50
  lw    $s0, ($t0)
  addiu $a1, $sp, 0x5c
  addiu $a2, $sp, 0x58
  lw    $t1, 0x488($s0)
  addiu $a3, $sp, 0x54
  sw    $t1, 0x60($sp)
  jal   sub_GAME_7F08A274
   lw    $a0, 0xa8($s0)
  lui   $t0, %hi(pPlayer) 
  addiu $t0, %lo(pPlayer) # addiu $t0, $t0, -0x5f50
  lw    $s0, ($t0)
  lw    $a0, 0x488($s0)
  lw    $a1, 0x48c($s0)
  jal   sub_GAME_7F080D60
   lw    $a2, 0x494($s0)
  lui   $t0, %hi(pPlayer) 
  addiu $t0, %lo(pPlayer) # addiu $t0, $t0, -0x5f50
  lw    $a0, ($t0)
  jal   sub_GAME_7F089780
   swc1  $f0, 0x64($sp)
  lui   $t0, %hi(pPlayer) 
  lwc1  $f2, 0x64($sp)
  addiu $t0, %lo(pPlayer) # addiu $t0, $t0, -0x5f50
  lw    $s0, ($t0)
  add.s $f10, $f0, $f2
  addiu $a0, $sp, 0x60
  lw    $a1, 0x48c($s0)
  lw    $a2, 0x494($s0)
  swc1  $f10, 0x10($sp)
  jal   sub_GAME_7F0B26B8
   lw    $a3, 0x5c($sp)
  lui   $t0, %hi(pPlayer) 
  addiu $t0, %lo(pPlayer) # addiu $t0, $t0, -0x5f50
  bltz  $v0, .L7F080FD0
   lwc1  $f2, 0x64($sp)
  lw    $t2, ($t0)
  lwc1  $f0, 0x74($t2)
  c.lt.s $f2, $f0
  nop   
  bc1fl .L7F080FD4
   lw    $t3, ($t0)
  mov.s $f2, $f0
.L7F080FD0:
  lw    $t3, ($t0)
.L7F080FD4:
  swc1  $f2, 0x74($t3)
  lw    $s0, ($t0)
.L7F080FDC:
  lw    $t4, 0x2a6c($s0)
.L7F080FE0:
  mtc1  $zero, $f16
  beql  $t4, $zero, .L7F081024
   lwc1  $f8, 0x7c($s0)
  lwc1  $f4, 0x70($s0)
  lwc1  $f6, 0x74($s0)
  c.lt.s $f4, $f6
  nop   
  bc1fl .L7F081024
   lwc1  $f8, 0x7c($s0)
  sw    $zero, 0x2a6c($s0)
  lw    $s0, ($t0)
  lw    $t5, 0x2a70($s0)
  sw    $t5, 0x488($s0)
  lw    $t6, ($t0)
  sw    $zero, 0x2a70($t6)
  lw    $s0, ($t0)
  lwc1  $f8, 0x7c($s0)
.L7F081024:
  lwc1  $f12, 0x70($s0)
  c.le.s $f16, $f8
  nop   
  bc1t  .L7F081048
   nop   
  lwc1  $f0, 0x74($s0)
  c.lt.s $f12, $f0
  nop   
  bc1f  .L7F0810D8
.L7F081048:
   lui   $at, %hi(D_800550E4)
  lwc1  $f2, %lo(D_800550E4)($at)
  lui   $a3, %hi(clock_timer)
  addiu $a3, %lo(clock_timer) # addiu $a3, $a3, -0x7c8c
  div.s $f10, $f12, $f2
  lui   $at, %hi(D_800550E8)
  move  $v1, $zero
  swc1  $f10, 0x6c($s0)
  lw    $t7, ($a3)
  blezl $t7, .L7F0810A8
   lw    $s0, ($t0)
  lwc1  $f0, %lo(D_800550E8)($at)
  lw    $s0, ($t0)
.L7F08107C:
  addiu $v1, $v1, 1
  lwc1  $f4, 0x6c($s0)
  lwc1  $f8, 0x74($s0)
  mul.s $f6, $f4, $f0
  add.s $f10, $f6, $f8
  swc1  $f10, 0x6c($s0)
  lw    $t8, ($a3)
  slt   $at, $v1, $t8
  bnezl $at, .L7F08107C
   lw    $s0, ($t0)
  lw    $s0, ($t0)
.L7F0810A8:
  lwc1  $f12, 0x70($s0)
  lwc1  $f0, 0x74($s0)
  c.lt.s $f12, $f0
  nop   
  bc1fl .L7F0810DC
   c.lt.s $f0, $f12
  lwc1  $f4, 0x6c($s0)
  mul.s $f6, $f4, $f2
  swc1  $f6, 0x70($s0)
  lw    $s0, ($t0)
  lwc1  $f12, 0x70($s0)
  lwc1  $f0, 0x74($s0)
.L7F0810D8:
  c.lt.s $f0, $f12
.L7F0810DC:
  lui   $a3, %hi(clock_timer)
  addiu $a3, %lo(clock_timer) # addiu $a3, $a3, -0x7c8c
  move  $v1, $zero
  bc1f  .L7F081260
   lwc1  $f2, 0x7c($s0)
  sw    $zero, 0x6c($sp)
  swc1  $f2, 0x48($sp)
  jal   get_debug_fast_bond_flag
   swc1  $f12, 0x4c($sp)
  lui   $a3, %hi(clock_timer)
  lui   $t0, %hi(pPlayer) 
  mtc1  $zero, $f16
  addiu $t0, %lo(pPlayer) # addiu $t0, $t0, -0x5f50
  addiu $a3, %lo(clock_timer) # addiu $a3, $a3, -0x7c8c
  lw    $v1, 0x6c($sp)
  lwc1  $f14, 0x48($sp)
  beqz  $v0, .L7F081164
   lwc1  $f18, 0x4c($sp)
  lui   $v0, %hi(flt_CODE_bss_80079990)
  addiu $v0, %lo(flt_CODE_bss_80079990) # addiu $v0, $v0, -0x6670
  lwc1  $f8, ($v0)
  c.eq.s $f16, $f8
  nop   
  bc1f  .L7F081164
   nop   
  lwc1  $f10, 8($v0)
  lui   $at, %hi(D_800550EC)
  c.eq.s $f16, $f10
  nop   
  bc1f  .L7F081164
   nop   
  lwc1  $f4, %lo(D_800550EC)($at)
  b     .L7F081170
   swc1  $f4, 0x40($sp)
.L7F081164:
  lui   $at, %hi(player_gravity_modifier)
  lwc1  $f6, %lo(player_gravity_modifier)($at)
  swc1  $f6, 0x40($sp)
.L7F081170:
  lui   $at, %hi(global_timer_delta)
  lwc1  $f12, %lo(global_timer_delta)($at)
  lwc1  $f8, 0x40($sp)
  li    $at, 0x3F000000 # 0.500000
  lw    $s0, ($t0)
  mul.s $f10, $f12, $f8
  mtc1  $at, $f8
  lwc1  $f0, 0x74($s0)
  sub.s $f2, $f14, $f10
  add.s $f4, $f14, $f2
  mov.s $f14, $f2
  mul.s $f6, $f12, $f4
  nop   
  mul.s $f10, $f6, $f8
  add.s $f18, $f18, $f10
  c.lt.s $f18, $f0
  nop   
  bc1f  .L7F08124C
   nop   
  lwc1  $f4, 0x70($s0)
  lui    $at, %hi(player_view_gravity_modifier)
  lwc1  $f8, %lo(player_view_gravity_modifier)($at)
  sub.s $f14, $f4, $f0
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f4
  lwc1  $f2, 0x7c($s0)
  add.s $f6, $f14, $f14
  swc1  $f0, 0x4c($sp)
  sw    $v1, 0x6c($sp)
  mul.s $f10, $f6, $f8
  mtc1  $at, $f8
  div.s $f6, $f10, $f4
  mul.s $f10, $f6, $f8
  nop   
  mul.s $f4, $f2, $f2
  jal   sqrtf
   add.s $f12, $f4, $f10
  lui   $t0, %hi(pPlayer) 
  addiu $t0, %lo(pPlayer) # addiu $t0, $t0, -0x5f50
  lw    $s0, ($t0)
  lui   $a3, %hi(clock_timer)
  mtc1  $zero, $f16
  lw    $t9, 0x2a6c($s0)
  addiu $a3, %lo(clock_timer) # addiu $a3, $a3, -0x7c8c
  lw    $v1, 0x6c($sp)
  lwc1  $f18, 0x4c($sp)
  beqz  $t9, .L7F08124C
   neg.s $f14, $f0
  sw    $zero, 0x2a6c($s0)
  lw    $s0, ($t0)
  lw    $t1, 0x2a70($s0)
  sw    $t1, 0x488($s0)
  lw    $t2, ($t0)
  sw    $zero, 0x2a70($t2)
  lw    $s0, ($t0)
.L7F08124C:
  swc1  $f18, 0x70($s0)
  lw    $t3, ($t0)
  swc1  $f14, 0x7c($t3)
  lw    $s0, ($t0)
  lwc1  $f2, 0x7c($s0)
.L7F081260:
  c.lt.s $f2, $f16
  nop   
  bc1fl .L7F081318
   lw    $t7, 0x2a6c($s0)
  lwc1  $f6, 0x74($s0)
  lwc1  $f8, 0x70($s0)
  lui    $at, %hi(D_800550F8)
  c.le.s $f8, $f6
  nop   
  bc1fl .L7F081318
   lw    $t7, 0x2a6c($s0)
  lwc1  $f4, %lo(D_800550F8)($at)
  li    $t4, 15
  li    $at, 0xC0A00000 # -5.000000
  c.lt.s $f2, $f4
  nop   
  bc1fl .L7F0812C8
   mtc1  $at, $f0
  sw    $t4, 0x8c($s0)
  li    $at, 0xC2B40000 # -90.000000
  mtc1  $at, $f10
  lw    $t5, ($t0)
  swc1  $f10, 0x90($t5)
  b     .L7F08130C
   lw    $s0, ($t0)
  mtc1  $at, $f0
.L7F0812C8:
  li    $t6, 15
  c.lt.s $f2, $f0
  nop   
  bc1fl .L7F081310
   swc1  $f16, 0x7c($s0)
  sw    $t6, 0x8c($s0)
  lw    $s0, ($t0)
  li    $at, 0xC2B40000 # -90.000000
  mtc1  $at, $f4
  lwc1  $f6, 0x7c($s0)
  lui   $at, %hi(D_800550FC)
  sub.s $f8, $f0, $f6
  lwc1  $f6, %lo(D_800550FC)($at)
  mul.s $f10, $f8, $f4
  div.s $f8, $f10, $f6
  swc1  $f8, 0x90($s0)
  lw    $s0, ($t0)
.L7F08130C:
  swc1  $f16, 0x7c($s0)
.L7F081310:
  lw    $s0, ($t0)
  lw    $t7, 0x2a6c($s0)
.L7F081318:
  beqz  $t7, .L7F081398
   move  $a0, $s0
  jal   sub_GAME_7F089780
   sw    $v1, 0x6c($sp)
  lui   $t0, %hi(pPlayer) 
  addiu $t0, %lo(pPlayer) # addiu $t0, $t0, -0x5f50
  lw    $s0, ($t0)
  swc1  $f0, 0x3c($sp)
  lw    $a2, 0x494($s0)
  lw    $a1, 0x48c($s0)
  jal   sub_GAME_7F0B2970
   lw    $a0, 0x488($s0)
  lui   $t0, %hi(pPlayer) 
  addiu $t0, %lo(pPlayer) # addiu $t0, $t0, -0x5f50
  lw    $s0, ($t0)
  lwc1  $f10, 0x3c($sp)
  lui   $a3, %hi(clock_timer)
  lwc1  $f4, 0x70($s0)
  mtc1  $zero, $f16
  addiu $a3, %lo(clock_timer) # addiu $a3, $a3, -0x7c8c
  add.s $f6, $f4, $f10
  lw    $v1, 0x6c($sp)
  c.lt.s $f6, $f0
  nop   
  bc1fl .L7F08139C
   lw    $t1, ($a3)
  sw    $zero, 0x2a6c($s0)
  lw    $s0, ($t0)
  lw    $t8, 0x2a70($s0)
  sw    $t8, 0x488($s0)
  lw    $t9, ($t0)
  sw    $zero, 0x2a70($t9)
.L7F081398:
  lw    $t1, ($a3)
.L7F08139C:
  blez  $t1, .L7F08144C
   li    $at, 0xC0900000 # -4.500000
  mtc1  $at, $f12
  lui   $at, %hi(D_80055100)
  lwc1  $f2, %lo(D_80055100)($at)
  lw    $s0, ($t0)
.L7F0813B4:
  lw    $t2, 0x8c($s0)
  blezl $t2, .L7F0813EC
   lwc1  $f0, 0x90($s0)
  lwc1  $f8, 0x84($s0)
  lwc1  $f10, 0x90($s0)
  mul.s $f4, $f8, $f2
  add.s $f6, $f4, $f10
  swc1  $f6, 0x84($s0)
  lw    $s0, ($t0)
  lw    $t3, 0x8c($s0)
  addiu $t4, $t3, -1
  b     .L7F081438
   sw    $t4, 0x8c($s0)
  lwc1  $f0, 0x90($s0)
.L7F0813EC:
  c.lt.s $f0, $f16
  nop   
  bc1fl .L7F08142C
   lwc1  $f4, 0x84($s0)
  sub.s $f8, $f0, $f12
  swc1  $f8, 0x90($s0)
  lw    $s0, ($t0)
  lwc1  $f0, 0x90($s0)
  c.le.s $f16, $f0
  nop   
  bc1fl .L7F08142C
   lwc1  $f4, 0x84($s0)
  swc1  $f16, 0x90($s0)
  lw    $s0, ($t0)
  lwc1  $f0, 0x90($s0)
  lwc1  $f4, 0x84($s0)
.L7F08142C:
  mul.s $f10, $f4, $f2
  add.s $f6, $f10, $f0
  swc1  $f6, 0x84($s0)
.L7F081438:
  lw    $t5, ($a3)
  addiu $v1, $v1, 1
  slt   $at, $v1, $t5
  bnezl $at, .L7F0813B4
   lw    $s0, ($t0)
.L7F08144C:
  lw    $s0, ($t0)
  lui   $at, %hi(D_80055104)
  lwc1  $f4, %lo(D_80055104)($at)
  lwc1  $f8, 0x84($s0)
  mul.s $f10, $f8, $f4
  swc1  $f10, 0x88($s0)
  lw    $ra, 0x24($sp)
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0x70
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80055108
.word 0x3f666666 /*0.89999998*/
glabel D_8005510C
.word 0x3dccccd0 /*0.10000002*/

.text
glabel sub_GAME_7F081478
  lui   $v1, %hi(pPlayersPerm)
  lui   $t0, %hi(pPlayer) 
  addiu $t0, %lo(pPlayer) # addiu $t0, $t0, -0x5f50
  addiu $v1, %lo(pPlayersPerm) # addiu $v1, $v1, -0x5f4c
  lw    $t6, ($v1)
  lw    $v0, ($t0)
  addiu $sp, $sp, -0x38
  sw    $ra, 0x1c($sp)
  lwc1  $f6, 0x64($t6)
  lwc1  $f4, 0x500($v0)
  li    $at, 0x41F00000 # 30.000000
  mtc1  $at, $f2
  mul.s $f8, $f4, $f6
  li    $at, 0x40E00000 # 7.000000
  mtc1  $at, $f10
  addiu $a0, $sp, 0x2c
  add.s $f16, $f8, $f10
  swc1  $f16, 0x29bc($v0)
  lw    $v0, ($t0)
  lw    $t7, ($v1)
  lwc1  $f18, 0x88($v0)
  lwc1  $f4, 0xa0($v0)
  lwc1  $f8, 0x64($t7)
  lwc1  $f16, 0x29bc($v0)
  add.s $f6, $f18, $f4
  mul.s $f10, $f6, $f8
  add.s $f0, $f16, $f10
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F0814FC
   lwc1  $f18, 0x70($v0)
  mov.s $f0, $f2
  lwc1  $f18, 0x70($v0)
.L7F0814FC:
  lui   $v1, %hi(cameramode)
  li    $at, 5
  add.s $f4, $f18, $f0
  swc1  $f4, 0x490($v0)
  lw    $v1, %lo(cameramode)($v1)
  beq   $v1, $at, .L7F081528
   li    $at, 6
  beq   $v1, $at, .L7F081528
   li    $at, 7
  bnel  $v1, $at, .L7F08153C
   lw    $v0, ($t0)
.L7F081528:
  lw    $v0, ($t0)
  lw    $t8, 0xd4($v0)
  bnezl $t8, .L7F081564
   lw    $t9, 0xd8($v0)
  lw    $v0, ($t0)
.L7F08153C:
  lwc1  $f6, 0x48c($v0)
  swc1  $f6, 0x4b4($v0)
  lw    $v0, ($t0)
  lwc1  $f8, 0x490($v0)
  swc1  $f8, 0x4b8($v0)
  lw    $v0, ($t0)
  lwc1  $f16, 0x494($v0)
  swc1  $f16, 0x4bc($v0)
  lw    $v0, ($t0)
  lw    $t9, 0xd8($v0)
.L7F081564:
  lui   $v1, %hi(stanlinelog_flag)
  addiu $v1, %lo(stanlinelog_flag) # addiu $v1, $v1, 0xfb4
  beql  $t9, $zero, .L7F0815C4
   mtc1  $zero, $f2
  mtc1  $zero, $f2
  lwc1  $f0, 0x29c0($v0)
  li    $at, 0x3E800000 # 0.250000
  c.lt.s $f2, $f0
  nop   
  bc1fl .L7F0815C4
   mtc1  $zero, $f2
  mtc1  $at, $f10
  nop   
  sub.s $f18, $f0, $f10
  swc1  $f18, 0x29c0($v0)
  lw    $v0, ($t0)
  lwc1  $f4, 0x29c0($v0)
  c.lt.s $f4, $f2
  nop   
  bc1fl .L7F0815C4
   mtc1  $zero, $f2
  swc1  $f2, 0x29c0($v0)
  lw    $v0, ($t0)
  mtc1  $zero, $f2
.L7F0815C4:
  lwc1  $f6, 0x158($v0)
  li    $at, 0x3F800000 # 1.000000
  c.lt.s $f6, $f2
  nop   
  bc1fl .L7F081608
   lw    $t1, 0x488($v0)
  mtc1  $at, $f8
  lwc1  $f16, 0x164($v0)
  lwc1  $f4, 0x29c0($v0)
  sub.s $f10, $f8, $f16
  lwc1  $f8, 0x4b8($v0)
  neg.s $f18, $f10
  mul.s $f6, $f18, $f4
  add.s $f16, $f8, $f6
  swc1  $f16, 0x4b8($v0)
  lw    $v0, ($t0)
  lw    $t1, 0x488($v0)
.L7F081608:
  lw    $t2, ($v1)
  sw    $zero, ($v1)
  sw    $t1, 0x2c($sp)
  sw    $t2, 0x28($sp)
  lwc1  $f10, 0x4bc($v0)
  lw    $a3, 0x4b4($v0)
  lw    $a2, 0x494($v0)
  lw    $a1, 0x48c($v0)
  jal   sub_GAME_7F0B0BE4
   swc1  $f10, 0x10($sp)
  lw    $t3, 0x28($sp)
  lui   $t0, %hi(pPlayer) 
  lui   $at, %hi(stanlinelog_flag)
  addiu $t0, %lo(pPlayer) # addiu $t0, $t0, -0x5f50
  sw    $t3, %lo(stanlinelog_flag)($at)
  lw    $t5, ($t0)
  lw    $t4, 0x2c($sp)
  sw    $t4, 0x4d8($t5)
  lw    $v0, ($t0)
  lwc1  $f18, 0x4b4($v0)
  swc1  $f18, 0x4a4($v0)
  lw    $v0, ($t0)
  lwc1  $f4, 0x4bc($v0)
  swc1  $f4, 0x4ac($v0)
  lw    $v0, ($t0)
  lw    $a0, 0x4d8($v0)
  lw    $a1, 0x4b4($v0)
  jal   sub_GAME_7F080D60
   lw    $a2, 0x4bc($v0)
  lui   $t0, %hi(pPlayer) 
  addiu $t0, %lo(pPlayer) # addiu $t0, $t0, -0x5f50
  lw    $t6, ($t0)
  lui   $a0, %hi(clock_timer)
  addiu $a0, %lo(clock_timer) # addiu $a0, $a0, -0x7c8c
  swc1  $f0, 0x4a8($t6)
  lw    $v0, ($t0)
  move  $v1, $zero
  lui   $at, %hi(D_80055108)
  lw    $t7, 0x488($v0)
  lw    $t8, 0xa8($v0)
  sw    $t7, 0x14($t8)
  lw    $v0, ($t0)
  lwc1  $f8, 0x48c($v0)
  lw    $t9, 0xa8($v0)
  swc1  $f8, 8($t9)
  lw    $v0, ($t0)
  lwc1  $f6, 0x490($v0)
  lw    $t1, 0xa8($v0)
  swc1  $f6, 0xc($t1)
  lw    $v0, ($t0)
  lwc1  $f16, 0x494($v0)
  lw    $t2, 0xa8($v0)
  swc1  $f16, 0x10($t2)
  lw    $t3, ($a0)
  blezl $t3, .L7F08174C
   lw    $v0, ($t0)
  lwc1  $f0, %lo(D_80055108)($at)
  lw    $v0, ($t0)
.L7F0816F0:
  addiu $v1, $v1, 1
  lwc1  $f18, 0x3b8($v0)
  lwc1  $f10, 0x4b4($v0)
  mul.s $f4, $f0, $f18
  add.s $f8, $f10, $f4
  swc1  $f8, 0x3b8($v0)
  lw    $v0, ($t0)
  lwc1  $f16, 0x3bc($v0)
  lwc1  $f6, 0x4b8($v0)
  mul.s $f18, $f0, $f16
  add.s $f10, $f6, $f18
  swc1  $f10, 0x3bc($v0)
  lw    $v0, ($t0)
  lwc1  $f8, 0x3c0($v0)
  lwc1  $f4, 0x4bc($v0)
  mul.s $f16, $f0, $f8
  add.s $f6, $f4, $f16
  swc1  $f6, 0x3c0($v0)
  lw    $t4, ($a0)
  slt   $at, $v1, $t4
  bnezl $at, .L7F0816F0
   lw    $v0, ($t0)
  lw    $v0, ($t0)
.L7F08174C:
  lui   $at, %hi(D_8005510C)
  lwc1  $f0, %lo(D_8005510C)($at)
  lwc1  $f18, 0x3b8($v0)
  mul.s $f10, $f18, $f0
  swc1  $f10, 0x3c4($v0)
  lw    $v0, ($t0)
  lwc1  $f8, 0x3bc($v0)
  mul.s $f4, $f8, $f0
  swc1  $f4, 0x3c8($v0)
  lw    $v0, ($t0)
  lwc1  $f16, 0x3c0($v0)
  mul.s $f6, $f16, $f0
  swc1  $f6, 0x3cc($v0)
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80055110
.word 0x3c8efa35 /*0.017453292*/
glabel D_80055114
.word 0x3c8efa35 /*0.017453292*/
glabel D_80055118
.word 0x3c8efa35 /*0.017453292*/
glabel D_8005511C
.word 0x3c8efa35 /*0.017453292*/

.text
glabel sub_GAME_7F081790
  addiu $sp, $sp, -0x20
  sw    $s0, 0x18($sp)
  lui   $s0, %hi(pPlayer)
  addiu $s0, %lo(pPlayer) # addiu $s0, $s0, -0x5f50
  lw    $v0, ($s0)
  sw    $ra, 0x1c($sp)
  li    $at, 0xC3340000 # -180.000000
  mtc1  $at, $f2
  lwc1  $f0, 0x158($v0)
  li    $at, 0x43B40000 # 360.000000
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F0817F4
   li    $at, 0x43340000 # 180.000000
  mtc1  $at, $f14
  nop   
  add.s $f4, $f0, $f14
.L7F0817D4:
  swc1  $f4, 0x158($v0)
  lw    $v0, ($s0)
  lwc1  $f0, 0x158($v0)
  c.lt.s $f0, $f2
  nop   
  bc1tl .L7F0817D4
   add.s $f4, $f0, $f14
  li    $at, 0x43340000 # 180.000000
.L7F0817F4:
  mtc1  $at, $f2
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f14
  c.le.s $f2, $f0
  li    $at, 0x42B40000 # 90.000000
  bc1fl .L7F081834
   mtc1  $at, $f2
  sub.s $f6, $f0, $f14
.L7F081814:
  swc1  $f6, 0x158($v0)
  lw    $v0, ($s0)
  lwc1  $f0, 0x158($v0)
  c.le.s $f2, $f0
  nop   
  bc1tl .L7F081814
   sub.s $f6, $f0, $f14
  mtc1  $at, $f2
.L7F081834:
  li    $at, 0xC2B40000 # -90.000000
  c.lt.s $f2, $f0
  nop   
  bc1fl .L7F081858
   mtc1  $at, $f2
  swc1  $f2, 0x158($v0)
  b     .L7F081874
   lw    $v0, ($s0)
  mtc1  $at, $f2
.L7F081858:
  nop   
  c.lt.s $f0, $f2
  nop   
  bc1f  .L7F081874
   nop   
  swc1  $f2, 0x158($v0)
  lw    $v0, ($s0)
.L7F081874:
  lui   $at, %hi(D_80055110)
  lwc1  $f10, %lo(D_80055110)($at)
  lwc1  $f8, 0x148($v0)
  mul.s $f12, $f8, $f10
  jal   cosf
   nop   
  lw    $t6, ($s0)
  lui   $at, %hi(D_80055114)
  swc1  $f0, 0x150($t6)
  lw    $t7, ($s0)
  lwc1  $f18, %lo(D_80055114)($at)
  lwc1  $f16, 0x148($t7)
  mul.s $f12, $f16, $f18
  jal   sinf
   nop   
  lw    $t8, ($s0)
  mtc1  $zero, $f6
  li    $at, 0x43B40000 # 360.000000
  swc1  $f0, 0x154($t8)
  lw    $v0, ($s0)
  mtc1  $at, $f14
  lui   $at, %hi(D_80055118)
  lwc1  $f4, 0x158($v0)
  swc1  $f4, 0x15c($v0)
  lw    $v0, ($s0)
  lwc1  $f2, 0x15c($v0)
  c.lt.s $f2, $f6
  nop   
  bc1f  .L7F0818FC
   nop   
  add.s $f8, $f2, $f14
  swc1  $f8, 0x15c($v0)
  lw    $t9, ($s0)
  lwc1  $f2, 0x15c($t9)
.L7F0818FC:
  lwc1  $f10, %lo(D_80055118)($at)
  mul.s $f12, $f2, $f10
  jal   cosf
   nop   
  lw    $t0, ($s0)
  lui   $at, %hi(D_8005511C)
  swc1  $f0, 0x164($t0)
  lw    $t1, ($s0)
  lwc1  $f18, %lo(D_8005511C)($at)
  lwc1  $f16, 0x15c($t1)
  mul.s $f12, $f16, $f18
  jal   sinf
   nop   
  lw    $t2, ($s0)
  mtc1  $zero, $f8
  swc1  $f0, 0x168($t2)
  lw    $v0, ($s0)
  lwc1  $f4, 0x154($v0)
  neg.s $f6, $f4
  swc1  $f6, 0x498($v0)
  lw    $t3, ($s0)
  swc1  $f8, 0x49c($t3)
  lw    $v0, ($s0)
  lwc1  $f10, 0x150($v0)
  swc1  $f10, 0x4a0($v0)
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80055120
.word 0x3d75c290 /*0.060000002*/
glabel D_80055124
.word 0x3da3d708 /*0.079999983*/
glabel D_80055128
.word 0x3c8efa35 /*0.017453292*/
glabel D_8005512C
.word 0x3c8efa35 /*0.017453292*/
glabel D_80055130
.word 0x3c8efa35 /*0.017453292*/
glabel D_80055134
.word 0x3f8a3d71 /*1.08*/
glabel D_80055138
.word 0x3c23d70a /*0.0099999998*/
glabel D_8005513C
.word 0x3c23d70a /*0.0099999998*/
glabel D_80055140
.word 0x40c90fdb /*6.2831855*/
glabel D_80055144
.word 0x3f5dddde /*0.86666667*/
glabel D_80055148
.word 0x3d4ccccd /*0.050000001*/
glabel D_8005514C
.word 0x3e99999a /*0.30000001*/
glabel D_80055150
.word 0x3e99999a /*0.30000001*/
glabel D_80055154
.word 0x3e99999a /*0.30000001*/
glabel D_80055158
.word 0x3f6b851f /*0.92000002*/
glabel D_8005515C
.word 0x3da3d708 /*0.079999983*/
glabel D_80055160
.word 0x3e99999a /*0.30000001*/
glabel D_80055164
.word 0x3dcccccd /*0.1*/
glabel D_80055168
.word 0x3f266666 /*0.64999998*/

.text
glabel controller_gameplay_interaction
  addiu $sp, $sp, -0x1c0
  sdc1  $f20, 0x30($sp)
  mtc1  $zero, $f20
  sw    $ra, 0x3c($sp)
  sw    $s0, 0x38($sp)
  sw    $a0, 0x1c0($sp)
  sw    $a1, 0x1c4($sp)
  sw    $a2, 0x1c8($sp)
  sw    $a3, 0x1cc($sp)
  sw    $zero, 0x1bc($sp)
  sw    $zero, 0x1b8($sp)
  sw    $zero, 0x1b4($sp)
  sw    $zero, 0x1b0($sp)
  sw    $zero, 0x1ac($sp)
  sw    $zero, 0x1a8($sp)
  sw    $zero, 0x1a4($sp)
  sw    $zero, 0x1a0($sp)
  sw    $zero, 0x19c($sp)
  sw    $zero, 0x198($sp)
  sw    $zero, 0x194($sp)
  sw    $zero, 0x190($sp)
  sw    $zero, 0x174($sp)
  sw    $zero, 0x170($sp)
  sw    $zero, 0x16c($sp)
  sw    $zero, 0x168($sp)
  sw    $zero, 0x15c($sp)
  sw    $zero, 0x158($sp)
  sw    $zero, 0x154($sp)
  sw    $zero, 0x150($sp)
  sw    $zero, 0x14c($sp)
  sw    $zero, 0x148($sp)
  swc1  $f20, 0x18c($sp)
  swc1  $f20, 0x188($sp)
  swc1  $f20, 0x184($sp)
  swc1  $f20, 0x180($sp)
  swc1  $f20, 0x17c($sp)
  swc1  $f20, 0x178($sp)
  swc1  $f20, 0x164($sp)
  jal   get_cur_player_look_vertical_inverted
   swc1  $f20, 0x160($sp)
  lb    $a0, 0x1c3($sp)
  sltiu $t6, $v0, 1
  sw    $t6, 0x144($sp)
  slti  $at, $a0, -5
  beqz  $at, .L7F081A34
   sw    $zero, 0x140($sp)
  b     .L7F081A48
   addiu $v1, $a0, 5
.L7F081A34:
  slti  $at, $a0, 6
  bnez  $at, .L7F081A48
   move  $v1, $zero
  b     .L7F081A48
   addiu $v1, $a0, -5
.L7F081A48:
  lb    $a1, 0x1c7($sp)
  lui   $s0, %hi(pPlayer)
  addiu $s0, %lo(pPlayer) # addiu $s0, $s0, -0x5f50
  slti  $at, $a1, -5
  beqz  $at, .L7F081A68
   lb    $t7, 0x1c3($sp)
  b     .L7F081A7C
   addiu $v0, $a1, 5
.L7F081A68:
  slti  $at, $a1, 6
  bnez  $at, .L7F081A7C
   move  $v0, $zero
  b     .L7F081A7C
   addiu $v0, $a1, -5
.L7F081A7C:
  lb    $t8, 0x1c7($sp)
  lw    $t0, ($s0)
  sw    $t7, 0x134($sp)
  sw    $v1, 0x12c($sp)
  sw    $v0, 0x128($sp)
  sw    $v1, 0x124($sp)
  sw    $v0, 0x120($sp)
  sw    $t8, 0x130($sp)
  lw    $t9, 0xd8($t0)
  bnez  $t9, .L7F081B10
   lui   $t2, %hi(camera_80036424) 
  lw    $t2, %lo(camera_80036424)($t2)
  bgtzl $t2, .L7F081B14
   lw    $t0, ($s0)
  lw    $v0, 0x1c8($t0)
  li    $at, 5
  lhu   $t4, 0x1ce($sp)
  beql  $v0, $at, .L7F081AE0
   li    $at, 5
  lhu   $t3, 0x1ca($sp)
  not   $t5, $t4
  and   $t6, $t3, $t5
  andi  $t7, $t6, 0x1000
  bnez  $t7, .L7F081AF4
   li    $at, 5
.L7F081AE0:
  bnel  $v0, $at, .L7F081B14
   lw    $t0, ($s0)
  lw    $t8, 0x1d0($t0)
  beql  $t8, $zero, .L7F081B14
   lw    $t0, ($s0)
.L7F081AF4:
  jal   getPlayerCount
   nop   
  li    $at, 1
  bnel  $v0, $at, .L7F081B14
   lw    $t0, ($s0)
  jal   trigger_solo_watch_menu
   move  $a0, $zero
.L7F081B10:
  lw    $t0, ($s0)
.L7F081B14:
  lw    $t9, 0x1c8($t0)
  bnezl $t9, .L7F0829CC
   lw    $t2, ($s0)
  lw    $t2, 0xd8($t0)
  bnezl $t2, .L7F0829CC
   lw    $t2, ($s0)
  jal   getPlayerCount
   nop   
  li    $at, 1
  beq   $v0, $at, .L7F081B5C
   lui   $t4, %hi(stop_play_flag) 
  lw    $t4, %lo(stop_play_flag)($t4)
  lui   $t3, %hi(is_gameover_flag) 
  bnezl $t4, .L7F0829CC
   lw    $t2, ($s0)
  lw    $t3, %lo(is_gameover_flag)($t3)
  bnezl $t3, .L7F0829CC
   lw    $t2, ($s0)
.L7F081B5C:
  lhu   $t5, 0x1ca($sp)
  jal   cur_player_get_control_type
   sw    $t5, 0x5c($sp)
  li    $at, 6
  beql  $v0, $at, .L7F081BB4
   lhu   $t7, 0x1ce($sp)
  jal   cur_player_get_control_type
   nop   
  li    $at, 7
  beql  $v0, $at, .L7F081BB4
   lhu   $t7, 0x1ce($sp)
  jal   cur_player_get_control_type
   nop   
  li    $at, 5
  beql  $v0, $at, .L7F081BB4
   lhu   $t7, 0x1ce($sp)
  jal   cur_player_get_control_type
   nop   
  li    $at, 4
  bne   $v0, $at, .L7F0822B8
   nop   
  lhu   $t7, 0x1ce($sp)
.L7F081BB4:
  lw    $t6, 0x5c($sp)
  not   $t8, $t7
  and   $t9, $t6, $t8
  jal   get_cur_playernum
   sw    $t9, 0x60($sp)
  jal   getPlayerCount
   sw    $v0, 0x64($sp)
  lw    $t2, 0x64($sp)
  addu  $a0, $v0, $t2
  sll   $t4, $a0, 0x18
  jal   get_cur_controller_horz_stick_pos
   sra   $a0, $t4, 0x18
  jal   get_cur_playernum
   sb    $v0, 0x11f($sp)
  jal   getPlayerCount
   sw    $v0, 0x64($sp)
  lw    $t5, 0x64($sp)
  addu  $a0, $v0, $t5
  sll   $t7, $a0, 0x18
  jal   get_cur_controller_vert_stick_pos
   sra   $a0, $t7, 0x18
  jal   get_cur_playernum
   sb    $v0, 0x11e($sp)
  jal   getPlayerCount
   sw    $v0, 0x64($sp)
  lw    $t8, 0x64($sp)
  li    $a1, 65535
  addu  $a0, $v0, $t8
  sll   $t9, $a0, 0x18
  jal   get_controller_buttons_held
   sra   $a0, $t9, 0x18
  lw    $t3, ($s0)
  lb    $t4, 0x11f($sp)
  sh    $v0, 0x11c($sp)
  lhu   $t5, 0x3b6($t3)
  slti  $at, $t4, -5
  move  $v1, $t4
  beqz  $at, .L7F081C58
   sh    $t5, 0x11a($sp)
  b     .L7F081C70
   addiu $v1, $t4, 5
.L7F081C58:
  slti  $at, $v1, 6
  bnez  $at, .L7F081C70
   move  $v1, $zero
  lb    $v1, 0x11f($sp)
  b     .L7F081C70
   addiu $v1, $v1, -5
.L7F081C70:
  lb    $v0, 0x11e($sp)
  slti  $at, $v0, -5
  beqz  $at, .L7F081C88
   addiu $t7, $v0, 5
  b     .L7F081CA0
   sw    $t7, 0x110($sp)
.L7F081C88:
  slti  $at, $v0, 6
  bnez  $at, .L7F081C9C
   addiu $t6, $v0, -5
  b     .L7F081CA0
   sw    $t6, 0x110($sp)
.L7F081C9C:
  sw    $zero, 0x110($sp)
.L7F081CA0:
  jal   cur_player_get_control_type
   sw    $v1, 0x114($sp)
  li    $at, 4
  beq   $v0, $at, .L7F081CC8
   lw    $v1, 0x114($sp)
  jal   cur_player_get_control_type
   sw    $v1, 0x114($sp)
  li    $at, 6
  bne   $v0, $at, .L7F081CD8
   lw    $v1, 0x114($sp)
.L7F081CC8:
  lw    $t8, 0x110($sp)
  sw    $v1, 0x124($sp)
  b     .L7F081D10
   sw    $t8, 0x128($sp)
.L7F081CD8:
  lui   $t9, %hi(in_tank_flag) 
  lw    $t9, %lo(in_tank_flag)($t9)
  li    $at, 1
  bnel  $t9, $at, .L7F081D08
   sw    $v1, 0x124($sp)
  lw    $t2, ($s0)
  lw    $t3, 0x124($t2)
  bnezl $t3, .L7F081D08
   sw    $v1, 0x124($sp)
  b     .L7F081D08
   sw    $v1, 0x12c($sp)
  sw    $v1, 0x124($sp)
.L7F081D08:
  lw    $t5, 0x110($sp)
  sw    $t5, 0x120($sp)
.L7F081D10:
  jal   cur_player_get_control_type
   nop   
  li    $at, 4
  beql  $v0, $at, .L7F081D3C
   lhu   $v0, 0x11c($sp)
  jal   cur_player_get_control_type
   nop   
  li    $at, 5
  bne   $v0, $at, .L7F081D8C
   lw    $t9, 0x5c($sp)
  lhu   $v0, 0x11c($sp)
.L7F081D3C:
  lhu   $t6, 0x11a($sp)
  lw    $t3, 0x5c($sp)
  andi  $t4, $v0, 0x2000
  sltu  $t7, $zero, $t4
  sw    $t7, 0x104($sp)
  lw    $t7, 0x60($sp)
  not   $t8, $t6
  and   $v1, $v0, $t8
  andi  $t9, $v1, 0x2000
  andi  $t5, $t3, 0x2000
  andi  $t6, $t7, 0x2000
  sltu  $t2, $zero, $t9
  sltu  $t4, $zero, $t5
  sltu  $t8, $zero, $t6
  sw    $t2, 0x100($sp)
  sw    $t4, 0x10c($sp)
  sw    $t8, 0x108($sp)
  sw    $v1, 0x50($sp)
  b     .L7F081DD8
   sw    $v0, 0x58($sp)
.L7F081D8C:
  andi  $t2, $t9, 0x2000
  lhu   $t9, 0x11a($sp)
  lw    $t5, 0x60($sp)
  lhu   $v0, 0x11c($sp)
  sltu  $t3, $zero, $t2
  not   $t2, $t9
  sw    $t3, 0x104($sp)
  andi  $t4, $t5, 0x2000
  and   $v1, $v0, $t2
  andi  $t3, $v1, 0x2000
  andi  $t6, $v0, 0x2000
  sltu  $t7, $zero, $t4
  sltu  $t8, $zero, $t6
  sltu  $t5, $zero, $t3
  sw    $t7, 0x100($sp)
  sw    $t8, 0x10c($sp)
  sw    $t5, 0x108($sp)
  sw    $v1, 0x50($sp)
  sw    $v0, 0x58($sp)
.L7F081DD8:
  jal   get_controls_locked_flag
   nop   
  bnezl $v0, .L7F082260
   lw    $v0, 0x10c($sp)
  jal   sub_GAME_7F0C24BC
   nop   
  beql  $v0, $zero, .L7F082260
   lw    $v0, 0x10c($sp)
  jal   cur_player_get_aim_control
   nop   
  bnezl $v0, .L7F081E1C
   lw    $t6, 0x100($sp)
  lw    $t4, 0x104($sp)
  lw    $t7, ($s0)
  b     .L7F081E34
   sw    $t4, 0x124($t7)
  lw    $t6, 0x100($sp)
.L7F081E1C:
  beql  $t6, $zero, .L7F081E38
   lw    $t9, ($s0)
  lw    $t0, ($s0)
  lw    $a1, 0x124($t0)
  sltiu $t8, $a1, 1
  sw    $t8, 0x124($t0)
.L7F081E34:
  lw    $t9, ($s0)
.L7F081E38:
  lw    $a0, 0x60($sp)
  li    $t7, 1
  lw    $v1, 0x124($t9)
  andi  $t2, $a0, 0x4000
  sltu  $t3, $zero, $t2
  sltiu $v0, $v1, 1
  sw    $v0, 0x1bc($sp)
  sw    $v0, 0x148($sp)
  move  $a1, $t3
  sw    $t3, 0x48($sp)
  bnez  $t3, .L7F081E78
   sw    $v1, 0x1b8($sp)
  lw    $a1, 0x50($sp)
  sw    $t3, 0x48($sp)
  andi  $t5, $a1, 0x4000
  sltu  $a1, $zero, $t5
.L7F081E78:
  sw    $a1, 0x1b0($sp)
  sw    $v0, 0x1ac($sp)
  sw    $t7, 0x1a8($sp)
  sw    $v0, 0x1a4($sp)
  beqz  $v1, .L7F081ED4
   sw    $v0, 0x1a0($sp)
  lb    $a0, 0x1c7($sp)
  slti  $at, $a0, 0x3d
  bnez  $at, .L7F081ED4
   addiu $t6, $a0, -0x3c
  mtc1  $t6, $f4
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f2
  cvt.s.w $f6, $f4
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f12
  div.s $f0, $f6, $f2
  c.lt.s $f12, $f0
  swc1  $f0, 0x184($sp)
  bc1f  .L7F081EE8
   nop   
  b     .L7F081EE8
   swc1  $f12, 0x184($sp)
.L7F081ED4:
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f12
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f2
  lb    $a0, 0x1c7($sp)
.L7F081EE8:
  beqz  $v1, .L7F081F20
   slti  $at, $a0, -0x3c
  beqz  $at, .L7F081F20
   li    $t8, -60
  subu  $t9, $t8, $a0
  mtc1  $t9, $f8
  nop   
  cvt.s.w $f10, $f8
  div.s $f0, $f10, $f2
  c.lt.s $f12, $f0
  swc1  $f0, 0x180($sp)
  bc1f  .L7F081F20
   nop   
  swc1  $f12, 0x180($sp)
.L7F081F20:
  beqz  $v1, .L7F081F64
   move  $a0, $zero
  lb    $v0, 0x1c3($sp)
  li    $t2, -60
  slti  $at, $v0, -0x3c
  beqz  $at, .L7F081F64
   subu  $t3, $t2, $v0
  mtc1  $t3, $f18
  nop   
  cvt.s.w $f4, $f18
  div.s $f0, $f4, $f2
  c.lt.s $f12, $f0
  swc1  $f0, 0x17c($sp)
  bc1f  .L7F081F68
   nop   
  b     .L7F081F68
   swc1  $f12, 0x17c($sp)
.L7F081F64:
  lb    $v0, 0x1c3($sp)
.L7F081F68:
  beqz  $v1, .L7F081F9C
   slti  $at, $v0, 0x3d
  bnez  $at, .L7F081F9C
   addiu $t5, $v0, -0x3c
  mtc1  $t5, $f6
  nop   
  cvt.s.w $f8, $f6
  div.s $f0, $f8, $f2
  c.lt.s $f12, $f0
  swc1  $f0, 0x178($sp)
  bc1fl .L7F081FA0
   lw    $t4, 0x5c($sp)
  swc1  $f12, 0x178($sp)
.L7F081F9C:
  lw    $t4, 0x5c($sp)
.L7F081FA0:
  andi  $t7, $t4, 0x8000
  sltu  $t6, $zero, $t7
  bnez  $t6, .L7F081FC4
   sw    $t6, 0x4c($sp)
  lw    $v0, 0x58($sp)
  andi  $t8, $v0, 0x8000
  sltu  $a1, $zero, $t8
  beql  $a1, $zero, .L7F081FD4
   lw    $t3, 0x60($sp)
.L7F081FC4:
  lw    $a1, 0x108($sp)
  sltu  $t2, $zero, $a1
  move  $a1, $t2
  lw    $t3, 0x60($sp)
.L7F081FD4:
  sw    $a1, 0x174($sp)
  andi  $t5, $t3, 0x8000
  sltu  $t4, $zero, $t5
  bnez  $t4, .L7F081FFC
   sw    $t4, 0x44($sp)
  lw    $v0, 0x50($sp)
  andi  $t7, $v0, 0x8000
  sltu  $a1, $zero, $t7
  beql  $a1, $zero, .L7F08200C
   sw    $a1, 0x170($sp)
.L7F081FFC:
  lw    $a1, 0x10c($sp)
  sltiu $t8, $a1, 1
  move  $a1, $t8
  sw    $a1, 0x170($sp)
.L7F08200C:
  sw    $v1, 0x16c($sp)
  jal   get_item_in_hand
   sw    $v1, 0x168($sp)
  move  $a0, $v0
  jal   check_special_attributes
   li    $a1, 32768
  beqz  $v0, .L7F0820C8
   nop   
  lw    $t9, ($s0)
  lw    $v0, 0x110($sp)
  lw    $t2, 0x124($t9)
  beqz  $t2, .L7F0820C8
   nop   
  bgez  $v0, .L7F082084
   negu  $t3, $v0
  mtc1  $t3, $f10
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f2
  cvt.s.w $f18, $f10
  li    $at, 0x428C0000 # 70.000000
  mtc1  $at, $f4
  nop   
  div.s $f12, $f18, $f4
  c.lt.s $f2, $f12
  nop   
  bc1fl .L7F082080
   add.s $f12, $f12, $f12
  mov.s $f12, $f2
  add.s $f12, $f12, $f12
.L7F082080:
  swc1  $f12, 0x164($sp)
.L7F082084:
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f2
  blez  $v0, .L7F0820C8
   lwc1  $f12, 0x164($sp)
  mtc1  $v0, $f6
  li    $at, 0x428C0000 # 70.000000
  mtc1  $at, $f10
  cvt.s.w $f8, $f6
  div.s $f14, $f8, $f10
  c.lt.s $f2, $f14
  nop   
  bc1fl .L7F0820C0
   add.s $f14, $f14, $f14
  mov.s $f14, $f2
  add.s $f14, $f14, $f14
.L7F0820C0:
  swc1  $f12, 0x164($sp)
  swc1  $f14, 0x160($sp)
.L7F0820C8:
  jal   get_item_in_hand
   move  $a0, $zero
  move  $a0, $v0
  jal   check_special_attributes
   li    $a1, 32768
  sltiu $a1, $v0, 1
  beqz  $a1, .L7F082108
   move  $a0, $zero
  lw    $t5, ($s0)
  lw    $a1, 0x124($t5)
  sltu  $t4, $zero, $a1
  beqz  $t4, .L7F082108
   move  $a1, $t4
  lb    $a1, 0x11e($sp)
  slti  $t7, $a1, -0x1e
  move  $a1, $t7
.L7F082108:
  jal   get_item_in_hand
   sw    $a1, 0x15c($sp)
  move  $a0, $v0
  jal   check_special_attributes
   li    $a1, 32768
  sltiu $a1, $v0, 1
  beql  $a1, $zero, .L7F08214C
   lw    $t2, 0x4c($sp)
  lw    $t6, ($s0)
  lw    $a1, 0x124($t6)
  sltu  $t8, $zero, $a1
  beqz  $t8, .L7F082148
   move  $a1, $t8
  lb    $a1, 0x11e($sp)
  slti  $t9, $a1, 0x1f
  xori  $a1, $t9, 1
.L7F082148:
  lw    $t2, 0x4c($sp)
.L7F08214C:
  sw    $a1, 0x158($sp)
  lw    $t3, 0x48($sp)
  beqz  $t2, .L7F082160
   lw    $t5, 0x5c($sp)
  bnez  $t3, .L7F0821A8
.L7F082160:
   andi  $t4, $t5, 0x4000
  beqz  $t4, .L7F082174
   lw    $t7, 0x44($sp)
  bnez  $t7, .L7F0821A8
   nop   
.L7F082174:
  lw    $t6, 0x58($sp)
  lw    $t9, 0x50($sp)
  lw    $t3, 0x58($sp)
  andi  $t8, $t6, 0x8000
  beqz  $t8, .L7F082190
   andi  $t2, $t9, 0x4000
  bnez  $t2, .L7F0821A8
.L7F082190:
   andi  $t5, $t3, 0x4000
  beqz  $t5, .L7F0821CC
   lw    $t4, 0x50($sp)
  andi  $t7, $t4, 0x8000
  beqz  $t7, .L7F0821CC
   nop   
.L7F0821A8:
  jal   get_item_in_hand
   move  $a0, $zero
  li    $at, 29
  bne   $v0, $at, .L7F0821CC
   li    $t6, 1
  sw    $t6, 0x14c($sp)
  sw    $zero, 0x174($sp)
  sw    $zero, 0x170($sp)
  sw    $zero, 0x1b0($sp)
.L7F0821CC:
  lui   $t8, %hi(in_tank_flag) 
  lw    $t8, %lo(in_tank_flag)($t8)
  li    $at, 1
  bnel  $t8, $at, .L7F082260
   lw    $v0, 0x10c($sp)
  lw    $t9, ($s0)
  lw    $t2, 0x124($t9)
  beql  $t2, $zero, .L7F082260
   lw    $v0, 0x10c($sp)
  jal   get_item_in_hand
   move  $a0, $zero
  li    $at, 32
  bne   $v0, $at, .L7F082220
   lw    $t4, 0x124($sp)
  lw    $t3, 0x124($sp)
  sw    $zero, 0x134($sp)
  lw    $t5, 0x12c($sp)
  bnezl $t3, .L7F082258
   swc1  $f20, 0x17c($sp)
  b     .L7F082254
   sw    $t5, 0x124($sp)
.L7F082220:
  bnez  $t4, .L7F082254
   lwc1  $f18, 0x17c($sp)
  c.lt.s $f20, $f18
  nop   
  bc1fl .L7F082240
   lwc1  $f4, 0x178($sp)
  swc1  $f18, 0x18c($sp)
  lwc1  $f4, 0x178($sp)
.L7F082240:
  c.lt.s $f20, $f4
  nop   
  bc1fl .L7F082258
   swc1  $f20, 0x17c($sp)
  swc1  $f4, 0x188($sp)
.L7F082254:
  swc1  $f20, 0x17c($sp)
.L7F082258:
  swc1  $f20, 0x178($sp)
  lw    $v0, 0x10c($sp)
.L7F082260:
  lw    $t0, ($s0)
  li    $t5, 1
  sltu  $a1, $zero, $v0
  beql  $a1, $zero, .L7F0822A8
   lhu   $t4, 0x11c($sp)
  lw    $a1, 0x1c8($t0)
  lw    $v0, 0x5c($sp)
  sltiu $t6, $a1, 1
  beqz  $t6, .L7F0822A4
   move  $a1, $t6
  andi  $t8, $v0, 0x8000
  sltiu $a1, $t8, 1
  beql  $a1, $zero, .L7F0822A8
   lhu   $t4, 0x11c($sp)
  lw    $a1, 0x58($sp)
  andi  $t2, $a1, 0x8000
  sltiu $a1, $t2, 1
.L7F0822A4:
  lhu   $t4, 0x11c($sp)
.L7F0822A8:
  sw    $a1, 0x1b4($sp)
  sw    $t5, 0x140($sp)
  b     .L7F0829C8
   sh    $t4, 0x3b6($t0)
.L7F0822B8:
  jal   cur_player_get_control_type
   nop   
  li    $at, 2
  beql  $v0, $at, .L7F0822E4
   li    $t7, 32768
  jal   cur_player_get_control_type
   nop   
  li    $at, 3
  bne   $v0, $at, .L7F0822F8
   li    $t8, 8192
  li    $t7, 32768
.L7F0822E4:
  li    $t6, 48
  sh    $t7, 0xfe($sp)
  li    $v1, 8192
  b     .L7F082308
   sh    $t6, 0xfa($sp)
.L7F0822F8:
  li    $t9, 32768
  sh    $t8, 0xfe($sp)
  li    $v1, 48
  sh    $t9, 0xfa($sp)
.L7F082308:
  jal   get_controls_locked_flag
   sh    $v1, 0xfc($sp)
  bnez  $v0, .L7F082960
   lhu   $v1, 0xfc($sp)
  jal   sub_GAME_7F0C24BC
   sh    $v1, 0xfc($sp)
  beqz  $v0, .L7F082960
   lhu   $v1, 0xfc($sp)
  lhu   $t3, 0x1ce($sp)
  lw    $t2, 0x5c($sp)
  sh    $v1, 0xfc($sp)
  not   $t5, $t3
  and   $t4, $t2, $t5
  jal   cur_player_get_aim_control
   sw    $t4, 0x60($sp)
  bnez  $v0, .L7F082364
   lhu   $v1, 0xfc($sp)
  lw    $t7, 0x5c($sp)
  lw    $t9, ($s0)
  and   $t6, $t7, $v1
  sltu  $t8, $zero, $t6
  b     .L7F082384
   sw    $t8, 0x124($t9)
.L7F082364:
  lw    $t3, 0x60($sp)
  and   $t2, $t3, $v1
  beql  $t2, $zero, .L7F082388
   lw    $t4, ($s0)
  lw    $t0, ($s0)
  lw    $a1, 0x124($t0)
  sltiu $t5, $a1, 1
  sw    $t5, 0x124($t0)
.L7F082384:
  lw    $t4, ($s0)
.L7F082388:
  lw    $v0, 0x60($sp)
  lw    $v1, 0x124($t4)
  andi  $t7, $v0, 0x4000
  sltu  $t6, $zero, $t7
  sltiu $a1, $v1, 1
  sw    $a1, 0x1bc($sp)
  sw    $a1, 0x148($sp)
  sw    $t6, 0x1b0($sp)
  sw    $t6, 0x48($sp)
  jal   cur_player_get_control_type
   sw    $v1, 0x1b8($sp)
  li    $at, 1
  beql  $v0, $at, .L7F0823D8
   lw    $v0, 0x5c($sp)
  jal   cur_player_get_control_type
   nop   
  li    $at, 3
  bne   $v0, $at, .L7F0824E0
   lw    $a2, 0x5c($sp)
  lw    $v0, 0x5c($sp)
.L7F0823D8:
  lui   $a0, %hi(in_tank_flag)
  andi  $a2, $v0, 0x202
  sltu  $t8, $zero, $a2
  beqz  $t8, .L7F082438
   move  $a2, $t8
  lw    $t9, ($s0)
  lui   $t2, %hi(in_tank_flag) 
  li    $at, 0x3F800000 # 1.000000
  lw    $t3, 0x124($t9)
  bnezl $t3, .L7F082430
   mtc1  $at, $f8
  lw    $t2, %lo(in_tank_flag)($t2)
  li    $at, 1
  li    $t5, 1
  bne   $t2, $at, .L7F082424
   li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  b     .L7F082438
   swc1  $f6, 0x17c($sp)
.L7F082424:
  b     .L7F082438
   sw    $t5, 0x194($sp)
  mtc1  $at, $f8
.L7F082430:
  nop   
  swc1  $f8, 0x18c($sp)
.L7F082438:
  andi  $t4, $v0, 0x101
  lw    $t6, ($s0)
  sltu  $t7, $zero, $t4
  sw    $t7, 0x44($sp)
  lw    $a0, %lo(in_tank_flag)($a0)
  beqz  $t7, .L7F08248C
   lw    $v1, 0x124($t6)
  bnez  $v1, .L7F082480
   li    $at, 0x3F800000 # 1.000000
  li    $at, 1
  bne   $a0, $at, .L7F082478
   li    $t8, 1
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  b     .L7F08248C
   swc1  $f10, 0x178($sp)
.L7F082478:
  b     .L7F08248C
   sw    $t8, 0x190($sp)
.L7F082480:
  mtc1  $at, $f18
  nop   
  swc1  $f18, 0x188($sp)
.L7F08248C:
  sltiu $v0, $v1, 1
  beqz  $v0, .L7F0824A4
   move  $a1, $v0
  lw    $a1, 0x5c($sp)
  andi  $t9, $a1, 0x808
  sltu  $a1, $zero, $t9
.L7F0824A4:
  sw    $a1, 0x19c($sp)
  beqz  $v0, .L7F0824BC
   move  $a1, $v0
  lw    $a1, 0x5c($sp)
  andi  $t2, $a1, 0x404
  sltu  $a1, $zero, $t2
.L7F0824BC:
  sw    $a1, 0x198($sp)
  li    $at, 1
  move  $a1, $v0
  bne   $a0, $at, .L7F0824D8
   sw    $v0, 0x1a0($sp)
  b     .L7F0825A4
   sw    $v0, 0x1a8($sp)
.L7F0824D8:
  b     .L7F0825A4
   sw    $a1, 0x1a4($sp)
.L7F0824E0:
  andi  $t4, $a2, 0x202
  sltu  $a2, $zero, $t4
  beqz  $a2, .L7F0824FC
   li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  nop   
  swc1  $f4, 0x18c($sp)
.L7F0824FC:
  lw    $a0, 0x5c($sp)
  li    $at, 0x3F800000 # 1.000000
  andi  $t7, $a0, 0x101
  sltu  $a0, $zero, $t7
  beql  $a0, $zero, .L7F082524
   lw    $t9, ($s0)
  mtc1  $at, $f6
  nop   
  swc1  $f6, 0x188($sp)
  lw    $t9, ($s0)
.L7F082524:
  lw    $v1, 0x124($t9)
  sltiu $v0, $v1, 1
  beqz  $v0, .L7F082538
   move  $a1, $v0
  move  $a1, $a2
.L7F082538:
  sw    $a1, 0x194($sp)
  move  $a1, $v0
  beqz  $v0, .L7F082550
   sw    $a0, 0x44($sp)
  move  $a1, $a0
  sw    $a0, 0x44($sp)
.L7F082550:
  sw    $a1, 0x190($sp)
  move  $a1, $v0
  bnez  $v1, .L7F082580
   sw    $v0, 0x1ac($sp)
  lw    $t3, 0x5c($sp)
  li    $at, 0x3F800000 # 1.000000
  andi  $t2, $t3, 0x808
  beqz  $t2, .L7F082580
   nop   
  mtc1  $at, $f8
  nop   
  swc1  $f8, 0x184($sp)
.L7F082580:
  bnez  $v1, .L7F0825A0
   lw    $t5, 0x5c($sp)
  andi  $t4, $t5, 0x404
  beqz  $t4, .L7F0825A0
   li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  nop   
  swc1  $f10, 0x180($sp)
.L7F0825A0:
  sw    $a1, 0x1a4($sp)
.L7F0825A4:
  beqz  $v1, .L7F0825F8
   nop   
  lb    $t6, 0x1c7($sp)
  slti  $at, $t6, 0x3d
  bnez  $at, .L7F0825F8
   addiu $t7, $t6, -0x3c
  mtc1  $t7, $f18
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f2
  cvt.s.w $f4, $f18
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  lui   $at, 0x3f80
  div.s $f0, $f4, $f2
  c.lt.s $f6, $f0
  swc1  $f0, 0x184($sp)
  bc1fl .L7F082650
   li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f8
  b     .L7F08264C
   swc1  $f8, 0x184($sp)
.L7F0825F8:
  beqz  $v1, .L7F08264C
   lb    $t8, 0x1c7($sp)
  slti  $at, $t8, -0x3c
  beqz  $at, .L7F08264C
   li    $t9, -60
  subu  $t3, $t9, $t8
  mtc1  $t3, $f10
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f2
  cvt.s.w $f18, $f10
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  lui   $at, 0x3f80
  div.s $f0, $f18, $f2
  c.lt.s $f4, $f0
  swc1  $f0, 0x180($sp)
  bc1fl .L7F082650
   li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f6
  nop   
  swc1  $f6, 0x180($sp)
.L7F08264C:
  li    $at, 0x41200000 # 10.000000
.L7F082650:
  mtc1  $at, $f2
  beqz  $v1, .L7F0826A4
   nop   
  lb    $v0, 0x1c3($sp)
  li    $t2, -60
  slti  $at, $v0, -0x3c
  beqz  $at, .L7F0826A4
   subu  $t5, $t2, $v0
  mtc1  $t5, $f8
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f18
  cvt.s.w $f10, $f8
  li    $at, 0x3F800000 # 1.000000
  div.s $f0, $f10, $f2
  c.lt.s $f18, $f0
  swc1  $f0, 0x17c($sp)
  bc1f  .L7F0826A4
   nop   
  mtc1  $at, $f4
  nop   
  swc1  $f4, 0x17c($sp)
.L7F0826A4:
  beqz  $v1, .L7F0826EC
   lb    $v0, 0x1c3($sp)
  slti  $at, $v0, 0x3d
  bnez  $at, .L7F0826EC
   addiu $t4, $v0, -0x3c
  mtc1  $t4, $f6
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  cvt.s.w $f8, $f6
  li    $at, 0x3F800000 # 1.000000
  div.s $f0, $f8, $f2
  c.lt.s $f10, $f0
  swc1  $f0, 0x178($sp)
  bc1fl .L7F0826F0
   lhu   $v0, 0xfa($sp)
  mtc1  $at, $f18
  nop   
  swc1  $f18, 0x178($sp)
.L7F0826EC:
  lhu   $v0, 0xfa($sp)
.L7F0826F0:
  lw    $t6, 0x5c($sp)
  and   $a0, $t6, $v0
  sltu  $a1, $zero, $a0
  beqz  $a1, .L7F082718
   sw    $a1, 0x4c($sp)
  lw    $t9, 0x60($sp)
  lhu   $t8, 0xfe($sp)
  and   $a1, $t9, $t8
  sltu  $t3, $zero, $a1
  move  $a1, $t3
.L7F082718:
  lw    $t2, 0x60($sp)
  sw    $a1, 0x174($sp)
  and   $a0, $t2, $v0
  sltu  $a1, $zero, $a0
  beqz  $a1, .L7F082744
   sw    $a1, 0x40($sp)
  lw    $t4, 0x5c($sp)
  lhu   $t6, 0xfe($sp)
  and   $a1, $t4, $t6
  sltiu $t7, $a1, 1
  move  $a1, $t7
.L7F082744:
  sw    $a1, 0x170($sp)
  sw    $v1, 0x16c($sp)
  sw    $v1, 0x168($sp)
  move  $a0, $zero
  jal   get_item_in_hand
   sw    $a2, 0x50($sp)
  move  $a0, $v0
  jal   check_special_attributes
   li    $a1, 32768
  beqz  $v0, .L7F0827B8
   lw    $a2, 0x50($sp)
  lw    $t9, ($s0)
  lw    $t3, 0x5c($sp)
  lw    $t8, 0x124($t9)
  andi  $v0, $t3, 0x808
  sltu  $t2, $zero, $v0
  beqz  $t8, .L7F0827B8
   andi  $t5, $t3, 0x404
  beqz  $t5, .L7F0827A4
   move  $v0, $t2
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  nop   
  swc1  $f4, 0x164($sp)
.L7F0827A4:
  beqz  $v0, .L7F0827B8
   li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  nop   
  swc1  $f6, 0x160($sp)
.L7F0827B8:
  move  $a0, $zero
  jal   get_item_in_hand
   sw    $a2, 0x50($sp)
  move  $a0, $v0
  jal   check_special_attributes
   li    $a1, 32768
  sltiu $a1, $v0, 1
  beqz  $a1, .L7F0827FC
   lw    $a2, 0x50($sp)
  lw    $t4, ($s0)
  lw    $a1, 0x124($t4)
  sltu  $t6, $zero, $a1
  beqz  $t6, .L7F0827FC
   move  $a1, $t6
  lw    $a1, 0x5c($sp)
  andi  $t7, $a1, 0x404
  sltu  $a1, $zero, $t7
.L7F0827FC:
  sw    $a1, 0x15c($sp)
  move  $a0, $zero
  jal   get_item_in_hand
   sw    $a2, 0x50($sp)
  move  $a0, $v0
  jal   check_special_attributes
   li    $a1, 32768
  sltiu $a1, $v0, 1
  beqz  $a1, .L7F082848
   lw    $a2, 0x50($sp)
  lw    $t8, ($s0)
  lw    $a1, 0x124($t8)
  sltu  $t2, $zero, $a1
  beqz  $t2, .L7F082848
   move  $a1, $t2
  lw    $a1, 0x5c($sp)
  not   $a1, $a1
  andi  $t3, $a1, 0x808
  sltu  $a1, $zero, $t3
.L7F082848:
  lw    $t4, ($s0)
  sw    $a1, 0x158($sp)
  lw    $v0, 0x124($t4)
  sltu  $a1, $zero, $v0
  beqz  $a1, .L7F082864
   move  $v0, $a1
  move  $a1, $a2
.L7F082864:
  sw    $a1, 0x154($sp)
  beqz  $v0, .L7F082874
   move  $a1, $v0
  lw    $a1, 0x44($sp)
.L7F082874:
  lw    $t7, 0x4c($sp)
  sw    $a1, 0x150($sp)
  lw    $t9, 0x48($sp)
  beqz  $t7, .L7F08288C
   lw    $t8, 0x5c($sp)
  bnez  $t9, .L7F0828A0
.L7F08288C:
   andi  $t2, $t8, 0x4000
  beqz  $t2, .L7F0828C4
   lw    $t3, 0x40($sp)
  beqz  $t3, .L7F0828C4
   nop   
.L7F0828A0:
  jal   get_item_in_hand
   move  $a0, $zero
  li    $at, 29
  bne   $v0, $at, .L7F0828C4
   li    $t5, 1
  sw    $t5, 0x14c($sp)
  sw    $zero, 0x174($sp)
  sw    $zero, 0x170($sp)
  sw    $zero, 0x1b0($sp)
.L7F0828C4:
  lui   $t4, %hi(in_tank_flag) 
  lw    $t4, %lo(in_tank_flag)($t4)
  li    $at, 1
  bnel  $t4, $at, .L7F082964
   lw    $t8, 0x5c($sp)
  lw    $t6, ($s0)
  lw    $t7, 0x124($t6)
  beql  $t7, $zero, .L7F082964
   lw    $t8, 0x5c($sp)
  jal   get_item_in_hand
   move  $a0, $zero
  li    $at, 32
  bne   $v0, $at, .L7F08290C
   lwc1  $f8, 0x18c($sp)
  li    $t9, 1
  sw    $zero, 0x134($sp)
  b     .L7F082958
   sw    $t9, 0x1a8($sp)
.L7F08290C:
  c.eq.s $f8, $f20
  lwc1  $f10, 0x188($sp)
  bc1fl .L7F08295C
   swc1  $f20, 0x17c($sp)
  c.eq.s $f10, $f20
  lwc1  $f18, 0x17c($sp)
  bc1fl .L7F08295C
   swc1  $f20, 0x17c($sp)
  c.lt.s $f20, $f18
  nop   
  bc1fl .L7F082944
   lwc1  $f4, 0x178($sp)
  swc1  $f18, 0x18c($sp)
  lwc1  $f4, 0x178($sp)
.L7F082944:
  c.lt.s $f20, $f4
  nop   
  bc1fl .L7F08295C
   swc1  $f20, 0x17c($sp)
  swc1  $f4, 0x188($sp)
.L7F082958:
  swc1  $f20, 0x17c($sp)
.L7F08295C:
  swc1  $f20, 0x178($sp)
.L7F082960:
  lw    $t8, 0x5c($sp)
.L7F082964:
  lhu   $t2, 0xfe($sp)
  and   $v0, $t8, $t2
  sltu  $a1, $zero, $v0
  beqz  $a1, .L7F08299C
   nop   
  lw    $t5, ($s0)
  lhu   $t6, 0xfa($sp)
  lw    $a1, 0x1c8($t5)
  sltiu $t4, $a1, 1
  beqz  $t4, .L7F08299C
   move  $a1, $t4
  and   $a1, $t8, $t6
  sltiu $t7, $a1, 1
  move  $a1, $t7
.L7F08299C:
  jal   cur_player_get_control_type
   sw    $a1, 0x1b4($sp)
  li    $at, 1
  beql  $v0, $at, .L7F0829C4
   li    $t9, 1
  jal   cur_player_get_control_type
   nop   
  li    $at, 3
  bne   $v0, $at, .L7F0829C8
   li    $t9, 1
.L7F0829C4:
  sw    $t9, 0x140($sp)
.L7F0829C8:
  lw    $t2, ($s0)
.L7F0829CC:
  sw    $zero, 0xd0($t2)
  lw    $t3, 0x1b0($sp)
  beqz  $t3, .L7F082C2C
   lui   $t5, %hi(in_tank_flag) 
  lw    $t5, %lo(in_tank_flag)($t5)
  li    $at, 1
  lui   $t4, %hi(ptr_playerstank) 
  bne   $t5, $at, .L7F082AA4
   lui   $v0, %hi(ptr_playerstank)
  lw    $t4, %lo(ptr_playerstank)($t4)
  li    $a0, 32
  lw    $t8, 4($t4)
  jal   get_ammo_count_for_weapon
   sw    $t8, 0xf4($sp)
  lw    $t6, 0xf4($sp)
  li    $a0, 32
  move  $a1, $zero
  jal   add_ammo_to_weapon
   sw    $v0, 0xd8($t6)
  jal   sub_GAME_7F08C61C
   li    $a0, 32
  jal   get_item_in_hand
   move  $a0, $zero
  li    $at, 32
  bnel  $v0, $at, .L7F082A54
   lw    $t2, 0xf4($sp)
  jal   get_ammo_in_hands_magazine
   move  $a0, $zero
  lw    $v1, 0xf4($sp)
  lw    $t7, 0xd8($v1)
  addu  $t9, $t7, $v0
  jal   autoadvance_on_deplete_all_ammo
   sw    $t9, 0xd8($v1)
  lw    $t2, 0xf4($sp)
.L7F082A54:
  lui   $at, %hi(in_tank_flag)
  move  $v0, $zero
  sw    $zero, 0xc4($t2)
  sw    $zero, %lo(in_tank_flag)($at)
  lw    $t3, ($s0)
  li    $v1, 12
  swc1  $f20, 0x16c($t3)
  lw    $t5, ($s0)
  swc1  $f20, 0x174($t5)
  lw    $t4, ($s0)
  swc1  $f20, 0x14c($t4)
.L7F082A80:
  lw    $t8, ($s0)
  addu  $t6, $t8, $v0
  addiu $v0, $v0, 4
  bne   $v0, $v1, .L7F082A80
   swc1  $f20, 0x180($t6)
  lw    $t9, ($s0)
  li    $t7, 2
  b     .L7F082C2C
   sw    $t7, 0x9c($t9)
.L7F082AA4:
  lw    $v0, %lo(ptr_playerstank)($v0)
  beql  $v0, $zero, .L7F082C24
   lw    $t5, ($s0)
  lbu   $t2, ($v0)
  li    $at, 1
  bnel  $t2, $at, .L7F082C24
   lw    $t5, ($s0)
  lw    $a1, 4($v0)
  li    $at, 45
  lui   $t5, %hi(D_80036480)
  lbu   $t3, 3($a1)
  bnel  $t3, $at, .L7F082C24
   lw    $t5, ($s0)
  lw    $t5, %lo(D_80036480)($t5)
  li    $a0, 32
  beql  $t5, $zero, .L7F082C24
   lw    $t5, ($s0)
  jal   add_item_to_inventory
   sw    $a1, 0xec($sp)
  lw    $v1, 0xec($sp)
  li    $a0, 32
  jal   add_ammo_to_weapon
   lw    $a1, 0xd8($v1)
  lw    $v1, 0xec($sp)
  lui   $a0, %hi(D_8003646C)
  addiu $a0, %lo(D_8003646C) # addiu $a0, $a0, 0x646c
  lwc1  $f6, 0xc8($v1)
  sw    $zero, 0xd8($v1)
  lui   $at, %hi(D_80055120)
  swc1  $f6, ($a0)
  lwc1  $f10, %lo(D_80055120)($at)
  lwc1  $f8, ($a0)
  lui   $at, %hi(D_80036470)
  lui   $a1, %hi(D_80036474)
  div.s $f18, $f8, $f10
  addiu $a1, %lo(D_80036474) # addiu $a1, $a1, 0x6474
  li    $t4, 1
  li    $t9, 1
  lui   $v0, %hi(flt_CODE_bss_800799D0)
  addiu $v0, %lo(flt_CODE_bss_800799D0) # addiu $v0, $v0, -0x6630
  swc1  $f18, %lo(D_80036470)($at)
  lwc1  $f4, 0xcc($v1)
  lui   $at, %hi(D_80036484)
  swc1  $f4, %lo(D_80036484)($at)
  lwc1  $f6, 0xcc($v1)
  lui   $at, %hi(D_80055124)
  swc1  $f6, ($a1)
  lwc1  $f10, %lo(D_80055124)($at)
  lwc1  $f8, ($a1)
  lui   $at, %hi(D_80036478)
  div.s $f18, $f8, $f10
  swc1  $f18, %lo(D_80036478)($at)
  lui   $at, %hi(D_8003647C)
  swc1  $f20, %lo(D_8003647C)($at)
  lwc1  $f4, 0xdc($v1)
  lui   $at, %hi(D_80036464)
  swc1  $f4, %lo(D_80036464)($at)
  lui   $at, %hi(D_80036460)
  swc1  $f20, %lo(D_80036460)($at)
  lui   $at, %hi(in_tank_flag)
  sw    $t4, %lo(in_tank_flag)($at)
  lui   $at, %hi(dword_CODE_bss_800799B8)
  sw    $zero, %lo(dword_CODE_bss_800799B8)($at)
  lw    $t8, ($s0)
  lui   $at, %hi(flt_CODE_bss_800799BC)
  swc1  $f20, 0x16c($t8)
  lw    $t6, ($s0)
  swc1  $f20, 0x174($t6)
  lw    $t7, ($s0)
  swc1  $f20, 0x14c($t7)
  lw    $t2, ($s0)
  sw    $t9, 0x9c($t2)
  swc1  $f20, %lo(flt_CODE_bss_800799BC)($at)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  lui   $at, %hi(flt_CODE_bss_800799C0)
  swc1  $f6, %lo(flt_CODE_bss_800799C0)($at)
  lw    $t0, ($s0)
  lui   $at, %hi(flt_CODE_bss_800799C4)
  lwc1  $f8, 0x148($t0)
  swc1  $f8, %lo(flt_CODE_bss_800799C4)($at)
  lwc1  $f10, 0x158($t0)
  lui   $at, %hi(flt_CODE_bss_800799C8)
  swc1  $f10, %lo(flt_CODE_bss_800799C8)($at)
  lwc1  $f18, 0x48c($t0)
  lui   $at, %hi(D_80036490)
  swc1  $f18, ($v0)
  lwc1  $f4, 0x490($t0)
  swc1  $f4, 4($v0)
  lwc1  $f6, 0x494($t0)
  swc1  $f6, 8($v0)
  jal   sub_GAME_7F07C7B4
   sw    $zero, %lo(D_80036490)($at)
  b     .L7F082C30
   lw    $t4, 0x144($sp)
  lw    $t5, ($s0)
.L7F082C24:
  li    $t3, 1
  sw    $t3, 0xd0($t5)
.L7F082C2C:
  lw    $t4, 0x144($sp)
.L7F082C30:
  bnez  $t4, .L7F082C60
   nop   
  lb    $t8, 0x1c7($sp)
  lw    $t7, 0x128($sp)
  lwc1  $f0, 0x184($sp)
  lwc1  $f8, 0x180($sp)
  negu  $t6, $t8
  negu  $t9, $t7
  sw    $t6, 0x130($sp)
  sw    $t9, 0x128($sp)
  swc1  $f0, 0x180($sp)
  swc1  $f8, 0x184($sp)
.L7F082C60:
  jal   check_if_bond_is_invincible
   nop   
  beqz  $v0, .L7F082C88
   nop   
  jal   getPlayerCount
   nop   
  li    $at, 1
  bne   $v0, $at, .L7F082C88
   nop   
  sw    $zero, 0x1b4($sp)
.L7F082C88:
  jal   sub_GAME_7F067420
   lw    $a0, 0x1b4($sp)
  jal   get_invisible_to_guards_flag
   nop   
  beql  $v0, $zero, .L7F082D3C
   li    $a0, 2
  jal   get_hands_firing_status
   move  $a0, $zero
  bnezl $v0, .L7F082CC4
   swc1  $f20, 0xe4($sp)
  jal   get_hands_firing_status
   li    $a0, 1
  beql  $v0, $zero, .L7F082D3C
   li    $a0, 2
  swc1  $f20, 0xe4($sp)
.L7F082CC4:
  jal   get_hands_firing_status
   move  $a0, $zero
  beqz  $v0, .L7F082CF8
   nop   
  jal   sub_GAME_7F067174
   move  $a0, $zero
  c.lt.s $f20, $f0
  nop   
  bc1f  .L7F082CF8
   nop   
  jal   sub_GAME_7F067174
   move  $a0, $zero
  swc1  $f0, 0xe4($sp)
.L7F082CF8:
  jal   get_hands_firing_status
   li    $a0, 1
  beqz  $v0, .L7F082D30
   nop   
  jal   sub_GAME_7F067174
   li    $a0, 1
  lwc1  $f10, 0xe4($sp)
  c.lt.s $f10, $f0
  nop   
  bc1f  .L7F082D30
   nop   
  jal   sub_GAME_7F067174
   li    $a0, 1
  swc1  $f0, 0xe4($sp)
.L7F082D30:
  jal   sub_GAME_7F022EEC
   lwc1  $f12, 0xe4($sp)
  li    $a0, 2
.L7F082D3C:
  jal   set_unset_bitflags
   lw    $a1, 0x16c($sp)
  lwc1  $f18, 0x164($sp)
  c.lt.s $f20, $f18
  nop   
  bc1fl .L7F082D64
   lwc1  $f4, 0x160($sp)
  jal   sub_GAME_7F05DDA4
   mov.s $f12, $f18
  lwc1  $f4, 0x160($sp)
.L7F082D64:
  c.lt.s $f20, $f4
  nop   
  bc1fl .L7F082D80
   lw    $t2, ($s0)
  jal   sub_GAME_7F05DE94
   mov.s $f12, $f4
  lw    $t2, ($s0)
.L7F082D80:
  lw    $t5, 0x168($sp)
  lw    $t3, 0x1c8($t2)
  bnez  $t3, .L7F082DD0
   li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f12
  beqz  $t5, .L7F082DC0
   nop   
  jal   sub_GAME_7F05DD38
   nop   
  c.le.s $f0, $f20
  mov.s $f12, $f0
  li    $at, 0x42700000 # 60.000000
  bc1f  .L7F082DC0
   nop   
  mtc1  $at, $f12
  nop   
.L7F082DC0:
  jal   sub_GAME_7F07E46C
   nop   
  jal   sub_GAME_7F07E62C
   nop   
.L7F082DD0:
  lui   $t4, %hi(in_tank_flag) 
  lw    $t4, %lo(in_tank_flag)($t4)
  li    $at, 1
  lw    $t6, 0x194($sp)
  bne   $t4, $at, .L7F0830FC
   lui   $v0, %hi(D_80036488)
  addiu $v0, %lo(D_80036488) # addiu $v0, $v0, 0x6488
  swc1  $f20, ($v0)
  lui   $t8, %hi(dword_CODE_bss_800799B8) 
  lw    $t8, %lo(dword_CODE_bss_800799B8)($t8)
  li    $at, 2
  lwc1  $f6, 0x188($sp)
  bne   $t8, $at, .L7F0830F4
   nop   
  c.lt.s $f20, $f6
  lw    $t0, ($s0)
  lui   $at, %hi(global_timer_delta)
  lwc1  $f10, 0x18c($sp)
  bc1fl .L7F082E48
   c.lt.s $f20, $f10
  lwc1  $f8, %lo(global_timer_delta)($at)
  lui   $at, %hi(D_80055128)
  lwc1  $f18, %lo(D_80055128)($at)
  mul.s $f10, $f8, $f6
  lwc1  $f8, ($v0)
  mul.s $f4, $f10, $f18
  add.s $f6, $f8, $f4
  b     .L7F082F04
   swc1  $f6, ($v0)
  c.lt.s $f20, $f10
.L7F082E48:
  lui   $at, %hi(global_timer_delta)
  lw    $t6, 0x1a8($sp)
  bc1f  .L7F082E7C
   nop   
  lwc1  $f18, %lo(global_timer_delta)($at)
  lui   $at, %hi(D_8005512C)
  lwc1  $f4, %lo(D_8005512C)($at)
  mul.s $f8, $f18, $f10
  lwc1  $f18, ($v0)
  mul.s $f6, $f8, $f4
  sub.s $f10, $f18, $f6
  b     .L7F082F04
   swc1  $f10, ($v0)
.L7F082E7C:
  beqz  $t6, .L7F082F04
   lw    $t7, 0x124($sp)
  mtc1  $t7, $f8
  li    $at, 0x428C0000 # 70.000000
  mtc1  $at, $f18
  cvt.s.w $f4, $f8
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  lui   $at, 0x3f80
  div.s $f2, $f4, $f18
  c.lt.s $f6, $f2
  nop   
  bc1fl .L7F082EC0
   li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f2
  nop   
  li    $at, 0xBF800000 # -1.000000
.L7F082EC0:
  mtc1  $at, $f10
  li    $at, 0xBF800000 # -1.000000
  c.lt.s $f2, $f10
  nop   
  bc1f  .L7F082EE0
   nop   
  mtc1  $at, $f2
  nop   
.L7F082EE0:
  lui   $at, %hi(D_80055130)
  lwc1  $f8, %lo(D_80055130)($at)
  lui    $at, %hi(global_timer_delta)
  lwc1  $f18, %lo(global_timer_delta)($at)
  mul.s $f4, $f8, $f2
  lwc1  $f10, ($v0)
  mul.s $f6, $f4, $f18
  add.s $f8, $f10, $f6
  swc1  $f8, ($v0)
.L7F082F04:
  lw    $t9, 0x124($t0)
  li    $at, 0x3F800000 # 1.000000
  lw    $t2, 0x1ac($sp)
  bnez  $t9, .L7F0830F4
   nop   
  mtc1  $at, $f2
  mov.s $f0, $f20
  beqz  $t2, .L7F082F48
   mov.s $f14, $f2
  lw    $t1, 0x120($sp)
  li    $at, 0x428C0000 # 70.000000
  mtc1  $at, $f10
  mtc1  $t1, $f4
  nop   
  cvt.s.w $f18, $f4
  b     .L7F082F70
   div.s $f0, $f18, $f10
.L7F082F48:
  lw    $t3, 0x19c($sp)
  lw    $t5, 0x198($sp)
  beqz  $t3, .L7F082F60
   nop   
  b     .L7F082F70
   mov.s $f0, $f2
.L7F082F60:
  beqz  $t5, .L7F082F70
   li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f0
  nop   
.L7F082F70:
  c.lt.s $f2, $f0
  li    $at, 0xBF800000 # -1.000000
  lui   $t4, %hi(clock_timer) 
  bc1fl .L7F082F90
   mtc1  $at, $f6
  b     .L7F082FAC
   mov.s $f0, $f2
  mtc1  $at, $f6
.L7F082F90:
  lui   $at, 0xbf80
  c.lt.s $f0, $f6
  nop   
  bc1fl .L7F082FB0
   li    $at, 0x41700000 # 15.000000
  mtc1  $at, $f0
  nop   
.L7F082FAC:
  li    $at, 0x41700000 # 15.000000
.L7F082FB0:
  mtc1  $at, $f16
  lui   $v1, %hi(D_80036490)
  addiu $v1, %lo(D_80036490) # addiu $v1, $v1, 0x6490
  mul.s $f12, $f0, $f16
  lw    $v0, ($v1)
  li    $at, 0x3F000000 # 0.500000
  blez  $v0, .L7F082FEC
   mov.s $f2, $f12
  mtc1  $at, $f8
  lw    $t4, %lo(clock_timer)($t4)
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f14
  subu  $t8, $v0, $t4
  mul.s $f2, $f12, $f8
  sw    $t8, ($v1)
.L7F082FEC:
  lwc1  $f0, 0x174($t0)
  c.eq.s $f2, $f0
  nop   
  bc1t  .L7F0830F4
   nop   
  c.lt.s $f0, $f2
  li    $at, 0x3E800000 # 0.250000
  bc1fl .L7F083080
   c.lt.s $f2, $f0
  sub.s $f4, $f2, $f0
  mtc1  $at, $f18
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f8
  mul.s $f10, $f4, $f18
  li    $at, 0x41200000 # 10.000000
  div.s $f6, $f10, $f16
  mtc1  $at, $f10
  li    $at, 0x42700000 # 60.000000
  add.s $f4, $f6, $f8
  mtc1  $at, $f8
  lui   $at, %hi(global_timer_delta)
  mul.s $f18, $f4, $f14
  lwc1  $f4, %lo(global_timer_delta)($at)
  mul.s $f6, $f18, $f10
  div.s $f12, $f6, $f8
  mul.s $f18, $f12, $f4
  add.s $f10, $f0, $f18
  swc1  $f10, 0x174($t0)
  lw    $t0, ($s0)
  lwc1  $f6, 0x174($t0)
  c.lt.s $f2, $f6
  nop   
  bc1f  .L7F0830F4
   nop   
  b     .L7F0830F4
   swc1  $f2, 0x174($t0)
  c.lt.s $f2, $f0
.L7F083080:
  li    $at, 0x3E800000 # 0.250000
  bc1f  .L7F0830F4
   nop   
  sub.s $f8, $f0, $f2
  mtc1  $at, $f4
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f6
  mul.s $f18, $f8, $f4
  li    $at, 0xC1200000 # -10.000000
  div.s $f10, $f18, $f16
  mtc1  $at, $f18
  li    $at, 0x42700000 # 60.000000
  add.s $f8, $f10, $f6
  mtc1  $at, $f6
  lui   $at, %hi(global_timer_delta)
  mul.s $f4, $f8, $f14
  lwc1  $f8, %lo(global_timer_delta)($at)
  mul.s $f10, $f4, $f18
  div.s $f12, $f10, $f6
  mul.s $f4, $f12, $f8
  add.s $f18, $f0, $f4
  swc1  $f18, 0x174($t0)
  lw    $t0, ($s0)
  lwc1  $f10, 0x174($t0)
  c.lt.s $f10, $f2
  nop   
  bc1f  .L7F0830F4
   nop   
  swc1  $f2, 0x174($t0)
.L7F0830F4:
  b     .L7F083394
   lw    $t0, ($s0)
.L7F0830FC:
  beqz  $t6, .L7F083114
   lw    $t7, 0x190($sp)
  jal   sub_GAME_7F07FCC4
   li    $a0, -1
  b     .L7F083138
   lw    $t9, 0x1a8($sp)
.L7F083114:
  beqz  $t7, .L7F08312C
   nop   
  jal   sub_GAME_7F07FCC4
   li    $a0, 1
  b     .L7F083138
   lw    $t9, 0x1a8($sp)
.L7F08312C:
  jal   sub_GAME_7F07FCC4
   move  $a0, $zero
  lw    $t9, 0x1a8($sp)
.L7F083138:
  lw    $t2, 0x124($sp)
  beql  $t9, $zero, .L7F083164
   lw    $t5, 0x19c($sp)
  mtc1  $t2, $f6
  li    $at, 0x428C0000 # 70.000000
  mtc1  $at, $f4
  cvt.s.w $f8, $f6
  lw    $t3, ($s0)
  div.s $f18, $f8, $f4
  swc1  $f18, 0x16c($t3)
  lw    $t5, 0x19c($sp)
.L7F083164:
  lw    $t7, 0x198($sp)
  beqz  $t5, .L7F083194
   nop   
  jal   sub_GAME_7F07FE1C
   li    $a0, 1
  lw    $t0, ($s0)
  lui   $t8, %hi(clock_timer) 
  lw    $t8, %lo(clock_timer)($t8)
  lw    $t4, 0x17c($t0)
  addu  $t6, $t4, $t8
  b     .L7F0831B4
   sw    $t6, 0x17c($t0)
.L7F083194:
  beqz  $t7, .L7F0831AC
   nop   
  jal   sub_GAME_7F07FE1C
   li    $a0, -1
  b     .L7F0831B8
   lw    $t9, 0x1ac($sp)
.L7F0831AC:
  jal   sub_GAME_7F07FE1C
   move  $a0, $zero
.L7F0831B4:
  lw    $t9, 0x1ac($sp)
.L7F0831B8:
  lw    $t2, 0x120($sp)
  beql  $t9, $zero, .L7F083218
   lw    $t0, ($s0)
  mtc1  $t2, $f10
  li    $at, 0x428C0000 # 70.000000
  mtc1  $at, $f8
  cvt.s.w $f6, $f10
  lw    $t3, ($s0)
  div.s $f4, $f6, $f8
  swc1  $f4, 0x174($t3)
  lw    $t5, 0x120($sp)
  slti  $at, $t5, 0x3d
  bnezl $at, .L7F083210
   lw    $t7, ($s0)
  lw    $t0, ($s0)
  lui   $t8, %hi(clock_timer) 
  lw    $t8, %lo(clock_timer)($t8)
  lw    $t4, 0x17c($t0)
  addu  $t6, $t4, $t8
  b     .L7F083214
   sw    $t6, 0x17c($t0)
  lw    $t7, ($s0)
.L7F083210:
  sw    $zero, 0x17c($t7)
.L7F083214:
  lw    $t0, ($s0)
.L7F083218:
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f18
  lwc1  $f0, 0x174($t0)
  lui   $at, 0x3f80
  c.lt.s $f18, $f0
  nop   
  bc1fl .L7F083250
   li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f10
  nop   
  swc1  $f10, 0x174($t0)
  lw    $t0, ($s0)
  lwc1  $f0, 0x174($t0)
  li    $at, 0xBF800000 # -1.000000
.L7F083250:
  mtc1  $at, $f6
  lui   $at, 0xbf80
  c.lt.s $f0, $f6
  nop   
  bc1fl .L7F08327C
   li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  nop   
  swc1  $f8, 0x174($t0)
  lw    $t0, ($s0)
  li    $at, 0x3F800000 # 1.000000
.L7F08327C:
  mtc1  $at, $f4
  lwc1  $f0, 0x16c($t0)
  lui   $at, 0x3f80
  c.lt.s $f4, $f0
  nop   
  bc1fl .L7F0832B0
   li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f18
  nop   
  swc1  $f18, 0x16c($t0)
  lw    $t0, ($s0)
  lwc1  $f0, 0x16c($t0)
  li    $at, 0xBF800000 # -1.000000
.L7F0832B0:
  mtc1  $at, $f10
  li    $at, 0xBF800000 # -1.000000
  c.lt.s $f0, $f10
  nop   
  bc1f  .L7F0832D8
   nop   
  mtc1  $at, $f6
  nop   
  swc1  $f6, 0x16c($t0)
  lw    $t0, ($s0)
.L7F0832D8:
  lui   $at, %hi(D_80055134)
  lwc1  $f4, %lo(D_80055134)($at)
  lwc1  $f8, 0x174($t0)
  mul.s $f18, $f8, $f4
  swc1  $f18, 0x174($t0)
  lw    $t0, ($s0)
  lwc1  $f10, 0x174($t0)
  lwc1  $f6, 0x178($t0)
  mul.s $f8, $f10, $f6
  swc1  $f8, 0x174($t0)
  lw    $t9, 0x1ac($sp)
  lw    $t2, 0x19c($sp)
  bnezl $t9, .L7F083324
   lw    $t5, 0x154($sp)
  bnezl $t2, .L7F083324
   lw    $t5, 0x154($sp)
  lw    $t3, ($s0)
  sw    $zero, 0x17c($t3)
  lw    $t5, 0x154($sp)
.L7F083324:
  lw    $t4, 0x150($sp)
  beqz  $t5, .L7F083340
   nop   
  jal   sub_GAME_7F079988
   li    $a0, -1
  b     .L7F083364
   lw    $t8, 0x15c($sp)
.L7F083340:
  beqz  $t4, .L7F083358
   nop   
  jal   sub_GAME_7F079988
   li    $a0, 1
  b     .L7F083364
   lw    $t8, 0x15c($sp)
.L7F083358:
  jal   sub_GAME_7F079988
   move  $a0, $zero
  lw    $t8, 0x15c($sp)
.L7F083364:
  lw    $t6, 0x158($sp)
  beqz  $t8, .L7F083380
   nop   
  jal   change_crouch_position
   li    $a0, -2
  b     .L7F083394
   lw    $t0, ($s0)
.L7F083380:
  beql  $t6, $zero, .L7F083394
   lw    $t0, ($s0)
  jal   change_crouch_position
   li    $a0, 2
  lw    $t0, ($s0)
.L7F083394:
  lw    $t7, 0x17c($t0)
  slti  $at, $t7, 0xb4
  bnez  $at, .L7F0833FC
   li    $at, 0x3FA00000 # 1.250000
  mtc1  $at, $f2
  lwc1  $f0, 0x178($t0)
  lui   $at, %hi(D_80055138)
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F0833E4
   c.lt.s $f2, $f0
  lwc1  $f4, %lo(D_80055138)($at)
  lui   $at, %hi(global_timer_delta)
  lwc1  $f18, %lo(global_timer_delta)($at)
  mul.s $f10, $f4, $f18
  add.s $f6, $f0, $f10
  swc1  $f6, 0x178($t0)
  lw    $t0, ($s0)
  lwc1  $f0, 0x178($t0)
  c.lt.s $f2, $f0
.L7F0833E4:
  nop   
  bc1fl .L7F08346C
   lw    $t9, 0x1c8($t0)
  swc1  $f2, 0x178($t0)
  b     .L7F083468
   lw    $t0, ($s0)
.L7F0833FC:
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  lwc1  $f0, 0x178($t0)
  lui   $at, %hi(D_8005513C)
  c.lt.s $f8, $f0
  nop   
  bc1fl .L7F083440
   lui   $at, %hi(0x3F800000) # $at, 0x3f80
  lwc1  $f4, %lo(D_8005513C)($at)
  lui   $at, %hi(global_timer_delta)
  lwc1  $f18, %lo(global_timer_delta)($at)
  mul.s $f10, $f4, $f18
  sub.s $f6, $f0, $f10
  swc1  $f6, 0x178($t0)
  lw    $t0, ($s0)
  lwc1  $f0, 0x178($t0)
  li    $at, 0x3F800000 # 1.000000
.L7F083440:
  mtc1  $at, $f8
  li    $at, 0x3F800000 # 1.000000
  c.lt.s $f0, $f8
  nop   
  bc1fl .L7F08346C
   lw    $t9, 0x1c8($t0)
  mtc1  $at, $f4
  nop   
  swc1  $f4, 0x178($t0)
  lw    $t0, ($s0)
.L7F083468:
  lw    $t9, 0x1c8($t0)
.L7F08346C:
  bnezl $t9, .L7F083B40
   lw    $t6, 0x1a4($sp)
  lw    $t2, 0x114($t0)
  li    $at, 0xC0800000 # -4.000000
  mtc1  $at, $f14
  beqz  $t2, .L7F083680
   li    $at, 0x43960000 # 300.000000
  lw    $t3, 0x488($t0)
  mtc1  $at, $f18
  addiu $a1, $sp, 0xa0
  sw    $t3, 0xc0($sp)
  swc1  $f18, 0xbc($sp)
  lw    $a0, 0xa8($t0)
  swc1  $f14, 0xc4($sp)
  addiu $a2, $sp, 0xa8
  jal   sub_GAME_7F08A274
   addiu $a3, $sp, 0xa4
  lw    $t0, ($s0)
  li    $at, 0x43960000 # 300.000000
  mtc1  $at, $f0
  lwc1  $f10, 0x498($t0)
  lwc1  $f8, 0x48c($t0)
  mul.s $f6, $f10, $f0
  add.s $f4, $f6, $f8
  swc1  $f4, 0xac($sp)
  lwc1  $f18, 0x490($t0)
  swc1  $f18, 0xb0($sp)
  lwc1  $f10, 0x4a0($t0)
  lwc1  $f8, 0x494($t0)
  mul.s $f6, $f10, $f0
  add.s $f4, $f6, $f8
  jal   sub_GAME_7F0B1CC4
   swc1  $f4, 0xb4($sp)
  lw    $t0, ($s0)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  lw    $a1, 0x48c($t0)
  lw    $a2, 0x494($t0)
  lwc1  $f18, 0xb4($sp)
  lwc1  $f10, 0xa8($sp)
  lwc1  $f6, 0xa4($sp)
  li    $t5, 4096
  sw    $t5, 0x14($sp)
  swc1  $f20, 0x20($sp)
  addiu $a0, $sp, 0xc0
  lw    $a3, 0xac($sp)
  swc1  $f8, 0x24($sp)
  swc1  $f18, 0x10($sp)
  swc1  $f10, 0x18($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f6, 0x1c($sp)
  beqz  $v0, .L7F083560
   lwc1  $f14, 0xc4($sp)
  lw    $a0, 0xc0($sp)
  lw    $a1, 0xac($sp)
  lw    $a2, 0xb4($sp)
  jal   sub_GAME_7F080D60
   swc1  $f14, 0xc4($sp)
  lwc1  $f14, 0xc4($sp)
  b     .L7F0835C4
   swc1  $f0, 0xb0($sp)
.L7F083560:
  lw    $t0, ($s0)
  addiu $a2, $sp, 0xac
  swc1  $f14, 0xc4($sp)
  addiu $a0, $t0, 0x48c
  jal   sub_GAME_7F026298
   addiu $a1, $t0, 0x498
  lw    $t0, ($s0)
  lwc1  $f4, 0xac($sp)
  lwc1  $f10, 0xb4($sp)
  lwc1  $f18, 0x48c($t0)
  lwc1  $f6, 0x494($t0)
  sub.s $f0, $f4, $f18
  sub.s $f2, $f10, $f6
  mul.s $f8, $f0, $f0
  nop   
  mul.s $f4, $f2, $f2
  jal   sqrtf
   add.s $f12, $f8, $f4
  swc1  $f0, 0xbc($sp)
  lw    $a0, 0xc0($sp)
  lw    $a1, 0xac($sp)
  jal   sub_GAME_7F080D60
   lw    $a2, 0xb4($sp)
  lwc1  $f14, 0xc4($sp)
  swc1  $f0, 0xb0($sp)
.L7F0835C4:
  lwc1  $f18, 0xbc($sp)
  c.lt.s $f20, $f18
  nop   
  bc1fl .L7F083684
   lw    $t0, ($s0)
  lw    $t4, ($s0)
  li    $at, 0xC3960000 # -300.000000
  mtc1  $at, $f6
  lwc1  $f10, 0x74($t4)
  li    $at, 0x43FA0000 # 500.000000
  sub.s $f12, $f0, $f10
  c.lt.s $f6, $f12
  nop   
  bc1fl .L7F083684
   lw    $t0, ($s0)
  mtc1  $at, $f8
  nop   
  c.lt.s $f12, $f8
  nop   
  bc1fl .L7F083684
   lw    $t0, ($s0)
  jal   convert_angle_using_inverse
   mov.s $f14, $f18
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f12
  lui   $at, %hi(D_80055140)
  lwc1  $f10, %lo(D_80055140)($at)
  mul.s $f4, $f0, $f12
  li    $at, 0xC0800000 # -4.000000
  mtc1  $at, $f8
  li    $at, 0x43340000 # 180.000000
  mtc1  $at, $f18
  lui   $at, %hi(D_80055144)
  div.s $f6, $f4, $f10
  add.s $f2, $f6, $f8
  c.le.s $f18, $f2
  mov.s $f14, $f2
  bc1fl .L7F083668
   c.lt.s $f20, $f14
  sub.s $f14, $f2, $f12
  c.lt.s $f20, $f14
.L7F083668:
  nop   
  bc1fl .L7F083684
   lw    $t0, ($s0)
  lwc1  $f4, %lo(D_80055144)($at)
  mul.s $f14, $f14, $f4
  nop   
.L7F083680:
  lw    $t0, ($s0)
.L7F083684:
  lw    $t1, 0x120($sp)
  lui   $t6, %hi(in_tank_flag) 
  lw    $t8, 0x110($t0)
  slti  $at, $t1, 0x28
  beqz  $t8, .L7F0836B4
   nop   
  beqz  $at, .L7F0836B4
   slti  $at, $t1, -0x27
  bnez  $at, .L7F0836B4
   nop   
  sw    $zero, 0x110($t0)
  lw    $t0, ($s0)
.L7F0836B4:
  lw    $t6, %lo(in_tank_flag)($t6)
  lwc1  $f10, 0x184($sp)
  bnezl $t6, .L7F08383C
   lw    $t8, 0x104($t0)
  c.lt.s $f20, $f10
  lwc1  $f6, 0x180($sp)
  bc1tl .L7F0836E8
   sw    $zero, 0x104($t0)
  c.lt.s $f20, $f6
  lw    $t3, 0x140($sp)
  bc1f  .L7F083704
   nop   
  sw    $zero, 0x104($t0)
.L7F0836E8:
  lw    $t9, ($s0)
  li    $t7, 1
  sw    $t7, 0x10c($t9)
  lw    $t2, ($s0)
  sw    $zero, 0x120($t2)
  b     .L7F083838
   lw    $t0, ($s0)
.L7F083704:
  beql  $t3, $zero, .L7F08371C
   lw    $t5, 0x118($t0)
  sw    $zero, 0x120($t0)
  b     .L7F083830
   lw    $t0, ($s0)
  lw    $t5, 0x118($t0)
.L7F08371C:
  lw    $t4, 0x1ac($sp)
  beql  $t5, $zero, .L7F0837B8
   lw    $t2, 0x11c($t0)
  beqz  $t4, .L7F08374C
   slti  $at, $t1, 0x3d
  beqz  $at, .L7F083744
   li    $t8, 1
  slti  $at, $t1, -0x3c
  beql  $at, $zero, .L7F083750
   lw    $t6, 0x120($t0)
.L7F083744:
  sw    $t8, 0x120($t0)
  lw    $t0, ($s0)
.L7F08374C:
  lw    $t6, 0x120($t0)
.L7F083750:
  li    $at, 0x40A00000 # 5.000000
  beql  $t6, $zero, .L7F083834
   sw    $zero, 0x10c($t0)
  mtc1  $at, $f8
  lwc1  $f0, 0x158($t0)
  li    $at, 0xC1200000 # -10.000000
  add.s $f18, $f14, $f8
  c.lt.s $f18, $f0
  nop   
  bc1tl .L7F08379C
   lw    $t7, 0x110($t0)
  mtc1  $at, $f4
  nop   
  add.s $f10, $f14, $f4
  c.lt.s $f0, $f10
  nop   
  bc1fl .L7F083834
   sw    $zero, 0x10c($t0)
  lw    $t7, 0x110($t0)
.L7F08379C:
  li    $t9, 1
  bnezl $t7, .L7F083834
   sw    $zero, 0x10c($t0)
  sw    $t9, 0x104($t0)
  b     .L7F083830
   lw    $t0, ($s0)
  lw    $t2, 0x11c($t0)
.L7F0837B8:
  lw    $t3, 0x1ac($sp)
  beql  $t2, $zero, .L7F083834
   sw    $zero, 0x10c($t0)
  beqz  $t3, .L7F083830
   slti  $at, $t1, 0x3d
  beqz  $at, .L7F0837D8
   slti  $at, $t1, -0x3c
  beqz  $at, .L7F083830
.L7F0837D8:
   li    $at, 0x40A00000 # 5.000000
  mtc1  $at, $f6
  lwc1  $f0, 0x158($t0)
  li    $at, 0xC1200000 # -10.000000
  add.s $f8, $f14, $f6
  c.lt.s $f8, $f0
  nop   
  bc1tl .L7F08381C
   lw    $t5, 0x110($t0)
  mtc1  $at, $f18
  nop   
  add.s $f4, $f14, $f18
  c.lt.s $f0, $f4
  nop   
  bc1fl .L7F083834
   sw    $zero, 0x10c($t0)
  lw    $t5, 0x110($t0)
.L7F08381C:
  li    $t4, 1
  bnezl $t5, .L7F083834
   sw    $zero, 0x10c($t0)
  sw    $t4, 0x104($t0)
  lw    $t0, ($s0)
.L7F083830:
  sw    $zero, 0x10c($t0)
.L7F083834:
  lw    $t0, ($s0)
.L7F083838:
  lw    $t8, 0x104($t0)
.L7F08383C:
  lui   $t6, %hi(in_tank_flag) 
  lw    $t2, 0x1a0($sp)
  beqz  $t8, .L7F083970
   nop   
  lw    $t6, %lo(in_tank_flag)($t6)
  bnezl $t6, .L7F083B40
   lw    $t6, 0x1a4($sp)
  lwc1  $f2, 0x160($t0)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f6
  mul.s $f10, $f2, $f2
  lui   $at, %hi(D_80055148)
  lwc1  $f18, %lo(D_80055148)($at)
  lwc1  $f0, 0x158($t0)
  li    $at, 0x3F800000 # 1.000000
  mul.s $f8, $f10, $f6
  div.s $f12, $f8, $f18
  add.s $f4, $f14, $f12
  c.lt.s $f4, $f0
  nop   
  bc1fl .L7F0838AC
   sub.s $f10, $f14, $f12
  mtc1  $at, $f12
  jal   sub_GAME_7F080010
   swc1  $f14, 0xc4($sp)
  b     .L7F0838E4
   lwc1  $f14, 0xc4($sp)
  sub.s $f10, $f14, $f12
.L7F0838AC:
  li    $at, 0xBF800000 # -1.000000
  c.lt.s $f0, $f10
  nop   
  bc1fl .L7F0838D8
   mov.s $f12, $f20
  mtc1  $at, $f12
  jal   sub_GAME_7F080010
   swc1  $f14, 0xc4($sp)
  b     .L7F0838E4
   lwc1  $f14, 0xc4($sp)
  mov.s $f12, $f20
.L7F0838D8:
  jal   sub_GAME_7F080010
   swc1  $f14, 0xc4($sp)
  lwc1  $f14, 0xc4($sp)
.L7F0838E4:
  lw    $t0, ($s0)
  lui    $at, %hi(global_timer_delta)
  lwc1  $f8, %lo(global_timer_delta)($at)
  lwc1  $f6, 0x160($t0)
  lwc1  $f0, 0x158($t0)
  mul.s $f2, $f6, $f8
  c.lt.s $f14, $f0
  add.s $f18, $f2, $f2
  bc1f  .L7F083924
   add.s $f12, $f0, $f18
  c.lt.s $f14, $f12
  nop   
  bc1fl .L7F083928
   c.lt.s $f0, $f14
  b     .L7F083B3C
   swc1  $f12, 0x158($t0)
.L7F083924:
  c.lt.s $f0, $f14
.L7F083928:
  nop   
  bc1fl .L7F083950
   swc1  $f14, 0x158($t0)
  c.lt.s $f12, $f14
  nop   
  bc1fl .L7F083950
   swc1  $f14, 0x158($t0)
  b     .L7F083B3C
   swc1  $f12, 0x158($t0)
  swc1  $f14, 0x158($t0)
.L7F083950:
  lw    $t7, ($s0)
  swc1  $f20, 0x160($t7)
  lw    $t0, ($s0)
  lw    $t9, 0x10c($t0)
  bnezl $t9, .L7F083B40
   lw    $t6, 0x1a4($sp)
  b     .L7F083B3C
   sw    $zero, 0x104($t0)
.L7F083970:
  beqz  $t2, .L7F083A2C
   lwc1  $f18, 0x184($sp)
  jal   video_related_23
   nop   
  lw    $t3, 0x128($sp)
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f4
  mtc1  $t3, $f10
  li    $at, 0x428C0000 # 70.000000
  mtc1  $at, $f8
  cvt.s.w $f6, $f10
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f18
  li    $at, 0xBF800000 # -1.000000
  div.s $f14, $f0, $f4
  div.s $f12, $f6, $f8
  c.lt.s $f18, $f12
  mov.s $f2, $f12
  bc1fl .L7F0839D4
   mtc1  $at, $f4
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f2
  b     .L7F0839F4
   c.le.s $f20, $f2
  mtc1  $at, $f4
.L7F0839D4:
  li    $at, 0xBF800000 # -1.000000
  c.lt.s $f12, $f4
  nop   
  bc1fl .L7F0839F4
   c.le.s $f20, $f2
  mtc1  $at, $f2
  nop   
  c.le.s $f20, $f2
.L7F0839F4:
  nop   
  bc1fl .L7F083A10
   neg.s $f10, $f2
  mul.s $f2, $f2, $f2
  b     .L7F083A1C
   neg.s $f6, $f2
  neg.s $f10, $f2
.L7F083A10:
  mul.s $f2, $f2, $f10
  nop   
  neg.s $f6, $f2
.L7F083A1C:
  lw    $t5, ($s0)
  mul.s $f8, $f6, $f14
  b     .L7F083AC4
   swc1  $f8, 0x160($t5)
.L7F083A2C:
  c.lt.s $f20, $f18
  lwc1  $f4, 0x180($sp)
  bc1fl .L7F083A78
   c.lt.s $f20, $f4
  jal   sub_GAME_7F080010
   mov.s $f12, $f18
  lw    $t4, 0x1ac($sp)
  lw    $t8, 0x120($sp)
  beqz  $t4, .L7F083AC4
   slti  $at, $t8, 0x3d
  beqz  $at, .L7F083A64
   slti  $at, $t8, 0x3c
  beql  $at, $zero, .L7F083AC8
   lw    $t0, ($s0)
.L7F083A64:
  lw    $t7, ($s0)
  li    $t6, 1
  b     .L7F083AC4
   sw    $t6, 0x110($t7)
  c.lt.s $f20, $f4
.L7F083A78:
  nop   
  bc1f  .L7F083ABC
   nop   
  jal   sub_GAME_7F080010
   neg.s $f12, $f4
  lw    $t9, 0x1ac($sp)
  lw    $t2, 0x120($sp)
  beqz  $t9, .L7F083AC4
   slti  $at, $t2, 0x3d
  beqz  $at, .L7F083AAC
   slti  $at, $t2, 0x3c
  beql  $at, $zero, .L7F083AC8
   lw    $t0, ($s0)
.L7F083AAC:
  lw    $t5, ($s0)
  li    $t3, 1
  b     .L7F083AC4
   sw    $t3, 0x110($t5)
.L7F083ABC:
  jal   sub_GAME_7F080010
   mov.s $f12, $f20
.L7F083AC4:
  lw    $t0, ($s0)
.L7F083AC8:
  lui    $at, %hi(global_timer_delta)
  lwc1  $f6, %lo(global_timer_delta)($at)
  lwc1  $f10, 0x160($t0)
  li    $at, 0x40600000 # 3.500000
  mtc1  $at, $f18
  mul.s $f8, $f10, $f6
  lwc1  $f10, 0x158($t0)
  lui   $t4, %hi(in_tank_flag) 
  li    $at, 1
  lui   $t8, %hi(dword_CODE_bss_800799B8) 
  mul.s $f4, $f8, $f18
  add.s $f6, $f10, $f4
  swc1  $f6, 0x158($t0)
  lw    $t4, %lo(in_tank_flag)($t4)
  bnel  $t4, $at, .L7F083B40
   lw    $t6, 0x1a4($sp)
  lw    $t8, %lo(dword_CODE_bss_800799B8)($t8)
  li    $at, 2
  bnel  $t8, $at, .L7F083B40
   lw    $t6, 0x1a4($sp)
  lw    $t0, ($s0)
  li    $at, 0xC1A00000 # -20.000000
  mtc1  $at, $f0
  lwc1  $f8, 0x158($t0)
  c.lt.s $f8, $f0
  nop   
  bc1fl .L7F083B40
   lw    $t6, 0x1a4($sp)
  swc1  $f0, 0x158($t0)
.L7F083B3C:
  lw    $t6, 0x1a4($sp)
.L7F083B40:
  lwc1  $f6, 0x17c($sp)
  beql  $t6, $zero, .L7F083BF0
   c.lt.s $f20, $f6
  jal   video_related_23
   nop   
  lw    $t7, 0x12c($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f14
  mtc1  $t7, $f18
  li    $at, 0x428C0000 # 70.000000
  mtc1  $at, $f4
  cvt.s.w $f10, $f18
  li    $at, 0xBF800000 # -1.000000
  div.s $f12, $f10, $f4
  c.lt.s $f14, $f12
  mov.s $f2, $f12
  bc1fl .L7F083B94
   mtc1  $at, $f6
  b     .L7F083BB0
   mov.s $f2, $f14
  mtc1  $at, $f6
.L7F083B94:
  li    $at, 0xBF800000 # -1.000000
  c.lt.s $f12, $f6
  nop   
  bc1fl .L7F083BB4
   c.le.s $f20, $f2
  mtc1  $at, $f2
  nop   
.L7F083BB0:
  c.le.s $f20, $f2
.L7F083BB4:
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f18
  bc1f  .L7F083BD0
   div.s $f10, $f0, $f18
  mul.s $f2, $f2, $f2
  b     .L7F083BDC
   nop   
.L7F083BD0:
  neg.s $f8, $f2
  mul.s $f2, $f2, $f8
  nop   
.L7F083BDC:
  mul.s $f4, $f2, $f10
  lw    $t9, ($s0)
  b     .L7F083C50
   swc1  $f4, 0x14c($t9)
  c.lt.s $f20, $f6
.L7F083BF0:
  lwc1  $f8, 0x178($sp)
  bc1fl .L7F083C18
   c.lt.s $f20, $f8
  jal   sub_GAME_7F0802C4
   mov.s $f12, $f6
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f14
  b     .L7F083C50
   nop   
  c.lt.s $f20, $f8
.L7F083C18:
  nop   
  bc1f  .L7F083C3C
   nop   
  jal   sub_GAME_7F0802C4
   neg.s $f12, $f8
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f14
  b     .L7F083C50
   nop   
.L7F083C3C:
  jal   sub_GAME_7F0802C4
   mov.s $f12, $f20
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f14
  nop   
.L7F083C50:
  lui   $t2, %hi(in_tank_flag) 
  lw    $t2, %lo(in_tank_flag)($t2)
  li    $at, 1
  lui   $t3, %hi(dword_CODE_bss_800799B8) 
  bnel  $t2, $at, .L7F083D90
   lw    $t6, 0x14c($sp)
  lw    $t3, %lo(dword_CODE_bss_800799B8)($t3)
  li    $at, 2
  lw    $t5, 0x1a4($sp)
  bnel  $t3, $at, .L7F083D88
   lw    $t8, ($s0)
  beqz  $t5, .L7F083CA0
   mov.s $f2, $f20
  lw    $t4, ($s0)
  lui   $at, %hi(D_8005514C)
  lwc1  $f10, %lo(D_8005514C)($at)
  lwc1  $f18, 0x14c($t4)
  mul.s $f2, $f18, $f10
  b     .L7F083D00
   nop   
.L7F083CA0:
  lwc1  $f4, 0x17c($sp)
  lwc1  $f8, 0x178($sp)
  c.lt.s $f20, $f4
  nop   
  bc1fl .L7F083CD8
   c.lt.s $f20, $f8
  jal   sub_GAME_7F080228
   mov.s $f12, $f14
  lui   $at, %hi(D_80055150)
  lwc1  $f6, %lo(D_80055150)($at)
  mul.s $f2, $f0, $f6
  b     .L7F083D00
   nop   
  c.lt.s $f20, $f8
.L7F083CD8:
  li    $at, 0xBF800000 # -1.000000
  bc1f  .L7F083D00
   nop   
  mtc1  $at, $f12
  jal   sub_GAME_7F080228
   nop   
  lui   $at, %hi(D_80055154)
  lwc1  $f18, %lo(D_80055154)($at)
  mul.s $f2, $f0, $f18
  nop   
.L7F083D00:
  lui   $v1, %hi(clock_timer)
  lw    $v1, %lo(clock_timer)($v1)
  move  $v0, $zero
  lw    $t0, ($s0)
  blez  $v1, .L7F083D64
   lui   $at, %hi(D_80055158)
  lui   $a0, %hi(D_80036460)
  addiu $a0, %lo(D_80036460) # addiu $a0, $a0, 0x6460
  lwc1  $f0, %lo(D_80055158)($at)
  lwc1  $f18, ($a0)
  addiu $v0, $v0, 1
  slt   $at, $v0, $v1
  mul.s $f20, $f0, $f18
  beql  $at, $zero, .L7F083D60
   add.s $f18, $f20, $f2
  add.s $f18, $f20, $f2
.L7F083D40:
  addiu $v0, $v0, 1
  slt   $at, $v0, $v1
  swc1  $f18, ($a0)
  lwc1  $f18, ($a0)
  mul.s $f20, $f0, $f18
  bnezl $at, .L7F083D40
   add.s $f18, $f20, $f2
  add.s $f18, $f20, $f2
.L7F083D60:
  swc1  $f18, ($a0)
.L7F083D64:
  lui   $a0, %hi(D_80036460)
  addiu $a0, %lo(D_80036460) # addiu $a0, $a0, 0x6460
  lui   $at, %hi(D_8005515C)
  lwc1  $f18, %lo(D_8005515C)($at)
  lwc1  $f8, ($a0)
  mul.s $f10, $f8, $f18
  b     .L7F083D8C
   swc1  $f10, 0x14c($t0)
  lw    $t8, ($s0)
.L7F083D88:
  swc1  $f20, 0x14c($t8)
.L7F083D8C:
  lw    $t6, 0x14c($sp)
.L7F083D90:
  beql  $t6, $zero, .L7F083DB0
   li    $t2, 1
  lw    $t7, ($s0)
  sw    $zero, 0x894($t7)
  lw    $t9, ($s0)
  jal   trigger_remote_mine_detonation
   sw    $zero, 0x898($t9)
  li    $t2, 1
.L7F083DB0:
  jal   getPlayerCount
   sw    $t2, 0x74($sp)
  slti  $at, $v0, 2
  bnezl $at, .L7F083DF0
   lw    $t3, 0x74($sp)
  jal   get_scenario
   nop   
  li    $at, 2
  bnel  $v0, $at, .L7F083DF0
   lw    $t3, 0x74($sp)
  jal   bondinvIsAliveWithFlag
   nop   
  beql  $v0, $zero, .L7F083DF0
   lw    $t3, 0x74($sp)
  sw    $zero, 0x74($sp)
  lw    $t3, 0x74($sp)
.L7F083DF0:
  beql  $t3, $zero, .L7F083E24
   lw    $t8, 0x1bc($sp)
  lw    $t5, 0x174($sp)
  beql  $t5, $zero, .L7F083E10
   lw    $t4, 0x170($sp)
  jal   backstep_through_inventory
   nop   
  lw    $t4, 0x170($sp)
.L7F083E10:
  beql  $t4, $zero, .L7F083E24
   lw    $t8, 0x1bc($sp)
  jal   advance_through_inventory
   nop   
  lw    $t8, 0x1bc($sp)
.L7F083E24:
  beql  $t8, $zero, .L7F083E3C
   lw    $t7, 0x1b8($sp)
  lw    $t6, ($s0)
  b     .L7F083E50
   sw    $zero, 0x430($t6)
  lw    $t7, 0x1b8($sp)
.L7F083E3C:
  beql  $t7, $zero, .L7F083E54
   lw    $t3, ($s0)
  lw    $t2, ($s0)
  li    $t9, 2
  sw    $t9, 0x430($t2)
.L7F083E50:
  lw    $t3, ($s0)
.L7F083E54:
  lw    $v0, 0x430($t3)
  bnezl $v0, .L7F083F64
   li    $at, 2
  jal   sub_GAME_7F067AA4
   move  $a0, $zero
  lw    $t5, 0x148($sp)
  beql  $t5, $zero, .L7F083EC4
   lw    $t7, ($s0)
  jal   redirect_get_BONDdata_autoaim_x
   nop   
  beql  $v0, $zero, .L7F083EC4
   lw    $t7, ($s0)
  lw    $t4, ($s0)
  lw    $t8, 0x140($t4)
  beql  $t8, $zero, .L7F083EC4
   lw    $t7, ($s0)
  jal   get_item_in_hand
   move  $a0, $zero
  move  $a0, $v0
  jal   check_special_attributes
   li    $a1, 8
  beql  $v0, $zero, .L7F083EC4
   lw    $t7, ($s0)
  lw    $t6, ($s0)
  lwc1  $f4, 0x13c($t6)
  b     .L7F083ED8
   swc1  $f4, 0x70($sp)
  lw    $t7, ($s0)
.L7F083EC4:
  lui   $at, %hi(D_80055160)
  lwc1  $f8, %lo(D_80055160)($at)
  lwc1  $f6, 0x14c($t7)
  mul.s $f18, $f6, $f8
  swc1  $f18, 0x70($sp)
.L7F083ED8:
  lw    $t9, 0x148($sp)
  beql  $t9, $zero, .L7F083F30
   lw    $t4, ($s0)
  jal   redirect_get_BONDdata_autoaim_y
   nop   
  beql  $v0, $zero, .L7F083F30
   lw    $t4, ($s0)
  lw    $t2, ($s0)
  lw    $t3, 0x130($t2)
  beql  $t3, $zero, .L7F083F30
   lw    $t4, ($s0)
  jal   get_item_in_hand
   move  $a0, $zero
  move  $a0, $v0
  jal   check_special_attributes
   li    $a1, 8
  beql  $v0, $zero, .L7F083F30
   lw    $t4, ($s0)
  lw    $t5, ($s0)
  b     .L7F083F48
   lwc1  $f14, 0x12c($t5)
  lw    $t4, ($s0)
.L7F083F30:
  lui   $at, %hi(D_80055164)
  lwc1  $f6, %lo(D_80055164)($at)
  lwc1  $f10, 0x160($t4)
  neg.s $f4, $f10
  mul.s $f14, $f4, $f6
  nop   
.L7F083F48:
  lui   $a2, (0x3F5C28F6 >> 16) # lui $a2, 0x3f5c
  ori   $a2, (0x3F5C28F6 & 0xFFFF) # ori $a2, $a2, 0x28f6
  jal   sub_GAME_7F067F58
   lwc1  $f12, 0x70($sp)
  b     .L7F083FB8
   lw    $ra, 0x3c($sp)
  li    $at, 2
.L7F083F64:
  bnel  $v0, $at, .L7F083FB8
   lw    $ra, 0x3c($sp)
  jal   sub_GAME_7F067AA4
   move  $a0, $zero
  lw    $t8, 0x134($sp)
  lw    $t6, 0x130($sp)
  lui   $at, %hi(D_80055168)
  mtc1  $t8, $f8
  mtc1  $t6, $f4
  lwc1  $f0, %lo(D_80055168)($at)
  cvt.s.w $f18, $f8
  li    $at, 0x42A00000 # 80.000000
  mtc1  $at, $f2
  cvt.s.w $f6, $f4
  mul.s $f10, $f18, $f0
  nop   
  mul.s $f8, $f6, $f0
  div.s $f12, $f10, $f2
  jal   sub_GAME_7F067FBC
   div.s $f14, $f8, $f2
  lw    $ra, 0x3c($sp)
.L7F083FB8:
  ldc1  $f20, 0x30($sp)
  lw    $s0, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x1c0
");

#ifdef VERSION_US
asm(R"
glabel sub_GAME_7F083FC8
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lw    $v1, 0xf4($v0)
  bltzl $v1, .L7F084204
   lw    $v1, 0xf8($v0)
  bnez  $v1, .L7F08406C
   li    $a0, 8
  jal   set_unset_ammo_on_screen_setting
   move  $a1, $zero
  li    $a0, 16
  jal   set_unset_bitflags
   move  $a1, $zero
  jal   set_flags_in_BONDdata_stationary_intro_cam
   li    $a0, 4
  jal   sub_GAME_7F08A944
   li    $a0, 4
  li    $a0, 8
  jal   set_unset_clock_lock_bits
   move  $a1, $zero
  jal   get_BONDdata_watch_health
   nop   
  li    $at, 0x41000000 # 8.000000
  mtc1  $at, $f4
  lui   $v1, %hi(pPlayer)
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  mul.s $f6, $f0, $f4
  lw    $t8, ($v1)
  li    $t1, 7
  trunc.w.s $f8, $f6
  mfc1  $t7, $f8
  nop   
  sw    $t7, 0x29d4($t8)
  lw    $v0, ($v1)
  lw    $t9, 0x29d4($v0)
  slti  $at, $t9, 8
  bnezl $at, .L7F084070
   lw    $t2, 0x29d4($v0)
  sw    $t1, 0x29d4($v0)
  lw    $v0, ($v1)
.L7F08406C:
  lw    $t2, 0x29d4($v0)
.L7F084070:
  lui   $t4, %hi(D_80036634) 
  addiu $t4, %lo(D_80036634) # addiu $t4, $t4, 0x6634
  sll   $t3, $t2, 2
  subu  $t3, $t3, $t2
  sll   $t3, $t3, 2
  subu  $t3, $t3, $t2
  sll   $t3, $t3, 2
  addu  $t0, $t3, $t4
  lw    $t5, 8($t0)
  lw    $v1, 0xf4($v0)
  slt   $at, $t5, $v1
  beql  $at, $zero, .L7F0840C0
   lw    $t7, 0xd8($v0)
  lw    $t6, 0x18($t0)
  li    $a0, 255
  li    $a1, 255
  slt   $at, $t6, $v1
  bnez  $at, .L7F0841A0
   li    $t6, -1
  lw    $t7, 0xd8($v0)
.L7F0840C0:
  bnezl $t7, .L7F084168
   lw    $t1, 0x1c8($v0)
  lw    $a0, 0x10($t0)
  slt   $at, $v1, $a0
  bnezl $at, .L7F084168
   lw    $t1, 0x1c8($v0)
  lw    $a2, 0x18($t0)
  slt   $at, $a2, $v1
  bnezl $at, .L7F084168
   lw    $t1, 0x1c8($v0)
  lw    $a1, 0x14($t0)
  subu  $v0, $v1, $a0
  subu  $a3, $a2, $a0
  slt   $at, $v0, $a1
  beqz  $at, .L7F084120
   subu  $t8, $a3, $v0
  mtc1  $v0, $f16
  lwc1  $f10, 0x1c($t0)
  mtc1  $a1, $f6
  cvt.s.w $f18, $f16
  cvt.s.w $f8, $f6
  mul.s $f4, $f10, $f18
  b     .L7F084144
   div.s $f0, $f4, $f8
.L7F084120:
  mtc1  $t8, $f10
  lwc1  $f16, 0x1c($t0)
  subu  $t9, $a3, $a1
  cvt.s.w $f18, $f10
  mtc1  $t9, $f4
  nop   
  cvt.s.w $f8, $f4
  mul.s $f6, $f16, $f18
  div.s $f0, $f6, $f8
.L7F084144:
  mfc1  $a3, $f0
  lw    $a0, 0x20($t0)
  lw    $a1, 0x24($t0)
  jal   set_rgba_tint
   lw    $a2, 0x28($t0)
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lw    $v1, 0xf4($v0)
  lw    $t1, 0x1c8($v0)
.L7F084168:
  lui   $t2, %hi(clock_timer) 
  lui   $t4, %hi(D_80048498) 
  bnez  $t1, .L7F084188
   nop   
  lw    $t2, %lo(clock_timer)($t2)
  addu  $t3, $v1, $t2
  b     .L7F084194
   sw    $t3, 0xf4($v0)
.L7F084188:
  lw    $t4, %lo(D_80048498)($t4)
  addu  $t5, $v1, $t4
  sw    $t5, 0xf4($v0)
.L7F084194:
  lui   $v0, %hi(pPlayer)
  b     .L7F084200
   lw    $v0, %lo(pPlayer)($v0)
.L7F0841A0:
  sw    $t6, 0xf4($v0)
  li    $a2, 255
  jal   set_rgba_tint
   li    $a3, 0
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  li    $a0, 8
  lw    $t7, 0xd8($v0)
  bnezl $t7, .L7F084204
   lw    $v1, 0xf8($v0)
  jal   set_unset_ammo_on_screen_setting
   li    $a1, 1
  li    $a0, 16
  jal   set_unset_bitflags
   li    $a1, 1
  jal   unset_flags_in_BONDdata_stationary_intro_cam
   li    $a0, 4
  jal   sub_GAME_7F08A928
   li    $a0, 4
  li    $a0, 8
  jal   set_unset_clock_lock_bits
   li    $a1, 1
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
.L7F084200:
  lw    $v1, 0xf8($v0)
.L7F084204:
  bltzl $v1, .L7F084354
   lw    $ra, 0x14($sp)
  bnezl $v1, .L7F08426C
   lw    $t4, 0xd8($v0)
  jal   get_BONDdata_watch_health
   nop   
  li    $at, 0x41000000 # 8.000000
  mtc1  $at, $f10
  lui   $t1, %hi(pPlayer) 
  lw    $t1, %lo(pPlayer)($t1)
  mul.s $f16, $f0, $f10
  lui   $v0, %hi(pPlayer)
  li    $t3, 7
  trunc.w.s $f18, $f16
  mfc1  $t9, $f18
  nop   
  sw    $t9, 0x29b8($t1)
  lw    $v0, %lo(pPlayer)($v0)
  lw    $t2, 0x29b8($v0)
  slti  $at, $t2, 8
  bnezl $at, .L7F08426C
   lw    $t4, 0xd8($v0)
  sw    $t3, 0x29b8($v0)
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lw    $t4, 0xd8($v0)
.L7F08426C:
  lui   $t7, %hi(D_80036794) 
  li    $t8, -1
  bnezl $t4, .L7F084350
   sw    $t8, 0xf8($v0)
  lw    $t5, 0x29b8($v0)
  addiu $t7, %lo(D_80036794) # addiu $t7, $t7, 0x6794
  lw    $v1, 0xf8($v0)
  sll   $t6, $t5, 2
  subu  $t6, $t6, $t5
  sll   $t6, $t6, 2
  addu  $a0, $t6, $t7
  lw    $a1, ($a0)
  slt   $at, $v1, $a1
  bnezl $at, .L7F0842F4
   slt   $at, $v1, $a1
  lw    $t8, 4($a0)
  slt   $at, $t8, $v1
  bnezl $at, .L7F0842F4
   slt   $at, $v1, $a1
  lwc1  $f4, 0xe4($v0)
  lui   $t1, %hi(clock_timer) 
  swc1  $f4, 0xec($v0)
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lwc1  $f6, 0xe8($v0)
  swc1  $f6, 0xf0($v0)
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lw    $t1, %lo(clock_timer)($t1)
  lw    $t9, 0xf8($v0)
  addu  $t2, $t9, $t1
  b     .L7F084350
   sw    $t2, 0xf8($v0)
  slt   $at, $v1, $a1
.L7F0842F4:
  bnez  $at, .L7F084344
   li    $t7, -1
  lw    $t3, 8($a0)
  slt   $at, $t3, $v1
  bnez  $at, .L7F084344
   nop   
  lwc1  $f8, 0xdc($v0)
  lui   $t5, %hi(clock_timer) 
  swc1  $f8, 0xec($v0)
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lwc1  $f10, 0xe0($v0)
  swc1  $f10, 0xf0($v0)
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lw    $t5, %lo(clock_timer)($t5)
  lw    $t4, 0xf8($v0)
  addu  $t6, $t4, $t5
  b     .L7F084350
   sw    $t6, 0xf8($v0)
.L7F084344:
  b     .L7F084350
   sw    $t7, 0xf8($v0)
  sw    $t8, 0xf8($v0)
.L7F084350:
  lw    $ra, 0x14($sp)
.L7F084354:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

#ifdef VERSION_JP
asm(R"
glabel sub_GAME_7F083FC8
  lui   $v0, %hi(pPlayer) # $v0, 0x8008
  lw    $v0, %lo(pPlayer)($v0)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  mtc1  $zero, $f4
  lwc1  $f0, 0xf4($v0)
  c.le.s $f4, $f0
  nop   
  bc1fl .Ljp7F08483C
   lwc1  $f0, 0xf8($v0)
  mtc1  $zero, $f6
  li    $a0, 8
  c.eq.s $f6, $f0
  nop   
  bc1fl .Ljp7F0846B0
   lw    $t0, 0xd8($v0)
  jal   set_unset_ammo_on_screen_setting
   move  $a1, $zero
  li    $a0, 16
  jal   set_unset_bitflags
   move  $a1, $zero
  jal   set_flags_in_BONDdata_stationary_intro_cam
   li    $a0, 4
  jal   sub_GAME_7F08A944
   li    $a0, 4
  li    $a0, 8
  jal   set_unset_clock_lock_bits
   move  $a1, $zero
  jal   get_BONDdata_watch_health
   nop   
  li    $at, 0x41000000 # 8.000000
  mtc1  $at, $f8
  lui   $a0, %hi(pPlayer) # $a0, 0x8008
  addiu $a0, %lo(pPlayer) # addiu $a0, $a0, -0x5ee0
  mul.s $f10, $f0, $f8
  lw    $t8, ($a0)
  li    $t9, 7
  trunc.w.s $f4, $f10
  mfc1  $t7, $f4
  nop   
  sw    $t7, 0x29d4($t8)
  lw    $v0, ($a0)
  lw    $v1, 0x29d4($v0)
  slti  $at, $v1, 8
  bnez  $at, .Ljp7F08469C
   nop   
  sw    $t9, 0x29d4($v0)
  lw    $v0, ($a0)
  lw    $v1, 0x29d4($v0)
.Ljp7F08469C:
  bgezl $v1, .Ljp7F0846B0
   lw    $t0, 0xd8($v0)
  sw    $zero, 0x29d4($v0)
  lw    $v0, ($a0)
  lw    $t0, 0xd8($v0)
.Ljp7F0846B0:
  lui   $t3, %hi(D_80036634) # $t3, 0x8003
  li    $at, 0xBF800000 # -1.000000
  bnez  $t0, .Ljp7F0847D0
   li    $a0, 255
  lw    $t1, 0x29d4($v0)
  addiu $t3, %lo(D_80036634) # addiu $t3, $t3, 0x6674
  lwc1  $f0, 0xf4($v0)
  sll   $t2, $t1, 2
  subu  $t2, $t2, $t1
  sll   $t2, $t2, 2
  subu  $t2, $t2, $t1
  sll   $t2, $t2, 2
  addu  $v1, $t2, $t3
  lwc1  $f6, 8($v1)
  c.le.s $f0, $f6
  nop   
  bc1tl .Ljp7F084710
   lwc1  $f2, 0x10($v1)
  lwc1  $f8, 0x18($v1)
  c.le.s $f0, $f8
  nop   
  bc1fl .Ljp7F0847D4
   mtc1  $at, $f6
  lwc1  $f2, 0x10($v1)
.Ljp7F084710:
  c.le.s $f2, $f0
  nop   
  bc1fl .Ljp7F084798
   lw    $t4, 0x1c8($v0)
  lwc1  $f16, 0x18($v1)
  c.le.s $f0, $f16
  nop   
  bc1fl .Ljp7F084798
   lw    $t4, 0x1c8($v0)
  sub.s $f12, $f0, $f2
  lwc1  $f14, 0x14($v1)
  sub.s $f18, $f16, $f2
  c.lt.s $f12, $f14
  nop   
  bc1fl .Ljp7F084764
   sub.s $f8, $f18, $f12
  lwc1  $f10, 0x1c($v1)
  mul.s $f4, $f10, $f12
  b     .Ljp7F084774
   div.s $f0, $f4, $f14
  sub.s $f8, $f18, $f12
.Ljp7F084764:
  lwc1  $f6, 0x1c($v1)
  sub.s $f4, $f18, $f14
  mul.s $f10, $f6, $f8
  div.s $f0, $f10, $f4
.Ljp7F084774:
  mfc1  $a3, $f0
  lw    $a0, 0x20($v1)
  lw    $a1, 0x24($v1)
  jal   set_rgba_tint
   lw    $a2, 0x28($v1)
  lui   $v0, %hi(pPlayer) # $v0, 0x8008
  lw    $v0, %lo(pPlayer)($v0)
  lwc1  $f0, 0xf4($v0)
  lw    $t4, 0x1c8($v0)
.Ljp7F084798:
  lui    $at, %hi(jpD_800484D0) # -0.000000
  bnez  $t4, .Ljp7F0847B8
   nop   
  lui    $at, %hi(global_timer_delta) # -0.000000
  lwc1  $f6, %lo(global_timer_delta)($at)
  add.s $f8, $f0, $f6
  b     .Ljp7F0847C4
   swc1  $f8, 0xf4($v0)
.Ljp7F0847B8:
  lwc1  $f10, %lo(jpD_800484D0)($at)
  add.s $f4, $f0, $f10
  swc1  $f4, 0xf4($v0)
.Ljp7F0847C4:
  lui   $v0, %hi(pPlayer) # $v0, 0x8008
  b     .Ljp7F084838
   lw    $v0, %lo(pPlayer)($v0)
.Ljp7F0847D0:
  mtc1  $at, $f6
.Ljp7F0847D4:
  li    $a1, 255
  li    $a2, 255
  li    $a3, 0
  jal   set_rgba_tint
   swc1  $f6, 0xf4($v0)
  lui   $v0, %hi(pPlayer) # $v0, 0x8008
  lw    $v0, %lo(pPlayer)($v0)
  li    $a0, 8
  lw    $t5, 0xd8($v0)
  bnezl $t5, .Ljp7F08483C
   lwc1  $f0, 0xf8($v0)
  jal   set_unset_ammo_on_screen_setting
   li    $a1, 1
  li    $a0, 16
  jal   set_unset_bitflags
   li    $a1, 1
  jal   unset_flags_in_BONDdata_stationary_intro_cam
   li    $a0, 4
  jal   sub_GAME_7F08A928
   li    $a0, 4
  li    $a0, 8
  jal   set_unset_clock_lock_bits
   li    $a1, 1
  lui   $v0, %hi(pPlayer) # $v0, 0x8008
  lw    $v0, %lo(pPlayer)($v0)
.Ljp7F084838:
  lwc1  $f0, 0xf8($v0)
.Ljp7F08483C:
  mtc1  $zero, $f8
  nop   
  c.le.s $f8, $f0
  nop   
  bc1fl .Ljp7F084A04
   lw    $ra, 0x14($sp)
  mtc1  $zero, $f10
  nop   
  c.eq.s $f10, $f0
  nop   
  bc1fl .Ljp7F0848DC
   lw    $t0, 0xd8($v0)
  jal   get_BONDdata_watch_health
   nop   
  li    $at, 0x41000000 # 8.000000
  mtc1  $at, $f4
  lui   $t8, %hi(pPlayer) # $t8, 0x8008
  lw    $t8, %lo(pPlayer)($t8)
  mul.s $f6, $f0, $f4
  lui   $v0, %hi(pPlayer) # $v0, 0x8008
  li    $t9, 7
  trunc.w.s $f8, $f6
  mfc1  $t7, $f8
  nop   
  sw    $t7, 0x29b8($t8)
  lw    $v0, %lo(pPlayer)($v0)
  lw    $v1, 0x29b8($v0)
  slti  $at, $v1, 8
  bnez  $at, .Ljp7F0848C4
   nop   
  sw    $t9, 0x29b8($v0)
  lui   $v0, %hi(pPlayer) # $v0, 0x8008
  lw    $v0, %lo(pPlayer)($v0)
  lw    $v1, 0x29b8($v0)
.Ljp7F0848C4:
  bgezl $v1, .Ljp7F0848DC
   lw    $t0, 0xd8($v0)
  sw    $zero, 0x29b8($v0)
  lui   $v0, %hi(pPlayer) # $v0, 0x8008
  lw    $v0, %lo(pPlayer)($v0)
  lw    $t0, 0xd8($v0)
.Ljp7F0848DC:
  li    $at, 0xBF800000 # -1.000000
  bnezl $t0, .Ljp7F0849F8
   mtc1  $at, $f10
  lw    $t1, 0x29b8($v0)
  lui   $t3, %hi(D_80036794) # $t3, 0x8003
  addiu $t3, %lo(D_80036794) # addiu $t3, $t3, 0x67d4
  sll   $t2, $t1, 2
  subu  $t2, $t2, $t1
  sll   $t2, $t2, 2
  addu  $v1, $t2, $t3
  lw    $t4, ($v1)
  lwc1  $f0, 0xf8($v0)
  mtc1  $t4, $f10
  nop   
  cvt.s.w $f2, $f10
  c.le.s $f2, $f0
  nop   
  bc1fl .Ljp7F084984
   c.le.s $f2, $f0
  lw    $t5, 4($v1)
  mtc1  $t5, $f4
  nop   
  cvt.s.w $f6, $f4
  c.le.s $f0, $f6
  nop   
  bc1fl .Ljp7F084984
   c.le.s $f2, $f0
  lwc1  $f8, 0xe4($v0)
  lui    $at, %hi(global_timer_delta)
  swc1  $f8, 0xec($v0)
  lui   $v0, %hi(pPlayer) # $v0, 0x8008
  lw    $v0, %lo(pPlayer)($v0)
  lwc1  $f10, 0xe8($v0)
  swc1  $f10, 0xf0($v0)
  lui   $v0, %hi(pPlayer) # $v0, 0x8008
  lw    $v0, %lo(pPlayer)($v0)
  lwc1  $f6, %lo(global_timer_delta)($at)
  lwc1  $f4, 0xf8($v0)
  add.s $f8, $f4, $f6
  b     .Ljp7F084A00
   swc1  $f8, 0xf8($v0)
  c.le.s $f2, $f0
.Ljp7F084984:
  li    $at, 0xBF800000 # -1.000000
  bc1fl .Ljp7F0849EC
   mtc1  $at, $f8
  lw    $t6, 8($v1)
  mtc1  $t6, $f10
  nop   
  cvt.s.w $f4, $f10
  c.le.s $f0, $f4
  nop   
  bc1fl .Ljp7F0849EC
   mtc1  $at, $f8
  lwc1  $f6, 0xdc($v0)
  lui    $at, %hi(global_timer_delta) 
  swc1  $f6, 0xec($v0)
  lui   $v0, %hi(pPlayer) # $v0, 0x8008
  lw    $v0, %lo(pPlayer)($v0)
  lwc1  $f8, 0xe0($v0)
  swc1  $f8, 0xf0($v0)
  lui   $v0, %hi(pPlayer) # $v0, 0x8008
  lw    $v0, %lo(pPlayer)($v0)
  lwc1  $f4, %lo(global_timer_delta)($at)
  lwc1  $f10, 0xf8($v0)
  add.s $f6, $f10, $f4
  b     .Ljp7F084A00
   swc1  $f6, 0xf8($v0)
  mtc1  $at, $f8
.Ljp7F0849EC:
  b     .Ljp7F084A00
   swc1  $f8, 0xf8($v0)
  mtc1  $at, $f10
.Ljp7F0849F8:
  nop   
  swc1  $f10, 0xf8($v0)
.Ljp7F084A00:
  lw    $ra, 0x14($sp)
.Ljp7F084A04:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");
#endif

#endif




asm(R"
glabel sub_GAME_7F084360
  lui   $a0, %hi(dword_CODE_bss_800799A0)
  addiu $a0, %lo(dword_CODE_bss_800799A0) # addiu $a0, $a0, -0x6660
  lw    $t6, ($a0)
  lui   $t8, %hi(D_80036444) 
  addiu $sp, $sp, -0x40
  addiu $t7, $t6, 1
  sw    $t7, ($a0)
  lw    $t8, %lo(D_80036444)($t8)
  sw    $ra, 0x24($sp)
  lui   $t9, %hi(disable_player_pickups_flag) 
  beql  $t8, $zero, .L7F08463C
   lw    $ra, 0x24($sp)
  lw    $t9, %lo(disable_player_pickups_flag)($t9)
  lui   $t0, %hi(dword_CODE_bss_8007999C) 
  lui   $t1, %hi(global_timer) 
  bnezl $t9, .L7F08463C
   lw    $ra, 0x24($sp)
  lw    $t0, %lo(dword_CODE_bss_8007999C)($t0)
  lw    $t1, %lo(global_timer)($t1)
  lui   $v0, %hi(pPlayer)
  slt   $at, $t0, $t1
  beql  $at, $zero, .L7F08463C
   lw    $ra, 0x24($sp)
  lw    $v0, %lo(pPlayer)($v0)
  move  $v1, $t7
  li    $at, 1
  lw    $t2, 0xa8($v0)
  lwc1  $f4, 8($t2)
  swc1  $f4, 0x34($sp)
  lw    $t3, 0xa8($v0)
  lwc1  $f6, 0xc($t3)
  swc1  $f6, 0x38($sp)
  lw    $t4, 0xa8($v0)
  lwc1  $f8, 0x10($t4)
  swc1  $f8, 0x3c($sp)
  bgez  $v1, .L7F084400
   andi  $t5, $v1, 3
  beqz  $t5, .L7F084400
   nop   
  addiu $t5, $t5, -4
.L7F084400:
  beqz  $t5, .L7F084428
   nop   
  beq   $t5, $at, .L7F084480
   li    $at, 2
  beq   $t5, $at, .L7F0844D8
   li    $at, 3
  beq   $t5, $at, .L7F084530
   nop   
  b     .L7F084584
   nop   
.L7F084428:
  jal   get_random_value
   nop   
  mtc1  $v0, $f10
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F08444C
   cvt.s.w $f16, $f10
  mtc1  $at, $f18
  nop   
  add.s $f16, $f16, $f18
.L7F08444C:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f4
  li    $at, 0x43160000 # 150.000000
  mtc1  $at, $f8
  mul.s $f6, $f16, $f4
  li    $at, 0x437A0000 # 250.000000
  mtc1  $at, $f18
  lwc1  $f4, 0x34($sp)
  mul.s $f10, $f8, $f6
  add.s $f16, $f18, $f10
  add.s $f8, $f4, $f16
  b     .L7F084584
   swc1  $f8, 0x34($sp)
.L7F084480:
  jal   get_random_value
   nop   
  mtc1  $v0, $f6
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F0844A4
   cvt.s.w $f18, $f6
  mtc1  $at, $f10
  nop   
  add.s $f18, $f18, $f10
.L7F0844A4:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f4
  li    $at, 0x43160000 # 150.000000
  mtc1  $at, $f8
  mul.s $f16, $f18, $f4
  li    $at, 0x437A0000 # 250.000000
  mtc1  $at, $f10
  lwc1  $f4, 0x34($sp)
  mul.s $f6, $f8, $f16
  add.s $f18, $f10, $f6
  sub.s $f8, $f4, $f18
  b     .L7F084584
   swc1  $f8, 0x34($sp)
.L7F0844D8:
  jal   get_random_value
   nop   
  mtc1  $v0, $f16
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F0844FC
   cvt.s.w $f10, $f16
  mtc1  $at, $f6
  nop   
  add.s $f10, $f10, $f6
.L7F0844FC:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f4
  li    $at, 0x43160000 # 150.000000
  mtc1  $at, $f8
  mul.s $f18, $f10, $f4
  li    $at, 0x437A0000 # 250.000000
  mtc1  $at, $f6
  lwc1  $f4, 0x3c($sp)
  mul.s $f16, $f8, $f18
  add.s $f10, $f6, $f16
  add.s $f8, $f4, $f10
  b     .L7F084584
   swc1  $f8, 0x3c($sp)
.L7F084530:
  jal   get_random_value
   nop   
  mtc1  $v0, $f18
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F084554
   cvt.s.w $f6, $f18
  mtc1  $at, $f16
  nop   
  add.s $f6, $f6, $f16
.L7F084554:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f4
  li    $at, 0x43160000 # 150.000000
  mtc1  $at, $f8
  mul.s $f10, $f6, $f4
  li    $at, 0x437A0000 # 250.000000
  mtc1  $at, $f16
  lwc1  $f4, 0x3c($sp)
  mul.s $f18, $f8, $f10
  add.s $f6, $f16, $f18
  sub.s $f8, $f4, $f6
  swc1  $f8, 0x3c($sp)
.L7F084584:
  jal   get_random_value
   nop   
  mtc1  $v0, $f10
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F0845A8
   cvt.s.w $f16, $f10
  mtc1  $at, $f18
  nop   
  add.s $f16, $f16, $f18
.L7F0845A8:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f4
  li    $at, 0x43480000 # 200.000000
  mtc1  $at, $f8
  mul.s $f6, $f16, $f4
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f18
  lwc1  $f4, 0x38($sp)
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  move  $a0, $zero
  mul.s $f10, $f8, $f6
  addiu $a1, $sp, 0x34
  li    $a3, 18
  sub.s $f16, $f10, $f18
  add.s $f8, $f4, $f16
  swc1  $f8, 0x38($sp)
  lw    $v1, 0xa8($t6)
  lw    $a2, 0x14($v1)
  addiu $t7, $v1, 0x2c
  sw    $t7, 0x18($sp)
  sw    $zero, 0x1c($sp)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F09C250
   sw    $zero, 0x10($sp)
  jal   get_random_value
   nop   
  li    $at, 15
  divu  $zero, $v0, $at
  lui   $t9, %hi(global_timer) 
  lw    $t9, %lo(global_timer)($t9)
  mfhi  $t8
  lui   $at, %hi(dword_CODE_bss_8007999C)
  addu  $t0, $t8, $t9
  addiu $t1, $t0, 0xf
  sw    $t1, %lo(dword_CODE_bss_8007999C)($at)
  lw    $ra, 0x24($sp)
.L7F08463C:
  addiu $sp, $sp, 0x40
  jr    $ra
   nop   
");

#ifdef VERSION_US
asm(R"
.late_rodata
glabel D_8005516C
.word 0x3d888889 /*0.06666667*/
glabel D_80055170
.word 0x40c90fdb /*6.2831855*/
glabel D_80055174
.word 0x3c8efa35 /*0.017453292*/
glabel D_80055178
.word 0x3f8147ae  /*1.01*/
glabel D_8005517C
.word 0x3f8147ae  /*1.01*/
glabel D_80055180
.word 0x40c90fdb /*6.2831855*/
glabel D_80055184
.word 0x3c8efa35 /*0.017453292*/
glabel D_80055188
.word 0x40490fdb /*3.1415927*/
glabel D_8005518C
.word 0x40c90fdb /*6.2831855*/
glabel D_80055190
.word 0xc0490fdb /*-3.1415927*/
glabel D_80055194
.word 0x40c90fdb /*6.2831855*/
glabel D_80055198
.word 0x3f6b851f /*0.92000002*/
glabel D_8005519C
.word 0x3da3d708 /*0.079999983*/
glabel D_800551A0
.word 0x40c90fdb /*6.2831855*/
glabel D_800551A4
.word 0x3f6b851f /*0.92000002*/
glabel D_800551A8
.word 0x3f6b851f /*0.92000002*/
glabel D_800551AC
.word 0x3da3d708 /*0.079999983*/
glabel D_800551B0
.word 0x3f6b851f /*0.92000002*/
glabel D_800551B4
.word 0x3f6b851f /*0.92000002*/
glabel D_800551B8
.word 0x3f6b851f /*0.92000002*/
glabel D_800551BC
.word 0x40c90fdb /*6.2831855*/
glabel D_800551C0
.word 0x3f6b851f /*0.92000002*/
glabel D_800551C4
.word 0x3f6b851f /*0.92000002*/
glabel D_800551C8
.word 0x3f6b851f /*0.92000002*/
glabel D_800551CC
.word 0x3f6b851f /*0.92000002*/
glabel D_800551D0
.word 0x3da3d708 /*0.079999983*/
glabel D_800551D4
.word 0x3c8efa35 /*0.017453292*/
glabel D_800551D8
.word 0x40c90fdb /*6.2831855*/
glabel D_800551DC
.word 0x40c90fdb /*6.2831855*/
glabel D_800551E0
.word 0x40c90fdb /*6.2831855*/
glabel D_800551E4
.word 0x40c90fdb /*6.2831855*/
glabel D_800551E8
.word 0x3e99999a /*0.30000001*/
glabel D_800551EC
.word 0x3e19999a /*0.15000001*/
glabel D_800551F0
.word 0x469c4000 /*20000.0*/
glabel D_800551F4
.word 0x3f666666 /*0.89999998*/
glabel D_800551F8
.word 0x46477c00 /*12767.0*/
glabel D_800551FC
.word 0x469c4000 /*20000.0*/
glabel D_80055200
.word 0x3f666666 /*0.89999998*/
glabel D_80055204
.word 0x45f2b800 /*7767.0*/
glabel D_80055208
.word 0x3f666666 /*0.89999998*/
glabel D_8005520C
.word 0x46c35000 /*25000.0;*/
glabel D_80055210
.word 0x3e32b8c3 /*0.17453294*/
glabel D_80055214
.word 0x3edf66f3 /*0.43633232*/
glabel D_80055218
.word 0xbdb2b8c3 /*-0.087266468*/
glabel D_8005521C
.word 0x3f70a3d7 /*0.94*/
glabel D_80055220
.word 0x3d75c290 /*0.060000002*/
glabel D_80055224
.word 0x4528c000 /*2700.0*/
glabel D_80055228
.word 0x40c90fdb /*6.2831855*/
glabel D_8005522C
.word 0x40c90fdb /*6.2831855*/
glabel D_80055230
.word 0x3f19999a /*0.60000002*/
glabel D_80055234
.word 0x3f4ccccd /*0.80000001*/
glabel D_80055238
.word 0x3dcccccd /*0.1*/
glabel D_8005523C
.word 0x4528c000 /*2700.0*/
glabel D_80055240
.word 0x3f947ae1 /*1.16*/
glabel D_80055244
.word 0x3f8147ae  /*1.01*/
glabel D_80055248
.word 0x3f7d7721 /*0.99009901*/
glabel D_8005524C
.word 0x3f333333 /*0.69999999*/
glabel D_80055250
.word 0x3f99999a /*1.2*/
glabel D_80055254
.word 0x3c8efa35 /*0.017453292*/
glabel D_80055258
.word 0x40c90fdb /*6.2831855*/
glabel D_8005525C
.word 0x3f547ae1 /*0.82999998*/
glabel D_80055260
.word 0x3e2e147c /*0.17000002*/
.text
glabel MoveBond
  addiu $sp, $sp, -0x3b8
  lui   $t6, %hi(D_800367F4) 
  sw    $ra, 0x2c($sp)
  sw    $s1, 0x28($sp)
  sw    $s0, 0x24($sp)
  sdc1  $f20, 0x18($sp)
  sw    $a0, 0x3b8($sp)
  sw    $a1, 0x3bc($sp)
  sw    $a2, 0x3c0($sp)
  sw    $a3, 0x3c4($sp)
  addiu $t6, %lo(D_800367F4) # addiu $t6, $t6, 0x67f4
  lw    $at, ($t6)
  addiu $t5, $sp, 0x3ac
  lw    $t7, 4($t6)
  sw    $at, ($t5)
  lw    $at, 8($t6)
  mtc1  $zero, $f20
  sll   $s0, $a0, 0x18
  sw    $at, 8($t5)
  sra   $t4, $s0, 0x18
  sw    $t7, 4($t5)
  slti  $at, $t4, 0x64
  move  $s0, $t4
  sw    $zero, 0x394($sp)
  swc1  $f20, 0x398($sp)
  beqz  $at, .L7F0846C0
   swc1  $f20, 0x390($sp)
  slti  $at, $t4, -0x63
  beql  $at, $zero, .L7F0846CC
   lb    $t3, 0x3bf($sp)
.L7F0846C0:
  jal   return_null
   nop   
  lb    $t3, 0x3bf($sp)
.L7F0846CC:
  slti  $at, $t3, 0x64
  beqz  $at, .L7F0846E0
   slti  $at, $t3, -0x63
  beqz  $at, .L7F0846E8
   nop   
.L7F0846E0:
  jal   return_null
   nop   
.L7F0846E8:
  lui   $v1, %hi(camera_80036424)
  addiu $v1, %lo(camera_80036424) # addiu $v1, $v1, 0x6424
  lw    $v0, ($v1)
  blez  $v0, .L7F08474C
   addiu $t8, $v0, 1
  slti  $at, $t8, 4
  bnez  $at, .L7F08474C
   sw    $t8, ($v1)
  lui   $s1, %hi(pPlayer)
  addiu $s1, %lo(pPlayer) # addiu $s1, $s1, -0x5f50
  lw    $t9, ($s1)
  sw    $zero, ($v1)
  li    $a0, 1
  sw    $zero, 0x2a54($t9)
  lw    $t2, ($s1)
  jal   get_item_in_hand
   sw    $zero, 0x2a50($t2)
  li    $a0, 1
  jal   remove_hands_item
   move  $a1, $v0
  jal   get_item_in_hand
   move  $a0, $zero
  move  $a0, $zero
  jal   remove_hands_item
   move  $a1, $v0
.L7F08474C:
  lui   $s1, %hi(pPlayer)
  addiu $s1, %lo(pPlayer) # addiu $s1, $s1, -0x5f50
  jal   setptrBONDdata
   move  $a0, $zero
  jal   sub_GAME_7F083FC8
   nop   
  jal   sub_GAME_7F084360
   nop   
  sll   $a0, $s0, 0x18
  sra   $t5, $a0, 0x18
  move  $a0, $t5
  lb    $a1, 0x3bf($sp)
  lhu   $a2, 0x3c2($sp)
  jal   controller_gameplay_interaction
   lhu   $a3, 0x3c6($sp)
  jal   get_controls_locked_flag
   nop   
  beql  $v0, $zero, .L7F0847A4
   lw    $t6, ($s1)
  jal   sub_GAME_7F07EAF0
   nop   
  lw    $t6, ($s1)
.L7F0847A4:
  lw    $t7, 0x1c8($t6)
  beqz  $t7, .L7F0847B8
   nop   
  jal   sub_GAME_7F07EC54
   nop   
.L7F0847B8:
  lui   $t3, %hi(in_tank_flag) 
  lw    $t3, %lo(in_tank_flag)($t3)
  bnez  $t3, .L7F08497C
   nop   
  jal   sub_GAME_7F0799F0
   nop   
  bnezl $v0, .L7F084808
   lw    $t0, ($s1)
  lw    $t0, ($s1)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f10
  lwc1  $f4, 0x174($t0)
  mul.s $f6, $f4, $f10
  mtc1  $at, $f4
  swc1  $f6, 0x174($t0)
  lw    $t0, ($s1)
  lwc1  $f8, 0x16c($t0)
  mul.s $f10, $f8, $f4
  swc1  $f10, 0x16c($t0)
  lw    $t0, ($s1)
.L7F084808:
  lwc1  $f18, 0x180($t0)
  c.eq.s $f20, $f18
  nop   
  bc1fl .L7F084834
   lwc1  $f0, 0x188($t0)
  lwc1  $f6, 0x188($t0)
  c.eq.s $f20, $f6
  nop   
  bc1t  .L7F08497C
   nop   
  lwc1  $f0, 0x188($t0)
.L7F084834:
  lwc1  $f2, 0x150($t0)
  lwc1  $f16, 0x154($t0)
  neg.s $f14, $f18
  mul.s $f8, $f0, $f2
  nop   
  mul.s $f4, $f14, $f16
  add.s $f10, $f8, $f4
  mul.s $f6, $f14, $f2
  nop   
  mul.s $f8, $f0, $f16
  swc1  $f10, 0x38c($sp)
  mul.s $f10, $f0, $f0
  sub.s $f4, $f6, $f8
  mul.s $f6, $f18, $f18
  swc1  $f4, 0x388($sp)
  jal   sqrtf
   add.s $f12, $f10, $f6
  lw    $t0, ($s1)
  lwc1  $f4, 0x38c($sp)
  lui   $at, %hi(D_8005516C)
  lwc1  $f8, 0x174($t0)
  lui   $t1, %hi(global_timer_delta) 
  addiu $t1, %lo(global_timer_delta) # addiu $t1, $t1, -0x7c88
  add.s $f10, $f8, $f4
  move  $v1, $zero
  li    $a0, 12
  swc1  $f10, 0x174($t0)
  lw    $t0, ($s1)
  lwc1  $f8, 0x388($sp)
  lwc1  $f6, 0x16c($t0)
  add.s $f4, $f6, $f8
  swc1  $f4, 0x16c($t0)
  lwc1  $f12, %lo(D_8005516C)($at)
  lw    $t8, ($s1)
.L7F0848BC:
  addu  $v0, $t8, $v1
  lwc1  $f2, 0x180($v0)
  c.eq.s $f20, $f2
  nop   
  bc1tl .L7F084974
   addiu $v1, $v1, 4
  c.lt.s $f20, $f2
  nop   
  bc1fl .L7F084928
   c.lt.s $f2, $f20
  lwc1  $f10, ($t1)
  mul.s $f6, $f12, $f10
  nop   
  mul.s $f8, $f6, $f2
  div.s $f4, $f8, $f0
  sub.s $f10, $f2, $f4
  swc1  $f10, 0x180($v0)
  lw    $t4, ($s1)
  addu  $v0, $t4, $v1
  lwc1  $f6, 0x180($v0)
  c.lt.s $f6, $f20
  nop   
  bc1f  .L7F084970
   nop   
  b     .L7F084970
   swc1  $f20, 0x180($v0)
  c.lt.s $f2, $f20
.L7F084928:
  nop   
  bc1fl .L7F084974
   addiu $v1, $v1, 4
  lwc1  $f8, ($t1)
  mul.s $f4, $f12, $f8
  nop   
  mul.s $f10, $f4, $f2
  div.s $f6, $f10, $f0
  sub.s $f8, $f2, $f6
  swc1  $f8, 0x180($v0)
  lw    $t9, ($s1)
  addu  $v0, $t9, $v1
  lwc1  $f4, 0x180($v0)
  c.lt.s $f20, $f4
  nop   
  bc1f  .L7F084970
   nop   
  swc1  $f20, 0x180($v0)
.L7F084970:
  addiu $v1, $v1, 4
.L7F084974:
  bnel  $v1, $a0, .L7F0848BC
   lw    $t8, ($s1)
.L7F08497C:
  lui   $t2, %hi(in_tank_flag) 
  lw    $t2, %lo(in_tank_flag)($t2)
  lui   $t1, %hi(global_timer_delta) 
  li    $at, 1
  addiu $t1, %lo(global_timer_delta) # addiu $t1, $t1, -0x7c88
  bne   $t2, $at, .L7F0851D8
   lw    $t0, ($s1)
  lwc1  $f10, 0x14c($t0)
  lwc1  $f6, ($t1)
  lui   $at, %hi(D_80055170)
  lwc1  $f12, %lo(D_80055170)($at)
  mul.s $f8, $f10, $f6
  lui   $at, %hi(D_80055174)
  lwc1  $f4, %lo(D_80055174)($at)
  li    $at, 0x40600000 # 3.500000
  mtc1  $at, $f6
  lui   $at, %hi(D_80036464)
  addiu $s0, $sp, 0x374
  mul.s $f10, $f8, $f4
  lwc1  $f8, %lo(D_80036464)($at)
  move  $a3, $s0
  addiu $a0, $t0, 0x48c
  addiu $t5, $sp, 0x368
  mul.s $f2, $f10, $f6
  add.s $f0, $f8, $f2
  c.le.s $f12, $f0
  nop   
  bc1fl .L7F0849F8
   c.lt.s $f0, $f20
  sub.s $f0, $f0, $f12
  c.lt.s $f0, $f20
.L7F0849F8:
  nop   
  bc1fl .L7F084A0C
   lw    $a1, 0x488($t0)
  add.s $f0, $f0, $f12
  lw    $a1, 0x488($t0)
.L7F084A0C:
  mfc1  $a2, $f0
  swc1  $f2, 0x358($sp)
  swc1  $f0, 0x35c($sp)
  jal   sub_GAME_7F07CAC8
   sw    $t5, 0x10($sp)
  beql  $v0, $zero, .L7F084A40
   lui   $at, 0xbf80
  lwc1  $f4, 0x35c($sp)
  lui    $at, %hi(D_80036464)
  swc1  $f4, %lo(D_80036464)($at)
  b     .L7F084D64
   lw    $t0, ($s1)
  li    $at, 0xBF800000 # -1.000000
.L7F084A40:
  mtc1  $at, $f10
  mtc1  $at, $f6
  addiu $a0, $sp, 0x348
  addiu $a1, $sp, 0x33c
  swc1  $f10, 0x31c($sp)
  jal   sub_GAME_7F0B28B0
   swc1  $f6, 0x304($sp)
  lwc1  $f8, 0x33c($sp)
  lwc1  $f4, 0x348($sp)
  lwc1  $f10, 0x344($sp)
  lwc1  $f6, 0x350($sp)
  sub.s $f2, $f8, $f4
  sub.s $f14, $f10, $f6
  mul.s $f8, $f2, $f2
  swc1  $f2, 0x338($sp)
  mul.s $f4, $f14, $f14
  swc1  $f14, 0x334($sp)
  jal   sqrtf
   add.s $f12, $f8, $f4
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  lwc1  $f2, 0x338($sp)
  lwc1  $f14, 0x334($sp)
  div.s $f16, $f10, $f0
  lw    $t0, ($s1)
  lwc1  $f10, 0x370($sp)
  mul.s $f2, $f2, $f16
  nop   
  mul.s $f14, $f14, $f16
  neg.s $f12, $f2
  swc1  $f12, 0x320($sp)
  swc1  $f14, 0x324($sp)
  lwc1  $f6, 0x494($t0)
  swc1  $f6, 0x48($sp)
  lwc1  $f4, 0x48($sp)
  lwc1  $f8, 0x48c($t0)
  sub.s $f6, $f4, $f10
  swc1  $f8, 0x44($sp)
  lwc1  $f4, 0x44($sp)
  lwc1  $f10, 0x368($sp)
  mul.s $f8, $f6, $f12
  sub.s $f6, $f4, $f10
  mul.s $f4, $f6, $f14
  add.s $f18, $f8, $f4
  c.lt.s $f18, $f20
  nop   
  bc1f  .L7F084B14
   nop   
  neg.s $f10, $f14
  neg.s $f6, $f12
  neg.s $f18, $f18
  swc1  $f10, 0x324($sp)
  swc1  $f6, 0x320($sp)
.L7F084B14:
  lwc1  $f8, 0x48($sp)
  lwc1  $f4, 0x350($sp)
  lwc1  $f6, 0x320($sp)
  sub.s $f10, $f8, $f4
  lwc1  $f4, 0x44($sp)
  mul.s $f8, $f10, $f6
  lwc1  $f10, 0x348($sp)
  sub.s $f6, $f4, $f10
  lwc1  $f4, 0x324($sp)
  mul.s $f10, $f6, $f4
  add.s $f0, $f8, $f10
  c.lt.s $f0, $f18
  nop   
  bc1fl .L7F084B5C
   lwc1  $f4, 0x368($sp)
  sub.s $f6, $f18, $f0
  swc1  $f6, 0x31c($sp)
  lwc1  $f4, 0x368($sp)
.L7F084B5C:
  lwc1  $f8, 0x374($sp)
  lwc1  $f10, 0x370($sp)
  lwc1  $f6, 0x37c($sp)
  sub.s $f2, $f4, $f8
  sub.s $f14, $f10, $f6
  mul.s $f4, $f2, $f2
  swc1  $f2, 0x338($sp)
  mul.s $f8, $f14, $f14
  swc1  $f14, 0x334($sp)
  jal   sqrtf
   add.s $f12, $f4, $f8
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  lwc1  $f2, 0x338($sp)
  lwc1  $f14, 0x334($sp)
  div.s $f16, $f10, $f0
  lw    $t0, ($s1)
  lwc1  $f10, 0x370($sp)
  mul.s $f2, $f2, $f16
  nop   
  mul.s $f14, $f14, $f16
  neg.s $f12, $f2
  swc1  $f12, 0x308($sp)
  swc1  $f14, 0x30c($sp)
  lwc1  $f6, 0x494($t0)
  swc1  $f6, 0x48($sp)
  lwc1  $f8, 0x48($sp)
  lwc1  $f4, 0x48c($t0)
  sub.s $f6, $f8, $f10
  swc1  $f4, 0x44($sp)
  lwc1  $f8, 0x44($sp)
  lwc1  $f10, 0x368($sp)
  mul.s $f4, $f6, $f12
  sub.s $f6, $f8, $f10
  mul.s $f8, $f6, $f14
  add.s $f18, $f4, $f8
  c.lt.s $f18, $f20
  nop   
  bc1f  .L7F084C10
   nop   
  neg.s $f16, $f14
  neg.s $f10, $f12
  neg.s $f18, $f18
  swc1  $f10, 0x308($sp)
  swc1  $f16, 0x30c($sp)
.L7F084C10:
  lwc1  $f6, 0x48($sp)
  lwc1  $f4, 0x350($sp)
  lwc1  $f12, 0x308($sp)
  lwc1  $f16, 0x30c($sp)
  sub.s $f8, $f6, $f4
  lwc1  $f4, 0x44($sp)
  mul.s $f10, $f8, $f12
  lwc1  $f8, 0x348($sp)
  sub.s $f8, $f4, $f8
  mul.s $f8, $f8, $f16
  add.s $f0, $f10, $f8
  lwc1  $f10, 0x344($sp)
  sub.s $f8, $f6, $f10
  lwc1  $f10, 0x33c($sp)
  mul.s $f6, $f8, $f12
  sub.s $f8, $f4, $f10
  mul.s $f4, $f8, $f16
  add.s $f2, $f6, $f4
  c.lt.s $f2, $f0
  nop   
  bc1fl .L7F084C70
   c.lt.s $f0, $f18
  mov.s $f0, $f2
  c.lt.s $f0, $f18
.L7F084C70:
  nop   
  bc1fl .L7F084C88
   lwc1  $f2, 0x304($sp)
  sub.s $f2, $f18, $f0
  swc1  $f2, 0x304($sp)
  lwc1  $f2, 0x304($sp)
.L7F084C88:
  lwc1  $f10, 0x31c($sp)
  c.le.s $f20, $f2
  nop   
  bc1fl .L7F084CCC
   lwc1  $f0, 0x31c($sp)
  c.lt.s $f2, $f10
  nop   
  bc1tl .L7F084CC0
   swc1  $f16, 0x324($sp)
  c.lt.s $f10, $f20
  nop   
  bc1fl .L7F084CCC
   lwc1  $f0, 0x31c($sp)
  swc1  $f16, 0x324($sp)
.L7F084CC0:
  swc1  $f12, 0x320($sp)
  swc1  $f2, 0x31c($sp)
  lwc1  $f0, 0x31c($sp)
.L7F084CCC:
  lwc1  $f8, 0x324($sp)
  c.le.s $f20, $f0
  nop   
  bc1fl .L7F084D64
   swc1  $f20, 0x358($sp)
  mul.s $f6, $f0, $f8
  lui   $at, %hi(D_80055178)
  lwc1  $f4, %lo(D_80055178)($at)
  lwc1  $f8, 0x320($sp)
  lui   $at, %hi(D_8005517C)
  addiu $a0, $sp, 0x3ac
  li    $a1, 1
  mul.s $f10, $f6, $f4
  lwc1  $f4, %lo(D_8005517C)($at)
  mul.s $f6, $f0, $f8
  swc1  $f10, 0x3ac($sp)
  mul.s $f10, $f6, $f4
  jal   sub_GAME_7F07D960
   swc1  $f10, 0x3b4($sp)
  lw    $t0, ($s1)
  swc1  $f20, 0x3ac($sp)
  swc1  $f20, 0x3b4($sp)
  addiu $t6, $sp, 0x368
  lw    $a1, 0x488($t0)
  sw    $t6, 0x10($sp)
  lw    $a2, 0x35c($sp)
  move  $a3, $s0
  jal   sub_GAME_7F07CAC8
   addiu $a0, $t0, 0x48c
  beqz  $v0, .L7F084D54
   lwc1  $f8, 0x35c($sp)
  lui   $at, %hi(D_80036464)
  b     .L7F084D58
   swc1  $f8, %lo(D_80036464)($at)
.L7F084D54:
  swc1  $f20, 0x358($sp)
.L7F084D58:
  b     .L7F084D64
   lw    $t0, ($s1)
  swc1  $f20, 0x358($sp)
.L7F084D64:
  lui   $at, %hi(D_80055180)
  lwc1  $f14, %lo(D_80055180)($at)
  lui   $v1, %hi(D_80036484)
  addiu $v1, %lo(D_80036484) # addiu $v1, $v1, 0x6484
  lui   $at, %hi(D_80036488)
  lwc1  $f4, %lo(D_80036488)($at)
  lwc1  $f6, ($v1)
  lui   $a3, %hi(D_80036474)
  addiu $a3, %lo(D_80036474) # addiu $a3, $a3, 0x6474
  add.s $f10, $f6, $f4
  lwc1  $f12, ($a3)
  li    $at, 0x40600000 # 3.500000
  lui   $a0, %hi(clock_timer)
  swc1  $f10, ($v1)
  lwc1  $f0, ($v1)
  mtc1  $at, $f10
  mov.s $f16, $f12
  c.le.s $f14, $f0
  nop   
  bc1fl .L7F084DC8
   c.lt.s $f0, $f20
  sub.s $f8, $f0, $f14
  swc1  $f8, ($v1)
  lwc1  $f0, ($v1)
  c.lt.s $f0, $f20
.L7F084DC8:
  nop   
  bc1fl .L7F084DE4
   lwc1  $f4, 0x14c($t0)
  add.s $f6, $f0, $f14
  swc1  $f6, ($v1)
  lwc1  $f0, ($v1)
  lwc1  $f4, 0x14c($t0)
.L7F084DE4:
  lui   $at, %hi(D_80055184)
  lwc1  $f6, %lo(D_80055184)($at)
  mul.s $f8, $f4, $f10
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f10
  lui   $at, %hi(D_80055188)
  mul.s $f4, $f8, $f6
  nop   
  mul.s $f8, $f4, $f10
  add.s $f2, $f8, $f0
  c.lt.s $f2, $f20
  nop   
  bc1f  .L7F084E20
   nop   
  add.s $f2, $f2, $f14
.L7F084E20:
  c.le.s $f14, $f2
  nop   
  bc1fl .L7F084E38
   sub.s $f0, $f2, $f12
  sub.s $f2, $f2, $f14
  sub.s $f0, $f2, $f12
.L7F084E38:
  lwc1  $f6, %lo(D_80055188)($at)
  lui   $at, %hi(D_80055190)
  c.le.s $f6, $f0
  nop   
  bc1f  .L7F084E60
   nop   
  lui   $at, %hi(D_8005518C)
  lwc1  $f4, %lo(D_8005518C)($at)
  b     .L7F084E80
   sub.s $f2, $f2, $f4
.L7F084E60:
  lwc1  $f10, %lo(D_80055190)($at)
  lui   $at, %hi(D_80055194)
  c.lt.s $f0, $f10
  nop   
  bc1f  .L7F084E80
   nop   
  lwc1  $f8, %lo(D_80055194)($at)
  add.s $f2, $f2, $f8
.L7F084E80:
  lw    $a0, %lo(clock_timer)($a0)
  move  $v0, $zero
  lui   $at, %hi(D_80055198)
  blez  $a0, .L7F084EDC
   lui   $s0, %hi(D_80036478)
  lwc1  $f14, %lo(D_80055198)($at)
  addiu $s0, %lo(D_80036478) # addiu $s0, $s0, 0x6478
  lwc1  $f12, ($s0)
  addiu $v0, $v0, 1
  slt   $at, $v0, $a0
  mul.s $f18, $f14, $f12
  beql  $at, $zero, .L7F084ED8
   add.s $f12, $f18, $f2
  add.s $f12, $f18, $f2
.L7F084EB8:
  addiu $v0, $v0, 1
  slt   $at, $v0, $a0
  swc1  $f12, ($s0)
  lwc1  $f12, ($s0)
  mul.s $f18, $f14, $f12
  bnezl $at, .L7F084EB8
   add.s $f12, $f18, $f2
  add.s $f12, $f18, $f2
.L7F084ED8:
  swc1  $f12, ($s0)
.L7F084EDC:
  lui   $s0, %hi(D_80036478)
  addiu $s0, %lo(D_80036478) # addiu $s0, $s0, 0x6478
  lui   $at, %hi(D_8005519C)
  lwc1  $f0, %lo(D_8005519C)($at)
  lwc1  $f8, ($s0)
  lui   $at, %hi(D_800551A0)
  lwc1  $f2, %lo(D_800551A0)($at)
  mul.s $f6, $f8, $f0
  addiu $a0, $t0, 0x48c
  lui   $a2, %hi(D_80036464)
  swc1  $f6, ($a3)
  lwc1  $f12, ($a3)
  c.le.s $f2, $f12
  nop   
  bc1fl .L7F084F34
   c.lt.s $f12, $f20
  sub.s $f4, $f12, $f2
  swc1  $f4, ($a3)
  lwc1  $f12, ($a3)
  div.s $f10, $f12, $f0
  swc1  $f10, ($s0)
  c.lt.s $f12, $f20
.L7F084F34:
  nop   
  bc1fl .L7F084F58
   lw    $a1, 0x488($t0)
  add.s $f8, $f12, $f2
  swc1  $f8, ($a3)
  lwc1  $f6, ($a3)
  div.s $f4, $f6, $f0
  swc1  $f4, ($s0)
  lw    $a1, 0x488($t0)
.L7F084F58:
  swc1  $f16, 0x354($sp)
  jal   sub_GAME_7F07CDA8
   lw    $a2, %lo(D_80036464)($a2)
  lui   $v1, %hi(D_80036484)
  lui   $at, %hi(D_800551A8)
  lwc1  $f14, %lo(D_800551A8)($at)
  addiu $v1, %lo(D_80036484) # addiu $v1, $v1, 0x6484
  bnez  $v0, .L7F084F9C
   lwc1  $f16, 0x354($sp)
  lui   $at, %hi(D_80036474)
  swc1  $f16, %lo(D_80036474)($at)
  lwc1  $f10, %lo(D_80036474)($at)
  lui   $at, %hi(D_800551AC)
  lwc1  $f8, %lo(D_800551AC)($at)
  swc1  $f16, ($v1)
  div.s $f6, $f10, $f8
  swc1  $f6, ($s0)
.L7F084F9C:
  lui   $v1, %hi(ptr_playerstank)
  lw    $v1, %lo(ptr_playerstank)($v1)
  lui   $v0, %hi(flt_CODE_bss_800799A8)
  addiu $v0, %lo(flt_CODE_bss_800799A8) # addiu $v0, $v0, -0x6658
  beqz  $v1, .L7F08506C
   addiu $s0, $sp, 0x2b4
  lw    $t7, 4($v1)
  lwc1  $f4, ($v0)
  lwc1  $f10, 8($v0)
  swc1  $f20, 0x2f8($sp)
  lwc1  $f12, 0x358($sp)
  move  $a1, $s0
  sw    $t7, 0x300($sp)
  swc1  $f4, 0x2f4($sp)
  jal   sub_GAME_7F0585FC
   swc1  $f10, 0x2fc($sp)
  move  $a0, $s0
  jal   sub_GAME_7F0583D8
   addiu $a1, $sp, 0x2f4
  jal   sub_GAME_7F07C7B4
   nop   
  lui   $v0, %hi(flt_CODE_bss_800799A8)
  addiu $v0, %lo(flt_CODE_bss_800799A8) # addiu $v0, $v0, -0x6658
  lwc1  $f8, ($v0)
  lwc1  $f6, 0x2f4($sp)
  lwc1  $f10, 8($v0)
  lui   $at, %hi(D_800551BC)
  sub.s $f4, $f8, $f6
  lwc1  $f8, 0x2fc($sp)
  swc1  $f20, 0x2f8($sp)
  move  $a1, $s0
  swc1  $f4, 0x2f4($sp)
  sub.s $f6, $f10, $f8
  lwc1  $f4, %lo(D_800551BC)($at)
  lui   $at, %hi(D_80036464)
  lwc1  $f10, %lo(D_80036464)($at)
  swc1  $f6, 0x2fc($sp)
  jal   sub_GAME_7F0585FC
   sub.s $f12, $f4, $f10
  lw    $t3, 0x300($sp)
  move  $a1, $s0
  lw    $t8, 0x14($t3)
  jal   matrix_multiply_A1_by_F12
   lwc1  $f12, 0x14($t8)
  move  $a0, $s0
  jal   sub_GAME_7F0583D8
   addiu $a1, $sp, 0x2f4
  addiu $a0, $sp, 0x2f4
  jal   sub_GAME_7F07D960
   li    $a1, 1
  lui   $at, %hi(D_800551CC)
  lwc1  $f14, %lo(D_800551CC)($at)
.L7F08506C:
  lui   $a0, %hi(clock_timer)
  lw    $a0, %lo(clock_timer)($a0)
  lui   $at, %hi(D_80036474)
  lwc1  $f12, %lo(D_80036474)($at)
  blezl $a0, .L7F0850EC
   lui   $at, 0x43b4
  blez  $a0, .L7F0850E8
   move  $v0, $zero
  lui   $at, %hi(D_80036488)
  lwc1  $f8, %lo(D_80036488)($at)
  lui   $at, %hi(global_timer_delta)
  lwc1  $f6, %lo(global_timer_delta)($at)
  lui   $v1, %hi(D_8003647C)
  addiu $v1, %lo(D_8003647C) # addiu $v1, $v1, 0x647c
  div.s $f0, $f8, $f6
  lwc1  $f16, ($v1)
  addiu $v0, $v0, 1
  slt   $at, $v0, $a0
  mul.s $f18, $f14, $f16
  beql  $at, $zero, .L7F0850E4
   add.s $f16, $f18, $f0
  add.s $f16, $f18, $f0
.L7F0850C4:
  addiu $v0, $v0, 1
  slt   $at, $v0, $a0
  swc1  $f16, ($v1)
  lwc1  $f16, ($v1)
  mul.s $f18, $f14, $f16
  bnezl $at, .L7F0850C4
   add.s $f16, $f18, $f0
  add.s $f16, $f18, $f0
.L7F0850E4:
  swc1  $f16, ($v1)
.L7F0850E8:
  li    $at, 0x43B40000 # 360.000000
.L7F0850EC:
  mtc1  $at, $f14
  lui   $v1, %hi(D_8003647C)
  addiu $v1, %lo(D_8003647C) # addiu $v1, $v1, 0x647c
  lui   $at, %hi(D_800551D0)
  lwc1  $f4, %lo(D_800551D0)($at)
  lwc1  $f6, ($v1)
  lw    $t0, ($s1)
  li    $at, 0x40600000 # 3.500000
  mul.s $f2, $f6, $f4
  mtc1  $at, $f8
  lwc1  $f10, 0x14c($t0)
  lui   $at, %hi(D_800551D4)
  lwc1  $f4, %lo(D_800551D4)($at)
  mul.s $f6, $f10, $f8
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f8
  lui   $at, %hi(D_80036464)
  mul.s $f10, $f6, $f4
  lwc1  $f4, %lo(D_80036464)($at)
  li    $at, 0x40800000 # 4.000000
  mul.s $f6, $f10, $f8
  add.s $f10, $f4, $f12
  mtc1  $at, $f4
  lui   $at, %hi(D_800551D8)
  add.s $f8, $f10, $f6
  mul.s $f10, $f2, $f4
  add.s $f6, $f8, $f10
  lwc1  $f8, %lo(D_800551D8)($at)
  mul.s $f4, $f6, $f14
  div.s $f10, $f4, $f8
  swc1  $f10, 0x148($t0)
  lw    $t0, ($s1)
  lwc1  $f0, 0x148($t0)
  c.lt.s $f0, $f20
  nop   
  bc1fl .L7F0851A4
   c.le.s $f14, $f0
  add.s $f6, $f0, $f14
.L7F085184:
  swc1  $f6, 0x148($t0)
  lw    $t0, ($s1)
  lwc1  $f0, 0x148($t0)
  c.lt.s $f0, $f20
  nop   
  bc1tl .L7F085184
   add.s $f6, $f0, $f14
  c.le.s $f14, $f0
.L7F0851A4:
  nop   
  bc1f  .L7F0851D0
   nop   
  sub.s $f4, $f0, $f14
.L7F0851B4:
  swc1  $f4, 0x148($t0)
  lw    $t0, ($s1)
  lwc1  $f0, 0x148($t0)
  c.le.s $f14, $f0
  nop   
  bc1tl .L7F0851B4
   sub.s $f4, $f0, $f14
.L7F0851D0:
  b     .L7F08525C
   nop   
.L7F0851D8:
  lwc1  $f8, 0x14c($t0)
  lwc1  $f10, ($t1)
  li    $at, 0x40600000 # 3.500000
  mtc1  $at, $f4
  mul.s $f6, $f8, $f10
  lwc1  $f10, 0x148($t0)
  lui   $at, 0x43b4
  mul.s $f8, $f6, $f4
  add.s $f0, $f10, $f8
  c.lt.s $f0, $f20
  nop   
  bc1fl .L7F08522C
   li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f14
  nop   
  add.s $f0, $f0, $f14
.L7F085218:
  c.lt.s $f0, $f20
  nop   
  bc1tl .L7F085218
   add.s $f0, $f0, $f14
  li    $at, 0x43B40000 # 360.000000
.L7F08522C:
  mtc1  $at, $f14
  nop   
  c.le.s $f14, $f0
  nop   
  bc1fl .L7F08525C
   swc1  $f0, 0x148($t0)
  sub.s $f0, $f0, $f14
.L7F085248:
  c.le.s $f14, $f0
  nop   
  bc1tl .L7F085248
   sub.s $f0, $f0, $f14
  swc1  $f0, 0x148($t0)
.L7F08525C:
  jal   sub_GAME_7F081790
   nop   
  jal   sub_GAME_7F0799F0
   swc1  $f20, 0x2ac($sp)
  bnez  $v0, .L7F085280
   li    $at, 0xC2C80000 # -100.000000
  mtc1  $at, $f6
  b     .L7F0852A8
   swc1  $f6, 0x2ac($sp)
.L7F085280:
  jal   sub_GAME_7F0799F0
   nop   
  li    $at, 1
  bne   $v0, $at, .L7F0852A0
   li    $at, 0xC2700000 # -60.000000
  mtc1  $at, $f4
  b     .L7F0852A8
   swc1  $f4, 0x2ac($sp)
.L7F0852A0:
  jal   sub_GAME_7F0799F0
   nop   
.L7F0852A8:
  lw    $t0, ($s1)
  lwc1  $f10, 0x2ac($sp)
  li    $at, 0x3F000000 # 0.500000
  lwc1  $f0, 0xa0($t0)
  addiu $a0, $t0, 0xa0
  addiu $a2, $t0, 0xa4
  c.eq.s $f10, $f0
  nop   
  bc1tl .L7F0852FC
   lwc1  $f6, 0x2ac($sp)
  mtc1  $at, $f0
  li    $at, 0x40A00000 # 5.000000
  mtc1  $at, $f8
  mfc1  $a1, $f10
  mfc1  $a3, $f0
  swc1  $f0, 0x10($sp)
  jal   sub_GAME_7F042F18
   swc1  $f8, 0x14($sp)
  lw    $t0, ($s1)
  lwc1  $f0, 0xa0($t0)
  lwc1  $f6, 0x2ac($sp)
.L7F0852FC:
  lui   $s0, %hi(SFX_80036458)
  lui   $t4, %hi(in_tank_flag) 
  c.eq.s $f6, $f0
  addiu $s0, %lo(SFX_80036458) # addiu $s0, $s0, 0x6458
  bc1f  .L7F085318
   nop   
  swc1  $f20, 0xa4($t0)
.L7F085318:
  lw    $t4, %lo(in_tank_flag)($t4)
  li    $at, 1
  bne   $t4, $at, .L7F085B48
   lui   $v0, %hi(dword_CODE_bss_800799B8)
  lw    $v0, %lo(dword_CODE_bss_800799B8)($v0)
  lui   $v1, %hi(ptr_playerstank)
  li    $at, 1
  bnez  $v0, .L7F085634
   nop   
  lw    $v1, %lo(ptr_playerstank)($v1)
  lui   $at, %hi(D_800551DC)
  addiu $a1, $sp, 0x268
  beqz  $v1, .L7F085600
   nop   
  lwc1  $f4, %lo(D_800551DC)($at)
  lui   $at, %hi(D_80036464)
  lwc1  $f10, %lo(D_80036464)($at)
  lw    $s0, 4($v1)
  jal   sub_GAME_7F0585FC
   sub.s $f12, $f4, $f10
  lw    $t9, 0x14($s0)
  addiu $a1, $sp, 0x268
  jal   matrix_multiply_A1_by_F12
   lwc1  $f12, 0x14($t9)
  lui   $v0, %hi(flt_CODE_bss_800799A8)
  addiu $v0, %lo(flt_CODE_bss_800799A8) # addiu $v0, $v0, -0x6658
  lwc1  $f8, ($v0)
  lwc1  $f6, 4($v0)
  lwc1  $f4, 8($v0)
  addiu $a0, $sp, 0x268
  addiu $a1, $sp, 0x25c
  swc1  $f8, 0x25c($sp)
  swc1  $f6, 0x260($sp)
  jal   sub_GAME_7F0583D8
   swc1  $f4, 0x264($sp)
  lwc1  $f10, 0x25c($sp)
  lwc1  $f8, 0x58($s0)
  lwc1  $f4, 0x260($sp)
  li    $at, 0xC1A00000 # -20.000000
  add.s $f6, $f10, $f8
  mtc1  $at, $f0
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f14
  swc1  $f6, 0x25c($sp)
  lwc1  $f10, 0x5c($s0)
  lwc1  $f6, 0x264($sp)
  lui   $at, %hi(D_80036464)
  add.s $f8, $f4, $f10
  lw    $t2, ($s1)
  swc1  $f8, 0x260($sp)
  lwc1  $f4, 0x60($s0)
  lwc1  $f8, %lo(D_80036464)($at)
  lui   $at, %hi(D_80036474)
  add.s $f10, $f6, $f4
  lwc1  $f6, %lo(D_80036474)($at)
  lui   $at, %hi(D_800551E0)
  add.s $f4, $f8, $f6
  swc1  $f10, 0x264($sp)
  lwc1  $f2, 0x158($t2)
  lwc1  $f8, %lo(D_800551E0)($at)
  mul.s $f10, $f4, $f14
  c.lt.s $f2, $f0
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f18
  lui   $at, %hi(global_timer_delta)
  bc1f  .L7F085428
   div.s $f16, $f10, $f8
  mov.s $f2, $f0
.L7F085428:
  lwc1  $f6, %lo(global_timer_delta)($at)
  li    $at, 0x42340000 # 45.000000
  mtc1  $at, $f4
  lui   $s0, %hi(flt_CODE_bss_800799BC)
  addiu $s0, %lo(flt_CODE_bss_800799BC) # addiu $s0, $s0, -0x6644
  div.s $f10, $f6, $f4
  lwc1  $f8, ($s0)
  lui   $at, %hi(D_800551E4)
  add.s $f6, $f8, $f10
  swc1  $f6, ($s0)
  lwc1  $f0, ($s0)
  c.le.s $f18, $f0
  nop   
  bc1f  .L7F08546C
   nop   
  swc1  $f18, ($s0)
  lwc1  $f0, ($s0)
.L7F08546C:
  lwc1  $f4, %lo(D_800551E4)($at)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f10
  mul.s $f8, $f0, $f4
  swc1  $f2, 0x254($sp)
  swc1  $f16, 0x258($sp)
  mul.s $f12, $f8, $f10
  jal   cosf
   nop   
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f14
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f8
  add.s $f4, $f0, $f6
  lui   $v0, %hi(flt_CODE_bss_800799C0)
  addiu $v0, %lo(flt_CODE_bss_800799C0) # addiu $v0, $v0, -0x6640
  li    $at, 0x3F800000 # 1.000000
  mul.s $f10, $f4, $f8
  mtc1  $at, $f6
  lwc1  $f8, 0x254($sp)
  lui   $at, %hi(flt_CODE_bss_800799C8)
  lw    $t5, ($s1)
  lwc1  $f16, 0x258($sp)
  lui   $v1, %hi(flt_CODE_bss_800799D0)
  swc1  $f10, ($v0)
  lwc1  $f2, ($v0)
  addiu $v1, %lo(flt_CODE_bss_800799D0) # addiu $v1, $v1, -0x6630
  sub.s $f4, $f6, $f2
  lwc1  $f6, %lo(flt_CODE_bss_800799C8)($at)
  lui   $at, %hi(flt_CODE_bss_800799C4)
  mul.s $f10, $f4, $f8
  nop   
  mul.s $f4, $f2, $f6
  add.s $f8, $f4, $f10
  swc1  $f8, 0x158($t5)
  lwc1  $f18, %lo(flt_CODE_bss_800799C4)($at)
  li    $at, 0x43340000 # 180.000000
  mtc1  $at, $f6
  sub.s $f12, $f16, $f18
  li    $at, 0xC3340000 # -180.000000
  mtc1  $at, $f4
  li    $at, 0x3F800000 # 1.000000
  c.lt.s $f6, $f12
  mtc1  $at, $f8
  li    $at, 0x3F800000 # 1.000000
  bc1f  .L7F085534
   nop   
  sub.s $f16, $f16, $f14
.L7F085534:
  c.lt.s $f12, $f4
  nop   
  bc1fl .L7F08554C
   lwc1  $f2, ($v0)
  add.s $f16, $f16, $f14
  lwc1  $f2, ($v0)
.L7F08554C:
  lw    $t6, ($s1)
  sub.s $f6, $f8, $f2
  mul.s $f10, $f2, $f18
  nop   
  mul.s $f4, $f6, $f16
  add.s $f8, $f10, $f4
  mtc1  $at, $f4
  swc1  $f8, 0x148($t6)
  lw    $t0, ($s1)
  lwc1  $f0, 0x148($t0)
  c.le.s $f14, $f0
  nop   
  bc1f  .L7F085594
   nop   
  sub.s $f6, $f0, $f14
  swc1  $f6, 0x148($t0)
  lw    $t0, ($s1)
  lwc1  $f0, 0x148($t0)
.L7F085594:
  c.lt.s $f0, $f20
  nop   
  bc1fl .L7F0855B4
   lwc1  $f2, ($v0)
  add.s $f10, $f0, $f14
  swc1  $f10, 0x148($t0)
  lw    $t0, ($s1)
  lwc1  $f2, ($v0)
.L7F0855B4:
  lwc1  $f8, ($v1)
  lwc1  $f10, 0x25c($sp)
  sub.s $f0, $f4, $f2
  mul.s $f6, $f2, $f8
  nop   
  mul.s $f4, $f0, $f10
  lwc1  $f10, 0x48c($t0)
  swc1  $f20, 0x3b0($sp)
  add.s $f8, $f6, $f4
  lwc1  $f4, 8($v1)
  sub.s $f6, $f8, $f10
  mul.s $f8, $f2, $f4
  lwc1  $f10, 0x264($sp)
  swc1  $f6, 0x3ac($sp)
  mul.s $f6, $f0, $f10
  lwc1  $f10, 0x494($t0)
  add.s $f4, $f8, $f6
  sub.s $f8, $f4, $f10
  swc1  $f8, 0x3b4($sp)
.L7F085600:
  lui   $s0, %hi(flt_CODE_bss_800799BC)
  addiu $s0, %lo(flt_CODE_bss_800799BC) # addiu $s0, $s0, -0x6644
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  lwc1  $f6, ($s0)
  lw    $t0, ($s1)
  lui   $at, %hi(dword_CODE_bss_800799B8)
  c.le.s $f4, $f6
  li    $t7, 1
  bc1fl .L7F0859E4
   lui   $at, %hi(0x3F3F99B8) # $at, 0x3f40
  b     .L7F0859E0
   sw    $t7, %lo(dword_CODE_bss_800799B8)($at)
.L7F085634:
  bne   $v0, $at, .L7F0856A0
   lui   $s0, %hi(SFX_80036458)
  li    $t3, 2
  lui   $at, %hi(dword_CODE_bss_800799B8)
  addiu $s0, %lo(SFX_80036458) # addiu $s0, $s0, 0x6458
  sw    $t3, %lo(dword_CODE_bss_800799B8)($at)
  lw    $t8, ($s0)
  bnezl $t8, .L7F08567C
   lw    $a0, ($s0)
  jal   get_controls_locked_flag
   nop   
  bnez  $v0, .L7F085678
   lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 66
  jal   play_sfx_a1
   move  $a2, $s0
.L7F085678:
  lw    $a0, ($s0)
.L7F08567C:
  li    $a1, 8
  jal   sfx_c_70009184
   li    $a2, 25000
  lui   $v0, %hi(dword_CODE_bss_800799B4)
  addiu $v0, %lo(dword_CODE_bss_800799B4) # addiu $v0, $v0, -0x664c
  li    $t4, 25000
  sw    $t4, ($v0)
  b     .L7F0859E0
   lw    $t0, ($s1)
.L7F0856A0:
  lw    $t0, ($s1)
  li    $at, 0x41700000 # 15.000000
  mtc1  $at, $f8
  lwc1  $f10, 0x174($t0)
  lui   $at, %hi(D_800551E8)
  lwc1  $f4, %lo(D_800551E8)($at)
  div.s $f0, $f10, $f8
  lwc1  $f6, 0x14c($t0)
  div.s $f2, $f6, $f4
  c.lt.s $f0, $f20
  nop   
  bc1fl .L7F0856DC
   c.lt.s $f2, $f20
  neg.s $f0, $f0
  c.lt.s $f2, $f20
.L7F0856DC:
  nop   
  bc1fl .L7F0856F0
   c.lt.s $f0, $f2
  neg.s $f2, $f2
  c.lt.s $f0, $f2
.L7F0856F0:
  mov.s $f12, $f0
  bc1fl .L7F085704
   c.lt.s $f20, $f12
  mov.s $f12, $f2
  c.lt.s $f20, $f12
.L7F085704:
  nop   
  bc1f  .L7F085818
   li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  lui   $s0, %hi(SFX_80036458)
  addiu $s0, %lo(SFX_80036458) # addiu $s0, $s0, 0x6458
  c.lt.s $f10, $f12
  li    $at, 0x3F800000 # 1.000000
  bc1fl .L7F085738
   lw    $t9, 4($s0)
  mtc1  $at, $f12
  nop   
  lw    $t9, 4($s0)
.L7F085738:
  bnezl $t9, .L7F085774
   lw    $a0, 4($s0)
  jal   get_controls_locked_flag
   swc1  $f12, 0x244($sp)
  bnez  $v0, .L7F085770
   lwc1  $f12, 0x244($sp)
  lui   $a0, %hi(ptr_sfx_buf)
  lui   $a2, %hi(SFX_8003645C)
  addiu $a2, %lo(SFX_8003645C) # addiu $a2, $a2, 0x645c
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 62
  jal   play_sfx_a1
   swc1  $f12, 0x244($sp)
  lwc1  $f12, 0x244($sp)
.L7F085770:
  lw    $a0, 4($s0)
.L7F085774:
  lui   $at, %hi(D_800551EC)
  li    $a1, 8
  beql  $a0, $zero, .L7F085850
   lw    $t6, ($s0)
  lwc1  $f0, %lo(D_800551EC)($at)
  li    $a2, 32767
  lui   $at, %hi(D_800551F4)
  c.lt.s $f12, $f0
  nop   
  bc1f  .L7F0857C0
   nop   
  lui   $at, %hi(D_800551F0)
  lwc1  $f8, %lo(D_800551F0)($at)
  mul.s $f6, $f12, $f8
  div.s $f4, $f6, $f0
  trunc.w.s $f10, $f4
  mfc1  $a2, $f10
  b     .L7F085808
   nop   
.L7F0857C0:
  lwc1  $f8, %lo(D_800551F4)($at)
  lui   $at, %hi(D_800551F8)
  c.lt.s $f12, $f8
  nop   
  bc1f  .L7F085808
   nop   
  sub.s $f6, $f12, $f0
  lwc1  $f4, %lo(D_800551F8)($at)
  li    $at, 0x3F400000 # 0.750000
  mtc1  $at, $f8
  mul.s $f10, $f6, $f4
  lui   $at, %hi(D_800551FC)
  lwc1  $f4, %lo(D_800551FC)($at)
  div.s $f6, $f10, $f8
  add.s $f10, $f6, $f4
  trunc.w.s $f8, $f10
  mfc1  $a2, $f8
  nop   
.L7F085808:
  jal   sfx_c_70009184
   swc1  $f12, 0x244($sp)
  b     .L7F08584C
   lwc1  $f12, 0x244($sp)
.L7F085818:
  lui   $s0, %hi(SFX_80036458)
  addiu $s0, %lo(SFX_80036458) # addiu $s0, $s0, 0x6458
  lw    $a0, 4($s0)
  beql  $a0, $zero, .L7F085850
   lw    $t6, ($s0)
  jal   sfxGetArg0Unk3F
   swc1  $f12, 0x244($sp)
  beqz  $v0, .L7F08584C
   lwc1  $f12, 0x244($sp)
  lw    $a0, 4($s0)
  jal   sfxDeactivate
   swc1  $f12, 0x244($sp)
  lwc1  $f12, 0x244($sp)
.L7F08584C:
  lw    $t6, ($s0)
.L7F085850:
  bnezl $t6, .L7F085888
   lw    $a0, ($s0)
  jal   get_controls_locked_flag
   swc1  $f12, 0x244($sp)
  bnez  $v0, .L7F085884
   lwc1  $f12, 0x244($sp)
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 65
  move  $a2, $s0
  jal   play_sfx_a1
   swc1  $f12, 0x244($sp)
  lwc1  $f12, 0x244($sp)
.L7F085884:
  lw    $a0, ($s0)
.L7F085888:
  beqz  $a0, .L7F0858F4
   lui   $v0, %hi(dword_CODE_bss_800799B4)
  addiu $v0, %lo(dword_CODE_bss_800799B4) # addiu $v0, $v0, -0x664c
  li    $t7, 32767
  sw    $t7, ($v0)
  lui   $at, %hi(D_80055200)
  lwc1  $f6, %lo(D_80055200)($at)
  lui   $at, %hi(D_80055204)
  li    $a1, 8
  c.lt.s $f12, $f6
  nop   
  bc1f  .L7F0858EC
   nop   
  lwc1  $f4, %lo(D_80055204)($at)
  lui   $at, %hi(D_80055208)
  lwc1  $f8, %lo(D_80055208)($at)
  mul.s $f10, $f12, $f4
  lui   $at, %hi(D_8005520C)
  lwc1  $f4, %lo(D_8005520C)($at)
  div.s $f6, $f10, $f8
  add.s $f10, $f6, $f4
  trunc.w.s $f8, $f10
  mfc1  $t8, $f8
  nop   
  sw    $t8, ($v0)
.L7F0858EC:
  jal   sfx_c_70009184
   lw    $a2, ($v0)
.L7F0858F4:
  jal   get_item_in_hand
   move  $a0, $zero
  li    $at, 32
  bne   $v0, $at, .L7F085920
   lui   $a0, %hi(clock_timer)
  lw    $t0, ($s1)
  lui   $at, %hi(D_80055210)
  lwc1  $f6, %lo(D_80055210)($at)
  lwc1  $f2, 0x2a08($t0)
  b     .L7F08592C
   add.s $f2, $f2, $f6
.L7F085920:
  lui   $at, %hi(D_8003646C)
  lwc1  $f2, %lo(D_8003646C)($at)
  lw    $t0, ($s1)
.L7F08592C:
  lui   $at, %hi(D_80055214)
  lwc1  $f0, %lo(D_80055214)($at)
  lui   $at, %hi(D_80055218)
  c.lt.s $f0, $f2
  nop   
  bc1f  .L7F08594C
   nop   
  mov.s $f2, $f0
.L7F08594C:
  lwc1  $f0, %lo(D_80055218)($at)
  c.lt.s $f2, $f0
  nop   
  bc1f  .L7F085964
   nop   
  mov.s $f2, $f0
.L7F085964:
  lw    $a0, %lo(clock_timer)($a0)
  move  $v0, $zero
  blez  $a0, .L7F0859C0
   lui   $at, %hi(D_8005521C)
  lui   $v1, %hi(D_80036470)
  addiu $v1, %lo(D_80036470) # addiu $v1, $v1, 0x6470
  lwc1  $f0, %lo(D_8005521C)($at)
  lwc1  $f16, ($v1)
  addiu $v0, $v0, 1
  slt   $at, $v0, $a0
  mul.s $f18, $f0, $f16
  beql  $at, $zero, .L7F0859BC
   add.s $f16, $f18, $f2
  add.s $f16, $f18, $f2
.L7F08599C:
  addiu $v0, $v0, 1
  slt   $at, $v0, $a0
  swc1  $f16, ($v1)
  lwc1  $f16, ($v1)
  mul.s $f18, $f0, $f16
  bnezl $at, .L7F08599C
   add.s $f16, $f18, $f2
  add.s $f16, $f18, $f2
.L7F0859BC:
  swc1  $f16, ($v1)
.L7F0859C0:
  lui   $v1, %hi(D_80036470)
  addiu $v1, %lo(D_80036470) # addiu $v1, $v1, 0x6470
  lui   $at, %hi(D_80055220)
  lwc1  $f4, %lo(D_80055220)($at)
  lwc1  $f6, ($v1)
  lui   $at, %hi(D_8003646C)
  mul.s $f10, $f6, $f4
  swc1  $f10, %lo(D_8003646C)($at)
.L7F0859E0:
  li    $at, 0x3F400000 # 0.750000
.L7F0859E4:
  mtc1  $at, $f0
  lui   $at, %hi(global_timer_delta)
  lwc1  $f8, %lo(global_timer_delta)($at)
  lui   $at, %hi(D_80055224)
  lwc1  $f4, %lo(D_80055224)($at)
  mul.s $f6, $f0, $f8
  lwc1  $f8, 0x19c($t0)
  mfc1  $a2, $f20
  mov.s $f12, $f20
  div.s $f10, $f6, $f4
  sub.s $f6, $f8, $f10
  swc1  $f6, 0x19c($t0)
  lw    $t0, ($s1)
  lwc1  $f4, 0x19c($t0)
  c.lt.s $f4, $f20
  nop   
  bc1f  .L7F085A30
   nop   
  swc1  $f20, 0x19c($t0)
.L7F085A30:
  jal   sub_GAME_7F080B34
   mov.s $f14, $f20
  lui   $at, %hi(D_80055228)
  lwc1  $f8, %lo(D_80055228)($at)
  lui   $at, %hi(D_80036464)
  lwc1  $f10, %lo(D_80036464)($at)
  jal   sinf
   sub.s $f12, $f8, $f10
  lw    $t4, ($s1)
  lui   $at, %hi(global_timer_delta)
  lwc1  $f8, %lo(global_timer_delta)($at)
  lwc1  $f6, 0x174($t4)
  lui   $at, %hi(D_8005522C)
  mul.s $f4, $f6, $f0
  lwc1  $f6, 0x3ac($sp)
  mul.s $f10, $f4, $f8
  lwc1  $f8, %lo(D_8005522C)($at)
  lui   $at, %hi(D_80036464)
  add.s $f4, $f6, $f10
  lwc1  $f6, %lo(D_80036464)($at)
  swc1  $f4, 0x3ac($sp)
  jal   cosf
   sub.s $f12, $f8, $f6
  lw    $t9, ($s1)
  lui   $at, %hi(global_timer_delta)
  lwc1  $f8, %lo(global_timer_delta)($at)
  lwc1  $f10, 0x174($t9)
  addiu $a0, $sp, 0x3ac
  li    $a1, 1
  mul.s $f4, $f10, $f0
  lwc1  $f10, 0x3b4($sp)
  mul.s $f6, $f4, $f8
  add.s $f4, $f10, $f6
  jal   sub_GAME_7F07D960
   swc1  $f4, 0x3b4($sp)
  lui   $t2, %hi(dword_CODE_bss_800799B8) 
  lw    $t2, %lo(dword_CODE_bss_800799B8)($t2)
  li    $at, 2
  lui   $t5, %hi(clock_timer) 
  bnel  $t2, $at, .L7F0863AC
   lw    $t0, ($s1)
  lw    $t5, %lo(clock_timer)($t5)
  blezl $t5, .L7F0863AC
   lw    $t0, ($s1)
  lw    $t0, ($s1)
  lui   $at, %hi(global_timer_delta)
  lwc1  $f14, %lo(global_timer_delta)($at)
  lwc1  $f8, 0x48c($t0)
  lwc1  $f10, 0x408($t0)
  lwc1  $f4, 0x494($t0)
  sub.s $f6, $f8, $f10
  lwc1  $f8, 0x410($t0)
  sub.s $f10, $f4, $f8
  div.s $f0, $f6, $f14
  div.s $f2, $f10, $f14
  mul.s $f6, $f0, $f0
  nop   
  mul.s $f4, $f2, $f2
  jal   sqrtf
   add.s $f12, $f6, $f4
  lw    $t0, ($s1)
  mov.s $f2, $f0
  lwc1  $f8, 0x174($t0)
  c.lt.s $f8, $f20
  nop   
  bc1f  .L7F085B40
   nop   
  neg.s $f2, $f0
.L7F085B40:
  b     .L7F0863A8
   swc1  $f2, 0x174($t0)
.L7F085B48:
  lw    $a0, ($s0)
  beql  $a0, $zero, .L7F085BB4
   lw    $a0, 4($s0)
  jal   sfxGetArg0Unk3F
   nop   
  beqz  $v0, .L7F085BB0
   lui   $t7, %hi(clock_timer) 
  lw    $t7, %lo(clock_timer)($t7)
  lui   $v0, %hi(dword_CODE_bss_800799B4)
  addiu $v0, %lo(dword_CODE_bss_800799B4) # addiu $v0, $v0, -0x664c
  sll   $t3, $t7, 5
  subu  $t3, $t3, $t7
  lw    $t6, ($v0)
  sll   $t3, $t3, 2
  addu  $t3, $t3, $t7
  sll   $t3, $t3, 3
  subu  $a2, $t6, $t3
  blez  $a2, .L7F085BA8
   sw    $a2, ($v0)
  lw    $a0, ($s0)
  jal   sfx_c_70009184
   li    $a1, 8
  b     .L7F085BB4
   lw    $a0, 4($s0)
.L7F085BA8:
  jal   sfxDeactivate
   lw    $a0, ($s0)
.L7F085BB0:
  lw    $a0, 4($s0)
.L7F085BB4:
  beqz  $a0, .L7F085BD4
   nop   
  jal   sfxGetArg0Unk3F
   nop   
  beqz  $v0, .L7F085BD4
   nop   
  jal   sfxDeactivate
   lw    $a0, 4($s0)
.L7F085BD4:
  lui   $at, %hi(global_timer_delta)
  lwc1  $f14, %lo(global_timer_delta)($at)
  lui   $at, %hi(D_80036AF4)
  lwc1  $f10, %lo(D_80036AF4)($at)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f6
  lw    $t0, ($s1)
  li    $at, 0x42C80000 # 100.000000
  mul.s $f4, $f10, $f6
  lwc1  $f8, 0x16c($t0)
  swc1  $f8, 0x4c($sp)
  lwc1  $f10, 0x4c($sp)
  mul.s $f12, $f4, $f14
  nop   
  mul.s $f6, $f10, $f12
  swc1  $f6, 0x3a0($sp)
  lwc1  $f0, 0x1274($t0)
  lwc1  $f4, 0x4a0($t0)
  lwc1  $f6, 0x1278($t0)
  neg.s $f8, $f0
  lwc1  $f10, 0x498($t0)
  mul.s $f16, $f4, $f8
  sub.s $f4, $f16, $f6
  mul.s $f18, $f10, $f0
  swc1  $f4, 0x220($sp)
  lwc1  $f8, 0x127c($t0)
  lwc1  $f6, 0x220($sp)
  sub.s $f10, $f18, $f8
  mul.s $f4, $f6, $f6
  swc1  $f10, 0x21c($sp)
  lwc1  $f8, 0x21c($sp)
  mul.s $f10, $f8, $f8
  add.s $f2, $f4, $f10
  mtc1  $at, $f4
  nop   
  c.le.s $f4, $f2
  swc1  $f2, 0x218($sp)
  bc1f  .L7F085C8C
   nop   
  lui   $at, %hi(D_80055230)
  lwc1  $f0, %lo(D_80055230)($at)
  mul.s $f10, $f6, $f0
  nop   
  mul.s $f4, $f8, $f0
  swc1  $f10, 0x220($sp)
  swc1  $f4, 0x21c($sp)
.L7F085C8C:
  lui   $at, %hi(D_80055234)
  lwc1  $f16, %lo(D_80055234)($at)
  lwc1  $f6, 0x4c($sp)
  lwc1  $f10, 0x14c($t0)
  lwc1  $f2, 0x174($t0)
  mul.s $f0, $f6, $f16
  c.lt.s $f0, $f20
  mul.s $f12, $f10, $f16
  bc1fl .L7F085CBC
   c.lt.s $f2, $f20
  neg.s $f0, $f0
  c.lt.s $f2, $f20
.L7F085CBC:
  lui   $at, %hi(D_80055238)
  bc1fl .L7F085CD0
   c.lt.s $f12, $f20
  neg.s $f2, $f2
  c.lt.s $f12, $f20
.L7F085CD0:
  nop   
  bc1fl .L7F085CE4
   c.lt.s $f2, $f0
  neg.s $f12, $f12
  c.lt.s $f2, $f0
.L7F085CE4:
  swc1  $f2, 0x398($sp)
  bc1fl .L7F085CF8
   lwc1  $f8, 0x398($sp)
  swc1  $f0, 0x398($sp)
  lwc1  $f8, 0x398($sp)
.L7F085CF8:
  c.lt.s $f8, $f12
  nop   
  bc1fl .L7F085D10
   lwc1  $f4, 0x218($sp)
  swc1  $f12, 0x398($sp)
  lwc1  $f4, 0x218($sp)
.L7F085D10:
  lwc1  $f6, %lo(D_80055238)($at)
  li    $at, 0x3F400000 # 0.750000
  mtc1  $at, $f0
  c.le.s $f6, $f4
  nop   
  bc1fl .L7F085D48
   lwc1  $f8, 0x398($sp)
  lwc1  $f10, 0x398($sp)
  c.lt.s $f10, $f16
  nop   
  bc1fl .L7F085D48
   lwc1  $f8, 0x398($sp)
  swc1  $f16, 0x398($sp)
  lwc1  $f8, 0x398($sp)
.L7F085D48:
  c.le.s $f0, $f8
  nop   
  bc1fl .L7F085D80
   lwc1  $f10, 0x398($sp)
  sub.s $f4, $f8, $f0
  li    $at, 0x44610000 # 900.000000
  mtc1  $at, $f10
  mul.s $f6, $f4, $f14
  lwc1  $f4, 0x19c($t0)
  div.s $f8, $f6, $f10
  add.s $f6, $f4, $f8
  b     .L7F085DA0
   swc1  $f6, 0x19c($t0)
  lwc1  $f10, 0x398($sp)
.L7F085D80:
  lui   $at, %hi(D_8005523C)
  lwc1  $f6, %lo(D_8005523C)($at)
  sub.s $f4, $f0, $f10
  mul.s $f8, $f4, $f14
  lwc1  $f4, 0x19c($t0)
  div.s $f10, $f8, $f6
  sub.s $f8, $f4, $f10
  swc1  $f8, 0x19c($t0)
.L7F085DA0:
  lw    $t0, ($s1)
  lwc1  $f0, 0x19c($t0)
  c.lt.s $f0, $f20
  nop   
  bc1fl .L7F085DC8
   lui   $at, 0x3f80
  swc1  $f20, 0x19c($t0)
  b     .L7F085DF0
   lw    $t0, ($s1)
  li    $at, 0x3F800000 # 1.000000
.L7F085DC8:
  mtc1  $at, $f6
  li    $at, 0x3F800000 # 1.000000
  c.lt.s $f6, $f0
  nop   
  bc1fl .L7F085DF4
   lwc1  $f12, 0x398($sp)
  mtc1  $at, $f4
  nop   
  swc1  $f4, 0x19c($t0)
  lw    $t0, ($s1)
.L7F085DF0:
  lwc1  $f12, 0x398($sp)
.L7F085DF4:
  lwc1  $f14, 0x174($t0)
  jal   sub_GAME_7F080B34
   lw    $a2, 0x3a0($sp)
  lw    $t0, ($s1)
  lui   $at, %hi(global_timer_delta)
  lwc1  $f14, %lo(global_timer_delta)($at)
  lwc1  $f2, 0x504($t0)
  lwc1  $f10, 0x498($t0)
  lwc1  $f0, 0x4fc($t0)
  lwc1  $f6, 0x4a0($t0)
  mul.s $f8, $f2, $f10
  nop   
  mul.s $f4, $f0, $f6
  sub.s $f10, $f8, $f4
  lwc1  $f8, 0x3ac($sp)
  mul.s $f6, $f10, $f14
  add.s $f4, $f8, $f6
  swc1  $f4, 0x3ac($sp)
  lwc1  $f10, 0x4a0($t0)
  lwc1  $f6, 0x498($t0)
  mul.s $f8, $f2, $f10
  nop   
  mul.s $f10, $f0, $f6
  add.s $f6, $f8, $f10
  lwc1  $f10, 0x3b4($sp)
  mul.s $f8, $f6, $f14
  add.s $f6, $f10, $f8
  lwc1  $f10, 0x220($sp)
  add.s $f8, $f4, $f10
  lwc1  $f4, 0x21c($sp)
  swc1  $f6, 0x3b4($sp)
  add.s $f10, $f6, $f4
  swc1  $f8, 0x3ac($sp)
  swc1  $f10, 0x3b4($sp)
  lwc1  $f8, 0x48c($t0)
  swc1  $f8, 0x208($sp)
  lwc1  $f6, 0x494($t0)
  swc1  $f6, 0x204($sp)
  lw    $t4, 0x488($t0)
  jal   get_debug_fast_bond_flag
   sw    $t4, 0x200($sp)
  beql  $v0, $zero, .L7F085F20
   lw    $t9, ($s1)
  lw    $t0, ($s1)
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f0
  lwc1  $f4, 0x498($t0)
  lwc1  $f10, 0x174($t0)
  lwc1  $f6, 0x4a0($t0)
  lui   $at, %hi(global_timer_delta)
  mul.s $f8, $f4, $f10
  lwc1  $f4, 0x16c($t0)
  lwc1  $f14, %lo(global_timer_delta)($at)
  mul.s $f10, $f6, $f4
  sub.s $f6, $f8, $f10
  lwc1  $f10, 0x3ac($sp)
  mul.s $f4, $f6, $f14
  nop   
  mul.s $f8, $f4, $f0
  add.s $f6, $f10, $f8
  swc1  $f6, 0x3ac($sp)
  lwc1  $f10, 0x174($t0)
  lwc1  $f4, 0x4a0($t0)
  lwc1  $f6, 0x498($t0)
  mul.s $f8, $f4, $f10
  lwc1  $f4, 0x16c($t0)
  mul.s $f10, $f6, $f4
  add.s $f6, $f8, $f10
  lwc1  $f10, 0x3b4($sp)
  mul.s $f4, $f6, $f14
  nop   
  mul.s $f8, $f4, $f0
  add.s $f6, $f10, $f8
  swc1  $f6, 0x3b4($sp)
  lw    $t9, ($s1)
.L7F085F20:
  addiu $a0, $sp, 0x3ac
  move  $a1, $zero
  lwc1  $f4, 0x1274($t9)
  c.eq.s $f20, $f4
  nop   
  bc1f  .L7F085F40
   nop   
  li    $a1, 1
.L7F085F40:
  jal   sub_GAME_7F07D960
   nop   
  lw    $t2, ($s1)
  lui   $at, %hi(D_80055240)
  lwc1  $f8, %lo(D_80055240)($at)
  lwc1  $f10, 0x4b0($t2)
  addiu $s0, $sp, 0x1b4
  sw    $s0, 0x10($sp)
  mul.s $f6, $f10, $f8
  addiu $a0, $sp, 0x200
  lw    $a1, 0x208($sp)
  lw    $a2, 0x204($sp)
  mfc1  $a3, $f6
  jal   sub_GAME_7F0B2314
   nop   
  jal   sub_GAME_7F0B23A4
   move  $a0, $s0
  beqz  $v0, .L7F085F90
   li    $t5, 1
  sw    $t5, 0x394($sp)
.L7F085F90:
  lw    $t0, ($s1)
  lui   $at, %hi(D_80055244)
  lwc1  $f10, %lo(D_80055244)($at)
  lwc1  $f4, 0x4b0($t0)
  lw    $a1, 0x48c($t0)
  lw    $a2, 0x494($t0)
  mul.s $f8, $f4, $f10
  sw    $s0, 0x10($sp)
  addiu $a0, $t0, 0x488
  mfc1  $a3, $f8
  jal   sub_GAME_7F0B2314
   nop   
  jal   sub_GAME_7F0B23A4
   move  $a0, $s0
  beqz  $v0, .L7F085FD4
   li    $t7, 1
  sw    $t7, 0x394($sp)
.L7F085FD4:
  lw    $t0, ($s1)
  lw    $a1, 0x48c($t0)
  lw    $a2, 0x494($t0)
  lw    $a3, 0x4b0($t0)
  sw    $s0, 0x10($sp)
  jal   sub_GAME_7F0B2314
   addiu $a0, $t0, 0x488
  jal   sub_GAME_7F0B23A4
   move  $a0, $s0
  bnez  $v0, .L7F086030
   nop   
  lw    $t6, ($s1)
  lui   $at, %hi(D_80055248)
  lwc1  $f4, %lo(D_80055248)($at)
  lwc1  $f6, 0x4b0($t6)
  sw    $s0, 0x10($sp)
  addiu $a0, $sp, 0x200
  mul.s $f10, $f6, $f4
  lw    $a1, 0x208($sp)
  lw    $a2, 0x204($sp)
  mfc1  $a3, $f10
  jal   sub_GAME_7F0B2314
   nop   
.L7F086030:
  jal   sub_GAME_7F0B23A4
   move  $a0, $s0
  beqz  $v0, .L7F08631C
   li    $t3, 1
  sw    $t3, 0x394($sp)
  addiu $a0, $sp, 0x174
  addiu $a1, $sp, 0x170
  jal   sub_GAME_7F0B2420
   addiu $a2, $sp, 0x184
  lw    $t8, ($s1)
  lwc1  $f8, 0x1a0($sp)
  lwc1  $f6, 0x74($t8)
  c.le.s $f6, $f8
  lwc1  $f8, 0x198($sp)
  lwc1  $f6, 0x18c($sp)
  bc1fl .L7F086320
   lw    $t0, ($s1)
  lwc1  $f4, 0x184($sp)
  lwc1  $f10, 0x190($sp)
  sub.s $f14, $f8, $f6
  sub.s $f2, $f4, $f10
  mul.s $f4, $f14, $f14
  swc1  $f14, 0x16c($sp)
  mul.s $f10, $f2, $f2
  swc1  $f2, 0x168($sp)
  jal   sqrtf
   add.s $f12, $f4, $f10
  lwc1  $f2, 0x168($sp)
  lwc1  $f14, 0x16c($sp)
  lwc1  $f8, 0x204($sp)
  div.s $f2, $f2, $f0
  lwc1  $f6, 0x18c($sp)
  swc1  $f8, 0x30($sp)
  sub.s $f4, $f8, $f6
  lwc1  $f8, 0x184($sp)
  swc1  $f6, 0x34($sp)
  div.s $f14, $f14, $f0
  mul.s $f10, $f4, $f2
  lwc1  $f4, 0x208($sp)
  sub.s $f6, $f4, $f8
  mul.s $f6, $f6, $f14
  add.s $f12, $f10, $f6
  lwc1  $f6, 0x30($sp)
  lwc1  $f10, 0x3b4($sp)
  swc1  $f12, 0x50($sp)
  add.s $f6, $f6, $f10
  lwc1  $f10, 0x34($sp)
  sub.s $f6, $f6, $f10
  mul.s $f10, $f6, $f2
  lwc1  $f6, 0x3ac($sp)
  add.s $f4, $f4, $f6
  sub.s $f6, $f4, $f8
  mul.s $f4, $f6, $f14
  add.s $f18, $f10, $f4
  lwc1  $f4, 0x3b4($sp)
  mul.s $f8, $f12, $f18
  mov.s $f16, $f18
  c.le.s $f8, $f20
  mul.s $f8, $f4, $f4
  bc1fl .L7F086130
   c.lt.s $f18, $f20
  b     .L7F0861A4
   mov.s $f14, $f20
  c.lt.s $f18, $f20
.L7F086130:
  nop   
  bc1fl .L7F08614C
   c.le.s $f12, $f16
  lwc1  $f12, 0x50($sp)
  neg.s $f16, $f18
  neg.s $f12, $f12
  c.le.s $f12, $f16
.L7F08614C:
  nop   
  bc1fl .L7F086164
   lw    $t4, ($s1)
  b     .L7F0861A4
   mov.s $f14, $f20
  lw    $t4, ($s1)
.L7F086164:
  lwc1  $f0, 0x4b0($t4)
  c.lt.s $f0, $f16
  nop   
  bc1fl .L7F086184
   c.lt.s $f12, $f0
  b     .L7F0861A4
   mov.s $f14, $f20
  c.lt.s $f12, $f0
.L7F086184:
  nop   
  bc1fl .L7F08619C
   sub.s $f6, $f12, $f0
  b     .L7F0861A4
   mov.s $f14, $f20
  sub.s $f6, $f12, $f0
.L7F08619C:
  sub.s $f10, $f12, $f16
  div.s $f14, $f6, $f10
.L7F0861A4:
  lwc1  $f6, 0x3ac($sp)
  swc1  $f14, 0x180($sp)
  mul.s $f10, $f6, $f6
  jal   sqrtf
   add.s $f12, $f8, $f10
  c.lt.s $f20, $f0
  lwc1  $f14, 0x180($sp)
  li    $at, 0x3F800000 # 1.000000
  bc1fl .L7F086234
   lwc1  $f6, 0x19c($sp)
  mtc1  $at, $f4
  li    $at, 0x3E800000 # 0.250000
  mtc1  $at, $f8
  sub.s $f6, $f4, $f14
  lw    $t9, ($s1)
  lwc1  $f4, 0x1a0($sp)
  li    $at, 0x3E800000 # 0.250000
  mul.s $f2, $f6, $f0
  nop   
  mul.s $f12, $f2, $f8
  swc1  $f12, 0x390($sp)
  lwc1  $f18, 0x74($t9)
  add.s $f10, $f18, $f12
  c.le.s $f4, $f10
  nop   
  bc1f  .L7F086230
   nop   
  sub.s $f6, $f4, $f18
  mtc1  $at, $f8
  nop   
  div.s $f10, $f6, $f8
  swc1  $f6, 0x390($sp)
  sub.s $f16, $f2, $f10
  div.s $f4, $f16, $f0
  add.s $f14, $f14, $f4
.L7F086230:
  lwc1  $f6, 0x19c($sp)
.L7F086234:
  lwc1  $f8, 0x184($sp)
  lwc1  $f10, 0x1a4($sp)
  lwc1  $f4, 0x18c($sp)
  sub.s $f12, $f6, $f8
  lwc1  $f6, 0x1a8($sp)
  lw    $t0, ($s1)
  sub.s $f16, $f10, $f4
  lwc1  $f10, 0x1b0($sp)
  sub.s $f18, $f6, $f8
  sub.s $f6, $f10, $f4
  mul.s $f8, $f18, $f18
  nop   
  mul.s $f10, $f6, $f6
  swc1  $f6, 0x48($sp)
  add.s $f4, $f8, $f10
  mul.s $f8, $f12, $f12
  nop   
  mul.s $f10, $f16, $f16
  add.s $f8, $f8, $f10
  lwc1  $f10, 0x1a0($sp)
  c.lt.s $f4, $f8
  lwc1  $f4, 0x188($sp)
  bc1f  .L7F08629C
   sub.s $f8, $f10, $f4
  mov.s $f12, $f18
  mov.s $f16, $f6
.L7F08629C:
  lwc1  $f6, 0x390($sp)
  lwc1  $f4, 0x3ac($sp)
  addiu $a0, $sp, 0x3ac
  div.s $f0, $f6, $f8
  move  $a1, $zero
  mul.s $f10, $f0, $f12
  nop   
  mul.s $f6, $f4, $f14
  add.s $f8, $f10, $f6
  mul.s $f4, $f0, $f16
  lwc1  $f10, 0x3b4($sp)
  swc1  $f8, 0x3ac($sp)
  mul.s $f6, $f10, $f14
  lwc1  $f10, 0x208($sp)
  add.s $f8, $f4, $f6
  swc1  $f8, 0x3b4($sp)
  swc1  $f10, 0x48c($t0)
  lw    $t2, ($s1)
  lwc1  $f4, 0x204($sp)
  swc1  $f4, 0x494($t2)
  lw    $t7, ($s1)
  lw    $t5, 0x200($sp)
  sw    $t5, 0x488($t7)
  lw    $t6, ($s1)
  lwc1  $f6, 0x1274($t6)
  c.eq.s $f20, $f6
  nop   
  bc1f  .L7F086314
   nop   
  li    $a1, 1
.L7F086314:
  jal   sub_GAME_7F07D960
   nop   
.L7F08631C:
  lw    $t0, ($s1)
.L7F086320:
  lwc1  $f10, 0x208($sp)
  lwc1  $f6, 0x204($sp)
  lwc1  $f8, 0x48c($t0)
  lwc1  $f4, 0x494($t0)
  sub.s $f2, $f8, $f10
  lwc1  $f8, 0x3b4($sp)
  sub.s $f14, $f4, $f6
  mul.s $f10, $f8, $f8
  lwc1  $f4, 0x3ac($sp)
  mul.s $f6, $f4, $f4
  add.s $f0, $f10, $f6
  c.eq.s $f0, $f20
  mov.s $f12, $f0
  bc1t  .L7F086370
   nop   
  mul.s $f8, $f2, $f2
  nop   
  mul.s $f4, $f14, $f14
  add.s $f10, $f8, $f4
  div.s $f12, $f10, $f0
.L7F086370:
  jal   sqrtf
   nop   
  lwc1  $f8, 0x220($sp)
  lw    $t0, ($s1)
  mul.s $f4, $f0, $f8
  lwc1  $f6, 0x1278($t0)
  add.s $f10, $f6, $f4
  swc1  $f10, 0x1278($t0)
  lwc1  $f6, 0x21c($sp)
  lw    $t0, ($s1)
  mul.s $f4, $f0, $f6
  lwc1  $f8, 0x127c($t0)
  add.s $f10, $f8, $f4
  swc1  $f10, 0x127c($t0)
.L7F0863A8:
  lw    $t0, ($s1)
.L7F0863AC:
  lui    $at, %hi(D_8005524C)
  lwc1  $f8, %lo(D_8005524C)($at)
  lwc1  $f6, 0x160($t0)
  li    $at, 0x40A00000 # 5.000000
  lwc1  $f10, 0xa4($t0)
  div.s $f4, $f6, $f8
  mtc1  $at, $f6
  lwc1  $f20, 0x14c($t0)
  div.s $f8, $f10, $f6
  add.s $f2, $f4, $f8
  jal   sub_GAME_7F08EAF8
   swc1  $f2, 0x144($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f14
  lwc1  $f2, 0x144($sp)
  mfc1  $a3, $f20
  mov.s $f12, $f0
  c.lt.s $f14, $f2
  li    $at, 0xBF800000 # -1.000000
  bc1fl .L7F08640C
   mtc1  $at, $f14
  b     .L7F086424
   mov.s $f2, $f14
  mtc1  $at, $f14
.L7F08640C:
  nop   
  c.lt.s $f2, $f14
  nop   
  bc1fl .L7F086428
   lw    $t3, ($s1)
  mov.s $f2, $f14
.L7F086424:
  lw    $t3, ($s1)
.L7F086428:
  li    $at, 1
  mfc1  $a2, $f2
  lw    $t8, 0x4e8($t3)
  bne   $t8, $at, .L7F086448
   lui   $at, %hi(D_80055250)
  lwc1  $f10, %lo(D_80055250)($at)
  mul.s $f12, $f0, $f10
  nop   
.L7F086448:
  jal   sub_GAME_7F05E0E4
   lwc1  $f14, 0x398($sp)
  lw    $t4, ($s1)
  lui   $at, %hi(D_80055254)
  lwc1  $f4, %lo(D_80055254)($at)
  lwc1  $f6, 0x15c($t4)
  mul.s $f12, $f6, $f4
  jal   sub_GAME_7F05E5F0
   nop   
  lui   $v1, %hi(ptr_playerstank)
  lw    $v1, %lo(ptr_playerstank)($v1)
  lui   $t9, %hi(in_tank_flag) 
  beql  $v1, $zero, .L7F086938
   lw    $a0, 0x394($sp)
  lw    $t9, %lo(in_tank_flag)($t9)
  li    $at, 1
  lui   $t2, %hi(dword_CODE_bss_800799B8) 
  bnel  $t9, $at, .L7F086938
   lw    $a0, 0x394($sp)
  lw    $t2, %lo(dword_CODE_bss_800799B8)($t2)
  li    $at, 2
  bnel  $t2, $at, .L7F086938
   lw    $a0, 0x394($sp)
  lw    $v0, 4($v1)
  move  $a0, $zero
  sw    $v0, 0x138($sp)
  lw    $t5, 0x14($v0)
  move  $s0, $v0
  lw    $t7, 8($t5)
  lw    $t6, 8($t7)
  lw    $t3, 0x14($t6)
  lw    $t8, 4($t3)
  jal   get_item_in_hand
   sw    $t8, 0x130($sp)
  xori  $v1, $v0, 0x20
  sltiu $a0, $v1, 1
  beql  $a0, $zero, .L7F0864F0
   sw    $a0, 0xc4($s0)
  jal   get_hands_firing_status
   move  $a0, $zero
  sltu  $a0, $zero, $v0
  sw    $a0, 0xc4($s0)
.L7F0864F0:
  lui   $at, %hi(D_8003646C)
  lwc1  $f8, %lo(D_8003646C)($at)
  lui   $at, %hi(D_80036474)
  addiu $a1, $sp, 0xf0
  swc1  $f8, 0xc8($s0)
  lwc1  $f10, %lo(D_80036474)($at)
  lui   $at, %hi(D_80036464)
  swc1  $f10, 0xcc($s0)
  lwc1  $f6, %lo(D_80036464)($at)
  lui   $at, %hi(D_80055258)
  swc1  $f6, 0xdc($s0)
  lwc1  $f4, %lo(D_80055258)($at)
  lui   $at, %hi(D_80036464)
  lwc1  $f8, %lo(D_80036464)($at)
  jal   sub_GAME_7F0585FC
   sub.s $f12, $f4, $f8
  lw    $t4, 0x138($sp)
  addiu $a1, $sp, 0xf0
  lw    $t9, 0x14($t4)
  jal   matrix_multiply_A1_by_F12
   lwc1  $f12, 0x14($t9)
  lui   $at, %hi(flt_CODE_bss_800799AC)
  lwc1  $f10, %lo(flt_CODE_bss_800799A8)($at)
  lwc1  $f4, %lo(flt_CODE_bss_800799AC)($at)
  lui   $at, %hi(flt_CODE_bss_800799B0)
  neg.s $f6, $f10
  lwc1  $f10, %lo(flt_CODE_bss_800799B0)($at)
  swc1  $f6, 0xe4($sp)
  neg.s $f8, $f4
  neg.s $f6, $f10
  swc1  $f8, 0xe8($sp)
  swc1  $f6, 0xec($sp)
  addiu $a0, $sp, 0xf0
  jal   sub_GAME_7F0583D8
   addiu $a1, $sp, 0xe4
  lw    $t0, ($s1)
  lwc1  $f4, 0xe4($sp)
  lwc1  $f6, 0xec($sp)
  lwc1  $f8, 0x48c($t0)
  lw    $v0, 0x138($sp)
  add.s $f10, $f4, $f8
  swc1  $f10, 0xe4($sp)
  lwc1  $f4, 0x494($t0)
  add.s $f8, $f6, $f4
  swc1  $f8, 0xec($sp)
  lw    $t2, 0x488($t0)
  lw    $t5, 0x10($v0)
  sw    $t2, 0x14($t5)
  lw    $t0, ($s1)
  lwc1  $f10, 0xec($sp)
  lw    $a0, 0x10($v0)
  lw    $a1, 0x48c($t0)
  lw    $a2, 0x494($t0)
  lw    $a3, 0xe4($sp)
  swc1  $f10, 0x10($sp)
  jal   sub_GAME_7F0B0BE4
   addiu $a0, $a0, 0x14
  lw    $t7, 0x138($sp)
  lw    $a1, 0xe4($sp)
  lw    $a2, 0xec($sp)
  lw    $t6, 0x10($t7)
  jal   sub_GAME_7F0B2970
   lw    $a0, 0x14($t6)
  lui   $v1, %hi(clock_timer)
  addiu $v1, %lo(clock_timer) # addiu $v1, $v1, -0x7c8c
  swc1  $f0, 0xd4($s0)
  lw    $t3, ($v1)
  move  $v0, $zero
  lui   $at, %hi(D_8005525C)
  blez  $t3, .L7F086638
   nop   
  lwc1  $f2, 0xd4($s0)
  lwc1  $f0, %lo(D_8005525C)($at)
  lwc1  $f6, 0xd0($s0)
.L7F086618:
  addiu $v0, $v0, 1
  mul.s $f4, $f6, $f0
  add.s $f8, $f4, $f2
  swc1  $f8, 0xd0($s0)
  lw    $t8, ($v1)
  slt   $at, $v0, $t8
  bnezl $at, .L7F086618
   lwc1  $f6, 0xd0($s0)
.L7F086638:
  lui   $at, %hi(D_80055260)
  lwc1  $f6, %lo(D_80055260)($at)
  lwc1  $f10, 0xd0($s0)
  lw    $a0, 0x130($sp)
  mul.s $f20, $f10, $f6
  jal   sub_GAME_7F03E864
   nop   
  lw    $v0, 0x138($sp)
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f6
  lw    $t4, 0x14($v0)
  addiu $a0, $sp, 0xf0
  addiu $a1, $v0, 0x18
  lwc1  $f4, 0x14($t4)
  mul.s $f8, $f0, $f4
  sub.s $f10, $f20, $f8
  add.s $f4, $f10, $f6
  jal   matrix_4x4_copy
   swc1  $f4, 0xe8($sp)
  lw    $a0, 0x138($sp)
  lwc1  $f0, 0xe4($sp)
  lw    $t9, 0x10($a0)
  swc1  $f0, 8($t9)
  swc1  $f0, 0x58($a0)
  lwc1  $f0, 0xe8($sp)
  lw    $t2, 0x10($a0)
  swc1  $f0, 0xc($t2)
  swc1  $f0, 0x5c($a0)
  lwc1  $f0, 0xec($sp)
  lw    $t5, 0x10($a0)
  swc1  $f0, 0x10($t5)
  jal   sub_GAME_7F056CA0
   swc1  $f0, 0x60($a0)
  jal   sub_GAME_7F040484
   lw    $a0, 0x138($sp)
  lw    $a1, ($s1)
  lui   $a2, %hi(D_80036464)
  lw    $a2, %lo(D_80036464)($a2)
  addiu $a0, $sp, 0xb4
  jal   sub_GAME_7F07C888
   addiu $a1, $a1, 0x48c
  lw    $t7, 0x138($sp)
  addiu $s0, $sp, 0x94
  move  $a1, $s0
  jal   sub_GAME_7F03CB8C
   lw    $a0, 0x10($t7)
  jal   sub_GAME_7F03E3FC
   move  $a0, $s0
  lui   $t6, %hi(ptr_list_object_lookup_indices) 
  lw    $t6, %lo(ptr_list_object_lookup_indices)($t6)
  li    $at, 0x40400000 # 3.000000
  sw    $t6, 0x8c($sp)
  lh    $v0, ($t6)
  bltzl $v0, .L7F086938
   lw    $a0, 0x394($sp)
  mtc1  $at, $f20
  nop   
  lw    $t4, 0x138($sp)
.L7F086720:
  sll   $t3, $v0, 2
  subu  $t3, $t3, $v0
  sll   $t3, $t3, 2
  lw    $t9, 0x10($t4)
  addu  $t3, $t3, $v0
  lui   $t8, %hi(pos_data_entry) 
  addiu $t8, %lo(pos_data_entry) # addiu $t8, $t8, -0x63c8
  sll   $t3, $t3, 2
  addu  $s0, $t3, $t8
  beql  $s0, $t9, .L7F086920
   lw    $t7, 0x8c($sp)
  lbu   $v0, ($s0)
  li    $at, 3
  li    $t2, 1
  bne   $v0, $at, .L7F0868AC
   move  $a0, $s0
  sw    $t2, 0x7c($sp)
  lw    $t0, 4($s0)
  addiu $a1, $sp, 0x80
  addiu $a2, $sp, 0x88
  addiu $a3, $sp, 0x84
  jal   sub_GAME_7F03CF88
   sw    $t0, 0x6c($sp)
  addiu $a0, $s0, 8
  sw    $a0, 0x50($sp)
  addiu $a1, $sp, 0xb4
  jal   sub_GAME_7F03CCD8
   li    $a2, 4
  beqz  $v0, .L7F086840
   lw    $t0, 0x6c($sp)
  sw    $zero, 0x7c($sp)
  lb    $t5, 7($t0)
  li    $at, 4
  bnel  $t5, $at, .L7F086844
   lw    $t4, 0x7c($sp)
  lw    $v1, 0x14($t0)
  lui   $at, 0x100
  lui   $v0, %hi(D_80048380)
  sll   $t7, $v1, 7
  bltz  $t7, .L7F086840
   or    $t6, $v1, $at
  sw    $t6, 0x14($t0)
  lw    $v0, %lo(D_80048380)($v0)
  li    $at, 3
  lui   $a0, %hi(ptr_sfx_buf)
  div   $zero, $v0, $at
  mfhi  $v0
  slti  $at, $v0, 2
  beqz  $at, .L7F08681C
   li    $a1, 183
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   move  $a2, $zero
  move  $a0, $v0
  jal   sub_GAME_7F053A10
   lw    $a1, 0x50($sp)
  lui   $v0, %hi(D_80048380)
  lw    $v0, %lo(D_80048380)($v0)
  li    $at, 3
  div   $zero, $v0, $at
  mfhi  $v0
  nop   
  nop   
.L7F08681C:
  blez  $v0, .L7F086840
   lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 213
  jal   play_sfx_a1
   move  $a2, $zero
  move  $a0, $v0
  jal   sub_GAME_7F053A10
   lw    $a1, 0x50($sp)
.L7F086840:
  lw    $t4, 0x7c($sp)
.L7F086844:
  lw    $a0, 0x50($sp)
  lw    $a1, 0x80($sp)
  beqz  $t4, .L7F086868
   addiu $a2, $sp, 0xb4
  jal   sub_GAME_7F044718
   li    $a3, 4
  beql  $v0, $zero, .L7F08686C
   lw    $t9, 0x7c($sp)
  sw    $zero, 0x7c($sp)
.L7F086868:
  lw    $t9, 0x7c($sp)
.L7F08686C:
  lw    $t2, 0x138($sp)
  bnezl $t9, .L7F086920
   lw    $t7, 0x8c($sp)
  lwc1  $f8, 0x58($t2)
  mfc1  $a2, $f20
  addiu $a1, $sp, 0x70
  swc1  $f8, 0x70($sp)
  lwc1  $f10, 0xc($s0)
  li    $a3, 1
  swc1  $f10, 0x74($sp)
  lwc1  $f6, 0x60($t2)
  swc1  $f6, 0x78($sp)
  jal   sub_GAME_7F027804
   lw    $a0, 4($s0)
  b     .L7F086920
   lw    $t7, 0x8c($sp)
.L7F0868AC:
  li    $at, 1
  bne   $v0, $at, .L7F08691C
   move  $a0, $s0
  addiu $a1, $sp, 0x64
  jal   sub_GAME_7F03CCB0
   addiu $a2, $sp, 0x60
  lw    $a1, 0x60($sp)
  lw    $a0, 0x64($sp)
  addiu $a2, $sp, 0xb4
  blezl $a1, .L7F086920
   lw    $t7, 0x8c($sp)
  jal   sub_GAME_7F0446B8
   li    $a3, 4
  beql  $v0, $zero, .L7F086920
   lw    $t7, 0x8c($sp)
  jal   get_cur_playernum
   nop   
  lw    $a2, 4($s0)
  lui   $a1, (0x461C4000 >> 16) # lui $a1, 0x461c
  ori   $a1, (0x461C4000 & 0xFFFF) # ori $a1, $a1, 0x4000
  sw    $v0, 0x10($sp)
  move  $a0, $s0
  li    $a3, 32
  jal   sub_GAME_7F04DEFC
   addiu $a2, $a2, 0x58
  li    $t5, 90
  lui   $at, %hi(D_80036490)
  sw    $t5, %lo(D_80036490)($at)
.L7F08691C:
  lw    $t7, 0x8c($sp)
.L7F086920:
  addiu $t6, $t7, 2
  sw    $t6, 0x8c($sp)
  lh    $v0, ($t6)
  bgezl $v0, .L7F086720
   lw    $t4, 0x138($sp)
  lw    $a0, 0x394($sp)
.L7F086938:
  jal   sub_GAME_7F080DF8
   lw    $a1, 0x390($sp)
  jal   sub_GAME_7F081478
   nop   
  jal   sub_GAME_7F08A19C
   nop   
  jal   get_debug_man_pos_flag
   nop   
  beql  $v0, $zero, .L7F08697C
   lw    $ra, 0x2c($sp)
  lw    $t0, ($s1)
  addiu $a3, $sp, 0x5c
  lw    $a0, 0x488($t0)
  lw    $a1, 0x48c($t0)
  jal   copy_tile_RGB_as_24bit
   lw    $a2, 0x494($t0)
  lw    $ra, 0x2c($sp)
.L7F08697C:
  ldc1  $f20, 0x18($sp)
  lw    $s0, 0x24($sp)
  lw    $s1, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x3b8
");

#ifdef VERSION_JP
asm(R"
.late_rodata
glabel D_8005516C
.word 0x3d888889 /*0.06666667*/
glabel D_80055170
.word 0x40c90fdb /*6.2831855*/
glabel D_80055174
.word 0x3c8efa35 /*0.017453292*/
glabel D_80055178
.word 0x3f8147ae  /*1.01*/
glabel D_8005517C
.word 0x3f8147ae  /*1.01*/
glabel D_80055180
.word 0x40c90fdb /*6.2831855*/
glabel D_80055184
.word 0x3c8efa35 /*0.017453292*/
glabel D_80055188
.word 0x40490fdb /*3.1415927*/
glabel D_8005518C
.word 0x40c90fdb /*6.2831855*/
glabel D_80055190
.word 0xc0490fdb /*-3.1415927*/
glabel D_80055194
.word 0x40c90fdb /*6.2831855*/
glabel D_80055198
.word 0x3f6b851f /*0.92000002*/
glabel D_8005519C
.word 0x3da3d708 /*0.079999983*/
glabel D_800551A0
.word 0x40c90fdb /*6.2831855*/
glabel D_800551A4
.word 0x3f6b851f /*0.92000002*/
glabel D_800551A8
.word 0x3f6b851f /*0.92000002*/
glabel D_800551AC
.word 0x3da3d708 /*0.079999983*/
glabel D_800551B0
.word 0x3f6b851f /*0.92000002*/
glabel D_800551B4
.word 0x3f6b851f /*0.92000002*/
glabel D_800551B8
.word 0x3f6b851f /*0.92000002*/
glabel D_800551BC
.word 0x40c90fdb /*6.2831855*/
glabel D_800551C0
.word 0x3f6b851f /*0.92000002*/
glabel D_800551C4
.word 0x3f6b851f /*0.92000002*/
glabel D_800551C8
.word 0x3f6b851f /*0.92000002*/
glabel D_800551CC
.word 0x3f6b851f /*0.92000002*/
glabel D_800551D0
.word 0x3da3d708 /*0.079999983*/
glabel D_800551D4
.word 0x3c8efa35 /*0.017453292*/
glabel D_800551D8
.word 0x40c90fdb /*6.2831855*/
glabel D_800551DC
.word 0x40c90fdb /*6.2831855*/
glabel D_800551E0
.word 0x40c90fdb /*6.2831855*/
glabel D_800551E4
.word 0x40c90fdb /*6.2831855*/
glabel D_800551E8
.word 0x3e99999a /*0.30000001*/
glabel D_800551EC
.word 0x3e19999a /*0.15000001*/
glabel D_800551F0
.word 0x469c4000 /*20000.0*/
glabel D_800551F4
.word 0x3f666666 /*0.89999998*/
glabel D_800551F8
.word 0x46477c00 /*12767.0*/
glabel D_800551FC
.word 0x469c4000 /*20000.0*/
glabel D_80055200
.word 0x3f666666 /*0.89999998*/
glabel D_80055204
.word 0x45f2b800 /*7767.0*/
glabel D_80055208
.word 0x3f666666 /*0.89999998*/
glabel D_8005520C
.word 0x46c35000 /*25000.0;*/
glabel D_80055210
.word 0x3e32b8c3 /*0.17453294*/
glabel D_80055214
.word 0x3edf66f3 /*0.43633232*/
glabel D_80055218
.word 0xbdb2b8c3 /*-0.087266468*/
glabel D_8005521C
.word 0x3f70a3d7 /*0.94*/
glabel D_80055220
.word 0x3d75c290 /*0.060000002*/
glabel D_80055224
.word 0x4528c000 /*2700.0*/
glabel D_80055228
.word 0x40c90fdb /*6.2831855*/
glabel D_8005522C
.word 0x40c90fdb /*6.2831855*/
glabel D_80055230
.word 0x3f19999a /*0.60000002*/
glabel D_80055234
.word 0x3f4ccccd /*0.80000001*/
glabel D_80055238
.word 0x3dcccccd /*0.1*/
glabel D_8005523C
.word 0x4528c000 /*2700.0*/
glabel D_80055240
.word 0x3f947ae1 /*1.16*/
glabel D_80055244
.word 0x3f8147ae  /*1.01*/
glabel D_80055248
.word 0x3f7d7721 /*0.99009901*/
glabel D_8005524C
.word 0x3f333333 /*0.69999999*/
glabel D_80055250
.word 0x3f99999a /*1.2*/
glabel D_80055254
.word 0x3c8efa35 /*0.017453292*/
glabel D_80055258
.word 0x40c90fdb /*6.2831855*/
glabel D_8005525C
.word 0x3f547ae1 /*0.82999998*/
glabel D_80055260
.word 0x3e2e147c /*0.17000002*/
.text
glabel MoveBond
  addiu $sp, $sp, -0x3b8
  lui   $t9, %hi(D_800367F4) # $t9, 0x8003
  sw    $ra, 0x2c($sp)
  sw    $s1, 0x28($sp)
  sw    $s0, 0x24($sp)
  sdc1  $f20, 0x18($sp)
  sw    $a0, 0x3b8($sp)
  sw    $a1, 0x3bc($sp)
  sw    $a2, 0x3c0($sp)
  sw    $a3, 0x3c4($sp)
  addiu $t9, %lo(D_800367F4) # addiu $t9, $t9, 0x6834
  lw    $at, ($t9)
  addiu $t2, $sp, 0x3ac
  lw    $t4, 4($t9)
  sw    $at, ($t2)
  lw    $at, 8($t9)
  mtc1  $zero, $f20
  sll   $s0, $a0, 0x18
  sw    $at, 8($t2)
  sra   $t6, $s0, 0x18
  sw    $t4, 4($t2)
  slti  $at, $t6, 0x64
  move  $s0, $t6
  sw    $zero, 0x394($sp)
  swc1  $f20, 0x398($sp)
  beqz  $at, .Ljp7F084D70
   swc1  $f20, 0x390($sp)
  slti  $at, $t6, -0x63
  beql  $at, $zero, .Ljp7F084D7C
   lb    $t3, 0x3bf($sp)
.Ljp7F084D70:
  jal   return_null
   nop   
  lb    $t3, 0x3bf($sp)
.Ljp7F084D7C:
  slti  $at, $t3, 0x64
  beqz  $at, .Ljp7F084D90
   slti  $at, $t3, -0x63
  beqz  $at, .Ljp7F084D98
   nop   
.Ljp7F084D90:
  jal   return_null
   nop   
.Ljp7F084D98:
  lui   $v1, %hi(camera_80036424) # $v1, 0x8003
  addiu $v1, %lo(camera_80036424) # addiu $v1, $v1, 0x6464
  lw    $v0, ($v1)
  blez  $v0, .Ljp7F084DFC
   addiu $t5, $v0, 1
  slti  $at, $t5, 4
  bnez  $at, .Ljp7F084DFC
   sw    $t5, ($v1)
  lui   $s1, %hi(pPlayer) # $s1, 0x8008
  addiu $s1, %lo(pPlayer) # addiu $s1, $s1, -0x5ee0
  lw    $t8, ($s1)
  sw    $zero, ($v1)
  li    $a0, 1
  sw    $zero, 0x2a54($t8)
  lw    $t7, ($s1)
  jal   get_item_in_hand
   sw    $zero, 0x2a50($t7)
  li    $a0, 1
  jal   remove_hands_item
   move  $a1, $v0
  jal   get_item_in_hand
   move  $a0, $zero
  move  $a0, $zero
  jal   remove_hands_item
   move  $a1, $v0
.Ljp7F084DFC:
  lui   $s1, %hi(pPlayer) # $s1, 0x8008
  addiu $s1, %lo(pPlayer) # addiu $s1, $s1, -0x5ee0
  jal   setptrBONDdata
   move  $a0, $zero
  jal   sub_GAME_7F083FC8
   nop   
  jal   sub_GAME_7F084360
   nop   
  sll   $a0, $s0, 0x18
  sra   $t2, $a0, 0x18
  move  $a0, $t2
  lb    $a1, 0x3bf($sp)
  lhu   $a2, 0x3c2($sp)
  jal   controller_gameplay_interaction
   lhu   $a3, 0x3c6($sp)
  jal   get_controls_locked_flag
   nop   
  beql  $v0, $zero, .Ljp7F084E54
   lw    $t9, ($s1)
  jal   sub_GAME_7F07EAF0
   nop   
  lw    $t9, ($s1)
.Ljp7F084E54:
  lw    $t4, 0x1c8($t9)
  beqz  $t4, .Ljp7F084E68
   nop   
  jal   sub_GAME_7F07EC54
   nop   
.Ljp7F084E68:
  lui   $t3, %hi(in_tank_flag) # $t3, 0x8003
  lw    $t3, %lo(in_tank_flag)($t3)
  bnez  $t3, .Ljp7F08502C
   nop   
  jal   sub_GAME_7F0799F0
   nop   
  bnezl $v0, .Ljp7F084EB8
   lw    $t0, ($s1)
  lw    $t0, ($s1)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f10
  lwc1  $f4, 0x174($t0)
  mul.s $f6, $f4, $f10
  mtc1  $at, $f4
  swc1  $f6, 0x174($t0)
  lw    $t0, ($s1)
  lwc1  $f8, 0x16c($t0)
  mul.s $f10, $f8, $f4
  swc1  $f10, 0x16c($t0)
  lw    $t0, ($s1)
.Ljp7F084EB8:
  lwc1  $f18, 0x180($t0)
  c.eq.s $f20, $f18
  nop   
  bc1fl .Ljp7F084EE4
   lwc1  $f0, 0x188($t0)
  lwc1  $f6, 0x188($t0)
  c.eq.s $f20, $f6
  nop   
  bc1t  .Ljp7F08502C
   nop   
  lwc1  $f0, 0x188($t0)
.Ljp7F084EE4:
  lwc1  $f2, 0x150($t0)
  lwc1  $f16, 0x154($t0)
  neg.s $f14, $f18
  mul.s $f8, $f0, $f2
  nop   
  mul.s $f4, $f14, $f16
  add.s $f10, $f8, $f4
  mul.s $f6, $f14, $f2
  nop   
  mul.s $f8, $f0, $f16
  swc1  $f10, 0x38c($sp)
  mul.s $f10, $f0, $f0
  sub.s $f4, $f6, $f8
  mul.s $f6, $f18, $f18
  swc1  $f4, 0x388($sp)
  jal   sqrtf
   add.s $f12, $f10, $f6
  lw    $t0, ($s1)
  lwc1  $f4, 0x38c($sp)
  lui   $at, %hi(D_8005516C) # $at, 0x8005
  lwc1  $f8, 0x174($t0)
  lui   $t1, %hi(global_timer_delta) # $t1, 0x8005
  addiu $t1, %lo(global_timer_delta) # addiu $t1, $t1, -0x7c4c
  add.s $f10, $f8, $f4
  move  $v1, $zero
  li    $a0, 12
  swc1  $f10, 0x174($t0)
  lw    $t0, ($s1)
  lwc1  $f8, 0x388($sp)
  lwc1  $f6, 0x16c($t0)
  add.s $f4, $f6, $f8
  swc1  $f4, 0x16c($t0)
  lwc1  $f12, %lo(D_8005516C)($at)
  lw    $t5, ($s1)
.Ljp7F084F6C:
  addu  $v0, $t5, $v1
  lwc1  $f2, 0x180($v0)
  c.eq.s $f20, $f2
  nop   
  bc1tl .Ljp7F085024
   addiu $v1, $v1, 4
  c.lt.s $f20, $f2
  nop   
  bc1fl .Ljp7F084FD8
   c.lt.s $f2, $f20
  lwc1  $f10, ($t1)
  mul.s $f6, $f12, $f10
  nop   
  mul.s $f8, $f6, $f2
  div.s $f4, $f8, $f0
  sub.s $f10, $f2, $f4
  swc1  $f10, 0x180($v0)
  lw    $t6, ($s1)
  addu  $v0, $t6, $v1
  lwc1  $f6, 0x180($v0)
  c.lt.s $f6, $f20
  nop   
  bc1f  .Ljp7F085020
   nop   
  b     .Ljp7F085020
   swc1  $f20, 0x180($v0)
  c.lt.s $f2, $f20
.Ljp7F084FD8:
  nop   
  bc1fl .Ljp7F085024
   addiu $v1, $v1, 4
  lwc1  $f8, ($t1)
  mul.s $f4, $f12, $f8
  nop   
  mul.s $f10, $f4, $f2
  div.s $f6, $f10, $f0
  sub.s $f8, $f2, $f6
  swc1  $f8, 0x180($v0)
  lw    $t8, ($s1)
  addu  $v0, $t8, $v1
  lwc1  $f4, 0x180($v0)
  c.lt.s $f20, $f4
  nop   
  bc1f  .Ljp7F085020
   nop   
  swc1  $f20, 0x180($v0)
.Ljp7F085020:
  addiu $v1, $v1, 4
.Ljp7F085024:
  bnel  $v1, $a0, .Ljp7F084F6C
   lw    $t5, ($s1)
.Ljp7F08502C:
  lui   $t7, %hi(in_tank_flag) # $t7, 0x8003
  lw    $t7, %lo(in_tank_flag)($t7)
  lui   $t1, %hi(global_timer_delta) # $t1, 0x8005
  li    $at, 1
  addiu $t1, %lo(global_timer_delta) # addiu $t1, $t1, -0x7c4c
  bne   $t7, $at, .Ljp7F085888
   lw    $t0, ($s1)
  lwc1  $f10, 0x14c($t0)
  lwc1  $f6, ($t1)
  lui   $at, %hi(D_80055170) # $at, 0x8005
  lwc1  $f12, %lo(D_80055170)($at)
  mul.s $f8, $f10, $f6
  lui   $at, %hi(D_80055174) # $at, 0x8005
  lwc1  $f4, %lo(D_80055174)($at)
  li    $at, 0x40600000 # 3.500000
  mtc1  $at, $f6
  lui   $at, %hi(D_80036464) # $at, 0x8003
  addiu $s0, $sp, 0x374
  mul.s $f10, $f8, $f4
  lwc1  $f8, %lo(D_80036464)($at)
  move  $a3, $s0
  addiu $a0, $t0, 0x48c
  addiu $t2, $sp, 0x368
  mul.s $f2, $f10, $f6
  add.s $f0, $f8, $f2
  c.le.s $f12, $f0
  nop   
  bc1fl .Ljp7F0850A8
   c.lt.s $f0, $f20
  sub.s $f0, $f0, $f12
  c.lt.s $f0, $f20
.Ljp7F0850A8:
  nop   
  bc1fl .Ljp7F0850BC
   lw    $a1, 0x488($t0)
  add.s $f0, $f0, $f12
  lw    $a1, 0x488($t0)
.Ljp7F0850BC:
  mfc1  $a2, $f0
  swc1  $f2, 0x358($sp)
  swc1  $f0, 0x35c($sp)
  jal   sub_GAME_7F07CAC8
   sw    $t2, 0x10($sp)
  beql  $v0, $zero, .Ljp7F0850F0
   lui   $at, 0xbf80
  lwc1  $f4, 0x35c($sp)
  li    $at, 0x80030000 # -0.000000
  swc1  $f4, %lo(D_80036464)($at)
  b     .Ljp7F085414
   lw    $t0, ($s1)
  li    $at, 0xBF800000 # -1.000000
.Ljp7F0850F0:
  mtc1  $at, $f10
  mtc1  $at, $f6
  addiu $a0, $sp, 0x348
  addiu $a1, $sp, 0x33c
  swc1  $f10, 0x31c($sp)
  jal   sub_GAME_7F0B28B0
   swc1  $f6, 0x304($sp)
  lwc1  $f8, 0x33c($sp)
  lwc1  $f4, 0x348($sp)
  lwc1  $f10, 0x344($sp)
  lwc1  $f6, 0x350($sp)
  sub.s $f2, $f8, $f4
  sub.s $f14, $f10, $f6
  mul.s $f8, $f2, $f2
  swc1  $f2, 0x338($sp)
  mul.s $f4, $f14, $f14
  swc1  $f14, 0x334($sp)
  jal   sqrtf
   add.s $f12, $f8, $f4
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  lwc1  $f2, 0x338($sp)
  lwc1  $f14, 0x334($sp)
  div.s $f16, $f10, $f0
  lw    $t0, ($s1)
  lwc1  $f10, 0x370($sp)
  mul.s $f2, $f2, $f16
  nop   
  mul.s $f14, $f14, $f16
  neg.s $f12, $f2
  swc1  $f12, 0x320($sp)
  swc1  $f14, 0x324($sp)
  lwc1  $f6, 0x494($t0)
  swc1  $f6, 0x48($sp)
  lwc1  $f4, 0x48($sp)
  lwc1  $f8, 0x48c($t0)
  sub.s $f6, $f4, $f10
  swc1  $f8, 0x44($sp)
  lwc1  $f4, 0x44($sp)
  lwc1  $f10, 0x368($sp)
  mul.s $f8, $f6, $f12
  sub.s $f6, $f4, $f10
  mul.s $f4, $f6, $f14
  add.s $f18, $f8, $f4
  c.lt.s $f18, $f20
  nop   
  bc1f  .Ljp7F0851C4
   nop   
  neg.s $f10, $f14
  neg.s $f6, $f12
  neg.s $f18, $f18
  swc1  $f10, 0x324($sp)
  swc1  $f6, 0x320($sp)
.Ljp7F0851C4:
  lwc1  $f8, 0x48($sp)
  lwc1  $f4, 0x350($sp)
  lwc1  $f6, 0x320($sp)
  sub.s $f10, $f8, $f4
  lwc1  $f4, 0x44($sp)
  mul.s $f8, $f10, $f6
  lwc1  $f10, 0x348($sp)
  sub.s $f6, $f4, $f10
  lwc1  $f4, 0x324($sp)
  mul.s $f10, $f6, $f4
  add.s $f0, $f8, $f10
  c.lt.s $f0, $f18
  nop   
  bc1fl .Ljp7F08520C
   lwc1  $f4, 0x368($sp)
  sub.s $f6, $f18, $f0
  swc1  $f6, 0x31c($sp)
  lwc1  $f4, 0x368($sp)
.Ljp7F08520C:
  lwc1  $f8, 0x374($sp)
  lwc1  $f10, 0x370($sp)
  lwc1  $f6, 0x37c($sp)
  sub.s $f2, $f4, $f8
  sub.s $f14, $f10, $f6
  mul.s $f4, $f2, $f2
  swc1  $f2, 0x338($sp)
  mul.s $f8, $f14, $f14
  swc1  $f14, 0x334($sp)
  jal   sqrtf
   add.s $f12, $f4, $f8
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  lwc1  $f2, 0x338($sp)
  lwc1  $f14, 0x334($sp)
  div.s $f16, $f10, $f0
  lw    $t0, ($s1)
  lwc1  $f10, 0x370($sp)
  mul.s $f2, $f2, $f16
  nop   
  mul.s $f14, $f14, $f16
  neg.s $f12, $f2
  swc1  $f12, 0x308($sp)
  swc1  $f14, 0x30c($sp)
  lwc1  $f6, 0x494($t0)
  swc1  $f6, 0x48($sp)
  lwc1  $f8, 0x48($sp)
  lwc1  $f4, 0x48c($t0)
  sub.s $f6, $f8, $f10
  swc1  $f4, 0x44($sp)
  lwc1  $f8, 0x44($sp)
  lwc1  $f10, 0x368($sp)
  mul.s $f4, $f6, $f12
  sub.s $f6, $f8, $f10
  mul.s $f8, $f6, $f14
  add.s $f18, $f4, $f8
  c.lt.s $f18, $f20
  nop   
  bc1f  .Ljp7F0852C0
   nop   
  neg.s $f16, $f14
  neg.s $f10, $f12
  neg.s $f18, $f18
  swc1  $f10, 0x308($sp)
  swc1  $f16, 0x30c($sp)
.Ljp7F0852C0:
  lwc1  $f6, 0x48($sp)
  lwc1  $f4, 0x350($sp)
  lwc1  $f12, 0x308($sp)
  lwc1  $f16, 0x30c($sp)
  sub.s $f8, $f6, $f4
  lwc1  $f4, 0x44($sp)
  mul.s $f10, $f8, $f12
  lwc1  $f8, 0x348($sp)
  sub.s $f8, $f4, $f8
  mul.s $f8, $f8, $f16
  add.s $f0, $f10, $f8
  lwc1  $f10, 0x344($sp)
  sub.s $f8, $f6, $f10
  lwc1  $f10, 0x33c($sp)
  mul.s $f6, $f8, $f12
  sub.s $f8, $f4, $f10
  mul.s $f4, $f8, $f16
  add.s $f2, $f6, $f4
  c.lt.s $f2, $f0
  nop   
  bc1fl .Ljp7F085320
   c.lt.s $f0, $f18
  mov.s $f0, $f2
  c.lt.s $f0, $f18
.Ljp7F085320:
  nop   
  bc1fl .Ljp7F085338
   lwc1  $f2, 0x304($sp)
  sub.s $f2, $f18, $f0
  swc1  $f2, 0x304($sp)
  lwc1  $f2, 0x304($sp)
.Ljp7F085338:
  lwc1  $f10, 0x31c($sp)
  c.le.s $f20, $f2
  nop   
  bc1fl .Ljp7F08537C
   lwc1  $f0, 0x31c($sp)
  c.lt.s $f2, $f10
  nop   
  bc1tl .Ljp7F085370
   swc1  $f16, 0x324($sp)
  c.lt.s $f10, $f20
  nop   
  bc1fl .Ljp7F08537C
   lwc1  $f0, 0x31c($sp)
  swc1  $f16, 0x324($sp)
.Ljp7F085370:
  swc1  $f12, 0x320($sp)
  swc1  $f2, 0x31c($sp)
  lwc1  $f0, 0x31c($sp)
.Ljp7F08537C:
  lwc1  $f8, 0x324($sp)
  c.le.s $f20, $f0
  nop   
  bc1fl .Ljp7F085414
   swc1  $f20, 0x358($sp)
  mul.s $f6, $f0, $f8
  lui   $at, %hi(D_80055178) # $at, 0x8005
  lwc1  $f4, %lo(D_80055178)($at)
  lwc1  $f8, 0x320($sp)
  lui   $at, %hi(D_8005517C) # $at, 0x8005
  addiu $a0, $sp, 0x3ac
  li    $a1, 1
  mul.s $f10, $f6, $f4
  lwc1  $f4, %lo(D_8005517C)($at)
  mul.s $f6, $f0, $f8
  swc1  $f10, 0x3ac($sp)
  mul.s $f10, $f6, $f4
  jal   sub_GAME_7F07D960
   swc1  $f10, 0x3b4($sp)
  lw    $t0, ($s1)
  swc1  $f20, 0x3ac($sp)
  swc1  $f20, 0x3b4($sp)
  addiu $t9, $sp, 0x368
  lw    $a1, 0x488($t0)
  sw    $t9, 0x10($sp)
  lw    $a2, 0x35c($sp)
  move  $a3, $s0
  jal   sub_GAME_7F07CAC8
   addiu $a0, $t0, 0x48c
  beqz  $v0, .Ljp7F085404
   lwc1  $f8, 0x35c($sp)
  lui   $at, %hi(D_80036464) # $at, 0x8003
  b     .Ljp7F085408
   swc1  $f8, %lo(D_80036464)($at)
.Ljp7F085404:
  swc1  $f20, 0x358($sp)
.Ljp7F085408:
  b     .Ljp7F085414
   lw    $t0, ($s1)
  swc1  $f20, 0x358($sp)
.Ljp7F085414:
  lui   $at, %hi(D_80055180) # $at, 0x8005
  lwc1  $f14, %lo(D_80055180)($at)
  lui   $v1, %hi(D_80036484) # $v1, 0x8003
  addiu $v1, %lo(D_80036484) # addiu $v1, $v1, 0x64c4
  lui   $at, %hi(D_80036488) # $at, 0x8003
  lwc1  $f4, %lo(D_80036488)($at)
  lwc1  $f6, ($v1)
  lui   $a3, %hi(D_80036474) # $a3, 0x8003
  addiu $a3, %lo(D_80036474) # addiu $a3, $a3, 0x64b4
  add.s $f10, $f6, $f4
  lwc1  $f12, ($a3)
  li    $at, 0x40600000 # 3.500000
  lui   $a0, %hi(clock_timer) # $a0, 0x8005
  swc1  $f10, ($v1)
  lwc1  $f0, ($v1)
  mtc1  $at, $f10
  mov.s $f16, $f12
  c.le.s $f14, $f0
  nop   
  bc1fl .Ljp7F085478
   c.lt.s $f0, $f20
  sub.s $f8, $f0, $f14
  swc1  $f8, ($v1)
  lwc1  $f0, ($v1)
  c.lt.s $f0, $f20
.Ljp7F085478:
  nop   
  bc1fl .Ljp7F085494
   lwc1  $f4, 0x14c($t0)
  add.s $f6, $f0, $f14
  swc1  $f6, ($v1)
  lwc1  $f0, ($v1)
  lwc1  $f4, 0x14c($t0)
.Ljp7F085494:
  lui   $at, %hi(D_80055184) # $at, 0x8005
  lwc1  $f6, %lo(D_80055184)($at)
  mul.s $f8, $f4, $f10
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f10
  lui   $at, %hi(D_80055188) # $at, 0x8005
  mul.s $f4, $f8, $f6
  nop   
  mul.s $f8, $f4, $f10
  add.s $f2, $f8, $f0
  c.lt.s $f2, $f20
  nop   
  bc1f  .Ljp7F0854D0
   nop   
  add.s $f2, $f2, $f14
.Ljp7F0854D0:
  c.le.s $f14, $f2
  nop   
  bc1fl .Ljp7F0854E8
   sub.s $f0, $f2, $f12
  sub.s $f2, $f2, $f14
  sub.s $f0, $f2, $f12
.Ljp7F0854E8:
  lwc1  $f6, %lo(D_80055188)($at)
  lui   $at, %hi(D_80055190)
  c.le.s $f6, $f0
  nop   
  bc1f  .Ljp7F085510
   nop   
  lui   $at, %hi(D_8005518C) # $at, 0x8005
  lwc1  $f4, %lo(D_8005518C)($at)
  b     .Ljp7F085530
   sub.s $f2, $f2, $f4
.Ljp7F085510:
  lwc1  $f10, %lo(D_80055190)($at)
  lui   $at, %hi(D_80055194) # $at, 0x8005
  c.lt.s $f0, $f10
  nop   
  bc1f  .Ljp7F085530
   nop   
  lwc1  $f8, %lo(D_80055194)($at)
  add.s $f2, $f2, $f8
.Ljp7F085530:
  lw    $a0, %lo(clock_timer)($a0)
  move  $v0, $zero
  lui   $at, %hi(D_80055198) # $at, 0x8005
  blez  $a0, .Ljp7F08558C
   lui   $s0, %hi(D_80036478) # $s0, 0x8003
  lwc1  $f14, %lo(D_80055198)($at)
  addiu $s0, %lo(D_80036478) # addiu $s0, $s0, 0x64b8
  lwc1  $f12, ($s0)
  addiu $v0, $v0, 1
  slt   $at, $v0, $a0
  mul.s $f18, $f14, $f12
  beql  $at, $zero, .Ljp7F085588
   add.s $f12, $f18, $f2
  add.s $f12, $f18, $f2
.Ljp7F085568:
  addiu $v0, $v0, 1
  slt   $at, $v0, $a0
  swc1  $f12, ($s0)
  lwc1  $f12, ($s0)
  mul.s $f18, $f14, $f12
  bnezl $at, .Ljp7F085568
   add.s $f12, $f18, $f2
  add.s $f12, $f18, $f2
.Ljp7F085588:
  swc1  $f12, ($s0)
.Ljp7F08558C:
  lui   $s0, %hi(D_80036478) # $s0, 0x8003
  addiu $s0, %lo(D_80036478) # addiu $s0, $s0, 0x64b8
  lui   $at, %hi(D_8005519C) # $at, 0x8005
  lwc1  $f0, %lo(D_8005519C)($at)
  lwc1  $f8, ($s0)
  lui   $at, %hi(D_800551A0) # $at, 0x8005
  lwc1  $f2, %lo(D_800551A0)($at)
  mul.s $f6, $f8, $f0
  addiu $a0, $t0, 0x48c
  lui   $a2, %hi(D_80036464) # $a2, 0x8003
  swc1  $f6, ($a3)
  lwc1  $f12, ($a3)
  c.le.s $f2, $f12
  nop   
  bc1fl .Ljp7F0855E4
   c.lt.s $f12, $f20
  sub.s $f4, $f12, $f2
  swc1  $f4, ($a3)
  lwc1  $f12, ($a3)
  div.s $f10, $f12, $f0
  swc1  $f10, ($s0)
  c.lt.s $f12, $f20
.Ljp7F0855E4:
  nop   
  bc1fl .Ljp7F085608
   lw    $a1, 0x488($t0)
  add.s $f8, $f12, $f2
  swc1  $f8, ($a3)
  lwc1  $f6, ($a3)
  div.s $f4, $f6, $f0
  swc1  $f4, ($s0)
  lw    $a1, 0x488($t0)
.Ljp7F085608:
  swc1  $f16, 0x354($sp)
  jal   sub_GAME_7F07CDA8
   lw    $a2, %lo(D_80036464)($a2)
  lui   $v1, %hi(D_80036484) # $v1, 0x8003
  lui   $at, %hi(D_800551A8) # $at, 0x8005
  lwc1  $f14, %lo(D_800551A8)($at)
  addiu $v1, %lo(D_80036484) # addiu $v1, $v1, 0x64c4
  bnez  $v0, .Ljp7F08564C
   lwc1  $f16, 0x354($sp)
  lui   $at, %hi(D_80036474) # $at, 0x8003
  swc1  $f16, %lo(D_80036474)($at)
  lwc1  $f10, %lo(D_80036474)($at)
  lui   $at, %hi(D_800551AC) # $at, 0x8005
  lwc1  $f8, %lo(D_800551AC)($at)
  swc1  $f16, ($v1)
  div.s $f6, $f10, $f8
  swc1  $f6, ($s0)
.Ljp7F08564C:
  lui   $v1, %hi(ptr_playerstank) # $v1, 0x8003
  lw    $v1, %lo(ptr_playerstank)($v1)
  lui   $v0, %hi(flt_CODE_bss_800799A8) # $v0, 0x8008
  addiu $v0, %lo(flt_CODE_bss_800799A8) # addiu $v0, $v0, -0x6618
  beqz  $v1, .Ljp7F08571C
   addiu $s0, $sp, 0x2b4
  lw    $t4, 4($v1)
  lwc1  $f4, ($v0)
  lwc1  $f10, 8($v0)
  swc1  $f20, 0x2f8($sp)
  lwc1  $f12, 0x358($sp)
  move  $a1, $s0
  sw    $t4, 0x300($sp)
  swc1  $f4, 0x2f4($sp)
  jal   sub_GAME_7F0585FC
   swc1  $f10, 0x2fc($sp)
  move  $a0, $s0
  jal   sub_GAME_7F0583D8
   addiu $a1, $sp, 0x2f4
  jal   sub_GAME_7F07C7B4
   nop   
  lui   $v0, %hi(flt_CODE_bss_800799A8) # $v0, 0x8008
  addiu $v0, %lo(flt_CODE_bss_800799A8) # addiu $v0, $v0, -0x6618
  lwc1  $f8, ($v0)
  lwc1  $f6, 0x2f4($sp)
  lwc1  $f10, 8($v0)
  lui   $at, %hi(D_800551BC) # $at, 0x8005
  sub.s $f4, $f8, $f6
  lwc1  $f8, 0x2fc($sp)
  swc1  $f20, 0x2f8($sp)
  move  $a1, $s0
  swc1  $f4, 0x2f4($sp)
  sub.s $f6, $f10, $f8
  lwc1  $f4, %lo(D_800551BC)($at)
  lui   $at, %hi(D_80036464) # $at, 0x8003
  lwc1  $f10, %lo(D_80036464)($at)
  swc1  $f6, 0x2fc($sp)
  jal   sub_GAME_7F0585FC
   sub.s $f12, $f4, $f10
  lw    $t3, 0x300($sp)
  move  $a1, $s0
  lw    $t5, 0x14($t3)
  jal   matrix_multiply_A1_by_F12
   lwc1  $f12, 0x14($t5)
  move  $a0, $s0
  jal   sub_GAME_7F0583D8
   addiu $a1, $sp, 0x2f4
  addiu $a0, $sp, 0x2f4
  jal   sub_GAME_7F07D960
   li    $a1, 1
  lui   $at, %hi(D_800551CC) # $at, 0x8005
  lwc1  $f14, %lo(D_800551CC)($at)
.Ljp7F08571C:
  lui   $a0, %hi(clock_timer) # $a0, 0x8005
  lw    $a0, %lo(clock_timer)($a0)
  lui   $at, %hi(D_80036474) # $at, 0x8003
  lwc1  $f12, %lo(D_80036474)($at)
  blezl $a0, .Ljp7F08579C
   lui   $at, 0x43b4
  blez  $a0, .Ljp7F085798
   move  $v0, $zero
  lui   $at, %hi(D_80036488) # $at, 0x8003
  lwc1  $f8, %lo(D_80036488)($at)
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  lwc1  $f6, %lo(global_timer_delta)($at)
  lui   $v1, %hi(D_8003647C) # $v1, 0x8003
  addiu $v1, %lo(D_8003647C) # addiu $v1, $v1, 0x64bc
  div.s $f0, $f8, $f6
  lwc1  $f16, ($v1)
  addiu $v0, $v0, 1
  slt   $at, $v0, $a0
  mul.s $f18, $f14, $f16
  beql  $at, $zero, .Ljp7F085794
   add.s $f16, $f18, $f0
  add.s $f16, $f18, $f0
.Ljp7F085774:
  addiu $v0, $v0, 1
  slt   $at, $v0, $a0
  swc1  $f16, ($v1)
  lwc1  $f16, ($v1)
  mul.s $f18, $f14, $f16
  bnezl $at, .Ljp7F085774
   add.s $f16, $f18, $f0
  add.s $f16, $f18, $f0
.Ljp7F085794:
  swc1  $f16, ($v1)
.Ljp7F085798:
  li    $at, 0x43B40000 # 360.000000
.Ljp7F08579C:
  mtc1  $at, $f14
  lui   $v1, %hi(D_8003647C) # $v1, 0x8003
  addiu $v1, %lo(D_8003647C) # addiu $v1, $v1, 0x64bc
  lui   $at, %hi(D_800551D0) # $at, 0x8005
  lwc1  $f4, %lo(D_800551D0)($at)
  lwc1  $f6, ($v1)
  lw    $t0, ($s1)
  li    $at, 0x40600000 # 3.500000
  mul.s $f2, $f6, $f4
  mtc1  $at, $f8
  lwc1  $f10, 0x14c($t0)
  lui   $at, %hi(D_800551D4) # $at, 0x8005
  lwc1  $f4, %lo(D_800551D4)($at)
  mul.s $f6, $f10, $f8
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f8
  lui   $at, %hi(D_80036464) # $at, 0x8003
  mul.s $f10, $f6, $f4
  lwc1  $f4, %lo(D_80036464)($at)
  li    $at, 0x40800000 # 4.000000
  mul.s $f6, $f10, $f8
  add.s $f10, $f4, $f12
  mtc1  $at, $f4
  lui   $at, %hi(D_800551D8) # $at, 0x8005
  add.s $f8, $f10, $f6
  mul.s $f10, $f2, $f4
  add.s $f6, $f8, $f10
  lwc1  $f8, %lo(D_800551D8)($at)
  mul.s $f4, $f6, $f14
  div.s $f10, $f4, $f8
  swc1  $f10, 0x148($t0)
  lw    $t0, ($s1)
  lwc1  $f0, 0x148($t0)
  c.lt.s $f0, $f20
  nop   
  bc1fl .Ljp7F085854
   c.le.s $f14, $f0
  add.s $f6, $f0, $f14
.Ljp7F085834:
  swc1  $f6, 0x148($t0)
  lw    $t0, ($s1)
  lwc1  $f0, 0x148($t0)
  c.lt.s $f0, $f20
  nop   
  bc1tl .Ljp7F085834
   add.s $f6, $f0, $f14
  c.le.s $f14, $f0
.Ljp7F085854:
  nop   
  bc1f  .Ljp7F085880
   nop   
  sub.s $f4, $f0, $f14
.Ljp7F085864:
  swc1  $f4, 0x148($t0)
  lw    $t0, ($s1)
  lwc1  $f0, 0x148($t0)
  c.le.s $f14, $f0
  nop   
  bc1tl .Ljp7F085864
   sub.s $f4, $f0, $f14
.Ljp7F085880:
  b     .Ljp7F08590C
   nop   
.Ljp7F085888:
  lwc1  $f8, 0x14c($t0)
  lwc1  $f10, ($t1)
  li    $at, 0x40600000 # 3.500000
  mtc1  $at, $f4
  mul.s $f6, $f8, $f10
  lwc1  $f10, 0x148($t0)
  lui   $at, 0x43b4
  mul.s $f8, $f6, $f4
  add.s $f0, $f10, $f8
  c.lt.s $f0, $f20
  nop   
  bc1fl .Ljp7F0858DC
   li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f14
  nop   
  add.s $f0, $f0, $f14
.Ljp7F0858C8:
  c.lt.s $f0, $f20
  nop   
  bc1tl .Ljp7F0858C8
   add.s $f0, $f0, $f14
  li    $at, 0x43B40000 # 360.000000
.Ljp7F0858DC:
  mtc1  $at, $f14
  nop   
  c.le.s $f14, $f0
  nop   
  bc1fl .Ljp7F08590C
   swc1  $f0, 0x148($t0)
  sub.s $f0, $f0, $f14
.Ljp7F0858F8:
  c.le.s $f14, $f0
  nop   
  bc1tl .Ljp7F0858F8
   sub.s $f0, $f0, $f14
  swc1  $f0, 0x148($t0)
.Ljp7F08590C:
  jal   sub_GAME_7F081790
   nop   
  jal   sub_GAME_7F0799F0
   swc1  $f20, 0x2ac($sp)
  bnez  $v0, .Ljp7F085930
   li    $at, 0xC2C80000 # -100.000000
  mtc1  $at, $f6
  b     .Ljp7F085958
   swc1  $f6, 0x2ac($sp)
.Ljp7F085930:
  jal   sub_GAME_7F0799F0
   nop   
  li    $at, 1
  bne   $v0, $at, .Ljp7F085950
   li    $at, 0xC2700000 # -60.000000
  mtc1  $at, $f4
  b     .Ljp7F085958
   swc1  $f4, 0x2ac($sp)
.Ljp7F085950:
  jal   sub_GAME_7F0799F0
   nop   
.Ljp7F085958:
  lw    $t0, ($s1)
  lwc1  $f10, 0x2ac($sp)
  li    $at, 0x3F000000 # 0.500000
  lwc1  $f0, 0xa0($t0)
  addiu $a0, $t0, 0xa0
  addiu $a2, $t0, 0xa4
  c.eq.s $f10, $f0
  nop   
  bc1tl .Ljp7F0859AC
   lwc1  $f6, 0x2ac($sp)
  mtc1  $at, $f0
  li    $at, 0x40A00000 # 5.000000
  mtc1  $at, $f8
  mfc1  $a1, $f10
  mfc1  $a3, $f0
  swc1  $f0, 0x10($sp)
  jal   sub_GAME_7F042F18
   swc1  $f8, 0x14($sp)
  lw    $t0, ($s1)
  lwc1  $f0, 0xa0($t0)
  lwc1  $f6, 0x2ac($sp)
.Ljp7F0859AC:
  lui   $s0, %hi(SFX_80036458) # $s0, 0x8003
  lui   $t6, %hi(in_tank_flag) # $t6, 0x8003
  c.eq.s $f6, $f0
  addiu $s0, %lo(SFX_80036458) # addiu $s0, $s0, 0x6498
  bc1f  .Ljp7F0859C8
   nop   
  swc1  $f20, 0xa4($t0)
.Ljp7F0859C8:
  lw    $t6, %lo(in_tank_flag)($t6)
  li    $at, 1
  bne   $t6, $at, .Ljp7F0861F8
   lui   $v0, %hi(dword_CODE_bss_800799B8) # $v0, 0x8008
  lw    $v0, %lo(dword_CODE_bss_800799B8)($v0)
  lui   $v1, %hi(ptr_playerstank) # $v1, 0x8003
  li    $at, 1
  bnez  $v0, .Ljp7F085CE4
   nop   
  lw    $v1, %lo(ptr_playerstank)($v1)
  lui   $at, %hi(D_800551DC) # $at, 0x8005
  addiu $a1, $sp, 0x268
  beqz  $v1, .Ljp7F085CB0
   nop   
  lwc1  $f4, %lo(D_800551DC)($at)
  lui   $at, %hi(D_80036464) # $at, 0x8003
  lwc1  $f10, %lo(D_80036464)($at)
  lw    $s0, 4($v1)
  jal   sub_GAME_7F0585FC
   sub.s $f12, $f4, $f10
  lw    $t8, 0x14($s0)
  addiu $a1, $sp, 0x268
  jal   matrix_multiply_A1_by_F12
   lwc1  $f12, 0x14($t8)
  lui   $v0, %hi(flt_CODE_bss_800799A8) # $v0, 0x8008
  addiu $v0, %lo(flt_CODE_bss_800799A8) # addiu $v0, $v0, -0x6618
  lwc1  $f8, ($v0)
  lwc1  $f6, 4($v0)
  lwc1  $f4, 8($v0)
  addiu $a0, $sp, 0x268
  addiu $a1, $sp, 0x25c
  swc1  $f8, 0x25c($sp)
  swc1  $f6, 0x260($sp)
  jal   sub_GAME_7F0583D8
   swc1  $f4, 0x264($sp)
  lwc1  $f10, 0x25c($sp)
  lwc1  $f8, 0x58($s0)
  lwc1  $f4, 0x260($sp)
  li    $at, 0xC1A00000 # -20.000000
  add.s $f6, $f10, $f8
  mtc1  $at, $f0
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f14
  swc1  $f6, 0x25c($sp)
  lwc1  $f10, 0x5c($s0)
  lwc1  $f6, 0x264($sp)
  lui   $at, %hi(D_80036464) # $at, 0x8003
  add.s $f8, $f4, $f10
  lw    $t7, ($s1)
  swc1  $f8, 0x260($sp)
  lwc1  $f4, 0x60($s0)
  lwc1  $f8, %lo(D_80036464)($at)
  lui   $at, %hi(D_80036474) # $at, 0x8003
  add.s $f10, $f6, $f4
  lwc1  $f6, %lo(D_80036474)($at)
  lui   $at, %hi(D_800551E0) # $at, 0x8005
  add.s $f4, $f8, $f6
  swc1  $f10, 0x264($sp)
  lwc1  $f2, 0x158($t7)
  lwc1  $f8, %lo(D_800551E0)($at)
  mul.s $f10, $f4, $f14
  c.lt.s $f2, $f0
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f18
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  bc1f  .Ljp7F085AD8
   div.s $f16, $f10, $f8
  mov.s $f2, $f0
.Ljp7F085AD8:
  lwc1  $f6, %lo(global_timer_delta)($at)
  li    $at, 0x42340000 # 45.000000
  mtc1  $at, $f4
  lui   $s0, %hi(flt_CODE_bss_800799BC) # $s0, 0x8008
  addiu $s0, %lo(flt_CODE_bss_800799BC) # addiu $s0, $s0, -0x6604
  div.s $f10, $f6, $f4
  lwc1  $f8, ($s0)
  lui   $at, %hi(D_800551E4) # $at, 0x8005
  add.s $f6, $f8, $f10
  swc1  $f6, ($s0)
  lwc1  $f0, ($s0)
  c.le.s $f18, $f0
  nop   
  bc1f  .Ljp7F085B1C
   nop   
  swc1  $f18, ($s0)
  lwc1  $f0, ($s0)
.Ljp7F085B1C:
  lwc1  $f4, %lo(D_800551E4)($at)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f10
  mul.s $f8, $f0, $f4
  swc1  $f2, 0x254($sp)
  swc1  $f16, 0x258($sp)
  mul.s $f12, $f8, $f10
  jal   cosf
   nop   
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f14
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f8
  add.s $f4, $f0, $f6
  lui   $v0, %hi(flt_CODE_bss_800799C0) # $v0, 0x8008
  addiu $v0, %lo(flt_CODE_bss_800799C0) # addiu $v0, $v0, -0x6600
  li    $at, 0x3F800000 # 1.000000
  mul.s $f10, $f4, $f8
  mtc1  $at, $f6
  lwc1  $f8, 0x254($sp)
  lui   $at, %hi(flt_CODE_bss_800799C8) # $at, 0x8008
  lw    $t2, ($s1)
  lwc1  $f16, 0x258($sp)
  lui   $v1, %hi(flt_CODE_bss_800799D0) # $v1, 0x8008
  swc1  $f10, ($v0)
  lwc1  $f2, ($v0)
  addiu $v1, %lo(flt_CODE_bss_800799D0) # addiu $v1, $v1, -0x65f0
  sub.s $f4, $f6, $f2
  lwc1  $f6, %lo(flt_CODE_bss_800799C8)($at)
  lui   $at, %hi(flt_CODE_bss_800799C4) # $at, 0x8008
  mul.s $f10, $f4, $f8
  nop   
  mul.s $f4, $f2, $f6
  add.s $f8, $f4, $f10
  swc1  $f8, 0x158($t2)
  lwc1  $f18, %lo(flt_CODE_bss_800799C4)($at)
  li    $at, 0x43340000 # 180.000000
  mtc1  $at, $f6
  sub.s $f12, $f16, $f18
  li    $at, 0xC3340000 # -180.000000
  mtc1  $at, $f4
  li    $at, 0x3F800000 # 1.000000
  c.lt.s $f6, $f12
  mtc1  $at, $f8
  li    $at, 0x3F800000 # 1.000000
  bc1f  .Ljp7F085BE4
   nop   
  sub.s $f16, $f16, $f14
.Ljp7F085BE4:
  c.lt.s $f12, $f4
  nop   
  bc1fl .Ljp7F085BFC
   lwc1  $f2, ($v0)
  add.s $f16, $f16, $f14
  lwc1  $f2, ($v0)
.Ljp7F085BFC:
  lw    $t9, ($s1)
  sub.s $f6, $f8, $f2
  mul.s $f10, $f2, $f18
  nop   
  mul.s $f4, $f6, $f16
  add.s $f8, $f10, $f4
  mtc1  $at, $f4
  swc1  $f8, 0x148($t9)
  lw    $t0, ($s1)
  lwc1  $f0, 0x148($t0)
  c.le.s $f14, $f0
  nop   
  bc1f  .Ljp7F085C44
   nop   
  sub.s $f6, $f0, $f14
  swc1  $f6, 0x148($t0)
  lw    $t0, ($s1)
  lwc1  $f0, 0x148($t0)
.Ljp7F085C44:
  c.lt.s $f0, $f20
  nop   
  bc1fl .Ljp7F085C64
   lwc1  $f2, ($v0)
  add.s $f10, $f0, $f14
  swc1  $f10, 0x148($t0)
  lw    $t0, ($s1)
  lwc1  $f2, ($v0)
.Ljp7F085C64:
  lwc1  $f8, ($v1)
  lwc1  $f10, 0x25c($sp)
  sub.s $f0, $f4, $f2
  mul.s $f6, $f2, $f8
  nop   
  mul.s $f4, $f0, $f10
  lwc1  $f10, 0x48c($t0)
  swc1  $f20, 0x3b0($sp)
  add.s $f8, $f6, $f4
  lwc1  $f4, 8($v1)
  sub.s $f6, $f8, $f10
  mul.s $f8, $f2, $f4
  lwc1  $f10, 0x264($sp)
  swc1  $f6, 0x3ac($sp)
  mul.s $f6, $f0, $f10
  lwc1  $f10, 0x494($t0)
  add.s $f4, $f8, $f6
  sub.s $f8, $f4, $f10
  swc1  $f8, 0x3b4($sp)
.Ljp7F085CB0:
  lui   $s0, %hi(flt_CODE_bss_800799BC) # $s0, 0x8008
  addiu $s0, %lo(flt_CODE_bss_800799BC) # addiu $s0, $s0, -0x6604
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  lwc1  $f6, ($s0)
  lw    $t0, ($s1)
  lui   $at, %hi(dword_CODE_bss_800799B8)
  c.le.s $f4, $f6
  li    $t4, 1
  bc1fl .Ljp7F086094
   lui   $at, %hi(0x3F3F99F8) # $at, 0x3f40
  b     .Ljp7F086090
   sw    $t4, %lo(dword_CODE_bss_800799B8)($at)
.Ljp7F085CE4:
  bne   $v0, $at, .Ljp7F085D50
   lui   $s0, %hi(SFX_80036458) # $s0, 0x8003
  li    $t3, 2
  lui   $at, %hi(dword_CODE_bss_800799B8) # $at, 0x8008
  addiu $s0, %lo(SFX_80036458) # addiu $s0, $s0, 0x6498
  sw    $t3, %lo(dword_CODE_bss_800799B8)($at)
  lw    $t5, ($s0)
  bnezl $t5, .Ljp7F085D2C
   lw    $a0, ($s0)
  jal   get_controls_locked_flag
   nop   
  bnez  $v0, .Ljp7F085D28
   lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 66
  jal   play_sfx_a1
   move  $a2, $s0
.Ljp7F085D28:
  lw    $a0, ($s0)
.Ljp7F085D2C:
  li    $a1, 8
  jal   sfx_c_70009184
   li    $a2, 25000
  lui   $v0, %hi(dword_CODE_bss_800799B4) # $v0, 0x8008
  addiu $v0, %lo(dword_CODE_bss_800799B4) # addiu $v0, $v0, -0x660c
  li    $t6, 25000
  sw    $t6, ($v0)
  b     .Ljp7F086090
   lw    $t0, ($s1)
.Ljp7F085D50:
  lw    $t0, ($s1)
  li    $at, 0x41700000 # 15.000000
  mtc1  $at, $f8
  lwc1  $f10, 0x174($t0)
  lui   $at, %hi(D_800551E8) # $at, 0x8005
  lwc1  $f4, %lo(D_800551E8)($at)
  div.s $f0, $f10, $f8
  lwc1  $f6, 0x14c($t0)
  div.s $f2, $f6, $f4
  c.lt.s $f0, $f20
  nop   
  bc1fl .Ljp7F085D8C
   c.lt.s $f2, $f20
  neg.s $f0, $f0
  c.lt.s $f2, $f20
.Ljp7F085D8C:
  nop   
  bc1fl .Ljp7F085DA0
   c.lt.s $f0, $f2
  neg.s $f2, $f2
  c.lt.s $f0, $f2
.Ljp7F085DA0:
  mov.s $f12, $f0
  bc1fl .Ljp7F085DB4
   c.lt.s $f20, $f12
  mov.s $f12, $f2
  c.lt.s $f20, $f12
.Ljp7F085DB4:
  nop   
  bc1f  .Ljp7F085EC8
   li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  lui   $s0, %hi(SFX_80036458) # $s0, 0x8003
  addiu $s0, %lo(SFX_80036458) # addiu $s0, $s0, 0x6498
  c.lt.s $f10, $f12
  li    $at, 0x3F800000 # 1.000000
  bc1fl .Ljp7F085DE8
   lw    $t8, 4($s0)
  mtc1  $at, $f12
  nop   
  lw    $t8, 4($s0)
.Ljp7F085DE8:
  bnezl $t8, .Ljp7F085E24
   lw    $a0, 4($s0)
  jal   get_controls_locked_flag
   swc1  $f12, 0x244($sp)
  bnez  $v0, .Ljp7F085E20
   lwc1  $f12, 0x244($sp)
  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  lui   $a2, %hi(SFX_8003645C) # $a2, 0x8003
  addiu $a2, %lo(SFX_8003645C) # addiu $a2, $a2, 0x649c
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 62
  jal   play_sfx_a1
   swc1  $f12, 0x244($sp)
  lwc1  $f12, 0x244($sp)
.Ljp7F085E20:
  lw    $a0, 4($s0)
.Ljp7F085E24:
  lui   $at, %hi(D_800551EC) # $at, 0x8005
  li    $a1, 8
  beql  $a0, $zero, .Ljp7F085F00
   lw    $t9, ($s0)
  lwc1  $f0, %lo(D_800551EC)($at)
  li    $a2, 32767
  lui   $at, 0x8005
  c.lt.s $f12, $f0
  nop   
  bc1f  .Ljp7F085E70
   nop   
  lui   $at, %hi(D_800551F0) # $at, 0x8005
  lwc1  $f8, %lo(D_800551F0)($at)
  mul.s $f6, $f12, $f8
  div.s $f4, $f6, $f0
  trunc.w.s $f10, $f4
  mfc1  $a2, $f10
  b     .Ljp7F085EB8
   nop   
.Ljp7F085E70:
  lwc1  $f8, %lo(D_800551F4)($at)
  lui   $at, %hi(D_800551F4) # $at, 0x8005
  c.lt.s $f12, $f8
  nop   
  bc1f  .Ljp7F085EB8
   nop   
  sub.s $f6, $f12, $f0
  lwc1  $f4, %lo(D_800551F8)($at)
  li    $at, 0x3F400000 # 0.750000
  mtc1  $at, $f8
  mul.s $f10, $f6, $f4
  lui   $at, %hi(D_800551FC) # $at, 0x8005
  lwc1  $f4, %lo(D_800551FC)($at)
  div.s $f6, $f10, $f8
  add.s $f10, $f6, $f4
  trunc.w.s $f8, $f10
  mfc1  $a2, $f8
  nop   
.Ljp7F085EB8:
  jal   sfx_c_70009184
   swc1  $f12, 0x244($sp)
  b     .Ljp7F085EFC
   lwc1  $f12, 0x244($sp)
.Ljp7F085EC8:
  lui   $s0, %hi(SFX_80036458) # $s0, 0x8003
  addiu $s0, %lo(SFX_80036458) # addiu $s0, $s0, 0x6498
  lw    $a0, 4($s0)
  beql  $a0, $zero, .Ljp7F085F00
   lw    $t9, ($s0)
  jal   sfxGetArg0Unk3F
   swc1  $f12, 0x244($sp)
  beqz  $v0, .Ljp7F085EFC
   lwc1  $f12, 0x244($sp)
  lw    $a0, 4($s0)
  jal   sfxDeactivate
   swc1  $f12, 0x244($sp)
  lwc1  $f12, 0x244($sp)
.Ljp7F085EFC:
  lw    $t9, ($s0)
.Ljp7F085F00:
  bnezl $t9, .Ljp7F085F38
   lw    $a0, ($s0)
  jal   get_controls_locked_flag
   swc1  $f12, 0x244($sp)
  bnez  $v0, .Ljp7F085F34
   lwc1  $f12, 0x244($sp)
  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 65
  move  $a2, $s0
  jal   play_sfx_a1
   swc1  $f12, 0x244($sp)
  lwc1  $f12, 0x244($sp)
.Ljp7F085F34:
  lw    $a0, ($s0)
.Ljp7F085F38:
  beqz  $a0, .Ljp7F085FA4
   lui   $v0, %hi(dword_CODE_bss_800799B4) # $v0, 0x8008
  addiu $v0, %lo(dword_CODE_bss_800799B4) # addiu $v0, $v0, -0x660c
  li    $t4, 32767
  sw    $t4, ($v0)
  lui   $at, %hi(D_80055200) # $at, 0x8005
  lwc1  $f6, %lo(D_80055200)($at)
  lui   $at, %hi(D_80055204) # $at, 0x8005
  li    $a1, 8
  c.lt.s $f12, $f6
  nop   
  bc1f  .Ljp7F085F9C
   nop   
  lwc1  $f4, %lo(D_80055204)($at)
  lui   $at, %hi(D_80055208) # $at, 0x8005
  lwc1  $f8, %lo(D_80055208)($at)
  mul.s $f10, $f12, $f4
  lui   $at, %hi(D_8005520C) # $at, 0x8005
  lwc1  $f4, %lo(D_8005520C)($at)
  div.s $f6, $f10, $f8
  add.s $f10, $f6, $f4
  trunc.w.s $f8, $f10
  mfc1  $t5, $f8
  nop   
  sw    $t5, ($v0)
.Ljp7F085F9C:
  jal   sfx_c_70009184
   lw    $a2, ($v0)
.Ljp7F085FA4:
  jal   get_item_in_hand
   move  $a0, $zero
  li    $at, 32
  bne   $v0, $at, .Ljp7F085FD0
   lui   $a0, %hi(clock_timer) # $a0, 0x8005
  lw    $t0, ($s1)
  lui   $at, %hi(D_80055210) # $at, 0x8005
  lwc1  $f6, %lo(D_80055210)($at)
  lwc1  $f2, 0x2a08($t0)
  b     .Ljp7F085FDC
   add.s $f2, $f2, $f6
.Ljp7F085FD0:
  lui   $at, %hi(D_8003646C) # $at, 0x8003
  lwc1  $f2, %lo(D_8003646C)($at)
  lw    $t0, ($s1)
.Ljp7F085FDC:
  lui   $at, %hi(D_80055214) # $at, 0x8005
  lwc1  $f0, %lo(D_80055214)($at)
  lui   $at, %hi(D_80055218) # $at, 0x8005
  c.lt.s $f0, $f2
  nop   
  bc1f  .Ljp7F085FFC
   nop   
  mov.s $f2, $f0
.Ljp7F085FFC:
  lwc1  $f0, %lo(D_80055218)($at)
  c.lt.s $f2, $f0
  nop   
  bc1f  .Ljp7F086014
   nop   
  mov.s $f2, $f0
.Ljp7F086014:
  lw    $a0, %lo(clock_timer)($a0)
  move  $v0, $zero
  blez  $a0, .Ljp7F086070
   lui   $at, %hi(D_8005521C) # $at, 0x8005
  lui   $v1, %hi(D_80036470) # $v1, 0x8003
  addiu $v1, %lo(D_80036470) # addiu $v1, $v1, 0x64b0
  lwc1  $f0, %lo(D_8005521C)($at)
  lwc1  $f16, ($v1)
  addiu $v0, $v0, 1
  slt   $at, $v0, $a0
  mul.s $f18, $f0, $f16
  beql  $at, $zero, .Ljp7F08606C
   add.s $f16, $f18, $f2
  add.s $f16, $f18, $f2
.Ljp7F08604C:
  addiu $v0, $v0, 1
  slt   $at, $v0, $a0
  swc1  $f16, ($v1)
  lwc1  $f16, ($v1)
  mul.s $f18, $f0, $f16
  bnezl $at, .Ljp7F08604C
   add.s $f16, $f18, $f2
  add.s $f16, $f18, $f2
.Ljp7F08606C:
  swc1  $f16, ($v1)
.Ljp7F086070:
  lui   $v1, %hi(D_80036470) # $v1, 0x8003
  addiu $v1, %lo(D_80036470) # addiu $v1, $v1, 0x64b0
  lui   $at, %hi(D_80055220) # $at, 0x8005
  lwc1  $f4, %lo(D_80055220)($at)
  lwc1  $f6, ($v1)
  lui   $at, %hi(D_8003646C) # $at, 0x8003
  mul.s $f10, $f6, $f4
  swc1  $f10, %lo(D_8003646C)($at)
.Ljp7F086090:
  li    $at, 0x3F400000 # 0.750000
.Ljp7F086094:
  mtc1  $at, $f0
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  lwc1  $f8, %lo(global_timer_delta)($at)
  lui   $at, %hi(D_80055224) # $at, 0x8005
  lwc1  $f4, %lo(D_80055224)($at)
  mul.s $f6, $f0, $f8
  lwc1  $f8, 0x19c($t0)
  mfc1  $a2, $f20
  mov.s $f12, $f20
  div.s $f10, $f6, $f4
  sub.s $f6, $f8, $f10
  swc1  $f6, 0x19c($t0)
  lw    $t0, ($s1)
  lwc1  $f4, 0x19c($t0)
  c.lt.s $f4, $f20
  nop   
  bc1f  .Ljp7F0860E0
   nop   
  swc1  $f20, 0x19c($t0)
.Ljp7F0860E0:
  jal   sub_GAME_7F080B34
   mov.s $f14, $f20
  lui   $at, %hi(D_80055228) # $at, 0x8005
  lwc1  $f8, %lo(D_80055228)($at)
  lui   $at, %hi(D_80036464) # $at, 0x8003
  lwc1  $f10, %lo(D_80036464)($at)
  jal   sinf
   sub.s $f12, $f8, $f10
  lw    $t6, ($s1)
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  lwc1  $f8, %lo(global_timer_delta)($at)
  lwc1  $f6, 0x174($t6)
  lui   $at, %hi(D_8005522C) # $at, 0x8005
  mul.s $f4, $f6, $f0
  lwc1  $f6, 0x3ac($sp)
  mul.s $f10, $f4, $f8
  lwc1  $f8, %lo(D_8005522C)($at)
  lui   $at, %hi(D_80036464) # $at, 0x8003
  add.s $f4, $f6, $f10
  lwc1  $f6, %lo(D_80036464)($at)
  swc1  $f4, 0x3ac($sp)
  jal   cosf
   sub.s $f12, $f8, $f6
  lw    $t8, ($s1)
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  lwc1  $f8, %lo(global_timer_delta)($at)
  lwc1  $f10, 0x174($t8)
  addiu $a0, $sp, 0x3ac
  li    $a1, 1
  mul.s $f4, $f10, $f0
  lwc1  $f10, 0x3b4($sp)
  mul.s $f6, $f4, $f8
  add.s $f4, $f10, $f6
  jal   sub_GAME_7F07D960
   swc1  $f4, 0x3b4($sp)
  lui   $t7, %hi(dword_CODE_bss_800799B8) # $t7, 0x8008
  lw    $t7, %lo(dword_CODE_bss_800799B8)($t7)
  li    $at, 2
  lui   $t2, %hi(clock_timer) # $t2, 0x8005
  bnel  $t7, $at, .Ljp7F086A60
   lw    $t0, ($s1)
  lw    $t2, %lo(clock_timer)($t2)
  blezl $t2, .Ljp7F086A60
   lw    $t0, ($s1)
  lw    $t0, ($s1)
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  lwc1  $f14, %lo(global_timer_delta)($at)
  lwc1  $f8, 0x48c($t0)
  lwc1  $f10, 0x408($t0)
  lwc1  $f4, 0x494($t0)
  sub.s $f6, $f8, $f10
  lwc1  $f8, 0x410($t0)
  sub.s $f10, $f4, $f8
  div.s $f0, $f6, $f14
  div.s $f2, $f10, $f14
  mul.s $f6, $f0, $f0
  nop   
  mul.s $f4, $f2, $f2
  jal   sqrtf
   add.s $f12, $f6, $f4
  lw    $t0, ($s1)
  mov.s $f2, $f0
  lwc1  $f8, 0x174($t0)
  c.lt.s $f8, $f20
  nop   
  bc1f  .Ljp7F0861F0
   nop   
  neg.s $f2, $f0
.Ljp7F0861F0:
  b     .Ljp7F086A5C
   swc1  $f2, 0x174($t0)
.Ljp7F0861F8:
  lw    $a0, ($s0)
  beql  $a0, $zero, .Ljp7F086268
   lw    $a0, 4($s0)
  jal   sfxGetArg0Unk3F
   nop   
  beqz  $v0, .Ljp7F086264
   li    $at, 0x447A0000 # 1000.000000
  mtc1  $at, $f10
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  lwc1  $f6, %lo(global_timer_delta)($at)
  lui   $v0, %hi(dword_CODE_bss_800799B4) # $v0, 0x8008
  addiu $v0, %lo(dword_CODE_bss_800799B4) # addiu $v0, $v0, -0x660c
  mul.s $f4, $f10, $f6
  lw    $t3, ($v0)
  li    $a1, 8
  trunc.w.s $f8, $f4
  mfc1  $t4, $f8
  nop   
  subu  $a2, $t3, $t4
  blez  $a2, .Ljp7F08625C
   sw    $a2, ($v0)
  jal   sfx_c_70009184
   lw    $a0, ($s0)
  b     .Ljp7F086268
   lw    $a0, 4($s0)
.Ljp7F08625C:
  jal   sfxDeactivate
   lw    $a0, ($s0)
.Ljp7F086264:
  lw    $a0, 4($s0)
.Ljp7F086268:
  beqz  $a0, .Ljp7F086288
   nop   
  jal   sfxGetArg0Unk3F
   nop   
  beqz  $v0, .Ljp7F086288
   nop   
  jal   sfxDeactivate
   lw    $a0, 4($s0)
.Ljp7F086288:
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  lwc1  $f14, %lo(global_timer_delta)($at)
  lui   $at, %hi(D_80036AF4) # $at, 0x8003
  lwc1  $f10, %lo(D_80036AF4)($at)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f6
  lw    $t0, ($s1)
  li    $at, 0x42C80000 # 100.000000
  mul.s $f4, $f10, $f6
  lwc1  $f8, 0x16c($t0)
  swc1  $f8, 0x4c($sp)
  lwc1  $f10, 0x4c($sp)
  mul.s $f12, $f4, $f14
  nop   
  mul.s $f6, $f10, $f12
  swc1  $f6, 0x3a0($sp)
  lwc1  $f0, 0x1274($t0)
  lwc1  $f4, 0x4a0($t0)
  lwc1  $f6, 0x1278($t0)
  neg.s $f8, $f0
  lwc1  $f10, 0x498($t0)
  mul.s $f16, $f4, $f8
  sub.s $f4, $f16, $f6
  mul.s $f18, $f10, $f0
  swc1  $f4, 0x220($sp)
  lwc1  $f8, 0x127c($t0)
  lwc1  $f6, 0x220($sp)
  sub.s $f10, $f18, $f8
  mul.s $f4, $f6, $f6
  swc1  $f10, 0x21c($sp)
  lwc1  $f8, 0x21c($sp)
  mul.s $f10, $f8, $f8
  add.s $f2, $f4, $f10
  mtc1  $at, $f4
  nop   
  c.le.s $f4, $f2
  swc1  $f2, 0x218($sp)
  bc1f  .Ljp7F086340
   nop   
  lui   $at, %hi(D_80055230) # $at, 0x8005
  lwc1  $f0, %lo(D_80055230)($at)
  mul.s $f10, $f6, $f0
  nop   
  mul.s $f4, $f8, $f0
  swc1  $f10, 0x220($sp)
  swc1  $f4, 0x21c($sp)
.Ljp7F086340:
  lui   $at, %hi(D_80055234) # $at, 0x8005
  lwc1  $f16, %lo(D_80055234)($at)
  lwc1  $f6, 0x4c($sp)
  lwc1  $f10, 0x14c($t0)
  lwc1  $f2, 0x174($t0)
  mul.s $f0, $f6, $f16
  c.lt.s $f0, $f20
  mul.s $f12, $f10, $f16
  bc1fl .Ljp7F086370
   c.lt.s $f2, $f20
  neg.s $f0, $f0
  c.lt.s $f2, $f20
.Ljp7F086370:
  lui   $at, %hi(D_80055238) # $at, 0x8005
  bc1fl .Ljp7F086384
   c.lt.s $f12, $f20
  neg.s $f2, $f2
  c.lt.s $f12, $f20
.Ljp7F086384:
  nop   
  bc1fl .Ljp7F086398
   c.lt.s $f2, $f0
  neg.s $f12, $f12
  c.lt.s $f2, $f0
.Ljp7F086398:
  swc1  $f2, 0x398($sp)
  bc1fl .Ljp7F0863AC
   lwc1  $f8, 0x398($sp)
  swc1  $f0, 0x398($sp)
  lwc1  $f8, 0x398($sp)
.Ljp7F0863AC:
  c.lt.s $f8, $f12
  nop   
  bc1fl .Ljp7F0863C4
   lwc1  $f4, 0x218($sp)
  swc1  $f12, 0x398($sp)
  lwc1  $f4, 0x218($sp)
.Ljp7F0863C4:
  lwc1  $f6, %lo(D_80055238)($at)
  li    $at, 0x3F400000 # 0.750000
  mtc1  $at, $f0
  c.le.s $f6, $f4
  nop   
  bc1fl .Ljp7F0863FC
   lwc1  $f8, 0x398($sp)
  lwc1  $f10, 0x398($sp)
  c.lt.s $f10, $f16
  nop   
  bc1fl .Ljp7F0863FC
   lwc1  $f8, 0x398($sp)
  swc1  $f16, 0x398($sp)
  lwc1  $f8, 0x398($sp)
.Ljp7F0863FC:
  c.le.s $f0, $f8
  nop   
  bc1fl .Ljp7F086434
   lwc1  $f10, 0x398($sp)
  sub.s $f4, $f8, $f0
  li    $at, 0x44610000 # 900.000000
  mtc1  $at, $f10
  mul.s $f6, $f4, $f14
  lwc1  $f4, 0x19c($t0)
  div.s $f8, $f6, $f10
  add.s $f6, $f4, $f8
  b     .Ljp7F086454
   swc1  $f6, 0x19c($t0)
  lwc1  $f10, 0x398($sp)
.Ljp7F086434:
  lui   $at, %hi(D_8005523C) # $at, 0x8005
  lwc1  $f6, %lo(D_8005523C)($at)
  sub.s $f4, $f0, $f10
  mul.s $f8, $f4, $f14
  lwc1  $f4, 0x19c($t0)
  div.s $f10, $f8, $f6
  sub.s $f8, $f4, $f10
  swc1  $f8, 0x19c($t0)
.Ljp7F086454:
  lw    $t0, ($s1)
  lwc1  $f0, 0x19c($t0)
  c.lt.s $f0, $f20
  nop   
  bc1fl .Ljp7F08647C
   lui   $at, 0x3f80
  swc1  $f20, 0x19c($t0)
  b     .Ljp7F0864A4
   lw    $t0, ($s1)
  li    $at, 0x3F800000 # 1.000000
.Ljp7F08647C:
  mtc1  $at, $f6
  li    $at, 0x3F800000 # 1.000000
  c.lt.s $f6, $f0
  nop   
  bc1fl .Ljp7F0864A8
   lwc1  $f12, 0x398($sp)
  mtc1  $at, $f4
  nop   
  swc1  $f4, 0x19c($t0)
  lw    $t0, ($s1)
.Ljp7F0864A4:
  lwc1  $f12, 0x398($sp)
.Ljp7F0864A8:
  lwc1  $f14, 0x174($t0)
  jal   sub_GAME_7F080B34
   lw    $a2, 0x3a0($sp)
  lw    $t0, ($s1)
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  lwc1  $f14, %lo(global_timer_delta)($at)
  lwc1  $f2, 0x504($t0)
  lwc1  $f10, 0x498($t0)
  lwc1  $f0, 0x4fc($t0)
  lwc1  $f6, 0x4a0($t0)
  mul.s $f8, $f2, $f10
  nop   
  mul.s $f4, $f0, $f6
  sub.s $f10, $f8, $f4
  lwc1  $f8, 0x3ac($sp)
  mul.s $f6, $f10, $f14
  add.s $f4, $f8, $f6
  swc1  $f4, 0x3ac($sp)
  lwc1  $f10, 0x4a0($t0)
  lwc1  $f6, 0x498($t0)
  mul.s $f8, $f2, $f10
  nop   
  mul.s $f10, $f0, $f6
  add.s $f6, $f8, $f10
  lwc1  $f10, 0x3b4($sp)
  mul.s $f8, $f6, $f14
  add.s $f6, $f10, $f8
  lwc1  $f10, 0x220($sp)
  add.s $f8, $f4, $f10
  lwc1  $f4, 0x21c($sp)
  swc1  $f6, 0x3b4($sp)
  add.s $f10, $f6, $f4
  swc1  $f8, 0x3ac($sp)
  swc1  $f10, 0x3b4($sp)
  lwc1  $f8, 0x48c($t0)
  swc1  $f8, 0x208($sp)
  lwc1  $f6, 0x494($t0)
  swc1  $f6, 0x204($sp)
  lw    $t6, 0x488($t0)
  jal   get_debug_fast_bond_flag
   sw    $t6, 0x200($sp)
  beql  $v0, $zero, .Ljp7F0865D4
   lw    $t8, ($s1)
  lw    $t0, ($s1)
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f0
  lwc1  $f4, 0x498($t0)
  lwc1  $f10, 0x174($t0)
  lwc1  $f6, 0x4a0($t0)
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  mul.s $f8, $f4, $f10
  lwc1  $f4, 0x16c($t0)
  lwc1  $f14, %lo(global_timer_delta)($at)
  mul.s $f10, $f6, $f4
  sub.s $f6, $f8, $f10
  lwc1  $f10, 0x3ac($sp)
  mul.s $f4, $f6, $f14
  nop   
  mul.s $f8, $f4, $f0
  add.s $f6, $f10, $f8
  swc1  $f6, 0x3ac($sp)
  lwc1  $f10, 0x174($t0)
  lwc1  $f4, 0x4a0($t0)
  lwc1  $f6, 0x498($t0)
  mul.s $f8, $f4, $f10
  lwc1  $f4, 0x16c($t0)
  mul.s $f10, $f6, $f4
  add.s $f6, $f8, $f10
  lwc1  $f10, 0x3b4($sp)
  mul.s $f4, $f6, $f14
  nop   
  mul.s $f8, $f4, $f0
  add.s $f6, $f10, $f8
  swc1  $f6, 0x3b4($sp)
  lw    $t8, ($s1)
.Ljp7F0865D4:
  addiu $a0, $sp, 0x3ac
  move  $a1, $zero
  lwc1  $f4, 0x1274($t8)
  c.eq.s $f20, $f4
  nop   
  bc1f  .Ljp7F0865F4
   nop   
  li    $a1, 1
.Ljp7F0865F4:
  jal   sub_GAME_7F07D960
   nop   
  lw    $t7, ($s1)
  lui   $at, %hi(D_80055240) # $at, 0x8005
  lwc1  $f8, %lo(D_80055240)($at)
  lwc1  $f10, 0x4b0($t7)
  addiu $s0, $sp, 0x1b4
  sw    $s0, 0x10($sp)
  mul.s $f6, $f10, $f8
  addiu $a0, $sp, 0x200
  lw    $a1, 0x208($sp)
  lw    $a2, 0x204($sp)
  mfc1  $a3, $f6
  jal   sub_GAME_7F0B2314
   nop   
  jal   sub_GAME_7F0B23A4
   move  $a0, $s0
  beqz  $v0, .Ljp7F086644
   li    $t2, 1
  sw    $t2, 0x394($sp)
.Ljp7F086644:
  lw    $t0, ($s1)
  lui   $at, %hi(D_80055244) # $at, 0x8005
  lwc1  $f10, %lo(D_80055244)($at)
  lwc1  $f4, 0x4b0($t0)
  lw    $a1, 0x48c($t0)
  lw    $a2, 0x494($t0)
  mul.s $f8, $f4, $f10
  sw    $s0, 0x10($sp)
  addiu $a0, $t0, 0x488
  mfc1  $a3, $f8
  jal   sub_GAME_7F0B2314
   nop   
  jal   sub_GAME_7F0B23A4
   move  $a0, $s0
  beqz  $v0, .Ljp7F086688
   li    $t9, 1
  sw    $t9, 0x394($sp)
.Ljp7F086688:
  lw    $t0, ($s1)
  lw    $a1, 0x48c($t0)
  lw    $a2, 0x494($t0)
  lw    $a3, 0x4b0($t0)
  sw    $s0, 0x10($sp)
  jal   sub_GAME_7F0B2314
   addiu $a0, $t0, 0x488
  jal   sub_GAME_7F0B23A4
   move  $a0, $s0
  bnez  $v0, .Ljp7F0866E4
   nop   
  lw    $t3, ($s1)
  lui   $at, %hi(D_80055248) # $at, 0x8005
  lwc1  $f4, %lo(D_80055248)($at)
  lwc1  $f6, 0x4b0($t3)
  sw    $s0, 0x10($sp)
  addiu $a0, $sp, 0x200
  mul.s $f10, $f6, $f4
  lw    $a1, 0x208($sp)
  lw    $a2, 0x204($sp)
  mfc1  $a3, $f10
  jal   sub_GAME_7F0B2314
   nop   
.Ljp7F0866E4:
  jal   sub_GAME_7F0B23A4
   move  $a0, $s0
  beqz  $v0, .Ljp7F0869D0
   li    $t4, 1
  sw    $t4, 0x394($sp)
  addiu $a0, $sp, 0x174
  addiu $a1, $sp, 0x170
  jal   sub_GAME_7F0B2420
   addiu $a2, $sp, 0x184
  lw    $t5, ($s1)
  lwc1  $f8, 0x1a0($sp)
  lwc1  $f6, 0x74($t5)
  c.le.s $f6, $f8
  lwc1  $f8, 0x198($sp)
  lwc1  $f6, 0x18c($sp)
  bc1fl .Ljp7F0869D4
   lw    $t0, ($s1)
  lwc1  $f4, 0x184($sp)
  lwc1  $f10, 0x190($sp)
  sub.s $f14, $f8, $f6
  sub.s $f2, $f4, $f10
  mul.s $f4, $f14, $f14
  swc1  $f14, 0x16c($sp)
  mul.s $f10, $f2, $f2
  swc1  $f2, 0x168($sp)
  jal   sqrtf
   add.s $f12, $f4, $f10
  lwc1  $f2, 0x168($sp)
  lwc1  $f14, 0x16c($sp)
  lwc1  $f8, 0x204($sp)
  div.s $f2, $f2, $f0
  lwc1  $f6, 0x18c($sp)
  swc1  $f8, 0x30($sp)
  sub.s $f4, $f8, $f6
  lwc1  $f8, 0x184($sp)
  swc1  $f6, 0x34($sp)
  div.s $f14, $f14, $f0
  mul.s $f10, $f4, $f2
  lwc1  $f4, 0x208($sp)
  sub.s $f6, $f4, $f8
  mul.s $f6, $f6, $f14
  add.s $f12, $f10, $f6
  lwc1  $f6, 0x30($sp)
  lwc1  $f10, 0x3b4($sp)
  swc1  $f12, 0x50($sp)
  add.s $f6, $f6, $f10
  lwc1  $f10, 0x34($sp)
  sub.s $f6, $f6, $f10
  mul.s $f10, $f6, $f2
  lwc1  $f6, 0x3ac($sp)
  add.s $f4, $f4, $f6
  sub.s $f6, $f4, $f8
  mul.s $f4, $f6, $f14
  add.s $f18, $f10, $f4
  lwc1  $f4, 0x3b4($sp)
  mul.s $f8, $f12, $f18
  mov.s $f16, $f18
  c.le.s $f8, $f20
  mul.s $f8, $f4, $f4
  bc1fl .Ljp7F0867E4
   c.lt.s $f18, $f20
  b     .Ljp7F086858
   mov.s $f14, $f20
  c.lt.s $f18, $f20
.Ljp7F0867E4:
  nop   
  bc1fl .Ljp7F086800
   c.le.s $f12, $f16
  lwc1  $f12, 0x50($sp)
  neg.s $f16, $f18
  neg.s $f12, $f12
  c.le.s $f12, $f16
.Ljp7F086800:
  nop   
  bc1fl .Ljp7F086818
   lw    $t6, ($s1)
  b     .Ljp7F086858
   mov.s $f14, $f20
  lw    $t6, ($s1)
.Ljp7F086818:
  lwc1  $f0, 0x4b0($t6)
  c.lt.s $f0, $f16
  nop   
  bc1fl .Ljp7F086838
   c.lt.s $f12, $f0
  b     .Ljp7F086858
   mov.s $f14, $f20
  c.lt.s $f12, $f0
.Ljp7F086838:
  nop   
  bc1fl .Ljp7F086850
   sub.s $f6, $f12, $f0
  b     .Ljp7F086858
   mov.s $f14, $f20
  sub.s $f6, $f12, $f0
.Ljp7F086850:
  sub.s $f10, $f12, $f16
  div.s $f14, $f6, $f10
.Ljp7F086858:
  lwc1  $f6, 0x3ac($sp)
  swc1  $f14, 0x180($sp)
  mul.s $f10, $f6, $f6
  jal   sqrtf
   add.s $f12, $f8, $f10
  c.lt.s $f20, $f0
  lwc1  $f14, 0x180($sp)
  li    $at, 0x3F800000 # 1.000000
  bc1fl .Ljp7F0868E8
   lwc1  $f6, 0x19c($sp)
  mtc1  $at, $f4
  li    $at, 0x3E800000 # 0.250000
  mtc1  $at, $f8
  sub.s $f6, $f4, $f14
  lw    $t8, ($s1)
  lwc1  $f4, 0x1a0($sp)
  li    $at, 0x3E800000 # 0.250000
  mul.s $f2, $f6, $f0
  nop   
  mul.s $f12, $f2, $f8
  swc1  $f12, 0x390($sp)
  lwc1  $f18, 0x74($t8)
  add.s $f10, $f18, $f12
  c.le.s $f4, $f10
  nop   
  bc1f  .Ljp7F0868E4
   nop   
  sub.s $f6, $f4, $f18
  mtc1  $at, $f8
  nop   
  div.s $f10, $f6, $f8
  swc1  $f6, 0x390($sp)
  sub.s $f16, $f2, $f10
  div.s $f4, $f16, $f0
  add.s $f14, $f14, $f4
.Ljp7F0868E4:
  lwc1  $f6, 0x19c($sp)
.Ljp7F0868E8:
  lwc1  $f8, 0x184($sp)
  lwc1  $f10, 0x1a4($sp)
  lwc1  $f4, 0x18c($sp)
  sub.s $f12, $f6, $f8
  lwc1  $f6, 0x1a8($sp)
  lw    $t0, ($s1)
  sub.s $f16, $f10, $f4
  lwc1  $f10, 0x1b0($sp)
  sub.s $f18, $f6, $f8
  sub.s $f6, $f10, $f4
  mul.s $f8, $f18, $f18
  nop   
  mul.s $f10, $f6, $f6
  swc1  $f6, 0x48($sp)
  add.s $f4, $f8, $f10
  mul.s $f8, $f12, $f12
  nop   
  mul.s $f10, $f16, $f16
  add.s $f8, $f8, $f10
  lwc1  $f10, 0x1a0($sp)
  c.lt.s $f4, $f8
  lwc1  $f4, 0x188($sp)
  bc1f  .Ljp7F086950
   sub.s $f8, $f10, $f4
  mov.s $f12, $f18
  mov.s $f16, $f6
.Ljp7F086950:
  lwc1  $f6, 0x390($sp)
  lwc1  $f4, 0x3ac($sp)
  addiu $a0, $sp, 0x3ac
  div.s $f0, $f6, $f8
  move  $a1, $zero
  mul.s $f10, $f0, $f12
  nop   
  mul.s $f6, $f4, $f14
  add.s $f8, $f10, $f6
  mul.s $f4, $f0, $f16
  lwc1  $f10, 0x3b4($sp)
  swc1  $f8, 0x3ac($sp)
  mul.s $f6, $f10, $f14
  lwc1  $f10, 0x208($sp)
  add.s $f8, $f4, $f6
  swc1  $f8, 0x3b4($sp)
  swc1  $f10, 0x48c($t0)
  lw    $t7, ($s1)
  lwc1  $f4, 0x204($sp)
  swc1  $f4, 0x494($t7)
  lw    $t9, ($s1)
  lw    $t2, 0x200($sp)
  sw    $t2, 0x488($t9)
  lw    $t3, ($s1)
  lwc1  $f6, 0x1274($t3)
  c.eq.s $f20, $f6
  nop   
  bc1f  .Ljp7F0869C8
   nop   
  li    $a1, 1
.Ljp7F0869C8:
  jal   sub_GAME_7F07D960
   nop   
.Ljp7F0869D0:
  lw    $t0, ($s1)
.Ljp7F0869D4:
  lwc1  $f10, 0x208($sp)
  lwc1  $f6, 0x204($sp)
  lwc1  $f8, 0x48c($t0)
  lwc1  $f4, 0x494($t0)
  sub.s $f2, $f8, $f10
  lwc1  $f8, 0x3b4($sp)
  sub.s $f14, $f4, $f6
  mul.s $f10, $f8, $f8
  lwc1  $f4, 0x3ac($sp)
  mul.s $f6, $f4, $f4
  add.s $f0, $f10, $f6
  c.eq.s $f0, $f20
  mov.s $f12, $f0
  bc1t  .Ljp7F086A24
   nop   
  mul.s $f8, $f2, $f2
  nop   
  mul.s $f4, $f14, $f14
  add.s $f10, $f8, $f4
  div.s $f12, $f10, $f0
.Ljp7F086A24:
  jal   sqrtf
   nop   
  lwc1  $f8, 0x220($sp)
  lw    $t0, ($s1)
  mul.s $f4, $f0, $f8
  lwc1  $f6, 0x1278($t0)
  add.s $f10, $f6, $f4
  swc1  $f10, 0x1278($t0)
  lwc1  $f6, 0x21c($sp)
  lw    $t0, ($s1)
  mul.s $f4, $f0, $f6
  lwc1  $f8, 0x127c($t0)
  add.s $f10, $f8, $f4
  swc1  $f10, 0x127c($t0)
.Ljp7F086A5C:
  lw    $t0, ($s1)
.Ljp7F086A60:
  lui    $at, %hi(D_8005524C)
  lwc1  $f8, %lo(D_8005524C)($at)
  lwc1  $f6, 0x160($t0)
  li    $at, 0x40A00000 # 5.000000
  lwc1  $f10, 0xa4($t0)
  div.s $f4, $f6, $f8
  mtc1  $at, $f6
  lwc1  $f20, 0x14c($t0)
  div.s $f8, $f10, $f6
  add.s $f2, $f4, $f8
  jal   sub_GAME_7F08EAF8
   swc1  $f2, 0x144($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f14
  lwc1  $f2, 0x144($sp)
  mfc1  $a3, $f20
  mov.s $f12, $f0
  c.lt.s $f14, $f2
  li    $at, 0xBF800000 # -1.000000
  bc1fl .Ljp7F086AC0
   mtc1  $at, $f14
  b     .Ljp7F086AD8
   mov.s $f2, $f14
  mtc1  $at, $f14
.Ljp7F086AC0:
  nop   
  c.lt.s $f2, $f14
  nop   
  bc1fl .Ljp7F086ADC
   lw    $t4, ($s1)
  mov.s $f2, $f14
.Ljp7F086AD8:
  lw    $t4, ($s1)
.Ljp7F086ADC:
  li    $at, 1
  mfc1  $a2, $f2
  lw    $t5, 0x4e8($t4)
  bne   $t5, $at, .Ljp7F086AFC
   lui   $at, %hi(D_80055250) # $at, 0x8005
  lwc1  $f10, %lo(D_80055250)($at)
  mul.s $f12, $f0, $f10
  nop   
.Ljp7F086AFC:
  jal   sub_GAME_7F05E0E4
   lwc1  $f14, 0x398($sp)
  lw    $t6, ($s1)
  lui   $at, %hi(D_80055254) # $at, 0x8005
  lwc1  $f4, %lo(D_80055254)($at)
  lwc1  $f6, 0x15c($t6)
  mul.s $f12, $f6, $f4
  jal   sub_GAME_7F05E5F0
   nop   
  lui   $v1, %hi(ptr_playerstank) # $v1, 0x8003
  lw    $v1, %lo(ptr_playerstank)($v1)
  lui   $t8, %hi(in_tank_flag) # $t8, 0x8003
  beql  $v1, $zero, .Ljp7F087004
   lw    $a0, 0x394($sp)
  lw    $t8, %lo(in_tank_flag)($t8)
  li    $at, 1
  lui   $t7, %hi(dword_CODE_bss_800799B8) # $t7, 0x8008
  bnel  $t8, $at, .Ljp7F087004
   lw    $a0, 0x394($sp)
  lw    $t7, %lo(dword_CODE_bss_800799B8)($t7)
  li    $at, 2
  bnel  $t7, $at, .Ljp7F087004
   lw    $a0, 0x394($sp)
  lw    $v0, 4($v1)
  move  $a0, $zero
  sw    $v0, 0x138($sp)
  lw    $t2, 0x14($v0)
  move  $s0, $v0
  lw    $t9, 8($t2)
  lw    $t3, 8($t9)
  lw    $t4, 0x14($t3)
  lw    $t5, 4($t4)
  jal   get_item_in_hand
   sw    $t5, 0x130($sp)
  xori  $v1, $v0, 0x20
  sltiu $a0, $v1, 1
  beql  $a0, $zero, .Ljp7F086BA4
   sw    $a0, 0xc4($s0)
  jal   get_hands_firing_status
   move  $a0, $zero
  sltu  $a0, $zero, $v0
  sw    $a0, 0xc4($s0)
.Ljp7F086BA4:
  lui   $at, %hi(D_8003646C) # $at, 0x8003
  lwc1  $f8, %lo(D_8003646C)($at)
  lui   $at, %hi(D_80036474) # $at, 0x8003
  addiu $a1, $sp, 0xf0
  swc1  $f8, 0xc8($s0)
  lwc1  $f10, %lo(D_80036474)($at)
  lui   $at, %hi(D_80036464) # $at, 0x8003
  swc1  $f10, 0xcc($s0)
  lwc1  $f6, %lo(D_80036464)($at)
  lui   $at, %hi(D_80055258) # $at, 0x8005
  swc1  $f6, 0xdc($s0)
  lwc1  $f4, %lo(D_80055258)($at)
  lui   $at, %hi(D_80036464) # $at, 0x8003
  lwc1  $f8, %lo(D_80036464)($at)
  jal   sub_GAME_7F0585FC
   sub.s $f12, $f4, $f8
  lw    $t6, 0x138($sp)
  addiu $a1, $sp, 0xf0
  lw    $t8, 0x14($t6)
  jal   matrix_multiply_A1_by_F12
   lwc1  $f12, 0x14($t8)
  lui   $at, %hi(flt_CODE_bss_800799AC) # $at, 0x8008
  lwc1  $f10, %lo(flt_CODE_bss_800799A8)($at)
  lwc1  $f4, %lo(flt_CODE_bss_800799AC)($at)
  lui   $at, %hi(flt_CODE_bss_800799B0) # $at, 0x8008
  neg.s $f6, $f10
  lwc1  $f10, %lo(flt_CODE_bss_800799B0)($at)
  swc1  $f6, 0xe4($sp)
  neg.s $f8, $f4
  neg.s $f6, $f10
  swc1  $f8, 0xe8($sp)
  swc1  $f6, 0xec($sp)
  addiu $a0, $sp, 0xf0
  jal   sub_GAME_7F0583D8
   addiu $a1, $sp, 0xe4
  lw    $t0, ($s1)
  lwc1  $f4, 0xe4($sp)
  lwc1  $f6, 0xec($sp)
  lwc1  $f8, 0x48c($t0)
  lw    $v0, 0x138($sp)
  add.s $f10, $f4, $f8
  swc1  $f10, 0xe4($sp)
  lwc1  $f4, 0x494($t0)
  add.s $f8, $f6, $f4
  swc1  $f8, 0xec($sp)
  lw    $t7, 0x488($t0)
  lw    $t2, 0x10($v0)
  sw    $t7, 0x14($t2)
  lw    $t0, ($s1)
  lwc1  $f10, 0xec($sp)
  lw    $a0, 0x10($v0)
  lw    $a1, 0x48c($t0)
  lw    $a2, 0x494($t0)
  lw    $a3, 0xe4($sp)
  swc1  $f10, 0x10($sp)
  jal   sub_GAME_7F0B0BE4
   addiu $a0, $a0, 0x14
  lw    $t9, 0x138($sp)
  lw    $a1, 0xe4($sp)
  lw    $a2, 0xec($sp)
  lw    $t3, 0x10($t9)
  jal   sub_GAME_7F0B2970
   lw    $a0, 0x14($t3)
  lui   $v1, %hi(clock_timer) # $v1, 0x8005
  addiu $v1, %lo(clock_timer) # addiu $v1, $v1, -0x7c5c
  swc1  $f0, 0xd4($s0)
  lw    $t4, ($v1)
  move  $v0, $zero
  lui   $at, %hi(D_8005525C) # $at, 0x8005
  blez  $t4, .Ljp7F086CEC
   nop   
  lwc1  $f2, 0xd4($s0)
  lwc1  $f0, %lo(D_8005525C)($at)
  lwc1  $f6, 0xd0($s0)
.Ljp7F086CCC:
  addiu $v0, $v0, 1
  mul.s $f4, $f6, $f0
  add.s $f8, $f4, $f2
  swc1  $f8, 0xd0($s0)
  lw    $t5, ($v1)
  slt   $at, $v0, $t5
  bnezl $at, .Ljp7F086CCC
   lwc1  $f6, 0xd0($s0)
.Ljp7F086CEC:
  lui   $at, %hi(D_80055260) # $at, 0x8005
  lwc1  $f6, %lo(D_80055260)($at)
  lwc1  $f10, 0xd0($s0)
  lw    $a0, 0x130($sp)
  mul.s $f20, $f10, $f6
  jal   sub_GAME_7F03E864
   nop   
  lw    $v0, 0x138($sp)
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f6
  lw    $t6, 0x14($v0)
  addiu $a0, $sp, 0xf0
  addiu $a1, $v0, 0x18
  lwc1  $f4, 0x14($t6)
  mul.s $f8, $f0, $f4
  sub.s $f10, $f20, $f8
  add.s $f4, $f10, $f6
  jal   matrix_4x4_copy
   swc1  $f4, 0xe8($sp)
  lw    $a0, 0x138($sp)
  lwc1  $f0, 0xe4($sp)
  lw    $t8, 0x10($a0)
  swc1  $f0, 8($t8)
  swc1  $f0, 0x58($a0)
  lwc1  $f0, 0xe8($sp)
  lw    $t7, 0x10($a0)
  swc1  $f0, 0xc($t7)
  swc1  $f0, 0x5c($a0)
  lwc1  $f0, 0xec($sp)
  lw    $t2, 0x10($a0)
  swc1  $f0, 0x10($t2)
  jal   sub_GAME_7F056CA0
   swc1  $f0, 0x60($a0)
  jal   sub_GAME_7F040484
   lw    $a0, 0x138($sp)
  lw    $a1, ($s1)
  lui   $a2, %hi(D_80036464) # $a2, 0x8003
  lw    $a2, %lo(D_80036464)($a2)
  addiu $a0, $sp, 0xb4
  jal   sub_GAME_7F07C888
   addiu $a1, $a1, 0x48c
  lw    $t9, 0x138($sp)
  addiu $s0, $sp, 0x94
  move  $a1, $s0
  jal   sub_GAME_7F03CB8C
   lw    $a0, 0x10($t9)
  jal   sub_GAME_7F03E3FC
   move  $a0, $s0
  lui   $t3, %hi(ptr_list_object_lookup_indices) # $t3, 0x8007
  lw    $t3, %lo(ptr_list_object_lookup_indices)($t3)
  li    $at, 0x40400000 # 3.000000
  sw    $t3, 0x8c($sp)
  lh    $v0, ($t3)
  bltzl $v0, .Ljp7F087004
   lw    $a0, 0x394($sp)
  mtc1  $at, $f20
  nop   
  lw    $t6, 0x138($sp)
.Ljp7F086DD4:
  sll   $t4, $v0, 2
  subu  $t4, $t4, $v0
  sll   $t4, $t4, 2
  lw    $t8, 0x10($t6)
  addu  $t4, $t4, $v0
  lui   $t5, %hi(pos_data_entry) # $t5, 0x8007
  addiu $t5, %lo(pos_data_entry) # addiu $t5, $t5, -0x6388
  sll   $t4, $t4, 2
  addu  $s0, $t4, $t5
  beql  $s0, $t8, .Ljp7F086FEC
   lw    $t4, 0x8c($sp)
  lbu   $v0, ($s0)
  li    $at, 3
  li    $t7, 1
  bne   $v0, $at, .Ljp7F086F78
   move  $a0, $s0
  sw    $t7, 0x7c($sp)
  lw    $v1, 4($s0)
  addiu $a1, $sp, 0x80
  addiu $a2, $sp, 0x88
  addiu $a3, $sp, 0x84
  jal   sub_GAME_7F03CF88
   sw    $v1, 0x6c($sp)
  addiu $a0, $s0, 8
  sw    $a0, 0x50($sp)
  addiu $a1, $sp, 0xb4
  jal   sub_GAME_7F03CCD8
   li    $a2, 4
  beqz  $v0, .Ljp7F086F0C
   lw    $v1, 0x6c($sp)
  sw    $zero, 0x7c($sp)
  lb    $t2, 7($v1)
  li    $at, 4
  bnel  $t2, $at, .Ljp7F086F10
   lw    $t7, 0x7c($sp)
  lw    $t9, 0x14($v1)
  sll   $t3, $t9, 7
  bltzl $t3, .Ljp7F086F10
   lw    $t7, 0x7c($sp)
  jal   get_controls_locked_flag
   sw    $v1, 0x6c($sp)
  bnez  $v0, .Ljp7F086F0C
   lw    $v1, 0x6c($sp)
  lw    $t4, 0x14($v1)
  lui   $at, 0x100
  lui   $v0, %hi(D_80048380) # $v0, 0x8005
  or    $t5, $t4, $at
  sw    $t5, 0x14($v1)
  lw    $v0, %lo(D_80048380)($v0)
  li    $at, 3
  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  div   $zero, $v0, $at
  mfhi  $v0
  slti  $at, $v0, 2
  beqz  $at, .Ljp7F086EE8
   li    $a1, 183
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   move  $a2, $zero
  move  $a0, $v0
  jal   sub_GAME_7F053A10
   lw    $a1, 0x50($sp)
  lui   $v0, %hi(D_80048380) # $v0, 0x8005
  lw    $v0, %lo(D_80048380)($v0)
  li    $at, 3
  div   $zero, $v0, $at
  mfhi  $v0
  nop   
  nop   
.Ljp7F086EE8:
  blez  $v0, .Ljp7F086F0C
   lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 213
  jal   play_sfx_a1
   move  $a2, $zero
  move  $a0, $v0
  jal   sub_GAME_7F053A10
   lw    $a1, 0x50($sp)
.Ljp7F086F0C:
  lw    $t7, 0x7c($sp)
.Ljp7F086F10:
  lw    $a0, 0x50($sp)
  lw    $a1, 0x80($sp)
  beqz  $t7, .Ljp7F086F34
   addiu $a2, $sp, 0xb4
  jal   sub_GAME_7F044718
   li    $a3, 4
  beql  $v0, $zero, .Ljp7F086F38
   lw    $t2, 0x7c($sp)
  sw    $zero, 0x7c($sp)
.Ljp7F086F34:
  lw    $t2, 0x7c($sp)
.Ljp7F086F38:
  lw    $t9, 0x138($sp)
  bnezl $t2, .Ljp7F086FEC
   lw    $t4, 0x8c($sp)
  lwc1  $f8, 0x58($t9)
  mfc1  $a2, $f20
  addiu $a1, $sp, 0x70
  swc1  $f8, 0x70($sp)
  lwc1  $f10, 0xc($s0)
  li    $a3, 1
  swc1  $f10, 0x74($sp)
  lwc1  $f6, 0x60($t9)
  swc1  $f6, 0x78($sp)
  jal   sub_GAME_7F027804
   lw    $a0, 4($s0)
  b     .Ljp7F086FEC
   lw    $t4, 0x8c($sp)
.Ljp7F086F78:
  li    $at, 1
  bne   $v0, $at, .Ljp7F086FE8
   move  $a0, $s0
  addiu $a1, $sp, 0x64
  jal   sub_GAME_7F03CCB0
   addiu $a2, $sp, 0x60
  lw    $a1, 0x60($sp)
  lw    $a0, 0x64($sp)
  addiu $a2, $sp, 0xb4
  blezl $a1, .Ljp7F086FEC
   lw    $t4, 0x8c($sp)
  jal   sub_GAME_7F0446B8
   li    $a3, 4
  beql  $v0, $zero, .Ljp7F086FEC
   lw    $t4, 0x8c($sp)
  jal   get_cur_playernum
   nop   
  lw    $a2, 4($s0)
  lui   $a1, (0x461C4000 >> 16) # lui $a1, 0x461c
  ori   $a1, (0x461C4000 & 0xFFFF) # ori $a1, $a1, 0x4000
  sw    $v0, 0x10($sp)
  move  $a0, $s0
  li    $a3, 32
  jal   sub_GAME_7F04DEFC
   addiu $a2, $a2, 0x58
  li    $t3, 90
  lui   $at, %hi(D_80036490) # $at, 0x8003
  sw    $t3, %lo(D_80036490)($at)
.Ljp7F086FE8:
  lw    $t4, 0x8c($sp)
.Ljp7F086FEC:
  addiu $t5, $t4, 2
  sw    $t5, 0x8c($sp)
  lh    $v0, ($t5)
  bgezl $v0, .Ljp7F086DD4
   lw    $t6, 0x138($sp)
  lw    $a0, 0x394($sp)
.Ljp7F087004:
  jal   sub_GAME_7F080DF8
   lw    $a1, 0x390($sp)
  jal   sub_GAME_7F081478
   nop   
  jal   sub_GAME_7F08A19C
   nop   
  jal   get_debug_man_pos_flag
   nop   
  beql  $v0, $zero, .Ljp7F087048
   lw    $ra, 0x2c($sp)
  lw    $t0, ($s1)
  addiu $a3, $sp, 0x5c
  lw    $a0, 0x488($t0)
  lw    $a1, 0x48c($t0)
  jal   copy_tile_RGB_as_24bit
   lw    $a2, 0x494($t0)
  lw    $ra, 0x2c($sp)
.Ljp7F087048:
  ldc1  $f20, 0x18($sp)
  lw    $s0, 0x24($sp)
  lw    $s1, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x3b8
  
");
#endif

#endif


asm(R"
glabel sub_GAME_7F086990
  addiu $sp, $sp, -0x70
  lui   $t7, %hi(D_80036800) 
  sw    $ra, 0x24($sp)
  sw    $a0, 0x70($sp)
  sw    $a1, 0x74($sp)
  sw    $a2, 0x78($sp)
  sw    $a3, 0x7c($sp)
  addiu $t7, %lo(D_80036800) # addiu $t7, $t7, 0x6800
  lw    $at, ($t7)
  addiu $t6, $sp, 0x64
  lw    $t0, 4($t7)
  sw    $at, ($t6)
  lw    $at, 8($t7)
  lui   $t2, %hi(D_8003680C) 
  addiu $t2, %lo(D_8003680C) # addiu $t2, $t2, 0x680c
  sw    $t0, 4($t6)
  sw    $at, 8($t6)
  lw    $at, ($t2)
  addiu $t1, $sp, 0x58
  lw    $t5, 4($t2)
  sw    $at, ($t1)
  lw    $at, 8($t2)
  lui   $t8, %hi(D_80036818) 
  addiu $t8, %lo(D_80036818) # addiu $t8, $t8, 0x6818
  sw    $t5, 4($t1)
  sw    $at, 8($t1)
  lw    $at, ($t8)
  addiu $t9, $sp, 0x4c
  lw    $t0, 4($t8)
  sw    $at, ($t9)
  lw    $at, 8($t8)
  lui   $t3, %hi(D_80036824) 
  addiu $t3, %lo(D_80036824) # addiu $t3, $t3, 0x6824
  sw    $t0, 4($t9)
  sw    $at, 8($t9)
  lw    $at, ($t3)
  addiu $t4, $sp, 0x40
  lw    $t5, 4($t3)
  sw    $at, ($t4)
  lw    $at, 8($t3)
  sw    $t5, 4($t4)
  jal   sub_GAME_7F083FC8
   sw    $at, 8($t4)
  jal   sub_GAME_7F084360
   nop   
  move  $a0, $zero
  move  $a1, $zero
  move  $a2, $zero
  jal   controller_gameplay_interaction
   move  $a3, $zero
  jal   sub_GAME_7F081790
   nop   
  mtc1  $zero, $f12
  nop   
  mfc1  $a2, $f12
  jal   sub_GAME_7F080B34
   mov.s $f14, $f12
  lui   $v0, %hi(flt_CODE_bss_80079990)
  addiu $v0, %lo(flt_CODE_bss_80079990) # addiu $v0, $v0, -0x6670
  mtc1  $zero, $f12
  lwc1  $f2, ($v0)
  lui   $at, %hi(global_timer_delta)
  c.eq.s $f12, $f2
  nop   
  bc1f  .L7F086AAC
   nop   
  lwc1  $f4, 8($v0)
  c.eq.s $f12, $f4
  nop   
  bc1t  .L7F086AD4
   nop   
.L7F086AAC:
  lwc1  $f0, %lo(global_timer_delta)($at)
  lwc1  $f18, 8($v0)
  lwc1  $f6, 0x40($sp)
  mul.s $f8, $f2, $f0
  lwc1  $f16, 0x48($sp)
  mul.s $f4, $f18, $f0
  add.s $f10, $f6, $f8
  add.s $f6, $f16, $f4
  swc1  $f10, 0x40($sp)
  swc1  $f6, 0x48($sp)
.L7F086AD4:
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lui   $at, %hi(global_timer_delta)
  lwc1  $f0, %lo(global_timer_delta)($at)
  lwc1  $f8, 0x504($v0)
  lwc1  $f10, 0x498($v0)
  lwc1  $f16, 0x4fc($v0)
  lwc1  $f4, 0x4a0($v0)
  mul.s $f18, $f8, $f10
  addiu $a0, $sp, 0x40
  li    $a1, 1
  mul.s $f6, $f16, $f4
  lwc1  $f16, 0x40($sp)
  sub.s $f8, $f18, $f6
  mul.s $f10, $f8, $f0
  add.s $f4, $f16, $f10
  swc1  $f4, 0x40($sp)
  lwc1  $f6, 0x4a0($v0)
  lwc1  $f18, 0x504($v0)
  lwc1  $f10, 0x498($v0)
  lwc1  $f16, 0x4fc($v0)
  mul.s $f8, $f18, $f6
  nop   
  mul.s $f4, $f16, $f10
  lwc1  $f16, 0x48($sp)
  add.s $f18, $f8, $f4
  mul.s $f6, $f18, $f0
  add.s $f10, $f16, $f6
  jal   sub_GAME_7F07D960
   swc1  $f10, 0x48($sp)
  mtc1  $zero, $f12
  move  $a0, $zero
  mfc1  $a1, $f12
  jal   sub_GAME_7F080DF8
   nop   
  jal   sub_GAME_7F081478
   nop   
  lui   $v0, %hi(cameramode)
  lw    $v0, %lo(cameramode)($v0)
  li    $at, 8
  beq   $v0, $at, .L7F086B8C
   li    $at, 4
  beq   $v0, $at, .L7F086B8C
   li    $at, 10
  bne   $v0, $at, .L7F086B9C
   lhu   $a0, 0x7a($sp)
.L7F086B8C:
  jal   setptrBONDdata
   move  $a0, $zero
  b     .L7F086BEC
   lw    $ra, 0x24($sp)
.L7F086B9C:
  addiu $t7, $sp, 0x4c
  addiu $t6, $sp, 0x3c
  addiu $t9, $sp, 0x30
  sw    $t9, 0x18($sp)
  sw    $t6, 0x14($sp)
  sw    $t7, 0x10($sp)
  lhu   $a1, 0x7e($sp)
  addiu $a2, $sp, 0x64
  jal   sub_GAME_7F07B56C
   addiu $a3, $sp, 0x58
  jal   setptrBONDdata
   li    $a0, 1
  addiu $t8, $sp, 0x30
  sw    $t8, 0x10($sp)
  addiu $a0, $sp, 0x64
  addiu $a1, $sp, 0x58
  addiu $a2, $sp, 0x4c
  jal   sub_GAME_7F079A60
   lw    $a3, 0x3c($sp)
  lw    $ra, 0x24($sp)
.L7F086BEC:
  addiu $sp, $sp, 0x70
  jr    $ra
   nop   
");





int getWidth320or440(void) {
  if (camera_8003642C != 0) {
    return 440;
  }
  return 320;
}

int getHeight330or240(void) {
  if (camera_8003642C != 0) {
    return 330;
  }
  return 240;
}

int get_curplayer_viewport_width(void)
{
  if (getPlayerCount() >= 3) {
    return 159;
  }
  if (camera_8003642C != 0) {
    return 440;
  }
  if (cur_player_get_screen_setting() == 1) {
    return 320;
  }
  if (cur_player_get_screen_setting() == 2) {
    return 320;
  }
  return 320;
}

int get_curplayer_viewport_ulx(void)
{
  if (2 < getPlayerCount()) {
    if ((get_cur_playernum() == 1) || (get_cur_playernum() == 3)) {
      return 0xa1;
    }
  }
  return 0;
}


asm(R"
glabel get_curplayer_viewport_height
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   getPlayerCount
   nop   
  slti  $at, $v0, 2
  bnez  $at, .L7F086D48
   lui   $t6, %hi(camera_8003642C) 
  b     .L7F086E28
   li    $v0, 109
.L7F086D48:
  lw    $t6, %lo(camera_8003642C)($t6)
  beqz  $t6, .L7F086D94
   nop   
  jal   cur_player_get_screen_setting
   nop   
  li    $at, 1
  bne   $v0, $at, .L7F086D70
   nop   
  b     .L7F086E28
   li    $v0, 248
.L7F086D70:
  jal   cur_player_get_screen_setting
   nop   
  li    $at, 2
  bne   $v0, $at, .L7F086D8C
   nop   
  b     .L7F086E28
   li    $v0, 190
.L7F086D8C:
  b     .L7F086E28
   li    $v0, 304
.L7F086D94:
  jal   cur_player_get_screen_setting
   nop   
  li    $at, 1
  bne   $v0, $at, .L7F086DDC
   nop   
  jal   sub_GAME_7F07EA78
   nop   
  li    $at, 0x42200000 # 40.000000
  mtc1  $at, $f4
  nop   
  mul.s $f6, $f4, $f0
  trunc.w.s $f8, $f6
  mfc1  $v0, $f8
  nop   
  addiu $v0, $v0, 0xb4
  sll   $t8, $v0, 0x10
  b     .L7F086E28
   sra   $v0, $t8, 0x10
.L7F086DDC:
  jal   cur_player_get_screen_setting
   nop   
  li    $at, 2
  bnel  $v0, $at, .L7F086E28
   li    $v0, 220
  jal   sub_GAME_7F07EA78
   nop   
  li    $at, 0x42A80000 # 84.000000
  mtc1  $at, $f10
  nop   
  mul.s $f16, $f10, $f0
  trunc.w.s $f18, $f16
  mfc1  $v0, $f18
  nop   
  addiu $v0, $v0, 0x88
  sll   $t1, $v0, 0x10
  b     .L7F086E28
   sra   $v0, $t1, 0x10
  li    $v0, 220
.L7F086E28:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");






asm(R"
glabel get_curplayer_viewport_uly
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   getPlayerCount
   nop   
  li    $at, 2
  bne   $v0, $at, .L7F086E74
   nop   
  jal   get_cur_playernum
   nop   
  bnez  $v0, .L7F086E6C
   nop   
  b     .L7F086F8C
   li    $v0, 10
.L7F086E6C:
  b     .L7F086F8C
   li    $v0, 121
.L7F086E74:
  jal   getPlayerCount
   nop   
  slti  $at, $v0, 3
  bnez  $at, .L7F086EAC
   lui   $t6, %hi(camera_8003642C) 
  jal   get_cur_playernum
   nop   
  slti  $at, $v0, 2
  beqz  $at, .L7F086EA4
   nop   
  b     .L7F086F8C
   li    $v0, 10
.L7F086EA4:
  b     .L7F086F8C
   li    $v0, 121
.L7F086EAC:
  lw    $t6, %lo(camera_8003642C)($t6)
  beqz  $t6, .L7F086EF8
   nop   
  jal   cur_player_get_screen_setting
   nop   
  li    $at, 1
  bne   $v0, $at, .L7F086ED4
   nop   
  b     .L7F086F8C
   li    $v0, 41
.L7F086ED4:
  jal   cur_player_get_screen_setting
   nop   
  li    $at, 2
  bne   $v0, $at, .L7F086EF0
   nop   
  b     .L7F086F8C
   li    $v0, 70
.L7F086EF0:
  b     .L7F086F8C
   li    $v0, 13
.L7F086EF8:
  jal   cur_player_get_screen_setting
   nop   
  li    $at, 1
  bne   $v0, $at, .L7F086F40
   nop   
  jal   sub_GAME_7F07EA78
   nop   
  li    $at, 0xC1A00000 # -20.000000
  mtc1  $at, $f4
  nop   
  mul.s $f6, $f4, $f0
  trunc.w.s $f8, $f6
  mfc1  $v0, $f8
  nop   
  addiu $v0, $v0, 0x1e
  sll   $t8, $v0, 0x10
  b     .L7F086F8C
   sra   $v0, $t8, 0x10
.L7F086F40:
  jal   cur_player_get_screen_setting
   nop   
  li    $at, 2
  bnel  $v0, $at, .L7F086F8C
   li    $v0, 10
  jal   sub_GAME_7F07EA78
   nop   
  li    $at, 0xC2280000 # -42.000000
  mtc1  $at, $f10
  nop   
  mul.s $f16, $f10, $f0
  trunc.w.s $f18, $f16
  mfc1  $v0, $f18
  nop   
  addiu $v0, $v0, 0x34
  sll   $t1, $v0, 0x10
  b     .L7F086F8C
   sra   $v0, $t1, 0x10
  li    $v0, 10
.L7F086F8C:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

#ifdef VERSION_US
asm(R"
.late_rodata
glabel D_80055264
.word 0x3fe38e39 /*1.7777778*/
glabel D_80055268
.word 0x3fe38e39 /*1.7777778*/
.text
glabel possibly_reset_viewport_options_for_player
  addiu $sp, $sp, -0x20
  li    $at, 0x42700000 # 60.000000
  sw    $ra, 0x14($sp)
  mtc1  $at, $f12
  sw    $a0, 0x20($sp)
  sw    $a1, 0x24($sp)
  jal   set_cur_player_fovy
   sw    $a2, 0x28($sp)
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f12
  jal   setvideo_far
   nop   
  lui   $v1, %hi(camera_80036430)
  addiu $v1, %lo(camera_80036430) # addiu $v1, $v1, 0x6430
  lw    $v0, ($v1)
  beqz  $v0, .L7F087034
   slti  $at, $v0, 4
  bnez  $at, .L7F087024
   lui   $t6, %hi(resolution) 
  lw    $t6, %lo(resolution)($t6)
  beql  $t6, $zero, .L7F087028
   lw    $t9, ($v1)
  jal   get_video_settings2_frameb
   nop   
  lui   $t7, %hi(cfb_16_b) # $t7, 0x803e
  addiu $t7, %lo(cfb_16_b) # addiu $t7, $t7, -0x5800
  lui   $v1, %hi(camera_80036430)
  bne   $v0, $t7, .L7F087024
   addiu $v1, %lo(camera_80036430) # addiu $v1, $v1, 0x6430
  li    $t8, 1
  lui   $at, %hi(camera_8003642C)
  sw    $t8, %lo(camera_8003642C)($at)
  b     .L7F087088
   sw    $zero, ($v1)
.L7F087024:
  lw    $t9, ($v1)
.L7F087028:
  addiu $t0, $t9, 1
  b     .L7F087088
   sw    $t0, ($v1)
.L7F087034:
  lui   $v1, %hi(camera_80036434)
  addiu $v1, %lo(camera_80036434) # addiu $v1, $v1, 0x6434
  lw    $v0, ($v1)
  beqz  $v0, .L7F087088
   slti  $at, $v0, 4
  bnezl $at, .L7F087080
   lw    $t2, ($v1)
  jal   get_video_settings2_frameb
   nop   
  lui   $t1, %hi(cfb_16_a) # $t1, 0x803b
  addiu $t1, %lo(cfb_16_a) # addiu $t1, $t1, 0x5000
  lui   $v1, %hi(camera_80036434)
  bne   $v0, $t1, .L7F08707C
   addiu $v1, %lo(camera_80036434) # addiu $v1, $v1, 0x6434
  lui   $at, %hi(camera_8003642C)
  sw    $zero, %lo(camera_8003642C)($at)
  b     .L7F087088
   sw    $zero, ($v1)
.L7F08707C:
  lw    $t2, ($v1)
.L7F087080:
  addiu $t3, $t2, 1
  sw    $t3, ($v1)
.L7F087088:
  lui   $t4, %hi(camera_8003642C) 
  lw    $t4, %lo(camera_8003642C)($t4)
  beqz  $t4, .L7F0870B8
   nop   
  jal   get_video_settings2_frameb
   nop   
  lui   $t5, %hi(cfb_16_b) # $t5, 0x803e
  addiu $t5, %lo(cfb_16_b) # addiu $t5, $t5, -0x5800
  bne   $v0, $t5, .L7F0870B8
   lui   $a0, %hi(resolution)
  jal   set_video2buf_frameb
   lw    $a0, %lo(resolution)($a0)
.L7F0870B8:
  jal   get_screen_ratio
   nop   
  li    $at, 1
  bne   $v0, $at, .L7F08716C
   nop   
  jal   get_curplayer_viewport_width
   nop   
  jal   get_curplayer_viewport_height
   sh    $v0, 0x1c($sp)
  lh    $t6, 0x1c($sp)
  mtc1  $v0, $f8
  li    $at, 0x3F400000 # 0.750000
  mtc1  $t6, $f4
  cvt.s.w $f10, $f8
  mtc1  $at, $f18
  lui   $at, %hi(D_80055264)
  lwc1  $f8, %lo(D_80055264)($at)
  cvt.s.w $f6, $f4
  div.s $f16, $f6, $f10
  mul.s $f4, $f16, $f18
  nop   
  mul.s $f12, $f4, $f8
  jal   set_cur_player_aspect
   nop   
  jal   get_curplayer_viewport_width
   nop   
  jal   get_curplayer_viewport_height
   sh    $v0, 0x1c($sp)
  lh    $t7, 0x1c($sp)
  mtc1  $v0, $f16
  li    $at, 0x3F400000 # 0.750000
  mtc1  $t7, $f6
  cvt.s.w $f18, $f16
  mtc1  $at, $f8
  lui   $at, %hi(D_80055268)
  lwc1  $f16, %lo(D_80055268)($at)
  cvt.s.w $f10, $f6
  div.s $f4, $f10, $f18
  mul.s $f6, $f4, $f8
  nop   
  mul.s $f12, $f6, $f16
  jal   video_related_21
   nop   
  b     .L7F0871C4
   nop   
.L7F08716C:
  jal   get_curplayer_viewport_width
   nop   
  jal   get_curplayer_viewport_height
   sh    $v0, 0x1c($sp)
  lh    $t8, 0x1c($sp)
  mtc1  $v0, $f4
  mtc1  $t8, $f10
  cvt.s.w $f8, $f4
  cvt.s.w $f18, $f10
  jal   set_cur_player_aspect
   div.s $f12, $f18, $f8
  jal   get_curplayer_viewport_width
   nop   
  jal   get_curplayer_viewport_height
   sh    $v0, 0x1c($sp)
  lh    $t9, 0x1c($sp)
  mtc1  $v0, $f10
  mtc1  $t9, $f6
  cvt.s.w $f4, $f10
  cvt.s.w $f16, $f6
  jal   video_related_21
   div.s $f12, $f16, $f4
.L7F0871C4:
  jal   get_curplayer_viewport_width
   nop   
  jal   get_curplayer_viewport_height
   sh    $v0, 0x1c($sp)
  lh    $a0, 0x1c($sp)
  jal   set_cur_player_screen_size
   move  $a1, $v0
  jal   get_curplayer_viewport_ulx
   nop   
  jal   get_curplayer_viewport_uly
   sh    $v0, 0x1c($sp)
  lh    $a0, 0x1c($sp)
  jal   set_cur_player_viewport_size
   move  $a1, $v0
  jal   getWidth320or440
   nop   
  jal   getHeight330or240
   sh    $v0, 0x1c($sp)
  sll   $a1, $v0, 0x10
  sra   $t0, $a1, 0x10
  move  $a1, $t0
  jal   set_video2_text_clip_size
   lh    $a0, 0x1c($sp)
  jal   getWidth320or440
   nop   
  jal   getHeight330or240
   sh    $v0, 0x1c($sp)
  sll   $a1, $v0, 0x10
  sra   $t1, $a1, 0x10
  move  $a1, $t1
  jal   set_video2_settings_offset_18_1A
   lh    $a0, 0x1c($sp)
  jal   get_curplayer_viewport_width
   nop   
  jal   get_curplayer_viewport_height
   sh    $v0, 0x1c($sp)
  sll   $a1, $v0, 0x10
  sra   $t2, $a1, 0x10
  move  $a1, $t2
  jal   set_video2_width_height
   lh    $a0, 0x1c($sp)
  jal   get_curplayer_viewport_ulx
   nop   
  jal   get_curplayer_viewport_uly
   sh    $v0, 0x1c($sp)
  sll   $a1, $v0, 0x10
  sra   $t3, $a1, 0x10
  move  $a1, $t3
  jal   set_video2_ulx_uly
   lh    $a0, 0x1c($sp)
  jal   sub_GAME_7F0808BC
   nop   
  jal   update_curplayer_fade
   nop   
  jal   cur_player_get_autoaim
   nop   
  jal   set_BONDdata_autoaim_y
   move  $a0, $v0
  jal   cur_player_get_autoaim
   nop   
  jal   set_BONDdata_autoaim_x
   move  $a0, $v0
  jal   cur_player_get_lookahead
   nop   
  jal   set_BONDdata_lookahead_setting
   move  $a0, $v0
  jal   cur_player_get_ammo_onscreen_setting
   nop   
  li    $a0, 1
  jal   set_unset_ammo_on_screen_setting
   move  $a1, $v0
  jal   getPlayerCount
   nop   
  li    $at, 1
  bne   $v0, $at, .L7F087308
   nop   
  jal   cur_player_get_sight_onscreen_control
   nop   
  sltu  $a1, $zero, $v0
  bnez  $a1, .L7F087330
   nop   
.L7F087308:
  jal   getPlayerCount
   nop   
  slti  $v1, $v0, 2
  xori  $a1, $v1, 1
  beqz  $a1, .L7F087330
   lui   $t4, %hi(pPlayersPerm) 
  lw    $t4, %lo(pPlayersPerm)($t4)
  lbu   $a1, 0x6b($t4)
  sltu  $t5, $zero, $a1
  move  $a1, $t5
.L7F087330:
  jal   set_unset_bitflags
   li    $a0, 1
  lui   $v0, %hi(cameramode)
  lw    $v0, %lo(cameramode)($v0)
  li    $at, 4
  beqz  $v0, .L7F087368
   nop   
  bne   $v0, $at, .L7F08735C
   lui   $t6, %hi(D_800364B0) 
  lw    $t6, %lo(D_800364B0)($t6)
  bnez  $t6, .L7F087368
.L7F08735C:
   li    $at, 10
  bne   $v0, $at, .L7F0873B4
   lb    $a0, 0x23($sp)
.L7F087368:
  jal   get_cur_playernum
   nop   
  bnez  $v0, .L7F087394
   lui   $t0, %hi(pPlayer) 
  lui   $v0, %hi(mission_timer)
  addiu $v0, %lo(mission_timer) # addiu $v0, $v0, -0x65e0
  lui   $t8, %hi(clock_timer) 
  lw    $t8, %lo(clock_timer)($t8)
  lw    $t7, ($v0)
  addu  $t9, $t7, $t8
  sw    $t9, ($v0)
.L7F087394:
  lw    $t0, %lo(pPlayer)($t0)
  lb    $a0, 0x23($sp)
  lb    $a1, 0x27($sp)
  lhu   $a2, 0x2a($sp)
  jal   MoveBond
   lhu   $a3, 0x3b4($t0)
  b     .L7F0873CC
   nop   
.L7F0873B4:
  lui   $t1, %hi(pPlayer) 
  lw    $t1, %lo(pPlayer)($t1)
  lb    $a1, 0x27($sp)
  lhu   $a2, 0x2a($sp)
  jal   sub_GAME_7F086990
   lhu   $a3, 0x3b4($t1)
.L7F0873CC:
  lui   $v0, %hi(watch_time_0)
  addiu $v0, %lo(watch_time_0) # addiu $v0, $v0, -0x65dc
  lui   $t3, %hi(D_80048498) 
  lw    $t3, %lo(D_80048498)($t3)
  lw    $t2, ($v0)
  lui   $t5, %hi(stop_time_flag) 
  addu  $t4, $t2, $t3
  sw    $t4, ($v0)
  lw    $t5, %lo(stop_time_flag)($t5)
  beqz  $t5, .L7F08750C
   nop   
  jal   get_controls_locked_flag
   nop   
  bnez  $v0, .L7F0874C0
   lui   $t7, %hi(pPlayer) 
  lw    $t7, %lo(pPlayer)($t7)
  lhu   $t6, 0x2a($sp)
  li    $t2, 2
  lhu   $t8, 0x3b4($t7)
  lui   $at, %hi(stop_time_flag)
  not   $t9, $t8
  and   $t0, $t6, $t9
  andi  $t1, $t0, 0xf030
  beqz  $t1, .L7F0874C0
   nop   
  jal   check_if_fade_to_black_complete
   sw    $t2, %lo(stop_time_flag)($at)
  beqz  $v0, .L7F087490
   lui   $t3, %hi(pPlayer) 
  lw    $t3, %lo(pPlayer)($t3)
  mtc1  $zero, $f0
  move  $a0, $zero
  lwc1  $f18, 0x3dc($t3)
  move  $a1, $zero
  c.eq.s $f0, $f18
  nop   
  bc1f  .L7F0874C0
   nop   
  mfc1  $a3, $f0
  jal   set_rgba_tint
   move  $a2, $zero
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f12
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f14
  jal   fade_to_over_seconds
   nop   
  b     .L7F0874C0
   nop   
.L7F087490:
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  mtc1  $zero, $f0
  li    $at, 0x3F800000 # 1.000000
  lwc1  $f8, 0x404($v0)
  c.eq.s $f0, $f8
  nop   
  bc1f  .L7F0874C0
   nop   
  mtc1  $at, $f14
  jal   fade_to_over_seconds
   lwc1  $f12, 0x3e0($v0)
.L7F0874C0:
  lui   $t4, %hi(stop_time_flag) 
  lw    $t4, %lo(stop_time_flag)($t4)
  li    $at, 2
  bne   $t4, $at, .L7F08750C
   nop   
  jal   check_if_fade_to_black_complete
   nop   
  beqz  $v0, .L7F08750C
   lui   $t5, %hi(pPlayer) 
  lw    $t5, %lo(pPlayer)($t5)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  lwc1  $f10, 0x3dc($t5)
  c.eq.s $f6, $f10
  nop   
  bc1f  .L7F08750C
   nop   
  jal   return_to_title_from_level_end
   nop   
.L7F08750C:
  lui   $t7, %hi(enable_move_after_cinema) 
  lw    $t7, %lo(enable_move_after_cinema)($t7)
  beqz  $t7, .L7F087524
   nop   
  jal   sub_GAME_7F07B1A4
   nop   
.L7F087524:
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lw    $t8, 0xd8($v0)
  beqz  $t8, .L7F087598
   nop   
  lw    $v1, 0x424($v0)
  li    $a0, 1
  bnez  $v1, .L7F087568
   nop   
  jal   draw_item_in_hand_has_more_ammo
   move  $a1, $zero
  move  $a0, $zero
  jal   draw_item_in_hand_has_more_ammo
   move  $a1, $zero
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lw    $v1, 0x424($v0)
.L7F087568:
  beqz  $v1, .L7F087598
   nop   
  lw    $t6, 0x428($v0)
  lui   $t9, %hi(D_80036510) 
  beqz  $t6, .L7F087598
   nop   
  lw    $t9, %lo(D_80036510)($t9)
  slti  $at, $t9, 3
  bnez  $at, .L7F087598
   nop   
  jal   run_title_stage
   nop   
.L7F087598:
  lui   $t0, %hi(cameramode) 
  lw    $t0, %lo(cameramode)($t0)
  li    $at, 10
  bne   $t0, $at, .L7F0875C4
   nop   
  jal   check_if_fade_to_black_complete
   nop   
  beqz  $v0, .L7F0875C4
   nop   
  jal   run_title_stage
   nop   
.L7F0875C4:
  lui   $t2, %hi(pPlayer) 
  lw    $t2, %lo(pPlayer)($t2)
  lhu   $t1, 0x2a($sp)
  sh    $t1, 0x3b4($t2)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

#ifdef VERSION_JP
asm(R"
.late_rodata
glabel D_80055264
.word 0x3fe38e39 /*1.7777778*/
glabel D_80055268
.word 0x3fe38e39 /*1.7777778*/
.text
glabel possibly_reset_viewport_options_for_player
  addiu $sp, $sp, -0x20
  li    $at, 0x42700000 # 60.000000
  sw    $ra, 0x14($sp)
  mtc1  $at, $f12
  sw    $a0, 0x20($sp)
  sw    $a1, 0x24($sp)
  jal   set_cur_player_fovy
   sw    $a2, 0x28($sp)
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f12
  jal   setvideo_far
   nop   
  lui   $v1, %hi(camera_80036430) # $v1, 0x8003
  addiu $v1, %lo(camera_80036430) # addiu $v1, $v1, 0x6470
  lw    $v0, ($v1)
  beqz  $v0, .Ljp7F087700
   slti  $at, $v0, 4
  bnez  $at, .Ljp7F0876F0
   lui   $t6, %hi(resolution) # $t6, 0x8003
  lw    $t6, %lo(resolution)($t6)
  beql  $t6, $zero, .Ljp7F0876F4
   lw    $t9, ($v1)
  jal   get_video_settings2_frameb
   nop   
  lui   $t7, %hi(cfb_16_b) # $t7, 0x803e
  addiu $t7, %lo(cfb_16_b) # addiu $t7, $t7, -0x5800
  lui   $v1, %hi(camera_80036430) # $v1, 0x8003
  bne   $v0, $t7, .Ljp7F0876F0
   addiu $v1, %lo(camera_80036430) # addiu $v1, $v1, 0x6470
  li    $t8, 1
  lui   $at, %hi(camera_8003642C) # $at, 0x8003
  sw    $t8, %lo(camera_8003642C)($at)
  b     .Ljp7F087754
   sw    $zero, ($v1)
.Ljp7F0876F0:
  lw    $t9, ($v1)
.Ljp7F0876F4:
  addiu $t0, $t9, 1
  b     .Ljp7F087754
   sw    $t0, ($v1)
.Ljp7F087700:
  lui   $v1, %hi(camera_80036434) # $v1, 0x8003
  addiu $v1, %lo(camera_80036434) # addiu $v1, $v1, 0x6474
  lw    $v0, ($v1)
  beqz  $v0, .Ljp7F087754
   slti  $at, $v0, 4
  bnezl $at, .Ljp7F08774C
   lw    $t2, ($v1)
  jal   get_video_settings2_frameb
   nop   
  lui   $t1, %hi(cfb_16_a) # $t1, 0x803b
  addiu $t1, %lo(cfb_16_a) # addiu $t1, $t1, 0x5000
  lui   $v1, %hi(camera_80036434) # $v1, 0x8003
  bne   $v0, $t1, .Ljp7F087748
   addiu $v1, %lo(camera_80036434) # addiu $v1, $v1, 0x6474
  lui   $at, %hi(camera_8003642C) # $at, 0x8003
  sw    $zero, %lo(camera_8003642C)($at)
  b     .Ljp7F087754
   sw    $zero, ($v1)
.Ljp7F087748:
  lw    $t2, ($v1)
.Ljp7F08774C:
  addiu $t3, $t2, 1
  sw    $t3, ($v1)
.Ljp7F087754:
  lui   $t4, %hi(camera_8003642C) # $t4, 0x8003
  lw    $t4, %lo(camera_8003642C)($t4)
  beqz  $t4, .Ljp7F087784
   nop   
  jal   get_video_settings2_frameb
   nop   
  lui   $t5, %hi(cfb_16_b) # $t5, 0x803e
  addiu $t5, %lo(cfb_16_b) # addiu $t5, $t5, -0x5800
  bne   $v0, $t5, .Ljp7F087784
   lui   $a0, %hi(resolution) # $a0, 0x8003
  jal   set_video2buf_frameb
   lw    $a0, %lo(resolution)($a0)
.Ljp7F087784:
  jal   get_screen_ratio
   nop   
  li    $at, 1
  bne   $v0, $at, .Ljp7F087838
   nop   
  jal   get_curplayer_viewport_width
   nop   
  jal   get_curplayer_viewport_height
   sh    $v0, 0x1c($sp)
  lh    $t6, 0x1c($sp)
  mtc1  $v0, $f8
  li    $at, 0x3F400000 # 0.750000
  mtc1  $t6, $f4
  cvt.s.w $f10, $f8
  mtc1  $at, $f18
  lui   $at, %hi(D_80055264) # $at, 0x8005
  lwc1  $f8, %lo(D_80055264)($at)
  cvt.s.w $f6, $f4
  div.s $f16, $f6, $f10
  mul.s $f4, $f16, $f18
  nop   
  mul.s $f12, $f4, $f8
  jal   set_cur_player_aspect
   nop   
  jal   get_curplayer_viewport_width
   nop   
  jal   get_curplayer_viewport_height
   sh    $v0, 0x1c($sp)
  lh    $t7, 0x1c($sp)
  mtc1  $v0, $f16
  li    $at, 0x3F400000 # 0.750000
  mtc1  $t7, $f6
  cvt.s.w $f18, $f16
  mtc1  $at, $f8
  lui   $at, %hi(D_80055268) # $at, 0x8005
  lwc1  $f16, %lo(D_80055268)($at)
  cvt.s.w $f10, $f6
  div.s $f4, $f10, $f18
  mul.s $f6, $f4, $f8
  nop   
  mul.s $f12, $f6, $f16
  jal   video_related_21
   nop   
  b     .Ljp7F087890
   nop   
.Ljp7F087838:
  jal   get_curplayer_viewport_width
   nop   
  jal   get_curplayer_viewport_height
   sh    $v0, 0x1c($sp)
  lh    $t8, 0x1c($sp)
  mtc1  $v0, $f4
  mtc1  $t8, $f10
  cvt.s.w $f8, $f4
  cvt.s.w $f18, $f10
  jal   set_cur_player_aspect
   div.s $f12, $f18, $f8
  jal   get_curplayer_viewport_width
   nop   
  jal   get_curplayer_viewport_height
   sh    $v0, 0x1c($sp)
  lh    $t9, 0x1c($sp)
  mtc1  $v0, $f10
  mtc1  $t9, $f6
  cvt.s.w $f4, $f10
  cvt.s.w $f16, $f6
  jal   video_related_21
   div.s $f12, $f16, $f4
.Ljp7F087890:
  jal   get_curplayer_viewport_width
   nop   
  jal   get_curplayer_viewport_height
   sh    $v0, 0x1c($sp)
  lh    $a0, 0x1c($sp)
  jal   set_cur_player_screen_size
   move  $a1, $v0
  jal   get_curplayer_viewport_ulx
   nop   
  jal   get_curplayer_viewport_uly
   sh    $v0, 0x1c($sp)
  lh    $a0, 0x1c($sp)
  jal   set_cur_player_viewport_size
   move  $a1, $v0
  jal   getWidth320or440
   nop   
  jal   getHeight330or240
   sh    $v0, 0x1c($sp)
  sll   $a1, $v0, 0x10
  sra   $t0, $a1, 0x10
  move  $a1, $t0
  jal   set_video2_text_clip_size
   lh    $a0, 0x1c($sp)
  jal   getWidth320or440
   nop   
  jal   getHeight330or240
   sh    $v0, 0x1c($sp)
  sll   $a1, $v0, 0x10
  sra   $t1, $a1, 0x10
  move  $a1, $t1
  jal   set_video2_settings_offset_18_1A
   lh    $a0, 0x1c($sp)
  jal   get_curplayer_viewport_width
   nop   
  jal   get_curplayer_viewport_height
   sh    $v0, 0x1c($sp)
  sll   $a1, $v0, 0x10
  sra   $t2, $a1, 0x10
  move  $a1, $t2
  jal   set_video2_width_height
   lh    $a0, 0x1c($sp)
  jal   get_curplayer_viewport_ulx
   nop   
  jal   get_curplayer_viewport_uly
   sh    $v0, 0x1c($sp)
  sll   $a1, $v0, 0x10
  sra   $t3, $a1, 0x10
  move  $a1, $t3
  jal   set_video2_ulx_uly
   lh    $a0, 0x1c($sp)
  jal   sub_GAME_7F0808BC
   nop   
  jal   update_curplayer_fade
   nop   
  jal   cur_player_get_autoaim
   nop   
  jal   set_BONDdata_autoaim_y
   move  $a0, $v0
  jal   cur_player_get_autoaim
   nop   
  jal   set_BONDdata_autoaim_x
   move  $a0, $v0
  jal   cur_player_get_lookahead
   nop   
  jal   set_BONDdata_lookahead_setting
   move  $a0, $v0
  jal   cur_player_get_ammo_onscreen_setting
   nop   
  li    $a0, 1
  jal   set_unset_ammo_on_screen_setting
   move  $a1, $v0
  jal   getPlayerCount
   nop   
  li    $at, 1
  bne   $v0, $at, .Ljp7F0879D4
   nop   
  jal   cur_player_get_sight_onscreen_control
   nop   
  sltu  $a1, $zero, $v0
  bnez  $a1, .Ljp7F0879FC
   nop   
.Ljp7F0879D4:
  jal   getPlayerCount
   nop   
  slti  $v1, $v0, 2
  xori  $a1, $v1, 1
  beqz  $a1, .Ljp7F0879FC
   lui   $t4, %hi(pPlayersPerm) # $t4, 0x8008
  lw    $t4, %lo(pPlayersPerm)($t4)
  lbu   $a1, 0x6b($t4)
  sltu  $t5, $zero, $a1
  move  $a1, $t5
.Ljp7F0879FC:
  jal   set_unset_bitflags
   li    $a0, 1
  lui   $v0, %hi(cameramode) # $v0, 0x8003
  lw    $v0, %lo(cameramode)($v0)
  li    $at, 4
  beqz  $v0, .Ljp7F087A34
   nop   
  bne   $v0, $at, .Ljp7F087A28
   lui   $t6, %hi(D_800364B0) # $t6, 0x8003
  lw    $t6, %lo(D_800364B0)($t6)
  bnez  $t6, .Ljp7F087A34
.Ljp7F087A28:
   li    $at, 10
  bne   $v0, $at, .Ljp7F087A80
   lb    $a0, 0x23($sp)
.Ljp7F087A34:
  jal   get_cur_playernum
   nop   
  bnez  $v0, .Ljp7F087A60
   lui   $t0, %hi(pPlayer) # $t0, 0x8008
  lui   $v0, %hi(mission_timer) # $v0, 0x8008
  addiu $v0, %lo(mission_timer) # addiu $v0, $v0, -0x65a0
  lui   $t8, %hi(clock_timer) # $t8, 0x8005
  lw    $t8, %lo(clock_timer)($t8)
  lw    $t7, ($v0)
  addu  $t9, $t7, $t8
  sw    $t9, ($v0)
.Ljp7F087A60:
  lw    $t0, %lo(pPlayer)($t0)
  lb    $a0, 0x23($sp)
  lb    $a1, 0x27($sp)
  lhu   $a2, 0x2a($sp)
  jal   MoveBond
   lhu   $a3, 0x3b4($t0)
  b     .Ljp7F087A98
   nop   
.Ljp7F087A80:
  lui   $t1, %hi(pPlayer) # $t1, 0x8008
  lw    $t1, %lo(pPlayer)($t1)
  lb    $a1, 0x27($sp)
  lhu   $a2, 0x2a($sp)
  jal   sub_GAME_7F086990
   lhu   $a3, 0x3b4($t1)
.Ljp7F087A98:
  lui   $v0, %hi(watch_time_0) # $v0, 0x8008
  addiu $v0, %lo(watch_time_0) # addiu $v0, $v0, -0x659c
  lui   $at, %hi(jpD_800484D0) # $at, 0x8005
  lwc1  $f8, %lo(jpD_800484D0)($at)
  lwc1  $f18, ($v0)
  lui   $t2, %hi(stop_time_flag) # $t2, 0x8003
  add.s $f6, $f18, $f8
  swc1  $f6, ($v0)
  lw    $t2, %lo(stop_time_flag)($t2)
  beqz  $t2, .Ljp7F087BD8
   nop   
  jal   get_controls_locked_flag
   nop   
  bnez  $v0, .Ljp7F087B8C
   lui   $t4, %hi(pPlayer) # $t4, 0x8008
  lw    $t4, %lo(pPlayer)($t4)
  lhu   $t3, 0x2a($sp)
  li    $t9, 2
  lhu   $t5, 0x3b4($t4)
  lui   $at, %hi(stop_time_flag) # $at, 0x8003
  not   $t6, $t5
  and   $t7, $t3, $t6
  andi  $t8, $t7, 0xf030
  beqz  $t8, .Ljp7F087B8C
   nop   
  jal   check_if_fade_to_black_complete
   sw    $t9, %lo(stop_time_flag)($at)
  beqz  $v0, .Ljp7F087B5C
   lui   $t0, %hi(pPlayer) # $t0, 0x8008
  lw    $t0, %lo(pPlayer)($t0)
  mtc1  $zero, $f0
  move  $a0, $zero
  lwc1  $f10, 0x3dc($t0)
  move  $a1, $zero
  c.eq.s $f0, $f10
  nop   
  bc1f  .Ljp7F087B8C
   nop   
  mfc1  $a3, $f0
  jal   set_rgba_tint
   move  $a2, $zero
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f12
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f14
  jal   fade_to_over_seconds
   nop   
  b     .Ljp7F087B8C
   nop   
.Ljp7F087B5C:
  lui   $v0, %hi(pPlayer) # $v0, 0x8008
  lw    $v0, %lo(pPlayer)($v0)
  mtc1  $zero, $f0
  li    $at, 0x3F800000 # 1.000000
  lwc1  $f16, 0x404($v0)
  c.eq.s $f0, $f16
  nop   
  bc1f  .Ljp7F087B8C
   nop   
  mtc1  $at, $f14
  jal   fade_to_over_seconds
   lwc1  $f12, 0x3e0($v0)
.Ljp7F087B8C:
  lui   $t1, %hi(stop_time_flag) # $t1, 0x8003
  lw    $t1, %lo(stop_time_flag)($t1)
  li    $at, 2
  bne   $t1, $at, .Ljp7F087BD8
   nop   
  jal   check_if_fade_to_black_complete
   nop   
  beqz  $v0, .Ljp7F087BD8
   lui   $t2, %hi(pPlayer) # $t2, 0x8008
  lw    $t2, %lo(pPlayer)($t2)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  lwc1  $f18, 0x3dc($t2)
  c.eq.s $f4, $f18
  nop   
  bc1f  .Ljp7F087BD8
   nop   
  jal   return_to_title_from_level_end
   nop   
.Ljp7F087BD8:
  lui   $t4, %hi(enable_move_after_cinema) # $t4, 0x8003
  lw    $t4, %lo(enable_move_after_cinema)($t4)
  beqz  $t4, .Ljp7F087BF0
   nop   
  jal   sub_GAME_7F07B1A4
   nop   
.Ljp7F087BF0:
  lui   $v0, %hi(pPlayer) # $v0, 0x8008
  lw    $v0, %lo(pPlayer)($v0)
  lw    $t5, 0xd8($v0)
  beqz  $t5, .Ljp7F087C64
   nop   
  lw    $v1, 0x424($v0)
  li    $a0, 1
  bnez  $v1, .Ljp7F087C34
   nop   
  jal   draw_item_in_hand_has_more_ammo
   move  $a1, $zero
  move  $a0, $zero
  jal   draw_item_in_hand_has_more_ammo
   move  $a1, $zero
  lui   $v0, %hi(pPlayer) # $v0, 0x8008
  lw    $v0, %lo(pPlayer)($v0)
  lw    $v1, 0x424($v0)
.Ljp7F087C34:
  beqz  $v1, .Ljp7F087C64
   nop   
  lw    $t3, 0x428($v0)
  lui   $t6, %hi(D_80036510) # $t6, 0x8003
  beqz  $t3, .Ljp7F087C64
   nop   
  lw    $t6, %lo(D_80036510)($t6)
  slti  $at, $t6, 3
  bnez  $at, .Ljp7F087C64
   nop   
  jal   run_title_stage
   nop   
.Ljp7F087C64:
  lui   $t7, %hi(cameramode) # $t7, 0x8003
  lw    $t7, %lo(cameramode)($t7)
  li    $at, 10
  bne   $t7, $at, .Ljp7F087C90
   nop   
  jal   check_if_fade_to_black_complete
   nop   
  beqz  $v0, .Ljp7F087C90
   nop   
  jal   run_title_stage
   nop   
.Ljp7F087C90:
  lui   $t9, %hi(pPlayer) # $t9, 0x8008
  lw    $t9, %lo(pPlayer)($t9)
  lhu   $t8, 0x2a($sp)
  sh    $t8, 0x3b4($t9)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop    
");
#endif

#endif



asm(R"
glabel sub_GAME_7F0875E4
  lui   $a1, %hi(pPlayer)
  lw    $a1, %lo(pPlayer)($a1)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  jal   sub_GAME_7F0BCA34
   addiu $a1, $a1, 0x38
  jal   get_room_data_float1
   nop   
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lwc1  $f4, 0x38($v0)
  mul.s $f6, $f0, $f4
  jal   get_room_data_float1
   swc1  $f6, 0x50($v0)
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lwc1  $f8, 0x3c($v0)
  mul.s $f10, $f0, $f8
  jal   get_room_data_float1
   swc1  $f10, 0x54($v0)
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lwc1  $f16, 0x40($v0)
  mul.s $f18, $f0, $f16
  swc1  $f18, 0x58($v0)
  jal   sub_GAME_7F0BC624
   lw    $a0, 0x18($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");





asm(R"
glabel store_BONDdata_curpos_to_previous
  lui   $v1, %hi(pPlayer)
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $v0, ($v1)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lwc1  $f4, 0x38($v0)
  swc1  $f4, 0x44($v0)
  lw    $v0, ($v1)
  lwc1  $f6, 0x3c($v0)
  swc1  $f6, 0x48($v0)
  lw    $v0, ($v1)
  lwc1  $f8, 0x40($v0)
  jal   get_BONDdata_field_10CC
   swc1  $f8, 0x4c($v0)
  lui   $v1, %hi(pPlayer)
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $a1, ($v1)
  move  $a0, $v0
  jal   sub_GAME_7F0583D8
   addiu $a1, $a1, 0x44
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");





asm(R"
glabel sub_GAME_7F0876C4
  addiu $sp, $sp, -0x148
  sw    $ra, 0x44($sp)
  sw    $s1, 0x3c($sp)
  sw    $s0, 0x38($sp)
  move  $s0, $a1
  move  $s1, $a2
  sw    $s2, 0x40($sp)
  jal   get_cur_players_room
   sw    $a0, 0x148($sp)
  jal   sub_GAME_7F0875E4
   move  $a0, $v0
  jal   sub_GAME_7F0BD6E0
   nop   
  lui   $s2, %hi(pPlayer)
  addiu $s2, %lo(pPlayer) # addiu $s2, $s2, -0x5f50
  lw    $t6, ($s2)
  jal   sub_GAME_7F0BD6E0
   sw    $v0, 0x5c($t6)
  lw    $t7, ($s2)
  jal   sub_GAME_7F0BD6E0
   sw    $v0, 0x60($t7)
  lw    $t8, ($s2)
  jal   sub_GAME_7F0BD6E0
   sw    $v0, 0x64($t8)
  lw    $t9, ($s2)
  li    $a0, 2
  jal   sub_GAME_7F0BD6F8
   sw    $v0, 0x68($t9)
  lw    $t0, 0x148($sp)
  lw    $v1, ($s2)
  sw    $v0, 0x104($sp)
  lwc1  $f4, ($t0)
  lwc1  $f6, 0x38($v1)
  lui   $at, %hi(D_800364CC)
  lwc1  $f0, %lo(D_800364CC)($at)
  sub.s $f8, $f4, $f6
  addiu $a0, $sp, 0xc4
  mul.s $f10, $f8, $f0
  swc1  $f10, 0xac($sp)
  lwc1  $f16, 4($t0)
  lwc1  $f18, 0x3c($v1)
  mfc1  $a1, $f10
  sub.s $f4, $f16, $f18
  mul.s $f6, $f4, $f0
  swc1  $f6, 0xb0($sp)
  lwc1  $f8, 8($t0)
  lwc1  $f16, 0x40($v1)
  mfc1  $a2, $f6
  sub.s $f18, $f8, $f16
  mul.s $f4, $f18, $f0
  swc1  $f4, 0xb4($sp)
  lwc1  $f8, ($s0)
  mfc1  $a3, $f4
  add.s $f16, $f8, $f10
  swc1  $f16, 0xb8($sp)
  lwc1  $f18, 4($s0)
  add.s $f8, $f18, $f6
  swc1  $f8, 0xbc($sp)
  lwc1  $f16, 8($s0)
  add.s $f18, $f16, $f4
  swc1  $f18, 0xc0($sp)
  lwc1  $f8, ($s0)
  swc1  $f8, 0x10($sp)
  lwc1  $f16, 4($s0)
  swc1  $f16, 0x14($sp)
  lwc1  $f18, 8($s0)
  swc1  $f18, 0x18($sp)
  lwc1  $f10, ($s1)
  swc1  $f10, 0x1c($sp)
  lwc1  $f6, 4($s1)
  swc1  $f6, 0x20($sp)
  lwc1  $f4, 8($s1)
  jal   sub_GAME_7F059424
   swc1  $f4, 0x24($sp)
  lwc1  $f8, 0xb4($sp)
  lwc1  $f16, 0xb8($sp)
  lwc1  $f18, 0xbc($sp)
  lwc1  $f10, 0xc0($sp)
  swc1  $f8, 0x10($sp)
  swc1  $f16, 0x14($sp)
  swc1  $f18, 0x18($sp)
  swc1  $f10, 0x1c($sp)
  lwc1  $f6, ($s1)
  addiu $a0, $sp, 0x108
  lw    $a1, 0x104($sp)
  swc1  $f6, 0x20($sp)
  lwc1  $f4, 4($s1)
  lw    $a2, 0xac($sp)
  lw    $a3, 0xb0($sp)
  swc1  $f4, 0x24($sp)
  lwc1  $f8, 8($s1)
  jal   guLookAtReflect
   swc1  $f8, 0x28($sp)
  lw    $v0, 0x148($sp)
  lw    $t1, ($s2)
  lwc1  $f16, ($s0)
  lw    $a1, ($v0)
  lw    $a2, 4($v0)
  lw    $a3, 8($v0)
  lw    $a0, 0x64($t1)
  swc1  $f16, 0x10($sp)
  lwc1  $f18, 4($s0)
  swc1  $f18, 0x14($sp)
  lwc1  $f10, 8($s0)
  swc1  $f10, 0x18($sp)
  lwc1  $f6, ($s1)
  swc1  $f6, 0x1c($sp)
  lwc1  $f4, 4($s1)
  swc1  $f4, 0x20($sp)
  lwc1  $f8, 8($s1)
  jal   sub_GAME_7F059424
   swc1  $f8, 0x24($sp)
  lw    $t3, 0x148($sp)
  lw    $t2, ($s2)
  lwc1  $f16, ($s0)
  lw    $a1, ($t3)
  lw    $a2, 4($t3)
  lw    $a3, 8($t3)
  lw    $a0, 0x68($t2)
  swc1  $f16, 0x10($sp)
  lwc1  $f18, 4($s0)
  swc1  $f18, 0x14($sp)
  lwc1  $f10, 8($s0)
  swc1  $f10, 0x18($sp)
  lwc1  $f6, ($s1)
  swc1  $f6, 0x1c($sp)
  lwc1  $f4, 4($s1)
  swc1  $f4, 0x20($sp)
  lwc1  $f8, 8($s1)
  jal   sub_GAME_7F059708
   swc1  $f8, 0x24($sp)
  jal   sub_GAME_7F0BD6E0
   nop   
  jal   get_BONDdata_field_10DC
   move  $s0, $v0
  addiu $s1, $sp, 0x60
  move  $a2, $s1
  move  $a0, $v0
  jal   sub_GAME_7F0580C8
   addiu $a1, $sp, 0xc4
  li    $at, 0xC6FA0000 # -32000.000000
  mtc1  $at, $f12
  li    $at, 0x46FA0000 # 32000.000000
  mtc1  $at, $f2
  addiu $a1, $sp, 0x60
  addiu $a3, $sp, 0xa0
  li    $a0, 16
  move  $v1, $zero
.L7F087914:
  move  $v0, $a1
.L7F087918:
  lwc1  $f0, ($v0)
  addiu $v1, $v1, 4
  c.lt.s $f2, $f0
  nop   
  bc1fl .L7F08793C
   c.lt.s $f0, $f12
  b     .L7F08794C
   swc1  $f2, ($v0)
  c.lt.s $f0, $f12
.L7F08793C:
  nop   
  bc1f  .L7F08794C
   nop   
  swc1  $f12, ($v0)
.L7F08794C:
  bne   $v1, $a0, .L7F087918
   addiu $v0, $v0, 4
  addiu $a1, $a1, 0x10
  bnel  $a1, $a3, .L7F087914
   move  $v1, $zero
  move  $a0, $s1
  jal   guMtxF2L
   move  $a1, $s0
  jal   set_BONDdata_field_10E0
   move  $a0, $s0
  jal   sub_GAME_7F0B4878
   nop   
  mov.s $f12, $f0
  jal   matrix_multiply_A1_by_F12
   addiu $a1, $sp, 0xc4
  lw    $t4, ($s2)
  addiu $a0, $sp, 0xc4
  jal   guMtxF2L
   lw    $a1, 0x5c($t4)
  lw    $v1, ($s2)
  lw    $a0, 0x5c($v1)
  jal   sub_GAME_7F059334
   lw    $a1, 0x60($v1)
  lw    $t5, ($s2)
  jal   set_BONDdata_field_10C8
   lw    $a0, 0x5c($t5)
  lw    $t6, ($s2)
  jal   set_BONDdata_field_10C4
   lw    $a0, 0x60($t6)
  lw    $t7, ($s2)
  jal   copy_BONDdata_field_10CC_to_10E8_set_10CC
   lw    $a0, 0x64($t7)
  lw    $t8, ($s2)
  jal   sub_GAME_7F078424
   lw    $a0, 0x68($t8)
  jal   sub_GAME_7F078464
   lw    $a0, 0x104($sp)
  jal   sub_GAME_7F0785DC
   nop   
  jal   store_BONDdata_curpos_to_previous
   nop   
  lw    $ra, 0x44($sp)
  lw    $s0, 0x38($sp)
  lw    $s1, 0x3c($sp)
  lw    $s2, 0x40($sp)
  jr    $ra
   addiu $sp, $sp, 0x148
");





asm(R"
.late_rodata
glabel D_8005526C
.word 0x40490fdb /*3.1415927*/
glabel D_80055270
.word 0x40c90fdb /*6.2831855*/
glabel D_80055274
.word 0x40490fdb /*3.1415927*/
glabel D_80055278
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F087A08
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  addiu $sp, $sp, -0x80
  sw    $ra, 0x14($sp)
  sw    $a0, 0x80($sp)
  lw    $t6, ($v0)
  li    $at, 1
  lui   $t7, %hi(D_80036830) 
  bne   $t6, $at, .L7F087A94
   addiu $t7, %lo(D_80036830) # addiu $t7, $t7, 0x6830
  lwc1  $f4, 4($v0)
  swc1  $f4, 0x74($sp)
  lwc1  $f6, 8($v0)
  swc1  $f6, 0x78($sp)
  lwc1  $f8, 0xc($v0)
  swc1  $f8, 0x7c($sp)
  lwc1  $f18, 4($v0)
  lwc1  $f10, 0x10($v0)
  sub.s $f4, $f10, $f18
  swc1  $f4, 0x68($sp)
  lwc1  $f8, 8($v0)
  lwc1  $f6, 0x14($v0)
  sub.s $f10, $f6, $f8
  swc1  $f10, 0x6c($sp)
  lwc1  $f4, 0xc($v0)
  lwc1  $f18, 0x18($v0)
  sub.s $f6, $f18, $f4
  swc1  $f6, 0x70($sp)
  lwc1  $f8, 0x1c($v0)
  swc1  $f8, 0x5c($sp)
  lwc1  $f10, 0x20($v0)
  swc1  $f10, 0x60($sp)
  lwc1  $f18, 0x24($v0)
  b     .L7F087B30
   swc1  $f18, 0x64($sp)
.L7F087A94:
  lw    $at, ($t7)
  addiu $a2, $sp, 0x4c
  addiu $v1, $v0, 0x488
  sw    $at, ($a2)
  lw    $t0, 4($t7)
  addiu $a0, $v1, 0x2c
  addiu $a1, $v1, 0x38
  sw    $t0, 4($a2)
  lw    $at, 8($t7)
  sw    $at, 8($a2)
  lw    $t1, 0xd8($v0)
  bnezl $t1, .L7F087ADC
   mtc1  $zero, $f12
  jal   sub_GAME_7F09C7C4
   sw    $v1, 0x58($sp)
  b     .L7F087AE8
   lw    $v1, 0x58($sp)
  mtc1  $zero, $f12
.L7F087ADC:
  jal   video_related_9
   sw    $v1, 0x58($sp)
  lw    $v1, 0x58($sp)
.L7F087AE8:
  lwc1  $f4, 0x2c($v1)
  swc1  $f4, 0x74($sp)
  lwc1  $f6, 0x30($v1)
  swc1  $f6, 0x78($sp)
  lwc1  $f8, 0x34($v1)
  swc1  $f8, 0x7c($sp)
  lwc1  $f10, 0x38($v1)
  swc1  $f10, 0x68($sp)
  lwc1  $f18, 0x3c($v1)
  swc1  $f18, 0x6c($sp)
  lwc1  $f4, 0x40($v1)
  swc1  $f4, 0x70($sp)
  lwc1  $f6, 0x44($v1)
  swc1  $f6, 0x5c($sp)
  lwc1  $f8, 0x48($v1)
  swc1  $f8, 0x60($sp)
  lwc1  $f10, 0x4c($v1)
  swc1  $f10, 0x64($sp)
.L7F087B30:
  addiu $a0, $sp, 0x74
  addiu $a1, $sp, 0x68
  jal   sub_GAME_7F0876C4
   addiu $a2, $sp, 0x5c
  addiu $a0, $sp, 0x34
  jal   sub_GAME_7F068190
   addiu $a1, $sp, 0x40
  lwc1  $f0, 0x48($sp)
  lwc1  $f2, 0x40($sp)
  lwc1  $f18, 0x44($sp)
  mul.s $f4, $f0, $f0
  swc1  $f18, 0x30($sp)
  mul.s $f6, $f2, $f2
  jal   sqrtf
   add.s $f12, $f4, $f6
  jal   get_curplay_vertical_rotation_in_degrees
   swc1  $f0, 0x2c($sp)
  swc1  $f0, 0x20($sp)
  lwc1  $f12, 0x30($sp)
  jal   convert_angle_using_inverse
   lwc1  $f14, 0x2c($sp)
  lwc1  $f8, 0x20($sp)
  lui   $at, %hi(D_8005526C)
  lwc1  $f10, %lo(D_8005526C)($at)
  add.s $f2, $f0, $f8
  lui   $at, %hi(D_80055270)
  lui   $t2, %hi(pPlayer) 
  c.le.s $f10, $f2
  mov.s $f16, $f2
  bc1f  .L7F087BB4
   nop   
  lwc1  $f18, %lo(D_80055270)($at)
  sub.s $f16, $f2, $f18
.L7F087BB4:
  lw    $t2, %lo(pPlayer)($t2)
  swc1  $f16, 0x2a08($t2)
  lwc1  $f14, 0x48($sp)
  lwc1  $f12, 0x40($sp)
  neg.s $f14, $f14
  jal   convert_angle_using_inverse
   neg.s $f12, $f12
  lui   $at, %hi(D_80055274)
  lwc1  $f4, %lo(D_80055274)($at)
  mov.s $f2, $f0
  lui   $at, %hi(D_80055278)
  c.le.s $f4, $f0
  lui   $t3, %hi(pPlayer) 
  bc1f  .L7F087BF8
   nop   
  lwc1  $f6, %lo(D_80055278)($at)
  sub.s $f2, $f0, $f6
.L7F087BF8:
  lw    $t3, %lo(pPlayer)($t3)
  swc1  $f2, 0x2a0c($t3)
  lw    $ra, 0x14($sp)
  lw    $v0, 0x80($sp)
  addiu $sp, $sp, 0x80
  jr    $ra
   nop   
");





asm(R"
glabel seems_to_load_cuff_microcode
  addiu $sp, $sp, -0x48
  sw    $ra, 0x14($sp)
  sw    $a0, 0x48($sp)
  sw    $a1, 0x4c($sp)
  jal   getSelectedFolderBond
   sw    $a2, 0x50($sp)
  lw    $t6, 0x4c($sp)
  lw    $v1, 0x50($sp)
  sw    $v0, 0x40($sp)
  lw    $a2, 8($t6)
  sll   $a3, $v1, 2
  addu  $a0, $a2, $a3
  lw    $a1, ($a0)
  beql  $a1, $zero, .L7F087C8C
   lw    $t1, 4($a0)
  lw    $a0, 0x48($sp)
  jal   extract_id_from_object_structure_microcode
   sw    $a3, 0x1c($sp)
  lui   $t7, %hi(pPlayer) 
  lw    $t7, %lo(pPlayer)($t7)
  lw    $a3, 0x1c($sp)
  lw    $t8, 0x41c($t7)
  xori  $t9, $t8, 3
  sltiu $t9, $t9, 1
  sw    $t9, ($v0)
  lw    $t0, 0x4c($sp)
  lw    $v1, 0x50($sp)
  lw    $a2, 8($t0)
  addu  $a0, $a2, $a3
  lw    $t1, 4($a0)
.L7F087C8C:
  addiu $v0, $v1, 1
  sll   $t2, $v0, 2
  beqz  $t1, .L7F087D1C
   addu  $t3, $a2, $t2
  lw    $a1, ($t3)
  sw    $a3, 0x1c($sp)
  jal   extract_id_from_object_structure_microcode
   lw    $a0, 0x48($sp)
  lui   $t4, %hi(pPlayer) 
  lw    $t4, %lo(pPlayer)($t4)
  lw    $a3, 0x1c($sp)
  lw    $a0, 0x41c($t4)
  xori  $v1, $a0, 1
  sltiu $v1, $v1, 1
  bnezl $v1, .L7F087D0C
   sw    $v1, ($v0)
  xori  $v1, $a0, 6
  sltiu $v1, $v1, 1
  bnezl $v1, .L7F087D0C
   sw    $v1, ($v0)
  xori  $v1, $a0, 7
  sltiu $v1, $v1, 1
  bnezl $v1, .L7F087D0C
   sw    $v1, ($v0)
  xori  $v1, $a0, 8
  sltiu $v1, $v1, 1
  beql  $v1, $zero, .L7F087D0C
   sw    $v1, ($v0)
  lw    $v1, 0x40($sp)
  xori  $t5, $v1, 1
  sltu  $v1, $zero, $t5
  sw    $v1, ($v0)
.L7F087D0C:
  lw    $t6, 0x4c($sp)
  lw    $v1, 0x50($sp)
  lw    $a2, 8($t6)
  addu  $a0, $a2, $a3
.L7F087D1C:
  lw    $t7, 8($a0)
  addiu $v0, $v1, 2
  sll   $t8, $v0, 2
  beqz  $t7, .L7F087D90
   addu  $t9, $a2, $t8
  lw    $a1, ($t9)
  sw    $a3, 0x1c($sp)
  jal   extract_id_from_object_structure_microcode
   lw    $a0, 0x48($sp)
  lui   $t0, %hi(pPlayer) 
  lw    $t0, %lo(pPlayer)($t0)
  lw    $a3, 0x1c($sp)
  lw    $a0, 0x41c($t0)
  xori  $v1, $a0, 5
  sltiu $v1, $v1, 1
  bnezl $v1, .L7F087D80
   sw    $v1, ($v0)
  xori  $v1, $a0, 8
  sltiu $v1, $v1, 1
  beql  $v1, $zero, .L7F087D80
   sw    $v1, ($v0)
  lw    $v1, 0x40($sp)
  xori  $t1, $v1, 1
  sltiu $v1, $t1, 1
  sw    $v1, ($v0)
.L7F087D80:
  lw    $t2, 0x4c($sp)
  lw    $v1, 0x50($sp)
  lw    $a2, 8($t2)
  addu  $a0, $a2, $a3
.L7F087D90:
  lw    $t3, 0xc($a0)
  addiu $v0, $v1, 3
  sll   $t4, $v0, 2
  beqz  $t3, .L7F087DDC
   addu  $t5, $a2, $t4
  lw    $a1, ($t5)
  sw    $a3, 0x1c($sp)
  jal   extract_id_from_object_structure_microcode
   lw    $a0, 0x48($sp)
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  lw    $a3, 0x1c($sp)
  lw    $t7, 0x41c($t6)
  sltiu $t8, $t7, 1
  sw    $t8, ($v0)
  lw    $t9, 0x4c($sp)
  lw    $v1, 0x50($sp)
  lw    $a2, 8($t9)
  addu  $a0, $a2, $a3
.L7F087DDC:
  lw    $t0, 0x10($a0)
  addiu $v0, $v1, 4
  sll   $t1, $v0, 2
  beqz  $t0, .L7F087E2C
   addu  $t2, $a2, $t1
  lw    $a1, ($t2)
  sw    $a3, 0x1c($sp)
  jal   extract_id_from_object_structure_microcode
   lw    $a0, 0x48($sp)
  lui   $t3, %hi(pPlayer) 
  lw    $t3, %lo(pPlayer)($t3)
  lw    $a3, 0x1c($sp)
  lw    $t4, 0x41c($t3)
  xori  $t5, $t4, 2
  sltiu $t5, $t5, 1
  sw    $t5, ($v0)
  lw    $t6, 0x4c($sp)
  lw    $v1, 0x50($sp)
  lw    $a2, 8($t6)
  addu  $a0, $a2, $a3
.L7F087E2C:
  lw    $t7, 0x14($a0)
  addiu $v0, $v1, 5
  sll   $t8, $v0, 2
  beqz  $t7, .L7F087E64
   lw    $a0, 0x48($sp)
  addu  $t9, $a2, $t8
  jal   extract_id_from_object_structure_microcode
   lw    $a1, ($t9)
  lui   $t0, %hi(pPlayer) 
  lw    $t0, %lo(pPlayer)($t0)
  lw    $t1, 0x41c($t0)
  xori  $t2, $t1, 4
  sltiu $t2, $t2, 1
  sw    $t2, ($v0)
.L7F087E64:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x48
  jr    $ra
   nop   
");

#ifdef VERSION_US
asm(R"
.late_rodata
glabel D_8005527C
.word 0x3c8efa35 /*0.017453292*/
glabel D_80055280
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F087E74
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  addiu $sp, $sp, -0x1f8
  sw    $ra, 0x2c($sp)
  sw    $a0, 0x1f8($sp)
  lw    $t6, 0x1c8($v0)
  beql  $t6, $zero, .L7F088608
   lw    $ra, 0x2c($sp)
  lw    $t7, 0x200($v0)
  lui   $t9, %hi(D_8003683C) 
  addiu $t9, %lo(D_8003683C) # addiu $t9, $t9, 0x683c
  beqz  $t7, .L7F088604
   addiu $t8, $sp, 0x1b8
  addiu $t3, $t9, 0x3c
.L7F087EAC:
  lw    $at, ($t9)
  addiu $t9, $t9, 0xc
  addiu $t8, $t8, 0xc
  sw    $at, -0xc($t8)
  lw    $at, -8($t9)
  sw    $at, -8($t8)
  lw    $at, -4($t9)
  bne   $t9, $t3, .L7F087EAC
   sw    $at, -4($t8)
  lw    $at, ($t9)
  lui   $t5, %hi(D_8003687C) 
  addiu $t5, %lo(D_8003687C) # addiu $t5, $t5, 0x687c
  sw    $at, ($t8)
  lw    $at, ($t5)
  addiu $t4, $sp, 0x16c
  lw    $t7, 4($t5)
  sw    $at, ($t4)
  lw    $at, 8($t5)
  li    $a0, 1
  sw    $t7, 4($t4)
  jal   get_ptr_itemheader_in_hand
   sw    $at, 8($t4)
  sw    $v0, 0x160($sp)
  lui   $a0, %hi(pPlayer)
  lw    $t2, 8($v0)
  lw    $a0, %lo(pPlayer)($a0)
  lw    $a1, 0xc($t2)
  jal   extract_id_from_object_structure_microcode
   addiu $a0, $a0, 0x230
  jal   sub_GAME_7F0BD6E0
   sw    $v0, 0x158($sp)
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f4
  lui   $t3, %hi(pPlayer) 
  lw    $t3, %lo(pPlayer)($t3)
  li    $at, 0x43960000 # 300.000000
  mtc1  $at, $f6
  sw    $v0, 0x154($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  lw    $a2, 0x11c4($t3)
  lui   $a3, (0x3FBA2E8C >> 16) # lui $a3, 0x3fba
  ori   $a3, (0x3FBA2E8C & 0xFFFF) # ori $a3, $a3, 0x2e8c
  move  $a0, $v0
  addiu $a1, $sp, 0x152
  swc1  $f4, 0x10($sp)
  swc1  $f6, 0x14($sp)
  jal   guPerspective
   swc1  $f8, 0x18($sp)
  lw    $v1, 0x1f8($sp)
  lui   $t9, (0x01030040 >> 16) # lui $t9, 0x103
  ori   $t9, (0x01030040 & 0xFFFF) # ori $t9, $t9, 0x40
  sw    $t9, ($v1)
  lw    $t8, 0x154($sp)
  li    $at, 0xC1400000 # -12.000000
  mtc1  $at, $f0
  lui   $at, 0x8000
  lui   $t4, (0xBC00000E >> 16) # lui $t4, 0xbc00
  addu  $t6, $t8, $at
  ori   $t4, (0xBC00000E & 0xFFFF) # ori $t4, $t4, 0xe
  sw    $t6, 4($v1)
  addiu $a3, $v1, 8
  sw    $t4, ($a3)
  lhu   $t5, 0x152($sp)
  lui   $t0, %hi(pPlayer) 
  addiu $t0, %lo(pPlayer) # addiu $t0, $t0, -0x5f50
  sw    $t5, 4($a3)
  lw    $t7, ($t0)
  lw    $t3, 0x158($sp)
  li    $at, 0x43B40000 # 360.000000
  lw    $t2, 0x1cc($t7)
  addiu $t1, $a3, 8
  addiu $a0, $sp, 0x16c
  sw    $t2, ($t3)
  lw    $v0, ($t0)
  addiu $a2, $sp, 0x178
  lwc1  $f4, 0x54c($v0)
  lwc1  $f10, 0x498($v0)
  add.s $f6, $f4, $f0
  lwc1  $f4, 0x544($v0)
  mul.s $f8, $f10, $f6
  lwc1  $f10, 0x4a0($v0)
  neg.s $f6, $f10
  mul.s $f10, $f4, $f6
  lwc1  $f4, 0x48c($v0)
  add.s $f6, $f4, $f10
  add.s $f4, $f8, $f6
  swc1  $f4, 0x16c($sp)
  lwc1  $f8, 0x490($v0)
  lwc1  $f10, 0x548($v0)
  add.s $f6, $f10, $f8
  swc1  $f6, 0x170($sp)
  lwc1  $f10, 0x54c($v0)
  lwc1  $f4, 0x4a0($v0)
  add.s $f8, $f10, $f0
  lwc1  $f10, 0x544($v0)
  mul.s $f6, $f4, $f8
  lwc1  $f4, 0x498($v0)
  mul.s $f8, $f10, $f4
  lwc1  $f10, 0x494($v0)
  add.s $f4, $f10, $f8
  mtc1  $at, $f8
  lui   $at, %hi(D_8005527C)
  add.s $f10, $f6, $f4
  swc1  $f10, 0x174($sp)
  lwc1  $f6, 0x148($v0)
  lwc1  $f10, %lo(D_8005527C)($at)
  sw    $t1, 0x1f8($sp)
  sub.s $f4, $f8, $f6
  mul.s $f8, $f4, $f10
  mfc1  $a1, $f8
  jal   sub_GAME_7F0584D0
   nop   
  jal   get_BONDdata_field_10CC
   nop   
  move  $a0, $v0
  jal   matrix_4x4_multiply_homogeneous_in_place
   addiu $a1, $sp, 0x178
  lw    $t9, 0x160($sp)
  lh    $a0, 0xe($t9)
  sll   $t8, $a0, 6
  jal   sub_GAME_7F0BD714
   move  $a0, $t8
  lui   $a0, %hi(pPlayer)
  lw    $a0, %lo(pPlayer)($a0)
  sw    $v0, 0x164($sp)
  lw    $a1, 0x160($sp)
  li    $a2, 4
  jal   seems_to_load_cuff_microcode
   addiu $a0, $a0, 0x230
  lui   $a1, %hi(pPlayer)
  lw    $t4, 0x164($sp)
  lw    $a1, %lo(pPlayer)($a1)
  addiu $t6, $sp, 0x178
  sw    $t6, 0x1b8($sp)
  addiu $a0, $sp, 0x1b8
  sw    $t4, 0x1c8($sp)
  jal   subcalcmatrices
   addiu $a1, $a1, 0x230
  lw    $t5, 0x160($sp)
  lui   $t3, %hi(watch_time_0) 
  lw    $t3, %lo(watch_time_0)($t3)
  lw    $t7, 8($t5)
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lw    $t2, ($t7)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f0
  lw    $v1, 4($t2)
  li    $at, 0x41A00000 # 20.000000
  sw    $t3, 0x90($sp)
  mtc1  $at, $f4
  lwc1  $f6, 0x258($v0)
  div.s $f14, $f6, $f4
  c.lt.s $f0, $f14
  nop   
  bc1fl .L7F08812C
   lwc1  $f10, ($v1)
  mov.s $f14, $f0
  lwc1  $f10, ($v1)
.L7F08812C:
  lwc1  $f8, 0x244($v0)
  lwc1  $f4, 0x1d4($v0)
  lw    $t0, 0x164($sp)
  mul.s $f6, $f10, $f8
  mtc1  $zero, $f16
  lwc1  $f0, 0x30($t0)
  addiu $a0, $sp, 0x108
  mfc1  $a1, $f16
  mfc1  $a2, $f16
  mfc1  $a3, $f16
  sub.s $f10, $f4, $f6
  sub.s $f8, $f10, $f0
  mul.s $f4, $f8, $f14
  add.s $f6, $f4, $f0
  swc1  $f6, 0xb4($sp)
  lwc1  $f8, 0x244($v0)
  lwc1  $f10, 8($v1)
  lwc1  $f6, 0x1d8($v0)
  lwc1  $f2, 0x34($t0)
  mul.s $f4, $f10, $f8
  add.s $f10, $f6, $f4
  sub.s $f8, $f10, $f2
  mul.s $f6, $f8, $f14
  add.s $f4, $f6, $f2
  swc1  $f4, 0xb8($sp)
  lwc1  $f8, 0x244($v0)
  lwc1  $f10, 4($v1)
  lwc1  $f4, 0x1dc($v0)
  lwc1  $f12, 0x38($t0)
  mul.s $f6, $f10, $f8
  sub.s $f10, $f4, $f6
  sub.s $f8, $f10, $f12
  mul.s $f4, $f8, $f14
  add.s $f6, $f4, $f12
  swc1  $f6, 0xbc($sp)
  lwc1  $f10, 0x1e0($v0)
  swc1  $f10, 0x10($sp)
  lwc1  $f8, 0x1e4($v0)
  swc1  $f8, 0x14($sp)
  lwc1  $f4, 0x1e8($v0)
  swc1  $f4, 0x18($sp)
  lwc1  $f6, 0x1ec($v0)
  swc1  $f6, 0x1c($sp)
  lwc1  $f10, 0x1f0($v0)
  swc1  $f10, 0x20($sp)
  lwc1  $f8, 0x1f4($v0)
  swc1  $f14, 0x168($sp)
  jal   sub_GAME_7F059908
   swc1  $f8, 0x24($sp)
  lw    $a0, 0x164($sp)
  jal   sub_GAME_7F058860
   addiu $a1, $sp, 0xfc
  addiu $a0, $sp, 0x108
  jal   sub_GAME_7F058860
   addiu $a1, $sp, 0xf0
  addiu $a0, $sp, 0xfc
  jal   sub_GAME_7F05B3F4
   addiu $a1, $sp, 0xe0
  addiu $a0, $sp, 0xf0
  jal   sub_GAME_7F05B3F4
   addiu $a1, $sp, 0xd0
  addiu $a0, $sp, 0xe0
  jal   sub_GAME_7F05BE10
   addiu $a1, $sp, 0xd0
  addiu $a0, $sp, 0xe0
  addiu $a1, $sp, 0xd0
  lw    $a2, 0x168($sp)
  jal   sub_GAME_7F05BA08
   addiu $a3, $sp, 0xc0
  addiu $a0, $sp, 0xc0
  jal   sub_GAME_7F05B628
   lw    $a1, 0x164($sp)
  addiu $a0, $sp, 0xb4
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   lw    $a1, 0x164($sp)
  lui   $t9, %hi(pPlayer) 
  lw    $t9, %lo(pPlayer)($t9)
  lw    $a1, 0x164($sp)
  jal   matrix_multiply_A1_by_F12
   lwc1  $f12, 0x244($t9)
  li    $v1, 60
  lw    $a0, 0x90($sp)
  lui   $at, %hi(D_80055280)
  lwc1  $f2, %lo(D_80055280)($at)
  div   $zero, $a0, $v1
  mfhi  $t8
  mflo  $v0
  mtc1  $t8, $f4
  mtc1  $zero, $f16
  div   $zero, $v0, $v1
  mfhi  $t6
  mflo  $t4
  cvt.s.w $f6, $f4
  bnez  $v1, .L7F0882AC
   nop   
  break 7
.L7F0882AC:
  li    $at, -1
  bne   $v1, $at, .L7F0882C4
   lui   $at, 0x8000
  bne   $a0, $at, .L7F0882C4
   nop   
  break 6
.L7F0882C4:
  div   $zero, $t4, $v1
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f10
  mtc1  $t6, $f4
  mfhi  $t5
  div.s $f8, $f6, $f10
  bnez  $v1, .L7F0882E8
   nop   
  break 7
.L7F0882E8:
  li    $at, -1
  bne   $v1, $at, .L7F088300
   li    $at, 0x80000000 # -0.000000
  bne   $v0, $at, .L7F088300
   nop   
  break 6
.L7F088300:
  li    $at, 0x42700000 # 60.000000
  lw    $t3, 0x160($sp)
  cvt.s.w $f6, $f4
  add.s $f10, $f6, $f8
  mtc1  $at, $f8
  neg.s $f4, $f10
  mtc1  $t5, $f10
  mul.s $f6, $f4, $f2
  cvt.s.w $f4, $f10
  div.s $f18, $f6, $f8
  neg.s $f6, $f4
  mul.s $f8, $f6, $f2
  c.lt.s $f18, $f16
  mov.s $f12, $f18
  bnez  $v1, .L7F088344
   nop   
  break 7
.L7F088344:
  li    $at, -1
  bne   $v1, $at, .L7F08835C
   li    $at, 0x80000000 # -0.000000
  bne   $t4, $at, .L7F08835C
   nop   
  break 6
.L7F08835C:
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f10
  mtc1  $at, $f6
  li    $at, 3600
  div   $zero, $v0, $at
  mflo  $t7
  li    $at, 12
  div.s $f4, $f8, $f10
  div   $zero, $t7, $at
  div.s $f8, $f18, $f6
  mfhi  $t2
  mtc1  $t2, $f6
  li    $at, 0x41400000 # 12.000000
  add.s $f10, $f4, $f8
  cvt.s.w $f4, $f6
  swc1  $f10, 0x40($sp)
  mov.s $f14, $f10
  neg.s $f8, $f4
  mtc1  $at, $f4
  mul.s $f6, $f8, $f2
  div.s $f8, $f6, $f4
  mtc1  $at, $f6
  li    $at, 0x44340000 # 720.000000
  div.s $f4, $f10, $f6
  mtc1  $at, $f6
  add.s $f10, $f8, $f4
  div.s $f8, $f18, $f6
  lwc1  $f6, 0x40($sp)
  add.s $f4, $f10, $f8
  swc1  $f4, 0x3c($sp)
  mov.s $f0, $f4
  bc1f  .L7F0883F4
   lwc1  $f10, 0x3c($sp)
  add.s $f12, $f12, $f2
.L7F0883E4:
  c.lt.s $f12, $f16
  nop   
  bc1tl .L7F0883E4
   add.s $f12, $f12, $f2
.L7F0883F4:
  c.lt.s $f6, $f16
  nop   
  bc1fl .L7F08841C
   c.lt.s $f10, $f16
  add.s $f14, $f14, $f2
.L7F088408:
  c.lt.s $f14, $f16
  nop   
  bc1tl .L7F088408
   add.s $f14, $f14, $f2
  c.lt.s $f10, $f16
.L7F08841C:
  nop   
  bc1fl .L7F088440
   lw    $t9, 8($t3)
  add.s $f0, $f0, $f2
.L7F08842C:
  c.lt.s $f0, $f16
  nop   
  bc1tl .L7F08842C
   add.s $f0, $f0, $f2
  lw    $t9, 8($t3)
.L7F088440:
  lw    $a2, 0x164($sp)
  mfc1  $a1, $f0
  lw    $t8, ($t9)
  addiu $a2, $a2, 0x40
  lw    $a0, 4($t8)
  swc1  $f14, 0x98($sp)
  swc1  $f12, 0x9c($sp)
  jal   sub_GAME_7F0584D0
   sw    $a2, 0x40($sp)
  lw    $a1, 0x40($sp)
  jal   matrix_4x4_multiply_in_place
   lw    $a0, 0x164($sp)
  lw    $t6, 0x160($sp)
  lwc1  $f14, 0x98($sp)
  lw    $a2, 0x164($sp)
  lw    $t4, 8($t6)
  mfc1  $a1, $f14
  addiu $a2, $a2, 0x80
  lw    $t5, 4($t4)
  lw    $a0, 4($t5)
  jal   sub_GAME_7F0584D0
   sw    $a2, 0x40($sp)
  lw    $a1, 0x40($sp)
  jal   matrix_4x4_multiply_in_place
   lw    $a0, 0x164($sp)
  lw    $t7, 0x160($sp)
  lwc1  $f12, 0x9c($sp)
  lw    $a2, 0x164($sp)
  lw    $t2, 8($t7)
  mfc1  $a1, $f12
  addiu $a2, $a2, 0xc0
  lw    $t3, 8($t2)
  lw    $a0, 4($t3)
  jal   sub_GAME_7F0584D0
   sw    $a2, 0x40($sp)
  lw    $a1, 0x40($sp)
  jal   matrix_4x4_multiply_in_place
   lw    $a0, 0x164($sp)
  lw    $t8, 0x1f8($sp)
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  li    $t9, 3
  li    $t6, 4
  sw    $t9, 0x1c0($sp)
  sw    $zero, 0x1bc($sp)
  sw    $t6, 0x1e8($sp)
  sw    $t8, 0x1c4($sp)
  lw    $v1, 0x1c8($v0)
  li    $at, 5
  addiu $a0, $sp, 0x1b8
  beq   $v1, $at, .L7F088514
   li    $at, 12
  bne   $v1, $at, .L7F088520
.L7F088514:
   li    $t4, 205
  b     .L7F08854C
   sw    $t4, 0x1ec($sp)
.L7F088520:
  lbu   $t7, 0xfdc($v0)
  lbu   $t5, 0xfdf($v0)
  lbu   $t9, 0xfdd($v0)
  lbu   $t4, 0xfde($v0)
  sll   $t2, $t7, 0x18
  or    $t3, $t5, $t2
  sll   $t8, $t9, 0x10
  or    $t6, $t3, $t8
  sll   $t7, $t4, 8
  or    $t5, $t6, $t7
  sw    $t5, 0x1ec($sp)
.L7F08854C:
  jal   subdraw
   addiu $a1, $v0, 0x230
  lw    $t2, 0x1c4($sp)
  lw    $t9, 0x160($sp)
  sw    $t2, 0x1f8($sp)
  lw    $t3, 8($t9)
  lw    $t8, 8($t3)
  lw    $t4, 4($t8)
  jal   sub_GAME_7F0BD6E0
   sw    $t4, 0x8c($sp)
  sw    $v0, 0x48($sp)
  lw    $a0, 0x8c($sp)
  jal   init_something_copy_posdata_to_it
   addiu $a1, $sp, 0x4c
  lw    $a0, 0x164($sp)
  jal   matrix_4x4_multiply_in_place
   addiu $a1, $sp, 0x4c
  jal   sub_GAME_7F058C64
   nop   
  addiu $a0, $sp, 0x4c
  jal   sub_GAME_7F058C9C
   lw    $a1, 0x48($sp)
  jal   sub_GAME_7F058C88
   nop   
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  lw    $a0, 0x1f8($sp)
  lw    $v1, 0x1c8($t6)
  xori  $a2, $v1, 5
  sltiu $a2, $a2, 1
  bnez  $a2, .L7F0885D4
   nop   
  xori  $a2, $v1, 0xc
  sltiu $a2, $a2, 1
.L7F0885D4:
  jal   sub_GAME_7F0ACA28
   lw    $a1, 0x48($sp)
  jal   sub_GAME_7F058C64
   sw    $v0, 0x1f8($sp)
  lui   $t7, %hi(pPlayer) 
  lw    $t7, %lo(pPlayer)($t7)
  lw    $t5, 0x160($sp)
  lw    $a0, 0x23c($t7)
  jal   sub_GAME_7F08BD48
   lh    $a1, 0xe($t5)
  jal   sub_GAME_7F058C88
   nop   
.L7F088604:
  lw    $ra, 0x2c($sp)
.L7F088608:
  lw    $v0, 0x1f8($sp)
  addiu $sp, $sp, 0x1f8
  jr    $ra
   nop   
");

#ifdef VERSION_JP
asm(R"
.late_rodata
glabel D_8005527C
.word 0x3c8efa35 /*0.017453292*/
glabel D_80055280
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F087E74
  lui   $v0, %hi(pPlayer) # $v0, 0x8008
  lw    $v0, %lo(pPlayer)($v0)
  addiu $sp, $sp, -0x1f8
  sw    $ra, 0x2c($sp)
  sw    $a0, 0x1f8($sp)
  lw    $t6, 0x1c8($v0)
  beql  $t6, $zero, .Ljp7F088CDC
   lw    $ra, 0x2c($sp)
  lw    $t7, 0x200($v0)
  lui   $t9, %hi(D_8003683C) # $t9, 0x8003
  addiu $t9, %lo(D_8003683C) # addiu $t9, $t9, 0x687c
  beqz  $t7, .Ljp7F088CD8
   addiu $t8, $sp, 0x1b8
  addiu $t3, $t9, 0x3c
.Ljp7F088578:
  lw    $at, ($t9)
  addiu $t9, $t9, 0xc
  addiu $t8, $t8, 0xc
  sw    $at, -0xc($t8)
  lw    $at, -8($t9)
  sw    $at, -8($t8)
  lw    $at, -4($t9)
  bne   $t9, $t3, .Ljp7F088578
   sw    $at, -4($t8)
  lw    $at, ($t9)
  lui   $t5, %hi(D_8003687C) # $t5, 0x8003
  addiu $t5, %lo(D_8003687C) # addiu $t5, $t5, 0x68bc
  sw    $at, ($t8)
  lw    $at, ($t5)
  addiu $t4, $sp, 0x16c
  lw    $t7, 4($t5)
  sw    $at, ($t4)
  lw    $at, 8($t5)
  li    $a0, 1
  sw    $t7, 4($t4)
  jal   get_ptr_itemheader_in_hand
   sw    $at, 8($t4)
  sw    $v0, 0x160($sp)
  lui   $a0, %hi(pPlayer) # $a0, 0x8008
  lw    $t2, 8($v0)
  lw    $a0, %lo(pPlayer)($a0)
  lw    $a1, 0xc($t2)
  jal   extract_id_from_object_structure_microcode
   addiu $a0, $a0, 0x230
  jal   sub_GAME_7F0BD6E0
   sw    $v0, 0x158($sp)
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f4
  lui   $t3, %hi(pPlayer) # $t3, 0x8008
  lw    $t3, %lo(pPlayer)($t3)
  li    $at, 0x43960000 # 300.000000
  mtc1  $at, $f6
  sw    $v0, 0x154($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  lw    $a2, 0x11c4($t3)
  lui   $a3, (0x3FBA2E8C >> 16) # lui $a3, 0x3fba
  ori   $a3, (0x3FBA2E8C & 0xFFFF) # ori $a3, $a3, 0x2e8c
  move  $a0, $v0
  addiu $a1, $sp, 0x152
  swc1  $f4, 0x10($sp)
  swc1  $f6, 0x14($sp)
  jal   guPerspective
   swc1  $f8, 0x18($sp)
  lw    $v1, 0x1f8($sp)
  lui   $t9, (0x01030040 >> 16) # lui $t9, 0x103
  ori   $t9, (0x01030040 & 0xFFFF) # ori $t9, $t9, 0x40
  sw    $t9, ($v1)
  lw    $t8, 0x154($sp)
  li    $at, 0xC1400000 # -12.000000
  mtc1  $at, $f0
  lui   $at, 0x8000
  lui   $t4, (0xBC00000E >> 16) # lui $t4, 0xbc00
  addu  $t6, $t8, $at
  ori   $t4, (0xBC00000E & 0xFFFF) # ori $t4, $t4, 0xe
  sw    $t6, 4($v1)
  addiu $a3, $v1, 8
  sw    $t4, ($a3)
  lhu   $t5, 0x152($sp)
  lui   $t0, %hi(pPlayer) # $t0, 0x8008
  addiu $t0, %lo(pPlayer) # addiu $t0, $t0, -0x5ee0
  sw    $t5, 4($a3)
  lw    $t7, ($t0)
  lw    $t3, 0x158($sp)
  li    $at, 0x43B40000 # 360.000000
  lw    $t2, 0x1cc($t7)
  addiu $t1, $a3, 8
  addiu $a0, $sp, 0x16c
  sw    $t2, ($t3)
  lw    $v0, ($t0)
  addiu $a2, $sp, 0x178
  lwc1  $f4, 0x54c($v0)
  lwc1  $f10, 0x498($v0)
  add.s $f6, $f4, $f0
  lwc1  $f4, 0x544($v0)
  mul.s $f8, $f10, $f6
  lwc1  $f10, 0x4a0($v0)
  neg.s $f6, $f10
  mul.s $f10, $f4, $f6
  lwc1  $f4, 0x48c($v0)
  add.s $f6, $f4, $f10
  add.s $f4, $f8, $f6
  swc1  $f4, 0x16c($sp)
  lwc1  $f8, 0x490($v0)
  lwc1  $f10, 0x548($v0)
  add.s $f6, $f10, $f8
  swc1  $f6, 0x170($sp)
  lwc1  $f10, 0x54c($v0)
  lwc1  $f4, 0x4a0($v0)
  add.s $f8, $f10, $f0
  lwc1  $f10, 0x544($v0)
  mul.s $f6, $f4, $f8
  lwc1  $f4, 0x498($v0)
  mul.s $f8, $f10, $f4
  lwc1  $f10, 0x494($v0)
  add.s $f4, $f10, $f8
  mtc1  $at, $f8
  lui   $at, %hi(D_8005527C) # $at, 0x8005
  add.s $f10, $f6, $f4
  swc1  $f10, 0x174($sp)
  lwc1  $f6, 0x148($v0)
  lwc1  $f10, %lo(D_8005527C)($at)
  sw    $t1, 0x1f8($sp)
  sub.s $f4, $f8, $f6
  mul.s $f8, $f4, $f10
  mfc1  $a1, $f8
  jal   sub_GAME_7F0584D0
   nop   
  jal   get_BONDdata_field_10CC
   nop   
  move  $a0, $v0
  jal   matrix_4x4_multiply_homogeneous_in_place
   addiu $a1, $sp, 0x178
  lw    $t9, 0x160($sp)
  lh    $a0, 0xe($t9)
  sll   $t8, $a0, 6
  jal   sub_GAME_7F0BD714
   move  $a0, $t8
  lui   $a0, %hi(pPlayer) # $a0, 0x8008
  lw    $a0, %lo(pPlayer)($a0)
  sw    $v0, 0x164($sp)
  lw    $a1, 0x160($sp)
  li    $a2, 4
  jal   seems_to_load_cuff_microcode
   addiu $a0, $a0, 0x230
  lui   $a1, %hi(pPlayer) # $a1, 0x8008
  lw    $t4, 0x164($sp)
  lw    $a1, %lo(pPlayer)($a1)
  addiu $t6, $sp, 0x178
  sw    $t6, 0x1b8($sp)
  addiu $a0, $sp, 0x1b8
  sw    $t4, 0x1c8($sp)
  jal   subcalcmatrices
   addiu $a1, $a1, 0x230
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f0
  lui   $at, %hi(watch_time_0) # $at, 0x8008
  lw    $t5, 0x160($sp)
  lwc1  $f6, %lo(watch_time_0)($at)
  lui   $v0, %hi(pPlayer) # $v0, 0x8008
  lw    $t7, 8($t5)
  trunc.w.s $f4, $f6
  lw    $v0, %lo(pPlayer)($v0)
  lw    $t2, ($t7)
  li    $at, 0x41A00000 # 20.000000
  mfc1  $t9, $f4
  lw    $v1, 4($t2)
  mtc1  $at, $f8
  sw    $t9, 0x90($sp)
  lwc1  $f10, 0x258($v0)
  div.s $f14, $f10, $f8
  c.lt.s $f0, $f14
  nop   
  bc1fl .Ljp7F088800
   lwc1  $f6, ($v1)
  mov.s $f14, $f0
  lwc1  $f6, ($v1)
.Ljp7F088800:
  lwc1  $f4, 0x244($v0)
  lwc1  $f8, 0x1d4($v0)
  lw    $t0, 0x164($sp)
  mul.s $f10, $f6, $f4
  mtc1  $zero, $f16
  lwc1  $f0, 0x30($t0)
  addiu $a0, $sp, 0x108
  mfc1  $a1, $f16
  mfc1  $a2, $f16
  mfc1  $a3, $f16
  sub.s $f6, $f8, $f10
  sub.s $f4, $f6, $f0
  mul.s $f8, $f4, $f14
  add.s $f10, $f8, $f0
  swc1  $f10, 0xb4($sp)
  lwc1  $f4, 0x244($v0)
  lwc1  $f6, 8($v1)
  lwc1  $f10, 0x1d8($v0)
  lwc1  $f2, 0x34($t0)
  mul.s $f8, $f6, $f4
  add.s $f6, $f10, $f8
  sub.s $f4, $f6, $f2
  mul.s $f10, $f4, $f14
  add.s $f8, $f10, $f2
  swc1  $f8, 0xb8($sp)
  lwc1  $f4, 0x244($v0)
  lwc1  $f6, 4($v1)
  lwc1  $f8, 0x1dc($v0)
  lwc1  $f12, 0x38($t0)
  mul.s $f10, $f6, $f4
  sub.s $f6, $f8, $f10
  sub.s $f4, $f6, $f12
  mul.s $f8, $f4, $f14
  add.s $f10, $f8, $f12
  swc1  $f10, 0xbc($sp)
  lwc1  $f6, 0x1e0($v0)
  swc1  $f6, 0x10($sp)
  lwc1  $f4, 0x1e4($v0)
  swc1  $f4, 0x14($sp)
  lwc1  $f8, 0x1e8($v0)
  swc1  $f8, 0x18($sp)
  lwc1  $f10, 0x1ec($v0)
  swc1  $f10, 0x1c($sp)
  lwc1  $f6, 0x1f0($v0)
  swc1  $f6, 0x20($sp)
  lwc1  $f4, 0x1f4($v0)
  swc1  $f14, 0x168($sp)
  jal   sub_GAME_7F059908
   swc1  $f4, 0x24($sp)
  lw    $a0, 0x164($sp)
  jal   sub_GAME_7F058860
   addiu $a1, $sp, 0xfc
  addiu $a0, $sp, 0x108
  jal   sub_GAME_7F058860
   addiu $a1, $sp, 0xf0
  addiu $a0, $sp, 0xfc
  jal   sub_GAME_7F05B3F4
   addiu $a1, $sp, 0xe0
  addiu $a0, $sp, 0xf0
  jal   sub_GAME_7F05B3F4
   addiu $a1, $sp, 0xd0
  addiu $a0, $sp, 0xe0
  jal   sub_GAME_7F05BE10
   addiu $a1, $sp, 0xd0
  addiu $a0, $sp, 0xe0
  addiu $a1, $sp, 0xd0
  lw    $a2, 0x168($sp)
  jal   sub_GAME_7F05BA08
   addiu $a3, $sp, 0xc0
  addiu $a0, $sp, 0xc0
  jal   sub_GAME_7F05B628
   lw    $a1, 0x164($sp)
  addiu $a0, $sp, 0xb4
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   lw    $a1, 0x164($sp)
  lui   $t8, %hi(pPlayer) # $t8, 0x8008
  lw    $t8, %lo(pPlayer)($t8)
  lw    $a1, 0x164($sp)
  jal   matrix_multiply_A1_by_F12
   lwc1  $f12, 0x244($t8)
  li    $v1, 60
  lw    $a0, 0x90($sp)
  lui   $at, %hi(D_80055280) # $at, 0x8005
  lwc1  $f2, %lo(D_80055280)($at)
  div   $zero, $a0, $v1
  mfhi  $t6
  mflo  $v0
  mtc1  $t6, $f8
  mtc1  $zero, $f16
  div   $zero, $v0, $v1
  mfhi  $t4
  mflo  $t5
  cvt.s.w $f10, $f8
  bnez  $v1, .Ljp7F088980
   nop   
  break 7
.Ljp7F088980:
  li    $at, -1
  bne   $v1, $at, .Ljp7F088998
   lui   $at, 0x8000
  bne   $a0, $at, .Ljp7F088998
   nop   
  break 6
.Ljp7F088998:
  div   $zero, $t5, $v1
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f6
  mtc1  $t4, $f8
  mfhi  $t7
  div.s $f4, $f10, $f6
  bnez  $v1, .Ljp7F0889BC
   nop   
  break 7
.Ljp7F0889BC:
  li    $at, -1
  bne   $v1, $at, .Ljp7F0889D4
   li    $at, 0x80000000 # -0.000000
  bne   $v0, $at, .Ljp7F0889D4
   nop   
  break 6
.Ljp7F0889D4:
  li    $at, 0x42700000 # 60.000000
  lw    $t9, 0x160($sp)
  cvt.s.w $f10, $f8
  add.s $f6, $f10, $f4
  mtc1  $at, $f4
  neg.s $f8, $f6
  mtc1  $t7, $f6
  mul.s $f10, $f8, $f2
  cvt.s.w $f8, $f6
  div.s $f18, $f10, $f4
  neg.s $f10, $f8
  mul.s $f4, $f10, $f2
  c.lt.s $f18, $f16
  mov.s $f12, $f18
  bnez  $v1, .Ljp7F088A18
   nop   
  break 7
.Ljp7F088A18:
  li    $at, -1
  bne   $v1, $at, .Ljp7F088A30
   li    $at, 0x80000000 # -0.000000
  bne   $t5, $at, .Ljp7F088A30
   nop   
  break 6
.Ljp7F088A30:
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f6
  mtc1  $at, $f10
  li    $at, 3600
  div   $zero, $v0, $at
  mflo  $t2
  li    $at, 12
  div.s $f8, $f4, $f6
  div   $zero, $t2, $at
  div.s $f4, $f18, $f10
  mfhi  $t3
  mtc1  $t3, $f10
  li    $at, 0x41400000 # 12.000000
  add.s $f6, $f8, $f4
  cvt.s.w $f8, $f10
  swc1  $f6, 0x40($sp)
  mov.s $f14, $f6
  neg.s $f4, $f8
  mtc1  $at, $f8
  mul.s $f10, $f4, $f2
  div.s $f4, $f10, $f8
  mtc1  $at, $f10
  li    $at, 0x44340000 # 720.000000
  div.s $f8, $f6, $f10
  mtc1  $at, $f10
  add.s $f6, $f4, $f8
  div.s $f4, $f18, $f10
  lwc1  $f10, 0x40($sp)
  add.s $f8, $f6, $f4
  swc1  $f8, 0x3c($sp)
  mov.s $f0, $f8
  bc1f  .Ljp7F088AC8
   lwc1  $f6, 0x3c($sp)
  add.s $f12, $f12, $f2
.Ljp7F088AB8:
  c.lt.s $f12, $f16
  nop   
  bc1tl .Ljp7F088AB8
   add.s $f12, $f12, $f2
.Ljp7F088AC8:
  c.lt.s $f10, $f16
  nop   
  bc1fl .Ljp7F088AF0
   c.lt.s $f6, $f16
  add.s $f14, $f14, $f2
.Ljp7F088ADC:
  c.lt.s $f14, $f16
  nop   
  bc1tl .Ljp7F088ADC
   add.s $f14, $f14, $f2
  c.lt.s $f6, $f16
.Ljp7F088AF0:
  nop   
  bc1fl .Ljp7F088B14
   lw    $t8, 8($t9)
  add.s $f0, $f0, $f2
.Ljp7F088B00:
  c.lt.s $f0, $f16
  nop   
  bc1tl .Ljp7F088B00
   add.s $f0, $f0, $f2
  lw    $t8, 8($t9)
.Ljp7F088B14:
  lw    $a2, 0x164($sp)
  mfc1  $a1, $f0
  lw    $t6, ($t8)
  addiu $a2, $a2, 0x40
  lw    $a0, 4($t6)
  swc1  $f14, 0x98($sp)
  swc1  $f12, 0x9c($sp)
  jal   sub_GAME_7F0584D0
   sw    $a2, 0x40($sp)
  lw    $a1, 0x40($sp)
  jal   matrix_4x4_multiply_in_place
   lw    $a0, 0x164($sp)
  lw    $t4, 0x160($sp)
  lwc1  $f14, 0x98($sp)
  lw    $a2, 0x164($sp)
  lw    $t5, 8($t4)
  mfc1  $a1, $f14
  addiu $a2, $a2, 0x80
  lw    $t7, 4($t5)
  lw    $a0, 4($t7)
  jal   sub_GAME_7F0584D0
   sw    $a2, 0x40($sp)
  lw    $a1, 0x40($sp)
  jal   matrix_4x4_multiply_in_place
   lw    $a0, 0x164($sp)
  lw    $t2, 0x160($sp)
  lwc1  $f12, 0x9c($sp)
  lw    $a2, 0x164($sp)
  lw    $t3, 8($t2)
  mfc1  $a1, $f12
  addiu $a2, $a2, 0xc0
  lw    $t9, 8($t3)
  lw    $a0, 4($t9)
  jal   sub_GAME_7F0584D0
   sw    $a2, 0x40($sp)
  lw    $a1, 0x40($sp)
  jal   matrix_4x4_multiply_in_place
   lw    $a0, 0x164($sp)
  lw    $t6, 0x1f8($sp)
  lui   $v0, %hi(pPlayer) # $v0, 0x8008
  lw    $v0, %lo(pPlayer)($v0)
  li    $t8, 3
  li    $t4, 4
  sw    $t8, 0x1c0($sp)
  sw    $zero, 0x1bc($sp)
  sw    $t4, 0x1e8($sp)
  sw    $t6, 0x1c4($sp)
  lw    $v1, 0x1c8($v0)
  li    $at, 5
  addiu $a0, $sp, 0x1b8
  beq   $v1, $at, .Ljp7F088BE8
   li    $at, 12
  bne   $v1, $at, .Ljp7F088BF4
.Ljp7F088BE8:
   li    $t5, 205
  b     .Ljp7F088C20
   sw    $t5, 0x1ec($sp)
.Ljp7F088BF4:
  lbu   $t2, 0xfdc($v0)
  lbu   $t7, 0xfdf($v0)
  lbu   $t8, 0xfdd($v0)
  lbu   $t5, 0xfde($v0)
  sll   $t3, $t2, 0x18
  or    $t9, $t7, $t3
  sll   $t6, $t8, 0x10
  or    $t4, $t9, $t6
  sll   $t2, $t5, 8
  or    $t7, $t4, $t2
  sw    $t7, 0x1ec($sp)
.Ljp7F088C20:
  jal   subdraw
   addiu $a1, $v0, 0x230
  lw    $t3, 0x1c4($sp)
  lw    $t8, 0x160($sp)
  sw    $t3, 0x1f8($sp)
  lw    $t9, 8($t8)
  lw    $t6, 8($t9)
  lw    $t5, 4($t6)
  jal   sub_GAME_7F0BD6E0
   sw    $t5, 0x8c($sp)
  sw    $v0, 0x48($sp)
  lw    $a0, 0x8c($sp)
  jal   init_something_copy_posdata_to_it
   addiu $a1, $sp, 0x4c
  lw    $a0, 0x164($sp)
  jal   matrix_4x4_multiply_in_place
   addiu $a1, $sp, 0x4c
  jal   sub_GAME_7F058C64
   nop   
  addiu $a0, $sp, 0x4c
  jal   sub_GAME_7F058C9C
   lw    $a1, 0x48($sp)
  jal   sub_GAME_7F058C88
   nop   
  lui   $t4, %hi(pPlayer) # $t4, 0x8008
  lw    $t4, %lo(pPlayer)($t4)
  lw    $a0, 0x1f8($sp)
  lw    $v1, 0x1c8($t4)
  xori  $a2, $v1, 5
  sltiu $a2, $a2, 1
  bnez  $a2, .Ljp7F088CA8
   nop   
  xori  $a2, $v1, 0xc
  sltiu $a2, $a2, 1
.Ljp7F088CA8:
  jal   sub_GAME_7F0ACA28
   lw    $a1, 0x48($sp)
  jal   sub_GAME_7F058C64
   sw    $v0, 0x1f8($sp)
  lui   $t2, %hi(pPlayer) # $t2, 0x8008
  lw    $t2, %lo(pPlayer)($t2)
  lw    $t7, 0x160($sp)
  lw    $a0, 0x23c($t2)
  jal   sub_GAME_7F08BD48
   lh    $a1, 0xe($t7)
  jal   sub_GAME_7F058C88
   nop   
.Ljp7F088CD8:
  lw    $ra, 0x2c($sp)
.Ljp7F088CDC:
  lw    $v0, 0x1f8($sp)
  addiu $sp, $sp, 0x1f8
  jr    $ra
   nop     
");
#endif

#endif


asm(R"
glabel sub_GAME_7F088618
  addiu $sp, $sp, -0xc0
  sw    $s2, 0x38($sp)
  lui   $s2, %hi(pPlayer)
  addiu $s2, %lo(pPlayer) # addiu $s2, $s2, -0x5f50
  sw    $s1, 0x34($sp)
  lw    $s1, ($s2)
  sw    $s0, 0x30($sp)
  move  $s0, $a0
  sw    $ra, 0x3c($sp)
  li    $a1, 46
  li    $a2, 1
  lw    $a3, 0xf0($s1)
  jal   sub_GAME_7F0A2F30
   addiu $a0, $s1, 0x12b8
  lw    $s1, ($s2)
  lui   $at, (0x800012B8 >> 16) 
  ori   $at, (0x800012B8 & 0xFFFF) # ori $at, $at, 0x12b8
  li    $a2, 46
  addu  $a1, $s1, $at
  jal   sub_GAME_7F0A3330
   addiu $a0, $s1, 0x19f8
  lw    $s1, ($s2)
  li    $a1, 46
  li    $a2, -1
  addiu $a0, $s1, 0x1598
  jal   sub_GAME_7F0A2F30
   lw    $a3, 0xec($s1)
  lw    $s1, ($s2)
  lui   $at, (0x80001598 >> 16) 
  ori   $at, (0x80001598 & 0xFFFF) # ori $at, $at, 0x1598
  li    $a2, 46
  addu  $a1, $s1, $at
  jal   sub_GAME_7F0A3330
   addiu $a0, $s1, 0x2128
  jal   sub_GAME_7F0BD6E0
   nop   
  jal   sub_GAME_7F0BD6E0
   sw    $v0, 0xbc($sp)
  lui   $at, %hi(D_800364CC)
  lwc1  $f0, %lo(D_800364CC)($at)
  li    $at, 0xC4480000 # -800.000000
  mtc1  $at, $f4
  li    $at, 0x44480000 # 800.000000
  mtc1  $at, $f8
  mul.s $f6, $f4, $f0
  li    $at, 0xC4160000 # -600.000000
  mtc1  $at, $f16
  mul.s $f10, $f8, $f0
  li    $at, 0x44160000 # 600.000000
  mtc1  $at, $f4
  mul.s $f18, $f16, $f0
  li    $at, 0xC2C80000 # -100.000000
  mfc1  $a1, $f6
  mul.s $f6, $f4, $f0
  mtc1  $at, $f8
  li    $at, 0x447A0000 # 1000.000000
  mfc1  $a2, $f10
  mtc1  $at, $f10
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f16
  mfc1  $a3, $f18
  sw    $v0, 0xb8($sp)
  swc1  $f6, 0x10($sp)
  move  $a0, $v0
  swc1  $f8, 0x14($sp)
  swc1  $f10, 0x18($sp)
  jal   guOrtho
   swc1  $f16, 0x1c($sp)
  lui   $t6, (0x01030040 >> 16) # lui $t6, 0x103
  ori   $t6, (0x01030040 & 0xFFFF) # ori $t6, $t6, 0x40
  move  $s1, $s0
  sw    $t6, ($s1)
  lw    $a0, 0xb8($sp)
  jal   osVirtualToPhysical
   addiu $s0, $s0, 8
  mtc1  $zero, $f0
  sw    $v0, 4($s1)
  li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f18
  mfc1  $a1, $f0
  mfc1  $a3, $f0
  addiu $a0, $sp, 0x78
  lui   $a2, %hi(0x43FA0004) # $a2, 0x43fa
  swc1  $f0, 0x20($sp)
  swc1  $f0, 0x1c($sp)
  swc1  $f0, 0x18($sp)
  swc1  $f0, 0x14($sp)
  swc1  $f0, 0x10($sp)
  jal   sub_GAME_7F059694
   swc1  $f18, 0x24($sp)
  addiu $a0, $sp, 0x78
  jal   sub_GAME_7F058C9C
   lw    $a1, 0xbc($sp)
  lui   $t7, (0x01020040 >> 16) # lui $t7, 0x102
  ori   $t7, (0x01020040 & 0xFFFF) # ori $t7, $t7, 0x40
  move  $s1, $s0
  sw    $t7, ($s1)
  lw    $a0, 0xbc($sp)
  jal   osVirtualToPhysical
   addiu $s0, $s0, 8
  move  $v1, $s0
  sw    $v0, 4($s1)
  addiu $s0, $s0, 8
  lui   $t8, 0xe700
  move  $a0, $s0
  sw    $t8, ($v1)
  sw    $zero, 4($v1)
  addiu $s0, $s0, 8
  lui   $t9, (0xBA001402 >> 16) # lui $t9, 0xba00
  ori   $t9, (0xBA001402 & 0xFFFF) # ori $t9, $t9, 0x1402
  move  $a1, $s0
  sw    $t9, ($a0)
  sw    $zero, 4($a0)
  addiu $s0, $s0, 8
  lui   $t0, (0xB900031D >> 16) # lui $t0, 0xb900
  lui   $t1, (0x005041C8 >> 16) # lui $t1, 0x50
  ori   $t1, (0x005041C8 & 0xFFFF) # ori $t1, $t1, 0x41c8
  ori   $t0, (0xB900031D & 0xFFFF) # ori $t0, $t0, 0x31d
  move  $a2, $s0
  sw    $t0, ($a1)
  sw    $t1, 4($a1)
  lui   $t2, (0xB9000002 >> 16) # lui $t2, 0xb900
  ori   $t2, (0xB9000002 & 0xFFFF) # ori $t2, $t2, 2
  addiu $s0, $s0, 8
  sw    $t2, ($a2)
  sw    $zero, %lo(0x43FA0004)($a2)
  move  $a3, $s0
  addiu $s0, $s0, 8
  lui   $t3, (0xFCFFFFFF >> 16) # lui $t3, 0xfcff
  lui   $t4, (0xFFFE793C >> 16) # lui $t4, 0xfffe
  ori   $t4, (0xFFFE793C & 0xFFFF) # ori $t4, $t4, 0x793c
  ori   $t3, (0xFCFFFFFF & 0xFFFF) # ori $t3, $t3, 0xffff
  move  $v0, $s0
  sw    $t3, ($a3)
  sw    $t4, 4($a3)
  addiu $s0, $s0, 8
  lui   $t6, (0xE6E6E600 >> 16) # lui $t6, 0xe6e6
  ori   $t6, (0xE6E6E600 & 0xFFFF) # ori $t6, $t6, 0xe600
  lui   $t5, 0xfa00
  move  $v1, $s0
  sw    $t5, ($v0)
  sw    $t6, 4($v0)
  addiu $s0, $s0, 8
  li    $t8, 12288
  lui   $t7, 0xb600
  lui   $a2, 0x600
  sw    $t7, ($v1)
  sw    $t8, 4($v1)
  move  $a0, $s0
  sw    $a2, ($a0)
  lw    $t9, ($s2)
  lui   $at, (0x800019F8 >> 16) 
  ori   $at, (0x800019F8 & 0xFFFF) # ori $at, $at, 0x19f8
  addiu $s0, $s0, 8
  addu  $t0, $t9, $at
  sw    $t0, 4($a0)
  move  $a1, $s0
  sw    $a2, ($a1)
  lw    $t1, ($s2)
  lui   $at, (0x80002128 >> 16) 
  ori   $at, (0x80002128 & 0xFFFF) # ori $at, $at, 0x2128
  addiu $s0, $s0, 8
  lui   $t3, (0x01030040 >> 16) # lui $t3, 0x103
  addu  $t2, $t1, $at
  sw    $t2, 4($a1)
  ori   $t3, (0x01030040 & 0xFFFF) # ori $t3, $t3, 0x40
  move  $s1, $s0
  sw    $t3, ($s1)
  jal   get_BONDdata_field_10D8
   addiu $s0, $s0, 8
  jal   osVirtualToPhysical
   move  $a0, $v0
  sw    $v0, 4($s1)
  lw    $ra, 0x3c($sp)
  move  $v0, $s0
  lw    $s0, 0x30($sp)
  lw    $s2, 0x38($sp)
  lw    $s1, 0x34($sp)
  jr    $ra
   addiu $sp, $sp, 0xc0
");






asm(R"
.late_rodata
glabel D_80055284
.word 0x40c90fdb /*6.2831855*/
glabel D_80055288
.word 0x3e2e147c /*0.17000002*/
glabel D_8005528C
.word 0x3dccccd0 /*0.10000002*/

/*D:80055290*/
glabel jpt_mpspawntype
.word mp_spawntype_spawn
.word mp_spawntype_weapon
.word mp_spawntype_ammo
.word mp_spawntype_intro_swirly
.word mp_spawntype_intro_anim
.word mp_spawntype_handcuff
.word mp_spawntype_intro_camera

glabel D_800552AC
.word 0xb8d1b717 /*-0.000099999997*/
.text
glabel mp_respawn_handler
  addiu $sp, $sp, -0x58
  lui   $t7, %hi(D_8003688C) 
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  addiu $t7, %lo(D_8003688C) # addiu $t7, $t7, 0x688c
  lw    $at, ($t7)
  addiu $t6, $sp, 0x4c
  lw    $t0, 4($t7)
  sw    $at, ($t6)
  lw    $at, 8($t7)
  lui   $s0, %hi(ptr_setup_intro)
  sw    $t0, 4($t6)
  sw    $at, 8($t6)
  jal   init_player_BONDdata
   lw    $s0, %lo(ptr_setup_intro)($s0)
  jal   sub_GAME_7F0798B8
   nop   
  lui   $s1, %hi(pPlayer)
  addiu $s1, %lo(pPlayer) # addiu $s1, $s1, -0x5f50
  lw    $t1, ($s1)
  li    $t4, 1
  li    $v0, 7
  sw    $zero, 0xd8($t1)
  lw    $t2, ($s1)
  li    $t7, 2
  li    $a0, -1
  sw    $zero, 0x428($t2)
  lw    $t3, ($s1)
  sw    $zero, 0x424($t3)
  lw    $t5, ($s1)
  sw    $t4, 0x420($t5)
  lw    $t9, ($s1)
  sw    $v0, 0x29b8($t9)
  lw    $t8, ($s1)
  sw    $v0, 0x29d4($t8)
  lw    $t6, ($s1)
  sw    $zero, 0x1064($t6)
  lw    $t0, ($s1)
  jal   unset_flags_in_BONDdata_stationary_intro_cam
   sw    $t7, 0x1128($t0)
  jal   sub_GAME_7F08A928
   li    $a0, -1
  jal   getPlayerCount
   nop   
  slti  $at, $v0, 2
  bnez  $at, .L7F0889C4
   lui   $t1, %hi(dword_CODE_bss_80079C68) 
  lw    $t1, %lo(dword_CODE_bss_80079C68)($t1)
  blezl $t1, .L7F0889C8
   move  $v1, $zero
  jal   sub_GAME_7F0790F0
   nop   
  b     .L7F0889C8
   move  $v1, $v0
.L7F0889C4:
  move  $v1, $zero
.L7F0889C8:
  sll   $t2, $v1, 2
  lui   $v0, %hi(dword_CODE_bss_80079C28)
  addu  $v0, $v0, $t2
  lw    $v0, %lo(dword_CODE_bss_80079C28)($v0)
  lwc1  $f4, ($v0)
  swc1  $f4, 0x4c($sp)
  lwc1  $f6, 8($v0)
  lw    $a1, 0x4c($sp)
  swc1  $f6, 0x54($sp)
  lw    $a0, 0x28($v0)
  lw    $a2, 0x54($sp)
  jal   sub_GAME_7F080D60
   sw    $a0, 0x44($sp)
  lw    $v0, ($s1)
  lwc1  $f8, 0x29bc($v0)
  add.s $f10, $f8, $f0
  swc1  $f10, 0x50($sp)
  swc1  $f0, 0x70($v0)
  jal   get_random_value
   swc1  $f0, 0x3c($sp)
  mtc1  $v0, $f16
  lui   $at, %hi(D_80055284)
  lwc1  $f12, %lo(D_80055284)($at)
  lwc1  $f2, 0x3c($sp)
  bgez  $v0, .L7F088A40
   cvt.s.w $f18, $f16
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f4
  nop   
  add.s $f18, $f18, $f4
.L7F088A40:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f6
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f10
  mul.s $f8, $f18, $f6
  lw    $t3, ($s1)
  lui   $at, %hi(D_80055288)
  addiu $a1, $sp, 0x4c
  mul.s $f0, $f8, $f12
  nop   
  mul.s $f16, $f0, $f10
  swc1  $f0, 0x48($sp)
  div.s $f4, $f16, $f12
  swc1  $f4, 0x148($t3)
  lw    $t4, ($s1)
  swc1  $f2, 0x74($t4)
  lwc1  $f18, %lo(D_80055288)($at)
  lw    $t5, ($s1)
  div.s $f6, $f2, $f18
  swc1  $f6, 0x6c($t5)
  lw    $a0, ($s1)
  lw    $a2, 0x44($sp)
  jal   change_player_pos_to_target
   addiu $a0, $a0, 0x488
  jal   sinf
   lwc1  $f12, 0x48($sp)
  lw    $t9, ($s1)
  neg.s $f8, $f0
  mtc1  $zero, $f10
  swc1  $f8, 0x498($t9)
  lw    $t8, ($s1)
  swc1  $f10, 0x49c($t8)
  jal   cosf
   lwc1  $f12, 0x48($sp)
  lw    $t6, ($s1)
  lui   $at, %hi(D_8005528C)
  lwc1  $f12, %lo(D_8005528C)($at)
  swc1  $f0, 0x4a0($t6)
  lw    $t7, ($s1)
  lwc1  $f2, 0x4c($sp)
  swc1  $f2, 0x408($t7)
  lw    $t0, ($s1)
  lw    $t1, 0xa8($t0)
  swc1  $f2, 8($t1)
  lw    $t2, ($s1)
  lwc1  $f2, 0x50($sp)
  swc1  $f2, 0x40c($t2)
  lw    $t3, ($s1)
  lw    $t4, 0xa8($t3)
  swc1  $f2, 0xc($t4)
  lw    $t5, ($s1)
  lwc1  $f2, 0x54($sp)
  swc1  $f2, 0x410($t5)
  lw    $t9, ($s1)
  lw    $t8, 0xa8($t9)
  swc1  $f2, 0x10($t8)
  lw    $t7, ($s1)
  lw    $t6, 0x44($sp)
  lw    $t0, 0xa8($t7)
  sw    $t6, 0x14($t0)
  lw    $v0, ($s1)
  lwc1  $f16, 0x4b4($v0)
  div.s $f4, $f16, $f12
  swc1  $f4, 0x3b8($v0)
  lw    $v0, ($s1)
  lwc1  $f18, 0x4b8($v0)
  div.s $f6, $f18, $f12
  swc1  $f6, 0x3bc($v0)
  lw    $v0, ($s1)
  lwc1  $f8, 0x4bc($v0)
  div.s $f10, $f8, $f12
  jal   reinit_player_inventory
   swc1  $f10, 0x3c0($v0)
  lw    $t1, ($s1)
  li    $v0, 8
  li    $v1, 120
  sw    $zero, 0x1130($t1)
  lw    $t2, ($s1)
  sw    $zero, 0x1134($t2)
.L7F088B7C:
  lw    $t3, ($s1)
  addu  $t4, $t3, $v0
  sw    $zero, 0x1130($t4)
  lw    $t5, ($s1)
  addu  $t9, $t5, $v0
  sw    $zero, 0x1134($t9)
  lw    $t8, ($s1)
  addu  $t7, $t8, $v0
  sw    $zero, 0x1138($t7)
  lw    $t6, ($s1)
  addu  $t0, $t6, $v0
  addiu $v0, $v0, 0x10
  bne   $v0, $v1, .L7F088B7C
   sw    $zero, 0x113c($t0)
  beql  $s0, $zero, .L7F088C90
   mtc1  $zero, $f0
  lw    $v0, ($s0)
  li    $at, 9
  beq   $v0, $at, .L7F088C8C
   sltiu $at, $v0, 7
.L7F088BCC:
  beqz  $at, .L7F088C78
   sll   $t1, $v0, 2
  lui   $at, %hi(jpt_mpspawntype)
  addu  $at, $at, $t1
  lw    $t1, %lo(jpt_mpspawntype)($at)
  jr    $t1
   nop   
mp_spawntype_spawn:
  b     .L7F088C7C
   addiu $s0, $s0, 0xc
mp_spawntype_weapon:
  jal   check_ramrom_flags
   nop   
  lw    $t2, 0xc($s0)
  bne   $v0, $t2, .L7F088C28
   nop   
  lw    $a1, 8($s0)
  bltz  $a1, .L7F088C20
   nop   
  jal   add_doubles_item_to_inventory
   lw    $a0, 4($s0)
  b     .L7F088C7C
   addiu $s0, $s0, 0x10
.L7F088C20:
  jal   add_item_to_inventory
   lw    $a0, 4($s0)
.L7F088C28:
  b     .L7F088C7C
   addiu $s0, $s0, 0x10
mp_spawntype_ammo:
  jal   check_ramrom_flags
   nop   
  lw    $t3, 0xc($s0)
  bne   $v0, $t3, .L7F088C50
   nop   
  lw    $a0, 4($s0)
  jal   give_cur_player_ammo
   lw    $a1, 8($s0)
.L7F088C50:
  b     .L7F088C7C
   addiu $s0, $s0, 0x10
mp_spawntype_intro_swirly:
  b     .L7F088C7C
   addiu $s0, $s0, 0x20
mp_spawntype_intro_anim:
  b     .L7F088C7C
   addiu $s0, $s0, 8
mp_spawntype_handcuff:
  b     .L7F088C7C
   addiu $s0, $s0, 8
mp_spawntype_intro_camera:
  b     .L7F088C7C
   addiu $s0, $s0, 0x28
mp_spawntype_default:
.L7F088C78:
  addiu $s0, $s0, 4
.L7F088C7C:
  lw    $v0, ($s0)
  li    $at, 9
  bnel  $v0, $at, .L7F088BCC
   sltiu $at, $v0, 7
.L7F088C8C:
  mtc1  $zero, $f0
.L7F088C90:
  lw    $t4, ($s1)
  lui   $at, %hi(D_800552AC)
  swc1  $f0, 0x78($t4)
  lw    $t5, ($s1)
  lwc1  $f16, %lo(D_800552AC)($at)
  li    $at, 0x42F00000 # 120.000000
  mtc1  $at, $f12
  swc1  $f16, 0x7c($t5)
  lw    $t9, ($s1)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f14
  jal   set_curplayer_fade
   swc1  $f0, 0x80($t9)
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x58
");






asm(R"
glabel sub_GAME_7F088CD8
  addiu $sp, $sp, -0xb8
  sw    $ra, 0x5c($sp)
  sw    $s5, 0x4c($sp)
  move  $s5, $a0
  sw    $fp, 0x58($sp)
  sw    $s7, 0x54($sp)
  sw    $s6, 0x50($sp)
  sw    $s4, 0x48($sp)
  sw    $s3, 0x44($sp)
  sw    $s2, 0x40($sp)
  sw    $s1, 0x3c($sp)
  jal   get_stage_num
   sw    $s0, 0x38($sp)
  li    $at, 54
  bne   $v0, $at, .L7F0891D4
   lui   $s0, %hi(D_8003643C)
  addiu $s0, %lo(D_8003643C) # addiu $s0, $s0, 0x643c
  lw    $t6, ($s0)
  li    $at, 1
  lui   $t7, %hi(D_80036440) 
  bnel  $t6, $at, .L7F0891D8
   lw    $ra, 0x5c($sp)
  lw    $t7, %lo(D_80036440)($t7)
  lui   $v0, %hi(camera_80036438)
  addiu $v0, %lo(camera_80036438) # addiu $v0, $v0, 0x6438
  beqz  $t7, .L7F0891D4
   li    $s6, 220
  lw    $t8, ($v0)
  li    $s7, 220
  sw    $zero, 0x84($sp)
  addiu $t9, $t8, 1
  sw    $zero, 0x80($sp)
  sw    $t9, ($v0)
  sw    $t9, 0xb4($sp)
  jal   microcode_constructor
   move  $a0, $s5
  jal   get_video2_settings_height
   move  $s5, $v0
  lw    $t2, 0xb4($sp)
  lui   $a0, %hi(D_80036440)
  subu  $v1, $t2, $v0
  bgez  $v1, .L7F088D8C
   sra   $t3, $v1, 4
  addiu $at, $v1, 0xf
  sra   $t3, $at, 4
.L7F088D8C:
  move  $v1, $t3
  move  $a2, $t3
  bgez  $t2, .L7F088DA4
   sra   $t4, $t2, 4
  addiu $at, $t2, 0xf
  sra   $t4, $at, 4
.L7F088DA4:
  addiu $t5, $t4, 1
  bgez  $v1, .L7F088DB4
   sw    $t5, 0x90($sp)
  move  $a2, $zero
.L7F088DB4:
  blez  $a2, .L7F088E48
   move  $s3, $zero
  lw    $a0, %lo(D_80036440)($a0)
.L7F088DC0:
  lhu   $v0, ($a0)
  li    $at, 20497
  bnez  $v0, .L7F088DEC
   nop   
  lhu   $t6, 2($a0)
  bnez  $t6, .L7F088DEC
   li    $t7, 2
  sw    $s3, 0x90($sp)
  move  $a2, $s3
  b     .L7F088E48
   sw    $t7, ($s0)
.L7F088DEC:
  beq   $v0, $at, .L7F088E14
   lhu   $a1, 2($a0)
  lh    $v1, 4($a0)
  bltzl $v1, .L7F088E08
   lh    $v0, 6($a0)
  move  $s6, $v1
  lh    $v0, 6($a0)
.L7F088E08:
  bltzl $v0, .L7F088E18
   li    $at, 20497
  sw    $v0, 0x84($sp)
.L7F088E14:
  li    $at, 20497
.L7F088E18:
  beq   $a1, $at, .L7F088E40
   addiu $s3, $s3, 1
  lh    $v1, 8($a0)
  bltzl $v1, .L7F088E34
   lh    $v0, 0xa($a0)
  move  $s7, $v1
  lh    $v0, 0xa($a0)
.L7F088E34:
  bltz  $v0, .L7F088E40
   nop   
  sw    $v0, 0x80($sp)
.L7F088E40:
  bne   $s3, $a2, .L7F088DC0
   addiu $a0, $a0, 0xc
.L7F088E48:
  lw    $t8, 0x90($sp)
  move  $s3, $a2
  li    $a1, 12
  slt   $at, $a2, $t8
  beqz  $at, .L7F0891C8
   nop   
  multu $a2, $a1
  lui   $v1, %hi(D_80036440)
  lw    $v1, %lo(D_80036440)($v1)
  mflo  $s4
  addu  $a0, $v1, $s4
  lhu   $v0, ($a0)
  bnez  $v0, .L7F088E98
   nop   
  multu $a2, $a1
  mflo  $t9
  addu  $t1, $v1, $t9
  lhu   $t3, 2($t1)
  beqz  $t3, .L7F0891C8
   nop   
.L7F088E98:
  lui   $fp, %hi(ptrSecondFontTableLarge) 
  li    $at, 20497
  beq   $v0, $at, .L7F08901C
   addiu $fp, %lo(ptrSecondFontTableLarge) # addiu $fp, $fp, 0xeb8
  move  $a0, $v0
  jal   get_textptr_for_textID
   sll   $s1, $s3, 4
  lui   $t2, %hi(D_80036440) 
  lw    $t2, %lo(D_80036440)($t2)
  move  $s2, $v0
  addu  $a0, $t2, $s4
  lh    $v1, 4($a0)
  bltzl $v1, .L7F088ED8
   lh    $v0, 6($a0)
  move  $s6, $v1
  lh    $v0, 6($a0)
.L7F088ED8:
  bltz  $v0, .L7F088EE4
   nop   
  sw    $v0, 0x84($sp)
.L7F088EE4:
  jal   get_video2_settings_height
   nop   
  sll   $s0, $v0, 0x10
  sra   $t4, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t4
  lw    $t6, 0xb4($sp)
  addu  $t5, $v0, $s1
  lui   $t9, %hi(ptrFirstFontTableLarge) 
  lw    $t9, %lo(ptrFirstFontTableLarge)($t9)
  subu  $t7, $t5, $t6
  addu  $t8, $t7, $s0
  sw    $t8, 0xa8($sp)
  sw    $zero, 0x9c($sp)
  addiu $a0, $sp, 0x9c
  addiu $a1, $sp, 0x98
  move  $a2, $s2
  lw    $a3, ($fp)
  sw    $zero, 0x14($sp)
  sw    $zero, 0x98($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t9, 0x10($sp)
  lw    $t2, 0x84($sp)
  lw    $t1, 0xa8($sp)
  lw    $t3, 0x9c($sp)
  li    $at, 1
  bne   $t2, $at, .L7F088F64
   addu  $v1, $t1, $t3
  lw    $t0, 0x98($sp)
  move  $v0, $s6
  b     .L7F088F90
   subu  $a1, $s6, $t0
.L7F088F64:
  lw    $t4, 0x84($sp)
  li    $at, 2
  lw    $t0, 0x98($sp)
  bne   $t4, $at, .L7F088F8C
   move  $a1, $s6
  lw    $t0, 0x98($sp)
  sra   $t5, $t0, 1
  subu  $a1, $s6, $t5
  b     .L7F088F90
   addu  $v0, $a1, $t0
.L7F088F8C:
  addu  $v0, $s6, $t0
.L7F088F90:
  lw    $a2, 0xa8($sp)
  addiu $t6, $v1, 1
  sw    $t6, 0x10($sp)
  move  $a0, $s5
  addiu $a3, $v0, 1
  sw    $zero, 0x14($sp)
  sw    $a1, 0xac($sp)
  jal   microcode_constructor_related_to_menus
   addiu $a2, $a2, -1
  jal   get_video2_settings_txtClipW
   move  $s5, $v0
  sll   $s0, $v0, 0x10
  sra   $t7, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t7
  lui   $t9, %hi(ptrFirstFontTableLarge) 
  lw    $t9, %lo(ptrFirstFontTableLarge)($t9)
  lw    $t8, ($fp)
  li    $t1, -1
  sw    $t1, 0x18($sp)
  move  $a0, $s5
  addiu $a1, $sp, 0xac
  addiu $a2, $sp, 0xa8
  move  $a3, $s2
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t9, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t8, 0x10($sp)
  lui   $t3, %hi(D_80036440) 
  lw    $t3, %lo(D_80036440)($t3)
  move  $s5, $v0
  addu  $a0, $t3, $s4
.L7F08901C:
  lhu   $a1, 2($a0)
  li    $at, 20497
  beq   $a1, $at, .L7F089190
   move  $a0, $a1
  jal   get_textptr_for_textID
   sll   $s1, $s3, 4
  lui   $t2, %hi(D_80036440) 
  lw    $t2, %lo(D_80036440)($t2)
  move  $s2, $v0
  addu  $a0, $t2, $s4
  lh    $v1, 8($a0)
  bltzl $v1, .L7F089058
   lh    $v0, 0xa($a0)
  move  $s7, $v1
  lh    $v0, 0xa($a0)
.L7F089058:
  bltz  $v0, .L7F089064
   nop   
  sw    $v0, 0x80($sp)
.L7F089064:
  jal   get_video2_settings_height
   nop   
  sll   $s0, $v0, 0x10
  sra   $t4, $s0, 0x10
  jal   get_video2_settings_uly
   move  $s0, $t4
  lw    $t6, 0xb4($sp)
  addu  $t5, $v0, $s1
  lui   $t9, %hi(ptrFirstFontTableLarge) 
  lw    $t9, %lo(ptrFirstFontTableLarge)($t9)
  subu  $t7, $t5, $t6
  addu  $t8, $t7, $s0
  sw    $t8, 0xa8($sp)
  sw    $zero, 0x9c($sp)
  addiu $a0, $sp, 0x9c
  addiu $a1, $sp, 0x98
  move  $a2, $s2
  lw    $a3, ($fp)
  sw    $zero, 0x14($sp)
  sw    $zero, 0x98($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t9, 0x10($sp)
  lw    $t2, 0x80($sp)
  lw    $t1, 0xa8($sp)
  lw    $t3, 0x9c($sp)
  li    $at, 1
  bne   $t2, $at, .L7F0890E4
   addu  $v1, $t1, $t3
  lw    $t0, 0x98($sp)
  move  $v0, $s7
  b     .L7F089110
   subu  $a1, $s7, $t0
.L7F0890E4:
  lw    $t4, 0x80($sp)
  li    $at, 2
  lw    $t0, 0x98($sp)
  bne   $t4, $at, .L7F08910C
   move  $a1, $s7
  lw    $t0, 0x98($sp)
  sra   $t5, $t0, 1
  subu  $a1, $s7, $t5
  b     .L7F089110
   addu  $v0, $a1, $t0
.L7F08910C:
  addu  $v0, $s7, $t0
.L7F089110:
  lw    $a2, 0xa8($sp)
  addiu $t6, $v1, 1
  sw    $t6, 0x10($sp)
  move  $a0, $s5
  addiu $a3, $v0, 1
  sw    $zero, 0x14($sp)
  sw    $a1, 0xac($sp)
  jal   microcode_constructor_related_to_menus
   addiu $a2, $a2, -1
  jal   get_video2_settings_txtClipW
   move  $s5, $v0
  sll   $s0, $v0, 0x10
  sra   $t7, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t7
  lui   $t9, %hi(ptrFirstFontTableLarge) 
  lw    $t9, %lo(ptrFirstFontTableLarge)($t9)
  lw    $t8, ($fp)
  li    $t1, -1
  sw    $t1, 0x18($sp)
  move  $a0, $s5
  addiu $a1, $sp, 0xac
  addiu $a2, $sp, 0xa8
  move  $a3, $s2
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t9, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t8, 0x10($sp)
  move  $s5, $v0
.L7F089190:
  lw    $t3, 0x90($sp)
  addiu $s3, $s3, 1
  addiu $s4, $s4, 0xc
  slt   $at, $s3, $t3
  beqz  $at, .L7F0891C8
   lui   $t2, %hi(D_80036440) 
  lw    $t2, %lo(D_80036440)($t2)
  addu  $a0, $t2, $s4
  lhu   $v0, ($a0)
  bnez  $v0, .L7F088E98
   nop   
  lhu   $t4, 2($a0)
  bnez  $t4, .L7F088E98
   nop   
.L7F0891C8:
  jal   combiner_bayer_lod_perspective
   move  $a0, $s5
  move  $s5, $v0
.L7F0891D4:
  lw    $ra, 0x5c($sp)
.L7F0891D8:
  move  $v0, $s5
  lw    $s5, 0x4c($sp)
  lw    $s0, 0x38($sp)
  lw    $s1, 0x3c($sp)
  lw    $s2, 0x40($sp)
  lw    $s3, 0x44($sp)
  lw    $s4, 0x48($sp)
  lw    $s6, 0x50($sp)
  lw    $s7, 0x54($sp)
  lw    $fp, 0x58($sp)
  jr    $ra
   addiu $sp, $sp, 0xb8
");






asm(R"
glabel maybe_mp_interface
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  addiu $sp, $sp, -0x58
  sw    $ra, 0x1c($sp)
  sw    $a0, 0x58($sp)
  lw    $t7, ($t6)
  li    $at, 1
  bne   $t7, $at, .L7F089278
   nop   
  jal   sub_GAME_7F08A4E4
   nop   
  jal   sub_GAME_7F08A5FC
   lw    $a0, 0x58($sp)
  jal   sub_GAME_7F08A9F8
   sw    $v0, 0x58($sp)
  jal   sub_GAME_7F08AAE8
   lw    $a0, 0x58($sp)
  sw    $v0, 0x58($sp)
  jal   sub_GAME_7F056210
   move  $a0, $v0
  sw    $v0, 0x58($sp)
  jal   sub_GAME_7F0804E0
   move  $a0, $v0
  sw    $v0, 0x58($sp)
  jal   sub_GAME_7F088CD8
   move  $a0, $v0
  b     .L7F0896B4
   lw    $ra, 0x1c($sp)
.L7F089278:
  jal   sub_GAME_7F061920
   nop   
  jal   sub_GAME_7F06908C
   addiu $a0, $sp, 0x58
  jal   sub_GAME_7F062BE4
   addiu $a0, $sp, 0x58
  jal   sub_GAME_7F087E74
   lw    $a0, 0x58($sp)
  lui   $t8, %hi(pPlayer) 
  lw    $t8, %lo(pPlayer)($t8)
  sw    $v0, 0x58($sp)
  lw    $t9, 0x29c4($t8)
  beqz  $t9, .L7F089328
   nop   
  jal   get_video2_settings_ulx
   nop   
  jal   get_video2_settings_uly
   sw    $v0, 0x54($sp)
  jal   get_video2_settings_ulx
   sw    $v0, 0x50($sp)
  jal   get_video2_settings_width
   sh    $v0, 0x2e($sp)
  lh    $t0, 0x2e($sp)
  addu  $t1, $v0, $t0
  jal   get_video2_settings_uly
   sw    $t1, 0x4c($sp)
  jal   get_video2_settings_height
   sh    $v0, 0x2e($sp)
  lh    $t2, 0x2e($sp)
  lw    $a0, 0x58($sp)
  addu  $t3, $v0, $t2
  jal   microcode_constructor
   sw    $t3, 0x48($sp)
  lw    $t4, 0x48($sp)
  li    $t5, 160
  sw    $v0, 0x58($sp)
  sw    $t5, 0x14($sp)
  move  $a0, $v0
  lw    $a1, 0x54($sp)
  lw    $a2, 0x50($sp)
  lw    $a3, 0x4c($sp)
  jal   microcode_constructor_related_to_menus
   sw    $t4, 0x10($sp)
  sw    $v0, 0x58($sp)
.L7F089328:
  jal   check_if_healthbar_timer_greater_than_0
   nop   
  beqz  $v0, .L7F089358
   lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  lw    $t7, 0x1c8($t6)
  bnez  $t7, .L7F089358
   nop   
  jal   sub_GAME_7F088618
   lw    $a0, 0x58($sp)
  b     .L7F0893B0
   sw    $v0, 0x58($sp)
.L7F089358:
  jal   sub_GAME_7F0C6048
   nop   
  beqz  $v0, .L7F0893B0
   nop   
  jal   sub_GAME_7F088618
   lw    $a0, 0x58($sp)
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  sw    $v0, 0x58($sp)
  lui   $t8, %hi(clock_timer) 
  lw    $a0, 0x2a00($v1)
  blez  $a0, .L7F0893A4
   nop   
  lw    $t8, %lo(clock_timer)($t8)
  subu  $t9, $a0, $t8
  sw    $t9, 0x2a00($v1)
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  lw    $a0, 0x2a00($v1)
.L7F0893A4:
  bgez  $a0, .L7F0893B0
   nop   
  sw    $zero, 0x2a00($v1)
.L7F0893B0:
  jal   getPlayerCount
   nop   
  li    $at, 1
  bne   $v0, $at, .L7F0893CC
   nop   
  jal   display_objective_status_text_on_status_change
   nop   
.L7F0893CC:
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  lw    $v0, 0xd8($v1)
  beqz  $v0, .L7F089658
   nop   
  lw    $t0, 0x428($v1)
  li    $at, 1
  bnez  $t0, .L7F089500
   nop   
  bne   $v0, $at, .L7F089404
   move  $a0, $zero
  li    $t1, 2
  li    $a0, 1
  sw    $t1, 0xd8($v1)
.L7F089404:
  beqz  $a0, .L7F089484
   lui   $t2, %hi(pPlayer) 
  jal   die_blood_image_routine
   move  $a0, $zero
  jal   getPlayerCount
   nop   
  li    $at, 1
  bne   $v0, $at, .L7F089470
   nop   
  jal   reset_music_in_slot
   li    $a0, -1
  jal   set_missionstate
   move  $a0, $zero
  jal   sub_GAME_7F0C0BF0
   nop   
  jal   musicTrack1Vol
   andi  $a0, $v0, 0xffff
  lui   $at, %hi(music1_playing)
  sw    $zero, %lo(music1_playing)($at)
  jal   musicTrack2Vol
   move  $a0, $zero
  lui   $at, %hi(music2_playing)
  sw    $zero, %lo(music2_playing)($at)
  jal   musicTrack1Play
   li    $a0, 27
  b     .L7F089478
   nop   
.L7F089470:
  jal   set_missionstate
   li    $a0, 6
.L7F089478:
  lui   $v1, %hi(pPlayer)
  b     .L7F089500
   lw    $v1, %lo(pPlayer)($v1)
.L7F089484:
  lw    $t2, %lo(pPlayer)($t2)
  li    $a0, 150
  move  $a1, $zero
  lw    $t3, 0x424($t2)
  move  $a2, $zero
  lui   $a3, (0x3F34B4B5 >> 16) # lui $a3, 0x3f34
  beqz  $t3, .L7F0894B8
   lui   $t4, %hi(clock_timer) 
  jal   set_rgba_tint
   ori   $a3, (0x3F34B4B5 & 0xFFFF) # ori $a3, $a3, 0xb4b5
  lui   $v1, %hi(pPlayer)
  b     .L7F089500
   lw    $v1, %lo(pPlayer)($v1)
.L7F0894B8:
  lw    $t4, %lo(clock_timer)($t4)
  li    $a0, 2
  blez  $t4, .L7F0894D0
   nop   
  b     .L7F0894D0
   li    $a0, 1
.L7F0894D0:
  jal   die_blood_image_routine
   nop   
  beqz  $v0, .L7F0894EC
   lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  li    $t5, 1
  sw    $t5, 0x424($t6)
.L7F0894EC:
  jal   sub_GAME_7F01C670
   lw    $a0, 0x58($sp)
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  sw    $v0, 0x58($sp)
.L7F089500:
  jal   sub_GAME_7F06F5BC
   addiu $a0, $v1, 0x598
  lui   $a0, %hi(pPlayer)
  lw    $a0, %lo(pPlayer)($a0)
  swc1  $f0, 0x24($sp)
  jal   sub_GAME_7F06F5C4
   addiu $a0, $a0, 0x598
  lwc1  $f4, 0x24($sp)
  lui   $v1, %hi(pPlayer)
  c.le.s $f0, $f4
  nop   
  bc1f  .L7F089658
   nop   
  lw    $v1, %lo(pPlayer)($v1)
  lw    $t7, 0x424($v1)
  beqz  $t7, .L7F089658
   nop   
  lw    $t8, 0x428($v1)
  li    $t9, 1
  li    $at, 0x42700000 # 60.000000
  bnez  $t8, .L7F08958C
   move  $a1, $zero
  mtc1  $at, $f12
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  sw    $t9, 0x428($v1)
  move  $a2, $zero
  move  $a3, $zero
  jal   sub_GAME_7F0807E0
   swc1  $f6, 0x10($sp)
  li    $at, 0x42F00000 # 120.000000
  mtc1  $at, $f12
  mtc1  $zero, $f14
  jal   set_curplayer_fade
   nop   
.L7F08958C:
  jal   check_if_fade_to_black_complete
   nop   
  beqz  $v0, .L7F089658
   nop   
  jal   getPlayerCount
   nop   
  li    $at, 1
  bne   $v0, $at, .L7F0895C0
   nop   
  jal   set_camera_mode
   li    $a0, 5
  b     .L7F089658
   nop   
.L7F0895C0:
  jal   get_scenario
   nop   
  jal   get_cur_playernum
   sw    $v0, 0x40($sp)
  jal   getPlayerCount
   sw    $v0, 0x3c($sp)
  move  $a1, $v0
  move  $a0, $zero
  blez  $v0, .L7F089614
   move  $v1, $zero
  lw    $t0, 0x3c($sp)
  lui   $t2, %hi(player1_player_data) 
  addiu $t2, %lo(player1_player_data) # addiu $t2, $t2, -0x6110
  sll   $t1, $t0, 2
  addu  $v0, $t1, $t2
.L7F0895FC:
  lw    $t3, 0x24($v0)
  addiu $v1, $v1, 1
  slt   $at, $v1, $a1
  addiu $v0, $v0, 0x70
  bnez  $at, .L7F0895FC
   addu  $a0, $a0, $t3
.L7F089614:
  lw    $t4, 0x40($sp)
  li    $at, 1
  bne   $t4, $at, .L7F08962C
   slti  $at, $a0, 2
  beqz  $at, .L7F089658
   nop   
.L7F08962C:
  jal   get_cur_playernum
   nop   
  sll   $a0, $v0, 0x18
  sra   $t5, $a0, 0x18
  move  $a0, $t5
  jal   get_controller_buttons_held
   li    $a1, 45056
  beqz  $v0, .L7F089658
   nop   
  jal   mp_respawn_handler
   nop   
.L7F089658:
  jal   sub_GAME_7F08A4E4
   nop   
  jal   sub_GAME_7F08A5FC
   lw    $a0, 0x58($sp)
  jal   sub_GAME_7F08A9F8
   sw    $v0, 0x58($sp)
  jal   sub_GAME_7F08AAE8
   lw    $a0, 0x58($sp)
  sw    $v0, 0x58($sp)
  jal   sub_GAME_7F06A5E4
   addiu $a0, $sp, 0x58
  jal   generate_ammo_total_microcode
   lw    $a0, 0x58($sp)
  sw    $v0, 0x58($sp)
  jal   sub_GAME_7F056210
   move  $a0, $v0
  sw    $v0, 0x58($sp)
  jal   display_red_blue_on_radar
   move  $a0, $v0
  sw    $v0, 0x58($sp)
  jal   sub_GAME_7F0804E0
   move  $a0, $v0
  lw    $ra, 0x1c($sp)
.L7F0896B4:
  addiu $sp, $sp, 0x58
  jr    $ra
   nop   
");

asm(R"
glabel write_stan_tiles_in_yellow
  lui   $a1, %hi(dword_CODE_bss_80079DA0)
  lw    $a1, %lo(dword_CODE_bss_80079DA0)($a1)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  beqz  $a1, .L7F0896E4
   lui   $a2, (0xFF00FF80 >> 16) # lui $a2, 0xff00
  jal   sub_GAME_7F0B3024
   ori   $a2, (0xFF00FF80 & 0xFFFF) # ori $a2, $a2, 0xff80
  move  $a0, $v0
.L7F0896E4:
  lui   $a1, %hi(dword_CODE_bss_80079DA4)
  lw    $a1, %lo(dword_CODE_bss_80079DA4)($a1)
  lui   $a2, (0xFF00FF80 >> 16) # lui $a2, 0xff00
  beql  $a1, $zero, .L7F089708
   lw    $ra, 0x14($sp)
  jal   sub_GAME_7F0B3024
   ori   $a2, (0xFF00FF80 & 0xFFFF) # ori $a2, $a2, 0xff80
  move  $a0, $v0
  lw    $ra, 0x14($sp)
.L7F089708:
  addiu $sp, $sp, 0x18
  move  $v0, $a0
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F089718
  lui   $v1, %hi(D_800364D0)
  addiu $v1, %lo(D_800364D0) # addiu $v1, $v1, 0x64d0
  lwc1  $f4, ($v1)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f18
  div.s $f0, $f4, $f12
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lui   $at, %hi(D_800364D4)
  lwc1  $f6, 0x48c($v0)
  lwc1  $f10, 0x494($v0)
  addiu $v0, $v0, 0x488
  div.s $f4, $f18, $f12
  mul.s $f8, $f6, $f0
  nop   
  mul.s $f16, $f10, $f0
  swc1  $f8, 4($v0)
  swc1  $f16, 0xc($v0)
  swc1  $f12, ($v1)
  jr    $ra
   swc1  $f4, %lo(D_800364D4)($at)
");

void sub_GAME_7F08976C(float param_1) {
  D_800364CC = param_1;
}

asm(R"
glabel sub_GAME_7F089778
  jr    $ra
   lwc1  $f0, 0x74($a0)
");

asm(R"
glabel sub_GAME_7F089780
  lwc1  $f4, 0x29bc($a0)
  lwc1  $f6, 0x88($a0)
  lwc1  $f10, 0xa0($a0)
  add.s $f8, $f4, $f6
  jr    $ra
   add.s $f0, $f8, $f10
");

asm(R"
glabel get_curplayer_positiondata
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  jr    $ra
   lw    $v0, 0xa8($t6)
");

asm(R"
glabel kill_current_player
  addiu $sp, $sp, -0x20
  sw    $s0, 0x18($sp)
  lui   $s0, %hi(pPlayer)
  addiu $s0, %lo(pPlayer) # addiu $s0, $s0, -0x5f50
  lw    $v0, ($s0)
  sw    $ra, 0x1c($sp)
  lbu   $t6, 0x12b6($v0)
  bnezl $t6, .L7F0898D8
   lw    $ra, 0x1c($sp)
  lw    $t7, 0xd8($v0)
  bnezl $t7, .L7F0898D8
   lw    $ra, 0x1c($sp)
  lw    $t8, 0x1c8($v0)
  beql  $t8, $zero, .L7F0897F4
   li    $v1, 1
  jal   trigger_solo_watch_menu
   li    $a0, 1
  lw    $v0, ($s0)
  li    $v1, 1
.L7F0897F4:
  lui   $at, %hi(mission_kia_flag)
  sw    $v1, %lo(mission_kia_flag)($at)
  sw    $v1, 0xd8($v0)
  lw    $t2, ($s0)
  li    $a0, 1
  move  $t1, $t2
  addiu $t0, $t2, 0x54
.L7F089810:
  lw    $at, 0x488($t1)
  addiu $t1, $t1, 0xc
  addiu $t2, $t2, 0xc
  sw    $at, 0x428($t2)
  lw    $at, 0x480($t1)
  sw    $at, 0x42c($t2)
  lw    $at, 0x484($t1)
  bne   $t1, $t0, .L7F089810
   sw    $at, 0x430($t2)
  lw    $v0, ($s0)
  lui   $t3, %hi(ptr_playerstank) 
  lui   $at, %hi(D_8003648C)
  lwc1  $f4, 0x148($v0)
  swc1  $f4, 0x414($v0)
  lw    $v0, ($s0)
  lwc1  $f6, 0x158($v0)
  swc1  $f6, 0x418($v0)
  lw    $t3, %lo(ptr_playerstank)($t3)
  beqz  $t3, .L7F089864
   nop   
  sw    $v1, %lo(D_8003648C)($at)
.L7F089864:
  jal   draw_item_in_hand_has_more_ammo
   move  $a1, $zero
  move  $a0, $zero
  jal   draw_item_in_hand_has_more_ammo
   move  $a1, $zero
  jal   get_mission_timer
   nop   
  lw    $t4, ($s0)
  lui   $t7, %hi(pPlayersPerm) 
  lw    $t7, %lo(pPlayersPerm)($t7)
  lw    $t5, 0x29f4($t4)
  lw    $t8, 0x50($t7)
  subu  $t6, $v0, $t5
  slt   $at, $t6, $t8
  beqz  $at, .L7F0898C4
   nop   
  jal   get_mission_timer
   nop   
  lw    $t9, ($s0)
  lui   $t2, %hi(pPlayersPerm) 
  lw    $t2, %lo(pPlayersPerm)($t2)
  lw    $t0, 0x29f4($t9)
  subu  $t1, $v0, $t0
  sw    $t1, 0x50($t2)
.L7F0898C4:
  jal   get_mission_timer
   nop   
  lw    $t3, ($s0)
  sw    $v0, 0x29f4($t3)
  lw    $ra, 0x1c($sp)
.L7F0898D8:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0898E8
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   get_cur_controller_vert_stick_pos
   move  $a0, $zero
  sll   $t6, $v0, 3
  addiu $v0, $t6, 0x280
  li    $at, 160
  div   $zero, $v0, $at
  lw    $ra, 0x14($sp)
  mflo  $v0
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

#ifdef VERSION_US
asm(R"
.late_rodata
glabel pi_800552B0
.word 0x40490fdb /*3.1415927*/
.text
glabel record_damage_kills
  addiu $sp, $sp, -0x40
  lui   $t6, %hi(pPlayersPerm) 
  lw    $t6, %lo(pPlayersPerm)($t6)
  sw    $ra, 0x14($sp)
  swc1  $f14, 0x44($sp)
  sw    $a2, 0x48($sp)
  sw    $a3, 0x4c($sp)
  lwc1  $f4, 0x5c($t6)
  lui   $t7, %hi(pPlayer) 
  lw    $t7, %lo(pPlayer)($t7)
  mul.s $f6, $f4, $f12
  swc1  $f6, 0x3c($sp)
  lw    $t8, 0x1c8($t7)
  beqz  $t8, .L7F0899A0
   nop   
  jal   get_BONDdata_watch_armor
   nop   
  lui   $a0, %hi(pPlayer)
  lw    $a0, %lo(pPlayer)($a0)
  mfc1  $a3, $f0
  li    $a1, 46
  li    $a2, 1
  jal   sub_GAME_7F0A2F30
   addiu $a0, $a0, 0x12b8
  jal   get_BONDdata_watch_health
   nop   
  lui   $a0, %hi(pPlayer)
  lw    $a0, %lo(pPlayer)($a0)
  mfc1  $a3, $f0
  li    $a1, 46
  li    $a2, -1
  jal   sub_GAME_7F0A2F30
   addiu $a0, $a0, 0x1598
.L7F0899A0:
  jal   getPlayerCount
   nop   
  slti  $at, $v0, 2
  bnez  $at, .L7F0899CC
   lui   $t9, %hi(stop_play_flag) 
  lw    $t9, %lo(stop_play_flag)($t9)
  lui   $t0, %hi(is_gameover_flag) 
  bnezl $t9, .L7F089E40
   lw    $ra, 0x14($sp)
  lw    $t0, %lo(is_gameover_flag)($t0)
  bnez  $t0, .L7F089E3C
.L7F0899CC:
   lui   $t1, %hi(in_tank_flag) 
  lw    $t1, %lo(in_tank_flag)($t1)
  li    $at, 1
  lwc1  $f8, 0x3c($sp)
  bne   $t1, $at, .L7F0899F8
   lui   $v0, %hi(pPlayer)
  li    $at, 0x3E800000 # 0.250000
  mtc1  $at, $f10
  nop   
  mul.s $f16, $f8, $f10
  swc1  $f16, 0x3c($sp)
.L7F0899F8:
  lw    $v0, %lo(pPlayer)($v0)
  lw    $t2, 0xd8($v0)
  bnez  $t2, .L7F089A5C
   nop   
  lbu   $t3, 0x12b6($v0)
  bnez  $t3, .L7F089A5C
   nop   
  jal   get_cur_playernum
   nop   
  move  $a0, $v0
  jal   controller_7000C854
   lui   $a1, 0x3e80
  jal   cur_player_get_control_type
   nop   
  slti  $at, $v0, 4
  bnez  $at, .L7F089A5C
   nop   
  jal   get_cur_playernum
   nop   
  jal   getPlayerCount
   sw    $v0, 0x1c($sp)
  lw    $t4, 0x1c($sp)
  lui   $a1, 0x3e80
  jal   controller_7000C854
   addu  $a0, $v0, $t4
.L7F089A5C:
  jal   getPlayerCount
   nop   
  slti  $at, $v0, 2
  bnez  $at, .L7F089AAC
   nop   
  jal   get_scenario
   nop   
  li    $at, 4
  bne   $v0, $at, .L7F089AAC
   lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lwc1  $f18, 0xdc($v0)
  lwc1  $f4, 0x2a3c($v0)
  lwc1  $f8, 0xe0($v0)
  lwc1  $f10, 0x2a40($v0)
  mul.s $f6, $f18, $f4
  nop   
  mul.s $f16, $f8, $f10
  add.s $f18, $f6, $f16
  swc1  $f18, 0x3c($sp)
.L7F089AAC:
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lbu   $t5, 0x12b6($v0)
  bnezl $t5, .L7F089E40
   lw    $ra, 0x14($sp)
  lw    $t6, 0xd8($v0)
  lui   $t7, %hi(disable_player_pickups_flag) 
  bnezl $t6, .L7F089E40
   lw    $ra, 0x14($sp)
  lw    $t7, %lo(disable_player_pickups_flag)($t7)
  bnezl $t7, .L7F089E40
   lw    $ra, 0x14($sp)
  lw    $t8, 0xf4($v0)
  bltzl $t8, .L7F089B10
   lw    $v1, 0x1c8($v0)
  jal   getPlayerCount
   nop   
  slti  $at, $v0, 2
  bnez  $at, .L7F089E3C
   lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lw    $t9, 0xf4($v0)
  bnezl $t9, .L7F089E40
   lw    $ra, 0x14($sp)
  lw    $v1, 0x1c8($v0)
.L7F089B10:
  li    $at, 5
  beq   $v1, $at, .L7F089E3C
   li    $at, 12
  beql  $v1, $at, .L7F089E40
   lw    $ra, 0x14($sp)
  lwc1  $f4, 0xdc($v0)
  swc1  $f4, 0xe4($v0)
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lwc1  $f8, 0xe0($v0)
  jal   getPlayerCount
   swc1  $f8, 0xe8($v0)
  slti  $at, $v0, 2
  bnezl $at, .L7F089C1C
   lw    $v1, 0x50($sp)
  jal   get_cur_playernum
   nop   
  sw    $v0, 0x38($sp)
  lwc1  $f12, 0x44($sp)
  jal   convert_angle_using_inverse
   lwc1  $f14, 0x48($sp)
  li    $at, 0x43340000 # 180.000000
  mtc1  $at, $f10
  lui   $at, %hi(pi_800552B0)
  lwc1  $f16, %lo(pi_800552B0)($at)
  mul.s $f6, $f0, $f10
  lw    $t0, 0x38($sp)
  li    $at, 0x43B40000 # 360.000000
  lui   $t2, %hi(players_p1)
  sll   $t1, $t0, 2
  mtc1  $at, $f4
  addu  $t2, $t2, $t1
  div.s $f18, $f6, $f16
  lw    $t2, %lo(players_p1)($t2)
  mtc1  $zero, $f12
  lw    $t3, 0x4c($sp)
  lwc1  $f10, 0x148($t2)
  li    $at, 0x42B40000 # 90.000000
  sll   $t4, $t3, 3
  lui   $t5, %hi(player1_player_data) 
  subu  $t4, $t4, $t3
  mtc1  $at, $f6
  sll   $t4, $t4, 4
  addiu $t5, %lo(player1_player_data) # addiu $t5, $t5, -0x6110
  li    $at, 0x43870000 # 270.000000
  addu  $v0, $t4, $t5
  sub.s $f8, $f4, $f18
  sub.s $f2, $f10, $f8
  c.lt.s $f2, $f12
  nop   
  bc1fl .L7F089BE8
   c.lt.s $f2, $f6
  neg.s $f2, $f2
  c.lt.s $f2, $f6
.L7F089BE8:
  nop   
  bc1tl .L7F089C10
   lw    $t6, 0x3c($v0)
  mtc1  $at, $f16
  nop   
  c.lt.s $f16, $f2
  nop   
  bc1fl .L7F089C1C
   lw    $v1, 0x50($sp)
  lw    $t6, 0x3c($v0)
.L7F089C10:
  addiu $t7, $t6, 1
  sw    $t7, 0x3c($v0)
  lw    $v1, 0x50($sp)
.L7F089C1C:
  mtc1  $zero, $f12
  lui   $v0, %hi(pPlayer)
  beqz  $v1, .L7F089C68
   nop   
  lw    $v0, %lo(pPlayer)($v0)
  lwc1  $f18, 0x3c($sp)
  lwc1  $f0, 0xe0($v0)
  lwc1  $f2, 0x2a40($v0)
  mul.s $f4, $f0, $f2
  c.le.s $f18, $f4
  nop   
  bc1f  .L7F089C68
   nop   
  div.s $f10, $f18, $f2
  sub.s $f8, $f0, $f10
  swc1  $f8, 0xe0($v0)
  lui   $v0, %hi(pPlayer)
  b     .L7F089DD8
   lw    $v0, %lo(pPlayer)($v0)
.L7F089C68:
  lui   $v0, %hi(pPlayer)
  beqz  $v1, .L7F089CAC
   lw    $v0, %lo(pPlayer)($v0)
  lwc1  $f6, 0xe0($v0)
  lwc1  $f16, 0x2a40($v0)
  lwc1  $f18, 0x3c($sp)
  li    $at, 0x3F800000 # 1.000000
  div.s $f4, $f6, $f16
  lui   $t8, %hi(pPlayer) 
  mtc1  $at, $f8
  sub.s $f10, $f18, $f4
  swc1  $f10, 0x3c($sp)
  swc1  $f12, 0xe0($v0)
  lw    $t8, %lo(pPlayer)($t8)
  lui   $v0, %hi(pPlayer)
  swc1  $f8, 0x2a40($t8)
  lw    $v0, %lo(pPlayer)($v0)
.L7F089CAC:
  lwc1  $f6, 0x3c($sp)
  lwc1  $f16, 0x2a3c($v0)
  lwc1  $f4, 0xdc($v0)
  div.s $f18, $f6, $f16
  sub.s $f10, $f4, $f18
  swc1  $f10, 0xdc($v0)
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lwc1  $f8, 0xdc($v0)
  c.le.s $f8, $f12
  nop   
  bc1fl .L7F089DDC
   lw    $t3, 0xf4($v0)
  jal   getPlayerCount
   nop   
  slti  $at, $v0, 2
  bnez  $at, .L7F089DC8
   nop   
  jal   get_cur_playernum
   nop   
  sw    $v0, 0x2c($sp)
  jal   get_scenario
   sw    $zero, 0x28($sp)
  li    $at, 3
  bnel  $v0, $at, .L7F089D2C
   lw    $t0, 0x2c($sp)
  jal   checkforgoldengun
   nop   
  beqz  $v0, .L7F089D28
   li    $t9, 1
  sw    $t9, 0x28($sp)
.L7F089D28:
  lw    $t0, 0x2c($sp)
.L7F089D2C:
  lw    $t1, 0x4c($sp)
  beq   $t0, $t1, .L7F089D48
   nop   
  jal   drop_inventory
   nop   
  jal   increment_num_deaths
   nop   
.L7F089D48:
  jal   set_cur_player
   lw    $a0, 0x4c($sp)
  lw    $t2, 0x2c($sp)
  lw    $t3, 0x4c($sp)
  bne   $t2, $t3, .L7F089D70
   nop   
  jal   increment_num_suicides_display_MP
   nop   
  b     .L7F089D8C
   nop   
.L7F089D70:
  jal   increment_num_kills_display_text_in_MP
   nop   
  lw    $t4, 0x28($sp)
  beqz  $t4, .L7F089D8C
   nop   
  jal   increment_num_times_killed_MwtGC
   nop   
.L7F089D8C:
  jal   set_cur_player
   lw    $a0, 0x2c($sp)
  lw    $t5, 0x4c($sp)
  lw    $t7, 0x2c($sp)
  lui   $t0, %hi(player1_player_data) 
  sll   $t6, $t5, 3
  subu  $t6, $t6, $t5
  sll   $t6, $t6, 4
  sll   $t8, $t7, 2
  addu  $t9, $t6, $t8
  addiu $t0, %lo(player1_player_data) # addiu $t0, $t0, -0x6110
  addu  $v0, $t9, $t0
  lw    $t1, 0x24($v0)
  addiu $t2, $t1, 1
  sw    $t2, 0x24($v0)
.L7F089DC8:
  jal   kill_current_player
   nop   
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
.L7F089DD8:
  lw    $t3, 0xf4($v0)
.L7F089DDC:
  lwc1  $f6, 0x44($sp)
  lui   $t4, %hi(pPlayer) 
  bgez  $t3, .L7F089E20
   lui   $a0, %hi(ptr_sfx_buf)
  add.s $f16, $f6, $f6
  lwc1  $f4, 0x180($v0)
  add.s $f18, $f4, $f16
  swc1  $f18, 0x180($v0)
  lwc1  $f10, 0x48($sp)
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  add.s $f8, $f10, $f10
  lwc1  $f6, 0x188($v0)
  add.s $f4, $f6, $f8
  swc1  $f4, 0x188($v0)
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
.L7F089E20:
  sw    $zero, 0xf4($v0)
  lw    $t4, %lo(pPlayer)($t4)
  li    $a1, 68
  move  $a2, $zero
  sw    $zero, 0xf8($t4)
  jal   play_sfx_a1
   lw    $a0, %lo(ptr_sfx_buf)($a0)
.L7F089E3C:
  lw    $ra, 0x14($sp)
.L7F089E40:
  addiu $sp, $sp, 0x40
  jr    $ra
   nop   
");

#ifdef VERSION_JP
asm(R"
.late_rodata
glabel pi_800552B0
.word 0x40490fdb /*3.1415927*/
.text
glabel record_damage_kills
  addiu $sp, $sp, -0x40
  lui   $t6, %hi(pPlayersPerm) # $t6, 0x8008
  lw    $t6, %lo(pPlayersPerm)($t6)
  sw    $ra, 0x14($sp)
  swc1  $f14, 0x44($sp)
  sw    $a2, 0x48($sp)
  sw    $a3, 0x4c($sp)
  lwc1  $f4, 0x5c($t6)
  lui   $t7, %hi(pPlayer) # $t7, 0x8008
  lw    $t7, %lo(pPlayer)($t7)
  mul.s $f6, $f4, $f12
  swc1  $f6, 0x3c($sp)
  lw    $t8, 0x1c8($t7)
  beqz  $t8, .Ljp7F08A074
   nop   
  jal   get_BONDdata_watch_armor
   nop   
  lui   $a0, %hi(pPlayer) # $a0, 0x8008
  lw    $a0, %lo(pPlayer)($a0)
  mfc1  $a3, $f0
  li    $a1, 46
  li    $a2, 1
  jal   sub_GAME_7F0A2F30
   addiu $a0, $a0, 0x12b8
  jal   get_BONDdata_watch_health
   nop   
  lui   $a0, %hi(pPlayer) # $a0, 0x8008
  lw    $a0, %lo(pPlayer)($a0)
  mfc1  $a3, $f0
  li    $a1, 46
  li    $a2, -1
  jal   sub_GAME_7F0A2F30
   addiu $a0, $a0, 0x1598
.Ljp7F08A074:
  jal   getPlayerCount
   nop   
  slti  $at, $v0, 2
  bnez  $at, .Ljp7F08A0A0
   lui   $t9, %hi(stop_play_flag) # $t9, 0x8009
  lw    $t9, %lo(stop_play_flag)($t9)
  lui   $t0, %hi(is_gameover_flag) # $t0, 0x8009
  bnezl $t9, .Ljp7F08A548
   lw    $ra, 0x14($sp)
  lw    $t0, %lo(is_gameover_flag)($t0)
  bnez  $t0, .Ljp7F08A544
.Ljp7F08A0A0:
   lui   $t1, %hi(in_tank_flag) # $t1, 0x8003
  lw    $t1, %lo(in_tank_flag)($t1)
  li    $at, 1
  lwc1  $f8, 0x3c($sp)
  bne   $t1, $at, .Ljp7F08A0CC
   lui   $v0, %hi(pPlayer) # $v0, 0x8008
  li    $at, 0x3E800000 # 0.250000
  mtc1  $at, $f10
  nop   
  mul.s $f16, $f8, $f10
  swc1  $f16, 0x3c($sp)
.Ljp7F08A0CC:
  lw    $v0, %lo(pPlayer)($v0)
  lw    $t2, 0xd8($v0)
  bnez  $t2, .Ljp7F08A130
   nop   
  lbu   $t3, 0x12b6($v0)
  bnez  $t3, .Ljp7F08A130
   nop   
  jal   get_cur_playernum
   nop   
  move  $a0, $v0
  jal   controller_7000C854
   lui   $a1, 0x3e80
  jal   cur_player_get_control_type
   nop   
  slti  $at, $v0, 4
  bnez  $at, .Ljp7F08A130
   nop   
  jal   get_cur_playernum
   nop   
  jal   getPlayerCount
   sw    $v0, 0x1c($sp)
  lw    $t4, 0x1c($sp)
  lui   $a1, 0x3e80
  jal   controller_7000C854
   addu  $a0, $v0, $t4
.Ljp7F08A130:
  jal   getPlayerCount
   nop   
  slti  $at, $v0, 2
  bnez  $at, .Ljp7F08A180
   nop   
  jal   get_scenario
   nop   
  li    $at, 4
  bne   $v0, $at, .Ljp7F08A180
   lui   $v0, %hi(pPlayer) # $v0, 0x8008
  lw    $v0, %lo(pPlayer)($v0)
  lwc1  $f18, 0xdc($v0)
  lwc1  $f4, 0x2a3c($v0)
  lwc1  $f8, 0xe0($v0)
  lwc1  $f10, 0x2a40($v0)
  mul.s $f6, $f18, $f4
  nop   
  mul.s $f16, $f8, $f10
  add.s $f18, $f6, $f16
  swc1  $f18, 0x3c($sp)
.Ljp7F08A180:
  lui   $v0, %hi(pPlayer) # $v0, 0x8008
  lw    $v0, %lo(pPlayer)($v0)
  lbu   $t5, 0x12b6($v0)
  bnezl $t5, .Ljp7F08A548
   lw    $ra, 0x14($sp)
  lw    $t6, 0xd8($v0)
  lui   $t7, %hi(disable_player_pickups_flag) # $t7, 0x8003
  bnezl $t6, .Ljp7F08A548
   lw    $ra, 0x14($sp)
  lw    $t7, %lo(disable_player_pickups_flag)($t7)
  bnezl $t7, .Ljp7F08A548
   lw    $ra, 0x14($sp)
  lwc1  $f4, 0xf4($v0)
  mtc1  $zero, $f8
  nop   
  c.lt.s $f4, $f8
  nop   
  bc1tl .Ljp7F08A200
   lw    $v1, 0x1c8($v0)
  jal   getPlayerCount
   nop   
  slti  $at, $v0, 2
  bnez  $at, .Ljp7F08A544
   lui   $v0, %hi(pPlayer) # $v0, 0x8008
  lw    $v0, %lo(pPlayer)($v0)
  mtc1  $zero, $f10
  lwc1  $f6, 0xf4($v0)
  c.eq.s $f10, $f6
  nop   
  bc1fl .Ljp7F08A548
   lw    $ra, 0x14($sp)
  lw    $v1, 0x1c8($v0)
.Ljp7F08A200:
  li    $at, 5
  beq   $v1, $at, .Ljp7F08A544
   li    $at, 12
  beql  $v1, $at, .Ljp7F08A548
   lw    $ra, 0x14($sp)
  lwc1  $f16, 0xdc($v0)
  swc1  $f16, 0xe4($v0)
  lui   $v0, %hi(pPlayer) # $v0, 0x8008
  lw    $v0, %lo(pPlayer)($v0)
  lwc1  $f18, 0xe0($v0)
  jal   getPlayerCount
   swc1  $f18, 0xe8($v0)
  slti  $at, $v0, 2
  bnezl $at, .Ljp7F08A30C
   lw    $v1, 0x50($sp)
  jal   get_cur_playernum
   nop   
  sw    $v0, 0x38($sp)
  lwc1  $f12, 0x44($sp)
  jal   convert_angle_using_inverse
   lwc1  $f14, 0x48($sp)
  li    $at, 0x43340000 # 180.000000
  mtc1  $at, $f4
  lui   $at, %hi(pi_800552B0) # $at, 0x8005
  lwc1  $f10, %lo(pi_800552B0)($at)
  mul.s $f8, $f0, $f4
  lw    $t8, 0x38($sp)
  li    $at, 0x43B40000 # 360.000000
  lui   $t0, %hi(players_p1)
  sll   $t9, $t8, 2
  mtc1  $at, $f16
  addu  $t0, $t0, $t9
  div.s $f6, $f8, $f10
  lw    $t0, %lo(players_p1)($t0)
  mtc1  $zero, $f12
  lw    $t1, 0x4c($sp)
  lwc1  $f4, 0x148($t0)
  li    $at, 0x42B40000 # 90.000000
  sll   $t2, $t1, 3
  lui   $t3, %hi(player1_player_data) # $t3, 0x8008
  subu  $t2, $t2, $t1
  mtc1  $at, $f8
  sll   $t2, $t2, 4
  addiu $t3, %lo(player1_player_data) # addiu $t3, $t3, -0x60a0
  li    $at, 0x43870000 # 270.000000
  addu  $v0, $t2, $t3
  sub.s $f18, $f16, $f6
  sub.s $f2, $f4, $f18
  c.lt.s $f2, $f12
  nop   
  bc1fl .Ljp7F08A2D8
   c.lt.s $f2, $f8
  neg.s $f2, $f2
  c.lt.s $f2, $f8
.Ljp7F08A2D8:
  nop   
  bc1tl .Ljp7F08A300
   lw    $t4, 0x3c($v0)
  mtc1  $at, $f10
  nop   
  c.lt.s $f10, $f2
  nop   
  bc1fl .Ljp7F08A30C
   lw    $v1, 0x50($sp)
  lw    $t4, 0x3c($v0)
.Ljp7F08A300:
  addiu $t5, $t4, 1
  sw    $t5, 0x3c($v0)
  lw    $v1, 0x50($sp)
.Ljp7F08A30C:
  mtc1  $zero, $f12
  lui   $v0, %hi(pPlayer) # $v0, 0x8008
  beqz  $v1, .Ljp7F08A358
   nop   
  lw    $v0, %lo(pPlayer)($v0)
  lwc1  $f6, 0x3c($sp)
  lwc1  $f0, 0xe0($v0)
  lwc1  $f2, 0x2a40($v0)
  mul.s $f16, $f0, $f2
  c.le.s $f6, $f16
  nop   
  bc1f  .Ljp7F08A358
   nop   
  div.s $f4, $f6, $f2
  sub.s $f18, $f0, $f4
  swc1  $f18, 0xe0($v0)
  lui   $v0, %hi(pPlayer) # $v0, 0x8008
  b     .Ljp7F08A4CC
   lw    $v0, %lo(pPlayer)($v0)
.Ljp7F08A358:
  lui   $v0, %hi(pPlayer) # $v0, 0x8008
  beqz  $v1, .Ljp7F08A39C
   lw    $v0, %lo(pPlayer)($v0)
  lwc1  $f8, 0xe0($v0)
  lwc1  $f10, 0x2a40($v0)
  lwc1  $f6, 0x3c($sp)
  li    $at, 0x3F800000 # 1.000000
  div.s $f16, $f8, $f10
  lui   $t6, %hi(pPlayer) # $t6, 0x8008
  mtc1  $at, $f18
  sub.s $f4, $f6, $f16
  swc1  $f4, 0x3c($sp)
  swc1  $f12, 0xe0($v0)
  lw    $t6, %lo(pPlayer)($t6)
  lui   $v0, %hi(pPlayer) # $v0, 0x8008
  swc1  $f18, 0x2a40($t6)
  lw    $v0, %lo(pPlayer)($v0)
.Ljp7F08A39C:
  lwc1  $f8, 0x3c($sp)
  lwc1  $f10, 0x2a3c($v0)
  lwc1  $f16, 0xdc($v0)
  div.s $f6, $f8, $f10
  sub.s $f4, $f16, $f6
  swc1  $f4, 0xdc($v0)
  lui   $v0, %hi(pPlayer) # $v0, 0x8008
  lw    $v0, %lo(pPlayer)($v0)
  lwc1  $f18, 0xdc($v0)
  c.le.s $f18, $f12
  nop   
  bc1fl .Ljp7F08A4D0
   lwc1  $f8, 0xf4($v0)
  jal   getPlayerCount
   nop   
  slti  $at, $v0, 2
  bnez  $at, .Ljp7F08A4B8
   nop   
  jal   get_cur_playernum
   nop   
  sw    $v0, 0x2c($sp)
  jal   get_scenario
   sw    $zero, 0x28($sp)
  li    $at, 3
  bne   $v0, $at, .Ljp7F08A418
   nop   
  jal   checkforgoldengun
   nop   
  beqz  $v0, .Ljp7F08A418
   li    $t7, 1
  sw    $t7, 0x28($sp)
.Ljp7F08A418:
  jal   drop_inventory
   nop   
  lw    $t8, 0x2c($sp)
  lw    $t9, 0x4c($sp)
  beq   $t8, $t9, .Ljp7F08A438
   nop   
  jal   increment_num_deaths
   nop   
.Ljp7F08A438:
  jal   set_cur_player
   lw    $a0, 0x4c($sp)
  lw    $t0, 0x2c($sp)
  lw    $t1, 0x4c($sp)
  bne   $t0, $t1, .Ljp7F08A460
   nop   
  jal   increment_num_suicides_display_MP
   nop   
  b     .Ljp7F08A47C
   nop   
.Ljp7F08A460:
  jal   increment_num_kills_display_text_in_MP
   nop   
  lw    $t2, 0x28($sp)
  beqz  $t2, .Ljp7F08A47C
   nop   
  jal   increment_num_times_killed_MwtGC
   nop   
.Ljp7F08A47C:
  jal   set_cur_player
   lw    $a0, 0x2c($sp)
  lw    $t3, 0x4c($sp)
  lw    $t5, 0x2c($sp)
  lui   $t8, %hi(player1_player_data) # $t8, 0x8008
  sll   $t4, $t3, 3
  subu  $t4, $t4, $t3
  sll   $t4, $t4, 4
  sll   $t6, $t5, 2
  addu  $t7, $t4, $t6
  addiu $t8, %lo(player1_player_data) # addiu $t8, $t8, -0x60a0
  addu  $v0, $t7, $t8
  lw    $t9, 0x24($v0)
  addiu $t0, $t9, 1
  sw    $t0, 0x24($v0)
.Ljp7F08A4B8:
  jal   kill_current_player
   nop   
  lui   $v0, %hi(pPlayer) # $v0, 0x8008
  mtc1  $zero, $f12
  lw    $v0, %lo(pPlayer)($v0)
.Ljp7F08A4CC:
  lwc1  $f8, 0xf4($v0)
.Ljp7F08A4D0:
  lwc1  $f10, 0x44($sp)
  lui   $t1, %hi(pPlayer) # $t1, 0x8008
  c.lt.s $f8, $f12
  nop   
  bc1fl .Ljp7F08A520
   swc1  $f12, 0xf4($v0)
  add.s $f16, $f10, $f10
  lwc1  $f6, 0x180($v0)
  add.s $f4, $f6, $f16
  swc1  $f4, 0x180($v0)
  lwc1  $f18, 0x48($sp)
  lui   $v0, %hi(pPlayer) # $v0, 0x8008
  lw    $v0, %lo(pPlayer)($v0)
  add.s $f8, $f18, $f18
  lwc1  $f10, 0x188($v0)
  add.s $f6, $f10, $f8
  swc1  $f6, 0x188($v0)
  lui   $v0, %hi(pPlayer) # $v0, 0x8008
  lw    $v0, %lo(pPlayer)($v0)
  swc1  $f12, 0xf4($v0)
.Ljp7F08A520:
  lw    $t1, %lo(pPlayer)($t1)
  jal   get_controls_locked_flag
   swc1  $f12, 0xf8($t1)
  bnez  $v0, .Ljp7F08A544
   lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 68
  jal   play_sfx_a1
   move  $a2, $zero
.Ljp7F08A544:
  lw    $ra, 0x14($sp)
.Ljp7F08A548:
  addiu $sp, $sp, 0x40
  jr    $ra
   nop    
");
#endif

#endif



asm(R"
glabel sub_GAME_7F089E4C
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  swc1  $f12, 0x28($sp)
  swc1  $f14, 0x2c($sp)
  sw    $a2, 0x30($sp)
  sw    $a3, 0x34($sp)
  jal   sinf
   lwc1  $f12, 0x2c($sp)
  swc1  $f0, 0x20($sp)
  jal   cosf
   lwc1  $f12, 0x2c($sp)
  lw    $t6, 0x34($sp)
  mfc1  $a2, $f0
  lwc1  $f12, 0x28($sp)
  lwc1  $f14, 0x20($sp)
  lw    $a3, 0x30($sp)
  jal   record_damage_kills
   sw    $t6, 0x10($sp)
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

#ifdef VERSION_US
asm(R"
glabel check_if_bond_is_invincible
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  lw    $v0, 0xf4($t6)
  slti  $t7, $v0, 0
  jr    $ra
   xori  $v0, $t7, 1
");

#ifdef VERSION_JP
asm(R"
glabel check_if_bond_is_invincible
  lui   $t6, %hi(pPlayer) # $t6, 0x8008
  lw    $t6, %lo(pPlayer)($t6)
  mtc1  $zero, $f6
  move  $v0, $zero
  lwc1  $f4, 0xf4($t6)
  c.le.s $f6, $f4
  nop   
  bc1f  .Ljp7F08A5D4
   nop   
  li    $v0, 1
.Ljp7F08A5D4:
  jr    $ra
   nop   
");
#endif

#endif

#ifdef VERSION_US
int check_if_healthbar_timer_greater_than_0(void) {
  return 0 < pPlayer->healthshowtime;
}
#endif
#ifdef VERSION_JP
asm(R"
glabel check_if_healthbar_timer_greater_than_0
  lui   $t6, %hi(pPlayer) # $t6, 0x8008
  lw    $t6, %lo(pPlayer)($t6)
  mtc1  $zero, $f4
  move  $v0, $zero
  lwc1  $f6, 0xf8($t6)
  c.lt.s $f4, $f6
  nop   
  bc1f  .Ljp7F08A604
   nop   
  li    $v0, 1
.Ljp7F08A604:
  jr    $ra
   nop    
");
#endif




asm(R"
glabel get_BONDdata_bondfadefracnew
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  jr    $ra
   lwc1  $f0, 0x19c($t6)
");






asm(R"
.late_rodata
glabel twopi_800552B4
.word 0x40c90fdb /*6.2831855*/
.text
glabel get_curplay_horizontal_rotation_in_degrees
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f2
  lwc1  $f4, 0x148($t6)
  lui   $at, %hi(twopi_800552B4)
  lwc1  $f8, %lo(twopi_800552B4)($at)
  sub.s $f6, $f2, $f4
  mul.s $f10, $f6, $f8
  jr    $ra
   div.s $f0, $f10, $f2
");






asm(R"
.late_rodata
glabel D_800552B8
.word 0x40c90fdb /*6.2831855*/
.text
glabel get_curplay_vertical_rotation_in_degrees
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  lui   $at, %hi(D_800552B8)
  lwc1  $f6, %lo(D_800552B8)($at)
  lwc1  $f4, 0x158($t6)
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f10
  mul.s $f8, $f4, $f6
  jr    $ra
   div.s $f0, $f8, $f10
");


int sub_GAME_7F089F38(void) {
  return pPlayer->field_D0;
}







asm(R"
glabel set_bondata_invincible_flag
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  jr    $ra
   sb    $a0, 0x12b6($t6)
");






asm(R"
glabel get_bondata_invincible_flag
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  jr    $ra
   lbu   $v0, 0x12b6($t6)
");



void set_invisible_to_guards_flag(int param_1) {
  invisible_to_guards_flag = param_1;
}

int get_invisible_to_guards_flag(void) {
  return invisible_to_guards_flag;
}

void set_obj_collision_flag(int flag) {
  obj_collision_flag = flag;
}

int get_obj_collision_flag(void) {
  return obj_collision_flag;
}







asm(R"
glabel get_cur_players_room
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  li    $at, 1
  lw    $t6, ($v1)
  bnel  $t6, $at, .L7F089FC8
   lw    $t7, 0x4d8($v1)
  lw    $a0, 0x34($v1)
  beql  $a0, $zero, .L7F089FC8
   lw    $t7, 0x4d8($v1)
  jr    $ra
   lbu   $v0, 3($a0)

  lw    $t7, 0x4d8($v1)
.L7F089FC8:
  lbu   $v0, 3($t7)
  jr    $ra
   nop   
");






asm(R"
glabel get_BONDdata_position
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  li    $at, 1
  lw    $t6, ($v1)
  addiu $v0, $v1, 0x4b4
  bne   $t6, $at, .L7F089FF8
   nop   
  jr    $ra
   addiu $v0, $v1, 4

.L7F089FF8:
  jr    $ra
   nop   
");






asm(R"
glabel get_BONDdata_position3
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  li    $at, 1
  lw    $t6, ($v1)
  addiu $v0, $v1, 0x4a4
  bne   $t6, $at, .L7F08A024
   nop   
  jr    $ra
   addiu $v0, $v1, 0x28

.L7F08A024:
  jr    $ra
   nop   
");






asm(R"
glabel get_BONDdata_field408
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  jr    $ra
   addiu $v0, $v0, 0x408
");






asm(R"
glabel sub_GAME_7F08A03C
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a0, 0x20($sp)
  jal   sub_GAME_7F09B15C
   sw    $a1, 0x24($sp)
  lw    $t6, 0x20($sp)
  sw    $v0, 0x1c($sp)
  lw    $a0, 4($t6)
  beqz  $a0, .L7F08A06C
   nop   
  jal   set_or_unset_GUARDdata_flag
   lw    $a1, 0x24($sp)
.L7F08A06C:
  lui   $a0, %hi(ptr_playerstank)
  lw    $a0, %lo(ptr_playerstank)($a0)
  beql  $a0, $zero, .L7F08A088
   lw    $t8, 0x1c($sp)
  jal   sub_GAME_7F04F218
   lw    $a1, 0x24($sp)
  lw    $t8, 0x1c($sp)
.L7F08A088:
  lui   $t0, %hi(players_p1)
  lw    $t7, 0x24($sp)
  sll   $t9, $t8, 2
  addu  $t0, $t0, $t9
  lw    $t0, %lo(players_p1)($t0)
  sw    $t7, 0xac($t0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");






asm(R"
glabel sub_GAME_7F08A0B0
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a1, 0x24($sp)
  sw    $a2, 0x28($sp)
  jal   sub_GAME_7F09B15C
   sw    $a3, 0x2c($sp)
  lui   $a0, %hi(players_p1)
  addiu $a0, %lo(players_p1) # addiu $a0, $a0, -0x6120
  sll   $t6, $v0, 2
  addu  $t7, $a0, $t6
  lw    $t8, ($t7)
  lw    $t9, 0xac($t8)
  beql  $t9, $zero, .L7F08A188
   lw    $t6, 0x28($sp)
  jal   getPlayerCount
   sw    $v0, 0x1c($sp)
  lui   $a0, %hi(players_p1)
  li    $a1, 1
  addiu $a0, %lo(players_p1) # addiu $a0, $a0, -0x6120
  beq   $v0, $a1, .L7F08A118
   lw    $v1, 0x1c($sp)
  sll   $t0, $v1, 2
  addu  $t1, $a0, $t0
  lw    $t2, ($t1)
  lw    $t3, 0xd8($t2)
  bnez  $t3, .L7F08A184
.L7F08A118:
   sll   $t4, $v1, 2
  addu  $v0, $a0, $t4
  lw    $t5, ($v0)
  lw    $t8, 0x28($sp)
  lw    $t6, ($t5)
  beq   $a1, $t6, .L7F08A184
   li    $t7, 4
  sw    $t7, ($t8)
  lw    $t9, ($v0)
  lw    $t1, 0x24($sp)
  addiu $t0, $t9, 0xb0
  sw    $t0, ($t1)
  lw    $t2, ($v0)
  lw    $t3, 0x30($sp)
  lwc1  $f4, 0x70($t2)
  swc1  $f4, ($t3)
  jal   sub_GAME_7F089780
   lw    $a0, ($v0)
  lw    $t4, 0x30($sp)
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f10
  lwc1  $f6, ($t4)
  lw    $t5, 0x2c($sp)
  add.s $f8, $f0, $f6
  add.s $f16, $f8, $f10
  b     .L7F08A18C
   swc1  $f16, ($t5)
.L7F08A184:
  lw    $t6, 0x28($sp)
.L7F08A188:
  sw    $zero, ($t6)
.L7F08A18C:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");






asm(R"
glabel sub_GAME_7F08A19C
  lui   $t6, %hi(in_tank_flag) 
  lw    $t6, %lo(in_tank_flag)($t6)
  addiu $sp, $sp, -0x18
  li    $at, 1
  bne   $t6, $at, .L7F08A1DC
   sw    $ra, 0x14($sp)
  lui   $v1, %hi(pPlayer)
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $v0, ($v1)
  lui   $a2, %hi(D_80036464)
  lw    $a2, %lo(D_80036464)($a2)
  addiu $a0, $v0, 0xb0
  jal   sub_GAME_7F07C888
   addiu $a1, $v0, 0x48c
  b     .L7F08A268
   lw    $ra, 0x14($sp)
.L7F08A1DC:
  lui   $v1, %hi(pPlayer)
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $v0, ($v1)
  lwc1  $f4, 0x48c($v0)
  lwc1  $f6, 0x4b0($v0)
  add.s $f8, $f4, $f6
  swc1  $f8, 0xb0($v0)
  lw    $v0, ($v1)
  lwc1  $f10, 0x494($v0)
  swc1  $f10, 0xb4($v0)
  lw    $v0, ($v1)
  lwc1  $f16, 0x48c($v0)
  swc1  $f16, 0xb8($v0)
  lw    $v0, ($v1)
  lwc1  $f18, 0x494($v0)
  lwc1  $f4, 0x4b0($v0)
  add.s $f6, $f18, $f4
  swc1  $f6, 0xbc($v0)
  lw    $v0, ($v1)
  lwc1  $f8, 0x48c($v0)
  lwc1  $f10, 0x4b0($v0)
  sub.s $f16, $f8, $f10
  swc1  $f16, 0xc0($v0)
  lw    $v0, ($v1)
  lwc1  $f18, 0x494($v0)
  swc1  $f18, 0xc4($v0)
  lw    $v0, ($v1)
  lwc1  $f4, 0x48c($v0)
  swc1  $f4, 0xc8($v0)
  lw    $v0, ($v1)
  lwc1  $f6, 0x494($v0)
  lwc1  $f8, 0x4b0($v0)
  sub.s $f10, $f6, $f8
  swc1  $f10, 0xcc($v0)
  lw    $ra, 0x14($sp)
.L7F08A268:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");






asm(R"
glabel sub_GAME_7F08A274
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a1, 0x1c($sp)
  sw    $a2, 0x20($sp)
  jal   sub_GAME_7F09B15C
   sw    $a3, 0x24($sp)
  lui   $t7, %hi(players_p1) 
  addiu $t7, %lo(players_p1) # addiu $t7, $t7, -0x6120
  sll   $t6, $v0, 2
  addu  $v1, $t6, $t7
  lw    $t8, ($v1)
  lw    $t9, 0x1c($sp)
  lwc1  $f4, 0x4b0($t8)
  swc1  $f4, ($t9)
  jal   sub_GAME_7F089780
   lw    $a0, ($v1)
  li    $at, 0x41F00000 # 30.000000
  mtc1  $at, $f2
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f6
  lw    $t0, 0x20($sp)
  add.s $f8, $f0, $f6
  sub.s $f10, $f8, $f2
  swc1  $f10, ($t0)
  lw    $t1, 0x24($sp)
  swc1  $f2, ($t1)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");






asm(R"
glabel get_BONDdata_watch_health
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  jr    $ra
   lwc1  $f0, 0xdc($t6)
");



float get_BONDdata_watch_armor(void) {
  return pPlayer->bondarmour;
}






asm(R"
glabel add_BONDdata_watch_armor
  lui   $v0, %hi(pPlayersPerm)
  lw    $v0, %lo(pPlayersPerm)($v0)
  lui   $t6, %hi(pPlayer) 
  lwc1  $f4, 0x40($v0)
  add.s $f6, $f4, $f12
  swc1  $f6, 0x40($v0)
  lw    $t6, %lo(pPlayer)($t6)
  jr    $ra
   swc1  $f12, 0xe0($t6)
");

#ifdef VERSION_US
asm(R"
glabel reset_intro_camera_message_dialogs_for_BONDdata
  lui   $v0, %hi(pPlayer)
  addiu $v0, %lo(pPlayer) # addiu $v0, $v0, -0x5f50
  lw    $t6, ($v0)
  li    $t7, -1
  lui   $at, %hi(display_statusbar)
  sw    $zero, 0x11d8($t6)
  lw    $t8, ($v0)
  lui   $t9, %hi(ptrFirstFontTableSmall) 
  lui   $t0, %hi(ptrSecondFontTableSmall) 
  sw    $t7, 0x11dc($t8)
  sw    $zero, %lo(display_statusbar)($at)
  lw    $t9, %lo(ptrFirstFontTableSmall)($t9)
  lui   $at, %hi(status_bar_text_buffer_index)
  sw    $zero, %lo(status_bar_text_buffer_index)($at)
  lui   $at, %hi(copy_1stfonttable)
  lw    $t0, %lo(ptrSecondFontTableSmall)($t0)
  sw    $t9, %lo(copy_1stfonttable)($at)
  lui   $at, %hi(copy_2ndfonttable)
  jr    $ra
   sw    $t0, %lo(copy_2ndfonttable)($at)
");

#ifdef VERSION_JP
asm(R"
glabel reset_intro_camera_message_dialogs_for_BONDdata
  lui   $v0, %hi(pPlayer) # $v0, 0x8008
  addiu $v0, %lo(pPlayer) # addiu $v0, $v0, -0x5ee0
  lw    $t6, ($v0)
  li    $t7, -1
  lui   $at, %hi(display_statusbar) # $at, 0x8003
  sw    $zero, 0x11d8($t6)
  lw    $t8, ($v0)
  sw    $t7, 0x11dc($t8)
  sw    $zero, %lo(display_statusbar)($at)
  lui   $at, %hi(status_bar_text_buffer_index)
  jr    $ra
   sw    $zero, %lo(status_bar_text_buffer_index)($at)
");
#endif

#endif

asm(R"
glabel unset_flags_in_BONDdata_stationary_intro_cam
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  not   $t7, $a0
  lw    $t6, 0x11d8($v0)
  and   $t8, $t6, $t7
  jr    $ra
   sw    $t8, 0x11d8($v0)
");

asm(R"
glabel set_flags_in_BONDdata_stationary_intro_cam
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lw    $t6, 0x11d8($v0)
  or    $t7, $t6, $a0
  jr    $ra
   sw    $t7, 0x11d8($v0)
");

#ifdef VERSION_US
void sub_GAME_7F08A3B4(int arg0, int arg1) {
  copy_2ndfonttable = arg0;
  copy_1stfonttable = arg1;
}
#endif

#ifdef VERSION_US
asm(R"
glabel display_string_in_lower_left_corner
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  jal   getPlayerCount
   sw    $a0, 0x28($sp)
  li    $at, 1
  bne   $v0, $at, .L7F08A460
   lui   $a3, %hi(display_statusbar)
  addiu $a3, %lo(display_statusbar) # addiu $a3, $a3, 0x689c
  lw    $v1, ($a3)
  lui   $t9, %hi(dword_CODE_bss_80079A28) 
  lui   $t6, %hi(status_bar_text_buffer_index) 
  slti  $at, $v1, 5
  beqz  $at, .L7F08A4D4
   addiu $t9, %lo(dword_CODE_bss_80079A28) # addiu $t9, $t9, -0x65d8
  lw    $t6, %lo(status_bar_text_buffer_index)($t6)
  li    $at, 5
  lw    $a1, 0x28($sp)
  addu  $v0, $t6, $v1
  div   $zero, $v0, $at
  mfhi  $t7
  sll   $t8, $t7, 2
  subu  $t8, $t8, $t7
  sll   $t8, $t8, 3
  addu  $t8, $t8, $t7
  sll   $t8, $t8, 2
  addu  $t8, $t8, $t7
  addu  $a0, $t8, $t9
  sw    $a0, 0x18($sp)
  jal   something_with_strings
   li    $a2, 100
  lui   $a3, %hi(display_statusbar)
  addiu $a3, %lo(display_statusbar) # addiu $a3, $a3, 0x689c
  lw    $t0, ($a3)
  lw    $a0, 0x18($sp)
  addiu $t1, $t0, 1
  sw    $t1, ($a3)
  b     .L7F08A4D4
   sb    $zero, 0x64($a0)
.L7F08A460:
  jal   get_cur_playernum
   nop   
  sll   $t2, $v0, 2
  subu  $t2, $t2, $v0
  sll   $t2, $t2, 3
  addu  $t2, $t2, $v0
  sll   $t2, $t2, 2
  lui   $t3, %hi(dword_CODE_bss_80079A28) 
  addiu $t3, %lo(dword_CODE_bss_80079A28) # addiu $t3, $t3, -0x65d8
  addu  $t2, $t2, $v0
  sw    $v0, 0x20($sp)
  addu  $a0, $t2, $t3
  lw    $a1, 0x28($sp)
  jal   something_with_strings
   li    $a2, 100
  lw    $t4, 0x20($sp)
  lui   $t7, %hi(pPlayer) 
  lw    $t7, %lo(pPlayer)($t7)
  sll   $t5, $t4, 2
  subu  $t5, $t5, $t4
  sll   $t5, $t5, 3
  addu  $t5, $t5, $t4
  sll   $t5, $t5, 2
  lui   $at, %hi(dword_CODE_bss_80079A28+100)
  addu  $t5, $t5, $t4
  addu  $at, $at, $t5
  sb    $zero, %lo(dword_CODE_bss_80079A28+100)($at)
  li    $t6, 120
  sw    $t6, 0x11dc($t7)
.L7F08A4D4:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

#ifdef VERSION_JP
//JP FIXME hardcoded pointer values
//id/find in data
//80079c80
//80079c68
asm(R"
glabel display_string_in_lower_left_corner
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  sw    $a0, 0x28($sp)
  sw    $a1, 0x2c($sp)
  jal   getPlayerCount
   sw    $a2, 0x30($sp)
  li    $at, 1
  bne   $v0, $at, .L7F08AB98
   lui   $t0, %hi(display_statusbar) # $t0, 0x8003
  addiu $t0, %lo(display_statusbar) # addiu $t0, $t0, 0x68dc
  lw    $v0, ($t0)
  lui   $t9, %hi(dword_CODE_bss_80079A28) # $t9, 0x8008
  lui   $t6, %hi(status_bar_text_buffer_index) # $t6, 0x8003
  slti  $at, $v0, 5
  beqz  $at, .L7F08AC30
   addiu $t9, %lo(dword_CODE_bss_80079A28) # addiu $t9, $t9, -0x6598
  lw    $t6, %lo(status_bar_text_buffer_index)($t6)
  li    $at, 5
  lw    $a1, 0x28($sp)
  addu  $a3, $t6, $v0
  div   $zero, $a3, $at
  mfhi  $t7
  sll   $t8, $t7, 2
  subu  $t8, $t8, $t7
  sll   $t8, $t8, 3
  addu  $t8, $t8, $t7
  sll   $t8, $t8, 2
  addu  $t8, $t8, $t7
  addu  $a0, $t8, $t9
  sw    $a0, 0x18($sp)
  sw    $t7, 0x24($sp)
  jal   something_with_strings
   li    $a2, 100
  lw    $a3, 0x24($sp)
  lw    $a0, 0x18($sp)
  lw    $t1, 0x2c($sp)
  lui   $at, %hi(0x80079C80)
  sll   $v1, $a3, 2
  addu  $at, $at, $v1
  sb    $zero, 0x64($a0)
  lw    $t2, 0x30($sp)
  sw    $t1, %lo(0x80079C80)($at)
  lui   $at, %hi(0x80079C68)
  lui   $t0, %hi(display_statusbar) # $t0, 0x8003
  addu  $at, $at, $v1
  addiu $t0, %lo(display_statusbar) # addiu $t0, $t0, 0x68dc
  sw    $t2, %lo(0x80079C68)($at)
  lw    $t3, ($t0)
  addiu $t4, $t3, 1
  b     .L7F08AC30
   sw    $t4, ($t0)
.L7F08AB98:
  jal   get_cur_playernum
   nop   
  sll   $t5, $v0, 2
  subu  $t5, $t5, $v0
  sll   $t5, $t5, 3
  addu  $t5, $t5, $v0
  sll   $t5, $t5, 2
  lui   $t6, %hi(dword_CODE_bss_80079A28) # $t6, 0x8008
  addiu $t6, %lo(dword_CODE_bss_80079A28) # addiu $t6, $t6, -0x6598
  addu  $t5, $t5, $v0
  addu  $a0, $t5, $t6
  lw    $a1, 0x28($sp)
  li    $a2, 100
  jal   something_with_strings
   sw    $v0, 0x20($sp)
  lw    $a3, 0x20($sp)
  lui   $at, %hi(dword_CODE_bss_80079A28+0x64) #dword_CODE_bss_80079A28
  lw    $t8, 0x2c($sp)
  sll   $t7, $a3, 2
  subu  $t7, $t7, $a3
  sll   $t7, $t7, 3
  addu  $t7, $t7, $a3
  sll   $t7, $t7, 2
  addu  $t7, $t7, $a3
  addu  $at, $at, $t7
  sb    $zero, %lo(dword_CODE_bss_80079A28+0x64)($at)
  lui   $at, 0x8008
  sll   $v1, $a3, 2
  addu  $at, $at, $v1
  lw    $t9, 0x30($sp)
  lui   $t2, %hi(pPlayer) # $t2, 0x8008
  sw    $t8, -0x6380($at)
  lw    $t2, %lo(pPlayer)($t2)
  lui   $at, 0x8008
  addu  $at, $at, $v1
  li    $t1, 120
  sw    $t9, -0x6398($at)
  sw    $t1, 0x11dc($t2)
.L7F08AC30:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");
#endif

#endif

#ifdef VERSION_JP
void jp_display_string_in_lower_left_corner(char *string)
{
  display_string_in_lower_left_corner(string, ptrSecondFontTableSmall,
                                      ptrFirstFontTableSmall);
}
#endif



asm(R"
glabel sub_GAME_7F08A4E4
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lw    $t6, 0x11d8($v0)
  bnezl $t6, .L7F08A5F0
   lw    $ra, 0x14($sp)
  lw    $t7, 0x29c4($v0)
  bnezl $t7, .L7F08A5F0
   lw    $ra, 0x14($sp)
  lw    $v1, 0x11dc($v0)
  lui   $t8, %hi(clock_timer) 
  bltz  $v1, .L7F08A5A0
   nop   
  lw    $t8, %lo(clock_timer)($t8)
  subu  $t9, $v1, $t8
  jal   getPlayerCount
   sw    $t9, 0x11dc($v0)
  li    $at, 1
  bne   $v0, $at, .L7F08A5A0
   lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lw    $v1, 0x11dc($v0)
  bgez  $v1, .L7F08A580
   nop   
  lui   $v0, %hi(status_bar_text_buffer_index)
  addiu $v0, %lo(status_bar_text_buffer_index) # addiu $v0, $v0, 0x6898
  lw    $t0, ($v0)
  li    $at, 5
  lui   $t3, %hi(display_statusbar) 
  addiu $t1, $t0, 1
  div   $zero, $t1, $at
  mfhi  $t2
  sw    $t2, ($v0)
  lw    $t3, %lo(display_statusbar)($t3)
  lui   $at, %hi(display_statusbar)
  addiu $t4, $t3, -1
  b     .L7F08A5A0
   sw    $t4, %lo(display_statusbar)($at)
.L7F08A580:
  lui   $t5, %hi(display_statusbar) 
  lw    $t5, %lo(display_statusbar)($t5)
  slti  $at, $t5, 2
  bnez  $at, .L7F08A5A0
   slti  $at, $v1, 0x1f
  bnez  $at, .L7F08A5A0
   li    $t6, 30
  sw    $t6, 0x11dc($v0)
.L7F08A5A0:
  jal   getPlayerCount
   nop   
  li    $at, 1
  bne   $v0, $at, .L7F08A5EC
   lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lui   $v1, %hi(display_statusbar)
  lw    $t7, 0x11dc($v0)
  bgezl $t7, .L7F08A5F0
   lw    $ra, 0x14($sp)
  lw    $v1, %lo(display_statusbar)($v1)
  blez  $v1, .L7F08A5EC
   slti  $at, $v1, 2
  bnez  $at, .L7F08A5E8
   li    $t9, 120
  li    $t8, 30
  b     .L7F08A5EC
   sw    $t8, 0x11dc($v0)
.L7F08A5E8:
  sw    $t9, 0x11dc($v0)
.L7F08A5EC:
  lw    $ra, 0x14($sp)
.L7F08A5F0:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

#ifdef VERSION_US
asm(R"
glabel sub_GAME_7F08A5FC
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  addiu $sp, $sp, -0x60
  sw    $ra, 0x34($sp)
  sw    $a0, 0x60($sp)
  lw    $t6, 0x11d8($v0)
  bnezl $t6, .L7F08A8F0
   lw    $ra, 0x34($sp)
  lw    $t7, 0x11dc($v0)
  bltzl $t7, .L7F08A8F0
   lw    $ra, 0x34($sp)
  lw    $t8, 0x29c4($v0)
  bnezl $t8, .L7F08A8F0
   lw    $ra, 0x34($sp)
  jal   getPlayerCount
   sw    $zero, 0x5c($sp)
  li    $at, 1
  bne   $v0, $at, .L7F08A684
   lw    $v1, 0x5c($sp)
  lui   $t9, %hi(status_bar_text_buffer_index) 
  lw    $t9, %lo(status_bar_text_buffer_index)($t9)
  lui   $t1, %hi(dword_CODE_bss_80079A28)
  sll   $t0, $t9, 2
  subu  $t0, $t0, $t9
  sll   $t0, $t0, 3
  addu  $t0, $t0, $t9
  sll   $t0, $t0, 2
  addu  $t0, $t0, $t9
  addu  $t1, $t1, $t0
  lbu   $t1, %lo(dword_CODE_bss_80079A28)($t1)
  beqz  $t1, .L7F08A6AC
   nop   
  b     .L7F08A6AC
   li    $v1, 1
.L7F08A684:
  lui   $t2, %hi(pPlayer) 
  lw    $t2, %lo(pPlayer)($t2)
  lw    $t3, 0x11dc($t2)
  bltz  $t3, .L7F08A6AC
   nop   
  jal   get_cur_playernum
   nop   
  lui   $at, %hi(status_bar_text_buffer_index)
  sw    $v0, %lo(status_bar_text_buffer_index)($at)
  li    $v1, 1
.L7F08A6AC:
  beql  $v1, $zero, .L7F08A8F0
   lw    $ra, 0x34($sp)
  jal   microcode_constructor
   lw    $a0, 0x60($sp)
  lui   $t4, %hi(status_bar_text_buffer_index) 
  lw    $t4, %lo(status_bar_text_buffer_index)($t4)
  lui   $t7, %hi(copy_1stfonttable) 
  lw    $t7, %lo(copy_1stfonttable)($t7)
  sll   $t5, $t4, 2
  subu  $t5, $t5, $t4
  sll   $t5, $t5, 3
  addu  $t5, $t5, $t4
  sll   $t5, $t5, 2
  lui   $t6, %hi(dword_CODE_bss_80079A28) 
  addiu $t6, %lo(dword_CODE_bss_80079A28) # addiu $t6, $t6, -0x65d8
  lui   $a3, %hi(copy_2ndfonttable)
  addu  $t5, $t5, $t4
  sw    $v0, 0x60($sp)
  sw    $zero, 0x44($sp)
  sw    $zero, 0x48($sp)
  addu  $a2, $t5, $t6
  lw    $a3, %lo(copy_2ndfonttable)($a3)
  addiu $a0, $sp, 0x48
  addiu $a1, $sp, 0x44
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t7, 0x10($sp)
  jal   getPlayerCount
   nop   
  slti  $at, $v0, 3
  beqz  $at, .L7F08A73C
   nop   
  jal   get_video2_settings_ulx
   nop   
  b     .L7F08A76C
   addiu $v1, $v0, 0x1e
.L7F08A73C:
  jal   get_cur_playernum
   nop   
  andi  $t8, $v0, 1
  beqz  $t8, .L7F08A760
   nop   
  jal   get_video2_settings_ulx
   nop   
  b     .L7F08A76C
   addiu $v1, $v0, 0xa
.L7F08A760:
  jal   get_video2_settings_ulx
   nop   
  addiu $v1, $v0, 0x1e
.L7F08A76C:
  lw    $t9, 0x44($sp)
  sw    $v1, 0x58($sp)
  addu  $t0, $v1, $t9
  jal   getPlayerCount
   sw    $t0, 0x50($sp)
  slti  $at, $v0, 3
  beqz  $at, .L7F08A818
   nop   
  jal   get_item_in_hand
   li    $a0, 1
  jal   get_ammo_type_for_weapon
   move  $a0, $v0
  bnez  $v0, .L7F08A7D8
   nop   
  jal   is_clock_drawn_onscreen
   nop   
  bnez  $v0, .L7F08A7D8
   nop   
  jal   get_video2_settings_uly
   nop   
  jal   get_video2_settings_height
   sh    $v0, 0x3e($sp)
  lh    $t1, 0x3e($sp)
  addu  $t2, $v0, $t1
  addiu $t3, $t2, -0xc
  b     .L7F08A7F8
   sw    $t3, 0x4c($sp)
.L7F08A7D8:
  jal   get_video2_settings_uly
   nop   
  jal   get_video2_settings_height
   sh    $v0, 0x3e($sp)
  lh    $t4, 0x3e($sp)
  addu  $t5, $v0, $t4
  addiu $t6, $t5, -0x28
  sw    $t6, 0x4c($sp)
.L7F08A7F8:
  jal   get_cur_playernum
   nop   
  li    $at, 1
  bne   $v0, $at, .L7F08A828
   lw    $t7, 0x4c($sp)
  addiu $t8, $t7, -8
  b     .L7F08A828
   sw    $t8, 0x4c($sp)
.L7F08A818:
  jal   get_video2_settings_uly
   nop   
  addiu $t9, $v0, 0x10
  sw    $t9, 0x4c($sp)
.L7F08A828:
  lw    $t0, 0x4c($sp)
  lw    $t1, 0x48($sp)
  addiu $t3, $sp, 0x4c
  sw    $t3, 0x10($sp)
  subu  $t2, $t0, $t1
  sw    $t2, 0x54($sp)
  lw    $a0, 0x60($sp)
  addiu $a1, $sp, 0x58
  addiu $a2, $sp, 0x54
  jal   draw_blackbox_to_screen
   addiu $a3, $sp, 0x50
  jal   get_video2_settings_txtClipW
   sw    $v0, 0x60($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x3c($sp)
  lui   $t4, %hi(status_bar_text_buffer_index) 
  lw    $t4, %lo(status_bar_text_buffer_index)($t4)
  lui   $t7, %hi(copy_2ndfonttable) 
  lui   $t8, %hi(copy_1stfonttable) 
  sll   $t5, $t4, 2
  subu  $t5, $t5, $t4
  sll   $t5, $t5, 3
  addu  $t5, $t5, $t4
  lw    $t8, %lo(copy_1stfonttable)($t8)
  lw    $t7, %lo(copy_2ndfonttable)($t7)
  lh    $t1, 0x3c($sp)
  sll   $t5, $t5, 2
  lui   $t6, %hi(dword_CODE_bss_80079A28) 
  lui   $t0, (0x646464FF >> 16) # lui $t0, 0x6464
  ori   $t0, (0x646464FF & 0xFFFF) # ori $t0, $t0, 0x64ff
  addiu $t6, %lo(dword_CODE_bss_80079A28) # addiu $t6, $t6, -0x65d8
  li    $t9, -1
  addu  $t5, $t5, $t4
  addu  $a3, $t5, $t6
  sw    $t9, 0x18($sp)
  sw    $t0, 0x1c($sp)
  lw    $a0, 0x60($sp)
  addiu $a1, $sp, 0x58
  addiu $a2, $sp, 0x54
  sw    $v0, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $zero, 0x2c($sp)
  sw    $t8, 0x14($sp)
  sw    $t7, 0x10($sp)
  jal   jp_text_write_stuff
   sw    $t1, 0x20($sp)
  jal   combiner_bayer_lod_perspective
   move  $a0, $v0
  sw    $v0, 0x60($sp)
  lw    $ra, 0x34($sp)
.L7F08A8F0:
  lw    $v0, 0x60($sp)
  addiu $sp, $sp, 0x60
  jr    $ra
   nop   
");

#ifdef VERSION_JP
asm(R"
glabel sub_GAME_7F08A5FC
  lui   $v0, %hi(pPlayer) # $v0, 0x8008
  lw    $v0, %lo(pPlayer)($v0)
  addiu $sp, $sp, -0x60
  sw    $ra, 0x34($sp)
  sw    $a0, 0x60($sp)
  lw    $t6, 0x11d8($v0)
  bnezl $t6, .Ljp7F08B0CC
   lw    $ra, 0x34($sp)
  lw    $t7, 0x11dc($v0)
  bltzl $t7, .Ljp7F08B0CC
   lw    $ra, 0x34($sp)
  lw    $t8, 0x29c4($v0)
  bnezl $t8, .Ljp7F08B0CC
   lw    $ra, 0x34($sp)
  jal   getPlayerCount
   sw    $zero, 0x5c($sp)
  li    $at, 1
  bne   $v0, $at, .Ljp7F08AE0C
   lw    $v1, 0x5c($sp)
  lui   $t9, %hi(status_bar_text_buffer_index) # $t9, 0x8003
  lw    $t9, %lo(status_bar_text_buffer_index)($t9)
  lui   $t2, %hi(dword_CODE_bss_80079A28)
  sll   $t1, $t9, 2
  subu  $t1, $t1, $t9
  sll   $t1, $t1, 3
  addu  $t1, $t1, $t9
  sll   $t1, $t1, 2
  addu  $t1, $t1, $t9
  addu  $t2, $t2, $t1
  lbu   $t2, %lo(dword_CODE_bss_80079A28)($t2)
  beqz  $t2, .Ljp7F08AE34
   nop   
  b     .Ljp7F08AE34
   li    $v1, 1
.Ljp7F08AE0C:
  lui   $t3, %hi(pPlayer) # $t3, 0x8008
  lw    $t3, %lo(pPlayer)($t3)
  lw    $t4, 0x11dc($t3)
  bltz  $t4, .Ljp7F08AE34
   nop   
  jal   get_cur_playernum
   nop   
  lui   $at, %hi(status_bar_text_buffer_index) # $at, 0x8003
  sw    $v0, %lo(status_bar_text_buffer_index)($at)
  li    $v1, 1
.Ljp7F08AE34:
  beql  $v1, $zero, .Ljp7F08B0CC
   lw    $ra, 0x34($sp)
  jal   microcode_constructor
   lw    $a0, 0x60($sp)
  lui   $v1, %hi(status_bar_text_buffer_index) # $v1, 0x8003
  lw    $v1, %lo(status_bar_text_buffer_index)($v1)
  lui   $t7, %hi(dword_CODE_bss_jp80079Cd8) 
  lui   $t6, %hi(dword_CODE_bss_80079A28) # $t6, 0x8008
  sll   $t5, $v1, 2
  subu  $t5, $t5, $v1
  sll   $t5, $t5, 3
  sll   $t0, $v1, 2
  addu  $t7, $t7, $t0
  addu  $t5, $t5, $v1
  lw    $t7, %lo(dword_CODE_bss_jp80079Cd8) ($t7)
  sll   $t5, $t5, 2
  lui   $a3, %hi(dword_CODE_bss_jp80079Cd8+0x18)
  addu  $a3, $a3, $t0
  addiu $t6, %lo(dword_CODE_bss_80079A28) # addiu $t6, $t6, -0x6598
  addu  $t5, $t5, $v1
  sw    $v0, 0x60($sp)
  sw    $zero, 0x44($sp)
  sw    $zero, 0x48($sp)
  addu  $a2, $t5, $t6
  lw    $a3, %lo(dword_CODE_bss_jp80079Cd8+0x18)($a3)
  addiu $a0, $sp, 0x48
  addiu $a1, $sp, 0x44
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t7, 0x10($sp)
  jal   getPlayerCount
   nop   
  slti  $at, $v0, 3
  beqz  $at, .Ljp7F08AED0
   nop   
  jal   get_video2_settings_ulx
   nop   
  b     .Ljp7F08AF00
   addiu $v1, $v0, 0x1e
.Ljp7F08AED0:
  jal   get_cur_playernum
   nop   
  andi  $t8, $v0, 1
  beqz  $t8, .Ljp7F08AEF4
   nop   
  jal   get_video2_settings_ulx
   nop   
  b     .Ljp7F08AF00
   addiu $v1, $v0, 0xa
.Ljp7F08AEF4:
  jal   get_video2_settings_ulx
   nop   
  addiu $v1, $v0, 0x1e
.Ljp7F08AF00:
  lw    $t9, 0x44($sp)
  sw    $v1, 0x58($sp)
  addu  $t1, $v1, $t9
  jal   getPlayerCount
   sw    $t1, 0x50($sp)
  slti  $at, $v0, 3
  beqz  $at, .Ljp7F08AFAC
   nop   
  jal   get_item_in_hand
   li    $a0, 1
  jal   get_ammo_type_for_weapon
   move  $a0, $v0
  bnez  $v0, .Ljp7F08AF6C
   nop   
  jal   is_clock_drawn_onscreen
   nop   
  bnez  $v0, .Ljp7F08AF6C
   nop   
  jal   get_video2_settings_uly
   nop   
  jal   get_video2_settings_height
   sh    $v0, 0x3e($sp)
  lh    $v1, 0x3e($sp)
  addu  $t3, $v0, $v1
  addiu $t4, $t3, -0xc
  b     .Ljp7F08AF8C
   sw    $t4, 0x4c($sp)
.Ljp7F08AF6C:
  jal   get_video2_settings_uly
   nop   
  jal   get_video2_settings_height
   sh    $v0, 0x3e($sp)
  lh    $v1, 0x3e($sp)
  addu  $t6, $v0, $v1
  addiu $t7, $t6, -0x28
  sw    $t7, 0x4c($sp)
.Ljp7F08AF8C:
  jal   get_cur_playernum
   nop   
  li    $at, 1
  bne   $v0, $at, .Ljp7F08AFF8
   lw    $t8, 0x4c($sp)
  addiu $t9, $t8, -8
  b     .Ljp7F08AFF8
   sw    $t9, 0x4c($sp)
.Ljp7F08AFAC:
  jal   get_video2_settings_uly
   nop   
  lui   $t2, %hi(j_text_trigger) # $t2, 0x8005
  lw    $t2, %lo(j_text_trigger)($t2)
  sll   $v1, $v0, 0x10
  sra   $t1, $v1, 0x10
  beqz  $t2, .Ljp7F08AFE8
   move  $v1, $t1
  jal   get_cur_playernum
   sh    $t1, 0x3e($sp)
  slti  $at, $v0, 2
  beqz  $at, .Ljp7F08AFE8
   lh    $v1, 0x3e($sp)
  b     .Ljp7F08AFEC
   li    $v0, 8
.Ljp7F08AFE8:
  move  $v0, $zero
.Ljp7F08AFEC:
  addu  $t3, $v0, $v1
  addiu $t4, $t3, 0x10
  sw    $t4, 0x4c($sp)
.Ljp7F08AFF8:
  lw    $t5, 0x4c($sp)
  lw    $t6, 0x48($sp)
  addiu $t8, $sp, 0x4c
  sw    $t8, 0x10($sp)
  subu  $t7, $t5, $t6
  sw    $t7, 0x54($sp)
  lw    $a0, 0x60($sp)
  addiu $a1, $sp, 0x58
  addiu $a2, $sp, 0x54
  jal   draw_blackbox_to_screen
   addiu $a3, $sp, 0x50
  jal   get_video2_settings_txtClipW
   sw    $v0, 0x60($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x3c($sp)
  lui   $v1, %hi(status_bar_text_buffer_index) # $v1, 0x8003
  lw    $v1, %lo(status_bar_text_buffer_index)($v1)
  lui   $t2, %hi(dword_CODE_bss_jp80079Cd8+0x18)
  lui   $t3, %hi(dword_CODE_bss_jp80079Cd8) 
  sll   $t9, $v1, 2
  subu  $t9, $t9, $v1
  sll   $t0, $v1, 2
  sll   $t9, $t9, 3
  addu  $t2, $t2, $t0
  addu  $t3, $t3, $t0
  addu  $t9, $t9, $v1
  lw    $t3, %lo(dword_CODE_bss_jp80079Cd8) ($t3)
  lw    $t2, %lo(dword_CODE_bss_jp80079Cd8+0x18)($t2)
  lh    $t6, 0x3c($sp)
  sll   $t9, $t9, 2
  lui   $t1, %hi(dword_CODE_bss_80079A28) # $t1, 0x8008
  lui   $t5, (0x646464FF >> 16) # lui $t5, 0x6464
  ori   $t5, (0x646464FF & 0xFFFF) # ori $t5, $t5, 0x64ff
  addiu $t1, %lo(dword_CODE_bss_80079A28) # addiu $t1, $t1, -0x6598
  li    $t4, -1
  addu  $t9, $t9, $v1
  addu  $a3, $t9, $t1
  sw    $t4, 0x18($sp)
  sw    $t5, 0x1c($sp)
  lw    $a0, 0x60($sp)
  addiu $a1, $sp, 0x58
  addiu $a2, $sp, 0x54
  sw    $v0, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $zero, 0x2c($sp)
  sw    $t3, 0x14($sp)
  sw    $t2, 0x10($sp)
  jal   jp_text_write_stuff
   sw    $t6, 0x20($sp)
  jal   combiner_bayer_lod_perspective
   move  $a0, $v0
  sw    $v0, 0x60($sp)
  lw    $ra, 0x34($sp)
.Ljp7F08B0CC:
  lw    $v0, 0x60($sp)
  addiu $sp, $sp, 0x60
  jr    $ra
   nop   
");
#endif

#endif

asm(R"
glabel sub_GAME_7F08A900
  li    $t6, -1
  lui   $at, %hi(upper_text_window_timer)
  sw    $t6, %lo(upper_text_window_timer)($at)
  lui   $at, %hi(display_upper_text_window)
  sw    $zero, %lo(display_upper_text_window)($at)
  lui   $at, %hi(upper_text_buffer_index)
  sw    $zero, %lo(upper_text_buffer_index)($at)
  lui   $at, %hi(D_800368B4)
  jr    $ra
   sw    $zero, %lo(D_800368B4)($at)
");

asm(R"
glabel sub_GAME_7F08A928
  lui   $v0, %hi(D_800368B4)
  addiu $v0, %lo(D_800368B4) # addiu $v0, $v0, 0x68b4
  lw    $t6, ($v0)
  not   $t7, $a0
  and   $t8, $t6, $t7
  jr    $ra
   sw    $t8, ($v0)
");

asm(R"
glabel sub_GAME_7F08A944
  lui   $v0, %hi(D_800368B4)
  addiu $v0, %lo(D_800368B4) # addiu $v0, $v0, 0x68b4
  lw    $t6, ($v0)
  or    $t7, $t6, $a0
  jr    $ra
   sw    $t7, ($v0)
");

asm(R"
glabel display_string_at_top_of_screen
  lui   $a3, %hi(display_upper_text_window)
  addiu $a3, %lo(display_upper_text_window) # addiu $a3, $a3, 0x68ac
  lw    $v1, ($a3)
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  slti  $at, $v1, 2
  beqz  $at, .L7F08A9E8
   move  $a1, $a0
  lui   $t6, %hi(upper_text_buffer_index) 
  lw    $t6, %lo(upper_text_buffer_index)($t6)
  lui   $t9, %hi(dword_CODE_bss_80079C70) 
  addiu $t9, %lo(dword_CODE_bss_80079C70) # addiu $t9, $t9, -0x6390
  addu  $v0, $t6, $v1
  bgez  $v0, .L7F08A9A4
   andi  $t7, $v0, 1
  beqz  $t7, .L7F08A9A4
   nop   
  addiu $t7, $t7, -2
.L7F08A9A4:
  sll   $t8, $t7, 2
  addu  $t8, $t8, $t7
  sll   $t8, $t8, 2
  subu  $t8, $t8, $t7
  sll   $t8, $t8, 3
  subu  $t8, $t8, $t7
  addu  $a0, $t8, $t9
  sw    $a0, 0x1c($sp)
  jal   something_with_strings
   li    $a2, 150
  lui   $a3, %hi(display_upper_text_window)
  addiu $a3, %lo(display_upper_text_window) # addiu $a3, $a3, 0x68ac
  lw    $t0, ($a3)
  lw    $a0, 0x1c($sp)
  addiu $t1, $t0, 1
  sw    $t1, ($a3)
  sb    $zero, 0x96($a0)
.L7F08A9E8:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F08A9F8
  lui   $t6, %hi(D_800368B4) 
  lw    $t6, %lo(D_800368B4)($t6)
  lui   $t7, %hi(pPlayer) 
  bnez  $t6, .L7F08AAE0
   nop   
  lw    $t7, %lo(pPlayer)($t7)
  lui   $v1, %hi(upper_text_window_timer)
  addiu $v1, %lo(upper_text_window_timer) # addiu $v1, $v1, 0x68b0
  lw    $t8, 0x29c4($t7)
  bnez  $t8, .L7F08AAE0
   nop   
  lw    $v0, ($v1)
  lui   $t9, %hi(clock_timer) 
  bltz  $v0, .L7F08AAB0
   nop   
  lw    $t9, %lo(clock_timer)($t9)
  lui   $a0, %hi(upper_text_buffer_index)
  addiu $a0, %lo(upper_text_buffer_index) # addiu $a0, $a0, 0x68a8
  subu  $t0, $v0, $t9
  sw    $t0, ($v1)
  bgez  $t0, .L7F08AA88
   move  $v0, $t0
  lw    $t1, ($a0)
  lui   $a1, %hi(display_upper_text_window)
  addiu $a1, %lo(display_upper_text_window) # addiu $a1, $a1, 0x68ac
  lw    $t4, ($a1)
  addiu $t2, $t1, 1
  bgez  $t2, .L7F08AA78
   andi  $t3, $t2, 1
  beqz  $t3, .L7F08AA78
   nop   
  addiu $t3, $t3, -2
.L7F08AA78:
  addiu $t5, $t4, -1
  sw    $t3, ($a0)
  b     .L7F08AAB0
   sw    $t5, ($a1)
.L7F08AA88:
  lui   $a1, %hi(display_upper_text_window)
  addiu $a1, %lo(display_upper_text_window) # addiu $a1, $a1, 0x68ac
  lw    $t6, ($a1)
  slti  $at, $t6, 2
  bnez  $at, .L7F08AAB0
   slti  $at, $v0, 0x3d
  bnez  $at, .L7F08AAB0
   nop   
  li    $v0, 60
  sw    $v0, ($v1)
.L7F08AAB0:
  lui   $a1, %hi(display_upper_text_window)
  bgez  $v0, .L7F08AAE0
   addiu $a1, %lo(display_upper_text_window) # addiu $a1, $a1, 0x68ac
  lw    $v0, ($a1)
  blez  $v0, .L7F08AAE0
   slti  $at, $v0, 2
  bnez  $at, .L7F08AADC
   li    $t9, 240
  li    $t8, 60
  jr    $ra
   sw    $t8, ($v1)

.L7F08AADC:
  sw    $t9, ($v1)
.L7F08AAE0:
  jr    $ra
   nop   
");

#ifdef VERSION_US
asm(R"
.late_rodata
glabel D_800552BC
.word 0x40490fdb /*3.1415927*/
.text
glabel sub_GAME_7F08AAE8
  lui   $t6, %hi(D_800368B4) 
  lw    $t6, %lo(D_800368B4)($t6)
  addiu $sp, $sp, -0xe8
  sw    $s0, 0x38($sp)
  move  $s0, $a0
  bnez  $t6, .L7F08AD1C
   sw    $ra, 0x3c($sp)
  lui   $t7, %hi(upper_text_window_timer) 
  lw    $t7, %lo(upper_text_window_timer)($t7)
  lui   $t8, %hi(upper_text_buffer_index) 
  bltz  $t7, .L7F08AD1C
   nop   
  lw    $t8, %lo(upper_text_buffer_index)($t8)
  lui   $t0, %hi(dword_CODE_bss_80079C70)
  lui   $t1, %hi(pPlayer) 
  sll   $t9, $t8, 2
  addu  $t9, $t9, $t8
  sll   $t9, $t9, 2
  subu  $t9, $t9, $t8
  sll   $t9, $t9, 3
  subu  $t9, $t9, $t8
  addu  $t0, $t0, $t9
  lbu   $t0, %lo(dword_CODE_bss_80079C70)($t0)
  beqz  $t0, .L7F08AD1C
   nop   
  lw    $t1, %lo(pPlayer)($t1)
  lw    $t2, 0x29c4($t1)
  bnez  $t2, .L7F08AD1C
   nop   
  jal   microcode_constructor
   nop   
  lui   $t3, %hi(upper_text_buffer_index) 
  lw    $t3, %lo(upper_text_buffer_index)($t3)
  lui   $t6, %hi(ptrFirstFontTableLarge) 
  lw    $t6, %lo(ptrFirstFontTableLarge)($t6)
  sll   $t4, $t3, 2
  addu  $t4, $t4, $t3
  sll   $t4, $t4, 2
  subu  $t4, $t4, $t3
  sll   $t4, $t4, 3
  lui   $t5, %hi(dword_CODE_bss_80079C70) 
  addiu $t5, %lo(dword_CODE_bss_80079C70) # addiu $t5, $t5, -0x6390
  lui   $a3, %hi(ptrSecondFontTableLarge)
  subu  $t4, $t4, $t3
  move  $s0, $v0
  sw    $zero, 0xd4($sp)
  sw    $zero, 0xd8($sp)
  addu  $a2, $t4, $t5
  lw    $a3, %lo(ptrSecondFontTableLarge)($a3)
  addiu $a0, $sp, 0xd8
  addiu $a1, $sp, 0xd4
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t6, 0x10($sp)
  lui   $t7, %hi(camera_8003642C) 
  lw    $t7, %lo(camera_8003642C)($t7)
  beqz  $t7, .L7F08AC38
   nop   
  jal   get_video2_settings_ulx
   nop   
  addiu $t8, $v0, 0x46
  jal   get_video2_settings_uly
   sw    $t8, 0xe4($sp)
  move  $v1, $v0
  addiu $v1, $v1, 0x20
  li    $a0, 11
  div   $zero, $v1, $a0
  bnez  $a0, .L7F08AC00
   nop   
  break 7
.L7F08AC00:
  li    $at, -1
  bne   $a0, $at, .L7F08AC18
   lui   $at, 0x8000
  bne   $v1, $at, .L7F08AC18
   nop   
  break 6
.L7F08AC18:
  mflo  $v1
  nop   
  nop   
  multu $v1, $a0
  mflo  $v1
  addiu $v1, $v1, -2
  b     .L7F08AC54
   lw    $t0, 0xd8($sp)
.L7F08AC38:
  jal   get_video2_settings_ulx
   nop   
  addiu $t9, $v0, 0x1e
  jal   get_video2_settings_uly
   sw    $t9, 0xe4($sp)
  addiu $v1, $v0, 0xd
  lw    $t0, 0xd8($sp)
.L7F08AC54:
  sw    $v1, 0xe0($sp)
  addu  $t1, $v1, $t0
  jal   get_video2_settings_txtClipW
   sw    $t1, 0xdc($sp)
  lw    $v1, 0xe0($sp)
  lw    $t2, 0xdc($sp)
  li    $t3, 100
  sw    $t3, 0x14($sp)
  move  $a0, $s0
  move  $a1, $zero
  move  $a3, $v0
  addiu $a2, $v1, -2
  jal   microcode_constructor_related_to_menus
   sw    $t2, 0x10($sp)
  jal   get_video2_settings_txtClipW
   move  $s0, $v0
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x48($sp)
  lui   $t4, %hi(upper_text_buffer_index) 
  lw    $t4, %lo(upper_text_buffer_index)($t4)
  lui   $t7, %hi(ptrSecondFontTableLarge) 
  lui   $t8, %hi(ptrFirstFontTableLarge) 
  sll   $t5, $t4, 2
  addu  $t5, $t5, $t4
  sll   $t5, $t5, 2
  subu  $t5, $t5, $t4
  lw    $t8, %lo(ptrFirstFontTableLarge)($t8)
  lw    $t7, %lo(ptrSecondFontTableLarge)($t7)
  lh    $t0, 0x48($sp)
  sll   $t5, $t5, 3
  lui   $t6, %hi(dword_CODE_bss_80079C70) 
  addiu $t6, %lo(dword_CODE_bss_80079C70) # addiu $t6, $t6, -0x6390
  li    $t9, -1
  subu  $t5, $t5, $t4
  addu  $a3, $t5, $t6
  sw    $t9, 0x18($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0xe4
  addiu $a2, $sp, 0xe0
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t8, 0x14($sp)
  sw    $t7, 0x10($sp)
  jal   en_text_write_stuff
   sw    $t0, 0x1c($sp)
  jal   combiner_bayer_lod_perspective
   move  $a0, $v0
  b     .L7F08B0DC
   move  $s0, $v0
.L7F08AD1C:
  jal   get_debug_testingmanpos_flag
   nop   
  beqz  $v0, .L7F08B0DC
   lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lwc1  $f0, 0x498($v0)
  lwc1  $f14, 0x4a0($v0)
  jal   convert_angle_using_inverse
   neg.s $f12, $f0
  li    $at, 0x43340000 # 180.000000
  mtc1  $at, $f4
  lui   $at, %hi(D_800552BC)
  lwc1  $f8, %lo(D_800552BC)($at)
  mul.s $f6, $f0, $f4
  lui   $t4, %hi(D_800368B8) 
  addiu $t4, %lo(D_800368B8) # addiu $t4, $t4, 0x68b8
  addiu $t3, $sp, 0x4c
  lui   $t8, %hi(pPlayer) 
  div.s $f10, $f6, $f8
  trunc.w.s $f16, $f10
  mfc1  $t2, $f16
  nop   
  sw    $t2, 0x68($sp)
  lw    $at, ($t4)
  lw    $t7, 4($t4)
  sw    $at, ($t3)
  lw    $at, 8($t4)
  sw    $t7, 4($t3)
  lw    $t7, 0xc($t4)
  sw    $at, 8($t3)
  lw    $at, 0x10($t4)
  sw    $t7, 0xc($t3)
  lw    $t7, 0x14($t4)
  sw    $at, 0x10($t3)
  lwr   $at, 0x1a($t4)
  sw    $t7, 0x14($t3)
  swr   $at, 0x1a($t3)
  lw    $t8, %lo(pPlayer)($t8)
  lw    $t9, 0x488($t8)
  jal   sub_GAME_7F0B5DE0
   lbu   $a0, 3($t9)
  lui   $a1, %hi(a8s)
  addiu $a1, %lo(a8s) # addiu $a1, $a1, 0x4fc0
  addiu $a0, $sp, 0xc4
  jal   sprintf
   move  $a2, $v0
  lui   $t0, %hi(pPlayer) 
  lw    $t0, %lo(pPlayer)($t0)
  lui   $a1, %hi(aX4_0f)
  addiu $a1, %lo(aX4_0f) # addiu $a1, $a1, 0x4fc4
  lwc1  $f18, 0x48c($t0)
  addiu $a0, $sp, 0xb4
  cvt.d.s $f4, $f18
  mfc1  $a3, $f4
  mfc1  $a2, $f5
  jal   sprintf
   nop   
  lui   $t1, %hi(pPlayer) 
  lw    $t1, %lo(pPlayer)($t1)
  lui   $a1, %hi(aY4_0f)
  addiu $a1, %lo(aY4_0f) # addiu $a1, $a1, 0x4fcc
  lwc1  $f6, 0x490($t1)
  addiu $a0, $sp, 0xa4
  cvt.d.s $f8, $f6
  mfc1  $a3, $f8
  mfc1  $a2, $f9
  jal   sprintf
   nop   
  lui   $t2, %hi(pPlayer) 
  lw    $t2, %lo(pPlayer)($t2)
  lui   $a1, %hi(aZ4_0f)
  addiu $a1, %lo(aZ4_0f) # addiu $a1, $a1, 0x4fd4
  lwc1  $f10, 0x494($t2)
  addiu $a0, $sp, 0x94
  cvt.d.s $f16, $f10
  mfc1  $a3, $f16
  mfc1  $a2, $f17
  jal   sprintf
   nop   
  lw    $a3, 0x68($sp)
  li    $at, 45
  lui   $a1, %hi(aS3d)
  addiu $t6, $a3, 0x16
  div   $zero, $t6, $at
  mflo  $t5
  sll   $t3, $t5, 2
  subu  $t3, $t3, $t5
  addiu $t4, $sp, 0x4c
  addu  $a2, $t3, $t4
  addiu $a1, %lo(aS3d) # addiu $a1, $a1, 0x4fdc
  jal   sprintf
   addiu $a0, $sp, 0x84
  jal   get_video2_settings_ulx
   nop   
  addiu $t7, $v0, 0x11
  jal   get_video2_settings_uly
   sw    $t7, 0x80($sp)
  addiu $a2, $v0, 0x11
  addiu $t8, $a2, 0xa
  sw    $t8, 0x74($sp)
  sw    $a2, 0x7c($sp)
  jal   microcode_constructor
   move  $a0, $s0
  jal   get_video2_settings_txtClipW
   move  $s0, $v0
  lw    $t9, 0x74($sp)
  li    $t1, 100
  sw    $t1, 0x14($sp)
  addiu $t0, $t9, 1
  sw    $t0, 0x10($sp)
  lw    $a2, 0x7c($sp)
  move  $a0, $s0
  move  $a1, $zero
  jal   microcode_constructor_related_to_menus
   move  $a3, $v0
  jal   get_video2_settings_txtClipW
   move  $s0, $v0
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x48($sp)
  lui   $t2, %hi(ptrSecondFontTableSmall) 
  lui   $t6, %hi(ptrFirstFontTableSmall) 
  lw    $t6, %lo(ptrFirstFontTableSmall)($t6)
  lw    $t2, %lo(ptrSecondFontTableSmall)($t2)
  lh    $t3, 0x48($sp)
  li    $t5, -1
  sw    $t5, 0x18($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x80
  addiu $a2, $sp, 0x7c
  addiu $a3, $sp, 0xc4
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t6, 0x14($sp)
  sw    $t2, 0x10($sp)
  jal   en_text_write_stuff
   sw    $t3, 0x1c($sp)
  jal   get_video2_settings_ulx
   move  $s0, $v0
  addiu $t4, $v0, 0x57
  jal   get_video2_settings_txtClipW
   sw    $t4, 0x80($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x48($sp)
  lui   $t7, %hi(ptrSecondFontTableSmall) 
  lui   $t8, %hi(ptrFirstFontTableSmall) 
  lw    $t8, %lo(ptrFirstFontTableSmall)($t8)
  lw    $t7, %lo(ptrSecondFontTableSmall)($t7)
  lh    $t0, 0x48($sp)
  li    $t9, -1
  sw    $t9, 0x18($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x80
  addiu $a2, $sp, 0x7c
  addiu $a3, $sp, 0xb4
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t8, 0x14($sp)
  sw    $t7, 0x10($sp)
  jal   en_text_write_stuff
   sw    $t0, 0x1c($sp)
  jal   get_video2_settings_ulx
   move  $s0, $v0
  addiu $t1, $v0, 0x8d
  jal   get_video2_settings_txtClipW
   sw    $t1, 0x80($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x48($sp)
  lui   $t2, %hi(ptrSecondFontTableSmall) 
  lui   $t6, %hi(ptrFirstFontTableSmall) 
  lw    $t6, %lo(ptrFirstFontTableSmall)($t6)
  lw    $t2, %lo(ptrSecondFontTableSmall)($t2)
  lh    $t3, 0x48($sp)
  li    $t5, -1
  sw    $t5, 0x18($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x80
  addiu $a2, $sp, 0x7c
  addiu $a3, $sp, 0xa4
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t6, 0x14($sp)
  sw    $t2, 0x10($sp)
  jal   en_text_write_stuff
   sw    $t3, 0x1c($sp)
  jal   get_video2_settings_ulx
   move  $s0, $v0
  addiu $t4, $v0, 0xc3
  jal   get_video2_settings_txtClipW
   sw    $t4, 0x80($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x48($sp)
  lui   $t7, %hi(ptrSecondFontTableSmall) 
  lui   $t8, %hi(ptrFirstFontTableSmall) 
  lw    $t8, %lo(ptrFirstFontTableSmall)($t8)
  lw    $t7, %lo(ptrSecondFontTableSmall)($t7)
  lh    $t0, 0x48($sp)
  li    $t9, -1
  sw    $t9, 0x18($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x80
  addiu $a2, $sp, 0x7c
  addiu $a3, $sp, 0x94
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t8, 0x14($sp)
  sw    $t7, 0x10($sp)
  jal   en_text_write_stuff
   sw    $t0, 0x1c($sp)
  jal   get_video2_settings_ulx
   move  $s0, $v0
  addiu $t1, $v0, 0xf9
  jal   get_video2_settings_txtClipW
   sw    $t1, 0x80($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x48($sp)
  lui   $t2, %hi(ptrSecondFontTableSmall) 
  lui   $t6, %hi(ptrFirstFontTableSmall) 
  lw    $t6, %lo(ptrFirstFontTableSmall)($t6)
  lw    $t2, %lo(ptrSecondFontTableSmall)($t2)
  lh    $t3, 0x48($sp)
  li    $t5, -1
  sw    $t5, 0x18($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x80
  addiu $a2, $sp, 0x7c
  addiu $a3, $sp, 0x84
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t6, 0x14($sp)
  sw    $t2, 0x10($sp)
  jal   en_text_write_stuff
   sw    $t3, 0x1c($sp)
  jal   combiner_bayer_lod_perspective
   move  $a0, $v0
  move  $s0, $v0
.L7F08B0DC:
  lw    $ra, 0x3c($sp)
  move  $v0, $s0
  lw    $s0, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0xe8
");

#ifdef VERSION_JP
asm(R"
.late_rodata
glabel D_800552BC
.word 0x40490fdb /*3.1415927*/
.text
glabel sub_GAME_7F08AAE8
  lui   $t6, %hi(D_800368B4) # $t6, 0x8003
  lw    $t6, %lo(D_800368B4)($t6)
  addiu $sp, $sp, -0xe8
  sw    $s0, 0x38($sp)
  move  $s0, $a0
  bnez  $t6, .Ljp7F08B5A4
   sw    $ra, 0x3c($sp)
  lui   $t7, %hi(upper_text_window_timer) # $t7, 0x8003
  lw    $t7, %lo(upper_text_window_timer)($t7)
  lui   $t8, %hi(upper_text_buffer_index) # $t8, 0x8003
  bltz  $t7, .Ljp7F08B5A4
   nop   
  lw    $t8, %lo(upper_text_buffer_index)($t8)
  lui   $t0, %hi(dword_CODE_bss_80079C70)
  lui   $t1, %hi(pPlayer) # $t1, 0x8008
  sll   $t9, $t8, 2
  addu  $t9, $t9, $t8
  sll   $t9, $t9, 2
  subu  $t9, $t9, $t8
  sll   $t9, $t9, 3
  subu  $t9, $t9, $t8
  addu  $t0, $t0, $t9
  lbu   $t0, %lo(dword_CODE_bss_80079C70)($t0)
  beqz  $t0, .Ljp7F08B5A4
   nop   
  lw    $t1, %lo(pPlayer)($t1)
  lw    $t2, 0x29c4($t1)
  bnez  $t2, .Ljp7F08B5A4
   nop   
  jal   microcode_constructor
   nop   
  lui   $t3, %hi(upper_text_buffer_index) # $t3, 0x8003
  lw    $t3, %lo(upper_text_buffer_index)($t3)
  lui   $t6, %hi(ptrFirstFontTableLarge) # $t6, 0x8004
  lw    $t6, %lo(ptrFirstFontTableLarge)($t6)
  sll   $t4, $t3, 2
  addu  $t4, $t4, $t3
  sll   $t4, $t4, 2
  subu  $t4, $t4, $t3
  sll   $t4, $t4, 3
  lui   $t5, %hi(dword_CODE_bss_80079C70) # $t5, 0x8008
  addiu $t5, %lo(dword_CODE_bss_80079C70) # addiu $t5, $t5, -0x6320
  lui   $a3, %hi(ptrSecondFontTableLarge) # $a3, 0x8004
  subu  $t4, $t4, $t3
  move  $s0, $v0
  sw    $zero, 0xd4($sp)
  sw    $zero, 0xd8($sp)
  addu  $a2, $t4, $t5
  lw    $a3, %lo(ptrSecondFontTableLarge)($a3)
  addiu $a0, $sp, 0xd8
  addiu $a1, $sp, 0xd4
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t6, 0x10($sp)
  lui   $t7, %hi(camera_8003642C) # $t7, 0x8003
  lw    $t7, %lo(camera_8003642C)($t7)
  beqz  $t7, .Ljp7F08B414
   nop   
  jal   get_video2_settings_ulx
   nop   
  addiu $t8, $v0, 0x46
  jal   get_video2_settings_uly
   sw    $t8, 0xe4($sp)
  move  $v1, $v0
  addiu $v1, $v1, 0x20
  li    $a0, 11
  div   $zero, $v1, $a0
  bnez  $a0, .Ljp7F08B3DC
   nop   
  break 7
.Ljp7F08B3DC:
  li    $at, -1
  bne   $a0, $at, .Ljp7F08B3F4
   lui   $at, 0x8000
  bne   $v1, $at, .Ljp7F08B3F4
   nop   
  break 6
.Ljp7F08B3F4:
  mflo  $v1
  nop   
  nop   
  multu $v1, $a0
  mflo  $v1
  addiu $v1, $v1, -2
  b     .Ljp7F08B430
   lw    $t0, 0xd8($sp)
.Ljp7F08B414:
  jal   get_video2_settings_ulx
   nop   
  addiu $t9, $v0, 0x1e
  jal   get_video2_settings_uly
   sw    $t9, 0xe4($sp)
  addiu $v1, $v0, 0xd
  lw    $t0, 0xd8($sp)
.Ljp7F08B430:
  sw    $v1, 0xe0($sp)
  addu  $t1, $v1, $t0
  jal   get_video2_settings_txtClipW
   sw    $t1, 0xdc($sp)
  lw    $v1, 0xe0($sp)
  lw    $t2, 0xdc($sp)
  li    $t3, 100
  sw    $t3, 0x14($sp)
  move  $a0, $s0
  move  $a1, $zero
  move  $a3, $v0
  addiu $a2, $v1, -2
  jal   microcode_constructor_related_to_menus
   sw    $t2, 0x10($sp)
  lui   $t4, %hi(j_text_trigger) # $t4, 0x8005
  lw    $t4, %lo(j_text_trigger)($t4)
  move  $s0, $v0
  beqz  $t4, .Ljp7F08B510
   nop   
  jal   get_video2_settings_txtClipW
   nop   
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x48($sp)
  lui   $t5, %hi(upper_text_buffer_index) # $t5, 0x8003
  lw    $t5, %lo(upper_text_buffer_index)($t5)
  lui   $t8, %hi(ptrSecondFontTableLarge) # $t8, 0x8004
  lui   $t9, %hi(ptrFirstFontTableLarge) # $t9, 0x8004
  sll   $t6, $t5, 2
  addu  $t6, $t6, $t5
  sll   $t6, $t6, 2
  subu  $t6, $t6, $t5
  lw    $t9, %lo(ptrFirstFontTableLarge)($t9)
  lw    $t8, %lo(ptrSecondFontTableLarge)($t8)
  lh    $t2, 0x48($sp)
  sll   $t6, $t6, 3
  lui   $t7, %hi(dword_CODE_bss_80079C70) # $t7, 0x8008
  lui   $t1, (0x646464FF >> 16) # lui $t1, 0x6464
  ori   $t1, (0x646464FF & 0xFFFF) # ori $t1, $t1, 0x64ff
  addiu $t7, %lo(dword_CODE_bss_80079C70) # addiu $t7, $t7, -0x6320
  li    $t0, -1
  subu  $t6, $t6, $t5
  addu  $a3, $t6, $t7
  sw    $t0, 0x18($sp)
  sw    $t1, 0x1c($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0xe4
  addiu $a2, $sp, 0xe0
  sw    $v0, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $zero, 0x2c($sp)
  sw    $t9, 0x14($sp)
  sw    $t8, 0x10($sp)
  jal   jp_text_write_stuff
   sw    $t2, 0x20($sp)
  b     .Ljp7F08B594
   move  $s0, $v0
.Ljp7F08B510:
  jal   get_video2_settings_txtClipW
   nop   
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x48($sp)
  lui   $t3, %hi(upper_text_buffer_index) # $t3, 0x8003
  lw    $t3, %lo(upper_text_buffer_index)($t3)
  lui   $t6, %hi(ptrSecondFontTableLarge) # $t6, 0x8004
  lui   $t7, %hi(ptrFirstFontTableLarge) # $t7, 0x8004
  sll   $t4, $t3, 2
  addu  $t4, $t4, $t3
  sll   $t4, $t4, 2
  subu  $t4, $t4, $t3
  lw    $t7, %lo(ptrFirstFontTableLarge)($t7)
  lw    $t6, %lo(ptrSecondFontTableLarge)($t6)
  lh    $t9, 0x48($sp)
  sll   $t4, $t4, 3
  lui   $t5, %hi(dword_CODE_bss_80079C70) # $t5, 0x8008
  addiu $t5, %lo(dword_CODE_bss_80079C70) # addiu $t5, $t5, -0x6320
  li    $t8, -1
  subu  $t4, $t4, $t3
  addu  $a3, $t4, $t5
  sw    $t8, 0x18($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0xe4
  addiu $a2, $sp, 0xe0
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t7, 0x14($sp)
  sw    $t6, 0x10($sp)
  jal   en_text_write_stuff
   sw    $t9, 0x1c($sp)
  move  $s0, $v0
.Ljp7F08B594:
  jal   combiner_bayer_lod_perspective
   move  $a0, $s0
  b     .Ljp7F08B964
   move  $s0, $v0
.Ljp7F08B5A4:
  jal   get_debug_testingmanpos_flag
   nop   
  beqz  $v0, .Ljp7F08B964
   lui   $v0, %hi(pPlayer) # $v0, 0x8008
  lw    $v0, %lo(pPlayer)($v0)
  lwc1  $f0, 0x498($v0)
  lwc1  $f14, 0x4a0($v0)
  jal   convert_angle_using_inverse
   neg.s $f12, $f0
  li    $at, 0x43340000 # 180.000000
  mtc1  $at, $f4
  lui   $at, %hi(D_800552BC) # $at, 0x8005
  lwc1  $f8, %lo(D_800552BC)($at)
  mul.s $f6, $f0, $f4
  lui   $t3, %hi(D_800368B8) # $t3, 0x8003
  addiu $t3, %lo(D_800368B8) # addiu $t3, $t3, 0x68f0
  addiu $t2, $sp, 0x4c
  lui   $t7, %hi(pPlayer) # $t7, 0x8008
  div.s $f10, $f6, $f8
  trunc.w.s $f16, $f10
  mfc1  $t1, $f16
  nop   
  sw    $t1, 0x68($sp)
  lw    $at, ($t3)
  lw    $t6, 4($t3)
  sw    $at, ($t2)
  lw    $at, 8($t3)
  sw    $t6, 4($t2)
  lw    $t6, 0xc($t3)
  sw    $at, 8($t2)
  lw    $at, 0x10($t3)
  sw    $t6, 0xc($t2)
  lw    $t6, 0x14($t3)
  sw    $at, 0x10($t2)
  lwr   $at, 0x1a($t3)
  sw    $t6, 0x14($t2)
  swr   $at, 0x1a($t2)
  lw    $t7, %lo(pPlayer)($t7)
  lw    $t8, 0x488($t7)
  jal   sub_GAME_7F0B5DE0
   lbu   $a0, 3($t8)
  lui   $a1, %hi(a8s) # $a1, 0x8005
  addiu $a1, %lo(a8s) # addiu $a1, $a1, 0x4ff0
  addiu $a0, $sp, 0xc4
  jal   sprintf
   move  $a2, $v0
  lui   $t9, %hi(pPlayer) # $t9, 0x8008
  lw    $t9, %lo(pPlayer)($t9)
  lui   $a1, %hi(aX4_0f) # $a1, 0x8005
  addiu $a1, %lo(aX4_0f) # addiu $a1, $a1, 0x4ff4
  lwc1  $f18, 0x48c($t9)
  addiu $a0, $sp, 0xb4
  cvt.d.s $f4, $f18
  mfc1  $a3, $f4
  mfc1  $a2, $f5
  jal   sprintf
   nop   
  lui   $t0, %hi(pPlayer) # $t0, 0x8008
  lw    $t0, %lo(pPlayer)($t0)
  lui   $a1, %hi(aY4_0f) # $a1, 0x8005
  addiu $a1, %lo(aY4_0f) # addiu $a1, $a1, 0x4ffc
  lwc1  $f6, 0x490($t0)
  addiu $a0, $sp, 0xa4
  cvt.d.s $f8, $f6
  mfc1  $a3, $f8
  mfc1  $a2, $f9
  jal   sprintf
   nop   
  lui   $t1, %hi(pPlayer) # $t1, 0x8008
  lw    $t1, %lo(pPlayer)($t1)
  lui   $a1, %hi(aZ4_0f) # $a1, 0x8005
  addiu $a1, %lo(aZ4_0f) # addiu $a1, $a1, 0x5004
  lwc1  $f10, 0x494($t1)
  addiu $a0, $sp, 0x94
  cvt.d.s $f16, $f10
  mfc1  $a3, $f16
  mfc1  $a2, $f17
  jal   sprintf
   nop   
  lw    $a3, 0x68($sp)
  li    $at, 45
  lui   $a1, %hi(aS3d) # $a1, 0x8005
  addiu $t5, $a3, 0x16
  div   $zero, $t5, $at
  mflo  $t4
  sll   $t2, $t4, 2
  subu  $t2, $t2, $t4
  addiu $t3, $sp, 0x4c
  addu  $a2, $t2, $t3
  addiu $a1, %lo(aS3d) # addiu $a1, $a1, 0x500c
  jal   sprintf
   addiu $a0, $sp, 0x84
  jal   get_video2_settings_ulx
   nop   
  addiu $t6, $v0, 0x11
  jal   get_video2_settings_uly
   sw    $t6, 0x80($sp)
  addiu $a2, $v0, 0x11
  addiu $t7, $a2, 0xa
  sw    $t7, 0x74($sp)
  sw    $a2, 0x7c($sp)
  jal   microcode_constructor
   move  $a0, $s0
  jal   get_video2_settings_txtClipW
   move  $s0, $v0
  lw    $t8, 0x74($sp)
  li    $t0, 100
  sw    $t0, 0x14($sp)
  addiu $t9, $t8, 1
  sw    $t9, 0x10($sp)
  lw    $a2, 0x7c($sp)
  move  $a0, $s0
  move  $a1, $zero
  jal   microcode_constructor_related_to_menus
   move  $a3, $v0
  jal   get_video2_settings_txtClipW
   move  $s0, $v0
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x48($sp)
  lui   $t1, %hi(ptrSecondFontTableSmall) # $t1, 0x8004
  lui   $t5, %hi(ptrFirstFontTableSmall) # $t5, 0x8004
  lw    $t5, %lo(ptrFirstFontTableSmall)($t5)
  lw    $t1, %lo(ptrSecondFontTableSmall)($t1)
  lh    $t2, 0x48($sp)
  li    $t4, -1
  sw    $t4, 0x18($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x80
  addiu $a2, $sp, 0x7c
  addiu $a3, $sp, 0xc4
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t5, 0x14($sp)
  sw    $t1, 0x10($sp)
  jal   en_text_write_stuff
   sw    $t2, 0x1c($sp)
  jal   get_video2_settings_ulx
   move  $s0, $v0
  addiu $t3, $v0, 0x57
  jal   get_video2_settings_txtClipW
   sw    $t3, 0x80($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x48($sp)
  lui   $t6, %hi(ptrSecondFontTableSmall) # $t6, 0x8004
  lui   $t7, %hi(ptrFirstFontTableSmall) # $t7, 0x8004
  lw    $t7, %lo(ptrFirstFontTableSmall)($t7)
  lw    $t6, %lo(ptrSecondFontTableSmall)($t6)
  lh    $t9, 0x48($sp)
  li    $t8, -1
  sw    $t8, 0x18($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x80
  addiu $a2, $sp, 0x7c
  addiu $a3, $sp, 0xb4
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t7, 0x14($sp)
  sw    $t6, 0x10($sp)
  jal   en_text_write_stuff
   sw    $t9, 0x1c($sp)
  jal   get_video2_settings_ulx
   move  $s0, $v0
  addiu $t0, $v0, 0x8d
  jal   get_video2_settings_txtClipW
   sw    $t0, 0x80($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x48($sp)
  lui   $t1, %hi(ptrSecondFontTableSmall) # $t1, 0x8004
  lui   $t5, %hi(ptrFirstFontTableSmall) # $t5, 0x8004
  lw    $t5, %lo(ptrFirstFontTableSmall)($t5)
  lw    $t1, %lo(ptrSecondFontTableSmall)($t1)
  lh    $t2, 0x48($sp)
  li    $t4, -1
  sw    $t4, 0x18($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x80
  addiu $a2, $sp, 0x7c
  addiu $a3, $sp, 0xa4
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t5, 0x14($sp)
  sw    $t1, 0x10($sp)
  jal   en_text_write_stuff
   sw    $t2, 0x1c($sp)
  jal   get_video2_settings_ulx
   move  $s0, $v0
  addiu $t3, $v0, 0xc3
  jal   get_video2_settings_txtClipW
   sw    $t3, 0x80($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x48($sp)
  lui   $t6, %hi(ptrSecondFontTableSmall) # $t6, 0x8004
  lui   $t7, %hi(ptrFirstFontTableSmall) # $t7, 0x8004
  lw    $t7, %lo(ptrFirstFontTableSmall)($t7)
  lw    $t6, %lo(ptrSecondFontTableSmall)($t6)
  lh    $t9, 0x48($sp)
  li    $t8, -1
  sw    $t8, 0x18($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x80
  addiu $a2, $sp, 0x7c
  addiu $a3, $sp, 0x94
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t7, 0x14($sp)
  sw    $t6, 0x10($sp)
  jal   en_text_write_stuff
   sw    $t9, 0x1c($sp)
  jal   get_video2_settings_ulx
   move  $s0, $v0
  addiu $t0, $v0, 0xf9
  jal   get_video2_settings_txtClipW
   sw    $t0, 0x80($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x48($sp)
  lui   $t1, %hi(ptrSecondFontTableSmall) # $t1, 0x8004
  lui   $t5, %hi(ptrFirstFontTableSmall) # $t5, 0x8004
  lw    $t5, %lo(ptrFirstFontTableSmall)($t5)
  lw    $t1, %lo(ptrSecondFontTableSmall)($t1)
  lh    $t2, 0x48($sp)
  li    $t4, -1
  sw    $t4, 0x18($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x80
  addiu $a2, $sp, 0x7c
  addiu $a3, $sp, 0x84
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t5, 0x14($sp)
  sw    $t1, 0x10($sp)
  jal   en_text_write_stuff
   sw    $t2, 0x1c($sp)
  jal   combiner_bayer_lod_perspective
   move  $a0, $v0
  move  $s0, $v0
.Ljp7F08B964:
  lw    $ra, 0x3c($sp)
  move  $v0, $s0
  lw    $s0, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0xe8
");
#endif

#endif

asm(R"
.late_rodata
glabel D_800552C0
.word 0xbd4ccccd /*-0.050000001*/
glabel D_800552C4
.word 0xbecccccd /*-0.40000001*/
glabel D_800552C8
.word 0x3d4ccccd /*0.050000001*/
glabel D_800552CC
.word 0x3ecccccd /*0.40000001*/
glabel D_800552D0
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F08B0F0
  addiu $sp, $sp, -0xf8
  sw    $ra, 0x24($sp)
  sw    $s1, 0x20($sp)
  sw    $s0, 0x1c($sp)
  jal   sub_GAME_7F09B15C
   sw    $a0, 0xf8($sp)
  lw    $t6, 0xf8($sp)
  sw    $v0, 0xf4($sp)
  lw    $t7, 4($t6)
  beqz  $t7, .L7F08B144
   sw    $t7, 0xf0($sp)
  jal   get_cur_playernum
   nop   
  jal   sub_GAME_7F09B4D8
   move  $a0, $v0
  bnezl $v0, .L7F08B148
   lw    $t1, 0xf0($sp)
  lw    $v0, 0xf0($sp)
  lhu   $t8, 0x12($v0)
  andi  $t9, $t8, 0xf7ff
  sh    $t9, 0x12($v0)
.L7F08B144:
  lw    $t1, 0xf0($sp)
.L7F08B148:
  lw    $t2, 0xf4($sp)
  lui   $t4, %hi(players_p1) 
  beqz  $t1, .L7F08B288
   sll   $t3, $t2, 2
  addiu $t4, %lo(players_p1) # addiu $t4, $t4, -0x6120
  addu  $s1, $t3, $t4
  lw    $t5, ($s1)
  lw    $t6, 0xd4($t5)
  beql  $t6, $zero, .L7F08B28C
   lw    $t7, 0xf0($sp)
  jal   get_debug_render_raster
   nop   
  beql  $v0, $zero, .L7F08B198
   lw    $t9, ($s1)
  lw    $t7, ($s1)
  li    $at, 1
  lw    $t8, ($t7)
  bnel  $t8, $at, .L7F08B28C
   lw    $t7, 0xf0($sp)
  lw    $t9, ($s1)
.L7F08B198:
  sw    $zero, 0xac($t9)
  jal   sub_GAME_7F020EF0
   lw    $a0, 0xf8($sp)
  lw    $t2, ($s1)
  sw    $v0, 0xe8($sp)
  li    $t1, 1
  sw    $t1, 0xac($t2)
  lw    $t0, ($s1)
  lw    $t3, 0xa8($t0)
  lwc1  $f4, 8($t3)
  swc1  $f4, 0x48c($t0)
  lw    $t0, ($s1)
  lw    $t4, 0xa8($t0)
  lwc1  $f6, 0xc($t4)
  swc1  $f6, 0x490($t0)
  lw    $t0, ($s1)
  lw    $t5, 0xa8($t0)
  lwc1  $f8, 0x10($t5)
  swc1  $f8, 0x494($t0)
  lw    $t0, ($s1)
  lw    $t6, 0xa8($t0)
  lw    $t7, 0x14($t6)
  sw    $t7, 0x488($t0)
  jal   sub_GAME_7F07DE9C
   lw    $a0, ($s1)
  lw    $t8, 0xf8($sp)
  lbu   $t9, 1($t8)
  andi  $t1, $t9, 2
  beqz  $t1, .L7F08B280
   nop   
  lw    $t2, ($s1)
  lw    $t3, 0xd4($t2)
  jal   sub_GAME_7F078444
   lw    $s0, 0xc($t3)
  move  $a0, $v0
  move  $a1, $s0
  jal   sub_GAME_7F05818C
   addiu $a2, $sp, 0xa4
  li    $at, 0x40E00000 # 7.000000
  mtc1  $at, $f0
  lwc1  $f10, 0xb4($sp)
  lwc1  $f4, 0xd4($sp)
  lw    $t4, ($s1)
  mul.s $f18, $f10, $f0
  add.s $f6, $f18, $f4
  swc1  $f6, 0x4b4($t4)
  lwc1  $f8, 0xb8($sp)
  lwc1  $f18, 0xd8($sp)
  lw    $t5, ($s1)
  mul.s $f10, $f8, $f0
  add.s $f4, $f10, $f18
  swc1  $f4, 0x4b8($t5)
  lwc1  $f6, 0xbc($sp)
  lwc1  $f10, 0xdc($sp)
  lw    $t6, ($s1)
  mul.s $f8, $f6, $f0
  add.s $f18, $f8, $f10
  swc1  $f18, 0x4bc($t6)
.L7F08B280:
  b     .L7F08BCA4
   lw    $v0, 0xe8($sp)
.L7F08B288:
  lw    $t7, 0xf0($sp)
.L7F08B28C:
  lw    $t8, 0xf4($sp)
  lui   $t1, %hi(players_p1) 
  beqz  $t7, .L7F08BC90
   sll   $t9, $t8, 2
  addiu $t1, %lo(players_p1) # addiu $t1, $t1, -0x6120
  addu  $s1, $t9, $t1
  lw    $t2, ($s1)
  lw    $t3, 0xd4($t2)
  beql  $t3, $zero, .L7F08BC94
   lw    $t2, 0xf8($sp)
  jal   getPlayerCount
   nop   
  slti  $at, $v0, 2
  bnezl $at, .L7F08BC94
   lw    $t2, 0xf8($sp)
  jal   get_cur_playernum
   nop   
  lw    $t4, 0xf4($sp)
  li    $at, 0xBF800000 # -1.000000
  li    $a1, 1
  beql  $v0, $t4, .L7F08BC94
   lw    $t2, 0xf8($sp)
  mtc1  $at, $f2
  sw    $zero, 0x9c($sp)
  sw    $zero, 0x7c($sp)
  lw    $a0, 0xf0($sp)
  swc1  $f2, 0x90($sp)
  jal   something_with_weaponpos_of_guarddata_hand
   swc1  $f2, 0x94($sp)
  move  $s0, $v0
  lw    $a0, 0xf0($sp)
  jal   something_with_weaponpos_of_guarddata_hand
   move  $a1, $zero
  lwc1  $f2, 0x94($sp)
  move  $a1, $v0
  move  $v1, $zero
  move  $a0, $zero
  beqz  $s0, .L7F08B32C
   sw    $zero, 0x54($sp)
  lw    $v1, 4($s0)
.L7F08B32C:
  beql  $v0, $zero, .L7F08B33C
   sw    $v1, 0x5c($sp)
  lw    $a0, 4($v0)
  sw    $v1, 0x5c($sp)
.L7F08B33C:
  sw    $a0, 0x58($sp)
  sw    $a1, 0x60($sp)
  jal   get_cur_playernum
   swc1  $f2, 0x94($sp)
  jal   sub_GAME_7F09B4D8
   move  $a0, $v0
  lw    $v1, 0x5c($sp)
  lw    $a1, 0x60($sp)
  bnez  $v0, .L7F08B378
   lwc1  $f2, 0x94($sp)
  lui   $v0, %hi(D_800368B8+0x1C)
  addiu $v0, %lo(D_800368B8+0x1C) # addiu $v0, $v0, 0x68d4
  lw    $t5, ($v0)
  addiu $t6, $t5, 1
  sw    $t6, ($v0)
.L7F08B378:
  lui   $v0, %hi(D_800368B8+0x1C)
  addiu $v0, %lo(D_800368B8+0x1C) # addiu $v0, $v0, 0x68d4
  lw    $t7, ($v0)
  slti  $at, $t7, 2
  bnezl $at, .L7F08BA78
   lw    $t2, ($s1)
  lw    $t0, ($s1)
  lwc1  $f4, 0x2a08($t0)
  swc1  $f4, 0x8c($sp)
  lwc1  $f6, 0x2a0c($t0)
  swc1  $f6, 0x88($sp)
  lw    $t8, 0xd8($t0)
  beqz  $t8, .L7F08B484
   lui   $a3, %hi(D_8003650C)
  lw    $a3, %lo(D_8003650C)($a3)
  move  $a1, $zero
  move  $s0, $zero
  blez  $a3, .L7F08B400
   lui   $t9, %hi(D_800364D8)
  addiu $v0, $t9, %lo(D_800364D8)
  lui   $v1, %hi(ptr_animation_table)
  sll   $t1, $a3, 2
  addu  $a0, $t1, $v0
  lw    $v1, %lo(ptr_animation_table)($v1)
  lw    $a2, 0x1284($t0)
  lw    $t2, ($v0)
.L7F08B3E0:
  addiu $v0, $v0, 4
  sltu  $at, $v0, $a0
  addu  $t3, $t2, $v1
  bne   $a2, $t3, .L7F08B3F8
   nop   
  li    $a1, 1
.L7F08B3F8:
  bnezl $at, .L7F08B3E0
   lw    $t2, ($v0)
.L7F08B400:
  beqz  $a1, .L7F08B418
   li    $at, 0x3F000000 # 0.500000
  lw    $a2, 0x1284($t0)
  mtc1  $at, $f12
  b     .L7F08B470
   sw    $a2, 0x9c($sp)
.L7F08B418:
  jal   get_random_value
   swc1  $f2, 0x94($sp)
  lui   $t4, %hi(D_8003650C) 
  lw    $t4, %lo(D_8003650C)($t4)
  lui   $t7, %hi(D_800364D8)
  lui   $t8, %hi(ptr_animation_table) 
  divu  $zero, $v0, $t4
  mfhi  $t5
  sll   $t6, $t5, 2
  addu  $t7, $t7, $t6
  lw    $t7, %lo(D_800364D8)($t7)
  lw    $t8, %lo(ptr_animation_table)($t8)
  lw    $t0, ($s1)
  li    $at, 0x3F000000 # 0.500000
  addu  $t1, $t7, $t8
  sw    $t1, 0x9c($sp)
  mtc1  $at, $f12
  lwc1  $f2, 0x94($sp)
  bnez  $t4, .L7F08B46C
   nop   
  break 7
.L7F08B46C:
  lw    $a2, 0x1284($t0)
.L7F08B470:
  mtc1  $zero, $f14
  nop   
  swc1  $f14, 0x8c($sp)
  b     .L7F08B858
   swc1  $f14, 0x88($sp)
.L7F08B484:
  beqz  $s0, .L7F08B49C
   nop   
  beqz  $a1, .L7F08B49C
   nop   
  b     .L7F08B550
   li    $s0, 3
.L7F08B49C:
  bnez  $s0, .L7F08B4B4
   nop   
  bnez  $a1, .L7F08B4B4
   nop   
  b     .L7F08B550
   li    $s0, 2
.L7F08B4B4:
  beqz  $v1, .L7F08B4D8
   li    $a1, 512
  lb    $a0, 0x80($v1)
  jal   check_special_attributes
   sw    $v1, 0x5c($sp)
  bnez  $v0, .L7F08B4D8
   lw    $v1, 0x5c($sp)
  b     .L7F08B550
   li    $s0, 2
.L7F08B4D8:
  lw    $v0, 0x58($sp)
  li    $a1, 512
  beqz  $v0, .L7F08B504
   nop   
  lb    $a0, 0x80($v0)
  jal   check_special_attributes
   sw    $v1, 0x5c($sp)
  bnez  $v0, .L7F08B504
   lw    $v1, 0x5c($sp)
  b     .L7F08B550
   li    $s0, 2
.L7F08B504:
  beqz  $v1, .L7F08B524
   li    $a1, 256
  jal   check_special_attributes
   lb    $a0, 0x80($v1)
  beql  $v0, $zero, .L7F08B528
   lw    $v0, 0x58($sp)
  b     .L7F08B550
   move  $s0, $zero
.L7F08B524:
  lw    $v0, 0x58($sp)
.L7F08B528:
  li    $a1, 256
  beql  $v0, $zero, .L7F08B550
   li    $s0, 1
  jal   check_special_attributes
   lb    $a0, 0x80($v0)
  beql  $v0, $zero, .L7F08B550
   li    $s0, 1
  b     .L7F08B550
   move  $s0, $zero
  li    $s0, 1
.L7F08B550:
  jal   sub_GAME_7F079A1C
   lw    $a0, 0xf4($sp)
  li    $at, 1
  beql  $v0, $at, .L7F08B574
   lui   $at, 0x3f80
  jal   sub_GAME_7F079A1C
   lw    $a0, 0xf4($sp)
  bnez  $v0, .L7F08B588
   li    $at, 0x3F800000 # 1.000000
.L7F08B574:
  mtc1  $at, $f12
  mtc1  $zero, $f14
  li    $a0, 5
  b     .L7F08B7F8
   lw    $t0, ($s1)
.L7F08B588:
  lw    $t0, ($s1)
  mtc1  $zero, $f14
  sll   $t9, $s0, 4
  lwc1  $f2, 0x16c($t0)
  subu  $t9, $t9, $s0
  sll   $t9, $t9, 3
  c.lt.s $f2, $f14
  lui   $t2, %hi(firing_animation_groups+0x50) #firing_animation_groups[440]
  addu  $t2, $t2, $t9
  bc1fl .L7F08B600
   c.lt.s $f14, $f2
  lw    $t2, %lo(firing_animation_groups+0x50)($t2) #firing_animation_groups[440]
  li    $at, 0x42B40000 # 90.000000
  beql  $t2, $zero, .L7F08B600
   c.lt.s $f14, $f2
  lwc1  $f0, 0x1280($t0)
  mtc1  $at, $f8
  li    $a0, 4
  neg.s $f12, $f2
  c.lt.s $f0, $f8
  li    $at, 0x41700000 # 15.000000
  bc1fl .L7F08B7FC
   sll   $t7, $s0, 4
  mtc1  $at, $f10
  nop   
  add.s $f18, $f0, $f10
  swc1  $f18, 0x1280($t0)
  b     .L7F08B7F8
   lw    $t0, ($s1)
  c.lt.s $f14, $f2
.L7F08B600:
  sll   $t3, $s0, 4
  subu  $t3, $t3, $s0
  sll   $t3, $t3, 3
  bc1f  .L7F08B660
   lui   $t4, %hi(firing_animation_groups+0x3C)
  addu  $t4, $t4, $t3
  lw    $t4, %lo(firing_animation_groups+0x3C)($t4)
  li    $at, 0xC2B40000 # -90.000000
  beql  $t4, $zero, .L7F08B664
   lwc1  $f2, 0x14c($t0)
  lwc1  $f0, 0x1280($t0)
  mtc1  $at, $f4
  li    $a0, 3
  mov.s $f12, $f2
  c.lt.s $f4, $f0
  li    $at, 0x41700000 # 15.000000
  bc1fl .L7F08B7FC
   sll   $t7, $s0, 4
  mtc1  $at, $f6
  nop   
  sub.s $f8, $f0, $f6
  swc1  $f8, 0x1280($t0)
  b     .L7F08B7F8
   lw    $t0, ($s1)
.L7F08B660:
  lwc1  $f2, 0x14c($t0)
.L7F08B664:
  lui   $at, %hi(D_800552C0)
  c.lt.s $f2, $f14
  nop   
  bc1fl .L7F08B680
   lwc1  $f0, 0x174($t0)
  neg.s $f2, $f2
  lwc1  $f0, 0x174($t0)
.L7F08B680:
  lwc1  $f10, %lo(D_800552C0)($at)
  lui   $at, %hi(D_800552C8)
  c.lt.s $f0, $f10
  nop   
  bc1f  .L7F08B708
   nop   
  neg.s $f2, $f2
  lui   $at, %hi(D_800552C4)
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F08B6B8
   lw    $t5, 0x4e8($t0)
  mov.s $f2, $f0
  lw    $t5, 0x4e8($t0)
.L7F08B6B8:
  beql  $t5, $zero, .L7F08B6DC
   add.s $f12, $f2, $f2
  lwc1  $f18, %lo(D_800552C4)($at)
  li    $a0, 2
  c.lt.s $f18, $f0
  nop   
  bc1f  .L7F08B700
   nop   
  add.s $f12, $f2, $f2
.L7F08B6DC:
  li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f16
  li    $a0, 1
  c.lt.s $f12, $f16
  nop   
  bc1fl .L7F08B7A8
   lwc1  $f0, 0x1280($t0)
  b     .L7F08B7A4
   mov.s $f12, $f16
.L7F08B700:
  b     .L7F08B7A4
   mov.s $f12, $f2
.L7F08B708:
  lwc1  $f12, %lo(D_800552C8)($at)
  c.lt.s $f12, $f0
  nop   
  bc1tl .L7F08B730
   c.lt.s $f2, $f0
  c.lt.s $f12, $f2
  li    $at, 0x3F800000 # 1.000000
  bc1fl .L7F08B7A0
   mtc1  $at, $f12
  c.lt.s $f2, $f0
.L7F08B730:
  lui    $at, %hi(D_800552CC)
  bc1fl .L7F08B744
   lw    $t6, 0x4e8($t0)
  mov.s $f2, $f0
  lw    $t6, 0x4e8($t0)
.L7F08B744:
  beql  $t6, $zero, .L7F08B768
   add.s $f12, $f2, $f2
  lwc1  $f4, %lo(D_800552CC)($at)
  li    $a0, 2
  c.lt.s $f0, $f4
  nop   
  bc1f  .L7F08B794
   nop   
  add.s $f12, $f2, $f2
.L7F08B768:
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  li    $a0, 1
  li    $at, 0x3F800000 # 1.000000
  c.lt.s $f6, $f12
  nop   
  bc1fl .L7F08B7A8
   lwc1  $f0, 0x1280($t0)
  mtc1  $at, $f12
  b     .L7F08B7A8
   lwc1  $f0, 0x1280($t0)
.L7F08B794:
  b     .L7F08B7A4
   mov.s $f12, $f2
  mtc1  $at, $f12
.L7F08B7A0:
  move  $a0, $zero
.L7F08B7A4:
  lwc1  $f0, 0x1280($t0)
.L7F08B7A8:
  li    $at, 0x41700000 # 15.000000
  c.lt.s $f14, $f0
  nop   
  bc1fl .L7F08B7D8
   c.lt.s $f0, $f14
  mtc1  $at, $f8
  nop   
  sub.s $f10, $f0, $f8
  swc1  $f10, 0x1280($t0)
  lw    $t0, ($s1)
  lwc1  $f0, 0x1280($t0)
  c.lt.s $f0, $f14
.L7F08B7D8:
  li    $at, 0x41700000 # 15.000000
  bc1fl .L7F08B7FC
   sll   $t7, $s0, 4
  mtc1  $at, $f18
  nop   
  add.s $f4, $f0, $f18
  swc1  $f4, 0x1280($t0)
  lw    $t0, ($s1)
.L7F08B7F8:
  sll   $t7, $s0, 4
.L7F08B7FC:
  sll   $t8, $a0, 2
  addu  $t8, $t8, $a0
  subu  $t7, $t7, $s0
  sll   $t7, $t7, 3
  sll   $t8, $t8, 2
  lui   $t9, %hi(firing_animation_groups) 
  addiu $t9, %lo(firing_animation_groups) # addiu $t9, $t9, 0x68d8
  addu  $t1, $t7, $t8
  addu  $v0, $t1, $t9
  lw    $v1, 4($v0)
  lw    $t2, ($v0)
  lui   $t3, %hi(ptr_animation_table) 
  beqz  $v1, .L7F08B840
   sw    $t2, 0x7c($sp)
  lw    $t3, %lo(ptr_animation_table)($t3)
  addu  $t4, $v1, $t3
  sw    $t4, 0x9c($sp)
.L7F08B840:
  lwc1  $f6, 8($v0)
  lwc1  $f8, 0x10($v0)
  lwc1  $f2, 0xc($v0)
  mul.s $f12, $f12, $f6
  swc1  $f8, 0x90($sp)
  lw    $a2, 0x1284($t0)
.L7F08B858:
  lw    $t5, 0x7c($sp)
  lw    $t6, 0x9c($sp)
  li    $v0, 1
  beql  $t5, $zero, .L7F08B880
   lw    $t8, 0x9c($sp)
  bnezl $t6, .L7F08B880
   lw    $t8, 0x9c($sp)
  lw    $t7, ($t5)
  sw    $t7, 0x9c($sp)
  lw    $t8, 0x9c($sp)
.L7F08B880:
  beql  $t8, $a2, .L7F08B890
   c.le.s $f14, $f2
  sw    $v0, 0x54($sp)
  c.le.s $f14, $f2
.L7F08B890:
  lw    $v0, 0x54($sp)
  bc1fl .L7F08B8C8
   c.lt.s $f2, $f14
  lw    $a0, 0xd4($t0)
  lb    $t1, 0x26($a0)
  beql  $t1, $zero, .L7F08B8C4
   li    $v0, 1
  lwc1  $f10, 0x90($a0)
  c.eq.s $f2, $f10
  nop   
  bc1tl .L7F08B8C8
   c.lt.s $f2, $f14
  li    $v0, 1
.L7F08B8C4:
  c.lt.s $f2, $f14
.L7F08B8C8:
  nop   
  bc1f  .L7F08B8E8
   nop   
  lw    $t9, 0xd4($t0)
  lb    $t2, 0x26($t9)
  beqz  $t2, .L7F08B8E8
   nop   
  li    $v0, 1
.L7F08B8E8:
  beql  $v0, $zero, .L7F08B9C0
   lwc1  $f6, 0x1288($t0)
  lw    $a0, 0xd4($t0)
  lw    $a1, 0x9c($sp)
  move  $a2, $zero
  lw    $t3, 0x54($a0)
  li    $at, 0x41800000 # 16.000000
  bnezl $t3, .L7F08B9B4
   lw    $t1, ($s1)
  c.le.s $f14, $f2
  mtc1  $at, $f18
  bc1fl .L7F08B928
   mov.s $f0, $f14
  b     .L7F08B928
   mov.s $f0, $f2
  mov.s $f0, $f14
.L7F08B928:
  mfc1  $a3, $f0
  swc1  $f12, 0x10($sp)
  swc1  $f18, 0x14($sp)
  swc1  $f2, 0x94($sp)
  jal   sub_GAME_7F06FCA8
   swc1  $f12, 0x98($sp)
  lwc1  $f2, 0x94($sp)
  mtc1  $zero, $f14
  lw    $t4, 0x9c($sp)
  lw    $t6, ($s1)
  c.le.s $f14, $f2
  lwc1  $f12, 0x98($sp)
  sw    $t4, 0x1284($t6)
  lw    $t5, ($s1)
  lui   $a2, 0x4180
  bc1f  .L7F08B984
   swc1  $f12, 0x1288($t5)
  lw    $t7, ($s1)
  mfc1  $a1, $f2
  jal   sub_GAME_7F06FDCC
   lw    $a0, 0xd4($t7)
  mtc1  $zero, $f14
  nop   
.L7F08B984:
  lwc1  $f4, 0x90($sp)
  c.le.s $f14, $f4
  nop   
  bc1fl .L7F08B9B4
   lw    $t1, ($s1)
  lw    $t8, ($s1)
  mfc1  $a1, $f4
  jal   sub_GAME_7F06FDE8
   lw    $a0, 0xd4($t8)
  mtc1  $zero, $f14
  nop   
  lw    $t1, ($s1)
.L7F08B9B4:
  b     .L7F08B9FC
   lw    $a2, 0x1284($t1)
  lwc1  $f6, 0x1288($t0)
.L7F08B9C0:
  c.eq.s $f12, $f6
  nop   
  bc1tl .L7F08BA00
   lw    $t3, 0x9c($sp)
  lw    $a0, 0xd4($t0)
  mfc1  $a1, $f12
  swc1  $f12, 0x98($sp)
  jal   sub_GAME_7F06FE4C
   lui   $a2, 0x3f80
  lwc1  $f12, 0x98($sp)
  lw    $t9, ($s1)
  mtc1  $zero, $f14
  swc1  $f12, 0x1288($t9)
  lw    $t2, ($s1)
  lw    $a2, 0x1284($t2)
.L7F08B9FC:
  lw    $t3, 0x9c($sp)
.L7F08BA00:
  lw    $t4, 0x7c($sp)
  bnel  $t3, $a2, .L7F08BA64
   lw    $v0, 0xf0($sp)
  beqz  $t4, .L7F08BA44
   lw    $t7, 0xf0($sp)
  lw    $a0, 0xf0($sp)
  move  $a2, $zero
  li    $a3, 1
  lhu   $t6, 0x12($a0)
  andi  $t5, $t6, 0xfbff
  sh    $t5, 0x12($a0)
  lwc1  $f8, 0x8c($sp)
  lw    $a1, 0x7c($sp)
  jal   sub_GAME_7F02D048
   swc1  $f8, 0x10($sp)
  b     .L7F08BA64
   lw    $v0, 0xf0($sp)
.L7F08BA44:
  lhu   $t8, 0x12($t7)
  swc1  $f14, 0x154($t7)
  swc1  $f14, 0x150($t7)
  ori   $t1, $t8, 0x400
  sh    $t1, 0x12($t7)
  lwc1  $f10, 0x8c($sp)
  swc1  $f10, 0x158($t7)
  lw    $v0, 0xf0($sp)
.L7F08BA64:
  lwc1  $f18, 0x88($sp)
  li    $t9, 10
  sb    $t9, 0xe($v0)
  swc1  $f18, 0x15c($v0)
  lw    $t2, ($s1)
.L7F08BA78:
  lw    $v1, 0xf8($sp)
  lw    $v0, 0xf0($sp)
  lwc1  $f4, 0x48c($t2)
  addiu $a1, $sp, 0x70
  move  $s0, $zero
  swc1  $f4, 8($v1)
  lw    $t3, ($s1)
  lwc1  $f6, 0x490($t3)
  swc1  $f6, 0xc($v1)
  lw    $t4, ($s1)
  lwc1  $f8, 0x494($t4)
  swc1  $f8, 0x10($v1)
  lw    $t6, ($s1)
  lw    $t5, 0x488($t6)
  sw    $t5, 0x14($v1)
  jal   getsuboffset
   lw    $a0, 0x1c($v0)
  lw    $v0, 0xf8($sp)
  lw    $t8, 0xf0($sp)
  addiu $a1, $sp, 0x70
  lwc1  $f10, 8($v0)
  swc1  $f10, 0x70($sp)
  lwc1  $f18, 0x10($v0)
  swc1  $f18, 0x78($sp)
  jal   setsuboffset
   lw    $a0, 0x1c($t8)
  lw    $t0, ($s1)
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f0
  lwc1  $f6, 0x148($t0)
  lwc1  $f4, 0x1280($t0)
  lui   $at, %hi(D_800552D0)
  sub.s $f8, $f0, $f6
  lwc1  $f18, %lo(D_800552D0)($at)
  lw    $t1, 0xf0($sp)
  add.s $f10, $f4, $f8
  lw    $a0, 0x1c($t1)
  mul.s $f6, $f10, $f18
  div.s $f4, $f6, $f0
  mfc1  $a1, $f4
  jal   setsubroty
   nop   
  lw    $a0, 0xf0($sp)
  li    $t2, 25
  move  $a1, $zero
  lw    $t7, 0x14($a0)
  sb    $t2, 7($a0)
  ori   $t9, $t7, 1
  sw    $t9, 0x14($a0)
  lw    $t3, 0x7c($sp)
  sw    $t3, 0x2c($a0)
  lw    $t4, ($s1)
  jal   sub_GAME_7F02D118
   lb    $a2, 0x87d($t4)
  lw    $t6, ($s1)
  lw    $a0, 0xf0($sp)
  li    $a1, 1
  jal   sub_GAME_7F02D118
   lb    $a2, 0xc25($t6)
  jal   sub_GAME_7F020EF0
   lw    $a0, 0xf8($sp)
  sw    $v0, 0xa0($sp)
  move  $a3, $zero
  move  $v1, $zero
.L7F08BB78:
  lw    $t5, ($s1)
  lw    $a0, 0xf0($sp)
  move  $a1, $s0
  addu  $a2, $t5, $v1
  addiu $a2, $a2, 0x2a18
  sw    $v1, 0x34($sp)
  jal   sub_GAME_7F02D630
   sw    $a3, 0x38($sp)
  lw    $v1, 0x34($sp)
  beqz  $v0, .L7F08BBBC
   lw    $a3, 0x38($sp)
  lw    $t1, ($s1)
  lui   $t8, %hi(D_80048380) 
  lw    $t8, %lo(D_80048380)($t8)
  addu  $t7, $t1, $a3
  b     .L7F08BC30
   sw    $t8, 0x2a30($t7)
.L7F08BBBC:
  lw    $t0, ($s1)
  lui   $t3, %hi(D_80048380) 
  lw    $t3, %lo(D_80048380)($t3)
  addu  $t9, $t0, $a3
  lw    $t2, 0x2a30($t9)
  addiu $t4, $t3, -1
  sll   $v0, $s0, 3
  slt   $at, $t2, $t4
  beqz  $at, .L7F08BC30
   subu  $v0, $v0, $s0
  sll   $v0, $v0, 2
  addu  $v0, $v0, $s0
  sll   $v0, $v0, 2
  addu  $v0, $v0, $s0
  sll   $v0, $v0, 3
  addu  $t6, $t0, $v0
  lwc1  $f8, 0xb58($t6)
  addu  $t5, $t0, $v1
  swc1  $f8, 0x2a18($t5)
  lw    $t0, ($s1)
  addu  $t1, $t0, $v0
  lwc1  $f10, 0xb5c($t1)
  addu  $t8, $t0, $v1
  swc1  $f10, 0x2a1c($t8)
  lw    $t0, ($s1)
  addu  $t7, $t0, $v0
  lwc1  $f18, 0xb60($t7)
  addu  $t9, $t0, $v1
  swc1  $f18, 0x2a20($t9)
.L7F08BC30:
  addiu $s0, $s0, 1
  li    $at, 2
  addiu $a3, $a3, 4
  bne   $s0, $at, .L7F08BB78
   addiu $v1, $v1, 0xc
  lw    $t3, 0xf0($sp)
  lhu   $t2, 0x12($t3)
  ori   $t4, $t2, 0x800
  sh    $t4, 0x12($t3)
  lw    $t6, ($s1)
  lw    $t5, 0xf8($sp)
  lwc1  $f6, 0x48c($t6)
  swc1  $f6, 8($t5)
  lw    $t1, ($s1)
  lwc1  $f4, 0x490($t1)
  swc1  $f4, 0xc($t5)
  lw    $t8, ($s1)
  lwc1  $f8, 0x494($t8)
  swc1  $f8, 0x10($t5)
  lw    $t7, ($s1)
  lw    $t9, 0x488($t7)
  sw    $t9, 0x14($t5)
  b     .L7F08BCA4
   lw    $v0, 0xa0($sp)
.L7F08BC90:
  lw    $t2, 0xf8($sp)
.L7F08BC94:
  move  $v0, $zero
  lbu   $t4, 1($t2)
  andi  $t3, $t4, 0xfffd
  sb    $t3, 1($t2)
.L7F08BCA4:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0xf8
");

int sub_GAME_7F08BCB8(int a0) {
  return a0;
}

asm(R"
glabel sub_GAME_7F08BCC0
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lw    $t6, 4($a0)
  beql  $t6, $zero, .L7F08BCE4
   lw    $ra, 0x14($sp)
  jal   sub_GAME_7F021BFC
   nop   
  move  $a1, $v0
  lw    $ra, 0x14($sp)
.L7F08BCE4:
  addiu $sp, $sp, 0x18
  move  $v0, $a1
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F08BCF4
  lui   $t6, (0x01020040 >> 16) # lui $t6, 0x102
  ori   $t6, (0x01020040 & 0xFFFF) # ori $t6, $t6, 0x40
  sw    $t6, ($a0)
  lui   $t7, %hi(pPlayer) 
  lw    $t7, %lo(pPlayer)($t7)
  addiu $v0, $a0, 8
  lw    $t8, 0x5c($t7)
  jr    $ra
   sw    $t8, 4($a0)
");

asm(R"
glabel sub_GAME_7F08BD18
  addiu $sp, $sp, -0x58
  sw    $ra, 0x14($sp)
  sw    $a0, 0x58($sp)
  jal   matrix_4x4_copy
   addiu $a1, $sp, 0x18
  addiu $a0, $sp, 0x18
  jal   sub_GAME_7F058C9C
   lw    $a1, 0x58($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x58
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F08BD48
  addiu $sp, $sp, -0x78
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s0, 0x18($sp)
  move  $s3, $a1
  move  $s4, $a0
  sw    $ra, 0x2c($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  blez  $a1, .L7F08BDA4
   move  $s0, $zero
  move  $s1, $a0
  addiu $s2, $sp, 0x38
.L7F08BD7C:
  move  $a0, $s1
  jal   matrix_4x4_copy
   move  $a1, $s2
  sll   $t6, $s0, 6
  addu  $a1, $t6, $s4
  jal   sub_GAME_7F058C9C
   move  $a0, $s2
  addiu $s0, $s0, 1
  bne   $s0, $s3, .L7F08BD7C
   addiu $s1, $s1, 0x40
.L7F08BDA4:
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  lw    $s3, 0x24($sp)
  lw    $s4, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x78
");

asm(R"
glabel sub_GAME_7F08BDC4
  addiu $sp, $sp, -0x60
  sw    $ra, 0x14($sp)
  sw    $a0, 0x60($sp)
  jal   matrix_4x4_copy
   addiu $a1, $sp, 0x20
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lwc1  $f4, 0x50($sp)
  lwc1  $f10, 0x54($sp)
  lwc1  $f6, 0x44($v0)
  addiu $a0, $sp, 0x20
  lw    $a1, 0x60($sp)
  sub.s $f8, $f4, $f6
  lwc1  $f4, 0x58($sp)
  swc1  $f8, 0x50($sp)
  lwc1  $f16, 0x48($v0)
  sub.s $f18, $f10, $f16
  swc1  $f18, 0x54($sp)
  lwc1  $f6, 0x4c($v0)
  sub.s $f8, $f4, $f6
  jal   sub_GAME_7F058C9C
   swc1  $f8, 0x58($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x60
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F08BE2C
  addiu $sp, $sp, -0x78
  sw    $s4, 0x24($sp)
  sw    $s3, 0x20($sp)
  sw    $s0, 0x14($sp)
  move  $s3, $a1
  move  $s4, $a0
  sw    $ra, 0x2c($sp)
  sw    $s5, 0x28($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  blez  $a1, .L7F08BEC8
   move  $s0, $zero
  lui   $s5, %hi(pPlayer)
  addiu $s5, %lo(pPlayer) # addiu $s5, $s5, -0x5f50
  move  $s1, $a0
  addiu $s2, $sp, 0x38
.L7F08BE6C:
  move  $a0, $s1
  jal   matrix_4x4_copy
   move  $a1, $s2
  lw    $v0, ($s5)
  lwc1  $f4, 0x68($sp)
  lwc1  $f10, 0x6c($sp)
  lwc1  $f6, 0x44($v0)
  sll   $t6, $s0, 6
  addu  $a1, $t6, $s4
  sub.s $f8, $f4, $f6
  lwc1  $f4, 0x70($sp)
  move  $a0, $s2
  swc1  $f8, 0x68($sp)
  lwc1  $f16, 0x48($v0)
  sub.s $f18, $f10, $f16
  swc1  $f18, 0x6c($sp)
  lwc1  $f6, 0x4c($v0)
  sub.s $f8, $f4, $f6
  jal   sub_GAME_7F058C9C
   swc1  $f8, 0x70($sp)
  addiu $s0, $s0, 1
  bne   $s0, $s3, .L7F08BE6C
   addiu $s1, $s1, 0x40
.L7F08BEC8:
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  lw    $s4, 0x24($sp)
  lw    $s5, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x78
");

asm(R"
glabel sub_GAME_7F08BEEC
  addiu $sp, $sp, -0x80
  sw    $s5, 0x28($sp)
  sw    $s4, 0x24($sp)
  sw    $s1, 0x18($sp)
  move  $s4, $a1
  move  $s5, $a0
  sw    $ra, 0x2c($sp)
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s0, 0x14($sp)
  blez  $a1, .L7F08BF94
   move  $s1, $zero
  lui   $s3, %hi(pPlayer)
  addiu $s3, %lo(pPlayer) # addiu $s3, $s3, -0x5f50
  move  $s0, $a0
  addiu $s2, $sp, 0x40
.L7F08BF2C:
  jal   sub_GAME_7F078444
   nop   
  move  $a0, $v0
  move  $a1, $s0
  jal   sub_GAME_7F05818C
   move  $a2, $s2
  lw    $v0, ($s3)
  lwc1  $f4, 0x70($sp)
  lwc1  $f10, 0x74($sp)
  lwc1  $f6, 0x38($v0)
  sll   $t6, $s1, 6
  addu  $a1, $t6, $s5
  sub.s $f8, $f4, $f6
  lwc1  $f4, 0x78($sp)
  move  $a0, $s2
  swc1  $f8, 0x70($sp)
  lwc1  $f16, 0x3c($v0)
  sub.s $f18, $f10, $f16
  swc1  $f18, 0x74($sp)
  lwc1  $f6, 0x40($v0)
  sub.s $f8, $f4, $f6
  jal   sub_GAME_7F058C9C
   swc1  $f8, 0x78($sp)
  addiu $s1, $s1, 1
  bne   $s1, $s4, .L7F08BF2C
   addiu $s0, $s0, 0x40
.L7F08BF94:
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  lw    $s4, 0x24($sp)
  lw    $s5, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x80
");

int get_mission_timer(void) {
  extern int mission_timer;
  return mission_timer;
}

void trigger_explosions_around_player(int delay){
  extern int dword_CODE_bss_8007999C;
  extern int dword_CODE_bss_800799A0;
  extern int global_timer;

  D_80036444 = 1;
  dword_CODE_bss_8007999C = delay + global_timer;
  dword_CODE_bss_800799A0 = 0;
}
