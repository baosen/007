


.section .text


glabel osPiRawStartDma
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  sw    $a0, 0x28($sp)
  sw    $a1, 0x2c($sp)
  sw    $a2, 0x30($sp)
  sw    $a3, 0x34($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  lui   $t6, %hi(PI_STATUS_REG) # $t6, 0xa460
  lw    $s0, %lo(PI_STATUS_REG)($t6)
  andi  $t7, $s0, 3
  beqz  $t7, .L7000CFD8
   nop   
.L7000CFC4:
  lui   $t8, %hi(PI_STATUS_REG) # $t8, 0xa460
  lw    $s0, %lo(PI_STATUS_REG)($t8)
  andi  $t9, $s0, 3
  bnez  $t9, .L7000CFC4
   nop   
.L7000CFD8:
  jal   osVirtualToPhysical
   lw    $a0, 0x30($sp)
  lui   $t0, 0xa460
  sw    $v0, ($t0)
  lui   $t1, %hi(osRomBase) 
  lw    $t1, %lo(osRomBase)($t1)
  lw    $t2, 0x2c($sp)
  lui   $at, (0x1FFFFFFF >> 16) # lui $at, 0x1fff
  ori   $at, (0x1FFFFFFF & 0xFFFF) # ori $at, $at, 0xffff
  or    $t3, $t1, $t2
  and   $t4, $t3, $at
  lui   $t5, %hi(PI_CART_ADDR_REG) # $t5, 0xa460
  sw    $t4, %lo(PI_CART_ADDR_REG)($t5)
  lw    $s1, 0x28($sp)
  beqz  $s1, .L7000D028
   li    $at, 1
  beq   $s1, $at, .L7000D03C
   nop   
  b     .L7000D050
   nop   
.L7000D028:
  lw    $t6, 0x34($sp)
  lui   $t8, %hi(PI_WR_LEN_REG) # $t8, 0xa460
  addiu $t7, $t6, -1
  b     .L7000D058
   sw    $t7, %lo(PI_WR_LEN_REG)($t8)
.L7000D03C:
  lw    $t9, 0x34($sp)
  lui   $t1, %hi(PI_RD_LEN_REG) # $t1, 0xa460
  addiu $t0, $t9, -1
  b     .L7000D058
   sw    $t0, %lo(PI_RD_LEN_REG)($t1)
.L7000D050:
  b     .L7000D05C
   li    $v0, -1
.L7000D058:
  move  $v0, $zero
.L7000D05C:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
