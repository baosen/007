


.section .text, "ax"  
glabel osViSetSpecialFeatures
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  sw    $a0, 0x28($sp)
  jal   __osDisableInt
   sw    $s0, 0x18($sp)
  lw    $t6, 0x28($sp)
  move  $s0, $v0
  andi  $t7, $t6, 1
  beqz  $t7, .L7000F7EC
   nop   
  lui   $t8, %hi(__osViNext) 
  lw    $t8, %lo(__osViNext)($t8)
  lw    $t9, 0xc($t8)
  ori   $t0, $t9, 8
  sw    $t0, 0xc($t8)
.L7000F7EC:
  lw    $t1, 0x28($sp)
  andi  $t2, $t1, 2
  beqz  $t2, .L7000F814
   nop   
  lui   $t3, %hi(__osViNext) 
  lw    $t3, %lo(__osViNext)($t3)
  li    $at, -9
  lw    $t4, 0xc($t3)
  and   $t5, $t4, $at
  sw    $t5, 0xc($t3)
.L7000F814:
  lw    $t6, 0x28($sp)
  andi  $t7, $t6, 4
  beqz  $t7, .L7000F838
   nop   
  lui   $t9, %hi(__osViNext) 
  lw    $t9, %lo(__osViNext)($t9)
  lw    $t0, 0xc($t9)
  ori   $t8, $t0, 4
  sw    $t8, 0xc($t9)
.L7000F838:
  lw    $t1, 0x28($sp)
  andi  $t2, $t1, 8
  beqz  $t2, .L7000F860
   nop   
  lui   $t4, %hi(__osViNext) 
  lw    $t4, %lo(__osViNext)($t4)
  li    $at, -5
  lw    $t5, 0xc($t4)
  and   $t3, $t5, $at
  sw    $t3, 0xc($t4)
.L7000F860:
  lw    $t6, 0x28($sp)
  andi  $t7, $t6, 0x10
  beqz  $t7, .L7000F884
   nop   
  lui   $t0, %hi(__osViNext) 
  lw    $t0, %lo(__osViNext)($t0)
  lw    $t8, 0xc($t0)
  ori   $t9, $t8, 0x10
  sw    $t9, 0xc($t0)
.L7000F884:
  lw    $t1, 0x28($sp)
  andi  $t2, $t1, 0x20
  beqz  $t2, .L7000F8AC
   nop   
  lui   $t5, %hi(__osViNext) 
  lw    $t5, %lo(__osViNext)($t5)
  li    $at, -17
  lw    $t3, 0xc($t5)
  and   $t4, $t3, $at
  sw    $t4, 0xc($t5)
.L7000F8AC:
  lw    $t6, 0x28($sp)
  andi  $t7, $t6, 0x40
  beqz  $t7, .L7000F8EC
   nop   
  lui   $t8, %hi(__osViNext) 
  lw    $t8, %lo(__osViNext)($t8)
  lui   $at, 1
  lui   $t1, %hi(__osViNext) 
  lw    $t9, 0xc($t8)
  or    $t0, $t9, $at
  sw    $t0, 0xc($t8)
  lw    $t1, %lo(__osViNext)($t1)
  li    $at, -769
  lw    $t2, 0xc($t1)
  and   $t3, $t2, $at
  sw    $t3, 0xc($t1)
.L7000F8EC:
  lw    $t4, 0x28($sp)
  andi  $t5, $t4, 0x80
  beqz  $t5, .L7000F938
   nop   
  lui   $t6, %hi(__osViNext) 
  lw    $t6, %lo(__osViNext)($t6)
  lui   $at, (0xFFFEFFFF >> 16) # lui $at, 0xfffe
  ori   $at, (0xFFFEFFFF & 0xFFFF) # ori $at, $at, 0xffff
  lw    $t7, 0xc($t6)
  lui   $t0, %hi(__osViNext) 
  and   $t9, $t7, $at
  sw    $t9, 0xc($t6)
  lw    $t0, %lo(__osViNext)($t0)
  lw    $t2, 8($t0)
  lw    $t8, 0xc($t0)
  lw    $t3, 4($t2)
  andi  $t1, $t3, 0x300
  or    $t4, $t8, $t1
  sw    $t4, 0xc($t0)
.L7000F938:
  lui   $t5, %hi(__osViNext) 
  lw    $t5, %lo(__osViNext)($t5)
  move  $a0, $s0
  lhu   $t7, ($t5)
  ori   $t9, $t7, 8
  jal   __osRestoreInt
   sh    $t9, ($t5)
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
