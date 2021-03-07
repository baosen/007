


.section .text
.ifndef VERSION_EU
glabel osCreatePiManager
  addiu $sp, $sp, -0x30
  lui   $t6, %hi(__osPiDevMgr) 
  lw    $t6, %lo(__osPiDevMgr)($t6)
  sw    $ra, 0x1c($sp)
  sw    $a0, 0x30($sp)
  sw    $a1, 0x34($sp)
  sw    $a2, 0x38($sp)
  bnez  $t6, .L70014728
   sw    $a3, 0x3c($sp)
  lw    $a0, 0x34($sp)
  lw    $a1, 0x38($sp)
  jal   osCreateMesgQueue
   lw    $a2, 0x3c($sp)
  lui   $a0, %hi(pieventQueue)
  lui   $a1, %hi(piEventBuf)
  addiu $a1, %lo(piEventBuf) # addiu $a1, $a1, 0x7c98
  addiu $a0, %lo(pieventQueue) # addiu $a0, $a0, 0x7c80
  jal   osCreateMesgQueue
   li    $a2, 1
  lui   $t7, %hi(__osPiAccessQueueEnabled) 
  lw    $t7, %lo(__osPiAccessQueueEnabled)($t7)
  bnez  $t7, .L70014614
   nop   
  jal   __osPiCreateAccessQueue
   nop   
.L70014614:
  lui   $a1, %hi(pieventQueue)
  lui   $a2, (0x22222222 >> 16) # lui $a2, 0x2222
  ori   $a2, (0x22222222 & 0xFFFF) # ori $a2, $a2, 0x2222
  addiu $a1, %lo(pieventQueue) # addiu $a1, $a1, 0x7c80
  jal   osSetEventMesg
   li    $a0, 8
  li    $t8, -1
  sw    $t8, 0x28($sp)
  jal   osGetThreadPri
   move  $a0, $zero
  sw    $v0, 0x24($sp)
  lw    $t9, 0x24($sp)
  lw    $t0, 0x30($sp)
  slt   $at, $t9, $t0
  beqz  $at, .L70014664
   nop   
  sw    $t9, 0x28($sp)
  move  $a0, $zero
  jal   osSetThreadPri
   move  $a1, $t0
.L70014664:
  jal   __osDisableInt
   nop   
  lui   $at, %hi(__osPiDevMgr.cmdQueue)
  lw    $t3, 0x34($sp)
  lui   $t2, %hi(piThread) 
  lui   $t4, %hi(pieventQueue) 
  li    $t1, 1
  addiu $t2, %lo(piThread) # addiu $t2, $t2, 0x6ad0
  addiu $t4, %lo(pieventQueue) # addiu $t4, $t4, 0x7c80
  sw    $t1, %lo(__osPiDevMgr)($at)
  sw    $t2, %lo(__osPiDevMgr.thread)($at)
  sw    $t4, %lo(__osPiDevMgr.evtQueue)($at)
  lui   $t8, %hi(piThreadStack)
  sw    $t3, %lo(__osPiDevMgr.cmdQueue)($at)
  lw    $t0, 0x30($sp)
  lui   $at, %hi(__osPiDevMgr.edma)
  lui   $t5, %hi(__osPiAccessQueue) 
  lui   $t6, %hi(osPiRawStartDma) # $t6, 0x7001
  lui   $t7, %hi(osEPiRawStartDma) # $t7, 0x7002
  addiu $t8, $t8, %lo(piThreadStack)
  addiu $t5, %lo(__osPiAccessQueue) # addiu $t5, $t5, -0x7018
  addiu $t6, %lo(osPiRawStartDma) # addiu $t6, $t6, -0x3070
  addiu $t7, %lo(osEPiRawStartDma) # addiu $t7, $t7, -0x1ad0
  addiu $t9, $t8, 0x1000
  lui   $a2, %hi(__osDevMgrMain) # $a2, 0x7002
  lui   $a3, %hi(__osPiDevMgr)
  sw    $v0, 0x2c($sp)
  sw    $t5, %lo(__osPiDevMgr.acsQueue)($at)
  sw    $t6, %lo(__osPiDevMgr.dma)($at)
  sw    $t7, %lo(__osPiDevMgr.edma)($at)
  addiu $a3, %lo(__osPiDevMgr) # addiu $a3, $a3, 0x7790
  addiu $a2, %lo(__osDevMgrMain) # addiu $a2, $a2, -0x19f0
  sw    $t9, 0x10($sp)
  move  $a0, $t2
  move  $a1, $zero
  jal   osCreateThread
   sw    $t0, 0x14($sp)
  lui   $a0, %hi(piThread)
  jal   osStartThread
   addiu $a0, %lo(piThread) # addiu $a0, $a0, 0x6ad0
  jal   __osRestoreInt
   lw    $a0, 0x2c($sp)
  lw    $t1, 0x28($sp)
  li    $at, -1
  beq   $t1, $at, .L70014728
   nop   
  move  $a0, $zero
  jal   osSetThreadPri
   move  $a1, $t1
.L70014728:
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
.endif
.ifdef VERSION_EU
glabel osCreatePiManager
  addiu $sp, $sp, -0x30
  sw    $s0, 0x20($sp)
  lui   $s0, %hi(__osPiDevMgr) # $s0, 0x8002
  addiu $s0, %lo(__osPiDevMgr) # addiu $s0, $s0, 0xfb0
  lw    $t6, ($s0)
  sw    $ra, 0x24($sp)
  sw    $a0, 0x30($sp)
  sw    $a1, 0x34($sp)
  bnez  $t6, .L70001C4C
   sw    $a2, 0x38($sp)
  move  $a0, $a1
  move  $a1, $a2
  jal   osCreateMesgQueue
   move  $a2, $a3
  lui   $a0, %hi(pieventQueue) # $a0, 0x8005
  lui   $a1, %hi(piEventBuf) # $a1, 0x8005
  addiu $a1, %lo(piEventBuf) # addiu $a1, $a1, 0x2598
  addiu $a0, %lo(pieventQueue) # addiu $a0, $a0, 0x2580
  jal   osCreateMesgQueue
   li    $a2, 1
  lui   $t7, %hi(__osPiAccessQueueEnabled) # $t7, 0x8002
  lw    $t7, %lo(__osPiAccessQueueEnabled)($t7)
  bnez  $t7, .L70001B58
   nop   
  jal   __osPiCreateAccessQueue
   nop   
.L70001B58:
  lui   $a1, %hi(pieventQueue) # $a1, 0x8005
  lui   $a2, (0x22222222 >> 16) # lui $a2, 0x2222
  ori   $a2, (0x22222222 & 0xFFFF) # ori $a2, $a2, 0x2222
  addiu $a1, %lo(pieventQueue) # addiu $a1, $a1, 0x2580
  jal   osSetEventMesg
   li    $a0, 8
  li    $t8, -1
  sw    $t8, 0x28($sp)
  jal   osGetThreadPri
   move  $a0, $zero
  lw    $t9, 0x30($sp)
  move  $a0, $zero
  slt   $at, $v0, $t9
  beqz  $at, .L70001B9C
   move  $a1, $t9
  jal   osSetThreadPri
   sw    $v0, 0x28($sp)
.L70001B9C:
  jal   __osDisableInt
   nop   
  lw    $t1, 0x34($sp)
  lw    $t7, 0x30($sp)
  lui   $a0, %hi(piThread) # $a0, 0x8005
  lui   $t2, %hi(pieventQueue) # $t2, 0x8005
  lui   $t3, %hi(__osPiAccessQueue) # $t3, 0x8005
  lui   $t4, %hi(osPiRawStartDma) # $t4, 0x7001
  lui   $t5, %hi(osEPiRawStartDma) # $t5, 0x7001
  lui   $t6, %hi(pieventQueue) # $t6, 0x8005
  addiu $a0, %lo(piThread) # addiu $a0, $a0, 0x22d0
  li    $t0, 1
  addiu $t2, %lo(pieventQueue) # addiu $t2, $t2, 0x2580
  addiu $t3, %lo(__osPiAccessQueue) # addiu $t3, $t3, 0x7ca8
  addiu $t4, %lo(osPiRawStartDma) # addiu $t4, $t4, -0x4310
  addiu $t5, %lo(osEPiRawStartDma) # addiu $t5, $t5, -0x23e0
  addiu $t6, %lo(pieventQueue) # addiu $t6, $t6, 0x2580
  lui   $a2, %hi(__osDevMgrMain) # $a2, 0x7001
  sw    $v0, 0x2c($sp)
  sw    $t0, ($s0)
  sw    $a0, 4($s0)
  sw    $t2, 0xc($s0)
  sw    $t3, 0x10($s0)
  sw    $t4, 0x14($s0)
  sw    $t5, 0x18($s0)
  addiu $a2, %lo(__osDevMgrMain) # addiu $a2, $a2, -0x2300
  sw    $t6, 0x10($sp)
  move  $a1, $zero
  move  $a3, $s0
  sw    $t1, 8($s0)
  jal   osCreateThread
   sw    $t7, 0x14($sp)
  lui   $a0, %hi(piThread) # $a0, 0x8005
  jal   osStartThread
   addiu $a0, %lo(piThread) # addiu $a0, $a0, 0x22d0
  jal   __osRestoreInt
   lw    $a0, 0x2c($sp)
  lw    $t8, 0x28($sp)
  li    $at, -1
  move  $a0, $zero
  beql  $t8, $at, .L70001C50
   lw    $ra, 0x24($sp)
  jal   osSetThreadPri
   move  $a1, $t8
.L70001C4C:
  lw    $ra, 0x24($sp)
.L70001C50:
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
.endif


.section .data
glabel __osPiDevMgr
glabel __osPiDevMgr.active
.word 0
glabel __osPiDevMgr.thread
.word 0
glabel __osPiDevMgr.cmdQueue
.word 0
glabel __osPiDevMgr.evtQueue
.word 0
glabel __osPiDevMgr.acsQueue
.word 0
glabel __osPiDevMgr.dma
.word 0
glabel __osPiDevMgr.edma
.word 0


glabel __osPiTable
.word 0

.section .bss
glabel piThread
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0
.word 0,0,0,0

glabel piThreadStack
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0
.word 0, 0, 0, 0

glabel pieventQueue
.word 0, 0, 0, 0, 0, 0

glabel piEventBuf
.word 0, 0
