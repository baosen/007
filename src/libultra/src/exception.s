


.section .text 
glabel __osExceptionPreamble
  lui   $k0, %hi(__osException) # $k0, 0x7001
  addiu $k0, %lo(__osException) # addiu $k0, $k0, 0x1a0
  jr    $k0
   nop   
glabel __osException
  lui   $k0, %hi(__osThreadSave) # $k0, 0x8007
  addiu $k0, %lo(__osThreadSave) # addiu $k0, $k0, -0x71d0
  sd    $at, 0x20($k0)
  mfc0  $k1, $12
  sw    $k1, 0x118($k0)
  li    $at, -4
  and   $k1, $k1, $at
  mtc0  $k1, $12
  sd    $t0, 0x58($k0)
  sd    $t1, 0x60($k0)
  sd    $t2, 0x68($k0)
  sw    $zero, 0x18($k0)
  mfc0  $t0, $13
  move  $t0, $k0
  lui   $k0, %hi(__osRunningThread) # $k0, 0x8002
  lw    $k0, %lo(__osRunningThread)($k0)
  ld    $t1, 0x20($t0)
  sd    $t1, 0x20($k0)
  ld    $t1, 0x118($t0)
  sd    $t1, 0x118($k0)
  ld    $t1, 0x58($t0)
  sd    $t1, 0x58($k0)
  ld    $t1, 0x60($t0)
  sd    $t1, 0x60($k0)
  ld    $t1, 0x68($t0)
  sd    $t1, 0x68($k0)
  lw    $k1, 0x118($k0)
  mflo  $t0
  sd    $t0, 0x108($k0)
  mfhi  $t0
  andi  $t1, $k1, 0xff00
  sd    $v0, 0x28($k0)
  sd    $v1, 0x30($k0)
  sd    $a0, 0x38($k0)
  sd    $a1, 0x40($k0)
  sd    $a2, 0x48($k0)
  sd    $a3, 0x50($k0)
  sd    $t3, 0x70($k0)
  sd    $t4, 0x78($k0)
  sd    $t5, 0x80($k0)
  sd    $t6, 0x88($k0)
  sd    $t7, 0x90($k0)
  sd    $s0, 0x98($k0)
  sd    $s1, 0xa0($k0)
  sd    $s2, 0xa8($k0)
  sd    $s3, 0xb0($k0)
  sd    $s4, 0xb8($k0)
  sd    $s5, 0xc0($k0)
  sd    $s6, 0xc8($k0)
  sd    $s7, 0xd0($k0)
  sd    $t8, 0xd8($k0)
  sd    $t9, 0xe0($k0)
  sd    $gp, 0xe8($k0)
  sd    $sp, 0xf0($k0)
  sd    $fp, 0xf8($k0)
  sd    $ra, 0x100($k0)
  beqz  $t1, .L700102B8
   sd    $t0, 0x110($k0)
  lui   $t0, %hi(__OSGlobalIntMask) 
  addiu $t0, %lo(__OSGlobalIntMask) # addiu $t0, $t0, 0x698c
  lw    $t0, ($t0)
  li    $at, -1
  xor   $t0, $t0, $at
  lui   $at, (0xFFFF00FF >> 16) # lui $at, 0xffff
  andi  $t0, $t0, 0xff00
  ori   $at, (0xFFFF00FF & 0xFFFF) # ori $at, $at, 0xff
  or    $t1, $t1, $t0
  and   $k1, $k1, $at
  or    $k1, $k1, $t1
  sw    $k1, 0x118($k0)
.L700102B8:
  lui   $t1, %hi(MI_INTR_MASK_REG) # $t1, 0xa430
  lw    $t1, %lo(MI_INTR_MASK_REG)($t1)
  beqz  $t1, .L700102F0
   nop   
  lui   $t0, %hi(__OSGlobalIntMask) 
  addiu $t0, %lo(__OSGlobalIntMask) # addiu $t0, $t0, 0x698c
  lw    $t0, ($t0)
  lw    $t4, 0x128($k0)
  li    $at, -1
  srl   $t0, $t0, 0x10
  xor   $t0, $t0, $at
  andi  $t0, $t0, 0x3f
  and   $t0, $t0, $t4
  or    $t1, $t1, $t0
.L700102F0:
  sw    $t1, 0x128($k0)
  mfc0  $t0, $14
  sw    $t0, 0x11c($k0)
  lw    $t0, 0x18($k0)
  beqz  $t0, .L70010354
   nop   
  cfc1  $t0, $31
  nop   
  sw    $t0, 0x12c($k0)
  sdc1  $f0, 0x130($k0)
  sdc1  $f2, 0x138($k0)
  sdc1  $f4, 0x140($k0)
  sdc1  $f6, 0x148($k0)
  sdc1  $f8, 0x150($k0)
  sdc1  $f10, 0x158($k0)
  sdc1  $f12, 0x160($k0)
  sdc1  $f14, 0x168($k0)
  sdc1  $f16, 0x170($k0)
  sdc1  $f18, 0x178($k0)
  sdc1  $f20, 0x180($k0)
  sdc1  $f22, 0x188($k0)
  sdc1  $f24, 0x190($k0)
  sdc1  $f26, 0x198($k0)
  sdc1  $f28, 0x1a0($k0)
  sdc1  $f30, 0x1a8($k0)
.L70010354:
  mfc0  $t0, $13
  sw    $t0, 0x120($k0)
  li    $t1, 2
  sh    $t1, 0x10($k0)
  andi  $t1, $t0, 0x7c
  li    $t2, 36
  beq   $t1, $t2, .L70010630
   nop   
  li    $t2, 44
  beq   $t1, $t2, .L70010778
   nop   
  li    $t2, 0
  bne   $t1, $t2, .L70010694
   nop   
  and   $s0, $k1, $t0
glabel next_interrupt
.L70010390:
  andi  $t1, $s0, 0xff00
  srl   $t2, $t1, 0xc
  bnez  $t2, .L700103A8
   nop   
  srl   $t2, $t1, 8
  addi  $t2, $t2, 0x10
.L700103A8:
  lui   $at, %hi(__osIntOffTable)
  addu  $at, $at, $t2
  lbu   $t2, %lo(__osIntOffTable)($at)
  lui   $at, %hi(__osIntTable)
  addu  $at, $at, $t2
  lw    $t2, %lo(__osIntTable)($at)
  jr    $t2
   nop   
glabel IP6_Hdlr
  li    $at, -8193
  b     .L70010390
   and   $s0, $s0, $at
glabel IP7_Hdlr
  li    $at, -16385
  b     .L70010390
   and   $s0, $s0, $at
glabel counter
  mfc0  $t1, $11
  mtc0  $t1, $11
  jal   send_mesg
   li    $a0, 24
  lui   $at, (0xFFFF7FFF >> 16) # lui $at, 0xffff
  ori   $at, (0xFFFF7FFF & 0xFFFF) # ori $at, $at, 0x7fff
  b     .L70010390
   and   $s0, $s0, $at
glabel cart
  li    $at, -2049
  and   $s0, $s0, $at
  li    $t2, 4
  lui   $at, %hi(__osHwIntTable)
  addu  $at, $at, $t2
  lw    $t2, %lo(__osHwIntTable)($at)
  lui   $sp, %hi(leoDiskStack) # $sp, 0x8006
  addiu $sp, %lo(leoDiskStack) # addiu $sp, $sp, 0x7df0
  li    $a0, 16
  beqz  $t2, .L70010444
   addiu $sp, $sp, 0xff0
  jalr  $t2
  nop   
  beqz  $v0, .L70010444
   nop   
  b     .L70010648
   nop   
.L70010444:
  jal   send_mesg
   nop   
  b     .L70010390
   nop   
glabel rcp
  lui   $t0, %hi(__OSGlobalIntMask) 
  addiu $t0, %lo(__OSGlobalIntMask) # addiu $t0, $t0, 0x698c
  lw    $t0, ($t0)
  lui   $s1, %hi(MI_INTR_REG) # $s1, 0xa430
  lw    $s1, %lo(MI_INTR_REG)($s1)
  srl   $t0, $t0, 0x10
  and   $s1, $s1, $t0
  andi  $t1, $s1, 1
  beqz  $t1, .L700104C4
   nop   
  lui   $t4, %hi(SP_STATUS_REG) # $t4, 0xa404
  lw    $t4, %lo(SP_STATUS_REG)($t4)
  li    $t1, 8
  lui   $at, %hi(SP_STATUS_REG) # $at, 0xa404
  andi  $t4, $t4, 0x300
  andi  $s1, $s1, 0x3e
  beqz  $t4, .L700104B4
   sw    $t1, %lo(SP_STATUS_REG)($at)
  jal   send_mesg
   li    $a0, 32
  beqz  $s1, .L70010588
   nop   
  b     .L700104C4
   nop   
.L700104B4:
  jal   send_mesg
   li    $a0, 88
  beqz  $s1, .L70010588
   nop   
.L700104C4:
  andi  $t1, $s1, 8
  beqz  $t1, .L700104E8
   lui   $at, %hi(VI_CURRENT_REG) # $at, 0xa440
  andi  $s1, $s1, 0x37
  sw    $zero, %lo(VI_CURRENT_REG)($at)
  jal   send_mesg
   li    $a0, 56
  beqz  $s1, .L70010588
   nop   
.L700104E8:
  andi  $t1, $s1, 4
  beqz  $t1, .L70010514
   nop   
  li    $t1, 1
  lui   $at, %hi(AI_STATUS_REG) # $at, 0xa450
  andi  $s1, $s1, 0x3b
  sw    $t1, %lo(AI_STATUS_REG)($at)
  jal   send_mesg
   li    $a0, 48
  beqz  $s1, .L70010588
   nop   
.L70010514:
  andi  $t1, $s1, 2
  beqz  $t1, .L70010538
   lui   $at, %hi(SI_STATUS_REG) # $at, 0xa480
  andi  $s1, $s1, 0x3d
  sw    $zero, %lo(SI_STATUS_REG)($at)
  jal   send_mesg
   li    $a0, 40
  beqz  $s1, .L70010588
   nop   
.L70010538:
  andi  $t1, $s1, 0x10
  beqz  $t1, .L70010564
   nop   
  li    $t1, 2
  lui   $at, %hi(PI_STATUS_REG) # $at, 0xa460
  andi  $s1, $s1, 0x2f
  sw    $t1, %lo(PI_STATUS_REG)($at)
  jal   send_mesg
   li    $a0, 64
  beqz  $s1, .L70010588
   nop   
.L70010564:
  andi  $t1, $s1, 0x20
  beqz  $t1, .L70010588
   nop   
  li    $t1, 2048
  lui   $at, 0xa430
  andi  $s1, $s1, 0x1f
  sw    $t1, ($at)
  jal   send_mesg
   li    $a0, 72
.L70010588:
  li    $at, -1025
  b     .L70010390
   and   $s0, $s0, $at
glabel prenmi
  lw    $k1, 0x118($k0)
  li    $at, -4097
  lui   $t1, %hi(__osShutdown) 
  and   $k1, $k1, $at
  sw    $k1, 0x118($k0)
  addiu $t1, %lo(__osShutdown) # addiu $t1, $t1, 0x6988
  lw    $t2, ($t1)
  beqz  $t2, .L700105C0
   li    $at, -4097
  b     .L70010648
   and   $s0, $s0, $at
.L700105C0:
  li    $t2, 1
  sw    $t2, ($t1)
  jal   send_mesg
   li    $a0, 112
  lui   $t2, %hi(__osRunQueue) 
  lw    $t2, %lo(__osRunQueue)($t2)
  li    $at, -4097
  and   $s0, $s0, $at
  lw    $k1, 0x118($t2)
  and   $k1, $k1, $at
  b     .L70010648
   sw    $k1, 0x118($t2)
glabel sw2
  li    $at, -513
  and   $t0, $t0, $at
  mtc0  $t0, $13
  jal   send_mesg
   li    $a0, 8
  li    $at, -513
  b     .L70010390
   and   $s0, $s0, $at
glabel swl
  li    $at, -257
  and   $t0, $t0, $at
  mtc0  $t0, $13
  jal   send_mesg
   li    $a0, 0
  li    $at, -257
  b     .L70010390
   and   $s0, $s0, $at
.L70010630:
  li    $t1, 1
  sh    $t1, 0x12($k0)
  jal   send_mesg
   li    $a0, 80
  b     .L70010648
   nop   
glabel redispatch
.L70010648:
  lui   $t2, %hi(__osRunQueue) 
  lw    $t2, %lo(__osRunQueue)($t2)
  lw    $t1, 4($k0)
  lw    $t3, 4($t2)
  slt   $at, $t1, $t3
  beqz  $at, .L7001067C
   nop   
  lui   $a0, %hi(__osRunQueue)
  move  $a1, $k0
  jal   __osEnqueueThread
   addiu $a0, %lo(__osRunQueue) # addiu $a0, $a0, 0x7728
  j     __osDispatchThread
   nop   

glabel enqueueRunning
.L7001067C:
  lui   $t1, %hi(__osRunQueue) 
  addiu $t1, %lo(__osRunQueue) # addiu $t1, $t1, 0x7728
  lw    $t2, ($t1)
  sw    $t2, ($k0)
  j     __osDispatchThread
   sw    $k0, ($t1)

.L70010694:
  lui   $at, %hi(__osFaultedThread)
  sw    $k0, %lo(__osFaultedThread)($at)
  li    $t1, 1
  sh    $t1, 0x10($k0)
  li    $t1, 2
  sh    $t1, 0x12($k0)
  mfc0  $t2, $8
  sw    $t2, 0x124($k0)
  jal   send_mesg
   li    $a0, 96
  j     __osDispatchThread
   nop   

glabel send_mesg
  lui   $t2, %hi(__osEventStateTab) 
  addiu $t2, %lo(__osEventStateTab) # addiu $t2, $t2, 0x6a10
  addu  $t2, $t2, $a0
  lw    $t1, ($t2)
  move  $s2, $ra
  beqz  $t1, .L70010770
   nop   
  lw    $t3, 8($t1)
  lw    $t4, 0x10($t1)
  slt   $at, $t3, $t4
  beqz  $at, .L70010770
   nop   
  lw    $t5, 0xc($t1)
  addu  $t5, $t5, $t3
  div   $zero, $t5, $t4
  bnez  $t4, .L7001070C
   nop   
  break 7
.L7001070C:
  li    $at, -1
  bne   $t4, $at, .L70010724
   lui   $at, 0x8000
  bne   $t5, $at, .L70010724
   nop   
  break 6
.L70010724:
  lw    $t4, 0x14($t1)
  mfhi  $t5
  sll   $t5, $t5, 2
  addu  $t4, $t4, $t5
  lw    $t5, 4($t2)
  addiu $t2, $t3, 1
  sw    $t5, ($t4)
  sw    $t2, 8($t1)
  lw    $t2, ($t1)
  lw    $t3, ($t2)
  beqz  $t3, .L70010770
   nop   
  jal   __osPopThread
   move  $a0, $t1
  move  $t2, $v0
  lui   $a0, %hi(__osRunQueue)
  move  $a1, $t2
  jal   __osEnqueueThread
   addiu $a0, %lo(__osRunQueue) # addiu $a0, $a0, 0x7728
.L70010770:
  jr    $s2
   nop   
glabel handle_CpU
.L70010778:
  lui   $at, 0x3000
  and   $t1, $t0, $at
  srl   $t1, $t1, 0x1c
  li    $t2, 1
  bne   $t1, $t2, .L70010694
   nop   
  lw    $k1, 0x118($k0)
  lui   $at, 0x2000
  li    $t1, 1
  or    $k1, $k1, $at
  sw    $t1, 0x18($k0)
  b     .L7001067C
   sw    $k1, 0x118($k0)
glabel __osEnqueueAndYield
  lui   $a1, %hi(__osRunningThread)
  lw    $a1, %lo(__osRunningThread)($a1)
  mfc0  $t0, $12
  lw    $k1, 0x18($a1)
  ori   $t0, $t0, 2
  sw    $t0, 0x118($a1)
  sd    $s0, 0x98($a1)
  sd    $s1, 0xa0($a1)
  sd    $s2, 0xa8($a1)
  sd    $s3, 0xb0($a1)
  sd    $s4, 0xb8($a1)
  sd    $s5, 0xc0($a1)
  sd    $s6, 0xc8($a1)
  sd    $s7, 0xd0($a1)
  sd    $gp, 0xe8($a1)
  sd    $sp, 0xf0($a1)
  sd    $fp, 0xf8($a1)
  sd    $ra, 0x100($a1)
  beqz  $k1, .L7001081C
   sw    $ra, 0x11c($a1)
  cfc1  $k1, $31
  sdc1  $f20, 0x180($a1)
  sdc1  $f22, 0x188($a1)
  sdc1  $f24, 0x190($a1)
  sdc1  $f26, 0x198($a1)
  sdc1  $f28, 0x1a0($a1)
  sdc1  $f30, 0x1a8($a1)
  sw    $k1, 0x12c($a1)
.L7001081C:
  lw    $k1, 0x118($a1)
  andi  $t1, $k1, 0xff00
  beqz  $t1, .L7001085C
   nop   
  lui   $t0, %hi(__OSGlobalIntMask) 
  addiu $t0, %lo(__OSGlobalIntMask) # addiu $t0, $t0, 0x698c
  lw    $t0, ($t0)
  li    $at, -1
  xor   $t0, $t0, $at
  lui   $at, (0xFFFF00FF >> 16) # lui $at, 0xffff
  andi  $t0, $t0, 0xff00
  ori   $at, (0xFFFF00FF & 0xFFFF) # ori $at, $at, 0xff
  or    $t1, $t1, $t0
  and   $k1, $k1, $at
  or    $k1, $k1, $t1
  sw    $k1, 0x118($a1)
.L7001085C:
  lui   $k1, %hi(MI_INTR_MASK_REG) # $k1, 0xa430
  lw    $k1, %lo(MI_INTR_MASK_REG)($k1)
  beqz  $k1, .L70010894
   nop   
  lui   $k0, %hi(__OSGlobalIntMask) # $k0, 0x8002
  addiu $k0, %lo(__OSGlobalIntMask) # addiu $k0, $k0, 0x698c
  lw    $k0, ($k0)
  lw    $t0, 0x128($a1)
  li    $at, -1
  srl   $k0, $k0, 0x10
  xor   $k0, $k0, $at
  andi  $k0, $k0, 0x3f
  and   $k0, $k0, $t0
  or    $k1, $k1, $k0
.L70010894:
  beqz  $a0, .L700108A4
   sw    $k1, 0x128($a1)
  jal   __osEnqueueThread
   nop   
.L700108A4:
  j     __osDispatchThread
   nop   

glabel __osEnqueueThread
  lw    $t8, ($a0)
  lw    $t7, 4($a1)
  move  $t9, $a0
  lw    $t6, 4($t8)
  slt   $at, $t6, $t7
  bnez  $at, .L700108E0
   nop   
.L700108C8:
  move  $t9, $t8
  lw    $t8, ($t8)
  lw    $t6, 4($t8)
  slt   $at, $t6, $t7
  beqz  $at, .L700108C8
   nop   
.L700108E0:
  lw    $t8, ($t9)
  sw    $t8, ($a1)
  sw    $a1, ($t9)
  jr    $ra
   sw    $a0, 8($a1)

glabel __osPopThread
  lw    $v0, ($a0)
  lw    $t9, ($v0)
  jr    $ra
   sw    $t9, ($a0)

glabel __osDispatchThread
  lui   $a0, %hi(__osRunQueue)
  jal   __osPopThread
   addiu $a0, %lo(__osRunQueue) # addiu $a0, $a0, 0x7728
  lui   $at, %hi(__osRunningThread)
  sw    $v0, %lo(__osRunningThread)($at)
  li    $t0, 4
  sh    $t0, 0x10($v0)
  move  $k0, $v0
glabel __osDispatchThreadSave
  lui   $t0, %hi(__OSGlobalIntMask) 
  lw    $k1, 0x118($k0)
  addiu $t0, %lo(__OSGlobalIntMask) # addiu $t0, $t0, 0x698c
  lw    $t0, ($t0)
  lui   $at, (0xFFFF00FF >> 16) # lui $at, 0xffff
  andi  $t1, $k1, 0xff00
  ori   $at, (0xFFFF00FF & 0xFFFF) # ori $at, $at, 0xff
  andi  $t0, $t0, 0xff00
  and   $t1, $t1, $t0
  and   $k1, $k1, $at
  or    $k1, $k1, $t1
  mtc0  $k1, $12
  ld    $k1, 0x108($k0)
  ld    $at, 0x20($k0)
  ld    $v0, 0x28($k0)
  mtlo  $k1
  ld    $k1, 0x110($k0)
  ld    $v1, 0x30($k0)
  ld    $a0, 0x38($k0)
  ld    $a1, 0x40($k0)
  ld    $a2, 0x48($k0)
  ld    $a3, 0x50($k0)
  ld    $t0, 0x58($k0)
  ld    $t1, 0x60($k0)
  ld    $t2, 0x68($k0)
  ld    $t3, 0x70($k0)
  ld    $t4, 0x78($k0)
  ld    $t5, 0x80($k0)
  ld    $t6, 0x88($k0)
  ld    $t7, 0x90($k0)
  ld    $s0, 0x98($k0)
  ld    $s1, 0xa0($k0)
  ld    $s2, 0xa8($k0)
  ld    $s3, 0xb0($k0)
  ld    $s4, 0xb8($k0)
  ld    $s5, 0xc0($k0)
  ld    $s6, 0xc8($k0)
  ld    $s7, 0xd0($k0)
  ld    $t8, 0xd8($k0)
  ld    $t9, 0xe0($k0)
  ld    $gp, 0xe8($k0)
  mthi  $k1
  ld    $sp, 0xf0($k0)
  ld    $fp, 0xf8($k0)
  ld    $ra, 0x100($k0)
  lw    $k1, 0x11c($k0)
  mtc0  $k1, $14
  lw    $k1, 0x18($k0)
  beqz  $k1, .L70010A34
   nop   
  lw    $k1, 0x12c($k0)
  ctc1  $k1, $31
  ldc1  $f0, 0x130($k0)
  ldc1  $f2, 0x138($k0)
  ldc1  $f4, 0x140($k0)
  ldc1  $f6, 0x148($k0)
  ldc1  $f8, 0x150($k0)
  ldc1  $f10, 0x158($k0)
  ldc1  $f12, 0x160($k0)
  ldc1  $f14, 0x168($k0)
  ldc1  $f16, 0x170($k0)
  ldc1  $f18, 0x178($k0)
  ldc1  $f20, 0x180($k0)
  ldc1  $f22, 0x188($k0)
  ldc1  $f24, 0x190($k0)
  ldc1  $f26, 0x198($k0)
  ldc1  $f28, 0x1a0($k0)
  ldc1  $f30, 0x1a8($k0)
.L70010A34:
  lw    $k1, 0x128($k0)
  lui   $k0, %hi(__OSGlobalIntMask) # $k0, 0x8002
  addiu $k0, %lo(__OSGlobalIntMask) # addiu $k0, $k0, 0x698c
  lw    $k0, ($k0)
  srl   $k0, $k0, 0x10
  and   $k1, $k1, $k0
  sll   $k1, $k1, 1
  lui   $k0, %hi(__osRcpImTable) # $k0, 0x8003
  addiu $k0, %lo(__osRcpImTable) # addiu $k0, $k0, -0x6c60
  addu  $k1, $k1, $k0
  lhu   $k1, ($k1)
  lui   $k0, %hi(MI_INTR_MASK_REG) # $k0, 0xa430
  addiu $k0, %lo(MI_INTR_MASK_REG) # addiu $k0, $k0, 0xc
  sw    $k1, ($k0)
  nop   
  nop   
  nop   
  nop   
  eret  
glabel __osCleanupThread
  jal   osDestroyThread
   move  $a0, $zero


.section .data
/*80027704*/
glabel __osHwIntTable
.word          0,         0,         0,         0
.word          0,         0,         0,         0

.section .rodata
/*80029440*/
glabel __osIntOffTable
.byte    0,0x14,0x18,0x18,0x1C,0x1C,0x1C,0x1C
.byte 0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20
.byte    0,   4,   8,   8, 0xC, 0xC, 0xC, 0xC
.byte 0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10

/*80029460*/
glabel __osIntTable
.word redispatch
.word swl
.word sw2
.word rcp
.word cart
.word prenmi
.word IP6_Hdlr
.word IP7_Hdlr
.word counter
