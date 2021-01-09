asm(R"
glabel truncf
  mtc1  $zero, $f4
  nop   
  c.le.s $f4, $f12
  nop   
  bc1fl .L7F05C394
   trunc.w.s $f10, $f12
  trunc.w.s $f6, $f12
  mfc1  $t7, $f6
  nop   
  mtc1  $t7, $f8
  jr    $ra
   cvt.s.w $f0, $f8

  trunc.w.s $f10, $f12
.L7F05C394:
  li    $at, 0x3F800000 # 1.000000
  mfc1  $t9, $f10
  nop   
  mtc1  $t9, $f16
  nop   
  cvt.s.w $f2, $f16
  c.eq.s $f12, $f2
  nop   
  bc1fl .L7F05C3C8
   mtc1  $at, $f18
  jr    $ra
   mov.s $f0, $f2

  mtc1  $at, $f18
.L7F05C3C8:
  nop   
  sub.s $f0, $f2, $f18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F05C3D8
  mtc1  $zero, $f4
  nop   
  c.le.s $f4, $f12
  nop   
  bc1fl .L7F05C404
   trunc.w.s $f8, $f12
  trunc.w.s $f6, $f12
  mfc1  $v0, $f6
  jr    $ra
   nop   

  trunc.w.s $f8, $f12
.L7F05C404:
  mfc1  $v1, $f8
  nop   
  mtc1  $v1, $f10
  addiu $v0, $v1, -1
  cvt.s.w $f16, $f10
  c.eq.s $f12, $f16
  nop   
  bc1f  .L7F05C430
   nop   
  jr    $ra
   move  $v0, $v1

.L7F05C430:
  jr    $ra
   nop   
");
