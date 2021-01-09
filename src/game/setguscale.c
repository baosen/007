asm(R"
.late_rodata
glabel default_gu_scale
.word 0x3dcccccd

.text
glabel set_gu_scale
  lui   $at, %hi(default_gu_scale)
  lwc1  $f0, %lo(default_gu_scale)($at)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lui   $a0, %hi(dword_CODE_bss_8007A100)
  mfc1  $a1, $f0
  mfc1  $a2, $f0
  mfc1  $a3, $f0
  jal   guScale
   addiu $a0, %lo(dword_CODE_bss_8007A100) # addiu $a0, $a0, -0x5f00
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");
