


.section .text, "ax" 
glabel osInvalICache
  blez  $a1, .L7000D398
   nop   
  li    $t3, 16384
  sltu  $at, $a1, $t3
  beqz  $at, .L7000D3A0
   nop   
  move  $t0, $a0
  addu  $t1, $a0, $a1
  sltu  $at, $t0, $t1
  beqz  $at, .L7000D398
   nop   
  andi  $t2, $t0, 0x1f
  addiu $t1, $t1, -0x20
  subu  $t0, $t0, $t2
.L7000D388:
  cache 0x10, ($t0)
  sltu  $at, $t0, $t1
  bnez  $at, .L7000D388
   addiu $t0, $t0, 0x20
.L7000D398:
  jr    $ra
   nop   

.L7000D3A0:
  lui   $t0, 0x8000
  addu  $t1, $t0, $t3
  addiu $t1, $t1, -0x20
.L7000D3AC:
  cache 0, ($t0)
  sltu  $at, $t0, $t1
  bnez  $at, .L7000D3AC
   addiu $t0, $t0, 0x20
  jr    $ra
   nop   
