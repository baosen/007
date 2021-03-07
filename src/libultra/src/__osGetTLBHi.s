.section .text

glabel __osGetTLBHi
  mtc0  $a0, $0
  nop   
  tlbr  
  nop   
  nop   
  nop   
  mfc0  $v0, $10
  jr    $ra
   nop   

