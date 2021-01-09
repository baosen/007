asm(R"
glabel sub_GAME_7F007290
  mtc1  $zero, $f0
  lui   $at, %hi(flt_CODE_bss_80079E80)
  swc1  $f0, %lo(flt_CODE_bss_80079E80)($at)
  lui   $at, %hi(flt_CODE_bss_80079E84)
  swc1  $f0, %lo(flt_CODE_bss_80079E84)($at)
  lui   $at, %hi(flt_CODE_bss_80079E88)
  jr    $ra
   swc1  $f0, %lo(flt_CODE_bss_80079E88)($at)
");