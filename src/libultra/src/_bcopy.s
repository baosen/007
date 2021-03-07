.section .text

glabel _bcopy
  beqz  $a2, .L7000F9DC
   move  $a3, $a1
  beq   $a0, $a1, .L7000F9DC
   slt   $at, $a1, $a0
  bnezl $at, .L7000F9A4
   slti  $at, $a2, 0x10
  add   $v0, $a0, $a2
  slt   $at, $a1, $v0
  beql  $at, $zero, .L7000F9A4
   slti  $at, $a2, 0x10
  b     .L7000FB08
   slti  $at, $a2, 0x10
  slti  $at, $a2, 0x10
.L7000F9A4:
  bnez  $at, .L7000F9BC
   nop   
  andi  $v0, $a0, 3
  andi  $v1, $a1, 3
  beq   $v0, $v1, .L7000F9E4
   nop   
.L7000F9BC:
  beqz  $a2, .L7000F9DC
   nop   
  addu  $v1, $a0, $a2
.L7000F9C8:
  lb    $v0, ($a0)
  addiu $a0, $a0, 1
  addiu $a1, $a1, 1
  bne   $a0, $v1, .L7000F9C8
   sb    $v0, -1($a1)
.L7000F9DC:
  jr    $ra
   move  $v0, $a3

.L7000F9E4:
  beqz  $v0, .L7000FA48
   li    $at, 1
  beq   $v0, $at, .L7000FA2C
   li    $at, 2
  beql  $v0, $at, .L7000FA18
   lh    $v0, ($a0)
  lb    $v0, ($a0)
  addiu $a0, $a0, 1
  addiu $a1, $a1, 1
  addiu $a2, $a2, -1
  b     .L7000FA48
   sb    $v0, -1($a1)
  lh    $v0, ($a0)
.L7000FA18:
  addiu $a0, $a0, 2
  addiu $a1, $a1, 2
  addiu $a2, $a2, -2
  b     .L7000FA48
   sh    $v0, -2($a1)
.L7000FA2C:
  lb    $v0, ($a0)
  lh    $v1, 1($a0)
  addiu $a0, $a0, 3
  addiu $a1, $a1, 3
  addiu $a2, $a2, -3
  sb    $v0, -3($a1)
  sh    $v1, -2($a1)
.L7000FA48:
  slti  $at, $a2, 0x20
  bnezl $at, .L7000FAA8
   slti  $at, $a2, 0x10
  lw    $v0, ($a0)
  lw    $v1, 4($a0)
  lw    $t0, 8($a0)
  lw    $t1, 0xc($a0)
  lw    $t2, 0x10($a0)
  lw    $t3, 0x14($a0)
  lw    $t4, 0x18($a0)
  lw    $t5, 0x1c($a0)
  addiu $a0, $a0, 0x20
  addiu $a1, $a1, 0x20
  addiu $a2, $a2, -0x20
  sw    $v0, -0x20($a1)
  sw    $v1, -0x1c($a1)
  sw    $t0, -0x18($a1)
  sw    $t1, -0x14($a1)
  sw    $t2, -0x10($a1)
  sw    $t3, -0xc($a1)
  sw    $t4, -8($a1)
  b     .L7000FA48
   sw    $t5, -4($a1)
.L7000FAA4:
  slti  $at, $a2, 0x10
.L7000FAA8:
  bnezl $at, .L7000FAE4
   slti  $at, $a2, 4
  lw    $v0, ($a0)
  lw    $v1, 4($a0)
  lw    $t0, 8($a0)
  lw    $t1, 0xc($a0)
  addiu $a0, $a0, 0x10
  addiu $a1, $a1, 0x10
  addiu $a2, $a2, -0x10
  sw    $v0, -0x10($a1)
  sw    $v1, -0xc($a1)
  sw    $t0, -8($a1)
  b     .L7000FAA4
   sw    $t1, -4($a1)
.L7000FAE0:
  slti  $at, $a2, 4
.L7000FAE4:
  bnez  $at, .L7000F9BC
   nop   
  lw    $v0, ($a0)
  addiu $a0, $a0, 4
  addiu $a1, $a1, 4
  addiu $a2, $a2, -4
  b     .L7000FAE0
   sw    $v0, -4($a1)
  slti  $at, $a2, 0x10
.L7000FB08:
  add   $a0, $a0, $a2
  bnez  $at, .L7000FB24
   add   $a1, $a1, $a2
  andi  $v0, $a0, 3
  andi  $v1, $a1, 3
  beq   $v0, $v1, .L7000FB54
   nop   
.L7000FB24:
  beqz  $a2, .L7000F9DC
   nop   
  addiu $a0, $a0, -1
  addiu $a1, $a1, -1
  subu  $v1, $a0, $a2
.L7000FB38:
  lb    $v0, ($a0)
  addiu $a0, $a0, -1
  addiu $a1, $a1, -1
  bne   $a0, $v1, .L7000FB38
   sb    $v0, 1($a1)
  jr    $ra
   move  $v0, $a3

.L7000FB54:
  beqz  $v0, .L7000FBB8
   li    $at, 3
  beq   $v0, $at, .L7000FB9C
   li    $at, 2
  beql  $v0, $at, .L7000FB88
   lh    $v0, -2($a0)
  lb    $v0, -1($a0)
  addiu $a0, $a0, -1
  addiu $a1, $a1, -1
  addiu $a2, $a2, -1
  b     .L7000FBB8
   sb    $v0, ($a1)
  lh    $v0, -2($a0)
.L7000FB88:
  addiu $a0, $a0, -2
  addiu $a1, $a1, -2
  addiu $a2, $a2, -2
  b     .L7000FBB8
   sh    $v0, ($a1)
.L7000FB9C:
  lb    $v0, -1($a0)
  lh    $v1, -3($a0)
  addiu $a0, $a0, -3
  addiu $a1, $a1, -3
  addiu $a2, $a2, -3
  sb    $v0, 2($a1)
  sh    $v1, ($a1)
.L7000FBB8:
  slti  $at, $a2, 0x20
  bnezl $at, .L7000FC18
   slti  $at, $a2, 0x10
  lw    $v0, -4($a0)
  lw    $v1, -8($a0)
  lw    $t0, -0xc($a0)
  lw    $t1, -0x10($a0)
  lw    $t2, -0x14($a0)
  lw    $t3, -0x18($a0)
  lw    $t4, -0x1c($a0)
  lw    $t5, -0x20($a0)
  addiu $a0, $a0, -0x20
  addiu $a1, $a1, -0x20
  addiu $a2, $a2, -0x20
  sw    $v0, 0x1c($a1)
  sw    $v1, 0x18($a1)
  sw    $t0, 0x14($a1)
  sw    $t1, 0x10($a1)
  sw    $t2, 0xc($a1)
  sw    $t3, 8($a1)
  sw    $t4, 4($a1)
  b     .L7000FBB8
   sw    $t5, ($a1)
.L7000FC14:
  slti  $at, $a2, 0x10
.L7000FC18:
  bnezl $at, .L7000FC54
   slti  $at, $a2, 4
  lw    $v0, -4($a0)
  lw    $v1, -8($a0)
  lw    $t0, -0xc($a0)
  lw    $t1, -0x10($a0)
  addiu $a0, $a0, -0x10
  addiu $a1, $a1, -0x10
  addiu $a2, $a2, -0x10
  sw    $v0, 0xc($a1)
  sw    $v1, 8($a1)
  sw    $t0, 4($a1)
  b     .L7000FC14
   sw    $t1, ($a1)
.L7000FC50:
  slti  $at, $a2, 4
.L7000FC54:
  bnez  $at, .L7000FB24
   nop   
  lw    $v0, -4($a0)
  addiu $a0, $a0, -4
  addiu $a1, $a1, -4
  addiu $a2, $a2, -4
  b     .L7000FC50
   sw    $v0, ($a1)

