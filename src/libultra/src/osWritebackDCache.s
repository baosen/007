


.section .text, "ax" 
glabel osWritebackDCache
  blez  $a1, .L70010C18
   nop   
  li    $t3, 8192
  sltu  $at, $a1, $t3
  beqz  $at, .L70010C20
   nop   
  move  $t0, $a0
  addu  $t1, $a0, $a1
  sltu  $at, $t0, $t1
  beqz  $at, .L70010C18
   nop   
  andi  $t2, $t0, 0xf
  addiu $t1, $t1, -0x10
  subu  $t0, $t0, $t2
.L70010C08:
  cache 0x19, ($t0)
  sltu  $at, $t0, $t1
  bnez  $at, .L70010C08
   addiu $t0, $t0, 0x10
.L70010C18:
  jr    $ra
   nop   

.L70010C20:
  lui   $t0, 0x8000
  addu  $t1, $t0, $t3
  addiu $t1, $t1, -0x10
.L70010C2C:
  cache 1, ($t0)
  sltu  $at, $t0, $t1
  bnez  $at, .L70010C2C
   addiu $t0, $t0, 0x10
  jr    $ra
   nop   
