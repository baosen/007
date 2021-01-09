


.section .text, "ax" 
glabel osInvalDCache
  blez  $a1, .L70010BA0
   nop   
  li    $t3, 8192
  sltu  $at, $a1, $t3
  beqz  $at, .L70010BA8
   nop   
  move  $t0, $a0
  addu  $t1, $a0, $a1
  sltu  $at, $t0, $t1
  beqz  $at, .L70010BA0
   nop   
  andi  $t2, $t0, 0xf
  beqz  $t2, .L70010B70
   addiu $t1, $t1, -0x10
  subu  $t0, $t0, $t2
  cache 0x15, ($t0)
  sltu  $at, $t0, $t1
  beqz  $at, .L70010BA0
   nop   
  addiu $t0, $t0, 0x10
.L70010B70:
  andi  $t2, $t1, 0xf
  beqz  $t2, .L70010B90
   nop   
  subu  $t1, $t1, $t2
  cache 0x15, 0x10($t1)
  sltu  $at, $t1, $t0
  bnez  $at, .L70010BA0
   nop   
.L70010B90:
  cache 0x11, ($t0)
  sltu  $at, $t0, $t1
  bnez  $at, .L70010B90
   addiu $t0, $t0, 0x10
.L70010BA0:
  jr    $ra
   nop   

.L70010BA8:
  lui   $t0, 0x8000
  addu  $t1, $t0, $t3
  addiu $t1, $t1, -0x10
.L70010BB4:
  cache 1, ($t0)
  sltu  $at, $t0, $t1
  bnez  $at, .L70010BB4
   addiu $t0, $t0, 0x10
  jr    $ra
   nop   
