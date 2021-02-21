int dword_CODE_bss_8007A0D0;
int dword_CODE_bss_8007A0D4;
int dword_CODE_bss_8007A0D8;
int dword_CODE_bss_8007A0DC;
int dword_CODE_bss_8007A0E0;
int dword_CODE_bss_8007A0E4;
int dword_CODE_bss_8007A0E8;
int dword_CODE_bss_8007A0EC;
short word_CODE_bss_8007A0F0;
short word_CODE_bss_8007A0F2;

void null_init_main_1(void) {}

asm(R"
glabel sub_GAME_7F09B7A8
  lui   $v1, %hi(dword_CODE_bss_8007A0D4)
  lw    $v1, %lo(dword_CODE_bss_8007A0D4)($v1)
  move  $v0, $zero
  lui   $a0, %hi(dword_CODE_bss_8007A0E8)
  blez  $v1, .L7F09B7DC
   sll   $a1, $v1, 2
  addu  $a1, $a1, $v1
  sll   $a1, $a1, 2
  lw    $a0, %lo(dword_CODE_bss_8007A0E8)($a0)
.L7F09B7CC:
  addiu $v0, $v0, 0x14
  slt   $at, $v0, $a1
  bnez  $at, .L7F09B7CC
   addiu $a0, $a0, 0x14
.L7F09B7DC:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F09B7E4
  lui   $v1, %hi(dword_CODE_bss_8007A0DC)
  lw    $v1, %lo(dword_CODE_bss_8007A0DC)($v1)
  move  $v0, $zero
  lui   $a0, %hi(dword_CODE_bss_8007A0EC)
  blez  $v1, .L7F09B818
   sll   $a1, $v1, 2
  addu  $a1, $a1, $v1
  sll   $a1, $a1, 2
  lw    $a0, %lo(dword_CODE_bss_8007A0EC)($a0)
.L7F09B808:
  addiu $v0, $v0, 0x14
  slt   $at, $v0, $a1
  bnez  $at, .L7F09B808
   addiu $a0, $a0, 0x14
.L7F09B818:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F09B820
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   getPlayerCount
   nop   
  slti  $at, $v0, 2
  bnez  $at, .L7F09B874
   li    $v0, 500
  li    $t6, 3000
  lui   $at, %hi(dword_CODE_bss_8007A0D0)
  lui   $t0, %hi(dword_CODE_bss_8007A0D4) 
  sw    $t6, %lo(dword_CODE_bss_8007A0D0)($at)
  addiu $t0, %lo(dword_CODE_bss_8007A0D4) # addiu $t0, $t0, -0x5f2c
  li    $t7, 80
  lui   $t1, %hi(dword_CODE_bss_8007A0DC) 
  sw    $t7, ($t0)
  lui   $at, %hi(dword_CODE_bss_8007A0D8)
  addiu $t1, %lo(dword_CODE_bss_8007A0DC) # addiu $t1, $t1, -0x5f24
  li    $v1, 20
  sw    $v0, %lo(dword_CODE_bss_8007A0D8)($at)
  b     .L7F09B8F8
   sw    $v1, ($t1)
.L7F09B874:
  jal   sub_GAME_7F0BDF04
   nop   
  li    $at, 30
  beq   $v0, $at, .L7F09B8C8
   li    $at, 29
  beq   $v0, $at, .L7F09B8C8
   li    $v1, 20
  li    $v0, 500
  lui   $at, %hi(dword_CODE_bss_8007A0D0)
  lui   $t0, %hi(dword_CODE_bss_8007A0D4) 
  sw    $v0, %lo(dword_CODE_bss_8007A0D0)($at)
  addiu $t0, %lo(dword_CODE_bss_8007A0D4) # addiu $t0, $t0, -0x5f2c
  lui   $t1, %hi(dword_CODE_bss_8007A0DC) 
  sw    $v1, ($t0)
  lui   $at, %hi(dword_CODE_bss_8007A0D8)
  li    $t8, 1500
  addiu $t1, %lo(dword_CODE_bss_8007A0DC) # addiu $t1, $t1, -0x5f24
  sw    $t8, %lo(dword_CODE_bss_8007A0D8)($at)
  li    $t9, 40
  b     .L7F09B8F8
   sw    $t9, ($t1)
.L7F09B8C8:
  li    $v0, 500
  lui   $at, %hi(dword_CODE_bss_8007A0D0)
  lui   $t0, %hi(dword_CODE_bss_8007A0D4) 
  sw    $v0, %lo(dword_CODE_bss_8007A0D0)($at)
  addiu $t0, %lo(dword_CODE_bss_8007A0D4) # addiu $t0, $t0, -0x5f2c
  li    $v1, 20
  lui   $t1, %hi(dword_CODE_bss_8007A0DC) 
  sw    $v1, ($t0)
  lui   $at, %hi(dword_CODE_bss_8007A0D8)
  addiu $t1, %lo(dword_CODE_bss_8007A0DC) # addiu $t1, $t1, -0x5f24
  sw    $v0, %lo(dword_CODE_bss_8007A0D8)($at)
  sw    $v1, ($t1)
.L7F09B8F8:
  lw    $a0, ($t0)
  li    $a1, 4
  sll   $t3, $a0, 2
  addu  $t3, $t3, $a0
  jal   mempAllocBytesInBank
   sll   $a0, $t3, 2
  lui   $a2, %hi(dword_CODE_bss_8007A0E8)
  addiu $a2, %lo(dword_CODE_bss_8007A0E8) # addiu $a2, $a2, -0x5f18
  sw    $v0, ($a2)
  lui   $a0, %hi(dword_CODE_bss_8007A0D0)
  lw    $a0, %lo(dword_CODE_bss_8007A0D0)($a0)
  li    $a1, 4
  sll   $t4, $a0, 4
  jal   mempAllocBytesInBank
   move  $a0, $t4
  lui   $t1, %hi(dword_CODE_bss_8007A0DC) 
  lui   $at, %hi(dword_CODE_bss_8007A0E0)
  sw    $v0, %lo(dword_CODE_bss_8007A0E0)($at)
  addiu $t1, %lo(dword_CODE_bss_8007A0DC) # addiu $t1, $t1, -0x5f24
  lw    $a0, ($t1)
  li    $a1, 4
  sll   $t5, $a0, 2
  addu  $t5, $t5, $a0
  jal   mempAllocBytesInBank
   sll   $a0, $t5, 2
  lui   $a3, %hi(dword_CODE_bss_8007A0EC)
  addiu $a3, %lo(dword_CODE_bss_8007A0EC) # addiu $a3, $a3, -0x5f14
  sw    $v0, ($a3)
  lui   $a0, %hi(dword_CODE_bss_8007A0D8)
  lw    $a0, %lo(dword_CODE_bss_8007A0D8)($a0)
  li    $a1, 4
  sll   $t6, $a0, 4
  jal   mempAllocBytesInBank
   move  $a0, $t6
  lui   $t2, %hi(dword_CODE_bss_8007A0D0) 
  addiu $t2, %lo(dword_CODE_bss_8007A0D0) # addiu $t2, $t2, -0x5f30
  lw    $t7, ($t2)
  lui   $a1, %hi(dword_CODE_bss_8007A0E4)
  addiu $a1, %lo(dword_CODE_bss_8007A0E4) # addiu $a1, $a1, -0x5f1c
  sw    $v0, ($a1)
  lui   $a2, %hi(dword_CODE_bss_8007A0E8)
  lui   $at, %hi(word_CODE_bss_8007A0F0)
  addiu $a2, %lo(dword_CODE_bss_8007A0E8) # addiu $a2, $a2, -0x5f18
  lui   $t8, %hi(dword_CODE_bss_8007A0E0) 
  sh    $t7, %lo(word_CODE_bss_8007A0F0)($at)
  lw    $t9, ($a2)
  lw    $t8, %lo(dword_CODE_bss_8007A0E0)($t8)
  li    $a0, -1
  lui   $t0, %hi(dword_CODE_bss_8007A0D4) 
  sw    $t8, ($t9)
  lw    $t4, ($a2)
  lw    $t3, ($t2)
  addiu $t0, %lo(dword_CODE_bss_8007A0D4) # addiu $t0, $t0, -0x5f2c
  lui   $a3, %hi(dword_CODE_bss_8007A0EC)
  sh    $t3, 0xc($t4)
  lw    $t5, ($a2)
  lui   $t1, %hi(dword_CODE_bss_8007A0DC) 
  addiu $t1, %lo(dword_CODE_bss_8007A0DC) # addiu $t1, $t1, -0x5f24
  sh    $zero, 0xe($t5)
  lw    $t6, ($a2)
  addiu $a3, %lo(dword_CODE_bss_8007A0EC) # addiu $a3, $a3, -0x5f14
  li    $v0, 20
  sh    $a0, 0x10($t6)
  lw    $t7, ($a2)
  li    $v1, 1
  lui   $t5, %hi(dword_CODE_bss_8007A0D8) 
  sh    $a0, 0x12($t7)
  lw    $t8, ($t0)
  slti  $at, $t8, 2
  bnez  $at, .L7F09BA3C
   nop   
  lw    $t9, ($a2)
.L7F09BA18:
  addiu $v1, $v1, 1
  addu  $t3, $t9, $v0
  sh    $a0, 0xe($t3)
  lw    $t4, ($t0)
  addiu $v0, $v0, 0x14
  slt   $at, $v1, $t4
  bnezl $at, .L7F09BA18
   lw    $t9, ($a2)
  li    $v1, 1
.L7F09BA3C:
  lw    $t5, %lo(dword_CODE_bss_8007A0D8)($t5)
  lui   $at, %hi(word_CODE_bss_8007A0F2)
  lui   $t8, %hi(dword_CODE_bss_8007A0D8) 
  sh    $t5, %lo(word_CODE_bss_8007A0F2)($at)
  lw    $t7, ($a3)
  lw    $t6, ($a1)
  li    $v0, 20
  sw    $t6, ($t7)
  lw    $t9, ($a3)
  lw    $t8, %lo(dword_CODE_bss_8007A0D8)($t8)
  sh    $t8, 0xc($t9)
  lw    $t3, ($a3)
  sh    $zero, 0xe($t3)
  lw    $t4, ($a3)
  sh    $a0, 0x10($t4)
  lw    $t5, ($a3)
  sh    $a0, 0x12($t5)
  lw    $t6, ($t1)
  slti  $at, $t6, 2
  bnezl $at, .L7F09BAB8
   lw    $ra, 0x14($sp)
  lw    $t7, ($a3)
.L7F09BA94:
  addiu $v1, $v1, 1
  addu  $t8, $t7, $v0
  sh    $a0, 0xe($t8)
  lw    $t9, ($t1)
  addiu $v0, $v0, 0x14
  slt   $at, $v1, $t9
  bnezl $at, .L7F09BA94
   lw    $t7, ($a3)
  lw    $ra, 0x14($sp)
.L7F09BAB8:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F09BAC4
  addiu $sp, $sp, -0x30
  sw    $ra, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  move  $s3, $a0
  move  $s4, $a1
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  jal   get_ptr_obj_pos_list_current_entry
   sw    $s0, 0x18($sp)
  beqz  $v0, .L7F09BB9C
   move  $s1, $v0
  li    $s2, 1
  li    $s0, 24
  lbu   $t6, ($s1)
.L7F09BB00:
  bnel  $s2, $t6, .L7F09BB94
   lw    $s1, 0x24($s1)
  lw    $v0, 4($s1)
  lw    $a0, 0x14($v0)
  lw    $v1, 8($a0)
  lw    $a1, ($v1)
  beql  $a1, $zero, .L7F09BB94
   lw    $s1, 0x24($s1)
  lhu   $v0, ($a1)
.L7F09BB24:
  andi  $t7, $v0, 0xff
  bnel  $t7, $s0, .L7F09BB50
   lw    $v0, 0x14($a1)
  jal   extract_id_from_object_structure_microcode
   nop   
  lw    $t8, ($v0)
  bnel  $s3, $t8, .L7F09BB94
   lw    $s1, 0x24($s1)
  b     .L7F09BB90
   sw    $s4, ($v0)
  lw    $v0, 0x14($a1)
.L7F09BB50:
  beqz  $v0, .L7F09BB60
   nop   
  b     .L7F09BB88
   move  $a1, $v0
.L7F09BB60:
  beqz  $a1, .L7F09BB88
   nop   
  lw    $v0, 0xc($a1)
.L7F09BB6C:
  beql  $v0, $zero, .L7F09BB80
   lw    $a1, 8($a1)
  b     .L7F09BB88
   move  $a1, $v0
  lw    $a1, 8($a1)
.L7F09BB80:
  bnezl $a1, .L7F09BB6C
   lw    $v0, 0xc($a1)
.L7F09BB88:
  bnezl $a1, .L7F09BB24
   lhu   $v0, ($a1)
.L7F09BB90:
  lw    $s1, 0x24($s1)
.L7F09BB94:
  bnezl $s1, .L7F09BB00
   lbu   $t6, ($s1)
.L7F09BB9C:
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  lw    $s3, 0x24($sp)
  lw    $s4, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x30
");

asm(R"
glabel sub_GAME_7F09BBBC
  addiu $sp, $sp, -0x40
  sw    $s5, 0x2c($sp)
  lui   $s5, %hi(word_CODE_bss_8007A0F2)
  lui   $t7, %hi(dword_CODE_bss_8007A0D8) 
  lw    $t7, %lo(dword_CODE_bss_8007A0D8)($t7)
  addiu $s5, %lo(word_CODE_bss_8007A0F2) # addiu $s5, $s5, -0x5f0e
  lh    $t6, ($s5)
  sra   $t8, $t7, 2
  sw    $s6, 0x30($sp)
  slt   $at, $t6, $t8
  sw    $ra, 0x3c($sp)
  sw    $fp, 0x38($sp)
  sw    $s7, 0x34($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  beqz  $at, .L7F09BD34
   move  $s6, $zero
  lui   $a0, %hi(dword_CODE_bss_8007A0DC)
  lw    $a0, %lo(dword_CODE_bss_8007A0DC)($a0)
  move  $fp, $zero
  lui   $v1, %hi(dword_CODE_bss_8007A0EC)
  addiu $a1, $a0, -1
  blez  $a1, .L7F09BD34
   li    $s7, 20
  lui   $s4, %hi(dword_CODE_bss_8007A0EC)
  addiu $s4, %lo(dword_CODE_bss_8007A0EC) # addiu $s4, $s4, -0x5f14
  lw    $v1, %lo(dword_CODE_bss_8007A0EC)($v1)
.L7F09BC34:
  multu $fp, $s7
  addiu $v0, $fp, 1
  sll   $t2, $v0, 0x10
  sra   $t3, $t2, 0x10
  sll   $s2, $v0, 0x10
  sra   $t1, $s2, 0x10
  slt   $at, $t3, $a0
  mflo  $s3
  addu  $t9, $v1, $s3
  lh    $t0, 0xe($t9)
  blezl $t0, .L7F09BD20
   addiu $fp, $fp, 1
  beqz  $at, .L7F09BD1C
   move  $s2, $t1
.L7F09BC6C:
  multu $s2, $s7
  addu  $s0, $v1, $s3
  mflo  $s1
  addu  $v0, $v1, $s1
  lh    $t4, 0xe($v0)
  blezl $t4, .L7F09BD04
   addiu $s2, $s2, 1
  lw    $t5, 4($s0)
  lw    $t7, 4($v0)
  bnel  $t5, $t7, .L7F09BD04
   addiu $s2, $s2, 1
  lw    $t6, 8($s0)
  lw    $t8, 8($v0)
  bnel  $t6, $t8, .L7F09BD04
   addiu $s2, $s2, 1
  lw    $a0, ($v0)
  lw    $a1, ($s0)
  jal   sub_GAME_7F09BAC4
   li    $s6, 1
  lw    $v1, ($s4)
  lui   $a0, %hi(dword_CODE_bss_8007A0DC)
  addu  $s0, $v1, $s3
  addu  $t0, $v1, $s1
  lh    $t1, 0xe($t0)
  lh    $t9, 0xe($s0)
  addu  $t2, $t9, $t1
  sh    $t2, 0xe($s0)
  lw    $t3, ($s4)
  addu  $t4, $t3, $s1
  sh    $zero, 0xe($t4)
  lw    $v1, ($s4)
  lh    $t5, ($s5)
  addu  $t7, $v1, $s1
  lh    $t6, 0xc($t7)
  addu  $t8, $t5, $t6
  sh    $t8, ($s5)
  lw    $a0, %lo(dword_CODE_bss_8007A0DC)($a0)
  addiu $s2, $s2, 1
.L7F09BD04:
  sll   $t0, $s2, 0x10
  sra   $s2, $t0, 0x10
  slt   $at, $s2, $a0
  bnez  $at, .L7F09BC6C
   nop   
  addiu $a1, $a0, -1
.L7F09BD1C:
  addiu $fp, $fp, 1
.L7F09BD20:
  sll   $t1, $fp, 0x10
  sra   $fp, $t1, 0x10
  slt   $at, $fp, $a1
  bnez  $at, .L7F09BC34
   nop   
.L7F09BD34:
  lui   $s4, %hi(dword_CODE_bss_8007A0EC)
  addiu $s4, %lo(dword_CODE_bss_8007A0EC) # addiu $s4, $s4, -0x5f14
  beqz  $s6, .L7F09BDF8
   li    $s7, 20
  move  $a0, $zero
  move  $fp, $zero
  li    $a1, -1
.L7F09BD50:
  multu $fp, $s7
  lw    $v1, ($s4)
  mflo  $s3
  addu  $s0, $v1, $s3
  lh    $s2, 0x10($s0)
  bltzl $s2, .L7F09BDF0
   li    $a0, 1
  lh    $t3, 0xe($s0)
  bnezl $t3, .L7F09BDE0
   sll   $fp, $s2, 0x10
  multu $s2, $s7
  mflo  $s1
  addu  $v0, $v1, $s1
  lh    $t4, 0xe($v0)
  bnezl $t4, .L7F09BDE0
   sll   $fp, $s2, 0x10
  lh    $t7, 0xc($s0)
  lh    $t5, 0xc($v0)
  addu  $t6, $t7, $t5
  sh    $t6, 0xc($s0)
  lw    $t8, ($s4)
  addu  $t0, $t8, $s1
  sh    $a1, 0xe($t0)
  lw    $v1, ($s4)
  addu  $t9, $v1, $s1
  lh    $s2, 0x10($t9)
  addu  $t1, $v1, $s3
  bltz  $s2, .L7F09BDF0
   sh    $s2, 0x10($t1)
  multu $s2, $s7
  lw    $t2, ($s4)
  mflo  $t3
  addu  $t4, $t2, $t3
  b     .L7F09BDF0
   sh    $fp, 0x12($t4)
  sll   $fp, $s2, 0x10
.L7F09BDE0:
  sra   $t7, $fp, 0x10
  b     .L7F09BDF0
   move  $fp, $t7
  li    $a0, 1
.L7F09BDF0:
  beqz  $a0, .L7F09BD50
   nop   
.L7F09BDF8:
  lui   $t6, %hi(dword_CODE_bss_8007A0D8) 
  lw    $t6, %lo(dword_CODE_bss_8007A0D8)($t6)
  lh    $t5, ($s5)
  sra   $t8, $t6, 2
  slt   $at, $t5, $t8
  beql  $at, $zero, .L7F09BE20
   lw    $ra, 0x3c($sp)
  jal   sub_GAME_7F056690
   nop   
  lw    $ra, 0x3c($sp)
.L7F09BE20:
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
glabel sub_GAME_7F09BE4C
  addiu $sp, $sp, -0x20
  sw    $s0, 0x18($sp)
  li    $at, 2827
  move  $s0, $a0
  sw    $ra, 0x1c($sp)
  sw    $a2, 0x28($sp)
  beq   $a1, $at, .L7F09BE90
   sw    $a3, 0x2c($sp)
  li    $at, 52428
  bne   $a1, $at, .L7F09BEAC
   lui   $t0, %hi(dword_CODE_bss_8007A0E8) 
  lui   $t3, %hi(word_CODE_bss_8007A0F0) 
  lui   $a2, %hi(dword_CODE_bss_8007A0D4+2)
  lw    $t0, %lo(dword_CODE_bss_8007A0E8)($t0)
  addiu $t3, %lo(word_CODE_bss_8007A0F0) # addiu $t3, $t3, -0x5f10
  b     .L7F09BEB4
   lh    $a2, %lo(dword_CODE_bss_8007A0D4+2)($a2)
.L7F09BE90:
  lui   $t0, %hi(dword_CODE_bss_8007A0EC) 
  lui   $t3, %hi(word_CODE_bss_8007A0F2) 
  lui   $a2, %hi(dword_CODE_bss_8007A0DC+0x2)
  lw    $t0, %lo(dword_CODE_bss_8007A0EC)($t0)
  addiu $t3, %lo(word_CODE_bss_8007A0F2) # addiu $t3, $t3, -0x5f0e
  b     .L7F09BEB4
   lh    $a2, %lo(dword_CODE_bss_8007A0DC+0x2)($a2)
.L7F09BEAC:
  b     .L7F09C030
   move  $v0, $zero
.L7F09BEB4:
  move  $v1, $zero
  move  $v0, $zero
  move  $a1, $zero
  li    $t1, 20
  li    $a3, -1
.L7F09BEC8:
  multu $a1, $t1
  mflo  $t6
  addu  $a0, $t0, $t6
  lh    $t7, 0xe($a0)
  bnezl $t7, .L7F09BEFC
   lh    $a1, 0x10($a0)
  lh    $t8, 0xc($a0)
  slt   $at, $t8, $s0
  bnezl $at, .L7F09BEFC
   lh    $a1, 0x10($a0)
  b     .L7F09BF20
   li    $v1, 1
  lh    $a1, 0x10($a0)
.L7F09BEFC:
  addiu $v0, $v0, 1
  slt   $at, $a2, $v0
  beql  $a1, $a3, .L7F09BF18
   sll   $v1, $a3, 0x10
  beqz  $at, .L7F09BF20
   nop   
  sll   $v1, $a3, 0x10
.L7F09BF18:
  sra   $t9, $v1, 0x10
  move  $v1, $t9
.L7F09BF20:
  beqz  $v1, .L7F09BEC8
   nop   
  slt   $at, $a2, $v0
  beql  $at, $zero, .L7F09BF50
   li    $at, 1
  jal   sub_GAME_7F09B7A8
   nop   
  jal   sub_GAME_7F09B7E4
   nop   
  b     .L7F09C030
   move  $v0, $zero
  li    $at, 1
.L7F09BF50:
  bne   $v1, $at, .L7F09C030
   move  $v0, $zero
  multu $a1, $t1
  lw    $t6, 0x28($sp)
  move  $t4, $zero
  mflo  $t5
  addu  $a0, $t0, $t5
  lh    $t8, 0xe($a0)
  lh    $t2, 0xc($a0)
  sw    $t6, 4($a0)
  lw    $t7, 0x2c($sp)
  addiu $t9, $t8, 1
  sh    $t9, 0xe($a0)
  beq   $t2, $s0, .L7F09C004
   sw    $t7, 8($a0)
  blez  $a2, .L7F09C004
   move  $v1, $zero
  move  $v0, $t0
.L7F09BF98:
  lh    $t5, 0xe($v0)
  bnel  $a3, $t5, .L7F09BFFC
   addiu $v1, $v1, 1
  lw    $t6, ($a0)
  sh    $s0, 0xc($a0)
  sll   $t7, $s0, 4
  subu  $t9, $t2, $s0
  addu  $t8, $t6, $t7
  sw    $t8, ($v0)
  sh    $t9, 0xc($v0)
  sh    $zero, 0xe($v0)
  sh    $a1, 0x12($v0)
  lh    $t5, 0x10($a0)
  li    $t4, 1
  sh    $t5, 0x10($v0)
  lh    $v0, 0x10($a0)
  bltz  $v0, .L7F09BFF0
   nop   
  multu $v0, $t1
  mflo  $t6
  addu  $t7, $t0, $t6
  sh    $v1, 0x12($t7)
.L7F09BFF0:
  b     .L7F09C004
   sh    $v1, 0x10($a0)
  addiu $v1, $v1, 1
.L7F09BFFC:
  bne   $v1, $a2, .L7F09BF98
   addiu $v0, $v0, 0x14
.L7F09C004:
  beql  $t4, $zero, .L7F09C020
   lh    $t5, ($t3)
  lh    $t8, ($t3)
  subu  $t9, $t8, $s0
  b     .L7F09C028
   sh    $t9, ($t3)
  lh    $t5, ($t3)
.L7F09C020:
  subu  $t6, $t5, $t2
  sh    $t6, ($t3)
.L7F09C028:
  b     .L7F09C030
   lw    $v0, ($a0)
.L7F09C030:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F09C044
  lui   $v0, %hi(dword_CODE_bss_8007A0E0)
  lw    $v0, %lo(dword_CODE_bss_8007A0E0)($v0)
  addiu $sp, $sp, -0x20
  sw    $s0, 0x18($sp)
  sltu  $at, $a0, $v0
  move  $s0, $a0
  bnez  $at, .L7F09C094
   sw    $ra, 0x1c($sp)
  lui   $t6, %hi(dword_CODE_bss_8007A0D0) 
  lw    $t6, %lo(dword_CODE_bss_8007A0D0)($t6)
  lui   $t2, %hi(word_CODE_bss_8007A0F0) 
  lui   $a3, %hi(dword_CODE_bss_8007A0E8)
  addiu $t7, $t6, -1
  sll   $t8, $t7, 4
  addu  $t9, $t8, $v0
  sltu  $at, $t9, $a0
  bnez  $at, .L7F09C094
   addiu $t2, %lo(word_CODE_bss_8007A0F0) # addiu $t2, $t2, -0x5f10
  b     .L7F09C0F0
   lw    $a3, %lo(dword_CODE_bss_8007A0E8)($a3)
.L7F09C094:
  lui   $v0, %hi(dword_CODE_bss_8007A0E4)
  lw    $v0, %lo(dword_CODE_bss_8007A0E4)($v0)
  lui   $t3, %hi(dword_CODE_bss_8007A0D8) 
  sltu  $at, $s0, $v0
  bnez  $at, .L7F09C0D8
   nop   
  lw    $t3, %lo(dword_CODE_bss_8007A0D8)($t3)
  lui   $t2, %hi(word_CODE_bss_8007A0F2) 
  lui   $a3, %hi(dword_CODE_bss_8007A0EC)
  addiu $t4, $t3, -1
  sll   $t5, $t4, 4
  addu  $t6, $t5, $v0
  sltu  $at, $t6, $s0
  bnez  $at, .L7F09C0D8
   addiu $t2, %lo(word_CODE_bss_8007A0F2) # addiu $t2, $t2, -0x5f0e
  b     .L7F09C0F0
   lw    $a3, %lo(dword_CODE_bss_8007A0EC)($a3)
.L7F09C0D8:
  jal   sub_GAME_7F09B7A8
   nop   
  jal   sub_GAME_7F09B7E4
   nop   
  b     .L7F09C238
   lw    $ra, 0x1c($sp)
.L7F09C0F0:
  move  $a1, $zero
  move  $t0, $zero
  li    $t1, -1
  li    $a2, 20
.L7F09C100:
  multu $a1, $a2
  mflo  $t7
  addu  $a0, $a3, $t7
  lw    $t8, ($a0)
  bnel  $s0, $t8, .L7F09C220
   lh    $a1, 0x10($a0)
  lh    $v0, 0xe($a0)
  li    $t0, 1
  addiu $t9, $v0, -1
  sh    $t9, 0xe($a0)
  lh    $t3, 0xe($a0)
  bnez  $t3, .L7F09C22C
   nop   
  lh    $t4, ($t2)
  lh    $t5, 0xc($a0)
  addu  $t6, $t4, $t5
  sh    $t6, ($t2)
  lh    $v1, 0x10($a0)
  bltzl $v1, .L7F09C1A4
   lh    $v1, 0x12($a0)
  multu $v1, $a2
  mflo  $t7
  addu  $v0, $a3, $t7
  lh    $t8, 0xe($v0)
  bnezl $t8, .L7F09C1A4
   lh    $v1, 0x12($a0)
  lh    $t9, 0xc($a0)
  lh    $t3, 0xc($v0)
  addu  $t4, $t9, $t3
  sh    $t4, 0xc($a0)
  lh    $t5, 0x10($v0)
  sh    $t5, 0x10($a0)
  sh    $t1, 0xe($v0)
  lh    $v1, 0x10($a0)
  bltzl $v1, .L7F09C1A4
   lh    $v1, 0x12($a0)
  multu $v1, $a2
  mflo  $t6
  addu  $t7, $a3, $t6
  sh    $a1, 0x12($t7)
  lh    $v1, 0x12($a0)
.L7F09C1A4:
  bltz  $v1, .L7F09C22C
   nop   
  multu $v1, $a2
  mflo  $t8
  addu  $v0, $a3, $t8
  lh    $t9, 0xe($v0)
  sll   $t8, $v1, 0x10
  bnez  $t9, .L7F09C22C
   sra   $t9, $t8, 0x10
  multu $t9, $a2
  lh    $t3, 0xc($v0)
  lh    $t4, 0xc($a0)
  sll   $a1, $v1, 0x10
  sra   $t7, $a1, 0x10
  addu  $t5, $t3, $t4
  sh    $t5, 0xc($v0)
  lh    $t6, 0x10($a0)
  move  $a1, $t7
  mflo  $t3
  sh    $t6, 0x10($v0)
  sh    $t1, 0xe($a0)
  addu  $t4, $a3, $t3
  lh    $v1, 0x10($t4)
  bltz  $v1, .L7F09C22C
   nop   
  multu $v1, $a2
  mflo  $t5
  addu  $t6, $a3, $t5
  b     .L7F09C22C
   sh    $t7, 0x12($t6)
  lh    $a1, 0x10($a0)
.L7F09C220:
  bne   $a1, $t1, .L7F09C22C
   nop   
  li    $t0, 1
.L7F09C22C:
  beqz  $t0, .L7F09C100
   nop   
  lw    $ra, 0x1c($sp)
.L7F09C238:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");
