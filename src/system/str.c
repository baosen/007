asm(R"
glabel textpointer_load_parse_something
  lbu   $v0, ($a1)
  addiu $v1, $a0, 1
  addiu $a1, $a1, 1
  beqz  $v0, .L7000A798
   sb    $v0, ($a0)
.L7000A784:
  lbu   $v0, ($a1)
  addiu $v1, $v1, 1
  addiu $a1, $a1, 1
  bnez  $v0, .L7000A784
   sb    $v0, -1($v1)
.L7000A798:
  jr    $ra
   move  $v0, $a0
");

asm(R"
glabel something_with_strings
  lbu   $v0, ($a1)
  addiu $v1, $a0, 1
  addiu $a1, $a1, 1
  beqz  $v0, .L7000A7D4
   sb    $v0, ($a0)
.L7000A7B4:
  addiu $a2, $a2, -1
  beql  $a2, $zero, .L7000A7D8
   move  $v0, $a2
  lbu   $v0, ($a1)
  addiu $v1, $v1, 1
  addiu $a1, $a1, 1
  bnez  $v0, .L7000A7B4
   sb    $v0, -1($v1)
.L7000A7D4:
  move  $v0, $a2
.L7000A7D8:
  beqz  $a2, .L7000A7F4
   addiu $a2, $a2, -1
.L7000A7E0:
  move  $v0, $a2
  sb    $zero, ($v1)
  addiu $v1, $v1, 1
  bnez  $a2, .L7000A7E0
   addiu $a2, $a2, -1
.L7000A7F4:
  jr    $ra
   move  $v0, $a0
");

asm(R"
glabel string_append_from_obseg_textbank
  lbu   $t6, ($a0)
  move  $v0, $a0
  beql  $t6, $zero, .L7000A820
   lbu   $v1, ($a1)
  lbu   $t7, 1($v0)
.L7000A810:
  addiu $v0, $v0, 1
  bnezl $t7, .L7000A810
   lbu   $t7, 1($v0)
  lbu   $v1, ($a1)
.L7000A820:
  addiu $v0, $v0, 1
  addiu $a1, $a1, 1
  beqz  $v1, .L7000A844
   sb    $v1, -1($v0)
.L7000A830:
  lbu   $v1, ($a1)
  addiu $v0, $v0, 1
  addiu $a1, $a1, 1
  bnez  $v1, .L7000A830
   sb    $v1, -1($v0)
.L7000A844:
  jr    $ra
   move  $v0, $a0
");

int something_with_strings_0(unsigned char *a0, unsigned char *a1) {
  if (*a0 != *a1) {
    if (*a0 < *a1) {
      return -1;
    }
    return 1;
  }
  if (*a0 == '\0') {
    return 0;
  }
  return something_with_strings_0(a0 + 1, a1 + 1);
}

asm(R"
glabel string_related
.L7000A898:
  bnezl $a2, .L7000A8AC
   lbu   $v0, ($a0)
  jr    $ra
   move  $v0, $zero

  lbu   $v0, ($a0)
.L7000A8AC:
  lbu   $v1, ($a1)
  addiu $a2, $a2, -1
  addiu $a0, $a0, 1
  beq   $v0, $v1, .L7000A8D8
   slt   $at, $v0, $v1
  beqz  $at, .L7000A8D0
   nop   
  jr    $ra
   li    $v0, -1

.L7000A8D0:
  jr    $ra
   li    $v0, 1

.L7000A8D8:
  bnez  $v0, .L7000A8E8
   nop   
  jr    $ra
   move  $v0, $zero

.L7000A8E8:
  b     .L7000A898
   addiu $a1, $a1, 1
  jr    $ra
   nop   
");

asm(R"
glabel strtol_related
  andi  $t6, $a0, 0xff
  sw    $a0, ($sp)
  slti  $at, $t6, 0x61
  bnez  $at, .L7000A924
   move  $a0, $t6
  slti  $at, $t6, 0x7b
  beqz  $at, .L7000A924
   addiu $v0, $t6, -0x20
  andi  $t7, $v0, 0xff
  jr    $ra
   move  $v0, $t7

.L7000A924:
  move  $v0, $a0
  jr    $ra
   nop   
");

asm(R"
glabel strtol_related_0
  andi  $t6, $a0, 0xff
  slti  $v0, $t6, 0x30
  xori  $v0, $v0, 1
  beqz  $v0, .L7000A948
   sw    $a0, ($sp)
  slti  $v0, $t6, 0x3a
.L7000A948:
  jr    $ra
   nop   
");

asm(R"
glabel strtol_related_1
  andi  $t6, $a0, 0xff
  slti  $v0, $t6, 0x61
  sw    $a0, ($sp)
  bnez  $v0, .L7000A970
   move  $v1, $t6
  slti  $v0, $t6, 0x7b
  bnez  $v0, .L7000A984
   nop   
.L7000A970:
  slti  $v0, $v1, 0x41
  xori  $v0, $v0, 1
  beqz  $v0, .L7000A984
   nop   
  slti  $v0, $v1, 0x5b
.L7000A984:
  jr    $ra
   nop   
");

asm(R"
glabel strtol_related_2
  andi  $t6, $a0, 0xff
  xori  $v0, $t6, 0x20
  sltiu $v0, $v0, 1
  bnez  $v0, .L7000A9D8
   sw    $a0, ($sp)
  xori  $v0, $t6, 9
  sltiu $v0, $v0, 1
  bnez  $v0, .L7000A9D8
   nop   
  xori  $v0, $t6, 0xa
  sltiu $v0, $v0, 1
  bnez  $v0, .L7000A9D8
   nop   
  xori  $v0, $t6, 0xc
  sltiu $v0, $v0, 1
  bnez  $v0, .L7000A9D8
   nop   
  xori  $v0, $t6, 0xb
  sltiu $v0, $v0, 1
.L7000A9D8:
  jr    $ra
   nop   
");

asm(R"
glabel strtol
  addiu $sp, $sp, -0x60
  sw    $s3, 0x24($sp)
  move  $s3, $a2
  sw    $ra, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a1, 0x64($sp)
  bltz  $a2, .L7000AA20
   move  $a3, $a0
  li    $at, 1
  beq   $a2, $at, .L7000AA20
   slti  $at, $a2, 0x25
  bnezl $at, .L7000AA28
   lbu   $a0, ($a3)
.L7000AA20:
  li    $s3, 10
  lbu   $a0, ($a3)
.L7000AA28:
  move  $s2, $a3
  jal   strtol_related_2
   sw    $a3, 0x60($sp)
  beql  $v0, $zero, .L7000AA54
   lbu   $v0, ($s2)
  addiu $s2, $s2, 1
.L7000AA40:
  jal   strtol_related_2
   lbu   $a0, ($s2)
  bnezl $v0, .L7000AA40
   addiu $s2, $s2, 1
  lbu   $v0, ($s2)
.L7000AA54:
  li    $at, 45
  beql  $v0, $zero, .L7000AC30
   lw    $v0, 0x64($sp)
  bne   $v0, $at, .L7000AA74
   li    $t6, 1
  sw    $t6, 0x5c($sp)
  b     .L7000AA90
   addiu $s2, $s2, 1
.L7000AA74:
  li    $at, 43
  bnel  $v0, $at, .L7000AA90
   sw    $zero, 0x5c($sp)
  sw    $zero, 0x5c($sp)
  b     .L7000AA90
   addiu $s2, $s2, 1
  sw    $zero, 0x5c($sp)
.L7000AA90:
  li    $at, 16
  bne   $s3, $at, .L7000AAC4
   nop   
  lbu   $t7, ($s2)
  li    $at, 48
  bne   $t7, $at, .L7000AAC4
   nop   
  jal   strtol_related
   lbu   $a0, 1($s2)
  li    $at, 88
  bne   $v0, $at, .L7000AAC4
   nop   
  addiu $s2, $s2, 2
.L7000AAC4:
  bnez  $s3, .L7000AB00
   lbu   $v0, ($s2)
  li    $at, 48
  bne   $v0, $at, .L7000AB00
   li    $s3, 10
  jal   strtol_related
   lbu   $a0, 1($s2)
  li    $at, 88
  bne   $v0, $at, .L7000AAF8
   li    $s3, 8
  addiu $s2, $s2, 2
  b     .L7000AAF8
   li    $s3, 16
.L7000AAF8:
  b     .L7000AB00
   lbu   $v0, ($s2)
.L7000AB00:
  andi  $s0, $v0, 0xff
  sw    $s2, 0x44($sp)
  sw    $zero, 0x40($sp)
  move  $s1, $zero
  beqz  $s0, .L7000ABE0
   move  $v1, $s0
  li    $s4, -1
.L7000AB1C:
  andi  $a0, $s0, 0xff
  jal   strtol_related_0
   sw    $v1, 0x34($sp)
  beqz  $v0, .L7000AB40
   lw    $v1, 0x34($sp)
  addiu $s0, $v1, -0x30
  andi  $t8, $s0, 0xff
  b     .L7000AB64
   move  $s0, $t8
.L7000AB40:
  jal   strtol_related_1
   andi  $a0, $s0, 0xff
  beql  $v0, $zero, .L7000ABE4
   lw    $t2, 0x44($sp)
  jal   strtol_related
   andi  $a0, $s0, 0xff
  addiu $s0, $v0, -0x37
  andi  $t9, $s0, 0xff
  move  $s0, $t9
.L7000AB64:
  slt   $at, $s0, $s3
  beqz  $at, .L7000ABE0
   li    $t1, 1
  divu  $zero, $s4, $s3
  mflo  $v0
  sltu  $at, $v0, $s1
  bnez  $s3, .L7000AB88
   nop   
  break 7
.L7000AB88:
  bnez  $at, .L7000ABB8
   nop   
  bne   $s1, $v0, .L7000ABC0
   nop   
  divu  $zero, $s4, $s3
  mfhi  $t0
  sltu  $at, $t0, $s0
  bnez  $s3, .L7000ABB0
   nop   
  break 7
.L7000ABB0:
  beqz  $at, .L7000ABC0
   nop   
.L7000ABB8:
  b     .L7000ABD0
   sw    $t1, 0x40($sp)
.L7000ABC0:
  multu $s1, $s3
  mflo  $s1
  addu  $s1, $s1, $s0
  nop   
.L7000ABD0:
  lbu   $s0, 1($s2)
  addiu $s2, $s2, 1
  bnez  $s0, .L7000AB1C
   move  $v1, $s0
.L7000ABE0:
  lw    $t2, 0x44($sp)
.L7000ABE4:
  lw    $v0, 0x64($sp)
  beql  $s2, $t2, .L7000AC30
   lw    $v0, 0x64($sp)
  beql  $v0, $zero, .L7000AC00
   lw    $t3, 0x40($sp)
  sw    $s2, ($v0)
  lw    $t3, 0x40($sp)
.L7000AC00:
  lw    $t4, 0x5c($sp)
  beqz  $t3, .L7000AC14
   nop   
  b     .L7000AC44
   li    $v0, -1
.L7000AC14:
  beqz  $t4, .L7000AC24
   move  $v1, $s1
  b     .L7000AC44
   negu  $v0, $s1
.L7000AC24:
  b     .L7000AC44
   move  $v0, $v1
  lw    $v0, 0x64($sp)
.L7000AC30:
  lw    $t5, 0x60($sp)
  beql  $v0, $zero, .L7000AC44
   move  $v0, $zero
  sw    $t5, ($v0)
  move  $v0, $zero
.L7000AC44:
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  lw    $s3, 0x24($sp)
  lw    $s4, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x60
");
