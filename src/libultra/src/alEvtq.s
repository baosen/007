


.section .text, "ax" 
glabel alEvtqFlushType
  addiu $sp, $sp, -0x40
  sw    $s3, 0x20($sp)
  sll   $s3, $a1, 0x10
  sw    $s2, 0x1c($sp)
  move  $s2, $a0
  sra   $t6, $s3, 0x10
  sw    $ra, 0x24($sp)
  move  $s3, $t6
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  sw    $a1, 0x44($sp)
  jal   osSetIntMask
   li    $a0, 1
  sw    $v0, 0x2c($sp)
  lw    $s0, 8($s2)
  beqz  $s0, .L70012E68
   nop   
.L70012E24:
  lh    $t7, 0xc($s0)
  lw    $s1, ($s0)
  bne   $s3, $t7, .L70012E60
   nop   
  beqz  $s1, .L70012E4C
   nop   
  lw    $t8, 8($s1)
  lw    $t9, 8($s0)
  addu  $t0, $t8, $t9
  sw    $t0, 8($s1)
.L70012E4C:
  jal   alUnlink
   move  $a0, $s0
  move  $a0, $s0
  jal   alLink
   move  $a1, $s2
.L70012E60:
  bnez  $s1, .L70012E24
   move  $s0, $s1
.L70012E68:
  jal   osSetIntMask
   lw    $a0, 0x2c($sp)
  lw    $ra, 0x24($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x40

glabel alEvtqFlush
  addiu $sp, $sp, -0x38
  sw    $s2, 0x20($sp)
  move  $s2, $a0
  sw    $ra, 0x24($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  jal   osSetIntMask
   li    $a0, 1
  sw    $v0, 0x2c($sp)
  lw    $s0, 8($s2)
  beqz  $s0, .L70012EDC
   nop   
.L70012EBC:
  lw    $s1, ($s0)
  jal   alUnlink
   move  $a0, $s0
  move  $a0, $s0
  jal   alLink
   move  $a1, $s2
  bnez  $s1, .L70012EBC
   move  $s0, $s1
.L70012EDC:
  jal   osSetIntMask
   lw    $a0, 0x2c($sp)
  lw    $ra, 0x24($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x38

glabel alEvtqPostEvent
  addiu $sp, $sp, -0x30
  sw    $ra, 0x14($sp)
  sw    $a0, 0x30($sp)
  sw    $a1, 0x34($sp)
  sw    $zero, 0x20($sp)
  li    $a0, 1
  jal   osSetIntMask
   sw    $a2, 0x38($sp)
  lw    $t6, 0x30($sp)
  lw    $a3, 0x38($sp)
  move  $a1, $v0
  lw    $t0, ($t6)
  bnez  $t0, .L70012F44
   move  $a0, $t0
  jal   osSetIntMask
   move  $a0, $v0
  b     .L70013014
   lw    $ra, 0x14($sp)
.L70012F44:
  sw    $a1, 0x1c($sp)
  sw    $a3, 0x38($sp)
  jal   alUnlink
   sw    $t0, 0x2c($sp)
  lw    $t0, 0x2c($sp)
  lw    $a0, 0x34($sp)
  li    $a2, 16
  jal   alCopy
   addiu $a1, $t0, 0xc
  lw    $a3, 0x38($sp)
  lui   $at, (0x7FFFFFFF >> 16) # lui $at, 0x7fff
  ori   $at, (0x7FFFFFFF & 0xFFFF) # ori $at, $at, 0xffff
  bne   $a3, $at, .L70012F84
   lw    $t0, 0x2c($sp)
  li    $t7, -1
  sw    $t7, 0x20($sp)
.L70012F84:
  lw    $v0, 0x30($sp)
  li    $at, -8
  lw    $t8, 0x20($sp)
  beq   $v0, $at, .L70013008
   addiu $a1, $v0, 8
.L70012F98:
  lw    $v0, ($a1)
  bnezl $v0, .L70012FCC
   lw    $v1, 8($v0)
  beql  $t8, $zero, .L70012FB8
   sw    $a3, 8($t0)
  b     .L70012FB8
   sw    $zero, 8($t0)
  sw    $a3, 8($t0)
.L70012FB8:
  jal   alLink
   move  $a0, $t0
  b     .L70013008
   nop   
  lw    $v1, 8($v0)
.L70012FCC:
  move  $a2, $v0
  slt   $at, $a3, $v1
  beql  $at, $zero, .L70013000
   move  $a1, $v0
  sw    $a3, 8($t0)
  lw    $t9, 8($a2)
  move  $a0, $t0
  subu  $t1, $t9, $a3
  jal   alLink
   sw    $t1, 8($a2)
  b     .L70013008
   nop   
  move  $a1, $v0
.L70013000:
  bnez  $v0, .L70012F98
   subu  $a3, $a3, $v1
.L70013008:
  jal   osSetIntMask
   lw    $a0, 0x1c($sp)
  lw    $ra, 0x14($sp)
.L70013014:
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   

glabel alEvtqNextEvent
  addiu $sp, $sp, -0x30
  sw    $ra, 0x1c($sp)
  sw    $a0, 0x30($sp)
  sw    $s0, 0x18($sp)
  sw    $a1, 0x34($sp)
  jal   osSetIntMask
   li    $a0, 1
  lw    $t6, 0x30($sp)
  sw    $v0, 0x24($sp)
  lw    $t8, 0x34($sp)
  lw    $s0, 8($t6)
  move  $v1, $zero
  beql  $s0, $zero, .L70013088
   li    $t7, -1
  jal   alUnlink
   move  $a0, $s0
  addiu $a0, $s0, 0xc
  lw    $a1, 0x34($sp)
  jal   alCopy
   li    $a2, 16
  move  $a0, $s0
  jal   alLink
   lw    $a1, 0x30($sp)
  b     .L7001308C
   lw    $v1, 8($s0)
  li    $t7, -1
.L70013088:
  sh    $t7, ($t8)
.L7001308C:
  lw    $a0, 0x24($sp)
  jal   osSetIntMask
   sw    $v1, 0x28($sp)
  lw    $ra, 0x1c($sp)
  lw    $v0, 0x28($sp)
  lw    $s0, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x30

glabel alEvtqNew
  addiu $sp, $sp, -0x28
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s0, 0x14($sp)
  sw    $ra, 0x24($sp)
  sw    $s1, 0x18($sp)
  move  $s2, $a0
  move  $s3, $a2
  sw    $zero, 0x10($a0)
  sw    $zero, 8($a0)
  sw    $zero, 0xc($a0)
  sw    $zero, ($a0)
  sw    $zero, 4($a0)
  blez  $a2, .L70013104
   move  $s0, $zero
  move  $s1, $a1
.L700130EC:
  move  $a0, $s1
  jal   alLink
   move  $a1, $s2
  addiu $s0, $s0, 1
  bne   $s0, $s3, .L700130EC
   addiu $s1, $s1, 0x1c
.L70013104:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
