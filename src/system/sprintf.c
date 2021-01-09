asm(R"
glabel proutSprintf
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   memcpy
   sw    $a2, 0x20($sp)
  lw    $ra, 0x14($sp)
  lw    $t6, 0x20($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   addu  $v0, $v0, $t6
");

asm(R"
glabel sprintf
  addiu $sp, $sp, -0x20
  sw    $a0, 0x20($sp)
  sw    $ra, 0x14($sp)
  sw    $a1, 0x24($sp)
  sw    $a2, 0x28($sp)
  sw    $a3, 0x2c($sp)
  lui   $a0, %hi(proutSprintf) # $a0, 0x7001
  addiu $a0, %lo(proutSprintf) # addiu $a0, $a0, -0x5390
  addiu $a3, $sp, 0x28
  lw    $a2, 0x24($sp)
  jal   _Printf
   lw    $a1, 0x20($sp)
  bltz  $v0, .L7000ACD8
   move  $v1, $v0
  lw    $t6, 0x20($sp)
  addu  $t7, $t6, $v0
  sb    $zero, ($t7)
.L7000ACD8:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  addiu $v0, $v1, -1
  jr    $ra
   nop   
");
