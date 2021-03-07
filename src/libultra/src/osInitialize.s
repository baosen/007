

.section .data
glabel osClockRate
.dword 62500000
glabel __osShutdown
 .word 0
glabel __OSGlobalIntMask
 .word 0x3FFF01
glabel osDiskExist
 .word 0
.align 4
.section .rodata
.section .bss
glabel __osFinalRom
.word 0

.section .text
glabel osInitialize
  addiu $sp, $sp, -0x40
  sw    $ra, 0x1c($sp)
  li    $t6, 1
  lui   $at, %hi(__osFinalRom)
  sw    $s0, 0x18($sp)
  sw    $zero, 0x38($sp)
  jal   __osGetSR
   sw    $t6, %lo(__osFinalRom)($at)
  move  $s0, $v0
  lui   $at, 0x2000
  jal   __osSetSR
   or    $a0, $s0, $at
  lui   $a0, (0x01000800 >> 16) # lui $a0, 0x100
  jal   __osSetFpcCsr
   ori   $a0, (0x01000800 & 0xFFFF) # ori $a0, $a0, 0x800
  lui   $a0, (0x1FC007FC >> 16) # lui $a0, 0x1fc0
  ori   $a0, (0x1FC007FC & 0xFFFF) # ori $a0, $a0, 0x7fc
  jal   __osSiRawReadIo
   addiu $a1, $sp, 0x3c
  beqz  $v0, .L7000D0EC
   nop   
.L7000D0D4:
  lui   $a0, (0x1FC007FC >> 16) # lui $a0, 0x1fc0
  ori   $a0, (0x1FC007FC & 0xFFFF) # ori $a0, $a0, 0x7fc
  jal   __osSiRawReadIo
   addiu $a1, $sp, 0x3c
  bnez  $v0, .L7000D0D4
   nop   
.L7000D0EC:
  lw    $a1, 0x3c($sp)
  lui   $a0, (0x1FC007FC >> 16) # lui $a0, 0x1fc0
  ori   $a0, (0x1FC007FC & 0xFFFF) # ori $a0, $a0, 0x7fc
  ori   $t7, $a1, 8
  jal   __osSiRawWriteIo
   move  $a1, $t7
  beqz  $v0, .L7000D12C
   nop   
.L7000D10C:
  lw    $a1, 0x3c($sp)
  lui   $a0, (0x1FC007FC >> 16) # lui $a0, 0x1fc0
  ori   $a0, (0x1FC007FC & 0xFFFF) # ori $a0, $a0, 0x7fc
  ori   $t8, $a1, 8
  jal   __osSiRawWriteIo
   move  $a1, $t8
  bnez  $v0, .L7000D10C
   nop   
.L7000D12C:
  lui   $t0, %hi(__osExceptionPreamble) # $t0, 0x7001
  addiu $t0, %lo(__osExceptionPreamble) # addiu $t0, $t0, 0x190
  lw    $at, ($t0)
  lui   $t9, 0x8000
  lui   $t5, %hi(__osExceptionPreamble) # $t5, 0x7001
  sw    $at, ($t9)
  lw    $t3, 4($t0)
  addiu $t5, %lo(__osExceptionPreamble) # addiu $t5, $t5, 0x190
  lui   $t4, 0x8000
  sw    $t3, 4($t9)
  lw    $at, 8($t0)
  ori   $t4, (0x80000080 & 0xFFFF) # ori $t4, $t4, 0x80
  lui   $t1, %hi(__osExceptionPreamble) # $t1, 0x7001
  sw    $at, 8($t9)
  lw    $t3, 0xc($t0)
  addiu $t1, %lo(__osExceptionPreamble) # addiu $t1, $t1, 0x190
  lui   $t2, 0x8000
  sw    $t3, 0xC($t9)
  lw    $at, 0($t5)
  ori   $t2, (0x80000100 & 0xFFFF) # ori $t2, $t2, 0x100
  lui   $t6, %hi(__osExceptionPreamble) # $t6, 0x7001
  sw    $at, 0($t4)
  lw    $t8, 4($t5)
  addiu $t6, %lo(__osExceptionPreamble) # addiu $t6, $t6, 0x190
  lui   $t7, 0x8000
  sw    $t8, 4($t4)
  lw    $at, 8($t5)
  ori   $t7, (0x80000180 & 0xFFFF) # ori $t7, $t7, 0x180
  lui   $a0, 0x8000
  sw    $at, 8($t4)
  lw    $t8, 0xc($t5)
  li    $a1, 400
  sw    $t8, 0xC($t4)
  lw    $at, 0($t1)
  sw    $at, 0($t2)
  lw    $t3, 4($t1)
  sw    $t3, 4($t2)
  lw    $at, 8($t1)
  sw    $at, 8($t2)
  lw    $t3, 0xc($t1)
  sw    $t3, 0xC($t2)
  lw    $at, 0($t6)
  sw    $at, 0($t7)
  lw    $t8, 4($t6)
  sw    $t8, 4($t7)
  lw    $at, 8($t6)
  sw    $at, 8($t7)
  lw    $t8, 0xc($t6)
  jal   osWritebackDCache
   sw    $t8, 0xC($t7)
  lui   $a0, 0x8000
  jal   osInvalICache
   li    $a1, 400
  jal   osMapTLBRdb
   nop   
  li    $a0, 4
  jal   osPiRawReadIo
   addiu $a1, $sp, 0x38
  lw    $t0, 0x38($sp)
  li    $at, -16
  and   $t9, $t0, $at
  beqz  $t9, .L7000D23C
   sw    $t9, 0x38($sp)
  lui   $at, %hi(osClockRate)
  move  $t3, $t9
  li    $t2, 0
  sw    $t2, %lo(osClockRate)($at)
  sw    $t3, %lo(osClockRate+4)($at)
.L7000D23C:
  lui   $a0, %hi(osClockRate)
  lui   $a1, %hi(osClockRate)
  lw    $a1, %lo(osClockRate+4)($a1)
  lw    $a0, %lo(osClockRate)($a0)
  li    $a2, 0
  jal   __ll_mul
   li    $a3, 3
  sw    $v0, 0x20($sp)
  sw    $v1, 0x24($sp)
  lw    $a1, 0x24($sp)
  lw    $a0, 0x20($sp)
  li    $a2, 0
  jal   __ull_div
   li    $a3, 4
  lui   $t1, %hi(osResetType) 
  lw    $t1, %lo(osResetType)($t1)
  lui   $at, %hi(osClockRate)
  sw    $v0, %lo(osClockRate)($at)
  bnez  $t1, .L7000D29C
   sw    $v1, %lo(osClockRate+4)($at)
  lui   $a0, %hi(osAppNMIBuffer)
  addiu $a0, %lo(osAppNMIBuffer) # addiu $a0, $a0, 0x31c
  jal   _blkclr
   li    $a1, 64
.L7000D29C:
  lui   $t5, %hi(PI_STATUS_REG) # $t5, 0xa460
  lw    $t4, %lo(PI_STATUS_REG)($t5)
  andi  $t7, $t4, 3
  beqz  $t7, .L7000D2CC
   sw    $t4, 0x30($sp)
.L7000D2B0:
  lui   $t6, %hi(PI_STATUS_REG) # $t6, 0xa460
  lw    $t8, %lo(PI_STATUS_REG)($t6)
  sw    $t8, 0x30($sp)
  lw    $t0, 0x30($sp)
  andi  $t9, $t0, 3
  bnez  $t9, .L7000D2B0
   nop   
.L7000D2CC:
  lui   $t2, %hi(ASIC_STATUS) # $t2, 0xa500
  lw    $t3, %lo(ASIC_STATUS)($t2)
  andi  $t1, $t3, 0xffff
  bnez  $t1, .L7000D304
   sw    $t3, 0x34($sp)
  li    $t5, 1
  lui   $at, %hi(osDiskExist)
  lui   $a1, %hi(__osLeoInterrupt) # $a1, 0x7001
  sw    $t5, %lo(osDiskExist)($at)
  addiu $a1, %lo(__osLeoInterrupt) # addiu $a1, $a1, 0x7d30
  jal   __osSetHWIntrRoutine
   li    $a0, 1
  b     .L7000D30C
   nop   
.L7000D304:
  lui   $at, %hi(osDiskExist)
  sw    $zero, %lo(osDiskExist)($at)
.L7000D30C:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x40
  jr    $ra
   nop   





