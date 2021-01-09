.section .text
glabel __osGetFpcCsr
  cfc1  $v0, $31
  jr    $ra
  nop
 