


.section .text 
glabel guMtxF2L
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f0
  move  $v0, $a1
  addiu $v1, $a1, 0x20
  move  $a2, $zero
  move  $a3, $a0
  li    $t4, 4
  li    $t3, 2
  lui   $t2, 0xffff
.L7000FF34:
  move  $a0, $zero
  move  $t0, $a3
  lwc1  $f14, 4($t0)
  addiu $a0, $a0, 1
  lwc1  $f18, ($t0)
  mul.s $f16, $f14, $f0
  beq   $a0, $t3, .L7000FFB4
   nop   
.L7000FF54:
  mul.s $f14, $f18, $f0
  addiu $a0, $a0, 1
  addiu $v0, $v0, 4
  addiu $v1, $v1, 4
  addiu $t0, $t0, 8
  trunc.w.s $f12, $f16
  trunc.w.s $f14, $f14
  mfc1  $t1, $f12
  mfc1  $a1, $f14
  sra   $t9, $t1, 0x10
  andi  $t5, $t9, 0xffff
  and   $t8, $a1, $t2
  or    $t6, $t8, $t5
  sll   $t7, $a1, 0x10
  and   $t9, $t7, $t2
  sw    $t6, -4($v0)
  andi  $t8, $t1, 0xffff
  or    $t5, $t9, $t8
  sw    $t5, -4($v1)
  lwc1  $f14, 4($t0)
  lwc1  $f18, ($t0)
  mul.s $f16, $f14, $f0
  bne   $a0, $t3, .L7000FF54
   nop   
.L7000FFB4:
  mul.s $f14, $f18, $f0
  addiu $t0, $t0, 8
  addiu $v0, $v0, 4
  addiu $v1, $v1, 4
  trunc.w.s $f12, $f16
  trunc.w.s $f14, $f14
  mfc1  $t1, $f12
  mfc1  $a1, $f14
  sra   $t9, $t1, 0x10
  andi  $t5, $t9, 0xffff
  and   $t8, $a1, $t2
  or    $t6, $t8, $t5
  sll   $t7, $a1, 0x10
  and   $t9, $t7, $t2
  andi  $t8, $t1, 0xffff
  sw    $t6, -4($v0)
  or    $t5, $t9, $t8
  sw    $t5, -4($v1)
  addiu $a2, $a2, 1
  bne   $a2, $t4, .L7000FF34
   addiu $a3, $a3, 0x10
  jr    $ra
   nop   

.section .rodata
glabel F64_80029430
.word 0x3f91df46, 0x9d353918 #0.017453292222222222
.word 0,0

.section .text
glabel guMtxIdentF
  li    $at, 0x3F800000 # 1.000000
  move  $v1, $a0
  mtc1  $at, $f0
  mtc1  $zero, $f2
  li    $a0, 1
  move  $v0, $zero
  li    $a3, 4
  li    $a2, 3
  li    $a1, 2
.L70010034:
  bnezl $v0, .L70010048
   swc1  $f2, ($v1)
  b     .L70010048
   swc1  $f0, ($v1)
  swc1  $f2, ($v1)
.L70010048:
  bnel  $v0, $a0, .L7001005C
   swc1  $f2, 4($v1)
  b     .L7001005C
   swc1  $f0, 4($v1)
  swc1  $f2, 4($v1)
.L7001005C:
  bnel  $v0, $a1, .L70010070
   swc1  $f2, 8($v1)
  b     .L70010070
   swc1  $f0, 8($v1)
  swc1  $f2, 8($v1)
.L70010070:
  bnel  $v0, $a2, .L70010084
   swc1  $f2, 0xc($v1)
  b     .L70010084
   swc1  $f0, 0xc($v1)
  swc1  $f2, 0xc($v1)
.L70010084:
  addiu $v0, $v0, 1
  bne   $v0, $a3, .L70010034
   addiu $v1, $v1, 0x10
  jr    $ra
   nop   

glabel guMtxIdent
  addiu $sp, $sp, -0x58
  sw    $ra, 0x14($sp)
  sw    $a0, 0x58($sp)
  jal   guMtxIdentF
   addiu $a0, $sp, 0x18
  addiu $a0, $sp, 0x18
  jal   guMtxF2L
   lw    $a1, 0x58($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x58
  jr    $ra
   nop   

glabel guMtxL2F
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f0
  addiu $sp, $sp, -0x10
  move  $v0, $a1
  addiu $v1, $a1, 0x20
  move  $a2, $zero
  move  $t0, $a0
  li    $t4, 4
  li    $t3, 2
  lui   $t2, 0xffff
.L700100F0:
  move  $a0, $zero
  move  $t1, $t0
.L700100F8:
  lw    $t6, ($v1)
  lw    $t9, ($v0)
  addiu $a0, $a0, 1
  srl   $t7, $t6, 0x10
  andi  $t8, $t7, 0xffff
  and   $t5, $t9, $t2
  or    $t6, $t8, $t5
  sw    $t6, 4($sp)
  lw    $t7, ($v1)
  lw    $t8, ($v0)
  lw    $a1, 4($sp)
  andi  $t9, $t7, 0xffff
  sll   $t5, $t8, 0x10
  mtc1  $a1, $f18
  and   $t6, $t5, $t2
  or    $a3, $t9, $t6
  cvt.s.w $f18, $f18
  mtc1  $a3, $f16
  sw    $a3, ($sp)
  addiu $v0, $v0, 4
  addiu $v1, $v1, 4
  cvt.s.w $f16, $f16
  addiu $t1, $t1, 8
  div.s $f18, $f18, $f0
  div.s $f16, $f16, $f0
  swc1  $f18, -8($t1)
  bne   $a0, $t3, .L700100F8
   swc1  $f16, -4($t1)
  addiu $a2, $a2, 1
  bne   $a2, $t4, .L700100F0
   addiu $t0, $t0, 0x10
  jr    $ra
   addiu $sp, $sp, 0x10
