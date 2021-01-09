extern image_entries;

asm(R"
glabel image_entries_load
  lui   $a0, %hi(image_entries)
  addiu $v0, $a0, %lo(image_entries)
  lw    $t6, ($v0)
  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
  li    $a3, 65535
  and   $t7, $t6, $at
  beq   $a3, $t7, .L7F000C40
   move  $v1, $zero
  lui   $t8, %hi(image_entries) 
  addiu $t8, %lo(image_entries) # addiu $t8, $t8, -0x6d00
  lw    $a1, ($t8)
  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
  and   $a2, $a1, $at
.L7F000C0C:
  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
  and   $t9, $v1, $at
  xor   $t0, $t9, $a1
  sll   $t1, $t0, 8
  srl   $t2, $t1, 8
  xor   $t3, $t2, $a1
  lw    $a1, 8($v0)
  addu  $v1, $v1, $a2
  sw    $t3, ($v0)
  and   $a2, $a1, $at
  bne   $a3, $a2, .L7F000C0C
   addiu $v0, $v0, 8
.L7F000C40:
  lw    $a1, ($v0)
  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
  and   $t4, $v1, $at
  xor   $t5, $t4, $a1
  sll   $t6, $t5, 8
  srl   $t7, $t6, 8
  xor   $t8, $t7, $a1
  jr    $ra
   sw    $t8, ($v0)
");
