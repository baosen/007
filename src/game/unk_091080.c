int dword_CODE_bss_80079E20;

int D_80037010 = 0;
float stanbondx = 0.0f;
int stanbondy = 0;
int stanbondz = 0;
int D_80037020 = 0;
int D_80037024 = 0;
float D_80037028 = -1.0;
int D_8003702C = 0;
float D_80037030 = 1.0;
int D_80037034 = 0;
int D_80037038 = 0;
float D_8003703C = 1.0;
int D_80037040 = 0;
int D_80037044 = 0;
float D_80037048 = 1.0;
int D_8003704C = 0;
float D_80037050 = 1.0;
int D_80037054 = 0;
float D_80037058 = 1.0;
float D_8003705C = 1.0;
int D_80037060 = 0;
int D_80037064 = 0;
int D_80037068 = 0;

asm(R"
.late_rodata
glabel D_80055850
.word 0x3c8efa35 /*0.017453292*/
glabel D_80055854
.word 0x3c8efa35 /*0.017453292*/
glabel D_80055858
.word 0x3c8efa35 /*0.017453292*/
glabel D_8005585C
.word 0x3c8efa35 /*0.017453292*/

.text
glabel sub_GAME_7F091080
  addiu $sp, $sp, -0x18
  sw    $a0, 0x18($sp)
  lb    $t7, 0x1b($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f0
  sll   $a3, $a1, 0x18
  sra   $t6, $a3, 0x18
  slti  $at, $t7, -3
  move  $a3, $t6
  sw    $ra, 0x14($sp)
  sw    $a1, 0x1c($sp)
  sw    $a2, 0x20($sp)
  beqz  $at, .L7F0910C4
   mov.s $f2, $f0
  addiu $t8, $t7, 3
  b     .L7F0910E0
   sb    $t8, 0x1b($sp)
.L7F0910C4:
  lb    $t9, 0x1b($sp)
  slti  $at, $t9, 4
  bnez  $at, .L7F0910DC
   addiu $t0, $t9, -3
  b     .L7F0910E0
   sb    $t0, 0x1b($sp)
.L7F0910DC:
  sb    $zero, 0x1b($sp)
.L7F0910E0:
  slti  $at, $a3, -3
  beqz  $at, .L7F0910FC
   lhu   $a1, 0x22($sp)
  addiu $a3, $a3, 3
  sll   $t1, $a3, 0x18
  b     .L7F091118
   sra   $a3, $t1, 0x18
.L7F0910FC:
  slti  $at, $a3, 4
  bnez  $at, .L7F091114
   addiu $a3, $a3, -3
  sll   $t3, $a3, 0x18
  b     .L7F091118
   sra   $a3, $t3, 0x18
.L7F091114:
  move  $a3, $zero
.L7F091118:
  andi  $t5, $a1, 0x30
  bnez  $t5, .L7F091334
   andi  $t6, $a1, 0x2000
  beqz  $t6, .L7F09113C
   lui   $t7, %hi(D_80037054) 
  li    $at, 0x40A00000 # 5.000000
  mtc1  $at, $f4
  nop   
  div.s $f2, $f0, $f4
.L7F09113C:
  lhu   $t7, %lo(D_80037054)($t7)
  mtc1  $a3, $f8
  andi  $t2, $a1, 0x101
  not   $t8, $t7
  and   $v0, $a1, $t8
  andi  $t9, $v0, 0x8000
  andi  $t0, $v0, 0x4000
  beqz  $t9, .L7F091170
   cvt.s.w $f0, $f8
  lui   $at, %hi(D_80037050)
  lwc1  $f12, %lo(D_80037050)($at)
  add.s $f12, $f12, $f12
  swc1  $f12, %lo(D_80037050)($at)
.L7F091170:
  lui   $at, %hi(D_80037050)
  beqz  $t0, .L7F091190
   lwc1  $f12, %lo(D_80037050)($at)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f6
  nop   
  mul.s $f12, $f12, $f6
  nop   
.L7F091190:
  lui   $at, %hi(D_80037040)
  lwc1  $f16, %lo(D_80037040)($at)
  lui   $a0, %hi(stanbondx)
  addiu $a0, %lo(stanbondx) # addiu $a0, $a0, 0x7014
  mul.s $f4, $f0, $f16
  lwc1  $f10, ($a0)
  lui   $at, %hi(D_8003703C)
  andi  $t1, $a1, 0x202
  lui   $v0, %hi(D_80037044)
  addiu $v0, %lo(D_80037044) # addiu $v0, $v0, 0x7044
  andi  $t5, $a1, 0x400
  mul.s $f6, $f4, $f2
  andi  $t6, $a1, 8
  andi  $t7, $a1, 4
  mul.s $f8, $f6, $f12
  lwc1  $f6, 8($a0)
  add.s $f4, $f10, $f8
  neg.s $f10, $f0
  swc1  $f4, ($a0)
  lwc1  $f18, %lo(D_8003703C)($at)
  li    $at, 0x41A00000 # 20.000000
  mul.s $f8, $f10, $f18
  nop   
  mul.s $f4, $f8, $f2
  nop   
  mul.s $f10, $f4, $f12
  add.s $f8, $f6, $f10
  beqz  $t1, .L7F091244
   swc1  $f8, 8($a0)
  mtc1  $at, $f0
  lwc1  $f4, ($a0)
  mul.s $f6, $f0, $f18
  nop   
  mul.s $f10, $f6, $f2
  nop   
  mul.s $f8, $f10, $f12
  lwc1  $f10, 8($a0)
  sub.s $f6, $f4, $f8
  mul.s $f4, $f0, $f16
  swc1  $f6, ($a0)
  mul.s $f8, $f4, $f2
  nop   
  mul.s $f6, $f8, $f12
  sub.s $f4, $f10, $f6
  swc1  $f4, 8($a0)
.L7F091244:
  li    $at, 0x41A00000 # 20.000000
  mtc1  $at, $f0
  beql  $t2, $zero, .L7F091290
   lb    $t3, 0x1b($sp)
  mul.s $f10, $f0, $f18
  lwc1  $f8, ($a0)
  mul.s $f6, $f10, $f2
  nop   
  mul.s $f4, $f6, $f12
  lwc1  $f6, 8($a0)
  add.s $f10, $f8, $f4
  mul.s $f8, $f0, $f16
  swc1  $f10, ($a0)
  mul.s $f4, $f8, $f2
  nop   
  mul.s $f10, $f4, $f12
  add.s $f8, $f6, $f10
  swc1  $f8, 8($a0)
  lb    $t3, 0x1b($sp)
.L7F091290:
  li    $at, 0x3E000000 # 0.125000
  mtc1  $at, $f8
  mtc1  $t3, $f4
  lui   $v1, %hi(D_80037038)
  addiu $v1, %lo(D_80037038) # addiu $v1, $v1, 0x7038
  cvt.s.w $f6, $f4
  andi  $t4, $a1, 0x800
  lui   $at, %hi(D_80037050)
  mul.s $f10, $f6, $f2
  lwc1  $f6, ($v1)
  mul.s $f4, $f10, $f8
  add.s $f10, $f6, $f4
  beqz  $t4, .L7F0912D8
   swc1  $f10, ($v1)
  add.s $f6, $f2, $f2
  lwc1  $f8, ($v0)
  sub.s $f4, $f8, $f6
  swc1  $f4, ($v0)
.L7F0912D8:
  lui   $v0, %hi(D_80037044)
  beqz  $t5, .L7F0912F4
   addiu $v0, %lo(D_80037044) # addiu $v0, $v0, 0x7044
  add.s $f8, $f2, $f2
  lwc1  $f10, ($v0)
  add.s $f6, $f10, $f8
  swc1  $f6, ($v0)
.L7F0912F4:
  beqz  $t6, .L7F091310
   nop   
  mul.s $f10, $f0, $f2
  lwc1  $f4, 4($a0)
  mul.s $f8, $f10, $f12
  add.s $f6, $f4, $f8
  swc1  $f6, 4($a0)
.L7F091310:
  beqz  $t7, .L7F091334
   swc1  $f12, %lo(D_80037050)($at)
  mul.s $f4, $f0, $f2
  lwc1  $f10, 4($a0)
  lui   $at, %hi(D_80037050)
  mul.s $f8, $f4, $f12
  sub.s $f6, $f10, $f8
  swc1  $f6, 4($a0)
  swc1  $f12, %lo(D_80037050)($at)
.L7F091334:
  lui   $v1, %hi(D_80037038)
  addiu $v1, %lo(D_80037038) # addiu $v1, $v1, 0x7038
  mtc1  $zero, $f12
  lwc1  $f14, ($v1)
  lui   $v0, %hi(D_80037044)
  addiu $v0, %lo(D_80037044) # addiu $v0, $v0, 0x7044
  c.lt.s $f14, $f12
  lui   $at, 0x43b4
  bc1fl .L7F091384
   li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f2
  nop   
  add.s $f4, $f14, $f2
.L7F091368:
  swc1  $f4, ($v1)
  lwc1  $f14, ($v1)
  c.lt.s $f14, $f12
  nop   
  bc1tl .L7F091368
   add.s $f4, $f14, $f2
  li    $at, 0x43B40000 # 360.000000
.L7F091384:
  mtc1  $at, $f2
  lui   $at, %hi(D_80055850)
  c.le.s $f2, $f14
  nop   
  bc1fl .L7F0913BC
   lwc1  $f0, ($v0)
  sub.s $f10, $f14, $f2
.L7F0913A0:
  swc1  $f10, ($v1)
  lwc1  $f14, ($v1)
  c.le.s $f2, $f14
  nop   
  bc1tl .L7F0913A0
   sub.s $f10, $f14, $f2
  lwc1  $f0, ($v0)
.L7F0913BC:
  c.lt.s $f0, $f12
  nop   
  bc1fl .L7F0913EC
   c.le.s $f2, $f0
  add.s $f8, $f0, $f2
.L7F0913D0:
  swc1  $f8, ($v0)
  lwc1  $f0, ($v0)
  c.lt.s $f0, $f12
  nop   
  bc1tl .L7F0913D0
   add.s $f8, $f0, $f2
  c.le.s $f2, $f0
.L7F0913EC:
  nop   
  bc1f  .L7F091414
   nop   
  sub.s $f6, $f0, $f2
.L7F0913FC:
  swc1  $f6, ($v0)
  lwc1  $f0, ($v0)
  c.le.s $f2, $f0
  nop   
  bc1tl .L7F0913FC
   sub.s $f6, $f0, $f2
.L7F091414:
  lwc1  $f4, %lo(D_80055850)($at)
  mul.s $f12, $f14, $f4
  jal   cosf
   nop   
  lui   $at, %hi(D_8003703C)
  swc1  $f0, %lo(D_8003703C)($at)
  lui   $v1, %hi(D_80037038)
  addiu $v1, %lo(D_80037038) # addiu $v1, $v1, 0x7038
  lui   $at, %hi(D_80055854)
  lwc1  $f8, %lo(D_80055854)($at)
  lwc1  $f10, ($v1)
  mul.s $f12, $f10, $f8
  jal   sinf
   nop   
  lui   $at, %hi(D_80037040)
  swc1  $f0, %lo(D_80037040)($at)
  lui   $v0, %hi(D_80037044)
  addiu $v0, %lo(D_80037044) # addiu $v0, $v0, 0x7044
  lui   $at, %hi(D_80055858)
  lwc1  $f4, %lo(D_80055858)($at)
  lwc1  $f6, ($v0)
  mul.s $f12, $f6, $f4
  jal   cosf
   nop   
  lui   $at, %hi(D_80037048)
  swc1  $f0, %lo(D_80037048)($at)
  lui   $v0, %hi(D_80037044)
  addiu $v0, %lo(D_80037044) # addiu $v0, $v0, 0x7044
  lui   $at, %hi(D_8005585C)
  lwc1  $f8, %lo(D_8005585C)($at)
  lwc1  $f10, ($v0)
  mul.s $f12, $f10, $f8
  jal   sinf
   nop   
  lui   $a0, %hi(D_8003704C)
  addiu $a0, %lo(D_8003704C) # addiu $a0, $a0, 0x704c
  swc1  $f0, ($a0)
  lwc1  $f2, ($a0)
  lui   $v0, %hi(D_80037020)
  addiu $v0, %lo(D_80037020) # addiu $v0, $v0, 0x7020
  lui   $at, %hi(D_80037048)
  swc1  $f2, 4($v0)
  lwc1  $f14, %lo(D_80037048)($at)
  lui   $at, %hi(D_80037040)
  lwc1  $f16, %lo(D_80037040)($at)
  lui   $at, %hi(D_8003703C)
  neg.s $f4, $f14
  mul.s $f6, $f14, $f16
  neg.s $f8, $f2
  lui   $v1, %hi(D_8003702C)
  addiu $v1, %lo(D_8003702C) # addiu $v1, $v1, 0x702c
  lhu   $t8, 0x22($sp)
  swc1  $f6, ($v0)
  lwc1  $f18, %lo(D_8003703C)($at)
  lui   $at, %hi(D_80037054)
  swc1  $f14, 4($v1)
  mul.s $f10, $f4, $f18
  nop   
  mul.s $f6, $f8, $f16
  nop   
  mul.s $f4, $f2, $f18
  swc1  $f10, 8($v0)
  swc1  $f6, ($v1)
  swc1  $f4, 8($v1)
  sh    $t8, %lo(D_80037054)($at)
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f12
  jal   set_cur_player_fovy
   nop   
  lui   $v0, %hi(dword_CODE_bss_80079E20)
  addiu $v0, %lo(dword_CODE_bss_80079E20) # addiu $v0, $v0, -0x61e0
  lw    $t9, ($v0)
  li    $at, 1
  addiu $v1, $t9, 1
  bne   $v1, $at, .L7F09155C
   sw    $v1, ($v0)
  jal   remove_item_in_hand
   move  $a0, $zero
  jal   remove_item_in_hand
   li    $a0, 1
  b     .L7F091574
   lw    $ra, 0x14($sp)
.L7F09155C:
  li    $at, 4
  bnel  $v1, $at, .L7F091574
   lw    $ra, 0x14($sp)
  jal   solo_char_load
   nop   
  lw    $ra, 0x14($sp)
.L7F091574:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F091580
  addiu $sp, $sp, -0x18
  sw    $a0, 0x18($sp)
  sw    $ra, 0x14($sp)
  lui   $a0, %hi(stanbondx)
  lui   $a1, %hi(D_80037020)
  lui   $a2, %hi(D_8003702C)
  addiu $a2, %lo(D_8003702C) # addiu $a2, $a2, 0x702c
  addiu $a1, %lo(D_80037020) # addiu $a1, $a1, 0x7020
  jal   sub_GAME_7F0876C4
   addiu $a0, %lo(stanbondx) # addiu $a0, $a0, 0x7014
  lw    $ra, 0x14($sp)
  lw    $v0, 0x18($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0915BC
  lui   $v0, %hi(D_80037058)
  addiu $v0, %lo(D_80037058) # addiu $v0, $v0, 0x7058
  lwc1  $f4, ($v0)
  lui   $v1, %hi(stanbondx)
  addiu $v1, %lo(stanbondx) # addiu $v1, $v1, 0x7014
  div.s $f0, $f4, $f12
  lwc1  $f6, ($v1)
  li    $at, 0x3F800000 # 1.000000
  lwc1  $f10, 4($v1)
  lwc1  $f18, 8($v1)
  swc1  $f12, ($v0)
  mul.s $f8, $f6, $f0
  mtc1  $at, $f6
  lui   $at, %hi(D_8003705C)
  mul.s $f16, $f10, $f0
  nop   
  mul.s $f4, $f18, $f0
  swc1  $f8, ($v1)
  swc1  $f16, 4($v1)
  div.s $f8, $f6, $f12
  swc1  $f4, 8($v1)
  jr    $ra
   swc1  $f8, %lo(D_8003705C)($at)
");

asm(R"
.late_rodata
glabel D_80055860
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F091618
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  jal   get_BONDdata_position
   nop   
  jal   get_curplay_horizontal_rotation_in_degrees
   nop   
  lui   $at, %hi(D_80055860)
  lwc1  $f4, %lo(D_80055860)($at)
  sub.s $f12, $f4, $f0
  jal   cosf
   swc1  $f12, 0x18($sp)
  jal   sinf
   lwc1  $f12, 0x18($sp)
  jal   cosf
   lwc1  $f12, 0x18($sp)
  jal   sinf
   lwc1  $f12, 0x18($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F09166C
  lui   $v0, %hi(stanbondx)
  lui   $v1, %hi(D_80037060)
  addiu $v1, %lo(D_80037060) # addiu $v1, $v1, 0x7060
  addiu $v0, %lo(stanbondx) # addiu $v0, $v0, 0x7014
  lwc1  $f4, ($v0)
  lwc1  $f6, ($v1)
  lwc1  $f8, 4($v0)
  lwc1  $f10, 4($v1)
  sub.s $f0, $f4, $f6
  lwc1  $f16, 8($v0)
  lwc1  $f18, 8($v1)
  sub.s $f2, $f8, $f10
  mul.s $f4, $f0, $f0
  addiu $sp, $sp, -0x18
  sub.s $f14, $f16, $f18
  mul.s $f6, $f2, $f2
  sw    $ra, 0x14($sp)
  mul.s $f10, $f14, $f14
  add.s $f8, $f4, $f6
  jal   sqrtf
   add.s $f12, $f8, $f10
  lui   $v0, %hi(stanbondx)
  addiu $v0, %lo(stanbondx) # addiu $v0, $v0, 0x7014
  lw    $ra, 0x14($sp)
  lui   $v1, %hi(D_80037060)
  lwc1  $f16, ($v0)
  lwc1  $f18, 4($v0)
  lwc1  $f4, 8($v0)
  addiu $v1, %lo(D_80037060) # addiu $v1, $v1, 0x7060
  addiu $sp, $sp, 0x18
  swc1  $f16, ($v1)
  swc1  $f18, 4($v1)
  jr    $ra
   swc1  $f4, 8($v1)
");

asm(R"
glabel sub_GAME_7F0916F4
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   get_BONDdata_position
   nop   
  lwc1  $f4, ($v0)
  lui   $v1, %hi(stanbondx)
  addiu $v1, %lo(stanbondx) # addiu $v1, $v1, 0x7014
  swc1  $f4, ($v1)
  lwc1  $f6, 4($v0)
  lw    $ra, 0x14($sp)
  lui   $at, %hi(dword_CODE_bss_80079E20)
  swc1  $f6, 4($v1)
  lwc1  $f8, 8($v0)
  addiu $sp, $sp, 0x18
  swc1  $f8, 8($v1)
  jr    $ra
   sw    $zero, %lo(dword_CODE_bss_80079E20)($at)
");
