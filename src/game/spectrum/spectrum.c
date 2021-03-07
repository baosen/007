int ptr_sectrum_monitor_data_temp_buf;
int ptr_sectrum_game_data_temp_buf;
int ptr_spectrum_roms;
int ptr_300alloc;
int ptr_6000alloc;
int ptr_pc_keyboard_table_alloc;
char spectrum_header16_15;
char byte_CODE_bss_8008E339;
char byte_CODE_bss_8008E33A;
char byte_CODE_bss_8008E33B;
char off_CODE_bss_8008E33C;
char byte_CODE_bss_8008E33D;
char byte_CODE_bss_8008E33E;
char byte_CODE_bss_8008E33F;
char off_CODE_bss_8008E340;
char byte_CODE_bss_8008E341;
char byte_CODE_bss_8008E342;
char byte_CODE_bss_8008E343;
char off_CODE_bss_8008E344;
char byte_CODE_bss_8008E345;
char byte_CODE_bss_8008E346;
char byte_CODE_bss_8008E347;
char spec_I;
char byte_CODE_bss_8008E349;
char spec_IFF2_lower;
char spec_IFF2_upper;
char spec_IM;
char byte_CODE_bss_8008E34D;
short spec_IX, spec_IY, spec_SP, spec_PC;

char D_8004EC30 = 0;

char D_8004EC34[] = {0xFF, 0xFF, 0xFF, 0xFF};
char D_8004EC38[] = {0xFF, 0xFF, 0xFF, 0xFF};
char D_8004EC3C[] = {0xFF, 0x0, 0x0, 0x0};

short D_8004EC40[] = {
    0,     0,     0x7FE, 0x3FE, 0x3FD, 0x3FB, 0x3F7, 0x3EF, 0x4F7, 0x3FD,
    0x4FD, 0x4FE, 0x4FB, 0x6FB, 0x7F7, 0x6F7, 0x8FB, 0xEF,  0x4FE, 0x3FE,
    0x3FD, 0x3FB, 0x3F7, 0x3EF, 0x4EF, 0x4F7, 0x4FB, 0x4FD, 0xFD,  0x5FD,
    0x7F7, 0x6FB, 0x8FB, 0xEF,  0x3FD, 0x1FE, 0x7EF, 0xF7,  0x1FB, 0x2FB,
    0x1F7, 0x1EF, 0x6EF, 0x5FB, 0x6F7, 0x6FB, 0x6FD, 0x7FB, 0x7F7, 0x5FD,
    0x5FE, 0x2FE, 0x2F7, 0x1FD, 0x2EF, 0x5F7, 0xEF,  0x2FD, 0xFB,  0x5EF,
    0xFD,  0x8FF, 0x8FF, 0x8FF, 0x4EF, 0x6F7, 0x8FF, 0x1FE, 0x7EF, 0xF7,
    0x1FB, 0x2FB, 0x1F7, 0x1EF, 0x6EF, 0x5FB, 0x6F7, 0x6FB, 0x6FD, 0x7FB,
    0x7F7, 0x5FD, 0x5FE, 0x2FE, 0x2F7, 0x1FD, 0x2EF, 0x5F7, 0xEF,  0x2FD,
    0xFB,  0x5EF, 0xFD,  0x8FF, 0x8FF, 0x8FF, 0x8FF, 0x8FF, 0,     0};

int D_8004ED08 = 0;

short D_8004ED0C[] = {1, 0x21, 0x8001, 0x8021, 0x401, 0x421, 0x8401, 0x8421,
                      1, 0x3F, 0xF801, 0xF83F, 0x7C1, 0x7FF, 0xFFC1, 0xFFFF};

char *romnames[] = {"em/data/sabre.seg.rz",  "em/data/atic.seg.rz",
                    "em/data/jetpac.seg.rz", "em/data/jetman.seg.rz",
                    "em/data/alien8.seg.rz", "em/data/gunfright.seg.rz",
                    "em/data/under.seg.rz",  "em/data/knightlore.seg.rz",
                    "em/data/pssst.seg.rz",  "em/data/cookie.seg.rz"};

unsigned int D_8004ED54[] = {0x7000000, 0x0, 0xFF000000, 0xFF000000};

const char aEmDataSpec_rom_seg_rz[] = "em/data/spec_rom.seg.rz";

asm(R"
glabel sub_GAME_7F0D28E0
  sll   $t8, $a2, 8
  andi  $t9, $t8, 0x700
  sll   $t6, $a2, 5
  andi  $t7, $t6, 0x1800
  sll   $v1, $a2, 2
  or    $t3, $t7, $t9
  sra   $t0, $a1, 3
  andi  $t8, $v1, 0x3e0
  addiu $sp, $sp, -8
  addu  $t7, $t8, $t0
  sw    $s0, 4($sp)
  addu  $t9, $t7, $a0
  lbu   $t1, 0x1800($t9)
  andi  $t4, $v1, 0xe0
  or    $t5, $t3, $t4
  or    $t6, $t5, $t0
  andi  $t3, $t1, 0x80
  move  $s0, $a3
  addu  $v0, $t6, $a0
  beqz  $t3, .L7F0D2958
   move  $t2, $t1
  lui   $t4, %hi(D_8004EC40+0xC4) 
  lbu   $t4, %lo(D_8004EC40+0xC4)($t4)
  move  $v1, $t1
  andi  $t5, $v1, 7
  beqz  $t4, .L7F0D2958
   move  $v1, $t5
  sra   $t6, $t1, 3
  b     .L7F0D296C
   andi  $a0, $t6, 7
.L7F0D2958:
  move  $a0, $t2
  andi  $t7, $a0, 7
  sra   $t9, $t2, 3
  move  $a0, $t7
  andi  $v1, $t9, 7
.L7F0D296C:
  andi  $t4, $t2, 0x40
  bnez  $t4, .L7F0D2990
   move  $a1, $zero
  addiu $a0, $a0, 8
  addiu $v1, $v1, 8
  andi  $t5, $a0, 0xff
  andi  $t6, $v1, 0xff
  move  $a0, $t5
  move  $v1, $t6
.L7F0D2990:
  li    $t1, 8
.L7F0D2994:
  lbu   $a3, ($v0)
  addiu $a1, $a1, 1
  addiu $v0, $v0, 0x100
  andi  $t8, $a3, 0x80
  beqz  $t8, .L7F0D29B4
   andi  $t7, $a3, 0x40
  b     .L7F0D29B8
   move  $a2, $a0
.L7F0D29B4:
  move  $a2, $v1
.L7F0D29B8:
  beqz  $t7, .L7F0D29C8
   sll   $t9, $a2, 4
  b     .L7F0D29CC
   move  $t0, $a0
.L7F0D29C8:
  move  $t0, $v1
.L7F0D29CC:
  or    $t3, $t0, $t9
  andi  $t4, $a3, 0x20
  beqz  $t4, .L7F0D29E4
   sb    $t3, ($s0)
  b     .L7F0D29E8
   move  $a2, $a0
.L7F0D29E4:
  move  $a2, $v1
.L7F0D29E8:
  andi  $t5, $a3, 0x10
  beqz  $t5, .L7F0D29FC
   sll   $t6, $a2, 4
  b     .L7F0D2A00
   move  $t0, $a0
.L7F0D29FC:
  move  $t0, $v1
.L7F0D2A00:
  or    $t8, $t0, $t6
  andi  $t7, $a3, 8
  beqz  $t7, .L7F0D2A18
   sb    $t8, 1($s0)
  b     .L7F0D2A1C
   move  $a2, $a0
.L7F0D2A18:
  move  $a2, $v1
.L7F0D2A1C:
  andi  $t9, $a3, 4
  beqz  $t9, .L7F0D2A30
   sll   $t3, $a2, 4
  b     .L7F0D2A34
   move  $t0, $a0
.L7F0D2A30:
  move  $t0, $v1
.L7F0D2A34:
  or    $t4, $t0, $t3
  andi  $t5, $a3, 2
  beqz  $t5, .L7F0D2A4C
   sb    $t4, 2($s0)
  b     .L7F0D2A50
   move  $a2, $a0
.L7F0D2A4C:
  move  $a2, $v1
.L7F0D2A50:
  andi  $t6, $a3, 1
  beqz  $t6, .L7F0D2A64
   sll   $t8, $a2, 4
  b     .L7F0D2A68
   move  $t0, $a0
.L7F0D2A64:
  move  $t0, $v1
.L7F0D2A68:
  or    $t7, $t0, $t8
  sb    $t7, 3($s0)
  bne   $a1, $t1, .L7F0D2994
   addiu $s0, $s0, 0x20
  lw    $s0, 4($sp)
  jr    $ra
   addiu $sp, $sp, 8
");

asm(R"
glabel sub_GAME_7F0D2A84
  lui   $v0, %hi(D_8004ED08)
  addiu $v0, %lo(D_8004ED08) # addiu $v0, $v0, -0x12f8
  lbu   $t6, ($v0)
  li    $at, 25
  addiu $sp, $sp, -0x60
  addiu $t7, $t6, 1
  andi  $t8, $t7, 0xff
  div   $zero, $t8, $at
  sw    $s5, 0x2c($sp)
  mfhi  $t9
  move  $s5, $a0
  sw    $ra, 0x3c($sp)
  sw    $fp, 0x38($sp)
  sw    $s7, 0x34($sp)
  sw    $s6, 0x30($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a1, 0x64($sp)
  bnez  $t9, .L7F0D2B48
   sb    $t7, ($v0)
  sb    $zero, ($v0)
  lui   $s6, %hi(ptr_300alloc)
  addiu $s6, %lo(ptr_300alloc) # addiu $s6, $s6, -0x1cd4
  li    $v0, 1
  move  $v1, $zero
.L7F0D2AF4:
  lw    $t0, ($s6)
  li    $at, 768
  addu  $t1, $t0, $v1
  sb    $v0, ($t1)
  lw    $t2, ($s6)
  addu  $t3, $t2, $v1
  sb    $v0, 1($t3)
  lw    $t4, ($s6)
  addu  $t5, $t4, $v1
  sb    $v0, 2($t5)
  lw    $t6, ($s6)
  addu  $t7, $t6, $v1
  addiu $v1, $v1, 4
  bne   $v1, $at, .L7F0D2AF4
   sb    $v0, 3($t7)
  lui   $v0, %hi(D_8004EC40+0xC4)
  addiu $v0, %lo(D_8004EC40+0xC4) # addiu $v0, $v0, -0x12fc
  lbu   $t8, ($v0)
  li    $t9, 1
  subu  $t0, $t9, $t8
  sb    $t0, ($v0)
.L7F0D2B48:
  lui   $s6, %hi(ptr_300alloc)
  addiu $s6, %lo(ptr_300alloc) # addiu $s6, $s6, -0x1cd4
  sw    $zero, 0x58($sp)
.L7F0D2B54:
  lw    $t1, 0x58($sp)
  move  $s7, $zero
  sra   $t2, $t1, 6
  sll   $t3, $t2, 2
  sw    $t3, 0x40($sp)
  addiu $fp, $t1, 0x40
  lw    $t4, 0x40($sp)
.L7F0D2B70:
  lw    $s4, 0x58($sp)
  sra   $t5, $s7, 6
  lw    $t9, 0x64($sp)
  addu  $t6, $t4, $t5
  sll   $t7, $t6, 0xb
  slt   $at, $s4, $fp
  beqz  $at, .L7F0D2BF8
   addu  $s1, $t7, $t9
  addiu $s3, $s7, 0x40
.L7F0D2B94:
  slt   $at, $s7, $s3
  beqz  $at, .L7F0D2BE8
   move  $s0, $s7
  sra   $s2, $s4, 3
  sll   $t0, $s2, 5
  move  $s2, $t0
.L7F0D2BAC:
  lw    $t1, ($s6)
  sra   $t2, $s0, 3
  or    $t3, $s2, $t2
  addu  $t4, $t3, $t1
  lbu   $t5, ($t4)
  move  $a0, $s5
  move  $a1, $s0
  beqz  $t5, .L7F0D2BD8
   move  $a2, $s4
  jal   sub_GAME_7F0D28E0
   move  $a3, $s1
.L7F0D2BD8:
  addiu $s0, $s0, 8
  slt   $at, $s0, $s3
  bnez  $at, .L7F0D2BAC
   addiu $s1, $s1, 4
.L7F0D2BE8:
  addiu $s4, $s4, 8
  slt   $at, $s4, $fp
  bnez  $at, .L7F0D2B94
   addiu $s1, $s1, 0xe0
.L7F0D2BF8:
  addiu $s7, $s7, 0x40
  slti  $at, $s7, 0x100
  bnezl $at, .L7F0D2B70
   lw    $t4, 0x40($sp)
  slti  $at, $fp, 0xc0
  bnez  $at, .L7F0D2B54
   sw    $fp, 0x58($sp)
  move  $v0, $zero
.L7F0D2C18:
  lw    $t7, ($s6)
  li    $at, 768
  addu  $t9, $t7, $v0
  sb    $zero, ($t9)
  lw    $t8, ($s6)
  addu  $t0, $t8, $v0
  sb    $zero, 1($t0)
  lw    $t2, ($s6)
  addu  $t3, $t2, $v0
  sb    $zero, 2($t3)
  lw    $t1, ($s6)
  addu  $t4, $t1, $v0
  addiu $v0, $v0, 4
  bne   $v0, $at, .L7F0D2C18
   sb    $zero, 3($t4)
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
   addiu $sp, $sp, 0x60
");

asm(R"
glabel spectrum_p1controller_to_kempston
  addiu $sp, $sp, -0x38
  sw    $ra, 0x14($sp)
  sw    $zero, 0x34($sp)
  sw    $zero, 0x30($sp)
  sw    $zero, 0x2c($sp)
  sw    $zero, 0x28($sp)
  jal   redirect_to_ramrom_replay_and_record_handlers_if_set
   sw    $zero, 0x24($sp)
  move  $a0, $zero
  jal   get_controller_buttons_held
   li    $a1, 65535
  move  $a0, $zero
  li    $a1, -3
  li    $a2, 3
  jal   get_controller_3dstick_L_R
   sw    $v0, 0x20($sp)
  move  $a0, $zero
  li    $a1, -3
  li    $a2, 3
  jal   get_controller_3dstick_U_D
   sw    $v0, 0x1c($sp)
  li    $t6, 255
  lui   $at, %hi(D_8004EC34)
  lui   $a0, %hi(D_8004EC34+1)
  lui   $a1, %hi(D_8004EC3C+1)
  lw    $a3, 0x20($sp)
  lw    $t0, 0x1c($sp)
  addiu $a1, %lo(D_8004EC3C+1) # addiu $a1, $a1, -0x13c3
  addiu $a0, %lo(D_8004EC34+1) # addiu $a0, $a0, -0x13cb
  sb    $t6, %lo(D_8004EC34)($at)
  li    $v1, 255
.L7F0D2D00:
  addiu $a0, $a0, 4
  sb    $v1, -3($a0)
  sb    $v1, -2($a0)
  sb    $v1, -1($a0)
  bne   $a0, $a1, .L7F0D2D00
   sb    $v1, -4($a0)
  andi  $t7, $a3, 0x2000
  beqz  $t7, .L7F0D2D2C
   andi  $t9, $a3, 0x202
  li    $t8, 1
  sw    $t8, 0x24($sp)
.L7F0D2D2C:
  bnez  $t9, .L7F0D2D3C
   andi  $t2, $a3, 0x101
  slti  $at, $t0, -1
  beqz  $at, .L7F0D2D44
.L7F0D2D3C:
   li    $t1, 1
  sw    $t1, 0x2c($sp)
.L7F0D2D44:
  bnez  $t2, .L7F0D2D54
   andi  $t4, $a3, 0x808
  slti  $at, $t0, 2
  bnez  $at, .L7F0D2D5C
.L7F0D2D54:
   li    $t3, 1
  sw    $t3, 0x28($sp)
.L7F0D2D5C:
  bnez  $t4, .L7F0D2D6C
   andi  $t5, $a3, 0x404
  slti  $at, $v0, 2
  bnez  $at, .L7F0D2D74
.L7F0D2D6C:
   li    $a1, 1
  sw    $a1, 0x34($sp)
.L7F0D2D74:
  bnez  $t5, .L7F0D2D84
   lw    $a1, 0x34($sp)
  slti  $at, $v0, -1
  beqz  $at, .L7F0D2D8C
.L7F0D2D84:
   li    $a2, 1
  sw    $a2, 0x30($sp)
.L7F0D2D8C:
  lui   $v1, %hi(byte_CODE_bss_8008E34D)
  lbu   $v1, %lo(byte_CODE_bss_8008E34D)($v1)
  li    $a0, 2
  lw    $a2, 0x30($sp)
  bne   $a0, $v1, .L7F0D2DB4
   li    $v0, 4
  andi  $t6, $a3, 0xc000
  beqz  $t6, .L7F0D2DB4
   nop   
  li    $a1, 1
.L7F0D2DB4:
  beq   $v0, $v1, .L7F0D2DC0
   li    $at, 7
  bne   $v1, $at, .L7F0D2DD0
.L7F0D2DC0:
   andi  $t7, $a3, 0xc000
  beqz  $t7, .L7F0D2DD0
   nop   
  li    $a2, 1
.L7F0D2DD0:
  beqz  $v1, .L7F0D2DFC
   li    $at, 1
  beq   $v1, $at, .L7F0D2DFC
   li    $at, 6
  beq   $v1, $at, .L7F0D2DFC
   li    $at, 9
  beql  $v1, $at, .L7F0D2E00
   andi  $t8, $a3, 0xc000
  beq   $v0, $v1, .L7F0D2DFC
   li    $at, 7
  bne   $v1, $at, .L7F0D2E18
.L7F0D2DFC:
   andi  $t8, $a3, 0xc000
.L7F0D2E00:
  beqz  $t8, .L7F0D2E18
   lui   $v0, %hi(D_8004EC34)
  addiu $v0, %lo(D_8004EC34) # addiu $v0, $v0, -0x13cc
  lbu   $t9, 4($v0)
  andi  $t1, $t9, 0xfe
  sb    $t1, 4($v0)
.L7F0D2E18:
  lui   $v0, %hi(D_8004EC34)
  beq   $a0, $v1, .L7F0D2E2C
   addiu $v0, %lo(D_8004EC34) # addiu $v0, $v0, -0x13cc
  li    $at, 8
  bne   $v1, $at, .L7F0D2E44
.L7F0D2E2C:
   andi  $t2, $a3, 0xc000
  beql  $t2, $zero, .L7F0D2E48
   li    $at, 5
  lbu   $t3, 3($v0)
  andi  $t4, $t3, 0xef
  sb    $t4, 3($v0)
.L7F0D2E44:
  li    $at, 5
.L7F0D2E48:
  bne   $v1, $at, .L7F0D2E64
   andi  $t5, $a3, 0xc000
  beql  $t5, $zero, .L7F0D2E68
   li    $at, 3
  lbu   $t6, 3($v0)
  andi  $t7, $t6, 0xfb
  sb    $t7, 3($v0)
.L7F0D2E64:
  li    $at, 3
.L7F0D2E68:
  bne   $v1, $at, .L7F0D2EAC
   andi  $t8, $a3, 0xc000
  beqz  $t8, .L7F0D2E84
   andi  $t2, $a3, 0x8000
  lbu   $t9, 4($v0)
  andi  $t1, $t9, 0xef
  sb    $t1, 4($v0)
.L7F0D2E84:
  beqz  $t2, .L7F0D2E98
   andi  $t5, $a3, 0x4000
  lbu   $t3, ($v0)
  andi  $t4, $t3, 0xfd
  sb    $t4, ($v0)
.L7F0D2E98:
  beql  $t5, $zero, .L7F0D2EB0
   li    $at, 6
  lbu   $t6, 7($v0)
  andi  $t7, $t6, 0xfe
  sb    $t7, 7($v0)
.L7F0D2EAC:
  li    $at, 6
.L7F0D2EB0:
  bne   $v1, $at, .L7F0D2ED8
   andi  $t8, $a3, 0x8000
  beqz  $t8, .L7F0D2EC4
   andi  $a0, $a3, 0x4000
  li    $a1, 1
.L7F0D2EC4:
  beql  $a0, $zero, .L7F0D2EDC
   li    $at, 1
  lbu   $t9, 7($v0)
  andi  $t1, $t9, 0xfe
  sb    $t1, 7($v0)
.L7F0D2ED8:
  li    $at, 1
.L7F0D2EDC:
  bne   $v1, $at, .L7F0D2F34
   andi  $t2, $a3, 0xc000
  beqz  $t2, .L7F0D2EF8
   andi  $t5, $a3, 0x200
  lbu   $t3, ($v0)
  andi  $t4, $t3, 0xfd
  sb    $t4, ($v0)
.L7F0D2EF8:
  beqz  $t5, .L7F0D2F0C
   andi  $t8, $a3, 0x400
  lbu   $t6, 3($v0)
  andi  $t7, $t6, 0xf7
  sb    $t7, 3($v0)
.L7F0D2F0C:
  beqz  $t8, .L7F0D2F20
   andi  $t2, $a3, 0x100
  lbu   $t9, 3($v0)
  andi  $t1, $t9, 0xef
  sb    $t1, 3($v0)
.L7F0D2F20:
  beql  $t2, $zero, .L7F0D2F38
   andi  $t5, $a3, 0x20
  lbu   $t3, 4($v0)
  andi  $t4, $t3, 0xef
  sb    $t4, 4($v0)
.L7F0D2F34:
  andi  $t5, $a3, 0x20
.L7F0D2F38:
  beqz  $t5, .L7F0D2F88
   lui   $at, %hi(D_8004EC40)
  lui   $v0, %hi(ptr_spectrum_roms)
  addiu $v0, %lo(ptr_spectrum_roms) # addiu $v0, $v0, -0x1cd8
  move  $v1, $zero
  li    $a0, 16384
.L7F0D2F50:
  lw    $t6, ($v0)
  addu  $t7, $t6, $v1
  sb    $zero, ($t7)
  lw    $t8, ($v0)
  addu  $t9, $t8, $v1
  sb    $zero, 1($t9)
  lw    $t1, ($v0)
  addu  $t2, $t1, $v1
  sb    $zero, 2($t2)
  lw    $t3, ($v0)
  addu  $t4, $t3, $v1
  addiu $v1, 4 # addiu $v1, $v1, 4
  bne   $v1, $a0, .L7F0D2F50
   sb    $zero, 3($t4)
.L7F0D2F88:
  lw    $t5, 0x24($sp)
  lw    $t2, 0x2c($sp)
  sll   $t7, $a1, 3
  sll   $t6, $t5, 4
  lw    $t5, 0x28($sp)
  or    $t8, $t6, $t7
  sll   $t9, $a2, 2
  lw    $ra, 0x14($sp)
  or    $t1, $t8, $t9
  sll   $t3, $t2, 1
  or    $t4, $t1, $t3
  or    $t6, $t4, $t5
  sb    $t6, %lo(D_8004EC40)($at)
  jr    $ra
   addiu $sp, $sp, 0x38
");

asm(R"
glabel init_spectrum_game
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  li    $a0, 256
  jal   mempAllocBytesInBank
   li    $a1, 4
  lui   $a2, %hi(ptr_pc_keyboard_table_alloc)
  addiu $a2, %lo(ptr_pc_keyboard_table_alloc) # addiu $a2, $a2, -0x1ccc
  sw    $v0, ($a2)
  move  $a0, $zero
  li    $a3, 4
  li    $a1, 8
  move  $v1, $zero
.L7F0D2FF8:
  move  $v0, $zero
  srav  $t6, $a0, $v0
.L7F0D3000:
  andi  $t7, $t6, 1
  beqz  $t7, .L7F0D3010
   addiu $v0, $v0, 1
  addiu $v1, $v1, 1
.L7F0D3010:
  bnel  $v0, $a1, .L7F0D3000
   srav  $t6, $a0, $v0
  andi  $t8, $v1, 1
  beql  $t8, $zero, .L7F0D3038
   lw    $t2, ($a2)
  lw    $t9, ($a2)
  addu  $t1, $t9, $a0
  b     .L7F0D3040
   sb    $zero, ($t1)
  lw    $t2, ($a2)
.L7F0D3038:
  addu  $t3, $t2, $a0
  sb    $a3, ($t3)
.L7F0D3040:
  addiu $a0, $a0, 1
  slti  $at, $a0, 0x100
  bnezl $at, .L7F0D2FF8
   move  $v1, $zero
  li    $a0, 24576
  jal   mempAllocBytesInBank
   li    $a1, 4
  lui   $at, %hi(ptr_6000alloc)
  sw    $v0, %lo(ptr_6000alloc)($at)
  li    $a0, 768
  jal   mempAllocBytesInBank
   li    $a1, 4
  lui   $v1, %hi(ptr_300alloc)
  addiu $v1, %lo(ptr_300alloc) # addiu $v1, $v1, -0x1cd4
  sw    $v0, ($v1)
  li    $v0, 1
  move  $a0, $zero
.L7F0D3084:
  lw    $t4, ($v1)
  addu  $t5, $t4, $a0
  addiu $a0, $a0, 1
  slti  $at, $a0, 0x300
  bnez  $at, .L7F0D3084
   sb    $v0, ($t5)
  lui   $a0, 1
  jal   mempAllocBytesInBank
   li    $a1, 4
  lui   $t0, %hi(ptr_spectrum_roms) 
  addiu $t0, %lo(ptr_spectrum_roms) # addiu $t0, $t0, -0x1cd8
  lui   $a0, %hi(aEmDataSpec_rom_seg_rz)
  sw    $v0, ($t0)
  addiu $a0, %lo(aEmDataSpec_rom_seg_rz) # addiu $a0, $a0, -0x3eec
  li    $a1, 1
  li    $a2, 256
  jal   _load_resource_named_to_membank
   li    $a3, 4
  lui   $v1, %hi(ptr_sectrum_monitor_data_temp_buf)
  addiu $v1, %lo(ptr_sectrum_monitor_data_temp_buf) # addiu $v1, $v1, -0x1ce0
  lui   $t0, %hi(ptr_spectrum_roms) 
  addiu $t0, %lo(ptr_spectrum_roms) # addiu $t0, $t0, -0x1cd8
  sw    $v0, ($v1)
  move  $a0, $zero
.L7F0D30E4:
  lw    $t6, ($v1)
  lw    $t9, ($t0)
  addu  $t7, $t6, $a0
  addu  $t1, $t9, $a0
  lbu   $t8, ($t7)
  addiu $a0, $a0, 1
  slti  $at, $a0, 0x4000
  bnez  $at, .L7F0D30E4
   sb    $t8, ($t1)
  lw    $t2, 0x18($sp)
  lui   $v1, %hi(byte_CODE_bss_8008E34D)
  addiu $v1, %lo(byte_CODE_bss_8008E34D) # addiu $v1, $v1, -0x1cb3
  andi  $v0, $t2, 0xff
  slti  $at, $v0, 5
  bnez  $at, .L7F0D312C
   sb    $t2, ($v1)
  sb    $zero, ($v1)
  andi  $v0, $zero, 0xff
.L7F0D312C:
  sll   $t3, $v0, 2
  lui   $a0, %hi(romnames)
  addu  $a0, $a0, $t3
  lw    $a0, %lo(romnames)($a0)
  li    $a1, 1
  li    $a2, 256
  jal   _load_resource_named_to_membank
   li    $a3, 4
  lui   $v1, %hi(ptr_sectrum_game_data_temp_buf)
  addiu $v1, %lo(ptr_sectrum_game_data_temp_buf) # addiu $v1, $v1, -0x1cdc
  sw    $v0, ($v1)
  lui   $t0, %hi(ptr_spectrum_roms) 
  addiu $t0, %lo(ptr_spectrum_roms) # addiu $t0, $t0, -0x1cd8
  li    $v0, 49152
  move  $a0, $zero
.L7F0D3168:
  lw    $t4, ($v1)
  lw    $t7, ($t0)
  addu  $t5, $a0, $t4
  lbu   $t6, 0x1b($t5)
  addu  $t9, $t7, $a0
  sb    $t6, 0x4000($t9)
  lw    $t8, ($v1)
  lw    $t3, ($t0)
  addu  $t1, $a0, $t8
  lbu   $t2, 0x1c($t1)
  addu  $t4, $t3, $a0
  sb    $t2, 0x4001($t4)
  lw    $t5, ($v1)
  lw    $t9, ($t0)
  addu  $t7, $a0, $t5
  lbu   $t6, 0x1d($t7)
  addu  $t8, $t9, $a0
  sb    $t6, 0x4002($t8)
  lw    $t1, ($v1)
  lw    $t4, ($t0)
  addu  $t3, $a0, $t1
  lbu   $t2, 0x1e($t3)
  addu  $t5, $t4, $a0
  addiu $a0, $a0, 4
  bne   $a0, $v0, .L7F0D3168
   sb    $t2, 0x4003($t5)
  lw    $v0, ($v1)
  lui   $at, %hi(spec_I)
  lui   $a1, %hi(spec_IFF2_upper)
  lbu   $t7, ($v0)
  addiu $a1, %lo(spec_IFF2_upper) # addiu $a1, $a1, -0x1cb5
  lui   $a2, %hi(spec_SP)
  sb    $t7, %lo(spec_I)($at)
  lbu   $t9, 1($v0)
  lui   $at, %hi(byte_CODE_bss_8008E347)
  addiu $a2, %lo(spec_SP) # addiu $a2, $a2, -0x1cae
  sb    $t9, %lo(byte_CODE_bss_8008E347)($at)
  lbu   $t6, 2($v0)
  lui   $at, %hi(byte_CODE_bss_8008E346)
  lui   $a3, %hi(spec_IM)
  sb    $t6, %lo(byte_CODE_bss_8008E346)($at)
  lbu   $t8, 3($v0)
  lui   $at, %hi(byte_CODE_bss_8008E345)
  addiu $a3, %lo(spec_IM) # addiu $a3, $a3, -0x1cb4
  sb    $t8, %lo(byte_CODE_bss_8008E345)($at)
  lbu   $t1, 4($v0)
  lui   $at, %hi(off_CODE_bss_8008E344)
  sb    $t1, %lo(off_CODE_bss_8008E344)($at)
  lbu   $t3, 5($v0)
  lui   $at, %hi(byte_CODE_bss_8008E343)
  sb    $t3, %lo(byte_CODE_bss_8008E343)($at)
  lbu   $t4, 6($v0)
  lui   $at, %hi(byte_CODE_bss_8008E342)
  sb    $t4, %lo(byte_CODE_bss_8008E342)($at)
  lbu   $t2, 7($v0)
  lui   $at, %hi(byte_CODE_bss_8008E341)
  sb    $t2, %lo(byte_CODE_bss_8008E341)($at)
  lbu   $t5, 8($v0)
  lui   $at, %hi(off_CODE_bss_8008E340)
  sb    $t5, %lo(off_CODE_bss_8008E340)($at)
  lbu   $t7, 9($v0)
  lui   $at, %hi(byte_CODE_bss_8008E33F)
  sb    $t7, %lo(byte_CODE_bss_8008E33F)($at)
  lbu   $t9, 0xa($v0)
  lui   $at, %hi(byte_CODE_bss_8008E33E)
  sb    $t9, %lo(byte_CODE_bss_8008E33E)($at)
  lbu   $t6, 0xb($v0)
  lui   $at, %hi(byte_CODE_bss_8008E33D)
  sb    $t6, %lo(byte_CODE_bss_8008E33D)($at)
  lbu   $t8, 0xc($v0)
  lui   $at, %hi(off_CODE_bss_8008E33C)
  sb    $t8, %lo(off_CODE_bss_8008E33C)($at)
  lbu   $t1, 0xd($v0)
  lui   $at, %hi(byte_CODE_bss_8008E33B)
  sb    $t1, %lo(byte_CODE_bss_8008E33B)($at)
  lbu   $t3, 0xe($v0)
  lui   $at, %hi(byte_CODE_bss_8008E33A)
  sb    $t3, %lo(byte_CODE_bss_8008E33A)($at)
  lbu   $t4, 0x10($v0)
  lbu   $t5, 0xf($v0)
  lui   $at, %hi(spec_IY)
  sll   $t2, $t4, 8
  addu  $t7, $t2, $t5
  sh    $t7, %lo(spec_IY)($at)
  lbu   $t9, 0x12($v0)
  lbu   $t8, 0x11($v0)
  lui   $at, %hi(spec_IX)
  sll   $t6, $t9, 8
  addu  $t1, $t6, $t8
  sh    $t1, %lo(spec_IX)($at)
  lbu   $t3, 0x13($v0)
  lui   $at, %hi(spec_IFF2_lower)
  sra   $t4, $t3, 2
  andi  $t5, $t4, 1
  sb    $t5, ($a1)
  sb    $t5, %lo(spec_IFF2_lower)($at)
  lbu   $t7, 0x14($v0)
  lui   $at, %hi(byte_CODE_bss_8008E349)
  sb    $t7, %lo(byte_CODE_bss_8008E349)($at)
  lbu   $t9, 0x15($v0)
  lui   $at, %hi(byte_CODE_bss_8008E339)
  sb    $t9, %lo(byte_CODE_bss_8008E339)($at)
  lbu   $t6, 0x16($v0)
  lui   $at, %hi(spectrum_header16_15)
  sb    $t6, %lo(spectrum_header16_15)($at)
  lbu   $t8, 0x18($v0)
  lbu   $t3, 0x17($v0)
  lui   $at, %hi(spec_PC)
  sll   $t1, $t8, 8
  addu  $t4, $t1, $t3
  sh    $t4, ($a2)
  lbu   $t2, 0x19($v0)
  andi  $a0, $t2, 0xff
  blez  $a0, .L7F0D333C
   sb    $t2, ($a3)
  addiu $t5, $a0, 1
  sb    $t5, ($a3)
.L7F0D333C:
  lhu   $v1, ($a2)
  lw    $v0, ($t0)
  lw    $ra, 0x14($sp)
  addiu $t4, $v1, 2
  addu  $t6, $v0, $v1
  lbu   $t8, 1($t6)
  addu  $t7, $v1, $v0
  lbu   $t9, ($t7)
  sll   $t1, $t8, 8
  addiu $sp, $sp, 0x18
  or    $t3, $t9, $t1
  sh    $t3, %lo(spec_PC)($at)
  jr    $ra
   sh    $t4, ($a2)
");

asm(R"
glabel run_spectrum_game
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   spectrum_p1controller_to_kempston
   nop   
  jal   spectrum_hw_emulation
   nop   
  lui   $a0, %hi(ptr_spectrum_roms)
  lw    $a0, %lo(ptr_spectrum_roms)($a0)
  lui   $a1, %hi(ptr_6000alloc)
  lw    $a1, %lo(ptr_6000alloc)($a1)
  jal   sub_GAME_7F0D2A84
   addiu $a0, $a0, 0x4000
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel spectrum_draw_screen
  addiu $sp, $sp, -0xa0
  move  $v0, $a0
  sw    $ra, 0x2c($sp)
  sw    $fp, 0x28($sp)
  sw    $s7, 0x24($sp)
  sw    $s6, 0x20($sp)
  sw    $s5, 0x1c($sp)
  sw    $s4, 0x18($sp)
  sw    $s3, 0x14($sp)
  sw    $s2, 0x10($sp)
  sw    $s1, 0xc($sp)
  sw    $s0, 8($sp)
  lui   $t3, 0xe700
  addiu $a0, $a0, 8
  sw    $t3, ($v0)
  sw    $zero, 4($v0)
  move  $v1, $a0
  lui   $t6, %hi(D_8004ED0C) 
  addiu $t6, %lo(D_8004ED0C) # addiu $t6, $t6, -0x12f4
  addiu $a0, $a0, 8
  lui   $s0, 0xfd10
  sw    $t6, 4($v1)
  move  $a1, $a0
  lui   $t7, (0xF5000300 >> 16) # lui $t7, 0xf500
  sw    $s0, ($v1)
  ori   $t7, (0xF5000300 & 0xFFFF) # ori $t7, $t7, 0x300
  addiu $a0, $a0, 8
  lui   $s1, 0x700
  sw    $t7, ($a1)
  move  $a2, $a0
  sw    $s1, 4($a1)
  addiu $a0, $a0, 8
  lui   $s2, 0xe600
  move  $a3, $a0
  sw    $s2, ($a2)
  sw    $zero, 4($a2)
  lui   $t9, (0x0703C000 >> 16) # lui $t9, 0x703
  ori   $t9, (0x0703C000 & 0xFFFF) # ori $t9, $t9, 0xc000
  addiu $a0, $a0, 8
  lui   $t8, 0xf000
  sw    $t8, ($a3)
  sw    $t9, 4($a3)
  move  $v0, $a0
  lui   $t6, (0xBA001301 >> 16) # lui $t6, 0xba00
  ori   $t6, (0xBA001301 & 0xFFFF) # ori $t6, $t6, 0x1301
  addiu $a0, $a0, 8
  sw    $t6, ($v0)
  move  $v1, $a0
  sw    $zero, 4($v0)
  lui   $t8, (0x0F0A4000 >> 16) # lui $t8, 0xf0a
  lui   $t7, (0xB900031D >> 16) # lui $t7, 0xb900
  ori   $t7, (0xB900031D & 0xFFFF) # ori $t7, $t7, 0x31d
  ori   $t8, (0x0F0A4000 & 0xFFFF) # ori $t8, $t8, 0x4000
  addiu $a0, $a0, 8
  sw    $t8, 4($v1)
  sw    $t7, ($v1)
  move  $a1, $a0
  lui   $t9, (0xFCFFFFFF >> 16) # lui $t9, 0xfcff
  ori   $t9, (0xFCFFFFFF & 0xFFFF) # ori $t9, $t9, 0xffff
  addiu $a0, $a0, 8
  lui   $t6, (0xFFFCF87C >> 16) # lui $t6, 0xfffc
  ori   $t6, (0xFFFCF87C & 0xFFFF) # ori $t6, $t6, 0xf87c
  sw    $t9, ($a1)
  move  $a2, $a0
  sw    $t6, 4($a1)
  lui   $t7, (0xBA000C02 >> 16) # lui $t7, 0xba00
  ori   $t7, (0xBA000C02 & 0xFFFF) # ori $t7, $t7, 0xc02
  addiu $a0, $a0, 8
  sw    $t7, ($a2)
  sw    $zero, 4($a2)
  move  $a3, $a0
  lui   $t8, (0xBB000001 >> 16) # lui $t8, 0xbb00
  ori   $t8, (0xBB000001 & 0xFFFF) # ori $t8, $t8, 1
  li    $t9, -1
  sw    $t9, 4($a3)
  sw    $t8, ($a3)
  lui   $s3, %hi(ptr_6000alloc)
  lui   $s6, (0x073FF200 >> 16) # lui $s6, 0x73f
  lui   $s7, (0xBA000E02 >> 16) # lui $s7, 0xba00
  lui   $ra, (0xF5400800 >> 16) # lui $ra, 0xf540
  addiu $a0, $a0, 8
  ori   $ra, (0xF5400800 & 0xFFFF) # ori $ra, $ra, 0x800
  ori   $s7, (0xBA000E02 & 0xFFFF) # ori $s7, $s7, 0xe02
  ori   $s6, (0x073FF200 & 0xFFFF) # ori $s6, $s6, 0xf200
  addiu $s3, %lo(ptr_6000alloc) # addiu $s3, $s3, -0x1cd0
  sw    $zero, 0x3c($sp)
  move  $v0, $zero
  lui   $s4, 0xf510
  lui   $s5, 0xf300
  li    $fp, 32768
.L7F0D351C:
  lw    $t0, 0x3c($sp)
  addiu $v1, $v0, 1
  sll   $t4, $v1, 6
  sll   $t5, $v0, 6
  addiu $t5, $t5, 0x18
  addiu $t4, $t4, 0x18
  sll   $t7, $t4, 2
  sll   $t9, $t5, 2
  sll   $t6, $t0, 0xb
  move  $t0, $t6
  andi  $t5, $t9, 0xfff
  andi  $t4, $t7, 0xfff
  sw    $v1, 0x34($sp)
  move  $a3, $zero
.L7F0D3554:
  move  $v0, $a0
  addiu $a0, $a0, 8
  sw    $t3, ($v0)
  sw    $zero, 4($v0)
  move  $v1, $a0
  sw    $s0, ($v1)
  lw    $t7, ($s3)
  addiu $a0, $a0, 8
  move  $a1, $a0
  addu  $t8, $t0, $t7
  sw    $t8, 4($v1)
  addiu $a0, $a0, 8
  move  $a2, $a0
  sw    $s1, 4($a1)
  sw    $s4, ($a1)
  addiu $a0, $a0, 8
  move  $t1, $a0
  sw    $zero, 4($a2)
  sw    $s2, ($a2)
  addiu $a0, $a0, 8
  move  $v0, $a0
  sw    $s6, 4($t1)
  sw    $s5, ($t1)
  addiu $a0, $a0, 8
  sw    $zero, 4($v0)
  sw    $t3, ($v0)
  move  $v1, $a0
  addiu $a0, $a0, 8
  move  $a1, $a0
  lui   $t9, (0x00018060 >> 16) # lui $t9, 1
  sw    $s7, ($v1)
  sw    $fp, 4($v1)
  ori   $t9, (0x00018060 & 0xFFFF) # ori $t9, $t9, 0x8060
  sw    $t9, 4($a1)
  addiu $a0, $a0, 8
  addiu $v0, $a3, 1
  sw    $ra, ($a1)
  move  $a2, $a0
  lui   $t7, (0x007E07E0 >> 16) # lui $t7, 0x7e
  lui   $t6, 0xf200
  sll   $t8, $v0, 6
  sw    $t6, ($a2)
  ori   $t7, (0x007E07E0 & 0xFFFF) # ori $t7, $t7, 0x7e0
  addiu $t9, $t8, 0x20
  sw    $t7, 4($a2)
  sll   $t6, $t9, 2
  andi  $t7, $t6, 0xfff
  sll   $t8, $t7, 0xc
  lui   $at, 0xe400
  or    $t9, $t8, $at
  addiu $a0, $a0, 8
  or    $t6, $t9, $t4
  sll   $t7, $a3, 6
  addiu $t8, $t7, 0x20
  move  $t2, $a0
  sw    $t6, ($t2)
  sll   $t9, $t8, 2
  andi  $t6, $t9, 0xfff
  sll   $t7, $t6, 0xc
  addiu $a0, $a0, 8
  move  $v1, $a0
  or    $t8, $t7, $t5
  sw    $t8, 4($t2)
  addiu $a0, $a0, 8
  move  $a1, $a0
  lui   $t7, (0x04000400 >> 16) # lui $t7, 0x400
  lui   $t9, 0xb400
  li    $at, 4
  sw    $t9, ($v1)
  ori   $t7, (0x04000400 & 0xFFFF) # ori $t7, $t7, 0x400
  sw    $zero, 4($v1)
  lui   $t6, 0xb300
  move  $a3, $v0
  addiu $t0, $t0, 0x800
  sw    $t6, ($a1)
  sw    $t7, 4($a1)
  bne   $v0, $at, .L7F0D3554
   addiu $a0, $a0, 8
  lw    $t8, 0x3c($sp)
  lw    $v0, 0x34($sp)
  li    $at, 3
  addiu $t9, $t8, 4
  bne   $v0, $at, .L7F0D351C
   sw    $t9, 0x3c($sp)
  lw    $ra, 0x2c($sp)
  lw    $s0, 8($sp)
  lw    $s1, 0xc($sp)
  lw    $s2, 0x10($sp)
  lw    $s3, 0x14($sp)
  lw    $s4, 0x18($sp)
  lw    $s5, 0x1c($sp)
  lw    $s6, 0x20($sp)
  lw    $s7, 0x24($sp)
  lw    $fp, 0x28($sp)
  addiu $sp, $sp, 0xa0
  jr    $ra
   move  $v0, $a0
");

asm(R"
glabel spectrum_input_handling
  sw    $a1, 4($sp)
  andi  $t6, $a1, 0xff
  andi  $v0, $a2, 0xff
  li    $at, 254
  move  $a1, $t6
  sw    $a0, ($sp)
  bne   $v0, $at, .L7F0D37B4
   sw    $a2, 8($sp)
  lui   $a2, %hi(D_8004EC34)
  li    $v1, 255
  addiu $a2, %lo(D_8004EC34) # addiu $a2, $a2, -0x13cc
  move  $v0, $zero
  li    $a3, 8
.L7F0D370C:
  andi  $t8, $a1, 1
  bnez  $t8, .L7F0D372C
   move  $a0, $a1
  addu  $t9, $a2, $v0
  lbu   $t0, ($t9)
  and   $v1, $v1, $t0
  andi  $t1, $v1, 0xff
  move  $v1, $t1
.L7F0D372C:
  srl   $a1, $a0, 1
  andi  $a0, $a1, 0xff
  andi  $t3, $a0, 1
  bnez  $t3, .L7F0D3754
   srl   $a1, $a0, 1
  addu  $t4, $a2, $v0
  lbu   $t5, 1($t4)
  and   $v1, $v1, $t5
  andi  $t6, $v1, 0xff
  move  $v1, $t6
.L7F0D3754:
  andi  $a0, $a1, 0xff
  andi  $t8, $a0, 1
  bnez  $t8, .L7F0D3778
   srl   $a1, $a0, 1
  addu  $t9, $a2, $v0
  lbu   $t0, 2($t9)
  and   $v1, $v1, $t0
  andi  $t1, $v1, 0xff
  move  $v1, $t1
.L7F0D3778:
  andi  $a0, $a1, 0xff
  andi  $t3, $a0, 1
  bnez  $t3, .L7F0D379C
   srl   $a1, $a0, 1
  addu  $t4, $a2, $v0
  lbu   $t5, 3($t4)
  and   $v1, $v1, $t5
  andi  $t6, $v1, 0xff
  move  $v1, $t6
.L7F0D379C:
  andi  $t7, $a1, 0xff
  addiu $v0, $v0, 4
  bne   $v0, $a3, .L7F0D370C
   move  $a1, $t7
  jr    $ra
   move  $v0, $v1

.L7F0D37B4:
  li    $at, 31
  bne   $v0, $at, .L7F0D37C8
   lui   $v0, %hi(D_8004EC40)
  jr    $ra
   lbu   $v0, %lo(D_8004EC40)($v0)

.L7F0D37C8:
  li    $v0, 255
  jr    $ra
   nop   
");

void nullsub_50(void) {}

asm(R"
glabel sub_GAME_7F0D37DC
  andi  $t6, $a2, 0xff
  li    $at, 254
  sw    $a0, ($sp)
  sw    $a1, 4($sp)
  sw    $a2, 8($sp)
  sw    $a3, 0xc($sp)
  bne   $t6, $at, .L7F0D3820
   andi  $t7, $a3, 0xff
  lui   $t8, %hi(D_8004ED54) 
  lbu   $t8, %lo(D_8004ED54)($t8)
  andi  $v0, $t7, 7
  lui   $at, %hi(D_8004ED54)
  beq   $v0, $t8, .L7F0D3818
   nop   
  sb    $v0, %lo(D_8004ED54)($at)
.L7F0D3818:
  jr    $ra
   move  $v0, $zero

.L7F0D3820:
  move  $v0, $zero
  jr    $ra
   nop   
");

asm(R"
.late_rodata
/*D:8005C12C*/
glabel spectrum_op_table
.word spectrum_op_00
.word spectrum_op_01
.word spectrum_op_02
.word spectrum_op_03
.word spectrum_op_04
.word spectrum_op_05
.word spectrum_op_06
.word spectrum_op_07
.word spectrum_op_08
.word spectrum_op_09
.word spectrum_op_0A
.word spectrum_op_0B
.word spectrum_op_0C
.word spectrum_op_0D
.word spectrum_op_0E
.word spectrum_op_0F
.word spectrum_op_10
.word spectrum_op_11
.word spectrum_op_12
.word spectrum_op_13
.word spectrum_op_14
.word spectrum_op_15
.word spectrum_op_16
.word spectrum_op_17
.word spectrum_op_18
.word spectrum_op_19
.word spectrum_op_1A
.word spectrum_op_1B
.word spectrum_op_1C
.word spectrum_op_1D
.word spectrum_op_1E
.word spectrum_op_1F
.word spectrum_op_20
.word spectrum_op_21
.word spectrum_op_22
.word spectrum_op_23
.word spectrum_op_24
.word spectrum_op_25
.word spectrum_op_26
.word spectrum_op_27
.word spectrum_op_28
.word spectrum_op_29
.word spectrum_op_2A
.word spectrum_op_2B
.word spectrum_op_2C
.word spectrum_op_2D
.word spectrum_op_2E
.word spectrum_op_2F
.word spectrum_op_30
.word spectrum_op_31
.word spectrum_op_32
.word spectrum_op_33
.word spectrum_op_34
.word spectrum_op_35
.word spectrum_op_36
.word spectrum_op_37
.word spectrum_op_38
.word spectrum_op_39
.word spectrum_op_3A
.word spectrum_op_3B
.word spectrum_op_3C
.word spectrum_op_3D
.word spectrum_op_3E
.word spectrum_op_3F
.word spectrum_op_40
.word spectrum_op_41
.word spectrum_op_42
.word spectrum_op_43
.word spectrum_op_44
.word spectrum_op_45
.word spectrum_op_46
.word spectrum_op_47
.word spectrum_op_48
.word spectrum_op_49
.word spectrum_op_4A
.word spectrum_op_4B
.word spectrum_op_4C
.word spectrum_op_4D
.word spectrum_op_4E
.word spectrum_op_4F
.word spectrum_op_50
.word spectrum_op_51
.word spectrum_op_52
.word spectrum_op_53
.word spectrum_op_54
.word spectrum_op_55
.word spectrum_op_56
.word spectrum_op_57
.word spectrum_op_58
.word spectrum_op_59
.word spectrum_op_5A
.word spectrum_op_5B
.word spectrum_op_5C
.word spectrum_op_5D
.word spectrum_op_5E
.word spectrum_op_5F
.word spectrum_op_60
.word spectrum_op_61
.word spectrum_op_62
.word spectrum_op_63
.word spectrum_op_64
.word spectrum_op_65
.word spectrum_op_66
.word spectrum_op_67
.word spectrum_op_68
.word spectrum_op_69
.word spectrum_op_6A
.word spectrum_op_6B
.word spectrum_op_6C
.word spectrum_op_6D
.word spectrum_op_6E
.word spectrum_op_6F
.word spectrum_op_70
.word spectrum_op_71
.word spectrum_op_72
.word spectrum_op_73
.word spectrum_op_74
.word spectrum_op_75
.word spectrum_op_76
.word spectrum_op_77
.word spectrum_op_78
.word spectrum_op_79
.word spectrum_op_7A
.word spectrum_op_7B
.word spectrum_op_7C
.word spectrum_op_7D
.word spectrum_op_7E
.word spectrum_op_7F
.word spectrum_op_80
.word spectrum_op_81
.word spectrum_op_82
.word spectrum_op_83
.word spectrum_op_84
.word spectrum_op_85
.word spectrum_op_86
.word spectrum_op_87
.word spectrum_op_88
.word spectrum_op_89
.word spectrum_op_8A
.word spectrum_op_8B
.word spectrum_op_8C
.word spectrum_op_8D
.word spectrum_op_8E
.word spectrum_op_8F
.word spectrum_op_90
.word spectrum_op_91
.word spectrum_op_92
.word spectrum_op_93
.word spectrum_op_94
.word spectrum_op_95
.word spectrum_op_96
.word spectrum_op_97
.word spectrum_op_98
.word spectrum_op_99
.word spectrum_op_9A
.word spectrum_op_9B
.word spectrum_op_9C
.word spectrum_op_9D
.word spectrum_op_9E
.word spectrum_op_9F
.word spectrum_op_A0
.word spectrum_op_A1
.word spectrum_op_A2
.word spectrum_op_A3
.word spectrum_op_A4
.word spectrum_op_A5
.word spectrum_op_A6
.word spectrum_op_A7
.word spectrum_op_A8
.word spectrum_op_A9
.word spectrum_op_AA
.word spectrum_op_AB
.word spectrum_op_AC
.word spectrum_op_AD
.word spectrum_op_AE
.word spectrum_op_AF
.word spectrum_op_B0
.word spectrum_op_B1
.word spectrum_op_B2
.word spectrum_op_B3
.word spectrum_op_B4
.word spectrum_op_B5
.word spectrum_op_B6
.word spectrum_op_B7
.word spectrum_op_B8
.word spectrum_op_B9
.word spectrum_op_BA
.word spectrum_op_BB
.word spectrum_op_BC
.word spectrum_op_BD
.word spectrum_op_BE
.word spectrum_op_BF
.word spectrum_op_C0
.word spectrum_op_C1
.word spectrum_op_C2
.word spectrum_op_C3
.word spectrum_op_C4
.word spectrum_op_C5
.word spectrum_op_C6
.word spectrum_op_C7
.word spectrum_op_C8
.word spectrum_op_C9
.word spectrum_op_CA
.word spectrum_op_CB
.word spectrum_op_CC
.word spectrum_op_CD
.word spectrum_op_CE
.word spectrum_op_CF
.word spectrum_op_D0
.word spectrum_op_D1
.word spectrum_op_D2
.word spectrum_op_D3
.word spectrum_op_D4
.word spectrum_op_D5
.word spectrum_op_D6
.word spectrum_op_D7
.word spectrum_op_D8
.word spectrum_op_D9
.word spectrum_op_DA
.word spectrum_op_DB
.word spectrum_op_DC
.word spectrum_op_DD
.word spectrum_op_DE
.word spectrum_op_DF
.word spectrum_op_E0
.word spectrum_op_E1
.word spectrum_op_E2
.word spectrum_op_E3
.word spectrum_op_E4
.word spectrum_op_E5
.word spectrum_op_E6
.word spectrum_op_E7
.word spectrum_op_E8
.word spectrum_op_E9
.word spectrum_op_EA
.word spectrum_op_EB
.word spectrum_op_EC
.word spectrum_op_ED
.word spectrum_op_EE
.word spectrum_op_EF
.word spectrum_op_F0
.word spectrum_op_F1
.word spectrum_op_F2
.word spectrum_op_F3
.word spectrum_op_F4
.word spectrum_op_F5
.word spectrum_op_F6
.word spectrum_op_F7
.word spectrum_op_F8
.word spectrum_op_F9
.word spectrum_op_FA
.word spectrum_op_FB
.word spectrum_op_FC
.word spectrum_op_FD
.word spectrum_op_FE
.word spectrum_op_FF

/*D:8005C52C*/
glabel jpt_8005C52C
.word spectrum_op_CB_00
.word spectrum_op_CB_01
.word spectrum_op_CB_02
.word spectrum_op_CB_03
.word spectrum_op_CB_04
.word spectrum_op_CB_05
.word spectrum_op_CB_06
.word spectrum_op_CB_07
.word spectrum_op_CB_08
.word spectrum_op_CB_09
.word spectrum_op_CB_0A
.word spectrum_op_CB_0B
.word spectrum_op_CB_0C
.word spectrum_op_CB_0D
.word spectrum_op_CB_0E
.word spectrum_op_CB_0F
.word spectrum_op_CB_10
.word spectrum_op_CB_11
.word spectrum_op_CB_12
.word spectrum_op_CB_13
.word spectrum_op_CB_14
.word spectrum_op_CB_15
.word spectrum_op_CB_16
.word spectrum_op_CB_17
.word spectrum_op_CB_18
.word spectrum_op_CB_19
.word spectrum_op_CB_1A
.word spectrum_op_CB_1B
.word spectrum_op_CB_1C
.word spectrum_op_CB_1D
.word spectrum_op_CB_1E
.word spectrum_op_CB_1F
.word spectrum_op_CB_20
.word spectrum_op_CB_21
.word spectrum_op_CB_22
.word spectrum_op_CB_23
.word spectrum_op_CB_24
.word spectrum_op_CB_25
.word spectrum_op_CB_26
.word spectrum_op_CB_27
.word spectrum_op_CB_28
.word spectrum_op_CB_29
.word spectrum_op_CB_2A
.word spectrum_op_CB_2B
.word spectrum_op_CB_2C
.word spectrum_op_CB_2D
.word spectrum_op_CB_2E
.word spectrum_op_CB_2F
.word spectrum_op_CB_30
.word spectrum_op_CB_31
.word spectrum_op_CB_32
.word spectrum_op_CB_33
.word spectrum_op_CB_34
.word spectrum_op_CB_35
.word spectrum_op_CB_36
.word spectrum_op_CB_37
.word spectrum_op_CB_38
.word spectrum_op_CB_39
.word spectrum_op_CB_3A
.word spectrum_op_CB_3B
.word spectrum_op_CB_3C
.word spectrum_op_CB_3D
.word spectrum_op_CB_3E
.word spectrum_op_CB_3F

/*D:8005C62C*/
glabel jpt_8005C62C
.word spectrum_op_SET_x_B
.word spectrum_op_SET_x_C
.word spectrum_op_SET_x_D
.word spectrum_op_SET_x_E
.word spectrum_op_SET_x_H
.word spectrum_op_SET_x_L
.word spectrum_op_SET_x_HL
.word spectrum_op_SET_x_A

/*D:8005C64C*/
glabel jpt_8005C64C
.word spectrum_op_RES_x_B
.word spectrum_op_RES_x_C
.word spectrum_op_RES_x_D
.word spectrum_op_RES_x_E
.word spectrum_op_RES_x_H
.word spectrum_op_RES_x_L
.word spectrum_op_RES_x_HL
.word spectrum_op_RES_x_A

/*D:8005C66C*/
glabel jpt_8005C66C
.word spectrum_op_BIT_x_B
.word spectrum_op_BIT_x_C
.word spectrum_op_BIT_x_D
.word spectrum_op_BIT_x_E
.word spectrum_op_BIT_x_H
.word spectrum_op_BIT_x_L
.word spectrum_op_BIT_x_HL
.word spectrum_op_BIT_x_A

/*D:8005C68C*/
glabel jpt_8005C68C
.word .L7F0DC5C4
.word .L7F0DC5CC
.word .L7F0DC5D4
.word .L7F0DC5DC
.word .L7F0DC5E4
.word .L7F0DC5EC
.word .L7F0E27FC
.word .L7F0DC5F4

/*D:8005C6AC*/
glabel jpt_8005C6AC
.word spectrum_op_ED_A0
.word spectrum_op_ED_A1
.word spectrum_op_ED_A2
.word spectrum_op_ED_A3
.word .L7F0E1A6C
.word .L7F0E1A6C
.word .L7F0E1A6C
.word .L7F0E1A6C
.word spectrum_op_ED_A8
.word spectrum_op_ED_A9
.word spectrum_op_ED_AA
.word spectrum_op_ED_AB
.word .L7F0E1A6C
.word .L7F0E1A6C
.word .L7F0E1A6C
.word .L7F0E1A6C
.word spectrum_op_ED_B0
.word spectrum_op_ED_B1
.word spectrum_op_ED_B2
.word spectrum_op_ED_B3
.word .L7F0E1A6C
.word .L7F0E1A6C
.word .L7F0E1A6C
.word .L7F0E1A6C
.word spectrum_op_ED_B8
.word spectrum_op_ED_B9
.word spectrum_op_ED_BA
.word spectrum_op_ED_BB

/*D:8005C71C*/
glabel jpt_8005C71C
.word spectrum_op_ED_40
.word spectrum_op_ED_41
.word spectrum_op_ED_42
.word spectrum_op_ED_43
.word spectrum_op_ED_44
.word spectrum_op_ED_45
.word spectrum_op_ED_46
.word spectrum_op_ED_47
.word spectrum_op_ED_48
.word spectrum_op_ED_49
.word spectrum_op_ED_4A
.word spectrum_op_ED_4B
.word spectrum_op_ED_4C
.word spectrum_op_ED_4D
.word spectrum_op_ED_4E
.word spectrum_op_ED_4F
.word spectrum_op_ED_50
.word spectrum_op_ED_51
.word spectrum_op_ED_52
.word spectrum_op_ED_53
.word spectrum_op_ED_54
.word spectrum_op_ED_55
.word spectrum_op_ED_56
.word spectrum_op_ED_57
.word spectrum_op_ED_58
.word spectrum_op_ED_59
.word spectrum_op_ED_5A
.word spectrum_op_ED_5B
.word spectrum_op_ED_5C
.word spectrum_op_ED_5D
.word spectrum_op_ED_5E
.word spectrum_op_ED_5F
.word spectrum_op_ED_60
.word spectrum_op_ED_61
.word spectrum_op_ED_62
.word spectrum_op_ED_63
.word spectrum_op_ED_64
.word spectrum_op_ED_65
.word spectrum_op_ED_66
.word spectrum_op_ED_67
.word spectrum_op_ED_68
.word spectrum_op_ED_69
.word spectrum_op_ED_6A
.word spectrum_op_ED_6B
.word spectrum_op_ED_6C
.word spectrum_op_ED_6D
.word spectrum_op_ED_6E
.word spectrum_op_ED_6F
.word spectrum_op_ED_70
.word spectrum_op_ED_71
.word spectrum_op_ED_72
.word spectrum_op_ED_73
.word spectrum_op_ED_74
.word spectrum_op_ED_75
.word spectrum_op_ED_76
.word .L7F0E1A6C
.word spectrum_op_ED_78
.word spectrum_op_ED_79
.word spectrum_op_ED_7A
.word spectrum_op_ED_7B
.word spectrum_op_ED_7C
.word spectrum_op_ED_7D
.word spectrum_op_ED_7E

.text
glabel spectrum_hw_emulation
  addiu $sp, $sp, -0x2b0
  lui   $t6, (0x00011100 >> 16) # lui $t6, 1
  ori   $t6, (0x00011100 & 0xFFFF) # ori $t6, $t6, 0x1100
  sw    $t6, 0x280($sp)
  lui   $t6, %hi(byte_CODE_bss_8008E341) 
  lbu   $t6, %lo(byte_CODE_bss_8008E341)($t6)
  lui   $t5, %hi(off_CODE_bss_8008E340) 
  lui   $t7, %hi(byte_CODE_bss_8008E342) 
  lui   $t8, %hi(byte_CODE_bss_8008E343) 
  lui   $t9, %hi(off_CODE_bss_8008E344) 
  lui   $t0, %hi(byte_CODE_bss_8008E345) 
  lui   $t1, %hi(byte_CODE_bss_8008E346) 
  lbu   $t5, %lo(off_CODE_bss_8008E340)($t5)
  lbu   $t7, %lo(byte_CODE_bss_8008E342)($t7)
  lbu   $t8, %lo(byte_CODE_bss_8008E343)($t8)
  lbu   $t9, %lo(off_CODE_bss_8008E344)($t9)
  lbu   $t0, %lo(byte_CODE_bss_8008E345)($t0)
  lbu   $t1, %lo(byte_CODE_bss_8008E346)($t1)
  sb    $zero, 0x2a5($sp)
  sb    $zero, 0x2a0($sp)
  sb    $zero, 0x2a1($sp)
  sb    $zero, 0x2a2($sp)
  sb    $zero, 0x2a3($sp)
  sb    $zero, 0x2a4($sp)
  sb    $zero, 0x2a6($sp)
  sb    $t6, 0x2a5($sp)
  lui   $t6, %hi(byte_CODE_bss_8008E349) 
  sb    $t5, 0x2a6($sp)
  sb    $t7, 0x2a4($sp)
  sb    $t8, 0x2a3($sp)
  sb    $t9, 0x2a2($sp)
  sb    $t0, 0x2a1($sp)
  sb    $t1, 0x2a0($sp)
  lbu   $t6, %lo(byte_CODE_bss_8008E349)($t6)
  lui   $t2, %hi(byte_CODE_bss_8008E347) 
  lui   $t3, %hi(spec_IFF2_lower) 
  lui   $t4, %hi(spec_IFF2_upper) 
  lui   $t5, %hi(spec_I) 
  lui   $t7, %hi(spec_IM) 
  lui   $t8, %hi(spec_IX) 
  lui   $t9, %hi(spec_IY) 
  lui   $t0, %hi(spec_SP) 
  lui   $t1, %hi(spec_PC) 
  lbu   $t2, %lo(byte_CODE_bss_8008E347)($t2)
  lbu   $t3, %lo(spec_IFF2_lower)($t3)
  lbu   $t4, %lo(spec_IFF2_upper)($t4)
  lbu   $t5, %lo(spec_I)($t5)
  lbu   $t7, %lo(spec_IM)($t7)
  lhu   $t8, %lo(spec_IX)($t8)
  lhu   $t9, %lo(spec_IY)($t9)
  lhu   $t0, %lo(spec_SP)($t0)
  lhu   $t1, %lo(spec_PC)($t1)
  sw    $s7, 0x30($sp)
  sw    $s6, 0x2c($sp)
  sw    $s5, 0x28($sp)
  sw    $s4, 0x24($sp)
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  lui   $at, (0x00011100 >> 16) # lui $at, 1
  sb    $zero, 0x29b($sp)
  sb    $zero, 0x29c($sp)
  sb    $zero, 0x29d($sp)
  sb    $zero, 0x2a7($sp)
  sb    $zero, 0x29e($sp)
  sb    $zero, 0x29f($sp)
  sh    $zero, 0x298($sp)
  sh    $zero, 0x292($sp)
  sh    $zero, 0x294($sp)
  sh    $zero, 0x296($sp)
  sw    $zero, 0x288($sp)
  lui   $s0, %hi(spectrum_header16_15)
  lui   $s1, %hi(byte_CODE_bss_8008E339)
  lui   $s2, %hi(byte_CODE_bss_8008E33A)
  lui   $s3, %hi(byte_CODE_bss_8008E33B)
  lui   $s4, %hi(off_CODE_bss_8008E33C)
  lui   $s5, %hi(byte_CODE_bss_8008E33D)
  lui   $s6, %hi(byte_CODE_bss_8008E33E)
  lui   $s7, %hi(byte_CODE_bss_8008E33F) 
  ori   $at, (0x00011100 & 0xFFFF) # ori $at, $at, 0x1100
  sw    $ra, 0x34($sp)
  sb    $zero, 0x286($sp)
  sb    $zero, 0x287($sp)
  sw    $zero, 0x28c($sp)
  lbu   $s0, %lo(spectrum_header16_15)($s0)
  lbu   $s1, %lo(byte_CODE_bss_8008E339)($s1)
  lbu   $s2, %lo(byte_CODE_bss_8008E33A)($s2)
  lbu   $s3, %lo(byte_CODE_bss_8008E33B)($s3)
  lbu   $s4, %lo(off_CODE_bss_8008E33C)($s4)
  lbu   $s5, %lo(byte_CODE_bss_8008E33D)($s5)
  lbu   $s6, %lo(byte_CODE_bss_8008E33E)($s6)
  lbu   $s7, %lo(byte_CODE_bss_8008E33F)($s7)
  sb    $t6, 0x2a7($sp)
  sw    $t6, 0x288($sp)
  sb    $t2, 0x29f($sp)
  sb    $t3, 0x29d($sp)
  sb    $t4, 0x29c($sp)
  sb    $t5, 0x29e($sp)
  sb    $t7, 0x29b($sp)
  sh    $t8, 0x296($sp)
  sh    $t9, 0x294($sp)
  sh    $t0, 0x292($sp)
  bnez  $at, .L7F0D39D8
   sh    $t1, 0x298($sp)
  lbu   $t3, 0x285($sp)
  bnez  $t3, .L7F0E281C
.L7F0D39D8:
   lui   $t7, %hi(ptr_spectrum_roms) 
  lbu   $t4, 0x286($sp)
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  lhu   $t6, 0x298($sp)
  li    $t5, 1
  sb    $zero, 0x286($sp)
  sb    $t5, 0x285($sp)
  sb    $t4, 0x287($sp)
  addu  $t8, $t6, $t7
  lbu   $t9, ($t8)
  lw    $t1, 0x288($sp)
  addiu $t0, $t6, 1
  andi  $t3, $t9, 0xff
  sltiu $at, $t3, 0x100
  addiu $t2, $t1, 1
  sh    $t0, 0x298($sp)
  sw    $t2, 0x288($sp)
  beqz  $at, .L7F0E27FC
   sb    $t9, 0x284($sp)
  sll   $t3, $t3, 2
  lui   $at, %hi(spectrum_op_table)
  addu  $at, $at, $t3
  lw    $t3, %lo(spectrum_op_table)($at)
  jr    $t3
   nop   
spectrum_op_00:
  lw    $t4, 0x28c($sp)
  addiu $t5, $t4, 4
  b     .L7F0E27FC
   sw    $t5, 0x28c($sp)
spectrum_op_01:
  lw    $t7, 0x28c($sp)
  lhu   $t9, 0x298($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  addiu $t8, $t7, 0xa
  sw    $t8, 0x28c($sp)
  addiu $t4, $t9, 1
  addu  $t0, $t9, $t6
  lbu   $s3, ($t0)
  andi  $t2, $t4, 0xffff
  sh    $t4, 0x298($sp)
  addu  $t3, $t2, $t6
  lbu   $s2, ($t3)
  addiu $t5, $t4, 1
  b     .L7F0E27FC
   sh    $t5, 0x298($sp)
spectrum_op_02:
  lw    $t7, 0x28c($sp)
  sll   $t0, $s2, 8
  or    $t9, $t0, $s3
  slti  $at, $t9, 0x5b00
  addiu $t8, $t7, 7
  bnez  $at, .L7F0D3AC4
   sw    $t8, 0x28c($sp)
  lui   $t2, %hi(ptr_spectrum_roms) 
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  sll   $t6, $s2, 8
  or    $t3, $t6, $s3
  addu  $t1, $t2, $t3
  b     .L7F0E27FC
   sb    $s0, ($t1)
.L7F0D3AC4:
  sll   $t4, $s2, 8
  or    $t5, $t4, $s3
  slti  $at, $t5, 0x5800
  bnez  $at, .L7F0D3B10
   sll   $t5, $s2, 8
  lui   $t7, %hi(ptr_spectrum_roms) 
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  sll   $t8, $s2, 8
  or    $t0, $t8, $s3
  addu  $t9, $t7, $t0
  sb    $s0, ($t9)
  lui   $t2, %hi(ptr_300alloc) 
  lw    $t2, %lo(ptr_300alloc)($t2)
  sll   $t3, $s2, 8
  or    $t1, $t3, $s3
  li    $t6, 1
  addu  $t4, $t2, $t1
  b     .L7F0E27FC
   sb    $t6, -0x5800($t4)
.L7F0D3B10:
  or    $t8, $t5, $s3
  slti  $at, $t8, 0x4000
  bnez  $at, .L7F0E27FC
   lui   $t7, %hi(ptr_spectrum_roms) 
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  sll   $t0, $s2, 8
  or    $t9, $t0, $s3
  addu  $t3, $t7, $t9
  sb    $s0, ($t3)
  sll   $t1, $s2, 8
  or    $t6, $t1, $s3
  lui   $t3, %hi(ptr_300alloc) 
  sll   $t8, $s2, 8
  lw    $t3, %lo(ptr_300alloc)($t3)
  or    $t0, $t8, $s3
  andi  $t4, $t6, 0x1800
  sra   $t5, $t4, 3
  andi  $t7, $t0, 0xff
  or    $t9, $t5, $t7
  li    $t2, 1
  addu  $t1, $t3, $t9
  b     .L7F0E27FC
   sb    $t2, ($t1)
spectrum_op_03:
  lw    $t6, 0x28c($sp)
  addiu $s3, $s3, 1
  andi  $t8, $s3, 0xff
  addiu $t4, $t6, 6
  sw    $t4, 0x28c($sp)
  bnez  $t8, .L7F0E27FC
   move  $s3, $t8
  addiu $s2, $s2, 1
  andi  $t0, $s2, 0xff
  b     .L7F0E27FC
   move  $s2, $t0
spectrum_op_04:
  addiu $s2, $s2, 1
  andi  $t3, $s2, 0xff
  lw    $t5, 0x28c($sp)
  andi  $t2, $t3, 0xf
  sltiu $t1, $t2, 1
  move  $s2, $t3
  sltiu $t9, $t3, 1
  andi  $t4, $t3, 0xa8
  andi  $t6, $s1, 1
  or    $t8, $t6, $t4
  xori  $t2, $s2, 0x80
  sll   $t0, $t1, 4
  addiu $t7, $t5, 4
  or    $t5, $t8, $t0
  sltiu $t2, $t2, 1
  sll   $t3, $t9, 6
  sw    $t9, 0x44($sp)
  or    $t9, $t5, $t3
  sll   $t6, $t2, 2
  or    $s1, $t9, $t6
  andi  $t4, $s1, 0xff
  sw    $t7, 0x28c($sp)
  move  $s1, $t4
  b     .L7F0E27FC
   sw    $t1, 0x48($sp)
spectrum_op_05:
  lw    $t1, 0x28c($sp)
  andi  $t0, $s2, 0xf
  addiu $s2, $s2, -1
  addiu $t8, $t1, 4
  sw    $t8, 0x28c($sp)
  andi  $t6, $s2, 0xff
  sltiu $t7, $t0, 1
  sll   $t3, $t7, 4
  xori  $t8, $t6, 0x7f
  sltiu $t8, $t8, 1
  andi  $t5, $s1, 1
  or    $s1, $t5, $t3
  sll   $t0, $t8, 2
  sw    $t7, 0x48($sp)
  sltiu $t4, $t6, 1
  andi  $t1, $t6, 0xa8
  or    $t7, $t1, $t0
  sll   $t3, $t4, 6
  or    $t2, $t7, $t3
  ori   $t9, $s1, 2
  or    $s1, $t9, $t2
  andi  $t9, $s1, 0xff
  move  $s1, $t9
  sw    $t4, 0x44($sp)
  b     .L7F0E27FC
   move  $s2, $t6
spectrum_op_06:
  lw    $t6, 0x28c($sp)
  lui   $t1, %hi(ptr_spectrum_roms) 
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  lhu   $t8, 0x298($sp)
  addiu $t4, $t6, 7
  sw    $t4, 0x28c($sp)
  addu  $t0, $t8, $t1
  lbu   $s2, ($t0)
  addiu $t5, $t8, 1
  b     .L7F0E27FC
   sh    $t5, 0x298($sp)
spectrum_op_07:
  sll   $t2, $s0, 1
  sra   $t9, $s0, 7
  or    $s0, $t2, $t9
  lw    $t7, 0x28c($sp)
  andi  $t6, $s0, 0xff
  andi  $t1, $t6, 0x29
  andi  $t4, $s1, 0xc4
  or    $s1, $t4, $t1
  andi  $t0, $s1, 0xff
  addiu $t3, $t7, 4
  sw    $t3, 0x28c($sp)
  move  $s0, $t6
  b     .L7F0E27FC
   move  $s1, $t0
spectrum_op_08:
  lw    $t8, 0x28c($sp)
  sb    $s0, 0x27f($sp)
  sb    $s1, 0x27e($sp)
  lbu   $t7, 0x27f($sp)
  lbu   $t3, 0x27e($sp)
  lbu   $s0, 0x2a6($sp)
  lbu   $s1, 0x2a5($sp)
  addiu $t5, $t8, 4
  sw    $t5, 0x28c($sp)
  sb    $t7, 0x2a6($sp)
  b     .L7F0E27FC
   sb    $t3, 0x2a5($sp)
spectrum_op_09:
  lw    $t2, 0x28c($sp)
  lbu   $t6, 0x287($sp)
  lbu   $t1, 0x287($sp)
  addiu $t9, $t2, 0xb
  bnez  $t6, .L7F0D3D7C
   sw    $t9, 0x28c($sp)
  addu  $t4, $s7, $s3
  andi  $t1, $t4, 0xffff
  srl   $t0, $t1, 8
  andi  $t5, $t0, 0xffff
  andi  $t8, $s6, 0xf
  addu  $t7, $t5, $t8
  andi  $t3, $s2, 0xf
  addu  $t2, $t7, $t3
  sh    $t4, 0x27c($sp)
  li    $at, 15
  slt   $t9, $at, $t2
  lbu   $s7, 0x27d($sp)
  addu  $t5, $s6, $s2
  addu  $t2, $t0, $t5
  sh    $t0, 0x27c($sp)
  sh    $t2, 0x27c($sp)
  lbu   $s6, 0x27d($sp)
  sll   $t6, $t9, 4
  andi  $t4, $s1, 0xc4
  or    $t1, $t6, $t4
  sra   $t9, $t2, 8
  andi  $t3, $s6, 0x28
  or    $t6, $t3, $t9
  or    $s1, $t1, $t6
  andi  $t4, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t4
.L7F0D3D7C:
  li    $at, 1
  bne   $t1, $at, .L7F0D3D94
   sll   $t2, $s2, 8
  lhu   $t0, 0x296($sp)
  b     .L7F0D3D9C
   sw    $t0, 0x278($sp)
.L7F0D3D94:
  lhu   $t8, 0x294($sp)
  sw    $t8, 0x278($sp)
.L7F0D3D9C:
  lw    $t5, 0x278($sp)
  or    $t3, $t2, $s3
  li    $at, 4095
  andi  $t7, $t5, 0xfff
  addu  $t9, $t7, $t3
  sltu  $t6, $at, $t9
  lbu   $t3, 0x287($sp)
  sll   $t4, $t6, 4
  andi  $t1, $s1, 0xc4
  sll   $t8, $s2, 8
  or    $t2, $t8, $s3
  or    $s1, $t1, $t4
  andi  $t0, $s1, 0xff
  li    $at, 1
  addu  $t7, $t5, $t2
  sw    $t7, 0x278($sp)
  bne   $t3, $at, .L7F0D3DEC
   move  $s1, $t0
  b     .L7F0D3DF4
   sh    $t7, 0x296($sp)
.L7F0D3DEC:
  lw    $t9, 0x278($sp)
  sh    $t9, 0x294($sp)
.L7F0D3DF4:
  lw    $t6, 0x278($sp)
  srl   $t1, $t6, 8
  andi  $t4, $t1, 0x28
  srl   $t0, $t6, 0x10
  or    $t8, $t4, $t0
  or    $s1, $s1, $t8
  andi  $t5, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t5
spectrum_op_0A:
  lw    $t2, 0x28c($sp)
  lui   $t1, %hi(ptr_spectrum_roms) 
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  sll   $t7, $s2, 8
  or    $t9, $t7, $s3
  addiu $t3, $t2, 7
  sw    $t3, 0x28c($sp)
  addu  $t6, $t9, $t1
  b     .L7F0E27FC
   lbu   $s0, ($t6)
spectrum_op_0B:
  lw    $t4, 0x28c($sp)
  sltiu $t8, $s3, 1
  addiu $s3, $s3, -1
  andi  $t5, $s3, 0xff
  addiu $t0, $t4, 6
  sw    $t0, 0x28c($sp)
  move  $s3, $t5
  beqz  $t8, .L7F0E27FC
   sw    $t8, 0x48($sp)
  addiu $s2, $s2, -1
  andi  $t3, $s2, 0xff
  b     .L7F0E27FC
   move  $s2, $t3
spectrum_op_0C:
  addiu $s3, $s3, 1
  andi  $t1, $s3, 0xff
  lw    $t7, 0x28c($sp)
  andi  $t4, $t1, 0xf
  sltiu $t0, $t4, 1
  move  $s3, $t1
  sltiu $t6, $t1, 1
  andi  $t5, $t1, 0xa8
  andi  $t8, $s1, 1
  or    $t2, $t8, $t5
  xori  $t4, $s3, 0x80
  sll   $t3, $t0, 4
  addiu $t9, $t7, 4
  or    $t7, $t2, $t3
  sltiu $t4, $t4, 1
  sll   $t1, $t6, 6
  sw    $t6, 0x44($sp)
  or    $t6, $t7, $t1
  sll   $t8, $t4, 2
  or    $s1, $t6, $t8
  andi  $t5, $s1, 0xff
  sw    $t9, 0x28c($sp)
  move  $s1, $t5
  b     .L7F0E27FC
   sw    $t0, 0x48($sp)
spectrum_op_0D:
  lw    $t0, 0x28c($sp)
  andi  $t3, $s3, 0xf
  addiu $s3, $s3, -1
  addiu $t2, $t0, 4
  sw    $t2, 0x28c($sp)
  andi  $t8, $s3, 0xff
  sltiu $t9, $t3, 1
  sll   $t1, $t9, 4
  xori  $t2, $t8, 0x7f
  sltiu $t2, $t2, 1
  andi  $t7, $s1, 1
  or    $s1, $t7, $t1
  sll   $t3, $t2, 2
  sw    $t9, 0x48($sp)
  sltiu $t5, $t8, 1
  andi  $t0, $t8, 0xa8
  or    $t9, $t0, $t3
  sll   $t1, $t5, 6
  or    $t4, $t9, $t1
  ori   $t6, $s1, 2
  or    $s1, $t6, $t4
  andi  $t6, $s1, 0xff
  move  $s1, $t6
  sw    $t5, 0x44($sp)
  b     .L7F0E27FC
   move  $s3, $t8
spectrum_op_0E:
  lw    $t8, 0x28c($sp)
  lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  lhu   $t2, 0x298($sp)
  addiu $t5, $t8, 7
  sw    $t5, 0x28c($sp)
  addu  $t3, $t2, $t0
  lbu   $s3, ($t3)
  addiu $t7, $t2, 1
  b     .L7F0E27FC
   sh    $t7, 0x298($sp)
spectrum_op_0F:
  andi  $t6, $s0, 1
  sra   $t5, $s0, 1
  sll   $t0, $s0, 7
  or    $s0, $t5, $t0
  lw    $t9, 0x28c($sp)
  andi  $t4, $s1, 0xc4
  andi  $t3, $s0, 0xff
  or    $t8, $t4, $t6
  andi  $t2, $t3, 0x28
  or    $s1, $t8, $t2
  andi  $t7, $s1, 0xff
  addiu $t1, $t9, 4
  sw    $t1, 0x28c($sp)
  move  $s0, $t3
  b     .L7F0E27FC
   move  $s1, $t7
spectrum_op_10:
  lw    $t9, 0x28c($sp)
  addiu $s2, $s2, -1
  andi  $t4, $s2, 0xff
  addiu $t1, $t9, 8
  sw    $t1, 0x28c($sp)
  bnez  $t4, .L7F0D3FD8
   move  $s2, $t4
  lhu   $t6, 0x298($sp)
  addiu $t8, $t6, 1
  b     .L7F0E27FC
   sh    $t8, 0x298($sp)
.L7F0D3FD8:
  lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  lhu   $t5, 0x298($sp)
  lw    $t1, 0x28c($sp)
  addu  $t3, $t5, $t0
  lb    $t2, ($t3)
  addiu $t4, $t1, 5
  sw    $t4, 0x28c($sp)
  addu  $t7, $t5, $t2
  addiu $t9, $t7, 1
  sh    $t9, 0x298($sp)
  b     .L7F0E27FC
   sw    $t2, 0x274($sp)
spectrum_op_11:
  lw    $t6, 0x28c($sp)
  lhu   $t0, 0x298($sp)
  lui   $t3, %hi(ptr_spectrum_roms) 
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  addiu $t8, $t6, 0xa
  sw    $t8, 0x28c($sp)
  addiu $t1, $t0, 1
  addu  $t5, $t0, $t3
  lbu   $s5, ($t5)
  andi  $t7, $t1, 0xffff
  sh    $t1, 0x298($sp)
  addu  $t9, $t7, $t3
  lbu   $s4, ($t9)
  addiu $t4, $t1, 1
  b     .L7F0E27FC
   sh    $t4, 0x298($sp)
spectrum_op_12:
  lw    $t6, 0x28c($sp)
  sll   $t5, $s4, 8
  or    $t0, $t5, $s5
  slti  $at, $t0, 0x5b00
  addiu $t8, $t6, 7
  bnez  $at, .L7F0D4084
   sw    $t8, 0x28c($sp)
  lui   $t7, %hi(ptr_spectrum_roms) 
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  sll   $t3, $s4, 8
  or    $t9, $t3, $s5
  addu  $t2, $t7, $t9
  b     .L7F0E27FC
   sb    $s0, ($t2)
.L7F0D4084:
  sll   $t1, $s4, 8
  or    $t4, $t1, $s5
  slti  $at, $t4, 0x5800
  bnez  $at, .L7F0D40D0
   sll   $t4, $s4, 8
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  sll   $t8, $s4, 8
  or    $t5, $t8, $s5
  addu  $t0, $t6, $t5
  sb    $s0, ($t0)
  lui   $t7, %hi(ptr_300alloc) 
  lw    $t7, %lo(ptr_300alloc)($t7)
  sll   $t9, $s4, 8
  or    $t2, $t9, $s5
  li    $t3, 1
  addu  $t1, $t7, $t2
  b     .L7F0E27FC
   sb    $t3, -0x5800($t1)
.L7F0D40D0:
  or    $t8, $t4, $s5
  slti  $at, $t8, 0x4000
  bnez  $at, .L7F0E27FC
   lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  sll   $t5, $s4, 8
  or    $t0, $t5, $s5
  addu  $t9, $t6, $t0
  sb    $s0, ($t9)
  sll   $t2, $s4, 8
  or    $t3, $t2, $s5
  lui   $t9, %hi(ptr_300alloc) 
  sll   $t8, $s4, 8
  lw    $t9, %lo(ptr_300alloc)($t9)
  or    $t5, $t8, $s5
  andi  $t1, $t3, 0x1800
  sra   $t4, $t1, 3
  andi  $t6, $t5, 0xff
  or    $t0, $t4, $t6
  li    $t7, 1
  addu  $t2, $t9, $t0
  b     .L7F0E27FC
   sb    $t7, ($t2)
spectrum_op_13:
  lw    $t3, 0x28c($sp)
  addiu $s5, $s5, 1
  andi  $t8, $s5, 0xff
  addiu $t1, $t3, 6
  sw    $t1, 0x28c($sp)
  bnez  $t8, .L7F0E27FC
   move  $s5, $t8
  addiu $s4, $s4, 1
  andi  $t5, $s4, 0xff
  b     .L7F0E27FC
   move  $s4, $t5
spectrum_op_14:
  addiu $s4, $s4, 1
  andi  $t9, $s4, 0xff
  lw    $t4, 0x28c($sp)
  andi  $t7, $t9, 0xf
  sltiu $t2, $t7, 1
  move  $s4, $t9
  sltiu $t0, $t9, 1
  andi  $t1, $t9, 0xa8
  andi  $t3, $s1, 1
  or    $t8, $t3, $t1
  xori  $t7, $s4, 0x80
  sll   $t5, $t2, 4
  addiu $t6, $t4, 4
  or    $t4, $t8, $t5
  sltiu $t7, $t7, 1
  sll   $t9, $t0, 6
  sw    $t0, 0x44($sp)
  or    $t0, $t4, $t9
  sll   $t3, $t7, 2
  or    $s1, $t0, $t3
  andi  $t1, $s1, 0xff
  sw    $t6, 0x28c($sp)
  move  $s1, $t1
  b     .L7F0E27FC
   sw    $t2, 0x48($sp)
spectrum_op_15:
  lw    $t2, 0x28c($sp)
  andi  $t5, $s4, 0xf
  addiu $s4, $s4, -1
  addiu $t8, $t2, 4
  sw    $t8, 0x28c($sp)
  andi  $t3, $s4, 0xff
  sltiu $t6, $t5, 1
  sll   $t9, $t6, 4
  xori  $t8, $t3, 0x7f
  sltiu $t8, $t8, 1
  andi  $t4, $s1, 1
  or    $s1, $t4, $t9
  sll   $t5, $t8, 2
  sw    $t6, 0x48($sp)
  sltiu $t1, $t3, 1
  andi  $t2, $t3, 0xa8
  or    $t6, $t2, $t5
  sll   $t9, $t1, 6
  or    $t7, $t6, $t9
  ori   $t0, $s1, 2
  or    $s1, $t0, $t7
  andi  $t0, $s1, 0xff
  move  $s1, $t0
  sw    $t1, 0x44($sp)
  b     .L7F0E27FC
   move  $s4, $t3
spectrum_op_16:
  lw    $t3, 0x28c($sp)
  lui   $t2, %hi(ptr_spectrum_roms) 
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  lhu   $t8, 0x298($sp)
  addiu $t1, $t3, 7
  sw    $t1, 0x28c($sp)
  addu  $t5, $t8, $t2
  lbu   $s4, ($t5)
  addiu $t4, $t8, 1
  b     .L7F0E27FC
   sh    $t4, 0x298($sp)
spectrum_op_17:
  sra   $t7, $s0, 7
  sll   $t0, $s0, 1
  andi  $t3, $s1, 1
  or    $s0, $t0, $t3
  lw    $t6, 0x28c($sp)
  andi  $t1, $s0, 0xff
  andi  $t5, $t1, 0x28
  andi  $t2, $s1, 0xc4
  or    $t8, $t2, $t5
  or    $s1, $t8, $t7
  addiu $t9, $t6, 4
  andi  $t6, $s1, 0xff
  sw    $t9, 0x28c($sp)
  sw    $t7, 0x270($sp)
  move  $s0, $t1
  b     .L7F0E27FC
   move  $s1, $t6
spectrum_op_18:
  lw    $t9, 0x28c($sp)
  lui   $t3, %hi(ptr_spectrum_roms) 
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  lhu   $t0, 0x298($sp)
  addiu $t7, $t9, 7
  sw    $t7, 0x28c($sp)
  addu  $t1, $t0, $t3
  lb    $t2, ($t1)
  addiu $t6, $t7, 5
  sw    $t6, 0x28c($sp)
  addu  $t5, $t0, $t2
  addiu $t8, $t5, 1
  sh    $t8, 0x298($sp)
  b     .L7F0E27FC
   sw    $t2, 0x26c($sp)
spectrum_op_19:
  lw    $t9, 0x28c($sp)
  lbu   $t3, 0x287($sp)
  lbu   $t0, 0x287($sp)
  addiu $t7, $t9, 0xb
  bnez  $t3, .L7F0D4354
   sw    $t7, 0x28c($sp)
  addu  $t1, $s7, $s5
  andi  $t0, $t1, 0xffff
  srl   $t2, $t0, 8
  andi  $t8, $t2, 0xffff
  andi  $t5, $s6, 0xf
  addu  $t4, $t8, $t5
  andi  $t6, $s4, 0xf
  addu  $t9, $t4, $t6
  sh    $t1, 0x26a($sp)
  li    $at, 15
  slt   $t7, $at, $t9
  lbu   $s7, 0x26b($sp)
  addu  $t8, $s6, $s4
  addu  $t9, $t2, $t8
  sh    $t2, 0x26a($sp)
  sh    $t9, 0x26a($sp)
  lbu   $s6, 0x26b($sp)
  sll   $t3, $t7, 4
  andi  $t1, $s1, 0xc4
  or    $t0, $t3, $t1
  sra   $t7, $t9, 8
  andi  $t6, $s6, 0x28
  or    $t3, $t6, $t7
  or    $s1, $t0, $t3
  andi  $t1, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t1
.L7F0D4354:
  li    $at, 1
  bne   $t0, $at, .L7F0D436C
   sll   $t9, $s4, 8
  lhu   $t2, 0x296($sp)
  b     .L7F0D4374
   sw    $t2, 0x264($sp)
.L7F0D436C:
  lhu   $t5, 0x294($sp)
  sw    $t5, 0x264($sp)
.L7F0D4374:
  lw    $t8, 0x264($sp)
  or    $t6, $t9, $s5
  li    $at, 4095
  andi  $t4, $t8, 0xfff
  addu  $t7, $t4, $t6
  sltu  $t3, $at, $t7
  lbu   $t6, 0x287($sp)
  sll   $t1, $t3, 4
  andi  $t0, $s1, 0xc4
  sll   $t5, $s4, 8
  or    $t9, $t5, $s5
  or    $s1, $t0, $t1
  andi  $t2, $s1, 0xff
  li    $at, 1
  addu  $t4, $t8, $t9
  sw    $t4, 0x264($sp)
  bne   $t6, $at, .L7F0D43C4
   move  $s1, $t2
  b     .L7F0D43CC
   sh    $t4, 0x296($sp)
.L7F0D43C4:
  lw    $t7, 0x264($sp)
  sh    $t7, 0x294($sp)
.L7F0D43CC:
  lw    $t3, 0x264($sp)
  srl   $t0, $t3, 8
  andi  $t1, $t0, 0x28
  srl   $t2, $t3, 0x10
  or    $t5, $t1, $t2
  or    $s1, $s1, $t5
  andi  $t8, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t8
spectrum_op_1A:
  lw    $t9, 0x28c($sp)
  lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  sll   $t4, $s4, 8
  or    $t7, $t4, $s5
  addiu $t6, $t9, 7
  sw    $t6, 0x28c($sp)
  addu  $t3, $t7, $t0
  b     .L7F0E27FC
   lbu   $s0, ($t3)
spectrum_op_1B:
  lw    $t1, 0x28c($sp)
  sltiu $t5, $s5, 1
  addiu $s5, $s5, -1
  andi  $t8, $s5, 0xff
  addiu $t2, $t1, 6
  sw    $t2, 0x28c($sp)
  move  $s5, $t8
  beqz  $t5, .L7F0E27FC
   sw    $t5, 0x48($sp)
  addiu $s4, $s4, -1
  andi  $t6, $s4, 0xff
  b     .L7F0E27FC
   move  $s4, $t6
spectrum_op_1C:
  addiu $s5, $s5, 1
  andi  $t0, $s5, 0xff
  lw    $t4, 0x28c($sp)
  andi  $t1, $t0, 0xf
  sltiu $t2, $t1, 1
  move  $s5, $t0
  sltiu $t3, $t0, 1
  andi  $t8, $t0, 0xa8
  andi  $t5, $s1, 1
  or    $t9, $t5, $t8
  xori  $t1, $s5, 0x80
  sll   $t6, $t2, 4
  addiu $t7, $t4, 4
  or    $t4, $t9, $t6
  sltiu $t1, $t1, 1
  sll   $t0, $t3, 6
  sw    $t3, 0x44($sp)
  or    $t3, $t4, $t0
  sll   $t5, $t1, 2
  or    $s1, $t3, $t5
  andi  $t8, $s1, 0xff
  sw    $t7, 0x28c($sp)
  move  $s1, $t8
  b     .L7F0E27FC
   sw    $t2, 0x48($sp)
spectrum_op_1D:
  lw    $t2, 0x28c($sp)
  andi  $t6, $s5, 0xf
  addiu $s5, $s5, -1
  addiu $t9, $t2, 4
  sw    $t9, 0x28c($sp)
  andi  $t5, $s5, 0xff
  sltiu $t7, $t6, 1
  sll   $t0, $t7, 4
  xori  $t9, $t5, 0x7f
  sltiu $t9, $t9, 1
  andi  $t4, $s1, 1
  or    $s1, $t4, $t0
  sll   $t6, $t9, 2
  sw    $t7, 0x48($sp)
  sltiu $t8, $t5, 1
  andi  $t2, $t5, 0xa8
  or    $t7, $t2, $t6
  sll   $t0, $t8, 6
  or    $t1, $t7, $t0
  ori   $t3, $s1, 2
  or    $s1, $t3, $t1
  andi  $t3, $s1, 0xff
  move  $s1, $t3
  sw    $t8, 0x44($sp)
  b     .L7F0E27FC
   move  $s5, $t5
spectrum_op_1E:
  lw    $t5, 0x28c($sp)
  lui   $t2, %hi(ptr_spectrum_roms) 
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  lhu   $t9, 0x298($sp)
  addiu $t8, $t5, 7
  sw    $t8, 0x28c($sp)
  addu  $t6, $t9, $t2
  lbu   $s5, ($t6)
  addiu $t4, $t9, 1
  b     .L7F0E27FC
   sh    $t4, 0x298($sp)
spectrum_op_1F:
  andi  $t1, $s0, 1
  sra   $t3, $s0, 1
  sll   $t5, $s1, 7
  or    $s0, $t3, $t5
  lw    $t7, 0x28c($sp)
  andi  $t8, $s0, 0xff
  andi  $t6, $t8, 0x28
  andi  $t2, $s1, 0xc4
  or    $t9, $t2, $t6
  or    $s1, $t9, $t1
  addiu $t0, $t7, 4
  andi  $t7, $s1, 0xff
  sw    $t0, 0x28c($sp)
  sw    $t1, 0x260($sp)
  move  $s0, $t8
  b     .L7F0E27FC
   move  $s1, $t7
spectrum_op_20:
  lw    $t0, 0x28c($sp)
  andi  $t3, $s1, 0x40
  lhu   $t2, 0x298($sp)
  addiu $t1, $t0, 7
  beqz  $t3, .L7F0D45B0
   sw    $t1, 0x28c($sp)
  lhu   $t5, 0x298($sp)
  addiu $t8, $t5, 1
  b     .L7F0E27FC
   sh    $t8, 0x298($sp)
.L7F0D45B0:
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  lw    $t1, 0x28c($sp)
  addu  $t9, $t2, $t6
  lb    $t4, ($t9)
  addiu $t3, $t1, 5
  sw    $t3, 0x28c($sp)
  addu  $t7, $t2, $t4
  addiu $t0, $t7, 1
  sh    $t0, 0x298($sp)
  b     .L7F0E27FC
   sw    $t4, 0x25c($sp)
spectrum_op_21:
  lw    $t5, 0x28c($sp)
  lbu   $t6, 0x287($sp)
  lhu   $t9, 0x298($sp)
  addiu $t8, $t5, 0xa
  bnez  $t6, .L7F0D4628
   sw    $t8, 0x28c($sp)
  lui   $t2, %hi(ptr_spectrum_roms) 
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  addiu $t3, $t9, 1
  andi  $t0, $t3, 0xffff
  addu  $t4, $t9, $t2
  lbu   $s7, ($t4)
  sh    $t3, 0x298($sp)
  addu  $t1, $t0, $t2
  lbu   $s6, ($t1)
  addiu $t5, $t3, 1
  b     .L7F0E27FC
   sh    $t5, 0x298($sp)
.L7F0D4628:
  lbu   $t8, 0x287($sp)
  li    $at, 1
  lhu   $t6, 0x298($sp)
  bne   $t8, $at, .L7F0D4664
   lhu   $t5, 0x298($sp)
  lui   $t4, %hi(ptr_spectrum_roms) 
  lw    $t4, %lo(ptr_spectrum_roms)($t4)
  addu  $t2, $t4, $t6
  lbu   $t1, 1($t2)
  addu  $t9, $t6, $t4
  lbu   $t0, ($t9)
  sll   $t7, $t1, 8
  or    $t3, $t0, $t7
  b     .L7F0D4688
   sh    $t3, 0x296($sp)
.L7F0D4664:
  lui   $t8, %hi(ptr_spectrum_roms) 
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  addu  $t6, $t8, $t5
  lbu   $t2, 1($t6)
  addu  $t9, $t5, $t8
  lbu   $t4, ($t9)
  sll   $t1, $t2, 8
  or    $t0, $t4, $t1
  sh    $t0, 0x294($sp)
.L7F0D4688:
  lhu   $t7, 0x298($sp)
  addiu $t3, $t7, 2
  b     .L7F0E27FC
   sh    $t3, 0x298($sp)
spectrum_op_22:
  lw    $t9, 0x28c($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  lhu   $t5, 0x298($sp)
  addiu $t8, $t9, 0x10
  sw    $t8, 0x28c($sp)
  addu  $t1, $t6, $t5
  lbu   $t0, 1($t1)
  addu  $t2, $t5, $t6
  lbu   $t4, ($t2)
  lbu   $t8, 0x287($sp)
  sll   $t7, $t0, 8
  addiu $t9, $t5, 2
  or    $t3, $t4, $t7
  sh    $t3, 0x25a($sp)
  bnez  $t8, .L7F0D4828
   sh    $t9, 0x298($sp)
  andi  $t2, $t3, 0xffff
  slti  $at, $t2, 0x5b00
  bnez  $at, .L7F0D4700
   lhu   $t0, 0x25a($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  addu  $t1, $t6, $t2
  b     .L7F0D4778
   sb    $s7, ($t1)
.L7F0D4700:
  slti  $at, $t0, 0x5800
  bnez  $at, .L7F0D4738
   lhu   $t6, 0x25a($sp)
  lui   $t4, %hi(ptr_spectrum_roms) 
  lw    $t4, %lo(ptr_spectrum_roms)($t4)
  lui   $t5, %hi(ptr_300alloc) 
  li    $t3, 1
  addu  $t7, $t4, $t0
  sb    $s7, ($t7)
  lhu   $t9, 0x25a($sp)
  lw    $t5, %lo(ptr_300alloc)($t5)
  addu  $t8, $t5, $t9
  b     .L7F0D4778
   sb    $t3, -0x5800($t8)
.L7F0D4738:
  slti  $at, $t6, 0x4000
  bnez  $at, .L7F0D4778
   lui   $t2, %hi(ptr_spectrum_roms) 
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  lui   $t8, %hi(ptr_300alloc) 
  li    $t4, 1
  addu  $t1, $t2, $t6
  sb    $s7, ($t1)
  lhu   $t0, 0x25a($sp)
  lw    $t8, %lo(ptr_300alloc)($t8)
  andi  $t7, $t0, 0x1800
  sra   $t5, $t7, 3
  andi  $t9, $t0, 0xff
  or    $t3, $t5, $t9
  addu  $t2, $t8, $t3
  sb    $t4, ($t2)
.L7F0D4778:
  lhu   $t6, 0x25a($sp)
  lhu   $t5, 0x25a($sp)
  lui   $t7, %hi(ptr_spectrum_roms) 
  addiu $t1, $t6, 1
  slti  $at, $t1, 0x5b00
  bnez  $at, .L7F0D47A4
   addiu $t9, $t5, 1
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  addu  $t0, $t7, $t6
  b     .L7F0E27FC
   sb    $s6, 1($t0)
.L7F0D47A4:
  slti  $at, $t9, 0x5800
  bnez  $at, .L7F0D47DC
   lhu   $t6, 0x25a($sp)
  lui   $t8, %hi(ptr_spectrum_roms) 
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  lui   $t2, %hi(ptr_300alloc) 
  li    $t4, 1
  addu  $t3, $t8, $t5
  sb    $s6, 1($t3)
  lhu   $t1, 0x25a($sp)
  lw    $t2, %lo(ptr_300alloc)($t2)
  addu  $t7, $t2, $t1
  b     .L7F0E27FC
   sb    $t4, -0x57ff($t7)
.L7F0D47DC:
  addiu $t0, $t6, 1
  slti  $at, $t0, 0x4000
  bnez  $at, .L7F0E27FC
   lui   $t9, %hi(ptr_spectrum_roms) 
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  li    $t5, 1
  addu  $t8, $t9, $t6
  sb    $s6, 1($t8)
  lhu   $t3, 0x25a($sp)
  lui   $t9, %hi(ptr_300alloc) 
  lw    $t9, %lo(ptr_300alloc)($t9)
  addiu $t2, $t3, 1
  andi  $t1, $t2, 0x1800
  sra   $t4, $t1, 3
  andi  $t7, $t2, 0xff
  or    $t0, $t4, $t7
  addu  $t6, $t9, $t0
  b     .L7F0E27FC
   sb    $t5, ($t6)
.L7F0D4828:
  lbu   $t8, 0x287($sp)
  li    $at, 1
  lhu   $t3, 0x25a($sp)
  bne   $t8, $at, .L7F0D49A4
   slti  $at, $t3, 0x5b00
  bnez  $at, .L7F0D485C
   lhu   $t7, 0x25a($sp)
  lui   $t2, %hi(ptr_spectrum_roms) 
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  lhu   $t1, 0x296($sp)
  addu  $t4, $t2, $t3
  b     .L7F0D48DC
   sb    $t1, ($t4)
.L7F0D485C:
  slti  $at, $t7, 0x5800
  bnez  $at, .L7F0D4898
   lhu   $t1, 0x25a($sp)
  lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  lhu   $t9, 0x296($sp)
  lui   $t8, %hi(ptr_300alloc) 
  addu  $t5, $t0, $t7
  sb    $t9, ($t5)
  lhu   $t2, 0x25a($sp)
  lw    $t8, %lo(ptr_300alloc)($t8)
  li    $t6, 1
  addu  $t3, $t8, $t2
  b     .L7F0D48DC
   sb    $t6, -0x5800($t3)
.L7F0D4898:
  slti  $at, $t1, 0x4000
  bnez  $at, .L7F0D48DC
   lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  lhu   $t4, 0x296($sp)
  li    $t9, 1
  addu  $t7, $t0, $t1
  sb    $t4, ($t7)
  lhu   $t5, 0x25a($sp)
  lui   $t0, %hi(ptr_300alloc) 
  lw    $t0, %lo(ptr_300alloc)($t0)
  andi  $t8, $t5, 0x1800
  sra   $t2, $t8, 3
  andi  $t6, $t5, 0xff
  or    $t3, $t2, $t6
  addu  $t1, $t0, $t3
  sb    $t9, ($t1)
.L7F0D48DC:
  lhu   $t4, 0x25a($sp)
  lhu   $t0, 0x25a($sp)
  lhu   $t8, 0x296($sp)
  addiu $t7, $t4, 1
  slti  $at, $t7, 0x5b00
  bnez  $at, .L7F0D4910
   addiu $t3, $t0, 1
  lui   $t2, %hi(ptr_spectrum_roms) 
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  sra   $t5, $t8, 8
  addu  $t6, $t2, $t4
  b     .L7F0E27FC
   sb    $t5, 1($t6)
.L7F0D4910:
  slti  $at, $t3, 0x5800
  bnez  $at, .L7F0D4950
   lhu   $t3, 0x25a($sp)
  lui   $t7, %hi(ptr_spectrum_roms) 
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  lhu   $t9, 0x296($sp)
  lui   $t4, %hi(ptr_300alloc) 
  addu  $t8, $t7, $t0
  sra   $t1, $t9, 8
  sb    $t1, 1($t8)
  lhu   $t5, 0x25a($sp)
  lw    $t4, %lo(ptr_300alloc)($t4)
  li    $t2, 1
  addu  $t6, $t4, $t5
  b     .L7F0E27FC
   sb    $t2, -0x57ff($t6)
.L7F0D4950:
  addiu $t9, $t3, 1
  slti  $at, $t9, 0x4000
  bnez  $at, .L7F0E27FC
   lhu   $t7, 0x296($sp)
  lui   $t1, %hi(ptr_spectrum_roms) 
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  sra   $t0, $t7, 8
  li    $t4, 1
  addu  $t8, $t1, $t3
  sb    $t0, 1($t8)
  lhu   $t5, 0x25a($sp)
  lui   $t3, %hi(ptr_300alloc) 
  lw    $t3, %lo(ptr_300alloc)($t3)
  addiu $t2, $t5, 1
  andi  $t6, $t2, 0x1800
  sra   $t9, $t6, 3
  andi  $t7, $t2, 0xff
  or    $t1, $t9, $t7
  addu  $t0, $t3, $t1
  b     .L7F0E27FC
   sb    $t4, ($t0)
.L7F0D49A4:
  lhu   $t8, 0x25a($sp)
  lhu   $t9, 0x25a($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  slti  $at, $t8, 0x5b00
  bnezl $at, .L7F0D49D4
   slti  $at, $t9, 0x5800
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  lhu   $t5, 0x294($sp)
  addu  $t2, $t6, $t8
  b     .L7F0D4A50
   sb    $t5, ($t2)
  slti  $at, $t9, 0x5800
.L7F0D49D4:
  bnez  $at, .L7F0D4A0C
   lhu   $t5, 0x25a($sp)
  lui   $t3, %hi(ptr_spectrum_roms) 
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  lhu   $t7, 0x294($sp)
  lui   $t0, %hi(ptr_300alloc) 
  addu  $t1, $t3, $t9
  sb    $t7, ($t1)
  lhu   $t6, 0x25a($sp)
  lw    $t0, %lo(ptr_300alloc)($t0)
  li    $t4, 1
  addu  $t8, $t0, $t6
  b     .L7F0D4A50
   sb    $t4, -0x5800($t8)
.L7F0D4A0C:
  slti  $at, $t5, 0x4000
  bnez  $at, .L7F0D4A50
   lui   $t3, %hi(ptr_spectrum_roms) 
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  lhu   $t2, 0x294($sp)
  li    $t7, 1
  addu  $t9, $t3, $t5
  sb    $t2, ($t9)
  lhu   $t1, 0x25a($sp)
  lui   $t3, %hi(ptr_300alloc) 
  lw    $t3, %lo(ptr_300alloc)($t3)
  andi  $t0, $t1, 0x1800
  sra   $t6, $t0, 3
  andi  $t4, $t1, 0xff
  or    $t8, $t6, $t4
  addu  $t5, $t3, $t8
  sb    $t7, ($t5)
.L7F0D4A50:
  lhu   $t2, 0x25a($sp)
  lhu   $t3, 0x25a($sp)
  lhu   $t0, 0x294($sp)
  addiu $t9, $t2, 1
  slti  $at, $t9, 0x5b00
  bnez  $at, .L7F0D4A84
   addiu $t8, $t3, 1
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  sra   $t1, $t0, 8
  addu  $t4, $t6, $t2
  b     .L7F0E27FC
   sb    $t1, 1($t4)
.L7F0D4A84:
  slti  $at, $t8, 0x5800
  bnez  $at, .L7F0D4AC4
   lhu   $t8, 0x25a($sp)
  lui   $t9, %hi(ptr_spectrum_roms) 
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  lhu   $t7, 0x294($sp)
  lui   $t2, %hi(ptr_300alloc) 
  addu  $t0, $t9, $t3
  sra   $t5, $t7, 8
  sb    $t5, 1($t0)
  lhu   $t1, 0x25a($sp)
  lw    $t2, %lo(ptr_300alloc)($t2)
  li    $t6, 1
  addu  $t4, $t2, $t1
  b     .L7F0E27FC
   sb    $t6, -0x57ff($t4)
.L7F0D4AC4:
  addiu $t7, $t8, 1
  slti  $at, $t7, 0x4000
  bnez  $at, .L7F0E27FC
   lhu   $t9, 0x294($sp)
  lui   $t5, %hi(ptr_spectrum_roms) 
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  sra   $t3, $t9, 8
  li    $t2, 1
  addu  $t0, $t5, $t8
  sb    $t3, 1($t0)
  lhu   $t1, 0x25a($sp)
  lui   $t8, %hi(ptr_300alloc) 
  lw    $t8, %lo(ptr_300alloc)($t8)
  addiu $t6, $t1, 1
  andi  $t4, $t6, 0x1800
  sra   $t7, $t4, 3
  andi  $t9, $t6, 0xff
  or    $t5, $t7, $t9
  addu  $t3, $t8, $t5
  b     .L7F0E27FC
   sb    $t2, ($t3)
spectrum_op_23:
  lw    $t0, 0x28c($sp)
  lbu   $t4, 0x287($sp)
  lbu   $t9, 0x287($sp)
  addiu $t1, $t0, 6
  bnez  $t4, .L7F0D4B50
   sw    $t1, 0x28c($sp)
  addiu $s7, $s7, 1
  andi  $t6, $s7, 0xff
  bnez  $t6, .L7F0E27FC
   move  $s7, $t6
  addiu $s6, $s6, 1
  andi  $t7, $s6, 0xff
  b     .L7F0E27FC
   move  $s6, $t7
.L7F0D4B50:
  li    $at, 1
  bne   $t9, $at, .L7F0D4B6C
   lhu   $t2, 0x294($sp)
  lhu   $t8, 0x296($sp)
  addiu $t5, $t8, 1
  b     .L7F0E27FC
   sh    $t5, 0x296($sp)
.L7F0D4B6C:
  addiu $t3, $t2, 1
  b     .L7F0E27FC
   sh    $t3, 0x294($sp)
spectrum_op_24:
  lw    $t0, 0x28c($sp)
  lbu   $t4, 0x287($sp)
  lbu   $t8, 0x287($sp)
  addiu $t1, $t0, 4
  bnez  $t4, .L7F0D4BE8
   sw    $t1, 0x28c($sp)
  addiu $s6, $s6, 1
  andi  $t6, $s6, 0xff
  andi  $t9, $t6, 0xf
  sltiu $t8, $t9, 1
  move  $s6, $t6
  sltiu $t7, $t6, 1
  andi  $t2, $t6, 0xa8
  andi  $t5, $s1, 1
  or    $t3, $t5, $t2
  xori  $t9, $s6, 0x80
  sll   $t0, $t8, 4
  or    $t1, $t3, $t0
  sltiu $t9, $t9, 1
  sll   $t6, $t7, 6
  sw    $t7, 0x44($sp)
  or    $t7, $t1, $t6
  sll   $t5, $t9, 2
  or    $s1, $t7, $t5
  andi  $t2, $s1, 0xff
  move  $s1, $t2
  b     .L7F0E27FC
   sw    $t8, 0x48($sp)
.L7F0D4BE8:
  li    $at, 1
  bne   $t8, $at, .L7F0D4C00
   lhu   $t0, 0x294($sp)
  lhu   $t3, 0x296($sp)
  b     .L7F0D4C04
   sw    $t3, 0x48($sp)
.L7F0D4C00:
  sw    $t0, 0x48($sp)
.L7F0D4C04:
  lw    $t4, 0x48($sp)
  andi  $t0, $s1, 1
  li    $at, 1
  sra   $t6, $t4, 8
  addiu $t2, $t6, 1
  andi  $t7, $t2, 0xff
  sltiu $t5, $t7, 1
  andi  $t4, $t2, 0xff
  sb    $t6, 0x259($sp)
  andi  $t1, $t4, 0xa8
  sw    $t5, 0x44($sp)
  andi  $t8, $t2, 0xf
  lw    $t9, 0x44($sp)
  sltiu $t3, $t8, 1
  or    $t6, $t0, $t1
  sll   $t7, $t3, 4
  or    $t5, $t6, $t7
  xori  $t0, $t4, 0x80
  sb    $t2, 0x259($sp)
  sltiu $t0, $t0, 1
  sll   $t2, $t9, 6
  lbu   $t6, 0x287($sp)
  or    $t8, $t5, $t2
  sll   $t1, $t0, 2
  or    $s1, $t8, $t1
  sw    $t3, 0x48($sp)
  andi  $t3, $s1, 0xff
  bne   $t6, $at, .L7F0D4C90
   move  $s1, $t3
  lhu   $t7, 0x296($sp)
  sll   $t5, $t4, 8
  andi  $t9, $t7, 0xff
  or    $t2, $t9, $t5
  b     .L7F0E27FC
   sh    $t2, 0x296($sp)
.L7F0D4C90:
  lhu   $t0, 0x294($sp)
  lbu   $t1, 0x259($sp)
  andi  $t8, $t0, 0xff
  sll   $t3, $t1, 8
  or    $t6, $t8, $t3
  b     .L7F0E27FC
   sh    $t6, 0x294($sp)
spectrum_op_25:
  lw    $t7, 0x28c($sp)
  lbu   $t9, 0x287($sp)
  lbu   $t6, 0x287($sp)
  addiu $t4, $t7, 4
  bnez  $t9, .L7F0D4D20
   sw    $t4, 0x28c($sp)
  andi  $t5, $s6, 0xf
  addiu $s6, $s6, -1
  andi  $t6, $s6, 0xff
  sltiu $t2, $t5, 1
  sll   $t1, $t2, 4
  xori  $t9, $t6, 0x7f
  sltiu $t9, $t9, 1
  andi  $t0, $s1, 1
  or    $s1, $t0, $t1
  sll   $t5, $t9, 2
  sw    $t2, 0x48($sp)
  sltiu $t7, $t6, 1
  andi  $t4, $t6, 0xa8
  or    $t2, $t4, $t5
  sll   $t1, $t7, 6
  or    $t8, $t2, $t1
  ori   $t3, $s1, 2
  or    $s1, $t3, $t8
  andi  $t3, $s1, 0xff
  move  $s1, $t3
  sw    $t7, 0x44($sp)
  b     .L7F0E27FC
   move  $s6, $t6
.L7F0D4D20:
  li    $at, 1
  bne   $t6, $at, .L7F0D4D38
   lhu   $t9, 0x294($sp)
  lhu   $t7, 0x296($sp)
  b     .L7F0D4D3C
   sw    $t7, 0x48($sp)
.L7F0D4D38:
  sw    $t9, 0x48($sp)
.L7F0D4D3C:
  lw    $t4, 0x48($sp)
  andi  $t8, $s1, 1
  li    $at, 1
  sra   $t0, $t4, 8
  andi  $t2, $t0, 0xf
  sltiu $t1, $t2, 1
  sll   $t3, $t1, 4
  or    $s1, $t8, $t3
  andi  $t9, $t0, 0xff
  addiu $t4, $t9, -1
  andi  $t8, $t4, 0xff
  xori  $t3, $t8, 0x7f
  ori   $t6, $s1, 2
  sb    $t0, 0x258($sp)
  move  $s1, $t6
  sltiu $t3, $t3, 1
  andi  $t5, $t4, 0xff
  sw    $t1, 0x48($sp)
  andi  $t1, $t4, 0xa8
  sltiu $t0, $t5, 1
  sll   $t6, $t3, 2
  or    $t7, $t1, $t6
  sll   $t9, $t0, 6
  lbu   $t8, 0x287($sp)
  or    $t5, $t7, $t9
  or    $s1, $s1, $t5
  andi  $t2, $s1, 0xff
  move  $s1, $t2
  sw    $t0, 0x44($sp)
  bne   $t8, $at, .L7F0D4DD0
   sb    $t4, 0x258($sp)
  lhu   $t3, 0x296($sp)
  sll   $t0, $t4, 8
  andi  $t1, $t3, 0xff
  or    $t7, $t1, $t0
  b     .L7F0E27FC
   sh    $t7, 0x296($sp)
.L7F0D4DD0:
  lhu   $t9, 0x294($sp)
  lbu   $t2, 0x258($sp)
  andi  $t5, $t9, 0xff
  sll   $t8, $t2, 8
  or    $t3, $t5, $t8
  b     .L7F0E27FC
   sh    $t3, 0x294($sp)
spectrum_op_26:
  lw    $t4, 0x28c($sp)
  lbu   $t1, 0x287($sp)
  lbu   $t2, 0x287($sp)
  addiu $t6, $t4, 7
  bnez  $t1, .L7F0D4E1C
   sw    $t6, 0x28c($sp)
  lui   $t7, %hi(ptr_spectrum_roms) 
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  lhu   $t0, 0x298($sp)
  addu  $t9, $t0, $t7
  b     .L7F0D4E78
   lbu   $s6, ($t9)
.L7F0D4E1C:
  li    $at, 1
  bne   $t2, $at, .L7F0D4E54
   lhu   $t9, 0x298($sp)
  lui   $t8, %hi(ptr_spectrum_roms) 
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  lhu   $t5, 0x298($sp)
  lhu   $t1, 0x296($sp)
  addu  $t3, $t5, $t8
  lbu   $t4, ($t3)
  andi  $t0, $t1, 0xff
  sll   $t6, $t4, 8
  or    $t7, $t6, $t0
  b     .L7F0D4E78
   sh    $t7, 0x296($sp)
.L7F0D4E54:
  lui   $t2, %hi(ptr_spectrum_roms) 
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  lhu   $t4, 0x294($sp)
  addu  $t5, $t9, $t2
  lbu   $t8, ($t5)
  andi  $t1, $t4, 0xff
  sll   $t3, $t8, 8
  or    $t6, $t3, $t1
  sh    $t6, 0x294($sp)
.L7F0D4E78:
  lhu   $t0, 0x298($sp)
  addiu $t7, $t0, 1
  b     .L7F0E27FC
   sh    $t7, 0x298($sp)
spectrum_op_27:
  lw    $t9, 0x28c($sp)
  andi  $t5, $s1, 1
  andi  $t8, $s1, 0x10
  addiu $t2, $t9, 4
  sw    $t2, 0x28c($sp)
  sb    $t5, 0x256($sp)
  bnez  $t8, .L7F0D4EB4
   sb    $zero, 0x257($sp)
  andi  $t4, $s0, 0xf
  slti  $at, $t4, 0xa
  bnez  $at, .L7F0D4EBC
.L7F0D4EB4:
   li    $t3, 6
  sb    $t3, 0x257($sp)
.L7F0D4EBC:
  andi  $t1, $s1, 1
  bnez  $t1, .L7F0D4ED8
   andi  $t9, $s1, 2
  sra   $t6, $s0, 4
  slti  $at, $t6, 0xa
  bnez  $at, .L7F0D4EE4
   nop   
.L7F0D4ED8:
  lbu   $t0, 0x257($sp)
  ori   $t7, $t0, 0x60
  sb    $t7, 0x257($sp)
.L7F0D4EE4:
  beqz  $t9, .L7F0D4F5C
   slti  $at, $s0, 0x91
  lbu   $t2, 0x257($sp)
  andi  $t7, $s0, 0xf
  subu  $t5, $s0, $t2
  andi  $t8, $t5, 0x1ff
  andi  $t3, $t8, 0xa8
  sra   $t6, $t8, 8
  andi  $t9, $t2, 0xf
  slt   $t5, $t7, $t9
  or    $t0, $t3, $t6
  xor   $t3, $s0, $t2
  sll   $t4, $t5, 4
  xor   $t9, $t8, $s0
  sh    $t8, 0x254($sp)
  lbu   $s0, 0x255($sp)
  andi  $t6, $t3, 0x80
  and   $t5, $t6, $t9
  or    $t1, $t0, $t4
  sra   $t0, $t5, 5
  or    $s1, $t1, $t0
  sb    $t2, 0x253($sp)
  sltiu $t3, $s0, 1
  sll   $t7, $t3, 6
  ori   $t2, $s1, 2
  or    $s1, $t2, $t7
  andi  $t6, $s1, 0xff
  move  $s1, $t6
  b     .L7F0D4FE8
   sw    $t3, 0x48($sp)
.L7F0D4F5C:
  bnez  $at, .L7F0D4F78
   andi  $t9, $s0, 0xf
  slti  $at, $t9, 0xa
  bnez  $at, .L7F0D4F78
   lbu   $t5, 0x257($sp)
  ori   $t1, $t5, 0x60
  sb    $t1, 0x257($sp)
.L7F0D4F78:
  lbu   $t0, 0x257($sp)
  andi  $t6, $s0, 0xf
  li    $at, 15
  addu  $t2, $s0, $t0
  andi  $t3, $t2, 0xa8
  sra   $t8, $t2, 8
  andi  $t9, $t0, 0xf
  addu  $t5, $t6, $t9
  or    $t7, $t3, $t8
  not   $t8, $s0
  slt   $t1, $at, $t5
  xor   $t5, $t2, $s0
  sh    $t2, 0x250($sp)
  lbu   $s0, 0x251($sp)
  sll   $t4, $t1, 4
  xor   $t6, $t8, $t0
  andi  $t9, $t6, 0x80
  and   $t1, $t9, $t5
  or    $t3, $t7, $t4
  sra   $t7, $t1, 5
  sltiu $t8, $s0, 1
  sll   $t6, $t8, 6
  or    $t4, $t3, $t7
  or    $s1, $t4, $t6
  andi  $t2, $s1, 0xff
  move  $s1, $t2
  sw    $t8, 0x48($sp)
  sb    $t0, 0x24f($sp)
.L7F0D4FE8:
  lui   $t9, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t9, %lo(ptr_pc_keyboard_table_alloc)($t9)
  lbu   $t3, 0x256($sp)
  addu  $t5, $s0, $t9
  lbu   $t1, ($t5)
  or    $t7, $s1, $t3
  andi  $t4, $t7, 0xfb
  or    $s1, $t1, $t4
  andi  $t8, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t8
spectrum_op_28:
  lw    $t0, 0x28c($sp)
  andi  $t2, $s1, 0x40
  lhu   $t9, 0x298($sp)
  addiu $t6, $t0, 7
  beqz  $t2, .L7F0D5058
   sw    $t6, 0x28c($sp)
  lui   $t5, %hi(ptr_spectrum_roms) 
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  addiu $t0, $t6, 5
  addu  $t3, $t9, $t5
  lb    $t7, ($t3)
  sw    $t0, 0x28c($sp)
  addu  $t1, $t9, $t7
  addiu $t4, $t1, 1
  sh    $t4, 0x298($sp)
  b     .L7F0E27FC
   sw    $t7, 0x248($sp)
.L7F0D5058:
  lhu   $t6, 0x298($sp)
  addiu $t2, $t6, 1
  b     .L7F0E27FC
   sh    $t2, 0x298($sp)
spectrum_op_29:
  lw    $t5, 0x28c($sp)
  lbu   $t9, 0x287($sp)
  addiu $t3, $t5, 0xb
  bnez  $t9, .L7F0D518C
   sw    $t3, 0x28c($sp)
  bnez  $t9, .L7F0D50F0
   lbu   $t1, 0x287($sp)
  addu  $t7, $s7, $s7
  andi  $t1, $t7, 0xffff
  srl   $t4, $t1, 8
  andi  $t0, $t4, 0xffff
  andi  $t8, $s6, 0xf
  addu  $t6, $t0, $t8
  andi  $t2, $s6, 0xf
  addu  $t5, $t6, $t2
  sh    $t7, 0x246($sp)
  li    $at, 15
  slt   $t3, $at, $t5
  lbu   $s7, 0x247($sp)
  addu  $t0, $s6, $s6
  addu  $t5, $t4, $t0
  sh    $t4, 0x246($sp)
  sh    $t5, 0x246($sp)
  lbu   $s6, 0x247($sp)
  sll   $t9, $t3, 4
  andi  $t7, $s1, 0xc4
  or    $t1, $t9, $t7
  sra   $t3, $t5, 8
  andi  $t2, $s6, 0x28
  or    $t9, $t2, $t3
  or    $s1, $t1, $t9
  andi  $t7, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t7
.L7F0D50F0:
  li    $at, 1
  bne   $t1, $at, .L7F0D5108
   sll   $t5, $s6, 8
  lhu   $t4, 0x296($sp)
  b     .L7F0D5110
   sw    $t4, 0x240($sp)
.L7F0D5108:
  lhu   $t8, 0x294($sp)
  sw    $t8, 0x240($sp)
.L7F0D5110:
  lw    $t0, 0x240($sp)
  or    $t2, $t5, $s7
  li    $at, 4095
  andi  $t6, $t0, 0xfff
  addu  $t3, $t6, $t2
  sltu  $t9, $at, $t3
  lbu   $t2, 0x287($sp)
  sll   $t7, $t9, 4
  andi  $t1, $s1, 0xc4
  sll   $t8, $s6, 8
  or    $t5, $t8, $s7
  or    $s1, $t1, $t7
  andi  $t4, $s1, 0xff
  li    $at, 1
  addu  $t6, $t0, $t5
  sw    $t6, 0x240($sp)
  bne   $t2, $at, .L7F0D5160
   move  $s1, $t4
  b     .L7F0D5168
   sh    $t6, 0x296($sp)
.L7F0D5160:
  lw    $t3, 0x240($sp)
  sh    $t3, 0x294($sp)
.L7F0D5168:
  lw    $t9, 0x240($sp)
  srl   $t1, $t9, 8
  andi  $t7, $t1, 0x28
  srl   $t4, $t9, 0x10
  or    $t8, $t7, $t4
  or    $s1, $s1, $t8
  andi  $t0, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t0
.L7F0D518C:
  lbu   $t5, 0x287($sp)
  li    $at, 1
  lbu   $t1, 0x287($sp)
  bne   $t5, $at, .L7F0D52C0
   nop   
  bnez  $t5, .L7F0D5220
   lbu   $t0, 0x287($sp)
  lhu   $t2, 0x296($sp)
  andi  $t7, $s6, 0xf
  li    $at, 15
  andi  $t6, $t2, 0xff
  addu  $t3, $s7, $t6
  andi  $t1, $t3, 0xffff
  srl   $t9, $t1, 8
  andi  $t4, $t9, 0xffff
  sra   $t0, $t2, 8
  andi  $t5, $t0, 0xf
  addu  $t8, $t4, $t7
  addu  $t6, $t8, $t5
  sh    $t3, 0x23e($sp)
  slt   $t3, $at, $t6
  sll   $t1, $t3, 4
  lbu   $s7, 0x23f($sp)
  addu  $t2, $s6, $t0
  addu  $t3, $t9, $t2
  sh    $t9, 0x23e($sp)
  sh    $t3, 0x23e($sp)
  lbu   $s6, 0x23f($sp)
  andi  $t4, $s1, 0xc4
  or    $t7, $t1, $t4
  sra   $t1, $t3, 8
  andi  $t6, $s6, 0x28
  or    $t4, $t6, $t1
  or    $s1, $t7, $t4
  andi  $t7, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t7
.L7F0D5220:
  li    $at, 1
  bne   $t0, $at, .L7F0D5238
   lhu   $t8, 0x294($sp)
  lhu   $t9, 0x296($sp)
  b     .L7F0D523C
   sw    $t9, 0x238($sp)
.L7F0D5238:
  sw    $t8, 0x238($sp)
.L7F0D523C:
  lhu   $t2, 0x296($sp)
  lw    $t4, 0x238($sp)
  li    $at, 4095
  sra   $t5, $t2, 8
  sll   $t3, $t5, 8
  andi  $t6, $t2, 0xff
  or    $t1, $t3, $t6
  andi  $t7, $t4, 0xfff
  addu  $t0, $t7, $t1
  sltu  $t9, $at, $t0
  lbu   $t6, 0x287($sp)
  sll   $t8, $t9, 4
  andi  $t5, $s1, 0xc4
  or    $s1, $t5, $t8
  andi  $t2, $s1, 0xff
  li    $at, 1
  addu  $t3, $t4, $t1
  sw    $t3, 0x238($sp)
  bne   $t6, $at, .L7F0D5294
   move  $s1, $t2
  b     .L7F0D529C
   sh    $t3, 0x296($sp)
.L7F0D5294:
  lw    $t7, 0x238($sp)
  sh    $t7, 0x294($sp)
.L7F0D529C:
  lw    $t0, 0x238($sp)
  srl   $t9, $t0, 8
  andi  $t5, $t9, 0x28
  srl   $t8, $t0, 0x10
  or    $t2, $t5, $t8
  or    $s1, $s1, $t2
  andi  $t4, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t4
.L7F0D52C0:
  bnez  $t1, .L7F0D5340
   lbu   $t4, 0x287($sp)
  lhu   $t6, 0x294($sp)
  andi  $t5, $s6, 0xf
  li    $at, 15
  andi  $t3, $t6, 0xff
  addu  $t7, $s7, $t3
  andi  $t9, $t7, 0xffff
  srl   $t0, $t9, 8
  andi  $t8, $t0, 0xffff
  sra   $t4, $t6, 8
  andi  $t1, $t4, 0xf
  addu  $t2, $t8, $t5
  addu  $t3, $t2, $t1
  sh    $t7, 0x236($sp)
  slt   $t7, $at, $t3
  sll   $t9, $t7, 4
  lbu   $s7, 0x237($sp)
  addu  $t6, $s6, $t4
  addu  $t7, $t0, $t6
  sh    $t0, 0x236($sp)
  sh    $t7, 0x236($sp)
  lbu   $s6, 0x237($sp)
  andi  $t8, $s1, 0xc4
  or    $t5, $t9, $t8
  sra   $t9, $t7, 8
  andi  $t3, $s6, 0x28
  or    $t8, $t3, $t9
  or    $s1, $t5, $t8
  andi  $t5, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t5
.L7F0D5340:
  li    $at, 1
  bne   $t4, $at, .L7F0D5358
   lhu   $t2, 0x294($sp)
  lhu   $t0, 0x296($sp)
  b     .L7F0D535C
   sw    $t0, 0x230($sp)
.L7F0D5358:
  sw    $t2, 0x230($sp)
.L7F0D535C:
  lhu   $t6, 0x294($sp)
  lw    $t8, 0x230($sp)
  li    $at, 4095
  sra   $t1, $t6, 8
  sll   $t7, $t1, 8
  andi  $t3, $t6, 0xff
  or    $t9, $t7, $t3
  andi  $t5, $t8, 0xfff
  addu  $t4, $t5, $t9
  sltu  $t0, $at, $t4
  lbu   $t3, 0x287($sp)
  sll   $t2, $t0, 4
  andi  $t1, $s1, 0xc4
  or    $s1, $t1, $t2
  andi  $t6, $s1, 0xff
  li    $at, 1
  addu  $t7, $t8, $t9
  sw    $t7, 0x230($sp)
  bne   $t3, $at, .L7F0D53B4
   move  $s1, $t6
  b     .L7F0D53BC
   sh    $t7, 0x296($sp)
.L7F0D53B4:
  lw    $t5, 0x230($sp)
  sh    $t5, 0x294($sp)
.L7F0D53BC:
  lw    $t4, 0x230($sp)
  srl   $t0, $t4, 8
  andi  $t1, $t0, 0x28
  srl   $t2, $t4, 0x10
  or    $t6, $t1, $t2
  or    $s1, $s1, $t6
  andi  $t8, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t8
spectrum_op_2A:
  lw    $t9, 0x28c($sp)
  lui   $t5, %hi(ptr_spectrum_roms) 
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  lhu   $t7, 0x298($sp)
  addiu $t3, $t9, 0x10
  sw    $t3, 0x28c($sp)
  addu  $t1, $t5, $t7
  lbu   $t2, 1($t1)
  addu  $t0, $t7, $t5
  lbu   $t4, ($t0)
  lbu   $t3, 0x287($sp)
  sll   $t6, $t2, 8
  addiu $t9, $t7, 2
  or    $t8, $t4, $t6
  sh    $t8, 0x22e($sp)
  bnez  $t3, .L7F0D5438
   sh    $t9, 0x298($sp)
  andi  $t0, $t8, 0xffff
  addu  $t1, $t0, $t5
  lbu   $s7, ($t1)
  b     .L7F0E27FC
   lbu   $s6, 1($t1)
.L7F0D5438:
  lbu   $t2, 0x287($sp)
  li    $at, 1
  lhu   $t4, 0x22e($sp)
  bne   $t2, $at, .L7F0D5474
   lhu   $t1, 0x22e($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  addu  $t9, $t6, $t4
  lbu   $t3, 1($t9)
  addu  $t8, $t4, $t6
  lbu   $t7, ($t8)
  sll   $t0, $t3, 8
  or    $t5, $t7, $t0
  b     .L7F0E27FC
   sh    $t5, 0x296($sp)
.L7F0D5474:
  lui   $t2, %hi(ptr_spectrum_roms) 
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  addu  $t4, $t2, $t1
  lbu   $t9, 1($t4)
  addu  $t8, $t1, $t2
  lbu   $t6, ($t8)
  sll   $t3, $t9, 8
  or    $t7, $t6, $t3
  b     .L7F0E27FC
   sh    $t7, 0x294($sp)
spectrum_op_2B:
  lw    $t0, 0x28c($sp)
  lbu   $t8, 0x287($sp)
  lbu   $t6, 0x287($sp)
  addiu $t5, $t0, 6
  bnez  $t8, .L7F0D54DC
   sw    $t5, 0x28c($sp)
  sltiu $t2, $s7, 1
  addiu $s7, $s7, -1
  andi  $t1, $s7, 0xff
  move  $s7, $t1
  beqz  $t2, .L7F0E27FC
   sw    $t2, 0x48($sp)
  addiu $s6, $s6, -1
  andi  $t9, $s6, 0xff
  b     .L7F0E27FC
   move  $s6, $t9
.L7F0D54DC:
  li    $at, 1
  bne   $t6, $at, .L7F0D54F8
   lhu   $t0, 0x294($sp)
  lhu   $t3, 0x296($sp)
  addiu $t7, $t3, -1
  b     .L7F0E27FC
   sh    $t7, 0x296($sp)
.L7F0D54F8:
  addiu $t5, $t0, -1
  b     .L7F0E27FC
   sh    $t5, 0x294($sp)
spectrum_op_2C:
  lw    $t8, 0x28c($sp)
  lbu   $t1, 0x287($sp)
  lbu   $t3, 0x287($sp)
  addiu $t2, $t8, 4
  bnez  $t1, .L7F0D5574
   sw    $t2, 0x28c($sp)
  addiu $s7, $s7, 1
  andi  $t4, $s7, 0xff
  andi  $t6, $t4, 0xf
  sltiu $t3, $t6, 1
  move  $s7, $t4
  sltiu $t9, $t4, 1
  andi  $t0, $t4, 0xa8
  andi  $t7, $s1, 1
  or    $t5, $t7, $t0
  xori  $t6, $s7, 0x80
  sll   $t8, $t3, 4
  or    $t2, $t5, $t8
  sltiu $t6, $t6, 1
  sll   $t4, $t9, 6
  sw    $t9, 0x44($sp)
  or    $t9, $t2, $t4
  sll   $t7, $t6, 2
  or    $s1, $t9, $t7
  andi  $t0, $s1, 0xff
  move  $s1, $t0
  b     .L7F0E27FC
   sw    $t3, 0x48($sp)
.L7F0D5574:
  li    $at, 1
  bne   $t3, $at, .L7F0D558C
   lhu   $t8, 0x294($sp)
  lhu   $t5, 0x296($sp)
  b     .L7F0D5590
   sb    $t5, 0x22d($sp)
.L7F0D558C:
  sb    $t8, 0x22d($sp)
.L7F0D5590:
  lbu   $t1, 0x22d($sp)
  andi  $t3, $s1, 1
  li    $at, 1
  addiu $t2, $t1, 1
  andi  $t8, $t2, 0xa8
  or    $t1, $t3, $t8
  andi  $t4, $t2, 0xff
  andi  $t7, $t2, 0xf
  sltiu $t0, $t7, 1
  sltiu $t6, $t4, 1
  sll   $t4, $t0, 4
  andi  $t3, $t2, 0xff
  xori  $t8, $t3, 0x80
  or    $t9, $t1, $t4
  sltiu $t8, $t8, 1
  sll   $t7, $t6, 6
  sw    $t0, 0x48($sp)
  lbu   $t4, 0x287($sp)
  sll   $t0, $t8, 2
  or    $t5, $t9, $t7
  or    $s1, $t5, $t0
  andi  $t1, $s1, 0xff
  move  $s1, $t1
  sw    $t6, 0x44($sp)
  bne   $t4, $at, .L7F0D5610
   sb    $t2, 0x22d($sp)
  lhu   $t6, 0x296($sp)
  andi  $t7, $t2, 0xff
  andi  $t9, $t6, 0xff00
  or    $t3, $t9, $t7
  b     .L7F0E27FC
   sh    $t3, 0x296($sp)
.L7F0D5610:
  lhu   $t8, 0x294($sp)
  lbu   $t0, 0x22d($sp)
  andi  $t5, $t8, 0xff00
  or    $t1, $t5, $t0
  b     .L7F0E27FC
   sh    $t1, 0x294($sp)
spectrum_op_2D:
  lw    $t4, 0x28c($sp)
  lbu   $t2, 0x287($sp)
  lbu   $t1, 0x287($sp)
  addiu $t6, $t4, 4
  bnez  $t2, .L7F0D569C
   sw    $t6, 0x28c($sp)
  andi  $t9, $s7, 0xf
  addiu $s7, $s7, -1
  andi  $t1, $s7, 0xff
  sltiu $t7, $t9, 1
  sll   $t8, $t7, 4
  xori  $t2, $t1, 0x7f
  sltiu $t2, $t2, 1
  andi  $t3, $s1, 1
  or    $s1, $t3, $t8
  sll   $t9, $t2, 2
  sw    $t7, 0x48($sp)
  sltiu $t4, $t1, 1
  andi  $t6, $t1, 0xa8
  or    $t7, $t6, $t9
  sll   $t8, $t4, 6
  or    $t5, $t7, $t8
  ori   $t0, $s1, 2
  or    $s1, $t0, $t5
  andi  $t0, $s1, 0xff
  move  $s1, $t0
  sw    $t4, 0x44($sp)
  b     .L7F0E27FC
   move  $s7, $t1
.L7F0D569C:
  li    $at, 1
  bne   $t1, $at, .L7F0D56B4
   lhu   $t2, 0x294($sp)
  lhu   $t4, 0x296($sp)
  b     .L7F0D56B8
   sb    $t4, 0x22c($sp)
.L7F0D56B4:
  sb    $t2, 0x22c($sp)
.L7F0D56B8:
  lbu   $t6, 0x22c($sp)
  andi  $t7, $s1, 1
  li    $at, 1
  andi  $t9, $t6, 0xf
  sltiu $t3, $t9, 1
  sll   $t8, $t3, 4
  or    $s1, $t7, $t8
  addiu $t1, $t6, -1
  andi  $t7, $t1, 0xff
  xori  $t8, $t7, 0x7f
  ori   $t5, $s1, 2
  move  $s1, $t5
  sltiu $t8, $t8, 1
  andi  $t4, $t1, 0xff
  sw    $t3, 0x48($sp)
  andi  $t3, $t1, 0xa8
  sltiu $t2, $t4, 1
  sll   $t5, $t8, 2
  or    $t0, $t3, $t5
  sll   $t6, $t2, 6
  lbu   $t7, 0x287($sp)
  or    $t4, $t0, $t6
  or    $s1, $s1, $t4
  andi  $t9, $s1, 0xff
  move  $s1, $t9
  sw    $t2, 0x44($sp)
  bne   $t7, $at, .L7F0D5740
   sb    $t1, 0x22c($sp)
  lhu   $t8, 0x296($sp)
  andi  $t5, $t1, 0xff
  andi  $t3, $t8, 0xff00
  or    $t2, $t3, $t5
  b     .L7F0E27FC
   sh    $t2, 0x296($sp)
.L7F0D5740:
  lhu   $t0, 0x294($sp)
  lbu   $t4, 0x22c($sp)
  andi  $t6, $t0, 0xff00
  or    $t9, $t6, $t4
  b     .L7F0E27FC
   sh    $t9, 0x294($sp)
spectrum_op_2E:
  lw    $t7, 0x28c($sp)
  lbu   $t1, 0x287($sp)
  lbu   $t0, 0x287($sp)
  addiu $t8, $t7, 7
  bnez  $t1, .L7F0D5788
   sw    $t8, 0x28c($sp)
  lui   $t5, %hi(ptr_spectrum_roms) 
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  lhu   $t3, 0x298($sp)
  addu  $t2, $t3, $t5
  b     .L7F0D57DC
   lbu   $s7, ($t2)
.L7F0D5788:
  li    $at, 1
  bne   $t0, $at, .L7F0D57BC
   lhu   $t5, 0x298($sp)
  lui   $t4, %hi(ptr_spectrum_roms) 
  lw    $t4, %lo(ptr_spectrum_roms)($t4)
  lhu   $t6, 0x298($sp)
  lhu   $t8, 0x296($sp)
  addu  $t9, $t6, $t4
  lbu   $t7, ($t9)
  andi  $t1, $t8, 0xff00
  or    $t3, $t7, $t1
  b     .L7F0D57DC
   sh    $t3, 0x296($sp)
.L7F0D57BC:
  lui   $t2, %hi(ptr_spectrum_roms) 
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  lhu   $t4, 0x294($sp)
  addu  $t0, $t5, $t2
  lbu   $t6, ($t0)
  andi  $t9, $t4, 0xff00
  or    $t8, $t6, $t9
  sh    $t8, 0x294($sp)
.L7F0D57DC:
  lhu   $t7, 0x298($sp)
  addiu $t1, $t7, 1
  b     .L7F0E27FC
   sh    $t1, 0x298($sp)
spectrum_op_2F:
  not   $s0, $s0
  lw    $t3, 0x28c($sp)
  andi  $t2, $s0, 0xff
  andi  $t4, $t2, 0x28
  andi  $t0, $s1, 0xc5
  or    $s1, $t0, $t4
  ori   $t6, $s1, 0x12
  addiu $t5, $t3, 4
  sw    $t5, 0x28c($sp)
  move  $s0, $t2
  b     .L7F0E27FC
   andi  $s1, $t6, 0xff
spectrum_op_30:
  lw    $t8, 0x28c($sp)
  andi  $t1, $s1, 1
  lhu   $t2, 0x298($sp)
  addiu $t7, $t8, 7
  beqz  $t1, .L7F0D5844
   sw    $t7, 0x28c($sp)
  lhu   $t3, 0x298($sp)
  addiu $t5, $t3, 1
  b     .L7F0E27FC
   sh    $t5, 0x298($sp)
.L7F0D5844:
  lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  lw    $t7, 0x28c($sp)
  addu  $t4, $t2, $t0
  lb    $t6, ($t4)
  addiu $t1, $t7, 5
  sw    $t1, 0x28c($sp)
  addu  $t9, $t2, $t6
  addiu $t8, $t9, 1
  sh    $t8, 0x298($sp)
  b     .L7F0E27FC
   sw    $t6, 0x228($sp)
spectrum_op_31:
  lw    $t3, 0x28c($sp)
  lui   $t4, %hi(ptr_spectrum_roms) 
  lw    $t4, %lo(ptr_spectrum_roms)($t4)
  lhu   $t0, 0x298($sp)
  addiu $t5, $t3, 0xa
  sw    $t5, 0x28c($sp)
  addu  $t9, $t4, $t0
  lbu   $t8, 1($t9)
  addu  $t2, $t0, $t4
  lbu   $t6, ($t2)
  sll   $t7, $t8, 8
  addiu $t3, $t0, 2
  or    $t1, $t6, $t7
  sh    $t1, 0x292($sp)
  b     .L7F0E27FC
   sh    $t3, 0x298($sp)
spectrum_op_32:
  lw    $t5, 0x28c($sp)
  lui   $t9, %hi(ptr_spectrum_roms) 
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  lhu   $t4, 0x298($sp)
  addiu $t2, $t5, 0xd
  sw    $t2, 0x28c($sp)
  addu  $t7, $t9, $t4
  lbu   $t1, 1($t7)
  addu  $t8, $t4, $t9
  lbu   $t6, ($t8)
  sll   $t0, $t1, 8
  addiu $t5, $t4, 2
  or    $t3, $t6, $t0
  andi  $t2, $t3, 0xffff
  slti  $at, $t2, 0x5b00
  sh    $t3, 0x226($sp)
  bnez  $at, .L7F0D5910
   sh    $t5, 0x298($sp)
  lui   $t8, %hi(ptr_spectrum_roms) 
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  addu  $t9, $t8, $t2
  b     .L7F0E27FC
   sb    $s0, ($t9)
.L7F0D5910:
  lhu   $t7, 0x226($sp)
  lhu   $t8, 0x226($sp)
  lui   $t1, %hi(ptr_spectrum_roms) 
  slti  $at, $t7, 0x5800
  bnezl $at, .L7F0D5954
   slti  $at, $t8, 0x4000
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  lui   $t3, %hi(ptr_300alloc) 
  li    $t0, 1
  addu  $t6, $t1, $t7
  sb    $s0, ($t6)
  lhu   $t4, 0x226($sp)
  lw    $t3, %lo(ptr_300alloc)($t3)
  addu  $t5, $t3, $t4
  b     .L7F0E27FC
   sb    $t0, -0x5800($t5)
  slti  $at, $t8, 0x4000
.L7F0D5954:
  bnez  $at, .L7F0E27FC
   lui   $t2, %hi(ptr_spectrum_roms) 
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  lui   $t5, %hi(ptr_300alloc) 
  li    $t1, 1
  addu  $t9, $t2, $t8
  sb    $s0, ($t9)
  lhu   $t7, 0x226($sp)
  lw    $t5, %lo(ptr_300alloc)($t5)
  andi  $t6, $t7, 0x1800
  sra   $t3, $t6, 3
  andi  $t4, $t7, 0xff
  or    $t0, $t3, $t4
  addu  $t2, $t5, $t0
  b     .L7F0E27FC
   sb    $t1, ($t2)
spectrum_op_33:
  lw    $t8, 0x28c($sp)
  lhu   $t6, 0x292($sp)
  addiu $t9, $t8, 6
  addiu $t7, $t6, 1
  sw    $t9, 0x28c($sp)
  b     .L7F0E27FC
   sh    $t7, 0x292($sp)
spectrum_op_34:
  lw    $t3, 0x28c($sp)
  lbu   $t5, 0x287($sp)
  sll   $t0, $s6, 8
  addiu $t4, $t3, 0xb
  bnez  $t5, .L7F0D59D4
   sw    $t4, 0x28c($sp)
  or    $t1, $t0, $s7
  b     .L7F0D5A28
   sh    $t1, 0x224($sp)
.L7F0D59D4:
  lw    $t2, 0x28c($sp)
  lbu   $t9, 0x287($sp)
  li    $at, 1
  addiu $t8, $t2, 8
  bne   $t9, $at, .L7F0D59F8
   sw    $t8, 0x28c($sp)
  lhu   $t6, 0x296($sp)
  b     .L7F0D5A00
   sw    $t6, 0x48($sp)
.L7F0D59F8:
  lhu   $t7, 0x294($sp)
  sw    $t7, 0x48($sp)
.L7F0D5A00:
  lui   $t4, %hi(ptr_spectrum_roms) 
  lw    $t4, %lo(ptr_spectrum_roms)($t4)
  lhu   $t3, 0x298($sp)
  lw    $t1, 0x48($sp)
  addu  $t5, $t3, $t4
  lb    $t0, ($t5)
  addiu $t8, $t3, 1
  sh    $t8, 0x298($sp)
  addu  $t2, $t0, $t1
  sh    $t2, 0x224($sp)
.L7F0D5A28:
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  lhu   $t9, 0x224($sp)
  addu  $t7, $t9, $t6
  lbu   $t4, ($t7)
  andi  $t9, $s1, 1
  addiu $t5, $t4, 1
  andi  $t7, $t5, 0xa8
  sb    $t4, 0x223($sp)
  or    $t4, $t9, $t7
  andi  $t0, $t5, 0xff
  andi  $t3, $t5, 0xf
  sltiu $t8, $t3, 1
  sltiu $t1, $t0, 1
  sll   $t0, $t8, 4
  andi  $t9, $t5, 0xff
  xori  $t7, $t9, 0x80
  or    $t2, $t4, $t0
  lhu   $t0, 0x224($sp)
  sltiu $t7, $t7, 1
  sll   $t3, $t1, 6
  sw    $t8, 0x48($sp)
  sll   $t8, $t7, 2
  or    $t6, $t2, $t3
  or    $s1, $t6, $t8
  andi  $t4, $s1, 0xff
  slti  $at, $t0, 0x5b00
  move  $s1, $t4
  sw    $t1, 0x44($sp)
  bnez  $at, .L7F0D5AB8
   sb    $t5, 0x223($sp)
  lui   $t2, %hi(ptr_spectrum_roms) 
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  addu  $t3, $t2, $t0
  b     .L7F0E27FC
   sb    $t5, ($t3)
.L7F0D5AB8:
  lhu   $t5, 0x224($sp)
  lhu   $t1, 0x224($sp)
  lui   $t7, %hi(ptr_spectrum_roms) 
  slti  $at, $t5, 0x5800
  bnezl $at, .L7F0D5B00
   slti  $at, $t1, 0x4000
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  lbu   $t9, 0x223($sp)
  lui   $t4, %hi(ptr_300alloc) 
  addu  $t6, $t7, $t5
  sb    $t9, ($t6)
  lhu   $t2, 0x224($sp)
  lw    $t4, %lo(ptr_300alloc)($t4)
  li    $t8, 1
  addu  $t0, $t4, $t2
  b     .L7F0E27FC
   sb    $t8, -0x5800($t0)
  slti  $at, $t1, 0x4000
.L7F0D5B00:
  bnez  $at, .L7F0E27FC
   lui   $t7, %hi(ptr_spectrum_roms) 
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  lbu   $t3, 0x223($sp)
  li    $t9, 1
  addu  $t5, $t7, $t1
  sb    $t3, ($t5)
  lhu   $t6, 0x224($sp)
  lui   $t7, %hi(ptr_300alloc) 
  lw    $t7, %lo(ptr_300alloc)($t7)
  andi  $t4, $t6, 0x1800
  sra   $t2, $t4, 3
  andi  $t8, $t6, 0xff
  or    $t0, $t2, $t8
  addu  $t1, $t7, $t0
  b     .L7F0E27FC
   sb    $t9, ($t1)
spectrum_op_35:
  lw    $t3, 0x28c($sp)
  lbu   $t4, 0x287($sp)
  sll   $t6, $s6, 8
  addiu $t5, $t3, 0xb
  bnez  $t4, .L7F0D5B68
   sw    $t5, 0x28c($sp)
  or    $t2, $t6, $s7
  b     .L7F0D5BBC
   sh    $t2, 0x220($sp)
.L7F0D5B68:
  lw    $t8, 0x28c($sp)
  lbu   $t0, 0x287($sp)
  li    $at, 1
  addiu $t7, $t8, 8
  bne   $t0, $at, .L7F0D5B8C
   sw    $t7, 0x28c($sp)
  lhu   $t9, 0x296($sp)
  b     .L7F0D5B94
   sw    $t9, 0x48($sp)
.L7F0D5B8C:
  lhu   $t1, 0x294($sp)
  sw    $t1, 0x48($sp)
.L7F0D5B94:
  lui   $t5, %hi(ptr_spectrum_roms) 
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  lhu   $t3, 0x298($sp)
  lw    $t2, 0x48($sp)
  addu  $t4, $t3, $t5
  lb    $t6, ($t4)
  addiu $t7, $t3, 1
  sh    $t7, 0x298($sp)
  addu  $t8, $t6, $t2
  sh    $t8, 0x220($sp)
.L7F0D5BBC:
  lui   $t9, %hi(ptr_spectrum_roms) 
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  lhu   $t0, 0x220($sp)
  andi  $t8, $s1, 1
  addu  $t1, $t0, $t9
  lbu   $t5, ($t1)
  andi  $t4, $t5, 0xf
  sltiu $t6, $t4, 1
  sll   $t2, $t6, 4
  or    $s1, $t8, $t2
  addiu $t0, $t5, -1
  andi  $t8, $t0, 0xff
  xori  $t2, $t8, 0x7f
  ori   $t3, $s1, 2
  sw    $t6, 0x48($sp)
  andi  $t6, $t0, 0xa8
  move  $s1, $t3
  sltiu $t2, $t2, 1
  andi  $t9, $t0, 0xff
  sb    $t5, 0x21f($sp)
  sb    $t0, 0x21f($sp)
  sltiu $t1, $t9, 1
  sll   $t3, $t2, 2
  lhu   $t0, 0x220($sp)
  or    $t7, $t6, $t3
  sll   $t5, $t1, 6
  or    $t9, $t7, $t5
  or    $s1, $s1, $t9
  andi  $t4, $s1, 0xff
  slti  $at, $t0, 0x5b00
  move  $s1, $t4
  bnez  $at, .L7F0D5C58
   sw    $t1, 0x44($sp)
  lui   $t2, %hi(ptr_spectrum_roms) 
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  lbu   $t8, 0x21f($sp)
  addu  $t6, $t2, $t0
  b     .L7F0E27FC
   sb    $t8, ($t6)
.L7F0D5C58:
  lhu   $t3, 0x220($sp)
  lhu   $t8, 0x220($sp)
  lui   $t7, %hi(ptr_spectrum_roms) 
  slti  $at, $t3, 0x5800
  bnezl $at, .L7F0D5CA0
   slti  $at, $t8, 0x4000
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  lbu   $t1, 0x21f($sp)
  lui   $t4, %hi(ptr_300alloc) 
  addu  $t5, $t7, $t3
  sb    $t1, ($t5)
  lhu   $t2, 0x220($sp)
  lw    $t4, %lo(ptr_300alloc)($t4)
  li    $t9, 1
  addu  $t0, $t4, $t2
  b     .L7F0E27FC
   sb    $t9, -0x5800($t0)
  slti  $at, $t8, 0x4000
.L7F0D5CA0:
  bnez  $at, .L7F0E27FC
   lui   $t7, %hi(ptr_spectrum_roms) 
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  lbu   $t6, 0x21f($sp)
  li    $t1, 1
  addu  $t3, $t7, $t8
  sb    $t6, ($t3)
  lhu   $t5, 0x220($sp)
  lui   $t7, %hi(ptr_300alloc) 
  lw    $t7, %lo(ptr_300alloc)($t7)
  andi  $t4, $t5, 0x1800
  sra   $t2, $t4, 3
  andi  $t9, $t5, 0xff
  or    $t0, $t2, $t9
  addu  $t8, $t7, $t0
  b     .L7F0E27FC
   sb    $t1, ($t8)
spectrum_op_36:
  lw    $t6, 0x28c($sp)
  lbu   $t4, 0x287($sp)
  sll   $t5, $s6, 8
  addiu $t3, $t6, 0xa
  bnez  $t4, .L7F0D5D08
   sw    $t3, 0x28c($sp)
  or    $t2, $t5, $s7
  b     .L7F0D5D5C
   sh    $t2, 0x21c($sp)
.L7F0D5D08:
  lw    $t9, 0x28c($sp)
  lbu   $t0, 0x287($sp)
  li    $at, 1
  addiu $t7, $t9, 5
  bne   $t0, $at, .L7F0D5D2C
   sw    $t7, 0x28c($sp)
  lhu   $t1, 0x296($sp)
  b     .L7F0D5D34
   sw    $t1, 0x48($sp)
.L7F0D5D2C:
  lhu   $t8, 0x294($sp)
  sw    $t8, 0x48($sp)
.L7F0D5D34:
  lui   $t3, %hi(ptr_spectrum_roms) 
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  lhu   $t6, 0x298($sp)
  lw    $t2, 0x48($sp)
  addu  $t4, $t6, $t3
  lb    $t5, ($t4)
  addiu $t7, $t6, 1
  sh    $t7, 0x298($sp)
  addu  $t9, $t5, $t2
  sh    $t9, 0x21c($sp)
.L7F0D5D5C:
  lhu   $t0, 0x21c($sp)
  lhu   $t2, 0x21c($sp)
  lhu   $t1, 0x298($sp)
  slti  $at, $t0, 0x5b00
  bnez  $at, .L7F0D5D8C
   lui   $t8, %hi(ptr_spectrum_roms) 
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  addu  $t3, $t1, $t8
  lbu   $t4, ($t3)
  addu  $t5, $t8, $t0
  b     .L7F0D5E1C
   sb    $t4, ($t5)
.L7F0D5D8C:
  slti  $at, $t2, 0x5800
  bnez  $at, .L7F0D5DD0
   lhu   $t9, 0x21c($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  lhu   $t9, 0x298($sp)
  lui   $t0, %hi(ptr_300alloc) 
  addu  $t3, $t6, $t2
  addu  $t7, $t9, $t6
  lbu   $t1, ($t7)
  li    $t8, 1
  sb    $t1, ($t3)
  lhu   $t4, 0x21c($sp)
  lw    $t0, %lo(ptr_300alloc)($t0)
  addu  $t5, $t0, $t4
  b     .L7F0D5E1C
   sb    $t8, -0x5800($t5)
.L7F0D5DD0:
  slti  $at, $t9, 0x4000
  bnez  $at, .L7F0D5E1C
   lhu   $t7, 0x298($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  li    $t0, 1
  addu  $t2, $t7, $t6
  lbu   $t1, ($t2)
  addu  $t3, $t6, $t9
  lui   $t6, %hi(ptr_300alloc) 
  sb    $t1, ($t3)
  lhu   $t4, 0x21c($sp)
  lw    $t6, %lo(ptr_300alloc)($t6)
  andi  $t8, $t4, 0x1800
  sra   $t5, $t8, 3
  andi  $t7, $t4, 0xff
  or    $t2, $t5, $t7
  addu  $t9, $t6, $t2
  sb    $t0, ($t9)
.L7F0D5E1C:
  lhu   $t1, 0x298($sp)
  addiu $t3, $t1, 1
  b     .L7F0E27FC
   sh    $t3, 0x298($sp)
spectrum_op_37:
  lw    $t8, 0x28c($sp)
  andi  $t5, $s1, 0xc4
  ori   $t7, $t5, 1
  andi  $t6, $s0, 0x28
  or    $s1, $t7, $t6
  andi  $t2, $s1, 0xff
  addiu $t4, $t8, 4
  sw    $t4, 0x28c($sp)
  b     .L7F0E27FC
   move  $s1, $t2
spectrum_op_38:
  lw    $t0, 0x28c($sp)
  andi  $t1, $s1, 1
  lhu   $t3, 0x298($sp)
  addiu $t9, $t0, 7
  beqz  $t1, .L7F0D5E98
   sw    $t9, 0x28c($sp)
  lui   $t8, %hi(ptr_spectrum_roms) 
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  addiu $t0, $t9, 5
  addu  $t4, $t3, $t8
  lb    $t5, ($t4)
  sw    $t0, 0x28c($sp)
  addu  $t7, $t3, $t5
  addiu $t6, $t7, 1
  sh    $t6, 0x298($sp)
  b     .L7F0E27FC
   sw    $t5, 0x218($sp)
.L7F0D5E98:
  lhu   $t9, 0x298($sp)
  addiu $t1, $t9, 1
  b     .L7F0E27FC
   sh    $t1, 0x298($sp)
spectrum_op_39:
  lw    $t8, 0x28c($sp)
  lbu   $t3, 0x287($sp)
  lhu   $t5, 0x292($sp)
  addiu $t4, $t8, 0xb
  bnez  $t3, .L7F0D5F34
   sw    $t4, 0x28c($sp)
  andi  $t7, $t5, 0xff
  addu  $t6, $s7, $t7
  andi  $t2, $t6, 0xffff
  srl   $t0, $t2, 8
  andi  $t1, $t0, 0xffff
  andi  $t9, $s6, 0xf
  sra   $t4, $t5, 8
  andi  $t3, $t4, 0xf
  addu  $t8, $t1, $t9
  addu  $t7, $t8, $t3
  sh    $t6, 0x216($sp)
  li    $at, 15
  slt   $t6, $at, $t7
  sll   $t2, $t6, 4
  lbu   $s7, 0x217($sp)
  addu  $t5, $s6, $t4
  addu  $t6, $t0, $t5
  sh    $t0, 0x216($sp)
  sh    $t6, 0x216($sp)
  lbu   $s6, 0x217($sp)
  andi  $t1, $s1, 0xc4
  or    $t9, $t2, $t1
  sra   $t2, $t6, 8
  andi  $t7, $s6, 0x28
  or    $t1, $t7, $t2
  or    $s1, $t9, $t1
  andi  $t9, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t9
.L7F0D5F34:
  lbu   $t4, 0x287($sp)
  li    $at, 1
  lhu   $t8, 0x294($sp)
  bne   $t4, $at, .L7F0D5F50
   lhu   $t0, 0x296($sp)
  b     .L7F0D5F54
   sw    $t0, 0x210($sp)
.L7F0D5F50:
  sw    $t8, 0x210($sp)
.L7F0D5F54:
  lhu   $t5, 0x292($sp)
  lw    $t1, 0x210($sp)
  li    $at, 4095
  sra   $t3, $t5, 8
  sll   $t6, $t3, 8
  andi  $t7, $t5, 0xff
  or    $t2, $t6, $t7
  andi  $t9, $t1, 0xfff
  addu  $t4, $t9, $t2
  sltu  $t0, $at, $t4
  lbu   $t7, 0x287($sp)
  sll   $t8, $t0, 4
  andi  $t3, $s1, 0xc4
  or    $s1, $t3, $t8
  andi  $t5, $s1, 0xff
  li    $at, 1
  addu  $t6, $t1, $t2
  sw    $t6, 0x210($sp)
  bne   $t7, $at, .L7F0D5FAC
   move  $s1, $t5
  b     .L7F0D5FB4
   sh    $t6, 0x296($sp)
.L7F0D5FAC:
  lw    $t9, 0x210($sp)
  sh    $t9, 0x294($sp)
.L7F0D5FB4:
  lw    $t4, 0x210($sp)
  srl   $t0, $t4, 8
  andi  $t3, $t0, 0x28
  srl   $t8, $t4, 0x10
  or    $t5, $t3, $t8
  or    $s1, $s1, $t5
  andi  $t1, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t1
spectrum_op_3A:
  lw    $t2, 0x28c($sp)
  lui   $t9, %hi(ptr_spectrum_roms) 
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  lhu   $t6, 0x298($sp)
  addiu $t7, $t2, 0xd
  sw    $t7, 0x28c($sp)
  addu  $t3, $t9, $t6
  lbu   $t8, 1($t3)
  addu  $t0, $t6, $t9
  lbu   $t4, ($t0)
  sll   $t5, $t8, 8
  addiu $t2, $t6, 2
  or    $t1, $t4, $t5
  andi  $t7, $t1, 0xffff
  sh    $t1, 0x20e($sp)
  sh    $t2, 0x298($sp)
  addu  $t0, $t7, $t9
  b     .L7F0E27FC
   lbu   $s0, ($t0)
spectrum_op_3B:
  lw    $t3, 0x28c($sp)
  lhu   $t4, 0x292($sp)
  addiu $t8, $t3, 6
  addiu $t5, $t4, -1
  sw    $t8, 0x28c($sp)
  b     .L7F0E27FC
   sh    $t5, 0x292($sp)
spectrum_op_3C:
  addiu $s0, $s0, 1
  andi  $t2, $s0, 0xff
  lw    $t1, 0x28c($sp)
  andi  $t9, $t2, 0xf
  sltiu $t0, $t9, 1
  move  $s0, $t2
  sltiu $t7, $t2, 1
  andi  $t8, $t2, 0xa8
  andi  $t3, $s1, 1
  or    $t4, $t3, $t8
  xori  $t9, $s0, 0x80
  sll   $t5, $t0, 4
  addiu $t6, $t1, 4
  or    $t1, $t4, $t5
  sltiu $t9, $t9, 1
  sll   $t2, $t7, 6
  sw    $t7, 0x44($sp)
  or    $t7, $t1, $t2
  sll   $t3, $t9, 2
  or    $s1, $t7, $t3
  andi  $t8, $s1, 0xff
  sw    $t6, 0x28c($sp)
  move  $s1, $t8
  b     .L7F0E27FC
   sw    $t0, 0x48($sp)
spectrum_op_3D:
  lw    $t0, 0x28c($sp)
  andi  $t5, $s0, 0xf
  addiu $s0, $s0, -1
  addiu $t4, $t0, 4
  sw    $t4, 0x28c($sp)
  andi  $t3, $s0, 0xff
  sltiu $t6, $t5, 1
  sll   $t2, $t6, 4
  xori  $t4, $t3, 0x7f
  sltiu $t4, $t4, 1
  andi  $t1, $s1, 1
  or    $s1, $t1, $t2
  sll   $t5, $t4, 2
  sw    $t6, 0x48($sp)
  sltiu $t8, $t3, 1
  andi  $t0, $t3, 0xa8
  or    $t6, $t0, $t5
  sll   $t2, $t8, 6
  or    $t9, $t6, $t2
  ori   $t7, $s1, 2
  or    $s1, $t7, $t9
  andi  $t7, $s1, 0xff
  move  $s1, $t7
  sw    $t8, 0x44($sp)
  b     .L7F0E27FC
   move  $s0, $t3
spectrum_op_3E:
  lw    $t3, 0x28c($sp)
  lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  lhu   $t4, 0x298($sp)
  addiu $t8, $t3, 7
  sw    $t8, 0x28c($sp)
  addu  $t5, $t4, $t0
  lbu   $s0, ($t5)
  addiu $t1, $t4, 1
  b     .L7F0E27FC
   sh    $t1, 0x298($sp)
spectrum_op_3F:
  andi  $t7, $s1, 1
  lw    $t6, 0x28c($sp)
  xori  $t3, $t7, 1
  andi  $t9, $s1, 0xc4
  andi  $t0, $s1, 1
  sll   $t5, $t0, 4
  or    $t8, $t9, $t3
  or    $t4, $t8, $t5
  andi  $t1, $s0, 0x28
  or    $s1, $t4, $t1
  addiu $t2, $t6, 4
  andi  $t6, $s1, 0xff
  sw    $t2, 0x28c($sp)
  b     .L7F0E27FC
   move  $s1, $t6
spectrum_op_40:
  lw    $t2, 0x28c($sp)
  addiu $t7, $t2, 4
  b     .L7F0E27FC
   sw    $t7, 0x28c($sp)
spectrum_op_41:
  lw    $t9, 0x28c($sp)
  andi  $s2, $s3, 0xff
  addiu $t3, $t9, 4
  b     .L7F0E27FC
   sw    $t3, 0x28c($sp)
spectrum_op_42:
  lw    $t0, 0x28c($sp)
  andi  $s2, $s4, 0xff
  addiu $t8, $t0, 4
  b     .L7F0E27FC
   sw    $t8, 0x28c($sp)
spectrum_op_43:
  lw    $t5, 0x28c($sp)
  andi  $s2, $s5, 0xff
  addiu $t4, $t5, 4
  b     .L7F0E27FC
   sw    $t4, 0x28c($sp)
spectrum_op_44:
  lw    $t1, 0x28c($sp)
  lbu   $t2, 0x287($sp)
  lbu   $t7, 0x287($sp)
  addiu $t6, $t1, 4
  bnez  $t2, .L7F0D61E0
   sw    $t6, 0x28c($sp)
  b     .L7F0E27FC
   andi  $s2, $s6, 0xff
.L7F0D61E0:
  li    $at, 1
  bne   $t7, $at, .L7F0D61FC
   lhu   $t0, 0x294($sp)
  lhu   $t9, 0x296($sp)
  sra   $t3, $t9, 8
  b     .L7F0D6204
   sw    $t3, 0x48($sp)
.L7F0D61FC:
  sra   $t8, $t0, 8
  sw    $t8, 0x48($sp)
.L7F0D6204:
  b     .L7F0E27FC
   lbu   $s2, 0x4b($sp)
spectrum_op_45:
  lw    $t5, 0x28c($sp)
  lbu   $t1, 0x287($sp)
  lbu   $t6, 0x287($sp)
  addiu $t4, $t5, 4
  bnez  $t1, .L7F0D622C
   sw    $t4, 0x28c($sp)
  b     .L7F0E27FC
   andi  $s2, $s7, 0xff
.L7F0D622C:
  li    $at, 1
  bne   $t6, $at, .L7F0D6248
   lhu   $t9, 0x294($sp)
  lhu   $t2, 0x296($sp)
  andi  $t7, $t2, 0xff
  b     .L7F0D6250
   sw    $t7, 0x48($sp)
.L7F0D6248:
  andi  $t3, $t9, 0xff
  sw    $t3, 0x48($sp)
.L7F0D6250:
  b     .L7F0E27FC
   lbu   $s2, 0x4b($sp)
spectrum_op_46:
  lw    $t0, 0x28c($sp)
  lbu   $t5, 0x287($sp)
  sll   $t4, $s6, 8
  addiu $t8, $t0, 7
  bnez  $t5, .L7F0D627C
   sw    $t8, 0x28c($sp)
  or    $t1, $t4, $s7
  b     .L7F0D62D0
   sh    $t1, 0x20c($sp)
.L7F0D627C:
  lw    $t6, 0x28c($sp)
  lbu   $t7, 0x287($sp)
  li    $at, 1
  addiu $t2, $t6, 8
  bne   $t7, $at, .L7F0D62A0
   sw    $t2, 0x28c($sp)
  lhu   $t9, 0x296($sp)
  b     .L7F0D62A8
   sw    $t9, 0x48($sp)
.L7F0D62A0:
  lhu   $t3, 0x294($sp)
  sw    $t3, 0x48($sp)
.L7F0D62A8:
  lui   $t8, %hi(ptr_spectrum_roms) 
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  lhu   $t0, 0x298($sp)
  lw    $t1, 0x48($sp)
  addu  $t5, $t0, $t8
  lb    $t4, ($t5)
  addiu $t2, $t0, 1
  sh    $t2, 0x298($sp)
  addu  $t6, $t4, $t1
  sh    $t6, 0x20c($sp)
.L7F0D62D0:
  lui   $t9, %hi(ptr_spectrum_roms) 
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  lhu   $t7, 0x20c($sp)
  addu  $t3, $t7, $t9
  b     .L7F0E27FC
   lbu   $s2, ($t3)
spectrum_op_47:
  lw    $t8, 0x28c($sp)
  andi  $s2, $s0, 0xff
  addiu $t5, $t8, 4
  b     .L7F0E27FC
   sw    $t5, 0x28c($sp)
spectrum_op_48:
  lw    $t4, 0x28c($sp)
  andi  $s3, $s2, 0xff
  addiu $t1, $t4, 4
  b     .L7F0E27FC
   sw    $t1, 0x28c($sp)
spectrum_op_49:
  lw    $t6, 0x28c($sp)
  addiu $t0, $t6, 4
  b     .L7F0E27FC
   sw    $t0, 0x28c($sp)
spectrum_op_4A:
  lw    $t2, 0x28c($sp)
  andi  $s3, $s4, 0xff
  addiu $t7, $t2, 4
  b     .L7F0E27FC
   sw    $t7, 0x28c($sp)
spectrum_op_4B:
  lw    $t9, 0x28c($sp)
  andi  $s3, $s5, 0xff
  addiu $t3, $t9, 4
  b     .L7F0E27FC
   sw    $t3, 0x28c($sp)
spectrum_op_4C:
  lw    $t8, 0x28c($sp)
  lbu   $t4, 0x287($sp)
  lbu   $t1, 0x287($sp)
  addiu $t5, $t8, 4
  bnez  $t4, .L7F0D6368
   sw    $t5, 0x28c($sp)
  b     .L7F0E27FC
   andi  $s3, $s6, 0xff
.L7F0D6368:
  li    $at, 1
  bne   $t1, $at, .L7F0D6384
   lhu   $t2, 0x294($sp)
  lhu   $t6, 0x296($sp)
  sra   $t0, $t6, 8
  b     .L7F0D638C
   sw    $t0, 0x48($sp)
.L7F0D6384:
  sra   $t7, $t2, 8
  sw    $t7, 0x48($sp)
.L7F0D638C:
  b     .L7F0E27FC
   lbu   $s3, 0x4b($sp)
spectrum_op_4D:
  lw    $t9, 0x28c($sp)
  lbu   $t8, 0x287($sp)
  lbu   $t5, 0x287($sp)
  addiu $t3, $t9, 4
  bnez  $t8, .L7F0D63B4
   sw    $t3, 0x28c($sp)
  b     .L7F0E27FC
   andi  $s3, $s7, 0xff
.L7F0D63B4:
  li    $at, 1
  bne   $t5, $at, .L7F0D63D0
   lhu   $t6, 0x294($sp)
  lhu   $t4, 0x296($sp)
  andi  $t1, $t4, 0xff
  b     .L7F0D63D8
   sw    $t1, 0x48($sp)
.L7F0D63D0:
  andi  $t0, $t6, 0xff
  sw    $t0, 0x48($sp)
.L7F0D63D8:
  b     .L7F0E27FC
   lbu   $s3, 0x4b($sp)
spectrum_op_4E:
  lw    $t2, 0x28c($sp)
  lbu   $t9, 0x287($sp)
  sll   $t3, $s6, 8
  addiu $t7, $t2, 7
  bnez  $t9, .L7F0D6404
   sw    $t7, 0x28c($sp)
  or    $t8, $t3, $s7
  b     .L7F0D6458
   sh    $t8, 0x20a($sp)
.L7F0D6404:
  lw    $t5, 0x28c($sp)
  lbu   $t1, 0x287($sp)
  li    $at, 1
  addiu $t4, $t5, 8
  bne   $t1, $at, .L7F0D6428
   sw    $t4, 0x28c($sp)
  lhu   $t6, 0x296($sp)
  b     .L7F0D6430
   sw    $t6, 0x48($sp)
.L7F0D6428:
  lhu   $t0, 0x294($sp)
  sw    $t0, 0x48($sp)
.L7F0D6430:
  lui   $t7, %hi(ptr_spectrum_roms) 
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  lhu   $t2, 0x298($sp)
  lw    $t8, 0x48($sp)
  addu  $t9, $t2, $t7
  lb    $t3, ($t9)
  addiu $t4, $t2, 1
  sh    $t4, 0x298($sp)
  addu  $t5, $t3, $t8
  sh    $t5, 0x20a($sp)
.L7F0D6458:
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  lhu   $t1, 0x20a($sp)
  addu  $t0, $t1, $t6
  b     .L7F0E27FC
   lbu   $s3, ($t0)
spectrum_op_4F:
  lw    $t7, 0x28c($sp)
  andi  $s3, $s0, 0xff
  addiu $t9, $t7, 4
  b     .L7F0E27FC
   sw    $t9, 0x28c($sp)
spectrum_op_50:
  lw    $t3, 0x28c($sp)
  andi  $s4, $s2, 0xff
  addiu $t8, $t3, 4
  b     .L7F0E27FC
   sw    $t8, 0x28c($sp)
spectrum_op_51:
  lw    $t5, 0x28c($sp)
  andi  $s4, $s3, 0xff
  addiu $t2, $t5, 4
  b     .L7F0E27FC
   sw    $t2, 0x28c($sp)
spectrum_op_52:
  lw    $t4, 0x28c($sp)
  addiu $t1, $t4, 4
  b     .L7F0E27FC
   sw    $t1, 0x28c($sp)
spectrum_op_53:
  lw    $t6, 0x28c($sp)
  andi  $s4, $s5, 0xff
  addiu $t0, $t6, 4
  b     .L7F0E27FC
   sw    $t0, 0x28c($sp)
spectrum_op_54:
  lw    $t7, 0x28c($sp)
  lbu   $t3, 0x287($sp)
  lbu   $t8, 0x287($sp)
  addiu $t9, $t7, 4
  bnez  $t3, .L7F0D64F0
   sw    $t9, 0x28c($sp)
  b     .L7F0E27FC
   andi  $s4, $s6, 0xff
.L7F0D64F0:
  li    $at, 1
  bne   $t8, $at, .L7F0D650C
   lhu   $t4, 0x294($sp)
  lhu   $t5, 0x296($sp)
  sra   $t2, $t5, 8
  b     .L7F0D6514
   sw    $t2, 0x48($sp)
.L7F0D650C:
  sra   $t1, $t4, 8
  sw    $t1, 0x48($sp)
.L7F0D6514:
  b     .L7F0E27FC
   lbu   $s4, 0x4b($sp)
spectrum_op_55:
  lw    $t6, 0x28c($sp)
  lbu   $t7, 0x287($sp)
  lbu   $t9, 0x287($sp)
  addiu $t0, $t6, 4
  bnez  $t7, .L7F0D653C
   sw    $t0, 0x28c($sp)
  b     .L7F0E27FC
   andi  $s4, $s7, 0xff
.L7F0D653C:
  li    $at, 1
  bne   $t9, $at, .L7F0D6558
   lhu   $t5, 0x294($sp)
  lhu   $t3, 0x296($sp)
  andi  $t8, $t3, 0xff
  b     .L7F0D6560
   sw    $t8, 0x48($sp)
.L7F0D6558:
  andi  $t2, $t5, 0xff
  sw    $t2, 0x48($sp)
.L7F0D6560:
  b     .L7F0E27FC
   lbu   $s4, 0x4b($sp)
spectrum_op_56:
  lw    $t4, 0x28c($sp)
  lbu   $t6, 0x287($sp)
  sll   $t0, $s6, 8
  addiu $t1, $t4, 7
  bnez  $t6, .L7F0D658C
   sw    $t1, 0x28c($sp)
  or    $t7, $t0, $s7
  b     .L7F0D65E0
   sh    $t7, 0x208($sp)
.L7F0D658C:
  lw    $t9, 0x28c($sp)
  lbu   $t8, 0x287($sp)
  li    $at, 1
  addiu $t3, $t9, 8
  bne   $t8, $at, .L7F0D65B0
   sw    $t3, 0x28c($sp)
  lhu   $t5, 0x296($sp)
  b     .L7F0D65B8
   sw    $t5, 0x48($sp)
.L7F0D65B0:
  lhu   $t2, 0x294($sp)
  sw    $t2, 0x48($sp)
.L7F0D65B8:
  lui   $t1, %hi(ptr_spectrum_roms) 
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  lhu   $t4, 0x298($sp)
  lw    $t7, 0x48($sp)
  addu  $t6, $t4, $t1
  lb    $t0, ($t6)
  addiu $t3, $t4, 1
  sh    $t3, 0x298($sp)
  addu  $t9, $t0, $t7
  sh    $t9, 0x208($sp)
.L7F0D65E0:
  lui   $t5, %hi(ptr_spectrum_roms) 
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  lhu   $t8, 0x208($sp)
  addu  $t2, $t8, $t5
  b     .L7F0E27FC
   lbu   $s4, ($t2)
spectrum_op_57:
  lw    $t1, 0x28c($sp)
  andi  $s4, $s0, 0xff
  addiu $t6, $t1, 4
  b     .L7F0E27FC
   sw    $t6, 0x28c($sp)
spectrum_op_58:
  lw    $t0, 0x28c($sp)
  andi  $s5, $s2, 0xff
  addiu $t7, $t0, 4
  b     .L7F0E27FC
   sw    $t7, 0x28c($sp)
spectrum_op_59:
  lw    $t9, 0x28c($sp)
  andi  $s5, $s3, 0xff
  addiu $t4, $t9, 4
  b     .L7F0E27FC
   sw    $t4, 0x28c($sp)
spectrum_op_5A:
  lw    $t3, 0x28c($sp)
  andi  $s5, $s4, 0xff
  addiu $t8, $t3, 4
  b     .L7F0E27FC
   sw    $t8, 0x28c($sp)
spectrum_op_5B:
  lw    $t5, 0x28c($sp)
  addiu $t2, $t5, 4
  b     .L7F0E27FC
   sw    $t2, 0x28c($sp)
spectrum_op_5C:
  lw    $t1, 0x28c($sp)
  lbu   $t0, 0x287($sp)
  lbu   $t7, 0x287($sp)
  addiu $t6, $t1, 4
  bnez  $t0, .L7F0D6678
   sw    $t6, 0x28c($sp)
  b     .L7F0E27FC
   andi  $s5, $s6, 0xff
.L7F0D6678:
  li    $at, 1
  bne   $t7, $at, .L7F0D6694
   lhu   $t3, 0x294($sp)
  lhu   $t9, 0x296($sp)
  sra   $t4, $t9, 8
  b     .L7F0D669C
   sw    $t4, 0x48($sp)
.L7F0D6694:
  sra   $t8, $t3, 8
  sw    $t8, 0x48($sp)
.L7F0D669C:
  b     .L7F0E27FC
   lbu   $s5, 0x4b($sp)
spectrum_op_5D:
  lw    $t5, 0x28c($sp)
  lbu   $t1, 0x287($sp)
  lbu   $t6, 0x287($sp)
  addiu $t2, $t5, 4
  bnez  $t1, .L7F0D66C4
   sw    $t2, 0x28c($sp)
  b     .L7F0E27FC
   andi  $s5, $s7, 0xff
.L7F0D66C4:
  li    $at, 1
  bne   $t6, $at, .L7F0D66E0
   lhu   $t9, 0x294($sp)
  lhu   $t0, 0x296($sp)
  andi  $t7, $t0, 0xff
  b     .L7F0D66E8
   sw    $t7, 0x48($sp)
.L7F0D66E0:
  andi  $t4, $t9, 0xff
  sw    $t4, 0x48($sp)
.L7F0D66E8:
  b     .L7F0E27FC
   lbu   $s5, 0x4b($sp)
spectrum_op_5E:
  lw    $t3, 0x28c($sp)
  lbu   $t5, 0x287($sp)
  sll   $t2, $s6, 8
  addiu $t8, $t3, 7
  bnez  $t5, .L7F0D6714
   sw    $t8, 0x28c($sp)
  or    $t1, $t2, $s7
  b     .L7F0D6768
   sh    $t1, 0x206($sp)
.L7F0D6714:
  lw    $t6, 0x28c($sp)
  lbu   $t7, 0x287($sp)
  li    $at, 1
  addiu $t0, $t6, 8
  bne   $t7, $at, .L7F0D6738
   sw    $t0, 0x28c($sp)
  lhu   $t9, 0x296($sp)
  b     .L7F0D6740
   sw    $t9, 0x48($sp)
.L7F0D6738:
  lhu   $t4, 0x294($sp)
  sw    $t4, 0x48($sp)
.L7F0D6740:
  lui   $t8, %hi(ptr_spectrum_roms) 
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  lhu   $t3, 0x298($sp)
  lw    $t1, 0x48($sp)
  addu  $t5, $t3, $t8
  lb    $t2, ($t5)
  addiu $t0, $t3, 1
  sh    $t0, 0x298($sp)
  addu  $t6, $t2, $t1
  sh    $t6, 0x206($sp)
.L7F0D6768:
  lui   $t9, %hi(ptr_spectrum_roms) 
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  lhu   $t7, 0x206($sp)
  addu  $t4, $t7, $t9
  b     .L7F0E27FC
   lbu   $s5, ($t4)
spectrum_op_5F:
  lw    $t8, 0x28c($sp)
  andi  $s5, $s0, 0xff
  addiu $t5, $t8, 4
  b     .L7F0E27FC
   sw    $t5, 0x28c($sp)
spectrum_op_60:
  lw    $t2, 0x28c($sp)
  lbu   $t6, 0x287($sp)
  lbu   $t3, 0x287($sp)
  addiu $t1, $t2, 4
  bnez  $t6, .L7F0D67B4
   sw    $t1, 0x28c($sp)
  b     .L7F0E27FC
   andi  $s6, $s2, 0xff
.L7F0D67B4:
  li    $at, 1
  bne   $t3, $at, .L7F0D67D8
   lhu   $t8, 0x294($sp)
  lhu   $t0, 0x296($sp)
  sll   $t9, $s2, 8
  andi  $t7, $t0, 0xff
  or    $t4, $t7, $t9
  b     .L7F0E27FC
   sh    $t4, 0x296($sp)
.L7F0D67D8:
  andi  $t5, $t8, 0xff
  sll   $t2, $s2, 8
  or    $t1, $t5, $t2
  b     .L7F0E27FC
   sh    $t1, 0x294($sp)
spectrum_op_61:
  lw    $t6, 0x28c($sp)
  lbu   $t0, 0x287($sp)
  lbu   $t7, 0x287($sp)
  addiu $t3, $t6, 4
  bnez  $t0, .L7F0D680C
   sw    $t3, 0x28c($sp)
  b     .L7F0E27FC
   andi  $s6, $s3, 0xff
.L7F0D680C:
  li    $at, 1
  bne   $t7, $at, .L7F0D6830
   lhu   $t2, 0x294($sp)
  lhu   $t9, 0x296($sp)
  sll   $t8, $s3, 8
  andi  $t4, $t9, 0xff
  or    $t5, $t4, $t8
  b     .L7F0E27FC
   sh    $t5, 0x296($sp)
.L7F0D6830:
  andi  $t1, $t2, 0xff
  sll   $t6, $s3, 8
  or    $t3, $t1, $t6
  b     .L7F0E27FC
   sh    $t3, 0x294($sp)
spectrum_op_62:
  lw    $t0, 0x28c($sp)
  lbu   $t9, 0x287($sp)
  lbu   $t4, 0x287($sp)
  addiu $t7, $t0, 4
  bnez  $t9, .L7F0D6864
   sw    $t7, 0x28c($sp)
  b     .L7F0E27FC
   andi  $s6, $s4, 0xff
.L7F0D6864:
  li    $at, 1
  bne   $t4, $at, .L7F0D6888
   lhu   $t6, 0x294($sp)
  lhu   $t8, 0x296($sp)
  sll   $t2, $s4, 8
  andi  $t5, $t8, 0xff
  or    $t1, $t5, $t2
  b     .L7F0E27FC
   sh    $t1, 0x296($sp)
.L7F0D6888:
  andi  $t3, $t6, 0xff
  sll   $t0, $s4, 8
  or    $t7, $t3, $t0
  b     .L7F0E27FC
   sh    $t7, 0x294($sp)
spectrum_op_63:
  lw    $t9, 0x28c($sp)
  lbu   $t8, 0x287($sp)
  lbu   $t5, 0x287($sp)
  addiu $t4, $t9, 4
  bnez  $t8, .L7F0D68BC
   sw    $t4, 0x28c($sp)
  b     .L7F0E27FC
   andi  $s6, $s5, 0xff
.L7F0D68BC:
  li    $at, 1
  bne   $t5, $at, .L7F0D68E0
   lhu   $t0, 0x294($sp)
  lhu   $t2, 0x296($sp)
  sll   $t6, $s5, 8
  andi  $t1, $t2, 0xff
  or    $t3, $t1, $t6
  b     .L7F0E27FC
   sh    $t3, 0x296($sp)
.L7F0D68E0:
  andi  $t7, $t0, 0xff
  sll   $t9, $s5, 8
  or    $t4, $t7, $t9
  b     .L7F0E27FC
   sh    $t4, 0x294($sp)
spectrum_op_64:
  lw    $t8, 0x28c($sp)
  addiu $t5, $t8, 4
  b     .L7F0E27FC
   sw    $t5, 0x28c($sp)
spectrum_op_65:
  lw    $t2, 0x28c($sp)
  lbu   $t6, 0x287($sp)
  lbu   $t5, 0x287($sp)
  addiu $t1, $t2, 4
  sltiu $t3, $t6, 1
  beqz  $t3, .L7F0D695C
   sw    $t1, 0x28c($sp)
  beqz  $t3, .L7F0D6930
   lbu   $t0, 0x287($sp)
  b     .L7F0E27FC
   andi  $s6, $s7, 0xff
.L7F0D6930:
  li    $at, 1
  bne   $t0, $at, .L7F0D694C
   lhu   $t4, 0x294($sp)
  lhu   $t7, 0x296($sp)
  andi  $t9, $t7, 0xff
  b     .L7F0D6954
   sw    $t9, 0x48($sp)
.L7F0D694C:
  andi  $t8, $t4, 0xff
  sw    $t8, 0x48($sp)
.L7F0D6954:
  b     .L7F0E27FC
   lbu   $s6, 0x4b($sp)
.L7F0D695C:
  li    $at, 1
  bne   $t5, $at, .L7F0D69C0
   lbu   $t1, 0x287($sp)
  bnez  $t5, .L7F0D6978
   lbu   $t2, 0x287($sp)
  b     .L7F0D69A4
   sw    $s7, 0x44($sp)
.L7F0D6978:
  li    $at, 1
  bne   $t2, $at, .L7F0D6994
   lhu   $t3, 0x294($sp)
  lhu   $t1, 0x296($sp)
  andi  $t6, $t1, 0xff
  b     .L7F0D699C
   sw    $t6, 0x40($sp)
.L7F0D6994:
  andi  $t0, $t3, 0xff
  sw    $t0, 0x40($sp)
.L7F0D699C:
  lw    $t7, 0x40($sp)
  sw    $t7, 0x44($sp)
.L7F0D69A4:
  lw    $t9, 0x44($sp)
  lhu   $t8, 0x296($sp)
  sll   $t4, $t9, 8
  andi  $t5, $t8, 0xff
  or    $t2, $t4, $t5
  b     .L7F0E27FC
   sh    $t2, 0x296($sp)
.L7F0D69C0:
  bnez  $t1, .L7F0D69D0
   lbu   $t6, 0x287($sp)
  b     .L7F0D69FC
   sw    $s7, 0x3c($sp)
.L7F0D69D0:
  li    $at, 1
  bne   $t6, $at, .L7F0D69EC
   lhu   $t7, 0x294($sp)
  lhu   $t3, 0x296($sp)
  andi  $t0, $t3, 0xff
  b     .L7F0D69F4
   sw    $t0, 0x38($sp)
.L7F0D69EC:
  andi  $t9, $t7, 0xff
  sw    $t9, 0x38($sp)
.L7F0D69F4:
  lw    $t8, 0x38($sp)
  sw    $t8, 0x3c($sp)
.L7F0D69FC:
  lw    $t4, 0x3c($sp)
  lhu   $t2, 0x294($sp)
  sll   $t5, $t4, 8
  andi  $t1, $t2, 0xff
  or    $t6, $t5, $t1
  b     .L7F0E27FC
   sh    $t6, 0x294($sp)
spectrum_op_66:
  lw    $t3, 0x28c($sp)
  lbu   $t7, 0x287($sp)
  sll   $t9, $s6, 8
  addiu $t0, $t3, 7
  bnez  $t7, .L7F0D6A3C
   sw    $t0, 0x28c($sp)
  or    $t8, $t9, $s7
  b     .L7F0D6A90
   sh    $t8, 0x204($sp)
.L7F0D6A3C:
  lw    $t4, 0x28c($sp)
  lbu   $t5, 0x287($sp)
  li    $at, 1
  addiu $t2, $t4, 8
  bne   $t5, $at, .L7F0D6A60
   sw    $t2, 0x28c($sp)
  lhu   $t1, 0x296($sp)
  b     .L7F0D6A68
   sw    $t1, 0x48($sp)
.L7F0D6A60:
  lhu   $t6, 0x294($sp)
  sw    $t6, 0x48($sp)
.L7F0D6A68:
  lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  lhu   $t3, 0x298($sp)
  lw    $t8, 0x48($sp)
  addu  $t7, $t3, $t0
  lb    $t9, ($t7)
  addiu $t2, $t3, 1
  sh    $t2, 0x298($sp)
  addu  $t4, $t9, $t8
  sh    $t4, 0x204($sp)
.L7F0D6A90:
  lui   $t1, %hi(ptr_spectrum_roms) 
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  lhu   $t5, 0x204($sp)
  addu  $t6, $t5, $t1
  b     .L7F0E27FC
   lbu   $s6, ($t6)
spectrum_op_67:
  lw    $t0, 0x28c($sp)
  lbu   $t9, 0x287($sp)
  lbu   $t8, 0x287($sp)
  addiu $t7, $t0, 4
  bnez  $t9, .L7F0D6AC8
   sw    $t7, 0x28c($sp)
  b     .L7F0E27FC
   andi  $s6, $s0, 0xff
.L7F0D6AC8:
  li    $at, 1
  bne   $t8, $at, .L7F0D6AEC
   lhu   $t1, 0x294($sp)
  lhu   $t4, 0x296($sp)
  sll   $t2, $s0, 8
  andi  $t3, $t4, 0xff
  or    $t5, $t3, $t2
  b     .L7F0E27FC
   sh    $t5, 0x296($sp)
.L7F0D6AEC:
  andi  $t6, $t1, 0xff
  sll   $t0, $s0, 8
  or    $t7, $t6, $t0
  b     .L7F0E27FC
   sh    $t7, 0x294($sp)
spectrum_op_68:
  lw    $t9, 0x28c($sp)
  lbu   $t4, 0x287($sp)
  lbu   $t3, 0x287($sp)
  addiu $t8, $t9, 4
  bnez  $t4, .L7F0D6B20
   sw    $t8, 0x28c($sp)
  b     .L7F0E27FC
   andi  $s7, $s2, 0xff
.L7F0D6B20:
  li    $at, 1
  bne   $t3, $at, .L7F0D6B40
   lhu   $t6, 0x294($sp)
  lhu   $t2, 0x296($sp)
  andi  $t5, $t2, 0xff00
  or    $t1, $t5, $s2
  b     .L7F0E27FC
   sh    $t1, 0x296($sp)
.L7F0D6B40:
  andi  $t0, $t6, 0xff00
  or    $t7, $t0, $s2
  b     .L7F0E27FC
   sh    $t7, 0x294($sp)
spectrum_op_69:
  lw    $t9, 0x28c($sp)
  lbu   $t4, 0x287($sp)
  lbu   $t3, 0x287($sp)
  addiu $t8, $t9, 4
  bnez  $t4, .L7F0D6B70
   sw    $t8, 0x28c($sp)
  b     .L7F0E27FC
   andi  $s7, $s3, 0xff
.L7F0D6B70:
  li    $at, 1
  bne   $t3, $at, .L7F0D6B90
   lhu   $t6, 0x294($sp)
  lhu   $t2, 0x296($sp)
  andi  $t5, $t2, 0xff00
  or    $t1, $t5, $s3
  b     .L7F0E27FC
   sh    $t1, 0x296($sp)
.L7F0D6B90:
  andi  $t0, $t6, 0xff00
  or    $t7, $t0, $s3
  b     .L7F0E27FC
   sh    $t7, 0x294($sp)
spectrum_op_6A:
  lw    $t9, 0x28c($sp)
  lbu   $t4, 0x287($sp)
  lbu   $t3, 0x287($sp)
  addiu $t8, $t9, 4
  bnez  $t4, .L7F0D6BC0
   sw    $t8, 0x28c($sp)
  b     .L7F0E27FC
   andi  $s7, $s4, 0xff
.L7F0D6BC0:
  li    $at, 1
  bne   $t3, $at, .L7F0D6BE0
   lhu   $t6, 0x294($sp)
  lhu   $t2, 0x296($sp)
  andi  $t5, $t2, 0xff00
  or    $t1, $t5, $s4
  b     .L7F0E27FC
   sh    $t1, 0x296($sp)
.L7F0D6BE0:
  andi  $t0, $t6, 0xff00
  or    $t7, $t0, $s4
  b     .L7F0E27FC
   sh    $t7, 0x294($sp)
spectrum_op_6B:
  lw    $t9, 0x28c($sp)
  lbu   $t4, 0x287($sp)
  lbu   $t3, 0x287($sp)
  addiu $t8, $t9, 4
  bnez  $t4, .L7F0D6C10
   sw    $t8, 0x28c($sp)
  b     .L7F0E27FC
   andi  $s7, $s5, 0xff
.L7F0D6C10:
  li    $at, 1
  bne   $t3, $at, .L7F0D6C30
   lhu   $t6, 0x294($sp)
  lhu   $t2, 0x296($sp)
  andi  $t5, $t2, 0xff00
  or    $t1, $t5, $s5
  b     .L7F0E27FC
   sh    $t1, 0x296($sp)
.L7F0D6C30:
  andi  $t0, $t6, 0xff00
  or    $t7, $t0, $s5
  b     .L7F0E27FC
   sh    $t7, 0x294($sp)
spectrum_op_6C:
  lw    $t9, 0x28c($sp)
  lbu   $t4, 0x287($sp)
  lbu   $t7, 0x287($sp)
  addiu $t8, $t9, 4
  sltiu $t3, $t4, 1
  beqz  $t3, .L7F0D6C98
   sw    $t8, 0x28c($sp)
  beqz  $t3, .L7F0D6C6C
   lbu   $t2, 0x287($sp)
  b     .L7F0E27FC
   andi  $s7, $s6, 0xff
.L7F0D6C6C:
  li    $at, 1
  bne   $t2, $at, .L7F0D6C88
   lhu   $t6, 0x294($sp)
  lhu   $t5, 0x296($sp)
  sra   $t1, $t5, 8
  b     .L7F0D6C90
   sw    $t1, 0x48($sp)
.L7F0D6C88:
  sra   $t0, $t6, 8
  sw    $t0, 0x48($sp)
.L7F0D6C90:
  b     .L7F0E27FC
   lbu   $s7, 0x4b($sp)
.L7F0D6C98:
  li    $at, 1
  bne   $t7, $at, .L7F0D6CF8
   lbu   $t9, 0x287($sp)
  bnez  $t7, .L7F0D6CB4
   lbu   $t9, 0x287($sp)
  b     .L7F0D6CE0
   sw    $s6, 0x44($sp)
.L7F0D6CB4:
  li    $at, 1
  bne   $t9, $at, .L7F0D6CD0
   lhu   $t3, 0x294($sp)
  lhu   $t8, 0x296($sp)
  sra   $t4, $t8, 8
  b     .L7F0D6CD8
   sw    $t4, 0x40($sp)
.L7F0D6CD0:
  sra   $t2, $t3, 8
  sw    $t2, 0x40($sp)
.L7F0D6CD8:
  lw    $t5, 0x40($sp)
  sw    $t5, 0x44($sp)
.L7F0D6CE0:
  lhu   $t6, 0x296($sp)
  lw    $t1, 0x44($sp)
  andi  $t0, $t6, 0xff00
  or    $t7, $t1, $t0
  b     .L7F0E27FC
   sh    $t7, 0x296($sp)
.L7F0D6CF8:
  bnez  $t9, .L7F0D6D08
   lbu   $t8, 0x287($sp)
  b     .L7F0D6D34
   sw    $s6, 0x3c($sp)
.L7F0D6D08:
  li    $at, 1
  bne   $t8, $at, .L7F0D6D24
   lhu   $t2, 0x294($sp)
  lhu   $t4, 0x296($sp)
  sra   $t3, $t4, 8
  b     .L7F0D6D2C
   sw    $t3, 0x38($sp)
.L7F0D6D24:
  sra   $t5, $t2, 8
  sw    $t5, 0x38($sp)
.L7F0D6D2C:
  lw    $t6, 0x38($sp)
  sw    $t6, 0x3c($sp)
.L7F0D6D34:
  lhu   $t0, 0x294($sp)
  lw    $t1, 0x3c($sp)
  andi  $t7, $t0, 0xff00
  or    $t9, $t1, $t7
  b     .L7F0E27FC
   sh    $t9, 0x294($sp)
spectrum_op_6D:
  lw    $t8, 0x28c($sp)
  addiu $t4, $t8, 4
  b     .L7F0E27FC
   sw    $t4, 0x28c($sp)
spectrum_op_6E:
  lw    $t3, 0x28c($sp)
  lbu   $t5, 0x287($sp)
  sll   $t6, $s6, 8
  addiu $t2, $t3, 7
  bnez  $t5, .L7F0D6D80
   sw    $t2, 0x28c($sp)
  or    $t0, $t6, $s7
  b     .L7F0D6DD4
   sh    $t0, 0x202($sp)
.L7F0D6D80:
  lw    $t1, 0x28c($sp)
  lbu   $t9, 0x287($sp)
  li    $at, 1
  addiu $t7, $t1, 8
  bne   $t9, $at, .L7F0D6DA4
   sw    $t7, 0x28c($sp)
  lhu   $t8, 0x296($sp)
  b     .L7F0D6DAC
   sw    $t8, 0x48($sp)
.L7F0D6DA4:
  lhu   $t4, 0x294($sp)
  sw    $t4, 0x48($sp)
.L7F0D6DAC:
  lui   $t2, %hi(ptr_spectrum_roms) 
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  lhu   $t3, 0x298($sp)
  lw    $t0, 0x48($sp)
  addu  $t5, $t3, $t2
  lb    $t6, ($t5)
  addiu $t7, $t3, 1
  sh    $t7, 0x298($sp)
  addu  $t1, $t6, $t0
  sh    $t1, 0x202($sp)
.L7F0D6DD4:
  lui   $t8, %hi(ptr_spectrum_roms) 
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  lhu   $t9, 0x202($sp)
  addu  $t4, $t9, $t8
  b     .L7F0E27FC
   lbu   $s7, ($t4)
spectrum_op_6F:
  lw    $t2, 0x28c($sp)
  lbu   $t6, 0x287($sp)
  lbu   $t0, 0x287($sp)
  addiu $t5, $t2, 4
  bnez  $t6, .L7F0D6E0C
   sw    $t5, 0x28c($sp)
  b     .L7F0E27FC
   andi  $s7, $s0, 0xff
.L7F0D6E0C:
  li    $at, 1
  bne   $t0, $at, .L7F0D6E2C
   lhu   $t9, 0x294($sp)
  lhu   $t1, 0x296($sp)
  andi  $t3, $t1, 0xff00
  or    $t7, $t3, $s0
  b     .L7F0E27FC
   sh    $t7, 0x296($sp)
.L7F0D6E2C:
  andi  $t8, $t9, 0xff00
  or    $t4, $t8, $s0
  b     .L7F0E27FC
   sh    $t4, 0x294($sp)
spectrum_op_70:
  lw    $t2, 0x28c($sp)
  lbu   $t6, 0x287($sp)
  sll   $t0, $s6, 8
  addiu $t5, $t2, 7
  bnez  $t6, .L7F0D6E60
   sw    $t5, 0x28c($sp)
  or    $t1, $t0, $s7
  b     .L7F0D6EB4
   sh    $t1, 0x200($sp)
.L7F0D6E60:
  lw    $t3, 0x28c($sp)
  lbu   $t9, 0x287($sp)
  li    $at, 1
  addiu $t7, $t3, 8
  bne   $t9, $at, .L7F0D6E84
   sw    $t7, 0x28c($sp)
  lhu   $t8, 0x296($sp)
  b     .L7F0D6E8C
   sw    $t8, 0x48($sp)
.L7F0D6E84:
  lhu   $t4, 0x294($sp)
  sw    $t4, 0x48($sp)
.L7F0D6E8C:
  lui   $t5, %hi(ptr_spectrum_roms) 
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  lhu   $t2, 0x298($sp)
  lw    $t1, 0x48($sp)
  addu  $t6, $t2, $t5
  lb    $t0, ($t6)
  addiu $t7, $t2, 1
  sh    $t7, 0x298($sp)
  addu  $t3, $t0, $t1
  sh    $t3, 0x200($sp)
.L7F0D6EB4:
  lhu   $t9, 0x200($sp)
  lhu   $t5, 0x200($sp)
  lui   $t8, %hi(ptr_spectrum_roms) 
  slti  $at, $t9, 0x5b00
  bnezl $at, .L7F0D6EE0
   slti  $at, $t5, 0x5800
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  addu  $t4, $t8, $t9
  b     .L7F0E27FC
   sb    $s2, ($t4)
  slti  $at, $t5, 0x5800
.L7F0D6EE0:
  bnez  $at, .L7F0D6F14
   lhu   $t8, 0x200($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  lui   $t3, %hi(ptr_300alloc) 
  li    $t1, 1
  addu  $t0, $t6, $t5
  sb    $s2, ($t0)
  lhu   $t2, 0x200($sp)
  lw    $t3, %lo(ptr_300alloc)($t3)
  addu  $t7, $t3, $t2
  b     .L7F0E27FC
   sb    $t1, -0x5800($t7)
.L7F0D6F14:
  slti  $at, $t8, 0x4000
  bnez  $at, .L7F0E27FC
   lui   $t9, %hi(ptr_spectrum_roms) 
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  lui   $t7, %hi(ptr_300alloc) 
  li    $t6, 1
  addu  $t4, $t9, $t8
  sb    $s2, ($t4)
  lhu   $t5, 0x200($sp)
  lw    $t7, %lo(ptr_300alloc)($t7)
  andi  $t0, $t5, 0x1800
  sra   $t3, $t0, 3
  andi  $t2, $t5, 0xff
  or    $t1, $t3, $t2
  addu  $t9, $t7, $t1
  b     .L7F0E27FC
   sb    $t6, ($t9)
spectrum_op_71:
  lw    $t8, 0x28c($sp)
  lbu   $t0, 0x287($sp)
  sll   $t5, $s6, 8
  addiu $t4, $t8, 7
  bnez  $t0, .L7F0D6F7C
   sw    $t4, 0x28c($sp)
  or    $t3, $t5, $s7
  b     .L7F0D6FD0
   sh    $t3, 0x1fe($sp)
.L7F0D6F7C:
  lw    $t2, 0x28c($sp)
  lbu   $t1, 0x287($sp)
  li    $at, 1
  addiu $t7, $t2, 8
  bne   $t1, $at, .L7F0D6FA0
   sw    $t7, 0x28c($sp)
  lhu   $t6, 0x296($sp)
  b     .L7F0D6FA8
   sw    $t6, 0x48($sp)
.L7F0D6FA0:
  lhu   $t9, 0x294($sp)
  sw    $t9, 0x48($sp)
.L7F0D6FA8:
  lui   $t4, %hi(ptr_spectrum_roms) 
  lw    $t4, %lo(ptr_spectrum_roms)($t4)
  lhu   $t8, 0x298($sp)
  lw    $t3, 0x48($sp)
  addu  $t0, $t8, $t4
  lb    $t5, ($t0)
  addiu $t7, $t8, 1
  sh    $t7, 0x298($sp)
  addu  $t2, $t5, $t3
  sh    $t2, 0x1fe($sp)
.L7F0D6FD0:
  lhu   $t1, 0x1fe($sp)
  lhu   $t4, 0x1fe($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  slti  $at, $t1, 0x5b00
  bnezl $at, .L7F0D6FFC
   slti  $at, $t4, 0x5800
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  addu  $t9, $t6, $t1
  b     .L7F0E27FC
   sb    $s3, ($t9)
  slti  $at, $t4, 0x5800
.L7F0D6FFC:
  bnez  $at, .L7F0D7030
   lhu   $t6, 0x1fe($sp)
  lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  lui   $t2, %hi(ptr_300alloc) 
  li    $t3, 1
  addu  $t5, $t0, $t4
  sb    $s3, ($t5)
  lhu   $t8, 0x1fe($sp)
  lw    $t2, %lo(ptr_300alloc)($t2)
  addu  $t7, $t2, $t8
  b     .L7F0E27FC
   sb    $t3, -0x5800($t7)
.L7F0D7030:
  slti  $at, $t6, 0x4000
  bnez  $at, .L7F0E27FC
   lui   $t1, %hi(ptr_spectrum_roms) 
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  lui   $t7, %hi(ptr_300alloc) 
  li    $t0, 1
  addu  $t9, $t1, $t6
  sb    $s3, ($t9)
  lhu   $t4, 0x1fe($sp)
  lw    $t7, %lo(ptr_300alloc)($t7)
  andi  $t5, $t4, 0x1800
  sra   $t2, $t5, 3
  andi  $t8, $t4, 0xff
  or    $t3, $t2, $t8
  addu  $t1, $t7, $t3
  b     .L7F0E27FC
   sb    $t0, ($t1)
spectrum_op_72:
  lw    $t6, 0x28c($sp)
  lbu   $t5, 0x287($sp)
  sll   $t4, $s6, 8
  addiu $t9, $t6, 7
  bnez  $t5, .L7F0D7098
   sw    $t9, 0x28c($sp)
  or    $t2, $t4, $s7
  b     .L7F0D70EC
   sh    $t2, 0x1fc($sp)
.L7F0D7098:
  lw    $t8, 0x28c($sp)
  lbu   $t3, 0x287($sp)
  li    $at, 1
  addiu $t7, $t8, 8
  bne   $t3, $at, .L7F0D70BC
   sw    $t7, 0x28c($sp)
  lhu   $t0, 0x296($sp)
  b     .L7F0D70C4
   sw    $t0, 0x48($sp)
.L7F0D70BC:
  lhu   $t1, 0x294($sp)
  sw    $t1, 0x48($sp)
.L7F0D70C4:
  lui   $t9, %hi(ptr_spectrum_roms) 
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  lhu   $t6, 0x298($sp)
  lw    $t2, 0x48($sp)
  addu  $t5, $t6, $t9
  lb    $t4, ($t5)
  addiu $t7, $t6, 1
  sh    $t7, 0x298($sp)
  addu  $t8, $t4, $t2
  sh    $t8, 0x1fc($sp)
.L7F0D70EC:
  lhu   $t3, 0x1fc($sp)
  lhu   $t9, 0x1fc($sp)
  lui   $t0, %hi(ptr_spectrum_roms) 
  slti  $at, $t3, 0x5b00
  bnezl $at, .L7F0D7118
   slti  $at, $t9, 0x5800
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  addu  $t1, $t0, $t3
  b     .L7F0E27FC
   sb    $s4, ($t1)
  slti  $at, $t9, 0x5800
.L7F0D7118:
  bnez  $at, .L7F0D714C
   lhu   $t0, 0x1fc($sp)
  lui   $t5, %hi(ptr_spectrum_roms) 
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  lui   $t8, %hi(ptr_300alloc) 
  li    $t2, 1
  addu  $t4, $t5, $t9
  sb    $s4, ($t4)
  lhu   $t6, 0x1fc($sp)
  lw    $t8, %lo(ptr_300alloc)($t8)
  addu  $t7, $t8, $t6
  b     .L7F0E27FC
   sb    $t2, -0x5800($t7)
.L7F0D714C:
  slti  $at, $t0, 0x4000
  bnez  $at, .L7F0E27FC
   lui   $t3, %hi(ptr_spectrum_roms) 
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  lui   $t7, %hi(ptr_300alloc) 
  li    $t5, 1
  addu  $t1, $t3, $t0
  sb    $s4, ($t1)
  lhu   $t9, 0x1fc($sp)
  lw    $t7, %lo(ptr_300alloc)($t7)
  andi  $t4, $t9, 0x1800
  sra   $t8, $t4, 3
  andi  $t6, $t9, 0xff
  or    $t2, $t8, $t6
  addu  $t3, $t7, $t2
  b     .L7F0E27FC
   sb    $t5, ($t3)
spectrum_op_73:
  lw    $t0, 0x28c($sp)
  lbu   $t4, 0x287($sp)
  sll   $t9, $s6, 8
  addiu $t1, $t0, 7
  bnez  $t4, .L7F0D71B4
   sw    $t1, 0x28c($sp)
  or    $t8, $t9, $s7
  b     .L7F0D7208
   sh    $t8, 0x1fa($sp)
.L7F0D71B4:
  lw    $t6, 0x28c($sp)
  lbu   $t2, 0x287($sp)
  li    $at, 1
  addiu $t7, $t6, 8
  bne   $t2, $at, .L7F0D71D8
   sw    $t7, 0x28c($sp)
  lhu   $t5, 0x296($sp)
  b     .L7F0D71E0
   sw    $t5, 0x48($sp)
.L7F0D71D8:
  lhu   $t3, 0x294($sp)
  sw    $t3, 0x48($sp)
.L7F0D71E0:
  lui   $t1, %hi(ptr_spectrum_roms) 
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  lhu   $t0, 0x298($sp)
  lw    $t8, 0x48($sp)
  addu  $t4, $t0, $t1
  lb    $t9, ($t4)
  addiu $t7, $t0, 1
  sh    $t7, 0x298($sp)
  addu  $t6, $t9, $t8
  sh    $t6, 0x1fa($sp)
.L7F0D7208:
  lhu   $t2, 0x1fa($sp)
  lhu   $t1, 0x1fa($sp)
  lui   $t5, %hi(ptr_spectrum_roms) 
  slti  $at, $t2, 0x5b00
  bnezl $at, .L7F0D7234
   slti  $at, $t1, 0x5800
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  addu  $t3, $t5, $t2
  b     .L7F0E27FC
   sb    $s5, ($t3)
  slti  $at, $t1, 0x5800
.L7F0D7234:
  bnez  $at, .L7F0D7268
   lhu   $t5, 0x1fa($sp)
  lui   $t4, %hi(ptr_spectrum_roms) 
  lw    $t4, %lo(ptr_spectrum_roms)($t4)
  lui   $t6, %hi(ptr_300alloc) 
  li    $t8, 1
  addu  $t9, $t4, $t1
  sb    $s5, ($t9)
  lhu   $t0, 0x1fa($sp)
  lw    $t6, %lo(ptr_300alloc)($t6)
  addu  $t7, $t6, $t0
  b     .L7F0E27FC
   sb    $t8, -0x5800($t7)
.L7F0D7268:
  slti  $at, $t5, 0x4000
  bnez  $at, .L7F0E27FC
   lui   $t2, %hi(ptr_spectrum_roms) 
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  lui   $t7, %hi(ptr_300alloc) 
  li    $t4, 1
  addu  $t3, $t2, $t5
  sb    $s5, ($t3)
  lhu   $t1, 0x1fa($sp)
  lw    $t7, %lo(ptr_300alloc)($t7)
  andi  $t9, $t1, 0x1800
  sra   $t6, $t9, 3
  andi  $t0, $t1, 0xff
  or    $t8, $t6, $t0
  addu  $t2, $t7, $t8
  b     .L7F0E27FC
   sb    $t4, ($t2)
spectrum_op_74:
  lw    $t5, 0x28c($sp)
  lbu   $t9, 0x287($sp)
  sll   $t1, $s6, 8
  addiu $t3, $t5, 7
  bnez  $t9, .L7F0D72D0
   sw    $t3, 0x28c($sp)
  or    $t6, $t1, $s7
  b     .L7F0D7324
   sh    $t6, 0x1f8($sp)
.L7F0D72D0:
  lw    $t0, 0x28c($sp)
  lbu   $t8, 0x287($sp)
  li    $at, 1
  addiu $t7, $t0, 8
  bne   $t8, $at, .L7F0D72F4
   sw    $t7, 0x28c($sp)
  lhu   $t4, 0x296($sp)
  b     .L7F0D72FC
   sw    $t4, 0x48($sp)
.L7F0D72F4:
  lhu   $t2, 0x294($sp)
  sw    $t2, 0x48($sp)
.L7F0D72FC:
  lui   $t3, %hi(ptr_spectrum_roms) 
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  lhu   $t5, 0x298($sp)
  lw    $t6, 0x48($sp)
  addu  $t9, $t5, $t3
  lb    $t1, ($t9)
  addiu $t7, $t5, 1
  sh    $t7, 0x298($sp)
  addu  $t0, $t1, $t6
  sh    $t0, 0x1f8($sp)
.L7F0D7324:
  lhu   $t8, 0x1f8($sp)
  lhu   $t3, 0x1f8($sp)
  lui   $t4, %hi(ptr_spectrum_roms) 
  slti  $at, $t8, 0x5b00
  bnezl $at, .L7F0D7350
   slti  $at, $t3, 0x5800
  lw    $t4, %lo(ptr_spectrum_roms)($t4)
  addu  $t2, $t4, $t8
  b     .L7F0E27FC
   sb    $s6, ($t2)
  slti  $at, $t3, 0x5800
.L7F0D7350:
  bnez  $at, .L7F0D7384
   lhu   $t4, 0x1f8($sp)
  lui   $t9, %hi(ptr_spectrum_roms) 
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  lui   $t0, %hi(ptr_300alloc) 
  li    $t6, 1
  addu  $t1, $t9, $t3
  sb    $s6, ($t1)
  lhu   $t5, 0x1f8($sp)
  lw    $t0, %lo(ptr_300alloc)($t0)
  addu  $t7, $t0, $t5
  b     .L7F0E27FC
   sb    $t6, -0x5800($t7)
.L7F0D7384:
  slti  $at, $t4, 0x4000
  bnez  $at, .L7F0E27FC
   lui   $t8, %hi(ptr_spectrum_roms) 
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  lui   $t7, %hi(ptr_300alloc) 
  li    $t9, 1
  addu  $t2, $t8, $t4
  sb    $s6, ($t2)
  lhu   $t3, 0x1f8($sp)
  lw    $t7, %lo(ptr_300alloc)($t7)
  andi  $t1, $t3, 0x1800
  sra   $t0, $t1, 3
  andi  $t5, $t3, 0xff
  or    $t6, $t0, $t5
  addu  $t8, $t7, $t6
  b     .L7F0E27FC
   sb    $t9, ($t8)
spectrum_op_75:
  lw    $t4, 0x28c($sp)
  lbu   $t1, 0x287($sp)
  sll   $t3, $s6, 8
  addiu $t2, $t4, 7
  bnez  $t1, .L7F0D73EC
   sw    $t2, 0x28c($sp)
  or    $t0, $t3, $s7
  b     .L7F0D7440
   sh    $t0, 0x1f6($sp)
.L7F0D73EC:
  lw    $t5, 0x28c($sp)
  lbu   $t6, 0x287($sp)
  li    $at, 1
  addiu $t7, $t5, 8
  bne   $t6, $at, .L7F0D7410
   sw    $t7, 0x28c($sp)
  lhu   $t9, 0x296($sp)
  b     .L7F0D7418
   sw    $t9, 0x48($sp)
.L7F0D7410:
  lhu   $t8, 0x294($sp)
  sw    $t8, 0x48($sp)
.L7F0D7418:
  lui   $t2, %hi(ptr_spectrum_roms) 
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  lhu   $t4, 0x298($sp)
  lw    $t0, 0x48($sp)
  addu  $t1, $t4, $t2
  lb    $t3, ($t1)
  addiu $t7, $t4, 1
  sh    $t7, 0x298($sp)
  addu  $t5, $t3, $t0
  sh    $t5, 0x1f6($sp)
.L7F0D7440:
  lhu   $t6, 0x1f6($sp)
  lhu   $t2, 0x1f6($sp)
  lui   $t9, %hi(ptr_spectrum_roms) 
  slti  $at, $t6, 0x5b00
  bnezl $at, .L7F0D746C
   slti  $at, $t2, 0x5800
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  addu  $t8, $t9, $t6
  b     .L7F0E27FC
   sb    $s7, ($t8)
  slti  $at, $t2, 0x5800
.L7F0D746C:
  bnez  $at, .L7F0D74A0
   lhu   $t9, 0x1f6($sp)
  lui   $t1, %hi(ptr_spectrum_roms) 
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  lui   $t5, %hi(ptr_300alloc) 
  li    $t0, 1
  addu  $t3, $t1, $t2
  sb    $s7, ($t3)
  lhu   $t4, 0x1f6($sp)
  lw    $t5, %lo(ptr_300alloc)($t5)
  addu  $t7, $t5, $t4
  b     .L7F0E27FC
   sb    $t0, -0x5800($t7)
.L7F0D74A0:
  slti  $at, $t9, 0x4000
  bnez  $at, .L7F0E27FC
   lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  lui   $t7, %hi(ptr_300alloc) 
  li    $t1, 1
  addu  $t8, $t6, $t9
  sb    $s7, ($t8)
  lhu   $t2, 0x1f6($sp)
  lw    $t7, %lo(ptr_300alloc)($t7)
  andi  $t3, $t2, 0x1800
  sra   $t5, $t3, 3
  andi  $t4, $t2, 0xff
  or    $t0, $t5, $t4
  addu  $t6, $t7, $t0
  b     .L7F0E27FC
   sb    $t1, ($t6)
spectrum_op_76:
  lw    $t9, 0x28c($sp)
  lw    $t3, 0x280($sp)
  addiu $t8, $t9, 4
  sltu  $at, $t8, $t3
  beqz  $at, .L7F0D7514
   sw    $t8, 0x28c($sp)
  subu  $t2, $t3, $t8
  addiu $t5, $t2, 3
  li    $at, -4
  and   $t4, $t5, $at
  addu  $t7, $t8, $t4
  sw    $t7, 0x28c($sp)
.L7F0D7514:
  lhu   $t0, 0x298($sp)
  addiu $t1, $t0, -1
  b     .L7F0E27FC
   sh    $t1, 0x298($sp)
spectrum_op_77:
  lw    $t6, 0x28c($sp)
  lbu   $t3, 0x287($sp)
  sll   $t2, $s6, 8
  addiu $t9, $t6, 7
  bnez  $t3, .L7F0D7548
   sw    $t9, 0x28c($sp)
  or    $t5, $t2, $s7
  b     .L7F0D759C
   sh    $t5, 0x1f4($sp)
.L7F0D7548:
  lw    $t8, 0x28c($sp)
  lbu   $t7, 0x287($sp)
  li    $at, 1
  addiu $t4, $t8, 8
  bne   $t7, $at, .L7F0D756C
   sw    $t4, 0x28c($sp)
  lhu   $t0, 0x296($sp)
  b     .L7F0D7574
   sw    $t0, 0x48($sp)
.L7F0D756C:
  lhu   $t1, 0x294($sp)
  sw    $t1, 0x48($sp)
.L7F0D7574:
  lui   $t9, %hi(ptr_spectrum_roms) 
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  lhu   $t6, 0x298($sp)
  lw    $t5, 0x48($sp)
  addu  $t3, $t6, $t9
  lb    $t2, ($t3)
  addiu $t4, $t6, 1
  sh    $t4, 0x298($sp)
  addu  $t8, $t2, $t5
  sh    $t8, 0x1f4($sp)
.L7F0D759C:
  lhu   $t7, 0x1f4($sp)
  lhu   $t9, 0x1f4($sp)
  lui   $t0, %hi(ptr_spectrum_roms) 
  slti  $at, $t7, 0x5b00
  bnezl $at, .L7F0D75C8
   slti  $at, $t9, 0x5800
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  addu  $t1, $t0, $t7
  b     .L7F0E27FC
   sb    $s0, ($t1)
  slti  $at, $t9, 0x5800
.L7F0D75C8:
  bnez  $at, .L7F0D75FC
   lhu   $t0, 0x1f4($sp)
  lui   $t3, %hi(ptr_spectrum_roms) 
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  lui   $t8, %hi(ptr_300alloc) 
  li    $t5, 1
  addu  $t2, $t3, $t9
  sb    $s0, ($t2)
  lhu   $t6, 0x1f4($sp)
  lw    $t8, %lo(ptr_300alloc)($t8)
  addu  $t4, $t8, $t6
  b     .L7F0E27FC
   sb    $t5, -0x5800($t4)
.L7F0D75FC:
  slti  $at, $t0, 0x4000
  bnez  $at, .L7F0E27FC
   lui   $t7, %hi(ptr_spectrum_roms) 
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  lui   $t4, %hi(ptr_300alloc) 
  li    $t3, 1
  addu  $t1, $t7, $t0
  sb    $s0, ($t1)
  lhu   $t9, 0x1f4($sp)
  lw    $t4, %lo(ptr_300alloc)($t4)
  andi  $t2, $t9, 0x1800
  sra   $t8, $t2, 3
  andi  $t6, $t9, 0xff
  or    $t5, $t8, $t6
  addu  $t7, $t4, $t5
  b     .L7F0E27FC
   sb    $t3, ($t7)
spectrum_op_78:
  lw    $t0, 0x28c($sp)
  andi  $s0, $s2, 0xff
  addiu $t1, $t0, 4
  b     .L7F0E27FC
   sw    $t1, 0x28c($sp)
spectrum_op_79:
  lw    $t2, 0x28c($sp)
  andi  $s0, $s3, 0xff
  addiu $t9, $t2, 4
  b     .L7F0E27FC
   sw    $t9, 0x28c($sp)
spectrum_op_7A:
  lw    $t8, 0x28c($sp)
  andi  $s0, $s4, 0xff
  addiu $t6, $t8, 4
  b     .L7F0E27FC
   sw    $t6, 0x28c($sp)
spectrum_op_7B:
  lw    $t4, 0x28c($sp)
  andi  $s0, $s5, 0xff
  addiu $t5, $t4, 4
  b     .L7F0E27FC
   sw    $t5, 0x28c($sp)
spectrum_op_7C:
  lw    $t3, 0x28c($sp)
  lbu   $t0, 0x287($sp)
  lbu   $t1, 0x287($sp)
  addiu $t7, $t3, 4
  bnez  $t0, .L7F0D76B0
   sw    $t7, 0x28c($sp)
  b     .L7F0E27FC
   andi  $s0, $s6, 0xff
.L7F0D76B0:
  li    $at, 1
  bne   $t1, $at, .L7F0D76CC
   lhu   $t8, 0x294($sp)
  lhu   $t2, 0x296($sp)
  sra   $t9, $t2, 8
  b     .L7F0D76D4
   sw    $t9, 0x48($sp)
.L7F0D76CC:
  sra   $t6, $t8, 8
  sw    $t6, 0x48($sp)
.L7F0D76D4:
  b     .L7F0E27FC
   lbu   $s0, 0x4b($sp)
spectrum_op_7D:
  lw    $t4, 0x28c($sp)
  lbu   $t3, 0x287($sp)
  lbu   $t7, 0x287($sp)
  addiu $t5, $t4, 4
  bnez  $t3, .L7F0D76FC
   sw    $t5, 0x28c($sp)
  b     .L7F0E27FC
   andi  $s0, $s7, 0xff
.L7F0D76FC:
  li    $at, 1
  bne   $t7, $at, .L7F0D7718
   lhu   $t2, 0x294($sp)
  lhu   $t0, 0x296($sp)
  andi  $t1, $t0, 0xff
  b     .L7F0D7720
   sw    $t1, 0x48($sp)
.L7F0D7718:
  andi  $t9, $t2, 0xff
  sw    $t9, 0x48($sp)
.L7F0D7720:
  b     .L7F0E27FC
   lbu   $s0, 0x4b($sp)
spectrum_op_7E:
  lw    $t8, 0x28c($sp)
  lbu   $t4, 0x287($sp)
  sll   $t5, $s6, 8
  addiu $t6, $t8, 7
  bnez  $t4, .L7F0D774C
   sw    $t6, 0x28c($sp)
  or    $t3, $t5, $s7
  b     .L7F0D77A0
   sh    $t3, 0x1f2($sp)
.L7F0D774C:
  lw    $t7, 0x28c($sp)
  lbu   $t1, 0x287($sp)
  li    $at, 1
  addiu $t0, $t7, 8
  bne   $t1, $at, .L7F0D7770
   sw    $t0, 0x28c($sp)
  lhu   $t2, 0x296($sp)
  b     .L7F0D7778
   sw    $t2, 0x48($sp)
.L7F0D7770:
  lhu   $t9, 0x294($sp)
  sw    $t9, 0x48($sp)
.L7F0D7778:
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  lhu   $t8, 0x298($sp)
  lw    $t3, 0x48($sp)
  addu  $t4, $t8, $t6
  lb    $t5, ($t4)
  addiu $t0, $t8, 1
  sh    $t0, 0x298($sp)
  addu  $t7, $t5, $t3
  sh    $t7, 0x1f2($sp)
.L7F0D77A0:
  lui   $t2, %hi(ptr_spectrum_roms) 
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  lhu   $t1, 0x1f2($sp)
  addu  $t9, $t1, $t2
  b     .L7F0E27FC
   lbu   $s0, ($t9)
spectrum_op_7F:
  lw    $t6, 0x28c($sp)
  addiu $t4, $t6, 4
  b     .L7F0E27FC
   sw    $t4, 0x28c($sp)
spectrum_op_80:
  lw    $t5, 0x28c($sp)
  andi  $t7, $s2, 0xff
  addu  $t0, $s0, $t7
  addiu $t3, $t5, 4
  andi  $t1, $t0, 0xa8
  sra   $t2, $t0, 8
  andi  $t4, $t7, 0xf
  andi  $t6, $s0, 0xf
  sw    $t3, 0x28c($sp)
  addu  $t5, $t6, $t4
  or    $t9, $t1, $t2
  li    $at, 15
  slt   $t3, $at, $t5
  not   $t2, $s0
  xor   $t5, $t0, $s0
  sh    $t0, 0x1f0($sp)
  lbu   $s0, 0x1f1($sp)
  xor   $t6, $t2, $t7
  sll   $t8, $t3, 4
  andi  $t4, $t6, 0x80
  and   $t3, $t4, $t5
  or    $t1, $t9, $t8
  sra   $t9, $t3, 5
  sltiu $t2, $s0, 1
  sll   $t6, $t2, 6
  or    $t8, $t1, $t9
  or    $s1, $t8, $t6
  andi  $t0, $s1, 0xff
  move  $s1, $t0
  sw    $t2, 0x48($sp)
  b     .L7F0E27FC
   sb    $s2, 0x1ef($sp)
spectrum_op_81:
  lw    $t4, 0x28c($sp)
  andi  $t3, $s3, 0xff
  addu  $t9, $s0, $t3
  addiu $t5, $t4, 4
  andi  $t8, $t9, 0xa8
  sra   $t2, $t9, 8
  andi  $t0, $t3, 0xf
  andi  $t6, $s0, 0xf
  sw    $t5, 0x28c($sp)
  addu  $t4, $t6, $t0
  or    $t7, $t8, $t2
  li    $at, 15
  slt   $t5, $at, $t4
  not   $t2, $s0
  xor   $t4, $t9, $s0
  sh    $t9, 0x1ec($sp)
  lbu   $s0, 0x1ed($sp)
  xor   $t6, $t2, $t3
  sll   $t1, $t5, 4
  andi  $t0, $t6, 0x80
  and   $t5, $t0, $t4
  or    $t8, $t7, $t1
  sra   $t7, $t5, 5
  sltiu $t2, $s0, 1
  sll   $t6, $t2, 6
  or    $t1, $t8, $t7
  or    $s1, $t1, $t6
  andi  $t9, $s1, 0xff
  move  $s1, $t9
  sw    $t2, 0x48($sp)
  b     .L7F0E27FC
   sb    $s3, 0x1eb($sp)
spectrum_op_82:
  lw    $t0, 0x28c($sp)
  andi  $t5, $s4, 0xff
  addu  $t7, $s0, $t5
  addiu $t4, $t0, 4
  andi  $t1, $t7, 0xa8
  sra   $t2, $t7, 8
  andi  $t9, $t5, 0xf
  andi  $t6, $s0, 0xf
  sw    $t4, 0x28c($sp)
  addu  $t0, $t6, $t9
  or    $t3, $t1, $t2
  li    $at, 15
  slt   $t4, $at, $t0
  not   $t2, $s0
  xor   $t0, $t7, $s0
  sh    $t7, 0x1e8($sp)
  lbu   $s0, 0x1e9($sp)
  xor   $t6, $t2, $t5
  sll   $t8, $t4, 4
  andi  $t9, $t6, 0x80
  and   $t4, $t9, $t0
  or    $t1, $t3, $t8
  sra   $t3, $t4, 5
  sltiu $t2, $s0, 1
  sll   $t6, $t2, 6
  or    $t8, $t1, $t3
  or    $s1, $t8, $t6
  andi  $t7, $s1, 0xff
  move  $s1, $t7
  sw    $t2, 0x48($sp)
  b     .L7F0E27FC
   sb    $s4, 0x1e7($sp)
spectrum_op_83:
  lw    $t9, 0x28c($sp)
  andi  $t4, $s5, 0xff
  addu  $t3, $s0, $t4
  addiu $t0, $t9, 4
  andi  $t8, $t3, 0xa8
  sra   $t2, $t3, 8
  andi  $t7, $t4, 0xf
  andi  $t6, $s0, 0xf
  sw    $t0, 0x28c($sp)
  addu  $t9, $t6, $t7
  or    $t5, $t8, $t2
  li    $at, 15
  slt   $t0, $at, $t9
  not   $t2, $s0
  xor   $t9, $t3, $s0
  sh    $t3, 0x1e4($sp)
  lbu   $s0, 0x1e5($sp)
  xor   $t6, $t2, $t4
  sll   $t1, $t0, 4
  andi  $t7, $t6, 0x80
  and   $t0, $t7, $t9
  or    $t8, $t5, $t1
  sra   $t5, $t0, 5
  sltiu $t2, $s0, 1
  sll   $t6, $t2, 6
  or    $t1, $t8, $t5
  or    $s1, $t1, $t6
  andi  $t3, $s1, 0xff
  move  $s1, $t3
  sw    $t2, 0x48($sp)
  b     .L7F0E27FC
   sb    $s5, 0x1e3($sp)
spectrum_op_84:
  lw    $t7, 0x28c($sp)
  lbu   $t0, 0x287($sp)
  lbu   $t8, 0x287($sp)
  addiu $t9, $t7, 4
  bnez  $t0, .L7F0D79E8
   sw    $t9, 0x28c($sp)
  b     .L7F0D7A14
   sb    $s6, 0x1df($sp)
.L7F0D79E8:
  li    $at, 1
  bne   $t8, $at, .L7F0D7A04
   lhu   $t2, 0x294($sp)
  lhu   $t5, 0x296($sp)
  sra   $t1, $t5, 8
  b     .L7F0D7A0C
   sw    $t1, 0x48($sp)
.L7F0D7A04:
  sra   $t4, $t2, 8
  sw    $t4, 0x48($sp)
.L7F0D7A0C:
  lw    $t6, 0x48($sp)
  sb    $t6, 0x1df($sp)
.L7F0D7A14:
  lbu   $t3, 0x1df($sp)
  andi  $t1, $s0, 0xf
  li    $at, 15
  addu  $t9, $s0, $t3
  andi  $t0, $t9, 0xa8
  sra   $t8, $t9, 8
  andi  $t2, $t3, 0xf
  addu  $t4, $t1, $t2
  or    $t5, $t0, $t8
  not   $t8, $s0
  slt   $t6, $at, $t4
  xor   $t4, $t9, $s0
  sh    $t9, 0x1e0($sp)
  lbu   $s0, 0x1e1($sp)
  sll   $t7, $t6, 4
  xor   $t1, $t8, $t3
  andi  $t2, $t1, 0x80
  and   $t6, $t2, $t4
  or    $t0, $t5, $t7
  sra   $t5, $t6, 5
  sltiu $t8, $s0, 1
  sll   $t1, $t8, 6
  or    $t7, $t0, $t5
  or    $s1, $t7, $t1
  andi  $t9, $s1, 0xff
  move  $s1, $t9
  b     .L7F0E27FC
   sw    $t8, 0x48($sp)
spectrum_op_85:
  lw    $t2, 0x28c($sp)
  lbu   $t6, 0x287($sp)
  lbu   $t0, 0x287($sp)
  addiu $t4, $t2, 4
  bnez  $t6, .L7F0D7AA4
   sw    $t4, 0x28c($sp)
  b     .L7F0D7AD0
   sb    $s7, 0x1db($sp)
.L7F0D7AA4:
  li    $at, 1
  bne   $t0, $at, .L7F0D7AC0
   lhu   $t8, 0x294($sp)
  lhu   $t5, 0x296($sp)
  andi  $t7, $t5, 0xff
  b     .L7F0D7AC8
   sw    $t7, 0x48($sp)
.L7F0D7AC0:
  andi  $t3, $t8, 0xff
  sw    $t3, 0x48($sp)
.L7F0D7AC8:
  lw    $t1, 0x48($sp)
  sb    $t1, 0x1db($sp)
.L7F0D7AD0:
  lbu   $t9, 0x1db($sp)
  andi  $t7, $s0, 0xf
  li    $at, 15
  addu  $t4, $s0, $t9
  andi  $t6, $t4, 0xa8
  sra   $t0, $t4, 8
  andi  $t8, $t9, 0xf
  addu  $t3, $t7, $t8
  or    $t5, $t6, $t0
  not   $t0, $s0
  slt   $t1, $at, $t3
  xor   $t3, $t4, $s0
  sh    $t4, 0x1dc($sp)
  lbu   $s0, 0x1dd($sp)
  sll   $t2, $t1, 4
  xor   $t7, $t0, $t9
  andi  $t8, $t7, 0x80
  and   $t1, $t8, $t3
  or    $t6, $t5, $t2
  sra   $t5, $t1, 5
  sltiu $t0, $s0, 1
  sll   $t7, $t0, 6
  or    $t2, $t6, $t5
  or    $s1, $t2, $t7
  andi  $t4, $s1, 0xff
  move  $s1, $t4
  b     .L7F0E27FC
   sw    $t0, 0x48($sp)
spectrum_op_86:
  lw    $t8, 0x28c($sp)
  lbu   $t1, 0x287($sp)
  sll   $t6, $s6, 8
  addiu $t3, $t8, 7
  bnez  $t1, .L7F0D7B64
   sw    $t3, 0x28c($sp)
  or    $t5, $t6, $s7
  b     .L7F0D7BB8
   sh    $t5, 0x1d8($sp)
.L7F0D7B64:
  lw    $t2, 0x28c($sp)
  lbu   $t9, 0x287($sp)
  li    $at, 1
  addiu $t0, $t2, 8
  bne   $t9, $at, .L7F0D7B88
   sw    $t0, 0x28c($sp)
  lhu   $t7, 0x296($sp)
  b     .L7F0D7B90
   sw    $t7, 0x48($sp)
.L7F0D7B88:
  lhu   $t4, 0x294($sp)
  sw    $t4, 0x48($sp)
.L7F0D7B90:
  lui   $t3, %hi(ptr_spectrum_roms) 
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  lhu   $t8, 0x298($sp)
  lw    $t5, 0x48($sp)
  addu  $t1, $t8, $t3
  lb    $t6, ($t1)
  addiu $t0, $t8, 1
  sh    $t0, 0x298($sp)
  addu  $t2, $t6, $t5
  sh    $t2, 0x1d8($sp)
.L7F0D7BB8:
  lui   $t7, %hi(ptr_spectrum_roms) 
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  lhu   $t9, 0x1d8($sp)
  li    $at, 15
  addu  $t4, $t9, $t7
  lbu   $t3, ($t4)
  andi  $t9, $s0, 0xf
  addu  $t6, $s0, $t3
  andi  $t5, $t6, 0xa8
  sra   $t2, $t6, 8
  andi  $t0, $t3, 0xf
  addu  $t7, $t9, $t0
  or    $t8, $t5, $t2
  not   $t2, $s0
  slt   $t4, $at, $t7
  xor   $t7, $t6, $s0
  sh    $t6, 0x1d6($sp)
  lbu   $s0, 0x1d7($sp)
  sll   $t1, $t4, 4
  xor   $t9, $t2, $t3
  andi  $t0, $t9, 0x80
  and   $t4, $t0, $t7
  or    $t5, $t8, $t1
  sra   $t8, $t4, 5
  sltiu $t2, $s0, 1
  sll   $t9, $t2, 6
  or    $t1, $t5, $t8
  or    $s1, $t1, $t9
  andi  $t6, $s1, 0xff
  move  $s1, $t6
  sw    $t2, 0x48($sp)
  b     .L7F0E27FC
   sb    $t3, 0x1d5($sp)
spectrum_op_87:
  lw    $t0, 0x28c($sp)
  andi  $t4, $s0, 0xff
  addu  $t8, $s0, $t4
  addiu $t7, $t0, 4
  andi  $t1, $t8, 0xa8
  sra   $t2, $t8, 8
  andi  $t6, $t4, 0xf
  andi  $t9, $s0, 0xf
  sw    $t7, 0x28c($sp)
  addu  $t0, $t9, $t6
  or    $t3, $t1, $t2
  li    $at, 15
  slt   $t7, $at, $t0
  not   $t2, $s0
  xor   $t0, $t8, $s0
  sh    $t8, 0x1d2($sp)
  sb    $s0, 0x1d1($sp)
  lbu   $s0, 0x1d3($sp)
  xor   $t9, $t2, $t4
  sll   $t5, $t7, 4
  andi  $t6, $t9, 0x80
  and   $t7, $t6, $t0
  or    $t1, $t3, $t5
  sra   $t3, $t7, 5
  sltiu $t2, $s0, 1
  sll   $t9, $t2, 6
  or    $t5, $t1, $t3
  or    $s1, $t5, $t9
  andi  $t8, $s1, 0xff
  move  $s1, $t8
  b     .L7F0E27FC
   sw    $t2, 0x48($sp)
spectrum_op_88:
  lw    $t6, 0x28c($sp)
  andi  $t7, $s2, 0xff
  addu  $t1, $s0, $t7
  andi  $t3, $s1, 1
  addu  $t5, $t1, $t3
  addiu $t0, $t6, 4
  sw    $t0, 0x28c($sp)
  andi  $t0, $s0, 0xf
  andi  $t1, $t7, 0xf
  addu  $t3, $t0, $t1
  andi  $t4, $t5, 0xa8
  sra   $t8, $t5, 8
  andi  $t2, $s1, 1
  addu  $t9, $t3, $t2
  or    $t6, $t4, $t8
  li    $at, 15
  slt   $t4, $at, $t9
  sll   $t8, $t4, 4
  move  $t9, $t5
  not   $t1, $s0
  xor   $t4, $t9, $s0
  sh    $t5, 0x1ce($sp)
  lbu   $s0, 0x1cf($sp)
  xor   $t3, $t1, $t7
  andi  $t2, $t3, 0x80
  or    $t0, $t6, $t8
  and   $t6, $t2, $t4
  sra   $t8, $t6, 5
  sltiu $t7, $s0, 1
  sll   $t5, $t7, 6
  or    $t1, $t0, $t8
  or    $s1, $t1, $t5
  andi  $t9, $s1, 0xff
  move  $s1, $t9
  sw    $t7, 0x48($sp)
  b     .L7F0E27FC
   sb    $s2, 0x1cd($sp)
spectrum_op_89:
  lw    $t2, 0x28c($sp)
  andi  $t6, $s3, 0xff
  addu  $t0, $s0, $t6
  andi  $t8, $s1, 1
  addu  $t1, $t0, $t8
  addiu $t4, $t2, 4
  sw    $t4, 0x28c($sp)
  andi  $t4, $s0, 0xf
  andi  $t0, $t6, 0xf
  addu  $t8, $t4, $t0
  andi  $t3, $t1, 0xa8
  sra   $t9, $t1, 8
  andi  $t7, $s1, 1
  addu  $t5, $t8, $t7
  or    $t2, $t3, $t9
  li    $at, 15
  slt   $t3, $at, $t5
  sll   $t9, $t3, 4
  move  $t5, $t1
  not   $t0, $s0
  xor   $t3, $t5, $s0
  sh    $t1, 0x1ca($sp)
  lbu   $s0, 0x1cb($sp)
  xor   $t8, $t0, $t6
  andi  $t7, $t8, 0x80
  or    $t4, $t2, $t9
  and   $t2, $t7, $t3
  sra   $t9, $t2, 5
  sltiu $t6, $s0, 1
  sll   $t1, $t6, 6
  or    $t0, $t4, $t9
  or    $s1, $t0, $t1
  andi  $t5, $s1, 0xff
  move  $s1, $t5
  sw    $t6, 0x48($sp)
  b     .L7F0E27FC
   sb    $s3, 0x1c9($sp)
spectrum_op_8A:
  lw    $t7, 0x28c($sp)
  andi  $t2, $s4, 0xff
  addu  $t4, $s0, $t2
  andi  $t9, $s1, 1
  addu  $t0, $t4, $t9
  addiu $t3, $t7, 4
  sw    $t3, 0x28c($sp)
  andi  $t3, $s0, 0xf
  andi  $t4, $t2, 0xf
  addu  $t9, $t3, $t4
  andi  $t8, $t0, 0xa8
  sra   $t5, $t0, 8
  andi  $t6, $s1, 1
  addu  $t1, $t9, $t6
  or    $t7, $t8, $t5
  li    $at, 15
  slt   $t8, $at, $t1
  sll   $t5, $t8, 4
  move  $t1, $t0
  not   $t4, $s0
  xor   $t8, $t1, $s0
  sh    $t0, 0x1c6($sp)
  lbu   $s0, 0x1c7($sp)
  xor   $t9, $t4, $t2
  andi  $t6, $t9, 0x80
  or    $t3, $t7, $t5
  and   $t7, $t6, $t8
  sra   $t5, $t7, 5
  sltiu $t2, $s0, 1
  sll   $t0, $t2, 6
  or    $t4, $t3, $t5
  or    $s1, $t4, $t0
  andi  $t1, $s1, 0xff
  move  $s1, $t1
  sw    $t2, 0x48($sp)
  b     .L7F0E27FC
   sb    $s4, 0x1c5($sp)
spectrum_op_8B:
  lw    $t6, 0x28c($sp)
  andi  $t7, $s5, 0xff
  addu  $t3, $s0, $t7
  andi  $t5, $s1, 1
  addu  $t4, $t3, $t5
  addiu $t8, $t6, 4
  sw    $t8, 0x28c($sp)
  andi  $t8, $s0, 0xf
  andi  $t3, $t7, 0xf
  addu  $t5, $t8, $t3
  andi  $t9, $t4, 0xa8
  sra   $t1, $t4, 8
  andi  $t2, $s1, 1
  addu  $t0, $t5, $t2
  or    $t6, $t9, $t1
  li    $at, 15
  slt   $t9, $at, $t0
  sll   $t1, $t9, 4
  move  $t0, $t4
  not   $t3, $s0
  xor   $t9, $t0, $s0
  sh    $t4, 0x1c2($sp)
  lbu   $s0, 0x1c3($sp)
  xor   $t5, $t3, $t7
  andi  $t2, $t5, 0x80
  or    $t8, $t6, $t1
  and   $t6, $t2, $t9
  sra   $t1, $t6, 5
  sltiu $t7, $s0, 1
  sll   $t4, $t7, 6
  or    $t3, $t8, $t1
  or    $s1, $t3, $t4
  andi  $t0, $s1, 0xff
  move  $s1, $t0
  sw    $t7, 0x48($sp)
  b     .L7F0E27FC
   sb    $s5, 0x1c1($sp)
spectrum_op_8C:
  lw    $t2, 0x28c($sp)
  lbu   $t6, 0x287($sp)
  lbu   $t8, 0x287($sp)
  addiu $t9, $t2, 4
  bnez  $t6, .L7F0D7F2C
   sw    $t9, 0x28c($sp)
  b     .L7F0D7F58
   sb    $s6, 0x1bd($sp)
.L7F0D7F2C:
  li    $at, 1
  bne   $t8, $at, .L7F0D7F48
   lhu   $t7, 0x294($sp)
  lhu   $t1, 0x296($sp)
  sra   $t3, $t1, 8
  b     .L7F0D7F50
   sw    $t3, 0x48($sp)
.L7F0D7F48:
  sra   $t5, $t7, 8
  sw    $t5, 0x48($sp)
.L7F0D7F50:
  lw    $t4, 0x48($sp)
  sb    $t4, 0x1bd($sp)
.L7F0D7F58:
  lbu   $t0, 0x1bd($sp)
  andi  $t9, $s1, 1
  andi  $t4, $s0, 0xf
  addu  $t2, $s0, $t0
  addu  $t6, $t2, $t9
  andi  $t2, $t0, 0xf
  addu  $t9, $t4, $t2
  andi  $t1, $t6, 0xa8
  sra   $t7, $t6, 8
  andi  $t8, $s1, 1
  addu  $t3, $t9, $t8
  or    $t5, $t1, $t7
  li    $at, 15
  slt   $t1, $at, $t3
  sll   $t7, $t1, 4
  move  $t3, $t6
  not   $t2, $s0
  xor   $t1, $t3, $s0
  sh    $t6, 0x1be($sp)
  lbu   $s0, 0x1bf($sp)
  xor   $t9, $t2, $t0
  andi  $t8, $t9, 0x80
  or    $t4, $t5, $t7
  and   $t5, $t8, $t1
  sra   $t7, $t5, 5
  sltiu $t0, $s0, 1
  sll   $t6, $t0, 6
  or    $t2, $t4, $t7
  or    $s1, $t2, $t6
  andi  $t3, $s1, 0xff
  move  $s1, $t3
  b     .L7F0E27FC
   sw    $t0, 0x48($sp)
spectrum_op_8D:
  lw    $t8, 0x28c($sp)
  lbu   $t5, 0x287($sp)
  lbu   $t4, 0x287($sp)
  addiu $t1, $t8, 4
  bnez  $t5, .L7F0D7FFC
   sw    $t1, 0x28c($sp)
  b     .L7F0D8028
   sb    $s7, 0x1b9($sp)
.L7F0D7FFC:
  li    $at, 1
  bne   $t4, $at, .L7F0D8018
   lhu   $t0, 0x294($sp)
  lhu   $t7, 0x296($sp)
  andi  $t2, $t7, 0xff
  b     .L7F0D8020
   sw    $t2, 0x48($sp)
.L7F0D8018:
  andi  $t9, $t0, 0xff
  sw    $t9, 0x48($sp)
.L7F0D8020:
  lw    $t6, 0x48($sp)
  sb    $t6, 0x1b9($sp)
.L7F0D8028:
  lbu   $t3, 0x1b9($sp)
  andi  $t1, $s1, 1
  andi  $t6, $s0, 0xf
  addu  $t8, $s0, $t3
  addu  $t5, $t8, $t1
  andi  $t8, $t3, 0xf
  addu  $t1, $t6, $t8
  andi  $t7, $t5, 0xa8
  sra   $t0, $t5, 8
  andi  $t4, $s1, 1
  addu  $t2, $t1, $t4
  or    $t9, $t7, $t0
  li    $at, 15
  slt   $t7, $at, $t2
  sll   $t0, $t7, 4
  move  $t2, $t5
  not   $t8, $s0
  xor   $t7, $t2, $s0
  sh    $t5, 0x1ba($sp)
  lbu   $s0, 0x1bb($sp)
  xor   $t1, $t8, $t3
  andi  $t4, $t1, 0x80
  or    $t6, $t9, $t0
  and   $t9, $t4, $t7
  sra   $t0, $t9, 5
  sltiu $t3, $s0, 1
  sll   $t5, $t3, 6
  or    $t8, $t6, $t0
  or    $s1, $t8, $t5
  andi  $t2, $s1, 0xff
  move  $s1, $t2
  b     .L7F0E27FC
   sw    $t3, 0x48($sp)
spectrum_op_8E:
  lw    $t4, 0x28c($sp)
  lbu   $t9, 0x287($sp)
  sll   $t6, $s6, 8
  addiu $t7, $t4, 7
  bnez  $t9, .L7F0D80D0
   sw    $t7, 0x28c($sp)
  or    $t0, $t6, $s7
  b     .L7F0D8124
   sh    $t0, 0x1b6($sp)
.L7F0D80D0:
  lw    $t8, 0x28c($sp)
  lbu   $t1, 0x287($sp)
  li    $at, 1
  addiu $t3, $t8, 8
  bne   $t1, $at, .L7F0D80F4
   sw    $t3, 0x28c($sp)
  lhu   $t5, 0x296($sp)
  b     .L7F0D80FC
   sw    $t5, 0x48($sp)
.L7F0D80F4:
  lhu   $t2, 0x294($sp)
  sw    $t2, 0x48($sp)
.L7F0D80FC:
  lui   $t7, %hi(ptr_spectrum_roms) 
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  lhu   $t4, 0x298($sp)
  lw    $t0, 0x48($sp)
  addu  $t9, $t4, $t7
  lb    $t6, ($t9)
  addiu $t3, $t4, 1
  sh    $t3, 0x298($sp)
  addu  $t8, $t6, $t0
  sh    $t8, 0x1b6($sp)
.L7F0D8124:
  lui   $t5, %hi(ptr_spectrum_roms) 
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  lhu   $t1, 0x1b6($sp)
  andi  $t6, $s1, 1
  andi  $t8, $s1, 1
  addu  $t2, $t1, $t5
  lbu   $t7, ($t2)
  li    $at, 15
  addu  $t9, $s0, $t7
  addu  $t0, $t9, $t6
  andi  $t9, $s0, 0xf
  andi  $t2, $t7, 0xf
  addu  $t6, $t9, $t2
  andi  $t4, $t0, 0xa8
  sra   $t1, $t0, 8
  or    $t5, $t4, $t1
  addu  $t3, $t6, $t8
  slt   $t4, $at, $t3
  sll   $t1, $t4, 4
  move  $t3, $t0
  not   $t2, $s0
  xor   $t4, $t3, $s0
  sh    $t0, 0x1b4($sp)
  lbu   $s0, 0x1b5($sp)
  xor   $t6, $t2, $t7
  andi  $t8, $t6, 0x80
  or    $t9, $t5, $t1
  and   $t5, $t8, $t4
  sb    $t7, 0x1b3($sp)
  sra   $t1, $t5, 5
  sltiu $t7, $s0, 1
  sll   $t0, $t7, 6
  or    $t2, $t9, $t1
  or    $s1, $t2, $t0
  andi  $t3, $s1, 0xff
  move  $s1, $t3
  b     .L7F0E27FC
   sw    $t7, 0x48($sp)
spectrum_op_8F:
  lw    $t8, 0x28c($sp)
  andi  $t5, $s0, 0xff
  addu  $t9, $s0, $t5
  andi  $t1, $s1, 1
  addu  $t2, $t9, $t1
  addiu $t4, $t8, 4
  sw    $t4, 0x28c($sp)
  andi  $t4, $s0, 0xf
  andi  $t9, $t5, 0xf
  addu  $t1, $t4, $t9
  andi  $t6, $t2, 0xa8
  sra   $t3, $t2, 8
  andi  $t7, $s1, 1
  addu  $t0, $t1, $t7
  or    $t8, $t6, $t3
  li    $at, 15
  slt   $t6, $at, $t0
  sll   $t3, $t6, 4
  move  $t0, $t2
  not   $t9, $s0
  xor   $t6, $t0, $s0
  sh    $t2, 0x1b0($sp)
  sb    $s0, 0x1af($sp)
  lbu   $s0, 0x1b1($sp)
  xor   $t1, $t9, $t5
  andi  $t7, $t1, 0x80
  or    $t4, $t8, $t3
  and   $t8, $t7, $t6
  sra   $t3, $t8, 5
  sltiu $t5, $s0, 1
  sll   $t2, $t5, 6
  or    $t9, $t4, $t3
  or    $s1, $t9, $t2
  andi  $t0, $s1, 0xff
  move  $s1, $t0
  b     .L7F0E27FC
   sw    $t5, 0x48($sp)
spectrum_op_90:
  lw    $t7, 0x28c($sp)
  andi  $t8, $s2, 0xff
  subu  $t4, $s0, $t8
  addiu $t6, $t7, 4
  andi  $t3, $t4, 0x1ff
  sw    $t6, 0x28c($sp)
  andi  $t6, $t8, 0xf
  andi  $t5, $t3, 0xa8
  sra   $t2, $t3, 8
  andi  $t7, $s0, 0xf
  slt   $t4, $t7, $t6
  or    $t0, $t5, $t2
  xor   $t5, $s0, $t8
  sll   $t9, $t4, 4
  xor   $t6, $t3, $s0
  sh    $t3, 0x1ac($sp)
  lbu   $s0, 0x1ad($sp)
  andi  $t2, $t5, 0x80
  and   $t4, $t2, $t6
  or    $t1, $t0, $t9
  sra   $t0, $t4, 5
  or    $s1, $t1, $t0
  sltiu $t5, $s0, 1
  sll   $t7, $t5, 6
  ori   $t8, $s1, 2
  or    $s1, $t8, $t7
  andi  $t2, $s1, 0xff
  move  $s1, $t2
  sw    $t5, 0x48($sp)
  b     .L7F0E27FC
   sb    $s2, 0x1ab($sp)
spectrum_op_91:
  lw    $t6, 0x28c($sp)
  andi  $t1, $s3, 0xff
  subu  $t0, $s0, $t1
  addiu $t4, $t6, 4
  andi  $t9, $t0, 0x1ff
  sw    $t4, 0x28c($sp)
  andi  $t4, $t1, 0xf
  andi  $t5, $t9, 0xa8
  sra   $t7, $t9, 8
  andi  $t6, $s0, 0xf
  slt   $t0, $t6, $t4
  or    $t2, $t5, $t7
  xor   $t5, $s0, $t1
  sll   $t8, $t0, 4
  xor   $t4, $t9, $s0
  sh    $t9, 0x1a8($sp)
  lbu   $s0, 0x1a9($sp)
  andi  $t7, $t5, 0x80
  and   $t0, $t7, $t4
  or    $t3, $t2, $t8
  sra   $t2, $t0, 5
  or    $s1, $t3, $t2
  sltiu $t5, $s0, 1
  sll   $t6, $t5, 6
  ori   $t1, $s1, 2
  or    $s1, $t1, $t6
  andi  $t7, $s1, 0xff
  move  $s1, $t7
  sw    $t5, 0x48($sp)
  b     .L7F0E27FC
   sb    $s3, 0x1a7($sp)
spectrum_op_92:
  lw    $t4, 0x28c($sp)
  andi  $t3, $s4, 0xff
  subu  $t2, $s0, $t3
  addiu $t0, $t4, 4
  andi  $t8, $t2, 0x1ff
  sw    $t0, 0x28c($sp)
  andi  $t0, $t3, 0xf
  andi  $t5, $t8, 0xa8
  sra   $t6, $t8, 8
  andi  $t4, $s0, 0xf
  slt   $t2, $t4, $t0
  or    $t7, $t5, $t6
  xor   $t5, $s0, $t3
  sll   $t1, $t2, 4
  xor   $t0, $t8, $s0
  sh    $t8, 0x1a4($sp)
  lbu   $s0, 0x1a5($sp)
  andi  $t6, $t5, 0x80
  and   $t2, $t6, $t0
  or    $t9, $t7, $t1
  sra   $t7, $t2, 5
  or    $s1, $t9, $t7
  sltiu $t5, $s0, 1
  sll   $t4, $t5, 6
  ori   $t3, $s1, 2
  or    $s1, $t3, $t4
  andi  $t6, $s1, 0xff
  move  $s1, $t6
  sw    $t5, 0x48($sp)
  b     .L7F0E27FC
   sb    $s4, 0x1a3($sp)
spectrum_op_93:
  lw    $t0, 0x28c($sp)
  andi  $t9, $s5, 0xff
  subu  $t7, $s0, $t9
  addiu $t2, $t0, 4
  andi  $t1, $t7, 0x1ff
  sw    $t2, 0x28c($sp)
  andi  $t2, $t9, 0xf
  andi  $t5, $t1, 0xa8
  sra   $t4, $t1, 8
  andi  $t0, $s0, 0xf
  slt   $t7, $t0, $t2
  or    $t6, $t5, $t4
  xor   $t5, $s0, $t9
  sll   $t3, $t7, 4
  xor   $t2, $t1, $s0
  sh    $t1, 0x1a0($sp)
  lbu   $s0, 0x1a1($sp)
  andi  $t4, $t5, 0x80
  and   $t7, $t4, $t2
  or    $t8, $t6, $t3
  sra   $t6, $t7, 5
  or    $s1, $t8, $t6
  sltiu $t5, $s0, 1
  sll   $t0, $t5, 6
  ori   $t9, $s1, 2
  or    $s1, $t9, $t0
  andi  $t4, $s1, 0xff
  move  $s1, $t4
  sw    $t5, 0x48($sp)
  b     .L7F0E27FC
   sb    $s5, 0x19f($sp)
spectrum_op_94:
  lw    $t2, 0x28c($sp)
  lbu   $t8, 0x287($sp)
  lbu   $t6, 0x287($sp)
  addiu $t7, $t2, 4
  bnez  $t8, .L7F0D8460
   sw    $t7, 0x28c($sp)
  b     .L7F0D848C
   sb    $s6, 0x19b($sp)
.L7F0D8460:
  li    $at, 1
  bne   $t6, $at, .L7F0D847C
   lhu   $t5, 0x294($sp)
  lhu   $t3, 0x296($sp)
  sra   $t9, $t3, 8
  b     .L7F0D8484
   sw    $t9, 0x48($sp)
.L7F0D847C:
  sra   $t1, $t5, 8
  sw    $t1, 0x48($sp)
.L7F0D8484:
  lw    $t0, 0x48($sp)
  sb    $t0, 0x19b($sp)
.L7F0D848C:
  lbu   $t4, 0x19b($sp)
  andi  $t1, $s0, 0xf
  subu  $t2, $s0, $t4
  andi  $t7, $t2, 0x1ff
  andi  $t6, $t7, 0xa8
  sra   $t9, $t7, 8
  andi  $t0, $t4, 0xf
  slt   $t2, $t1, $t0
  or    $t5, $t6, $t9
  xor   $t6, $s0, $t4
  sll   $t8, $t2, 4
  xor   $t0, $t7, $s0
  sh    $t7, 0x19c($sp)
  lbu   $s0, 0x19d($sp)
  andi  $t9, $t6, 0x80
  and   $t2, $t9, $t0
  or    $t3, $t5, $t8
  sra   $t5, $t2, 5
  or    $s1, $t3, $t5
  sltiu $t6, $s0, 1
  sll   $t1, $t6, 6
  ori   $t4, $s1, 2
  or    $s1, $t4, $t1
  andi  $t9, $s1, 0xff
  move  $s1, $t9
  b     .L7F0E27FC
   sw    $t6, 0x48($sp)
spectrum_op_95:
  lw    $t0, 0x28c($sp)
  lbu   $t3, 0x287($sp)
  lbu   $t5, 0x287($sp)
  addiu $t2, $t0, 4
  bnez  $t3, .L7F0D8518
   sw    $t2, 0x28c($sp)
  b     .L7F0D8544
   sb    $s7, 0x197($sp)
.L7F0D8518:
  li    $at, 1
  bne   $t5, $at, .L7F0D8534
   lhu   $t6, 0x294($sp)
  lhu   $t8, 0x296($sp)
  andi  $t4, $t8, 0xff
  b     .L7F0D853C
   sw    $t4, 0x48($sp)
.L7F0D8534:
  andi  $t7, $t6, 0xff
  sw    $t7, 0x48($sp)
.L7F0D853C:
  lw    $t1, 0x48($sp)
  sb    $t1, 0x197($sp)
.L7F0D8544:
  lbu   $t9, 0x197($sp)
  andi  $t7, $s0, 0xf
  subu  $t0, $s0, $t9
  andi  $t2, $t0, 0x1ff
  andi  $t5, $t2, 0xa8
  sra   $t4, $t2, 8
  andi  $t1, $t9, 0xf
  slt   $t0, $t7, $t1
  or    $t6, $t5, $t4
  xor   $t5, $s0, $t9
  sll   $t3, $t0, 4
  xor   $t1, $t2, $s0
  sh    $t2, 0x198($sp)
  lbu   $s0, 0x199($sp)
  andi  $t4, $t5, 0x80
  and   $t0, $t4, $t1
  or    $t8, $t6, $t3
  sra   $t6, $t0, 5
  or    $s1, $t8, $t6
  sltiu $t5, $s0, 1
  sll   $t7, $t5, 6
  ori   $t9, $s1, 2
  or    $s1, $t9, $t7
  andi  $t4, $s1, 0xff
  move  $s1, $t4
  b     .L7F0E27FC
   sw    $t5, 0x48($sp)
spectrum_op_96:
  lw    $t1, 0x28c($sp)
  lbu   $t8, 0x287($sp)
  sll   $t6, $s6, 8
  addiu $t0, $t1, 7
  bnez  $t8, .L7F0D85D4
   sw    $t0, 0x28c($sp)
  or    $t3, $t6, $s7
  b     .L7F0D8628
   sh    $t3, 0x194($sp)
.L7F0D85D4:
  lw    $t9, 0x28c($sp)
  lbu   $t2, 0x287($sp)
  li    $at, 1
  addiu $t5, $t9, 8
  bne   $t2, $at, .L7F0D85F8
   sw    $t5, 0x28c($sp)
  lhu   $t7, 0x296($sp)
  b     .L7F0D8600
   sw    $t7, 0x48($sp)
.L7F0D85F8:
  lhu   $t4, 0x294($sp)
  sw    $t4, 0x48($sp)
.L7F0D8600:
  lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  lhu   $t1, 0x298($sp)
  lw    $t3, 0x48($sp)
  addu  $t8, $t1, $t0
  lb    $t6, ($t8)
  addiu $t5, $t1, 1
  sh    $t5, 0x298($sp)
  addu  $t9, $t6, $t3
  sh    $t9, 0x194($sp)
.L7F0D8628:
  lui   $t7, %hi(ptr_spectrum_roms) 
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  lhu   $t2, 0x194($sp)
  addu  $t4, $t2, $t7
  lbu   $t0, ($t4)
  andi  $t4, $s0, 0xf
  subu  $t8, $s0, $t0
  andi  $t6, $t8, 0x1ff
  andi  $t9, $t6, 0xa8
  sra   $t5, $t6, 8
  andi  $t7, $t0, 0xf
  slt   $t8, $t4, $t7
  or    $t2, $t9, $t5
  xor   $t9, $s0, $t0
  sll   $t3, $t8, 4
  xor   $t7, $t6, $s0
  sh    $t6, 0x192($sp)
  lbu   $s0, 0x193($sp)
  andi  $t5, $t9, 0x80
  and   $t8, $t5, $t7
  or    $t1, $t2, $t3
  sra   $t2, $t8, 5
  or    $s1, $t1, $t2
  sb    $t0, 0x191($sp)
  sltiu $t9, $s0, 1
  sll   $t4, $t9, 6
  ori   $t0, $s1, 2
  or    $s1, $t0, $t4
  andi  $t5, $s1, 0xff
  move  $s1, $t5
  b     .L7F0E27FC
   sw    $t9, 0x48($sp)
spectrum_op_97:
  lw    $t7, 0x28c($sp)
  andi  $t1, $s0, 0xff
  subu  $t2, $s0, $t1
  addiu $t8, $t7, 4
  andi  $t3, $t2, 0x1ff
  sw    $t8, 0x28c($sp)
  andi  $t8, $t1, 0xf
  andi  $t9, $t3, 0xa8
  sra   $t4, $t3, 8
  andi  $t7, $s0, 0xf
  slt   $t2, $t7, $t8
  or    $t5, $t9, $t4
  xor   $t9, $s0, $t1
  sll   $t0, $t2, 4
  xor   $t8, $t3, $s0
  sh    $t3, 0x18e($sp)
  sb    $s0, 0x18d($sp)
  lbu   $s0, 0x18f($sp)
  andi  $t4, $t9, 0x80
  and   $t2, $t4, $t8
  or    $t6, $t5, $t0
  sra   $t5, $t2, 5
  or    $s1, $t6, $t5
  sltiu $t9, $s0, 1
  sll   $t7, $t9, 6
  ori   $t1, $s1, 2
  or    $s1, $t1, $t7
  andi  $t4, $s1, 0xff
  move  $s1, $t4
  b     .L7F0E27FC
   sw    $t9, 0x48($sp)
spectrum_op_98:
  andi  $t6, $s2, 0xff
  lw    $t8, 0x28c($sp)
  subu  $t5, $s0, $t6
  andi  $t0, $s1, 1
  subu  $t1, $t5, $t0
  andi  $t9, $t1, 0x1ff
  andi  $t5, $t6, 0xf
  addiu $t2, $t8, 4
  addu  $t1, $t5, $t0
  andi  $t3, $s0, 0xf
  sw    $t2, 0x28c($sp)
  slt   $t4, $t3, $t1
  sra   $t8, $t9, 8
  andi  $t7, $t9, 0xa8
  or    $t2, $t7, $t8
  xor   $t5, $s0, $t6
  sll   $t7, $t4, 4
  xor   $t1, $t9, $s0
  sh    $t9, 0x18a($sp)
  lbu   $s0, 0x18b($sp)
  andi  $t0, $t5, 0x80
  and   $t4, $t0, $t1
  or    $t8, $t2, $t7
  sra   $t2, $t4, 5
  or    $s1, $t8, $t2
  sltiu $t5, $s0, 1
  sll   $t3, $t5, 6
  ori   $t6, $s1, 2
  or    $s1, $t6, $t3
  andi  $t0, $s1, 0xff
  move  $s1, $t0
  sw    $t5, 0x48($sp)
  b     .L7F0E27FC
   sb    $s2, 0x189($sp)
spectrum_op_99:
  andi  $t8, $s3, 0xff
  lw    $t1, 0x28c($sp)
  subu  $t2, $s0, $t8
  andi  $t7, $s1, 1
  subu  $t6, $t2, $t7
  andi  $t5, $t6, 0x1ff
  andi  $t2, $t8, 0xf
  addiu $t4, $t1, 4
  addu  $t6, $t2, $t7
  andi  $t9, $s0, 0xf
  sw    $t4, 0x28c($sp)
  slt   $t0, $t9, $t6
  sra   $t1, $t5, 8
  andi  $t3, $t5, 0xa8
  or    $t4, $t3, $t1
  xor   $t2, $s0, $t8
  sll   $t3, $t0, 4
  xor   $t6, $t5, $s0
  sh    $t5, 0x186($sp)
  lbu   $s0, 0x187($sp)
  andi  $t7, $t2, 0x80
  and   $t0, $t7, $t6
  or    $t1, $t4, $t3
  sra   $t4, $t0, 5
  or    $s1, $t1, $t4
  sltiu $t2, $s0, 1
  sll   $t9, $t2, 6
  ori   $t8, $s1, 2
  or    $s1, $t8, $t9
  andi  $t7, $s1, 0xff
  move  $s1, $t7
  sw    $t2, 0x48($sp)
  b     .L7F0E27FC
   sb    $s3, 0x185($sp)
spectrum_op_9A:
  andi  $t1, $s4, 0xff
  lw    $t6, 0x28c($sp)
  subu  $t4, $s0, $t1
  andi  $t3, $s1, 1
  subu  $t8, $t4, $t3
  andi  $t2, $t8, 0x1ff
  andi  $t4, $t1, 0xf
  addiu $t0, $t6, 4
  addu  $t8, $t4, $t3
  andi  $t5, $s0, 0xf
  sw    $t0, 0x28c($sp)
  slt   $t7, $t5, $t8
  sra   $t6, $t2, 8
  andi  $t9, $t2, 0xa8
  or    $t0, $t9, $t6
  xor   $t4, $s0, $t1
  sll   $t9, $t7, 4
  xor   $t8, $t2, $s0
  sh    $t2, 0x182($sp)
  lbu   $s0, 0x183($sp)
  andi  $t3, $t4, 0x80
  and   $t7, $t3, $t8
  or    $t6, $t0, $t9
  sra   $t0, $t7, 5
  or    $s1, $t6, $t0
  sltiu $t4, $s0, 1
  sll   $t5, $t4, 6
  ori   $t1, $s1, 2
  or    $s1, $t1, $t5
  andi  $t3, $s1, 0xff
  move  $s1, $t3
  sw    $t4, 0x48($sp)
  b     .L7F0E27FC
   sb    $s4, 0x181($sp)
spectrum_op_9B:
  andi  $t6, $s5, 0xff
  lw    $t8, 0x28c($sp)
  subu  $t0, $s0, $t6
  andi  $t9, $s1, 1
  subu  $t1, $t0, $t9
  andi  $t4, $t1, 0x1ff
  andi  $t0, $t6, 0xf
  addiu $t7, $t8, 4
  addu  $t1, $t0, $t9
  andi  $t2, $s0, 0xf
  sw    $t7, 0x28c($sp)
  slt   $t3, $t2, $t1
  sra   $t8, $t4, 8
  andi  $t5, $t4, 0xa8
  or    $t7, $t5, $t8
  xor   $t0, $s0, $t6
  sll   $t5, $t3, 4
  xor   $t1, $t4, $s0
  sh    $t4, 0x17e($sp)
  lbu   $s0, 0x17f($sp)
  andi  $t9, $t0, 0x80
  and   $t3, $t9, $t1
  or    $t8, $t7, $t5
  sra   $t7, $t3, 5
  or    $s1, $t8, $t7
  sltiu $t0, $s0, 1
  sll   $t2, $t0, 6
  ori   $t6, $s1, 2
  or    $s1, $t6, $t2
  andi  $t9, $s1, 0xff
  move  $s1, $t9
  sw    $t0, 0x48($sp)
  b     .L7F0E27FC
   sb    $s5, 0x17d($sp)
spectrum_op_9C:
  lw    $t1, 0x28c($sp)
  lbu   $t8, 0x287($sp)
  lbu   $t7, 0x287($sp)
  addiu $t3, $t1, 4
  bnez  $t8, .L7F0D8964
   sw    $t3, 0x28c($sp)
  b     .L7F0D8990
   sb    $s6, 0x179($sp)
.L7F0D8964:
  li    $at, 1
  bne   $t7, $at, .L7F0D8980
   lhu   $t0, 0x294($sp)
  lhu   $t5, 0x296($sp)
  sra   $t6, $t5, 8
  b     .L7F0D8988
   sw    $t6, 0x48($sp)
.L7F0D8980:
  sra   $t4, $t0, 8
  sw    $t4, 0x48($sp)
.L7F0D8988:
  lw    $t2, 0x48($sp)
  sb    $t2, 0x179($sp)
.L7F0D8990:
  lbu   $t9, 0x179($sp)
  andi  $t3, $s1, 1
  andi  $t5, $s0, 0xf
  subu  $t1, $s0, $t9
  subu  $t8, $t1, $t3
  andi  $t7, $t8, 0x1ff
  andi  $t1, $t9, 0xf
  addu  $t8, $t1, $t3
  slt   $t0, $t5, $t8
  andi  $t6, $t7, 0xa8
  sra   $t4, $t7, 8
  or    $t2, $t6, $t4
  xor   $t1, $s0, $t9
  sll   $t6, $t0, 4
  xor   $t8, $t7, $s0
  sh    $t7, 0x17a($sp)
  lbu   $s0, 0x17b($sp)
  andi  $t3, $t1, 0x80
  and   $t0, $t3, $t8
  or    $t4, $t2, $t6
  sra   $t2, $t0, 5
  or    $s1, $t4, $t2
  sltiu $t1, $s0, 1
  sll   $t5, $t1, 6
  ori   $t9, $s1, 2
  or    $s1, $t9, $t5
  andi  $t3, $s1, 0xff
  move  $s1, $t3
  b     .L7F0E27FC
   sw    $t1, 0x48($sp)
spectrum_op_9D:
  lw    $t8, 0x28c($sp)
  lbu   $t4, 0x287($sp)
  lbu   $t2, 0x287($sp)
  addiu $t0, $t8, 4
  bnez  $t4, .L7F0D8A28
   sw    $t0, 0x28c($sp)
  b     .L7F0D8A54
   sb    $s7, 0x175($sp)
.L7F0D8A28:
  li    $at, 1
  bne   $t2, $at, .L7F0D8A44
   lhu   $t1, 0x294($sp)
  lhu   $t6, 0x296($sp)
  andi  $t9, $t6, 0xff
  b     .L7F0D8A4C
   sw    $t9, 0x48($sp)
.L7F0D8A44:
  andi  $t7, $t1, 0xff
  sw    $t7, 0x48($sp)
.L7F0D8A4C:
  lw    $t5, 0x48($sp)
  sb    $t5, 0x175($sp)
.L7F0D8A54:
  lbu   $t3, 0x175($sp)
  andi  $t0, $s1, 1
  andi  $t6, $s0, 0xf
  subu  $t8, $s0, $t3
  subu  $t4, $t8, $t0
  andi  $t2, $t4, 0x1ff
  andi  $t8, $t3, 0xf
  addu  $t4, $t8, $t0
  slt   $t1, $t6, $t4
  andi  $t9, $t2, 0xa8
  sra   $t7, $t2, 8
  or    $t5, $t9, $t7
  xor   $t8, $s0, $t3
  sll   $t9, $t1, 4
  xor   $t4, $t2, $s0
  sh    $t2, 0x176($sp)
  lbu   $s0, 0x177($sp)
  andi  $t0, $t8, 0x80
  and   $t1, $t0, $t4
  or    $t7, $t5, $t9
  sra   $t5, $t1, 5
  or    $s1, $t7, $t5
  sltiu $t8, $s0, 1
  sll   $t6, $t8, 6
  ori   $t3, $s1, 2
  or    $s1, $t3, $t6
  andi  $t0, $s1, 0xff
  move  $s1, $t0
  b     .L7F0E27FC
   sw    $t8, 0x48($sp)
spectrum_op_9E:
  lw    $t4, 0x28c($sp)
  lbu   $t7, 0x287($sp)
  sll   $t5, $s6, 8
  addiu $t1, $t4, 7
  bnez  $t7, .L7F0D8AF0
   sw    $t1, 0x28c($sp)
  or    $t9, $t5, $s7
  b     .L7F0D8B44
   sh    $t9, 0x172($sp)
.L7F0D8AF0:
  lw    $t3, 0x28c($sp)
  lbu   $t2, 0x287($sp)
  li    $at, 1
  addiu $t8, $t3, 8
  bne   $t2, $at, .L7F0D8B14
   sw    $t8, 0x28c($sp)
  lhu   $t6, 0x296($sp)
  b     .L7F0D8B1C
   sw    $t6, 0x48($sp)
.L7F0D8B14:
  lhu   $t0, 0x294($sp)
  sw    $t0, 0x48($sp)
.L7F0D8B1C:
  lui   $t1, %hi(ptr_spectrum_roms) 
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  lhu   $t4, 0x298($sp)
  lw    $t9, 0x48($sp)
  addu  $t7, $t4, $t1
  lb    $t5, ($t7)
  addiu $t8, $t4, 1
  sh    $t8, 0x298($sp)
  addu  $t3, $t5, $t9
  sh    $t3, 0x172($sp)
.L7F0D8B44:
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  lhu   $t2, 0x172($sp)
  andi  $t5, $s1, 1
  andi  $t4, $s0, 0xf
  addu  $t0, $t2, $t6
  lbu   $t1, ($t0)
  subu  $t7, $s0, $t1
  subu  $t9, $t7, $t5
  andi  $t3, $t9, 0x1ff
  andi  $t7, $t1, 0xf
  addu  $t9, $t7, $t5
  slt   $t2, $t4, $t9
  andi  $t8, $t3, 0xa8
  sra   $t6, $t3, 8
  or    $t0, $t8, $t6
  xor   $t7, $s0, $t1
  sll   $t8, $t2, 4
  xor   $t9, $t3, $s0
  sh    $t3, 0x170($sp)
  lbu   $s0, 0x171($sp)
  andi  $t5, $t7, 0x80
  and   $t2, $t5, $t9
  or    $t6, $t0, $t8
  sra   $t0, $t2, 5
  or    $s1, $t6, $t0
  sb    $t1, 0x16f($sp)
  sltiu $t7, $s0, 1
  sll   $t4, $t7, 6
  ori   $t1, $s1, 2
  or    $s1, $t1, $t4
  andi  $t5, $s1, 0xff
  move  $s1, $t5
  b     .L7F0E27FC
   sw    $t7, 0x48($sp)
spectrum_op_9F:
  andi  $t6, $s0, 0xff
  lw    $t9, 0x28c($sp)
  subu  $t0, $s0, $t6
  andi  $t8, $s1, 1
  subu  $t1, $t0, $t8
  andi  $t7, $t1, 0x1ff
  andi  $t0, $t6, 0xf
  addiu $t2, $t9, 4
  addu  $t1, $t0, $t8
  andi  $t3, $s0, 0xf
  sw    $t2, 0x28c($sp)
  slt   $t5, $t3, $t1
  sra   $t9, $t7, 8
  andi  $t4, $t7, 0xa8
  or    $t2, $t4, $t9
  xor   $t0, $s0, $t6
  sll   $t4, $t5, 4
  xor   $t1, $t7, $s0
  sh    $t7, 0x16c($sp)
  sb    $s0, 0x16b($sp)
  lbu   $s0, 0x16d($sp)
  andi  $t8, $t0, 0x80
  and   $t5, $t8, $t1
  or    $t9, $t2, $t4
  sra   $t2, $t5, 5
  or    $s1, $t9, $t2
  sltiu $t0, $s0, 1
  sll   $t3, $t0, 6
  ori   $t6, $s1, 2
  or    $s1, $t6, $t3
  andi  $t8, $s1, 0xff
  move  $s1, $t8
  b     .L7F0E27FC
   sw    $t0, 0x48($sp)
spectrum_op_A0:
  lw    $t1, 0x28c($sp)
  lui   $t8, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t8, %lo(ptr_pc_keyboard_table_alloc)($t8)
  and   $s0, $s0, $s2
  andi  $t9, $s0, 0xff
  addiu $t5, $t1, 4
  sltiu $t2, $t9, 1
  sw    $t5, 0x28c($sp)
  sw    $t2, 0x48($sp)
  addu  $t1, $t9, $t8
  lbu   $t5, ($t1)
  sll   $t0, $t2, 6
  andi  $t4, $t9, 0xa8
  or    $t7, $t4, $t0
  ori   $t3, $t7, 0x10
  move  $s0, $t9
  or    $s1, $t5, $t3
  andi  $t9, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t9
spectrum_op_A1:
  lw    $t2, 0x28c($sp)
  lui   $t9, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t9, %lo(ptr_pc_keyboard_table_alloc)($t9)
  and   $s0, $s0, $s3
  andi  $t4, $s0, 0xff
  addiu $t6, $t2, 4
  sltiu $t0, $t4, 1
  sw    $t6, 0x28c($sp)
  sw    $t0, 0x48($sp)
  addu  $t2, $t4, $t9
  lbu   $t6, ($t2)
  sll   $t1, $t0, 6
  andi  $t7, $t4, 0xa8
  or    $t5, $t7, $t1
  ori   $t3, $t5, 0x10
  move  $s0, $t4
  or    $s1, $t6, $t3
  andi  $t4, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t4
spectrum_op_A2:
  lw    $t0, 0x28c($sp)
  lui   $t4, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t4, %lo(ptr_pc_keyboard_table_alloc)($t4)
  and   $s0, $s0, $s4
  andi  $t7, $s0, 0xff
  addiu $t8, $t0, 4
  sltiu $t1, $t7, 1
  sw    $t8, 0x28c($sp)
  sw    $t1, 0x48($sp)
  addu  $t0, $t7, $t4
  lbu   $t8, ($t0)
  sll   $t2, $t1, 6
  andi  $t5, $t7, 0xa8
  or    $t6, $t5, $t2
  ori   $t3, $t6, 0x10
  move  $s0, $t7
  or    $s1, $t8, $t3
  andi  $t7, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t7
spectrum_op_A3:
  lw    $t1, 0x28c($sp)
  lui   $t7, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t7, %lo(ptr_pc_keyboard_table_alloc)($t7)
  and   $s0, $s0, $s5
  andi  $t5, $s0, 0xff
  addiu $t9, $t1, 4
  sltiu $t2, $t5, 1
  sw    $t9, 0x28c($sp)
  sw    $t2, 0x48($sp)
  addu  $t1, $t5, $t7
  lbu   $t9, ($t1)
  sll   $t0, $t2, 6
  andi  $t6, $t5, 0xa8
  or    $t8, $t6, $t0
  ori   $t3, $t8, 0x10
  move  $s0, $t5
  or    $s1, $t9, $t3
  andi  $t5, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t5
spectrum_op_A4:
  lw    $t2, 0x28c($sp)
  lbu   $t6, 0x287($sp)
  lbu   $t0, 0x287($sp)
  addiu $t4, $t2, 4
  bnez  $t6, .L7F0D8DB8
   sw    $t4, 0x28c($sp)
  b     .L7F0D8DE4
   sw    $s6, 0x48($sp)
.L7F0D8DB8:
  li    $at, 1
  bne   $t0, $at, .L7F0D8DD4
   lhu   $t1, 0x294($sp)
  lhu   $t8, 0x296($sp)
  sra   $t7, $t8, 8
  b     .L7F0D8DDC
   sw    $t7, 0x44($sp)
.L7F0D8DD4:
  sra   $t9, $t1, 8
  sw    $t9, 0x44($sp)
.L7F0D8DDC:
  lw    $t3, 0x44($sp)
  sw    $t3, 0x48($sp)
.L7F0D8DE4:
  lw    $t5, 0x48($sp)
  lui   $t9, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t9, %lo(ptr_pc_keyboard_table_alloc)($t9)
  and   $s0, $s0, $t5
  andi  $t2, $s0, 0xff
  sltiu $t4, $t2, 1
  sw    $t4, 0x48($sp)
  addu  $t3, $t2, $t9
  lbu   $t5, ($t3)
  sll   $t8, $t4, 6
  andi  $t6, $t2, 0xa8
  or    $t7, $t6, $t8
  ori   $t1, $t7, 0x10
  move  $s0, $t2
  or    $s1, $t5, $t1
  andi  $t2, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t2
spectrum_op_A5:
  lw    $t4, 0x28c($sp)
  lbu   $t6, 0x287($sp)
  lbu   $t8, 0x287($sp)
  addiu $t0, $t4, 4
  bnez  $t6, .L7F0D8E4C
   sw    $t0, 0x28c($sp)
  b     .L7F0D8E78
   sw    $s7, 0x48($sp)
.L7F0D8E4C:
  li    $at, 1
  bne   $t8, $at, .L7F0D8E68
   lhu   $t3, 0x294($sp)
  lhu   $t7, 0x296($sp)
  andi  $t9, $t7, 0xff
  b     .L7F0D8E70
   sw    $t9, 0x44($sp)
.L7F0D8E68:
  andi  $t5, $t3, 0xff
  sw    $t5, 0x44($sp)
.L7F0D8E70:
  lw    $t1, 0x44($sp)
  sw    $t1, 0x48($sp)
.L7F0D8E78:
  lw    $t2, 0x48($sp)
  lui   $t5, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t5, %lo(ptr_pc_keyboard_table_alloc)($t5)
  and   $s0, $s0, $t2
  andi  $t4, $s0, 0xff
  sltiu $t0, $t4, 1
  sw    $t0, 0x48($sp)
  addu  $t1, $t4, $t5
  lbu   $t2, ($t1)
  sll   $t7, $t0, 6
  andi  $t6, $t4, 0xa8
  or    $t9, $t6, $t7
  ori   $t3, $t9, 0x10
  move  $s0, $t4
  or    $s1, $t2, $t3
  andi  $t4, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t4
spectrum_op_A6:
  lw    $t0, 0x28c($sp)
  lbu   $t6, 0x287($sp)
  sll   $t7, $s6, 8
  addiu $t8, $t0, 7
  bnez  $t6, .L7F0D8EE4
   sw    $t8, 0x28c($sp)
  or    $t9, $t7, $s7
  b     .L7F0D8F38
   sh    $t9, 0x168($sp)
.L7F0D8EE4:
  lw    $t5, 0x28c($sp)
  lbu   $t2, 0x287($sp)
  li    $at, 1
  addiu $t1, $t5, 8
  bne   $t2, $at, .L7F0D8F08
   sw    $t1, 0x28c($sp)
  lhu   $t3, 0x296($sp)
  b     .L7F0D8F10
   sw    $t3, 0x48($sp)
.L7F0D8F08:
  lhu   $t4, 0x294($sp)
  sw    $t4, 0x48($sp)
.L7F0D8F10:
  lui   $t8, %hi(ptr_spectrum_roms) 
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  lhu   $t0, 0x298($sp)
  lw    $t9, 0x48($sp)
  addu  $t6, $t0, $t8
  lb    $t7, ($t6)
  addiu $t1, $t0, 1
  sh    $t1, 0x298($sp)
  addu  $t5, $t7, $t9
  sh    $t5, 0x168($sp)
.L7F0D8F38:
  lui   $t2, %hi(ptr_spectrum_roms) 
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  lhu   $t3, 0x168($sp)
  addu  $t4, $t2, $t3
  lbu   $t8, ($t4)
  lui   $t3, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t3, %lo(ptr_pc_keyboard_table_alloc)($t3)
  and   $s0, $s0, $t8
  andi  $t6, $s0, 0xff
  sltiu $t7, $t6, 1
  sw    $t7, 0x48($sp)
  addu  $t4, $t6, $t3
  lbu   $t8, ($t4)
  sll   $t0, $t7, 6
  andi  $t9, $t6, 0xa8
  or    $t1, $t9, $t0
  ori   $t2, $t1, 0x10
  move  $s0, $t6
  or    $s1, $t8, $t2
  andi  $t6, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t6
spectrum_op_A7:
  lw    $t7, 0x28c($sp)
  lui   $t6, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t6, %lo(ptr_pc_keyboard_table_alloc)($t6)
  and   $s0, $s0, $s0
  andi  $t9, $s0, 0xff
  addiu $t5, $t7, 4
  sltiu $t0, $t9, 1
  sw    $t5, 0x28c($sp)
  sw    $t0, 0x48($sp)
  addu  $t7, $t9, $t6
  lbu   $t5, ($t7)
  sll   $t4, $t0, 6
  andi  $t1, $t9, 0xa8
  or    $t8, $t1, $t4
  ori   $t2, $t8, 0x10
  move  $s0, $t9
  or    $s1, $t5, $t2
  andi  $t9, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t9
spectrum_op_A8:
  lw    $t0, 0x28c($sp)
  lui   $t2, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t2, %lo(ptr_pc_keyboard_table_alloc)($t2)
  xor   $s0, $s0, $s2
  andi  $t1, $s0, 0xff
  sltiu $t4, $t1, 1
  addiu $t3, $t0, 4
  sw    $t3, 0x28c($sp)
  sw    $t4, 0x48($sp)
  addu  $t9, $t1, $t2
  lbu   $t0, ($t9)
  sll   $t7, $t4, 6
  andi  $t8, $t1, 0xa8
  or    $t5, $t8, $t7
  or    $s1, $t0, $t5
  andi  $t3, $s1, 0xff
  move  $s1, $t3
  b     .L7F0E27FC
   move  $s0, $t1
spectrum_op_A9:
  lw    $t1, 0x28c($sp)
  lui   $t5, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t5, %lo(ptr_pc_keyboard_table_alloc)($t5)
  xor   $s0, $s0, $s3
  andi  $t6, $s0, 0xff
  sltiu $t8, $t6, 1
  addiu $t4, $t1, 4
  sw    $t4, 0x28c($sp)
  sw    $t8, 0x48($sp)
  addu  $t3, $t6, $t5
  lbu   $t1, ($t3)
  sll   $t9, $t8, 6
  andi  $t7, $t6, 0xa8
  or    $t0, $t7, $t9
  or    $s1, $t1, $t0
  andi  $t4, $s1, 0xff
  move  $s1, $t4
  b     .L7F0E27FC
   move  $s0, $t6
spectrum_op_AA:
  lw    $t6, 0x28c($sp)
  lui   $t0, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t0, %lo(ptr_pc_keyboard_table_alloc)($t0)
  xor   $s0, $s0, $s4
  andi  $t2, $s0, 0xff
  sltiu $t7, $t2, 1
  addiu $t8, $t6, 4
  sw    $t8, 0x28c($sp)
  sw    $t7, 0x48($sp)
  addu  $t4, $t2, $t0
  lbu   $t6, ($t4)
  sll   $t3, $t7, 6
  andi  $t9, $t2, 0xa8
  or    $t1, $t9, $t3
  or    $s1, $t6, $t1
  andi  $t8, $s1, 0xff
  move  $s1, $t8
  b     .L7F0E27FC
   move  $s0, $t2
spectrum_op_AB:
  lw    $t2, 0x28c($sp)
  lui   $t1, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t1, %lo(ptr_pc_keyboard_table_alloc)($t1)
  xor   $s0, $s0, $s5
  andi  $t5, $s0, 0xff
  sltiu $t9, $t5, 1
  addiu $t7, $t2, 4
  sw    $t7, 0x28c($sp)
  sw    $t9, 0x48($sp)
  addu  $t8, $t5, $t1
  lbu   $t2, ($t8)
  sll   $t4, $t9, 6
  andi  $t3, $t5, 0xa8
  or    $t6, $t3, $t4
  or    $s1, $t2, $t6
  andi  $t7, $s1, 0xff
  move  $s1, $t7
  b     .L7F0E27FC
   move  $s0, $t5
spectrum_op_AC:
  lw    $t5, 0x28c($sp)
  lbu   $t0, 0x287($sp)
  lbu   $t3, 0x287($sp)
  addiu $t9, $t5, 4
  bnez  $t0, .L7F0D9130
   sw    $t9, 0x28c($sp)
  b     .L7F0D915C
   sw    $s6, 0x48($sp)
.L7F0D9130:
  li    $at, 1
  bne   $t3, $at, .L7F0D914C
   lhu   $t8, 0x294($sp)
  lhu   $t4, 0x296($sp)
  sra   $t1, $t4, 8
  b     .L7F0D9154
   sw    $t1, 0x44($sp)
.L7F0D914C:
  sra   $t2, $t8, 8
  sw    $t2, 0x44($sp)
.L7F0D9154:
  lw    $t6, 0x44($sp)
  sw    $t6, 0x48($sp)
.L7F0D915C:
  lw    $t7, 0x48($sp)
  lui   $t8, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t8, %lo(ptr_pc_keyboard_table_alloc)($t8)
  xor   $s0, $s0, $t7
  andi  $t5, $s0, 0xff
  sltiu $t9, $t5, 1
  sw    $t9, 0x48($sp)
  addu  $t2, $t5, $t8
  lbu   $t6, ($t2)
  sll   $t4, $t9, 6
  andi  $t0, $t5, 0xa8
  or    $t1, $t0, $t4
  or    $s1, $t6, $t1
  andi  $t7, $s1, 0xff
  move  $s1, $t7
  b     .L7F0E27FC
   move  $s0, $t5
spectrum_op_AD:
  lw    $t5, 0x28c($sp)
  lbu   $t3, 0x287($sp)
  lbu   $t0, 0x287($sp)
  addiu $t9, $t5, 4
  bnez  $t3, .L7F0D91C0
   sw    $t9, 0x28c($sp)
  b     .L7F0D91EC
   sw    $s7, 0x48($sp)
.L7F0D91C0:
  li    $at, 1
  bne   $t0, $at, .L7F0D91DC
   lhu   $t2, 0x294($sp)
  lhu   $t4, 0x296($sp)
  andi  $t8, $t4, 0xff
  b     .L7F0D91E4
   sw    $t8, 0x44($sp)
.L7F0D91DC:
  andi  $t6, $t2, 0xff
  sw    $t6, 0x44($sp)
.L7F0D91E4:
  lw    $t1, 0x44($sp)
  sw    $t1, 0x48($sp)
.L7F0D91EC:
  lw    $t7, 0x48($sp)
  lui   $t2, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t2, %lo(ptr_pc_keyboard_table_alloc)($t2)
  xor   $s0, $s0, $t7
  andi  $t5, $s0, 0xff
  sltiu $t9, $t5, 1
  sw    $t9, 0x48($sp)
  addu  $t6, $t5, $t2
  lbu   $t1, ($t6)
  sll   $t4, $t9, 6
  andi  $t3, $t5, 0xa8
  or    $t8, $t3, $t4
  or    $s1, $t1, $t8
  andi  $t7, $s1, 0xff
  move  $s1, $t7
  b     .L7F0E27FC
   move  $s0, $t5
spectrum_op_AE:
  lw    $t5, 0x28c($sp)
  lbu   $t0, 0x287($sp)
  sll   $t3, $s6, 8
  addiu $t9, $t5, 7
  bnez  $t0, .L7F0D9254
   sw    $t9, 0x28c($sp)
  or    $t4, $t3, $s7
  b     .L7F0D92A8
   sh    $t4, 0x166($sp)
.L7F0D9254:
  lw    $t2, 0x28c($sp)
  lbu   $t1, 0x287($sp)
  li    $at, 1
  addiu $t6, $t2, 8
  bne   $t1, $at, .L7F0D9278
   sw    $t6, 0x28c($sp)
  lhu   $t8, 0x296($sp)
  b     .L7F0D9280
   sw    $t8, 0x48($sp)
.L7F0D9278:
  lhu   $t7, 0x294($sp)
  sw    $t7, 0x48($sp)
.L7F0D9280:
  lui   $t9, %hi(ptr_spectrum_roms) 
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  lhu   $t5, 0x298($sp)
  lw    $t4, 0x48($sp)
  addu  $t0, $t5, $t9
  lb    $t3, ($t0)
  addiu $t6, $t5, 1
  sh    $t6, 0x298($sp)
  addu  $t2, $t3, $t4
  sh    $t2, 0x166($sp)
.L7F0D92A8:
  lui   $t1, %hi(ptr_spectrum_roms) 
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  lhu   $t8, 0x166($sp)
  addu  $t7, $t1, $t8
  lbu   $t9, ($t7)
  lui   $t1, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t1, %lo(ptr_pc_keyboard_table_alloc)($t1)
  xor   $s0, $s0, $t9
  andi  $t0, $s0, 0xff
  sltiu $t3, $t0, 1
  sw    $t3, 0x48($sp)
  addu  $t8, $t0, $t1
  lbu   $t7, ($t8)
  sll   $t5, $t3, 6
  andi  $t4, $t0, 0xa8
  or    $t6, $t4, $t5
  or    $s1, $t7, $t6
  andi  $t9, $s1, 0xff
  move  $s1, $t9
  b     .L7F0E27FC
   move  $s0, $t0
spectrum_op_AF:
  lw    $t0, 0x28c($sp)
  lui   $t6, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t6, %lo(ptr_pc_keyboard_table_alloc)($t6)
  xor   $s0, $s0, $s0
  andi  $t2, $s0, 0xff
  sltiu $t4, $t2, 1
  addiu $t3, $t0, 4
  sw    $t3, 0x28c($sp)
  sw    $t4, 0x48($sp)
  addu  $t9, $t2, $t6
  lbu   $t0, ($t9)
  sll   $t8, $t4, 6
  andi  $t5, $t2, 0xa8
  or    $t7, $t5, $t8
  or    $s1, $t0, $t7
  andi  $t3, $s1, 0xff
  move  $s1, $t3
  b     .L7F0E27FC
   move  $s0, $t2
spectrum_op_B0:
  lw    $t2, 0x28c($sp)
  lui   $t7, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t7, %lo(ptr_pc_keyboard_table_alloc)($t7)
  or    $s0, $s0, $s2
  andi  $t1, $s0, 0xff
  sltiu $t5, $t1, 1
  addiu $t4, $t2, 4
  sw    $t4, 0x28c($sp)
  sw    $t5, 0x48($sp)
  addu  $t3, $t1, $t7
  lbu   $t2, ($t3)
  sll   $t9, $t5, 6
  andi  $t8, $t1, 0xa8
  or    $t0, $t8, $t9
  or    $s1, $t2, $t0
  andi  $t4, $s1, 0xff
  move  $s1, $t4
  b     .L7F0E27FC
   move  $s0, $t1
spectrum_op_B1:
  lw    $t1, 0x28c($sp)
  lui   $t0, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t0, %lo(ptr_pc_keyboard_table_alloc)($t0)
  or    $s0, $s0, $s3
  andi  $t6, $s0, 0xff
  sltiu $t8, $t6, 1
  addiu $t5, $t1, 4
  sw    $t5, 0x28c($sp)
  sw    $t8, 0x48($sp)
  addu  $t4, $t6, $t0
  lbu   $t1, ($t4)
  sll   $t3, $t8, 6
  andi  $t9, $t6, 0xa8
  or    $t2, $t9, $t3
  or    $s1, $t1, $t2
  andi  $t5, $s1, 0xff
  move  $s1, $t5
  b     .L7F0E27FC
   move  $s0, $t6
spectrum_op_B2:
  lw    $t6, 0x28c($sp)
  lui   $t2, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t2, %lo(ptr_pc_keyboard_table_alloc)($t2)
  or    $s0, $s0, $s4
  andi  $t7, $s0, 0xff
  sltiu $t9, $t7, 1
  addiu $t8, $t6, 4
  sw    $t8, 0x28c($sp)
  sw    $t9, 0x48($sp)
  addu  $t5, $t7, $t2
  lbu   $t6, ($t5)
  sll   $t4, $t9, 6
  andi  $t3, $t7, 0xa8
  or    $t1, $t3, $t4
  or    $s1, $t6, $t1
  andi  $t8, $s1, 0xff
  move  $s1, $t8
  b     .L7F0E27FC
   move  $s0, $t7
spectrum_op_B3:
  lw    $t7, 0x28c($sp)
  lui   $t1, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t1, %lo(ptr_pc_keyboard_table_alloc)($t1)
  or    $s0, $s0, $s5
  andi  $t0, $s0, 0xff
  sltiu $t3, $t0, 1
  addiu $t9, $t7, 4
  sw    $t9, 0x28c($sp)
  sw    $t3, 0x48($sp)
  addu  $t8, $t0, $t1
  lbu   $t7, ($t8)
  sll   $t5, $t3, 6
  andi  $t4, $t0, 0xa8
  or    $t6, $t4, $t5
  or    $s1, $t7, $t6
  andi  $t9, $s1, 0xff
  move  $s1, $t9
  b     .L7F0E27FC
   move  $s0, $t0
spectrum_op_B4:
  lw    $t0, 0x28c($sp)
  lbu   $t2, 0x287($sp)
  lbu   $t4, 0x287($sp)
  addiu $t3, $t0, 4
  bnez  $t2, .L7F0D9498
   sw    $t3, 0x28c($sp)
  b     .L7F0D94C4
   sw    $s6, 0x48($sp)
.L7F0D9498:
  li    $at, 1
  bne   $t4, $at, .L7F0D94B4
   lhu   $t8, 0x294($sp)
  lhu   $t5, 0x296($sp)
  sra   $t1, $t5, 8
  b     .L7F0D94BC
   sw    $t1, 0x44($sp)
.L7F0D94B4:
  sra   $t7, $t8, 8
  sw    $t7, 0x44($sp)
.L7F0D94BC:
  lw    $t6, 0x44($sp)
  sw    $t6, 0x48($sp)
.L7F0D94C4:
  lw    $t9, 0x48($sp)
  lui   $t8, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t8, %lo(ptr_pc_keyboard_table_alloc)($t8)
  or    $s0, $s0, $t9
  andi  $t0, $s0, 0xff
  sltiu $t3, $t0, 1
  sw    $t3, 0x48($sp)
  addu  $t7, $t0, $t8
  lbu   $t6, ($t7)
  sll   $t5, $t3, 6
  andi  $t2, $t0, 0xa8
  or    $t1, $t2, $t5
  or    $s1, $t6, $t1
  andi  $t9, $s1, 0xff
  move  $s1, $t9
  b     .L7F0E27FC
   move  $s0, $t0
spectrum_op_B5:
  lw    $t0, 0x28c($sp)
  lbu   $t4, 0x287($sp)
  lbu   $t2, 0x287($sp)
  addiu $t3, $t0, 4
  bnez  $t4, .L7F0D9528
   sw    $t3, 0x28c($sp)
  b     .L7F0D9554
   sw    $s7, 0x48($sp)
.L7F0D9528:
  li    $at, 1
  bne   $t2, $at, .L7F0D9544
   lhu   $t7, 0x294($sp)
  lhu   $t5, 0x296($sp)
  andi  $t8, $t5, 0xff
  b     .L7F0D954C
   sw    $t8, 0x44($sp)
.L7F0D9544:
  andi  $t6, $t7, 0xff
  sw    $t6, 0x44($sp)
.L7F0D954C:
  lw    $t1, 0x44($sp)
  sw    $t1, 0x48($sp)
.L7F0D9554:
  lw    $t9, 0x48($sp)
  lui   $t7, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t7, %lo(ptr_pc_keyboard_table_alloc)($t7)
  or    $s0, $s0, $t9
  andi  $t0, $s0, 0xff
  sltiu $t3, $t0, 1
  sw    $t3, 0x48($sp)
  addu  $t6, $t0, $t7
  lbu   $t1, ($t6)
  sll   $t5, $t3, 6
  andi  $t4, $t0, 0xa8
  or    $t8, $t4, $t5
  or    $s1, $t1, $t8
  andi  $t9, $s1, 0xff
  move  $s1, $t9
  b     .L7F0E27FC
   move  $s0, $t0
spectrum_op_B6:
  lw    $t0, 0x28c($sp)
  lbu   $t2, 0x287($sp)
  sll   $t4, $s6, 8
  addiu $t3, $t0, 7
  bnez  $t2, .L7F0D95BC
   sw    $t3, 0x28c($sp)
  or    $t5, $t4, $s7
  b     .L7F0D9610
   sh    $t5, 0x164($sp)
.L7F0D95BC:
  lw    $t7, 0x28c($sp)
  lbu   $t1, 0x287($sp)
  li    $at, 1
  addiu $t6, $t7, 8
  bne   $t1, $at, .L7F0D95E0
   sw    $t6, 0x28c($sp)
  lhu   $t8, 0x296($sp)
  b     .L7F0D95E8
   sw    $t8, 0x48($sp)
.L7F0D95E0:
  lhu   $t9, 0x294($sp)
  sw    $t9, 0x48($sp)
.L7F0D95E8:
  lui   $t3, %hi(ptr_spectrum_roms) 
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  lhu   $t0, 0x298($sp)
  lw    $t5, 0x48($sp)
  addu  $t2, $t0, $t3
  lb    $t4, ($t2)
  addiu $t6, $t0, 1
  sh    $t6, 0x298($sp)
  addu  $t7, $t4, $t5
  sh    $t7, 0x164($sp)
.L7F0D9610:
  lui   $t1, %hi(ptr_spectrum_roms) 
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  lhu   $t8, 0x164($sp)
  addu  $t9, $t1, $t8
  lbu   $t3, ($t9)
  lui   $t1, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t1, %lo(ptr_pc_keyboard_table_alloc)($t1)
  or    $s0, $s0, $t3
  andi  $t2, $s0, 0xff
  sltiu $t4, $t2, 1
  sw    $t4, 0x48($sp)
  addu  $t8, $t2, $t1
  lbu   $t9, ($t8)
  sll   $t0, $t4, 6
  andi  $t5, $t2, 0xa8
  or    $t6, $t5, $t0
  or    $s1, $t9, $t6
  andi  $t3, $s1, 0xff
  move  $s1, $t3
  b     .L7F0E27FC
   move  $s0, $t2
spectrum_op_B7:
  lw    $t2, 0x28c($sp)
  lui   $t6, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t6, %lo(ptr_pc_keyboard_table_alloc)($t6)
  or    $s0, $s0, $s0
  andi  $t7, $s0, 0xff
  sltiu $t5, $t7, 1
  addiu $t4, $t2, 4
  sw    $t4, 0x28c($sp)
  sw    $t5, 0x48($sp)
  addu  $t3, $t7, $t6
  lbu   $t2, ($t3)
  sll   $t8, $t5, 6
  andi  $t0, $t7, 0xa8
  or    $t9, $t0, $t8
  or    $s1, $t2, $t9
  andi  $t4, $s1, 0xff
  move  $s1, $t4
  b     .L7F0E27FC
   move  $s0, $t7
spectrum_op_B8:
  andi  $t1, $s2, 0xff
  subu  $t0, $s0, $t1
  lw    $t7, 0x28c($sp)
  andi  $t8, $t0, 0x1ff
  andi  $t6, $t8, 0xffff
  sltiu $t3, $t6, 1
  andi  $t6, $t1, 0xf
  andi  $t0, $s0, 0xf
  addiu $t5, $t7, 4
  slt   $t2, $t0, $t6
  sw    $t5, 0x28c($sp)
  sra   $t7, $t8, 8
  andi  $t9, $t8, 0xa8
  or    $t5, $t9, $t7
  sll   $t4, $t2, 4
  xor   $t7, $s0, $t1
  move  $t6, $t8
  xor   $t2, $t6, $s0
  andi  $t0, $t7, 0x80
  or    $t9, $t5, $t4
  and   $t5, $t0, $t2
  sra   $t4, $t5, 5
  or    $t1, $t9, $t4
  sh    $t8, 0x162($sp)
  sll   $t8, $t3, 6
  ori   $t7, $t1, 2
  or    $s1, $t7, $t8
  andi  $t6, $s1, 0xff
  move  $s1, $t6
  sw    $t3, 0x48($sp)
  b     .L7F0E27FC
   sb    $s2, 0x161($sp)
spectrum_op_B9:
  andi  $t5, $s3, 0xff
  subu  $t9, $s0, $t5
  lw    $t0, 0x28c($sp)
  andi  $t4, $t9, 0x1ff
  andi  $t1, $t4, 0xffff
  sltiu $t3, $t1, 1
  andi  $t1, $t5, 0xf
  andi  $t9, $s0, 0xf
  addiu $t2, $t0, 4
  slt   $t7, $t9, $t1
  sw    $t2, 0x28c($sp)
  sra   $t0, $t4, 8
  andi  $t8, $t4, 0xa8
  or    $t2, $t8, $t0
  sll   $t6, $t7, 4
  xor   $t0, $s0, $t5
  move  $t1, $t4
  xor   $t7, $t1, $s0
  andi  $t9, $t0, 0x80
  or    $t8, $t2, $t6
  and   $t2, $t9, $t7
  sra   $t6, $t2, 5
  or    $t5, $t8, $t6
  sh    $t4, 0x15e($sp)
  sll   $t4, $t3, 6
  ori   $t0, $t5, 2
  or    $s1, $t0, $t4
  andi  $t1, $s1, 0xff
  move  $s1, $t1
  sw    $t3, 0x48($sp)
  b     .L7F0E27FC
   sb    $s3, 0x15d($sp)
spectrum_op_BA:
  andi  $t2, $s4, 0xff
  subu  $t8, $s0, $t2
  lw    $t9, 0x28c($sp)
  andi  $t6, $t8, 0x1ff
  andi  $t5, $t6, 0xffff
  sltiu $t3, $t5, 1
  andi  $t5, $t2, 0xf
  andi  $t8, $s0, 0xf
  addiu $t7, $t9, 4
  slt   $t0, $t8, $t5
  sw    $t7, 0x28c($sp)
  sra   $t9, $t6, 8
  andi  $t4, $t6, 0xa8
  or    $t7, $t4, $t9
  sll   $t1, $t0, 4
  xor   $t9, $s0, $t2
  move  $t5, $t6
  xor   $t0, $t5, $s0
  andi  $t8, $t9, 0x80
  or    $t4, $t7, $t1
  and   $t7, $t8, $t0
  sra   $t1, $t7, 5
  or    $t2, $t4, $t1
  sh    $t6, 0x15a($sp)
  sll   $t6, $t3, 6
  ori   $t9, $t2, 2
  or    $s1, $t9, $t6
  andi  $t5, $s1, 0xff
  move  $s1, $t5
  sw    $t3, 0x48($sp)
  b     .L7F0E27FC
   sb    $s4, 0x159($sp)
spectrum_op_BB:
  andi  $t7, $s5, 0xff
  subu  $t4, $s0, $t7
  lw    $t8, 0x28c($sp)
  andi  $t1, $t4, 0x1ff
  andi  $t2, $t1, 0xffff
  sltiu $t3, $t2, 1
  andi  $t2, $t7, 0xf
  andi  $t4, $s0, 0xf
  addiu $t0, $t8, 4
  slt   $t9, $t4, $t2
  sw    $t0, 0x28c($sp)
  sra   $t8, $t1, 8
  andi  $t6, $t1, 0xa8
  or    $t0, $t6, $t8
  sll   $t5, $t9, 4
  xor   $t8, $s0, $t7
  move  $t2, $t1
  xor   $t9, $t2, $s0
  andi  $t4, $t8, 0x80
  or    $t6, $t0, $t5
  and   $t0, $t4, $t9
  sra   $t5, $t0, 5
  or    $t7, $t6, $t5
  sh    $t1, 0x156($sp)
  sll   $t1, $t3, 6
  ori   $t8, $t7, 2
  or    $s1, $t8, $t1
  andi  $t2, $s1, 0xff
  move  $s1, $t2
  sw    $t3, 0x48($sp)
  b     .L7F0E27FC
   sb    $s5, 0x155($sp)
spectrum_op_BC:
  lw    $t4, 0x28c($sp)
  lbu   $t0, 0x287($sp)
  lbu   $t6, 0x287($sp)
  addiu $t9, $t4, 4
  bnez  $t0, .L7F0D98D0
   sw    $t9, 0x28c($sp)
  b     .L7F0D98FC
   sb    $s6, 0x151($sp)
.L7F0D98D0:
  li    $at, 1
  bne   $t6, $at, .L7F0D98EC
   lhu   $t3, 0x294($sp)
  lhu   $t5, 0x296($sp)
  sra   $t7, $t5, 8
  b     .L7F0D98F4
   sw    $t7, 0x48($sp)
.L7F0D98EC:
  sra   $t8, $t3, 8
  sw    $t8, 0x48($sp)
.L7F0D98F4:
  lw    $t1, 0x48($sp)
  sb    $t1, 0x151($sp)
.L7F0D98FC:
  lbu   $t2, 0x151($sp)
  subu  $t4, $s0, $t2
  andi  $t9, $t4, 0x1ff
  andi  $t0, $t9, 0xffff
  sltiu $t6, $t0, 1
  andi  $t4, $s0, 0xf
  andi  $t0, $t2, 0xf
  slt   $t5, $t4, $t0
  andi  $t7, $t9, 0xa8
  sra   $t8, $t9, 8
  or    $t1, $t7, $t8
  sll   $t3, $t5, 4
  move  $t0, $t9
  xor   $t8, $s0, $t2
  andi  $t4, $t8, 0x80
  xor   $t5, $t0, $s0
  or    $t7, $t1, $t3
  and   $t1, $t4, $t5
  sra   $t3, $t1, 5
  or    $t2, $t7, $t3
  sh    $t9, 0x152($sp)
  sll   $t9, $t6, 6
  ori   $t8, $t2, 2
  or    $s1, $t8, $t9
  andi  $t0, $s1, 0xff
  move  $s1, $t0
  b     .L7F0E27FC
   sw    $t6, 0x48($sp)
spectrum_op_BD:
  lw    $t4, 0x28c($sp)
  lbu   $t1, 0x287($sp)
  lbu   $t7, 0x287($sp)
  addiu $t5, $t4, 4
  bnez  $t1, .L7F0D998C
   sw    $t5, 0x28c($sp)
  b     .L7F0D99B8
   sb    $s7, 0x14d($sp)
.L7F0D998C:
  li    $at, 1
  bne   $t7, $at, .L7F0D99A8
   lhu   $t6, 0x294($sp)
  lhu   $t3, 0x296($sp)
  andi  $t2, $t3, 0xff
  b     .L7F0D99B0
   sw    $t2, 0x48($sp)
.L7F0D99A8:
  andi  $t8, $t6, 0xff
  sw    $t8, 0x48($sp)
.L7F0D99B0:
  lw    $t9, 0x48($sp)
  sb    $t9, 0x14d($sp)
.L7F0D99B8:
  lbu   $t0, 0x14d($sp)
  subu  $t4, $s0, $t0
  andi  $t5, $t4, 0x1ff
  andi  $t1, $t5, 0xffff
  sltiu $t7, $t1, 1
  andi  $t4, $s0, 0xf
  andi  $t1, $t0, 0xf
  slt   $t3, $t4, $t1
  andi  $t2, $t5, 0xa8
  sra   $t8, $t5, 8
  or    $t9, $t2, $t8
  sll   $t6, $t3, 4
  move  $t1, $t5
  xor   $t8, $s0, $t0
  andi  $t4, $t8, 0x80
  xor   $t3, $t1, $s0
  or    $t2, $t9, $t6
  and   $t9, $t4, $t3
  sra   $t6, $t9, 5
  or    $t0, $t2, $t6
  sh    $t5, 0x14e($sp)
  sll   $t5, $t7, 6
  ori   $t8, $t0, 2
  or    $s1, $t8, $t5
  andi  $t1, $s1, 0xff
  move  $s1, $t1
  b     .L7F0E27FC
   sw    $t7, 0x48($sp)
spectrum_op_BE:
  lw    $t4, 0x28c($sp)
  lbu   $t9, 0x287($sp)
  sll   $t2, $s6, 8
  addiu $t3, $t4, 7
  bnez  $t9, .L7F0D9A4C
   sw    $t3, 0x28c($sp)
  or    $t6, $t2, $s7
  b     .L7F0D9AA0
   sh    $t6, 0x14a($sp)
.L7F0D9A4C:
  lw    $t0, 0x28c($sp)
  lbu   $t8, 0x287($sp)
  li    $at, 1
  addiu $t7, $t0, 8
  bne   $t8, $at, .L7F0D9A70
   sw    $t7, 0x28c($sp)
  lhu   $t5, 0x296($sp)
  b     .L7F0D9A78
   sw    $t5, 0x48($sp)
.L7F0D9A70:
  lhu   $t1, 0x294($sp)
  sw    $t1, 0x48($sp)
.L7F0D9A78:
  lui   $t3, %hi(ptr_spectrum_roms) 
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  lhu   $t4, 0x298($sp)
  lw    $t6, 0x48($sp)
  addu  $t9, $t4, $t3
  lb    $t2, ($t9)
  addiu $t7, $t4, 1
  sh    $t7, 0x298($sp)
  addu  $t0, $t2, $t6
  sh    $t0, 0x14a($sp)
.L7F0D9AA0:
  lui   $t5, %hi(ptr_spectrum_roms) 
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  lhu   $t8, 0x14a($sp)
  addu  $t1, $t8, $t5
  lbu   $t3, ($t1)
  subu  $t9, $s0, $t3
  andi  $t2, $t9, 0x1ff
  andi  $t6, $t2, 0xffff
  sltiu $t0, $t6, 1
  andi  $t6, $s0, 0xf
  andi  $t9, $t3, 0xf
  slt   $t4, $t6, $t9
  andi  $t7, $t2, 0xa8
  sra   $t5, $t2, 8
  or    $t1, $t7, $t5
  sll   $t8, $t4, 4
  move  $t9, $t2
  xor   $t5, $s0, $t3
  andi  $t6, $t5, 0x80
  xor   $t4, $t9, $s0
  or    $t7, $t1, $t8
  and   $t1, $t6, $t4
  sra   $t8, $t1, 5
  sb    $t3, 0x147($sp)
  or    $t3, $t7, $t8
  sh    $t2, 0x148($sp)
  sll   $t2, $t0, 6
  ori   $t5, $t3, 2
  or    $s1, $t5, $t2
  andi  $t9, $s1, 0xff
  move  $s1, $t9
  b     .L7F0E27FC
   sw    $t0, 0x48($sp)
spectrum_op_BF:
  andi  $t1, $s0, 0xff
  subu  $t7, $s0, $t1
  lw    $t6, 0x28c($sp)
  andi  $t8, $t7, 0x1ff
  andi  $t3, $t8, 0xffff
  sltiu $t0, $t3, 1
  andi  $t3, $t1, 0xf
  andi  $t7, $s0, 0xf
  addiu $t4, $t6, 4
  slt   $t5, $t7, $t3
  sw    $t4, 0x28c($sp)
  sra   $t6, $t8, 8
  andi  $t2, $t8, 0xa8
  or    $t4, $t2, $t6
  sll   $t9, $t5, 4
  xor   $t6, $s0, $t1
  move  $t3, $t8
  xor   $t5, $t3, $s0
  andi  $t7, $t6, 0x80
  or    $t2, $t4, $t9
  and   $t4, $t7, $t5
  sra   $t9, $t4, 5
  or    $t1, $t2, $t9
  sh    $t8, 0x144($sp)
  sll   $t8, $t0, 6
  ori   $t6, $t1, 2
  or    $s1, $t6, $t8
  andi  $t3, $s1, 0xff
  move  $s1, $t3
  sw    $t0, 0x48($sp)
  b     .L7F0E27FC
   sb    $s0, 0x143($sp)
spectrum_op_C0:
  lw    $t7, 0x28c($sp)
  andi  $t4, $s1, 0x40
  lui   $t0, %hi(ptr_spectrum_roms) 
  addiu $t5, $t7, 5
  bnez  $t4, .L7F0E27FC
   sw    $t5, 0x28c($sp)
  lhu   $t1, 0x292($sp)
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  addiu $t9, $t5, 6
  sw    $t9, 0x28c($sp)
  addu  $t3, $t0, $t1
  lbu   $t7, 1($t3)
  addu  $t6, $t1, $t0
  lbu   $t8, ($t6)
  sll   $t5, $t7, 8
  addiu $t2, $t1, 2
  or    $t4, $t8, $t5
  sh    $t4, 0x298($sp)
  b     .L7F0E27FC
   sh    $t2, 0x292($sp)
spectrum_op_C1:
  lw    $t9, 0x28c($sp)
  lui   $t3, %hi(ptr_spectrum_roms) 
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  lhu   $t0, 0x292($sp)
  addiu $t6, $t9, 0xa
  sw    $t6, 0x28c($sp)
  addu  $t7, $t0, $t3
  lbu   $s3, ($t7)
  lbu   $s2, 1($t7)
  addiu $t8, $t0, 2
  b     .L7F0E27FC
   sh    $t8, 0x292($sp)
spectrum_op_C2:
  lw    $t5, 0x28c($sp)
  andi  $t1, $s1, 0x40
  lhu   $t2, 0x298($sp)
  addiu $t4, $t5, 0xa
  bnez  $t1, .L7F0D9C64
   sw    $t4, 0x28c($sp)
  lui   $t9, %hi(ptr_spectrum_roms) 
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  addu  $t7, $t9, $t2
  lbu   $t0, 1($t7)
  addu  $t6, $t2, $t9
  lbu   $t3, ($t6)
  sll   $t8, $t0, 8
  or    $t5, $t3, $t8
  b     .L7F0E27FC
   sh    $t5, 0x298($sp)
.L7F0D9C64:
  lhu   $t4, 0x298($sp)
  addiu $t1, $t4, 2
  b     .L7F0E27FC
   sh    $t1, 0x298($sp)
spectrum_op_C3:
  lw    $t6, 0x28c($sp)
  lui   $t7, %hi(ptr_spectrum_roms) 
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  lhu   $t2, 0x298($sp)
  addiu $t9, $t6, 0xa
  sw    $t9, 0x28c($sp)
  addu  $t8, $t7, $t2
  lbu   $t5, 1($t8)
  addu  $t0, $t2, $t7
  lbu   $t3, ($t0)
  sll   $t4, $t5, 8
  or    $t1, $t3, $t4
  b     .L7F0E27FC
   sh    $t1, 0x298($sp)
spectrum_op_C4:
  lw    $t6, 0x28c($sp)
  andi  $t0, $s1, 0x40
  addiu $t9, $t6, 0xa
  bnez  $t0, .L7F0D9E84
   sw    $t9, 0x28c($sp)
  lhu   $t8, 0x292($sp)
  addiu $t2, $t9, 7
  sw    $t2, 0x28c($sp)
  addiu $t5, $t8, -2
  andi  $t3, $t5, 0xffff
  slti  $at, $t3, 0x5b00
  bnez  $at, .L7F0D9CFC
   sh    $t5, 0x292($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  lhu   $t4, 0x298($sp)
  addu  $t9, $t6, $t3
  addiu $t1, $t4, 2
  b     .L7F0D9D88
   sb    $t1, ($t9)
.L7F0D9CFC:
  lhu   $t0, 0x292($sp)
  lhu   $t9, 0x292($sp)
  lhu   $t7, 0x298($sp)
  slti  $at, $t0, 0x5800
  bnez  $at, .L7F0D9D40
   lui   $t8, %hi(ptr_spectrum_roms) 
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  addiu $t2, $t7, 2
  lui   $t6, %hi(ptr_300alloc) 
  addu  $t5, $t8, $t0
  sb    $t2, ($t5)
  lhu   $t3, 0x292($sp)
  lw    $t6, %lo(ptr_300alloc)($t6)
  li    $t4, 1
  addu  $t1, $t6, $t3
  b     .L7F0D9D88
   sb    $t4, -0x5800($t1)
.L7F0D9D40:
  slti  $at, $t9, 0x4000
  bnez  $at, .L7F0D9D88
   lhu   $t7, 0x298($sp)
  lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  addiu $t8, $t7, 2
  li    $t5, 1
  addu  $t2, $t0, $t9
  sb    $t8, ($t2)
  lhu   $t6, 0x292($sp)
  lui   $t0, %hi(ptr_300alloc) 
  lw    $t0, %lo(ptr_300alloc)($t0)
  andi  $t3, $t6, 0x1800
  sra   $t4, $t3, 3
  andi  $t1, $t6, 0xff
  or    $t7, $t4, $t1
  addu  $t9, $t0, $t7
  sb    $t5, ($t9)
.L7F0D9D88:
  lhu   $t8, 0x292($sp)
  lhu   $t7, 0x292($sp)
  lhu   $t3, 0x298($sp)
  addiu $t2, $t8, 1
  slti  $at, $t2, 0x5b00
  bnez  $at, .L7F0D9DC0
   addiu $t5, $t7, 1
  lui   $t1, %hi(ptr_spectrum_roms) 
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  addiu $t6, $t3, 2
  sra   $t4, $t6, 8
  addu  $t0, $t1, $t8
  b     .L7F0D9E58
   sb    $t4, 1($t0)
.L7F0D9DC0:
  slti  $at, $t5, 0x5800
  bnez  $at, .L7F0D9E04
   lhu   $t9, 0x292($sp)
  lhu   $t9, 0x298($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  addiu $t2, $t9, 2
  sra   $t3, $t2, 8
  addu  $t1, $t6, $t7
  sb    $t3, 1($t1)
  lui   $t4, %hi(ptr_300alloc) 
  lw    $t4, %lo(ptr_300alloc)($t4)
  lhu   $t0, 0x292($sp)
  li    $t8, 1
  addu  $t5, $t4, $t0
  b     .L7F0D9E58
   sb    $t8, -0x57ff($t5)
.L7F0D9E04:
  addiu $t2, $t9, 1
  slti  $at, $t2, 0x4000
  bnez  $at, .L7F0D9E58
   lhu   $t6, 0x298($sp)
  lui   $t1, %hi(ptr_spectrum_roms) 
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  addiu $t7, $t6, 2
  sra   $t3, $t7, 8
  addu  $t4, $t1, $t9
  sb    $t3, 1($t4)
  lhu   $t8, 0x292($sp)
  lui   $t9, %hi(ptr_300alloc) 
  lw    $t9, %lo(ptr_300alloc)($t9)
  addiu $t5, $t8, 1
  andi  $t2, $t5, 0x1800
  sra   $t6, $t2, 3
  andi  $t7, $t5, 0xff
  or    $t1, $t6, $t7
  li    $t0, 1
  addu  $t3, $t9, $t1
  sb    $t0, ($t3)
.L7F0D9E58:
  lui   $t8, %hi(ptr_spectrum_roms) 
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  lhu   $t4, 0x298($sp)
  addu  $t6, $t8, $t4
  lbu   $t7, 1($t6)
  addu  $t2, $t4, $t8
  lbu   $t5, ($t2)
  sll   $t9, $t7, 8
  or    $t1, $t5, $t9
  b     .L7F0E27FC
   sh    $t1, 0x298($sp)
.L7F0D9E84:
  lhu   $t0, 0x298($sp)
  addiu $t3, $t0, 2
  b     .L7F0E27FC
   sh    $t3, 0x298($sp)
spectrum_op_C5:
  lhu   $t4, 0x292($sp)
  lw    $t2, 0x28c($sp)
  lui   $t5, %hi(ptr_spectrum_roms) 
  addiu $t6, $t4, -2
  andi  $t7, $t6, 0xffff
  slti  $at, $t7, 0x5b00
  addiu $t8, $t2, 0xb
  sw    $t8, 0x28c($sp)
  bnez  $at, .L7F0D9ECC
   sh    $t6, 0x292($sp)
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  addu  $t9, $t5, $t7
  b     .L7F0D9F4C
   sb    $s3, ($t9)
.L7F0D9ECC:
  lhu   $t1, 0x292($sp)
  lhu   $t5, 0x292($sp)
  lui   $t0, %hi(ptr_spectrum_roms) 
  slti  $at, $t1, 0x5800
  bnezl $at, .L7F0D9F10
   slti  $at, $t5, 0x4000
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  lui   $t8, %hi(ptr_300alloc) 
  li    $t2, 1
  addu  $t3, $t0, $t1
  sb    $s3, ($t3)
  lhu   $t4, 0x292($sp)
  lw    $t8, %lo(ptr_300alloc)($t8)
  addu  $t6, $t8, $t4
  b     .L7F0D9F4C
   sb    $t2, -0x5800($t6)
  slti  $at, $t5, 0x4000
.L7F0D9F10:
  bnez  $at, .L7F0D9F4C
   lui   $t7, %hi(ptr_spectrum_roms) 
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  lui   $t6, %hi(ptr_300alloc) 
  li    $t0, 1
  addu  $t9, $t7, $t5
  sb    $s3, ($t9)
  lhu   $t1, 0x292($sp)
  lw    $t6, %lo(ptr_300alloc)($t6)
  andi  $t3, $t1, 0x1800
  sra   $t8, $t3, 3
  andi  $t4, $t1, 0xff
  or    $t2, $t8, $t4
  addu  $t7, $t6, $t2
  sb    $t0, ($t7)
.L7F0D9F4C:
  lhu   $t5, 0x292($sp)
  lhu   $t8, 0x292($sp)
  lui   $t3, %hi(ptr_spectrum_roms) 
  addiu $t9, $t5, 1
  slti  $at, $t9, 0x5b00
  bnez  $at, .L7F0D9F78
   addiu $t4, $t8, 1
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  addu  $t1, $t3, $t5
  b     .L7F0E27FC
   sb    $s2, 1($t1)
.L7F0D9F78:
  slti  $at, $t4, 0x5800
  bnez  $at, .L7F0D9FB0
   lhu   $t5, 0x292($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  lui   $t7, %hi(ptr_300alloc) 
  li    $t0, 1
  addu  $t2, $t6, $t8
  sb    $s2, 1($t2)
  lhu   $t9, 0x292($sp)
  lw    $t7, %lo(ptr_300alloc)($t7)
  addu  $t3, $t7, $t9
  b     .L7F0E27FC
   sb    $t0, -0x57ff($t3)
.L7F0D9FB0:
  addiu $t1, $t5, 1
  slti  $at, $t1, 0x4000
  bnez  $at, .L7F0E27FC
   lui   $t4, %hi(ptr_spectrum_roms) 
  lw    $t4, %lo(ptr_spectrum_roms)($t4)
  li    $t8, 1
  addu  $t6, $t4, $t5
  sb    $s2, 1($t6)
  lhu   $t2, 0x292($sp)
  lui   $t4, %hi(ptr_300alloc) 
  lw    $t4, %lo(ptr_300alloc)($t4)
  addiu $t7, $t2, 1
  andi  $t9, $t7, 0x1800
  sra   $t0, $t9, 3
  andi  $t3, $t7, 0xff
  or    $t1, $t0, $t3
  addu  $t5, $t4, $t1
  b     .L7F0E27FC
   sb    $t8, ($t5)
spectrum_op_C6:
  lw    $t6, 0x28c($sp)
  lui   $t7, %hi(ptr_spectrum_roms) 
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  lhu   $t9, 0x298($sp)
  addiu $t2, $t6, 7
  sw    $t2, 0x28c($sp)
  addu  $t0, $t9, $t7
  lbu   $t3, ($t0)
  andi  $t9, $s0, 0xf
  li    $at, 15
  addu  $t1, $s0, $t3
  andi  $t2, $t3, 0xf
  addu  $t7, $t9, $t2
  andi  $t8, $t1, 0xa8
  sra   $t5, $t1, 8
  or    $t6, $t8, $t5
  not   $t5, $s0
  slt   $t0, $at, $t7
  xor   $t7, $t1, $s0
  sh    $t1, 0x140($sp)
  xor   $t9, $t5, $t3
  lbu   $s0, 0x141($sp)
  andi  $t2, $t9, 0x80
  sll   $t4, $t0, 4
  and   $t0, $t2, $t7
  or    $t8, $t6, $t4
  lhu   $t2, 0x298($sp)
  sra   $t6, $t0, 5
  sltiu $t5, $s0, 1
  sll   $t9, $t5, 6
  or    $t4, $t8, $t6
  or    $s1, $t4, $t9
  andi  $t1, $s1, 0xff
  addiu $t7, $t2, 1
  move  $s1, $t1
  sw    $t5, 0x48($sp)
  sh    $t7, 0x298($sp)
  b     .L7F0E27FC
   sb    $t3, 0x13f($sp)
spectrum_op_C7:
  lhu   $t6, 0x292($sp)
  lw    $t0, 0x28c($sp)
  lui   $t9, %hi(ptr_spectrum_roms) 
  addiu $t4, $t6, -2
  andi  $t5, $t4, 0xffff
  slti  $at, $t5, 0x5b00
  addiu $t8, $t0, 0xb
  sw    $t8, 0x28c($sp)
  bnez  $at, .L7F0DA0D4
   sh    $t4, 0x292($sp)
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  lhu   $t3, 0x298($sp)
  addu  $t1, $t9, $t5
  b     .L7F0DA15C
   sb    $t3, ($t1)
.L7F0DA0D4:
  lhu   $t2, 0x292($sp)
  lhu   $t3, 0x292($sp)
  lui   $t0, %hi(ptr_spectrum_roms) 
  slti  $at, $t2, 0x5800
  bnezl $at, .L7F0DA11C
   slti  $at, $t3, 0x4000
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  lhu   $t7, 0x298($sp)
  lui   $t4, %hi(ptr_300alloc) 
  addu  $t8, $t0, $t2
  sb    $t7, ($t8)
  lhu   $t9, 0x292($sp)
  lw    $t4, %lo(ptr_300alloc)($t4)
  li    $t6, 1
  addu  $t5, $t4, $t9
  b     .L7F0DA15C
   sb    $t6, -0x5800($t5)
  slti  $at, $t3, 0x4000
.L7F0DA11C:
  bnez  $at, .L7F0DA15C
   lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  lhu   $t1, 0x298($sp)
  li    $t7, 1
  addu  $t2, $t0, $t3
  sb    $t1, ($t2)
  lhu   $t8, 0x292($sp)
  lui   $t0, %hi(ptr_300alloc) 
  lw    $t0, %lo(ptr_300alloc)($t0)
  andi  $t4, $t8, 0x1800
  sra   $t9, $t4, 3
  andi  $t6, $t8, 0xff
  or    $t5, $t9, $t6
  addu  $t3, $t0, $t5
  sb    $t7, ($t3)
.L7F0DA15C:
  lhu   $t1, 0x292($sp)
  lhu   $t0, 0x292($sp)
  lhu   $t4, 0x298($sp)
  addiu $t2, $t1, 1
  slti  $at, $t2, 0x5b00
  bnez  $at, .L7F0DA190
   addiu $t5, $t0, 1
  lui   $t9, %hi(ptr_spectrum_roms) 
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  sra   $t8, $t4, 8
  addu  $t6, $t9, $t1
  b     .L7F0DA220
   sb    $t8, 1($t6)
.L7F0DA190:
  slti  $at, $t5, 0x5800
  bnez  $at, .L7F0DA1D0
   lhu   $t5, 0x292($sp)
  lui   $t2, %hi(ptr_spectrum_roms) 
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  lhu   $t7, 0x298($sp)
  lui   $t1, %hi(ptr_300alloc) 
  addu  $t4, $t2, $t0
  sra   $t3, $t7, 8
  sb    $t3, 1($t4)
  lhu   $t8, 0x292($sp)
  lw    $t1, %lo(ptr_300alloc)($t1)
  li    $t9, 1
  addu  $t6, $t1, $t8
  b     .L7F0DA220
   sb    $t9, -0x57ff($t6)
.L7F0DA1D0:
  addiu $t7, $t5, 1
  slti  $at, $t7, 0x4000
  bnez  $at, .L7F0DA220
   lhu   $t2, 0x298($sp)
  lui   $t3, %hi(ptr_spectrum_roms) 
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  sra   $t0, $t2, 8
  li    $t1, 1
  addu  $t4, $t3, $t5
  sb    $t0, 1($t4)
  lhu   $t8, 0x292($sp)
  lui   $t5, %hi(ptr_300alloc) 
  lw    $t5, %lo(ptr_300alloc)($t5)
  addiu $t9, $t8, 1
  andi  $t6, $t9, 0x1800
  sra   $t7, $t6, 3
  andi  $t2, $t9, 0xff
  or    $t3, $t7, $t2
  addu  $t0, $t5, $t3
  sb    $t1, ($t0)
.L7F0DA220:
  b     .L7F0E27FC
   sh    $zero, 0x298($sp)
spectrum_op_C8:
  lw    $t4, 0x28c($sp)
  andi  $t6, $s1, 0x40
  lui   $t5, %hi(ptr_spectrum_roms) 
  addiu $t8, $t4, 5
  beqz  $t6, .L7F0E27FC
   sw    $t8, 0x28c($sp)
  lhu   $t2, 0x292($sp)
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  addiu $t7, $t8, 6
  sw    $t7, 0x28c($sp)
  addu  $t0, $t5, $t2
  lbu   $t4, 1($t0)
  addu  $t3, $t2, $t5
  lbu   $t1, ($t3)
  sll   $t8, $t4, 8
  addiu $t9, $t2, 2
  or    $t6, $t1, $t8
  sh    $t6, 0x298($sp)
  b     .L7F0E27FC
   sh    $t9, 0x292($sp)
spectrum_op_C9:
  lw    $t7, 0x28c($sp)
  lui   $t1, %hi(ptr_spectrum_roms) 
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  lhu   $t4, 0x292($sp)
  addiu $t3, $t7, 4
  sw    $t3, 0x28c($sp)
  addiu $t0, $t3, 6
  sw    $t0, 0x28c($sp)
  addu  $t2, $t1, $t4
  lbu   $t9, 1($t2)
  addu  $t8, $t4, $t1
  lbu   $t6, ($t8)
  sll   $t7, $t9, 8
  addiu $t5, $t4, 2
  or    $t3, $t6, $t7
  sh    $t3, 0x298($sp)
  b     .L7F0E27FC
   sh    $t5, 0x292($sp)
spectrum_op_CA:
  lw    $t0, 0x28c($sp)
  andi  $t1, $s1, 0x40
  lhu   $t2, 0x298($sp)
  addiu $t8, $t0, 0xa
  beqz  $t1, .L7F0DA300
   sw    $t8, 0x28c($sp)
  lui   $t9, %hi(ptr_spectrum_roms) 
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  addu  $t3, $t9, $t2
  lbu   $t4, 1($t3)
  addu  $t6, $t2, $t9
  lbu   $t7, ($t6)
  sll   $t5, $t4, 8
  or    $t0, $t7, $t5
  b     .L7F0E27FC
   sh    $t0, 0x298($sp)
.L7F0DA300:
  lhu   $t8, 0x298($sp)
  addiu $t1, $t8, 2
  b     .L7F0E27FC
   sh    $t1, 0x298($sp)
spectrum_op_CB:
  lw    $t6, 0x28c($sp)
  lbu   $t2, 0x287($sp)
  lui   $t3, %hi(ptr_spectrum_roms)
  addiu $t9, $t6, 4
  beqz  $t2, .L7F0DA3A0
   sw    $t9, 0x28c($sp)
  li    $at, 1
  bne   $t2, $at, .L7F0DA340
   lui   $t5, %hi(ptr_spectrum_roms) 
  lhu   $t3, 0x296($sp)
  b     .L7F0DA348
   sw    $t3, 0x48($sp)
.L7F0DA340:
  lhu   $t4, 0x294($sp)
  sw    $t4, 0x48($sp)
.L7F0DA348:
  lhu   $t7, 0x298($sp)
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  lw    $t1, 0x48($sp)
  lw    $t2, 0x28c($sp)
  addu  $t0, $t7, $t5
  lb    $t8, ($t0)
  addiu $t9, $t7, 1
  andi  $t4, $t9, 0xffff
  addiu $t3, $t2, 8
  addu  $t6, $t8, $t1
  sh    $t6, 0x13c($sp)
  sh    $t9, 0x298($sp)
  sw    $t3, 0x28c($sp)
  addu  $t0, $t4, $t5
  lbu   $t8, ($t0)
  andi  $t6, $t8, 0xf8
  ori   $t7, $t6, 6
  sb    $t8, 0x13b($sp)
  andi  $t1, $t8, 7
  sb    $t1, 0x13a($sp)
  b     .L7F0DA3D8
   sb    $t7, 0x13b($sp)
.L7F0DA3A0:
  lhu   $t2, 0x298($sp)
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  lw    $t5, 0x28c($sp)
  lw    $t1, 0x288($sp)
  addu  $t9, $t2, $t3
  lbu   $t4, ($t9)
  sll   $t6, $s6, 8
  or    $t7, $t6, $s7
  addiu $t0, $t5, 4
  addiu $t8, $t1, 1
  sw    $t0, 0x28c($sp)
  sw    $t8, 0x288($sp)
  sh    $t7, 0x13c($sp)
  sb    $t4, 0x13b($sp)
.L7F0DA3D8:
  lhu   $t2, 0x298($sp)
  lbu   $t9, 0x13b($sp)
  lbu   $t7, 0x13b($sp)
  addiu $t3, $t2, 1
  slti  $at, $t9, 0x40
spectrum_op_CB_40_FF:
  beqz  $at, .L7F0DBE80
   sh    $t3, 0x298($sp)
  sltiu $at, $t9, 0x40
def_7F0DBF10:
  beqz  $at, .L7F0DC598
   sll   $t9, $t9, 2
  lui   $at, %hi(jpt_8005C52C)
  addu  $at, $at, $t9
  lw    $t9, %lo(jpt_8005C52C)($at)
  jr    $t9
   nop   
spectrum_op_CB_00:
  sll   $t4, $s2, 1
  sra   $t5, $s2, 7
  or    $s2, $t4, $t5
  andi  $t0, $s2, 0xff
  lui   $t4, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t4, %lo(ptr_pc_keyboard_table_alloc)($t4)
  sltiu $t1, $t0, 1
  sw    $t1, 0x48($sp)
  move  $s2, $t0
  andi  $t8, $t0, 1
  andi  $t6, $t0, 0xa8
  addu  $t5, $t0, $t4
  lbu   $t0, ($t5)
  or    $t7, $t8, $t6
  sll   $t3, $t1, 6
  or    $t9, $t7, $t3
  or    $s1, $t0, $t9
  andi  $t1, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t1
spectrum_op_CB_01:
  sll   $t8, $s3, 1
  sra   $t6, $s3, 7
  or    $s3, $t8, $t6
  andi  $t2, $s3, 0xff
  lui   $t8, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t8, %lo(ptr_pc_keyboard_table_alloc)($t8)
  sltiu $t7, $t2, 1
  sw    $t7, 0x48($sp)
  move  $s3, $t2
  andi  $t3, $t2, 1
  andi  $t4, $t2, 0xa8
  addu  $t6, $t2, $t8
  lbu   $t2, ($t6)
  or    $t5, $t3, $t4
  sll   $t9, $t7, 6
  or    $t1, $t5, $t9
  or    $s1, $t2, $t1
  andi  $t7, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t7
spectrum_op_CB_02:
  sll   $t3, $s4, 1
  sra   $t4, $s4, 7
  or    $s4, $t3, $t4
  andi  $t0, $s4, 0xff
  lui   $t3, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t3, %lo(ptr_pc_keyboard_table_alloc)($t3)
  sltiu $t5, $t0, 1
  sw    $t5, 0x48($sp)
  move  $s4, $t0
  andi  $t9, $t0, 1
  andi  $t8, $t0, 0xa8
  addu  $t4, $t0, $t3
  lbu   $t0, ($t4)
  or    $t6, $t9, $t8
  sll   $t1, $t5, 6
  or    $t7, $t6, $t1
  or    $s1, $t0, $t7
  andi  $t5, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t5
spectrum_op_CB_03:
  sll   $t9, $s5, 1
  sra   $t8, $s5, 7
  or    $s5, $t9, $t8
  andi  $t2, $s5, 0xff
  lui   $t9, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t9, %lo(ptr_pc_keyboard_table_alloc)($t9)
  sltiu $t6, $t2, 1
  sw    $t6, 0x48($sp)
  move  $s5, $t2
  andi  $t1, $t2, 1
  andi  $t3, $t2, 0xa8
  addu  $t8, $t2, $t9
  lbu   $t2, ($t8)
  or    $t4, $t1, $t3
  sll   $t7, $t6, 6
  or    $t5, $t4, $t7
  or    $s1, $t2, $t5
  andi  $t6, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t6
spectrum_op_CB_04:
  sll   $t1, $s6, 1
  sra   $t3, $s6, 7
  or    $s6, $t1, $t3
  andi  $t0, $s6, 0xff
  lui   $t1, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t1, %lo(ptr_pc_keyboard_table_alloc)($t1)
  sltiu $t4, $t0, 1
  sw    $t4, 0x48($sp)
  move  $s6, $t0
  andi  $t7, $t0, 1
  andi  $t9, $t0, 0xa8
  addu  $t3, $t0, $t1
  lbu   $t0, ($t3)
  or    $t8, $t7, $t9
  sll   $t5, $t4, 6
  or    $t6, $t8, $t5
  or    $s1, $t0, $t6
  andi  $t4, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t4
spectrum_op_CB_05:
  sll   $t7, $s7, 1
  sra   $t9, $s7, 7
  or    $s7, $t7, $t9
  andi  $t2, $s7, 0xff
  lui   $t7, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t7, %lo(ptr_pc_keyboard_table_alloc)($t7)
  sltiu $t8, $t2, 1
  sw    $t8, 0x48($sp)
  move  $s7, $t2
  andi  $t5, $t2, 1
  andi  $t1, $t2, 0xa8
  addu  $t9, $t2, $t7
  lbu   $t2, ($t9)
  or    $t3, $t5, $t1
  sll   $t6, $t8, 6
  or    $t4, $t3, $t6
  or    $s1, $t2, $t4
  andi  $t8, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t8
spectrum_op_CB_06:
  lw    $t5, 0x28c($sp)
  lui   $t3, %hi(ptr_spectrum_roms) 
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  lhu   $t0, 0x13c($sp)
  addiu $t1, $t5, 7
  sw    $t1, 0x28c($sp)
  addu  $t6, $t0, $t3
  lbu   $t7, ($t6)
  sll   $t9, $t7, 1
  sra   $t2, $t7, 7
  or    $t4, $t9, $t2
  andi  $t8, $t4, 0xff
  sltiu $t5, $t8, 1
  lui   $t8, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t8, %lo(ptr_pc_keyboard_table_alloc)($t8)
  andi  $t1, $t4, 0xff
  sb    $t7, 0x139($sp)
  andi  $t0, $t1, 1
  andi  $t6, $t4, 0xa8
  or    $t7, $t0, $t6
  sb    $t4, 0x139($sp)
  sw    $t5, 0x48($sp)
  addu  $t3, $t1, $t8
  lbu   $t0, ($t3)
  sll   $t9, $t5, 6
  lhu   $t5, 0x13c($sp)
  or    $t2, $t7, $t9
  or    $s1, $t0, $t2
  andi  $t6, $s1, 0xff
  slti  $at, $t5, 0x5b00
  bnez  $at, .L7F0DA68C
   move  $s1, $t6
  lui   $t9, %hi(ptr_spectrum_roms) 
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  move  $t7, $t4
  addu  $t4, $t9, $t5
  b     .L7F0DC598
   sb    $t7, ($t4)
.L7F0DA68C:
  lhu   $t1, 0x13c($sp)
  lhu   $t7, 0x13c($sp)
  lui   $t3, %hi(ptr_spectrum_roms) 
  slti  $at, $t1, 0x5800
  bnezl $at, .L7F0DA6D4
   slti  $at, $t7, 0x4000
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  lbu   $t8, 0x139($sp)
  lui   $t6, %hi(ptr_300alloc) 
  addu  $t0, $t3, $t1
  sb    $t8, ($t0)
  lhu   $t9, 0x13c($sp)
  lw    $t6, %lo(ptr_300alloc)($t6)
  li    $t2, 1
  addu  $t5, $t6, $t9
  b     .L7F0DC598
   sb    $t2, -0x5800($t5)
  slti  $at, $t7, 0x4000
.L7F0DA6D4:
  bnez  $at, .L7F0DC598
   lui   $t3, %hi(ptr_spectrum_roms) 
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  lbu   $t4, 0x139($sp)
  li    $t8, 1
  addu  $t1, $t3, $t7
  sb    $t4, ($t1)
  lhu   $t0, 0x13c($sp)
  lui   $t3, %hi(ptr_300alloc) 
  lw    $t3, %lo(ptr_300alloc)($t3)
  andi  $t6, $t0, 0x1800
  sra   $t9, $t6, 3
  andi  $t2, $t0, 0xff
  or    $t5, $t9, $t2
  addu  $t7, $t3, $t5
  b     .L7F0DC598
   sb    $t8, ($t7)
spectrum_op_CB_07:
  sll   $t4, $s0, 1
  sra   $t1, $s0, 7
  or    $s0, $t4, $t1
  andi  $t6, $s0, 0xff
  lui   $t4, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t4, %lo(ptr_pc_keyboard_table_alloc)($t4)
  sltiu $t0, $t6, 1
  sw    $t0, 0x48($sp)
  move  $s0, $t6
  andi  $t9, $t6, 1
  andi  $t2, $t6, 0xa8
  addu  $t1, $t6, $t4
  lbu   $t6, ($t1)
  or    $t3, $t9, $t2
  sll   $t8, $t0, 6
  or    $t7, $t3, $t8
  or    $s1, $t6, $t7
  andi  $t0, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t0
spectrum_op_CB_08:
  andi  $t5, $s2, 1
  sll   $t3, $t5, 7
  sra   $t2, $s2, 1
  or    $s2, $t2, $t3
  andi  $t8, $s2, 0xff
  lui   $t2, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t2, %lo(ptr_pc_keyboard_table_alloc)($t2)
  sltiu $t4, $t8, 1
  sw    $t4, 0x48($sp)
  move  $s2, $t8
  andi  $t1, $t8, 0xa8
  sb    $t5, 0x138($sp)
  addu  $t3, $t8, $t2
  lbu   $t8, ($t3)
  or    $t6, $t5, $t1
  sll   $t0, $t4, 6
  or    $t9, $t6, $t0
  or    $s1, $t8, $t9
  andi  $t4, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t4
spectrum_op_CB_09:
  andi  $t7, $s3, 1
  sll   $t6, $t7, 7
  sra   $t1, $s3, 1
  or    $s3, $t1, $t6
  andi  $t0, $s3, 0xff
  lui   $t1, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t1, %lo(ptr_pc_keyboard_table_alloc)($t1)
  sltiu $t2, $t0, 1
  sw    $t2, 0x48($sp)
  move  $s3, $t0
  andi  $t3, $t0, 0xa8
  sb    $t7, 0x137($sp)
  addu  $t6, $t0, $t1
  lbu   $t0, ($t6)
  or    $t8, $t7, $t3
  sll   $t4, $t2, 6
  or    $t5, $t8, $t4
  or    $s1, $t0, $t5
  andi  $t2, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t2
spectrum_op_CB_0A:
  andi  $t9, $s4, 1
  sll   $t8, $t9, 7
  sra   $t3, $s4, 1
  or    $s4, $t3, $t8
  andi  $t4, $s4, 0xff
  lui   $t3, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t3, %lo(ptr_pc_keyboard_table_alloc)($t3)
  sltiu $t1, $t4, 1
  sw    $t1, 0x48($sp)
  move  $s4, $t4
  andi  $t6, $t4, 0xa8
  sb    $t9, 0x136($sp)
  addu  $t8, $t4, $t3
  lbu   $t4, ($t8)
  or    $t0, $t9, $t6
  sll   $t2, $t1, 6
  or    $t7, $t0, $t2
  or    $s1, $t4, $t7
  andi  $t1, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t1
spectrum_op_CB_0B:
  andi  $t5, $s5, 1
  sll   $t0, $t5, 7
  sra   $t6, $s5, 1
  or    $s5, $t6, $t0
  andi  $t2, $s5, 0xff
  lui   $t6, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t6, %lo(ptr_pc_keyboard_table_alloc)($t6)
  sltiu $t3, $t2, 1
  sw    $t3, 0x48($sp)
  move  $s5, $t2
  andi  $t8, $t2, 0xa8
  sb    $t5, 0x135($sp)
  addu  $t0, $t2, $t6
  lbu   $t2, ($t0)
  or    $t4, $t5, $t8
  sll   $t1, $t3, 6
  or    $t9, $t4, $t1
  or    $s1, $t2, $t9
  andi  $t3, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t3
spectrum_op_CB_0C:
  andi  $t7, $s6, 1
  sll   $t4, $t7, 7
  sra   $t8, $s6, 1
  or    $s6, $t8, $t4
  andi  $t1, $s6, 0xff
  lui   $t8, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t8, %lo(ptr_pc_keyboard_table_alloc)($t8)
  sltiu $t6, $t1, 1
  sw    $t6, 0x48($sp)
  move  $s6, $t1
  andi  $t0, $t1, 0xa8
  sb    $t7, 0x134($sp)
  addu  $t4, $t1, $t8
  lbu   $t1, ($t4)
  or    $t2, $t7, $t0
  sll   $t3, $t6, 6
  or    $t5, $t2, $t3
  or    $s1, $t1, $t5
  andi  $t6, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t6
spectrum_op_CB_0D:
  andi  $t9, $s7, 1
  sll   $t2, $t9, 7
  sra   $t0, $s7, 1
  or    $s7, $t0, $t2
  andi  $t3, $s7, 0xff
  lui   $t0, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t0, %lo(ptr_pc_keyboard_table_alloc)($t0)
  sltiu $t8, $t3, 1
  sw    $t8, 0x48($sp)
  move  $s7, $t3
  andi  $t4, $t3, 0xa8
  sb    $t9, 0x133($sp)
  addu  $t2, $t3, $t0
  lbu   $t3, ($t2)
  or    $t1, $t9, $t4
  sll   $t6, $t8, 6
  or    $t7, $t1, $t6
  or    $s1, $t3, $t7
  andi  $t8, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t8
spectrum_op_CB_0E:
  lw    $t9, 0x28c($sp)
  lui   $t1, %hi(ptr_spectrum_roms) 
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  lhu   $t5, 0x13c($sp)
  addiu $t4, $t9, 7
  sw    $t4, 0x28c($sp)
  addu  $t6, $t5, $t1
  lbu   $t0, ($t6)
  andi  $t2, $t0, 0xff
  andi  $t6, $t2, 1
  andi  $t8, $t6, 0xff
  sll   $t9, $t8, 7
  sra   $t7, $t2, 1
  or    $t4, $t7, $t9
  lui   $t9, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t9, %lo(ptr_pc_keyboard_table_alloc)($t9)
  andi  $t5, $t4, 0xff
  sb    $t0, 0x139($sp)
  sltiu $t1, $t5, 1
  andi  $t2, $t4, 0xa8
  or    $t3, $t6, $t2
  sw    $t1, 0x48($sp)
  sb    $t4, 0x139($sp)
  sb    $t6, 0x132($sp)
  addu  $t0, $t5, $t9
  lbu   $t6, ($t0)
  sll   $t8, $t1, 6
  lhu   $t1, 0x13c($sp)
  or    $t7, $t3, $t8
  or    $s1, $t6, $t7
  andi  $t2, $s1, 0xff
  slti  $at, $t1, 0x5b00
  bnez  $at, .L7F0DAA00
   move  $s1, $t2
  lui   $t8, %hi(ptr_spectrum_roms) 
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  move  $t3, $t4
  addu  $t4, $t8, $t1
  b     .L7F0DC598
   sb    $t3, ($t4)
.L7F0DAA00:
  lhu   $t5, 0x13c($sp)
  lhu   $t3, 0x13c($sp)
  lui   $t0, %hi(ptr_spectrum_roms) 
  slti  $at, $t5, 0x5800
  bnezl $at, .L7F0DAA48
   slti  $at, $t3, 0x4000
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  lbu   $t9, 0x139($sp)
  lui   $t2, %hi(ptr_300alloc) 
  addu  $t6, $t0, $t5
  sb    $t9, ($t6)
  lhu   $t8, 0x13c($sp)
  lw    $t2, %lo(ptr_300alloc)($t2)
  li    $t7, 1
  addu  $t1, $t2, $t8
  b     .L7F0DC598
   sb    $t7, -0x5800($t1)
  slti  $at, $t3, 0x4000
.L7F0DAA48:
  bnez  $at, .L7F0DC598
   lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  lbu   $t4, 0x139($sp)
  li    $t9, 1
  addu  $t5, $t0, $t3
  sb    $t4, ($t5)
  lhu   $t6, 0x13c($sp)
  lui   $t0, %hi(ptr_300alloc) 
  lw    $t0, %lo(ptr_300alloc)($t0)
  andi  $t2, $t6, 0x1800
  sra   $t8, $t2, 3
  andi  $t7, $t6, 0xff
  or    $t1, $t8, $t7
  addu  $t3, $t0, $t1
  b     .L7F0DC598
   sb    $t9, ($t3)
spectrum_op_CB_0F:
  andi  $t2, $s0, 1
  sll   $t6, $t2, 7
  sra   $t5, $s0, 1
  or    $s0, $t5, $t6
  andi  $t8, $s0, 0xff
  lui   $t5, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t5, %lo(ptr_pc_keyboard_table_alloc)($t5)
  sltiu $t7, $t8, 1
  sw    $t7, 0x48($sp)
  move  $s0, $t8
  andi  $t0, $t8, 0xa8
  sb    $t2, 0x131($sp)
  addu  $t6, $t8, $t5
  lbu   $t8, ($t6)
  or    $t1, $t2, $t0
  sll   $t3, $t7, 6
  or    $t4, $t1, $t3
  or    $s1, $t8, $t4
  andi  $t7, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t7
spectrum_op_CB_10:
  sra   $t5, $s2, 7
  sll   $t0, $s2, 1
  andi  $t9, $s1, 1
  or    $s2, $t0, $t9
  andi  $t1, $s2, 0xff
  lui   $t0, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t0, %lo(ptr_pc_keyboard_table_alloc)($t0)
  sltiu $t3, $t1, 1
  sw    $t3, 0x48($sp)
  move  $s2, $t1
  andi  $t6, $t1, 0xa8
  sb    $t5, 0x130($sp)
  addu  $t9, $t1, $t0
  lbu   $t1, ($t9)
  or    $t8, $t5, $t6
  sll   $t7, $t3, 6
  or    $t2, $t8, $t7
  or    $s1, $t1, $t2
  andi  $t3, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t3
spectrum_op_CB_11:
  sra   $t0, $s3, 7
  sll   $t6, $s3, 1
  andi  $t4, $s1, 1
  or    $s3, $t6, $t4
  andi  $t8, $s3, 0xff
  lui   $t6, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t6, %lo(ptr_pc_keyboard_table_alloc)($t6)
  sltiu $t7, $t8, 1
  sw    $t7, 0x48($sp)
  move  $s3, $t8
  andi  $t9, $t8, 0xa8
  sb    $t0, 0x12f($sp)
  addu  $t4, $t8, $t6
  lbu   $t8, ($t4)
  or    $t1, $t0, $t9
  sll   $t3, $t7, 6
  or    $t5, $t1, $t3
  or    $s1, $t8, $t5
  andi  $t7, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t7
spectrum_op_CB_12:
  sra   $t6, $s4, 7
  sll   $t9, $s4, 1
  andi  $t2, $s1, 1
  or    $s4, $t9, $t2
  andi  $t1, $s4, 0xff
  lui   $t9, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t9, %lo(ptr_pc_keyboard_table_alloc)($t9)
  sltiu $t3, $t1, 1
  sw    $t3, 0x48($sp)
  move  $s4, $t1
  andi  $t4, $t1, 0xa8
  sb    $t6, 0x12e($sp)
  addu  $t2, $t1, $t9
  lbu   $t1, ($t2)
  or    $t8, $t6, $t4
  sll   $t7, $t3, 6
  or    $t0, $t8, $t7
  or    $s1, $t1, $t0
  andi  $t3, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t3
spectrum_op_CB_13:
  sra   $t9, $s5, 7
  sll   $t4, $s5, 1
  andi  $t5, $s1, 1
  or    $s5, $t4, $t5
  andi  $t8, $s5, 0xff
  lui   $t4, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t4, %lo(ptr_pc_keyboard_table_alloc)($t4)
  sltiu $t7, $t8, 1
  sw    $t7, 0x48($sp)
  move  $s5, $t8
  andi  $t2, $t8, 0xa8
  sb    $t9, 0x12d($sp)
  addu  $t5, $t8, $t4
  lbu   $t8, ($t5)
  or    $t1, $t9, $t2
  sll   $t3, $t7, 6
  or    $t6, $t1, $t3
  or    $s1, $t8, $t6
  andi  $t7, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t7
spectrum_op_CB_14:
  sra   $t4, $s6, 7
  sll   $t2, $s6, 1
  andi  $t0, $s1, 1
  or    $s6, $t2, $t0
  andi  $t1, $s6, 0xff
  lui   $t2, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t2, %lo(ptr_pc_keyboard_table_alloc)($t2)
  sltiu $t3, $t1, 1
  sw    $t3, 0x48($sp)
  move  $s6, $t1
  andi  $t5, $t1, 0xa8
  sb    $t4, 0x12c($sp)
  addu  $t0, $t1, $t2
  lbu   $t1, ($t0)
  or    $t8, $t4, $t5
  sll   $t7, $t3, 6
  or    $t9, $t8, $t7
  or    $s1, $t1, $t9
  andi  $t3, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t3
spectrum_op_CB_15:
  sra   $t2, $s7, 7
  sll   $t5, $s7, 1
  andi  $t6, $s1, 1
  or    $s7, $t5, $t6
  andi  $t8, $s7, 0xff
  lui   $t5, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t5, %lo(ptr_pc_keyboard_table_alloc)($t5)
  sltiu $t7, $t8, 1
  sw    $t7, 0x48($sp)
  move  $s7, $t8
  andi  $t0, $t8, 0xa8
  sb    $t2, 0x12b($sp)
  addu  $t6, $t8, $t5
  lbu   $t8, ($t6)
  or    $t1, $t2, $t0
  sll   $t3, $t7, 6
  or    $t4, $t1, $t3
  or    $s1, $t8, $t4
  andi  $t7, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t7
spectrum_op_CB_16:
  lw    $t2, 0x28c($sp)
  lui   $t1, %hi(ptr_spectrum_roms) 
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  lhu   $t9, 0x13c($sp)
  addiu $t0, $t2, 7
  sw    $t0, 0x28c($sp)
  addu  $t3, $t9, $t1
  lbu   $t5, ($t3)
  andi  $t7, $s1, 1
  andi  $t6, $t5, 0xff
  sll   $t4, $t6, 1
  or    $t2, $t4, $t7
  lui   $t7, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t7, %lo(ptr_pc_keyboard_table_alloc)($t7)
  sra   $t1, $t6, 7
  andi  $t0, $t2, 0xff
  sb    $t5, 0x139($sp)
  andi  $t5, $t2, 0xa8
  sltiu $t9, $t0, 1
  sw    $t9, 0x48($sp)
  or    $t8, $t1, $t5
  sb    $t2, 0x139($sp)
  sb    $t1, 0x12a($sp)
  addu  $t3, $t0, $t7
  lbu   $t1, ($t3)
  sll   $t6, $t9, 6
  lhu   $t9, 0x13c($sp)
  or    $t4, $t8, $t6
  or    $s1, $t1, $t4
  andi  $t5, $s1, 0xff
  slti  $at, $t9, 0x5b00
  bnez  $at, .L7F0DAD74
   move  $s1, $t5
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  move  $t8, $t2
  addu  $t2, $t6, $t9
  b     .L7F0DC598
   sb    $t8, ($t2)
.L7F0DAD74:
  lhu   $t0, 0x13c($sp)
  lhu   $t8, 0x13c($sp)
  lui   $t3, %hi(ptr_spectrum_roms) 
  slti  $at, $t0, 0x5800
  bnezl $at, .L7F0DADBC
   slti  $at, $t8, 0x4000
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  lbu   $t7, 0x139($sp)
  lui   $t5, %hi(ptr_300alloc) 
  addu  $t1, $t3, $t0
  sb    $t7, ($t1)
  lhu   $t6, 0x13c($sp)
  lw    $t5, %lo(ptr_300alloc)($t5)
  li    $t4, 1
  addu  $t9, $t5, $t6
  b     .L7F0DC598
   sb    $t4, -0x5800($t9)
  slti  $at, $t8, 0x4000
.L7F0DADBC:
  bnez  $at, .L7F0DC598
   lui   $t3, %hi(ptr_spectrum_roms) 
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  lbu   $t2, 0x139($sp)
  li    $t7, 1
  addu  $t0, $t3, $t8
  sb    $t2, ($t0)
  lhu   $t1, 0x13c($sp)
  lui   $t3, %hi(ptr_300alloc) 
  lw    $t3, %lo(ptr_300alloc)($t3)
  andi  $t5, $t1, 0x1800
  sra   $t6, $t5, 3
  andi  $t4, $t1, 0xff
  or    $t9, $t6, $t4
  addu  $t8, $t3, $t9
  b     .L7F0DC598
   sb    $t7, ($t8)
spectrum_op_CB_17:
  sra   $t4, $s0, 7
  sll   $t0, $s0, 1
  andi  $t5, $s1, 1
  or    $s0, $t0, $t5
  andi  $t1, $s0, 0xff
  lui   $t0, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t0, %lo(ptr_pc_keyboard_table_alloc)($t0)
  sltiu $t6, $t1, 1
  sw    $t6, 0x48($sp)
  move  $s0, $t1
  andi  $t3, $t1, 0xa8
  sb    $t4, 0x129($sp)
  addu  $t5, $t1, $t0
  lbu   $t1, ($t5)
  or    $t9, $t4, $t3
  sll   $t8, $t6, 6
  or    $t2, $t9, $t8
  or    $s1, $t1, $t2
  andi  $t6, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t6
spectrum_op_CB_18:
  andi  $t0, $s2, 1
  sra   $t3, $s2, 1
  sll   $t7, $s1, 7
  or    $s2, $t3, $t7
  andi  $t9, $s2, 0xff
  lui   $t3, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t3, %lo(ptr_pc_keyboard_table_alloc)($t3)
  sltiu $t8, $t9, 1
  sw    $t8, 0x48($sp)
  move  $s2, $t9
  andi  $t5, $t9, 0xa8
  sb    $t0, 0x128($sp)
  addu  $t7, $t9, $t3
  lbu   $t9, ($t7)
  or    $t1, $t0, $t5
  sll   $t6, $t8, 6
  or    $t4, $t1, $t6
  or    $s1, $t9, $t4
  andi  $t8, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t8
spectrum_op_CB_19:
  andi  $t3, $s3, 1
  sra   $t5, $s3, 1
  sll   $t2, $s1, 7
  or    $s3, $t5, $t2
  andi  $t1, $s3, 0xff
  lui   $t5, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t5, %lo(ptr_pc_keyboard_table_alloc)($t5)
  sltiu $t6, $t1, 1
  sw    $t6, 0x48($sp)
  move  $s3, $t1
  andi  $t7, $t1, 0xa8
  sb    $t3, 0x127($sp)
  addu  $t2, $t1, $t5
  lbu   $t1, ($t2)
  or    $t9, $t3, $t7
  sll   $t8, $t6, 6
  or    $t0, $t9, $t8
  or    $s1, $t1, $t0
  andi  $t6, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t6
spectrum_op_CB_1A:
  andi  $t5, $s4, 1
  sra   $t7, $s4, 1
  sll   $t4, $s1, 7
  or    $s4, $t7, $t4
  andi  $t9, $s4, 0xff
  lui   $t7, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t7, %lo(ptr_pc_keyboard_table_alloc)($t7)
  sltiu $t8, $t9, 1
  sw    $t8, 0x48($sp)
  move  $s4, $t9
  andi  $t2, $t9, 0xa8
  sb    $t5, 0x126($sp)
  addu  $t4, $t9, $t7
  lbu   $t9, ($t4)
  or    $t1, $t5, $t2
  sll   $t6, $t8, 6
  or    $t3, $t1, $t6
  or    $s1, $t9, $t3
  andi  $t8, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t8
spectrum_op_CB_1B:
  andi  $t7, $s5, 1
  sra   $t2, $s5, 1
  sll   $t0, $s1, 7
  or    $s5, $t2, $t0
  andi  $t1, $s5, 0xff
  lui   $t2, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t2, %lo(ptr_pc_keyboard_table_alloc)($t2)
  sltiu $t6, $t1, 1
  sw    $t6, 0x48($sp)
  move  $s5, $t1
  andi  $t4, $t1, 0xa8
  sb    $t7, 0x125($sp)
  addu  $t0, $t1, $t2
  lbu   $t1, ($t0)
  or    $t9, $t7, $t4
  sll   $t8, $t6, 6
  or    $t5, $t9, $t8
  or    $s1, $t1, $t5
  andi  $t6, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t6
spectrum_op_CB_1C:
  andi  $t2, $s6, 1
  sra   $t4, $s6, 1
  sll   $t3, $s1, 7
  or    $s6, $t4, $t3
  andi  $t9, $s6, 0xff
  lui   $t4, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t4, %lo(ptr_pc_keyboard_table_alloc)($t4)
  sltiu $t8, $t9, 1
  sw    $t8, 0x48($sp)
  move  $s6, $t9
  andi  $t0, $t9, 0xa8
  sb    $t2, 0x124($sp)
  addu  $t3, $t9, $t4
  lbu   $t9, ($t3)
  or    $t1, $t2, $t0
  sll   $t6, $t8, 6
  or    $t7, $t1, $t6
  or    $s1, $t9, $t7
  andi  $t8, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t8
spectrum_op_CB_1D:
  andi  $t4, $s7, 1
  sra   $t0, $s7, 1
  sll   $t5, $s1, 7
  or    $s7, $t0, $t5
  andi  $t1, $s7, 0xff
  lui   $t0, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t0, %lo(ptr_pc_keyboard_table_alloc)($t0)
  sltiu $t6, $t1, 1
  sw    $t6, 0x48($sp)
  move  $s7, $t1
  andi  $t3, $t1, 0xa8
  sb    $t4, 0x123($sp)
  addu  $t5, $t1, $t0
  lbu   $t1, ($t5)
  or    $t9, $t4, $t3
  sll   $t8, $t6, 6
  or    $t2, $t9, $t8
  or    $s1, $t1, $t2
  andi  $t6, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t6
spectrum_op_CB_1E:
  lw    $t4, 0x28c($sp)
  lui   $t9, %hi(ptr_spectrum_roms) 
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  lhu   $t7, 0x13c($sp)
  addiu $t3, $t4, 7
  sw    $t3, 0x28c($sp)
  addu  $t8, $t7, $t9
  lbu   $t0, ($t8)
  sll   $t6, $s1, 7
  andi  $t5, $t0, 0xff
  sra   $t2, $t5, 1
  or    $t4, $t2, $t6
  lui   $t6, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t6, %lo(ptr_pc_keyboard_table_alloc)($t6)
  andi  $t9, $t5, 1
  andi  $t3, $t4, 0xff
  sb    $t0, 0x139($sp)
  andi  $t0, $t4, 0xa8
  sltiu $t7, $t3, 1
  sw    $t7, 0x48($sp)
  or    $t1, $t9, $t0
  sb    $t4, 0x139($sp)
  sb    $t9, 0x122($sp)
  addu  $t8, $t3, $t6
  lbu   $t9, ($t8)
  sll   $t5, $t7, 6
  lhu   $t7, 0x13c($sp)
  or    $t2, $t1, $t5
  or    $s1, $t9, $t2
  andi  $t0, $s1, 0xff
  slti  $at, $t7, 0x5b00
  bnez  $at, .L7F0DB0E8
   move  $s1, $t0
  lui   $t5, %hi(ptr_spectrum_roms) 
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  move  $t1, $t4
  addu  $t4, $t5, $t7
  b     .L7F0DC598
   sb    $t1, ($t4)
.L7F0DB0E8:
  lhu   $t3, 0x13c($sp)
  lhu   $t1, 0x13c($sp)
  lui   $t8, %hi(ptr_spectrum_roms) 
  slti  $at, $t3, 0x5800
  bnezl $at, .L7F0DB130
   slti  $at, $t1, 0x4000
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  lbu   $t6, 0x139($sp)
  lui   $t0, %hi(ptr_300alloc) 
  addu  $t9, $t8, $t3
  sb    $t6, ($t9)
  lhu   $t5, 0x13c($sp)
  lw    $t0, %lo(ptr_300alloc)($t0)
  li    $t2, 1
  addu  $t7, $t0, $t5
  b     .L7F0DC598
   sb    $t2, -0x5800($t7)
  slti  $at, $t1, 0x4000
.L7F0DB130:
  bnez  $at, .L7F0DC598
   lui   $t8, %hi(ptr_spectrum_roms) 
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  lbu   $t4, 0x139($sp)
  li    $t6, 1
  addu  $t3, $t8, $t1
  sb    $t4, ($t3)
  lhu   $t9, 0x13c($sp)
  lui   $t8, %hi(ptr_300alloc) 
  lw    $t8, %lo(ptr_300alloc)($t8)
  andi  $t0, $t9, 0x1800
  sra   $t5, $t0, 3
  andi  $t2, $t9, 0xff
  or    $t7, $t5, $t2
  addu  $t1, $t8, $t7
  b     .L7F0DC598
   sb    $t6, ($t1)
spectrum_op_CB_1F:
  andi  $t2, $s0, 1
  sra   $t3, $s0, 1
  sll   $t0, $s1, 7
  or    $s0, $t3, $t0
  andi  $t9, $s0, 0xff
  lui   $t3, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t3, %lo(ptr_pc_keyboard_table_alloc)($t3)
  sltiu $t5, $t9, 1
  sw    $t5, 0x48($sp)
  move  $s0, $t9
  andi  $t8, $t9, 0xa8
  sb    $t2, 0x121($sp)
  addu  $t0, $t9, $t3
  lbu   $t9, ($t0)
  or    $t7, $t2, $t8
  sll   $t1, $t5, 6
  or    $t4, $t7, $t1
  or    $s1, $t9, $t4
  andi  $t5, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t5
spectrum_op_CB_20:
  lui   $t2, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t2, %lo(ptr_pc_keyboard_table_alloc)($t2)
  sra   $t1, $s2, 7
  sll   $t8, $s2, 1
  andi  $s2, $t8, 0xff
  sltiu $t7, $s2, 1
  sw    $t7, 0x48($sp)
  sb    $t1, 0x120($sp)
  addu  $t8, $s2, $t2
  lbu   $t6, ($t8)
  andi  $t3, $s2, 0xa8
  or    $t0, $t1, $t3
  sll   $t4, $t7, 6
  or    $t5, $t0, $t4
  or    $s1, $t6, $t5
  andi  $t7, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t7
spectrum_op_CB_21:
  lui   $t1, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t1, %lo(ptr_pc_keyboard_table_alloc)($t1)
  sra   $t4, $s3, 7
  sll   $t3, $s3, 1
  andi  $s3, $t3, 0xff
  sltiu $t0, $s3, 1
  sw    $t0, 0x48($sp)
  sb    $t4, 0x11f($sp)
  addu  $t3, $s3, $t1
  lbu   $t9, ($t3)
  andi  $t2, $s3, 0xa8
  or    $t8, $t4, $t2
  sll   $t5, $t0, 6
  or    $t7, $t8, $t5
  or    $s1, $t9, $t7
  andi  $t0, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t0
spectrum_op_CB_22:
  lui   $t4, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t4, %lo(ptr_pc_keyboard_table_alloc)($t4)
  sra   $t5, $s4, 7
  sll   $t2, $s4, 1
  andi  $s4, $t2, 0xff
  sltiu $t8, $s4, 1
  sw    $t8, 0x48($sp)
  sb    $t5, 0x11e($sp)
  addu  $t2, $s4, $t4
  lbu   $t6, ($t2)
  andi  $t1, $s4, 0xa8
  or    $t3, $t5, $t1
  sll   $t7, $t8, 6
  or    $t0, $t3, $t7
  or    $s1, $t6, $t0
  andi  $t8, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t8
spectrum_op_CB_23:
  lui   $t5, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t5, %lo(ptr_pc_keyboard_table_alloc)($t5)
  sra   $t7, $s5, 7
  sll   $t1, $s5, 1
  andi  $s5, $t1, 0xff
  sltiu $t3, $s5, 1
  sw    $t3, 0x48($sp)
  sb    $t7, 0x11d($sp)
  addu  $t1, $s5, $t5
  lbu   $t9, ($t1)
  andi  $t4, $s5, 0xa8
  or    $t2, $t7, $t4
  sll   $t0, $t3, 6
  or    $t8, $t2, $t0
  or    $s1, $t9, $t8
  andi  $t3, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t3
spectrum_op_CB_24:
  lui   $t7, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t7, %lo(ptr_pc_keyboard_table_alloc)($t7)
  sra   $t0, $s6, 7
  sll   $t4, $s6, 1
  andi  $s6, $t4, 0xff
  sltiu $t2, $s6, 1
  sw    $t2, 0x48($sp)
  sb    $t0, 0x11c($sp)
  addu  $t4, $s6, $t7
  lbu   $t6, ($t4)
  andi  $t5, $s6, 0xa8
  or    $t1, $t0, $t5
  sll   $t8, $t2, 6
  or    $t3, $t1, $t8
  or    $s1, $t6, $t3
  andi  $t2, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t2
spectrum_op_CB_25:
  lui   $t0, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t0, %lo(ptr_pc_keyboard_table_alloc)($t0)
  sra   $t8, $s7, 7
  sll   $t5, $s7, 1
  andi  $s7, $t5, 0xff
  sltiu $t1, $s7, 1
  sw    $t1, 0x48($sp)
  sb    $t8, 0x11b($sp)
  addu  $t5, $s7, $t0
  lbu   $t9, ($t5)
  andi  $t7, $s7, 0xa8
  or    $t4, $t8, $t7
  sll   $t3, $t1, 6
  or    $t2, $t4, $t3
  or    $s1, $t9, $t2
  andi  $t1, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t1
spectrum_op_CB_26:
  lw    $t8, 0x28c($sp)
  lui   $t4, %hi(ptr_spectrum_roms) 
  lw    $t4, %lo(ptr_spectrum_roms)($t4)
  lhu   $t6, 0x13c($sp)
  addiu $t7, $t8, 7
  sw    $t7, 0x28c($sp)
  addu  $t3, $t6, $t4
  lbu   $t0, ($t3)
  andi  $t5, $t0, 0xff
  sra   $t7, $t5, 7
  sll   $t2, $t5, 1
  lui   $t5, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t5, %lo(ptr_pc_keyboard_table_alloc)($t5)
  andi  $t1, $t2, 0xff
  sb    $t0, 0x139($sp)
  sltiu $t8, $t1, 1
  andi  $t4, $t2, 0xa8
  or    $t3, $t7, $t4
  sw    $t8, 0x48($sp)
  sb    $t2, 0x139($sp)
  sb    $t7, 0x11a($sp)
  addu  $t6, $t1, $t5
  lbu   $t7, ($t6)
  sll   $t0, $t8, 6
  lhu   $t8, 0x13c($sp)
  or    $t9, $t3, $t0
  or    $s1, $t7, $t9
  andi  $t4, $s1, 0xff
  slti  $at, $t8, 0x5b00
  bnez  $at, .L7F0DB40C
   move  $s1, $t4
  lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  move  $t3, $t2
  addu  $t2, $t0, $t8
  b     .L7F0DC598
   sb    $t3, ($t2)
.L7F0DB40C:
  lhu   $t1, 0x13c($sp)
  lhu   $t3, 0x13c($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  slti  $at, $t1, 0x5800
  bnezl $at, .L7F0DB454
   slti  $at, $t3, 0x4000
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  lbu   $t5, 0x139($sp)
  lui   $t4, %hi(ptr_300alloc) 
  addu  $t7, $t6, $t1
  sb    $t5, ($t7)
  lhu   $t0, 0x13c($sp)
  lw    $t4, %lo(ptr_300alloc)($t4)
  li    $t9, 1
  addu  $t8, $t4, $t0
  b     .L7F0DC598
   sb    $t9, -0x5800($t8)
  slti  $at, $t3, 0x4000
.L7F0DB454:
  bnez  $at, .L7F0DC598
   lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  lbu   $t2, 0x139($sp)
  li    $t5, 1
  addu  $t1, $t6, $t3
  sb    $t2, ($t1)
  lhu   $t7, 0x13c($sp)
  lui   $t6, %hi(ptr_300alloc) 
  lw    $t6, %lo(ptr_300alloc)($t6)
  andi  $t4, $t7, 0x1800
  sra   $t0, $t4, 3
  andi  $t9, $t7, 0xff
  or    $t8, $t0, $t9
  addu  $t3, $t6, $t8
  b     .L7F0DC598
   sb    $t5, ($t3)
spectrum_op_CB_27:
  lui   $t2, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t2, %lo(ptr_pc_keyboard_table_alloc)($t2)
  sra   $t0, $s0, 7
  sll   $t1, $s0, 1
  andi  $s0, $t1, 0xff
  sltiu $t7, $s0, 1
  sw    $t7, 0x48($sp)
  sb    $t0, 0x119($sp)
  addu  $t1, $s0, $t2
  lbu   $t4, ($t1)
  andi  $t9, $s0, 0xa8
  or    $t6, $t0, $t9
  sll   $t5, $t7, 6
  or    $t3, $t6, $t5
  or    $s1, $t4, $t3
  andi  $t7, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t7
spectrum_op_CB_28:
  sll   $t9, $s2, 0x18
  sra   $t8, $t9, 0x18
  sra   $t6, $t8, 1
  lui   $t8, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t8, %lo(ptr_pc_keyboard_table_alloc)($t8)
  andi  $t1, $s2, 1
  andi  $s2, $t6, 0xff
  sltiu $t2, $s2, 1
  sw    $t2, 0x48($sp)
  sb    $t1, 0x118($sp)
  addu  $t6, $s2, $t8
  lbu   $t5, ($t6)
  andi  $t4, $s2, 0xa8
  or    $t3, $t1, $t4
  sll   $t0, $t2, 6
  or    $t9, $t3, $t0
  or    $s1, $t5, $t9
  andi  $t2, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t2
spectrum_op_CB_29:
  sll   $t4, $s3, 0x18
  sra   $t7, $t4, 0x18
  sra   $t3, $t7, 1
  lui   $t7, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t7, %lo(ptr_pc_keyboard_table_alloc)($t7)
  andi  $t6, $s3, 1
  andi  $s3, $t3, 0xff
  sltiu $t8, $s3, 1
  sw    $t8, 0x48($sp)
  sb    $t6, 0x117($sp)
  addu  $t3, $s3, $t7
  lbu   $t0, ($t3)
  andi  $t5, $s3, 0xa8
  or    $t9, $t6, $t5
  sll   $t1, $t8, 6
  or    $t4, $t9, $t1
  or    $s1, $t0, $t4
  andi  $t8, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t8
spectrum_op_CB_2A:
  sll   $t5, $s4, 0x18
  sra   $t2, $t5, 0x18
  sra   $t9, $t2, 1
  lui   $t2, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t2, %lo(ptr_pc_keyboard_table_alloc)($t2)
  andi  $t3, $s4, 1
  andi  $s4, $t9, 0xff
  sltiu $t7, $s4, 1
  sw    $t7, 0x48($sp)
  sb    $t3, 0x116($sp)
  addu  $t9, $s4, $t2
  lbu   $t1, ($t9)
  andi  $t0, $s4, 0xa8
  or    $t4, $t3, $t0
  sll   $t6, $t7, 6
  or    $t5, $t4, $t6
  or    $s1, $t1, $t5
  andi  $t7, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t7
spectrum_op_CB_2B:
  sll   $t0, $s5, 0x18
  sra   $t8, $t0, 0x18
  sra   $t4, $t8, 1
  lui   $t8, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t8, %lo(ptr_pc_keyboard_table_alloc)($t8)
  andi  $t9, $s5, 1
  andi  $s5, $t4, 0xff
  sltiu $t2, $s5, 1
  sw    $t2, 0x48($sp)
  sb    $t9, 0x115($sp)
  addu  $t4, $s5, $t8
  lbu   $t6, ($t4)
  andi  $t1, $s5, 0xa8
  or    $t5, $t9, $t1
  sll   $t3, $t2, 6
  or    $t0, $t5, $t3
  or    $s1, $t6, $t0
  andi  $t2, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t2
spectrum_op_CB_2C:
  sll   $t1, $s6, 0x18
  sra   $t7, $t1, 0x18
  sra   $t5, $t7, 1
  lui   $t7, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t7, %lo(ptr_pc_keyboard_table_alloc)($t7)
  andi  $t4, $s6, 1
  andi  $s6, $t5, 0xff
  sltiu $t8, $s6, 1
  sw    $t8, 0x48($sp)
  sb    $t4, 0x114($sp)
  addu  $t5, $s6, $t7
  lbu   $t3, ($t5)
  andi  $t6, $s6, 0xa8
  or    $t0, $t4, $t6
  sll   $t9, $t8, 6
  or    $t1, $t0, $t9
  or    $s1, $t3, $t1
  andi  $t8, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t8
spectrum_op_CB_2D:
  sll   $t6, $s7, 0x18
  sra   $t2, $t6, 0x18
  sra   $t0, $t2, 1
  lui   $t2, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t2, %lo(ptr_pc_keyboard_table_alloc)($t2)
  andi  $t5, $s7, 1
  andi  $s7, $t0, 0xff
  sltiu $t7, $s7, 1
  sw    $t7, 0x48($sp)
  sb    $t5, 0x113($sp)
  addu  $t0, $s7, $t2
  lbu   $t9, ($t0)
  andi  $t3, $s7, 0xa8
  or    $t1, $t5, $t3
  sll   $t4, $t7, 6
  or    $t6, $t1, $t4
  or    $s1, $t9, $t6
  andi  $t7, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t7
spectrum_op_CB_2E:
  lw    $t5, 0x28c($sp)
  lui   $t1, %hi(ptr_spectrum_roms) 
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  lhu   $t8, 0x13c($sp)
  addiu $t3, $t5, 7
  sw    $t3, 0x28c($sp)
  addu  $t4, $t8, $t1
  lbu   $t0, ($t4)
  sb    $t0, 0x139($sp)
  lb    $t6, 0x139($sp)
  andi  $t8, $t0, 1
  sb    $t8, 0x112($sp)
  sra   $t7, $t6, 1
  lui   $t6, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t6, %lo(ptr_pc_keyboard_table_alloc)($t6)
  andi  $t5, $t7, 0xff
  sltiu $t3, $t5, 1
  andi  $t4, $t7, 0xa8
  or    $t2, $t8, $t4
  sw    $t3, 0x48($sp)
  sb    $t7, 0x139($sp)
  addu  $t1, $t5, $t6
  lbu   $t8, ($t1)
  sll   $t0, $t3, 6
  lhu   $t3, 0x13c($sp)
  or    $t9, $t2, $t0
  or    $s1, $t8, $t9
  andi  $t4, $s1, 0xff
  slti  $at, $t3, 0x5b00
  bnez  $at, .L7F0DB754
   move  $s1, $t4
  lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  move  $t2, $t7
  addu  $t7, $t0, $t3
  b     .L7F0DC598
   sb    $t2, ($t7)
.L7F0DB754:
  lhu   $t5, 0x13c($sp)
  lhu   $t2, 0x13c($sp)
  lui   $t1, %hi(ptr_spectrum_roms) 
  slti  $at, $t5, 0x5800
  bnezl $at, .L7F0DB79C
   slti  $at, $t2, 0x4000
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  lbu   $t6, 0x139($sp)
  lui   $t4, %hi(ptr_300alloc) 
  addu  $t8, $t1, $t5
  sb    $t6, ($t8)
  lhu   $t0, 0x13c($sp)
  lw    $t4, %lo(ptr_300alloc)($t4)
  li    $t9, 1
  addu  $t3, $t4, $t0
  b     .L7F0DC598
   sb    $t9, -0x5800($t3)
  slti  $at, $t2, 0x4000
.L7F0DB79C:
  bnez  $at, .L7F0DC598
   lui   $t1, %hi(ptr_spectrum_roms) 
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  lbu   $t7, 0x139($sp)
  li    $t6, 1
  addu  $t5, $t1, $t2
  sb    $t7, ($t5)
  lhu   $t8, 0x13c($sp)
  lui   $t1, %hi(ptr_300alloc) 
  lw    $t1, %lo(ptr_300alloc)($t1)
  andi  $t4, $t8, 0x1800
  sra   $t0, $t4, 3
  andi  $t9, $t8, 0xff
  or    $t3, $t0, $t9
  addu  $t2, $t1, $t3
  b     .L7F0DC598
   sb    $t6, ($t2)
spectrum_op_CB_2F:
  sll   $t5, $s0, 0x18
  sra   $t4, $t5, 0x18
  sra   $t8, $t4, 1
  lui   $t4, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t4, %lo(ptr_pc_keyboard_table_alloc)($t4)
  andi  $t1, $s0, 1
  andi  $s0, $t8, 0xff
  sltiu $t9, $s0, 1
  sw    $t9, 0x48($sp)
  sb    $t1, 0x111($sp)
  addu  $t8, $s0, $t4
  lbu   $t0, ($t8)
  andi  $t3, $s0, 0xa8
  or    $t6, $t1, $t3
  sll   $t7, $t9, 6
  or    $t5, $t6, $t7
  or    $s1, $t0, $t5
  andi  $t9, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t9
spectrum_op_CB_30:
  sll   $t3, $s2, 1
  ori   $t2, $t3, 1
  lui   $t3, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t3, %lo(ptr_pc_keyboard_table_alloc)($t3)
  sra   $t4, $s2, 7
  andi  $s2, $t2, 0xff
  sltiu $t7, $s2, 1
  sw    $t7, 0x48($sp)
  sb    $t4, 0x110($sp)
  addu  $t2, $s2, $t3
  lbu   $t6, ($t2)
  andi  $t8, $s2, 0xa8
  or    $t0, $t4, $t8
  sll   $t9, $t7, 6
  or    $t1, $t0, $t9
  or    $s1, $t6, $t1
  andi  $t7, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t7
spectrum_op_CB_31:
  sll   $t8, $s3, 1
  ori   $t5, $t8, 1
  lui   $t8, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t8, %lo(ptr_pc_keyboard_table_alloc)($t8)
  sra   $t3, $s3, 7
  andi  $s3, $t5, 0xff
  sltiu $t9, $s3, 1
  sw    $t9, 0x48($sp)
  sb    $t3, 0x10f($sp)
  addu  $t5, $s3, $t8
  lbu   $t0, ($t5)
  andi  $t2, $s3, 0xa8
  or    $t6, $t3, $t2
  sll   $t7, $t9, 6
  or    $t4, $t6, $t7
  or    $s1, $t0, $t4
  andi  $t9, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t9
spectrum_op_CB_32:
  sll   $t2, $s4, 1
  ori   $t1, $t2, 1
  lui   $t2, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t2, %lo(ptr_pc_keyboard_table_alloc)($t2)
  sra   $t8, $s4, 7
  andi  $s4, $t1, 0xff
  sltiu $t7, $s4, 1
  sw    $t7, 0x48($sp)
  sb    $t8, 0x10e($sp)
  addu  $t1, $s4, $t2
  lbu   $t6, ($t1)
  andi  $t5, $s4, 0xa8
  or    $t0, $t8, $t5
  sll   $t9, $t7, 6
  or    $t3, $t0, $t9
  or    $s1, $t6, $t3
  andi  $t7, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t7
spectrum_op_CB_33:
  sll   $t5, $s5, 1
  ori   $t4, $t5, 1
  lui   $t5, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t5, %lo(ptr_pc_keyboard_table_alloc)($t5)
  sra   $t2, $s5, 7
  andi  $s5, $t4, 0xff
  sltiu $t9, $s5, 1
  sw    $t9, 0x48($sp)
  sb    $t2, 0x10d($sp)
  addu  $t4, $s5, $t5
  lbu   $t0, ($t4)
  andi  $t1, $s5, 0xa8
  or    $t6, $t2, $t1
  sll   $t7, $t9, 6
  or    $t8, $t6, $t7
  or    $s1, $t0, $t8
  andi  $t9, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t9
spectrum_op_CB_34:
  sll   $t1, $s6, 1
  ori   $t3, $t1, 1
  lui   $t1, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t1, %lo(ptr_pc_keyboard_table_alloc)($t1)
  sra   $t5, $s6, 7
  andi  $s6, $t3, 0xff
  sltiu $t7, $s6, 1
  sw    $t7, 0x48($sp)
  sb    $t5, 0x10c($sp)
  addu  $t3, $s6, $t1
  lbu   $t6, ($t3)
  andi  $t4, $s6, 0xa8
  or    $t0, $t5, $t4
  sll   $t9, $t7, 6
  or    $t2, $t0, $t9
  or    $s1, $t6, $t2
  andi  $t7, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t7
spectrum_op_CB_35:
  sll   $t4, $s7, 1
  ori   $t8, $t4, 1
  lui   $t4, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t4, %lo(ptr_pc_keyboard_table_alloc)($t4)
  sra   $t1, $s7, 7
  andi  $s7, $t8, 0xff
  sltiu $t9, $s7, 1
  sw    $t9, 0x48($sp)
  sb    $t1, 0x10b($sp)
  addu  $t8, $s7, $t4
  lbu   $t0, ($t8)
  andi  $t3, $s7, 0xa8
  or    $t6, $t1, $t3
  sll   $t7, $t9, 6
  or    $t5, $t6, $t7
  or    $s1, $t0, $t5
  andi  $t9, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t9
spectrum_op_CB_36:
  lw    $t1, 0x28c($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  lhu   $t2, 0x13c($sp)
  addiu $t3, $t1, 7
  sw    $t3, 0x28c($sp)
  addu  $t7, $t2, $t6
  lbu   $t4, ($t7)
  andi  $t8, $t4, 0xff
  sll   $t5, $t8, 1
  ori   $t9, $t5, 1
  lui   $t5, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t5, %lo(ptr_pc_keyboard_table_alloc)($t5)
  andi  $t1, $t9, 0xff
  sra   $t2, $t8, 7
  sb    $t4, 0x139($sp)
  sltiu $t3, $t1, 1
  andi  $t7, $t9, 0xa8
  or    $t4, $t2, $t7
  sw    $t3, 0x48($sp)
  sb    $t9, 0x139($sp)
  sb    $t2, 0x10a($sp)
  addu  $t6, $t1, $t5
  lbu   $t2, ($t6)
  sll   $t0, $t3, 6
  lhu   $t3, 0x13c($sp)
  or    $t8, $t4, $t0
  or    $s1, $t2, $t8
  andi  $t7, $s1, 0xff
  slti  $at, $t3, 0x5b00
  bnez  $at, .L7F0DBA90
   move  $s1, $t7
  lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  move  $t4, $t9
  addu  $t9, $t0, $t3
  b     .L7F0DC598
   sb    $t4, ($t9)
.L7F0DBA90:
  lhu   $t1, 0x13c($sp)
  lhu   $t4, 0x13c($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  slti  $at, $t1, 0x5800
  bnezl $at, .L7F0DBAD8
   slti  $at, $t4, 0x4000
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  lbu   $t5, 0x139($sp)
  lui   $t7, %hi(ptr_300alloc) 
  addu  $t2, $t6, $t1
  sb    $t5, ($t2)
  lhu   $t0, 0x13c($sp)
  lw    $t7, %lo(ptr_300alloc)($t7)
  li    $t8, 1
  addu  $t3, $t7, $t0
  b     .L7F0DC598
   sb    $t8, -0x5800($t3)
  slti  $at, $t4, 0x4000
.L7F0DBAD8:
  bnez  $at, .L7F0DC598
   lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  lbu   $t9, 0x139($sp)
  li    $t5, 1
  addu  $t1, $t6, $t4
  sb    $t9, ($t1)
  lhu   $t2, 0x13c($sp)
  lui   $t6, %hi(ptr_300alloc) 
  lw    $t6, %lo(ptr_300alloc)($t6)
  andi  $t7, $t2, 0x1800
  sra   $t0, $t7, 3
  andi  $t8, $t2, 0xff
  or    $t3, $t0, $t8
  addu  $t4, $t6, $t3
  b     .L7F0DC598
   sb    $t5, ($t4)
spectrum_op_CB_37:
  sll   $t1, $s0, 1
  ori   $t7, $t1, 1
  lui   $t1, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t1, %lo(ptr_pc_keyboard_table_alloc)($t1)
  sra   $t8, $s0, 7
  andi  $s0, $t7, 0xff
  sltiu $t0, $s0, 1
  sw    $t0, 0x48($sp)
  sb    $t8, 0x109($sp)
  addu  $t7, $s0, $t1
  lbu   $t2, ($t7)
  andi  $t6, $s0, 0xa8
  or    $t3, $t8, $t6
  sll   $t4, $t0, 6
  or    $t9, $t3, $t4
  or    $s1, $t2, $t9
  andi  $t0, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t0
spectrum_op_CB_38:
  lui   $t8, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t8, %lo(ptr_pc_keyboard_table_alloc)($t8)
  andi  $t4, $s2, 1
  srl   $t6, $s2, 1
  andi  $s2, $t6, 0xff
  sltiu $t3, $s2, 1
  sw    $t3, 0x48($sp)
  sb    $t4, 0x108($sp)
  addu  $t6, $s2, $t8
  lbu   $t5, ($t6)
  andi  $t1, $s2, 0xa8
  or    $t7, $t4, $t1
  sll   $t9, $t3, 6
  or    $t0, $t7, $t9
  or    $s1, $t5, $t0
  andi  $t3, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t3
spectrum_op_CB_39:
  lui   $t4, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t4, %lo(ptr_pc_keyboard_table_alloc)($t4)
  andi  $t9, $s3, 1
  srl   $t1, $s3, 1
  andi  $s3, $t1, 0xff
  sltiu $t7, $s3, 1
  sw    $t7, 0x48($sp)
  sb    $t9, 0x107($sp)
  addu  $t1, $s3, $t4
  lbu   $t2, ($t1)
  andi  $t8, $s3, 0xa8
  or    $t6, $t9, $t8
  sll   $t0, $t7, 6
  or    $t3, $t6, $t0
  or    $s1, $t2, $t3
  andi  $t7, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t7
spectrum_op_CB_3A:
  lui   $t9, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t9, %lo(ptr_pc_keyboard_table_alloc)($t9)
  andi  $t0, $s4, 1
  srl   $t8, $s4, 1
  andi  $s4, $t8, 0xff
  sltiu $t6, $s4, 1
  sw    $t6, 0x48($sp)
  sb    $t0, 0x106($sp)
  addu  $t8, $s4, $t9
  lbu   $t5, ($t8)
  andi  $t4, $s4, 0xa8
  or    $t1, $t0, $t4
  sll   $t3, $t6, 6
  or    $t7, $t1, $t3
  or    $s1, $t5, $t7
  andi  $t6, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t6
spectrum_op_CB_3B:
  lui   $t0, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t0, %lo(ptr_pc_keyboard_table_alloc)($t0)
  andi  $t3, $s5, 1
  srl   $t4, $s5, 1
  andi  $s5, $t4, 0xff
  sltiu $t1, $s5, 1
  sw    $t1, 0x48($sp)
  sb    $t3, 0x105($sp)
  addu  $t4, $s5, $t0
  lbu   $t2, ($t4)
  andi  $t9, $s5, 0xa8
  or    $t8, $t3, $t9
  sll   $t7, $t1, 6
  or    $t6, $t8, $t7
  or    $s1, $t2, $t6
  andi  $t1, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t1
spectrum_op_CB_3C:
  lui   $t3, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t3, %lo(ptr_pc_keyboard_table_alloc)($t3)
  andi  $t7, $s6, 1
  srl   $t9, $s6, 1
  andi  $s6, $t9, 0xff
  sltiu $t8, $s6, 1
  sw    $t8, 0x48($sp)
  sb    $t7, 0x104($sp)
  addu  $t9, $s6, $t3
  lbu   $t5, ($t9)
  andi  $t0, $s6, 0xa8
  or    $t4, $t7, $t0
  sll   $t6, $t8, 6
  or    $t1, $t4, $t6
  or    $s1, $t5, $t1
  andi  $t8, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t8
spectrum_op_CB_3D:
  lui   $t7, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t7, %lo(ptr_pc_keyboard_table_alloc)($t7)
  andi  $t6, $s7, 1
  srl   $t0, $s7, 1
  andi  $s7, $t0, 0xff
  sltiu $t4, $s7, 1
  sw    $t4, 0x48($sp)
  sb    $t6, 0x103($sp)
  addu  $t0, $s7, $t7
  lbu   $t2, ($t0)
  andi  $t3, $s7, 0xa8
  or    $t9, $t6, $t3
  sll   $t1, $t4, 6
  or    $t8, $t9, $t1
  or    $s1, $t2, $t8
  andi  $t4, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t4
spectrum_op_CB_3E:
  lw    $t6, 0x28c($sp)
  lui   $t9, %hi(ptr_spectrum_roms) 
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  lhu   $t5, 0x13c($sp)
  addiu $t3, $t6, 7
  sw    $t3, 0x28c($sp)
  addu  $t1, $t5, $t9
  lbu   $t7, ($t1)
  andi  $t0, $t7, 0xff
  andi  $t3, $t0, 1
  srl   $t8, $t0, 1
  lui   $t0, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t0, %lo(ptr_pc_keyboard_table_alloc)($t0)
  andi  $t4, $t8, 0xff
  sb    $t7, 0x139($sp)
  sltiu $t6, $t4, 1
  andi  $t9, $t8, 0xa8
  or    $t1, $t3, $t9
  sw    $t6, 0x48($sp)
  sb    $t8, 0x139($sp)
  sb    $t3, 0x102($sp)
  addu  $t5, $t4, $t0
  lbu   $t3, ($t5)
  sll   $t7, $t6, 6
  lhu   $t6, 0x13c($sp)
  or    $t2, $t1, $t7
  or    $s1, $t3, $t2
  andi  $t9, $s1, 0xff
  slti  $at, $t6, 0x5b00
  bnez  $at, .L7F0DBDAC
   move  $s1, $t9
  lui   $t7, %hi(ptr_spectrum_roms) 
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  move  $t1, $t8
  addu  $t8, $t7, $t6
  b     .L7F0DC598
   sb    $t1, ($t8)
.L7F0DBDAC:
  lhu   $t4, 0x13c($sp)
  lhu   $t1, 0x13c($sp)
  lui   $t5, %hi(ptr_spectrum_roms) 
  slti  $at, $t4, 0x5800
  bnezl $at, .L7F0DBDF4
   slti  $at, $t1, 0x4000
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  lbu   $t0, 0x139($sp)
  lui   $t9, %hi(ptr_300alloc) 
  addu  $t3, $t5, $t4
  sb    $t0, ($t3)
  lhu   $t7, 0x13c($sp)
  lw    $t9, %lo(ptr_300alloc)($t9)
  li    $t2, 1
  addu  $t6, $t9, $t7
  b     .L7F0DC598
   sb    $t2, -0x5800($t6)
  slti  $at, $t1, 0x4000
.L7F0DBDF4:
  bnez  $at, .L7F0DC598
   lui   $t5, %hi(ptr_spectrum_roms) 
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  lbu   $t8, 0x139($sp)
  li    $t0, 1
  addu  $t4, $t5, $t1
  sb    $t8, ($t4)
  lhu   $t3, 0x13c($sp)
  lui   $t5, %hi(ptr_300alloc) 
  lw    $t5, %lo(ptr_300alloc)($t5)
  andi  $t9, $t3, 0x1800
  sra   $t7, $t9, 3
  andi  $t2, $t3, 0xff
  or    $t6, $t7, $t2
  addu  $t1, $t5, $t6
  b     .L7F0DC598
   sb    $t0, ($t1)
spectrum_op_CB_3F:
  lui   $t8, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t8, %lo(ptr_pc_keyboard_table_alloc)($t8)
  andi  $t7, $s0, 1
  srl   $t4, $s0, 1
  andi  $s0, $t4, 0xff
  sltiu $t3, $s0, 1
  sw    $t3, 0x48($sp)
  sb    $t7, 0x101($sp)
  addu  $t4, $s0, $t8
  lbu   $t9, ($t4)
  andi  $t2, $s0, 0xa8
  or    $t5, $t7, $t2
  sll   $t0, $t3, 6
  or    $t1, $t5, $t0
  or    $s1, $t9, $t1
  andi  $t3, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t3
.L7F0DBE80:
  sra   $t2, $t7, 3
  andi  $t5, $t7, 0xc7
  andi  $t6, $t2, 7
  slti  $at, $t5, 0x88
  sb    $t6, 0x100($sp)
  bnez  $at, .L7F0DBEC0
   sw    $t5, 0x48($sp)
  addiu $t0, $t5, -0xc0
  sltiu $at, $t0, 8
  beqz  $at, .L7F0DC598
   sll   $t0, $t0, 2
  lui   $at, %hi(jpt_8005C62C)
  addu  $at, $at, $t0
  lw    $t0, %lo(jpt_8005C62C)($at)
  jr    $t0
   nop   
.L7F0DBEC0:
  lw    $t8, 0x48($sp)
  lw    $t9, 0x48($sp)
  slti  $at, $t8, 0x48
  bnez  $at, .L7F0DBEF8
   addiu $t1, $t9, -0x40
  addiu $t4, $t8, -0x80
  sltiu $at, $t4, 8
  beqz  $at, .L7F0DC598
   sll   $t4, $t4, 2
  lui   $at, %hi(jpt_8005C64C)
  addu  $at, $at, $t4
  lw    $t4, %lo(jpt_8005C64C)($at)
  jr    $t4
   nop   
.L7F0DBEF8:
  sltiu $at, $t1, 8
  beqz  $at, .L7F0DC598
   sll   $t1, $t1, 2
  lui   $at, %hi(jpt_8005C66C)
  addu  $at, $at, $t1
  lw    $t1, %lo(jpt_8005C66C)($at)
  jr    $t1
   nop   
spectrum_op_BIT_x_B:
  lbu   $t3, 0x100($sp)
  li    $t2, 1
  li    $t0, 84
  sllv  $t6, $t2, $t3
  and   $t7, $s2, $t6
  beqz  $t7, .L7F0DBF3C
   li    $t5, 16
  b     .L7F0DBF40
   sw    $t5, 0x44($sp)
.L7F0DBF3C:
  sw    $t0, 0x44($sp)
.L7F0DBF40:
  lw    $t8, 0x44($sp)
  andi  $t4, $s1, 1
  andi  $t1, $s2, 0x28
  or    $t9, $t8, $t4
  or    $s1, $t9, $t1
  andi  $t2, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t2
spectrum_op_BIT_x_C:
  lbu   $t3, 0x100($sp)
  li    $t6, 1
  li    $t8, 84
  sllv  $t7, $t6, $t3
  and   $t5, $s3, $t7
  beqz  $t5, .L7F0DBF84
   li    $t0, 16
  b     .L7F0DBF88
   sw    $t0, 0x48($sp)
.L7F0DBF84:
  sw    $t8, 0x48($sp)
.L7F0DBF88:
  lw    $t4, 0x48($sp)
  andi  $t9, $s1, 1
  andi  $t2, $s3, 0x28
  or    $t1, $t4, $t9
  or    $s1, $t1, $t2
  andi  $t6, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t6
spectrum_op_BIT_x_D:
  lbu   $t3, 0x100($sp)
  li    $t7, 1
  li    $t4, 84
  sllv  $t5, $t7, $t3
  and   $t0, $s4, $t5
  beqz  $t0, .L7F0DBFCC
   li    $t8, 16
  b     .L7F0DBFD0
   sw    $t8, 0x48($sp)
.L7F0DBFCC:
  sw    $t4, 0x48($sp)
.L7F0DBFD0:
  lw    $t9, 0x48($sp)
  andi  $t1, $s1, 1
  andi  $t6, $s4, 0x28
  or    $t2, $t9, $t1
  or    $s1, $t2, $t6
  andi  $t7, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t7
spectrum_op_BIT_x_E:
  lbu   $t3, 0x100($sp)
  li    $t5, 1
  li    $t9, 84
  sllv  $t0, $t5, $t3
  and   $t8, $s5, $t0
  beqz  $t8, .L7F0DC014
   li    $t4, 16
  b     .L7F0DC018
   sw    $t4, 0x48($sp)
.L7F0DC014:
  sw    $t9, 0x48($sp)
.L7F0DC018:
  lw    $t1, 0x48($sp)
  andi  $t2, $s1, 1
  andi  $t7, $s5, 0x28
  or    $t6, $t1, $t2
  or    $s1, $t6, $t7
  andi  $t5, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t5
spectrum_op_BIT_x_H:
  lbu   $t3, 0x100($sp)
  li    $t0, 1
  li    $t1, 84
  sllv  $t8, $t0, $t3
  and   $t4, $s6, $t8
  beqz  $t4, .L7F0DC05C
   li    $t9, 16
  b     .L7F0DC060
   sw    $t9, 0x48($sp)
.L7F0DC05C:
  sw    $t1, 0x48($sp)
.L7F0DC060:
  lw    $t2, 0x48($sp)
  andi  $t6, $s1, 1
  andi  $t5, $s6, 0x28
  or    $t7, $t2, $t6
  or    $s1, $t7, $t5
  andi  $t0, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t0
spectrum_op_BIT_x_L:
  lbu   $t3, 0x100($sp)
  li    $t8, 1
  li    $t2, 84
  sllv  $t4, $t8, $t3
  and   $t9, $s7, $t4
  beqz  $t9, .L7F0DC0A4
   li    $t1, 16
  b     .L7F0DC0A8
   sw    $t1, 0x48($sp)
.L7F0DC0A4:
  sw    $t2, 0x48($sp)
.L7F0DC0A8:
  lw    $t6, 0x48($sp)
  andi  $t7, $s1, 1
  andi  $t0, $s7, 0x28
  or    $t5, $t6, $t7
  or    $s1, $t5, $t0
  andi  $t8, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t8
spectrum_op_BIT_x_HL:
  lw    $t3, 0x28c($sp)
  lui   $t1, %hi(ptr_spectrum_roms) 
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  lhu   $t9, 0x13c($sp)
  addiu $t4, $t3, 4
  lbu   $t7, 0x100($sp)
  sw    $t4, 0x28c($sp)
  addu  $t2, $t9, $t1
  lbu   $t6, ($t2)
  li    $t5, 1
  sllv  $t0, $t5, $t7
  and   $t8, $t6, $t0
  beqz  $t8, .L7F0DC10C
   sb    $t6, 0x139($sp)
  li    $t3, 16
  b     .L7F0DC114
   sw    $t3, 0x48($sp)
.L7F0DC10C:
  li    $t4, 84
  sw    $t4, 0x48($sp)
.L7F0DC114:
  lw    $t9, 0x48($sp)
  lbu   $t5, 0x139($sp)
  lhu   $t0, 0x13c($sp)
  andi  $t1, $s1, 1
  or    $t2, $t9, $t1
  andi  $t7, $t5, 0x28
  or    $s1, $t2, $t7
  andi  $t6, $s1, 0xff
  slti  $at, $t0, 0x5b00
  bnez  $at, .L7F0DC158
   move  $s1, $t6
  lui   $t3, %hi(ptr_spectrum_roms) 
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  lbu   $t8, 0x139($sp)
  addu  $t4, $t3, $t0
  b     .L7F0DC598
   sb    $t8, ($t4)
.L7F0DC158:
  lhu   $t9, 0x13c($sp)
  lhu   $t8, 0x13c($sp)
  lui   $t5, %hi(ptr_spectrum_roms) 
  slti  $at, $t9, 0x5800
  bnezl $at, .L7F0DC1A0
   slti  $at, $t8, 0x4000
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  lbu   $t1, 0x139($sp)
  lui   $t6, %hi(ptr_300alloc) 
  addu  $t2, $t5, $t9
  sb    $t1, ($t2)
  lhu   $t3, 0x13c($sp)
  lw    $t6, %lo(ptr_300alloc)($t6)
  li    $t7, 1
  addu  $t0, $t6, $t3
  b     .L7F0DC598
   sb    $t7, -0x5800($t0)
  slti  $at, $t8, 0x4000
.L7F0DC1A0:
  bnez  $at, .L7F0DC598
   lui   $t5, %hi(ptr_spectrum_roms) 
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  lbu   $t4, 0x139($sp)
  li    $t1, 1
  addu  $t9, $t5, $t8
  sb    $t4, ($t9)
  lhu   $t2, 0x13c($sp)
  lui   $t5, %hi(ptr_300alloc) 
  lw    $t5, %lo(ptr_300alloc)($t5)
  andi  $t6, $t2, 0x1800
  sra   $t3, $t6, 3
  andi  $t7, $t2, 0xff
  or    $t0, $t3, $t7
  addu  $t8, $t5, $t0
  b     .L7F0DC598
   sb    $t1, ($t8)
spectrum_op_BIT_x_A:
  lbu   $t4, 0x100($sp)
  li    $t9, 1
  li    $t7, 84
  sllv  $t6, $t9, $t4
  and   $t2, $s0, $t6
  beqz  $t2, .L7F0DC208
   li    $t3, 16
  b     .L7F0DC20C
   sw    $t3, 0x48($sp)
.L7F0DC208:
  sw    $t7, 0x48($sp)
.L7F0DC20C:
  lw    $t5, 0x48($sp)
  andi  $t0, $s1, 1
  andi  $t8, $s0, 0x28
  or    $t1, $t5, $t0
  or    $s1, $t1, $t8
  andi  $t9, $s1, 0xff
  b     .L7F0DC598
   move  $s1, $t9
spectrum_op_RES_x_B:
  lbu   $t4, 0x100($sp)
  li    $t6, 1
  sllv  $t2, $t6, $t4
  not   $t3, $t2
  and   $s2, $s2, $t3
  andi  $t7, $s2, 0xff
  b     .L7F0DC598
   move  $s2, $t7
spectrum_op_RES_x_C:
  lbu   $t5, 0x100($sp)
  li    $t0, 1
  sllv  $t1, $t0, $t5
  not   $t8, $t1
  and   $s3, $s3, $t8
  andi  $t9, $s3, 0xff
  b     .L7F0DC598
   move  $s3, $t9
spectrum_op_RES_x_D:
  lbu   $t6, 0x100($sp)
  li    $t4, 1
  sllv  $t2, $t4, $t6
  not   $t3, $t2
  and   $s4, $s4, $t3
  andi  $t7, $s4, 0xff
  b     .L7F0DC598
   move  $s4, $t7
spectrum_op_RES_x_E:
  lbu   $t0, 0x100($sp)
  li    $t5, 1
  sllv  $t1, $t5, $t0
  not   $t8, $t1
  and   $s5, $s5, $t8
  andi  $t9, $s5, 0xff
  b     .L7F0DC598
   move  $s5, $t9
spectrum_op_RES_x_H:
  lbu   $t4, 0x100($sp)
  li    $t6, 1
  sllv  $t2, $t6, $t4
  not   $t3, $t2
  and   $s6, $s6, $t3
  andi  $t7, $s6, 0xff
  b     .L7F0DC598
   move  $s6, $t7
spectrum_op_RES_x_L:
  lbu   $t5, 0x100($sp)
  li    $t0, 1
  sllv  $t1, $t0, $t5
  not   $t8, $t1
  and   $s7, $s7, $t8
  andi  $t9, $s7, 0xff
  b     .L7F0DC598
   move  $s7, $t9
spectrum_op_RES_x_HL:
  lw    $t6, 0x28c($sp)
  lui   $t3, %hi(ptr_spectrum_roms) 
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  lhu   $t2, 0x13c($sp)
  addiu $t4, $t6, 4
  lbu   $t5, 0x100($sp)
  sw    $t4, 0x28c($sp)
  addu  $t7, $t2, $t3
  lbu   $t0, ($t7)
  lhu   $t4, 0x13c($sp)
  li    $t1, 1
  sllv  $t8, $t1, $t5
  not   $t9, $t8
  and   $t6, $t0, $t9
  sb    $t0, 0x139($sp)
  slti  $at, $t4, 0x5b00
  bnez  $at, .L7F0DC348
   sb    $t6, 0x139($sp)
  lui   $t3, %hi(ptr_spectrum_roms) 
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  addu  $t7, $t3, $t4
  b     .L7F0DC598
   sb    $t6, ($t7)
.L7F0DC348:
  lhu   $t1, 0x13c($sp)
  lhu   $t2, 0x13c($sp)
  lui   $t8, %hi(ptr_spectrum_roms) 
  slti  $at, $t1, 0x5800
  bnezl $at, .L7F0DC390
   slti  $at, $t2, 0x4000
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  lbu   $t5, 0x139($sp)
  lui   $t6, %hi(ptr_300alloc) 
  addu  $t0, $t8, $t1
  sb    $t5, ($t0)
  lhu   $t3, 0x13c($sp)
  lw    $t6, %lo(ptr_300alloc)($t6)
  li    $t9, 1
  addu  $t4, $t6, $t3
  b     .L7F0DC598
   sb    $t9, -0x5800($t4)
  slti  $at, $t2, 0x4000
.L7F0DC390:
  bnez  $at, .L7F0DC598
   lui   $t8, %hi(ptr_spectrum_roms) 
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  lbu   $t7, 0x139($sp)
  li    $t5, 1
  addu  $t1, $t8, $t2
  sb    $t7, ($t1)
  lhu   $t0, 0x13c($sp)
  lui   $t8, %hi(ptr_300alloc) 
  lw    $t8, %lo(ptr_300alloc)($t8)
  andi  $t6, $t0, 0x1800
  sra   $t3, $t6, 3
  andi  $t9, $t0, 0xff
  or    $t4, $t3, $t9
  addu  $t2, $t8, $t4
  b     .L7F0DC598
   sb    $t5, ($t2)
spectrum_op_RES_x_A:
  lbu   $t7, 0x100($sp)
  li    $t1, 1
  sllv  $t6, $t1, $t7
  not   $t0, $t6
  and   $s0, $s0, $t0
  andi  $t3, $s0, 0xff
  b     .L7F0DC598
   move  $s0, $t3
spectrum_op_SET_x_B:
  lbu   $t9, 0x100($sp)
  li    $t8, 1
  sllv  $t4, $t8, $t9
  or    $s2, $s2, $t4
  andi  $t5, $s2, 0xff
  b     .L7F0DC598
   move  $s2, $t5
spectrum_op_SET_x_C:
  lbu   $t2, 0x100($sp)
  li    $t1, 1
  sllv  $t7, $t1, $t2
  or    $s3, $s3, $t7
  andi  $t6, $s3, 0xff
  b     .L7F0DC598
   move  $s3, $t6
spectrum_op_SET_x_D:
  lbu   $t0, 0x100($sp)
  li    $t3, 1
  sllv  $t8, $t3, $t0
  or    $s4, $s4, $t8
  andi  $t9, $s4, 0xff
  b     .L7F0DC598
   move  $s4, $t9
spectrum_op_SET_x_E:
  lbu   $t4, 0x100($sp)
  li    $t5, 1
  sllv  $t1, $t5, $t4
  or    $s5, $s5, $t1
  andi  $t2, $s5, 0xff
  b     .L7F0DC598
   move  $s5, $t2
spectrum_op_SET_x_H:
  lbu   $t7, 0x100($sp)
  li    $t6, 1
  sllv  $t3, $t6, $t7
  or    $s6, $s6, $t3
  andi  $t0, $s6, 0xff
  b     .L7F0DC598
   move  $s6, $t0
spectrum_op_SET_x_L:
  lbu   $t8, 0x100($sp)
  li    $t9, 1
  sllv  $t5, $t9, $t8
  or    $s7, $s7, $t5
  andi  $t4, $s7, 0xff
  b     .L7F0DC598
   move  $s7, $t4
spectrum_op_SET_x_HL:
  lw    $t1, 0x28c($sp)
  lui   $t7, %hi(ptr_spectrum_roms) 
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  lhu   $t6, 0x13c($sp)
  addiu $t2, $t1, 4
  sw    $t2, 0x28c($sp)
  addu  $t3, $t6, $t7
  lbu   $t0, ($t3)
  lbu   $t9, 0x100($sp)
  lhu   $t1, 0x13c($sp)
  li    $t8, 1
  sllv  $t5, $t8, $t9
  or    $t4, $t0, $t5
  sb    $t0, 0x139($sp)
  slti  $at, $t1, 0x5b00
  bnez  $at, .L7F0DC4F4
   sb    $t4, 0x139($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  addu  $t7, $t6, $t1
  b     .L7F0DC598
   sb    $t4, ($t7)
.L7F0DC4F4:
  lhu   $t3, 0x13c($sp)
  lhu   $t2, 0x13c($sp)
  lui   $t9, %hi(ptr_spectrum_roms) 
  slti  $at, $t3, 0x5800
  bnezl $at, .L7F0DC53C
   slti  $at, $t2, 0x4000
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  lbu   $t8, 0x139($sp)
  lui   $t4, %hi(ptr_300alloc) 
  addu  $t0, $t9, $t3
  sb    $t8, ($t0)
  lhu   $t6, 0x13c($sp)
  lw    $t4, %lo(ptr_300alloc)($t4)
  li    $t5, 1
  addu  $t1, $t4, $t6
  b     .L7F0DC598
   sb    $t5, -0x5800($t1)
  slti  $at, $t2, 0x4000
.L7F0DC53C:
  bnez  $at, .L7F0DC598
   lui   $t9, %hi(ptr_spectrum_roms) 
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  lbu   $t7, 0x139($sp)
  li    $t8, 1
  addu  $t3, $t9, $t2
  sb    $t7, ($t3)
  lhu   $t0, 0x13c($sp)
  lui   $t9, %hi(ptr_300alloc) 
  lw    $t9, %lo(ptr_300alloc)($t9)
  andi  $t4, $t0, 0x1800
  sra   $t6, $t4, 3
  andi  $t5, $t0, 0xff
  or    $t1, $t6, $t5
  addu  $t2, $t9, $t1
  b     .L7F0DC598
   sb    $t8, ($t2)
spectrum_op_SET_x_A:
  lbu   $t7, 0x100($sp)
  li    $t3, 1
  sllv  $t4, $t3, $t7
  or    $s0, $s0, $t4
  andi  $t0, $s0, 0xff
  move  $s0, $t0
.L7F0DC598:
  lbu   $t6, 0x287($sp)
  lbu   $t5, 0x13a($sp)
  beqz  $t6, .L7F0E27FC
   sltiu $at, $t5, 8
  beqz  $at, .L7F0E27FC
   sll   $t5, $t5, 2
  lui   $at, %hi(jpt_8005C68C)
  addu  $at, $at, $t5
  lw    $t5, %lo(jpt_8005C68C)($at)
.L7F0DC5BC:
  jr    $t5
   nop   
.L7F0DC5C4:
  b     .L7F0E27FC
   lbu   $s2, 0x139($sp)
.L7F0DC5CC:
  b     .L7F0E27FC
   lbu   $s3, 0x139($sp)
.L7F0DC5D4:
  b     .L7F0E27FC
   lbu   $s4, 0x139($sp)
.L7F0DC5DC:
  b     .L7F0E27FC
   lbu   $s5, 0x139($sp)
.L7F0DC5E4:
  b     .L7F0E27FC
   lbu   $s6, 0x139($sp)
.L7F0DC5EC:
  b     .L7F0E27FC
   lbu   $s7, 0x139($sp)
.L7F0DC5F4:
  b     .L7F0E27FC
   lbu   $s0, 0x139($sp)
spectrum_op_CC:
  lw    $t9, 0x28c($sp)
  andi  $t8, $s1, 0x40
  addiu $t1, $t9, 0xa
  beqz  $t8, .L7F0DC7D4
   sw    $t1, 0x28c($sp)
  lhu   $t7, 0x292($sp)
  addiu $t3, $t1, 7
  sw    $t3, 0x28c($sp)
  addiu $t4, $t7, -2
  andi  $t0, $t4, 0xffff
  slti  $at, $t0, 0x5b00
  bnez  $at, .L7F0DC64C
   sh    $t4, 0x292($sp)
  lui   $t9, %hi(ptr_spectrum_roms) 
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  lhu   $t6, 0x298($sp)
  addu  $t1, $t9, $t0
  addiu $t5, $t6, 2
  b     .L7F0DC6D8
   sb    $t5, ($t1)
.L7F0DC64C:
  lhu   $t8, 0x292($sp)
  lhu   $t1, 0x292($sp)
  lhu   $t2, 0x298($sp)
  slti  $at, $t8, 0x5800
  bnez  $at, .L7F0DC690
   lui   $t7, %hi(ptr_spectrum_roms) 
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  addiu $t3, $t2, 2
  lui   $t9, %hi(ptr_300alloc) 
  addu  $t4, $t7, $t8
  sb    $t3, ($t4)
  lhu   $t0, 0x292($sp)
  lw    $t9, %lo(ptr_300alloc)($t9)
  li    $t6, 1
  addu  $t5, $t9, $t0
  b     .L7F0DC6D8
   sb    $t6, -0x5800($t5)
.L7F0DC690:
  slti  $at, $t1, 0x4000
  bnez  $at, .L7F0DC6D8
   lhu   $t2, 0x298($sp)
  lui   $t8, %hi(ptr_spectrum_roms) 
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  addiu $t7, $t2, 2
  li    $t4, 1
  addu  $t3, $t8, $t1
  sb    $t7, ($t3)
  lhu   $t9, 0x292($sp)
  lui   $t8, %hi(ptr_300alloc) 
  lw    $t8, %lo(ptr_300alloc)($t8)
  andi  $t0, $t9, 0x1800
  sra   $t6, $t0, 3
  andi  $t5, $t9, 0xff
  or    $t2, $t6, $t5
  addu  $t1, $t8, $t2
  sb    $t4, ($t1)
.L7F0DC6D8:
  lhu   $t7, 0x292($sp)
  lhu   $t2, 0x292($sp)
  lhu   $t0, 0x298($sp)
  addiu $t3, $t7, 1
  slti  $at, $t3, 0x5b00
  bnez  $at, .L7F0DC710
   addiu $t4, $t2, 1
  lui   $t5, %hi(ptr_spectrum_roms) 
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  addiu $t9, $t0, 2
  sra   $t6, $t9, 8
  addu  $t8, $t5, $t7
  b     .L7F0DC7A8
   sb    $t6, 1($t8)
.L7F0DC710:
  slti  $at, $t4, 0x5800
  bnez  $at, .L7F0DC754
   lhu   $t1, 0x292($sp)
  lhu   $t1, 0x298($sp)
  lui   $t9, %hi(ptr_spectrum_roms) 
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  addiu $t3, $t1, 2
  sra   $t0, $t3, 8
  addu  $t5, $t9, $t2
  sb    $t0, 1($t5)
  lui   $t6, %hi(ptr_300alloc) 
  lw    $t6, %lo(ptr_300alloc)($t6)
  lhu   $t8, 0x292($sp)
  li    $t7, 1
  addu  $t4, $t6, $t8
  b     .L7F0DC7A8
   sb    $t7, -0x57ff($t4)
.L7F0DC754:
  addiu $t3, $t1, 1
  slti  $at, $t3, 0x4000
  bnez  $at, .L7F0DC7A8
   lhu   $t9, 0x298($sp)
  lui   $t5, %hi(ptr_spectrum_roms) 
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  addiu $t2, $t9, 2
  sra   $t0, $t2, 8
  addu  $t6, $t5, $t1
  sb    $t0, 1($t6)
  lhu   $t7, 0x292($sp)
  lui   $t1, %hi(ptr_300alloc) 
  lw    $t1, %lo(ptr_300alloc)($t1)
  addiu $t4, $t7, 1
  andi  $t3, $t4, 0x1800
  sra   $t9, $t3, 3
  andi  $t2, $t4, 0xff
  or    $t5, $t9, $t2
  li    $t8, 1
  addu  $t0, $t1, $t5
  sb    $t8, ($t0)
.L7F0DC7A8:
  lui   $t7, %hi(ptr_spectrum_roms) 
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  lhu   $t6, 0x298($sp)
  addu  $t9, $t7, $t6
  lbu   $t2, 1($t9)
  addu  $t3, $t6, $t7
  lbu   $t4, ($t3)
  sll   $t1, $t2, 8
  or    $t5, $t4, $t1
  b     .L7F0E27FC
   sh    $t5, 0x298($sp)
.L7F0DC7D4:
  lhu   $t8, 0x298($sp)
  addiu $t0, $t8, 2
  b     .L7F0E27FC
   sh    $t0, 0x298($sp)
spectrum_op_CD:
  lw    $t3, 0x28c($sp)
  lhu   $t2, 0x292($sp)
  lhu   $t5, 0x298($sp)
  addiu $t7, $t3, 0xa
  addiu $t4, $t2, -2
  andi  $t1, $t4, 0xffff
  sw    $t7, 0x28c($sp)
  slti  $at, $t1, 0x5b00
  addiu $t9, $t7, 7
  sw    $t9, 0x28c($sp)
  bnez  $at, .L7F0DC82C
   sh    $t4, 0x292($sp)
  lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  addiu $t8, $t5, 2
  addu  $t3, $t0, $t1
  b     .L7F0DC8B8
   sb    $t8, ($t3)
.L7F0DC82C:
  lhu   $t7, 0x292($sp)
  lhu   $t3, 0x292($sp)
  lhu   $t6, 0x298($sp)
  slti  $at, $t7, 0x5800
  bnez  $at, .L7F0DC870
   lui   $t2, %hi(ptr_spectrum_roms) 
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  addiu $t9, $t6, 2
  lui   $t0, %hi(ptr_300alloc) 
  addu  $t4, $t2, $t7
  sb    $t9, ($t4)
  lhu   $t1, 0x292($sp)
  lw    $t0, %lo(ptr_300alloc)($t0)
  li    $t5, 1
  addu  $t8, $t0, $t1
  b     .L7F0DC8B8
   sb    $t5, -0x5800($t8)
.L7F0DC870:
  slti  $at, $t3, 0x4000
  bnez  $at, .L7F0DC8B8
   lhu   $t6, 0x298($sp)
  lui   $t7, %hi(ptr_spectrum_roms) 
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  addiu $t2, $t6, 2
  li    $t4, 1
  addu  $t9, $t7, $t3
  sb    $t2, ($t9)
  lhu   $t0, 0x292($sp)
  lui   $t7, %hi(ptr_300alloc) 
  lw    $t7, %lo(ptr_300alloc)($t7)
  andi  $t1, $t0, 0x1800
  sra   $t5, $t1, 3
  andi  $t8, $t0, 0xff
  or    $t6, $t5, $t8
  addu  $t3, $t7, $t6
  sb    $t4, ($t3)
.L7F0DC8B8:
  lhu   $t2, 0x292($sp)
  lhu   $t6, 0x292($sp)
  lhu   $t1, 0x298($sp)
  addiu $t9, $t2, 1
  slti  $at, $t9, 0x5b00
  bnez  $at, .L7F0DC8F0
   addiu $t4, $t6, 1
  lui   $t8, %hi(ptr_spectrum_roms) 
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  addiu $t0, $t1, 2
  sra   $t5, $t0, 8
  addu  $t7, $t8, $t2
  b     .L7F0DC988
   sb    $t5, 1($t7)
.L7F0DC8F0:
  slti  $at, $t4, 0x5800
  bnez  $at, .L7F0DC934
   lhu   $t3, 0x292($sp)
  lhu   $t3, 0x298($sp)
  lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  addiu $t9, $t3, 2
  sra   $t1, $t9, 8
  addu  $t8, $t0, $t6
  sb    $t1, 1($t8)
  lui   $t5, %hi(ptr_300alloc) 
  lw    $t5, %lo(ptr_300alloc)($t5)
  lhu   $t7, 0x292($sp)
  li    $t2, 1
  addu  $t4, $t5, $t7
  b     .L7F0DC988
   sb    $t2, -0x57ff($t4)
.L7F0DC934:
  addiu $t9, $t3, 1
  slti  $at, $t9, 0x4000
  bnez  $at, .L7F0DC988
   lhu   $t0, 0x298($sp)
  lui   $t8, %hi(ptr_spectrum_roms) 
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  addiu $t6, $t0, 2
  sra   $t1, $t6, 8
  addu  $t5, $t8, $t3
  sb    $t1, 1($t5)
  lhu   $t2, 0x292($sp)
  lui   $t3, %hi(ptr_300alloc) 
  lw    $t3, %lo(ptr_300alloc)($t3)
  addiu $t4, $t2, 1
  andi  $t9, $t4, 0x1800
  sra   $t0, $t9, 3
  andi  $t6, $t4, 0xff
  or    $t8, $t0, $t6
  li    $t7, 1
  addu  $t1, $t3, $t8
  sb    $t7, ($t1)
.L7F0DC988:
  lui   $t2, %hi(ptr_spectrum_roms) 
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  lhu   $t5, 0x298($sp)
  addu  $t0, $t2, $t5
  lbu   $t6, 1($t0)
  addu  $t9, $t5, $t2
  lbu   $t4, ($t9)
  sll   $t3, $t6, 8
  or    $t8, $t4, $t3
  b     .L7F0E27FC
   sh    $t8, 0x298($sp)
spectrum_op_CE:
  lw    $t7, 0x28c($sp)
  lui   $t2, %hi(ptr_spectrum_roms) 
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  lhu   $t9, 0x298($sp)
  addiu $t1, $t7, 7
  sw    $t1, 0x28c($sp)
  addu  $t5, $t9, $t2
  lbu   $t0, ($t5)
  andi  $t4, $s1, 1
  andi  $t8, $s1, 1
  addu  $t6, $s0, $t0
  addu  $t3, $t6, $t4
  andi  $t6, $s0, 0xf
  andi  $t5, $t0, 0xf
  addu  $t4, $t6, $t5
  andi  $t7, $t3, 0xa8
  sra   $t9, $t3, 8
  or    $t2, $t7, $t9
  addu  $t1, $t4, $t8
  li    $at, 15
  slt   $t7, $at, $t1
  sll   $t9, $t7, 4
  move  $t1, $t3
  not   $t5, $s0
  xor   $t7, $t1, $s0
  sh    $t3, 0xfe($sp)
  xor   $t4, $t5, $t0
  lbu   $s0, 0xff($sp)
  andi  $t8, $t4, 0x80
  or    $t6, $t2, $t9
  and   $t2, $t8, $t7
  sb    $t0, 0xfd($sp)
  lhu   $t8, 0x298($sp)
  sra   $t9, $t2, 5
  sltiu $t0, $s0, 1
  sll   $t3, $t0, 6
  or    $t5, $t6, $t9
  or    $s1, $t5, $t3
  andi  $t1, $s1, 0xff
  addiu $t7, $t8, 1
  move  $s1, $t1
  sw    $t0, 0x48($sp)
  b     .L7F0E27FC
   sh    $t7, 0x298($sp)
spectrum_op_CF:
  lhu   $t9, 0x292($sp)
  lw    $t2, 0x28c($sp)
  lui   $t3, %hi(ptr_spectrum_roms) 
  addiu $t5, $t9, -2
  andi  $t0, $t5, 0xffff
  slti  $at, $t0, 0x5b00
  addiu $t6, $t2, 0xb
  sw    $t6, 0x28c($sp)
  bnez  $at, .L7F0DCAA0
   sh    $t5, 0x292($sp)
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  lhu   $t4, 0x298($sp)
  addu  $t1, $t3, $t0
  b     .L7F0DCB28
   sb    $t4, ($t1)
.L7F0DCAA0:
  lhu   $t8, 0x292($sp)
  lhu   $t4, 0x292($sp)
  lui   $t2, %hi(ptr_spectrum_roms) 
  slti  $at, $t8, 0x5800
  bnezl $at, .L7F0DCAE8
   slti  $at, $t4, 0x4000
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  lhu   $t7, 0x298($sp)
  lui   $t5, %hi(ptr_300alloc) 
  addu  $t6, $t2, $t8
  sb    $t7, ($t6)
  lhu   $t3, 0x292($sp)
  lw    $t5, %lo(ptr_300alloc)($t5)
  li    $t9, 1
  addu  $t0, $t5, $t3
  b     .L7F0DCB28
   sb    $t9, -0x5800($t0)
  slti  $at, $t4, 0x4000
.L7F0DCAE8:
  bnez  $at, .L7F0DCB28
   lui   $t2, %hi(ptr_spectrum_roms) 
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  lhu   $t1, 0x298($sp)
  li    $t7, 1
  addu  $t8, $t2, $t4
  sb    $t1, ($t8)
  lhu   $t6, 0x292($sp)
  lui   $t2, %hi(ptr_300alloc) 
  lw    $t2, %lo(ptr_300alloc)($t2)
  andi  $t5, $t6, 0x1800
  sra   $t3, $t5, 3
  andi  $t9, $t6, 0xff
  or    $t0, $t3, $t9
  addu  $t4, $t2, $t0
  sb    $t7, ($t4)
.L7F0DCB28:
  lhu   $t1, 0x292($sp)
  lhu   $t2, 0x292($sp)
  lhu   $t5, 0x298($sp)
  addiu $t8, $t1, 1
  slti  $at, $t8, 0x5b00
  bnez  $at, .L7F0DCB5C
   addiu $t0, $t2, 1
  lui   $t3, %hi(ptr_spectrum_roms) 
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  sra   $t6, $t5, 8
  addu  $t9, $t3, $t1
  b     .L7F0DCBEC
   sb    $t6, 1($t9)
.L7F0DCB5C:
  slti  $at, $t0, 0x5800
  bnez  $at, .L7F0DCB9C
   lhu   $t0, 0x292($sp)
  lui   $t8, %hi(ptr_spectrum_roms) 
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  lhu   $t7, 0x298($sp)
  lui   $t1, %hi(ptr_300alloc) 
  addu  $t5, $t8, $t2
  sra   $t4, $t7, 8
  sb    $t4, 1($t5)
  lhu   $t6, 0x292($sp)
  lw    $t1, %lo(ptr_300alloc)($t1)
  li    $t3, 1
  addu  $t9, $t1, $t6
  b     .L7F0DCBEC
   sb    $t3, -0x57ff($t9)
.L7F0DCB9C:
  addiu $t7, $t0, 1
  slti  $at, $t7, 0x4000
  bnez  $at, .L7F0DCBEC
   lhu   $t8, 0x298($sp)
  lui   $t4, %hi(ptr_spectrum_roms) 
  lw    $t4, %lo(ptr_spectrum_roms)($t4)
  sra   $t2, $t8, 8
  li    $t1, 1
  addu  $t5, $t4, $t0
  sb    $t2, 1($t5)
  lhu   $t6, 0x292($sp)
  lui   $t0, %hi(ptr_300alloc) 
  lw    $t0, %lo(ptr_300alloc)($t0)
  addiu $t3, $t6, 1
  andi  $t9, $t3, 0x1800
  sra   $t7, $t9, 3
  andi  $t8, $t3, 0xff
  or    $t4, $t7, $t8
  addu  $t2, $t0, $t4
  sb    $t1, ($t2)
.L7F0DCBEC:
  li    $t5, 8
  b     .L7F0E27FC
   sh    $t5, 0x298($sp)
spectrum_op_D0:
  lw    $t6, 0x28c($sp)
  andi  $t3, $s1, 1
  lui   $t4, %hi(ptr_spectrum_roms) 
  addiu $t9, $t6, 5
  bnez  $t3, .L7F0E27FC
   sw    $t9, 0x28c($sp)
  lhu   $t0, 0x292($sp)
  lw    $t4, %lo(ptr_spectrum_roms)($t4)
  addiu $t8, $t9, 6
  sw    $t8, 0x28c($sp)
  addu  $t5, $t4, $t0
  lbu   $t6, 1($t5)
  addu  $t1, $t0, $t4
  lbu   $t2, ($t1)
  sll   $t9, $t6, 8
  addiu $t7, $t0, 2
  or    $t3, $t2, $t9
  sh    $t3, 0x298($sp)
  b     .L7F0E27FC
   sh    $t7, 0x292($sp)
spectrum_op_D1:
  lw    $t8, 0x28c($sp)
  lui   $t5, %hi(ptr_spectrum_roms) 
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  lhu   $t4, 0x292($sp)
  addiu $t1, $t8, 0xa
  sw    $t1, 0x28c($sp)
  addu  $t6, $t4, $t5
  lbu   $s5, ($t6)
  lbu   $s4, 1($t6)
  addiu $t2, $t4, 2
  b     .L7F0E27FC
   sh    $t2, 0x292($sp)
spectrum_op_D2:
  lw    $t9, 0x28c($sp)
  andi  $t0, $s1, 1
  lhu   $t7, 0x298($sp)
  addiu $t3, $t9, 0xa
  bnez  $t0, .L7F0DCCB8
   sw    $t3, 0x28c($sp)
  lui   $t8, %hi(ptr_spectrum_roms) 
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  addu  $t6, $t8, $t7
  lbu   $t4, 1($t6)
  addu  $t1, $t7, $t8
  lbu   $t5, ($t1)
  sll   $t2, $t4, 8
  or    $t9, $t5, $t2
  b     .L7F0E27FC
   sh    $t9, 0x298($sp)
.L7F0DCCB8:
  lhu   $t3, 0x298($sp)
  addiu $t0, $t3, 2
  b     .L7F0E27FC
   sh    $t0, 0x298($sp)
spectrum_op_D3:
  lw    $t1, 0x28c($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  lhu   $t7, 0x298($sp)
  addiu $a0, $t1, 0xb
  sw    $a0, 0x28c($sp)
  addu  $t4, $t7, $t6
  lbu   $a2, ($t4)
  move  $a1, $s0
  jal   sub_GAME_7F0D37DC
   move  $a3, $s0
  lw    $t5, 0x28c($sp)
  lhu   $t3, 0x298($sp)
  sw    $v0, 0x48($sp)
  addu  $t9, $t5, $v0
  addiu $t0, $t3, 1
  sw    $t9, 0x28c($sp)
  b     .L7F0E27FC
   sh    $t0, 0x298($sp)
spectrum_op_D4:
  lw    $t1, 0x28c($sp)
  andi  $t7, $s1, 1
  addiu $t8, $t1, 0xa
  bnez  $t7, .L7F0DCEEC
   sw    $t8, 0x28c($sp)
  lhu   $t5, 0x292($sp)
  addiu $t4, $t8, 7
  sw    $t4, 0x28c($sp)
  addiu $t2, $t5, -2
  andi  $t9, $t2, 0xffff
  slti  $at, $t9, 0x5b00
  bnez  $at, .L7F0DCD64
   sh    $t2, 0x292($sp)
  lui   $t1, %hi(ptr_spectrum_roms) 
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  lhu   $t3, 0x298($sp)
  addu  $t8, $t1, $t9
  addiu $t0, $t3, 2
  b     .L7F0DCDF0
   sb    $t0, ($t8)
.L7F0DCD64:
  lhu   $t7, 0x292($sp)
  lhu   $t8, 0x292($sp)
  lhu   $t6, 0x298($sp)
  slti  $at, $t7, 0x5800
  bnez  $at, .L7F0DCDA8
   lui   $t5, %hi(ptr_spectrum_roms) 
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  addiu $t4, $t6, 2
  lui   $t1, %hi(ptr_300alloc) 
  addu  $t2, $t5, $t7
  sb    $t4, ($t2)
  lhu   $t9, 0x292($sp)
  lw    $t1, %lo(ptr_300alloc)($t1)
  li    $t3, 1
  addu  $t0, $t1, $t9
  b     .L7F0DCDF0
   sb    $t3, -0x5800($t0)
.L7F0DCDA8:
  slti  $at, $t8, 0x4000
  bnez  $at, .L7F0DCDF0
   lhu   $t6, 0x298($sp)
  lui   $t7, %hi(ptr_spectrum_roms) 
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  addiu $t5, $t6, 2
  li    $t2, 1
  addu  $t4, $t7, $t8
  sb    $t5, ($t4)
  lhu   $t1, 0x292($sp)
  lui   $t7, %hi(ptr_300alloc) 
  lw    $t7, %lo(ptr_300alloc)($t7)
  andi  $t9, $t1, 0x1800
  sra   $t3, $t9, 3
  andi  $t0, $t1, 0xff
  or    $t6, $t3, $t0
  addu  $t8, $t7, $t6
  sb    $t2, ($t8)
.L7F0DCDF0:
  lhu   $t5, 0x292($sp)
  lhu   $t6, 0x292($sp)
  lhu   $t9, 0x298($sp)
  addiu $t4, $t5, 1
  slti  $at, $t4, 0x5b00
  bnez  $at, .L7F0DCE28
   addiu $t2, $t6, 1
  lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  addiu $t1, $t9, 2
  sra   $t3, $t1, 8
  addu  $t7, $t0, $t5
  b     .L7F0DCEC0
   sb    $t3, 1($t7)
.L7F0DCE28:
  slti  $at, $t2, 0x5800
  bnez  $at, .L7F0DCE6C
   lhu   $t8, 0x292($sp)
  lhu   $t8, 0x298($sp)
  lui   $t1, %hi(ptr_spectrum_roms) 
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  addiu $t4, $t8, 2
  sra   $t9, $t4, 8
  addu  $t0, $t1, $t6
  sb    $t9, 1($t0)
  lui   $t3, %hi(ptr_300alloc) 
  lw    $t3, %lo(ptr_300alloc)($t3)
  lhu   $t7, 0x292($sp)
  li    $t5, 1
  addu  $t2, $t3, $t7
  b     .L7F0DCEC0
   sb    $t5, -0x57ff($t2)
.L7F0DCE6C:
  addiu $t4, $t8, 1
  slti  $at, $t4, 0x4000
  bnez  $at, .L7F0DCEC0
   lhu   $t1, 0x298($sp)
  lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  addiu $t6, $t1, 2
  sra   $t9, $t6, 8
  addu  $t3, $t0, $t8
  sb    $t9, 1($t3)
  lhu   $t5, 0x292($sp)
  lui   $t8, %hi(ptr_300alloc) 
  lw    $t8, %lo(ptr_300alloc)($t8)
  addiu $t2, $t5, 1
  andi  $t4, $t2, 0x1800
  sra   $t1, $t4, 3
  andi  $t6, $t2, 0xff
  or    $t0, $t1, $t6
  li    $t7, 1
  addu  $t9, $t8, $t0
  sb    $t7, ($t9)
.L7F0DCEC0:
  lui   $t5, %hi(ptr_spectrum_roms) 
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  lhu   $t3, 0x298($sp)
  addu  $t1, $t5, $t3
  lbu   $t6, 1($t1)
  addu  $t4, $t3, $t5
  lbu   $t2, ($t4)
  sll   $t8, $t6, 8
  or    $t0, $t2, $t8
  b     .L7F0E27FC
   sh    $t0, 0x298($sp)
.L7F0DCEEC:
  lhu   $t7, 0x298($sp)
  addiu $t9, $t7, 2
  b     .L7F0E27FC
   sh    $t9, 0x298($sp)
spectrum_op_D5:
  lhu   $t3, 0x292($sp)
  lw    $t4, 0x28c($sp)
  lui   $t2, %hi(ptr_spectrum_roms) 
  addiu $t1, $t3, -2
  andi  $t6, $t1, 0xffff
  slti  $at, $t6, 0x5b00
  addiu $t5, $t4, 0xb
  sw    $t5, 0x28c($sp)
  bnez  $at, .L7F0DCF34
   sh    $t1, 0x292($sp)
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  addu  $t8, $t2, $t6
  b     .L7F0DCFB4
   sb    $s5, ($t8)
.L7F0DCF34:
  lhu   $t0, 0x292($sp)
  lhu   $t2, 0x292($sp)
  lui   $t7, %hi(ptr_spectrum_roms) 
  slti  $at, $t0, 0x5800
  bnezl $at, .L7F0DCF78
   slti  $at, $t2, 0x4000
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  lui   $t5, %hi(ptr_300alloc) 
  li    $t4, 1
  addu  $t9, $t7, $t0
  sb    $s5, ($t9)
  lhu   $t3, 0x292($sp)
  lw    $t5, %lo(ptr_300alloc)($t5)
  addu  $t1, $t5, $t3
  b     .L7F0DCFB4
   sb    $t4, -0x5800($t1)
  slti  $at, $t2, 0x4000
.L7F0DCF78:
  bnez  $at, .L7F0DCFB4
   lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  lui   $t1, %hi(ptr_300alloc) 
  li    $t7, 1
  addu  $t8, $t6, $t2
  sb    $s5, ($t8)
  lhu   $t0, 0x292($sp)
  lw    $t1, %lo(ptr_300alloc)($t1)
  andi  $t9, $t0, 0x1800
  sra   $t5, $t9, 3
  andi  $t3, $t0, 0xff
  or    $t4, $t5, $t3
  addu  $t6, $t1, $t4
  sb    $t7, ($t6)
.L7F0DCFB4:
  lhu   $t2, 0x292($sp)
  lhu   $t5, 0x292($sp)
  lui   $t9, %hi(ptr_spectrum_roms) 
  addiu $t8, $t2, 1
  slti  $at, $t8, 0x5b00
  bnez  $at, .L7F0DCFE0
   addiu $t3, $t5, 1
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  addu  $t0, $t9, $t2
  b     .L7F0E27FC
   sb    $s4, 1($t0)
.L7F0DCFE0:
  slti  $at, $t3, 0x5800
  bnez  $at, .L7F0DD018
   lhu   $t2, 0x292($sp)
  lui   $t1, %hi(ptr_spectrum_roms) 
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  lui   $t6, %hi(ptr_300alloc) 
  li    $t7, 1
  addu  $t4, $t1, $t5
  sb    $s4, 1($t4)
  lhu   $t8, 0x292($sp)
  lw    $t6, %lo(ptr_300alloc)($t6)
  addu  $t9, $t6, $t8
  b     .L7F0E27FC
   sb    $t7, -0x57ff($t9)
.L7F0DD018:
  addiu $t0, $t2, 1
  slti  $at, $t0, 0x4000
  bnez  $at, .L7F0E27FC
   lui   $t3, %hi(ptr_spectrum_roms) 
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  li    $t5, 1
  addu  $t1, $t3, $t2
  sb    $s4, 1($t1)
  lhu   $t4, 0x292($sp)
  lui   $t3, %hi(ptr_300alloc) 
  lw    $t3, %lo(ptr_300alloc)($t3)
  addiu $t6, $t4, 1
  andi  $t8, $t6, 0x1800
  sra   $t7, $t8, 3
  andi  $t9, $t6, 0xff
  or    $t0, $t7, $t9
  addu  $t2, $t3, $t0
  b     .L7F0E27FC
   sb    $t5, ($t2)
spectrum_op_D6:
  lw    $t1, 0x28c($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  lhu   $t8, 0x298($sp)
  addiu $t4, $t1, 7
  sw    $t4, 0x28c($sp)
  addu  $t7, $t8, $t6
  lbu   $t9, ($t7)
  andi  $t7, $s0, 0xf
  subu  $t3, $s0, $t9
  andi  $t0, $t3, 0x1ff
  andi  $t2, $t0, 0xa8
  sra   $t4, $t0, 8
  andi  $t6, $t9, 0xf
  slt   $t3, $t7, $t6
  or    $t8, $t2, $t4
  xor   $t2, $s0, $t9
  sll   $t5, $t3, 4
  xor   $t6, $t0, $s0
  sh    $t0, 0xfa($sp)
  lbu   $s0, 0xfb($sp)
  andi  $t4, $t2, 0x80
  and   $t3, $t4, $t6
  or    $t1, $t8, $t5
  sra   $t8, $t3, 5
  lhu   $t6, 0x298($sp)
  or    $s1, $t1, $t8
  sb    $t9, 0xf9($sp)
  sltiu $t2, $s0, 1
  sll   $t7, $t2, 6
  ori   $t9, $s1, 2
  or    $s1, $t9, $t7
  andi  $t4, $s1, 0xff
  addiu $t3, $t6, 1
  move  $s1, $t4
  sw    $t2, 0x48($sp)
  b     .L7F0E27FC
   sh    $t3, 0x298($sp)
spectrum_op_D7:
  lhu   $t5, 0x292($sp)
  lw    $t1, 0x28c($sp)
  lui   $t7, %hi(ptr_spectrum_roms) 
  addiu $t9, $t5, -2
  andi  $t2, $t9, 0xffff
  slti  $at, $t2, 0x5b00
  addiu $t8, $t1, 0xb
  sw    $t8, 0x28c($sp)
  bnez  $at, .L7F0DD138
   sh    $t9, 0x292($sp)
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  lhu   $t0, 0x298($sp)
  addu  $t4, $t7, $t2
  b     .L7F0DD1C0
   sb    $t0, ($t4)
.L7F0DD138:
  lhu   $t6, 0x292($sp)
  lhu   $t0, 0x292($sp)
  lui   $t1, %hi(ptr_spectrum_roms) 
  slti  $at, $t6, 0x5800
  bnezl $at, .L7F0DD180
   slti  $at, $t0, 0x4000
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  lhu   $t3, 0x298($sp)
  lui   $t9, %hi(ptr_300alloc) 
  addu  $t8, $t1, $t6
  sb    $t3, ($t8)
  lhu   $t7, 0x292($sp)
  lw    $t9, %lo(ptr_300alloc)($t9)
  li    $t5, 1
  addu  $t2, $t9, $t7
  b     .L7F0DD1C0
   sb    $t5, -0x5800($t2)
  slti  $at, $t0, 0x4000
.L7F0DD180:
  bnez  $at, .L7F0DD1C0
   lui   $t1, %hi(ptr_spectrum_roms) 
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  lhu   $t4, 0x298($sp)
  li    $t3, 1
  addu  $t6, $t1, $t0
  sb    $t4, ($t6)
  lhu   $t8, 0x292($sp)
  lui   $t1, %hi(ptr_300alloc) 
  lw    $t1, %lo(ptr_300alloc)($t1)
  andi  $t9, $t8, 0x1800
  sra   $t7, $t9, 3
  andi  $t5, $t8, 0xff
  or    $t2, $t7, $t5
  addu  $t0, $t1, $t2
  sb    $t3, ($t0)
.L7F0DD1C0:
  lhu   $t4, 0x292($sp)
  lhu   $t1, 0x292($sp)
  lhu   $t9, 0x298($sp)
  addiu $t6, $t4, 1
  slti  $at, $t6, 0x5b00
  bnez  $at, .L7F0DD1F4
   addiu $t2, $t1, 1
  lui   $t7, %hi(ptr_spectrum_roms) 
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  sra   $t8, $t9, 8
  addu  $t5, $t7, $t4
  b     .L7F0DD284
   sb    $t8, 1($t5)
.L7F0DD1F4:
  slti  $at, $t2, 0x5800
  bnez  $at, .L7F0DD234
   lhu   $t2, 0x292($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  lhu   $t3, 0x298($sp)
  lui   $t4, %hi(ptr_300alloc) 
  addu  $t9, $t6, $t1
  sra   $t0, $t3, 8
  sb    $t0, 1($t9)
  lhu   $t8, 0x292($sp)
  lw    $t4, %lo(ptr_300alloc)($t4)
  li    $t7, 1
  addu  $t5, $t4, $t8
  b     .L7F0DD284
   sb    $t7, -0x57ff($t5)
.L7F0DD234:
  addiu $t3, $t2, 1
  slti  $at, $t3, 0x4000
  bnez  $at, .L7F0DD284
   lhu   $t6, 0x298($sp)
  lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  sra   $t1, $t6, 8
  li    $t4, 1
  addu  $t9, $t0, $t2
  sb    $t1, 1($t9)
  lhu   $t8, 0x292($sp)
  lui   $t2, %hi(ptr_300alloc) 
  lw    $t2, %lo(ptr_300alloc)($t2)
  addiu $t7, $t8, 1
  andi  $t5, $t7, 0x1800
  sra   $t3, $t5, 3
  andi  $t6, $t7, 0xff
  or    $t0, $t3, $t6
  addu  $t1, $t2, $t0
  sb    $t4, ($t1)
.L7F0DD284:
  li    $t9, 16
  b     .L7F0E27FC
   sh    $t9, 0x298($sp)
spectrum_op_D8:
  lw    $t8, 0x28c($sp)
  andi  $t7, $s1, 1
  lui   $t0, %hi(ptr_spectrum_roms) 
  addiu $t5, $t8, 5
  beqz  $t7, .L7F0E27FC
   sw    $t5, 0x28c($sp)
  lhu   $t2, 0x292($sp)
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  addiu $t6, $t5, 6
  sw    $t6, 0x28c($sp)
  addu  $t9, $t0, $t2
  lbu   $t8, 1($t9)
  addu  $t4, $t2, $t0
  lbu   $t1, ($t4)
  sll   $t5, $t8, 8
  addiu $t3, $t2, 2
  or    $t7, $t1, $t5
  sh    $t7, 0x298($sp)
  b     .L7F0E27FC
   sh    $t3, 0x292($sp)
spectrum_op_D9:
  lw    $t6, 0x28c($sp)
  sb    $s2, 0xf8($sp)
  sb    $s3, 0xf7($sp)
  sb    $s4, 0xf6($sp)
  sb    $s5, 0xf5($sp)
  sb    $s6, 0xf4($sp)
  sb    $s7, 0xf3($sp)
  lbu   $t0, 0xf8($sp)
  lbu   $t9, 0xf7($sp)
  lbu   $t8, 0xf6($sp)
  lbu   $t1, 0xf5($sp)
  lbu   $t5, 0xf4($sp)
  lbu   $t7, 0xf3($sp)
  lbu   $s2, 0x2a4($sp)
  lbu   $s3, 0x2a3($sp)
  lbu   $s4, 0x2a2($sp)
  lbu   $s5, 0x2a1($sp)
  lbu   $s6, 0x2a0($sp)
  lbu   $s7, 0x29f($sp)
  addiu $t4, $t6, 4
  sw    $t4, 0x28c($sp)
  sb    $t0, 0x2a4($sp)
  sb    $t9, 0x2a3($sp)
  sb    $t8, 0x2a2($sp)
  sb    $t1, 0x2a1($sp)
  sb    $t5, 0x2a0($sp)
  b     .L7F0E27FC
   sb    $t7, 0x29f($sp)
spectrum_op_DA:
  lw    $t2, 0x28c($sp)
  andi  $t6, $s1, 1
  lhu   $t4, 0x298($sp)
  addiu $t3, $t2, 0xa
  beqz  $t6, .L7F0DD390
   sw    $t3, 0x28c($sp)
  lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  addu  $t1, $t0, $t4
  lbu   $t5, 1($t1)
  addu  $t9, $t4, $t0
  lbu   $t8, ($t9)
  sll   $t7, $t5, 8
  or    $t2, $t8, $t7
  b     .L7F0E27FC
   sh    $t2, 0x298($sp)
.L7F0DD390:
  lhu   $t3, 0x298($sp)
  addiu $t6, $t3, 2
  b     .L7F0E27FC
   sh    $t6, 0x298($sp)
spectrum_op_DB:
  lw    $t9, 0x28c($sp)
  lui   $t1, %hi(ptr_spectrum_roms) 
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  lhu   $t4, 0x298($sp)
  addiu $a0, $t9, 0xb
  sw    $a0, 0x28c($sp)
  addu  $t5, $t4, $t1
  lbu   $a2, ($t5)
  jal   spectrum_input_handling
   move  $a1, $s0
  lw    $t8, 0x28c($sp)
  lhu   $t6, 0x298($sp)
  andi  $t7, $v0, 0xffff
  sra   $t2, $t7, 8
  sh    $v0, 0xf0($sp)
  addu  $t3, $t8, $t2
  addiu $t9, $t6, 1
  lbu   $s0, 0xf1($sp)
  sw    $t3, 0x28c($sp)
  b     .L7F0E27FC
   sh    $t9, 0x298($sp)
spectrum_op_DC:
  lw    $t0, 0x28c($sp)
  andi  $t1, $s1, 1
  addiu $t4, $t0, 0xa
  beqz  $t1, .L7F0DD5CC
   sw    $t4, 0x28c($sp)
  lhu   $t8, 0x292($sp)
  addiu $t7, $t4, 7
  sw    $t7, 0x28c($sp)
  addiu $t2, $t8, -2
  andi  $t3, $t2, 0xffff
  slti  $at, $t3, 0x5b00
  bnez  $at, .L7F0DD444
   sh    $t2, 0x292($sp)
  lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  lhu   $t6, 0x298($sp)
  addu  $t4, $t0, $t3
  addiu $t9, $t6, 2
  b     .L7F0DD4D0
   sb    $t9, ($t4)
.L7F0DD444:
  lhu   $t1, 0x292($sp)
  lhu   $t4, 0x292($sp)
  lhu   $t5, 0x298($sp)
  slti  $at, $t1, 0x5800
  bnez  $at, .L7F0DD488
   lui   $t8, %hi(ptr_spectrum_roms) 
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  addiu $t7, $t5, 2
  lui   $t0, %hi(ptr_300alloc) 
  addu  $t2, $t8, $t1
  sb    $t7, ($t2)
  lhu   $t3, 0x292($sp)
  lw    $t0, %lo(ptr_300alloc)($t0)
  li    $t6, 1
  addu  $t9, $t0, $t3
  b     .L7F0DD4D0
   sb    $t6, -0x5800($t9)
.L7F0DD488:
  slti  $at, $t4, 0x4000
  bnez  $at, .L7F0DD4D0
   lhu   $t5, 0x298($sp)
  lui   $t1, %hi(ptr_spectrum_roms) 
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  addiu $t8, $t5, 2
  li    $t2, 1
  addu  $t7, $t1, $t4
  sb    $t8, ($t7)
  lhu   $t0, 0x292($sp)
  lui   $t1, %hi(ptr_300alloc) 
  lw    $t1, %lo(ptr_300alloc)($t1)
  andi  $t3, $t0, 0x1800
  sra   $t6, $t3, 3
  andi  $t9, $t0, 0xff
  or    $t5, $t6, $t9
  addu  $t4, $t1, $t5
  sb    $t2, ($t4)
.L7F0DD4D0:
  lhu   $t8, 0x292($sp)
  lhu   $t5, 0x292($sp)
  lhu   $t3, 0x298($sp)
  addiu $t7, $t8, 1
  slti  $at, $t7, 0x5b00
  bnez  $at, .L7F0DD508
   addiu $t2, $t5, 1
  lui   $t9, %hi(ptr_spectrum_roms) 
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  addiu $t0, $t3, 2
  sra   $t6, $t0, 8
  addu  $t1, $t9, $t8
  b     .L7F0DD5A0
   sb    $t6, 1($t1)
.L7F0DD508:
  slti  $at, $t2, 0x5800
  bnez  $at, .L7F0DD54C
   lhu   $t4, 0x292($sp)
  lhu   $t4, 0x298($sp)
  lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  addiu $t7, $t4, 2
  sra   $t3, $t7, 8
  addu  $t9, $t0, $t5
  sb    $t3, 1($t9)
  lui   $t6, %hi(ptr_300alloc) 
  lw    $t6, %lo(ptr_300alloc)($t6)
  lhu   $t1, 0x292($sp)
  li    $t8, 1
  addu  $t2, $t6, $t1
  b     .L7F0DD5A0
   sb    $t8, -0x57ff($t2)
.L7F0DD54C:
  addiu $t7, $t4, 1
  slti  $at, $t7, 0x4000
  bnez  $at, .L7F0DD5A0
   lhu   $t0, 0x298($sp)
  lui   $t9, %hi(ptr_spectrum_roms) 
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  addiu $t5, $t0, 2
  sra   $t3, $t5, 8
  addu  $t6, $t9, $t4
  sb    $t3, 1($t6)
  lhu   $t8, 0x292($sp)
  lui   $t4, %hi(ptr_300alloc) 
  lw    $t4, %lo(ptr_300alloc)($t4)
  addiu $t2, $t8, 1
  andi  $t7, $t2, 0x1800
  sra   $t0, $t7, 3
  andi  $t5, $t2, 0xff
  or    $t9, $t0, $t5
  li    $t1, 1
  addu  $t3, $t4, $t9
  sb    $t1, ($t3)
.L7F0DD5A0:
  lui   $t8, %hi(ptr_spectrum_roms) 
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  lhu   $t6, 0x298($sp)
  addu  $t0, $t8, $t6
  lbu   $t5, 1($t0)
  addu  $t7, $t6, $t8
  lbu   $t2, ($t7)
  sll   $t4, $t5, 8
  or    $t9, $t2, $t4
  b     .L7F0E27FC
   sh    $t9, 0x298($sp)
.L7F0DD5CC:
  lhu   $t1, 0x298($sp)
  addiu $t3, $t1, 2
  b     .L7F0E27FC
   sh    $t3, 0x298($sp)
spectrum_op_DD:
  lw    $t7, 0x28c($sp)
  li    $t6, 1
  sb    $t6, 0x286($sp)
  addiu $t8, $t7, 4
  sw    $t8, 0x28c($sp)
  b     .L7F0E27FC
   sb    $zero, 0x285($sp)
spectrum_op_DE:
  lw    $t0, 0x28c($sp)
  lui   $t4, %hi(ptr_spectrum_roms) 
  lw    $t4, %lo(ptr_spectrum_roms)($t4)
  lhu   $t2, 0x298($sp)
  addiu $t5, $t0, 7
  sw    $t5, 0x28c($sp)
  addu  $t9, $t2, $t4
  lbu   $t1, ($t9)
  andi  $t7, $s1, 1
  andi  $t0, $s0, 0xf
  subu  $t3, $s0, $t1
  subu  $t8, $t3, $t7
  andi  $t6, $t8, 0x1ff
  andi  $t3, $t1, 0xf
  addu  $t8, $t3, $t7
  slt   $t2, $t0, $t8
  andi  $t5, $t6, 0xa8
  sra   $t4, $t6, 8
  or    $t9, $t5, $t4
  xor   $t3, $s0, $t1
  sll   $t5, $t2, 4
  xor   $t8, $t6, $s0
  sh    $t6, 0xee($sp)
  lbu   $s0, 0xef($sp)
  andi  $t7, $t3, 0x80
  and   $t2, $t7, $t8
  or    $t4, $t9, $t5
  sra   $t9, $t2, 5
  lhu   $t8, 0x298($sp)
  or    $s1, $t4, $t9
  sb    $t1, 0xed($sp)
  sltiu $t3, $s0, 1
  sll   $t0, $t3, 6
  ori   $t1, $s1, 2
  or    $s1, $t1, $t0
  andi  $t7, $s1, 0xff
  addiu $t2, $t8, 1
  move  $s1, $t7
  sw    $t3, 0x48($sp)
  b     .L7F0E27FC
   sh    $t2, 0x298($sp)
spectrum_op_DF:
  lhu   $t5, 0x292($sp)
  lw    $t4, 0x28c($sp)
  lui   $t0, %hi(ptr_spectrum_roms) 
  addiu $t1, $t5, -2
  andi  $t3, $t1, 0xffff
  slti  $at, $t3, 0x5b00
  addiu $t9, $t4, 0xb
  sw    $t9, 0x28c($sp)
  bnez  $at, .L7F0DD6D8
   sh    $t1, 0x292($sp)
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  lhu   $t6, 0x298($sp)
  addu  $t7, $t0, $t3
  b     .L7F0DD760
   sb    $t6, ($t7)
.L7F0DD6D8:
  lhu   $t8, 0x292($sp)
  lhu   $t6, 0x292($sp)
  lui   $t4, %hi(ptr_spectrum_roms) 
  slti  $at, $t8, 0x5800
  bnezl $at, .L7F0DD720
   slti  $at, $t6, 0x4000
  lw    $t4, %lo(ptr_spectrum_roms)($t4)
  lhu   $t2, 0x298($sp)
  lui   $t1, %hi(ptr_300alloc) 
  addu  $t9, $t4, $t8
  sb    $t2, ($t9)
  lhu   $t0, 0x292($sp)
  lw    $t1, %lo(ptr_300alloc)($t1)
  li    $t5, 1
  addu  $t3, $t1, $t0
  b     .L7F0DD760
   sb    $t5, -0x5800($t3)
  slti  $at, $t6, 0x4000
.L7F0DD720:
  bnez  $at, .L7F0DD760
   lui   $t4, %hi(ptr_spectrum_roms) 
  lw    $t4, %lo(ptr_spectrum_roms)($t4)
  lhu   $t7, 0x298($sp)
  li    $t2, 1
  addu  $t8, $t4, $t6
  sb    $t7, ($t8)
  lhu   $t9, 0x292($sp)
  lui   $t4, %hi(ptr_300alloc) 
  lw    $t4, %lo(ptr_300alloc)($t4)
  andi  $t1, $t9, 0x1800
  sra   $t0, $t1, 3
  andi  $t5, $t9, 0xff
  or    $t3, $t0, $t5
  addu  $t6, $t4, $t3
  sb    $t2, ($t6)
.L7F0DD760:
  lhu   $t7, 0x292($sp)
  lhu   $t4, 0x292($sp)
  lhu   $t1, 0x298($sp)
  addiu $t8, $t7, 1
  slti  $at, $t8, 0x5b00
  bnez  $at, .L7F0DD794
   addiu $t3, $t4, 1
  lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  sra   $t9, $t1, 8
  addu  $t5, $t0, $t7
  b     .L7F0DD824
   sb    $t9, 1($t5)
.L7F0DD794:
  slti  $at, $t3, 0x5800
  bnez  $at, .L7F0DD7D4
   lhu   $t3, 0x292($sp)
  lui   $t8, %hi(ptr_spectrum_roms) 
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  lhu   $t2, 0x298($sp)
  lui   $t7, %hi(ptr_300alloc) 
  addu  $t1, $t8, $t4
  sra   $t6, $t2, 8
  sb    $t6, 1($t1)
  lhu   $t9, 0x292($sp)
  lw    $t7, %lo(ptr_300alloc)($t7)
  li    $t0, 1
  addu  $t5, $t7, $t9
  b     .L7F0DD824
   sb    $t0, -0x57ff($t5)
.L7F0DD7D4:
  addiu $t2, $t3, 1
  slti  $at, $t2, 0x4000
  bnez  $at, .L7F0DD824
   lhu   $t8, 0x298($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  sra   $t4, $t8, 8
  li    $t7, 1
  addu  $t1, $t6, $t3
  sb    $t4, 1($t1)
  lhu   $t9, 0x292($sp)
  lui   $t3, %hi(ptr_300alloc) 
  lw    $t3, %lo(ptr_300alloc)($t3)
  addiu $t0, $t9, 1
  andi  $t5, $t0, 0x1800
  sra   $t2, $t5, 3
  andi  $t8, $t0, 0xff
  or    $t6, $t2, $t8
  addu  $t4, $t3, $t6
  sb    $t7, ($t4)
.L7F0DD824:
  li    $t1, 24
  b     .L7F0E27FC
   sh    $t1, 0x298($sp)
spectrum_op_E0:
  lw    $t9, 0x28c($sp)
  andi  $t0, $s1, 4
  lui   $t6, %hi(ptr_spectrum_roms) 
  addiu $t5, $t9, 5
  bnez  $t0, .L7F0E27FC
   sw    $t5, 0x28c($sp)
  lhu   $t3, 0x292($sp)
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  addiu $t8, $t5, 6
  sw    $t8, 0x28c($sp)
  addu  $t1, $t6, $t3
  lbu   $t9, 1($t1)
  addu  $t7, $t3, $t6
  lbu   $t4, ($t7)
  sll   $t5, $t9, 8
  addiu $t2, $t3, 2
  or    $t0, $t4, $t5
  sh    $t0, 0x298($sp)
  b     .L7F0E27FC
   sh    $t2, 0x292($sp)
spectrum_op_E1:
  lw    $t8, 0x28c($sp)
  lbu   $t6, 0x287($sp)
  lbu   $t0, 0x287($sp)
  addiu $t7, $t8, 0xa
  bnez  $t6, .L7F0DD8BC
   sw    $t7, 0x28c($sp)
  lui   $t9, %hi(ptr_spectrum_roms) 
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  lhu   $t1, 0x292($sp)
  addu  $t4, $t1, $t9
  lbu   $s7, ($t4)
  lbu   $s6, 1($t4)
  addiu $t5, $t1, 2
  b     .L7F0E27FC
   sh    $t5, 0x292($sp)
.L7F0DD8BC:
  li    $at, 1
  bne   $t0, $at, .L7F0DD8FC
   lui   $t8, %hi(ptr_spectrum_roms)
  lui   $t2, %hi(ptr_spectrum_roms) 
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  lhu   $t3, 0x292($sp)
  addu  $t6, $t2, $t3
  lbu   $t9, 1($t6)
  addu  $t8, $t3, $t2
  lbu   $t7, ($t8)
  sll   $t4, $t9, 8
  addiu $t5, $t3, 2
  or    $t1, $t7, $t4
  sh    $t1, 0x296($sp)
  b     .L7F0E27FC
   sh    $t5, 0x292($sp)
.L7F0DD8FC:
  lhu   $t0, 0x292($sp)
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  addiu $t3, $t0, 2
  addu  $t9, $t8, $t0
  lbu   $t7, 1($t9)
  addu  $t2, $t0, $t8
  lbu   $t6, ($t2)
  sll   $t4, $t7, 8
  sh    $t3, 0x292($sp)
  or    $t1, $t6, $t4
  b     .L7F0E27FC
   sh    $t1, 0x294($sp)
spectrum_op_E2:
  lw    $t5, 0x28c($sp)
  andi  $t8, $s1, 4
  lhu   $t9, 0x298($sp)
  addiu $t2, $t5, 0xa
  bnez  $t8, .L7F0DD96C
   sw    $t2, 0x28c($sp)
  lui   $t7, %hi(ptr_spectrum_roms) 
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  addu  $t1, $t7, $t9
  lbu   $t0, 1($t1)
  addu  $t6, $t9, $t7
  lbu   $t4, ($t6)
  sll   $t3, $t0, 8
  or    $t5, $t4, $t3
  b     .L7F0E27FC
   sh    $t5, 0x298($sp)
.L7F0DD96C:
  lhu   $t2, 0x298($sp)
  addiu $t8, $t2, 2
  b     .L7F0E27FC
   sh    $t8, 0x298($sp)
spectrum_op_E3:
  lw    $t6, 0x28c($sp)
  lbu   $t9, 0x287($sp)
  lbu   $t4, 0x287($sp)
  addiu $t7, $t6, 0x13
  bnez  $t9, .L7F0DDB1C
   sw    $t7, 0x28c($sp)
  lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  lhu   $t1, 0x292($sp)
  lhu   $t7, 0x292($sp)
  lui   $t9, %hi(ptr_spectrum_roms) 
  addu  $t5, $t0, $t1
  lbu   $t2, 1($t5)
  addu  $t4, $t1, $t0
  lbu   $t3, ($t4)
  sll   $t8, $t2, 8
  slti  $at, $t7, 0x5b00
  or    $t6, $t3, $t8
  bnez  $at, .L7F0DD9DC
   sh    $t6, 0xea($sp)
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  addu  $t4, $t9, $t7
  b     .L7F0DDA5C
   sb    $s7, ($t4)
.L7F0DD9DC:
  lhu   $t0, 0x292($sp)
  lhu   $t9, 0x292($sp)
  lui   $t1, %hi(ptr_spectrum_roms) 
  slti  $at, $t0, 0x5800
  bnezl $at, .L7F0DDA20
   slti  $at, $t9, 0x4000
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  lui   $t3, %hi(ptr_300alloc) 
  li    $t2, 1
  addu  $t5, $t1, $t0
  sb    $s7, ($t5)
  lhu   $t8, 0x292($sp)
  lw    $t3, %lo(ptr_300alloc)($t3)
  addu  $t6, $t3, $t8
  b     .L7F0DDA5C
   sb    $t2, -0x5800($t6)
  slti  $at, $t9, 0x4000
.L7F0DDA20:
  bnez  $at, .L7F0DDA5C
   lui   $t7, %hi(ptr_spectrum_roms) 
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  lui   $t6, %hi(ptr_300alloc) 
  li    $t1, 1
  addu  $t4, $t7, $t9
  sb    $s7, ($t4)
  lhu   $t0, 0x292($sp)
  lw    $t6, %lo(ptr_300alloc)($t6)
  andi  $t5, $t0, 0x1800
  sra   $t3, $t5, 3
  andi  $t8, $t0, 0xff
  or    $t2, $t3, $t8
  addu  $t7, $t6, $t2
  sb    $t1, ($t7)
.L7F0DDA5C:
  lhu   $t9, 0x292($sp)
  lhu   $t3, 0x292($sp)
  lui   $t5, %hi(ptr_spectrum_roms) 
  addiu $t4, $t9, 1
  slti  $at, $t4, 0x5b00
  bnez  $at, .L7F0DDA88
   addiu $t8, $t3, 1
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  addu  $t0, $t5, $t9
  b     .L7F0DDB08
   sb    $s6, 1($t0)
.L7F0DDA88:
  slti  $at, $t8, 0x5800
  bnez  $at, .L7F0DDAC0
   lhu   $t9, 0x292($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  lui   $t7, %hi(ptr_300alloc) 
  li    $t1, 1
  addu  $t2, $t6, $t3
  sb    $s6, 1($t2)
  lhu   $t4, 0x292($sp)
  lw    $t7, %lo(ptr_300alloc)($t7)
  addu  $t5, $t7, $t4
  b     .L7F0DDB08
   sb    $t1, -0x57ff($t5)
.L7F0DDAC0:
  addiu $t0, $t9, 1
  slti  $at, $t0, 0x4000
  bnez  $at, .L7F0DDB08
   lui   $t8, %hi(ptr_spectrum_roms) 
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  li    $t3, 1
  addu  $t6, $t8, $t9
  sb    $s6, 1($t6)
  lhu   $t2, 0x292($sp)
  lui   $t8, %hi(ptr_300alloc) 
  lw    $t8, %lo(ptr_300alloc)($t8)
  addiu $t7, $t2, 1
  andi  $t4, $t7, 0x1800
  sra   $t1, $t4, 3
  andi  $t5, $t7, 0xff
  or    $t0, $t1, $t5
  addu  $t9, $t8, $t0
  sb    $t3, ($t9)
.L7F0DDB08:
  lhu   $s6, 0xea($sp)
  lbu   $s7, 0xeb($sp)
  sra   $t6, $s6, 8
  b     .L7F0E27FC
   andi  $s6, $t6, 0xff
.L7F0DDB1C:
  li    $at, 1
  bne   $t4, $at, .L7F0DDCCC
   lhu   $t8, 0x292($sp)
  lui   $t1, %hi(ptr_spectrum_roms) 
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  lhu   $t7, 0x292($sp)
  lhu   $t2, 0x292($sp)
  addu  $t0, $t1, $t7
  lbu   $t3, 1($t0)
  addu  $t5, $t7, $t1
  lbu   $t8, ($t5)
  sll   $t9, $t3, 8
  slti  $at, $t2, 0x5b00
  or    $t6, $t8, $t9
  bnez  $at, .L7F0DDB74
   sh    $t6, 0xe8($sp)
  lui   $t5, %hi(ptr_spectrum_roms) 
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  lhu   $t4, 0x296($sp)
  addu  $t1, $t5, $t2
  b     .L7F0DDBFC
   sb    $t4, ($t1)
.L7F0DDB74:
  lhu   $t7, 0x292($sp)
  lhu   $t4, 0x292($sp)
  lui   $t3, %hi(ptr_spectrum_roms) 
  slti  $at, $t7, 0x5800
  bnezl $at, .L7F0DDBBC
   slti  $at, $t4, 0x4000
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  lhu   $t0, 0x296($sp)
  lui   $t6, %hi(ptr_300alloc) 
  addu  $t8, $t3, $t7
  sb    $t0, ($t8)
  lhu   $t5, 0x292($sp)
  lw    $t6, %lo(ptr_300alloc)($t6)
  li    $t9, 1
  addu  $t2, $t6, $t5
  b     .L7F0DDBFC
   sb    $t9, -0x5800($t2)
  slti  $at, $t4, 0x4000
.L7F0DDBBC:
  bnez  $at, .L7F0DDBFC
   lui   $t3, %hi(ptr_spectrum_roms) 
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  lhu   $t1, 0x296($sp)
  li    $t0, 1
  addu  $t7, $t3, $t4
  sb    $t1, ($t7)
  lhu   $t8, 0x292($sp)
  lui   $t3, %hi(ptr_300alloc) 
  lw    $t3, %lo(ptr_300alloc)($t3)
  andi  $t6, $t8, 0x1800
  sra   $t5, $t6, 3
  andi  $t9, $t8, 0xff
  or    $t2, $t5, $t9
  addu  $t4, $t3, $t2
  sb    $t0, ($t4)
.L7F0DDBFC:
  lhu   $t1, 0x292($sp)
  lhu   $t3, 0x292($sp)
  lhu   $t6, 0x296($sp)
  addiu $t7, $t1, 1
  slti  $at, $t7, 0x5b00
  bnez  $at, .L7F0DDC30
   addiu $t2, $t3, 1
  lui   $t5, %hi(ptr_spectrum_roms) 
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  sra   $t8, $t6, 8
  addu  $t9, $t5, $t1
  b     .L7F0DDCC0
   sb    $t8, 1($t9)
.L7F0DDC30:
  slti  $at, $t2, 0x5800
  bnez  $at, .L7F0DDC70
   lhu   $t2, 0x292($sp)
  lui   $t7, %hi(ptr_spectrum_roms) 
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  lhu   $t0, 0x296($sp)
  lui   $t1, %hi(ptr_300alloc) 
  addu  $t6, $t7, $t3
  sra   $t4, $t0, 8
  sb    $t4, 1($t6)
  lhu   $t8, 0x292($sp)
  lw    $t1, %lo(ptr_300alloc)($t1)
  li    $t5, 1
  addu  $t9, $t1, $t8
  b     .L7F0DDCC0
   sb    $t5, -0x57ff($t9)
.L7F0DDC70:
  addiu $t0, $t2, 1
  slti  $at, $t0, 0x4000
  bnez  $at, .L7F0DDCC0
   lhu   $t7, 0x296($sp)
  lui   $t4, %hi(ptr_spectrum_roms) 
  lw    $t4, %lo(ptr_spectrum_roms)($t4)
  sra   $t3, $t7, 8
  li    $t1, 1
  addu  $t6, $t4, $t2
  sb    $t3, 1($t6)
  lhu   $t8, 0x292($sp)
  lui   $t2, %hi(ptr_300alloc) 
  lw    $t2, %lo(ptr_300alloc)($t2)
  addiu $t5, $t8, 1
  andi  $t9, $t5, 0x1800
  sra   $t0, $t9, 3
  andi  $t7, $t5, 0xff
  or    $t4, $t0, $t7
  addu  $t3, $t2, $t4
  sb    $t1, ($t3)
.L7F0DDCC0:
  lhu   $t6, 0xe8($sp)
  b     .L7F0E27FC
   sh    $t6, 0x296($sp)
.L7F0DDCCC:
  lui   $t9, %hi(ptr_spectrum_roms) 
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  lhu   $t3, 0x292($sp)
  addu  $t7, $t9, $t8
  lbu   $t2, 1($t7)
  addu  $t5, $t8, $t9
  lbu   $t0, ($t5)
  sll   $t4, $t2, 8
  slti  $at, $t3, 0x5b00
  or    $t1, $t0, $t4
  bnez  $at, .L7F0DDD14
   sh    $t1, 0xe6($sp)
  lui   $t5, %hi(ptr_spectrum_roms) 
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  lhu   $t6, 0x294($sp)
  addu  $t9, $t5, $t3
  b     .L7F0DDD9C
   sb    $t6, ($t9)
.L7F0DDD14:
  lhu   $t8, 0x292($sp)
  lhu   $t6, 0x292($sp)
  lui   $t2, %hi(ptr_spectrum_roms) 
  slti  $at, $t8, 0x5800
  bnezl $at, .L7F0DDD5C
   slti  $at, $t6, 0x4000
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  lhu   $t7, 0x294($sp)
  lui   $t1, %hi(ptr_300alloc) 
  addu  $t0, $t2, $t8
  sb    $t7, ($t0)
  lhu   $t5, 0x292($sp)
  lw    $t1, %lo(ptr_300alloc)($t1)
  li    $t4, 1
  addu  $t3, $t1, $t5
  b     .L7F0DDD9C
   sb    $t4, -0x5800($t3)
  slti  $at, $t6, 0x4000
.L7F0DDD5C:
  bnez  $at, .L7F0DDD9C
   lui   $t2, %hi(ptr_spectrum_roms) 
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  lhu   $t9, 0x294($sp)
  li    $t7, 1
  addu  $t8, $t2, $t6
  sb    $t9, ($t8)
  lhu   $t0, 0x292($sp)
  lui   $t2, %hi(ptr_300alloc) 
  lw    $t2, %lo(ptr_300alloc)($t2)
  andi  $t1, $t0, 0x1800
  sra   $t5, $t1, 3
  andi  $t4, $t0, 0xff
  or    $t3, $t5, $t4
  addu  $t6, $t2, $t3
  sb    $t7, ($t6)
.L7F0DDD9C:
  lhu   $t9, 0x292($sp)
  lhu   $t2, 0x292($sp)
  lhu   $t1, 0x294($sp)
  addiu $t8, $t9, 1
  slti  $at, $t8, 0x5b00
  bnez  $at, .L7F0DDDD0
   addiu $t3, $t2, 1
  lui   $t5, %hi(ptr_spectrum_roms) 
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  sra   $t0, $t1, 8
  addu  $t4, $t5, $t9
  b     .L7F0DDE60
   sb    $t0, 1($t4)
.L7F0DDDD0:
  slti  $at, $t3, 0x5800
  bnez  $at, .L7F0DDE10
   lhu   $t3, 0x292($sp)
  lui   $t8, %hi(ptr_spectrum_roms) 
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  lhu   $t7, 0x294($sp)
  lui   $t9, %hi(ptr_300alloc) 
  addu  $t1, $t8, $t2
  sra   $t6, $t7, 8
  sb    $t6, 1($t1)
  lhu   $t0, 0x292($sp)
  lw    $t9, %lo(ptr_300alloc)($t9)
  li    $t5, 1
  addu  $t4, $t9, $t0
  b     .L7F0DDE60
   sb    $t5, -0x57ff($t4)
.L7F0DDE10:
  addiu $t7, $t3, 1
  slti  $at, $t7, 0x4000
  bnez  $at, .L7F0DDE60
   lhu   $t8, 0x294($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  sra   $t2, $t8, 8
  li    $t9, 1
  addu  $t1, $t6, $t3
  sb    $t2, 1($t1)
  lhu   $t0, 0x292($sp)
  lui   $t3, %hi(ptr_300alloc) 
  lw    $t3, %lo(ptr_300alloc)($t3)
  addiu $t5, $t0, 1
  andi  $t4, $t5, 0x1800
  sra   $t7, $t4, 3
  andi  $t8, $t5, 0xff
  or    $t6, $t7, $t8
  addu  $t2, $t3, $t6
  sb    $t9, ($t2)
.L7F0DDE60:
  lhu   $t1, 0xe6($sp)
  b     .L7F0E27FC
   sh    $t1, 0x294($sp)
spectrum_op_E4:
  lw    $t0, 0x28c($sp)
  andi  $t5, $s1, 4
  addiu $t4, $t0, 0xa
  bnez  $t5, .L7F0DE044
   sw    $t4, 0x28c($sp)
  lhu   $t3, 0x292($sp)
  addiu $t8, $t4, 7
  sw    $t8, 0x28c($sp)
  addiu $t6, $t3, -2
  andi  $t9, $t6, 0xffff
  slti  $at, $t9, 0x5b00
  bnez  $at, .L7F0DDEBC
   sh    $t6, 0x292($sp)
  lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  lhu   $t2, 0x298($sp)
  addu  $t4, $t0, $t9
  addiu $t1, $t2, 2
  b     .L7F0DDF48
   sb    $t1, ($t4)
.L7F0DDEBC:
  lhu   $t5, 0x292($sp)
  lhu   $t4, 0x292($sp)
  lhu   $t7, 0x298($sp)
  slti  $at, $t5, 0x5800
  bnez  $at, .L7F0DDF00
   lui   $t3, %hi(ptr_spectrum_roms) 
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  addiu $t8, $t7, 2
  lui   $t0, %hi(ptr_300alloc) 
  addu  $t6, $t3, $t5
  sb    $t8, ($t6)
  lhu   $t9, 0x292($sp)
  lw    $t0, %lo(ptr_300alloc)($t0)
  li    $t2, 1
  addu  $t1, $t0, $t9
  b     .L7F0DDF48
   sb    $t2, -0x5800($t1)
.L7F0DDF00:
  slti  $at, $t4, 0x4000
  bnez  $at, .L7F0DDF48
   lhu   $t7, 0x298($sp)
  lui   $t5, %hi(ptr_spectrum_roms) 
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  addiu $t3, $t7, 2
  li    $t6, 1
  addu  $t8, $t5, $t4
  sb    $t3, ($t8)
  lhu   $t0, 0x292($sp)
  lui   $t5, %hi(ptr_300alloc) 
  lw    $t5, %lo(ptr_300alloc)($t5)
  andi  $t9, $t0, 0x1800
  sra   $t2, $t9, 3
  andi  $t1, $t0, 0xff
  or    $t7, $t2, $t1
  addu  $t4, $t5, $t7
  sb    $t6, ($t4)
.L7F0DDF48:
  lhu   $t3, 0x292($sp)
  lhu   $t7, 0x292($sp)
  lhu   $t9, 0x298($sp)
  addiu $t8, $t3, 1
  slti  $at, $t8, 0x5b00
  bnez  $at, .L7F0DDF80
   addiu $t6, $t7, 1
  lui   $t1, %hi(ptr_spectrum_roms) 
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  addiu $t0, $t9, 2
  sra   $t2, $t0, 8
  addu  $t5, $t1, $t3
  b     .L7F0DE018
   sb    $t2, 1($t5)
.L7F0DDF80:
  slti  $at, $t6, 0x5800
  bnez  $at, .L7F0DDFC4
   lhu   $t4, 0x292($sp)
  lhu   $t4, 0x298($sp)
  lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  addiu $t8, $t4, 2
  sra   $t9, $t8, 8
  addu  $t1, $t0, $t7
  sb    $t9, 1($t1)
  lui   $t2, %hi(ptr_300alloc) 
  lw    $t2, %lo(ptr_300alloc)($t2)
  lhu   $t5, 0x292($sp)
  li    $t3, 1
  addu  $t6, $t2, $t5
  b     .L7F0DE018
   sb    $t3, -0x57ff($t6)
.L7F0DDFC4:
  addiu $t8, $t4, 1
  slti  $at, $t8, 0x4000
  bnez  $at, .L7F0DE018
   lhu   $t0, 0x298($sp)
  lui   $t1, %hi(ptr_spectrum_roms) 
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  addiu $t7, $t0, 2
  sra   $t9, $t7, 8
  addu  $t2, $t1, $t4
  sb    $t9, 1($t2)
  lhu   $t3, 0x292($sp)
  lui   $t4, %hi(ptr_300alloc) 
  lw    $t4, %lo(ptr_300alloc)($t4)
  addiu $t6, $t3, 1
  andi  $t8, $t6, 0x1800
  sra   $t0, $t8, 3
  andi  $t7, $t6, 0xff
  or    $t1, $t0, $t7
  li    $t5, 1
  addu  $t9, $t4, $t1
  sb    $t5, ($t9)
.L7F0DE018:
  lui   $t3, %hi(ptr_spectrum_roms) 
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  lhu   $t2, 0x298($sp)
  addu  $t0, $t3, $t2
  lbu   $t7, 1($t0)
  addu  $t8, $t2, $t3
  lbu   $t6, ($t8)
  sll   $t4, $t7, 8
  or    $t1, $t6, $t4
  b     .L7F0E27FC
   sh    $t1, 0x298($sp)
.L7F0DE044:
  lhu   $t5, 0x298($sp)
  addiu $t9, $t5, 2
  b     .L7F0E27FC
   sh    $t9, 0x298($sp)
spectrum_op_E5:
  lw    $t8, 0x28c($sp)
  lbu   $t2, 0x287($sp)
  lbu   $t7, 0x287($sp)
  addiu $t3, $t8, 0xb
  bnez  $t2, .L7F0DE1C8
   sw    $t3, 0x28c($sp)
  lhu   $t0, 0x292($sp)
  lui   $t4, %hi(ptr_spectrum_roms) 
  addiu $t7, $t0, -2
  andi  $t6, $t7, 0xffff
  slti  $at, $t6, 0x5b00
  bnez  $at, .L7F0DE098
   sh    $t7, 0x292($sp)
  lw    $t4, %lo(ptr_spectrum_roms)($t4)
  addu  $t1, $t4, $t6
  b     .L7F0DE118
   sb    $s7, ($t1)
.L7F0DE098:
  lhu   $t5, 0x292($sp)
  lhu   $t4, 0x292($sp)
  lui   $t9, %hi(ptr_spectrum_roms) 
  slti  $at, $t5, 0x5800
  bnezl $at, .L7F0DE0DC
   slti  $at, $t4, 0x4000
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  lui   $t2, %hi(ptr_300alloc) 
  li    $t3, 1
  addu  $t8, $t9, $t5
  sb    $s7, ($t8)
  lhu   $t0, 0x292($sp)
  lw    $t2, %lo(ptr_300alloc)($t2)
  addu  $t7, $t2, $t0
  b     .L7F0DE118
   sb    $t3, -0x5800($t7)
  slti  $at, $t4, 0x4000
.L7F0DE0DC:
  bnez  $at, .L7F0DE118
   lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  lui   $t7, %hi(ptr_300alloc) 
  li    $t9, 1
  addu  $t1, $t6, $t4
  sb    $s7, ($t1)
  lhu   $t5, 0x292($sp)
  lw    $t7, %lo(ptr_300alloc)($t7)
  andi  $t8, $t5, 0x1800
  sra   $t2, $t8, 3
  andi  $t0, $t5, 0xff
  or    $t3, $t2, $t0
  addu  $t6, $t7, $t3
  sb    $t9, ($t6)
.L7F0DE118:
  lhu   $t4, 0x292($sp)
  lhu   $t2, 0x292($sp)
  lui   $t8, %hi(ptr_spectrum_roms) 
  addiu $t1, $t4, 1
  slti  $at, $t1, 0x5b00
  bnez  $at, .L7F0DE144
   addiu $t0, $t2, 1
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  addu  $t5, $t8, $t4
  b     .L7F0E27FC
   sb    $s6, 1($t5)
.L7F0DE144:
  slti  $at, $t0, 0x5800
  bnez  $at, .L7F0DE17C
   lhu   $t4, 0x292($sp)
  lui   $t7, %hi(ptr_spectrum_roms) 
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  lui   $t6, %hi(ptr_300alloc) 
  li    $t9, 1
  addu  $t3, $t7, $t2
  sb    $s6, 1($t3)
  lhu   $t1, 0x292($sp)
  lw    $t6, %lo(ptr_300alloc)($t6)
  addu  $t8, $t6, $t1
  b     .L7F0E27FC
   sb    $t9, -0x57ff($t8)
.L7F0DE17C:
  addiu $t5, $t4, 1
  slti  $at, $t5, 0x4000
  bnez  $at, .L7F0E27FC
   lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  li    $t2, 1
  addu  $t7, $t0, $t4
  sb    $s6, 1($t7)
  lhu   $t3, 0x292($sp)
  lui   $t0, %hi(ptr_300alloc) 
  lw    $t0, %lo(ptr_300alloc)($t0)
  addiu $t6, $t3, 1
  andi  $t1, $t6, 0x1800
  sra   $t9, $t1, 3
  andi  $t8, $t6, 0xff
  or    $t5, $t9, $t8
  addu  $t4, $t0, $t5
  b     .L7F0E27FC
   sb    $t2, ($t4)
.L7F0DE1C8:
  li    $at, 1
  bne   $t7, $at, .L7F0DE354
   lhu   $t1, 0x292($sp)
  lhu   $t3, 0x292($sp)
  lui   $t8, %hi(ptr_spectrum_roms) 
  addiu $t1, $t3, -2
  andi  $t6, $t1, 0xffff
  slti  $at, $t6, 0x5b00
  bnez  $at, .L7F0DE204
   sh    $t1, 0x292($sp)
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  lhu   $t9, 0x296($sp)
  addu  $t0, $t8, $t6
  b     .L7F0DE28C
   sb    $t9, ($t0)
.L7F0DE204:
  lhu   $t5, 0x292($sp)
  lhu   $t9, 0x292($sp)
  lui   $t4, %hi(ptr_spectrum_roms) 
  slti  $at, $t5, 0x5800
  bnezl $at, .L7F0DE24C
   slti  $at, $t9, 0x4000
  lw    $t4, %lo(ptr_spectrum_roms)($t4)
  lhu   $t2, 0x296($sp)
  lui   $t1, %hi(ptr_300alloc) 
  addu  $t7, $t4, $t5
  sb    $t2, ($t7)
  lhu   $t8, 0x292($sp)
  lw    $t1, %lo(ptr_300alloc)($t1)
  li    $t3, 1
  addu  $t6, $t1, $t8
  b     .L7F0DE28C
   sb    $t3, -0x5800($t6)
  slti  $at, $t9, 0x4000
.L7F0DE24C:
  bnez  $at, .L7F0DE28C
   lui   $t4, %hi(ptr_spectrum_roms) 
  lw    $t4, %lo(ptr_spectrum_roms)($t4)
  lhu   $t0, 0x296($sp)
  li    $t2, 1
  addu  $t5, $t4, $t9
  sb    $t0, ($t5)
  lhu   $t7, 0x292($sp)
  lui   $t4, %hi(ptr_300alloc) 
  lw    $t4, %lo(ptr_300alloc)($t4)
  andi  $t1, $t7, 0x1800
  sra   $t8, $t1, 3
  andi  $t3, $t7, 0xff
  or    $t6, $t8, $t3
  addu  $t9, $t4, $t6
  sb    $t2, ($t9)
.L7F0DE28C:
  lhu   $t0, 0x292($sp)
  lhu   $t4, 0x292($sp)
  lhu   $t1, 0x296($sp)
  addiu $t5, $t0, 1
  slti  $at, $t5, 0x5b00
  bnez  $at, .L7F0DE2C0
   addiu $t6, $t4, 1
  lui   $t8, %hi(ptr_spectrum_roms) 
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  sra   $t7, $t1, 8
  addu  $t3, $t8, $t0
  b     .L7F0E27FC
   sb    $t7, 1($t3)
.L7F0DE2C0:
  slti  $at, $t6, 0x5800
  bnez  $at, .L7F0DE300
   lhu   $t6, 0x292($sp)
  lui   $t5, %hi(ptr_spectrum_roms) 
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  lhu   $t2, 0x296($sp)
  lui   $t0, %hi(ptr_300alloc) 
  addu  $t1, $t5, $t4
  sra   $t9, $t2, 8
  sb    $t9, 1($t1)
  lhu   $t7, 0x292($sp)
  lw    $t0, %lo(ptr_300alloc)($t0)
  li    $t8, 1
  addu  $t3, $t0, $t7
  b     .L7F0E27FC
   sb    $t8, -0x57ff($t3)
.L7F0DE300:
  addiu $t2, $t6, 1
  slti  $at, $t2, 0x4000
  bnez  $at, .L7F0E27FC
   lhu   $t5, 0x296($sp)
  lui   $t9, %hi(ptr_spectrum_roms) 
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  sra   $t4, $t5, 8
  li    $t0, 1
  addu  $t1, $t9, $t6
  sb    $t4, 1($t1)
  lhu   $t7, 0x292($sp)
  lui   $t6, %hi(ptr_300alloc) 
  lw    $t6, %lo(ptr_300alloc)($t6)
  addiu $t8, $t7, 1
  andi  $t3, $t8, 0x1800
  sra   $t2, $t3, 3
  andi  $t5, $t8, 0xff
  or    $t9, $t2, $t5
  addu  $t4, $t6, $t9
  b     .L7F0E27FC
   sb    $t0, ($t4)
.L7F0DE354:
  addiu $t7, $t1, -2
  andi  $t3, $t7, 0xffff
  slti  $at, $t3, 0x5b00
  bnez  $at, .L7F0DE380
   sh    $t7, 0x292($sp)
  lui   $t2, %hi(ptr_spectrum_roms) 
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  lhu   $t8, 0x294($sp)
  addu  $t5, $t2, $t3
  b     .L7F0DE408
   sb    $t8, ($t5)
.L7F0DE380:
  lhu   $t6, 0x292($sp)
  lhu   $t8, 0x292($sp)
  lui   $t0, %hi(ptr_spectrum_roms) 
  slti  $at, $t6, 0x5800
  bnezl $at, .L7F0DE3C8
   slti  $at, $t8, 0x4000
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  lhu   $t9, 0x294($sp)
  lui   $t7, %hi(ptr_300alloc) 
  addu  $t4, $t0, $t6
  sb    $t9, ($t4)
  lhu   $t2, 0x292($sp)
  lw    $t7, %lo(ptr_300alloc)($t7)
  li    $t1, 1
  addu  $t3, $t7, $t2
  b     .L7F0DE408
   sb    $t1, -0x5800($t3)
  slti  $at, $t8, 0x4000
.L7F0DE3C8:
  bnez  $at, .L7F0DE408
   lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  lhu   $t5, 0x294($sp)
  li    $t9, 1
  addu  $t6, $t0, $t8
  sb    $t5, ($t6)
  lhu   $t4, 0x292($sp)
  lui   $t0, %hi(ptr_300alloc) 
  lw    $t0, %lo(ptr_300alloc)($t0)
  andi  $t7, $t4, 0x1800
  sra   $t2, $t7, 3
  andi  $t1, $t4, 0xff
  or    $t3, $t2, $t1
  addu  $t8, $t0, $t3
  sb    $t9, ($t8)
.L7F0DE408:
  lhu   $t5, 0x292($sp)
  lhu   $t0, 0x292($sp)
  lhu   $t7, 0x294($sp)
  addiu $t6, $t5, 1
  slti  $at, $t6, 0x5b00
  bnez  $at, .L7F0DE43C
   addiu $t3, $t0, 1
  lui   $t2, %hi(ptr_spectrum_roms) 
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  sra   $t4, $t7, 8
  addu  $t1, $t2, $t5
  b     .L7F0E27FC
   sb    $t4, 1($t1)
.L7F0DE43C:
  slti  $at, $t3, 0x5800
  bnez  $at, .L7F0DE47C
   lhu   $t3, 0x292($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  lhu   $t9, 0x294($sp)
  lui   $t5, %hi(ptr_300alloc) 
  addu  $t7, $t6, $t0
  sra   $t8, $t9, 8
  sb    $t8, 1($t7)
  lhu   $t4, 0x292($sp)
  lw    $t5, %lo(ptr_300alloc)($t5)
  li    $t2, 1
  addu  $t1, $t5, $t4
  b     .L7F0E27FC
   sb    $t2, -0x57ff($t1)
.L7F0DE47C:
  addiu $t9, $t3, 1
  slti  $at, $t9, 0x4000
  bnez  $at, .L7F0E27FC
   lhu   $t6, 0x294($sp)
  lui   $t8, %hi(ptr_spectrum_roms) 
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  sra   $t0, $t6, 8
  li    $t5, 1
  addu  $t7, $t8, $t3
  sb    $t0, 1($t7)
  lhu   $t4, 0x292($sp)
  lui   $t3, %hi(ptr_300alloc) 
  lw    $t3, %lo(ptr_300alloc)($t3)
  addiu $t2, $t4, 1
  andi  $t1, $t2, 0x1800
  sra   $t9, $t1, 3
  andi  $t6, $t2, 0xff
  or    $t8, $t9, $t6
  addu  $t0, $t3, $t8
  b     .L7F0E27FC
   sb    $t5, ($t0)
spectrum_op_E6:
  lw    $t7, 0x28c($sp)
  lui   $t1, %hi(ptr_spectrum_roms) 
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  lhu   $t2, 0x298($sp)
  addiu $t4, $t7, 7
  sw    $t4, 0x28c($sp)
  addu  $t9, $t1, $t2
  lbu   $t6, ($t9)
  lui   $t2, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t2, %lo(ptr_pc_keyboard_table_alloc)($t2)
  and   $s0, $s0, $t6
  andi  $t3, $s0, 0xff
  sltiu $t8, $t3, 1
  sw    $t8, 0x48($sp)
  sll   $t7, $t8, 6
  addu  $t9, $t3, $t2
  lbu   $t6, ($t9)
  andi  $t5, $t3, 0xa8
  lhu   $t8, 0x298($sp)
  or    $t4, $t5, $t7
  ori   $t1, $t4, 0x10
  move  $s0, $t3
  or    $s1, $t6, $t1
  andi  $t3, $s1, 0xff
  addiu $t0, $t8, 1
  move  $s1, $t3
  b     .L7F0E27FC
   sh    $t0, 0x298($sp)
spectrum_op_E7:
  lhu   $t4, 0x292($sp)
  lw    $t5, 0x28c($sp)
  lui   $t1, %hi(ptr_spectrum_roms) 
  addiu $t2, $t4, -2
  andi  $t9, $t2, 0xffff
  slti  $at, $t9, 0x5b00
  addiu $t7, $t5, 0xb
  sw    $t7, 0x28c($sp)
  bnez  $at, .L7F0DE57C
   sh    $t2, 0x292($sp)
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  lhu   $t6, 0x298($sp)
  addu  $t3, $t1, $t9
  b     .L7F0DE604
   sb    $t6, ($t3)
.L7F0DE57C:
  lhu   $t8, 0x292($sp)
  lhu   $t6, 0x292($sp)
  lui   $t5, %hi(ptr_spectrum_roms) 
  slti  $at, $t8, 0x5800
  bnezl $at, .L7F0DE5C4
   slti  $at, $t6, 0x4000
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  lhu   $t0, 0x298($sp)
  lui   $t2, %hi(ptr_300alloc) 
  addu  $t7, $t5, $t8
  sb    $t0, ($t7)
  lhu   $t1, 0x292($sp)
  lw    $t2, %lo(ptr_300alloc)($t2)
  li    $t4, 1
  addu  $t9, $t2, $t1
  b     .L7F0DE604
   sb    $t4, -0x5800($t9)
  slti  $at, $t6, 0x4000
.L7F0DE5C4:
  bnez  $at, .L7F0DE604
   lui   $t5, %hi(ptr_spectrum_roms) 
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  lhu   $t3, 0x298($sp)
  li    $t0, 1
  addu  $t8, $t5, $t6
  sb    $t3, ($t8)
  lhu   $t7, 0x292($sp)
  lui   $t5, %hi(ptr_300alloc) 
  lw    $t5, %lo(ptr_300alloc)($t5)
  andi  $t2, $t7, 0x1800
  sra   $t1, $t2, 3
  andi  $t4, $t7, 0xff
  or    $t9, $t1, $t4
  addu  $t6, $t5, $t9
  sb    $t0, ($t6)
.L7F0DE604:
  lhu   $t3, 0x292($sp)
  lhu   $t5, 0x292($sp)
  lhu   $t2, 0x298($sp)
  addiu $t8, $t3, 1
  slti  $at, $t8, 0x5b00
  bnez  $at, .L7F0DE638
   addiu $t9, $t5, 1
  lui   $t1, %hi(ptr_spectrum_roms) 
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  sra   $t7, $t2, 8
  addu  $t4, $t1, $t3
  b     .L7F0DE6C8
   sb    $t7, 1($t4)
.L7F0DE638:
  slti  $at, $t9, 0x5800
  bnez  $at, .L7F0DE678
   lhu   $t9, 0x292($sp)
  lui   $t8, %hi(ptr_spectrum_roms) 
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  lhu   $t0, 0x298($sp)
  lui   $t3, %hi(ptr_300alloc) 
  addu  $t2, $t8, $t5
  sra   $t6, $t0, 8
  sb    $t6, 1($t2)
  lhu   $t7, 0x292($sp)
  lw    $t3, %lo(ptr_300alloc)($t3)
  li    $t1, 1
  addu  $t4, $t3, $t7
  b     .L7F0DE6C8
   sb    $t1, -0x57ff($t4)
.L7F0DE678:
  addiu $t0, $t9, 1
  slti  $at, $t0, 0x4000
  bnez  $at, .L7F0DE6C8
   lhu   $t8, 0x298($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  sra   $t5, $t8, 8
  li    $t3, 1
  addu  $t2, $t6, $t9
  sb    $t5, 1($t2)
  lhu   $t7, 0x292($sp)
  lui   $t9, %hi(ptr_300alloc) 
  lw    $t9, %lo(ptr_300alloc)($t9)
  addiu $t1, $t7, 1
  andi  $t4, $t1, 0x1800
  sra   $t0, $t4, 3
  andi  $t8, $t1, 0xff
  or    $t6, $t0, $t8
  addu  $t5, $t9, $t6
  sb    $t3, ($t5)
.L7F0DE6C8:
  li    $t2, 32
  b     .L7F0E27FC
   sh    $t2, 0x298($sp)
spectrum_op_E8:
  lw    $t7, 0x28c($sp)
  andi  $t1, $s1, 4
  lui   $t6, %hi(ptr_spectrum_roms) 
  addiu $t4, $t7, 5
  beqz  $t1, .L7F0E27FC
   sw    $t4, 0x28c($sp)
  lhu   $t9, 0x292($sp)
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  addiu $t8, $t4, 6
  sw    $t8, 0x28c($sp)
  addu  $t2, $t6, $t9
  lbu   $t7, 1($t2)
  addu  $t3, $t9, $t6
  lbu   $t5, ($t3)
  sll   $t4, $t7, 8
  addiu $t0, $t9, 2
  or    $t1, $t5, $t4
  sh    $t1, 0x298($sp)
  b     .L7F0E27FC
   sh    $t0, 0x292($sp)
spectrum_op_E9:
  lw    $t8, 0x28c($sp)
  lbu   $t6, 0x287($sp)
  lbu   $t5, 0x287($sp)
  addiu $t3, $t8, 4
  bnez  $t6, .L7F0DE74C
   sw    $t3, 0x28c($sp)
  sll   $t2, $s6, 8
  or    $t7, $t2, $s7
  b     .L7F0E27FC
   sh    $t7, 0x298($sp)
.L7F0DE74C:
  li    $at, 1
  bne   $t5, $at, .L7F0DE764
   lhu   $t1, 0x294($sp)
  lhu   $t4, 0x296($sp)
  b     .L7F0DE768
   sw    $t4, 0x48($sp)
.L7F0DE764:
  sw    $t1, 0x48($sp)
.L7F0DE768:
  lw    $t9, 0x48($sp)
  b     .L7F0E27FC
   sh    $t9, 0x298($sp)
spectrum_op_EA:
  lw    $t0, 0x28c($sp)
  andi  $t3, $s1, 4
  lhu   $t6, 0x298($sp)
  addiu $t8, $t0, 0xa
  beqz  $t3, .L7F0DE7B4
   sw    $t8, 0x28c($sp)
  lui   $t2, %hi(ptr_spectrum_roms) 
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  addu  $t4, $t2, $t6
  lbu   $t1, 1($t4)
  addu  $t7, $t6, $t2
  lbu   $t5, ($t7)
  sll   $t9, $t1, 8
  or    $t0, $t5, $t9
  b     .L7F0E27FC
   sh    $t0, 0x298($sp)
.L7F0DE7B4:
  lhu   $t8, 0x298($sp)
  addiu $t3, $t8, 2
  b     .L7F0E27FC
   sh    $t3, 0x298($sp)
spectrum_op_EB:
  lw    $t7, 0x28c($sp)
  sb    $s6, 0xe5($sp)
  sb    $s5, 0xe4($sp)
  andi  $s6, $s4, 0xff
  andi  $s5, $s7, 0xff
  addiu $t2, $t7, 4
  sw    $t2, 0x28c($sp)
  lbu   $s4, 0xe5($sp)
  b     .L7F0E27FC
   lbu   $s7, 0xe4($sp)
spectrum_op_EC:
  lw    $t6, 0x28c($sp)
  andi  $t1, $s1, 4
  addiu $t4, $t6, 0xa
  beqz  $t1, .L7F0DE9C4
   sw    $t4, 0x28c($sp)
  lhu   $t0, 0x292($sp)
  addiu $t9, $t4, 7
  sw    $t9, 0x28c($sp)
  addiu $t8, $t0, -2
  andi  $t3, $t8, 0xffff
  slti  $at, $t3, 0x5b00
  bnez  $at, .L7F0DE83C
   sh    $t8, 0x292($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  lhu   $t7, 0x298($sp)
  addu  $t4, $t6, $t3
  addiu $t2, $t7, 2
  b     .L7F0DE8C8
   sb    $t2, ($t4)
.L7F0DE83C:
  lhu   $t1, 0x292($sp)
  lhu   $t4, 0x292($sp)
  lhu   $t5, 0x298($sp)
  slti  $at, $t1, 0x5800
  bnez  $at, .L7F0DE880
   lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  addiu $t9, $t5, 2
  lui   $t6, %hi(ptr_300alloc) 
  addu  $t8, $t0, $t1
  sb    $t9, ($t8)
  lhu   $t3, 0x292($sp)
  lw    $t6, %lo(ptr_300alloc)($t6)
  li    $t7, 1
  addu  $t2, $t6, $t3
  b     .L7F0DE8C8
   sb    $t7, -0x5800($t2)
.L7F0DE880:
  slti  $at, $t4, 0x4000
  bnez  $at, .L7F0DE8C8
   lhu   $t5, 0x298($sp)
  lui   $t1, %hi(ptr_spectrum_roms) 
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  addiu $t0, $t5, 2
  li    $t8, 1
  addu  $t9, $t1, $t4
  sb    $t0, ($t9)
  lhu   $t6, 0x292($sp)
  lui   $t1, %hi(ptr_300alloc) 
  lw    $t1, %lo(ptr_300alloc)($t1)
  andi  $t3, $t6, 0x1800
  sra   $t7, $t3, 3
  andi  $t2, $t6, 0xff
  or    $t5, $t7, $t2
  addu  $t4, $t1, $t5
  sb    $t8, ($t4)
.L7F0DE8C8:
  lhu   $t0, 0x292($sp)
  lhu   $t5, 0x292($sp)
  lhu   $t3, 0x298($sp)
  addiu $t9, $t0, 1
  slti  $at, $t9, 0x5b00
  bnez  $at, .L7F0DE900
   addiu $t8, $t5, 1
  lui   $t2, %hi(ptr_spectrum_roms) 
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  addiu $t6, $t3, 2
  sra   $t7, $t6, 8
  addu  $t1, $t2, $t0
  b     .L7F0DE998
   sb    $t7, 1($t1)
.L7F0DE900:
  slti  $at, $t8, 0x5800
  bnez  $at, .L7F0DE944
   lhu   $t4, 0x292($sp)
  lhu   $t4, 0x298($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  addiu $t9, $t4, 2
  sra   $t3, $t9, 8
  addu  $t2, $t6, $t5
  sb    $t3, 1($t2)
  lui   $t7, %hi(ptr_300alloc) 
  lw    $t7, %lo(ptr_300alloc)($t7)
  lhu   $t1, 0x292($sp)
  li    $t0, 1
  addu  $t8, $t7, $t1
  b     .L7F0DE998
   sb    $t0, -0x57ff($t8)
.L7F0DE944:
  addiu $t9, $t4, 1
  slti  $at, $t9, 0x4000
  bnez  $at, .L7F0DE998
   lhu   $t6, 0x298($sp)
  lui   $t2, %hi(ptr_spectrum_roms) 
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  addiu $t5, $t6, 2
  sra   $t3, $t5, 8
  addu  $t7, $t2, $t4
  sb    $t3, 1($t7)
  lhu   $t0, 0x292($sp)
  lui   $t4, %hi(ptr_300alloc) 
  lw    $t4, %lo(ptr_300alloc)($t4)
  addiu $t8, $t0, 1
  andi  $t9, $t8, 0x1800
  sra   $t6, $t9, 3
  andi  $t5, $t8, 0xff
  or    $t2, $t6, $t5
  li    $t1, 1
  addu  $t3, $t4, $t2
  sb    $t1, ($t3)
.L7F0DE998:
  lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  lhu   $t7, 0x298($sp)
  addu  $t6, $t0, $t7
  lbu   $t5, 1($t6)
  addu  $t9, $t7, $t0
  lbu   $t8, ($t9)
  sll   $t4, $t5, 8
  or    $t2, $t8, $t4
  b     .L7F0E27FC
   sh    $t2, 0x298($sp)
.L7F0DE9C4:
  lhu   $t1, 0x298($sp)
  addiu $t3, $t1, 2
  b     .L7F0E27FC
   sh    $t3, 0x298($sp)
spectrum_op_ED:
  lw    $t9, 0x28c($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  lhu   $t7, 0x298($sp)
  addiu $t0, $t9, 4
  sw    $t0, 0x28c($sp)
  addu  $t5, $t7, $t6
  lbu   $t8, ($t5)
  lw    $t2, 0x288($sp)
  addiu $t4, $t7, 1
  andi  $t3, $t8, 0xff
  slti  $at, $t3, 0x7f
  addiu $t1, $t2, 1
  sh    $t4, 0x298($sp)
  sw    $t1, 0x288($sp)
  sw    $t3, 0x48($sp)
  bnez  $at, .L7F0DEA40
   sb    $t8, 0xe3($sp)
  addiu $t9, $t3, -0xa0
  sltiu $at, $t9, 0x1c
  beqz  $at, .L7F0E1A6C
   sll   $t9, $t9, 2
  lui   $at, %hi(jpt_8005C6AC)
  addu  $at, $at, $t9
  lw    $t9, %lo(jpt_8005C6AC)($at)
  jr    $t9
   nop   
.L7F0DEA40:
  lw    $t0, 0x48($sp)
  addiu $t6, $t0, -0x40
  sltiu $at, $t6, 0x3f
  beqz  $at, .L7F0E1A6C
   sll   $t6, $t6, 2
  lui   $at, %hi(jpt_8005C71C)
  addu  $at, $at, $t6
  lw    $t6, %lo(jpt_8005C71C)($at)
  jr    $t6
   nop   
spectrum_op_ED_40:
  lw    $t5, 0x28c($sp)
  move  $a1, $s2
  move  $a2, $s3
  addiu $a0, $t5, 8
  jal   spectrum_input_handling
   sw    $a0, 0x28c($sp)
  lw    $t7, 0x28c($sp)
  andi  $t4, $v0, 0xffff
  sra   $t2, $t4, 8
  sh    $v0, 0xe0($sp)
  addu  $t1, $t7, $t2
  lbu   $s2, 0xe1($sp)
  lui   $t7, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t7, %lo(ptr_pc_keyboard_table_alloc)($t7)
  sltiu $t3, $s2, 1
  sw    $t3, 0x48($sp)
  sw    $t1, 0x28c($sp)
  addu  $t2, $s2, $t7
  lbu   $t1, ($t2)
  andi  $t9, $s1, 1
  andi  $t0, $s2, 0xa8
  or    $t6, $t9, $t0
  sll   $t8, $t3, 6
  or    $t4, $t6, $t8
  or    $s1, $t1, $t4
  andi  $t3, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t3
spectrum_op_ED_41:
  lw    $t9, 0x28c($sp)
  move  $a1, $s2
  move  $a2, $s3
  addiu $a0, $t9, 8
  sw    $a0, 0x28c($sp)
  jal   sub_GAME_7F0D37DC
   move  $a3, $s2
  lw    $t5, 0x28c($sp)
  sw    $v0, 0x48($sp)
  addu  $t8, $t5, $v0
  b     .L7F0E27FC
   sw    $t8, 0x28c($sp)
spectrum_op_ED_42:
  sll   $t1, $s2, 8
  lw    $t7, 0x28c($sp)
  or    $t4, $t1, $s3
  sll   $t3, $s6, 8
  or    $t9, $t3, $s7
  andi  $t0, $t4, 0xffff
  subu  $t5, $t9, $t0
  andi  $t6, $s1, 1
  lui   $at, (0x0001FFFF >> 16) # lui $at, 1
  ori   $at, (0x0001FFFF & 0xFFFF) # ori $at, $at, 0xffff
  subu  $t8, $t5, $t6
  addiu $t2, $t7, 0xb
  and   $t7, $t8, $at
  srl   $t3, $t7, 8
  andi  $t9, $t3, 0xa8
  srl   $t0, $t7, 0x10
  sw    $t2, 0x28c($sp)
  or    $t5, $t9, $t0
  andi  $t2, $t7, 0xffff
  sltiu $t1, $t2, 1
  ori   $t6, $t5, 2
  sll   $t0, $s6, 8
  or    $t5, $t0, $s7
  andi  $t2, $t4, 0xfff
  andi  $t3, $s1, 1
  addu  $t9, $t2, $t3
  andi  $t8, $t5, 0xfff
  slt   $t2, $t8, $t9
  sll   $t3, $t2, 4
  or    $t0, $t6, $t3
  sll   $t5, $s6, 8
  or    $t8, $t5, $s7
  sll   $t2, $s6, 8
  or    $t6, $t2, $s7
  move  $t3, $t4
  xor   $t5, $t6, $t3
  xor   $t9, $t8, $t7
  and   $t8, $t5, $t9
  andi  $t2, $t8, 0x8000
  sh    $t4, 0xde($sp)
  srl   $t4, $t2, 0xd
  or    $t6, $t0, $t4
  sll   $t3, $t1, 6
  or    $s1, $t6, $t3
  srl   $s6, $t7, 8
  andi  $t8, $s6, 0xff
  ori   $t5, $s1, 2
  sw    $t7, 0xd8($sp)
  lbu   $s7, 0xdb($sp)
  andi  $s1, $t5, 0xff
  move  $s6, $t8
  b     .L7F0E27FC
   sw    $t1, 0x48($sp)
spectrum_op_ED_43:
  lw    $t2, 0x28c($sp)
  lui   $t1, %hi(ptr_spectrum_roms) 
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  lhu   $t4, 0x298($sp)
  addiu $t0, $t2, 0x10
  sw    $t0, 0x28c($sp)
  addu  $t5, $t1, $t4
  lbu   $t9, 1($t5)
  addu  $t6, $t4, $t1
  lbu   $t3, ($t6)
  sll   $t7, $t9, 8
  addiu $t2, $t4, 2
  or    $t8, $t3, $t7
  andi  $t0, $t8, 0xffff
  slti  $at, $t0, 0x5b00
  sh    $t8, 0xd6($sp)
  bnez  $at, .L7F0DEC38
   sh    $t2, 0x298($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  addu  $t1, $t6, $t0
  b     .L7F0DECB8
   sb    $s3, ($t1)
.L7F0DEC38:
  lhu   $t5, 0xd6($sp)
  lhu   $t6, 0xd6($sp)
  lui   $t9, %hi(ptr_spectrum_roms) 
  slti  $at, $t5, 0x5800
  bnezl $at, .L7F0DEC7C
   slti  $at, $t6, 0x4000
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  lui   $t8, %hi(ptr_300alloc) 
  li    $t7, 1
  addu  $t3, $t9, $t5
  sb    $s3, ($t3)
  lhu   $t4, 0xd6($sp)
  lw    $t8, %lo(ptr_300alloc)($t8)
  addu  $t2, $t8, $t4
  b     .L7F0DECB8
   sb    $t7, -0x5800($t2)
  slti  $at, $t6, 0x4000
.L7F0DEC7C:
  bnez  $at, .L7F0DECB8
   lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  lui   $t2, %hi(ptr_300alloc) 
  li    $t9, 1
  addu  $t1, $t0, $t6
  sb    $s3, ($t1)
  lhu   $t5, 0xd6($sp)
  lw    $t2, %lo(ptr_300alloc)($t2)
  andi  $t3, $t5, 0x1800
  sra   $t8, $t3, 3
  andi  $t4, $t5, 0xff
  or    $t7, $t8, $t4
  addu  $t0, $t2, $t7
  sb    $t9, ($t0)
.L7F0DECB8:
  lhu   $t6, 0xd6($sp)
  lhu   $t8, 0xd6($sp)
  lui   $t3, %hi(ptr_spectrum_roms) 
  addiu $t1, $t6, 1
  slti  $at, $t1, 0x5b00
  bnez  $at, .L7F0DECE4
   addiu $t4, $t8, 1
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  addu  $t5, $t3, $t6
  b     .L7F0E27FC
   sb    $s2, 1($t5)
.L7F0DECE4:
  slti  $at, $t4, 0x5800
  bnez  $at, .L7F0DED1C
   lhu   $t6, 0xd6($sp)
  lui   $t2, %hi(ptr_spectrum_roms) 
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  lui   $t0, %hi(ptr_300alloc) 
  li    $t9, 1
  addu  $t7, $t2, $t8
  sb    $s2, 1($t7)
  lhu   $t1, 0xd6($sp)
  lw    $t0, %lo(ptr_300alloc)($t0)
  addu  $t3, $t0, $t1
  b     .L7F0E27FC
   sb    $t9, -0x57ff($t3)
.L7F0DED1C:
  addiu $t5, $t6, 1
  slti  $at, $t5, 0x4000
  bnez  $at, .L7F0E27FC
   lui   $t4, %hi(ptr_spectrum_roms) 
  lw    $t4, %lo(ptr_spectrum_roms)($t4)
  li    $t8, 1
  addu  $t2, $t4, $t6
  sb    $s2, 1($t2)
  lhu   $t7, 0xd6($sp)
  lui   $t4, %hi(ptr_300alloc) 
  lw    $t4, %lo(ptr_300alloc)($t4)
  addiu $t0, $t7, 1
  andi  $t1, $t0, 0x1800
  sra   $t9, $t1, 3
  andi  $t3, $t0, 0xff
  or    $t5, $t9, $t3
  addu  $t6, $t4, $t5
  b     .L7F0E27FC
   sb    $t8, ($t6)
spectrum_op_ED_44:
  negu  $s0, $s0
  andi  $t1, $s0, 0xff
  lw    $t2, 0x28c($sp)
  sltiu $t0, $t1, 1
  andi  $t8, $t1, 0xf
  move  $s0, $t1
  andi  $t9, $t1, 0xa8
  addiu $t7, $t2, 4
  xori  $t1, $t1, 0x80
  slt   $t6, $zero, $t8
  sll   $t4, $t0, 6
  sw    $t7, 0x28c($sp)
  or    $t5, $t9, $t4
  sll   $t2, $t6, 4
  sltiu $t1, $t1, 1
  sw    $t0, 0x48($sp)
  sll   $t0, $t1, 2
  or    $t7, $t5, $t2
  or    $t3, $t7, $t0
  ori   $t9, $t3, 2
  slt   $t4, $zero, $s0
  or    $s1, $t9, $t4
  andi  $t8, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t8
spectrum_op_ED_45:
  lw    $t6, 0x28c($sp)
  lui   $t3, %hi(ptr_spectrum_roms) 
  lbu   $t2, 0x29c($sp)
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  lhu   $t0, 0x292($sp)
  addiu $t5, $t6, 4
  sw    $t5, 0x28c($sp)
  addiu $t7, $t5, 6
  sw    $t7, 0x28c($sp)
  sb    $t2, 0x29d($sp)
  addu  $t8, $t3, $t0
  lbu   $t6, 1($t8)
  addu  $t9, $t0, $t3
  lbu   $t4, ($t9)
  sll   $t5, $t6, 8
  addiu $t1, $t0, 2
  or    $t2, $t4, $t5
  sh    $t2, 0x298($sp)
  b     .L7F0E27FC
   sh    $t1, 0x292($sp)
spectrum_op_ED_46:
  lw    $t7, 0x28c($sp)
  sb    $zero, 0x29b($sp)
  addiu $t9, $t7, 4
  b     .L7F0E27FC
   sw    $t9, 0x28c($sp)
spectrum_op_ED_47:
  lw    $t3, 0x28c($sp)
  sb    $s0, 0x29e($sp)
  addiu $t8, $t3, 5
  b     .L7F0E27FC
   sw    $t8, 0x28c($sp)
spectrum_op_ED_48:
  lw    $t6, 0x28c($sp)
  move  $a1, $s2
  move  $a2, $s3
  addiu $a0, $t6, 8
  jal   spectrum_input_handling
   sw    $a0, 0x28c($sp)
  lw    $t5, 0x28c($sp)
  andi  $t2, $v0, 0xffff
  sra   $t0, $t2, 8
  sh    $v0, 0xd4($sp)
  addu  $t1, $t5, $t0
  lbu   $s3, 0xd5($sp)
  lui   $t5, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t5, %lo(ptr_pc_keyboard_table_alloc)($t5)
  sltiu $t7, $s3, 1
  sw    $t7, 0x48($sp)
  sw    $t1, 0x28c($sp)
  addu  $t0, $s3, $t5
  lbu   $t1, ($t0)
  andi  $t9, $s1, 1
  andi  $t3, $s3, 0xa8
  or    $t8, $t9, $t3
  sll   $t4, $t7, 6
  or    $t2, $t8, $t4
  or    $s1, $t1, $t2
  andi  $t7, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t7
spectrum_op_ED_49:
  lw    $t9, 0x28c($sp)
  move  $a1, $s2
  move  $a2, $s3
  addiu $a0, $t9, 8
  sw    $a0, 0x28c($sp)
  jal   sub_GAME_7F0D37DC
   move  $a3, $s3
  lw    $t6, 0x28c($sp)
  sw    $v0, 0x48($sp)
  addu  $t4, $t6, $v0
  b     .L7F0E27FC
   sw    $t4, 0x28c($sp)
spectrum_op_ED_4A:
  sll   $t1, $s2, 8
  or    $t2, $t1, $s3
  sll   $t7, $s6, 8
  or    $t9, $t7, $s7
  andi  $t3, $t2, 0xffff
  lw    $t5, 0x28c($sp)
  addu  $t6, $t9, $t3
  andi  $t8, $s1, 1
  addu  $t4, $t6, $t8
  addiu $t0, $t5, 0xb
  srl   $t1, $t4, 8
  sw    $t0, 0x28c($sp)
  andi  $t7, $t1, 0xa8
  andi  $t5, $t4, 0xffff
  srl   $t9, $t4, 0x10
  sll   $t6, $s6, 8
  or    $t8, $t6, $s7
  or    $t3, $t7, $t9
  sltiu $t0, $t5, 1
  andi  $t5, $t8, 0xfff
  andi  $t7, $t2, 0xfff
  addu  $t9, $t5, $t7
  andi  $t6, $s1, 1
  addu  $t8, $t9, $t6
  li    $at, 4095
  slt   $t1, $at, $t8
  sll   $t5, $t1, 4
  or    $t7, $t3, $t5
  sll   $t9, $s6, 8
  or    $t6, $t9, $s7
  sll   $t1, $s6, 8
  nor   $t3, $t1, $s7
  move  $t5, $t2
  xor   $t9, $t3, $t5
  xor   $t8, $t6, $t4
  and   $t6, $t9, $t8
  andi  $t1, $t6, 0x8000
  sh    $t2, 0xd2($sp)
  srl   $t2, $t1, 0xd
  or    $t3, $t7, $t2
  sll   $t5, $t0, 6
  or    $s1, $t3, $t5
  srl   $s6, $t4, 8
  andi  $t6, $s6, 0xff
  ori   $t9, $s1, 2
  sw    $t4, 0xcc($sp)
  lbu   $s7, 0xcf($sp)
  andi  $s1, $t9, 0xff
  move  $s6, $t6
  b     .L7F0E27FC
   sw    $t0, 0x48($sp)
spectrum_op_ED_4B:
  lw    $t1, 0x28c($sp)
  lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  lhu   $t2, 0x298($sp)
  addiu $t7, $t1, 0x10
  sw    $t7, 0x28c($sp)
  addu  $t9, $t0, $t2
  lbu   $t8, 1($t9)
  addu  $t3, $t2, $t0
  lbu   $t5, ($t3)
  sll   $t4, $t8, 8
  addiu $t1, $t2, 2
  or    $t6, $t5, $t4
  andi  $t7, $t6, 0xffff
  sh    $t6, 0xca($sp)
  sh    $t1, 0x298($sp)
  addu  $t3, $t7, $t0
  lbu   $s3, ($t3)
  b     .L7F0E27FC
   lbu   $s2, 1($t3)
spectrum_op_ED_4C:
  negu  $s0, $s0
  andi  $t5, $s0, 0xff
  lw    $t9, 0x28c($sp)
  sltiu $t4, $t5, 1
  andi  $t0, $t5, 0xf
  move  $s0, $t5
  andi  $t6, $t5, 0xa8
  addiu $t8, $t9, 4
  xori  $t5, $t5, 0x80
  slt   $t3, $zero, $t0
  sll   $t1, $t4, 6
  sw    $t8, 0x28c($sp)
  or    $t7, $t6, $t1
  sll   $t9, $t3, 4
  sltiu $t5, $t5, 1
  sw    $t4, 0x48($sp)
  sll   $t4, $t5, 2
  or    $t8, $t7, $t9
  or    $t2, $t8, $t4
  ori   $t6, $t2, 2
  slt   $t1, $zero, $s0
  or    $s1, $t6, $t1
  andi  $t0, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t0
spectrum_op_ED_4D:
  lw    $t3, 0x28c($sp)
  lui   $t4, %hi(ptr_spectrum_roms) 
  lw    $t4, %lo(ptr_spectrum_roms)($t4)
  lhu   $t8, 0x292($sp)
  addiu $t7, $t3, 4
  sw    $t7, 0x28c($sp)
  addiu $t5, $t7, 6
  sw    $t5, 0x28c($sp)
  addu  $t1, $t4, $t8
  lbu   $t0, 1($t1)
  addu  $t2, $t8, $t4
  lbu   $t6, ($t2)
  sll   $t3, $t0, 8
  addiu $t9, $t8, 2
  or    $t7, $t6, $t3
  sh    $t7, 0x298($sp)
  b     .L7F0E27FC
   sh    $t9, 0x292($sp)
spectrum_op_ED_4E:
  lw    $t5, 0x28c($sp)
  li    $t4, 1
  sb    $t4, 0x29b($sp)
  addiu $t2, $t5, 4
  b     .L7F0E27FC
   sw    $t2, 0x28c($sp)
spectrum_op_ED_4F:
  lw    $t1, 0x28c($sp)
  andi  $t6, $s0, 0xff
  sb    $s0, 0x2a7($sp)
  addiu $t0, $t1, 5
  sw    $t0, 0x28c($sp)
  b     .L7F0E27FC
   sw    $t6, 0x288($sp)
spectrum_op_ED_50:
  lw    $t3, 0x28c($sp)
  move  $a1, $s2
  move  $a2, $s3
  addiu $a0, $t3, 8
  jal   spectrum_input_handling
   sw    $a0, 0x28c($sp)
  lw    $t8, 0x28c($sp)
  andi  $t9, $v0, 0xffff
  sra   $t5, $t9, 8
  sh    $v0, 0xc8($sp)
  addu  $t2, $t8, $t5
  lbu   $s4, 0xc9($sp)
  lui   $t8, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t8, %lo(ptr_pc_keyboard_table_alloc)($t8)
  sltiu $t4, $s4, 1
  sw    $t4, 0x48($sp)
  sw    $t2, 0x28c($sp)
  addu  $t5, $s4, $t8
  lbu   $t2, ($t5)
  andi  $t1, $s1, 1
  andi  $t0, $s4, 0xa8
  or    $t6, $t1, $t0
  sll   $t7, $t4, 6
  or    $t9, $t6, $t7
  or    $s1, $t2, $t9
  andi  $t4, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t4
spectrum_op_ED_51:
  lw    $t1, 0x28c($sp)
  move  $a1, $s2
  move  $a2, $s3
  addiu $a0, $t1, 8
  sw    $a0, 0x28c($sp)
  jal   sub_GAME_7F0D37DC
   move  $a3, $s4
  lw    $t3, 0x28c($sp)
  sw    $v0, 0x48($sp)
  addu  $t7, $t3, $v0
  b     .L7F0E27FC
   sw    $t7, 0x28c($sp)
spectrum_op_ED_52:
  sll   $t2, $s4, 8
  lw    $t8, 0x28c($sp)
  or    $t9, $t2, $s5
  sll   $t4, $s6, 8
  or    $t1, $t4, $s7
  andi  $t0, $t9, 0xffff
  subu  $t3, $t1, $t0
  andi  $t6, $s1, 1
  lui   $at, (0x0001FFFF >> 16) # lui $at, 1
  ori   $at, (0x0001FFFF & 0xFFFF) # ori $at, $at, 0xffff
  subu  $t7, $t3, $t6
  addiu $t5, $t8, 0xb
  and   $t8, $t7, $at
  srl   $t4, $t8, 8
  andi  $t1, $t4, 0xa8
  srl   $t0, $t8, 0x10
  sw    $t5, 0x28c($sp)
  or    $t3, $t1, $t0
  andi  $t5, $t8, 0xffff
  sltiu $t2, $t5, 1
  ori   $t6, $t3, 2
  sll   $t0, $s6, 8
  or    $t3, $t0, $s7
  andi  $t5, $t9, 0xfff
  andi  $t4, $s1, 1
  addu  $t1, $t5, $t4
  andi  $t7, $t3, 0xfff
  slt   $t5, $t7, $t1
  sll   $t4, $t5, 4
  or    $t0, $t6, $t4
  sll   $t3, $s6, 8
  or    $t7, $t3, $s7
  sll   $t5, $s6, 8
  or    $t6, $t5, $s7
  move  $t4, $t9
  xor   $t3, $t6, $t4
  xor   $t1, $t7, $t8
  and   $t7, $t3, $t1
  andi  $t5, $t7, 0x8000
  sh    $t9, 0xc6($sp)
  srl   $t9, $t5, 0xd
  or    $t6, $t0, $t9
  sll   $t4, $t2, 6
  or    $s1, $t6, $t4
  srl   $s6, $t8, 8
  andi  $t7, $s6, 0xff
  ori   $t3, $s1, 2
  sw    $t8, 0xc0($sp)
  lbu   $s7, 0xc3($sp)
  andi  $s1, $t3, 0xff
  move  $s6, $t7
  b     .L7F0E27FC
   sw    $t2, 0x48($sp)
spectrum_op_ED_53:
  lw    $t5, 0x28c($sp)
  lui   $t2, %hi(ptr_spectrum_roms) 
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  lhu   $t9, 0x298($sp)
  addiu $t0, $t5, 0x10
  sw    $t0, 0x28c($sp)
  addu  $t3, $t2, $t9
  lbu   $t1, 1($t3)
  addu  $t6, $t9, $t2
  lbu   $t4, ($t6)
  sll   $t8, $t1, 8
  addiu $t5, $t9, 2
  or    $t7, $t4, $t8
  andi  $t0, $t7, 0xffff
  slti  $at, $t0, 0x5b00
  sh    $t7, 0xbe($sp)
  bnez  $at, .L7F0DF2B0
   sh    $t5, 0x298($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  addu  $t2, $t6, $t0
  b     .L7F0DF330
   sb    $s5, ($t2)
.L7F0DF2B0:
  lhu   $t3, 0xbe($sp)
  lhu   $t6, 0xbe($sp)
  lui   $t1, %hi(ptr_spectrum_roms) 
  slti  $at, $t3, 0x5800
  bnezl $at, .L7F0DF2F4
   slti  $at, $t6, 0x4000
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  lui   $t7, %hi(ptr_300alloc) 
  li    $t8, 1
  addu  $t4, $t1, $t3
  sb    $s5, ($t4)
  lhu   $t9, 0xbe($sp)
  lw    $t7, %lo(ptr_300alloc)($t7)
  addu  $t5, $t7, $t9
  b     .L7F0DF330
   sb    $t8, -0x5800($t5)
  slti  $at, $t6, 0x4000
.L7F0DF2F4:
  bnez  $at, .L7F0DF330
   lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  lui   $t5, %hi(ptr_300alloc) 
  li    $t1, 1
  addu  $t2, $t0, $t6
  sb    $s5, ($t2)
  lhu   $t3, 0xbe($sp)
  lw    $t5, %lo(ptr_300alloc)($t5)
  andi  $t4, $t3, 0x1800
  sra   $t7, $t4, 3
  andi  $t9, $t3, 0xff
  or    $t8, $t7, $t9
  addu  $t0, $t5, $t8
  sb    $t1, ($t0)
.L7F0DF330:
  lhu   $t6, 0xbe($sp)
  lhu   $t7, 0xbe($sp)
  lui   $t4, %hi(ptr_spectrum_roms) 
  addiu $t2, $t6, 1
  slti  $at, $t2, 0x5b00
  bnez  $at, .L7F0DF35C
   addiu $t9, $t7, 1
  lw    $t4, %lo(ptr_spectrum_roms)($t4)
  addu  $t3, $t4, $t6
  b     .L7F0E27FC
   sb    $s4, 1($t3)
.L7F0DF35C:
  slti  $at, $t9, 0x5800
  bnez  $at, .L7F0DF394
   lhu   $t6, 0xbe($sp)
  lui   $t5, %hi(ptr_spectrum_roms) 
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  lui   $t0, %hi(ptr_300alloc) 
  li    $t1, 1
  addu  $t8, $t5, $t7
  sb    $s4, 1($t8)
  lhu   $t2, 0xbe($sp)
  lw    $t0, %lo(ptr_300alloc)($t0)
  addu  $t4, $t0, $t2
  b     .L7F0E27FC
   sb    $t1, -0x57ff($t4)
.L7F0DF394:
  addiu $t3, $t6, 1
  slti  $at, $t3, 0x4000
  bnez  $at, .L7F0E27FC
   lui   $t9, %hi(ptr_spectrum_roms) 
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  li    $t7, 1
  addu  $t5, $t9, $t6
  sb    $s4, 1($t5)
  lhu   $t8, 0xbe($sp)
  lui   $t9, %hi(ptr_300alloc) 
  lw    $t9, %lo(ptr_300alloc)($t9)
  addiu $t0, $t8, 1
  andi  $t2, $t0, 0x1800
  sra   $t1, $t2, 3
  andi  $t4, $t0, 0xff
  or    $t3, $t1, $t4
  addu  $t6, $t9, $t3
  b     .L7F0E27FC
   sb    $t7, ($t6)
spectrum_op_ED_54:
  negu  $s0, $s0
  andi  $t2, $s0, 0xff
  lw    $t5, 0x28c($sp)
  sltiu $t0, $t2, 1
  andi  $t7, $t2, 0xf
  move  $s0, $t2
  andi  $t1, $t2, 0xa8
  addiu $t8, $t5, 4
  xori  $t2, $t2, 0x80
  slt   $t6, $zero, $t7
  sll   $t9, $t0, 6
  sw    $t8, 0x28c($sp)
  or    $t3, $t1, $t9
  sll   $t5, $t6, 4
  sltiu $t2, $t2, 1
  sw    $t0, 0x48($sp)
  sll   $t0, $t2, 2
  or    $t8, $t3, $t5
  or    $t4, $t8, $t0
  ori   $t1, $t4, 2
  slt   $t9, $zero, $s0
  or    $s1, $t1, $t9
  andi  $t7, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t7
spectrum_op_ED_55:
  lw    $t6, 0x28c($sp)
  lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  lhu   $t8, 0x292($sp)
  addiu $t3, $t6, 4
  sw    $t3, 0x28c($sp)
  addiu $t2, $t3, 6
  sw    $t2, 0x28c($sp)
  addu  $t9, $t0, $t8
  lbu   $t7, 1($t9)
  addu  $t4, $t8, $t0
  lbu   $t1, ($t4)
  sll   $t6, $t7, 8
  addiu $t5, $t8, 2
  or    $t3, $t1, $t6
  sh    $t3, 0x298($sp)
  b     .L7F0E27FC
   sh    $t5, 0x292($sp)
spectrum_op_ED_56:
  lw    $t2, 0x28c($sp)
  li    $t0, 2
  sb    $t0, 0x29b($sp)
  addiu $t4, $t2, 4
  b     .L7F0E27FC
   sw    $t4, 0x28c($sp)
spectrum_op_ED_57:
  lbu   $s0, 0x29e($sp)
  lw    $t9, 0x28c($sp)
  lbu   $t0, 0x29c($sp)
  andi  $t6, $s1, 1
  sltiu $t1, $s0, 1
  andi  $t3, $s0, 0xa8
  or    $t8, $t6, $t3
  sll   $t2, $t1, 6
  addiu $t7, $t9, 5
  or    $t4, $t8, $t2
  sll   $t9, $t0, 2
  sw    $t7, 0x28c($sp)
  or    $s1, $t4, $t9
  andi  $t7, $s1, 0xff
  move  $s1, $t7
  b     .L7F0E27FC
   sw    $t1, 0x48($sp)
spectrum_op_ED_58:
  lw    $t1, 0x28c($sp)
  move  $a1, $s2
  move  $a2, $s3
  addiu $a0, $t1, 8
  jal   spectrum_input_handling
   sw    $a0, 0x28c($sp)
  lw    $t3, 0x28c($sp)
  andi  $t5, $v0, 0xffff
  sra   $t8, $t5, 8
  sh    $v0, 0xbc($sp)
  addu  $t2, $t3, $t8
  lbu   $s5, 0xbd($sp)
  lui   $t3, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t3, %lo(ptr_pc_keyboard_table_alloc)($t3)
  sltiu $t0, $s5, 1
  sw    $t0, 0x48($sp)
  sw    $t2, 0x28c($sp)
  addu  $t8, $s5, $t3
  lbu   $t2, ($t8)
  andi  $t4, $s1, 1
  andi  $t9, $s5, 0xa8
  or    $t7, $t4, $t9
  sll   $t6, $t0, 6
  or    $t5, $t7, $t6
  or    $s1, $t2, $t5
  andi  $t0, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t0
spectrum_op_ED_59:
  lw    $t4, 0x28c($sp)
  move  $a1, $s2
  move  $a2, $s3
  addiu $a0, $t4, 8
  sw    $a0, 0x28c($sp)
  jal   sub_GAME_7F0D37DC
   move  $a3, $s5
  lw    $t1, 0x28c($sp)
  sw    $v0, 0x48($sp)
  addu  $t6, $t1, $v0
  b     .L7F0E27FC
   sw    $t6, 0x28c($sp)
spectrum_op_ED_5A:
  sll   $t2, $s4, 8
  or    $t5, $t2, $s5
  sll   $t0, $s6, 8
  or    $t4, $t0, $s7
  andi  $t9, $t5, 0xffff
  lw    $t3, 0x28c($sp)
  addu  $t1, $t4, $t9
  andi  $t7, $s1, 1
  addu  $t6, $t1, $t7
  addiu $t8, $t3, 0xb
  srl   $t2, $t6, 8
  sw    $t8, 0x28c($sp)
  andi  $t0, $t2, 0xa8
  andi  $t3, $t6, 0xffff
  srl   $t4, $t6, 0x10
  sll   $t1, $s6, 8
  or    $t7, $t1, $s7
  or    $t9, $t0, $t4
  sltiu $t8, $t3, 1
  andi  $t3, $t7, 0xfff
  andi  $t0, $t5, 0xfff
  addu  $t4, $t3, $t0
  andi  $t1, $s1, 1
  addu  $t7, $t4, $t1
  li    $at, 4095
  slt   $t2, $at, $t7
  sll   $t3, $t2, 4
  or    $t0, $t9, $t3
  sll   $t4, $s6, 8
  or    $t1, $t4, $s7
  sll   $t2, $s6, 8
  nor   $t9, $t2, $s7
  move  $t3, $t5
  xor   $t4, $t9, $t3
  xor   $t7, $t1, $t6
  and   $t1, $t4, $t7
  andi  $t2, $t1, 0x8000
  sh    $t5, 0xba($sp)
  srl   $t5, $t2, 0xd
  or    $t9, $t0, $t5
  sll   $t3, $t8, 6
  or    $s1, $t9, $t3
  srl   $s6, $t6, 8
  andi  $t1, $s6, 0xff
  ori   $t4, $s1, 2
  sw    $t6, 0xb4($sp)
  lbu   $s7, 0xb7($sp)
  andi  $s1, $t4, 0xff
  move  $s6, $t1
  b     .L7F0E27FC
   sw    $t8, 0x48($sp)
spectrum_op_ED_5B:
  lw    $t2, 0x28c($sp)
  lui   $t8, %hi(ptr_spectrum_roms) 
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  lhu   $t5, 0x298($sp)
  addiu $t0, $t2, 0x10
  sw    $t0, 0x28c($sp)
  addu  $t4, $t8, $t5
  lbu   $t7, 1($t4)
  addu  $t9, $t5, $t8
  lbu   $t3, ($t9)
  sll   $t6, $t7, 8
  addiu $t2, $t5, 2
  or    $t1, $t3, $t6
  andi  $t0, $t1, 0xffff
  sh    $t1, 0xb2($sp)
  sh    $t2, 0x298($sp)
  addu  $t9, $t0, $t8
  lbu   $s5, ($t9)
  b     .L7F0E27FC
   lbu   $s4, 1($t9)
spectrum_op_ED_5C:
  negu  $s0, $s0
  andi  $t3, $s0, 0xff
  lw    $t4, 0x28c($sp)
  sltiu $t6, $t3, 1
  andi  $t8, $t3, 0xf
  move  $s0, $t3
  andi  $t1, $t3, 0xa8
  addiu $t7, $t4, 4
  xori  $t3, $t3, 0x80
  slt   $t9, $zero, $t8
  sll   $t2, $t6, 6
  sw    $t7, 0x28c($sp)
  or    $t0, $t1, $t2
  sll   $t4, $t9, 4
  sltiu $t3, $t3, 1
  sw    $t6, 0x48($sp)
  sll   $t6, $t3, 2
  or    $t7, $t0, $t4
  or    $t5, $t7, $t6
  ori   $t1, $t5, 2
  slt   $t2, $zero, $s0
  or    $s1, $t1, $t2
  andi  $t8, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t8
spectrum_op_ED_5D:
  lw    $t9, 0x28c($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  lhu   $t7, 0x292($sp)
  addiu $t0, $t9, 4
  sw    $t0, 0x28c($sp)
  addiu $t3, $t0, 6
  sw    $t3, 0x28c($sp)
  addu  $t2, $t6, $t7
  lbu   $t8, 1($t2)
  addu  $t5, $t7, $t6
  lbu   $t1, ($t5)
  sll   $t9, $t8, 8
  addiu $t4, $t7, 2
  or    $t0, $t1, $t9
  sh    $t0, 0x298($sp)
  b     .L7F0E27FC
   sh    $t4, 0x292($sp)
spectrum_op_ED_5E:
  lw    $t3, 0x28c($sp)
  li    $t6, 3
  sb    $t6, 0x29b($sp)
  addiu $t5, $t3, 4
  b     .L7F0E27FC
   sw    $t5, 0x28c($sp)
spectrum_op_ED_5F:
  lbu   $t1, 0x2a7($sp)
  lw    $t0, 0x288($sp)
  lw    $t2, 0x28c($sp)
  andi  $t9, $t1, 0x80
  andi  $t7, $t0, 0x7f
  or    $s0, $t9, $t7
  andi  $t3, $s0, 0xff
  addiu $t8, $t2, 5
  lbu   $t7, 0x29c($sp)
  sw    $t8, 0x28c($sp)
  andi  $t2, $t3, 0xa8
  sltiu $t5, $t3, 1
  andi  $t6, $s1, 1
  or    $t8, $t6, $t2
  sll   $t0, $t5, 6
  sb    $s0, 0x2a7($sp)
  or    $t9, $t8, $t0
  sll   $t4, $t7, 2
  move  $s0, $t3
  or    $s1, $t9, $t4
  andi  $t3, $s1, 0xff
  move  $s1, $t3
  b     .L7F0E27FC
   sw    $t5, 0x48($sp)
spectrum_op_ED_60:
  lw    $t5, 0x28c($sp)
  move  $a1, $s2
  move  $a2, $s3
  addiu $a0, $t5, 8
  jal   spectrum_input_handling
   sw    $a0, 0x28c($sp)
  lw    $t2, 0x28c($sp)
  andi  $t1, $v0, 0xffff
  sra   $t8, $t1, 8
  sh    $v0, 0xb0($sp)
  addu  $t0, $t2, $t8
  lbu   $s6, 0xb1($sp)
  lui   $t2, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t2, %lo(ptr_pc_keyboard_table_alloc)($t2)
  sltiu $t7, $s6, 1
  sw    $t7, 0x48($sp)
  sw    $t0, 0x28c($sp)
  addu  $t8, $s6, $t2
  lbu   $t0, ($t8)
  andi  $t9, $s1, 1
  andi  $t4, $s6, 0xa8
  or    $t3, $t9, $t4
  sll   $t6, $t7, 6
  or    $t1, $t3, $t6
  or    $s1, $t0, $t1
  andi  $t7, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t7
spectrum_op_ED_61:
  lw    $t9, 0x28c($sp)
  move  $a1, $s2
  move  $a2, $s3
  addiu $a0, $t9, 8
  sw    $a0, 0x28c($sp)
  jal   sub_GAME_7F0D37DC
   move  $a3, $s6
  lw    $t5, 0x28c($sp)
  sw    $v0, 0x48($sp)
  addu  $t6, $t5, $v0
  b     .L7F0E27FC
   sw    $t6, 0x28c($sp)
spectrum_op_ED_62:
  sll   $t0, $s6, 8
  lw    $t2, 0x28c($sp)
  or    $t1, $t0, $s7
  sll   $t7, $s6, 8
  or    $t9, $t7, $s7
  andi  $t4, $t1, 0xffff
  subu  $t5, $t9, $t4
  andi  $t3, $s1, 1
  lui   $at, (0x0001FFFF >> 16) # lui $at, 1
  ori   $at, (0x0001FFFF & 0xFFFF) # ori $at, $at, 0xffff
  subu  $t6, $t5, $t3
  addiu $t8, $t2, 0xb
  and   $t2, $t6, $at
  srl   $t7, $t2, 8
  andi  $t9, $t7, 0xa8
  srl   $t4, $t2, 0x10
  sw    $t8, 0x28c($sp)
  or    $t5, $t9, $t4
  andi  $t8, $t2, 0xffff
  sltiu $t0, $t8, 1
  ori   $t3, $t5, 2
  sll   $t4, $s6, 8
  or    $t5, $t4, $s7
  andi  $t8, $t1, 0xfff
  andi  $t7, $s1, 1
  addu  $t9, $t8, $t7
  andi  $t6, $t5, 0xfff
  slt   $t8, $t6, $t9
  sll   $t7, $t8, 4
  or    $t4, $t3, $t7
  sll   $t5, $s6, 8
  or    $t6, $t5, $s7
  sll   $t8, $s6, 8
  or    $t3, $t8, $s7
  move  $t7, $t1
  xor   $t5, $t3, $t7
  xor   $t9, $t6, $t2
  and   $t6, $t5, $t9
  andi  $t8, $t6, 0x8000
  sh    $t1, 0xae($sp)
  srl   $t1, $t8, 0xd
  or    $t3, $t4, $t1
  sll   $t7, $t0, 6
  or    $s1, $t3, $t7
  srl   $s6, $t2, 8
  andi  $t6, $s6, 0xff
  ori   $t5, $s1, 2
  sw    $t2, 0xa8($sp)
  lbu   $s7, 0xab($sp)
  andi  $s1, $t5, 0xff
  move  $s6, $t6
  b     .L7F0E27FC
   sw    $t0, 0x48($sp)
spectrum_op_ED_63:
  lw    $t8, 0x28c($sp)
  lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  lhu   $t1, 0x298($sp)
  addiu $t4, $t8, 0x10
  sw    $t4, 0x28c($sp)
  addu  $t5, $t0, $t1
  lbu   $t9, 1($t5)
  addu  $t3, $t1, $t0
  lbu   $t7, ($t3)
  sll   $t2, $t9, 8
  addiu $t8, $t1, 2
  or    $t6, $t7, $t2
  andi  $t4, $t6, 0xffff
  slti  $at, $t4, 0x5b00
  sh    $t6, 0xa6($sp)
  bnez  $at, .L7F0DF998
   sh    $t8, 0x298($sp)
  lui   $t3, %hi(ptr_spectrum_roms) 
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  addu  $t0, $t3, $t4
  b     .L7F0DFA18
   sb    $s7, ($t0)
.L7F0DF998:
  lhu   $t5, 0xa6($sp)
  lhu   $t3, 0xa6($sp)
  lui   $t9, %hi(ptr_spectrum_roms) 
  slti  $at, $t5, 0x5800
  bnezl $at, .L7F0DF9DC
   slti  $at, $t3, 0x4000
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  lui   $t6, %hi(ptr_300alloc) 
  li    $t2, 1
  addu  $t7, $t9, $t5
  sb    $s7, ($t7)
  lhu   $t1, 0xa6($sp)
  lw    $t6, %lo(ptr_300alloc)($t6)
  addu  $t8, $t6, $t1
  b     .L7F0DFA18
   sb    $t2, -0x5800($t8)
  slti  $at, $t3, 0x4000
.L7F0DF9DC:
  bnez  $at, .L7F0DFA18
   lui   $t4, %hi(ptr_spectrum_roms) 
  lw    $t4, %lo(ptr_spectrum_roms)($t4)
  lui   $t8, %hi(ptr_300alloc) 
  li    $t9, 1
  addu  $t0, $t4, $t3
  sb    $s7, ($t0)
  lhu   $t5, 0xa6($sp)
  lw    $t8, %lo(ptr_300alloc)($t8)
  andi  $t7, $t5, 0x1800
  sra   $t6, $t7, 3
  andi  $t1, $t5, 0xff
  or    $t2, $t6, $t1
  addu  $t4, $t8, $t2
  sb    $t9, ($t4)
.L7F0DFA18:
  lhu   $t3, 0xa6($sp)
  lhu   $t6, 0xa6($sp)
  lui   $t7, %hi(ptr_spectrum_roms) 
  addiu $t0, $t3, 1
  slti  $at, $t0, 0x5b00
  bnez  $at, .L7F0DFA44
   addiu $t1, $t6, 1
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  addu  $t5, $t7, $t3
  b     .L7F0E27FC
   sb    $s6, 1($t5)
.L7F0DFA44:
  slti  $at, $t1, 0x5800
  bnez  $at, .L7F0DFA7C
   lhu   $t3, 0xa6($sp)
  lui   $t8, %hi(ptr_spectrum_roms) 
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  lui   $t4, %hi(ptr_300alloc) 
  li    $t9, 1
  addu  $t2, $t8, $t6
  sb    $s6, 1($t2)
  lhu   $t0, 0xa6($sp)
  lw    $t4, %lo(ptr_300alloc)($t4)
  addu  $t7, $t4, $t0
  b     .L7F0E27FC
   sb    $t9, -0x57ff($t7)
.L7F0DFA7C:
  addiu $t5, $t3, 1
  slti  $at, $t5, 0x4000
  bnez  $at, .L7F0E27FC
   lui   $t1, %hi(ptr_spectrum_roms) 
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  li    $t6, 1
  addu  $t8, $t1, $t3
  sb    $s6, 1($t8)
  lhu   $t2, 0xa6($sp)
  lui   $t1, %hi(ptr_300alloc) 
  lw    $t1, %lo(ptr_300alloc)($t1)
  addiu $t4, $t2, 1
  andi  $t0, $t4, 0x1800
  sra   $t9, $t0, 3
  andi  $t7, $t4, 0xff
  or    $t5, $t9, $t7
  addu  $t3, $t1, $t5
  b     .L7F0E27FC
   sb    $t6, ($t3)
spectrum_op_ED_64:
  negu  $s0, $s0
  andi  $t0, $s0, 0xff
  lw    $t8, 0x28c($sp)
  sltiu $t4, $t0, 1
  andi  $t6, $t0, 0xf
  move  $s0, $t0
  andi  $t9, $t0, 0xa8
  addiu $t2, $t8, 4
  xori  $t0, $t0, 0x80
  slt   $t3, $zero, $t6
  sll   $t1, $t4, 6
  sw    $t2, 0x28c($sp)
  or    $t5, $t9, $t1
  sll   $t8, $t3, 4
  sltiu $t0, $t0, 1
  sw    $t4, 0x48($sp)
  sll   $t4, $t0, 2
  or    $t2, $t5, $t8
  or    $t7, $t2, $t4
  ori   $t9, $t7, 2
  slt   $t1, $zero, $s0
  or    $s1, $t9, $t1
  andi  $t6, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t6
spectrum_op_ED_65:
  lw    $t3, 0x28c($sp)
  lui   $t4, %hi(ptr_spectrum_roms) 
  lw    $t4, %lo(ptr_spectrum_roms)($t4)
  lhu   $t2, 0x292($sp)
  addiu $t5, $t3, 4
  sw    $t5, 0x28c($sp)
  addiu $t0, $t5, 6
  sw    $t0, 0x28c($sp)
  addu  $t1, $t4, $t2
  lbu   $t6, 1($t1)
  addu  $t7, $t2, $t4
  lbu   $t9, ($t7)
  sll   $t3, $t6, 8
  addiu $t8, $t2, 2
  or    $t5, $t9, $t3
  sh    $t5, 0x298($sp)
  b     .L7F0E27FC
   sh    $t8, 0x292($sp)
spectrum_op_ED_66:
  lw    $t0, 0x28c($sp)
  sb    $zero, 0x29b($sp)
  addiu $t7, $t0, 4
  b     .L7F0E27FC
   sw    $t7, 0x28c($sp)
spectrum_op_ED_67:
  lw    $t4, 0x28c($sp)
  lui   $t3, %hi(ptr_spectrum_roms) 
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  sll   $t6, $s6, 8
  or    $t9, $t6, $s7
  addiu $t1, $t4, 0xe
  sw    $t1, 0x28c($sp)
  addu  $t5, $t9, $t3
  lbu   $t2, ($t5)
  sll   $t0, $s0, 4
  andi  $t1, $s0, 0xf0
  sll   $t9, $s6, 8
  andi  $t4, $t2, 0xf
  or    $s0, $t1, $t4
  or    $t3, $t9, $s7
  sra   $t8, $t2, 4
  or    $t7, $t0, $t8
  andi  $t6, $s0, 0xff
  slti  $at, $t3, 0x5b00
  sb    $t7, 0xa4($sp)
  move  $s0, $t6
  bnez  $at, .L7F0DFC04
   sb    $t2, 0xa5($sp)
  lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  move  $t5, $t7
  sll   $t8, $s6, 8
  or    $t7, $t8, $s7
  addu  $t2, $t0, $t7
  b     .L7F0DFCAC
   sb    $t5, ($t2)
.L7F0DFC04:
  sll   $t1, $s6, 8
  or    $t4, $t1, $s7
  slti  $at, $t4, 0x5800
  bnez  $at, .L7F0DFC54
   sll   $t3, $s6, 8
  lui   $t9, %hi(ptr_spectrum_roms) 
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  lbu   $t6, 0xa4($sp)
  sll   $t3, $s6, 8
  or    $t8, $t3, $s7
  addu  $t0, $t9, $t8
  lui   $t5, %hi(ptr_300alloc) 
  sb    $t6, ($t0)
  lw    $t5, %lo(ptr_300alloc)($t5)
  sll   $t2, $s6, 8
  or    $t1, $t2, $s7
  li    $t7, 1
  addu  $t4, $t5, $t1
  b     .L7F0DFCAC
   sb    $t7, -0x5800($t4)
.L7F0DFC54:
  or    $t9, $t3, $s7
  slti  $at, $t9, 0x4000
  bnez  $at, .L7F0DFCAC
   lbu   $t8, 0xa4($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  sll   $t0, $s6, 8
  or    $t2, $t0, $s7
  addu  $t5, $t6, $t2
  sb    $t8, ($t5)
  sll   $t7, $s6, 8
  or    $t4, $t7, $s7
  lui   $t5, %hi(ptr_300alloc) 
  lw    $t5, %lo(ptr_300alloc)($t5)
  andi  $t3, $t4, 0x1800
  or    $t6, $t0, $s7
  andi  $t2, $t6, 0xff
  sra   $t9, $t3, 3
  or    $t8, $t9, $t2
  li    $t1, 1
  addu  $t7, $t5, $t8
  sb    $t1, ($t7)
.L7F0DFCAC:
  lui   $t8, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t8, %lo(ptr_pc_keyboard_table_alloc)($t8)
  sltiu $t4, $s0, 1
  sw    $t4, 0x48($sp)
  addu  $t1, $s0, $t8
  lbu   $t7, ($t1)
  andi  $t3, $s1, 1
  andi  $t0, $s0, 0xa8
  or    $t6, $t3, $t0
  sll   $t2, $t4, 6
  or    $t5, $t6, $t2
  or    $s1, $t7, $t5
  andi  $t4, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t4
spectrum_op_ED_68:
  lw    $t3, 0x28c($sp)
  move  $a1, $s2
  move  $a2, $s3
  addiu $a0, $t3, 8
  jal   spectrum_input_handling
   sw    $a0, 0x28c($sp)
  lw    $t9, 0x28c($sp)
  andi  $t6, $v0, 0xffff
  sra   $t2, $t6, 8
  sh    $v0, 0xa2($sp)
  addu  $t8, $t9, $t2
  lbu   $s7, 0xa3($sp)
  lui   $t9, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t9, %lo(ptr_pc_keyboard_table_alloc)($t9)
  sltiu $t1, $s7, 1
  sw    $t1, 0x48($sp)
  sw    $t8, 0x28c($sp)
  addu  $t2, $s7, $t9
  lbu   $t8, ($t2)
  andi  $t7, $s1, 1
  andi  $t5, $s7, 0xa8
  or    $t4, $t7, $t5
  sll   $t0, $t1, 6
  or    $t6, $t4, $t0
  or    $s1, $t8, $t6
  andi  $t1, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t1
spectrum_op_ED_69:
  lw    $t7, 0x28c($sp)
  move  $a1, $s2
  move  $a2, $s3
  addiu $a0, $t7, 8
  sw    $a0, 0x28c($sp)
  jal   sub_GAME_7F0D37DC
   move  $a3, $s7
  lw    $t3, 0x28c($sp)
  sw    $v0, 0x48($sp)
  addu  $t0, $t3, $v0
  b     .L7F0E27FC
   sw    $t0, 0x28c($sp)
spectrum_op_ED_6A:
  sll   $t8, $s6, 8
  or    $t6, $t8, $s7
  sll   $t1, $s6, 8
  or    $t7, $t1, $s7
  andi  $t5, $t6, 0xffff
  lw    $t9, 0x28c($sp)
  addu  $t3, $t7, $t5
  andi  $t4, $s1, 1
  addu  $t0, $t3, $t4
  addiu $t2, $t9, 0xb
  srl   $t8, $t0, 8
  sw    $t2, 0x28c($sp)
  andi  $t1, $t8, 0xa8
  andi  $t9, $t0, 0xffff
  srl   $t7, $t0, 0x10
  sll   $t3, $s6, 8
  or    $t4, $t3, $s7
  or    $t5, $t1, $t7
  sltiu $t2, $t9, 1
  andi  $t9, $t4, 0xfff
  andi  $t1, $t6, 0xfff
  addu  $t7, $t9, $t1
  andi  $t3, $s1, 1
  addu  $t4, $t7, $t3
  li    $at, 4095
  slt   $t8, $at, $t4
  sll   $t9, $t8, 4
  or    $t1, $t5, $t9
  sll   $t7, $s6, 8
  or    $t3, $t7, $s7
  sll   $t8, $s6, 8
  nor   $t5, $t8, $s7
  move  $t9, $t6
  xor   $t7, $t5, $t9
  xor   $t4, $t3, $t0
  and   $t3, $t7, $t4
  andi  $t8, $t3, 0x8000
  sh    $t6, 0xa0($sp)
  srl   $t6, $t8, 0xd
  or    $t5, $t1, $t6
  sll   $t9, $t2, 6
  or    $s1, $t5, $t9
  srl   $s6, $t0, 8
  andi  $t3, $s6, 0xff
  ori   $t7, $s1, 2
  sw    $t0, 0x9c($sp)
  lbu   $s7, 0x9f($sp)
  andi  $s1, $t7, 0xff
  move  $s6, $t3
  b     .L7F0E27FC
   sw    $t2, 0x48($sp)
spectrum_op_ED_6B:
  lw    $t8, 0x28c($sp)
  lui   $t2, %hi(ptr_spectrum_roms) 
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  lhu   $t6, 0x298($sp)
  addiu $t1, $t8, 0x10
  sw    $t1, 0x28c($sp)
  addu  $t7, $t2, $t6
  lbu   $t4, 1($t7)
  addu  $t5, $t6, $t2
  lbu   $t9, ($t5)
  sll   $t0, $t4, 8
  addiu $t8, $t6, 2
  or    $t3, $t9, $t0
  andi  $t1, $t3, 0xffff
  sh    $t3, 0x9a($sp)
  sh    $t8, 0x298($sp)
  addu  $t5, $t1, $t2
  lbu   $s7, ($t5)
  b     .L7F0E27FC
   lbu   $s6, 1($t5)
spectrum_op_ED_6C:
  negu  $s0, $s0
  andi  $t9, $s0, 0xff
  lw    $t7, 0x28c($sp)
  sltiu $t0, $t9, 1
  andi  $t2, $t9, 0xf
  move  $s0, $t9
  andi  $t3, $t9, 0xa8
  addiu $t4, $t7, 4
  xori  $t9, $t9, 0x80
  slt   $t5, $zero, $t2
  sll   $t8, $t0, 6
  sw    $t4, 0x28c($sp)
  or    $t1, $t3, $t8
  sll   $t7, $t5, 4
  sltiu $t9, $t9, 1
  sw    $t0, 0x48($sp)
  sll   $t0, $t9, 2
  or    $t4, $t1, $t7
  or    $t6, $t4, $t0
  ori   $t3, $t6, 2
  slt   $t8, $zero, $s0
  or    $s1, $t3, $t8
  andi  $t2, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t2
spectrum_op_ED_6D:
  lw    $t5, 0x28c($sp)
  lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  lhu   $t4, 0x292($sp)
  addiu $t1, $t5, 4
  sw    $t1, 0x28c($sp)
  addiu $t9, $t1, 6
  sw    $t9, 0x28c($sp)
  addu  $t8, $t0, $t4
  lbu   $t2, 1($t8)
  addu  $t6, $t4, $t0
  lbu   $t3, ($t6)
  sll   $t5, $t2, 8
  addiu $t7, $t4, 2
  or    $t1, $t3, $t5
  sh    $t1, 0x298($sp)
  b     .L7F0E27FC
   sh    $t7, 0x292($sp)
spectrum_op_ED_6E:
  lw    $t9, 0x28c($sp)
  li    $t0, 1
  sb    $t0, 0x29b($sp)
  addiu $t6, $t9, 4
  b     .L7F0E27FC
   sw    $t6, 0x28c($sp)
spectrum_op_ED_6F:
  lw    $t8, 0x28c($sp)
  lui   $t1, %hi(ptr_spectrum_roms) 
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  sll   $t3, $s6, 8
  or    $t5, $t3, $s7
  addiu $t2, $t8, 5
  sw    $t2, 0x28c($sp)
  addu  $t4, $t5, $t1
  lbu   $t7, ($t4)
  andi  $t6, $s0, 0xf
  andi  $t2, $s0, 0xf0
  sll   $t5, $s6, 8
  sra   $t8, $t7, 4
  or    $s0, $t2, $t8
  or    $t1, $t5, $s7
  sll   $t9, $t7, 4
  or    $t0, $t6, $t9
  andi  $t3, $s0, 0xff
  slti  $at, $t1, 0x5b00
  sb    $t0, 0x98($sp)
  move  $s0, $t3
  bnez  $at, .L7F0DFFE4
   sb    $t7, 0x99($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  move  $t4, $t0
  sll   $t9, $s6, 8
  or    $t0, $t9, $s7
  addu  $t7, $t6, $t0
  b     .L7F0E008C
   sb    $t4, ($t7)
.L7F0DFFE4:
  sll   $t2, $s6, 8
  or    $t8, $t2, $s7
  slti  $at, $t8, 0x5800
  bnez  $at, .L7F0E0034
   sll   $t1, $s6, 8
  lui   $t5, %hi(ptr_spectrum_roms) 
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  lbu   $t3, 0x98($sp)
  sll   $t1, $s6, 8
  or    $t9, $t1, $s7
  addu  $t6, $t5, $t9
  lui   $t4, %hi(ptr_300alloc) 
  sb    $t3, ($t6)
  lw    $t4, %lo(ptr_300alloc)($t4)
  sll   $t7, $s6, 8
  or    $t2, $t7, $s7
  li    $t0, 1
  addu  $t8, $t4, $t2
  b     .L7F0E008C
   sb    $t0, -0x5800($t8)
.L7F0E0034:
  or    $t5, $t1, $s7
  slti  $at, $t5, 0x4000
  bnez  $at, .L7F0E008C
   lbu   $t9, 0x98($sp)
  lui   $t3, %hi(ptr_spectrum_roms) 
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  sll   $t6, $s6, 8
  or    $t7, $t6, $s7
  addu  $t4, $t3, $t7
  sb    $t9, ($t4)
  sll   $t0, $s6, 8
  or    $t8, $t0, $s7
  lui   $t4, %hi(ptr_300alloc) 
  lw    $t4, %lo(ptr_300alloc)($t4)
  andi  $t1, $t8, 0x1800
  or    $t3, $t6, $s7
  andi  $t7, $t3, 0xff
  sra   $t5, $t1, 3
  or    $t9, $t5, $t7
  li    $t2, 1
  addu  $t0, $t4, $t9
  sb    $t2, ($t0)
.L7F0E008C:
  lui   $t9, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t9, %lo(ptr_pc_keyboard_table_alloc)($t9)
  sltiu $t8, $s0, 1
  sw    $t8, 0x48($sp)
  addu  $t2, $s0, $t9
  lbu   $t0, ($t2)
  andi  $t1, $s1, 1
  andi  $t6, $s0, 0xa8
  or    $t3, $t1, $t6
  sll   $t7, $t8, 6
  or    $t4, $t3, $t7
  or    $s1, $t0, $t4
  andi  $t8, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t8
spectrum_op_ED_70:
  lw    $t1, 0x28c($sp)
  move  $a1, $s2
  move  $a2, $s3
  addiu $a0, $t1, 8
  jal   spectrum_input_handling
   sw    $a0, 0x28c($sp)
  lw    $t3, 0x28c($sp)
  andi  $t8, $v0, 0xffff
  sra   $t7, $t8, 8
  addu  $t9, $t3, $t7
  sw    $t9, 0x28c($sp)
  lui   $t9, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t9, %lo(ptr_pc_keyboard_table_alloc)($t9)
  andi  $t2, $t8, 0xff
  andi  $t1, $t8, 0xa8
  sltiu $t0, $t2, 1
  sb    $t8, 0x97($sp)
  andi  $t4, $s1, 1
  or    $t6, $t4, $t1
  sw    $t0, 0x48($sp)
  sh    $v0, 0x94($sp)
  addu  $t8, $t2, $t9
  lbu   $t4, ($t8)
  sll   $t3, $t0, 6
  or    $t7, $t6, $t3
  or    $s1, $t4, $t7
  andi  $t1, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t1
spectrum_op_ED_71:
  lw    $t0, 0x28c($sp)
  move  $a1, $s2
  move  $a2, $s3
  addiu $a0, $t0, 8
  sw    $a0, 0x28c($sp)
  jal   sub_GAME_7F0D37DC
   move  $a3, $zero
  lw    $t3, 0x28c($sp)
  sw    $v0, 0x48($sp)
  addu  $t2, $t3, $v0
  b     .L7F0E27FC
   sw    $t2, 0x28c($sp)
spectrum_op_ED_72:
  lhu   $t4, 0x292($sp)
  lw    $t9, 0x28c($sp)
  sll   $t7, $s6, 8
  or    $t1, $t7, $s7
  andi  $t6, $s1, 1
  lui   $at, (0x0001FFFF >> 16) # lui $at, 1
  subu  $t0, $t1, $t4
  subu  $t3, $t0, $t6
  ori   $at, (0x0001FFFF & 0xFFFF) # ori $at, $at, 0xffff
  addiu $t8, $t9, 0xb
  sw    $t8, 0x28c($sp)
  and   $t5, $t3, $at
  srl   $t8, $t5, 8
  andi  $t7, $t8, 0xa8
  srl   $t1, $t5, 0x10
  or    $t0, $t7, $t1
  andi  $t2, $t5, 0xffff
  sltiu $t9, $t2, 1
  andi  $t2, $s1, 1
  ori   $t6, $t0, 2
  sll   $t1, $s6, 8
  andi  $t3, $t4, 0xfff
  addu  $t7, $t3, $t2
  or    $t0, $t1, $s7
  andi  $t3, $t0, 0xfff
  slt   $t2, $t3, $t7
  sll   $t1, $t2, 4
  or    $t0, $t6, $t1
  sll   $t3, $s6, 8
  or    $t7, $t3, $s7
  sll   $t6, $s6, 8
  or    $t1, $t6, $s7
  xor   $t3, $t1, $t5
  xor   $t2, $t7, $t4
  and   $t7, $t2, $t3
  sh    $t4, 0x92($sp)
  andi  $t4, $t7, 0x8000
  srl   $t6, $t4, 0xd
  sw    $t5, 0x8c($sp)
  sll   $t5, $t9, 6
  or    $t1, $t0, $t6
  or    $s1, $t1, $t5
  ori   $t2, $s1, 2
  andi  $s1, $t2, 0xff
  lbu   $s7, 0x8f($sp)
  andi  $s6, $t8, 0xff
  b     .L7F0E27FC
   sw    $t9, 0x48($sp)
spectrum_op_ED_73:
  lw    $t7, 0x28c($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  lhu   $t0, 0x298($sp)
  addiu $t4, $t7, 0x10
  sw    $t4, 0x28c($sp)
  addu  $t5, $t6, $t0
  lbu   $t2, 1($t5)
  addu  $t9, $t0, $t6
  lbu   $t1, ($t9)
  sll   $t3, $t2, 8
  addiu $t7, $t0, 2
  or    $t8, $t1, $t3
  andi  $t4, $t8, 0xffff
  slti  $at, $t4, 0x5b00
  sh    $t8, 0x8a($sp)
  bnez  $at, .L7F0E028C
   sh    $t7, 0x298($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  lhu   $t9, 0x292($sp)
  addu  $t5, $t6, $t4
  b     .L7F0E0314
   sb    $t9, ($t5)
.L7F0E028C:
  lhu   $t2, 0x8a($sp)
  lhu   $t9, 0x8a($sp)
  lui   $t3, %hi(ptr_spectrum_roms) 
  slti  $at, $t2, 0x5800
  bnezl $at, .L7F0E02D4
   slti  $at, $t9, 0x4000
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  lhu   $t1, 0x292($sp)
  lui   $t7, %hi(ptr_300alloc) 
  addu  $t8, $t3, $t2
  sb    $t1, ($t8)
  lhu   $t6, 0x8a($sp)
  lw    $t7, %lo(ptr_300alloc)($t7)
  li    $t0, 1
  addu  $t4, $t7, $t6
  b     .L7F0E0314
   sb    $t0, -0x5800($t4)
  slti  $at, $t9, 0x4000
.L7F0E02D4:
  bnez  $at, .L7F0E0314
   lui   $t3, %hi(ptr_spectrum_roms) 
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  lhu   $t5, 0x292($sp)
  li    $t1, 1
  addu  $t2, $t3, $t9
  sb    $t5, ($t2)
  lhu   $t8, 0x8a($sp)
  lui   $t3, %hi(ptr_300alloc) 
  lw    $t3, %lo(ptr_300alloc)($t3)
  andi  $t7, $t8, 0x1800
  sra   $t6, $t7, 3
  andi  $t0, $t8, 0xff
  or    $t4, $t6, $t0
  addu  $t9, $t3, $t4
  sb    $t1, ($t9)
.L7F0E0314:
  lhu   $t5, 0x8a($sp)
  lhu   $t3, 0x8a($sp)
  lhu   $t7, 0x292($sp)
  addiu $t2, $t5, 1
  slti  $at, $t2, 0x5b00
  bnez  $at, .L7F0E0348
   addiu $t4, $t3, 1
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  sra   $t8, $t7, 8
  addu  $t0, $t6, $t5
  b     .L7F0E27FC
   sb    $t8, 1($t0)
.L7F0E0348:
  slti  $at, $t4, 0x5800
  bnez  $at, .L7F0E0388
   lhu   $t4, 0x8a($sp)
  lui   $t2, %hi(ptr_spectrum_roms) 
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  lhu   $t1, 0x292($sp)
  lui   $t5, %hi(ptr_300alloc) 
  addu  $t7, $t2, $t3
  sra   $t9, $t1, 8
  sb    $t9, 1($t7)
  lhu   $t8, 0x8a($sp)
  lw    $t5, %lo(ptr_300alloc)($t5)
  li    $t6, 1
  addu  $t0, $t5, $t8
  b     .L7F0E27FC
   sb    $t6, -0x57ff($t0)
.L7F0E0388:
  addiu $t1, $t4, 1
  slti  $at, $t1, 0x4000
  bnez  $at, .L7F0E27FC
   lhu   $t2, 0x292($sp)
  lui   $t9, %hi(ptr_spectrum_roms) 
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  sra   $t3, $t2, 8
  li    $t5, 1
  addu  $t7, $t9, $t4
  sb    $t3, 1($t7)
  lhu   $t8, 0x8a($sp)
  lui   $t4, %hi(ptr_300alloc) 
  lw    $t4, %lo(ptr_300alloc)($t4)
  addiu $t6, $t8, 1
  andi  $t0, $t6, 0x1800
  sra   $t1, $t0, 3
  andi  $t2, $t6, 0xff
  or    $t9, $t1, $t2
  addu  $t3, $t4, $t9
  b     .L7F0E27FC
   sb    $t5, ($t3)
spectrum_op_ED_74:
  negu  $s0, $s0
  andi  $t0, $s0, 0xff
  lw    $t7, 0x28c($sp)
  sltiu $t6, $t0, 1
  andi  $t5, $t0, 0xf
  move  $s0, $t0
  andi  $t1, $t0, 0xa8
  addiu $t8, $t7, 4
  xori  $t0, $t0, 0x80
  slt   $t3, $zero, $t5
  sll   $t4, $t6, 6
  sw    $t8, 0x28c($sp)
  or    $t9, $t1, $t4
  sll   $t7, $t3, 4
  sltiu $t0, $t0, 1
  sw    $t6, 0x48($sp)
  sll   $t6, $t0, 2
  or    $t8, $t9, $t7
  or    $t2, $t8, $t6
  ori   $t1, $t2, 2
  slt   $t4, $zero, $s0
  or    $s1, $t1, $t4
  andi  $t5, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t5
spectrum_op_ED_75:
  lw    $t3, 0x28c($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  lhu   $t8, 0x292($sp)
  addiu $t9, $t3, 4
  sw    $t9, 0x28c($sp)
  addiu $t0, $t9, 6
  sw    $t0, 0x28c($sp)
  addu  $t4, $t6, $t8
  lbu   $t5, 1($t4)
  addu  $t2, $t8, $t6
  lbu   $t1, ($t2)
  sll   $t3, $t5, 8
  addiu $t7, $t8, 2
  or    $t9, $t1, $t3
  sh    $t9, 0x298($sp)
  b     .L7F0E27FC
   sh    $t7, 0x292($sp)
spectrum_op_ED_76:
  lw    $t0, 0x28c($sp)
  li    $t6, 2
  sb    $t6, 0x29b($sp)
  addiu $t2, $t0, 4
  b     .L7F0E27FC
   sw    $t2, 0x28c($sp)
spectrum_op_ED_78:
  lw    $t4, 0x28c($sp)
  move  $a1, $s2
  move  $a2, $s3
  addiu $a0, $t4, 8
  jal   spectrum_input_handling
   sw    $a0, 0x28c($sp)
  lw    $t1, 0x28c($sp)
  andi  $t3, $v0, 0xffff
  sra   $t9, $t3, 8
  sh    $v0, 0x88($sp)
  addu  $t8, $t1, $t9
  lbu   $s0, 0x89($sp)
  lui   $t1, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t1, %lo(ptr_pc_keyboard_table_alloc)($t1)
  sltiu $t7, $s0, 1
  sw    $t7, 0x48($sp)
  sw    $t8, 0x28c($sp)
  addu  $t9, $s0, $t1
  lbu   $t8, ($t9)
  andi  $t0, $s1, 1
  andi  $t2, $s0, 0xa8
  or    $t6, $t0, $t2
  sll   $t5, $t7, 6
  or    $t3, $t6, $t5
  or    $s1, $t8, $t3
  andi  $t7, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t7
spectrum_op_ED_79:
  lw    $t0, 0x28c($sp)
  move  $a1, $s2
  move  $a2, $s3
  addiu $a0, $t0, 8
  sw    $a0, 0x28c($sp)
  jal   sub_GAME_7F0D37DC
   move  $a3, $s0
  lw    $t4, 0x28c($sp)
  sw    $v0, 0x48($sp)
  addu  $t5, $t4, $v0
  b     .L7F0E27FC
   sw    $t5, 0x28c($sp)
spectrum_op_ED_7A:
  lhu   $t8, 0x292($sp)
  sll   $t3, $s6, 8
  lw    $t1, 0x28c($sp)
  or    $t7, $t3, $s7
  andi  $t2, $s1, 1
  addu  $t0, $t7, $t8
  addu  $t4, $t0, $t2
  addiu $t9, $t1, 0xb
  sw    $t9, 0x28c($sp)
  srl   $t1, $t4, 8
  andi  $t9, $t1, 0xa8
  andi  $t6, $t4, 0xffff
  srl   $t3, $t4, 0x10
  sll   $t0, $s6, 8
  or    $t2, $t0, $s7
  or    $t7, $t9, $t3
  sltiu $t5, $t6, 1
  andi  $t6, $t2, 0xfff
  andi  $t9, $t8, 0xfff
  addu  $t3, $t6, $t9
  andi  $t0, $s1, 1
  addu  $t2, $t3, $t0
  li    $at, 4095
  slt   $t6, $at, $t2
  sll   $t9, $t6, 4
  or    $t3, $t7, $t9
  sll   $t0, $s6, 8
  nor   $t2, $t0, $s7
  sll   $t7, $s6, 8
  or    $t9, $t7, $s7
  xor   $t0, $t9, $t4
  xor   $t6, $t2, $t8
  and   $t2, $t6, $t0
  sh    $t8, 0x86($sp)
  andi  $t8, $t2, 0x8000
  srl   $t7, $t8, 0xd
  sw    $t4, 0x80($sp)
  sll   $t4, $t5, 6
  or    $t9, $t3, $t7
  or    $s1, $t9, $t4
  ori   $t6, $s1, 2
  andi  $s1, $t6, 0xff
  lbu   $s7, 0x83($sp)
  andi  $s6, $t1, 0xff
  b     .L7F0E27FC
   sw    $t5, 0x48($sp)
spectrum_op_ED_7B:
  lw    $t2, 0x28c($sp)
  lui   $t7, %hi(ptr_spectrum_roms) 
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  lhu   $t3, 0x298($sp)
  addiu $t8, $t2, 0x10
  sw    $t8, 0x28c($sp)
  addu  $t4, $t7, $t3
  lbu   $t6, 1($t4)
  addu  $t5, $t3, $t7
  lbu   $t9, ($t5)
  sll   $t0, $t6, 8
  addiu $t2, $t3, 2
  or    $t1, $t9, $t0
  andi  $t8, $t1, 0xffff
  sh    $t1, 0x7e($sp)
  sh    $t2, 0x298($sp)
  addu  $t6, $t7, $t8
  lbu   $t9, 1($t6)
  addu  $t5, $t8, $t7
  lbu   $t4, ($t5)
  sll   $t0, $t9, 8
  or    $t1, $t4, $t0
  b     .L7F0E27FC
   sh    $t1, 0x292($sp)
spectrum_op_ED_7C:
  negu  $s0, $s0
  andi  $t5, $s0, 0xff
  lw    $t3, 0x28c($sp)
  sltiu $t7, $t5, 1
  andi  $t0, $t5, 0xf
  move  $s0, $t5
  andi  $t8, $t5, 0xa8
  addiu $t2, $t3, 4
  xori  $t5, $t5, 0x80
  slt   $t1, $zero, $t0
  sll   $t9, $t7, 6
  sw    $t2, 0x28c($sp)
  or    $t4, $t8, $t9
  sll   $t3, $t1, 4
  sltiu $t5, $t5, 1
  sw    $t7, 0x48($sp)
  sll   $t7, $t5, 2
  or    $t2, $t4, $t3
  or    $t6, $t2, $t7
  ori   $t8, $t6, 2
  slt   $t9, $zero, $s0
  or    $s1, $t8, $t9
  andi  $t0, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t0
spectrum_op_ED_7D:
  lw    $t1, 0x28c($sp)
  lui   $t7, %hi(ptr_spectrum_roms) 
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  lhu   $t2, 0x292($sp)
  addiu $t4, $t1, 4
  sw    $t4, 0x28c($sp)
  addiu $t5, $t4, 6
  sw    $t5, 0x28c($sp)
  addu  $t9, $t7, $t2
  lbu   $t0, 1($t9)
  addu  $t6, $t2, $t7
  lbu   $t8, ($t6)
  sll   $t1, $t0, 8
  addiu $t3, $t2, 2
  or    $t4, $t8, $t1
  sh    $t4, 0x298($sp)
  b     .L7F0E27FC
   sh    $t3, 0x292($sp)
spectrum_op_ED_7E:
  lw    $t5, 0x28c($sp)
  li    $t7, 3
  sb    $t7, 0x29b($sp)
  addiu $t6, $t5, 4
  b     .L7F0E27FC
   sw    $t6, 0x28c($sp)
spectrum_op_ED_A0:
  lw    $t9, 0x28c($sp)
  lui   $t4, %hi(ptr_spectrum_roms) 
  lw    $t4, %lo(ptr_spectrum_roms)($t4)
  sll   $t8, $s6, 8
  or    $t1, $t8, $s7
  addiu $t0, $t9, 0xc
  sw    $t0, 0x28c($sp)
  sll   $t5, $s4, 8
  addu  $t2, $t1, $t4
  lbu   $t3, ($t2)
  or    $t6, $t5, $s5
  slti  $at, $t6, 0x5b00
  bnez  $at, .L7F0E0770
   sb    $t3, 0x7d($sp)
  lui   $t9, %hi(ptr_spectrum_roms) 
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  sll   $t0, $s4, 8
  or    $t8, $t0, $s5
  addu  $t1, $t9, $t8
  b     .L7F0E0818
   sb    $t3, ($t1)
.L7F0E0770:
  sll   $t4, $s4, 8
  or    $t2, $t4, $s5
  slti  $at, $t2, 0x5800
  bnez  $at, .L7F0E07C0
   sll   $t6, $s4, 8
  lui   $t5, %hi(ptr_spectrum_roms) 
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  lbu   $t3, 0x7d($sp)
  sll   $t6, $s4, 8
  or    $t0, $t6, $s5
  addu  $t9, $t5, $t0
  lui   $t7, %hi(ptr_300alloc) 
  sb    $t3, ($t9)
  lw    $t7, %lo(ptr_300alloc)($t7)
  sll   $t1, $s4, 8
  or    $t4, $t1, $s5
  li    $t8, 1
  addu  $t2, $t7, $t4
  b     .L7F0E0818
   sb    $t8, -0x5800($t2)
.L7F0E07C0:
  or    $t5, $t6, $s5
  slti  $at, $t5, 0x4000
  bnez  $at, .L7F0E0818
   lbu   $t0, 0x7d($sp)
  lui   $t3, %hi(ptr_spectrum_roms) 
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  sll   $t9, $s4, 8
  or    $t1, $t9, $s5
  addu  $t7, $t3, $t1
  sb    $t0, ($t7)
  sll   $t8, $s4, 8
  or    $t2, $t8, $s5
  lui   $t7, %hi(ptr_300alloc) 
  lw    $t7, %lo(ptr_300alloc)($t7)
  andi  $t6, $t2, 0x1800
  or    $t3, $t9, $s5
  andi  $t1, $t3, 0xff
  sra   $t5, $t6, 3
  or    $t0, $t5, $t1
  li    $t4, 1
  addu  $t8, $t7, $t0
  sb    $t4, ($t8)
.L7F0E0818:
  addiu $s7, $s7, 1
  andi  $t2, $s7, 0xff
  bnez  $t2, .L7F0E0834
   move  $s7, $t2
  addiu $s6, $s6, 1
  andi  $t6, $s6, 0xff
  move  $s6, $t6
.L7F0E0834:
  addiu $s5, $s5, 1
  andi  $t9, $s5, 0xff
  bnez  $t9, .L7F0E0850
   move  $s5, $t9
  addiu $s4, $s4, 1
  andi  $t3, $s4, 0xff
  move  $s4, $t3
.L7F0E0850:
  sltiu $t5, $s3, 1
  addiu $s3, $s3, -1
  andi  $t1, $s3, 0xff
  move  $s3, $t1
  beqz  $t5, .L7F0E0874
   sw    $t5, 0x48($sp)
  addiu $s2, $s2, -1
  andi  $t0, $s2, 0xff
  move  $s2, $t0
.L7F0E0874:
  lbu   $t8, 0x7d($sp)
  or    $t9, $s2, $s3
  slt   $t3, $zero, $t9
  andi  $t4, $s1, 0xc1
  andi  $t2, $t8, 0x28
  or    $t6, $t4, $t2
  sll   $t5, $t3, 2
  or    $s1, $t6, $t5
  andi  $t1, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t1
spectrum_op_ED_A1:
  lw    $t7, 0x28c($sp)
  lui   $t9, %hi(ptr_spectrum_roms) 
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  sll   $t4, $s6, 8
  andi  $t8, $s1, 1
  or    $t2, $t4, $s7
  addiu $t0, $t7, 0xc
  sw    $t0, 0x28c($sp)
  sb    $t8, 0x7c($sp)
  addu  $t3, $t2, $t9
  lbu   $t6, ($t3)
  addiu $s7, $s7, 1
  subu  $t5, $s0, $t6
  andi  $t1, $t5, 0x1ff
  andi  $t7, $t1, 0xffff
  sltiu $t0, $t7, 1
  andi  $t7, $s0, 0xf
  andi  $t5, $t6, 0xf
  slt   $t8, $t7, $t5
  andi  $t4, $t1, 0xa8
  sra   $t9, $t1, 8
  or    $t3, $t4, $t9
  sll   $t2, $t8, 4
  move  $t5, $t1
  xor   $t9, $s0, $t6
  andi  $t7, $t9, 0x80
  xor   $t8, $t5, $s0
  or    $t4, $t3, $t2
  and   $t3, $t7, $t8
  sra   $t2, $t3, 5
  sb    $t6, 0x79($sp)
  or    $t6, $t4, $t2
  sh    $t1, 0x7a($sp)
  sll   $t1, $t0, 6
  ori   $t9, $t6, 2
  or    $s1, $t9, $t1
  andi  $t5, $s1, 0xff
  andi  $t7, $s7, 0xff
  move  $s1, $t5
  sw    $t0, 0x48($sp)
  bnez  $t7, .L7F0E0954
   move  $s7, $t7
  addiu $s6, $s6, 1
  andi  $t8, $s6, 0xff
  move  $s6, $t8
.L7F0E0954:
  sltiu $t3, $s3, 1
  addiu $s3, $s3, -1
  andi  $t4, $s3, 0xff
  move  $s3, $t4
  beqz  $t3, .L7F0E0978
   sw    $t3, 0x48($sp)
  addiu $s2, $s2, -1
  andi  $t6, $s2, 0xff
  move  $s2, $t6
.L7F0E0978:
  lbu   $t9, 0x7c($sp)
  or    $t5, $s2, $s3
  slt   $t7, $zero, $t5
  andi  $t0, $s1, 0xfa
  sll   $t8, $t7, 2
  or    $t1, $t0, $t9
  or    $s1, $t1, $t8
  andi  $t3, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t3
spectrum_op_ED_A2:
  lw    $t4, 0x28c($sp)
  move  $a1, $s2
  move  $a2, $s3
  addiu $a0, $t4, 0xc
  jal   spectrum_input_handling
   sw    $a0, 0x28c($sp)
  sll   $t6, $s6, 8
  or    $t0, $t6, $s7
  slti  $at, $t0, 0x5b00
  bnez  $at, .L7F0E09E8
   sh    $v0, 0x76($sp)
  lui   $t5, %hi(ptr_spectrum_roms) 
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  sll   $t7, $s6, 8
  or    $t1, $t7, $s7
  addu  $t8, $t5, $t1
  b     .L7F0E0A90
   sb    $v0, ($t8)
.L7F0E09E8:
  sll   $t3, $s6, 8
  or    $t4, $t3, $s7
  slti  $at, $t4, 0x5800
  bnez  $at, .L7F0E0A38
   sll   $t0, $s6, 8
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  lhu   $t2, 0x76($sp)
  sll   $t0, $s6, 8
  or    $t7, $t0, $s7
  addu  $t5, $t6, $t7
  lui   $t9, %hi(ptr_300alloc) 
  sb    $t2, ($t5)
  lw    $t9, %lo(ptr_300alloc)($t9)
  sll   $t8, $s6, 8
  or    $t3, $t8, $s7
  li    $t1, 1
  addu  $t4, $t9, $t3
  b     .L7F0E0A90
   sb    $t1, -0x5800($t4)
.L7F0E0A38:
  or    $t6, $t0, $s7
  slti  $at, $t6, 0x4000
  bnez  $at, .L7F0E0A90
   lhu   $t7, 0x76($sp)
  lui   $t2, %hi(ptr_spectrum_roms) 
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  sll   $t5, $s6, 8
  or    $t8, $t5, $s7
  addu  $t9, $t2, $t8
  sb    $t7, ($t9)
  sll   $t1, $s6, 8
  or    $t4, $t1, $s7
  lui   $t9, %hi(ptr_300alloc) 
  lw    $t9, %lo(ptr_300alloc)($t9)
  andi  $t0, $t4, 0x1800
  or    $t2, $t5, $s7
  andi  $t8, $t2, 0xff
  sra   $t6, $t0, 3
  or    $t7, $t6, $t8
  li    $t3, 1
  addu  $t1, $t9, $t7
  sb    $t3, ($t1)
.L7F0E0A90:
  lhu   $t0, 0x76($sp)
  lw    $t4, 0x28c($sp)
  addiu $s7, $s7, 1
  sra   $t5, $t0, 8
  andi  $t6, $s7, 0xff
  addu  $t2, $t4, $t5
  sw    $t2, 0x28c($sp)
  bnez  $t6, .L7F0E0AC0
   move  $s7, $t6
  addiu $s6, $s6, 1
  andi  $t8, $s6, 0xff
  move  $s6, $t8
.L7F0E0AC0:
  lui   $t5, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t5, %lo(ptr_pc_keyboard_table_alloc)($t5)
  addiu $s2, $s2, -1
  andi  $t9, $s2, 0xff
  addu  $t2, $t9, $t5
  lbu   $t6, ($t2)
  slt   $t3, $zero, $t9
  sll   $t1, $t3, 6
  andi  $t7, $t9, 0xa8
  move  $s2, $t9
  or    $t0, $t7, $t1
  xor   $t8, $t6, $s3
  andi  $t9, $t8, 4
  ori   $t4, $t0, 2
  or    $s1, $t9, $t4
  andi  $t3, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t3
spectrum_op_ED_A3:
  lw    $t7, 0x28c($sp)
  lui   $t2, %hi(ptr_spectrum_roms) 
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  sll   $t0, $s6, 8
  or    $t5, $t0, $s7
  addiu $a0, $t7, 0xc
  sw    $a0, 0x28c($sp)
  addu  $t6, $t5, $t2
  lbu   $a3, ($t6)
  move  $a1, $s2
  move  $a2, $s3
  jal   sub_GAME_7F0D37DC
   sb    $a3, 0x75($sp)
  lw    $t9, 0x28c($sp)
  addiu $s7, $s7, 1
  andi  $t7, $s7, 0xff
  addu  $t3, $t9, $v0
  sw    $t3, 0x28c($sp)
  sw    $v0, 0x48($sp)
  bnez  $t7, .L7F0E0B68
   move  $s7, $t7
  addiu $s6, $s6, 1
  andi  $t0, $s6, 0xff
  move  $s6, $t0
.L7F0E0B68:
  addiu $s2, $s2, -1
  andi  $t5, $s2, 0xff
  andi  $t2, $s1, 1
  ori   $t6, $t2, 0x12
  andi  $t1, $t5, 0xa8
  sltiu $t9, $t5, 1
  sll   $t4, $t9, 6
  or    $t8, $t6, $t1
  or    $s1, $t8, $t4
  andi  $t3, $s1, 0xff
  move  $s2, $t5
  b     .L7F0E27FC
   move  $s1, $t3
spectrum_op_ED_A8:
  lw    $t7, 0x28c($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  sll   $t5, $s6, 8
  or    $t2, $t5, $s7
  addiu $t0, $t7, 0xc
  sw    $t0, 0x28c($sp)
  sll   $t8, $s4, 8
  addu  $t1, $t2, $t6
  lbu   $t9, ($t1)
  or    $t4, $t8, $s5
  slti  $at, $t4, 0x5b00
  bnez  $at, .L7F0E0BF0
   sb    $t9, 0x74($sp)
  lui   $t7, %hi(ptr_spectrum_roms) 
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  sll   $t0, $s4, 8
  or    $t5, $t0, $s5
  addu  $t2, $t7, $t5
  b     .L7F0E0C98
   sb    $t9, ($t2)
.L7F0E0BF0:
  sll   $t6, $s4, 8
  or    $t1, $t6, $s5
  slti  $at, $t1, 0x5800
  bnez  $at, .L7F0E0C40
   sll   $t4, $s4, 8
  lui   $t8, %hi(ptr_spectrum_roms) 
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  lbu   $t9, 0x74($sp)
  sll   $t4, $s4, 8
  or    $t0, $t4, $s5
  addu  $t7, $t8, $t0
  lui   $t3, %hi(ptr_300alloc) 
  sb    $t9, ($t7)
  lw    $t3, %lo(ptr_300alloc)($t3)
  sll   $t2, $s4, 8
  or    $t6, $t2, $s5
  li    $t5, 1
  addu  $t1, $t3, $t6
  b     .L7F0E0C98
   sb    $t5, -0x5800($t1)
.L7F0E0C40:
  or    $t8, $t4, $s5
  slti  $at, $t8, 0x4000
  bnez  $at, .L7F0E0C98
   lbu   $t0, 0x74($sp)
  lui   $t9, %hi(ptr_spectrum_roms) 
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  sll   $t7, $s4, 8
  or    $t2, $t7, $s5
  addu  $t3, $t9, $t2
  sb    $t0, ($t3)
  sll   $t5, $s4, 8
  or    $t1, $t5, $s5
  lui   $t3, %hi(ptr_300alloc) 
  lw    $t3, %lo(ptr_300alloc)($t3)
  andi  $t4, $t1, 0x1800
  or    $t9, $t7, $s5
  andi  $t2, $t9, 0xff
  sra   $t8, $t4, 3
  or    $t0, $t8, $t2
  li    $t6, 1
  addu  $t5, $t3, $t0
  sb    $t6, ($t5)
.L7F0E0C98:
  sltiu $t1, $s7, 1
  addiu $s7, $s7, -1
  andi  $t4, $s7, 0xff
  move  $s7, $t4
  beqz  $t1, .L7F0E0CBC
   sw    $t1, 0x48($sp)
  addiu $s6, $s6, -1
  andi  $t9, $s6, 0xff
  move  $s6, $t9
.L7F0E0CBC:
  sltiu $t8, $s5, 1
  addiu $s5, $s5, -1
  andi  $t2, $s5, 0xff
  move  $s5, $t2
  beqz  $t8, .L7F0E0CE0
   sw    $t8, 0x48($sp)
  addiu $s4, $s4, -1
  andi  $t0, $s4, 0xff
  move  $s4, $t0
.L7F0E0CE0:
  sltiu $t6, $s3, 1
  addiu $s3, $s3, -1
  andi  $t5, $s3, 0xff
  move  $s3, $t5
  beqz  $t6, .L7F0E0D04
   sw    $t6, 0x48($sp)
  addiu $s2, $s2, -1
  andi  $t4, $s2, 0xff
  move  $s2, $t4
.L7F0E0D04:
  lbu   $t9, 0x74($sp)
  or    $t3, $s2, $s3
  slt   $t0, $zero, $t3
  andi  $t7, $s1, 0xc1
  andi  $t8, $t9, 0x28
  or    $t2, $t7, $t8
  sll   $t6, $t0, 2
  or    $s1, $t2, $t6
  andi  $t5, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t5
spectrum_op_ED_A9:
  lw    $t1, 0x28c($sp)
  lui   $t3, %hi(ptr_spectrum_roms) 
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  sll   $t7, $s6, 8
  andi  $t9, $s1, 1
  or    $t8, $t7, $s7
  addiu $t4, $t1, 0xc
  sw    $t4, 0x28c($sp)
  sb    $t9, 0x73($sp)
  addu  $t0, $t8, $t3
  lbu   $t2, ($t0)
  subu  $t6, $s0, $t2
  andi  $t5, $t6, 0x1ff
  andi  $t1, $t5, 0xffff
  sltiu $t4, $t1, 1
  andi  $t1, $s0, 0xf
  andi  $t6, $t2, 0xf
  slt   $t9, $t1, $t6
  andi  $t7, $t5, 0xa8
  sra   $t3, $t5, 8
  or    $t0, $t7, $t3
  sll   $t8, $t9, 4
  move  $t6, $t5
  xor   $t3, $s0, $t2
  andi  $t1, $t3, 0x80
  xor   $t9, $t6, $s0
  or    $t7, $t0, $t8
  and   $t0, $t1, $t9
  sra   $t8, $t0, 5
  sb    $t2, 0x6f($sp)
  or    $t2, $t7, $t8
  sh    $t5, 0x70($sp)
  sll   $t5, $t4, 6
  ori   $t3, $t2, 2
  sltiu $t1, $s7, 1
  or    $s1, $t3, $t5
  addiu $s7, $s7, -1
  andi  $t6, $s1, 0xff
  sw    $t4, 0x48($sp)
  andi  $t9, $s7, 0xff
  move  $s1, $t6
  move  $s7, $t9
  beqz  $t1, .L7F0E0DEC
   sw    $t1, 0x48($sp)
  addiu $s6, $s6, -1
  andi  $t7, $s6, 0xff
  move  $s6, $t7
.L7F0E0DEC:
  sltiu $t8, $s3, 1
  addiu $s3, $s3, -1
  andi  $t2, $s3, 0xff
  move  $s3, $t2
  beqz  $t8, .L7F0E0E10
   sw    $t8, 0x48($sp)
  addiu $s2, $s2, -1
  andi  $t3, $s2, 0xff
  move  $s2, $t3
.L7F0E0E10:
  lbu   $t6, 0x73($sp)
  or    $t9, $s2, $s3
  slt   $t0, $zero, $t9
  andi  $t5, $s1, 0xfa
  sll   $t7, $t0, 2
  or    $t1, $t5, $t6
  or    $s1, $t1, $t7
  andi  $t8, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t8
spectrum_op_ED_AA:
  lw    $t2, 0x28c($sp)
  move  $a1, $s2
  move  $a2, $s3
  addiu $a0, $t2, 0xc
  jal   spectrum_input_handling
   sw    $a0, 0x28c($sp)
  sll   $t3, $s6, 8
  or    $t5, $t3, $s7
  slti  $at, $t5, 0x5b00
  bnez  $at, .L7F0E0E80
   sh    $v0, 0x6c($sp)
  lui   $t9, %hi(ptr_spectrum_roms) 
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  sll   $t0, $s6, 8
  or    $t1, $t0, $s7
  addu  $t7, $t9, $t1
  b     .L7F0E0F28
   sb    $v0, ($t7)
.L7F0E0E80:
  sll   $t8, $s6, 8
  or    $t2, $t8, $s7
  slti  $at, $t2, 0x5800
  bnez  $at, .L7F0E0ED0
   sll   $t5, $s6, 8
  lui   $t3, %hi(ptr_spectrum_roms) 
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  lhu   $t4, 0x6c($sp)
  sll   $t5, $s6, 8
  or    $t0, $t5, $s7
  addu  $t9, $t3, $t0
  lui   $t6, %hi(ptr_300alloc) 
  sb    $t4, ($t9)
  lw    $t6, %lo(ptr_300alloc)($t6)
  sll   $t7, $s6, 8
  or    $t8, $t7, $s7
  li    $t1, 1
  addu  $t2, $t6, $t8
  b     .L7F0E0F28
   sb    $t1, -0x5800($t2)
.L7F0E0ED0:
  or    $t3, $t5, $s7
  slti  $at, $t3, 0x4000
  bnez  $at, .L7F0E0F28
   lhu   $t0, 0x6c($sp)
  lui   $t4, %hi(ptr_spectrum_roms) 
  lw    $t4, %lo(ptr_spectrum_roms)($t4)
  sll   $t9, $s6, 8
  or    $t7, $t9, $s7
  addu  $t6, $t4, $t7
  sb    $t0, ($t6)
  sll   $t1, $s6, 8
  or    $t2, $t1, $s7
  lui   $t6, %hi(ptr_300alloc) 
  lw    $t6, %lo(ptr_300alloc)($t6)
  andi  $t5, $t2, 0x1800
  or    $t4, $t9, $s7
  andi  $t7, $t4, 0xff
  sra   $t3, $t5, 3
  or    $t0, $t3, $t7
  li    $t8, 1
  addu  $t1, $t6, $t0
  sb    $t8, ($t1)
.L7F0E0F28:
  lhu   $t5, 0x6c($sp)
  lw    $t2, 0x28c($sp)
  sltiu $t3, $s7, 1
  addiu $s7, $s7, -1
  sra   $t9, $t5, 8
  andi  $t7, $s7, 0xff
  addu  $t4, $t2, $t9
  sw    $t4, 0x28c($sp)
  move  $s7, $t7
  beqz  $t3, .L7F0E0F60
   sw    $t3, 0x48($sp)
  addiu $s6, $s6, -1
  andi  $t0, $s6, 0xff
  move  $s6, $t0
.L7F0E0F60:
  lui   $t3, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t3, %lo(ptr_pc_keyboard_table_alloc)($t3)
  addiu $s2, $s2, -1
  andi  $t8, $s2, 0xff
  addu  $t7, $t8, $t3
  lbu   $t6, ($t7)
  andi  $t1, $t8, 0xa8
  slt   $t5, $zero, $t8
  move  $s2, $t8
  sll   $t2, $t5, 6
  xor   $t0, $t6, $s3
  xori  $t8, $t0, 4
  or    $t9, $t1, $t2
  ori   $t4, $t9, 2
  andi  $t5, $t8, 4
  or    $s1, $t5, $t4
  andi  $t1, $s1, 0xff
  b     .L7F0E27FC
   move  $s1, $t1
spectrum_op_ED_AB:
  lw    $t2, 0x28c($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  sll   $t3, $s6, 8
  or    $t7, $t3, $s7
  addiu $a0, $t2, 0xc
  sw    $a0, 0x28c($sp)
  addu  $t0, $t7, $t6
  lbu   $a3, ($t0)
  move  $a1, $s2
  move  $a2, $s3
  jal   sub_GAME_7F0D37DC
   sb    $a3, 0x6b($sp)
  lw    $t5, 0x28c($sp)
  sltiu $t2, $s7, 1
  addiu $s7, $s7, -1
  sw    $v0, 0x48($sp)
  andi  $t3, $s7, 0xff
  addu  $t1, $t5, $v0
  sw    $t1, 0x28c($sp)
  move  $s7, $t3
  beqz  $t2, .L7F0E1014
   sw    $t2, 0x48($sp)
  addiu $s6, $s6, -1
  andi  $t6, $s6, 0xff
  move  $s6, $t6
.L7F0E1014:
  addiu $s2, $s2, -1
  andi  $t0, $s2, 0xff
  andi  $t9, $s1, 1
  ori   $t8, $t9, 0x12
  andi  $t5, $t0, 0xa8
  sltiu $t1, $t0, 1
  sll   $t2, $t1, 6
  or    $t4, $t8, $t5
  or    $s1, $t4, $t2
  andi  $t3, $s1, 0xff
  move  $s2, $t0
  b     .L7F0E27FC
   move  $s1, $t3
spectrum_op_ED_B0:
  lw    $t7, 0x28c($sp)
  lui   $t8, %hi(ptr_spectrum_roms) 
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  sll   $t0, $s6, 8
  or    $t9, $t0, $s7
  addiu $t6, $t7, 0xc
  sw    $t6, 0x28c($sp)
  sll   $t4, $s4, 8
  addu  $t5, $t9, $t8
  lbu   $t1, ($t5)
  or    $t2, $t4, $s5
  slti  $at, $t2, 0x5b00
  bnez  $at, .L7F0E109C
   sb    $t1, 0x6a($sp)
  lui   $t7, %hi(ptr_spectrum_roms) 
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  sll   $t6, $s4, 8
  or    $t0, $t6, $s5
  addu  $t9, $t7, $t0
  b     .L7F0E1144
   sb    $t1, ($t9)
.L7F0E109C:
  sll   $t8, $s4, 8
  or    $t5, $t8, $s5
  slti  $at, $t5, 0x5800
  bnez  $at, .L7F0E10EC
   sll   $t2, $s4, 8
  lui   $t4, %hi(ptr_spectrum_roms) 
  lw    $t4, %lo(ptr_spectrum_roms)($t4)
  lbu   $t1, 0x6a($sp)
  sll   $t2, $s4, 8
  or    $t6, $t2, $s5
  addu  $t7, $t4, $t6
  lui   $t3, %hi(ptr_300alloc) 
  sb    $t1, ($t7)
  lw    $t3, %lo(ptr_300alloc)($t3)
  sll   $t9, $s4, 8
  or    $t8, $t9, $s5
  li    $t0, 1
  addu  $t5, $t3, $t8
  b     .L7F0E1144
   sb    $t0, -0x5800($t5)
.L7F0E10EC:
  or    $t4, $t2, $s5
  slti  $at, $t4, 0x4000
  bnez  $at, .L7F0E1144
   lbu   $t6, 0x6a($sp)
  lui   $t1, %hi(ptr_spectrum_roms) 
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  sll   $t7, $s4, 8
  or    $t9, $t7, $s5
  addu  $t3, $t1, $t9
  sb    $t6, ($t3)
  sll   $t0, $s4, 8
  or    $t5, $t0, $s5
  lui   $t3, %hi(ptr_300alloc) 
  lw    $t3, %lo(ptr_300alloc)($t3)
  andi  $t2, $t5, 0x1800
  or    $t1, $t7, $s5
  andi  $t9, $t1, 0xff
  sra   $t4, $t2, 3
  or    $t6, $t4, $t9
  li    $t8, 1
  addu  $t0, $t3, $t6
  sb    $t8, ($t0)
.L7F0E1144:
  addiu $s7, $s7, 1
  andi  $t5, $s7, 0xff
  bnez  $t5, .L7F0E1160
   move  $s7, $t5
  addiu $s6, $s6, 1
  andi  $t2, $s6, 0xff
  move  $s6, $t2
.L7F0E1160:
  addiu $s5, $s5, 1
  andi  $t7, $s5, 0xff
  bnez  $t7, .L7F0E117C
   move  $s5, $t7
  addiu $s4, $s4, 1
  andi  $t1, $s4, 0xff
  move  $s4, $t1
.L7F0E117C:
  sltiu $t4, $s3, 1
  addiu $s3, $s3, -1
  andi  $t9, $s3, 0xff
  move  $s3, $t9
  beqz  $t4, .L7F0E11A0
   sw    $t4, 0x48($sp)
  addiu $s2, $s2, -1
  andi  $t6, $s2, 0xff
  move  $s2, $t6
.L7F0E11A0:
  lbu   $t0, 0x6a($sp)
  or    $t7, $s2, $s3
  slt   $t1, $zero, $t7
  andi  $t8, $s1, 0xc1
  andi  $t5, $t0, 0x28
  or    $t2, $t8, $t5
  sll   $t4, $t1, 2
  or    $s1, $t2, $t4
  andi  $t9, $s1, 0xff
  or    $t3, $s2, $s3
  beqz  $t3, .L7F0E27FC
   move  $s1, $t9
  lhu   $t6, 0x298($sp)
  lw    $t8, 0x28c($sp)
  addiu $t0, $t6, -2
  addiu $t5, $t8, 5
  sw    $t5, 0x28c($sp)
  b     .L7F0E27FC
   sh    $t0, 0x298($sp)
spectrum_op_ED_B1:
  lw    $t7, 0x28c($sp)
  lui   $t3, %hi(ptr_spectrum_roms) 
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  sll   $t4, $s6, 8
  andi  $t2, $s1, 1
  or    $t9, $t4, $s7
  addiu $t1, $t7, 0xc
  sw    $t1, 0x28c($sp)
  sb    $t2, 0x69($sp)
  addu  $t6, $t9, $t3
  lbu   $t0, ($t6)
  addiu $s7, $s7, 1
  li    $at, 4
  subu  $t8, $s0, $t0
  andi  $t5, $t8, 0x1ff
  andi  $t7, $t5, 0xffff
  sltiu $t1, $t7, 1
  andi  $t7, $s0, 0xf
  andi  $t8, $t0, 0xf
  slt   $t2, $t7, $t8
  andi  $t4, $t5, 0xa8
  sra   $t3, $t5, 8
  or    $t6, $t4, $t3
  sll   $t9, $t2, 4
  move  $t8, $t5
  xor   $t3, $s0, $t0
  andi  $t7, $t3, 0x80
  xor   $t2, $t8, $s0
  or    $t4, $t6, $t9
  and   $t6, $t7, $t2
  sra   $t9, $t6, 5
  sb    $t0, 0x65($sp)
  or    $t0, $t4, $t9
  sh    $t5, 0x66($sp)
  sll   $t5, $t1, 6
  ori   $t3, $t0, 2
  or    $s1, $t3, $t5
  andi  $t8, $s1, 0xff
  andi  $t7, $s7, 0xff
  move  $s1, $t8
  sw    $t1, 0x48($sp)
  bnez  $t7, .L7F0E12A4
   move  $s7, $t7
  addiu $s6, $s6, 1
  andi  $t2, $s6, 0xff
  move  $s6, $t2
.L7F0E12A4:
  sltiu $t6, $s3, 1
  addiu $s3, $s3, -1
  andi  $t4, $s3, 0xff
  move  $s3, $t4
  beqz  $t6, .L7F0E12C8
   sw    $t6, 0x48($sp)
  addiu $s2, $s2, -1
  andi  $t0, $s2, 0xff
  move  $s2, $t0
.L7F0E12C8:
  lbu   $t3, 0x69($sp)
  or    $t8, $s2, $s3
  slt   $t7, $zero, $t8
  andi  $t1, $s1, 0xfa
  sll   $t2, $t7, 2
  or    $t5, $t1, $t3
  or    $s1, $t5, $t2
  andi  $t6, $s1, 0xff
  andi  $t4, $t6, 0x44
  bne   $t4, $at, .L7F0E27FC
   move  $s1, $t6
  lhu   $t9, 0x298($sp)
  lw    $t1, 0x28c($sp)
  addiu $t0, $t9, -2
  addiu $t3, $t1, 5
  sw    $t3, 0x28c($sp)
  b     .L7F0E27FC
   sh    $t0, 0x298($sp)
spectrum_op_ED_B2:
  lw    $t8, 0x28c($sp)
  move  $a1, $s2
  move  $a2, $s3
  addiu $a0, $t8, 0xc
  jal   spectrum_input_handling
   sw    $a0, 0x28c($sp)
  sll   $t5, $s6, 8
  or    $t2, $t5, $s7
  slti  $at, $t2, 0x5b00
  bnez  $at, .L7F0E1358
   sh    $v0, 0x62($sp)
  lui   $t4, %hi(ptr_spectrum_roms) 
  lw    $t4, %lo(ptr_spectrum_roms)($t4)
  sll   $t9, $s6, 8
  or    $t0, $t9, $s7
  addu  $t1, $t4, $t0
  b     .L7F0E1400
   sb    $v0, ($t1)
.L7F0E1358:
  sll   $t3, $s6, 8
  or    $t8, $t3, $s7
  slti  $at, $t8, 0x5800
  bnez  $at, .L7F0E13A8
   sll   $t2, $s6, 8
  lui   $t5, %hi(ptr_spectrum_roms) 
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  lhu   $t7, 0x62($sp)
  sll   $t2, $s6, 8
  or    $t9, $t2, $s7
  addu  $t4, $t5, $t9
  lui   $t6, %hi(ptr_300alloc) 
  sb    $t7, ($t4)
  lw    $t6, %lo(ptr_300alloc)($t6)
  sll   $t1, $s6, 8
  or    $t3, $t1, $s7
  li    $t0, 1
  addu  $t8, $t6, $t3
  b     .L7F0E1400
   sb    $t0, -0x5800($t8)
.L7F0E13A8:
  or    $t5, $t2, $s7
  slti  $at, $t5, 0x4000
  bnez  $at, .L7F0E1400
   lhu   $t9, 0x62($sp)
  lui   $t7, %hi(ptr_spectrum_roms) 
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  sll   $t4, $s6, 8
  or    $t1, $t4, $s7
  addu  $t6, $t7, $t1
  sb    $t9, ($t6)
  sll   $t0, $s6, 8
  or    $t8, $t0, $s7
  lui   $t6, %hi(ptr_300alloc) 
  lw    $t6, %lo(ptr_300alloc)($t6)
  andi  $t2, $t8, 0x1800
  or    $t7, $t4, $s7
  andi  $t1, $t7, 0xff
  sra   $t5, $t2, 3
  or    $t9, $t5, $t1
  li    $t3, 1
  addu  $t0, $t6, $t9
  sb    $t3, ($t0)
.L7F0E1400:
  lhu   $t2, 0x62($sp)
  lw    $t8, 0x28c($sp)
  addiu $s7, $s7, 1
  sra   $t4, $t2, 8
  andi  $t5, $s7, 0xff
  addu  $t7, $t8, $t4
  sw    $t7, 0x28c($sp)
  bnez  $t5, .L7F0E1430
   move  $s7, $t5
  addiu $s6, $s6, 1
  andi  $t1, $s6, 0xff
  move  $s6, $t1
.L7F0E1430:
  lui   $t4, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t4, %lo(ptr_pc_keyboard_table_alloc)($t4)
  addiu $s2, $s2, -1
  andi  $t6, $s2, 0xff
  addu  $t7, $t6, $t4
  lbu   $t5, ($t7)
  slt   $t3, $zero, $t6
  sll   $t0, $t3, 6
  andi  $t9, $t6, 0xa8
  move  $s2, $t6
  or    $t2, $t9, $t0
  xor   $t1, $t5, $s3
  andi  $t6, $t1, 4
  ori   $t8, $t2, 2
  or    $s1, $t6, $t8
  andi  $t3, $s1, 0xff
  beqz  $s2, .L7F0E27FC
   move  $s1, $t3
  lhu   $t9, 0x298($sp)
  lw    $t2, 0x28c($sp)
  addiu $t0, $t9, -2
  addiu $t4, $t2, 5
  sw    $t4, 0x28c($sp)
  b     .L7F0E27FC
   sh    $t0, 0x298($sp)
spectrum_op_ED_B3:
  lw    $t7, 0x28c($sp)
  lui   $t8, %hi(ptr_spectrum_roms) 
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  sll   $t1, $s6, 8
  or    $t6, $t1, $s7
  addiu $a0, $t7, 0xc
  sw    $a0, 0x28c($sp)
  addu  $t3, $t6, $t8
  lbu   $a3, ($t3)
  move  $a1, $s2
  move  $a2, $s3
  jal   sub_GAME_7F0D37DC
   sb    $a3, 0x61($sp)
  lw    $t0, 0x28c($sp)
  addiu $s7, $s7, 1
  andi  $t7, $s7, 0xff
  addu  $t4, $t0, $v0
  sw    $t4, 0x28c($sp)
  sw    $v0, 0x48($sp)
  bnez  $t7, .L7F0E14F4
   move  $s7, $t7
  addiu $s6, $s6, 1
  andi  $t1, $s6, 0xff
  move  $s6, $t1
.L7F0E14F4:
  addiu $s2, $s2, -1
  andi  $t6, $s2, 0xff
  andi  $t8, $s1, 1
  ori   $t3, $t8, 0x12
  andi  $t5, $t6, 0xa8
  sltiu $t0, $t6, 1
  sll   $t2, $t0, 6
  or    $t9, $t3, $t5
  or    $s1, $t9, $t2
  andi  $t4, $s1, 0xff
  move  $s2, $t6
  beqz  $t6, .L7F0E27FC
   move  $s1, $t4
  lhu   $t7, 0x298($sp)
  lw    $t6, 0x28c($sp)
  addiu $t1, $t7, -2
  addiu $t8, $t6, 5
  sw    $t8, 0x28c($sp)
  b     .L7F0E27FC
   sh    $t1, 0x298($sp)
spectrum_op_ED_B8:
  lw    $t3, 0x28c($sp)
  lui   $t2, %hi(ptr_spectrum_roms) 
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  sll   $t0, $s6, 8
  or    $t9, $t0, $s7
  addiu $t5, $t3, 0xc
  sw    $t5, 0x28c($sp)
  sll   $t1, $s4, 8
  addu  $t4, $t9, $t2
  lbu   $t7, ($t4)
  or    $t6, $t1, $s5
  slti  $at, $t6, 0x5b00
  bnez  $at, .L7F0E1598
   sb    $t7, 0x60($sp)
  lui   $t3, %hi(ptr_spectrum_roms) 
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  sll   $t5, $s4, 8
  or    $t0, $t5, $s5
  addu  $t9, $t3, $t0
  b     .L7F0E1640
   sb    $t7, ($t9)
.L7F0E1598:
  sll   $t2, $s4, 8
  or    $t4, $t2, $s5
  slti  $at, $t4, 0x5800
  bnez  $at, .L7F0E15E8
   sll   $t6, $s4, 8
  lui   $t1, %hi(ptr_spectrum_roms) 
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  lbu   $t7, 0x60($sp)
  sll   $t6, $s4, 8
  or    $t5, $t6, $s5
  addu  $t3, $t1, $t5
  lui   $t8, %hi(ptr_300alloc) 
  sb    $t7, ($t3)
  lw    $t8, %lo(ptr_300alloc)($t8)
  sll   $t9, $s4, 8
  or    $t2, $t9, $s5
  li    $t0, 1
  addu  $t4, $t8, $t2
  b     .L7F0E1640
   sb    $t0, -0x5800($t4)
.L7F0E15E8:
  or    $t1, $t6, $s5
  slti  $at, $t1, 0x4000
  bnez  $at, .L7F0E1640
   lbu   $t5, 0x60($sp)
  lui   $t7, %hi(ptr_spectrum_roms) 
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  sll   $t3, $s4, 8
  or    $t9, $t3, $s5
  addu  $t8, $t7, $t9
  sb    $t5, ($t8)
  sll   $t0, $s4, 8
  or    $t4, $t0, $s5
  lui   $t8, %hi(ptr_300alloc) 
  lw    $t8, %lo(ptr_300alloc)($t8)
  andi  $t6, $t4, 0x1800
  or    $t7, $t3, $s5
  andi  $t9, $t7, 0xff
  sra   $t1, $t6, 3
  or    $t5, $t1, $t9
  li    $t2, 1
  addu  $t0, $t8, $t5
  sb    $t2, ($t0)
.L7F0E1640:
  sltiu $t4, $s7, 1
  addiu $s7, $s7, -1
  andi  $t6, $s7, 0xff
  move  $s7, $t6
  beqz  $t4, .L7F0E1664
   sw    $t4, 0x48($sp)
  addiu $s6, $s6, -1
  andi  $t7, $s6, 0xff
  move  $s6, $t7
.L7F0E1664:
  sltiu $t1, $s5, 1
  addiu $s5, $s5, -1
  andi  $t9, $s5, 0xff
  move  $s5, $t9
  beqz  $t1, .L7F0E1688
   sw    $t1, 0x48($sp)
  addiu $s4, $s4, -1
  andi  $t5, $s4, 0xff
  move  $s4, $t5
.L7F0E1688:
  sltiu $t2, $s3, 1
  addiu $s3, $s3, -1
  andi  $t0, $s3, 0xff
  move  $s3, $t0
  beqz  $t2, .L7F0E16AC
   sw    $t2, 0x48($sp)
  addiu $s2, $s2, -1
  andi  $t6, $s2, 0xff
  move  $s2, $t6
.L7F0E16AC:
  lbu   $t7, 0x60($sp)
  or    $t8, $s2, $s3
  slt   $t5, $zero, $t8
  andi  $t3, $s1, 0xc1
  andi  $t1, $t7, 0x28
  or    $t9, $t3, $t1
  sll   $t2, $t5, 2
  or    $s1, $t9, $t2
  andi  $t0, $s1, 0xff
  or    $t4, $s2, $s3
  beqz  $t4, .L7F0E27FC
   move  $s1, $t0
  lhu   $t6, 0x298($sp)
  lw    $t3, 0x28c($sp)
  addiu $t7, $t6, -2
  addiu $t1, $t3, 5
  sw    $t1, 0x28c($sp)
  b     .L7F0E27FC
   sh    $t7, 0x298($sp)
spectrum_op_ED_B9:
  lw    $t8, 0x28c($sp)
  lui   $t4, %hi(ptr_spectrum_roms) 
  lw    $t4, %lo(ptr_spectrum_roms)($t4)
  sll   $t2, $s6, 8
  andi  $t9, $s1, 1
  or    $t0, $t2, $s7
  addiu $t5, $t8, 0xc
  sw    $t5, 0x28c($sp)
  sb    $t9, 0x5f($sp)
  addu  $t6, $t0, $t4
  lbu   $t7, ($t6)
  li    $at, 4
  subu  $t3, $s0, $t7
  andi  $t1, $t3, 0x1ff
  andi  $t8, $t1, 0xffff
  sltiu $t5, $t8, 1
  andi  $t8, $s0, 0xf
  andi  $t3, $t7, 0xf
  slt   $t9, $t8, $t3
  andi  $t2, $t1, 0xa8
  sra   $t4, $t1, 8
  or    $t6, $t2, $t4
  sll   $t0, $t9, 4
  move  $t3, $t1
  xor   $t4, $s0, $t7
  andi  $t8, $t4, 0x80
  xor   $t9, $t3, $s0
  or    $t2, $t6, $t0
  and   $t6, $t8, $t9
  sra   $t0, $t6, 5
  sb    $t7, 0x5b($sp)
  or    $t7, $t2, $t0
  sh    $t1, 0x5c($sp)
  sll   $t1, $t5, 6
  ori   $t4, $t7, 2
  sltiu $t8, $s7, 1
  or    $s1, $t4, $t1
  addiu $s7, $s7, -1
  andi  $t3, $s1, 0xff
  sw    $t5, 0x48($sp)
  andi  $t9, $s7, 0xff
  move  $s1, $t3
  move  $s7, $t9
  beqz  $t8, .L7F0E17B8
   sw    $t8, 0x48($sp)
  addiu $s6, $s6, -1
  andi  $t2, $s6, 0xff
  move  $s6, $t2
.L7F0E17B8:
  sltiu $t0, $s3, 1
  addiu $s3, $s3, -1
  andi  $t7, $s3, 0xff
  move  $s3, $t7
  beqz  $t0, .L7F0E17DC
   sw    $t0, 0x48($sp)
  addiu $s2, $s2, -1
  andi  $t4, $s2, 0xff
  move  $s2, $t4
.L7F0E17DC:
  lbu   $t3, 0x5f($sp)
  or    $t9, $s2, $s3
  slt   $t6, $zero, $t9
  andi  $t1, $s1, 0xfa
  sll   $t2, $t6, 2
  or    $t8, $t1, $t3
  or    $s1, $t8, $t2
  andi  $t0, $s1, 0xff
  andi  $t7, $t0, 0x44
  bne   $t7, $at, .L7F0E27FC
   move  $s1, $t0
  lhu   $t5, 0x298($sp)
  lw    $t1, 0x28c($sp)
  addiu $t4, $t5, -2
  addiu $t3, $t1, 5
  sw    $t3, 0x28c($sp)
  b     .L7F0E27FC
   sh    $t4, 0x298($sp)
spectrum_op_ED_BA:
  lw    $t9, 0x28c($sp)
  move  $a1, $s2
  move  $a2, $s3
  addiu $a0, $t9, 0xc
  jal   spectrum_input_handling
   sw    $a0, 0x28c($sp)
  sll   $t8, $s6, 8
  or    $t2, $t8, $s7
  slti  $at, $t2, 0x5b00
  bnez  $at, .L7F0E186C
   sh    $v0, 0x58($sp)
  lui   $t7, %hi(ptr_spectrum_roms) 
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  sll   $t5, $s6, 8
  or    $t4, $t5, $s7
  addu  $t1, $t7, $t4
  b     .L7F0E1914
   sb    $v0, ($t1)
.L7F0E186C:
  sll   $t3, $s6, 8
  or    $t9, $t3, $s7
  slti  $at, $t9, 0x5800
  bnez  $at, .L7F0E18BC
   sll   $t2, $s6, 8
  lui   $t8, %hi(ptr_spectrum_roms) 
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  lhu   $t6, 0x58($sp)
  sll   $t2, $s6, 8
  or    $t5, $t2, $s7
  addu  $t7, $t8, $t5
  lui   $t0, %hi(ptr_300alloc) 
  sb    $t6, ($t7)
  lw    $t0, %lo(ptr_300alloc)($t0)
  sll   $t1, $s6, 8
  or    $t3, $t1, $s7
  li    $t4, 1
  addu  $t9, $t0, $t3
  b     .L7F0E1914
   sb    $t4, -0x5800($t9)
.L7F0E18BC:
  or    $t8, $t2, $s7
  slti  $at, $t8, 0x4000
  bnez  $at, .L7F0E1914
   lhu   $t5, 0x58($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  sll   $t7, $s6, 8
  or    $t1, $t7, $s7
  addu  $t0, $t6, $t1
  sb    $t5, ($t0)
  sll   $t4, $s6, 8
  or    $t9, $t4, $s7
  lui   $t0, %hi(ptr_300alloc) 
  lw    $t0, %lo(ptr_300alloc)($t0)
  andi  $t2, $t9, 0x1800
  or    $t6, $t7, $s7
  andi  $t1, $t6, 0xff
  sra   $t8, $t2, 3
  or    $t5, $t8, $t1
  li    $t3, 1
  addu  $t4, $t0, $t5
  sb    $t3, ($t4)
.L7F0E1914:
  lhu   $t2, 0x58($sp)
  lw    $t9, 0x28c($sp)
  sltiu $t8, $s7, 1
  addiu $s7, $s7, -1
  sra   $t7, $t2, 8
  andi  $t1, $s7, 0xff
  addu  $t6, $t9, $t7
  sw    $t6, 0x28c($sp)
  move  $s7, $t1
  beqz  $t8, .L7F0E194C
   sw    $t8, 0x48($sp)
  addiu $s6, $s6, -1
  andi  $t5, $s6, 0xff
  move  $s6, $t5
.L7F0E194C:
  lui   $t8, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t8, %lo(ptr_pc_keyboard_table_alloc)($t8)
  addiu $s2, $s2, -1
  andi  $t3, $s2, 0xff
  addu  $t1, $t3, $t8
  lbu   $t0, ($t1)
  andi  $t4, $t3, 0xa8
  slt   $t2, $zero, $t3
  move  $s2, $t3
  sll   $t9, $t2, 6
  xor   $t5, $t0, $s3
  xori  $t3, $t5, 4
  or    $t7, $t4, $t9
  ori   $t6, $t7, 2
  andi  $t2, $t3, 4
  or    $s1, $t2, $t6
  andi  $t4, $s1, 0xff
  beqz  $s2, .L7F0E27FC
   move  $s1, $t4
  lhu   $t9, 0x298($sp)
  lw    $t8, 0x28c($sp)
  addiu $t7, $t9, -2
  addiu $t1, $t8, 5
  sw    $t1, 0x28c($sp)
  b     .L7F0E27FC
   sh    $t7, 0x298($sp)
spectrum_op_ED_BB:
  lw    $t0, 0x28c($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  sll   $t3, $s6, 8
  or    $t2, $t3, $s7
  addiu $a0, $t0, 0xc
  sw    $a0, 0x28c($sp)
  addu  $t4, $t2, $t6
  lbu   $a3, ($t4)
  move  $a1, $s2
  move  $a2, $s3
  jal   sub_GAME_7F0D37DC
   sb    $a3, 0x57($sp)
  lw    $t7, 0x28c($sp)
  sltiu $t0, $s7, 1
  addiu $s7, $s7, -1
  sw    $v0, 0x48($sp)
  andi  $t3, $s7, 0xff
  addu  $t1, $t7, $v0
  sw    $t1, 0x28c($sp)
  move  $s7, $t3
  beqz  $t0, .L7F0E1A1C
   sw    $t0, 0x48($sp)
  addiu $s6, $s6, -1
  andi  $t6, $s6, 0xff
  move  $s6, $t6
.L7F0E1A1C:
  addiu $s2, $s2, -1
  andi  $t4, $s2, 0xff
  andi  $t5, $s1, 1
  ori   $t9, $t5, 0x12
  andi  $t7, $t4, 0xa8
  sltiu $t1, $t4, 1
  sll   $t0, $t1, 6
  or    $t8, $t9, $t7
  or    $s1, $t8, $t0
  andi  $t3, $s1, 0xff
  move  $s2, $t4
  beqz  $t4, .L7F0E27FC
   move  $s1, $t3
  lhu   $t2, 0x298($sp)
  lw    $t4, 0x28c($sp)
  addiu $t6, $t2, -2
  addiu $t5, $t4, 5
  sw    $t5, 0x28c($sp)
  b     .L7F0E27FC
   sh    $t6, 0x298($sp)
.L7F0E1A6C:
  lw    $t9, 0x28c($sp)
  addiu $t7, $t9, 4
  b     .L7F0E27FC
   sw    $t7, 0x28c($sp)
spectrum_op_EE:
  lw    $t1, 0x28c($sp)
  lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  lhu   $t3, 0x298($sp)
  addiu $t8, $t1, 7
  sw    $t8, 0x28c($sp)
  addu  $t2, $t0, $t3
  lbu   $t6, ($t2)
  lui   $t0, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t0, %lo(ptr_pc_keyboard_table_alloc)($t0)
  xor   $s0, $s0, $t6
  andi  $t4, $s0, 0xff
  sltiu $t5, $t4, 1
  sw    $t5, 0x48($sp)
  addu  $t3, $t4, $t0
  lbu   $t2, ($t3)
  move  $s0, $t4
  andi  $t9, $t4, 0xa8
  lhu   $t4, 0x298($sp)
  sll   $t1, $t5, 6
  or    $t8, $t9, $t1
  or    $s1, $t2, $t8
  andi  $t6, $s1, 0xff
  addiu $t5, $t4, 1
  move  $s1, $t6
  b     .L7F0E27FC
   sh    $t5, 0x298($sp)
spectrum_op_EF:
  lhu   $t1, 0x292($sp)
  lw    $t7, 0x28c($sp)
  lui   $t8, %hi(ptr_spectrum_roms) 
  addiu $t0, $t1, -2
  andi  $t3, $t0, 0xffff
  slti  $at, $t3, 0x5b00
  addiu $t9, $t7, 0xb
  sw    $t9, 0x28c($sp)
  bnez  $at, .L7F0E1B24
   sh    $t0, 0x292($sp)
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  lhu   $t2, 0x298($sp)
  addu  $t6, $t8, $t3
  b     .L7F0E1BAC
   sb    $t2, ($t6)
.L7F0E1B24:
  lhu   $t4, 0x292($sp)
  lhu   $t2, 0x292($sp)
  lui   $t7, %hi(ptr_spectrum_roms) 
  slti  $at, $t4, 0x5800
  bnezl $at, .L7F0E1B6C
   slti  $at, $t2, 0x4000
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  lhu   $t5, 0x298($sp)
  lui   $t0, %hi(ptr_300alloc) 
  addu  $t9, $t7, $t4
  sb    $t5, ($t9)
  lhu   $t8, 0x292($sp)
  lw    $t0, %lo(ptr_300alloc)($t0)
  li    $t1, 1
  addu  $t3, $t0, $t8
  b     .L7F0E1BAC
   sb    $t1, -0x5800($t3)
  slti  $at, $t2, 0x4000
.L7F0E1B6C:
  bnez  $at, .L7F0E1BAC
   lui   $t7, %hi(ptr_spectrum_roms) 
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  lhu   $t6, 0x298($sp)
  li    $t5, 1
  addu  $t4, $t7, $t2
  sb    $t6, ($t4)
  lhu   $t9, 0x292($sp)
  lui   $t7, %hi(ptr_300alloc) 
  lw    $t7, %lo(ptr_300alloc)($t7)
  andi  $t0, $t9, 0x1800
  sra   $t8, $t0, 3
  andi  $t1, $t9, 0xff
  or    $t3, $t8, $t1
  addu  $t2, $t7, $t3
  sb    $t5, ($t2)
.L7F0E1BAC:
  lhu   $t6, 0x292($sp)
  lhu   $t7, 0x292($sp)
  lhu   $t0, 0x298($sp)
  addiu $t4, $t6, 1
  slti  $at, $t4, 0x5b00
  bnez  $at, .L7F0E1BE0
   addiu $t3, $t7, 1
  lui   $t8, %hi(ptr_spectrum_roms) 
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  sra   $t9, $t0, 8
  addu  $t1, $t8, $t6
  b     .L7F0E1C70
   sb    $t9, 1($t1)
.L7F0E1BE0:
  slti  $at, $t3, 0x5800
  bnez  $at, .L7F0E1C20
   lhu   $t3, 0x292($sp)
  lui   $t4, %hi(ptr_spectrum_roms) 
  lw    $t4, %lo(ptr_spectrum_roms)($t4)
  lhu   $t5, 0x298($sp)
  lui   $t6, %hi(ptr_300alloc) 
  addu  $t0, $t4, $t7
  sra   $t2, $t5, 8
  sb    $t2, 1($t0)
  lhu   $t9, 0x292($sp)
  lw    $t6, %lo(ptr_300alloc)($t6)
  li    $t8, 1
  addu  $t1, $t6, $t9
  b     .L7F0E1C70
   sb    $t8, -0x57ff($t1)
.L7F0E1C20:
  addiu $t5, $t3, 1
  slti  $at, $t5, 0x4000
  bnez  $at, .L7F0E1C70
   lhu   $t4, 0x298($sp)
  lui   $t2, %hi(ptr_spectrum_roms) 
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  sra   $t7, $t4, 8
  li    $t6, 1
  addu  $t0, $t2, $t3
  sb    $t7, 1($t0)
  lhu   $t9, 0x292($sp)
  lui   $t3, %hi(ptr_300alloc) 
  lw    $t3, %lo(ptr_300alloc)($t3)
  addiu $t8, $t9, 1
  andi  $t1, $t8, 0x1800
  sra   $t5, $t1, 3
  andi  $t4, $t8, 0xff
  or    $t2, $t5, $t4
  addu  $t7, $t3, $t2
  sb    $t6, ($t7)
.L7F0E1C70:
  li    $t0, 40
  b     .L7F0E27FC
   sh    $t0, 0x298($sp)
spectrum_op_F0:
  lw    $t9, 0x28c($sp)
  andi  $t8, $s1, 0x80
  lui   $t2, %hi(ptr_spectrum_roms) 
  addiu $t1, $t9, 5
  bnez  $t8, .L7F0E27FC
   sw    $t1, 0x28c($sp)
  lhu   $t3, 0x292($sp)
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  addiu $t4, $t1, 6
  sw    $t4, 0x28c($sp)
  addu  $t0, $t2, $t3
  lbu   $t9, 1($t0)
  addu  $t6, $t3, $t2
  lbu   $t7, ($t6)
  sll   $t1, $t9, 8
  addiu $t5, $t3, 2
  or    $t8, $t7, $t1
  sh    $t8, 0x298($sp)
  b     .L7F0E27FC
   sh    $t5, 0x292($sp)
spectrum_op_F1:
  lw    $t4, 0x28c($sp)
  lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  lhu   $t2, 0x292($sp)
  addiu $t6, $t4, 0xa
  sw    $t6, 0x28c($sp)
  addu  $t9, $t2, $t0
  lbu   $s1, ($t9)
  lbu   $s0, 1($t9)
  addiu $t7, $t2, 2
  b     .L7F0E27FC
   sh    $t7, 0x292($sp)
spectrum_op_F2:
  lw    $t1, 0x28c($sp)
  andi  $t3, $s1, 0x80
  lhu   $t5, 0x298($sp)
  addiu $t8, $t1, 0xa
  bnez  $t3, .L7F0E1D3C
   sw    $t8, 0x28c($sp)
  lui   $t4, %hi(ptr_spectrum_roms) 
  lw    $t4, %lo(ptr_spectrum_roms)($t4)
  addu  $t9, $t4, $t5
  lbu   $t2, 1($t9)
  addu  $t6, $t5, $t4
  lbu   $t0, ($t6)
  sll   $t7, $t2, 8
  or    $t1, $t0, $t7
  b     .L7F0E27FC
   sh    $t1, 0x298($sp)
.L7F0E1D3C:
  lhu   $t8, 0x298($sp)
  addiu $t3, $t8, 2
  b     .L7F0E27FC
   sh    $t3, 0x298($sp)
spectrum_op_F3:
  lw    $t6, 0x28c($sp)
  sb    $zero, 0x29c($sp)
  sb    $zero, 0x29d($sp)
  addiu $t4, $t6, 4
  sw    $t4, 0x28c($sp)
  b     .L7F0E27FC
   sb    $zero, 0x285($sp)
spectrum_op_F4:
  lw    $t5, 0x28c($sp)
  andi  $t2, $s1, 0x80
  addiu $t9, $t5, 0xa
  bnez  $t2, .L7F0E1F40
   sw    $t9, 0x28c($sp)
  lhu   $t1, 0x292($sp)
  addiu $t7, $t9, 7
  sw    $t7, 0x28c($sp)
  addiu $t8, $t1, -2
  andi  $t3, $t8, 0xffff
  slti  $at, $t3, 0x5b00
  bnez  $at, .L7F0E1DB8
   sh    $t8, 0x292($sp)
  lui   $t5, %hi(ptr_spectrum_roms) 
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  lhu   $t6, 0x298($sp)
  addu  $t9, $t5, $t3
  addiu $t4, $t6, 2
  b     .L7F0E1E44
   sb    $t4, ($t9)
.L7F0E1DB8:
  lhu   $t2, 0x292($sp)
  lhu   $t9, 0x292($sp)
  lhu   $t0, 0x298($sp)
  slti  $at, $t2, 0x5800
  bnez  $at, .L7F0E1DFC
   lui   $t1, %hi(ptr_spectrum_roms) 
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  addiu $t7, $t0, 2
  lui   $t5, %hi(ptr_300alloc) 
  addu  $t8, $t1, $t2
  sb    $t7, ($t8)
  lhu   $t3, 0x292($sp)
  lw    $t5, %lo(ptr_300alloc)($t5)
  li    $t6, 1
  addu  $t4, $t5, $t3
  b     .L7F0E1E44
   sb    $t6, -0x5800($t4)
.L7F0E1DFC:
  slti  $at, $t9, 0x4000
  bnez  $at, .L7F0E1E44
   lhu   $t0, 0x298($sp)
  lui   $t2, %hi(ptr_spectrum_roms) 
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  addiu $t1, $t0, 2
  li    $t8, 1
  addu  $t7, $t2, $t9
  sb    $t1, ($t7)
  lhu   $t5, 0x292($sp)
  lui   $t2, %hi(ptr_300alloc) 
  lw    $t2, %lo(ptr_300alloc)($t2)
  andi  $t3, $t5, 0x1800
  sra   $t6, $t3, 3
  andi  $t4, $t5, 0xff
  or    $t0, $t6, $t4
  addu  $t9, $t2, $t0
  sb    $t8, ($t9)
.L7F0E1E44:
  lhu   $t1, 0x292($sp)
  lhu   $t0, 0x292($sp)
  lhu   $t3, 0x298($sp)
  addiu $t7, $t1, 1
  slti  $at, $t7, 0x5b00
  bnez  $at, .L7F0E1E7C
   addiu $t8, $t0, 1
  lui   $t4, %hi(ptr_spectrum_roms) 
  lw    $t4, %lo(ptr_spectrum_roms)($t4)
  addiu $t5, $t3, 2
  sra   $t6, $t5, 8
  addu  $t2, $t4, $t1
  b     .L7F0E1F14
   sb    $t6, 1($t2)
.L7F0E1E7C:
  slti  $at, $t8, 0x5800
  bnez  $at, .L7F0E1EC0
   lhu   $t9, 0x292($sp)
  lhu   $t9, 0x298($sp)
  lui   $t5, %hi(ptr_spectrum_roms) 
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  addiu $t7, $t9, 2
  sra   $t3, $t7, 8
  addu  $t4, $t5, $t0
  sb    $t3, 1($t4)
  lui   $t6, %hi(ptr_300alloc) 
  lw    $t6, %lo(ptr_300alloc)($t6)
  lhu   $t2, 0x292($sp)
  li    $t1, 1
  addu  $t8, $t6, $t2
  b     .L7F0E1F14
   sb    $t1, -0x57ff($t8)
.L7F0E1EC0:
  addiu $t7, $t9, 1
  slti  $at, $t7, 0x4000
  bnez  $at, .L7F0E1F14
   lhu   $t5, 0x298($sp)
  lui   $t4, %hi(ptr_spectrum_roms) 
  lw    $t4, %lo(ptr_spectrum_roms)($t4)
  addiu $t0, $t5, 2
  sra   $t3, $t0, 8
  addu  $t6, $t4, $t9
  sb    $t3, 1($t6)
  lhu   $t1, 0x292($sp)
  lui   $t9, %hi(ptr_300alloc) 
  lw    $t9, %lo(ptr_300alloc)($t9)
  addiu $t8, $t1, 1
  andi  $t7, $t8, 0x1800
  sra   $t5, $t7, 3
  andi  $t0, $t8, 0xff
  or    $t4, $t5, $t0
  li    $t2, 1
  addu  $t3, $t9, $t4
  sb    $t2, ($t3)
.L7F0E1F14:
  lui   $t1, %hi(ptr_spectrum_roms) 
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  lhu   $t6, 0x298($sp)
  addu  $t5, $t1, $t6
  lbu   $t0, 1($t5)
  addu  $t7, $t6, $t1
  lbu   $t8, ($t7)
  sll   $t9, $t0, 8
  or    $t4, $t8, $t9
  b     .L7F0E27FC
   sh    $t4, 0x298($sp)
.L7F0E1F40:
  lhu   $t2, 0x298($sp)
  addiu $t3, $t2, 2
  b     .L7F0E27FC
   sh    $t3, 0x298($sp)
spectrum_op_F5:
  lhu   $t6, 0x292($sp)
  lw    $t7, 0x28c($sp)
  lui   $t8, %hi(ptr_spectrum_roms) 
  addiu $t5, $t6, -2
  andi  $t0, $t5, 0xffff
  slti  $at, $t0, 0x5b00
  addiu $t1, $t7, 0xb
  sw    $t1, 0x28c($sp)
  bnez  $at, .L7F0E1F88
   sh    $t5, 0x292($sp)
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  addu  $t9, $t8, $t0
  b     .L7F0E2008
   sb    $s1, ($t9)
.L7F0E1F88:
  lhu   $t4, 0x292($sp)
  lhu   $t8, 0x292($sp)
  lui   $t2, %hi(ptr_spectrum_roms) 
  slti  $at, $t4, 0x5800
  bnezl $at, .L7F0E1FCC
   slti  $at, $t8, 0x4000
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  lui   $t1, %hi(ptr_300alloc) 
  li    $t7, 1
  addu  $t3, $t2, $t4
  sb    $s1, ($t3)
  lhu   $t6, 0x292($sp)
  lw    $t1, %lo(ptr_300alloc)($t1)
  addu  $t5, $t1, $t6
  b     .L7F0E2008
   sb    $t7, -0x5800($t5)
  slti  $at, $t8, 0x4000
.L7F0E1FCC:
  bnez  $at, .L7F0E2008
   lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  lui   $t5, %hi(ptr_300alloc) 
  li    $t2, 1
  addu  $t9, $t0, $t8
  sb    $s1, ($t9)
  lhu   $t4, 0x292($sp)
  lw    $t5, %lo(ptr_300alloc)($t5)
  andi  $t3, $t4, 0x1800
  sra   $t1, $t3, 3
  andi  $t6, $t4, 0xff
  or    $t7, $t1, $t6
  addu  $t0, $t5, $t7
  sb    $t2, ($t0)
.L7F0E2008:
  lhu   $t8, 0x292($sp)
  lhu   $t1, 0x292($sp)
  lui   $t3, %hi(ptr_spectrum_roms) 
  addiu $t9, $t8, 1
  slti  $at, $t9, 0x5b00
  bnez  $at, .L7F0E2034
   addiu $t6, $t1, 1
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  addu  $t4, $t3, $t8
  b     .L7F0E27FC
   sb    $s0, 1($t4)
.L7F0E2034:
  slti  $at, $t6, 0x5800
  bnez  $at, .L7F0E206C
   lhu   $t8, 0x292($sp)
  lui   $t5, %hi(ptr_spectrum_roms) 
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  lui   $t0, %hi(ptr_300alloc) 
  li    $t2, 1
  addu  $t7, $t5, $t1
  sb    $s0, 1($t7)
  lhu   $t9, 0x292($sp)
  lw    $t0, %lo(ptr_300alloc)($t0)
  addu  $t3, $t0, $t9
  b     .L7F0E27FC
   sb    $t2, -0x57ff($t3)
.L7F0E206C:
  addiu $t4, $t8, 1
  slti  $at, $t4, 0x4000
  bnez  $at, .L7F0E27FC
   lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  li    $t1, 1
  addu  $t5, $t6, $t8
  sb    $s0, 1($t5)
  lhu   $t7, 0x292($sp)
  lui   $t6, %hi(ptr_300alloc) 
  lw    $t6, %lo(ptr_300alloc)($t6)
  addiu $t0, $t7, 1
  andi  $t9, $t0, 0x1800
  sra   $t2, $t9, 3
  andi  $t3, $t0, 0xff
  or    $t4, $t2, $t3
  addu  $t8, $t6, $t4
  b     .L7F0E27FC
   sb    $t1, ($t8)
spectrum_op_F6:
  lw    $t5, 0x28c($sp)
  lui   $t9, %hi(ptr_spectrum_roms) 
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  lhu   $t0, 0x298($sp)
  addiu $t7, $t5, 7
  sw    $t7, 0x28c($sp)
  addu  $t2, $t9, $t0
  lbu   $t3, ($t2)
  lui   $t9, %hi(ptr_pc_keyboard_table_alloc) 
  lw    $t9, %lo(ptr_pc_keyboard_table_alloc)($t9)
  or    $s0, $s0, $t3
  andi  $t6, $s0, 0xff
  sltiu $t4, $t6, 1
  sw    $t4, 0x48($sp)
  addu  $t0, $t6, $t9
  lbu   $t2, ($t0)
  move  $s0, $t6
  andi  $t1, $t6, 0xa8
  lhu   $t6, 0x298($sp)
  sll   $t5, $t4, 6
  or    $t7, $t1, $t5
  or    $s1, $t2, $t7
  andi  $t3, $s1, 0xff
  addiu $t4, $t6, 1
  move  $s1, $t3
  b     .L7F0E27FC
   sh    $t4, 0x298($sp)
spectrum_op_F7:
  lhu   $t5, 0x292($sp)
  lw    $t8, 0x28c($sp)
  lui   $t7, %hi(ptr_spectrum_roms) 
  addiu $t9, $t5, -2
  andi  $t0, $t9, 0xffff
  slti  $at, $t0, 0x5b00
  addiu $t1, $t8, 0xb
  sw    $t1, 0x28c($sp)
  bnez  $at, .L7F0E2160
   sh    $t9, 0x292($sp)
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  lhu   $t2, 0x298($sp)
  addu  $t3, $t7, $t0
  b     .L7F0E21E8
   sb    $t2, ($t3)
.L7F0E2160:
  lhu   $t6, 0x292($sp)
  lhu   $t2, 0x292($sp)
  lui   $t8, %hi(ptr_spectrum_roms) 
  slti  $at, $t6, 0x5800
  bnezl $at, .L7F0E21A8
   slti  $at, $t2, 0x4000
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  lhu   $t4, 0x298($sp)
  lui   $t9, %hi(ptr_300alloc) 
  addu  $t1, $t8, $t6
  sb    $t4, ($t1)
  lhu   $t7, 0x292($sp)
  lw    $t9, %lo(ptr_300alloc)($t9)
  li    $t5, 1
  addu  $t0, $t9, $t7
  b     .L7F0E21E8
   sb    $t5, -0x5800($t0)
  slti  $at, $t2, 0x4000
.L7F0E21A8:
  bnez  $at, .L7F0E21E8
   lui   $t8, %hi(ptr_spectrum_roms) 
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  lhu   $t3, 0x298($sp)
  li    $t4, 1
  addu  $t6, $t8, $t2
  sb    $t3, ($t6)
  lhu   $t1, 0x292($sp)
  lui   $t8, %hi(ptr_300alloc) 
  lw    $t8, %lo(ptr_300alloc)($t8)
  andi  $t9, $t1, 0x1800
  sra   $t7, $t9, 3
  andi  $t5, $t1, 0xff
  or    $t0, $t7, $t5
  addu  $t2, $t8, $t0
  sb    $t4, ($t2)
.L7F0E21E8:
  lhu   $t3, 0x292($sp)
  lhu   $t8, 0x292($sp)
  lhu   $t9, 0x298($sp)
  addiu $t6, $t3, 1
  slti  $at, $t6, 0x5b00
  bnez  $at, .L7F0E221C
   addiu $t0, $t8, 1
  lui   $t7, %hi(ptr_spectrum_roms) 
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  sra   $t1, $t9, 8
  addu  $t5, $t7, $t3
  b     .L7F0E22AC
   sb    $t1, 1($t5)
.L7F0E221C:
  slti  $at, $t0, 0x5800
  bnez  $at, .L7F0E225C
   lhu   $t0, 0x292($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  lhu   $t4, 0x298($sp)
  lui   $t3, %hi(ptr_300alloc) 
  addu  $t9, $t6, $t8
  sra   $t2, $t4, 8
  sb    $t2, 1($t9)
  lhu   $t1, 0x292($sp)
  lw    $t3, %lo(ptr_300alloc)($t3)
  li    $t7, 1
  addu  $t5, $t3, $t1
  b     .L7F0E22AC
   sb    $t7, -0x57ff($t5)
.L7F0E225C:
  addiu $t4, $t0, 1
  slti  $at, $t4, 0x4000
  bnez  $at, .L7F0E22AC
   lhu   $t6, 0x298($sp)
  lui   $t2, %hi(ptr_spectrum_roms) 
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  sra   $t8, $t6, 8
  li    $t3, 1
  addu  $t9, $t2, $t0
  sb    $t8, 1($t9)
  lhu   $t1, 0x292($sp)
  lui   $t0, %hi(ptr_300alloc) 
  lw    $t0, %lo(ptr_300alloc)($t0)
  addiu $t7, $t1, 1
  andi  $t5, $t7, 0x1800
  sra   $t4, $t5, 3
  andi  $t6, $t7, 0xff
  or    $t2, $t4, $t6
  addu  $t8, $t0, $t2
  sb    $t3, ($t8)
.L7F0E22AC:
  li    $t9, 48
  b     .L7F0E27FC
   sh    $t9, 0x298($sp)
spectrum_op_F8:
  lw    $t1, 0x28c($sp)
  andi  $t7, $s1, 0x80
  lui   $t2, %hi(ptr_spectrum_roms) 
  addiu $t5, $t1, 5
  beqz  $t7, .L7F0E27FC
   sw    $t5, 0x28c($sp)
  lhu   $t0, 0x292($sp)
  lw    $t2, %lo(ptr_spectrum_roms)($t2)
  addiu $t6, $t5, 6
  sw    $t6, 0x28c($sp)
  addu  $t9, $t2, $t0
  lbu   $t1, 1($t9)
  addu  $t3, $t0, $t2
  lbu   $t8, ($t3)
  sll   $t5, $t1, 8
  addiu $t4, $t0, 2
  or    $t7, $t8, $t5
  sh    $t7, 0x298($sp)
  b     .L7F0E27FC
   sh    $t4, 0x292($sp)
spectrum_op_F9:
  lw    $t6, 0x28c($sp)
  lbu   $t2, 0x287($sp)
  lbu   $t8, 0x287($sp)
  addiu $t3, $t6, 6
  bnez  $t2, .L7F0E2330
   sw    $t3, 0x28c($sp)
  sll   $t9, $s6, 8
  or    $t1, $t9, $s7
  b     .L7F0E27FC
   sh    $t1, 0x292($sp)
.L7F0E2330:
  li    $at, 1
  bne   $t8, $at, .L7F0E2348
   lhu   $t7, 0x294($sp)
  lhu   $t5, 0x296($sp)
  b     .L7F0E234C
   sw    $t5, 0x48($sp)
.L7F0E2348:
  sw    $t7, 0x48($sp)
.L7F0E234C:
  lw    $t0, 0x48($sp)
  b     .L7F0E27FC
   sh    $t0, 0x292($sp)
spectrum_op_FA:
  lw    $t4, 0x28c($sp)
  andi  $t3, $s1, 0x80
  lhu   $t2, 0x298($sp)
  addiu $t6, $t4, 0xa
  beqz  $t3, .L7F0E2398
   sw    $t6, 0x28c($sp)
  lui   $t9, %hi(ptr_spectrum_roms) 
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  addu  $t5, $t9, $t2
  lbu   $t7, 1($t5)
  addu  $t1, $t2, $t9
  lbu   $t8, ($t1)
  sll   $t0, $t7, 8
  or    $t4, $t8, $t0
  b     .L7F0E27FC
   sh    $t4, 0x298($sp)
.L7F0E2398:
  lhu   $t6, 0x298($sp)
  addiu $t3, $t6, 2
  b     .L7F0E27FC
   sh    $t3, 0x298($sp)
spectrum_op_FB:
  lw    $t1, 0x28c($sp)
  li    $t2, 1
  li    $t5, 1
  addiu $t9, $t1, 4
  sw    $t9, 0x28c($sp)
  sb    $t5, 0x29d($sp)
  sb    $t2, 0x29c($sp)
  b     .L7F0E27FC
   sb    $zero, 0x285($sp)
spectrum_op_FC:
  lw    $t7, 0x28c($sp)
  andi  $t0, $s1, 0x80
  addiu $t8, $t7, 0xa
  beqz  $t0, .L7F0E25A4
   sw    $t8, 0x28c($sp)
  lhu   $t3, 0x292($sp)
  addiu $t6, $t8, 7
  sw    $t6, 0x28c($sp)
  addiu $t1, $t3, -2
  andi  $t9, $t1, 0xffff
  slti  $at, $t9, 0x5b00
  bnez  $at, .L7F0E241C
   sh    $t1, 0x292($sp)
  lui   $t7, %hi(ptr_spectrum_roms) 
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  lhu   $t2, 0x298($sp)
  addu  $t8, $t7, $t9
  addiu $t5, $t2, 2
  b     .L7F0E24A8
   sb    $t5, ($t8)
.L7F0E241C:
  lhu   $t0, 0x292($sp)
  lhu   $t8, 0x292($sp)
  lhu   $t4, 0x298($sp)
  slti  $at, $t0, 0x5800
  bnez  $at, .L7F0E2460
   lui   $t3, %hi(ptr_spectrum_roms) 
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  addiu $t6, $t4, 2
  lui   $t7, %hi(ptr_300alloc) 
  addu  $t1, $t3, $t0
  sb    $t6, ($t1)
  lhu   $t9, 0x292($sp)
  lw    $t7, %lo(ptr_300alloc)($t7)
  li    $t2, 1
  addu  $t5, $t7, $t9
  b     .L7F0E24A8
   sb    $t2, -0x5800($t5)
.L7F0E2460:
  slti  $at, $t8, 0x4000
  bnez  $at, .L7F0E24A8
   lhu   $t4, 0x298($sp)
  lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  addiu $t3, $t4, 2
  li    $t1, 1
  addu  $t6, $t0, $t8
  sb    $t3, ($t6)
  lhu   $t7, 0x292($sp)
  lui   $t0, %hi(ptr_300alloc) 
  lw    $t0, %lo(ptr_300alloc)($t0)
  andi  $t9, $t7, 0x1800
  sra   $t2, $t9, 3
  andi  $t5, $t7, 0xff
  or    $t4, $t2, $t5
  addu  $t8, $t0, $t4
  sb    $t1, ($t8)
.L7F0E24A8:
  lhu   $t3, 0x292($sp)
  lhu   $t4, 0x292($sp)
  lhu   $t9, 0x298($sp)
  addiu $t6, $t3, 1
  slti  $at, $t6, 0x5b00
  bnez  $at, .L7F0E24E0
   addiu $t1, $t4, 1
  lui   $t5, %hi(ptr_spectrum_roms) 
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  addiu $t7, $t9, 2
  sra   $t2, $t7, 8
  addu  $t0, $t5, $t3
  b     .L7F0E2578
   sb    $t2, 1($t0)
.L7F0E24E0:
  slti  $at, $t1, 0x5800
  bnez  $at, .L7F0E2524
   lhu   $t8, 0x292($sp)
  lhu   $t8, 0x298($sp)
  lui   $t7, %hi(ptr_spectrum_roms) 
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  addiu $t6, $t8, 2
  sra   $t9, $t6, 8
  addu  $t5, $t7, $t4
  sb    $t9, 1($t5)
  lui   $t2, %hi(ptr_300alloc) 
  lw    $t2, %lo(ptr_300alloc)($t2)
  lhu   $t0, 0x292($sp)
  li    $t3, 1
  addu  $t1, $t2, $t0
  b     .L7F0E2578
   sb    $t3, -0x57ff($t1)
.L7F0E2524:
  addiu $t6, $t8, 1
  slti  $at, $t6, 0x4000
  bnez  $at, .L7F0E2578
   lhu   $t7, 0x298($sp)
  lui   $t5, %hi(ptr_spectrum_roms) 
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  addiu $t4, $t7, 2
  sra   $t9, $t4, 8
  addu  $t2, $t5, $t8
  sb    $t9, 1($t2)
  lhu   $t3, 0x292($sp)
  lui   $t8, %hi(ptr_300alloc) 
  lw    $t8, %lo(ptr_300alloc)($t8)
  addiu $t1, $t3, 1
  andi  $t6, $t1, 0x1800
  sra   $t7, $t6, 3
  andi  $t4, $t1, 0xff
  or    $t5, $t7, $t4
  li    $t0, 1
  addu  $t9, $t8, $t5
  sb    $t0, ($t9)
.L7F0E2578:
  lui   $t3, %hi(ptr_spectrum_roms) 
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  lhu   $t2, 0x298($sp)
  addu  $t7, $t3, $t2
  lbu   $t4, 1($t7)
  addu  $t6, $t2, $t3
  lbu   $t1, ($t6)
  sll   $t8, $t4, 8
  or    $t5, $t1, $t8
  b     .L7F0E27FC
   sh    $t5, 0x298($sp)
.L7F0E25A4:
  lhu   $t0, 0x298($sp)
  addiu $t9, $t0, 2
  b     .L7F0E27FC
   sh    $t9, 0x298($sp)
spectrum_op_FD:
  lw    $t6, 0x28c($sp)
  li    $t2, 2
  sb    $t2, 0x286($sp)
  addiu $t3, $t6, 4
  sw    $t3, 0x28c($sp)
  b     .L7F0E27FC
   sb    $zero, 0x285($sp)
spectrum_op_FE:
  lw    $t7, 0x28c($sp)
  lui   $t8, %hi(ptr_spectrum_roms) 
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  lhu   $t1, 0x298($sp)
  addiu $t4, $t7, 7
  sw    $t4, 0x28c($sp)
  addu  $t5, $t1, $t8
  lbu   $t0, ($t5)
  subu  $t9, $s0, $t0
  andi  $t6, $t9, 0x1ff
  andi  $t3, $t6, 0xffff
  sltiu $t2, $t3, 1
  andi  $t3, $s0, 0xf
  andi  $t9, $t0, 0xf
  slt   $t7, $t3, $t9
  andi  $t4, $t6, 0xa8
  sra   $t8, $t6, 8
  or    $t5, $t4, $t8
  sll   $t1, $t7, 4
  move  $t9, $t6
  xor   $t8, $s0, $t0
  andi  $t3, $t8, 0x80
  xor   $t7, $t9, $s0
  or    $t4, $t5, $t1
  and   $t5, $t3, $t7
  sra   $t1, $t5, 5
  sb    $t0, 0x53($sp)
  lhu   $t3, 0x298($sp)
  or    $t0, $t4, $t1
  sh    $t6, 0x54($sp)
  sll   $t6, $t2, 6
  ori   $t8, $t0, 2
  or    $s1, $t8, $t6
  andi  $t9, $s1, 0xff
  addiu $t7, $t3, 1
  move  $s1, $t9
  sw    $t2, 0x48($sp)
  b     .L7F0E27FC
   sh    $t7, 0x298($sp)
spectrum_op_FF:
  lhu   $t1, 0x292($sp)
  lw    $t5, 0x28c($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  addiu $t0, $t1, -2
  andi  $t2, $t0, 0xffff
  slti  $at, $t2, 0x5b00
  addiu $t4, $t5, 0xb
  sw    $t4, 0x28c($sp)
  bnez  $at, .L7F0E26A8
   sh    $t0, 0x292($sp)
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  lhu   $t8, 0x298($sp)
  addu  $t9, $t6, $t2
  b     .L7F0E2730
   sb    $t8, ($t9)
.L7F0E26A8:
  lhu   $t3, 0x292($sp)
  lhu   $t8, 0x292($sp)
  lui   $t5, %hi(ptr_spectrum_roms) 
  slti  $at, $t3, 0x5800
  bnezl $at, .L7F0E26F0
   slti  $at, $t8, 0x4000
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  lhu   $t7, 0x298($sp)
  lui   $t0, %hi(ptr_300alloc) 
  addu  $t4, $t5, $t3
  sb    $t7, ($t4)
  lhu   $t6, 0x292($sp)
  lw    $t0, %lo(ptr_300alloc)($t0)
  li    $t1, 1
  addu  $t2, $t0, $t6
  b     .L7F0E2730
   sb    $t1, -0x5800($t2)
  slti  $at, $t8, 0x4000
.L7F0E26F0:
  bnez  $at, .L7F0E2730
   lui   $t5, %hi(ptr_spectrum_roms) 
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  lhu   $t9, 0x298($sp)
  li    $t7, 1
  addu  $t3, $t5, $t8
  sb    $t9, ($t3)
  lhu   $t4, 0x292($sp)
  lui   $t5, %hi(ptr_300alloc) 
  lw    $t5, %lo(ptr_300alloc)($t5)
  andi  $t0, $t4, 0x1800
  sra   $t6, $t0, 3
  andi  $t1, $t4, 0xff
  or    $t2, $t6, $t1
  addu  $t8, $t5, $t2
  sb    $t7, ($t8)
.L7F0E2730:
  lhu   $t9, 0x292($sp)
  lhu   $t5, 0x292($sp)
  lhu   $t0, 0x298($sp)
  addiu $t3, $t9, 1
  slti  $at, $t3, 0x5b00
  bnez  $at, .L7F0E2764
   addiu $t2, $t5, 1
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  sra   $t4, $t0, 8
  addu  $t1, $t6, $t9
  b     .L7F0E27F4
   sb    $t4, 1($t1)
.L7F0E2764:
  slti  $at, $t2, 0x5800
  bnez  $at, .L7F0E27A4
   lhu   $t2, 0x292($sp)
  lui   $t3, %hi(ptr_spectrum_roms) 
  lw    $t3, %lo(ptr_spectrum_roms)($t3)
  lhu   $t7, 0x298($sp)
  lui   $t9, %hi(ptr_300alloc) 
  addu  $t0, $t3, $t5
  sra   $t8, $t7, 8
  sb    $t8, 1($t0)
  lhu   $t4, 0x292($sp)
  lw    $t9, %lo(ptr_300alloc)($t9)
  li    $t6, 1
  addu  $t1, $t9, $t4
  b     .L7F0E27F4
   sb    $t6, -0x57ff($t1)
.L7F0E27A4:
  addiu $t7, $t2, 1
  slti  $at, $t7, 0x4000
  bnez  $at, .L7F0E27F4
   lhu   $t3, 0x298($sp)
  lui   $t8, %hi(ptr_spectrum_roms) 
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  sra   $t5, $t3, 8
  li    $t9, 1
  addu  $t0, $t8, $t2
  sb    $t5, 1($t0)
  lhu   $t4, 0x292($sp)
  lui   $t2, %hi(ptr_300alloc) 
  lw    $t2, %lo(ptr_300alloc)($t2)
  addiu $t6, $t4, 1
  andi  $t1, $t6, 0x1800
  sra   $t7, $t1, 3
  andi  $t3, $t6, 0xff
  or    $t8, $t7, $t3
  addu  $t5, $t2, $t8
  sb    $t9, ($t5)
.L7F0E27F4:
  li    $t0, 56
  sh    $t0, 0x298($sp)
.L7F0E27FC:
  lw    $t4, 0x28c($sp)
  lw    $t1, 0x280($sp)
  sltu  $at, $t4, $t1
  bnez  $at, .L7F0D39D8
   nop   
  lbu   $t6, 0x285($sp)
  beqz  $t6, .L7F0D39D8
   nop   
.L7F0E281C:
  lw    $t7, 0x28c($sp)
  lw    $t3, 0x280($sp)
  lbu   $t2, 0x285($sp)
  sltu  $at, $t7, $t3
  bnez  $at, .L7F0E2C08
   nop   
  beqz  $t2, .L7F0E2C08
   nop   
  lbu   $t9, 0x29d($sp)
  subu  $t8, $t7, $t3
  sw    $t8, 0x28c($sp)
  beqz  $t9, .L7F0E2C08
   lhu   $t5, 0x298($sp)
  lui   $t0, %hi(ptr_spectrum_roms) 
  lw    $t0, %lo(ptr_spectrum_roms)($t0)
  li    $at, 118
  addiu $t6, $t5, 1
  addu  $t4, $t5, $t0
  lbu   $t1, ($t4)
  bnel  $t1, $at, .L7F0E2878
   lw    $t2, 0x28c($sp)
  sh    $t6, 0x298($sp)
  lw    $t2, 0x28c($sp)
.L7F0E2878:
  lbu   $t3, 0x29b($sp)
  sb    $zero, 0x29c($sp)
  addiu $t7, $t2, 5
  sb    $zero, 0x29d($sp)
  sw    $t7, 0x28c($sp)
  beqz  $t3, .L7F0E28B8
   sw    $t3, 0x48($sp)
  li    $at, 1
  beq   $t3, $at, .L7F0E28B8
   li    $at, 2
  beq   $t3, $at, .L7F0E28B8
   li    $at, 3
  beq   $t3, $at, .L7F0E2A4C
   lw    $t9, 0x28c($sp)
  b     .L7F0E2C08
   nop   
.L7F0E28B8:
  lhu   $t0, 0x292($sp)
  lw    $t8, 0x28c($sp)
  lui   $t6, %hi(ptr_spectrum_roms) 
  addiu $t4, $t0, -2
  andi  $t1, $t4, 0xffff
  slti  $at, $t1, 0x5b00
  addiu $t9, $t8, 8
  sw    $t9, 0x28c($sp)
  bnez  $at, .L7F0E28F4
   sh    $t4, 0x292($sp)
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  lhu   $t5, 0x298($sp)
  addu  $t2, $t6, $t1
  b     .L7F0E297C
   sb    $t5, ($t2)
.L7F0E28F4:
  lhu   $t7, 0x292($sp)
  lhu   $t5, 0x292($sp)
  lui   $t8, %hi(ptr_spectrum_roms) 
  slti  $at, $t7, 0x5800
  bnezl $at, .L7F0E293C
   slti  $at, $t5, 0x4000
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  lhu   $t3, 0x298($sp)
  lui   $t4, %hi(ptr_300alloc) 
  addu  $t9, $t8, $t7
  sb    $t3, ($t9)
  lhu   $t6, 0x292($sp)
  lw    $t4, %lo(ptr_300alloc)($t4)
  li    $t0, 1
  addu  $t1, $t4, $t6
  b     .L7F0E297C
   sb    $t0, -0x5800($t1)
  slti  $at, $t5, 0x4000
.L7F0E293C:
  bnez  $at, .L7F0E297C
   lui   $t8, %hi(ptr_spectrum_roms) 
  lw    $t8, %lo(ptr_spectrum_roms)($t8)
  lhu   $t2, 0x298($sp)
  li    $t3, 1
  addu  $t7, $t8, $t5
  sb    $t2, ($t7)
  lhu   $t9, 0x292($sp)
  lui   $t8, %hi(ptr_300alloc) 
  lw    $t8, %lo(ptr_300alloc)($t8)
  andi  $t4, $t9, 0x1800
  sra   $t6, $t4, 3
  andi  $t0, $t9, 0xff
  or    $t1, $t6, $t0
  addu  $t5, $t8, $t1
  sb    $t3, ($t5)
.L7F0E297C:
  lhu   $t2, 0x292($sp)
  lhu   $t8, 0x292($sp)
  lhu   $t4, 0x298($sp)
  addiu $t7, $t2, 1
  slti  $at, $t7, 0x5b00
  bnez  $at, .L7F0E29B0
   addiu $t1, $t8, 1
  lui   $t6, %hi(ptr_spectrum_roms) 
  lw    $t6, %lo(ptr_spectrum_roms)($t6)
  sra   $t9, $t4, 8
  addu  $t0, $t6, $t2
  b     .L7F0E2A40
   sb    $t9, 1($t0)
.L7F0E29B0:
  slti  $at, $t1, 0x5800
  bnez  $at, .L7F0E29F0
   lhu   $t1, 0x292($sp)
  lui   $t7, %hi(ptr_spectrum_roms) 
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  lhu   $t3, 0x298($sp)
  lui   $t2, %hi(ptr_300alloc) 
  addu  $t4, $t7, $t8
  sra   $t5, $t3, 8
  sb    $t5, 1($t4)
  lhu   $t9, 0x292($sp)
  lw    $t2, %lo(ptr_300alloc)($t2)
  li    $t6, 1
  addu  $t0, $t2, $t9
  b     .L7F0E2A40
   sb    $t6, -0x57ff($t0)
.L7F0E29F0:
  addiu $t3, $t1, 1
  slti  $at, $t3, 0x4000
  bnez  $at, .L7F0E2A40
   lhu   $t7, 0x298($sp)
  lui   $t5, %hi(ptr_spectrum_roms) 
  lw    $t5, %lo(ptr_spectrum_roms)($t5)
  sra   $t8, $t7, 8
  li    $t2, 1
  addu  $t4, $t5, $t1
  sb    $t8, 1($t4)
  lhu   $t9, 0x292($sp)
  lui   $t1, %hi(ptr_300alloc) 
  lw    $t1, %lo(ptr_300alloc)($t1)
  addiu $t6, $t9, 1
  andi  $t0, $t6, 0x1800
  sra   $t3, $t0, 3
  andi  $t7, $t6, 0xff
  or    $t5, $t3, $t7
  addu  $t8, $t1, $t5
  sb    $t2, ($t8)
.L7F0E2A40:
  li    $t4, 56
  b     .L7F0E2C08
   sh    $t4, 0x298($sp)
.L7F0E2A4C:
  lbu   $t6, 0x29e($sp)
  lui   $t1, %hi(ptr_spectrum_roms) 
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  sll   $t3, $t6, 8
  addiu $t0, $t9, 0xe
  ori   $t7, $t3, 0xff
  lhu   $t6, 0x292($sp)
  sw    $t0, 0x28c($sp)
  addu  $t8, $t1, $t7
  lbu   $t4, 1($t8)
  addu  $t5, $t7, $t1
  lbu   $t2, ($t5)
  addiu $t3, $t6, -2
  andi  $t5, $t3, 0xffff
  sll   $t9, $t4, 8
  slti  $at, $t5, 0x5b00
  or    $t0, $t2, $t9
  sw    $t0, 0x4c($sp)
  bnez  $at, .L7F0E2AB4
   sh    $t3, 0x292($sp)
  lui   $t7, %hi(ptr_spectrum_roms) 
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  lhu   $t1, 0x298($sp)
  addu  $t8, $t7, $t5
  b     .L7F0E2B3C
   sb    $t1, ($t8)
.L7F0E2AB4:
  lhu   $t4, 0x292($sp)
  lhu   $t1, 0x292($sp)
  lui   $t9, %hi(ptr_spectrum_roms) 
  slti  $at, $t4, 0x5800
  bnezl $at, .L7F0E2AFC
   slti  $at, $t1, 0x4000
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  lhu   $t2, 0x298($sp)
  lui   $t3, %hi(ptr_300alloc) 
  addu  $t0, $t9, $t4
  sb    $t2, ($t0)
  lhu   $t7, 0x292($sp)
  lw    $t3, %lo(ptr_300alloc)($t3)
  li    $t6, 1
  addu  $t5, $t3, $t7
  b     .L7F0E2B3C
   sb    $t6, -0x5800($t5)
  slti  $at, $t1, 0x4000
.L7F0E2AFC:
  bnez  $at, .L7F0E2B3C
   lui   $t9, %hi(ptr_spectrum_roms) 
  lw    $t9, %lo(ptr_spectrum_roms)($t9)
  lhu   $t8, 0x298($sp)
  li    $t2, 1
  addu  $t4, $t9, $t1
  sb    $t8, ($t4)
  lhu   $t0, 0x292($sp)
  lui   $t9, %hi(ptr_300alloc) 
  lw    $t9, %lo(ptr_300alloc)($t9)
  andi  $t3, $t0, 0x1800
  sra   $t7, $t3, 3
  andi  $t6, $t0, 0xff
  or    $t5, $t7, $t6
  addu  $t1, $t9, $t5
  sb    $t2, ($t1)
.L7F0E2B3C:
  lhu   $t8, 0x292($sp)
  lhu   $t9, 0x292($sp)
  lhu   $t3, 0x298($sp)
  addiu $t4, $t8, 1
  slti  $at, $t4, 0x5b00
  bnez  $at, .L7F0E2B70
   addiu $t5, $t9, 1
  lui   $t7, %hi(ptr_spectrum_roms) 
  lw    $t7, %lo(ptr_spectrum_roms)($t7)
  sra   $t0, $t3, 8
  addu  $t6, $t7, $t8
  b     .L7F0E2C00
   sb    $t0, 1($t6)
.L7F0E2B70:
  slti  $at, $t5, 0x5800
  bnez  $at, .L7F0E2BB0
   lhu   $t5, 0x292($sp)
  lui   $t4, %hi(ptr_spectrum_roms) 
  lw    $t4, %lo(ptr_spectrum_roms)($t4)
  lhu   $t2, 0x298($sp)
  lui   $t8, %hi(ptr_300alloc) 
  addu  $t3, $t4, $t9
  sra   $t1, $t2, 8
  sb    $t1, 1($t3)
  lhu   $t0, 0x292($sp)
  lw    $t8, %lo(ptr_300alloc)($t8)
  li    $t7, 1
  addu  $t6, $t8, $t0
  b     .L7F0E2C00
   sb    $t7, -0x57ff($t6)
.L7F0E2BB0:
  addiu $t2, $t5, 1
  slti  $at, $t2, 0x4000
  bnez  $at, .L7F0E2C00
   lhu   $t4, 0x298($sp)
  lui   $t1, %hi(ptr_spectrum_roms) 
  lw    $t1, %lo(ptr_spectrum_roms)($t1)
  sra   $t9, $t4, 8
  li    $t8, 1
  addu  $t3, $t1, $t5
  sb    $t9, 1($t3)
  lhu   $t0, 0x292($sp)
  lui   $t5, %hi(ptr_300alloc) 
  lw    $t5, %lo(ptr_300alloc)($t5)
  addiu $t7, $t0, 1
  andi  $t6, $t7, 0x1800
  sra   $t2, $t6, 3
  andi  $t4, $t7, 0xff
  or    $t1, $t2, $t4
  addu  $t9, $t5, $t1
  sb    $t8, ($t9)
.L7F0E2C00:
  lw    $t3, 0x4c($sp)
  sh    $t3, 0x298($sp)
.L7F0E2C08:
  lui   $at, %hi(spectrum_header16_15)
  sb    $s0, %lo(spectrum_header16_15)($at)
  lui   $at, %hi(byte_CODE_bss_8008E339)
  sb    $s1, %lo(byte_CODE_bss_8008E339)($at)
  lui   $at, %hi(byte_CODE_bss_8008E33A)
  sb    $s2, %lo(byte_CODE_bss_8008E33A)($at)
  lui   $at, %hi(byte_CODE_bss_8008E33B)
  sb    $s3, %lo(byte_CODE_bss_8008E33B)($at)
  lui   $at, %hi(off_CODE_bss_8008E33C)
  sb    $s4, %lo(off_CODE_bss_8008E33C)($at)
  lui   $at, %hi(byte_CODE_bss_8008E33D)
  sb    $s5, %lo(byte_CODE_bss_8008E33D)($at)
  lui   $at, %hi(byte_CODE_bss_8008E33E)
  sb    $s6, %lo(byte_CODE_bss_8008E33E)($at)
  lbu   $t0, 0x2a6($sp)
  lui   $at, %hi(byte_CODE_bss_8008E33F)
  sb    $s7, %lo(byte_CODE_bss_8008E33F)($at)
  lbu   $t6, 0x2a5($sp)
  lui   $at, %hi(off_CODE_bss_8008E340)
  sb    $t0, %lo(off_CODE_bss_8008E340)($at)
  lbu   $t7, 0x2a4($sp)
  lui   $at, %hi(byte_CODE_bss_8008E341)
  sb    $t6, %lo(byte_CODE_bss_8008E341)($at)
  lbu   $t2, 0x2a3($sp)
  lui   $at, %hi(byte_CODE_bss_8008E342)
  sb    $t7, %lo(byte_CODE_bss_8008E342)($at)
  lbu   $t4, 0x2a2($sp)
  lui   $at, %hi(byte_CODE_bss_8008E343)
  sb    $t2, %lo(byte_CODE_bss_8008E343)($at)
  lbu   $t5, 0x2a1($sp)
  lui   $at, %hi(off_CODE_bss_8008E344)
  sb    $t4, %lo(off_CODE_bss_8008E344)($at)
  lbu   $t1, 0x2a0($sp)
  lui   $at, %hi(byte_CODE_bss_8008E345)
  sb    $t5, %lo(byte_CODE_bss_8008E345)($at)
  lbu   $t8, 0x29f($sp)
  lui   $at, %hi(byte_CODE_bss_8008E346)
  sb    $t1, %lo(byte_CODE_bss_8008E346)($at)
  lbu   $t9, 0x29d($sp)
  lui   $at, %hi(byte_CODE_bss_8008E347)
  sb    $t8, %lo(byte_CODE_bss_8008E347)($at)
  lbu   $t3, 0x29c($sp)
  lui   $at, %hi(spec_IFF2_lower)
  sb    $t9, %lo(spec_IFF2_lower)($at)
  lbu   $t0, 0x29e($sp)
  lui   $at, %hi(spec_IFF2_upper)
  sb    $t3, %lo(spec_IFF2_upper)($at)
  lbu   $t6, 0x2a7($sp)
  lui   $at, %hi(spec_I)
  sb    $t0, %lo(spec_I)($at)
  lbu   $t2, 0x29b($sp)
  lui   $at, %hi(byte_CODE_bss_8008E349)
  sb    $t6, %lo(byte_CODE_bss_8008E349)($at)
  lhu   $t4, 0x296($sp)
  lui   $at, %hi(spec_IM)
  sb    $t2, %lo(spec_IM)($at)
  lhu   $t5, 0x294($sp)
  lui   $at, %hi(spec_IX)
  sh    $t4, %lo(spec_IX)($at)
  lhu   $t1, 0x292($sp)
  lui   $at, %hi(spec_IY)
  lw    $t7, 0x288($sp)
  sh    $t5, %lo(spec_IY)($at)
  lw    $ra, 0x34($sp)
  lui   $at, %hi(spec_SP)
  lhu   $t8, 0x298($sp)
  sh    $t1, %lo(spec_SP)($at)
  lui   $at, %hi(spec_PC)
  lw    $s7, 0x30($sp)
  lw    $s6, 0x2c($sp)
  lw    $s5, 0x28($sp)
  lw    $s4, 0x24($sp)
  lw    $s3, 0x20($sp)
  lw    $s2, 0x1c($sp)
  lw    $s1, 0x18($sp)
  lw    $s0, 0x14($sp)
  sb    $t7, 0x2a7($sp)
  addiu $sp, $sp, 0x2b0
  jr    $ra
   sh    $t8, %lo(spec_PC)($at)
");
