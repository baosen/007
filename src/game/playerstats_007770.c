asm(R"
glabel sub_GAME_7F007770
  addiu $sp, $sp, -0x40
  sw    $ra, 0x24($sp)
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  jal   getPlayerCount
   sw    $s0, 0x14($sp)
  jal   get_cur_playernum
   move  $s3, $v0
  sw    $v0, 0x30($sp)
  blez  $s3, .L7F0077D4
   move  $s0, $zero
  addiu $s2, $sp, 0x38
  addiu $s1, $sp, 0x3c
.L7F0077A8:
  jal   set_cur_player
   move  $a0, $s0
  move  $a0, $s1
  jal   sub_GAME_7F08DB08
   move  $a1, $s2
  lw    $a0, 0x3c($sp)
  jal   store_favorite_weapon_current_player
   lw    $a1, 0x38($sp)
  addiu $s0, $s0, 1
  bne   $s0, $s3, .L7F0077A8
   nop   
.L7F0077D4:
  jal   set_cur_player
   lw    $a0, 0x30($sp)
  lw    $ra, 0x24($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x40
");