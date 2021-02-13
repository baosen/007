asm(R"
glabel alloc_explosion_smoke_casing_scorch_impact_buffers
  lui   $at, %hi(D_80040170)
  sw    $zero, %lo(D_80040170)($at)
  lui   $at, %hi(D_80040174)
  sw    $zero, %lo(D_80040174)($at)
  lui   $at, %hi(D_8004017C+0x684)
  sw    $zero, %lo(D_8004017C+0x684)($at)
  lui   $at, %hi(D_8004017C+0x688)
  sw    $zero, %lo(D_8004017C+0x688)($at)
  lui   $at, %hi(D_8004017C+0x68C)
  sw    $zero, %lo(D_8004017C+0x68C)($at)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lui   $at, %hi(D_80040178)
  li    $a0, 5952
  li    $a1, 4
  jal   mempAllocBytesInBank
   swc1  $f4, %lo(D_80040178)($at)
  lui   $v1, %hi(ptr_explosion_buf)
  addiu $v1, %lo(ptr_explosion_buf) # addiu $v1, $v1, -0x5ebc
  sw    $v0, ($v1)
  move  $a0, $zero
  move  $a2, $zero
  li    $a1, 960
.L7F006DF4:
  lw    $t6, ($v1)
  move  $v0, $zero
  addu  $t7, $t6, $a2
  sw    $zero, ($t7)
.L7F006E04:
  lw    $t8, ($v1)
  sll   $t9, $a0, 5
  subu  $t9, $t9, $a0
  sll   $t9, $t9, 5
  addu  $t0, $t8, $t9
  addu  $t1, $t0, $v0
  sh    $zero, 0x1c($t1)
  lw    $t2, ($v1)
  sll   $t3, $a0, 5
  subu  $t3, $t3, $a0
  sll   $t3, $t3, 5
  addu  $t4, $t2, $t3
  addu  $t5, $t4, $v0
  sh    $zero, 0x34($t5)
  lw    $t6, ($v1)
  sll   $t7, $a0, 5
  subu  $t7, $t7, $a0
  sll   $t7, $t7, 5
  addu  $t8, $t6, $t7
  addu  $t9, $t8, $v0
  sh    $zero, 0x4c($t9)
  lw    $t0, ($v1)
  sll   $t1, $a0, 5
  subu  $t1, $t1, $a0
  sll   $t1, $t1, 5
  addu  $t2, $t0, $t1
  addu  $t3, $t2, $v0
  addiu $v0, $v0, 0x60
  bne   $v0, $a1, .L7F006E04
   sh    $zero, 0x64($t3)
  addiu $a0, $a0, 1
  slti  $at, $a0, 6
  bnez  $at, .L7F006DF4
   addiu $a2, $a2, 0x3e0
  li    $a0, 8160
  jal   mempAllocBytesInBank
   li    $a1, 4
  lui   $v1, %hi(ptr_smoke_buf)
  addiu $v1, %lo(ptr_smoke_buf) # addiu $v1, $v1, -0x5ec0
  mtc1  $zero, $f0
  sw    $v0, ($v1)
  move  $a0, $zero
  move  $a2, $zero
  li    $a1, 400
.L7F006EB4:
  lw    $t4, ($v1)
  sll   $t7, $a0, 2
  subu  $t7, $t7, $a0
  sll   $t7, $t7, 2
  addu  $t5, $t4, $a2
  sw    $zero, ($t5)
  addu  $t7, $t7, $a0
  lw    $t6, ($v1)
  sll   $t7, $t7, 2
  subu  $t7, $t7, $a0
  sll   $t0, $a0, 2
  subu  $t0, $t0, $a0
  sll   $t7, $t7, 3
  sll   $t0, $t0, 2
  addu  $t8, $t6, $t7
  swc1  $f0, 0x14($t8)
  addu  $t0, $t0, $a0
  lw    $t9, ($v1)
  sll   $t0, $t0, 2
  subu  $t0, $t0, $a0
  sll   $t0, $t0, 3
  addu  $t1, $t9, $t0
  swc1  $f0, 0x3c($t1)
  li    $v0, 80
.L7F006F14:
  sll   $t3, $a0, 2
  subu  $t3, $t3, $a0
  sll   $t3, $t3, 2
  addu  $t3, $t3, $a0
  lw    $t2, ($v1)
  sll   $t3, $t3, 2
  subu  $t3, $t3, $a0
  sll   $t7, $a0, 2
  sll   $t3, $t3, 3
  subu  $t7, $t7, $a0
  addu  $t4, $t2, $t3
  sll   $t7, $t7, 2
  addu  $t5, $t4, $v0
  addu  $t7, $t7, $a0
  swc1  $f0, 0x14($t5)
  lw    $t6, ($v1)
  sll   $t7, $t7, 2
  subu  $t7, $t7, $a0
  sll   $t7, $t7, 3
  sll   $t1, $a0, 2
  subu  $t1, $t1, $a0
  addu  $t8, $t6, $t7
  addu  $t9, $t8, $v0
  sll   $t1, $t1, 2
  addu  $t1, $t1, $a0
  swc1  $f0, 0x3c($t9)
  lw    $t0, ($v1)
  sll   $t1, $t1, 2
  subu  $t1, $t1, $a0
  sll   $t1, $t1, 3
  sll   $t5, $a0, 2
  subu  $t5, $t5, $a0
  addu  $t2, $t0, $t1
  addu  $t3, $t2, $v0
  sll   $t5, $t5, 2
  addu  $t5, $t5, $a0
  swc1  $f0, 0x64($t3)
  lw    $t4, ($v1)
  sll   $t5, $t5, 2
  subu  $t5, $t5, $a0
  sll   $t5, $t5, 3
  addu  $t6, $t4, $t5
  addu  $t7, $t6, $v0
  addiu $v0, $v0, 0xa0
  bne   $v0, $a1, .L7F006F14
   swc1  $f0, 0x8c($t7)
  addiu $a0, $a0, 1
  slti  $at, $a0, 0x14
  bnez  $at, .L7F006EB4
   addiu $a2, $a2, 0x198
  jal   getPlayerCount
   nop   
  li    $at, 1
  bne   $v0, $at, .L7F007048
   li    $a0, 1760
  jal   mempAllocBytesInBank
   li    $a1, 4
  lui   $a1, %hi(ptr_scorch_buf)
  addiu $a1, %lo(ptr_scorch_buf) # addiu $a1, $a1, -0x5eb0
  sw    $v0, ($a1)
  li    $v0, 1760
  move  $v1, $zero
  li    $a2, -1
.L7F007010:
  lw    $t8, ($a1)
  addu  $t9, $t8, $v1
  sh    $a2, ($t9)
  lw    $t0, ($a1)
  addu  $t1, $t0, $v1
  sh    $a2, 0x58($t1)
  lw    $t2, ($a1)
  addu  $t3, $t2, $v1
  sh    $a2, 0xb0($t3)
  lw    $t4, ($a1)
  addu  $t5, $t4, $v1
  addiu $v1, $v1, 0x160
  bne   $v1, $v0, .L7F007010
   sh    $a2, 0x108($t5)
.L7F007048:
  li    $a0, 8000
  jal   mempAllocBytesInBank
   li    $a1, 4
  lui   $a1, %hi(ptr_bullet_impact_buf)
  addiu $a1, %lo(ptr_bullet_impact_buf) # addiu $a1, $a1, -0x5eac
  sw    $v0, ($a1)
  li    $a2, -1
  move  $v1, $zero
.L7F007068:
  lw    $t6, ($a1)
  addu  $t7, $t6, $v1
  addiu $v1, $v1, 0x50
  slti  $at, $v1, 0x1f40
  bnez  $at, .L7F007068
   sh    $a2, ($t7)
  jal   getPlayerCount
   nop   
  li    $t8, 200
  div   $zero, $t8, $v0
  lui   $a2, %hi(max_casings)
  addiu $a2, %lo(max_casings) # addiu $a2, $a2, -0x5eb8
  bnez  $v0, .L7F0070A4
   nop   
  break 7
.L7F0070A4:
  li    $at, -1
  bne   $v0, $at, .L7F0070BC
   lui   $at, 0x8000
  bne   $t8, $at, .L7F0070BC
   nop   
  break 6
.L7F0070BC:
  mflo  $t9
  sw    $t9, ($a2)
  jal   sub_GAME_7F0BDF04
   nop   
  lui   $a2, %hi(max_casings)
  li    $at, 29
  beq   $v0, $at, .L7F0070F4
   addiu $a2, %lo(max_casings) # addiu $a2, $a2, -0x5eb8
  jal   sub_GAME_7F0BDF04
   nop   
  lui   $a2, %hi(max_casings)
  li    $at, 30
  bne   $v0, $at, .L7F007100
   addiu $a2, %lo(max_casings) # addiu $a2, $a2, -0x5eb8
.L7F0070F4:
  lw    $t0, ($a2)
  sra   $t1, $t0, 1
  sw    $t1, ($a2)
.L7F007100:
  lw    $a0, ($a2)
  li    $at, -16
  li    $a1, 4
  sll   $t2, $a0, 4
  subu  $t2, $t2, $a0
  sll   $t2, $t2, 3
  addiu $a0, $t2, 0xf
  and   $t3, $a0, $at
  jal   mempAllocBytesInBank
   move  $a0, $t3
  lui   $a2, %hi(max_casings)
  addiu $a2, %lo(max_casings) # addiu $a2, $a2, -0x5eb8
  lw    $t4, ($a2)
  lui   $v1, %hi(ptr_ejected_casing_buf)
  addiu $v1, %lo(ptr_ejected_casing_buf) # addiu $v1, $v1, -0x5eb4
  sw    $v0, ($v1)
  blez  $t4, .L7F007170
   move  $a0, $zero
  move  $v0, $zero
  lw    $t5, ($v1)
.L7F007150:
  addiu $a0, $a0, 1
  addu  $t6, $t5, $v0
  sw    $zero, ($t6)
  lw    $t7, ($a2)
  addiu $v0, $v0, 0x78
  slt   $at, $a0, $t7
  bnezl $at, .L7F007150
   lw    $t5, ($v1)
.L7F007170:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");
