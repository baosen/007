


.section .text, "ax" 
glabel osUnmapTLB
  mfc0  $t0, $10
  mtc0  $a0, $0
  lui   $t1, 0x8000
  mtc0  $t1, $10
  mtc0  $zero, $2
  mtc0  $zero, $3
  nop   
  tlbwi 
  nop   
  nop   
  nop   
  nop   
  mtc0  $t0, $10
  jr    $ra
   nop   

