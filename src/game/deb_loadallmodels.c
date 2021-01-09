enum {
  PROJECTILES_MAX = 0x2E,
  PROJECTILES_TYPE_KNIFE = 0xBA,
  PROJECTILES_TYPE_GRENADE = 0xC4,
  PROJECTILES_TYPE_REMOTE_MINE = 0xC7,
  PROJECTILES_TYPE_PROX_MINE = 0xC8,
  PROJECTILES_TYPE_TIMED_MINE = 0xC9,
  PROJECTILES_TYPE_ROCKET_ROUND = 0xCA,
  PROJECTILES_TYPE_ROCKET_ROUND2 = 0xCA,
  PROJECTILES_TYPE_GLAUNCH_ROUND = 0xCB,
  PROJECTILES_TYPE_BOMBCASE = 0xE2,
  PROJECTILES_TYPE_BUG = 0xF5,
  PROJECTILES_TYPE_MICROCAMERA = 0xF6,
  PROJECTILES_TYPE_GE_KEY = 0xF8,
  PROJECTILES_TYPE_PLASTIQUE = 0x111
};

unsigned int global_action_block_temp_buffer[119] = {0};

int weapon_models_for_weapon_load[] = {
    PROJECTILES_TYPE_KNIFE,         PROJECTILES_TYPE_GRENADE,
    PROJECTILES_TYPE_REMOTE_MINE,   PROJECTILES_TYPE_PROX_MINE,
    PROJECTILES_TYPE_TIMED_MINE,    PROJECTILES_TYPE_ROCKET_ROUND,
    PROJECTILES_TYPE_GLAUNCH_ROUND, 0xFFFFFFFF};

extern float ai_accuracy_modifier, ai_damage_modifier, ai_health_modifier,
    ai_reaction_speed;
extern int setting_007_5, objectiveregisters1;

void init_obj_register_difficulty_vals(void) {
  objectiveregisters1 = 0;
  ai_accuracy_modifier = 1.0f;
  ai_damage_modifier = 1.0f;
  ai_health_modifier = 1.0f;
  ai_reaction_speed = 1.0f;
  setting_007_5 = 0;
}

asm(R"
glabel alloc_false_GUARDdata_to_exec_global_action
  lui   $t5, %hi(ptr_setup_path_tbl) 
  addiu $t5, %lo(ptr_setup_path_tbl) # addiu $t5, $t5, 0x5d00
  lw    $a1, 0x14($t5)
  lui   $v0, %hi(objectiveregisters3)
  lui   $a2, %hi(objectiveregisters2)
  addiu $a2, %lo(objectiveregisters2) # addiu $a2, $a2, 0x97c
  addiu $v0, %lo(objectiveregisters3) # addiu $v0, $v0, 0x980
  addiu $sp, $sp, -0x208
  sw    $ra, 0x14($sp)
  sw    $zero, ($a2)
  beqz  $a1, .L7F001248
   sw    $zero, ($v0)
  lw    $t6, ($a1)
  move  $v1, $a1
  move  $a3, $zero
  beqz  $t6, .L7F0010CC
   li    $a1, 4
  lw    $t7, 4($v1)
.L7F0010A4:
  slti  $at, $t7, 0x1000
  bnezl $at, .L7F0010C0
   lw    $t6, 8($v1)
  lw    $t8, ($v0)
  addiu $t9, $t8, 1
  sw    $t9, ($v0)
  lw    $t6, 8($v1)
.L7F0010C0:
  addiu $v1, $v1, 8
  bnezl $t6, .L7F0010A4
   lw    $t7, 4($v1)
.L7F0010CC:
  lw    $v1, ($v0)
  move  $t0, $zero
  blez  $v1, .L7F001248
   sll   $a0, $v1, 4
  subu  $a0, $a0, $v1
  sll   $a0, $a0, 3
  subu  $a0, $a0, $v1
  sll   $a0, $a0, 2
  addiu $a0, $a0, 0xf
  ori   $t7, $a0, 0xf
  xori  $a0, $t7, 0xf
  jal   mempAllocBytesInBank
   sw    $a3, 0x200($sp)
  lui   $t5, %hi(ptr_setup_path_tbl) 
  addiu $t5, %lo(ptr_setup_path_tbl) # addiu $t5, $t5, 0x5d00
  lw    $a1, 0x14($t5)
  lui   $a2, %hi(objectiveregisters2)
  addiu $a2, %lo(objectiveregisters2) # addiu $a2, $a2, 0x97c
  sw    $v0, ($a2)
  lw    $t9, ($a1)
  lw    $a3, 0x200($sp)
  move  $a0, $zero
  beqz  $t9, .L7F001248
   move  $v1, $a1
  lui   $t0, %hi(global_action_block_temp_buffer) 
  addiu $t0, %lo(global_action_block_temp_buffer) # addiu $t0, $t0, -0x5fa0
  li    $t4, 26
  li    $t3, -1
  li    $t2, 254
  li    $t1, 476
  addiu $a1, $sp, 0x24
  lw    $t6, 4($v1)
.L7F00114C:
  move  $t9, $t0
  addiu $t8, $t0, 0x1d4
  slti  $at, $t6, 0x1000
  bnez  $at, .L7F001234
   move  $t6, $a1
.L7F001160:
  lw    $at, ($t9)
  addiu $t9, $t9, 0xc
  addiu $t6, $t6, 0xc
  sw    $at, -0xc($t6)
  lw    $at, -8($t9)
  sw    $at, -8($t6)
  lw    $at, -4($t9)
  bne   $t9, $t8, .L7F001160
   sw    $at, -4($t6)
  multu $a3, $t1
  lw    $at, ($t9)
  sw    $at, ($t6)
  lw    $t8, 4($t9)
  sw    $t8, 4($t6)
  lw    $t7, ($a2)
  mflo  $v0
  addiu $t6, $a1, 0x1d4
  addu  $t8, $t7, $v0
  move  $t7, $a1
.L7F0011AC:
  lw    $at, ($t7)
  addiu $t7, $t7, 0xc
  addiu $t8, $t8, 0xc
  sw    $at, -0xc($t8)
  lw    $at, -8($t7)
  sw    $at, -8($t8)
  lw    $at, -4($t7)
  bne   $t7, $t6, .L7F0011AC
   sw    $at, -4($t8)
  lw    $at, ($t7)
  addiu $a3, $a3, 1
  sw    $at, ($t8)
  lw    $t6, 4($t7)
  sw    $t6, 4($t8)
  lw    $t9, ($a2)
  addu  $t6, $t9, $v0
  sh    $t2, ($t6)
  lw    $t7, 0x14($t5)
  lw    $t6, ($a2)
  addu  $t8, $t7, $a0
  lw    $t9, ($t8)
  addu  $t7, $t6, $v0
  sw    $t9, 0x104($t7)
  lw    $t8, ($a2)
  addu  $t6, $t8, $v0
  sh    $zero, 0x108($t6)
  lw    $t9, ($a2)
  addu  $t7, $t9, $v0
  sh    $t3, 0x10a($t7)
  lw    $t8, ($a2)
  addu  $t6, $t8, $v0
  sb    $t4, 7($t6)
  lw    $t9, 0x14($t5)
  addu  $v1, $t9, $a0
.L7F001234:
  lw    $t7, 8($v1)
  addiu $a0, $a0, 8
  addiu $v1, $v1, 8
  bnezl $t7, .L7F00114C
   lw    $t6, 4($v1)
.L7F001248:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x208
  jr    $ra
   nop   
");

asm(R"
glabel debug_object_load_all_models
  addiu $sp, $sp, -0x38
  lui   $t6, %hi(ptr_setup_actions) 
  lw    $t6, %lo(ptr_setup_actions)($t6)
  sw    $ra, 0x34($sp)
  sw    $s7, 0x30($sp)
  sw    $s6, 0x2c($sp)
  sw    $s5, 0x28($sp)
  sw    $s4, 0x24($sp)
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  lw    $s0, ($t6)
  li    $s5, 191
  li    $s6, 192
  beqz  $s0, .L7F0013E0
   move  $s7, $zero
  li    $s4, 190
  li    $s3, 189
  li    $s2, 27
  li    $s1, 4
.L7F0012AC:
  lbu   $v1, ($s0)
.L7F0012B0:
  lui   $t7, %hi(ptr_setup_actions) 
  bne   $s1, $v1, .L7F0012C8
   nop   
  lw    $t7, %lo(ptr_setup_actions)($t7)
  b     .L7F0013CC
   addu  $v0, $t7, $s7
.L7F0012C8:
  beql  $v1, $s2, .L7F0012FC
   lbu   $t8, 1($s0)
  beq   $v1, $s3, .L7F001320
   nop   
  beq   $v1, $s4, .L7F00134C
   nop   
  beql  $v1, $s5, .L7F00137C
   lbu   $t2, 1($s0)
  beql  $v1, $s6, .L7F0013A8
   lbu   $t5, 1($s0)
  b     .L7F0013BC
   move  $a0, $s0
  lbu   $t8, 1($s0)
.L7F0012FC:
  lbu   $t0, 2($s0)
  sll   $t9, $t8, 8
  or    $v0, $t9, $t0
  jal   load_model
   andi  $a0, $v0, 0xffff
  beql  $v0, $zero, .L7F0013BC
   move  $a0, $s0
  b     .L7F0013BC
   move  $a0, $s0
.L7F001320:
  jal   load_body_head_if_not_loaded
   lbu   $a0, 1($s0)
  lb    $a0, 2($s0)
  bltzl $a0, .L7F0013BC
   move  $a0, $s0
  jal   load_body_head_if_not_loaded
   nop   
  beql  $v0, $zero, .L7F0013BC
   move  $a0, $s0
  b     .L7F0013BC
   move  $a0, $s0
.L7F00134C:
  jal   load_body_head_if_not_loaded
   lbu   $a0, 1($s0)
  lb    $a0, 2($s0)
  bltzl $a0, .L7F0013BC
   move  $a0, $s0
  jal   load_body_head_if_not_loaded
   nop   
  beql  $v0, $zero, .L7F0013BC
   move  $a0, $s0
  b     .L7F0013BC
   move  $a0, $s0
  lbu   $t2, 1($s0)
.L7F00137C:
  lbu   $t4, 2($s0)
  sll   $t3, $t2, 8
  jal   load_model
   or    $a0, $t3, $t4
  jal   set_weapon_model_generated_thrown_object
   lbu   $a0, 3($s0)
  beql  $v0, $zero, .L7F0013BC
   move  $a0, $s0
  b     .L7F0013BC
   move  $a0, $s0
  lbu   $t5, 1($s0)
.L7F0013A8:
  lbu   $t7, 2($s0)
  sll   $t6, $t5, 8
  jal   load_model
   or    $a0, $t6, $t7
  move  $a0, $s0
.L7F0013BC:
  jal   get_length_of_action_block
   move  $a1, $zero
  b     .L7F0012AC
   addu  $s0, $s0, $v0
.L7F0013CC:
  lw    $s0, 8($v0)
  addiu $s7, $s7, 8
  addiu $v0, $v0, 8
  bnezl $s0, .L7F0012B0
   lbu   $v1, ($s0)
.L7F0013E0:
  lw    $ra, 0x34($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  lw    $s4, 0x24($sp)
  lw    $s5, 0x28($sp)
  lw    $s6, 0x2c($sp)
  lw    $s7, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x38
");

asm(R"
glabel debug_weapon_load_table
  addiu $sp, $sp, -0x50
  lui   $t7, %hi(weapon_models_for_weapon_load) 
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  addiu $t7, %lo(weapon_models_for_weapon_load) # addiu $t7, $t7, -0x5dc4
  lw    $at, ($t7)
  lw    $t0, 4($t7)
  addiu $t6, $sp, 0x30
  sw    $at, ($t6)
  sw    $t0, 4($t6)
  lw    $t0, 0xc($t7)
  lw    $at, 8($t7)
  addiu $s0, $sp, 0x30
  sw    $t0, 0xc($t6)
  sw    $at, 8($t6)
  lw    $at, 0x10($t7)
  lw    $t0, 0x14($t7)
  sw    $at, 0x10($t6)
  sw    $t0, 0x14($t6)
  lw    $t0, 0x1c($t7)
  lw    $at, 0x18($t7)
  sw    $t0, 0x1c($t6)
  sw    $at, 0x18($t6)
  lw    $t1, 0x30($sp)
  bltzl $t1, .L7F001494
   lw    $ra, 0x1c($sp)
  lw    $a0, ($s0)
.L7F001478:
  jal   load_model
   nop   
  lw    $a0, 4($s0)
  addiu $s0, $s0, 4
  bgez  $a0, .L7F001478
   nop   
  lw    $ra, 0x1c($sp)
.L7F001494:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x50
  jr    $ra
   nop
");
