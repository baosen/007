// CPU cycle count.
int D_80048490 = -1;
int D_80048494 = 0;
int D_80048498 = 1;

#ifdef VERSION_JP
float jpD_800484CC = 1.0f;
float jpD_800484D0 = 1.0f;
#endif

int D_8004849C = -1;
int D_800484A0 = 0;
int D_800484A4 = 0;
int D_800484A8 = 0;
unsigned int previous_count = 0, current_count = 0;
int D_800484B4 = 1;

void initialize_count(void) {
  current_count = osGetCount();
  previous_count = current_count;
}

#ifdef VERSION_US
asm(R"
glabel set_cpu_cycle_count
  lui   $t6, %hi(current_count) 
  lw    $t6, %lo(current_count)($t6)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lui   $at, %hi(previous_count)
  sw    $a0, 0x18($sp)
  jal   osGetCount
   sw    $t6, %lo(previous_count)($at)
  lui   $a0, %hi(D_80048494)
  lui   $at, %hi(current_count)
  sw    $v0, %lo(current_count)($at)
  addiu $a0, %lo(D_80048494) # addiu $a0, $a0, -0x7b6c
  lw    $v1, ($a0)
  lw    $a3, 0x18($sp)
  lui   $at, %hi(D_80048490)
  sw    $v1, %lo(D_80048490)($at)
  addu  $t7, $v1, $a3
  sw    $t7, ($a0)
  lui   $at, %hi(D_80048498)
  sw    $a3, %lo(D_80048498)($at)
  lw    $v1, ($a0)
  lui   $a1, %hi(D_800484A0)
  addiu $a1, %lo(D_800484A0) # addiu $a1, $a1, -0x7b60
  lw    $t8, ($a1)
  lui   $a2, %hi(D_8004849C)
  addiu $a2, %lo(D_8004849C) # addiu $a2, $a2, -0x7b64
  andi  $t0, $v1, 1
  sw    $t8, ($a2)
  bgez  $v1, .L7F0C0B20
   sra   $t9, $v1, 1
  addiu $at, $v1, 1
  sra   $t9, $at, 1
.L7F0C0B20:
  sw    $t9, ($a1)
  lui   $at, %hi(D_800484A4)
  sw    $t0, %lo(D_800484A4)($at)
  lw    $t2, ($a2)
  lw    $t1, ($a1)
  lw    $ra, 0x14($sp)
  lui   $at, %hi(D_800484A8)
  subu  $t3, $t1, $t2
  sw    $t3, %lo(D_800484A8)($at)
  jr    $ra
   addiu $sp, $sp, 0x18
");
#endif

#ifdef VERSION_JP
asm(R"
glabel set_cpu_cycle_count
  lui   $t6, %hi(current_count) # $t6, 0x8005
  lw    $t6, %lo(current_count)($t6)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lui   $at, %hi(previous_count) # $at, 0x8005
  sw    $a0, 0x18($sp)
  jal   osGetCount
   sw    $t6, %lo(previous_count)($at)
  lw    $a2, 0x18($sp)
  lui   $a0, %hi(D_80048494) # $a0, 0x8005
  lui   $at, %hi(current_count) # $at, 0x8005
  mtc1  $a2, $f4
  sw    $v0, %lo(current_count)($at)
  addiu $a0, %lo(D_80048494) # addiu $a0, $a0, -0x7b3c
  lw    $v1, ($a0)
  cvt.s.w $f6, $f4
  lui   $at, %hi(D_80048490) # $at, 0x8005
  sw    $v1, %lo(D_80048490)($at)
  addu  $t7, $v1, $a2
  lui   $a3, %hi(jpD_800484CC) # $a3, 0x8005
  sw    $t7, ($a0)
  lui   $at, %hi(D_80048498) # $at, 0x8005
  addiu $a3, %lo(jpD_800484CC) # addiu $a3, $a3, -0x7b34
  sw    $a2, %lo(D_80048498)($at)
  swc1  $f6, ($a3)
  lwc1  $f8, ($a3)
  lui   $at, %hi(jpD_800484D0) # $at, 0x8005
  lui   $a1, %hi(D_800484A0) # $a1, 0x8005
  swc1  $f8, %lo(jpD_800484D0)($at)
  lw    $v1, ($a0)
  addiu $a1, %lo(D_800484A0) # addiu $a1, $a1, -0x7b28
  lw    $t8, ($a1)
  lui   $t0, %hi(D_8004849C) # $t0, 0x8005
  addiu $t0, %lo(D_8004849C) # addiu $t0, $t0, -0x7b2c
  andi  $t1, $v1, 1
  sw    $t8, ($t0)
  bgez  $v1, .L7F0C17B0
   sra   $t9, $v1, 1
  addiu $at, $v1, 1
  sra   $t9, $at, 1
.L7F0C17B0:
  sw    $t9, ($a1)
  lui   $at, %hi(D_800484A4) # $at, 0x8005
  sw    $t1, %lo(D_800484A4)($at)
  lw    $t3, ($t0)
  lw    $t2, ($a1)
  lw    $ra, 0x14($sp)
  lui   $at, %hi(D_800484A8) # $at, 0x8005
  subu  $t4, $t2, $t3
  sw    $t4, %lo(D_800484A8)($at)
  jr    $ra
   addiu $sp, $sp, 0x18  
");
#endif

asm(R"
glabel setup_cpu_cycle_count
  addiu $sp, $sp, -0x28
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  lui   $s0, %hi(D_800484B4)
  lui   $s1, %hi(current_count)
  lui   $s2, (0x0005EB61 >> 16) # lui $s2, 5
  lui   $s3, (0x000BD6C3 >> 16) # lui $s3, 0xb
  sw    $ra, 0x24($sp)
  ori   $s3, (0x000BD6C3 & 0xFFFF) # ori $s3, $s3, 0xd6c3
  ori   $s2, (0x0005EB61 & 0xFFFF) # ori $s2, $s2, 0xeb61
  addiu $s1, %lo(current_count) # addiu $s1, $s1, -0x7b50
  addiu $s0, %lo(D_800484B4) # addiu $s0, $s0, -0x7b4c
.L7F0C0B84:
  jal   osGetCount
   nop   
  lw    $t6, ($s1)
  lw    $t9, ($s0)
  subu  $t7, $v0, $t6
  addu  $t8, $t7, $s2
  divu  $zero, $t8, $s3
  mflo  $a0
  sltu  $at, $a0, $t9
  bnez  $s3, .L7F0C0BB4
   nop   
  break 7
.L7F0C0BB4:
  bnez  $at, .L7F0C0B84
   nop   
  li    $t0, 1
  jal   set_cpu_cycle_count
   sw    $t0, ($s0)
  lw    $ra, 0x24($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

void sub_GAME_7F0C0BE4(int arg0) { D_800484B4 = arg0; }

void sub_GAME_7F0C0BF0(void) { sub_GAME_7F0A9358(); }
