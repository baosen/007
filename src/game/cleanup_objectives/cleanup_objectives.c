asm(R"
glabel cleanupObjectives
  lui   $v0, %hi(objective_ptrs)
  lw    $v0, %lo(objective_ptrs)($v0)
  lui   $a0, %hi(objective_ptrs+8)
  addiu $a0, %lo(objective_ptrs+8) # addiu $a0, $a0, 0x5d38
  beqz  $v0, .L7F0075D4
   li    $v1, 8
  lbu   $t6, 0xe($v0)
  lui   $t8, %hi(dword_CODE_bss_80075D58) 
  andi  $t7, $t6, 1
  beqz  $t7, .L7F0075D4
   nop   
  lw    $t8, %lo(dword_CODE_bss_80075D58)($t8)
  li    $a1, 2
  li    $t9, 1
  beq   $a1, $t8, .L7F0075D4
   lui   $at, %hi(dword_CODE_bss_80075D58)
  sw    $t9, %lo(dword_CODE_bss_80075D58)($at)
.L7F0075D4:
  lui   $v0, %hi(objective_ptrs+4)
  lw    $v0, %lo(objective_ptrs+4)($v0)
  lui   $t0, %hi(dword_CODE_bss_80075D58) 
  addiu $t0, %lo(dword_CODE_bss_80075D58) # addiu $t0, $t0, 0x5d58
  beqz  $v0, .L7F007618
   li    $a1, 2
  lbu   $t1, 0xe($v0)
  lui   $t3, %hi(dword_CODE_bss_80075D5C) 
  andi  $t2, $t1, 1
  beqz  $t2, .L7F007618
   nop   
  lw    $t3, %lo(dword_CODE_bss_80075D5C)($t3)
  li    $t4, 1
  lui   $at, %hi(dword_CODE_bss_80075D5C)
  beq   $a1, $t3, .L7F007618
   nop   
  sw    $t4, %lo(dword_CODE_bss_80075D5C)($at)
.L7F007618:
  lui   $a2, %hi(dword_CODE_bss_80075D58)
  addiu $a2, %lo(dword_CODE_bss_80075D58) # addiu $a2, $a2, 0x5d58
  li    $a3, 1
.L7F007624:
  lw    $v0, ($a0)
  beql  $v0, $zero, .L7F007658
   lw    $v0, 4($a0)
  lbu   $t5, 0xe($v0)
  addu  $v0, $a2, $v1
  andi  $t6, $t5, 1
  beql  $t6, $zero, .L7F007658
   lw    $v0, 4($a0)
  lw    $t7, ($v0)
  beql  $a1, $t7, .L7F007658
   lw    $v0, 4($a0)
  sw    $a3, ($v0)
  lw    $v0, 4($a0)
.L7F007658:
  beql  $v0, $zero, .L7F007688
   lw    $v0, 8($a0)
  lbu   $t8, 0xe($v0)
  addu  $v0, $a2, $v1
  andi  $t9, $t8, 1
  beql  $t9, $zero, .L7F007688
   lw    $v0, 8($a0)
  lw    $t1, 4($v0)
  beql  $a1, $t1, .L7F007688
   lw    $v0, 8($a0)
  sw    $a3, 4($v0)
  lw    $v0, 8($a0)
.L7F007688:
  beql  $v0, $zero, .L7F0076B8
   lw    $v0, 0xc($a0)
  lbu   $t2, 0xe($v0)
  addu  $v0, $a2, $v1
  andi  $t3, $t2, 1
  beql  $t3, $zero, .L7F0076B8
   lw    $v0, 0xc($a0)
  lw    $t4, 8($v0)
  beql  $a1, $t4, .L7F0076B8
   lw    $v0, 0xc($a0)
  sw    $a3, 8($v0)
  lw    $v0, 0xc($a0)
.L7F0076B8:
  addiu $a0, $a0, 0x10
  beqz  $v0, .L7F0076E8
   nop   
  lbu   $t5, 0xe($v0)
  addu  $v0, $a2, $v1
  andi  $t6, $t5, 1
  beqz  $t6, .L7F0076E8
   nop   
  lw    $t7, 0xc($v0)
  beq   $a1, $t7, .L7F0076E8
   nop   
  sw    $a3, 0xc($v0)
.L7F0076E8:
  bne   $a0, $t0, .L7F007624
   addiu $v1, $v1, 0x10
  jr    $ra
   nop   
");
