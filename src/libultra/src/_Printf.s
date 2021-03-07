.section .text

glabel _Putfld
  addiu $sp, $sp, -0x18
  sw    $a1, 0x20($sp)
  sw    $ra, 0x14($sp)
  andi  $t6, $a1, 0xff
  slti  $at, $t6, 0x26
  move  $a1, $t6
  sw    $zero, 0xc($s0)
  sw    $zero, 0x10($s0)
  sw    $zero, 0x14($s0)
  sw    $zero, 0x18($s0)
  sw    $zero, 0x1c($s0)
  sw    $zero, 0x20($s0)
  bnez  $at, .L7001394C
   move  $v1, $t6
  addiu $t7, $t6, -0x45
  sltiu $at, $t7, 0x34
  beqz  $at, .L70013F38
   sll   $t7, $t7, 2
  lui   $at, %hi(jpt_80029714)
  addu  $at, $at, $t7
  lw    $t7, %lo(jpt_80029714)($at)
  jr    $t7
   nop   
.L7001394C:
  li    $at, 37
  beql  $v1, $at, .L70013F1C
   lw    $t8, 0xc($s0)
  b     .L70013F3C
   lw    $t6, 0xc($s0)
.L70013960:
  lw    $t8, ($a2)
  li    $at, -4
  addiu $t9, $t8, 3
  and   $t6, $t9, $at
  addiu $t7, $t6, 4
  sw    $t7, ($a2)
  lw    $t6, 0xc($s0)
  lw    $t9, -4($t7)
  addu  $t7, $a3, $t6
  sb    $t9, ($t7)
  lw    $t8, 0xc($s0)
  addiu $t6, $t8, 1
  b     .L70013F50
   sw    $t6, 0xc($s0)
.L70013998:
  lbu   $v0, 0x34($s0)
  li    $at, 108
  bnel  $v0, $at, .L700139D8
   li    $at, 76
  lw    $t9, ($a2)
  li    $at, -4
  addiu $t7, $t9, 3
  and   $t8, $t7, $at
  addiu $t6, $t8, 4
  sw    $t6, ($a2)
  lw    $t7, -4($t6)
  sra   $t8, $t7, 0x1f
  sw    $t8, ($s0)
  b     .L70013A34
   sw    $t7, 4($s0)
  li    $at, 76
.L700139D8:
  bnel  $v0, $at, .L70013A10
   lw    $t7, ($a2)
  lw    $t6, ($a2)
  li    $at, -8
  addiu $t7, $t6, 7
  and   $t8, $t7, $at
  addiu $t9, $t8, 8
  sw    $t9, ($a2)
  lw    $t8, -8($t9)
  lw    $t9, -4($t9)
  sw    $t8, ($s0)
  b     .L70013A34
   sw    $t9, 4($s0)
  lw    $t7, ($a2)
.L70013A10:
  li    $at, -4
  addiu $t6, $t7, 3
  and   $t8, $t6, $at
  addiu $t9, $t8, 4
  sw    $t9, ($a2)
  lw    $t6, -4($t9)
  sra   $t8, $t6, 0x1f
  sw    $t8, ($s0)
  sw    $t6, 4($s0)
.L70013A34:
  lbu   $t7, 0x34($s0)
  li    $at, 104
  bnel  $t7, $at, .L70013A60
   lw    $t6, ($s0)
  lw    $t7, 4($s0)
  sll   $t9, $t7, 0x10
  sra   $t6, $t9, 0x10
  sra   $t8, $t6, 0x1f
  sw    $t8, ($s0)
  sw    $t6, 4($s0)
  lw    $t6, ($s0)
.L70013A60:
  bgtzl $t6, .L70013A9C
   lw    $v0, 0x30($s0)
  bltzl $t6, .L70013A7C
   lw    $t9, 0xc($s0)
  b     .L70013A9C
   lw    $v0, 0x30($s0)
  lw    $t9, 0xc($s0)
.L70013A7C:
  li    $t8, 45
  addu  $t6, $a3, $t9
  sb    $t8, ($t6)
  lw    $t7, 0xc($s0)
  addiu $t9, $t7, 1
  b     .L70013AEC
   sw    $t9, 0xc($s0)
  lw    $v0, 0x30($s0)
.L70013A9C:
  andi  $t8, $v0, 2
  beqz  $t8, .L70013AC8
   andi  $t6, $v0, 1
  lw    $t7, 0xc($s0)
  li    $t6, 43
  addu  $t9, $a3, $t7
  sb    $t6, ($t9)
  lw    $t8, 0xc($s0)
  addiu $t7, $t8, 1
  b     .L70013AEC
   sw    $t7, 0xc($s0)
.L70013AC8:
  beql  $t6, $zero, .L70013AF0
   lw    $t9, 0xc($s0)
  lw    $t8, 0xc($s0)
  li    $t9, 32
  addu  $t7, $a3, $t8
  sb    $t9, ($t7)
  lw    $t6, 0xc($s0)
  addiu $t8, $t6, 1
  sw    $t8, 0xc($s0)
.L70013AEC:
  lw    $t9, 0xc($s0)
.L70013AF0:
  move  $a0, $s0
  addu  $t7, $t9, $a3
  jal   _Litob
   sw    $t7, 8($s0)
  b     .L70013F54
   lw    $ra, 0x14($sp)
.L70013B08:
  lbu   $v0, 0x34($s0)
  li    $at, 108
  bnel  $v0, $at, .L70013B48
   li    $at, 76
  lw    $t6, ($a2)
  li    $at, -4
  addiu $t8, $t6, 3
  and   $t9, $t8, $at
  addiu $t7, $t9, 4
  sw    $t7, ($a2)
  lw    $t8, -4($t7)
  sra   $t6, $t8, 0x1f
  sw    $t6, ($s0)
  b     .L70013BA4
   sw    $t8, 4($s0)
  li    $at, 76
.L70013B48:
  bnel  $v0, $at, .L70013B80
   lw    $t6, ($a2)
  lw    $t9, ($a2)
  li    $at, -8
  addiu $t8, $t9, 7
  and   $t6, $t8, $at
  addiu $t7, $t6, 8
  sw    $t7, ($a2)
  lw    $t9, -4($t7)
  lw    $t8, -8($t7)
  sw    $t9, 4($s0)
  b     .L70013BA4
   sw    $t8, ($s0)
  lw    $t6, ($a2)
.L70013B80:
  li    $at, -4
  addiu $t7, $t6, 3
  and   $t8, $t7, $at
  addiu $t9, $t8, 4
  sw    $t9, ($a2)
  lw    $t7, -4($t9)
  sra   $t8, $t7, 0x1f
  sw    $t8, ($s0)
  sw    $t7, 4($s0)
.L70013BA4:
  lbu   $v0, 0x34($s0)
  li    $at, 104
  bne   $v0, $at, .L70013BCC
   nop   
  lw    $t7, 4($s0)
  li    $t6, 0
  sw    $t6, ($s0)
  andi  $t9, $t7, 0xffff
  b     .L70013BE4
   sw    $t9, 4($s0)
.L70013BCC:
  bnezl $v0, .L70013BE8
   lw    $t7, 0x30($s0)
  lw    $t9, 4($s0)
  li    $t8, 0
  sw    $t8, ($s0)
  sw    $t9, 4($s0)
.L70013BE4:
  lw    $t7, 0x30($s0)
.L70013BE8:
  andi  $t6, $t7, 8
  beql  $t6, $zero, .L70013C40
   lw    $t8, 0xc($s0)
  lw    $t9, 0xc($s0)
  li    $t8, 48
  li    $at, 120
  addu  $t7, $a3, $t9
  sb    $t8, ($t7)
  lw    $t6, 0xc($s0)
  addiu $t9, $t6, 1
  beq   $v1, $at, .L70013C24
   sw    $t9, 0xc($s0)
  li    $at, 88
  bnel  $v1, $at, .L70013C40
   lw    $t8, 0xc($s0)
.L70013C24:
  lw    $t8, 0xc($s0)
  addu  $t7, $a3, $t8
  sb    $a1, ($t7)
  lw    $t6, 0xc($s0)
  addiu $t9, $t6, 1
  sw    $t9, 0xc($s0)
  lw    $t8, 0xc($s0)
.L70013C40:
  move  $a0, $s0
  addu  $t7, $t8, $a3
  jal   _Litob
   sw    $t7, 8($s0)
  b     .L70013F54
   lw    $ra, 0x14($sp)
.L70013C58:
  lbu   $t6, 0x34($s0)
  li    $at, 76
  bnel  $t6, $at, .L70013CC8
   lw    $v0, ($a2)
  lw    $v0, ($a2)
  andi  $t9, $v0, 1
  beqz  $t9, .L70013C88
   move  $v1, $v0
  addiu $t8, $v1, 7
  sw    $t8, ($a2)
  b     .L70013CB8
   addiu $v0, $t8, -0x16
.L70013C88:
  andi  $t7, $v1, 2
  beqz  $t7, .L70013CA4
   addiu $t9, $v0, 7
  addiu $t6, $v1, 0xa
  sw    $t6, ($a2)
  b     .L70013CB4
   addiu $a0, $t6, -0x28
.L70013CA4:
  li    $at, -8
  and   $t8, $t9, $at
  addiu $a0, $t8, 8
  sw    $a0, ($a2)
.L70013CB4:
  move  $v0, $a0
.L70013CB8:
  ldc1  $f4, -8($v0)
  b     .L70013D1C
   sdc1  $f4, ($s0)
  lw    $v0, ($a2)
.L70013CC8:
  andi  $t6, $v0, 1
  beqz  $t6, .L70013CE4
   move  $v1, $v0
  addiu $t9, $v1, 7
  sw    $t9, ($a2)
  b     .L70013D14
   addiu $v0, $t9, -0x16
.L70013CE4:
  andi  $t8, $v1, 2
  beqz  $t8, .L70013D00
   addiu $t6, $v0, 7
  addiu $t7, $v1, 0xa
  sw    $t7, ($a2)
  b     .L70013D10
   addiu $a0, $t7, -0x28
.L70013D00:
  li    $at, -8
  and   $t9, $t6, $at
  addiu $a0, $t9, 8
  sw    $a0, ($a2)
.L70013D10:
  move  $v0, $a0
.L70013D14:
  ldc1  $f6, -8($v0)
  sdc1  $f6, ($s0)
.L70013D1C:
  lhu   $t7, ($s0)
  andi  $t6, $t7, 0x8000
  beql  $t6, $zero, .L70013D50
   lw    $v0, 0x30($s0)
  lw    $t8, 0xc($s0)
  li    $t9, 45
  addu  $t7, $a3, $t8
  sb    $t9, ($t7)
  lw    $t6, 0xc($s0)
  addiu $t8, $t6, 1
  b     .L70013DA0
   sw    $t8, 0xc($s0)
  lw    $v0, 0x30($s0)
.L70013D50:
  andi  $t9, $v0, 2
  beqz  $t9, .L70013D7C
   andi  $t7, $v0, 1
  lw    $t6, 0xc($s0)
  li    $t7, 43
  addu  $t8, $a3, $t6
  sb    $t7, ($t8)
  lw    $t9, 0xc($s0)
  addiu $t6, $t9, 1
  b     .L70013DA0
   sw    $t6, 0xc($s0)
.L70013D7C:
  beql  $t7, $zero, .L70013DA4
   lw    $t8, 0xc($s0)
  lw    $t9, 0xc($s0)
  li    $t8, 32
  addu  $t6, $a3, $t9
  sb    $t8, ($t6)
  lw    $t7, 0xc($s0)
  addiu $t9, $t7, 1
  sw    $t9, 0xc($s0)
.L70013DA0:
  lw    $t8, 0xc($s0)
.L70013DA4:
  move  $a0, $s0
  addu  $t6, $t8, $a3
  jal   _Ldtob
   sw    $t6, 8($s0)
  b     .L70013F54
   lw    $ra, 0x14($sp)
.L70013DBC:
  lbu   $v0, 0x34($s0)
  li    $at, 104
  bnel  $v0, $at, .L70013DF8
   li    $at, 108
  lw    $t7, ($a2)
  li    $at, -4
  addiu $t9, $t7, 3
  and   $t8, $t9, $at
  addiu $t6, $t8, 4
  sw    $t6, ($a2)
  lw    $t9, -4($t6)
  lw    $t7, 0x2c($s0)
  b     .L70013F50
   sh    $t7, ($t9)
  li    $at, 108
.L70013DF8:
  bnel  $v0, $at, .L70013E2C
   li    $at, 76
  lw    $t8, ($a2)
  li    $at, -4
  addiu $t6, $t8, 3
  and   $t7, $t6, $at
  addiu $t9, $t7, 4
  sw    $t9, ($a2)
  lw    $t6, -4($t9)
  lw    $t8, 0x2c($s0)
  b     .L70013F50
   sw    $t8, ($t6)
  li    $at, 76
.L70013E2C:
  bnel  $v0, $at, .L70013E68
   lw    $t7, ($a2)
  lw    $t7, ($a2)
  li    $at, -4
  addiu $t9, $t7, 3
  and   $t8, $t9, $at
  addiu $t6, $t8, 4
  sw    $t6, ($a2)
  lw    $t6, -4($t6)
  lw    $t7, 0x2c($s0)
  li    $t8, 0
  sw    $t8, ($t6)
  b     .L70013F50
   sw    $t7, 4($t6)
  lw    $t7, ($a2)
.L70013E68:
  li    $at, -4
  addiu $t8, $t7, 3
  and   $t9, $t8, $at
  addiu $t6, $t9, 4
  sw    $t6, ($a2)
  lw    $t8, -4($t6)
  lw    $t7, 0x2c($s0)
  b     .L70013F50
   sw    $t7, ($t8)
.L70013E8C:
  lw    $t9, ($a2)
  li    $at, -4
  move  $a0, $s0
  addiu $t6, $t9, 3
  and   $t7, $t6, $at
  addiu $t8, $t7, 4
  sw    $t8, ($a2)
  lw    $t6, -4($t8)
  lw    $t7, 0xc($s0)
  li    $a1, 120
  sra   $t8, $t6, 0x1f
  sw    $t6, 4($s0)
  addu  $t6, $t7, $a3
  sw    $t8, ($s0)
  jal   _Litob
   sw    $t6, 8($s0)
  b     .L70013F54
   lw    $ra, 0x14($sp)
.L70013ED4:
  lw    $t8, ($a2)
  li    $at, -4
  addiu $t9, $t8, 3
  and   $t7, $t9, $at
  addiu $t6, $t7, 4
  sw    $t6, ($a2)
  lw    $a0, -4($t6)
  jal   strlen
   sw    $a0, 8($s0)
  lw    $v1, 0x24($s0)
  sw    $v0, 0x14($s0)
  bltz  $v1, .L70013F50
   slt   $at, $v1, $v0
  beql  $at, $zero, .L70013F54
   lw    $ra, 0x14($sp)
  b     .L70013F50
   sw    $v1, 0x14($s0)
  lw    $t8, 0xc($s0)
.L70013F1C:
  li    $t6, 37
  addu  $t9, $a3, $t8
  sb    $t6, ($t9)
  lw    $t7, 0xc($s0)
  addiu $t8, $t7, 1
  b     .L70013F50
   sw    $t8, 0xc($s0)
.L70013F38:
  lw    $t6, 0xc($s0)
.L70013F3C:
  addu  $t9, $a3, $t6
  sb    $a1, ($t9)
  lw    $t7, 0xc($s0)
  addiu $t8, $t7, 1
  sw    $t8, 0xc($s0)
.L70013F50:
  lw    $ra, 0x14($sp)
.L70013F54:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   

glabel _Printf
  addiu $sp, $sp, -0xe0
  sw    $s7, 0x34($sp)
  sw    $s6, 0x30($sp)
  sw    $s5, 0x2c($sp)
  sw    $fp, 0x38($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $a3, 0xec($sp)
  lui   $s5, %hi(zeros)
  lui   $s6, %hi(printf_symbols)
  lui   $s7, %hi(spaces) 
  move  $a3, $a2
  move  $s3, $a1
  move  $s4, $a0
  sw    $ra, 0x3c($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a2, 0xe8($sp)
  sw    $zero, 0xd4($sp)
  addiu $s7, %lo(spaces) # addiu $s7, $s7, 0x7740
  addiu $s6, %lo(printf_symbols) # addiu $s6, $s6, -0x690c
  addiu $s5, %lo(zeros) # addiu $s5, $s5, 0x7764
  li    $fp, 10
.L70013FC0:
  lbu   $s0, ($a3)
  addiu $s2, $a3, 1
  li    $v1, 37
  blez  $s0, .L70013FF4
   move  $a0, $s3
.L70013FD4:
  bnel  $v1, $s0, .L70013FE8
   lbu   $s0, ($s2)
  b     .L70013FF4
   addiu $s2, $s2, -1
  lbu   $s0, ($s2)
.L70013FE8:
  addiu $s2, $s2, 1
  bgtz  $s0, .L70013FD4
   nop   
.L70013FF4:
  subu  $v0, $s2, $a3
  blez  $v0, .L7001402C
   move  $a1, $a3
  move  $s1, $v0
  jalr  $s4
  move  $a2, $v0
  beqz  $v0, .L70014024
   move  $s3, $v0
  lw    $t6, 0xd4($sp)
  addu  $t7, $t6, $s1
  b     .L7001402C
   sw    $t7, 0xd4($sp)
.L70014024:
  b     .L70014574
   lw    $v0, 0xd4($sp)
.L7001402C:
  bnez  $s0, .L7001403C
   addiu $s2, $s2, 1
  b     .L70014574
   lw    $v0, 0xd4($sp)
.L7001403C:
  sw    $zero, 0xd8($sp)
  lbu   $a1, ($s2)
  jal   strchr
   move  $a0, $s6
  beqz  $v0, .L7001408C
   move  $s0, $v0
.L70014054:
  subu  $t9, $s0, $s6
  sll   $t6, $t9, 2
  lui   $t7, %hi(byteshiftleft_lookup)
  addu  $t7, $t7, $t6
  lw    $t7, %lo(byteshiftleft_lookup)($t7)
  lw    $t8, 0xd8($sp)
  addiu $s2, $s2, 1
  move  $a0, $s6
  or    $t9, $t8, $t7
  sw    $t9, 0xd8($sp)
  jal   strchr
   lbu   $a1, ($s2)
  bnez  $v0, .L70014054
   move  $s0, $v0
.L7001408C:
  lbu   $t6, ($s2)
  li    $v0, 42
  lw    $t8, 0xec($sp)
  bne   $v0, $t6, .L700140E0
   lui   $a0, %hi(aHll)
  addiu $t7, $t8, 3
  li    $at, -4
  and   $t9, $t7, $at
  addiu $t6, $t9, 4
  sw    $t6, 0xec($sp)
  lw    $t8, ($t9)
  addiu $s2, $s2, 1
  bgez  $t8, .L700140D8
   sw    $t8, 0xd0($sp)
  lw    $t6, 0xd8($sp)
  negu  $t7, $t8
  sw    $t7, 0xd0($sp)
  ori   $t9, $t6, 4
  sw    $t9, 0xd8($sp)
.L700140D8:
  b     .L7001413C
   lbu   $a1, ($s2)
.L700140E0:
  sw    $zero, 0xd0($sp)
  lbu   $a1, ($s2)
  slti  $at, $a1, 0x30
  bnez  $at, .L7001413C
   slti  $at, $a1, 0x3a
  beql  $at, $zero, .L70014140
   li    $at, 46
  lw    $t8, 0xd0($sp)
.L70014100:
  slti  $at, $t8, 0x3e7
  beql  $at, $zero, .L70014124
   lbu   $a1, 1($s2)
  multu $t8, $fp
  mflo  $t7
  addu  $t6, $a1, $t7
  addiu $t9, $t6, -0x30
  sw    $t9, 0xd0($sp)
  lbu   $a1, 1($s2)
.L70014124:
  addiu $s2, $s2, 1
  slti  $at, $a1, 0x30
  bnez  $at, .L7001413C
   slti  $at, $a1, 0x3a
  bnezl $at, .L70014100
   lw    $t8, 0xd0($sp)
.L7001413C:
  li    $at, 46
.L70014140:
  beq   $a1, $at, .L70014154
   li    $t8, -1
  sw    $t8, 0xcc($sp)
  b     .L700141E8
   lbu   $a1, ($s2)
.L70014154:
  lbu   $t7, 1($s2)
  lw    $t6, 0xec($sp)
  addiu $s2, $s2, 1
  bne   $v0, $t7, .L7001418C
   addiu $t9, $t6, 3
  li    $at, -4
  and   $t8, $t9, $at
  addiu $t7, $t8, 4
  sw    $t7, 0xec($sp)
  lw    $t6, ($t8)
  addiu $s2, $s2, 1
  sw    $t6, 0xcc($sp)
  b     .L700141E8
   lbu   $a1, ($s2)
.L7001418C:
  sw    $zero, 0xcc($sp)
  lbu   $a1, ($s2)
  slti  $at, $a1, 0x30
  bnez  $at, .L700141E8
   slti  $at, $a1, 0x3a
  beqz  $at, .L700141E8
   nop   
  lw    $t9, 0xcc($sp)
.L700141AC:
  slti  $at, $t9, 0x3e7
  beql  $at, $zero, .L700141D0
   lbu   $a1, 1($s2)
  multu $t9, $fp
  mflo  $t7
  addu  $t8, $a1, $t7
  addiu $t6, $t8, -0x30
  sw    $t6, 0xcc($sp)
  lbu   $a1, 1($s2)
.L700141D0:
  addiu $s2, $s2, 1
  slti  $at, $a1, 0x30
  bnez  $at, .L700141E8
   slti  $at, $a1, 0x3a
  bnezl $at, .L700141AC
   lw    $t9, 0xcc($sp)
.L700141E8:
  jal   strchr
   addiu $a0, %lo(aHll) # addiu $a0, $a0, -0x6910
  beqz  $v0, .L70014208
   addiu $s0, $sp, 0xa8
  lbu   $t9, ($s2)
  addiu $s2, $s2, 1
  b     .L7001420C
   sb    $t9, 0xdc($sp)
.L70014208:
  sb    $zero, 0xdc($sp)
.L7001420C:
  lbu   $t7, 0xdc($sp)
  li    $v0, 108
  addiu $a2, $sp, 0xec
  bne   $v0, $t7, .L70014238
   addiu $a3, $sp, 0x7c
  lbu   $t8, ($s2)
  li    $t6, 76
  bne   $v0, $t8, .L70014238
   nop   
  sb    $t6, 0xdc($sp)
  addiu $s2, $s2, 1
.L70014238:
  jal   _Putfld
   lbu   $a1, ($s2)
  lw    $t9, 0xd0($sp)
  lw    $t7, 0xb4($sp)
  lw    $t6, 0xb8($sp)
  subu  $t8, $t9, $t7
  lw    $t7, 0xbc($sp)
  subu  $t9, $t8, $t6
  lw    $t6, 0xc0($sp)
  subu  $t8, $t9, $t7
  lw    $t7, 0xc4($sp)
  subu  $t9, $t8, $t6
  lw    $t6, 0xc8($sp)
  subu  $t8, $t9, $t7
  lw    $t7, 0xd8($sp)
  subu  $t9, $t8, $t6
  sw    $t9, 0xd0($sp)
  andi  $t8, $t7, 4
  bnez  $t8, .L700142EC
   slt   $t6, $zero, $t9
  beql  $t6, $zero, .L700142F0
   lw    $t9, 0xb4($sp)
  beqz  $t6, .L700142EC
   move  $s1, $t9
  sltiu $at, $s1, 0x21
.L7001429C:
  bnez  $at, .L700142AC
   move  $s0, $s1
  b     .L700142AC
   li    $s0, 32
.L700142AC:
  blez  $s0, .L700142E0
   move  $a0, $s3
  move  $a1, $s7
  jalr  $s4
  move  $a2, $s0
  beqz  $v0, .L700142D8
   move  $s3, $v0
  lw    $t7, 0xd4($sp)
  addu  $t8, $t7, $s0
  b     .L700142E0
   sw    $t8, 0xd4($sp)
.L700142D8:
  b     .L70014574
   lw    $v0, 0xd4($sp)
.L700142E0:
  subu  $s1, $s1, $s0
  bgtzl $s1, .L7001429C
   sltiu $at, $s1, 0x21
.L700142EC:
  lw    $t9, 0xb4($sp)
.L700142F0:
  move  $a0, $s3
  addiu $a1, $sp, 0x7c
  blezl $t9, .L70014330
   lw    $t9, 0xb8($sp)
  jalr  $s4
  move  $a2, $t9
  beqz  $v0, .L70014324
   move  $s3, $v0
  lw    $t6, 0xd4($sp)
  lw    $t7, 0xb4($sp)
  addu  $t8, $t6, $t7
  b     .L7001432C
   sw    $t8, 0xd4($sp)
.L70014324:
  b     .L70014574
   lw    $v0, 0xd4($sp)
.L7001432C:
  lw    $t9, 0xb8($sp)
.L70014330:
  slt   $t6, $zero, $t9
  beql  $t6, $zero, .L7001439C
   lw    $t9, 0xbc($sp)
  beqz  $t6, .L70014398
   move  $s1, $t9
  sltiu $at, $s1, 0x21
.L70014348:
  bnez  $at, .L70014358
   move  $s0, $s1
  b     .L70014358
   li    $s0, 32
.L70014358:
  blez  $s0, .L7001438C
   move  $a0, $s3
  move  $a1, $s5
  jalr  $s4
  move  $a2, $s0
  beqz  $v0, .L70014384
   move  $s3, $v0
  lw    $t7, 0xd4($sp)
  addu  $t8, $t7, $s0
  b     .L7001438C
   sw    $t8, 0xd4($sp)
.L70014384:
  b     .L70014574
   lw    $v0, 0xd4($sp)
.L7001438C:
  subu  $s1, $s1, $s0
  bgtzl $s1, .L70014348
   sltiu $at, $s1, 0x21
.L70014398:
  lw    $t9, 0xbc($sp)
.L7001439C:
  move  $a0, $s3
  lw    $a1, 0xb0($sp)
  blezl $t9, .L700143DC
   lw    $t9, 0xc0($sp)
  jalr  $s4
  move  $a2, $t9
  beqz  $v0, .L700143D0
   move  $s3, $v0
  lw    $t6, 0xd4($sp)
  lw    $t7, 0xbc($sp)
  addu  $t8, $t6, $t7
  b     .L700143D8
   sw    $t8, 0xd4($sp)
.L700143D0:
  b     .L70014574
   lw    $v0, 0xd4($sp)
.L700143D8:
  lw    $t9, 0xc0($sp)
.L700143DC:
  slt   $t6, $zero, $t9
  beql  $t6, $zero, .L70014448
   lw    $t9, 0xc4($sp)
  beqz  $t6, .L70014444
   move  $s1, $t9
  sltiu $at, $s1, 0x21
.L700143F4:
  bnez  $at, .L70014404
   move  $s0, $s1
  b     .L70014404
   li    $s0, 32
.L70014404:
  blez  $s0, .L70014438
   move  $a0, $s3
  move  $a1, $s5
  jalr  $s4
  move  $a2, $s0
  beqz  $v0, .L70014430
   move  $s3, $v0
  lw    $t7, 0xd4($sp)
  addu  $t8, $t7, $s0
  b     .L70014438
   sw    $t8, 0xd4($sp)
.L70014430:
  b     .L70014574
   lw    $v0, 0xd4($sp)
.L70014438:
  subu  $s1, $s1, $s0
  bgtzl $s1, .L700143F4
   sltiu $at, $s1, 0x21
.L70014444:
  lw    $t9, 0xc4($sp)
.L70014448:
  move  $a0, $s3
  lw    $t6, 0xb0($sp)
  blez  $t9, .L70014488
   lw    $t7, 0xbc($sp)
  addu  $a1, $t6, $t7
  jalr  $s4
  move  $a2, $t9
  beqz  $v0, .L70014480
   move  $s3, $v0
  lw    $t8, 0xd4($sp)
  lw    $t6, 0xc4($sp)
  addu  $t7, $t8, $t6
  b     .L70014488
   sw    $t7, 0xd4($sp)
.L70014480:
  b     .L70014574
   lw    $v0, 0xd4($sp)
.L70014488:
  lw    $t9, 0xc8($sp)
  slt   $t8, $zero, $t9
  beql  $t8, $zero, .L700144F8
   lw    $t9, 0xd8($sp)
  beqz  $t8, .L700144F4
   move  $s1, $t9
  sltiu $at, $s1, 0x21
.L700144A4:
  bnez  $at, .L700144B4
   move  $s0, $s1
  b     .L700144B4
   li    $s0, 32
.L700144B4:
  blez  $s0, .L700144E8
   move  $a0, $s3
  move  $a1, $s5
  jalr  $s4
  move  $a2, $s0
  beqz  $v0, .L700144E0
   move  $s3, $v0
  lw    $t6, 0xd4($sp)
  addu  $t7, $t6, $s0
  b     .L700144E8
   sw    $t7, 0xd4($sp)
.L700144E0:
  b     .L70014574
   lw    $v0, 0xd4($sp)
.L700144E8:
  subu  $s1, $s1, $s0
  bgtzl $s1, .L700144A4
   sltiu $at, $s1, 0x21
.L700144F4:
  lw    $t9, 0xd8($sp)
.L700144F8:
  lw    $t6, 0xd0($sp)
  andi  $t8, $t9, 4
  beqz  $t8, .L7001456C
   slt   $t7, $zero, $t6
  beqz  $t7, .L7001456C
   nop   
  beqz  $t7, .L7001456C
   move  $s1, $t6
  sltiu $at, $s1, 0x21
.L7001451C:
  bnez  $at, .L7001452C
   move  $s0, $s1
  b     .L7001452C
   li    $s0, 32
.L7001452C:
  blez  $s0, .L70014560
   move  $a0, $s3
  move  $a1, $s7
  jalr  $s4
  move  $a2, $s0
  beqz  $v0, .L70014558
   move  $s3, $v0
  lw    $t9, 0xd4($sp)
  addu  $t8, $t9, $s0
  b     .L70014560
   sw    $t8, 0xd4($sp)
.L70014558:
  b     .L70014574
   lw    $v0, 0xd4($sp)
.L70014560:
  subu  $s1, $s1, $s0
  bgtzl $s1, .L7001451C
   sltiu $at, $s1, 0x21
.L7001456C:
  b     .L70013FC0
   addiu $a3, $s2, 1
.L70014574:
  lw    $ra, 0x3c($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  lw    $s3, 0x24($sp)
  lw    $s4, 0x28($sp)
  lw    $s5, 0x2c($sp)
  lw    $s6, 0x30($sp)
  lw    $s7, 0x34($sp)
  lw    $fp, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0xe0

.section .data
glabel spaces
.asciiz "                                "
.align 2
glabel zeros
.asciiz "00000000000000000000000000000000"
.align 2

.section .rodata
glabel aHll
.ascii "hlL"<0>
glabel printf_symbols
.ascii " +-#0"<0>
.align 2
glabel byteshiftleft_lookup
.word          1,         2,         4,         8,      0x10,         0

glabel jpt_80029714
.word .L70013C58, .L70013F38, .L70013C58, .L70013F38
.word .L70013F38, .L70013F38, .L70013F38, .L70013F38
.word .L70013F38, .L70013F38, .L70013F38, .L70013F38
.word .L70013F38, .L70013F38, .L70013F38, .L70013F38
.word .L70013F38, .L70013F38, .L70013F38, .L70013B08
.word .L70013F38, .L70013F38, .L70013F38, .L70013F38
.word .L70013F38, .L70013F38, .L70013F38, .L70013F38
.word .L70013F38, .L70013F38, .L70013960, .L70013998
.word .L70013C58, .L70013C58, .L70013C58, .L70013F38
.word .L70013998, .L70013F38, .L70013F38, .L70013F38
.word .L70013F38, .L70013DBC, .L70013B08, .L70013E8C
.word .L70013F38, .L70013F38, .L70013ED4, .L70013F38
.word .L70013B08, .L70013F38, .L70013F38, .L70013B08
.align 4
