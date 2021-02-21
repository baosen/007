asm(R"
glabel cleanupObjectSounds
  addiu $sp, $sp, -0x20
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  lui   $s0, %hi(sound_effects)
  lui   $s1, %hi(ptr_list_object_lookup_indices)
  sw    $ra, 0x1c($sp)
  addiu $s1, %lo(ptr_list_object_lookup_indices) # addiu $s1, $s1, -0x63d0
  addiu $s0, %lo(sound_effects) # addiu $s0, $s0, -0x6490
  lw    $a0, ($s0)
.L7F007484:
  beql  $a0, $zero, .L7F0074A8
   addiu $s0, $s0, 0x18
  jal   sfxGetArg0Unk3F
   nop   
  beql  $v0, $zero, .L7F0074A8
   addiu $s0, $s0, 0x18
  jal   sfxDeactivate
   lw    $a0, ($s0)
  addiu $s0, $s0, 0x18
.L7F0074A8:
  bnel  $s0, $s1, .L7F007484
   lw    $a0, ($s0)
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x20
");
