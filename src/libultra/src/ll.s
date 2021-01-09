


.section .text, "ax" 
glabel __ull_rshift
  sw    $a0, ($sp)
  sw    $a1, 4($sp)
  sw    $a2, 8($sp)
  sw    $a3, 0xc($sp)
  ld    $t7, 8($sp)
  ld    $t6, ($sp)
  dsrlv $v0, $t6, $t7
  dsll32 $v1, $v0, 0
  dsra32 $v1, $v1, 0
  jr    $ra
   dsra32 $v0, $v0, 0

glabel __ull_rem
  sw    $a0, ($sp)
  sw    $a1, 4($sp)
  sw    $a2, 8($sp)
  sw    $a3, 0xc($sp)
  ld    $t7, 8($sp)
  ld    $t6, ($sp)
  ddivu $zero, $t6, $t7
  bnez  $t7, .L7000EC94
   nop   
  break 7
.L7000EC94:
  mfhi  $v0
  dsll32 $v1, $v0, 0
  dsra32 $v1, $v1, 0
  jr    $ra
   dsra32 $v0, $v0, 0

glabel __ull_div
  sw    $a0, ($sp)
  sw    $a1, 4($sp)
  sw    $a2, 8($sp)
  sw    $a3, 0xc($sp)
  ld    $t7, 8($sp)
  ld    $t6, ($sp)
  ddivu $zero, $t6, $t7
  bnez  $t7, .L7000ECD0
   nop   
  break 7
.L7000ECD0:
  mflo  $v0
  dsll32 $v1, $v0, 0
  dsra32 $v1, $v1, 0
  jr    $ra
   dsra32 $v0, $v0, 0

glabel __ll_lshift
  sw    $a0, ($sp)
  sw    $a1, 4($sp)
  sw    $a2, 8($sp)
  sw    $a3, 0xc($sp)
  ld    $t7, 8($sp)
  ld    $t6, ($sp)
  dsllv $v0, $t6, $t7
  dsll32 $v1, $v0, 0
  dsra32 $v1, $v1, 0
  jr    $ra
   dsra32 $v0, $v0, 0

glabel __ll_rem
  sw    $a0, ($sp)
  sw    $a1, 4($sp)
  sw    $a2, 8($sp)
  sw    $a3, 0xc($sp)
  ld    $t7, 8($sp)
  ld    $t6, ($sp)
  ddivu $zero, $t6, $t7
  bnez  $t7, .L7000ED38
   nop   
  break 7
.L7000ED38:
  mfhi  $v0
  dsll32 $v1, $v0, 0
  dsra32 $v1, $v1, 0
  jr    $ra
   dsra32 $v0, $v0, 0

glabel __ll_div
  sw    $a0, ($sp)
  sw    $a1, 4($sp)
  sw    $a2, 8($sp)
  sw    $a3, 0xc($sp)
  ld    $t7, 8($sp)
  ld    $t6, ($sp)
  ddiv  $zero, $t6, $t7
  nop   
  bnez  $t7, .L7000ED78
   nop   
  break 7
.L7000ED78:
  daddiu $at, $zero, -1
  bne   $t7, $at, .L7000ED94
   daddiu $at, $zero, 1
  dsll32 $at, $at, 0x1f
  bne   $t6, $at, .L7000ED94
   nop   
  break 6
.L7000ED94:
  mflo  $v0
  dsll32 $v1, $v0, 0
  dsra32 $v1, $v1, 0
  jr    $ra
   dsra32 $v0, $v0, 0

glabel __ll_mul
  sw    $a0, ($sp)
  sw    $a1, 4($sp)
  sw    $a2, 8($sp)
  sw    $a3, 0xc($sp)
  ld    $t7, 8($sp)
  ld    $t6, ($sp)
  dmultu $t6, $t7
  mflo  $v0
  dsll32 $v1, $v0, 0
  dsra32 $v1, $v1, 0
  jr    $ra
   dsra32 $v0, $v0, 0

glabel __ull_divremi
  lh    $t7, 0x12($sp)
  sw    $a2, 8($sp)
  sw    $a3, 0xc($sp)
  ld    $t6, 8($sp)
  move  $t8, $t7
  move  $t9, $t8
  ddivu $zero, $t6, $t9
  bnez  $t9, .L7000EE00
   nop   
  break 7
.L7000EE00:
  mflo  $t0
  sd    $t0, ($a0)
  lh    $t2, 0x12($sp)
  ld    $t1, 8($sp)
  move  $t3, $t2
  move  $t4, $t3
  ddivu $zero, $t1, $t4
  bnez  $t4, .L7000EE28
   nop   
  break 7
.L7000EE28:
  mfhi  $t5
  sd    $t5, ($a1)
  jr    $ra
   nop   

glabel __ll_mod
  addiu $sp, $sp, -8
  sw    $a0, 8($sp)
  sw    $a1, 0xc($sp)
  sw    $a2, 0x10($sp)
  sw    $a3, 0x14($sp)
  ld    $t7, 0x10($sp)
  ld    $t6, 8($sp)
  ddiv  $zero, $t6, $t7
  nop   
  bnez  $t7, .L7000EE68
   nop   
  break 7
.L7000EE68:
  daddiu $at, $zero, -1
  bne   $t7, $at, .L7000EE84
   daddiu $at, $zero, 1
  dsll32 $at, $at, 0x1f
  bne   $t6, $at, .L7000EE84
   nop   
  break 6
.L7000EE84:
  mfhi  $t8
  sd    $t8, ($sp)
  bgez  $t8, .L7000EE9C
   nop   
  bgtz  $t7, .L7000EEB4
   nop   
.L7000EE9C:
  ld    $t9, ($sp)
  blez  $t9, .L7000EEC4
   nop   
  ld    $t0, 0x10($sp)
  bgez  $t0, .L7000EEC4
   nop   
.L7000EEB4:
  ld    $t1, ($sp)
  ld    $t2, 0x10($sp)
  daddu $t3, $t1, $t2
  sd    $t3, ($sp)
.L7000EEC4:
  lw    $v0, ($sp)
  lw    $v1, 4($sp)
  jr    $ra
   addiu $sp, $sp, 8

glabel __ll_rshift
  sw    $a0, ($sp)
  sw    $a1, 4($sp)
  sw    $a2, 8($sp)
  sw    $a3, 0xc($sp)
  ld    $t7, 8($sp)
  ld    $t6, ($sp)
  dsrav $v0, $t6, $t7
  dsll32 $v1, $v0, 0
  dsra32 $v1, $v1, 0
  jr    $ra
   dsra32 $v0, $v0, 0

glabel osAiSetNextBuffer
  addiu $sp, $sp, -0x20
  lui   $t7, %hi(B_800276F0) 
  lbu   $t7, %lo(B_800276F0)($t7)
  sw    $a0, 0x20($sp)
  lw    $t6, 0x20($sp)
  sw    $ra, 0x14($sp)
  sw    $a1, 0x24($sp)
  beqz  $t7, .L7000EF2C
   sw    $t6, 0x1c($sp)
  addiu $t8, $t6, -0x2000
  sw    $t8, 0x1c($sp)
.L7000EF2C:
  lw    $t9, 0x20($sp)
  lw    $t0, 0x24($sp)
  li    $at, 8192
  addu  $t1, $t9, $t0
  andi  $t2, $t1, 0x3fff
  bne   $t2, $at, .L7000EF58
   nop   
  li    $t3, 1
  lui   $at, %hi(B_800276F0)
  b     .L7000EF60
   sb    $t3, %lo(B_800276F0)($at)
.L7000EF58:
  lui   $at, %hi(B_800276F0)
  sb    $zero, %lo(B_800276F0)($at)
.L7000EF60:
  jal   __osAiDeviceBusy
   nop   
  beqz  $v0, .L7000EF78
   nop   
  b     .L7000EF98
   li    $v0, -1
.L7000EF78:
  jal   osVirtualToPhysical
   lw    $a0, 0x1c($sp)
  lui   $t4, 0xa450
  sw    $v0, ($t4)
  lw    $t5, 0x24($sp)
  lui   $t7, %hi(AI_LEN_REG) # $t7, 0xa450
  move  $v0, $zero
  sw    $t5, %lo(AI_LEN_REG)($t7)
.L7000EF98:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   

  nop   
  nop   
.section .data
glabel B_800276F0
.byte 0
