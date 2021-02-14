asm(R"
glabel cosf
  lui   $at, %hi(D_800536C0)
  lwc1  $f10, %lo(D_800536C0)($at)
  add.s $f12, $f12, $f10
");

asm(R"
.late_rodata
glabel D_800536C0
.word 0x3fc90fda /*1.5707963*/
glabel D_800536C4
.word 0x362edef8 /*0.0000026057805*/
glabel D_800536C8
.word 0xb94fb7ff /*-0.00019809602*/
glabel D_800536CC
.word 0x3c08876a /*0.0083330665*/
glabel D_800536D0
.word 0xbe2aaaa6 /*-0.1666666*/
glabel D_800536D4
.word 0x3ea2f983 /*0.31830987*/
glabel D_800536D8
.word 0x40490fdb /*3.1415927*/
glabel D_800536DC
.word 0x330885a3 /*3.178650856*/
glabel D_800536E0
.word 0x362edef8 /*0.0000026057805*/
glabel D_800536E4
.word 0xb94fb7ff /*-0.00019809602*/
glabel D_800536E8
.word 0x3c08876a /*0.0083330665*/
glabel D_800536EC
.word 0xbe2aaaa6 /*-0.1666666*/

.text
glabel sinf
  mfc1  $t0, $f12
  nop   
  sra   $t0, $t0, 0x16
  andi  $t0, $t0, 0x1ff
  slti  $at, $t0, 0xff
  beqz  $at, .L7F057F28
   nop   
  slti  $at, $t0, 0xe6
  bnez  $at, .L7F057FC4
   mov.s $f0, $f12
  mul.s $f16, $f12, $f12
  lui   $at, %hi(D_800536C4)
  lwc1  $f18, %lo(D_800536C4)($at)
  mul.s $f18, $f18, $f16
  lui   $at, %hi(D_800536C8)
  lwc1  $f10, %lo(D_800536C8)($at)
  add.s $f18, $f10, $f18
  mul.s $f18, $f18, $f16
  lui   $at, %hi(D_800536CC)
  lwc1  $f10, %lo(D_800536CC)($at)
  add.s $f18, $f10, $f18
  mul.s $f18, $f18, $f16
  lui   $at, %hi(D_800536D0)
  lwc1  $f10, %lo(D_800536D0)($at)
  add.s $f18, $f10, $f18
  mul.s $f18, $f18, $f16
  nop   
  mul.s $f18, $f18, $f12
  add.s $f0, $f18, $f12
  j     .L7F057FC4
   nop   

.L7F057F28:
  slti  $at, $t0, 0x136
  beql  $at, $zero, .L7F057FC4
   mtc1  $zero, $f0
  lui   $at, %hi(D_800536D4)
  lwc1  $f16, %lo(D_800536D4)($at)
  mul.s $f16, $f16, $f12
  round.w.s $f16, $f16
  mfc1  $t1, $f16
  cvt.s.w $f16, $f16
  lui   $at, %hi(D_800536D8)
  lwc1  $f18, %lo(D_800536D8)($at)
  mul.s $f18, $f18, $f16
  sub.s $f12, $f12, $f18
  lui   $at, %hi(D_800536DC)
  lwc1  $f18, %lo(D_800536DC)($at)
  mul.s $f18, $f18, $f16
  sub.s $f12, $f12, $f18
  mul.s $f16, $f12, $f12
  lui   $at, %hi(D_800536E0)
  lwc1  $f18, %lo(D_800536E0)($at)
  mul.s $f18, $f18, $f16
  lui   $at, %hi(D_800536E4)
  lwc1  $f10, %lo(D_800536E4)($at)
  add.s $f18, $f10, $f18
  mul.s $f18, $f18, $f16
  lui   $at, %hi(D_800536E8)
  lwc1  $f10, %lo(D_800536E8)($at)
  add.s $f18, $f10, $f18
  mul.s $f18, $f18, $f16
  lui   $at, %hi(D_800536EC)
  lwc1  $f10, %lo(D_800536EC)($at)
  add.s $f18, $f10, $f18
  mul.s $f18, $f18, $f16
  nop   
  mul.s $f18, $f18, $f12
  add.s $f0, $f18, $f12
  andi  $t1, $t1, 1
  bnezl $t1, .L7F057FC4
  neg.s $f0, $f0

.L7F057FC4:
  jr    $ra
  nop
");

