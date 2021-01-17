asm(R"
glabel cleanupplayersoundrelated
  addiu $sp, $sp, -0x30
  sw    $ra, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  jal   getPlayerCount
   move  $s4, $zero
  blez  $v0, .L7F007A14
   sll   $t6, $s4, 2
  lui   $t7, %hi(players_p1) 
  addiu $t7, %lo(players_p1) # addiu $t7, $t7, -0x6120
  addu  $s2, $t6, $t7
  li    $s3, 1872
  move  $s1, $zero
.L7F0079C0:
  lw    $t8, ($s2)
.L7F0079C4:
  addu  $s0, $t8, $s1
  lw    $a0, 0xa44($s0)
  addiu $s0, $s0, 0x870
  beql  $a0, $zero, .L7F0079F4
   addiu $s1, $s1, 0x3a8
  jal   sfxGetArg0Unk3F
   nop   
  beql  $v0, $zero, .L7F0079F4
   addiu $s1, $s1, 0x3a8
  jal   sfxDeactivate
   lw    $a0, 0x1d4($s0)
  addiu $s1, $s1, 0x3a8
.L7F0079F4:
  bnel  $s1, $s3, .L7F0079C4
   lw    $t8, ($s2)
  addiu $s4, $s4, 1
  jal   getPlayerCount
   addiu $s2, $s2, 4
  slt   $at, $s4, $v0
  bnezl $at, .L7F0079C0
   move  $s1, $zero
.L7F007A14:
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  lw    $s3, 0x24($sp)
  lw    $s4, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x30
");
