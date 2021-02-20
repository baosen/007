asm(R"
glabel init_pathtable_something
  addiu $sp, $sp, -0x38
  sw    $s0, 0x1c($sp)
  move  $s0, $a0
  sw    $ra, 0x24($sp)
  sw    $s1, 0x20($sp)
  move  $s1, $a2
  jal   stanMatchTileName
   move  $a0, $a1
  beqz  $v0, .L7F006800
   sw    $v0, ($s1)
  move  $a0, $v0
  lw    $a1, ($s0)
  jal   sub_GAME_7F0B036C
   lw    $a2, 8($s0)
  bnezl $v0, .L7F006870
   li    $v0, 1
.L7F006800:
  lwc1  $f4, ($s0)
  addiu $a0, $sp, 0x2c
  addiu $a1, $sp, 0x30
  swc1  $f4, 0x2c($sp)
  lwc1  $f6, 4($s0)
  addiu $a2, $sp, 0x34
  li    $a3, 0
  swc1  $f6, 0x30($sp)
  lwc1  $f8, 8($s0)
  jal   sub_GAME_7F0AFB78
   swc1  $f8, 0x34($sp)
  beqz  $v0, .L7F006860
   sw    $v0, ($s1)
  lwc1  $f10, 8($s0)
  lw    $a3, ($s0)
  move  $a0, $s1
  lw    $a1, 0x2c($sp)
  lw    $a2, 0x34($sp)
  jal   sub_GAME_7F0B0BE4
   swc1  $f10, 0x10($sp)
  beql  $v0, $zero, .L7F006864
   sw    $zero, ($s1)
  b     .L7F006870
   li    $v0, 2
.L7F006860:
  sw    $zero, ($s1)
.L7F006864:
  b     .L7F006870
   move  $v0, $zero
  li    $v0, 1
.L7F006870:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x38
");