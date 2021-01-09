#include "chr.h"

void init_guards(void) {
  animation_rate = 1.0f;
  D_8002C904 = 0;
  D_8002C908 = 0;
  D_8002C90C = 0;
  D_8002C910 = 0;
  D_8002CC58 = 0;
  show_patrols_flag = 0;
  player1_guardID = 0x1388;
  ptr_guard_data = 0;
  num_guards = 0;
  init_obj_register_difficulty_vals();
}

asm(R"
glabel alloc_init_GUARDdata_entries
  addiu $t6, $a0, 0xa
  sll   $t7, $t6, 4
  subu  $t7, $t7, $t6
  sll   $t7, $t7, 3
  subu  $t7, $t7, $t6
  sll   $t7, $t7, 2
  addiu $sp, $sp, -0x18
  lui   $a2, %hi(num_guards)
  addiu $a0, $t7, 0xf
  addiu $a2, %lo(num_guards) # addiu $a2, $a2, -0x3398
  sw    $ra, 0x14($sp)
  ori   $t8, $a0, 0xf
  sw    $t6, ($a2)
  xori  $a0, $t8, 0xf
  jal   mempAllocBytesInBank
   li    $a1, 4
  lui   $a2, %hi(num_guards)
  addiu $a2, %lo(num_guards) # addiu $a2, $a2, -0x3398
  lw    $t0, ($a2)
  lui   $a0, %hi(ptr_guard_data)
  addiu $a0, %lo(ptr_guard_data) # addiu $a0, $a0, -0x339c
  sw    $v0, ($a0)
  blez  $t0, .L7F000F40
   move  $v1, $zero
  move  $v0, $zero
  lw    $t1, ($a0)
.L7F000F20:
  addiu $v1, $v1, 1
  addu  $t2, $t1, $v0
  sw    $zero, 0x1c($t2)
  lw    $t3, ($a2)
  addiu $v0, $v0, 0x1dc
  slt   $at, $v1, $t3
  bnezl $at, .L7F000F20
   lw    $t1, ($a0)
.L7F000F40:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel set_new_rand_head_bodies
  lui   $t6, %hi(c_item_entries) 
  lw    $t6, %lo(c_item_entries)($t6)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  beqz  $t6, .L7F000F88
   sw    $a0, 0x18($sp)
  lui   $t7, %hi(c_item_entries)
  addiu $v0, $t7, %lo(c_item_entries)
  lw    $v1, ($v0)
  sw    $zero, ($v1)
.L7F000F78:
  lw    $v1, 0x14($v0)
  addiu $v0, $v0, 0x14
  bnezl $v1, .L7F000F78
   sw    $zero, ($v1)
.L7F000F88:
  jal   get_random_value
   nop   
  lui   $t8, %hi(num_male_heads) 
  lw    $t8, %lo(num_male_heads)($t8)
  lui   $at, %hi(current_random_male_head)
  divu  $zero, $v0, $t8
  mfhi  $t9
  sw    $t9, %lo(current_random_male_head)($at)
  bnez  $t8, .L7F000FB4
   nop   
  break 7
.L7F000FB4:
  jal   get_random_value
   nop   
  lui   $t0, %hi(num_female_heads) 
  lw    $t0, %lo(num_female_heads)($t0)
  lui   $at, %hi(current_random_female_head)
  divu  $zero, $v0, $t0
  mfhi  $t1
  sw    $t1, %lo(current_random_female_head)($at)
  bnez  $t0, .L7F000FE0
   nop   
  break 7
.L7F000FE0:
  jal   get_random_value
   nop   
  lui   $t2, %hi(num_bodies) 
  lw    $t2, %lo(num_bodies)($t2)
  lw    $ra, 0x14($sp)
  lui   $at, %hi(current_random_body)
  divu  $zero, $v0, $t2
  mfhi  $t3
  sw    $t3, %lo(current_random_body)($at)
  bnez  $t2, .L7F001010
   nop   
  break 7
.L7F001010:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop
");
