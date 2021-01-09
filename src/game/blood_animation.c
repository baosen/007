asm(R"
glabel insert_imageDL
  addiu $sp, $sp, -0x38
  sw    $s0, 0x18($sp)
  sw    $ra, 0x1c($sp)
  lui   $t6, (0xBA001402 >> 16) # lui $t6, 0xba00
  ori   $t6, (0xBA001402 & 0xFFFF) # ori $t6, $t6, 0x1402
  lui   $t7, 0x30
  sw    $t7, 4($a0)
  sw    $t6, ($a0)
  addiu $s0, $a0, 8
  sw    $s0, 0x30($sp)
  jal   get_video2_settings_txtClipW
   addiu $s0, $s0, 8
  addiu $t8, $v0, -1
  lw    $t1, 0x30($sp)
  andi  $t9, $t8, 0xfff
  lui   $at, 0xff10
  or    $t0, $t9, $at
  jal   get_video_settings2_frameb
   sw    $t0, ($t1)
  jal   osVirtualToPhysical
   move  $a0, $v0
  lw    $t2, 0x30($sp)
  move  $v1, $s0
  lui   $t4, (0x00010001 >> 16) # lui $t4, 1
  sw    $v0, 4($t2)
  ori   $t4, (0x00010001 & 0xFFFF) # ori $t4, $t4, 1
  lui   $t3, 0xf700
  sw    $t3, ($v1)
  sw    $t4, 4($v1)
  addiu $s0, $s0, 8
  sw    $s0, 0x28($sp)
  jal   get_video2_settings_txtClipW
   addiu $s0, $s0, 8
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x22($sp)
  lh    $t9, 0x22($sp)
  addiu $t5, $v0, -1
  lw    $v1, 0x28($sp)
  andi  $t6, $t5, 0x3ff
  addiu $t0, $t9, -1
  andi  $t1, $t0, 0x3ff
  sll   $t7, $t6, 2
  lui   $at, 0xf600
  or    $t8, $t7, $at
  sll   $t2, $t1, 0xe
  or    $t3, $t8, $t2
  sw    $t3, ($v1)
  sw    $zero, 4($v1)
  lw    $ra, 0x1c($sp)
  move  $v0, $s0
  lw    $s0, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x38
");

asm(R"
glabel sub_GAME_7F01C1A4
  addiu $sp, $sp, -0x20
  lui   $t6, (0x01030040 >> 16) # lui $t6, 0x103
  sw    $ra, 0x14($sp)
  ori   $t6, (0x01030040 & 0xFFFF) # ori $t6, $t6, 0x40
  sw    $t6, ($a0)
  move  $v1, $a0
  addiu $a1, $a0, 8
  lui   $a0, %hi(matrix_buffer_gunbarrel_0)
  lw    $a0, %lo(matrix_buffer_gunbarrel_0)($a0)
  sw    $a1, 0x20($sp)
  jal   osVirtualToPhysical
   sw    $v1, 0x1c($sp)
  lw    $v1, 0x1c($sp)
  lw    $t0, 0x20($sp)
  lui   $t7, (0x01020040 >> 16) # lui $t7, 0x102
  ori   $t7, (0x01020040 & 0xFFFF) # ori $t7, $t7, 0x40
  sw    $v0, 4($v1)
  lui   $t8, %hi(D_8002A7D0) 
  sw    $t7, ($t0)
  lw    $t8, %lo(D_8002A7D0)($t8)
  lui   $t1, %hi(matrix_buffer_rarelogo_2) 
  lw    $t1, %lo(matrix_buffer_rarelogo_2)($t1)
  addiu $a1, $t0, 8
  sll   $t9, $t8, 6
  sw    $a1, 0x20($sp)
  sw    $t0, 0x18($sp)
  jal   osVirtualToPhysical
   addu  $a0, $t9, $t1
  lw    $v1, 0x20($sp)
  lw    $t0, 0x18($sp)
  lui   $t2, 0xe700
  addiu $a0, $v1, 8
  sw    $v0, 4($t0)
  lui   $t3, (0xBA001402 >> 16) # lui $t3, 0xba00 gDPSetCycleType(2cycle)
  sw    $zero, 4($v1)
  sw    $t2, ($v1)
  ori   $t3, (0xBA001402 & 0xFFFF) # ori $t3, $t3, 0x1402
  addiu $a2, $a0, 8
  sw    $t3, ($a0)
  sw    $zero, 4($a0)
  lui   $t4, (0xB900031D >> 16) # lui $t4, 0xb900 gDPSetRenderMode(AAOpaSurf)
  lui   $t5, (0x00552048 >> 16) # lui $t5, 0x55
  ori   $t5, (0x00552048 & 0xFFFF) # ori $t5, $t5, 0x2048
  ori   $t4, (0xB900031D & 0xFFFF) # ori $t4, $t4, 0x31d
  sw    $t4, ($a2)
  sw    $t5, 4($a2)
  addiu $a3, $a2, 8
  lui   $t6, 0xb700
  li    $t7, 516
  sw    $t7, 4($a3)
  sw    $t6, ($a3)
  lw    $ra, 0x14($sp)
  addiu $v0, $a3, 8
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel die_blood_image_routine
  addiu $sp, $sp, -0x38
  sw    $ra, 0x24($sp)
  sw    $s1, 0x20($sp)
  bnez  $a0, .L7F01C2B4
   sw    $s0, 0x1c($sp)
  lui   $s1, %hi(pPlayer)
  addiu $s1, %lo(pPlayer) # addiu $s1, $s1, -0x5f50
  lw    $t7, ($s1)
  lui   $t6, %hi(die_blood_image_1) 
  addiu $t6, %lo(die_blood_image_1) # addiu $t6, $t6, -0x44d0
  b     .L7F01C2E4
   sw    $t6, 0x11a8($t7)
.L7F01C2B4:
  li    $at, 1
  bne   $a0, $at, .L7F01C2E4
   lui   $s1, %hi(pPlayer)
  addiu $s1, %lo(pPlayer) # addiu $s1, $s1, -0x5f50
  lw    $s0, ($s1)
  lui   $t8, %hi(D_8002C50C) 
  addiu $t8, %lo(D_8002C50C) # addiu $t8, $t8, -0x3af4
  lw    $v0, 0x11ac($s0)
  sltu  $at, $v0, $t8
  beqz  $at, .L7F01C2E4
   nop   
  sw    $v0, 0x11a8($s0)
.L7F01C2E4:
  lui   $s1, %hi(pPlayer)
  addiu $s1, %lo(pPlayer) # addiu $s1, $s1, -0x5f50
  lw    $s0, ($s1)
  li    $t0, 1
  li    $a0, 7680
  lw    $t9, 0x11b8($s0)
  subu  $t1, $t0, $t9
  jal   sub_GAME_7F0BD714
   sw    $t1, 0x11b8($s0)
  lw    $s0, ($s1)
  li    $a0, 7680
  lw    $t2, 0x11b8($s0)
  sll   $t3, $t2, 2
  addu  $t4, $s0, $t3
  jal   sub_GAME_7F0BD714
   sw    $v0, 0x11b0($t4)
  lw    $t5, ($s1)
  sw    $v0, 0x30($sp)
  addiu $t6, $sp, 0x37
  lw    $a0, 0x11a8($t5)
  sw    $t6, 0x10($sp)
  li    $a1, 80
  li    $a2, 96
  jal   decrypt_bleeding_animation_data
   move  $a3, $v0
  lw    $t7, ($s1)
  li    $a1, 80
  li    $a2, 96
  sw    $v0, 0x11ac($t7)
  lw    $s0, ($s1)
  lw    $a0, 0x30($sp)
  lw    $t8, 0x11b8($s0)
  sll   $t0, $t8, 2
  addu  $t9, $s0, $t0
  jal   sub_GAME_7F01D16C
   lw    $a3, 0x11b0($t9)
  lw    $s0, ($s1)
  li    $a1, 80
  lw    $t1, 0x11b8($s0)
  sll   $t2, $t1, 2
  addu  $t3, $s0, $t2
  lw    $a0, 0x11b0($t3)
  jal   sub_GAME_7F01D02C
   move  $a2, $a0
  lw    $s0, ($s1)
  li    $a1, 80
  lw    $t4, 0x11b8($s0)
  sll   $t5, $t4, 2
  addu  $t6, $s0, $t5
  lw    $a0, 0x11b0($t6)
  jal   sub_GAME_7F01CEEC
   move  $a2, $a0
  lw    $s0, ($s1)
  li    $a1, 7680
  lw    $t7, 0x11b8($s0)
  sll   $t8, $t7, 2
  addu  $t0, $s0, $t8
  lw    $a0, 0x11b0($t0)
  jal   sub_GAME_7F01CC94
   move  $a2, $a0
  lw    $t9, ($s1)
  lw    $ra, 0x24($sp)
  lui   $t2, %hi(D_8002C50C) 
  lw    $t1, 0x11ac($t9)
  addiu $t2, %lo(D_8002C50C) # addiu $t2, $t2, -0x3af4
  lw    $s1, 0x20($sp)
  lw    $s0, 0x1c($sp)
  sltu  $v0, $t1, $t2
  xori  $v0, $v0, 1
  jr    $ra
   addiu $sp, $sp, 0x38
");

asm(R"
glabel sub_GAME_7F01C400
  addiu $sp, $sp, -0x70
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  lui   $t6, (0xBA000E02 >> 16) # lui $t6, 0xba00 #G_SETOTHERMODE_H
  ori   $t6, (0xBA000E02 & 0xFFFF) # ori $t6, $t6, 0xe02
  sw    $t6, ($a0)
  sw    $zero, 4($a0)
  addiu $v1, $a0, 8
  lui   $t7, (0xBA000C02 >> 16) # lui $t7, 0xba00
  ori   $t7, (0xBA000C02 & 0xFFFF) # ori $t7, $t7, 0xc02
  li    $t8, 8192
  sw    $t8, 4($v1)
  sw    $t7, ($v1)
  jal   sub_GAME_7F01C1A4
   addiu $a0, $v1, 8
  lui   $t9, (0xBB000001 >> 16) # lui $t9, 0xbb00
  ori   $t9, (0xBB000001 & 0xFFFF) # ori $t9, $t9, 1
  sw    $t9, ($v0)
  lui   $t0, (0x80008000 >> 16)
  lui   $t1, (0xB900031D >> 16) # lui $t1, 0xb900 #gDPSetRenderMode(OpaSurf)
  lui   $t2, (0x00504340 >> 16) # lui $t2, 0x50
  lui   $t3, (0xFC119623 >> 16) # lui $t3, 0xfc11
  lui   $t4, (0xFF2FFFFF >> 16) # lui $t4, 0xff2f
  lui   $t5, (0xBA000602 >> 16) # lui $t5, 0xba00
  lui   $t7, (0x960000B4 >> 16) # lui $t7, 0x9600
  lui   $t8, (0xBA001301 >> 16) # lui $t8, 0xba00
  ori   $t0, (0x80008000 & 0xFFFF) # ori $t0, $t0, 0x8000
  ori   $t2, (0x00504340 & 0xFFFF) # ori $t2, $t2, 0x4340
  ori   $t1, (0xB900031D & 0xFFFF) # ori $t1, $t1, 0x31d
  ori   $t4, (0xFF2FFFFF & 0xFFFF) # ori $t4, $t4, 0xffff
  ori   $t3, (0xFC119623 & 0xFFFF) # ori $t3, $t3, 0x9623 #setcombine()
  ori   $t5, (0xBA000602 & 0xFFFF) # ori $t5, $t5, 0x602
  ori   $t7, (0x960000B4 & 0xFFFF) # ori $t7, $t7, 0xb4
  lui   $t6, 0xfa00
  ori   $t8, (0xBA001301 & 0xFFFF) # ori $t8, $t8, 0x1301
  lui   $t9, 0xfd90
  sw    $t0, 4($v0)
  sw    $t1, 8($v0)
  sw    $t2, 0xc($v0)
  sw    $t3, 0x10($v0)
  sw    $t4, 0x14($v0)
  sw    $t5, 0x18($v0)
  sw    $zero, 0x1c($v0)
  sw    $t6, 0x20($v0)
  sw    $t7, 0x24($v0)
  sw    $t8, 0x28($v0)
  sw    $zero, 0x2c($v0)
  sw    $t9, 0x30($v0)
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  lui   $at, 0x8000
  lui   $t9, (0x0777F156 >> 16) # lui $t9, 0x777
  lw    $t0, 0x11b8($v1)
  lui   $t6, (0x07080200 >> 16) # lui $t6, 0x708
  lui   $t5, 0xf590
  sll   $t1, $t0, 2
  addu  $t2, $v1, $t1
  lw    $t3, 0x11b0($t2)
  lui   $t2, (0x00080200 >> 16) # lui $t2, 8
  lui   $t1, (0xF5800C00 >> 16) # lui $t1, 0xf580
  addu  $t4, $t3, $at
  sw    $t4, 0x34($v0)
  lui   $t4, (0x0017C13C >> 16) # lui $t4, 0x17
  ori   $t4, (0x0017C13C & 0xFFFF) # ori $t4, $t4, 0xc13c
  lui   $t3, 0xf200
  ori   $t1, (0xF5800C00 & 0xFFFF) # ori $t1, $t1, 0xc00
  ori   $t2, (0x00080200 & 0xFFFF) # ori $t2, $t2, 0x200
  sw    $t5, 0x38($v0)
  lui   $t0, 0xe700
  ori   $t6, (0x07080200 & 0xFFFF) # ori $t6, $t6, 0x200
  ori   $t9, (0x0777F156 & 0xFFFF) # ori $t9, $t9, 0xf156
  lui   $t8, 0xf300
  lui   $t7, 0xe600
  sw    $t7, 0x40($v0)
  sw    $t8, 0x48($v0)
  sw    $t9, 0x4c($v0)
  sw    $t6, 0x3c($v0)
  sw    $t0, 0x50($v0)
  sw    $t2, 0x5c($v0)
  sw    $t1, 0x58($v0)
  sw    $t3, 0x60($v0)
  sw    $t4, 0x64($v0)
  sw    $zero, 0x54($v0)
  sw    $zero, 0x44($v0)
  addiu $t5, $v0, 0x68
  sw    $t5, 0x30($sp)
  jal   get_video2_settings_txtClipW
   addiu $s0, $v0, 0x70
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x26($sp)
  lh    $t0, 0x26($sp)
  sll   $t6, $v0, 2
  lw    $a1, 0x30($sp)
  sll   $t1, $t0, 2
  addiu $t2, $t1, -1
  addiu $t7, $t6, -1
  andi  $t8, $t7, 0xfff
  andi  $t3, $t2, 0xfff
  lui   $at, 0xe400
  or    $t9, $t8, $at
  sll   $t4, $t3, 0xc
  or    $t5, $t9, $t4
  move  $v1, $s0
  sw    $t5, ($a1)
  sw    $zero, 4($a1)
  addiu $s0, $s0, 8
  lui   $t6, 0xb400
  sw    $t6, ($v1)
  move  $a0, $s0
  sw    $zero, 4($v1)
  lui   $t7, 0xb300
  sw    $t7, ($a0)
  sw    $a0, 0x28($sp)
  jal   get_video2_settings_txtClipW
   addiu $s0, $s0, 8
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x26($sp)
  lui   $t8, (0x00014000 >> 16) # lui $t8, 1
  ori   $t8, (0x00014000 & 0xFFFF) # ori $t8, $t8, 0x4000
  div   $zero, $t8, $v0
  mflo  $t0
  lh    $t2, 0x26($sp)
  lui   $t3, (0x00018000 >> 16) # lui $t3, 1
  ori   $t3, (0x00018000 & 0xFFFF) # ori $t3, $t3, 0x8000
  div   $zero, $t3, $t2
  bnez  $v0, .L7F01C600
   nop   
  break 7
.L7F01C600:
  li    $at, -1
  bne   $v0, $at, .L7F01C618
   lui   $at, 0x8000
  bne   $t8, $at, .L7F01C618
   nop   
  break 6
.L7F01C618:
  mflo  $t9
  lw    $t7, 0x28($sp)
  andi  $t4, $t9, 0xffff
  sll   $t5, $t4, 0x10
  andi  $t1, $t0, 0xffff
  or    $t6, $t1, $t5
  sw    $t6, 4($t7)
  lw    $ra, 0x1c($sp)
  move  $v0, $s0
  lw    $s0, 0x18($sp)
  bnez  $t2, .L7F01C64C
   nop   
  break 7
.L7F01C64C:
  li    $at, -1
  bne   $t2, $at, .L7F01C664
   lui   $at, 0x8000
  bne   $t3, $at, .L7F01C664
   nop   
  break 6
.L7F01C664:
  addiu $sp, $sp, 0x70
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F01C670
  addiu $sp, $sp, -0x88
  sw    $s0, 0x14($sp)
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  addiu $s0, $a0, 8
  lui   $t6, (0xBA000E02 >> 16) # lui $t6, 0xba00 #G_SETOTHERMODE_H()
  ori   $t6, (0xBA000E02 & 0xFFFF) # ori $t6, $t6, 0xe02
  move  $v1, $s0
  lui   $t7, (0xBA000C02 >> 16) # lui $t7, 0xba00
  sw    $t6, ($a0)
  sw    $zero, 4($a0)
  ori   $t7, (0xBA000C02 & 0xFFFF) # ori $t7, $t7, 0xc02 #G_SETOTHERMODE_H()
  addiu $s0, $s0, 8
  sw    $t7, ($v1)
  li    $t8, 8192
  move  $a1, $s0
  sw    $t8, 4($v1)
  addiu $s0, $s0, 8
  lui   $t9, (0xBA001402 >> 16) # lui $t9, 0xba00  #gDPSetCycleType(2Cycle)
  ori   $t9, (0xBA001402 & 0xFFFF) # ori $t9, $t9, 0x1402
  move  $a2, $s0
  sw    $t9, ($a1)
  sw    $zero, 4($a1)
  addiu $s0, $s0, 8
  lui   $t0, 0xb700
  li    $t1, 516
  sw    $t1, 4($a2)
  sw    $t0, ($a2)
  move  $a3, $s0
  addiu $s0, $s0, 8
  lui   $t2, (0xBB000001 >> 16) # lui $t2, 0xbb00 
  lui   $t3, (0x80008000 >> 16) # lui $t3, 0x8000
  ori   $t3, (0x80008000 & 0xFFFF) # ori $t3, $t3, 0x8000
  ori   $t2, (0xBB000001 & 0xFFFF) # ori $t2, $t2, 1
  move  $v0, $s0
  sw    $t2, ($a3)
  sw    $t3, 4($a3)
  addiu $s0, $s0, 8
  lui   $t4, (0xB900031D >> 16) # lui $t4, 0xb900 #gDPSetRenderMode()
  lui   $t5, (0x00504340 >> 16) # lui $t5, 0x50
  ori   $t5, (0x00504340 & 0xFFFF) # ori $t5, $t5, 0x4340
  ori   $t4, (0xB900031D & 0xFFFF) # ori $t4, $t4, 0x31d
  move  $v1, $s0
  sw    $t4, ($v0)
  sw    $t5, 4($v0)
  lui   $t7, (0xFF2FFFFF >> 16) # lui $t7, 0xff2f
  lui   $t6, (0xFC119623 >> 16) # lui $t6, 0xfc11 #Setcombine()
  ori   $t6, (0xFC119623 & 0xFFFF) # ori $t6, $t6, 0x9623
  ori   $t7, (0xFF2FFFFF & 0xFFFF) # ori $t7, $t7, 0xffff
  addiu $s0, $s0, 8
  sw    $t7, 4($v1)
  sw    $t6, ($v1)
  move  $a0, $s0
  addiu $s0, $s0, 8
  lui   $t8, (0xBA000602 >> 16) # lui $t8, 0xba00  #G_SETOTHERMODE_H(envmapping)
  ori   $t8, (0xBA000602 & 0xFFFF) # ori $t8, $t8, 0x602
  move  $a1, $s0
  sw    $t8, ($a0)
  sw    $zero, 4($a0)
  addiu $s0, $s0, 8
  lui   $t0, (0x960000B4 >> 16) # lui $t0, 0x9600
  ori   $t0, (0x960000B4 & 0xFFFF) # ori $t0, $t0, 0xb4
  lui   $t9, 0xfa00
  move  $a2, $s0
  sw    $t9, ($a1)
  sw    $t0, 4($a1)
  lui   $t1, (0xBA001301 >> 16) # lui $t1, 0xba00  #G_SETOTHERMODE_H()
  ori   $t1, (0xBA001301 & 0xFFFF) # ori $t1, $t1, 0x1301
  addiu $s0, $s0, 8
  sw    $t1, ($a2)
  sw    $zero, 4($a2)
  move  $v0, $s0
  lui   $t2, 0xfd90
  sw    $t2, ($v0)
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  lui   $at, 0x8000
  addiu $s0, $s0, 8
  lw    $t3, 0x11b8($v1)
  move  $a0, $s0
  addiu $s0, $s0, 8
  sll   $t4, $t3, 2
  addu  $t5, $v1, $t4
  lw    $t6, 0x11b0($t5)
  lui   $t9, (0x07080200 >> 16) # lui $t9, 0x708
  ori   $t9, (0x07080200 & 0xFFFF) # ori $t9, $t9, 0x200
  addu  $t7, $t6, $at
  sw    $t7, 4($v0)
  move  $a1, $s0
  lui   $t8, 0xf590
  sw    $t8, ($a0)
  addiu $s0, $s0, 8
  sw    $t9, 4($a0)
  move  $a2, $s0
  lui   $t0, 0xe600
  sw    $t0, ($a1)
  addiu $s0, $s0, 8
  sw    $zero, 4($a1)
  lui   $t2, (0x0777F156 >> 16) # lui $t2, 0x777
  ori   $t2, (0x0777F156 & 0xFFFF) # ori $t2, $t2, 0xf156
  move  $a3, $s0
  lui   $t1, 0xf300
  sw    $t1, ($a2)
  addiu $s0, $s0, 8
  sw    $t2, 4($a2)
  move  $v0, $s0
  lui   $t3, 0xe700
  sw    $t3, ($a3)
  addiu $s0, $s0, 8
  sw    $zero, 4($a3)
  lui   $t5, (0x00080200 >> 16) # lui $t5, 8
  lui   $t4, (0xF5800C00 >> 16) # lui $t4, 0xf580 #settilesize()
  ori   $t4, (0xF5800C00 & 0xFFFF) # ori $t4, $t4, 0xc00
  ori   $t5, (0x00080200 & 0xFFFF) # ori $t5, $t5, 0x200
  move  $v1, $s0
  sw    $t5, 4($v0)
  sw    $t4, ($v0)
  lui   $t7, (0x0017C13C >> 16) # lui $t7, 0x17
  ori   $t7, (0x0017C13C & 0xFFFF) # ori $t7, $t7, 0xc13c
  lui   $t6, 0xf200
  sw    $t6, ($v1)
  sw    $t7, 4($v1)
  addiu $s0, $s0, 8
  sw    $s0, 0x40($sp)
  jal   get_video2_settings_width
   addiu $s0, $s0, 8
  jal   get_video2_settings_ulx
   sh    $v0, 0x26($sp)
  jal   get_video2_settings_uly
   sh    $v0, 0x28($sp)
  sll   $s1, $v0, 0x10
  sra   $t8, $s1, 0x10
  jal   get_video2_settings_height
   move  $s1, $t8
  lh    $t9, 0x28($sp)
  lh    $t0, 0x26($sp)
  addu  $t6, $v0, $s1
  sll   $t7, $t6, 2
  addu  $t1, $t9, $t0
  sll   $t2, $t1, 2
  addiu $t3, $t2, -1
  addiu $t8, $t7, -1
  andi  $t9, $t8, 0xfff
  andi  $t4, $t3, 0xfff
  lui   $at, 0xe400
  lw    $t2, 0x40($sp)
  or    $t0, $t9, $at
  sll   $t5, $t4, 0xc
  or    $t1, $t0, $t5
  jal   get_video2_settings_ulx
   sw    $t1, ($t2)
  sll   $s1, $v0, 0x10
  sra   $t3, $s1, 0x10
  jal   get_video2_settings_uly
   move  $s1, $t3
  sll   $t7, $s1, 2
  lw    $t5, 0x40($sp)
  andi  $t8, $t7, 0xfff
  sll   $t4, $v0, 2
  andi  $t6, $t4, 0xfff
  sll   $t9, $t8, 0xc
  or    $t0, $t6, $t9
  move  $v1, $s0
  sw    $t0, 4($t5)
  addiu $s0, $s0, 8
  lui   $t1, 0xb400
  sw    $t1, ($v1)
  move  $a0, $s0
  sw    $zero, 4($v1)
  lui   $t2, 0xb300
  sw    $t2, ($a0)
  sw    $a0, 0x38($sp)
  jal   get_video2_settings_width
   addiu $s0, $s0, 8
  sll   $s1, $v0, 0x10
  sra   $t3, $s1, 0x10
  jal   get_video2_settings_height
   move  $s1, $t3
  lui   $t4, (0x00014000 >> 16) # lui $t4, 1
  ori   $t4, (0x00014000 & 0xFFFF) # ori $t4, $t4, 0x4000
  div   $zero, $t4, $v0
  mflo  $t7
  lui   $t6, (0x00018000 >> 16) # lui $t6, 1
  ori   $t6, (0x00018000 & 0xFFFF) # ori $t6, $t6, 0x8000
  div   $zero, $t6, $s1
  bnez  $v0, .L7F01C960
   nop   
  break 7
.L7F01C960:
  li    $at, -1
  bne   $v0, $at, .L7F01C978
   lui   $at, 0x8000
  bne   $t4, $at, .L7F01C978
   nop   
  break 6
.L7F01C978:
  mflo  $t9
  lw    $t2, 0x38($sp)
  andi  $t0, $t9, 0xffff
  sll   $t5, $t0, 0x10
  andi  $t8, $t7, 0xffff
  or    $t1, $t8, $t5
  move  $v1, $s0
  addiu $s0, $s0, 8
  sw    $t1, 4($t2)
  lui   $t3, 0xe700
  move  $a0, $s0
  sw    $t3, ($v1)
  sw    $zero, 4($v1)
  lui   $t4, (0xBA000602 >> 16) # lui $t4, 0xba00  #G_SETOTHERMODE_H()
  bnez  $s1, .L7F01C9BC
   nop   
  break 7
.L7F01C9BC:
  li    $at, -1
  bne   $s1, $at, .L7F01C9D4
   lui   $at, 0x8000
  bne   $t6, $at, .L7F01C9D4
   nop   
  break 6
.L7F01C9D4:
  ori   $t4, (0xBA000602 & 0xFFFF) # ori $t4, $t4, 0x602 #G_SETOTHERMODE_H()
  addiu $s0, $s0, 8
  li    $t7, 64
  sw    $t7, 4($a0)
  sw    $t4, ($a0)
  move  $a1, $s0
  lui   $t6, (0xBA001301 >> 16) # lui $t6, 0xba00 #G_SETOTHERMODE_H()
  ori   $t6, (0xBA001301 & 0xFFFF) # ori $t6, $t6, 0x1301
  lui   $t9, 8
  sw    $t9, 4($a1)
  sw    $t6, ($a1)
  lw    $ra, 0x1c($sp)
  addiu $v0, $s0, 8
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x88
");

asm(R"
glabel sub_GAME_7F01CA18
  addiu $sp, $sp, -0x30
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F01C1A4
   nop   
  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
  lui   $t7, (0x00504340 >> 16) # lui $t7, 0x50
  lui   $t8, (0xFCFFFFFF >> 16) # lui $t8, 0xfcff
  lui   $t9, (0xFFFDF6FB >> 16) # lui $t9, 0xfffd
  lui   $t1, (0x960000B4 >> 16) # lui $t1, 0x9600
  lui   $t2, (0xBA000602 >> 16) # lui $t2, 0xba00
  ori   $t7, (0x00504340 & 0xFFFF) # ori $t7, $t7, 0x4340
  ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
  ori   $t9, (0xFFFDF6FB & 0xFFFF) # ori $t9, $t9, 0xf6fb
  ori   $t8, (0xFCFFFFFF & 0xFFFF) # ori $t8, $t8, 0xffff
  ori   $t1, (0x960000B4 & 0xFFFF) # ori $t1, $t1, 0xb4
  lui   $t0, 0xfa00
  ori   $t2, (0xBA000602 & 0xFFFF) # ori $t2, $t2, 0x602
  sw    $t6, ($v0)		#$v0 = gfx glist
  sw    $t7, 4($v0)
  sw    $t8, 8($v0)
  sw    $t9, 0xc($v0)
  sw    $t0, 0x10($v0)
  sw    $t1, 0x14($v0)
  sw    $t2, 0x18($v0)
  sw    $zero, 0x1c($v0)
  addiu $t3, $v0, 0x20
  addiu $t4, $v0, 0x28
  sw    $t4, 0x30($sp)
  jal   get_video2_settings_txtClipW
   sw    $t3, 0x1c($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x1a($sp)
  lh    $t8, 0x1a($sp)
  lw    $v1, 0x1c($sp)
  andi  $t5, $v0, 0x3ff
  sll   $t6, $t5, 2
  lui   $at, 0xf600
  andi  $t9, $t8, 0x3ff
  sll   $t0, $t9, 0xe
  or    $t7, $t6, $at
  or    $t1, $t7, $t0
  sw    $t1, ($v1)
  sw    $zero, 4($v1)
  lw    $ra, 0x14($sp)
  lw    $v0, 0x30($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");
