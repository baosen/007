


.section .text  
glabel osViSetXScale
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  swc1  $f12, 0x28($sp)
  sw    $s1, 0x18($sp)
  jal   __osDisableInt
   sw    $s0, 0x14($sp)
  lui   $t6, %hi(__osViNext) 
  lw    $t6, %lo(__osViNext)($t6)
  lwc1  $f4, 0x28($sp)
  lui   $t7, %hi(__osViNext) 
  lui   $t0, %hi(__osViNext) 
  swc1  $f4, 0x18($t6)
  lw    $t7, %lo(__osViNext)($t7)
  move  $s1, $v0
  lhu   $t8, ($t7)
  ori   $t9, $t8, 2
  sh    $t9, ($t7)
  lw    $t0, %lo(__osViNext)($t0)
  lw    $t1, 8($t0)
  lwc1  $f6, 0x18($t0)
  lw    $s0, 0x20($t1)
  andi  $t2, $s0, 0xfff
  move  $s0, $t2
  mtc1  $s0, $f8
  bgez  $s0, .L7000E148
   cvt.s.w $f10, $f8
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f16
  nop   
  add.s $f10, $f10, $f16
.L7000E148:
  mul.s $f18, $f6, $f10
  li    $t4, 1
  cfc1  $t3, $31
  ctc1  $t4, $31
  nop   
  cvt.w.s $f4, $f18
  cfc1  $t4, $31
  nop   
  andi  $at, $t4, 4
  andi  $t4, $t4, 0x78
  beqz  $t4, .L7000E1C0
   li    $at, 0x4F000000 # 2147483648.000000
  mtc1  $at, $f4
  li    $t4, 1
  sub.s $f4, $f18, $f4
  ctc1  $t4, $31
  nop   
  cvt.w.s $f4, $f4
  cfc1  $t4, $31
  nop   
  andi  $at, $t4, 4
  andi  $t4, $t4, 0x78
  bnez  $t4, .L7000E1B8
   nop   
  mfc1  $t4, $f4
  lui   $at, 0x8000
  b     .L7000E1D0
   or    $t4, $t4, $at
.L7000E1B8:
  b     .L7000E1D0
   li    $t4, -1
.L7000E1C0:
  mfc1  $t4, $f4
  nop   
  bltz  $t4, .L7000E1B8
   nop   
.L7000E1D0:
  ctc1  $t3, $31
  andi  $t5, $t4, 0xfff
  sw    $t5, 0x20($t0)
  jal   __osRestoreInt
   move  $a0, $s1
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
