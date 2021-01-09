int dword_CODE_bss_8008D350;
int dword_CODE_bss_8008D354;
int dword_CODE_bss_8008D358;
int dword_CODE_bss_8008D35C;
int dword_CODE_bss_8008D360;
int dword_CODE_bss_8008D364;
int dword_CODE_bss_8008D368;
int dword_CODE_bss_8008D36C;

unsigned char D_8004E8E0[] = {0x10, 0x11, 0x12, 0, 8,   7, 9,   6, 0xA, 5,
                              0xB,  4,    0xC,  3, 0xD, 2, 0xE, 1, 0xF, 0};

short D_8004E8F4[] = {3,    4,    5,    6,    7,     8,    9,    0xA,
                      0xB,  0xD,  0xF,  0x11, 0x13,  0x17, 0x1B, 0x1F,
                      0x23, 0x2B, 0x33, 0x3B, 0x43,  0x53, 0x63, 0x73,
                      0x83, 0xA3, 0xC3, 0xE3, 0x102, 0,    0,    0};

unsigned int D_8004E934[] = {0,         0,         0x1010101, 0x2020202,
                             0x3030303, 0x4040404, 0x5050505, 0x636300};

short D_8004E954[] = {
    1,     2,     3,     4,     5,      7,      9,      0xD,    0x11,   0x19,
    0x21,  0x31,  0x41,  0x61,  0x81,   0xC1,   0x101,  0x181,  0x201,  0x301,
    0x401, 0x601, 0x801, 0xC01, 0x1001, 0x1801, 0x2001, 0x3001, 0x4001, 0x6001};

unsigned short D_8004E990[] = {0,     0,     0x101, 0x202, 0x303, 0x404,
                               0x505, 0x606, 0x707, 0x808, 0x909, 0xA0A,
                               0xB0B, 0xC0C, 0xD0D, 0};

unsigned short D_8004E9B0[] = {0,     1,      3,      7,      0xF,    0x1F,
                               0x3F,  0x7F,   0xFF,   0x1FF,  0x3FF,  0x7FF,
                               0xFFF, 0x1FFF, 0x3FFF, 0x7FFF, 0xFFFF, 0};

int D_8004E9D4 = 9;
int D_8004E9D8 = 6;

asm(R"
glabel sub_GAME_7F0CE8B0
  addiu $sp, $sp, -0x5f8
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  addiu $s1, $sp, 0x5b0
  move  $s2, $a0
  sw    $ra, 0x3c($sp)
  sw    $a1, 0x5fc($sp)
  sw    $fp, 0x38($sp)
  sw    $s7, 0x34($sp)
  sw    $s6, 0x30($sp)
  sw    $s5, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s0, 0x18($sp)
  sw    $a2, 0x600($sp)
  sw    $a3, 0x604($sp)
  li    $a1, 68
  jal   _blkclr
   move  $a0, $s1
  lw    $t6, 0x5fc($sp)
  move  $fp, $s2
  li    $a3, 1
  andi  $v0, $t6, 3
  negu  $v0, $v0
  beqz  $v0, .L7F0CE948
   move  $ra, $t6
  addu  $v1, $v0, $t6
.L7F0CE91C:
  lw    $t7, ($fp)
  addiu $ra, $ra, -1
  addiu $fp, $fp, 4
  sll   $t8, $t7, 2
  addu  $v0, $s1, $t8
  lw    $t9, ($v0)
  addiu $t6, $t9, 1
  bne   $v1, $ra, .L7F0CE91C
   sw    $t6, ($v0)
  beql  $ra, $zero, .L7F0CE9B8
   lw    $t7, 0x5fc($sp)
.L7F0CE948:
  lw    $t7, ($fp)
  addiu $ra, $ra, -4
  addiu $fp, $fp, 0x10
  sll   $t8, $t7, 2
  addu  $v0, $s1, $t8
  lw    $t9, ($v0)
  addiu $t6, $t9, 1
  sw    $t6, ($v0)
  lw    $t7, -0xc($fp)
  sll   $t8, $t7, 2
  addu  $v0, $s1, $t8
  lw    $t9, ($v0)
  addiu $t6, $t9, 1
  sw    $t6, ($v0)
  lw    $t7, -8($fp)
  sll   $t8, $t7, 2
  addu  $v0, $s1, $t8
  lw    $t9, ($v0)
  addiu $t6, $t9, 1
  sw    $t6, ($v0)
  lw    $t7, -4($fp)
  sll   $t8, $t7, 2
  addu  $v0, $s1, $t8
  lw    $t9, ($v0)
  addiu $t6, $t9, 1
  bnez  $ra, .L7F0CE948
   sw    $t6, ($v0)
  lw    $t7, 0x5fc($sp)
.L7F0CE9B8:
  lw    $t8, 0x5b0($sp)
  lw    $a1, 0x610($sp)
  addiu $v1, $sp, 0x5b4
  bne   $t7, $t8, .L7F0CE9E4
   li    $v0, 17
  lw    $s5, 0x60c($sp)
  lw    $a1, 0x610($sp)
  move  $v0, $zero
  sw    $zero, ($s5)
  b     .L7F0CEEC0
   sw    $zero, ($a1)
.L7F0CE9E4:
  lw    $s0, ($a1)
.L7F0CE9E8:
  lw    $t9, ($v1)
  bnezl $t9, .L7F0CEA04
   sltu  $at, $s0, $a3
  addiu $a3, $a3, 1
  bne   $a3, $v0, .L7F0CE9E8
   addiu $v1, $v1, 4
  sltu  $at, $s0, $a3
.L7F0CEA04:
  beqz  $at, .L7F0CEA10
   move  $s4, $a3
  move  $s0, $a3
.L7F0CEA10:
  li    $ra, 16
  addiu $v0, $sp, 0x5f0
.L7F0CEA18:
  lw    $t6, ($v0)
  bnezl $t6, .L7F0CEA34
   sltu  $at, $ra, $s0
  addiu $ra, $ra, -1
  bnez  $ra, .L7F0CEA18
   addiu $v0, $v0, -4
  sltu  $at, $ra, $s0
.L7F0CEA34:
  beqz  $at, .L7F0CEA40
   sw    $ra, 0x5a8($sp)
  move  $s0, $ra
.L7F0CEA40:
  li    $t7, 1
  sltu  $at, $a3, $ra
  sw    $s0, ($a1)
  beqz  $at, .L7F0CEA7C
   sllv  $a0, $t7, $a3
  sll   $t8, $ra, 2
  addiu $t9, $sp, 0x5b0
  addu  $a1, $t8, $t9
.L7F0CEA60:
  lw    $t6, ($v1)
  addiu $v1, $v1, 4
  sltu  $at, $v1, $a1
  subu  $a0, $a0, $t6
  sll   $t7, $a0, 1
  bnez  $at, .L7F0CEA60
   move  $a0, $t7
.L7F0CEA7C:
  lw    $v1, ($v0)
  addiu $ra, $ra, -1
  move  $a3, $zero
  subu  $a0, $a0, $v1
  addu  $t8, $v1, $a0
  sw    $t8, ($v0)
  sw    $zero, 0x80($sp)
  addiu $fp, $sp, 0x5b4
  addiu $a2, $sp, 0x84
  beqz  $ra, .L7F0CEB2C
   addiu $v0, $v0, -4
  andi  $t0, $ra, 3
  negu  $t0, $t0
  beqz  $t0, .L7F0CEAE8
   addu  $v1, $t0, $ra
  sll   $t9, $v1, 2
  addiu $t6, $sp, 0x5b0
  addu  $a1, $t9, $t6
.L7F0CEAC4:
  lw    $t7, ($fp)
  addiu $v0, $v0, -4
  addiu $a2, $a2, 4
  addu  $a3, $a3, $t7
  sw    $a3, -4($a2)
  bne   $a1, $v0, .L7F0CEAC4
   addiu $fp, $fp, 4
  addiu $t8, $sp, 0x5b0
  beq   $v0, $t8, .L7F0CEB2C
.L7F0CEAE8:
   addiu $v1, $sp, 0x5b0
.L7F0CEAEC:
  lw    $t9, ($fp)
  addiu $v0, $v0, -0x10
  addiu $a2, $a2, 0x10
  addu  $a3, $a3, $t9
  sw    $a3, -0x10($a2)
  lw    $t6, 4($fp)
  addiu $fp, $fp, 0x10
  addu  $a3, $a3, $t6
  sw    $a3, -0xc($a2)
  lw    $t7, -8($fp)
  addu  $a3, $a3, $t7
  sw    $a3, -8($a2)
  lw    $t8, -4($fp)
  addu  $a3, $a3, $t8
  bne   $v0, $v1, .L7F0CEAEC
   sw    $a3, -4($a2)
.L7F0CEB2C:
  move  $fp, $s2
  move  $ra, $zero
  addiu $a2, $sp, 0x7c
  addiu $a1, $sp, 0xc4
  lw    $a3, ($fp)
.L7F0CEB40:
  addiu $fp, $fp, 4
  beqz  $a3, .L7F0CEB68
   sll   $t9, $a3, 2
  addu  $v0, $a2, $t9
  lw    $v1, ($v0)
  sll   $t6, $v1, 2
  addu  $t7, $a1, $t6
  sw    $ra, ($t7)
  addiu $t8, $v1, 1
  sw    $t8, ($v0)
.L7F0CEB68:
  lw    $t9, 0x5fc($sp)
  addiu $ra, $ra, 1
  sltu  $at, $ra, $t9
  bnezl $at, .L7F0CEB40
   lw    $a3, ($fp)
  lw    $t6, 0x5a8($sp)
  sw    $a0, 0x74($sp)
  move  $ra, $zero
  slt   $at, $t6, $s4
  sw    $zero, 0x7c($sp)
  move  $fp, $a1
  li    $t4, -1
  negu  $t2, $s0
  sw    $zero, 0x544($sp)
  move  $a2, $zero
  bnez  $at, .L7F0CEEA4
   move  $t0, $zero
  sll   $t7, $s4, 2
  addiu $t8, $sp, 0x5b0
  addu  $t9, $t7, $t8
  lui   $s7, %hi(dword_CODE_bss_8008D360) 
  lui   $s2, %hi(dword_CODE_bss_8008D36C)
  addiu $s2, %lo(dword_CODE_bss_8008D36C) # addiu $s2, $s2, -0x2c94
  addiu $s7, %lo(dword_CODE_bss_8008D360) # addiu $s7, $s7, -0x2ca0
  sw    $t9, 0x5c($sp)
  lw    $s5, 0x60c($sp)
  addiu $s3, $sp, 0x584
.L7F0CEBD4:
  lw    $t6, 0x5c($sp)
  lw    $t8, 0x5fc($sp)
  sll   $t5, $t4, 2
  lw    $s6, ($t6)
  addiu $t7, $sp, 0x7c
  sll   $t9, $t8, 2
  move  $a1, $s6
  beqz  $s6, .L7F0CEE84
   addiu $s6, $s6, -1
  addu  $t3, $t5, $t7
  addiu $t6, $sp, 0xc4
  addu  $t7, $t9, $t6
  li    $t9, 1
  addiu $t8, $s4, 0x1f
  sllv  $t6, $t9, $t8
  sw    $t6, 0x40($sp)
  sw    $t7, 0x44($sp)
.L7F0CEC18:
  addu  $v1, $t2, $s0
  slt   $at, $v1, $s4
  beqz  $at, .L7F0CED40
   addiu $s1, $s6, 1
  addiu $t7, $sp, 0x544
  addu  $t1, $t5, $t7
  lw    $t9, 0x5a8($sp)
.L7F0CEC34:
  addiu $t4, $t4, 1
  addiu $t5, $t5, 4
  subu  $t0, $t9, $v1
  sltu  $at, $s0, $t0
  addiu $t1, $t1, 4
  addiu $t3, $t3, 4
  beqz  $at, .L7F0CEC58
   move  $t2, $v1
  move  $t0, $s0
.L7F0CEC58:
  subu  $v0, $s4, $t2
  li    $t8, 1
  sllv  $a0, $t8, $v0
  sltu  $at, $s1, $a0
  beqz  $at, .L7F0CECB8
   move  $a3, $v0
  addiu $a3, $v0, 1
  subu  $v1, $a0, $s6
  sll   $t6, $s4, 2
  addiu $t7, $sp, 0x5b0
  sltu  $at, $a3, $t0
  addiu $v1, $v1, -1
  beqz  $at, .L7F0CECB8
   addu  $a2, $t6, $t7
.L7F0CEC90:
  lw    $a0, 4($a2)
  sll   $v0, $v1, 1
  addiu $a2, $a2, 4
  sltu  $at, $a0, $v0
  beql  $at, $zero, .L7F0CECBC
   lw    $v1, ($s2)
  addiu $a3, $a3, 1
  sltu  $at, $a3, $t0
  bnez  $at, .L7F0CEC90
   subu  $v1, $v0, $a0
.L7F0CECB8:
  lw    $v1, ($s2)
.L7F0CECBC:
  lw    $t6, ($s7)
  li    $t9, 1
  sllv  $t0, $t9, $a3
  sll   $t8, $v1, 3
  addu  $t7, $v1, $t0
  addiu $t9, $t7, 1
  addu  $a2, $t8, $t6
  sw    $t9, ($s2)
  addiu $a0, $a2, 8
  sw    $a0, ($s5)
  sw    $zero, 4($a2)
  addiu $s5, $a2, 4
  move  $a2, $a0
  beqz  $t4, .L7F0CED30
   sw    $a0, ($t1)
  sw    $ra, ($t3)
  addiu $t8, $a3, 0x10
  sb    $s0, 0x585($sp)
  sb    $t8, 0x584($sp)
  sw    $a0, 0x588($sp)
  lw    $t6, -4($t1)
  subu  $t7, $t2, $s0
  lw    $at, ($s3)
  srlv  $t9, $ra, $t7
  sll   $t8, $t9, 3
  addu  $t7, $t6, $t8
  sw    $at, ($t7)
  lw    $t8, 4($s3)
  sw    $t8, 4($t7)
.L7F0CED30:
  addu  $v1, $t2, $s0
  slt   $at, $v1, $s4
  bnezl $at, .L7F0CEC34
   lw    $t9, 0x5a8($sp)
.L7F0CED40:
  lw    $t9, 0x44($sp)
  li    $t6, 1
  subu  $v1, $s4, $t2
  sllv  $a1, $t6, $t2
  sltu  $at, $fp, $t9
  sb    $v1, 0x585($sp)
  bnez  $at, .L7F0CED6C
   addiu $a1, $a1, -1
  li    $t7, 99
  b     .L7F0CEDE8
   sb    $t7, 0x584($sp)
.L7F0CED6C:
  lw    $v0, ($fp)
  lw    $t8, 0x600($sp)
  lw    $a0, 0x600($sp)
  lw    $t6, 0x608($sp)
  sltu  $at, $v0, $t8
  beqz  $at, .L7F0CEDB0
   sltiu $at, $v0, 0x100
  beqz  $at, .L7F0CED9C
   li    $t9, 15
  li    $t6, 16
  b     .L7F0CEDA0
   sb    $t6, 0x584($sp)
.L7F0CED9C:
  sb    $t9, 0x584($sp)
.L7F0CEDA0:
  lw    $t7, ($fp)
  addiu $fp, $fp, 4
  b     .L7F0CEDE8
   sh    $t7, 0x588($sp)
.L7F0CEDB0:
  subu  $t8, $v0, $a0
  addu  $t9, $t8, $t6
  lbu   $t7, ($t9)
  lw    $t8, 0x604($sp)
  addiu $fp, $fp, 4
  sb    $t7, 0x584($sp)
  lw    $t6, -4($fp)
  sll   $t9, $t6, 1
  sll   $t6, $a0, 1
  addu  $t7, $t8, $t9
  negu  $t8, $t6
  addu  $t9, $t7, $t8
  lhu   $t6, ($t9)
  sh    $t6, 0x588($sp)
.L7F0CEDE8:
  srlv  $a3, $ra, $t2
  sltu  $at, $a3, $t0
  beqz  $at, .L7F0CEE20
   li    $t7, 1
  sllv  $v0, $t7, $v1
.L7F0CEDFC:
  lw    $at, ($s3)
  sll   $t8, $a3, 3
  addu  $t9, $a2, $t8
  sw    $at, ($t9)
  lw    $t7, 4($s3)
  addu  $a3, $a3, $v0
  sltu  $at, $a3, $t0
  bnez  $at, .L7F0CEDFC
   sw    $t7, 4($t9)
.L7F0CEE20:
  lw    $a3, 0x40($sp)
  lw    $v0, ($t3)
  and   $t8, $ra, $a3
  beqz  $t8, .L7F0CEE44
.L7F0CEE30:
   srl   $t6, $a3, 1
  xor   $ra, $ra, $a3
  and   $t9, $ra, $t6
  bnez  $t9, .L7F0CEE30
   move  $a3, $t6
.L7F0CEE44:
  xor   $ra, $ra, $a3
  and   $t7, $ra, $a1
  beq   $t7, $v0, .L7F0CEE7C
   move  $a1, $s6
.L7F0CEE54:
  subu  $t2, $t2, $s0
  li    $t8, 1
  sllv  $t6, $t8, $t2
  lw    $t8, -4($t3)
  addiu $t9, $t6, -1
  and   $t7, $ra, $t9
  addiu $t4, $t4, -1
  addiu $t5, $t5, -4
  bne   $t7, $t8, .L7F0CEE54
   addiu $t3, $t3, -4
.L7F0CEE7C:
  bnez  $s6, .L7F0CEC18
   addiu $s6, $s6, -1
.L7F0CEE84:
  lw    $t6, 0x5c($sp)
  lw    $t7, 0x5a8($sp)
  addiu $s4, $s4, 1
  addiu $t9, $t6, 4
  slt   $at, $t7, $s4
  beqz  $at, .L7F0CEBD4
   sw    $t9, 0x5c($sp)
  sw    $s5, 0x60c($sp)
.L7F0CEEA4:
  lw    $v0, 0x74($sp)
  sltu  $t8, $zero, $v0
  beqz  $t8, .L7F0CEEC0
   move  $v0, $t8
  lw    $v0, 0x5a8($sp)
  xori  $t6, $v0, 1
  sltu  $v0, $zero, $t6
.L7F0CEEC0:
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
   addiu $sp, $sp, 0x5f8
");

asm(R"
glabel sub_GAME_7F0CEEF0
  addiu $sp, $sp, -0x70
  lui   $t1, %hi(D_8004E9B0) 
  addiu $t1, %lo(D_8004E9B0) # addiu $t1, $t1, -0x1650
  sw    $fp, 0x38($sp)
  sw    $s7, 0x34($sp)
  sw    $s5, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s1, 0x1c($sp)
  sll   $t7, $a2, 1
  sll   $t9, $a3, 1
  sw    $ra, 0x3c($sp)
  sw    $a3, 0x7c($sp)
  lui   $s4, %hi(dword_CODE_bss_8008D364)
  lui   $s1, %hi(dword_CODE_bss_8008D368)
  lui   $s5, %hi(dword_CODE_bss_8008D35C)
  addu  $t4, $t1, $t7
  addu  $t5, $t1, $t9
  lui   $s3, %hi(dword_CODE_bss_8008D358)
  lui   $s7, %hi(dword_CODE_bss_8008D354) 
  lui   $fp, %hi(dword_CODE_bss_8008D350) 
  sw    $s6, 0x30($sp)
  sw    $s2, 0x20($sp)
  sw    $s0, 0x18($sp)
  sw    $a0, 0x70($sp)
  sw    $a1, 0x74($sp)
  sw    $a2, 0x78($sp)
  lw    $s4, %lo(dword_CODE_bss_8008D364)($s4)
  lw    $s1, %lo(dword_CODE_bss_8008D368)($s1)
  lw    $s5, %lo(dword_CODE_bss_8008D35C)($s5)
  lhu   $t2, ($t4)
  lhu   $t3, ($t5)
  addiu $fp, %lo(dword_CODE_bss_8008D350) # addiu $fp, $fp, -0x2cb0
  addiu $s7, %lo(dword_CODE_bss_8008D354) # addiu $s7, $s7, -0x2cac
  addiu $s3, %lo(dword_CODE_bss_8008D358) # addiu $s3, $s3, -0x2ca8
  li    $a3, 32768
  move  $ra, $a2
.L7F0CEF84:
  sltu  $at, $s1, $ra
.L7F0CEF88:
  beql  $at, $zero, .L7F0CEFC0
   lw    $t9, 0x70($sp)
  lw    $v1, ($fp)
.L7F0CEF94:
  lw    $v0, ($s3)
  addu  $t7, $v1, $v0
  lbu   $t8, ($t7)
  addiu $t6, $v0, 1
  sw    $t6, ($s3)
  sllv  $t9, $t8, $s1
  addiu $s1, $s1, 8
  sltu  $at, $s1, $ra
  bnez  $at, .L7F0CEF94
   or    $s4, $s4, $t9
  lw    $t9, 0x70($sp)
.L7F0CEFC0:
  and   $t7, $s4, $t2
  sll   $t8, $t7, 3
  addu  $a2, $t8, $t9
  lbu   $s2, ($a2)
  sltiu $at, $s2, 0x11
  bnezl $at, .L7F0CF050
   lbu   $v0, 1($a2)
  lbu   $v0, 1($a2)
.L7F0CEFE0:
  addiu $s2, $s2, -0x10
  subu  $s1, $s1, $v0
  sltu  $at, $s1, $s2
  beqz  $at, .L7F0CF020
   srlv  $s4, $s4, $v0
  lw    $v1, ($fp)
.L7F0CEFF8:
  lw    $v0, ($s3)
  addu  $t6, $v1, $v0
  lbu   $t7, ($t6)
  addiu $t9, $v0, 1
  sw    $t9, ($s3)
  sllv  $t8, $t7, $s1
  addiu $s1, $s1, 8
  sltu  $at, $s1, $s2
  bnez  $at, .L7F0CEFF8
   or    $s4, $s4, $t8
.L7F0CF020:
  sll   $t6, $s2, 1
  addu  $t7, $t1, $t6
  lhu   $t8, ($t7)
  lw    $t7, 4($a2)
  and   $t9, $t8, $s4
  sll   $t6, $t9, 3
  addu  $a2, $t6, $t7
  lbu   $s2, ($a2)
  sltiu $at, $s2, 0x11
  beql  $at, $zero, .L7F0CEFE0
   lbu   $v0, 1($a2)
  lbu   $v0, 1($a2)
.L7F0CF050:
  li    $at, 16
  srlv  $s4, $s4, $v0
  bne   $s2, $at, .L7F0CF0A8
   subu  $s1, $s1, $v0
  lw    $t8, ($s7)
  lw    $t9, ($fp)
  lw    $t6, ($s3)
  addu  $a1, $t8, $s5
  move  $v0, $a1
  addu  $a0, $t9, $t6
  sltu  $at, $a1, $a0
  bnez  $at, .L7F0CF098
   subu  $t7, $v0, $a0
  sltu  $at, $t7, $a3
  beql  $at, $zero, .L7F0CF09C
   lhu   $t8, 4($a2)
.L7F0CF090:
  b     .L7F0CF090
   nop   
.L7F0CF098:
  lhu   $t8, 4($a2)
.L7F0CF09C:
  addiu $s5, $s5, 1
  b     .L7F0CEF84
   sb    $t8, ($a1)
.L7F0CF0A8:
  li    $at, 15
  beq   $s2, $at, .L7F0CF340
   sltu  $at, $s1, $s2
  beql  $at, $zero, .L7F0CF0EC
   sll   $t9, $s2, 1
  lw    $v1, ($fp)
.L7F0CF0C0:
  lw    $v0, ($s3)
  addu  $t9, $v1, $v0
  lbu   $t6, ($t9)
  addiu $t8, $v0, 1
  sw    $t8, ($s3)
  sllv  $t7, $t6, $s1
  addiu $s1, $s1, 8
  sltu  $at, $s1, $s2
  bnez  $at, .L7F0CF0C0
   or    $s4, $s4, $t7
  sll   $t9, $s2, 1
.L7F0CF0EC:
  addu  $t6, $t1, $t9
  lhu   $t7, ($t6)
  lw    $t6, 0x7c($sp)
  lhu   $t9, 4($a2)
  subu  $s1, $s1, $s2
  and   $t8, $t7, $s4
  sltu  $at, $s1, $t6
  srlv  $s4, $s4, $s2
  beqz  $at, .L7F0CF144
   addu  $t0, $t8, $t9
  lw    $v1, ($fp)
  move  $a0, $t6
.L7F0CF11C:
  lw    $v0, ($s3)
  addu  $t7, $v1, $v0
  lbu   $t8, ($t7)
  addiu $t6, $v0, 1
  sw    $t6, ($s3)
  sllv  $t9, $t8, $s1
  addiu $s1, $s1, 8
  sltu  $at, $s1, $a0
  bnez  $at, .L7F0CF11C
   or    $s4, $s4, $t9
.L7F0CF144:
  lw    $t9, 0x74($sp)
  and   $t7, $s4, $t3
  sll   $t8, $t7, 3
  addu  $a2, $t8, $t9
  lbu   $s2, ($a2)
  sltiu $at, $s2, 0x11
  bnezl $at, .L7F0CF1D8
   lbu   $v0, 1($a2)
  lbu   $v0, 1($a2)
.L7F0CF168:
  addiu $s2, $s2, -0x10
  subu  $s1, $s1, $v0
  sltu  $at, $s1, $s2
  beqz  $at, .L7F0CF1A8
   srlv  $s4, $s4, $v0
  lw    $v1, ($fp)
.L7F0CF180:
  lw    $v0, ($s3)
  addu  $t6, $v1, $v0
  lbu   $t7, ($t6)
  addiu $t9, $v0, 1
  sw    $t9, ($s3)
  sllv  $t8, $t7, $s1
  addiu $s1, $s1, 8
  sltu  $at, $s1, $s2
  bnez  $at, .L7F0CF180
   or    $s4, $s4, $t8
.L7F0CF1A8:
  sll   $t6, $s2, 1
  addu  $t7, $t1, $t6
  lhu   $t8, ($t7)
  lw    $t7, 4($a2)
  and   $t9, $t8, $s4
  sll   $t6, $t9, 3
  addu  $a2, $t6, $t7
  lbu   $s2, ($a2)
  sltiu $at, $s2, 0x11
  beql  $at, $zero, .L7F0CF168
   lbu   $v0, 1($a2)
  lbu   $v0, 1($a2)
.L7F0CF1D8:
  subu  $s1, $s1, $v0
  sltu  $at, $s1, $s2
  beqz  $at, .L7F0CF214
   srlv  $s4, $s4, $v0
  lw    $v1, ($fp)
.L7F0CF1EC:
  lw    $v0, ($s3)
  addu  $t8, $v1, $v0
  lbu   $t9, ($t8)
  addiu $t7, $v0, 1
  sw    $t7, ($s3)
  sllv  $t6, $t9, $s1
  addiu $s1, $s1, 8
  sltu  $at, $s1, $s2
  bnez  $at, .L7F0CF1EC
   or    $s4, $s4, $t6
.L7F0CF214:
  lhu   $t8, 4($a2)
  sll   $t6, $s2, 1
  addu  $t7, $t1, $t6
  subu  $t9, $s5, $t8
  lhu   $t8, ($t7)
  subu  $s1, $s1, $s2
  and   $t6, $t8, $s4
  subu  $s0, $t9, $t6
  srlv  $s4, $s4, $s2
  move  $s2, $t0
.L7F0CF23C:
  subu  $t7, $s5, $s0
  sltu  $at, $t7, $s2
  bnez  $at, .L7F0CF2DC
   move  $t0, $zero
  lw    $v1, ($s7)
  lw    $t8, ($fp)
  lw    $t9, ($s3)
  addu  $s6, $s5, $s2
  addu  $v0, $s6, $v1
  addiu $v0, $v0, -1
  addu  $a0, $t8, $t9
  sltu  $at, $v0, $a0
  bnez  $at, .L7F0CF288
   subu  $t6, $v0, $a0
  sltu  $at, $t6, $a3
  beql  $at, $zero, .L7F0CF28C
   addu  $a0, $v1, $s5
.L7F0CF280:
  b     .L7F0CF280
   nop   
.L7F0CF288:
  addu  $a0, $v1, $s5
.L7F0CF28C:
  addu  $a1, $v1, $s0
  move  $a2, $s2
  sw    $t0, 0x68($sp)
  sw    $t2, 0x58($sp)
  sw    $t3, 0x54($sp)
  sw    $t4, 0x44($sp)
  jal   memcpy
   sw    $t5, 0x40($sp)
  lui   $t1, %hi(D_8004E9B0) 
  addiu $t1, %lo(D_8004E9B0) # addiu $t1, $t1, -0x1650
  li    $a3, 32768
  lw    $t0, 0x68($sp)
  lw    $t2, 0x58($sp)
  lw    $t3, 0x54($sp)
  lw    $t4, 0x44($sp)
  lw    $t5, 0x40($sp)
  lw    $ra, 0x78($sp)
  move  $s5, $s6
  b     .L7F0CF330
   addu  $s0, $s0, $s2
.L7F0CF2DC:
  lw    $v1, ($s7)
  lw    $t7, ($fp)
  lw    $t8, ($s3)
  addu  $a1, $v1, $s5
  move  $v0, $a1
  addu  $a0, $t7, $t8
  sltu  $at, $a1, $a0
  bnez  $at, .L7F0CF314
   subu  $t9, $v0, $a0
  sltu  $at, $t9, $a3
  beql  $at, $zero, .L7F0CF318
   addu  $t6, $s0, $v1
.L7F0CF30C:
  b     .L7F0CF30C
   nop   
.L7F0CF314:
  addu  $t6, $s0, $v1
.L7F0CF318:
  lbu   $t7, ($t6)
  addiu $s2, $s2, -1
  addiu $s0, $s0, 1
  addiu $s5, $s5, 1
  bnez  $s2, .L7F0CF2DC
   sb    $t7, ($a1)
.L7F0CF330:
  bnezl $t0, .L7F0CF23C
   move  $s2, $t0
  b     .L7F0CEF88
   sltu  $at, $s1, $ra
.L7F0CF340:
  lui   $at, %hi(dword_CODE_bss_8008D35C)
  sw    $s5, %lo(dword_CODE_bss_8008D35C)($at)
  lui   $at, %hi(dword_CODE_bss_8008D364)
  sw    $s4, %lo(dword_CODE_bss_8008D364)($at)
  lw    $ra, 0x3c($sp)
  lui   $at, %hi(dword_CODE_bss_8008D368)
  sw    $s1, %lo(dword_CODE_bss_8008D368)($at)
  lw    $s1, 0x1c($sp)
  lw    $s4, 0x28($sp)
  lw    $s5, 0x2c($sp)
  lw    $s0, 0x18($sp)
  lw    $s2, 0x20($sp)
  lw    $s3, 0x24($sp)
  lw    $s6, 0x30($sp)
  lw    $s7, 0x34($sp)
  lw    $fp, 0x38($sp)
  addiu $sp, $sp, 0x70
  jr    $ra
   move  $v0, $zero
");

asm(R"
glabel zlib_decompressor_type0
  lui   $t3, %hi(dword_CODE_bss_8008D368) 
  addiu $t3, %lo(dword_CODE_bss_8008D368) # addiu $t3, $t3, -0x2c98
  lw    $a0, ($t3)
  lui   $t2, %hi(dword_CODE_bss_8008D364) 
  addiu $t2, %lo(dword_CODE_bss_8008D364) # addiu $t2, $t2, -0x2c9c
  andi  $v0, $a0, 7
  lw    $v1, ($t2)
  lui   $t4, %hi(dword_CODE_bss_8008D35C) 
  subu  $a0, $a0, $v0
  addiu $t4, %lo(dword_CODE_bss_8008D35C) # addiu $t4, $t4, -0x2ca4
  addiu $sp, $sp, -0x10
  sltiu $at, $a0, 0x10
  sw    $s1, 0xc($sp)
  sw    $s0, 8($sp)
  lw    $a1, ($t4)
  beqz  $at, .L7F0CF408
   srlv  $v1, $v1, $v0
  lui   $a2, %hi(dword_CODE_bss_8008D350)
  lui   $t5, %hi(dword_CODE_bss_8008D358) 
  addiu $t5, %lo(dword_CODE_bss_8008D358) # addiu $t5, $t5, -0x2ca8
  lw    $a2, %lo(dword_CODE_bss_8008D350)($a2)
.L7F0CF3E0:
  lw    $a3, ($t5)
  addu  $t6, $a2, $a3
  lbu   $t7, ($t6)
  addiu $t9, $a3, 1
  sw    $t9, ($t5)
  sllv  $t8, $t7, $a0
  addiu $a0, $a0, 8
  sltiu $at, $a0, 0x10
  bnez  $at, .L7F0CF3E0
   or    $v1, $v1, $t8
.L7F0CF408:
  addiu $a0, $a0, -0x10
  lui   $t5, %hi(dword_CODE_bss_8008D358) 
  andi  $v0, $v1, 0xffff
  srl   $t6, $v1, 0x10
  sltiu $at, $a0, 0x10
  addiu $t5, %lo(dword_CODE_bss_8008D358) # addiu $t5, $t5, -0x2ca8
  beqz  $at, .L7F0CF458
   move  $v1, $t6
  lui   $a2, %hi(dword_CODE_bss_8008D350)
  lw    $a2, %lo(dword_CODE_bss_8008D350)($a2)
.L7F0CF430:
  lw    $a3, ($t5)
  addu  $t7, $a2, $a3
  lbu   $t8, ($t7)
  addiu $t6, $a3, 1
  sw    $t6, ($t5)
  sllv  $t9, $t8, $a0
  addiu $a0, $a0, 8
  sltiu $at, $a0, 0x10
  bnez  $at, .L7F0CF430
   or    $v1, $v1, $t9
.L7F0CF458:
  move  $a2, $v0
  srl   $t7, $v1, 0x10
  move  $v1, $t7
  addiu $a0, $a0, -0x10
  beqz  $v0, .L7F0CF508
   addiu $v0, $v0, -1
  lui   $s0, %hi(dword_CODE_bss_8008D354)
  addiu $s0, %lo(dword_CODE_bss_8008D354) # addiu $s0, $s0, -0x2cac
  li    $s1, 32768
.L7F0CF47C:
  lui   $a2, %hi(dword_CODE_bss_8008D350)
  sltiu $at, $a0, 8
  beqz  $at, .L7F0CF4B4
   lw    $a2, %lo(dword_CODE_bss_8008D350)($a2)
.L7F0CF48C:
  lw    $a3, ($t5)
  addu  $t8, $a2, $a3
  lbu   $t9, ($t8)
  addiu $t7, $a3, 1
  sw    $t7, ($t5)
  sllv  $t6, $t9, $a0
  addiu $a0, $a0, 8
  sltiu $at, $a0, 8
  bnez  $at, .L7F0CF48C
   or    $v1, $v1, $t6
.L7F0CF4B4:
  lw    $t8, ($s0)
  lw    $t9, ($t5)
  srl   $t7, $v1, 8
  addu  $a3, $t8, $a1
  addu  $t1, $a2, $t9
  sltu  $at, $a3, $t1
  bnez  $at, .L7F0CF4EC
   move  $t0, $a3
  subu  $t6, $t0, $t1
  sltu  $at, $t6, $s1
  beql  $at, $zero, .L7F0CF4F0
   move  $a2, $v0
.L7F0CF4E4:
  b     .L7F0CF4E4
   nop   
.L7F0CF4EC:
  move  $a2, $v0
.L7F0CF4F0:
  sb    $v1, ($a3)
  addiu $a1, $a1, 1
  move  $v1, $t7
  addiu $a0, $a0, -8
  bnez  $v0, .L7F0CF47C
   addiu $v0, $v0, -1
.L7F0CF508:
  lw    $s0, 8($sp)
  lw    $s1, 0xc($sp)
  sw    $a1, ($t4)
  sw    $v1, ($t2)
  sw    $a0, ($t3)
  addiu $sp, $sp, 0x10
  jr    $ra
   move  $v0, $zero
");

asm(R"
glabel zlib_decompressor_type1
  addiu $sp, $sp, -0x4c0
  sw    $ra, 0x24($sp)
  addiu $v0, $sp, 0x2c
  addiu $a0, $sp, 0x26c
  li    $v1, 8
.L7F0CF53C:
  addiu $v0, $v0, 0x10
  sw    $v1, -0xc($v0)
  sw    $v1, -8($v0)
  sw    $v1, -4($v0)
  bne   $v0, $a0, .L7F0CF53C
   sw    $v1, -0x10($v0)
  addiu $t6, $sp, 0x42c
  sltu  $at, $v0, $t6
  beqz  $at, .L7F0CF57C
   addiu $t7, $sp, 0x48c
  addiu $a1, $sp, 0x42c
  li    $a0, 9
.L7F0CF56C:
  addiu $v0, $v0, 4
  sltu  $at, $v0, $a1
  bnez  $at, .L7F0CF56C
   sw    $a0, -4($v0)
.L7F0CF57C:
  sltu  $at, $v0, $t7
  beqz  $at, .L7F0CF5A0
   addiu $t8, $sp, 0x4ac
  addiu $a1, $sp, 0x48c
  li    $a0, 7
.L7F0CF590:
  addiu $v0, $v0, 4
  sltu  $at, $v0, $a1
  bnez  $at, .L7F0CF590
   sw    $a0, -4($v0)
.L7F0CF5A0:
  sltu  $at, $v0, $t8
  beqz  $at, .L7F0CF5C0
   li    $t9, 7
  addiu $a0, $sp, 0x4ac
.L7F0CF5B0:
  addiu $v0, $v0, 4
  sltu  $at, $v0, $a0
  bnez  $at, .L7F0CF5B0
   sw    $v1, -4($v0)
.L7F0CF5C0:
  lui   $t0, %hi(D_8004E934) 
  addiu $t0, %lo(D_8004E934) # addiu $t0, $t0, -0x16cc
  lui   $a3, %hi(D_8004E8F4)
  addiu $t1, $sp, 0x4b8
  addiu $t2, $sp, 0x4b0
  sw    $t9, 0x4b0($sp)
  sw    $t2, 0x18($sp)
  sw    $t1, 0x14($sp)
  addiu $a3, %lo(D_8004E8F4) # addiu $a3, $a3, -0x170c
  sw    $t0, 0x10($sp)
  addiu $a0, $sp, 0x2c
  li    $a1, 288
  jal   sub_GAME_7F0CE8B0
   li    $a2, 257
  li    $t3, 5
  li    $t4, 5
  sw    $t4, 0x30($sp)
  sw    $t3, 0x2c($sp)
  addiu $v0, $sp, 0x34
  addiu $a0, $sp, 0xa4
  li    $v1, 5
.L7F0CF614:
  addiu $v0, $v0, 0x10
  sw    $v1, -0xc($v0)
  sw    $v1, -8($v0)
  sw    $v1, -4($v0)
  bne   $v0, $a0, .L7F0CF614
   sw    $v1, -0x10($v0)
  lui   $t6, %hi(D_8004E990) 
  li    $t5, 5
  addiu $t6, %lo(D_8004E990) # addiu $t6, $t6, -0x1670
  lui   $a3, %hi(D_8004E954)
  addiu $t7, $sp, 0x4b4
  addiu $t8, $sp, 0x4ac
  sw    $t5, 0x4ac($sp)
  sw    $t8, 0x18($sp)
  sw    $t7, 0x14($sp)
  addiu $a3, %lo(D_8004E954) # addiu $a3, $a3, -0x16ac
  sw    $t6, 0x10($sp)
  addiu $a0, $sp, 0x2c
  li    $a1, 30
  jal   sub_GAME_7F0CE8B0
   move  $a2, $zero
  lw    $a0, 0x4b8($sp)
  lw    $a1, 0x4b4($sp)
  lw    $a2, 0x4b0($sp)
  jal   sub_GAME_7F0CEEF0
   lw    $a3, 0x4ac($sp)
  lw    $ra, 0x24($sp)
  addiu $sp, $sp, 0x4c0
  move  $v0, $zero
  jr    $ra
   nop   
");

asm(R"
glabel zlib_decompressor_type2
  lui   $t0, %hi(dword_CODE_bss_8008D368) 
  lw    $t0, %lo(dword_CODE_bss_8008D368)($t0)
  addiu $sp, $sp, -0x568
  lui   $t1, %hi(dword_CODE_bss_8008D364) 
  sltiu $at, $t0, 5
  sw    $ra, 0x2c($sp)
  sw    $s0, 0x28($sp)
  beqz  $at, .L7F0CF6EC
   lw    $t1, %lo(dword_CODE_bss_8008D364)($t1)
  lui   $v1, %hi(dword_CODE_bss_8008D350)
  lui   $t2, %hi(dword_CODE_bss_8008D358) 
  addiu $t2, %lo(dword_CODE_bss_8008D358) # addiu $t2, $t2, -0x2ca8
  lw    $v1, %lo(dword_CODE_bss_8008D350)($v1)
.L7F0CF6C4:
  lw    $v0, ($t2)
  addu  $t6, $v1, $v0
  lbu   $t7, ($t6)
  addiu $t9, $v0, 1
  sw    $t9, ($t2)
  sllv  $t8, $t7, $t0
  addiu $t0, $t0, 8
  sltiu $at, $t0, 5
  bnez  $at, .L7F0CF6C4
   or    $t1, $t1, $t8
.L7F0CF6EC:
  andi  $t6, $t1, 0x1f
  addiu $t0, $t0, -5
  lui   $t2, %hi(dword_CODE_bss_8008D358) 
  addiu $t7, $t6, 0x101
  srl   $t8, $t1, 5
  sltiu $at, $t0, 5
  addiu $t2, %lo(dword_CODE_bss_8008D358) # addiu $t2, $t2, -0x2ca8
  sw    $t7, 0x53c($sp)
  beqz  $at, .L7F0CF744
   move  $t1, $t8
  lui   $v1, %hi(dword_CODE_bss_8008D350)
  lw    $v1, %lo(dword_CODE_bss_8008D350)($v1)
.L7F0CF71C:
  lw    $v0, ($t2)
  addu  $t9, $v1, $v0
  lbu   $t6, ($t9)
  addiu $t8, $v0, 1
  sw    $t8, ($t2)
  sllv  $t7, $t6, $t0
  addiu $t0, $t0, 8
  sltiu $at, $t0, 5
  bnez  $at, .L7F0CF71C
   or    $t1, $t1, $t7
.L7F0CF744:
  andi  $t9, $t1, 0x1f
  addiu $t0, $t0, -5
  addiu $t6, $t9, 1
  srl   $t7, $t1, 5
  sltiu $at, $t0, 4
  sw    $t6, 0x538($sp)
  beqz  $at, .L7F0CF794
   move  $t1, $t7
  lui   $v1, %hi(dword_CODE_bss_8008D350)
  lw    $v1, %lo(dword_CODE_bss_8008D350)($v1)
.L7F0CF76C:
  lw    $v0, ($t2)
  addu  $t8, $v1, $v0
  lbu   $t9, ($t8)
  addiu $t7, $v0, 1
  sw    $t7, ($t2)
  sllv  $t6, $t9, $t0
  addiu $t0, $t0, 8
  sltiu $at, $t0, 4
  bnez  $at, .L7F0CF76C
   or    $t1, $t1, $t6
.L7F0CF794:
  andi  $a2, $t1, 0xf
  addiu $a2, $a2, 4
  srl   $t8, $t1, 4
  move  $t1, $t8
  addiu $t0, $t0, -4
  beqz  $a2, .L7F0CF820
   move  $a0, $zero
  lui   $a1, %hi(D_8004E8E0)
  addiu $a1, %lo(D_8004E8E0) # addiu $a1, $a1, -0x1720
  addiu $s0, $sp, 0x40
.L7F0CF7BC:
  sltiu $at, $t0, 3
  beqz  $at, .L7F0CF7F8
   addiu $a0, $a0, 1
  lui   $v1, %hi(dword_CODE_bss_8008D350)
  lw    $v1, %lo(dword_CODE_bss_8008D350)($v1)
.L7F0CF7D0:
  lw    $v0, ($t2)
  addu  $t9, $v1, $v0
  lbu   $t6, ($t9)
  addiu $t8, $v0, 1
  sw    $t8, ($t2)
  sllv  $t7, $t6, $t0
  addiu $t0, $t0, 8
  sltiu $at, $t0, 3
  bnez  $at, .L7F0CF7D0
   or    $t1, $t1, $t7
.L7F0CF7F8:
  lbu   $t6, ($a1)
  andi  $t9, $t1, 7
  addiu $a1, $a1, 1
  sll   $t7, $t6, 2
  addu  $t8, $s0, $t7
  srl   $t6, $t1, 3
  sw    $t9, ($t8)
  move  $t1, $t6
  bne   $a0, $a2, .L7F0CF7BC
   addiu $t0, $t0, -3
.L7F0CF820:
  sltiu $at, $a0, 0x13
  beqz  $at, .L7F0CF85C
   addiu $s0, $sp, 0x40
  lui   $t7, %hi(D_8004E8E0) 
  addiu $t7, %lo(D_8004E8E0) # addiu $t7, $t7, -0x1720
  lui   $v0, %hi(D_8004E8E0+0x13)
  addiu $v0, %lo(D_8004E8E0+0x13) # addiu $v0, $v0, -0x170d
  addu  $a1, $a0, $t7
.L7F0CF840:
  lbu   $t9, ($a1)
  addiu $a1, $a1, 1
  sltu  $at, $a1, $v0
  sll   $t8, $t9, 2
  addu  $t6, $s0, $t8
  bnez  $at, .L7F0CF840
   sw    $zero, ($t6)
.L7F0CF85C:
  li    $t7, 7
  addiu $t9, $sp, 0x550
  addiu $t8, $sp, 0x548
  sw    $t7, 0x548($sp)
  sw    $t8, 0x18($sp)
  sw    $t9, 0x14($sp)
  move  $a0, $s0
  li    $a1, 19
  li    $a2, 19
  move  $a3, $zero
  sw    $zero, 0x10($sp)
  sw    $t0, 0x534($sp)
  jal   sub_GAME_7F0CE8B0
   sw    $t1, 0x530($sp)
  lw    $t9, 0x548($sp)
  lw    $t6, 0x53c($sp)
  lw    $t7, 0x538($sp)
  lui   $t3, %hi(D_8004E9B0)
  sll   $t8, $t9, 1
  lui   $t2, %hi(dword_CODE_bss_8008D358) 
  addu  $t3, $t3, $t8
  addu  $a3, $t6, $t7
  addiu $t2, %lo(dword_CODE_bss_8008D358) # addiu $t2, $t2, -0x2ca8
  lw    $t0, 0x534($sp)
  lw    $t1, 0x530($sp)
  lhu   $t3, %lo(D_8004E9B0)($t3)
  move  $a2, $zero
  beqz  $a3, .L7F0CFAF4
   move  $a1, $zero
  li    $t5, 17
  li    $t4, 16
  lw    $t6, 0x548($sp)
.L7F0CF8DC:
  lui   $v1, %hi(dword_CODE_bss_8008D350)
  sltu  $at, $t0, $t6
  beql  $at, $zero, .L7F0CF920
   lw    $t6, 0x550($sp)
  lw    $v1, %lo(dword_CODE_bss_8008D350)($v1)
.L7F0CF8F0:
  lw    $v0, ($t2)
  addu  $t7, $v1, $v0
  lbu   $t9, ($t7)
  lw    $t7, 0x548($sp)
  addiu $t6, $v0, 1
  sllv  $t8, $t9, $t0
  addiu $t0, $t0, 8
  sltu  $at, $t0, $t7
  or    $t1, $t1, $t8
  bnez  $at, .L7F0CF8F0
   sw    $t6, ($t2)
  lw    $t6, 0x550($sp)
.L7F0CF920:
  and   $t9, $t1, $t3
  sll   $t8, $t9, 3
  addu  $t7, $t8, $t6
  sw    $t7, 0x54c($sp)
  lbu   $a0, 1($t7)
  sll   $t9, $a1, 2
  addu  $t8, $s0, $t9
  srlv  $t1, $t1, $a0
  subu  $t0, $t0, $a0
  lhu   $a0, 4($t7)
  sltiu $at, $a0, 0x10
  beqz  $at, .L7F0CF964
   nop   
  move  $a2, $a0
  sw    $a0, ($t8)
  b     .L7F0CFAE8
   addiu $a1, $a1, 1
.L7F0CF964:
  bne   $a0, $t4, .L7F0CF9E8
   sltiu $at, $t0, 2
  beqz  $at, .L7F0CF9A0
   lui   $v1, %hi(dword_CODE_bss_8008D350)
  lw    $v1, %lo(dword_CODE_bss_8008D350)($v1)
.L7F0CF978:
  lw    $v0, ($t2)
  addu  $t6, $v1, $v0
  lbu   $t7, ($t6)
  addiu $t8, $v0, 1
  sw    $t8, ($t2)
  sllv  $t9, $t7, $t0
  addiu $t0, $t0, 8
  sltiu $at, $t0, 2
  bnez  $at, .L7F0CF978
   or    $t1, $t1, $t9
.L7F0CF9A0:
  andi  $a0, $t1, 3
  addiu $a0, $a0, 3
  move  $v1, $a0
  srl   $t6, $t1, 2
  move  $t1, $t6
  addiu $t0, $t0, -2
  beqz  $a0, .L7F0CFAE8
   addiu $a0, $a0, -1
  sll   $t7, $a1, 2
  addu  $v0, $s0, $t7
.L7F0CF9C8:
  move  $v1, $a0
  sw    $a2, ($v0)
  addiu $a1, $a1, 1
  addiu $v0, $v0, 4
  bnez  $a0, .L7F0CF9C8
   addiu $a0, $a0, -1
  b     .L7F0CFAEC
   sltu  $at, $a1, $a3
.L7F0CF9E8:
  bne   $a0, $t5, .L7F0CFA70
   move  $a2, $zero
  sltiu $at, $t0, 3
  beqz  $at, .L7F0CFA28
   lui   $v1, %hi(dword_CODE_bss_8008D350)
  lw    $v1, %lo(dword_CODE_bss_8008D350)($v1)
.L7F0CFA00:
  lw    $v0, ($t2)
  addu  $t9, $v1, $v0
  lbu   $t8, ($t9)
  addiu $t7, $v0, 1
  sw    $t7, ($t2)
  sllv  $t6, $t8, $t0
  addiu $t0, $t0, 8
  sltiu $at, $t0, 3
  bnez  $at, .L7F0CFA00
   or    $t1, $t1, $t6
.L7F0CFA28:
  andi  $a0, $t1, 7
  addiu $a0, $a0, 3
  move  $v1, $a0
  srl   $t9, $t1, 3
  move  $t1, $t9
  addiu $t0, $t0, -3
  beqz  $a0, .L7F0CFAE8
   addiu $a0, $a0, -1
  sll   $t8, $a1, 2
  addu  $v0, $s0, $t8
.L7F0CFA50:
  move  $v1, $a0
  sw    $zero, ($v0)
  addiu $a1, $a1, 1
  addiu $v0, $v0, 4
  bnez  $a0, .L7F0CFA50
   addiu $a0, $a0, -1
  b     .L7F0CFAEC
   sltu  $at, $a1, $a3
.L7F0CFA70:
  sltiu $at, $t0, 7
  beqz  $at, .L7F0CFAA8
   lui   $v1, %hi(dword_CODE_bss_8008D350)
  lw    $v1, %lo(dword_CODE_bss_8008D350)($v1)
.L7F0CFA80:
  lw    $v0, ($t2)
  addu  $t6, $v1, $v0
  lbu   $t7, ($t6)
  addiu $t8, $v0, 1
  sw    $t8, ($t2)
  sllv  $t9, $t7, $t0
  addiu $t0, $t0, 8
  sltiu $at, $t0, 7
  bnez  $at, .L7F0CFA80
   or    $t1, $t1, $t9
.L7F0CFAA8:
  andi  $a0, $t1, 0x7f
  addiu $a0, $a0, 0xb
  move  $v1, $a0
  srl   $t6, $t1, 7
  move  $t1, $t6
  addiu $t0, $t0, -7
  beqz  $a0, .L7F0CFAE8
   addiu $a0, $a0, -1
  sll   $t7, $a1, 2
  addu  $v0, $s0, $t7
.L7F0CFAD0:
  move  $v1, $a0
  sw    $zero, ($v0)
  addiu $a1, $a1, 1
  addiu $v0, $v0, 4
  bnez  $a0, .L7F0CFAD0
   addiu $a0, $a0, -1
.L7F0CFAE8:
  sltu  $at, $a1, $a3
.L7F0CFAEC:
  bnezl $at, .L7F0CF8DC
   lw    $t6, 0x548($sp)
.L7F0CFAF4:
  lui   $at, %hi(dword_CODE_bss_8008D364)
  lui   $t9, %hi(D_8004E9D4) 
  lw    $t9, %lo(D_8004E9D4)($t9)
  sw    $t1, %lo(dword_CODE_bss_8008D364)($at)
  lui   $t8, %hi(D_8004E934) 
  lui   $at, %hi(dword_CODE_bss_8008D368)
  addiu $t8, %lo(D_8004E934) # addiu $t8, $t8, -0x16cc
  lui   $a3, %hi(D_8004E8F4)
  addiu $t6, $sp, 0x550
  addiu $t7, $sp, 0x548
  sw    $t0, %lo(dword_CODE_bss_8008D368)($at)
  sw    $t7, 0x18($sp)
  sw    $t6, 0x14($sp)
  addiu $a3, %lo(D_8004E8F4) # addiu $a3, $a3, -0x170c
  sw    $t8, 0x10($sp)
  move  $a0, $s0
  lw    $a1, 0x53c($sp)
  li    $a2, 257
  jal   sub_GAME_7F0CE8B0
   sw    $t9, 0x548($sp)
  lui   $t9, %hi(D_8004E9D8) 
  lw    $t9, %lo(D_8004E9D8)($t9)
  lw    $t8, 0x53c($sp)
  lui   $t7, %hi(D_8004E990) 
  sw    $t9, 0x544($sp)
  sll   $t6, $t8, 2
  addiu $t8, $sp, 0x544
  addiu $t9, $sp, 0x54c
  addiu $t7, %lo(D_8004E990) # addiu $t7, $t7, -0x1670
  lui   $a3, %hi(D_8004E954)
  addiu $a3, %lo(D_8004E954) # addiu $a3, $a3, -0x16ac
  sw    $t7, 0x10($sp)
  sw    $t9, 0x14($sp)
  sw    $t8, 0x18($sp)
  addu  $a0, $s0, $t6
  lw    $a1, 0x538($sp)
  jal   sub_GAME_7F0CE8B0
   move  $a2, $zero
  lw    $a0, 0x550($sp)
  lw    $a1, 0x54c($sp)
  lw    $a2, 0x548($sp)
  jal   sub_GAME_7F0CEEF0
   lw    $a3, 0x544($sp)
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x28($sp)
  addiu $sp, $sp, 0x568
  jr    $ra
   move  $v0, $zero
");

asm(R"
glabel select_zlib_decompression_routine
  lui   $t1, %hi(dword_CODE_bss_8008D368) 
  addiu $t1, %lo(dword_CODE_bss_8008D368) # addiu $t1, $t1, -0x2c98
  lw    $v1, ($t1)
  lui   $t0, %hi(dword_CODE_bss_8008D364) 
  addiu $t0, %lo(dword_CODE_bss_8008D364) # addiu $t0, $t0, -0x2c9c
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  move  $a3, $a0
  bnez  $v1, .L7F0CFC10
   lw    $a1, ($t0)
  lui   $a2, %hi(dword_CODE_bss_8008D350)
  lui   $a0, %hi(dword_CODE_bss_8008D358)
  addiu $a0, %lo(dword_CODE_bss_8008D358) # addiu $a0, $a0, -0x2ca8
  lw    $a2, %lo(dword_CODE_bss_8008D350)($a2)
.L7F0CFBEC:
  lw    $v0, ($a0)
  addu  $t6, $a2, $v0
  lbu   $t7, ($t6)
  addiu $t9, $v0, 1
  sw    $t9, ($a0)
  sllv  $t8, $t7, $v1
  addiu $v1, $v1, 8
  beqz  $v1, .L7F0CFBEC
   or    $a1, $a1, $t8
.L7F0CFC10:
  addiu $v1, $v1, -1
  lui   $a0, %hi(dword_CODE_bss_8008D358)
  andi  $t2, $a1, 1
  srl   $t3, $a1, 1
  sltiu $at, $v1, 2
  addiu $a0, %lo(dword_CODE_bss_8008D358) # addiu $a0, $a0, -0x2ca8
  sw    $t2, ($a3)
  beqz  $at, .L7F0CFC64
   move  $a1, $t3
  lui   $a2, %hi(dword_CODE_bss_8008D350)
  lw    $a2, %lo(dword_CODE_bss_8008D350)($a2)
.L7F0CFC3C:
  lw    $v0, ($a0)
  addu  $t4, $a2, $v0
  lbu   $t5, ($t4)
  addiu $t7, $v0, 1
  sw    $t7, ($a0)
  sllv  $t6, $t5, $v1
  addiu $v1, $v1, 8
  sltiu $at, $v1, 2
  bnez  $at, .L7F0CFC3C
   or    $a1, $a1, $t6
.L7F0CFC64:
  andi  $v0, $a1, 3
  srl   $t8, $a1, 2
  addiu $v1, $v1, -2
  li    $at, 2
  sw    $t8, ($t0)
  bne   $v0, $at, .L7F0CFC90
   sw    $v1, ($t1)
  jal   zlib_decompressor_type2
   nop   
  b     .L7F0CFCC8
   lw    $ra, 0x14($sp)
.L7F0CFC90:
  bnez  $v0, .L7F0CFCA8
   li    $at, 1
  jal   zlib_decompressor_type0
   nop   
  b     .L7F0CFCC8
   lw    $ra, 0x14($sp)
.L7F0CFCA8:
  bnel  $v0, $at, .L7F0CFCC4
   li    $v0, 2
  jal   zlib_decompressor_type1
   nop   
  b     .L7F0CFCC8
   lw    $ra, 0x14($sp)
  li    $v0, 2
.L7F0CFCC4:
  lw    $ra, 0x14($sp)
.L7F0CFCC8:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel loop_to_decompress_entire_file
  addiu $sp, $sp, -0x38
  sw    $s2, 0x1c($sp)
  lui   $at, %hi(dword_CODE_bss_8008D35C)
  lui   $s2, %hi(dword_CODE_bss_8008D368)
  sw    $zero, %lo(dword_CODE_bss_8008D35C)($at)
  addiu $s2, %lo(dword_CODE_bss_8008D368) # addiu $s2, $s2, -0x2c98
  sw    $s0, 0x14($sp)
  sw    $s3, 0x20($sp)
  sw    $s1, 0x18($sp)
  sw    $zero, ($s2)
  lui   $at, %hi(dword_CODE_bss_8008D364)
  lui   $s0, %hi(dword_CODE_bss_8008D36C)
  sw    $ra, 0x24($sp)
  sw    $zero, %lo(dword_CODE_bss_8008D364)($at)
  move  $s1, $zero
  addiu $s0, %lo(dword_CODE_bss_8008D36C) # addiu $s0, $s0, -0x2c94
  addiu $s3, $sp, 0x34
  sw    $zero, ($s0)
.L7F0CFD1C:
  jal   select_zlib_decompression_routine
   move  $a0, $s3
  beqz  $v0, .L7F0CFD34
   lw    $t6, 0x34($sp)
  b     .L7F0CFD90
   lw    $ra, 0x24($sp)
.L7F0CFD34:
  lw    $v0, ($s0)
  sltu  $at, $s1, $v0
  beqz  $at, .L7F0CFD48
   nop   
  move  $s1, $v0
.L7F0CFD48:
  beql  $t6, $zero, .L7F0CFD1C
   sw    $zero, ($s0)
  lw    $v1, ($s2)
  lui   $v0, %hi(dword_CODE_bss_8008D358)
  addiu $v0, %lo(dword_CODE_bss_8008D358) # addiu $v0, $v0, -0x2ca8
  sltiu $at, $v1, 8
  bnezl $at, .L7F0CFD8C
   move  $v0, $zero
.L7F0CFD68:
  lw    $t8, ($v0)
  addiu $t7, $v1, -8
  sltiu $at, $t7, 8
  addiu $t9, $t8, -1
  sw    $t7, ($s2)
  sw    $t9, ($v0)
  beqz  $at, .L7F0CFD68
   move  $v1, $t7
  move  $v0, $zero
.L7F0CFD8C:
  lw    $ra, 0x24($sp)
.L7F0CFD90:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x38
");
