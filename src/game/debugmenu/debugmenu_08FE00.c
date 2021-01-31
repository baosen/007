int highlighted_debug_option = 0;
int ptr_last_debuggrp_cutoff = 0;
int ptr_textptrs = 0;
int ptr_positions = 0;
int number_groups = 0;
int ptr_groupings = 0;
int num_mcm_something = 2;
unsigned int mcm_xoffset_multiplier = 0x4040400,
             mcm_yoffset_multiplier = 0x7070700;

const char aMenu_cErrorTriedToCallFont_makegt[] =
    "menu.c: ERROR! Tried to call font_makegt\n";

void nullsub_32(void) {}

void sub_GAME_7F08FE08(int param_1) { num_mcm_something = param_1; }

asm(R"
glabel init_debug_menu_values
  lui   $at, %hi(ptr_textptrs)
  sw    $a0, %lo(ptr_textptrs)($at)
  lui   $at, %hi(ptr_positions)
  sw    $a1, %lo(ptr_positions)($at)
  lui   $at, %hi(ptr_groupings)
  sw    $a2, %lo(ptr_groupings)($at)
  lw    $t6, ($a2)
  move  $v0, $zero
  move  $v1, $a2
  bltzl $t6, .L7F08FE58
   sll   $t8, $v0, 2
  lw    $t7, 4($v1)
.L7F08FE44:
  addiu $v0, $v0, 1
  addiu $v1, $v1, 4
  bgezl $t7, .L7F08FE44
   lw    $t7, 4($v1)
  sll   $t8, $v0, 2
.L7F08FE58:
  addu  $t9, $a2, $t8
  lw    $t0, -4($t9)
  lui   $at, %hi(ptr_last_debuggrp_cutoff)
  sw    $t0, %lo(ptr_last_debuggrp_cutoff)($at)
  lui   $at, %hi(number_groups)
  jr    $ra
   sw    $v0, %lo(number_groups)($at)
");

asm(R"
glabel print_debug_mcm_to_stdout
  addiu $sp, $sp, -0x40
  lui   $v0, %hi(num_mcm_something)
  lw    $v0, %lo(num_mcm_something)($v0)
  lui   $t6, %hi(ptr_last_debuggrp_cutoff) 
  lw    $t6, %lo(ptr_last_debuggrp_cutoff)($t6)
  sw    $fp, 0x38($sp)
  sw    $s7, 0x34($sp)
  lui   $s7, %hi(mcm_xoffset_multiplier)
  lui   $fp, %hi(mcm_yoffset_multiplier)
  sw    $s0, 0x18($sp)
  addu  $s7, $s7, $v0
  addu  $fp, $fp, $v0
  sw    $ra, 0x3c($sp)
  sw    $s6, 0x30($sp)
  sw    $s5, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $a0, 0x40($sp)
  lbu   $s7, %lo(mcm_xoffset_multiplier)($s7)
  lbu   $fp, %lo(mcm_yoffset_multiplier)($fp)
  blez  $t6, .L7F08FFD8
   move  $s0, $zero
  lui   $s6, %hi(ptr_textptrs)
  lui   $s4, %hi(ptr_positions)
  lui   $s3, %hi(highlighted_debug_option)
  addiu $s3, %lo(highlighted_debug_option) # addiu $s3, $s3, 0x6b70
  addiu $s4, %lo(ptr_positions) # addiu $s4, $s4, 0x6b7c
  addiu $s6, %lo(ptr_textptrs) # addiu $s6, $s6, 0x6b78
  move  $s1, $zero
  move  $s2, $zero
  li    $s5, 7
.L7F08FEF8:
  jal   nullsub_32
   nop   
  lw    $t7, ($s3)
  li    $a0, 192
  li    $a1, 192
  bne   $s0, $t7, .L7F08FF30
   li    $a2, 192
  li    $a0, 192
  move  $a1, $zero
  move  $a2, $zero
  jal   set_debug_text_color
   li    $a3, 192
  b     .L7F08FF3C
   lw    $t8, ($s4)
.L7F08FF30:
  jal   set_debug_text_color
   li    $a3, 192
  lw    $t8, ($s4)
.L7F08FF3C:
  addu  $v0, $t8, $s1
  lw    $t9, ($v0)
  lw    $t1, 4($v0)
  multu $t9, $s7
  mflo  $a0
  addiu $a0, $a0, -0x14
  bgez  $a0, .L7F08FF64
   sra   $t0, $a0, 2
  addiu $at, $a0, 3
  sra   $t0, $at, 2
.L7F08FF64:
  multu $t1, $fp
  move  $a0, $t0
  mflo  $t2
  addiu $t3, $t2, -8
  nop   
  div   $zero, $t3, $s5
  mflo  $a1
  bnez  $s5, .L7F08FF8C
   nop   
  break 7
.L7F08FF8C:
  li    $at, -1
  bne   $s5, $at, .L7F08FFA4
   lui   $at, 0x8000
  bne   $t3, $at, .L7F08FFA4
   nop   
  break 6
.L7F08FFA4:
  jal   set_final_debug_text_positions
   nop   
  lw    $t4, ($s6)
  addu  $t5, $t4, $s2
  jal   write_string_stdout
   lw    $a0, ($t5)
  lui   $t6, %hi(ptr_last_debuggrp_cutoff) 
  lw    $t6, %lo(ptr_last_debuggrp_cutoff)($t6)
  addiu $s0, $s0, 1
  addiu $s1, $s1, 8
  slt   $at, $s0, $t6
  bnez  $at, .L7F08FEF8
   addiu $s2, $s2, 4
.L7F08FFD8:
  lw    $ra, 0x3c($sp)
  lw    $v0, 0x40($sp)
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

asm(R"
glabel sub_GAME_7F09000C
  addiu $sp, $sp, -0x40
  sw    $s5, 0x2c($sp)
  lui   $v0, %hi(num_mcm_something)
  lw    $v0, %lo(num_mcm_something)($v0)
  lui   $s5, %hi(ptr_last_debuggrp_cutoff)
  addiu $s5, %lo(ptr_last_debuggrp_cutoff) # addiu $s5, $s5, 0x6b74
  lw    $t6, ($s5)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  lui   $s3, %hi(mcm_xoffset_multiplier)
  lui   $s4, %hi(mcm_yoffset_multiplier)
  sw    $s0, 0x18($sp)
  addu  $s3, $s3, $v0
  addu  $s4, $s4, $v0
  sw    $ra, 0x3c($sp)
  sw    $fp, 0x38($sp)
  sw    $s7, 0x34($sp)
  sw    $s6, 0x30($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $a0, 0x40($sp)
  sw    $a1, 0x44($sp)
  sw    $a2, 0x48($sp)
  lbu   $s3, %lo(mcm_xoffset_multiplier)($s3)
  lbu   $s4, %lo(mcm_yoffset_multiplier)($s4)
  blez  $t6, .L7F090180
   move  $s0, $zero
  lui   $s7, %hi(ptr_positions) 
  lui   $s6, %hi(highlighted_debug_option)
  addiu $s6, %lo(highlighted_debug_option) # addiu $s6, $s6, 0x6b70
  addiu $s7, %lo(ptr_positions) # addiu $s7, $s7, 0x6b7c
  move  $s1, $zero
  move  $s2, $zero
  li    $fp, 7
.L7F090094:
  jal   nullsub_32
   nop   
  lw    $t7, ($s6)
  li    $a0, 192
  li    $a1, 192
  bne   $s0, $t7, .L7F0900CC
   li    $a2, 192
  li    $a0, 192
  move  $a1, $zero
  move  $a2, $zero
  jal   set_debug_text_color
   li    $a3, 192
  b     .L7F0900D8
   lw    $t8, ($s7)
.L7F0900CC:
  jal   set_debug_text_color
   li    $a3, 192
  lw    $t8, ($s7)
.L7F0900D8:
  addu  $v0, $t8, $s1
  lw    $t9, ($v0)
  lw    $t1, 4($v0)
  multu $t9, $s3
  mflo  $a0
  addiu $a0, $a0, -0x14
  bgez  $a0, .L7F090100
   sra   $t0, $a0, 2
  addiu $at, $a0, 3
  sra   $t0, $at, 2
.L7F090100:
  multu $t1, $s4
  move  $a0, $t0
  mflo  $t2
  addiu $t3, $t2, -8
  nop   
  div   $zero, $t3, $fp
  mflo  $a1
  bnez  $fp, .L7F090128
   nop   
  break 7
.L7F090128:
  li    $at, -1
  bne   $fp, $at, .L7F090140
   lui   $at, 0x8000
  bne   $t3, $at, .L7F090140
   nop   
  break 6
.L7F090140:
  jal   set_final_debug_text_positions
   nop   
  lui   $t4, %hi(ptr_textptrs) 
  lw    $t4, %lo(ptr_textptrs)($t4)
  addu  $t5, $t4, $s2
  jal   write_string_stdout
   lw    $a0, ($t5)
  lui   $a0, %hi(aMenu_cErrorTriedToCallFont_makegt)
  jal   osSyncPrintf
   addiu $a0, %lo(aMenu_cErrorTriedToCallFont_makegt) # addiu $a0, $a0, 0x5340
  lw    $t6, ($s5)
  addiu $s0, $s0, 1
  addiu $s1, $s1, 8
  slt   $at, $s0, $t6
  bnez  $at, .L7F090094
   addiu $s2, $s2, 4
.L7F090180:
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

int get_highlighted_debug_option(void) { return highlighted_debug_option; }

void sub_GAME_7F0901BC(int value) { highlighted_debug_option = value; }

asm(R"
glabel sub_GAME_7F0901C8
  lui   $a2, %hi(highlighted_debug_option)
  addiu $a2, %lo(highlighted_debug_option) # addiu $a2, $a2, 0x6b70
  lw    $t6, ($a2)
  lui   $t8, %hi(ptr_groupings) 
  lui   $a0, %hi(number_groups)
  addiu $v0, $t6, -1
  bgez  $v0, .L7F0901FC
   sw    $v0, ($a2)
  lw    $t8, %lo(ptr_groupings)($t8)
  lw    $t9, ($t8)
  addiu $t0, $t9, -1
  jr    $ra
   sw    $t0, ($a2)

.L7F0901FC:
  lw    $a0, %lo(number_groups)($a0)
  move  $v1, $zero
  lui   $a1, %hi(ptr_groupings)
  blez  $a0, .L7F090240
   nop   
  lw    $a1, %lo(ptr_groupings)($a1)
.L7F090214:
  lw    $t2, ($a1)
  addiu $v1, $v1, 1
  addiu $t1, $v0, 1
  bne   $t1, $t2, .L7F090238
   slt   $at, $v1, $a0
  lw    $t3, 4($a1)
  addiu $t4, $t3, -1
  jr    $ra
   sw    $t4, ($a2)

.L7F090238:
  bnez  $at, .L7F090214
   addiu $a1, $a1, 4
.L7F090240:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F090248
  lui   $a3, %hi(highlighted_debug_option)
  addiu $a3, %lo(highlighted_debug_option) # addiu $a3, $a3, 0x6b70
  lw    $t6, ($a3)
  lui   $v1, %hi(ptr_groupings)
  lui   $a1, %hi(number_groups)
  addiu $v0, $t6, 1
  sw    $v0, ($a3)
  lw    $v1, %lo(ptr_groupings)($v1)
  lw    $t8, ($v1)
  bne   $v0, $t8, .L7F09027C
   nop   
  jr    $ra
   sw    $zero, ($a3)

.L7F09027C:
  lw    $a1, %lo(number_groups)($a1)
  move  $a0, $zero
  move  $a2, $v1
  blez  $a1, .L7F0902B8
   nop   
.L7F090290:
  lw    $t9, ($a2)
  addiu $a0, $a0, 1
  slt   $at, $a0, $a1
  bne   $v0, $t9, .L7F0902B0
   nop   
  lw    $t0, -4($a2)
  jr    $ra
   sw    $t0, ($a3)

.L7F0902B0:
  bnez  $at, .L7F090290
   addiu $a2, $a2, 4
.L7F0902B8:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0902C0
  lui   $v1, %hi(ptr_groupings)
  lw    $v1, %lo(ptr_groupings)($v1)
  lui   $t0, %hi(highlighted_debug_option) 
  addiu $t0, %lo(highlighted_debug_option) # addiu $t0, $t0, 0x6b70
  lw    $v0, ($t0)
  lw    $a0, ($v1)
  lui   $a1, %hi(number_groups)
  slt   $at, $v0, $a0
  beqz  $at, .L7F090304
   addu  $t6, $v0, $a0
  sw    $t6, ($t0)
  lw    $a1, 4($v1)
  slt   $at, $t6, $a1
  bnez  $at, .L7F090394
   addiu $t8, $a1, -1
  jr    $ra
   sw    $t8, ($t0)

.L7F090304:
  lw    $a1, %lo(number_groups)($a1)
  move  $a0, $zero
  move  $a2, $v1
  blez  $a1, .L7F090394
   nop   
.L7F090318:
  lw    $a3, ($a2)
  addiu $a0, $a0, 1
  slt   $at, $v0, $a3
  beql  $at, $zero, .L7F09038C
   slt   $at, $a0, $a1
  lw    $t1, -4($a2)
  addu  $t9, $v0, $a3
  subu  $t2, $t9, $t1
  sw    $t2, ($t0)
  lw    $a0, 4($a2)
  bgezl $a0, .L7F090370
   lw    $t8, ($t0)
  lw    $t4, ($a2)
  subu  $t5, $t2, $t4
  sw    $t5, ($t0)
  lw    $a0, ($v1)
  slt   $at, $t5, $a0
  bnez  $at, .L7F090394
   addiu $t7, $a0, -1
  jr    $ra
   sw    $t7, ($t0)

  lw    $t8, ($t0)
.L7F090370:
  addiu $t9, $a0, -1
  slt   $at, $t8, $a0
  bnez  $at, .L7F090394
   nop   
  jr    $ra
   sw    $t9, ($t0)

  slt   $at, $a0, $a1
.L7F09038C:
  bnez  $at, .L7F090318
   addiu $a2, $a2, 4
.L7F090394:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F09039C
  lui   $v1, %hi(ptr_groupings)
  lw    $v1, %lo(ptr_groupings)($v1)
  lui   $a3, %hi(highlighted_debug_option)
  addiu $a3, %lo(highlighted_debug_option) # addiu $a3, $a3, 0x6b70
  lw    $v0, ($a3)
  lw    $a0, ($v1)
  lui   $a1, %hi(number_groups)
  slt   $at, $v0, $a0
  beql  $at, $zero, .L7F090418
   slt   $at, $v0, $a0
  lw    $a1, %lo(number_groups)($a1)
  move  $a0, $zero
  addiu $a1, $a1, -1
  blezl $a1, .L7F0903EC
   sll   $t6, $a0, 2
  addiu $a0, $a0, 1
.L7F0903DC:
  slt   $at, $a0, $a1
  bnezl $at, .L7F0903DC
   addiu $a0, $a0, 1
  sll   $t6, $a0, 2
.L7F0903EC:
  addu  $a1, $v1, $t6
  lw    $t7, -4($a1)
  addu  $t8, $v0, $t7
  sw    $t8, ($a3)
  lw    $a2, ($a1)
  slt   $at, $t8, $a2
  bnez  $at, .L7F090480
   addiu $t0, $a2, -1
  jr    $ra
   sw    $t0, ($a3)

  slt   $at, $v0, $a0
.L7F090418:
  bnez  $at, .L7F09043C
   move  $a1, $zero
  move  $a0, $v1
  lw    $t1, 4($a0)
.L7F090428:
  addiu $a1, $a1, 1
  addiu $a0, $a0, 4
  slt   $at, $v0, $t1
  beql  $at, $zero, .L7F090428
   lw    $t1, 4($a0)
.L7F09043C:
  sll   $t2, $a1, 2
  addu  $a0, $v1, $t2
  lw    $t3, -4($a0)
  addiu $t5, $a1, -2
  subu  $t4, $v0, $t3
  bltz  $t5, .L7F090464
   sw    $t4, ($a3)
  lw    $t7, -8($a0)
  addu  $t8, $t4, $t7
  sw    $t8, ($a3)
.L7F090464:
  lw    $v0, -4($a0)
  lw    $t9, ($a3)
  addiu $t0, $v0, -1
  slt   $at, $t9, $v0
  bnez  $at, .L7F090480
   nop   
  sw    $t0, ($a3)
.L7F090480:
  jr    $ra
   nop   
");
