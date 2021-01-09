#include "unk_093880.h"

asm(R"
glabel sub_GAME_7F0072B0
  lui   $at, %hi(off_CODE_bss_80079E30)
  sb    $zero, %lo(off_CODE_bss_80079E30)($at)
  lui   $at, %hi(off_CODE_bss_80079E30+1)
  sb    $zero, %lo(off_CODE_bss_80079E30+1)($at)
  lui   $at, %hi(off_CODE_bss_80079E30+2)
  lui   $v1, %hi(off_CODE_bss_80079E30+3)
  lui   $v0, %hi(off_CODE_bss_80079E30+0x4b)
  addiu $v0, %lo(off_CODE_bss_80079E30+0x4b) # addiu $v0, $v0, -0x6185
  addiu $v1, %lo(off_CODE_bss_80079E30+3) # addiu $v1, $v1, -0x61cd
  sb    $zero, %lo(off_CODE_bss_80079E30+2)($at)
.L7F0072D8:
  addiu $v1, $v1, 4
  sb    $zero, -3($v1)
  sb    $zero, -2($v1)
  sb    $zero, -1($v1)
  bne   $v1, $v0, .L7F0072D8
   sb    $zero, -4($v1)
  jr    $ra
   nop   
");

void disable_onscreen_cheat_text(void) {
  pPlayer->something_with_cheat_text = 0;
  pPlayer->can_display_cheat_text = 0;
}
