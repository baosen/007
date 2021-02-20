asm(R"
glabel sub_GAME_7F007180
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F0BDF04
   nop   
  jal   getPlayerCount
   sw    $v0, 0x18($sp)
  li    $t6, 200
  div   $zero, $t6, $v0
  lw    $v1, 0x18($sp)
  lui   $a2, %hi(dword_CODE_bss_8007A160)
  addiu $a2, %lo(dword_CODE_bss_8007A160) # addiu $a2, $a2, -0x5ea0
  bnez  $v0, .L7F0071B8
   nop   
  break 7
.L7F0071B8:
  li    $at, -1
  bne   $v0, $at, .L7F0071D0
   lui   $at, 0x8000
  bne   $t6, $at, .L7F0071D0
   nop   
  break 6
.L7F0071D0:
  mflo  $t7
  li    $at, 29
  beq   $v1, $at, .L7F0071EC
   sw    $t7, ($a2)
  li    $at, 30
  bnel  $v1, $at, .L7F0071FC
   lw    $a0, ($a2)
.L7F0071EC:
  lw    $t8, ($a2)
  sra   $t9, $t8, 1
  sw    $t9, ($a2)
  lw    $a0, ($a2)
.L7F0071FC:
  li    $at, -16
  li    $a1, 4
  sll   $t0, $a0, 2
  subu  $t0, $t0, $a0
  sll   $t0, $t0, 2
  addu  $t0, $t0, $a0
  sll   $t0, $t0, 3
  addiu $a0, $t0, 0xf
  and   $t1, $a0, $at
  jal   mempAllocBytesInBank
   move  $a0, $t1
  lui   $a2, %hi(dword_CODE_bss_8007A160)
  addiu $a2, %lo(dword_CODE_bss_8007A160) # addiu $a2, $a2, -0x5ea0
  lw    $t2, ($a2)
  lui   $a0, %hi(dword_CODE_bss_8007A164)
  addiu $a0, %lo(dword_CODE_bss_8007A164) # addiu $a0, $a0, -0x5e9c
  sw    $v0, ($a0)
  blez  $t2, .L7F007270
   move  $v1, $zero
  move  $v0, $zero
  lw    $t3, ($a0)
.L7F007250:
  addiu $v1, $v1, 1
  addu  $t4, $t3, $v0
  sw    $zero, ($t4)
  lw    $t5, ($a2)
  addiu $v0, $v0, 0x68
  slt   $at, $v1, $t5
  bnezl $at, .L7F007250
   lw    $t3, ($a0)
.L7F007270:
  lw    $ra, 0x14($sp)
  lui   $at, %hi(D_80040940)
  sw    $zero, %lo(D_80040940)($at)
  jr    $ra
   addiu $sp, $sp, 0x20
");
