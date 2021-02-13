asm(R"
.late_rodata
glabel D_80053700
.word 0x40490fdb /*3.1415927*/
glabel D_80053704
.word 0x3fc90fdb /*1.5707964*/
glabel D_80053708
.word 0x4096cbe4 /*4.712389*/
glabel D_8005370C
.word 0x40c90fdb /*6.2831855*/
glabel D_80053710
.word 0x3fc90fdb /*1.5707964*/
glabel D_80053714
.word 0x40490fdb /*3.1415927*/
glabel D_80053718
.word 0x40c90fdb /*6.2831855*/
.text
glabel convert_angle_using_inverse
  mtc1  $zero, $f16
  addiu $sp, $sp, -0x20
  sdc1  $f20, 0x10($sp)
  c.eq.s $f12, $f16
  mov.s $f20, $f12
  sw    $ra, 0x1c($sp)
  bc1fl .L7F05AA74
   c.eq.s $f14, $f16
  c.le.s $f16, $f14
  lui   $at, %hi(D_80053700)
  bc1f  .L7F05AA68
   nop   
  b     .L7F05AB50
   mov.s $f2, $f16
.L7F05AA68:
  b     .L7F05AB50
   lwc1  $f2, %lo(D_80053700)($at)
  c.eq.s $f14, $f16
.L7F05AA74:
  nop   
  bc1f  .L7F05AAA4
   nop   
  c.lt.s $f16, $f20
  lui   $at, %hi(D_80053708)
  bc1f  .L7F05AA9C
   nop   
  lui   $at, %hi(D_80053704)
  b     .L7F05AB50
   lwc1  $f2, %lo(D_80053704)($at)
.L7F05AA9C:
  b     .L7F05AB50
   lwc1  $f2, %lo(D_80053708)($at)
.L7F05AAA4:
  mul.s $f4, $f20, $f20
  swc1  $f14, 0x24($sp)
  mul.s $f6, $f14, $f14
  jal   sqrtf
   add.s $f12, $f4, $f6
  lwc1  $f14, 0x24($sp)
  mov.s $f2, $f0
  c.lt.s $f14, $f20
  nop   
  bc1fl .L7F05AB04
   div.s $f12, $f20, $f2
  jal   sub_GAME_7F05ACB0
   div.s $f12, $f14, $f0
  mtc1  $zero, $f16
  mov.s $f2, $f0
  lui   $at, %hi(D_8005370C)
  c.lt.s $f20, $f16
  nop   
  bc1fl .L7F05AB54
   lw    $ra, 0x1c($sp)
  lwc1  $f8, %lo(D_8005370C)($at)
  b     .L7F05AB50
   sub.s $f2, $f8, $f0
  div.s $f12, $f20, $f2
.L7F05AB04:
  jal   sub_GAME_7F05ACB0
   swc1  $f14, 0x24($sp)
  lwc1  $f14, 0x24($sp)
  mtc1  $zero, $f16
  lui   $at, %hi(D_80053710)
  lwc1  $f10, %lo(D_80053710)($at)
  c.lt.s $f14, $f16
  lui   $at, %hi(D_80053714)
  sub.s $f12, $f10, $f0
  bc1f  .L7F05AB38
   mov.s $f2, $f12
  lwc1  $f18, %lo(D_80053714)($at)
  sub.s $f2, $f18, $f12
.L7F05AB38:
  c.lt.s $f2, $f16
  lui   $at, %hi(D_80053718)
  bc1fl .L7F05AB54
   lw    $ra, 0x1c($sp)
  lwc1  $f4, %lo(D_80053718)($at)
  add.s $f2, $f2, $f4
.L7F05AB50:
  lw    $ra, 0x1c($sp)
.L7F05AB54:
  ldc1  $f20, 0x10($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   mov.s $f0, $f2
");
