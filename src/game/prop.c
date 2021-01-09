int lastmpweaponnum;

const char aNochr[] = "-nochr", aNoprop[] = "-noprop", aNoobj[] = "-noobj",
           aNoprop_0[] = "-noprop";
const unsigned int only_read_by_stageload[64] = {0};
const char aMp_[] = "mp_";

asm(R"
glabel load_proptype
  addiu $sp, $sp, -0x28
  sw    $s0, 0x14($sp)
  lui   $s0, %hi(ptr_setup_objects)
  lw    $s0, %lo(ptr_setup_objects)($s0)
  sw    $s1, 0x18($sp)
  sw    $ra, 0x24($sp)
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  beqz  $s0, .L7F001BB4
   move  $s1, $zero
  lbu   $v1, 3($s0)
  li    $s3, 48
  andi  $s2, $a0, 0xff
  beql  $s3, $v1, .L7F001BB8
   lw    $ra, 0x24($sp)
.L7F001B8C:
  bne   $s2, $v1, .L7F001B98
   nop   
  addiu $s1, $s1, 1
.L7F001B98:
  jal   get_size_of_setup_object_type
   move  $a0, $s0
  sll   $t6, $v0, 2
  addu  $s0, $t6, $s0
  lbu   $v1, 3($s0)
  bne   $s3, $v1, .L7F001B8C
   nop   
.L7F001BB4:
  lw    $ra, 0x24($sp)
.L7F001BB8:
  move  $v0, $s1
  lw    $s1, 0x18($sp)
  lw    $s0, 0x14($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
glabel sub_GAME_7F001BD4
  addiu $sp, $sp, -0x48
  sw    $ra, 0x14($sp)
  lwc1  $f4, 0x2c($a0)
  swc1  $f4, 0x34($sp)
  lwc1  $f6, 0x30($a0)
  swc1  $f6, 0x30($sp)
  lwc1  $f10, 0x34($a0)
  swc1  $f10, 0x2c($sp)
  lwc1  $f8, 0x38($a0)
  swc1  $f8, 0x28($sp)
  lwc1  $f4, 0x3c($a0)
  swc1  $f4, 0x24($sp)
  lwc1  $f6, 0x40($a0)
  swc1  $f6, 0x20($sp)
  lwc1  $f10, 0x10($a0)
  lwc1  $f8, 0x20($a0)
  lwc1  $f6, 0x1c($a0)
  mul.s $f4, $f10, $f8
  lwc1  $f10, 0x14($a0)
  mul.s $f8, $f6, $f10
  sub.s $f6, $f4, $f8
  swc1  $f6, 0x3c($sp)
  lwc1  $f4, 0x18($a0)
  lwc1  $f10, 0x14($a0)
  mul.s $f8, $f10, $f4
  lwc1  $f4, 0xc($a0)
  lwc1  $f10, 0x20($a0)
  mul.s $f10, $f10, $f4
  sub.s $f4, $f8, $f10
  swc1  $f4, 0x40($sp)
  lwc1  $f10, 0x1c($a0)
  lwc1  $f8, 0xc($a0)
  mul.s $f8, $f8, $f10
  lwc1  $f10, 0x18($a0)
  swc1  $f6, 0x18($sp)
  lwc1  $f6, 0x10($a0)
  sw    $a1, 0x4c($sp)
  sw    $a0, 0x48($sp)
  mul.s $f10, $f10, $f6
  sub.s $f6, $f8, $f10
  lwc1  $f8, 0x18($sp)
  mul.s $f10, $f8, $f8
  swc1  $f6, 0x44($sp)
  mul.s $f8, $f4, $f4
  add.s $f4, $f10, $f8
  mul.s $f10, $f6, $f6
  jal   sqrtf
   add.s $f12, $f10, $f4
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f18
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  lwc1  $f6, 0x3c($sp)
  lwc1  $f4, 0x40($sp)
  div.s $f2, $f8, $f0
  lw    $a0, 0x48($sp)
  lw    $a1, 0x4c($sp)
  mul.s $f10, $f6, $f2
  lwc1  $f6, 0x44($sp)
  mul.s $f8, $f4, $f2
  swc1  $f10, 0x3c($sp)
  mul.s $f4, $f6, $f2
  lwc1  $f6, 0x20($sp)
  swc1  $f8, 0x40($sp)
  lwc1  $f8, 0x24($sp)
  add.s $f12, $f8, $f6
  swc1  $f4, 0x44($sp)
  lwc1  $f4, 0x34($sp)
  lwc1  $f8, 0x30($sp)
  lwc1  $f6, 0x2c($sp)
  add.s $f14, $f4, $f8
  lwc1  $f4, 0x28($sp)
  add.s $f16, $f6, $f4
  mul.s $f8, $f14, $f10
  lwc1  $f6, 0xc($a0)
  mul.s $f4, $f16, $f6
  lwc1  $f6, 0x18($a0)
  add.s $f10, $f8, $f4
  mul.s $f8, $f6, $f12
  add.s $f4, $f8, $f10
  lwc1  $f8, ($a0)
  mul.s $f6, $f4, $f18
  add.s $f10, $f6, $f8
  swc1  $f10, ($a1)
  lwc1  $f4, 0x40($sp)
  lwc1  $f8, 0x10($a0)
  mul.s $f6, $f14, $f4
  nop   
  mul.s $f10, $f16, $f8
  lwc1  $f8, 0x1c($a0)
  add.s $f4, $f6, $f10
  mul.s $f6, $f8, $f12
  add.s $f10, $f6, $f4
  lwc1  $f6, 4($a0)
  mul.s $f8, $f10, $f18
  add.s $f4, $f8, $f6
  swc1  $f4, 4($a1)
  lwc1  $f10, 0x44($sp)
  lwc1  $f6, 0x14($a0)
  mul.s $f8, $f14, $f10
  nop   
  mul.s $f4, $f16, $f6
  lwc1  $f6, 0x20($a0)
  add.s $f10, $f8, $f4
  mul.s $f8, $f6, $f12
  add.s $f4, $f8, $f10
  lwc1  $f8, 8($a0)
  mul.s $f6, $f4, $f18
  add.s $f10, $f6, $f8
  swc1  $f10, 8($a1)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x48
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_8004EEB4
.word 0x358637bd
.text
glabel prepare_load_objects
  addiu $sp, $sp, -0xf8
  sw    $ra, 0x34($sp)
  sw    $s1, 0x30($sp)
  sw    $s0, 0x2c($sp)
  sw    $a0, 0xf8($sp)
  sw    $a2, 0x100($sp)
  lh    $a0, 4($a1)
  move  $s1, $a1
  move  $s0, $zero
  jal   load_model
   sw    $a0, 0xf0($sp)
  lhu   $t6, ($s1)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t6, $f4
  bgez  $t6, .L7F001DE8
   cvt.s.w $f6, $f4
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F001DE8:
  li    $at, 0x3B800000 # 0.003906
  mtc1  $at, $f10
  li    $at, 0x47800000 # 65536.000000
  mul.s $f4, $f6, $f10
  mtc1  $at, $f10
  swc1  $f4, 0x78($sp)
  lw    $t7, 0x74($s1)
  mtc1  $t7, $f8
  nop   
  cvt.s.w $f6, $f8
  div.s $f4, $f6, $f10
  jal   getPlayerCount
   swc1  $f4, 0x74($s1)
  slti  $at, $v0, 2
  bnez  $at, .L7F001E90
   li    $v1, 1
  jal   get_scenario
   sw    $v1, 0x74($sp)
  li    $at, 2
  bne   $v0, $at, .L7F001E54
   lw    $v1, 0x74($sp)
  lh    $t8, 4($s1)
  li    $at, 333
  bne   $t8, $at, .L7F001E54
   nop   
  b     .L7F001E7C
   move  $v1, $zero
.L7F001E54:
  jal   get_scenario
   sw    $v1, 0x74($sp)
  li    $at, 3
  bne   $v0, $at, .L7F001E7C
   lw    $v1, 0x74($sp)
  lh    $t9, 4($s1)
  li    $at, 208
  bne   $t9, $at, .L7F001E7C
   nop   
  move  $v1, $zero
.L7F001E7C:
  beql  $v1, $zero, .L7F001E94
   lw    $v1, 8($s1)
  lbu   $t0, 2($s1)
  ori   $t1, $t0, 4
  sb    $t1, 2($s1)
.L7F001E90:
  lw    $v1, 8($s1)
.L7F001E94:
  andi  $t2, $v1, 0x8000
  beqz  $t2, .L7F001F20
   andi  $t8, $v1, 0x4000
  lbu   $t3, 3($s1)
  lw    $t6, 0xf0($sp)
  li    $at, 8
  bne   $t3, $at, .L7F001EE0
   sll   $t7, $t6, 2
  lw    $t4, 0xf0($sp)
  lui   $a1, %hi(PitemZ_entries)
  move  $a0, $s1
  sll   $t5, $t4, 2
  subu  $t5, $t5, $t4
  sll   $t5, $t5, 2
  addu  $a1, $a1, $t5
  jal   sub_GAME_7F051DD8
   lw    $a1, %lo(PitemZ_entries)($a1)
  b     .L7F001F00
   lw    $a0, 0x14($s1)
.L7F001EE0:
  subu  $t7, $t7, $t6
  sll   $t7, $t7, 2
  lui   $a1, %hi(PitemZ_entries)
  addu  $a1, $a1, $t7
  lw    $a1, %lo(PitemZ_entries)($a1)
  jal   sub_GAME_7F0406F8
   move  $a0, $s1
  lw    $a0, 0x14($s1)
.L7F001F00:
  lwc1  $f6, 0x78($sp)
  lwc1  $f8, 0x14($a0)
  mul.s $f10, $f8, $f6
  mfc1  $a1, $f10
  jal   set_obj_instance_controller_scale
   nop   
  b     .L7F002728
   lw    $ra, 0x34($sp)
.L7F001F20:
  beql  $t8, $zero, .L7F001FE8
   lh    $v1, 6($s1)
  jal   check_if_guardnum_loaded_get_ptr_GUARDdata
   lh    $a0, 6($s1)
  beqz  $v0, .L7F002724
   sw    $v0, 0x6c($sp)
  lw    $t9, 0x18($v0)
  beql  $t9, $zero, .L7F002728
   lw    $ra, 0x34($sp)
  lw    $t0, 0x1c($v0)
  beql  $t0, $zero, .L7F002728
   lw    $ra, 0x34($sp)
  lbu   $t1, 3($s1)
  lw    $t4, 0xf0($sp)
  li    $at, 8
  bne   $t1, $at, .L7F001F90
   sll   $t5, $t4, 2
  lw    $t2, 0xf0($sp)
  lui   $a1, %hi(PitemZ_entries)
  move  $a0, $s1
  sll   $t3, $t2, 2
  subu  $t3, $t3, $t2
  sll   $t3, $t3, 2
  addu  $a1, $a1, $t3
  jal   sub_GAME_7F051DD8
   lw    $a1, %lo(PitemZ_entries)($a1)
  b     .L7F001FB0
   move  $s0, $v0
.L7F001F90:
  subu  $t5, $t5, $t4
  sll   $t5, $t5, 2
  lui   $a1, %hi(PitemZ_entries)
  addu  $a1, $a1, $t5
  lw    $a1, %lo(PitemZ_entries)($a1)
  jal   sub_GAME_7F0406F8
   move  $a0, $s1
  move  $s0, $v0
.L7F001FB0:
  lw    $a0, 0x14($s1)
  lwc1  $f8, 0x78($sp)
  lwc1  $f4, 0x14($a0)
  mul.s $f6, $f4, $f8
  mfc1  $a1, $f6
  jal   set_obj_instance_controller_scale
   nop   
  lw    $t6, 0x6c($sp)
  move  $a0, $s0
  jal   sub_GAME_7F03A5A4
   lw    $a1, 0x18($t6)
  b     .L7F002728
   lw    $ra, 0x34($sp)
  lh    $v1, 6($s1)
.L7F001FE8:
  lui   $t8, %hi(ptr_0xxxpresets) 
  lui   $t3, %hi(ptr_2xxxpresets) 
  slti  $at, $v1, 0x2710
  beqz  $at, .L7F0020DC
   sll   $t2, $v1, 4
  sll   $t7, $v1, 2
  subu  $t7, $t7, $v1
  lw    $t8, %lo(ptr_0xxxpresets)($t8)
  sll   $t7, $t7, 2
  subu  $t7, $t7, $v1
  sll   $t7, $t7, 2
  addu  $v0, $t7, $t8
  lwc1  $f10, 0x18($v0)
  mtc1  $zero, $f0
  addiu $a0, $sp, 0x8c
  neg.s $f4, $f10
  mfc1  $a1, $f0
  swc1  $f4, 0x10($sp)
  lwc1  $f8, 0x1c($v0)
  mfc1  $a2, $f0
  mfc1  $a3, $f0
  neg.s $f6, $f8
  swc1  $f6, 0x14($sp)
  lwc1  $f10, 0x20($v0)
  neg.s $f4, $f10
  swc1  $f4, 0x18($sp)
  lwc1  $f8, 0xc($v0)
  swc1  $f8, 0x1c($sp)
  lwc1  $f6, 0x10($v0)
  swc1  $f6, 0x20($sp)
  lwc1  $f10, 0x14($v0)
  sw    $v0, 0x64($sp)
  jal   sub_GAME_7F059908
   swc1  $f10, 0x24($sp)
  lw    $v0, 0x64($sp)
  lwc1  $f4, ($v0)
  swc1  $f4, 0xd0($sp)
  lwc1  $f8, 4($v0)
  swc1  $f8, 0xd4($sp)
  lwc1  $f6, 8($v0)
  swc1  $f6, 0xd8($sp)
  lw    $t9, 8($s1)
  andi  $t0, $t9, 2
  beql  $t0, $zero, .L7F0020BC
   lwc1  $f6, ($v0)
  lwc1  $f10, ($v0)
  swc1  $f10, 0x80($sp)
  lwc1  $f4, 4($v0)
  swc1  $f4, 0x84($sp)
  lwc1  $f8, 8($v0)
  b     .L7F0020D0
   swc1  $f8, 0x88($sp)
  lwc1  $f6, ($v0)
.L7F0020BC:
  swc1  $f6, 0x80($sp)
  lwc1  $f10, 4($v0)
  swc1  $f10, 0x84($sp)
  lwc1  $f4, 8($v0)
  swc1  $f4, 0x88($sp)
.L7F0020D0:
  lw    $t1, 0x28($v0)
  b     .L7F0022EC
   sw    $t1, 0xcc($sp)
.L7F0020DC:
  lw    $t3, %lo(ptr_2xxxpresets)($t3)
  addu  $t2, $t2, $v1
  sll   $t2, $t2, 2
  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
  addu  $s0, $t2, $t3
  addu  $s0, $s0, $at
  lwc1  $f8, 0x18($s0)
  mtc1  $zero, $f0
  addiu $a0, $sp, 0x8c
  neg.s $f6, $f8
  mfc1  $a1, $f0
  swc1  $f6, 0x10($sp)
  lwc1  $f10, 0x1c($s0)
  mfc1  $a2, $f0
  mfc1  $a3, $f0
  neg.s $f4, $f10
  swc1  $f4, 0x14($sp)
  lwc1  $f8, 0x20($s0)
  neg.s $f6, $f8
  swc1  $f6, 0x18($sp)
  lwc1  $f10, 0xc($s0)
  swc1  $f10, 0x1c($sp)
  lwc1  $f4, 0x10($s0)
  swc1  $f4, 0x20($sp)
  lwc1  $f8, 0x14($s0)
  jal   sub_GAME_7F059908
   swc1  $f8, 0x24($sp)
  lw    $t4, 0xc($s1)
  move  $a0, $s0
  andi  $t5, $t4, 1
  bnezl $t5, .L7F002250
   lwc1  $f10, ($s0)
  jal   sub_GAME_7F001BD4
   addiu $a1, $sp, 0xd0
  lwc1  $f6, 0x34($s0)
  lwc1  $f10, 0x38($s0)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f0
  sub.s $f4, $f6, $f10
  lwc1  $f6, 0xc($s0)
  addiu $a0, $sp, 0xcc
  mul.s $f8, $f4, $f0
  lwc1  $f4, 0xd0($sp)
  mfc1  $a3, $f4
  mul.s $f10, $f6, $f8
  add.s $f6, $f10, $f4
  swc1  $f6, 0x80($sp)
  lwc1  $f10, 0x38($s0)
  lwc1  $f8, 0x34($s0)
  sub.s $f6, $f8, $f10
  lwc1  $f10, 0x10($s0)
  mul.s $f8, $f6, $f0
  nop   
  mul.s $f6, $f10, $f8
  lwc1  $f10, 0xd4($sp)
  add.s $f8, $f6, $f10
  swc1  $f8, 0x84($sp)
  lwc1  $f10, 0x38($s0)
  lwc1  $f6, 0x34($s0)
  sub.s $f8, $f6, $f10
  lwc1  $f10, 0x14($s0)
  mul.s $f6, $f8, $f0
  nop   
  mul.s $f8, $f10, $f6
  lwc1  $f10, 0xd8($sp)
  add.s $f6, $f8, $f10
  swc1  $f6, 0x88($sp)
  lw    $t6, 0x28($s0)
  sw    $t6, 0xcc($sp)
  lw    $a2, 8($s0)
  lw    $a1, ($s0)
  jal   sub_GAME_7F0B0BE4
   swc1  $f10, 0x10($sp)
  bnezl $v0, .L7F0022F0
   addiu $t1, $sp, 0xdc
  lwc1  $f8, ($s0)
  swc1  $f8, 0xd0($sp)
  lwc1  $f6, 4($s0)
  swc1  $f6, 0xd4($sp)
  lwc1  $f4, 8($s0)
  swc1  $f4, 0xd8($sp)
  lw    $t7, 0x28($s0)
  sw    $t7, 0xcc($sp)
  lw    $v1, 8($s1)
  andi  $t8, $v1, 2
  bnez  $t8, .L7F0022EC
   andi  $t9, $v1, 0x1000
  bnezl $t9, .L7F0022F0
   addiu $t1, $sp, 0xdc
  b     .L7F0022F0
   addiu $t1, $sp, 0xdc
  lwc1  $f10, ($s0)
.L7F002250:
  move  $a0, $s0
  addiu $a1, $sp, 0x80
  swc1  $f10, 0xd0($sp)
  lwc1  $f8, 4($s0)
  swc1  $f8, 0xd4($sp)
  lwc1  $f6, 8($s0)
  swc1  $f6, 0xd8($sp)
  lw    $t0, 0x28($s0)
  jal   sub_GAME_7F001BD4
   sw    $t0, 0xcc($sp)
  lwc1  $f4, 0x34($s0)
  lwc1  $f10, 0x38($s0)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f0
  sub.s $f8, $f4, $f10
  lwc1  $f4, 0xc($s0)
  mul.s $f6, $f8, $f0
  lwc1  $f8, 0x80($sp)
  mul.s $f10, $f6, $f4
  add.s $f6, $f8, $f10
  swc1  $f6, 0x80($sp)
  lwc1  $f8, 0x38($s0)
  lwc1  $f4, 0x34($s0)
  sub.s $f10, $f4, $f8
  lwc1  $f4, 0x10($s0)
  mul.s $f6, $f10, $f0
  lwc1  $f10, 0x84($sp)
  mul.s $f8, $f6, $f4
  add.s $f6, $f10, $f8
  swc1  $f6, 0x84($sp)
  lwc1  $f10, 0x38($s0)
  lwc1  $f4, 0x34($s0)
  sub.s $f8, $f4, $f10
  lwc1  $f4, 0x14($s0)
  mul.s $f6, $f8, $f0
  lwc1  $f8, 0x88($sp)
  mul.s $f10, $f6, $f4
  add.s $f6, $f8, $f10
  swc1  $f6, 0x88($sp)
.L7F0022EC:
  addiu $t1, $sp, 0xdc
.L7F0022F0:
  sw    $t1, 0x10($sp)
  addiu $a0, $sp, 0xd0
  lw    $a1, 0xcc($sp)
  li    $a2, 0
  jal   sub_GAME_7F056850
   addiu $a3, $sp, 0xe0
  beql  $v0, $zero, .L7F002728
   lw    $ra, 0x34($sp)
  lbu   $t2, 3($s1)
  lw    $t3, 0xf0($sp)
  li    $at, 8
  bne   $t2, $at, .L7F002348
   sll   $t4, $t3, 2
  subu  $t4, $t4, $t3
  sll   $t4, $t4, 2
  lui   $a1, %hi(PitemZ_entries)
  addu  $a1, $a1, $t4
  lw    $a1, %lo(PitemZ_entries)($a1)
  jal   sub_GAME_7F051DD8
   move  $a0, $s1
  b     .L7F002354
   sw    $v0, 0x60($sp)
.L7F002348:
  jal   sub_GAME_7F04071C
   move  $a0, $s1
  sw    $v0, 0x60($sp)
.L7F002354:
  beql  $s0, $zero, .L7F002698
   lw    $a0, 0x14($s1)
  jal   sub_GAME_7F040078
   move  $a0, $s1
  beqz  $v0, .L7F002694
   li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f18
  addiu $a1, $sp, 0x8c
  swc1  $f18, 0x58($sp)
  lw    $v1, 8($s1)
  mov.s $f16, $f18
  andi  $t5, $v1, 0x30
  beqz  $t5, .L7F0023FC
   andi  $t9, $v1, 0x50
  lwc1  $f2, 4($v0)
  lwc1  $f0, 8($v0)
  andi  $t6, $v1, 2
  c.lt.s $f2, $f0
  nop   
  bc1f  .L7F0023FC
   nop   
  beql  $t6, $zero, .L7F0023DC
   lwc1  $f4, 0x30($s0)
  lwc1  $f4, 0x30($s0)
  lwc1  $f8, 0x2c($s0)
  lw    $t7, 0x14($s1)
  sub.s $f6, $f0, $f2
  sub.s $f10, $f4, $f8
  lwc1  $f4, 0x14($t7)
  mul.s $f8, $f6, $f4
  div.s $f6, $f10, $f8
  b     .L7F0023FC
   swc1  $f6, 0x58($sp)
  lwc1  $f4, 0x30($s0)
.L7F0023DC:
  lwc1  $f10, 0x2c($s0)
  lw    $t8, 0x14($s1)
  sub.s $f6, $f0, $f2
  sub.s $f8, $f4, $f10
  lwc1  $f4, 0x14($t8)
  mul.s $f10, $f6, $f4
  div.s $f6, $f8, $f10
  swc1  $f6, 0x58($sp)
.L7F0023FC:
  beqz  $t9, .L7F002460
   andi  $t2, $v1, 0x90
  lwc1  $f2, 0xc($v0)
  lwc1  $f0, 0x10($v0)
  c.lt.s $f2, $f0
  nop   
  bc1f  .L7F002460
   nop   
  lw    $t0, 0x14($s1)
  andi  $t1, $v1, 2
  beqz  $t1, .L7F002448
   lwc1  $f12, 0x14($t0)
  sub.s $f6, $f0, $f2
  lwc1  $f4, 0x40($s0)
  lwc1  $f8, 0x3c($s0)
  sub.s $f10, $f4, $f8
  mul.s $f4, $f6, $f12
  b     .L7F002460
   div.s $f18, $f10, $f4
.L7F002448:
  sub.s $f4, $f0, $f2
  lwc1  $f8, 0x38($s0)
  lwc1  $f6, 0x34($s0)
  sub.s $f10, $f8, $f6
  mul.s $f8, $f4, $f12
  div.s $f16, $f10, $f8
.L7F002460:
  beqz  $t2, .L7F0024C4
   andi  $t5, $v1, 0x10
  lwc1  $f2, 0x14($v0)
  lwc1  $f0, 0x18($v0)
  c.lt.s $f2, $f0
  nop   
  bc1fl .L7F0024C8
   lwc1  $f0, 0x58($sp)
  lw    $t3, 0x14($s1)
  andi  $t4, $v1, 2
  beqz  $t4, .L7F0024AC
   lwc1  $f12, 0x14($t3)
  sub.s $f8, $f0, $f2
  lwc1  $f6, 0x38($s0)
  lwc1  $f4, 0x34($s0)
  sub.s $f10, $f6, $f4
  mul.s $f6, $f8, $f12
  b     .L7F0024C4
   div.s $f16, $f10, $f6
.L7F0024AC:
  sub.s $f6, $f0, $f2
  lwc1  $f4, 0x40($s0)
  lwc1  $f8, 0x3c($s0)
  sub.s $f10, $f4, $f8
  mul.s $f4, $f6, $f12
  div.s $f18, $f10, $f4
.L7F0024C4:
  lwc1  $f0, 0x58($sp)
.L7F0024C8:
  lwc1  $f12, 0x58($sp)
  c.lt.s $f16, $f0
  nop   
  bc1fl .L7F0024E4
   c.lt.s $f18, $f0
  mov.s $f0, $f16
  c.lt.s $f18, $f0
.L7F0024E4:
  nop   
  bc1fl .L7F0024F8
   c.lt.s $f12, $f16
  mov.s $f0, $f18
  c.lt.s $f12, $f16
.L7F0024F8:
  mov.s $f14, $f12
  andi  $t6, $v1, 0x20
  andi  $t8, $v1, 0x40
  bc1fl .L7F002514
   c.lt.s $f14, $f18
  mov.s $f14, $f16
  c.lt.s $f14, $f18
.L7F002514:
  andi  $t0, $v1, 0x80
  bc1f  .L7F002524
   nop   
  mov.s $f14, $f18
.L7F002524:
  beqz  $t5, .L7F00253C
   nop   
  mov.s $f18, $f0
  mov.s $f16, $f0
  b     .L7F0025FC
   mov.s $f12, $f0
.L7F00253C:
  bnez  $t6, .L7F00257C
   andi  $t7, $v1, 2
  lwc1  $f0, 8($v0)
  beqz  $t7, .L7F002568
   lwc1  $f2, 4($v0)
  c.eq.s $f2, $f0
  nop   
  bc1f  .L7F00257C
   nop   
  b     .L7F00257C
   mov.s $f12, $f14
.L7F002568:
  c.eq.s $f2, $f0
  nop   
  bc1f  .L7F00257C
   nop   
  mov.s $f12, $f14
.L7F00257C:
  bnez  $t8, .L7F0025BC
   andi  $t9, $v1, 2
  lwc1  $f0, 0x10($v0)
  beqz  $t9, .L7F0025A8
   lwc1  $f2, 0xc($v0)
  c.eq.s $f2, $f0
  nop   
  bc1f  .L7F0025BC
   nop   
  b     .L7F0025BC
   mov.s $f18, $f14
.L7F0025A8:
  c.eq.s $f2, $f0
  nop   
  bc1f  .L7F0025BC
   nop   
  mov.s $f16, $f14
.L7F0025BC:
  bnez  $t0, .L7F0025FC
   andi  $t1, $v1, 2
  lwc1  $f0, 0x18($v0)
  beqz  $t1, .L7F0025E8
   lwc1  $f2, 0x14($v0)
  c.eq.s $f2, $f0
  nop   
  bc1fl .L7F002600
   div.s $f12, $f12, $f14
  b     .L7F0025FC
   mov.s $f16, $f14
.L7F0025E8:
  c.eq.s $f2, $f0
  nop   
  bc1fl .L7F002600
   div.s $f12, $f12, $f14
  mov.s $f18, $f14
.L7F0025FC:
  div.s $f12, $f12, $f14
.L7F002600:
  lui    $at, %hi(D_8004EEB4)
  lwc1  $f0, %lo(D_8004EEB4)($at)
  li    $at, 0x3F800000 # 1.000000
  div.s $f16, $f16, $f14
  c.le.s $f12, $f0
  nop   
  bc1t  .L7F002640
   div.s $f18, $f18, $f14
  c.le.s $f16, $f0
  nop   
  bc1tl .L7F002644
   mtc1  $at, $f12
  c.le.s $f18, $f0
  nop   
  bc1fl .L7F002654
   swc1  $f14, 0x48($sp)
.L7F002640:
  mtc1  $at, $f12
.L7F002644:
  nop   
  mov.s $f18, $f12
  mov.s $f16, $f12
  swc1  $f14, 0x48($sp)
.L7F002654:
  swc1  $f16, 0x54($sp)
  jal   sub_GAME_7F0589B4
   swc1  $f18, 0x50($sp)
  lwc1  $f12, 0x54($sp)
  jal   sub_GAME_7F0589E4
   addiu $a1, $sp, 0x8c
  lwc1  $f12, 0x50($sp)
  jal   sub_GAME_7F058A4C
   addiu $a1, $sp, 0x8c
  lw    $a0, 0x14($s1)
  lwc1  $f14, 0x48($sp)
  lwc1  $f6, 0x14($a0)
  mul.s $f10, $f6, $f14
  mfc1  $a1, $f10
  jal   set_obj_instance_controller_scale
   nop   
.L7F002694:
  lw    $a0, 0x14($s1)
.L7F002698:
  lwc1  $f8, 0x78($sp)
  lwc1  $f4, 0x14($a0)
  mul.s $f6, $f4, $f8
  mfc1  $a1, $f6
  jal   set_obj_instance_controller_scale
   nop   
  lw    $t2, 0x14($s1)
  addiu $a1, $sp, 0x8c
  jal   matrix_multiply_A1_by_F12
   lwc1  $f12, 0x14($t2)
  lw    $t3, 8($s1)
  move  $a0, $s1
  addiu $a1, $sp, 0xe0
  andi  $t4, $t3, 2
  beqz  $t4, .L7F0026FC
   addiu $a2, $sp, 0x8c
  addiu $t5, $sp, 0x80
  sw    $t5, 0x10($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xe0
  addiu $a2, $sp, 0x8c
  jal   sub_GAME_7F040BA0
   lw    $a3, 0xdc($sp)
  b     .L7F00270C
   nop   
.L7F0026FC:
  addiu $t6, $sp, 0x80
  sw    $t6, 0x10($sp)
  jal   sub_GAME_7F04088C
   lw    $a3, 0xdc($sp)
.L7F00270C:
  jal   sub_GAME_7F056CA0
   move  $a0, $s1
  jal   set_current_objposdata_plus_0x28
   lw    $a0, 0x60($sp)
  jal   set_stateflag_0x04_for_posdata
   lw    $a0, 0x60($sp)
.L7F002724:
  lw    $ra, 0x34($sp)
.L7F002728:
  lw    $s0, 0x2c($sp)
  lw    $s1, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0xf8
");

asm(R"
.late_rodata
glabel jpt_8004EEB8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027E0
.word .L7F0027E0
.word .L7F0027E0
.word .L7F0027E0
.word .L7F0027E0
.word .L7F0027C8
.word .L7F0027C8
.word .L7F0027C8
glabel jpt_mp_ammo_crate_expansion
.word .L7F002870
.word .L7F002870
.word .L7F002870
.word .L7F002870
.word .L7F002870
.word .L7F002870
.word .L7F002870
.word .L7F002870
.text
glabel expand_08_obj_set_guard_MP_weapons
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  sw    $a0, 0x28($sp)
  sw    $a2, 0x30($sp)
  lw    $t6, 8($a1)
  move  $a3, $a1
  andi  $t7, $t6, 0x4000
  beql  $t7, $zero, .L7F002804
   li    $a1, 1
  lh    $a0, 6($a1)
  jal   check_if_guardnum_loaded_get_ptr_GUARDdata
   sw    $a1, 0x2c($sp)
  lw    $a3, 0x2c($sp)
  beqz  $v0, .L7F002998
   sw    $v0, 0x1c($sp)
  lw    $t8, 0x18($v0)
  beql  $t8, $zero, .L7F00299C
   lw    $ra, 0x14($sp)
  lw    $t9, 0x1c($v0)
  li    $a0, 28
  beql  $t9, $zero, .L7F00299C
   lw    $ra, 0x14($sp)
  jal   cheatCheckIfOn
   sw    $a3, 0x2c($sp)
  beqz  $v0, .L7F0027E0
   lw    $a3, 0x2c($sp)
  lb    $t0, 0x80($a3)
  addiu $t1, $t0, -2
  sltiu $at, $t1, 0x1e
  beqz  $at, .L7F0027E0
   sll   $t1, $t1, 2
  lui   $at, %hi(jpt_8004EEB8)
  addu  $at, $at, $t1
  lw    $t1, %lo(jpt_8004EEB8)($at)
  jr    $t1
   nop   
.L7F0027C8:
  li    $t2, 25
  li    $t3, 211
  li    $t4, 256
  sb    $t2, 0x80($a3)
  sh    $t3, 4($a3)
  sh    $t4, ($a3)
.L7F0027E0:
  lb    $a0, 0x80($a3)
  jal   set_weapon_model_generated_thrown_object
   sw    $a3, 0x2c($sp)
  lw    $a0, 0x2c($sp)
  jal   sub_GAME_7F052030
   lw    $a1, 0x1c($sp)
  b     .L7F00299C
   lw    $ra, 0x14($sp)
  li    $a1, 1
.L7F002804:
  sw    $a1, 0x18($sp)
  jal   getPlayerCount
   sw    $a3, 0x2c($sp)
  slti  $at, $v0, 2
  lw    $a1, 0x18($sp)
  bnez  $at, .L7F00296C
   lw    $a3, 0x2c($sp)
  li    $t5, -1
  lui   $at, %hi(lastmpweaponnum)
  sw    $t5, %lo(lastmpweaponnum)($at)
  lbu   $v0, 0x80($a3)
  slti  $at, $v0, 0x59
  bnez  $at, .L7F00285C
   addiu $t6, $v0, -0xf0
  sltiu $at, $t6, 8
  beqz  $at, .L7F00296C
   sll   $t6, $t6, 2
  lui   $at, %hi(jpt_mp_ammo_crate_expansion)
  addu  $at, $at, $t6
  lw    $t6, %lo(jpt_mp_ammo_crate_expansion)($at)
  jr    $t6
   nop   
.L7F00285C:
  li    $at, 88
  beql  $v0, $at, .L7F002950
   sw    $a1, 0x18($sp)
  b     .L7F002970
   lb    $a0, 0x80($a3)
.L7F002870:
  jal   get_ptr_mp_weapon_set_data
   sw    $a3, 0x2c($sp)
  lw    $a3, 0x2c($sp)
  lui   $at, %hi(lastmpweaponnum)
  li    $t1, 1
  lbu   $a0, 0x80($a3)
  addiu $a0, $a0, -0xf0
  sll   $t7, $a0, 2
  subu  $t7, $t7, $a0
  sll   $t7, $t7, 3
  sw    $a0, %lo(lastmpweaponnum)($at)
  addu  $v1, $v0, $t7
  lw    $t8, ($v1)
  li    $at, 0x43800000 # 256.000000
  mtc1  $at, $f6
  sb    $t8, 0x80($a3)
  lw    $t9, 4($v1)
  li    $at, 0x4F000000 # 2147483648.000000
  sh    $t9, 4($a3)
  lwc1  $f4, 8($v1)
  mul.s $f8, $f4, $f6
  cfc1  $t0, $31
  ctc1  $t1, $31
  nop   
  cvt.w.s $f10, $f8
  cfc1  $t1, $31
  nop   
  andi  $t1, $t1, 0x78
  beql  $t1, $zero, .L7F002930
   mfc1  $t1, $f10
  mtc1  $at, $f10
  li    $t1, 1
  sub.s $f10, $f8, $f10
  ctc1  $t1, $31
  nop   
  cvt.w.s $f10, $f10
  cfc1  $t1, $31
  nop   
  andi  $t1, $t1, 0x78
  bnez  $t1, .L7F002924
   nop   
  mfc1  $t1, $f10
  lui   $at, 0x8000
  b     .L7F00293C
   or    $t1, $t1, $at
.L7F002924:
  b     .L7F00293C
   li    $t1, -1
  mfc1  $t1, $f10
.L7F002930:
  nop   
  bltz  $t1, .L7F002924
   nop   
.L7F00293C:
  ctc1  $t0, $31
  sh    $t1, ($a3)
  b     .L7F00296C
   lw    $a1, 0x14($v1)
  sw    $a1, 0x18($sp)
.L7F002950:
  jal   get_scenario
   sw    $a3, 0x2c($sp)
  li    $at, 2
  lw    $a1, 0x18($sp)
  beq   $v0, $at, .L7F00296C
   lw    $a3, 0x2c($sp)
  move  $a1, $zero
def_7F002854:
.L7F00296C:
  lb    $a0, 0x80($a3)
.L7F002970:
  beql  $a0, $zero, .L7F00299C
   lw    $ra, 0x14($sp)
  beql  $a1, $zero, .L7F00299C
   lw    $ra, 0x14($sp)
  jal   set_weapon_model_generated_thrown_object
   sw    $a3, 0x2c($sp)
  lw    $a1, 0x2c($sp)
  lw    $a0, 0x28($sp)
  jal   prepare_load_objects
   lw    $a2, 0x30($sp)
.L7F002998:
  lw    $ra, 0x14($sp)
.L7F00299C:
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel MP_weapon_expansion_routine
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lw    $t6, 8($a1)
  move  $a3, $a1
  andi  $t7, $t6, 0x4000
  beqz  $t7, .L7F002A04
   nop   
  lh    $a0, 6($a1)
  jal   check_if_guardnum_loaded_get_ptr_GUARDdata
   sw    $a1, 0x1c($sp)
  lw    $a3, 0x1c($sp)
  beqz  $v0, .L7F002A0C
   move  $a1, $v0
  lw    $t8, 0x18($v0)
  beql  $t8, $zero, .L7F002A10
   lw    $ra, 0x14($sp)
  lw    $t9, 0x1c($v0)
  beql  $t9, $zero, .L7F002A10
   lw    $ra, 0x14($sp)
  jal   sub_GAME_7F051084
   move  $a0, $a3
  b     .L7F002A10
   lw    $ra, 0x14($sp)
.L7F002A04:
  jal   prepare_load_objects
   move  $a1, $a3
.L7F002A0C:
  lw    $ra, 0x14($sp)
.L7F002A10:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

void jmp_prepare_load_objects(void) { prepare_load_objects(); }

asm(R"
.late_rodata
glabel D_8004EF50
.word 0x40c90fdb
glabel D_8004EF54
.word 0x40c90fdb
glabel D_8004EF58
.word 0x3ebba866
glabel D_8004EF5C
.word 0x3fc90fdb
glabel D_8004EF60
.word 0x3fc90fdb
glabel D_8004EF64
.word 0x358637bd

.text
glabel sub_GAME_7F002A3C
  addiu $sp, $sp, -0x58
  sw    $ra, 0x34($sp)
  sw    $s0, 0x30($sp)
  jal   prepare_load_objects
   move  $s0, $a1
  lw    $v0, 0x80($s0)
  bltzl $v0, .L7F002C48
   lw    $ra, 0x34($sp)
  lw    $t6, 0x14($s0)
  sll   $t2, $v0, 4
  slti  $at, $v0, 0x2710
  lw    $t7, 8($t6)
  sll   $t0, $v0, 2
  addu  $t2, $t2, $v0
  lw    $t8, 8($t7)
  subu  $t0, $t0, $v0
  sll   $t2, $t2, 2
  lw    $t9, ($t8)
  lui   $t3, %hi(ptr_2xxxpresets) 
  beqz  $at, .L7F002AAC
   lw    $a2, 4($t9)
  sll   $t0, $t0, 2
  lui   $t1, %hi(ptr_0xxxpresets) 
  lw    $t1, %lo(ptr_0xxxpresets)($t1)
  subu  $t0, $t0, $v0
  sll   $t0, $t0, 2
  b     .L7F002AC0
   addu  $v1, $t0, $t1
.L7F002AAC:
  lw    $t3, %lo(ptr_2xxxpresets)($t3)
  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
  addu  $v1, $t2, $t3
  addu  $v1, $v1, $at
.L7F002AC0:
  lwc1  $f4, ($a2)
  addiu $a0, $s0, 0x18
  addiu $a1, $sp, 0x44
  swc1  $f4, 0x44($sp)
  lwc1  $f6, 4($a2)
  swc1  $f6, 0x48($sp)
  lwc1  $f8, 8($a2)
  sw    $v1, 0x50($sp)
  jal   sub_GAME_7F0583D8
   swc1  $f8, 0x4c($sp)
  lw    $t4, 0x10($s0)
  lwc1  $f10, 0x44($sp)
  lwc1  $f4, 0x48($sp)
  lwc1  $f16, 8($t4)
  lw    $v1, 0x50($sp)
  mtc1  $zero, $f0
  add.s $f18, $f10, $f16
  lwc1  $f10, 0x4c($sp)
  li    $at, 0x3F800000 # 1.000000
  addiu $a0, $s0, 0x84
  swc1  $f18, 0x44($sp)
  lw    $t5, 0x10($s0)
  mfc1  $a1, $f0
  mfc1  $a2, $f0
  lwc1  $f6, 0xc($t5)
  mfc1  $a3, $f0
  add.s $f8, $f4, $f6
  swc1  $f8, 0x48($sp)
  lw    $t6, 0x10($s0)
  lwc1  $f16, 0x10($t6)
  add.s $f4, $f10, $f16
  swc1  $f4, 0x4c($sp)
  lwc1  $f6, ($v1)
  sub.s $f10, $f18, $f6
  swc1  $f10, 0x10($sp)
  lwc1  $f16, 4($v1)
  sub.s $f18, $f8, $f16
  mtc1  $at, $f8
  swc1  $f18, 0x14($sp)
  lwc1  $f6, 8($v1)
  sw    $a0, 0x3c($sp)
  swc1  $f0, 0x24($sp)
  sub.s $f10, $f4, $f6
  swc1  $f0, 0x1c($sp)
  swc1  $f8, 0x20($sp)
  jal   sub_GAME_7F059908
   swc1  $f10, 0x18($sp)
  lw    $t7, 0x14($s0)
  lw    $a1, 0x3c($sp)
  jal   matrix_multiply_A1_by_F12
   lwc1  $f12, 0x14($t7)
  lw    $t8, 0xe4($s0)
  mtc1  $zero, $f0
  lw    $v1, 0x50($sp)
  bnezl $t8, .L7F002C14
   lwc1  $f4, 0xcc($s0)
  lw    $t0, 0xcc($s0)
  lui   $at, %hi(D_8004EF50)
  lwc1  $f2, %lo(D_8004EF50)($at)
  mtc1  $t0, $f16
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f12
  cvt.s.w $f18, $f16
  lw    $t1, 0xd0($s0)
  lw    $t2, 0xdc($s0)
  lw    $t3, 0xe8($s0)
  mtc1  $t1, $f10
  li    $t9, 1
  mul.s $f4, $f18, $f2
  sw    $t9, 0xe4($s0)
  cvt.s.w $f8, $f10
  div.s $f6, $f4, $f12
  mtc1  $t2, $f4
  mul.s $f16, $f8, $f2
  div.s $f18, $f16, $f12
  swc1  $f6, 0xcc($s0)
  mtc1  $t3, $f16
  cvt.s.w $f6, $f4
  mul.s $f10, $f6, $f2
  swc1  $f18, 0xd0($s0)
  cvt.s.w $f18, $f16
  div.s $f8, $f10, $f12
  swc1  $f18, 0xe8($s0)
  swc1  $f8, 0xdc($s0)
  lwc1  $f4, 0xcc($s0)
.L7F002C14:
  sw    $zero, 0xd4($s0)
  swc1  $f0, 0xd8($s0)
  swc1  $f4, 0xc8($s0)
  lwc1  $f16, 8($v1)
  lwc1  $f8, 0x4c($sp)
  lwc1  $f10, ($v1)
  lwc1  $f6, 0x44($sp)
  sub.s $f14, $f8, $f16
  jal   convert_angle_using_inverse
   sub.s $f12, $f6, $f10
  swc1  $f0, 0xc4($s0)
  sw    $zero, 0xe0($s0)
  lw    $ra, 0x34($sp)
.L7F002C48:
  lw    $s0, 0x30($sp)
  addiu $sp, $sp, 0x58
  jr    $ra
   nop   
");

asm(R"
glabel expand_type_0D_object_autoturret
  addiu $sp, $sp, -0x38
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  jal   prepare_load_objects
   move  $s0, $a1
  lw    $t6, 0xa4($s0)
  lw    $t7, 0xa8($s0)
  li    $at, 0x47800000 # 65536.000000
  mtc1  $t6, $f4
  mtc1  $at, $f2
  lui   $at, %hi(D_8004EF54)
  cvt.s.w $f6, $f4
  lwc1  $f12, %lo(D_8004EF54)($at)
  mtc1  $t7, $f16
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f4
  cvt.s.w $f18, $f16
  mul.s $f8, $f6, $f12
  lw    $t8, 0x88($s0)
  lw    $t9, 0x8c($s0)
  mtc1  $zero, $f0
  li    $v1, -1
  mul.s $f6, $f18, $f4
  sw    $zero, 0xac($s0)
  sw    $v1, 0xb8($s0)
  sw    $v1, 0xbc($s0)
  sw    $v1, 0xc0($s0)
  sw    $zero, 0xc4($s0)
  div.s $f10, $f8, $f2
  sw    $zero, 0xc8($s0)
  li    $a0, 48
  li    $a1, 4
  swc1  $f0, 0x90($s0)
  swc1  $f0, 0x94($s0)
  swc1  $f0, 0x84($s0)
  swc1  $f0, 0x9c($s0)
  swc1  $f0, 0xa0($s0)
  swc1  $f0, 0x98($s0)
  swc1  $f0, 0xb0($s0)
  swc1  $f0, 0xb4($s0)
  div.s $f8, $f6, $f2
  swc1  $f10, 0xa4($s0)
  mtc1  $t8, $f10
  mtc1  $t9, $f6
  cvt.s.w $f16, $f10
  mul.s $f18, $f16, $f12
  swc1  $f8, 0xa8($s0)
  cvt.s.w $f8, $f6
  div.s $f4, $f18, $f2
  mul.s $f10, $f8, $f12
  div.s $f16, $f10, $f2
  swc1  $f4, 0x88($s0)
  jal   mempAllocBytesInBank
   swc1  $f16, 0x8c($s0)
  li    $v1, -1
  sw    $v0, 0xcc($s0)
  sb    $v1, ($v0)
  lw    $a0, 0x80($s0)
  mtc1  $zero, $f0
  sw    $zero, 0xd0($s0)
  bltz  $a0, .L7F002E08
   swc1  $f0, 0xd4($s0)
  slti  $at, $a0, 0x2710
  beqz  $at, .L7F002D80
   sll   $t2, $a0, 4
  sll   $t0, $a0, 2
  subu  $t0, $t0, $a0
  sll   $t0, $t0, 2
  lui   $t1, %hi(ptr_0xxxpresets) 
  lw    $t1, %lo(ptr_0xxxpresets)($t1)
  subu  $t0, $t0, $a0
  sll   $t0, $t0, 2
  b     .L7F002DA0
   addu  $v1, $t0, $t1
.L7F002D80:
  lui   $t3, %hi(ptr_2xxxpresets) 
  lw    $t3, %lo(ptr_2xxxpresets)($t3)
  addu  $t2, $t2, $a0
  sll   $t2, $t2, 2
  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
  addu  $v1, $t2, $t3
  addu  $v1, $v1, $at
.L7F002DA0:
  lw    $v0, 0x10($s0)
  lwc1  $f6, 4($v1)
  lwc1  $f18, ($v1)
  lwc1  $f8, 0xc($v0)
  lwc1  $f4, 8($v0)
  sub.s $f10, $f6, $f8
  sub.s $f12, $f18, $f4
  swc1  $f10, 0x28($sp)
  lwc1  $f16, 8($v1)
  lwc1  $f18, 0x10($v0)
  swc1  $f12, 0x2c($sp)
  sub.s $f14, $f16, $f18
  jal   convert_angle_using_inverse
   swc1  $f14, 0x24($sp)
  lwc1  $f2, 0x2c($sp)
  lwc1  $f14, 0x24($sp)
  swc1  $f0, 0x84($s0)
  mul.s $f4, $f2, $f2
  nop   
  mul.s $f6, $f14, $f14
  jal   sqrtf
   add.s $f12, $f4, $f6
  lwc1  $f12, 0x28($sp)
  jal   convert_angle_using_inverse
   mov.s $f14, $f0
  swc1  $f0, 0x98($s0)
.L7F002E08:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   
");

void jmp_prepare_load_objects_0(void) { prepare_load_objects(); }

asm(R"
glabel sub_GAME_7F002E3C
  addiu $sp, $sp, -0x38
  sw    $a0, 0x38($sp)
  lui   $t6, %hi(dword_CODE_bss_80075B98) 
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  addiu $t6, %lo(dword_CODE_bss_80075B98) # addiu $t6, $t6, 0x5b98
  addiu $a0, $a1, 0x80
  move  $s0, $a1
  move  $s1, $a2
  sw    $ra, 0x1c($sp)
  move  $t0, $a0
  addiu $t9, $t6, 0x6c
.L7F002E6C:
  lw    $at, ($t6)
  addiu $t6, $t6, 0xc
  addiu $t0, $t0, 0xc
  sw    $at, -0xc($t0)
  lw    $at, -8($t6)
  sw    $at, -8($t0)
  lw    $at, -4($t6)
  bne   $t6, $t9, .L7F002E6C
   sw    $at, -4($t0)
  lw    $at, ($t6)
  sw    $at, ($t0)
  lw    $t9, 4($t6)
  sw    $t9, 4($t0)
  jal   set_ptr_monitor_img_to_obj_ani_slot
   lw    $a1, 0xfc($s0)
  lh    $t1, 6($s0)
  lw    $a0, 0x38($sp)
  move  $a1, $s0
  bgez  $t1, .L7F00308C
   nop   
  lw    $t2, 8($s0)
  andi  $t3, $t2, 0x8000
  bnez  $t3, .L7F00308C
   nop   
  lh    $t4, 4($s0)
  sw    $t4, 0x2c($sp)
  lw    $t5, 0xf4($s0)
  jal   sub_GAME_7F056A88
   addu  $a0, $t5, $s1
  move  $s1, $v0
  jal   load_model
   lw    $a0, 0x2c($sp)
  lhu   $t8, ($s0)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t8, $f4
  bgez  $t8, .L7F002F0C
   cvt.s.w $f6, $f4
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F002F0C:
  li    $at, 0x3B800000 # 0.003906
  mtc1  $at, $f10
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f8
  mul.s $f16, $f6, $f10
  swc1  $f16, 0x20($sp)
  lw    $t7, 0x74($s0)
  mtc1  $t7, $f18
  nop   
  cvt.s.w $f4, $f18
  div.s $f6, $f4, $f8
  jal   getPlayerCount
   swc1  $f6, 0x74($s0)
  slti  $at, $v0, 2
  bnez  $at, .L7F002F58
   nop   
  lbu   $t9, 2($s0)
  ori   $t6, $t9, 4
  sb    $t6, 2($s0)
.L7F002F58:
  jal   sub_GAME_7F04071C
   move  $a0, $s0
  jal   sub_GAME_7F03FE98
   sw    $v0, 0x24($sp)
  sw    $v0, 0x6c($s0)
  lw    $t0, 0x24($sp)
  beql  $t0, $zero, .L7F003098
   lw    $t9, 8($s0)
  beql  $v0, $zero, .L7F003098
   lw    $t9, 8($s0)
  lw    $t2, 0x64($s0)
  lw    $a0, 0x14($s0)
  ori   $t3, $t2, 0x40
  sw    $t3, 0x64($s0)
  lwc1  $f16, 0x20($sp)
  lwc1  $f10, 0x14($a0)
  mul.s $f18, $f10, $f16
  mfc1  $a1, $f18
  jal   set_obj_instance_controller_scale
   nop   
  lw    $t4, 0x14($s1)
  lw    $t5, 0x14($s0)
  li    $at, 1
  sw    $t4, 0x18($t5)
  lw    $v0, 0xf8($s0)
  bnez  $v0, .L7F002FE0
   nop   
  lw    $t8, 0x14($s1)
  lw    $t0, 0x14($s0)
  lw    $t7, 8($t8)
  lw    $t9, 8($t7)
  lw    $t6, ($t9)
  b     .L7F003044
   sw    $t6, 0x1c($t0)
.L7F002FE0:
  bnel  $v0, $at, .L7F003008
   li    $at, 2
  lw    $t1, 0x14($s1)
  lw    $t5, 0x14($s0)
  lw    $t2, 8($t1)
  lw    $t3, 8($t2)
  lw    $t4, 4($t3)
  b     .L7F003044
   sw    $t4, 0x1c($t5)
  li    $at, 2
.L7F003008:
  bnel  $v0, $at, .L7F003030
   lw    $t1, 0x14($s1)
  lw    $t8, 0x14($s1)
  lw    $t0, 0x14($s0)
  lw    $t7, 8($t8)
  lw    $t9, 8($t7)
  lw    $t6, 8($t9)
  b     .L7F003044
   sw    $t6, 0x1c($t0)
  lw    $t1, 0x14($s1)
.L7F003030:
  lw    $t5, 0x14($s0)
  lw    $t2, 8($t1)
  lw    $t3, 8($t2)
  lw    $t4, 0xc($t3)
  sw    $t4, 0x1c($t5)
.L7F003044:
  lw    $a0, 0x24($sp)
  jal   sub_GAME_7F03A5A4
   lw    $a1, 0x10($s1)
  lw    $a1, 0x6c($s0)
  lui   $at, %hi(D_8004EF58)
  lwc1  $f12, %lo(D_8004EF58)($at)
  jal   sub_GAME_7F058570
   addiu $a1, $a1, 4
  lw    $t8, 0x14($s0)
  lw    $t7, 0x14($s1)
  lw    $a1, 0x6c($s0)
  lwc1  $f4, 0x14($t8)
  lwc1  $f8, 0x14($t7)
  addiu $a1, $a1, 4
  jal   matrix_multiply_A1_by_F12
   div.s $f12, $f4, $f8
  b     .L7F003098
   lw    $t9, 8($s0)
.L7F00308C:
  jal   prepare_load_objects
   move  $a2, $s1
  lw    $t9, 8($s0)
.L7F003098:
  sll   $t6, $t9, 1
  bgezl $t6, .L7F0030C0
   lw    $ra, 0x1c($sp)
  lw    $v0, 0x10($s0)
  beql  $v0, $zero, .L7F0030C0
   lw    $ra, 0x1c($sp)
  lbu   $t0, 1($v0)
  ori   $t1, $t0, 1
  sb    $t1, 1($v0)
  lw    $ra, 0x1c($sp)
.L7F0030C0:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x38
");

asm(R"
glabel sub_GAME_7F0030D0
  addiu $sp, $sp, -0x20
  sw    $a0, 0x20($sp)
  lui   $t6, %hi(dword_CODE_bss_80075B98) 
  sw    $s0, 0x18($sp)
  addiu $t6, %lo(dword_CODE_bss_80075B98) # addiu $t6, $t6, 0x5b98
  addiu $a0, $a1, 0x80
  move  $s0, $a1
  sw    $ra, 0x1c($sp)
  sw    $a2, 0x28($sp)
  move  $t0, $a0
  addiu $t9, $t6, 0x6c
.L7F0030FC:
  lw    $at, ($t6)
  addiu $t6, $t6, 0xc
  addiu $t0, $t0, 0xc
  sw    $at, -0xc($t0)
  lw    $at, -8($t6)
  sw    $at, -8($t0)
  lw    $at, -4($t6)
  bne   $t6, $t9, .L7F0030FC
   sw    $at, -4($t0)
  lw    $at, ($t6)
  sw    $at, ($t0)
  lw    $t9, 4($t6)
  sw    $t9, 4($t0)
  jal   set_ptr_monitor_img_to_obj_ani_slot
   lbu   $a1, 0x250($s0)
  lui   $t1, %hi(dword_CODE_bss_80075B98) 
  addiu $t1, %lo(dword_CODE_bss_80075B98) # addiu $t1, $t1, 0x5b98
  addiu $a0, $s0, 0xf4
  move  $t5, $a0
  addiu $t4, $t1, 0x6c
.L7F00314C:
  lw    $at, ($t1)
  addiu $t1, $t1, 0xc
  addiu $t5, $t5, 0xc
  sw    $at, -0xc($t5)
  lw    $at, -8($t1)
  sw    $at, -8($t5)
  lw    $at, -4($t1)
  bne   $t1, $t4, .L7F00314C
   sw    $at, -4($t5)
  lw    $at, ($t1)
  sw    $at, ($t5)
  lw    $t4, 4($t1)
  sw    $t4, 4($t5)
  jal   set_ptr_monitor_img_to_obj_ani_slot
   lbu   $a1, 0x251($s0)
  lui   $t8, %hi(dword_CODE_bss_80075B98) 
  addiu $t8, %lo(dword_CODE_bss_80075B98) # addiu $t8, $t8, 0x5b98
  addiu $a0, $s0, 0x168
  move  $t0, $a0
  addiu $t6, $t8, 0x6c
.L7F00319C:
  lw    $at, ($t8)
  addiu $t8, $t8, 0xc
  addiu $t0, $t0, 0xc
  sw    $at, -0xc($t0)
  lw    $at, -8($t8)
  sw    $at, -8($t0)
  lw    $at, -4($t8)
  bne   $t8, $t6, .L7F00319C
   sw    $at, -4($t0)
  lw    $at, ($t8)
  sw    $at, ($t0)
  lw    $t6, 4($t8)
  sw    $t6, 4($t0)
  jal   set_ptr_monitor_img_to_obj_ani_slot
   lbu   $a1, 0x252($s0)
  lui   $t3, %hi(dword_CODE_bss_80075B98) 
  addiu $t3, %lo(dword_CODE_bss_80075B98) # addiu $t3, $t3, 0x5b98
  addiu $a0, $s0, 0x1dc
  move  $t5, $a0
  addiu $t1, $t3, 0x6c
.L7F0031EC:
  lw    $at, ($t3)
  addiu $t3, $t3, 0xc
  addiu $t5, $t5, 0xc
  sw    $at, -0xc($t5)
  lw    $at, -8($t3)
  sw    $at, -8($t5)
  lw    $at, -4($t3)
  bne   $t3, $t1, .L7F0031EC
   sw    $at, -4($t5)
  lw    $at, ($t3)
  sw    $at, ($t5)
  lw    $t1, 4($t3)
  sw    $t1, 4($t5)
  jal   set_ptr_monitor_img_to_obj_ani_slot
   lbu   $a1, 0x253($s0)
  lw    $a0, 0x20($sp)
  move  $a1, $s0
  jal   prepare_load_objects
   lw    $a2, 0x28($sp)
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F00324C
  addiu $sp, $sp, -0x50
  sw    $ra, 0x24($sp)
  sw    $s1, 0x20($sp)
  sw    $s0, 0x1c($sp)
  sw    $a1, 0x54($sp)
  move  $s0, $a0
  move  $s1, $a3
  sw    $a2, 0x58($sp)
  jal   sub_GAME_7F001BD4
   addiu $a1, $sp, 0x30
  lw    $t6, 0x28($s0)
  lwc1  $f4, 0x38($sp)
  addiu $a0, $sp, 0x2c
  sw    $t6, 0x2c($sp)
  lw    $a2, 8($s0)
  lw    $a1, ($s0)
  lw    $a3, 0x30($sp)
  jal   sub_GAME_7F0B0BE4
   swc1  $f4, 0x10($sp)
  bnezl $v0, .L7F0032C4
   lwc1  $f16, 0x10($s0)
  lw    $t7, 0x28($s0)
  sw    $t7, 0x2c($sp)
  lwc1  $f6, ($s0)
  swc1  $f6, 0x30($sp)
  lwc1  $f8, 4($s0)
  swc1  $f8, 0x34($sp)
  lwc1  $f10, 8($s0)
  swc1  $f10, 0x38($sp)
  lwc1  $f16, 0x10($s0)
.L7F0032C4:
  lwc1  $f18, 0x20($s0)
  lwc1  $f6, 0x1c($s0)
  lwc1  $f8, 0x14($s0)
  mul.s $f4, $f16, $f18
  nop   
  mul.s $f10, $f6, $f8
  sub.s $f16, $f4, $f10
  swc1  $f16, 0x40($sp)
  lwc1  $f6, 0x18($s0)
  lwc1  $f18, 0x14($s0)
  lwc1  $f10, 0xc($s0)
  lwc1  $f4, 0x20($s0)
  mul.s $f8, $f18, $f6
  nop   
  mul.s $f18, $f4, $f10
  sub.s $f6, $f8, $f18
  swc1  $f6, 0x44($sp)
  lwc1  $f10, 0x1c($s0)
  lwc1  $f4, 0xc($s0)
  lwc1  $f18, 0x18($s0)
  mul.s $f8, $f4, $f10
  lwc1  $f4, 0x10($s0)
  mul.s $f10, $f18, $f4
  sub.s $f18, $f8, $f10
  mul.s $f4, $f16, $f16
  nop   
  mul.s $f8, $f6, $f6
  swc1  $f18, 0x48($sp)
  mul.s $f16, $f18, $f18
  add.s $f10, $f4, $f8
  jal   sqrtf
   add.s $f12, $f16, $f10
  li    $at, 0x42480000 # 50.000000
  mtc1  $at, $f12
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  lwc1  $f4, 0x40($sp)
  lwc1  $f18, 0x44($sp)
  div.s $f2, $f6, $f0
  lwc1  $f10, 0x48($sp)
  lw    $t8, 0x2c($sp)
  addiu $s0, $sp, 0x4c
  move  $a0, $s0
  sw    $t8, 0x4c($sp)
  mul.s $f8, $f4, $f2
  nop   
  mul.s $f16, $f18, $f2
  lwc1  $f18, 0x30($sp)
  mul.s $f6, $f10, $f2
  swc1  $f8, 0x40($sp)
  mul.s $f4, $f8, $f12
  swc1  $f16, 0x44($sp)
  swc1  $f6, 0x48($sp)
  add.s $f16, $f4, $f18
  swc1  $f16, ($s1)
  lwc1  $f10, 0x34($sp)
  lw    $a3, ($s1)
  swc1  $f10, 4($s1)
  lwc1  $f6, 0x48($sp)
  lwc1  $f4, 0x38($sp)
  mul.s $f8, $f6, $f12
  add.s $f18, $f8, $f4
  swc1  $f18, 8($s1)
  lwc1  $f16, 8($s1)
  lw    $a2, 0x38($sp)
  lw    $a1, 0x30($sp)
  jal   sub_GAME_7F0B0BE4
   swc1  $f16, 0x10($sp)
  lw    $t9, 0x4c($sp)
  lw    $t1, 0x54($sp)
  lw    $v0, 0x60($sp)
  lbu   $t0, 3($t9)
  li    $at, 0x42480000 # 50.000000
  mtc1  $at, $f12
  sw    $t0, ($t1)
  lwc1  $f6, 0x40($sp)
  lwc1  $f10, 0x30($sp)
  lw    $t2, 0x2c($sp)
  mul.s $f8, $f6, $f12
  move  $a0, $s0
  sw    $t2, 0x4c($sp)
  sub.s $f4, $f10, $f8
  swc1  $f4, ($v0)
  lwc1  $f18, 0x34($sp)
  lw    $a3, ($v0)
  swc1  $f18, 4($v0)
  lwc1  $f6, 0x48($sp)
  lwc1  $f16, 0x38($sp)
  mul.s $f10, $f6, $f12
  sub.s $f8, $f16, $f10
  swc1  $f8, 8($v0)
  lwc1  $f4, 8($v0)
  lw    $a2, 0x38($sp)
  lw    $a1, 0x30($sp)
  jal   sub_GAME_7F0B0BE4
   swc1  $f4, 0x10($sp)
  lw    $t3, 0x4c($sp)
  lw    $v0, 0x58($sp)
  li    $t8, -1
  lbu   $t4, 3($t3)
  sw    $t4, ($v0)
  lw    $t6, 0x54($sp)
  lw    $t7, ($t6)
  bnel  $t4, $t7, .L7F003470
   lw    $ra, 0x24($sp)
  sw    $t8, ($v0)
  lw    $ra, 0x24($sp)
.L7F003470:
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x50
");

asm(R"
glabel sub_GAME_7F003480
  addiu $sp, $sp, -0x1d8
  sw    $ra, 0x34($sp)
  sw    $s1, 0x30($sp)
  sw    $s0, 0x2c($sp)
  sw    $a0, 0x1d8($sp)
  sw    $a2, 0x1e0($sp)
  lh    $a0, 4($a1)
  li    $t5, -1
  li    $t6, -1
  li    $t8, -1
  move  $s1, $a1
  sw    $t5, 0x1b4($sp)
  sw    $t6, 0x1b0($sp)
  sw    $t8, 0x1ac($sp)
  jal   load_model
   sw    $a0, 0x1d0($sp)
  lh    $t9, 6($s1)
  lw    $v1, 8($s1)
  lui   $t0, %hi(ptr_2xxxpresets) 
  sll   $t7, $t9, 4
  lw    $t0, %lo(ptr_2xxxpresets)($t0)
  addu  $t7, $t7, $t9
  sll   $t7, $t7, 2
  sll   $t1, $v1, 3
  bltz  $t1, .L7F0034F0
   addu  $s0, $t7, $t0
  sll   $t2, $v1, 1
  bgez  $t2, .L7F00353C
.L7F0034F0:
   addiu $t3, $sp, 0x194
  sw    $t3, 0x10($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x1b0
  addiu $a2, $sp, 0x1ac
  jal   sub_GAME_7F00324C
   addiu $a3, $sp, 0x1a0
  lw    $t4, 8($s1)
  lw    $a0, 0x1b0($sp)
  sll   $t5, $t4, 3
  bgez  $t5, .L7F00353C
   nop   
  bltz  $a0, .L7F00353C
   lw    $a1, 0x1ac($sp)
  bltz  $a1, .L7F00353C
   addiu $a2, $sp, 0x1a0
  jal   sub_GAME_7F0B9CC8
   addiu $a3, $sp, 0x194
  sw    $v0, 0x1b4($sp)
.L7F00353C:
  lui   $v1, %hi(scale_1_0_item_related)
  addiu $v1, %lo(scale_1_0_item_related) # addiu $v1, $v1, -0x5c40
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  lwc1  $f12, ($v1)
  lw    $t6, 0x1b4($sp)
  c.eq.s $f8, $f12
  nop   
  bc1tl .L7F0036FC
   lw    $a1, 0x28($s0)
  bltz  $t6, .L7F0036DC
   move  $a0, $t6
  jal   sub_GAME_7F0B96CC
   addiu $a1, $sp, 0x180
  jal   get_room_data_float2
   nop   
  lwc1  $f10, 0x18c($sp)
  lwc1  $f18, 0x188($sp)
  lui   $v1, %hi(scale_1_0_item_related)
  mul.s $f6, $f10, $f0
  addiu $v1, %lo(scale_1_0_item_related) # addiu $v1, $v1, -0x5c40
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f16
  lwc1  $f12, ($v1)
  addiu $a0, $sp, 0x16c
  swc1  $f6, 0x18c($sp)
  lwc1  $f4, 8($s0)
  lwc1  $f10, 4($s0)
  lwc1  $f14, ($s0)
  mul.s $f8, $f18, $f4
  lwc1  $f4, 0x184($sp)
  swc1  $f6, 0x38($sp)
  lwc1  $f6, 0x180($sp)
  mul.s $f10, $f10, $f4
  swc1  $f18, 0x3c($sp)
  c.lt.s $f12, $f16
  mul.s $f18, $f14, $f6
  add.s $f18, $f18, $f10
  lwc1  $f10, 0x18c($sp)
  bc1f  .L7F003628
   add.s $f2, $f8, $f18
  lwc1  $f10, 0x38($sp)
  sub.s $f18, $f16, $f12
  sub.s $f8, $f2, $f10
  mul.s $f2, $f8, $f18
  nop   
  mul.s $f10, $f6, $f2
  sub.s $f8, $f14, $f10
  mul.s $f6, $f4, $f2
  lwc1  $f4, 0x3c($sp)
  swc1  $f8, 0x170($sp)
  lwc1  $f18, 4($s0)
  sub.s $f10, $f18, $f6
  mul.s $f18, $f4, $f2
  swc1  $f10, 0x174($sp)
  lwc1  $f8, 8($s0)
  sub.s $f6, $f8, $f18
  b     .L7F00366C
   swc1  $f6, 0x178($sp)
.L7F003628:
  sub.s $f4, $f2, $f10
  lwc1  $f18, 0x180($sp)
  sub.s $f8, $f12, $f16
  mul.s $f2, $f4, $f8
  lwc1  $f4, 0x184($sp)
  mul.s $f6, $f18, $f2
  add.s $f10, $f6, $f14
  mul.s $f8, $f4, $f2
  swc1  $f10, 0x170($sp)
  lwc1  $f18, 4($s0)
  lwc1  $f10, 0x188($sp)
  add.s $f6, $f8, $f18
  mul.s $f4, $f10, $f2
  swc1  $f6, 0x174($sp)
  lwc1  $f8, 8($s0)
  add.s $f18, $f4, $f8
  swc1  $f18, 0x178($sp)
.L7F00366C:
  lw    $t8, 0x28($s0)
  lwc1  $f6, 0x178($sp)
  lw    $a3, 0x170($sp)
  sw    $t8, 0x16c($sp)
  lw    $a2, 8($s0)
  lw    $a1, ($s0)
  jal   sub_GAME_7F0B0BE4
   swc1  $f6, 0x10($sp)
  lui   $v1, %hi(scale_1_0_item_related)
  beqz  $v0, .L7F0036F8
   addiu $v1, %lo(scale_1_0_item_related) # addiu $v1, $v1, -0x5c40
  lw    $t9, 0x16c($sp)
  lwc1  $f18, 0x2c($s0)
  sw    $t9, 0x28($s0)
  lwc1  $f10, 0x170($sp)
  swc1  $f10, ($s0)
  lwc1  $f4, 0x174($sp)
  swc1  $f4, 4($s0)
  lwc1  $f8, 0x178($sp)
  lwc1  $f4, 0x30($s0)
  swc1  $f8, 8($s0)
  lwc1  $f6, ($v1)
  mul.s $f10, $f18, $f6
  swc1  $f10, 0x2c($s0)
  lwc1  $f8, ($v1)
  mul.s $f18, $f4, $f8
  b     .L7F0036F8
   swc1  $f18, 0x30($s0)
.L7F0036DC:
  lwc1  $f6, 0x2c($s0)
  lwc1  $f4, 0x30($s0)
  mul.s $f10, $f6, $f12
  swc1  $f10, 0x2c($s0)
  lwc1  $f8, ($v1)
  mul.s $f18, $f4, $f8
  swc1  $f18, 0x30($s0)
.L7F0036F8:
  lw    $a1, 0x28($s0)
.L7F0036FC:
  addiu $t7, $sp, 0x1c8
  sw    $t7, 0x10($sp)
  move  $a0, $s0
  li    $a2, 0
  jal   sub_GAME_7F056850
   addiu $a3, $sp, 0x1b8
  beql  $v0, $zero, .L7F003BDC
   sw    $zero, 0x10($s1)
  lwc1  $f6, 0x18($s0)
  mtc1  $zero, $f0
  addiu $a0, $sp, 0x12c
  neg.s $f10, $f6
  mfc1  $a1, $f0
  swc1  $f10, 0x10($sp)
  lwc1  $f4, 0x1c($s0)
  mfc1  $a2, $f0
  mfc1  $a3, $f0
  neg.s $f8, $f4
  swc1  $f8, 0x14($sp)
  lwc1  $f18, 0x20($s0)
  neg.s $f6, $f18
  swc1  $f6, 0x18($sp)
  lwc1  $f10, 0xc($s0)
  swc1  $f10, 0x1c($sp)
  lwc1  $f4, 0x10($s0)
  swc1  $f4, 0x20($sp)
  lwc1  $f8, 0x14($s0)
  jal   sub_GAME_7F059908
   swc1  $f8, 0x24($sp)
  lw    $t0, 0x1d0($sp)
  lui   $t2, %hi(PitemZ_entries)
  lw    $t3, 0x1c8($sp)
  sll   $t1, $t0, 2
  subu  $t1, $t1, $t0
  sll   $t1, $t1, 2
  addu  $t2, $t2, $t1
  lw    $t2, %lo(PitemZ_entries)($t2)
  sw    $t3, 0x114($sp)
  lui   $at, %hi(D_8004EF5C)
  sw    $t2, 0x124($sp)
  lwc1  $f18, 0x2c($s0)
  lwc1  $f12, %lo(D_8004EF5C)($at)
  addiu $a1, $sp, 0xd4
  swc1  $f18, 0x78($sp)
  lwc1  $f6, 0x30($s0)
  swc1  $f6, 0x74($sp)
  lwc1  $f10, 0x34($s0)
  swc1  $f10, 0x70($sp)
  lwc1  $f4, 0x38($s0)
  swc1  $f4, 0x6c($sp)
  lwc1  $f8, 0x3c($s0)
  swc1  $f8, 0x68($sp)
  lwc1  $f18, 0x40($s0)
  jal   sub_GAME_7F058570
   swc1  $f18, 0x64($sp)
  lui   $at, %hi(D_8004EF60)
  lwc1  $f12, %lo(D_8004EF60)($at)
  jal   sub_GAME_7F058688
   addiu $a1, $sp, 0x88
  addiu $a0, $sp, 0x88
  jal   sub_GAME_7F058068
   addiu $a1, $sp, 0xd4
  addiu $a0, $sp, 0x12c
  jal   sub_GAME_7F058068
   addiu $a1, $sp, 0xd4
  move  $a0, $s0
  jal   sub_GAME_7F001BD4
   addiu $a1, $sp, 0x118
  lw    $t4, 0x124($sp)
  lwc1  $f6, 0x6c($sp)
  lwc1  $f10, 0x70($sp)
  lw    $t5, ($t4)
  lui    $at, %hi(D_8004EF64)
  sub.s $f4, $f6, $f10
  lw    $t6, 0x14($t5)
  lwc1  $f10, 0x64($sp)
  lwc1  $f0, %lo(D_8004EF64)($at)
  lw    $v0, 4($t6)
  addiu $a1, $sp, 0xd4
  lwc1  $f8, 8($v0)
  lwc1  $f18, 4($v0)
  sub.s $f6, $f8, $f18
  lwc1  $f8, 0x68($sp)
  lwc1  $f18, 0x10($v0)
  div.s $f12, $f4, $f6
  lwc1  $f4, 0xc($v0)
  sub.s $f2, $f10, $f8
  lwc1  $f8, 0x78($sp)
  lwc1  $f10, 0x74($sp)
  sub.s $f6, $f18, $f4
  lwc1  $f4, 0x18($v0)
  div.s $f14, $f2, $f6
  lwc1  $f6, 0x14($v0)
  c.le.s $f12, $f0
  sub.s $f18, $f10, $f8
  sub.s $f10, $f4, $f6
  bc1t  .L7F0038A0
   div.s $f16, $f18, $f10
  c.le.s $f14, $f0
  nop   
  bc1tl .L7F0038A4
   li    $at, 0x3F800000 # 1.000000
  c.le.s $f16, $f0
  nop   
  bc1f  .L7F0038B4
.L7F0038A0:
   li    $at, 0x3F800000 # 1.000000
.L7F0038A4:
  mtc1  $at, $f16
  mtc1  $at, $f14
  mtc1  $at, $f12
  nop   
.L7F0038B4:
  swc1  $f2, 0x48($sp)
  swc1  $f12, 0x60($sp)
  swc1  $f14, 0x5c($sp)
  jal   sub_GAME_7F0589B4
   swc1  $f16, 0x58($sp)
  lwc1  $f12, 0x5c($sp)
  jal   sub_GAME_7F0589E4
   addiu $a1, $sp, 0xd4
  lwc1  $f12, 0x58($sp)
  jal   sub_GAME_7F058A4C
   addiu $a1, $sp, 0xd4
  lwc1  $f8, 0x118($sp)
  lwc1  $f4, 0x11c($sp)
  lwc1  $f6, 0x120($sp)
  swc1  $f8, 0xc8($sp)
  swc1  $f4, 0xcc($sp)
  swc1  $f6, 0xd0($sp)
  lw    $t8, 0xc($s1)
  lwc1  $f2, 0x48($sp)
  addiu $a0, $sp, 0x114
  andi  $t9, $t8, 1
  bnez  $t9, .L7F003964
   lwc1  $f4, 0x1b8($sp)
  mfc1  $a3, $f8
  lw    $a1, 0x1b8($sp)
  lw    $a2, 0x1c0($sp)
  swc1  $f6, 0x10($sp)
  jal   sub_GAME_7F0B0BE4
   swc1  $f2, 0x48($sp)
  beqz  $v0, .L7F00393C
   lwc1  $f2, 0x48($sp)
  lw    $t7, 0x114($sp)
  b     .L7F003978
   sw    $t7, 0x1c8($sp)
.L7F00393C:
  lwc1  $f18, 0x1b8($sp)
  lwc1  $f10, 0x1c0($sp)
  swc1  $f18, 0x118($sp)
  swc1  $f10, 0x120($sp)
  lw    $t0, 8($s1)
  andi  $t1, $t0, 0x1000
  bnezl $t1, .L7F00397C
   lhu   $v0, 0x9a($s1)
  b     .L7F00397C
   lhu   $v0, 0x9a($s1)
.L7F003964:
  lwc1  $f8, 0x1bc($sp)
  lwc1  $f6, 0x1c0($sp)
  swc1  $f4, 0x118($sp)
  swc1  $f8, 0x11c($sp)
  swc1  $f6, 0x120($sp)
.L7F003978:
  lhu   $v0, 0x9a($s1)
.L7F00397C:
  li    $at, 4
  beq   $v0, $at, .L7F003990
   li    $at, 8
  bne   $v0, $at, .L7F0039B8
   lwc1  $f10, 0x70($sp)
.L7F003990:
  lwc1  $f18, 0x18($s0)
  mul.s $f10, $f18, $f2
  swc1  $f10, 0x7c($sp)
  lwc1  $f4, 0x1c($s0)
  mul.s $f8, $f4, $f2
  swc1  $f8, 0x80($sp)
  lwc1  $f6, 0x20($s0)
  mul.s $f18, $f6, $f2
  b     .L7F0039E4
   swc1  $f18, 0x84($sp)
.L7F0039B8:
  lwc1  $f4, 0x6c($sp)
  lwc1  $f8, 0xc($s0)
  sub.s $f0, $f10, $f4
  mul.s $f6, $f8, $f0
  swc1  $f6, 0x7c($sp)
  lwc1  $f18, 0x10($s0)
  mul.s $f10, $f18, $f0
  swc1  $f10, 0x80($sp)
  lwc1  $f4, 0x14($s0)
  mul.s $f8, $f4, $f0
  swc1  $f8, 0x84($sp)
.L7F0039E4:
  lw    $t2, 0x84($s1)
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f0
  mtc1  $t2, $f6
  lw    $t3, 0x88($s1)
  lw    $t4, 0x8c($s1)
  cvt.s.w $f18, $f6
  mtc1  $t3, $f4
  lw    $t5, 0x90($s1)
  lw    $t6, 0x94($s1)
  addiu $t8, $sp, 0x7c
  cvt.s.w $f8, $f4
  addiu $t9, $sp, 0xc8
  move  $a0, $s1
  addiu $a1, $sp, 0x118
  addiu $a2, $sp, 0xd4
  div.s $f10, $f18, $f0
  mtc1  $t4, $f18
  div.s $f6, $f8, $f0
  swc1  $f10, 0x84($s1)
  mtc1  $t5, $f8
  cvt.s.w $f10, $f18
  div.s $f4, $f10, $f0
  mtc1  $t6, $f10
  swc1  $f6, 0x88($s1)
  cvt.s.w $f6, $f8
  div.s $f18, $f6, $f0
  swc1  $f4, 0x8c($s1)
  cvt.s.w $f4, $f10
  div.s $f8, $f4, $f0
  swc1  $f18, 0x90($s1)
  swc1  $f8, 0x94($s1)
  sw    $t9, 0x14($sp)
  sw    $t8, 0x10($sp)
  jal   initialize_door
   lw    $a3, 0x1c8($sp)
  lw    $t7, 8($s1)
  move  $s0, $v0
  lw    $t1, 0x1b4($sp)
  sll   $t0, $t7, 3
  bgezl $t0, .L7F003AC0
   lw    $v0, 0x14($s0)
  sw    $t1, 0xf0($s1)
  lw    $t2, 0x1b4($sp)
  bltzl $t2, .L7F003AC0
   lw    $v0, 0x14($s0)
  mtc1  $zero, $f6
  lwc1  $f18, 0xb4($s1)
  c.eq.s $f6, $f18
  nop   
  bc1fl .L7F003AC0
   lw    $v0, 0x14($s0)
  jal   sub_GAME_7F0535C4
   move  $a0, $s1
  lw    $v0, 0x14($s0)
.L7F003AC0:
  move  $a0, $s0
  lbu   $t3, 3($v0)
  sb    $t3, 0x2c($s0)
  jal   sub_GAME_7F03DD9C
   lbu   $a1, 3($v0)
  li    $v0, 255
  sb    $v0, 0x2d($s0)
  sb    $v0, 0x2e($s0)
  lw    $v1, 8($s1)
  sll   $t4, $v1, 3
  bltz  $t4, .L7F003AF8
   sll   $t5, $v1, 1
  bgezl $t5, .L7F003B5C
   lw    $a0, 0x14($s1)
.L7F003AF8:
  lw    $t8, 0x14($s0)
  lw    $t6, 0x1b0($sp)
  lw    $a1, 0x1ac($sp)
  lbu   $t9, 3($t8)
  beq   $t6, $t9, .L7F003B30
   nop   
  bltz  $t6, .L7F003B48
   lw    $t7, 0x1b0($sp)
  sb    $t7, 0x2d($s0)
  lh    $a1, 0x1b2($sp)
  jal   sub_GAME_7F03DD9C
   move  $a0, $s0
  b     .L7F003B4C
   lbu   $t1, 0x2d($s0)
.L7F003B30:
  bltz  $a1, .L7F003B48
   lw    $t0, 0x1ac($sp)
  sb    $t0, 0x2d($s0)
  lh    $a1, 0x1ae($sp)
  jal   sub_GAME_7F03DD9C
   move  $a0, $s0
.L7F003B48:
  lbu   $t1, 0x2d($s0)
.L7F003B4C:
  li    $at, 255
  beql  $t1, $at, .L7F003B5C
   lw    $a0, 0x14($s1)
  lw    $a0, 0x14($s1)
.L7F003B5C:
  lwc1  $f0, 0x60($sp)
  lwc1  $f12, 0x5c($sp)
  beqz  $a0, .L7F003BA8
   lwc1  $f10, 0x58($sp)
  c.lt.s $f0, $f12
  nop   
  bc1fl .L7F003B84
   c.lt.s $f0, $f10
  mov.s $f0, $f12
  c.lt.s $f0, $f10
.L7F003B84:
  nop   
  bc1fl .L7F003B98
   lwc1  $f4, 0x14($a0)
  mov.s $f0, $f10
  lwc1  $f4, 0x14($a0)
.L7F003B98:
  mul.s $f8, $f4, $f0
  mfc1  $a1, $f8
  jal   set_obj_instance_controller_scale
   nop   
.L7F003BA8:
  jal   set_current_objposdata_plus_0x28
   move  $a0, $s0
  jal   set_stateflag_0x04_for_posdata
   move  $a0, $s0
  lw    $v0, 0x80($s1)
  lw    $t3, 0x1e0($sp)
  beql  $v0, $zero, .L7F003BE0
   lw    $ra, 0x34($sp)
  jal   sub_GAME_7F056A88
   addu  $a0, $v0, $t3
  b     .L7F003BDC
   sw    $v0, 0xc8($s1)
  sw    $zero, 0x10($s1)
.L7F003BDC:
  lw    $ra, 0x34($sp)
.L7F003BE0:
  lw    $s0, 0x2c($sp)
  lw    $s1, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x1d8
");

#ifdef VERSION_US
asm(R"
.late_rodata
glabel jpt_object_type_expansion
.word door_expand
.word door_scale_expand
.word obj_03_expand
.word key_expand
.word obj_03_expand
.word surv_camera_expand
.word obj_03_expand
.word item_expand
.word actor_expand
.word single_screen_display_expand
.word multi_screen_display_expand
.word rack_expand
.word autogun_expand
.word other_obj_expand
.word other_obj_expand
.word other_obj_expand
.word hat_expand
.word actor_attr_expand
.word other_obj_expand
.word ammo_box_expand
.word body_armor_expand
.word tag_expand
.word type17_objective_expand
.word other_obj_expand
.word other_obj_expand
.word other_obj_expand
.word other_obj_expand
.word other_obj_expand
.word other_obj_expand
.word type1E_subobjective_expand
.word other_obj_expand
.word type20_subobjective_expand
.word type21_subobjective_expand
.word other_obj_expand
.word type23_solo_brief_text
.word obj_03_expand
.word type25_rename
.word other_obj_expand
.word type27_wheeled_vehicle
.word type28_aircraft
.word obj_03_expand
.word obj_03_expand
.word obj_03_expand
.word other_obj_expand
.word type2D_tank
.word type2E_viewport_pos
.word type2F_tinted_glass

glabel D_8004F024
.word 0x40c90fdb
glabel D_8004F028
.word 0x3e2e147c

glabel jpt_8004F02C
.word .L7F004B6C
.word .L7F004B6C
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004B6C
.word .L7F004B6C
.word .L7F004DE4
.word .L7F004B6C
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004BD8
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004C2C
.word .L7F004B6C
.word .L7F004B6C
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004B6C
.word .L7F004DE4
.word .L7F004D70
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004B6C
.word .L7F004B6C
.word .L7F004B6C
.word .L7F004CA4
.word .L7F004DE4
.word .L7F004DE4
.word .L7F004B6C

.text
glabel proplvreset2
  addiu $sp, $sp, -0x280
  sw    $s5, 0x34($sp)
  move  $s5, $a0
  sw    $ra, 0x44($sp)
  lui   $a1, %hi(aNochr)
  sw    $fp, 0x40($sp)
  sw    $s7, 0x3c($sp)
  sw    $s6, 0x38($sp)
  sw    $s4, 0x30($sp)
  sw    $s3, 0x2c($sp)
  sw    $s2, 0x28($sp)
  sw    $s1, 0x24($sp)
  sw    $s0, 0x20($sp)
  sdc1  $f20, 0x18($sp)
  addiu $a1, %lo(aNochr) # addiu $a1, $a1, -0x1270
  jal   check_token
   li    $a0, 1
  sltiu $a2, $v0, 1
  beqz  $a2, .L7F003C50
   li    $a0, 1
  lui   $a1, %hi(aNoprop)
  jal   check_token
   addiu $a1, %lo(aNoprop) # addiu $a1, $a1, -0x1268
  sltiu $a2, $v0, 1
.L7F003C50:
  lui   $a1, %hi(aNoobj)
  sw    $a2, 0x278($sp)
  addiu $a1, %lo(aNoobj) # addiu $a1, $a1, -0x1260
  jal   check_token
   li    $a0, 1
  sltiu $v1, $v0, 1
  beqz  $v1, .L7F003C80
   li    $a0, 1
  lui   $a1, %hi(aNoprop_0)
  jal   check_token
   addiu $a1, %lo(aNoprop_0) # addiu $a1, $a1, -0x1258
  sltiu $v1, $v0, 1
.L7F003C80:
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  move  $fp, $v1
  lui   $at, %hi(scale_1_0_item_related)
  lui   $v1, %hi(PitemZ_entries+0xFF0)
  lui   $v0, %hi(PitemZ_entries)
  addiu $v0, %lo(PitemZ_entries) # addiu $v0, $v0, -0x5dd8
  addiu $v1, $v1, %lo(PitemZ_entries+0xFF0)
  swc1  $f4, %lo(scale_1_0_item_related)($at)
.L7F003CA4:
  lw    $t6, ($v0)
  addiu $v0, $v0, 0xc
  sltu  $at, $v0, $v1
  bnez  $at, .L7F003CA4
   sw    $zero, ($t6)
  slti  $at, $s5, 0x3b
  beqz  $at, .L7F004E10
   sll   $t7, $s5, 2
  lui   $t8, %hi(setup_text_pointers) 
  addiu $t8, %lo(setup_text_pointers) # addiu $t8, $t8, 0x74e4
  addu  $s0, $t7, $t8
  lw    $v0, ($s0)
  lui   $t9, %hi(only_read_by_stageload) 
  addiu $s1, $sp, 0x174
  beqz  $v0, .L7F004E10
   addiu $t9, %lo(only_read_by_stageload) # addiu $t9, $t9, -0x1250
  move  $t2, $s1
  addiu $t1, $t9, 0xfc
.L7F003CEC:
  lw    $at, ($t9)
  addiu $t9, $t9, 0xc
  addiu $t2, $t2, 0xc
  sw    $at, -0xc($t2)
  lw    $at, -8($t9)
  sw    $at, -8($t2)
  lw    $at, -4($t9)
  bne   $t9, $t1, .L7F003CEC
   sw    $at, -4($t2)
  lw    $at, ($t9)
  move  $s4, $zero
  move  $s3, $zero
  sw    $at, ($t2)
  lbu   $t3, ($v0)
  sb    $zero, 0x175($sp)
  jal   getPlayerCount
   sb    $t3, 0x174($sp)
  slti  $at, $v0, 2
  bnez  $at, .L7F003D48
   lui   $a1, %hi(aMp_)
  addiu $a1, %lo(aMp_) # addiu $a1, $a1, -0x1150
  jal   string_append_from_obseg_textbank
   move  $a0, $s1
.L7F003D48:
  lw    $a1, ($s0)
  move  $a0, $s1
  jal   string_append_from_obseg_textbank
   addiu $a1, $a1, 1
  move  $a0, $s1
  li    $a1, 1
  li    $a2, 256
  jal   _load_resource_named_to_membank
   li    $a3, 4
  lui   $v1, %hi(dword_CODE_bss_80075D28)
  addiu $v1, %lo(dword_CODE_bss_80075D28) # addiu $v1, $v1, 0x5d28
  sw    $v0, ($v1)
  move  $s1, $v0
  jal   get_textbank_number_for_stagenum
   move  $a0, $s5
  jal   load_mission_text_bank
   move  $a0, $v0
  lw    $t4, ($s1)
  lui   $a3, %hi(ptr_setup_path_tbl)
  addiu $a3, %lo(ptr_setup_path_tbl) # addiu $a3, $a3, 0x5d00
  addu  $t5, $s1, $t4
  sw    $t5, ($a3)
  lw    $t6, 4($s1)
  addu  $t7, $s1, $t6
  sw    $t7, 4($a3)
  lw    $t8, 8($s1)
  addu  $t0, $s1, $t8
  sw    $t0, 8($a3)
  lw    $t1, 0xc($s1)
  addu  $t9, $s1, $t1
  sw    $t9, 0xc($a3)
  lw    $t2, 0x10($s1)
  addu  $t3, $s1, $t2
  sw    $t3, 0x10($a3)
  lw    $t4, 0x14($s1)
  addu  $t5, $s1, $t4
  sw    $t5, 0x14($a3)
  lw    $t6, 0x18($s1)
  addu  $t7, $s1, $t6
  sw    $t7, 0x18($a3)
  lw    $t8, 0x1c($s1)
  addu  $t0, $s1, $t8
  sw    $t0, 0x1c($a3)
  lw    $v0, 0x20($s1)
  beqz  $v0, .L7F003E08
   addu  $t1, $s1, $v0
  b     .L7F003E0C
   sw    $t1, 0x20($a3)
.L7F003E08:
  sw    $zero, 0x20($a3)
.L7F003E0C:
  lw    $v0, 0x24($s1)
  beqz  $v0, .L7F003E20
   addu  $t9, $s1, $v0
  b     .L7F003E24
   sw    $t9, 0x24($a3)
.L7F003E20:
  sw    $zero, 0x24($a3)
.L7F003E24:
  lw    $a1, ($a3)
  beql  $a1, $zero, .L7F003E6C
   lw    $a1, 4($a3)
  lw    $t2, ($a1)
  move  $v1, $zero
  move  $v0, $a1
  bltzl $t2, .L7F003E6C
   lw    $a1, 4($a3)
  lw    $t3, 4($v0)
.L7F003E48:
  addiu $v1, $v1, 0x10
  addu  $t4, $t3, $s1
  sw    $t4, 4($v0)
  lw    $t5, ($a3)
  addu  $v0, $t5, $v1
  lw    $t6, ($v0)
  bgezl $t6, .L7F003E48
   lw    $t3, 4($v0)
  lw    $a1, 4($a3)
.L7F003E6C:
  beql  $a1, $zero, .L7F003EC4
   lw    $a2, 0x14($a3)
  lw    $t7, ($a1)
  move  $v1, $zero
  move  $v0, $a1
  beql  $t7, $zero, .L7F003EC4
   lw    $a2, 0x14($a3)
  lw    $a0, ($a1)
  addu  $t8, $a0, $s1
.L7F003E90:
  sw    $t8, ($v0)
  lw    $t0, 4($a3)
  addu  $v0, $t0, $v1
  lw    $t1, 4($v0)
  addiu $v1, $v1, 0xc
  addu  $t9, $t1, $s1
  sw    $t9, 4($v0)
  lw    $t2, 4($a3)
  addu  $v0, $t2, $v1
  lw    $a0, ($v0)
  bnezl $a0, .L7F003E90
   addu  $t8, $a0, $s1
  lw    $a2, 0x14($a3)
.L7F003EC4:
  beql  $a2, $zero, .L7F003F08
   lw    $v0, 0x10($a3)
  lw    $t3, ($a2)
  move  $a1, $zero
  move  $v0, $a2
  beql  $t3, $zero, .L7F003F08
   lw    $v0, 0x10($a3)
  lw    $v1, ($a2)
  addu  $t4, $v1, $s1
.L7F003EE8:
  sw    $t4, ($v0)
  lw    $t5, 0x14($a3)
  addiu $a1, $a1, 8
  addu  $v0, $t5, $a1
  lw    $v1, ($v0)
  bnezl $v1, .L7F003EE8
   addu  $t4, $v1, $s1
  lw    $v0, 0x10($a3)
.L7F003F08:
  beql  $v0, $zero, .L7F003F8C
   lw    $t2, 0x18($a3)
  lw    $t6, ($v0)
  move  $a1, $zero
  move  $a2, $v0
  beql  $t6, $zero, .L7F003F8C
   lw    $t2, 0x18($a3)
  lw    $a0, ($v0)
  addu  $t7, $a0, $s1
.L7F003F2C:
  sw    $t7, ($a2)
  lw    $t8, 0x10($a3)
  move  $v1, $zero
  addu  $a2, $t8, $a1
  lw    $a0, ($a2)
  lw    $t0, ($a0)
  move  $v0, $a0
  bltzl $t0, .L7F003F70
   sh    $v1, 6($a2)
  lw    $t1, 4($v0)
.L7F003F54:
  addiu $v1, $v1, 1
  addiu $v0, $v0, 4
  bgezl $t1, .L7F003F54
   lw    $t1, 4($v0)
  lui   $a3, %hi(ptr_setup_path_tbl)
  addiu $a3, %lo(ptr_setup_path_tbl) # addiu $a3, $a3, 0x5d00
  sh    $v1, 6($a2)
.L7F003F70:
  lw    $t9, 0x10($a3)
  addiu $a1, $a1, 8
  addu  $a2, $t9, $a1
  lw    $a0, ($a2)
  bnezl $a0, .L7F003F2C
   addu  $t7, $a0, $s1
  lw    $t2, 0x18($a3)
.L7F003F8C:
  beqz  $t2, .L7F004004
   nop   
  jal   get_room_data_float2
   nop   
  lui   $s0, %hi(ptr_0xxxpresets)
  lw    $s0, %lo(ptr_0xxxpresets)($s0)
  mov.s $f2, $f0
  lw    $v0, 0x24($s0)
  beqz  $v0, .L7F004004
   nop   
  lwc1  $f6, ($s0)
.L7F003FB8:
  lwc1  $f10, 4($s0)
  lwc1  $f18, 8($s0)
  mul.s $f8, $f6, $f2
  addu  $a1, $s1, $v0
  sw    $a1, 0x24($s0)
  mul.s $f16, $f10, $f2
  move  $a0, $s0
  addiu $a2, $s0, 0x28
  mul.s $f4, $f18, $f2
  swc1  $f8, ($s0)
  swc1  $f16, 4($s0)
  swc1  $f4, 8($s0)
  jal   init_pathtable_something
   swc1  $f2, 0x15c($sp)
  lw    $v0, 0x50($s0)
  addiu $s0, $s0, 0x2c
  lwc1  $f2, 0x15c($sp)
  bnezl $v0, .L7F003FB8
   lwc1  $f6, ($s0)
.L7F004004:
  lui   $a3, %hi(ptr_setup_path_tbl)
  addiu $a3, %lo(ptr_setup_path_tbl) # addiu $a3, $a3, 0x5d00
  lw    $t4, 0x1c($a3)
  beql  $t4, $zero, .L7F0040E0
   lw    $a1, 0x20($a3)
  jal   get_room_data_float2
   nop   
  lui   $a3, %hi(ptr_setup_path_tbl)
  addiu $a3, %lo(ptr_setup_path_tbl) # addiu $a3, $a3, 0x5d00
  lw    $s0, 0x1c($a3)
  mov.s $f2, $f0
  lw    $v0, 0x24($s0)
  beql  $v0, $zero, .L7F0040E0
   lw    $a1, 0x20($a3)
  lwc1  $f6, ($s0)
.L7F004040:
  lwc1  $f10, 4($s0)
  lwc1  $f18, 8($s0)
  mul.s $f8, $f6, $f2
  lwc1  $f6, 0x2c($s0)
  addu  $a1, $s1, $v0
  mul.s $f16, $f10, $f2
  lwc1  $f10, 0x30($s0)
  sw    $a1, 0x24($s0)
  mul.s $f4, $f18, $f2
  swc1  $f8, ($s0)
  lwc1  $f18, 0x34($s0)
  mul.s $f8, $f6, $f2
  swc1  $f16, 4($s0)
  lwc1  $f6, 0x38($s0)
  mul.s $f16, $f10, $f2
  swc1  $f4, 8($s0)
  lwc1  $f10, 0x3c($s0)
  mul.s $f4, $f18, $f2
  swc1  $f8, 0x2c($s0)
  lwc1  $f18, 0x40($s0)
  mul.s $f8, $f6, $f2
  swc1  $f16, 0x30($s0)
  move  $a0, $s0
  mul.s $f16, $f10, $f2
  swc1  $f4, 0x34($s0)
  addiu $a2, $s0, 0x28
  mul.s $f4, $f18, $f2
  swc1  $f8, 0x38($s0)
  swc1  $f16, 0x3c($s0)
  swc1  $f4, 0x40($s0)
  jal   init_pathtable_something
   swc1  $f2, 0x150($sp)
  lw    $v0, 0x68($s0)
  addiu $s0, $s0, 0x44
  lwc1  $f2, 0x150($sp)
  bnezl $v0, .L7F004040
   lwc1  $f6, ($s0)
  lui   $a3, %hi(ptr_setup_path_tbl)
  addiu $a3, %lo(ptr_setup_path_tbl) # addiu $a3, $a3, 0x5d00
  lw    $a1, 0x20($a3)
.L7F0040E0:
  beql  $a1, $zero, .L7F004124
   lw    $a1, 0x24($a3)
  lw    $t6, ($a1)
  move  $v0, $zero
  move  $v1, $a1
  beql  $t6, $zero, .L7F004124
   lw    $a1, 0x24($a3)
  lw    $a0, ($a1)
  addu  $t7, $a0, $s1
.L7F004104:
  sw    $t7, ($v1)
  lw    $t8, 0x20($a3)
  addiu $v0, $v0, 4
  addu  $v1, $t8, $v0
  lw    $a0, ($v1)
  bnezl $a0, .L7F004104
   addu  $t7, $a0, $s1
  lw    $a1, 0x24($a3)
.L7F004124:
  beql  $a1, $zero, .L7F004164
   lw    $t2, 0x278($sp)
  lw    $t0, ($a1)
  move  $v0, $zero
  move  $v1, $a1
  beqz  $t0, .L7F004160
   move  $a0, $t0
  addu  $t1, $a0, $s1
.L7F004144:
  sw    $t1, ($v1)
  lw    $t9, 0x24($a3)
  addiu $v0, $v0, 4
  addu  $v1, $t9, $v0
  lw    $a0, ($v1)
  bnezl $a0, .L7F004144
   addu  $t1, $a0, $s1
.L7F004160:
  lw    $t2, 0x278($sp)
.L7F004164:
  beqz  $t2, .L7F0041B0
   nop   
  jal   load_proptype
   li    $a0, 9
  jal   alloc_init_GUARDdata_entries
   move  $a0, $v0
  jal   load_proptype
   li    $a0, 9
  move  $s4, $v0
  jal   load_proptype
   li    $a0, 8
  move  $s3, $v0
  jal   load_proptype
   li    $a0, 4
  addu  $s3, $s3, $v0
  jal   load_proptype
   li    $a0, 17
  b     .L7F0041B8
   addu  $s3, $s3, $v0
.L7F0041B0:
  jal   alloc_init_GUARDdata_entries
   move  $a0, $zero
.L7F0041B8:
  beqz  $fp, .L7F0042A4
   nop   
  jal   load_proptype
   li    $a0, 1
  addu  $s3, $s3, $v0
  jal   load_proptype
   li    $a0, 6
  addu  $s3, $s3, $v0
  jal   load_proptype
   li    $a0, 13
  addu  $s3, $s3, $v0
  jal   load_proptype
   li    $a0, 12
  addu  $s3, $s3, $v0
  jal   load_proptype
   li    $a0, 10
  addu  $s3, $s3, $v0
  jal   load_proptype
   li    $a0, 11
  addu  $s3, $s3, $v0
  jal   load_proptype
   li    $a0, 21
  addu  $s3, $s3, $v0
  jal   load_proptype
   li    $a0, 3
  addu  $s3, $s3, $v0
  jal   load_proptype
   li    $a0, 42
  addu  $s3, $s3, $v0
  jal   load_proptype
   li    $a0, 47
  addu  $s3, $s3, $v0
  jal   load_proptype
   li    $a0, 43
  addu  $s3, $s3, $v0
  jal   load_proptype
   li    $a0, 41
  addu  $s3, $s3, $v0
  jal   load_proptype
   li    $a0, 36
  addu  $s3, $s3, $v0
  jal   load_proptype
   li    $a0, 5
  addu  $s3, $s3, $v0
  jal   load_proptype
   li    $a0, 7
  addu  $s3, $s3, $v0
  jal   load_proptype
   li    $a0, 20
  addu  $s3, $s3, $v0
  jal   load_proptype
   li    $a0, 39
  addu  $s3, $s3, $v0
  jal   load_proptype
   li    $a0, 45
  addu  $s3, $s3, $v0
  jal   load_proptype
   li    $a0, 40
  addu  $s4, $s4, $v0
.L7F0042A4:
  jal   sub_GAME_7F005540
   move  $a0, $s3
  jal   sub_GAME_7F005624
   move  $a0, $s4
  jal   getPlayerCount
   move  $s0, $zero
  blez  $v0, .L7F0042F0
   nop   
.L7F0042C4:
  jal   set_cur_player
   move  $a0, $s0
  jal   load_proptype
   li    $a0, 14
  jal   alloc_additional_item_slots
   move  $a0, $v0
  jal   getPlayerCount
   addiu $s0, $s0, 1
  slt   $at, $s0, $v0
  bnez  $at, .L7F0042C4
   nop   
.L7F0042F0:
  lui   $t3, %hi(ptr_setup_objects) 
  lw    $t3, %lo(ptr_setup_objects)($t3)
  beqz  $t3, .L7F004E78
   nop   
  jal   get_current_difficulty
   nop   
  addiu $t4, $v0, 4
  li    $t5, 1
  jal   getPlayerCount
   sllv  $s4, $t5, $t4
  slti  $at, $v0, 2
  bnez  $at, .L7F00433C
   nop   
  jal   getPlayerCount
   nop   
  addiu $t6, $v0, 0x14
  li    $t7, 1
  sllv  $t8, $t7, $t6
  or    $s4, $s4, $t8
.L7F00433C:
  lui   $s2, %hi(ptr_setup_objects)
  lw    $s2, %lo(ptr_setup_objects)($s2)
  li    $at, 48
  move  $s3, $zero
  lbu   $v1, 3($s2)
  li    $s7, 52
  beql  $v1, $at, .L7F004B30
   lbu   $v1, 3($s2)
  mtc1  $zero, $f20
  li    $s6, 65535
  addiu $t0, $v1, -1
.L7F004368:
  sltiu $at, $t0, 0x2f
  beqz  $at, other_obj_expand
   sll   $t0, $t0, 2
  lui   $at, %hi(jpt_object_type_expansion)
  addu  $at, $at, $t0
  lw    $t0, %lo(jpt_object_type_expansion)($at)
  jr    $t0
   nop   
actor_attr_expand:
  lbu   $s0, 0xb($s2)
  jal   check_if_guardnum_loaded_get_ptr_GUARDdata
   lw    $a0, 4($s2)
  beqz  $v0, other_obj_expand
   nop   
  lw    $t1, 0x18($v0)
  beqz  $t1, other_obj_expand
   nop   
  lw    $t9, 0x1c($v0)
  beqz  $t9, other_obj_expand
   nop   
  b     other_obj_expand
   sb    $s0, 0x10($v0)
actor_expand:
  lw    $t2, 0x278($sp)
  move  $a0, $s5
  move  $a1, $s2
  beqz  $t2, other_obj_expand
   nop   
  jal   expand_09_characters
   move  $a2, $s3
  b     other_obj_expand
   nop   
door_expand:
  beqz  $fp, other_obj_expand
   nop   
  lw    $t3, 0xc($s2)
  move  $a0, $s5
  move  $a1, $s2
  and   $t5, $t3, $s4
  bnez  $t5, other_obj_expand
   nop   
  jal   sub_GAME_7F003480
   move  $a2, $s3
  b     other_obj_expand
   nop   
door_scale_expand:
  lw    $t4, 4($s2)
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f10
  mtc1  $t4, $f6
  lui   $at, %hi(scale_1_0_item_related)
  cvt.s.w $f8, $f6
  div.s $f16, $f8, $f10
  b     other_obj_expand
   swc1  $f16, %lo(scale_1_0_item_related)($at)
item_expand:
  lw    $t7, 0x278($sp)
  beqz  $t7, other_obj_expand
   nop   
  lw    $t6, 0xc($s2)
  move  $a0, $s5
  move  $a1, $s2
  and   $t8, $t6, $s4
  bnez  $t8, other_obj_expand
   nop   
  jal   expand_08_obj_set_guard_MP_weapons
   move  $a2, $s3
  b     other_obj_expand
   nop   
key_expand:
  lw    $t0, 0x278($sp)
  beqz  $t0, other_obj_expand
   nop   
  lw    $t1, 0xc($s2)
  move  $a0, $s5
  move  $a1, $s2
  and   $t9, $t1, $s4
  bnez  $t9, other_obj_expand
   nop   
  jal   jmp_prepare_load_objects
   move  $a2, $s3
  b     other_obj_expand
   nop   
hat_expand:
  lw    $t2, 0x278($sp)
  beqz  $t2, other_obj_expand
   nop   
  lw    $t3, 0xc($s2)
  move  $a0, $s5
  move  $a1, $s2
  and   $t5, $t3, $s4
  bnez  $t5, other_obj_expand
   nop   
  jal   MP_weapon_expansion_routine
   move  $a2, $s3
  b     other_obj_expand
   nop   
surv_camera_expand:
  beqz  $fp, other_obj_expand
   nop   
  lw    $t4, 0xc($s2)
  move  $a0, $s5
  move  $a1, $s2
  and   $t7, $t4, $s4
  bnez  $t7, other_obj_expand
   nop   
  jal   sub_GAME_7F002A3C
   move  $a2, $s3
  b     other_obj_expand
   nop   
autogun_expand:
  beqz  $fp, other_obj_expand
   nop   
  lw    $t6, 0xc($s2)
  move  $a0, $s5
  move  $a1, $s2
  and   $t8, $t6, $s4
  bnez  $t8, other_obj_expand
   nop   
  jal   expand_type_0D_object_autoturret
   move  $a2, $s3
  b     other_obj_expand
   nop   
rack_expand:
  beqz  $fp, other_obj_expand
   nop   
  lw    $t0, 0xc($s2)
  move  $a0, $s5
  move  $a1, $s2
  and   $t1, $t0, $s4
  bnez  $t1, other_obj_expand
   nop   
  jal   jmp_prepare_load_objects_0
   move  $a2, $s3
  b     other_obj_expand
   nop   
single_screen_display_expand:
  beqz  $fp, other_obj_expand
   nop   
  lw    $t9, 0xc($s2)
  move  $a0, $s5
  move  $a1, $s2
  and   $t2, $t9, $s4
  bnez  $t2, other_obj_expand
   nop   
  jal   sub_GAME_7F002E3C
   move  $a2, $s3
  b     other_obj_expand
   nop   
multi_screen_display_expand:
  beqz  $fp, other_obj_expand
   nop   
  lw    $t3, 0xc($s2)
  move  $a0, $s5
  move  $a1, $s2
  and   $t5, $t3, $s4
  bnez  $t5, other_obj_expand
   nop   
  jal   sub_GAME_7F0030D0
   move  $a2, $s3
  b     other_obj_expand
   nop   
body_armor_expand:
  beqz  $fp, other_obj_expand
   nop   
  lw    $t4, 0xc($s2)
  and   $t7, $t4, $s4
  bnez  $t7, other_obj_expand
   nop   
  lw    $t6, 0x80($s2)
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f6
  mtc1  $t6, $f18
  move  $a0, $s5
  move  $a1, $s2
  cvt.s.w $f4, $f18
  move  $a2, $s3
  div.s $f8, $f4, $f6
  swc1  $f8, 0x80($s2)
  lwc1  $f10, 0x80($s2)
  jal   prepare_load_objects
   swc1  $f10, 0x84($s2)
  b     other_obj_expand
   nop   
type2F_tinted_glass:
  beqz  $fp, other_obj_expand
   nop   
  lw    $t8, 0xc($s2)
  and   $t0, $t8, $s4
  bnez  $t0, other_obj_expand
   nop   
  lw    $t1, 8($s2)
  sll   $t9, $t1, 3
  bgezl $t9, .L7F00471C
   move  $a0, $s5
  lh    $v0, 6($s2)
  lui   $t3, %hi(ptr_2xxxpresets) 
  addiu $a1, $sp, 0x118
  slti  $at, $v0, 0x2710
  bnez  $at, .L7F004718
   sll   $t2, $v0, 4
  lw    $t3, %lo(ptr_2xxxpresets)($t3)
  addu  $t2, $t2, $v0
  sll   $t2, $t2, 2
  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
  addu  $s0, $t2, $t3
  addu  $s0, $s0, $at
  jal   sub_GAME_7F001BD4
   move  $a0, $s0
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f0
  lwc1  $f16, 0xc($s0)
  lwc1  $f4, 0x118($sp)
  addiu $a0, $sp, 0x118
  mul.s $f18, $f16, $f0
  lwc1  $f16, 0x11c($sp)
  addiu $a1, $sp, 0x10c
  add.s $f6, $f18, $f4
  swc1  $f6, 0x10c($sp)
  lwc1  $f8, 0x10($s0)
  mul.s $f10, $f8, $f0
  add.s $f18, $f10, $f16
  lwc1  $f10, 0x120($sp)
  swc1  $f18, 0x110($sp)
  lwc1  $f6, 0x14($s0)
  mul.s $f8, $f6, $f0
  add.s $f18, $f8, $f10
  swc1  $f18, 0x114($sp)
  lwc1  $f6, 0xc($s0)
  mul.s $f8, $f0, $f6
  sub.s $f18, $f4, $f8
  swc1  $f18, 0x118($sp)
  lwc1  $f6, 0x10($s0)
  mul.s $f4, $f0, $f6
  sub.s $f8, $f16, $f4
  swc1  $f8, 0x11c($sp)
  lwc1  $f18, 0x14($s0)
  mul.s $f6, $f0, $f18
  sub.s $f16, $f10, $f6
  jal   sub_GAME_7F0B9E04
   swc1  $f16, 0x120($sp)
  lw    $t5, 0x90($s2)
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f18
  mtc1  $t5, $f4
  sw    $v0, 0x8c($s2)
  cvt.s.w $f8, $f4
  div.s $f10, $f8, $f18
  swc1  $f10, 0x90($s2)
.L7F004718:
  move  $a0, $s5
.L7F00471C:
  move  $a1, $s2
  jal   prepare_load_objects
   move  $a2, $s3
  b     other_obj_expand
   nop   
obj_03_expand:
  beqz  $fp, other_obj_expand
   nop   
  lw    $t4, 0xc($s2)
  move  $a0, $s5
  move  $a1, $s2
  and   $t7, $t4, $s4
  bnez  $t7, other_obj_expand
   nop   
  jal   prepare_load_objects
   move  $a2, $s3
  b     other_obj_expand
   nop   
ammo_box_expand:
  jal   getPlayerCount
   li    $s0, 1
  slti  $at, $v0, 2
  bnez  $at, .L7F0047A8
   nop   
  jal   get_ptr_mp_weapon_set_data
   nop   
  lui   $t6, %hi(lastmpweaponnum) 
  lw    $t6, %lo(lastmpweaponnum)($t6)
  sll   $t8, $t6, 2
  subu  $t8, $t8, $t6
  sll   $t8, $t8, 3
  addu  $v1, $v0, $t8
  lw    $a0, 0xc($v1)
  lw    $s0, 0x10($v1)
  sll   $t0, $a0, 2
  addu  $t1, $s2, $t0
  sh    $s0, 0x7e($t1)
.L7F0047A8:
  blez  $s0, other_obj_expand
   nop   
  beqz  $fp, other_obj_expand
   nop   
  lw    $t9, 0xc($s2)
  move  $s1, $zero
  move  $s0, $s2
  and   $t2, $t9, $s4
  bnez  $t2, other_obj_expand
   nop   
.L7F0047D0:
  lhu   $t3, 0x82($s0)
  blezl $t3, .L7F0047F4
   addiu $s1, $s1, 4
  lhu   $a0, 0x80($s0)
  beql  $s6, $a0, .L7F0047F4
   addiu $s1, $s1, 4
  jal   load_model
   nop   
  addiu $s1, $s1, 4
.L7F0047F4:
  bne   $s1, $s7, .L7F0047D0
   addiu $s0, $s0, 4
  move  $a0, $s5
  move  $a1, $s2
  jal   prepare_load_objects
   move  $a2, $s3
  b     other_obj_expand
   nop   
type2D_tank:
  beqz  $fp, other_obj_expand
   nop   
  lw    $t5, 0xc($s2)
  li    $a0, 32
  and   $t4, $t5, $s4
  bnez  $t4, other_obj_expand
   nop   
  jal   set_weapon_model_generated_thrown_object
   swc1  $f20, 0xe8($sp)
  move  $a0, $s5
  move  $a1, $s2
  jal   prepare_load_objects
   move  $a2, $s3
  swc1  $f20, 0xc8($s2)
  swc1  $f20, 0xcc($s2)
  lwc1  $f12, 0x38($s2)
  jal   convert_angle_using_inverse
   lwc1  $f14, 0x40($s2)
  lui   $at, %hi(D_8004F024)
  lwc1  $f6, %lo(D_8004F024)($at)
  lw    $v0, 0x10($s2)
  sub.s $f16, $f6, $f0
  beqz  $v0, .L7F004888
   swc1  $f16, 0xdc($s2)
  lw    $a0, 0x14($v0)
  lw    $a1, 8($v0)
  jal   sub_GAME_7F0B2970
   lw    $a2, 0x10($v0)
  swc1  $f0, 0xe8($sp)
.L7F004888:
  lwc1  $f2, 0xe8($sp)
  lui   $at, %hi(D_8004F028)
  swc1  $f2, 0xd4($s2)
  lwc1  $f4, %lo(D_8004F028)($at)
  div.s $f8, $f2, $f4
  b     other_obj_expand
   swc1  $f8, 0xd0($s2)
type27_wheeled_vehicle:
  beqz  $fp, other_obj_expand
   nop   
  lw    $t7, 0xc($s2)
  move  $a0, $s5
  move  $a1, $s2
  and   $t6, $t7, $s4
  bnez  $t6, other_obj_expand
   nop   
  jal   prepare_load_objects
   move  $a2, $s3
  lw    $a0, 0x14($s2)
  beql  $a0, $zero, .L7F00490C
   lui   $at, 0xbf80
  lw    $t8, 8($a0)
  lw    $t0, 8($t8)
  lw    $a1, 0x14($t0)
  beql  $a1, $zero, .L7F00490C
   lui   $at, 0xbf80
  jal   extract_id_from_object_structure_microcode
   nop   
  lw    $t1, 8($s2)
  li    $at, 0x10000000 # 0.000000
  and   $t9, $t1, $at
  sltiu $t2, $t9, 1
  sw    $t2, ($v0)
  li    $at, 0xBF800000 # -1.000000
.L7F00490C:
  mtc1  $at, $f18
  swc1  $f20, 0x88($s2)
  swc1  $f20, 0x8c($s2)
  swc1  $f20, 0x90($s2)
  swc1  $f20, 0x94($s2)
  swc1  $f20, 0x9c($s2)
  swc1  $f20, 0xa0($s2)
  lw    $a0, 0x80($s2)
  jal   LoadNext_PrevActionBlock
   swc1  $f18, 0x98($s2)
  li    $t3, -1
  sw    $v0, 0x80($s2)
  sh    $zero, 0x84($s2)
  sh    $t3, 0x86($s2)
  sw    $zero, 0xa4($s2)
  sw    $zero, 0xa8($s2)
  b     other_obj_expand
   sw    $zero, 0xac($s2)
type28_aircraft:
  beqz  $fp, other_obj_expand
   nop   
  lw    $t5, 0xc($s2)
  move  $a0, $s5
  move  $a1, $s2
  and   $t4, $t5, $s4
  bnez  $t4, other_obj_expand
   nop   
  jal   prepare_load_objects
   move  $a2, $s3
  li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f0
  swc1  $f20, 0x98($s2)
  swc1  $f20, 0x9c($s2)
  swc1  $f20, 0x88($s2)
  swc1  $f20, 0x8c($s2)
  swc1  $f20, 0x90($s2)
  swc1  $f20, 0xa4($s2)
  lw    $a0, 0x80($s2)
  swc1  $f0, 0xa0($s2)
  jal   LoadNext_PrevActionBlock
   swc1  $f0, 0x94($s2)
  li    $t7, -1
  sw    $v0, 0x80($s2)
  sh    $zero, 0x84($s2)
  sh    $t7, 0x86($s2)
  sw    $zero, 0xa8($s2)
  sw    $zero, 0xac($s2)
  b     other_obj_expand
   sw    $zero, 0xb0($s2)
tag_expand:
  lh    $t6, 6($s2)
  move  $a0, $s5
  jal   sub_GAME_7F056EA0
   addu  $a1, $t6, $s3
  beqz  $v0, .L7F0049F0
   sw    $v0, 0xc($s2)
  lw    $t8, 0x64($v0)
  ori   $t0, $t8, 0x10
  sw    $t0, 0x64($v0)
.L7F0049F0:
  jal   set_parent_cur_tag_entry
   move  $a0, $s2
  b     other_obj_expand
   nop   
type25_rename:
  lw    $t1, 4($s2)
  move  $a0, $s5
  jal   sub_GAME_7F056EA0
   addu  $a1, $t1, $s3
  beqz  $v0, .L7F004A24
   sw    $v0, 0x24($s2)
  lw    $t9, 0x64($v0)
  ori   $t2, $t9, 0x400
  sw    $t2, 0x64($v0)
.L7F004A24:
  jal   sub_GAME_7F08D8A0
   move  $a0, $s2
  b     other_obj_expand
   nop   
type23_solo_brief_text:
  jal   setup_briefing_text_entry_parent
   move  $a0, $s2
  b     other_obj_expand
   nop   
type2E_viewport_pos:
  lw    $t3, 4($s2)
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f0
  mtc1  $t3, $f10
  lw    $t4, 0xc($s2)
  lw    $t5, 8($s2)
  cvt.s.w $f6, $f10
  mtc1  $t4, $f10
  mtc1  $t5, $f4
  lw    $t7, 0x10($s2)
  lw    $t6, 0x14($s2)
  cvt.s.w $f8, $f4
  mtc1  $t7, $f4
  li    $at, 0x47800000 # 65536.000000
  div.s $f16, $f6, $f0
  cvt.s.w $f6, $f10
  div.s $f18, $f8, $f0
  swc1  $f16, 4($s2)
  cvt.s.w $f8, $f4
  mtc1  $at, $f4
  div.s $f16, $f6, $f0
  mtc1  $t6, $f6
  swc1  $f18, 8($s2)
  mtc1  $at, $f18
  nop   
  div.s $f10, $f8, $f18
  swc1  $f16, 0xc($s2)
  cvt.s.w $f16, $f6
  div.s $f8, $f16, $f4
  swc1  $f10, 0x10($s2)
  b     other_obj_expand
   swc1  $f8, 0x14($s2)
type17_objective_expand:
  jal   add_ptr_to_objective
   move  $a0, $s2
  b     other_obj_expand
   nop   
type20_subobjective_expand:
  jal   set_parent_cur_obj_enter_room
   move  $a0, $s2
  b     other_obj_expand
   nop   
type21_subobjective_expand:
  jal   set_parent_cur_obj_deposited_in_room
   move  $a0, $s2
  b     other_obj_expand
   nop   
type1E_subobjective_expand:
  jal   set_parent_cur_obj_photograph
   move  $a0, $s2
other_obj_expand:
  jal   get_size_of_setup_object_type
   move  $a0, $s2
  sll   $t8, $v0, 2
  addu  $s2, $t8, $s2
  lbu   $v1, 3($s2)
  li    $at, 48
  addiu $s3, $s3, 1
  bnel  $v1, $at, .L7F004368
   addiu $t0, $v1, -1
  lui   $s2, %hi(ptr_setup_objects)
  lw    $s2, %lo(ptr_setup_objects)($s2)
  move  $s3, $zero
  lbu   $v1, 3($s2)
.L7F004B30:
  li    $at, 48
  lui   $s7, 8
  beq   $v1, $at, .L7F004E78
   li    $s6, 8
  li    $fp, 43
  li    $s4, 1
  addiu $t0, $v1, -3
.L7F004B4C:
  sltiu $at, $t0, 0x2d
  beqz  $at, .L7F004DE4
   sll   $t0, $t0, 2
  lui   $at, %hi(jpt_8004F02C)
  addu  $at, $at, $t0
  lw    $t0, %lo(jpt_8004F02C)($at)
  jr    $t0
   nop   
.L7F004B6C:
  lw    $t1, 0x10($s2)
  beqz  $t1, .L7F004DE4
   nop   
  lw    $t9, 8($s2)
  andi  $t2, $t9, 0x8000
  beqz  $t2, .L7F004DE4
   nop   
  lh    $v0, 6($s2)
  move  $a0, $s5
  jal   sub_GAME_7F056EA0
   addu  $a1, $s3, $v0
  beqz  $v0, .L7F004DE4
   move  $s0, $v0
  lw    $t3, 0x10($v0)
  beqz  $t3, .L7F004DE4
   nop   
  lw    $t5, 0x64($s2)
  lw    $a0, 0x14($s2)
  or    $t4, $t5, $s7
  sw    $t4, 0x64($s2)
  jal   set_obj_instance_controller_scale
   lw    $a1, 0x14($a0)
  lw    $a0, 0x10($s2)
  jal   sub_GAME_7F03A5A4
   lw    $a1, 0x10($s0)
  b     .L7F004DE4
   nop   
.L7F004BD8:
  lw    $t7, 4($s2)
  jal   sub_GAME_7F056A88
   addu  $a0, $t7, $s3
  lw    $t6, 8($s2)
  move  $s0, $v0
  jal   sub_GAME_7F056A88
   addu  $a0, $t6, $s3
  beqz  $s0, .L7F004DE4
   move  $a1, $v0
  beqz  $v0, .L7F004DE4
   nop   
  lbu   $t8, 3($s0)
  bne   $s6, $t8, .L7F004DE4
   nop   
  lbu   $t0, 3($v0)
  bne   $s6, $t0, .L7F004DE4
   nop   
  jal   link_objects
   move  $a0, $s0
  b     .L7F004DE4
   nop   
.L7F004C2C:
  lw    $v0, 4($s2)
  lw    $s1, 8($s2)
  move  $a0, $s5
  jal   sub_GAME_7F056EA0
   addu  $a1, $s3, $v0
  move  $s0, $v0
  jal   sub_GAME_7F056A88
   addu  $a0, $s3, $s1
  beqz  $s0, .L7F004DE4
   nop   
  lw    $v1, 0x10($s0)
  beqz  $v1, .L7F004DE4
   nop   
  beqz  $v0, .L7F004DE4
   nop   
  lbu   $t1, 3($v0)
  bne   $s4, $t1, .L7F004DE4
   nop   
  lw    $t9, 0x10($v0)
  beqz  $t9, .L7F004DE4
   nop   
  sw    $v1, 4($s2)
  lw    $t2, 0x10($v0)
  move  $a0, $s2
  jal   sub_GAME_7F001910
   sw    $t2, 8($s2)
  lw    $t3, 0x64($s0)
  ori   $t5, $t3, 1
  b     .L7F004DE4
   sw    $t5, 0x64($s0)
.L7F004CA4:
  lw    $v0, 4($s2)
  lw    $t4, 0xc($s2)
  lw    $s1, 8($s2)
  move  $a0, $s5
  addu  $a1, $s3, $v0
  jal   sub_GAME_7F056EA0
   sw    $t4, 0x80($sp)
  move  $s0, $v0
  move  $a0, $s5
  jal   sub_GAME_7F056EA0
   addu  $a1, $s3, $s1
  lw    $t7, 0x80($sp)
  move  $s1, $v0
  move  $a0, $s5
  jal   sub_GAME_7F056EA0
   addu  $a1, $s3, $t7
  beqz  $s0, .L7F004DE4
   nop   
  lw    $t6, 0x10($s0)
  beqz  $t6, .L7F004DE4
   nop   
  beqz  $s1, .L7F004DE4
   nop   
  lw    $t8, 0x10($s1)
  beqz  $t8, .L7F004DE4
   nop   
  lbu   $t0, 3($s1)
  bne   $fp, $t0, .L7F004DE4
   nop   
  beqz  $v0, .L7F004DE4
   nop   
  lw    $t1, 0x10($v0)
  beqz  $t1, .L7F004DE4
   nop   
  lbu   $t9, 3($v0)
  move  $a0, $s2
  bne   $s4, $t9, .L7F004DE4
   nop   
  sw    $s0, 4($s2)
  sw    $s1, 8($s2)
  sw    $v0, 0xc($s2)
  jal   sub_GAME_7F001940
   sw    $v0, 0x74($sp)
  lw    $t2, 0xc($s0)
  lw    $v1, 0x74($sp)
  ori   $t3, $t2, 0x400
  sw    $t3, 0xc($s0)
  lw    $t5, 0xc($v1)
  ori   $t4, $t5, 0x400
  b     .L7F004DE4
   sw    $t4, 0xc($v1)
.L7F004D70:
  lw    $v0, 4($s2)
  lw    $s1, 8($s2)
  move  $a0, $s5
  jal   sub_GAME_7F056EA0
   addu  $a1, $s3, $v0
  move  $s0, $v0
  move  $a0, $s5
  jal   sub_GAME_7F056EA0
   addu  $a1, $s3, $s1
  beqz  $s0, .L7F004DE4
   nop   
  lw    $t7, 0x10($s0)
  beqz  $t7, .L7F004DE4
   nop   
  beqz  $v0, .L7F004DE4
   nop   
  lw    $t6, 0x10($v0)
  beqz  $t6, .L7F004DE4
   nop   
  lbu   $t8, 3($s0)
  move  $a0, $s2
  bne   $s4, $t8, .L7F004DE4
   nop   
  sw    $s0, 4($s2)
  jal   sub_GAME_7F001928
   sw    $v0, 8($s2)
  lw    $t0, 0x64($s0)
  ori   $t1, $t0, 0x2000
  sw    $t1, 0x64($s0)
.L7F004DE4:
  jal   get_size_of_setup_object_type
   move  $a0, $s2
  sll   $t9, $v0, 2
  addu  $s2, $t9, $s2
  lbu   $v1, 3($s2)
  li    $at, 48
  addiu $s3, $s3, 1
  bnel  $v1, $at, .L7F004B4C
   addiu $t0, $v1, -3
  b     .L7F004E78
   nop   
.L7F004E10:
  lui   $at, %hi(ptr_setup_path_tbl)
  sw    $zero, %lo(ptr_setup_path_tbl)($at)
  lui   $at, %hi(ptr_setup_path_link)
  sw    $zero, %lo(ptr_setup_path_link)($at)
  lui   $at, %hi(ptr_setup_intro)
  sw    $zero, %lo(ptr_setup_intro)($at)
  lui   $at, %hi(ptr_setup_objects)
  sw    $zero, %lo(ptr_setup_objects)($at)
  lui   $at, %hi(ptr_setup_path_sets)
  sw    $zero, %lo(ptr_setup_path_sets)($at)
  lui   $at, %hi(ptr_setup_actions)
  sw    $zero, %lo(ptr_setup_actions)($at)
  lui   $at, %hi(ptr_0xxxpresets)
  sw    $zero, %lo(ptr_0xxxpresets)($at)
  lui   $at, %hi(ptr_2xxxpresets)
  sw    $zero, %lo(ptr_2xxxpresets)($at)
  lui   $at, %hi(dword_CODE_bss_80075D20)
  sw    $zero, %lo(dword_CODE_bss_80075D20)($at)
  lui   $at, %hi(dword_CODE_bss_80075D24)
  sw    $zero, %lo(dword_CODE_bss_80075D24)($at)
  jal   alloc_init_GUARDdata_entries
   move  $a0, $zero
  jal   sub_GAME_7F005540
   move  $a0, $zero
  jal   sub_GAME_7F005624
   move  $a0, $zero
.L7F004E78:
  jal   alloc_false_GUARDdata_to_exec_global_action
   nop   
  lw    $ra, 0x44($sp)
  ldc1  $f20, 0x18($sp)
  lw    $s0, 0x20($sp)
  lw    $s1, 0x24($sp)
  lw    $s2, 0x28($sp)
  lw    $s3, 0x2c($sp)
  lw    $s4, 0x30($sp)
  lw    $s5, 0x34($sp)
  lw    $s6, 0x38($sp)
  lw    $s7, 0x3c($sp)
  lw    $fp, 0x40($sp)
  jr    $ra
   addiu $sp, $sp, 0x280
");
#endif

#ifdef VERSION_JP
asm(R"
.late_rodata
glabel jpt_object_type_expansion
.word door_expand
.word door_scale_expand
.word obj_03_expand
.word key_expand
.word obj_03_expand
.word surv_camera_expand
.word obj_03_expand
.word item_expand
.word actor_expand
.word single_screen_display_expand
.word multi_screen_display_expand
.word rack_expand
.word autogun_expand
.word other_obj_expand
.word other_obj_expand
.word other_obj_expand
.word hat_expand
.word actor_attr_expand
.word other_obj_expand
.word ammo_box_expand
.word body_armor_expand
.word tag_expand
.word type17_objective_expand
.word other_obj_expand
.word other_obj_expand
.word other_obj_expand
.word other_obj_expand
.word other_obj_expand
.word other_obj_expand
.word type1E_subobjective_expand
.word other_obj_expand
.word type20_subobjective_expand
.word type21_subobjective_expand
.word other_obj_expand
.word type23_solo_brief_text
.word obj_03_expand
.word type25_rename
.word other_obj_expand
.word type27_wheeled_vehicle
.word type28_aircraft
.word obj_03_expand
.word obj_03_expand
.word obj_03_expand
.word other_obj_expand
.word type2D_tank
.word type2E_viewport_pos
.word type2F_tinted_glass

glabel D_8004F024
.word 0x40c90fdb
glabel D_8004F028
.word 0x3e2e147c

glabel jpt_8004F02C
.word .L7F004B7C
.word .L7F004B7C
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004B7C
.word .L7F004B7C
.word .L7F004DF4
.word .L7F004B7C
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004BE8
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004C3C
.word .L7F004B7C
.word .L7F004B7C
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004B7C
.word .L7F004DF4
.word .L7F004D80
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004B7C
.word .L7F004B7C
.word .L7F004B7C
.word .L7F004CB4
.word .L7F004DF4
.word .L7F004DF4
.word .L7F004B7C


  .text
  glabel proplvreset2
  addiu $sp, $sp, -0x280
  sw    $s5, 0x34($sp)
  move  $s5, $a0
  sw    $ra, 0x44($sp)
  lui   $a1, %hi(aNochr) # $a1, 0x8005
  sw    $fp, 0x40($sp)
  sw    $s7, 0x3c($sp)
  sw    $s6, 0x38($sp)
  sw    $s4, 0x30($sp)
  sw    $s3, 0x2c($sp)
  sw    $s2, 0x28($sp)
  sw    $s1, 0x24($sp)
  sw    $s0, 0x20($sp)
  sdc1  $f20, 0x18($sp)
  addiu $a1, %lo(aNochr) # addiu $a1, $a1, -0x1240
  jal   check_token
   li    $a0, 1
  sltiu $a2, $v0, 1
  beqz  $a2, .L7F003C50
   li    $a0, 1
  lui   $a1, %hi(aNoprop) # $a1, 0x8005
  jal   check_token
   addiu $a1, %lo(aNoprop) # addiu $a1, $a1, -0x1238
  sltiu $a2, $v0, 1
.L7F003C50:
  lui   $a1, %hi(aNoobj) # $a1, 0x8005
  sw    $a2, 0x278($sp)
  addiu $a1, %lo(aNoobj) # addiu $a1, $a1, -0x1230
  jal   check_token
   li    $a0, 1
  sltiu $v1, $v0, 1
  beqz  $v1, .L7F003C80
   li    $a0, 1
  lui   $a1, %hi(aNoprop_0) # $a1, 0x8005
  jal   check_token
   addiu $a1, %lo(aNoprop_0) # addiu $a1, $a1, -0x1228
  sltiu $v1, $v0, 1
.L7F003C80:
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  move  $fp, $v1
  lui   $at, %hi(scale_1_0_item_related) # $at, 0x8003
  lui   $v1, %hi(PitemZ_entries+0xFF0) # $v1, 0x8004
  lui   $v0, %hi(PitemZ_entries) # $v0, 0x8004
  addiu $v0, %lo(PitemZ_entries) # addiu $v0, $v0, -0x5da8
  addiu $v1, %lo(PitemZ_entries+0xFF0) # addiu $v1, $v1, -0x4db8
  swc1  $f4, %lo(scale_1_0_item_related)($at)
.L7F003CA4:
  lw    $t6, ($v0)
  addiu $v0, $v0, 0xc
  sltu  $at, $v0, $v1
  bnez  $at, .L7F003CA4
   sw    $zero, ($t6)
  slti  $at, $s5, 0x3b
  beqz  $at, .L7F004E20
   sll   $t7, $s5, 2
  lui   $t8, %hi(setup_text_pointers) # $t8, 0x8003
  addiu $t8, %lo(setup_text_pointers) # addiu $t8, $t8, 0x7514
  addu  $s0, $t7, $t8
  lw    $v0, ($s0)
  lui   $t9, %hi(only_read_by_stageload) # $t9, 0x8005
  addiu $s1, $sp, 0x174
  beqz  $v0, .L7F004E20
   addiu $t9, %lo(only_read_by_stageload) # addiu $t9, $t9, -0x1220
  move  $t2, $s1
  addiu $t1, $t9, 0xfc
.L7F003CEC:
  lw    $at, ($t9)
  addiu $t9, $t9, 0xc
  addiu $t2, $t2, 0xc
  sw    $at, -0xc($t2)
  lw    $at, -8($t9)
  sw    $at, -8($t2)
  lw    $at, -4($t9)
  bne   $t9, $t1, .L7F003CEC
   sw    $at, -4($t2)
  lw    $at, ($t9)
  move  $s4, $zero
  move  $s3, $zero
  sw    $at, ($t2)
  lbu   $t3, ($v0)
  sb    $zero, 0x175($sp)
  jal   getPlayerCount
   sb    $t3, 0x174($sp)
  slti  $at, $v0, 2
  bnez  $at, .L7F003D48
   lui   $a1, %hi(aMp_) # $a1, 0x8005
  addiu $a1, %lo(aMp_) # addiu $a1, $a1, -0x1120
  jal   string_append_from_obseg_textbank
   move  $a0, $s1
.L7F003D48:
  lw    $a1, ($s0)
  move  $a0, $s1
  jal   string_append_from_obseg_textbank
   addiu $a1, $a1, 1
  move  $a0, $s1
  li    $a1, 1
  li    $a2, 256
  jal   _load_resource_named_to_membank
   li    $a3, 4
  lui   $v1, %hi(dword_CODE_bss_80075D28) # $v1, 0x8007
  addiu $v1, %lo(dword_CODE_bss_80075D28) # addiu $v1, $v1, 0x5d68
  sw    $v0, ($v1)
  move  $s1, $v0
  jal   get_textbank_number_for_stagenum
   move  $a0, $s5
  jal   load_mission_text_bank
   move  $a0, $v0
  lw    $t4, ($s1)
  lui   $a3, %hi(ptr_setup_path_tbl) # $a3, 0x8007
  addiu $a3, %lo(ptr_setup_path_tbl) # addiu $a3, $a3, 0x5d40
  addu  $t5, $s1, $t4
  sw    $t5, ($a3)
  lw    $t6, 4($s1)
  addu  $t7, $s1, $t6
  sw    $t7, 4($a3)
  lw    $t8, 8($s1)
  addu  $t0, $s1, $t8
  sw    $t0, 8($a3)
  lw    $t1, 0xc($s1)
  addu  $t9, $s1, $t1
  sw    $t9, 0xc($a3)
  lw    $t2, 0x10($s1)
  addu  $t3, $s1, $t2
  sw    $t3, 0x10($a3)
  lw    $t4, 0x14($s1)
  addu  $t5, $s1, $t4
  sw    $t5, 0x14($a3)
  lw    $t6, 0x18($s1)
  addu  $t7, $s1, $t6
  sw    $t7, 0x18($a3)
  lw    $t8, 0x1c($s1)
  addu  $t0, $s1, $t8
  sw    $t0, 0x1c($a3)
  lw    $v0, 0x20($s1)
  beqz  $v0, .L7F003E08
   addu  $t1, $s1, $v0
  b     .L7F003E0C
   sw    $t1, 0x20($a3)
.L7F003E08:
  sw    $zero, 0x20($a3)
.L7F003E0C:
  lw    $v0, 0x24($s1)
  beqz  $v0, .L7F003E20
   addu  $t9, $s1, $v0
  b     .L7F003E24
   sw    $t9, 0x24($a3)
.L7F003E20:
  sw    $zero, 0x24($a3)
.L7F003E24:
  lw    $a1, ($a3)
  beql  $a1, $zero, .L7F003E6C
   lw    $a1, 4($a3)
  lw    $t2, ($a1)
  move  $v1, $zero
  move  $v0, $a1
  bltzl $t2, .L7F003E6C
   lw    $a1, 4($a3)
  lw    $t3, 4($v0)
.L7F003E48:
  addiu $v1, $v1, 0x10
  addu  $t4, $t3, $s1
  sw    $t4, 4($v0)
  lw    $t5, ($a3)
  addu  $v0, $t5, $v1
  lw    $t6, ($v0)
  bgezl $t6, .L7F003E48
   lw    $t3, 4($v0)
  lw    $a1, 4($a3)
.L7F003E6C:
  beql  $a1, $zero, .L7F003EC4
   lw    $a2, 0x14($a3)
  lw    $t7, ($a1)
  move  $v1, $zero
  move  $v0, $a1
  beql  $t7, $zero, .L7F003EC4
   lw    $a2, 0x14($a3)
  lw    $a0, ($a1)
  addu  $t8, $a0, $s1
.L7F003E90:
  sw    $t8, ($v0)
  lw    $t0, 4($a3)
  addu  $v0, $t0, $v1
  lw    $t1, 4($v0)
  addiu $v1, $v1, 0xc
  addu  $t9, $t1, $s1
  sw    $t9, 4($v0)
  lw    $t2, 4($a3)
  addu  $v0, $t2, $v1
  lw    $a0, ($v0)
  bnezl $a0, .L7F003E90
   addu  $t8, $a0, $s1
  lw    $a2, 0x14($a3)
.L7F003EC4:
  beql  $a2, $zero, .L7F003F08
   lw    $v0, 0x10($a3)
  lw    $t3, ($a2)
  move  $a1, $zero
  move  $v0, $a2
  beql  $t3, $zero, .L7F003F08
   lw    $v0, 0x10($a3)
  lw    $v1, ($a2)
  addu  $t4, $v1, $s1
.L7F003EE8:
  sw    $t4, ($v0)
  lw    $t5, 0x14($a3)
  addiu $a1, $a1, 8
  addu  $v0, $t5, $a1
  lw    $v1, ($v0)
  bnezl $v1, .L7F003EE8
   addu  $t4, $v1, $s1
  lw    $v0, 0x10($a3)
.L7F003F08:
  beql  $v0, $zero, .L7F003F8C
   lw    $t2, 0x18($a3)
  lw    $t6, ($v0)
  move  $a1, $zero
  move  $a2, $v0
  beql  $t6, $zero, .L7F003F8C
   lw    $t2, 0x18($a3)
  lw    $a0, ($v0)
  addu  $t7, $a0, $s1
.L7F003F2C:
  sw    $t7, ($a2)
  lw    $t8, 0x10($a3)
  move  $v1, $zero
  addu  $a2, $t8, $a1
  lw    $a0, ($a2)
  lw    $t0, ($a0)
  move  $v0, $a0
  bltzl $t0, .L7F003F70
   sh    $v1, 6($a2)
  lw    $t1, 4($v0)
.L7F003F54:
  addiu $v1, $v1, 1
  addiu $v0, $v0, 4
  bgezl $t1, .L7F003F54
   lw    $t1, 4($v0)
  lui   $a3, %hi(ptr_setup_path_tbl) # $a3, 0x8007
  addiu $a3, %lo(ptr_setup_path_tbl) # addiu $a3, $a3, 0x5d40
  sh    $v1, 6($a2)
.L7F003F70:
  lw    $t9, 0x10($a3)
  addiu $a1, $a1, 8
  addu  $a2, $t9, $a1
  lw    $a0, ($a2)
  bnezl $a0, .L7F003F2C
   addu  $t7, $a0, $s1
  lw    $t2, 0x18($a3)
.L7F003F8C:
  beqz  $t2, .L7F004004
   nop   
  jal   get_room_data_float2
   nop   
  lui   $s0, %hi(ptr_0xxxpresets) # $s0, 0x8007
  lw    $s0, %lo(ptr_0xxxpresets)($s0)
  mov.s $f2, $f0
  lw    $v0, 0x24($s0)
  beqz  $v0, .L7F004004
   nop   
  lwc1  $f6, ($s0)
.L7F003FB8:
  lwc1  $f10, 4($s0)
  lwc1  $f18, 8($s0)
  mul.s $f8, $f6, $f2
  addu  $a1, $s1, $v0
  sw    $a1, 0x24($s0)
  mul.s $f16, $f10, $f2
  move  $a0, $s0
  addiu $a2, $s0, 0x28
  mul.s $f4, $f18, $f2
  swc1  $f8, ($s0)
  swc1  $f16, 4($s0)
  swc1  $f4, 8($s0)
  jal   init_pathtable_something
   swc1  $f2, 0x15c($sp)
  lw    $v0, 0x50($s0)
  addiu $s0, $s0, 0x2c
  lwc1  $f2, 0x15c($sp)
  bnezl $v0, .L7F003FB8
   lwc1  $f6, ($s0)
.L7F004004:
  lui   $a3, %hi(ptr_setup_path_tbl) # $a3, 0x8007
  addiu $a3, %lo(ptr_setup_path_tbl) # addiu $a3, $a3, 0x5d40
  lw    $t4, 0x1c($a3)
  beql  $t4, $zero, .L7F0040E0
   lw    $a1, 0x20($a3)
  jal   get_room_data_float2
   nop   
  lui   $a3, %hi(ptr_setup_path_tbl) # $a3, 0x8007
  addiu $a3, %lo(ptr_setup_path_tbl) # addiu $a3, $a3, 0x5d40
  lw    $s0, 0x1c($a3)
  mov.s $f2, $f0
  lw    $v0, 0x24($s0)
  beql  $v0, $zero, .L7F0040E0
   lw    $a1, 0x20($a3)
  lwc1  $f6, ($s0)
.L7F004040:
  lwc1  $f10, 4($s0)
  lwc1  $f18, 8($s0)
  mul.s $f8, $f6, $f2
  lwc1  $f6, 0x2c($s0)
  addu  $a1, $s1, $v0
  mul.s $f16, $f10, $f2
  lwc1  $f10, 0x30($s0)
  sw    $a1, 0x24($s0)
  mul.s $f4, $f18, $f2
  swc1  $f8, ($s0)
  lwc1  $f18, 0x34($s0)
  mul.s $f8, $f6, $f2
  swc1  $f16, 4($s0)
  lwc1  $f6, 0x38($s0)
  mul.s $f16, $f10, $f2
  swc1  $f4, 8($s0)
  lwc1  $f10, 0x3c($s0)
  mul.s $f4, $f18, $f2
  swc1  $f8, 0x2c($s0)
  lwc1  $f18, 0x40($s0)
  mul.s $f8, $f6, $f2
  swc1  $f16, 0x30($s0)
  move  $a0, $s0
  mul.s $f16, $f10, $f2
  swc1  $f4, 0x34($s0)
  addiu $a2, $s0, 0x28
  mul.s $f4, $f18, $f2
  swc1  $f8, 0x38($s0)
  swc1  $f16, 0x3c($s0)
  swc1  $f4, 0x40($s0)
  jal   init_pathtable_something
   swc1  $f2, 0x150($sp)
  lw    $v0, 0x68($s0)
  addiu $s0, $s0, 0x44
  lwc1  $f2, 0x150($sp)
  bnezl $v0, .L7F004040
   lwc1  $f6, ($s0)
  lui   $a3, %hi(ptr_setup_path_tbl) # $a3, 0x8007
  addiu $a3, %lo(ptr_setup_path_tbl) # addiu $a3, $a3, 0x5d40
  lw    $a1, 0x20($a3)
.L7F0040E0:
  beql  $a1, $zero, .L7F004124
   lw    $a1, 0x24($a3)
  lw    $t6, ($a1)
  move  $v0, $zero
  move  $v1, $a1
  beql  $t6, $zero, .L7F004124
   lw    $a1, 0x24($a3)
  lw    $a0, ($a1)
  addu  $t7, $a0, $s1
.L7F004104:
  sw    $t7, ($v1)
  lw    $t8, 0x20($a3)
  addiu $v0, $v0, 4
  addu  $v1, $t8, $v0
  lw    $a0, ($v1)
  bnezl $a0, .L7F004104
   addu  $t7, $a0, $s1
  lw    $a1, 0x24($a3)
.L7F004124:
  beql  $a1, $zero, .L7F004164
   lw    $t2, 0x278($sp)
  lw    $t0, ($a1)
  move  $v0, $zero
  move  $v1, $a1
  beqz  $t0, .L7F004160
   move  $a0, $t0
  addu  $t1, $a0, $s1
.L7F004144:
  sw    $t1, ($v1)
  lw    $t9, 0x24($a3)
  addiu $v0, $v0, 4
  addu  $v1, $t9, $v0
  lw    $a0, ($v1)
  bnezl $a0, .L7F004144
   addu  $t1, $a0, $s1
.L7F004160:
  lw    $t2, 0x278($sp)
.L7F004164:
  beqz  $t2, .L7F0041B0
   nop   
  jal   load_proptype
   li    $a0, 9
  jal   alloc_init_GUARDdata_entries
   move  $a0, $v0
  jal   load_proptype
   li    $a0, 9
  move  $s4, $v0
  jal   load_proptype
   li    $a0, 8
  move  $s3, $v0
  jal   load_proptype
   li    $a0, 4
  addu  $s3, $s3, $v0
  jal   load_proptype
   li    $a0, 17
  b     .L7F0041B8
   addu  $s3, $s3, $v0
.L7F0041B0:
  jal   alloc_init_GUARDdata_entries
   move  $a0, $zero
.L7F0041B8:
  beqz  $fp, .L7F0042A4
   nop   
  jal   load_proptype
   li    $a0, 1
  addu  $s3, $s3, $v0
  jal   load_proptype
   li    $a0, 6
  addu  $s3, $s3, $v0
  jal   load_proptype
   li    $a0, 13
  addu  $s3, $s3, $v0
  jal   load_proptype
   li    $a0, 12
  addu  $s3, $s3, $v0
  jal   load_proptype
   li    $a0, 10
  addu  $s3, $s3, $v0
  jal   load_proptype
   li    $a0, 11
  addu  $s3, $s3, $v0
  jal   load_proptype
   li    $a0, 21
  addu  $s3, $s3, $v0
  jal   load_proptype
   li    $a0, 3
  addu  $s3, $s3, $v0
  jal   load_proptype
   li    $a0, 42
  addu  $s3, $s3, $v0
  jal   load_proptype
   li    $a0, 47
  addu  $s3, $s3, $v0
  jal   load_proptype
   li    $a0, 43
  addu  $s3, $s3, $v0
  jal   load_proptype
   li    $a0, 41
  addu  $s3, $s3, $v0
  jal   load_proptype
   li    $a0, 36
  addu  $s3, $s3, $v0
  jal   load_proptype
   li    $a0, 5
  addu  $s3, $s3, $v0
  jal   load_proptype
   li    $a0, 7
  addu  $s3, $s3, $v0
  jal   load_proptype
   li    $a0, 20
  addu  $s3, $s3, $v0
  jal   load_proptype
   li    $a0, 39
  addu  $s3, $s3, $v0
  jal   load_proptype
   li    $a0, 45
  addu  $s3, $s3, $v0
  jal   load_proptype
   li    $a0, 40
  addu  $s4, $s4, $v0
.L7F0042A4:
  jal   sub_GAME_7F005540
   move  $a0, $s3
  jal   sub_GAME_7F005624
   move  $a0, $s4
  jal   getPlayerCount
   move  $s0, $zero
  blez  $v0, .L7F0042F0
   nop   
.L7F0042C4:
  jal   set_cur_player
   move  $a0, $s0
  jal   load_proptype
   li    $a0, 14
  jal   alloc_additional_item_slots
   move  $a0, $v0
  jal   getPlayerCount
   addiu $s0, $s0, 1
  slt   $at, $s0, $v0
  bnez  $at, .L7F0042C4
   nop   
.L7F0042F0:
  lui   $t3, %hi(ptr_setup_objects) # $t3, 0x8007
  lw    $t3, %lo(ptr_setup_objects)($t3)
  beqz  $t3, .L7F004E88
   nop   
  jal   get_current_difficulty
   nop   
  addiu $t4, $v0, 4
  li    $t5, 1
  jal   getPlayerCount
   sllv  $s4, $t5, $t4
  slti  $at, $v0, 2
  bnez  $at, .L7F00433C
   nop   
  jal   getPlayerCount
   nop   
  addiu $t6, $v0, 0x14
  li    $t7, 1
  sllv  $t8, $t7, $t6
  or    $s4, $s4, $t8
.L7F00433C:
  lui   $s2, %hi(ptr_setup_objects) # $s2, 0x8007
  lw    $s2, %lo(ptr_setup_objects)($s2)
  li    $at, 48
  move  $s3, $zero
  lbu   $v1, 3($s2)
  li    $s7, 52
  beql  $v1, $at, .L7F004B40
   lbu   $v1, 3($s2)
  mtc1  $zero, $f20
  li    $s6, 65535
  addiu $t0, $v1, -1
.L7F004368:
  sltiu $at, $t0, 0x2f
  beqz  $at, other_obj_expand
   sll   $t0, $t0, 2
  lui   $at, %hi(jpt_object_type_expansion)
  addu  $at, $at, $t0
  lw    $t0, %lo(jpt_object_type_expansion)($at)
  jr    $t0
   nop   
actor_attr_expand:
  lbu   $s0, 0xb($s2)
  jal   check_if_guardnum_loaded_get_ptr_GUARDdata
   lw    $a0, 4($s2)
  beqz  $v0, other_obj_expand
   nop   
  lw    $t1, 0x18($v0)
  beqz  $t1, other_obj_expand
   nop   
  lw    $t9, 0x1c($v0)
  beqz  $t9, other_obj_expand
   nop   
  b     other_obj_expand
   sb    $s0, 0x10($v0)
actor_expand:
  lw    $t2, 0x278($sp)
  move  $a0, $s5
  move  $a1, $s2
  beqz  $t2, other_obj_expand
   nop   
  jal   expand_09_characters
   move  $a2, $s3
  b     other_obj_expand
   nop   
door_expand:
  beqz  $fp, other_obj_expand
   nop   
  lw    $t3, 0xc($s2)
  move  $a0, $s5
  move  $a1, $s2
  and   $t5, $t3, $s4
  bnez  $t5, other_obj_expand
   nop   
  jal   sub_GAME_7F003480
   move  $a2, $s3
  b     other_obj_expand
   nop   
door_scale_expand:
  lw    $t4, 4($s2)
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f10
  mtc1  $t4, $f6
  lui   $at, %hi(scale_1_0_item_related) # $at, 0x8003
  cvt.s.w $f8, $f6
  div.s $f16, $f8, $f10
  b     other_obj_expand
   swc1  $f16, %lo(scale_1_0_item_related)($at)
item_expand:
  lw    $t7, 0x278($sp)
  beqz  $t7, other_obj_expand
   nop   
  lw    $t6, 0xc($s2)
  move  $a0, $s5
  move  $a1, $s2
  and   $t8, $t6, $s4
  bnez  $t8, other_obj_expand
   nop   
  jal   expand_08_obj_set_guard_MP_weapons
   move  $a2, $s3
  b     other_obj_expand
   nop   
key_expand:
  lw    $t0, 0x278($sp)
  beqz  $t0, other_obj_expand
   nop   
  lw    $t1, 0xc($s2)
  move  $a0, $s5
  move  $a1, $s2
  and   $t9, $t1, $s4
  bnez  $t9, other_obj_expand
   nop   
  jal   jmp_prepare_load_objects
   move  $a2, $s3
  b     other_obj_expand
   nop   
hat_expand:
  lw    $t2, 0x278($sp)
  beqz  $t2, other_obj_expand
   nop   
  lw    $t3, 0xc($s2)
  move  $a0, $s5
  move  $a1, $s2
  and   $t5, $t3, $s4
  bnez  $t5, other_obj_expand
   nop   
  jal   MP_weapon_expansion_routine
   move  $a2, $s3
  b     other_obj_expand
   nop   
surv_camera_expand:
  beqz  $fp, other_obj_expand
   nop   
  lw    $t4, 0xc($s2)
  move  $a0, $s5
  move  $a1, $s2
  and   $t7, $t4, $s4
  bnez  $t7, other_obj_expand
   nop   
  jal   sub_GAME_7F002A3C
   move  $a2, $s3
  b     other_obj_expand
   nop   
autogun_expand:
  beqz  $fp, other_obj_expand
   nop   
  lw    $t6, 0xc($s2)
  move  $a0, $s5
  move  $a1, $s2
  and   $t8, $t6, $s4
  bnez  $t8, other_obj_expand
   nop   
  jal   expand_type_0D_object_autoturret
   move  $a2, $s3
  b     other_obj_expand
   nop   
rack_expand:
  beqz  $fp, other_obj_expand
   nop   
  lw    $t0, 0xc($s2)
  move  $a0, $s5
  move  $a1, $s2
  and   $t1, $t0, $s4
  bnez  $t1, other_obj_expand
   nop   
  jal   jmp_prepare_load_objects_0
   move  $a2, $s3
  b     other_obj_expand
   nop   
single_screen_display_expand:
  beqz  $fp, other_obj_expand
   nop   
  lw    $t9, 0xc($s2)
  move  $a0, $s5
  move  $a1, $s2
  and   $t2, $t9, $s4
  bnez  $t2, other_obj_expand
   nop   
  jal   sub_GAME_7F002E3C
   move  $a2, $s3
  b     other_obj_expand
   nop   
multi_screen_display_expand:
  beqz  $fp, other_obj_expand
   nop   
  lw    $t3, 0xc($s2)
  move  $a0, $s5
  move  $a1, $s2
  and   $t5, $t3, $s4
  bnez  $t5, other_obj_expand
   nop   
  jal   sub_GAME_7F0030D0
   move  $a2, $s3
  b     other_obj_expand
   nop   
body_armor_expand:
  beqz  $fp, other_obj_expand
   nop   
  lw    $t4, 0xc($s2)
  lui   $t6, %hi(j_text_trigger) # $t6, 0x8005
  and   $t7, $t4, $s4
  beql  $t7, $zero, .L7F0045EC
   lw    $t8, 0x80($s2)
  lw    $t6, %lo(j_text_trigger)($t6)
  beqz  $t6, other_obj_expand
   nop   
  lw    $t8, 0x80($s2)
.L7F0045EC:
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f6
  mtc1  $t8, $f18
  move  $a0, $s5
  move  $a1, $s2
  cvt.s.w $f4, $f18
  move  $a2, $s3
  div.s $f8, $f4, $f6
  swc1  $f8, 0x80($s2)
  lwc1  $f10, 0x80($s2)
  jal   prepare_load_objects
   swc1  $f10, 0x84($s2)
  b     other_obj_expand
   nop   
type2F_tinted_glass:
  beqz  $fp, other_obj_expand
   nop   
  lw    $t0, 0xc($s2)
  and   $t1, $t0, $s4
  bnez  $t1, other_obj_expand
   nop   
  lw    $t9, 8($s2)
  sll   $t2, $t9, 3
  bgezl $t2, .L7F00472C
   move  $a0, $s5
  lh    $v0, 6($s2)
  lui   $t5, %hi(ptr_2xxxpresets) # $t5, 0x8007
  addiu $a1, $sp, 0x118
  slti  $at, $v0, 0x2710
  bnez  $at, .L7F004728
   sll   $t3, $v0, 4
  lw    $t5, %lo(ptr_2xxxpresets)($t5)
  addu  $t3, $t3, $v0
  sll   $t3, $t3, 2
  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
  addu  $s0, $t3, $t5
  addu  $s0, $s0, $at
  jal   sub_GAME_7F001BD4
   move  $a0, $s0
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f0
  lwc1  $f16, 0xc($s0)
  lwc1  $f4, 0x118($sp)
  addiu $a0, $sp, 0x118
  mul.s $f18, $f16, $f0
  lwc1  $f16, 0x11c($sp)
  addiu $a1, $sp, 0x10c
  add.s $f6, $f18, $f4
  swc1  $f6, 0x10c($sp)
  lwc1  $f8, 0x10($s0)
  mul.s $f10, $f8, $f0
  add.s $f18, $f10, $f16
  lwc1  $f10, 0x120($sp)
  swc1  $f18, 0x110($sp)
  lwc1  $f6, 0x14($s0)
  mul.s $f8, $f6, $f0
  add.s $f18, $f8, $f10
  swc1  $f18, 0x114($sp)
  lwc1  $f6, 0xc($s0)
  mul.s $f8, $f0, $f6
  sub.s $f18, $f4, $f8
  swc1  $f18, 0x118($sp)
  lwc1  $f6, 0x10($s0)
  mul.s $f4, $f0, $f6
  sub.s $f8, $f16, $f4
  swc1  $f8, 0x11c($sp)
  lwc1  $f18, 0x14($s0)
  mul.s $f6, $f0, $f18
  sub.s $f16, $f10, $f6
  jal   sub_GAME_7F0B9E04
   swc1  $f16, 0x120($sp)
  lw    $t4, 0x90($s2)
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f18
  mtc1  $t4, $f4
  sw    $v0, 0x8c($s2)
  cvt.s.w $f8, $f4
  div.s $f10, $f8, $f18
  swc1  $f10, 0x90($s2)
.L7F004728:
  move  $a0, $s5
.L7F00472C:
  move  $a1, $s2
  jal   prepare_load_objects
   move  $a2, $s3
  b     other_obj_expand
   nop   
obj_03_expand:
  beqz  $fp, other_obj_expand
   nop   
  lw    $t7, 0xc($s2)
  move  $a0, $s5
  move  $a1, $s2
  and   $t6, $t7, $s4
  bnez  $t6, other_obj_expand
   nop   
  jal   prepare_load_objects
   move  $a2, $s3
  b     other_obj_expand
   nop   
ammo_box_expand:
  jal   getPlayerCount
   li    $s0, 1
  slti  $at, $v0, 2
  bnez  $at, .L7F0047B8
   nop   
  jal   get_ptr_mp_weapon_set_data
   nop   
  lui   $t8, %hi(lastmpweaponnum) # $t8, 0x8007
  lw    $t8, %lo(lastmpweaponnum)($t8)
  sll   $t0, $t8, 2
  subu  $t0, $t0, $t8
  sll   $t0, $t0, 3
  addu  $v1, $v0, $t0
  lw    $a0, 0xc($v1)
  lw    $s0, 0x10($v1)
  sll   $t1, $a0, 2
  addu  $t9, $s2, $t1
  sh    $s0, 0x7e($t9)
.L7F0047B8:
  blez  $s0, other_obj_expand
   nop   
  beqz  $fp, other_obj_expand
   nop   
  lw    $t2, 0xc($s2)
  move  $s1, $zero
  move  $s0, $s2
  and   $t3, $t2, $s4
  bnez  $t3, other_obj_expand
   nop   
.L7F0047E0:
  lhu   $t5, 0x82($s0)
  blezl $t5, .L7F004804
   addiu $s1, $s1, 4
  lhu   $a0, 0x80($s0)
  beql  $s6, $a0, .L7F004804
   addiu $s1, $s1, 4
  jal   load_model
   nop   
  addiu $s1, $s1, 4
.L7F004804:
  bne   $s1, $s7, .L7F0047E0
   addiu $s0, $s0, 4
  move  $a0, $s5
  move  $a1, $s2
  jal   prepare_load_objects
   move  $a2, $s3
  b     other_obj_expand
   nop   
type2D_tank:
  beqz  $fp, other_obj_expand
   nop   
  lw    $t4, 0xc($s2)
  li    $a0, 32
  and   $t7, $t4, $s4
  bnez  $t7, other_obj_expand
   nop   
  jal   set_weapon_model_generated_thrown_object
   swc1  $f20, 0xe8($sp)
  move  $a0, $s5
  move  $a1, $s2
  jal   prepare_load_objects
   move  $a2, $s3
  swc1  $f20, 0xc8($s2)
  swc1  $f20, 0xcc($s2)
  lwc1  $f12, 0x38($s2)
  jal   convert_angle_using_inverse
   lwc1  $f14, 0x40($s2)
  lui   $at, %hi(D_8004F024) # $at, 0x8005
  lwc1  $f6, %lo(D_8004F024)($at)
  lw    $v0, 0x10($s2)
  sub.s $f16, $f6, $f0
  beqz  $v0, .L7F004898
   swc1  $f16, 0xdc($s2)
  lw    $a0, 0x14($v0)
  lw    $a1, 8($v0)
  jal   sub_GAME_7F0B2970
   lw    $a2, 0x10($v0)
  swc1  $f0, 0xe8($sp)
.L7F004898:
  lwc1  $f2, 0xe8($sp)
  lui   $at, %hi(D_8004F028) # $at, 0x8005
  swc1  $f2, 0xd4($s2)
  lwc1  $f4, %lo(D_8004F028)($at)
  div.s $f8, $f2, $f4
  b     other_obj_expand
   swc1  $f8, 0xd0($s2)
type27_wheeled_vehicle:
  beqz  $fp, other_obj_expand
   nop   
  lw    $t6, 0xc($s2)
  move  $a0, $s5
  move  $a1, $s2
  and   $t8, $t6, $s4
  bnez  $t8, other_obj_expand
   nop   
  jal   prepare_load_objects
   move  $a2, $s3
  lw    $a0, 0x14($s2)
  beql  $a0, $zero, .L7F00491C
   lui   $at, 0xbf80
  lw    $t0, 8($a0)
  lw    $t1, 8($t0)
  lw    $a1, 0x14($t1)
  beql  $a1, $zero, .L7F00491C
   lui   $at, 0xbf80
  jal   extract_id_from_object_structure_microcode
   nop   
  lw    $t9, 8($s2)
  li    $at, 0x10000000 # 0.000000
  and   $t2, $t9, $at
  sltiu $t3, $t2, 1
  sw    $t3, ($v0)
  li    $at, 0xBF800000 # -1.000000
.L7F00491C:
  mtc1  $at, $f18
  swc1  $f20, 0x88($s2)
  swc1  $f20, 0x8c($s2)
  swc1  $f20, 0x90($s2)
  swc1  $f20, 0x94($s2)
  swc1  $f20, 0x9c($s2)
  swc1  $f20, 0xa0($s2)
  lw    $a0, 0x80($s2)
  jal   LoadNext_PrevActionBlock
   swc1  $f18, 0x98($s2)
  li    $t5, -1
  sw    $v0, 0x80($s2)
  sh    $zero, 0x84($s2)
  sh    $t5, 0x86($s2)
  sw    $zero, 0xa4($s2)
  sw    $zero, 0xa8($s2)
  b     other_obj_expand
   sw    $zero, 0xac($s2)
type28_aircraft:
  beqz  $fp, other_obj_expand
   nop   
  lw    $t4, 0xc($s2)
  move  $a0, $s5
  move  $a1, $s2
  and   $t7, $t4, $s4
  bnez  $t7, other_obj_expand
   nop   
  jal   prepare_load_objects
   move  $a2, $s3
  li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f0
  swc1  $f20, 0x98($s2)
  swc1  $f20, 0x9c($s2)
  swc1  $f20, 0x88($s2)
  swc1  $f20, 0x8c($s2)
  swc1  $f20, 0x90($s2)
  swc1  $f20, 0xa4($s2)
  lw    $a0, 0x80($s2)
  swc1  $f0, 0xa0($s2)
  jal   LoadNext_PrevActionBlock
   swc1  $f0, 0x94($s2)
  li    $t6, -1
  sw    $v0, 0x80($s2)
  sh    $zero, 0x84($s2)
  sh    $t6, 0x86($s2)
  sw    $zero, 0xa8($s2)
  sw    $zero, 0xac($s2)
  b     other_obj_expand
   sw    $zero, 0xb0($s2)
tag_expand:
  lh    $t8, 6($s2)
  move  $a0, $s5
  jal   sub_GAME_7F056EA0
   addu  $a1, $t8, $s3
  beqz  $v0, .L7F004A00
   sw    $v0, 0xc($s2)
  lw    $t0, 0x64($v0)
  ori   $t1, $t0, 0x10
  sw    $t1, 0x64($v0)
.L7F004A00:
  jal   set_parent_cur_tag_entry
   move  $a0, $s2
  b     other_obj_expand
   nop   
type25_rename:
  lw    $t9, 4($s2)
  move  $a0, $s5
  jal   sub_GAME_7F056EA0
   addu  $a1, $t9, $s3
  beqz  $v0, .L7F004A34
   sw    $v0, 0x24($s2)
  lw    $t2, 0x64($v0)
  ori   $t3, $t2, 0x400
  sw    $t3, 0x64($v0)
.L7F004A34:
  jal   sub_GAME_7F08D8A0
   move  $a0, $s2
  b     other_obj_expand
   nop   
type23_solo_brief_text:
  jal   setup_briefing_text_entry_parent
   move  $a0, $s2
  b     other_obj_expand
   nop   
type2E_viewport_pos:
  lw    $t5, 4($s2)
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f0
  mtc1  $t5, $f10
  lw    $t7, 0xc($s2)
  lw    $t4, 8($s2)
  cvt.s.w $f6, $f10
  mtc1  $t7, $f10
  mtc1  $t4, $f4
  lw    $t6, 0x10($s2)
  lw    $t8, 0x14($s2)
  cvt.s.w $f8, $f4
  mtc1  $t6, $f4
  li    $at, 0x47800000 # 65536.000000
  div.s $f16, $f6, $f0
  cvt.s.w $f6, $f10
  div.s $f18, $f8, $f0
  swc1  $f16, 4($s2)
  cvt.s.w $f8, $f4
  mtc1  $at, $f4
  div.s $f16, $f6, $f0
  mtc1  $t8, $f6
  swc1  $f18, 8($s2)
  mtc1  $at, $f18
  nop   
  div.s $f10, $f8, $f18
  swc1  $f16, 0xc($s2)
  cvt.s.w $f16, $f6
  div.s $f8, $f16, $f4
  swc1  $f10, 0x10($s2)
  b     other_obj_expand
   swc1  $f8, 0x14($s2)
type17_objective_expand:
  jal   add_ptr_to_objective
   move  $a0, $s2
  b     other_obj_expand
   nop   
type20_subobjective_expand:
  jal   set_parent_cur_obj_enter_room
   move  $a0, $s2
  b     other_obj_expand
   nop   
type21_subobjective_expand:
  jal   set_parent_cur_obj_deposited_in_room
   move  $a0, $s2
  b     other_obj_expand
   nop   
type1E_subobjective_expand:
  jal   set_parent_cur_obj_photograph
   move  $a0, $s2
other_obj_expand:
  jal   get_size_of_setup_object_type
   move  $a0, $s2
  sll   $t0, $v0, 2
  addu  $s2, $t0, $s2
  lbu   $v1, 3($s2)
  li    $at, 48
  addiu $s3, $s3, 1
  bnel  $v1, $at, .L7F004368
   addiu $t0, $v1, -1
  lui   $s2, %hi(ptr_setup_objects) # $s2, 0x8007
  lw    $s2, %lo(ptr_setup_objects)($s2)
  move  $s3, $zero
  lbu   $v1, 3($s2)
.L7F004B40:
  li    $at, 48
  lui   $s7, 8
  beq   $v1, $at, .L7F004E88
   li    $s6, 8
  li    $fp, 43
  li    $s4, 1
  addiu $t1, $v1, -3
.L7F004B5C:
  sltiu $at, $t1, 0x2d
  beqz  $at, .L7F004DF4
   sll   $t1, $t1, 2
  lui   $at, %hi(jpt_8004F02C)
  addu  $at, $at, $t1
  lw    $t1, %lo(jpt_8004F02C)($at)
  jr    $t1
   nop   
.L7F004B7C:
  lw    $t9, 0x10($s2)
  beqz  $t9, .L7F004DF4
   nop   
  lw    $t2, 8($s2)
  andi  $t3, $t2, 0x8000
  beqz  $t3, .L7F004DF4
   nop   
  lh    $v0, 6($s2)
  move  $a0, $s5
  jal   sub_GAME_7F056EA0
   addu  $a1, $s3, $v0
  beqz  $v0, .L7F004DF4
   move  $s0, $v0
  lw    $t5, 0x10($v0)
  beqz  $t5, .L7F004DF4
   nop   
  lw    $t4, 0x64($s2)
  lw    $a0, 0x14($s2)
  or    $t7, $t4, $s7
  sw    $t7, 0x64($s2)
  jal   set_obj_instance_controller_scale
   lw    $a1, 0x14($a0)
  lw    $a0, 0x10($s2)
  jal   sub_GAME_7F03A5A4
   lw    $a1, 0x10($s0)
  b     .L7F004DF4
   nop   
.L7F004BE8:
  lw    $t6, 4($s2)
  jal   sub_GAME_7F056A88
   addu  $a0, $t6, $s3
  lw    $t8, 8($s2)
  move  $s0, $v0
  jal   sub_GAME_7F056A88
   addu  $a0, $t8, $s3
  beqz  $s0, .L7F004DF4
   move  $a1, $v0
  beqz  $v0, .L7F004DF4
   nop   
  lbu   $t0, 3($s0)
  bne   $s6, $t0, .L7F004DF4
   nop   
  lbu   $t1, 3($v0)
  bne   $s6, $t1, .L7F004DF4
   nop   
  jal   link_objects
   move  $a0, $s0
  b     .L7F004DF4
   nop   
.L7F004C3C:
  lw    $v0, 4($s2)
  lw    $s1, 8($s2)
  move  $a0, $s5
  jal   sub_GAME_7F056EA0
   addu  $a1, $s3, $v0
  move  $s0, $v0
  jal   sub_GAME_7F056A88
   addu  $a0, $s3, $s1
  beqz  $s0, .L7F004DF4
   nop   
  lw    $v1, 0x10($s0)
  beqz  $v1, .L7F004DF4
   nop   
  beqz  $v0, .L7F004DF4
   nop   
  lbu   $t9, 3($v0)
  bne   $s4, $t9, .L7F004DF4
   nop   
  lw    $t2, 0x10($v0)
  beqz  $t2, .L7F004DF4
   nop   
  sw    $v1, 4($s2)
  lw    $t3, 0x10($v0)
  move  $a0, $s2
  jal   sub_GAME_7F001910
   sw    $t3, 8($s2)
  lw    $t5, 0x64($s0)
  ori   $t4, $t5, 1
  b     .L7F004DF4
   sw    $t4, 0x64($s0)
.L7F004CB4:
  lw    $v0, 4($s2)
  lw    $t7, 0xc($s2)
  lw    $s1, 8($s2)
  move  $a0, $s5
  addu  $a1, $s3, $v0
  jal   sub_GAME_7F056EA0
   sw    $t7, 0x80($sp)
  move  $s0, $v0
  move  $a0, $s5
  jal   sub_GAME_7F056EA0
   addu  $a1, $s3, $s1
  lw    $t6, 0x80($sp)
  move  $s1, $v0
  move  $a0, $s5
  jal   sub_GAME_7F056EA0
   addu  $a1, $s3, $t6
  beqz  $s0, .L7F004DF4
   nop   
  lw    $t8, 0x10($s0)
  beqz  $t8, .L7F004DF4
   nop   
  beqz  $s1, .L7F004DF4
   nop   
  lw    $t0, 0x10($s1)
  beqz  $t0, .L7F004DF4
   nop   
  lbu   $t1, 3($s1)
  bne   $fp, $t1, .L7F004DF4
   nop   
  beqz  $v0, .L7F004DF4
   nop   
  lw    $t9, 0x10($v0)
  beqz  $t9, .L7F004DF4
   nop   
  lbu   $t2, 3($v0)
  move  $a0, $s2
  bne   $s4, $t2, .L7F004DF4
   nop   
  sw    $s0, 4($s2)
  sw    $s1, 8($s2)
  sw    $v0, 0xc($s2)
  jal   sub_GAME_7F001940
   sw    $v0, 0x74($sp)
  lw    $t3, 0xc($s0)
  lw    $v1, 0x74($sp)
  ori   $t5, $t3, 0x400
  sw    $t5, 0xc($s0)
  lw    $t4, 0xc($v1)
  ori   $t7, $t4, 0x400
  b     .L7F004DF4
   sw    $t7, 0xc($v1)
.L7F004D80:
  lw    $v0, 4($s2)
  lw    $s1, 8($s2)
  move  $a0, $s5
  jal   sub_GAME_7F056EA0
   addu  $a1, $s3, $v0
  move  $s0, $v0
  move  $a0, $s5
  jal   sub_GAME_7F056EA0
   addu  $a1, $s3, $s1
  beqz  $s0, .L7F004DF4
   nop   
  lw    $t6, 0x10($s0)
  beqz  $t6, .L7F004DF4
   nop   
  beqz  $v0, .L7F004DF4
   nop   
  lw    $t8, 0x10($v0)
  beqz  $t8, .L7F004DF4
   nop   
  lbu   $t0, 3($s0)
  move  $a0, $s2
  bne   $s4, $t0, .L7F004DF4
   nop   
  sw    $s0, 4($s2)
  jal   sub_GAME_7F001928
   sw    $v0, 8($s2)
  lw    $t1, 0x64($s0)
  ori   $t9, $t1, 0x2000
  sw    $t9, 0x64($s0)
.L7F004DF4:
  jal   get_size_of_setup_object_type
   move  $a0, $s2
  sll   $t2, $v0, 2
  addu  $s2, $t2, $s2
  lbu   $v1, 3($s2)
  li    $at, 48
  addiu $s3, $s3, 1
  bnel  $v1, $at, .L7F004B5C
   addiu $t1, $v1, -3
  b     .L7F004E88
   nop   
.L7F004E20:
  lui   $at, %hi(ptr_setup_path_tbl) # $at, 0x8007
  sw    $zero, %lo(ptr_setup_path_tbl)($at)
  lui   $at, %hi(ptr_setup_path_link) # $at, 0x8007
  sw    $zero, %lo(ptr_setup_path_link)($at)
  lui   $at, %hi(ptr_setup_intro) # $at, 0x8007
  sw    $zero, %lo(ptr_setup_intro)($at)
  lui   $at, %hi(ptr_setup_objects) # $at, 0x8007
  sw    $zero, %lo(ptr_setup_objects)($at)
  lui   $at, %hi(ptr_setup_path_sets) # $at, 0x8007
  sw    $zero, %lo(ptr_setup_path_sets)($at)
  lui   $at, %hi(ptr_setup_actions) # $at, 0x8007
  sw    $zero, %lo(ptr_setup_actions)($at)
  lui   $at, %hi(ptr_0xxxpresets) # $at, 0x8007
  sw    $zero, %lo(ptr_0xxxpresets)($at)
  lui   $at, %hi(ptr_2xxxpresets) # $at, 0x8007
  sw    $zero, %lo(ptr_2xxxpresets)($at)
  lui   $at, %hi(dword_CODE_bss_80075D20) # $at, 0x8007
  sw    $zero, %lo(dword_CODE_bss_80075D20)($at)
  lui   $at, %hi(dword_CODE_bss_80075D24) # $at, 0x8007
  sw    $zero, %lo(dword_CODE_bss_80075D24)($at)
  jal   alloc_init_GUARDdata_entries
   move  $a0, $zero
  jal   sub_GAME_7F005540
   move  $a0, $zero
  jal   sub_GAME_7F005624
   move  $a0, $zero
.L7F004E88:
  jal   alloc_false_GUARDdata_to_exec_global_action
   nop   
  lw    $ra, 0x44($sp)
  ldc1  $f20, 0x18($sp)
  lw    $s0, 0x20($sp)
  lw    $s1, 0x24($sp)
  lw    $s2, 0x28($sp)
  lw    $s3, 0x2c($sp)
  lw    $s4, 0x30($sp)
  lw    $s5, 0x34($sp)
  lw    $s6, 0x38($sp)
  lw    $s7, 0x3c($sp)
  lw    $fp, 0x40($sp)
  jr    $ra
   addiu $sp, $sp, 0x280
");
#endif
