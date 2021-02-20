int D_80040E80 = 0;
int text_spacing = 0;
int text_orientation = 0;
int text_wordwrap = 0;
int overlap_correction = -1;
int text_bilevel_filter = 0;
int text_x = 0;
int text_y = 0;
int text_s = 0;
int text_t = 0;
int D_80040EA8 = 0;
int ptrFirstFontTableSmall = 0;
int ptrSecondFontTableSmall = 0;
int ptrFirstFontTableLarge = 0;
int ptrSecondFontTableLarge = 0;

unsigned short D_80040EBC[] = {0x0000, 0x5555, 0xaaaa, 0xffff, 0x0000, 0x5555,
                               0xaaaa, 0xffff, 0x0000, 0x5555, 0xaaaa, 0xffff,
                               0x0000, 0x5555, 0xaaaa, 0xffff};
unsigned int D_80040EDC = 0;
unsigned int D_80040EE0 = 0;

unsigned int D_80040EE4[] = {0x55555555, 0x55555555, 0xAAAAAAAA,
                             0xAAAAAAAA, 0xFFFFFFFF, 0xFFFFFFFF};
unsigned int D_80040EFC = 0;
unsigned int D_80040F00 = 0;

int D_80040F04 = 0xC;
int D_80040F08 = 0xB;
int D_80040F0C = 0;
int D_80040F10 = 0;
int D_80040F14 = 0;
int D_80040F18 = 0;
int D_80040F1C = 0xC;
int D_80040F20 = 0xB;
int D_80040F24 = 0;
int D_80040F28 = 0;

void null_init_textrelated(void) {}

void setTextSpacingInverted(int spacing) { text_spacing = -spacing; }

void setTextOrientation(int orientation) { text_orientation = orientation; }

void setTextWordWrap(int flag) { text_wordwrap = flag; }

void setTextOverlapCorrection(int flag) { overlap_correction = flag; }

asm(R"
glabel load_font_tables
  lui   $at, %hi(text_spacing)
  sw    $zero, %lo(text_spacing)($at)
  lui   $at, %hi(text_orientation)
  sw    $zero, %lo(text_orientation)($at)
  lui   $at, %hi(text_wordwrap)
  sw    $zero, %lo(text_wordwrap)($at)
  lui   $at, %hi(overlap_correction)
  li    $t6, -1
  sw    $t6, %lo(overlap_correction)($at)
  lui   $at, %hi(text_bilevel_filter)
  sw    $zero, %lo(text_bilevel_filter)($at)
  lui   $at, %hi(text_x)
  sw    $zero, %lo(text_x)($at)
  lui   $at, %hi(text_y)
  sw    $zero, %lo(text_y)($at)
  lui   $at, %hi(text_s)
  lui   $t7, %hi(0x000024B0) # $t7, 0
  lui   $t8, 0
  addiu $sp, $sp, -0x28
  sw    $zero, %lo(text_s)($at)
  addiu $t8, $t8, 0
  addiu $t7, %lo(0x000024B0) # addiu $t7, $t7, 0x24b0
  sw    $ra, 0x14($sp)
  lui   $at, %hi(text_t)
  subu  $a2, $t7, $t8
  sw    $zero, %lo(text_t)($at)
  move  $a0, $a2
  sw    $a2, 0x1c($sp)
  jal   mempAllocBytesInBank
   li    $a1, 4
  lui   $a3, %hi(ptrFirstFontTableSmall)
  lui   $t0, %hi(ptrSecondFontTableSmall) 
  addiu $t0, %lo(ptrSecondFontTableSmall) # addiu $t0, $t0, 0xeb0
  addiu $a3, %lo(ptrFirstFontTableSmall) # addiu $a3, $a3, 0xeac
  addiu $t9, $v0, 0x2a4
  lui   $a1, %hi(_fonttablectlsmall1) # $a1, 0x2e
  sw    $v0, ($a3)
  lw    $a2, 0x1c($sp)
  sw    $t9, ($t0)
  move  $a0, $v0
  jal   romCopy
   addiu $a1, %lo(_fonttablectlsmall1) # addiu $a1, $a1, 0x63f0
  lui   $a3, %hi(ptrFirstFontTableSmall)
  lui   $t0, %hi(ptrSecondFontTableSmall) 
  addiu $t0, %lo(ptrSecondFontTableSmall) # addiu $t0, $t0, 0xeb0
  addiu $a3, %lo(ptrFirstFontTableSmall) # addiu $a3, $a3, 0xeac
  move  $v1, $zero
.L7F0ACC68:
  lw    $t1, ($t0)
  lw    $t3, ($a3)
  addu  $v0, $t1, $v1
  lw    $t2, 0x14($v0)
  addiu $v1, $v1, 0x18
  slti  $at, $v1, 0x8d0
  addu  $t4, $t2, $t3
  bnez  $at, .L7F0ACC68
   sw    $t4, 0x14($v0)
  lui   $t5, %hi(0x00003540) # $t5, 0
  lui   $t6, 0
  addiu $t6, $t6, 0
  addiu $t5, %lo(0x00003540) # addiu $t5, $t5, 0x3540
  subu  $a2, $t5, $t6
  move  $a0, $a2
  sw    $a2, 0x1c($sp)
  jal   mempAllocBytesInBank
   li    $a1, 4
  lui   $a3, %hi(ptrFirstFontTableLarge)
  lui   $t0, %hi(ptrSecondFontTableLarge) 
  addiu $t0, %lo(ptrSecondFontTableLarge) # addiu $t0, $t0, 0xeb8
  addiu $a3, %lo(ptrFirstFontTableLarge) # addiu $a3, $a3, 0xeb4
  addiu $t7, $v0, 0x2a4
  lui   $a1, %hi(_fonttablectllarge1) # $a1, 0x2f
  sw    $v0, ($a3)
  lw    $a2, 0x1c($sp)
  sw    $t7, ($t0)
  move  $a0, $v0
  jal   romCopy
   addiu $a1, %lo(_fonttablectllarge1) # addiu $a1, $a1, -0x7760
  lui   $t0, %hi(ptrSecondFontTableLarge) 
  addiu $t0, %lo(ptrSecondFontTableLarge) # addiu $t0, $t0, 0xeb8
  lw    $v0, ($t0)
  lui   $a3, %hi(ptrFirstFontTableLarge)
  addiu $a3, %lo(ptrFirstFontTableLarge) # addiu $a3, $a3, 0xeb4
  lw    $t9, ($a3)
  lw    $t8, 0x14($v0)
  li    $v1, 48
  li    $a0, 2256
  addu  $t1, $t8, $t9
  sw    $t1, 0x14($v0)
  lw    $v0, ($t0)
  lw    $t3, ($a3)
  lw    $t2, 0x2c($v0)
  addu  $t4, $t2, $t3
  sw    $t4, 0x2c($v0)
.L7F0ACD20:
  lw    $t5, ($t0)
  lw    $t7, ($a3)
  addu  $v0, $t5, $v1
  lw    $t6, 0x14($v0)
  addu  $t8, $t6, $t7
  sw    $t8, 0x14($v0)
  lw    $t9, ($t0)
  lw    $t2, ($a3)
  addu  $v0, $t9, $v1
  lw    $t1, 0x2c($v0)
  addu  $t3, $t1, $t2
  sw    $t3, 0x2c($v0)
  lw    $t4, ($t0)
  lw    $t6, ($a3)
  addu  $v0, $t4, $v1
  lw    $t5, 0x44($v0)
  addu  $t7, $t5, $t6
  sw    $t7, 0x44($v0)
  lw    $t8, ($t0)
  lw    $t1, ($a3)
  addu  $v0, $t8, $v1
  lw    $t9, 0x5c($v0)
  addiu $v1, $v1, 0x60
  addu  $t2, $t9, $t1
  bne   $v1, $a0, .L7F0ACD20
   sw    $t2, 0x5c($v0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel microcode_constructor
  move  $v0, $a0
  addiu $a0, $a0, 8
  lui   $t6, 0xe700
  sw    $t6, ($v0)
  sw    $zero, 4($v0)
  move  $v1, $a0
  addiu $a0, $a0, 8
  lui   $t7, (0xBA001402 >> 16) # lui $t7, 0xba00
  ori   $t7, (0xBA001402 & 0xFFFF) # ori $t7, $t7, 0x1402
  move  $a1, $a0
  sw    $t7, ($v1)
  sw    $zero, 4($v1)
  addiu $a0, $a0, 8
  lui   $t8, (0xBA000602 >> 16) # lui $t8, 0xba00
  ori   $t8, (0xBA000602 & 0xFFFF) # ori $t8, $t8, 0x602
  li    $t9, 192
  move  $a2, $a0
  sw    $t9, 4($a1)
  sw    $t8, ($a1)
  addiu $a0, $a0, 8
  lui   $t0, (0xB900031D >> 16) # lui $t0, 0xb900
  lui   $t1, (0x005041C8 >> 16) # lui $t1, 0x50
  ori   $t1, (0x005041C8 & 0xFFFF) # ori $t1, $t1, 0x41c8
  ori   $t0, (0xB900031D & 0xFFFF) # ori $t0, $t0, 0x31d
  move  $a3, $a0
  sw    $t0, ($a2)
  sw    $t1, 4($a2)
  lui   $t2, (0xFCFF97FF >> 16) # lui $t2, 0xfcff
  lui   $t3, (0xFF2DFEFF >> 16) # lui $t3, 0xff2d
  ori   $t3, (0xFF2DFEFF & 0xFFFF) # ori $t3, $t3, 0xfeff
  ori   $t2, (0xFCFF97FF & 0xFFFF) # ori $t2, $t2, 0x97ff
  addiu $a0, $a0, 8
  sw    $t2, ($a3)
  sw    $t3, 4($a3)
  move  $v0, $a0
  addiu $a0, $a0, 8
  lui   $t4, (0xBA001301 >> 16) # lui $t4, 0xba00
  ori   $t4, (0xBA001301 & 0xFFFF) # ori $t4, $t4, 0x1301
  move  $v1, $a0
  sw    $t4, ($v0)
  sw    $zero, 4($v0)
  addiu $a0, $a0, 8
  lui   $t5, (0xB9000002 >> 16) # lui $t5, 0xb900
  ori   $t5, (0xB9000002 & 0xFFFF) # ori $t5, $t5, 2
  move  $a1, $a0
  sw    $t5, ($v1)
  sw    $zero, 4($v1)
  addiu $a0, $a0, 8
  lui   $t6, (0xBA001001 >> 16) # lui $t6, 0xba00
  ori   $t6, (0xBA001001 & 0xFFFF) # ori $t6, $t6, 0x1001
  move  $a2, $a0
  sw    $t6, ($a1)
  sw    $zero, 4($a1)
  lui   $t7, (0xBA000903 >> 16) # lui $t7, 0xba00
  ori   $t7, (0xBA000903 & 0xFFFF) # ori $t7, $t7, 0x903
  addiu $a0, $a0, 8
  li    $t8, 3072
  sw    $t8, 4($a2)
  sw    $t7, ($a2)
  move  $a3, $a0
  lui   $t9, (0xBA000E02 >> 16) # lui $t9, 0xba00
  ori   $t9, (0xBA000E02 & 0xFFFF) # ori $t9, $t9, 0xe02
  sw    $t9, ($a3)
  sw    $zero, 4($a3)
  lui   $t0, %hi(text_bilevel_filter) 
  lw    $t0, %lo(text_bilevel_filter)($t0)
  addiu $a0, $a0, 8
  move  $v0, $a0
  beqz  $t0, .L7F0ACED4
   lui   $t3, 0xba00
  move  $v0, $a0
  lui   $t1, (0xBA000C02 >> 16) # lui $t1, 0xba00
  ori   $t1, (0xBA000C02 & 0xFFFF) # ori $t1, $t1, 0xc02
  li    $t2, 12288
  sw    $t2, 4($v0)
  sw    $t1, ($v0)
  addiu $a0, $a0, 8
  jr    $ra
   move  $v0, $a0

.L7F0ACED4:
  ori   $t3, $t3, 0xc02
  li    $t4, 8192
  sw    $t4, 4($v0)
  sw    $t3, ($v0)
  addiu $a0, $a0, 8
  jr    $ra
   move  $v0, $a0
");

asm(R"
glabel combiner_bayer_lod_perspective
  addiu $a1, $a0, 8
  lui   $t6, 0xe700
  sw    $t6, ($a0)
  sw    $zero, 4($a0)
  lui   $t7, (0xBA000602 >> 16) # lui $t7, 0xba00
  ori   $t7, (0xBA000602 & 0xFFFF) # ori $t7, $t7, 0x602
  addiu $a2, $a1, 8
  li    $t8, 64
  sw    $t8, 4($a1)
  sw    $t7, ($a1)
  lui   $t9, (0xBA001301 >> 16) # lui $t9, 0xba00
  ori   $t9, (0xBA001301 & 0xFFFF) # ori $t9, $t9, 0x1301
  addiu $a3, $a2, 8
  lui   $t0, 8
  lui   $t1, (0xBA001001 >> 16) # lui $t1, 0xba00
  sw    $t0, 4($a2)
  sw    $t9, ($a2)
  ori   $t1, (0xBA001001 & 0xFFFF) # ori $t1, $t1, 0x1001
  lui   $t2, 1
  sw    $t2, 4($a3)
  sw    $t1, ($a3)
  jr    $ra
   addiu $v0, $a3, 8
");

asm(R"
glabel draw_blackbox_to_screen
  lui   $t2, (0xB900031D >> 16) # lui $t2, 0xb900
  lui   $t3, (0x00504240 >> 16) # lui $t3, 0x50
  move  $v0, $a0
  ori   $t3, (0x00504240 & 0xFFFF) # ori $t3, $t3, 0x4240
  ori   $t2, (0xB900031D & 0xFFFF) # ori $t2, $t2, 0x31d
  sw    $t2, ($v0)
  sw    $t3, 4($v0)
  lui   $t6, (0xFCFFFFFF >> 16) # lui $t6, 0xfcff
  lui   $t7, (0xFFFDF6FB >> 16) # lui $t7, 0xfffd
  addiu $a0, $a0, 8
  ori   $t7, (0xFFFDF6FB & 0xFFFF) # ori $t7, $t7, 0xf6fb
  ori   $t6, (0xFCFFFFFF & 0xFFFF) # ori $t6, $t6, 0xffff
  sw    $t6, ($a0)
  sw    $t7, 4($a0)
  addiu $t0, $a0, 8
  lui   $t8, 0xfa00
  sw    $t8, ($t0)
  sw    $zero, 4($t0)
  lw    $t9, 0x10($sp)
  lw    $t8, ($a3)
  lui   $at, 0xf600
  lw    $t4, ($t9)
  andi  $t9, $t8, 0x3ff
  addiu $t1, $t0, 8
  andi  $t5, $t4, 0x3ff
  sll   $t6, $t5, 2
  or    $t7, $t6, $at
  sll   $t4, $t9, 0xe
  or    $t5, $t7, $t4
  sw    $t5, ($t1)
  lw    $t7, ($a1)
  lw    $t6, ($a2)
  addiu $v1, $t1, 8
  andi  $t4, $t7, 0x3ff
  andi  $t8, $t6, 0x3ff
  sll   $t9, $t8, 2
  sll   $t5, $t4, 0xe
  or    $t6, $t9, $t5
  sw    $t6, 4($t1)
  addiu $a1, $v1, 8
  lui   $t8, (0xFCFF97FF >> 16) # lui $t8, 0xfcff
  lui   $t7, (0xFF2DFEFF >> 16) # lui $t7, 0xff2d
  sw    $t3, 4($v1)
  sw    $t2, ($v1)
  ori   $t7, (0xFF2DFEFF & 0xFFFF) # ori $t7, $t7, 0xfeff
  ori   $t8, (0xFCFF97FF & 0xFFFF) # ori $t8, $t8, 0x97ff
  sw    $t8, ($a1)
  sw    $t7, 4($a1)
  jr    $ra
   addiu $v0, $a1, 8
");

asm(R"
glabel microcode_constructor_related_to_menus
  move  $v0, $a0
  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
  lui   $t7, (0x00504240 >> 16) # lui $t7, 0x50
  ori   $t7, (0x00504240 & 0xFFFF) # ori $t7, $t7, 0x4240
  ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
  sw    $t6, ($v0)
  sw    $t7, 4($v0)
  lui   $t8, (0xFCFFFFFF >> 16) # lui $t8, 0xfcff
  lui   $t9, (0xFFFDF6FB >> 16) # lui $t9, 0xfffd
  addiu $a0, $a0, 8
  ori   $t9, (0xFFFDF6FB & 0xFFFF) # ori $t9, $t9, 0xf6fb
  ori   $t8, (0xFCFFFFFF & 0xFFFF) # ori $t8, $t8, 0xffff
  sw    $t8, ($a0)
  sw    $t9, 4($a0)
  addiu $t0, $a0, 8
  lui   $t2, 0xfa00
  sw    $t2, ($t0)
  lw    $t3, 0x14($sp)
  lui   $at, 0xf600
  addiu $t1, $t0, 8
  srl   $t9, $t3, 0x10
  andi  $t2, $t9, 0xff
  sll   $t4, $t2, 0x10
  srl   $t6, $t3, 0x18
  sll   $t7, $t6, 0x18
  srl   $t8, $t3, 8
  andi  $t9, $t8, 0xff
  or    $t5, $t7, $t4
  sll   $t2, $t9, 8
  move  $t4, $t3
  andi  $t6, $t4, 0xff
  or    $t7, $t5, $t2
  or    $t8, $t7, $t6
  sw    $t8, 4($t0)
  lw    $t3, 0x10($sp)
  andi  $t9, $a3, 0x3ff
  sll   $t5, $t9, 0xe
  or    $t2, $t5, $at
  andi  $t4, $t3, 0x3ff
  sll   $t7, $t4, 2
  or    $t6, $t2, $t7
  andi  $t5, $a2, 0x3ff
  andi  $t8, $a1, 0x3ff
  sll   $t9, $t8, 0xe
  sll   $t3, $t5, 2
  or    $t4, $t9, $t3
  addiu $v1, $t1, 8
  lui   $t7, (0xFF2DFEFF >> 16) # lui $t7, 0xff2d
  lui   $t2, (0xFCFF97FF >> 16) # lui $t2, 0xfcff
  sw    $t4, 4($t1)
  sw    $t6, ($t1)
  ori   $t2, (0xFCFF97FF & 0xFFFF) # ori $t2, $t2, 0x97ff
  ori   $t7, (0xFF2DFEFF & 0xFFFF) # ori $t7, $t7, 0xfeff
  sw    $t7, 4($v1)
  sw    $t2, ($v1)
  jr    $ra
   addiu $v0, $v1, 8
");

asm(R"
glabel sub_GAME_7F0AD0F8
  addiu $sp, $sp, -0xf0
  lw    $t9, 0x100($sp)
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  sw    $a1, 0xf4($sp)
  lw    $t4, 0x10($t9)
  lw    $t6, ($a2)
  lw    $t7, 0x118($sp)
  sll   $t5, $t4, 2
  subu  $t5, $t5, $t4
  lw    $t8, 0x104($sp)
  sll   $t5, $t5, 2
  lw    $t9, 0x10($a3)
  addu  $t5, $t5, $t4
  addu  $t1, $t6, $t7
  sll   $t6, $t5, 2
  addu  $t7, $t8, $t6
  sll   $t4, $t9, 2
  addu  $t5, $t7, $t4
  lui   $t6, %hi(text_spacing) 
  lw    $t6, %lo(text_spacing)($t6)
  lw    $t8, ($t5)
  lw    $t7, ($a1)
  move  $s0, $a0
  addu  $v0, $t8, $t6
  subu  $t4, $t7, $v0
  addiu $t5, $t4, 1
  sw    $t5, ($a1)
  lui   $t8, %hi(text_orientation) 
  lw    $t8, %lo(text_orientation)($t8)
  move  $s1, $a3
  bnezl $t8, .L7F0AD1CC
   lw    $a0, 0x108($sp)
  blezl $t5, .L7F0ADA94
   lw    $t4, 0xf4($sp)
  jal   get_video2_settings_txtClipW
   sw    $t1, 0xe0($sp)
  lw    $t6, 0xf4($sp)
  lw    $t1, 0xe0($sp)
  lw    $t7, ($t6)
  slt   $at, $v0, $t7
  bnezl $at, .L7F0ADA94
   lw    $t4, 0xf4($sp)
  jal   get_video2_settings_txtClipH
   sw    $t1, 0xe0($sp)
  lw    $t1, 0xe0($sp)
  lw    $t4, 4($s1)
  addu  $t9, $t1, $t4
  slt   $at, $v0, $t9
  bnezl $at, .L7F0ADA94
   lw    $t4, 0xf4($sp)
  lw    $a0, 0x108($sp)
.L7F0AD1CC:
  lw    $t8, 0x110($sp)
  lw    $t6, 0xf4($sp)
  lw    $t2, 0x10c($sp)
  addu  $t5, $a0, $t8
  sw    $t5, 0x24($sp)
  lw    $v0, ($t6)
  lw    $t4, 0x114($sp)
  slt   $at, $t5, $v0
  bnezl $at, .L7F0ADA94
   lw    $t4, 0xf4($sp)
  lw    $t9, 4($s1)
  addu  $t3, $t2, $t4
  addu  $v1, $t9, $t1
  slt   $at, $t3, $v1
  bnez  $at, .L7F0ADA90
   slt   $at, $v0, $a0
  bnezl $at, .L7F0ADA94
   lw    $t4, 0xf4($sp)
  lw    $t8, 8($s1)
  addu  $t5, $v1, $t8
  slt   $at, $t5, $t2
  bnezl $at, .L7F0ADA94
   lw    $t4, 0xf4($sp)
  lw    $t6, ($s1)
  lui   $a1, %hi(D_80040EA8)
  addiu $a1, %lo(D_80040EA8) # addiu $a1, $a1, 0xea8
  slti  $at, $t6, 0x80
  beqz  $at, .L7F0AD3F8
   move  $v0, $s0
  move  $v0, $s0
  lui   $t7, (0xBA000E02 >> 16) # lui $t7, 0xba00
  ori   $t7, (0xBA000E02 & 0xFFFF) # ori $t7, $t7, 0xe02
  addiu $s0, $s0, 8
  sw    $t7, ($v0)
  sw    $zero, 4($v0)
  move  $v1, $s0
  lui   $t4, 0xfd90
  sw    $t4, ($v1)
  lw    $t9, 0x14($s1)
  addiu $s0, $s0, 8
  move  $a0, $s0
  addiu $s0, $s0, 8
  sw    $t9, 4($v1)
  move  $a1, $s0
  lui   $t8, 0xf590
  lui   $t5, 0x700
  sw    $t5, 4($a0)
  sw    $t8, ($a0)
  addiu $s0, $s0, 8
  lui   $t6, 0xe600
  sw    $t6, ($a1)
  move  $t0, $s0
  sw    $zero, 4($a1)
  lui   $t7, 0xf300
  sw    $t7, ($t0)
  lw    $v1, 0xc($s1)
  lw    $t9, 8($s1)
  addiu $s0, $s0, 8
  addiu $v1, $v1, 7
  andi  $t4, $v1, 0xf8
  multu $t4, $t9
  move  $v1, $t4
  li    $a2, 2047
  mflo  $v0
  addiu $v0, $v0, 1
  sra   $t8, $v0, 1
  addiu $v0, $t8, -1
  slti  $at, $v0, 0x7ff
  beqz  $at, .L7F0AD2EC
   nop   
  b     .L7F0AD2EC
   move  $a2, $v0
.L7F0AD2EC:
  bgez  $v1, .L7F0AD2FC
   sra   $v0, $v1, 3
  addiu $at, $v1, 7
  sra   $v0, $at, 3
.L7F0AD2FC:
  bgtz  $v0, .L7F0AD30C
   andi  $t9, $a2, 0xfff
  b     .L7F0AD310
   li    $a3, 1
.L7F0AD30C:
  move  $a3, $v0
.L7F0AD310:
  bgtz  $v0, .L7F0AD320
   addiu $t5, $a3, 0x7ff
  b     .L7F0AD324
   li    $a1, 1
.L7F0AD320:
  move  $a1, $v0
.L7F0AD324:
  div   $zero, $t5, $a1
  bnez  $a1, .L7F0AD334
   nop   
  break 7
.L7F0AD334:
  li    $at, -1
  bne   $a1, $at, .L7F0AD34C
   lui   $at, 0x8000
  bne   $t5, $at, .L7F0AD34C
   nop   
  break 6
.L7F0AD34C:
  mflo  $t6
  andi  $t7, $t6, 0xfff
  lui   $at, 0x700
  or    $t4, $t7, $at
  sll   $t8, $t9, 0xc
  or    $t5, $t4, $t8
  sw    $t5, 4($t0)
  move  $v0, $s0
  lui   $t6, 0xe700
  sw    $t6, ($v0)
  sw    $zero, 4($v0)
  lw    $t7, 0xc($s1)
  addiu $s0, $s0, 8
  move  $v1, $s0
  addiu $t9, $t7, 7
  andi  $t4, $t9, 0xf8
  addiu $t8, $t4, 7
  sra   $t5, $t8, 3
  andi  $t6, $t5, 0x1ff
  sll   $t7, $t6, 9
  lui   $at, 0xf588
  or    $t9, $t7, $at
  addiu $s0, $s0, 8
  move  $a0, $s0
  sw    $t9, ($v1)
  lui   $t4, 0xf200
  sw    $zero, 4($v1)
  sw    $t4, ($a0)
  lw    $t8, 0xc($s1)
  addiu $s0, $s0, 8
  addiu $t5, $t8, 7
  andi  $t6, $t5, 0xf8
  lw    $t5, 8($s1)
  addiu $t7, $t6, -1
  sll   $t9, $t7, 2
  andi  $t4, $t9, 0xfff
  addiu $t6, $t5, -1
  sll   $t7, $t6, 2
  andi  $t9, $t7, 0xfff
  sll   $t8, $t4, 0xc
  or    $t4, $t8, $t9
  b     .L7F0AD6A4
   sw    $t4, 4($a0)
.L7F0AD3F8:
  addiu $s0, $s0, 8
  lui   $t5, 0xe700
  sw    $t5, ($v0)
  sw    $zero, 4($v0)
  move  $v1, $s0
  lui   $t6, (0xBA000E02 >> 16) # lui $t6, 0xba00
  ori   $t6, (0xBA000E02 & 0xFFFF) # ori $t6, $t6, 0xe02
  li    $t7, 49152
  sw    $t7, 4($v1)
  sw    $t6, ($v1)
  lw    $t8, ($a1)
  addiu $s0, $s0, 8
  move  $a3, $s0
  beqz  $t8, .L7F0AD588
   lui   $t9, 0xfd10
  sw    $zero, ($a1)
  sw    $t9, ($a3)
  lui   $a0, %hi(D_80040EBC)
  addiu $a0, %lo(D_80040EBC) # addiu $a0, $a0, 0xebc
  sw    $t3, 0x20($sp)
  sw    $t1, 0xe0($sp)
  sw    $a3, 0xb4($sp)
  jal   osVirtualToPhysical
   addiu $s0, $s0, 8
  lw    $a3, 0xb4($sp)
  lw    $t1, 0xe0($sp)
  lw    $t3, 0x20($sp)
  move  $v1, $s0
  addiu $s0, $s0, 8
  sw    $v0, 4($a3)
  move  $a0, $s0
  lui   $t4, 0xe800
  lui   $t5, (0xF5000100 >> 16) # lui $t5, 0xf500
  ori   $t5, (0xF5000100 & 0xFFFF) # ori $t5, $t5, 0x100
  sw    $t4, ($v1)
  sw    $zero, 4($v1)
  sw    $t5, ($a0)
  addiu $s0, $s0, 8
  lui   $t6, 0x700
  sw    $t6, 4($a0)
  move  $a1, $s0
  addiu $s0, $s0, 8
  move  $a2, $s0
  lui   $t7, 0xe600
  sw    $t7, ($a1)
  addiu $s0, $s0, 8
  sw    $zero, 4($a1)
  lui   $t9, (0x0703C000 >> 16) # lui $t9, 0x703
  ori   $t9, (0x0703C000 & 0xFFFF) # ori $t9, $t9, 0xc000
  move  $t0, $s0
  lui   $t8, 0xf000
  sw    $t8, ($a2)
  sw    $t9, 4($a2)
  addiu $s0, $s0, 8
  lui   $t4, 0xe700
  sw    $t4, ($t0)
  sw    $zero, 4($t0)
  move  $a3, $s0
  lui   $t5, 0xfd10
  sw    $t5, ($a3)
  lui   $a0, %hi(D_80040EDC)
  addiu $a0, %lo(D_80040EDC) # addiu $a0, $a0, 0xedc
  sw    $a3, 0x9c($sp)
  addiu $s0, $s0, 8
  sw    $t1, 0xe0($sp)
  jal   osVirtualToPhysical
   sw    $t3, 0x20($sp)
  lw    $a3, 0x9c($sp)
  lw    $t1, 0xe0($sp)
  lw    $t3, 0x20($sp)
  move  $v1, $s0
  addiu $s0, $s0, 8
  lui   $t6, 0xe800
  sw    $v0, 4($a3)
  sw    $t6, ($v1)
  move  $a0, $s0
  addiu $s0, $s0, 8
  sw    $zero, 4($v1)
  lui   $t7, (0xF5000110 >> 16) # lui $t7, 0xf500
  ori   $t7, (0xF5000110 & 0xFFFF) # ori $t7, $t7, 0x110
  move  $a1, $s0
  lui   $t8, 0x700
  sw    $t8, 4($a0)
  addiu $s0, $s0, 8
  sw    $t7, ($a0)
  move  $a2, $s0
  lui   $t9, 0xe600
  sw    $t9, ($a1)
  addiu $s0, $s0, 8
  sw    $zero, 4($a1)
  lui   $t5, (0x0703C000 >> 16) # lui $t5, 0x703
  ori   $t5, (0x0703C000 & 0xFFFF) # ori $t5, $t5, 0xc000
  move  $t0, $s0
  lui   $t4, 0xf000
  sw    $t4, ($a2)
  sw    $t5, 4($a2)
  lui   $t6, 0xe700
  sw    $t6, ($t0)
  sw    $zero, 4($t0)
  addiu $s0, $s0, 8
.L7F0AD588:
  move  $a1, $s0
  lui   $t7, 0xfd50
  sw    $t7, ($a1)
  lw    $a0, 0x14($s1)
  sw    $t3, 0x20($sp)
  sw    $t1, 0xe0($sp)
  sw    $a1, 0x84($sp)
  jal   osVirtualToPhysical
   addiu $s0, $s0, 8
  lw    $a1, 0x84($sp)
  lw    $t1, 0xe0($sp)
  lw    $t2, 0x10c($sp)
  lw    $t3, 0x20($sp)
  move  $v1, $s0
  addiu $s0, $s0, 8
  sw    $v0, 4($a1)
  lui   $t0, 0x700
  lui   $t8, 0xf550
  move  $a0, $s0
  sw    $t8, ($v1)
  sw    $t0, 4($v1)
  addiu $s0, $s0, 8
  lui   $t9, 0xe600
  sw    $t9, ($a0)
  sw    $zero, 4($a0)
  move  $a2, $s0
  lui   $t4, 0xf300
  sw    $t4, ($a2)
  lw    $a3, 8($s1)
  addiu $s0, $s0, 8
  move  $v0, $s0
  sll   $t5, $a3, 2
  addiu $a3, $t5, -1
  slti  $at, $a3, 0x7ff
  beqz  $at, .L7F0AD620
   addiu $s0, $s0, 8
  b     .L7F0AD624
   move  $a1, $a3
.L7F0AD620:
  li    $a1, 2047
.L7F0AD624:
  andi  $t6, $a1, 0xfff
  sll   $t7, $t6, 0xc
  or    $t8, $t7, $t0
  ori   $t9, $t8, 0x800
  sw    $t9, 4($a2)
  lui   $t4, 0xe700
  lui   $t5, (0xF5400200 >> 16) # lui $t5, 0xf540
  sw    $t4, ($v0)
  sw    $zero, 4($v0)
  ori   $t5, (0xF5400200 & 0xFFFF) # ori $t5, $t5, 0x200
  move  $v1, $s0
  sw    $t5, ($v1)
  lw    $t7, ($s1)
  lui   $at, 8
  addiu $s0, $s0, 8
  andi  $t8, $t7, 1
  sll   $t9, $t8, 0x14
  or    $t4, $t9, $at
  ori   $t5, $t4, 0x200
  sw    $t5, 4($v1)
  move  $a0, $s0
  lui   $t6, 0xf200
  sw    $t6, ($a0)
  lw    $t7, 8($s1)
  lui   $at, (0x0003C000 >> 16) # lui $at, 3
  ori   $at, (0x0003C000 & 0xFFFF) # ori $at, $at, 0xc000
  addiu $t8, $t7, -1
  sll   $t9, $t8, 2
  andi  $t4, $t9, 0xfff
  or    $t5, $t4, $at
  sw    $t5, 4($a0)
  addiu $s0, $s0, 8
.L7F0AD6A4:
  lw    $t6, 0xf4($sp)
  lw    $t8, 0xc($s1)
  lw    $t9, 0x24($sp)
  lw    $t7, ($t6)
  addu  $t0, $t7, $t8
  slt   $at, $t9, $t0
  bnezl $at, .L7F0ADA94
   lw    $t4, 0xf4($sp)
  lw    $a0, 4($s1)
  addu  $v1, $a0, $t1
  slt   $at, $v1, $t2
  bnezl $at, .L7F0AD9A4
   lw    $t6, 8($s1)
  lw    $t4, 8($s1)
  lui   $t5, %hi(text_orientation) 
  addu  $v0, $v1, $t4
  slt   $at, $t3, $v0
  bnezl $at, .L7F0AD8C8
   slt   $at, $t3, $v1
  lw    $t5, %lo(text_orientation)($t5)
  lui   $a2, %hi(text_x)
  addiu $a2, %lo(text_x) # addiu $a2, $a2, 0xe98
  beqz  $t5, .L7F0AD7F8
   lui   $a3, %hi(text_y)
  lui   $a2, %hi(text_x)
  addiu $a2, %lo(text_x) # addiu $a2, $a2, 0xe98
  lw    $t7, ($a2)
  lui   $a3, %hi(text_y)
  sll   $t6, $t0, 2
  addiu $a3, %lo(text_y) # addiu $a3, $a3, 0xe9c
  addu  $t8, $t6, $t7
  lw    $t7, ($a3)
  andi  $t9, $t8, 0xfff
  subu  $t5, $t1, $a0
  sll   $t6, $t5, 2
  lui   $at, 0xe500
  or    $t4, $t9, $at
  addu  $t8, $t6, $t7
  andi  $t9, $t8, 0xfff
  sll   $t5, $t9, 0xc
  or    $t6, $t4, $t5
  move  $v0, $s0
  sw    $t6, ($v0)
  lw    $t7, 0xf4($sp)
  lw    $t4, ($a2)
  addiu $s0, $s0, 8
  lw    $t8, ($t7)
  lw    $t7, 4($s1)
  move  $v1, $s0
  sll   $t9, $t8, 2
  addu  $t5, $t9, $t4
  lw    $t9, 8($s1)
  subu  $t8, $t1, $t7
  lw    $t7, ($a3)
  andi  $t6, $t5, 0xfff
  subu  $t4, $t8, $t9
  sll   $t5, $t4, 2
  addu  $t8, $t5, $t7
  andi  $t9, $t8, 0xfff
  sll   $t4, $t9, 0xc
  or    $t5, $t6, $t4
  sw    $t5, 4($v0)
  lui   $t7, 0xb400
  sw    $t7, ($v1)
  lw    $t8, 8($s1)
  lui   $t4, %hi(text_s) 
  lw    $t4, %lo(text_s)($t4)
  addiu $t9, $t8, -1
  sll   $t6, $t9, 5
  lui   $t8, %hi(text_t) 
  lw    $t9, %lo(text_t)($t8)
  addu  $t5, $t6, $t4
  andi  $t7, $t5, 0xffff
  addiu $s0, $s0, 8
  sll   $t6, $t9, 0x10
  or    $t4, $t6, $t7
  move  $a1, $s0
  lui   $t8, (0x0400FC00 >> 16) # lui $t8, 0x400
  ori   $t8, (0x0400FC00 & 0xFFFF) # ori $t8, $t8, 0xfc00
  sw    $t4, 4($v1)
  lui   $t5, 0xb300
  sw    $t5, ($a1)
  sw    $t8, 4($a1)
  b     .L7F0ADA90
   addiu $s0, $s0, 8
.L7F0AD7F8:
  lw    $t6, ($a2)
  sll   $t9, $t0, 2
  addiu $a3, $a3, %lo(text_y)
  addu  $t7, $t9, $t6
  lw    $t6, ($a3)
  andi  $t4, $t7, 0xfff
  sll   $t5, $t4, 0xc
  sll   $t9, $v0, 2
  lui   $at, 0xe400
  addu  $t7, $t9, $t6
  andi  $t4, $t7, 0xfff
  or    $t8, $t5, $at
  or    $t5, $t8, $t4
  move  $v1, $s0
  sw    $t5, ($v1)
  lw    $t9, 0xf4($sp)
  lw    $t8, ($a2)
  addiu $s0, $s0, 8
  lw    $t6, ($t9)
  move  $a0, $s0
  addiu $s0, $s0, 8
  sll   $t7, $t6, 2
  lw    $t6, 4($s1)
  addu  $t4, $t7, $t8
  andi  $t5, $t4, 0xfff
  lw    $t4, ($a3)
  addu  $t7, $t1, $t6
  sll   $t8, $t7, 2
  sll   $t9, $t5, 0xc
  addu  $t5, $t8, $t4
  andi  $t6, $t5, 0xfff
  or    $t7, $t9, $t6
  sw    $t7, 4($v1)
  lui   $t8, 0xb400
  sw    $t8, ($a0)
  lui   $t4, %hi(text_s) 
  lw    $t5, %lo(text_s)($t4)
  lui   $t6, %hi(text_t) 
  lw    $t6, %lo(text_t)($t6)
  sll   $t9, $t5, 0x10
  lui   $t5, (0x04000400 >> 16) # lui $t5, 0x400
  andi  $t7, $t6, 0xffff
  or    $t8, $t9, $t7
  move  $a1, $s0
  sw    $t8, 4($a0)
  ori   $t5, (0x04000400 & 0xFFFF) # ori $t5, $t5, 0x400
  lui   $t4, 0xb300
  sw    $t4, ($a1)
  sw    $t5, 4($a1)
  b     .L7F0ADA90
   addiu $s0, $s0, 8
  slt   $at, $t3, $v1
.L7F0AD8C8:
  bnez  $at, .L7F0ADA90
   lui   $a2, %hi(text_x)
  addiu $a2, %lo(text_x) # addiu $a2, $a2, 0xe98
  lw    $t9, ($a2)
  lui   $a3, %hi(text_y)
  sll   $t6, $t0, 2
  addiu $a3, %lo(text_y) # addiu $a3, $a3, 0xe9c
  addu  $t7, $t6, $t9
  lw    $t6, ($a3)
  andi  $t8, $t7, 0xfff
  sll   $t4, $t8, 0xc
  lui   $at, 0xe400
  addu  $t9, $t3, $t6
  andi  $t7, $t9, 0xfff
  or    $t5, $t4, $at
  or    $t8, $t5, $t7
  move  $v0, $s0
  sw    $t8, ($v0)
  lw    $t4, 0xf4($sp)
  lw    $t5, ($a2)
  addiu $s0, $s0, 8
  lw    $t6, ($t4)
  move  $v1, $s0
  addiu $s0, $s0, 8
  sll   $t9, $t6, 2
  lw    $t6, 4($s1)
  addu  $t7, $t9, $t5
  andi  $t8, $t7, 0xfff
  lw    $t7, ($a3)
  addu  $t9, $t1, $t6
  sll   $t5, $t9, 2
  sll   $t4, $t8, 0xc
  addu  $t8, $t5, $t7
  andi  $t6, $t8, 0xfff
  or    $t9, $t4, $t6
  sw    $t9, 4($v0)
  lui   $t5, 0xb400
  sw    $t5, ($v1)
  lui   $t7, %hi(text_s) 
  lw    $t8, %lo(text_s)($t7)
  lui   $t6, %hi(text_t) 
  lw    $t6, %lo(text_t)($t6)
  sll   $t4, $t8, 0x10
  lui   $t8, (0x04000400 >> 16) # lui $t8, 0x400
  andi  $t9, $t6, 0xffff
  or    $t5, $t4, $t9
  move  $a0, $s0
  sw    $t5, 4($v1)
  ori   $t8, (0x04000400 & 0xFFFF) # ori $t8, $t8, 0x400
  lui   $t7, 0xb300
  sw    $t7, ($a0)
  sw    $t8, 4($a0)
  b     .L7F0ADA90
   addiu $s0, $s0, 8
  lw    $t6, 8($s1)
.L7F0AD9A4:
  lui   $a2, %hi(text_x)
  addiu $a2, %lo(text_x) # addiu $a2, $a2, 0xe98
  addu  $v0, $v1, $t6
  slt   $at, $v0, $t2
  bnez  $at, .L7F0ADA90
   lui   $a3, %hi(text_y)
  lw    $t9, ($a2)
  sll   $t4, $t0, 2
  addiu $a3, %lo(text_y) # addiu $a3, $a3, 0xe9c
  addu  $t5, $t4, $t9
  lw    $t9, ($a3)
  andi  $t7, $t5, 0xfff
  sll   $t8, $t7, 0xc
  sll   $t4, $v0, 2
  lui   $at, 0xe400
  addu  $t5, $t4, $t9
  andi  $t7, $t5, 0xfff
  or    $t6, $t8, $at
  or    $t8, $t6, $t7
  move  $v1, $s0
  sw    $t8, ($v1)
  lw    $t4, 0xf4($sp)
  lw    $t6, ($a2)
  addiu $s0, $s0, 8
  lw    $t9, ($t4)
  move  $a0, $s0
  addiu $s0, $s0, 8
  sll   $t5, $t9, 2
  addu  $t7, $t5, $t6
  lw    $t5, ($a3)
  andi  $t8, $t7, 0xfff
  sll   $t9, $t2, 2
  addu  $t6, $t9, $t5
  andi  $t7, $t6, 0xfff
  sll   $t4, $t8, 0xc
  or    $t8, $t4, $t7
  sw    $t8, 4($v1)
  lui   $t9, 0xb400
  sw    $t9, ($a0)
  lw    $t6, 4($s1)
  subu  $t5, $t2, $t1
  lui   $t8, %hi(text_t) 
  subu  $t4, $t5, $t6
  lw    $t8, %lo(text_t)($t8)
  sll   $t7, $t4, 5
  lui   $t6, %hi(text_s) 
  lw    $t4, %lo(text_s)($t6)
  addu  $t9, $t7, $t8
  andi  $t5, $t9, 0xffff
  sll   $t7, $t4, 0x10
  or    $t8, $t7, $t5
  move  $a1, $s0
  sw    $t8, 4($a0)
  lui   $t6, (0x04000400 >> 16) # lui $t6, 0x400
  ori   $t6, (0x04000400 & 0xFFFF) # ori $t6, $t6, 0x400
  lui   $t9, 0xb300
  sw    $t9, ($a1)
  sw    $t6, 4($a1)
  addiu $s0, $s0, 8
.L7F0ADA90:
  lw    $t4, 0xf4($sp)
.L7F0ADA94:
  lw    $t5, 0xc($s1)
  move  $v0, $s0
  lw    $t7, ($t4)
  addu  $t8, $t7, $t5
  sw    $t8, ($t4)
  lw    $ra, 0x1c($sp)
  lw    $s1, 0x18($sp)
  lw    $s0, 0x14($sp)
  jr    $ra
   addiu $sp, $sp, 0xf0
");

#ifdef VERSION_US
asm(R"
glabel en_text_write_stuff
  addiu $sp, $sp, -0xa8
  li    $t6, 1
  lui   $at, %hi(D_80040EA8)
  lw    $t8, 0xd0($sp)
  sw    $ra, 0x5c($sp)
  sw    $fp, 0x58($sp)
  sw    $s7, 0x54($sp)
  sw    $s6, 0x50($sp)
  sw    $s5, 0x4c($sp)
  sw    $s4, 0x48($sp)
  sw    $s3, 0x44($sp)
  sw    $s2, 0x40($sp)
  sw    $s1, 0x3c($sp)
  sw    $s0, 0x38($sp)
  sw    $t6, %lo(D_80040EA8)($at)
  lw    $t7, ($a2)
  lw    $s4, ($a1)
  move  $s0, $a3
  move  $s1, $a1
  move  $s2, $a2
  move  $s3, $a0
  li    $s5, 72
  bnez  $t8, .L7F0ADB30
   sw    $t7, 0xa0($sp)
  lw    $t9, 0xb8($sp)
  lw    $t0, 0x88c($t9)
  lw    $t1, 0x890($t9)
  addu  $t2, $t0, $t1
  sw    $t2, 0xd0($sp)
.L7F0ADB30:
  lui   $t3, %hi(j_text_trigger) 
  lw    $t3, %lo(j_text_trigger)($t3)
  lw    $t4, 0xd0($sp)
  move  $a0, $s3
  beqz  $t3, .L7F0ADB54
   slti  $at, $t4, 0xe
  beqz  $at, .L7F0ADB54
   li    $t5, 14
  sw    $t5, 0xd0($sp)
.L7F0ADB54:
  lw    $v1, 0xc0($sp)
  lui   $t6, 0xfa00
  sw    $t6, ($a0)
  srl   $t9, $v1, 0x18
  srl   $t2, $v1, 0x10
  andi  $t3, $t2, 0xff
  sll   $t0, $t9, 0x18
  srl   $t7, $v1, 8
  andi  $t8, $t7, 0xff
  sll   $t4, $t3, 0x10
  or    $t5, $t0, $t4
  sll   $t9, $t8, 8
  or    $t1, $t5, $t9
  andi  $t3, $v1, 0xff
  or    $t0, $t1, $t3
  sw    $t0, 4($a0)
  lbu   $v0, ($s0)
  addiu $s3, $s3, 8
  lw    $s7, 0xbc($sp)
  beqz  $v0, .L7F0ADD78
   lw    $fp, 0xc4($sp)
  addiu $s6, $sp, 0x6c
  li    $at, 32
.L7F0ADBB0:
  bnel  $v0, $at, .L7F0ADBD4
   li    $at, 10
  lw    $t4, ($s1)
  li    $s5, 72
  addiu $s0, $s0, 1
  addiu $t6, $t4, 5
  b     .L7F0ADD6C
   sw    $t6, ($s1)
  li    $at, 10
.L7F0ADBD4:
  bnel  $v0, $at, .L7F0ADC28
   slti  $at, $v0, 0x80
  lui   $v0, %hi(overlap_correction)
  lw    $v0, %lo(overlap_correction)($v0)
  li    $s5, 72
  lw    $t2, 0xd0($sp)
  bltz  $v0, .L7F0ADC10
   addiu $s0, $s0, 1
  lw    $t7, ($s1)
  bnel  $s4, $t7, .L7F0ADC14
   lw    $t9, ($s2)
  lw    $t8, ($s2)
  addu  $t5, $t8, $v0
  b     .L7F0ADC1C
   sw    $t5, ($s2)
.L7F0ADC10:
  lw    $t9, ($s2)
.L7F0ADC14:
  addu  $t1, $t9, $t2
  sw    $t1, ($s2)
.L7F0ADC1C:
  b     .L7F0ADD6C
   sw    $s4, ($s1)
  slti  $at, $v0, 0x80
.L7F0ADC28:
  beqz  $at, .L7F0ADCA0
   lui   $t6, %hi(D_80040EFC)
  li    $v1, 24
  multu $v0, $v1
  lw    $t0, 0xb8($sp)
  lw    $t8, 0xa0($sp)
  lw    $t5, 0xc8($sp)
  lw    $t9, 0xcc($sp)
  move  $a0, $s3
  move  $a1, $s1
  move  $a2, $s2
  sw    $s7, 0x14($sp)
  sw    $s4, 0x18($sp)
  mflo  $t3
  addu  $a3, $t3, $t0
  addiu $a3, $a3, -0x318
  multu $s5, $v1
  sw    $fp, 0x20($sp)
  sw    $t8, 0x1c($sp)
  sw    $t5, 0x24($sp)
  sw    $t9, 0x28($sp)
  mflo  $t4
  addu  $t6, $t4, $t0
  addiu $t7, $t6, -0x318
  jal   sub_GAME_7F0AD0F8
   sw    $t7, 0x10($sp)
  move  $s3, $v0
  lbu   $s5, ($s0)
  b     .L7F0ADD6C
   addiu $s0, $s0, 1
.L7F0ADCA0:
  addiu $t6, $t6, %lo(D_80040EFC)
  lw    $at, ($t6)
  lbu   $t2, 1($s0)
  andi  $t3, $v0, 0x7f
  sw    $at, ($s6)
  lw    $t8, 4($t6)
  sll   $t4, $t3, 7
  andi  $t1, $t2, 0x7f
  sw    $t8, 4($s6)
  lw    $at, 8($t6)
  or    $v1, $t1, $t4
  andi  $a0, $v1, 0xffff
  sw    $at, 8($s6)
  lw    $t8, 0xc($t6)
  andi  $t5, $a0, 0x2000
  andi  $t3, $a0, 0x1fff
  sw    $t8, 0xc($s6)
  lw    $at, 0x10($t6)
  li    $t9, 15
  li    $t2, 16
  sw    $at, 0x10($s6)
  lw    $t8, 0x14($t6)
  slti  $at, $t3, 0x3c7
  beqz  $t5, .L7F0ADD0C
   sw    $t8, 0x14($s6)
  sw    $t9, 0x78($sp)
  sw    $t2, 0x74($sp)
.L7F0ADD0C:
  bnezl $at, .L7F0ADD1C
   addiu $t1, $a0, 0x80
  li    $a0, 2
  addiu $t1, $a0, 0x80
.L7F0ADD1C:
  jal   something_with_LnameX
   sw    $t1, 0x6c($sp)
  lw    $t4, 0xa0($sp)
  lw    $t0, 0xc8($sp)
  lw    $t7, 0xcc($sp)
  sw    $v0, 0x80($sp)
  move  $a0, $s3
  move  $a1, $s1
  move  $a2, $s2
  move  $a3, $s6
  sw    $s6, 0x10($sp)
  sw    $s7, 0x14($sp)
  sw    $s4, 0x18($sp)
  sw    $fp, 0x20($sp)
  sw    $t4, 0x1c($sp)
  sw    $t0, 0x24($sp)
  jal   sub_GAME_7F0AD0F8
   sw    $t7, 0x28($sp)
  move  $s3, $v0
  addiu $s0, $s0, 2
.L7F0ADD6C:
  lbu   $v0, ($s0)
  bnezl $v0, .L7F0ADBB0
   li    $at, 32
.L7F0ADD78:
  lw    $ra, 0x5c($sp)
  move  $v0, $s3
  lw    $s3, 0x44($sp)
  lw    $s0, 0x38($sp)
  lw    $s1, 0x3c($sp)
  lw    $s2, 0x40($sp)
  lw    $s4, 0x48($sp)
  lw    $s5, 0x4c($sp)
  lw    $s6, 0x50($sp)
  lw    $s7, 0x54($sp)
  lw    $fp, 0x58($sp)
  jr    $ra
   addiu $sp, $sp, 0xa8
");
#endif
#ifdef VERSION_JP
asm(R"
glabel en_text_write_stuff
  addiu $sp, $sp, -0xa8
  li    $t6, 1
  lui   $at, %hi(D_80040EA8)
  lw    $t8, 0xd0($sp)
  sw    $ra, 0x5c($sp)
  sw    $fp, 0x58($sp)
  sw    $s7, 0x54($sp)
  sw    $s6, 0x50($sp)
  sw    $s5, 0x4c($sp)
  sw    $s4, 0x48($sp)
  sw    $s3, 0x44($sp)
  sw    $s2, 0x40($sp)
  sw    $s1, 0x3c($sp)
  sw    $s0, 0x38($sp)
  sw    $t6, %lo(D_80040EA8)($at)
  lw    $t7, ($a2)
  lw    $s4, ($a1)
  move  $s0, $a3
  move  $s1, $a1
  move  $s2, $a2
  move  $s3, $a0
  li    $s5, 72
  bnez  $t8, .L7F0ADB30
   sw    $t7, 0xa0($sp)
  lw    $t9, 0xb8($sp)
  lw    $t0, 0x88c($t9)
  lw    $t1, 0x890($t9)
  addu  $t2, $t0, $t1
  sw    $t2, 0xd0($sp)
.L7F0ADB30:
  lui   $t3, %hi(j_text_trigger) 
  lw    $t3, %lo(j_text_trigger)($t3)
  lw    $t4, 0xd0($sp)
  move  $a0, $s3
  beqz  $t3, .L7F0ADB54
   slti  $at, $t4, 0xe
  beqz  $at, .L7F0ADB54
   li    $t5, 14
  sw    $t5, 0xd0($sp)
.L7F0ADB54:
  lw    $v1, 0xc0($sp)
  lui   $t6, 0xfa00
  sw    $t6, ($a0)
  srl   $t9, $v1, 0x18
  srl   $t2, $v1, 0x10
  andi  $t3, $t2, 0xff
  sll   $t0, $t9, 0x18
  srl   $t7, $v1, 8
  andi  $t8, $t7, 0xff
  sll   $t4, $t3, 0x10
  or    $t5, $t0, $t4
  sll   $t9, $t8, 8
  or    $t1, $t5, $t9
  andi  $t3, $v1, 0xff
  or    $t0, $t1, $t3
  sw    $t0, 4($a0)
  lbu   $v0, ($s0)
  addiu $s3, $s3, 8
  lw    $s7, 0xbc($sp)
  beqz  $v0, .L7F0ADD78
   lw    $fp, 0xc4($sp)
  addiu $s6, $sp, 0x6c
  li    $at, 32
.L7F0ADBB0:
  bnel  $v0, $at, .L7F0ADBD4
   li    $at, 10
  lw    $t4, ($s1)
  li    $s5, 72
  addiu $s0, $s0, 1
  addiu $t6, $t4, 5
  b     .L7F0ADD6C
   sw    $t6, ($s1)
  li    $at, 10
.L7F0ADBD4:
  bnel  $v0, $at, .L7F0ADC28
   slti  $at, $v0, 0x80
  lui   $v0, %hi(overlap_correction)
  lw    $v0, %lo(overlap_correction)($v0)
  li    $s5, 72
  lw    $t2, 0xd0($sp)
  bltz  $v0, .L7F0ADC10
   addiu $s0, $s0, 1
  lw    $t7, ($s1)
  bnel  $s4, $t7, .L7F0ADC14
   lw    $t9, ($s2)
  lw    $t8, ($s2)
  addu  $t5, $t8, $v0
  b     .L7F0ADC1C
   sw    $t5, ($s2)
.L7F0ADC10:
  lw    $t9, ($s2)
.L7F0ADC14:
  addu  $t1, $t9, $t2
  sw    $t1, ($s2)
.L7F0ADC1C:
  b     .L7F0ADD6C
   sw    $s4, ($s1)
  slti  $at, $v0, 0x80
.L7F0ADC28:
  beqz  $at, .L7F0ADCA0
   lui   $t6, %hi(D_80040EFC)
  li    $v1, 24
  multu $v0, $v1
  lw    $t0, 0xb8($sp)
  lw    $t8, 0xa0($sp)
  lw    $t5, 0xc8($sp)
  lw    $t9, 0xcc($sp)
  move  $a0, $s3
  move  $a1, $s1
  move  $a2, $s2
  sw    $s7, 0x14($sp)
  sw    $s4, 0x18($sp)
  mflo  $t3
  addu  $a3, $t3, $t0
  addiu $a3, $a3, -0x318
  multu $s5, $v1
  sw    $fp, 0x20($sp)
  sw    $t8, 0x1c($sp)
  sw    $t5, 0x24($sp)
  sw    $t9, 0x28($sp)
  mflo  $t4
  addu  $t6, $t4, $t0
  addiu $t7, $t6, -0x318
  jal   sub_GAME_7F0AD0F8
   sw    $t7, 0x10($sp)
  move  $s3, $v0
  lbu   $s5, ($s0)
  b     .L7F0ADD6C
   addiu $s0, $s0, 1
.L7F0ADCA0:
  addiu $t6, $t6, %lo(D_80040EFC)
  lw    $at, ($t6)
  lbu   $t2, 1($s0)
  andi  $t3, $v0, 0x7f
  sw    $at, ($s6)
  lw    $t8, 4($t6)
  sll   $t4, $t3, 7
  andi  $t1, $t2, 0x7f
  sw    $t8, 4($s6)
  lw    $at, 8($t6)
  or    $v1, $t1, $t4
  andi  $a0, $v1, 0xffff
  sw    $at, 8($s6)
  lw    $t8, 0xc($t6)
  andi  $t5, $a0, 0x2000
  andi  $t3, $a0, 0x1fff
  sw    $t8, 0xc($s6)
  lw    $at, 0x10($t6)
  li    $t9, 15
  li    $t2, 16
  sw    $at, 0x10($s6)
  lw    $t8, 0x14($t6)
  slti  $at, $t3, 0x3c8
  beqz  $t5, .L7F0ADD0C
   sw    $t8, 0x14($s6)
  sw    $t9, 0x78($sp)
  sw    $t2, 0x74($sp)
.L7F0ADD0C:
  bnezl $at, .L7F0ADD1C
   addiu $t1, $a0, 0x80
  li    $a0, 2
  addiu $t1, $a0, 0x80
.L7F0ADD1C:
  jal   something_with_LnameX
   sw    $t1, 0x6c($sp)
  lw    $t4, 0xa0($sp)
  lw    $t0, 0xc8($sp)
  lw    $t7, 0xcc($sp)
  sw    $v0, 0x80($sp)
  move  $a0, $s3
  move  $a1, $s1
  move  $a2, $s2
  move  $a3, $s6
  sw    $s6, 0x10($sp)
  sw    $s7, 0x14($sp)
  sw    $s4, 0x18($sp)
  sw    $fp, 0x20($sp)
  sw    $t4, 0x1c($sp)
  sw    $t0, 0x24($sp)
  jal   sub_GAME_7F0AD0F8
   sw    $t7, 0x28($sp)
  move  $s3, $v0
  addiu $s0, $s0, 2
.L7F0ADD6C:
  lbu   $v0, ($s0)
  bnezl $v0, .L7F0ADBB0
   li    $at, 32
.L7F0ADD78:
  lw    $ra, 0x5c($sp)
  move  $v0, $s3
  lw    $s3, 0x44($sp)
  lw    $s0, 0x38($sp)
  lw    $s1, 0x3c($sp)
  lw    $s2, 0x40($sp)
  lw    $s4, 0x48($sp)
  lw    $s5, 0x4c($sp)
  lw    $s6, 0x50($sp)
  lw    $s7, 0x54($sp)
  lw    $fp, 0x58($sp)
  jr    $ra
   addiu $sp, $sp, 0xa8
");
#endif

asm(R"
glabel sub_GAME_7F0ADDAC
  addiu $sp, $sp, -0x60
  sw    $ra, 0x4c($sp)
  sw    $fp, 0x48($sp)
  sw    $s7, 0x44($sp)
  sw    $s6, 0x40($sp)
  sw    $s5, 0x3c($sp)
  sw    $s4, 0x38($sp)
  sw    $s3, 0x34($sp)
  sw    $s2, 0x30($sp)
  sw    $s1, 0x2c($sp)
  sw    $s0, 0x28($sp)
  lw    $t6, ($a2)
  lw    $t7, 0x90($sp)
  lw    $t1, 0x70($sp)
  lw    $t9, 0x74($sp)
  addu  $t8, $t6, $t7
  sw    $t8, 0x50($sp)
  lw    $t2, 0x10($t1)
  lw    $t6, 0x10($a3)
  move  $s3, $a0
  sll   $t3, $t2, 2
  subu  $t3, $t3, $t2
  sll   $t3, $t3, 2
  addu  $t3, $t3, $t2
  sll   $t4, $t3, 2
  addu  $t5, $t9, $t4
  sll   $t7, $t6, 2
  addu  $t8, $t5, $t7
  lui   $t2, %hi(text_spacing) 
  lw    $t2, %lo(text_spacing)($t2)
  lw    $t1, ($t8)
  lw    $t3, ($a1)
  move  $fp, $a3
  addu  $v0, $t1, $t2
  subu  $t9, $t3, $v0
  addiu $t4, $t9, 1
  sw    $t4, ($a1)
  sw    $a1, 0x64($sp)
  lw    $t6, ($a1)
  blezl $t6, .L7F0AE418
   lw    $a1, 0x64($sp)
  jal   get_video2_settings_txtClipW
   sw    $a1, 0x64($sp)
  lw    $t5, 0x64($sp)
  lw    $t7, ($t5)
  slt   $at, $v0, $t7
  bnezl $at, .L7F0AE418
   lw    $a1, 0x64($sp)
  jal   get_video2_settings_txtClipH
   nop   
  lw    $t8, 0x50($sp)
  lw    $t1, 4($fp)
  lw    $t2, 0x64($sp)
  addu  $a0, $t8, $t1
  slt   $at, $v0, $a0
  bnezl $at, .L7F0AE418
   lw    $a1, 0x64($sp)
  lw    $s4, 0x78($sp)
  lw    $s6, 0x88($sp)
  lw    $v1, ($t2)
  lw    $s5, 0x7c($sp)
  addu  $t3, $s4, $s6
  slt   $at, $t3, $v1
  bnez  $at, .L7F0AE414
   lw    $s7, 0x8c($sp)
  addu  $t9, $s5, $s7
  slt   $at, $t9, $a0
  bnez  $at, .L7F0AE414
   slt   $at, $v1, $s4
  bnezl $at, .L7F0AE418
   lw    $a1, 0x64($sp)
  lw    $t4, 8($fp)
  addu  $t6, $a0, $t4
  slt   $at, $t6, $s5
  bnezl $at, .L7F0AE418
   lw    $a1, 0x64($sp)
  lw    $t5, ($fp)
  lui   $a1, %hi(D_80040EA8)
  addiu $a1, %lo(D_80040EA8) # addiu $a1, $a1, 0xea8
  slti  $at, $t5, 0x80
  beqz  $at, .L7F0AE0A8
   lui   $s1, 0xe700
  move  $v0, $s3
  lui   $t7, (0xBA000E02 >> 16) # lui $t7, 0xba00
  ori   $t7, (0xBA000E02 & 0xFFFF) # ori $t7, $t7, 0xe02
  addiu $s3, $s3, 8
  sw    $t7, ($v0)
  sw    $zero, 4($v0)
  move  $v1, $s3
  lui   $t8, 0xfd90
  sw    $t8, ($v1)
  lw    $t1, 0x14($fp)
  addiu $s3, $s3, 8
  move  $a0, $s3
  addiu $s3, $s3, 8
  sw    $t1, 4($v1)
  lui   $s2, 0x700
  move  $a1, $s3
  lui   $t2, 0xf590
  sw    $t2, ($a0)
  sw    $s2, 4($a0)
  addiu $s3, $s3, 8
  lui   $t3, 0xe600
  sw    $t3, ($a1)
  move  $t0, $s3
  sw    $zero, 4($a1)
  lui   $t9, 0xf300
  sw    $t9, ($t0)
  lw    $v1, 0xc($fp)
  lw    $t6, 8($fp)
  addiu $s3, $s3, 8
  addiu $v1, $v1, 7
  andi  $t4, $v1, 0xf8
  multu $t4, $t6
  move  $v1, $t4
  lui   $s1, 0xe700
  li    $a2, 2047
  mflo  $v0
  addiu $v0, $v0, 1
  sra   $t5, $v0, 1
  addiu $v0, $t5, -1
  slti  $at, $v0, 0x7ff
  beqz  $at, .L7F0ADFA4
   nop   
  b     .L7F0ADFA4
   move  $a2, $v0
.L7F0ADFA4:
  bgez  $v1, .L7F0ADFB4
   sra   $v0, $v1, 3
  addiu $at, $v1, 7
  sra   $v0, $at, 3
.L7F0ADFB4:
  bgtz  $v0, .L7F0ADFC4
   andi  $t3, $a2, 0xfff
  b     .L7F0ADFC8
   li    $a3, 1
.L7F0ADFC4:
  move  $a3, $v0
.L7F0ADFC8:
  bgtz  $v0, .L7F0ADFD8
   addiu $t7, $a3, 0x7ff
  b     .L7F0ADFDC
   li    $a1, 1
.L7F0ADFD8:
  move  $a1, $v0
.L7F0ADFDC:
  div   $zero, $t7, $a1
  mflo  $t8
  andi  $t1, $t8, 0xfff
  or    $t2, $t1, $s2
  sll   $t9, $t3, 0xc
  or    $t4, $t2, $t9
  sw    $t4, 4($t0)
  move  $v0, $s3
  sw    $s1, ($v0)
  sw    $zero, 4($v0)
  lw    $t6, 0xc($fp)
  bnez  $a1, .L7F0AE014
   nop   
  break 7
.L7F0AE014:
  li    $at, -1
  bne   $a1, $at, .L7F0AE02C
   lui   $at, 0x8000
  bne   $t7, $at, .L7F0AE02C
   nop   
  break 6
.L7F0AE02C:
  addiu $t5, $t6, 7
  andi  $t7, $t5, 0xf8
  addiu $t8, $t7, 7
  sra   $t1, $t8, 3
  addiu $s3, $s3, 8
  move  $v1, $s3
  andi  $t3, $t1, 0x1ff
  sll   $t2, $t3, 9
  lui   $at, 0xf588
  or    $t9, $t2, $at
  addiu $s3, $s3, 8
  move  $a0, $s3
  sw    $t9, ($v1)
  sw    $zero, 4($v1)
  lui   $t4, 0xf200
  sw    $t4, ($a0)
  lw    $t6, 0xc($fp)
  lw    $t9, 8($fp)
  addiu $s3, $s3, 8
  addiu $t5, $t6, 7
  andi  $t7, $t5, 0xf8
  addiu $t8, $t7, -1
  sll   $t1, $t8, 2
  addiu $t4, $t9, -1
  sll   $t6, $t4, 2
  andi  $t3, $t1, 0xfff
  sll   $t2, $t3, 0xc
  andi  $t5, $t6, 0xfff
  or    $t7, $t2, $t5
  b     .L7F0AE2F8
   sw    $t7, 4($a0)
.L7F0AE0A8:
  move  $v0, $s3
  addiu $s3, $s3, 8
  sw    $s1, ($v0)
  sw    $zero, 4($v0)
  move  $v1, $s3
  lui   $t8, (0xBA000E02 >> 16) # lui $t8, 0xba00
  ori   $t8, (0xBA000E02 & 0xFFFF) # ori $t8, $t8, 0xe02
  li    $t1, 49152
  sw    $t1, 4($v1)
  sw    $t8, ($v1)
  lw    $t3, ($a1)
  addiu $s3, $s3, 8
  move  $s0, $s3
  beqz  $t3, .L7F0AE1FC
   lui   $t9, 0xfd10
  sw    $zero, ($a1)
  lui   $a0, %hi(D_80040EBC)
  addiu $a0, %lo(D_80040EBC) # addiu $a0, $a0, 0xebc
  sw    $t9, ($s0)
  jal   osVirtualToPhysical
   addiu $s3, $s3, 8
  move  $v1, $s3
  addiu $s3, $s3, 8
  sw    $v0, 4($s0)
  move  $a0, $s3
  lui   $t4, 0xe800
  sw    $t4, ($v1)
  sw    $zero, 4($v1)
  lui   $t6, (0xF5000100 >> 16) # lui $t6, 0xf500
  ori   $t6, (0xF5000100 & 0xFFFF) # ori $t6, $t6, 0x100
  addiu $s3, $s3, 8
  lui   $s2, 0x700
  sw    $s2, 4($a0)
  move  $a1, $s3
  sw    $t6, ($a0)
  addiu $s3, $s3, 8
  move  $a2, $s3
  lui   $t2, 0xe600
  sw    $t2, ($a1)
  addiu $s3, $s3, 8
  sw    $zero, 4($a1)
  lui   $t7, (0x0703C000 >> 16) # lui $t7, 0x703
  ori   $t7, (0x0703C000 & 0xFFFF) # ori $t7, $t7, 0xc000
  move  $a3, $s3
  lui   $t5, 0xf000
  sw    $t5, ($a2)
  sw    $t7, 4($a2)
  addiu $s3, $s3, 8
  sw    $zero, 4($a3)
  sw    $s1, ($a3)
  move  $s0, $s3
  lui   $a0, %hi(D_80040EDC)
  lui   $t8, 0xfd10
  sw    $t8, ($s0)
  addiu $a0, %lo(D_80040EDC) # addiu $a0, $a0, 0xedc
  jal   osVirtualToPhysical
   addiu $s3, $s3, 8
  move  $v1, $s3
  addiu $s3, $s3, 8
  sw    $v0, 4($s0)
  move  $a0, $s3
  lui   $t1, 0xe800
  sw    $t1, ($v1)
  addiu $s3, $s3, 8
  sw    $zero, 4($v1)
  lui   $t3, (0xF5000110 >> 16) # lui $t3, 0xf500
  ori   $t3, (0xF5000110 & 0xFFFF) # ori $t3, $t3, 0x110
  move  $a1, $s3
  addiu $s3, $s3, 8
  sw    $t3, ($a0)
  sw    $s2, 4($a0)
  move  $a2, $s3
  lui   $t9, 0xe600
  sw    $t9, ($a1)
  addiu $s3, $s3, 8
  sw    $zero, 4($a1)
  lui   $t6, (0x0703C000 >> 16) # lui $t6, 0x703
  ori   $t6, (0x0703C000 & 0xFFFF) # ori $t6, $t6, 0xc000
  move  $a3, $s3
  lui   $t4, 0xf000
  sw    $t4, ($a2)
  sw    $t6, 4($a2)
  sw    $zero, 4($a3)
  sw    $s1, ($a3)
  addiu $s3, $s3, 8
.L7F0AE1FC:
  move  $s0, $s3
  lui   $t2, 0xfd50
  sw    $t2, ($s0)
  lui   $s2, 0x700
  lw    $a0, 0x14($fp)
  jal   osVirtualToPhysical
   addiu $s3, $s3, 8
  move  $v1, $s3
  sw    $v0, 4($s0)
  addiu $s3, $s3, 8
  lui   $t5, 0xf550
  move  $a0, $s3
  sw    $t5, ($v1)
  sw    $s2, 4($v1)
  addiu $s3, $s3, 8
  lui   $t7, 0xe600
  sw    $t7, ($a0)
  sw    $zero, 4($a0)
  move  $a2, $s3
  lui   $t8, 0xf300
  sw    $t8, ($a2)
  lw    $a3, 8($fp)
  addiu $s3, $s3, 8
  move  $v0, $s3
  sll   $t1, $a3, 2
  addiu $a3, $t1, -1
  slti  $at, $a3, 0x7ff
  beqz  $at, .L7F0AE278
   addiu $s3, $s3, 8
  b     .L7F0AE27C
   move  $a1, $a3
.L7F0AE278:
  li    $a1, 2047
.L7F0AE27C:
  andi  $t3, $a1, 0xfff
  sll   $t9, $t3, 0xc
  or    $t4, $t9, $s2
  ori   $t6, $t4, 0x800
  sw    $t6, 4($a2)
  lui   $t2, (0xF5400200 >> 16) # lui $t2, 0xf540
  sw    $zero, 4($v0)
  sw    $s1, ($v0)
  ori   $t2, (0xF5400200 & 0xFFFF) # ori $t2, $t2, 0x200
  move  $v1, $s3
  sw    $t2, ($v1)
  lw    $t7, ($fp)
  lui   $at, 8
  addiu $s3, $s3, 8
  andi  $t8, $t7, 1
  sll   $t1, $t8, 0x14
  or    $t3, $t1, $at
  ori   $t9, $t3, 0x200
  sw    $t9, 4($v1)
  move  $a0, $s3
  lui   $t4, 0xf200
  sw    $t4, ($a0)
  lw    $t6, 8($fp)
  lui   $at, (0x0003C000 >> 16) # lui $at, 3
  ori   $at, (0x0003C000 & 0xFFFF) # ori $at, $at, 0xc000
  addiu $t2, $t6, -1
  sll   $t5, $t2, 2
  andi  $t7, $t5, 0xfff
  or    $t8, $t7, $at
  sw    $t8, 4($a0)
  addiu $s3, $s3, 8
.L7F0AE2F8:
  lw    $v0, 0x84($sp)
  move  $a0, $s3
  lui   $t1, 0xfa00
  srl   $t4, $v0, 0x18
  srl   $t5, $v0, 0x10
  andi  $t7, $t5, 0xff
  sll   $t6, $t4, 0x18
  sll   $t8, $t7, 0x10
  sw    $t1, ($a0)
  srl   $t9, $v0, 8
  andi  $t4, $t9, 0xff
  or    $t1, $t6, $t8
  sll   $t2, $t4, 8
  or    $t5, $t1, $t2
  andi  $t6, $v0, 0xff
  or    $t8, $t5, $t6
  sw    $t8, 4($a0)
  lw    $t3, 0x64($sp)
  addiu $s3, $s3, 8
  li    $s1, -1
  li    $s2, 2
  lw    $v1, ($t3)
  li    $s0, -1
.L7F0AE354:
  bnez  $s1, .L7F0AE364
   addu  $a1, $v1, $s1
  beql  $s0, $zero, .L7F0AE398
   addiu $s0, $s0, 1
.L7F0AE364:
  lw    $t9, 0x50($sp)
  move  $a0, $s3
  move  $a3, $fp
  sw    $s4, 0x10($sp)
  sw    $s5, 0x14($sp)
  sw    $s6, 0x18($sp)
  sw    $s7, 0x1c($sp)
  jal   sub_GAME_7F0AE45C
   addu  $a2, $t9, $s0
  lw    $t4, 0x64($sp)
  move  $s3, $v0
  lw    $v1, ($t4)
  addiu $s0, $s0, 1
.L7F0AE398:
  bne   $s0, $s2, .L7F0AE354
   nop   
  addiu $s1, $s1, 1
  bnel  $s1, $s2, .L7F0AE354
   li    $s0, -1
  lw    $v0, 0x80($sp)
  lui   $t1, 0xfa00
  sw    $t1, ($s3)
  srl   $t5, $v0, 0x18
  srl   $t3, $v0, 0x10
  andi  $t9, $t3, 0xff
  sll   $t6, $t5, 0x18
  sll   $t4, $t9, 0x10
  srl   $t7, $v0, 8
  andi  $t5, $t7, 0xff
  or    $t1, $t6, $t4
  sll   $t8, $t5, 8
  or    $t3, $t1, $t8
  andi  $t6, $v0, 0xff
  or    $t4, $t3, $t6
  sw    $t4, 4($s3)
  move  $a1, $v1
  addiu $a0, $s3, 8
  sw    $s7, 0x1c($sp)
  sw    $s6, 0x18($sp)
  sw    $s5, 0x14($sp)
  sw    $s4, 0x10($sp)
  lw    $a2, 0x50($sp)
  jal   sub_GAME_7F0AE45C
   move  $a3, $fp
  move  $s3, $v0
.L7F0AE414:
  lw    $a1, 0x64($sp)
.L7F0AE418:
  lw    $t7, 0xc($fp)
  move  $v0, $s3
  lw    $t2, ($a1)
  addu  $t5, $t2, $t7
  sw    $t5, ($a1)
  lw    $ra, 0x4c($sp)
  lw    $fp, 0x48($sp)
  lw    $s7, 0x44($sp)
  lw    $s6, 0x40($sp)
  lw    $s5, 0x3c($sp)
  lw    $s4, 0x38($sp)
  lw    $s3, 0x34($sp)
  lw    $s2, 0x30($sp)
  lw    $s1, 0x2c($sp)
  lw    $s0, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x60
");

asm(R"
glabel sub_GAME_7F0AE45C
  lw    $t6, 0xc($a3)
  lw    $t7, 0x10($sp)
  lw    $t8, 0x18($sp)
  addu  $v0, $t6, $a1
  addu  $t9, $t7, $t8
  slt   $at, $t9, $v0
  bnez  $at, .L7F0AE6E4
   nop   
  lw    $v1, 4($a3)
  lw    $t1, 0x14($sp)
  lw    $t4, 0x1c($sp)
  addu  $t0, $v1, $a2
  slt   $at, $t0, $t1
  bnezl $at, .L7F0AE64C
   lw    $t7, 8($a3)
  lw    $t5, 8($a3)
  addu  $t2, $t1, $t4
  lui   $t6, %hi(text_orientation) 
  addu  $t3, $t0, $t5
  slt   $at, $t2, $t3
  bnezl $at, .L7F0AE5CC
   slt   $at, $t2, $t0
  lw    $t6, %lo(text_orientation)($t6)
  sll   $t8, $v0, 2
  andi  $t4, $t8, 0xfff
  beqz  $t6, .L7F0AE55C
   addiu $t0, $a0, 8
  subu  $t7, $a2, $v1
  sll   $t8, $t7, 2
  andi  $t9, $t8, 0xfff
  sll   $t4, $t9, 0xc
  lui   $at, 0xe500
  sll   $t6, $v0, 2
  andi  $t7, $t6, 0xfff
  or    $t5, $t4, $at
  or    $t8, $t5, $t7
  sw    $t8, ($a0)
  lw    $t9, 4($a3)
  lw    $t6, 8($a3)
  addiu $t1, $a0, 8
  subu  $t4, $a2, $t9
  subu  $t5, $t4, $t6
  sll   $t7, $t5, 2
  andi  $t8, $t7, 0xfff
  sll   $t4, $a1, 2
  andi  $t6, $t4, 0xfff
  sll   $t9, $t8, 0xc
  or    $t5, $t9, $t6
  sw    $t5, 4($a0)
  lui   $t7, 0xb400
  sw    $t7, ($t1)
  lw    $t8, 8($a3)
  lui   $t7, (0x0400FC00 >> 16) # lui $t7, 0x400
  addiu $t2, $t1, 8
  addiu $t4, $t8, -1
  sll   $t9, $t4, 5
  andi  $t6, $t9, 0xffff
  sw    $t6, 4($t1)
  ori   $t7, (0x0400FC00 & 0xFFFF) # ori $t7, $t7, 0xfc00
  lui   $t5, 0xb300
  sw    $t5, ($t2)
  sw    $t7, 4($t2)
  jr    $ra
   addiu $v0, $t2, 8

.L7F0AE55C:
  sll   $t9, $t4, 0xc
  lui   $at, 0xe400
  sll   $t5, $t3, 2
  andi  $t7, $t5, 0xfff
  or    $t6, $t9, $at
  or    $t8, $t6, $t7
  sw    $t8, ($a0)
  lw    $t6, 4($a3)
  sll   $t4, $a1, 2
  andi  $t9, $t4, 0xfff
  addu  $t7, $a2, $t6
  sll   $t8, $t7, 2
  andi  $t4, $t8, 0xfff
  sll   $t5, $t9, 0xc
  or    $t9, $t5, $t4
  sw    $t9, 4($a0)
  lui   $t8, (0x04000400 >> 16) # lui $t8, 0x400
  lui   $t6, 0xb400
  addiu $t1, $t0, 8
  sw    $t6, ($t0)
  ori   $t8, (0x04000400 & 0xFFFF) # ori $t8, $t8, 0x400
  sw    $zero, 4($t0)
  lui   $t7, 0xb300
  sw    $t7, ($t1)
  sw    $t8, 4($t1)
  jr    $ra
   addiu $v0, $t1, 8

  slt   $at, $t2, $t0
.L7F0AE5CC:
  bnez  $at, .L7F0AE6E4
   addiu $t0, $a0, 8
  sll   $t5, $v0, 2
  andi  $t4, $t5, 0xfff
  sll   $t9, $t4, 0xc
  lui   $at, 0xe400
  sll   $t7, $t2, 2
  andi  $t8, $t7, 0xfff
  or    $t6, $t9, $at
  or    $t5, $t6, $t8
  sw    $t5, ($a0)
  lw    $t6, 4($a3)
  sll   $t4, $a1, 2
  andi  $t9, $t4, 0xfff
  addu  $t8, $a2, $t6
  sll   $t5, $t8, 2
  andi  $t4, $t5, 0xfff
  sll   $t7, $t9, 0xc
  or    $t9, $t7, $t4
  sw    $t9, 4($a0)
  lui   $t5, (0x04000400 >> 16) # lui $t5, 0x400
  lui   $t6, 0xb400
  addiu $t1, $t0, 8
  sw    $t6, ($t0)
  ori   $t5, (0x04000400 & 0xFFFF) # ori $t5, $t5, 0x400
  sw    $zero, 4($t0)
  lui   $t8, 0xb300
  sw    $t8, ($t1)
  sw    $t5, 4($t1)
  jr    $ra
   addiu $v0, $t1, 8

  lw    $t7, 8($a3)
.L7F0AE64C:
  sll   $t4, $v0, 2
  andi  $t9, $t4, 0xfff
  addu  $t3, $t0, $t7
  slt   $at, $t3, $t1
  bnez  $at, .L7F0AE6E4
   move  $v1, $a0
  sll   $t6, $t9, 0xc
  lui   $at, 0xe400
  sll   $t5, $t3, 2
  andi  $t7, $t5, 0xfff
  or    $t8, $t6, $at
  or    $t4, $t8, $t7
  sll   $t9, $a1, 2
  andi  $t6, $t9, 0xfff
  sll   $t8, $t1, 2
  andi  $t7, $t8, 0xfff
  sll   $t5, $t6, 0xc
  sw    $t4, ($v1)
  or    $t4, $t5, $t7
  addiu $a0, $a0, 8
  move  $t0, $a0
  sw    $t4, 4($v1)
  lui   $t9, 0xb400
  sw    $t9, ($t0)
  lw    $t6, 4($a3)
  addiu $a0, $a0, 8
  move  $t2, $a0
  subu  $t8, $t1, $t6
  subu  $t5, $t8, $a2
  sll   $t7, $t5, 5
  andi  $t4, $t7, 0xffff
  sw    $t4, 4($t0)
  lui   $t6, (0x04000400 >> 16) # lui $t6, 0x400
  ori   $t6, (0x04000400 & 0xFFFF) # ori $t6, $t6, 0x400
  lui   $t9, 0xb300
  sw    $t9, ($t2)
  sw    $t6, 4($t2)
  addiu $a0, $a0, 8
.L7F0AE6E4:
  jr    $ra
   move  $v0, $a0
");

#ifdef VERSION_US
asm(R"
glabel jp_text_write_stuff
  addiu $sp, $sp, -0x98
  li    $t6, 1
  lui   $at, %hi(D_80040EA8)
  lw    $t8, 0xc4($sp)
  sw    $ra, 0x64($sp)
  sw    $fp, 0x60($sp)
  sw    $s7, 0x5c($sp)
  sw    $s6, 0x58($sp)
  sw    $s5, 0x54($sp)
  sw    $s4, 0x50($sp)
  sw    $s3, 0x4c($sp)
  sw    $s2, 0x48($sp)
  sw    $s1, 0x44($sp)
  sw    $s0, 0x40($sp)
  sw    $t6, %lo(D_80040EA8)($at)
  lw    $t7, ($a2)
  lw    $s6, ($a1)
  move  $s0, $a3
  move  $s1, $a1
  move  $s3, $a2
  move  $s5, $a0
  li    $s4, 72
  bnez  $t8, .L7F0AE760
   sw    $t7, 0x90($sp)
  lw    $t9, 0xa8($sp)
  lw    $t0, 0x88c($t9)
  lw    $t1, 0x890($t9)
  addu  $t2, $t0, $t1
  sw    $t2, 0xc4($sp)
.L7F0AE760:
  lui   $t3, %hi(j_text_trigger) 
  lw    $t3, %lo(j_text_trigger)($t3)
  lw    $t4, 0xc4($sp)
  addiu $s2, $sp, 0x74
  beqz  $t3, .L7F0AE784
   slti  $at, $t4, 0xe
  beqz  $at, .L7F0AE784
   li    $t5, 14
  sw    $t5, 0xc4($sp)
.L7F0AE784:
  lbu   $v0, ($s0)
  lw    $fp, 0xb0($sp)
  lw    $s7, 0xac($sp)
  beqz  $v0, .L7F0AE958
   li    $at, 32
.L7F0AE798:
  bnel  $v0, $at, .L7F0AE7BC
   li    $at, 10
  lw    $t6, ($s1)
  li    $s4, 72
  addiu $s0, $s0, 1
  addiu $t7, $t6, 5
  b     .L7F0AE94C
   sw    $t7, ($s1)
  li    $at, 10
.L7F0AE7BC:
  bnel  $v0, $at, .L7F0AE7E8
   slti  $at, $v0, 0x80
  sw    $s6, ($s1)
  lw    $t8, ($s3)
  lw    $t9, 0xc4($sp)
  li    $s4, 72
  addiu $s0, $s0, 1
  addu  $t0, $t8, $t9
  b     .L7F0AE94C
   sw    $t0, ($s3)
  slti  $at, $v0, 0x80
.L7F0AE7E8:
  beqz  $at, .L7F0AE870
   lui   $t6, %hi(D_80040F14)
  li    $v1, 24
  multu $v0, $v1
  lw    $t2, 0xa8($sp)
  lw    $t6, 0x90($sp)
  lw    $t7, 0xb4($sp)
  lw    $t8, 0xb8($sp)
  lw    $t9, 0xbc($sp)
  lw    $t0, 0xc0($sp)
  move  $a0, $s5
  move  $a1, $s1
  move  $a2, $s3
  mflo  $t1
  addu  $a3, $t1, $t2
  addiu $a3, $a3, -0x318
  multu $s4, $v1
  sw    $s7, 0x14($sp)
  sw    $s6, 0x18($sp)
  sw    $fp, 0x20($sp)
  sw    $t6, 0x1c($sp)
  sw    $t7, 0x24($sp)
  sw    $t8, 0x28($sp)
  sw    $t9, 0x2c($sp)
  sw    $t0, 0x30($sp)
  mflo  $t3
  addu  $t4, $t3, $t2
  addiu $t5, $t4, -0x318
  jal   sub_GAME_7F0ADDAC
   sw    $t5, 0x10($sp)
  move  $s5, $v0
  lbu   $s4, ($s0)
  b     .L7F0AE94C
   addiu $s0, $s0, 1
.L7F0AE870:
  addiu $t6, $t6, %lo(D_80040F14)
  lw    $at, ($t6)
  lbu   $t1, 1($s0)
  andi  $t2, $v0, 0x7f
  sw    $at, ($s2)
  lw    $t8, 4($t6)
  sll   $t4, $t2, 7
  andi  $t3, $t1, 0x7f
  sw    $t8, 4($s2)
  lw    $at, 8($t6)
  or    $v1, $t3, $t4
  andi  $a0, $v1, 0xffff
  sw    $at, 8($s2)
  lw    $t8, 0xc($t6)
  andi  $t9, $a0, 0x2000
  andi  $t2, $a0, 0x1fff
  sw    $t8, 0xc($s2)
  lw    $at, 0x10($t6)
  li    $t0, 15
  li    $t1, 16
  sw    $at, 0x10($s2)
  lw    $t8, 0x14($t6)
  slti  $at, $t2, 0x3c7
  beqz  $t9, .L7F0AE8DC
   sw    $t8, 0x14($s2)
  sw    $t0, 0x80($sp)
  sw    $t1, 0x7c($sp)
.L7F0AE8DC:
  bnezl $at, .L7F0AE8EC
   addiu $t3, $a0, 0x80
  li    $a0, 2
  addiu $t3, $a0, 0x80
.L7F0AE8EC:
  jal   something_with_LnameX
   sw    $t3, 0x74($sp)
  lw    $t4, 0x90($sp)
  lw    $t5, 0xb4($sp)
  lw    $t7, 0xb8($sp)
  lw    $t6, 0xbc($sp)
  lw    $t8, 0xc0($sp)
  sw    $v0, 0x88($sp)
  move  $a0, $s5
  move  $a1, $s1
  move  $a2, $s3
  move  $a3, $s2
  sw    $s2, 0x10($sp)
  sw    $s7, 0x14($sp)
  sw    $s6, 0x18($sp)
  sw    $fp, 0x20($sp)
  sw    $t4, 0x1c($sp)
  sw    $t5, 0x24($sp)
  sw    $t7, 0x28($sp)
  sw    $t6, 0x2c($sp)
  jal   sub_GAME_7F0ADDAC
   sw    $t8, 0x30($sp)
  move  $s5, $v0
  addiu $s0, $s0, 2
.L7F0AE94C:
  lbu   $v0, ($s0)
  bnezl $v0, .L7F0AE798
   li    $at, 32
.L7F0AE958:
  lw    $ra, 0x64($sp)
  move  $v0, $s5
  lw    $s5, 0x54($sp)
  lw    $s0, 0x40($sp)
  lw    $s1, 0x44($sp)
  lw    $s2, 0x48($sp)
  lw    $s3, 0x4c($sp)
  lw    $s4, 0x50($sp)
  lw    $s6, 0x58($sp)
  lw    $s7, 0x5c($sp)
  lw    $fp, 0x60($sp)
  jr    $ra
   addiu $sp, $sp, 0x98
");
#endif
#ifdef VERSION_JP
asm(R"
glabel jp_text_write_stuff
  addiu $sp, $sp, -0x98
  li    $t6, 1
  lui   $at, %hi(D_80040EA8)
  lw    $t8, 0xc4($sp)
  sw    $ra, 0x64($sp)
  sw    $fp, 0x60($sp)
  sw    $s7, 0x5c($sp)
  sw    $s6, 0x58($sp)
  sw    $s5, 0x54($sp)
  sw    $s4, 0x50($sp)
  sw    $s3, 0x4c($sp)
  sw    $s2, 0x48($sp)
  sw    $s1, 0x44($sp)
  sw    $s0, 0x40($sp)
  sw    $t6, %lo(D_80040EA8)($at)
  lw    $t7, ($a2)
  lw    $s6, ($a1)
  move  $s0, $a3
  move  $s1, $a1
  move  $s3, $a2
  move  $s5, $a0
  li    $s4, 72
  bnez  $t8, .L7F0AE760
   sw    $t7, 0x90($sp)
  lw    $t9, 0xa8($sp)
  lw    $t0, 0x88c($t9)
  lw    $t1, 0x890($t9)
  addu  $t2, $t0, $t1
  sw    $t2, 0xc4($sp)
.L7F0AE760:
  lui   $t3, %hi(j_text_trigger) 
  lw    $t3, %lo(j_text_trigger)($t3)
  lw    $t4, 0xc4($sp)
  addiu $s2, $sp, 0x74
  beqz  $t3, .L7F0AE784
   slti  $at, $t4, 0xe
  beqz  $at, .L7F0AE784
   li    $t5, 14
  sw    $t5, 0xc4($sp)
.L7F0AE784:
  lbu   $v0, ($s0)
  lw    $fp, 0xb0($sp)
  lw    $s7, 0xac($sp)
  beqz  $v0, .L7F0AE958
   li    $at, 32
.L7F0AE798:
  bnel  $v0, $at, .L7F0AE7BC
   li    $at, 10
  lw    $t6, ($s1)
  li    $s4, 72
  addiu $s0, $s0, 1
  addiu $t7, $t6, 5
  b     .L7F0AE94C
   sw    $t7, ($s1)
  li    $at, 10
.L7F0AE7BC:
  bnel  $v0, $at, .L7F0AE7E8
   slti  $at, $v0, 0x80
  sw    $s6, ($s1)
  lw    $t8, ($s3)
  lw    $t9, 0xc4($sp)
  li    $s4, 72
  addiu $s0, $s0, 1
  addu  $t0, $t8, $t9
  b     .L7F0AE94C
   sw    $t0, ($s3)
  slti  $at, $v0, 0x80
.L7F0AE7E8:
  beqz  $at, .L7F0AE870
   lui   $t6, %hi(D_80040F14)
  li    $v1, 24
  multu $v0, $v1
  lw    $t2, 0xa8($sp)
  lw    $t6, 0x90($sp)
  lw    $t7, 0xb4($sp)
  lw    $t8, 0xb8($sp)
  lw    $t9, 0xbc($sp)
  lw    $t0, 0xc0($sp)
  move  $a0, $s5
  move  $a1, $s1
  move  $a2, $s3
  mflo  $t1
  addu  $a3, $t1, $t2
  addiu $a3, $a3, -0x318
  multu $s4, $v1
  sw    $s7, 0x14($sp)
  sw    $s6, 0x18($sp)
  sw    $fp, 0x20($sp)
  sw    $t6, 0x1c($sp)
  sw    $t7, 0x24($sp)
  sw    $t8, 0x28($sp)
  sw    $t9, 0x2c($sp)
  sw    $t0, 0x30($sp)
  mflo  $t3
  addu  $t4, $t3, $t2
  addiu $t5, $t4, -0x318
  jal   sub_GAME_7F0ADDAC
   sw    $t5, 0x10($sp)
  move  $s5, $v0
  lbu   $s4, ($s0)
  b     .L7F0AE94C
   addiu $s0, $s0, 1
.L7F0AE870:
  addiu $t6, $t6, %lo(D_80040F14)
  lw    $at, ($t6)
  lbu   $t1, 1($s0)
  andi  $t2, $v0, 0x7f
  sw    $at, ($s2)
  lw    $t8, 4($t6)
  sll   $t4, $t2, 7
  andi  $t3, $t1, 0x7f
  sw    $t8, 4($s2)
  lw    $at, 8($t6)
  or    $v1, $t3, $t4
  andi  $a0, $v1, 0xffff
  sw    $at, 8($s2)
  lw    $t8, 0xc($t6)
  andi  $t9, $a0, 0x2000
  andi  $t2, $a0, 0x1fff
  sw    $t8, 0xc($s2)
  lw    $at, 0x10($t6)
  li    $t0, 15
  li    $t1, 16
  sw    $at, 0x10($s2)
  lw    $t8, 0x14($t6)
  slti  $at, $t2, 0x3c8
  beqz  $t9, .L7F0AE8DC
   sw    $t8, 0x14($s2)
  sw    $t0, 0x80($sp)
  sw    $t1, 0x7c($sp)
.L7F0AE8DC:
  bnezl $at, .L7F0AE8EC
   addiu $t3, $a0, 0x80
  li    $a0, 2
  addiu $t3, $a0, 0x80
.L7F0AE8EC:
  jal   something_with_LnameX
   sw    $t3, 0x74($sp)
  lw    $t4, 0x90($sp)
  lw    $t5, 0xb4($sp)
  lw    $t7, 0xb8($sp)
  lw    $t6, 0xbc($sp)
  lw    $t8, 0xc0($sp)
  sw    $v0, 0x88($sp)
  move  $a0, $s5
  move  $a1, $s1
  move  $a2, $s3
  move  $a3, $s2
  sw    $s2, 0x10($sp)
  sw    $s7, 0x14($sp)
  sw    $s6, 0x18($sp)
  sw    $fp, 0x20($sp)
  sw    $t4, 0x1c($sp)
  sw    $t5, 0x24($sp)
  sw    $t7, 0x28($sp)
  sw    $t6, 0x2c($sp)
  jal   sub_GAME_7F0ADDAC
   sw    $t8, 0x30($sp)
  move  $s5, $v0
  addiu $s0, $s0, 2
.L7F0AE94C:
  lbu   $v0, ($s0)
  bnezl $v0, .L7F0AE798
   li    $at, 32
.L7F0AE958:
  lw    $ra, 0x64($sp)
  move  $v0, $s5
  lw    $s5, 0x54($sp)
  lw    $s0, 0x40($sp)
  lw    $s1, 0x44($sp)
  lw    $s2, 0x48($sp)
  lw    $s3, 0x4c($sp)
  lw    $s4, 0x50($sp)
  lw    $s6, 0x58($sp)
  lw    $s7, 0x5c($sp)
  lw    $fp, 0x60($sp)
  jr    $ra
   addiu $sp, $sp, 0x98
");
#endif

asm(R"
glabel sub_GAME_7F0AE98C
  addiu $sp, $sp, -0x18
  sw    $s0, 8($sp)
  lw    $s0, 0x2c($sp)
  sw    $s3, 0x14($sp)
  sw    $s2, 0x10($sp)
  sw    $s1, 0xc($sp)
  sw    $zero, ($a0)
  li    $v0, 72
  move  $t0, $zero
  bnez  $s0, .L7F0AE9C4
   sw    $zero, ($a1)
  lw    $t6, 0x890($a3)
  lw    $t7, 0x88c($a3)
  addu  $s0, $t6, $t7
.L7F0AE9C4:
  lui   $t8, %hi(j_text_trigger) 
  lw    $t8, %lo(j_text_trigger)($t8)
  lui   $s3, %hi(text_spacing)
  slti  $at, $s0, 0xe
  beqz  $t8, .L7F0AE9E8
   addiu $s3, %lo(text_spacing) # addiu $s3, $s3, 0xe84
  beql  $at, $zero, .L7F0AE9EC
   lbu   $t1, ($a2)
  li    $s0, 14
.L7F0AE9E8:
  lbu   $t1, ($a2)
.L7F0AE9EC:
  li    $s2, 13
  li    $s1, 24
  beqz  $t1, .L7F0AEB38
   li    $t5, 10
  li    $t4, 32
  lw    $t2, 0x28($sp)
.L7F0AEA04:
  bne   $t4, $t1, .L7F0AEA30
   nop   
  lbu   $t9, 1($a2)
  li    $v0, 72
  beq   $t5, $t9, .L7F0AEA28
   nop   
  lw    $t6, ($a1)
  addiu $t7, $t6, 5
  sw    $t7, ($a1)
.L7F0AEA28:
  b     .L7F0AEB2C
   addiu $a2, $a2, 1
.L7F0AEA30:
  bne   $t5, $t1, .L7F0AEA64
   slti  $at, $t1, 0x80
  lw    $v1, ($a1)
  slt   $at, $t0, $v1
  beql  $at, $zero, .L7F0AEA50
   sw    $zero, ($a1)
  move  $t0, $v1
  sw    $zero, ($a1)
.L7F0AEA50:
  lw    $t8, ($a0)
  addiu $a2, $a2, 1
  addu  $t9, $t8, $s0
  b     .L7F0AEB2C
   sw    $t9, ($a0)
.L7F0AEA64:
  beql  $at, $zero, .L7F0AEAD8
   slti  $at, $t1, 0xc0
  multu $t1, $s1
  addiu $a2, $a2, 1
  mflo  $t6
  addu  $t3, $a3, $t6
  lw    $t7, -0x308($t3)
  multu $v0, $s1
  sll   $t8, $t7, 2
  addu  $t9, $t2, $t8
  mflo  $t6
  addu  $t7, $a3, $t6
  lw    $t8, -0x308($t7)
  multu $t8, $s2
  mflo  $t6
  sll   $t7, $t6, 2
  addu  $t8, $t9, $t7
  lw    $t6, ($t8)
  lw    $t9, ($s3)
  lw    $t8, -0x30c($t3)
  lw    $t7, ($a1)
  addu  $v1, $t6, $t9
  addiu $v1, $v1, -1
  addu  $t6, $t7, $t8
  subu  $t9, $t6, $v1
  sw    $t9, ($a1)
  b     .L7F0AEB2C
   lbu   $v0, -1($a2)
  slti  $at, $t1, 0xc0
.L7F0AEAD8:
  beql  $at, $zero, .L7F0AEB0C
   lw    $t8, ($t2)
  lw    $t7, ($t2)
  lw    $t8, ($s3)
  lw    $t6, ($a1)
  addiu $a2, $a2, 2
  addu  $v1, $t7, $t8
  addiu $v1, $v1, -1
  subu  $t9, $t6, $v1
  addiu $t7, $t9, 0xb
  b     .L7F0AEB2C
   sw    $t7, ($a1)
  lw    $t8, ($t2)
.L7F0AEB0C:
  lw    $t6, ($s3)
  lw    $t9, ($a1)
  addiu $a2, $a2, 2
  addu  $v1, $t8, $t6
  addiu $v1, $v1, -1
  subu  $t7, $t9, $v1
  addiu $t8, $t7, 0xf
  sw    $t8, ($a1)
.L7F0AEB2C:
  lbu   $t1, ($a2)
  bnez  $t1, .L7F0AEA04
   nop   
.L7F0AEB38:
  lw    $t6, ($a1)
  slt   $at, $t6, $t0
  beql  $at, $zero, .L7F0AEB50
   lw    $s0, 8($sp)
  sw    $t0, ($a1)
  lw    $s0, 8($sp)
.L7F0AEB50:
  lw    $s1, 0xc($sp)
  lw    $s2, 0x10($sp)
  lw    $s3, 0x14($sp)
  jr    $ra
   addiu $sp, $sp, 0x18
");

asm(R"
glabel sub_GAME_7F0AEB64
  addiu $sp, $sp, -0x90
  sw    $s4, 0x30($sp)
  sw    $s3, 0x2c($sp)
  sw    $s2, 0x28($sp)
  sw    $s0, 0x20($sp)
  move  $s0, $a2
  move  $s2, $a1
  move  $s3, $a3
  sw    $ra, 0x34($sp)
  sw    $s1, 0x24($sp)
  sw    $a0, 0x90($sp)
  move  $t3, $zero
  sw    $zero, 0x7c($sp)
  li    $t5, 1
  addiu $s4, $sp, 0x4c
  li    $t2, 24
.L7F0AEBA4:
  sw    $zero, 0x80($sp)
  lbu   $a0, ($s2)
  move  $s1, $zero
  move  $v1, $zero
  slti  $at, $a0, 0x21
  bnez  $at, .L7F0AEC34
   addiu $a1, $sp, 0x80
  addiu $v0, $sp, 0x4c
  sb    $a0, ($v0)
.L7F0AEBC8:
  lbu   $t6, ($s2)
  addiu $s2, $s2, 1
  addiu $s1, $s1, 1
  multu $t6, $t2
  lbu   $t6, ($v0)
  addiu $v0, $v0, 1
  slti  $at, $t6, 0x80
  mflo  $t7
  addu  $t8, $s3, $t7
  lw    $t9, -0x30c($t8)
  bnez  $at, .L7F0AEC24
   addu  $v1, $v1, $t9
  lbu   $t7, ($s2)
  addiu $s2, $s2, 1
  addiu $s1, $s1, 1
  sb    $t7, ($v0)
  lbu   $t8, -1($s2)
  addiu $v0, $v0, 1
  multu $t8, $t2
  mflo  $t9
  addu  $t6, $s3, $t9
  lw    $t7, -0x30c($t6)
  addu  $v1, $v1, $t7
.L7F0AEC24:
  lbu   $a0, ($s2)
  slti  $at, $a0, 0x21
  beql  $at, $zero, .L7F0AEBC8
   sb    $a0, ($v0)
.L7F0AEC34:
  addu  $t8, $s4, $s1
  sb    $zero, ($t8)
  lw    $t9, 0xa0($sp)
  sw    $t5, 0x78($sp)
  sw    $t3, 0x8c($sp)
  sw    $zero, 0x14($sp)
  addiu $a0, $sp, 0x7c
  move  $a2, $s4
  move  $a3, $s3
  jal   sub_GAME_7F0AE98C
   sw    $t9, 0x10($sp)
  lw    $t3, 0x8c($sp)
  lw    $t6, 0x80($sp)
  lw    $t7, 0x90($sp)
  lui   $t0, %hi(text_wordwrap) 
  addu  $t3, $t3, $t6
  slt   $at, $t7, $t3
  addiu $t0, %lo(text_wordwrap) # addiu $t0, $t0, 0xe8c
  li    $t1, 32
  li    $t2, 24
  li    $t4, 10
  bnez  $at, .L7F0AEC98
   lw    $t5, 0x78($sp)
  b     .L7F0AEC9C
   li    $a0, 1
.L7F0AEC98:
  move  $a0, $zero
.L7F0AEC9C:
  lbu   $v0, ($s2)
  li    $at, 10
  bnel  $v0, $at, .L7F0AED64
   li    $at, 32
  bnez  $a0, .L7F0AECE8
   move  $v1, $zero
  sb    $t4, ($s0)
  lw    $t8, ($t0)
  addiu $s0, $s0, 1
  blez  $t8, .L7F0AECE8
   nop   
  sb    $t1, ($s0)
.L7F0AECCC:
  lw    $t9, ($t0)
  addiu $v1, $v1, 1
  addiu $s0, $s0, 1
  slt   $at, $v1, $t9
  bnezl $at, .L7F0AECCC
   sb    $t1, ($s0)
  move  $v1, $zero
.L7F0AECE8:
  blez  $s1, .L7F0AED54
   move  $t3, $zero
  andi  $a1, $s1, 3
  beqz  $a1, .L7F0AED1C
   move  $a0, $a1
  addu  $v0, $s4, $v1
.L7F0AED00:
  lbu   $t6, ($v0)
  addiu $v1, $v1, 1
  addiu $s0, $s0, 1
  addiu $v0, $v0, 1
  bne   $a0, $v1, .L7F0AED00
   sb    $t6, -1($s0)
  beq   $v1, $s1, .L7F0AED54
.L7F0AED1C:
   addiu $t7, $sp, 0x4c
  addu  $a0, $s1, $t7
  addu  $v0, $s4, $v1
.L7F0AED28:
  lbu   $t8, ($v0)
  addiu $v0, $v0, 4
  addiu $s0, $s0, 4
  sb    $t8, -4($s0)
  lbu   $t9, -3($v0)
  sb    $t9, -3($s0)
  lbu   $t6, -2($v0)
  sb    $t6, -2($s0)
  lbu   $t7, -1($v0)
  bne   $v0, $a0, .L7F0AED28
   sb    $t7, -1($s0)
.L7F0AED54:
  sb    $t4, ($s0)
  b     .L7F0AEEE0
   addiu $s0, $s0, 1
  li    $at, 32
.L7F0AED64:
  bne   $v0, $at, .L7F0AEE30
   nop   
  bnez  $a0, .L7F0AEDB8
   move  $v1, $zero
  sb    $t4, ($s0)
  lw    $v0, ($t0)
  addiu $s0, $s0, 1
  blezl $v0, .L7F0AEDAC
   lw    $t9, 0x80($sp)
  sb    $t1, ($s0)
.L7F0AED8C:
  lw    $v0, ($t0)
  addiu $v1, $v1, 1
  addiu $s0, $s0, 1
  slt   $at, $v1, $v0
  bnezl $at, .L7F0AED8C
   sb    $t1, ($s0)
  move  $v1, $zero
  lw    $t9, 0x80($sp)
.L7F0AEDAC:
  sll   $t8, $v0, 2
  addu  $t8, $t8, $v0
  addu  $t3, $t8, $t9
.L7F0AEDB8:
  blez  $s1, .L7F0AEE24
   addiu $t3, $t3, 5
  andi  $a1, $s1, 3
  beqz  $a1, .L7F0AEDEC
   move  $a0, $a1
  addu  $v0, $s4, $v1
.L7F0AEDD0:
  lbu   $t6, ($v0)
  addiu $v1, $v1, 1
  addiu $s0, $s0, 1
  addiu $v0, $v0, 1
  bne   $a0, $v1, .L7F0AEDD0
   sb    $t6, -1($s0)
  beq   $v1, $s1, .L7F0AEE24
.L7F0AEDEC:
   addiu $t7, $sp, 0x4c
  addu  $a0, $s1, $t7
  addu  $v0, $s4, $v1
.L7F0AEDF8:
  lbu   $t8, ($v0)
  addiu $v0, $v0, 4
  addiu $s0, $s0, 4
  sb    $t8, -4($s0)
  lbu   $t9, -3($v0)
  sb    $t9, -3($s0)
  lbu   $t6, -2($v0)
  sb    $t6, -2($s0)
  lbu   $t7, -1($v0)
  bne   $v0, $a0, .L7F0AEDF8
   sb    $t7, -1($s0)
.L7F0AEE24:
  sb    $t1, ($s0)
  b     .L7F0AEEE0
   addiu $s0, $s0, 1
.L7F0AEE30:
  bnez  $v0, .L7F0AEEE0
   move  $v1, $zero
  bnez  $a0, .L7F0AEE74
   move  $t5, $zero
  sb    $t4, ($s0)
  lw    $t8, ($t0)
  addiu $s0, $s0, 1
  blez  $t8, .L7F0AEE74
   nop   
  sb    $t1, ($s0)
.L7F0AEE58:
  lw    $t9, ($t0)
  addiu $v1, $v1, 1
  addiu $s0, $s0, 1
  slt   $at, $v1, $t9
  bnezl $at, .L7F0AEE58
   sb    $t1, ($s0)
  move  $v1, $zero
.L7F0AEE74:
  blez  $s1, .L7F0AEEDC
   andi  $a1, $s1, 3
  beqz  $a1, .L7F0AEEA4
   move  $a0, $a1
  addu  $v0, $s4, $v1
.L7F0AEE88:
  lbu   $t6, ($v0)
  addiu $v1, $v1, 1
  addiu $s0, $s0, 1
  addiu $v0, $v0, 1
  bne   $a0, $v1, .L7F0AEE88
   sb    $t6, -1($s0)
  beq   $v1, $s1, .L7F0AEEDC
.L7F0AEEA4:
   addiu $t7, $sp, 0x4c
  addu  $a0, $s1, $t7
  addu  $v0, $s4, $v1
.L7F0AEEB0:
  lbu   $t8, ($v0)
  addiu $v0, $v0, 4
  addiu $s0, $s0, 4
  sb    $t8, -4($s0)
  lbu   $t9, -3($v0)
  sb    $t9, -3($s0)
  lbu   $t6, -2($v0)
  sb    $t6, -2($s0)
  lbu   $t7, -1($v0)
  bne   $v0, $a0, .L7F0AEEB0
   sb    $t7, -1($s0)
.L7F0AEEDC:
  sb    $zero, ($s0)
.L7F0AEEE0:
  li    $at, 1
  beq   $t5, $at, .L7F0AEBA4
   addiu $s2, $s2, 1
  lw    $ra, 0x34($sp)
  lw    $s0, 0x20($sp)
  lw    $s1, 0x24($sp)
  lw    $s2, 0x28($sp)
  lw    $s3, 0x2c($sp)
  lw    $s4, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x90
");

void sub_GAME_7F0AEF0C(int arg0, int arg1, int arg2, int arg3) {}

unsigned int sub_GAME_7F0AEF20(unsigned int param_1, unsigned int param_2) {
  return param_1;
}
