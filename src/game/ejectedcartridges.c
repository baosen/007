asm(R"
glabel something_with_ejected_cartridges
  addiu $sp, $sp, -0x20
  lui   $at, %hi(dword_CODE_bss_80075DB0)
  lui   $v0, %hi(dword_CODE_bss_80075DB8)
  lui   $v1, %hi(dword_CODE_bss_80075DC8)
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  sw    $zero, %lo(dword_CODE_bss_80075DB0)($at)
  addiu $v1, %lo(dword_CODE_bss_80075DC8) # addiu $v1, $v1, 0x5dc8
  addiu $v0, %lo(dword_CODE_bss_80075DB8) # addiu $v0, $v0, 0x5db8
.L7F005068:
  addiu $v0, $v0, 4
  sltu  $at, $v0, $v1
  bnez  $at, .L7F005068
   sw    $zero, -4($v0)
  lui   $t6, %hi(ejected_cartridge) 
  lw    $t6, %lo(ejected_cartridge)($t6)
  lui   $at, %hi(cartridges_eject)
  sw    $zero, %lo(cartridges_eject)($at)
  lui   $at, %hi(D_80034CA0)
  beqz  $t6, .L7F0050BC
   sw    $zero, %lo(D_80034CA0)($at)
  lui   $t7, %hi(ejected_cartridge)
  addiu $s0, $t7, %lo(ejected_cartridge)
  lw    $s1, ($s0)
  move  $a0, $s1
.L7F0050A4:
  jal   load_object_into_memory
   lw    $a1, 4($s0)
  lw    $s1, 8($s0)
  addiu $s0, $s0, 8
  bnezl $s1, .L7F0050A4
   move  $a0, $s1
.L7F0050BC:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x20
");
