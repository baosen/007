


.section .text, "ax" 
glabel osAiSetFrequency
  lui   $t6, %hi(osViClock)#%hi(osViClock) 
  lw    $t6, %lo(osViClock)($t6)#%lo(osViClock)($t6)
  mtc1  $a0, $f8
  addiu $sp, $sp, -0x10
  mtc1  $t6, $f4
  cvt.s.w $f10, $f8
  bgez  $a0, .L7000E960
   cvt.s.w $f6, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f16
  nop   
  add.s $f10, $f10, $f16
.L7000E960:
  div.s $f18, $f6, $f10
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f4
  li    $a1, 1
  add.s $f12, $f18, $f4
  cfc1  $t7, $31
  ctc1  $a1, $31
  nop   
  cvt.w.s $f8, $f12
  cfc1  $a1, $31
  nop   
  andi  $at, $a1, 4
  andi  $a1, $a1, 0x78
  beqz  $a1, .L7000E9E4
   li    $at, 0x4F000000 # 2147483648.000000
  mtc1  $at, $f8
  li    $a1, 1
  sub.s $f8, $f12, $f8
  ctc1  $a1, $31
  nop   
  cvt.w.s $f8, $f8
  cfc1  $a1, $31
  nop   
  andi  $at, $a1, 4
  andi  $a1, $a1, 0x78
  bnez  $a1, .L7000E9DC
   nop   
  mfc1  $a1, $f8
  lui   $at, 0x8000
  b     .L7000E9F4
   or    $a1, $a1, $at
.L7000E9DC:
  b     .L7000E9F4
   li    $a1, -1
.L7000E9E4:
  mfc1  $a1, $f8
  nop   
  bltz  $a1, .L7000E9DC
   nop   
.L7000E9F4:
  ctc1  $t7, $31
  sltiu $at, $a1, 0x84
  beqz  $at, .L7000EA0C
   nop   
  b     .L7000EA88
   li    $v0, -1
.L7000EA0C:
  li    $at, 66
  divu  $zero, $a1, $at
  mflo  $a2
  andi  $t8, $a2, 0xff
  move  $a2, $t8
  slti  $at, $a2, 0x11
  bnez  $at, .L7000EA30
   nop   
  li    $a2, 16
.L7000EA30:
  addiu $t9, $a1, -1
  lui   $t0, %hi(AI_DACRATE_REG) # $t0, 0xa450
  sw    $t9, %lo(AI_DACRATE_REG)($t0)
  addiu $t1, $a2, -1
  lui   $t2, %hi(AI_BITRATE_REG) # $t2, 0xa450
  sw    $t1, %lo(AI_BITRATE_REG)($t2)
  li    $t3, 1
  lui   $t4, %hi(AI_CONTROL_REG) # $t4, 0xa450
  sw    $t3, %lo(AI_CONTROL_REG)($t4)
  lui   $t5, %hi(osViClock)  #osViClock
  lw    $t5, %lo(osViClock)($t5) #osViClock
  div   $zero, $t5, $a1
  mflo  $v0
  bnez  $a1, .L7000EA70
   nop   
  break 7
.L7000EA70:
  li    $at, -1
  bne   $a1, $at, .L7000EA88
   lui   $at, 0x8000
  bne   $t5, $at, .L7000EA88
   nop   
  break 6
.L7000EA88:
  jr    $ra
   addiu $sp, $sp, 0x10
