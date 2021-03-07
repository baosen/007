.section .text  
glabel __CSPPostNextSeqEvent
  addiu $sp, $sp, -0x30
  sw    $ra, 0x14($sp)
  lw    $t6, 0x2c($a0)
  li    $at, 1
  move  $a3, $a0
  bnel  $t6, $at, .L70011024
   lw    $ra, 0x14($sp)
  lw    $a0, 0x18($a0)
  addiu $a1, $sp, 0x1c
  beql  $a0, $zero, .L70011024
   lw    $ra, 0x14($sp)
  jal   __alCSeqNextDelta
   sw    $a3, 0x30($sp)
  beqz  $v0, .L70011020
   lw    $a3, 0x30($sp)
  sh    $zero, 0x20($sp)
  lw    $t7, 0x24($a3)
  lw    $t8, 0x1c($sp)
  addiu $a0, $a3, 0x48
  addiu $a1, $sp, 0x20
  multu $t7, $t8
  mflo  $a2
  jal   alEvtqPostEvent
   nop   
.L70011020:
  lw    $ra, 0x14($sp)
.L70011024:
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   

glabel ultra_70011030
  lw    $v0, 0x18($a0)
  li    $t8, 488
  beql  $v0, $zero, .L7001105C
   sw    $t8, 0x24($a0)
  lwc1  $f4, 8($v0)
  mul.s $f6, $f12, $f4
  trunc.w.s $f8, $f6
  mfc1  $t7, $f8
  jr    $ra
   sw    $t7, 0x24($a0)

  sw    $t8, 0x24($a0)
.L7001105C:
  jr    $ra
   nop   

  jr    $ra
   nop   

glabel ultra_7001106C
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lbu   $t6, 8($a1)
  li    $at, 255
  move  $s0, $zero
  bne   $t6, $at, .L7001122C
   move  $s3, $zero
  lbu   $t7, 9($a1)
  li    $at, 81
  addiu $v0, $a1, 4
  bnel  $t7, $at, .L70011230
   lw    $ra, 0x14($sp)
  lbu   $t6, 8($v0)
  lbu   $t8, 7($v0)
  lw    $fp, 0x24($s7)
  sll   $t7, $t6, 8
  lbu   $t6, 9($v0)
  sll   $t9, $t8, 0x10
  or    $t8, $t9, $t7
  or    $v1, $t8, $t6
  mtc1  $v1, $f4
  move  $a0, $s7
  jal   ultra_70011030
   cvt.s.w $f12, $f4
  lw    $s1, 0x50($s7)
  beqz  $s1, .L70011148
   nop   
  li    $s4, 21
.L700110DC:
  lh    $t7, 0xc($s1)
  lw    $t9, 8($s1)
  lw    $s2, ($s1)
  bne   $s4, $t7, .L70011140
   addu  $s0, $s0, $t9
  jal   alUnlink
   move  $a0, $s1
  beql  $s3, $zero, .L70011118
   sw    $zero, ($s1)
  move  $a0, $s1
  jal   alLink
   move  $a1, $s3
  b     .L70011120
   nop   
  sw    $zero, ($s1)
.L70011118:
  sw    $zero, 4($s1)
  move  $s3, $s1
.L70011120:
  beqz  $s2, .L7001113C
   move  $v1, $s0
  lw    $v0, 8($s1)
  lw    $t8, 8($s2)
  subu  $s0, $s0, $v0
  addu  $t6, $t8, $v0
  sw    $t6, 8($s2)
.L7001113C:
  sw    $v1, 8($s1)
.L70011140:
  bnez  $s2, .L700110DC
   move  $s1, $s2
.L70011148:
  beqz  $s3, .L7001122C
   move  $s1, $s3
  addiu $s4, $s7, 0x48
  addiu $s5, $s4, 8
  li    $s6, -8
.L7001115C:
  lw    $t9, 8($s1)
  lw    $t7, 0x24($s7)
  lw    $s2, ($s1)
  div   $zero, $t9, $fp
  mflo  $v0
  li    $a0, 1
  bnez  $fp, .L70011180
   nop   
  break 7
.L70011180:
  li    $at, -1
  bne   $fp, $at, .L70011198
   lui   $at, 0x8000
  bne   $t9, $at, .L70011198
   nop   
  break 6
.L70011198:
  multu $t7, $v0
  move  $s0, $s5
  mflo  $t8
  sw    $t8, 8($s1)
  jal   osSetIntMask
   nop   
  beq   $s4, $s6, .L7001121C
   move  $s3, $v0
  lw    $a0, ($s0)
.L700111BC:
  bnezl $a0, .L700111DC
   lw    $v0, 8($s1)
  move  $a0, $s1
  jal   alLink
   move  $a1, $s0
  b     .L7001121C
   nop   
  lw    $v0, 8($s1)
.L700111DC:
  lw    $v1, 8($a0)
  move  $a2, $a0
  slt   $at, $v0, $v1
  beqz  $at, .L7001120C
   subu  $t9, $v0, $v1
  subu  $t6, $v1, $v0
  sw    $t6, 8($a0)
  move  $a0, $s1
  jal   alLink
   move  $a1, $s0
  b     .L7001121C
   nop   
.L7001120C:
  sw    $t9, 8($s1)
  lw    $s0, ($s0)
  bnezl $s0, .L700111BC
   lw    $a0, ($s0)
.L7001121C:
  jal   osSetIntMask
   move  $a0, $s3
  bnez  $s2, .L7001115C
   move  $s1, $s2
.L7001122C:
  lw    $ra, 0x14($sp)
.L70011230:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   

glabel __CSPHandleMIDIMsg
  addiu $sp, $sp, -0xb8
  sw    $ra, 0x24($sp)
  lbu   $s6, 8($t0)
  lbu   $s4, 9($t0)
  lbu   $s1, 0xa($t0)
  andi  $v1, $s6, 0xf0
  addiu $t7, $v1, -0x80
  sltiu $at, $t7, 0x61
  andi  $t6, $s6, 0xf
  beqz  $at, .L70011A54
   move  $s6, $t6
  sll   $t7, $t7, 2
  lui   $at, %hi(audio_related_jump_table_0) # 0x8003
  addu  $at, $at, $t7
  lw    $t7, %lo(audio_related_jump_table_0)($at) # -0x6b70
  jr    $t7
   nop   
.L70011280:
  beql  $s1, $zero, .L70011624
   move  $a0, $s2
  lw    $t8, 0x2c($s2)
  li    $at, 1
  move  $a0, $s2
  bne   $t8, $at, .L70011A54
   andi  $a1, $s4, 0xff
  andi  $a2, $s1, 0xff
  andi  $a3, $s6, 0xff
  jal   __lookupSoundQuick
   sw    $t0, 0xbc($sp)
  beqz  $v0, .L70011A54
   move  $s7, $v0
  lw    $t9, 0x60($s2)
  sll   $fp, $s6, 4
  move  $a0, $s2
  addu  $t6, $t9, $fp
  lbu   $t7, 8($t6)
  sh    $zero, 0x76($sp)
  sb    $zero, 0x78($sp)
  andi  $a1, $s4, 0xff
  andi  $a2, $s1, 0xff
  andi  $a3, $s6, 0xff
  jal   __mapVoice
   sh    $t7, 0x74($sp)
  beqz  $v0, .L70011A54
   move  $s0, $v0
  lw    $a0, 0x14($s2)
  addiu $a1, $v0, 4
  sw    $a1, 0x38($sp)
  jal   alSynAllocVoice
   addiu $a2, $sp, 0x74
  sw    $s7, 0x20($s0)
  sb    $zero, 0x34($s0)
  lw    $t8, 0x60($s2)
  li    $s5, 2
  addu  $t9, $t8, $fp
  lbu   $t6, 0xb($t9)
  slti  $at, $t6, 0x40
  bnezl $at, .L70011330
   sb    $zero, 0x35($s0)
  b     .L70011330
   sb    $s5, 0x35($s0)
  sb    $zero, 0x35($s0)
.L70011330:
  lw    $v0, 4($s7)
  lbu   $t7, 4($v0)
  lb    $t6, 5($v0)
  subu  $t8, $s4, $t7
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
  lw    $t7, 0x1c($s2)
  lw    $t9, ($t8)
  sb    $zero, 0x37($s0)
  addu  $t6, $t7, $t9
  sw    $t6, 0x24($s0)
  lw    $t8, 0x60($s2)
  addu  $t7, $t8, $fp
  lw    $s1, ($t7)
  swc1  $f4, 0x64($sp)
  lbu   $a2, 4($s1)
  beql  $a2, $zero, .L70011414
   cfc1  $t8, $31
  lw    $v0, 0x70($s2)
  beql  $v0, $zero, .L70011414
   cfc1  $t8, $31
  lbu   $t9, 6($s1)
  lbu   $a3, 5($s1)
  addiu $a0, $sp, 0x5c
  sw    $t9, 0x10($sp)
  lbu   $t6, 7($s1)
  addiu $a1, $sp, 0x64
  jalr  $v0
  sw    $t6, 0x14($sp)
  beqz  $v0, .L70011410
   li    $t8, 22
  lw    $t7, 0x5c($sp)
  sh    $t8, 0x8c($sp)
  sw    $s0, 0x90($sp)
  addiu $a0, $s2, 0x48
  addiu $a1, $sp, 0x8c
  move  $a2, $v0
  jal   alEvtqPostEvent
   sw    $t7, 0x94($sp)
  lbu   $t9, 0x37($s0)
  ori   $t6, $t9, 1
  sb    $t6, 0x37($s0)
.L70011410:
  cfc1  $t8, $31
.L70011414:
  li    $t7, 1
  ctc1  $t7, $31
  lwc1  $f6, 0x64($sp)
  li    $at, 0x4F000000 # 2147483648.000000
  cvt.w.s $f8, $f6
  cfc1  $t7, $31
  nop   
  andi  $t7, $t7, 0x78
  beql  $t7, $zero, .L70011484
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
  bnez  $t7, .L70011478
   nop   
  mfc1  $t7, $f8
  lui   $at, 0x8000
  b     .L70011490
   or    $t7, $t7, $at
.L70011478:
  b     .L70011490
   li    $t7, -1
  mfc1  $t7, $f8
.L70011484:
  nop   
  bltz  $t7, .L70011478
   nop   
.L70011490:
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  sb    $t7, 0x36($s0)
  ctc1  $t8, $31
  swc1  $f10, 0x64($sp)
  lbu   $a2, 8($s1)
  addiu $s5, $s2, 0x48
  beql  $a2, $zero, .L7001151C
   lwc1  $f4, 0x64($sp)
  lw    $v0, 0x70($s2)
  beql  $v0, $zero, .L7001151C
   lwc1  $f4, 0x64($sp)
  lbu   $t9, 0xa($s1)
  lbu   $a3, 9($s1)
  addiu $a0, $sp, 0x5c
  sw    $t9, 0x10($sp)
  lbu   $t6, 0xb($s1)
  addiu $a1, $sp, 0x64
  jalr  $v0
  sw    $t6, 0x14($sp)
  beqz  $v0, .L70011518
   li    $t8, 23
  lw    $t7, 0x5c($sp)
  sh    $t8, 0x8c($sp)
  sw    $s0, 0x90($sp)
  sb    $s6, 0x98($sp)
  move  $a0, $s5
  addiu $a1, $sp, 0x8c
  move  $a2, $v0
  jal   alEvtqPostEvent
   sw    $t7, 0x94($sp)
  lbu   $t9, 0x37($s0)
  ori   $t6, $t9, 2
  sb    $t6, 0x37($s0)
.L70011518:
  lwc1  $f4, 0x64($sp)
.L7001151C:
  lwc1  $f8, 0x28($s0)
  move  $a0, $s0
  swc1  $f4, 0x2c($s0)
  lw    $t8, 0x60($s2)
  lwc1  $f4, 0x2c($s0)
  move  $a1, $s2
  addu  $v0, $t8, $fp
  lwc1  $f6, 0xc($v0)
  lbu   $s1, 0xa($v0)
  mul.s $f10, $f6, $f8
  nop   
  mul.s $f20, $f10, $f4
  jal   __vsPan
   nop   
  andi  $fp, $v0, 0xff
  move  $a0, $s0
  jal   __vsVol
   move  $a1, $s2
  lw    $t7, ($s7)
  lw    $a0, 0x14($s2)
  lw    $a2, 8($s7)
  lw    $s3, ($t7)
  mfc1  $a3, $f20
  sw    $s1, 0x18($sp)
  sw    $fp, 0x14($sp)
  sw    $v0, 0x10($sp)
  lw    $a1, 0x38($sp)
  jal   alSynStartVoiceParams
   sw    $s3, 0x1c($sp)
  lw    $t6, 0x38($sp)
  li    $t9, 6
  sh    $t9, 0x8c($sp)
  sw    $t6, 0x90($sp)
  lw    $t8, ($s7)
  move  $a0, $s5
  addiu $a1, $sp, 0x8c
  lbu   $t7, 0xd($t8)
  move  $a2, $s3
  sb    $t7, 0x98($sp)
  lw    $t9, ($s7)
  lw    $t6, 4($t9)
  jal   alEvtqPostEvent
   sw    $t6, 0x94($sp)
  lw    $v0, 0xbc($sp)
  li    $t7, 21
  ori   $t9, $s6, 0x80
  lw    $t8, 0xc($v0)
  addiu $v0, $v0, 4
  beql  $t8, $zero, .L70011A58
   lw    $ra, 0x24($sp)
  sh    $t7, 0x8c($sp)
  sb    $t9, 0x94($sp)
  sb    $s4, 0x95($sp)
  sb    $zero, 0x96($sp)
  lw    $t8, 8($v0)
  lw    $t6, 0x24($s2)
  move  $a0, $s5
  addiu $a1, $sp, 0x8c
  multu $t6, $t8
  mflo  $s3
  move  $a2, $s3
  jal   alEvtqPostEvent
   nop   
  b     .L70011A58
   lw    $ra, 0x24($sp)
.L70011620:
  move  $a0, $s2
.L70011624:
  andi  $a1, $s4, 0xff
  jal   __lookupVoice
   andi  $a2, $s6, 0xff
  beqz  $v0, .L70011A54
   move  $s0, $v0
  lbu   $t7, 0x35($v0)
  li    $s6, 2
  li    $t9, 4
  bne   $s6, $t7, .L70011654
   move  $a0, $s2
  b     .L70011A54
   sb    $t9, 0x35($v0)
.L70011654:
  lw    $t6, 0x20($s0)
  li    $fp, 3
  sb    $fp, 0x35($s0)
  lw    $t8, ($t6)
  addiu $a1, $s0, 4
  jal   __seqpReleaseVoice
   lw    $a2, 8($t8)
  b     .L70011A58
   lw    $ra, 0x24($sp)
.L70011678:
  move  $a0, $s2
  andi  $a1, $s4, 0xff
  jal   __lookupVoice
   andi  $a2, $s6, 0xff
  beqz  $v0, .L70011A54
   move  $s0, $v0
  sb    $s1, 0x33($v0)
  move  $a0, $v0
  jal   __vsVol
   move  $a1, $s2
  sll   $s1, $v0, 0x10
  sra   $t7, $s1, 0x10
  move  $s1, $t7
  move  $a0, $s0
  jal   __vsDelta
   lw    $a1, 0x1c($s2)
  sll   $a2, $s1, 0x10
  sra   $t9, $a2, 0x10
  move  $a2, $t9
  lw    $a0, 0x14($s2)
  addiu $a1, $s0, 4
  jal   alSynSetVol
   move  $a3, $v0
  b     .L70011A58
   lw    $ra, 0x24($sp)
.L700116DC:
  lw    $s0, 0x64($s2)
  beql  $s0, $zero, .L70011A58
   lw    $ra, 0x24($sp)
  move  $s3, $s6
  lbu   $t6, 0x31($s0)
.L700116F0:
  move  $a0, $s0
  move  $a1, $s2
  bnel  $s3, $t6, .L70011740
   lw    $s0, ($s0)
  jal   __vsVol
   sb    $s4, 0x33($s0)
  sll   $s1, $v0, 0x10
  sra   $t8, $s1, 0x10
  move  $s1, $t8
  move  $a0, $s0
  jal   __vsDelta
   lw    $a1, 0x1c($s2)
  sll   $a2, $s1, 0x10
  sra   $t7, $a2, 0x10
  move  $a2, $t7
  lw    $a0, 0x14($s2)
  addiu $a1, $s0, 4
  jal   alSynSetVol
   move  $a3, $v0
  lw    $s0, ($s0)
.L70011740:
  bnezl $s0, .L700116F0
   lbu   $t6, 0x31($s0)
  b     .L70011A58
   lw    $ra, 0x24($sp)
.L70011750:
  li    $at, 7
  beq   $s4, $at, .L700117E4
   move  $v0, $s4
  li    $at, 10
  beq   $v0, $at, .L70011788
   li    $at, 16
  beq   $v0, $at, .L70011874
   li    $at, 64
  beq   $v0, $at, .L70011888
   li    $at, 91
  beql  $v0, $at, .L7001193C
   lw    $t9, 0x60($s2)
  b     .L70011A58
   lw    $ra, 0x24($sp)
.L70011788:
  lw    $t9, 0x60($s2)
  sll   $t6, $s6, 4
  addu  $t8, $t9, $t6
  sb    $s1, 7($t8)
  lw    $s0, 0x64($s2)
  beql  $s0, $zero, .L70011A58
   lw    $ra, 0x24($sp)
  move  $s3, $s6
  lbu   $t7, 0x31($s0)
.L700117AC:
  move  $a0, $s0
  bnel  $s3, $t7, .L700117D4
   lw    $s0, ($s0)
  jal   __vsPan
   move  $a1, $s2
  lw    $a0, 0x14($s2)
  addiu $a1, $s0, 4
  jal   alSynSetPan
   andi  $a2, $v0, 0xff
  lw    $s0, ($s0)
.L700117D4:
  bnezl $s0, .L700117AC
   lbu   $t7, 0x31($s0)
  b     .L70011A58
   lw    $ra, 0x24($sp)
.L700117E4:
  lw    $t9, 0x60($s2)
  sll   $t6, $s6, 4
  addu  $t8, $t9, $t6
  sb    $s1, 9($t8)
  lw    $s0, 0x64($s2)
  beql  $s0, $zero, .L70011A58
   lw    $ra, 0x24($sp)
  move  $s3, $s6
  li    $s4, 3
  lbu   $t7, 0x31($s0)
.L7001180C:
  bnel  $s3, $t7, .L70011864
   lw    $s0, ($s0)
  lbu   $t9, 0x34($s0)
  move  $a0, $s0
  beql  $s4, $t9, .L70011864
   lw    $s0, ($s0)
  jal   __vsVol
   move  $a1, $s2
  sll   $s1, $v0, 0x10
  sra   $t6, $s1, 0x10
  move  $s1, $t6
  move  $a0, $s0
  jal   __vsDelta
   lw    $a1, 0x1c($s2)
  sll   $a2, $s1, 0x10
  sra   $t8, $a2, 0x10
  move  $a2, $t8
  lw    $a0, 0x14($s2)
  addiu $a1, $s0, 4
  jal   alSynSetVol
   move  $a3, $v0
  lw    $s0, ($s0)
.L70011864:
  bnezl $s0, .L7001180C
   lbu   $t7, 0x31($s0)
  b     .L70011A58
   lw    $ra, 0x24($sp)
.L70011874:
  lw    $t7, 0x60($s2)
  sll   $t9, $s6, 4
  addu  $t6, $t7, $t9
  b     .L70011A54
   sb    $s1, 8($t6)
.L70011888:
  lw    $t8, 0x60($s2)
  sll   $t7, $s6, 4
  addu  $t9, $t8, $t7
  sb    $s1, 0xb($t9)
  lw    $s0, 0x64($s2)
  beql  $s0, $zero, .L70011A58
   lw    $ra, 0x24($sp)
  move  $s3, $s6
  li    $s6, 2
  li    $fp, 3
  li    $s7, 4
  li    $s5, 2
  li    $s4, 3
  lbu   $t6, 0x31($s0)
.L700118C0:
  bnel  $s3, $t6, .L70011928
   lw    $s0, ($s0)
  lbu   $v0, 0x35($s0)
  slti  $at, $s1, 0x40
  beql  $s4, $v0, .L70011928
   lw    $s0, ($s0)
  bnez  $at, .L700118F0
   nop   
  bnezl $v0, .L70011928
   lw    $s0, ($s0)
  b     .L70011924
   sb    $s5, 0x35($s0)
.L700118F0:
  bne   $s6, $v0, .L70011900
   nop   
  b     .L70011924
   sb    $zero, 0x35($s0)
.L70011900:
  bnel  $s7, $v0, .L70011928
   lw    $s0, ($s0)
  lw    $t8, 0x20($s0)
  sb    $fp, 0x35($s0)
  move  $a0, $s2
  lw    $t7, ($t8)
  addiu $a1, $s0, 4
  jal   __seqpReleaseVoice
   lw    $a2, 8($t7)
.L70011924:
  lw    $s0, ($s0)
.L70011928:
  bnezl $s0, .L700118C0
   lbu   $t6, 0x31($s0)
  b     .L70011A58
   lw    $ra, 0x24($sp)
  lw    $t9, 0x60($s2)
.L7001193C:
  sll   $t6, $s6, 4
  addu  $t8, $t9, $t6
  sb    $s1, 0xa($t8)
  lw    $s0, 0x64($s2)
  beql  $s0, $zero, .L70011A58
   lw    $ra, 0x24($sp)
  move  $s3, $s6
  lbu   $t7, 0x31($s0)
.L7001195C:
  addiu $a1, $s0, 4
  andi  $a2, $s1, 0xff
  bnel  $s3, $t7, .L70011978
   lw    $s0, ($s0)
  jal   alSynSetFXMix
   lw    $a0, 0x14($s2)
  lw    $s0, ($s0)
.L70011978:
  bnezl $s0, .L7001195C
   lbu   $t7, 0x31($s0)
  b     .L70011A58
   lw    $ra, 0x24($sp)
.L70011988:
  lw    $v0, 0x20($s2)
  sll   $t6, $s4, 2
  move  $a0, $s2
  lh    $t9, ($v0)
  move  $a2, $s6
  addu  $t8, $v0, $t6
  slt   $at, $s4, $t9
  beql  $at, $zero, .L70011A58
   lw    $ra, 0x24($sp)
  jal   __setInstChanState
   lw    $a1, 0xc($t8)
  b     .L70011A58
   lw    $ra, 0x24($sp)
.L700119BC:
  lw    $t7, 0x60($s2)
  sll   $fp, $s6, 4
  sll   $t8, $s1, 7
  addu  $t9, $t7, $fp
  lh    $t6, 4($t9)
  addu  $t7, $t8, $s4
  addiu $t9, $t7, -0x2000
  multu $t6, $t9
  mflo  $a0
  bgez  $a0, .L700119F0
   sra   $t8, $a0, 0xd
  addiu $at, $a0, 0x1fff
  sra   $t8, $at, 0xd
.L700119F0:
  jal   alCents2Ratio
   move  $a0, $t8
  lw    $t7, 0x60($s2)
  mov.s $f20, $f0
  addu  $t6, $t7, $fp
  swc1  $f0, 0xc($t6)
  lw    $s0, 0x64($s2)
  beql  $s0, $zero, .L70011A58
   lw    $ra, 0x24($sp)
  move  $s3, $s6
  lbu   $t9, 0x31($s0)
.L70011A1C:
  bnel  $s3, $t9, .L70011A4C
   lw    $s0, ($s0)
  lwc1  $f6, 0x28($s0)
  lwc1  $f10, 0x2c($s0)
  lw    $a0, 0x14($s2)
  mul.s $f8, $f6, $f20
  addiu $a1, $s0, 4
  mul.s $f4, $f8, $f10
  mfc1  $a2, $f4
  jal   alSynSetPitch
   nop   
  lw    $s0, ($s0)
.L70011A4C:
  bnezl $s0, .L70011A1C
   lbu   $t9, 0x31($s0)
.L70011A54:
  lw    $ra, 0x24($sp)
.L70011A58:
  addiu $sp, $sp, 0xb8
  jr    $ra
   nop   

  jr    $ra
   nop   

glabel ultra_70011A6C
  addiu $sp, $sp, -0xa0
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
.L70011AAC:
  lhu   $t7, 0x38($s2)
  sltiu $at, $t7, 0x18
  beqz  $at, .L7001202C
   sll   $t7, $t7, 2
  lui   $at, %hi(audio_related_jump_table_1) # 0x8003
  addu  $at, $at, $t7
  lw    $t7, %lo(audio_related_jump_table_1)($at) # -0x69ec
  jr    $t7
   nop   
.L70011AD0:
  lw    $a0, 0x18($s2)
  beql  $a0, $zero, .L70012030
   move  $a0, $s5
  jal   alCSeqNextEvent
   addiu $a1, $sp, 0x58
  lh    $t8, 0x58($sp)
  addiu $t9, $t8, -1
  sltiu $at, $t9, 0x14
  beqz  $at, .L7001202C
   sll   $t9, $t9, 2
  lui   $at, %hi(audio_related_jump_table_2) # 0x8003
  addu  $at, $at, $t9
  lw    $t9, %lo(audio_related_jump_table_2)($at) # -0x698c
  jr    $t9
   nop   
.L70011B0C:
  addiu $t0, $sp, 0x58
  sw    $s2, 0xa0($sp)
  jal   __CSPHandleMIDIMsg
   sw    $s5, 0x4c($sp)
  lw    $s2, 0xa0($sp)
  lw    $s5, 0x4c($sp)
  jal   __CSPPostNextSeqEvent
   move  $a0, $s2
  b     .L70012030
   move  $a0, $s5
.L70011B34:
  move  $s7, $s2
  addiu $a1, $sp, 0x58
  sw    $s2, 0xa0($sp)
  jal   ultra_7001106C
   sw    $s5, 0x4c($sp)
  lw    $s2, 0xa0($sp)
  lw    $s5, 0x4c($sp)
  jal   __CSPPostNextSeqEvent
   move  $a0, $s2
  b     .L70012030
   move  $a0, $s5
.L70011B60:
  li    $t6, 2
  sw    $t6, 0x2c($s2)
  li    $t7, 16
  lui   $a2, (0x7FFFFFFF >> 16) # lui $a2, 0x7fff
  sh    $t7, 0x58($sp)
  ori   $a2, (0x7FFFFFFF & 0xFFFF) # ori $a2, $a2, 0xffff
  move  $a0, $s5
  jal   alEvtqPostEvent
   addiu $a1, $sp, 0x58
  b     .L70012030
   move  $a0, $s5
.L70011B8C:
  jal   __CSPPostNextSeqEvent
   move  $a0, $s2
  b     .L70012030
   move  $a0, $s5
.L70011B9C:
  li    $t8, 9
  sh    $t8, 0x8c($sp)
  lw    $a2, 0x5c($s2)
  move  $a0, $s5
  jal   alEvtqPostEvent
   addiu $a1, $sp, 0x8c
  b     .L70012030
   move  $a0, $s5
.L70011BBC:
  lw    $s0, 0x3c($s2)
  lw    $a0, 0x14($s2)
  jal   alSynStopVoice
   move  $a1, $s0
  lw    $a0, 0x14($s2)
  jal   alSynFreeVoice
   move  $a1, $s0
  lw    $s1, 0x10($s0)
  move  $a0, $s2
  lbu   $t9, 0x37($s1)
  beql  $t9, $zero, .L70011BF8
   move  $a0, $s2
  jal   __seqpStopOsc
   move  $a1, $s1
  move  $a0, $s2
.L70011BF8:
  jal   __unmapVoice
   move  $a1, $s0
  b     .L70012030
   move  $a0, $s5
.L70011C08:
  lw    $s0, 0x3c($s2)
  li    $t7, 1
  lw    $s1, 0x10($s0)
  lbu   $t6, 0x34($s1)
  bnezl $t6, .L70011C28
   lw    $s3, 0x40($s2)
  sb    $t7, 0x34($s1)
  lw    $s3, 0x40($s2)
.L70011C28:
  lw    $t8, 0x1c($s2)
  move  $a0, $s1
  move  $a1, $s2
  addu  $t9, $t8, $s3
  sw    $t9, 0x24($s1)
  lbu   $t6, 0x44($s2)
  jal   __vsVol
   sb    $t6, 0x30($s1)
  sll   $a2, $v0, 0x10
  sra   $t7, $a2, 0x10
  move  $a2, $t7
  lw    $a0, 0x14($s2)
  move  $a1, $s0
  jal   alSynSetVol
   move  $a3, $s3
  b     .L70012030
   move  $a0, $s5
.L70011C6C:
  lw    $t9, 0x74($s2)
  lw    $s4, 0x40($s2)
  lw    $s1, 0x3c($s2)
  addiu $a1, $sp, 0x78
  jalr  $t9
  move  $a0, $s4
  cfc1  $t8, $31
  li    $t6, 1
  ctc1  $t6, $31
  lwc1  $f4, 0x78($sp)
  move  $s3, $v0
  li    $at, 0x4F000000 # 2147483648.000000
  cvt.w.s $f6, $f4
  move  $a0, $s1
  move  $a1, $s2
  cfc1  $t6, $31
  nop   
  andi  $t6, $t6, 0x78
  beql  $t6, $zero, .L70011D04
   mfc1  $t6, $f6
  mtc1  $at, $f6
  li    $t6, 1
  sub.s $f6, $f4, $f6
  ctc1  $t6, $31
  nop   
  cvt.w.s $f6, $f6
  cfc1  $t6, $31
  nop   
  andi  $t6, $t6, 0x78
  bnez  $t6, .L70011CF8
   nop   
  mfc1  $t6, $f6
  lui   $at, 0x8000
  b     .L70011D10
   or    $t6, $t6, $at
.L70011CF8:
  b     .L70011D10
   li    $t6, -1
  mfc1  $t6, $f6
.L70011D04:
  nop   
  bltz  $t6, .L70011CF8
   nop   
.L70011D10:
  ctc1  $t8, $31
  jal   __vsVol
   sb    $t6, 0x36($s1)
  sll   $s0, $v0, 0x10
  sra   $t7, $s0, 0x10
  move  $s0, $t7
  move  $a0, $s1
  jal   __vsDelta
   lw    $a1, 0x1c($s2)
  sll   $a2, $s0, 0x10
  sra   $t9, $a2, 0x10
  move  $a2, $t9
  lw    $a0, 0x14($s2)
  addiu $a1, $s1, 4
  jal   alSynSetVol
   move  $a3, $v0
  li    $t8, 22
  sh    $t8, 0x8c($sp)
  sw    $s1, 0x90($sp)
  sw    $s4, 0x94($sp)
  move  $a0, $s5
  addiu $a1, $sp, 0x8c
  jal   alEvtqPostEvent
   move  $a2, $s3
  b     .L70012030
   move  $a0, $s5
.L70011D78:
  lw    $t9, 0x74($s2)
  lw    $s4, 0x40($s2)
  lw    $s1, 0x3c($s2)
  lbu   $s0, 0x44($s2)
  addiu $a1, $sp, 0x78
  jalr  $t9
  move  $a0, $s4
  lwc1  $f8, 0x78($sp)
  lwc1  $f4, 0x28($s1)
  sll   $t7, $s0, 4
  swc1  $f8, 0x2c($s1)
  lwc1  $f6, 0x2c($s1)
  lw    $t6, 0x60($s2)
  move  $s3, $v0
  mul.s $f8, $f4, $f6
  addu  $t8, $t6, $t7
  lwc1  $f10, 0xc($t8)
  lw    $a0, 0x14($s2)
  addiu $a1, $s1, 4
  mul.s $f4, $f10, $f8
  mfc1  $a2, $f4
  jal   alSynSetPitch
   nop   
  li    $t9, 23
  sh    $t9, 0x8c($sp)
  sw    $s1, 0x90($sp)
  sw    $s4, 0x94($sp)
  sb    $s0, 0x98($sp)
  move  $a0, $s5
  addiu $a1, $sp, 0x8c
  jal   alEvtqPostEvent
   move  $a2, $s3
  b     .L70012030
   move  $a0, $s5
.L70011E00:
  lw    $t0, 0x50($sp)
  sw    $s2, 0xa0($sp)
  jal   __CSPHandleMIDIMsg
   sw    $s5, 0x4c($sp)
  lw    $s2, 0xa0($sp)
  b     .L7001202C
   lw    $s5, 0x4c($sp)
.L70011E1C:
  move  $s7, $s2
  lw    $a1, 0x50($sp)
  sw    $s2, 0xa0($sp)
  jal   ultra_7001106C
   sw    $s5, 0x4c($sp)
  lw    $s2, 0xa0($sp)
  b     .L7001202C
   lw    $s5, 0x4c($sp)
.L70011E3C:
  lw    $s1, 0x64($s2)
  lh    $t6, 0x3c($s2)
  beqz  $s1, .L7001202C
   sh    $t6, 0x32($s2)
  move  $a0, $s1
.L70011E50:
  jal   __vsVol
   move  $a1, $s2
  sll   $s0, $v0, 0x10
  sra   $t7, $s0, 0x10
  move  $s0, $t7
  move  $a0, $s1
  jal   __vsDelta
   lw    $a1, 0x1c($s2)
  sll   $a2, $s0, 0x10
  sra   $t8, $a2, 0x10
  move  $a2, $t8
  lw    $a0, 0x14($s2)
  addiu $a1, $s1, 4
  jal   alSynSetVol
   move  $a3, $v0
  lw    $s1, ($s1)
  bnezl $s1, .L70011E50
   move  $a0, $s1
  b     .L70012030
   move  $a0, $s5
.L70011EA0:
  lw    $t9, 0x2c($s2)
  li    $at, 1
  li    $t6, 1
  beq   $t9, $at, .L7001202C
   move  $a0, $s2
  jal   __CSPPostNextSeqEvent
   sw    $t6, 0x2c($s2)
  b     .L70012030
   move  $a0, $s5
.L70011EC4:
  lw    $t7, 0x2c($s2)
  li    $at, 2
  bnel  $t7, $at, .L70012030
   move  $a0, $s5
  lw    $s1, 0x64($s2)
  beqz  $s1, .L70011F28
   addiu $s0, $s1, 4
.L70011EE0:
  move  $a1, $s0
  jal   alSynStopVoice
   lw    $a0, 0x14($s2)
  lw    $a0, 0x14($s2)
  jal   alSynFreeVoice
   move  $a1, $s0
  lbu   $t8, 0x37($s1)
  move  $a0, $s2
  beql  $t8, $zero, .L70011F14
   move  $a0, $s2
  jal   __seqpStopOsc
   move  $a1, $s1
  move  $a0, $s2
.L70011F14:
  jal   __unmapVoice
   move  $a1, $s0
  lw    $s1, 0x64($s2)
  bnezl $s1, .L70011EE0
   addiu $s0, $s1, 4
.L70011F28:
  b     .L7001202C
   sw    $zero, 0x2c($s2)
.L70011F30:
  lw    $t9, 0x2c($s2)
  li    $at, 1
  move  $a0, $s5
  bnel  $t9, $at, .L70012030
   move  $a0, $s5
  jal   alEvtqFlushType
   move  $a1, $zero
  move  $a0, $s5
  jal   alEvtqFlushType
   li    $a1, 21
  move  $a0, $s5
  jal   alEvtqFlushType
   li    $a1, 2
  lw    $s1, 0x64($s2)
  beqz  $s1, .L70011FA0
   addiu $s0, $s1, 4
.L70011F70:
  move  $a1, $s0
  move  $a0, $s2
  jal   __voiceNeedsNoteKill
   li    $a2, 50000
  beqz  $v0, .L70011F94
   move  $a0, $s2
  move  $a1, $s0
  jal   __seqpReleaseVoice
   li    $a2, 50000
.L70011F94:
  lw    $s1, ($s1)
  bnezl $s1, .L70011F70
   addiu $s0, $s1, 4
.L70011FA0:
  li    $t6, 2
  sw    $t6, 0x2c($s2)
  li    $t7, 16
  lui   $a2, (0x7FFFFFFF >> 16) # lui $a2, 0x7fff
  sh    $t7, 0x8c($sp)
  ori   $a2, (0x7FFFFFFF & 0xFFFF) # ori $a2, $a2, 0xffff
  move  $a0, $s5
  jal   alEvtqPostEvent
   addiu $a1, $sp, 0x8c
  b     .L70012030
   move  $a0, $s5
.L70011FCC:
  lbu   $s0, 0x3c($s2)
  lw    $t9, 0x60($s2)
  lbu   $t8, 0x3d($s2)
  sll   $t6, $s0, 4
  addu  $t7, $t9, $t6
  b     .L7001202C
   sb    $t8, 8($t7)
.L70011FE8:
  lw    $t9, 0x3c($s2)
  lui   $at, %hi(F32_800296C4)
  move  $a0, $s2
  sw    $t9, 0x18($s2)
  jal   ultra_70011030
   lwc1  $f12, %lo(F32_800296C4)($at)
  lw    $a1, 0x20($s2)
  beql  $a1, $zero, .L70012030
   move  $a0, $s5
  jal   __initFromBank
   move  $a0, $s2
  b     .L70012030
   move  $a0, $s5
.L7001201C:
  lw    $a1, 0x3c($s2)
  move  $a0, $s2
  jal   __initFromBank
   sw    $a1, 0x20($s2)
.L7001202C:
  move  $a0, $s5
.L70012030:
  jal   alEvtqNextEvent
   lw    $a1, 0x50($sp)
  beqz  $v0, .L70011AAC
   sw    $v0, 0x28($s2)
  lw    $t6, 0x1c($s2)
  addu  $t8, $t6, $v0
  sw    $t8, 0x1c($s2)
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
   addiu $sp, $sp, 0xa0

glabel alCSPNew
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
  li    $t0, 16000
  sh    $t7, 0x30($a0)
  sw    $t8, 0x24($a0)
  sw    $zero, 0x28($a0)
  sw    $zero, 0x2c($a0)
  sh    $t9, 0x32($a0)
  sw    $t0, 0x5c($a0)
  sw    $zero, 0x1c($a0)
  sw    $t6, 0x14($a0)
  lw    $t1, 0x10($a1)
  li    $t4, 9
  move  $s1, $a1
  sw    $t1, 0x70($a0)
  lw    $t2, 0x14($a1)
  move  $s0, $a0
  li    $t6, 16
  sw    $t2, 0x74($a0)
  lw    $t3, 0x18($a1)
  sh    $t4, 0x38($a0)
  sw    $t3, 0x78($a0)
  lbu   $t5, 8($a1)
  move  $a1, $zero
  sb    $t5, 0x34($a0)
  lbu   $a3, 8($s1)
  sw    $t6, 0x10($sp)
  move  $a0, $zero
  jal   alHeapDBAlloc
   sw    $a2, 0x2c($sp)
  sw    $v0, 0x60($s0)
  jal   __initChanState
   move  $a0, $s0
  lw    $a3, ($s1)
  li    $t7, 56
  sw    $t7, 0x10($sp)
  move  $a0, $zero
  move  $a1, $zero
  jal   alHeapDBAlloc
   lw    $a2, 0x2c($sp)
  sw    $zero, 0x6c($s0)
  lw    $t8, ($s1)
  move  $a0, $zero
  move  $a1, $zero
  blez  $t8, .L70012188
   li    $t1, 28
  move  $v1, $v0
  lw    $t9, 0x6c($s0)
.L70012168:
  addiu $a0, $a0, 1
  sw    $t9, ($v1)
  sw    $v1, 0x6c($s0)
  lw    $t0, ($s1)
  addiu $v1, $v1, 0x38
  slt   $at, $a0, $t0
  bnezl $at, .L70012168
   lw    $t9, 0x6c($s0)
.L70012188:
  sw    $zero, 0x64($s0)
  sw    $zero, 0x68($s0)
  lw    $a3, 4($s1)
  sw    $t1, 0x10($sp)
  lw    $a2, 0x2c($sp)
  jal   alHeapDBAlloc
   move  $a0, $zero
  addiu $a0, $s0, 0x48
  move  $a1, $v0
  jal   alEvtqNew
   lw    $a2, 4($s1)
  lui   $t2, %hi(ultra_70011A6C) # $t2, 0x7001
  addiu $t2, %lo(ultra_70011A6C) # addiu $t2, $t2, 0x1a6c
  sw    $zero, ($s0)
  sw    $t2, 8($s0)
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

 

.section .rodata
glabel audio_related_jump_table_0
.word .L70011620, .L70011A54, .L70011A54, .L70011A54
.word .L70011A54, .L70011A54, .L70011A54, .L70011A54
.word .L70011A54, .L70011A54, .L70011A54, .L70011A54
.word .L70011A54, .L70011A54, .L70011A54, .L70011A54
.word .L70011280, .L70011A54, .L70011A54, .L70011A54
.word .L70011A54, .L70011A54, .L70011A54, .L70011A54
.word .L70011A54, .L70011A54, .L70011A54, .L70011A54
.word .L70011A54, .L70011A54, .L70011A54, .L70011A54
.word .L70011678, .L70011A54, .L70011A54, .L70011A54
.word .L70011A54, .L70011A54, .L70011A54, .L70011A54
.word .L70011A54, .L70011A54, .L70011A54, .L70011A54
.word .L70011A54, .L70011A54, .L70011A54, .L70011A54
.word .L70011750, .L70011A54, .L70011A54, .L70011A54
.word .L70011A54, .L70011A54, .L70011A54, .L70011A54
.word .L70011A54, .L70011A54, .L70011A54, .L70011A54
.word .L70011A54, .L70011A54, .L70011A54, .L70011A54
.word .L70011988, .L70011A54, .L70011A54, .L70011A54
.word .L70011A54, .L70011A54, .L70011A54, .L70011A54
.word .L70011A54, .L70011A54, .L70011A54, .L70011A54
.word .L70011A54, .L70011A54, .L70011A54, .L70011A54
.word .L700116DC, .L70011A54, .L70011A54, .L70011A54
.word .L70011A54, .L70011A54, .L70011A54, .L70011A54
.word .L70011A54, .L70011A54, .L70011A54, .L70011A54
.word .L70011A54, .L70011A54, .L70011A54, .L70011A54
.word .L700119BC
glabel audio_related_jump_table_1
.word .L70011AD0
.word .L7001202C
.word .L70011E00
.word .L7001202C
.word .L7001202C
.word .L70011BBC
.word .L70011C08
.word .L70011E1C
.word .L7001202C
.word .L70011B9C
.word .L70011E3C
.word .L7001202C
.word .L70011FCC
.word .L70011FE8
.word .L7001201C
.word .L70011EA0
.word .L70011EC4
.word .L70011F30
.word .L7001202C
.word .L7001202C
.word .L7001202C
.word .L70011E00
.word .L70011C6C
.word .L70011D78
glabel audio_related_jump_table_2
.word .L70011B0C
.word .L7001202C
.word .L70011B34
.word .L70011B60
.word .L7001202C
.word .L7001202C
.word .L7001202C
.word .L7001202C
.word .L7001202C
.word .L7001202C
.word .L7001202C
.word .L7001202C
.word .L7001202C
.word .L7001202C
.word .L7001202C
.word .L7001202C
.word .L7001202C
.word .L70011B8C
.word .L70011B8C
.word .L70011B8C
glabel F32_800296C4
 .float 500000.0
.align 4
