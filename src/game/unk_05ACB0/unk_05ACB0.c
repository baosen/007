asm(R"
.late_rodata
glabel D_80053720
.word 0x46fffe00 /*32767.0*/
glabel D_80053724
.word 0x40490fdb /*3.1415927*/
glabel D_80053728
.word 0x477fff00 /*65535.0*/

.text
glabel sub_GAME_7F05ACB0
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  c.le.s $f4, $f12
  li    $at, 0xBF800000 # -1.000000
  bc1fl .L7F05ACDC
   mtc1  $at, $f6
  b     .L7F05AD14
   li    $a0, 32767
  mtc1  $at, $f6
.L7F05ACDC:
  lui   $at, %hi(D_80053720)
  c.le.s $f12, $f6
  nop   
  bc1f  .L7F05ACF8
   nop   
  b     .L7F05AD14
   li    $a0, -32767
.L7F05ACF8:
  lwc1  $f8, %lo(D_80053720)($at)
  mul.s $f10, $f12, $f8
  trunc.w.s $f16, $f10
  mfc1  $a0, $f16
  nop   
  sll   $t7, $a0, 0x10
  sra   $a0, $t7, 0x10
.L7F05AD14:
  jal   sub_GAME_7F05ABF0
   nop   
  mtc1  $v0, $f18
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F05AD38
   cvt.s.w $f4, $f18
  mtc1  $at, $f6
  nop   
  add.s $f4, $f4, $f6
.L7F05AD38:
  lui   $at, %hi(D_80053724)
  lwc1  $f8, %lo(D_80053724)($at)
  lw    $ra, 0x14($sp)
  lui   $at, %hi(D_80053728)
  mul.s $f10, $f4, $f8
  lwc1  $f16, %lo(D_80053728)($at)
  addiu $sp, $sp, 0x18
  jr    $ra
   div.s $f0, $f10, $f16
");

float sub_GAME_7F05AD5C(float arg0) {
  short phi_a0;
  if (arg0 >= 1.0f) {
    phi_a0 = (unsigned short)0x7FFF;
  } else if (arg0 <= -1.0f) {
    phi_a0 = (unsigned short)-0x7FFF;
  } else {
    phi_a0 = (short)(int)(arg0 * 32767.0f);
  }
  return ((float)sub_GAME_7F05AC44(phi_a0) * 3.1415927f) / 65535.0f;
}
