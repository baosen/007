extern int D_80036070;
extern int D_80036074;
extern int D_80036078;

void zero_contents_of_80036070_74(void) {
  D_80036070 = 0;
  D_80036074 = 0;
}

void set_contents_of_80036078(int arg0) { D_80036078 = arg0; }

asm(R"
glabel sub_GAME_7F005540
  addiu $sp, $sp, -0x30
  sw    $s4, 0x24($sp)
  lui   $s4, %hi(D_80036074)
  sw    $s5, 0x28($sp)
  move  $s5, $a0
  addiu $s4, %lo(D_80036074) # addiu $s4, $s4, 0x6074
  sw    $ra, 0x2c($sp)
  addiu $t6, $a0, 0x1e
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  sw    $t6, ($s4)
  sll   $a0, $t6, 5
  jal   mempAllocBytesInBank
   li    $a1, 4
  lw    $t8, ($s4)
  lui   $s2, %hi(ptr_allocation_1)
  addiu $s2, %lo(ptr_allocation_1) # addiu $s2, $s2, -0x66cc
  sw    $v0, ($s2)
  blez  $t8, .L7F005600
   move  $s1, $zero
  move  $s0, $zero
  li    $s3, 20
  lw    $t9, ($s2)
.L7F0055A4:
  slt   $at, $s1, $s5
  li    $a0, 80
  addu  $t0, $t9, $s0
  beqz  $at, .L7F0055C8
   sw    $zero, 8($t0)
  lw    $t1, ($s2)
  addu  $t2, $t1, $s0
  b     .L7F0055E8
   sw    $zero, 0x10($t2)
.L7F0055C8:
  jal   mempAllocBytesInBank
   li    $a1, 4
  lw    $t3, ($s2)
  addu  $t4, $t3, $s0
  sw    $v0, 0x10($t4)
  lw    $t5, ($s2)
  addu  $t6, $t5, $s0
  sh    $s3, 2($t6)
.L7F0055E8:
  lw    $t7, ($s4)
  addiu $s1, $s1, 1
  addiu $s0, $s0, 0x20
  slt   $at, $s1, $t7
  bnezl $at, .L7F0055A4
   lw    $t9, ($s2)
.L7F005600:
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  lw    $s4, 0x24($sp)
  lw    $s5, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x30
");

asm(R"
glabel sub_GAME_7F005624
  addiu $sp, $sp, -0x30
  sw    $s4, 0x24($sp)
  addiu $t6, $a0, 0xa
  lui   $s4, %hi(D_80036070)
  sw    $s5, 0x28($sp)
  sll   $t7, $t6, 2
  move  $s5, $a0
  addiu $s4, %lo(D_80036070) # addiu $s4, $s4, 0x6070
  sw    $ra, 0x2c($sp)
  subu  $t7, $t7, $t6
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  sw    $t6, ($s4)
  sll   $a0, $t7, 6
  jal   mempAllocBytesInBank
   li    $a1, 4
  lw    $t8, ($s4)
  lui   $s2, %hi(ptr_allocation_0)
  addiu $s2, %lo(ptr_allocation_0) # addiu $s2, $s2, -0x66d0
  sw    $v0, ($s2)
  blez  $t8, .L7F0056EC
   move  $s1, $zero
  move  $s0, $zero
  li    $s3, 140
  lw    $t9, ($s2)
.L7F005690:
  slt   $at, $s1, $s5
  li    $a0, 560
  addu  $t0, $t9, $s0
  beqz  $at, .L7F0056B4
   sw    $zero, 8($t0)
  lw    $t1, ($s2)
  addu  $t2, $t1, $s0
  b     .L7F0056D4
   sw    $zero, 0x10($t2)
.L7F0056B4:
  jal   mempAllocBytesInBank
   li    $a1, 4
  lw    $t3, ($s2)
  addu  $t4, $t3, $s0
  sw    $v0, 0x10($t4)
  lw    $t5, ($s2)
  addu  $t6, $t5, $s0
  sh    $s3, 2($t6)
.L7F0056D4:
  lw    $t7, ($s4)
  addiu $s1, $s1, 1
  addiu $s0, $s0, 0xbc
  slt   $at, $s1, $t7
  bnezl $at, .L7F005690
   lw    $t9, ($s2)
.L7F0056EC:
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  lw    $s4, 0x24($sp)
  lw    $s5, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x30
");
