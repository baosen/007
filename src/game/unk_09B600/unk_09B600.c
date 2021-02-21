asm(R"
glabel sub_GAME_7F09B600
  addiu $sp, $sp, -0x58
  lui   $t6, (0x8F809F47 >> 16) # lui $t6, 0x8f80 # seed for save profile checksum confirmation
  lui   $t7, (0x3108B3C1 >> 16) # lui $t7, 0x3108
  sw    $s5, 0x28($sp)
  sw    $s4, 0x24($sp)
  sw    $s3, 0x20($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  ori   $t7, (0x3108B3C1 & 0xFFFF) # ori $t7, $t7, 0xb3c1
  ori   $t6, (0x8F809F47 & 0xFFFF) # ori $t6, $t6, 0x9f47
  sltu  $at, $a0, $a1 #
  move  $s5, $a1
  sw    $ra, 0x2c($sp)
  sw    $s2, 0x1c($sp)
  sw    $a2, 0x60($sp)
  move  $a3, $a0
  move  $s1, $zero
  sw    $t6, 0x48($sp)
  sw    $t7, 0x4c($sp)
  move  $s3, $zero
  move  $s4, $zero
  beqz  $at, .L7F09B6B0
   move  $s0, $a0
  sw    $a0, 0x58($sp)
  addiu $s2, $sp, 0x48
.L7F09B664:
  lbu   $t8, ($s0)
  lw    $t5, 0x4c($sp)
  andi  $t9, $s1, 0xf
  sllv  $t0, $t8, $t9
  lw    $t4, 0x48($sp)
  addu  $t7, $t0, $t5
  sra   $t2, $t0, 0x1f
  sltu  $at, $t7, $t5
  addu  $t6, $at, $t2
  addu  $t6, $t6, $t4
  sw    $t6, 0x48($sp)
  sw    $t7, 0x4c($sp)
  jal   lotsa_shifting_randomizer_related
   move  $a0, $s2
  addiu $s0, $s0, 1
  addiu $s1, $s1, 7
  bne   $s0, $s5, .L7F09B664
   xor   $s3, $s3, $v0
  lw    $a3, 0x58($sp)
.L7F09B6B0:
  addiu $s0, $s5, -1
  sltu  $at, $s0, $a3
  bnez  $at, .L7F09B70C
   addiu $s2, $sp, 0x48
  addiu $s5, $a3, -1
.L7F09B6C4:
  lbu   $t1, ($s0)
  lw    $t3, 0x4c($sp)
  andi  $t8, $s1, 0xf
  sllv  $t9, $t1, $t8
  lw    $t2, 0x48($sp)
  addu  $t5, $t9, $t3
  sra   $t0, $t9, 0x1f
  sltu  $at, $t5, $t3
  addu  $t4, $at, $t0
  addu  $t4, $t4, $t2
  sw    $t4, 0x48($sp)
  sw    $t5, 0x4c($sp)
  jal   lotsa_shifting_randomizer_related
   move  $a0, $s2
  addiu $s0, $s0, -1
  addiu $s1, $s1, 3
  bne   $s0, $s5, .L7F09B6C4
   xor   $s4, $s4, $v0
.L7F09B70C:
  lw    $t6, 0x60($sp)
  sw    $s3, ($t6)
  sw    $s4, 4($t6)
  lw    $ra, 0x2c($sp)
  lw    $s5, 0x28($sp)
  lw    $s4, 0x24($sp)
  lw    $s3, 0x20($sp)
  lw    $s2, 0x1c($sp)
  lw    $s1, 0x18($sp)
  lw    $s0, 0x14($sp)
  jr    $ra
   addiu $sp, $sp, 0x58
");
