

.section .text
glabel osWritebackDCacheAll
  lui   $t0, 0x8000
  li    $t2, 8192
  addu  $t1, $t0, $t2
  addiu $t1, $t1, -0x10
.L7000D330:
  cache 1, ($t0)
  sltu  $at, $t0, $t1
  bnez  $at, .L7000D330
   addiu $t0, $t0, 0x10
  jr    $ra
   nop   
