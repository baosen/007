


.section .text, "ax"  
glabel osVirtualToPhysical
  addiu $sp, $sp, -0x18
  sw    $a0, 0x18($sp)
  lw    $t6, 0x18($sp)
  lui   $at, 0x8000
  sw    $ra, 0x14($sp)
  sltu  $at, $t6, $at
  bnez  $at, .L7000E8E8
   lui   $at, 0xa000
  sltu  $at, $t6, $at
  beqz  $at, .L7000E8E8
   lui   $at, (0x1FFFFFFF >> 16) # lui $at, 0x1fff
  ori   $at, (0x1FFFFFFF & 0xFFFF) # ori $at, $at, 0xffff
  b     .L7000E91C
   and   $v0, $t6, $at
.L7000E8E8:
  lw    $t7, 0x18($sp)
  lui   $at, 0xa000
  sltu  $at, $t7, $at
  bnez  $at, .L7000E914
   lui   $at, 0xc000
  sltu  $at, $t7, $at
  beqz  $at, .L7000E914
   lui   $at, (0x1FFFFFFF >> 16) # lui $at, 0x1fff
  ori   $at, (0x1FFFFFFF & 0xFFFF) # ori $at, $at, 0xffff
  b     .L7000E91C
   and   $v0, $t7, $at
.L7000E914:
  jal   __osProbeTLB
   lw    $a0, 0x18($sp)
.L7000E91C:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
