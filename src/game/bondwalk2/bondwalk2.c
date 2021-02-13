asm(R"
glabel sub_GAME_7F06ABB0
  addiu $sp, $sp, -0x40
  sw    $a0, 0x40($sp)
  sw    $a1, 0x44($sp)
  sw    $a2, 0x48($sp)
  sw    $a3, 0x4c($sp)
  mtc1  $zero, $f0
  lwc1  $f4, ($a2)
  c.lt.s $f0, $f4
  nop   
  bc1f  .L7F06AFE0
   nop   
  lwc1  $f6, 4($a2)
  lui   $t3, (0xBA001301 >> 16) # lui $t3, 0xba00
  c.lt.s $f0, $f6
  nop   
  bc1f  .L7F06AFE0
   nop   
  lw    $v0, ($a0)
  ori   $t3, (0xBA001301 & 0xFFFF) # ori $t3, $t3, 0x1301
  li    $at, 0x40800000 # 4.000000
  move  $v1, $v0
  sw    $t3, ($v1)
  sw    $zero, 4($v1)
  lw    $t9, 0x48($sp)
  lw    $t8, 0x44($sp)
  mtc1  $at, $f16
  lwc1  $f0, ($t9)
  lwc1  $f12, ($t8)
  lwc1  $f2, 4($t9)
  lwc1  $f14, 4($t8)
  sub.s $f8, $f12, $f0
  move  $a3, $zero
  move  $t0, $zero
  sub.s $f4, $f14, $f2
  mul.s $f10, $f8, $f16
  addiu $v0, $v0, 8
  mul.s $f6, $f4, $f16
  trunc.w.s $f18, $f10
  add.s $f10, $f0, $f12
  mfc1  $a1, $f18
  trunc.w.s $f8, $f6
  mul.s $f18, $f10, $f16
  add.s $f6, $f2, $f14
  mfc1  $a2, $f8
  mul.s $f8, $f6, $f16
  trunc.w.s $f4, $f18
  mfc1  $t1, $f4
  trunc.w.s $f10, $f8
  mfc1  $t2, $f10
  bltzl $t1, .L7F06AFC8
   move  $v1, $v0
  bltzl $t2, .L7F06AFC8
   move  $v1, $v0
  bgez  $a1, .L7F06AD30
   lw    $t4, 0x54($sp)
  beqz  $t4, .L7F06ACE4
   lw    $t7, 0x4c($sp)
  lw    $t5, 0x50($sp)
  negu  $t9, $a1
  subu  $t8, $t1, $a1
  multu $t9, $t5
  mflo  $t7
  sll   $t6, $t7, 5
  nop   
  div   $zero, $t6, $t8
  mflo  $t0
  bnez  $t8, .L7F06ACC4
   nop   
  break 7
.L7F06ACC4:
  li    $at, -1
  bne   $t8, $at, .L7F06ACDC
   lui   $at, 0x8000
  bne   $t6, $at, .L7F06ACDC
   nop   
  break 6
.L7F06ACDC:
  b     .L7F06AD30
   move  $a1, $zero
.L7F06ACE4:
  negu  $t9, $a1
  multu $t9, $t7
  subu  $t9, $t1, $a1
  lw    $t5, 0x50($sp)
  mflo  $t6
  sll   $t8, $t6, 5
  nop   
  div   $zero, $t8, $t9
  mflo  $a3
  bnez  $t9, .L7F06AD14
   nop   
  break 7
.L7F06AD14:
  li    $at, -1
  bne   $t9, $at, .L7F06AD2C
   lui   $at, 0x8000
  bne   $t8, $at, .L7F06AD2C
   nop   
  break 6
.L7F06AD2C:
  move  $a1, $zero
.L7F06AD30:
  lw    $t4, 0x54($sp)
  bgez  $a2, .L7F06ADE0
   lw    $t5, 0x50($sp)
  beqz  $t4, .L7F06AD98
   negu  $t8, $a2
  lw    $t6, 0x4c($sp)
  negu  $t7, $a2
  multu $t7, $t6
  subu  $t7, $t2, $a2
  mflo  $t8
  sll   $t9, $t8, 5
  nop   
  div   $zero, $t9, $t7
  mflo  $t6
  addu  $a3, $a3, $t6
  bnez  $t7, .L7F06AD78
   nop   
  break 7
.L7F06AD78:
  li    $at, -1
  bne   $t7, $at, .L7F06AD90
   lui   $at, 0x8000
  bne   $t9, $at, .L7F06AD90
   nop   
  break 6
.L7F06AD90:
  b     .L7F06ADE0
   move  $a2, $zero
.L7F06AD98:
  multu $t8, $t5
  subu  $t6, $t2, $a2
  mflo  $t9
  sll   $t7, $t9, 5
  nop   
  div   $zero, $t7, $t6
  mflo  $t8
  addu  $t0, $t0, $t8
  bnez  $t6, .L7F06ADC4
   nop   
  break 7
.L7F06ADC4:
  li    $at, -1
  bne   $t6, $at, .L7F06ADDC
   lui   $at, 0x8000
  bne   $t7, $at, .L7F06ADDC
   nop   
  break 6
.L7F06ADDC:
  move  $a2, $zero
.L7F06ADE0:
  beqz  $t4, .L7F06AE38
   lw    $t6, 0x58($sp)
  lw    $t9, 0x4c($sp)
  add.s $f6, $f2, $f2
  li    $at, 0x44800000 # 1024.000000
  mtc1  $t9, $f18
  mtc1  $at, $f12
  cvt.s.w $f4, $f18
  div.s $f8, $f4, $f6
  mtc1  $t5, $f4
  nop   
  cvt.s.w $f6, $f4
  mul.s $f10, $f8, $f12
  add.s $f8, $f0, $f0
  trunc.w.s $f18, $f10
  div.s $f10, $f6, $f8
  mfc1  $v1, $f18
  mul.s $f18, $f10, $f12
  trunc.w.s $f4, $f18
  mfc1  $a0, $f4
  b     .L7F06AE84
   nop   
.L7F06AE38:
  lw    $t8, 0x4c($sp)
  add.s $f10, $f0, $f0
  li    $at, 0x44800000 # 1024.000000
  mtc1  $t8, $f6
  mtc1  $at, $f12
  cvt.s.w $f8, $f6
  div.s $f18, $f8, $f10
  mtc1  $t5, $f8
  nop   
  cvt.s.w $f10, $f8
  mul.s $f4, $f18, $f12
  add.s $f18, $f2, $f2
  trunc.w.s $f6, $f4
  div.s $f4, $f10, $f18
  mfc1  $v1, $f6
  mul.s $f6, $f4, $f12
  trunc.w.s $f8, $f6
  mfc1  $a0, $f8
  nop   
.L7F06AE84:
  beqz  $t6, .L7F06AEA0
   lw    $t9, 0x4c($sp)
  addiu $t7, $t9, -1
  lui   $t8, 1
  sll   $t6, $t7, 5
  subu  $v1, $t8, $v1
  subu  $a3, $t6, $a3
.L7F06AEA0:
  lw    $t8, 0x5c($sp)
  addiu $t7, $t5, -1
  lui   $t9, 1
  beqz  $t8, .L7F06AEBC
   sll   $t6, $t7, 5
  subu  $a0, $t9, $a0
  subu  $t0, $t6, $t0
.L7F06AEBC:
  beqz  $t4, .L7F06AF48
   andi  $t9, $t1, 0xfff
  andi  $t8, $t1, 0xfff
  sll   $t9, $t8, 0xc
  lui   $at, 0xe500
  or    $t7, $t9, $at
  andi  $t6, $t2, 0xfff
  or    $t8, $t7, $t6
  andi  $t9, $a1, 0xfff
  move  $t4, $v0
  sw    $t8, ($t4)
  sll   $t7, $t9, 0xc
  andi  $t6, $a2, 0xfff
  or    $t8, $t7, $t6
  sw    $t8, 4($t4)
  addiu $v0, $v0, 8
  move  $t5, $v0
  lui   $t9, 0xb400
  sw    $t9, ($t5)
  andi  $t8, $t0, 0xffff
  sll   $t6, $a3, 0x10
  or    $t9, $t6, $t8
  sw    $t9, 4($t5)
  addiu $v0, $v0, 8
  sw    $v0, 0xc($sp)
  lw    $t6, 0xc($sp)
  lui   $t7, 0xb300
  sll   $t9, $v1, 0x10
  sw    $t7, ($t6)
  lw    $t8, 0xc($sp)
  andi  $t7, $a0, 0xffff
  or    $t6, $t9, $t7
  addiu $v0, $v0, 8
  b     .L7F06AFC4
   sw    $t6, 4($t8)
.L7F06AF48:
  sll   $t7, $t9, 0xc
  lui   $at, 0xe400
  or    $t6, $t7, $at
  andi  $t8, $t2, 0xfff
  or    $t9, $t6, $t8
  andi  $t7, $a1, 0xfff
  move  $t4, $v0
  sw    $t9, ($t4)
  sll   $t6, $t7, 0xc
  andi  $t8, $a2, 0xfff
  or    $t9, $t6, $t8
  sw    $t9, 4($t4)
  addiu $v0, $v0, 8
  move  $t5, $v0
  lui   $t7, 0xb400
  sw    $t7, ($t5)
  andi  $t9, $t0, 0xffff
  sll   $t8, $a3, 0x10
  or    $t7, $t8, $t9
  sw    $t7, 4($t5)
  addiu $v0, $v0, 8
  sw    $v0, ($sp)
  lw    $t8, ($sp)
  lui   $t6, 0xb300
  sll   $t7, $v1, 0x10
  sw    $t6, ($t8)
  lw    $t9, ($sp)
  andi  $t6, $a0, 0xffff
  or    $t8, $t7, $t6
  addiu $v0, $v0, 8
  sw    $t8, 4($t9)
.L7F06AFC4:
  move  $v1, $v0
.L7F06AFC8:
  lui   $t7, 8
  sw    $t7, 4($v1)
  sw    $t3, ($v1)
  lw    $t6, 0x40($sp)
  addiu $v0, $v0, 8
  sw    $v0, ($t6)
.L7F06AFE0:
  jr    $ra
   addiu $sp, $sp, 0x40
");

asm(R"
glabel display_image_at_on_screen_coord
  addiu $sp, $sp, -0x28
  sw    $ra, 0x24($sp)
  mtc1  $zero, $f0
  lwc1  $f4, ($a2)
  c.lt.s $f0, $f4
  nop   
  bc1fl .L7F06B108
   lw    $ra, 0x24($sp)
  lwc1  $f6, 4($a2)
  c.lt.s $f0, $f6
  nop   
  bc1fl .L7F06B108
   lw    $ra, 0x24($sp)
  lw    $v0, ($a0)
  lui   $t6, 0xfb00
  move  $v1, $v0
  sw    $t6, ($v1)
  lw    $t8, 0x48($sp)
  lw    $t0, 0x4c($sp)
  lw    $t4, 0x50($sp)
  sll   $t9, $t8, 0x18
  lw    $t8, 0x54($sp)
  andi  $t1, $t0, 0xff
  sll   $t2, $t1, 0x10
  andi  $t5, $t4, 0xff
  sll   $t6, $t5, 8
  or    $t3, $t9, $t2
  or    $t7, $t3, $t6
  andi  $t0, $t8, 0xff
  or    $t1, $t7, $t0
  sw    $t1, 4($v1)
  lw    $t9, 0x58($sp)
  addiu $v0, $v0, 8
  move  $v1, $v0
  beqz  $t9, .L7F06B098
   lw    $t5, 0x5c($sp)
  lui   $t2, (0xFC26A005 >> 16) # lui $t2, 0xfc26
  lui   $t4, (0x1F1493FF >> 16) # lui $t4, 0x1f14
  ori   $t4, (0x1F1493FF & 0xFFFF) # ori $t4, $t4, 0x93ff
  ori   $t2, (0xFC26A005 & 0xFFFF) # ori $t2, $t2, 0xa005
  sw    $t2, ($v1)
  sw    $t4, 4($v1)
  b     .L7F06B0DC
   addiu $v0, $v0, 8
.L7F06B098:
  beqz  $t5, .L7F06B0C0
   move  $v1, $v0
  move  $v1, $v0
  lui   $t3, (0xFC129BFF >> 16) # lui $t3, 0xfc12
  ori   $t3, (0xFC129BFF & 0xFFFF) # ori $t3, $t3, 0x9bff
  li    $t6, -456
  sw    $t6, 4($v1)
  sw    $t3, ($v1)
  b     .L7F06B0DC
   addiu $v0, $v0, 8
.L7F06B0C0:
  lui   $t8, (0xFC129A25 >> 16) # lui $t8, 0xfc12
  lui   $t7, (0xFF37FFFF >> 16) # lui $t7, 0xff37
  ori   $t7, (0xFF37FFFF & 0xFFFF) # ori $t7, $t7, 0xffff
  ori   $t8, (0xFC129A25 & 0xFFFF) # ori $t8, $t8, 0x9a25
  sw    $t8, ($v1)
  sw    $t7, 4($v1)
  addiu $v0, $v0, 8
.L7F06B0DC:
  sw    $v0, ($a0)
  lw    $t2, 0x44($sp)
  lw    $t9, 0x40($sp)
  lw    $t1, 0x3c($sp)
  lw    $t0, 0x38($sp)
  sw    $t2, 0x1c($sp)
  sw    $t9, 0x18($sp)
  sw    $t1, 0x14($sp)
  jal   sub_GAME_7F06ABB0
   sw    $t0, 0x10($sp)
  lw    $ra, 0x24($sp)
.L7F06B108:
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");
