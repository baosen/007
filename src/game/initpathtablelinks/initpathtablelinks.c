asm(R"
glabel init_path_table_links
  addiu $sp, $sp, -0xe0
  sw    $s4, 0x28($sp)
  lui   $s4, %hi(ptr_setup_path_tbl)
  addiu $s4, %lo(ptr_setup_path_tbl) # addiu $s4, $s4, 0x5d00
  sw    $s0, 0x18($sp)
  lw    $s0, ($s4)
  lw    $t6, 4($s4)
  sw    $s6, 0x30($sp)
  sw    $ra, 0x3c($sp)
  sw    $fp, 0x38($sp)
  sw    $s7, 0x34($sp)
  sw    $s5, 0x2c($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  move  $s6, $zero
  beqz  $s0, .L7F0069AC
   sw    $t6, 0xd8($sp)
  lw    $t7, ($s0)
  move  $a3, $zero
  move  $t5, $s0
  bltzl $t7, .L7F0069B0
   lw    $t6, 0xd8($sp)
  lw    $v0, 4($t5)
.L7F0068F0:
  lw    $a2, ($v0)
  move  $t0, $v0
  bltzl $a2, .L7F006998
   addiu $a3, $a3, 1
.L7F006900:
  bne   $a2, $a3, .L7F006920
   sll   $t9, $a2, 4
  lw    $t8, 0x20($s4)
  li    $s6, 1
  beql  $t8, $zero, .L7F006988
   lw    $a2, 4($t0)
  b     .L7F006988
   lw    $a2, 4($t0)
.L7F006920:
  addu  $v1, $t9, $s0
  lw    $a1, 4($v1)
  move  $a0, $zero
  lw    $t6, ($a1)
  bltzl $t6, .L7F006970
   sll   $t9, $a0, 2
  beq   $a3, $t6, .L7F00696C
   sll   $v0, $zero, 2
  addiu $v0, $v0, 4
.L7F006944:
  addu  $t8, $a1, $v0
  lw    $t9, ($t8)
  addiu $a0, $a0, 1
  bltzl $t9, .L7F006970
   sll   $t9, $a0, 2
  lw    $t6, 4($v1)
  addu  $t7, $t6, $v0
  lw    $t8, ($t7)
  bnel  $a3, $t8, .L7F006944
   addiu $v0, $v0, 4
.L7F00696C:
  sll   $t9, $a0, 2
.L7F006970:
  addu  $t6, $a1, $t9
  lw    $t7, ($t6)
  beql  $a3, $t7, .L7F006988
   lw    $a2, 4($t0)
  li    $s6, 1
  lw    $a2, 4($t0)
.L7F006988:
  addiu $t0, $t0, 4
  bgez  $a2, .L7F006900
   nop   
  addiu $a3, $a3, 1
.L7F006998:
  sll   $t8, $a3, 4
  addu  $t5, $t8, $s0
  lw    $t9, ($t5)
  bgezl $t9, .L7F0068F0
   lw    $v0, 4($t5)
.L7F0069AC:
  lw    $t6, 0xd8($sp)
.L7F0069B0:
  beqz  $t6, .L7F006B04
   nop   
  lw    $t7, ($t6)
  move  $s1, $zero
  move  $s5, $t6
  beqz  $t7, .L7F006B04
   addiu $fp, $sp, 0xa0
  sw    $t6, 0x48($sp)
  li    $s7, 12
  lw    $t8, ($s5)
.L7F0069D8:
  move  $s3, $zero
  lw    $v0, ($t8)
  bltzl $v0, .L7F006AEC
   lw    $t6, 0x48($sp)
.L7F0069E8:
  bne   $v0, $s1, .L7F006A08
   nop   
  lw    $t9, 0x24($s4)
  li    $s6, 1
  beql  $t9, $zero, .L7F006AD4
   lw    $t9, ($s5)
  b     .L7F006AD4
   lw    $t9, ($s5)
.L7F006A08:
  multu $v0, $s7
  lw    $t6, 0xd8($sp)
  move  $a1, $zero
  mflo  $t7
  addu  $s2, $t7, $t6
  lw    $a2, ($s2)
  move  $a0, $s2
  lw    $t8, ($a2)
  bltzl $t8, .L7F006A70
   sll   $t7, $a1, 2
  lw    $t9, ($a2)
  sll   $v0, $zero, 2
  addu  $v1, $a2, $v0
  beql  $s1, $t9, .L7F006A70
   sll   $t7, $a1, 2
  lw    $t7, 4($v1)
.L7F006A48:
  addiu $a1, $a1, 1
  addiu $v0, $v0, 4
  bltz  $t7, .L7F006A6C
   addiu $v1, $v1, 4
  lw    $t6, ($a0)
  addu  $t8, $t6, $v0
  lw    $t9, ($t8)
  bnel  $s1, $t9, .L7F006A48
   lw    $t7, 4($v1)
.L7F006A6C:
  sll   $t7, $a1, 2
.L7F006A70:
  addu  $t6, $a2, $t7
  lw    $t8, ($t6)
  beql  $s1, $t8, .L7F006A9C
   lw    $t7, ($s4)
  lw    $t9, 0x24($s4)
  li    $s6, 1
  beql  $t9, $zero, .L7F006AD4
   lw    $t9, ($s5)
  b     .L7F006AD4
   lw    $t9, ($s5)
  lw    $t7, ($s4)
.L7F006A9C:
  move  $a0, $s5
  move  $a1, $s2
  beqz  $t7, .L7F006AD0
   move  $a2, $fp
  jal   sub_GAME_7F08F438
   addiu $a3, $sp, 0x9c
  lw    $t6, 0xa0($sp)
  lw    $t8, 0x9c($sp)
  beql  $t6, $zero, .L7F006AD0
   li    $s6, 1
  bnezl $t8, .L7F006AD4
   lw    $t9, ($s5)
  li    $s6, 1
.L7F006AD0:
  lw    $t9, ($s5)
.L7F006AD4:
  addiu $s3, $s3, 4
  addu  $t7, $t9, $s3
  lw    $v0, ($t7)
  bgez  $v0, .L7F0069E8
   nop   
  lw    $t6, 0x48($sp)
.L7F006AEC:
  addiu $s1, $s1, 1
  addiu $s5, $t6, 0xc
  sw    $s5, 0x48($sp)
  lw    $t9, ($s5)
  bnezl $t9, .L7F0069D8
   lw    $t8, ($s5)
.L7F006B04:
  beqz  $s0, .L7F006D4C
   lw    $t7, 0xd8($sp)
  beqz  $t7, .L7F006D4C
   nop   
  lw    $v1, ($t7)
  move  $t1, $zero
  move  $t3, $t7
  beqz  $v1, .L7F006BA0
   move  $s7, $s0
  move  $t5, $t7
.L7F006B2C:
  lw    $a0, 4($t3)
  move  $a3, $zero
  lw    $v1, ($a0)
  bltz  $v1, .L7F006B80
   sll   $t6, $v1, 4
.L7F006B40:
  addu  $a1, $t6, $s0
  lw    $a2, 8($a1)
  bgez  $a2, .L7F006B60
   nop   
  sw    $t1, 8($a1)
  lw    $a0, 4($t3)
  b     .L7F006B6C
   addu  $v0, $a0, $a3
.L7F006B60:
  beq   $t1, $a2, .L7F006B6C
   addu  $v0, $a0, $a3
  li    $s6, 1
.L7F006B6C:
  lw    $v1, 4($v0)
  addiu $a3, $a3, 4
  addiu $v0, $v0, 4
  bgezl $v1, .L7F006B40
   sll   $t6, $v1, 4
.L7F006B80:
  lw    $t8, 0xc($t5)
  addiu $t5, $t5, 0xc
  move  $t3, $t5
  bnez  $t8, .L7F006B2C
   addiu $t1, $t1, 1
  lw    $t3, 0xd8($sp)
  move  $t1, $zero
  lw    $v1, ($t3)
.L7F006BA0:
  lw    $t7, ($s7)
  move  $a2, $s7
  lw    $t5, 0xd8($sp)
  bltz  $t7, .L7F006BD8
   li    $a3, 1
  lw    $t6, 8($a2)
.L7F006BB8:
  addiu $t1, $t1, 1
  sll   $t8, $t1, 4
  bgez  $t6, .L7F006BCC
   addu  $a2, $t8, $s0
  li    $s6, 1
.L7F006BCC:
  lw    $t9, ($a2)
  bgezl $t9, .L7F006BB8
   lw    $t6, 8($a2)
.L7F006BD8:
  beqz  $v1, .L7F006D4C
   nop   
  lw    $a0, 4($t3)
.L7F006BE4:
  move  $v1, $zero
  move  $t0, $zero
  lw    $a1, ($a0)
  move  $t4, $zero
  move  $t1, $zero
  bltz  $a1, .L7F006C44
   move  $v0, $a1
.L7F006C00:
  bnez  $t1, .L7F006C18
   sll   $t8, $v0, 4
  sll   $t7, $v0, 4
  addu  $t6, $t7, $s0
  b     .L7F006C20
   sw    $a3, 0xc($t6)
.L7F006C18:
  addu  $t9, $t8, $s0
  sw    $zero, 0xc($t9)
.L7F006C20:
  lw    $a0, 4($t3)
  addiu $t1, $t1, 4
  addu  $t7, $a0, $t1
  lw    $v0, ($t7)
  bgez  $v0, .L7F006C00
   nop   
  lw    $a1, ($a0)
  move  $v1, $zero
  move  $v0, $a1
.L7F006C44:
  bltz  $v0, .L7F006CC8
   move  $t1, $zero
  sll   $t6, $v0, 4
.L7F006C50:
  addu  $a2, $t6, $s0
  lw    $t8, 0xc($a2)
  addiu $t1, $t1, 4
  bnel  $a3, $t8, .L7F006CB0
   addu  $t8, $a0, $t1
  lw    $a1, 4($a2)
  move  $v1, $zero
  lw    $v0, ($a1)
  bltz  $v0, .L7F006CAC
   sll   $t9, $v0, 4
.L7F006C78:
  addu  $a0, $t9, $s0
  lw    $t7, 0xc($a0)
  addiu $v1, $v1, 4
  beql  $a3, $t7, .L7F006C9C
   addu  $t6, $a1, $v1
  sw    $a3, 0xc($a0)
  lw    $a1, 4($a2)
  move  $t0, $a3
  addu  $t6, $a1, $v1
.L7F006C9C:
  lw    $v0, ($t6)
  bgezl $v0, .L7F006C78
   sll   $t9, $v0, 4
  lw    $a0, 4($t3)
.L7F006CAC:
  addu  $t8, $a0, $t1
.L7F006CB0:
  lw    $v0, ($t8)
  bgezl $v0, .L7F006C50
   sll   $t6, $v0, 4
  lw    $a1, ($a0)
  move  $v1, $zero
  move  $v0, $a1
.L7F006CC8:
  bltz  $v0, .L7F006CFC
   sll   $t9, $v0, 4
.L7F006CD0:
  addu  $t7, $t9, $s0
  lw    $t6, 0xc($t7)
  addiu $v1, $v1, 1
  sll   $t8, $v1, 2
  beq   $a3, $t6, .L7F006CF0
   addu  $t9, $a0, $t8
  b     .L7F006CFC
   move  $t4, $a3
.L7F006CF0:
  lw    $v0, ($t9)
  bgezl $v0, .L7F006CD0
   sll   $t9, $v0, 4
.L7F006CFC:
  beqz  $t0, .L7F006D0C
   move  $v1, $zero
  bnez  $t4, .L7F006D2C
   move  $v0, $a1
.L7F006D0C:
  beql  $t4, $zero, .L7F006D3C
   lw    $t6, 0xc($t5)
  lw    $t7, 0x24($s4)
  li    $s6, 1
  beql  $t7, $zero, .L7F006D3C
   lw    $t6, 0xc($t5)
  b     .L7F006D3C
   lw    $t6, 0xc($t5)
.L7F006D2C:
  move  $t0, $zero
  b     .L7F006C44
   move  $t4, $zero
  lw    $t6, 0xc($t5)
.L7F006D3C:
  addiu $t5, $t5, 0xc
  move  $t3, $t5
  bnezl $t6, .L7F006BE4
   lw    $a0, 4($t3)
.L7F006D4C:
  beqz  $s6, .L7F006D5C
   lw    $s0, 0x18($sp)
.L7F006D54:
  b     .L7F006D54
   nop   
.L7F006D5C:
  lw    $ra, 0x3c($sp)
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
");
