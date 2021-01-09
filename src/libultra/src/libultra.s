

.section .text  
glabel osPfsInit
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a0, 0x20($sp)
  sw    $a1, 0x24($sp)
  sw    $a2, 0x28($sp)
  jal   __osSiGetAccess
   sw    $zero, 0x1c($sp)
  lw    $a0, 0x20($sp)
  jal   __osPfsGetStatus
   lw    $a1, 0x28($sp)
  jal   __osSiRelAccess
   sw    $v0, 0x1c($sp)
  lw    $t6, 0x1c($sp)
  beqz  $t6, .L70014784
   nop   
  b     .L700147E4
   move  $v0, $t6
.L70014784:
  lw    $t7, 0x20($sp)
  lw    $t8, 0x24($sp)
  sw    $t7, 4($t8)
  lw    $t0, 0x24($sp)
  lw    $t9, 0x28($sp)
  sw    $t9, 8($t0)
  lw    $t1, 0x24($sp)
  sw    $zero, ($t1)
  jal   __osGetId
   lw    $a0, 0x24($sp)
  sw    $v0, 0x1c($sp)
  lw    $t2, 0x1c($sp)
  beqz  $t2, .L700147C4
   nop   
  b     .L700147E4
   move  $v0, $t2
.L700147C4:
  jal   osPfsChecker
   lw    $a0, 0x24($sp)
  lw    $t3, 0x24($sp)
  sw    $v0, 0x1c($sp)
  lw    $t4, ($t3)
  ori   $t5, $t4, 1
  sw    $t5, ($t3)
  lw    $v0, 0x1c($sp)
.L700147E4:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   

glabel __osPfsGetStatus
  addiu $sp, $sp, -0x38
  sw    $ra, 0x14($sp)
  sw    $a0, 0x38($sp)
  sw    $a1, 0x3c($sp)
  sw    $zero, 0x34($sp)
  jal   __osPfsRequestData
   move  $a0, $zero
  lui   $a1, %hi(__osPfsPifRam)
  addiu $a1, %lo(__osPfsPifRam) # addiu $a1, $a1, 0x7d70
  jal   __osSiRawStartDma
   li    $a0, 1
  sw    $v0, 0x34($sp)
  lw    $a0, 0x38($sp)
  addiu $a1, $sp, 0x30
  jal   osRecvMesg
   li    $a2, 1
  lui   $a1, %hi(__osPfsPifRam)
  addiu $a1, %lo(__osPfsPifRam) # addiu $a1, $a1, 0x7d70
  jal   __osSiRawStartDma
   move  $a0, $zero
  sw    $v0, 0x34($sp)
  lw    $a0, 0x38($sp)
  addiu $a1, $sp, 0x30
  jal   osRecvMesg
   li    $a2, 1
  addiu $a0, $sp, 0x2f
  jal   __osPfsGetInitData
   addiu $a1, $sp, 0x1c
  lw    $t6, 0x3c($sp)
  sll   $t7, $t6, 2
  addu  $t8, $sp, $t7
  lbu   $t8, 0x1e($t8)
  andi  $t9, $t8, 1
  beqz  $t9, .L70014894
   nop   
  andi  $t0, $t8, 2
  beqz  $t0, .L70014894
   nop   
  b     .L700148F0
   li    $v0, 2
.L70014894:
  lw    $t1, 0x3c($sp)
  addiu $t3, $sp, 0x1c
  sll   $t2, $t1, 2
  addu  $t4, $t2, $t3
  lbu   $t5, 3($t4)
  bnez  $t5, .L700148C0
   nop   
  lbu   $t6, 2($t4)
  andi  $t7, $t6, 1
  bnez  $t7, .L700148C8
   nop   
.L700148C0:
  b     .L700148F0
   li    $v0, 1
.L700148C8:
  lw    $t9, 0x3c($sp)
  sll   $t8, $t9, 2
  addu  $t0, $sp, $t8
  lbu   $t0, 0x1e($t0)
  andi  $t1, $t0, 4
  beqz  $t1, .L700148EC
   nop   
  b     .L700148F0
   li    $v0, 4
.L700148EC:
  lw    $v0, 0x34($sp)
.L700148F0:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   

glabel osContInit
  addiu $sp, $sp, -0x80
  lui   $t6, %hi(__osContinitialized) 
  lw    $t6, %lo(__osContinitialized)($t6)
  sw    $ra, 0x24($sp)
  sw    $a0, 0x80($sp)
  sw    $a1, 0x84($sp)
  sw    $a2, 0x88($sp)
  beqz  $t6, .L7001492C
   sw    $zero, 0x78($sp)
  b     .L70014AE8
   move  $v0, $zero
.L7001492C:
  li    $t7, 1
  lui   $at, %hi(__osContinitialized)
  jal   osGetTime
   sw    $t7, %lo(__osContinitialized)($at)
  lui   $a1, (0x0007A120 >> 16) # lui $a1, 7
  lui   $a2, %hi(osClockRate)
  lui   $a3, %hi(osClockRate+0x4)
  sw    $v0, 0x70($sp)
  sw    $v1, 0x74($sp)
  lw    $a3, %lo(osClockRate+0x4)($a3)
  lw    $a2, %lo(osClockRate)($a2)
  ori   $a1, (0x0007A120 & 0xFFFF) # ori $a1, $a1, 0xa120
  jal   __ll_mul
   li    $a0, 0
  sw    $v0, 0x30($sp)
  sw    $v1, 0x34($sp)
  lui   $a3, (0x000F4240 >> 16) # lui $a3, 0xf
  ori   $a3, (0x000F4240 & 0xFFFF) # ori $a3, $a3, 0x4240
  lw    $a1, 0x34($sp)
  lw    $a0, 0x30($sp)
  jal   __ull_div
   li    $a2, 0
  lw    $t8, 0x70($sp)
  lw    $t9, 0x74($sp)
  sltu  $at, $v0, $t8
  bnez  $at, .L70014A58
   sltu  $at, $t8, $v0
  bnez  $at, .L700149A8
   sltu  $at, $t9, $v1
  beqz  $at, .L70014A58
   nop   
.L700149A8:
  addiu $a0, $sp, 0x38
  addiu $a1, $sp, 0x7c
  jal   osCreateMesgQueue
   li    $a2, 1
  lui   $a1, (0x0007A120 >> 16) # lui $a1, 7
  lui   $a2, %hi(osClockRate)
  lui   $a3, %hi(osClockRate+4)
  lw    $a3, %lo(osClockRate+4)($a3)
  lw    $a2, %lo(osClockRate)($a2)
  ori   $a1, (0x0007A120 & 0xFFFF) # ori $a1, $a1, 0xa120
  jal   __ll_mul
   li    $a0, 0
  sw    $v0, 0x28($sp)
  sw    $v1, 0x2c($sp)
  lui   $a3, (0x000F4240 >> 16) # lui $a3, 0xf
  ori   $a3, (0x000F4240 & 0xFFFF) # ori $a3, $a3, 0x4240
  lw    $a1, 0x2c($sp)
  lw    $a0, 0x28($sp)
  jal   __ull_div
   li    $a2, 0
  sw    $v0, 0x30($sp)
  sw    $v1, 0x34($sp)
  lw    $t1, 0x34($sp)
  lw    $t0, 0x30($sp)
  lw    $t2, 0x70($sp)
  lw    $t3, 0x74($sp)
  li    $t4, 0
  li    $t5, 0
  addiu $t6, $sp, 0x38
  addiu $t7, $sp, 0x7c
  subu  $a2, $t0, $t2
  sltu  $at, $t1, $t3
  subu  $a2, $a2, $at
  sw    $t7, 0x1c($sp)
  sw    $t6, 0x18($sp)
  sw    $t5, 0x14($sp)
  sw    $t4, 0x10($sp)
  addiu $a0, $sp, 0x50
  jal   osSetTimer
   subu  $a3, $t1, $t3
  addiu $a0, $sp, 0x38
  addiu $a1, $sp, 0x7c
  jal   osRecvMesg
   li    $a2, 1
.L70014A58:
  li    $t8, 4
  lui   $at, %hi(__osMaxControllers)
  sb    $t8, %lo(__osMaxControllers)($at)
  jal   __osPackRequestData
   move  $a0, $zero
  lui   $a1, %hi(__osContPifRam)
  addiu $a1, %lo(__osContPifRam) # addiu $a1, $a1, 0x7ca0
  jal   __osSiRawStartDma
   li    $a0, 1
  sw    $v0, 0x78($sp)
  lw    $a0, 0x80($sp)
  addiu $a1, $sp, 0x7c
  jal   osRecvMesg
   li    $a2, 1
  lui   $a1, %hi(__osContPifRam)
  addiu $a1, %lo(__osContPifRam) # addiu $a1, $a1, 0x7ca0
  jal   __osSiRawStartDma
   move  $a0, $zero
  sw    $v0, 0x78($sp)
  lw    $a0, 0x80($sp)
  addiu $a1, $sp, 0x7c
  jal   osRecvMesg
   li    $a2, 1
  lw    $a0, 0x84($sp)
  jal   __osContGetInitData
   lw    $a1, 0x88($sp)
  lui   $at, %hi(__osContLastCmd)
  jal   __osSiCreateAccessQueue
   sb    $zero, %lo(__osContLastCmd)($at)
  lui   $a0, %hi(__osEepromTimerQ)
  lui   $a1, %hi(__osEepromTimerMsg)
  addiu $a1, %lo(__osEepromTimerMsg) # addiu $a1, $a1, 0x7d20
  addiu $a0, %lo(__osEepromTimerQ) # addiu $a0, $a0, 0x7d08
  jal   osCreateMesgQueue
   li    $a2, 1
  lw    $v0, 0x78($sp)
.L70014AE8:
  lw    $ra, 0x24($sp)
  addiu $sp, $sp, 0x80
  jr    $ra
   nop   

glabel __osContGetInitData
  lui   $t7, %hi(__osMaxControllers) 
  lbu   $t7, %lo(__osMaxControllers)($t7)
  addiu $sp, $sp, -0x18
  lui   $t6, %hi(__osContPifRam) 
  addiu $t6, %lo(__osContPifRam) # addiu $t6, $t6, 0x7ca0
  sb    $zero, 7($sp)
  sw    $t6, 0x14($sp)
  blez  $t7, .L70014BB8
   sw    $zero, 8($sp)
.L70014B1C:
  lw    $t9, 0x14($sp)
  addiu $t8, $sp, 0xc
  lwl   $at, ($t9)
  lwr   $at, 3($t9)
  sw    $at, ($t8)
  lwl   $t1, 4($t9)
  lwr   $t1, 7($t9)
  sw    $t1, 4($t8)
  lbu   $t2, 0xe($sp)
  andi  $t3, $t2, 0xc0
  sra   $t4, $t3, 4
  sb    $t4, 3($a1)
  lbu   $t5, 3($a1)
  bnez  $t5, .L70014B8C
   nop   
  lbu   $t6, 0x11($sp)
  lbu   $t0, 0x10($sp)
  li    $t3, 1
  sll   $t7, $t6, 8
  or    $t8, $t7, $t0
  sh    $t8, ($a1)
  lbu   $t9, 0x12($sp)
  sb    $t9, 2($a1)
  lw    $t2, 8($sp)
  lbu   $t1, 7($sp)
  sllv  $t4, $t3, $t2
  or    $t5, $t1, $t4
  sb    $t5, 7($sp)
.L70014B8C:
  lw    $t6, 8($sp)
  lui   $t9, %hi(__osMaxControllers) 
  lbu   $t9, %lo(__osMaxControllers)($t9)
  lw    $t0, 0x14($sp)
  addiu $t7, $t6, 1
  slt   $at, $t7, $t9
  addiu $t8, $t0, 8
  sw    $t8, 0x14($sp)
  sw    $t7, 8($sp)
  bnez  $at, .L70014B1C
   addiu $a1, $a1, 4
.L70014BB8:
  lbu   $t3, 7($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   sb    $t3, ($a0)

glabel __osPackRequestData
  addiu $sp, $sp, -0x10
  andi  $a0, $a0, 0xff
  sw    $zero, ($sp)
.L70014BD4:
  lw    $t6, ($sp)
  lw    $t8, ($sp)
  lui   $at, %hi(__osContPifRam)
  sll   $t7, $t6, 2
  addu  $at, $at, $t7
  sw    $zero, %lo(__osContPifRam)($at)
  addiu $t9, $t8, 1
  slti  $at, $t9, 0x10
  bnez  $at, .L70014BD4
   sw    $t9, ($sp)
  lui   $t9, %hi(__osMaxControllers) 
  lbu   $t9, %lo(__osMaxControllers)($t9)
  lui   $t1, %hi(__osContPifRam) 
  li    $t0, 1
  lui   $at, %hi(__osContPifRam+0x3c)
  addiu $t1, %lo(__osContPifRam) # addiu $t1, $t1, 0x7ca0
  li    $t2, 255
  li    $t3, 1
  li    $t4, 3
  li    $t5, 255
  li    $t6, 255
  li    $t7, 255
  li    $t8, 255
  sw    $t0, %lo(__osContPifRam+0x3c)($at)
  sw    $t1, 0xc($sp)
  sb    $t2, 4($sp)
  sb    $t3, 5($sp)
  sb    $t4, 6($sp)
  sb    $a0, 7($sp)
  sb    $t5, 8($sp)
  sb    $t6, 9($sp)
  sb    $t7, 0xa($sp)
  sb    $t8, 0xb($sp)
  blez  $t9, .L70014CA8
   sw    $zero, ($sp)
.L70014C60:
  addiu $t1, $sp, 4
  lw    $at, ($t1)
  lw    $t0, 0xc($sp)
  lui   $t8, %hi(__osMaxControllers) 
  swl   $at, ($t0)
  swr   $at, 3($t0)
  lw    $t3, 4($t1)
  swl   $t3, 4($t0)
  swr   $t3, 7($t0)
  lw    $t6, ($sp)
  lbu   $t8, %lo(__osMaxControllers)($t8)
  lw    $t4, 0xc($sp)
  addiu $t7, $t6, 1
  slt   $at, $t7, $t8
  addiu $t5, $t4, 8
  sw    $t7, ($sp)
  bnez  $at, .L70014C60
   sw    $t5, 0xc($sp)
.L70014CA8:
  lw    $t2, 0xc($sp)
  li    $t9, 254
  addiu $sp, $sp, 0x10
  jr    $ra
   sb    $t9, ($t2)

  nop 

.section .data
glabel __osContinitialized
.word 0
.align 4

.section .bss
glabel __osContPifRam
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0

glabel __osContLastCmd
.byte 0

glabel __osMaxControllers
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0

glabel __osEepromTimer
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0

glabel __osEepromTimerQ
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0

glabel __osEepromTimerMsg
.word 0
glabel padding_80067d24
.word 0, 0, 0


.section .text  
glabel osContStartQuery
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a0, 0x20($sp)
  jal   __osSiGetAccess
   sw    $zero, 0x1c($sp)
  lui   $t6, %hi(__osContLastCmd) 
  lbu   $t6, %lo(__osContLastCmd)($t6)
  beqz  $t6, .L70014D10
   nop   
  jal   __osPackRequestData
   move  $a0, $zero
  lui   $a1, %hi(__osContPifRam)
  addiu $a1, %lo(__osContPifRam) # addiu $a1, $a1, 0x7ca0
  jal   __osSiRawStartDma
   li    $a0, 1
  sw    $v0, 0x1c($sp)
  lw    $a0, 0x20($sp)
  move  $a1, $zero
  jal   osRecvMesg
   li    $a2, 1
.L70014D10:
  lui   $a1, %hi(__osContPifRam)
  addiu $a1, %lo(__osContPifRam) # addiu $a1, $a1, 0x7ca0
  jal   __osSiRawStartDma
   move  $a0, $zero
  lui   $at, %hi(__osContLastCmd)
  sw    $v0, 0x1c($sp)
  jal   __osSiRelAccess
   sb    $zero, %lo(__osContLastCmd)($at)
  lw    $ra, 0x14($sp)
  lw    $v0, 0x1c($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   

glabel osContGetQuery
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a0, 0x20($sp)
  lw    $a1, 0x20($sp)
  jal   __osContGetInitData
   addiu $a0, $sp, 0x1f
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   

  nop   
glabel osContStartReadData
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a0, 0x20($sp)
  jal   __osSiGetAccess
   sw    $zero, 0x1c($sp)
  lui   $t6, %hi(__osContLastCmd) 
  lbu   $t6, %lo(__osContLastCmd)($t6)
  li    $at, 1
  beq   $t6, $at, .L70014DC4
   nop   
  jal   osContReadData_sub
   nop   
  lui   $a1, %hi(__osContPifRam)
  addiu $a1, %lo(__osContPifRam) # addiu $a1, $a1, 0x7ca0
  jal   __osSiRawStartDma
   li    $a0, 1
  sw    $v0, 0x1c($sp)
  lw    $a0, 0x20($sp)
  move  $a1, $zero
  jal   osRecvMesg
   li    $a2, 1
.L70014DC4:
  sw    $zero, 0x18($sp)
.L70014DC8:
  lw    $t8, 0x18($sp)
  lw    $t0, 0x18($sp)
  lui   $at, %hi(__osContPifRam)
  sll   $t9, $t8, 2
  addu  $at, $at, $t9
  li    $t7, 255
  sw    $t7, %lo(__osContPifRam)($at)
  addiu $t1, $t0, 1
  slti  $at, $t1, 0x10
  bnez  $at, .L70014DC8
   sw    $t1, 0x18($sp)
  lui   $at, %hi(__osContPifRam+0x3c)
  lui   $a1, %hi(__osContPifRam)
  sw    $zero, %lo(__osContPifRam+0x3c)($at)
  addiu $a1, %lo(__osContPifRam) # addiu $a1, $a1, 0x7ca0
  jal   __osSiRawStartDma
   move  $a0, $zero
  li    $t2, 1
  lui   $at, %hi(__osContLastCmd)
  sw    $v0, 0x1c($sp)
  jal   __osSiRelAccess
   sb    $t2, %lo(__osContLastCmd)($at)
  lw    $ra, 0x14($sp)
  lw    $v0, 0x1c($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   

glabel osContGetReadData
  lui   $t7, %hi(__osMaxControllers) 
  lbu   $t7, %lo(__osMaxControllers)($t7)
  lui   $t6, %hi(__osContPifRam) 
  addiu $sp, $sp, -0x10
  addiu $t6, %lo(__osContPifRam) # addiu $t6, $t6, 0x7ca0
  sw    $t6, 0xc($sp)
  blez  $t7, .L70014ED4
   sw    $zero, ($sp)
.L70014E54:
  lw    $t9, 0xc($sp)
  addiu $t8, $sp, 4
  lwl   $at, ($t9)
  lwr   $at, 3($t9)
  sw    $at, ($t8)
  lwl   $t1, 4($t9)
  lwr   $t1, 7($t9)
  sw    $t1, 4($t8)
  lbu   $t2, 6($sp)
  andi  $t3, $t2, 0xc0
  sra   $t4, $t3, 4
  sb    $t4, 4($a0)
  lbu   $t5, 4($a0)
  bnez  $t5, .L70014EA8
   nop   
  lhu   $t6, 8($sp)
  sh    $t6, ($a0)
  lb    $t7, 0xa($sp)
  sb    $t7, 2($a0)
  lb    $t0, 0xb($sp)
  sb    $t0, 3($a0)
.L70014EA8:
  lw    $t8, ($sp)
  lui   $t3, %hi(__osMaxControllers) 
  lbu   $t3, %lo(__osMaxControllers)($t3)
  lw    $t1, 0xc($sp)
  addiu $t9, $t8, 1
  slt   $at, $t9, $t3
  addiu $t2, $t1, 8
  sw    $t2, 0xc($sp)
  sw    $t9, ($sp)
  bnez  $at, .L70014E54
   addiu $a0, $a0, 6
.L70014ED4:
  jr    $ra
   addiu $sp, $sp, 0x10

glabel osContReadData_sub
  addiu $sp, $sp, -0x10
  lui   $t6, %hi(__osContPifRam) 
  addiu $t6, %lo(__osContPifRam) # addiu $t6, $t6, 0x7ca0
  sw    $t6, 0xc($sp)
  sw    $zero, ($sp)
.L70014EF0:
  lw    $t7, ($sp)
  lw    $t9, ($sp)
  lui   $at, %hi(__osContPifRam)
  sll   $t8, $t7, 2
  addu  $at, $at, $t8
  sw    $zero, %lo(__osContPifRam)($at)
  addiu $t0, $t9, 1
  slti  $at, $t0, 0x10
  bnez  $at, .L70014EF0
   sw    $t0, ($sp)
  lui   $t9, %hi(__osMaxControllers) 
  lbu   $t9, %lo(__osMaxControllers)($t9)
  li    $t1, 1
  lui   $at, %hi(__osContPifRam+0x3c)
  li    $t2, 255
  li    $t3, 1
  li    $t4, 4
  li    $t5, 1
  li    $t6, 65535
  li    $t7, -1
  li    $t8, -1
  sw    $t1, %lo(__osContPifRam+0x3c)($at)
  sb    $t2, 4($sp)
  sb    $t3, 5($sp)
  sb    $t4, 6($sp)
  sb    $t5, 7($sp)
  sh    $t6, 8($sp)
  sb    $t7, 0xa($sp)
  sb    $t8, 0xb($sp)
  blez  $t9, .L70014FB4
   sw    $zero, ($sp)
.L70014F6C:
  addiu $t1, $sp, 4
  lw    $at, ($t1)
  lw    $t0, 0xc($sp)
  lui   $t8, %hi(__osMaxControllers) 
  swl   $at, ($t0)
  swr   $at, 3($t0)
  lw    $t3, 4($t1)
  swl   $t3, 4($t0)
  swr   $t3, 7($t0)
  lw    $t6, ($sp)
  lbu   $t8, %lo(__osMaxControllers)($t8)
  lw    $t4, 0xc($sp)
  addiu $t7, $t6, 1
  slt   $at, $t7, $t8
  addiu $t5, $t4, 8
  sw    $t7, ($sp)
  bnez  $at, .L70014F6C
   sw    $t5, 0xc($sp)
.L70014FB4:
  lw    $t2, 0xc($sp)
  li    $t9, 254
  addiu $sp, $sp, 0x10
  jr    $ra
   sb    $t9, ($t2)

  nop   
  nop   
glabel osEepromProbe
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a0, 0x20($sp)
  jal   __osSiGetAccess
   sw    $zero, 0x1c($sp)
  lw    $a0, 0x20($sp)
  jal   __osEepStatus
   addiu $a1, $sp, 0x18
  sw    $v0, 0x1c($sp)
  lw    $t6, 0x1c($sp)
  bnez  $t6, .L7001501C
   nop   
  lhu   $t7, 0x18($sp)
  andi  $t8, $t7, 0x8000
  beqz  $t8, .L7001501C
   nop   
  li    $t9, 1
  b     .L70015020
   sw    $t9, 0x1c($sp)
.L7001501C:
  sw    $zero, 0x1c($sp)
.L70015020:
  jal   __osSiRelAccess
   nop   
  lw    $ra, 0x14($sp)
  lw    $v0, 0x1c($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   

  nop   
glabel osEepromRead
  addiu $sp, $sp, -0x38
  sw    $a1, 0x3c($sp)
  lbu   $t7, 0x3f($sp)
  lui   $t6, %hi(__osEepPifRam) 
  addiu $t6, %lo(__osEepPifRam) # addiu $t6, $t6, 0x7d30
  slti  $at, $t7, 0x41
  sw    $ra, 0x14($sp)
  sw    $a0, 0x38($sp)
  sw    $a2, 0x40($sp)
  sw    $zero, 0x34($sp)
  sw    $zero, 0x30($sp)
  bnez  $at, .L7001507C
   sw    $t6, 0x2c($sp)
  b     .L70015220
   li    $v0, -1
.L7001507C:
  jal   __osSiGetAccess
   nop   
  lw    $a0, 0x38($sp)
  jal   __osEepStatus
   addiu $a1, $sp, 0x28
  sw    $v0, 0x34($sp)
  lw    $t8, 0x34($sp)
  bnez  $t8, .L700150B0
   nop   
  lhu   $t9, 0x28($sp)
  li    $at, 32768
  beq   $t9, $at, .L700150B8
   nop   
.L700150B0:
  b     .L70015220
   li    $v0, 8
.L700150B8:
  lbu   $t0, 0x2a($sp)
  andi  $t1, $t0, 0x80
  beqz  $t1, .L700150E4
   nop   
.L700150C8:
  lw    $a0, 0x38($sp)
  jal   __osEepStatus
   addiu $a1, $sp, 0x28
  lbu   $t2, 0x2a($sp)
  andi  $t3, $t2, 0x80
  bnez  $t3, .L700150C8
   nop   
.L700150E4:
  jal   osEepromRead_sub
   lbu   $a0, 0x3f($sp)
  lui   $a1, %hi(__osEepPifRam)
  addiu $a1, %lo(__osEepPifRam) # addiu $a1, $a1, 0x7d30
  jal   __osSiRawStartDma
   li    $a0, 1
  sw    $v0, 0x34($sp)
  lw    $a0, 0x38($sp)
  move  $a1, $zero
  jal   osRecvMesg
   li    $a2, 1
  sw    $zero, 0x30($sp)
.L70015114:
  lw    $t5, 0x30($sp)
  lw    $t7, 0x30($sp)
  lui   $at, %hi(__osEepPifRam)
  sll   $t6, $t5, 2
  addu  $at, $at, $t6
  li    $t4, 255
  sw    $t4, %lo(__osEepPifRam)($at)
  addiu $t8, $t7, 1
  slti  $at, $t8, 0x10
  bnez  $at, .L70015114
   sw    $t8, 0x30($sp)
  lui   $at, %hi(__osEepPifRam+0x3C)
  lui   $a1, %hi(__osEepPifRam)
  sw    $zero, %lo(__osEepPifRam+0x3C)($at)
  addiu $a1, %lo(__osEepPifRam) # addiu $a1, $a1, 0x7d30
  jal   __osSiRawStartDma
   move  $a0, $zero
  li    $t9, 4
  lui   $at, %hi(__osContLastCmd)
  sw    $v0, 0x34($sp)
  sb    $t9, %lo(__osContLastCmd)($at)
  lw    $a0, 0x38($sp)
  move  $a1, $zero
  jal   osRecvMesg
   li    $a2, 1
  sw    $zero, 0x30($sp)
.L7001517C:
  lw    $t2, 0x30($sp)
  lw    $t0, 0x2c($sp)
  addiu $t3, $t2, 1
  slti  $at, $t3, 4
  addiu $t1, $t0, 1
  sw    $t3, 0x30($sp)
  bnez  $at, .L7001517C
   sw    $t1, 0x2c($sp)
  lw    $t4, 0x2c($sp)
  addiu $t5, $sp, 0x1c
  lwl   $at, ($t4)
  lwr   $at, 3($t4)
  sw    $at, ($t5)
  lwl   $t7, 4($t4)
  lwr   $t7, 7($t4)
  sw    $t7, 4($t5)
  lwl   $at, 8($t4)
  lwr   $at, 0xb($t4)
  sw    $at, 8($t5)
  lbu   $t8, 0x1d($sp)
  andi  $t9, $t8, 0xc0
  sra   $t0, $t9, 4
  bnez  $t0, .L70015214
   sw    $t0, 0x34($sp)
  sw    $zero, 0x30($sp)
.L700151E0:
  lw    $t1, 0x30($sp)
  lw    $t3, 0x40($sp)
  addu  $t2, $sp, $t1
  lbu   $t2, 0x20($t2)
  sb    $t2, ($t3)
  lw    $t4, 0x30($sp)
  lw    $t6, 0x40($sp)
  addiu $t7, $t4, 1
  slti  $at, $t7, 8
  addiu $t5, $t6, 1
  sw    $t7, 0x30($sp)
  bnez  $at, .L700151E0
   sw    $t5, 0x40($sp)
.L70015214:
  jal   __osSiRelAccess
   nop   
  lw    $v0, 0x34($sp)
.L70015220:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   

glabel osEepromRead_sub
  addiu $sp, $sp, -0x18
  lui   $t6, %hi(__osEepPifRam) 
  addiu $t6, %lo(__osEepPifRam) # addiu $t6, $t6, 0x7d30
  andi  $a0, $a0, 0xff
  sw    $t6, 0x14($sp)
  sw    $zero, 4($sp)
.L70015248:
  lw    $t8, 4($sp)
  lw    $t0, 4($sp)
  lui   $at, %hi(__osEepPifRam)
  sll   $t9, $t8, 2
  addu  $at, $at, $t9
  li    $t7, 255
  sw    $t7, %lo(__osEepPifRam)($at)
  addiu $t1, $t0, 1
  slti  $at, $t1, 0x10
  bnez  $at, .L70015248
   sw    $t1, 4($sp)
  li    $t2, 1
  lui   $at, %hi(__osEepPifRam+0x3C)
  li    $t3, 2
  li    $t4, 8
  li    $t5, 4
  sw    $t2, %lo(__osEepPifRam+0x3C)($at)
  sb    $t3, 8($sp)
  sb    $t4, 9($sp)
  sb    $t5, 0xa($sp)
  sb    $a0, 0xb($sp)
  sw    $zero, 4($sp)
.L700152A0:
  lw    $t6, 4($sp)
  addu  $t8, $sp, $t6
  sb    $zero, 0xc($t8)
  lw    $t7, 4($sp)
  addiu $t9, $t7, 1
  slti  $at, $t9, 8
  bnez  $at, .L700152A0
   sw    $t9, 4($sp)
  sw    $zero, 4($sp)
.L700152C4:
  lw    $t0, 0x14($sp)
  sb    $zero, ($t0)
  lw    $t3, 4($sp)
  lw    $t1, 0x14($sp)
  addiu $t4, $t3, 1
  slti  $at, $t4, 4
  addiu $t2, $t1, 1
  sw    $t4, 4($sp)
  bnez  $at, .L700152C4
   sw    $t2, 0x14($sp)
  addiu $t6, $sp, 8
  lw    $at, ($t6)
  lw    $t5, 0x14($sp)
  li    $t1, 254
  swl   $at, ($t5)
  swr   $at, 3($t5)
  lw    $t7, 4($t6)
  swl   $t7, 4($t5)
  swr   $t7, 7($t5)
  lw    $at, 8($t6)
  swl   $at, 8($t5)
  swr   $at, 0xb($t5)
  lw    $t9, 0x14($sp)
  addiu $t0, $t9, 0xc
  sw    $t0, 0x14($sp)
  sb    $t1, ($t0)
  jr    $ra
   addiu $sp, $sp, 0x18

  nop   
  nop   
  nop   

.section .bss
glabel __osEepPifRam
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0


.section .text
glabel osEepromWrite
  addiu $sp, $sp, -0x38
  sw    $a1, 0x3c($sp)
  lbu   $t7, 0x3f($sp)
  lui   $t6, %hi(__osEepPifRam) 
  addiu $t6, %lo(__osEepPifRam) # addiu $t6, $t6, 0x7d30
  slti  $at, $t7, 0x41
  sw    $ra, 0x14($sp)
  sw    $a0, 0x38($sp)
  sw    $a2, 0x40($sp)
  sw    $zero, 0x34($sp)
  bnez  $at, .L70015378
   sw    $t6, 0x2c($sp)
  b     .L700154E0
   li    $v0, -1
.L70015378:
  jal   __osSiGetAccess
   nop   
  lw    $a0, 0x38($sp)
  jal   __osEepStatus
   addiu $a1, $sp, 0x1c
  sw    $v0, 0x34($sp)
  lw    $t8, 0x34($sp)
  bnez  $t8, .L700153AC
   nop   
  lhu   $t9, 0x1c($sp)
  li    $at, 32768
  beq   $t9, $at, .L700153B4
   nop   
.L700153AC:
  b     .L700154E0
   li    $v0, 8
.L700153B4:
  lbu   $t0, 0x1e($sp)
  andi  $t1, $t0, 0x80
  beqz  $t1, .L700153E0
   nop   
.L700153C4:
  lw    $a0, 0x38($sp)
  jal   __osEepStatus
   addiu $a1, $sp, 0x1c
  lbu   $t2, 0x1e($sp)
  andi  $t3, $t2, 0x80
  bnez  $t3, .L700153C4
   nop   
.L700153E0:
  lbu   $a0, 0x3f($sp)
  jal   osEepromWrite_sub
   lw    $a1, 0x40($sp)
  lui   $a1, %hi(__osEepPifRam)
  addiu $a1, %lo(__osEepPifRam) # addiu $a1, $a1, 0x7d30
  jal   __osSiRawStartDma
   li    $a0, 1
  sw    $v0, 0x34($sp)
  lw    $a0, 0x38($sp)
  move  $a1, $zero
  jal   osRecvMesg
   li    $a2, 1
  sw    $zero, 0x30($sp)
.L70015414:
  lw    $t5, 0x30($sp)
  lw    $t7, 0x30($sp)
  lui   $at, %hi(__osEepPifRam)
  sll   $t6, $t5, 2
  addu  $at, $at, $t6
  li    $t4, 255
  sw    $t4, %lo(__osEepPifRam)($at)
  addiu $t8, $t7, 1
  slti  $at, $t8, 0x10
  bnez  $at, .L70015414
   sw    $t8, 0x30($sp)
  lui   $at, %hi(__osEepPifRam+0x3C)
  lui   $a1, %hi(__osEepPifRam)
  sw    $zero, %lo(__osEepPifRam+0x3C)($at)
  addiu $a1, %lo(__osEepPifRam) # addiu $a1, $a1, 0x7d30
  jal   __osSiRawStartDma
   move  $a0, $zero
  li    $t9, 5
  lui   $at, %hi(__osContLastCmd)
  sw    $v0, 0x34($sp)
  sb    $t9, %lo(__osContLastCmd)($at)
  lw    $a0, 0x38($sp)
  move  $a1, $zero
  jal   osRecvMesg
   li    $a2, 1
  sw    $zero, 0x30($sp)
.L7001547C:
  lw    $t2, 0x30($sp)
  lw    $t0, 0x2c($sp)
  addiu $t3, $t2, 1
  slti  $at, $t3, 4
  addiu $t1, $t0, 1
  sw    $t3, 0x30($sp)
  bnez  $at, .L7001547C
   sw    $t1, 0x2c($sp)
  lw    $t4, 0x2c($sp)
  addiu $t5, $sp, 0x20
  lwl   $at, ($t4)
  lwr   $at, 3($t4)
  sw    $at, ($t5)
  lwl   $t7, 4($t4)
  lwr   $t7, 7($t4)
  sw    $t7, 4($t5)
  lwl   $at, 8($t4)
  lwr   $at, 0xb($t4)
  sw    $at, 8($t5)
  lbu   $t8, 0x21($sp)
  andi  $t9, $t8, 0xc0
  sra   $t0, $t9, 4
  jal   __osSiRelAccess
   sw    $t0, 0x34($sp)
  lw    $v0, 0x34($sp)
.L700154E0:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   

glabel osEepromWrite_sub
  addiu $sp, $sp, -0x18
  lui   $t6, %hi(__osEepPifRam) 
  addiu $t6, %lo(__osEepPifRam) # addiu $t6, $t6, 0x7d30
  andi  $a0, $a0, 0xff
  sw    $t6, 0x14($sp)
  sw    $zero, 4($sp)
.L70015508:
  lw    $t8, 4($sp)
  lw    $t0, 4($sp)
  lui   $at, %hi(__osEepPifRam)
  sll   $t9, $t8, 2
  addu  $at, $at, $t9
  li    $t7, 255
  sw    $t7, %lo(__osEepPifRam)($at)
  addiu $t1, $t0, 1
  slti  $at, $t1, 0x10
  bnez  $at, .L70015508
   sw    $t1, 4($sp)
  li    $t2, 1
  lui   $at, %hi(__osEepPifRam+0x3C)
  li    $t3, 10
  li    $t4, 1
  li    $t5, 5
  sw    $t2, %lo(__osEepPifRam+0x3C)($at)
  sb    $t3, 8($sp)
  sb    $t4, 9($sp)
  sb    $t5, 0xa($sp)
  sb    $a0, 0xb($sp)
  sw    $zero, 4($sp)
.L70015560:
  lw    $t8, 4($sp)
  lbu   $t6, ($a1)
  addiu $a1, $a1, 1
  addu  $t7, $sp, $t8
  sb    $t6, 0xc($t7)
  lw    $t9, 4($sp)
  addiu $t0, $t9, 1
  slti  $at, $t0, 8
  bnez  $at, .L70015560
   sw    $t0, 4($sp)
  sw    $zero, 4($sp)
.L7001558C:
  lw    $t1, 0x14($sp)
  sb    $zero, ($t1)
  lw    $t4, 4($sp)
  lw    $t2, 0x14($sp)
  addiu $t5, $t4, 1
  slti  $at, $t5, 4
  addiu $t3, $t2, 1
  sw    $t5, 4($sp)
  bnez  $at, .L7001558C
   sw    $t3, 0x14($sp)
  addiu $t8, $sp, 8
  lw    $at, ($t8)
  lw    $t6, 0x14($sp)
  li    $t2, 254
  swl   $at, ($t6)
  swr   $at, 3($t6)
  lw    $t9, 4($t8)
  swl   $t9, 4($t6)
  swr   $t9, 7($t6)
  lw    $at, 8($t8)
  swl   $at, 8($t6)
  swr   $at, 0xb($t6)
  lw    $t0, 0x14($sp)
  addiu $t1, $t0, 0xc
  sw    $t1, 0x14($sp)
  sb    $t2, ($t1)
  jr    $ra
   addiu $sp, $sp, 0x18

glabel __osEepStatus
  addiu $sp, $sp, -0x30
  lui   $t6, %hi(__osEepPifRam) 
  addiu $t6, %lo(__osEepPifRam) # addiu $t6, $t6, 0x7d30
  sw    $ra, 0x14($sp)
  sw    $a0, 0x30($sp)
  sw    $a1, 0x34($sp)
  sw    $zero, 0x2c($sp)
  sw    $t6, 0x24($sp)
  sw    $zero, 0x28($sp)
.L70015620:
  lw    $t7, 0x28($sp)
  lw    $t9, 0x28($sp)
  lui   $at, %hi(__osEepPifRam)
  sll   $t8, $t7, 2
  addu  $at, $at, $t8
  sw    $zero, %lo(__osEepPifRam)($at)
  addiu $t0, $t9, 1
  slti  $at, $t0, 0x10
  bnez  $at, .L70015620
   sw    $t0, 0x28($sp)
  lui   $t2, %hi(__osEepPifRam) 
  li    $t1, 1
  lui   $at, %hi(__osEepPifRam+0x3C)
  addiu $t2, %lo(__osEepPifRam) # addiu $t2, $t2, 0x7d30
  sw    $t1, %lo(__osEepPifRam+0x3C)($at)
  sw    $t2, 0x24($sp)
  sw    $zero, 0x28($sp)
.L70015664:
  lw    $t3, 0x24($sp)
  sb    $zero, ($t3)
  lw    $t6, 0x28($sp)
  lw    $t4, 0x24($sp)
  addiu $t7, $t6, 1
  slti  $at, $t7, 4
  addiu $t5, $t4, 1
  sw    $t7, 0x28($sp)
  bnez  $at, .L70015664
   sw    $t5, 0x24($sp)
  li    $t8, 255
  li    $t9, 1
  li    $t0, 3
  li    $t1, 255
  li    $t2, 255
  li    $t3, 255
  li    $t4, 255
  sb    $t8, 0x1c($sp)
  sb    $t9, 0x1d($sp)
  sb    $t0, 0x1e($sp)
  sb    $zero, 0x1f($sp)
  sb    $t1, 0x20($sp)
  sb    $t2, 0x21($sp)
  sb    $t3, 0x22($sp)
  sb    $t4, 0x23($sp)
  addiu $t6, $sp, 0x1c
  lw    $at, ($t6)
  lw    $t5, 0x24($sp)
  li    $t2, 254
  lui   $a1, %hi(__osEepPifRam)
  swl   $at, ($t5)
  swr   $at, 3($t5)
  lw    $t9, 4($t6)
  addiu $a1, %lo(__osEepPifRam) # addiu $a1, $a1, 0x7d30
  li    $a0, 1
  swl   $t9, 4($t5)
  swr   $t9, 7($t5)
  lw    $t0, 0x24($sp)
  addiu $t1, $t0, 8
  sw    $t1, 0x24($sp)
  jal   __osSiRawStartDma
   sb    $t2, ($t1)
  sw    $v0, 0x2c($sp)
  lw    $a0, 0x30($sp)
  move  $a1, $zero
  jal   osRecvMesg
   li    $a2, 1
  li    $t3, 5
  lui   $at, %hi(__osContLastCmd)
  lui   $a1, %hi(__osEepPifRam)
  sb    $t3, %lo(__osContLastCmd)($at)
  addiu $a1, %lo(__osEepPifRam) # addiu $a1, $a1, 0x7d30
  jal   __osSiRawStartDma
   move  $a0, $zero
  sw    $v0, 0x2c($sp)
  lw    $a0, 0x30($sp)
  move  $a1, $zero
  jal   osRecvMesg
   li    $a2, 1
  lw    $t4, 0x2c($sp)
  beqz  $t4, .L70015764
   nop   
  b     .L70015810
   move  $v0, $t4
.L70015764:
  lui   $t8, %hi(__osEepPifRam) 
  addiu $t8, %lo(__osEepPifRam) # addiu $t8, $t8, 0x7d30
  sw    $t8, 0x24($sp)
  sw    $zero, 0x28($sp)
.L70015774:
  lw    $t7, 0x24($sp)
  sb    $zero, ($t7)
  lw    $t9, 0x28($sp)
  lw    $t5, 0x24($sp)
  addiu $t0, $t9, 1
  slti  $at, $t0, 4
  addiu $t6, $t5, 1
  sw    $t0, 0x28($sp)
  bnez  $at, .L70015774
   sw    $t6, 0x24($sp)
  lw    $t1, 0x24($sp)
  addiu $t2, $sp, 0x1c
  lwl   $at, ($t1)
  lwr   $at, 3($t1)
  sw    $at, ($t2)
  lwl   $t4, 4($t1)
  lwr   $t4, 7($t1)
  sw    $t4, 4($t2)
  lbu   $t8, 0x1e($sp)
  lw    $t6, 0x34($sp)
  andi  $t7, $t8, 0xc0
  sra   $t5, $t7, 4
  sb    $t5, 3($t6)
  lbu   $t9, 0x21($sp)
  lbu   $t3, 0x20($sp)
  lw    $t1, 0x34($sp)
  sll   $t0, $t9, 8
  or    $t2, $t0, $t3
  sh    $t2, ($t1)
  lw    $t8, 0x34($sp)
  lbu   $t4, 0x22($sp)
  sb    $t4, 2($t8)
  lw    $t7, 0x34($sp)
  lbu   $t5, 3($t7)
  beqz  $t5, .L7001580C
   nop   
  b     .L70015810
   move  $v0, $t5
.L7001580C:
  move  $v0, $zero
.L70015810:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   

glabel osEepromLongRead
  addiu $sp, $sp, -0x40
  sw    $a1, 0x44($sp)
  lbu   $t6, 0x47($sp)
  sw    $ra, 0x24($sp)
  sw    $a0, 0x40($sp)
  slti  $at, $t6, 0x41
  sw    $a2, 0x48($sp)
  sw    $a3, 0x4c($sp)
  bnez  $at, .L70015850
   sw    $zero, 0x3c($sp)
  b     .L7001594C
   li    $v0, -1
.L70015850:
  lw    $t7, 0x4c($sp)
  blez  $t7, .L70015948
   nop   
.L7001585C:
  lw    $a0, 0x40($sp)
  lbu   $a1, 0x47($sp)
  jal   osEepromRead
   lw    $a2, 0x48($sp)
  sw    $v0, 0x3c($sp)
  lw    $t8, 0x3c($sp)
  beqz  $t8, .L70015884
   nop   
  b     .L7001594C
   move  $v0, $t8
.L70015884:
  lw    $t9, 0x4c($sp)
  lbu   $t1, 0x47($sp)
  lw    $t3, 0x48($sp)
  lui   $a2, %hi(osClockRate)
  lui   $a3, %hi(osClockRate+4)
  addiu $t0, $t9, -8
  addiu $t2, $t1, 1
  addiu $t4, $t3, 8
  sw    $t0, 0x4c($sp)
  sb    $t2, 0x47($sp)
  sw    $t4, 0x48($sp)
  lw    $a3, %lo(osClockRate+4)($a3)
  lw    $a2, %lo(osClockRate)($a2)
  li    $a0, 0
  jal   __ll_mul
   li    $a1, 12000
  sw    $v0, 0x28($sp)
  sw    $v1, 0x2c($sp)
  lui   $a3, (0x000F4240 >> 16) # lui $a3, 0xf
  ori   $a3, (0x000F4240 & 0xFFFF) # ori $a3, $a3, 0x4240
  lw    $a1, 0x2c($sp)
  lw    $a0, 0x28($sp)
  jal   __ull_div
   li    $a2, 0
  lui   $t5, %hi(__osEepromTimerQ) 
  lui   $t8, %hi(__osEepromTimerMsg) 
  addiu $t8, %lo(__osEepromTimerMsg) # addiu $t8, $t8, 0x7d20
  addiu $t5, %lo(__osEepromTimerQ) # addiu $t5, $t5, 0x7d08
  sw    $v0, 0x30($sp)
  sw    $v1, 0x34($sp)
  lui   $a0, %hi(__osEepromTimer)
  li    $t6, 0
  li    $t7, 0
  sw    $t7, 0x14($sp)
  sw    $t6, 0x10($sp)
  addiu $a0, %lo(__osEepromTimer) # addiu $a0, $a0, 0x7ce8
  lw    $a3, 0x34($sp)
  lw    $a2, 0x30($sp)
  sw    $t5, 0x18($sp)
  jal   osSetTimer
   sw    $t8, 0x1c($sp)
  lui   $a0, %hi(__osEepromTimerQ)
  addiu $a0, %lo(__osEepromTimerQ) # addiu $a0, $a0, 0x7d08
  move  $a1, $zero
  jal   osRecvMesg
   li    $a2, 1
  lw    $t9, 0x4c($sp)
  bgtz  $t9, .L7001585C
   nop   
.L70015948:
  lw    $v0, 0x3c($sp)
.L7001594C:
  lw    $ra, 0x24($sp)
  addiu $sp, $sp, 0x40
  jr    $ra
   nop   

  nop   
glabel osEepromLongWrite
  addiu $sp, $sp, -0x40
  sw    $a1, 0x44($sp)
  lbu   $t6, 0x47($sp)
  sw    $ra, 0x24($sp)
  sw    $a0, 0x40($sp)
  slti  $at, $t6, 0x41
  sw    $a2, 0x48($sp)
  sw    $a3, 0x4c($sp)
  bnez  $at, .L70015990
   sw    $zero, 0x3c($sp)
  b     .L70015A8C
   li    $v0, -1
.L70015990:
  lw    $t7, 0x4c($sp)
  blez  $t7, .L70015A88
   nop   
.L7001599C:
  lw    $a0, 0x40($sp)
  lbu   $a1, 0x47($sp)
  jal   osEepromWrite
   lw    $a2, 0x48($sp)
  sw    $v0, 0x3c($sp)
  lw    $t8, 0x3c($sp)
  beqz  $t8, .L700159C4
   nop   
  b     .L70015A8C
   move  $v0, $t8
.L700159C4:
  lw    $t9, 0x4c($sp)
  lbu   $t1, 0x47($sp)
  lw    $t3, 0x48($sp)
  lui   $a2, %hi(osClockRate)
  lui   $a3, %hi(osClockRate+4)
  addiu $t0, $t9, -8
  addiu $t2, $t1, 1
  addiu $t4, $t3, 8
  sw    $t0, 0x4c($sp)
  sb    $t2, 0x47($sp)
  sw    $t4, 0x48($sp)
  lw    $a3, %lo(osClockRate+4)($a3)
  lw    $a2, %lo(osClockRate)($a2)
  li    $a0, 0
  jal   __ll_mul
   li    $a1, 12000
  sw    $v0, 0x28($sp)
  sw    $v1, 0x2c($sp)
  lui   $a3, (0x000F4240 >> 16) # lui $a3, 0xf
  ori   $a3, (0x000F4240 & 0xFFFF) # ori $a3, $a3, 0x4240
  lw    $a1, 0x2c($sp)
  lw    $a0, 0x28($sp)
  jal   __ull_div
   li    $a2, 0
  lui   $t5, %hi(__osEepromTimerQ) 
  lui   $t8, %hi(__osEepromTimerMsg) 
  addiu $t8, %lo(__osEepromTimerMsg) # addiu $t8, $t8, 0x7d20
  addiu $t5, %lo(__osEepromTimerQ) # addiu $t5, $t5, 0x7d08
  sw    $v0, 0x30($sp)
  sw    $v1, 0x34($sp)
  lui   $a0, %hi(__osEepromTimer)
  li    $t6, 0
  li    $t7, 0
  sw    $t7, 0x14($sp)
  sw    $t6, 0x10($sp)
  addiu $a0, %lo(__osEepromTimer) # addiu $a0, $a0, 0x7ce8
  lw    $a3, 0x34($sp)
  lw    $a2, 0x30($sp)
  sw    $t5, 0x18($sp)
  jal   osSetTimer
   sw    $t8, 0x1c($sp)
  lui   $a0, %hi(__osEepromTimerQ)
  addiu $a0, %lo(__osEepromTimerQ) # addiu $a0, $a0, 0x7d08
  move  $a1, $zero
  jal   osRecvMesg
   li    $a2, 1
  lw    $t9, 0x4c($sp)
  bgtz  $t9, .L7001599C
   nop   
.L70015A88:
  lw    $v0, 0x3c($sp)
.L70015A8C:
  lw    $ra, 0x24($sp)
  addiu $sp, $sp, 0x40
  jr    $ra
   nop   

  nop   
glabel osPfsIsPlug
  addiu $sp, $sp, -0x40
  sw    $ra, 0x14($sp)
  li    $t6, 3
  sw    $a0, 0x40($sp)
  sw    $a1, 0x44($sp)
  sw    $zero, 0x3c($sp)
  sb    $zero, 0x1f($sp)
  jal   __osSiGetAccess
   sw    $t6, 0x18($sp)
.L70015AC4:
  jal   __osPfsRequestData
   move  $a0, $zero
  lui   $a1, %hi(__osPfsPifRam)
  addiu $a1, %lo(__osPfsPifRam) # addiu $a1, $a1, 0x7d70
  jal   __osSiRawStartDma
   li    $a0, 1
  sw    $v0, 0x3c($sp)
  lw    $a0, 0x40($sp)
  addiu $a1, $sp, 0x38
  jal   osRecvMesg
   li    $a2, 1
  lui   $a1, %hi(__osPfsPifRam)
  addiu $a1, %lo(__osPfsPifRam) # addiu $a1, $a1, 0x7d70
  jal   __osSiRawStartDma
   move  $a0, $zero
  sw    $v0, 0x3c($sp)
  lw    $a0, 0x40($sp)
  addiu $a1, $sp, 0x38
  jal   osRecvMesg
   li    $a2, 1
  addiu $a0, $sp, 0x37
  jal   __osPfsGetInitData
   addiu $a1, $sp, 0x24
  lui   $t7, %hi(__osMaxControllers) 
  lbu   $t7, %lo(__osMaxControllers)($t7)
  sw    $zero, 0x20($sp)
  blez  $t7, .L70015B80
   nop   
.L70015B34:
  lw    $t8, 0x20($sp)
  sll   $t9, $t8, 2
  addu  $t0, $sp, $t9
  lbu   $t0, 0x26($t0)
  andi  $t1, $t0, 4
  bnez  $t1, .L70015B60
   nop   
  lw    $t2, 0x18($sp)
  addiu $t3, $t2, -1
  b     .L70015B80
   sw    $t3, 0x18($sp)
.L70015B60:
  lw    $t4, 0x20($sp)
  lui   $t6, %hi(__osMaxControllers) 
  lbu   $t6, %lo(__osMaxControllers)($t6)
  addiu $t5, $t4, 1
  sw    $t5, 0x20($sp)
  slt   $at, $t5, $t6
  bnez  $at, .L70015B34
   nop   
.L70015B80:
  lui   $t7, %hi(__osMaxControllers) 
  lbu   $t7, %lo(__osMaxControllers)($t7)
  lw    $t8, 0x20($sp)
  bne   $t7, $t8, .L70015B98
   nop   
  sw    $zero, 0x18($sp)
.L70015B98:
  lw    $t9, 0x18($sp)
  bgtz  $t9, .L70015AC4
   nop   
  lui   $t0, %hi(__osMaxControllers) 
  lbu   $t0, %lo(__osMaxControllers)($t0)
  sw    $zero, 0x20($sp)
  blez  $t0, .L70015C18
   nop   
.L70015BB8:
  lw    $t1, 0x20($sp)
  addiu $t3, $sp, 0x24
  sll   $t2, $t1, 2
  addu  $t4, $t2, $t3
  lbu   $t5, 3($t4)
  bnez  $t5, .L70015BF8
   nop   
  lbu   $t6, 2($t4)
  andi  $t7, $t6, 1
  beqz  $t7, .L70015BF8
   nop   
  lbu   $t8, 0x1f($sp)
  li    $t9, 1
  sllv  $t0, $t9, $t1
  or    $t2, $t8, $t0
  sb    $t2, 0x1f($sp)
.L70015BF8:
  lw    $t3, 0x20($sp)
  lui   $t4, %hi(__osMaxControllers) 
  lbu   $t4, %lo(__osMaxControllers)($t4)
  addiu $t5, $t3, 1
  sw    $t5, 0x20($sp)
  slt   $at, $t5, $t4
  bnez  $at, .L70015BB8
   nop   
.L70015C18:
  jal   __osSiRelAccess
   nop   
  lbu   $t6, 0x1f($sp)
  lw    $t7, 0x44($sp)
  sb    $t6, ($t7)
  lw    $ra, 0x14($sp)
  lw    $v0, 0x3c($sp)
  addiu $sp, $sp, 0x40
  jr    $ra
   nop   

glabel __osPfsRequestData
  addiu $sp, $sp, -0x10
  andi  $a0, $a0, 0xff
  lui   $at, %hi(__osContLastCmd)
  sb    $a0, %lo(__osContLastCmd)($at)
  sw    $zero, ($sp)
.L70015C54:
  lw    $t6, ($sp)
  lw    $t8, ($sp)
  lui   $at, %hi(__osPfsPifRam)
  sll   $t7, $t6, 2
  addu  $at, $at, $t7
  sw    $zero, %lo(__osPfsPifRam)($at)
  addiu $t9, $t8, 1
  slti  $at, $t9, 0x10
  bnez  $at, .L70015C54
   sw    $t9, ($sp)
  lui   $t9, %hi(__osMaxControllers) 
  lbu   $t9, %lo(__osMaxControllers)($t9)
  lui   $t1, %hi(__osPfsPifRam) 
  li    $t0, 1
  lui   $at, %hi(__osPfsPifRam+0x3c)
  addiu $t1, %lo(__osPfsPifRam) # addiu $t1, $t1, 0x7d70
  li    $t2, 255
  li    $t3, 1
  li    $t4, 3
  li    $t5, 255
  li    $t6, 255
  li    $t7, 255
  li    $t8, 255
  sw    $t0, %lo(__osPfsPifRam+0x3c)($at)
  sw    $t1, 0xc($sp)
  sb    $t2, 4($sp)
  sb    $t3, 5($sp)
  sb    $t4, 6($sp)
  sb    $a0, 7($sp)
  sb    $t5, 8($sp)
  sb    $t6, 9($sp)
  sb    $t7, 0xa($sp)
  sb    $t8, 0xb($sp)
  blez  $t9, .L70015D28
   sw    $zero, ($sp)
.L70015CE0:
  addiu $t1, $sp, 4
  lw    $at, ($t1)
  lw    $t0, 0xc($sp)
  lui   $t8, %hi(__osMaxControllers) 
  swl   $at, ($t0)
  swr   $at, 3($t0)
  lw    $t3, 4($t1)
  swl   $t3, 4($t0)
  swr   $t3, 7($t0)
  lw    $t6, ($sp)
  lbu   $t8, %lo(__osMaxControllers)($t8)
  lw    $t4, 0xc($sp)
  addiu $t7, $t6, 1
  slt   $at, $t7, $t8
  addiu $t5, $t4, 8
  sw    $t7, ($sp)
  bnez  $at, .L70015CE0
   sw    $t5, 0xc($sp)
.L70015D28:
  lw    $t2, 0xc($sp)
  li    $t9, 254
  addiu $sp, $sp, 0x10
  jr    $ra
   sb    $t9, ($t2)

glabel __osPfsGetInitData
  lui   $t7, %hi(__osMaxControllers) 
  lbu   $t7, %lo(__osMaxControllers)($t7)
  addiu $sp, $sp, -0x18
  lui   $t6, %hi(__osPfsPifRam) 
  addiu $t6, %lo(__osPfsPifRam) # addiu $t6, $t6, 0x7d70
  sb    $zero, 7($sp)
  sw    $t6, 0x14($sp)
  blez  $t7, .L70015DFC
   sw    $zero, 8($sp)
.L70015D60:
  lw    $t9, 0x14($sp)
  addiu $t8, $sp, 0xc
  lwl   $at, ($t9)
  lwr   $at, 3($t9)
  sw    $at, ($t8)
  lwl   $t1, 4($t9)
  lwr   $t1, 7($t9)
  sw    $t1, 4($t8)
  lbu   $t2, 0xe($sp)
  andi  $t3, $t2, 0xc0
  sra   $t4, $t3, 4
  sb    $t4, 3($a1)
  lbu   $t5, 3($a1)
  bnez  $t5, .L70015DD0
   nop   
  lbu   $t6, 0x11($sp)
  lbu   $t0, 0x10($sp)
  li    $t3, 1
  sll   $t7, $t6, 8
  or    $t8, $t7, $t0
  sh    $t8, ($a1)
  lbu   $t9, 0x12($sp)
  sb    $t9, 2($a1)
  lw    $t2, 8($sp)
  lbu   $t1, 7($sp)
  sllv  $t4, $t3, $t2
  or    $t5, $t1, $t4
  sb    $t5, 7($sp)
.L70015DD0:
  lw    $t6, 8($sp)
  lui   $t9, %hi(__osMaxControllers) 
  lbu   $t9, %lo(__osMaxControllers)($t9)
  lw    $t0, 0x14($sp)
  addiu $t7, $t6, 1
  slt   $at, $t7, $t9
  addiu $t8, $t0, 8
  sw    $t8, 0x14($sp)
  sw    $t7, 8($sp)
  bnez  $at, .L70015D60
   addiu $a1, $a1, 4
.L70015DFC:
  lbu   $t3, 7($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   sb    $t3, ($a0)

  nop   
.section .bss
glabel __osPfsPifRam
.byte 0, 0, 0, 0
.byte 0, 0, 0, 0
.byte 0, 0, 0, 0
.byte 0, 0, 0, 0
.byte 0, 0, 0, 0
.byte 0, 0, 0, 0
.byte 0, 0, 0, 0
.byte 0, 0, 0, 0
.byte 0, 0, 0, 0
.byte 0, 0, 0, 0
.byte 0, 0, 0, 0
.byte 0, 0, 0, 0
.byte 0, 0, 0, 0
.byte 0, 0, 0, 0
.byte 0, 0, 0, 0
.byte 0, 0, 0, 0



.section .text
glabel __osSiCreateAccessQueue
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  li    $t6, 1
  lui   $at, %hi(__osSiAccessQueueEnabled)
  lui   $a0, %hi(__osSiAccessQueue)
  lui   $a1, %hi(__osSiAccessBuf)
  sw    $t6, %lo(__osSiAccessQueueEnabled)($at)
  addiu $a1, %lo(__osSiAccessBuf) # addiu $a1, $a1, 0x7db0
  addiu $a0, %lo(__osSiAccessQueue) # addiu $a0, $a0, 0x7db8
  jal   osCreateMesgQueue
   li    $a2, 1
  lui   $a0, %hi(__osSiAccessQueue)
  addiu $a0, %lo(__osSiAccessQueue) # addiu $a0, $a0, 0x7db8
  move  $a1, $zero
  jal   osSendMesg
   move  $a2, $zero
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   

glabel __osSiGetAccess
  lui   $t6, %hi(__osSiAccessQueueEnabled) 
  lw    $t6, %lo(__osSiAccessQueueEnabled)($t6)
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  bnez  $t6, .L70015E80
   nop   
  jal   __osSiCreateAccessQueue
   nop   
.L70015E80:
  lui   $a0, %hi(__osSiAccessQueue)
  addiu $a0, %lo(__osSiAccessQueue) # addiu $a0, $a0, 0x7db8
  addiu $a1, $sp, 0x1c
  jal   osRecvMesg
   li    $a2, 1
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   

glabel __osSiRelAccess
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lui   $a0, %hi(__osSiAccessQueue)
  addiu $a0, %lo(__osSiAccessQueue) # addiu $a0, $a0, 0x7db8
  move  $a1, $zero
  jal   osSendMesg
   move  $a2, $zero
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   

.section .data
__osSiAccessQueueEnabled:
glabel __osSiAccessQueueEnabled
.word 0

.align 4
.section .bss
glabel __osSiAccessBuf
.word 0, 0
glabel __osSiAccessQueue
.byte 0, 0, 0, 0
.byte 0, 0, 0, 0
.byte 0, 0, 0, 0
.byte 0, 0, 0, 0
.byte 0, 0, 0, 0
.byte 0, 0, 0, 0

.section .text
glabel __osSiRawStartDma
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  jal   __osSiDeviceBusy
   sw    $a1, 0x1c($sp)
  beqz  $v0, .L70015EF4
   nop   
  b     .L70015F6C
   li    $v0, -1
.L70015EF4:
  lw    $t6, 0x18($sp)
  li    $at, 1
  bne   $t6, $at, .L70015F10
   nop   
  lw    $a0, 0x1c($sp)
  jal   osWritebackDCache
   li    $a1, 64
.L70015F10:
  jal   osVirtualToPhysical
   lw    $a0, 0x1c($sp)
  lui   $t7, 0xa480
  sw    $v0, ($t7)
  lw    $t8, 0x18($sp)
  bnez  $t8, .L70015F40
   nop   
  lui   $t9, (0x1FC007C0 >> 16) # lui $t9, 0x1fc0
  ori   $t9, (0x1FC007C0 & 0xFFFF) # ori $t9, $t9, 0x7c0
  lui   $t0, %hi(SI_PIF_ADDR_RD64B_REG) # $t0, 0xa480
  b     .L70015F50
   sw    $t9, %lo(SI_PIF_ADDR_RD64B_REG)($t0)
.L70015F40:
  lui   $t1, (0x1FC007C0 >> 16) # lui $t1, 0x1fc0
  ori   $t1, (0x1FC007C0 & 0xFFFF) # ori $t1, $t1, 0x7c0
  lui   $t2, %hi(SI_PIF_ADDR_WR64B_REG) # $t2, 0xa480
  sw    $t1, %lo(SI_PIF_ADDR_WR64B_REG)($t2)
.L70015F50:
  lw    $t3, 0x18($sp)
  bnez  $t3, .L70015F68
   nop   
  lw    $a0, 0x1c($sp)
  jal   osInvalDCache
   li    $a1, 64
.L70015F68:
  move  $v0, $zero
.L70015F6C:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   

  nop   
glabel __osContAddressCrc
  addiu $sp, $sp, -0x10
  andi  $a0, $a0, 0xffff
  sb    $zero, 0xf($sp)
  sw    $zero, 8($sp)
.L70015F90:
  lbu   $t6, 0xf($sp)
  andi  $t7, $t6, 0x10
  beqz  $t7, .L70015FAC
   nop   
  li    $t8, 21
  b     .L70015FB0
   sb    $t8, 0xe($sp)
.L70015FAC:
  sb    $zero, 0xe($sp)
.L70015FB0:
  lbu   $t9, 0xf($sp)
  andi  $t1, $a0, 0x400
  sll   $t0, $t9, 1
  beqz  $t1, .L70015FCC
   sb    $t0, 0xf($sp)
  b     .L70015FD0
   li    $a1, 1
.L70015FCC:
  move  $a1, $zero
.L70015FD0:
  lbu   $t2, 0xf($sp)
  lw    $t0, 8($sp)
  lbu   $t7, 0xe($sp)
  andi  $t3, $a1, 0xff
  sll   $t5, $a0, 1
  or    $t4, $t2, $t3
  move  $a0, $t5
  andi  $t8, $t4, 0xff
  addiu $t1, $t0, 1
  slti  $at, $t1, 0x10
  sb    $t4, 0xf($sp)
  andi  $t6, $a0, 0xffff
  xor   $t9, $t8, $t7
  sw    $t1, 8($sp)
  move  $a0, $t6
  bnez  $at, .L70015F90
   sb    $t9, 0xf($sp)
  lbu   $v0, 0xf($sp)
  addiu $sp, $sp, 0x10
  andi  $t2, $v0, 0x1f
  move  $v0, $t2
  andi  $t3, $v0, 0xff
  jr    $ra
   move  $v0, $t3

glabel __osContDataCrc
  addiu $sp, $sp, -0x10
  sb    $zero, 0xf($sp)
  sw    $zero, 8($sp)
.L7001603C:
  li    $t6, 7
  sw    $t6, 4($sp)
.L70016044:
  lbu   $t7, 0xf($sp)
  andi  $t8, $t7, 0x80
  beqz  $t8, .L70016060
   nop   
  li    $t9, 133
  b     .L70016064
   sb    $t9, 0xe($sp)
.L70016060:
  sb    $zero, 0xe($sp)
.L70016064:
  lbu   $t0, 0xf($sp)
  lw    $t2, 8($sp)
  li    $at, 32
  sll   $t1, $t0, 1
  bne   $t2, $at, .L70016088
   sb    $t1, 0xf($sp)
  andi  $t3, $t1, 0xff
  b     .L700160BC
   sb    $t3, 0xf($sp)
.L70016088:
  lw    $t5, 4($sp)
  lbu   $t4, ($a0)
  li    $t6, 1
  sllv  $t7, $t6, $t5
  and   $t8, $t4, $t7
  beqz  $t8, .L700160AC
   nop   
  b     .L700160B0
   li    $a1, 1
.L700160AC:
  move  $a1, $zero
.L700160B0:
  lbu   $t9, 0xf($sp)
  or    $t0, $t9, $a1
  sb    $t0, 0xf($sp)
.L700160BC:
  lw    $t6, 4($sp)
  lbu   $t2, 0xf($sp)
  lbu   $t1, 0xe($sp)
  addiu $t5, $t6, -1
  sw    $t5, 4($sp)
  xor   $t3, $t2, $t1
  bgez  $t5, .L70016044
   sb    $t3, 0xf($sp)
  lw    $t4, 8($sp)
  addiu $a0, $a0, 1
  addiu $t7, $t4, 1
  slti  $at, $t7, 0x21
  bnez  $at, .L7001603C
   sw    $t7, 8($sp)
  lbu   $v0, 0xf($sp)
  jr    $ra
   addiu $sp, $sp, 0x10

glabel __osContRamWrite
  addiu $sp, $sp, -0x60
  lw    $t8, 0x70($sp)
  lui   $t6, %hi(__osPfsPifRam) 
  addiu $t6, %lo(__osPfsPifRam) # addiu $t6, $t6, 0x7d70
  li    $t7, 2
  li    $at, 1
  sw    $ra, 0x1c($sp)
  sw    $a0, 0x60($sp)
  sw    $a1, 0x64($sp)
  sw    $a2, 0x68($sp)
  sw    $a3, 0x6c($sp)
  sw    $s0, 0x18($sp)
  sw    $zero, 0x5c($sp)
  sw    $t6, 0x54($sp)
  beq   $t8, $at, .L70016160
   sw    $t7, 0x28($sp)
  lhu   $t9, 0x6a($sp)
  slti  $at, $t9, 7
  beqz  $at, .L70016160
   nop   
  beqz  $t9, .L70016160
   nop   
  b     .L7001631C
   move  $v0, $zero
.L70016160:
  jal   __osSiGetAccess
   nop   
  li    $t0, 3
  lui   $at, %hi(__osContLastCmd)
  sb    $t0, %lo(__osContLastCmd)($at)
  lw    $a0, 0x64($sp)
  lhu   $a1, 0x6a($sp)
  jal   __osContRamWrite_sub
   lw    $a2, 0x6c($sp)
  lui   $a1, %hi(__osPfsPifRam)
  addiu $a1, %lo(__osPfsPifRam) # addiu $a1, $a1, 0x7d70
  jal   __osSiRawStartDma
   li    $a0, 1
  sw    $v0, 0x5c($sp)
  lw    $a0, 0x60($sp)
  move  $a1, $zero
  jal   osRecvMesg
   li    $a2, 1
.L700161A8:
  sw    $zero, 0x58($sp)
.L700161AC:
  lw    $t2, 0x58($sp)
  lw    $t4, 0x58($sp)
  lui   $at, %hi(__osPfsPifRam)
  sll   $t3, $t2, 2
  addu  $at, $at, $t3
  li    $t1, 255
  sw    $t1, %lo(__osPfsPifRam)($at)
  addiu $t5, $t4, 1
  slti  $at, $t5, 0x10
  bnez  $at, .L700161AC
   sw    $t5, 0x58($sp)
  lui   $at, %hi(__osPfsPifRam+0x3c)
  lui   $a1, %hi(__osPfsPifRam)
  sw    $zero, %lo(__osPfsPifRam+0x3c)($at)
  addiu $a1, %lo(__osPfsPifRam) # addiu $a1, $a1, 0x7d70
  jal   __osSiRawStartDma
   move  $a0, $zero
  sw    $v0, 0x5c($sp)
  lw    $a0, 0x60($sp)
  move  $a1, $zero
  jal   osRecvMesg
   li    $a2, 1
  lw    $t7, 0x64($sp)
  lui   $t6, %hi(__osPfsPifRam) 
  addiu $t6, %lo(__osPfsPifRam) # addiu $t6, $t6, 0x7d70
  beqz  $t7, .L70016244
   sw    $t6, 0x54($sp)
  blez  $t7, .L70016244
   sw    $zero, 0x58($sp)
.L70016220:
  lw    $t0, 0x58($sp)
  lw    $t1, 0x64($sp)
  lw    $t8, 0x54($sp)
  addiu $t2, $t0, 1
  slt   $at, $t2, $t1
  addiu $t9, $t8, 1
  sw    $t2, 0x58($sp)
  bnez  $at, .L70016220
   sw    $t9, 0x54($sp)
.L70016244:
  lw    $t4, 0x54($sp)
  addiu $t3, $sp, 0x2c
  addiu $t6, $t4, 0x24
.L70016250:
  lwl   $at, ($t4)
  lwr   $at, 3($t4)
  addiu $t4, $t4, 0xc
  addiu $t3, $t3, 0xc
  sw    $at, -0xc($t3)
  lwl   $at, -8($t4)
  lwr   $at, -5($t4)
  sw    $at, -8($t3)
  lwl   $at, -4($t4)
  lwr   $at, -1($t4)
  bne   $t4, $t6, .L70016250
   sw    $at, -4($t3)
  lwl   $at, ($t4)
  lwr   $at, 3($t4)
  sw    $at, ($t3)
  lbu   $t7, 0x2e($sp)
  andi  $t8, $t7, 0xc0
  sra   $t9, $t8, 4
  bnez  $t9, .L700162E8
   sw    $t9, 0x5c($sp)
  jal   __osContDataCrc
   lw    $a0, 0x6c($sp)
  lbu   $t0, 0x52($sp)
  beq   $v0, $t0, .L700162E8
   nop   
  lw    $a0, 0x60($sp)
  jal   __osPfsGetStatus
   lw    $a1, 0x64($sp)
  sw    $v0, 0x5c($sp)
  lw    $t2, 0x5c($sp)
  beqz  $t2, .L700162E0
   nop   
  jal   __osSiRelAccess
   nop   
  b     .L7001631C
   lw    $v0, 0x5c($sp)
.L700162E0:
  li    $t1, 4
  sw    $t1, 0x5c($sp)
.L700162E8:
  lw    $t5, 0x5c($sp)
  li    $at, 4
  bne   $t5, $at, .L70016310
   nop   
  lw    $t6, 0x28($sp)
  slti  $s0, $t6, 0
  xori  $s0, $s0, 1
  addiu $t4, $t6, -1
  bnez  $s0, .L700161A8
   sw    $t4, 0x28($sp)
.L70016310:
  jal   __osSiRelAccess
   nop   
  lw    $v0, 0x5c($sp)
.L7001631C:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x60
  jr    $ra
   nop   

glabel __osContRamWrite_sub
  addiu $sp, $sp, -0x48
  lui   $t6, %hi(__osPfsPifRam) 
  addiu $t6, %lo(__osPfsPifRam) # addiu $t6, $t6, 0x7d70
  sw    $ra, 0x14($sp)
  sw    $a0, 0x48($sp)
  sw    $a1, 0x4c($sp)
  sw    $a2, 0x50($sp)
  sw    $t6, 0x44($sp)
  sw    $zero, 0x18($sp)
.L70016354:
  lw    $t7, 0x18($sp)
  lw    $t9, 0x18($sp)
  lui   $at, %hi(__osPfsPifRam)
  sll   $t8, $t7, 2
  addu  $at, $at, $t8
  sw    $zero, %lo(__osPfsPifRam)($at)
  addiu $t0, $t9, 1
  slti  $at, $t0, 0x10
  bnez  $at, .L70016354
   sw    $t0, 0x18($sp)
  li    $t1, 1
  lui   $at, %hi(__osPfsPifRam+0x3c)
  li    $t2, 255
  li    $t3, 35
  li    $t4, 1
  li    $t5, 3
  sw    $t1, %lo(__osPfsPifRam+0x3c)($at)
  sb    $t2, 0x1c($sp)
  sb    $t3, 0x1d($sp)
  sb    $t4, 0x1e($sp)
  sb    $t5, 0x1f($sp)
  jal   __osContAddressCrc
   lhu   $a0, 0x4e($sp)
  lhu   $t6, 0x4e($sp)
  li    $t9, 255
  sb    $t9, 0x42($sp)
  sll   $t7, $t6, 5
  or    $t8, $v0, $t7
  sh    $t8, 0x20($sp)
  sw    $zero, 0x18($sp)
.L700163CC:
  lw    $t0, 0x50($sp)
  lw    $t2, 0x18($sp)
  lbu   $t1, ($t0)
  addu  $t3, $sp, $t2
  sb    $t1, 0x22($t3)
  lw    $t6, 0x18($sp)
  lw    $t4, 0x50($sp)
  addiu $t7, $t6, 1
  slti  $at, $t7, 0x20
  addiu $t5, $t4, 1
  sw    $t7, 0x18($sp)
  bnez  $at, .L700163CC
   sw    $t5, 0x50($sp)
  lw    $t8, 0x48($sp)
  beqz  $t8, .L70016440
   nop   
  blez  $t8, .L70016440
   sw    $zero, 0x18($sp)
.L70016414:
  lw    $t9, 0x44($sp)
  sb    $zero, ($t9)
  lw    $t2, 0x18($sp)
  lw    $t4, 0x48($sp)
  lw    $t0, 0x44($sp)
  addiu $t3, $t2, 1
  slt   $at, $t3, $t4
  addiu $t1, $t0, 1
  sw    $t3, 0x18($sp)
  bnez  $at, .L70016414
   sw    $t1, 0x44($sp)
.L70016440:
  addiu $t6, $sp, 0x1c
  addiu $t8, $t6, 0x24
  lw    $t5, 0x44($sp)
.L7001644C:
  lw    $at, ($t6)
  addiu $t6, $t6, 0xc
  addiu $t5, $t5, 0xc
  swl   $at, -0xc($t5)
  swr   $at, -9($t5)
  lw    $at, -8($t6)
  swl   $at, -8($t5)
  swr   $at, -5($t5)
  lw    $at, -4($t6)
  swl   $at, -4($t5)
  bne   $t6, $t8, .L7001644C
   swr   $at, -1($t5)
  lw    $at, ($t6)
  li    $t1, 254
  swl   $at, ($t5)
  swr   $at, 3($t5)
  lw    $t9, 0x44($sp)
  addiu $t0, $t9, 0x28
  sw    $t0, 0x44($sp)
  sb    $t1, ($t0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x48
  jr    $ra
   nop   

  nop   

glabel __osContRamRead
  addiu $sp, $sp, -0x60
  lui   $t6, %hi(__osPfsPifRam) 
  sw    $ra, 0x1c($sp)
  addiu $t6, %lo(__osPfsPifRam) # addiu $t6, $t6, 0x7d70
  li    $t7, 2
  sw    $a0, 0x60($sp)
  sw    $a1, 0x64($sp)
  sw    $a2, 0x68($sp)
  sw    $a3, 0x6c($sp)
  sw    $s0, 0x18($sp)
  sw    $zero, 0x5c($sp)
  sw    $t6, 0x54($sp)
  jal   __osSiGetAccess
   sw    $t7, 0x28($sp)
  li    $t8, 2
  lui   $at, %hi(__osContLastCmd)
  sb    $t8, %lo(__osContLastCmd)($at)
  lw    $a0, 0x64($sp)
  jal   __osContRamRead_sub
   lhu   $a1, 0x6a($sp)
  lui   $a1, %hi(__osPfsPifRam)
  addiu $a1, %lo(__osPfsPifRam) # addiu $a1, $a1, 0x7d70
  jal   __osSiRawStartDma
   li    $a0, 1
  sw    $v0, 0x5c($sp)
  lw    $a0, 0x60($sp)
  move  $a1, $zero
  jal   osRecvMesg
   li    $a2, 1
.L70016524:
  sw    $zero, 0x58($sp)
.L70016528:
  lw    $t0, 0x58($sp)
  lw    $t2, 0x58($sp)
  lui   $at, %hi(__osPfsPifRam)
  sll   $t1, $t0, 2
  addu  $at, $at, $t1
  li    $t9, 255
  sw    $t9, %lo(__osPfsPifRam)($at)
  addiu $t3, $t2, 1
  slti  $at, $t3, 0x10
  bnez  $at, .L70016528
   sw    $t3, 0x58($sp)
  lui   $at, %hi(__osPfsPifRam+0x3c)
  lui   $a1, %hi(__osPfsPifRam)
  sw    $zero, %lo(__osPfsPifRam+0x3c)($at)
  addiu $a1, %lo(__osPfsPifRam) # addiu $a1, $a1, 0x7d70
  jal   __osSiRawStartDma
   move  $a0, $zero
  sw    $v0, 0x5c($sp)
  lw    $a0, 0x60($sp)
  move  $a1, $zero
  jal   osRecvMesg
   li    $a2, 1
  lw    $t5, 0x64($sp)
  lui   $t4, %hi(__osPfsPifRam) 
  addiu $t4, %lo(__osPfsPifRam) # addiu $t4, $t4, 0x7d70
  beqz  $t5, .L700165C0
   sw    $t4, 0x54($sp)
  blez  $t5, .L700165C0
   sw    $zero, 0x58($sp)
.L7001659C:
  lw    $t8, 0x58($sp)
  lw    $t9, 0x64($sp)
  lw    $t6, 0x54($sp)
  addiu $t0, $t8, 1
  slt   $at, $t0, $t9
  addiu $t7, $t6, 1
  sw    $t0, 0x58($sp)
  bnez  $at, .L7001659C
   sw    $t7, 0x54($sp)
.L700165C0:
  lw    $t2, 0x54($sp)
  addiu $t1, $sp, 0x2c
  addiu $t4, $t2, 0x24
.L700165CC:
  lwl   $at, ($t2)
  lwr   $at, 3($t2)
  addiu $t2, $t2, 0xc
  addiu $t1, $t1, 0xc
  sw    $at, -0xc($t1)
  lwl   $at, -8($t2)
  lwr   $at, -5($t2)
  sw    $at, -8($t1)
  lwl   $at, -4($t2)
  lwr   $at, -1($t2)
  bne   $t2, $t4, .L700165CC
   sw    $at, -4($t1)
  lwl   $at, ($t2)
  lwr   $at, 3($t2)
  sw    $at, ($t1)
  lbu   $t5, 0x2e($sp)
  andi  $t6, $t5, 0xc0
  sra   $t7, $t6, 4
  bnez  $t7, .L700166AC
   sw    $t7, 0x5c($sp)
  addiu $a0, $sp, 0x2c
  jal   __osContDataCrc
   addiu $a0, $a0, 6
  sb    $v0, 0x27($sp)
  lbu   $t8, 0x27($sp)
  lbu   $t0, 0x52($sp)
  beq   $t8, $t0, .L70016674
   nop   
  lw    $a0, 0x60($sp)
  jal   __osPfsGetStatus
   lw    $a1, 0x64($sp)
  sw    $v0, 0x5c($sp)
  lw    $t9, 0x5c($sp)
  beqz  $t9, .L70016668
   nop   
  jal   __osSiRelAccess
   nop   
  b     .L700166E0
   lw    $v0, 0x5c($sp)
.L70016668:
  li    $t3, 4
  b     .L700166AC
   sw    $t3, 0x5c($sp)
.L70016674:
  sw    $zero, 0x58($sp)
.L70016678:
  lw    $t4, 0x58($sp)
  lw    $t1, 0x6c($sp)
  addu  $t2, $sp, $t4
  lbu   $t2, 0x32($t2)
  sb    $t2, ($t1)
  lw    $t7, 0x58($sp)
  lw    $t5, 0x6c($sp)
  addiu $t8, $t7, 1
  slti  $at, $t8, 0x20
  addiu $t6, $t5, 1
  sw    $t8, 0x58($sp)
  bnez  $at, .L70016678
   sw    $t6, 0x6c($sp)
.L700166AC:
  lw    $t0, 0x5c($sp)
  li    $at, 4
  bne   $t0, $at, .L700166D4
   nop   
  lw    $t9, 0x28($sp)
  slti  $s0, $t9, 0
  xori  $s0, $s0, 1
  addiu $t3, $t9, -1
  bnez  $s0, .L70016524
   sw    $t3, 0x28($sp)
.L700166D4:
  jal   __osSiRelAccess
   nop   
  lw    $v0, 0x5c($sp)
.L700166E0:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x60
  jr    $ra
   nop   

glabel __osContRamRead_sub
  addiu $sp, $sp, -0x48
  lui   $t6, %hi(__osPfsPifRam) 
  addiu $t6, %lo(__osPfsPifRam) # addiu $t6, $t6, 0x7d70
  sw    $ra, 0x14($sp)
  sw    $a0, 0x48($sp)
  sw    $a1, 0x4c($sp)
  sw    $t6, 0x44($sp)
  sw    $zero, 0x18($sp)
.L70016714:
  lw    $t7, 0x18($sp)
  lw    $t9, 0x18($sp)
  lui   $at, %hi(__osPfsPifRam)
  sll   $t8, $t7, 2
  addu  $at, $at, $t8
  sw    $zero, %lo(__osPfsPifRam)($at)
  addiu $t0, $t9, 1
  slti  $at, $t0, 0x10
  bnez  $at, .L70016714
   sw    $t0, 0x18($sp)
  li    $t1, 1
  lui   $at, %hi(__osPfsPifRam+0x3c)
  li    $t2, 255
  li    $t3, 3
  li    $t4, 33
  li    $t5, 2
  sw    $t1, %lo(__osPfsPifRam+0x3c)($at)
  sb    $t2, 0x1c($sp)
  sb    $t3, 0x1d($sp)
  sb    $t4, 0x1e($sp)
  sb    $t5, 0x1f($sp)
  jal   __osContAddressCrc
   lhu   $a0, 0x4e($sp)
  lhu   $t6, 0x4e($sp)
  li    $t9, 255
  sb    $t9, 0x42($sp)
  sll   $t7, $t6, 5
  or    $t8, $v0, $t7
  sh    $t8, 0x20($sp)
  sw    $zero, 0x18($sp)
.L7001678C:
  lw    $t1, 0x18($sp)
  li    $t0, 255
  addu  $t2, $sp, $t1
  sb    $t0, 0x22($t2)
  lw    $t3, 0x18($sp)
  addiu $t4, $t3, 1
  slti  $at, $t4, 0x20
  bnez  $at, .L7001678C
   sw    $t4, 0x18($sp)
  lw    $t5, 0x48($sp)
  beqz  $t5, .L700167F0
   nop   
  blez  $t5, .L700167F0
   sw    $zero, 0x18($sp)
.L700167C4:
  lw    $t6, 0x44($sp)
  sb    $zero, ($t6)
  lw    $t9, 0x18($sp)
  lw    $t1, 0x48($sp)
  lw    $t7, 0x44($sp)
  addiu $t0, $t9, 1
  slt   $at, $t0, $t1
  addiu $t8, $t7, 1
  sw    $t0, 0x18($sp)
  bnez  $at, .L700167C4
   sw    $t8, 0x44($sp)
.L700167F0:
  addiu $t3, $sp, 0x1c
  addiu $t5, $t3, 0x24
  lw    $t2, 0x44($sp)
.L700167FC:
  lw    $at, ($t3)
  addiu $t3, $t3, 0xc
  addiu $t2, $t2, 0xc
  swl   $at, -0xc($t2)
  swr   $at, -9($t2)
  lw    $at, -8($t3)
  swl   $at, -8($t2)
  swr   $at, -5($t2)
  lw    $at, -4($t3)
  swl   $at, -4($t2)
  bne   $t3, $t5, .L700167FC
   swr   $at, -1($t2)
  lw    $at, ($t3)
  li    $t8, 254
  swl   $at, ($t2)
  swr   $at, 3($t2)
  lw    $t6, 0x44($sp)
  addiu $t7, $t6, 0x28
  sw    $t7, 0x44($sp)
  sb    $t8, ($t7)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x48
  jr    $ra
   nop   

  nop   

glabel guAlignF
  addiu $sp, $sp, -0x30
  lui   $at, %hi(F32_800297F0)
  lwc1  $f4, %lo(F32_800297F0)($at)
  sw    $s0, 0x18($sp)
  move  $s0, $a0
  lui   $at, %hi(flt_CODE_bss_80067DD0)
  sw    $ra, 0x1c($sp)
  sw    $a1, 0x34($sp)
  sw    $a2, 0x38($sp)
  sw    $a3, 0x3c($sp)
  addiu $a2, $sp, 0x40
  addiu $a1, $sp, 0x3c
  addiu $a0, $sp, 0x38
  jal   guNormalize
   swc1  $f4, %lo(flt_CODE_bss_80067DD0)($at)
  lui    $at, %hi(flt_CODE_bss_80067DD0)
  lwc1  $f12, 0x34($sp)
  lwc1  $f6, %lo(flt_CODE_bss_80067DD0)($at)
  mul.s $f12, $f12, $f6
  jal   sinf
   swc1  $f12, 0x34($sp)
  lwc1  $f12, 0x34($sp)
  jal   cosf
   swc1  $f0, 0x2c($sp)
  lwc1  $f14, 0x38($sp)
  lwc1  $f18, 0x40($sp)
  swc1  $f0, 0x28($sp)
  mul.s $f8, $f14, $f14
  nop   
  mul.s $f10, $f18, $f18
  jal   sqrtf
   add.s $f12, $f8, $f10
  move  $a0, $s0
  jal   guMtxIdentF
   swc1  $f0, 0x24($sp)
  mtc1  $zero, $f12
  lwc1  $f14, 0x24($sp)
  lwc1  $f2, 0x28($sp)
  lwc1  $f16, 0x2c($sp)
  c.eq.s $f14, $f12
  li    $at, 0x3F800000 # 1.000000
  lwc1  $f6, 0x3c($sp)
  bc1tl .L70016A10
   lw    $ra, 0x1c($sp)
  mtc1  $at, $f4
  mul.s $f8, $f16, $f6
  lwc1  $f10, 0x38($sp)
  lwc1  $f6, 0x40($sp)
  div.s $f0, $f4, $f14
  mul.s $f4, $f8, $f10
  neg.s $f8, $f6
  mul.s $f10, $f8, $f2
  sub.s $f6, $f10, $f4
  mul.s $f8, $f6, $f0
  swc1  $f8, ($s0)
  lwc1  $f10, 0x3c($sp)
  lwc1  $f6, 0x38($sp)
  mul.s $f4, $f2, $f10
  lwc1  $f10, 0x40($sp)
  mul.s $f8, $f4, $f6
  nop   
  mul.s $f4, $f10, $f16
  sub.s $f6, $f4, $f8
  mul.s $f10, $f6, $f0
  swc1  $f10, 0x10($s0)
  mul.s $f6, $f16, $f14
  lwc1  $f4, 0x38($sp)
  swc1  $f12, 0x30($s0)
  mul.s $f10, $f2, $f14
  neg.s $f8, $f4
  swc1  $f8, 0x20($s0)
  swc1  $f6, 4($s0)
  swc1  $f10, 0x14($s0)
  lwc1  $f4, 0x3c($sp)
  swc1  $f12, 0x34($s0)
  neg.s $f8, $f4
  swc1  $f8, 0x24($s0)
  lwc1  $f6, 0x3c($sp)
  lwc1  $f4, 0x40($sp)
  mul.s $f10, $f16, $f6
  lwc1  $f6, 0x38($sp)
  mul.s $f8, $f10, $f4
  nop   
  mul.s $f10, $f2, $f6
  sub.s $f4, $f10, $f8
  neg.s $f10, $f16
  mul.s $f6, $f4, $f0
  swc1  $f6, 8($s0)
  lwc1  $f8, 0x38($sp)
  lwc1  $f6, 0x3c($sp)
  mul.s $f4, $f10, $f8
  lwc1  $f8, 0x40($sp)
  mul.s $f10, $f2, $f6
  nop   
  mul.s $f6, $f10, $f8
  sub.s $f10, $f4, $f6
  mul.s $f8, $f10, $f0
  mtc1  $at, $f10
  swc1  $f8, 0x18($s0)
  lwc1  $f4, 0x40($sp)
  swc1  $f12, 0x38($s0)
  swc1  $f12, 0xc($s0)
  neg.s $f6, $f4
  swc1  $f12, 0x1c($s0)
  swc1  $f6, 0x28($s0)
  swc1  $f12, 0x2c($s0)
  swc1  $f10, 0x3c($s0)
  lw    $ra, 0x1c($sp)
.L70016A10:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   

glabel guAlign
  mtc1  $a1, $f12
  mtc1  $a2, $f14
  mtc1  $a3, $f16
  addiu $sp, $sp, -0x60
  lwc1  $f4, 0x70($sp)
  sw    $ra, 0x1c($sp)
  sw    $a0, 0x60($sp)
  mfc1  $a1, $f12
  mfc1  $a2, $f14
  mfc1  $a3, $f16
  addiu $a0, $sp, 0x20
  jal   guAlignF
   swc1  $f4, 0x10($sp)
  addiu $a0, $sp, 0x20
  jal   guMtxF2L
   lw    $a1, 0x60($sp)
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x60
  jr    $ra
   nop

.section .rodata
glabel F32_800297F0
.float 0.017453292
.align 4

.section .bss
glabel flt_CODE_bss_80067DD0
.word 0
.word 0,0,0

.section .text
glabel guOrthoF
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a1, 0x1c($sp)
  sw    $a2, 0x20($sp)
  sw    $a3, 0x24($sp)
  jal   guMtxIdentF
   sw    $a0, 0x18($sp)
  lwc1  $f4, 0x20($sp)
  lwc1  $f6, 0x1c($sp)
  li    $at, 0x40000000 # 2.000000
  mtc1  $at, $f8
  sub.s $f0, $f4, $f6
  lw    $v0, 0x18($sp)
  lwc1  $f14, 0x28($sp)
  lwc1  $f16, 0x30($sp)
  div.s $f10, $f8, $f0
  lwc1  $f18, 0x2c($sp)
  mtc1  $at, $f6
  li    $at, 0xC0000000 # -2.000000
  sub.s $f12, $f16, $f18
  move  $v1, $zero
  li    $a0, 4
  swc1  $f10, ($v0)
  lwc1  $f4, 0x24($sp)
  mtc1  $at, $f10
  li    $at, 0x3F800000 # 1.000000
  sub.s $f2, $f14, $f4
  div.s $f4, $f10, $f12
  div.s $f8, $f6, $f2
  swc1  $f4, 0x28($v0)
  swc1  $f8, 0x14($v0)
  lwc1  $f8, 0x1c($sp)
  lwc1  $f6, 0x20($sp)
  add.s $f10, $f6, $f8
  neg.s $f4, $f10
  div.s $f6, $f4, $f0
  swc1  $f6, 0x30($v0)
  lwc1  $f8, 0x24($sp)
  add.s $f10, $f14, $f8
  add.s $f8, $f16, $f18
  neg.s $f4, $f10
  neg.s $f10, $f8
  div.s $f6, $f4, $f2
  div.s $f4, $f10, $f12
  swc1  $f6, 0x34($v0)
  mtc1  $at, $f6
  nop   
  swc1  $f6, 0x3c($v0)
  swc1  $f4, 0x38($v0)
  lwc1  $f0, 0x34($sp)
  lwc1  $f8, ($v0)
  addiu $v1, $v1, 1
  lwc1  $f18, 4($v0)
  mul.s $f12, $f8, $f0
  lwc1  $f14, 8($v0)
  beq   $v1, $a0, .L70016B90
   lwc1  $f16, 0xc($v0)
.L70016B54:
  mul.s $f10, $f18, $f0
  lwc1  $f8, 0x10($v0)
  lwc1  $f18, 0x14($v0)
  mul.s $f6, $f14, $f0
  lwc1  $f14, 0x18($v0)
  addiu $v1, $v1, 1
  mul.s $f4, $f16, $f0
  lwc1  $f16, 0x1c($v0)
  swc1  $f12, ($v0)
  mul.s $f12, $f8, $f0
  swc1  $f10, 4($v0)
  swc1  $f6, 8($v0)
  addiu $v0, $v0, 0x10
  bne   $v1, $a0, .L70016B54
   swc1  $f4, -4($v0)
.L70016B90:
  mul.s $f10, $f18, $f0
  addiu $v0, $v0, 0x10
  swc1  $f12, -0x10($v0)
  mul.s $f6, $f14, $f0
  nop   
  mul.s $f4, $f16, $f0
  swc1  $f10, -0xc($v0)
  swc1  $f6, -8($v0)
  swc1  $f4, -4($v0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   

glabel guOrtho
  addiu $sp, $sp, -0x68
  mtc1  $a1, $f12
  mtc1  $a2, $f14
  mtc1  $a3, $f16
  lwc1  $f4, 0x78($sp)
  lwc1  $f6, 0x7c($sp)
  lwc1  $f8, 0x80($sp)
  lwc1  $f10, 0x84($sp)
  sw    $ra, 0x24($sp)
  sw    $a0, 0x68($sp)
  mfc1  $a1, $f12
  mfc1  $a2, $f14
  mfc1  $a3, $f16
  addiu $a0, $sp, 0x28
  swc1  $f4, 0x10($sp)
  swc1  $f6, 0x14($sp)
  swc1  $f8, 0x18($sp)
  jal   guOrthoF
   swc1  $f10, 0x1c($sp)
  addiu $a0, $sp, 0x28
  jal   guMtxF2L
   lw    $a1, 0x68($sp)
  lw    $ra, 0x24($sp)
  addiu $sp, $sp, 0x68
  jr    $ra
   nop   

  nop   
glabel coss
  addiu $sp, $sp, -0x18
  sw    $a0, 0x18($sp)
  move  $a1, $a0
  addiu $a0, $a1, 0x4000
  sw    $ra, 0x14($sp)
  andi  $t6, $a0, 0xffff
  jal   sins
   move  $a0, $t6
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   

glabel sins
  andi  $t6, $a0, 0xffff
  srl   $t7, $t6, 4
  andi  $t8, $t7, 0xffff
  andi  $t9, $t8, 0x400
  sw    $a0, ($sp)
  beqz  $t9, .L70016C98
   move  $v0, $t8
  andi  $t0, $t8, 0x3ff
  sll   $t1, $t0, 1
  negu  $t2, $t1
  lui   $v1, %hi(sin_table + 0x7FE) # 0x8002
  addu  $v1, $v1, $t2
  b     .L70016CAC
   lh    $v1, %lo(sin_table + 0x7FE)($v1) # 0x7fce($v1)
.L70016C98:
  andi  $t3, $v0, 0x3ff
  sll   $t4, $t3, 1
  lui   $v1, %hi(sin_table) # 0x8002
  addu  $v1, $v1, $t4
  lh    $v1, %lo(sin_table)($v1) # 0x77d0($v1)
.L70016CAC:
  andi  $t5, $v0, 0x800
  beqz  $t5, .L70016CC8
   move  $v0, $v1
  negu  $v0, $v1
  sll   $t6, $v0, 0x10
  jr    $ra
   sra   $v0, $t6, 0x10

.L70016CC8:
  jr    $ra
   nop  

 .section .data
glabel sin_table
.half      0,  0x32,  0x64,  0x96
.half   0xC9,  0xFB, 0x12D, 0x160
.half  0x192, 0x1C4, 0x1F7, 0x229
.half  0x25B, 0x28E, 0x2C0, 0x2F2
.half  0x324, 0x357, 0x389, 0x3BB
.half  0x3EE, 0x420, 0x452, 0x484
.half  0x4B7, 0x4E9, 0x51B, 0x54E
.half  0x580, 0x5B2, 0x5E4, 0x617
.half  0x649, 0x67B, 0x6AD, 0x6E0
.half  0x712, 0x744, 0x776, 0x7A9
.half  0x7DB, 0x80D, 0x83F, 0x871
.half  0x8A4, 0x8D6, 0x908, 0x93A
.half  0x96C, 0x99F, 0x9D1, 0xA03
.half  0xA35, 0xA67, 0xA99, 0xACB
.half  0xAFE, 0xB30, 0xB62, 0xB94
.half  0xBC6, 0xBF8, 0xC2A, 0xC5C
.half  0xC8E, 0xCC0, 0xCF2, 0xD25
.half  0xD57, 0xD89, 0xDBB, 0xDED
.half  0xE1F, 0xE51, 0xE83, 0xEB5
.half  0xEE7, 0xF19, 0xF4B, 0xF7C
.half  0xFAE, 0xFE0,0x1012,0x1044
.half 0x1076,0x10A8,0x10DA,0x110C
.half 0x113E,0x116F,0x11A1,0x11D3
.half 0x1205,0x1237,0x1269,0x129A
.half 0x12CC,0x12FE,0x1330,0x1361
.half 0x1393,0x13C5,0x13F6,0x1428
.half 0x145A,0x148C,0x14BD,0x14EF
.half 0x1520,0x1552,0x1584,0x15B5
.half 0x15E7,0x1618,0x164A,0x167B
.half 0x16AD,0x16DF,0x1710,0x1741
.half 0x1773,0x17A4,0x17D6,0x1807
.half 0x1839,0x186A,0x189B,0x18CD
.half 0x18FE,0x1930,0x1961,0x1992
.half 0x19C3,0x19F5,0x1A26,0x1A57
.half 0x1A88,0x1ABA,0x1AEB,0x1B1C
.half 0x1B4D,0x1B7E,0x1BAF,0x1BE1
.half 0x1C12,0x1C43,0x1C74,0x1CA5
.half 0x1CD6,0x1D07,0x1D38,0x1D69
.half 0x1D9A,0x1DCB,0x1DFC,0x1E2D
.half 0x1E5D,0x1E8E,0x1EBF,0x1EF0
.half 0x1F21,0x1F52,0x1F82,0x1FB3
.half 0x1FE4,0x2015,0x2045,0x2076
.half 0x20A7,0x20D7,0x2108,0x2139
.half 0x2169,0x219A,0x21CA,0x21FB
.half 0x222B,0x225C,0x228C,0x22BD
.half 0x22ED,0x231D,0x234E,0x237E
.half 0x23AE,0x23DF,0x240F,0x243F
.half 0x2470,0x24A0,0x24D0,0x2500
.half 0x2530,0x2560,0x2591,0x25C1
.half 0x25F1,0x2621,0x2651,0x2681
.half 0x26B1,0x26E1,0x2711,0x2740
.half 0x2770,0x27A0,0x27D0,0x2800
.half 0x2830,0x285F,0x288F,0x28BF
.half 0x28EE,0x291E,0x294E,0x297D
.half 0x29AD,0x29DD,0x2A0C,0x2A3C
.half 0x2A6B,0x2A9B,0x2ACA,0x2AF9
.half 0x2B29,0x2B58,0x2B87,0x2BB7
.half 0x2BE6,0x2C15,0x2C44,0x2C74
.half 0x2CA3,0x2CD2,0x2D01,0x2D30
.half 0x2D5F,0x2D8E,0x2DBD,0x2DEC
.half 0x2E1B,0x2E4A,0x2E79,0x2EA8
.half 0x2ED7,0x2F06,0x2F34,0x2F63
.half 0x2F92,0x2FC0,0x2FEF,0x301E
.half 0x304C,0x307B,0x30A9,0x30D8
.half 0x3107,0x3135,0x3163,0x3192
.half 0x31C0,0x31EF,0x321D,0x324B
.half 0x3279,0x32A8,0x32D6,0x3304
.half 0x3332,0x3360,0x338E,0x33BC
.half 0x33EA,0x3418,0x3446,0x3474
.half 0x34A2,0x34D0,0x34FE,0x352B
.half 0x3559,0x3587,0x35B5,0x35E2
.half 0x3610,0x363D,0x366B,0x3698
.half 0x36C6,0x36F3,0x3721,0x374E
.half 0x377C,0x37A9,0x37D6,0x3803
.half 0x3831,0x385E,0x388B,0x38B8
.half 0x38E5,0x3912,0x393F,0x396C
.half 0x3999,0x39C6,0x39F3,0x3A20
.half 0x3A4D,0x3A79,0x3AA6,0x3AD3
.half 0x3B00,0x3B2C,0x3B59,0x3B85
.half 0x3BB2,0x3BDE,0x3C0B,0x3C37
.half 0x3C64,0x3C90,0x3CBC,0x3CE9
.half 0x3D15,0x3D41,0x3D6D,0x3D99
.half 0x3DC5,0x3DF1,0x3E1D,0x3E49
.half 0x3E75,0x3EA1,0x3ECD,0x3EF9
.half 0x3F25,0x3F50,0x3F7C,0x3FA8
.half 0x3FD3,0x3FFF,0x402B,0x4056
.half 0x4082,0x40AD,0x40D8,0x4104
.half 0x412F,0x415A,0x4186,0x41B1
.half 0x41DC,0x4207,0x4232,0x425D
.half 0x4288,0x42B3,0x42DE,0x4309
.half 0x4334,0x435F,0x4389,0x43B4
.half 0x43DF,0x4409,0x4434,0x445F
.half 0x4489,0x44B4,0x44DE,0x4508
.half 0x4533,0x455D,0x4587,0x45B1
.half 0x45DC,0x4606,0x4630,0x465A
.half 0x4684,0x46AE,0x46D8,0x4702
.half 0x472C,0x4755,0x477F,0x47A9
.half 0x47D2,0x47FC,0x4826,0x484F
.half 0x4879,0x48A2,0x48CC,0x48F5
.half 0x491E,0x4948,0x4971,0x499A
.half 0x49C3,0x49EC,0x4A15,0x4A3E
.half 0x4A67,0x4A90,0x4AB9,0x4AE2
.half 0x4B0B,0x4B33,0x4B5C,0x4B85
.half 0x4BAD,0x4BD6,0x4BFE,0x4C27
.half 0x4C4F,0x4C78,0x4CA0,0x4CC8
.half 0x4CF0,0x4D19,0x4D41,0x4D69
.half 0x4D91,0x4DB9,0x4DE1,0x4E09
.half 0x4E31,0x4E58,0x4E80,0x4EA8
.half 0x4ED0,0x4EF7,0x4F1F,0x4F46
.half 0x4F6E,0x4F95,0x4FBD,0x4FE4
.half 0x500B,0x5032,0x505A,0x5081
.half 0x50A8,0x50CF,0x50F6,0x511D
.half 0x5144,0x516B,0x5191,0x51B8
.half 0x51DF,0x5205,0x522C,0x5253
.half 0x5279,0x52A0,0x52C6,0x52EC
.half 0x5313,0x5339,0x535F,0x5385
.half 0x53AB,0x53D1,0x53F7,0x541D
.half 0x5443,0x5469,0x548F,0x54B5
.half 0x54DA,0x5500,0x5525,0x554B
.half 0x5571,0x5596,0x55BB,0x55E1
.half 0x5606,0x562B,0x5650,0x5675
.half 0x569B,0x56C0,0x56E5,0x5709
.half 0x572E,0x5753,0x5778,0x579D
.half 0x57C1,0x57E6,0x580A,0x582F
.half 0x5853,0x5878,0x589C,0x58C0
.half 0x58E5,0x5909,0x592D,0x5951
.half 0x5975,0x5999,0x59BD,0x59E1
.half 0x5A04,0x5A28,0x5A4C,0x5A6F
.half 0x5A93,0x5AB7,0x5ADA,0x5AFD
.half 0x5B21,0x5B44,0x5B67,0x5B8B
.half 0x5BAE,0x5BD1,0x5BF4,0x5C17
.half 0x5C3A,0x5C5D,0x5C7F,0x5CA2
.half 0x5CC5,0x5CE7,0x5D0A,0x5D2D
.half 0x5D4F,0x5D71,0x5D94,0x5DB6
.half 0x5DD8,0x5DFA,0x5E1D,0x5E3F
.half 0x5E61,0x5E83,0x5EA5,0x5EC6
.half 0x5EE8,0x5F0A,0x5F2C,0x5F4D
.half 0x5F6F,0x5F90,0x5FB2,0x5FD3
.half 0x5FF4,0x6016,0x6037,0x6058
.half 0x6079,0x609A,0x60BB,0x60DC
.half 0x60FD,0x611E,0x613E,0x615F
.half 0x6180,0x61A0,0x61C1,0x61E1
.half 0x6202,0x6222,0x6242,0x6263
.half 0x6283,0x62A3,0x62C3,0x62E3
.half 0x6303,0x6323,0x6342,0x6362
.half 0x6382,0x63A1,0x63C1,0x63E0
.half 0x6400,0x641F,0x643F,0x645E
.half 0x647D,0x649C,0x64BB,0x64DA
.half 0x64F9,0x6518,0x6537,0x6556
.half 0x6574,0x6593,0x65B2,0x65D0
.half 0x65EF,0x660D,0x662B,0x664A
.half 0x6668,0x6686,0x66A4,0x66C2
.half 0x66E0,0x66FE,0x671C,0x673A
.half 0x6757,0x6775,0x6792,0x67B0
.half 0x67CD,0x67EB,0x6808,0x6825
.half 0x6843,0x6860,0x687D,0x689A
.half 0x68B7,0x68D4,0x68F1,0x690D
.half 0x692A,0x6947,0x6963,0x6980
.half 0x699C,0x69B9,0x69D5,0x69F1
.half 0x6A0E,0x6A2A,0x6A46,0x6A62
.half 0x6A7E,0x6A9A,0x6AB5,0x6AD1
.half 0x6AED,0x6B08,0x6B24,0x6B40
.half 0x6B5B,0x6B76,0x6B92,0x6BAD
.half 0x6BC8,0x6BE3,0x6BFE,0x6C19
.half 0x6C34,0x6C4F,0x6C6A,0x6C84
.half 0x6C9F,0x6CBA,0x6CD4,0x6CEF
.half 0x6D09,0x6D23,0x6D3E,0x6D58
.half 0x6D72,0x6D8C,0x6DA6,0x6DC0
.half 0x6DDA,0x6DF3,0x6E0D,0x6E27
.half 0x6E40,0x6E5A,0x6E73,0x6E8D
.half 0x6EA6,0x6EBF,0x6ED9,0x6EF2
.half 0x6F0B,0x6F24,0x6F3D,0x6F55
.half 0x6F6E,0x6F87,0x6FA0,0x6FB8
.half 0x6FD1,0x6FE9,0x7002,0x701A
.half 0x7032,0x704A,0x7062,0x707A
.half 0x7092,0x70AA,0x70C2,0x70DA
.half 0x70F2,0x7109,0x7121,0x7138
.half 0x7150,0x7167,0x717E,0x7196
.half 0x71AD,0x71C4,0x71DB,0x71F2
.half 0x7209,0x7220,0x7236,0x724D
.half 0x7264,0x727A,0x7291,0x72A7
.half 0x72BD,0x72D4,0x72EA,0x7300
.half 0x7316,0x732C,0x7342,0x7358
.half 0x736E,0x7383,0x7399,0x73AE
.half 0x73C4,0x73D9,0x73EF,0x7404
.half 0x7419,0x742E,0x7443,0x7458
.half 0x746D,0x7482,0x7497,0x74AC
.half 0x74C0,0x74D5,0x74EA,0x74FE
.half 0x7512,0x7527,0x753B,0x754F
.half 0x7563,0x7577,0x758B,0x759F
.half 0x75B3,0x75C7,0x75DA,0x75EE
.half 0x7601,0x7615,0x7628,0x763B
.half 0x764F,0x7662,0x7675,0x7688
.half 0x769B,0x76AE,0x76C1,0x76D3
.half 0x76E6,0x76F9,0x770B,0x771E
.half 0x7730,0x7742,0x7754,0x7767
.half 0x7779,0x778B,0x779D,0x77AF
.half 0x77C0,0x77D2,0x77E4,0x77F5
.half 0x7807,0x7818,0x782A,0x783B
.half 0x784C,0x785D,0x786E,0x787F
.half 0x7890,0x78A1,0x78B2,0x78C3
.half 0x78D3,0x78E4,0x78F4,0x7905
.half 0x7915,0x7925,0x7936,0x7946
.half 0x7956,0x7966,0x7976,0x7985
.half 0x7995,0x79A5,0x79B5,0x79C4
.half 0x79D4,0x79E3,0x79F2,0x7A02
.half 0x7A11,0x7A20,0x7A2F,0x7A3E
.half 0x7A4D,0x7A5B,0x7A6A,0x7A79
.half 0x7A87,0x7A96,0x7AA4,0x7AB3
.half 0x7AC1,0x7ACF,0x7ADD,0x7AEB
.half 0x7AF9,0x7B07,0x7B15,0x7B23
.half 0x7B31,0x7B3E,0x7B4C,0x7B59
.half 0x7B67,0x7B74,0x7B81,0x7B8E
.half 0x7B9B,0x7BA8,0x7BB5,0x7BC2
.half 0x7BCF,0x7BDC,0x7BE8,0x7BF5
.half 0x7C02,0x7C0E,0x7C1A,0x7C27
.half 0x7C33,0x7C3F,0x7C4B,0x7C57
.half 0x7C63,0x7C6F,0x7C7A,0x7C86
.half 0x7C92,0x7C9D,0x7CA9,0x7CB4
.half 0x7CBF,0x7CCB,0x7CD6,0x7CE1
.half 0x7CEC,0x7CF7,0x7D02,0x7D0C
.half 0x7D17,0x7D22,0x7D2C,0x7D37
.half 0x7D41,0x7D4B,0x7D56,0x7D60
.half 0x7D6A,0x7D74,0x7D7E,0x7D88
.half 0x7D91,0x7D9B,0x7DA5,0x7DAE
.half 0x7DB8,0x7DC1,0x7DCB,0x7DD4
.half 0x7DDD,0x7DE6,0x7DEF,0x7DF8
.half 0x7E01,0x7E0A,0x7E13,0x7E1B
.half 0x7E24,0x7E2C,0x7E35,0x7E3D
.half 0x7E45,0x7E4D,0x7E56,0x7E5E
.half 0x7E66,0x7E6D,0x7E75,0x7E7D
.half 0x7E85,0x7E8C,0x7E94,0x7E9B
.half 0x7EA3,0x7EAA,0x7EB1,0x7EB8
.half 0x7EBF,0x7EC6,0x7ECD,0x7ED4
.half 0x7EDB,0x7EE1,0x7EE8,0x7EEE
.half 0x7EF5,0x7EFB,0x7F01,0x7F08
.half 0x7F0E,0x7F14,0x7F1A,0x7F20
.half 0x7F25,0x7F2B,0x7F31,0x7F36
.half 0x7F3C,0x7F41,0x7F47,0x7F4C
.half 0x7F51,0x7F56,0x7F5B,0x7F60
.half 0x7F65,0x7F6A,0x7F6F,0x7F74
.half 0x7F78,0x7F7D,0x7F81,0x7F85
.half 0x7F8A,0x7F8E,0x7F92,0x7F96
.half 0x7F9A,0x7F9E,0x7FA2,0x7FA6
.half 0x7FA9,0x7FAD,0x7FB0,0x7FB4
.half 0x7FB7,0x7FBA,0x7FBE,0x7FC1
.half 0x7FC4,0x7FC7,0x7FCA,0x7FCC
.half 0x7FCF,0x7FD2,0x7FD4,0x7FD7
.half 0x7FD9,0x7FDC,0x7FDE,0x7FE0
.half 0x7FE2,0x7FE4,0x7FE6,0x7FE8
.half 0x7FEA,0x7FEC,0x7FED,0x7FEF
.half 0x7FF1,0x7FF2,0x7FF3,0x7FF5
.half 0x7FF6,0x7FF7,0x7FF8,0x7FF9
.half 0x7FFA,0x7FFB,0x7FFB,0x7FFC
.half 0x7FFD,0x7FFD,0x7FFE,0x7FFE
.half 0x7FFE,0x7FFE,0x7FFE,0x7FFF

.section .text
glabel guTranslateF
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a1, 0x1c($sp)
  sw    $a2, 0x20($sp)
  sw    $a3, 0x24($sp)
  jal   guMtxIdentF
   sw    $a0, 0x18($sp)
  lw    $a0, 0x18($sp)
  lwc1  $f4, 0x1c($sp)
  swc1  $f4, 0x30($a0)
  lwc1  $f6, 0x20($sp)
  swc1  $f6, 0x34($a0)
  lwc1  $f8, 0x24($sp)
  swc1  $f8, 0x38($a0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   

glabel guTranslate
  addiu $sp, $sp, -0x68
  sw    $ra, 0x14($sp)
  sw    $a0, 0x68($sp)
  sw    $a1, 0x6c($sp)
  sw    $a2, 0x70($sp)
  sw    $a3, 0x74($sp)
  jal   guMtxIdentF
   addiu $a0, $sp, 0x28
  lwc1  $f4, 0x6c($sp)
  lwc1  $f6, 0x70($sp)
  lwc1  $f8, 0x74($sp)
  addiu $a0, $sp, 0x28
  lw    $a1, 0x68($sp)
  swc1  $f4, 0x58($sp)
  swc1  $f6, 0x5c($sp)
  jal   guMtxF2L
   swc1  $f8, 0x60($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x68
  jr    $ra
   nop   

  nop   
glabel _bcmp
  slti  $at, $a2, 0x10
  bnez  $at, .L70016E54
   xor   $v0, $a0, $a1
  andi  $v0, $v0, 3
  bnez  $v0, .L70016DE8
   negu  $t8, $a0
  andi  $t8, $t8, 3
  beqz  $t8, .L70016DAC
   subu  $a2, $a2, $t8
  move  $v0, $v1
  lwl   $v0, ($a0)
  lwl   $v1, ($a1)
  addu  $a0, $a0, $t8
  addu  $a1, $a1, $t8
  bne   $v0, $v1, .L70016E84
.L70016DAC:
   li    $at, -4
  and   $a3, $a2, $at
  beqz  $a3, .L70016E54
   subu  $a2, $a2, $a3
  addu  $a3, $a3, $a0
  lw    $v0, ($a0)
.L70016DC4:
  lw    $v1, ($a1)
  addiu $a0, $a0, 4
  addiu $a1, $a1, 4
  bne   $v0, $v1, .L70016E84
   nop   
  bnel  $a0, $a3, .L70016DC4
   lw    $v0, ($a0)
  b     .L70016E54
   nop   
.L70016DE8:
  negu  $a3, $a1
  andi  $a3, $a3, 3
  beqz  $a3, .L70016E1C
   subu  $a2, $a2, $a3
  addu  $a3, $a3, $a0
  lbu   $v0, ($a0)
.L70016E00:
  lbu   $v1, ($a1)
  addiu $a0, $a0, 1
  addiu $a1, $a1, 1
  bne   $v0, $v1, .L70016E84
   nop   
  bnel  $a0, $a3, .L70016E00
   lbu   $v0, ($a0)
.L70016E1C:
  li    $at, -4
  and   $a3, $a2, $at
  beqz  $a3, .L70016E54
   subu  $a2, $a2, $a3
  addu  $a3, $a3, $a0
  lwl   $v0, ($a0)
.L70016E34:
  lw    $v1, ($a1)
  lwr   $v0, 3($a0)
  addiu $a0, $a0, 4
  addiu $a1, $a1, 4
  bne   $v0, $v1, .L70016E84
   nop   
  bnel  $a0, $a3, .L70016E34
   lwl   $v0, ($a0)
.L70016E54:
  blez  $a2, .L70016E7C
   addu  $a3, $a2, $a0
  lbu   $v0, ($a0)
.L70016E60:
  lbu   $v1, ($a1)
  addiu $a0, $a0, 1
  addiu $a1, $a1, 1
  bne   $v0, $v1, .L70016E84
   nop   
  bnel  $a0, $a3, .L70016E60
   lbu   $v0, ($a0)
.L70016E7C:
  jr    $ra
   move  $v0, $zero

.L70016E84:
  jr    $ra
   li    $v0, 1

  nop   
glabel guScaleF
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a1, 0x1c($sp)
  sw    $a2, 0x20($sp)
  sw    $a3, 0x24($sp)
  jal   guMtxIdentF
   sw    $a0, 0x18($sp)
  lw    $a0, 0x18($sp)
  lwc1  $f4, 0x1c($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  swc1  $f4, ($a0)
  lwc1  $f6, 0x20($sp)
  swc1  $f6, 0x14($a0)
  lwc1  $f8, 0x24($sp)
  swc1  $f10, 0x3c($a0)
  swc1  $f8, 0x28($a0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   

glabel guScale
  mtc1  $a1, $f12
  mtc1  $a2, $f14
  mtc1  $a3, $f16
  addiu $sp, $sp, -0x58
  sw    $ra, 0x14($sp)
  sw    $a0, 0x58($sp)
  mfc1  $a1, $f12
  mfc1  $a2, $f14
  mfc1  $a3, $f16
  jal   guScaleF
   addiu $a0, $sp, 0x18
  addiu $a0, $sp, 0x18
  jal   guMtxF2L
   lw    $a1, 0x58($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x58
  jr    $ra
   nop   

  nop   
glabel guLookAtReflectF
  addiu $sp, $sp, -0x48
  sw    $ra, 0x44($sp)
  sdc1  $f30, 0x38($sp)
  sdc1  $f28, 0x30($sp)
  sdc1  $f26, 0x28($sp)
  sdc1  $f24, 0x20($sp)
  sdc1  $f22, 0x18($sp)
  sdc1  $f20, 0x10($sp)
  sw    $a2, 0x50($sp)
  sw    $a3, 0x54($sp)
  sw    $a0, 0x48($sp)
  jal   guMtxIdentF
   sw    $a1, 0x4c($sp)
  lwc1  $f4, 0x5c($sp)
  lwc1  $f6, 0x50($sp)
  lwc1  $f8, 0x60($sp)
  lwc1  $f10, 0x54($sp)
  sub.s $f0, $f4, $f6
  lwc1  $f6, 0x58($sp)
  lwc1  $f4, 0x64($sp)
  sub.s $f22, $f8, $f10
  mul.s $f8, $f0, $f0
  mov.s $f20, $f0
  sub.s $f24, $f4, $f6
  mul.s $f10, $f22, $f22
  add.s $f4, $f8, $f10
  mul.s $f6, $f24, $f24
  jal   sqrtf
   add.s $f12, $f4, $f6
  li    $at, 0xBFF00000 # -1.875000
  mtc1  $at, $f9
  mtc1  $zero, $f8
  cvt.d.s $f10, $f0
  lwc1  $f6, 0x6c($sp)
  div.d $f4, $f8, $f10
  lwc1  $f10, 0x70($sp)
  cvt.s.d $f2, $f4
  mul.s $f20, $f20, $f2
  nop   
  mul.s $f22, $f22, $f2
  nop   
  mul.s $f24, $f24, $f2
  nop   
  mul.s $f8, $f6, $f24
  nop   
  mul.s $f4, $f10, $f22
  sub.s $f26, $f8, $f4
  mul.s $f8, $f10, $f20
  lwc1  $f4, 0x68($sp)
  mul.s $f10, $f4, $f24
  sub.s $f28, $f8, $f10
  mul.s $f8, $f4, $f22
  nop   
  mul.s $f10, $f6, $f20
  sub.s $f30, $f8, $f10
  mul.s $f4, $f26, $f26
  nop   
  mul.s $f6, $f28, $f28
  add.s $f8, $f4, $f6
  mul.s $f10, $f30, $f30
  jal   sqrtf
   add.s $f12, $f8, $f10
  li    $at, 0x3FF00000 # 1.875000
  mtc1  $at, $f5
  mtc1  $zero, $f4
  cvt.d.s $f6, $f0
  div.d $f8, $f4, $f6
  cvt.s.d $f14, $f8
  mul.s $f26, $f26, $f14
  nop   
  mul.s $f28, $f28, $f14
  nop   
  mul.s $f30, $f30, $f14
  nop   
  mul.s $f10, $f22, $f30
  nop   
  mul.s $f4, $f24, $f28
  nop   
  mul.s $f6, $f24, $f26
  nop   
  mul.s $f8, $f20, $f30
  sub.s $f2, $f10, $f4
  mul.s $f10, $f20, $f28
  nop   
  mul.s $f4, $f22, $f26
  swc1  $f2, 0x68($sp)
  sub.s $f16, $f6, $f8
  mul.s $f6, $f2, $f2
  nop   
  mul.s $f8, $f16, $f16
  swc1  $f16, 0x6c($sp)
  sub.s $f18, $f10, $f4
  mul.s $f4, $f18, $f18
  add.s $f10, $f6, $f8
  swc1  $f18, 0x70($sp)
  jal   sqrtf
   add.s $f12, $f10, $f4
  lui   $at, %hi(F64_80029800) # 0x8003
  ldc1  $f2, %lo(F64_80029800)($at) # -0x6800
  li    $at, 0x40600000 # 3.500000
  mtc1  $at, $f17
  li    $at, 0x3FF00000 # 1.875000
  mtc1  $at, $f7
  mtc1  $zero, $f6
  cvt.d.s $f8, $f0
  lwc1  $f4, 0x68($sp)
  div.d $f10, $f6, $f8
  lwc1  $f8, 0x6c($sp)
  mtc1  $zero, $f16
  lw    $a0, 0x48($sp)
  lw    $a1, 0x4c($sp)
  li    $v0, 128
  cvt.s.d $f14, $f10
  mul.s $f6, $f4, $f14
  lwc1  $f4, 0x70($sp)
  mul.s $f10, $f8, $f14
  cvt.d.s $f8, $f26
  swc1  $f6, 0x68($sp)
  mul.s $f6, $f4, $f14
  swc1  $f10, 0x6c($sp)
  mul.d $f12, $f8, $f16
  swc1  $f6, 0x70($sp)
  c.lt.d $f12, $f2
  nop   
  bc1fl .L70017134
   mov.d $f0, $f2
  b     .L70017134
   mov.d $f0, $f12
  mov.d $f0, $f2
.L70017134:
  cvt.d.s $f4, $f28
  trunc.w.d $f10, $f0
  mul.d $f12, $f4, $f16
  mfc1  $t8, $f10
  nop   
  sb    $t8, 8($a1)
  c.lt.d $f12, $f2
  nop   
  bc1fl .L70017168
   mov.d $f0, $f2
  b     .L70017168
   mov.d $f0, $f12
  mov.d $f0, $f2
.L70017168:
  cvt.d.s $f8, $f30
  trunc.w.d $f6, $f0
  mul.d $f12, $f8, $f16
  mfc1  $t1, $f6
  nop   
  sb    $t1, 9($a1)
  c.lt.d $f12, $f2
  nop   
  bc1fl .L7001719C
   mov.d $f0, $f2
  b     .L7001719C
   mov.d $f0, $f12
  mov.d $f0, $f2
.L7001719C:
  trunc.w.d $f10, $f0
  mfc1  $t4, $f10
  nop   
  sb    $t4, 0xa($a1)
  lwc1  $f4, 0x68($sp)
  cvt.d.s $f6, $f4
  mul.d $f12, $f6, $f16
  c.lt.d $f12, $f2
  nop   
  bc1fl .L700171D4
   mov.d $f0, $f2
  b     .L700171D4
   mov.d $f0, $f12
  mov.d $f0, $f2
.L700171D4:
  trunc.w.d $f8, $f0
  mfc1  $t7, $f8
  nop   
  sb    $t7, 0x18($a1)
  lwc1  $f10, 0x6c($sp)
  cvt.d.s $f4, $f10
  mul.d $f12, $f4, $f16
  c.lt.d $f12, $f2
  nop   
  bc1fl .L7001720C
   mov.d $f0, $f2
  b     .L7001720C
   mov.d $f0, $f12
  mov.d $f0, $f2
.L7001720C:
  trunc.w.d $f6, $f0
  mfc1  $t0, $f6
  nop   
  sb    $t0, 0x19($a1)
  lwc1  $f8, 0x70($sp)
  cvt.d.s $f10, $f8
  mul.d $f12, $f10, $f16
  c.lt.d $f12, $f2
  nop   
  bc1fl .L70017244
   mov.d $f0, $f2
  b     .L70017244
   mov.d $f0, $f12
  mov.d $f0, $f2
.L70017244:
  trunc.w.d $f4, $f0
  sb    $zero, ($a1)
  sb    $zero, 1($a1)
  sb    $zero, 2($a1)
  mfc1  $t3, $f4
  sb    $zero, 3($a1)
  sb    $zero, 4($a1)
  sb    $zero, 5($a1)
  sb    $zero, 6($a1)
  sb    $zero, 7($a1)
  sb    $zero, 0x10($a1)
  sb    $v0, 0x11($a1)
  sb    $zero, 0x12($a1)
  sb    $zero, 0x13($a1)
  sb    $zero, 0x14($a1)
  sb    $v0, 0x15($a1)
  sb    $zero, 0x16($a1)
  sb    $zero, 0x17($a1)
  sb    $t3, 0x1a($a1)
  swc1  $f26, ($a0)
  lwc1  $f18, 0x50($sp)
  lwc1  $f16, 0x54($sp)
  lwc1  $f14, 0x58($sp)
  mul.s $f6, $f18, $f26
  lwc1  $f0, 0x68($sp)
  lwc1  $f12, 0x6c($sp)
  mul.s $f8, $f16, $f28
  lwc1  $f2, 0x70($sp)
  swc1  $f28, 0x10($a0)
  mul.s $f4, $f14, $f30
  swc1  $f30, 0x20($a0)
  swc1  $f20, 8($a0)
  swc1  $f22, 0x18($a0)
  swc1  $f24, 0x28($a0)
  add.s $f10, $f6, $f8
  swc1  $f0, 4($a0)
  swc1  $f12, 0x14($a0)
  swc1  $f2, 0x24($a0)
  add.s $f6, $f10, $f4
  mul.s $f10, $f18, $f0
  mtc1  $zero, $f0
  li    $at, 0x3F800000 # 1.000000
  mul.s $f4, $f16, $f12
  neg.s $f8, $f6
  swc1  $f8, 0x30($a0)
  mul.s $f8, $f14, $f2
  add.s $f6, $f10, $f4
  add.s $f10, $f6, $f8
  neg.s $f4, $f10
  swc1  $f4, 0x34($a0)
  lwc1  $f6, 0x50($sp)
  lwc1  $f10, 0x54($sp)
  mul.s $f8, $f6, $f20
  nop   
  mul.s $f4, $f10, $f22
  lwc1  $f10, 0x58($sp)
  swc1  $f0, 0xc($a0)
  swc1  $f0, 0x1c($a0)
  swc1  $f0, 0x2c($a0)
  add.s $f6, $f8, $f4
  mul.s $f8, $f10, $f24
  add.s $f4, $f6, $f8
  mtc1  $at, $f6
  neg.s $f10, $f4
  swc1  $f6, 0x3c($a0)
  swc1  $f10, 0x38($a0)
  lw    $ra, 0x44($sp)
  ldc1  $f30, 0x38($sp)
  ldc1  $f28, 0x30($sp)
  ldc1  $f26, 0x28($sp)
  ldc1  $f24, 0x20($sp)
  ldc1  $f22, 0x18($sp)
  ldc1  $f20, 0x10($sp)
  jr    $ra
   addiu $sp, $sp, 0x48

glabel guLookAtReflect
  addiu $sp, $sp, -0x78
  lwc1  $f4, 0x88($sp)
  mtc1  $a2, $f12
  mtc1  $a3, $f14
  swc1  $f4, 0x10($sp)
  lwc1  $f4, 0xa0($sp)
  lwc1  $f6, 0x8c($sp)
  lwc1  $f8, 0x90($sp)
  lwc1  $f10, 0x94($sp)
  lwc1  $f16, 0x98($sp)
  lwc1  $f18, 0x9c($sp)
  sw    $ra, 0x34($sp)
  sw    $a0, 0x78($sp)
  mfc1  $a2, $f12
  mfc1  $a3, $f14
  addiu $a0, $sp, 0x38
  swc1  $f4, 0x28($sp)
  swc1  $f6, 0x14($sp)
  swc1  $f8, 0x18($sp)
  swc1  $f10, 0x1c($sp)
  swc1  $f16, 0x20($sp)
  jal   guLookAtReflectF
   swc1  $f18, 0x24($sp)
  addiu $a0, $sp, 0x38
  jal   guMtxF2L
   lw    $a1, 0x78($sp)
  lw    $ra, 0x34($sp)
  addiu $sp, $sp, 0x78
  jr    $ra
   nop   

.align 4 

.section .rodata
glabel F64_80029800
.double 127.0
.align 4

.section .text 
glabel guLookAtF
  addiu $sp, $sp, -0x50
  sw    $ra, 0x4c($sp)
  sw    $s0, 0x48($sp)
  move  $s0, $a0
  sdc1  $f30, 0x40($sp)
  sdc1  $f28, 0x38($sp)
  sdc1  $f26, 0x30($sp)
  sdc1  $f24, 0x28($sp)
  sdc1  $f22, 0x20($sp)
  sdc1  $f20, 0x18($sp)
  sw    $a1, 0x54($sp)
  sw    $a2, 0x58($sp)
  jal   guMtxIdentF
   sw    $a3, 0x5c($sp)
  lwc1  $f4, 0x60($sp)
  lwc1  $f6, 0x54($sp)
  lwc1  $f8, 0x64($sp)
  lwc1  $f10, 0x58($sp)
  sub.s $f0, $f4, $f6
  lwc1  $f6, 0x5c($sp)
  lwc1  $f4, 0x68($sp)
  sub.s $f22, $f8, $f10
  mul.s $f8, $f0, $f0
  mov.s $f20, $f0
  sub.s $f24, $f4, $f6
  mul.s $f10, $f22, $f22
  add.s $f4, $f8, $f10
  mul.s $f6, $f24, $f24
  jal   sqrtf
   add.s $f12, $f4, $f6
  li    $at, 0xBFF00000 # -1.875000
  mtc1  $at, $f9
  mtc1  $zero, $f8
  cvt.d.s $f10, $f0
  lwc1  $f6, 0x70($sp)
  div.d $f4, $f8, $f10
  lwc1  $f10, 0x74($sp)
  cvt.s.d $f2, $f4
  mul.s $f20, $f20, $f2
  nop   
  mul.s $f22, $f22, $f2
  nop   
  mul.s $f24, $f24, $f2
  nop   
  mul.s $f8, $f6, $f24
  nop   
  mul.s $f4, $f10, $f22
  sub.s $f26, $f8, $f4
  mul.s $f8, $f10, $f20
  lwc1  $f4, 0x6c($sp)
  mul.s $f10, $f4, $f24
  sub.s $f28, $f8, $f10
  mul.s $f8, $f4, $f22
  nop   
  mul.s $f10, $f6, $f20
  sub.s $f30, $f8, $f10
  mul.s $f4, $f26, $f26
  nop   
  mul.s $f6, $f28, $f28
  add.s $f8, $f4, $f6
  mul.s $f10, $f30, $f30
  jal   sqrtf
   add.s $f12, $f8, $f10
  li    $at, 0x3FF00000 # 1.875000
  mtc1  $at, $f5
  mtc1  $zero, $f4
  cvt.d.s $f6, $f0
  div.d $f8, $f4, $f6
  cvt.s.d $f2, $f8
  mul.s $f26, $f26, $f2
  nop   
  mul.s $f28, $f28, $f2
  nop   
  mul.s $f30, $f30, $f2
  nop   
  mul.s $f10, $f22, $f30
  nop   
  mul.s $f4, $f24, $f28
  nop   
  mul.s $f6, $f24, $f26
  nop   
  mul.s $f8, $f20, $f30
  sub.s $f14, $f10, $f4
  mul.s $f10, $f20, $f28
  nop   
  mul.s $f4, $f22, $f26
  swc1  $f14, 0x6c($sp)
  sub.s $f16, $f6, $f8
  mul.s $f6, $f14, $f14
  nop   
  mul.s $f8, $f16, $f16
  swc1  $f16, 0x70($sp)
  sub.s $f18, $f10, $f4
  mul.s $f4, $f18, $f18
  add.s $f10, $f6, $f8
  swc1  $f18, 0x74($sp)
  jal   sqrtf
   add.s $f12, $f10, $f4
  li    $at, 0x3FF00000 # 1.875000
  mtc1  $at, $f7
  mtc1  $zero, $f6
  cvt.d.s $f8, $f0
  lwc1  $f14, 0x6c($sp)
  div.d $f10, $f6, $f8
  lwc1  $f12, 0x70($sp)
  lwc1  $f4, 0x74($sp)
  li    $at, 0x3F800000 # 1.000000
  cvt.s.d $f2, $f10
  mul.s $f14, $f14, $f2
  nop   
  mul.s $f12, $f12, $f2
  nop   
  mul.s $f6, $f4, $f2
  swc1  $f6, 0x74($sp)
  swc1  $f26, ($s0)
  swc1  $f28, 0x10($s0)
  swc1  $f30, 0x20($s0)
  lwc1  $f8, 0x54($sp)
  lwc1  $f4, 0x58($sp)
  mul.s $f10, $f8, $f26
  nop   
  mul.s $f6, $f4, $f28
  lwc1  $f4, 0x5c($sp)
  swc1  $f14, 4($s0)
  swc1  $f12, 0x14($s0)
  add.s $f8, $f10, $f6
  mul.s $f10, $f4, $f30
  add.s $f6, $f8, $f10
  neg.s $f4, $f6
  swc1  $f4, 0x30($s0)
  lwc1  $f0, 0x74($sp)
  swc1  $f12, 0x70($sp)
  swc1  $f14, 0x6c($sp)
  lwc1  $f14, 0x54($sp)
  lwc1  $f12, 0x58($sp)
  lwc1  $f2, 0x5c($sp)
  swc1  $f0, 0x24($s0)
  lwc1  $f8, 0x6c($sp)
  lwc1  $f6, 0x70($sp)
  swc1  $f20, 8($s0)
  mul.s $f10, $f14, $f8
  swc1  $f22, 0x18($s0)
  swc1  $f24, 0x28($s0)
  mul.s $f4, $f12, $f6
  add.s $f8, $f10, $f4
  mul.s $f6, $f2, $f0
  mtc1  $zero, $f0
  nop   
  swc1  $f0, 0xc($s0)
  swc1  $f0, 0x1c($s0)
  swc1  $f0, 0x2c($s0)
  add.s $f10, $f8, $f6
  mul.s $f8, $f14, $f20
  nop   
  mul.s $f6, $f12, $f22
  neg.s $f4, $f10
  swc1  $f4, 0x34($s0)
  mul.s $f4, $f2, $f24
  add.s $f10, $f8, $f6
  add.s $f8, $f10, $f4
  mtc1  $at, $f10
  neg.s $f6, $f8
  swc1  $f10, 0x3c($s0)
  swc1  $f6, 0x38($s0)
  lw    $ra, 0x4c($sp)
  lw    $s0, 0x48($sp)
  ldc1  $f30, 0x40($sp)
  ldc1  $f28, 0x38($sp)
  ldc1  $f26, 0x30($sp)
  ldc1  $f24, 0x28($sp)
  ldc1  $f22, 0x20($sp)
  ldc1  $f20, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x50

glabel guLookAt
  addiu $sp, $sp, -0x70
  lwc1  $f4, 0x80($sp)
  mtc1  $a1, $f12
  mtc1  $a2, $f14
  mtc1  $a3, $f16
  swc1  $f4, 0x10($sp)
  lwc1  $f4, 0x94($sp)
  lwc1  $f6, 0x84($sp)
  lwc1  $f8, 0x88($sp)
  lwc1  $f10, 0x8c($sp)
  lwc1  $f18, 0x90($sp)
  sw    $ra, 0x2c($sp)
  sw    $a0, 0x70($sp)
  mfc1  $a1, $f12
  mfc1  $a2, $f14
  mfc1  $a3, $f16
  addiu $a0, $sp, 0x30
  swc1  $f4, 0x24($sp)
  swc1  $f6, 0x14($sp)
  swc1  $f8, 0x18($sp)
  swc1  $f10, 0x1c($sp)
  jal   guLookAtF
   swc1  $f18, 0x20($sp)
  addiu $a0, $sp, 0x30
  jal   guMtxF2L
   lw    $a1, 0x70($sp)
  lw    $ra, 0x2c($sp)
  addiu $sp, $sp, 0x70
  jr    $ra
   nop   

glabel guRotateF
  addiu $sp, $sp, -0x38
  lui   $at, %hi(F32_80029810)
  lwc1  $f4, %lo(F32_80029810)($at)
  sw    $s0, 0x18($sp)
  move  $s0, $a0
  lui    $at, %hi(flt_CODE_bss_80067DE0)
  sw    $ra, 0x1c($sp)
  sw    $a1, 0x3c($sp)
  sw    $a2, 0x40($sp)
  sw    $a3, 0x44($sp)
  addiu $a2, $sp, 0x48
  addiu $a1, $sp, 0x44
  addiu $a0, $sp, 0x40
  jal   guNormalize
   swc1  $f4, %lo(flt_CODE_bss_80067DE0)($at)
  lui    $at, %hi(flt_CODE_bss_80067DE0)
  lwc1  $f12, 0x3c($sp)
  lwc1  $f6, %lo(flt_CODE_bss_80067DE0)($at)
  mul.s $f12, $f12, $f6
  jal   sinf
   swc1  $f12, 0x3c($sp)
  lwc1  $f12, 0x3c($sp)
  jal   cosf
   swc1  $f0, 0x34($sp)
  lwc1  $f10, 0x40($sp)
  lwc1  $f4, 0x44($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  mul.s $f6, $f10, $f4
  move  $a0, $s0
  sub.s $f2, $f8, $f0
  lwc1  $f8, 0x48($sp)
  swc1  $f0, 0x30($sp)
  mul.s $f16, $f6, $f2
  nop   
  mul.s $f6, $f4, $f8
  swc1  $f16, 0x2c($sp)
  mul.s $f18, $f6, $f2
  nop   
  mul.s $f4, $f8, $f10
  swc1  $f18, 0x28($sp)
  mul.s $f6, $f4, $f2
  jal   guMtxIdentF
   swc1  $f6, 0x24($sp)
  lwc1  $f8, 0x40($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  mul.s $f0, $f8, $f8
  lwc1  $f12, 0x30($sp)
  lwc1  $f14, 0x34($sp)
  lwc1  $f16, 0x2c($sp)
  lwc1  $f18, 0x28($sp)
  sub.s $f4, $f10, $f0
  mul.s $f6, $f4, $f12
  add.s $f8, $f6, $f0
  swc1  $f8, ($s0)
  lwc1  $f10, 0x40($sp)
  mul.s $f4, $f10, $f14
  sub.s $f6, $f18, $f4
  swc1  $f6, 0x24($s0)
  lwc1  $f8, 0x40($sp)
  mul.s $f10, $f8, $f14
  mtc1  $at, $f8
  add.s $f4, $f10, $f18
  swc1  $f4, 0x18($s0)
  lwc1  $f6, 0x44($sp)
  mul.s $f2, $f6, $f6
  sub.s $f10, $f8, $f2
  mul.s $f4, $f10, $f12
  add.s $f6, $f4, $f2
  swc1  $f6, 0x14($s0)
  lwc1  $f8, 0x44($sp)
  lwc1  $f4, 0x24($sp)
  mul.s $f10, $f8, $f14
  add.s $f6, $f10, $f4
  swc1  $f6, 0x20($s0)
  lwc1  $f10, 0x44($sp)
  lwc1  $f8, 0x24($sp)
  mul.s $f4, $f10, $f14
  sub.s $f6, $f8, $f4
  mtc1  $at, $f8
  swc1  $f6, 8($s0)
  lwc1  $f10, 0x48($sp)
  mul.s $f0, $f10, $f10
  sub.s $f4, $f8, $f0
  mul.s $f6, $f4, $f12
  add.s $f10, $f6, $f0
  swc1  $f10, 0x28($s0)
  lwc1  $f8, 0x48($sp)
  mul.s $f4, $f8, $f14
  sub.s $f6, $f16, $f4
  swc1  $f6, 0x10($s0)
  lwc1  $f10, 0x48($sp)
  mul.s $f8, $f10, $f14
  add.s $f4, $f8, $f16
  swc1  $f4, 4($s0)
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   

glabel guRotate
  mtc1  $a1, $f12
  mtc1  $a2, $f14
  mtc1  $a3, $f16
  addiu $sp, $sp, -0x60
  lwc1  $f4, 0x70($sp)
  sw    $ra, 0x1c($sp)
  sw    $a0, 0x60($sp)
  mfc1  $a1, $f12
  mfc1  $a2, $f14
  mfc1  $a3, $f16
  addiu $a0, $sp, 0x20
  jal   guRotateF
   swc1  $f4, 0x10($sp)
  addiu $a0, $sp, 0x20
  jal   guMtxF2L
   lw    $a1, 0x60($sp)
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x60
  jr    $ra
   nop   
.align 4

.section .rodata
glabel F32_80029810
.float 0.017453292
.align 4

.section .bss
glabel flt_CODE_bss_80067DE0
.word 0
.word 0,0,0

.section .text
glabel __d_to_ll
  trunc.l.d $f4, $f12
  dmfc1 $v0, $f4
  nop   
  dsll32 $v1, $v0, 0
  dsra32 $v1, $v1, 0
  jr    $ra
   dsra32 $v0, $v0, 0

glabel __f_to_ll
  trunc.l.s $f4, $f12
  dmfc1 $v0, $f4
  nop   
  dsll32 $v1, $v0, 0
  dsra32 $v1, $v1, 0
  jr    $ra
   dsra32 $v0, $v0, 0

glabel __d_to_ull
  cfc1  $t6, $31
  li    $v0, 1
  ctc1  $v0, $31
  nop   
  cvt.l.d $f4, $f12
  cfc1  $v0, $31
  nop   
  andi  $at, $v0, 4
  andi  $v0, $v0, 0x78
  beqz  $v0, .L700179C4
   li    $at, 0x43E00000 # 448.000000
  mtc1  $at, $f5
  mtc1  $zero, $f4
  li    $v0, 1
  sub.d $f4, $f12, $f4
  ctc1  $v0, $31
  nop   
  cvt.l.d $f4, $f4
  cfc1  $v0, $31
  nop   
  andi  $at, $v0, 4
  andi  $v0, $v0, 0x78
  bnez  $v0, .L700179BC
   nop   
  lui   $t7, %hi(D_80029820) 
  ld    $t7, %lo(D_80029820)($t7)
  dmfc1 $v0, $f4
  b     .L700179D4
   or    $v0, $v0, $t7
.L700179BC:
  b     .L700179D4
   li    $v0, -1
.L700179C4:
  dmfc1 $v0, $f4
  nop   
  bltz  $v0, .L700179BC
   nop   
.L700179D4:
  ctc1  $t6, $31
  dsll32 $v1, $v0, 0
  dsra32 $v1, $v1, 0
  jr    $ra
   dsra32 $v0, $v0, 0

glabel __f_to_ull
  cfc1  $t6, $31
  li    $v0, 1
  ctc1  $v0, $31
  nop   
  cvt.l.s $f4, $f12
  cfc1  $v0, $31
  nop   
  andi  $at, $v0, 4
  andi  $v0, $v0, 0x78
  beqz  $v0, .L70017A60
   li    $at, 0x5F000000 # 9223372036854775808.000000
  mtc1  $at, $f4
  li    $v0, 1
  sub.s $f4, $f12, $f4
  ctc1  $v0, $31
  nop   
  cvt.l.s $f4, $f4
  cfc1  $v0, $31
  nop   
  andi  $at, $v0, 4
  andi  $v0, $v0, 0x78
  bnez  $v0, .L70017A58
   nop   
  lui   $t7, %hi(D_80029828) 
  ld    $t7, %lo(D_80029828)($t7)
  dmfc1 $v0, $f4
  b     .L70017A70
   or    $v0, $v0, $t7
.L70017A58:
  b     .L70017A70
   li    $v0, -1
.L70017A60:
  dmfc1 $v0, $f4
  nop   
  bltz  $v0, .L70017A58
   nop   
.L70017A70:
  ctc1  $t6, $31
  dsll32 $v1, $v0, 0
  dsra32 $v1, $v1, 0
  jr    $ra
   dsra32 $v0, $v0, 0

glabel __ll_to_d
  sw    $a0, ($sp)
  sw    $a1, 4($sp)
  ld    $t6, ($sp)
  dmtc1 $t6, $f4
  jr    $ra
   cvt.d.l $f0, $f4

glabel __ll_to_f
  sw    $a0, ($sp)
  sw    $a1, 4($sp)
  ld    $t6, ($sp)
  dmtc1 $t6, $f4
  jr    $ra
   cvt.s.l $f0, $f4

glabel __ull_to_d
  sw    $a0, ($sp)
  sw    $a1, 4($sp)
  ld    $t6, ($sp)
  dmtc1 $t6, $f4
  bgez  $t6, .L70017AE0
   cvt.d.l $f0, $f4
  li    $at, 0x41F00000 # 30.000000
  mtc1  $at, $f7
  mtc1  $zero, $f6
  nop   
  add.d $f0, $f0, $f6
.L70017AE0:
  jr    $ra
   nop   

glabel __ull_to_f
  sw    $a0, ($sp)
  sw    $a1, 4($sp)
  ld    $t6, ($sp)
  dmtc1 $t6, $f4
  bgez  $t6, .L70017B10
   cvt.s.l $f0, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f6
  nop   
  add.s $f0, $f0, $f6
.L70017B10:
  jr    $ra
   nop   
.align 4
.section .rodata
glabel D_80029820
.word 0x80000000, 0
glabel D_80029828
.word 0x80000000, 0

.section .text  
glabel __osSetSR
  mtc0  $a0, $12
  nop   
  jr    $ra
   nop   

glabel __osGetSR
  mfc0  $v0, $12
  jr    $ra
   nop   

  nop   
glabel __osSiRawReadIo
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  jal   __osSiDeviceBusy
   sw    $a1, 0x1c($sp)
  beqz  $v0, .L70017B64
   nop   
  b     .L70017B80
   li    $v0, -1
.L70017B64:
  lw    $t6, 0x18($sp)
  lui   $at, 0xa000
  lw    $t9, 0x1c($sp)
  or    $t7, $t6, $at
  lw    $t8, ($t7)
  move  $v0, $zero
  sw    $t8, ($t9)
.L70017B80:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   

glabel __osSiRawWriteIo
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  jal   __osSiDeviceBusy
   sw    $a1, 0x1c($sp)
  beqz  $v0, .L70017BB4
   nop   
  b     .L70017BCC
   li    $v0, -1
.L70017BB4:
  lw    $t7, 0x18($sp)
  lw    $t6, 0x1c($sp)
  lui   $at, 0xa000
  or    $t8, $t7, $at
  move  $v0, $zero
  sw    $t6, ($t8)
.L70017BCC:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   

  nop   
glabel osPiRawReadIo
  lui   $t6, %hi(PI_STATUS_REG) # $t6, 0xa460
  lw    $a2, %lo(PI_STATUS_REG)($t6)
  addiu $sp, $sp, -8
  andi  $t7, $a2, 3
  beqz  $t7, .L70017C0C
   nop   
.L70017BF8:
  lui   $t8, %hi(PI_STATUS_REG) # $t8, 0xa460
  lw    $a2, %lo(PI_STATUS_REG)($t8)
  andi  $t9, $a2, 3
  bnez  $t9, .L70017BF8
   nop   
.L70017C0C:
  lui   $t0, %hi(osRomBase) 
  lw    $t0, %lo(osRomBase)($t0)
  lui   $at, 0xa000
  move  $v0, $zero
  or    $t1, $t0, $a0
  or    $t2, $t1, $at
  lw    $t3, ($t2)
  addiu $sp, $sp, 8
  jr    $ra
   sw    $t3, ($a1)

  nop   
  nop   
  nop   
glabel _blkclr
  slti  $at, $a1, 0xc
  bnez  $at, .L70017CBC
   negu  $v1, $a0
  andi  $v1, $v1, 3
  beqz  $v1, .L70017C60
   subu  $a1, $a1, $v1
  swl   $zero, ($a0)
  addu  $a0, $a0, $v1
.L70017C60:
  li    $at, -32
  and   $a3, $a1, $at
  beqz  $a3, .L70017C9C
   subu  $a1, $a1, $a3
  addu  $a3, $a3, $a0
.L70017C74:
  addiu $a0, $a0, 0x20
  sw    $zero, -0x20($a0)
  sw    $zero, -0x1c($a0)
  sw    $zero, -0x18($a0)
  sw    $zero, -0x14($a0)
  sw    $zero, -0x10($a0)
  sw    $zero, -0xc($a0)
  sw    $zero, -8($a0)
  bne   $a0, $a3, .L70017C74
   sw    $zero, -4($a0)
.L70017C9C:
  li    $at, -4
  and   $a3, $a1, $at
  beqz  $a3, .L70017CBC
   subu  $a1, $a1, $a3
  addu  $a3, $a3, $a0
.L70017CB0:
  addiu $a0, $a0, 4
  bne   $a0, $a3, .L70017CB0
   sw    $zero, -4($a0)
.L70017CBC:
  blez  $a1, .L70017CD4
   nop   
  addu  $a1, $a1, $a0
.L70017CC8:
  addiu $a0, $a0, 1
  bne   $a0, $a1, .L70017CC8
   sb    $zero, -1($a0)
.L70017CD4:
  jr    $ra
   nop   

  nop   
glabel __osSetHWIntrRoutine
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  sw    $a0, 0x28($sp)
  sw    $a1, 0x2c($sp)
  jal   __osDisableInt
   sw    $s0, 0x18($sp)
  lw    $t7, 0x28($sp)
  lw    $t6, 0x2c($sp)
  lui   $at, %hi(__osHwIntTable)
  sll   $t8, $t7, 2
  move  $s0, $v0
  addu  $at, $at, $t8
  move  $a0, $s0
  jal   __osRestoreInt
   sw    $t6, %lo(__osHwIntTable)($at)
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   

.section .bss
glabel leoDiskStack
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0


.section .text
glabel __osLeoInterrupt
  lui   $t6, %hi(osDiskExist) 
  lw    $t6, %lo(osDiskExist)($t6)
  addiu $sp, $sp, -0x40
  sw    $ra, 0x1c($sp)
  bnez  $t6, .L70017D50
   nop   
  b     .L70018404
   move  $v0, $zero
.L70017D50:
  lui   $t7, %hi(__osDiskHandle) 
  lw    $t7, %lo(__osDiskHandle)($t7)
  lui   $t3, %hi(PI_STATUS_REG) # $t3, 0xa460
  addiu $t8, $t7, 0x14
  sw    $t8, 0x30($sp)
  lhu   $t9, 0x1a($t7)
  sll   $t0, $t9, 3
  addu  $t0, $t0, $t9
  sll   $t0, $t0, 2
  addu  $t1, $t8, $t0
  addiu $t2, $t1, 0x18
  sw    $t2, 0x2c($sp)
  lw    $t4, %lo(PI_STATUS_REG)($t3)
  sw    $t4, 0x38($sp)
  lw    $t5, 0x38($sp)
  andi  $t6, $t5, 1
  beqz  $t6, .L70017E64
   nop   
  li    $t7, 3
  lui   $t9, %hi(PI_STATUS_REG) # $t9, 0xa460
  sw    $t7, %lo(PI_STATUS_REG)($t9)
  lui   $t8, %hi(PI_STATUS_REG) # $t8, 0xa460
  lw    $t0, %lo(PI_STATUS_REG)($t8)
  sw    $t0, 0x38($sp)
  lw    $t1, 0x38($sp)
  andi  $t2, $t1, 2
  beqz  $t2, .L70017DDC
   nop   
.L70017DC0:
  lui   $t3, %hi(PI_STATUS_REG) # $t3, 0xa460
  lw    $t4, %lo(PI_STATUS_REG)($t3)
  sw    $t4, 0x38($sp)
  lw    $t5, 0x38($sp)
  andi  $t6, $t5, 2
  bnez  $t6, .L70017DC0
   nop   
.L70017DDC:
  lui   $t7, %hi(ASIC_STATUS) # $t7, 0xa500
  lw    $t9, %lo(ASIC_STATUS)($t7)
  lui   $at, 0x200
  sw    $t9, 0x3c($sp)
  lw    $t8, 0x3c($sp)
  and   $t0, $t8, $at
  beqz  $t0, .L70017E4C
   nop   
  lui   $t1, %hi(PI_STATUS_REG) # $t1, 0xa460
  lw    $t2, %lo(PI_STATUS_REG)($t1)
  sw    $t2, 0x38($sp)
  lw    $t3, 0x38($sp)
  andi  $t4, $t3, 2
  beqz  $t4, .L70017E34
   nop   
.L70017E18:
  lui   $t5, %hi(PI_STATUS_REG) # $t5, 0xa460
  lw    $t6, %lo(PI_STATUS_REG)($t5)
  sw    $t6, 0x38($sp)
  lw    $t7, 0x38($sp)
  andi  $t9, $t7, 2
  bnez  $t9, .L70017E18
   nop   
.L70017E34:
  lw    $t8, 0x30($sp)
  lui   $at, 0x100
  lui   $t2, %hi(ASIC_BM_STATUS) # $t2, 0xa500
  lw    $t0, 0x10($t8)
  or    $t1, $t0, $at
  sw    $t1, %lo(ASIC_BM_STATUS)($t2)
.L70017E4C:
  lw    $t4, 0x2c($sp)
  li    $t3, 75
  jal   __osLeoInterrupt_sub1
   sw    $t3, ($t4)
  b     .L70018404
   li    $v0, 1
.L70017E64:
  lui   $t5, %hi(PI_STATUS_REG) # $t5, 0xa460
  lw    $t6, %lo(PI_STATUS_REG)($t5)
  sw    $t6, 0x38($sp)
  lw    $t7, 0x38($sp)
  andi  $t9, $t7, 2
  beqz  $t9, .L70017E9C
   nop   
.L70017E80:
  lui   $t8, %hi(PI_STATUS_REG) # $t8, 0xa460
  lw    $t0, %lo(PI_STATUS_REG)($t8)
  sw    $t0, 0x38($sp)
  lw    $t1, 0x38($sp)
  andi  $t2, $t1, 2
  bnez  $t2, .L70017E80
   nop   
.L70017E9C:
  lui   $t3, %hi(ASIC_STATUS) # $t3, 0xa500
  lw    $t4, %lo(ASIC_STATUS)($t3)
  lui   $at, 0x200
  sw    $t4, 0x3c($sp)
  lw    $t5, 0x3c($sp)
  and   $t6, $t5, $at
  beqz  $t6, .L70017F1C
   nop   
  lui   $t7, %hi(PI_STATUS_REG) # $t7, 0xa460
  lw    $t9, %lo(PI_STATUS_REG)($t7)
  sw    $t9, 0x38($sp)
  lw    $t8, 0x38($sp)
  andi  $t0, $t8, 2
  beqz  $t0, .L70017EF4
   nop   
.L70017ED8:
  lui   $t1, %hi(PI_STATUS_REG) # $t1, 0xa460
  lw    $t2, %lo(PI_STATUS_REG)($t1)
  sw    $t2, 0x38($sp)
  lw    $t3, 0x38($sp)
  andi  $t4, $t3, 2
  bnez  $t4, .L70017ED8
   nop   
.L70017EF4:
  lw    $t5, 0x30($sp)
  lui   $at, 0x100
  lui   $t9, %hi(ASIC_BM_STATUS) # $t9, 0xa500
  lw    $t6, 0x10($t5)
  move  $v0, $zero
  or    $t7, $t6, $at
  sw    $t7, %lo(ASIC_BM_STATUS)($t9)
  lw    $t8, 0x2c($sp)
  b     .L70018404
   sw    $zero, ($t8)
.L70017F1C:
  lw    $t0, 0x3c($sp)
  lui   $at, 0x800
  and   $t1, $t0, $at
  beqz  $t1, .L70017F70
   nop   
  lw    $t3, 0x2c($sp)
  li    $t2, 3
  jal   __osLeoInterrupt_sub2
   sw    $t2, ($t3)
  li    $t4, 2
  lui   $t5, %hi(PI_STATUS_REG) # $t5, 0xa460
  sw    $t4, %lo(PI_STATUS_REG)($t5)
  lui   $t6, %hi(__OSGlobalIntMask) 
  lw    $t6, %lo(__OSGlobalIntMask)($t6)
  lui   $at, (0x00100401 >> 16) # lui $at, 0x10
  ori   $at, (0x00100401 & 0xFFFF) # ori $at, $at, 0x401
  or    $t7, $t6, $at
  lui   $at, %hi(__OSGlobalIntMask)
  sw    $t7, %lo(__OSGlobalIntMask)($at)
  b     .L70018404
   li    $v0, 1
.L70017F70:
  lw    $t9, 0x30($sp)
  li    $at, 1
  lw    $t8, ($t9)
  bne   $t8, $at, .L7001806C
   nop   
  lw    $t0, 0x3c($sp)
  lui   $at, 0x4000
  and   $t1, $t0, $at
  bnez  $t1, .L70018018
   nop   
  lhu   $t4, 4($t9)
  lw    $t2, 8($t9)
  sll   $t5, $t4, 2
  addu  $t5, $t5, $t4
  sll   $t5, $t5, 2
  addu  $t5, $t5, $t4
  sll   $t5, $t5, 2
  addu  $t5, $t5, $t4
  addiu $t3, $t2, 1
  beq   $t3, $t5, .L70017FDC
   nop   
  lw    $t7, 0x2c($sp)
  li    $t6, 6
  jal   __osLeoInterrupt_sub1
   sw    $t6, ($t7)
  b     .L70018404
   li    $v0, 1
.L70017FDC:
  li    $t8, 2
  lui   $t0, %hi(PI_STATUS_REG) # $t0, 0xa460
  sw    $t8, %lo(PI_STATUS_REG)($t0)
  lui   $t1, %hi(__OSGlobalIntMask) 
  lw    $t1, %lo(__OSGlobalIntMask)($t1)
  lui   $at, (0x00100401 >> 16) # lui $at, 0x10
  ori   $at, (0x00100401 & 0xFFFF) # ori $at, $at, 0x401
  or    $t2, $t1, $at
  lw    $t9, 0x2c($sp)
  lui   $at, %hi(__OSGlobalIntMask)
  sw    $t2, %lo(__OSGlobalIntMask)($at)
  jal   __osLeoInterrupt_sub2
   sw    $zero, ($t9)
  b     .L70018404
   li    $v0, 1
.L70018018:
  lw    $t4, 0x2c($sp)
  lui   $a0, %hi(__osDiskHandle)
  lui   $a2, (0x05000400 >> 16) # lui $a2, 0x500
  lw    $t3, 4($t4)
  lw    $t5, 0xc($t4)
  ori   $a2, (0x05000400 & 0xFFFF) # ori $a2, $a2, 0x400
  li    $a1, 1
  addu  $t6, $t3, $t5
  sw    $t6, 4($t4)
  lw    $t7, 0x30($sp)
  lw    $t8, 8($t7)
  addiu $t0, $t8, 1
  sw    $t0, 8($t7)
  lw    $t1, 0x2c($sp)
  lw    $a0, %lo(__osDiskHandle)($a0)
  lw    $t2, 0xc($t1)
  lw    $a3, 4($t1)
  jal   osEPiRawStartDma
   sw    $t2, 0x10($sp)
  b     .L70018404
   li    $v0, 1
.L7001806C:
  lw    $t9, 0x30($sp)
  lw    $t3, ($t9)
  bnez  $t3, .L700183F0
   nop   
  lhu   $t5, 4($t9)
  li    $at, 3
  bne   $t5, $at, .L700180E4
   nop   
  lw    $t4, 0x2c($sp)
  lw    $t6, 8($t9)
  lw    $t8, 0x10($t4)
  addiu $t0, $t8, 0x11
  slt   $at, $t0, $t6
  beqz  $at, .L700180B8
   nop   
  jal   __osLeoInterrupt_sub1
   sw    $zero, ($t4)
  b     .L70018404
   li    $v0, 1
.L700180B8:
  lw    $t7, 0x3c($sp)
  lui   $at, 0x4000
  and   $t1, $t7, $at
  bnez  $t1, .L700180F8
   nop   
  lw    $t3, 0x2c($sp)
  li    $t2, 17
  jal   __osLeoInterrupt_sub1
   sw    $t2, ($t3)
  b     .L70018404
   li    $v0, 1
.L700180E4:
  lw    $t5, 0x2c($sp)
  lw    $t9, 4($t5)
  lw    $t8, 0xc($t5)
  addu  $t6, $t9, $t8
  sw    $t6, 4($t5)
.L700180F8:
  lui   $t0, %hi(ASIC_BM_STATUS) # $t0, 0xa500
  lw    $t4, %lo(ASIC_BM_STATUS)($t0)
  lui   $at, 0x20
  sw    $t4, 0x34($sp)
  lw    $t7, 0x34($sp)
  and   $t1, $t7, $at
  beqz  $t1, .L70018124
   lui   $at, 0x40
  and   $t2, $t7, $at
  bnez  $t2, .L70018138
   nop   
.L70018124:
  lw    $t3, 0x34($sp)
  lui   $at, 0x200
  and   $t9, $t3, $at
  beqz  $t9, .L700181BC
   nop   
.L70018138:
  lw    $t8, 0x2c($sp)
  lw    $t6, 0x10($t8)
  sltiu $at, $t6, 4
  bnez  $at, .L70018188
   nop   
  lw    $t5, 0x30($sp)
  li    $at, 3
  lhu   $t0, 4($t5)
  bne   $t0, $at, .L70018170
   nop   
  lw    $t4, 8($t5)
  slti  $at, $t4, 0x53
  bnez  $at, .L700181AC
   nop   
.L70018170:
  lw    $t7, 0x2c($sp)
  li    $t1, 17
  jal   __osLeoInterrupt_sub1
   sw    $t1, ($t7)
  b     .L70018404
   li    $v0, 1
.L70018188:
  lw    $t2, 0x2c($sp)
  lw    $t9, 0x30($sp)
  lw    $t3, 0x10($t2)
  sw    $t3, 0x28($sp)
  lw    $t8, 8($t9)
  sll   $t0, $t3, 2
  addu  $t5, $t2, $t0
  addiu $t6, $t8, 1
  sw    $t6, 0x14($t5)
.L700181AC:
  lw    $t4, 0x2c($sp)
  lw    $t1, 0x10($t4)
  addiu $t7, $t1, 1
  sw    $t7, 0x10($t4)
.L700181BC:
  lw    $t9, 0x3c($sp)
  lui   $at, 0x1000
  and   $t8, $t9, $at
  beqz  $t8, .L700182A0
   nop   
  lw    $t3, 0x30($sp)
  li    $at, 87
  lw    $t2, 8($t3)
  beq   $t2, $at, .L700181F4
   nop   
  lw    $t6, 0x2c($sp)
  li    $t0, 6
  jal   __osLeoInterrupt_sub1
   sw    $t0, ($t6)
.L700181F4:
  lw    $t5, 0x30($sp)
  li    $at, 2
  lhu   $t1, 4($t5)
  bne   $t1, $at, .L70018240
   nop   
  lhu   $t7, 6($t5)
  bnez  $t7, .L70018240
   nop   
  li    $t4, 1
  sh    $t4, 6($t5)
  lw    $t8, 0x30($sp)
  li    $t9, -1
  sw    $t9, 8($t8)
  lw    $t3, 0x30($sp)
  lw    $t2, 0x40($t3)
  lw    $t0, 0x48($t3)
  subu  $t6, $t2, $t0
  b     .L70018268
   sw    $t6, 0x40($t3)
.L70018240:
  li    $t1, 2
  lui   $t7, %hi(PI_STATUS_REG) # $t7, 0xa460
  sw    $t1, %lo(PI_STATUS_REG)($t7)
  lui   $t4, %hi(__OSGlobalIntMask) 
  lw    $t4, %lo(__OSGlobalIntMask)($t4)
  lui   $at, (0x00100401 >> 16) # lui $at, 0x10
  ori   $at, (0x00100401 & 0xFFFF) # ori $at, $at, 0x401
  or    $t5, $t4, $at
  lui   $at, %hi(__OSGlobalIntMask)
  sw    $t5, %lo(__OSGlobalIntMask)($at)
.L70018268:
  lw    $t9, 0x2c($sp)
  lui   $a0, %hi(__osDiskHandle)
  lw    $a0, %lo(__osDiskHandle)($a0)
  lw    $t8, 0xc($t9)
  lw    $a3, 8($t9)
  move  $a1, $zero
  sll   $t2, $t8, 2
  sw    $t2, 0x10($sp)
  jal   osEPiRawStartDma
   lui   $a2, 0x500
  lw    $t0, 0x2c($sp)
  li    $v0, 1
  b     .L70018404
   sw    $zero, ($t0)
.L700182A0:
  lw    $t6, 0x30($sp)
  li    $at, -1
  lw    $t3, 8($t6)
  bne   $t3, $at, .L70018334
   nop   
  lhu   $t1, 4($t6)
  li    $at, 2
  bne   $t1, $at, .L70018334
   nop   
  lhu   $t7, 6($t6)
  li    $at, 1
  bne   $t7, $at, .L70018334
   nop   
  addiu $t4, $t6, 0x18
  sw    $t4, 0x24($sp)
  lw    $t5, 0x28($t6)
  bnez  $t5, .L70018328
   nop   
  lw    $t9, 0x20($t6)
  lw    $t8, ($t9)
  lw    $t2, 4($t9)
  lw    $t3, 8($t9)
  lw    $t7, 0xc($t9)
  or    $t0, $t8, $t2
  or    $t1, $t0, $t3
  or    $t4, $t7, $t1
  beqz  $t4, .L70018328
   nop   
  lw    $t6, 0x2c($sp)
  li    $t5, 6
  jal   __osLeoInterrupt_sub1
   sw    $t5, ($t6)
  b     .L70018404
   li    $v0, 1
.L70018328:
  lw    $t8, 0x2c($sp)
  jal   __osLeoInterrupt_sub2
   sw    $zero, ($t8)
.L70018334:
  lw    $t2, 0x30($sp)
  lui   $at, 0x4000
  lw    $t0, 8($t2)
  addiu $t3, $t0, 1
  sw    $t3, 8($t2)
  lw    $t9, 0x3c($sp)
  and   $t7, $t9, $at
  beqz  $t7, .L700183BC
   nop   
  lw    $t1, 0x30($sp)
  lw    $t4, 8($t1)
  slti  $at, $t4, 0x55
  bnez  $at, .L70018384
   nop   
  lw    $t6, 0x2c($sp)
  li    $t5, 6
  jal   __osLeoInterrupt_sub1
   sw    $t5, ($t6)
  b     .L70018404
   li    $v0, 1
.L70018384:
  lw    $t8, 0x2c($sp)
  lui   $a0, %hi(__osDiskHandle)
  lui   $a2, (0x05000400 >> 16) # lui $a2, 0x500
  lw    $t0, 0xc($t8)
  lw    $a3, 4($t8)
  ori   $a2, (0x05000400 & 0xFFFF) # ori $a2, $a2, 0x400
  lw    $a0, %lo(__osDiskHandle)($a0)
  move  $a1, $zero
  jal   osEPiRawStartDma
   sw    $t0, 0x10($sp)
  lw    $t3, 0x2c($sp)
  li    $v0, 1
  b     .L70018404
   sw    $zero, ($t3)
.L700183BC:
  lw    $t2, 0x30($sp)
  lw    $t9, 8($t2)
  slti  $at, $t9, 0x55
  beqz  $at, .L700183E8
   nop   
  lw    $t1, 0x2c($sp)
  li    $t7, 6
  jal   __osLeoInterrupt_sub1
   sw    $t7, ($t1)
  b     .L70018404
   li    $v0, 1
.L700183E8:
  b     .L70018404
   li    $v0, 1
.L700183F0:
  lw    $t5, 0x2c($sp)
  li    $t4, 75
  jal   __osLeoInterrupt_sub1
   sw    $t4, ($t5)
  li    $v0, 1
.L70018404:
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x40
  jr    $ra
   nop   

glabel __osLeoInterrupt_sub1
  lui   $t6, %hi(__osDiskHandle) 
  lw    $t6, %lo(__osDiskHandle)($t6)
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  addiu $t7, $t6, 0x14
  sw    $t7, 0x1c($sp)
  lui   $t8, %hi(PI_STATUS_REG) # $t8, 0xa460
  lw    $t9, %lo(PI_STATUS_REG)($t8)
  sw    $t9, 0x18($sp)
  lw    $t0, 0x18($sp)
  andi  $t1, $t0, 2
  beqz  $t1, .L70018464
   nop   
.L70018448:
  lui   $t2, %hi(PI_STATUS_REG) # $t2, 0xa460
  lw    $t3, %lo(PI_STATUS_REG)($t2)
  sw    $t3, 0x18($sp)
  lw    $t4, 0x18($sp)
  andi  $t5, $t4, 2
  bnez  $t5, .L70018448
   nop   
.L70018464:
  lw    $t6, 0x1c($sp)
  lui   $at, 0x1000
  lui   $t9, %hi(ASIC_BM_STATUS) # $t9, 0xa500
  lw    $t7, 0x10($t6)
  lui   $t0, %hi(PI_STATUS_REG) # $t0, 0xa460
  or    $t8, $t7, $at
  sw    $t8, %lo(ASIC_BM_STATUS)($t9)
  lw    $t1, %lo(PI_STATUS_REG)($t0)
  sw    $t1, 0x18($sp)
  lw    $t2, 0x18($sp)
  andi  $t3, $t2, 2
  beqz  $t3, .L700184B4
   nop   
.L70018498:
  lui   $t4, %hi(PI_STATUS_REG) # $t4, 0xa460
  lw    $t5, %lo(PI_STATUS_REG)($t4)
  sw    $t5, 0x18($sp)
  lw    $t6, 0x18($sp)
  andi  $t7, $t6, 2
  bnez  $t7, .L70018498
   nop   
.L700184B4:
  lw    $t8, 0x1c($sp)
  lui   $t0, %hi(ASIC_BM_STATUS) # $t0, 0xa500
  lw    $t9, 0x10($t8)
  jal   __osLeoInterrupt_sub2
   sw    $t9, %lo(ASIC_BM_STATUS)($t0)
  li    $t1, 2
  lui   $t2, %hi(PI_STATUS_REG) # $t2, 0xa460
  sw    $t1, %lo(PI_STATUS_REG)($t2)
  lui   $t3, %hi(__OSGlobalIntMask) 
  lw    $t3, %lo(__OSGlobalIntMask)($t3)
  lui   $at, (0x00100401 >> 16) # lui $at, 0x10
  lw    $ra, 0x14($sp)
  ori   $at, (0x00100401 & 0xFFFF) # ori $at, $at, 0x401
  or    $t4, $t3, $at
  lui   $at, %hi(__OSGlobalIntMask)
  sw    $t4, %lo(__OSGlobalIntMask)($at)
  jr    $ra
   addiu $sp, $sp, 0x20

glabel __osLeoInterrupt_sub2
  addiu $sp, $sp, -0x30
  lui   $t6, %hi(__osEventStateTab) 
  addiu $t6, %lo(__osEventStateTab) # addiu $t6, $t6, 0x6a10
  addiu $t7, $t6, 0x40
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $t7, 0x2c($sp)
  lw    $t8, 0x40($t6)
  beqz  $t8, .L700185D4
   sw    $t8, 0x28($sp)
  lw    $t9, 8($t8)
  lw    $t0, 0x10($t8)
  slt   $at, $t9, $t0
  beqz  $at, .L700185D4
   nop   
  lw    $t1, 0x28($sp)
  lw    $t6, 0x2c($sp)
  lw    $t2, 0xc($t1)
  lw    $t3, 8($t1)
  lw    $t5, 0x10($t1)
  addu  $t4, $t2, $t3
  div   $zero, $t4, $t5
  mfhi  $t7
  sw    $t7, 0x24($sp)
  lw    $t0, 0x14($t1)
  lw    $t8, 4($t6)
  sll   $t9, $t7, 2
  addu  $t2, $t0, $t9
  sw    $t8, ($t2)
  lw    $t3, 0x28($sp)
  bnez  $t5, .L70018580
   nop   
  break 7
.L70018580:
  li    $at, -1
  bne   $t5, $at, .L70018598
   lui   $at, 0x8000
  bne   $t4, $at, .L70018598
   nop   
  break 6
.L70018598:
  lw    $t4, 8($t3)
  addiu $t5, $t4, 1
  sw    $t5, 8($t3)
  lw    $t6, 0x28($sp)
  lw    $t7, ($t6)
  lw    $t1, ($t7)
  beqz  $t1, .L700185D4
   nop   
  jal   __osPopThread
   move  $a0, $t6
  move  $s0, $v0
  lui   $a0, %hi(__osRunQueue)
  addiu $a0, %lo(__osRunQueue) # addiu $a0, $a0, 0x7728
  jal   __osEnqueueThread
   move  $a1, $s0
.L700185D4:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   

  nop   
  nop   
glabel __osDisableInt
  mfc0  $t0, $12
  li    $at, -2
  and   $t1, $t0, $at
  mtc0  $t1, $12
  andi  $v0, $t0, 1
  nop   
  jr    $ra
   nop   

glabel __osRestoreInt
  mfc0  $t0, $12
  or    $t0, $t0, $a0
  mtc0  $t0, $12
  nop   
  nop   
  jr    $ra
   nop   

  nop   
glabel __osTimerServicesInit
  lui   $at, %hi(__osCurrentTime)
  li    $t6, 0
  li    $t7, 0
  sw    $t7, %lo(__osCurrentTime+4)($at)
  sw    $t6, %lo(__osCurrentTime)($at)
  lui   $at, %hi(__osBaseCounter)
  lui   $t8, %hi(__osTimerList) 
  lw    $t8, %lo(__osTimerList)($t8)
  sw    $zero, %lo(__osBaseCounter)($at)
  lui   $at, %hi(__osViIntrCount)
  sw    $zero, %lo(__osViIntrCount)($at)
  lui   $t9, %hi(__osTimerList) 
  sw    $t8, 4($t8)
  lw    $t9, %lo(__osTimerList)($t9)
  lui   $t1, %hi(__osTimerList) 
  li    $t2, 0
  lw    $t0, 4($t9)
  li    $t3, 0
  lui   $t4, %hi(__osTimerList) 
  sw    $t0, ($t9)
  lw    $t1, %lo(__osTimerList)($t1)
  lui   $t5, %hi(__osTimerList) 
  lui   $t8, %hi(__osTimerList) 
  sw    $t2, 0x10($t1)
  sw    $t3, 0x14($t1)
  lw    $t4, %lo(__osTimerList)($t4)
  lw    $t6, 0x10($t4)
  lw    $t7, 0x14($t4)
  sw    $t6, 8($t4)
  sw    $t7, 0xc($t4)
  lw    $t5, %lo(__osTimerList)($t5)
  sw    $zero, 0x18($t5)
  lw    $t8, %lo(__osTimerList)($t8)
  jr    $ra
   sw    $zero, 0x1c($t8)

glabel __osTimerInterrupt
  lui   $t6, %hi(__osTimerList) 
  lw    $t6, %lo(__osTimerList)($t6)
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  lw    $t7, ($t6)
  beq   $t7, $t6, .L70018824
   nop   
.L700186D8:
  lui   $t8, %hi(__osTimerList) 
  lw    $t8, %lo(__osTimerList)($t8)
  lw    $t9, ($t8)
  bne   $t9, $t8, .L70018700
   sw    $t9, 0x24($sp)
  jal   __osSetCompare
   move  $a0, $zero
  lui   $at, %hi(__osTimerCounter)
  b     .L70018824
   sw    $zero, %lo(__osTimerCounter)($at)
.L70018700:
  jal   osGetCount
   nop   
  sw    $v0, 0x20($sp)
  lui   $t1, %hi(__osTimerCounter) 
  lw    $t1, %lo(__osTimerCounter)($t1)
  lw    $t0, 0x20($sp)
  lw    $t7, 0x24($sp)
  lui   $at, %hi(__osTimerCounter)
  subu  $t2, $t0, $t1
  sw    $t2, 0x1c($sp)
  sw    $t0, %lo(__osTimerCounter)($at)
  lw    $t6, 0x10($t7)
  lw    $t3, 0x1c($sp)
  li    $t4, 0
  move  $t9, $t7
  sltu  $at, $t6, $t4
  lw    $t7, 0x14($t7)
  bnez  $at, .L700187A0
   move  $t5, $t3
  sltu  $at, $t4, $t6
  bnez  $at, .L70018760
   sltu  $at, $t5, $t7
  beqz  $at, .L700187A0
   nop   
.L70018760:
  addiu $t8, $t9, 0x10
  sw    $t8, 0x18($sp)
  lw    $t3, 0x14($t9)
  lw    $t2, 0x10($t9)
  sltu  $at, $t3, $t5
  subu  $t0, $t2, $t4
  subu  $t0, $t0, $at
  subu  $t1, $t3, $t5
  sw    $t1, 0x14($t9)
  sw    $t0, 0x10($t9)
  lw    $t6, 0x24($sp)
  lw    $a0, 0x10($t6)
  jal   __osSetTimerIntr
   lw    $a1, 0x14($t6)
  b     .L70018824
   nop   
.L700187A0:
  lw    $t7, 0x24($sp)
  lw    $t8, ($t7)
  lw    $t2, 4($t7)
  sw    $t8, ($t2)
  lw    $t3, 0x24($sp)
  lw    $t4, 4($t3)
  lw    $t5, ($t3)
  sw    $t4, 4($t5)
  lw    $t0, 0x24($sp)
  sw    $zero, ($t0)
  lw    $t1, 0x24($sp)
  sw    $zero, 4($t1)
  lw    $t9, 0x24($sp)
  lw    $t6, 0x18($t9)
  beqz  $t6, .L700187F0
   nop   
  move  $a0, $t6
  lw    $a1, 0x1c($t9)
  jal   osSendMesg
   move  $a2, $zero
.L700187F0:
  lw    $t7, 0x24($sp)
  lw    $t8, 8($t7)
  lw    $t9, 0xc($t7)
  bnez  $t8, .L7001880C
   nop   
  beqz  $t9, .L700186D8
   nop   
.L7001880C:
  sw    $t8, 0x10($t7)
  sw    $t9, 0x14($t7)
  jal   __osInsertTimer
   lw    $a0, 0x24($sp)
  b     .L700186D8
   nop   
.L70018824:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   

glabel __osSetTimerIntr
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  sw    $a0, 0x28($sp)
  jal   __osDisableInt
   sw    $a1, 0x2c($sp)
  jal   osGetCount
   sw    $v0, 0x1c($sp)
  lui   $at, %hi(__osTimerCounter)
  sw    $v0, %lo(__osTimerCounter)($at)
  lui   $t6, %hi(__osTimerCounter) 
  lw    $t6, %lo(__osTimerCounter)($t6)
  lw    $t1, 0x2c($sp)
  lw    $t0, 0x28($sp)
  move  $t9, $t6
  addu  $t3, $t9, $t1
  li    $t8, 0
  sltu  $at, $t3, $t1
  addu  $t2, $at, $t8
  addu  $t2, $t2, $t0
  sw    $t2, 0x20($sp)
  sw    $t3, 0x24($sp)
  jal   __osSetCompare
   move  $a0, $t3
  jal   __osRestoreInt
   lw    $a0, 0x1c($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   

glabel __osInsertTimer
  addiu $sp, $sp, -0x38
  sw    $ra, 0x14($sp)
  jal   __osDisableInt
   sw    $a0, 0x38($sp)
  lui   $t6, %hi(__osTimerList) 
  lw    $t6, %lo(__osTimerList)($t6)
  sw    $v0, 0x24($sp)
  lw    $t8, 0x38($sp)
  lw    $t7, ($t6)
  sw    $t7, 0x34($sp)
  lw    $t1, 0x14($t8)
  lw    $t0, 0x10($t8)
  sw    $t1, 0x2c($sp)
  beq   $t7, $t6, .L70018984
   sw    $t0, 0x28($sp)
  lw    $t2, 0x10($t7)
  lw    $t3, 0x14($t7)
  sltu  $at, $t0, $t2
  bnez  $at, .L70018984
   sltu  $at, $t2, $t0
  bnez  $at, .L70018908
   sltu  $at, $t3, $t1
  beqz  $at, .L70018984
   nop   
.L70018908:
  addiu $t9, $sp, 0x28
  lw    $t8, 0x34($sp)
  sw    $t9, 0x20($sp)
  lw    $t5, 4($t9)
  lw    $t4, ($t9)
  lw    $t7, 0x14($t8)
  lw    $t6, 0x10($t8)
  lui   $t8, %hi(__osTimerList) 
  sltu  $at, $t5, $t7
  subu  $t0, $t4, $t6
  subu  $t0, $t0, $at
  subu  $t1, $t5, $t7
  sw    $t1, 4($t9)
  sw    $t0, ($t9)
  lw    $t2, 0x34($sp)
  lw    $t8, %lo(__osTimerList)($t8)
  lw    $t3, ($t2)
  beq   $t3, $t8, .L70018984
   sw    $t3, 0x34($sp)
  lw    $t4, 0x28($sp)
  lw    $t6, 0x10($t3)
  lw    $t5, 0x2c($sp)
  lw    $t7, 0x14($t3)
  sltu  $at, $t6, $t4
  bnez  $at, .L70018908
   nop   
  sltu  $at, $t4, $t6
  bnez  $at, .L70018984
   sltu  $at, $t7, $t5
  bnez  $at, .L70018908
   nop   
.L70018984:
  lw    $t9, 0x38($sp)
  lw    $t0, 0x28($sp)
  lw    $t1, 0x2c($sp)
  lui   $t8, %hi(__osTimerList) 
  sw    $t0, 0x10($t9)
  sw    $t1, 0x14($t9)
  lw    $t8, %lo(__osTimerList)($t8)
  lw    $t2, 0x34($sp)
  beq   $t2, $t8, .L700189DC
   nop   
  addiu $t3, $t2, 0x10
  sw    $t3, 0x1c($sp)
  lw    $t5, 0x14($t2)
  lw    $t4, 0x10($t2)
  lw    $t6, 0x28($sp)
  lw    $t7, 0x2c($sp)
  subu  $t0, $t4, $t6
  sltu  $at, $t5, $t7
  subu  $t0, $t0, $at
  subu  $t1, $t5, $t7
  sw    $t1, 0x14($t2)
  sw    $t0, 0x10($t2)
.L700189DC:
  lw    $t9, 0x34($sp)
  lw    $t8, 0x38($sp)
  sw    $t9, ($t8)
  lw    $t3, 0x34($sp)
  lw    $t5, 0x38($sp)
  lw    $t4, 4($t3)
  sw    $t4, 4($t5)
  lw    $t7, 0x34($sp)
  lw    $t6, 0x38($sp)
  lw    $t0, 4($t7)
  sw    $t6, ($t0)
  lw    $t2, 0x34($sp)
  lw    $t1, 0x38($sp)
  sw    $t1, 4($t2)
  jal   __osRestoreInt
   lw    $a0, 0x24($sp)
  lw    $ra, 0x14($sp)
  lw    $v0, 0x28($sp)
  lw    $v1, 0x2c($sp)
  jr    $ra
   addiu $sp, $sp, 0x38

.section .data
glabel __osTimerList
.word __osBaseTimer
.align 4
.section .bss
glabel __osBaseTimer
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
glabel __osCurrentTime
.word 0,0
glabel __osBaseCounter
.word 0
glabel __osViIntrCount
.word 0
glabel __osTimerCounter
.word 0
.word 0,0,0

#needs a proper home but works
glabel __osThreadSave
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0


.section .text
glabel osGetThreadPri
  bnez  $a0, .L70018A40
   nop   
  lui   $a0, %hi(__osRunningThread)
  lw    $a0, %lo(__osRunningThread)($a0)
.L70018A40:
  jr    $ra
   lw    $v0, 4($a0)

  nop   
  nop  


glabel __osViInit
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lui   $a0, %hi(vi)
  addiu $a0, %lo(vi) # addiu $a0, $a0, 0x7fe0
  jal   _blkclr
   li    $a1, 96
  lui   $t6, %hi(vi) 
  addiu $t6, %lo(vi) # addiu $t6, $t6, 0x7fe0
  lui   $at, %hi(__osViCurr)
  sw    $t6, %lo(__osViCurr)($at)
  lui   $at, %hi(__osViNext)
  addiu $t7, $t6, 0x30
  sw    $t7, %lo(__osViNext)($at)
  li    $t8, 1
  sh    $t8, 0x32($t6)
  lui   $t0, %hi(__osViCurr) 
  lw    $t0, %lo(__osViCurr)($t0)
  li    $t9, 1
  lui   $t1, %hi(copy_osTvType) 
  sh    $t9, 2($t0)
  lw    $t1, %lo(copy_osTvType)($t1)
  beqz  $t1, .L70018AD4
   nop   
  lui   $t3, %hi(__osViNext) 
  lw    $t3, %lo(__osViNext)($t3)
  lui   $t2, %hi(osViModeNtscLan1) 
  addiu $t2, %lo(osViModeNtscLan1) # addiu $t2, $t2, -0x7ce0
  lui   $t4, (0x02E6D354 >> 16) # lui $t4, 0x2e6
  ori   $t4, (0x02E6D354 & 0xFFFF) # ori $t4, $t4, 0xd354
  lui   $at, %hi(osViClock)
  sw    $t2, 8($t3)
  b     .L70018AF8
   sw    $t4, %lo(osViClock)($at)
.L70018AD4:
  lui   $t7, %hi(__osViNext) 
  lw    $t7, %lo(__osViNext)($t7)
  lui   $t5, %hi(osViModePalLan1) 
  addiu $t5, %lo(osViModePalLan1) # addiu $t5, $t5, -0x7c90
  lui   $t8, (0x02F5B2D2 >> 16) # lui $t8, 0x2f5
  ori   $t8, (0x02F5B2D2 & 0xFFFF) # ori $t8, $t8, 0xb2d2
  lui   $at, %hi(osViClock)
  sw    $t5, 8($t7)
  sw    $t8, %lo(osViClock)($at)
.L70018AF8:
  lui   $t9, %hi(__osViNext) 
  lw    $t9, %lo(__osViNext)($t9)
  li    $t6, 32
  lui   $t0, %hi(__osViNext) 
  sh    $t6, ($t9)
  lw    $t0, %lo(__osViNext)($t0)
  lui   $t3, %hi(VI_CURRENT_REG) # $t3, 0xa440
  lw    $t1, 8($t0)
  lw    $t2, 4($t1)
  sw    $t2, 0xc($t0)
  lw    $t4, %lo(VI_CURRENT_REG)($t3)
  sltiu $at, $t4, 0xb
  bnez  $at, .L70018B44
   nop   
.L70018B30:
  lui   $t5, %hi(VI_CURRENT_REG) # $t5, 0xa440
  lw    $t7, %lo(VI_CURRENT_REG)($t5)
  sltiu $at, $t7, 0xb
  beqz  $at, .L70018B30
   nop   
.L70018B44:
  lui   $t8, 0xa440
  jal   __osViSwapContext
   sw    $zero, ($t8)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   


.section .data
glabel _libultraosviSegmentDataStart

glabel vi
.byte    0,   0,   0,   0,   0,   0,   0,   0
.byte    0,   0,   0,   0,   0,   0,   0,   0
.byte    0,   0,   0,   0,   0,   0,   0,   0
.byte    0,   0,   0,   0,   0,   0,   0,   0
.byte    0,   0,   0,   0,   0,   0,   0,   0
.byte    0,   0,   0,   0,   0,   0,   0,   0

glabel vi_buffer_next
.byte    0,   0,   0,   0,   0,   0,   0,   0
.byte    0,   0,   0,   0,   0,   0,   0,   0
.byte    0,   0,   0,   0,   0,   0,   0,   0
.byte    0,   0,   0,   0,   0,   0,   0,   0
.byte    0,   0,   0,   0,   0,   0,   0,   0
.byte    0,   0,   0,   0,   0,   0,   0,   0

glabel __osViCurr
.word vi

glabel __osViNext
.word vi_buffer_next

glabel copy_osTvType
.word 1

glabel osViClock
.word 48681812

glabel _libultraosviSegmentDataEnd
.align 4


.section .text
glabel __osViGetCurrentContext
  lui   $v0, %hi(__osViCurr)
  jr    $ra
   lw    $v0, %lo(__osViCurr)($v0)

  nop   
glabel __osViSwapContext
  addiu $sp, $sp, -0x48
  sw    $s1, 0x1c($sp)
  sw    $ra, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s0, 0x18($sp)
  sw    $zero, 0x30($sp)
  lui   $s1, %hi(__osViNext)
  lui   $t6, %hi(VI_CURRENT_REG) # $t6, 0xa440
  lw    $s1, %lo(__osViNext)($s1)
  lw    $t7, %lo(VI_CURRENT_REG)($t6)
  lw    $s0, 8($s1)
  andi  $t8, $t7, 1
  sw    $t8, 0x30($sp)
  jal   osVirtualToPhysical
   lw    $a0, 4($s1)
  lw    $t9, 0x30($sp)
  move  $s2, $v0
  sll   $t0, $t9, 2
  addu  $t0, $t0, $t9
  sll   $t0, $t0, 2
  addu  $t1, $s0, $t0
  lw    $t2, 0x28($t1)
  addu  $t3, $t2, $s2
  sw    $t3, 0x3c($sp)
  lhu   $t4, ($s1)
  andi  $t5, $t4, 2
  beqz  $t5, .L70018BFC
   nop   
  lw    $t7, 0x20($s0)
  lw    $t6, 0x20($s1)
  li    $at, -4096
  and   $t8, $t7, $at
  or    $t9, $t6, $t8
  b     .L70018C04
   sw    $t9, 0x20($s1)
.L70018BFC:
  lw    $t0, 0x20($s0)
  sw    $t0, 0x20($s1)
.L70018C04:
  lhu   $t1, ($s1)
  andi  $t2, $t1, 4
  beqz  $t2, .L70018D14
   nop   
  lw    $t3, 0x30($sp)
  sll   $t4, $t3, 2
  addu  $t4, $t4, $t3
  sll   $t4, $t4, 2
  addu  $t5, $s0, $t4
  lw    $t7, 0x2c($t5)
  andi  $t6, $t7, 0xfff
  mtc1  $t6, $f6
  sw    $t6, 0x34($sp)
  lwc1  $f4, 0x24($s1)
  bgez  $t6, .L70018C54
   cvt.s.w $f8, $f6
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f10
  nop   
  add.s $f8, $f8, $f10
.L70018C54:
  mul.s $f16, $f4, $f8
  li    $t9, 1
  cfc1  $t8, $31
  ctc1  $t9, $31
  nop   
  cvt.w.s $f18, $f16
  cfc1  $t9, $31
  nop   
  andi  $at, $t9, 4
  andi  $t9, $t9, 0x78
  beqz  $t9, .L70018CCC
   li    $at, 0x4F000000 # 2147483648.000000
  mtc1  $at, $f18
  li    $t9, 1
  sub.s $f18, $f16, $f18
  ctc1  $t9, $31
  nop   
  cvt.w.s $f18, $f18
  cfc1  $t9, $31
  nop   
  andi  $at, $t9, 4
  andi  $t9, $t9, 0x78
  bnez  $t9, .L70018CC4
   nop   
  mfc1  $t9, $f18
  lui   $at, 0x8000
  b     .L70018CDC
   or    $t9, $t9, $at
.L70018CC4:
  b     .L70018CDC
   li    $t9, -1
.L70018CCC:
  mfc1  $t9, $f18
  nop   
  bltz  $t9, .L70018CC4
   nop   
.L70018CDC:
  sw    $t9, 0x2c($s1)
  lw    $t1, 0x30($sp)
  lw    $t0, 0x2c($s1)
  li    $at, -4096
  sll   $t2, $t1, 2
  addu  $t2, $t2, $t1
  sll   $t2, $t2, 2
  addu  $t3, $s0, $t2
  lw    $t4, 0x2c($t3)
  ctc1  $t8, $31
  and   $t5, $t4, $at
  or    $t7, $t0, $t5
  b     .L70018D30
   sw    $t7, 0x2c($s1)
.L70018D14:
  lw    $t6, 0x30($sp)
  sll   $t8, $t6, 2
  addu  $t8, $t8, $t6
  sll   $t8, $t8, 2
  addu  $t9, $s0, $t8
  lw    $t1, 0x2c($t9)
  sw    $t1, 0x2c($s1)
.L70018D30:
  lw    $t2, 0x1c($s0)
  sw    $t2, 0x38($sp)
  lhu   $t3, ($s1)
  andi  $t4, $t3, 0x20
  beqz  $t4, .L70018D4C
   nop   
  sw    $zero, 0x38($sp)
.L70018D4C:
  lhu   $t0, ($s1)
  andi  $t5, $t0, 0x40
  beqz  $t5, .L70018D6C
   nop   
  sw    $zero, 0x2c($s1)
  jal   osVirtualToPhysical
   lw    $a0, 4($s1)
  sw    $v0, 0x3c($sp)
.L70018D6C:
  lhu   $t7, ($s1)
  andi  $t6, $t7, 0x80
  beqz  $t6, .L70018D9C
   nop   
  lhu   $t8, 0x28($s1)
  lui   $at, 0x3ff
  lw    $a0, 4($s1)
  sll   $t9, $t8, 0x10
  and   $t1, $t9, $at
  jal   osVirtualToPhysical
   sw    $t1, 0x2c($s1)
  sw    $v0, 0x3c($sp)
.L70018D9C:
  lw    $t2, 0x3c($sp)
  lui   $t3, %hi(VI_LEAP_REG) # $t3, 0xa440
  lui   $t0, %hi(VI_V_BURST_REG) # $t0, 0xa440
  sw    $t2, %lo(VI_ORIGIN_REG)($t3)
  lw    $t4, 8($s0)
  lui   $t7, %hi(VI_BURST_REG) # $t7, 0xa440
  lui   $t8, %hi(VI_V_SYNC_REG) # $t8, 0xa440
  sw    $t4, %lo(VI_WIDTH_REG)($t0)
  lw    $t5, 0xc($s0)
  lui   $t1, %hi(VI_H_SYNC_REG) # $t1, 0xa440
  lui   $at, %hi(__osViNext)
  sw    $t5, %lo(VI_BURST_REG)($t7)
  lw    $t6, 0x10($s0)
  sw    $t6, %lo(VI_V_SYNC_REG)($t8)
  lw    $t9, 0x14($s0)
  sw    $t9, %lo(VI_H_SYNC_REG)($t1)
  lw    $t2, 0x18($s0)
  lui   $t9, %hi(VI_INTR_REG) # $t9, 0xa440
  sw    $t2, %lo(VI_LEAP_REG)($t3)
  lw    $t4, 0x38($sp)
  sw    $t4, %lo(VI_H_START_REG)($t0)
  lw    $t5, 0x30($sp)
  sll   $t7, $t5, 2
  addu  $t7, $t7, $t5
  sll   $t7, $t7, 2
  addu  $t6, $s0, $t7
  lw    $t8, 0x30($t6)
  sw    $t8, %lo(VI_V_START_REG)($t9)
  lw    $t1, 0x30($sp)
  sll   $t2, $t1, 2
  addu  $t2, $t2, $t1
  sll   $t2, $t2, 2
  addu  $t3, $s0, $t2
  lw    $t4, 0x34($t3)
  lui   $t2, %hi(VI_X_SCALE_REG) # $t2, 0xa440
  sw    $t4, %lo(VI_V_BURST_REG)($t0)
  lw    $t5, 0x30($sp)
  lui   $t4, %hi(VI_Y_SCALE_REG) # $t4, 0xa440
  sll   $t7, $t5, 2
  addu  $t7, $t7, $t5
  sll   $t7, $t7, 2
  addu  $t6, $s0, $t7
  lw    $t8, 0x38($t6)
  lui   $t5, 0xa440
  lui   $t7, %hi(__osViCurr) 
  sw    $t8, %lo(VI_INTR_REG)($t9)
  lw    $t1, 0x20($s1)
  lui   $t8, %hi(__osViCurr) 
  lui   $t6, %hi(__osViNext) 
  sw    $t1, %lo(VI_X_SCALE_REG)($t2)
  lw    $t3, 0x2c($s1)
  sw    $t3, %lo(VI_Y_SCALE_REG)($t4)
  lw    $t0, 0xc($s1)
  sw    $t0, ($t5)
  lw    $t7, %lo(__osViCurr)($t7)
  sw    $t7, %lo(__osViNext)($at)
  lui   $at, %hi(__osViCurr)
  sw    $s1, %lo(__osViCurr)($at)
  lw    $t8, %lo(__osViCurr)($t8)
  lw    $t6, %lo(__osViNext)($t6)
  addiu $t2, $t8, 0x30
.L70018E90:
  lw    $at, ($t8)
  addiu $t8, $t8, 0xc
  addiu $t6, $t6, 0xc
  sw    $at, -0xc($t6)
  lw    $at, -8($t8)
  sw    $at, -8($t6)
  lw    $at, -4($t8)
  bne   $t8, $t2, .L70018E90
   sw    $at, -4($t6)
  lw    $ra, 0x24($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x48

  nop   
glabel __osSpGetStatus
  lui   $t6, 0xa404
  jr    $ra
   lw    $v0, 0x10($t6)

  nop   
glabel __osSpSetStatus
  lui   $t6, 0xa404
  jr    $ra
   sw    $a0, 0x10($t6)

  nop   
glabel __osSpSetPc
  lui   $t6, %hi(SP_STATUS_REG) # $t6, 0xa404
  lw    $a1, %lo(SP_STATUS_REG)($t6)
  addiu $sp, $sp, -8
  andi  $t7, $a1, 1
  bnez  $t7, .L70018F10
   nop   
  b     .L70018F1C
   li    $v0, -1
.L70018F10:
  lui   $t8, 0xa408
  sw    $a0, ($t8)
  move  $v0, $zero
.L70018F1C:
  jr    $ra
   addiu $sp, $sp, 8

  nop   
  nop   
  nop   
glabel __osSpRawStartDma
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  sw    $a1, 0x1c($sp)
  sw    $a2, 0x20($sp)
  jal   __osSpDeviceBusy
   sw    $a3, 0x24($sp)
  beqz  $v0, .L70018F5C
   nop   
  b     .L70018FAC
   li    $v0, -1
.L70018F5C:
  lw    $t6, 0x1c($sp)
  lui   $t7, 0xa404
  sw    $t6, ($t7)
  jal   osVirtualToPhysical
   lw    $a0, 0x20($sp)
  lui   $t8, %hi(SP_DRAM_ADDR_REG) # $t8, 0xa404
  sw    $v0, %lo(SP_DRAM_ADDR_REG)($t8)
  lw    $t9, 0x18($sp)
  bnez  $t9, .L70018F98
   nop   
  lw    $t0, 0x24($sp)
  lui   $t2, %hi(SP_WR_LEN_REG) # $t2, 0xa404
  addiu $t1, $t0, -1
  b     .L70018FA8
   sw    $t1, %lo(SP_WR_LEN_REG)($t2)
.L70018F98:
  lw    $t3, 0x24($sp)
  lui   $t5, %hi(SP_RD_LEN_REG) # $t5, 0xa404
  addiu $t4, $t3, -1
  sw    $t4, %lo(SP_RD_LEN_REG)($t5)
.L70018FA8:
  move  $v0, $zero
.L70018FAC:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   

  nop   
glabel __osSpDeviceBusy
  lui   $t6, %hi(SP_STATUS_REG) # $t6, 0xa404
  lw    $a0, %lo(SP_STATUS_REG)($t6)
  addiu $sp, $sp, -8
  andi  $t7, $a0, 0x1c
  beqz  $t7, .L70018FE0
   nop   
  b     .L70018FE4
   li    $v0, 1
.L70018FE0:
  move  $v0, $zero
.L70018FE4:
  jr    $ra
   addiu $sp, $sp, 8

  nop   
glabel __osDpDeviceBusy
  lui   $t6, %hi(DPC_STATUS_REG) # $t6, 0xa410
  lw    $a0, %lo(DPC_STATUS_REG)($t6)
  addiu $sp, $sp, -8
  andi  $t7, $a0, 0x100
  beqz  $t7, .L70019010
   nop   
  b     .L70019014
   li    $v0, 1
.L70019010:
  move  $v0, $zero
.L70019014:
  jr    $ra
   addiu $sp, $sp, 8

  nop   
glabel __osProbeTLB
  mfc0  $t0, $10
  andi  $t1, $t0, 0xff
  li    $at, -8192
  and   $t2, $a0, $at
  or    $t1, $t1, $t2
  mtc0  $t1, $10
  nop   
  nop   
  nop   
  tlbp  
  nop   
  nop   
  mfc0  $t3, $0
  lui   $at, 0x8000
  and   $t3, $t3, $at
  bnez  $t3, .L700190C8
   nop   
  tlbr  
  nop   
  nop   
  nop   
  mfc0  $t3, $5
  addi  $t3, $t3, 0x2000
  srl   $t3, $t3, 1
  and   $t4, $t3, $a0
  bnez  $t4, .L70019098
   addi  $t3, $t3, -1
  mfc0  $v0, $2
  b     .L7001909C
   nop   
.L70019098:
  mfc0  $v0, $3
.L7001909C:
  andi  $t5, $v0, 2
  beqz  $t5, .L700190C8
   nop   
  lui   $at, (0x3FFFFFC0 >> 16) # lui $at, 0x3fff
  ori   $at, (0x3FFFFFC0 & 0xFFFF) # ori $at, $at, 0xffc0
  and   $v0, $v0, $at
  sll   $v0, $v0, 6
  and   $t5, $a0, $t3
  add   $v0, $v0, $t5
  b     .L700190CC
   nop   
.L700190C8:
  li    $v0, -1
.L700190CC:
  mtc0  $t0, $10
  jr    $ra
   nop   

  nop   
  nop   
glabel alSynDelete
  jr    $ra
   sw    $zero, ($a0)

  nop   
  nop   
glabel __osAiDeviceBusy
  lui   $t6, %hi(AI_STATUS_REG) # $t6, 0xa450
  lw    $a0, %lo(AI_STATUS_REG)($t6)
  lui   $at, 0x8000
  addiu $sp, $sp, -8
  and   $t7, $a0, $at
  beqz  $t7, .L70019114
   nop   
  b     .L70019118
   li    $v0, 1
.L70019114:
  move  $v0, $zero
.L70019118:
  jr    $ra
   addiu $sp, $sp, 8

glabel alSaveNew
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lui   $a1, %hi(alSavePull) # $a1, 0x7002
  lui   $a2, %hi(alSaveParam) # $a2, 0x7002
  addiu $a2, %lo(alSaveParam) # addiu $a2, $a2, -0x4a10
  addiu $a1, %lo(alSavePull) # addiu $a1, $a1, -0x49dc
  sw    $a0, 0x18($sp)
  jal   alFilterNew
   li    $a3, 3
  lw    $a0, 0x18($sp)
  li    $t6, 1
  sw    $zero, 0x14($a0)
  sw    $t6, 0x18($a0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   

glabel alMainBusNew
  addiu $sp, $sp, -0x18
  sw    $a1, 0x1c($sp)
  sw    $a2, 0x20($sp)
  sw    $ra, 0x14($sp)
  lui   $a2, %hi(alMainBusParam) # $a2, 0x7002
  lui   $a1, %hi(alMainBusPull) # $a1, 0x7002
  addiu $a1, %lo(alMainBusPull) # addiu $a1, $a1, -0x6670
  addiu $a2, %lo(alMainBusParam) # addiu $a2, $a2, -0x66a0
  sw    $a0, 0x18($sp)
  jal   alFilterNew
   li    $a3, 7
  lw    $a0, 0x18($sp)
  sw    $zero, 0x14($a0)
  lw    $t6, 0x20($sp)
  sw    $t6, 0x18($a0)
  lw    $t7, 0x1c($sp)
  sw    $t7, 0x1c($a0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   

glabel alAuxBusNew
  addiu $sp, $sp, -0x18
  sw    $a1, 0x1c($sp)
  sw    $a2, 0x20($sp)
  sw    $ra, 0x14($sp)
  lui   $a2, %hi(ultra_7001B4E0) # $a2, 0x7002
  lui   $a1, %hi(ultra_7001B510) # $a1, 0x7002
  addiu $a1, %lo(ultra_7001B510) # addiu $a1, $a1, -0x4af0
  addiu $a2, %lo(ultra_7001B4E0) # addiu $a2, $a2, -0x4b20
  sw    $a0, 0x18($sp)
  jal   alFilterNew
   li    $a3, 6
  lw    $a0, 0x18($sp)
  sw    $zero, 0x14($a0)
  lw    $t6, 0x20($sp)
  sw    $t6, 0x18($a0)
  lw    $t7, 0x1c($sp)
  sw    $t7, 0x1c($a0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   

glabel alResampleNew
  addiu $sp, $sp, -0x20
  sw    $a1, 0x24($sp)
  sw    $ra, 0x1c($sp)
  lui   $a1, %hi(alResamplePull) # $a1, 0x7002
  lui   $a2, %hi(alResampleParam) # $a2, 0x7002
  addiu $a2, %lo(alResampleParam) # addiu $a2, $a2, -0x5a00
  addiu $a1, %lo(alResamplePull) # addiu $a1, $a1, -0x5914
  sw    $a0, 0x20($sp)
  jal   alFilterNew
   li    $a3, 1
  li    $t6, 32
  sw    $t6, 0x10($sp)
  move  $a0, $zero
  move  $a1, $zero
  lw    $a2, 0x24($sp)
  jal   alHeapDBAlloc
   li    $a3, 1
  lw    $t0, 0x20($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $zero, $f4
  mtc1  $at, $f6
  li    $t7, 1
  sw    $v0, 0x14($t0)
  sw    $t7, 0x24($t0)
  sw    $zero, 0x30($t0)
  sw    $zero, 0x1c($t0)
  sw    $zero, 0x28($t0)
  sw    $zero, 0x2c($t0)
  swc1  $f4, 0x20($t0)
  swc1  $f6, 0x18($t0)
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   

glabel alLoadNew
  addiu $sp, $sp, -0x28
  sw    $a1, 0x2c($sp)
  sw    $a2, 0x30($sp)
  sw    $ra, 0x24($sp)
  sw    $s0, 0x20($sp)
  lui   $a2, %hi(alLoadParam) # $a2, 0x7002
  lui   $a1, %hi(alAdpcmPull) # $a1, 0x7002
  move  $s0, $a0
  addiu $a1, %lo(alAdpcmPull) # addiu $a1, $a1, -0x5ea4
  addiu $a2, %lo(alLoadParam) # addiu $a2, $a2, -0x6550
  jal   alFilterNew
   move  $a3, $zero
  li    $t6, 32
  sw    $t6, 0x10($sp)
  move  $a0, $zero
  move  $a1, $zero
  lw    $a2, 0x30($sp)
  jal   alHeapDBAlloc
   li    $a3, 1
  sw    $v0, 0x14($s0)
  li    $t7, 32
  sw    $t7, 0x10($sp)
  lw    $a2, 0x30($sp)
  move  $a0, $zero
  move  $a1, $zero
  jal   alHeapDBAlloc
   li    $a3, 1
  sw    $v0, 0x18($s0)
  lw    $t9, 0x2c($sp)
  addiu $a0, $s0, 0x34
  jalr  $t9
  nop   
  li    $t8, 1
  sw    $v0, 0x30($s0)
  sw    $zero, 0x3c($s0)
  sw    $t8, 0x40($s0)
  sw    $zero, 0x44($s0)
  lw    $ra, 0x24($sp)
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   

glabel alEnvmixerNew
  addiu $sp, $sp, -0x20
  sw    $a1, 0x24($sp)
  sw    $ra, 0x1c($sp)
  lui   $a1, %hi(alEnvmixerPull) # $a1, 0x7002
  lui   $a2, %hi(alEnvmixerParam) # $a2, 0x7002
  addiu $a2, %lo(alEnvmixerParam) # addiu $a2, $a2, -0x55ec
  addiu $a1, %lo(alEnvmixerPull) # addiu $a1, $a1, -0x51a4
  sw    $a0, 0x20($sp)
  jal   alFilterNew
   li    $a3, 4
  li    $t6, 80
  sw    $t6, 0x10($sp)
  move  $a0, $zero
  move  $a1, $zero
  lw    $a2, 0x24($sp)
  jal   alHeapDBAlloc
   li    $a3, 1
  lw    $t0, 0x20($sp)
  li    $v1, 1
  sw    $v0, 0x14($t0)
  sw    $v1, 0x38($t0)
  sw    $zero, 0x48($t0)
  sh    $v1, 0x1a($t0)
  sh    $v1, 0x28($t0)
  sh    $v1, 0x2e($t0)
  sh    $v1, 0x1c($t0)
  sh    $v1, 0x1e($t0)
  sh    $zero, 0x20($t0)
  sh    $zero, 0x22($t0)
  sh    $v1, 0x26($t0)
  sh    $zero, 0x24($t0)
  sw    $zero, 0x30($t0)
  sw    $zero, 0x34($t0)
  sh    $zero, 0x18($t0)
  sw    $zero, 0x3c($t0)
  sw    $zero, 0x40($t0)
  sw    $zero, 0x44($t0)
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   

glabel init_lpfilter
  lh    $v0, ($a0)
  li    $t9, 16384
  li    $t1, 1
  sll   $t6, $v0, 0xe
  sra   $v1, $t6, 0xf
  sll   $t7, $v1, 0x10
  sra   $v1, $t7, 0x10
  subu  $t0, $t9, $v1
  sh    $t0, 2($a0)
  sw    $t1, 0x2c($a0)
  move  $a1, $zero
  move  $a2, $a0
.L70019410:
  addiu $a1, $a1, 1
  slti  $at, $a1, 8
  addiu $a2, $a2, 2
  bnez  $at, .L70019410
   sh    $zero, 6($a2)
  mtc1  $v1, $f4
  li    $at, 0x40D00000 # 6.500000
  mtc1  $at, $f13
  cvt.d.w $f6, $f4
  mtc1  $zero, $f12
  addiu $a1, $a1, 1
  slti  $at, $a1, 0x10
  sh    $v1, 8($a2)
  div.d $f2, $f6, $f12
  addiu $a2, $a2, 2
  beqz  $at, .L70019478
   mov.d $f0, $f2
.L70019454:
  mul.d $f0, $f0, $f2
  addiu $a1, $a1, 1
  slti  $at, $a1, 0x10
  addiu $a2, $a2, 2
  mul.d $f8, $f0, $f12
  trunc.w.d $f10, $f8
  mfc1  $t3, $f10
  bnez  $at, .L70019454
   sh    $t3, 6($a2)
.L70019478:
  jr    $ra
   nop   

glabel alFxNew
  addiu $sp, $sp, -0x68
  sw    $s6, 0x58($sp)
  move  $s6, $a2
  sw    $ra, 0x64($sp)
  sw    $s5, 0x54($sp)
  sw    $a1, 0x6c($sp)
  lui   $a2, %hi(alFxParam) # $a2, 0x7002
  move  $s5, $a0
  sw    $fp, 0x60($sp)
  sw    $s7, 0x5c($sp)
  sw    $s4, 0x50($sp)
  sw    $s3, 0x4c($sp)
  sw    $s2, 0x48($sp)
  sw    $s1, 0x44($sp)
  sw    $s0, 0x40($sp)
  sdc1  $f26, 0x38($sp)
  sdc1  $f24, 0x30($sp)
  sdc1  $f22, 0x28($sp)
  sdc1  $f20, 0x20($sp)
  addiu $a2, %lo(alFxParam) # addiu $a2, $a2, 0x1c0
  move  $a1, $zero
  jal   alFilterNew
   li    $a3, 5
  lw    $v0, 0x6c($sp)
  lui   $t6, %hi(alFxPull) # $t6, 0x7002
  lui   $t7, %hi(alFxParamHdl) # $t7, 0x7002
  addiu $t6, %lo(alFxPull) # addiu $t6, $t6, 0x1d8
  addiu $t7, %lo(alFxParamHdl) # addiu $t7, $t7, -0x58
  sw    $t6, 4($s5)
  sw    $t7, 0x28($s5)
  lbu   $t8, 0x1c($v0)
  lui   $s3, %hi(NULL_PARAMS)
  addiu $s3, %lo(NULL_PARAMS) # addiu $s3, $s3, -0x7e48
  addiu $t9, $t8, -1
  sltiu $at, $t9, 6
  beqz  $at, .L7001956C
   sll   $t9, $t9, 2
  lui   $at, %hi(jpt_80029830)
  addu  $at, $at, $t9
  lw    $t9, %lo(jpt_80029830)($at)
  jr    $t9
   nop   
.L70019528:
  lui   $s3, %hi(SMALLROOM_PARAMS)
  b     .L7001956C
   addiu $s3, %lo(SMALLROOM_PARAMS) # addiu $s3, $s3, -0x7fb0
.L70019534:
  lui   $s3, %hi(BIGROOM_PARAMS)
  b     .L7001956C
   addiu $s3, %lo(BIGROOM_PARAMS) # addiu $s3, $s3, -0x7f48
.L70019540:
  lui   $s3, %hi(ECHO_PARAMS)
  b     .L7001956C
   addiu $s3, %lo(ECHO_PARAMS) # addiu $s3, $s3, -0x7ec0
.L7001954C:
  lui   $s3, %hi(CHORUS_PARAMS)
  b     .L7001956C
   addiu $s3, %lo(CHORUS_PARAMS) # addiu $s3, $s3, -0x7e98
.L70019558:
  lui   $s3, %hi(FLANGE_PARAMS)
  b     .L7001956C
   addiu $s3, %lo(FLANGE_PARAMS) # addiu $s3, $s3, -0x7e70
.L70019564:
  b     .L7001956C
   lw    $s3, 0x20($v0)
.L7001956C:
  lw    $t0, ($s3)
  li    $t2, 40
  li    $s1, 2
  sb    $t0, 0x24($s5)
  lw    $t1, 4($s3)
  move  $a0, $zero
  move  $a1, $zero
  sw    $t1, 0x1c($s5)
  sw    $t2, 0x10($sp)
  move  $a2, $s6
  jal   alHeapDBAlloc
   andi  $a3, $t0, 0xff
  sw    $v0, 0x20($s5)
  lw    $a3, 0x1c($s5)
  li    $t3, 2
  sw    $t3, 0x10($sp)
  move  $a0, $zero
  move  $a1, $zero
  jal   alHeapDBAlloc
   move  $a2, $s6
  lw    $t4, 0x1c($s5)
  sw    $v0, 0x14($s5)
  sw    $v0, 0x18($s5)
  beqz  $t4, .L700195FC
   move  $v1, $zero
  lw    $t5, 0x14($s5)
.L700195D4:
  sll   $t6, $v1, 1
  addiu $v1, $v1, 1
  addu  $t7, $t5, $t6
  sh    $zero, ($t7)
  lw    $t9, 0x1c($s5)
  andi  $t8, $v1, 0xffff
  move  $v1, $t8
  sltu  $at, $t8, $t9
  bnezl $at, .L700195D4
   lw    $t5, 0x14($s5)
.L700195FC:
  lbu   $t0, 0x24($s5)
  move  $s4, $zero
  li    $at, 0x3F800000 # 1.000000
  blez  $t0, .L7001987C
   li    $fp, 1
  mtc1  $at, $f24
  li    $at, 0x447A0000 # 1000.000000
  mtc1  $at, $f22
  lui   $at, %hi(F64_80029848)
  mtc1  $zero, $f26
  ldc1  $f20, %lo(F64_80029848)($at)
  li    $s7, 40
.L7001962C:
  multu $s4, $s7
  sll   $t3, $s1, 2
  lw    $t1, 0x20($s5)
  addu  $t4, $s3, $t3
  lw    $t5, ($t4)
  addiu $s1, $s1, 1
  andi  $t6, $s1, 0xffff
  sll   $t7, $t6, 2
  addu  $t8, $s3, $t7
  addiu $s1, $t6, 1
  mflo  $t2
  addu  $s0, $t1, $t2
  sw    $t5, ($s0)
  lw    $t9, ($t8)
  andi  $t0, $s1, 0xffff
  sll   $t1, $t0, 2
  addu  $t2, $s3, $t1
  sw    $t9, 4($s0)
  lw    $t3, ($t2)
  addiu $s1, $t0, 1
  andi  $t4, $s1, 0xffff
  sll   $t5, $t4, 2
  addu  $t6, $s3, $t5
  sh    $t3, 0xa($s0)
  lw    $t7, ($t6)
  addiu $s1, $t4, 1
  andi  $t8, $s1, 0xffff
  sll   $t9, $t8, 2
  addu  $t0, $s3, $t9
  sh    $t7, 8($s0)
  lw    $t1, ($t0)
  addiu $s1, $t8, 1
  andi  $t2, $s1, 0xffff
  sll   $t3, $t2, 2
  addu  $t4, $s3, $t3
  sh    $t1, 0xc($s0)
  lw    $v0, ($t4)
  move  $s1, $t2
  move  $t0, $s1
  beqz  $v0, .L700197CC
   addiu $s1, $t0, 2
  mtc1  $v0, $f4
  lw    $t5, 0x6c($sp)
  lw    $t8, 4($s0)
  cvt.s.w $f6, $f4
  lw    $t6, 0x18($t5)
  lw    $t9, ($s0)
  addiu $s1, $t2, 1
  mtc1  $t6, $f16
  andi  $t7, $s1, 0xffff
  div.s $f8, $f6, $f22
  subu  $t0, $t8, $t9
  move  $s1, $t7
  sll   $t1, $s1, 2
  cvt.d.w $f18, $f16
  addu  $t2, $s3, $t1
  li    $at, 0x41F00000 # 30.000000
  cvt.d.s $f0, $f8
  mtc1  $t0, $f8
  add.d $f10, $f0, $f0
  cvt.d.w $f16, $f8
  div.d $f4, $f10, $f18
  cvt.s.d $f6, $f4
  bgez  $t0, .L70019740
   swc1  $f6, 0x10($s0)
  mtc1  $at, $f11
  mtc1  $zero, $f10
  nop   
  add.d $f16, $f16, $f10
.L70019740:
  lw    $t3, ($t2)
  addiu $s1, $s1, 1
  andi  $t4, $s1, 0xffff
  mtc1  $t3, $f18
  swc1  $f24, 0x14($s0)
  sw    $zero, 0x18($s0)
  cvt.s.w $f4, $f18
  li    $t5, 52
  move  $s1, $t4
  move  $a0, $zero
  move  $a1, $zero
  move  $a2, $s6
  cvt.d.s $f6, $f4
  move  $a3, $fp
  div.d $f8, $f6, $f20
  mul.d $f10, $f8, $f16
  cvt.s.d $f18, $f10
  swc1  $f18, 0x1c($s0)
  jal   alHeapDBAlloc
   sw    $t5, 0x10($sp)
  sw    $v0, 0x24($s0)
  li    $t6, 32
  sw    $t6, 0x10($sp)
  move  $a0, $zero
  move  $a1, $zero
  move  $a2, $s6
  jal   alHeapDBAlloc
   move  $a3, $fp
  lw    $t7, 0x24($s0)
  sw    $v0, 0x14($t7)
  lw    $t8, 0x24($s0)
  swc1  $f26, 0x20($t8)
  lw    $t9, 0x24($s0)
  b     .L700197D8
   sw    $fp, 0x24($t9)
.L700197CC:
  andi  $t1, $s1, 0xffff
  sw    $zero, 0x24($s0)
  move  $s1, $t1
.L700197D8:
  sll   $t2, $s1, 2
  addu  $s2, $s3, $t2
  lw    $t3, ($s2)
  move  $a0, $zero
  move  $a1, $zero
  beqz  $t3, .L70019854
   move  $a2, $s6
  li    $t4, 48
  sw    $t4, 0x10($sp)
  jal   alHeapDBAlloc
   move  $a3, $fp
  sw    $v0, 0x20($s0)
  li    $t5, 8
  sw    $t5, 0x10($sp)
  move  $a0, $zero
  move  $a1, $zero
  move  $a2, $s6
  jal   alHeapDBAlloc
   move  $a3, $fp
  lw    $t6, 0x20($s0)
  addiu $s1, $s1, 1
  andi  $t9, $s1, 0xffff
  sw    $v0, 0x28($t6)
  lw    $t8, 0x20($s0)
  lw    $t7, ($s2)
  move  $s1, $t9
  sh    $t7, ($t8)
  jal   init_lpfilter
   lw    $a0, 0x20($s0)
  b     .L70019868
   lbu   $t2, 0x24($s5)
.L70019854:
  addiu $s1, $s1, 1
  andi  $t0, $s1, 0xffff
  sw    $zero, 0x20($s0)
  move  $s1, $t0
  lbu   $t2, 0x24($s5)
.L70019868:
  addiu $s4, $s4, 1
  andi  $t1, $s4, 0xffff
  slt   $at, $t1, $t2
  bnez  $at, .L7001962C
   move  $s4, $t1
.L7001987C:
  lw    $ra, 0x64($sp)
  ldc1  $f20, 0x20($sp)
  ldc1  $f22, 0x28($sp)
  ldc1  $f24, 0x30($sp)
  ldc1  $f26, 0x38($sp)
  lw    $s0, 0x40($sp)
  lw    $s1, 0x44($sp)
  lw    $s2, 0x48($sp)
  lw    $s3, 0x4c($sp)
  lw    $s4, 0x50($sp)
  lw    $s5, 0x54($sp)
  lw    $s6, 0x58($sp)
  lw    $s7, 0x5c($sp)
  lw    $fp, 0x60($sp)
  jr    $ra
   addiu $sp, $sp, 0x68

  nop

.section .data
glabel SMALLROOM_PARAMS
.word          3,     0xFA0,         0,     0x870,    0x2666,0xFFFFD99A,         0,         0
.word          0,         0,     0x2F8,     0x5F0,     0xCCC,0xFFFFF334,    0x3FFF,         0
.word          0,         0,         0,     0x960,    0x1388,         0,         0,         0
.word          0,    0x5000
glabel BIGROOM_PARAMS
.word          4,     0xFA0,         0,     0xA50,    0x2666,0xFFFFD99A,         0,         0
.word          0,         0,     0x370,     0x870,     0xCCC,0xFFFFF334,    0x3FFF,         0
.word          0,         0,     0xA50,     0xE38,     0xCCC,0xFFFFF334,    0x3FFF,         0
.word          0,         0,         0,     0xEB0,    0x1F40,         0,         0,         0
.word          0,    0x5000
glabel ECHO_PARAMS
.word          1,    0x1F40,         0,    0x1BF8,    0x2EE0,         0,    0x7FFF,         0
.word          0,         0
glabel CHORUS_PARAMS
.word          1,     0x320,         0,      0xC8,    0x4000,         0,    0x7FFF,    0x1DB0
.word      0x2BC,         0
glabel FLANGE_PARAMS
.word          1,     0x320,         0,      0xC8,         0,    0x5FFF,    0x7FFF,     0x17C
.word      0x1F4,         0
glabel NULL_PARAMS
.word          0,         0,         0,         0,         0,         0,         0,         0
.word          0,         0
.section .rodata
glabel jpt_80029830
.word .L70019528
.word .L70019534
.word .L7001954C
.word .L70019558
.word .L70019540
.word .L70019564
glabel F64_80029848
.double 173123.404906676

.section .text
glabel alSynAllocFX
  addiu $sp, $sp, -0x20
  sll   $t0, $a1, 0x10
  sra   $t6, $t0, 0x10
  sw    $s1, 0x18($sp)
  sll   $s1, $t6, 2
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x14($sp)
  sw    $a1, 0x24($sp)
  addu  $s1, $s1, $t6
  lw    $t7, 0x34($a0)
  sll   $s1, $s1, 2
  subu  $s1, $s1, $t6
  move  $s0, $a0
  sll   $s1, $s1, 2
  move  $a1, $a2
  addu  $a0, $t7, $s1
  addiu $a0, $a0, 0x20
  jal   alFxNew
   move  $a2, $a3
  lw    $t8, 0x34($s0)
  li    $a1, 1
  addu  $a2, $t8, $s1
  jal   alFxParam
   addiu $a0, $a2, 0x20
  lw    $t9, 0x34($s0)
  lw    $a0, 0x30($s0)
  li    $a1, 2
  addu  $a2, $t9, $s1
  jal   alMainBusParam
   addiu $a2, $a2, 0x20
  lw    $t2, 0x34($s0)
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x14($sp)
  addu  $v0, $t2, $s1
  lw    $s1, 0x18($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   addiu $v0, $v0, 0x20

  nop   
  nop   
glabel alMainBusParam
  li    $at, 2
  bne   $a1, $at, .L70019988
   lw    $v0, 0x1c($a0)
  lw    $t6, 0x14($a0)
  sll   $t7, $t6, 2
  addu  $t8, $v0, $t7
  sw    $a2, ($t8)
  lw    $t9, 0x14($a0)
  addiu $t0, $t9, 1
  sw    $t0, 0x14($a0)
.L70019988:
  jr    $ra
   move  $v0, $zero

glabel alMainBusPull
  addiu $sp, $sp, -0x48
  lw    $t0, 0x58($sp)
  sw    $ra, 0x44($sp)
  sw    $fp, 0x40($sp)
  sw    $s7, 0x3c($sp)
  sw    $s6, 0x38($sp)
  sw    $s5, 0x34($sp)
  sw    $s4, 0x30($sp)
  sw    $s3, 0x2c($sp)
  sw    $s2, 0x28($sp)
  sw    $s1, 0x24($sp)
  sw    $s0, 0x20($sp)
  lw    $v1, 0x1c($a0)
  lui   $t6, (0x02000440 >> 16) # lui $t6, 0x200
  sll   $v0, $a2, 1
  lui   $t7, (0x02000580 >> 16) # lui $t7, 0x200
  ori   $t6, (0x02000440 & 0xFFFF) # ori $t6, $t6, 0x440
  ori   $t7, (0x02000580 & 0xFFFF) # ori $t7, $t7, 0x580
  sw    $t6, ($t0)
  sw    $v0, 4($t0)
  sw    $t7, 8($t0)
  sw    $v0, 0xc($t0)
  lw    $t8, 0x14($a0)
  move  $s5, $a2
  move  $s7, $a1
  move  $fp, $a3
  move  $s4, $a0
  move  $s0, $zero
  blez  $t8, .L70019A7C
   addiu $s3, $t0, 0x10
  lui   $s2, (0x0C007FFF >> 16) # lui $s2, 0xc00
  ori   $s2, (0x0C007FFF & 0xFFFF) # ori $s2, $s2, 0x7fff
  move  $s1, $v1
  andi  $s6, $v0, 0xffff
.L70019A18:
  lw    $a0, ($s1)
  sw    $s3, 0x10($sp)
  move  $a1, $s7
  lw    $t9, 4($a0)
  move  $a2, $s5
  move  $a3, $fp
  jalr  $t9
  nop   
  lui   $t2, (0x06C00440 >> 16) # lui $t2, 0x6c0
  lui   $t3, (0x08000580 >> 16) # lui $t3, 0x800
  lui   $t1, 0x800
  ori   $t2, (0x06C00440 & 0xFFFF) # ori $t2, $t2, 0x440
  ori   $t3, (0x08000580 & 0xFFFF) # ori $t3, $t3, 0x580
  sw    $t1, ($v0)
  sw    $s6, 4($v0)
  sw    $t2, 0xc($v0)
  sw    $s2, 8($v0)
  sw    $t3, 0x14($v0)
  sw    $s2, 0x10($v0)
  lw    $t4, 0x14($s4)
  addiu $s0, $s0, 1
  addiu $s1, $s1, 4
  slt   $at, $s0, $t4
  bnez  $at, .L70019A18
   addiu $s3, $v0, 0x18
.L70019A7C:
  lw    $ra, 0x44($sp)
  move  $v0, $s3
  lw    $s3, 0x2c($sp)
  lw    $s0, 0x20($sp)
  lw    $s1, 0x24($sp)
  lw    $s2, 0x28($sp)
  lw    $s4, 0x30($sp)
  lw    $s5, 0x34($sp)
  lw    $s6, 0x38($sp)
  lw    $s7, 0x3c($sp)
  lw    $fp, 0x40($sp)
  jr    $ra
   addiu $sp, $sp, 0x48

glabel alLoadParam
  addiu $sp, $sp, -0x18
  li    $at, 4
  sw    $ra, 0x14($sp)
  beq   $a1, $at, .L70019C14
   move  $a3, $a0
  li    $at, 5
  bnel  $a1, $at, .L70019C78
   lw    $ra, 0x14($sp)
  sw    $a2, 0x28($a0)
  lw    $t6, ($a2)
  sw    $zero, 0x38($a0)
  lui   $t7, %hi(alAdpcmPull) # $t7, 0x7002
  sw    $t6, 0x44($a0)
  lbu   $v0, 8($a2)
  beql  $v0, $zero, .L70019B08
   lw    $v0, 0x28($a3)
  li    $a0, 1
  beq   $v0, $a0, .L70019BC8
   lui   $t0, %hi(alRaw16Pull) # $t0, 0x7002
  b     .L70019C78
   lw    $ra, 0x14($sp)
  lw    $v0, 0x28($a3)
.L70019B08:
  addiu $t7, %lo(alAdpcmPull) # addiu $t7, $t7, -0x5ea4
  sw    $t7, 4($a3)
  lw    $t8, 4($v0)
  li    $a1, 9
  div   $zero, $t8, $a1
  mflo  $t9
  bnez  $a1, .L70019B2C
   nop   
  break 7
.L70019B2C:
  li    $at, -1
  bne   $a1, $at, .L70019B44
   lui   $at, 0x8000
  bne   $t8, $at, .L70019B44
   nop   
  break 6
.L70019B44:
  multu $t9, $a1
  mflo  $t0
  sw    $t0, 4($v0)
  lw    $v0, 0x28($a3)
  lw    $a0, 0x10($v0)
  lw    $t1, ($a0)
  lw    $t3, 4($a0)
  sll   $t2, $t1, 4
  multu $t2, $t3
  mflo  $t4
  sw    $t4, 0x2c($a3)
  lw    $v1, 0xc($v0)
  beql  $v1, $zero, .L70019BBC
   sw    $zero, 0x24($a3)
  lw    $t5, ($v1)
  lw    $a1, 0x18($a3)
  li    $a2, 32
  sw    $t5, 0x1c($a3)
  lw    $t6, 0xc($v0)
  lw    $t7, 4($t6)
  sw    $t7, 0x20($a3)
  lw    $t8, 0xc($v0)
  lw    $t9, 8($t8)
  sw    $t9, 0x24($a3)
  lw    $a0, 0xc($v0)
  jal   alCopy
   addiu $a0, $a0, 0xc
  b     .L70019C78
   lw    $ra, 0x14($sp)
  sw    $zero, 0x24($a3)
.L70019BBC:
  sw    $zero, 0x20($a3)
  b     .L70019C74
   sw    $zero, 0x1c($a3)
.L70019BC8:
  lw    $v0, 0x28($a3)
  addiu $t0, %lo(alRaw16Pull) # addiu $t0, $t0, -0x637c
  sw    $t0, 4($a3)
  lw    $v1, 0xc($v0)
  beql  $v1, $zero, .L70019C08
   sw    $zero, 0x24($a3)
  lw    $t1, ($v1)
  sw    $t1, 0x1c($a3)
  lw    $t2, 0xc($v0)
  lw    $t3, 4($t2)
  sw    $t3, 0x20($a3)
  lw    $t4, 0xc($v0)
  lw    $t5, 8($t4)
  b     .L70019C74
   sw    $t5, 0x24($a3)
  sw    $zero, 0x24($a3)
.L70019C08:
  sw    $zero, 0x20($a3)
  b     .L70019C74
   sw    $zero, 0x1c($a3)
.L70019C14:
  lw    $v0, 0x28($a3)
  li    $a0, 1
  sw    $zero, 0x3c($a3)
  sw    $a0, 0x40($a3)
  beqz  $v0, .L70019C74
   sw    $zero, 0x38($a3)
  lw    $t6, ($v0)
  sw    $t6, 0x44($a3)
  lbu   $v1, 8($v0)
  bnez  $v1, .L70019C58
   nop   
  lw    $v1, 0xc($v0)
  beql  $v1, $zero, .L70019C78
   lw    $ra, 0x14($sp)
  lw    $t7, 8($v1)
  b     .L70019C74
   sw    $t7, 0x24($a3)
.L70019C58:
  bnel  $a0, $v1, .L70019C78
   lw    $ra, 0x14($sp)
  lw    $v1, 0xc($v0)
  beql  $v1, $zero, .L70019C78
   lw    $ra, 0x14($sp)
  lw    $t8, 8($v1)
  sw    $t8, 0x24($a3)
.L70019C74:
  lw    $ra, 0x14($sp)
.L70019C78:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   

glabel alRaw16Pull
  addiu $sp, $sp, -0x50
  lw    $t0, 0x60($sp)
  sw    $s3, 0x20($sp)
  sw    $s0, 0x14($sp)
  move  $s0, $a0
  move  $s3, $a2
  sw    $ra, 0x24($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $a3, 0x5c($sp)
  move  $t2, $a1
  bnez  $a2, .L70019CC0
   move  $t1, $t0
  b     .L7001A014
   move  $v0, $t0
.L70019CC0:
  lw    $v0, 0x38($s0)
  lw    $v1, 0x20($s0)
  addu  $t6, $v0, $s3
  sltu  $at, $v1, $t6
  beql  $at, $zero, .L70019EE4
   lw    $v0, 0x28($s0)
  lw    $t7, 0x24($s0)
  subu  $s2, $v1, $v0
  beql  $t7, $zero, .L70019EE4
   lw    $v0, 0x28($s0)
  blez  $s2, .L70019D64
   sll   $s1, $s2, 1
  lw    $a0, 0x44($s0)
  lw    $a2, 0x34($s0)
  sw    $t2, 0x54($sp)
  lw    $t9, 0x30($s0)
  move  $a1, $s1
  jalr  $t9
  nop   
  lw    $t2, 0x54($sp)
  andi  $a2, $v0, 7
  lw    $t0, 0x60($sp)
  lh    $t8, ($t2)
  addu  $a3, $s1, $a2
  andi  $t5, $a3, 7
  subu  $t6, $a3, $t5
  lui   $at, 0x800
  andi  $t3, $t8, 0xffff
  or    $t4, $t3, $at
  addiu $t7, $t6, 8
  addiu $t1, $t0, 8
  andi  $t9, $t7, 0xffff
  move  $a0, $t1
  subu  $t3, $v0, $a2
  lui   $t8, 0x400
  sw    $t9, 4($t0)
  sw    $t4, ($t0)
  sw    $t3, 4($a0)
  sw    $t8, ($a0)
  b     .L70019D68
   addiu $t1, $t1, 8
.L70019D64:
  move  $a2, $zero
.L70019D68:
  lh    $t4, ($t2)
  slt   $at, $s2, $s3
  addu  $t5, $t4, $a2
  sh    $t5, ($t2)
  lw    $t6, 0x28($s0)
  lw    $v0, 0x1c($s0)
  lw    $t7, ($t6)
  sll   $t9, $v0, 1
  sw    $v0, 0x38($s0)
  addu  $t8, $t7, $t9
  sw    $t8, 0x44($s0)
  beqz  $at, .L70019EBC
   lh    $t0, ($t2)
  lw    $v0, 0x24($s0)
.L70019DA0:
  li    $at, -1
  addu  $t0, $t0, $s1
  beq   $v0, $at, .L70019DBC
   subu  $s3, $s3, $s2
  beqz  $v0, .L70019DBC
   addiu $t3, $v0, -1
  sw    $t3, 0x24($s0)
.L70019DBC:
  lw    $t4, 0x20($s0)
  lw    $t5, 0x1c($s0)
  subu  $v0, $t4, $t5
  sltu  $at, $s3, $v0
  beqz  $at, .L70019DDC
   move  $s2, $v0
  b     .L70019DDC
   move  $s2, $s3
.L70019DDC:
  lw    $a0, 0x44($s0)
  lw    $a2, 0x34($s0)
  sw    $t1, 0x4c($sp)
  sw    $t0, 0x2c($sp)
  lw    $t9, 0x30($s0)
  sll   $s1, $s2, 1
  move  $a1, $s1
  jalr  $t9
  nop   
  lw    $t0, 0x2c($sp)
  andi  $a1, $v0, 7
  lw    $t1, 0x4c($sp)
  andi  $v1, $t0, 7
  beqz  $v1, .L70019E24
   addu  $a3, $s1, $a1
  li    $t6, 8
  b     .L70019E28
   subu  $a2, $t6, $v1
.L70019E24:
  move  $a2, $zero
.L70019E28:
  addu  $t7, $t0, $a2
  andi  $t4, $a3, 7
  subu  $t5, $a3, $t4
  andi  $t8, $t7, 0xffff
  move  $v1, $t1
  lui   $at, 0x800
  or    $t3, $t8, $at
  addiu $t1, $t1, 8
  addiu $t9, $t5, 8
  andi  $t6, $t9, 0xffff
  move  $a0, $t1
  sw    $t6, 4($v1)
  sw    $t3, ($v1)
  subu  $t8, $v0, $a1
  lui   $t7, 0x400
  sw    $t7, ($a0)
  sw    $t8, 4($a0)
  bnez  $a1, .L70019E78
   addiu $t1, $t1, 8
  beqz  $a2, .L70019EB0
.L70019E78:
   addu  $t3, $t0, $a1
  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
  addu  $t4, $t3, $a2
  and   $t5, $t4, $at
  move  $v0, $t1
  lui   $at, 0xa00
  sll   $t7, $t0, 0x10
  andi  $t8, $s1, 0xffff
  or    $t3, $t7, $t8
  or    $t9, $t5, $at
  sw    $t9, ($v0)
  sw    $t3, 4($v0)
  addiu $t1, $t1, 8
.L70019EB0:
  slt   $at, $s2, $s3
  bnezl $at, .L70019DA0
   lw    $v0, 0x24($s0)
.L70019EBC:
  lw    $t4, 0x38($s0)
  lw    $t9, 0x44($s0)
  sll   $t6, $s3, 1
  addu  $t5, $t4, $s3
  addu  $t7, $t9, $t6
  sw    $t5, 0x38($s0)
  sw    $t7, 0x44($s0)
  b     .L7001A014
   move  $v0, $t1
  lw    $v0, 0x28($s0)
.L70019EE4:
  lw    $a0, 0x44($s0)
  sll   $s1, $s3, 1
  lw    $t8, ($v0)
  lw    $t4, 4($v0)
  addu  $v1, $a0, $s1
  subu  $t3, $v1, $t8
  subu  $s2, $t3, $t4
  bgezl $s2, .L70019F10
   slt   $at, $s1, $s2
  move  $s2, $zero
  slt   $at, $s1, $s2
.L70019F10:
  beql  $at, $zero, .L70019F20
   slt   $at, $s2, $s1
  move  $s2, $s1
  slt   $at, $s2, $s1
.L70019F20:
  beql  $at, $zero, .L70019FD4
   sw    $v1, 0x44($s0)
  blez  $s3, .L70019FA8
   move  $a2, $zero
  lw    $a2, 0x34($s0)
  subu  $a1, $s1, $s2
  sw    $a1, 0x48($sp)
  sw    $t2, 0x54($sp)
  lw    $t9, 0x30($s0)
  jalr  $t9
  nop   
  lw    $t2, 0x54($sp)
  lw    $a3, 0x48($sp)
  andi  $a2, $v0, 7
  lh    $t5, ($t2)
  lw    $t0, 0x60($sp)
  addu  $a3, $a3, $a2
  andi  $t8, $a3, 7
  subu  $t3, $a3, $t8
  lui   $at, 0x800
  andi  $t6, $t5, 0xffff
  or    $t7, $t6, $at
  addiu $t4, $t3, 8
  addiu $t1, $t0, 8
  andi  $t9, $t4, 0xffff
  move  $a0, $t1
  subu  $t6, $v0, $a2
  lui   $t5, 0x400
  sw    $t9, 4($t0)
  sw    $t7, ($t0)
  sw    $t6, 4($a0)
  sw    $t5, ($a0)
  b     .L70019FA8
   addiu $t1, $t1, 8
.L70019FA8:
  lh    $t7, ($t2)
  addu  $t8, $t7, $a2
  sh    $t8, ($t2)
  lw    $t3, 0x38($s0)
  lw    $t9, 0x44($s0)
  addu  $t4, $t3, $s3
  addu  $t5, $t9, $s1
  sw    $t4, 0x38($s0)
  b     .L70019FD4
   sw    $t5, 0x44($s0)
  sw    $v1, 0x44($s0)
.L70019FD4:
  beqz  $s2, .L7001A010
   subu  $v1, $s1, $s2
  bgez  $v1, .L70019FE8
   move  $v0, $t1
  move  $v1, $zero
.L70019FE8:
  lh    $t6, ($t2)
  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
  addu  $t7, $t6, $v1
  and   $t8, $t7, $at
  lui   $at, 0x200
  or    $t3, $t8, $at
  sw    $t3, ($v0)
  sw    $s2, 4($v0)
  addiu $t1, $t1, 8
.L7001A010:
  move  $v0, $t1
.L7001A014:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x50

glabel ultra_7001A030
  addiu $sp, $sp, -0x18
  sw    $s3, 0x2c($sp)
  sw    $s5, 0x28($sp)
  sll   $t6, $s3, 0x10
  sll   $t8, $s5, 0x10
  sra   $s5, $t8, 0x10
  sra   $s3, $t6, 0x10
  blez  $s1, .L7001A0B8
   sw    $ra, 0x14($sp)
  lw    $t9, 0x30($s2)
  lw    $a0, 0x44($s2)
  move  $a1, $s1
  jalr  $t9
  lw    $a2, 0x34($s2)
  andi  $a2, $v0, 7
  addu  $s1, $s1, $a2
  andi  $t6, $s3, 0xffff
  lui   $at, 0x800
  or    $t7, $t6, $at
  andi  $t8, $s1, 7
  move  $a0, $s0
  subu  $t9, $s1, $t8
  addiu $t6, $t9, 8
  sw    $t7, ($a0)
  addiu $s0, $s0, 8
  andi  $t7, $t6, 0xffff
  move  $a1, $s0
  sw    $t7, 4($a0)
  subu  $t9, $v0, $a2
  lui   $t8, 0x400
  sw    $t8, ($a1)
  sw    $t9, 4($a1)
  b     .L7001A0BC
   addiu $s0, $s0, 8
.L7001A0B8:
  move  $a2, $zero
.L7001A0BC:
  andi  $t6, $s4, 2
  beqz  $t6, .L7001A0E8
   move  $v0, $s0
  lui   $t7, 0xf00
  sw    $t7, ($v0)
  lw    $t8, 0x18($s2)
  lui   $at, (0x1FFFFFFF >> 16) # lui $at, 0x1fff
  ori   $at, (0x1FFFFFFF & 0xFFFF) # ori $at, $at, 0xffff
  and   $t9, $t8, $at
  sw    $t9, 4($v0)
  addiu $s0, $s0, 8
.L7001A0E8:
  addu  $t6, $s3, $a2
  andi  $t7, $t6, 0xffff
  lui   $at, 0x800
  or    $t8, $t7, $at
  move  $v1, $s0
  sw    $t8, ($v1)
  sll   $t7, $s6, 1
  andi  $t8, $t7, 0xffff
  sll   $t6, $s5, 0x10
  or    $t9, $t6, $t8
  andi  $t7, $s4, 0xff
  addiu $s0, $s0, 8
  sll   $t6, $t7, 0x10
  lui   $at, 0x100
  sw    $t9, 4($v1)
  or    $t8, $t6, $at
  move  $a0, $s0
  sw    $t8, ($a0)
  lw    $t9, 0x14($s2)
  lui   $at, (0x1FFFFFFF >> 16) # lui $at, 0x1fff
  ori   $at, (0x1FFFFFFF & 0xFFFF) # ori $at, $at, 0xffff
  and   $t7, $t9, $at
  sw    $t7, 4($a0)
  sw    $zero, 0x40($s2)
  lw    $ra, 0x14($sp)
  addiu $s0, $s0, 8
  move  $v0, $s0
  jr    $ra
   addiu $sp, $sp, 0x18

glabel alAdpcmPull
  addiu $sp, $sp, -0xb0
  sw    $s7, 0x44($sp)
  sw    $a3, 0xbc($sp)
  move  $a3, $a1
  move  $s7, $a0
  sw    $ra, 0x4c($sp)
  sw    $fp, 0x48($sp)
  sw    $s6, 0x40($sp)
  sw    $s5, 0x3c($sp)
  sw    $s4, 0x38($sp)
  sw    $s3, 0x34($sp)
  sw    $s2, 0x30($sp)
  sw    $s1, 0x2c($sp)
  sw    $s0, 0x28($sp)
  sw    $a1, 0xb4($sp)
  move  $t0, $a2
  bnez  $a2, .L7001A1AC
   move  $t5, $zero
  b     .L7001A5CC
   lw    $v0, 0xc0($sp)
.L7001A1AC:
  lw    $t6, 0x2c($s7)
  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
  lw    $a1, 0xc0($sp)
  and   $t7, $t6, $at
  lui   $at, 0xb00
  or    $t8, $t7, $at
  sw    $t8, ($a1)
  lw    $t9, 0x28($s7)
  lui   $at, (0x1FFFFFFF >> 16) # lui $at, 0x1fff
  ori   $at, (0x1FFFFFFF & 0xFFFF) # ori $at, $at, 0xffff
  lw    $t6, 0x10($t9)
  addiu $t2, $a1, 8
  move  $a2, $zero
  addiu $t7, $t6, 8
  and   $t8, $t7, $at
  sw    $t8, 4($a1)
  lw    $v1, 0x38($s7)
  lw    $a0, 0x20($s7)
  move  $a1, $t0
  addu  $t9, $v1, $t0
  sltu  $t1, $a0, $t9
  beqz  $t1, .L7001A218
   li    $t7, 16
  lw    $t1, 0x24($s7)
  sltu  $t6, $zero, $t1
  move  $t1, $t6
.L7001A218:
  beqz  $t1, .L7001A228
   li    $at, 9
  b     .L7001A228
   subu  $a1, $a0, $v1
.L7001A228:
  lw    $v1, 0x3c($s7)
  move  $s0, $t2
  move  $s2, $s7
  beqz  $v1, .L7001A244
   move  $s3, $zero
  b     .L7001A244
   subu  $a2, $t7, $v1
.L7001A244:
  subu  $a0, $a1, $a2
  bgez  $a0, .L7001A254
   nop   
  move  $a0, $zero
.L7001A254:
  beqz  $t1, .L7001A45C
   addiu $fp, $a0, 0xf
  addiu $fp, $a0, 0xf
  sra   $t8, $fp, 4
  lh    $s5, ($a3)
  lw    $s4, 0x40($s7)
  sll   $t1, $t8, 3
  addu  $t1, $t1, $t8
  move  $s1, $t1
  sw    $t1, 0x5c($sp)
  sw    $t0, 0xb8($sp)
  sw    $a3, 0xb4($sp)
  sw    $a1, 0x8c($sp)
  move  $fp, $t8
  jal   ultra_7001A030
   move  $s6, $a0
  lw    $v1, 0x3c($s7)
  lw    $a1, 0x8c($sp)
  lw    $a3, 0xb4($sp)
  lw    $t0, 0xb8($sp)
  lw    $t1, 0x5c($sp)
  beqz  $v1, .L7001A2C4
   move  $t2, $v0
  lh    $t9, ($a3)
  sll   $t6, $v1, 1
  addu  $t7, $t9, $t6
  b     .L7001A2D0
   sh    $t7, ($a3)
.L7001A2C4:
  lh    $t8, ($a3)
  addiu $t9, $t8, 0x20
  sh    $t9, ($a3)
.L7001A2D0:
  lw    $v0, 0x1c($s7)
  lw    $t7, 0x28($s7)
  slt   $at, $a1, $t0
  andi  $t6, $v0, 0xf
  sw    $t6, 0x3c($s7)
  lw    $t8, ($t7)
  srl   $t9, $v0, 4
  sll   $t6, $t9, 3
  addu  $t6, $t6, $t9
  addu  $t7, $t8, $t6
  addiu $t9, $t7, 9
  sw    $t9, 0x44($s7)
  sw    $v0, 0x38($s7)
  beqz  $at, .L7001A42C
   lh    $a2, ($a3)
  sll   $v1, $a1, 1
.L7001A310:
  addiu $t8, $fp, 1
  sll   $t6, $t8, 5
  lw    $v0, 0x24($s7)
  addu  $a3, $t6, $a2
  li    $at, -32
  and   $t7, $a3, $at
  li    $at, -1
  subu  $t0, $t0, $a1
  move  $a3, $t7
  beq   $v0, $at, .L7001A348
   addu  $a2, $a2, $v1
  beqz  $v0, .L7001A348
   addiu $t9, $v0, -1
  sw    $t9, 0x24($s7)
.L7001A348:
  lw    $t8, 0x20($s7)
  lw    $t6, 0x1c($s7)
  move  $s0, $t2
  move  $s2, $s7
  subu  $v0, $t8, $t6
  sltu  $at, $t0, $v0
  beqz  $at, .L7001A370
   sll   $s5, $a3, 0x10
  b     .L7001A374
   move  $a1, $t0
.L7001A370:
  move  $a1, $v0
.L7001A374:
  lw    $t7, 0x3c($s7)
  sra   $t8, $s5, 0x10
  move  $s5, $t8
  addu  $a0, $a1, $t7
  addiu $a0, $a0, -0x10
  bgez  $a0, .L7001A394
   move  $s3, $zero
  move  $a0, $zero
.L7001A394:
  lw    $s4, 0x40($s7)
  addiu $fp, $a0, 0xf
  sra   $t9, $fp, 4
  sll   $t1, $t9, 3
  addu  $t1, $t1, $t9
  ori   $t6, $s4, 2
  move  $s4, $t6
  move  $s1, $t1
  sw    $t1, 0x5c($sp)
  move  $fp, $t9
  sw    $t0, 0xb8($sp)
  sw    $a3, 0x88($sp)
  sw    $a2, 0x80($sp)
  sw    $a1, 0x8c($sp)
  jal   ultra_7001A030
   move  $s6, $a0
  lw    $t7, 0x3c($s7)
  lw    $a3, 0x88($sp)
  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
  sll   $t9, $t7, 1
  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
  addu  $t8, $t9, $a3
  and   $t6, $t8, $at
  lw    $a1, 0x8c($sp)
  lui   $at, 0xa00
  lw    $a2, 0x80($sp)
  or    $t7, $t6, $at
  lw    $t0, 0xb8($sp)
  lw    $t1, 0x5c($sp)
  sll   $v1, $a1, 1
  andi  $t6, $v1, 0xffff
  sw    $t7, ($v0)
  sll   $t8, $a2, 0x10
  or    $t7, $t8, $t6
  slt   $at, $a1, $t0
  sw    $t7, 4($v0)
  bnez  $at, .L7001A310
   addiu $t2, $v0, 8
.L7001A42C:
  lw    $t9, 0x3c($s7)
  lw    $t7, 0x38($s7)
  move  $v0, $t2
  addu  $t8, $t9, $t0
  andi  $t6, $t8, 0xf
  lw    $t8, 0x44($s7)
  sw    $t6, 0x3c($s7)
  addu  $t9, $t7, $t0
  addu  $t6, $t8, $t1
  sw    $t9, 0x38($s7)
  b     .L7001A5CC
   sw    $t6, 0x44($s7)
.L7001A45C:
  lw    $v0, 0x28($s7)
  sra   $t7, $fp, 4
  lw    $t9, 0x44($s7)
  sll   $t1, $t7, 3
  lw    $t8, ($v0)
  addu  $t1, $t1, $t7
  move  $fp, $t7
  lw    $t7, 4($v0)
  addu  $t3, $t9, $t1
  subu  $t6, $t3, $t8
  subu  $v1, $t6, $t7
  bgez  $v1, .L7001A494
   sll   $a1, $fp, 4
  move  $v1, $zero
.L7001A494:
  div   $zero, $v1, $at
  mflo  $v0
  sll   $a0, $v0, 4
  addu  $t4, $a1, $a2
  slt   $at, $t4, $a0
  beqz  $at, .L7001A4B4
   move  $s0, $t2
  move  $a0, $t4
.L7001A4B4:
  andi  $t8, $a0, 0xf
  subu  $t6, $a0, $t8
  slt   $at, $t6, $t0
  beqz  $at, .L7001A570
   subu  $a2, $t1, $v1
  lh    $s5, ($a3)
  lw    $s4, 0x40($s7)
  li    $t5, 1
  sw    $t5, 0x7c($sp)
  sw    $t4, 0x50($sp)
  sw    $t1, 0x5c($sp)
  sw    $t0, 0xb8($sp)
  sw    $a3, 0xb4($sp)
  sw    $a0, 0x90($sp)
  move  $s2, $s7
  subu  $s6, $a1, $a0
  move  $s1, $a2
  jal   ultra_7001A030
   move  $s3, $zero
  lw    $v1, 0x3c($s7)
  lw    $a0, 0x90($sp)
  lw    $a3, 0xb4($sp)
  lw    $t0, 0xb8($sp)
  lw    $t1, 0x5c($sp)
  lw    $t4, 0x50($sp)
  lw    $t5, 0x7c($sp)
  beqz  $v1, .L7001A538
   move  $t2, $v0
  lh    $t7, ($a3)
  sll   $t9, $v1, 1
  addu  $t8, $t7, $t9
  b     .L7001A544
   sh    $t8, ($a3)
.L7001A538:
  lh    $t6, ($a3)
  addiu $t7, $t6, 0x20
  sh    $t7, ($a3)
.L7001A544:
  lw    $t9, 0x3c($s7)
  lw    $t7, 0x38($s7)
  addu  $t8, $t9, $t0
  andi  $t6, $t8, 0xf
  lw    $t8, 0x44($s7)
  sw    $t6, 0x3c($s7)
  addu  $t9, $t7, $t0
  addu  $t6, $t8, $t1
  sw    $t9, 0x38($s7)
  b     .L7001A578
   sw    $t6, 0x44($s7)
.L7001A570:
  sw    $zero, 0x3c($s7)
  sw    $t3, 0x44($s7)
.L7001A578:
  beqz  $a0, .L7001A5C8
   move  $v0, $t2
  beqz  $t5, .L7001A598
   sw    $zero, 0x3c($s7)
  subu  $v1, $t4, $a0
  sll   $t7, $v1, 1
  b     .L7001A59C
   move  $v1, $t7
.L7001A598:
  move  $v1, $zero
.L7001A59C:
  lh    $t9, ($a3)
  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
  addu  $t8, $t9, $v1
  and   $t6, $t8, $at
  lui   $at, 0x200
  or    $t7, $t6, $at
  sll   $t9, $a0, 1
  sw    $t9, 4($v0)
  sw    $t7, ($v0)
  addiu $t2, $t2, 8
.L7001A5C8:
  move  $v0, $t2
.L7001A5CC:
  lw    $ra, 0x4c($sp)
  lw    $s0, 0x28($sp)
  lw    $s1, 0x2c($sp)
  lw    $s2, 0x30($sp)
  lw    $s3, 0x34($sp)
  lw    $s4, 0x38($sp)
  lw    $s5, 0x3c($sp)
  lw    $s6, 0x40($sp)
  lw    $s7, 0x44($sp)
  lw    $fp, 0x48($sp)
  jr    $ra
   addiu $sp, $sp, 0xb0

  nop   
glabel alResampleParam
  addiu $t6, $a1, -1
  addiu $sp, $sp, -0x28
  sltiu $at, $t6, 9
  sw    $ra, 0x14($sp)
  beqz  $at, .L7001A6C0
   move  $a3, $a0
  sll   $t6, $t6, 2
  lui   $at, %hi(jpt_80029850)
  addu  $at, $at, $t6
  lw    $t6, %lo(jpt_80029850)($at)
  jr    $t6
   nop   
.L7001A630:
  b     .L7001A6D8
   sw    $a2, ($a3)
.L7001A638:
  lw    $a0, ($a3)
  mtc1  $zero, $f4
  li    $t7, 1
  sw    $t7, 0x24($a3)
  sw    $zero, 0x30($a3)
  sw    $zero, 0x1c($a3)
  beqz  $a0, .L7001A6D8
   swc1  $f4, 0x20($a3)
  lw    $t9, 8($a0)
  li    $a1, 4
  move  $a2, $zero
  jalr  $t9
  nop   
  b     .L7001A6DC
   lw    $ra, 0x14($sp)
.L7001A674:
  lw    $a0, ($a3)
  li    $t8, 1
  sw    $t8, 0x30($a3)
  beql  $a0, $zero, .L7001A6DC
   lw    $ra, 0x14($sp)
  lw    $t9, 8($a0)
  li    $a1, 9
  move  $a2, $zero
  jalr  $t9
  nop   
  b     .L7001A6DC
   lw    $ra, 0x14($sp)
.L7001A6A4:
  sw    $a2, 0x1c($sp)
  lwc1  $f6, 0x1c($sp)
  b     .L7001A6D8
   swc1  $f6, 0x18($a3)
.L7001A6B4:
  li    $t0, 1
  b     .L7001A6D8
   sw    $t0, 0x1c($a3)
.L7001A6C0:
  lw    $a0, ($a3)
  beql  $a0, $zero, .L7001A6DC
   lw    $ra, 0x14($sp)
  lw    $t9, 8($a0)
  jalr  $t9
  nop   
.L7001A6D8:
  lw    $ra, 0x14($sp)
.L7001A6DC:
  addiu $sp, $sp, 0x28
  move  $v0, $zero
  jr    $ra
   nop   

glabel alResamplePull
  addiu $sp, $sp, -0x50
  sw    $ra, 0x1c($sp)
  sw    $a1, 0x54($sp)
  lw    $t1, ($a0)
  li    $t6, 320
  move  $t0, $a0
  move  $t2, $a2
  bnez  $a2, .L7001A718
   sh    $t6, 0x46($sp)
  b     .L7001A8E4
   lw    $v0, 0x60($sp)
.L7001A718:
  lw    $t7, 0x1c($t0)
  lw    $t8, 0x60($sp)
  beql  $t7, $zero, .L7001A78C
   lwc1  $f2, 0x18($t0)
  sw    $t8, 0x10($sp)
  sw    $t2, 0x58($sp)
  lw    $t9, 4($t1)
  move  $a0, $t1
  addiu $a1, $sp, 0x46
  jalr  $t9
  move  $a2, $t2
  lh    $t3, 0x46($sp)
  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
  and   $t4, $t3, $at
  lui   $at, 0xa00
  lw    $t2, 0x58($sp)
  or    $t5, $t4, $at
  sw    $t5, ($v0)
  lw    $t6, 0x54($sp)
  sll   $t3, $t2, 1
  andi  $t4, $t3, 0xffff
  lh    $t8, ($t6)
  addiu $a1, $v0, 8
  sll   $t9, $t8, 0x10
  or    $t5, $t9, $t4
  b     .L7001A8E0
   sw    $t5, 4($v0)
  lwc1  $f2, 0x18($t0)
.L7001A78C:
  lui   $at, %hi(F64_80029878)
  ldc1  $f4, %lo(F64_80029878)($at)
  cvt.d.s $f6, $f2
  lui   $at, %hi(F64_80029880)
  c.lt.d $f4, $f6
  nop   
  bc1fl .L7001A7BC
   lui   $at, 0x4700
  lwc1  $f8, %lo(F64_80029880)($at)
  swc1  $f8, 0x18($t0)
  lwc1  $f2, 0x18($t0)
  li    $at, 0x47000000 # 32768.000000
.L7001A7BC:
  mtc1  $at, $f12
  move  $a0, $t1
  addiu $a1, $sp, 0x46
  mul.s $f10, $f2, $f12
  trunc.w.s $f16, $f10
  mfc1  $t7, $f16
  mtc1  $t2, $f16
  mtc1  $t7, $f18
  nop   
  cvt.s.w $f4, $f18
  cvt.s.w $f18, $f16
  swc1  $f4, 0x18($t0)
  lwc1  $f6, 0x18($t0)
  div.s $f8, $f6, $f12
  lwc1  $f6, 0x20($t0)
  swc1  $f8, 0x18($t0)
  lwc1  $f10, 0x18($t0)
  mul.s $f4, $f10, $f18
  add.s $f0, $f6, $f4
  trunc.w.s $f8, $f0
  mfc1  $a2, $f8
  nop   
  mtc1  $a2, $f16
  nop   
  cvt.s.w $f10, $f16
  sub.s $f18, $f0, $f10
  swc1  $f18, 0x20($t0)
  lw    $t3, 0x60($sp)
  sw    $t2, 0x58($sp)
  sw    $t0, 0x50($sp)
  sw    $t3, 0x10($sp)
  lw    $t9, 4($t1)
  jalr  $t9
  nop   
  lw    $t0, 0x50($sp)
  lh    $t5, 0x46($sp)
  li    $at, 0x47000000 # 32768.000000
  mtc1  $at, $f4
  lwc1  $f6, 0x18($t0)
  lui   $at, 0x800
  andi  $t6, $t5, 0xffff
  lw    $t2, 0x58($sp)
  or    $t7, $t6, $at
  sw    $t7, ($v0)
  lw    $t8, 0x54($sp)
  mul.s $f8, $f6, $f4
  sll   $t5, $t2, 1
  lh    $t9, ($t8)
  andi  $t6, $t5, 0xffff
  addiu $t8, $v0, 8
  sll   $t4, $t9, 0x10
  or    $t7, $t4, $t6
  trunc.w.s $f16, $f8
  sw    $t7, 4($v0)
  sw    $t8, 0x28($sp)
  lw    $t3, 0x24($t0)
  mfc1  $v1, $f16
  lui   $at, 0x500
  andi  $t9, $t3, 0xff
  sll   $t5, $t9, 0x10
  or    $t4, $t5, $at
  andi  $t6, $v1, 0xffff
  or    $t7, $t4, $t6
  sw    $t7, 8($v0)
  addiu $a1, $v0, 0x10
  lw    $a0, 0x14($t0)
  jal   osVirtualToPhysical
   sw    $a1, 0x48($sp)
  lw    $t8, 0x28($sp)
  lw    $t0, 0x50($sp)
  lw    $a1, 0x48($sp)
  sw    $v0, 4($t8)
  sw    $zero, 0x24($t0)
.L7001A8E0:
  move  $v0, $a1
.L7001A8E4:
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x50
  jr    $ra
   nop   
.align 4

.section .rodata
glabel jpt_80029850
.word .L7001A630
.word .L7001A6C0
.word .L7001A6C0
.word .L7001A638
.word .L7001A6C0
.word .L7001A6C0
.word .L7001A6A4
.word .L7001A6B4
.word .L7001A674
.align 3
glabel F64_80029878
.double 1.99996
glabel F64_80029880
.float 1.9999599
.word 0
.word 0
.word 0

.section .text
glabel _ldexpf
  beqz  $a2, .L7001A920
   li    $t6, 1
  sllv  $t7, $t6, $a2
  mtc1  $t7, $f4
  nop   
  cvt.d.w $f6, $f4
  mul.d $f12, $f12, $f6
  nop   
.L7001A920:
  jr    $ra
   mov.d $f0, $f12

glabel _frexpf
  mtc1  $zero, $f3
  mtc1  $zero, $f2
  sw    $zero, ($a2)
  lui   $at, 0x3ff0
  c.eq.d $f12, $f2
  nop   
  bc1fl .L7001A954
   c.lt.d $f2, $f12
  jr    $ra
   mov.d $f0, $f12

  c.lt.d $f2, $f12
.L7001A954:
  mtc1  $at, $f15
  mtc1  $zero, $f14
  lui   $at, 0x3fe0
  bc1fl .L7001A974
   neg.d $f0, $f12
  b     .L7001A974
   mov.d $f0, $f12
  neg.d $f0, $f12
.L7001A974:
  c.le.d $f14, $f0
  nop   
  bc1fl .L7001A9B4
   li    $at, 0x3FE00000 # 1.750000
  mtc1  $at, $f17
  mtc1  $zero, $f16
  nop   
.L7001A990:
  mul.d $f0, $f0, $f16
  lw    $t6, ($a2)
  addiu $t7, $t6, 1
  sw    $t7, ($a2)
  c.le.d $f14, $f0
  nop   
  bc1t  .L7001A990
   nop   
  li    $at, 0x3FE00000 # 1.750000
.L7001A9B4:
  mtc1  $at, $f17
  mtc1  $zero, $f16
  nop   
  c.lt.d $f0, $f16
  nop   
  bc1fl .L7001A9F0
   c.lt.d $f2, $f12
  add.d $f0, $f0, $f0
.L7001A9D4:
  lw    $t8, ($a2)
  c.lt.d $f0, $f16
  addiu $t9, $t8, -1
  sw    $t9, ($a2)
  bc1tl .L7001A9D4
   add.d $f0, $f0, $f0
  c.lt.d $f2, $f12
.L7001A9F0:
  nop   
  bc1fl .L7001AA08
   neg.d $f2, $f0
  b     .L7001AA08
   mov.d $f2, $f0
  neg.d $f2, $f0
.L7001AA08:
  mov.d $f0, $f2
  jr    $ra
   nop   

glabel alEnvmixerParam
  addiu $sp, $sp, -0x18
  li    $v0, 1
  sw    $ra, 0x14($sp)
  beq   $a1, $v0, .L7001AAC0
   move  $a3, $a0
  li    $at, 3
  beq   $a1, $at, .L7001AA4C
   li    $at, 4
  beq   $a1, $at, .L7001AA6C
   li    $at, 9
  beql  $a1, $at, .L7001AA9C
   lw    $a0, ($a3)
  b     .L7001AACC
   lw    $a0, ($a3)
.L7001AA4C:
  lw    $v0, 0x40($a3)
  beql  $v0, $zero, .L7001AA64
   sw    $a2, 0x3c($a3)
  b     .L7001AA64
   sw    $a2, ($v0)
  sw    $a2, 0x3c($a3)
.L7001AA64:
  b     .L7001AAE0
   sw    $a2, 0x40($a3)
.L7001AA6C:
  lw    $a0, ($a3)
  sw    $v0, 0x38($a3)
  sw    $zero, 0x48($a3)
  beqz  $a0, .L7001AAE0
   sh    $v0, 0x1a($a3)
  lw    $t9, 8($a0)
  li    $a1, 4
  jalr  $t9
  nop   
  b     .L7001AAE4
   lw    $ra, 0x14($sp)
  lw    $a0, ($a3)
.L7001AA9C:
  sw    $v0, 0x48($a3)
  beql  $a0, $zero, .L7001AAE4
   lw    $ra, 0x14($sp)
  lw    $t9, 8($a0)
  li    $a1, 9
  jalr  $t9
  nop   
  b     .L7001AAE4
   lw    $ra, 0x14($sp)
.L7001AAC0:
  b     .L7001AAE0
   sw    $a2, ($a3)
  lw    $a0, ($a3)
.L7001AACC:
  beql  $a0, $zero, .L7001AAE4
   lw    $ra, 0x14($sp)
  lw    $t9, 8($a0)
  jalr  $t9
  nop   
.L7001AAE0:
  lw    $ra, 0x14($sp)
.L7001AAE4:
  addiu $sp, $sp, 0x18
  move  $v0, $zero
  jr    $ra
   nop   

glabel ultra_7001AAF4
  bnezl $a0, .L7001AB28
   mtc1  $a0, $f6
  c.le.s $f14, $f12
  li    $t6, 65535
  li    $v0, -32768
  bc1f  .L7001AB1C
   nop   
  sh    $t6, ($a1)
  jr    $ra
   li    $v0, 32767

.L7001AB1C:
  jr    $ra
   sh    $zero, ($a1)

  mtc1  $a0, $f6
.L7001AB28:
  sub.s $f4, $f12, $f14
  li    $at, 0x40200000 # 2.500000
  mtc1  $at, $f5
  cvt.s.w $f8, $f6
  li    $at, 0x3F800000 # 1.000000
  div.s $f10, $f4, $f8
  mtc1  $zero, $f4
  cvt.d.s $f6, $f10
  mtc1  $zero, $f10
  mul.d $f8, $f6, $f4
  cvt.s.d $f2, $f8
  c.lt.s $f2, $f10
  mov.s $f0, $f2
  bc1fl .L7001AB74
   trunc.w.s $f4, $f0
  mtc1  $at, $f6
  nop   
  sub.s $f0, $f2, $f6
  trunc.w.s $f4, $f0
.L7001AB74:
  lui   $at, %hi(F32_80029964)
  mfc1  $v1, $f4
  lwc1  $f4, %lo(F32_80029964)($at)
  sll   $t8, $v1, 0x10
  sra   $v0, $t8, 0x10
  mtc1  $v0, $f8
  nop   
  cvt.s.w $f10, $f8
  sub.s $f6, $f0, $f10
  mul.s $f8, $f6, $f4
  trunc.w.s $f10, $f8
  mfc1  $t7, $f10
  nop   
  sh    $t7, ($a1)
  jr    $ra
   nop   

glabel ultra_7001ABB4
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  bnez  $s2, .L7001ABCC
   lw    $s1, ($s0)
  b     .L7001AE44
   move  $v0, $s4
.L7001ABCC:
  bnez  $s1, .L7001ABF0
   lui   $a0, %hi(aAssertionFaultSSLineD_1)
  lui   $a1, %hi(aSource)
  lui   $a2, %hi(aEnv_c_1)
  addiu $a2, %lo(aEnv_c_1) # addiu $a2, $a2, -0x66a4
  addiu $a1, %lo(aSource) # addiu $a1, $a1, -0x66ac
  addiu $a0, %lo(aAssertionFaultSSLineD_1) # addiu $a0, $a0, -0x66d8
  jal   osSyncPrintf
   li    $a3, 373
.L7001ABF0:
  sw    $s4, 0x10($sp)
  lw    $t9, 4($s1)
  move  $a0, $s1
  move  $a1, $s5
  move  $a2, $s2
  jalr  $t9
  move  $a3, $s6
  lh    $t6, ($s5)
  lui   $at, 0x800
  sll   $s4, $s2, 1
  andi  $t7, $t6, 0xffff
  or    $t8, $t7, $at
  sw    $t8, ($v0)
  lh    $t9, ($s3)
  lui   $at, 0x808
  addiu $s1, $v0, 0x10
  addiu $t7, $t9, 0x440
  sll   $t8, $t7, 0x10
  andi  $t9, $s4, 0xffff
  or    $t6, $t8, $t9
  sw    $t6, 4($v0)
  lh    $t7, ($s3)
  move  $s2, $s1
  addiu $t8, $t7, 0x580
  andi  $t9, $t8, 0xffff
  or    $t6, $t9, $at
  sw    $t6, 8($v0)
  lh    $v1, ($s3)
  addiu $t7, $v1, 0x800
  andi  $t8, $t7, 0xffff
  addiu $t6, $v1, 0x6c0
  sll   $t7, $t6, 0x10
  or    $t9, $t8, $t7
  sw    $t9, 0xc($v0)
  lw    $t6, 0x38($s0)
  lui   $t9, %hi(eqpower)
  beql  $t6, $zero, .L7001AE20
   lui   $t6, 0x308
  lh    $t8, 0x18($s0)
  sw    $zero, 0x38($s0)
  lh    $t6, 0x1a($s0)
  sll   $t7, $t8, 1
  addu  $t9, $t9, $t7
  lh    $t9, %lo(eqpower)($t9)
  lw    $a0, 0x34($s0)
  addiu $a1, $s0, 0x24
  multu $t9, $t6
  lh    $t9, 0x1c($s0)
  mtc1  $t9, $f4
  nop   
  cvt.s.w $f14, $f4
  mflo  $t8
  sra   $t7, $t8, 0xf
  sh    $t7, 0x28($s0)
  lh    $t6, 0x28($s0)
  mtc1  $t6, $f6
  jal   ultra_7001AAF4
   cvt.s.w $f12, $f6
  lh    $t8, 0x18($s0)
  lui   $t6, %hi(eqpower+0xFE)
  sh    $v0, 0x26($s0)
  sll   $t7, $t8, 1
  negu  $t9, $t7
  addu  $t6, $t6, $t9
  lh    $t6, %lo(eqpower+0xFE)($t6)
  lh    $t8, 0x1a($s0)
  lw    $a0, 0x34($s0)
  addiu $a1, $s0, 0x2a
  multu $t6, $t8
  lh    $t6, 0x1e($s0)
  mtc1  $t6, $f8
  nop   
  cvt.s.w $f14, $f8
  mflo  $t7
  sra   $t9, $t7, 0xf
  sh    $t9, 0x2e($s0)
  lh    $t8, 0x2e($s0)
  mtc1  $t8, $f10
  jal   ultra_7001AAF4
   cvt.s.w $f12, $f10
  lh    $t7, 0x1c($s0)
  sh    $v0, 0x2c($s0)
  move  $v1, $s1
  lui   $at, 0x906
  andi  $t9, $t7, 0xffff
  or    $t6, $t9, $at
  sw    $t6, ($v1)
  sw    $zero, 4($v1)
  lh    $t8, 0x1e($s0)
  addiu $s1, $s1, 8
  move  $a0, $s1
  lui   $at, 0x904
  andi  $t7, $t8, 0xffff
  or    $t9, $t7, $at
  sw    $t9, ($a0)
  sw    $zero, 4($a0)
  lh    $t6, 0x28($s0)
  addiu $s1, $s1, 8
  lui   $at, 0x902
  andi  $t8, $t6, 0xffff
  or    $t7, $t8, $at
  move  $a1, $s1
  sw    $t7, ($a1)
  lh    $t6, 0x26($s0)
  lhu   $t9, 0x24($s0)
  addiu $s1, $s1, 8
  sll   $t8, $t6, 0x10
  or    $t6, $t8, $t9
  sw    $t6, 4($a1)
  lh    $t7, 0x2e($s0)
  lui   $at, 0x900
  move  $a2, $s1
  andi  $t8, $t7, 0xffff
  or    $t9, $t8, $at
  sw    $t9, ($a2)
  lh    $t7, 0x2c($s0)
  lhu   $t6, 0x2a($s0)
  addiu $s1, $s1, 8
  sll   $t8, $t7, 0x10
  or    $t7, $t8, $t6
  sw    $t7, 4($a2)
  lh    $t9, 0x20($s0)
  lui   $at, 0x908
  move  $v0, $s1
  andi  $t8, $t9, 0xffff
  or    $t6, $t8, $at
  sw    $t6, ($v0)
  lh    $t7, 0x22($s0)
  addiu $s1, $s1, 8
  move  $s2, $s1
  andi  $t9, $t7, 0xffff
  sw    $t9, 4($v0)
  lui   $t8, 0x309
  sw    $t8, ($s2)
  lw    $a0, 0x14($s0)
  jal   osVirtualToPhysical
   addiu $s1, $s1, 8
  b     .L7001AE34
   sw    $v0, 4($s2)
  lui   $t6, 0x308
.L7001AE20:
  sw    $t6, ($s2)
  lw    $a0, 0x14($s0)
  jal   osVirtualToPhysical
   addiu $s1, $s1, 8
  sw    $v0, 4($s2)
.L7001AE34:
  lh    $t7, ($s5)
  move  $v0, $s1
  addu  $t9, $t7, $s4
  sh    $t9, ($s5)
.L7001AE44:
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   

  jr    $ra
   nop   

glabel alEnvmixerPull
  addiu $sp, $sp, -0xd8
  lw    $t6, 0xe8($sp)
  sw    $ra, 0x54($sp)
  sw    $fp, 0x50($sp)
  sw    $s7, 0x4c($sp)
  sw    $s6, 0x48($sp)
  sw    $s5, 0x44($sp)
  sw    $s4, 0x40($sp)
  sw    $s3, 0x3c($sp)
  sw    $s2, 0x38($sp)
  sw    $s1, 0x34($sp)
  sw    $s0, 0x30($sp)
  sdc1  $f22, 0x28($sp)
  sdc1  $f20, 0x20($sp)
  sw    $a1, 0xdc($sp)
  sw    $a2, 0xe0($sp)
  sw    $a3, 0xe4($sp)
  sw    $a0, 0xd0($sp)
  sw    $a3, 0xc4($sp)
  sh    $zero, 0xbe($sp)
  sh    $zero, 0xce($sp)
  sw    $t6, 0xd4($sp)
  lw    $t8, 0x3c($a0)
  move  $s7, $a0
  li    $at, 0x3FC00000 # 1.500000
  beql  $t8, $zero, .L7001B44C
   lw    $t6, 0x48($s7)
  mtc1  $at, $f23
  li    $at, 0x40F00000 # 7.500000
  mtc1  $at, $f21
  mtc1  $zero, $f22
  mtc1  $zero, $f20
  li    $s1, 1
  lw    $t9, 0x3c($s7)
.L7001AEE4:
  lw    $v0, 0xc4($sp)
  lw    $t8, 0xe0($sp)
  lw    $t6, 4($t9)
  lui   $a0, %hi(aAssertionFaultSSLineD)
  addiu $a0, %lo(aAssertionFaultSSLineD) # addiu $a0, $a0, -0x6770
  subu  $fp, $t6, $v0
  slt   $at, $t8, $fp
  bnez  $at, .L7001B448
   sw    $t6, 0xc4($sp)
  bgez  $fp, .L7001AF24
   lui   $a1, %hi(aSamples0)
  lui   $a2, %hi(aEnv_c)
  addiu $a2, %lo(aEnv_c) # addiu $a2, $a2, -0x6734
  addiu $a1, %lo(aSamples0) # addiu $a1, $a1, -0x6744
  jal   osSyncPrintf
   li    $a3, 104
.L7001AF24:
  slti  $at, $fp, 0xa1
  bnez  $at, .L7001AF4C
   lui   $a0, %hi(aAssertionFaultSSLineD_0)
  lui   $a1, %hi(aSamplesAl_max_rsp_samples)
  lui   $a2, %hi(aEnv_c_0)
  addiu $a2, %lo(aEnv_c_0) # addiu $a2, $a2, -0x66e0
  addiu $a1, %lo(aSamplesAl_max_rsp_samples) # addiu $a1, $a1, -0x6700
  addiu $a0, %lo(aAssertionFaultSSLineD_0) # addiu $a0, $a0, -0x672c
  jal   osSyncPrintf
   li    $a3, 105
.L7001AF4C:
  lw    $v1, 0x3c($s7)
  lhu   $t9, 8($v1)
  sltiu $at, $t9, 0x11
  beqz  $at, .L7001B3B8
   sll   $t9, $t9, 2
  lui   $at, %hi(jpt_80029968)
  addu  $at, $at, $t9
  lw    $t9, %lo(jpt_80029968)($at)
  jr    $t9
   nop   
.L7001AF74:
  lh    $t6, 0xa($v1)
  move  $s0, $v1
  beql  $t6, $zero, .L7001AF9C
   lw    $t9, 8($s7)
  lw    $t9, 8($s7)
  move  $a0, $s7
  li    $a1, 8
  jalr  $t9
  move  $a2, $zero
  lw    $t9, 8($s7)
.L7001AF9C:
  move  $a0, $s7
  li    $a1, 5
  jalr  $t9
  lw    $a2, 0x18($s0)
  lw    $t9, 8($s7)
  move  $a0, $s7
  li    $a1, 9
  jalr  $t9
  move  $a2, $zero
  sw    $s1, 0x38($s7)
  sw    $zero, 0x30($s7)
  lw    $t7, 0x14($s0)
  sw    $t7, 0x34($s7)
  lh    $v1, 0x10($s0)
  multu $v1, $v1
  mflo  $a0
  sra   $t8, $a0, 0xf
  sh    $t8, 0x1a($s7)
  lbu   $t6, 0x12($s0)
  lui   $t8, %hi(eqpower)
  sh    $t6, 0x18($s7)
  lbu   $t9, 0x13($s0)
  sll   $t7, $t9, 1
  addu  $t8, $t8, $t7
  lh    $t8, %lo(eqpower)($t8)
  sh    $t8, 0x20($s7)
  lbu   $t6, 0x13($s0)
  lui   $t8, %hi(eqpower+0xFE)
  sll   $t9, $t6, 1
  negu  $t7, $t9
  addu  $t8, $t8, $t7
  lh    $t8, %lo(eqpower+0xFE)($t8)
  sh    $t8, 0x22($s7)
  lw    $t6, 0x14($s0)
  beql  $t6, $zero, .L7001B03C
   lh    $v0, 0x18($s7)
  sh    $s1, 0x1c($s7)
  b     .L7001B080
   sh    $s1, 0x1e($s7)
  lh    $v0, 0x18($s7)
.L7001B03C:
  lui   $t7, %hi(eqpower)
  lh    $v1, 0x1a($s7)
  sll   $t9, $v0, 1
  addu  $t7, $t7, $t9
  lh    $t7, %lo(eqpower)($t7)
  negu  $t9, $t9
  multu $t7, $v1
  lui   $t7, %hi(eqpower+0xFE)
  addu  $t7, $t7, $t9
  mflo  $t8
  sra   $t6, $t8, 0xf
  sh    $t6, 0x1c($s7)
  lh    $t7, %lo(eqpower+0xFE)($t7)
  multu $t7, $v1
  mflo  $t8
  sra   $t6, $t8, 0xf
  sh    $t6, 0x1e($s7)
.L7001B080:
  lw    $t9, ($s7)
  beql  $t9, $zero, .L7001B404
   lh    $t8, 0xbe($sp)
  lwc1  $f4, 0xc($s0)
  li    $a1, 7
  swc1  $f4, 0xa4($sp)
  lw    $a0, ($s7)
  lw    $a2, 0xa4($sp)
  lw    $t9, 8($a0)
  jalr  $t9
  nop   
  b     .L7001B404
   lh    $t8, 0xbe($sp)
.L7001B0B4:
  move  $s0, $s7
  addiu $s5, $sp, 0xce
  addiu $s3, $sp, 0xbe
  move  $s2, $fp
  lw    $s6, 0xe4($sp)
  jal   ultra_7001ABB4
   lw    $s4, 0xd4($sp)
  sw    $v0, 0xd4($sp)
  lw    $t7, 0x30($s7)
  lw    $a0, 0x34($s7)
  li    $s1, 1
  addu  $a1, $t7, $fp
  slt   $at, $a1, $a0
  bnez  $at, .L7001B150
   sw    $a1, 0x30($s7)
  lh    $v0, 0x18($s7)
  lui   $t9, %hi(eqpower)
  lh    $v1, 0x1a($s7)
  sll   $t6, $v0, 1
  addu  $t9, $t9, $t6
  lh    $t9, %lo(eqpower)($t9)
  negu  $t6, $t6
  multu $t9, $v1
  lui   $t9, %hi(eqpower+0xFE)
  addu  $t9, $t9, $t6
  mflo  $t7
  sra   $t8, $t7, 0xf
  sh    $t8, 0x28($s7)
  lh    $t9, %lo(eqpower+0xFE)($t9)
  lh    $t6, 0x28($s7)
  sw    $a0, 0x30($s7)
  multu $t9, $v1
  sh    $t6, 0x1c($s7)
  mflo  $t7
  sra   $t8, $t7, 0xf
  sh    $t8, 0x2e($s7)
  lh    $t9, 0x2e($s7)
  b     .L7001B24C
   sh    $t9, 0x1e($s7)
.L7001B150:
  lh    $t7, 0x1c($s7)
  lh    $v1, 0x26($s7)
  lhu   $a0, 0x24($s7)
  mtc1  $t7, $f6
  sll   $t8, $v1, 0x10
  mtc1  $t8, $f8
  mtc1  $a0, $f4
  cvt.s.w $f12, $f6
  move  $v0, $a1
  li    $at, 0x4F800000 # 4294967296.000000
  cvt.s.w $f10, $f8
  bgez  $a0, .L7001B190
   cvt.s.w $f6, $f4
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7001B190:
  add.s $f4, $f10, $f6
  lh    $t7, 0x1e($s7)
  lh    $v1, 0x2c($s7)
  lhu   $a0, 0x2a($s7)
  cvt.d.s $f8, $f4
  mtc1  $v0, $f4
  div.d $f10, $f8, $f20
  sll   $t8, $v1, 0x10
  move  $v0, $a1
  li    $at, 0x4F800000 # 4294967296.000000
  cvt.s.w $f8, $f4
  cvt.s.d $f6, $f10
  mul.s $f10, $f6, $f8
  cvt.d.s $f8, $f12
  cvt.d.s $f4, $f10
  mul.d $f6, $f4, $f22
  add.d $f10, $f8, $f6
  mtc1  $t7, $f8
  mtc1  $t8, $f6
  cvt.s.d $f12, $f10
  cvt.s.w $f2, $f8
  trunc.w.s $f4, $f12
  cvt.s.w $f10, $f6
  mfc1  $t9, $f4
  mtc1  $a0, $f4
  sh    $t9, 0x1c($s7)
  bgez  $a0, .L7001B20C
   cvt.s.w $f8, $f4
  mtc1  $at, $f6
  nop   
  add.s $f8, $f8, $f6
.L7001B20C:
  add.s $f4, $f10, $f8
  cvt.d.s $f6, $f4
  mtc1  $v0, $f4
  div.d $f10, $f6, $f20
  cvt.s.w $f6, $f4
  cvt.s.d $f8, $f10
  mul.s $f10, $f8, $f6
  cvt.d.s $f6, $f2
  cvt.d.s $f4, $f10
  mul.d $f8, $f4, $f22
  add.d $f10, $f6, $f8
  cvt.s.d $f2, $f10
  trunc.w.s $f4, $f2
  mfc1  $t9, $f4
  nop   
  sh    $t9, 0x1e($s7)
.L7001B24C:
  lh    $t7, 0x1c($s7)
  bnezl $t7, .L7001B260
   lh    $t8, 0x1e($s7)
  sh    $s1, 0x1c($s7)
  lh    $t8, 0x1e($s7)
.L7001B260:
  bnezl $t8, .L7001B270
   lw    $v1, 0x3c($s7)
  sh    $s1, 0x1e($s7)
  lw    $v1, 0x3c($s7)
.L7001B270:
  li    $at, 12
  lh    $a0, 8($v1)
  bnel  $a0, $at, .L7001B290
   li    $at, 11
  lw    $t6, 0xc($v1)
  sh    $t6, 0x18($s7)
  lh    $a0, 8($v1)
  li    $at, 11
.L7001B290:
  bnel  $a0, $at, .L7001B2C0
   li    $at, 16
  sw    $zero, 0x30($s7)
  lw    $v0, 0xc($v1)
  multu $v0, $v0
  mflo  $v0
  sra   $t9, $v0, 0xf
  sh    $t9, 0x1a($s7)
  lw    $t7, 0x10($v1)
  sw    $t7, 0x34($s7)
  lh    $a0, 8($v1)
  li    $at, 16
.L7001B2C0:
  bne   $a0, $at, .L7001B2FC
   nop   
  lw    $t8, 0xc($v1)
  lui   $t9, %hi(eqpower)
  sll   $t6, $t8, 1
  addu  $t9, $t9, $t6
  lh    $t9, %lo(eqpower)($t9)
  sh    $t9, 0x20($s7)
  lw    $t7, 0xc($v1)
  lui   $t9, %hi(eqpower+0xFE)
  sll   $t8, $t7, 1
  negu  $t6, $t8
  addu  $t9, $t9, $t6
  lh    $t9, %lo(eqpower+0xFE)($t9)
  sh    $t9, 0x22($s7)
.L7001B2FC:
  b     .L7001B400
   sw    $s1, 0x38($s7)
.L7001B304:
  lh    $t7, 0xa($v1)
  move  $s0, $v1
  beql  $t7, $zero, .L7001B32C
   lw    $t9, 8($s7)
  lw    $t9, 8($s7)
  move  $a0, $s7
  li    $a1, 8
  jalr  $t9
  move  $a2, $zero
  lw    $t9, 8($s7)
.L7001B32C:
  move  $a0, $s7
  li    $a1, 5
  jalr  $t9
  lw    $a2, 0xc($s0)
  lw    $t9, 8($s7)
  move  $a0, $s7
  li    $a1, 9
  jalr  $t9
  move  $a2, $zero
  b     .L7001B404
   lh    $t8, 0xbe($sp)
.L7001B358:
  move  $s0, $s7
  addiu $s5, $sp, 0xce
  addiu $s3, $sp, 0xbe
  move  $s2, $fp
  lw    $s6, 0xe4($sp)
  jal   ultra_7001ABB4
   lw    $s4, 0xd4($sp)
  sw    $v0, 0xd4($sp)
  lw    $t9, 8($s7)
  li    $s1, 1
  move  $a0, $s7
  li    $a1, 4
  jalr  $t9
  move  $a2, $zero
  b     .L7001B404
   lh    $t8, 0xbe($sp)
.L7001B398:
  lw    $t8, 0xc($v1)
  lui   $a0, %hi(alGlobals)
  lw    $a0, %lo(alGlobals)($a0)
  sw    $zero, 0xd8($t8)
  jal   _freePVoice
   lw    $a1, 0xc($v1)
  b     .L7001B404
   lh    $t8, 0xbe($sp)
.L7001B3B8:
  move  $s0, $s7
  addiu $s5, $sp, 0xce
  addiu $s3, $sp, 0xbe
  move  $s2, $fp
  lw    $s6, 0xe4($sp)
  jal   ultra_7001ABB4
   lw    $s4, 0xd4($sp)
  sw    $v0, 0xd4($sp)
  lw    $t6, 0x30($s7)
  lw    $t9, 8($s7)
  lw    $v1, 0x3c($s7)
  addu  $t7, $t6, $fp
  sw    $t7, 0x30($s7)
  li    $s1, 1
  move  $a0, $s7
  lw    $a2, 0xc($v1)
  jalr  $t9
  lh    $a1, 8($v1)
.L7001B400:
  lh    $t8, 0xbe($sp)
.L7001B404:
  lw    $t9, 0xe0($sp)
  sll   $t6, $fp, 1
  addu  $t7, $t8, $t6
  subu  $t8, $t9, $fp
  sh    $t7, 0xbe($sp)
  sw    $t8, 0xe0($sp)
  lw    $a0, 0x3c($s7)
  lw    $t6, ($a0)
  bnez  $t6, .L7001B430
   sw    $t6, 0x3c($s7)
  sw    $zero, 0x40($s7)
.L7001B430:
  jal   __freeParam
   nop   
  lw    $t9, 0xd0($sp)
  lw    $t8, 0x3c($t9)
  bnezl $t8, .L7001AEE4
   lw    $t9, 0x3c($s7)
.L7001B448:
  lw    $t6, 0x48($s7)
.L7001B44C:
  li    $s1, 1
  move  $s0, $s7
  bne   $s1, $t6, .L7001B484
   addiu $s5, $sp, 0xce
  addiu $s3, $sp, 0xbe
  lw    $s2, 0xe0($sp)
  lw    $s6, 0xe4($sp)
  jal   ultra_7001ABB4
   lw    $s4, 0xd4($sp)
  sw    $v0, 0xd4($sp)
  lw    $t7, 0x30($s7)
  lw    $t9, 0xe0($sp)
  addu  $t8, $t7, $t9
  sw    $t8, 0x30($s7)
.L7001B484:
  lw    $a0, 0x34($s7)
  lw    $t6, 0x30($s7)
  slt   $at, $a0, $t6
  beql  $at, $zero, .L7001B4A0
   lw    $ra, 0x54($sp)
  sw    $a0, 0x30($s7)
  lw    $ra, 0x54($sp)
.L7001B4A0:
  lw    $v0, 0xd4($sp)
  ldc1  $f20, 0x20($sp)
  ldc1  $f22, 0x28($sp)
  lw    $s0, 0x30($sp)
  lw    $s1, 0x34($sp)
  lw    $s2, 0x38($sp)
  lw    $s3, 0x3c($sp)
  lw    $s4, 0x40($sp)
  lw    $s5, 0x44($sp)
  lw    $s6, 0x48($sp)
  lw    $s7, 0x4c($sp)
  lw    $fp, 0x50($sp)
  jr    $ra
   addiu $sp, $sp, 0xd8

  nop   
  nop

.section .data
glabel eqpower
.half 32767,32764,32757,32744,32727,32704,32677,32644
.half 32607,32564,32517,32464,32407,32344,32277,32205
.half 32127,32045,31958,31866,31770,31668,31561,31450
.half 31334,31213,31087,30957,30822,30682,30537,30388
.half 30234,30075,29912,29744,29572,29395,29214,29028
.half 28838,28643,28444,28241,28033,27821,27605,27385
.half 27160,26931,26698,26461,26220,25975,25726,25473
.half 25216,24956,24691,24423,24151,23875,23596,23313
.half 23026,22736,22442,22145,21845,21541,21234,20924
.half 20610,20294,19974,19651,19325,18997,18665,18331
.half 17993,17653,17310,16965,16617,16266,15913,15558
.half 15200,14840,14477,14113,13746,13377,13006,12633
.half 12258,11881,11503,11122,10740,10357, 9971, 9584
.half  9196, 8806, 8415, 8023, 7630, 7235, 6839, 6442
.half  6044, 5646, 5246, 4845, 4444, 4042, 3640, 3237
.half  2833, 2429, 2025, 1620, 1216,  810,  405,    0

.section .rodata
glabel aAssertionFaultSSLineD
.asciiz "\n--- ASSERTION FAULT - %s - %s, line %d\n\n"
.align 2
glabel aSamples0
.asciiz "samples >= 0"
.align 2
glabel aEnv_c
.asciiz "env.c"
.align 2
glabel aAssertionFaultSSLineD_0
.asciiz "\n--- ASSERTION FAULT - %s - %s, line %d\n\n"
.align 4
glabel aSamplesAl_max_rsp_samples
.asciiz "samples <= AL_MAX_RSP_SAMPLES"
.align 4
glabel aEnv_c_0
.asciiz "env.c"
.align 2
glabel aAssertionFaultSSLineD_1
.asciiz "\n--- ASSERTION FAULT - %s - %s, line %d\n\n"
.align 2
glabel aSource
.asciiz "source"
.align 2
glabel aEnv_c_1
.asciiz "env.c"
.align 2
glabel F32_80029964
.float 65535.0
glabel jpt_80029968
.word .L7001B398
.word .L7001B3B8
.word .L7001B3B8
.word .L7001B3B8
.word .L7001B3B8
.word .L7001B3B8
.word .L7001B3B8
.word .L7001B3B8
.word .L7001B3B8
.word .L7001B3B8
.word .L7001B3B8
.word .L7001B0B4
.word .L7001B0B4
.word .L7001AF74
.word .L7001B304
.word .L7001B358
.word .L7001B0B4
.align 4

.section .text
glabel ultra_7001B4E0
  li    $at, 2
  bne   $a1, $at, .L7001B508
   lw    $v0, 0x1c($a0)
  lw    $t6, 0x14($a0)
  sll   $t7, $t6, 2
  addu  $t8, $v0, $t7
  sw    $a2, ($t8)
  lw    $t9, 0x14($a0)
  addiu $t0, $t9, 1
  sw    $t0, 0x14($a0)
.L7001B508:
  jr    $ra
   move  $v0, $zero

glabel ultra_7001B510
  addiu $sp, $sp, -0x40
  lw    $t0, 0x50($sp)
  sw    $ra, 0x3c($sp)
  sw    $s6, 0x38($sp)
  sw    $s5, 0x34($sp)
  sw    $s4, 0x30($sp)
  sw    $s3, 0x2c($sp)
  sw    $s2, 0x28($sp)
  sw    $s1, 0x24($sp)
  sw    $s0, 0x20($sp)
  lw    $v1, 0x1c($a0)
  lui   $t6, (0x020006C0 >> 16) # lui $t6, 0x200
  sll   $v0, $a2, 1
  lui   $t7, (0x02000800 >> 16) # lui $t7, 0x200
  ori   $t6, (0x020006C0 & 0xFFFF) # ori $t6, $t6, 0x6c0
  ori   $t7, (0x02000800 & 0xFFFF) # ori $t7, $t7, 0x800
  sw    $t6, ($t0)
  sw    $v0, 4($t0)
  sw    $t7, 8($t0)
  sw    $v0, 0xc($t0)
  lw    $t8, 0x14($a0)
  move  $s4, $a2
  move  $s5, $a1
  move  $s6, $a3
  move  $s3, $a0
  move  $s0, $zero
  blez  $t8, .L7001B5BC
   addiu $s2, $t0, 0x10
  move  $s1, $v1
.L7001B584:
  lw    $a0, ($s1)
  sw    $s2, 0x10($sp)
  move  $a1, $s5
  lw    $t9, 4($a0)
  move  $a2, $s4
  move  $a3, $s6
  jalr  $t9
  nop   
  lw    $t1, 0x14($s3)
  addiu $s0, $s0, 1
  addiu $s1, $s1, 4
  slt   $at, $s0, $t1
  bnez  $at, .L7001B584
   move  $s2, $v0
.L7001B5BC:
  lw    $ra, 0x3c($sp)
  move  $v0, $s2
  lw    $s2, 0x28($sp)
  lw    $s0, 0x20($sp)
  lw    $s1, 0x24($sp)
  lw    $s3, 0x2c($sp)
  lw    $s4, 0x30($sp)
  lw    $s5, 0x34($sp)
  lw    $s6, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x40

  nop   
  nop   
glabel alSaveParam
  li    $at, 1
  beq   $a1, $at, .L7001B610
   move  $v0, $zero
  li    $at, 6
  beql  $a1, $at, .L7001B61C
   sw    $a2, 0x14($a0)
  jr    $ra
   move  $v0, $zero

.L7001B610:
  jr    $ra
   sw    $a2, ($a0)

  sw    $a2, 0x14($a0)
.L7001B61C:
  jr    $ra
   move  $v0, $zero

glabel alSavePull
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $a0, 0x20($sp)
  lw    $a0, ($a0)
  lw    $t7, 0x30($sp)
  sw    $a2, 0x28($sp)
  sw    $t7, 0x10($sp)
  lw    $t9, 4($a0)
  jalr  $t9
  nop   
  lw    $a2, 0x28($sp)
  lui   $v1, 0x800
  lui   $t2, (0x04400580 >> 16) # lui $t2, 0x440
  sll   $t8, $a2, 1
  sll   $t3, $a2, 2
  andi  $t0, $t8, 0xffff
  ori   $t2, (0x04400580 & 0xFFFF) # ori $t2, $t2, 0x580
  lui   $t1, 0xd00
  andi  $t4, $t3, 0xffff
  lui   $t5, 0x600
  sw    $t0, 4($v0)
  sw    $v1, ($v0)
  sw    $t1, 8($v0)
  sw    $t2, 0xc($v0)
  sw    $t4, 0x14($v0)
  sw    $v1, 0x10($v0)
  sw    $t5, 0x18($v0)
  lw    $t6, 0x20($sp)
  addiu $v0, $v0, 0x20
  lw    $t7, 0x14($t6)
  sw    $t7, -4($v0)
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   

glabel osJamMesg
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  sw    $a0, 0x28($sp)
  sw    $a1, 0x2c($sp)
  sw    $a2, 0x30($sp)
  sw    $s1, 0x18($sp)
  jal   __osDisableInt
   sw    $s0, 0x14($sp)
  lw    $t6, 0x28($sp)
  move  $s0, $v0
  lw    $t7, 8($t6)
  lw    $t8, 0x10($t6)
  slt   $at, $t7, $t8
  bnez  $at, .L7001B748
   nop   
.L7001B6EC:
  lw    $t9, 0x30($sp)
  li    $at, 1
  bne   $t9, $at, .L7001B720
   nop   
  lui   $t1, %hi(__osRunningThread) 
  lw    $t1, %lo(__osRunningThread)($t1)
  li    $t0, 8
  sh    $t0, 0x10($t1)
  lw    $a0, 0x28($sp)
  jal   __osEnqueueAndYield
   addiu $a0, $a0, 4
  b     .L7001B730
   nop   
.L7001B720:
  jal   __osRestoreInt
   move  $a0, $s0
  b     .L7001B7EC
   li    $v0, -1
.L7001B730:
  lw    $t2, 0x28($sp)
  lw    $t3, 8($t2)
  lw    $t4, 0x10($t2)
  slt   $at, $t3, $t4
  beqz  $at, .L7001B6EC
   nop   
.L7001B748:
  lw    $t5, 0x28($sp)
  lw    $t6, 0xc($t5)
  lw    $t7, 0x10($t5)
  addu  $t8, $t6, $t7
  addiu $t9, $t8, -1
  div   $zero, $t9, $t7
  mfhi  $t0
  sw    $t0, 0xc($t5)
  lw    $t2, 0x28($sp)
  lw    $t1, 0x2c($sp)
  bnez  $t7, .L7001B77C
   nop   
  break 7
.L7001B77C:
  li    $at, -1
  bne   $t7, $at, .L7001B794
   lui   $at, 0x8000
  bne   $t9, $at, .L7001B794
   nop   
  break 6
.L7001B794:
  lw    $t4, 0xc($t2)
  lw    $t3, 0x14($t2)
  sll   $t6, $t4, 2
  addu  $t8, $t3, $t6
  sw    $t1, ($t8)
  lw    $t9, 0x28($sp)
  lw    $t7, 8($t9)
  addiu $t0, $t7, 1
  sw    $t0, 8($t9)
  lw    $t5, 0x28($sp)
  lw    $t2, ($t5)
  lw    $t4, ($t2)
  beqz  $t4, .L7001B7E0
   nop   
  jal   __osPopThread
   move  $a0, $t5
  move  $s1, $v0
  jal   osStartThread
   move  $a0, $s1
.L7001B7E0:
  jal   __osRestoreInt
   move  $a0, $s0
  move  $v0, $zero
.L7001B7EC:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x28

glabel osPiGetCmdQueue
  lui   $t6, %hi(__osPiDevMgr) 
  lw    $t6, %lo(__osPiDevMgr)($t6)
  bnez  $t6, .L7001B818
   nop   
  jr    $ra
   move  $v0, $zero

.L7001B818:
  lui   $v0, %hi(__osPiDevMgr.cmdQueue)
  lw    $v0, %lo(__osPiDevMgr.cmdQueue)($v0)
  jr    $ra
   nop   

  nop   
  nop

glabel ultra_7001B830
  swc1  $f12, ($sp)
  lw    $v0, ($sp)
  lwc1  $f6, ($sp)
  lwc1  $f10, ($sp)
  sra   $t6, $v0, 0x16
  andi  $t7, $t6, 0x1ff
  slti  $at, $t7, 0x136
  beql  $at, $zero, .L7001B974
   c.eq.s $f10, $f10
  mtc1  $zero, $f4
  li    $at, 0x3FE00000 # 1.750000
  mtc1  $at, $f19
  c.lt.s $f4, $f6
  lwc1  $f0, ($sp)
  lui   $at, %hi(F64_800299D8)
  bc1fl .L7001B880
   neg.s $f0, $f0
  b     .L7001B880
   mov.s $f0, $f6
  neg.s $f0, $f0
.L7001B880:
  ldc1  $f8, %lo(F64_800299D8)($at)
  cvt.d.s $f12, $f0
  mtc1  $zero, $f18
  mul.d $f10, $f12, $f8
  mtc1  $zero, $f5
  mtc1  $zero, $f4
  add.d $f14, $f10, $f18
  c.le.d $f4, $f14
  nop   
  bc1fl .L7001B8C4
   sub.d $f10, $f14, $f18
  add.d $f6, $f14, $f18
  trunc.w.d $f8, $f6
  mfc1  $v0, $f8
  b     .L7001B8D4
   mtc1  $v0, $f6
  sub.d $f10, $f14, $f18
.L7001B8C4:
  trunc.w.d $f4, $f10
  mfc1  $v0, $f4
  nop   
  mtc1  $v0, $f6
.L7001B8D4:
  lui   $at, %hi(F64_800299E0)
  ldc1  $f10, %lo(F64_800299E0)($at)
  cvt.d.w $f8, $f6
  lui   $at, %hi(F64_800299E8)
  ldc1  $f6, %lo(F64_800299E8)($at)
  lui   $v1, %hi(F64_800299B0)
  addiu $v1, %lo(F64_800299B0) # addiu $v1, $v1, -0x6650
  sub.d $f0, $f8, $f18
  andi  $t0, $v0, 1
  mul.d $f4, $f0, $f10
  ldc1  $f10, 0x20($v1)
  mul.d $f8, $f0, $f6
  ldc1  $f6, 0x18($v1)
  sub.d $f2, $f12, $f4
  sub.d $f2, $f2, $f8
  mul.d $f14, $f2, $f2
  nop   
  mul.d $f4, $f10, $f14
  add.d $f8, $f4, $f6
  ldc1  $f4, 0x10($v1)
  mul.d $f10, $f8, $f14
  add.d $f6, $f10, $f4
  ldc1  $f10, 8($v1)
  mul.d $f8, $f6, $f14
  bnez  $t0, .L7001B954
   add.d $f16, $f10, $f8
  mul.d $f4, $f2, $f14
  nop   
  mul.d $f6, $f4, $f16
  add.d $f10, $f6, $f2
  jr    $ra
   cvt.s.d $f0, $f10

.L7001B954:
  mul.d $f8, $f2, $f14
  nop   
  mul.d $f4, $f8, $f16
  add.d $f6, $f4, $f2
  cvt.s.d $f0, $f6
  jr    $ra
   neg.s $f0, $f0

  c.eq.s $f10, $f10
.L7001B974:
  lui   $at, %hi(F64_800299F0)
  bc1t  .L7001B98C
   nop   
  lui   $at, %hi(F64_80029D40)
  jr    $ra
   lwc1  $f0, %lo(F64_80029D40)($at)

.L7001B98C:
  lwc1  $f0, %lo(F64_800299F0)($at)
  jr    $ra
   nop   

  nop   
  nop   

.section .rodata
glabel F64_800299B0
.double 1.0
glabel F64_800299B8
.word 0xbfc55554, 0xbc83656d #-0.16666659550427756
glabel F64_800299C0
.double 0.008333066246082155
glabel F64_800299C8
.double -0.0001980960290193795
glabel F64_800299D0
.double 0.000002605780637968037
glabel F64_800299D8
.double 0.3183098861837907
glabel F64_800299E0
.double 3.1415926218032837
glabel F64_800299E8
.double 3.178650954705639e-8
glabel F64_800299F0
.double 0.0
                    .word 0
                    .word 0
.section .text


glabel ultra_7001B9A0
  swc1  $f12, ($sp)
  lw    $v0, ($sp)
  lwc1  $f4, ($sp)
  sra   $v1, $v0, 0x16
  andi  $t6, $v1, 0x1ff
  slti  $at, $t6, 0xff
  beqz  $at, .L7001BA20
   move  $v1, $t6
  slti  $at, $t6, 0xe6
  bnez  $at, .L7001BA18
   cvt.d.s $f2, $f4
  mul.d $f12, $f2, $f2
  lui   $v1, %hi(F64_80029A00)
  addiu $v1, %lo(F64_80029A00) # addiu $v1, $v1, -0x6600
  ldc1  $f6, 0x20($v1)
  ldc1  $f10, 0x18($v1)
  ldc1  $f4, 0x10($v1)
  mul.d $f8, $f6, $f12
  add.d $f16, $f8, $f10
  ldc1  $f10, 8($v1)
  mul.d $f18, $f16, $f12
  add.d $f6, $f18, $f4
  mul.d $f8, $f6, $f12
  add.d $f14, $f10, $f8
  mul.d $f16, $f2, $f12
  nop   
  mul.d $f18, $f16, $f14
  add.d $f4, $f18, $f2
  jr    $ra
   cvt.s.d $f0, $f4

.L7001BA18:
  jr    $ra
   lwc1  $f0, ($sp)

.L7001BA20:
  slti  $at, $v1, 0x136
  beqz  $at, .L7001BB38
   lwc1  $f4, ($sp)
  lwc1  $f6, ($sp)
  lui    $at, %hi(F64_80029A28)
  ldc1  $f10, %lo(F64_80029A28)($at)
  cvt.d.s $f2, $f6
  mtc1  $zero, $f9
  mul.d $f0, $f2, $f10
  mtc1  $zero, $f8
  li    $at, 0x3FE00000 # 1.750000
  c.le.d $f8, $f0
  nop   
  bc1fl .L7001BA84
   mtc1  $at, $f7
  li    $at, 0x3FE00000 # 1.750000
  mtc1  $at, $f17
  mtc1  $zero, $f16
  nop   
  add.d $f18, $f0, $f16
  trunc.w.d $f4, $f18
  mfc1  $v0, $f4
  b     .L7001BAA0
   mtc1  $v0, $f16
  mtc1  $at, $f7
.L7001BA84:
  mtc1  $zero, $f6
  nop   
  sub.d $f10, $f0, $f6
  trunc.w.d $f8, $f10
  mfc1  $v0, $f8
  nop   
  mtc1  $v0, $f16
.L7001BAA0:
  lui   $at, %hi(F64_80029A30)
  ldc1  $f18, %lo(F64_80029A30)($at)
  cvt.d.w $f0, $f16
  lui   $at, %hi(F64_80029A38)
  ldc1  $f6, %lo(F64_80029A38)($at)
  lui   $v1, %hi(F64_80029A00)
  addiu $v1, %lo(F64_80029A00) # addiu $v1, $v1, -0x6600
  mul.d $f4, $f0, $f18
  ldc1  $f8, 0x20($v1)
  ldc1  $f18, 0x18($v1)
  andi  $t9, $v0, 1
  mul.d $f10, $f0, $f6
  sub.d $f2, $f2, $f4
  sub.d $f2, $f2, $f10
  ldc1  $f10, 0x10($v1)
  mul.d $f12, $f2, $f2
  nop   
  mul.d $f16, $f8, $f12
  add.d $f4, $f16, $f18
  ldc1  $f18, 8($v1)
  mul.d $f6, $f4, $f12
  add.d $f8, $f6, $f10
  mul.d $f16, $f8, $f12
  bnez  $t9, .L7001BB1C
   add.d $f14, $f18, $f16
  mul.d $f4, $f2, $f12
  nop   
  mul.d $f6, $f4, $f14
  add.d $f10, $f6, $f2
  jr    $ra
   cvt.s.d $f0, $f10

.L7001BB1C:
  mul.d $f8, $f2, $f12
  nop   
  mul.d $f18, $f8, $f14
  add.d $f16, $f18, $f2
  cvt.s.d $f0, $f16
  jr    $ra
   neg.s $f0, $f0

.L7001BB38:
  c.eq.s $f4, $f4
  lui   $at, %hi(F64_80029A40)
  bc1t  .L7001BB54
   nop   
  lui   $at, %hi(F64_80029D40)
  jr    $ra
   lwc1  $f0, %lo(F64_80029D40)($at)

.L7001BB54:
  lwc1  $f0, %lo(F64_80029A40)($at)
  jr    $ra
   nop   

.section .rodata
glabel F64_80029A00
.double 1.0
glabel F64_80029A08
.double -0.16666659550427756
glabel F64_80029A10
.double 0.008333066246082155
glabel F64_80029A18
.double -0.0001980960290193795
glabel F64_80029A20
.double 0.000002605780637968037
glabel F64_80029A28
.double 0.3183098861837907
glabel F64_80029A30
.double 3.1415926218032837
glabel F64_80029A38
.double 3.178650954705639e-8
glabel F64_80029A40
.double 0.0
                    .word 0
                    .word 0
.section .text

glabel osDestroyThread
  addiu $sp, $sp, -0x38
  sw    $ra, 0x24($sp)
  sw    $a0, 0x38($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  jal   __osDisableInt
   sw    $s0, 0x18($sp)
  lw    $t6, 0x38($sp)
  move  $s0, $v0
  bnez  $t6, .L7001BB9C
   nop   
  lui   $t7, %hi(__osRunningThread) 
  lw    $t7, %lo(__osRunningThread)($t7)
  b     .L7001BBBC
   sw    $t7, 0x38($sp)
.L7001BB9C:
  lw    $t8, 0x38($sp)
  li    $at, 1
  lhu   $t9, 0x10($t8)
  beq   $t9, $at, .L7001BBBC
   nop   
  lw    $a0, 8($t8)
  jal   __osDequeueThread
   move  $a1, $t8
.L7001BBBC:
  lui   $t0, %hi(__osActiveQueue) 
  lw    $t0, %lo(__osActiveQueue)($t0)
  lw    $t1, 0x38($sp)
  bne   $t0, $t1, .L7001BBE0
   nop   
  lw    $t2, 0xc($t0)
  lui   $at, %hi(__osActiveQueue)
  b     .L7001BC1C
   sw    $t2, %lo(__osActiveQueue)($at)
.L7001BBE0:
  lui   $s1, %hi(__osActiveQueue)
  lw    $s1, %lo(__osActiveQueue)($s1)
  lw    $s2, 0xc($s1)
  beqz  $s2, .L7001BC1C
   nop   
.L7001BBF4:
  lw    $t3, 0x38($sp)
  bne   $s2, $t3, .L7001BC0C
   nop   
  lw    $t4, 0xc($t3)
  b     .L7001BC1C
   sw    $t4, 0xc($s1)
.L7001BC0C:
  move  $s1, $s2
  lw    $s2, 0xc($s1)
  bnez  $s2, .L7001BBF4
   nop   
.L7001BC1C:
  lui   $t6, %hi(__osRunningThread) 
  lw    $t6, %lo(__osRunningThread)($t6)
  lw    $t5, 0x38($sp)
  bne   $t5, $t6, .L7001BC38
   nop   
  jal   __osDispatchThread
   nop   
.L7001BC38:
  jal   __osRestoreInt
   move  $a0, $s0
  lw    $ra, 0x24($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x38

  nop   
  nop   


glabel __setInstChanState
  lw    $t6, 0x60($a0)
  sll   $v0, $a2, 4
  addu  $t7, $t6, $v0
  sw    $a1, ($t7)
  lw    $t9, 0x60($a0)
  lbu   $t8, 1($a1)
  addu  $t0, $t9, $v0
  sb    $t8, 7($t0)
  lw    $t2, 0x60($a0)
  lbu   $t1, ($a1)
  addu  $t3, $t2, $v0
  sb    $t1, 9($t3)
  lw    $t5, 0x60($a0)
  lbu   $t4, 2($a1)
  addu  $t6, $t5, $v0
  sb    $t4, 8($t6)
  lw    $t9, 0x60($a0)
  lh    $t7, 0xc($a1)
  addu  $t8, $t9, $v0
  jr    $ra
   sh    $t7, 4($t8)

glabel __resetPerfChanState
  lw    $t6, 0x60($a0)
  sll   $v0, $a1, 4
  li    $t0, 64
  addu  $t7, $t6, $v0
  sb    $zero, 6($t7)
  lw    $t8, 0x60($a0)
  li    $t3, 127
  li    $t6, 5
  addu  $t9, $t8, $v0
  sb    $zero, 0xa($t9)
  lw    $t1, 0x60($a0)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  addu  $t2, $t1, $v0
  sb    $t0, 7($t2)
  lw    $t4, 0x60($a0)
  li    $t0, 200
  addu  $t5, $t4, $v0
  sb    $t3, 9($t5)
  lw    $t7, 0x60($a0)
  addu  $t8, $t7, $v0
  sb    $t6, 8($t8)
  lw    $t9, 0x60($a0)
  addu  $t1, $t9, $v0
  sb    $zero, 0xb($t1)
  lw    $t2, 0x60($a0)
  addu  $t4, $t2, $v0
  sh    $t0, 4($t4)
  lw    $t3, 0x60($a0)
  addu  $t5, $t3, $v0
  jr    $ra
   swc1  $f4, 0xc($t5)

glabel __initFromBank
  addiu $sp, $sp, -0x28
  sw    $s2, 0x20($sp)
  move  $s2, $a0
  sw    $ra, 0x24($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a1, 0x2c($sp)
  move  $v0, $a1
  lw    $s1, 0xc($v0)
.L7001BD58:
  addiu $v0, $v0, 4
  beql  $s1, $zero, .L7001BD58
   lw    $s1, 0xc($v0)
  lbu   $t6, 0x34($s2)
  move  $s0, $zero
  blez  $t6, .L7001BDA0
   move  $a0, $s2
.L7001BD74:
  jal   __resetPerfChanState
   move  $a1, $s0
  move  $a0, $s2
  move  $a1, $s1
  jal   __setInstChanState
   move  $a2, $s0
  lbu   $t7, 0x34($s2)
  addiu $s0, $s0, 1
  slt   $at, $s0, $t7
  bnezl $at, .L7001BD74
   move  $a0, $s2
.L7001BDA0:
  lw    $t8, 0x2c($sp)
  move  $a0, $s2
  lw    $t9, 8($t8)
  beql  $t9, $zero, .L7001BDD4
   lw    $ra, 0x24($sp)
  jal   __resetPerfChanState
   move  $a1, $s0
  lw    $t0, 0x2c($sp)
  move  $a0, $s2
  li    $a2, 9
  jal   __setInstChanState
   lw    $a1, 8($t0)
  lw    $ra, 0x24($sp)
.L7001BDD4:
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28

  jr    $ra
   nop   

glabel __vsDelta
  lw    $t6, 0x24($a0)
  li    $v0, 1000
  subu  $v1, $t6, $a1
  bltz  $v1, .L7001BE0C
   nop   
  jr    $ra
   move  $v0, $v1

.L7001BE0C:
  jr    $ra
   nop   

glabel __vsVol
  lbu   $t6, 0x36($a0)
  lbu   $t7, 0x33($a0)
  lbu   $t9, 0x30($a0)
  lbu   $t2, 0x31($a0)
  multu $t6, $t7
  lw    $t1, 0x60($a1)
  lw    $t6, 0x20($a0)
  sll   $t3, $t2, 4
  addu  $t4, $t1, $t3
  lbu   $t5, 9($t4)
  lbu   $t7, 0xd($t6)
  mflo  $t8
  nop   
  nop   
  multu $t8, $t9
  lh    $t9, 0x32($a1)
  mflo  $v1
  sra   $t0, $v1, 6
  move  $v1, $t0
  multu $t5, $t7
  mflo  $t8
  nop   
  nop   
  multu $t8, $t9
  mflo  $a2
  sra   $t0, $a2, 0xe
  nop   
  multu $v1, $t0
  mflo  $v1
  srl   $t2, $v1, 0xf
  sll   $v0, $t2, 0x10
  sra   $t1, $v0, 0x10
  jr    $ra
   move  $v0, $t1

glabel __seqpReleaseVoice
  addiu $sp, $sp, -0x60
  sw    $ra, 0x34($sp)
  sw    $s6, 0x30($sp)
  sw    $s5, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a2, 0x68($sp)
  lw    $s6, 0x10($a1)
  move  $s4, $a0
  move  $s5, $a1
  lbu   $t6, 0x34($s6)
  bnezl $t6, .L7001BF40
   li    $t2, 3
  lw    $s0, 0x50($a0)
  li    $s3, 6
  beql  $s0, $zero, .L7001BF40
   li    $t2, 3
.L7001BEEC:
  lh    $t7, 0xc($s0)
  lw    $s1, ($s0)
  bne   $s3, $t7, .L7001BF34
   nop   
  lw    $t8, 0x10($s0)
  bne   $s5, $t8, .L7001BF34
   nop   
  beqz  $s1, .L7001BF20
   addiu $s2, $s4, 0x48
  lw    $t9, 8($s1)
  lw    $t0, 8($s0)
  addu  $t1, $t9, $t0
  sw    $t1, 8($s1)
.L7001BF20:
  jal   alUnlink
   move  $a0, $s0
  move  $a0, $s0
  jal   alLink
   move  $a1, $s2
.L7001BF34:
  bnez  $s1, .L7001BEEC
   move  $s0, $s1
  li    $t2, 3
.L7001BF40:
  sb    $zero, 0x33($s6)
  sb    $t2, 0x34($s6)
  sb    $zero, 0x30($s6)
  lw    $t4, 0x68($sp)
  lw    $t3, 0x1c($s4)
  move  $a1, $s5
  move  $a2, $zero
  addu  $t5, $t3, $t4
  sw    $t5, 0x24($s6)
  lw    $a0, 0x14($s4)
  jal   alSynSetPriority
   addiu $s2, $s4, 0x48
  lw    $a0, 0x14($s4)
  move  $a1, $s5
  move  $a2, $zero
  jal   alSynSetVol
   lw    $a3, 0x68($sp)
  li    $t6, 5
  sh    $t6, 0x50($sp)
  sw    $s5, 0x54($sp)
  move  $a0, $s2
  addiu $a1, $sp, 0x50
  jal   alEvtqPostEvent
   lw    $a2, 0x68($sp)
  lw    $ra, 0x34($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  lw    $s3, 0x24($sp)
  lw    $s4, 0x28($sp)
  lw    $s5, 0x2c($sp)
  lw    $s6, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x60

glabel __voiceNeedsNoteKill
  addiu $sp, $sp, -0x30
  sw    $ra, 0x14($sp)
  lw    $a3, 0x50($a0)
  move  $t2, $a0
  move  $t0, $zero
  beqz  $a3, .L7001C05C
   li    $t1, 1
  li    $a0, 5
.L7001BFE8:
  lh    $t6, 0xc($a3)
  lw    $v1, 8($a3)
  lw    $v0, ($a3)
  bne   $a0, $t6, .L7001C054
   addu  $t0, $t0, $v1
  lw    $t7, 0x10($a3)
  bne   $a1, $t7, .L7001C054
   slt   $at, $a2, $t0
  beqz  $at, .L7001C04C
   move  $a0, $a3
  beql  $v0, $zero, .L7001C028
   sw    $a3, 0x2c($sp)
  lw    $t8, 8($v0)
  addu  $t9, $t8, $v1
  sw    $t9, 8($v0)
  sw    $a3, 0x2c($sp)
.L7001C028:
  sb    $t1, 0x1f($sp)
  jal   alUnlink
   sw    $t2, 0x30($sp)
  lw    $t2, 0x30($sp)
  lw    $a0, 0x2c($sp)
  jal   alLink
   addiu $a1, $t2, 0x48
  b     .L7001C05C
   lbu   $t1, 0x1f($sp)
.L7001C04C:
  b     .L7001C05C
   move  $t1, $zero
.L7001C054:
  bnez  $v0, .L7001BFE8
   move  $a3, $v0
.L7001C05C:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x30
  move  $v0, $t1
  jr    $ra
   nop   

glabel __unmapVoice
  lw    $v1, 0x64($a0)
  move  $v0, $zero
  addiu $a2, $a1, -4
  beqz  $v1, .L7001C0D8
   nop   
.L7001C084:
  bnel  $v1, $a2, .L7001C0CC
   move  $v0, $v1
  beql  $v0, $zero, .L7001C0A4
   lw    $t7, ($v1)
  lw    $t6, ($v1)
  b     .L7001C0A8
   sw    $t6, ($v0)
  lw    $t7, ($v1)
.L7001C0A4:
  sw    $t7, 0x64($a0)
.L7001C0A8:
  lw    $t8, 0x68($a0)
  bnel  $v1, $t8, .L7001C0BC
   lw    $t9, 0x6c($a0)
  sw    $v0, 0x68($a0)
  lw    $t9, 0x6c($a0)
.L7001C0BC:
  sw    $t9, ($v1)
  jr    $ra
   sw    $v1, 0x6c($a0)

  move  $v0, $v1
.L7001C0CC:
  lw    $v1, ($v1)
  bnez  $v1, .L7001C084
   nop   
.L7001C0D8:
  jr    $ra
   nop   

glabel __postNextSeqEvent
  addiu $sp, $sp, -0x38
  sw    $ra, 0x14($sp)
  lw    $t6, 0x2c($a0)
  li    $at, 1
  move  $a3, $a0
  bne   $t6, $at, .L7001C1AC
   lw    $a2, 0x18($a0)
  beqz  $a2, .L7001C1AC
   move  $a0, $a2
  addiu $a1, $sp, 0x24
  sw    $a2, 0x20($sp)
  jal   __alSeqNextDelta
   sw    $a3, 0x38($sp)
  lw    $a2, 0x20($sp)
  beqz  $v0, .L7001C1AC
   lw    $a3, 0x38($sp)
  lw    $t7, 0x84($a3)
  move  $a0, $a2
  beql  $t7, $zero, .L7001C18C
   sh    $zero, 0x28($sp)
  sw    $a2, 0x20($sp)
  jal   alSeqGetTicks
   sw    $a3, 0x38($sp)
  lw    $a3, 0x38($sp)
  lw    $t8, 0x24($sp)
  lw    $a2, 0x20($sp)
  lw    $t0, 0x80($a3)
  addu  $t9, $v0, $t8
  move  $a0, $a2
  lw    $t1, 8($t0)
  slt   $at, $t9, $t1
  bnezl $at, .L7001C18C
   sh    $zero, 0x28($sp)
  lw    $a1, 0x7c($a3)
  jal   alSeqSetLoc
   sw    $a3, 0x38($sp)
  lw    $a3, 0x38($sp)
  li    $at, -1
  lw    $v0, 0x84($a3)
  beq   $v0, $at, .L7001C188
   addiu $t2, $v0, -1
  sw    $t2, 0x84($a3)
.L7001C188:
  sh    $zero, 0x28($sp)
.L7001C18C:
  lw    $t3, 0x24($a3)
  lw    $t4, 0x24($sp)
  addiu $a0, $a3, 0x48
  addiu $a1, $sp, 0x28
  multu $t3, $t4
  mflo  $a2
  jal   alEvtqPostEvent
   nop   
.L7001C1AC:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   

glabel __handleMetaMsg
  lbu   $t6, 8($a0)
  li    $at, 255
  bne   $t6, $at, .L7001C22C
   nop   
  lbu   $t7, 9($a0)
  li    $at, 81
  addiu $v0, $a0, 4
  bne   $t7, $at, .L7001C22C
   nop   
  lbu   $t6, 8($v0)
  lbu   $t8, 7($v0)
  lw    $a2, 0x18($a1)
  sll   $t7, $t6, 8
  lbu   $t6, 9($v0)
  sll   $t9, $t8, 0x10
  or    $t8, $t9, $t7
  or    $v1, $t8, $t6
  mtc1  $v1, $f4
  li    $t8, 488
  beqz  $a2, .L7001C228
   cvt.s.w $f0, $f4
  lwc1  $f6, 0x14($a2)
  mul.s $f8, $f0, $f6
  trunc.w.s $f10, $f8
  mfc1  $t7, $f10
  jr    $ra
   sw    $t7, 0x24($a1)

.L7001C228:
  sw    $t8, 0x24($a1)
.L7001C22C:
  jr    $ra
   nop   

glabel __vsPan
  lbu   $t7, 0x31($a0)
  lw    $t6, 0x60($a1)
  lw    $t1, 0x20($a0)
  sll   $t8, $t7, 4
  addu  $t9, $t6, $t8
  lbu   $t0, 7($t9)
  lbu   $t2, 0xc($t1)
  addu  $v1, $t0, $t2
  addiu $v1, $v1, -0x40
  bgtzl $v1, .L7001C268
   slti  $at, $v1, 0x7f
  move  $v1, $zero
  slti  $at, $v1, 0x7f
.L7001C268:
  bnez  $at, .L7001C274
   nop   
  li    $v1, 127
.L7001C274:
  jr    $ra
   andi  $v0, $v1, 0xff

glabel __lookupVoice
  sw    $a1, 4($sp)
  sw    $a2, 8($sp)
  lw    $v1, 0x64($a0)
  andi  $t7, $a2, 0xff
  move  $a2, $t7
  beqz  $v1, .L7001C2E4
   andi  $t6, $a1, 0xff
  move  $v0, $t6
  li    $a3, 4
  li    $a1, 3
  lbu   $t8, 0x32($v1)
.L7001C2A8:
  bnel  $v0, $t8, .L7001C2DC
   lw    $v1, ($v1)
  lbu   $t9, 0x31($v1)
  bnel  $a2, $t9, .L7001C2DC
   lw    $v1, ($v1)
  lbu   $a0, 0x35($v1)
  beql  $a1, $a0, .L7001C2DC
   lw    $v1, ($v1)
  beql  $a3, $a0, .L7001C2DC
   lw    $v1, ($v1)
  jr    $ra
   move  $v0, $v1

  lw    $v1, ($v1)
.L7001C2DC:
  bnezl $v1, .L7001C2A8
   lbu   $t8, 0x32($v1)
.L7001C2E4:
  move  $v0, $zero
  jr    $ra
   nop   

glabel __mapVoice
  sw    $a1, 4($sp)
  sw    $a2, 8($sp)
  sw    $a3, 0xc($sp)
  lw    $v1, 0x6c($a0)
  andi  $t6, $a1, 0xff
  andi  $t7, $a2, 0xff
  andi  $t8, $a3, 0xff
  move  $a3, $t8
  move  $a2, $t7
  beqz  $v1, .L7001C358
   move  $a1, $t6
  lw    $t9, ($v1)
  sw    $t9, 0x6c($a0)
  sw    $zero, ($v1)
  lw    $t0, 0x64($a0)
  bnezl $t0, .L7001C340
   lw    $t1, 0x68($a0)
  b     .L7001C344
   sw    $v1, 0x64($a0)
  lw    $t1, 0x68($a0)
.L7001C340:
  sw    $v1, ($t1)
.L7001C344:
  sw    $v1, 0x68($a0)
  sb    $a3, 0x31($v1)
  sb    $a1, 0x32($v1)
  sb    $a2, 0x33($v1)
  sw    $v1, 0x14($v1)
.L7001C358:
  jr    $ra
   move  $v0, $v1

glabel __lookupSoundQuick
  sw    $a1, 4($sp)
  sw    $a2, 8($sp)
  sw    $a3, 0xc($sp)
  lw    $t8, 0x60($a0)
  andi  $t7, $a3, 0xff
  sll   $t9, $t7, 4
  addu  $t4, $t8, $t9
  lw    $v0, ($t4)
  andi  $t6, $a1, 0xff
  andi  $t3, $a2, 0xff
  lh    $t0, 0xe($v0)
  li    $v1, 1
  move  $t1, $t6
  blez  $t0, .L7001C450
   addu  $a1, $v1, $t0
.L7001C39C:
  bgez  $a1, .L7001C3AC
   sra   $t5, $a1, 1
  addiu $at, $a1, 1
  sra   $t5, $at, 1
.L7001C3AC:
  sll   $t6, $t5, 2
  addu  $t7, $v0, $t6
  lw    $a3, 0xc($t7)
  move  $a0, $t5
  lw    $a2, 4($a3)
  lbu   $t2, 2($a2)
  slt   $at, $t1, $t2
  bnezl $at, .L7001C410
   slt   $at, $t1, $t2
  lbu   $t8, 3($a2)
  slt   $at, $t8, $t1
  bnezl $at, .L7001C410
   slt   $at, $t1, $t2
  lbu   $t9, ($a2)
  move  $a1, $t3
  slt   $at, $t3, $t9
  bnezl $at, .L7001C410
   slt   $at, $t1, $t2
  lbu   $t4, 1($a2)
  slt   $at, $t4, $a1
  bnezl $at, .L7001C410
   slt   $at, $t1, $t2
  jr    $ra
   move  $v0, $a3

  slt   $at, $t1, $t2
.L7001C410:
  bnez  $at, .L7001C438
   nop   
  lbu   $t5, ($a2)
  slt   $at, $t3, $t5
  beql  $at, $zero, .L7001C444
   addiu $v1, $a0, 1
  lbu   $t6, 3($a2)
  slt   $at, $t6, $t1
  bnezl $at, .L7001C444
   addiu $v1, $a0, 1
.L7001C438:
  b     .L7001C444
   addiu $t0, $a0, -1
  addiu $v1, $a0, 1
.L7001C444:
  slt   $at, $t0, $v1
  beql  $at, $zero, .L7001C39C
   addu  $a1, $v1, $t0
.L7001C450:
  move  $v0, $zero
  jr    $ra
   nop   

glabel __handleMIDIMsg
  addiu $sp, $sp, -0xe0
  sw    $ra, 0x24($sp)
  lbu   $s6, 8($a0)
  lbu   $s3, 9($a0)
  lbu   $s4, 0xa($a0)
  andi  $v1, $s6, 0xf0
  addiu $t7, $v1, -0x80
  sltiu $at, $t7, 0x61
  andi  $t6, $s6, 0xf
  beqz  $at, .L7001CC64
   move  $s6, $t6
  sll   $t7, $t7, 2
  lui   $at, %hi(jpt_80029A50)
  addu  $at, $at, $t7
  lw    $t7, %lo(jpt_80029A50)($at)
  jr    $t7
   nop   
.L7001C4A0:
  beql  $s4, $zero, .L7001C7F8
   move  $a0, $s1
  lw    $t8, 0x2c($s1)
  li    $at, 1
  move  $a0, $s1
  bne   $t8, $at, .L7001CC64
   andi  $a1, $s3, 0xff
  andi  $a2, $s4, 0xff
  jal   __lookupSoundQuick
   andi  $a3, $s6, 0xff
  beqz  $v0, .L7001CC64
   move  $s7, $v0
  lw    $t9, 0x60($s1)
  sll   $fp, $s6, 4
  move  $a0, $s1
  addu  $t6, $t9, $fp
  lbu   $t7, 8($t6)
  sh    $zero, 0x9e($sp)
  sb    $zero, 0xa0($sp)
  andi  $a1, $s3, 0xff
  andi  $a2, $s4, 0xff
  andi  $a3, $s6, 0xff
  jal   __mapVoice
   sh    $t7, 0x9c($sp)
  beqz  $v0, .L7001CC64
   move  $s0, $v0
  lw    $a0, 0x14($s1)
  addiu $a1, $v0, 4
  sw    $a1, 0x34($sp)
  jal   alSynAllocVoice
   addiu $a2, $sp, 0x9c
  sw    $s7, 0x20($s0)
  sb    $zero, 0x34($s0)
  lw    $t8, 0x60($s1)
  li    $s5, 2
  addu  $t9, $t8, $fp
  lbu   $t6, 0xb($t9)
  slti  $at, $t6, 0x40
  bnezl $at, .L7001C54C
   sb    $zero, 0x35($s0)
  b     .L7001C54C
   sb    $s5, 0x35($s0)
  sb    $zero, 0x35($s0)
.L7001C54C:
  lw    $v0, 4($s7)
  lbu   $t7, 4($v0)
  lb    $t6, 5($v0)
  subu  $t8, $s3, $t7
  sll   $t9, $t8, 2
  subu  $t9, $t9, $t8
  sll   $t9, $t9, 3
  addu  $t9, $t9, $t8
  sll   $t9, $t9, 2
  addu  $a0, $t9, $t6
  sll   $t7, $a0, 0x10
  jal   alCents2Ratio
   sra   $a0, $t7, 0x10
  swc1  $f0, 0x28($s0)
  lw    $t9, ($s7)
  li    $at, 0x42FE0000 # 127.000000
  mtc1  $at, $f4
  lbu   $t6, 0xc($t9)
  sb    $t6, 0x30($s0)
  lw    $t8, ($s7)
  lw    $t7, 0x1c($s1)
  lw    $t9, ($t8)
  sb    $zero, 0x37($s0)
  addu  $t6, $t7, $t9
  sw    $t6, 0x24($s0)
  lw    $t8, 0x60($s1)
  addu  $t7, $t8, $fp
  lw    $s2, ($t7)
  swc1  $f4, 0x8c($sp)
  lbu   $a2, 4($s2)
  beql  $a2, $zero, .L7001C630
   cfc1  $t8, $31
  lw    $v0, 0x70($s1)
  beql  $v0, $zero, .L7001C630
   cfc1  $t8, $31
  lbu   $t9, 6($s2)
  lbu   $a3, 5($s2)
  addiu $a0, $sp, 0x84
  sw    $t9, 0x10($sp)
  lbu   $t6, 7($s2)
  addiu $a1, $sp, 0x8c
  jalr  $v0
  sw    $t6, 0x14($sp)
  beqz  $v0, .L7001C62C
   li    $t8, 22
  lw    $t7, 0x84($sp)
  sh    $t8, 0xb4($sp)
  sw    $s0, 0xb8($sp)
  addiu $a0, $s1, 0x48
  addiu $a1, $sp, 0xb4
  move  $a2, $v0
  jal   alEvtqPostEvent
   sw    $t7, 0xbc($sp)
  lbu   $t9, 0x37($s0)
  ori   $t6, $t9, 1
  sb    $t6, 0x37($s0)
.L7001C62C:
  cfc1  $t8, $31
.L7001C630:
  li    $t7, 1
  ctc1  $t7, $31
  lwc1  $f6, 0x8c($sp)
  li    $at, 0x4F000000 # 2147483648.000000
  cvt.w.s $f8, $f6
  cfc1  $t7, $31
  nop   
  andi  $t7, $t7, 0x78
  beql  $t7, $zero, .L7001C6A0
   mfc1  $t7, $f8
  mtc1  $at, $f8
  li    $t7, 1
  sub.s $f8, $f6, $f8
  ctc1  $t7, $31
  nop   
  cvt.w.s $f8, $f8
  cfc1  $t7, $31
  nop   
  andi  $t7, $t7, 0x78
  bnez  $t7, .L7001C694
   nop   
  mfc1  $t7, $f8
  lui   $at, 0x8000
  b     .L7001C6AC
   or    $t7, $t7, $at
.L7001C694:
  b     .L7001C6AC
   li    $t7, -1
  mfc1  $t7, $f8
.L7001C6A0:
  nop   
  bltz  $t7, .L7001C694
   nop   
.L7001C6AC:
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  sb    $t7, 0x36($s0)
  ctc1  $t8, $31
  swc1  $f10, 0x8c($sp)
  lbu   $a2, 8($s2)
  addiu $s5, $s1, 0x48
  beql  $a2, $zero, .L7001C738
   lwc1  $f4, 0x8c($sp)
  lw    $v0, 0x70($s1)
  beql  $v0, $zero, .L7001C738
   lwc1  $f4, 0x8c($sp)
  lbu   $t9, 0xa($s2)
  lbu   $a3, 9($s2)
  addiu $a0, $sp, 0x84
  sw    $t9, 0x10($sp)
  lbu   $t6, 0xb($s2)
  addiu $a1, $sp, 0x8c
  jalr  $v0
  sw    $t6, 0x14($sp)
  beqz  $v0, .L7001C734
   li    $t8, 23
  lw    $t7, 0x84($sp)
  sh    $t8, 0xb4($sp)
  sw    $s0, 0xb8($sp)
  sb    $s6, 0xc0($sp)
  move  $a0, $s5
  addiu $a1, $sp, 0xb4
  move  $a2, $v0
  jal   alEvtqPostEvent
   sw    $t7, 0xbc($sp)
  lbu   $t9, 0x37($s0)
  ori   $t6, $t9, 2
  sb    $t6, 0x37($s0)
.L7001C734:
  lwc1  $f4, 0x8c($sp)
.L7001C738:
  lwc1  $f8, 0x28($s0)
  move  $a0, $s0
  swc1  $f4, 0x2c($s0)
  lw    $t8, 0x60($s1)
  lwc1  $f4, 0x2c($s0)
  move  $a1, $s1
  addu  $v0, $t8, $fp
  lwc1  $f6, 0xc($v0)
  lbu   $s2, 0xa($v0)
  mul.s $f10, $f6, $f8
  nop   
  mul.s $f20, $f10, $f4
  jal   __vsPan
   nop   
  andi  $s4, $v0, 0xff
  move  $a0, $s0
  jal   __vsVol
   move  $a1, $s1
  lw    $t7, ($s7)
  lw    $a0, 0x14($s1)
  lw    $a2, 8($s7)
  lw    $s3, ($t7)
  mfc1  $a3, $f20
  sw    $s2, 0x18($sp)
  sw    $s4, 0x14($sp)
  sw    $v0, 0x10($sp)
  lw    $a1, 0x34($sp)
  jal   alSynStartVoiceParams
   sw    $s3, 0x1c($sp)
  lw    $t6, 0x34($sp)
  li    $t9, 6
  sh    $t9, 0xb4($sp)
  sw    $t6, 0xb8($sp)
  lw    $t8, ($s7)
  move  $a0, $s5
  addiu $a1, $sp, 0xb4
  lbu   $t7, 0xd($t8)
  sb    $t7, 0xc0($sp)
  lw    $t9, ($s7)
  lw    $t6, 4($t9)
  sw    $t6, 0xbc($sp)
  lw    $t8, ($s7)
  lw    $s3, ($t8)
  jal   alEvtqPostEvent
   move  $a2, $s3
  b     .L7001CC68
   lw    $ra, 0x24($sp)
.L7001C7F4:
  move  $a0, $s1
.L7001C7F8:
  andi  $a1, $s3, 0xff
  jal   __lookupVoice
   andi  $a2, $s6, 0xff
  beqz  $v0, .L7001CC64
   move  $s0, $v0
  lbu   $t7, 0x35($v0)
  li    $s6, 2
  li    $t9, 4
  bne   $s6, $t7, .L7001C828
   move  $a0, $s1
  b     .L7001CC64
   sb    $t9, 0x35($v0)
.L7001C828:
  lw    $t6, 0x20($s0)
  li    $fp, 3
  sb    $fp, 0x35($s0)
  lw    $t8, ($t6)
  addiu $a1, $s0, 4
  jal   __seqpReleaseVoice
   lw    $a2, 8($t8)
  b     .L7001CC68
   lw    $ra, 0x24($sp)
.L7001C84C:
  move  $a0, $s1
  andi  $a1, $s3, 0xff
  jal   __lookupVoice
   andi  $a2, $s6, 0xff
  beqz  $v0, .L7001CC64
   move  $s0, $v0
  sb    $s4, 0x33($v0)
  move  $a0, $v0
  jal   __vsVol
   move  $a1, $s1
  lw    $v1, 0x1c($s1)
  lw    $t9, 0x24($s0)
  sll   $a2, $v0, 0x10
  sra   $t7, $a2, 0x10
  subu  $a0, $t9, $v1
  bltz  $a0, .L7001C898
   move  $a2, $t7
  b     .L7001C89C
   move  $v0, $a0
.L7001C898:
  li    $v0, 1000
.L7001C89C:
  lw    $a0, 0x14($s1)
  addiu $a1, $s0, 4
  jal   alSynSetVol
   move  $a3, $v0
  b     .L7001CC68
   lw    $ra, 0x24($sp)
.L7001C8B4:
  lw    $s0, 0x64($s1)
  beql  $s0, $zero, .L7001CC68
   lw    $ra, 0x24($sp)
  move  $s2, $s6
  lbu   $t6, 0x31($s0)
.L7001C8C8:
  move  $a0, $s0
  move  $a1, $s1
  bnel  $s2, $t6, .L7001C91C
   lw    $s0, ($s0)
  jal   __vsVol
   sb    $s3, 0x33($s0)
  lw    $v1, 0x1c($s1)
  lw    $t7, 0x24($s0)
  sll   $a2, $v0, 0x10
  sra   $t8, $a2, 0x10
  subu  $a0, $t7, $v1
  bltz  $a0, .L7001C904
   move  $a2, $t8
  b     .L7001C908
   move  $v0, $a0
.L7001C904:
  li    $v0, 1000
.L7001C908:
  lw    $a0, 0x14($s1)
  addiu $a1, $s0, 4
  jal   alSynSetVol
   move  $a3, $v0
  lw    $s0, ($s0)
.L7001C91C:
  bnezl $s0, .L7001C8C8
   lbu   $t6, 0x31($s0)
  b     .L7001CC68
   lw    $ra, 0x24($sp)
.L7001C92C:
  slti  $at, $s3, 0x41
  bnez  $at, .L7001C954
   move  $v0, $s3
  li    $at, 91
  beq   $v0, $at, .L7001CB48
   li    $at, 93
  beql  $v0, $at, .L7001CC68
   lw    $ra, 0x24($sp)
  b     .L7001CC68
   lw    $ra, 0x24($sp)
.L7001C954:
  slti  $at, $v0, 0x1c
  bnez  $at, .L7001C974
   addiu $t9, $v0, -7
  li    $at, 64
  beql  $v0, $at, .L7001CA9C
   lw    $t7, 0x60($s1)
  b     .L7001CC68
   lw    $ra, 0x24($sp)
.L7001C974:
  sltiu $at, $t9, 0x15
  beqz  $at, .L7001CC64
   sll   $t9, $t9, 2
  lui   $at, %hi(jpt_80029BD4)
  addu  $at, $at, $t9
  lw    $t9, %lo(jpt_80029BD4)($at)
  jr    $t9
   nop   
.L7001C994:
  lw    $t6, 0x60($s1)
  sll   $t8, $s6, 4
  addu  $t7, $t6, $t8
  sb    $s4, 7($t7)
  lw    $s0, 0x64($s1)
  beql  $s0, $zero, .L7001CC68
   lw    $ra, 0x24($sp)
  move  $s2, $s6
  lbu   $t9, 0x31($s0)
.L7001C9B8:
  move  $a0, $s0
  bnel  $s2, $t9, .L7001C9E0
   lw    $s0, ($s0)
  jal   __vsPan
   move  $a1, $s1
  lw    $a0, 0x14($s1)
  addiu $a1, $s0, 4
  jal   alSynSetPan
   andi  $a2, $v0, 0xff
  lw    $s0, ($s0)
.L7001C9E0:
  bnezl $s0, .L7001C9B8
   lbu   $t9, 0x31($s0)
  b     .L7001CC68
   lw    $ra, 0x24($sp)
.L7001C9F0:
  lw    $t6, 0x60($s1)
  sll   $t8, $s6, 4
  addu  $t7, $t6, $t8
  sb    $s4, 9($t7)
  lw    $s0, 0x64($s1)
  beql  $s0, $zero, .L7001CC68
   lw    $ra, 0x24($sp)
  move  $s2, $s6
  li    $s3, 3
  lbu   $t9, 0x31($s0)
.L7001CA18:
  bnel  $s2, $t9, .L7001CA74
   lw    $s0, ($s0)
  lbu   $t6, 0x34($s0)
  move  $a0, $s0
  beql  $s3, $t6, .L7001CA74
   lw    $s0, ($s0)
  jal   __vsVol
   move  $a1, $s1
  lw    $v1, 0x1c($s1)
  lw    $t7, 0x24($s0)
  sll   $a2, $v0, 0x10
  sra   $t8, $a2, 0x10
  subu  $a0, $t7, $v1
  bltz  $a0, .L7001CA5C
   move  $a2, $t8
  b     .L7001CA60
   move  $v0, $a0
.L7001CA5C:
  li    $v0, 1000
.L7001CA60:
  lw    $a0, 0x14($s1)
  addiu $a1, $s0, 4
  jal   alSynSetVol
   move  $a3, $v0
  lw    $s0, ($s0)
.L7001CA74:
  bnezl $s0, .L7001CA18
   lbu   $t9, 0x31($s0)
  b     .L7001CC68
   lw    $ra, 0x24($sp)
.L7001CA84:
  lw    $t9, 0x60($s1)
  sll   $t6, $s6, 4
  addu  $t8, $t9, $t6
  b     .L7001CC64
   sb    $s4, 8($t8)
  lw    $t7, 0x60($s1)
.L7001CA9C:
  sll   $t9, $s6, 4
  addu  $t6, $t7, $t9
  sb    $s4, 0xb($t6)
  lw    $s0, 0x64($s1)
  beql  $s0, $zero, .L7001CC68
   lw    $ra, 0x24($sp)
  move  $s2, $s6
  li    $s6, 2
  li    $fp, 3
  li    $s7, 4
  li    $s5, 2
  li    $s3, 3
  lbu   $t8, 0x31($s0)
.L7001CAD0:
  bnel  $s2, $t8, .L7001CB38
   lw    $s0, ($s0)
  lbu   $v0, 0x35($s0)
  slti  $at, $s4, 0x40
  beql  $s3, $v0, .L7001CB38
   lw    $s0, ($s0)
  bnez  $at, .L7001CB00
   nop   
  bnezl $v0, .L7001CB38
   lw    $s0, ($s0)
  b     .L7001CB34
   sb    $s5, 0x35($s0)
.L7001CB00:
  bne   $s6, $v0, .L7001CB10
   nop   
  b     .L7001CB34
   sb    $zero, 0x35($s0)
.L7001CB10:
  bnel  $s7, $v0, .L7001CB38
   lw    $s0, ($s0)
  lw    $t7, 0x20($s0)
  sb    $fp, 0x35($s0)
  move  $a0, $s1
  lw    $t9, ($t7)
  addiu $a1, $s0, 4
  jal   __seqpReleaseVoice
   lw    $a2, 8($t9)
.L7001CB34:
  lw    $s0, ($s0)
.L7001CB38:
  bnezl $s0, .L7001CAD0
   lbu   $t8, 0x31($s0)
  b     .L7001CC68
   lw    $ra, 0x24($sp)
.L7001CB48:
  lw    $t6, 0x60($s1)
  sll   $t8, $s6, 4
  addu  $t7, $t6, $t8
  sb    $s4, 0xa($t7)
  lw    $s0, 0x64($s1)
  beql  $s0, $zero, .L7001CC68
   lw    $ra, 0x24($sp)
  move  $s2, $s6
  lbu   $t9, 0x31($s0)
.L7001CB6C:
  addiu $a1, $s0, 4
  andi  $a2, $s4, 0xff
  bnel  $s2, $t9, .L7001CB88
   lw    $s0, ($s0)
  jal   alSynSetFXMix
   lw    $a0, 0x14($s1)
  lw    $s0, ($s0)
.L7001CB88:
  bnezl $s0, .L7001CB6C
   lbu   $t9, 0x31($s0)
  b     .L7001CC68
   lw    $ra, 0x24($sp)
.L7001CB98:
  lw    $v0, 0x20($s1)
  sll   $t8, $s3, 2
  move  $a0, $s1
  lh    $t6, ($v0)
  move  $a2, $s6
  addu  $t7, $v0, $t8
  slt   $at, $s3, $t6
  beql  $at, $zero, .L7001CC68
   lw    $ra, 0x24($sp)
  jal   __setInstChanState
   lw    $a1, 0xc($t7)
  b     .L7001CC68
   lw    $ra, 0x24($sp)
.L7001CBCC:
  lw    $t9, 0x60($s1)
  sll   $fp, $s6, 4
  sll   $t7, $s4, 7
  addu  $t6, $t9, $fp
  lh    $t8, 4($t6)
  addu  $t9, $t7, $s3
  addiu $t6, $t9, -0x2000
  multu $t8, $t6
  mflo  $a0
  bgez  $a0, .L7001CC00
   sra   $t7, $a0, 0xd
  addiu $at, $a0, 0x1fff
  sra   $t7, $at, 0xd
.L7001CC00:
  jal   alCents2Ratio
   move  $a0, $t7
  lw    $t9, 0x60($s1)
  mov.s $f20, $f0
  addu  $t8, $t9, $fp
  swc1  $f0, 0xc($t8)
  lw    $s0, 0x64($s1)
  beql  $s0, $zero, .L7001CC68
   lw    $ra, 0x24($sp)
  move  $s2, $s6
  lbu   $t6, 0x31($s0)
.L7001CC2C:
  bnel  $s2, $t6, .L7001CC5C
   lw    $s0, ($s0)
  lwc1  $f6, 0x28($s0)
  lwc1  $f10, 0x2c($s0)
  lw    $a0, 0x14($s1)
  mul.s $f8, $f6, $f20
  addiu $a1, $s0, 4
  mul.s $f4, $f8, $f10
  mfc1  $a2, $f4
  jal   alSynSetPitch
   nop   
  lw    $s0, ($s0)
.L7001CC5C:
  bnezl $s0, .L7001CC2C
   lbu   $t6, 0x31($s0)
.L7001CC64:
  lw    $ra, 0x24($sp)
.L7001CC68:
  addiu $sp, $sp, 0xe0
  jr    $ra
   nop   

  jr    $ra
   nop   

glabel __seqpVoiceHandler
  addiu $sp, $sp, -0xd0
  sw    $s5, 0x34($sp)
  sw    $s2, 0x28($sp)
  addiu $t6, $a0, 0x38
  move  $s2, $a0
  sw    $ra, 0x44($sp)
  sw    $fp, 0x40($sp)
  sw    $s7, 0x3c($sp)
  sw    $s6, 0x38($sp)
  sw    $s4, 0x30($sp)
  sw    $s3, 0x2c($sp)
  sw    $s1, 0x24($sp)
  sw    $s0, 0x20($sp)
  sdc1  $f20, 0x18($sp)
  sw    $t6, 0x50($sp)
  addiu $s5, $a0, 0x48
.L7001CCBC:
  lhu   $t7, 0x38($s2)
  sltiu $at, $t7, 0x18
  beqz  $at, .L7001D24C
   sll   $t7, $t7, 2
  lui   $at, %hi(jpt_80029C28)
  addu  $at, $at, $t7
  lw    $t7, %lo(jpt_80029C28)($at)
  jr    $t7
   nop   
.L7001CCE0:
  lw    $a0, 0x18($s2)
  beql  $a0, $zero, .L7001D250
   move  $a0, $s5
  jal   alSeqNextEvent
   addiu $a1, $sp, 0x88
  lh    $v0, 0x88($sp)
  li    $at, 1
  move  $s1, $s2
  beq   $v0, $at, .L7001CD28
   addiu $a0, $sp, 0x88
  li    $at, 3
  beq   $v0, $at, .L7001CD4C
   move  $a1, $s2
  li    $at, 4
  beq   $v0, $at, .L7001CD64
   li    $t8, 2
  b     .L7001D250
   move  $a0, $s5
.L7001CD28:
  sw    $s2, 0xd0($sp)
  jal   __handleMIDIMsg
   sw    $s5, 0x4c($sp)
  lw    $s2, 0xd0($sp)
  lw    $s5, 0x4c($sp)
  jal   __postNextSeqEvent
   move  $a0, $s2
  b     .L7001D250
   move  $a0, $s5
.L7001CD4C:
  jal   __handleMetaMsg
   addiu $a0, $sp, 0x88
  jal   __postNextSeqEvent
   move  $a0, $s2
  b     .L7001D250
   move  $a0, $s5
.L7001CD64:
  sw    $t8, 0x2c($s2)
  li    $t9, 16
  lui   $a2, (0x7FFFFFFF >> 16) # lui $a2, 0x7fff
  sh    $t9, 0x88($sp)
  ori   $a2, (0x7FFFFFFF & 0xFFFF) # ori $a2, $a2, 0xffff
  move  $a0, $s5
  jal   alEvtqPostEvent
   addiu $a1, $sp, 0x88
  b     .L7001D250
   move  $a0, $s5
.L7001CD8C:
  li    $t6, 9
  sh    $t6, 0xbc($sp)
  lw    $a2, 0x5c($s2)
  move  $a0, $s5
  jal   alEvtqPostEvent
   addiu $a1, $sp, 0xbc
  b     .L7001D250
   move  $a0, $s5
.L7001CDAC:
  lw    $s0, 0x3c($s2)
  lw    $a0, 0x14($s2)
  jal   alSynStopVoice
   move  $a1, $s0
  lw    $a0, 0x14($s2)
  jal   alSynFreeVoice
   move  $a1, $s0
  lw    $s1, 0x10($s0)
  move  $a0, $s2
  lbu   $t7, 0x37($s1)
  beql  $t7, $zero, .L7001CDE8
   move  $a0, $s2
  jal   __seqpStopOsc
   move  $a1, $s1
  move  $a0, $s2
.L7001CDE8:
  jal   __unmapVoice
   move  $a1, $s0
  b     .L7001D250
   move  $a0, $s5
.L7001CDF8:
  lw    $s0, 0x3c($s2)
  li    $t9, 1
  lw    $s1, 0x10($s0)
  lbu   $t8, 0x34($s1)
  bnezl $t8, .L7001CE18
   lbu   $t6, 0x44($s2)
  sb    $t9, 0x34($s1)
  lbu   $t6, 0x44($s2)
.L7001CE18:
  lw    $s3, 0x40($s2)
  move  $a0, $s1
  sb    $t6, 0x30($s1)
  lw    $t7, 0x1c($s2)
  move  $a1, $s2
  addu  $t8, $t7, $s3
  jal   __vsVol
   sw    $t8, 0x24($s1)
  sll   $a2, $v0, 0x10
  sra   $t9, $a2, 0x10
  move  $a2, $t9
  lw    $a0, 0x14($s2)
  move  $a1, $s0
  jal   alSynSetVol
   move  $a3, $s3
  b     .L7001D250
   move  $a0, $s5
.L7001CE5C:
  lw    $t9, 0x74($s2)
  lw    $s4, 0x40($s2)
  lw    $s1, 0x3c($s2)
  addiu $a1, $sp, 0xa8
  jalr  $t9
  move  $a0, $s4
  cfc1  $t6, $31
  li    $t7, 1
  ctc1  $t7, $31
  lwc1  $f4, 0xa8($sp)
  move  $s3, $v0
  li    $at, 0x4F000000 # 2147483648.000000
  cvt.w.s $f6, $f4
  move  $a0, $s1
  move  $a1, $s2
  cfc1  $t7, $31
  nop   
  andi  $t7, $t7, 0x78
  beql  $t7, $zero, .L7001CEF4
   mfc1  $t7, $f6
  mtc1  $at, $f6
  li    $t7, 1
  sub.s $f6, $f4, $f6
  ctc1  $t7, $31
  nop   
  cvt.w.s $f6, $f6
  cfc1  $t7, $31
  nop   
  andi  $t7, $t7, 0x78
  bnez  $t7, .L7001CEE8
   nop   
  mfc1  $t7, $f6
  lui   $at, 0x8000
  b     .L7001CF00
   or    $t7, $t7, $at
.L7001CEE8:
  b     .L7001CF00
   li    $t7, -1
  mfc1  $t7, $f6
.L7001CEF4:
  nop   
  bltz  $t7, .L7001CEE8
   nop   
.L7001CF00:
  ctc1  $t6, $31
  jal   __vsVol
   sb    $t7, 0x36($s1)
  lw    $v1, 0x1c($s2)
  lw    $t9, 0x24($s1)
  sll   $a2, $v0, 0x10
  sra   $t8, $a2, 0x10
  subu  $a0, $t9, $v1
  bltz  $a0, .L7001CF30
   move  $a2, $t8
  b     .L7001CF34
   move  $v0, $a0
.L7001CF30:
  li    $v0, 1000
.L7001CF34:
  lw    $a0, 0x14($s2)
  addiu $a1, $s1, 4
  jal   alSynSetVol
   move  $a3, $v0
  li    $t6, 22
  sh    $t6, 0xbc($sp)
  sw    $s1, 0xc0($sp)
  sw    $s4, 0xc4($sp)
  move  $a0, $s5
  addiu $a1, $sp, 0xbc
  jal   alEvtqPostEvent
   move  $a2, $s3
  b     .L7001D250
   move  $a0, $s5
.L7001CF6C:
  lw    $t9, 0x74($s2)
  lw    $s4, 0x40($s2)
  lw    $s1, 0x3c($s2)
  lbu   $s0, 0x44($s2)
  addiu $a1, $sp, 0xa8
  jalr  $t9
  move  $a0, $s4
  lwc1  $f8, 0xa8($sp)
  lwc1  $f4, 0x28($s1)
  sll   $t8, $s0, 4
  swc1  $f8, 0x2c($s1)
  lwc1  $f6, 0x2c($s1)
  lw    $t7, 0x60($s2)
  move  $s3, $v0
  mul.s $f8, $f4, $f6
  addu  $t6, $t7, $t8
  lwc1  $f10, 0xc($t6)
  lw    $a0, 0x14($s2)
  addiu $a1, $s1, 4
  mul.s $f4, $f10, $f8
  mfc1  $a2, $f4
  jal   alSynSetPitch
   nop   
  li    $t9, 23
  sh    $t9, 0xbc($sp)
  sw    $s1, 0xc0($sp)
  sw    $s4, 0xc4($sp)
  sb    $s0, 0xc8($sp)
  move  $a0, $s5
  addiu $a1, $sp, 0xbc
  jal   alEvtqPostEvent
   move  $a2, $s3
  b     .L7001D250
   move  $a0, $s5
.L7001CFF4:
  move  $s1, $s2
  lw    $a0, 0x50($sp)
  sw    $s2, 0xd0($sp)
  jal   __handleMIDIMsg
   sw    $s5, 0x4c($sp)
  lw    $s2, 0xd0($sp)
  b     .L7001D24C
   lw    $s5, 0x4c($sp)
.L7001D014:
  move  $a1, $s2
  jal   __handleMetaMsg
   lw    $a0, 0x50($sp)
  b     .L7001D250
   move  $a0, $s5
.L7001D028:
  lw    $t7, 0x2c($s2)
  li    $at, 1
  li    $t8, 1
  beq   $t7, $at, .L7001D24C
   move  $a0, $s2
  jal   __postNextSeqEvent
   sw    $t8, 0x2c($s2)
  b     .L7001D250
   move  $a0, $s5
.L7001D04C:
  lw    $t6, 0x2c($s2)
  li    $at, 2
  bnel  $t6, $at, .L7001D250
   move  $a0, $s5
  lw    $s1, 0x64($s2)
  beqz  $s1, .L7001D0B0
   addiu $s0, $s1, 4
.L7001D068:
  move  $a1, $s0
  jal   alSynStopVoice
   lw    $a0, 0x14($s2)
  lw    $a0, 0x14($s2)
  jal   alSynFreeVoice
   move  $a1, $s0
  lbu   $t9, 0x37($s1)
  move  $a0, $s2
  beql  $t9, $zero, .L7001D09C
   move  $a0, $s2
  jal   __seqpStopOsc
   move  $a1, $s1
  move  $a0, $s2
.L7001D09C:
  jal   __unmapVoice
   move  $a1, $s0
  lw    $s1, 0x64($s2)
  bnezl $s1, .L7001D068
   addiu $s0, $s1, 4
.L7001D0B0:
  sw    $zero, 0x1c($s2)
  b     .L7001D24C
   sw    $zero, 0x2c($s2)
.L7001D0BC:
  lw    $t7, 0x2c($s2)
  li    $at, 1
  move  $a0, $s5
  bnel  $t7, $at, .L7001D250
   move  $a0, $s5
  jal   alEvtqFlushType
   move  $a1, $zero
  move  $a0, $s5
  jal   alEvtqFlushType
   li    $a1, 2
  lw    $s1, 0x64($s2)
  beqz  $s1, .L7001D120
   addiu $s0, $s1, 4
.L7001D0F0:
  move  $a1, $s0
  move  $a0, $s2
  jal   __voiceNeedsNoteKill
   li    $a2, 50000
  beqz  $v0, .L7001D114
   move  $a0, $s2
  move  $a1, $s0
  jal   __seqpReleaseVoice
   li    $a2, 50000
.L7001D114:
  lw    $s1, ($s1)
  bnezl $s1, .L7001D0F0
   addiu $s0, $s1, 4
.L7001D120:
  li    $t8, 2
  sw    $t8, 0x2c($s2)
  li    $t6, 16
  lui   $a2, (0x7FFFFFFF >> 16) # lui $a2, 0x7fff
  sh    $t6, 0xbc($sp)
  ori   $a2, (0x7FFFFFFF & 0xFFFF) # ori $a2, $a2, 0xffff
  move  $a0, $s5
  jal   alEvtqPostEvent
   addiu $a1, $sp, 0xbc
  b     .L7001D250
   move  $a0, $s5
.L7001D14C:
  lw    $s1, 0x64($s2)
  lh    $t9, 0x3c($s2)
  beqz  $s1, .L7001D24C
   sh    $t9, 0x32($s2)
  move  $a0, $s1
.L7001D160:
  jal   __vsVol
   move  $a1, $s2
  lw    $v1, 0x1c($s2)
  lw    $t8, 0x24($s1)
  sll   $a2, $v0, 0x10
  sra   $t7, $a2, 0x10
  subu  $a0, $t8, $v1
  bltz  $a0, .L7001D18C
   move  $a2, $t7
  b     .L7001D190
   move  $v0, $a0
.L7001D18C:
  li    $v0, 1000
.L7001D190:
  lw    $a0, 0x14($s2)
  addiu $a1, $s1, 4
  jal   alSynSetVol
   move  $a3, $v0
  lw    $s1, ($s1)
  bnezl $s1, .L7001D160
   move  $a0, $s1
  b     .L7001D250
   move  $a0, $s5
.L7001D1B4:
  lw    $t6, 0x3c($s2)
  lw    $t9, 0x40($s2)
  lw    $t7, 0x44($s2)
  sw    $t6, 0x7c($s2)
  sw    $t9, 0x80($s2)
  b     .L7001D24C
   sw    $t7, 0x84($s2)
.L7001D1D0:
  lbu   $s0, 0x3c($s2)
  lw    $t6, 0x60($s2)
  lbu   $t8, 0x3d($s2)
  sll   $t9, $s0, 4
  addu  $t7, $t6, $t9
  b     .L7001D24C
   sb    $t8, 8($t7)
.L7001D1EC:
  lw    $a1, 0x3c($s2)
  li    $t7, 488
  lui   $at, %hi(F32_80029C88)
  beqz  $a1, .L7001D21C
   sw    $a1, 0x18($s2)
  lwc1  $f6, %lo(F32_80029C88)($at)
  lwc1  $f10, 0x14($a1)
  mul.s $f8, $f6, $f10
  trunc.w.s $f4, $f8
  mfc1  $t8, $f4
  b     .L7001D220
   sw    $t8, 0x24($s2)
.L7001D21C:
  sw    $t7, 0x24($s2)
.L7001D220:
  lw    $a1, 0x20($s2)
  beql  $a1, $zero, .L7001D250
   move  $a0, $s5
  jal   __initFromBank
   move  $a0, $s2
  b     .L7001D250
   move  $a0, $s5
.L7001D23C:
  lw    $a1, 0x3c($s2)
  move  $a0, $s2
  jal   __initFromBank
   sw    $a1, 0x20($s2)
.L7001D24C:
  move  $a0, $s5
.L7001D250:
  jal   alEvtqNextEvent
   lw    $a1, 0x50($sp)
  beqz  $v0, .L7001CCBC
   sw    $v0, 0x28($s2)
  lw    $t6, 0x1c($s2)
  addu  $t9, $t6, $v0
  sw    $t9, 0x1c($s2)
  lw    $ra, 0x44($sp)
  lw    $fp, 0x40($sp)
  lw    $s7, 0x3c($sp)
  lw    $s6, 0x38($sp)
  lw    $s5, 0x34($sp)
  lw    $s4, 0x30($sp)
  lw    $s3, 0x2c($sp)
  lw    $s2, 0x28($sp)
  lw    $s1, 0x24($sp)
  lw    $s0, 0x20($sp)
  ldc1  $f20, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0xd0

glabel __seqpStopOsc
  addiu $sp, $sp, -0x38
  sw    $ra, 0x34($sp)
  sw    $s7, 0x30($sp)
  sw    $s6, 0x2c($sp)
  sw    $s5, 0x28($sp)
  sw    $s4, 0x24($sp)
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  lw    $s0, 0x50($a0)
  move  $s2, $a1
  move  $s5, $a0
  beqz  $s0, .L7001D378
   li    $s7, 23
  li    $s6, 22
.L7001D2E0:
  lh    $s3, 0xc($s0)
  lw    $s1, ($s0)
  beql  $s3, $s6, .L7001D2FC
   lw    $t6, 0x10($s0)
  bne   $s3, $s7, .L7001D370
   nop   
  lw    $t6, 0x10($s0)
.L7001D2FC:
  bne   $s2, $t6, .L7001D370
glabel unknown_libname_37
   nop   
  lw    $t9, 0x78($s5)
  lw    $a0, 0x14($s0)
  addiu $s4, $s5, 0x48
  jalr  $t9
  nop   
  jal   alUnlink
   move  $a0, $s0
  beqz  $s1, .L7001D338
   move  $a0, $s0
  lw    $t7, 8($s1)
glabel unknown_libname_38
  lw    $t8, 8($s0)
  addu  $t0, $t7, $t8
  sw    $t0, 8($s1)
glabel unknown_libname_39
.L7001D338:
  jal   alLink
   move  $a1, $s4
  bnel  $s3, $s6, .L7001D35C
   lbu   $t3, 0x37($s2)
  lbu   $t1, 0x37($s2)
  andi  $t2, $t1, 0xfe
  b     .L7001D364
   sb    $t2, 0x37($s2)
  lbu   $t3, 0x37($s2)
glabel unknown_libname_40
.L7001D35C:
  andi  $t4, $t3, 0xfd
  sb    $t4, 0x37($s2)
.L7001D364:
  lbu   $t5, 0x37($s2)
  beql  $t5, $zero, .L7001D37C
   lw    $ra, 0x34($sp)
.L7001D370:
  bnez  $s1, .L7001D2E0
   move  $s0, $s1
.L7001D378:
  lw    $ra, 0x34($sp)
.L7001D37C:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
glabel unknown_libname_41
  lw    $s4, 0x24($sp)
  lw    $s5, 0x28($sp)
  lw    $s6, 0x2c($sp)
  lw    $s7, 0x30($sp)
  jr    $ra
glabel unknown_libname_42
   addiu $sp, $sp, 0x38

glabel __initChanState
  addiu $sp, $sp, -0x28
  sw    $ra, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  lbu   $t6, 0x34($a0)
  move  $s1, $a0
  move  $s0, $zero
  blez  $t6, .L7001D3FC
   move  $s2, $zero
  lw    $t7, 0x60($s1)
.L7001D3D0:
  move  $a0, $s1
  move  $a1, $s0
  addu  $t8, $t7, $s2
  jal   __resetPerfChanState
   sw    $zero, ($t8)
  lbu   $t9, 0x34($s1)
  addiu $s0, $s0, 1
  addiu $s2, $s2, 0x10
  slt   $at, $s0, $t9
  bnezl $at, .L7001D3D0
   lw    $t7, 0x60($s1)
.L7001D3FC:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28

glabel alSeqpNew
  addiu $sp, $sp, -0x40
  sw    $ra, 0x24($sp)
  sw    $s1, 0x20($sp)
  sw    $s0, 0x1c($sp)
  lw    $a2, 0xc($a1)
  sw    $zero, 0x20($a0)
  sw    $zero, 0x18($a0)
  lui   $t6, %hi(alGlobals) 
  lw    $t6, %lo(alGlobals)($t6)
  li    $t7, 255
  li    $t8, 488
  li    $t9, 32767
  sh    $t7, 0x30($a0)
  sw    $t8, 0x24($a0)
  sw    $zero, 0x28($a0)
  sw    $zero, 0x2c($a0)
  sh    $t9, 0x32($a0)
  sw    $t6, 0x14($a0)
  lbu   $t0, 9($a1)
  li    $t1, 16000
  sw    $t1, 0x5c($a0)
  sw    $zero, 0x1c($a0)
  sb    $t0, 0x35($a0)
  lw    $t2, 0x10($a1)
  li    $t5, 9
  move  $s1, $a1
  sw    $t2, 0x70($a0)
  lw    $t3, 0x14($a1)
  move  $s0, $a0
  li    $t7, 16
  sw    $t3, 0x74($a0)
  lw    $t4, 0x18($a1)
  sw    $zero, 0x7c($a0)
  sw    $zero, 0x80($a0)
  sw    $zero, 0x84($a0)
  sh    $t5, 0x38($a0)
  sw    $t4, 0x78($a0)
  lbu   $t6, 8($a1)
  move  $a1, $zero
  sb    $t6, 0x34($a0)
  lbu   $a3, 8($s1)
  sw    $t7, 0x10($sp)
  move  $a0, $zero
  jal   alHeapDBAlloc
   sw    $a2, 0x2c($sp)
  sw    $v0, 0x60($s0)
  jal   __initChanState
   move  $a0, $s0
  lw    $a3, ($s1)
  li    $t8, 56
  sw    $t8, 0x10($sp)
  move  $a0, $zero
  move  $a1, $zero
  jal   alHeapDBAlloc
   lw    $a2, 0x2c($sp)
  sw    $zero, 0x6c($s0)
  lw    $t9, ($s1)
  move  $a0, $zero
  move  $a1, $zero
  blez  $t9, .L7001D530
   li    $t2, 28
  move  $v1, $v0
  lw    $t0, 0x6c($s0)
.L7001D510:
  addiu $a0, $a0, 1
  sw    $t0, ($v1)
  sw    $v1, 0x6c($s0)
  lw    $t1, ($s1)
  addiu $v1, $v1, 0x38
  slt   $at, $a0, $t1
  bnezl $at, .L7001D510
   lw    $t0, 0x6c($s0)
.L7001D530:
  sw    $zero, 0x64($s0)
  sw    $zero, 0x68($s0)
  lw    $a3, 4($s1)
  sw    $t2, 0x10($sp)
  lw    $a2, 0x2c($sp)
  jal   alHeapDBAlloc
   move  $a0, $zero
  addiu $a0, $s0, 0x48
  move  $a1, $v0
  jal   alEvtqNew
   lw    $a2, 4($s1)
  lui   $t3, %hi(__seqpVoiceHandler) # $t3, 0x7002
  addiu $t3, %lo(__seqpVoiceHandler) # addiu $t3, $t3, -0x3384
  sw    $zero, ($s0)
  sw    $t3, 8($s0)
  sw    $s0, 4($s0)
  lui   $a0, %hi(alGlobals)
  lw    $a0, %lo(alGlobals)($a0)
  jal   alSynAddPlayer
   move  $a1, $s0
  lw    $ra, 0x24($sp)
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x40

  nop   
  nop   
  nop   
.section .rodata


.section .rodata
glabel jpt_80029A50
					.word .L7001C7F4, .L7001CC64, .L7001CC64, .L7001CC64
                    .word .L7001CC64, .L7001CC64, .L7001CC64, .L7001CC64
                    .word .L7001CC64, .L7001CC64, .L7001CC64, .L7001CC64
                    .word .L7001CC64, .L7001CC64, .L7001CC64, .L7001CC64
                    .word .L7001C4A0, .L7001CC64, .L7001CC64, .L7001CC64
                    .word .L7001CC64, .L7001CC64, .L7001CC64, .L7001CC64
                    .word .L7001CC64, .L7001CC64, .L7001CC64, .L7001CC64
                    .word .L7001CC64, .L7001CC64, .L7001CC64, .L7001CC64
                    .word .L7001C84C, .L7001CC64, .L7001CC64, .L7001CC64
                    .word .L7001CC64, .L7001CC64, .L7001CC64, .L7001CC64
                    .word .L7001CC64, .L7001CC64, .L7001CC64, .L7001CC64
                    .word .L7001CC64, .L7001CC64, .L7001CC64, .L7001CC64
                    .word .L7001C92C, .L7001CC64, .L7001CC64, .L7001CC64
                    .word .L7001CC64, .L7001CC64, .L7001CC64, .L7001CC64
                    .word .L7001CC64, .L7001CC64, .L7001CC64, .L7001CC64
                    .word .L7001CC64, .L7001CC64, .L7001CC64, .L7001CC64
                    .word .L7001CB98, .L7001CC64, .L7001CC64, .L7001CC64
                    .word .L7001CC64, .L7001CC64, .L7001CC64, .L7001CC64
                    .word .L7001CC64, .L7001CC64, .L7001CC64, .L7001CC64
                    .word .L7001CC64, .L7001CC64, .L7001CC64, .L7001CC64
                    .word .L7001C8B4, .L7001CC64, .L7001CC64, .L7001CC64
                    .word .L7001CC64, .L7001CC64, .L7001CC64, .L7001CC64
                    .word .L7001CC64, .L7001CC64, .L7001CC64, .L7001CC64
                    .word .L7001CC64, .L7001CC64, .L7001CC64, .L7001CC64
                    .word .L7001CBCC
glabel jpt_80029BD4
                    .word .L7001C9F0, .L7001CC64, .L7001CC64, .L7001C994
                    .word .L7001CC64, .L7001CC64, .L7001CC64, .L7001CC64
                    .word .L7001CC64, .L7001CA84, .L7001CC64, .L7001CC64
                    .word .L7001CC64, .L7001CC64, .L7001CC64, .L7001CC64
                    .word .L7001CC64, .L7001CC64, .L7001CC64, .L7001CC64
                    .word .L7001CC64
glabel jpt_80029C28
	                .word .L7001CCE0, .L7001D24C, .L7001CFF4, .L7001D24C
                    .word .L7001D24C, .L7001CDAC, .L7001CDF8, .L7001D014
                    .word .L7001D24C, .L7001CD8C, .L7001D14C, .L7001D1B4
                    .word .L7001D1D0, .L7001D1EC, .L7001D23C, .L7001D028
                    .word .L7001D04C, .L7001D0BC, .L7001D24C, .L7001D24C
                    .word .L7001D24C, .L7001D24C, .L7001CE5C, .L7001CF6C
glabel F32_80029C88
.float 500000.0
                    .align 4

.section .text
glabel alSynStartVoiceParams
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a1, 0x24($sp)
  sw    $a2, 0x28($sp)
  sw    $a3, 0x2c($sp)
  lw    $t6, 8($a1)
  beql  $t6, $zero, .L7001D678
   lw    $ra, 0x14($sp)
  sw    $a0, 0x20($sp)
  jal   __allocParam
   sw    $a1, 0x24($sp)
  lw    $a0, 0x20($sp)
  lw    $a3, 0x24($sp)
  beqz  $v0, .L7001D674
   move  $a2, $v0
  lbu   $v1, 0x3b($sp)
  bgez  $v1, .L7001D5F4
   move  $v0, $v1
  negu  $v1, $v0
  andi  $t7, $v1, 0xff
  move  $v1, $t7
.L7001D5F4:
  lw    $t9, 8($a3)
  lw    $t8, 0x1c($a0)
  li    $t2, 13
  lw    $t0, 0xd8($t9)
  sw    $zero, ($a2)
  sh    $t2, 8($a2)
  addu  $t1, $t8, $t0
  sw    $t1, 4($a2)
  lh    $t3, 0x1a($a3)
  sh    $t3, 0xa($a2)
  lbu   $t4, 0x37($sp)
  sb    $t4, 0x12($a2)
  lh    $t5, 0x32($sp)
  sb    $v1, 0x13($a2)
  sh    $t5, 0x10($a2)
  lwc1  $f4, 0x2c($sp)
  swc1  $f4, 0xc($a2)
  sw    $a3, 0x24($sp)
  sw    $a2, 0x1c($sp)
  jal   _timeToSamples
   lw    $a1, 0x3c($sp)
  lw    $a2, 0x1c($sp)
  lw    $a3, 0x24($sp)
  li    $a1, 3
  sw    $v0, 0x14($a2)
  lw    $t6, 0x28($sp)
  sw    $t6, 0x18($a2)
  lw    $t7, 8($a3)
  lw    $a0, 0xc($t7)
  lw    $t9, 8($a0)
  jalr  $t9
  nop   
.L7001D674:
  lw    $ra, 0x14($sp)
.L7001D678:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   

  nop   
  nop   
  nop   
glabel alCopy
  move  $v0, $a0
  move  $v1, $a1
  blez  $a2, .L7001D6FC
   move  $a3, $zero
  andi  $a1, $a2, 3
  beqz  $a1, .L7001D6CC
   move  $a0, $a1
.L7001D6AC:
  lbu   $t6, ($v0)
  addiu $a3, $a3, 1
  addiu $v1, $v1, 1
  addiu $v0, $v0, 1
  bne   $a0, $a3, .L7001D6AC
   sb    $t6, -1($v1)
  beq   $a3, $a2, .L7001D6FC
   nop   
.L7001D6CC:
  lbu   $t7, ($v0)
  addiu $a3, $a3, 4
  addiu $v1, $v1, 4
  sb    $t7, -4($v1)
  lbu   $t8, 1($v0)
  addiu $v0, $v0, 4
  sb    $t8, -3($v1)
  lbu   $t9, -2($v0)
  sb    $t9, -2($v1)
  lbu   $t0, -1($v0)
  bne   $a3, $a2, .L7001D6CC
   sb    $t0, -1($v1)
.L7001D6FC:
  jr    $ra
   nop   

  nop   
  nop   
  nop   

glabel __osPiCreateAccessQueue
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  li    $t6, 1
  lui   $at, %hi(__osPiAccessQueueEnabled)
  lui   $a0, %hi(__osPiAccessQueue)
  lui   $a1, %hi(piAccessBuf)
  sw    $t6, %lo(__osPiAccessQueueEnabled)($at)
  addiu $a1, %lo(piAccessBuf) # addiu $a1, $a1, -0x7020
  addiu $a0, %lo(__osPiAccessQueue) # addiu $a0, $a0, -0x7018
  jal   osCreateMesgQueue
   li    $a2, 1
  lui   $a0, %hi(__osPiAccessQueue)
  addiu $a0, %lo(__osPiAccessQueue) # addiu $a0, $a0, -0x7018
  move  $a1, $zero
  jal   osSendMesg
   move  $a2, $zero
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   

glabel __osPiGetAccess
  lui   $t6, %hi(__osPiAccessQueueEnabled) 
  lw    $t6, %lo(__osPiAccessQueueEnabled)($t6)
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  bnez  $t6, .L7001D780
   nop   
  jal   __osPiCreateAccessQueue
   nop   
.L7001D780:
  lui   $a0, %hi(__osPiAccessQueue)
  addiu $a0, %lo(__osPiAccessQueue) # addiu $a0, $a0, -0x7018
  addiu $a1, $sp, 0x1c
  jal   osRecvMesg
   li    $a2, 1
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   

glabel __osPiRelAccess
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lui   $a0, %hi(__osPiAccessQueue)
  addiu $a0, %lo(__osPiAccessQueue) # addiu $a0, $a0, -0x7018
  move  $a1, $zero
  jal   osSendMesg
   move  $a2, $zero
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   

.section .data
glabel __osPiAccessQueueEnabled
.word 0
.align 4

.section .bss
glabel piAccessBuf
.word 0
.word 0
glabel __osPiAccessQueue
.byte 0, 0, 0, 0
.byte 0, 0, 0, 0
.byte 0, 0, 0, 0
.byte 0, 0, 0, 0
.byte 0, 0, 0, 0
.byte 0, 0, 0, 0

.section .text
glabel _Litob
  addiu $sp, $sp, -0x90
  sw    $s1, 0x20($sp)
  andi  $v0, $a1, 0xff
  li    $v1, 88
  move  $s1, $a0
  sw    $ra, 0x2c($sp)
  sw    $s3, 0x28($sp)
  sw    $s2, 0x24($sp)
  sw    $s0, 0x1c($sp)
  bne   $v1, $v0, .L7001D808
   sw    $a1, 0x94($sp)
  lui   $s3, %hi(auppercase_hex_char)
  b     .L7001D810
   addiu $s3, %lo(auppercase_hex_char) # addiu $s3, $s3, -0x7cfc
.L7001D808:
  lui   $s3, %hi(alowercase_hex_char)
  addiu $s3, %lo(alowercase_hex_char) # addiu $s3, $s3, -0x7d10
.L7001D810:
  li    $at, 111
  bne   $v0, $at, .L7001D824
   li    $s0, 24
  b     .L7001D844
   li    $t1, 8
.L7001D824:
  li    $at, 120
  beq   $v0, $at, .L7001D840
   li    $t0, 16
  beq   $v1, $v0, .L7001D840
   nop   
  b     .L7001D840
   li    $t0, 10
.L7001D840:
  move  $t1, $t0
.L7001D844:
  lw    $t8, ($s1)
  lw    $t9, 4($s1)
  li    $at, 100
  sw    $t8, 0x60($sp)
  sw    $t8, 0x40($sp)
  sw    $t9, 0x44($sp)
  beq   $v0, $at, .L7001D870
   sw    $t9, 0x64($sp)
  li    $at, 105
  bnel  $v0, $at, .L7001D8AC
   lw    $t2, 0x60($sp)
.L7001D870:
  lw    $t4, 0x40($sp)
  bgtzl $t4, .L7001D8AC
   lw    $t2, 0x60($sp)
  bltz  $t4, .L7001D88C
   lw    $t6, 0x60($sp)
  b     .L7001D8AC
   lw    $t2, 0x60($sp)
.L7001D88C:
  lw    $t7, 0x64($sp)
  not   $t8, $t6
  sltiu $at, $t7, 1
  addu  $t8, $t8, $at
  negu  $t9, $t7
  sw    $t9, 0x64($sp)
  sw    $t8, 0x60($sp)
  lw    $t2, 0x60($sp)
.L7001D8AC:
  lw    $t3, 0x64($sp)
  li    $t0, 23
  bnez  $t2, .L7001D8D0
   lw    $a0, 0x60($sp)
  bnezl $t3, .L7001D8D4
   li    $s0, 23
  lw    $t4, 0x24($s1)
  beql  $t4, $zero, .L7001D90C
   addiu $s2, $sp, 0x78
.L7001D8D0:
  li    $s0, 23
.L7001D8D4:
  lw    $a1, 0x64($sp)
  move  $a3, $t1
  sra   $a2, $t1, 0x1f
  sw    $t0, 0x4c($sp)
  jal   __ull_rem
   sw    $t1, 0x70($sp)
  lw    $t0, 0x4c($sp)
  addu  $t6, $v1, $s3
  lbu   $t7, ($t6)
  addiu $s2, $sp, 0x78
  lw    $t1, 0x70($sp)
  addu  $t8, $s2, $t0
  sb    $t7, ($t8)
  addiu $s2, $sp, 0x78
.L7001D90C:
  lw    $a0, 0x60($sp)
  lw    $a1, 0x64($sp)
  move  $a3, $t1
  sra   $a2, $t1, 0x1f
  jal   __ull_div
   sw    $t1, 0x70($sp)
  lw    $t1, 0x70($sp)
  sw    $v1, 4($s1)
  bltz  $v0, .L7001D9DC
   sw    $v0, ($s1)
  bgtz  $v0, .L7001D944
   nop   
  beql  $v1, $zero, .L7001D9E0
   li    $t4, 24
.L7001D944:
  blez  $s0, .L7001D9DC
   sra   $t4, $t1, 0x1f
  lw    $t2, ($s1)
  lw    $t3, 4($s1)
  sw    $t1, 0x3c($sp)
  sw    $t4, 0x38($sp)
  sw    $t2, 0x40($sp)
  sw    $t3, 0x44($sp)
  lw    $t6, 0x38($sp)
.L7001D968:
  lw    $t7, 0x3c($sp)
  addiu $a0, $sp, 0x50
  lw    $a2, 0x40($sp)
  lw    $a3, 0x44($sp)
  sw    $t6, 0x10($sp)
  jal   lldiv
   sw    $t7, 0x14($sp)
  lw    $t8, 0x50($sp)
  lw    $t9, 0x54($sp)
  addiu $a0, $s0, -1
  sw    $t8, ($s1)
  sw    $t9, 4($s1)
  lw    $t3, 0x5c($sp)
  addu  $t7, $s2, $a0
  move  $s0, $a0
  addu  $t5, $t3, $s3
  lbu   $t6, ($t5)
  sb    $t6, ($t7)
  lw    $t8, ($s1)
  lw    $t9, 4($s1)
  sw    $t8, 0x40($sp)
  bltz  $t8, .L7001D9DC
   sw    $t9, 0x44($sp)
  bgtz  $t8, .L7001D9D4
   nop   
  beql  $t9, $zero, .L7001D9E0
   li    $t4, 24
.L7001D9D4:
  bgtzl $s0, .L7001D968
   lw    $t6, 0x38($sp)
.L7001D9DC:
  li    $t4, 24
.L7001D9E0:
  subu  $a2, $t4, $s0
  sw    $a2, 0x14($s1)
  lw    $a0, 8($s1)
  jal   memcpy
   addu  $a1, $s2, $s0
  lw    $a1, 0x14($s1)
  lw    $a0, 0x24($s1)
  slt   $at, $a1, $a0
  beqz  $at, .L7001DA0C
   subu  $t5, $a0, $a1
  sw    $t5, 0x10($s1)
.L7001DA0C:
  bgezl $a0, .L7001DA50
   lw    $ra, 0x2c($sp)
  lw    $t6, 0x30($s1)
  li    $at, 16
  andi  $t7, $t6, 0x14
  bnel  $t7, $at, .L7001DA50
   lw    $ra, 0x2c($sp)
  lw    $t8, 0x28($s1)
  lw    $t9, 0xc($s1)
  lw    $v0, 0x10($s1)
  subu  $t2, $t8, $t9
  subu  $t3, $t2, $v0
  subu  $s0, $t3, $a1
  blez  $s0, .L7001DA4C
   addu  $t4, $v0, $s0
  sw    $t4, 0x10($s1)
.L7001DA4C:
  lw    $ra, 0x2c($sp)
.L7001DA50:
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  lw    $s2, 0x24($sp)
  lw    $s3, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x90

  nop   
  nop   

.section .data
glabel alowercase_hex_char
.asciiz "0123456789abcdef"
.align 2
glabel auppercase_hex_char
.asciiz "0123456789ABCDEF"
.align 4
.section .rodata
glabel digits
 .double 10.0
 .double 100.0
 .double 10000.0
 .double 1.0e8
 .double 1.0e16
 .double 1.0e32
 .double 1.0e64
 .double 1.0e128
 .double 1.0e256
glabel aNan
 .asciiz "NaN"
glabel aInf
 .asciiz "Inf"

.section .text
glabel xldtob_sub0
  addiu $sp, $sp, -0x18
  sw    $s2, 0x28($sp)
  sll   $t6, $s2, 0x10
  sra   $s2, $t6, 0x10
  sw    $s3, 0x24($sp)
  sll   $t8, $s3, 0x10
  sra   $s3, $t8, 0x10
  andi  $t6, $s4, 0xff
  sw    $s4, 0x1c($sp)
  move  $s4, $t6
  bgtz  $s3, .L7001DAAC
   sw    $ra, 0x14($sp)
  lui   $s1, %hi(asc_D_80029CE0)
  addiu $s1, %lo(asc_D_80029CE0) # addiu $s1, $s1, -0x6320
  li    $s3, 1
.L7001DAAC:
  li    $v0, 102
  beq   $v0, $s4, .L7001DAE4
   move  $v1, $s4
  li    $a0, 103
  beq   $a0, $v1, .L7001DAC8
   li    $at, 71
  bne   $v1, $at, .L7001DD20
.L7001DAC8:
   slti  $at, $s2, -4
  bnez  $at, .L7001DD20
   nop   
  lw    $t7, 0x24($s0)
  slt   $at, $s2, $t7
  beqz  $at, .L7001DD20
   nop   
.L7001DAE4:
  addiu $s2, $s2, 1
  sll   $t8, $s2, 0x10
  beq   $v0, $v1, .L7001DB28
   sra   $s2, $t8, 0x10
  lw    $t6, 0x30($s0)
  lw    $v0, 0x24($s0)
  andi  $t7, $t6, 8
  bnez  $t7, .L7001DB18
   slt   $at, $s3, $v0
  beql  $at, $zero, .L7001DB1C
   subu  $t8, $v0, $s2
  sw    $s3, 0x24($s0)
  move  $v0, $s3
.L7001DB18:
  subu  $t8, $v0, $s2
.L7001DB1C:
  bgez  $t8, .L7001DB28
   sw    $t8, 0x24($s0)
  sw    $zero, 0x24($s0)
.L7001DB28:
  bgtz  $s2, .L7001DBF8
   slt   $at, $s3, $s2
  lw    $t7, 8($s0)
  lw    $t8, 0x14($s0)
  li    $t6, 48
  negu  $v1, $s2
  addu  $t9, $t7, $t8
  sb    $t6, ($t9)
  lw    $t7, 0x14($s0)
  lw    $v0, 0x24($s0)
  move  $a1, $s1
  addiu $t8, $t7, 1
  bgtz  $v0, .L7001DB70
   sw    $t8, 0x14($s0)
  lw    $t6, 0x30($s0)
  andi  $t9, $t6, 8
  beql  $t9, $zero, .L7001DB98
   slt   $at, $v0, $v1
.L7001DB70:
  lw    $t8, 8($s0)
  lw    $t6, 0x14($s0)
  li    $t7, 46
  addu  $t9, $t8, $t6
  sb    $t7, ($t9)
  lw    $t8, 0x14($s0)
  lw    $v0, 0x24($s0)
  addiu $t6, $t8, 1
  sw    $t6, 0x14($s0)
  slt   $at, $v0, $v1
.L7001DB98:
  beql  $at, $zero, .L7001DBB4
   addu  $t8, $v0, $s2
  negu  $s2, $v0
  sll   $t7, $s2, 0x10
  sra   $s2, $t7, 0x10
  negu  $v1, $s2
  addu  $t8, $v0, $s2
.L7001DBB4:
  slt   $at, $t8, $s3
  sw    $v1, 0x18($s0)
  beqz  $at, .L7001DBD0
   sw    $t8, 0x24($s0)
  sll   $s3, $t8, 0x10
  sra   $t6, $s3, 0x10
  move  $s3, $t6
.L7001DBD0:
  lw    $t7, 8($s0)
  lw    $t9, 0x14($s0)
  sw    $s3, 0x1c($s0)
  move  $a2, $s3
  jal   memcpy
   addu  $a0, $t7, $t9
  lw    $t8, 0x24($s0)
  subu  $t6, $t8, $s3
  b     .L7001DF7C
   sw    $t6, 0x20($s0)
.L7001DBF8:
  beqz  $at, .L7001DC70
   move  $a1, $s1
  lw    $t7, 8($s0)
  lw    $t9, 0x14($s0)
  move  $a1, $s1
  move  $a2, $s3
  jal   memcpy
   addu  $a0, $t7, $t9
  lw    $t8, 0x14($s0)
  lw    $v0, 0x24($s0)
  subu  $t7, $s2, $s3
  addu  $t6, $t8, $s3
  sw    $t6, 0x14($s0)
  bgtz  $v0, .L7001DC44
   sw    $t7, 0x18($s0)
  lw    $t9, 0x30($s0)
  andi  $t8, $t9, 8
  beqz  $t8, .L7001DC68
   nop   
.L7001DC44:
  lw    $t7, 8($s0)
  lw    $t9, 0x14($s0)
  li    $t6, 46
  addu  $t8, $t7, $t9
  sb    $t6, ($t8)
  lw    $t7, 0x1c($s0)
  lw    $v0, 0x24($s0)
  addiu $t9, $t7, 1
  sw    $t9, 0x1c($s0)
.L7001DC68:
  b     .L7001DF7C
   sw    $v0, 0x20($s0)
.L7001DC70:
  lw    $t6, 8($s0)
  lw    $t8, 0x14($s0)
  move  $a2, $s2
  jal   memcpy
   addu  $a0, $t6, $t8
  lw    $t7, 0x14($s0)
  lw    $v0, 0x24($s0)
  subu  $s3, $s3, $s2
  sll   $t6, $s3, 0x10
  addu  $t9, $t7, $s2
  sw    $t9, 0x14($s0)
  bgtz  $v0, .L7001DCB4
   sra   $s3, $t6, 0x10
  lw    $t7, 0x30($s0)
  andi  $t9, $t7, 8
  beql  $t9, $zero, .L7001DCDC
   slt   $at, $v0, $s3
.L7001DCB4:
  lw    $t8, 8($s0)
  lw    $t7, 0x14($s0)
  li    $t6, 46
  addu  $t9, $t8, $t7
  sb    $t6, ($t9)
  lw    $t8, 0x14($s0)
  lw    $v0, 0x24($s0)
  addiu $t7, $t8, 1
  sw    $t7, 0x14($s0)
  slt   $at, $v0, $s3
.L7001DCDC:
  beqz  $at, .L7001DCF0
   addu  $a1, $s2, $s1
  sll   $s3, $v0, 0x10
  sra   $t6, $s3, 0x10
  move  $s3, $t6
.L7001DCF0:
  lw    $t9, 8($s0)
  lw    $t8, 0x14($s0)
  move  $a2, $s3
  jal   memcpy
   addu  $a0, $t9, $t8
  lw    $t7, 0x14($s0)
  lw    $t9, 0x24($s0)
  addu  $t6, $t7, $s3
  subu  $t8, $t9, $s3
  sw    $t6, 0x14($s0)
  b     .L7001DF7C
   sw    $t8, 0x18($s0)
.L7001DD20:
  beq   $a0, $v1, .L7001DD30
   li    $at, 71
  bnel  $v1, $at, .L7001DD70
   lw    $t8, 8($s0)
.L7001DD30:
  lw    $v0, 0x24($s0)
  li    $s4, 69
  slt   $at, $s3, $v0
  beql  $at, $zero, .L7001DD50
   addiu $t7, $v0, -1
  sw    $s3, 0x24($s0)
  move  $v0, $s3
  addiu $t7, $v0, -1
.L7001DD50:
  bgez  $t7, .L7001DD5C
   sw    $t7, 0x24($s0)
  sw    $zero, 0x24($s0)
.L7001DD5C:
  bne   $a0, $v1, .L7001DD6C
   nop   
  b     .L7001DD6C
   li    $s4, 101
.L7001DD6C:
  lw    $t8, 8($s0)
.L7001DD70:
  lw    $t7, 0x14($s0)
  lbu   $t9, ($s1)
  addiu $s1, $s1, 1
  addu  $t6, $t8, $t7
  sb    $t9, ($t6)
  lw    $t8, 0x14($s0)
  lw    $v0, 0x24($s0)
  addiu $t7, $t8, 1
  bgtz  $v0, .L7001DDA8
   sw    $t7, 0x14($s0)
  lw    $t9, 0x30($s0)
  andi  $t6, $t9, 8
  beqz  $t6, .L7001DDCC
   nop   
.L7001DDA8:
  lw    $t7, 8($s0)
  lw    $t9, 0x14($s0)
  li    $t8, 46
  addu  $t6, $t7, $t9
  sb    $t8, ($t6)
  lw    $t7, 0x14($s0)
  lw    $v0, 0x24($s0)
  addiu $t9, $t7, 1
  sw    $t9, 0x14($s0)
.L7001DDCC:
  blezl $v0, .L7001DE28
   lw    $t6, 8($s0)
  addiu $s3, $s3, -1
  sll   $t8, $s3, 0x10
  sra   $s3, $t8, 0x10
  slt   $at, $v0, $s3
  beqz  $at, .L7001DDF8
   move  $a1, $s1
  sll   $s3, $v0, 0x10
  sra   $t7, $s3, 0x10
  move  $s3, $t7
.L7001DDF8:
  lw    $t9, 8($s0)
  lw    $t8, 0x14($s0)
  move  $a2, $s3
  jal   memcpy
   addu  $a0, $t9, $t8
  lw    $t6, 0x14($s0)
  lw    $t9, 0x24($s0)
  addu  $t7, $t6, $s3
  subu  $t8, $t9, $s3
  sw    $t7, 0x14($s0)
  sw    $t8, 0x18($s0)
  lw    $t6, 8($s0)
.L7001DE28:
  lw    $t7, 0x14($s0)
  addu  $s1, $t6, $t7
  addiu $s1, $s1, 1
  bltz  $s2, .L7001DE4C
   sb    $s4, -1($s1)
  li    $t9, 43
  sb    $t9, ($s1)
  b     .L7001DE68
   addiu $s1, $s1, 1
.L7001DE4C:
  negu  $s2, $s2
  sll   $t6, $s2, 0x10
  li    $t8, 45
  sra   $t7, $t6, 0x10
  sb    $t8, ($s1)
  addiu $s1, $s1, 1
  move  $s2, $t7
.L7001DE68:
  slti  $at, $s2, 0x64
  bnezl $at, .L7001DF18
   li    $v0, 10
  slti  $at, $s2, 0x3e8
  bnez  $at, .L7001DEC8
   li    $v0, 1000
  div   $zero, $s2, $v0
  bnez  $v0, .L7001DE90
   nop   
  break 7
.L7001DE90:
  li    $at, -1
  bne   $v0, $at, .L7001DEA8
   lui   $at, 0x8000
  bne   $s2, $at, .L7001DEA8
   nop   
  break 6
.L7001DEA8:
  mfhi  $s2
  sll   $t6, $s2, 0x10
  mflo  $t9
  addiu $t8, $t9, 0x30
  sra   $t7, $t6, 0x10
  move  $s2, $t7
  sb    $t8, ($s1)
  addiu $s1, $s1, 1
.L7001DEC8:
  li    $v0, 100
  div   $zero, $s2, $v0
  bnez  $v0, .L7001DEDC
   nop   
  break 7
.L7001DEDC:
  li    $at, -1
  bne   $v0, $at, .L7001DEF4
   lui   $at, 0x8000
  bne   $s2, $at, .L7001DEF4
   nop   
  break 6
.L7001DEF4:
  mfhi  $s2
  sll   $t6, $s2, 0x10
  mflo  $t9
  addiu $t8, $t9, 0x30
  sra   $t7, $t6, 0x10
  move  $s2, $t7
  sb    $t8, ($s1)
  addiu $s1, $s1, 1
  li    $v0, 10
.L7001DF18:
  div   $zero, $s2, $v0
  bnez  $v0, .L7001DF28
   nop   
  break 7
.L7001DF28:
  li    $at, -1
  bne   $v0, $at, .L7001DF40
   lui   $at, 0x8000
  bne   $s2, $at, .L7001DF40
   nop   
  break 6
.L7001DF40:
  mfhi  $s2
  sll   $t6, $s2, 0x10
  mflo  $t9
  addiu $t8, $t9, 0x30
  sra   $t7, $t6, 0x10
  addiu $t9, $t7, 0x30
  sb    $t8, ($s1)
  sb    $t9, 1($s1)
  lw    $t8, 8($s0)
  move  $s2, $t7
  lw    $t7, 0x14($s0)
  addiu $s1, $s1, 2
  subu  $t6, $s1, $t8
  subu  $t9, $t6, $t7
  sw    $t9, 0x1c($s0)
.L7001DF7C:
  lw    $t8, 0x30($s0)
  li    $at, 16
  andi  $t6, $t8, 0x14
  bnel  $t6, $at, .L7001DFCC
   lw    $ra, 0x14($sp)
  lw    $t7, 0xc($s0)
  lw    $t9, 0x14($s0)
  lw    $t6, 0x18($s0)
  lw    $v1, 0x28($s0)
  addu  $t8, $t7, $t9
  lw    $t9, 0x1c($s0)
  addu  $t7, $t8, $t6
  lw    $t6, 0x20($s0)
  addu  $t8, $t7, $t9
  addu  $v0, $t8, $t6
  slt   $at, $v0, $v1
  beqz  $at, .L7001DFC8
   subu  $t7, $v1, $v0
  sw    $t7, 0x10($s0)
.L7001DFC8:
  lw    $ra, 0x14($sp)
.L7001DFCC:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   

  jr    $ra
   nop   

glabel _Ldtob
  addiu $sp, $sp, -0xd0
  sw    $ra, 0x3c($sp)
  sw    $s5, 0x38($sp)
  sw    $s4, 0x34($sp)
  sw    $s3, 0x30($sp)
  sw    $s2, 0x2c($sp)
  sw    $s1, 0x28($sp)
  sw    $s0, 0x24($sp)
  sdc1  $f20, 0x18($sp)
  sw    $a0, 0xd0($sp)
  sw    $a1, 0xd4($sp)
  lw    $v0, 0x24($a0)
  addiu $s5, $sp, 0xb0
  ldc1  $f20, ($a0)
  bgez  $v0, .L7001E028
   li    $t7, 6
  b     .L7001E054
   sw    $t7, 0x24($a0)
.L7001E028:
  bnez  $v0, .L7001E054
   lbu   $t8, 0xd7($sp)
  li    $at, 103
  beq   $t8, $at, .L7001E048
   sw    $t8, 0x48($sp)
  li    $at, 71
  bnel  $t8, $at, .L7001E058
   lw    $t6, 0xd0($sp)
.L7001E048:
  lw    $t7, 0xd0($sp)
  li    $t9, 1
  sw    $t9, 0x24($t7)
.L7001E054:
  lw    $t6, 0xd0($sp)
.L7001E058:
  li    $at, 2047
  lhu   $a0, ($t6)
  andi  $v1, $a0, 0x7ff0
  sra   $t8, $v1, 4
  sll   $t9, $t8, 0x10
  sra   $v1, $t9, 0x10
  bne   $v1, $at, .L7001E0D4
   nop   
  sh    $zero, 0x9a($sp)
  lhu   $t8, ($t6)
  li    $v1, 2
  sll   $v0, $v1, 0x10
  andi  $t9, $t8, 0xf
  bnezl $t9, .L7001E0B8
   sra   $t7, $v0, 0x10
  lhu   $t7, 2($t6)
  bnezl $t7, .L7001E0B8
   sra   $t7, $v0, 0x10
  lhu   $t8, 4($t6)
  bnezl $t8, .L7001E0B8
   sra   $t7, $v0, 0x10
  lhu   $t9, 6($t6)
  beqz  $t9, .L7001E0C0
   sra   $t7, $v0, 0x10
.L7001E0B8:
  b     .L7001E10C
   move  $v0, $t7
.L7001E0C0:
  li    $v1, 1
  sll   $v0, $v1, 0x10
  sra   $t7, $v0, 0x10
  b     .L7001E10C
   move  $v0, $t7
.L7001E0D4:
  blez  $v1, .L7001E0F8
   andi  $t8, $a0, 0x800f
  lw    $t9, 0xd0($sp)
  ori   $t6, $t8, 0x3ff0
  addiu $t7, $v1, -0x3fe
  sh    $t6, ($t9)
  sh    $t7, 0x9a($sp)
  b     .L7001E10C
   li    $v0, -1
.L7001E0F8:
  bgez  $v1, .L7001E108
   move  $v0, $zero
  b     .L7001E10C
   li    $v0, 2
.L7001E108:
  sh    $zero, 0x9a($sp)
.L7001E10C:
  blez  $v0, .L7001E158
   sll   $t8, $v0, 0x10
  sll   $t8, $v0, 0x10
  sra   $t6, $t8, 0x10
  li    $at, 2
  bne   $t6, $at, .L7001E134
   lw    $t9, 0xd0($sp)
  lui   $a1, %hi(aNan)
  b     .L7001E13C
   addiu $a1, %lo(aNan) # addiu $a1, $a1, -0x6328
.L7001E134:
  lui   $a1, %hi(aInf)
  addiu $a1, %lo(aInf) # addiu $a1, $a1, -0x6324
.L7001E13C:
  li    $t7, 3
  sw    $t7, 0x14($t9)
  lw    $a0, 8($t9)
  jal   memcpy
   li    $a2, 3
  b     .L7001E508
   lw    $ra, 0x3c($sp)
.L7001E158:
  sra   $t6, $t8, 0x10
  bnez  $t6, .L7001E16C
   move  $s3, $zero
  b     .L7001E4F0
   sh    $zero, 0x9a($sp)
.L7001E16C:
  mtc1  $zero, $f3
  mtc1  $zero, $f2
  lbu   $t7, 0xd7($sp)
  lh    $t9, 0x9a($sp)
  c.lt.d $f20, $f2
  li    $at, 30103
  move  $v1, $zero
  addiu $s5, $sp, 0xb1
  bc1f  .L7001E198
   sw    $t7, 0x48($sp)
  neg.d $f20, $f20
.L7001E198:
  multu $t9, $at
  lui   $at, (0x000186A0 >> 16) # lui $at, 1
  ori   $at, (0x000186A0 & 0xFFFF) # ori $at, $at, 0x86a0
  li    $a1, 6
  mflo  $t8
  nop   
  nop   
  div   $zero, $t8, $at
  mflo  $t6
  addiu $t7, $t6, -4
  sll   $t9, $t7, 0x10
  sra   $t8, $t9, 0x10
  bgez  $t8, .L7001E230
   sh    $t7, 0x9a($sp)
  sll   $t9, $t7, 0x10
  sra   $t8, $t9, 0x10
  li    $t6, 3
  subu  $a0, $t6, $t8
  li    $at, -4
  and   $v0, $a0, $at
  negu  $t9, $v0
  blez  $v0, .L7001E2A0
   sh    $t9, 0x9a($sp)
  lui   $a0, %hi(digits)
  addiu $a0, %lo(digits) # addiu $a0, $a0, -0x6370
.L7001E1FC:
  andi  $t6, $v0, 1
  beqz  $t6, .L7001E21C
   sra   $t9, $v0, 1
  sll   $t8, $v1, 3
  addu  $t7, $a0, $t8
  ldc1  $f4, ($t7)
  mul.d $f20, $f20, $f4
  nop   
.L7001E21C:
  move  $v0, $t9
  bgtz  $t9, .L7001E1FC
   addiu $v1, $v1, 1
  b     .L7001E2A4
   lw    $t7, 0x48($sp)
.L7001E230:
  lh    $t6, 0x9a($sp)
  li    $at, 0x3FF00000 # 1.875000
  move  $v1, $zero
  blez  $t6, .L7001E2A0
   andi  $t8, $t6, 0xfffc
  sll   $v0, $t8, 0x10
  sll   $t9, $t8, 0x10
  mtc1  $at, $f1
  mtc1  $zero, $f0
  sra   $t6, $t9, 0x10
  sra   $t7, $v0, 0x10
  sh    $t8, 0x9a($sp)
  blez  $t6, .L7001E29C
   move  $v0, $t7
  lui   $a0, %hi(digits)
  addiu $a0, %lo(digits) # addiu $a0, $a0, -0x6370
.L7001E270:
  andi  $t7, $v0, 1
  beqz  $t7, .L7001E290
   sra   $t6, $v0, 1
  sll   $t8, $v1, 3
  addu  $t9, $a0, $t8
  ldc1  $f6, ($t9)
  mul.d $f0, $f0, $f6
  nop   
.L7001E290:
  move  $v0, $t6
  bgtz  $t6, .L7001E270
   addiu $v1, $v1, 1
.L7001E29C:
  div.d $f20, $f20, $f0
.L7001E2A0:
  lw    $t7, 0x48($sp)
.L7001E2A4:
  li    $at, 102
  lw    $t8, 0xd0($sp)
  bne   $t7, $at, .L7001E2C0
   li    $t6, 48
  lh    $a1, 0x9a($sp)
  b     .L7001E2C0
   addiu $a1, $a1, 0xa
.L7001E2C0:
  lw    $t9, 0x24($t8)
  addu  $s4, $a1, $t9
  slti  $at, $s4, 0x14
  bnez  $at, .L7001E2D8
   nop   
  li    $s4, 19
.L7001E2D8:
  blez  $s4, .L7001E3A8
   sb    $t6, 0xb0($sp)
  c.lt.d $f2, $f20
  li    $s3, 48
  addiu $s2, $sp, 0x74
  bc1fl .L7001E3AC
   lh    $t8, 0x9a($sp)
  trunc.w.d $f8, $f20
.L7001E2F8:
  addiu $s4, $s4, -8
  addiu $s5, $s5, 8
  mfc1  $s1, $f8
  blez  $s4, .L7001E328
   nop   
  mtc1  $s1, $f10
  lui   $at, %hi(F64_80029CE8)
  ldc1  $f8, %lo(F64_80029CE8)($at)
  cvt.d.w $f4, $f10
  sub.d $f6, $f20, $f4
  mul.d $f20, $f6, $f8
  nop   
.L7001E328:
  blez  $s1, .L7001E370
   li    $s0, 8
  li    $s0, 7
  bltz  $s0, .L7001E370
   move  $a0, $s2
.L7001E33C:
  move  $a1, $s1
  jal   ldiv
   li    $a2, 10
  lw    $t8, 0x78($sp)
  addiu $s5, $s5, -1
  addiu $t9, $t8, 0x30
  sb    $t9, ($s5)
  lw    $s1, 0x74($sp)
  blezl $s1, .L7001E374
   mtc1  $zero, $f3
  addiu $s0, $s0, -1
  bgezl $s0, .L7001E33C
   move  $a0, $s2
.L7001E370:
  mtc1  $zero, $f3
.L7001E374:
  mtc1  $zero, $f2
  addiu $s0, $s0, -1
  bltz  $s0, .L7001E390
.L7001E380:
   addiu $s0, $s0, -1
  addiu $s5, $s5, -1
  bgez  $s0, .L7001E380
   sb    $s3, ($s5)
.L7001E390:
  blez  $s4, .L7001E3A8
   addiu $s5, $s5, 8
  c.lt.d $f2, $f20
  nop   
  bc1tl .L7001E2F8
   trunc.w.d $f8, $f20
.L7001E3A8:
  lh    $t8, 0x9a($sp)
.L7001E3AC:
  lbu   $t6, 0xb1($sp)
  addiu $t7, $sp, 0xb0
  li    $v0, 48
  subu  $s4, $s5, $t7
  addiu $t9, $t8, 7
  addiu $s4, $s4, -1
  sh    $t9, 0x9a($sp)
  bne   $v0, $t6, .L7001E3F0
   addiu $s5, $sp, 0xb1
  lh    $t7, 0x9a($sp)
.L7001E3D4:
  addiu $s5, $s5, 1
  addiu $s4, $s4, -1
  addiu $t8, $t7, -1
  sh    $t8, 0x9a($sp)
  lbu   $t9, ($s5)
  beql  $v0, $t9, .L7001E3D4
   lh    $t7, 0x9a($sp)
.L7001E3F0:
  lw    $t6, 0x48($sp)
  li    $at, 102
  lw    $t8, 0xd0($sp)
  bne   $t6, $at, .L7001E410
   lw    $t7, 0x48($sp)
  lh    $a1, 0x9a($sp)
  b     .L7001E430
   addiu $a1, $a1, 1
.L7001E410:
  li    $at, 101
  beq   $t7, $at, .L7001E424
   li    $at, 69
  bne   $t7, $at, .L7001E42C
   move  $v0, $zero
.L7001E424:
  b     .L7001E42C
   li    $v0, 1
.L7001E42C:
  move  $a1, $v0
.L7001E430:
  lw    $t9, 0x24($t8)
  addu  $s3, $a1, $t9
  sll   $t6, $s3, 0x10
  sra   $s3, $t6, 0x10
  slt   $at, $s4, $s3
  beqz  $at, .L7001E458
   nop   
  sll   $s3, $s4, 0x10
  sra   $t8, $s3, 0x10
  move  $s3, $t8
.L7001E458:
  blez  $s3, .L7001E4F0
   slt   $at, $s3, $s4
  beqz  $at, .L7001E480
   addu  $v0, $s3, $s5
  lbu   $t9, ($v0)
  slti  $at, $t9, 0x35
  bnezl $at, .L7001E484
   li    $a1, 48
  b     .L7001E488
   li    $a1, 57
.L7001E480:
  li    $a1, 48
.L7001E484:
  addu  $v0, $s3, $s5
.L7001E488:
  lbu   $t6, -1($v0)
  addiu $v1, $s3, -1
  move  $a0, $a1
  bne   $a1, $t6, .L7001E4BC
   li    $at, 57
  addu  $v0, $v1, $s5
.L7001E4A0:
  lbu   $t9, -1($v0)
  addiu $s3, $s3, -1
  sll   $t7, $s3, 0x10
  addiu $v1, $v1, -1
  addiu $v0, $v0, -1
  beq   $a0, $t9, .L7001E4A0
   sra   $s3, $t7, 0x10
.L7001E4BC:
  bne   $a0, $at, .L7001E4D0
   addu  $v0, $s5, $v1
  lbu   $t6, ($v0)
  addiu $t7, $t6, 1
  sb    $t7, ($v0)
.L7001E4D0:
  bgez  $v1, .L7001E4F0
   lh    $t6, 0x9a($sp)
  addiu $s3, $s3, 1
  sll   $t8, $s3, 0x10
  addiu $t7, $t6, 1
  sh    $t7, 0x9a($sp)
  sra   $s3, $t8, 0x10
  addiu $s5, $s5, -1
.L7001E4F0:
  lw    $s0, 0xd0($sp)
  lbu   $s4, 0xd7($sp)
  move  $s1, $s5
  jal   xldtob_sub0
   lh    $s2, 0x9a($sp)
  lw    $ra, 0x3c($sp)
.L7001E508:
  ldc1  $f20, 0x18($sp)
  lw    $s0, 0x24($sp)
  lw    $s1, 0x28($sp)
  lw    $s2, 0x2c($sp)
  lw    $s3, 0x30($sp)
  lw    $s4, 0x34($sp)
  lw    $s5, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0xd0

  nop   
.section .rodata
glabel asc_D_80029CE0
 .ascii "0"<0>
 .align 3
glabel F64_80029CE8
 .double 1.0e8

.section .text
glabel osEPiRawStartDma
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
  beqz  $t7, .L7001E578
   nop   
.L7001E564:
  lui   $t8, %hi(PI_STATUS_REG) # $t8, 0xa460
  lw    $s0, %lo(PI_STATUS_REG)($t8)
  andi  $t9, $s0, 3
  bnez  $t9, .L7001E564
   nop   
.L7001E578:
  jal   osVirtualToPhysical
   lw    $a0, 0x34($sp)
  lui   $t0, 0xa460
  sw    $v0, ($t0)
  lw    $t1, 0x28($sp)
  lw    $t3, 0x30($sp)
  lui   $at, (0x1FFFFFFF >> 16) # lui $at, 0x1fff
  lw    $t2, 0xc($t1)
  ori   $at, (0x1FFFFFFF & 0xFFFF) # ori $at, $at, 0xffff
  lui   $t6, %hi(PI_CART_ADDR_REG) # $t6, 0xa460
  or    $t4, $t2, $t3
  and   $t5, $t4, $at
  sw    $t5, %lo(PI_CART_ADDR_REG)($t6)
  lw    $s1, 0x2c($sp)
  beqz  $s1, .L7001E5C8
   li    $at, 1
  beq   $s1, $at, .L7001E5DC
   nop   
  b     .L7001E5F0
   nop   
.L7001E5C8:
  lw    $t7, 0x38($sp)
  lui   $t9, %hi(PI_WR_LEN_REG) # $t9, 0xa460
  addiu $t8, $t7, -1
  b     .L7001E5F8
   sw    $t8, %lo(PI_WR_LEN_REG)($t9)
.L7001E5DC:
  lw    $t0, 0x38($sp)
  lui   $t2, %hi(PI_RD_LEN_REG) # $t2, 0xa460
  addiu $t1, $t0, -1
  b     .L7001E5F8
   sw    $t1, %lo(PI_RD_LEN_REG)($t2)
.L7001E5F0:
  b     .L7001E5FC
   li    $v0, -1
.L7001E5F8:
  move  $v0, $zero
.L7001E5FC:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x28

glabel __osDevMgrMain
  addiu $sp, $sp, -0x40
  sw    $a0, 0x40($sp)
  lw    $t6, 0x40($sp)
  sw    $ra, 0x1c($sp)
  sw    $zero, 0x28($sp)
  sw    $zero, 0x3c($sp)
  sw    $zero, 0x30($sp)
  sw    $t6, 0x2c($sp)
.L7001E630:
  lw    $t7, 0x2c($sp)
  addiu $a1, $sp, 0x3c
  li    $a2, 1
  jal   osRecvMesg
   lw    $a0, 8($t7)
  lw    $t8, 0x3c($sp)
  lw    $t9, 0x14($t8)
  beqz  $t9, .L7001E7E4
   nop   
  lbu   $t0, 4($t9)
  li    $at, 2
  bne   $t0, $at, .L7001E7E4
   nop   
  lw    $t1, 0x14($t9)
  beqz  $t1, .L7001E678
   li    $at, 1
  bne   $t1, $at, .L7001E7E4
   nop   
.L7001E678:
  lw    $t2, 0x3c($sp)
  li    $t0, -1
  li    $at, 3
  lw    $t3, 0x14($t2)
  addiu $t4, $t3, 0x14
  sw    $t4, 0x20($sp)
  lhu   $t5, 6($t4)
  sll   $t6, $t5, 3
  addu  $t6, $t6, $t5
  sll   $t6, $t6, 2
  addu  $t7, $t4, $t6
  addiu $t8, $t7, 0x18
  sw    $t8, 0x24($sp)
  sw    $t0, 8($t4)
  lw    $t9, 0x20($sp)
  lhu   $t1, 4($t9)
  beq   $t1, $at, .L7001E6D4
   nop   
  lw    $t2, 0x24($sp)
  lw    $t3, 4($t2)
  lw    $t5, 0xc($t2)
  subu  $t6, $t3, $t5
  sw    $t6, 4($t2)
.L7001E6D4:
  lw    $t7, 0x20($sp)
  li    $at, 2
  lhu   $t8, 4($t7)
  bne   $t8, $at, .L7001E708
   nop   
  lw    $t0, 0x3c($sp)
  lw    $t4, 0x14($t0)
  lw    $t9, 0x14($t4)
  bnez  $t9, .L7001E708
   nop   
  li    $t1, 1
  b     .L7001E70C
   sw    $t1, 0x28($sp)
.L7001E708:
  sw    $zero, 0x28($sp)
.L7001E70C:
  lw    $t3, 0x2c($sp)
  addiu $a1, $sp, 0x34
  li    $a2, 1
  jal   osRecvMesg
   lw    $a0, 0x10($t3)
  lui   $a0, (0x00100401 >> 16) # lui $a0, 0x10
  jal   __osResetGlobalIntMask
   ori   $a0, (0x00100401 & 0xFFFF) # ori $a0, $a0, 0x401
  lw    $t6, 0x20($sp)
  lw    $t5, 0x3c($sp)
  lui   $at, 0x8000
  lw    $a2, 0x10($t6)
  lui   $a1, (0x05000510 >> 16) # lui $a1, 0x500
  ori   $a1, (0x05000510 & 0xFFFF) # ori $a1, $a1, 0x510
  or    $t2, $a2, $at
  move  $a2, $t2
  jal   osEPiRawWriteIo
   lw    $a0, 0x14($t5)
.L7001E754:
  lw    $t7, 0x2c($sp)
  addiu $a1, $sp, 0x38
  li    $a2, 1
  jal   osRecvMesg
   lw    $a0, 0xc($t7)
  lw    $t8, 0x3c($sp)
  move  $a2, $zero
  lw    $a0, 4($t8)
  jal   osSendMesg
   move  $a1, $t8
  lw    $t0, 0x28($sp)
  li    $at, 1
  bne   $t0, $at, .L7001E7A8
   nop   
  lw    $t4, 0x3c($sp)
  lw    $t9, 0x14($t4)
  lw    $t1, 0x2c($t9)
  bnez  $t1, .L7001E7A8
   nop   
  b     .L7001E754
   sw    $zero, 0x28($sp)
.L7001E7A8:
  lw    $t3, 0x2c($sp)
  move  $a1, $zero
  move  $a2, $zero
  jal   osSendMesg
   lw    $a0, 0x10($t3)
  lw    $t5, 0x3c($sp)
  li    $at, 1
  lw    $t6, 0x14($t5)
  lhu   $t2, 0x1a($t6)
  bne   $t2, $at, .L7001E630
   nop   
  jal   osYieldThread
   nop   
  b     .L7001E630
   nop   
.L7001E7E4:
  lw    $t7, 0x3c($sp)
  lhu   $t8, ($t7)
  addiu $t0, $t8, -0xa
  sltiu $at, $t0, 7
  beqz  $at, .L7001E940
   nop   
  sll   $t0, $t0, 2
  lui   $at, %hi(jpt_80029CF0)
  addu  $at, $at, $t0
  lw    $t0, %lo(jpt_80029CF0)($at)
  jr    $t0
   nop   
.L7001E814:
  lw    $t4, 0x2c($sp)
  addiu $a1, $sp, 0x34
  li    $a2, 1
  jal   osRecvMesg
   lw    $a0, 0x10($t4)
  lw    $t9, 0x3c($sp)
  lw    $t1, 0x2c($sp)
  move  $a0, $zero
  lw    $a1, 0xc($t9)
  lw    $a2, 8($t9)
  lw    $a3, 0x10($t9)
  lw    $t9, 0x14($t1)
  jalr  $t9
  nop   
  b     .L7001E948
   sw    $v0, 0x30($sp)
.L7001E854:
  lw    $t3, 0x2c($sp)
  addiu $a1, $sp, 0x34
  li    $a2, 1
  jal   osRecvMesg
   lw    $a0, 0x10($t3)
  lw    $t6, 0x2c($sp)
  lw    $t5, 0x3c($sp)
  li    $a0, 1
  lw    $t9, 0x14($t6)
  lw    $a1, 0xc($t5)
  lw    $a2, 8($t5)
  jalr  $t9
  lw    $a3, 0x10($t5)
  b     .L7001E948
   sw    $v0, 0x30($sp)
.L7001E890:
  lw    $t2, 0x2c($sp)
  addiu $a1, $sp, 0x34
  li    $a2, 1
  jal   osRecvMesg
   lw    $a0, 0x10($t2)
  lw    $t7, 0x3c($sp)
  lw    $t0, 0x2c($sp)
  move  $a1, $zero
  lw    $t8, 0x10($t7)
  lw    $a0, 0x14($t7)
  lw    $a2, 0xc($t7)
  lw    $a3, 8($t7)
  sw    $t8, 0x10($sp)
  lw    $t9, 0x18($t0)
  jalr  $t9
  nop   
  b     .L7001E948
   sw    $v0, 0x30($sp)
.L7001E8D8:
  lw    $t4, 0x2c($sp)
  addiu $a1, $sp, 0x34
  li    $a2, 1
  jal   osRecvMesg
   lw    $a0, 0x10($t4)
  lw    $t1, 0x3c($sp)
  lw    $t5, 0x2c($sp)
  li    $a1, 1
  lw    $t3, 0x10($t1)
  lw    $a0, 0x14($t1)
  lw    $a2, 0xc($t1)
  lw    $a3, 8($t1)
  sw    $t3, 0x10($sp)
  lw    $t9, 0x18($t5)
  jalr  $t9
  nop   
  b     .L7001E948
   sw    $v0, 0x30($sp)
.L7001E920:
  lw    $t6, 0x3c($sp)
  move  $a2, $zero
  lw    $a0, 4($t6)
  jal   osSendMesg
   move  $a1, $t6
  li    $t2, -1
  b     .L7001E948
   sw    $t2, 0x30($sp)
.L7001E940:
  li    $t7, -1
  sw    $t7, 0x30($sp)
.L7001E948:
  lw    $t8, 0x30($sp)
  bnez  $t8, .L7001E630
   nop   
  lw    $t0, 0x2c($sp)
  addiu $a1, $sp, 0x38
  li    $a2, 1
  jal   osRecvMesg
   lw    $a0, 0xc($t0)
  lw    $t4, 0x3c($sp)
  move  $a2, $zero
  lw    $a0, 4($t4)
  jal   osSendMesg
   move  $a1, $t4
  lw    $t1, 0x2c($sp)
  move  $a1, $zero
  move  $a2, $zero
  jal   osSendMesg
   lw    $a0, 0x10($t1)
  b     .L7001E630
   nop   
  nop   
  nop   
  nop   
  nop   
  nop   
  nop   
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x40
  jr    $ra
   nop   
.section .rodata
glabel jpt_80029CF0
 .word .L7001E920
 .word .L7001E814
 .word .L7001E854
 .word .L7001E940
 .word .L7001E940
 .word .L7001E890
 .word .L7001E8D8
.align 4

.section .text
glabel __osSumcalc
  addiu $sp, $sp, -0x10
  sw    $zero, 8($sp)
  sw    $a0, 4($sp)
  blez  $a1, .L7001EA10
   sw    $zero, 0xc($sp)
.L7001E9D4:
  lw    $t7, 4($sp)
  lw    $t6, 8($sp)
  lw    $t3, 0xc($sp)
  lbu   $t8, ($t7)
  addiu $t0, $t7, 1
  addiu $t4, $t3, 1
  addu  $t9, $t6, $t8
  sw    $t9, 8($sp)
  lw    $t1, 8($sp)
  slt   $at, $t4, $a1
  sw    $t4, 0xc($sp)
  andi  $t2, $t1, 0xffff
  sw    $t0, 4($sp)
  bnez  $at, .L7001E9D4
   sw    $t2, 8($sp)
.L7001EA10:
  lhu   $v0, 0xa($sp)
  jr    $ra
   addiu $sp, $sp, 0x10

glabel __osIdCheckSum
  addiu $sp, $sp, -8
  sh    $zero, 6($sp)
  sh    $zero, ($a2)
  lhu   $t6, ($a2)
  sh    $t6, ($a1)
  sw    $zero, ($sp)
.L7001EA34:
  lw    $t7, ($sp)
  addu  $t8, $a0, $t7
  lhu   $t9, ($t8)
  sh    $t9, 6($sp)
  lhu   $t0, ($a1)
  addu  $t1, $t0, $t9
  sh    $t1, ($a1)
  lhu   $t3, 6($sp)
  lhu   $t2, ($a2)
  not   $t4, $t3
  addu  $t5, $t2, $t4
  sh    $t5, ($a2)
  lw    $t6, ($sp)
  addiu $t7, $t6, 2
  sltiu $at, $t7, 0x1c
  bnez  $at, .L7001EA34
   sw    $t7, ($sp)
  move  $v0, $zero
  jr    $ra
   addiu $sp, $sp, 8

glabel __osRepairPackId
  addiu $sp, $sp, -0x78
  sw    $a0, 0x78($sp)
  lw    $t6, 0x78($sp)
  sw    $ra, 0x1c($sp)
  sw    $a1, 0x7c($sp)
  sw    $a2, 0x80($sp)
  sw    $zero, 0x74($sp)
  sb    $zero, 0x33($sp)
  lbu   $t7, 0x65($t6)
  beqz  $t7, .L7001EAD4
   nop   
  sb    $zero, 0x65($t6)
  jal   __osPfsSelectBank
   lw    $a0, 0x78($sp)
  sw    $v0, 0x74($sp)
  lw    $t8, 0x74($sp)
  beqz  $t8, .L7001EAD4
   nop   
  b     .L7001EE8C
   move  $v0, $t8
.L7001EAD4:
  lw    $t0, 0x80($sp)
  li    $t9, -1
  jal   osGetCount
   sw    $t9, ($t0)
  lw    $t1, 0x80($sp)
  sw    $v0, 4($t1)
  lw    $t2, 0x7c($sp)
  lw    $t3, 0x80($sp)
  lw    $t4, 8($t2)
  lw    $t5, 0xc($t2)
  sw    $t4, 8($t3)
  sw    $t5, 0xc($t3)
  lw    $t7, 0x7c($sp)
  lw    $t8, 0x80($sp)
  lw    $t6, 0x10($t7)
  lw    $t7, 0x14($t7)
  sw    $t6, 0x10($t8)
  sw    $t7, 0x14($t8)
  sw    $zero, 0x28($sp)
.L7001EB20:
  lw    $t9, 0x28($sp)
  lw    $t0, 0x78($sp)
  sb    $t9, 0x65($t0)
  jal   __osPfsSelectBank
   lw    $a0, 0x78($sp)
  sw    $v0, 0x74($sp)
  lw    $t1, 0x74($sp)
  beqz  $t1, .L7001EB4C
   nop   
  b     .L7001EE8C
   move  $v0, $t1
.L7001EB4C:
  lw    $t2, 0x78($sp)
  move  $a2, $zero
  addiu $a3, $sp, 0x54
  lw    $a0, 4($t2)
  jal   __osContRamRead
   lw    $a1, 8($t2)
  sw    $v0, 0x74($sp)
  lw    $t4, 0x74($sp)
  beqz  $t4, .L7001EB7C
   nop   
  b     .L7001EE8C
   move  $v0, $t4
.L7001EB7C:
  lw    $t5, 0x28($sp)
  addiu $t6, $sp, 0x54
  li    $t7, 1
  ori   $t3, $t5, 0x80
  sb    $t3, ($t6)
  sw    $t7, 0x2c($sp)
.L7001EB94:
  lw    $t8, 0x2c($sp)
  addiu $t9, $sp, 0x54
  addu  $t0, $t8, $t9
  lbu   $t1, ($t0)
  not   $t2, $t1
  sb    $t2, ($t0)
  lw    $t4, 0x2c($sp)
  addiu $t5, $t4, 1
  slti  $at, $t5, 0x20
  bnez  $at, .L7001EB94
   sw    $t5, 0x2c($sp)
  lw    $t3, 0x78($sp)
  move  $a2, $zero
  addiu $a3, $sp, 0x54
  lw    $a0, 4($t3)
  lw    $a1, 8($t3)
  jal   __osContRamWrite
   sw    $zero, 0x10($sp)
  sw    $v0, 0x74($sp)
  lw    $t6, 0x74($sp)
  beqz  $t6, .L7001EBF4
   nop   
  b     .L7001EE8C
   move  $v0, $t6
.L7001EBF4:
  lw    $t7, 0x78($sp)
  move  $a2, $zero
  addiu $a3, $sp, 0x34
  lw    $a0, 4($t7)
  jal   __osContRamRead
   lw    $a1, 8($t7)
  sw    $v0, 0x74($sp)
  lw    $t8, 0x74($sp)
  beqz  $t8, .L7001EC24
   nop   
  b     .L7001EE8C
   move  $v0, $t8
.L7001EC24:
  sw    $zero, 0x2c($sp)
.L7001EC28:
  lw    $t9, 0x2c($sp)
  addu  $t1, $sp, $t9
  addu  $t2, $sp, $t9
  lbu   $t2, 0x34($t2)
  lbu   $t1, 0x54($t1)
  bne   $t1, $t2, .L7001EC58
   nop   
  lw    $t0, 0x2c($sp)
  addiu $t4, $t0, 1
  slti  $at, $t4, 0x20
  bnez  $at, .L7001EC28
   sw    $t4, 0x2c($sp)
.L7001EC58:
  lw    $t5, 0x2c($sp)
  li    $at, 32
  bne   $t5, $at, .L7001ECFC
   nop   
  lw    $t3, 0x28($sp)
  blez  $t3, .L7001ECE0
   nop   
  lw    $t6, 0x78($sp)
  sb    $zero, 0x65($t6)
  jal   __osPfsSelectBank
   lw    $a0, 0x78($sp)
  sw    $v0, 0x74($sp)
  lw    $t7, 0x74($sp)
  beqz  $t7, .L7001EC9C
   nop   
  b     .L7001EE8C
   move  $v0, $t7
.L7001EC9C:
  lw    $t8, 0x78($sp)
  move  $a2, $zero
  addiu $a3, $sp, 0x54
  lw    $a0, 4($t8)
  jal   __osContRamRead
   lw    $a1, 8($t8)
  sw    $v0, 0x74($sp)
  lw    $t9, 0x74($sp)
  beqz  $t9, .L7001ECCC
   nop   
  b     .L7001EE8C
   move  $v0, $t9
.L7001ECCC:
  addiu $t1, $sp, 0x54
  lbu   $t2, ($t1)
  li    $at, 128
  bne   $t2, $at, .L7001ECFC
   nop   
.L7001ECE0:
  lw    $t0, 0x28($sp)
  addiu $t4, $t0, 1
  sw    $t4, 0x28($sp)
  lw    $t5, 0x28($sp)
  slti  $at, $t5, 0x3e
  bnez  $at, .L7001EB20
   nop   
.L7001ECFC:
  lw    $t3, 0x78($sp)
  sb    $zero, 0x65($t3)
  jal   __osPfsSelectBank
   lw    $a0, 0x78($sp)
  sw    $v0, 0x74($sp)
  lw    $t6, 0x74($sp)
  beqz  $t6, .L7001ED24
   nop   
  b     .L7001EE8C
   move  $v0, $t6
.L7001ED24:
  lw    $t7, 0x28($sp)
  blez  $t7, .L7001ED3C
   nop   
  li    $t8, 1
  b     .L7001ED40
   sb    $t8, 0x33($sp)
.L7001ED3C:
  sb    $zero, 0x33($sp)
.L7001ED40:
  lw    $t9, 0x7c($sp)
  lbu   $t0, 0x33($sp)
  lw    $t5, 0x80($sp)
  lhu   $t1, 0x18($t9)
  andi  $t2, $t1, 0xfffe
  or    $t4, $t2, $t0
  sh    $t4, 0x18($t5)
  lw    $t6, 0x80($sp)
  lw    $t3, 0x28($sp)
  sb    $t3, 0x1a($t6)
  lw    $t7, 0x7c($sp)
  lw    $t9, 0x80($sp)
  lbu   $t8, 0x1b($t7)
  sb    $t8, 0x1b($t9)
  lw    $t1, 0x80($sp)
  move  $a0, $t1
  addiu $a1, $t1, 0x1c
  jal   __osIdCheckSum
   addiu $a2, $t1, 0x1e
  li    $t2, 1
  addiu $t0, $sp, 0x20
  sh    $t2, ($t0)
  li    $t4, 3
  addiu $t5, $sp, 0x20
  sh    $t4, 2($t5)
  li    $t3, 4
  addiu $t6, $sp, 0x20
  sh    $t3, 4($t6)
  li    $t7, 6
  addiu $t8, $sp, 0x20
  sh    $t7, 6($t8)
  sw    $zero, 0x2c($sp)
.L7001EDC0:
  lw    $t1, 0x2c($sp)
  lw    $t9, 0x78($sp)
  li    $t0, 1
  sll   $t2, $t1, 1
  addu  $a2, $sp, $t2
  lhu   $a2, 0x20($a2)
  lw    $a0, 4($t9)
  lw    $a1, 8($t9)
  sw    $t0, 0x10($sp)
  jal   __osContRamWrite
   lw    $a3, 0x80($sp)
  sw    $v0, 0x74($sp)
  lw    $t4, 0x74($sp)
  beqz  $t4, .L7001EE04
   nop   
  b     .L7001EE8C
   move  $v0, $t4
.L7001EE04:
  lw    $t5, 0x2c($sp)
  addiu $t3, $t5, 1
  slti  $at, $t3, 4
  bnez  $at, .L7001EDC0
   sw    $t3, 0x2c($sp)
  lw    $t6, 0x78($sp)
  li    $a2, 1
  addiu $a3, $sp, 0x54
  lw    $a0, 4($t6)
  jal   __osContRamRead
   lw    $a1, 8($t6)
  sw    $v0, 0x74($sp)
  lw    $t7, 0x74($sp)
  beqz  $t7, .L7001EE48
   nop   
  b     .L7001EE8C
   move  $v0, $t7
.L7001EE48:
  sw    $zero, 0x2c($sp)
.L7001EE4C:
  lw    $t9, 0x2c($sp)
  lw    $t8, 0x80($sp)
  addu  $t0, $sp, $t9
  addu  $t1, $t8, $t9
  lbu   $t2, ($t1)
  lbu   $t0, 0x54($t0)
  beq   $t2, $t0, .L7001EE74
   nop   
  b     .L7001EE8C
   li    $v0, 10
.L7001EE74:
  lw    $t4, 0x2c($sp)
  addiu $t5, $t4, 1
  slti  $at, $t5, 0x20
  bnez  $at, .L7001EE4C
   sw    $t5, 0x2c($sp)
  move  $v0, $zero
.L7001EE8C:
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x78
  jr    $ra
   nop   

glabel __osCheckPackId
  addiu $sp, $sp, -0x38
  sw    $a0, 0x38($sp)
  lw    $t6, 0x38($sp)
  sw    $ra, 0x1c($sp)
  sw    $a1, 0x3c($sp)
  sw    $zero, 0x2c($sp)
  lbu   $t7, 0x65($t6)
  beqz  $t7, .L7001EEE4
   nop   
  sb    $zero, 0x65($t6)
  jal   __osPfsSelectBank
   lw    $a0, 0x38($sp)
  sw    $v0, 0x2c($sp)
  lw    $t8, 0x2c($sp)
  beqz  $t8, .L7001EEE4
   nop   
  b     .L7001F024
   move  $v0, $t8
.L7001EEE4:
  li    $t9, 1
  addiu $t0, $sp, 0x30
  sh    $t9, ($t0)
  li    $t1, 3
  addiu $t2, $sp, 0x30
  sh    $t1, 2($t2)
  li    $t3, 4
  addiu $t4, $sp, 0x30
  sh    $t3, 4($t4)
  li    $t5, 6
  addiu $t7, $sp, 0x30
  sh    $t5, 6($t7)
  li    $t6, 1
  sw    $t6, 0x24($sp)
.L7001EF1C:
  lw    $t9, 0x24($sp)
  lw    $t8, 0x38($sp)
  lw    $a3, 0x3c($sp)
  sll   $t0, $t9, 1
  addu  $a2, $sp, $t0
  lhu   $a2, 0x30($a2)
  lw    $a0, 4($t8)
  jal   __osContRamRead
   lw    $a1, 8($t8)
  sw    $v0, 0x2c($sp)
  lw    $t1, 0x2c($sp)
  beqz  $t1, .L7001EF58
   nop   
  b     .L7001F024
   move  $v0, $t1
.L7001EF58:
  lw    $a0, 0x3c($sp)
  addiu $a1, $sp, 0x2a
  jal   __osIdCheckSum
   addiu $a2, $sp, 0x28
  lw    $t2, 0x3c($sp)
  lhu   $t4, 0x2a($sp)
  lhu   $t3, 0x1c($t2)
  bne   $t3, $t4, .L7001EF8C
   nop   
  lhu   $t5, 0x1e($t2)
  lhu   $t7, 0x28($sp)
  beq   $t5, $t7, .L7001EFA0
   nop   
.L7001EF8C:
  lw    $t6, 0x24($sp)
  addiu $t8, $t6, 1
  slti  $at, $t8, 4
  bnez  $at, .L7001EF1C
   sw    $t8, 0x24($sp)
.L7001EFA0:
  lw    $t9, 0x24($sp)
  li    $at, 4
  bne   $t9, $at, .L7001EFB8
   nop   
  b     .L7001F024
   li    $v0, 10
.L7001EFB8:
  sw    $zero, 0x20($sp)
.L7001EFBC:
  lw    $t0, 0x20($sp)
  lw    $t1, 0x24($sp)
  beq   $t0, $t1, .L7001F00C
   nop   
  lw    $t3, 0x38($sp)
  sll   $t4, $t0, 1
  addu  $a2, $sp, $t4
  lhu   $a2, 0x30($a2)
  li    $t2, 1
  lw    $a0, 4($t3)
  lw    $a1, 8($t3)
  sw    $t2, 0x10($sp)
  jal   __osContRamWrite
   lw    $a3, 0x3c($sp)
  sw    $v0, 0x2c($sp)
  lw    $t5, 0x2c($sp)
  beqz  $t5, .L7001F00C
   nop   
  b     .L7001F024
   move  $v0, $t5
.L7001F00C:
  lw    $t7, 0x20($sp)
  addiu $t6, $t7, 1
  slti  $at, $t6, 4
  bnez  $at, .L7001EFBC
   sw    $t6, 0x20($sp)
  move  $v0, $zero
.L7001F024:
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   

glabel __osGetId
  addiu $sp, $sp, -0x68
  sw    $a0, 0x68($sp)
  lw    $t6, 0x68($sp)
  sw    $ra, 0x14($sp)
  lbu   $t7, 0x65($t6)
  beqz  $t7, .L7001F074
   nop   
  sb    $zero, 0x65($t6)
  jal   __osPfsSelectBank
   lw    $a0, 0x68($sp)
  sw    $v0, 0x1c($sp)
  lw    $t8, 0x1c($sp)
  beqz  $t8, .L7001F074
   nop   
  b     .L7001F280
   move  $v0, $t8
.L7001F074:
  lw    $t9, 0x68($sp)
  li    $a2, 1
  addiu $a3, $sp, 0x40
  lw    $a0, 4($t9)
  jal   __osContRamRead
   lw    $a1, 8($t9)
  sw    $v0, 0x1c($sp)
  lw    $t0, 0x1c($sp)
  beqz  $t0, .L7001F0A4
   nop   
  b     .L7001F280
   move  $v0, $t0
.L7001F0A4:
  addiu $a0, $sp, 0x40
  addiu $a1, $sp, 0x62
  jal   __osIdCheckSum
   addiu $a2, $sp, 0x60
  addiu $t1, $sp, 0x40
  sw    $t1, 0x18($sp)
  lhu   $t2, 0x1c($t1)
  lhu   $t3, 0x62($sp)
  bne   $t2, $t3, .L7001F0DC
   nop   
  lhu   $t4, 0x1e($t1)
  lhu   $t5, 0x60($sp)
  beq   $t4, $t5, .L7001F144
   nop   
.L7001F0DC:
  lw    $a0, 0x68($sp)
  jal   __osCheckPackId
   lw    $a1, 0x18($sp)
  sw    $v0, 0x1c($sp)
  lw    $t7, 0x1c($sp)
  li    $at, 10
  bne   $t7, $at, .L7001F130
   nop   
  lw    $a0, 0x68($sp)
  lw    $a1, 0x18($sp)
  jal   __osRepairPackId
   addiu $a2, $sp, 0x20
  sw    $v0, 0x1c($sp)
  lw    $t6, 0x1c($sp)
  beqz  $t6, .L7001F124
   nop   
  b     .L7001F280
   move  $v0, $t6
.L7001F124:
  addiu $t8, $sp, 0x20
  b     .L7001F144
   sw    $t8, 0x18($sp)
.L7001F130:
  lw    $t9, 0x1c($sp)
  beqz  $t9, .L7001F144
   nop   
  b     .L7001F280
   move  $v0, $t9
.L7001F144:
  lw    $t0, 0x18($sp)
  lhu   $t2, 0x18($t0)
  andi  $t3, $t2, 1
  bnez  $t3, .L7001F1A0
   nop   
  lw    $a0, 0x68($sp)
  move  $a1, $t0
  jal   __osRepairPackId
   addiu $a2, $sp, 0x20
  sw    $v0, 0x1c($sp)
  lw    $t1, 0x1c($sp)
  beqz  $t1, .L7001F180
   nop   
  b     .L7001F280
   move  $v0, $t1
.L7001F180:
  addiu $t4, $sp, 0x20
  sw    $t4, 0x18($sp)
  lhu   $t5, 0x18($t4)
  andi  $t7, $t5, 1
  bnez  $t7, .L7001F1A0
   nop   
  b     .L7001F280
   li    $v0, 11
.L7001F1A0:
  sw    $zero, 0x64($sp)
.L7001F1A4:
  lw    $t6, 0x18($sp)
  lw    $t8, 0x64($sp)
  lw    $t3, 0x68($sp)
  addu  $t9, $t6, $t8
  lbu   $t2, ($t9)
  addu  $t0, $t3, $t8
  sb    $t2, 0xc($t0)
  lw    $t1, 0x64($sp)
  addiu $t4, $t1, 1
  slti  $at, $t4, 0x20
  bnez  $at, .L7001F1A4
   sw    $t4, 0x64($sp)
  lw    $t5, 0x18($sp)
  lw    $t6, 0x68($sp)
  li    $a2, 7
  lbu   $t7, 0x1b($t5)
  li    $t5, 16
  sw    $t7, 0x4c($t6)
  lw    $t9, 0x18($sp)
  lw    $t8, 0x68($sp)
  li    $t6, 8
  lbu   $t3, 0x1a($t9)
  sb    $t3, 0x64($t8)
  lw    $t2, 0x68($sp)
  lbu   $t0, 0x64($t2)
  sll   $t1, $t0, 1
  addiu $t4, $t1, 3
  sw    $t4, 0x60($t2)
  lw    $t7, 0x68($sp)
  sw    $t5, 0x50($t7)
  lw    $t9, 0x68($sp)
  sw    $t6, 0x54($t9)
  lw    $t3, 0x68($sp)
  lbu   $t8, 0x64($t3)
  sll   $t0, $t8, 3
  addiu $t1, $t0, 8
  sw    $t1, 0x58($t3)
  lw    $t4, 0x68($sp)
  lbu   $t5, 0x64($t4)
  lw    $t2, 0x58($t4)
  sll   $t7, $t5, 3
  addu  $t6, $t2, $t7
  sw    $t6, 0x5c($t4)
  lw    $t9, 0x68($sp)
  lw    $a0, 4($t9)
  lw    $a1, 8($t9)
  jal   __osContRamRead
   addiu $a3, $t9, 0x2c
  sw    $v0, 0x1c($sp)
  lw    $t8, 0x1c($sp)
  beqz  $t8, .L7001F27C
   nop   
  b     .L7001F280
   move  $v0, $t8
.L7001F27C:
  move  $v0, $zero
.L7001F280:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x68
  jr    $ra
   nop   

glabel __osCheckId
  addiu $sp, $sp, -0x40
  sw    $a0, 0x40($sp)
  lw    $t6, 0x40($sp)
  sw    $ra, 0x14($sp)
  lbu   $t7, 0x65($t6)
  beqz  $t7, .L7001F2D0
   nop   
  sb    $zero, 0x65($t6)
  jal   __osPfsSelectBank
   lw    $a0, 0x40($sp)
  sw    $v0, 0x18($sp)
  lw    $t8, 0x18($sp)
  beqz  $t8, .L7001F2D0
   nop   
  b     .L7001F37C
   move  $v0, $t8
.L7001F2D0:
  lw    $t9, 0x40($sp)
  li    $a2, 1
  addiu $a3, $sp, 0x1c
  lw    $a0, 4($t9)
  jal   __osContRamRead
   lw    $a1, 8($t9)
  sw    $v0, 0x18($sp)
  lw    $t0, 0x18($sp)
  beqz  $t0, .L7001F338
   li    $at, 2
  beq   $t0, $at, .L7001F308
   nop   
  b     .L7001F37C
   move  $v0, $t0
.L7001F308:
  lw    $t1, 0x40($sp)
  li    $a2, 1
  addiu $a3, $sp, 0x1c
  lw    $a0, 4($t1)
  jal   __osContRamRead
   lw    $a1, 8($t1)
  sw    $v0, 0x18($sp)
  lw    $t2, 0x18($sp)
  beqz  $t2, .L7001F338
   nop   
  b     .L7001F37C
   move  $v0, $t2
.L7001F338:
  sw    $zero, 0x3c($sp)
.L7001F33C:
  lw    $t3, 0x3c($sp)
  lw    $t5, 0x40($sp)
  addu  $t4, $sp, $t3
  addu  $t7, $t5, $t3
  lbu   $t6, 0xc($t7)
  lbu   $t4, 0x1c($t4)
  beq   $t4, $t6, .L7001F364
   nop   
  b     .L7001F37C
   li    $v0, 2
.L7001F364:
  lw    $t8, 0x3c($sp)
  addiu $t9, $t8, 1
  slti  $at, $t9, 0x20
  bnez  $at, .L7001F33C
   sw    $t9, 0x3c($sp)
  move  $v0, $zero
.L7001F37C:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x40
  jr    $ra
   nop   

glabel __osPfsRWInode
  addiu $sp, $sp, -0x38
  sw    $a0, 0x38($sp)
  lw    $t6, 0x38($sp)
  sw    $ra, 0x1c($sp)
  sw    $a1, 0x3c($sp)
  sw    $a2, 0x40($sp)
  sw    $a3, 0x44($sp)
  lbu   $t7, 0x65($t6)
  beqz  $t7, .L7001F3D8
   nop   
  sb    $zero, 0x65($t6)
  jal   __osPfsSelectBank
   lw    $a0, 0x38($sp)
  sw    $v0, 0x2c($sp)
  lw    $t8, 0x2c($sp)
  beqz  $t8, .L7001F3D8
   nop   
  b     .L7001F69C
   move  $v0, $t8
.L7001F3D8:
  lbu   $t9, 0x47($sp)
  blez  $t9, .L7001F3F0
   nop   
  li    $t0, 1
  b     .L7001F3FC
   sw    $t0, 0x28($sp)
.L7001F3F0:
  lw    $t1, 0x38($sp)
  lw    $t2, 0x60($t1)
  sw    $t2, 0x28($sp)
.L7001F3FC:
  lbu   $t3, 0x43($sp)
  li    $at, 1
  bne   $t3, $at, .L7001F438
   nop   
  lw    $t5, 0x28($sp)
  lw    $t4, 0x3c($sp)
  negu  $a1, $t5
  sll   $t6, $a1, 1
  move  $a1, $t6
  sll   $t7, $t5, 1
  addiu $a1, $a1, 0x100
  jal   __osSumcalc
   addu  $a0, $t4, $t7
  lw    $t8, 0x3c($sp)
  sb    $v0, 1($t8)
.L7001F438:
  sw    $zero, 0x30($sp)
.L7001F43C:
  lw    $t0, 0x30($sp)
  lw    $t9, 0x3c($sp)
  lbu   $t3, 0x43($sp)
  sll   $t1, $t0, 5
  li    $at, 1
  addu  $t2, $t9, $t1
  bne   $t3, $at, .L7001F4C4
   sw    $t2, 0x24($sp)
  lw    $t4, 0x38($sp)
  lbu   $t5, 0x47($sp)
  move  $a3, $t2
  lw    $t7, 0x54($t4)
  sll   $t6, $t5, 3
  lw    $a0, 4($t4)
  lw    $a1, 8($t4)
  addu  $t8, $t7, $t6
  addu  $a2, $t8, $t0
  jal   __osContRamWrite
   sw    $zero, 0x10($sp)
  lw    $t9, 0x38($sp)
  lbu   $t3, 0x47($sp)
  sw    $v0, 0x2c($sp)
  lw    $t1, 0x58($t9)
  lw    $t7, 0x30($sp)
  sll   $t4, $t3, 3
  lw    $a1, 8($t9)
  lw    $a0, 4($t9)
  addu  $t5, $t1, $t4
  sw    $zero, 0x10($sp)
  lw    $a3, 0x24($sp)
  jal   __osContRamWrite
   addu  $a2, $t5, $t7
  b     .L7001F4F4
   sw    $v0, 0x2c($sp)
.L7001F4C4:
  lw    $t6, 0x38($sp)
  lbu   $t0, 0x47($sp)
  lw    $t3, 0x30($sp)
  lw    $t8, 0x54($t6)
  sll   $t2, $t0, 3
  lw    $a3, 0x24($sp)
  addu  $t9, $t8, $t2
  lw    $a0, 4($t6)
  lw    $a1, 8($t6)
  jal   __osContRamRead
   addu  $a2, $t9, $t3
  sw    $v0, 0x2c($sp)
.L7001F4F4:
  lw    $t1, 0x2c($sp)
  beqz  $t1, .L7001F508
   nop   
  b     .L7001F69C
   move  $v0, $t1
.L7001F508:
  lw    $t4, 0x30($sp)
  addiu $t5, $t4, 1
  slti  $at, $t5, 8
  bnez  $at, .L7001F43C
   sw    $t5, 0x30($sp)
  lbu   $t7, 0x43($sp)
  bnez  $t7, .L7001F698
   nop   
  lw    $t0, 0x28($sp)
  lw    $t6, 0x3c($sp)
  negu  $a1, $t0
  sll   $t2, $a1, 1
  move  $a1, $t2
  sll   $t8, $t0, 1
  addiu $a1, $a1, 0x100
  jal   __osSumcalc
   addu  $a0, $t6, $t8
  lw    $t9, 0x3c($sp)
  sb    $v0, 0x37($sp)
  lbu   $t1, 0x37($sp)
  lbu   $t3, 1($t9)
  beq   $t3, $t1, .L7001F63C
   nop   
  sw    $zero, 0x30($sp)
.L7001F568:
  lw    $t5, 0x30($sp)
  lw    $t4, 0x3c($sp)
  lw    $t8, 0x38($sp)
  sll   $t7, $t5, 5
  addu  $t6, $t4, $t7
  lbu   $t2, 0x47($sp)
  sw    $t6, 0x24($sp)
  lw    $t0, 0x58($t8)
  sll   $t9, $t2, 3
  move  $a3, $t6
  addu  $t3, $t0, $t9
  addu  $a2, $t3, $t5
  lw    $a1, 8($t8)
  jal   __osContRamRead
   lw    $a0, 4($t8)
  lw    $t1, 0x30($sp)
  sw    $v0, 0x2c($sp)
  addiu $t4, $t1, 1
  slti  $at, $t4, 8
  bnez  $at, .L7001F568
   sw    $t4, 0x30($sp)
  lw    $t7, 0x3c($sp)
  lbu   $t2, 0x37($sp)
  lbu   $t8, 1($t7)
  beq   $t8, $t2, .L7001F5D8
   nop   
  b     .L7001F69C
   li    $v0, 3
.L7001F5D8:
  sw    $zero, 0x30($sp)
.L7001F5DC:
  lw    $t9, 0x30($sp)
  lw    $t0, 0x3c($sp)
  lw    $t6, 0x38($sp)
  sll   $t3, $t9, 5
  addu  $t5, $t0, $t3
  lbu   $t4, 0x47($sp)
  sw    $t5, 0x24($sp)
  lw    $t1, 0x54($t6)
  sll   $t7, $t4, 3
  lw    $a1, 8($t6)
  lw    $a0, 4($t6)
  addu  $t8, $t1, $t7
  sw    $zero, 0x10($sp)
  move  $a3, $t5
  jal   __osContRamWrite
   addu  $a2, $t8, $t9
  lw    $t2, 0x30($sp)
  sw    $v0, 0x2c($sp)
  addiu $t0, $t2, 1
  slti  $at, $t0, 8
  bnez  $at, .L7001F5DC
   sw    $t0, 0x30($sp)
  b     .L7001F698
   nop   
.L7001F63C:
  sw    $zero, 0x30($sp)
.L7001F640:
  lw    $t6, 0x30($sp)
  lw    $t3, 0x3c($sp)
  lw    $t7, 0x38($sp)
  sll   $t4, $t6, 5
  addu  $t1, $t3, $t4
  lbu   $t9, 0x47($sp)
  sw    $t1, 0x24($sp)
  lw    $t8, 0x58($t7)
  sll   $t5, $t9, 3
  lw    $a1, 8($t7)
  lw    $a0, 4($t7)
  addu  $t2, $t8, $t5
  sw    $zero, 0x10($sp)
  move  $a3, $t1
  jal   __osContRamWrite
   addu  $a2, $t2, $t6
  lw    $t0, 0x30($sp)
  sw    $v0, 0x2c($sp)
  addiu $t3, $t0, 1
  slti  $at, $t3, 8
  bnez  $at, .L7001F640
   sw    $t3, 0x30($sp)
.L7001F698:
  move  $v0, $zero
.L7001F69C:
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   

glabel __osPfsSelectBank
  addiu $sp, $sp, -0x48
  sw    $ra, 0x1c($sp)
  sw    $a0, 0x48($sp)
  sw    $zero, 0x20($sp)
  sw    $zero, 0x24($sp)
.L7001F6C0:
  lw    $t6, 0x48($sp)
  lw    $t8, 0x24($sp)
  lbu   $t7, 0x65($t6)
  addu  $t9, $sp, $t8
  sb    $t7, 0x28($t9)
  lw    $t0, 0x24($sp)
  addiu $t1, $t0, 1
  slti  $at, $t1, 0x20
  bnez  $at, .L7001F6C0
   sw    $t1, 0x24($sp)
  lw    $t2, 0x48($sp)
  li    $a2, 1024
  addiu $a3, $sp, 0x28
  lw    $a0, 4($t2)
  lw    $a1, 8($t2)
  jal   __osContRamWrite
   sw    $zero, 0x10($sp)
  lw    $ra, 0x1c($sp)
  sw    $v0, 0x20($sp)
  lw    $v0, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x48

  nop   
  nop   
glabel __osSiDeviceBusy
  lui   $t6, %hi(SI_STATUS_REG) # $t6, 0xa480
  lw    $a0, %lo(SI_STATUS_REG)($t6)
  addiu $sp, $sp, -8
  andi  $t7, $a0, 3
  beqz  $t7, .L7001F740
   nop   
  b     .L7001F744
   li    $v0, 1
.L7001F740:
  move  $v0, $zero
.L7001F744:
  jr    $ra
   addiu $sp, $sp, 8

  nop   
glabel guNormalize
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lwc1  $f2, ($a0)
  lwc1  $f14, ($a1)
  lwc1  $f0, ($a2)
  mul.s $f4, $f2, $f2
  sw    $a2, 0x20($sp)
  sw    $a1, 0x1c($sp)
  mul.s $f6, $f14, $f14
  sw    $a0, 0x18($sp)
  mul.s $f10, $f0, $f0
  add.s $f8, $f4, $f6
  jal   sqrtf
   add.s $f12, $f10, $f8
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f16
  lw    $a0, 0x18($sp)
  lw    $a1, 0x1c($sp)
  div.s $f2, $f16, $f0
  lwc1  $f18, ($a0)
  lw    $a2, 0x20($sp)
  mul.s $f4, $f18, $f2
  swc1  $f4, ($a0)
  lwc1  $f6, ($a1)
  mul.s $f10, $f6, $f2
  swc1  $f10, ($a1)
  lwc1  $f8, ($a2)
  mul.s $f16, $f8, $f2
  swc1  $f16, ($a2)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   

  nop   
  nop   
  nop   
glabel sqrtf
  jr    $ra
   sqrt.s $f0, $f12

  nop   
  nop   
glabel osLeoDiskInit
  li    $t6, 2
  lui   $at, %hi(LeoDiskHandle+0x4)
  sb    $t6, %lo(LeoDiskHandle+0x4)($at)
  lui   $at, %hi(LeoDiskHandle+0xC)
  lui   $t7, 0xa500
  sw    $t7, %lo(LeoDiskHandle+0xC)($at)
  lui   $at, %hi(LeoDiskHandle+0x5)
  li    $t8, 3
  sb    $t8, %lo(LeoDiskHandle+0x5)($at)
  lui   $at, %hi(LeoDiskHandle+0x8)
  li    $t9, 6
  sb    $t9, %lo(LeoDiskHandle+0x8)($at)
  lui   $at, %hi(LeoDiskHandle+0x7)
  addiu $sp, $sp, -0x20
  li    $t0, 6
  li    $t1, 2
  sw    $ra, 0x14($sp)
  sb    $t0, %lo(LeoDiskHandle+0x6)($at)
  sb    $t1, %lo(LeoDiskHandle+0x7)($at)
  li    $t2, 3
  lui   $t3, %hi(PI_BSD_DOM2_LAT_REG) # $t3, 0xa460
  sw    $t2, %lo(PI_BSD_DOM2_LAT_REG)($t3)
  lui   $t4, %hi(LeoDiskHandle+0x8) 
  lbu   $t4, %lo(LeoDiskHandle+0x8)($t4)
  lui   $t5, %hi(PI_BSD_DOM2_PWD_REG) # $t5, 0xa460
  lui   $t6, %hi(LeoDiskHandle+0x6) 
  sw    $t4, %lo(PI_BSD_DOM2_PWD_REG)($t5)
  lbu   $t6, %lo(LeoDiskHandle+0x6)($t6)
  lui   $t7, %hi(PI_BSD_DOM2_PGS_REG) # $t7, 0xa460
  lui   $t8, %hi(LeoDiskHandle+0x7) 
  sw    $t6, %lo(PI_BSD_DOM2_PGS_REG)($t7)
  lbu   $t8, %lo(LeoDiskHandle+0x7)($t8)
  lui   $a0, %hi(LeoDiskHandle)
  lui   $t9, %hi(PI_BSD_DOM2_RLS_REG) # $t9, 0xa460
  addiu $a0, %lo(LeoDiskHandle) # addiu $a0, $a0, -0x7000
  addiu $a0, $a0, 0x14
  li    $a1, 96
  jal   _blkclr
   sw    $t8, %lo(PI_BSD_DOM2_RLS_REG)($t9)
  jal   __osDisableInt
   nop   
  lui   $t0, %hi(__osPiTable) 
  lw    $t0, %lo(__osPiTable)($t0)
  lui   $at, %hi(LeoDiskHandle)
  lui   $t1, %hi(LeoDiskHandle) 
  sw    $t0, %lo(LeoDiskHandle)($at)
  lui   $at, %hi(__osPiTable)
  addiu $t1, %lo(LeoDiskHandle) # addiu $t1, $t1, -0x7000
  sw    $t1, %lo(__osPiTable)($at)
  sw    $v0, 0x1c($sp)
  lui   $at, %hi(__osDiskHandle)
  sw    $t1, %lo(__osDiskHandle)($at)
  jal   __osRestoreInt
   lw    $a0, 0x1c($sp)
  lw    $ra, 0x14($sp)
  lui   $v0, %hi(LeoDiskHandle)
  addiu $v0, %lo(LeoDiskHandle) # addiu $v0, $v0, -0x7000
  jr    $ra
   addiu $sp, $sp, 0x20

  nop   
.section .bss
glabel LeoDiskHandle
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0

glabel __osDiskHandle
.word 0
.word 0, 0


.section .text
glabel __osSetCompare
  mtc0  $a0, $11
  jr    $ra
   nop   

  nop   
glabel alFilterNew
  sw    $zero, ($a0)
  sw    $a1, 4($a0)
  sw    $a2, 8($a0)
  sh    $zero, 0xc($a0)
  sh    $zero, 0xe($a0)
  jr    $ra
   sw    $a3, 0x10($a0)

  nop   
glabel _doModFunc
  mtc1  $a1, $f6
  lwc1  $f4, 0x10($a0)
  lwc1  $f16, 0x14($a0)
  cvt.s.w $f8, $f6
  li    $at, 0x40000000 # 2.000000
  mtc1  $at, $f5
  li    $at, 0x40100000 # 2.250000
  mul.s $f10, $f4, $f8
  mtc1  $zero, $f4
  add.s $f18, $f16, $f10
  swc1  $f18, 0x14($a0)
  lwc1  $f6, 0x14($a0)
  cvt.d.s $f0, $f6
  mtc1  $zero, $f6
  c.lt.d $f4, $f0
  nop   
  bc1fl .L7001F978
   cvt.s.d $f18, $f0
  mtc1  $at, $f9
  mtc1  $zero, $f8
  nop   
  sub.d $f16, $f0, $f8
  cvt.s.d $f10, $f16
  b     .L7001F97C
   swc1  $f10, 0x14($a0)
  cvt.s.d $f18, $f0
.L7001F978:
  swc1  $f18, 0x14($a0)
.L7001F97C:
  lwc1  $f2, 0x14($a0)
  li    $at, 0x3FF00000 # 1.875000
  mtc1  $at, $f9
  c.lt.s $f2, $f6
  mtc1  $zero, $f8
  bc1fl .L7001F9A0
   cvt.d.s $f4, $f2
  neg.s $f2, $f2
  cvt.d.s $f4, $f2
.L7001F9A0:
  lwc1  $f10, 0x1c($a0)
  sub.d $f16, $f4, $f8
  cvt.s.d $f2, $f16
  mul.s $f0, $f10, $f2
  jr    $ra
   nop   

glabel _filterBuffer
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  andi  $v0, $a1, 0xffff
  sll   $t8, $a2, 1
  andi  $t9, $t8, 0xffff
  sll   $t7, $v0, 0x10
  lui   $at, 0x800
  lui   $t2, (0x0B000020 >> 16) # lui $t2, 0xb00
  or    $t6, $v0, $at
  or    $t1, $t7, $t9
  ori   $t2, (0x0B000020 & 0xFFFF) # ori $t2, $t2, 0x20
  move  $t0, $a0
  sw    $t1, 4($a3)
  sw    $t6, ($a3)
  sw    $t2, 8($a3)
  sw    $t0, 0x28($sp)
  sw    $a3, 0x34($sp)
  jal   osVirtualToPhysical
   addiu $a0, $a0, 8
  lw    $a3, 0x34($sp)
  lw    $t0, 0x28($sp)
  lui   $at, 0xe00
  addiu $v1, $a3, 0x10
  addiu $t3, $v1, 8
  sw    $v0, 0xc($a3)
  sw    $t3, 0x24($sp)
  lw    $t4, 0x2c($t0)
  lh    $t7, 2($t0)
  andi  $t5, $t4, 0xff
  sll   $t6, $t5, 0x10
  or    $t8, $t6, $at
  andi  $t9, $t7, 0xffff
  or    $t1, $t8, $t9
  sw    $t1, ($v1)
  lw    $a0, 0x28($t0)
  jal   osVirtualToPhysical
   sw    $v1, 0x18($sp)
  lw    $a1, 0x18($sp)
  lw    $t0, 0x28($sp)
  sw    $v0, 4($a1)
  sw    $zero, 0x2c($t0)
  lw    $ra, 0x14($sp)
  lw    $v0, 0x24($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   

glabel _saveBuffer
  addiu $sp, $sp, -0x60
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  lw    $v1, 0x1c($a0)
  lw    $v0, 0x14($a0)
  lw    $t0, 0x70($sp)
  sll   $t6, $v1, 1
  sltu  $at, $a1, $v0
  move  $t2, $a0
  move  $t5, $a2
  move  $t3, $a3
  beqz  $at, .L7001FAA8
   addu  $t1, $v0, $t6
  addu  $a1, $a1, $t6
.L7001FAA8:
  sll   $a2, $t3, 1
  addu  $a3, $a2, $a1
  sltu  $at, $t1, $a3
  beqz  $at, .L7001FBA8
   addiu $s0, $t0, 8
  subu  $t3, $t1, $a1
  sra   $t8, $t3, 1
  lui   $t7, 0x800
  sw    $t7, ($t0)
  sll   $t3, $t8, 1
  andi  $t8, $t3, 0xffff
  sll   $t7, $t5, 0x10
  or    $t9, $t7, $t8
  addiu $s0, $t0, 8
  sw    $t9, 4($t0)
  move  $t4, $s0
  lui   $t6, 0x600
  sw    $t6, ($t4)
  sw    $t5, 0x68($sp)
  sw    $t4, 0x44($sp)
  sw    $t3, 0x24($sp)
  sw    $t2, 0x60($sp)
  sw    $t1, 0x4c($sp)
  sw    $a3, 0x28($sp)
  sw    $a2, 0x2c($sp)
  addiu $s0, $s0, 8
  jal   osVirtualToPhysical
   move  $a0, $a1
  lw    $t4, 0x44($sp)
  lw    $a3, 0x28($sp)
  lw    $t1, 0x4c($sp)
  lw    $t3, 0x24($sp)
  lw    $t5, 0x68($sp)
  lw    $t2, 0x60($sp)
  move  $v1, $s0
  lui   $t7, 0x800
  sw    $v0, 4($t4)
  sw    $t7, ($v1)
  subu  $t7, $a3, $t1
  addu  $t9, $t3, $t5
  sll   $t6, $t9, 0x10
  sra   $t8, $t7, 1
  sll   $t9, $t8, 1
  andi  $t7, $t9, 0xffff
  or    $t8, $t6, $t7
  addiu $s0, $s0, 8
  sw    $t8, 4($v1)
  move  $a1, $s0
  lui   $t9, 0x600
  sw    $t9, ($a1)
  lw    $a0, 0x14($t2)
  sw    $a1, 0x3c($sp)
  jal   osVirtualToPhysical
   addiu $s0, $s0, 8
  lw    $a1, 0x3c($sp)
  lw    $a2, 0x2c($sp)
  move  $v1, $s0
  lui   $t6, 0x800
  sw    $v0, 4($a1)
  andi  $t7, $a2, 0xffff
  sw    $t7, 4($v1)
  sw    $t6, ($v1)
  b     .L7001FBE4
   addiu $s0, $s0, 8
.L7001FBA8:
  lui   $t8, 0x800
  sw    $t8, ($t0)
  sll   $t6, $t5, 0x10
  andi  $t7, $a2, 0xffff
  or    $t8, $t6, $t7
  sw    $t8, 4($t0)
  move  $v1, $s0
  lui   $t9, 0x600
  sw    $t9, ($v1)
  sw    $v1, 0x30($sp)
  addiu $s0, $s0, 8
  jal   osVirtualToPhysical
   move  $a0, $a1
  lw    $v1, 0x30($sp)
  sw    $v0, 4($v1)
.L7001FBE4:
  lw    $ra, 0x1c($sp)
  move  $v0, $s0
  lw    $s0, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x60

glabel _loadBuffer
  addiu $sp, $sp, -0x60
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  lw    $v1, 0x1c($a0)
  lw    $v0, 0x14($a0)
  lw    $t0, 0x70($sp)
  sll   $t6, $v1, 1
  sltu  $at, $a1, $v0
  move  $t2, $a0
  move  $t5, $a2
  move  $t3, $a3
  beqz  $at, .L7001FC30
   addu  $t1, $v0, $t6
  addu  $a1, $a1, $t6
.L7001FC30:
  sll   $a2, $t3, 1
  addu  $a3, $a2, $a1
  sltu  $at, $t1, $a3
  beqz  $at, .L7001FD1C
   addiu $s0, $t0, 8
  andi  $t7, $t5, 0xffff
  lui   $at, 0x800
  subu  $t3, $t1, $a1
  sra   $t9, $t3, 1
  or    $t8, $t7, $at
  sll   $t6, $t9, 1
  andi  $t7, $t6, 0xffff
  sw    $t8, ($t0)
  addiu $s0, $t0, 8
  sw    $t7, 4($t0)
  move  $t4, $s0
  lui   $t8, 0x400
  sw    $t8, ($t4)
  sw    $t5, 0x68($sp)
  sw    $t4, 0x44($sp)
  sw    $t6, 0x24($sp)
  sw    $t2, 0x60($sp)
  sw    $t1, 0x4c($sp)
  sw    $a3, 0x28($sp)
  sw    $a2, 0x2c($sp)
  addiu $s0, $s0, 8
  jal   osVirtualToPhysical
   move  $a0, $a1
  lw    $t3, 0x24($sp)
  lw    $t5, 0x68($sp)
  lw    $a3, 0x28($sp)
  lw    $t1, 0x4c($sp)
  lw    $t4, 0x44($sp)
  addu  $t9, $t3, $t5
  andi  $t6, $t9, 0xffff
  lui   $at, 0x800
  lw    $t2, 0x60($sp)
  or    $t7, $t6, $at
  subu  $t8, $a3, $t1
  sra   $t9, $t8, 1
  move  $v1, $s0
  sw    $v0, 4($t4)
  sw    $t7, ($v1)
  sll   $t6, $t9, 1
  andi  $t7, $t6, 0xffff
  addiu $s0, $s0, 8
  sw    $t7, 4($v1)
  move  $a1, $s0
  lui   $t8, 0x400
  sw    $t8, ($a1)
  lw    $a0, 0x14($t2)
  sw    $a1, 0x3c($sp)
  jal   osVirtualToPhysical
   addiu $s0, $s0, 8
  lw    $a1, 0x3c($sp)
  lw    $a2, 0x2c($sp)
  sw    $v0, 4($a1)
  b     .L7001FD60
   andi  $a3, $a2, 0xffff
.L7001FD1C:
  andi  $t9, $t5, 0xffff
  lui   $at, 0x800
  or    $t6, $t9, $at
  andi  $a3, $a2, 0xffff
  sw    $a3, 4($t0)
  sw    $t6, ($t0)
  move  $v1, $s0
  lui   $t7, 0x400
  sw    $t7, ($v1)
  sw    $a3, 0x28($sp)
  sw    $v1, 0x34($sp)
  addiu $s0, $s0, 8
  jal   osVirtualToPhysical
   move  $a0, $a1
  lw    $v1, 0x34($sp)
  lw    $a3, 0x28($sp)
  sw    $v0, 4($v1)
.L7001FD60:
  move  $v1, $s0
  lui   $t8, 0x800
  sw    $t8, ($v1)
  sw    $a3, 4($v1)
  lw    $ra, 0x1c($sp)
  addiu $v0, $s0, 8
  lw    $s0, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x60

glabel _loadOutputBuffer
  addiu $sp, $sp, -0x60
  sw    $ra, 0x24($sp)
  sw    $s1, 0x20($sp)
  sw    $s0, 0x1c($sp)
  sw    $a2, 0x68($sp)
  lw    $t6, 0x24($a1)
  move  $s0, $a1
  move  $s1, $a3
  beqz  $t6, .L7001FF60
   move  $t2, $a0
  lw    $t7, 4($a1)
  lw    $t8, ($a1)
  move  $a0, $a1
  move  $a1, $a3
  subu  $t9, $t7, $t8
  sw    $t9, 0x38($sp)
  jal   _doModFunc
   sw    $t2, 0x60($sp)
  lw    $t4, 0x38($sp)
  li    $at, 0x47000000 # 32768.000000
  mtc1  $at, $f14
  mtc1  $t4, $f6
  li    $at, 0x3FF00000 # 1.875000
  mtc1  $at, $f5
  cvt.s.w $f8, $f6
  mtc1  $zero, $f4
  lw    $a0, 0x60($sp)
  li    $a2, 640
  div.s $f10, $f0, $f8
  mul.s $f16, $f10, $f14
  trunc.w.s $f18, $f16
  mfc1  $t6, $f18
  nop   
  mtc1  $t6, $f6
  nop   
  cvt.s.w $f8, $f6
  div.s $f10, $f8, $f14
  mtc1  $s1, $f8
  cvt.d.s $f16, $f10
  cvt.s.w $f10, $f8
  sub.d $f18, $f4, $f16
  cvt.s.d $f2, $f18
  mul.s $f4, $f2, $f10
  swc1  $f2, 0x44($sp)
  lw    $v0, 0x24($s0)
  lwc1  $f6, 0x20($v0)
  add.s $f12, $f6, $f4
  trunc.w.s $f16, $f12
  mfc1  $t1, $f16
  nop   
  mtc1  $t1, $f18
  nop   
  cvt.s.w $f8, $f18
  sub.s $f10, $f12, $f8
  swc1  $f10, 0x20($v0)
  lw    $t9, 0x18($s0)
  lw    $t8, 4($s0)
  lw    $t7, 0x18($a0)
  sw    $t1, 0x2c($sp)
  subu  $t4, $t8, $t9
  negu  $t5, $t4
  sll   $t6, $t5, 1
  addu  $t0, $t7, $t6
  andi  $v1, $t0, 7
  lw    $t9, 0x70($sp)
  sra   $t8, $v1, 1
  sll   $t3, $t8, 1
  subu  $a1, $t0, $t3
  sw    $t3, 0x28($sp)
  move  $v1, $t8
  addu  $a3, $t1, $t8
  jal   _loadBuffer
   sw    $t9, 0x10($sp)
  lw    $t3, 0x28($sp)
  lui   $at, 0x800
  addiu $t6, $v0, 8
  addiu $t4, $t3, 0x280
  andi  $t5, $t4, 0xffff
  or    $t7, $t5, $at
  sw    $t7, ($v0)
  lw    $t8, 0x68($sp)
  sll   $t4, $s1, 1
  andi  $t5, $t4, 0xffff
  sll   $t9, $t8, 0x10
  or    $t7, $t9, $t5
  sw    $t7, 4($v0)
  li    $at, 0x47000000 # 32768.000000
  mtc1  $at, $f4
  lwc1  $f6, 0x44($sp)
  sw    $t6, 0x30($sp)
  lw    $t5, 0x24($s0)
  mul.s $f16, $f6, $f4
  lui   $at, 0x500
  lw    $t7, 0x24($t5)
  addiu $v1, $v0, 0x10
  andi  $t6, $t7, 0xff
  sll   $t8, $t6, 0x10
  trunc.w.s $f18, $f16
  mfc1  $t4, $f18
  nop   
  andi  $t9, $t4, 0xffff
  or    $t4, $t8, $at
  or    $t5, $t4, $t9
  sw    $t5, 8($v0)
  lw    $t7, 0x24($s0)
  lw    $a0, 0x14($t7)
  jal   osVirtualToPhysical
   sw    $v1, 0x5c($sp)
  lw    $t6, 0x30($sp)
  lw    $t1, 0x2c($sp)
  lw    $v1, 0x5c($sp)
  sw    $v0, 4($t6)
  lw    $t8, 0x24($s0)
  sw    $zero, 0x24($t8)
  lw    $t4, 0x18($s0)
  addu  $t9, $t4, $t1
  subu  $t5, $t9, $s1
  b     .L7001FF90
   sw    $t5, 0x18($s0)
.L7001FF60:
  lw    $t6, 4($s0)
  lw    $t7, 0x18($t2)
  lw    $t9, 0x70($sp)
  negu  $t8, $t6
  sll   $t4, $t8, 1
  move  $a0, $t2
  lw    $a2, 0x68($sp)
  move  $a3, $s1
  addu  $a1, $t7, $t4
  jal   _loadBuffer
   sw    $t9, 0x10($sp)
  move  $v1, $v0
.L7001FF90:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  addiu $sp, $sp, 0x60
  jr    $ra
   move  $v0, $v1

glabel alFxParamHdl
  addiu $v0, $a1, -2
  andi  $t6, $v0, 7
  sltiu $at, $t6, 8
  beqz  $at, .L700201B8
   lw    $v1, ($a2)
  sll   $t6, $t6, 2
  lui   $at, %hi(jpt_80029D10)
  addu  $at, $at, $t6
  lw    $t6, %lo(jpt_80029D10)($at)
  jr    $t6
   nop   
.L7001FFD4:
  lw    $t7, 0x20($a0)
  bgez  $v0, .L7001FFE8
   sra   $t8, $v0, 3
  addiu $at, $v0, 7
  sra   $t8, $at, 3
.L7001FFE8:
  sll   $t9, $t8, 2
  addu  $t9, $t9, $t8
  sll   $t9, $t9, 3
  addu  $t0, $t7, $t9
  sw    $v1, ($t0)
  jr    $ra
   move  $v0, $zero
.L70020004:
  lw    $t1, 0x20($a0)
  bgez  $v0, .L70020018
   sra   $t2, $v0, 3
  addiu $at, $v0, 7
  sra   $t2, $at, 3
.L70020018:
  sll   $t3, $t2, 2
  addu  $t3, $t3, $t2
  sll   $t3, $t3, 3
  addu  $t4, $t1, $t3
  sw    $v1, 4($t4)
  jr    $ra
   move  $v0, $zero
.L70020034:
  lw    $t5, 0x20($a0)
  bgez  $v0, .L70020048
   sra   $t6, $v0, 3
  addiu $at, $v0, 7
  sra   $t6, $at, 3
.L70020048:
  sll   $t8, $t6, 2
  addu  $t8, $t8, $t6
  sll   $t8, $t8, 3
  addu  $t7, $t5, $t8
  sh    $v1, 8($t7)
  jr    $ra
   move  $v0, $zero
.L70020064:
  lw    $t9, 0x20($a0)
  bgez  $v0, .L70020078
   sra   $t0, $v0, 3
  addiu $at, $v0, 7
  sra   $t0, $at, 3
.L70020078:
  sll   $t2, $t0, 2
  addu  $t2, $t2, $t0
  sll   $t2, $t2, 3
  addu  $t1, $t9, $t2
  sh    $v1, 0xa($t1)
  jr    $ra
   move  $v0, $zero
.L70020094:
  lw    $t3, 0x20($a0)
  bgez  $v0, .L700200A8
   sra   $t4, $v0, 3
  addiu $at, $v0, 7
  sra   $t4, $at, 3
.L700200A8:
  sll   $t6, $t4, 2
  addu  $t6, $t6, $t4
  sll   $t6, $t6, 3
  addu  $t5, $t3, $t6
  sh    $v1, 0xc($t5)
  jr    $ra
   move  $v0, $zero
.L700200C4:
  mtc1  $v1, $f4
  lui   $at, %hi(F64_80029D30)
  lwc1  $f8, %lo(F64_80029D30)($at)
  cvt.s.w $f6, $f4
  lw    $t8, 0x20($a0)
  div.s $f10, $f6, $f8
  bgez  $v0, .L700200EC
   sra   $t7, $v0, 3
  addiu $at, $v0, 7
  sra   $t7, $at, 3
.L700200EC:
  sll   $t0, $t7, 2
  addu  $t0, $t0, $t7
  sll   $t0, $t0, 3
  addu  $t9, $t8, $t0
  move  $v0, $zero
  jr    $ra
   swc1  $f10, 0x10($t9)
.L70020108:
  lw    $t2, 0x20($a0)
  bgez  $v0, .L7002011C
   sra   $t1, $v0, 3
  addiu $at, $v0, 7
  sra   $t1, $at, 3
.L7002011C:
  sll   $t4, $t1, 2
  addu  $t4, $t4, $t1
  sll   $t4, $t4, 3
  addu  $a1, $t2, $t4
  lw    $t3, 4($a1)
  lw    $t6, ($a1)
  mtc1  $v1, $f6
  li    $at, 0x41F00000 # 30.000000
  subu  $t5, $t3, $t6
  mtc1  $t5, $f16
  cvt.s.w $f8, $f6
  bgez  $t5, .L70020160
   cvt.d.w $f18, $f16
  mtc1  $at, $f5
  mtc1  $zero, $f4
  nop   
  add.d $f18, $f18, $f4
.L70020160:
  lui   $at, %hi(F64_80029D38)
  ldc1  $f16, %lo(F64_80029D38)($at)
  cvt.d.s $f10, $f8
  move  $v0, $zero
  div.d $f4, $f10, $f16
  mul.d $f6, $f18, $f4
  cvt.s.d $f8, $f6
  jr    $ra
   swc1  $f8, 0x1c($a1)
.L70020184:
  lw    $t7, 0x20($a0)
  bgez  $v0, .L70020198
   sra   $t8, $v0, 3
  addiu $at, $v0, 7
  sra   $t8, $at, 3
.L70020198:
  sll   $t0, $t8, 2
  addu  $t0, $t0, $t8
  sll   $t0, $t0, 3
  addu  $t9, $t7, $t0
  lw    $a1, 0x20($t9)
  beqz  $a1, .L700201B8
   nop   
  sh    $v1, ($a1)
.L700201B8:
  jr    $ra
   move  $v0, $zero

glabel alFxParam
  li    $at, 1
  bne   $a1, $at, .L700201D0
   nop   
  sw    $a2, ($a0)
.L700201D0:
  jr    $ra
   move  $v0, $zero

glabel alFxPull
  addiu $sp, $sp, -0xa8
  sw    $s3, 0x2c($sp)
  move  $s3, $a0
  sw    $ra, 0x44($sp)
  sw    $fp, 0x40($sp)
  sw    $s7, 0x3c($sp)
  sw    $s6, 0x38($sp)
  sw    $s5, 0x34($sp)
  sw    $s4, 0x30($sp)
  sw    $s2, 0x28($sp)
  sw    $s1, 0x24($sp)
  sw    $s0, 0x20($sp)
  lw    $a0, ($a0)
  lw    $t6, 0xb8($sp)
  sw    $zero, 0x80($sp)
  move  $s6, $a2
  sw    $t6, 0x10($sp)
  lw    $t9, 4($a0)
  jalr  $t9
  nop   
  sll   $s1, $s6, 1
  lui   $t8, (0x0C00DA83 >> 16) # lui $t8, 0xc00
  lui   $t2, (0x06C006C0 >> 16) # lui $t2, 0x6c0
  lui   $t3, (0x0C005A82 >> 16) # lui $t3, 0xc00
  lui   $t4, (0x080006C0 >> 16) # lui $t4, 0x800
  andi  $t1, $s1, 0xffff
  lui   $t7, 0x800
  ori   $t2, (0x06C006C0 & 0xFFFF) # ori $t2, $t2, 0x6c0
  ori   $t8, (0x0C00DA83 & 0xFFFF) # ori $t8, $t8, 0xda83
  ori   $t4, (0x080006C0 & 0xFFFF) # ori $t4, $t4, 0x6c0
  ori   $t3, (0x0C005A82 & 0xFFFF) # ori $t3, $t3, 0x5a82
  sw    $t7, ($v0)
  sw    $t1, 4($v0)
  sw    $t8, 8($v0)
  sw    $t2, 0xc($v0)
  sw    $t3, 0x10($v0)
  sw    $t4, 0x14($v0)
  lw    $a1, 0x18($s3)
  addiu $t5, $v0, 0x18
  move  $s5, $zero
  li    $s2, 320
  sw    $t5, 0x10($sp)
  sw    $t1, 0x48($sp)
  sw    $s1, 0x50($sp)
  move  $a0, $s3
  li    $a2, 1728
  jal   _saveBuffer
   move  $a3, $s6
  lw    $v1, 0x80($sp)
  lui   $t6, (0x02000800 >> 16) # lui $t6, 0x200
  ori   $t6, (0x02000800 & 0xFFFF) # ori $t6, $t6, 0x800
  sw    $t6, ($v0)
  sw    $s1, 4($v0)
  lbu   $t9, 0x24($s3)
  addiu $s0, $v0, 8
  move  $s7, $zero
  blezl $t9, .L70020498
   lw    $v1, 0x1c($s3)
  lw    $v0, 0x18($s3)
.L700202C4:
  lw    $t7, 0x20($s3)
  sll   $t8, $s7, 2
  addu  $t8, $t8, $s7
  sll   $t8, $t8, 3
  addu  $s1, $t7, $t8
  lw    $t2, ($s1)
  lw    $t5, 4($s1)
  move  $a0, $s3
  negu  $t3, $t2
  sll   $t4, $t3, 1
  negu  $t6, $t5
  addu  $s4, $v0, $t4
  sll   $t9, $t6, 1
  bne   $s4, $v1, .L70020320
   addu  $fp, $v0, $t9
  move  $t7, $s2
  sll   $s2, $s5, 0x10
  sll   $s5, $t7, 0x10
  sra   $t2, $s5, 0x10
  sra   $t8, $s2, 0x10
  move  $s2, $t8
  b     .L70020338
   move  $s5, $t2
.L70020320:
  move  $a1, $s4
  move  $a2, $s5
  move  $a3, $s6
  jal   _loadBuffer
   sw    $s0, 0x10($sp)
  move  $s0, $v0
.L70020338:
  move  $a0, $s3
  move  $a1, $s1
  move  $a2, $s2
  move  $a3, $s6
  jal   _loadOutputBuffer
   sw    $s0, 0x10($sp)
  lh    $a0, 8($s1)
  move  $s0, $v0
  lui   $at, 0xc00
  beqz  $a0, .L700203B0
   andi  $t4, $a0, 0xffff
  sll   $t9, $s5, 0x10
  andi  $t7, $s2, 0xffff
  or    $t8, $t9, $t7
  or    $t5, $t4, $at
  sw    $t5, ($v0)
  sw    $t8, 4($v0)
  lw    $t2, 0x24($s1)
  addiu $s0, $v0, 8
  bnezl $t2, .L700203B4
   lh    $v1, 0xa($s1)
  lw    $t3, 0x20($s1)
  move  $a0, $s3
  move  $a1, $fp
  bnez  $t3, .L700203B0
   move  $a2, $s2
  move  $a3, $s6
  jal   _saveBuffer
   sw    $s0, 0x10($sp)
  move  $s0, $v0
.L700203B0:
  lh    $v1, 0xa($s1)
.L700203B4:
  move  $v0, $s0
  lui   $at, 0xc00
  beqz  $v1, .L700203FC
   andi  $t5, $v1, 0xffff
  sll   $t7, $s2, 0x10
  andi  $t8, $s5, 0xffff
  or    $t2, $t7, $t8
  or    $t6, $t5, $at
  sw    $t6, ($v0)
  sw    $t2, 4($v0)
  addiu $s0, $s0, 8
  sw    $s0, 0x10($sp)
  move  $a0, $s3
  move  $a1, $s4
  move  $a2, $s5
  jal   _saveBuffer
   move  $a3, $s6
  move  $s0, $v0
.L700203FC:
  lw    $a0, 0x20($s1)
  move  $a1, $s2
  move  $a2, $s6
  beql  $a0, $zero, .L70020420
   lw    $t3, 0x24($s1)
  jal   _filterBuffer
   move  $a3, $s0
  move  $s0, $v0
  lw    $t3, 0x24($s1)
.L70020420:
  move  $a0, $s3
  move  $a1, $fp
  bnez  $t3, .L70020440
   move  $a2, $s2
  move  $a3, $s6
  jal   _saveBuffer
   sw    $s0, 0x10($sp)
  move  $s0, $v0
.L70020440:
  lh    $v1, 0xc($s1)
  addiu $s7, $s7, 1
  sll   $t4, $s7, 0x10
  beqz  $v1, .L70020478
   sra   $s7, $t4, 0x10
  move  $v0, $s0
  andi  $t5, $v1, 0xffff
  lui   $at, 0xc00
  sll   $t7, $s2, 0x10
  ori   $t8, $t7, 0x800
  or    $t6, $t5, $at
  sw    $t6, ($v0)
  sw    $t8, 4($v0)
  addiu $s0, $s0, 8
.L70020478:
  lbu   $t6, 0x24($s3)
  lw    $t2, 4($s1)
  lw    $v0, 0x18($s3)
  slt   $at, $s7, $t6
  sll   $t3, $t2, 1
  bnez  $at, .L700202C4
   addu  $v1, $v0, $t3
  lw    $v1, 0x1c($s3)
.L70020498:
  lw    $t9, 0x18($s3)
  lw    $t7, 0x50($sp)
  lw    $t3, 0x14($s3)
  sll   $t2, $v1, 1
  addu  $t8, $t9, $t7
  addu  $t4, $t3, $t2
  sltu  $at, $t4, $t8
  beqz  $at, .L700204C4
   sw    $t8, 0x18($s3)
  subu  $t5, $t8, $t2
  sw    $t5, 0x18($s3)
.L700204C4:
  lui   $t6, (0x0A000800 >> 16) # lui $t6, 0xa00
  ori   $t6, (0x0A000800 & 0xFFFF) # ori $t6, $t6, 0x800
  move  $v1, $s0
  sw    $t6, ($v1)
  lw    $t9, 0x48($sp)
  lui   $at, 0x6c0
  addiu $v0, $s0, 8
  or    $t7, $t9, $at
  sw    $t7, 4($v1)
  lw    $ra, 0x44($sp)
  lw    $fp, 0x40($sp)
  lw    $s7, 0x3c($sp)
  lw    $s6, 0x38($sp)
  lw    $s5, 0x34($sp)
  lw    $s4, 0x30($sp)
  lw    $s3, 0x2c($sp)
  lw    $s2, 0x28($sp)
  lw    $s1, 0x24($sp)
  lw    $s0, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0xa8

  nop   
  nop  
.section .rodata
glabel jpt_80029D10
 .word .L7001FFD4
 .word .L70020004
 .word .L70020064
 .word .L70020034
 .word .L70020094
 .word .L700200C4
 .word .L70020108
 .word .L70020184
glabel F64_80029D30
 .double 4.9039833923682246e55
glabel F64_80029D38
 .double 173123.404906676
glabel F64_80029D40
 .double 1.4922257467118833e306
.word 0
.word 0

.section .text 
glabel alSeqGetLoc
  lw    $t6, 8($a0)
  sw    $t6, ($a1)
  lh    $t7, 0x1a($a0)
  sh    $t7, 0xc($a1)
  lw    $t8, 0xc($a0)
  jr    $ra
   sw    $t8, 4($a1)

glabel alSeqSetLoc
  lw    $t6, ($a1)
  sw    $t6, 8($a0)
  lh    $t7, 0xc($a1)
  sh    $t7, 0x1a($a0)
  lw    $t8, 4($a1)
  jr    $ra
   sw    $t8, 0xc($a0)

glabel alSeqGetTicks
  jr    $ra
   lw    $v0, 0xc($a0)

  jr    $ra
   nop   

glabel readVarLen
  lw    $v1, 8($a0)
  lbu   $v0, ($v1)
  addiu $t6, $v1, 1
  sw    $t6, 8($a0)
  andi  $t7, $v0, 0x80
  beqz  $t7, .L700205AC
   move  $a1, $v0
  andi  $a1, $v0, 0x7f
.L70020588:
  lw    $v1, 8($a0)
  sll   $t9, $a1, 7
  lbu   $v0, ($v1)
  addiu $t8, $v1, 1
  sw    $t8, 8($a0)
  andi  $t6, $v0, 0x7f
  andi  $t7, $v0, 0x80
  bnez  $t7, .L70020588
   addu  $a1, $t9, $t6
.L700205AC:
  jr    $ra
   move  $v0, $a1

glabel alSeqNextEvent
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  move  $a2, $a0
  jal   readVarLen
   move  $a3, $a1
  lw    $t6, 0xc($a2)
  lw    $v1, 8($a2)
  move  $t1, $v0
  addu  $t7, $t6, $v0
  sw    $t7, 0xc($a2)
  lbu   $a0, ($v1)
  li    $at, 255
  addiu $t8, $v1, 1
  sw    $t8, 8($a2)
  move  $v0, $a0
  bne   $a0, $at, .L700206B0
   andi  $a1, $a0, 0xff
  lbu   $v0, ($t8)
  addiu $t9, $t8, 1
  li    $at, 81
  sw    $t9, 8($a2)
  bne   $v0, $at, .L70020678
   move  $t0, $v0
  li    $t6, 3
  sh    $t6, ($a3)
  sw    $t1, 4($a3)
  sb    $a1, 8($a3)
  sb    $t0, 9($a3)
  lw    $v1, 8($a2)
  lbu   $v0, ($v1)
  addiu $t7, $v1, 1
  sw    $t7, 8($a2)
  sb    $v0, 0xa($a3)
  lw    $v1, 8($a2)
  lbu   $a0, ($v1)
  addiu $t8, $v1, 1
  sw    $t8, 8($a2)
  sb    $a0, 0xb($a3)
  lw    $v1, 8($a2)
  lbu   $a1, ($v1)
  addiu $t9, $v1, 1
  sw    $t9, 8($a2)
  sb    $a1, 0xc($a3)
  lw    $v1, 8($a2)
  lbu   $a0, ($v1)
  addiu $t6, $v1, 1
  sw    $t6, 8($a2)
  b     .L700206A8
   sb    $a0, 0xd($a3)
.L70020678:
  li    $at, 47
  bne   $v0, $at, .L700206A8
   li    $t7, 4
  sh    $t7, ($a3)
  sw    $t1, 4($a3)
  sb    $a1, 8($a3)
  sb    $t0, 9($a3)
  lw    $v1, 8($a2)
  lbu   $a0, ($v1)
  addiu $t8, $v1, 1
  sw    $t8, 8($a2)
  sb    $a0, 0xa($a3)
.L700206A8:
  b     .L70020728
   sh    $zero, 0x1a($a2)
.L700206B0:
  li    $t9, 1
  andi  $t6, $v0, 0x80
  sh    $t9, ($a3)
  beqz  $t6, .L700206E4
   sw    $t1, 4($a3)
  sb    $a1, 8($a3)
  lw    $v1, 8($a2)
  lbu   $a0, ($v1)
  addiu $t7, $v1, 1
  sw    $t7, 8($a2)
  sb    $a0, 9($a3)
  b     .L700206F0
   sh    $a1, 0x1a($a2)
.L700206E4:
  lh    $t8, 0x1a($a2)
  sb    $a0, 9($a3)
  sb    $t8, 8($a3)
.L700206F0:
  lbu   $v0, 8($a3)
  li    $at, 192
  andi  $t9, $v0, 0xf0
  beq   $t9, $at, .L70020724
   li    $at, 208
  beql  $t9, $at, .L70020728
   sb    $zero, 0xa($a3)
  lw    $v1, 8($a2)
  lbu   $a0, ($v1)
  addiu $t6, $v1, 1
  sw    $t6, 8($a2)
  b     .L70020728
   sb    $a0, 0xa($a3)
.L70020724:
  sb    $zero, 0xa($a3)
.L70020728:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   

glabel alSeqNewMarker
  addiu $sp, $sp, -0x60
  sw    $s7, 0x30($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  move  $s0, $a0
  move  $s1, $a2
  move  $s7, $a1
  sw    $ra, 0x34($sp)
  sw    $s6, 0x2c($sp)
  sw    $s5, 0x28($sp)
  sw    $s4, 0x24($sp)
  sw    $s3, 0x20($sp)
  bnez  $a2, .L70020788
   sw    $s2, 0x1c($sp)
  lw    $t6, 4($a0)
  sh    $zero, 0xc($a1)
  sw    $zero, 4($a1)
  sw    $zero, 8($a1)
  b     .L7002082C
   sw    $t6, ($a1)
.L70020788:
  lw    $t7, 8($s0)
  move  $v0, $zero
  li    $s3, 4
  sw    $t7, 0x4c($sp)
  lh    $t8, 0x1a($s0)
  addiu $s2, $sp, 0x50
  sh    $t8, 0x3e($sp)
  lw    $t9, 0xc($s0)
  sw    $t9, 0x44($sp)
  lw    $t0, 4($s0)
  sh    $zero, 0x1a($s0)
  sw    $zero, 0xc($s0)
  sw    $t0, 8($s0)
  lw    $s4, 8($s0)
.L700207C0:
  lh    $s5, 0x1a($s0)
  move  $s6, $v0
  move  $a0, $s0
  jal   alSeqNextEvent
   move  $a1, $s2
  lh    $t1, 0x50($sp)
  bnel  $t1, $s3, .L700207F4
   lw    $v0, 0xc($s0)
  lw    $s4, 8($s0)
  lh    $s5, 0x1a($s0)
  b     .L70020800
   lw    $s6, 0xc($s0)
  lw    $v0, 0xc($s0)
.L700207F4:
  sltu  $at, $v0, $s1
  bnezl $at, .L700207C0
   lw    $s4, 8($s0)
.L70020800:
  sw    $s4, ($s7)
  sh    $s5, 0xc($s7)
  sw    $s6, 4($s7)
  lw    $t2, 0xc($s0)
  sw    $t2, 8($s7)
  lw    $t3, 0x4c($sp)
  sw    $t3, 8($s0)
  lh    $t4, 0x3e($sp)
  sh    $t4, 0x1a($s0)
  lw    $t5, 0x44($sp)
  sw    $t5, 0xc($s0)
.L7002082C:
  lw    $ra, 0x34($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  lw    $s4, 0x24($sp)
  lw    $s5, 0x28($sp)
  lw    $s6, 0x2c($sp)
  lw    $s7, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x60

glabel alSeqSecToTicks
  mtc1  $a1, $f12
  lui   $at, %hi(F64_80029D50)
  ldc1  $f6, %lo(F64_80029D50)($at)
  lh    $t6, 0x18($a0)
  cvt.d.s $f4, $f12
  li    $at, 0x41F00000 # 30.000000
  mul.d $f8, $f4, $f6
  mtc1  $t6, $f10
  mtc1  $a2, $f4
  cvt.d.w $f16, $f10
  cvt.d.w $f6, $f4
  mul.d $f18, $f8, $f16
  bgezl $a2, .L700208A4
   div.d $f8, $f18, $f6
  mtc1  $at, $f11
  mtc1  $zero, $f10
  nop   
  add.d $f6, $f6, $f10
  div.d $f8, $f18, $f6
.L700208A4:
  li    $v0, 1
  li    $at, 0x41E00000 # 28.000000
  cfc1  $t7, $31
  ctc1  $v0, $31
  nop   
  cvt.w.d $f16, $f8
  cfc1  $v0, $31
  nop   
  andi  $v0, $v0, 0x78
  beql  $v0, $zero, .L70020924
   mfc1  $v0, $f16
  mtc1  $at, $f17
  mtc1  $zero, $f16
  li    $v0, 1
  lui   $at, 0x8000
  sub.d $f16, $f8, $f16
  ctc1  $v0, $31
  nop   
  cvt.w.d $f16, $f16
  cfc1  $v0, $31
  nop   
  andi  $v0, $v0, 0x78
  bnezl $v0, .L70020918
   ctc1  $t7, $31
  mfc1  $v0, $f16
  ctc1  $t7, $31
  jr    $ra
   or    $v0, $v0, $at

  ctc1  $t7, $31
.L70020918:
  jr    $ra
   li    $v0, -1

  mfc1  $v0, $f16
.L70020924:
  nop   
  bltzl $v0, .L70020918
   ctc1  $t7, $31
  ctc1  $t7, $31
  jr    $ra
   nop   

glabel alSeqTicksToSec
  mtc1  $a1, $f4
  mtc1  $a2, $f8
  li    $at, 0x4F800000 # 4294967296.000000
  cvt.s.w $f6, $f4
  bgez  $a2, .L70020960
   cvt.s.w $f10, $f8
  mtc1  $at, $f16
  nop   
  add.s $f10, $f10, $f16
.L70020960:
  lh    $t6, 0x18($a0)
  mul.s $f18, $f6, $f10
  lui   $at, %hi(F64_80029D58)
  mtc1  $t6, $f8
  ldc1  $f10, %lo(F64_80029D58)($at)
  cvt.s.w $f16, $f8
  cvt.d.s $f4, $f18
  cvt.d.s $f6, $f16
  mul.d $f18, $f6, $f10
  div.d $f8, $f4, $f18
  jr    $ra
   cvt.s.d $f0, $f8
.section .rodata
glabel F64_80029D50
 .double 1000000.0
glabel F64_80029D58
 .double 1000000.0

.section .text
glabel __alSeqNextDelta
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lw    $t7, 0x10($a0)
  lw    $t6, ($a0)
  lw    $v0, 8($a0)
  move  $a2, $a0
  addu  $t8, $t6, $t7
  sltu  $at, $v0, $t8
  bnez  $at, .L700209C0
   move  $t0, $a1
  b     .L700209D8
   move  $v0, $zero
.L700209C0:
  move  $a3, $v0
  jal   readVarLen
   move  $a0, $a2
  sw    $v0, ($t0)
  sw    $a3, 8($a2)
  li    $v0, 1
.L700209D8:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   

glabel read32
  lw    $a1, 8($a0)
  lbu   $v1, ($a1)
  addiu $t7, $a1, 1
  sw    $t7, 8($a0)
  lbu   $t8, ($t7)
  sll   $t6, $v1, 0x18
  sll   $t9, $t8, 0x10
  or    $v1, $t6, $t9
  addiu $t6, $t7, 1
  sw    $t6, 8($a0)
  lbu   $t7, ($t6)
  addiu $t9, $t6, 1
  sw    $t9, 8($a0)
  sll   $t8, $t7, 8
  lbu   $t6, ($t9)
  or    $v1, $v1, $t8
  addiu $t7, $t9, 1
  sw    $t7, 8($a0)
  jr    $ra
   or    $v0, $v1, $t6

glabel read16
  lw    $a1, 8($a0)
  lbu   $v1, ($a1)
  addiu $t9, $a1, 1
  sw    $t9, 8($a0)
  lbu   $t6, ($t9)
  sll   $t8, $v1, 8
  addiu $t9, $t9, 1
  or    $v1, $t8, $t6
  sll   $t7, $v1, 0x10
  sra   $v0, $t7, 0x10
  jr    $ra
   sw    $t9, 8($a0)

glabel alSeqNew
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  move  $a3, $a0
  sw    $a1, ($a0)
  sw    $a2, 0x10($a0)
  sh    $zero, 0x1a($a0)
  sw    $zero, 0xc($a0)
  jal   read32
   sw    $a1, 8($a0)
  lui   $at, (0x4D546864 >> 16) # lui $at, 0x4d54
  ori   $at, (0x4D546864 & 0xFFFF) # ori $at, $at, 0x6864
  bnel  $v0, $at, .L70020B34
   lw    $ra, 0x14($sp)
  jal   read32
   move  $a0, $a3
  jal   read16
   move  $a0, $a3
  bnezl $v0, .L70020B34
   lw    $ra, 0x14($sp)
  jal   read16
   move  $a0, $a3
  li    $at, 1
  bnel  $v0, $at, .L70020B34
   lw    $ra, 0x14($sp)
  jal   read16
   move  $a0, $a3
  sh    $v0, 0x18($a3)
  lh    $v1, 0x18($a3)
  andi  $t6, $v1, 0x8000
  bnezl $t6, .L70020B34
   lw    $ra, 0x14($sp)
  mtc1  $v1, $f6
  li    $at, 0x3FF00000 # 1.875000
  mtc1  $at, $f5
  cvt.s.w $f8, $f6
  mtc1  $zero, $f4
  move  $a0, $a3
  cvt.d.s $f10, $f8
  div.d $f6, $f4, $f10
  cvt.s.d $f8, $f6
  jal   read32
   swc1  $f8, 0x14($a3)
  lui   $at, (0x4D54726B >> 16) # lui $at, 0x4d54
  ori   $at, (0x4D54726B & 0xFFFF) # ori $at, $at, 0x726b
  bnel  $v0, $at, .L70020B34
   lw    $ra, 0x14($sp)
  jal   read32
   move  $a0, $a3
  lw    $t7, 8($a3)
  sw    $t7, 4($a3)
  lw    $ra, 0x14($sp)
.L70020B34:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   

glabel alSynSetPriority
  sw    $a0, ($sp)
  sw    $a2, 8($sp)
  jr    $ra
   sh    $a2, 0x16($a1)

glabel lldiv
  addiu $sp, $sp, -0x30
  sw    $a0, 0x30($sp)
  sw    $ra, 0x14($sp)
  sw    $a2, 0x38($sp)
  sw    $a3, 0x3c($sp)
  move  $a0, $a2
  move  $a1, $a3
  lw    $a3, 0x44($sp)
  jal   __ll_div
   lw    $a2, 0x40($sp)
  sw    $v0, 0x20($sp)
  sw    $v1, 0x24($sp)
  lw    $a0, 0x40($sp)
  lw    $a1, 0x44($sp)
  move  $a2, $v0
  jal   __ll_mul
   move  $a3, $v1
  lw    $t6, 0x38($sp)
  lw    $t7, 0x3c($sp)
  lw    $t0, 0x20($sp)
  subu  $t8, $t6, $v0
  sltu  $at, $t7, $v1
  subu  $t8, $t8, $at
  subu  $t9, $t7, $v1
  sw    $t9, 0x2c($sp)
  sw    $t8, 0x28($sp)
  bgtz  $t0, .L70020C18
   lw    $t1, 0x24($sp)
  bltz  $t0, .L70020BD0
   nop   
  b     .L70020C1C
   addiu $t0, $sp, 0x20
.L70020BD0:
  bltzl $t8, .L70020C1C
   addiu $t0, $sp, 0x20
  bgtz  $t8, .L70020BE8
   addiu $t3, $t1, 1
  beql  $t9, $zero, .L70020C1C
   addiu $t0, $sp, 0x20
.L70020BE8:
  lw    $t4, 0x40($sp)
  lw    $t5, 0x44($sp)
  sltiu $at, $t3, 1
  addu  $t2, $t0, $at
  subu  $t6, $t8, $t4
  sltu  $at, $t9, $t5
  subu  $t6, $t6, $at
  subu  $t7, $t9, $t5
  sw    $t2, 0x20($sp)
  sw    $t3, 0x24($sp)
  sw    $t7, 0x2c($sp)
  sw    $t6, 0x28($sp)
.L70020C18:
  addiu $t0, $sp, 0x20
.L70020C1C:
  lw    $v0, 0x30($sp)
  lw    $at, ($t0)
  sw    $at, ($v0)
  lw    $t3, 4($t0)
  sw    $t3, 4($v0)
  lw    $at, 8($t0)
  sw    $at, 8($v0)
  lw    $t3, 0xc($t0)
  sw    $t3, 0xc($v0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   

glabel ldiv
  div   $zero, $a1, $a2
  mflo  $v0
  addiu $sp, $sp, -8
  bnez  $a2, .L70020C68
   nop   
  break 7
.L70020C68:
  li    $at, -1
  bne   $a2, $at, .L70020C80
   lui   $at, 0x8000
  bne   $a1, $at, .L70020C80
   nop   
  break 6
.L70020C80:
  multu $a2, $v0
  sw    $v0, ($sp)
  addiu $t7, $sp, 0
  mflo  $t6
  subu  $v1, $a1, $t6
  bgez  $v0, .L70020CB8
   sw    $v1, 4($sp)
  sw    $v0, ($sp)
  blez  $v1, .L70020CB8
   sw    $v1, 4($sp)
  addiu $v0, $v0, 1
  subu  $v1, $v1, $a2
  sw    $v1, 4($sp)
  sw    $v0, ($sp)
.L70020CB8:
  lw    $at, ($t7)
  move  $v0, $a0
  sw    $at, ($a0)
  lw    $t0, 4($t7)
  addiu $sp, $sp, 8
  jr    $ra
   sw    $t0, 4($a0)

  nop   
  nop   
  nop   

glabel __osResetGlobalIntMask
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  sw    $a0, 0x28($sp)
  jal   __osDisableInt
   sw    $s0, 0x18($sp)
  lw    $t7, 0x28($sp)
  lui   $t6, %hi(__OSGlobalIntMask) 
  lw    $t6, %lo(__OSGlobalIntMask)($t6)
  li    $at, -1026
  and   $t8, $t7, $at
  not   $t9, $t8
  move  $s0, $v0
  lui   $at, %hi(__OSGlobalIntMask)
  and   $t0, $t6, $t9
  sw    $t0, %lo(__OSGlobalIntMask)($at)
  jal   __osRestoreInt
   move  $a0, $s0
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
  nop

  nop
  nop

glabel osEPiRawWriteIo
  lui   $t6, %hi(PI_STATUS_REG) # $t6, 0xa460
  lw    $a3, %lo(PI_STATUS_REG)($t6)
  addiu $sp, $sp, -8
  andi  $t7, $a3, 3
  beqz  $t7, .L70020D6C
   nop   
.L70020D58:
  lui   $t8, %hi(PI_STATUS_REG) # $t8, 0xa460
  lw    $a3, %lo(PI_STATUS_REG)($t8)
  andi  $t9, $a3, 3
  bnez  $t9, .L70020D58
   nop   
.L70020D6C:
  lw    $t0, 0xc($a0)
  lui   $at, 0xa000
  addiu $sp, $sp, 8
  or    $t1, $t0, $a1
  or    $t2, $t1, $at
  sw    $a2, ($t2)
  jr    $ra
  move  $v0, $zero
  nop   

.section .data
glabel osViModeNtscLan1
.word  0x2000000,    0x311E,     0x140, 0x3E52239
.word      0x20D,     0xC15, 0xC150C15,  0x6C02EC
.word      0x200,         0,     0x280,     0x400
.word   0x2501FF,   0xE0204,         2,     0x280
.word      0x400,  0x2501FF,   0xE0204,         2
glabel osViModePalLan1
.word 0x10000000,    0x311E,     0x140, 0x404233A
.word      0x271,  0x150C69, 0xC6F0C6E,  0x800300
.word      0x200,         0,     0x280,     0x400
.word   0x5F0239,   0x9026B,         2,     0x280
.word      0x400,  0x5F0239,   0x9026B,         2
.word       0x10,      0x10,      0x20,         0

.section .bss
glabel D_80069080
.word 0
glabel D_80069084
.word 0
glabel D_80069088
.word 0
glabel D_8006908C
.word 0
glabel D_80069090
.word 0
glabel D_80069094
.word 0
glabel D_80069098
.word 0
glabel D_8006909C
.word 0
glabel D_800690a0
.word 0
glabel D_800690a4
.word 0
glabel D_800690a8
.word 0
glabel D_800690ac
.word 0
glabel D_800690b0
.word 0
glabel D_800690b4
.word 0
glabel D_800690b8
.word 0
glabel D_800690BC
.word 0
glabel D_800690c0
.word 0
glabel D_800690C4
.word 0
glabel D_800690c8
.word 0
glabel D_800690cc
.word 0
glabel D_800690D0
.word 0
glabel D_800690D4
.word 0
glabel D_800690D8
.word 0
glabel D_800690DC
.word 0
glabel D_800690E0
.word 0
.word 0
glabel D_800690E8
.word 0
glabel D_800690EC
.word 0
glabel D_800690F0
.word 0
glabel D_800690F4
.word 0
glabel D_800690F8
.word 0
glabel D_800690FC
.word 0
glabel D_80069100
.word 0
glabel D_80069104
.word 0
glabel D_80069108
.word 0
glabel D_8006910C
.word 0
glabel D_80069110
.word 0
glabel D_80069114
.word 0
glabel D_80069118
.word 0
glabel D_8006911C
.word 0
glabel D_80069120
.word 0
glabel D_80069124
.word 0
glabel D_80069128
.word 0
.word 0
glabel D_80069130
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
