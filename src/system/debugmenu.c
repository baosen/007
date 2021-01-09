#include <stddef.h>
#include <types.h>

extern int debug_menu_x_pos_offset;
extern int debug_menu_y_pos_offset;
extern int debug_menu_x_text_pos;
extern int debug_menu_y_text_pos;

unsigned int dummied_function_7000AD80(int arg0, int arg1) { return 0; }

unsigned int dummied_function_7000AD90(int arg0, int arg1) { return 0; }

void null_function_7000ADA0(void) {}

void null_init_main_0(void) {}

void debug_text_related_2(void) {
  void blank_debug_buffer_chars(void);
  blank_debug_buffer_chars();
}

asm(R"
glabel display_text_to_coord
  sw    $a2, 8($sp)
  andi  $t6, $a2, 0xff
  lui   $v1, %hi(debug_text_color)
  lui   $t0, %hi(stdout_primary_color_table) 
  lui   $t2, %hi(stdout_environment_color_table) 
  lui   $t1, %hi(debug_text_bg_color) 
  move  $a2, $t6
  sw    $a0, ($sp)
  addiu $t1, %lo(debug_text_bg_color) # addiu $t1, $t1, 0x68b0
  addiu $t2, %lo(stdout_environment_color_table) # addiu $t2, $t2, 0x6710
  addiu $t0, %lo(stdout_primary_color_table) # addiu $t0, $t0, 0x6610
  lw    $v1, %lo(debug_text_color)($v1)
  move  $v0, $zero
  move  $a3, $zero
.L7000AE08:
  lw    $t7, 4($t0)
  addiu $t0, $t0, 8
  addu  $t9, $t2, $a3
  bnel  $v1, $t7, .L7000AE30
   addiu $v0, $v0, 1
  lw    $t8, 4($t1)
  lw    $t3, 4($t9)
  beql  $t8, $t3, .L7000AEA8
   lw    $t6, ($sp)
  addiu $v0, $v0, 1
.L7000AE30:
  slti  $at, $v0, 0x20
  bnez  $at, .L7000AE08
   addiu $a3, $a3, 8
  lui   $a3, %hi(string_formatting)
  addiu $a3, %lo(string_formatting) # addiu $a3, $a3, 0x6810
  lw    $v1, ($a3)
  lui   $t6, %hi(stdout_primary_color) 
  addiu $t6, %lo(stdout_primary_color) # addiu $t6, $t6, 0x68a8
  lw    $at, ($t6)
  lui   $t4, %hi(stdout_primary_color_table) 
  addiu $t4, %lo(stdout_primary_color_table) # addiu $t4, $t4, 0x6610
  sll   $a0, $v1, 3
  addu  $t5, $a0, $t4
  sw    $at, ($t5)
  lw    $t9, 4($t6)
  addu  $t8, $t2, $a0
  addiu $t7, $v1, 1
  sw    $t9, 4($t5)
  lw    $at, ($t1)
  sw    $at, ($t8)
  lw    $t4, 4($t1)
  sw    $t4, 4($t8)
  bgez  $t7, .L7000AE9C
   andi  $t5, $t7, 0x1f
  beqz  $t5, .L7000AE9C
   nop   
  addiu $t5, $t5, -0x20
.L7000AE9C:
  sw    $t5, ($a3)
  move  $v0, $t5
  lw    $t6, ($sp)
.L7000AEA8:
  sll   $t3, $a1, 1
  lui   $t4, %hi(stdout_debug_menu_screen_buffer) 
  sll   $t9, $t6, 3
  addu  $t9, $t9, $t6
  sll   $t9, $t9, 2
  subu  $t9, $t9, $t6
  sll   $t9, $t9, 1
  addu  $t8, $t9, $t3
  addiu $t4, %lo(stdout_debug_menu_screen_buffer) # addiu $t4, $t4, 0x5030
  addu  $v1, $t8, $t4
  sb    $a2, ($v1)
  jr    $ra
   sb    $v0, 1($v1)
");

void debugMenuSetTextPOStoOffset(void) {
  debug_menu_x_text_pos = debug_menu_x_pos_offset;
  debug_menu_y_text_pos = debug_menu_y_pos_offset;
}

void blank_debug_buffer_chars(void) {
  extern char *string_formatting[];

  int x, y;
  for (y = 0; y < 35; y++)
    for (x = 0; x < 80; x++)
      display_text_to_coord(x, y, '\0');
  debugMenuSetTextPOStoOffset();
  null_function_7000ADA0();
  string_formatting[0] = NULL;
}

void stubbed_function_7000AF84(int arg0, int arg1, int arg2, int arg3) {}

asm(R"
glabel something_debug_info_related
  addiu $sp, $sp, -0x28
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $ra, 0x24($sp)
  sw    $s0, 0x14($sp)
  li    $s1, 33
  li    $s2, 80
  addiu $s3, $a0, 0x21
.L7000AFBC:
  bltz  $s3, .L7000AFF4
   slti  $at, $s3, 0x23
  beqz  $at, .L7000AFF4
   move  $s0, $zero
  move  $a0, $s0
.L7000AFD0:
  move  $a1, $s3
  move  $a2, $s0
  jal   stubbed_function_7000AF84
   move  $a3, $s1
  addiu $s0, $s0, 1
  bnel  $s0, $s2, .L7000AFD0
   move  $a0, $s0
  b     .L7000B018
   move  $v0, $s1
.L7000AFF4:
  move  $s0, $zero
  move  $a0, $s0
.L7000AFFC:
  move  $a1, $s1
  jal   display_text_to_coord
   move  $a2, $zero
  addiu $s0, $s0, 1
  bnel  $s0, $s2, .L7000AFFC
   move  $a0, $s0
  move  $v0, $s1
.L7000B018:
  addiu $s3, $s3, -1
  bnez  $s1, .L7000AFBC
   addiu $s1, $s1, -1
  lw    $ra, 0x24($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
glabel set_final_debug_text_positions
  lui   $t6, %hi(debug_menu_x_pos_offset) 
  lw    $t6, %lo(debug_menu_x_pos_offset)($t6)
  lui   $t7, %hi(debug_menu_y_pos_offset) 
  lw    $t7, %lo(debug_menu_y_pos_offset)($t7)
  lui   $at, %hi(debug_menu_x_text_pos)
  addu  $a0, $a0, $t6
  sw    $a0, %lo(debug_menu_x_text_pos)($at)
  lui   $at, %hi(debug_menu_y_text_pos)
  addu  $a1, $a1, $t7
  jr    $ra
   sw    $a1, %lo(debug_menu_y_text_pos)($at)
");

void set_debug_text_color(int red, int blue, int green, int alpha) {
  extern unsigned int debug_text_color;
  debug_text_color = red << 24 | blue << 16 | green << 8 | 255U - alpha;
}

void set_color_speedgraph(int red, int green, int blue, int alpha) {
  extern unsigned int speedgraph_color;
  speedgraph_color = red << 24 | green << 16 | blue << 8 | 255U - alpha;
}

asm(R"
glabel write_char_to_screen
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  jal   get_video2_settings_txtClipW
   sw    $a0, 0x28($sp)
  addiu $t6, $v0, -0xd
  bgez  $t6, .L7000B0E8
   sra   $t7, $t6, 2
  addiu $at, $t6, 3
  sra   $t7, $at, 2
.L7000B0E8:
  jal   get_video2_settings_txtClipH
   sw    $t7, 0x24($sp)
  addiu $t0, $v0, -0xa
  li    $at, 7
  div   $zero, $t0, $at
  lbu   $a2, 0x2b($sp)
  mflo  $t0
  lui   $v0, %hi(debug_menu_x_text_pos)
  beqz  $a2, .L7000B120
   move  $v1, $a2
  slti  $at, $v1, 0x20
  bnez  $at, .L7000B148
   slti  $at, $v1, 0x7f
  beqz  $at, .L7000B148
.L7000B120:
   lui   $a3, %hi(debug_menu_y_text_pos)
  addiu $a3, %lo(debug_menu_y_text_pos) # addiu $a3, $a3, 0x4fac
  addiu $v0, %lo(debug_menu_x_text_pos) # addiu $v0, $v0, 0x4fa8
  lw    $a0, ($v0)
  lw    $a1, ($a3)
  sw    $v1, 0x1c($sp)
  jal   display_text_to_coord
   sw    $t0, 0x20($sp)
  lw    $v1, 0x1c($sp)
  lw    $t0, 0x20($sp)
.L7000B148:
  lui   $v0, %hi(debug_menu_x_text_pos)
  addiu $v0, %lo(debug_menu_x_text_pos) # addiu $v0, $v0, 0x4fa8
  lw    $t9, ($v0)
  lui   $a3, %hi(debug_menu_y_text_pos)
  li    $at, 13
  addiu $t1, $t9, 1
  addiu $a3, %lo(debug_menu_y_text_pos) # addiu $a3, $a3, 0x4fac
  beq   $v1, $at, .L7000B184
   sw    $t1, ($v0)
  li    $at, 10
  beq   $v1, $at, .L7000B184
   lw    $t3, 0x24($sp)
  slt   $at, $t1, $t3
  bnezl $at, .L7000B1B4
   lw    $ra, 0x14($sp)
.L7000B184:
  lw    $t5, ($a3)
  lui   $t4, %hi(debug_menu_x_pos_offset) 
  lw    $t4, %lo(debug_menu_x_pos_offset)($t4)
  addiu $t6, $t5, 1
  slt   $at, $t6, $t0
  sw    $t6, ($a3)
  bnez  $at, .L7000B1B0
   sw    $t4, ($v0)
  lui   $t8, %hi(debug_menu_y_pos_offset) 
  lw    $t8, %lo(debug_menu_y_pos_offset)($t8)
  sw    $t8, ($a3)
.L7000B1B0:
  lw    $ra, 0x14($sp)
.L7000B1B4:
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

void debug_printcharatpos(int x, int y, unsigned char character) {
  set_final_debug_text_positions(x, y);
  write_char_to_screen(character);
}

asm(R"
glabel write_string_stdout
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  lbu   $s0, ($a0)
  move  $s1, $a0
  beqz  $s0, .L7000B21C
   andi  $a0, $s0, 0xff
.L7000B208:
  jal   write_char_to_screen
   addiu $s1, $s1, 1
  lbu   $s0, ($s1)
  bnezl $s0, .L7000B208
   andi  $a0, $s0, 0xff
.L7000B21C:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x20
");

asm(R"
glabel debug_text_related
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  move  $s1, $a2
  jal   set_final_debug_text_positions
   sw    $s0, 0x14($sp)
  lbu   $s0, ($s1)
  beqz  $s0, .L7000B268
   andi  $a0, $s0, 0xff
.L7000B254:
  jal   write_char_to_screen
   addiu $s1, $s1, 1
  lbu   $s0, ($s1)
  bnezl $s0, .L7000B254
   andi  $a0, $s0, 0xff
.L7000B268:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x20
");

asm(R"
glabel read_screen_display_block_and_write_chars
  addiu $sp, $sp, -0x88
  sw    $s5, 0x2c($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  lui   $a3, %hi(stdout_primary_color_table)
  move  $s0, $a0
  sw    $ra, 0x3c($sp)
  sw    $fp, 0x38($sp)
  sw    $s7, 0x34($sp)
  sw    $s6, 0x30($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  move  $s1, $a0
  li    $a2, -1
  addiu $a3, %lo(stdout_primary_color_table) # addiu $a3, $a3, 0x6610
  move  $s5, $zero
  move  $t0, $zero
.L7000B2C4:
  lui   $t6, %hi(stdout_debug_menu_screen_buffer)
  addiu $a1, $t6, %lo(stdout_debug_menu_screen_buffer)
  addu  $a0, $t0, $a1
.L7000B2D0:
  lbu   $v0, ($a0)
  addiu $a1, $a1, 0x46
  lbu   $v1, 1($a0)
  beqz  $v0, .L7000B2F8
   nop   
  beql  $v1, $a2, .L7000B2F8
   addiu $s1, $s1, 0x18
  addiu $s1, $s1, 0x10
  move  $a2, $v1
  addiu $s1, $s1, 0x18
.L7000B2F8:
  bne   $a1, $a3, .L7000B2D0
   addiu $a0, $a0, 0x46
  addiu $t0, $t0, 2
  slti  $at, $t0, 0x46
  bnez  $at, .L7000B2C4
   nop   
  jal   num_microcode_cmds_that_fit
   move  $a0, $s0
  subu  $a0, $s1, $s0
  bgtz  $a0, .L7000B32C
   addiu $v1, $v0, -0x800
  b     .L7000B528
   move  $v0, $s0
.L7000B32C:
  bgtz  $v1, .L7000B340
   li    $s4, -1
  lui   $at, %hi(D_800268B8)
  b     .L7000B398
   sw    $zero, %lo(D_800268B8)($at)
.L7000B340:
  slt   $at, $v1, $a0
  beqz  $at, .L7000B38C
   sll   $t7, $v1, 8
  subu  $t7, $t7, $v1
  div   $zero, $t7, $a0
  bnez  $a0, .L7000B360
   nop   
  break 7
.L7000B360:
  li    $at, -1
  bne   $a0, $at, .L7000B378
   lui   $at, 0x8000
  bne   $t7, $at, .L7000B378
   nop   
  break 6
.L7000B378:
  lui   $at, %hi(D_800268B8)
  mflo  $t8
  sw    $t8, %lo(D_800268B8)($at)
  b     .L7000B39C
   move  $v0, $s0
.L7000B38C:
  li    $t9, 256
  lui   $at, %hi(D_800268B8)
  sw    $t9, %lo(D_800268B8)($at)
.L7000B398:
  move  $v0, $s0
.L7000B39C:
  lui   $t2, %hi(stdout_display_list) 
  addiu $t2, %lo(stdout_display_list) # addiu $t2, $t2, 0x4fb0
  lui   $t1, 0x600
  sw    $t1, ($v0)
  sw    $t2, 4($v0)
  lui   $fp, %hi(stdout_environment_color_table) 
  lui   $s7, %hi(stdout_primary_color_table) 
  addiu $s0, $s0, 8
  addiu $s7, %lo(stdout_primary_color_table) # addiu $s7, $s7, 0x6610
  addiu $fp, %lo(stdout_environment_color_table) # addiu $fp, $fp, 0x6710
  sw    $zero, 0x40($sp)
  move  $s5, $zero
  li    $s6, 80
.L7000B3D0:
  lw    $t3, 0x40($sp)
  lui   $t4, %hi(stdout_debug_menu_screen_buffer) 
  addiu $t4, %lo(stdout_debug_menu_screen_buffer) # addiu $t4, $t4, 0x5030
  move  $s1, $zero
  addu  $s2, $t3, $t4
.L7000B3E4:
  lbu   $s3, ($s2)
  lbu   $v1, 1($s2)
  beql  $s3, $zero, .L7000B504
   addiu $s1, $s1, 1
  beq   $v1, $s4, .L7000B42C
   sll   $v0, $v1, 3
  addu  $t5, $s7, $v0
  lw    $at, ($t5)
  addu  $t8, $fp, $v0
  addiu $s0, $s0, 0x10
  sw    $at, -0x10($s0)
  lw    $t7, 4($t5)
  move  $s4, $v1
  sw    $t7, -0xc($s0)
  lw    $at, ($t8)
  sw    $at, -8($s0)
  lw    $t1, 4($t8)
  sw    $t1, -4($s0)
.L7000B42C:
  jal   get_random_value
   nop   
  lui   $t3, %hi(D_800268B8) 
  lw    $t3, %lo(D_800268B8)($t3)
  andi  $t2, $v0, 0xff
  sltu  $at, $t2, $t3
  beql  $at, $zero, .L7000B504
   addiu $s1, $s1, 1
  jal   num_microcode_cmds_that_fit
   move  $a0, $s0
  slti  $at, $v0, 0x400
  bnez  $at, .L7000B500
   move  $v0, $s0
  sll   $v1, $s1, 4
  sll   $a0, $s5, 3
  subu  $a0, $a0, $s5
  addiu $t4, $v1, 0x10
  andi  $t6, $t4, 0xfff
  sll   $a0, $a0, 2
  andi  $t2, $v1, 0xfff
  sll   $t3, $t2, 0xc
  sll   $t5, $t6, 0xc
  addiu $t9, $a0, 0x1c
  andi  $t4, $a0, 0xfff
  lui   $at, 0xe400
  addiu $a2, $s3, -0x20
  sra   $t2, $a2, 5
  or    $t7, $t5, $at
  or    $t6, $t3, $t4
  andi  $t8, $t9, 0xfff
  or    $t1, $t7, $t8
  sll   $t3, $t2, 3
  subu  $t3, $t3, $t2
  addiu $s0, $s0, 8
  move  $a1, $s0
  sll   $t3, $t3, 5
  sw    $t1, ($v0)
  andi  $t8, $a2, 0x1f
  sw    $t6, 4($v0)
  sll   $t1, $t8, 0x17
  andi  $t4, $t3, 0xffff
  addiu $s0, $s0, 8
  lui   $t5, 0xb400
  sw    $t5, ($a1)
  move  $a3, $s0
  or    $t6, $t1, $t4
  sw    $t6, 4($a1)
  lui   $t9, (0x04000400 >> 16) # lui $t9, 0x400
  ori   $t9, (0x04000400 & 0xFFFF) # ori $t9, $t9, 0x400
  lui   $t5, 0xb300
  sw    $t5, ($a3)
  sw    $t9, 4($a3)
  addiu $s0, $s0, 8
.L7000B500:
  addiu $s1, $s1, 1
.L7000B504:
  bne   $s1, $s6, .L7000B3E4
   addiu $s2, $s2, 0x46
  lw    $t7, 0x40($sp)
  addiu $s5, $s5, 1
  li    $at, 35
  addiu $t8, $t7, 2
  bne   $s5, $at, .L7000B3D0
   sw    $t8, 0x40($sp)
  move  $v0, $s0
.L7000B528:
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
   addiu $sp, $sp, 0x88
");
