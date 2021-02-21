asm(R"
.late_rodata
glabel D_8005BD20
.word 0x40490fdb /*3.1415927*/
glabel D_8005BD24
.word 0x3c8efa35 /*0.017453292*/

.text
glabel display_red_blue_on_radar
  addiu $sp, $sp, -0x88
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
  jal   get_scenario
   sw    $a0, 0x88($sp)
  jal   get_cur_playernum
   move  $s4, $v0
  jal   getPlayerCount
   sw    $v0, 0x70($sp)
  li    $at, 1
  bne   $v0, $at, .L7F0C60FC
   sw    $v0, 0x74($sp)
  b     .L7F0C6588
   lw    $v0, 0x88($sp)
.L7F0C60FC:
  lui   $s7, %hi(pPlayer) 
  addiu $s7, %lo(pPlayer) # addiu $s7, $s7, -0x5f50
  lw    $v0, ($s7)
  lw    $t6, 0x29c4($v0)
  bnez  $t6, .L7F0C6120
   nop   
  lw    $t7, 0xd8($v0)
  beqz  $t7, .L7F0C6128
   nop   
.L7F0C6120:
  b     .L7F0C6588
   lw    $v0, 0x88($sp)
.L7F0C6128:
  jal   cheatCheckIfOn
   li    $a0, 23
  beqz  $v0, .L7F0C6140
   nop   
  b     .L7F0C6588
   lw    $v0, 0x88($sp)
.L7F0C6140:
  jal   get_video2_settings_ulx
   nop   
  sll   $s0, $v0, 0x10
  sra   $t8, $s0, 0x10
  jal   get_video2_settings_width
   move  $s0, $t8
  addu  $s5, $v0, $s0
  jal   get_video2_settings_uly
   addiu $s5, $s5, -0x29
  lw    $t9, 0x74($sp)
  addiu $s6, $v0, 0x1a
  addiu $a0, $sp, 0x88
  slti  $at, $t9, 3
  bnez  $at, .L7F0C6190
   lui   $a1, %hi(mpradarimages)
  lw    $t1, 0x70($sp)
  andi  $t2, $t1, 1
  bnezl $t2, .L7F0C6194
   li    $t3, 2
  addiu $s5, $s5, 0xf
.L7F0C6190:
  li    $t3, 2
.L7F0C6194:
  sw    $t3, 0x10($sp)
  lw    $a1, %lo(mpradarimages)($a1)
  li    $a2, 2
  jal   likely_generate_DL_for_image_declaration
   move  $a3, $zero
  jal   microcode_constructor
   lw    $a0, 0x88($sp)
  addiu $t4, $v0, 8
  sw    $t4, 0x88($sp)
  lui   $t5, (0xFCFFB3FF >> 16) # lui $t5, 0xfcff
  lui   $t6, (0xFF65FEFF >> 16) # lui $t6, 0xff65
  ori   $t6, (0xFF65FEFF & 0xFFFF) # ori $t6, $t6, 0xfeff
  ori   $t5, (0xFCFFB3FF & 0xFFFF) # ori $t5, $t5, 0xb3ff
  sw    $t5, ($v0)
  sw    $t6, 4($v0)
  lw    $t7, 0x88($sp)
  lui   $t9, 0xfa00
  li    $t1, 160
  addiu $t8, $t7, 8
  sw    $t8, 0x88($sp)
  addiu $t4, $s5, 0x10
  sw    $t1, 4($t7)
  sw    $t9, ($t7)
  lw    $a0, 0x88($sp)
  sll   $t5, $t4, 2
  andi  $t6, $t5, 0xfff
  addiu $t9, $s6, 0x10
  sll   $t1, $t9, 2
  sll   $t7, $t6, 0xc
  lui   $at, 0xe400
  or    $t8, $t7, $at
  andi  $t2, $t1, 0xfff
  addiu $t4, $s5, -0x10
  addiu $t3, $a0, 8
  sw    $t3, 0x88($sp)
  sll   $t5, $t4, 2
  addiu $t9, $s6, -0x10
  sll   $t1, $t9, 2
  andi  $t6, $t5, 0xfff
  or    $t3, $t8, $t2
  andi  $t8, $t1, 0xfff
  sll   $t7, $t6, 0xc
  or    $t2, $t7, $t8
  sw    $t2, 4($a0)
  sw    $t3, ($a0)
  lw    $t3, 0x88($sp)
  lui   $t6, (0x00100010 >> 16) # lui $t6, 0x10
  ori   $t6, (0x00100010 & 0xFFFF) # ori $t6, $t6, 0x10
  addiu $t4, $t3, 8
  sw    $t4, 0x88($sp)
  lui   $t5, 0xb400
  sw    $t5, ($t3)
  sw    $t6, 4($t3)
  lw    $t9, 0x88($sp)
  lui   $t8, (0x04000400 >> 16) # lui $t8, 0x400
  ori   $t8, (0x04000400 & 0xFFFF) # ori $t8, $t8, 0x400
  addiu $t1, $t9, 8
  sw    $t1, 0x88($sp)
  lui   $t7, 0xb300
  sw    $t7, ($t9)
  sw    $t8, 4($t9)
  li    $t3, 64
  addiu $t2, $s6, 2
  sw    $t2, 0x10($sp)
  sw    $t3, 0x14($sp)
  lw    $a0, 0x88($sp)
  addiu $a1, $s5, -2
  addiu $a2, $s6, -2
  jal   microcode_constructor_related_to_menus
   addiu $a3, $s5, 2
  li    $at, 5
  beq   $s4, $at, .L7F0C62DC
   sw    $v0, 0x88($sp)
  li    $at, 6
  beq   $s4, $at, .L7F0C62DC
   li    $at, 7
  beq   $s4, $at, .L7F0C62DC
   li    $at, 2
  beq   $s4, $at, .L7F0C62DC
   li    $at, 3
  bne   $s4, $at, .L7F0C6338
   lw    $a0, 0x88($sp)
.L7F0C62DC:
  lw    $t4, 0x70($sp)
  lui   $t6, %hi(player1_statistics+0x69)
  lw    $a0, 0x88($sp)
  sll   $t5, $t4, 3
  subu  $t5, $t5, $t4
  sll   $t5, $t5, 4
  addu  $t6, $t6, $t5
  lbu   $t6, %lo(player1_statistics+0x69)($t6)
  addiu $a1, $s5, -1
  addiu $a2, $s6, -1
  bnez  $t6, .L7F0C6318
   addiu $a3, $s5, 1
  lui   $v0, (0xFF7777FF >> 16) # lui $v0, 0xff77
  b     .L7F0C6320
   ori   $v0, (0xFF7777FF & 0xFFFF) # ori $v0, $v0, 0x77ff
.L7F0C6318:
  lui   $v0, (0x8888FFFF >> 16) # lui $v0, 0x8888
  ori   $v0, (0x8888FFFF & 0xFFFF) # ori $v0, $v0, 0xffff
.L7F0C6320:
  addiu $t9, $s6, 1
  sw    $t9, 0x10($sp)
  jal   microcode_constructor_related_to_menus
   sw    $v0, 0x14($sp)
  b     .L7F0C635C
   sw    $v0, 0x88($sp)
.L7F0C6338:
  addiu $t1, $s6, 1
  li    $t7, -96
  sw    $t7, 0x14($sp)
  sw    $t1, 0x10($sp)
  addiu $a1, $s5, -1
  addiu $a2, $s6, -1
  jal   microcode_constructor_related_to_menus
   addiu $a3, $s5, 1
  sw    $v0, 0x88($sp)
.L7F0C635C:
  lw    $t8, 0x74($sp)
  move  $s3, $zero
  li    $at, 0x43340000 # 180.000000
  blez  $t8, .L7F0C6580
   nop   
  mtc1  $at, $f30
  nop   
  lw    $t2, 0x70($sp)
.L7F0C637C:
  sll   $t3, $s3, 2
  lui   $a0, %hi(players_p1)
  beq   $s3, $t2, .L7F0C6570
   addu  $a0, $a0, $t3
  lw    $a0, %lo(players_p1)($a0)
  lw    $t4, 0xd8($a0)
  bnezl $t4, .L7F0C6574
   lw    $t8, 0x74($sp)
  lw    $t5, ($s7)
  lw    $v0, 0xa8($a0)
  li    $at, 0x41800000 # 16.000000
  lw    $v1, 0xa8($t5)
  lwc1  $f28, 8($v0)
  lwc1  $f18, 0x10($v0)
  lwc1  $f16, 8($v1)
  lwc1  $f10, 0x10($v1)
  mtc1  $at, $f8
  sub.s $f20, $f28, $f16
  li    $at, 0x457A0000 # 4000.000000
  mtc1  $at, $f16
  sub.s $f22, $f18, $f10
  li    $t6, 16
  mtc1  $t6, $f10
  div.s $f26, $f8, $f16
  mov.s $f12, $f20
  mov.s $f14, $f22
  jal   convert_angle_using_inverse
   cvt.s.w $f24, $f10
  mul.s $f6, $f0, $f30
  lui   $at, %hi(D_8005BD20)
  lwc1  $f8, %lo(D_8005BD20)($at)
  mul.s $f4, $f20, $f20
  lw    $t9, ($s7)
  lwc1  $f16, 0x148($t9)
  div.s $f10, $f6, $f8
  mul.s $f6, $f22, $f22
  add.s $f12, $f4, $f6
  add.s $f18, $f10, $f16
  jal   sqrtf
   add.s $f28, $f18, $f30
  mul.s $f2, $f0, $f26
  li    $at, 5
  sll   $t1, $s3, 3
  subu  $t1, $t1, $s3
  beq   $s4, $at, .L7F0C6458
   mov.s $f22, $f2
  li    $at, 6
  beq   $s4, $at, .L7F0C6458
   li    $at, 7
  beq   $s4, $at, .L7F0C6458
   li    $at, 2
  beq   $s4, $at, .L7F0C6458
   li    $at, 3
  bnel  $s4, $at, .L7F0C64C0
   c.lt.s $f2, $f24
.L7F0C6458:
  c.lt.s $f2, $f24
  lui   $t7, %hi(player1_statistics) 
  addiu $t7, %lo(player1_statistics) # addiu $t7, $t7, -0x6110
  sll   $t1, $t1, 4
  bc1f  .L7F0C6494
   addu  $v0, $t1, $t7
  lbu   $t8, 0x69($v0)
  lui   $s1, 0x2828
  bnez  $t8, .L7F0C648C
   nop   
  lui   $s1, (0xFF00FFFF >> 16) # lui $s1, 0xff00
  b     .L7F0C64E0
   ori   $s1, (0xFF0000A0 & 0xFFFF) # ori $s1, $s1, 0xa0
.L7F0C648C:
  b     .L7F0C64E0
   ori   $s1, (0xFF00FFFF & 0xFFFF) # ori $s1, $s1, 0xffff
.L7F0C6494:
  lbu   $t2, 0x69($v0)
  mov.s $f22, $f24
  lui   $s1, 0x2828
  bnez  $t2, .L7F0C64B4
   nop   
  lui   $s1, (0xFF00FFB0 >> 16) # lui $s1, 0xff00
  b     .L7F0C64E0
   ori   $s1, (0xFF000060 & 0xFFFF) # ori $s1, $s1, 0x60
.L7F0C64B4:
  b     .L7F0C64E0
   ori   $s1, (0xFF00FFB0 & 0xFFFF) # ori $s1, $s1, 0xffb0
  c.lt.s $f2, $f24
.L7F0C64C0:
  lui   $s1, (0xFFFF0060 >> 16) # lui $s1, 0xffff
  ori   $s1, (0xFFFF0060 & 0xFFFF) # ori $s1, $s1, 0x60
  bc1fl .L7F0C64E0
   mov.s $f22, $f24
  lui   $s1, (0xFFFF00A0 >> 16) # lui $s1, 0xffff
  b     .L7F0C64E0
   ori   $s1, (0xFFFF00A0 & 0xFFFF) # ori $s1, $s1, 0xa0
  mov.s $f22, $f24
.L7F0C64E0:
  lui   $at, %hi(D_8005BD24)
  lwc1  $f8, %lo(D_8005BD24)($at)
  mul.s $f20, $f28, $f8
  jal   sinf
   mov.s $f12, $f20
  mul.s $f10, $f0, $f22
  mov.s $f12, $f20
  trunc.w.s $f16, $f10
  mfc1  $t4, $f16
  jal   cosf
   addu  $s0, $t4, $s5
  mul.s $f18, $f0, $f22
  li    $t1, 64
  sw    $t1, 0x14($sp)
  lw    $a0, 0x88($sp)
  addiu $a1, $s0, -2
  addiu $a3, $s0, 2
  trunc.w.s $f4, $f18
  mfc1  $t6, $f4
  nop   
  addu  $v0, $t6, $s6
  addiu $t9, $v0, 2
  move  $s2, $v0
  sw    $t9, 0x10($sp)
  jal   microcode_constructor_related_to_menus
   addiu $a2, $v0, -2
  addiu $t7, $s2, 1
  sw    $v0, 0x88($sp)
  sw    $t7, 0x10($sp)
  move  $a0, $v0
  addiu $a1, $s0, -1
  addiu $a2, $s2, -1
  addiu $a3, $s0, 1
  jal   microcode_constructor_related_to_menus
   sw    $s1, 0x14($sp)
  sw    $v0, 0x88($sp)
.L7F0C6570:
  lw    $t8, 0x74($sp)
.L7F0C6574:
  addiu $s3, $s3, 1
  bnel  $s3, $t8, .L7F0C637C
   lw    $t2, 0x70($sp)
.L7F0C6580:
  jal   combiner_bayer_lod_perspective
   lw    $a0, 0x88($sp)
.L7F0C6588:
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
   addiu $sp, $sp, 0x88
");