.section .text
glabel osSetIntMask
  mfc0  $t4, $12
  andi  $v0, $t4, 0xff01
  lui   $t0, %hi(__OSGlobalIntMask) 
  addiu $t0, %lo(__OSGlobalIntMask) # addiu $t0, $t0, 0x698c
  lw    $t3, ($t0)
  li    $at, -1
  xor   $t0, $t3, $at
  andi  $t0, $t0, 0xff00
  or    $v0, $v0, $t0
  lui   $t2, %hi(MI_INTR_MASK_REG) # $t2, 0xa430
  lw    $t2, %lo(MI_INTR_MASK_REG)($t2)
  beqz  $t2, .L7000DD74
   srl   $t1, $t3, 0x10
  li    $at, -1
  xor   $t1, $t1, $at
  andi  $t1, $t1, 0x3f
  or    $t2, $t2, $t1
.L7000DD74:
  sll   $t2, $t2, 0x10
  or    $v0, $v0, $t2
  lui   $at, 0x3f
  and   $t0, $a0, $at
  and   $t0, $t0, $t3
  srl   $t0, $t0, 0xf
  lui   $t2, %hi(__osRcpImTable)
  addu  $t2, $t2, $t0
  lhu   $t2, %lo(__osRcpImTable)($t2)
  lui   $at, %hi(MI_INTR_MASK_REG) # $at, 0xa430
  sw    $t2, %lo(MI_INTR_MASK_REG)($at)
  andi  $t0, $a0, 0xff01
  andi  $t1, $t3, 0xff00
  and   $t0, $t0, $t1
  lui   $at, (0xFFFF00FF >> 16) # lui $at, 0xffff
  ori   $at, (0xFFFF00FF & 0xFFFF) # ori $at, $at, 0xff
  and   $t4, $t4, $at
  or    $t4, $t4, $t0
  mtc0  $t4, $12
  nop   
  nop   
  jr    $ra
   nop   

.section .rodata
glabel __osRcpImTable
	.half 0x555, 0x556, 0x559, 0x55a, 0x565, 0x566, 0x569, 0x56a
	.half 0x595, 0x596, 0x599, 0x59a, 0x5a5, 0x5a6, 0x5a9, 0x5aa
	.half 0x655, 0x656, 0x659, 0x65a, 0x665, 0x666, 0x669, 0x66a
	.half 0x695, 0x696, 0x699, 0x69a, 0x6a5, 0x6a6, 0x6a9, 0x6aa
	.half 0x955, 0x956, 0x959, 0x95a, 0x965, 0x966, 0x969, 0x96a
	.half 0x995, 0x996, 0x999, 0x99a, 0x9a5, 0x9a6, 0x9a9, 0x9aa
	.half 0xa55, 0xa56, 0xa59, 0xa5a, 0xa65, 0xa66, 0xa69, 0xa6a
	.half 0xa95, 0xa96, 0xa99, 0xa9a, 0xaa5, 0xaa6, 0xaa9, 0xaaa
