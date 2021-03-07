


.section .text 

.ifndef VERSION_EU
glabel osCreateViManager
  lui   $t6, %hi(__osViDevMgr) 
  lw    $t6, %lo(__osViDevMgr)($t6)
  addiu $sp, $sp, -0x30
  sw    $ra, 0x1c($sp)
  bnez  $t6, .L7000DA68
   sw    $a0, 0x30($sp)
  jal   __osTimerServicesInit
   nop   
  lui   $a0, %hi(viEventQueue)
  lui   $a1, %hi(viEventBuf)
  addiu $a1, %lo(viEventBuf) # addiu $a1, $a1, 0x69b8
  addiu $a0, %lo(viEventQueue) # addiu $a0, $a0, 0x69a0
  jal   osCreateMesgQueue
   li    $a2, 5
  lui   $at, %hi(viRetraceMsg+0x4)
  li    $t7, 13
  sh    $t7, %lo(viRetraceMsg)($at)
  sb    $zero, %lo(viRetraceMsg+0x2)($at)
  sw    $zero, %lo(viRetraceMsg+0x4)($at)
  lui   $at, %hi(viCounterMsg+0x4)
  li    $t8, 14
  lui   $a1, %hi(viEventQueue)
  lui   $a2, %hi(viRetraceMsg)
  sh    $t8, %lo(viCounterMsg)($at)
  sb    $zero, %lo(viCounterMsg+0x2)($at)
  sw    $zero, %lo(viCounterMsg+0x4)($at)
  addiu $a2, %lo(viRetraceMsg) # addiu $a2, $a2, 0x69d0
  addiu $a1, %lo(viEventQueue) # addiu $a1, $a1, 0x69a0
  jal   osSetEventMesg
   li    $a0, 7
  lui   $a1, %hi(viEventQueue)
  lui   $a2, %hi(viCounterMsg)
  addiu $a2, %lo(viCounterMsg) # addiu $a2, $a2, 0x69e8
  addiu $a1, %lo(viEventQueue) # addiu $a1, $a1, 0x69a0
  jal   osSetEventMesg
   li    $a0, 3
  li    $t9, -1
  sw    $t9, 0x28($sp)
  jal   osGetThreadPri
   move  $a0, $zero
  sw    $v0, 0x24($sp)
  lw    $t0, 0x24($sp)
  lw    $t1, 0x30($sp)
  slt   $at, $t0, $t1
  beqz  $at, .L7000D9B8
   nop   
  sw    $t0, 0x28($sp)
  move  $a0, $zero
  jal   osSetThreadPri
   move  $a1, $t1
.L7000D9B8:
  jal   __osDisableInt
   nop   
  lui   $at, %hi(D_800269AC)
  lui   $t4, %hi(viEventQueue) 
  lui   $t3, %hi(viThread) 
  addiu $t4, %lo(viEventQueue) # addiu $t4, $t4, 0x69a0
  li    $t2, 1
  addiu $t3, %lo(viThread) # addiu $t3, $t3, 0x57f0
  sw    $t2, %lo(__osViDevMgr)($at)
  sw    $t3, %lo(D_800269A4)($at)
  sw    $t4, %lo(D_800269A8)($at)
  sw    $t4, %lo(D_800269AC)($at)
  lui   $t5, %hi(viThreadStack) 
  lw    $t7, 0x30($sp)
  lui   $at, %hi(D_800269B8)
  addiu $t5, %lo(viThreadStack) # addiu $t5, $t5, 0x59a0
  addiu $t6, $t5, 0x1000
  lui   $a2, %hi(viMgrMain) # $a2, 0x7001
  lui   $a3, %hi(__osViDevMgr)
  sw    $v0, 0x2c($sp)
  sw    $zero, %lo(D_800269B0)($at)
  sw    $zero, %lo(D_800269B4)($at)
  sw    $zero, %lo(D_800269B8)($at)
  addiu $a3, %lo(__osViDevMgr) # addiu $a3, $a3, 0x69a0
  addiu $a2, %lo(viMgrMain) # addiu $a2, $a2, -0x2588
  sw    $t6, 0x10($sp)
  move  $a0, $t3
  move  $a1, $zero
  jal   osCreateThread
   sw    $t7, 0x14($sp)
  jal   __osViInit
   nop   
  lui   $a0, %hi(viThread)
  jal   osStartThread
   addiu $a0, %lo(viThread) # addiu $a0, $a0, 0x57f0
  jal   __osRestoreInt
   lw    $a0, 0x2c($sp)
  lw    $t8, 0x28($sp)
  li    $at, -1
  beq   $t8, $at, .L7000DA68
   nop   
  move  $a0, $zero
  jal   osSetThreadPri
   move  $a1, $t8
.L7000DA68:
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
.endif
.ifdef VERSION_EU
glabel osCreateViManager
  addiu $sp, $sp, -0x30
  sw    $s0, 0x20($sp)
  lui   $s0, %hi(__osViDevMgr) # $s0, 0x8002
  addiu $s0, %lo(__osViDevMgr) # addiu $s0, $s0, 0xf90
  lw    $t6, ($s0)
  sw    $ra, 0x24($sp)
  sw    $a0, 0x30($sp)
  bnezl $t6, .L70001948
   lw    $ra, 0x24($sp)
  jal   __osTimerServicesInit
   nop   
  lui   $a0, %hi(viEventQueue) # $a0, 0x8005
  lui   $a1, %hi(viEventBuf) # $a1, 0x8005
  addiu $a1, %lo(viEventBuf) # addiu $a1, $a1, 0x2278
  addiu $a0, %lo(viEventQueue) # addiu $a0, $a0, 0x2260
  jal   osCreateMesgQueue
   li    $a2, 5
  lui   $a2, %hi(viRetraceMsg) # $a2, 0x8005
  lui   $a3, %hi(viCounterMsg) # $a3, 0x8005
  addiu $a3, %lo(viCounterMsg) # addiu $a3, $a3, 0x22a8
  addiu $a2, %lo(viRetraceMsg) # addiu $a2, $a2, 0x2290
  li    $t7, 13
  li    $t8, 14
  lui   $a1, %hi(viEventQueue) # $a1, 0x8005
  sh    $t7, ($a2)
  sb    $zero, 2($a2)
  sw    $zero, 4($a2)
  sh    $t8, ($a3)
  sb    $zero, 2($a3)
  sw    $zero, 4($a3)
  addiu $a1, %lo(viEventQueue) # addiu $a1, $a1, 0x2260
  jal   osSetEventMesg
   li    $a0, 7
  lui   $a3, %hi(viCounterMsg)
  lui   $a1, %hi(viEventQueue) # $a1, 0x8005
  addiu $a2, $a3, %lo(viCounterMsg)
  addiu $a1, %lo(viEventQueue) # addiu $a1, $a1, 0x2260
  jal   osSetEventMesg
   li    $a0, 3
  li    $t9, -1
  sw    $t9, 0x28($sp)
  jal   osGetThreadPri
   move  $a0, $zero
  lw    $t0, 0x30($sp)
  move  $a0, $zero
  slt   $at, $v0, $t0
  beqz  $at, .L700018A8
   move  $a1, $t0
  jal   osSetThreadPri
   sw    $v0, 0x28($sp)
.L700018A8:
  jal   __osDisableInt
   nop   
  lw    $t3, 0x30($sp)
  lui   $v1, %hi(viEventQueue) # $v1, 0x8005
  lui   $a0, %hi(viThread) # $a0, 0x8005
  lui   $t2, %hi(viEventQueue) # $t2, 0x8005
  addiu $a0, %lo(viThread) # addiu $a0, $a0, 0x1fb0
  addiu $v1, %lo(viEventQueue) # addiu $v1, $v1, 0x2260
  li    $t1, 1
  addiu $t2, %lo(viEventQueue) # addiu $t2, $t2, 0x2260
  lui   $a2, %hi(viMgrMain) # $a2, 0x7000
  sw    $v0, 0x2c($sp)
  sw    $t1, ($s0)
  sw    $a0, 4($s0)
  sw    $v1, 8($s0)
  sw    $v1, 0xc($s0)
  sw    $zero, 0x10($s0)
  sw    $zero, 0x14($s0)
  sw    $zero, 0x18($s0)
  addiu $a2, %lo(viMgrMain) # addiu $a2, $a2, 0x1958
  sw    $t2, 0x10($sp)
  move  $a1, $zero
  move  $a3, $s0
  jal   osCreateThread
   sw    $t3, 0x14($sp)
  jal   __osViInit
   nop   
  lui   $a0, %hi(viThread) # $a0, 0x8005
  jal   osStartThread
   addiu $a0, %lo(viThread) # addiu $a0, $a0, 0x1fb0
  jal   __osRestoreInt
   lw    $a0, 0x2c($sp)
  lw    $t4, 0x28($sp)
  li    $at, -1
  move  $a0, $zero
  beql  $t4, $at, .L70001948
   lw    $ra, 0x24($sp)
  jal   osSetThreadPri
   move  $a1, $t4
  lw    $ra, 0x24($sp)
.L70001948:
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
.endif

.ifndef VERSION_EU
glabel viMgrMain
  addiu $sp, $sp, -0x38
  sw    $ra, 0x1c($sp)
  sw    $a0, 0x38($sp)
  sw    $s0, 0x18($sp)
  sw    $zero, 0x2c($sp)
  jal   __osViGetCurrentContext
   sw    $zero, 0x28($sp)
  sw    $v0, 0x34($sp)
  lw    $t6, 0x34($sp)
  lui   $at, %hi(retrace)
  lhu   $t7, 2($t6)
  bnez  $t7, .L7000DAB8
   sh    $t7, %lo(retrace)($at)
  li    $t8, 1
  lui   $at, %hi(retrace)
  sh    $t8, %lo(retrace)($at)
.L7000DAB8:
  lw    $t9, 0x38($sp)
  sw    $t9, 0x30($sp)
.L7000DAC0:
  lw    $t0, 0x30($sp)
  addiu $a1, $sp, 0x2c
  li    $a2, 1
  jal   osRecvMesg
   lw    $a0, 0xc($t0)
  lw    $t1, 0x2c($sp)
  li    $at, 13
  lhu   $s0, ($t1)
  beq   $s0, $at, .L7000DAF8
   li    $at, 14
  beq   $s0, $at, .L7000DC08
   nop   
  b     .L7000DAC0
   nop   
.L7000DAF8:
  jal   __osViSwapContext
   nop   
  lui   $t2, %hi(retrace) 
  lhu   $t2, %lo(retrace)($t2)
  lui   $at, %hi(retrace)
  addiu $t3, $t2, -1
  andi  $t4, $t3, 0xffff
  bnez  $t4, .L7000DB58
   sh    $t3, %lo(retrace)($at)
  jal   __osViGetCurrentContext
   nop   
  sw    $v0, 0x34($sp)
  lw    $t5, 0x34($sp)
  lw    $t6, 0x10($t5)
  beqz  $t6, .L7000DB48
   nop   
  move  $a0, $t6
  lw    $a1, 0x14($t5)
  jal   osSendMesg
   move  $a2, $zero
.L7000DB48:
  lw    $t7, 0x34($sp)
  lui   $at, %hi(retrace)
  lhu   $t8, 2($t7)
  sh    $t8, %lo(retrace)($at)
.L7000DB58:
  lui   $t9, %hi(__osViIntrCount) 
  lw    $t9, %lo(__osViIntrCount)($t9)
  lw    $t1, 0x28($sp)
  lui   $at, %hi(__osViIntrCount)
  addiu $t0, $t9, 1
  beqz  $t1, .L7000DBA0
   sw    $t0, %lo(__osViIntrCount)($at)
  jal   osGetCount
   nop   
  sw    $v0, 0x24($sp)
  lw    $t2, 0x24($sp)
  li    $t4, 0
  lui   $at, %hi(__osCurrentTime)
  sw    $t4, %lo(__osCurrentTime)($at)
  lui   $at, %hi(__osCurrentTime+4)
  move  $t5, $t2
  sw    $t5, %lo(__osCurrentTime+4)($at)
  sw    $zero, 0x28($sp)
.L7000DBA0:
  lui   $t3, %hi(__osBaseCounter) 
  lw    $t3, %lo(__osBaseCounter)($t3)
  jal   osGetCount
   sw    $t3, 0x24($sp)
  lui   $at, %hi(__osBaseCounter)
  sw    $v0, %lo(__osBaseCounter)($at)
  lui   $t6, %hi(__osBaseCounter) 
  lw    $t6, %lo(__osBaseCounter)($t6)
  lw    $t7, 0x24($sp)
  lui   $t3, %hi(__osCurrentTime+4) 
  lw    $t3, %lo(__osCurrentTime+4)($t3)
  subu  $t8, $t6, $t7
  move  $t1, $t8
  lui   $t2, %hi(__osCurrentTime) 
  addu  $t5, $t1, $t3
  lw    $t2, %lo(__osCurrentTime)($t2)
  li    $t0, 0
  sltu  $at, $t5, $t3
  addu  $t4, $at, $t0
  lui   $at, %hi(__osCurrentTime)
  addu  $t4, $t4, $t2
  sw    $t4, %lo(__osCurrentTime)($at)
  lui   $at, %hi(__osCurrentTime+4)
  sw    $t8, 0x24($sp)
  b     .L7000DAC0
   sw    $t5, %lo(__osCurrentTime+4)($at)
.L7000DC08:
  jal   __osTimerInterrupt
   nop   
  b     .L7000DAC0
   nop   
  nop   
  nop   
  nop   
  nop   
  nop   
  nop   
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   
.endif
.ifdef VERSION_EU
glabel viMgrMain
  addiu $sp, $sp, -0x50
  sw    $ra, 0x34($sp)
  sw    $s7, 0x30($sp)
  move  $s7, $a0
  sw    $s6, 0x2c($sp)
  sw    $s5, 0x28($sp)
  sw    $s4, 0x24($sp)
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  jal   __osViGetCurrentContext
   sw    $zero, 0x44($sp)
  lhu   $v1, 2($v0)
  lui   $at, %hi(retrace) # $at, 0x8005
  li    $s6, 14
  bnez  $v1, .L700019AC
   sh    $v1, %lo(retrace)($at)
  li    $v1, 1
  lui   $at, %hi(retrace) # $at, 0x8005
  sh    $v1, %lo(retrace)($at)
.L700019AC:
  lui   $s3, %hi(__osViIntrCount) # $s3, 0x8005
  lui   $s2, %hi(__osBaseCounter) # $s2, 0x8005
  lui   $s1, %hi(__osCurrentTime) # $s1, 0x8005
  addiu $s1, %lo(__osCurrentTime) # addiu $s1, $s1, 0x7c80
  addiu $s2, %lo(__osBaseCounter) # addiu $s2, $s2, 0x7c88
  addiu $s3, %lo(__osViIntrCount) # addiu $s3, $s3, 0x7c8c
  li    $s5, 13
  addiu $s4, $sp, 0x44
.L700019CC:
  lw    $a0, 0xc($s7)
.L700019D0:
  move  $a1, $s4
  jal   osRecvMesg
   li    $a2, 1
  lw    $t6, 0x44($sp)
  lhu   $v1, ($t6)
  beq   $v1, $s5, .L700019FC
   nop   
  beq   $v1, $s6, .L70001A98
   nop   
  b     .L700019D0
   lw    $a0, 0xc($s7)
.L700019FC:
  jal   __osViSwapContext
   nop   
  lui   $v1, %hi(retrace) # $v1, 0x8005
  lhu   $v1, %lo(retrace)($v1)
  lui   $at, %hi(retrace) # $at, 0x8005
  addiu $v1, $v1, -1
  andi  $t7, $v1, 0xffff
  bnez  $t7, .L70001A54
   sh    $t7, %lo(retrace)($at)
  jal   __osViGetCurrentContext
   nop   
  lw    $t8, 0x10($v0)
  move  $s0, $v0
  move  $a2, $zero
  beql  $t8, $zero, .L70001A4C
   lhu   $v1, 2($s0)
  lw    $a0, 0x10($v0)
  jal   osSendMesg
   lw    $a1, 0x14($v0)
  lhu   $v1, 2($s0)
.L70001A4C:
  lui   $at, %hi(retrace) # $at, 0x8005
  sh    $v1, %lo(retrace)($at)
.L70001A54:
  lw    $t9, ($s3)
  lw    $s0, ($s2)
  addiu $t0, $t9, 1
  jal   osGetCount
   sw    $t0, ($s3)
  lw    $t5, 4($s1)
  subu  $s0, $v0, $s0
  lw    $t4, ($s1)
  addu  $t7, $s0, $t5
  li    $t2, 0
  sltu  $at, $t7, $t5
  addu  $t6, $at, $t2
  addu  $t6, $t6, $t4
  sw    $v0, ($s2)
  sw    $t6, ($s1)
  b     .L700019CC
   sw    $t7, 4($s1)
.L70001A98:
  jal   __osTimerInterrupt
   nop   
  b     .L700019D0
   lw    $a0, 0xc($s7)
  nop   
  nop   
  nop   
  nop   
  nop   
  nop   
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
   addiu $sp, $sp, 0x50
.endif

.section .data
glabel __osViDevMgr
.word 0
glabel D_800269A4
.word 0
glabel D_800269A8
.word 0
glabel D_800269AC
.word 0
glabel D_800269B0
.word 0
glabel D_800269B4
.word 0
glabel D_800269B8
.word 0




.section .rodata


.section .bss
glabel viThread
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

glabel viThreadStack
        #[4096]
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
.section .bss
glabel viEventQueue
.word 0, 0, 0, 0, 0, 0

glabel viEventBuf
.word 0, 0, 0, 0, 0, 0

glabel viRetraceMsg
.word 0, 0, 0, 0, 0, 0

glabel viCounterMsg
.word 0, 0, 0, 0, 0, 0

glabel retrace
.half 0

