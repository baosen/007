int clippingfile;
int ptr_firstroom;
int dword_CODE_bss_8007B128;
int dword_CODE_bss_8007B12C;
int dword_CODE_bss_8007B130;
char dword_CODE_bss_8007B134;
char dword_CODE_bss_8007B135;
char dword_CODE_bss_8007B136;
char dword_CODE_bss_8007B137;
char dword_CODE_bss_8007B138[0x21C];
int dword_CODE_bss_8007B354;
int dword_CODE_bss_8007B358[0x1a1];
int dword_CODE_bss_8007B9DC;
int dword_CODE_bss_8007B9E0;
int dword_CODE_bss_8007B9E4;
int dword_CODE_bss_8007B9E8;
int dword_CODE_bss_8007B9EC;
float flt_CODE_bss_8007B9F0;
float flt_CODE_bss_8007B9F4;
float flt_CODE_bss_8007B9F8;
float flt_CODE_bss_8007B9FC;
float flt_CODE_bss_8007BA00;
int dword_CODE_bss_8007BA04;
int dword_CODE_bss_8007BA08;
int dword_CODE_bss_8007BA0C;
char dword_CODE_bss_8007BA10[0x580];

int D_80040F30[] = {0x8D8604C5, 0x9DA40000, 0, 0};
int stan_c_debug_notice_list_entry = 0;
float D_80040F44 = 1.0;
float D_80040F48 = 1.0;
unsigned char list_of_tilesizes[] = {0x20, 0x20, 0x20, 0x20, 0x28, 0x30,
                                     0x38, 0x40, 0x48, 0x50, 0x58, 0x00};
int base_ptr_connection_vals = 0;
int ptr_firstroom_0 = 0;
int D_80040F60 = 0;
int D_80040F64[18] = {0};
int D_80040FAC = 0;
int stanLoaded = 0;
int stanlinelog_flag[258] = {0};
int D_800413BC = 0;
float D_800413C0 = 0.0;
float D_800413C4 = 0.0;
int D_800413C8 = 1;
int D_800413CC = 1;
int D_800413D0[8] = {0};

const char aCDCC[] = "%c%d%c%c";
const char aStan_c_debug[] = "stan_c_debug";
const char aStanlinelog[] = "-stanlinelog";

int float2int(const float value) { return *(int *)(float *)&value; }

asm(R"
glabel sub_GAME_7F0AEF3C
  lui   $a2, %hi(D_80040FAC)
  lw    $a2, %lo(D_80040FAC)($a2)
  lui   $t7, %hi(D_80040F64) 
  addiu $sp, $sp, -0x28
  sll   $t6, $a2, 3
  addiu $t7, %lo(D_80040F64) # addiu $t7, $t7, 0xf64
  addu  $t6, $t6, $a2
  addu  $t8, $t6, $t7
  sw    $ra, 0x1c($sp)
  sw    $t8, 0x24($sp)
  lhu   $v0, ($a0)
  lbu   $v1, 2($a0)
  addiu $a2, $a2, 1
  sra   $t0, $v0, 0xf
  sra   $t1, $v1, 3
  andi  $t9, $a2, 7
  andi  $t2, $t0, 1
  andi  $t3, $t1, 0x1f
  lui   $at, %hi(D_80040FAC)
  andi  $a1, $v1, 7
  move  $t0, $t2
  move  $t1, $t3
  sw    $t9, %lo(D_80040FAC)($at)
  bnez  $a1, .L7F0AEFA8
   andi  $a3, $v0, 0x7fff
  b     .L7F0AEFAC
   move  $v0, $zero
.L7F0AEFA8:
  addiu $v0, $a1, 0x30
.L7F0AEFAC:
  lui   $a1, %hi(aCDCC)
  addiu $t4, $t1, 0x61
  sw    $t4, 0x10($sp)
  addiu $a1, %lo(aCDCC) # addiu $a1, $a1, -0x7a60
  lw    $a0, 0x24($sp)
  addiu $a2, $t0, 0x70
  jal   sprintf
   sw    $v0, 0x14($sp)
  lw    $ra, 0x1c($sp)
  lw    $v0, 0x24($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

void sub_GAME_7F0AEFE0(void) { sub_GAME_7F0AEF3C(); }

unsigned int stanRemovedAnimationRoutine(int arg0) { return 0; }

void something_stan_c_debug_related(void) {
  get_ptr_debug_notice_list_entry(&stan_c_debug_notice_list_entry,
                                  &aStan_c_debug);
}

asm(R"
glabel sub_GAME_7F0AF038
  addiu $sp, $sp, -0x20
  lui   $a3, %hi(dword_CODE_bss_8007B9DC)
  addiu $a3, %lo(dword_CODE_bss_8007B9DC) # addiu $a3, $a3, -0x4624
  sw    $zero, ($a3)
  lui   $at, %hi(dword_CODE_bss_8007B12C)
  sw    $zero, %lo(dword_CODE_bss_8007B128)($at)
  sw    $zero, %lo(dword_CODE_bss_8007B12C)($at)
  lui   $at, %hi(dword_CODE_bss_8007B130)
  lui   $v1, %hi(dword_CODE_bss_8007B134)
  lui   $v0, %hi(dword_CODE_bss_8007B354)
  sw    $s5, 0x1c($sp)
  sw    $s4, 0x18($sp)
  sw    $s3, 0x14($sp)
  sw    $s2, 0x10($sp)
  sw    $s1, 0xc($sp)
  sw    $s0, 8($sp)
  li    $a2, 255
  addiu $v0, %lo(dword_CODE_bss_8007B354) # addiu $v0, $v0, -0x4cac
  addiu $v1, %lo(dword_CODE_bss_8007B134) # addiu $v1, $v1, -0x4ecc
  sw    $zero, %lo(dword_CODE_bss_8007B130)($at)
.L7F0AF088:
  addiu $v1, $v1, 0x10
  sw    $zero, -0x10($v1)
  sw    $zero, -0xc($v1)
  sw    $zero, -8($v1)
  bne   $v1, $v0, .L7F0AF088
   sw    $zero, -4($v1)
  lui   $t6, %hi(clippingfile) 
  lw    $t6, %lo(clippingfile)($t6)
  lui   $t5, %hi(list_of_tilesizes) 
  addiu $t5, %lo(list_of_tilesizes) # addiu $t5, $t5, 0xf4c
  lw    $a0, 4($t6)
  move  $a1, $a2
  li    $t4, -32768
  lw    $t7, ($a0)
  li    $t3, 32767
  li    $t2, 12
  beqz  $t7, .L7F0AF1EC
   lui   $t1, %hi(dword_CODE_bss_8007B358) 
  lui   $t0, %hi(dword_CODE_bss_8007B128) 
  addiu $t0, %lo(dword_CODE_bss_8007B128) # addiu $t0, $t0, -0x4ed8
  addiu $t1, %lo(dword_CODE_bss_8007B358) # addiu $t1, $t1, -0x4ca8
  li    $v0, 6
  lbu   $s0, 3($a0)
.L7F0AF0E4:
  move  $v1, $zero
  beql  $a1, $s0, .L7F0AF148
   lh    $s0, 6($a0)
  lw    $t8, ($a3)
  andi  $a2, $s0, 0xff
  move  $a1, $a2
  slt   $at, $a2, $t8
  bnez  $at, .L7F0AF10C
   addiu $t9, $a1, 1
  sw    $t9, ($a3)
.L7F0AF10C:
  multu $a2, $t2
  sll   $t6, $a2, 2
  addu  $t7, $t0, $t6
  sw    $a0, ($t7)
  mflo  $t8
  addu  $s0, $t1, $t8
  sh    $t3, 4($s0)
  lh    $s1, 4($s0)
  sh    $t4, 0xa($s0)
  sh    $s1, 2($s0)
  sh    $s1, ($s0)
  lh    $s1, 0xa($s0)
  sh    $s1, 8($s0)
  sh    $s1, 6($s0)
  lh    $s0, 6($a0)
.L7F0AF148:
  sll   $t7, $a2, 2
  subu  $t7, $t7, $a2
  sra   $t9, $s0, 0xc
  andi  $s0, $t9, 0xf
  blez  $s0, .L7F0AF1D4
   move  $s1, $a0
  sll   $t7, $t7, 2
  addu  $s4, $t1, $t7
  move  $s2, $zero
.L7F0AF16C:
  move  $s3, $s1
  move  $s5, $s4
.L7F0AF174:
  lh    $s0, 8($s3)
  lh    $t8, ($s5)
  addiu $s2, $s2, 2
  slt   $at, $s0, $t8
  beql  $at, $zero, .L7F0AF198
   lh    $t9, 6($s5)
  sh    $s0, ($s5)
  lh    $s0, 8($s3)
  lh    $t9, 6($s5)
.L7F0AF198:
  addiu $s3, $s3, 2
  slt   $at, $t9, $s0
  beqz  $at, .L7F0AF1AC
   nop   
  sh    $s0, 6($s5)
.L7F0AF1AC:
  bne   $s2, $v0, .L7F0AF174
   addiu $s5, $s5, 2
  lh    $s0, 6($a0)
  addiu $v1, $v1, 1
  addiu $s1, $s1, 8
  sra   $t6, $s0, 0xc
  andi  $s0, $t6, 0xf
  slt   $at, $v1, $s0
  bnezl $at, .L7F0AF16C
   move  $s2, $zero
.L7F0AF1D4:
  addu  $t8, $t5, $s0
  lbu   $t9, ($t8)
  addu  $a0, $t9, $a0
  lw    $t6, ($a0)
  bnezl $t6, .L7F0AF0E4
   lbu   $s0, 3($a0)
.L7F0AF1EC:
  lw    $s0, 8($sp)
  lw    $s1, 0xc($sp)
  lw    $s2, 0x10($sp)
  lw    $s3, 0x14($sp)
  lw    $s4, 0x18($sp)
  lw    $s5, 0x1c($sp)
  jr    $ra
   addiu $sp, $sp, 0x20
");

asm(R"
.late_rodata
glabel D_800585CC
.word 0x46fffe00 /*32767.0*/
glabel D_800585D0
.word 0xff7fffff /*-3.4028235e38*/
glabel D_800585D4
.word 0xc6fffe00 /*-32767.0*/
.text
glabel sub_GAME_7F0AF20C
  addiu $sp, $sp, -0xc8
  lui   $at, %hi(D_800585CC)
  lwc1  $f2, %lo(D_800585CC)($at)
  sdc1  $f24, 0x30($sp)
  lui   $at, %hi(D_800585D0)
  lwc1  $f24, %lo(D_800585D0)($at)
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
  sdc1  $f22, 0x28($sp)
  sdc1  $f20, 0x20($sp)
  sw    $a1, 0xcc($sp)
  sw    $a2, 0xd0($sp)
  sw    $zero, 0x9c($sp)
  lui   $at, %hi(D_80040F44)
  lwc1  $f0, %lo(D_80040F44)($at)
  lwc1  $f4, ($a0)
  move  $s4, $a0
  lui   $s7, %hi(list_of_tilesizes) 
  mul.s $f6, $f4, $f0
  lui   $t2, %hi(dword_CODE_bss_8007B128) 
  lui   $at, %hi(D_800585D4)
  addiu $t2, %lo(dword_CODE_bss_8007B128) # addiu $t2, $t2, -0x4ed8
  addiu $s7, %lo(list_of_tilesizes) # addiu $s7, $s7, 0xf4c
  li    $s3, 3
  li    $s6, 255
  swc1  $f6, 0xb8($sp)
  lwc1  $f8, 4($a0)
  addiu $fp, $sp, 0x7c
  mul.s $f10, $f8, $f0
  swc1  $f10, 0xbc($sp)
  lwc1  $f16, 8($a0)
  lwc1  $f4, 0xbc($sp)
  li    $a0, 4
  mul.s $f18, $f16, $f0
  c.lt.s $f2, $f4
  nop   
  bc1f  .L7F0AF2C8
   swc1  $f18, 0xc0($sp)
  swc1  $f2, 0xbc($sp)
.L7F0AF2C8:
  lwc1  $f0, %lo(D_800585D4)($at)
  lwc1  $f12, 0xbc($sp)
  lwc1  $f2, 0xc0($sp)
  li    $at, 0x40000000 # 2.000000
  c.lt.s $f12, $f0
  move  $s5, $zero
  lui   $a2, %hi(dword_CODE_bss_8007B9DC)
  trunc.w.s $f10, $f2
  bc1fl .L7F0AF2F8
   lwc1  $f0, 0xb8($sp)
  mov.s $f12, $f0
  lwc1  $f0, 0xb8($sp)
.L7F0AF2F8:
  trunc.w.s $f8, $f12
  lw    $a2, %lo(dword_CODE_bss_8007B9DC)($a2)
  mfc1  $t1, $f10
  trunc.w.s $f6, $f0
  mfc1  $t9, $f8
  swc1  $f12, 0xbc($sp)
  sh    $t1, 0xb0($sp)
  mfc1  $t7, $f6
  sh    $t9, 0xae($sp)
  blez  $a2, .L7F0AF55C
   sh    $t7, 0xac($sp)
  mtc1  $at, $f22
  li    $at, 0xC0000000 # -2.000000
  mtc1  $at, $f20
  sw    $t2, 0x70($sp)
  lw    $s2, 0x88($sp)
.L7F0AF338:
  lw    $t3, 0x70($sp)
  sll   $t4, $s5, 2
  subu  $t4, $t4, $s5
  lw    $a1, ($t3)
  lui   $t5, %hi(dword_CODE_bss_8007B358) 
  addiu $t5, %lo(dword_CODE_bss_8007B358) # addiu $t5, $t5, -0x4ca8
  beqz  $a1, .L7F0AF540
   sll   $t4, $t4, 2
  addu  $v0, $t4, $t5
  lh    $t7, ($v0)
  lh    $t6, 0xac($sp)
  lh    $t9, 0xac($sp)
  slt   $at, $t6, $t7
  bnezl $at, .L7F0AF544
   lw    $t6, 0x70($sp)
  lh    $t8, 6($v0)
  lh    $t0, 0xb0($sp)
  slt   $at, $t8, $t9
  bnezl $at, .L7F0AF544
   lw    $t6, 0x70($sp)
  lh    $t1, 4($v0)
  lh    $t3, 0xb0($sp)
  slt   $at, $t0, $t1
  bnezl $at, .L7F0AF544
   lw    $t6, 0x70($sp)
  lh    $t2, 0xa($v0)
  lh    $t4, 0xae($sp)
  slt   $at, $t2, $t3
  bnezl $at, .L7F0AF544
   lw    $t6, 0x70($sp)
  lh    $t5, 2($v0)
  lw    $t6, 0xcc($sp)
  slt   $at, $t4, $t5
  bnezl $at, .L7F0AF544
   lw    $t6, 0x70($sp)
  beql  $t6, $zero, .L7F0AF41C
   lw    $t8, ($a1)
  lbu   $t7, ($t6)
  move  $s0, $zero
  addu  $v0, $t6, $zero
  beq   $s6, $t7, .L7F0AF410
   nop   
  lbu   $v1, ($t6)
.L7F0AF3E4:
  bnel  $s5, $v1, .L7F0AF3F8
   lbu   $v1, 1($v0)
  b     .L7F0AF41C
   lw    $t8, ($a1)
  lbu   $v1, 1($v0)
.L7F0AF3F8:
  addiu $s0, $s0, 1
  addiu $v0, $v0, 1
  beq   $s6, $v1, .L7F0AF410
   nop   
  bne   $s0, $a0, .L7F0AF3E4
   nop   
.L7F0AF410:
  b     .L7F0AF544
   lw    $t6, 0x70($sp)
  lw    $t8, ($a1)
.L7F0AF41C:
  move  $s1, $a1
  beqz  $t8, .L7F0AF534
   nop   
  lbu   $t9, 3($a1)
  bne   $s5, $t9, .L7F0AF534
   move  $s0, $zero
.L7F0AF434:
  lwc1  $f0, 0xb8($sp)
.L7F0AF438:
  lwc1  $f2, 0xc0($sp)
  move  $a0, $s1
  mfc1  $a2, $f0
  mfc1  $a3, $f2
  jal   sub_GAME_7F0AFE70
   move  $a1, $s0
  c.lt.s $f0, $f20
  addiu $s0, $s0, 1
  bc1tl .L7F0AF508
   lh    $v0, 6($s1)
  c.lt.s $f0, $f22
  nop   
  bc1f  .L7F0AF474
   nop   
  li    $s2, 1
.L7F0AF474:
  bnel  $s0, $s3, .L7F0AF438
   lwc1  $f0, 0xb8($sp)
  jal   sub_GAME_7F0AF760
   move  $a0, $s1
  bnezl $v0, .L7F0AF508
   lh    $v0, 6($s1)
  beqz  $s2, .L7F0AF4C8
   move  $a0, $s1
  jal   sub_GAME_7F0AF924
   move  $a1, $fp
  sw    $s1, 0xa0($sp)
  lwc1  $f16, 8($s4)
  lw    $a3, ($s4)
  addiu $a0, $sp, 0xa0
  lw    $a1, 0x7c($sp)
  lw    $a2, 0x84($sp)
  jal   sub_GAME_7F0B0BE4
   swc1  $f16, 0x10($sp)
  beqz  $v0, .L7F0AF504
   lw    $t0, 0xa0($sp)
  bne   $t0, $s1, .L7F0AF504
.L7F0AF4C8:
   move  $a0, $s1
  lw    $a1, ($s4)
  jal   sub_GAME_7F0B2970
   lw    $a2, 8($s4)
  lwc1  $f18, 4($s4)
  c.lt.s $f18, $f0
  nop   
  bc1tl .L7F0AF508
   lh    $v0, 6($s1)
  c.lt.s $f24, $f0
  nop   
  bc1fl .L7F0AF508
   lh    $v0, 6($s1)
  sw    $s1, 0x9c($sp)
  mov.s $f24, $f0
.L7F0AF504:
  lh    $v0, 6($s1)
.L7F0AF508:
  sra   $t1, $v0, 0xc
  andi  $t2, $t1, 0xf
  addu  $t3, $s7, $t2
  lbu   $t4, ($t3)
  addu  $s1, $t4, $s1
  lw    $t5, ($s1)
  beqz  $t5, .L7F0AF534
   nop   
  lbu   $t7, 3($s1)
  beql  $s5, $t7, .L7F0AF434
   move  $s0, $zero
.L7F0AF534:
  lui   $a2, %hi(dword_CODE_bss_8007B9DC)
  lw    $a2, %lo(dword_CODE_bss_8007B9DC)($a2)
  li    $a0, 4
.L7F0AF540:
  lw    $t6, 0x70($sp)
.L7F0AF544:
  addiu $s5, $s5, 1
  slt   $at, $s5, $a2
  addiu $t8, $t6, 4
  bnez  $at, .L7F0AF338
   sw    $t8, 0x70($sp)
  sw    $s2, 0x88($sp)
.L7F0AF55C:
  lw    $t9, 0x9c($sp)
  lw    $t0, 0xd0($sp)
  beql  $t9, $zero, .L7F0AF57C
   lw    $ra, 0x5c($sp)
  beql  $t0, $zero, .L7F0AF57C
   lw    $ra, 0x5c($sp)
  swc1  $f24, ($t0)
  lw    $ra, 0x5c($sp)
.L7F0AF57C:
  lw    $v0, 0x9c($sp)
  ldc1  $f20, 0x20($sp)
  ldc1  $f22, 0x28($sp)
  ldc1  $f24, 0x30($sp)
  lw    $s0, 0x38($sp)
  lw    $s1, 0x3c($sp)
  lw    $s2, 0x40($sp)
  lw    $s3, 0x44($sp)
  lw    $s4, 0x48($sp)
  lw    $s5, 0x4c($sp)
  lw    $s6, 0x50($sp)
  lw    $s7, 0x54($sp)
  lw    $fp, 0x58($sp)
  jr    $ra
   addiu $sp, $sp, 0xc8
");

asm(R"
glabel stanLoadFile
  lui   $v0, %hi(clippingfile)
  li    $t6, 1
  lui   $at, %hi(stanLoaded)
  addiu $v0, %lo(clippingfile) # addiu $v0, $v0, -0x4ee0
  addiu $sp, $sp, -0x18
  sw    $t6, %lo(stanLoaded)($at)
  sw    $ra, 0x14($sp)
  sw    $a0, ($v0)
  lw    $t8, 4($a0)
  lui   $at, %hi(base_ptr_connection_vals)
  lui   $a1, %hi(aStanlinelog)
  addiu $t9, $t8, -0x80
  sw    $t9, %lo(base_ptr_connection_vals)($at)
  addiu $a1, %lo(aStanlinelog) # addiu $a1, $a1, -0x7a44
  jal   check_token
   li    $a0, 1
  beqz  $v0, .L7F0AF608
   li    $t0, 1
  lui   $at, %hi(stanlinelog_flag)
  sw    $t0, %lo(stanlinelog_flag)($at)
.L7F0AF608:
  jal   sub_GAME_7F0AF038
   nop   
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f12
  jal   sub_GAME_7F0B2950
   nop   
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

void sub_GAME_7F0AF630(int arg0) {}

asm(R"
glabel sub_GAME_7F0AF638
  addiu $sp, $sp, -0x38
  sw    $s7, 0x30($sp)
  sw    $s6, 0x2c($sp)
  sw    $s4, 0x24($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $ra, 0x34($sp)
  sw    $s5, 0x28($sp)
  sw    $s3, 0x20($sp)
  sw    $s0, 0x14($sp)
  sw    $a1, 0x3c($sp)
  lui   $s6, %hi(base_ptr_connection_vals)
  andi  $s4, $a1, 0xff
  move  $s7, $zero
  sw    $a0, ($a2)
  li    $s1, 1
  addiu $s6, %lo(base_ptr_connection_vals) # addiu $s6, $s6, 0xf58
  addiu $s2, $a2, 4
  lw    $s3, -4($s2)
.L7F0AF684:
  addiu $s1, $s1, -1
  addiu $s2, $s2, -4
  lhu   $v0, ($s3)
  move  $s0, $zero
  move  $a0, $s3
  sra   $t7, $v0, 0xf
  andi  $t8, $t7, 1
  beq   $s4, $t8, .L7F0AF728
   xori  $t9, $v0, 0x8000
  jal   sub_GAME_7F0AF760
   sh    $t9, ($s3)
  bnez  $v0, .L7F0AF6BC
   move  $a0, $s3
  addiu $s7, $s7, 1
.L7F0AF6BC:
  lh    $a1, 6($s3)
  sra   $t0, $a1, 0xc
  andi  $a1, $t0, 0xf
  blez  $a1, .L7F0AF728
   nop   
.L7F0AF6D0:
  lhu   $v0, 0xe($a0)
  addiu $s0, $s0, 1
  sra   $t2, $v0, 4
  beql  $t2, $zero, .L7F0AF720
   slt   $at, $s0, $a1
  lw    $t4, ($s6)
  sll   $t3, $v0, 3
  addu  $v1, $t3, $t4
  lhu   $t5, ($v1)
  sra   $t6, $t5, 0xf
  andi  $t7, $t6, 1
  beql  $s4, $t7, .L7F0AF720
   slt   $at, $s0, $a1
  sw    $v1, ($s2)
  lh    $a1, 6($s3)
  addiu $s1, $s1, 1
  addiu $s2, $s2, 4
  sra   $t8, $a1, 0xc
  andi  $a1, $t8, 0xf
  slt   $at, $s0, $a1
.L7F0AF720:
  bnez  $at, .L7F0AF6D0
   addiu $a0, $a0, 8
.L7F0AF728:
  bnezl $s1, .L7F0AF684
   lw    $s3, -4($s2)
  lw    $ra, 0x34($sp)
  move  $v0, $s7
  lw    $s7, 0x30($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  lw    $s4, 0x24($sp)
  lw    $s5, 0x28($sp)
  lw    $s6, 0x2c($sp)
  jr    $ra
   addiu $sp, $sp, 0x38
");

asm(R"
glabel sub_GAME_7F0AF760
  lh    $a1, 6($a0)
  addiu $sp, $sp, -0x20
  sra   $v1, $a1, 8
  sra   $a2, $a1, 4
  andi  $t6, $v1, 0xf
  andi  $t7, $a2, 0xf
  sll   $t8, $t7, 3
  sll   $t9, $t6, 3
  addu  $t1, $a0, $t9
  addu  $t0, $a0, $t8
  lh    $t3, 8($t0)
  lh    $t4, 8($t1)
  andi  $a3, $a1, 0xf
  sll   $t9, $a3, 3
  subu  $t5, $t3, $t4
  sw    $t5, 0x14($sp)
  lh    $t7, 0xc($t1)
  lh    $t6, 0xc($t0)
  addu  $t2, $a0, $t9
  subu  $t8, $t6, $t7
  sw    $t8, 0x1c($sp)
  lh    $t4, 8($t1)
  lh    $t3, 8($t2)
  lw    $t9, 0x1c($sp)
  subu  $t5, $t3, $t4
  multu $t9, $t5
  sw    $t5, 8($sp)
  lh    $t7, 0xc($t1)
  lh    $t6, 0xc($t2)
  subu  $t8, $t6, $t7
  lw    $t6, 0x14($sp)
  sw    $t8, 0x10($sp)
  mflo  $t4
  nop   
  nop   
  multu $t8, $t6
  mflo  $t7
  subu  $t8, $t4, $t7
  sw    $t8, ($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   sltiu $v0, $t8, 1
");

asm(R"
glabel sub_GAME_7F0AF808
  addiu $sp, $sp, -0x58
  lui   $t6, %hi(clippingfile) 
  lw    $t6, %lo(clippingfile)($t6)
  sw    $ra, 0x44($sp)
  sw    $s2, 0x40($sp)
  sw    $s1, 0x3c($sp)
  sw    $s0, 0x38($sp)
  sdc1  $f26, 0x30($sp)
  sdc1  $f24, 0x28($sp)
  sdc1  $f22, 0x20($sp)
  sdc1  $f20, 0x18($sp)
  lw    $s0, 4($t6)
  mtc1  $a2, $f22
  mtc1  $a3, $f24
  lw    $t7, ($s0)
  mov.s $f20, $f12
  mov.s $f26, $f14
  beqz  $t7, .L7F0AF8F8
   lui   $s2, %hi(list_of_tilesizes)
  addiu $s2, %lo(list_of_tilesizes) # addiu $s2, $s2, 0xf4c
  addiu $s1, $sp, 0x50
  sw    $s0, 0x50($sp)
.L7F0AF860:
  jal   sub_GAME_7F0AF760
   move  $a0, $s0
  bnezl $v0, .L7F0AF8D8
   lh    $v0, 6($s0)
  mfc1  $a1, $f20
  mfc1  $a2, $f22
  jal   sub_GAME_7F0B036C
   move  $a0, $s0
  beql  $v0, $zero, .L7F0AF8D8
   lh    $v0, 6($s0)
  mfc1  $a1, $f20
  mfc1  $a2, $f22
  mfc1  $a3, $f24
  jal   sub_GAME_7F0B20D0
   move  $a0, $s1
  beqz  $v0, .L7F0AF8D4
   lw    $t8, 0x50($sp)
  bnel  $s0, $t8, .L7F0AF8D8
   lh    $v0, 6($s0)
  mfc1  $a1, $f20
  mfc1  $a2, $f22
  jal   sub_GAME_7F0B2970
   move  $a0, $s0
  c.lt.s $f0, $f26
  nop   
  bc1fl .L7F0AF8D8
   lh    $v0, 6($s0)
  b     .L7F0AF8FC
   move  $v0, $s0
.L7F0AF8D4:
  lh    $v0, 6($s0)
.L7F0AF8D8:
  sra   $t9, $v0, 0xc
  andi  $t0, $t9, 0xf
  addu  $t1, $s2, $t0
  lbu   $t2, ($t1)
  addu  $s0, $t2, $s0
  lw    $t3, ($s0)
  bnezl $t3, .L7F0AF860
   sw    $s0, 0x50($sp)
.L7F0AF8F8:
  move  $v0, $zero
.L7F0AF8FC:
  lw    $ra, 0x44($sp)
  ldc1  $f20, 0x18($sp)
  ldc1  $f22, 0x20($sp)
  ldc1  $f24, 0x28($sp)
  ldc1  $f26, 0x30($sp)
  lw    $s0, 0x38($sp)
  lw    $s1, 0x3c($sp)
  lw    $s2, 0x40($sp)
  jr    $ra
   addiu $sp, $sp, 0x58
");

asm(R"
glabel sub_GAME_7F0AF924
  lh    $a3, 6($a0)
  li    $at, 0x40400000 # 3.000000
  mtc1  $at, $f0
  sra   $t6, $a3, 8
  andi  $t7, $t6, 0xf
  sra   $t8, $a3, 4
  andi  $t9, $t8, 0xf
  sll   $t6, $t7, 3
  sll   $t7, $t9, 3
  addu  $t2, $a0, $t7
  addu  $t1, $a0, $t6
  lh    $t8, 8($t1)
  lh    $t9, 8($t2)
  andi  $t4, $a3, 0xf
  sll   $t5, $t4, 3
  mtc1  $t8, $f4
  mtc1  $t9, $f8
  addu  $t0, $a0, $t5
  lh    $t4, 8($t0)
  cvt.s.w $f6, $f4
  lui   $t3, %hi(D_80040F48) 
  mtc1  $t4, $f18
  addiu $t3, %lo(D_80040F48) # addiu $t3, $t3, 0xf48
  cvt.s.w $f10, $f8
  cvt.s.w $f4, $f18
  add.s $f16, $f6, $f10
  lwc1  $f10, ($t3)
  add.s $f8, $f4, $f16
  div.s $f6, $f8, $f0
  mul.s $f18, $f6, $f10
  swc1  $f18, ($a1)
  lh    $t6, 0xa($t2)
  lh    $t5, 0xa($t1)
  lh    $t7, 0xa($t0)
  mtc1  $t6, $f8
  mtc1  $t5, $f4
  mtc1  $t7, $f18
  cvt.s.w $f6, $f8
  cvt.s.w $f16, $f4
  cvt.s.w $f4, $f18
  add.s $f10, $f16, $f6
  lwc1  $f6, ($t3)
  add.s $f8, $f4, $f10
  div.s $f16, $f8, $f0
  mul.s $f18, $f16, $f6
  swc1  $f18, 4($a1)
  lh    $t9, 0xc($t2)
  lh    $t8, 0xc($t1)
  lh    $t4, 0xc($t0)
  mtc1  $t9, $f8
  mtc1  $t8, $f4
  mtc1  $t4, $f18
  cvt.s.w $f16, $f8
  cvt.s.w $f10, $f4
  cvt.s.w $f4, $f18
  add.s $f6, $f10, $f16
  lwc1  $f16, ($t3)
  add.s $f8, $f4, $f6
  div.s $f10, $f8, $f0
  mul.s $f18, $f10, $f16
  jr    $ra
   swc1  $f18, 8($a1)
");

asm(R"
.late_rodata
glabel D_800585D8
.word 0x3dcccccd /*0.1*/
glabel D_800585DC
.word 0x3f666666 /*0.89999998*/
.text
glabel sub_GAME_7F0AFA1C
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  lh    $t6, 6($a0)
  sll   $t7, $a1, 2
  li    $t8, 8
  subu  $t9, $t8, $t7
  srav  $a3, $t6, $t9
  andi  $t0, $a3, 0xf
  sll   $t1, $t0, 3
  addu  $v0, $a0, $t1
  lh    $t2, 8($v0)
  lui   $v1, %hi(D_80040F48)
  addiu $v1, %lo(D_80040F48) # addiu $v1, $v1, 0xf48
  mtc1  $t2, $f4
  lwc1  $f8, ($v1)
  addiu $a1, $sp, 0x1c
  cvt.s.w $f6, $f4
  mul.s $f10, $f6, $f8
  swc1  $f10, ($a2)
  lh    $t3, 0xa($v0)
  lwc1  $f4, ($v1)
  mtc1  $t3, $f16
  nop   
  cvt.s.w $f18, $f16
  mul.s $f6, $f18, $f4
  swc1  $f6, 4($a2)
  lh    $t4, 0xc($v0)
  lwc1  $f16, ($v1)
  mtc1  $t4, $f8
  nop   
  cvt.s.w $f10, $f8
  mul.s $f18, $f10, $f16
  swc1  $f18, 8($a2)
  jal   sub_GAME_7F0AF924
   sw    $a2, 0x30($sp)
  lui   $at, %hi(D_800585D8)
  lwc1  $f0, %lo(D_800585D8)($at)
  lw    $a2, 0x30($sp)
  lwc1  $f4, 0x1c($sp)
  lui   $at, %hi(D_800585DC)
  lwc1  $f2, %lo(D_800585DC)($at)
  mul.s $f6, $f4, $f0
  lwc1  $f8, ($a2)
  mul.s $f10, $f2, $f8
  lwc1  $f8, 4($a2)
  add.s $f16, $f6, $f10
  swc1  $f16, ($a2)
  lwc1  $f18, 0x20($sp)
  mul.s $f4, $f18, $f0
  nop   
  mul.s $f6, $f2, $f8
  lwc1  $f8, 8($a2)
  add.s $f10, $f4, $f6
  swc1  $f10, 4($a2)
  lwc1  $f16, 0x24($sp)
  mul.s $f18, $f16, $f0
  nop   
  mul.s $f4, $f2, $f8
  add.s $f6, $f18, $f4
  swc1  $f6, 8($a2)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0AFB1C
  lwc1  $f4, ($a1)
  lwc1  $f6, ($a0)
  addiu $sp, $sp, -0x10
  sub.s $f8, $f4, $f6
  swc1  $f8, 4($sp)
  lwc1  $f16, 4($a0)
  lwc1  $f10, 4($a1)
  sub.s $f18, $f10, $f16
  lwc1  $f10, 4($sp)
  swc1  $f18, 8($sp)
  lwc1  $f6, 8($a0)
  lwc1  $f4, 8($a1)
  mul.s $f16, $f10, $f10
  lwc1  $f18, 8($sp)
  sub.s $f8, $f4, $f6
  mul.s $f4, $f18, $f18
  swc1  $f8, 0xc($sp)
  lwc1  $f8, 0xc($sp)
  addiu $sp, $sp, 0x10
  mul.s $f10, $f8, $f8
  add.s $f6, $f16, $f4
  jr    $ra
   add.s $f0, $f10, $f6
");

asm(R"
glabel sub_GAME_7F0AFB78
  addiu $sp, $sp, -0x88
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
  sdc1  $f22, 0x20($sp)
  sdc1  $f20, 0x18($sp)
  sw    $zero, 0x78($sp)
  lwc1  $f4, ($a0)
  lui   $t6, %hi(clippingfile) 
  lw    $t6, %lo(clippingfile)($t6)
  swc1  $f4, 0x64($sp)
  lwc1  $f6, ($a1)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $a3, $f22
  swc1  $f6, 0x68($sp)
  lwc1  $f8, ($a2)
  mtc1  $at, $f20
  move  $s3, $a0
  swc1  $f8, 0x6c($sp)
  lw    $s1, 4($t6)
  move  $s4, $a1
  move  $s5, $a2
  lw    $t7, ($s1)
  li    $s6, 3
  addiu $s7, $sp, 0x7c
  beqz  $t7, .L7F0AFCE0
   li    $fp, 4
  addiu $s2, $sp, 0x58
  lhu   $t8, ($s1)
.L7F0AFC08:
  li    $at, 1
  sra   $t9, $t8, 0xf
  andi  $t0, $t9, 1
  beql  $t0, $at, .L7F0AFCBC
   lh    $v0, 6($s1)
  jal   sub_GAME_7F0AF760
   move  $a0, $s1
  bnez  $v0, .L7F0AFCB8
   move  $s0, $zero
.L7F0AFC2C:
  bne   $s0, $s6, .L7F0AFC48
   move  $a0, $s1
  move  $a0, $s1
  jal   sub_GAME_7F0AF924
   move  $a1, $s2
  b     .L7F0AFC58
   mfc1  $a3, $f22
.L7F0AFC48:
  move  $a1, $s0
  jal   sub_GAME_7F0AFA1C
   move  $a2, $s2
  mfc1  $a3, $f22
.L7F0AFC58:
  sw    $s1, 0x7c($sp)
  move  $a0, $s7
  lw    $a1, 0x58($sp)
  jal   sub_GAME_7F0B20D0
   lw    $a2, 0x60($sp)
  bgez  $v0, .L7F0AFCAC
   move  $a0, $s2
  jal   sub_GAME_7F0AFB1C
   addiu $a1, $sp, 0x64
  c.lt.s $f0, $f20
  nop   
  bc1fl .L7F0AFCB0
   addiu $s0, $s0, 1
  lwc1  $f10, 0x58($sp)
  sw    $s1, 0x78($sp)
  mov.s $f20, $f0
  swc1  $f10, ($s3)
  lwc1  $f16, 0x5c($sp)
  swc1  $f16, ($s4)
  lwc1  $f18, 0x60($sp)
  swc1  $f18, ($s5)
.L7F0AFCAC:
  addiu $s0, $s0, 1
.L7F0AFCB0:
  bne   $s0, $fp, .L7F0AFC2C
   nop   
.L7F0AFCB8:
  lh    $v0, 6($s1)
.L7F0AFCBC:
  lui   $t3, %hi(list_of_tilesizes)
  sra   $t1, $v0, 0xc
  andi  $t2, $t1, 0xf
  addu  $t3, $t3, $t2
  lbu   $t3, %lo(list_of_tilesizes)($t3)
  addu  $s1, $t3, $s1
  lw    $t4, ($s1)
  bnezl $t4, .L7F0AFC08
   lhu   $t8, ($s1)
.L7F0AFCE0:
  lw    $ra, 0x4c($sp)
  lw    $v0, 0x78($sp)
  ldc1  $f20, 0x18($sp)
  ldc1  $f22, 0x20($sp)
  lw    $s0, 0x28($sp)
  lw    $s1, 0x2c($sp)
  lw    $s2, 0x30($sp)
  lw    $s3, 0x34($sp)
  lw    $s4, 0x38($sp)
  lw    $s5, 0x3c($sp)
  lw    $s6, 0x40($sp)
  lw    $s7, 0x44($sp)
  lw    $fp, 0x48($sp)
  jr    $ra
   addiu $sp, $sp, 0x88
");

asm(R"
glabel sub_GAME_7F0AFD1C
  addiu $sp, $sp, -0x48
  sw    $ra, 0x14($sp)
  sw    $a2, 0x50($sp)
  sw    $a3, 0x54($sp)
  lh    $t7, 6($a0)
  addiu $t6, $a1, 1
  sll   $t1, $a1, 3
  sra   $t8, $t7, 0xc
  andi  $t9, $t8, 0xf
  div   $zero, $t6, $t9
  mfhi  $a2
  sll   $t0, $a2, 3
  addu  $v0, $a0, $t0
  addu  $v1, $a0, $t1
  lh    $t3, 8($v1)
  lh    $t2, 8($v0)
  lh    $t7, 0xc($v1)
  lh    $t5, 0xc($v0)
  subu  $t4, $t2, $t3
  mtc1  $t4, $f4
  subu  $t8, $t5, $t7
  mtc1  $t8, $f6
  cvt.s.w $f2, $f4
  bnez  $t9, .L7F0AFD84
   nop   
  break 7
.L7F0AFD84:
  li    $at, -1
  bne   $t9, $at, .L7F0AFD9C
   lui   $at, 0x8000
  bne   $t6, $at, .L7F0AFD9C
   nop   
  break 6
.L7F0AFD9C:
  cvt.s.w $f14, $f6
  mul.s $f8, $f2, $f2
  swc1  $f2, 0x40($sp)
  sw    $v1, 0x18($sp)
  sw    $v0, 0x1c($sp)
  mul.s $f10, $f14, $f14
  swc1  $f14, 0x3c($sp)
  jal   sqrtf
   add.s $f12, $f8, $f10
  mtc1  $zero, $f4
  lw    $v0, 0x1c($sp)
  lw    $v1, 0x18($sp)
  c.eq.s $f0, $f4
  lwc1  $f2, 0x40($sp)
  lwc1  $f14, 0x3c($sp)
  lwc1  $f18, 0x50($sp)
  bc1f  .L7F0AFE24
   mov.s $f16, $f0
  lh    $t6, 8($v0)
  lh    $t9, 0xc($v0)
  lwc1  $f10, 0x54($sp)
  mtc1  $t6, $f6
  mtc1  $t9, $f4
  cvt.s.w $f8, $f6
  cvt.s.w $f6, $f4
  sub.s $f0, $f18, $f8
  sub.s $f2, $f10, $f6
  mul.s $f8, $f0, $f0
  nop   
  mul.s $f4, $f2, $f2
  jal   sqrtf
   add.s $f12, $f8, $f4
  b     .L7F0AFE64
   lw    $ra, 0x14($sp)
.L7F0AFE24:
  lh    $t0, 0xc($v1)
  lwc1  $f10, 0x54($sp)
  lh    $t1, 8($v1)
  mtc1  $t0, $f6
  nop   
  cvt.s.w $f8, $f6
  neg.s $f6, $f2
  sub.s $f4, $f10, $f8
  mtc1  $t1, $f8
  mul.s $f10, $f4, $f6
  cvt.s.w $f4, $f8
  sub.s $f6, $f18, $f4
  mul.s $f8, $f14, $f6
  add.s $f12, $f10, $f8
  div.s $f0, $f12, $f16
  lw    $ra, 0x14($sp)
.L7F0AFE64:
  addiu $sp, $sp, 0x48
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0AFE70
  addiu $sp, $sp, -0x48
  sw    $a3, 0x54($sp)
  li    $at, 2
  move  $a3, $a0
  sw    $ra, 0x14($sp)
  sw    $a0, 0x48($sp)
  beq   $a1, $at, .L7F0AFE98
   sw    $a2, 0x50($sp)
  b     .L7F0AFE9C
   addiu $v1, $a1, 1
.L7F0AFE98:
  move  $v1, $zero
.L7F0AFE9C:
  lh    $v0, 6($a3)
  li    $t0, 8
  sll   $t6, $a1, 2
  sll   $t9, $v1, 2
  subu  $t7, $t0, $t6
  subu  $t1, $t0, $t9
  srav  $a1, $v0, $t7
  srav  $v1, $v0, $t1
  andi  $t8, $a1, 0xf
  andi  $t2, $v1, 0xf
  sll   $t3, $t2, 3
  sll   $t4, $t8, 3
  addu  $a2, $a3, $t4
  addu  $a0, $a3, $t3
  lh    $t5, 8($a0)
  lh    $t6, 8($a2)
  lh    $t8, 0xc($a0)
  lh    $t9, 0xc($a2)
  subu  $t7, $t5, $t6
  mtc1  $t7, $f4
  subu  $t1, $t8, $t9
  mtc1  $t1, $f6
  cvt.s.w $f2, $f4
  sw    $a2, 0x18($sp)
  sw    $a0, 0x1c($sp)
  cvt.s.w $f14, $f6
  mul.s $f8, $f2, $f2
  swc1  $f2, 0x40($sp)
  mul.s $f10, $f14, $f14
  swc1  $f14, 0x3c($sp)
  jal   sqrtf
   add.s $f12, $f8, $f10
  mtc1  $zero, $f4
  lw    $a0, 0x1c($sp)
  lw    $a2, 0x18($sp)
  c.eq.s $f0, $f4
  lwc1  $f2, 0x40($sp)
  lwc1  $f14, 0x3c($sp)
  lwc1  $f18, 0x50($sp)
  bc1f  .L7F0AFF80
   mov.s $f16, $f0
  lh    $t2, 8($a0)
  lh    $t3, 0xc($a0)
  lwc1  $f10, 0x54($sp)
  mtc1  $t2, $f6
  mtc1  $t3, $f4
  cvt.s.w $f8, $f6
  cvt.s.w $f6, $f4
  sub.s $f0, $f18, $f8
  sub.s $f2, $f10, $f6
  mul.s $f8, $f0, $f0
  nop   
  mul.s $f4, $f2, $f2
  jal   sqrtf
   add.s $f12, $f8, $f4
  b     .L7F0AFFC0
   lw    $ra, 0x14($sp)
.L7F0AFF80:
  lh    $t4, 0xc($a2)
  lwc1  $f10, 0x54($sp)
  lh    $t5, 8($a2)
  mtc1  $t4, $f6
  nop   
  cvt.s.w $f8, $f6
  neg.s $f6, $f2
  sub.s $f4, $f10, $f8
  mtc1  $t5, $f8
  mul.s $f10, $f4, $f6
  cvt.s.w $f4, $f8
  sub.s $f6, $f18, $f4
  mul.s $f8, $f14, $f6
  add.s $f12, $f10, $f8
  div.s $f0, $f12, $f16
  lw    $ra, 0x14($sp)
.L7F0AFFC0:
  addiu $sp, $sp, 0x48
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0AFFCC
  lui   $at, %hi(D_80040F44)
  mtc1  $a2, $f12
  lwc1  $f0, %lo(D_80040F44)($at)
  mtc1  $a3, $f14
  addiu $sp, $sp, -0x18
  mul.s $f4, $f12, $f0
  sw    $ra, 0x14($sp)
  mul.s $f6, $f14, $f0
  mfc1  $a2, $f4
  mfc1  $a3, $f6
  jal   sub_GAME_7F0AFD1C
   nop   
  lui   $at, %hi(D_80040F48)
  lwc1  $f8, %lo(D_80040F48)($at)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  mul.s $f0, $f0, $f8
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B0018
  lui   $at, %hi(D_80040F44)
  mtc1  $a2, $f12
  lwc1  $f0, %lo(D_80040F44)($at)
  mtc1  $a3, $f14
  addiu $sp, $sp, -0x18
  mul.s $f4, $f12, $f0
  sw    $ra, 0x14($sp)
  mul.s $f6, $f14, $f0
  mfc1  $a2, $f4
  mfc1  $a3, $f6
  jal   sub_GAME_7F0AFE70
   nop   
  lui   $at, %hi(D_80040F48)
  lwc1  $f8, %lo(D_80040F48)($at)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  mul.s $f0, $f0, $f8
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B0064
  addiu $sp, $sp, -0x18
  sll   $t6, $a1, 3
  sw    $ra, 0x14($sp)
  sw    $a3, 0x24($sp)
  addu  $v0, $a0, $t6
  lh    $t8, 0xc($v0)
  lh    $t7, 8($v0)
  lwc1  $f8, 0x24($sp)
  mtc1  $t8, $f10
  mtc1  $t7, $f4
  mtc1  $a2, $f14
  cvt.s.w $f16, $f10
  cvt.s.w $f6, $f4
  sub.s $f18, $f8, $f16
  sub.s $f14, $f14, $f6
  mul.s $f4, $f18, $f18
  swc1  $f18, 0x24($sp)
  mul.s $f6, $f14, $f14
  jal   sqrtf
   add.s $f12, $f6, $f4
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B00C4
  addiu $sp, $sp, -0x20
  sll   $t6, $a1, 3
  sw    $ra, 0x1c($sp)
  sdc1  $f20, 0x10($sp)
  addu  $v0, $a0, $t6
  lh    $t7, 8($v0)
  lui   $at, %hi(D_80040F44)
  mtc1  $a2, $f14
  lwc1  $f0, %lo(D_80040F44)($at)
  lh    $t8, 0xc($v0)
  mtc1  $t7, $f4
  mul.s $f14, $f14, $f0
  mtc1  $a3, $f20
  mtc1  $t8, $f8
  mul.s $f20, $f20, $f0
  cvt.s.w $f6, $f4
  cvt.s.w $f10, $f8
  sub.s $f14, $f14, $f6
  sub.s $f20, $f20, $f10
  mul.s $f16, $f14, $f14
  nop   
  mul.s $f18, $f20, $f20
  jal   sqrtf
   add.s $f12, $f16, $f18
  lui   $at, %hi(D_80040F48)
  lwc1  $f4, %lo(D_80040F48)($at)
  lw    $ra, 0x1c($sp)
  ldc1  $f20, 0x10($sp)
  mul.s $f0, $f0, $f4
  jr    $ra
   addiu $sp, $sp, 0x20
");

asm(R"
glabel sub_GAME_7F0B0140
  lui   $at, %hi(D_80040F44)
  sll   $t6, $a1, 3
  mtc1  $a2, $f12
  lwc1  $f2, %lo(D_80040F44)($at)
  addu  $v0, $a0, $t6
  lh    $t7, 0xc($v0)
  mul.s $f12, $f12, $f2
  mtc1  $a3, $f14
  lh    $t8, 8($v0)
  mtc1  $t7, $f4
  mul.s $f14, $f14, $f2
  mtc1  $t8, $f10
  lui   $at, %hi(D_80040F48)
  cvt.s.w $f6, $f4
  cvt.s.w $f16, $f10
  mul.s $f8, $f6, $f14
  lwc1  $f6, %lo(D_80040F48)($at)
  mul.s $f18, $f12, $f16
  add.s $f4, $f8, $f18
  mul.s $f0, $f4, $f6
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B0198
  sw    $a2, 8($sp)
  sw    $a3, 0xc($sp)
  lh    $t0, 6($a0)
  addiu $t9, $a1, 1
  sll   $t6, $a1, 3
  sra   $t1, $t0, 0xc
  andi  $t2, $t1, 0xf
  div   $zero, $t9, $t2
  addu  $v0, $a0, $t6
  mfhi  $a1
  lh    $t7, 8($v0)
  lh    $t8, 0xc($v0)
  sll   $t3, $a1, 3
  addu  $v0, $a0, $t3
  lh    $t4, 8($v0)
  lh    $t5, 0xc($v0)
  mtc1  $t7, $f4
  mtc1  $t4, $f8
  mtc1  $t8, $f6
  cvt.s.w $f0, $f4
  mtc1  $t5, $f10
  lwc1  $f16, 8($sp)
  lwc1  $f4, 0xc($sp)
  move  $v0, $zero
  cvt.s.w $f12, $f8
  cvt.s.w $f2, $f6
  bnez  $t2, .L7F0B020C
   nop   
  break 7
.L7F0B020C:
  li    $at, -1
  bne   $t2, $at, .L7F0B0224
   lui   $at, 0x8000
  bne   $t9, $at, .L7F0B0224
   nop   
  break 6
.L7F0B0224:
  cvt.s.w $f14, $f10
  sub.s $f12, $f12, $f0
  sub.s $f14, $f14, $f2
  mul.s $f8, $f12, $f12
  sub.s $f18, $f16, $f0
  mul.s $f10, $f14, $f14
  sub.s $f6, $f4, $f2
  mul.s $f16, $f18, $f12
  swc1  $f18, 8($sp)
  mul.s $f4, $f6, $f14
  swc1  $f6, 0xc($sp)
  add.s $f2, $f8, $f10
  add.s $f0, $f16, $f4
  c.lt.s $f2, $f0
  nop   
  bc1f  .L7F0B026C
   nop   
  li    $v0, 1
.L7F0B026C:
  beql  $v0, $zero, .L7F0B029C
   mtc1  $zero, $f10
  mtc1  $zero, $f8
  move  $v0, $zero
  c.lt.s $f0, $f8
  nop   
  bc1f  .L7F0B0290
   nop   
  li    $v0, 1
.L7F0B0290:
  bnez  $v0, .L7F0B02D0
   nop   
  mtc1  $zero, $f10
.L7F0B029C:
  move  $v0, $zero
  c.lt.s $f10, $f0
  nop   
  bc1f  .L7F0B02B4
   nop   
  li    $v0, 1
.L7F0B02B4:
  beqz  $v0, .L7F0B02D0
   nop   
  c.lt.s $f0, $f2
  move  $v0, $zero
  bc1f  .L7F0B02D0
   nop   
  li    $v0, 1
.L7F0B02D0:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B02D8
  addiu $sp, $sp, -0x40
  sdc1  $f24, 0x28($sp)
  sdc1  $f22, 0x20($sp)
  sdc1  $f20, 0x18($sp)
  sw    $s2, 0x38($sp)
  sw    $s1, 0x34($sp)
  sw    $s0, 0x30($sp)
  mtc1  $a1, $f20
  mtc1  $a2, $f22
  mtc1  $zero, $f24
  move  $s1, $a0
  sw    $ra, 0x3c($sp)
  move  $s0, $zero
  li    $s2, 3
  mfc1  $a2, $f20
.L7F0B0314:
  mfc1  $a3, $f22
  move  $a0, $s1
  jal   sub_GAME_7F0AFE70
   move  $a1, $s0
  c.lt.s $f0, $f24
  addiu $s0, $s0, 1
  bc1f  .L7F0B033C
   nop   
  b     .L7F0B0348
   move  $v0, $zero
.L7F0B033C:
  bnel  $s0, $s2, .L7F0B0314
   mfc1  $a2, $f20
  li    $v0, 1
.L7F0B0348:
  lw    $ra, 0x3c($sp)
  ldc1  $f20, 0x18($sp)
  ldc1  $f22, 0x20($sp)
  ldc1  $f24, 0x28($sp)
  lw    $s0, 0x30($sp)
  lw    $s1, 0x34($sp)
  lw    $s2, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x40
");

asm(R"
glabel sub_GAME_7F0B036C
  addiu $sp, $sp, -0x40
  sdc1  $f24, 0x28($sp)
  sdc1  $f22, 0x20($sp)
  sdc1  $f20, 0x18($sp)
  sw    $s2, 0x38($sp)
  sw    $s1, 0x34($sp)
  sw    $s0, 0x30($sp)
  mtc1  $a1, $f20
  mtc1  $a2, $f22
  mtc1  $zero, $f24
  move  $s1, $a0
  sw    $ra, 0x3c($sp)
  move  $s0, $zero
  li    $s2, 3
  mfc1  $a2, $f20
.L7F0B03A8:
  mfc1  $a3, $f22
  move  $a0, $s1
  jal   sub_GAME_7F0B0018
   move  $a1, $s0
  c.lt.s $f0, $f24
  addiu $s0, $s0, 1
  bc1f  .L7F0B03D0
   nop   
  b     .L7F0B03DC
   move  $v0, $zero
.L7F0B03D0:
  bnel  $s0, $s2, .L7F0B03A8
   mfc1  $a2, $f20
  li    $v0, 1
.L7F0B03DC:
  lw    $ra, 0x3c($sp)
  ldc1  $f20, 0x18($sp)
  ldc1  $f22, 0x20($sp)
  ldc1  $f24, 0x28($sp)
  lw    $s0, 0x30($sp)
  lw    $s1, 0x34($sp)
  lw    $s2, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x40
");

asm(R"
glabel sub_GAME_7F0B0400
  addiu $sp, $sp, -0x40
  sw    $a3, 0x4c($sp)
  li    $at, 2
  move  $a3, $a0
  sw    $ra, 0x14($sp)
  sw    $a0, 0x40($sp)
  beq   $a1, $at, .L7F0B0428
   sw    $a2, 0x48($sp)
  b     .L7F0B042C
   addiu $a0, $a1, 1
.L7F0B0428:
  move  $a0, $zero
.L7F0B042C:
  lh    $v0, 6($a3)
  li    $t0, 8
  sll   $t6, $a1, 2
  sll   $t9, $a0, 2
  subu  $t7, $t0, $t6
  subu  $t1, $t0, $t9
  srav  $a1, $v0, $t7
  srav  $a0, $v0, $t1
  andi  $t8, $a1, 0xf
  andi  $t2, $a0, 0xf
  sll   $t3, $t2, 3
  sll   $t4, $t8, 3
  addu  $a2, $a3, $t4
  addu  $v1, $a3, $t3
  lh    $t5, 8($v1)
  lh    $t6, 8($a2)
  lh    $t8, 0xc($v1)
  lh    $t9, 0xc($a2)
  subu  $t7, $t5, $t6
  mtc1  $t7, $f4
  subu  $t1, $t8, $t9
  mtc1  $t1, $f6
  cvt.s.w $f2, $f4
  sw    $a2, 0x1c($sp)
  cvt.s.w $f14, $f6
  mul.s $f8, $f2, $f2
  swc1  $f2, 0x38($sp)
  mul.s $f10, $f14, $f14
  swc1  $f14, 0x34($sp)
  jal   sqrtf
   add.s $f12, $f8, $f10
  mtc1  $zero, $f12
  lw    $a2, 0x1c($sp)
  lwc1  $f2, 0x38($sp)
  c.eq.s $f0, $f12
  lwc1  $f14, 0x34($sp)
  mov.s $f16, $f0
  lw    $ra, 0x14($sp)
  bc1fl .L7F0B04D8
   lh    $t2, 0xc($a2)
  b     .L7F0B0510
   mov.s $f0, $f12
  lh    $t2, 0xc($a2)
.L7F0B04D8:
  lwc1  $f18, 0x4c($sp)
  lh    $t3, 8($a2)
  mtc1  $t2, $f4
  neg.s $f10, $f2
  cvt.s.w $f6, $f4
  sub.s $f8, $f18, $f6
  mtc1  $t3, $f6
  lwc1  $f18, 0x48($sp)
  mul.s $f4, $f8, $f10
  cvt.s.w $f8, $f6
  sub.s $f10, $f18, $f8
  mul.s $f6, $f14, $f10
  add.s $f12, $f4, $f6
  div.s $f0, $f12, $f16
.L7F0B0510:
  jr    $ra
   addiu $sp, $sp, 0x40
");

asm(R"
glabel sub_GAME_7F0B0518
  addiu $sp, $sp, -0x40
  sdc1  $f20, 0x18($sp)
  lui   $at, %hi(D_80040F44)
  mtc1  $a1, $f20
  lwc1  $f0, %lo(D_80040F44)($at)
  sdc1  $f22, 0x20($sp)
  mtc1  $a2, $f22
  mul.s $f20, $f20, $f0
  sdc1  $f24, 0x28($sp)
  li    $at, 0xC0000000 # -2.000000
  sw    $s2, 0x38($sp)
  sw    $s1, 0x34($sp)
  sw    $s0, 0x30($sp)
  mtc1  $at, $f24
  mul.s $f22, $f22, $f0
  move  $s1, $a0
  sw    $ra, 0x3c($sp)
  move  $s0, $zero
  li    $s2, 3
  mfc1  $a2, $f20
.L7F0B0568:
  mfc1  $a3, $f22
  move  $a0, $s1
  jal   sub_GAME_7F0B0400
   move  $a1, $s0
  c.lt.s $f0, $f24
  addiu $s0, $s0, 1
  bc1f  .L7F0B0590
   nop   
  b     .L7F0B059C
   move  $v0, $zero
.L7F0B0590:
  bnel  $s0, $s2, .L7F0B0568
   mfc1  $a2, $f20
  li    $v0, 1
.L7F0B059C:
  lw    $ra, 0x3c($sp)
  ldc1  $f20, 0x18($sp)
  ldc1  $f22, 0x20($sp)
  ldc1  $f24, 0x28($sp)
  lw    $s0, 0x30($sp)
  lw    $s1, 0x34($sp)
  lw    $s2, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x40
");

asm(R"
glabel sub_GAME_7F0B05C0
  sw    $a2, 8($sp)
  lwc1  $f4, 8($sp)
  sw    $a3, 0xc($sp)
  lwc1  $f6, 0xc($sp)
  mul.s $f0, $f14, $f4
  nop   
  mul.s $f2, $f12, $f6
  c.lt.s $f0, $f2
  nop   
  bc1f  .L7F0B05F4
   nop   
  jr    $ra
   li    $v0, 1

.L7F0B05F4:
  c.lt.s $f2, $f0
  lwc1  $f8, 8($sp)
  bc1f  .L7F0B060C
   nop   
  jr    $ra
   li    $v0, -1

.L7F0B060C:
  mul.s $f10, $f12, $f8
  mtc1  $zero, $f0
  lwc1  $f16, 0xc($sp)
  c.lt.s $f10, $f0
  nop   
  bc1t  .L7F0B063C
   nop   
  mul.s $f18, $f14, $f16
  c.lt.s $f18, $f0
  nop   
  bc1f  .L7F0B0644
   nop   
.L7F0B063C:
  jr    $ra
   li    $v0, -1

.L7F0B0644:
  mul.s $f4, $f12, $f12
  lwc1  $f10, 8($sp)
  lwc1  $f18, 0xc($sp)
  mul.s $f6, $f14, $f14
  move  $v0, $zero
  mul.s $f16, $f10, $f10
  add.s $f8, $f4, $f6
  mul.s $f4, $f18, $f18
  add.s $f6, $f16, $f4
  c.lt.s $f8, $f6
  nop   
  bc1f  .L7F0B0680
   nop   
  jr    $ra
   li    $v0, 1

.L7F0B0680:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B0688
  addiu $sp, $sp, -0x48
  lwc1  $f18, 0x58($sp)
  lwc1  $f16, 0x5c($sp)
  swc1  $f12, 0x48($sp)
  lwc1  $f10, 0x48($sp)
  swc1  $f14, 0x4c($sp)
  lwc1  $f8, 0x4c($sp)
  sub.s $f0, $f10, $f18
  sw    $a2, 0x50($sp)
  lwc1  $f18, 0x50($sp)
  sub.s $f2, $f8, $f16
  sw    $a3, 0x54($sp)
  lwc1  $f16, 0x54($sp)
  sub.s $f12, $f18, $f10
  sw    $ra, 0x14($sp)
  swc1  $f0, 0x24($sp)
  sub.s $f14, $f16, $f8
  swc1  $f2, 0x20($sp)
  swc1  $f12, 0x1c($sp)
  neg.s $f8, $f0
  neg.s $f16, $f2
  mfc1  $a2, $f8
  mfc1  $a3, $f16
  jal   sub_GAME_7F0B05C0
   swc1  $f14, 0x18($sp)
  lwc1  $f6, 0x60($sp)
  lwc1  $f16, 0x48($sp)
  lwc1  $f10, 0x64($sp)
  lwc1  $f4, 0x4c($sp)
  sub.s $f18, $f6, $f16
  lwc1  $f12, 0x1c($sp)
  lwc1  $f14, 0x18($sp)
  sub.s $f8, $f10, $f4
  mfc1  $a2, $f18
  sw    $v0, 0x2c($sp)
  mfc1  $a3, $f8
  jal   sub_GAME_7F0B05C0
   nop   
  lw    $t6, 0x2c($sp)
  lwc1  $f6, 0x60($sp)
  lwc1  $f16, 0x58($sp)
  multu $v0, $t6
  lwc1  $f18, 0x64($sp)
  lwc1  $f10, 0x5c($sp)
  mflo  $v0
  slti  $t7, $v0, 1
  beqz  $t7, .L7F0B07AC
   move  $v0, $t7
  sub.s $f12, $f6, $f16
  lw    $a2, 0x24($sp)
  lw    $a3, 0x20($sp)
  sub.s $f14, $f18, $f10
  swc1  $f12, 0x1c($sp)
  jal   sub_GAME_7F0B05C0
   swc1  $f14, 0x18($sp)
  lwc1  $f4, 0x50($sp)
  lwc1  $f8, 0x58($sp)
  lwc1  $f16, 0x54($sp)
  lwc1  $f18, 0x5c($sp)
  sub.s $f6, $f4, $f8
  lwc1  $f12, 0x1c($sp)
  lwc1  $f14, 0x18($sp)
  sub.s $f10, $f16, $f18
  mfc1  $a2, $f6
  sw    $v0, 0x28($sp)
  mfc1  $a3, $f10
  jal   sub_GAME_7F0B05C0
   nop   
  lw    $t8, 0x28($sp)
  multu $v0, $t8
  mflo  $v0
  slti  $t9, $v0, 1
  move  $v0, $t9
.L7F0B07AC:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x48
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B07BC
  addiu $sp, $sp, -0x68
  swc1  $f12, 0x68($sp)
  sw    $a2, 0x70($sp)
  lwc1  $f4, 0x70($sp)
  lwc1  $f6, 0x68($sp)
  swc1  $f14, 0x6c($sp)
  lwc1  $f10, 0x6c($sp)
  sub.s $f12, $f4, $f6
  lwc1  $f4, 0x7c($sp)
  lwc1  $f16, 0x78($sp)
  sw    $a3, 0x74($sp)
  sub.s $f2, $f10, $f4
  lwc1  $f8, 0x74($sp)
  sw    $ra, 0x14($sp)
  sub.s $f0, $f6, $f16
  li    $t6, 1
  sw    $t6, 0x44($sp)
  sub.s $f14, $f8, $f10
  swc1  $f0, 0x28($sp)
  swc1  $f2, 0x24($sp)
  neg.s $f8, $f2
  neg.s $f18, $f0
  mfc1  $a3, $f8
  mfc1  $a2, $f18
  swc1  $f14, 0x1c($sp)
  jal   sub_GAME_7F0B05C0
   swc1  $f12, 0x20($sp)
  lwc1  $f6, 0x80($sp)
  lwc1  $f16, 0x68($sp)
  lwc1  $f10, 0x84($sp)
  lwc1  $f4, 0x6c($sp)
  sub.s $f18, $f6, $f16
  lwc1  $f12, 0x20($sp)
  lwc1  $f14, 0x1c($sp)
  sub.s $f8, $f10, $f4
  mfc1  $a2, $f18
  sw    $v0, 0x2c($sp)
  mfc1  $a3, $f8
  jal   sub_GAME_7F0B05C0
   nop   
  lw    $t7, 0x2c($sp)
  lwc1  $f6, 0x80($sp)
  lwc1  $f16, 0x78($sp)
  multu $v0, $t7
  lwc1  $f18, 0x84($sp)
  lwc1  $f10, 0x7c($sp)
  sub.s $f12, $f6, $f16
  lw    $a2, 0x28($sp)
  lw    $a3, 0x24($sp)
  sub.s $f14, $f18, $f10
  swc1  $f12, 0x20($sp)
  mflo  $t8
  sw    $t8, 0x4c($sp)
  jal   sub_GAME_7F0B05C0
   swc1  $f14, 0x1c($sp)
  lwc1  $f4, 0x70($sp)
  lwc1  $f8, 0x78($sp)
  lwc1  $f16, 0x74($sp)
  lwc1  $f18, 0x7c($sp)
  sub.s $f6, $f4, $f8
  lwc1  $f12, 0x20($sp)
  lwc1  $f14, 0x1c($sp)
  sub.s $f10, $f16, $f18
  mfc1  $a2, $f6
  sw    $v0, 0x2c($sp)
  mfc1  $a3, $f10
  jal   sub_GAME_7F0B05C0
   nop   
  lw    $v1, 0x88($sp)
  lw    $t9, 0x4c($sp)
  slt   $at, $t9, $v1
  bnezl $at, .L7F0B08E8
   lw    $t0, 0x2c($sp)
  sw    $zero, 0x44($sp)
  lw    $t0, 0x2c($sp)
.L7F0B08E8:
  lw    $a0, 0x44($sp)
  lw    $ra, 0x14($sp)
  multu $v0, $t0
  addiu $sp, $sp, 0x68
  mflo  $t1
  slt   $at, $t1, $v1
  bnez  $at, .L7F0B090C
   nop   
  move  $a0, $zero
.L7F0B090C:
  jr    $ra
   move  $v0, $a0
");

asm(R"
glabel sub_GAME_7F0B0914
  addiu $sp, $sp, -0xb8
  sdc1  $f20, 0x30($sp)
  lui   $at, %hi(D_80040F44)
  mtc1  $a1, $f20
  lwc1  $f0, %lo(D_80040F44)($at)
  sdc1  $f22, 0x38($sp)
  mtc1  $a2, $f22
  mul.s $f20, $f20, $f0
  sdc1  $f24, 0x40($sp)
  mtc1  $a3, $f24
  mul.s $f22, $f22, $f0
  sdc1  $f26, 0x48($sp)
  lwc1  $f26, 0xc8($sp)
  mul.s $f24, $f24, $f0
  sw    $ra, 0x84($sp)
  sw    $fp, 0x80($sp)
  mul.s $f26, $f26, $f0
  sw    $s7, 0x7c($sp)
  sw    $s6, 0x78($sp)
  sw    $s5, 0x74($sp)
  sw    $s4, 0x70($sp)
  sw    $s3, 0x6c($sp)
  sw    $s2, 0x68($sp)
  sw    $s1, 0x64($sp)
  sw    $s0, 0x60($sp)
  sdc1  $f30, 0x58($sp)
  sdc1  $f28, 0x50($sp)
  sw    $a0, 0xb8($sp)
  lw    $v0, ($a0)
  sub.s $f28, $f26, $f22
  move  $t6, $a0
  move  $s5, $zero
  sw    $zero, 0x8c($sp)
  neg.s $f28, $f28
  sub.s $f30, $f24, $f20
  move  $s1, $zero
  move  $s4, $zero
  lw    $fp, 0x98($sp)
  move  $s3, $v0
  move  $s6, $v0
  move  $s7, $v0
.L7F0B09B8:
  lw    $t7, 0xcc($sp)
  move  $a0, $s3
  beql  $t7, $zero, .L7F0B09D8
   lh    $a0, 6($s3)
  move  $a1, $s6
  jalr  $t7
  lw    $a2, 0xd0($sp)
  lh    $a0, 6($s3)
.L7F0B09D8:
  move  $s0, $s3
  sra   $t8, $a0, 0xc
  andi  $t9, $t8, 0xf
  blez  $t9, .L7F0B0B2C
   move  $a0, $t9
.L7F0B09EC:
  addiu $s2, $s1, 1
  div   $zero, $s2, $a0
  mfhi  $v1
  sll   $t3, $v1, 3
  addu  $v0, $s3, $t3
  lh    $a1, 0xc($v0)
  lh    $t0, 0xc($s0)
  lh    $t1, 8($v0)
  lh    $t2, 8($s0)
  subu  $t4, $a1, $t0
  mtc1  $t4, $f6
  subu  $t5, $t1, $t2
  mtc1  $t5, $f16
  cvt.s.w $f8, $f6
  mtc1  $zero, $f4
  bnez  $a0, .L7F0B0A34
   nop   
  break 7
.L7F0B0A34:
  li    $at, -1
  bne   $a0, $at, .L7F0B0A4C
   lui   $at, 0x8000
  bne   $s2, $at, .L7F0B0A4C
   nop   
  break 6
.L7F0B0A4C:
  cvt.s.w $f18, $f16
  mul.s $f10, $f8, $f30
  nop   
  mul.s $f6, $f28, $f18
  add.s $f8, $f10, $f6
  c.le.s $f8, $f4
  nop   
  bc1f  .L7F0B0B0C
   nop   
  mtc1  $t2, $f16
  mtc1  $t0, $f10
  mtc1  $t1, $f4
  cvt.s.w $f18, $f16
  mtc1  $a1, $f16
  lhu   $v0, 0xe($s0)
  mfc1  $a2, $f24
  mfc1  $a3, $f26
  cvt.s.w $f6, $f10
  swc1  $f18, 0x10($sp)
  sra   $t6, $v0, 4
  sltu  $t7, $zero, $t6
  sw    $t7, 0x20($sp)
  cvt.s.w $f8, $f4
  swc1  $f6, 0x14($sp)
  mov.s $f12, $f20
  mov.s $f14, $f22
  cvt.s.w $f18, $f16
  swc1  $f8, 0x18($sp)
  jal   sub_GAME_7F0B07BC
   swc1  $f18, 0x1c($sp)
  beql  $v0, $zero, .L7F0B0B10
   lh    $a0, 6($s3)
  lhu   $v1, 0xe($s0)
  lui   $t9, %hi(base_ptr_connection_vals) 
  lw    $t9, %lo(base_ptr_connection_vals)($t9)
  sll   $t8, $v1, 3
  addiu $s4, $s4, 1
  addu  $v0, $t8, $t9
  beq   $s6, $v0, .L7F0B0B0C
   nop   
  beq   $s7, $v0, .L7F0B0B0C
   nop   
  sra   $t3, $v1, 4
  beqz  $t3, .L7F0B0B08
   move  $fp, $s1
  b     .L7F0B0B0C
   move  $s5, $v0
.L7F0B0B08:
  move  $s5, $zero
.L7F0B0B0C:
  lh    $a0, 6($s3)
.L7F0B0B10:
  move  $s1, $s2
  addiu $s0, $s0, 8
  sra   $t4, $a0, 0xc
  andi  $t5, $t4, 0xf
  slt   $at, $s2, $t5
  bnez  $at, .L7F0B09EC
   move  $a0, $t5
.L7F0B0B2C:
  move  $s7, $s6
  move  $s6, $s3
  xor   $v0, $s3, $s5
  bnez  $v0, .L7F0B0B44
   move  $s3, $s5
  move  $s4, $zero
.L7F0B0B44:
  bnez  $s4, .L7F0B0B54
   lw    $t6, 0x8c($sp)
  b     .L7F0B0B9C
   li    $v0, 1
.L7F0B0B54:
  slti  $v0, $t6, 0x1f5
  xori  $v0, $v0, 1
  addiu $t7, $t6, 1
  bnez  $v0, .L7F0B0B78
   sw    $t7, 0x8c($sp)
  beqz  $s5, .L7F0B0B78
   lw    $t8, 0xb8($sp)
  bnez  $s4, .L7F0B0B90
   move  $s1, $zero
.L7F0B0B78:
  lui   $at, %hi(dword_CODE_bss_8007B9E4)
  sw    $s6, %lo(dword_CODE_bss_8007B9E4)($at)
  lui   $at, %hi(dword_CODE_bss_8007B9E8)
  sw    $fp, %lo(dword_CODE_bss_8007B9E8)($at)
  b     .L7F0B0B9C
   move  $v0, $zero
.L7F0B0B90:
  sw    $s5, ($t8)
  b     .L7F0B09B8
   move  $s4, $zero
.L7F0B0B9C:
  lw    $ra, 0x84($sp)
  ldc1  $f20, 0x30($sp)
  ldc1  $f22, 0x38($sp)
  ldc1  $f24, 0x40($sp)
  ldc1  $f26, 0x48($sp)
  ldc1  $f28, 0x50($sp)
  ldc1  $f30, 0x58($sp)
  lw    $s0, 0x60($sp)
  lw    $s1, 0x64($sp)
  lw    $s2, 0x68($sp)
  lw    $s3, 0x6c($sp)
  lw    $s4, 0x70($sp)
  lw    $s5, 0x74($sp)
  lw    $s6, 0x78($sp)
  lw    $s7, 0x7c($sp)
  lw    $fp, 0x80($sp)
  jr    $ra
   addiu $sp, $sp, 0xb8
");

asm(R"
glabel sub_GAME_7F0B0BE4
  addiu $sp, $sp, -0x28
  mtc1  $a1, $f12
  mtc1  $a2, $f14
  lwc1  $f4, 0x38($sp)
  sw    $ra, 0x24($sp)
  mfc1  $a1, $f12
  mfc1  $a2, $f14
  sw    $a3, 0x34($sp)
  sw    $zero, 0x14($sp)
  sw    $zero, 0x18($sp)
  jal   sub_GAME_7F0B0914
   swc1  $f4, 0x10($sp)
  lw    $ra, 0x24($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B0C24
  addiu $sp, $sp, -0x40
  mtc1  $a1, $f12
  mtc1  $a2, $f14
  lw    $t6, 0x54($sp)
  lw    $t7, 0x5c($sp)
  lwc1  $f4, 0x50($sp)
  lui   $t9, %hi(sub_GAME_7F0B0C98) # $t9, 0x7f0b
  sw    $ra, 0x24($sp)
  li    $t8, -1
  addiu $t9, %lo(sub_GAME_7F0B0C98) # addiu $t9, $t9, 0xc98
  addiu $t0, $sp, 0x30
  mfc1  $a1, $f12
  mfc1  $a2, $f14
  sw    $a3, 0x4c($sp)
  sw    $zero, 0x34($sp)
  sw    $t8, 0x3c($sp)
  sw    $t0, 0x18($sp)
  sw    $t9, 0x14($sp)
  sw    $t6, 0x30($sp)
  sw    $t7, 0x38($sp)
  jal   sub_GAME_7F0B0914
   swc1  $f4, 0x10($sp)
  lw    $t1, 0x34($sp)
  lw    $t2, 0x58($sp)
  sw    $t1, ($t2)
  lw    $ra, 0x24($sp)
  addiu $sp, $sp, 0x40
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B0C98
  sw    $a1, 4($sp)
  lw    $t6, 0xc($a2)
  lbu   $v0, 3($a0)
  beq   $t6, $v0, .L7F0B0CE4
   nop   
  lw    $t7, 4($a2)
  lw    $t8, 8($a2)
  slt   $at, $t7, $t8
  beqz  $at, .L7F0B0CE4
   nop   
  lw    $t9, ($a2)
  sw    $v0, ($t9)
  lw    $t0, ($a2)
  lw    $t2, 4($a2)
  sw    $v0, 0xc($a2)
  addiu $t1, $t0, 4
  addiu $t3, $t2, 1
  sw    $t1, ($a2)
  sw    $t3, 4($a2)
.L7F0B0CE4:
  jr    $ra
   nop   
");

void sub_GAME_7F0B0CEC(void) { sub_GAME_7F0B0C98(); }

asm(R"
glabel sub_GAME_7F0B0D0C
  addiu $sp, $sp, -0x48
  sw    $ra, 0x2c($sp)
  sw    $s0, 0x28($sp)
  sw    $a0, 0x48($sp)
  sw    $a1, 0x4c($sp)
  sw    $a2, 0x50($sp)
  sw    $a0, 0x44($sp)
  sw    $zero, 0x40($sp)
  lw    $v0, ($a3)
  move  $s0, $a3
  beql  $v0, $zero, .L7F0B0D90
   lw    $v1, 0x60($sp)
  lbu   $a2, 3($a0)
  lbu   $a3, 3($v0)
  lw    $v1, 0x60($sp)
  li    $v0, 1
  bne   $a2, $a3, .L7F0B0D5C
   andi  $a0, $a2, 0xff
  b     .L7F0B0E10
   sw    $a2, ($v1)
.L7F0B0D5C:
  jal   sub_GAME_7F0B8FD0
   andi  $a1, $a3, 0xff
  beqz  $v0, .L7F0B0D8C
   lw    $t7, 0x48($sp)
  lw    $v1, 0x60($sp)
  lbu   $t8, 3($t7)
  li    $v0, 2
  sw    $t8, ($v1)
  lw    $t9, ($s0)
  lbu   $t0, 3($t9)
  b     .L7F0B0E10
   sw    $t0, 4($v1)
.L7F0B0D8C:
  lw    $v1, 0x60($sp)
.L7F0B0D90:
  lwc1  $f4, 0x5c($sp)
  lw    $t2, 0x64($sp)
  addiu $t1, $sp, 0x40
  sw    $t1, 0x18($sp)
  addiu $a0, $sp, 0x44
  lw    $a1, 0x4c($sp)
  lw    $a2, 0x50($sp)
  lw    $a3, 0x58($sp)
  sw    $v1, 0x14($sp)
  swc1  $f4, 0x10($sp)
  jal   sub_GAME_7F0B0C24
   sw    $t2, 0x1c($sp)
  bnez  $v0, .L7F0B0DD0
   lw    $v1, 0x64($sp)
  b     .L7F0B0E10
   move  $v0, $zero
.L7F0B0DD0:
  lw    $t3, 0x40($sp)
  slt   $at, $v1, $t3
  beql  $at, $zero, .L7F0B0DE8
   lw    $v0, ($s0)
  sw    $v1, 0x40($sp)
  lw    $v0, ($s0)
.L7F0B0DE8:
  bnezl $v0, .L7F0B0DFC
   lw    $t5, 0x44($sp)
  lw    $v0, 0x44($sp)
  sw    $v0, ($s0)
  lw    $t5, 0x44($sp)
.L7F0B0DFC:
  beql  $t5, $v0, .L7F0B0E10
   lw    $v0, 0x40($sp)
  b     .L7F0B0E10
   move  $v0, $zero
  lw    $v0, 0x40($sp)
.L7F0B0E10:
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x28($sp)
  addiu $sp, $sp, 0x48
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B0E24
  addiu $sp, $sp, -0x160
  lwc1  $f4, 0x178($sp)
  lwc1  $f6, 0x17c($sp)
  sdc1  $f28, 0x48($sp)
  sdc1  $f24, 0x38($sp)
  c.le.s $f6, $f4
  li    $at, 0x3F800000 # 1.000000
  mtc1  $a3, $f24
  sw    $s0, 0x58($sp)
  sdc1  $f26, 0x40($sp)
  mtc1  $a1, $f12
  mtc1  $a2, $f14
  mtc1  $at, $f28
  lwc1  $f26, 0x170($sp)
  addiu $s0, $sp, 0xd0
  sw    $ra, 0x7c($sp)
  sw    $fp, 0x78($sp)
  sw    $s7, 0x74($sp)
  sw    $s6, 0x70($sp)
  sw    $s5, 0x6c($sp)
  sw    $s4, 0x68($sp)
  sw    $s3, 0x64($sp)
  sw    $s2, 0x60($sp)
  sw    $s1, 0x5c($sp)
  sdc1  $f30, 0x50($sp)
  sdc1  $f22, 0x30($sp)
  sdc1  $f20, 0x28($sp)
  sw    $a0, 0x160($sp)
  sw    $zero, 0x124($sp)
  bc1f  .L7F0B0EA4
   move  $t6, $zero
  li    $t6, 1
.L7F0B0EA4:
  lw    $t7, 0x160($sp)
  sw    $t6, 0xcc($sp)
  mfc1  $a1, $f12
  lw    $t8, ($t7)
  mfc1  $a2, $f14
  mfc1  $a3, $f24
  addiu $t9, $sp, 0x124
  li    $t3, 20
  move  $s5, $zero
  swc1  $f12, 0x14c($sp)
  swc1  $f14, 0x150($sp)
  swc1  $f24, 0x144($sp)
  swc1  $f26, 0x148($sp)
  sw    $t3, 0x1c($sp)
  sw    $t9, 0x18($sp)
  swc1  $f14, 0x168($sp)
  swc1  $f12, 0x164($sp)
  sw    $s0, 0x14($sp)
  swc1  $f26, 0x10($sp)
  addiu $a0, $sp, 0x154
  jal   sub_GAME_7F0B0C24
   sw    $t8, 0x154($sp)
  lw    $t4, 0x124($sp)
  lui   $a3, %hi(flt_CODE_bss_8007B9F8)
  sw    $v0, 0x158($sp)
  slti  $at, $t4, 0x15
  bnez  $at, .L7F0B0F1C
   addiu $a3, %lo(flt_CODE_bss_8007B9F8) # addiu $a3, $a3, -0x4608
  li    $t5, 20
  sw    $t5, 0x124($sp)
.L7F0B0F1C:
  bnez  $v0, .L7F0B100C
   lui   $fp, %hi(flt_CODE_bss_8007B9F0) 
  lui   $v0, %hi(dword_CODE_bss_8007B9E4)
  lw    $v0, %lo(dword_CODE_bss_8007B9E4)($v0)
  lui   $v1, %hi(dword_CODE_bss_8007B9E8)
  lw    $v1, %lo(dword_CODE_bss_8007B9E8)($v1)
  lh    $t7, 6($v0)
  li    $t3, 1
  addiu $t6, $v1, 1
  sra   $t8, $t7, 0xc
  andi  $t9, $t8, 0xf
  div   $zero, $t6, $t9
  sll   $t4, $v1, 3
  addu  $t0, $v0, $t4
  addiu $fp, %lo(flt_CODE_bss_8007B9F0) # addiu $fp, $fp, -0x4610
  bnez  $t9, .L7F0B0F64
   nop   
  break 7
.L7F0B0F64:
  li    $at, -1
  bne   $t9, $at, .L7F0B0F7C
   lui   $at, 0x8000
  bne   $t6, $at, .L7F0B0F7C
   nop   
  break 6
.L7F0B0F7C:
  lui   $at, %hi(D_800413BC)
  sw    $t3, %lo(D_800413BC)($at)
  lh    $t5, 8($t0)
  lui   $at, %hi(D_80040F48)
  lwc1  $f0, %lo(D_80040F48)($at)
  mtc1  $t5, $f8
  mfhi  $t2
  sll   $t8, $t2, 3
  cvt.s.w $f10, $f8
  addu  $t1, $v0, $t8
  move  $a2, $fp
  addiu $a0, $sp, 0x14c
  addiu $a1, $sp, 0x144
  mul.s $f18, $f10, $f0
  swc1  $f18, ($fp)
  lh    $t7, 0xc($t0)
  mtc1  $t7, $f4
  nop   
  cvt.s.w $f6, $f4
  mul.s $f8, $f6, $f0
  swc1  $f8, 4($fp)
  lh    $t6, 8($t1)
  mtc1  $t6, $f10
  nop   
  cvt.s.w $f18, $f10
  mul.s $f4, $f18, $f0
  swc1  $f4, ($a3)
  lh    $t9, 0xc($t1)
  mtc1  $t9, $f6
  nop   
  cvt.s.w $f8, $f6
  mul.s $f10, $f8, $f0
  jal   sub_GAME_7F0B3200
   swc1  $f10, 4($a3)
  b     .L7F0B1014
   mov.s $f28, $f0
.L7F0B100C:
  lui   $fp, %hi(flt_CODE_bss_8007B9F0) 
  addiu $fp, %lo(flt_CODE_bss_8007B9F0) # addiu $fp, $fp, -0x4610
.L7F0B1014:
  lw    $t3, 0x174($sp)
  lui   $s7, %hi(dword_CODE_bss_8007BA04) 
  addiu $s7, %lo(dword_CODE_bss_8007BA04) # addiu $s7, $s7, -0x45fc
  beqz  $t3, .L7F0B1360
   sw    $zero, ($s7)
  lw    $t5, 0x124($sp)
  li    $t4, -1
  move  $a0, $s0
  sll   $t7, $t5, 2
  addu  $t8, $s0, $t7
  jal   sub_GAME_7F03E3FC
   sw    $t4, ($t8)
  lui   $v1, %hi(ptr_list_object_lookup_indices)
  lw    $v1, %lo(ptr_list_object_lookup_indices)($v1)
  addiu $s4, $sp, 0x12c
  addiu $s3, $sp, 0x134
  lh    $v0, ($v1)
  bltzl $v0, .L7F0B1364
   lw    $t4, 0x154($sp)
  sw    $v1, 0xb8($sp)
  lwc1  $f30, 0xc4($sp)
.L7F0B1068:
  sll   $t6, $v0, 2
  subu  $t6, $t6, $v0
  sll   $t6, $t6, 2
  addu  $t6, $t6, $v0
  lui   $t9, %hi(pos_data_entry) 
  addiu $t9, %lo(pos_data_entry) # addiu $t9, $t9, -0x63c8
  sll   $t6, $t6, 2
  addu  $s6, $t6, $t9
  move  $a0, $s6
  jal   sub_GAME_7F03DA50
   lw    $a1, 0x174($sp)
  beqz  $v0, .L7F0B1344
   lwc1  $f16, 0xc0($sp)
  addiu $t3, $sp, 0xa0
  sw    $t3, 0x10($sp)
  move  $a0, $s6
  addiu $a1, $sp, 0xb4
  addiu $a2, $sp, 0xb0
  addiu $a3, $sp, 0xa4
  jal   sub_GAME_7F03CC20
   swc1  $f16, 0xc0($sp)
  lw    $v0, 0xb0($sp)
  lwc1  $f16, 0xc0($sp)
  blezl $v0, .L7F0B1348
   lw    $v1, 0xb8($sp)
  blez  $v0, .L7F0B1344
   move  $a1, $zero
  move  $s1, $zero
  lw    $t5, 0xb0($sp)
.L7F0B10DC:
  addiu $s2, $a1, 1
  lw    $t7, 0xb4($sp)
  div   $zero, $s2, $t5
  addu  $v1, $t7, $s1
  lwc1  $f18, ($v1)
  mfhi  $v0
  sll   $t4, $v0, 3
  swc1  $f18, 0x10($sp)
  lwc1  $f4, 4($v1)
  addu  $a0, $t7, $t4
  mfc1  $a2, $f24
  swc1  $f4, 0x14($sp)
  lwc1  $f6, ($a0)
  mfc1  $a3, $f26
  bnez  $t5, .L7F0B1120
   nop   
  break 7
.L7F0B1120:
  li    $at, -1
  bne   $t5, $at, .L7F0B1138
   li    $at, 0x80000000 # -0.000000
  bne   $s2, $at, .L7F0B1138
   nop   
  break 6
.L7F0B1138:
  swc1  $f6, 0x18($sp)
  lwc1  $f8, 4($a0)
  move  $s0, $v0
  swc1  $f16, 0xc0($sp)
  lwc1  $f12, 0x164($sp)
  lwc1  $f14, 0x168($sp)
  jal   sub_GAME_7F0B0688
   swc1  $f8, 0x1c($sp)
  beqz  $v0, .L7F0B132C
   lwc1  $f16, 0xc0($sp)
  lw    $t8, 0xb4($sp)
  sll   $t6, $s0, 3
  addiu $a0, $sp, 0x14c
  addu  $v1, $t8, $s1
  lwc1  $f10, ($v1)
  addu  $v0, $t8, $t6
  addiu $a1, $sp, 0x144
  swc1  $f10, 0x134($sp)
  lwc1  $f18, 4($v1)
  move  $a2, $s3
  move  $a3, $s4
  swc1  $f18, 0x138($sp)
  lwc1  $f4, ($v0)
  swc1  $f4, 0x12c($sp)
  lwc1  $f6, 4($v0)
  swc1  $f16, 0xc0($sp)
  jal   sub_GAME_7F0B3200
   swc1  $f6, 0x130($sp)
  c.lt.s $f0, $f28
  lwc1  $f16, 0xc0($sp)
  mov.s $f22, $f0
  bc1fl .L7F0B1330
   lw    $v0, 0xb0($sp)
  lw    $t9, 0xcc($sp)
  li    $s0, 1
  beqz  $t9, .L7F0B12D4
   nop   
  bnez  $s5, .L7F0B1290
   lwc1  $f8, 0x180($sp)
  lwc1  $f10, 0x184($sp)
  li    $s5, 1
  lwc1  $f18, 0x178($sp)
  c.le.s $f10, $f8
  lwc1  $f4, 0x17c($sp)
  li    $at, 0x3F800000 # 1.000000
  bc1fl .L7F0B1204
   mtc1  $at, $f6
  sub.s $f30, $f8, $f18
  b     .L7F0B1290
   sub.s $f16, $f10, $f4
  mtc1  $at, $f6
.L7F0B1204:
  lwc1  $f0, 0x164($sp)
  lwc1  $f2, 0x168($sp)
  c.lt.s $f28, $f6
  nop   
  bc1fl .L7F0B123C
   lwc1  $f0, 0x164($sp)
  sub.s $f24, $f24, $f0
  sub.s $f26, $f26, $f2
  mul.s $f24, $f24, $f28
  nop   
  mul.s $f26, $f26, $f28
  add.s $f24, $f0, $f24
  add.s $f26, $f2, $f26
  lwc1  $f0, 0x164($sp)
.L7F0B123C:
  lwc1  $f2, 0x168($sp)
  lw    $t3, 0x160($sp)
  mfc1  $a1, $f0
  mfc1  $a2, $f2
  jal   sub_GAME_7F0B2970
   lw    $a0, ($t3)
  lwc1  $f8, 0x178($sp)
  lwc1  $f10, 0x17c($sp)
  mfc1  $a1, $f24
  add.s $f18, $f8, $f0
  mfc1  $a2, $f26
  mov.s $f20, $f0
  add.s $f4, $f10, $f0
  swc1  $f18, 0x178($sp)
  lw    $a0, 0x154($sp)
  jal   sub_GAME_7F0B2970
   swc1  $f4, 0x17c($sp)
  sub.s $f6, $f0, $f20
  div.s $f2, $f6, $f28
  mov.s $f16, $f2
  mov.s $f30, $f2
.L7F0B1290:
  mul.s $f8, $f16, $f22
  lwc1  $f18, 0x17c($sp)
  lwc1  $f4, 0xa4($sp)
  add.s $f10, $f8, $f18
  c.le.s $f4, $f10
  nop   
  bc1tl .L7F0B12D4
   move  $s0, $zero
  mul.s $f8, $f30, $f22
  lwc1  $f18, 0x178($sp)
  lwc1  $f6, 0xa0($sp)
  add.s $f10, $f8, $f18
  c.le.s $f10, $f6
  nop   
  bc1f  .L7F0B12D4
   nop   
  move  $s0, $zero
.L7F0B12D4:
  beqz  $s0, .L7F0B132C
   li    $t5, 1
  lui   $at, %hi(D_800413BC)
  sw    $zero, 0x158($sp)
  sw    $t5, %lo(D_800413BC)($at)
  lw    $at, ($s3)
  lw    $t8, 4($s3)
  lui   $t6, %hi(flt_CODE_bss_8007B9F8) 
  sw    $at, ($fp)
  lw    $at, ($s4)
  addiu $t6, %lo(flt_CODE_bss_8007B9F8) # addiu $t6, $t6, -0x4608
  sw    $t8, 4($fp)
  sw    $at, ($t6)
  lw    $t5, 4($s4)
  lui   $at, %hi(dword_CODE_bss_8007B9E4)
  mov.s $f28, $f22
  sw    $t5, 4($t6)
  sw    $zero, %lo(dword_CODE_bss_8007B9E4)($at)
  lui   $at, %hi(dword_CODE_bss_8007B9E8)
  sw    $zero, %lo(dword_CODE_bss_8007B9E8)($at)
  sw    $s6, ($s7)
  sw    $zero, 0x154($sp)
.L7F0B132C:
  lw    $v0, 0xb0($sp)
.L7F0B1330:
  move  $a1, $s2
  addiu $s1, $s1, 8
  slt   $at, $s2, $v0
  bnezl $at, .L7F0B10DC
   lw    $t5, 0xb0($sp)
.L7F0B1344:
  lw    $v1, 0xb8($sp)
.L7F0B1348:
  lh    $v0, 2($v1)
  addiu $v1, $v1, 2
  sw    $v1, 0xb8($sp)
  bgez  $v0, .L7F0B1068
   swc1  $f16, 0xc0($sp)
  swc1  $f30, 0xc4($sp)
.L7F0B1360:
  lw    $t4, 0x154($sp)
.L7F0B1364:
  lwc1  $f0, 0x164($sp)
  lwc1  $f2, 0x168($sp)
  bnezl $t4, .L7F0B13B4
   lw    $t3, 0x154($sp)
  sub.s $f24, $f24, $f0
  lw    $t7, 0x160($sp)
  mfc1  $a1, $f0
  sub.s $f26, $f26, $f2
  mul.s $f24, $f24, $f28
  lw    $t8, ($t7)
  mfc1  $a2, $f2
  mul.s $f26, $f26, $f28
  addiu $a0, $sp, 0x154
  sw    $t8, 0x154($sp)
  add.s $f24, $f0, $f24
  add.s $f26, $f2, $f26
  mfc1  $a3, $f24
  jal   sub_GAME_7F0B0BE4
   swc1  $f26, 0x10($sp)
  lw    $t3, 0x154($sp)
.L7F0B13B4:
  lw    $t9, 0x160($sp)
  lui   $at, %hi(flt_CODE_bss_8007BA00)
  sw    $t3, ($t9)
  lw    $ra, 0x7c($sp)
  swc1  $f28, %lo(flt_CODE_bss_8007BA00)($at)
  ldc1  $f28, 0x48($sp)
  lw    $fp, 0x78($sp)
  lw    $s7, 0x74($sp)
  lw    $s6, 0x70($sp)
  lw    $s5, 0x6c($sp)
  lw    $s4, 0x68($sp)
  lw    $s3, 0x64($sp)
  lw    $s2, 0x60($sp)
  lw    $s1, 0x5c($sp)
  lw    $s0, 0x58($sp)
  ldc1  $f30, 0x50($sp)
  ldc1  $f26, 0x40($sp)
  ldc1  $f24, 0x38($sp)
  ldc1  $f22, 0x30($sp)
  ldc1  $f20, 0x28($sp)
  lw    $v0, 0x158($sp)
  jr    $ra
   addiu $sp, $sp, 0x160
");

asm(R"
glabel sub_GAME_7F0B1410
  addiu $sp, $sp, -0x128
  sdc1  $f26, 0x40($sp)
  sdc1  $f24, 0x38($sp)
  sdc1  $f22, 0x30($sp)
  mtc1  $a1, $f22
  mtc1  $a2, $f24
  mtc1  $a3, $f26
  sdc1  $f28, 0x48($sp)
  lwc1  $f28, 0x138($sp)
  sw    $s1, 0x54($sp)
  sdc1  $f20, 0x28($sp)
  li    $at, 0x3F800000 # 1.000000
  addiu $s1, $sp, 0x98
  sw    $ra, 0x74($sp)
  sw    $fp, 0x70($sp)
  mtc1  $at, $f20
  sw    $a0, 0xf0($sp)
  addiu $t6, $sp, 0xec
  li    $t7, 20
  mfc1  $a1, $f22
  mfc1  $a2, $f24
  mfc1  $a3, $f26
  sw    $s7, 0x6c($sp)
  sw    $s6, 0x68($sp)
  sw    $s5, 0x64($sp)
  sw    $s4, 0x60($sp)
  sw    $s3, 0x5c($sp)
  sw    $s2, 0x58($sp)
  sw    $s0, 0x50($sp)
  move  $fp, $zero
  sw    $t7, 0x1c($sp)
  sw    $t6, 0x18($sp)
  addiu $a0, $sp, 0xf0
  sw    $s1, 0x14($sp)
  sw    $zero, 0xec($sp)
  jal   sub_GAME_7F0B0C24
   swc1  $f28, 0x10($sp)
  lw    $v1, 0xec($sp)
  li    $t9, -1
  move  $a0, $s1
  slti  $at, $v1, 0x15
  bnezl $at, .L7F0B14C4
   lw    $t8, 0x13c($sp)
  li    $v1, 20
  lw    $t8, 0x13c($sp)
.L7F0B14C4:
  swc1  $f22, 0x118($sp)
  swc1  $f24, 0x11c($sp)
  swc1  $f26, 0x110($sp)
  beqz  $t8, .L7F0B167C
   swc1  $f28, 0x114($sp)
  sll   $t0, $v1, 2
  addu  $t1, $s1, $t0
  sw    $t9, ($t1)
  jal   sub_GAME_7F03E3FC
   sw    $v1, 0xec($sp)
  lui   $v1, %hi(ptr_list_object_lookup_indices)
  lw    $v1, %lo(ptr_list_object_lookup_indices)($v1)
  addiu $s7, $sp, 0xf8
  addiu $s6, $sp, 0x100
  lh    $v0, ($v1)
  addiu $s5, $sp, 0x110
  addiu $s4, $sp, 0x118
  bltzl $v0, .L7F0B1680
   lw    $ra, 0x74($sp)
  sw    $v1, 0x94($sp)
  sll   $t2, $v0, 2
.L7F0B1518:
  subu  $t2, $t2, $v0
  sll   $t2, $t2, 2
  addu  $t2, $t2, $v0
  lui   $t3, %hi(pos_data_entry) 
  addiu $t3, %lo(pos_data_entry) # addiu $t3, $t3, -0x63c8
  sll   $t2, $t2, 2
  addu  $s3, $t2, $t3
  move  $a0, $s3
  jal   sub_GAME_7F03DA50
   lw    $a1, 0x13c($sp)
  beqz  $v0, .L7F0B1664
   move  $a0, $s3
  addiu $a1, $sp, 0x90
  jal   sub_GAME_7F03CCB0
   addiu $a2, $sp, 0x8c
  lw    $v0, 0x8c($sp)
  blezl $v0, .L7F0B1668
   lw    $v1, 0x94($sp)
  blez  $v0, .L7F0B1664
   move  $a1, $zero
  move  $s0, $zero
  lw    $t4, 0x8c($sp)
.L7F0B1570:
  addiu $s2, $a1, 1
  lw    $t5, 0x90($sp)
  div   $zero, $s2, $t4
  addu  $v1, $t5, $s0
  lwc1  $f4, ($v1)
  mfhi  $v0
  sll   $t6, $v0, 3
  swc1  $f4, 0x10($sp)
  lwc1  $f6, 4($v1)
  addu  $a0, $t5, $t6
  mfc1  $a2, $f26
  swc1  $f6, 0x14($sp)
  lwc1  $f8, ($a0)
  mfc1  $a3, $f28
  bnez  $t4, .L7F0B15B4
   nop   
  break 7
.L7F0B15B4:
  li    $at, -1
  bne   $t4, $at, .L7F0B15CC
   lui   $at, 0x8000
  bne   $s2, $at, .L7F0B15CC
   nop   
  break 6
.L7F0B15CC:
  swc1  $f8, 0x18($sp)
  lwc1  $f10, 4($a0)
  move  $s1, $v0
  mov.s $f12, $f22
  mov.s $f14, $f24
  jal   sub_GAME_7F0B0688
   swc1  $f10, 0x1c($sp)
  beql  $v0, $zero, .L7F0B1650
   lw    $v0, 0x8c($sp)
  lw    $t7, 0x90($sp)
  sll   $t8, $s1, 3
  move  $a0, $s4
  addu  $v1, $t7, $s0
  lwc1  $f16, ($v1)
  addu  $v0, $t7, $t8
  move  $a1, $s5
  swc1  $f16, 0x100($sp)
  lwc1  $f18, 4($v1)
  move  $a2, $s6
  move  $a3, $s7
  swc1  $f18, 0x104($sp)
  lwc1  $f4, ($v0)
  swc1  $f4, 0xf8($sp)
  lwc1  $f6, 4($v0)
  jal   sub_GAME_7F0B3200
   swc1  $f6, 0xfc($sp)
  c.lt.s $f0, $f20
  nop   
  bc1fl .L7F0B1650
   lw    $v0, 0x8c($sp)
  mov.s $f20, $f0
  move  $fp, $s3
  lw    $v0, 0x8c($sp)
.L7F0B1650:
  move  $a1, $s2
  addiu $s0, $s0, 8
  slt   $at, $s2, $v0
  bnezl $at, .L7F0B1570
   lw    $t4, 0x8c($sp)
.L7F0B1664:
  lw    $v1, 0x94($sp)
.L7F0B1668:
  lh    $v0, 2($v1)
  addiu $v1, $v1, 2
  sw    $v1, 0x94($sp)
  bgezl $v0, .L7F0B1518
   sll   $t2, $v0, 2
.L7F0B167C:
  lw    $ra, 0x74($sp)
.L7F0B1680:
  move  $v0, $fp
  lw    $fp, 0x70($sp)
  ldc1  $f20, 0x28($sp)
  ldc1  $f22, 0x30($sp)
  ldc1  $f24, 0x38($sp)
  ldc1  $f26, 0x40($sp)
  ldc1  $f28, 0x48($sp)
  lw    $s0, 0x50($sp)
  lw    $s1, 0x54($sp)
  lw    $s2, 0x58($sp)
  lw    $s3, 0x5c($sp)
  lw    $s4, 0x60($sp)
  lw    $s5, 0x64($sp)
  lw    $s6, 0x68($sp)
  lw    $s7, 0x6c($sp)
  jr    $ra
   addiu $sp, $sp, 0x128
");

asm(R"
glabel sub_GAME_7F0B16C4
  addiu $sp, $sp, -0x48
  swc1  $f12, 0x48($sp)
  sw    $a2, 0x50($sp)
  lwc1  $f4, 0x50($sp)
  lwc1  $f6, 0x48($sp)
  swc1  $f14, 0x4c($sp)
  sw    $a3, 0x54($sp)
  sub.s $f2, $f4, $f6
  lwc1  $f8, 0x54($sp)
  lwc1  $f10, 0x4c($sp)
  sw    $ra, 0x14($sp)
  mul.s $f18, $f2, $f2
  sub.s $f16, $f8, $f10
  swc1  $f2, 0x20($sp)
  mul.s $f4, $f16, $f16
  swc1  $f16, 0x1c($sp)
  jal   sqrtf
   add.s $f12, $f18, $f4
  mtc1  $zero, $f6
  lwc1  $f2, 0x20($sp)
  lwc1  $f16, 0x1c($sp)
  c.eq.s $f0, $f6
  mov.s $f12, $f0
  lwc1  $f8, 0x58($sp)
  lwc1  $f10, 0x58($sp)
  bc1f  .L7F0B1760
   lwc1  $f18, 0x48($sp)
  lwc1  $f10, 0x50($sp)
  lwc1  $f18, 0x5c($sp)
  lwc1  $f4, 0x54($sp)
  sub.s $f0, $f8, $f10
  sub.s $f2, $f18, $f4
  mul.s $f6, $f0, $f0
  nop   
  mul.s $f8, $f2, $f2
  jal   sqrtf
   add.s $f12, $f6, $f8
  b     .L7F0B1788
   lw    $ra, 0x14($sp)
.L7F0B1760:
  sub.s $f4, $f10, $f18
  lwc1  $f10, 0x4c($sp)
  lwc1  $f8, 0x5c($sp)
  mul.s $f6, $f16, $f4
  sub.s $f18, $f8, $f10
  neg.s $f4, $f2
  mul.s $f8, $f4, $f18
  add.s $f10, $f6, $f8
  div.s $f0, $f10, $f12
  lw    $ra, 0x14($sp)
.L7F0B1788:
  addiu $sp, $sp, 0x48
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B1794
  addiu $sp, $sp, -0x18
  swc1  $f12, 0x18($sp)
  sw    $a2, 0x20($sp)
  lwc1  $f4, 0x20($sp)
  lwc1  $f6, 0x18($sp)
  sw    $a3, 0x24($sp)
  lwc1  $f10, 0x24($sp)
  sub.s $f8, $f4, $f6
  sw    $ra, 0x14($sp)
  sub.s $f16, $f10, $f14
  mul.s $f18, $f8, $f8
  swc1  $f8, 0x20($sp)
  mul.s $f4, $f16, $f16
  swc1  $f16, 0x24($sp)
  jal   sqrtf
   add.s $f12, $f18, $f4
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B17E4
  lwc1  $f4, 0x10($sp)
  lwc1  $f8, 0x14($sp)
  sw    $a2, 8($sp)
  sub.s $f6, $f4, $f12
  lwc1  $f4, 8($sp)
  sw    $a3, 0xc($sp)
  sub.s $f10, $f8, $f14
  lwc1  $f8, 0xc($sp)
  swc1  $f6, 0x10($sp)
  sub.s $f0, $f4, $f12
  swc1  $f10, 0x14($sp)
  move  $v0, $zero
  sub.s $f2, $f8, $f14
  mul.s $f4, $f0, $f0
  nop   
  mul.s $f8, $f2, $f2
  add.s $f18, $f4, $f8
  mul.s $f4, $f6, $f0
  nop   
  mul.s $f8, $f10, $f2
  add.s $f16, $f4, $f8
  c.lt.s $f18, $f16
  nop   
  bc1f  .L7F0B184C
   nop   
  li    $v0, 1
.L7F0B184C:
  beql  $v0, $zero, .L7F0B187C
   mtc1  $zero, $f10
  mtc1  $zero, $f6
  move  $v0, $zero
  c.lt.s $f16, $f6
  nop   
  bc1f  .L7F0B1870
   nop   
  li    $v0, 1
.L7F0B1870:
  bnez  $v0, .L7F0B18B0
   nop   
  mtc1  $zero, $f10
.L7F0B187C:
  move  $v0, $zero
  c.lt.s $f10, $f16
  nop   
  bc1f  .L7F0B1894
   nop   
  li    $v0, 1
.L7F0B1894:
  beqz  $v0, .L7F0B18B0
   nop   
  c.lt.s $f16, $f18
  move  $v0, $zero
  bc1f  .L7F0B18B0
   nop   
  li    $v0, 1
.L7F0B18B0:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B18B8
  addiu $sp, $sp, -0x120
  lwc1  $f4, 0x134($sp)
  lwc1  $f6, 0x138($sp)
  sdc1  $f30, 0x50($sp)
  sdc1  $f28, 0x48($sp)
  c.le.s $f6, $f4
  sdc1  $f26, 0x40($sp)
  mtc1  $a1, $f26
  mtc1  $a2, $f28
  mtc1  $a3, $f30
  sw    $s2, 0x60($sp)
  sw    $s1, 0x5c($sp)
  sw    $s0, 0x58($sp)
  move  $s1, $a0
  addiu $s2, $sp, 0xa8
  sw    $ra, 0x7c($sp)
  sw    $fp, 0x78($sp)
  sw    $s7, 0x74($sp)
  sw    $s6, 0x70($sp)
  sw    $s5, 0x6c($sp)
  sw    $s4, 0x68($sp)
  sw    $s3, 0x64($sp)
  sdc1  $f24, 0x38($sp)
  sdc1  $f22, 0x30($sp)
  sdc1  $f20, 0x28($sp)
  bc1f  .L7F0B1928
   move  $s0, $zero
  li    $s0, 1
.L7F0B1928:
  mfc1  $a1, $f26
  mfc1  $a2, $f28
  mfc1  $a3, $f30
  addiu $t6, $sp, 0xfc
  li    $t7, 20
  sw    $s0, 0x108($sp)
  sw    $zero, 0xfc($sp)
  sw    $t7, 0x18($sp)
  sw    $t6, 0x14($sp)
  move  $a0, $s1
  jal   sub_GAME_7F0B21B0
   sw    $s2, 0x10($sp)
  bltz  $v0, .L7F0B1968
   lw    $t8, 0xfc($sp)
  b     .L7F0B1C80
   lw    $ra, 0x7c($sp)
.L7F0B1968:
  slti  $at, $t8, 0x15
  bnez  $at, .L7F0B1978
   li    $t9, 20
  sw    $t9, 0xfc($sp)
.L7F0B1978:
  lw    $t0, 0x130($sp)
  lui   $at, %hi(dword_CODE_bss_8007BA04)
  sw    $zero, %lo(dword_CODE_bss_8007BA04)($at)
  beql  $t0, $zero, .L7F0B1C7C
   li    $v0, -2
  beql  $s0, $zero, .L7F0B19C0
   lw    $t2, 0xfc($sp)
  mfc1  $a1, $f26
  mfc1  $a2, $f28
  jal   sub_GAME_7F0B2970
   lw    $a0, ($s1)
  lwc1  $f8, 0x134($sp)
  lwc1  $f16, 0x138($sp)
  add.s $f10, $f8, $f0
  add.s $f18, $f16, $f0
  swc1  $f10, 0x134($sp)
  swc1  $f18, 0x138($sp)
  lw    $t2, 0xfc($sp)
.L7F0B19C0:
  li    $t1, -1
  move  $a0, $s2
  sll   $t3, $t2, 2
  addu  $t4, $s2, $t3
  jal   sub_GAME_7F03E3FC
   sw    $t1, ($t4)
  lui   $v1, %hi(ptr_list_object_lookup_indices)
  lw    $v1, %lo(ptr_list_object_lookup_indices)($v1)
  lui   $fp, %hi(dword_CODE_bss_8007B9E4) 
  lui   $s6, %hi(D_800413BC)
  lh    $v0, ($v1)
  addiu $s6, %lo(D_800413BC) # addiu $s6, $s6, 0x13bc
  addiu $fp, %lo(dword_CODE_bss_8007B9E4) # addiu $fp, $fp, -0x461c
  bltz  $v0, .L7F0B1C78
   li    $s7, 1
  lui   $s4, %hi(flt_CODE_bss_8007B9F8)
  lui   $s3, %hi(flt_CODE_bss_8007B9F0)
  addiu $s3, %lo(flt_CODE_bss_8007B9F0) # addiu $s3, $s3, -0x4610
  addiu $s4, %lo(flt_CODE_bss_8007B9F8) # addiu $s4, $s4, -0x4608
  sw    $v1, 0x100($sp)
  sll   $t5, $v0, 2
.L7F0B1A14:
  subu  $t5, $t5, $v0
  sll   $t5, $t5, 2
  addu  $t5, $t5, $v0
  lui   $t6, %hi(pos_data_entry) 
  addiu $t6, %lo(pos_data_entry) # addiu $t6, $t6, -0x63c8
  sll   $t5, $t5, 2
  addu  $s5, $t5, $t6
  move  $a0, $s5
  jal   sub_GAME_7F03DA50
   lw    $a1, 0x130($sp)
  beqz  $v0, .L7F0B1C60
   move  $a0, $s5
  addiu $t7, $sp, 0x90
  sw    $t7, 0x10($sp)
  addiu $a1, $sp, 0xa4
  addiu $a2, $sp, 0xa0
  jal   sub_GAME_7F03CC20
   addiu $a3, $sp, 0x94
  lw    $t8, 0xa0($sp)
  lw    $t9, 0x108($sp)
  blezl $t8, .L7F0B1C64
   lw    $v1, 0x100($sp)
  beqz  $t9, .L7F0B1AA4
   li    $at, 0xBF800000 # -1.000000
  lwc1  $f4, 0x134($sp)
  lwc1  $f6, 0x90($sp)
  lwc1  $f8, 0x94($sp)
  lwc1  $f10, 0x138($sp)
  c.le.s $f6, $f4
  nop   
  bc1fl .L7F0B1C64
   lw    $v1, 0x100($sp)
  c.le.s $f10, $f8
  nop   
  bc1fl .L7F0B1C64
   lw    $v1, 0x100($sp)
.L7F0B1AA4:
  mtc1  $at, $f24
  move  $a1, $zero
.L7F0B1AAC:
  lw    $t2, 0xa0($sp)
  addiu $t0, $a1, 1
  lw    $t3, 0xa4($sp)
  div   $zero, $t0, $t2
  mfhi  $v1
  sll   $t1, $v1, 3
  sll   $s1, $a1, 3
  addu  $v0, $t3, $s1
  addu  $a0, $t3, $t1
  lw    $a2, ($a0)
  lw    $a3, 4($a0)
  lwc1  $f12, ($v0)
  lwc1  $f14, 4($v0)
  bnez  $t2, .L7F0B1AEC
   nop   
  break 7
.L7F0B1AEC:
  li    $at, -1
  bne   $t2, $at, .L7F0B1B04
   lui   $at, 0x8000
  bne   $t0, $at, .L7F0B1B04
   nop   
  break 6
.L7F0B1B04:
  move  $s2, $v1
  swc1  $f28, 0x14($sp)
  jal   sub_GAME_7F0B16C4
   swc1  $f26, 0x10($sp)
  mtc1  $zero, $f16
  mov.s $f20, $f0
  c.lt.s $f0, $f16
  nop   
  bc1fl .L7F0B1B34
   c.lt.s $f24, $f20
  neg.s $f20, $f0
  c.lt.s $f24, $f20
.L7F0B1B34:
  nop   
  bc1f  .L7F0B1C2C
   nop   
  lw    $t4, 0xa4($sp)
  mfc1  $a2, $f26
  mfc1  $a3, $f28
  addu  $v0, $t4, $s1
  lwc1  $f12, ($v0)
  jal   sub_GAME_7F0B1794
   lwc1  $f14, 4($v0)
  lw    $t5, 0xa4($sp)
  sll   $s0, $s2, 3
  mfc1  $a2, $f26
  mfc1  $a3, $f28
  addu  $v1, $t5, $s0
  mov.s $f22, $f0
  lwc1  $f12, ($v1)
  jal   sub_GAME_7F0B1794
   lwc1  $f14, 4($v1)
  c.lt.s $f20, $f30
  nop   
  bc1f  .L7F0B1C2C
   nop   
  c.lt.s $f22, $f30
  nop   
  bc1tl .L7F0B1BE4
   lw    $t7, 0xa4($sp)
  c.lt.s $f0, $f30
  nop   
  bc1tl .L7F0B1BE4
   lw    $t7, 0xa4($sp)
  lw    $t6, 0xa4($sp)
  addu  $v0, $t6, $s1
  addu  $v1, $t6, $s0
  lw    $a2, ($v1)
  lw    $a3, 4($v1)
  lwc1  $f12, ($v0)
  lwc1  $f14, 4($v0)
  swc1  $f28, 0x14($sp)
  jal   sub_GAME_7F0B17E4
   swc1  $f26, 0x10($sp)
  beqz  $v0, .L7F0B1C2C
   nop   
  lw    $t7, 0xa4($sp)
.L7F0B1BE4:
  sw    $s7, ($s6)
  lw    $t8, 0xa4($sp)
  addu  $v0, $t7, $s1
  lwc1  $f18, ($v0)
  addu  $v1, $t8, $s0
  lui   $at, %hi(dword_CODE_bss_8007B9E8)
  swc1  $f18, ($s3)
  lwc1  $f4, 4($v0)
  mov.s $f24, $f20
  swc1  $f4, 4($s3)
  lwc1  $f6, ($v1)
  swc1  $f6, ($s4)
  lwc1  $f8, 4($v1)
  sw    $zero, ($fp)
  swc1  $f8, 4($s4)
  sw    $zero, %lo(dword_CODE_bss_8007B9E8)($at)
  lui   $at, %hi(dword_CODE_bss_8007BA04)
  sw    $s5, %lo(dword_CODE_bss_8007BA04)($at)
.L7F0B1C2C:
  beql  $s2, $zero, .L7F0B1C40
   lui   $at, 0xbf80
  b     .L7F0B1AAC
   move  $a1, $s2
  li    $at, 0xBF800000 # -1.000000
.L7F0B1C40:
  mtc1  $at, $f10
  nop   
  c.lt.s $f10, $f24
  nop   
  bc1fl .L7F0B1C64
   lw    $v1, 0x100($sp)
  b     .L7F0B1C7C
   li    $v0, 2
.L7F0B1C60:
  lw    $v1, 0x100($sp)
.L7F0B1C64:
  lh    $v0, 2($v1)
  addiu $v1, $v1, 2
  sw    $v1, 0x100($sp)
  bgezl $v0, .L7F0B1A14
   sll   $t5, $v0, 2
.L7F0B1C78:
  li    $v0, -2
.L7F0B1C7C:
  lw    $ra, 0x7c($sp)
.L7F0B1C80:
  ldc1  $f20, 0x28($sp)
  ldc1  $f22, 0x30($sp)
  ldc1  $f24, 0x38($sp)
  ldc1  $f26, 0x40($sp)
  ldc1  $f28, 0x48($sp)
  ldc1  $f30, 0x50($sp)
  lw    $s0, 0x58($sp)
  lw    $s1, 0x5c($sp)
  lw    $s2, 0x60($sp)
  lw    $s3, 0x64($sp)
  lw    $s4, 0x68($sp)
  lw    $s5, 0x6c($sp)
  lw    $s6, 0x70($sp)
  lw    $s7, 0x74($sp)
  lw    $fp, 0x78($sp)
  jr    $ra
   addiu $sp, $sp, 0x120
");

void sub_GAME_7F0B1CC4(void) {
  dword_CODE_bss_8007B9E4 = 0;
  dword_CODE_bss_8007B9E8 = 0;
  D_800413BC = 0;
}

int sub_GAME_7F0B1CE0(void) { return dword_CODE_bss_8007B9E4; }

int sub_GAME_7F0B1CEC(void) { return dword_CODE_bss_8007B9E8; }

asm(R"
glabel sub_GAME_7F0B1CF8
  sll   $t6, $a1, 3
  addu  $v0, $a0, $t6
  lh    $t7, 8($v0)
  lui   $at, %hi(D_80040F48)
  lwc1  $f0, %lo(D_80040F48)($at)
  mtc1  $t7, $f4
  addiu $t0, $a1, 1
  cvt.s.w $f6, $f4
  mul.s $f8, $f6, $f0
  swc1  $f8, ($a2)
  lh    $t8, 0xa($v0)
  mtc1  $t8, $f10
  nop   
  cvt.s.w $f16, $f10
  mul.s $f18, $f16, $f0
  swc1  $f18, 4($a2)
  lh    $t9, 0xc($v0)
  mtc1  $t9, $f4
  nop   
  cvt.s.w $f6, $f4
  mul.s $f8, $f6, $f0
  swc1  $f8, 8($a2)
  lh    $t1, 6($a0)
  sra   $t2, $t1, 0xc
  andi  $t3, $t2, 0xf
  div   $zero, $t0, $t3
  mfhi  $a1
  sll   $t4, $a1, 3
  addu  $v0, $a0, $t4
  lh    $t5, 8($v0)
  bnez  $t3, .L7F0B1D7C
   nop   
  break 7
.L7F0B1D7C:
  li    $at, -1
  bne   $t3, $at, .L7F0B1D94
   lui   $at, 0x8000
  bne   $t0, $at, .L7F0B1D94
   nop   
  break 6
.L7F0B1D94:
  mtc1  $t5, $f10
  nop   
  cvt.s.w $f16, $f10
  mul.s $f18, $f16, $f0
  swc1  $f18, ($a3)
  lh    $t6, 0xa($v0)
  mtc1  $t6, $f4
  nop   
  cvt.s.w $f6, $f4
  mul.s $f8, $f6, $f0
  swc1  $f8, 4($a3)
  lh    $t7, 0xc($v0)
  mtc1  $t7, $f10
  nop   
  cvt.s.w $f16, $f10
  mul.s $f18, $f16, $f0
  jr    $ra
   swc1  $f18, 8($a3)
");

asm(R"
glabel sub_GAME_7F0B1DDC
  addiu $sp, $sp, -0x150
  sdc1  $f26, 0x38($sp)
  lui   $at, %hi(D_80040F44)
  mtc1  $a1, $f26
  lwc1  $f0, %lo(D_80040F44)($at)
  sdc1  $f28, 0x40($sp)
  mtc1  $a2, $f28
  mul.s $f26, $f26, $f0
  sdc1  $f30, 0x48($sp)
  mtc1  $a3, $f30
  mul.s $f28, $f28, $f0
  sw    $ra, 0x74($sp)
  sw    $fp, 0x70($sp)
  sw    $s7, 0x6c($sp)
  sw    $s6, 0x68($sp)
  sw    $s5, 0x64($sp)
  sw    $s4, 0x60($sp)
  sw    $s3, 0x5c($sp)
  sw    $s2, 0x58($sp)
  sw    $s1, 0x54($sp)
  sw    $s0, 0x50($sp)
  sdc1  $f24, 0x30($sp)
  sdc1  $f22, 0x28($sp)
  sdc1  $f20, 0x20($sp)
  sw    $zero, 0xa4($sp)
  lw    $t6, ($a0)
  addiu $t7, $sp, 0xb0
  mul.s $f30, $f30, $f0
  li    $s4, 1
  sw    $t7, 0x84($sp)
  addiu $s2, $sp, 0xb0
  lw    $s6, 0x164($sp)
  lw    $s7, 0x16c($sp)
  lw    $fp, 0x168($sp)
  sw    $t6, 0xb0($sp)
  lw    $t8, 0x84($sp)
.L7F0B1E6C:
  lw    $t9, 0xa4($sp)
  lw    $t2, 0x160($sp)
  lw    $s3, ($t8)
  addiu $t1, $t8, 4
  addiu $t0, $t9, 1
  sw    $t0, 0xa4($sp)
  sw    $t1, 0x84($sp)
  beqz  $t2, .L7F0B1E9C
   move  $s0, $zero
  move  $a0, $s3
  jalr  $t2
  move  $a1, $s7
.L7F0B1E9C:
  lh    $v0, 6($s3)
  sra   $t3, $v0, 0xc
  andi  $t4, $t3, 0xf
  blez  $t4, .L7F0B2050
   move  $v0, $t4
.L7F0B1EB0:
  addiu $s5, $s0, 1
  div   $zero, $s5, $v0
  mfhi  $s1
  mfc1  $a2, $f26
  bnez  $v0, .L7F0B1ECC
   nop   
  break 7
.L7F0B1ECC:
  li    $at, -1
  bne   $v0, $at, .L7F0B1EE4
   lui   $at, 0x8000
  bne   $s5, $at, .L7F0B1EE4
   nop   
  break 6
.L7F0B1EE4:
  mfc1  $a3, $f28
  move  $a0, $s3
  jal   sub_GAME_7F0AFD1C
   move  $a1, $s0
  mfc1  $a2, $f26
  mfc1  $a3, $f28
  mov.s $f22, $f0
  move  $a0, $s3
  jal   sub_GAME_7F0B0064
   move  $a1, $s0
  mfc1  $a2, $f26
  mfc1  $a3, $f28
  mov.s $f20, $f0
  move  $a0, $s3
  jal   sub_GAME_7F0B0064
   move  $a1, $s1
  c.lt.s $f22, $f30
  mov.s $f24, $f0
  bc1fl .L7F0B2038
   lh    $v0, 6($s3)
  c.lt.s $f20, $f30
  nop   
  bc1t  .L7F0B1F6C
   nop   
  c.lt.s $f0, $f30
  move  $a0, $s3
  bc1t  .L7F0B1F6C
   nop   
  mfc1  $a2, $f26
  mfc1  $a3, $f28
  jal   sub_GAME_7F0B0198
   move  $a1, $s0
  beql  $v0, $zero, .L7F0B2038
   lh    $v0, 6($s3)
.L7F0B1F6C:
  beqz  $s6, .L7F0B1F90
   move  $a0, $s3
  mfc1  $a2, $f22
  mfc1  $a3, $f20
  move  $a1, $s0
  swc1  $f24, 0x10($sp)
  jalr  $s6
  sw    $s7, 0x14($sp)
  bnez  $v0, .L7F0B1FFC
.L7F0B1F90:
   sll   $t5, $s0, 3
  addu  $t6, $s3, $t5
  lhu   $a0, 0xe($t6)
  lui   $t0, %hi(base_ptr_connection_vals) 
  addiu $v0, $s4, -1
  sra   $t7, $a0, 4
  beqz  $t7, .L7F0B1FFC
   sll   $t9, $a0, 3
  lw    $t0, %lo(base_ptr_connection_vals)($t0)
  move  $a1, $v0
  bltz  $v0, .L7F0B1FE8
   addu  $v1, $t9, $t0
  sll   $t8, $v0, 2
  addiu $t1, $sp, 0xb0
  addu  $v0, $t8, $t1
  lw    $t2, ($v0)
.L7F0B1FD0:
  addiu $v0, $v0, -4
  sltu  $at, $v0, $s2
  beql  $v1, $t2, .L7F0B2038
   lh    $v0, 6($s3)
  beql  $at, $zero, .L7F0B1FD0
   lw    $t2, ($v0)
.L7F0B1FE8:
  sll   $t3, $s4, 2
  addu  $t4, $sp, $t3
  sw    $v1, 0xb0($t4)
  b     .L7F0B2034
   addiu $s4, $s4, 1
.L7F0B1FFC:
  lui   $at, %hi(dword_CODE_bss_8007B9E4)
  sw    $s3, %lo(dword_CODE_bss_8007B9E4)($at)
  lui   $at, %hi(dword_CODE_bss_8007B9E8)
  beqz  $fp, .L7F0B202C
   sw    $s0, %lo(dword_CODE_bss_8007B9E8)($at)
  addiu $a0, $sp, 0xb0
  move  $a1, $s4
  jalr  $fp
  move  $a2, $s7
  li    $at, 1
  beql  $v0, $at, .L7F0B2038
   lh    $v0, 6($s3)
.L7F0B202C:
  b     .L7F0B2088
   li    $v0, 2
.L7F0B2034:
  lh    $v0, 6($s3)
.L7F0B2038:
  move  $s0, $s5
  sra   $t5, $v0, 0xc
  andi  $t6, $t5, 0xf
  slt   $at, $s5, $t6
  bnez  $at, .L7F0B1EB0
   move  $v0, $t6
.L7F0B2050:
  sltiu $at, $s4, 0x29
  bnez  $at, .L7F0B2064
   lw    $t7, 0xa4($sp)
  b     .L7F0B2088
   li    $v0, 5
.L7F0B2064:
  slt   $at, $t7, $s4
  bnezl $at, .L7F0B1E6C
   lw    $t8, 0x84($sp)
  beqz  $fp, .L7F0B2084
   addiu $a0, $sp, 0xb0
  move  $a1, $s4
  jalr  $fp
  move  $a2, $s7
.L7F0B2084:
  li    $v0, -2
.L7F0B2088:
  lw    $ra, 0x74($sp)
  ldc1  $f20, 0x20($sp)
  ldc1  $f22, 0x28($sp)
  ldc1  $f24, 0x30($sp)
  ldc1  $f26, 0x38($sp)
  ldc1  $f28, 0x40($sp)
  ldc1  $f30, 0x48($sp)
  lw    $s0, 0x50($sp)
  lw    $s1, 0x54($sp)
  lw    $s2, 0x58($sp)
  lw    $s3, 0x5c($sp)
  lw    $s4, 0x60($sp)
  lw    $s5, 0x64($sp)
  lw    $s6, 0x68($sp)
  lw    $s7, 0x6c($sp)
  lw    $fp, 0x70($sp)
  jr    $ra
   addiu $sp, $sp, 0x150
");

asm(R"
glabel sub_GAME_7F0B20D0
  addiu $sp, $sp, -0x28
  mtc1  $a1, $f12
  mtc1  $a2, $f14
  sw    $ra, 0x24($sp)
  mfc1  $a1, $f12
  mfc1  $a2, $f14
  sw    $a3, 0x34($sp)
  sw    $zero, 0x10($sp)
  sw    $zero, 0x14($sp)
  sw    $zero, 0x18($sp)
  jal   sub_GAME_7F0B1DDC
   sw    $zero, 0x1c($sp)
  lw    $ra, 0x24($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B2110
  lw    $a2, 4($a1)
  move  $v0, $a1
  move  $v1, $zero
  blezl $a2, .L7F0B215C
   lw    $t8, 8($a1)
  lbu   $a3, 3($a0)
  lw    $t0, ($a1)
  lw    $t6, ($t0)
.L7F0B2130:
  bnel  $a3, $t6, .L7F0B2144
   lw    $t7, 4($v0)
  jr    $ra
   move  $v0, $zero

  lw    $t7, 4($v0)
.L7F0B2144:
  addiu $v1, $v1, 1
  addiu $t0, $t0, 4
  slt   $at, $v1, $t7
  bnezl $at, .L7F0B2130
   lw    $t6, ($t0)
  lw    $t8, 8($a1)
.L7F0B215C:
  move  $v0, $zero
  slt   $at, $a2, $t8
  beqz  $at, .L7F0B218C
   nop   
  lw    $t1, ($a1)
  lbu   $t9, 3($a0)
  sll   $t2, $a2, 2
  addu  $t3, $t1, $t2
  sw    $t9, ($t3)
  lw    $t4, 4($a1)
  addiu $t5, $t4, 1
  sw    $t5, 4($a1)
.L7F0B218C:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B2194
  sw    $a0, ($sp)
  sw    $a1, 4($sp)
  lw    $t6, 0xc($a2)
  li    $v0, 1
  addiu $t7, $t6, 1
  jr    $ra
   sw    $t7, 0xc($a2)
");

asm(R"
glabel sub_GAME_7F0B21B0
  addiu $sp, $sp, -0x40
  mtc1  $a1, $f12
  mtc1  $a2, $f14
  lw    $t6, 0x50($sp)
  lw    $t7, 0x58($sp)
  lui   $t8, %hi(sub_GAME_7F0B2110) # $t8, 0x7f0b
  lui   $t9, %hi(sub_GAME_7F0B2194) # $t9, 0x7f0b
  sw    $ra, 0x24($sp)
  addiu $t9, %lo(sub_GAME_7F0B2194) # addiu $t9, $t9, 0x2194
  addiu $t8, %lo(sub_GAME_7F0B2110) # addiu $t8, $t8, 0x2110
  addiu $t0, $sp, 0x30
  mfc1  $a1, $f12
  mfc1  $a2, $f14
  sw    $a3, 0x4c($sp)
  sw    $zero, 0x34($sp)
  sw    $zero, 0x3c($sp)
  sw    $t0, 0x1c($sp)
  sw    $t8, 0x10($sp)
  sw    $t9, 0x18($sp)
  sw    $zero, 0x14($sp)
  sw    $t6, 0x30($sp)
  jal   sub_GAME_7F0B1DDC
   sw    $t7, 0x38($sp)
  lw    $t1, 0x34($sp)
  lw    $t2, 0x54($sp)
  move  $v1, $v0
  move  $v0, $v1
  sw    $t1, ($t2)
  lw    $t3, 0x3c($sp)
  lw    $ra, 0x24($sp)
  slti  $at, $t3, 2
  bnez  $at, .L7F0B223C
   nop   
  b     .L7F0B223C
   li    $v0, 2
.L7F0B223C:
  jr    $ra
   addiu $sp, $sp, 0x40
");

asm(R"
glabel sub_GAME_7F0B2244
  lh    $v0, 4($a0)
  lui   $t7, %hi(D_80040F30)
  li    $t9, 1
  sra   $t6, $v0, 0xc
  addu  $t7, $t7, $t6
  lbu   $t7, %lo(D_80040F30)($t7)
  andi  $t8, $t7, 2
  beqz  $t8, .L7F0B226C
   nop   
  sw    $t9, ($a1)
.L7F0B226C:
  jr    $ra
   move  $v0, $zero
");

asm(R"
glabel sub_GAME_7F0B2274
  sll   $t6, $a1, 3
  sw    $a2, 8($sp)
  sw    $a3, 0xc($sp)
  addu  $t7, $a0, $t6
  lhu   $v0, 0xe($t7)
  lui   $t0, %hi(base_ptr_connection_vals) 
  sra   $t8, $v0, 4
  beql  $t8, $zero, .L7F0B230C
   move  $v0, $zero
  lw    $t0, %lo(base_ptr_connection_vals)($t0)
  sll   $t9, $v0, 3
  lui   $a1, %hi(D_80040F30)
  addu  $v1, $t9, $t0
  lh    $a0, 4($v1)
  addiu $a1, %lo(D_80040F30) # addiu $a1, $a1, 0xf30
  li    $t5, 1
  sra   $t1, $a0, 0xc
  addu  $t2, $a1, $t1
  lbu   $t3, ($t2)
  sra   $t7, $a0, 0xc
  lw    $t6, 0x14($sp)
  andi  $t4, $t3, 2
  beqz  $t4, .L7F0B22E0
   addu  $t8, $a1, $t7
  sw    $t5, ($t6)
  jr    $ra
   li    $v0, 1

.L7F0B22E0:
  lbu   $t9, ($t8)
  lui   $at, %hi(dword_CODE_bss_8007BA0C)
  li    $t1, 1
  andi  $t0, $t9, 0x40
  beqz  $t0, .L7F0B2308
   move  $v0, $zero
  lw    $t2, 0x14($sp)
  sw    $v1, %lo(dword_CODE_bss_8007BA0C)($at)
  jr    $ra
   sw    $t1, 4($t2)

.L7F0B2308:
  move  $v0, $zero
.L7F0B230C:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B2314
  addiu $sp, $sp, -0x28
  sw    $a0, 0x28($sp)
  mtc1  $a1, $f12
  mtc1  $a2, $f14
  sw    $ra, 0x24($sp)
  sw    $a3, 0x34($sp)
  li    $a0, 16
  lw    $v0, 0x38($sp)
  move  $v1, $zero
.L7F0B2338:
  addiu $v1, $v1, 4
  sw    $zero, ($v0)
  sw    $zero, 4($v0)
  sw    $zero, 8($v0)
  sw    $zero, 0xc($v0)
  bne   $v1, $a0, .L7F0B2338
   addiu $v0, $v0, 0x10
  lw    $t8, 0x38($sp)
  lui   $t6, %hi(sub_GAME_7F0B2244) # $t6, 0x7f0b
  lui   $t7, %hi(sub_GAME_7F0B2274) # $t7, 0x7f0b
  addiu $t7, %lo(sub_GAME_7F0B2274) # addiu $t7, $t7, 0x2274
  addiu $t6, %lo(sub_GAME_7F0B2244) # addiu $t6, $t6, 0x2244
  mfc1  $a1, $f12
  mfc1  $a2, $f14
  sw    $t6, 0x10($sp)
  sw    $t7, 0x14($sp)
  lw    $a0, 0x28($sp)
  lw    $a3, 0x34($sp)
  sw    $zero, 0x18($sp)
  jal   sub_GAME_7F0B1DDC
   sw    $t8, 0x1c($sp)
  lw    $ra, 0x24($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

int *sub_GAME_7F0B239C(int *arg0) { return *arg0; }

int *sub_GAME_7F0B23A4(int *arg0) { return *(arg0 + 1); }

asm(R"
glabel sub_GAME_7F0B23AC
  lh    $t6, 6($a0)
  sll   $t7, $a1, 2
  li    $t8, 8
  subu  $t9, $t8, $t7
  srav  $a1, $t6, $t9
  andi  $t0, $a1, 0xf
  sll   $t1, $t0, 3
  addu  $v0, $a0, $t1
  lh    $t2, 8($v0)
  lui   $at, %hi(D_80040F48)
  lwc1  $f0, %lo(D_80040F48)($at)
  mtc1  $t2, $f4
  nop   
  cvt.s.w $f6, $f4
  mul.s $f8, $f6, $f0
  swc1  $f8, ($a2)
  lh    $t3, 0xa($v0)
  mtc1  $t3, $f10
  nop   
  cvt.s.w $f16, $f10
  mul.s $f18, $f16, $f0
  swc1  $f18, 4($a2)
  lh    $t4, 0xc($v0)
  mtc1  $t4, $f4
  nop   
  cvt.s.w $f6, $f4
  mul.s $f8, $f6, $f0
  jr    $ra
   swc1  $f8, 8($a2)
");

asm(R"
glabel sub_GAME_7F0B2420
  addiu $sp, $sp, -0x48
  lui   $t1, %hi(dword_CODE_bss_8007BA0C) 
  lw    $t1, %lo(dword_CODE_bss_8007BA0C)($t1)
  sw    $ra, 0x3c($sp)
  sw    $fp, 0x38($sp)
  sw    $s7, 0x34($sp)
  sw    $s6, 0x30($sp)
  sw    $s5, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  lh    $t0, 6($t1)
  move  $s0, $a0
  move  $s1, $a1
  sra   $t6, $t0, 0xc
  andi  $t0, $t6, 0xf
  move  $s5, $a2
  blez  $t0, .L7F0B25DC
   move  $a3, $zero
  lui   $a0, %hi(base_ptr_connection_vals)
  lui   $a1, %hi(D_80040F30)
  addiu $a1, %lo(D_80040F30) # addiu $a1, $a1, 0xf30
  lw    $a0, %lo(base_ptr_connection_vals)($a0)
  move  $v1, $t1
.L7F0B2488:
  lhu   $v0, 0xe($v1)
  sll   $t8, $v0, 3
  sra   $t9, $v0, 4
  beqz  $t9, .L7F0B25CC
   addu  $s6, $t8, $a0
  lh    $v0, 4($s6)
  sra   $t2, $v0, 0xc
  addu  $t3, $a1, $t2
  lbu   $t4, ($t3)
  andi  $t5, $t4, 0x40
  beqz  $t5, .L7F0B25CC
   addiu $fp, $a3, 2
  li    $at, 3
  div   $zero, $fp, $at
  sw    $t1, ($s0)
  mfhi  $t6
  sw    $s6, ($s1)
  move  $s7, $zero
  sw    $t1, 0x40($sp)
  move  $fp, $t6
  li    $s4, 12
  li    $s3, 3
  move  $s0, $zero
.L7F0B24E4:
  sra   $s2, $s7, 2
  move  $s1, $s7
.L7F0B24EC:
  addu  $t7, $s2, $s0
  div   $zero, $t7, $s3
  mfhi  $a1
  andi  $t8, $s1, 3
  move  $a0, $s6
  multu $t8, $s4
  bnez  $s3, .L7F0B2510
   nop   
  break 7
.L7F0B2510:
  li    $at, -1
  bne   $s3, $at, .L7F0B2528
   lui   $at, 0x8000
  bne   $t7, $at, .L7F0B2528
   nop   
  break 6
.L7F0B2528:
  mflo  $t9
  addu  $a2, $s5, $t9
  jal   sub_GAME_7F0B23AC
   nop   
  addiu $s0, $s0, 1
  bne   $s0, $s3, .L7F0B24EC
   addiu $s1, $s1, 1
  addiu $t2, $s7, 3
  andi  $t3, $t2, 3
  multu $t3, $s4
  lw    $a0, 0x40($sp)
  move  $a1, $fp
  mflo  $t4
  addu  $a2, $s5, $t4
  jal   sub_GAME_7F0B23AC
   nop   
  addiu $s7, $s7, 1
  beql  $s7, $s4, .L7F0B25E0
   lw    $ra, 0x3c($sp)
  lwc1  $f0, 0x1c($s5)
  lwc1  $f2, 4($s5)
  c.lt.s $f0, $f2
  nop   
  bc1tl .L7F0B24E4
   move  $s0, $zero
  lwc1  $f12, 0x10($s5)
  c.lt.s $f0, $f12
  nop   
  bc1tl .L7F0B24E4
   move  $s0, $zero
  lwc1  $f0, 0x28($s5)
  c.lt.s $f0, $f2
  nop   
  bc1tl .L7F0B24E4
   move  $s0, $zero
  c.lt.s $f0, $f12
  nop   
  bc1tl .L7F0B24E4
   move  $s0, $zero
  b     .L7F0B25E0
   lw    $ra, 0x3c($sp)
.L7F0B25CC:
  addiu $a3, $a3, 1
  slt   $at, $a3, $t0
  bnez  $at, .L7F0B2488
   addiu $v1, $v1, 8
.L7F0B25DC:
  lw    $ra, 0x3c($sp)
.L7F0B25E0:
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
   addiu $sp, $sp, 0x48
");

asm(R"
glabel sub_GAME_7F0B260C
  sll   $t6, $a1, 3
  sw    $a2, 8($sp)
  sw    $a3, 0xc($sp)
  addu  $t7, $a0, $t6
  lh    $t8, 0xa($t7)
  lw    $a2, 0x14($sp)
  mtc1  $t8, $f4
  lwc1  $f0, ($a2)
  cvt.s.w $f6, $f4
  c.lt.s $f0, $f6
  nop   
  bc1fl .L7F0B26B0
   move  $v0, $zero
  lh    $t0, 6($a0)
  addiu $t9, $a1, 1
  sra   $t1, $t0, 0xc
  andi  $t2, $t1, 0xf
  div   $zero, $t9, $t2
  mfhi  $v0
  sll   $t3, $v0, 3
  addu  $t4, $a0, $t3
  lh    $t5, 0xa($t4)
  bnez  $t2, .L7F0B2670
   nop   
  break 7
.L7F0B2670:
  li    $at, -1
  bne   $t2, $at, .L7F0B2688
   lui   $at, 0x8000
  bne   $t9, $at, .L7F0B2688
   nop   
  break 6
.L7F0B2688:
  mtc1  $t5, $f8
  nop   
  cvt.s.w $f10, $f8
  c.lt.s $f0, $f10
  nop   
  bc1fl .L7F0B26B0
   move  $v0, $zero
  jr    $ra
   li    $v0, 1

  move  $v0, $zero
.L7F0B26B0:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B26B8
  addiu $sp, $sp, -0x30
  lui   $at, %hi(D_80040F44)
  lwc1  $f6, %lo(D_80040F44)($at)
  lwc1  $f4, 0x40($sp)
  mtc1  $a1, $f12
  mtc1  $a2, $f14
  mul.s $f8, $f4, $f6
  lui   $t6, %hi(sub_GAME_7F0B260C) # $t6, 0x7f0b
  sw    $ra, 0x24($sp)
  addiu $t6, %lo(sub_GAME_7F0B260C) # addiu $t6, $t6, 0x260c
  addiu $t7, $sp, 0x2c
  mfc1  $a1, $f12
  mfc1  $a2, $f14
  sw    $a3, 0x3c($sp)
  swc1  $f8, 0x2c($sp)
  sw    $t7, 0x1c($sp)
  sw    $t6, 0x14($sp)
  sw    $zero, 0x10($sp)
  jal   sub_GAME_7F0B1DDC
   sw    $zero, 0x18($sp)
  lw    $ra, 0x24($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B2718
  addiu $sp, $sp, -0x60
  sw    $ra, 0x3c($sp)
  sw    $s5, 0x2c($sp)
  sw    $s4, 0x28($sp)
  move  $s4, $a0
  move  $s5, $a1
  sw    $fp, 0x38($sp)
  sw    $s7, 0x34($sp)
  sw    $s6, 0x30($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  jalr  $a1
  sw    $s0, 0x18($sp)
  beqz  $v0, .L7F0B2760
   lui   $at, %hi(dword_CODE_bss_8007BA10)
  b     .L7F0B2880
   move  $v0, $s4
.L7F0B2760:
  li    $t6, 1
  lui   $s7, %hi(dword_CODE_bss_8007BA10) 
  lui   $s6, %hi(base_ptr_connection_vals)
  sw    $s4, %lo(dword_CODE_bss_8007BA10)($at)
  li    $s1, 1
  addiu $s6, %lo(base_ptr_connection_vals) # addiu $s6, $s6, 0xf58
  addiu $s7, %lo(dword_CODE_bss_8007BA10) # addiu $s7, $s7, -0x45f0
  sw    $t6, 0x58($sp)
  move  $fp, $zero
.L7F0B2784:
  blez  $s1, .L7F0B2864
   lui   $t7, %hi(dword_CODE_bss_8007BA10) 
  addiu $t7, %lo(dword_CODE_bss_8007BA10) # addiu $t7, $t7, -0x45f0
  sw    $t7, 0x44($sp)
.L7F0B2794:
  lw    $t8, 0x44($sp)
  move  $s2, $zero
  lw    $s4, ($t8)
  lh    $a0, 6($s4)
  move  $s3, $s4
  sra   $t9, $a0, 0xc
  andi  $a0, $t9, 0xf
  blezl $a0, .L7F0B284C
   lw    $t9, 0x44($sp)
.L7F0B27B8:
  lhu   $v0, 0xe($s3)
  lw    $t2, ($s6)
  sll   $t1, $v0, 3
  sra   $t3, $v0, 4
  beqz  $t3, .L7F0B2838
   addu  $s0, $t1, $t2
  blez  $s1, .L7F0B27F8
   move  $v0, $zero
  lui   $v1, %hi(dword_CODE_bss_8007BA10)
  addiu $v1, %lo(dword_CODE_bss_8007BA10) # addiu $v1, $v1, -0x45f0
.L7F0B27E0:
  lw    $t4, ($v1)
  addiu $v0, $v0, 1
  beql  $s0, $t4, .L7F0B283C
   addiu $s2, $s2, 1
  bne   $v0, $s1, .L7F0B27E0
   addiu $v1, $v1, 4
.L7F0B27F8:
  jalr  $s5
  move  $a0, $s0
  beqz  $v0, .L7F0B2810
   sll   $t5, $s1, 2
  b     .L7F0B2880
   move  $v0, $s0
.L7F0B2810:
  addiu $s1, $s1, 1
  addu  $t6, $s7, $t5
  sltiu $at, $s1, 0x15f
  bnez  $at, .L7F0B282C
   sw    $s0, ($t6)
  b     .L7F0B2880
   move  $v0, $zero
.L7F0B282C:
  lh    $a0, 6($s4)
  sra   $t7, $a0, 0xc
  andi  $a0, $t7, 0xf
.L7F0B2838:
  addiu $s2, $s2, 1
.L7F0B283C:
  slt   $at, $s2, $a0
  bnez  $at, .L7F0B27B8
   addiu $s3, $s3, 8
  lw    $t9, 0x44($sp)
.L7F0B284C:
  lw    $t1, 0x58($sp)
  addiu $fp, $fp, 1
  addiu $t0, $t9, 4
  slt   $at, $fp, $t1
  bnez  $at, .L7F0B2794
   sw    $t0, 0x44($sp)
.L7F0B2864:
  lw    $t2, 0x58($sp)
  move  $fp, $zero
  beql  $s1, $t2, .L7F0B2880
   move  $v0, $zero
  b     .L7F0B2784
   sw    $s1, 0x58($sp)
  move  $v0, $zero
.L7F0B2880:
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
glabel sub_GAME_7F0B28B0
  lui   $t6, %hi(dword_CODE_bss_8007B9E4) 
  lw    $t6, %lo(dword_CODE_bss_8007B9E4)($t6)
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  move  $a2, $a0
  move  $a3, $a1
  beqz  $t6, .L7F0B28E8
   sw    $t6, 0x1c($sp)
  lui   $a1, %hi(dword_CODE_bss_8007B9E8)
  lw    $a1, %lo(dword_CODE_bss_8007B9E8)($a1)
  jal   sub_GAME_7F0B1CF8
   move  $a0, $t6
  b     .L7F0B2940
   li    $v0, 1
.L7F0B28E8:
  lui   $t7, %hi(D_800413BC) 
  lw    $t7, %lo(D_800413BC)($t7)
  lui   $v1, %hi(flt_CODE_bss_8007B9F0)
  addiu $v1, %lo(flt_CODE_bss_8007B9F0) # addiu $v1, $v1, -0x4610
  beql  $t7, $zero, .L7F0B2940
   move  $v0, $zero
  mtc1  $zero, $f0
  lwc1  $f4, ($v1)
  lui   $a0, %hi(flt_CODE_bss_8007B9F8)
  swc1  $f0, 4($a2)
  swc1  $f4, ($a2)
  lwc1  $f6, 4($v1)
  addiu $a0, %lo(flt_CODE_bss_8007B9F8) # addiu $a0, $a0, -0x4608
  li    $v0, 1
  swc1  $f6, 8($a2)
  lwc1  $f8, ($a0)
  swc1  $f0, 4($a3)
  swc1  $f8, ($a3)
  lwc1  $f10, 4($a0)
  b     .L7F0B2940
   swc1  $f10, 8($a3)
  move  $v0, $zero
.L7F0B2940:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

void sub_GAME_7F0B2950(float arg0) {
  D_80040F44 = arg0;
  D_80040F48 = 1.0f / arg0;
}

asm(R"
glabel sub_GAME_7F0B2970
  lui   $at, %hi(D_80040F44)
  mtc1  $a1, $f14
  lwc1  $f0, %lo(D_80040F44)($at)
  addiu $sp, $sp, -0x90
  sw    $a2, 0x98($sp)
  mul.s $f14, $f14, $f0
  lwc1  $f4, 0x98($sp)
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  mul.s $f6, $f4, $f0
  lh    $v0, 6($a0)
  sra   $a1, $v0, 8
  sra   $a2, $v0, 4
  andi  $t6, $a1, 0xf
  andi  $t7, $a2, 0xf
  swc1  $f6, 0x98($sp)
  sll   $t8, $t7, 3
  sll   $t9, $t6, 3
  addu  $s0, $a0, $t9
  addu  $v1, $a0, $t8
  lh    $t1, 8($v1)
  lh    $t2, 8($s0)
  andi  $a3, $v0, 0xf
  subu  $t3, $t1, $t2
  mtc1  $t3, $f8
  sll   $t1, $a3, 3
  addu  $t0, $a0, $t1
  cvt.s.w $f10, $f8
  swc1  $f10, 0x84($sp)
  lh    $t5, 0xa($s0)
  lh    $t4, 0xa($v1)
  subu  $t6, $t4, $t5
  mtc1  $t6, $f16
  nop   
  cvt.s.w $f18, $f16
  swc1  $f18, 0x88($sp)
  lh    $t8, 0xc($s0)
  lh    $t7, 0xc($v1)
  subu  $t9, $t7, $t8
  mtc1  $t9, $f4
  nop   
  cvt.s.w $f6, $f4
  swc1  $f6, 0x8c($sp)
  lh    $t3, 8($s0)
  lh    $t2, 8($t0)
  subu  $t4, $t2, $t3
  mtc1  $t4, $f8
  nop   
  cvt.s.w $f10, $f8
  swc1  $f10, 0x78($sp)
  lh    $t6, 0xa($s0)
  lh    $t5, 0xa($t0)
  subu  $t7, $t5, $t6
  mtc1  $t7, $f16
  nop   
  cvt.s.w $f4, $f16
  swc1  $f4, 0x7c($sp)
  lh    $t9, 0xc($s0)
  lh    $t8, 0xc($t0)
  swc1  $f14, 0x94($sp)
  subu  $t1, $t8, $t9
  mtc1  $t1, $f8
  nop   
  cvt.s.w $f10, $f8
  mul.s $f16, $f18, $f10
  swc1  $f10, 0x80($sp)
  mul.s $f8, $f4, $f6
  jal   __f_to_ll
   sub.s $f12, $f16, $f8
  lwc1  $f18, 0x8c($sp)
  lwc1  $f10, 0x78($sp)
  lwc1  $f6, 0x80($sp)
  lwc1  $f16, 0x84($sp)
  mul.s $f4, $f18, $f10
  sw    $v0, 0x60($sp)
  sw    $v1, 0x64($sp)
  mul.s $f8, $f6, $f16
  jal   __f_to_ll
   sub.s $f12, $f4, $f8
  lwc1  $f18, 0x84($sp)
  lwc1  $f10, 0x7c($sp)
  lwc1  $f16, 0x78($sp)
  lwc1  $f4, 0x88($sp)
  mul.s $f6, $f18, $f10
  sw    $v0, 0x68($sp)
  sw    $v1, 0x6c($sp)
  mul.s $f8, $f16, $f4
  jal   __f_to_ll
   sub.s $f12, $f6, $f8
  sw    $v0, 0x70($sp)
  sw    $v1, 0x74($sp)
  lh    $a3, 0xa($s0)
  lw    $a0, 0x68($sp)
  lw    $a1, 0x6c($sp)
  jal   __ll_mul
   sra   $a2, $a3, 0x1f
  sw    $v0, 0x38($sp)
  sw    $v1, 0x3c($sp)
  lh    $a3, 8($s0)
  lw    $a0, 0x60($sp)
  lw    $a1, 0x64($sp)
  jal   __ll_mul
   sra   $a2, $a3, 0x1f
  sw    $v0, 0x40($sp)
  sw    $v1, 0x44($sp)
  lh    $a3, 0xc($s0)
  lw    $a0, 0x70($sp)
  lw    $a1, 0x74($sp)
  jal   __ll_mul
   sra   $a2, $a3, 0x1f
  lw    $t7, 0x44($sp)
  lw    $t6, 0x40($sp)
  lw    $t3, 0x3c($sp)
  addu  $t9, $v1, $t7
  sltu  $at, $t9, $t7
  addu  $t8, $at, $v0
  lw    $t2, 0x38($sp)
  addu  $t8, $t8, $t6
  addu  $t5, $t9, $t3
  lw    $t6, 0x68($sp)
  sltu  $at, $t5, $t3
  addu  $t4, $at, $t8
  addu  $t4, $t4, $t2
  sw    $t4, 0x58($sp)
  sw    $t5, 0x5c($sp)
  bnez  $t6, .L7F0B2B98
   lw    $t7, 0x6c($sp)
  bnezl $t7, .L7F0B2B9C
   lw    $a0, 0x70($sp)
  lh    $t1, 0xa($s0)
  lui   $at, %hi(D_80040F48)
  lwc1  $f16, %lo(D_80040F48)($at)
  mtc1  $t1, $f18
  nop   
  cvt.s.w $f10, $f18
  mul.s $f0, $f10, $f16
  b     .L7F0B2C1C
   lw    $ra, 0x1c($sp)
.L7F0B2B98:
  lw    $a0, 0x70($sp)
.L7F0B2B9C:
  jal   __ll_to_d
   lw    $a1, 0x74($sp)
  sdc1  $f0, 0x20($sp)
  lw    $a0, 0x60($sp)
  jal   __ll_to_d
   lw    $a1, 0x64($sp)
  lw    $a0, 0x58($sp)
  lw    $a1, 0x5c($sp)
  jal   __ll_to_d
   sdc1  $f0, 0x28($sp)
  lw    $a0, 0x68($sp)
  lw    $a1, 0x6c($sp)
  jal   __ll_to_d
   sdc1  $f0, 0x30($sp)
  lwc1  $f4, 0x98($sp)
  ldc1  $f8, 0x20($sp)
  lwc1  $f10, 0x94($sp)
  cvt.d.s $f6, $f4
  ldc1  $f2, 0x28($sp)
  mul.d $f18, $f6, $f8
  cvt.d.s $f16, $f10
  ldc1  $f12, 0x30($sp)
  lui   $at, %hi(D_80040F48)
  mul.d $f4, $f16, $f2
  sub.d $f6, $f12, $f4
  lwc1  $f4, %lo(D_80040F48)($at)
  sub.d $f8, $f6, $f18
  div.d $f10, $f8, $f0
  cvt.s.d $f16, $f10
  mul.s $f0, $f16, $f4
  nop   
  lw    $ra, 0x1c($sp)
.L7F0B2C1C:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x90
  jr    $ra
   nop   
");

asm(R"
glabel copy_tile_RGB_as_24bit
  sw    $a1, 4($sp)
  sw    $a2, 8($sp)
  lh    $v1, 4($a0)
  sra   $v0, $v1, 8
  andi  $t7, $v0, 0xf
  sra   $a1, $v1, 4
  andi  $t9, $a1, 0xf
  sll   $t4, $t7, 4
  or    $t5, $t4, $t7
  sll   $t6, $t9, 4
  andi  $t3, $v1, 0xf
  or    $t7, $t6, $t9
  sll   $t8, $t3, 4
  or    $t9, $t8, $t3
  sb    $t5, ($a3)
  sb    $t7, 1($a3)
  jr    $ra
  sb    $t9, 2($a3)
");

asm(R"
glabel sub_GAME_7F0B2C74
  lh    $t6, 6($a0)
  lui   $v0, %hi(D_80040F48)
  addiu $v0, %lo(D_80040F48) # addiu $v0, $v0, 0xf48
  sra   $t7, $t6, 8
  andi  $t8, $t7, 0xf
  sll   $t9, $t8, 3
  addu  $t0, $a0, $t9
  lh    $t1, 0xa($t0)
  mtc1  $t1, $f4
  nop   
  cvt.s.w $f2, $f4
  c.lt.s $f2, $f2
  mov.s $f0, $f2
  mov.s $f12, $f2
  mov.s $f14, $f2
  bc1f  .L7F0B2CBC
   mov.s $f16, $f2
  mov.s $f16, $f2
.L7F0B2CBC:
  c.lt.s $f14, $f16
  nop   
  bc1fl .L7F0B2CD4
   c.lt.s $f0, $f12
  mov.s $f16, $f14
  c.lt.s $f0, $f12
.L7F0B2CD4:
  mov.s $f2, $f0
  bc1fl .L7F0B2CE8
   c.lt.s $f2, $f14
  mov.s $f2, $f12
  c.lt.s $f2, $f14
.L7F0B2CE8:
  nop   
  bc1fl .L7F0B2CFC
   lwc1  $f6, ($v0)
  mov.s $f2, $f14
  lwc1  $f6, ($v0)
.L7F0B2CFC:
  mul.s $f8, $f16, $f6
  swc1  $f8, ($a1)
  lwc1  $f10, ($v0)
  mul.s $f18, $f2, $f10
  jr    $ra
   swc1  $f18, 4($a1)
");

asm(R"
glabel sub_GAME_7F0B2D14
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F0B2C74
   addiu $a1, $sp, 0x18
  lw    $ra, 0x14($sp)
  lwc1  $f0, 0x18($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

void sub_GAME_7F0B2D38(int arg0, int arg1, int arg2) {}

int sub_GAME_7F0B2D48(int arg0) { return arg0; }

asm(R"
glabel stanConvertNameStringToS32
  addiu $sp, $sp, -0x40
  sw    $ra, 0x14($sp)
  sw    $a1, 0x44($sp)
  sw    $a2, 0x48($sp)
  lbu   $v1, ($a0)
  addiu $v1, $v1, -0x70
  bltz  $v1, .L7F0B2E30
   slti  $at, $v1, 2
  beqz  $at, .L7F0B2E30
   addiu $a0, $a0, 1
  sw    $v1, 0x30($sp)
  addiu $a1, $sp, 0x38
  li    $a2, 10
  jal   strtol
   sw    $a0, 0x1c($sp)
  lw    $a0, 0x1c($sp)
  lw    $t6, 0x38($sp)
  li    $at, 32768
  sltu  $at, $v0, $at
  beql  $t6, $a0, .L7F0B2E34
   lw    $t9, 0x44($sp)
  beqz  $at, .L7F0B2E30
   lw    $t7, 0x38($sp)
  lbu   $v1, ($t7)
  addiu $v1, $v1, -0x61
  bltz  $v1, .L7F0B2E30
   slti  $at, $v1, 0x1a
  beqz  $at, .L7F0B2E30
   lw    $t8, 0x38($sp)
  lbu   $a0, 1($t8)
  move  $a1, $v1
  li    $at, 48
  beqz  $a0, .L7F0B2DE4
   move  $v1, $a0
  beq   $v1, $at, .L7F0B2DE4
   nop   
  addiu $v1, $v1, -0x30
.L7F0B2DE4:
  bltz  $v1, .L7F0B2E30
   slti  $at, $v1, 8
  beql  $at, $zero, .L7F0B2E34
   lw    $t9, 0x44($sp)
  beqz  $a0, .L7F0B2E08
   lw    $t9, 0x38($sp)
  lbu   $t0, 2($t9)
  bnezl $t0, .L7F0B2E34
   lw    $t9, 0x44($sp)
.L7F0B2E08:
  lw    $t1, 0x30($sp)
  lw    $t4, 0x44($sp)
  sll   $t5, $a1, 3
  sll   $t2, $t1, 0xf
  or    $t3, $t2, $v0
  sh    $t3, ($t4)
  lw    $t7, 0x48($sp)
  or    $t6, $t5, $v1
  b     .L7F0B2E48
   sb    $t6, ($t7)
.L7F0B2E30:
  lw    $t9, 0x44($sp)
.L7F0B2E34:
  li    $t8, 65535
  li    $t0, 255
  sh    $t8, ($t9)
  lw    $t1, 0x48($sp)
  sb    $t0, ($t1)
.L7F0B2E48:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x40
  jr    $ra
   nop   
");

asm(R"
glabel stanMatchTileName
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  lbu   $t6, ($a0)
  addiu $a1, $sp, 0x22
  bnez  $t6, .L7F0B2E78
   nop   
  b     .L7F0B2EF0
   move  $v0, $zero
.L7F0B2E78:
  jal   stanConvertNameStringToS32
   addiu $a2, $sp, 0x21
  lui   $t7, %hi(clippingfile) 
  lw    $t7, %lo(clippingfile)($t7)
  lui   $a1, %hi(list_of_tilesizes)
  addiu $a1, %lo(list_of_tilesizes) # addiu $a1, $a1, 0xf4c
  lw    $v1, 4($t7)
  lhu   $a0, 0x22($sp)
  lw    $t8, ($v1)
  beql  $t8, $zero, .L7F0B2EF0
   move  $v0, $zero
  lhu   $t9, ($v1)
.L7F0B2EA8:
  lbu   $t0, 0x21($sp)
  bnel  $a0, $t9, .L7F0B2ECC
   lh    $v0, 6($v1)
  lbu   $t1, 2($v1)
  bnel  $t0, $t1, .L7F0B2ECC
   lh    $v0, 6($v1)
  b     .L7F0B2EF0
   move  $v0, $v1
  lh    $v0, 6($v1)
.L7F0B2ECC:
  sra   $t2, $v0, 0xc
  andi  $t3, $t2, 0xf
  addu  $t4, $a1, $t3
  lbu   $t5, ($t4)
  addu  $v1, $t5, $v1
  lw    $t6, ($v1)
  bnezl $t6, .L7F0B2EA8
   lhu   $t9, ($v1)
  move  $v0, $zero
.L7F0B2EF0:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B2F00
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  jal   stanMatchTileName
   lw    $a0, ($a0)
  lw    $t7, 0x18($sp)
  sw    $v0, ($t7)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel stanDetermineEOF
  lui   $t0, %hi(clippingfile) 
  addiu $t0, %lo(clippingfile) # addiu $t0, $t0, -0x4ee0
  sw    $a0, ($t0)
  lw    $t6, 4($a0)
  subu  $v0, $a2, $a1
  lui   $at, %hi(base_ptr_connection_vals)
  addu  $t7, $t6, $v0
  addiu $t8, $t7, -0x80
  sw    $t8, %lo(base_ptr_connection_vals)($at)
  lw    $t9, 4($a0)
  lui   $at, %hi(ptr_firstroom_0)
  lui   $a2, %hi(list_of_tilesizes)
  addu  $t1, $t9, $v0
  sw    $t1, %lo(ptr_firstroom_0)($at)
  lw    $t2, 4($a0)
  addiu $a3, $a0, 4
  addiu $a2, %lo(list_of_tilesizes) # addiu $a2, $a2, 0xf4c
  beqz  $t2, .L7F0B2F94
   lui   $a1, %hi(D_80040F60)
  lw    $v1, ($a3)
  addu  $t3, $v1, $v0
.L7F0B2F80:
  lw    $v1, 4($a3)
  sw    $t3, ($a3)
  addiu $a3, $a3, 4
  bnezl $v1, .L7F0B2F80
   addu  $t3, $v1, $v0
.L7F0B2F94:
  addiu $v0, $a3, 4
  lw    $t4, ($v0)
  addiu $a1, %lo(D_80040F60) # addiu $a1, $a1, 0xf60
  beqz  $t4, .L7F0B2FD0
   nop   
  sw    $v0, ($a1)
.L7F0B2FAC:
  lh    $v1, 6($v0)
  sra   $t5, $v1, 0xc
  andi  $t6, $t5, 0xf
  addu  $t7, $a2, $t6
  lbu   $t8, ($t7)
  addu  $v0, $t8, $v0
  lw    $t9, ($v0)
  bnezl $t9, .L7F0B2FAC
   sw    $v0, ($a1)
.L7F0B2FD0:
  jr    $ra
   sw    $a0, ($t0)
");

unsigned char sub_GAME_7F0B2FD8(char *arg0) { return *(arg0 + 3); }

asm(R"
glabel sub_GAME_7F0B2FE0
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lbu   $v0, 3($a0)
  jal   sub_GAME_7F0B4F9C
  move  $a0, $v0
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
  nop   
");

void sub_GAME_7F0B3004(void) { sub_GAME_7F0B2D14(); }

int *sub_GAME_7F0B3024(int *ptrdl, int *ptrtile, unsigned int RGBAColor) {
  int *a = ptrtile;
  unsigned int b = RGBAColor;
  return ptrdl;
}

int sub_GAME_7F0B3034(int arg0) { return arg0; }

int sub_GAME_7F0B303C(int arg0) { return arg0; }

asm(R"
glabel sub_GAME_7F0B3044
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  jal   num_microcode_cmds_that_fit
   sw    $zero, 0x1c($sp)
  slti  $at, $v0, 0x1000
  bnez  $at, .L7F0B3070
   nop   
  jal   sub_GAME_7F0BD7A4
   nop   
  slti  $at, $v0, 0x1000
  beqz  $at, .L7F0B30B0
.L7F0B3070:
   lui   $a0, %hi(D_800413D0)
  addiu $a0, %lo(D_800413D0) # addiu $a0, $a0, 0x13d0
  lw    $t6, ($a0)
  lui   $v0, %hi(D_800413C0)
  addiu $v0, %lo(D_800413C0) # addiu $v0, $v0, 0x13c0
  bnez  $t6, .L7F0B30B0
   lui   $at, %hi(D_800413C4)
  mtc1  $zero, $f0
  lui   $t7, %hi(D_800413CC) 
  li    $t8, 1
  swc1  $f0, ($v0)
  lw    $t7, %lo(D_800413CC)($t7)
  swc1  $f0, %lo(D_800413C4)($at)
  lui   $at, %hi(D_800413C8)
  sw    $t7, %lo(D_800413C8)($at)
  sw    $t8, ($a0)
.L7F0B30B0:
  lui   $a0, %hi(D_800413D0)
  addiu $a0, %lo(D_800413D0) # addiu $a0, $a0, 0x13d0
  lw    $t9, ($a0)
  lui   $v0, %hi(D_800413C0)
  lui   $v1, %hi(D_800413CC)
  addiu $v0, %lo(D_800413C0) # addiu $v0, $v0, 0x13c0
  bnez  $t9, .L7F0B3110
   lw    $v1, %lo(D_800413CC)($v1)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f2
  lui   $at, %hi(D_800413C4)
  lwc1  $f6, %lo(D_800413C4)($at)
  lwc1  $f4, ($v0)
  add.s $f8, $f4, $f6
  swc1  $f8, ($v0)
  lwc1  $f0, ($v0)
  c.lt.s $f2, $f0
  nop   
  bc1fl .L7F0B3114
   lw    $ra, 0x14($sp)
  sub.s $f10, $f0, $f2
  li    $t0, 1
  sw    $t0, 0x1c($sp)
  swc1  $f10, ($v0)
.L7F0B3110:
  lw    $ra, 0x14($sp)
.L7F0B3114:
  addiu $t1, $v1, 1
  lui   $at, %hi(D_800413CC)
  lw    $v0, 0x1c($sp)
  sw    $t1, %lo(D_800413CC)($at)
  jr    $ra
   addiu $sp, $sp, 0x20
");

int sub_GAME_7F0B312C(int arg0, int arg1) { return arg0; }

asm(R"
glabel sub_GAME_7F0B3138
  addiu $sp, $sp, -0x30
  mtc1  $a2, $f12
  mtc1  $a3, $f14
  sw    $a0, 0x30($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f16
  lwc1  $f4, 0x44($sp)
  lw    $t6, 0x48($sp)
  lwc1  $f6, 0x4c($sp)
  lwc1  $f8, 0x50($sp)
  mtc1  $zero, $f10
  move  $a0, $a1
  sw    $ra, 0x2c($sp)
  mfc1  $a1, $f12
  mfc1  $a2, $f14
  lw    $a3, 0x40($sp)
  swc1  $f4, 0x10($sp)
  swc1  $f16, 0x24($sp)
  sw    $t6, 0x14($sp)
  swc1  $f6, 0x18($sp)
  swc1  $f8, 0x1c($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f10, 0x20($sp)
  lw    $ra, 0x2c($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B31A4
  addiu $sp, $sp, -0x28
  mtc1  $a2, $f12
  mtc1  $a3, $f14
  sw    $a0, 0x28($sp)
  lw    $t6, 0x3c($sp)
  lwc1  $f4, 0x40($sp)
  lwc1  $f6, 0x44($sp)
  sw    $a1, 0x2c($sp)
  move  $a0, $a1
  sw    $ra, 0x24($sp)
  mfc1  $a1, $f12
  mfc1  $a2, $f14
  lw    $a3, 0x38($sp)
  sw    $t6, 0x10($sp)
  swc1  $f4, 0x14($sp)
  jal   sub_GAME_7F0B18B8
   swc1  $f6, 0x18($sp)
  lw    $ra, 0x24($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");
