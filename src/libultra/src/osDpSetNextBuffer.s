


.section .text, "ax" 
glabel osDpSetNextBuffer
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  sw    $a0, 0x28($sp)
  sw    $a2, 0x30($sp)
  sw    $a3, 0x34($sp)
  jal   __osDpDeviceBusy
   sw    $s0, 0x18($sp)
  beqz  $v0, .L7000E7DC
   nop   
  b     .L7000E844
   li    $v0, -1
.L7000E7DC:
  li    $t6, 1
  lui   $t7, %hi(DPC_STATUS_REG) # $t7, 0xa410
  sw    $t6, %lo(DPC_STATUS_REG)($t7)
.L7000E7E8:
  lui   $t8, %hi(DPC_STATUS_REG) # $t8, 0xa410
  lw    $s0, %lo(DPC_STATUS_REG)($t8)
  andi  $t9, $s0, 1
  bnez  $t9, .L7000E7E8
   nop   
  jal   osVirtualToPhysical
   lw    $a0, 0x28($sp)
  lui   $t0, 0xa410
  sw    $v0, ($t0)
  jal   osVirtualToPhysical
   lw    $a0, 0x28($sp)
  lw    $t5, 0x34($sp)
  move  $t3, $v0
  lw    $t4, 0x30($sp)
  addu  $t7, $t3, $t5
  li    $t2, 0
  sltu  $at, $t7, $t5
  addu  $t6, $at, $t2
  move  $t1, $t7
  lui   $t8, %hi(DPC_END_REG) # $t8, 0xa410
  sw    $t1, %lo(DPC_END_REG)($t8)
  move  $v0, $zero
  addu  $t6, $t6, $t4
.L7000E844:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
