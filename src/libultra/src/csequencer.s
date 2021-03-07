


.section .text  
glabel alCSeqGetLoc
  lw    $t6, 4($a0)
  move  $a2, $a0
  move  $t0, $a0
  sw    $t6, ($a1)
  lw    $t7, 0xc($a0)
  move  $v0, $zero
  move  $v1, $a1
  sw    $t7, 4($a1)
  lw    $t8, 0x10($a0)
  li    $a0, 16
  move  $a3, $a1
  sw    $t8, 8($a1)
.L70012270:
  lw    $t9, 0x18($a2)
  addiu $v0, $v0, 2
  addiu $v1, $v1, 8
  sw    $t9, 4($v1)
  lw    $t1, 0x58($a2)
  addiu $a2, $a2, 8
  addiu $a3, $a3, 2
  sw    $t1, 0x44($v1)
  lbu   $t2, 0x98($t0)
  addiu $t0, $t0, 2
  sb    $t2, 0x8a($a3)
  lbu   $t3, 0xa6($t0)
  sb    $t3, 0x9a($a3)
  lw    $t4, 0xb0($a2)
  sw    $t4, 0xa4($v1)
  lw    $t5, 0x14($a2)
  sw    $t5, 8($v1)
  lw    $t6, 0x54($a2)
  sw    $t6, 0x48($v1)
  lbu   $t7, 0x97($t0)
  sb    $t7, 0x8b($a3)
  lbu   $t8, 0xa7($t0)
  sb    $t8, 0x9b($a3)
  lw    $t9, 0xb4($a2)
  bne   $v0, $a0, .L70012270
   sw    $t9, 0xa8($v1)
  jr    $ra
   nop   

glabel alCSeqSetLoc
  lw    $t6, ($a1)
  move  $v1, $a0
  move  $a3, $a0
  sw    $t6, 4($a0)
  lw    $t7, 4($a1)
  move  $v0, $zero
  move  $a2, $a1
  sw    $t7, 0xc($a0)
  lw    $t8, 8($a1)
  move  $t0, $a1
  sw    $t8, 0x10($a0)
  li    $a0, 16
.L70012310:
  lw    $t9, 0xc($a2)
  addiu $v0, $v0, 2
  addiu $v1, $v1, 8
  sw    $t9, 0x10($v1)
  lw    $t1, 0x4c($a2)
  addiu $a2, $a2, 8
  addiu $a3, $a3, 2
  sw    $t1, 0x50($v1)
  lbu   $t2, 0x8c($t0)
  addiu $t0, $t0, 2
  sb    $t2, 0x96($a3)
  lbu   $t3, 0x9a($t0)
  sb    $t3, 0xa6($a3)
  lw    $t4, 0xa4($a2)
  sw    $t4, 0xb0($v1)
  lw    $t5, 8($a2)
  sw    $t5, 0x14($v1)
  lw    $t6, 0x48($a2)
  sw    $t6, 0x54($v1)
  lbu   $t7, 0x8b($t0)
  sb    $t7, 0x97($a3)
  lbu   $t8, 0x9b($t0)
  sb    $t8, 0xa7($a3)
  lw    $t9, 0xa8($a2)
  bne   $v0, $a0, .L70012310
   sw    $t9, 0xb4($v1)
  jr    $ra
   nop   

glabel ultra_70012380
  addu  $v0, $a0, $a1
  lbu   $t6, 0x98($v0)
  sll   $t7, $a1, 2
  addu  $a2, $a0, $t7
  beql  $t6, $zero, .L700123C8
   lw    $a3, 0x18($a2)
  sll   $t7, $a1, 2
  addu  $a2, $a0, $t7
  lw    $a3, 0x58($a2)
  lbu   $v1, ($a3)
  addiu $t8, $a3, 1
  sw    $t8, 0x58($a2)
  lbu   $t9, 0x98($v0)
  addiu $t6, $t9, -1
  sb    $t6, 0x98($v0)
  jr    $ra
   move  $v0, $v1

  lw    $a3, 0x18($a2)
.L700123C8:
  li    $t0, 254
  lbu   $v1, ($a3)
  addiu $t8, $a3, 1
  sw    $t8, 0x18($a2)
  bne   $t0, $v1, .L7001243C
   nop   
  lbu   $a0, ($t8)
  addiu $t9, $t8, 1
  sw    $t9, 0x18($a2)
  beq   $t0, $a0, .L7001243C
   addiu $t6, $t9, 1
  lbu   $v1, ($t9)
  sw    $t6, 0x18($a2)
  lbu   $a1, ($t6)
  addiu $t7, $t6, 1
  sll   $t9, $a0, 8
  sw    $t7, 0x18($a2)
  addu  $t6, $t9, $v1
  subu  $t7, $t7, $t6
  addiu $t9, $t7, -4
  sw    $t9, 0x58($a2)
  sb    $a1, 0x98($v0)
  lw    $a3, 0x58($a2)
  lbu   $v1, ($a3)
  addiu $t8, $a3, 1
  sw    $t8, 0x58($a2)
  lbu   $t6, 0x98($v0)
  addiu $t7, $t6, -1
  sb    $t7, 0x98($v0)
.L7001243C:
  jr    $ra
   move  $v0, $v1

glabel ultra_70012444
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  move  $a0, $t2
  jal   ultra_70012380
   move  $a1, $t3
  andi  $t6, $v0, 0x80
  beqz  $t6, .L70012488
   move  $t1, $v0
  andi  $t1, $v0, 0x7f
.L70012468:
  move  $a0, $t2
  jal   ultra_70012380
   move  $a1, $t3
  sll   $t7, $t1, 7
  andi  $t8, $v0, 0x7f
  andi  $t9, $v0, 0x80
  bnez  $t9, .L70012468
   addu  $t1, $t7, $t8
.L70012488:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  move  $v0, $t1
  jr    $ra
   nop   

  jr    $ra
   nop   

glabel alCSeqNextEvent
  addiu $sp, $sp, -0x30
  sw    $s0, 0x18($sp)
  move  $s0, $a1
  sw    $ra, 0x1c($sp)
  move  $t4, $a0
  li    $t1, -1
  lw    $a2, 0x10($a0)
  li    $a1, 16
  lw    $t3, 0x24($sp)
  move  $v0, $zero
  lw    $t6, 4($t4)
.L700124D0:
  srlv  $t7, $t6, $v0
  andi  $t8, $t7, 1
  beql  $t8, $zero, .L7001251C
   addiu $v0, $v0, 1
  lw    $t6, 0x14($t4)
  sll   $t9, $v0, 2
  addu  $v1, $t4, $t9
  beql  $t6, $zero, .L70012504
   lw    $a0, 0xb8($v1)
  lw    $t7, 0xb8($v1)
  subu  $t8, $t7, $a2
  sw    $t8, 0xb8($v1)
  lw    $a0, 0xb8($v1)
.L70012504:
  sltu  $at, $a0, $t1
  beql  $at, $zero, .L7001251C
   addiu $v0, $v0, 1
  move  $t1, $a0
  move  $t3, $v0
  addiu $v0, $v0, 1
.L7001251C:
  bnel  $v0, $a1, .L700124D0
   lw    $t6, 4($t4)
  move  $a0, $t4
  jal   ultra_70012380
   move  $a1, $t3
  li    $at, 255
  andi  $t2, $v0, 0xff
  bne   $v0, $at, .L700126A4
   move  $v1, $v0
  move  $a0, $t4
  jal   ultra_70012380
   move  $a1, $t3
  li    $at, 81
  andi  $a2, $v0, 0xff
  bne   $v0, $at, .L700125A8
   move  $v1, $v0
  li    $t9, 3
  sh    $t9, ($s0)
  sb    $t2, 8($s0)
  sb    $a2, 9($s0)
  move  $a0, $t4
  jal   ultra_70012380
   move  $a1, $t3
  sb    $v0, 0xb($s0)
  move  $a0, $t4
  jal   ultra_70012380
   move  $a1, $t3
  sb    $v0, 0xc($s0)
  move  $a0, $t4
  jal   ultra_70012380
   move  $a1, $t3
  sb    $v0, 0xd($s0)
  addu  $t6, $t4, $t3
  b     .L70012740
   sb    $zero, 0xa8($t6)
.L700125A8:
  li    $at, 47
  bnel  $v1, $at, .L700125E8
   li    $at, 46
  lw    $t7, 4($t4)
  li    $t8, 1
  sllv  $t9, $t8, $t3
  xor   $t6, $t7, $t9
  beqz  $t6, .L700125D8
   sw    $t6, 4($t4)
  li    $t7, 18
  b     .L70012740
   sh    $t7, ($s0)
.L700125D8:
  li    $t9, 4
  b     .L70012740
   sh    $t9, ($s0)
  li    $at, 46
.L700125E8:
  bne   $v1, $at, .L70012618
   move  $a0, $t4
  jal   ultra_70012380
   move  $a1, $t3
  move  $a0, $t4
  jal   ultra_70012380
   move  $a1, $t3
  addu  $t6, $t4, $t3
  sb    $zero, 0xa8($t6)
  li    $t8, 19
  b     .L70012740
   sh    $t8, ($s0)
.L70012618:
  li    $at, 45
  bne   $v1, $at, .L70012740
   sll   $t7, $t3, 2
  addu  $t5, $t4, $t7
  lw    $v0, 0x18($t5)
  li    $at, 255
  lbu   $a0, 1($v0)
  addiu $v0, $v0, 1
  addiu $t9, $v0, 5
  bnez  $a0, .L70012650
   lbu   $a1, -1($v0)
  sb    $a1, ($v0)
  b     .L70012690
   sw    $t9, 0x18($t5)
.L70012650:
  beq   $a0, $at, .L7001265C
   addiu $t6, $a0, -1
  sb    $t6, ($v0)
.L7001265C:
  lbu   $t7, 2($v0)
  lbu   $v1, 1($v0)
  lbu   $t6, 3($v0)
  sll   $t9, $t7, 0x10
  sll   $t8, $v1, 0x18
  lbu   $t7, 4($v0)
  addu  $v1, $t8, $t9
  sll   $t8, $t6, 8
  addu  $v1, $v1, $t8
  addiu $v0, $v0, 5
  addu  $v1, $v1, $t7
  subu  $t9, $v0, $v1
  sw    $t9, 0x18($t5)
.L70012690:
  addu  $t6, $t4, $t3
  sb    $zero, 0xa8($t6)
  li    $t8, 20
  b     .L70012740
   sh    $t8, ($s0)
.L700126A4:
  li    $t7, 1
  andi  $t9, $v1, 0x80
  beqz  $t9, .L700126D4
   sh    $t7, ($s0)
  sb    $t2, 8($s0)
  move  $a0, $t4
  jal   ultra_70012380
   move  $a1, $t3
  sb    $v0, 9($s0)
  addu  $t6, $t4, $t3
  b     .L700126E4
   sb    $t2, 0xa8($t6)
.L700126D4:
  addu  $t8, $t4, $t3
  lbu   $t7, 0xa8($t8)
  sb    $v0, 9($s0)
  sb    $t7, 8($s0)
.L700126E4:
  lbu   $v0, 8($s0)
  li    $at, 192
  andi  $t9, $v0, 0xf0
  beq   $t9, $at, .L7001273C
   li    $at, 208
  beq   $t9, $at, .L7001273C
   move  $a0, $t4
  jal   ultra_70012380
   move  $a1, $t3
  lbu   $t6, 8($s0)
  li    $at, 144
  sb    $v0, 0xa($s0)
  andi  $t8, $t6, 0xf0
  bne   $t8, $at, .L70012740
   move  $t2, $t4
  sw    $t1, 0x28($sp)
  jal   ultra_70012444
   sw    $t3, 0x24($sp)
  lw    $t1, 0x28($sp)
  lw    $t3, 0x24($sp)
  b     .L70012740
   sw    $v0, 0xc($s0)
.L7001273C:
  sb    $zero, 0xa($s0)
.L70012740:
  sw    $t1, 4($s0)
  lw    $t7, 0xc($t4)
  sw    $t1, 0x10($t4)
  li    $at, 18
  addu  $t9, $t7, $t1
  sw    $t9, 0xc($t4)
  lh    $t6, ($s0)
  move  $t2, $t4
  sll   $t8, $t3, 2
  beql  $t6, $at, .L70012784
   li    $t6, 1
  jal   ultra_70012444
   addu  $t5, $t4, $t8
  lw    $t7, 0xb8($t5)
  addu  $t9, $t7, $v0
  sw    $t9, 0xb8($t5)
  li    $t6, 1
.L70012784:
  sw    $t6, 0x14($t4)
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   

glabel alCSeqNew
  addiu $sp, $sp, -0x30
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $ra, 0x2c($sp)
  li    $t6, 1
  move  $s0, $a0
  move  $s4, $a1
  sw    $a1, ($a0)
  sw    $zero, 4($a0)
  sw    $zero, 0x10($a0)
  sw    $zero, 0xc($a0)
  sw    $t6, 0x14($a0)
  move  $s1, $a0
  move  $s2, $zero
  li    $s3, 16
  move  $t5, $zero
  move  $t4, $a0
.L700127EC:
  sb    $zero, 0xa8($s1)
  sw    $zero, 0x58($t4)
  sb    $zero, 0x98($s1)
  lw    $t7, ($s0)
  li    $t6, 1
  addu  $t8, $t7, $s2
  lw    $v0, ($t8)
  sllv  $t7, $t6, $t5
  beqz  $v0, .L70012838
   addu  $t6, $s4, $v0
  lw    $t9, 4($s0)
  move  $t2, $s0
  move  $t3, $t5
  or    $t8, $t9, $t7
  sw    $t8, 4($s0)
  jal   ultra_70012444
   sw    $t6, 0x18($t4)
  b     .L7001283C
   sw    $v0, 0xb8($t4)
.L70012838:
  sw    $zero, 0x18($t4)
.L7001283C:
  addiu $t5, $t5, 1
  addiu $s1, $s1, 1
  addiu $s2, $s2, 4
  bne   $t5, $s3, .L700127EC
   addiu $t4, $t4, 4
  lw    $t9, ($s0)
  li    $at, 0x3FF00000 # 1.875000
  mtc1  $at, $f5
  lw    $t7, 0x40($t9)
  mtc1  $zero, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t7, $f6
  bgez  $t7, .L70012880
   cvt.s.w $f8, $f6
  mtc1  $at, $f10
  nop   
  add.s $f8, $f8, $f10
.L70012880:
  cvt.d.s $f6, $f8
  div.d $f10, $f4, $f6
  cvt.s.d $f8, $f10
  swc1  $f8, 8($s0)
  lw    $ra, 0x2c($sp)
  lw    $s4, 0x28($sp)
  lw    $s3, 0x24($sp)
  lw    $s2, 0x20($sp)
  lw    $s1, 0x1c($sp)
  lw    $s0, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x30

glabel alCSeqNewMarker
  addiu $sp, $sp, -0x150
  sw    $s3, 0x20($sp)
  sw    $s1, 0x18($sp)
  move  $s1, $a1
  addiu $s3, $sp, 0x48
  sw    $ra, 0x2c($sp)
  sw    $s5, 0x28($sp)
  sw    $s4, 0x24($sp)
  sw    $s2, 0x1c($sp)
  sw    $s0, 0x14($sp)
  move  $a3, $a0
  move  $s2, $a2
  lw    $a1, ($a3)
  jal   alCSeqNew
   move  $a0, $s3
  li    $s5, 4
  addiu $s4, $sp, 0x140
  addiu $s0, $sp, 0x58
  lw    $t6, 0x4c($sp)
.L700128FC:
  addiu $a0, $sp, 0x48
  move  $v1, $a0
  sw    $t6, ($s1)
  lw    $t7, 0x54($sp)
  move  $v0, $s1
  move  $a1, $s1
  sw    $t7, 4($s1)
  lw    $t8, 0x58($sp)
  sw    $t8, 8($s1)
.L70012920:
  lw    $t0, 0x18($v1)
  addiu $a0, $a0, 4
  addiu $v0, $v0, 0x10
  sw    $t0, -4($v0)
  lw    $t1, 0x58($v1)
  addiu $v1, $v1, 0x10
  addiu $a1, $a1, 4
  sw    $t1, 0x3c($v0)
  lbu   $t2, 0x94($a0)
  sb    $t2, 0x88($a1)
  lbu   $t3, 0xa4($a0)
  sb    $t3, 0x98($a1)
  lw    $t4, 0xa8($v1)
  sw    $t4, 0x9c($v0)
  lw    $t5, 0xc($v1)
  sw    $t5, ($v0)
  lw    $t6, 0x4c($v1)
  sw    $t6, 0x40($v0)
  lbu   $t7, 0x95($a0)
  sb    $t7, 0x89($a1)
  lbu   $t8, 0xa5($a0)
  sb    $t8, 0x99($a1)
  lw    $t9, 0xac($v1)
  sw    $t9, 0xa0($v0)
  lw    $t0, 0x10($v1)
  sw    $t0, 4($v0)
  lw    $t1, 0x50($v1)
  sw    $t1, 0x44($v0)
  lbu   $t2, 0x96($a0)
  sb    $t2, 0x8a($a1)
  lbu   $t3, 0xa6($a0)
  sb    $t3, 0x9a($a1)
  lw    $t4, 0xb0($v1)
  sw    $t4, 0xa4($v0)
  lw    $t5, 0x14($v1)
  sw    $t5, 8($v0)
  lw    $t6, 0x54($v1)
  sw    $t6, 0x48($v0)
  lbu   $t7, 0x97($a0)
  sb    $t7, 0x8b($a1)
  lbu   $t8, 0xa7($a0)
  sb    $t8, 0x9b($a1)
  lw    $t9, 0xb4($v1)
  bne   $a0, $s0, .L70012920
   sw    $t9, 0xa8($v0)
  move  $a0, $s3
  jal   alCSeqNextEvent
   move  $a1, $s4
  lh    $t0, 0x140($sp)
  lw    $t1, 0x54($sp)
  beq   $t0, $s5, .L700129F8
   sltu  $at, $t1, $s2
  bnezl $at, .L700128FC
   lw    $t6, 0x4c($sp)
.L700129F8:
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  lw    $s4, 0x24($sp)
  lw    $s5, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x150

glabel alCSeqGetTicks
  jr    $ra
   lw    $v0, 0xc($a0)

glabel alCSeqSecToTicks
  lw    $t6, ($a0)
  mtc1  $a1, $f12
  lui   $at, %hi(F64_800296D0)
  lw    $t7, 0x40($t6)
  ldc1  $f6, %lo(F64_800296D0)($at)
  cvt.d.s $f4, $f12
  mtc1  $t7, $f10
  mul.d $f8, $f4, $f6
  li    $at, 0x41F00000 # 30.000000
  bgez  $t7, .L70012A60
   cvt.d.w $f16, $f10
  mtc1  $at, $f19
  mtc1  $zero, $f18
  nop   
  add.d $f16, $f16, $f18
.L70012A60:
  mtc1  $a2, $f6
  mul.d $f4, $f8, $f16
  li    $at, 0x41F00000 # 30.000000
  bgez  $a2, .L70012A84
   cvt.d.w $f10, $f6
  mtc1  $at, $f19
  mtc1  $zero, $f18
  nop   
  add.d $f10, $f10, $f18
.L70012A84:
  div.d $f8, $f4, $f10
  li    $v0, 1
  li    $at, 0x41E00000 # 28.000000
  cfc1  $t8, $31
  ctc1  $v0, $31
  nop   
  cvt.w.d $f16, $f8
  cfc1  $v0, $31
  nop   
  andi  $v0, $v0, 0x78
  beql  $v0, $zero, .L70012B08
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
  bnezl $v0, .L70012AFC
   ctc1  $t8, $31
  mfc1  $v0, $f16
  ctc1  $t8, $31
  jr    $ra
   or    $v0, $v0, $at

  ctc1  $t8, $31
.L70012AFC:
  jr    $ra
   li    $v0, -1

  mfc1  $v0, $f16
.L70012B08:
  nop   
  bltzl $v0, .L70012AFC
   ctc1  $t8, $31
  ctc1  $t8, $31
  jr    $ra
   nop   

glabel alCSeqTicksToSec
  mtc1  $a1, $f4
  mtc1  $a2, $f8
  li    $at, 0x4F800000 # 4294967296.000000
  cvt.s.w $f6, $f4
  bgez  $a2, .L70012B44
   cvt.s.w $f10, $f8
  mtc1  $at, $f16
  nop   
  add.s $f10, $f10, $f16
.L70012B44:
  lw    $t6, ($a0)
  mul.s $f18, $f6, $f10
  li    $at, 0x4F800000 # 4294967296.000000
  lw    $t7, 0x40($t6)
  mtc1  $t7, $f8
  cvt.d.s $f4, $f18
  bgez  $t7, .L70012B70
   cvt.s.w $f16, $f8
  mtc1  $at, $f6
  nop   
  add.s $f16, $f16, $f6
.L70012B70:
  lui   $at, %hi(F64_800296D8)
  ldc1  $f18, %lo(F64_800296D8)($at)
  cvt.d.s $f10, $f16
  mul.d $f8, $f10, $f18
  div.d $f6, $f4, $f8
  jr    $ra
   cvt.s.d $f0, $f6

glabel __alCSeqNextDelta
  lw    $t6, 4($a0)
  move  $t1, $a1
  li    $v1, -1
  bnez  $t6, .L70012BA8
   lw    $v0, 0x10($a0)
  jr    $ra
   move  $v0, $zero

.L70012BA8:
  move  $a2, $zero
  li    $t2, 16
  lw    $a1, 4($a0)
.L70012BB4:
  addiu $t6, $a2, 1
  srlv  $t7, $a1, $a2
  andi  $t8, $t7, 1
  beql  $t8, $zero, .L70012C04
   srlv  $t7, $a1, $t6
  lw    $t3, 0x14($a0)
  sll   $t9, $a2, 2
  addu  $a3, $a0, $t9
  beql  $t3, $zero, .L70012BF0
   lw    $t0, 0xb8($a3)
  lw    $t4, 0xb8($a3)
  subu  $t5, $t4, $v0
  sw    $t5, 0xb8($a3)
  lw    $a1, 4($a0)
  lw    $t0, 0xb8($a3)
.L70012BF0:
  sltu  $at, $t0, $v1
  beql  $at, $zero, .L70012C04
   srlv  $t7, $a1, $t6
  move  $v1, $t0
  srlv  $t7, $a1, $t6
.L70012C04:
  andi  $t8, $t7, 1
  beqz  $t8, .L70012C48
   addiu $t6, $a2, 2
  lw    $t3, 0x14($a0)
  sll   $t9, $a2, 2
  addu  $a3, $a0, $t9
  beql  $t3, $zero, .L70012C38
   lw    $t0, 0xbc($a3)
  lw    $t4, 0xbc($a3)
  subu  $t5, $t4, $v0
  sw    $t5, 0xbc($a3)
  lw    $a1, 4($a0)
  lw    $t0, 0xbc($a3)
.L70012C38:
  sltu  $at, $t0, $v1
  beql  $at, $zero, .L70012C4C
   srlv  $t7, $a1, $t6
  move  $v1, $t0
.L70012C48:
  srlv  $t7, $a1, $t6
.L70012C4C:
  andi  $t8, $t7, 1
  beqz  $t8, .L70012C90
   addiu $t6, $a2, 3
  lw    $t3, 0x14($a0)
  sll   $t9, $a2, 2
  addu  $a3, $a0, $t9
  beql  $t3, $zero, .L70012C80
   lw    $t0, 0xc0($a3)
  lw    $t4, 0xc0($a3)
  subu  $t5, $t4, $v0
  sw    $t5, 0xc0($a3)
  lw    $a1, 4($a0)
  lw    $t0, 0xc0($a3)
.L70012C80:
  sltu  $at, $t0, $v1
  beql  $at, $zero, .L70012C94
   srlv  $t7, $a1, $t6
  move  $v1, $t0
.L70012C90:
  srlv  $t7, $a1, $t6
.L70012C94:
  andi  $t8, $t7, 1
  beql  $t8, $zero, .L70012CD8
   addiu $a2, $a2, 4
  lw    $t3, 0x14($a0)
  sll   $t9, $a2, 2
  addu  $a3, $a0, $t9
  beql  $t3, $zero, .L70012CC4
   lw    $a1, 0xc4($a3)
  lw    $t4, 0xc4($a3)
  subu  $t5, $t4, $v0
  sw    $t5, 0xc4($a3)
  lw    $a1, 0xc4($a3)
.L70012CC4:
  sltu  $at, $a1, $v1
  beql  $at, $zero, .L70012CD8
   addiu $a2, $a2, 4
  move  $v1, $a1
  addiu $a2, $a2, 4
.L70012CD8:
  bnel  $a2, $t2, .L70012BB4
   lw    $a1, 4($a0)
  sw    $zero, 0x14($a0)
  sw    $v1, ($t1)
  li    $v0, 1
  jr    $ra
   nop   


.section .rodata
glabel F64_800296D0
.double 1000000.0
glabel F64_800296D8
.double 1000000.0
