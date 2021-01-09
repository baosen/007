asm(R"
glabel cleanupGuardData
  lui   $v1, %hi(num_guards)
  lw    $v1, %lo(num_guards)($v1)
  addiu $sp, $sp, -0x28
  sw    $s2, 0x20($sp)
  sw    $ra, 0x24($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  blez  $v1, .L7F007444
   move  $s2, $zero
  lui   $s1, %hi(ptr_guard_data)
  addiu $s1, %lo(ptr_guard_data) # addiu $s1, $s1, -0x339c
  move  $s0, $zero
.L7F0073E0:
  lw    $t6, ($s1)
  addu  $v0, $t6, $s0
  lw    $t7, 0x1c($v0)
  beql  $t7, $zero, .L7F007438
   addiu $s2, $s2, 1
  jal   disable_sounds_attached_to_player_then_something
   lw    $a0, 0x18($v0)
  lw    $t8, ($s1)
  addu  $t9, $t8, $s0
  jal   sub_GAME_7F03A538
   lw    $a0, 0x18($t9)
  lw    $t0, ($s1)
  addu  $t1, $t0, $s0
  jal   unset_stateflag_0x04_for_posdata
   lw    $a0, 0x18($t1)
  lw    $t2, ($s1)
  addu  $t3, $t2, $s0
  jal   set_last_obj_pos_data
   lw    $a0, 0x18($t3)
  lui   $v1, %hi(num_guards)
  lw    $v1, %lo(num_guards)($v1)
  addiu $s2, $s2, 1
.L7F007438:
  slt   $at, $s2, $v1
  bnez  $at, .L7F0073E0
   addiu $s0, $s0, 0x1dc
.L7F007444:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");
