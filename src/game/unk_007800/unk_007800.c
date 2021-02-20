asm(R"
glabel cleanupExplosions
  addiu $sp, $sp, -0x28
  sw    $ra, 0x24($sp)
  lui   $at, %hi(D_80040170)
  mtc1  $zero, $f12
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  jal   video_related_9
   sw    $zero, %lo(D_80040170)($at)
  lui   $s1, %hi(ptr_explosion_buf)
  addiu $s1, %lo(ptr_explosion_buf) # addiu $s1, $s1, -0x5ebc
  lw    $t6, ($s1)
  move  $s0, $zero
  li    $s2, 5952
  beqz  $t6, .L7F007894
   nop   
  lw    $t7, ($s1)
.L7F007844:
  addu  $t8, $t7, $s0
  lw    $a0, ($t8)
  beql  $a0, $zero, .L7F00788C
   addiu $s0, $s0, 0x3e0
  jal   sub_GAME_7F03A538
   nop   
  lw    $t9, ($s1)
  addu  $t0, $t9, $s0
  jal   unset_stateflag_0x04_for_posdata
   lw    $a0, ($t0)
  lw    $t1, ($s1)
  addu  $t2, $t1, $s0
  jal   set_last_obj_pos_data
   lw    $a0, ($t2)
  lw    $t3, ($s1)
  addu  $t4, $t3, $s0
  sw    $zero, ($t4)
  addiu $s0, $s0, 0x3e0
.L7F00788C:
  bnel  $s0, $s2, .L7F007844
   lw    $t7, ($s1)
.L7F007894:
  lui   $s1, %hi(ptr_smoke_buf)
  addiu $s1, %lo(ptr_smoke_buf) # addiu $s1, $s1, -0x5ec0
  lw    $t5, ($s1)
  move  $s0, $zero
  li    $s2, 8160
  beql  $t5, $zero, .L7F007908
   lw    $ra, 0x24($sp)
  lw    $t6, ($s1)
.L7F0078B4:
  addu  $t7, $t6, $s0
  lw    $a0, ($t7)
  beql  $a0, $zero, .L7F0078FC
   addiu $s0, $s0, 0x198
  jal   sub_GAME_7F03A538
   nop   
  lw    $t8, ($s1)
  addu  $t9, $t8, $s0
  jal   unset_stateflag_0x04_for_posdata
   lw    $a0, ($t9)
  lw    $t0, ($s1)
  addu  $t1, $t0, $s0
  jal   set_last_obj_pos_data
   lw    $a0, ($t1)
  lw    $t2, ($s1)
  addu  $t3, $t2, $s0
  sw    $zero, ($t3)
  addiu $s0, $s0, 0x198
.L7F0078FC:
  bnel  $s0, $s2, .L7F0078B4
   lw    $t6, ($s1)
  lw    $ra, 0x24($sp)
.L7F007908:
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");
