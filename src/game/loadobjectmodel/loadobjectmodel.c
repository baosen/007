asm(R"
glabel sub_GAME_7F056850
  addiu $sp, $sp, -0x30
  sw    $ra, 0x2c($sp)
  sw    $s0, 0x28($sp)
  lwc1  $f4, ($a0)
  mtc1  $a2, $f12
  move  $s0, $a3
  swc1  $f4, ($a3)
  lwc1  $f6, 4($a0)
  swc1  $f6, 4($a3)
  lwc1  $f8, 8($a0)
  swc1  $f8, 8($a3)
  lw    $t6, 0x40($sp)
  bnez  $a1, .L7F056890
   sw    $a1, ($t6)
  b     .L7F0568E0
   move  $v0, $zero
.L7F056890:
  mtc1  $zero, $f0
  lw    $a0, 0x40($sp)
  li    $t7, 31
  c.lt.s $f0, $f12
  li    $at, 0x3F800000 # 1.000000
  bc1fl .L7F0568E0
   li    $v0, 1
  mtc1  $at, $f10
  lw    $a1, ($s0)
  lw    $a2, 8($s0)
  mfc1  $a3, $f12
  swc1  $f0, 0x14($sp)
  sw    $t7, 0x10($sp)
  jal   sub_GAME_7F0B18B8
   swc1  $f10, 0x18($sp)
  bltzl $v0, .L7F0568E0
   li    $v0, 1
  b     .L7F0568E0
   move  $v0, $zero
  li    $v0, 1
.L7F0568E0:
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x28($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

unsigned int get_size_of_setup_object_type(unsigned char *object) {
  switch (object[3]) {
  case 9:
    return 7;
  case 1:
    return 0x40;
  case 2:
    return 2;
  case 3:
    return 0x20;
  case 0x2a:
    return 0x20;
  case 0x2f:
    return 0x25;
  case 0x2b:
    return 0x20;
  case 0x24:
    return 0x20;
  case 4:
    return 0x21;
  case 5:
    return 0x20;
  case 6:
    return 0x3b;
  case 7:
    return 0x21;
  case 8:
    return 0x22;
  case 10:
    return 0x40;
  case 0xb:
    return 0x95;
  case 0xc:
    return 0x20;
  case 0xd:
    return 0x36;
  case 0xe:
    return 3;
  case 0x11:
    return 0x20;
  case 0x12:
    return 3;
  case 0x13:
    return 4;
  case 0x2c:
    return 5;
  case 0x14:
    return 0x2d;
  case 0x15:
    return 0x22;
  case 0x16:
    return 4;
  case 0x25:
    return 10;
  case 0x17:
    return 4;
  case 0x18:
    return 1;
  case 0x19:
    return 2;
  case 0x1a:
    return 2;
  case 0x1b:
    return 2;
  case 0x1c:
    return 2;
  case 0x1d:
    return 2;
  case 0x1e:
    return 4;
  case 0x1f:
    return 1;
  case 0x20:
    return 4;
  case 0x21:
    return 5;
  case 0x22:
    return 1;
  case 0x23:
    return 4;
  case 0x26:
    return 4;
  case 0x27:
    return 0x2c;
  case 0x28:
    return 0x2d;
  case 0x2d:
    return 0x38;
  case 0x2e:
    return 7;
  default:
    return 1;
  }
}

asm(R"
glabel sub_GAME_7F056A88
  addiu $sp, $sp, -0x28
  sw    $s1, 0x18($sp)
  sw    $s3, 0x20($sp)
  lui   $s1, %hi(ptr_setup_objects)
  move  $s3, $a0
  sw    $ra, 0x24($sp)
  sw    $s2, 0x1c($sp)
  sw    $s0, 0x14($sp)
  bltz  $a0, .L7F056AFC
   lw    $s1, %lo(ptr_setup_objects)($s1)
  beql  $s1, $zero, .L7F056B00
   move  $v0, $zero
  lbu   $t6, 3($s1)
  li    $s2, 48
  move  $s0, $zero
  beql  $s2, $t6, .L7F056B00
   move  $v0, $zero
.L7F056ACC:
  bne   $s0, $s3, .L7F056ADC
   nop   
  b     .L7F056B00
   move  $v0, $s1
.L7F056ADC:
  jal   get_size_of_setup_object_type
   move  $a0, $s1
  sll   $t7, $v0, 2
  addu  $s1, $t7, $s1
  lbu   $t8, 3($s1)
  addiu $s0, $s0, 1
  bne   $s2, $t8, .L7F056ACC
   nop   
.L7F056AFC:
  move  $v0, $zero
.L7F056B00:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
glabel check_if_object_type_has_been_loaded
  addiu $sp, $sp, -0x28
  sw    $s0, 0x14($sp)
  lui   $s0, %hi(ptr_setup_objects)
  lw    $s0, %lo(ptr_setup_objects)($s0)
  sw    $s3, 0x20($sp)
  move  $s3, $a0
  sw    $ra, 0x24($sp)
  sw    $s2, 0x1c($sp)
  beqz  $s0, .L7F056B88
   sw    $s1, 0x18($sp)
  lbu   $t6, 3($s0)
  li    $s2, 48
  move  $s1, $zero
  beql  $s2, $t6, .L7F056B8C
   li    $v0, -1
.L7F056B58:
  bne   $s0, $s3, .L7F056B68
   nop   
  b     .L7F056B8C
   move  $v0, $s1
.L7F056B68:
  jal   get_size_of_setup_object_type
   move  $a0, $s0
  sll   $t7, $v0, 2
  addu  $s0, $t7, $s0
  lbu   $t8, 3($s0)
  addiu $s1, $s1, 1
  bne   $s2, $t8, .L7F056B58
   nop   
.L7F056B88:
  li    $v0, -1
.L7F056B8C:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
glabel sub_GAME_7F056BA8
  addiu $sp, $sp, -0x28
  sw    $s0, 0x14($sp)
  lui   $s0, %hi(ptr_setup_objects)
  lw    $s0, %lo(ptr_setup_objects)($s0)
  sw    $s3, 0x20($sp)
  move  $s3, $a0
  sw    $ra, 0x24($sp)
  sw    $s2, 0x1c($sp)
  beqz  $s0, .L7F056C18
   sw    $s1, 0x18($sp)
  lbu   $t6, 3($s0)
  li    $s2, 48
  move  $s1, $zero
  beql  $s2, $t6, .L7F056C1C
   li    $v0, -1
  lw    $t7, 0x10($s0)
.L7F056BE8:
  bne   $s3, $t7, .L7F056BF8
   nop   
  b     .L7F056C1C
   move  $v0, $s1
.L7F056BF8:
  jal   get_size_of_setup_object_type
   move  $a0, $s0
  sll   $t8, $v0, 2
  addu  $s0, $t8, $s0
  lbu   $t9, 3($s0)
  addiu $s1, $s1, 1
  bnel  $s2, $t9, .L7F056BE8
   lw    $t7, 0x10($s0)
.L7F056C18:
  li    $v0, -1
.L7F056C1C:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
glabel load_model
  sll   $t6, $a0, 2
  subu  $t6, $t6, $a0
  lui   $t7, %hi(PitemZ_entries) 
  addiu $t7, %lo(PitemZ_entries) # addiu $t7, $t7, -0x5dd8
  sll   $t6, $t6, 2
  addu  $v0, $t6, $t7
  lw    $a2, ($v0)
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  lw    $t8, ($a2)
  move  $a0, $a2
  bnezl $t8, .L7F056C90
   move  $v0, $zero
  lw    $a1, 4($v0)
  jal   load_object_into_memory
   sw    $v0, 0x1c($sp)
  lw    $v0, 0x1c($sp)
  jal   set_objuse_flag_compute_grp_nums_set_obj_loaded
   lw    $a0, ($v0)
  b     .L7F056C90
   li    $v0, 1
  move  $v0, $zero
.L7F056C90:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
.late_rodata
/*hack for below*/
glabel jpt_8005354C
.word .L7F056EE4
.word .L7F056EEC
.word .L7F056EE4
.word .L7F056EE4
.word .L7F056EE4
.word .L7F056EE4
.word .L7F056EE4
.word .L7F056EE4
.word .L7F056EEC
.word .L7F056EE4
.word .L7F056EE4
.word .L7F056EE4
.word .L7F056EE4
.word .L7F056EEC
.word .L7F056EF4
.word .L7F056EF4
.word .L7F056EE4
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EE4
.word .L7F056EE4
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EE4
.word .L7F056EEC
.word .L7F056EEC
.word .L7F056EE4

.text
glabel sub_GAME_7F056CA0
  addiu $sp, $sp, -0x50
  sw    $ra, 0x24($sp)
  sw    $s1, 0x20($sp)
  sw    $s0, 0x1c($sp)
  sdc1  $f20, 0x10($sp)
  lw    $s1, 0x10($a0)
  move  $s0, $a0
  mtc1  $zero, $f20
  jal   sub_GAME_7F03E18C
   move  $a0, $s1
  lw    $t6, 0xc($s0)
  sll   $t7, $t6, 0xe
  bgez  $t7, .L7F056D04
   nop   
  lw    $v0, 0x14($s1)
  li    $t9, 255
  li    $t0, 255
  beqz  $v0, .L7F056CFC
   nop   
  lbu   $t8, 3($v0)
  sb    $t9, 0x2d($s1)
  b     .L7F056E80
   sb    $t8, 0x2c($s1)
.L7F056CFC:
  b     .L7F056E80
   sb    $t0, 0x2c($s1)
.L7F056D04:
  jal   sub_GAME_7F040078
   move  $a0, $s0
  beqz  $v0, .L7F056E80
   move  $a0, $v0
  addiu $a1, $s0, 0x18
  sw    $a1, 0x28($sp)
  jal   sub_GAME_7F03E87C
   sw    $v0, 0x30($sp)
  li    $at, 0x41F00000 # 30.000000
  mtc1  $at, $f4
  lw    $a0, 0x30($sp)
  lw    $a1, 0x28($sp)
  sub.s $f6, $f0, $f4
  jal   sub_GAME_7F03E9BC
   swc1  $f6, 0x40($sp)
  swc1  $f0, 0x44($sp)
  lw    $a0, 0x30($sp)
  jal   sub_GAME_7F03EAFC
   lw    $a1, 0x28($sp)
  li    $at, 0x41F00000 # 30.000000
  mtc1  $at, $f8
  lw    $a0, 0x30($sp)
  lw    $a1, 0x28($sp)
  sub.s $f10, $f0, $f8
  jal   sub_GAME_7F03E91C
   swc1  $f10, 0x48($sp)
  li    $at, 0x41F00000 # 30.000000
  mtc1  $at, $f16
  lw    $a0, 0x30($sp)
  lw    $a1, 0x28($sp)
  add.s $f18, $f0, $f16
  jal   sub_GAME_7F03EA5C
   swc1  $f18, 0x34($sp)
  swc1  $f0, 0x38($sp)
  lw    $a0, 0x30($sp)
  jal   sub_GAME_7F03EB9C
   lw    $a1, 0x28($sp)
  lwc1  $f2, 0x40($sp)
  mtc1  $zero, $f6
  li    $at, 0x41F00000 # 30.000000
  neg.s $f2, $f2
  mtc1  $at, $f4
  c.lt.s $f6, $f2
  lwc1  $f8, 0x34($sp)
  add.s $f12, $f0, $f4
  lwc1  $f0, 0x48($sp)
  bc1fl .L7F056DCC
   neg.s $f0, $f0
  mov.s $f20, $f2
  neg.s $f0, $f0
.L7F056DCC:
  c.lt.s $f20, $f0
  nop   
  bc1fl .L7F056DE4
   c.lt.s $f20, $f8
  mov.s $f20, $f0
  c.lt.s $f20, $f8
.L7F056DE4:
  nop   
  bc1fl .L7F056DF8
   c.lt.s $f20, $f12
  mov.s $f20, $f8
  c.lt.s $f20, $f12
.L7F056DF8:
  swc1  $f12, 0x3c($sp)
  bc1fl .L7F056E10
   lwc1  $f10, 0x40($sp)
  mov.s $f20, $f12
  swc1  $f12, 0x3c($sp)
  lwc1  $f10, 0x40($sp)
.L7F056E10:
  lwc1  $f16, 0x58($s0)
  lwc1  $f4, 0x44($sp)
  mfc1  $a3, $f20
  add.s $f18, $f10, $f16
  lwc1  $f10, 0x48($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0x40
  swc1  $f18, 0x40($sp)
  lwc1  $f6, 0x5c($s0)
  addiu $a2, $sp, 0x34
  add.s $f8, $f4, $f6
  lwc1  $f4, 0x34($sp)
  swc1  $f8, 0x44($sp)
  lwc1  $f16, 0x60($s0)
  add.s $f18, $f10, $f16
  lwc1  $f10, 0x38($sp)
  swc1  $f18, 0x48($sp)
  lwc1  $f6, 0x58($s0)
  add.s $f8, $f4, $f6
  lwc1  $f4, 0x3c($sp)
  swc1  $f8, 0x34($sp)
  lwc1  $f16, 0x5c($s0)
  add.s $f18, $f10, $f16
  swc1  $f18, 0x38($sp)
  lwc1  $f6, 0x60($s0)
  add.s $f8, $f4, $f6
  jal   sub_GAME_7F03E27C
   swc1  $f8, 0x3c($sp)
.L7F056E80:
  jal   sub_GAME_7F03E210
   move  $a0, $s1
  lw    $ra, 0x24($sp)
  ldc1  $f20, 0x10($sp)
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x50
");

asm(R"
.late_rodata
.word .L7F056EE4
.word .L7F056EE4
.word .L7F056EE4
.word .L7F056EE4
.word .L7F056EEC
.word .L7F056EE4
.word .L7F056EEC
.word .L7F056EE4

.text
glabel sub_GAME_7F056EA0
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  jal   sub_GAME_7F056A88
   move  $a0, $a1
  beqz  $v0, .L7F056EF4
   move  $v1, $v0
  lbu   $t6, 3($v0)
  addiu $t7, $t6, -1
  sltiu $at, $t7, 0x2f
  beqz  $at, .L7F056EF4
   sll   $t7, $t7, 2
  lui   $at, %hi(jpt_8005354C)
  addu  $at, $at, $t7
  lw    $t7, %lo(jpt_8005354C)($at)
.L7F056EDC:
  jr    $t7
   nop   
.L7F056EE4:
  b     .L7F056EF8
   move  $v0, $v1
.L7F056EEC:
  b     .L7F056EF8
   move  $v0, $zero
def_7F056EDC:
.L7F056EF4:
  move  $v0, $v1
.L7F056EF8:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F056F08
  addiu $sp, $sp, -0x40
  sw    $s0, 0x18($sp)
  lui   $s0, %hi(ptr_setup_objects)
  lw    $s0, %lo(ptr_setup_objects)($s0)
  sw    $fp, 0x38($sp)
  sw    $s7, 0x34($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  move  $s7, $a0
  move  $fp, $a3
  sw    $ra, 0x3c($sp)
  sw    $s6, 0x30($sp)
  sw    $s5, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s1, 0x1c($sp)
  sw    $a1, 0x44($sp)
  sw    $a2, 0x48($sp)
  move  $s2, $zero
  beqz  $s0, .L7F057038
   move  $s3, $zero
  lbu   $v1, 3($s0)
  li    $at, 48
  andi  $s4, $a0, 0xff
  beq   $v1, $at, .L7F057038
   li    $s6, 8
  lw    $s5, 0x54($sp)
  lw    $s1, 0x50($sp)
.L7F056F74:
  bne   $s4, $v1, .L7F057018
   nop   
  lw    $v0, 0x10($s0)
  bnez  $v0, .L7F056FA0
   nop   
  bnez  $fp, .L7F057018
   nop   
  bnez  $s1, .L7F057018
   nop   
  b     .L7F05704C
   move  $v0, $s0
.L7F056FA0:
  beq   $s7, $s6, .L7F057018
   nop   
  lw    $t6, 0x64($s0)
  andi  $t7, $t6, 0x80
  bnez  $t7, .L7F057018
   nop   
  lbu   $t8, 2($s0)
  andi  $t9, $t8, 4
  bnez  $t9, .L7F057018
   nop   
  lw    $t0, 0x1c($v0)
  bnez  $t0, .L7F057018
   nop   
  beqz  $s1, .L7F056FEC
   move  $a1, $s5
  jal   sub_GAME_7F06C060
   lw    $a0, 0x14($s0)
  beqz  $v0, .L7F057018
   nop   
.L7F056FEC:
  bnez  $s2, .L7F05700C
   nop   
  lw    $t1, 0x10($s0)
  lbu   $t2, 1($t1)
  andi  $t3, $t2, 2
  bnez  $t3, .L7F05700C
   nop   
  move  $s2, $s0
.L7F05700C:
  bnez  $s3, .L7F057018
   nop   
  move  $s3, $s0
.L7F057018:
  jal   get_size_of_setup_object_type
   move  $a0, $s0
  sll   $t4, $v0, 2
  addu  $s0, $t4, $s0
  lbu   $v1, 3($s0)
  li    $at, 48
  bne   $v1, $at, .L7F056F74
   nop   
.L7F057038:
  lw    $t5, 0x44($sp)
  move  $v0, $zero
  sw    $s2, ($t5)
  lw    $t6, 0x48($sp)
  sw    $s3, ($t6)
.L7F05704C:
  lw    $ra, 0x3c($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  lw    $s3, 0x24($sp)
  lw    $s4, 0x28($sp)
  lw    $s5, 0x2c($sp)
  lw    $s6, 0x30($sp)
  lw    $s7, 0x34($sp)
  lw    $fp, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x40
");
