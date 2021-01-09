void thread0_rmon(void) {}
int rmon_debug_is_final_build(void) { return 1; }
int rmon_debug_returns_neg_1(void) { return -1; }
void rmon_debug_stub(void) {}
void rmon_debug_stub_0(void) {}
void rmon_debug_stub_1(void) {}
void rmon_debug_stub_2(void) {}
void rmon_debug_stub_3(void) {}
void rmon_debug_stub_4(void) {}

asm(R"
glabel proutSyncPrintf
  addiu $sp, $sp, -0x28
  sw    $s2, 0x20($sp)
  sw    $s0, 0x18($sp)
  move  $s2, $a2
  sw    $ra, 0x24($sp)
  sw    $s1, 0x1c($sp)
  sw    $a0, 0x28($sp)
  beqz  $a2, .L7000CF28
   move  $s0, $zero
  move  $s1, $a1
  lbu   $a0, ($s1)
.L7000CF14:
  addiu $s0, $s0, 1
  jal   __osRdbSend
   addiu $s1, $s1, 1
  bnel  $s0, $s2, .L7000CF14
   lbu   $a0, ($s1)
.L7000CF28:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   li    $v0, 1
");

asm(R"
glabel osSyncPrintf
  addiu $sp, $sp, -0x20
  sw    $a0, 0x20($sp)
  sw    $ra, 0x14($sp)
  sw    $a1, 0x24($sp)
  sw    $a2, 0x28($sp)
  sw    $a3, 0x2c($sp)
  lui   $a0, %hi(proutSyncPrintf) # $a0, 0x7001
  addiu $a0, %lo(proutSyncPrintf) # addiu $a0, $a0, -0x3118
  addiu $a3, $sp, 0x24
  lw    $a2, 0x20($sp)
  jal   _Printf
   move  $a1, $zero
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop  
");
