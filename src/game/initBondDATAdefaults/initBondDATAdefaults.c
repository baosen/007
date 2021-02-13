int D_8002A790[] = {0, 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

asm(R"
glabel sub_GAME_7F0062C0
  addiu $sp, $sp, -0x48
  sw    $s3, 0x28($sp)
  sw    $s2, 0x24($sp)
  sw    $s1, 0x20($sp)
  sw    $s0, 0x1c($sp)
  sw    $ra, 0x34($sp)
  sw    $s5, 0x30($sp)
  sw    $s4, 0x2c($sp)
  slt   $at, $a1, $a2
  move  $s0, $a3
  move  $s1, $a1
  move  $s2, $a2
  move  $s3, $a0
  sw    $zero, ($a3)
  sw    $zero, 4($a3)
  beqz  $at, .L7F006368
   sw    $zero, 8($a3)
  lui   $s4, %hi(model_guard_character)
  addiu $s4, %lo(model_guard_character) # addiu $s4, $s4, -0x2c00
  addiu $s5, $sp, 0x40
.L7F006310:
  move  $a0, $zero
  move  $a1, $zero
  move  $a2, $s4
  move  $a3, $s3
  sw    $s1, 0x10($sp)
  jal   sub_GAME_7F06D2E4
   sw    $s5, 0x14($sp)
  lw    $t6, ($s0)
  lh    $t7, 0x40($sp)
  lw    $t9, 4($s0)
  lw    $t2, 8($s0)
  addu  $t8, $t6, $t7
  sw    $t8, ($s0)
  lh    $t0, 0x42($sp)
  addiu $s1, $s1, 1
  slt   $at, $s1, $s2
  addu  $t1, $t9, $t0
  sw    $t1, 4($s0)
  lh    $t3, 0x44($sp)
  addu  $t4, $t2, $t3
  bnez  $at, .L7F006310
   sw    $t4, 8($s0)
.L7F006368:
  lw    $ra, 0x34($sp)
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  lw    $s2, 0x24($sp)
  lw    $s3, 0x28($sp)
  lw    $s4, 0x2c($sp)
  lw    $s5, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x48
");

#ifdef VERSION_US
asm(R"
.late_rodata
glabel D_8004F1F0
.word 0x3dccccce
glabel D_8004F1F4
.word 0x4164924b
glabel D_8004F1F8
.word 0x3f6e147b

.text
glabel sets_a_bunch_of_BONDdata_values_to_default
  addiu $sp, $sp, -0xe0
  sw    $s2, 0x38($sp)
  lui   $s2, %hi(player_gait_object)
  addiu $s2, %lo(player_gait_object) # addiu $s2, $s2, -0x39b0
  lh    $t6, 0x14($s2)
  sw    $ra, 0x44($sp)
  sw    $s4, 0x40($sp)
  slti  $at, $t6, 0x1f
  sw    $s3, 0x3c($sp)
  sw    $s1, 0x34($sp)
  sw    $s0, 0x30($sp)
  sdc1  $f22, 0x28($sp)
  bnez  $at, .L7F0063CC
   sdc1  $f20, 0x20($sp)
  jal   return_null
   nop   
.L7F0063CC:
  lui   $s1, %hi(pPlayer)
  addiu $s1, %lo(pPlayer) # addiu $s1, $s1, -0x5f50
  lw    $s0, ($s1)
  move  $a1, $s2
  addiu $a0, $s0, 0x598
  jal   sub_GAME_7F075FAC
   addiu $a2, $s0, 0x654
  lui   $at, %hi(D_8004F1F0)
  lwc1  $f22, %lo(D_8004F1F0)($at)
  lw    $a0, ($s1)
  mfc1  $a1, $f22
  jal   set_obj_instance_controller_scale
   addiu $a0, $a0, 0x598
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f0
  lw    $t7, ($s1)
  lui   $at, %hi(D_8004F1F4)
  lwc1  $f2, %lo(D_8004F1F4)($at)
  sw    $zero, 0x4e8($t7)
  lui   $at, %hi(D_8004F1F8)
  lwc1  $f4, %lo(D_8004F1F8)($at)
  lw    $t8, ($s1)
  mtc1  $zero, $f20
  li    $v0, 1
  swc1  $f4, 0x4ec($t8)
  lw    $t9, ($s1)
  lui   $s0, %hi(D_80036AD0)
  lui   $s4, %hi(ptr_animation_table)
  sw    $zero, 0x4f0($t9)
  lw    $t0, ($s1)
  lui   $s3, %hi(D_80036B00)
  addiu $s3, %lo(D_80036B00) # addiu $s3, $s3, 0x6b00
  swc1  $f0, 0x4f4($t0)
  lw    $t1, ($s1)
  addiu $s4, %lo(ptr_animation_table) # addiu $s4, $s4, -0x6ac8
  addiu $s0, %lo(D_80036AD0) # addiu $s0, $s0, 0x6ad0
  swc1  $f0, 0x4f8($t1)
  lw    $t2, ($s1)
  addiu $s2, $sp, 0xd0
  swc1  $f20, 0x4fc($t2)
  lw    $t3, ($s1)
  swc1  $f20, 0x500($t3)
  lw    $t4, ($s1)
  swc1  $f20, 0x504($t4)
  lw    $t5, ($s1)
  swc1  $f20, 0x508($t5)
  lw    $t6, ($s1)
  swc1  $f20, 0x50c($t6)
  lw    $t7, ($s1)
  swc1  $f20, 0x510($t7)
  lw    $t8, ($s1)
  swc1  $f20, 0x514($t8)
  lw    $t9, ($s1)
  swc1  $f20, 0x518($t9)
  lw    $t0, ($s1)
  swc1  $f20, 0x51c($t0)
  lw    $t1, ($s1)
  swc1  $f20, 0x520($t1)
  lw    $t2, ($s1)
  swc1  $f20, 0x524($t2)
  lw    $t3, ($s1)
  swc1  $f20, 0x528($t3)
  lw    $t4, ($s1)
  swc1  $f20, 0x52c($t4)
  lw    $t5, ($s1)
  swc1  $f20, 0x530($t5)
  lw    $t6, ($s1)
  swc1  $f2, 0x534($t6)
  lw    $t7, ($s1)
  swc1  $f20, 0x538($t7)
  lw    $t8, ($s1)
  swc1  $f2, 0x53c($t8)
  lw    $t9, ($s1)
  swc1  $f20, 0x540($t9)
  lw    $t0, ($s1)
  sw    $v0, 0x4dc($t0)
  lw    $t1, ($s1)
  sw    $v0, 0x4e0($t1)
  lw    $t2, ($s1)
  sw    $v0, 0x4e4($t2)
  lw    $t3, ($s1)
  swc1  $f20, 0x544($t3)
  lw    $t4, ($s1)
  swc1  $f20, 0x548($t4)
  lw    $t5, ($s1)
  swc1  $f20, 0x54c($t5)
  lw    $t6, ($s1)
  swc1  $f20, 0x550($t6)
  lw    $t7, ($s1)
  swc1  $f20, 0x554($t7)
  lw    $t8, ($s1)
  swc1  $f20, 0x558($t8)
  lw    $t9, ($s1)
  swc1  $f20, 0x55c($t9)
  lw    $t0, ($s1)
  swc1  $f20, 0x560($t0)
  lw    $t1, ($s1)
  swc1  $f20, 0x564($t1)
  lw    $t2, ($s1)
  swc1  $f20, 0x568($t2)
  lw    $t3, ($s1)
  swc1  $f0, 0x56c($t3)
  lw    $t4, ($s1)
  swc1  $f20, 0x570($t4)
  lw    $t5, ($s1)
  swc1  $f20, 0x574($t5)
  lw    $t6, ($s1)
  swc1  $f0, 0x578($t6)
  lw    $t7, ($s1)
  swc1  $f20, 0x57c($t7)
  lw    $t8, ($s1)
  swc1  $f0, 0x580($t8)
  lw    $t9, ($s1)
  swc1  $f20, 0x584($t9)
  lw    $t0, ($s1)
  swc1  $f20, 0x588($t0)
  lw    $t1, ($s1)
  swc1  $f0, 0x58c($t1)
  lw    $t2, ($s1)
  swc1  $f20, 0x590($t2)
  lw    $t3, ($s1)
  sw    $zero, 0x594($t3)
.L7F0065B4:
  lwc1  $f6, 4($s0)
  lwc1  $f10, 8($s0)
  lw    $t4, ($s0)
  trunc.w.s $f8, $f6
  lw    $t5, ($s4)
  move  $a3, $s2
  trunc.w.s $f16, $f10
  mfc1  $a1, $f8
  addu  $a0, $t4, $t5
  mfc1  $a2, $f16
  jal   sub_GAME_7F0062C0
   nop   
  lw    $t8, 0xd8($sp)
  lwc1  $f18, 8($s0)
  lwc1  $f4, 4($s0)
  mtc1  $t8, $f8
  addiu $s0, $s0, 0x18
  sub.s $f6, $f18, $f4
  cvt.s.w $f10, $f8
  mul.s $f16, $f10, $f22
  div.s $f18, $f16, $f6
  bne   $s0, $s3, .L7F0065B4
   swc1  $f18, -0xc($s0)
  li    $at, 0x3F000000 # 0.500000
  lui   $t9, %hi(D_8002A790) 
  addiu $s2, $sp, 0x90
  addiu $t9, %lo(D_8002A790) # addiu $t9, $t9, -0x5870
  mtc1  $at, $f22
  addiu $t1, $t9, 0x3c
  move  $t2, $s2
.L7F00662C:
  lw    $at, ($t9)
  addiu $t9, $t9, 0xc
  addiu $t2, $t2, 0xc
  sw    $at, -0xc($t2)
  lw    $at, -8($t9)
  sw    $at, -8($t2)
  lw    $at, -4($t9)
  bne   $t9, $t1, .L7F00662C
   sw    $at, -4($t2)
  lw    $at, ($t9)
  lui   $t4, %hi(0x0000001C) # $t4, 0
  addiu $t4, %lo(0x0000001C) # addiu $t4, $t4, 0x1c
  sw    $at, ($t2)
  lw    $t3, ($s4)
  lw    $a0, ($s1)
  mfc1  $a3, $f20
  swc1  $f20, 0x14($sp)
  swc1  $f22, 0x10($sp)
  move  $a2, $zero
  addu  $a1, $t3, $t4
  jal   sub_GAME_7F06FCA8
   addiu $a0, $a0, 0x598
  lw    $a0, ($s1)
  jal   subcalcpos
   addiu $a0, $a0, 0x598
  addiu $s3, $sp, 0x50
  jal   matrix_4x4_set_identity
   move  $a0, $s3
  lw    $s0, ($s1)
  sw    $s3, 0x90($sp)
  move  $a0, $s2
  addiu $t5, $s0, 0x6d0
  sw    $t5, 0xa0($sp)
  jal   subcalcmatrices
   addiu $a1, $s0, 0x598
  lw    $s0, ($s1)
  li    $s3, 24
  lui   $s2, %hi(D_80036AD0)
  lwc1  $f4, 0x704($s0)
  addiu $s2, %lo(D_80036AD0) # addiu $s2, $s2, 0x6ad0
  move  $a2, $zero
  swc1  $f4, 0x550($s0)
  lw    $t6, ($s1)
  swc1  $f20, 0x554($t6)
  lw    $s0, ($s1)
  lwc1  $f8, 0x744($s0)
  lwc1  $f10, 0x704($s0)
  sub.s $f16, $f8, $f10
  swc1  $f16, 0x558($s0)
  lw    $s0, ($s1)
  lwc1  $f6, 0x748($s0)
  lwc1  $f18, 0x708($s0)
  sub.s $f4, $f6, $f18
  swc1  $f4, 0x55c($s0)
  lw    $s0, ($s1)
  lw    $t1, ($s4)
  lw    $t7, 0x4e8($s0)
  swc1  $f20, 0x14($sp)
  swc1  $f22, 0x10($sp)
  multu $t7, $s3
  addiu $a0, $s0, 0x598
  mflo  $t8
  addu  $v0, $s2, $t8
  lw    $t0, ($v0)
  lw    $a3, 4($v0)
  jal   sub_GAME_7F06FCA8
   addu  $a1, $t0, $t1
  lw    $s0, ($s1)
  mfc1  $a2, $f20
  lw    $t9, 0x4e8($s0)
  addiu $a0, $s0, 0x598
  multu $t9, $s3
  mflo  $t2
  addu  $t3, $s2, $t2
  jal   sub_GAME_7F06FDCC
   lw    $a1, 4($t3)
  lw    $s0, ($s1)
  lw    $t4, 0x4e8($s0)
  addiu $a0, $s0, 0x598
  multu $t4, $s3
  mflo  $t5
  addu  $t6, $s2, $t5
  jal   sub_GAME_7F06FDE8
   lw    $a1, 8($t6)
  lw    $a0, ($s1)
  lui   $a1, %hi(sub_GAME_7F08DBB0) # $a1, 0x7f09
  addiu $a1, %lo(sub_GAME_7F08DBB0) # addiu $a1, $a1, -0x2450
  jal   sub_GAME_7F06FE3C
   addiu $a0, $a0, 0x598
  jal   sub_GAME_7F08DBC8
   nop   
  lw    $ra, 0x44($sp)
  ldc1  $f20, 0x20($sp)
  ldc1  $f22, 0x28($sp)
  lw    $s0, 0x30($sp)
  lw    $s1, 0x34($sp)
  lw    $s2, 0x38($sp)
  lw    $s3, 0x3c($sp)
  lw    $s4, 0x40($sp)
  jr    $ra
   addiu $sp, $sp, 0xe0
");
#endif

#ifdef VERSION_JP
asm(R"
.late_rodata
glabel D_8004F1F0
.word 0x3dccccce
glabel D_8004F1F4
.word 0x4164924b
glabel D_8004F1F8
.word 0x3f6e147b

.text
glabel sets_a_bunch_of_BONDdata_values_to_default
  addiu $sp, $sp, -0xe0
  sw    $s2, 0x38($sp)
  lui   $s2, %hi(player_gait_object) # $s2, 0x8004
  addiu $s2, %lo(player_gait_object) # addiu $s2, $s2, -0x3980
  lh    $t6, 0x14($s2)
  sw    $ra, 0x44($sp)
  sw    $s4, 0x40($sp)
  slti  $at, $t6, 0x1f
  sw    $s3, 0x3c($sp)
  sw    $s1, 0x34($sp)
  sw    $s0, 0x30($sp)
  sdc1  $f22, 0x28($sp)
  bnez  $at, .L7F0063CC
   sdc1  $f20, 0x20($sp)
  jal   return_null
   nop   
.L7F0063CC:
  lui   $s1, %hi(pPlayer) # $s1, 0x8008
  addiu $s1, %lo(pPlayer) # addiu $s1, $s1, -0x5ee0
  lw    $s0, ($s1)
  move  $a1, $s2
  addiu $a0, $s0, 0x598
  jal   sub_GAME_7F075FAC
   addiu $a2, $s0, 0x654
  lui   $at, %hi(D_8004F1F0) # $at, 0x8005
  lwc1  $f22, %lo(D_8004F1F0)($at)
  lw    $a0, ($s1)
  mfc1  $a1, $f22
  jal   set_obj_instance_controller_scale
   addiu $a0, $a0, 0x598
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f0
  mtc1  $zero, $f20
  lw    $a0, ($s1)
  mfc1  $a1, $f0
  mfc1  $a2, $f20
  jal   sub_GAME_7F06FF18
   addiu $a0, $a0, 0x598
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f0
  lw    $t7, ($s1)
  lui   $at, %hi(D_8004F1F4) # $at, 0x8005
  lwc1  $f2, %lo(D_8004F1F4)($at)
  sw    $zero, 0x4e8($t7)
  lui   $at, %hi(D_8004F1F8) # $at, 0x8005
  lwc1  $f4, %lo(D_8004F1F8)($at)
  lw    $t8, ($s1)
  li    $v0, 1
  lui   $s0, %hi(D_80036AD0) # $s0, 0x8003
  swc1  $f4, 0x4ec($t8)
  lw    $t9, ($s1)
  lui   $s4, %hi(ptr_animation_table) # $s4, 0x8007
  lui   $s3, %hi(D_80036B00) # $s3, 0x8003
  sw    $zero, 0x4f0($t9)
  lw    $t0, ($s1)
  addiu $s3, %lo(D_80036B00) # addiu $s3, $s3, 0x6b30
  addiu $s4, %lo(ptr_animation_table) # addiu $s4, $s4, -0x6a88
  swc1  $f0, 0x4f4($t0)
  lw    $t1, ($s1)
  addiu $s0, %lo(D_80036AD0) # addiu $s0, $s0, 0x6b00
  addiu $s2, $sp, 0xd0
  swc1  $f0, 0x4f8($t1)
  lw    $t2, ($s1)
  swc1  $f20, 0x4fc($t2)
  lw    $t3, ($s1)
  swc1  $f20, 0x500($t3)
  lw    $t4, ($s1)
  swc1  $f20, 0x504($t4)
  lw    $t5, ($s1)
  swc1  $f20, 0x508($t5)
  lw    $t6, ($s1)
  swc1  $f20, 0x50c($t6)
  lw    $t7, ($s1)
  swc1  $f20, 0x510($t7)
  lw    $t8, ($s1)
  swc1  $f20, 0x514($t8)
  lw    $t9, ($s1)
  swc1  $f20, 0x518($t9)
  lw    $t0, ($s1)
  swc1  $f20, 0x51c($t0)
  lw    $t1, ($s1)
  swc1  $f20, 0x520($t1)
  lw    $t2, ($s1)
  swc1  $f20, 0x524($t2)
  lw    $t3, ($s1)
  swc1  $f20, 0x528($t3)
  lw    $t4, ($s1)
  swc1  $f20, 0x52c($t4)
  lw    $t5, ($s1)
  swc1  $f20, 0x530($t5)
  lw    $t6, ($s1)
  swc1  $f2, 0x534($t6)
  lw    $t7, ($s1)
  swc1  $f20, 0x538($t7)
  lw    $t8, ($s1)
  swc1  $f2, 0x53c($t8)
  lw    $t9, ($s1)
  swc1  $f20, 0x540($t9)
  lw    $t0, ($s1)
  sw    $v0, 0x4dc($t0)
  lw    $t1, ($s1)
  sw    $v0, 0x4e0($t1)
  lw    $t2, ($s1)
  sw    $v0, 0x4e4($t2)
  lw    $t3, ($s1)
  swc1  $f20, 0x544($t3)
  lw    $t4, ($s1)
  swc1  $f20, 0x548($t4)
  lw    $t5, ($s1)
  swc1  $f20, 0x54c($t5)
  lw    $t6, ($s1)
  swc1  $f20, 0x550($t6)
  lw    $t7, ($s1)
  swc1  $f20, 0x554($t7)
  lw    $t8, ($s1)
  swc1  $f20, 0x558($t8)
  lw    $t9, ($s1)
  swc1  $f20, 0x55c($t9)
  lw    $t0, ($s1)
  swc1  $f20, 0x560($t0)
  lw    $t1, ($s1)
  swc1  $f20, 0x564($t1)
  lw    $t2, ($s1)
  swc1  $f20, 0x568($t2)
  lw    $t3, ($s1)
  swc1  $f0, 0x56c($t3)
  lw    $t4, ($s1)
  swc1  $f20, 0x570($t4)
  lw    $t5, ($s1)
  swc1  $f20, 0x574($t5)
  lw    $t6, ($s1)
  swc1  $f0, 0x578($t6)
  lw    $t7, ($s1)
  swc1  $f20, 0x57c($t7)
  lw    $t8, ($s1)
  swc1  $f0, 0x580($t8)
  lw    $t9, ($s1)
  swc1  $f20, 0x584($t9)
  lw    $t0, ($s1)
  swc1  $f20, 0x588($t0)
  lw    $t1, ($s1)
  swc1  $f0, 0x58c($t1)
  lw    $t2, ($s1)
  swc1  $f20, 0x590($t2)
  lw    $t3, ($s1)
  sw    $zero, 0x594($t3)
.L7F0065D0:
  lwc1  $f6, 4($s0)
  lwc1  $f10, 8($s0)
  lw    $t4, ($s0)
  trunc.w.s $f8, $f6
  lw    $t5, ($s4)
  move  $a3, $s2
  trunc.w.s $f16, $f10
  mfc1  $a1, $f8
  addu  $a0, $t4, $t5
  mfc1  $a2, $f16
  jal   sub_GAME_7F0062C0
   nop   
  lw    $t8, 0xd8($sp)
  lwc1  $f18, 8($s0)
  lwc1  $f4, 4($s0)
  mtc1  $t8, $f8
  addiu $s0, $s0, 0x18
  sub.s $f6, $f18, $f4
  cvt.s.w $f10, $f8
  mul.s $f16, $f10, $f22
  div.s $f18, $f16, $f6
  bne   $s0, $s3, .L7F0065D0
   swc1  $f18, -0xc($s0)
  li    $at, 0x3F000000 # 0.500000
  lui   $t9, %hi(D_8002A790) # $t9, 0x8003
  addiu $s2, $sp, 0x90
  addiu $t9, %lo(D_8002A790) # addiu $t9, $t9, -0x5830
  mtc1  $at, $f22
  addiu $t1, $t9, 0x3c
  move  $t2, $s2
.L7F006648:
  lw    $at, ($t9)
  addiu $t9, $t9, 0xc
  addiu $t2, $t2, 0xc
  sw    $at, -0xc($t2)
  lw    $at, -8($t9)
  sw    $at, -8($t2)
  lw    $at, -4($t9)
  bne   $t9, $t1, .L7F006648
   sw    $at, -4($t2)
  lw    $at, ($t9)
  lui   $t4, %hi(0x0000001C) # $t4, 0
  addiu $t4, %lo(0x0000001C) # addiu $t4, $t4, 0x1c
  sw    $at, ($t2)
  lw    $t3, ($s4)
  lw    $a0, ($s1)
  mfc1  $a3, $f20
  swc1  $f20, 0x14($sp)
  swc1  $f22, 0x10($sp)
  move  $a2, $zero
  addu  $a1, $t3, $t4
  jal   sub_GAME_7F06FCA8
   addiu $a0, $a0, 0x598
  lw    $a0, ($s1)
  jal   subcalcpos
   addiu $a0, $a0, 0x598
  addiu $s3, $sp, 0x50
  jal   matrix_4x4_set_identity
   move  $a0, $s3
  lw    $s0, ($s1)
  sw    $s3, 0x90($sp)
  move  $a0, $s2
  addiu $t5, $s0, 0x6d0
  sw    $t5, 0xa0($sp)
  jal   subcalcmatrices
   addiu $a1, $s0, 0x598
  lw    $s0, ($s1)
  li    $s3, 24
  lui   $s2, %hi(D_80036AD0) # $s2, 0x8003
  lwc1  $f4, 0x704($s0)
  addiu $s2, %lo(D_80036AD0) # addiu $s2, $s2, 0x6b00
  move  $a2, $zero
  swc1  $f4, 0x550($s0)
  lw    $t6, ($s1)
  swc1  $f20, 0x554($t6)
  lw    $s0, ($s1)
  lwc1  $f8, 0x744($s0)
  lwc1  $f10, 0x704($s0)
  sub.s $f16, $f8, $f10
  swc1  $f16, 0x558($s0)
  lw    $s0, ($s1)
  lwc1  $f6, 0x748($s0)
  lwc1  $f18, 0x708($s0)
  sub.s $f4, $f6, $f18
  swc1  $f4, 0x55c($s0)
  lw    $s0, ($s1)
  lw    $t1, ($s4)
  lw    $t7, 0x4e8($s0)
  swc1  $f20, 0x14($sp)
  swc1  $f22, 0x10($sp)
  multu $t7, $s3
  addiu $a0, $s0, 0x598
  mflo  $t8
  addu  $v0, $s2, $t8
  lw    $t0, ($v0)
  lw    $a3, 4($v0)
  jal   sub_GAME_7F06FCA8
   addu  $a1, $t0, $t1
  lw    $s0, ($s1)
  mfc1  $a2, $f20
  lw    $t9, 0x4e8($s0)
  addiu $a0, $s0, 0x598
  multu $t9, $s3
  mflo  $t2
  addu  $t3, $s2, $t2
  jal   sub_GAME_7F06FDCC
   lw    $a1, 4($t3)
  lw    $s0, ($s1)
  lw    $t4, 0x4e8($s0)
  addiu $a0, $s0, 0x598
  multu $t4, $s3
  mflo  $t5
  addu  $t6, $s2, $t5
  jal   sub_GAME_7F06FDE8
   lw    $a1, 8($t6)
  lw    $a0, ($s1)
  lui   $a1, %hi(sub_GAME_7F08DBB0) # $a1, 0x7f09
  addiu $a1, %lo(sub_GAME_7F08DBB0) # addiu $a1, $a1, -0x1970
  jal   sub_GAME_7F06FE3C
   addiu $a0, $a0, 0x598
  jal   sub_GAME_7F08DBC8
   nop   
  lw    $ra, 0x44($sp)
  ldc1  $f20, 0x20($sp)
  ldc1  $f22, 0x28($sp)
  lw    $s0, 0x30($sp)
  lw    $s1, 0x34($sp)
  lw    $s2, 0x38($sp)
  lw    $s3, 0x3c($sp)
  lw    $s4, 0x40($sp)
  jr    $ra
   addiu $sp, $sp, 0xe0
");
#endif
