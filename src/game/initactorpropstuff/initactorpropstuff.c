void sub_GAME_7F0009A0(void);

asm(R"
glabel reset_counter_rand_body_head
  lui   $a0, %hi(list_of_bodies)
  addiu $a0, %lo(list_of_bodies) # addiu $a0, $a0, -0x32f4
  sll   $t6, $zero, 2
  addu  $t7, $a0, $t6
  lw    $t8, ($t7)
  lui   $v1, %hi(num_bodies)
  addiu $v1, %lo(num_bodies) # addiu $v1, $v1, -0x3300
  sw    $zero, ($v1)
  bltz  $t8, .L7F000158
   move  $v0, $zero
  addiu $t9, $v0, 1
.L7F00013C:
  sll   $t0, $t9, 2
  addu  $t1, $a0, $t0
  lw    $t2, ($t1)
  sw    $t9, ($v1)
  move  $v0, $t9
  bgezl $t2, .L7F00013C
   addiu $t9, $v0, 1
.L7F000158:
  lui   $a0, %hi(random_male_heads)
  addiu $a0, %lo(random_male_heads) # addiu $a0, $a0, -0x3248
  sll   $t3, $zero, 2
  addu  $t4, $a0, $t3
  lw    $t5, ($t4)
  lui   $v1, %hi(num_male_heads)
  addiu $v1, %lo(num_male_heads) # addiu $v1, $v1, -0x32fc
  sw    $zero, ($v1)
  bltz  $t5, .L7F0001A0
   move  $v0, $zero
  addiu $t6, $v0, 1
.L7F000184:
  sll   $t7, $t6, 2
  addu  $t8, $a0, $t7
  lw    $t9, ($t8)
  sw    $t6, ($v1)
  move  $v0, $t6
  bgezl $t9, .L7F000184
   addiu $t6, $v0, 1
.L7F0001A0:
  lui   $a0, %hi(random_female_heads)
  addiu $a0, %lo(random_female_heads) # addiu $a0, $a0, -0x31e0
  sll   $t0, $zero, 2
  addu  $t1, $a0, $t0
  lw    $t2, ($t1)
  lui   $v1, %hi(num_female_heads)
  addiu $v1, %lo(num_female_heads) # addiu $v1, $v1, -0x32f8
  sw    $zero, ($v1)
  bltz  $t2, .L7F0001E8
   move  $v0, $zero
  addiu $t3, $v0, 1
.L7F0001CC:
  sll   $t4, $t3, 2
  addu  $t5, $a0, $t4
  lw    $t6, ($t5)
  sw    $t3, ($v1)
  move  $v0, $t3
  bgezl $t6, .L7F0001CC
   addiu $t3, $v0, 1
.L7F0001E8:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0001F0
  addiu $sp, $sp, -0x48
  sw    $s3, 0x28($sp)
  sw    $s2, 0x24($sp)
  sw    $s1, 0x20($sp)
  sw    $s0, 0x1c($sp)
  slt   $at, $a1, $a2
  move  $s0, $a1
  move  $s2, $a2
  move  $s3, $a0
  sw    $ra, 0x34($sp)
  sw    $s5, 0x30($sp)
  sw    $s4, 0x2c($sp)
  beqz  $at, .L7F000268
   move  $s1, $zero
  lui   $s4, %hi(model_guard_character)
  addiu $s4, %lo(model_guard_character) # addiu $s4, $s4, -0x2c00
  addiu $s5, $sp, 0x40
.L7F000234:
  move  $a0, $zero
  move  $a1, $zero
  move  $a2, $s4
  move  $a3, $s3
  sw    $s0, 0x10($sp)
  jal   sub_GAME_7F06D2E4
   sw    $s5, 0x14($sp)
  addu  $s1, $s1, $v0
  addiu $s0, $s0, 1
  andi  $t6, $s1, 0xffff
  slt   $at, $s0, $s2
  bnez  $at, .L7F000234
   move  $s1, $t6
.L7F000268:
  lw    $ra, 0x34($sp)
  move  $v0, $s1
  lw    $s1, 0x20($sp)
  lw    $s0, 0x1c($sp)
  lw    $s2, 0x24($sp)
  lw    $s3, 0x28($sp)
  lw    $s4, 0x2c($sp)
  lw    $s5, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x48
");

asm(R"
glabel sub_GAME_7F000290
  addiu $sp, $sp, -0x48
  sw    $s3, 0x28($sp)
  sw    $s2, 0x24($sp)
  sw    $s1, 0x20($sp)
  sw    $s0, 0x1c($sp)
  slt   $at, $a1, $a2
  move  $s0, $a1
  move  $s2, $a2
  move  $s3, $a0
  sw    $ra, 0x34($sp)
  sw    $s5, 0x30($sp)
  sw    $s4, 0x2c($sp)
  beqz  $at, .L7F000304
   move  $s1, $zero
  lui   $s4, %hi(model_guard_character)
  addiu $s4, %lo(model_guard_character) # addiu $s4, $s4, -0x2c00
  addiu $s5, $sp, 0x3c
.L7F0002D4:
  move  $a0, $zero
  move  $a1, $zero
  move  $a2, $s4
  move  $a3, $s3
  sw    $s0, 0x10($sp)
  jal   sub_GAME_7F06D2E4
   sw    $s5, 0x14($sp)
  lh    $t6, 0x40($sp)
  addiu $s0, $s0, 1
  slt   $at, $s0, $s2
  bnez  $at, .L7F0002D4
   addu  $s1, $s1, $t6
.L7F000304:
  lw    $ra, 0x34($sp)
  move  $v0, $s1
  lw    $s1, 0x20($sp)
  lw    $s0, 0x1c($sp)
  lw    $s2, 0x24($sp)
  lw    $s3, 0x28($sp)
  lw    $s4, 0x2c($sp)
  lw    $s5, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x48
");

asm(R"
.late_rodata
glabel F32_8004ED70
.word 0x40c90fdb
glabel F32_8004ED74
.word 0x38c90fdb
.text
glabel sub_GAME_7F00032C
  addiu $sp, $sp, -0x40
  sw    $ra, 0x3c($sp)
  sw    $s3, 0x38($sp)
  sw    $s2, 0x34($sp)
  sw    $s1, 0x30($sp)
  sw    $s0, 0x2c($sp)
  sdc1  $f24, 0x20($sp)
  sdc1  $f22, 0x18($sp)
  sdc1  $f20, 0x10($sp)
  lw    $t6, ($a0)
  move  $s1, $zero
  move  $s0, $a0
  beqz  $t6, .L7F000440
   move  $v0, $t6
  lui   $at, %hi(F32_8004ED70)
  lwc1  $f24, %lo(F32_8004ED70)($at)
  lui   $at, %hi(F32_8004ED74)
  lui   $s2, %hi(ptr_animation_table)
  mtc1  $zero, $f20
  addiu $s2, %lo(ptr_animation_table) # addiu $s2, $s2, -0x6ac8
  lwc1  $f22, %lo(F32_8004ED74)($at)
  li    $s3, 32768
  lw    $t7, ($s2)
.L7F000388:
  lwc1  $f12, 4($s0)
  addu  $t8, $v0, $t7
  jal   sub_GAME_7F05C3D8
   sw    $t8, ($s0)
  lw    $a0, ($s0)
  move  $a1, $zero
  jal   sub_GAME_7F0001F0
   move  $a2, $v0
  lwc1  $f0, 4($s0)
  andi  $v1, $v0, 0xffff
  slt   $at, $v1, $s3
  c.lt.s $f20, $f0
  nop   
  bc1fl .L7F00042C
   swc1  $f20, 8($s0)
  beql  $at, $zero, .L7F0003FC
   mtc1  $v1, $f18
  mtc1  $v1, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v1, .L7F0003E8
   cvt.s.w $f6, $f4
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F0003E8:
  mul.s $f10, $f6, $f22
  div.s $f16, $f10, $f0
  b     .L7F00042C
   swc1  $f16, 8($s0)
  mtc1  $v1, $f18
.L7F0003FC:
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v1, .L7F000414
   cvt.s.w $f4, $f18
  mtc1  $at, $f8
  nop   
  add.s $f4, $f4, $f8
.L7F000414:
  mul.s $f6, $f4, $f22
  sub.s $f10, $f6, $f24
  div.s $f16, $f10, $f0
  b     .L7F00042C
   swc1  $f16, 8($s0)
  swc1  $f20, 8($s0)
.L7F00042C:
  lw    $v0, 0x48($s0)
  addiu $s0, $s0, 0x48
  addiu $s1, $s1, 1
  bnezl $v0, .L7F000388
   lw    $t7, ($s2)
.L7F000440:
  lw    $ra, 0x3c($sp)
  move  $v0, $s1
  lw    $s1, 0x30($sp)
  ldc1  $f20, 0x10($sp)
  ldc1  $f22, 0x18($sp)
  ldc1  $f24, 0x20($sp)
  lw    $s0, 0x2c($sp)
  lw    $s2, 0x34($sp)
  lw    $s3, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x40
");

asm(R"
glabel sub_GAME_7F00046C
  addiu $sp, $sp, -0x28
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $ra, 0x24($sp)
  move  $s0, $a0
  move  $s1, $zero
  li    $s2, 128
.L7F00048C:
  lw    $v0, ($s0)
  lw    $t6, 4($v0)
  bgezl $t6, .L7F0004B0
   addiu $s1, $s1, 4
  jal   sub_GAME_7F00032C
   lw    $a0, ($v0)
  lw    $t7, ($s0)
  sw    $v0, 4($t7)
  addiu $s1, $s1, 4
.L7F0004B0:
  bne   $s1, $s2, .L7F00048C
   addiu $s0, $s0, 4
  lw    $ra, 0x24($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
glabel sub_GAME_7F0004D0
  lw    $t6, ($a0)
  move  $v1, $zero
  move  $v0, $a0
  beqz  $t6, .L7F000510
   nop   
  lw    $a1, ($a0)
  lui   $a0, %hi(ptr_animation_table)
  addiu $a0, %lo(ptr_animation_table) # addiu $a0, $a0, -0x6ac8
  lw    $t7, ($a0)
.L7F0004F4:
  addiu $v1, $v1, 1
  addiu $v0, $v0, 0x1c
  addu  $t8, $a1, $t7
  lw    $a1, ($v0)
  sw    $t8, -0x1c($v0)
  bnezl $a1, .L7F0004F4
   lw    $t7, ($a0)
.L7F000510:
  jr    $ra
   move  $v0, $v1
");

asm(R"
.late_rodata
glabel F32_8004ED78
.word 0x3dccccce
.text
glabel somethingwith_weapon_animation_groups
  addiu $sp, $sp, -0x40
  lui   $t6, %hi(D_8002C914) 
  lw    $t6, %lo(D_8002C914)($t6)
  sw    $s1, 0x24($sp)
  li    $s1, -1
  sw    $ra, 0x2c($sp)
  sw    $s2, 0x28($sp)
  sw    $s0, 0x20($sp)
  beq   $s1, $t6, .L7F000588
   sdc1  $f20, 0x18($sp)
  lui   $s0, %hi(D_8002C914)
  addiu $s0, %lo(D_8002C914) # addiu $s0, $s0, -0x36ec
  lw    $a0, 0x1c($s0)
.L7F00054C:
  beql  $a0, $zero, .L7F000564
   lw    $a0, 0x24($s0)
  jal   sub_GAME_7F0004D0
   nop   
  sw    $v0, 0x20($s0)
  lw    $a0, 0x24($s0)
.L7F000564:
  beql  $a0, $zero, .L7F00057C
   lw    $t7, 0x2c($s0)
  jal   sub_GAME_7F0004D0
   nop   
  sw    $v0, 0x28($s0)
  lw    $t7, 0x2c($s0)
.L7F00057C:
  addiu $s0, $s0, 0x2c
  bnel  $s1, $t7, .L7F00054C
   lw    $a0, 0x1c($s0)
.L7F000588:
  lui   $a0, %hi(D_8002DEBC)
  jal   sub_GAME_7F0004D0
   addiu $a0, %lo(D_8002DEBC) # addiu $a0, $a0, -0x2144
  lui   $a0, %hi(ptr_rifle_firing_animation_groups)
  jal   sub_GAME_7F00046C
   addiu $a0, %lo(ptr_rifle_firing_animation_groups) # addiu $a0, $a0, -0x12d8
  lui   $a0, %hi(ptr_pistol_firing_animation_groups)
  jal   sub_GAME_7F00046C
   addiu $a0, %lo(ptr_pistol_firing_animation_groups) # addiu $a0, $a0, -0xbf8
  lui   $a0, %hi(ptr_doubles_firing_animation_groups)
  jal   sub_GAME_7F00046C
   addiu $a0, %lo(ptr_doubles_firing_animation_groups) # addiu $a0, $a0, -0x920
  lui   $a0, %hi(ptr_crouched_rifle_firing_animation_groups)
  jal   sub_GAME_7F00046C
   addiu $a0, %lo(ptr_crouched_rifle_firing_animation_groups) # addiu $a0, $a0, -0x690
  lui   $a0, %hi(ptr_crouched_pistol_firing_animation_groups)
  jal   sub_GAME_7F00046C
   addiu $a0, %lo(ptr_crouched_pistol_firing_animation_groups) # addiu $a0, $a0, -0x328
  lui   $a0, %hi(ptr_crouched_doubles_firing_animation_groups)
  jal   sub_GAME_7F00046C
   addiu $a0, %lo(ptr_crouched_doubles_firing_animation_groups) # addiu $a0, $a0, -8
  lui   $a0, %hi(D_80030078)
  jal   sub_GAME_7F00032C
   addiu $a0, %lo(D_80030078) # addiu $a0, $a0, 0x78
  lui   $a0, %hi(D_80030660)
  jal   sub_GAME_7F00032C
   addiu $a0, %lo(D_80030660) # addiu $a0, $a0, 0x660
  lui   $s2, %hi(ptr_animation_table)
  addiu $s2, %lo(ptr_animation_table) # addiu $s2, $s2, -0x6ac8
  lw    $t8, ($s2)
  lui   $s1, %hi(0x00004018) # $s1, 0
  addiu $s1, %lo(0x00004018) # addiu $s1, $s1, 0x4018
  addu  $a0, $s1, $t8
  lhu   $a2, 4($a0)
  move  $a1, $zero
  jal   sub_GAME_7F000290
   addiu $a2, $a2, -1
  mtc1  $v0, $f4
  lw    $s0, ($s2)
  lui   $at, %hi(F32_8004ED78)
  cvt.s.w $f6, $f4
  addu  $t9, $s1, $s0
  lhu   $t0, 4($t9)
  lwc1  $f20, %lo(F32_8004ED78)($at)
  mtc1  $t0, $f10
  mul.s $f8, $f6, $f20
  bgez  $t0, .L7F000658
   cvt.s.w $f16, $f10
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f18
  nop   
  add.s $f16, $f16, $f18
.L7F000658:
  div.s $f4, $f8, $f16
  lui   $v1, %hi(0x000040D4) # $v1, 0
  lui   $at, %hi(D_80030984)
  addiu $v1, %lo(0x000040D4) # addiu $v1, $v1, 0x40d4
  addu  $a0, $v1, $s0
  move  $a1, $zero
  swc1  $f4, %lo(D_80030984)($at)
  lhu   $a2, 4($a0)
  sw    $v1, 0x34($sp)
  jal   sub_GAME_7F000290
   addiu $a2, $a2, -1
  mtc1  $v0, $f6
  lw    $v1, 0x34($sp)
  lw    $s0, ($s2)
  cvt.s.w $f10, $f6
  addu  $t1, $v1, $s0
  lhu   $t2, 4($t1)
  mtc1  $t2, $f8
  mul.s $f18, $f10, $f20
  bgez  $t2, .L7F0006BC
   cvt.s.w $f16, $f8
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f4
  nop   
  add.s $f16, $f16, $f4
.L7F0006BC:
  div.s $f6, $f18, $f16
  lui   $s1, %hi(0x00004070) # $s1, 0
  lui   $at, %hi(D_80030988)
  addiu $s1, %lo(0x00004070) # addiu $s1, $s1, 0x4070
  addu  $a0, $s1, $s0
  move  $a1, $zero
  swc1  $f6, %lo(D_80030988)($at)
  lhu   $a2, 4($a0)
  jal   sub_GAME_7F000290
   addiu $a2, $a2, -1
  mtc1  $v0, $f10
  lw    $s0, ($s2)
  cvt.s.w $f8, $f10
  addu  $t3, $s1, $s0
  lhu   $t4, 4($t3)
  mtc1  $t4, $f18
  mul.s $f4, $f8, $f20
  bgez  $t4, .L7F000718
   cvt.s.w $f16, $f18
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f6
  nop   
  add.s $f16, $f16, $f6
.L7F000718:
  div.s $f10, $f4, $f16
  lui   $v1, %hi(0x00008204) # $v1, 1
  lui   $at, %hi(D_8003098C)
  addiu $v1, %lo(0x00008204) # addiu $v1, $v1, -0x7dfc
  addu  $a0, $v1, $s0
  move  $a1, $zero
  swc1  $f10, %lo(D_8003098C)($at)
  lhu   $a2, 4($a0)
  sw    $v1, 0x34($sp)
  jal   sub_GAME_7F000290
   addiu $a2, $a2, -1
  mtc1  $v0, $f8
  lw    $v1, 0x34($sp)
  lw    $s0, ($s2)
  cvt.s.w $f18, $f8
  addu  $t5, $v1, $s0
  lhu   $t6, 4($t5)
  mtc1  $t6, $f4
  mul.s $f6, $f18, $f20
  bgez  $t6, .L7F00077C
   cvt.s.w $f16, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f10
  nop   
  add.s $f16, $f16, $f10
.L7F00077C:
  div.s $f8, $f6, $f16
  lui   $a3, %hi(0x0000777C) # $a3, 0
  lui   $at, %hi(D_80030990)
  addiu $a3, %lo(0x0000777C) # addiu $a3, $a3, 0x777c
  addu  $a0, $a3, $s0
  move  $a1, $zero
  swc1  $f8, %lo(D_80030990)($at)
  lhu   $a2, 4($a0)
  sw    $a3, 0x38($sp)
  jal   sub_GAME_7F000290
   addiu $a2, $a2, -1
  mtc1  $v0, $f18
  lw    $a3, 0x38($sp)
  lw    $s0, ($s2)
  cvt.s.w $f4, $f18
  li    $at, 0x4F800000 # 4294967296.000000
  addu  $t7, $a3, $s0
  lhu   $t8, 4($t7)
  mtc1  $t8, $f6
  mul.s $f10, $f4, $f20
  bgez  $t8, .L7F0007E0
   cvt.s.w $f16, $f6
  mtc1  $at, $f8
  nop   
  add.s $f16, $f16, $f8
.L7F0007E0:
  div.s $f18, $f10, $f16
  lui   $s1, %hi(0x000077D4) # $s1, 0
  lui   $at, %hi(D_80030994)
  addiu $s1, %lo(0x000077D4) # addiu $s1, $s1, 0x77d4
  addu  $a0, $s1, $s0
  move  $a1, $zero
  swc1  $f18, %lo(D_80030994)($at)
  lhu   $a2, 4($a0)
  jal   sub_GAME_7F000290
   addiu $a2, $a2, -1
  mtc1  $v0, $f4
  lw    $s0, ($s2)
  li    $at, 0x4F800000 # 4294967296.000000
  cvt.s.w $f6, $f4
  addu  $t9, $s1, $s0
  lhu   $t0, 4($t9)
  mtc1  $t0, $f10
  mul.s $f8, $f6, $f20
  bgez  $t0, .L7F00083C
   cvt.s.w $f16, $f10
  mtc1  $at, $f18
  nop   
  add.s $f16, $f16, $f18
.L7F00083C:
  div.s $f4, $f8, $f16
  lui   $v1, %hi(0x000084C4) # $v1, 1
  lui   $at, %hi(D_80030998)
  addiu $v1, %lo(0x000084C4) # addiu $v1, $v1, -0x7b3c
  addu  $a0, $v1, $s0
  move  $a1, $zero
  swc1  $f4, %lo(D_80030998)($at)
  lhu   $a2, 4($a0)
  sw    $v1, 0x38($sp)
  jal   sub_GAME_7F000290
   addiu $a2, $a2, -1
  mtc1  $v0, $f6
  lw    $v1, 0x38($sp)
  lw    $s0, ($s2)
  cvt.s.w $f10, $f6
  li    $at, 0x4F800000 # 4294967296.000000
  addu  $t1, $v1, $s0
  lhu   $t2, 4($t1)
  mtc1  $t2, $f8
  mul.s $f18, $f10, $f20
  bgez  $t2, .L7F0008A0
   cvt.s.w $f16, $f8
  mtc1  $at, $f4
  nop   
  add.s $f16, $f16, $f4
.L7F0008A0:
  div.s $f6, $f18, $f16
  lui   $a3, %hi(0x00008520) # $a3, 1
  lui   $at, %hi(D_8003099C)
  addiu $a3, %lo(0x00008520) # addiu $a3, $a3, -0x7ae0
  addu  $a0, $a3, $s0
  move  $a1, $zero
  swc1  $f6, %lo(D_8003099C)($at)
  lhu   $a2, 4($a0)
  sw    $a3, 0x30($sp)
  jal   sub_GAME_7F000290
   addiu $a2, $a2, -1
  mtc1  $v0, $f10
  lw    $a3, 0x30($sp)
  lw    $s0, ($s2)
  cvt.s.w $f8, $f10
  li    $at, 0x4F800000 # 4294967296.000000
  addu  $t3, $a3, $s0
  lhu   $t4, 4($t3)
  mtc1  $t4, $f18
  mul.s $f4, $f8, $f20
  bgez  $t4, .L7F000904
   cvt.s.w $f16, $f18
  mtc1  $at, $f6
  nop   
  add.s $f16, $f16, $f6
.L7F000904:
  div.s $f10, $f4, $f16
  lui   $at, %hi(D_800309A0)
  addu  $a0, $s1, $s0
  move  $a1, $zero
  swc1  $f10, %lo(D_800309A0)($at)
  lhu   $a2, 4($a0)
  jal   sub_GAME_7F000290
   addiu $a2, $a2, -1
  mtc1  $v0, $f8
  lw    $t5, ($s2)
  li    $at, 0x4F800000 # 4294967296.000000
  cvt.s.w $f18, $f8
  addu  $t6, $s1, $t5
  lhu   $t7, 4($t6)
  mtc1  $t7, $f4
  mul.s $f6, $f18, $f20
  bgez  $t7, .L7F000958
   cvt.s.w $f16, $f4
  mtc1  $at, $f10
  nop   
  add.s $f16, $f16, $f10
.L7F000958:
  div.s $f8, $f6, $f16
  lw    $ra, 0x2c($sp)
  lui   $at, %hi(D_800309A4)
  ldc1  $f20, 0x18($sp)
  lw    $s0, 0x20($sp)
  lw    $s1, 0x24($sp)
  lw    $s2, 0x28($sp)
  addiu $sp, $sp, 0x40
  jr    $ra
   swc1  $f8, %lo(D_800309A4)($at)
");

void sub_GAME_7F000980(void) { sub_GAME_7F0009A0(); }

extern char dword_CODE_bss_80075DC8[20][160]; // TODO: This seems like an array
                                              // of 20 of these. Fix the other
                                              // files? (Aliasing violation)

void sub_GAME_7F0009A0(void) {
  unsigned int *end = &dword_CODE_bss_80075DC8[20];
  unsigned int *ptr = &dword_CODE_bss_80075DC8[0];
  while (end > ptr) {
    ptr[39] = 0;
    ptr += 0x28;
  }
}
