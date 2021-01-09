asm(R"
glabel sub_GAME_7F007920
  lui   $a0, %hi(dword_CODE_bss_8007A160)
  addiu $a0, %lo(dword_CODE_bss_8007A160) # addiu $a0, $a0, -0x5ea0
  lw    $t6, ($a0)
  move  $v0, $zero
  move  $v1, $zero
  blez  $t6, .L7F007964
   lui   $a1, %hi(dword_CODE_bss_8007A164)
  addiu $a1, %lo(dword_CODE_bss_8007A164) # addiu $a1, $a1, -0x5e9c
  lw    $t7, ($a1)
.L7F007944:
  addiu $v0, $v0, 1
  addu  $t8, $t7, $v1
  sw    $zero, ($t8)
  lw    $t9, ($a0)
  addiu $v1, $v1, 0x68
  slt   $at, $v0, $t9
  bnezl $at, .L7F007944
   lw    $t7, ($a1)
.L7F007964:
  jr    $ra
   nop   
");
