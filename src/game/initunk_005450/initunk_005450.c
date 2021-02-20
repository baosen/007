// Called by stage load.
asm(R"
glabel sub_GAME_7F005450
  lui   $t2, %hi(dword_CODE_bss_80076A50) 
  addiu $t2, %lo(dword_CODE_bss_80076A50) # addiu $t2, $t2, 0x6a50
  lui   $at, %hi(D_80036060)
  lui   $t3, %hi(dword_CODE_bss_80076A64) 
  sw    $t2, %lo(D_80036060)($at)
  addiu $t3, %lo(dword_CODE_bss_80076A64) # addiu $t3, $t3, 0x6a64
  lui   $t6, %hi(dword_CODE_bss_80076A78)
  sw    $t3, 0xc($t2)
  addiu $a2, $t6, %lo(dword_CODE_bss_80076A78)
  lui   $at, %hi(dword_CODE_bss_80076A70)
  sw    $a2, %lo(dword_CODE_bss_80076A70)($at)
  lui   $at, %hi(dword_CODE_bss_80076A74)
  sw    $t2, %lo(dword_CODE_bss_80076A74)($at)
  lui   $t7, %hi(dword_CODE_bss_80076A8C)
  addiu $a0, $t7, %lo(dword_CODE_bss_80076A8C)
  lui   $at, %hi(dword_CODE_bss_80076A84)
  sw    $a0, %lo(dword_CODE_bss_80076A84)($at)
  lui   $at, %hi(dword_CODE_bss_80076A88)
  lui   $a1, %hi(dword_CODE_bss_80076AA0)
  lui   $a3, %hi(dword_CODE_bss_80076AB4)
  lui   $t0, %hi(dword_CODE_bss_80076AC8) 
  lui   $t1, %hi(dword_CODE_bss_80076ADC) 
  lui   $v0, %hi(flt_CODE_bss_8007996C)
  addiu $v0, %lo(flt_CODE_bss_8007996C) # addiu $v0, $v0, -0x6694
  addiu $t1, %lo(dword_CODE_bss_80076ADC) # addiu $t1, $t1, 0x6adc
  addiu $t0, %lo(dword_CODE_bss_80076AC8) # addiu $t0, $t0, 0x6ac8
  addiu $a3, %lo(dword_CODE_bss_80076AB4) # addiu $a3, $a3, 0x6ab4
  addiu $a1, %lo(dword_CODE_bss_80076AA0) # addiu $a1, $a1, 0x6aa0
  sw    $t3, %lo(dword_CODE_bss_80076A88)($at)
  move  $v1, $a0
.L7F0054C8:
  sw    $t1, 0x48($v1)
  addiu $t1, $t1, 0x50
  sw    $a3, 0x20($v1)
  sw    $a0, 0x24($v1)
  sw    $t0, 0x34($v1)
  sw    $a1, 0x38($v1)
  sw    $a3, 0x4c($v1)
  sw    $a1, 0xc($v1)
  sw    $a2, 0x10($v1)
  addiu $a2, $a2, 0x50
  addiu $a1, $a1, 0x50
  addiu $a3, $a3, 0x50
  addiu $t0, $t0, 0x50
  addiu $a0, $a0, 0x50
  bne   $t1, $v0, .L7F0054C8
   addiu $v1, $v1, 0x50
  lui   $t8, %hi(dword_CODE_bss_80079908) 
  addiu $t8, %lo(dword_CODE_bss_80079908) # addiu $t8, $t8, -0x66f8
  jr    $ra
   sw    $t8, 0x2edc($t2)
");
