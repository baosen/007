
.section .text, "ax" 

  jr    $ra
   nop   

glabel _timeToSamples
  lw    $t6, 0x44($a0)
  mtc1  $a1, $f4
  lui   $at, %hi(F64_80029420)
  mtc1  $t6, $f8
  cvt.s.w $f6, $f4
  ldc1  $f4, %lo(F64_80029420)($at)
  li    $at, 0x3FE00000 # 1.750000
  mtc1  $at, $f7
  li    $at, -16
  cvt.s.w $f10, $f8
  mul.s $f16, $f6, $f10
  mtc1  $zero, $f6
  cvt.d.s $f18, $f16
  div.d $f8, $f18, $f4
  add.d $f10, $f8, $f6
  cvt.s.d $f0, $f10
  trunc.w.s $f16, $f0
  mfc1  $v0, $f16
  nop   
  and   $t8, $v0, $at
  jr    $ra
   move  $v0, $t8

glabel _freePVoice
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  sw    $a1, 0x1c($sp)
  jal   alUnlink
   move  $a0, $a1
  lw    $a1, 0x18($sp)
  lw    $a0, 0x1c($sp)
  jal   alLink
   addiu $a1, $a1, 0x14
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   

glabel _collectPVoices
  addiu $sp, $sp, -0x28
  sw    $ra, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  lw    $s0, 0x14($a0)
  move  $s1, $a0
  addiu $s2, $a0, 4
  beql  $s0, $zero, .L7000F0A4
   lw    $ra, 0x24($sp)
.L7000F080:
  jal   alUnlink
   move  $a0, $s0
  move  $a0, $s0
  jal   alLink
   move  $a1, $s2
  lw    $s0, 0x14($s1)
  bnez  $s0, .L7000F080
   nop   
  lw    $ra, 0x24($sp)
.L7000F0A4:
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28

glabel __freeParam
  lui   $v0, %hi(alGlobals)
  lw    $v0, %lo(alGlobals)($v0)
  lw    $t6, 0x2c($v0)
  sw    $t6, ($a0)
  jr    $ra
   sw    $a0, 0x2c($v0)

glabel __allocParam
  lui   $v0, %hi(alGlobals)
  lw    $v0, %lo(alGlobals)($v0)
  move  $v1, $zero
  lw    $a0, 0x2c($v0)
  beqz  $a0, .L7000F0F8
   nop   
  lw    $t6, ($a0)
  move  $v1, $a0
  sw    $t6, 0x2c($v0)
  sw    $zero, ($a0)
.L7000F0F8:
  jr    $ra
   move  $v0, $v1

  jr    $ra
   nop   

glabel alAudioFrame
  addiu $sp, $sp, -0xb8
  sw    $s1, 0x30($sp)
  lui   $s1, %hi(alGlobals)
  lw    $s1, %lo(alGlobals)($s1)
  sw    $ra, 0x4c($sp)
  sw    $s7, 0x48($sp)
  sw    $s6, 0x44($sp)
  sw    $s5, 0x40($sp)
  sw    $s4, 0x3c($sp)
  sw    $s3, 0x38($sp)
  sw    $s2, 0x34($sp)
  sw    $s0, 0x2c($sp)
  sdc1  $f22, 0x20($sp)
  sdc1  $f20, 0x18($sp)
  sw    $a0, 0xb8($sp)
  sw    $a1, 0xbc($sp)
  sh    $zero, 0xaa($sp)
  lw    $t7, ($s1)
  move  $s3, $a3
  move  $s4, $a0
  bnez  $t7, .L7000F16C
   move  $s5, $a2
  sw    $zero, ($a1)
  b     .L7000F36C
   move  $v0, $a0
.L7000F16C:
  sw    $zero, 0xb4($sp)
  lw    $v0, ($s1)
  lui   $v1, (0x7FFFFFFF >> 16) # lui $v1, 0x7fff
  ori   $v1, (0x7FFFFFFF & 0xFFFF) # ori $v1, $v1, 0xffff
  beqz  $v0, .L7000F1B8
   li    $s2, -16
  lw    $a0, 0x20($s1)
  lw    $t9, 0x10($v0)
.L7000F18C:
  subu  $t0, $t9, $a0
  slt   $at, $t0, $v1
  beql  $at, $zero, .L7000F1B0
   lw    $v0, ($v0)
  sw    $v0, 0xb4($sp)
  lw    $t1, 0x10($v0)
  lw    $a0, 0x20($s1)
  subu  $v1, $t1, $a0
  lw    $v0, ($v0)
.L7000F1B0:
  bnezl $v0, .L7000F18C
   lw    $t9, 0x10($v0)
.L7000F1B8:
  lw    $t2, 0xb4($sp)
  lw    $a0, 0x20($s1)
  lw    $v0, 0x10($t2)
  subu  $t3, $v0, $a0
  slt   $at, $t3, $s3
  beqz  $at, .L7000F2B0
   sw    $v0, 0x1c($s1)
  li    $at, 0x3FE00000 # 1.750000
  mtc1  $at, $f23
  lui   $at, %hi(F64_80029428)
  mtc1  $zero, $f22
  ldc1  $f20, %lo(F64_80029428)($at)
.L7000F1E8:
  lw    $t4, 0x1c($s1)
  lui   $s0, (0x7FFFFFFF >> 16) # lui $s0, 0x7fff
  ori   $s0, (0x7FFFFFFF & 0xFFFF) # ori $s0, $s0, 0xffff
  and   $t5, $t4, $s2
  sw    $t5, 0x1c($s1)
  lw    $a0, 0xb4($sp)
  lw    $t9, 8($a0)
  jalr  $t9
  nop   
  lw    $t8, 0x44($s1)
  mtc1  $v0, $f4
  lw    $t0, 0xb4($sp)
  mtc1  $t8, $f8
  cvt.s.w $f6, $f4
  lw    $t1, 0x10($t0)
  cvt.s.w $f10, $f8
  mul.s $f16, $f6, $f10
  cvt.d.s $f18, $f16
  div.d $f4, $f18, $f20
  add.d $f8, $f4, $f22
  cvt.s.d $f0, $f8
  trunc.w.s $f6, $f0
  mfc1  $v0, $f6
  nop   
  addu  $t2, $t1, $v0
  sw    $t2, 0x10($t0)
  sw    $zero, 0xb4($sp)
  lw    $v1, ($s1)
  beql  $v1, $zero, .L7000F298
   lw    $t7, 0xb4($sp)
  lw    $a0, 0x20($s1)
  lw    $t3, 0x10($v1)
.L7000F268:
  subu  $t4, $t3, $a0
  slt   $at, $t4, $s0
  beql  $at, $zero, .L7000F28C
   lw    $v1, ($v1)
  sw    $v1, 0xb4($sp)
  lw    $t5, 0x10($v1)
  lw    $a0, 0x20($s1)
  subu  $s0, $t5, $a0
  lw    $v1, ($v1)
.L7000F28C:
  bnezl $v1, .L7000F268
   lw    $t3, 0x10($v1)
  lw    $t7, 0xb4($sp)
.L7000F298:
  lw    $a0, 0x20($s1)
  lw    $v0, 0x10($t7)
  subu  $t9, $v0, $a0
  slt   $at, $t9, $s3
  bnez  $at, .L7000F1E8
   sw    $v0, 0x1c($s1)
.L7000F2B0:
  lw    $t8, 0x1c($s1)
  li    $s2, -16
  addiu $s7, $sp, 0xaa
  and   $t6, $t8, $s2
  blez  $s3, .L7000F34C
   sw    $t6, 0x1c($s1)
  lui   $s6, 0x700
.L7000F2CC:
  lw    $v0, 0x48($s1)
  move  $s0, $s3
  slt   $at, $v0, $s3
  beqz  $at, .L7000F2E8
   nop   
  b     .L7000F2E8
   move  $s0, $v0
.L7000F2E8:
  sw    $s6, ($s4)
  sw    $zero, 4($s4)
  lw    $s2, 0x38($s1)
  li    $a1, 6
  move  $a2, $s5
  lw    $t9, 8($s2)
  move  $a0, $s2
  jalr  $t9
  nop   
  lw    $a3, 0x20($s1)
  addiu $t1, $s4, 8
  sw    $t1, 0x10($sp)
  lw    $t9, 4($s2)
  move  $a0, $s2
  move  $a1, $s7
  jalr  $t9
  move  $a2, $s0
  lw    $t3, 0x20($s1)
  subu  $s3, $s3, $s0
  sll   $t0, $s0, 2
  addu  $t4, $t3, $s0
  move  $s4, $v0
  addu  $s5, $s5, $t0
  bgtz  $s3, .L7000F2CC
   sw    $t4, 0x20($s1)
.L7000F34C:
  lw    $t5, 0xb8($sp)
  lw    $t6, 0xbc($sp)
  move  $a0, $s1
  subu  $t7, $s4, $t5
  sra   $t8, $t7, 3
  jal   _collectPVoices
   sw    $t8, ($t6)
  move  $v0, $s4
.L7000F36C:
  lw    $ra, 0x4c($sp)
  ldc1  $f20, 0x18($sp)
  ldc1  $f22, 0x20($sp)
  lw    $s0, 0x2c($sp)
  lw    $s1, 0x30($sp)
  lw    $s2, 0x34($sp)
  lw    $s3, 0x38($sp)
  lw    $s4, 0x3c($sp)
  lw    $s5, 0x40($sp)
  lw    $s6, 0x44($sp)
  lw    $s7, 0x48($sp)
  jr    $ra
   addiu $sp, $sp, 0xb8

glabel alSynNew
  addiu $sp, $sp, -0x78
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
  lw    $s7, 0x14($a1)
  sw    $zero, ($a0)
  lw    $t6, 4($a1)
  sw    $zero, 0x20($a0)
  sw    $zero, 0x1c($a0)
  sw    $t6, 0x3c($a0)
  lw    $t7, 0x18($a1)
  li    $t8, 160
  sw    $t8, 0x48($a0)
  sw    $t7, 0x44($a0)
  lw    $t9, 0x10($a1)
  move  $s6, $a0
  move  $fp, $a1
  li    $t0, 28
  sw    $t9, 0x24($a0)
  sw    $t0, 0x10($sp)
  move  $a0, $zero
  move  $a1, $zero
  li    $a3, 1
  jal   alHeapDBAlloc
   move  $a2, $s7
  sw    $v0, 0x5c($sp)
  jal   alSaveNew
   move  $a0, $v0
  lw    $t1, 0x5c($sp)
  li    $t2, 76
  move  $a0, $zero
  sw    $t1, 0x38($s6)
  sw    $t2, 0x10($sp)
  move  $a1, $zero
  move  $a2, $s7
  jal   alHeapDBAlloc
   li    $a3, 1
  li    $t3, 1
  sw    $v0, 0x34($s6)
  sw    $t3, 0x40($s6)
  lw    $a3, 4($fp)
  li    $t4, 4
  sw    $t4, 0x10($sp)
  move  $a0, $zero
  move  $a1, $zero
  jal   alHeapDBAlloc
   move  $a2, $s7
  lw    $a0, 0x34($s6)
  move  $a1, $v0
  jal   alAuxBusNew
   lw    $a2, 4($fp)
  li    $t5, 32
  sw    $t5, 0x10($sp)
  move  $a0, $zero
  move  $a1, $zero
  move  $a2, $s7
  jal   alHeapDBAlloc
   li    $a3, 1
  sw    $v0, 0x30($s6)
  lw    $a3, 4($fp)
  li    $t6, 4
  sw    $t6, 0x10($sp)
  move  $a0, $zero
  move  $a1, $zero
  jal   alHeapDBAlloc
   move  $a2, $s7
  lw    $a0, 0x30($s6)
  move  $a1, $v0
  jal   alMainBusNew
   lw    $a2, 4($fp)
  lbu   $t7, 0x1c($fp)
  move  $a0, $s6
  move  $a2, $fp
  beqz  $t7, .L7000F4FC
   li    $a1, 2
  move  $a1, $zero
  jal   alSynAllocFX
   move  $a3, $s7
  b     .L7000F50C
   sw    $zero, 4($s6)
.L7000F4FC:
  lw    $a0, 0x30($s6)
  jal   alMainBusParam
   lw    $a2, 0x34($s6)
  sw    $zero, 4($s6)
.L7000F50C:
  sw    $zero, 8($s6)
  sw    $zero, 0x14($s6)
  sw    $zero, 0x18($s6)
  sw    $zero, 0xc($s6)
  sw    $zero, 0x10($s6)
  lw    $a3, 4($fp)
  li    $t8, 220
  sw    $t8, 0x10($sp)
  move  $a0, $zero
  move  $a1, $zero
  jal   alHeapDBAlloc
   move  $a2, $s7
  lw    $t9, 4($fp)
  move  $s4, $zero
  move  $s0, $v0
  blez  $t9, .L7000F608
   addiu $a1, $s6, 4
  addiu $s1, $v0, 0x8c
  addiu $s2, $v0, 0x58
  addiu $s3, $v0, 0x10
  sw    $a1, 0x48($sp)
.L7000F560:
  lw    $a1, 0x48($sp)
  move  $s5, $s0
  jal   alLink
   move  $a0, $s0
  sw    $zero, 8($s0)
  lw    $a1, 0x24($s6)
  move  $a0, $s3
  jal   alLoadNew
   move  $a2, $s7
  move  $a0, $s3
  li    $a1, 1
  jal   alLoadParam
   move  $a2, $zero
  move  $a0, $s2
  jal   alResampleNew
   move  $a1, $s7
  move  $a0, $s2
  li    $a1, 1
  jal   alResampleParam
   move  $a2, $s3
  move  $a0, $s1
  jal   alEnvmixerNew
   move  $a1, $s7
  move  $a0, $s1
  li    $a1, 1
  jal   alEnvmixerParam
   move  $a2, $s2
  lw    $a0, 0x34($s6)
  li    $a1, 2
  jal   ultra_7001B4E0
   move  $a2, $s1
  addiu $t0, $s5, 0x8c
  sw    $t0, 0xc($s5)
  lw    $t1, 4($fp)
  addiu $s4, $s4, 1
  addiu $s0, $s0, 0xdc
  slt   $at, $s4, $t1
  addiu $s1, $s1, 0xdc
  addiu $s2, $s2, 0xdc
  bnez  $at, .L7000F560
   addiu $s3, $s3, 0xdc
  move  $s4, $zero
.L7000F608:
  lw    $a0, 0x5c($sp)
  li    $a1, 1
  jal   alSaveParam
   lw    $a2, 0x30($s6)
  lw    $a3, 8($fp)
  li    $t2, 28
  sw    $t2, 0x10($sp)
  move  $a0, $zero
  move  $a1, $zero
  jal   alHeapDBAlloc
   move  $a2, $s7
  sw    $zero, 0x2c($s6)
  lw    $t3, 8($fp)
  move  $v1, $v0
  blezl $t3, .L7000F670
   sw    $s7, 0x28($s6)
  lw    $t4, 0x2c($s6)
.L7000F64C:
  addiu $s4, $s4, 1
  sw    $t4, ($v1)
  sw    $v1, 0x2c($s6)
  lw    $t5, 8($fp)
  addiu $v1, $v1, 0x1c
  slt   $at, $s4, $t5
  bnezl $at, .L7000F64C
   lw    $t4, 0x2c($s6)
  sw    $s7, 0x28($s6)
.L7000F670:
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
   addiu $sp, $sp, 0x78

.section .rodata
glabel F64_80029420
.double 1000000.0
glabel F64_80029428
.double 1000000.0
