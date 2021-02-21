typedef struct {
  unsigned int *thing1, *thing2;
  unsigned short thing3, thing4;
} image_sound;

int dword_CODE_bss_8008D140, dword_CODE_bss_8008D144;
char dword_CODE_bss_8008D148[0x160];
char dword_CODE_bss_8008D2A8[0xA0];
int dword_CODE_bss_8008D348;

unsigned short D_8004E760[] = {0xD0, 0xD1};
unsigned char D_8004E764[] = {0x7, 0x0, 0x0, 0x0};
image_sound isnd_default = {&D_8004E760, &D_8004E764, 0x0, 0x1};

unsigned short D_8004E774[] = {0xD0, 0xD1};
unsigned char D_8004E778[] = {0x1, 0x0, 0x0, 0x0};
image_sound isnd_stone = {&D_8004E774, &D_8004E778, 0x2, 0x1};

unsigned short D_8004E788[] = {0x4B, 0xD9};
unsigned char D_8004E78C[] = {0x1, 0x0, 0x0, 0x0};
image_sound isnd_wood = {&D_8004E788, &D_8004E78C, 0x2, 0x1};

unsigned short D_8004E79C[] = {0x48, 0xF0, 0xEF, 0x00};
unsigned char D_8004E7A4[] = {0x7, 0x0, 0x0, 0x0};
image_sound isnd_metal = {&D_8004E79C, &D_8004E7A4, 0x3, 0x1};

unsigned short D_8004E7B4[] = {0x46, 0x00};
unsigned char D_8004E7B8[] = {0x4, 0x5, 0x6, 0x0};
image_sound isnd_glass = {&D_8004E7B4, &D_8004E7B8, 0x1, 0x3};

unsigned short D_8004E7C8[] = {0x4C, 0x00};
unsigned char D_8004E7CC[] = {0, 0, 0, 0};
image_sound isnd_water = {&D_8004E7C8, &D_8004E7CC, 0x1, 0x0};

unsigned short D_8004E7DC[] = {0x4A, 0x00};
unsigned char D_8004E7E0[] = {0x1, 0x0, 0x0, 0x0};
image_sound isnd_snow = {&D_8004E7DC, &D_8004E7E0, 0x1, 0x1};

unsigned short D_8004E7F0[] = {0xDC, 0xB9};
unsigned char D_8004E7F4[] = {0x2, 0x0, 0x0, 0x0};
image_sound isnd_dirt = {&D_8004E7F0, &D_8004E7F4, 0x2, 0x1};

unsigned short D_8004E804[] = {0xE7, 0xE6, 0xE0, 0x00};
unsigned char D_8004E80C[] = {0x2, 0x0, 0x0, 0x0};
image_sound isnd_mud = {&D_8004E804, &D_8004E80C, 0x3, 0x1};

unsigned short D_8004E81C[] = {0xD4, 0x00};
unsigned char D_8004E820[] = {0x1, 0x0, 0x0, 0x0};
image_sound isnd_tile = {&D_8004E81C, &D_8004E820, 0x1, 0x1};

unsigned short D_8004E830[] = {0x78, 0xDD};
unsigned char D_8004E834[] = {0x1, 0x7, 0x0, 0x0};
image_sound isnd_metalobj = {&D_8004E830, &D_8004E834, 0x2, 0x2};

unsigned short D_8004E844[] = {0x45, 0x00};
unsigned char D_8004E848[] = {0x2, 0x0, 0x0, 0x0};
image_sound isnd_chr = {&D_8004E844, &D_8004E848, 0x1, 0x1};

unsigned short D_8004E858[] = {0x46, 0x00};
unsigned char D_8004E85C[] = {0x11, 0x12, 0x13, 0x0};
image_sound isnd_glass_xlu = {&D_8004E858, &D_8004E85C, 0x1, 0x3};

unsigned int *D_8004E86C[] = {
    &isnd_default,  &isnd_stone, &isnd_wood,      &isnd_metal,    &isnd_glass,
    &isnd_water,    &isnd_snow,  &isnd_dirt,      &isnd_mud,      &isnd_tile,
    &isnd_metalobj, &isnd_chr,   &isnd_glass_xlu, "HIT_DEFAULT",  "HIT_STONE",
    "HIT_WOOD",     "HIT_METAL", "HIT_GLASS",     "HIT_WATER",    "HIT_SNOW",
    "HIT_DIRT",     "HIT_MUD",   "HIT_TILE",      "HIT_METALOBJ", "HIT_CHR",
    "HIT_GLASS_XLU"};

void nullsub_47(void) {}

asm(R"
glabel sub_GAME_7F0CC4C8
  lui   $v1, %hi(dword_CODE_bss_8008D148)
  lui   $a0, %hi(dword_CODE_bss_8008D2A8)
  lui   $v0, %hi(dword_CODE_bss_8008D348)
  addiu $v0, %lo(dword_CODE_bss_8008D348) # addiu $v0, $v0, -0x2cb8
  addiu $a0, %lo(dword_CODE_bss_8008D2A8) # addiu $a0, $a0, -0x2d58
  addiu $v1, %lo(dword_CODE_bss_8008D148) # addiu $v1, $v1, -0x2eb8
.L7F0CC4E0:
  addiu $a0, $a0, 0x50
  sw    $zero, 0x2c($v1)
  sw    $zero, -0x3c($a0)
  sw    $zero, 0x58($v1)
  sw    $zero, -0x28($a0)
  sw    $zero, 0x84($v1)
  sw    $zero, -0x14($a0)
  addiu $v1, $v1, 0xb0
  sw    $zero, -0xb0($v1)
  bne   $a0, $v0, .L7F0CC4E0
   sw    $zero, -0x50($a0)
  li    $t6, -1
  lui   $at, %hi(dword_CODE_bss_8008D140)
  jr    $ra
   sw    $t6, %lo(dword_CODE_bss_8008D140)($at)
");

asm(R"
glabel sub_GAME_7F0CC51C
  move  $v0, $a0
  blez  $a1, .L7F0CC540
   move  $v1, $a2
.L7F0CC528:
  lbu   $t6, ($v0)
  addiu $a1, $a1, -1
  addiu $v1, $v1, 1
  addiu $v0, $v0, 1
  bgtz  $a1, .L7F0CC528
   sb    $t6, -1($v1)
.L7F0CC540:
  jr    $ra
   subu  $v0, $v1, $a2
");

unsigned int sub_GAME_7F0CC548(int arg0) {
  if (arg0 == dword_CODE_bss_8008D140)
    return 0;
  dword_CODE_bss_8008D140 = arg0;
  return 1;
}

asm(R"
glabel sub_GAME_7F0CC574
  sll   $t6, $a0, 2
  subu  $t6, $t6, $a0
  sll   $t6, $t6, 2
  subu  $t6, $t6, $a0
  lui   $t7, %hi(dword_CODE_bss_8008D148) 
  addiu $t7, %lo(dword_CODE_bss_8008D148) # addiu $t7, $t7, -0x2eb8
  sll   $t6, $t6, 2
  addu  $v0, $t6, $t7
  lw    $t8, ($v0)
  move  $v1, $zero
  beql  $t8, $zero, .L7F0CC63C
   lw    $t7, 0x10($sp)
  lw    $t9, 4($v0)
  bnel  $a1, $t9, .L7F0CC63C
   lw    $t7, 0x10($sp)
  lw    $t0, 8($v0)
  bnel  $a2, $t0, .L7F0CC63C
   lw    $t7, 0x10($sp)
  lw    $t1, 0xc($v0)
  lw    $t2, 0x10($sp)
  bnel  $a3, $t1, .L7F0CC63C
   lw    $t7, 0x10($sp)
  lw    $t3, 0x10($v0)
  lw    $t4, 0x14($sp)
  bnel  $t2, $t3, .L7F0CC63C
   lw    $t7, 0x10($sp)
  lw    $t5, 0x14($v0)
  lw    $t6, 0x18($sp)
  bnel  $t4, $t5, .L7F0CC63C
   lw    $t7, 0x10($sp)
  lw    $t7, 0x18($v0)
  lw    $t8, 0x1c($sp)
  bnel  $t6, $t7, .L7F0CC63C
   lw    $t7, 0x10($sp)
  lw    $t9, 0x1c($v0)
  lw    $t0, 0x20($sp)
  bnel  $t8, $t9, .L7F0CC63C
   lw    $t7, 0x10($sp)
  lw    $t1, 0x20($v0)
  lw    $t2, 0x24($sp)
  bnel  $t0, $t1, .L7F0CC63C
   lw    $t7, 0x10($sp)
  lw    $t3, 0x24($v0)
  lw    $t4, 0x28($sp)
  bnel  $t2, $t3, .L7F0CC63C
   lw    $t7, 0x10($sp)
  lw    $t5, 0x28($v0)
  beq   $t4, $t5, .L7F0CC688
   nop   
  lw    $t7, 0x10($sp)
.L7F0CC63C:
  lw    $t8, 0x14($sp)
  lw    $t9, 0x18($sp)
  lw    $t0, 0x1c($sp)
  lw    $t1, 0x20($sp)
  lw    $t2, 0x24($sp)
  lw    $t3, 0x28($sp)
  li    $t6, 1
  li    $v1, 1
  sw    $t6, ($v0)
  sw    $a1, 4($v0)
  sw    $a2, 8($v0)
  sw    $a3, 0xc($v0)
  sw    $t7, 0x10($v0)
  sw    $t8, 0x14($v0)
  sw    $t9, 0x18($v0)
  sw    $t0, 0x1c($v0)
  sw    $t1, 0x20($v0)
  sw    $t2, 0x24($v0)
  sw    $t3, 0x28($v0)
.L7F0CC688:
  jr    $ra
   move  $v0, $v1
");

asm(R"
glabel sub_GAME_7F0CC690
  sll   $t6, $a0, 2
  addu  $t6, $t6, $a0
  lui   $t7, %hi(dword_CODE_bss_8008D2A8) 
  addiu $t7, %lo(dword_CODE_bss_8008D2A8) # addiu $t7, $t7, -0x2d58
  sll   $t6, $t6, 2
  addu  $v0, $t6, $t7
  lw    $t8, ($v0)
  move  $v1, $zero
  li    $t4, 1
  beql  $t8, $zero, .L7F0CC6F4
   lw    $t5, 0x10($sp)
  lw    $t9, 4($v0)
  bnel  $a1, $t9, .L7F0CC6F4
   lw    $t5, 0x10($sp)
  lw    $t0, 8($v0)
  bnel  $a2, $t0, .L7F0CC6F4
   lw    $t5, 0x10($sp)
  lw    $t1, 0xc($v0)
  lw    $t2, 0x10($sp)
  bnel  $a3, $t1, .L7F0CC6F4
   lw    $t5, 0x10($sp)
  lw    $t3, 0x10($v0)
  beq   $t2, $t3, .L7F0CC70C
   nop   
  lw    $t5, 0x10($sp)
.L7F0CC6F4:
  li    $v1, 1
  sw    $t4, ($v0)
  sw    $a1, 4($v0)
  sw    $a2, 8($v0)
  sw    $a3, 0xc($v0)
  sw    $t5, 0x10($v0)
.L7F0CC70C:
  jr    $ra
   move  $v0, $v1
");

asm(R"
glabel sub_GAME_7F0CC714
  bnez  $a1, .L7F0CC724
   lbu   $v1, 8($a0)
  jr    $ra
   move  $v0, $v1

.L7F0CC724:
  lw    $t6, 0xc($a0)
  lui   $v0, %hi(dword_CODE_bss_8008D090)
  sll   $t8, $t6, 2
  bgez  $t8, .L7F0CC794
   nop   
  lw    $v0, %lo(dword_CODE_bss_8008D090)($v0)
  move  $a2, $zero
  blez  $v0, .L7F0CC78C
   nop   
  lw    $v1, ($a0)
  lui   $a3, %hi(word_CODE_bss_8008C730)
  addiu $a3, %lo(word_CODE_bss_8008C730) # addiu $a3, $a3, -0x38d0
  srl   $t9, $v1, 0x14
  move  $v1, $t9
.L7F0CC75C:
  lh    $t0, ($a3)
  bne   $v1, $t0, .L7F0CC77C
   sll   $t1, $a2, 4
  addu  $t2, $t1, $a1
  lui   $v0, %hi(word_CODE_bss_8008C730+1)
  addu  $v0, $v0, $t2
  jr    $ra
   lbu   $v0, %lo(word_CODE_bss_8008C730+1)($v0)

.L7F0CC77C:
  addiu $a2, $a2, 1
  slt   $at, $a2, $v0
  bnez  $at, .L7F0CC75C
   addiu $a3, $a3, 0x10
.L7F0CC78C:
  jr    $ra
   li    $v0, 1

.L7F0CC794:
  blez  $a1, .L7F0CC7F0
   move  $a2, $zero
  andi  $a0, $a1, 3
  beqz  $a0, .L7F0CC7C4
   move  $v0, $a0
.L7F0CC7A8:
  addiu $v1, $v1, 1
  sra   $t3, $v1, 1
  addiu $a2, $a2, 1
  bne   $v0, $a2, .L7F0CC7A8
   move  $v1, $t3
  beql  $a2, $a1, .L7F0CC7F4
   move  $v0, $v1
.L7F0CC7C4:
  addiu $v1, $v1, 1
  sra   $t4, $v1, 1
  addiu $v1, $t4, 1
  sra   $t5, $v1, 1
  addiu $v1, $t5, 1
  sra   $t6, $v1, 1
  addiu $v1, $t6, 1
  sra   $t7, $v1, 1
  addiu $a2, $a2, 4
  bne   $a2, $a1, .L7F0CC7C4
   move  $v1, $t7
.L7F0CC7F0:
  move  $v0, $v1
.L7F0CC7F4:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0CC7FC
  bnez  $a1, .L7F0CC80C
   lbu   $v1, 9($a0)
  jr    $ra
   move  $v0, $v1

.L7F0CC80C:
  lw    $t6, 0xc($a0)
  lui   $v0, %hi(dword_CODE_bss_8008D090)
  sll   $t8, $t6, 2
  bgez  $t8, .L7F0CC87C
   nop   
  lw    $v0, %lo(dword_CODE_bss_8008D090)($v0)
  move  $a2, $zero
  blez  $v0, .L7F0CC874
   nop   
  lw    $v1, ($a0)
  lui   $a3, %hi(word_CODE_bss_8008C730)
  addiu $a3, %lo(word_CODE_bss_8008C730) # addiu $a3, $a3, -0x38d0
  srl   $t9, $v1, 0x14
  move  $v1, $t9
.L7F0CC844:
  lh    $t0, ($a3)
  bne   $v1, $t0, .L7F0CC864
   sll   $t1, $a2, 4
  addu  $t2, $t1, $a1
  lui   $v0, %hi(word_CODE_bss_8008C730+8)
  addu  $v0, $v0, $t2
  jr    $ra
   lbu   $v0, %lo(word_CODE_bss_8008C730+8)($v0)

.L7F0CC864:
  addiu $a2, $a2, 1
  slt   $at, $a2, $v0
  bnez  $at, .L7F0CC844
   addiu $a3, $a3, 0x10
.L7F0CC874:
  jr    $ra
   li    $v0, 1

.L7F0CC87C:
  blez  $a1, .L7F0CC8D8
   move  $a2, $zero
  andi  $a0, $a1, 3
  beqz  $a0, .L7F0CC8AC
   move  $v0, $a0
.L7F0CC890:
  addiu $v1, $v1, 1
  sra   $t3, $v1, 1
  addiu $a2, $a2, 1
  bne   $v0, $a2, .L7F0CC890
   move  $v1, $t3
  beql  $a2, $a1, .L7F0CC8DC
   move  $v0, $v1
.L7F0CC8AC:
  addiu $v1, $v1, 1
  sra   $t4, $v1, 1
  addiu $v1, $t4, 1
  sra   $t5, $v1, 1
  addiu $v1, $t5, 1
  sra   $t6, $v1, 1
  addiu $v1, $t6, 1
  sra   $t7, $v1, 1
  addiu $a2, $a2, 4
  bne   $a2, $a1, .L7F0CC8AC
   move  $v1, $t7
.L7F0CC8D8:
  move  $v0, $v1
.L7F0CC8DC:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0CC8E4
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  lw    $v1, 8($a0)
  andi  $t6, $v1, 3
  jal   sub_GAME_7F0CC714
   sw    $t6, 0x1c($sp)
  lw    $v1, 0x1c($sp)
  li    $at, 3
  move  $a0, $v0
  bne   $v1, $at, .L7F0CC92C
   lw    $ra, 0x14($sp)
  addiu $v0, $v0, 3
  bgez  $v0, .L7F0CC924
   sra   $t7, $v0, 2
  addiu $at, $v0, 3
  sra   $t7, $at, 2
.L7F0CC924:
  b     .L7F0CC98C
   move  $v0, $t7
.L7F0CC92C:
  li    $at, 2
  bne   $v1, $at, .L7F0CC950
   addiu $v0, $a0, 3
  bgez  $v0, .L7F0CC948
   sra   $t8, $v0, 2
  addiu $at, $v0, 3
  sra   $t8, $at, 2
.L7F0CC948:
  b     .L7F0CC98C
   move  $v0, $t8
.L7F0CC950:
  li    $at, 1
  bne   $v1, $at, .L7F0CC978
   addiu $v0, $a0, 0xf
  addiu $v0, $a0, 7
  bgez  $v0, .L7F0CC970
   sra   $t9, $v0, 3
  addiu $at, $v0, 7
  sra   $t9, $at, 3
.L7F0CC970:
  b     .L7F0CC98C
   move  $v0, $t9
.L7F0CC978:
  bgez  $v0, .L7F0CC988
   sra   $t0, $v0, 4
  addiu $at, $v0, 0xf
  sra   $t0, $at, 4
.L7F0CC988:
  move  $v0, $t0
.L7F0CC98C:
  jr    $ra
   addiu $sp, $sp, 0x20
");

int sub_GAME_7F0CC994(int arg0, int arg1) {
  int sp1C = sub_GAME_7F0CC7FC();
  return (sub_GAME_7F0CC8E4(arg0, arg1) * sp1C);
}

asm(R"
glabel sub_GAME_7F0CC9D4
  addiu $sp, $sp, -0x28
  sw    $ra, 0x24($sp)
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  lw    $v1, 8($a0)
  lbu   $v0, 0xb($a0)
  move  $s1, $a2
  andi  $t6, $v1, 3
  srl   $t7, $v0, 5
  move  $s3, $a0
  beqz  $t7, .L7F0CCA14
   move  $v1, $t6
  b     .L7F0CCA18
   move  $s2, $t7
.L7F0CCA14:
  li    $s2, 1
.L7F0CCA18:
  li    $v0, 3
  bne   $v1, $v0, .L7F0CCA2C
   sw    $zero, ($s1)
  b     .L7F0CCA54
   sw    $v0, ($a1)
.L7F0CCA2C:
  li    $v0, 2
  bne   $v1, $v0, .L7F0CCA40
   li    $at, 1
  b     .L7F0CCA54
   sw    $v0, ($a1)
.L7F0CCA40:
  bnel  $v1, $at, .L7F0CCA54
   sw    $v0, ($a1)
  b     .L7F0CCA54
   sw    $v0, ($a1)
  sw    $v0, ($a1)
.L7F0CCA54:
  blez  $s2, .L7F0CCA80
   move  $s0, $zero
.L7F0CCA5C:
  move  $a0, $s3
  jal   sub_GAME_7F0CC994
   move  $a1, $s0
  lw    $t8, ($s1)
  sll   $t9, $v0, 2
  addiu $s0, $s0, 1
  addu  $t0, $t8, $t9
  bne   $s0, $s2, .L7F0CCA5C
   sw    $t0, ($s1)
.L7F0CCA80:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
glabel sub_GAME_7F0CCA9C
  addiu $a0, $a0, -1
  blez  $a0, .L7F0CCAC4
   move  $v1, $zero
  li    $v0, 8
  sra   $t6, $a0, 1
.L7F0CCAB0:
  move  $a0, $t6
  blez  $t6, .L7F0CCAC4
   addiu $v1, $v1, 1
  bnel  $v1, $v0, .L7F0CCAB0
   sra   $t6, $a0, 1
.L7F0CCAC4:
  jr    $ra
   move  $v0, $v1
");

unsigned int sub_GAME_7F0CCACC(int arg0) {
  if (arg0 == 1) {
    return 2;
  }
  if (arg0 == 2) {
    return 1;
  }
  return 0;
}

asm(R"
glabel sub_GAME_7F0CCAFC
  trunc.w.s $f4, $f12
  mfc1  $v0, $f4
  nop   
  mtc1  $v0, $f6
  move  $v1, $v0
  cvt.s.w $f8, $f6
  c.lt.s $f8, $f12
  nop   
  bc1f  .L7F0CCB30
   nop   
  addiu $v1, $v0, 1
  jr    $ra
   move  $v0, $v1

.L7F0CCB30:
  jr    $ra
   move  $v0, $v1
");

asm(R"
glabel sub_GAME_7F0CCB38
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  jal   sub_GAME_7F0CC8E4
   move  $a1, $zero
  lw    $t6, 0x18($sp)
  li    $at, 3
  move  $a0, $v0
  lw    $v1, 8($t6)
  sll   $t8, $v0, 2
  andi  $t7, $v1, 3
  bne   $t7, $at, .L7F0CCB9C
   move  $v1, $t7
  mtc1  $t8, $f6
  li    $at, 0x40000000 # 2.000000
  mtc1  $at, $f4
  cvt.s.w $f8, $f6
  li    $at, 0x45000000 # 2048.000000
  mtc1  $at, $f16
  div.s $f10, $f4, $f8
  mul.s $f12, $f10, $f16
  jal   sub_GAME_7F0CCAFC
   nop   
  b     .L7F0CCC44
   lw    $ra, 0x14($sp)
.L7F0CCB9C:
  li    $at, 2
  bne   $v1, $at, .L7F0CCBD8
   sll   $t9, $a0, 2
  mtc1  $t9, $f6
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f18
  cvt.s.w $f4, $f6
  li    $at, 0x45000000 # 2048.000000
  mtc1  $at, $f10
  div.s $f8, $f18, $f4
  mul.s $f12, $f8, $f10
  jal   sub_GAME_7F0CCAFC
   nop   
  b     .L7F0CCC44
   lw    $ra, 0x14($sp)
.L7F0CCBD8:
  li    $at, 1
  bne   $v1, $at, .L7F0CCC18
   sll   $t1, $a0, 4
  sll   $t0, $a0, 3
  mtc1  $t0, $f6
  li    $at, 0x41000000 # 8.000000
  mtc1  $at, $f16
  cvt.s.w $f18, $f6
  li    $at, 0x45000000 # 2048.000000
  mtc1  $at, $f8
  div.s $f4, $f16, $f18
  mul.s $f12, $f4, $f8
  jal   sub_GAME_7F0CCAFC
   nop   
  b     .L7F0CCC44
   lw    $ra, 0x14($sp)
.L7F0CCC18:
  mtc1  $t1, $f6
  li    $at, 0x41800000 # 16.000000
  mtc1  $at, $f10
  cvt.s.w $f16, $f6
  li    $at, 0x45000000 # 2048.000000
  mtc1  $at, $f4
  div.s $f18, $f10, $f16
  mul.s $f12, $f18, $f4
  jal   sub_GAME_7F0CCAFC
   nop   
  lw    $ra, 0x14($sp)
.L7F0CCC44:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0CCC50
  addiu $sp, $sp, -0x90
  sw    $ra, 0x44($sp)
  sw    $s2, 0x40($sp)
  sw    $s1, 0x3c($sp)
  sw    $s0, 0x38($sp)
  sw    $a2, 0x98($sp)
  sw    $a3, 0x9c($sp)
  lw    $t6, ($a1)
  lui   $t9, %hi(image_entries) 
  move  $s2, $a0
  srl   $t7, $t6, 0x14
  sll   $t8, $t7, 3
  addiu $t9, %lo(image_entries) # addiu $t9, $t9, -0x6d00
  move  $s1, $a1
  addu  $s0, $t8, $t9
  jal   sub_GAME_7F0CCA9C
   lbu   $a0, 8($a1)
  sw    $v0, 0x88($sp)
  jal   sub_GAME_7F0CCA9C
   lbu   $a0, 9($s1)
  sw    $v0, 0x84($sp)
  move  $a0, $s1
  jal   sub_GAME_7F0CC8E4
   move  $a1, $zero
  lw    $t0, 0xa4($sp)
  move  $v1, $s2
  lui   $at, 0xfa00
  andi  $t1, $t0, 0xff
  sll   $t2, $t1, 8
  or    $t3, $t2, $at
  li    $t4, -1
  sw    $t4, 4($v1)
  sw    $t3, ($v1)
  lw    $a0, 0xc($s1)
  addiu $s2, $s2, 8
  sw    $v0, 0x80($sp)
  srl   $t5, $a0, 0x1e
  jal   sub_GAME_7F0CC548
   sll   $a0, $t5, 0xe
  beqz  $v0, .L7F0CCD18
   lw    $a3, 0x80($sp)
  lui   $t7, (0xBA000E02 >> 16) # lui $t7, 0xba00
  ori   $t7, (0xBA000E02 & 0xFFFF) # ori $t7, $t7, 0xe02
  move  $v0, $s2
  sw    $t7, ($v0)
  lw    $t8, 0xc($s1)
  addiu $s2, $s2, 8
  srl   $t9, $t8, 0x1e
  sll   $t0, $t9, 0xe
  sw    $t0, 4($v0)
.L7F0CCD18:
  lbu   $t4, 4($s0)
  lw    $t2, 4($s0)
  lw    $v0, 8($s1)
  andi  $t5, $t4, 0xf
  multu $a3, $t5
  srl   $t3, $t2, 0x1c
  sw    $zero, 0x18($sp)
  sw    $zero, 0x14($sp)
  lw    $t8, 0x88($sp)
  sll   $a1, $v0, 0x1b
  srl   $t1, $a1, 0x1d
  move  $a1, $t1
  lw    $t2, 0x84($sp)
  move  $a0, $zero
  mflo  $t6
  addu  $t7, $t3, $t6
  sw    $t7, 0x10($sp)
  lbu   $t9, 5($s0)
  lw    $t7, 0xa0($sp)
  lw    $t6, 0x9c($sp)
  srl   $t0, $t9, 4
  subu  $t1, $t8, $t0
  sw    $t1, 0x1c($sp)
  lhu   $t4, 4($s0)
  sw    $a3, 0x80($sp)
  andi  $a2, $v0, 3
  andi  $t5, $t4, 0xf
  subu  $t3, $t2, $t5
  sw    $t3, 0x20($sp)
  sw    $t7, 0x28($sp)
  jal   sub_GAME_7F0CC574
   sw    $t6, 0x24($sp)
  beqz  $v0, .L7F0CCE8C
   lw    $a3, 0x80($sp)
  lw    $t2, 8($s1)
  lui   $at, 0xf500
  andi  $t7, $a3, 0x1ff
  sll   $t9, $t2, 0x1b
  andi  $t5, $t2, 3
  lbu   $t2, 4($s0)
  sll   $t3, $t5, 0x13
  srl   $t8, $t9, 0x1d
  andi  $t5, $t2, 0xf
  multu $a3, $t5
  andi  $t0, $t8, 7
  sll   $t1, $t0, 0x15
  lw    $t0, 4($s0)
  or    $t4, $t1, $at
  or    $t6, $t4, $t3
  sll   $t9, $t7, 9
  srl   $t1, $t0, 0x1c
  or    $t8, $t6, $t9
  move  $v1, $s2
  mflo  $t4
  addu  $t3, $t1, $t4
  andi  $t7, $t3, 0x1ff
  or    $t6, $t8, $t7
  sw    $t6, ($v1)
  sw    $v1, 0x54($sp)
  addiu $s2, $s2, 8
  jal   sub_GAME_7F0CCACC
   move  $a0, $zero
  move  $a0, $zero
  jal   sub_GAME_7F0CCACC
   sw    $v0, 0x4c($sp)
  lw    $v1, 0x4c($sp)
  lw    $t4, 0x84($sp)
  lhu   $t8, 4($s0)
  andi  $t9, $v0, 3
  andi  $t2, $v1, 3
  sll   $t5, $t2, 0x12
  sll   $t0, $t9, 8
  or    $t1, $t0, $t5
  subu  $t7, $t4, $t8
  lw    $t0, 0xa0($sp)
  andi  $t6, $t7, 0xf
  lbu   $t7, 5($s0)
  sll   $t9, $t6, 0xe
  lw    $t8, 0x88($sp)
  or    $t2, $t1, $t9
  andi  $t5, $t0, 0xf
  sll   $t3, $t5, 0xa
  or    $t4, $t2, $t3
  srl   $t6, $t7, 4
  lw    $t2, 0x9c($sp)
  subu  $t1, $t8, $t6
  andi  $t9, $t1, 0xf
  lw    $t8, 0x54($sp)
  sll   $t0, $t9, 4
  or    $t5, $t4, $t0
  andi  $t3, $t2, 0xf
  or    $t7, $t5, $t3
  sw    $t7, 4($t8)
.L7F0CCE8C:
  lw    $a0, 0x98($sp)
  li    $v0, 2
  move  $v1, $zero
  bne   $a0, $v0, .L7F0CCEB8
   nop   
  lw    $t6, 0xc($s1)
  sll   $t9, $t6, 2
  bltz  $t9, .L7F0CCEB8
   nop   
  b     .L7F0CCEB8
   move  $v1, $v0
.L7F0CCEB8:
  bne   $a0, $v0, .L7F0CCED8
   move  $a1, $v1
  lw    $t4, 0xc($s1)
  sll   $t2, $t4, 2
  bltzl $t2, .L7F0CCEDC
   move  $v1, $zero
  b     .L7F0CCEDC
   move  $v1, $v0
.L7F0CCED8:
  move  $v1, $zero
.L7F0CCEDC:
  bne   $a0, $v0, .L7F0CCEFC
   move  $a2, $v1
  lw    $t5, 0xc($s1)
  sll   $t7, $t5, 2
  bltzl $t7, .L7F0CCF00
   move  $v1, $zero
  b     .L7F0CCF00
   move  $v1, $v0
.L7F0CCEFC:
  move  $v1, $zero
.L7F0CCF00:
  lbu   $t8, 8($s1)
  addiu $t6, $t8, -1
  sll   $t1, $t6, 2
  bne   $a0, $v0, .L7F0CCF2C
   addu  $a3, $v1, $t1
  lw    $t9, 0xc($s1)
  sll   $t0, $t9, 2
  bltzl $t0, .L7F0CCF30
   move  $v1, $zero
  b     .L7F0CCF30
   li    $v1, 2
.L7F0CCF2C:
  move  $v1, $zero
.L7F0CCF30:
  lbu   $t2, 9($s1)
  sw    $a3, 0x64($sp)
  sw    $a2, 0x68($sp)
  addiu $t5, $t2, -1
  sll   $t3, $t5, 2
  addu  $s0, $v1, $t3
  sw    $s0, 0x10($sp)
  sw    $a1, 0x6c($sp)
  jal   sub_GAME_7F0CC690
   move  $a0, $zero
  lw    $a1, 0x6c($sp)
  lw    $a2, 0x68($sp)
  beqz  $v0, .L7F0CCFA0
   lw    $a3, 0x64($sp)
  andi  $t7, $a1, 0xfff
  sll   $t8, $t7, 0xc
  move  $v0, $s2
  lui   $at, 0xf200
  andi  $t4, $a3, 0xfff
  sll   $t0, $t4, 0xc
  or    $t6, $t8, $at
  andi  $t1, $a2, 0xfff
  andi  $t2, $s0, 0xfff
  or    $t5, $t0, $t2
  or    $t9, $t6, $t1
  sw    $t9, ($v0)
  sw    $t5, 4($v0)
  addiu $s2, $s2, 8
.L7F0CCFA0:
  lw    $ra, 0x44($sp)
  move  $v0, $s2
  lw    $s2, 0x40($sp)
  lw    $s0, 0x38($sp)
  lw    $s1, 0x3c($sp)
  jr    $ra
   addiu $sp, $sp, 0x90
");

asm(R"
glabel sub_GAME_7F0CCFBC
  addiu $sp, $sp, -8
  sw    $s0, 4($sp)
  lbu   $v0, 0xb($a2)
  move  $s0, $a0
  move  $v1, $zero
  srl   $t6, $v0, 5
  beqz  $t6, .L7F0CCFE4
   nop   
  b     .L7F0CCFE4
   addiu $v1, $t6, -1
.L7F0CCFE4:
  beql  $a3, $zero, .L7F0CD050
   lw    $t5, ($a1)
  beqz  $a1, .L7F0CD024
   move  $v0, $s0
  lw    $a0, ($a1)
  li    $at, -14337
  sll   $t8, $v1, 0xb
  and   $t7, $a0, $at
  or    $v0, $t7, $t8
  beql  $v0, $a0, .L7F0CD06C
   move  $v0, $s0
  sw    $v0, ($s0)
  lw    $t9, 4($a1)
  addiu $s0, $s0, 8
  b     .L7F0CD068
   sw    $t9, -4($s0)
.L7F0CD024:
  andi  $t0, $v1, 7
  sll   $t1, $t0, 0xb
  lui   $at, 0xbb00
  or    $t2, $t1, $at
  ori   $t3, $t2, 1
  li    $t4, -1
  sw    $t4, 4($v0)
  sw    $t3, ($v0)
  b     .L7F0CD068
   addiu $s0, $s0, 8
  lw    $t5, ($a1)
.L7F0CD050:
  li    $at, -14337
  sll   $t8, $v1, 0xb
  and   $t6, $t5, $at
  sw    $t6, ($a1)
  or    $t9, $t6, $t8
  sw    $t9, ($a1)
.L7F0CD068:
  move  $v0, $s0
.L7F0CD06C:
  lw    $s0, 4($sp)
  jr    $ra
   addiu $sp, $sp, 8
");

asm(R"
glabel expland_c0_DL_psuedocommands
  addiu $sp, $sp, -0x90
  sw    $s0, 0x34($sp)
  move  $s0, $a0
  sw    $s1, 0x38($sp)
  move  $s1, $a1
  sw    $ra, 0x3c($sp)
  sw    $a2, 0x98($sp)
  move  $a0, $a1
  addiu $a1, $sp, 0x8c
  jal   sub_GAME_7F0CC9D4
   addiu $a2, $sp, 0x88
  lw    $t6, 0xc($s1)
  li    $a0, 7
  move  $v0, $s0
  srl   $t7, $t6, 0x1e
  bnez  $t7, .L7F0CD1F0
   lui   $at, 0xfd00
  lw    $t8, 8($s1)
  lw    $t7, 0x8c($sp)
  lui   $at, 0xfd00
  sll   $t9, $t8, 0x1b
  srl   $t3, $t9, 0x1d
  andi  $t4, $t3, 7
  sll   $t5, $t4, 0x15
  andi  $t8, $t7, 3
  sll   $t9, $t8, 0x13
  or    $t6, $t5, $at
  or    $t3, $t6, $t9
  move  $v0, $s0
  sw    $t3, ($v0)
  lw    $t4, 4($s1)
  addiu $s0, $s0, 8
  move  $a3, $zero
  sw    $t4, 4($v0)
  lw    $a1, 8($s1)
  lw    $t8, 0x98($sp)
  sw    $zero, 0x28($sp)
  sll   $t5, $a1, 0x1b
  srl   $a1, $t5, 0x1d
  sw    $zero, 0x24($sp)
  sw    $zero, 0x20($sp)
  sw    $zero, 0x1c($sp)
  sw    $zero, 0x18($sp)
  sw    $zero, 0x14($sp)
  lw    $a2, 0x8c($sp)
  jal   sub_GAME_7F0CC574
   sw    $t8, 0x10($sp)
  beqz  $v0, .L7F0CD184
   lui   $t2, 0x700
  lw    $t6, 8($s1)
  lw    $t8, 0x8c($sp)
  lui   $at, 0xf500
  sll   $t9, $t6, 0x1b
  srl   $t3, $t9, 0x1d
  andi  $t4, $t3, 7
  sll   $t5, $t4, 0x15
  lw    $t4, 0x98($sp)
  or    $t7, $t5, $at
  andi  $t6, $t8, 3
  sll   $t9, $t6, 0x13
  move  $v0, $s0
  or    $t3, $t7, $t9
  andi  $t5, $t4, 0x1ff
  or    $t8, $t3, $t5
  sw    $t8, ($v0)
  sw    $t2, 4($v0)
  addiu $s0, $s0, 8
.L7F0CD184:  /*LoadTexture(){gDPLoadSync(); gDPLoadBlock();}*/
  move  $v0, $s0
  addiu $s0, $s0, 8
  lui   $t6, 0xe600
  sw    $t6, ($v0)
  sw    $zero, 4($v0)
  move  $a1, $s0
  lui   $t7, 0xf300
  sw    $t7, ($a1)
  lw    $v1, 0x88($sp)
  addiu $s0, $s0, 8
  lui   $t2, 0x700
  addiu $v1, $v1, -1
  slti  $at, $v1, 0x7ff
  beqz  $at, .L7F0CD1C8
   move  $v0, $s0
  b     .L7F0CD1CC
   move  $a0, $v1
.L7F0CD1C8:
  li    $a0, 2047
.L7F0CD1CC:
  andi  $t9, $a0, 0xfff
  sll   $t4, $t9, 0xc
  or    $t3, $t4, $t2
  sw    $t3, 4($a1)
  lui   $t5, 0xe700
  sw    $t5, ($v0)
  sw    $zero, 4($v0)
  b     .L7F0CD418
   addiu $s0, $s0, 8
.L7F0CD1F0:
  lw    $t8, 8($s1)
  lw    $t5, 0x8c($sp)
  addiu $s0, $s0, 8
  sll   $t6, $t8, 0x1b
  srl   $t7, $t6, 0x1d
  andi  $t9, $t7, 7
  sll   $t4, $t9, 0x15
  andi  $t8, $t5, 3
  sll   $t6, $t8, 0x13
  or    $t3, $t4, $at
  or    $t7, $t3, $t6
  sw    $t7, ($v0)
  lw    $t9, 4($s1)
  li    $a0, 7
  move  $a3, $zero
  sw    $t9, 4($v0)
  lw    $a1, 8($s1)
  lw    $t8, 0x98($sp)
  sw    $zero, 0x28($sp)
  sll   $t4, $a1, 0x1b
  srl   $a1, $t4, 0x1d
  sw    $zero, 0x24($sp)
  sw    $zero, 0x20($sp)
  sw    $zero, 0x1c($sp)
  sw    $zero, 0x18($sp)
  sw    $zero, 0x14($sp)
  lw    $a2, 0x8c($sp)
  jal   sub_GAME_7F0CC574
   sw    $t8, 0x10($sp)
  beqz  $v0, .L7F0CD2B8
   move  $a2, $zero
  lw    $t3, 8($s1)
  lw    $t8, 0x8c($sp)
  lui   $at, 0xf500
  sll   $t6, $t3, 0x1b
  srl   $t7, $t6, 0x1d
  andi  $t9, $t7, 7
  sll   $t4, $t9, 0x15
  lw    $t9, 0x98($sp)
  or    $t5, $t4, $at
  andi  $t3, $t8, 3
  sll   $t6, $t3, 0x13
  move  $v0, $s0
  or    $t7, $t5, $t6
  andi  $t4, $t9, 0x1ff
  lui   $t2, 0x700
  or    $t8, $t7, $t4
  sw    $t8, ($v0)
  sw    $t2, 4($v0)
  addiu $s0, $s0, 8
.L7F0CD2B8:
  move  $v0, $s0
  addiu $s0, $s0, 8
  lui   $t3, 0xe600
  sw    $t3, ($v0)
  sw    $zero, 4($v0)
  move  $a1, $s0
  lui   $t5, 0xf300
  sw    $t5, ($a1)
  lw    $v1, 0x88($sp)
  addiu $s0, $s0, 8
  lui   $t2, 0x700
  addiu $v1, $v1, -1
  slti  $at, $v1, 0x7ff
  beqz  $at, .L7F0CD2FC
   move  $v0, $s0
  b     .L7F0CD300
   move  $a0, $v1
.L7F0CD2FC:
  li    $a0, 2047
.L7F0CD300:
  andi  $t6, $a0, 0xfff
  sll   $t9, $t6, 0xc
  or    $t7, $t9, $t2
  sw    $t7, 4($a1)
  lui   $t4, 0xe700
  sw    $t4, ($v0)
  sw    $zero, 4($v0)
  lbu   $t8, 0xa($s1)
  lw    $t0, 0x88($sp)
  li    $t3, 1023
  subu  $v1, $t3, $t8
  sltu  $at, $v1, $t0
  beqz  $at, .L7F0CD340
   addiu $s0, $s0, 8
  b     .L7F0CD344
   move  $t1, $v1
.L7F0CD340:
  move  $t1, $zero
.L7F0CD344:
  subu  $t0, $t0, $t1
  li    $t6, 256
  sw    $t6, 0x10($sp)
  sw    $t0, 0x70($sp)
  li    $a0, 7
  move  $a1, $zero
  li    $a3, 1
  sw    $zero, 0x14($sp)
  sw    $zero, 0x18($sp)
  sw    $zero, 0x1c($sp)
  sw    $zero, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  jal   sub_GAME_7F0CC574
   sw    $t1, 0x6c($sp)
  lw    $t0, 0x70($sp)
  lw    $t1, 0x6c($sp)
  beqz  $v0, .L7F0CD3A8
   lui   $t2, 0x700
  move  $v0, $s0
  lui   $t9, (0xF5000300 >> 16) # lui $t9, 0xf500
  ori   $t9, (0xF5000300 & 0xFFFF) # ori $t9, $t9, 0x300
  sw    $t9, ($v0)
  sw    $t2, 4($v0)
  addiu $s0, $s0, 8
.L7F0CD3A8:
  move  $v0, $s0
  andi  $t3, $t0, 0x3ff
  sll   $t8, $t3, 0xe
  andi  $a0, $t1, 0x3ff
  lui   $at, 0xf000
  addiu $s0, $s0, 8
  lui   $t7, 0xe600
  or    $t5, $t8, $at
  sll   $t4, $a0, 2
  sw    $t7, ($v0)
  sw    $zero, 4($v0)
  or    $t6, $t5, $t4
  move  $v1, $s0
  sw    $t6, ($v1)
  lbu   $t9, 0xa($s1)
  move  $a0, $t4
  addiu $s0, $s0, 8
  addu  $t7, $t9, $t0
  andi  $t4, $t7, 0x3ff
  sll   $t3, $t4, 0xe
  or    $t8, $t3, $t2
  or    $t5, $t8, $a0
  move  $a1, $s0
  sw    $t5, 4($v1)
  lui   $t6, 0xe700
  sw    $t6, ($a1)
  sw    $zero, 4($a1)
  addiu $s0, $s0, 8
.L7F0CD418:
  lw    $ra, 0x3c($sp)
  move  $v0, $s0
  lw    $s0, 0x34($sp)
  lw    $s1, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x90
");

asm(R"
glabel sub_GAME_7F0CD430
  addiu $sp, $sp, -0xb8
  lw    $t6, 0xd0($sp)
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
  sw    $a2, 0xc0($sp)
  sw    $a3, 0xc4($sp)
  sw    $t6, 0xb4($sp)
  lbu   $v0, 0xb($a1)
  lw    $s0, 0xcc($sp)
  move  $s5, $a1
  srl   $t7, $v0, 5
  addu  $t0, $t7, $s0
  slt   $at, $s0, $t0
  beqz  $at, .L7F0CD778
   move  $s6, $a0
  subu  $s2, $s0, $s0
  sw    $s0, 0xac($sp)
  sw    $t0, 0x64($sp)
.L7F0CD498:
  move  $a0, $s5
  jal   sub_GAME_7F0CC714
   move  $a1, $s2
  jal   sub_GAME_7F0CCA9C
   move  $a0, $v0
  move  $s3, $v0
  move  $a0, $s5
  jal   sub_GAME_7F0CC7FC
   move  $a1, $s2
  jal   sub_GAME_7F0CCA9C
   move  $a0, $v0
  move  $s4, $v0
  move  $a0, $s5
  jal   sub_GAME_7F0CC8E4
   move  $a1, $s2
  move  $s0, $v0
  move  $a0, $s5
  jal   sub_GAME_7F0CC994
   move  $a1, $s2
  sw    $v0, 0x80($sp)
  lw    $v1, 0xc($s5)
  sll   $fp, $v1, 2
  srl   $a0, $v1, 0x1e
  srl   $t8, $fp, 0x1f
  sll   $t9, $a0, 0xe
  move  $fp, $t8
  jal   sub_GAME_7F0CC548
   move  $a0, $t9
  beqz  $v0, .L7F0CD534
   move  $a3, $s0
  lui   $t1, (0xBA000E02 >> 16) # lui $t1, 0xba00
  ori   $t1, (0xBA000E02 & 0xFFFF) # ori $t1, $t1, 0xe02
  move  $v0, $s6
  sw    $t1, ($v0)
  lw    $t2, 0xc($s5)
  addiu $s6, $s6, 8
  srl   $t3, $t2, 0x1e
  sll   $t4, $t3, 0xe
  sw    $t4, 4($v0)
.L7F0CD534:
  lw    $v0, 8($s5)
  lw    $t6, 0xb4($sp)
  lw    $t7, 0xc0($sp)
  lw    $t8, 0xc4($sp)
  sll   $a1, $v0, 0x1b
  srl   $t5, $a1, 0x1d
  move  $a1, $t5
  sw    $s2, 0x28($sp)
  sw    $s2, 0x24($sp)
  sw    $s4, 0x20($sp)
  sw    $s3, 0x1c($sp)
  lw    $a0, 0xac($sp)
  andi  $a2, $v0, 3
  sw    $t6, 0x10($sp)
  sw    $t7, 0x14($sp)
  jal   sub_GAME_7F0CC574
   sw    $t8, 0x18($sp)
  beqz  $v0, .L7F0CD630
   move  $s1, $s6
  lw    $t5, 8($s5)
  lui   $at, 0xf500
  addiu $s6, $s6, 8
  sll   $t9, $t5, 0x1b
  srl   $t1, $t9, 0x1d
  andi  $t2, $t1, 7
  sll   $t3, $t2, 0x15
  or    $t4, $t3, $at
  lw    $t3, 0xb4($sp)
  andi  $t6, $t5, 3
  sll   $t7, $t6, 0x13
  andi  $t9, $s0, 0x1ff
  sll   $t1, $t9, 9
  or    $t8, $t4, $t7
  or    $t2, $t8, $t1
  andi  $t5, $t3, 0x1ff
  or    $t6, $t2, $t5
  sw    $t6, ($s1)
  jal   sub_GAME_7F0CCACC
   lw    $a0, 0xc4($sp)
  move  $s0, $v0
  jal   sub_GAME_7F0CCACC
   lw    $a0, 0xc0($sp)
  lw    $t9, 0xac($sp)
  andi  $t4, $v0, 3
  sll   $t7, $t4, 8
  andi  $t8, $t9, 7
  sll   $t1, $t8, 0x18
  or    $t3, $t7, $t1
  andi  $t2, $s0, 3
  sll   $t5, $t2, 0x12
  or    $t6, $t3, $t5
  andi  $t4, $s4, 0xf
  sll   $t9, $t4, 0xe
  andi  $t7, $s2, 0xf
  sll   $t1, $t7, 0xa
  or    $t8, $t6, $t9
  andi  $t3, $s3, 0xf
  sll   $t5, $t3, 4
  or    $t2, $t8, $t1
  or    $t4, $t2, $t5
  andi  $t6, $s2, 0xf
  or    $t9, $t4, $t6
  sw    $t9, 4($s1)
.L7F0CD630:
  lw    $v0, 0xc8($sp)
  li    $v1, 2
  move  $a0, $s5
  bne   $v0, $v1, .L7F0CD654
   move  $a1, $s2
  bnezl $fp, .L7F0CD658
   move  $s0, $zero
  b     .L7F0CD658
   move  $s0, $v1
.L7F0CD654:
  move  $s0, $zero
.L7F0CD658:
  bne   $v0, $v1, .L7F0CD670
   sw    $s0, 0x90($sp)
  bnezl $fp, .L7F0CD674
   move  $s0, $zero
  b     .L7F0CD674
   move  $s0, $v1
.L7F0CD670:
  move  $s0, $zero
.L7F0CD674:
  jal   sub_GAME_7F0CC714
   move  $s7, $s0
  lw    $t7, 0xc8($sp)
  move  $s3, $v0
  li    $at, 2
  bne   $t7, $at, .L7F0CD6A0
   addiu $t8, $s3, -1
  bnezl $fp, .L7F0CD6A4
   move  $s0, $zero
  b     .L7F0CD6A4
   li    $s0, 2
.L7F0CD6A0:
  move  $s0, $zero
.L7F0CD6A4:
  sll   $t1, $t8, 2
  addu  $s4, $s0, $t1
  move  $a0, $s5
  jal   sub_GAME_7F0CC7FC
   move  $a1, $s2
  lw    $t3, 0xc8($sp)
  li    $at, 2
  move  $s3, $v0
  bne   $t3, $at, .L7F0CD6DC
   lw    $a0, 0xac($sp)
  bnezl $fp, .L7F0CD6E0
   move  $s0, $zero
  b     .L7F0CD6E0
   li    $s0, 2
.L7F0CD6DC:
  move  $s0, $zero
.L7F0CD6E0:
  addiu $t2, $s3, -1
  sll   $t5, $t2, 2
  addu  $s1, $s0, $t5
  sw    $s1, 0x10($sp)
  lw    $a1, 0x90($sp)
  move  $a2, $s7
  jal   sub_GAME_7F0CC690
   move  $a3, $s4
  beqz  $v0, .L7F0CD754
   addiu $s2, $s2, 1
  lw    $t4, 0x90($sp)
  lui   $at, 0xf200
  andi  $t8, $s7, 0xfff
  andi  $t6, $t4, 0xfff
  sll   $t9, $t6, 0xc
  or    $t7, $t9, $at
  or    $t1, $t7, $t8
  move  $v0, $s6
  sw    $t1, ($v0)
  lw    $t3, 0xac($sp)
  andi  $t4, $s4, 0xfff
  sll   $t6, $t4, 0xc
  andi  $t2, $t3, 7
  sll   $t5, $t2, 0x18
  or    $t9, $t5, $t6
  andi  $t7, $s1, 0xfff
  or    $t8, $t9, $t7
  sw    $t8, 4($v0)
  addiu $s6, $s6, 8
.L7F0CD754:
  lw    $t4, 0xac($sp)
  lw    $t1, 0xb4($sp)
  lw    $t3, 0x80($sp)
  lw    $t6, 0x64($sp)
  addiu $t5, $t4, 1
  addu  $t2, $t1, $t3
  sw    $t5, 0xac($sp)
  bne   $t5, $t6, .L7F0CD498
   sw    $t2, 0xb4($sp)
.L7F0CD778:
  lw    $ra, 0x5c($sp)
  move  $v0, $s6
  lw    $s6, 0x50($sp)
  lw    $s0, 0x38($sp)
  lw    $s1, 0x3c($sp)
  lw    $s2, 0x40($sp)
  lw    $s3, 0x44($sp)
  lw    $s4, 0x48($sp)
  lw    $s5, 0x4c($sp)
  lw    $s7, 0x54($sp)
  lw    $fp, 0x58($sp)
  jr    $ra
   addiu $sp, $sp, 0xb8
");

asm(R"
glabel sub_GAME_7F0CD7AC
  addiu $sp, $sp, -0x98
  sw    $s0, 0x34($sp)
  move  $s0, $a0
  sw    $ra, 0x3c($sp)
  sw    $s1, 0x38($sp)
  move  $s1, $a1
  jal   sub_GAME_7F0CCB38
   move  $a0, $a1
  sw    $v0, 0x8c($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0x94
  jal   sub_GAME_7F0CC9D4
   addiu $a2, $sp, 0x90
  lw    $t6, 0xc($s1)
  li    $a0, 7
  move  $v0, $s0
  srl   $t7, $t6, 0x1e
  bnez  $t7, .L7F0CD928
   lui   $at, 0xfd00
  lw    $t8, 8($s1)
  lw    $t7, 0x94($sp)
  lui   $at, 0xfd00
  sll   $t9, $t8, 0x1b
  srl   $t3, $t9, 0x1d
  andi  $t4, $t3, 7
  sll   $t5, $t4, 0x15
  andi  $t8, $t7, 3
  sll   $t9, $t8, 0x13
  or    $t6, $t5, $at
  or    $t3, $t6, $t9
  move  $v0, $s0
  sw    $t3, ($v0)
  lw    $t4, 4($s1)
  addiu $s0, $s0, 8
  move  $a3, $zero
  sw    $t4, 4($v0)
  lw    $a1, 8($s1)
  sw    $zero, 0x28($sp)
  sw    $zero, 0x24($sp)
  sll   $t5, $a1, 0x1b
  srl   $a1, $t5, 0x1d
  sw    $zero, 0x20($sp)
  sw    $zero, 0x1c($sp)
  sw    $zero, 0x18($sp)
  sw    $zero, 0x14($sp)
  sw    $zero, 0x10($sp)
  jal   sub_GAME_7F0CC574
   lw    $a2, 0x94($sp)
  beqz  $v0, .L7F0CD8B0
   lui   $t2, 0x700
  lw    $t8, 8($s1)
  lw    $t7, 0x94($sp)
  move  $v0, $s0
  sll   $t6, $t8, 0x1b
  srl   $t9, $t6, 0x1d
  andi  $t3, $t9, 7
  sll   $t4, $t3, 0x15
  lui   $at, 0xf500
  andi  $t8, $t7, 3
  sll   $t6, $t8, 0x13
  or    $t5, $t4, $at
  or    $t9, $t5, $t6
  sw    $t9, ($v0)
  sw    $t2, 4($v0)
  addiu $s0, $s0, 8
.L7F0CD8B0:
  move  $v0, $s0
  addiu $s0, $s0, 8
  lui   $t3, 0xe600
  sw    $t3, ($v0)
  sw    $zero, 4($v0)
  move  $a1, $s0
  lui   $t4, 0xf300
  sw    $t4, ($a1)
  lw    $v1, 0x90($sp)
  lui   $t2, 0x700
  lw    $t6, 0x8c($sp)
  addiu $v1, $v1, -1
  slti  $at, $v1, 0x7ff
  beqz  $at, .L7F0CD8F4
   addiu $s0, $s0, 8
  b     .L7F0CD8F8
   move  $a0, $v1
.L7F0CD8F4:
  li    $a0, 2047
.L7F0CD8F8:
  andi  $t7, $a0, 0xfff
  sll   $t8, $t7, 0xc
  or    $t5, $t8, $t2
  andi  $t9, $t6, 0xfff
  or    $t3, $t5, $t9
  move  $v0, $s0
  sw    $t3, 4($a1)
  lui   $t4, 0xe700
  sw    $t4, ($v0)
  sw    $zero, 4($v0)
  b     .L7F0CDB4C
   addiu $s0, $s0, 8
.L7F0CD928:
  lw    $t7, 8($s1)
  lw    $t4, 0x94($sp)
  addiu $s0, $s0, 8
  sll   $t8, $t7, 0x1b
  srl   $t6, $t8, 0x1d
  andi  $t5, $t6, 7
  sll   $t9, $t5, 0x15
  andi  $t7, $t4, 3
  sll   $t8, $t7, 0x13
  or    $t3, $t9, $at
  or    $t6, $t3, $t8
  sw    $t6, ($v0)
  lw    $t5, 4($s1)
  li    $a0, 7
  move  $a3, $zero
  sw    $t5, 4($v0)
  lw    $a1, 8($s1)
  sw    $zero, 0x28($sp)
  sw    $zero, 0x24($sp)
  sll   $t9, $a1, 0x1b
  srl   $a1, $t9, 0x1d
  sw    $zero, 0x20($sp)
  sw    $zero, 0x1c($sp)
  sw    $zero, 0x18($sp)
  sw    $zero, 0x14($sp)
  sw    $zero, 0x10($sp)
  jal   sub_GAME_7F0CC574
   lw    $a2, 0x94($sp)
  beqz  $v0, .L7F0CD9E0
   move  $a2, $zero
  lw    $t7, 8($s1)
  lw    $t4, 0x94($sp)
  move  $v0, $s0
  sll   $t3, $t7, 0x1b
  srl   $t8, $t3, 0x1d
  andi  $t6, $t8, 7
  sll   $t5, $t6, 0x15
  lui   $at, 0xf500
  andi  $t7, $t4, 3
  sll   $t3, $t7, 0x13
  or    $t9, $t5, $at
  lui   $t2, 0x700
  or    $t8, $t9, $t3
  sw    $t8, ($v0)
  sw    $t2, 4($v0)
  addiu $s0, $s0, 8
.L7F0CD9E0:
  move  $v0, $s0
  addiu $s0, $s0, 8
  lui   $t6, 0xe600
  sw    $t6, ($v0)
  sw    $zero, 4($v0)
  move  $a1, $s0
  lui   $t5, 0xf300
  sw    $t5, ($a1)
  lw    $v1, 0x90($sp)
  lui   $t2, 0x700
  lw    $t3, 0x8c($sp)
  addiu $v1, $v1, -1
  slti  $at, $v1, 0x7ff
  beqz  $at, .L7F0CDA24
   addiu $s0, $s0, 8
  b     .L7F0CDA28
   move  $a0, $v1
.L7F0CDA24:
  li    $a0, 2047
.L7F0CDA28:
  andi  $t4, $a0, 0xfff
  sll   $t7, $t4, 0xc
  or    $t9, $t7, $t2
  andi  $t8, $t3, 0xfff
  or    $t6, $t9, $t8
  sw    $t6, 4($a1)
  move  $v0, $s0
  lui   $t5, 0xe700
  sw    $t5, ($v0)
  sw    $zero, 4($v0)
  lbu   $t4, 0xa($s1)
  lw    $t0, 0x90($sp)
  li    $t7, 1023
  subu  $v1, $t7, $t4
  sltu  $at, $v1, $t0
  beqz  $at, .L7F0CDA74
   addiu $s0, $s0, 8
  b     .L7F0CDA78
   move  $t1, $v1
.L7F0CDA74:
  move  $t1, $zero
.L7F0CDA78:
  subu  $t0, $t0, $t1
  li    $t9, 256
  sw    $t9, 0x10($sp)
  sw    $t0, 0x74($sp)
  li    $a0, 7
  move  $a1, $zero
  li    $a3, 1
  sw    $zero, 0x14($sp)
  sw    $zero, 0x18($sp)
  sw    $zero, 0x1c($sp)
  sw    $zero, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  jal   sub_GAME_7F0CC574
   sw    $t1, 0x70($sp)
  lw    $t0, 0x74($sp)
  lw    $t1, 0x70($sp)
  beqz  $v0, .L7F0CDADC
   lui   $t2, 0x700
  move  $v0, $s0
  lui   $t8, (0xF5000300 >> 16) # lui $t8, 0xf500
  ori   $t8, (0xF5000300 & 0xFFFF) # ori $t8, $t8, 0x300
  sw    $t8, ($v0)
  sw    $t2, 4($v0)
  addiu $s0, $s0, 8
.L7F0CDADC:
  move  $v0, $s0
  andi  $t7, $t0, 0x3ff
  sll   $t4, $t7, 0xe
  andi  $a0, $t1, 0x3ff
  lui   $at, 0xf000
  addiu $s0, $s0, 8
  lui   $t6, 0xe600
  or    $t3, $t4, $at
  sll   $t5, $a0, 2
  sw    $t6, ($v0)
  sw    $zero, 4($v0)
  or    $t9, $t3, $t5
  move  $v1, $s0
  sw    $t9, ($v1)
  lbu   $t8, 0xa($s1)
  move  $a0, $t5
  addiu $s0, $s0, 8
  addu  $t6, $t8, $t0
  andi  $t5, $t6, 0x3ff
  sll   $t7, $t5, 0xe
  or    $t4, $t7, $t2
  or    $t3, $t4, $a0
  move  $a1, $s0
  sw    $t3, 4($v1)
  lui   $t9, 0xe700
  sw    $t9, ($a1)
  sw    $zero, 4($a1)
  addiu $s0, $s0, 8
.L7F0CDB4C:
  lw    $ra, 0x3c($sp)
  move  $v0, $s0
  lw    $s0, 0x34($sp)
  lw    $s1, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x98
");

asm(R"
glabel sub_GAME_7F0CDB64
  addiu $sp, $sp, -0x70
  sw    $s1, 0x38($sp)
  move  $s1, $a0
  sw    $ra, 0x3c($sp)
  sw    $s0, 0x34($sp)
  sw    $a2, 0x78($sp)
  sw    $a3, 0x7c($sp)
  move  $s0, $a1
  jal   sub_GAME_7F0CCA9C
   lbu   $a0, 8($a1)
  sw    $v0, 0x6c($sp)
  jal   sub_GAME_7F0CCA9C
   lbu   $a0, 9($s0)
  sw    $v0, 0x68($sp)
  move  $a0, $s0
  jal   sub_GAME_7F0CC8E4
   move  $a1, $zero
  sw    $v0, 0x64($sp)
  lw    $v1, 0xc($s0)
  sll   $t6, $v1, 2
  srl   $a0, $v1, 0x1e
  srl   $t7, $t6, 0x1f
  sll   $t8, $a0, 0xe
  sw    $t7, 0x50($sp)
  jal   sub_GAME_7F0CC548
   move  $a0, $t8
  beqz  $v0, .L7F0CDBF4
   lui   $t9, (0xBA000E02 >> 16) # lui $t9, 0xba00
  move  $v0, $s1
  ori   $t9, (0xBA000E02 & 0xFFFF) # ori $t9, $t9, 0xe02
  sw    $t9, ($v0)
  lw    $t1, 0xc($s0)
  addiu $s1, $s1, 8
  srl   $t2, $t1, 0x1e
  sll   $t3, $t2, 0xe
  sw    $t3, 4($v0)
.L7F0CDBF4:
  lw    $v0, 8($s0)
  lw    $t5, 0x78($sp)
  lw    $t6, 0x7c($sp)
  lw    $t7, 0x6c($sp)
  lw    $t8, 0x68($sp)
  sll   $a1, $v0, 0x1b
  srl   $t4, $a1, 0x1d
  move  $a1, $t4
  sw    $zero, 0x28($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x10($sp)
  lw    $a0, 0x84($sp)
  lw    $a3, 0x64($sp)
  andi  $a2, $v0, 3
  sw    $t5, 0x14($sp)
  sw    $t6, 0x18($sp)
  sw    $t7, 0x1c($sp)
  jal   sub_GAME_7F0CC574
   sw    $t8, 0x20($sp)
  beqz  $v0, .L7F0CDCF0
   move  $v1, $s1
  lw    $t5, 8($s0)
  lui   $at, 0xf500
  addiu $s1, $s1, 8
  sll   $t9, $t5, 0x1b
  srl   $t1, $t9, 0x1d
  lw    $t9, 0x64($sp)
  andi  $t2, $t1, 7
  sll   $t3, $t2, 0x15
  andi  $t6, $t5, 3
  sll   $t7, $t6, 0x13
  or    $t4, $t3, $at
  andi  $t1, $t9, 0x1ff
  sll   $t2, $t1, 9
  or    $t8, $t4, $t7
  or    $t3, $t8, $t2
  sw    $t3, ($v1)
  sw    $v1, 0x48($sp)
  jal   sub_GAME_7F0CCACC
   lw    $a0, 0x7c($sp)
  lw    $a0, 0x78($sp)
  jal   sub_GAME_7F0CCACC
   sw    $v0, 0x40($sp)
  lw    $t4, 0x84($sp)
  andi  $t5, $v0, 3
  lw    $v1, 0x40($sp)
  sll   $t6, $t5, 8
  andi  $t7, $t4, 7
  lw    $t5, 0x68($sp)
  sll   $t9, $t7, 0x18
  or    $t1, $t6, $t9
  lw    $t9, 0x6c($sp)
  andi  $t8, $v1, 3
  sll   $t2, $t8, 0x12
  andi  $t4, $t5, 0xf
  or    $t3, $t1, $t2
  lw    $t5, 0x48($sp)
  sll   $t7, $t4, 0xe
  andi  $t8, $t9, 0xf
  sll   $t1, $t8, 4
  or    $t6, $t3, $t7
  or    $t2, $t6, $t1
  sw    $t2, 4($t5)
.L7F0CDCF0:
  lw    $v0, 0x80($sp)
  li    $a0, 2
  lw    $t0, 0x50($sp)
  bne   $v0, $a0, .L7F0CDD14
   move  $v1, $zero
  bnezl $t0, .L7F0CDD18
   lw    $t0, 0x50($sp)
  b     .L7F0CDD18
   move  $v1, $a0
.L7F0CDD14:
  lw    $t0, 0x50($sp)
.L7F0CDD18:
  bne   $v0, $a0, .L7F0CDD30
   move  $a1, $v1
  bnezl $t0, .L7F0CDD34
   move  $v1, $zero
  b     .L7F0CDD34
   move  $v1, $a0
.L7F0CDD30:
  move  $v1, $zero
.L7F0CDD34:
  bne   $v0, $a0, .L7F0CDD4C
   move  $a2, $v1
  bnezl $t0, .L7F0CDD50
   move  $v1, $zero
  b     .L7F0CDD50
   move  $v1, $a0
.L7F0CDD4C:
  move  $v1, $zero
.L7F0CDD50:
  lbu   $t4, 8($s0)
  addiu $t3, $t4, -1
  sll   $t7, $t3, 2
  bne   $v0, $a0, .L7F0CDD74
   addu  $a3, $v1, $t7
  bnezl $t0, .L7F0CDD78
   move  $v1, $zero
  b     .L7F0CDD78
   li    $v1, 2
.L7F0CDD74:
  move  $v1, $zero
.L7F0CDD78:
  lbu   $t9, 9($s0)
  sw    $a3, 0x58($sp)
  sw    $a2, 0x5c($sp)
  addiu $t8, $t9, -1
  sll   $t6, $t8, 2
  addu  $t0, $v1, $t6
  sw    $t0, 0x10($sp)
  sw    $t0, 0x54($sp)
  sw    $a1, 0x60($sp)
  jal   sub_GAME_7F0CC690
   lw    $a0, 0x84($sp)
  lw    $a1, 0x60($sp)
  lw    $a2, 0x5c($sp)
  lw    $a3, 0x58($sp)
  beqz  $v0, .L7F0CDE00
   lw    $t0, 0x54($sp)
  andi  $t1, $a1, 0xfff
  sll   $t2, $t1, 0xc
  lui   $at, 0xf200
  or    $t5, $t2, $at
  andi  $t4, $a2, 0xfff
  or    $t3, $t5, $t4
  move  $v0, $s1
  sw    $t3, ($v0)
  lw    $t7, 0x84($sp)
  andi  $t6, $a3, 0xfff
  sll   $t1, $t6, 0xc
  andi  $t9, $t7, 7
  sll   $t8, $t9, 0x18
  or    $t2, $t8, $t1
  andi  $t5, $t0, 0xfff
  or    $t4, $t2, $t5
  sw    $t4, 4($v0)
  addiu $s1, $s1, 8
.L7F0CDE00:
  lw    $ra, 0x3c($sp)
  move  $v0, $s1
  lw    $s1, 0x38($sp)
  lw    $s0, 0x34($sp)
  jr    $ra
   addiu $sp, $sp, 0x70
");

asm(R"
glabel sub_GAME_7F0CDE18
  addiu $sp, $sp, -0x28
  sw    $ra, 0x24($sp)
  sw    $a2, 0x30($sp)
  sw    $a1, 0x2c($sp)
  sw    $a3, 0x34($sp)
  jal   expland_c0_DL_psuedocommands
   move  $a2, $zero
  lw    $t6, 0x38($sp)
  move  $a0, $v0
  lw    $a1, 0x2c($sp)
  lw    $a2, 0x30($sp)
  lw    $a3, 0x34($sp)
  sw    $zero, 0x14($sp)
  sw    $zero, 0x18($sp)
  jal   sub_GAME_7F0CD430
   sw    $t6, 0x10($sp)
  lw    $a1, 0x2c($sp)
  li    $at, 1
  move  $a0, $v0
  lbu   $t7, 0xb($a1)
  lw    $a2, 0x30($sp)
  lw    $a3, 0x34($sp)
  srl   $t8, $t7, 5
  bne   $t8, $at, .L7F0CDE94
   lw    $t9, 0x38($sp)
  li    $t0, 1
  sw    $t0, 0x14($sp)
  sw    $t9, 0x10($sp)
  jal   sub_GAME_7F0CD430
   sw    $zero, 0x18($sp)
  move  $a0, $v0
.L7F0CDE94:
  lw    $ra, 0x24($sp)
  addiu $sp, $sp, 0x28
  move  $v0, $a0
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0CDEA8
  addiu $sp, $sp, -0x38
  sw    $s0, 0x28($sp)
  move  $s0, $a0
  sw    $ra, 0x2c($sp)
  sw    $a1, 0x3c($sp)
  sw    $a2, 0x40($sp)
  sw    $a3, 0x44($sp)
  move  $a1, $zero
  jal   sub_GAME_7F0CC994
   lw    $a0, 0x4c($sp)
  sw    $v0, 0x34($sp)
  move  $a0, $s0
  jal   sub_GAME_7F0CD7AC
   lw    $a1, 0x4c($sp)
  lui   $t6, 0xe800
  sw    $t6, ($v0)
  sw    $zero, 4($v0)
  lw    $a2, 0x34($sp)
  lw    $a1, 0x3c($sp)
  jal   expland_c0_DL_psuedocommands
   addiu $a0, $v0, 8
  lw    $t7, 0x54($sp)
  lw    $t8, 0x58($sp)
  move  $a0, $v0
  lw    $a1, 0x4c($sp)
  lw    $a2, 0x48($sp)
  lw    $a3, 0x50($sp)
  sw    $t7, 0x10($sp)
  jal   sub_GAME_7F0CCC50
   sw    $t8, 0x14($sp)
  lw    $t9, 0x48($sp)
  lw    $t1, 0x34($sp)
  li    $t0, 1
  sw    $t0, 0x14($sp)
  move  $a0, $v0
  lw    $a1, 0x3c($sp)
  lw    $a2, 0x40($sp)
  lw    $a3, 0x44($sp)
  sw    $t9, 0x10($sp)
  jal   sub_GAME_7F0CD430
   sw    $t1, 0x18($sp)
  lw    $t2, 0x3c($sp)
  li    $at, 1
  move  $s0, $v0
  lbu   $t3, 0xb($t2)
  move  $a0, $v0
  lw    $a2, 0x40($sp)
  srl   $t4, $t3, 5
  bne   $t4, $at, .L7F0CDF94
   move  $a1, $t2
  lw    $t5, 0x48($sp)
  lw    $t7, 0x34($sp)
  li    $t6, 2
  sw    $t6, 0x14($sp)
  lw    $a3, 0x44($sp)
  sw    $t5, 0x10($sp)
  jal   sub_GAME_7F0CD430
   sw    $t7, 0x18($sp)
  move  $s0, $v0
.L7F0CDF94:
  lw    $ra, 0x2c($sp)
  move  $v0, $s0
  lw    $s0, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x38
");

asm(R"
glabel sub_GAME_7F0CDFA8
  addiu $sp, $sp, -0x30
  sw    $ra, 0x2c($sp)
  sw    $s0, 0x28($sp)
  sw    $a2, 0x38($sp)
  move  $s0, $a1
  sw    $a3, 0x3c($sp)
  jal   expland_c0_DL_psuedocommands
   move  $a2, $zero
  lw    $t6, 0x48($sp)
  lw    $t7, 0x4c($sp)
  move  $a0, $v0
  move  $a1, $s0
  lw    $a2, 0x40($sp)
  lw    $a3, 0x44($sp)
  sw    $t6, 0x10($sp)
  jal   sub_GAME_7F0CCC50
   sw    $t7, 0x14($sp)
  lw    $t8, 0x40($sp)
  li    $t9, 1
  sw    $t9, 0x14($sp)
  move  $a0, $v0
  move  $a1, $s0
  lw    $a2, 0x38($sp)
  lw    $a3, 0x3c($sp)
  sw    $zero, 0x18($sp)
  jal   sub_GAME_7F0CD430
   sw    $t8, 0x10($sp)
  lbu   $t0, 0xb($s0)
  li    $at, 1
  move  $a0, $v0
  srl   $t1, $t0, 5
  bne   $t1, $at, .L7F0CE050
   move  $a1, $s0
  lw    $t2, 0x40($sp)
  li    $t3, 2
  sw    $t3, 0x14($sp)
  lw    $a2, 0x38($sp)
  lw    $a3, 0x3c($sp)
  sw    $zero, 0x18($sp)
  jal   sub_GAME_7F0CD430
   sw    $t2, 0x10($sp)
  move  $a0, $v0
.L7F0CE050:
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x28($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   move  $v0, $a0
");

asm(R"
glabel sub_GAME_7F0CE064
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $a1, 0x24($sp)
  sw    $a2, 0x28($sp)
  jal   sub_GAME_7F0CD7AC
   sw    $a3, 0x2c($sp)
  lw    $t6, 0x30($sp)
  move  $a0, $v0
  lw    $a1, 0x24($sp)
  lw    $a2, 0x28($sp)
  lw    $a3, 0x2c($sp)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0CDB64
   sw    $t6, 0x10($sp)
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0CE0AC
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $a1, 0x24($sp)
  sw    $a2, 0x28($sp)
  jal   sub_GAME_7F0CD7AC
   sw    $a3, 0x2c($sp)
  lw    $t6, 0x30($sp)
  move  $a0, $v0
  lw    $a1, 0x24($sp)
  lw    $a2, 0x28($sp)
  lw    $a3, 0x2c($sp)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0CDB64
   sw    $t6, 0x10($sp)
  lw    $t7, 0x30($sp)
  li    $t8, 1
  sw    $t8, 0x14($sp)
  move  $a0, $v0
  lw    $a1, 0x24($sp)
  lw    $a2, 0x28($sp)
  lw    $a3, 0x2c($sp)
  jal   sub_GAME_7F0CDB64
   sw    $t7, 0x10($sp)
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel PADDINGHACKING
.word 0
/*D:8005BF20*/
glabel tlb_ptr_DL_type_B1toC0
.word .L7F0CE66C
.word .L7F0CE720
.word .L7F0CE720
.word .L7F0CE720
.word .L7F0CE720
.word .L7F0CE720
.word .L7F0CE720
.word .L7F0CE720
.word .L7F0CE720
.word .L7F0CE6B8
.word .L7F0CE694
.word .L7F0CE720
.word .L7F0CE720
.word .L7F0CE720
.word .L7F0CE66C
.word .L7F0CE1D8

/*D:8005BF60*/
glabel tlb_ptr_C0_image_recall_types
.word .L7F0CE2BC
.word .L7F0CE428
.word .L7F0CE4B8
.word .L7F0CE584
.word .L7F0CE5BC
.text
glabel process_microcode_sort_display_modes_expand_image_calls
  addiu $sp, $sp, -0x98
  sw    $s2, 0x38($sp)
  sw    $ra, 0x54($sp)
  sw    $fp, 0x50($sp)
  sw    $s6, 0x48($sp)
  sw    $s4, 0x40($sp)
  sw    $s1, 0x34($sp)
  sw    $s0, 0x30($sp)
  li    $t6, 1
  sra   $s2, $a1, 3
  move  $s6, $a3
  sw    $s7, 0x4c($sp)
  sw    $s5, 0x44($sp)
  sw    $s3, 0x3c($sp)
  sw    $a2, 0xa0($sp)
  sw    $zero, 0x8c($sp)
  move  $s4, $zero
  move  $fp, $zero
  sw    $t6, 0x5c($sp)
  sw    $zero, 0x58($sp)
  move  $s1, $a0
  move  $s0, $a2
  jal   sub_GAME_7F0CC4C8
   sw    $s2, 0x88($sp)
  bnez  $s6, .L7F0CE188
   li    $s7, 15
  lui   $s6, %hi(ptr_texture_alloc_start)
  addiu $s6, %lo(ptr_texture_alloc_start) # addiu $s6, $s6, -0x38e0
.L7F0CE188:
  blez  $s2, .L7F0CE748
   lui   $s5, %hi(D_800483C8)
  addiu $s5, %lo(D_800483C8) # addiu $s5, $s5, -0x7c38
.L7F0CE194:
  lbu   $v0, ($s1)
  slti  $at, $v0, 0xc1
  bnez  $at, .L7F0CE1B8
   addiu $t7, $v0, -0xb1
  li    $at, 231
  beql  $v0, $at, .L7F0CE650
   lw    $at, ($s1)
  b     .L7F0CE724
   lw    $at, ($s1)
.L7F0CE1B8:
  sltiu $at, $t7, 0x10
  beqz  $at, .L7F0CE720
   sll   $t7, $t7, 2
  lui   $at, %hi(tlb_ptr_DL_type_B1toC0)
  addu  $at, $at, $t7
  lw    $t7, %lo(tlb_ptr_DL_type_B1toC0)($at)
  jr    $t7
   nop   
.L7F0CE1D8:
  bnez  $fp, .L7F0CE1F4
   move  $v0, $s0
  lui   $t8, 0xe700
  sw    $t8, ($v0)
  addiu $s0, $s0, 8
  sw    $zero, 4($v0)
  li    $fp, 1
.L7F0CE1F4:
  lw    $t9, 0x58($sp)
  move  $a0, $s0
  beql  $t9, $zero, .L7F0CE210
   lw    $s3, 4($s1)
  jal   save_ptrDL_enpoint_to_current_init_lightfixture_table
   sw    $zero, 0x58($sp)
  lw    $s3, 4($s1)
.L7F0CE210:
  lui   $t6, %hi(D_800483C4) 
  lw    $t6, %lo(D_800483C4)($t6)
  andi  $t5, $s3, 0xfff
  move  $s3, $t5
  bne   $t5, $t6, .L7F0CE258
   move  $a1, $s6
  lw    $a0, ($s5)
  sll   $t7, $t5, 2
  beqz  $a0, .L7F0CE258
   addu  $t8, $a0, $t7
  lbu   $t9, ($t8)
  sltiu $at, $t9, 0xff
  beqz  $at, .L7F0CE250
   nop   
  b     .L7F0CE25C
   li    $s4, 1
.L7F0CE250:
  b     .L7F0CE25C
   move  $s4, $zero
.L7F0CE258:
  move  $s4, $zero
.L7F0CE25C:
  jal   calls_load_image_to_buffer
   move  $a0, $s3
  move  $a0, $s3
  jal   sub_GAME_7F0CBB0C
   move  $a1, $s6
  beqz  $v0, .L7F0CE644
   move  $s2, $v0
  lw    $a3, 0x5c($sp)
  sw    $zero, 0x5c($sp)
  move  $a0, $s0
  lw    $a1, 0x8c($sp)
  jal   sub_GAME_7F0CCFBC
   move  $a2, $v0
  lw    $v1, ($s1)
  move  $s0, $v0
  andi  $t5, $v1, 7
  sltiu $at, $t5, 5
  beqz  $at, .L7F0CE5F0
   sll   $t5, $t5, 2
  lui   $at, %hi(tlb_ptr_C0_image_recall_types)
  addu  $at, $at, $t5
  lw    $t5, %lo(tlb_ptr_C0_image_recall_types)($at)
  jr    $t5
   nop   
.L7F0CE2BC:
  lw    $t1, 4($s1)
  lw    $a0, ($s5)
  srl   $a2, $v1, 0x16
  srl   $t6, $t1, 0x18
  andi  $t1, $t6, 0xff
  srl   $a3, $v1, 0x14
  srl   $t0, $v1, 0x12
  srl   $t2, $v1, 0xe
  srl   $t3, $v1, 0xa
  andi  $t8, $a2, 3
  andi  $t9, $a3, 3
  andi  $t5, $t0, 3
  andi  $t6, $t2, 0xf
  andi  $t7, $t3, 0xf
  move  $a2, $t8
  move  $a3, $t9
  move  $t0, $t5
  move  $t2, $t6
  beqz  $a0, .L7F0CE374
   move  $t3, $t7
  sll   $v1, $s3, 2
  addu  $v0, $a0, $v1
  lbu   $t8, ($v0)
  li    $at, 255
  bne   $t8, $at, .L7F0CE374
   nop   
  sb    $t1, ($v0)
  lw    $t9, ($s5)
  li    $a0, 15
  subu  $t5, $a0, $t6
  addu  $v0, $t9, $v1
  lbu   $t9, 1($v0)
  move  $t6, $t5
  sll   $t8, $t6, 5
  andi  $t5, $t9, 0xff1f
  or    $t6, $t8, $t5
  sb    $t6, 1($v0)
  lw    $t7, ($s5)
  subu  $t8, $a0, $t3
  sll   $t5, $t8, 2
  addu  $v0, $t7, $v1
  lbu   $t7, 1($v0)
  andi  $t6, $t5, 0x1c
  andi  $t9, $t7, 0xffe3
  or    $t8, $t6, $t9
  sb    $t8, 1($v0)
.L7F0CE374:
  beqz  $s4, .L7F0CE408
   move  $a0, $s0
  lw    $t5, ($s5)
  sll   $t7, $s3, 2
  sw    $t0, 0x10($sp)
  addu  $v0, $t5, $t7
  lbu   $t6, 1($v0)
  move  $a0, $s0
  move  $a1, $s2
  srl   $t9, $t6, 5
  subu  $t8, $s7, $t9
  sw    $t8, 0x14($sp)
  lw    $t5, ($v0)
  sll   $t7, $t5, 0xb
  srl   $t6, $t7, 0x1d
  subu  $t9, $s7, $t6
  sw    $t9, 0x18($sp)
  lbu   $t8, ($v0)
  jal   sub_GAME_7F0CDFA8
   sw    $t8, 0x1c($sp)
  lui   $t5, (0xBA001402 >> 16) # lui $t5, 0xba00
  ori   $t5, (0xBA001402 & 0xFFFF) # ori $t5, $t5, 0x1402
  sw    $t5, ($v0)
  lui   $t6, (0xBA001001 >> 16) # lui $t6, 0xba00
  lui   $t8, (0xBA001102 >> 16) # lui $t8, 0xba00
  lui   $t7, 0x10
  ori   $t6, (0xBA001001 & 0xFFFF) # ori $t6, $t6, 0x1001
  lui   $t9, 1
  ori   $t8, (0xBA001102 & 0xFFFF) # ori $t8, $t8, 0x1102
  lui   $t5, 4
  sw    $t7, 4($v0)
  sw    $t9, 0xc($v0)
  sw    $t6, 8($v0)
  sw    $t5, 0x14($v0)
  sw    $t8, 0x10($v0)
  b     .L7F0CE5F0
   addiu $s0, $v0, 0x18
.L7F0CE408:
  move  $a1, $s2
  sw    $t0, 0x10($sp)
  sw    $t2, 0x14($sp)
  sw    $t3, 0x18($sp)
  jal   sub_GAME_7F0CDFA8
   sw    $t1, 0x1c($sp)
  b     .L7F0CE5F0
   move  $s0, $v0
.L7F0CE428:
  lw    $a0, 4($s1)
  move  $a1, $s6
  srl   $t7, $a0, 0xc
  andi  $a0, $t7, 0xfff
  jal   calls_load_image_to_buffer
   sw    $a0, 0x80($sp)
  lw    $a0, 0x80($sp)
  jal   sub_GAME_7F0CBB0C
   move  $a1, $s6
  beqz  $v0, .L7F0CE5F0
   move  $a0, $s0
  lw    $v1, ($s1)
  lw    $t1, 4($s1)
  sw    $v0, 0x14($sp)
  srl   $a2, $v1, 0x16
  srl   $t9, $t1, 0x18
  andi  $t1, $t9, 0xff
  srl   $a3, $v1, 0x14
  srl   $t0, $v1, 0x12
  srl   $t2, $v1, 0xe
  srl   $t3, $v1, 0xa
  andi  $t5, $a2, 3
  andi  $t7, $a3, 3
  andi  $t6, $t0, 3
  andi  $t9, $t2, 0xf
  andi  $t8, $t3, 0xf
  move  $a2, $t5
  move  $a3, $t7
  sw    $t8, 0x1c($sp)
  sw    $t9, 0x18($sp)
  sw    $t6, 0x10($sp)
  sw    $t1, 0x20($sp)
  jal   sub_GAME_7F0CDEA8
   move  $a1, $s2
  b     .L7F0CE5F0
   move  $s0, $v0
.L7F0CE4B8:
  srl   $a2, $v1, 0x16
  srl   $a3, $v1, 0x14
  srl   $t0, $v1, 0x12
  andi  $t5, $a2, 3
  andi  $t7, $a3, 3
  andi  $t6, $t0, 3
  move  $a2, $t5
  move  $a3, $t7
  beqz  $s4, .L7F0CE56C
   move  $t0, $t6
  lw    $t9, ($s5)
  sll   $t8, $s3, 2
  sw    $t6, 0x10($sp)
  addu  $v0, $t9, $t8
  lbu   $t5, 1($v0)
  move  $a0, $s0
  move  $a1, $s2
  srl   $t7, $t5, 5
  subu  $t6, $s7, $t7
  sw    $t6, 0x14($sp)
  lw    $t9, ($v0)
  sll   $t8, $t9, 0xb
  srl   $t5, $t8, 0x1d
  subu  $t7, $s7, $t5
  sw    $t7, 0x18($sp)
  lbu   $t6, ($v0)
  jal   sub_GAME_7F0CDFA8
   sw    $t6, 0x1c($sp)
  lui   $t9, (0xBA001402 >> 16) # lui $t9, 0xba00
  ori   $t9, (0xBA001402 & 0xFFFF) # ori $t9, $t9, 0x1402
  sw    $t9, ($v0)
  lui   $t5, (0xBA001001 >> 16) # lui $t5, 0xba00
  lui   $t6, (0xBA001102 >> 16) # lui $t6, 0xba00
  lui   $t8, 0x10
  ori   $t5, (0xBA001001 & 0xFFFF) # ori $t5, $t5, 0x1001
  lui   $t7, 1
  ori   $t6, (0xBA001102 & 0xFFFF) # ori $t6, $t6, 0x1102
  lui   $t9, 4
  sw    $t8, 4($v0)
  sw    $t7, 0xc($v0)
  sw    $t5, 8($v0)
  sw    $t9, 0x14($v0)
  sw    $t6, 0x10($v0)
  b     .L7F0CE5F0
   addiu $s0, $v0, 0x18
.L7F0CE56C:
  move  $a0, $s0
  move  $a1, $s2
  jal   sub_GAME_7F0CDE18
   sw    $t0, 0x10($sp)
  b     .L7F0CE5F0
   move  $s0, $v0
.L7F0CE584:
  srl   $a2, $v1, 0x16
  srl   $a3, $v1, 0x14
  srl   $t0, $v1, 0x12
  andi  $t8, $a2, 3
  andi  $t5, $a3, 3
  andi  $t7, $t0, 3
  move  $a2, $t8
  move  $a3, $t5
  sw    $t7, 0x10($sp)
  move  $a0, $s0
  jal   sub_GAME_7F0CE0AC
   move  $a1, $s2
  b     .L7F0CE5F0
   move  $s0, $v0
.L7F0CE5BC:
  srl   $a2, $v1, 0x16
  srl   $a3, $v1, 0x14
  srl   $t0, $v1, 0x12
  andi  $t6, $a2, 3
  andi  $t9, $a3, 3
  andi  $t8, $t0, 3
  move  $a2, $t6
  move  $a3, $t9
  sw    $t8, 0x10($sp)
  move  $a0, $s0
  jal   sub_GAME_7F0CE064
   move  $a1, $s2
  move  $s0, $v0
def_7F0CE2B4:
.L7F0CE5F0:
  li    $at, 1508
  bne   $s3, $at, .L7F0CE60C
   move  $a0, $s0
  jal   sub_GAME_7F09343C
   li    $a1, 1
  jal   sub_GAME_7F0CC4C8
   move  $s0, $v0
.L7F0CE60C:
  li    $at, 1511
  bne   $s3, $at, .L7F0CE628
   move  $a0, $s0
  jal   sub_GAME_7F09365C
   li    $a1, 1
  jal   sub_GAME_7F0CC4C8
   move  $s0, $v0
.L7F0CE628:
  jal   check_if_imageID_is_light
   move  $a0, $s3
  beqz  $v0, .L7F0CE644
   move  $a0, $s0
  li    $t5, 1
  jal   add_entry_to_init_lightfixture_table
   sw    $t5, 0x58($sp)
.L7F0CE644:
  b     .L7F0CE738
   addiu $s1, $s1, 8
  lw    $at, ($s1)
.L7F0CE650:
  li    $fp, 1
  addiu $s0, $s0, 8
  sw    $at, -8($s0)
  lw    $t9, 4($s1)
  addiu $s1, $s1, 8
  b     .L7F0CE738
   sw    $t9, -4($s0)
.L7F0CE66C:
  li    $t8, 1
  sw    $t8, 0x5c($sp)
  lw    $at, ($s1)
  move  $fp, $zero
  addiu $s0, $s0, 8
  sw    $at, -8($s0)
  lw    $t7, 4($s1)
  addiu $s1, $s1, 8
  b     .L7F0CE738
   sw    $t7, -4($s0)
.L7F0CE694:
  sw    $s0, 0x8c($sp)
  sw    $zero, 0x5c($sp)
  lw    $at, ($s1)
  addiu $s0, $s0, 8
  addiu $s1, $s1, 8
  sw    $at, -8($s0)
  lw    $t6, -4($s1)
  b     .L7F0CE738
   sw    $t6, -4($s0)
.L7F0CE6B8:
  beql  $s4, $zero, .L7F0CE708
   lw    $at, ($s1)
  lb    $v0, 2($s1)
  li    $at, 17
  beq   $v0, $at, .L7F0CE6E0
   li    $at, 20
  beq   $v0, $at, .L7F0CE6E0
   li    $at, 16
  bnel  $v0, $at, .L7F0CE6EC
   lw    $at, ($s1)
.L7F0CE6E0:
  b     .L7F0CE738
   addiu $s1, $s1, 8
  lw    $at, ($s1)
.L7F0CE6EC:
  addiu $s0, $s0, 8
  addiu $s1, $s1, 8
  sw    $at, -8($s0)
  lw    $t7, -4($s1)
  b     .L7F0CE738
   sw    $t7, -4($s0)
  lw    $at, ($s1)
.L7F0CE708:
  addiu $s0, $s0, 8
  addiu $s1, $s1, 8
  sw    $at, -8($s0)
  lw    $t9, -4($s1)
  b     .L7F0CE738
   sw    $t9, -4($s0)
.L7F0CE720:
  lw    $at, ($s1)
.L7F0CE724:
  addiu $s0, $s0, 8
  addiu $s1, $s1, 8
  sw    $at, -8($s0)
  lw    $t5, -4($s1)
  sw    $t5, -4($s0)
.L7F0CE738:
  lw    $t7, 0x88($sp)
  addiu $t8, $t7, -1
  bgtz  $t8, .L7F0CE194
   sw    $t8, 0x88($sp)
.L7F0CE748:
  lw    $t9, 0x58($sp)
  beql  $t9, $zero, .L7F0CE760
   lw    $t6, 0xa0($sp)
  jal   save_ptrDL_enpoint_to_current_init_lightfixture_table
   move  $a0, $s0
  lw    $t6, 0xa0($sp)
.L7F0CE760:
  lw    $ra, 0x54($sp)
  lw    $s1, 0x34($sp)
  subu  $v0, $s0, $t6
  lw    $s0, 0x30($sp)
  lw    $s2, 0x38($sp)
  lw    $s3, 0x3c($sp)
  lw    $s4, 0x40($sp)
  lw    $s5, 0x44($sp)
  lw    $s6, 0x48($sp)
  lw    $s7, 0x4c($sp)
  lw    $fp, 0x50($sp)
  jr    $ra
   addiu $sp, $sp, 0x98
");

asm(R"
glabel sub_GAME_7F0CE794
  sra   $t6, $a2, 3
  addiu $v0, $t6, -1
  move  $a2, $t6
  sll   $v1, $v0, 3
  addu  $a0, $v1, $a0
  addu  $a1, $v1, $a1
  move  $a3, $t6
  beqz  $a2, .L7F0CE7DC
   move  $a2, $v0
.L7F0CE7B8:
  lw    $t8, ($a0)
  lw    $t9, 4($a0)
  move  $a3, $a2
  addiu $a1, $a1, -8
  addiu $a0, $a0, -8
  sw    $t8, 8($a1)
  sw    $t9, 0xc($a1)
  bnez  $a2, .L7F0CE7B8
   addiu $a2, $a2, -1
.L7F0CE7DC:
  jr    $ra
   nop   
");
