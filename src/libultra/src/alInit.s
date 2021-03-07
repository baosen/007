


.section .text 

glabel alUnlink
  lw    $v0, ($a0)
  beql  $v0, $zero, .L7000EAA8
   lw    $v0, 4($a0)
  lw    $t6, 4($a0)
  sw    $t6, 4($v0)
  lw    $v0, 4($a0)
.L7000EAA8:
  beqz  $v0, .L7000EAB8
   nop   
  lw    $t7, ($a0)
  sw    $t7, ($v0)
.L7000EAB8:
  jr    $ra
   nop   

glabel alLink
  lw    $t6, ($a1)
  sw    $a1, 4($a0)
  sw    $t6, ($a0)
  lw    $v0, ($a1)
  beqz  $v0, .L7000EADC
   nop   
  sw    $a0, 4($v0)
.L7000EADC:
  jr    $ra
   sw    $a0, ($a1)

glabel alClose
  lui   $t6, %hi(alGlobals) 
  lw    $t6, %lo(alGlobals)($t6)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  beql  $t6, $zero, .L7000EB10
   lw    $ra, 0x14($sp)
  jal   alSynDelete
   nop   
  lui   $at, %hi(alGlobals)
  sw    $zero, %lo(alGlobals)($at)
  lw    $ra, 0x14($sp)
.L7000EB10:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   

glabel alInit
  lui   $v0, %hi(alGlobals)
  addiu $v0, %lo(alGlobals) # addiu $v0, $v0, 0x76e0
  lw    $t6, ($v0)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  bnezl $t6, .L7000EB44
   lw    $ra, 0x14($sp)
  jal   alSynNew
   sw    $a0, ($v0)
  lw    $ra, 0x14($sp)
.L7000EB44:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   

.section .data
glabel alGlobals
 .word 0
.align 4

.section .text
glabel alHeapDBAlloc
  lw    $t6, 0x10($sp)
  sw    $a0, ($sp)
  sw    $a1, 4($sp)
  multu $a3, $t6
  lw    $t9, 8($a2)
  lw    $t8, ($a2)
  lw    $a0, 4($a2)
  li    $at, -16
  addu  $t0, $t8, $t9
  move  $v1, $zero
  mflo  $v0
  addiu $v0, $v0, 0xf
  and   $t7, $v0, $at
  addu  $t1, $a0, $t7
  sltu  $at, $t0, $t1
  bnez  $at, .L7000EB9C
   addu  $t2, $a0, $t7
  move  $v1, $a0
  sw    $t2, 4($a2)
.L7000EB9C:
  jr    $ra
   move  $v0, $v1

