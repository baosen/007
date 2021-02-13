#include <types.h>

int sub_GAME_7F01D6C0(void) { return save_7000C6FC(); }

asm(R"
glabel sub_GAME_7F01D6E0
  addiu $sp, $sp, -0x60
  lui   $t6, %hi(D_8002C520) 
  addiu $v0, $sp, 0
  addiu $t6, %lo(D_8002C520) # addiu $t6, $t6, -0x3ae0
  addiu $t9, $t6, 0x60
  move  $t0, $v0
.L7F01D6F8:
  lw    $at, ($t6)
  addiu $t6, $t6, 0xc
  addiu $t0, $t0, 0xc
  sw    $at, -0xc($t0)
  lw    $at, -8($t6)
  sw    $at, -8($t0)
  lw    $at, -4($t6)
  bne   $t6, $t9, .L7F01D6F8
   sw    $at, -4($t0)
  lui   $t1, %hi(save6) 
  addiu $t1, %lo(save6) # addiu $t1, $t1, -0x6500
  move  $t5, $v0
  addiu $t4, $v0, 0x60
.L7F01D72C:
  lw    $at, ($t5)
  addiu $t5, $t5, 0xc
  addiu $t1, $t1, 0xc
  sw    $at, -0xc($t1)
  lw    $at, -8($t5)
  sw    $at, -8($t1)
  lw    $at, -4($t5)
  bne   $t5, $t4, .L7F01D72C
   sw    $at, -4($t1)
  jr    $ra
   addiu $sp, $sp, 0x60
");

asm(R"
glabel sub_GAME_7F01D758
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F01D6C0
   sw    $a0, 0x18($sp)
  beqz  $v0, .L7F01D790
   lw    $a3, 0x18($sp)
  addiu $a0, $a3, 8
  addiu $a1, $a3, 0x20
  jal   sub_GAME_7F09B600
   move  $a2, $a3
  lw    $a1, 0x18($sp)
  move  $a0, $zero
  jal   save_7000C808
   li    $a2, 32
.L7F01D790:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F01D7A0
  lui   $t6, %hi(save1) 
  addiu $t6, %lo(save1) # addiu $t6, $t6, -0x66e0
  addiu $sp, $sp, -0x18
  sltu  $at, $a0, $t6
  bnez  $at, .L7F01D830
   sw    $ra, 0x14($sp)
  lui   $t7, %hi(save6) 
  addiu $t7, %lo(save6) # addiu $t7, $t7, -0x6500
  sltu  $at, $a0, $t7
  beql  $at, $zero, .L7F01D834
   lw    $ra, 0x14($sp)
  jal   sub_GAME_7F01D6C0
   sw    $a0, 0x18($sp)
  beqz  $v0, .L7F01D830
   lw    $a3, 0x18($sp)
  addiu $a0, $a3, 8
  addiu $a1, $a3, 0x60
  move  $a2, $a3
  jal   sub_GAME_7F09B600
   sw    $a3, 0x18($sp)
  lw    $a1, 0x18($sp)
  lui   $t8, %hi(save1) 
  addiu $t8, %lo(save1) # addiu $t8, $t8, -0x66e0
  li    $at, 96
  subu  $a0, $a1, $t8
  div   $zero, $a0, $at
  mflo  $t9
  sll   $t0, $t9, 2
  subu  $t0, $t0, $t9
  sll   $t0, $t0, 5
  srl   $t1, $t0, 3
  addiu $a0, $t1, 4
  andi  $t2, $a0, 0xff
  move  $a0, $t2
  jal   save_7000C808
   li    $a2, 96
.L7F01D830:
  lw    $ra, 0x14($sp)
.L7F01D834:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F01D840
  addiu $sp, $sp, -0x78
  lui   $t6, %hi(D_8002C580) 
  addiu $v0, $sp, 0x18
  addiu $t6, %lo(D_8002C580) # addiu $t6, $t6, -0x3a80
  sw    $ra, 0x14($sp)
  addiu $t9, $t6, 0x60
  move  $t0, $v0
.L7F01D85C:
  lw    $at, ($t6)
  addiu $t6, $t6, 0xc
  addiu $t0, $t0, 0xc
  sw    $at, -0xc($t0)
  lw    $at, -8($t6)
  sw    $at, -8($t0)
  lw    $at, -4($t6)
  bne   $t6, $t9, .L7F01D85C
   sw    $at, -4($t0)
  move  $t4, $v0
  move  $t5, $a0
  addiu $t3, $v0, 0x60
.L7F01D88C:
  lw    $at, ($t4)
  addiu $t4, $t4, 0xc
  addiu $t5, $t5, 0xc
  sw    $at, -0xc($t5)
  lw    $at, -8($t4)
  sw    $at, -8($t5)
  lw    $at, -4($t4)
  bne   $t4, $t3, .L7F01D88C
   sw    $at, -4($t5)
  jal   sub_GAME_7F01D7A0
   nop   
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x78
  jr    $ra
   nop   
");

int get_foldernum_of_eeprom(unsigned char *a0) { return a0[8] & 7; }

asm(R"
glabel set_eeprom_to_folder_num
  lbu   $t6, 8($a0)
  andi  $t9, $a1, 7
  andi  $t8, $t6, 0xfff8
  sb    $t8, 8($a0)
  or    $t0, $t8, $t9
  jr    $ra
   sb    $t0, 8($a0)
");

int set_eeprom_flag_0x18(unsigned char arg0[]) { return (arg0[8] & 0x18) >> 3; }

asm(R"
glabel reset_eeprom_flag_0x18
  lbu   $t6, 8($a0)
  sll   $t9, $a1, 3
  andi  $t0, $t9, 0x18
  andi  $t8, $t6, 0xffe7
  sb    $t8, 8($a0)
  or    $t1, $t8, $t0
  jr    $ra
   sb    $t1, 8($a0)
");

int get_selected_bond(unsigned char arg0[]) { return (arg0[8] & 0x60) >> 5; }

asm(R"
glabel set_selected_bond
  lbu   $t6, 8($a0)
  sll   $t9, $a1, 5
  andi  $t0, $t9, 0x60
  andi  $t8, $t6, 0xff9f
  sb    $t8, 8($a0)
  or    $t1, $t8, $t0
  jr    $ra
   sb    $t1, 8($a0)
");

int check_if_eeprom_flag_set_0x80(unsigned char arg0[]) {
  return (arg0[8] & 0x80) != 0;
}

asm(R"
glabel toggle_eeprom_flag_set_0x80
  beql  $a1, $zero, .L7F01D980
   lbu   $t8, 8($a0)
  lbu   $t6, 8($a0)
  ori   $t7, $t6, 0x80
  jr    $ra
   sb    $t7, 8($a0)

  lbu   $t8, 8($a0)
.L7F01D980:
  andi  $t9, $t8, 0xff7f
  sb    $t9, 8($a0)
  jr    $ra
   nop   
");

asm(R"
glabel get_eeprom_stage_complete_time_for_difficulty
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  bltz  $a1, .L7F01DAD0
   move  $a3, $a0
  slti  $at, $a1, 0x14
  beql  $at, $zero, .L7F01DAD4
   move  $v0, $zero
  bltz  $a2, .L7F01DAD0
   slti  $at, $a2, 4
  beqz  $at, .L7F01DAD0
   li    $v1, 3
  bne   $a2, $v1, .L7F01D9EC
   li    $t0, 7
  jal   get_foldernum_of_eeprom
   nop   
  jal   check_for_007_mode_unlocked
   move  $a0, $v0
  beqz  $v0, .L7F01D9E4
   nop   
  b     .L7F01DAD4
   li    $v0, 1023
.L7F01D9E4:
  b     .L7F01DAD4
   move  $v0, $zero
.L7F01D9EC:
  sll   $t6, $a2, 2
  addu  $t6, $t6, $a2
  sll   $t6, $t6, 2
  addu  $a0, $t6, $a1
  sll   $t7, $a0, 2
  addu  $t7, $t7, $a0
  sll   $t7, $t7, 1
  andi  $t8, $t7, 7
  subu  $v0, $t0, $t8
  li    $at, 1
  beq   $v0, $at, .L7F01DAA8
   move  $a0, $t7
  beq   $v0, $v1, .L7F01DA84
   sra   $t3, $a0, 3
  li    $at, 5
  beql  $v0, $at, .L7F01DA60
   sra   $t7, $a0, 3
  bne   $v0, $t0, .L7F01DAC8
   move  $v1, $zero
  sra   $t9, $t7, 3
  addu  $v0, $a3, $t9
  lbu   $t1, 0x13($v0)
  lbu   $t5, 0x12($v0)
  andi  $t2, $t1, 0xc0
  sra   $t3, $t2, 6
  sll   $t6, $t5, 2
  b     .L7F01DAD4
   or    $v0, $t3, $t6
  sra   $t7, $a0, 3
.L7F01DA60:
  addu  $v0, $a3, $t7
  lbu   $t8, 0x13($v0)
  lbu   $t2, 0x12($v0)
  andi  $t9, $t8, 0xf0
  andi  $t4, $t2, 0x3f
  sll   $t5, $t4, 4
  sra   $t1, $t9, 4
  b     .L7F01DAD4
   or    $v0, $t1, $t5
.L7F01DA84:
  addu  $v0, $a3, $t3
  lbu   $t6, 0x13($v0)
  lbu   $t9, 0x12($v0)
  andi  $t7, $t6, 0xfc
  andi  $t2, $t9, 0xf
  sll   $t4, $t2, 6
  sra   $t8, $t7, 2
  b     .L7F01DAD4
   or    $v0, $t8, $t4
.L7F01DAA8:
  sra   $t1, $a0, 3
  addu  $v0, $a3, $t1
  lbu   $t6, 0x12($v0)
  lbu   $t3, 0x13($v0)
  andi  $t7, $t6, 3
  sll   $t9, $t7, 8
  b     .L7F01DAD4
   or    $v0, $t3, $t9
.L7F01DAC8:
  b     .L7F01DAD4
   move  $v0, $v1
.L7F01DAD0:
  move  $v0, $zero
.L7F01DAD4:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F01DAE4
  bltz  $a1, .L7F01DC58
   slti  $at, $a1, 0x14
  beqz  $at, .L7F01DC58
   nop   
  bltz  $a2, .L7F01DC58
   slti  $at, $a2, 3
  beqz  $at, .L7F01DC58
   li    $t0, 7
  bnez  $a3, .L7F01DB14
   sll   $t6, $a2, 2
  b     .L7F01DB24
   li    $a3, 79
.L7F01DB14:
  slti  $at, $a3, 0x400
  bnezl $at, .L7F01DB28
   addu  $t6, $t6, $a2
  li    $a3, 1023
.L7F01DB24:
  addu  $t6, $t6, $a2
.L7F01DB28:
  sll   $t6, $t6, 2
  addu  $v0, $t6, $a1
  sll   $t7, $v0, 2
  addu  $t7, $t7, $v0
  sll   $t7, $t7, 1
  andi  $t8, $t7, 7
  subu  $v1, $t0, $t8
  li    $at, 1
  beq   $v1, $at, .L7F01DC20
   move  $v0, $t7
  li    $at, 3
  beq   $v1, $at, .L7F01DBE4
   sra   $t8, $v0, 3
  li    $at, 5
  beq   $v1, $at, .L7F01DBA8
   sra   $t4, $v0, 3
  bne   $v1, $t0, .L7F01DC58
   sra   $t9, $t7, 3
  addu  $v1, $a0, $t9
  lbu   $t1, 0x12($v1)
  lbu   $t3, 0x13($v1)
  sra   $t7, $a3, 2
  andi  $t5, $t1, 0xff00
  andi  $t9, $t3, 0xff3f
  sll   $t2, $a3, 6
  sb    $t5, 0x12($v1)
  sb    $t9, 0x13($v1)
  or    $t8, $t5, $t7
  or    $t3, $t9, $t2
  sb    $t8, 0x12($v1)
  jr    $ra
   sb    $t3, 0x13($v1)

.L7F01DBA8:
  addu  $v1, $a0, $t4
  lbu   $t6, 0x12($v1)
  lbu   $t7, 0x13($v1)
  sra   $t9, $a3, 4
  andi  $t1, $t6, 0xffc0
  andi  $t4, $t7, 0xff0f
  andi  $t2, $t9, 0x3f
  sll   $t5, $a3, 4
  sb    $t1, 0x12($v1)
  sb    $t4, 0x13($v1)
  or    $t3, $t1, $t2
  or    $t7, $t4, $t5
  sb    $t3, 0x12($v1)
  jr    $ra
   sb    $t7, 0x13($v1)

.L7F01DBE4:
  addu  $v1, $a0, $t8
  lbu   $t9, 0x12($v1)
  lbu   $t2, 0x13($v1)
  sra   $t4, $a3, 6
  andi  $t6, $t9, 0xfff0
  andi  $t8, $t2, 0xff03
  andi  $t5, $t4, 0xf
  sll   $t1, $a3, 2
  sb    $t6, 0x12($v1)
  sb    $t8, 0x13($v1)
  or    $t7, $t6, $t5
  or    $t2, $t8, $t1
  sb    $t7, 0x12($v1)
  jr    $ra
   sb    $t2, 0x13($v1)

.L7F01DC20:
  sra   $t3, $v0, 3
  addu  $v1, $a0, $t3
  lbu   $t4, 0x12($v1)
  lbu   $t5, 0x13($v1)
  sra   $t8, $a3, 8
  andi  $t9, $t4, 0xfffc
  andi  $t3, $t5, 0xff00
  andi  $t1, $t8, 3
  sb    $t9, 0x12($v1)
  sb    $t3, 0x13($v1)
  or    $t2, $t9, $t1
  or    $t6, $t3, $a3
  sb    $t2, 0x12($v1)
  sb    $t6, 0x13($v1)
.L7F01DC58:
  jr    $ra
   nop   
");

asm(R"
glabel get_eeprom_stage_completed_for_difficulty
  addiu $sp, $sp, -0x18
  bltz  $a1, .L7F01DC9C
   sw    $ra, 0x14($sp)
  slti  $at, $a1, 0x14
  beql  $at, $zero, .L7F01DCA0
   move  $v0, $zero
  bltz  $a2, .L7F01DC9C
   slti  $at, $a2, 4
  beql  $at, $zero, .L7F01DCA0
   move  $v0, $zero
  jal   get_eeprom_stage_complete_time_for_difficulty
   nop   
  sltu  $t6, $zero, $v0
  b     .L7F01DCA0
   move  $v0, $t6
.L7F01DC9C:
  move  $v0, $zero
.L7F01DCA0:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F01DCB0
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  bltz  $a1, .L7F01DD10
   sw    $a0, 0x18($sp)
  slti  $at, $a1, 0x14
  beql  $at, $zero, .L7F01DD14
   lw    $ra, 0x14($sp)
  bltz  $a2, .L7F01DD10
   slti  $at, $a2, 4
  beql  $at, $zero, .L7F01DD14
   lw    $ra, 0x14($sp)
  sw    $a1, 0x1c($sp)
  sw    $a2, 0x20($sp)
  jal   get_eeprom_stage_complete_time_for_difficulty
   sw    $a3, 0x24($sp)
  lw    $a1, 0x1c($sp)
  lw    $a2, 0x20($sp)
  beqz  $v0, .L7F01DD08
   lw    $a3, 0x24($sp)
  slt   $at, $a3, $v0
  beql  $at, $zero, .L7F01DD14
   lw    $ra, 0x14($sp)
.L7F01DD08:
  jal   sub_GAME_7F01DAE4
   lw    $a0, 0x18($sp)
.L7F01DD10:
  lw    $ra, 0x14($sp)
.L7F01DD14:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel check_if_cheat_unlocked
  bltz  $a1, .L7F01DD68
   slti  $at, $a1, 0x14
  beqz  $at, .L7F01DD68
   li    $t3, 1
  lbu   $a2, 0x10($a0)
  lbu   $t6, 0xe($a0)
  lbu   $t1, 0xf($a0)
  sll   $t7, $a2, 0x18
  sll   $t9, $a2, 0x10
  or    $t8, $t6, $t7
  or    $t0, $t8, $t9
  sll   $t2, $t1, 8
  or    $v1, $t0, $t2
  sllv  $t4, $t3, $a1
  and   $v0, $t4, $v1
  sltu  $t5, $zero, $v0
  jr    $ra
   move  $v0, $t5

.L7F01DD68:
  move  $v0, $zero
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F01DD74
  bltz  $a1, .L7F01DDBC
   move  $a2, $a0
  slti  $at, $a1, 0x14
  beqz  $at, .L7F01DDBC
   li    $t6, 1
  sllv  $v0, $t6, $a1
  sltiu $at, $v0, 0x100
  bnez  $at, .L7F01DDAC
   move  $a0, $zero
.L7F01DD98:
  srl   $t7, $v0, 8
  sltiu $at, $t7, 0x100
  addiu $a0, $a0, 1
  beqz  $at, .L7F01DD98
   move  $v0, $t7
.L7F01DDAC:
  addu  $v1, $a2, $a0
  lbu   $t8, 0xe($v1)
  or    $t0, $t8, $v0
  sb    $t0, 0xe($v1)
.L7F01DDBC:
  jr    $ra
   nop   
");

asm(R"
glabel get_save_folder_ptr
  addiu $sp, $sp, -0x28
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $s2, 0x20($sp)
  lui   $s0, %hi(save1)
  lui   $s1, %hi(save6)
  move  $s2, $a0
  sw    $ra, 0x24($sp)
  addiu $s1, %lo(save6) # addiu $s1, $s1, -0x6500
  addiu $s0, %lo(save1) # addiu $s0, $s0, -0x66e0
.L7F01DDEC:
  jal   check_if_eeprom_flag_set_0x80
   move  $a0, $s0
  bnezl $v0, .L7F01DE18
   addiu $s0, $s0, 0x60
  jal   get_foldernum_of_eeprom
   move  $a0, $s0
  bnel  $v0, $s2, .L7F01DE18
   addiu $s0, $s0, 0x60
  b     .L7F01DE38
   move  $v0, $s0
  addiu $s0, $s0, 0x60
.L7F01DE18:
  bne   $s0, $s1, .L7F01DDEC
   nop   
  li    $at, 100
  bne   $s2, $at, .L7F01DE38
   move  $v0, $zero
  lui   $v0, %hi(save6)
  b     .L7F01DE38
   addiu $v0, %lo(save6) # addiu $v0, $v0, -0x6500
.L7F01DE38:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
glabel sub_GAME_7F01DE50
  addiu $sp, $sp, -0x28
  sw    $s1, 0x1c($sp)
  sw    $s2, 0x20($sp)
  sw    $s0, 0x18($sp)
  lui   $s1, %hi(save1)
  sw    $ra, 0x24($sp)
  addiu $s1, %lo(save1) # addiu $s1, $s1, -0x66e0
  move  $s0, $zero
  li    $s2, 5
.L7F01DE74:
  jal   check_if_eeprom_flag_set_0x80
   move  $a0, $s1
  beql  $v0, $zero, .L7F01DE90
   addiu $s0, $s0, 1
  b     .L7F01DE9C
   move  $v0, $s0
  addiu $s0, $s0, 1
.L7F01DE90:
  bne   $s0, $s2, .L7F01DE74
   addiu $s1, $s1, 0x60
  li    $v0, -1
.L7F01DE9C:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
glabel sub_GAME_7F01DEB4
  addiu $sp, $sp, -0x88
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  jal   sub_GAME_7F01DE50
   sw    $a0, 0x88($sp)
  bltz  $v0, .L7F01DF7C
   move  $v1, $v0
  lui   $t6, %hi(D_8002C5E0) 
  addiu $v0, $sp, 0x24
  addiu $t6, %lo(D_8002C5E0) # addiu $t6, $t6, -0x3a20
  addiu $t8, $t6, 0x60
  move  $t9, $v0
.L7F01DEE4:
  lw    $at, ($t6)
  addiu $t6, $t6, 0xc
  addiu $t9, $t9, 0xc
  sw    $at, -0xc($t9)
  lw    $at, -8($t6)
  sw    $at, -8($t9)
  lw    $at, -4($t6)
  bne   $t6, $t8, .L7F01DEE4
   sw    $at, -4($t9)
  sll   $t0, $v1, 2
  subu  $t0, $t0, $v1
  lui   $t1, %hi(save1) 
  addiu $t1, %lo(save1) # addiu $t1, $t1, -0x66e0
  sll   $t0, $t0, 5
  addu  $s0, $t0, $t1
  move  $t5, $s0
  move  $t4, $v0
  addiu $t3, $v0, 0x60
.L7F01DF2C:
  lw    $at, ($t4)
  addiu $t4, $t4, 0xc
  addiu $t5, $t5, 0xc
  sw    $at, -0xc($t5)
  lw    $at, -8($t4)
  sw    $at, -8($t5)
  lw    $at, -4($t4)
  bne   $t4, $t3, .L7F01DF2C
   sw    $at, -4($t5)
  move  $a0, $s0
  jal   set_eeprom_to_folder_num
   lw    $a1, 0x88($sp)
  move  $a0, $s0
  jal   toggle_eeprom_flag_set_0x80
   move  $a1, $zero
  move  $a0, $s0
  jal   set_selected_bond
   lw    $a1, 0x88($sp)
  jal   sub_GAME_7F01D7A0
   move  $a0, $s0
.L7F01DF7C:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x88
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F01DF90
  addiu $sp, $sp, -0xb8
  sw    $ra, 0x3c($sp)
  sw    $fp, 0x38($sp)
  sw    $s7, 0x34($sp)
  sw    $s6, 0x30($sp)
  sw    $s5, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  jal   sub_GAME_7F01D6C0
   sw    $s0, 0x18($sp)
  beqz  $v0, .L7F01E25C
   addiu $s1, $sp, 0x94
  li    $s0, 1
  move  $a0, $zero
  move  $a1, $s1
  jal   save_7000C7BC
   li    $a2, 32
  lbu   $t6, 0x9c($sp)
  li    $at, 66
  addiu $s5, $sp, 0x8c
  beq   $t6, $at, .L7F01DFF4
   addiu $a0, $sp, 0x9c
  move  $s0, $zero
.L7F01DFF4:
  addiu $a1, $sp, 0xb4
  jal   sub_GAME_7F09B600
   move  $a2, $s5
  lw    $t7, 0x8c($sp)
  lw    $t8, 0x94($sp)
  lw    $t9, 0x90($sp)
  lw    $t0, 0x98($sp)
  bne   $t7, $t8, .L7F01E020
   lui   $t1, %hi(D_8002C640) 
  beq   $t9, $t0, .L7F01E024
   nop   
.L7F01E020:
  move  $s0, $zero
.L7F01E024:
  bnez  $s0, .L7F01E0B4
   addiu $t1, %lo(D_8002C640) # addiu $t1, $t1, -0x39c0
  lw    $at, ($t1)
  addiu $v0, $sp, 0x64
  move  $a0, $s1
  sw    $at, ($v0)
  lw    $t3, 4($t1)
  sw    $t3, 4($v0)
  lw    $at, 8($t1)
  lw    $t5, 4($v0)
  sw    $at, 8($v0)
  lw    $t3, 0xc($t1)
  sw    $t3, 0xc($v0)
  lw    $at, 0x10($t1)
  sw    $at, 0x10($v0)
  lw    $t3, 0x14($t1)
  sw    $t3, 0x14($v0)
  lw    $at, 0x18($t1)
  sw    $at, 0x18($v0)
  lw    $at, ($v0)
  lw    $t3, 0x1c($t1)
  sw    $t5, 4($s1)
  sw    $at, ($s1)
  lw    $at, 8($v0)
  lw    $t5, 0xc($v0)
  sw    $t3, 0x1c($v0)
  sw    $at, 8($s1)
  lw    $at, 0x10($v0)
  sw    $t5, 0xc($s1)
  lw    $t5, 0x14($v0)
  sw    $at, 0x10($s1)
  lw    $at, 0x18($v0)
  sw    $t3, 0x1c($s1)
  sw    $t5, 0x14($s1)
  jal   sub_GAME_7F01D758
   sw    $at, 0x18($s1)
.L7F01E0B4:
  lui   $a1, %hi(save1)
  addiu $a1, %lo(save1) # addiu $a1, $a1, -0x66e0
  li    $a0, 4
  jal   save_7000C7BC
   li    $a2, 480
  lui   $s0, %hi(save1)
  lui   $s3, %hi(save1+8)
  lui   $s2, %hi(save2)
  lui   $s4, %hi(dword_CODE_bss_80069B60)
  addiu $s4, %lo(dword_CODE_bss_80069B60) # addiu $s4, $s4, -0x64a0
  addiu $s2, %lo(save2) # addiu $s2, $s2, -0x6680
  addiu $s3, %lo(save1+8) # addiu $s3, $s3, -0x66d8
  addiu $s0, %lo(save1) # addiu $s0, $s0, -0x66e0
.L7F01E0E8:
  li    $s1, 1
  move  $a0, $s3
  move  $a1, $s2
  jal   sub_GAME_7F09B600
   move  $a2, $s5
  lw    $t6, 0x8c($sp)
  lw    $t7, ($s0)
  lw    $t8, 0x90($sp)
  bnel  $t6, $t7, .L7F01E120
   move  $s1, $zero
  lw    $t9, 4($s0)
  beq   $t8, $t9, .L7F01E120
   nop   
  move  $s1, $zero
.L7F01E120:
  bnezl $s1, .L7F01E134
   addiu $s2, $s2, 0x60
  jal   sub_GAME_7F01D840
   move  $a0, $s0
  addiu $s2, $s2, 0x60
.L7F01E134:
  addiu $s0, $s0, 0x60
  bne   $s2, $s4, .L7F01E0E8
   addiu $s3, $s3, 0x60
  move  $s6, $zero
  li    $fp, 96
  li    $s7, 5
.L7F01E14C:
  lui   $s0, %hi(save1)
  li    $s4, -1
  li    $s5, -1
  addiu $s0, %lo(save1) # addiu $s0, $s0, -0x66e0
  move  $s1, $zero
.L7F01E160:
  jal   check_if_eeprom_flag_set_0x80
   move  $a0, $s0
  bnezl $v0, .L7F01E1F8
   addiu $s1, $s1, 1
  jal   get_foldernum_of_eeprom
   move  $a0, $s0
  bnel  $v0, $s6, .L7F01E1F8
   addiu $s1, $s1, 1
  bgez  $s4, .L7F01E19C
   move  $a0, $s0
  move  $s4, $s1
  jal   set_eeprom_flag_0x18
   move  $a0, $s0
  b     .L7F01E1F4
   move  $s5, $v0
.L7F01E19C:
  addiu $s3, $s5, 1
  bgez  $s3, .L7F01E1B4
   andi  $t0, $s3, 3
  beqz  $t0, .L7F01E1B4
   nop   
  addiu $t0, $t0, -4
.L7F01E1B4:
  jal   set_eeprom_flag_0x18
   move  $s3, $t0
  bne   $v0, $s3, .L7F01E1EC
   move  $s2, $v0
  multu $s4, $fp
  lui   $t1, %hi(save1) 
  addiu $t1, %lo(save1) # addiu $t1, $t1, -0x66e0
  mflo  $t2
  addu  $a0, $t2, $t1
  jal   sub_GAME_7F01D840
   nop   
  move  $s4, $s1
  b     .L7F01E1F4
   move  $s5, $s2
.L7F01E1EC:
  jal   sub_GAME_7F01D840
   move  $a0, $s0
.L7F01E1F4:
  addiu $s1, $s1, 1
.L7F01E1F8:
  bne   $s1, $s7, .L7F01E160
   addiu $s0, $s0, 0x60
  bgezl $s4, .L7F01E214
   addiu $s6, $s6, 1
  jal   sub_GAME_7F01DEB4
   move  $a0, $s6
  addiu $s6, $s6, 1
.L7F01E214:
  slti  $at, $s6, 4
  bnez  $at, .L7F01E14C
   nop   
  move  $s6, $zero
  li    $s1, 4
.L7F01E228:
  jal   get_save_folder_ptr
   move  $a0, $s6
  beqz  $v0, .L7F01E250
   move  $a0, $v0
  lui   $t4, %hi(save_selected_bond) 
  addiu $t4, %lo(save_selected_bond) # addiu $t4, $t4, -0x3af0
  sll   $t3, $s6, 2
  jal   get_selected_bond
   addu  $s0, $t3, $t4
  sw    $v0, ($s0)
.L7F01E250:
  addiu $s6, $s6, 1
  bne   $s6, $s1, .L7F01E228
   nop   
.L7F01E25C:
  lw    $ra, 0x3c($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  lw    $s3, 0x24($sp)
  lw    $s4, 0x28($sp)
  lw    $s5, 0x2c($sp)
  lw    $s6, 0x30($sp)
  lw    $s7, 0x34($sp)
  lw    $fp, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0xb8
");

bool check_if_valid_folder_num(int folder_number) {
  if (0 <= folder_number && folder_number < 4)
    return true;
  if (folder_number == 100)
    return true;
  return false;
}

asm(R"
glabel isStageUnlockedAtDifficulty
  addiu $sp, $sp, -0x30
  sw    $ra, 0x2c($sp)
  sw    $s5, 0x28($sp)
  sw    $s3, 0x20($sp)
  sw    $s0, 0x14($sp)
  move  $s0, $a0
  move  $s3, $a1
  move  $s5, $a2
  sw    $s4, 0x24($sp)
  sw    $s2, 0x1c($sp)
  jal   check_if_valid_folder_num
   sw    $s1, 0x18($sp)
  beql  $v0, $zero, .L7F01E4E0
   move  $v0, $zero
  bltz  $s3, .L7F01E4DC
   slti  $at, $s3, 0x14
  beql  $at, $zero, .L7F01E4E0
   move  $v0, $zero
  bltz  $s5, .L7F01E4DC
   slti  $at, $s5, 4
  beql  $at, $zero, .L7F01E4E0
   move  $v0, $zero
  jal   get_save_folder_ptr
   move  $a0, $s0
  beqz  $v0, .L7F01E494
   move  $s2, $v0
  move  $a0, $v0
  move  $a1, $s3
  jal   get_eeprom_stage_completed_for_difficulty
   move  $a2, $s5
  beqz  $v0, .L7F01E348
   li    $at, 18
  b     .L7F01E4E0
   li    $v0, 3
.L7F01E348:
  bnel  $s3, $at, .L7F01E358
   li    $at, 19
  blez  $s5, .L7F01E368
   li    $at, 19
.L7F01E358:
  bne   $s3, $at, .L7F01E370
   slti  $at, $s5, 2
  beql  $at, $zero, .L7F01E374
   slti  $at, $s5, 4
.L7F01E368:
  b     .L7F01E4E0
   move  $v0, $zero
.L7F01E370:
  slti  $at, $s5, 4
.L7F01E374:
  beqz  $at, .L7F01E3C8
   move  $s1, $s5
  li    $s4, 4
.L7F01E380:
  blez  $s3, .L7F01E3AC
   move  $s0, $zero
  move  $a0, $s2
.L7F01E38C:
  move  $a1, $s0
  jal   get_eeprom_stage_completed_for_difficulty
   move  $a2, $s1
  beql  $v0, $zero, .L7F01E3B0
   slt   $at, $s0, $s3
  addiu $s0, $s0, 1
  bnel  $s0, $s3, .L7F01E38C
   move  $a0, $s2
.L7F01E3AC:
  slt   $at, $s0, $s3
.L7F01E3B0:
  bnez  $at, .L7F01E3C0
   addiu $s1, $s1, 1
  b     .L7F01E4E0
   li    $v0, 1
.L7F01E3C0:
  bne   $s1, $s4, .L7F01E380
   nop   
.L7F01E3C8:
  slti  $at, $s5, 3
  beqz  $at, .L7F01E414
   li    $s4, 4
  slti  $at, $s3, 0x12
  beqz  $at, .L7F01E414
   slti  $at, $s5, 4
  beqz  $at, .L7F01E414
   move  $s1, $s5
  addiu $s0, $s3, -1
  move  $a0, $s2
.L7F01E3F0:
  move  $a1, $s0
  jal   get_eeprom_stage_completed_for_difficulty
   move  $a2, $s1
  beqz  $v0, .L7F01E40C
   addiu $s1, $s1, 1
  b     .L7F01E4E0
   li    $v0, 1
.L7F01E40C:
  bnel  $s1, $s4, .L7F01E3F0
   move  $a0, $s2
.L7F01E414:
  slti  $at, $s5, 3
  beqz  $at, .L7F01E494
   move  $s1, $zero
  move  $a0, $s2
.L7F01E424:
  move  $a1, $s1
  jal   get_eeprom_stage_completed_for_difficulty
   move  $a2, $zero
  beql  $v0, $zero, .L7F01E44C
   slti  $at, $s1, 0x12
  addiu $s1, $s1, 1
  slti  $at, $s1, 0x12
  bnezl $at, .L7F01E424
   move  $a0, $s2
  slti  $at, $s1, 0x12
.L7F01E44C:
  bnez  $at, .L7F01E494
   nop   
  blez  $s5, .L7F01E480
   move  $s1, $zero
  move  $a0, $s2
.L7F01E460:
  move  $a1, $s3
  jal   get_eeprom_stage_completed_for_difficulty
   move  $a2, $s1
  beql  $v0, $zero, .L7F01E484
   slt   $at, $s1, $s5
  addiu $s1, $s1, 1
  bnel  $s1, $s5, .L7F01E460
   move  $a0, $s2
.L7F01E480:
  slt   $at, $s1, $s5
.L7F01E484:
  bnez  $at, .L7F01E494
   nop   
  b     .L7F01E4E0
   li    $v0, 1
.L7F01E494:
  bnez  $s3, .L7F01E4A4
   nop   
  b     .L7F01E4E0
   li    $v0, 1
.L7F01E4A4:
  jal   get_debug_enable_agent_levels_flag
   nop   
  beqz  $v0, .L7F01E4C4
   nop   
  bnez  $s5, .L7F01E4C4
   nop   
  b     .L7F01E4E0
   li    $v0, 1
.L7F01E4C4:
  jal   get_debug_enable_all_levels_flag
   nop   
  beql  $v0, $zero, .L7F01E4E0
   move  $v0, $zero
  b     .L7F01E4E0
   li    $v0, 1
.L7F01E4DC:
  move  $v0, $zero
.L7F01E4E0:
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  lw    $s4, 0x24($sp)
  lw    $s5, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x30
");

asm(R"
glabel sub_GAME_7F01E504
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  sw    $a0, 0x28($sp)
  sw    $a1, 0x2c($sp)
  jal   sub_GAME_7F01DE50
   sw    $zero, 0x20($sp)
  bltz  $v0, .L7F01E5E8
   move  $v1, $v0
  lw    $t9, 0x2c($sp)
  sll   $t6, $v0, 2
  subu  $t6, $t6, $v0
  lui   $t7, %hi(save1) 
  addiu $t7, %lo(save1) # addiu $t7, $t7, -0x66e0
  sll   $t6, $t6, 5
  addu  $t8, $t6, $t7
  addiu $t1, $t9, 0x60
.L7F01E544:
  lw    $at, ($t9)
  addiu $t9, $t9, 0xc
  addiu $t8, $t8, 0xc
  sw    $at, -0xc($t8)
  lw    $at, -8($t9)
  sw    $at, -8($t8)
  lw    $at, -4($t9)
  bne   $t9, $t1, .L7F01E544
   sw    $at, -4($t8)
  lw    $t2, 0x28($sp)
  beqz  $t2, .L7F01E59C
   move  $a0, $t2
  jal   set_eeprom_flag_0x18
   sw    $v1, 0x24($sp)
  addiu $t3, $v0, 1
  lw    $v1, 0x24($sp)
  bgez  $t3, .L7F01E598
   andi  $t4, $t3, 3
  beqz  $t4, .L7F01E598
   nop   
  addiu $t4, $t4, -4
.L7F01E598:
  sw    $t4, 0x20($sp)
.L7F01E59C:
  sll   $t5, $v1, 2
  subu  $t5, $t5, $v1
  lui   $t6, %hi(save1) 
  addiu $t6, %lo(save1) # addiu $t6, $t6, -0x66e0
  sll   $t5, $t5, 5
  addu  $a0, $t5, $t6
  sw    $a0, 0x1c($sp)
  jal   toggle_eeprom_flag_set_0x80
   move  $a1, $zero
  lw    $a0, 0x1c($sp)
  jal   reset_eeprom_flag_0x18
   lw    $a1, 0x20($sp)
  jal   sub_GAME_7F01D7A0
   lw    $a0, 0x1c($sp)
  lw    $t7, 0x28($sp)
  beql  $t7, $zero, .L7F01E5EC
   lw    $ra, 0x14($sp)
  jal   sub_GAME_7F01D840
   move  $a0, $t7
.L7F01E5E8:
  lw    $ra, 0x14($sp)
.L7F01E5EC:
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel unlock_stage_in_folder_on_difficulty
  addiu $sp, $sp, -0x98
  sw    $s5, 0x28($sp)
  sw    $s4, 0x24($sp)
  sw    $s2, 0x1c($sp)
  sw    $s0, 0x14($sp)
  move  $s0, $a0
  move  $s2, $a1
  move  $s4, $a2
  move  $s5, $a3
  sw    $ra, 0x2c($sp)
  sw    $s3, 0x20($sp)
  bltz  $a0, .L7F01E73C
   sw    $s1, 0x18($sp)
  slti  $at, $a0, 4
  beql  $at, $zero, .L7F01E740
   lw    $ra, 0x2c($sp)
  bltz  $a1, .L7F01E73C
   slti  $at, $a1, 0x14
  beql  $at, $zero, .L7F01E740
   lw    $ra, 0x2c($sp)
  bltz  $a2, .L7F01E73C
   slti  $at, $a2, 4
  beqz  $at, .L7F01E73C
   addiu $s1, $sp, 0x38
  lui   $t6, %hi(D_8002C640+0x20) 
  addiu $t6, %lo(D_8002C640+0x20) # addiu $t6, $t6, -0x39a0
  addiu $t8, $t6, 0x60
  move  $t9, $s1
.L7F01E668:
  lw    $at, ($t6)
  addiu $t6, $t6, 0xc
  addiu $t9, $t9, 0xc
  sw    $at, -0xc($t9)
  lw    $at, -8($t6)
  sw    $at, -8($t9)
  lw    $at, -4($t6)
  bne   $t6, $t8, .L7F01E668
   sw    $at, -4($t9)
  jal   get_save_folder_ptr
   move  $a0, $s0
  beqz  $v0, .L7F01E6D4
   sw    $v0, 0x34($sp)
  move  $t2, $v0
  move  $t3, $s1
  addiu $t1, $v0, 0x60
.L7F01E6A8:
  lw    $at, ($t2)
  addiu $t2, $t2, 0xc
  addiu $t3, $t3, 0xc
  sw    $at, -0xc($t3)
  lw    $at, -8($t2)
  sw    $at, -8($t3)
  lw    $at, -4($t2)
  bne   $t2, $t1, .L7F01E6A8
   sw    $at, -4($t3)
  b     .L7F01E6E0
   nop   
.L7F01E6D4:
  move  $a0, $s1
  jal   set_eeprom_to_folder_num
   move  $a1, $s0
.L7F01E6E0:
  bltz  $s4, .L7F01E730
   move  $s0, $s4
  lui   $s3, (0x05F5E0FF >> 16) # lui $s3, 0x5f5
  ori   $s3, (0x05F5E0FF & 0xFFFF) # ori $s3, $s3, 0xe0ff
.L7F01E6F0:
  bne   $s0, $s4, .L7F01E714
   move  $a0, $s1
  move  $a0, $s1
  move  $a1, $s2
  move  $a2, $s0
  jal   sub_GAME_7F01DCB0
   move  $a3, $s5
  b     .L7F01E728
   addiu $s0, $s0, -1
.L7F01E714:
  move  $a1, $s2
  move  $a2, $s0
  jal   sub_GAME_7F01DCB0
   move  $a3, $s3
  addiu $s0, $s0, -1
.L7F01E728:
  bgez  $s0, .L7F01E6F0
   nop   
.L7F01E730:
  lw    $a0, 0x34($sp)
  jal   sub_GAME_7F01E504
   move  $a1, $s1
.L7F01E73C:
  lw    $ra, 0x2c($sp)
.L7F01E740:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  lw    $s4, 0x24($sp)
  lw    $s5, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x98
");

asm(R"
glabel sub_GAME_7F01E760
  addiu $sp, $sp, -0x80
  sw    $ra, 0x14($sp)
  bltz  $a0, .L7F01E864
   move  $a3, $a0
  slti  $at, $a0, 4
  beql  $at, $zero, .L7F01E868
   lw    $ra, 0x14($sp)
  bltz  $a1, .L7F01E864
   slti  $at, $a1, 0x14
  beql  $at, $zero, .L7F01E868
   lw    $ra, 0x14($sp)
  sw    $a1, 0x84($sp)
  jal   get_save_folder_ptr
   sw    $a3, 0x80($sp)
  lw    $a3, 0x80($sp)
  beqz  $v0, .L7F01E7C4
   move  $a2, $v0
  move  $a0, $v0
  lw    $a1, 0x84($sp)
  sw    $v0, 0x7c($sp)
  jal   check_if_cheat_unlocked
   sw    $a3, 0x80($sp)
  lw    $a2, 0x7c($sp)
  bnez  $v0, .L7F01E864
   lw    $a3, 0x80($sp)
.L7F01E7C4:
  lui   $t6, %hi(D_8002C6C0) 
  addiu $a0, $sp, 0x1c
  addiu $t6, %lo(D_8002C6C0) # addiu $t6, $t6, -0x3940
  addiu $t8, $t6, 0x60
  move  $t9, $a0
.L7F01E7D8:
  lw    $at, ($t6)
  addiu $t6, $t6, 0xc
  addiu $t9, $t9, 0xc
  sw    $at, -0xc($t9)
  lw    $at, -8($t6)
  sw    $at, -8($t9)
  lw    $at, -4($t6)
  bne   $t6, $t8, .L7F01E7D8
   sw    $at, -4($t9)
  beqz  $a2, .L7F01E83C
   move  $a1, $a3
  move  $t2, $a2
  move  $t3, $a0
  addiu $t1, $a2, 0x60
.L7F01E810:
  lw    $at, ($t2)
  addiu $t2, $t2, 0xc
  addiu $t3, $t3, 0xc
  sw    $at, -0xc($t3)
  lw    $at, -8($t2)
  sw    $at, -8($t3)
  lw    $at, -4($t2)
  bne   $t2, $t1, .L7F01E810
   sw    $at, -4($t3)
  b     .L7F01E850
   lw    $a1, 0x84($sp)
.L7F01E83C:
  jal   set_eeprom_to_folder_num
   sw    $a2, 0x7c($sp)
  lw    $a2, 0x7c($sp)
  addiu $a0, $sp, 0x1c
  lw    $a1, 0x84($sp)
.L7F01E850:
  jal   sub_GAME_7F01DD74
   sw    $a2, 0x7c($sp)
  lw    $a0, 0x7c($sp)
  jal   sub_GAME_7F01E504
   addiu $a1, $sp, 0x1c
.L7F01E864:
  lw    $ra, 0x14($sp)
.L7F01E868:
  addiu $sp, $sp, 0x80
  jr    $ra
   nop   
");

asm(R"
glabel get_highest_stage_difficulty_completed_in_folder
  addiu $sp, $sp, -0x28
  sw    $ra, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a1, 0x2c($sp)
  jal   get_save_folder_ptr
   sw    $a2, 0x30($sp)
  beqz  $v0, .L7F01E8E8
   move  $s2, $v0
  li    $s1, 3
  li    $s0, 19
.L7F01E8A4:
  move  $a0, $s2
.L7F01E8A8:
  move  $a1, $s0
  jal   get_eeprom_stage_completed_for_difficulty
   move  $a2, $s1
  beql  $v0, $zero, .L7F01E8D4
   addiu $s0, $s0, -1
  lw    $t6, 0x2c($sp)
  sw    $s0, ($t6)
  lw    $t7, 0x30($sp)
  b     .L7F01E8FC
   sw    $s1, ($t7)
  addiu $s0, $s0, -1
.L7F01E8D4:
  bgezl $s0, .L7F01E8A8
   move  $a0, $s2
  addiu $s1, $s1, -1
  bgezl $s1, .L7F01E8A4
   li    $s0, 19
.L7F01E8E8:
  lw    $t8, 0x2c($sp)
  li    $v0, -1
  sw    $v0, ($t8)
  lw    $t9, 0x30($sp)
  sw    $v0, ($t9)
.L7F01E8FC:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
glabel check_egypt_completed_in_folder
  addiu $sp, $sp, -0x28
  sw    $ra, 0x24($sp)
  sw    $s2, 0x1c($sp)
  move  $s2, $a0
  sw    $s3, 0x20($sp)
  sw    $s1, 0x18($sp)
  jal   get_save_folder_ptr
   sw    $s0, 0x14($sp)
  beqz  $v0, .L7F01E978
   li    $s1, 19
  li    $s3, 4
  move  $s0, $zero
.L7F01E944:
  move  $a0, $s2
.L7F01E948:
  move  $a1, $s1
  jal   isStageUnlockedAtDifficulty
   move  $a2, $s0
  beqz  $v0, .L7F01E964
   addiu $s0, $s0, 1
  b     .L7F01E97C
   move  $v0, $s1
.L7F01E964:
  bnel  $s0, $s3, .L7F01E948
   move  $a0, $s2
  addiu $s1, $s1, -1
  bgezl $s1, .L7F01E944
   move  $s0, $zero
.L7F01E978:
  move  $v0, $zero
.L7F01E97C:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

unsigned int check_egypt_completed_any_folder(void) {
  int isfound, folder, isunlocked;
  isunlocked = 0;
  folder = 0;
  while (folder != 4) {
    isfound = check_egypt_completed_in_folder(folder);
    folder += 1;
    if (isunlocked < isfound)
      isunlocked = isfound;
  }
  return isunlocked;
}

asm(R"
glabel check_cradle_completed_in_folder
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  li    $a1, 17
  jal   isStageUnlockedAtDifficulty
   move  $a2, $zero
  xori  $t6, $v0, 3
  sltiu $v0, $t6, 1
  bnez  $v0, .L7F01EA4C
   lw    $a0, 0x18($sp)
  li    $a1, 17
  jal   isStageUnlockedAtDifficulty
   li    $a2, 1
  xori  $t7, $v0, 3
  sltiu $v0, $t7, 1
  bnez  $v0, .L7F01EA4C
   lw    $a0, 0x18($sp)
  li    $a1, 17
  jal   isStageUnlockedAtDifficulty
   li    $a2, 2
  xori  $t8, $v0, 3
  sltiu $v0, $t8, 1
.L7F01EA4C:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel check_aztec_completed_in_folder_secret_00
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  li    $a1, 18
  jal   isStageUnlockedAtDifficulty
   li    $a2, 1
  xori  $t6, $v0, 3
  sltiu $v0, $t6, 1
  bnez  $v0, .L7F01EA98
   lw    $a0, 0x18($sp)
  li    $a1, 18
  jal   isStageUnlockedAtDifficulty
   li    $a2, 2
  xori  $t7, $v0, 3
  sltiu $v0, $t7, 1
.L7F01EA98:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel check_egypt_completed_in_folder_00
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  li    $a1, 19
  jal   isStageUnlockedAtDifficulty
   li    $a2, 2
  lw    $ra, 0x14($sp)
  xori  $t6, $v0, 3
  sltiu $v0, $t6, 1
  jr    $ra
   addiu $sp, $sp, 0x18
");

unsigned int check_cradle_completed_any_folder(void) {
  unsigned int completed;
  int folder = 0;
  while (folder != 4) {
    completed = check_cradle_completed_in_folder(folder);
    folder += 1;
    if (completed != false)
      return true;
  }
  return false;
}

unsigned int check_aztec_completed_any_folder_secret_00(void) {
  unsigned int completed;
  int folder = 0;
  while (folder != 4) {
    completed = check_aztec_completed_in_folder_secret_00(folder);
    folder += 1;
    if (completed != false)
      return true;
  }
  return false;
}

unsigned int check_egypt_completed_any_folder_00(void) {
  unsigned int completed;
  int folder = 0;
  while (folder != 4) {
    completed = check_egypt_completed_in_folder_00(folder);
    folder += 1;
    if (completed != false)
      return true;
  }
  return false;
}

unsigned char
removed_would_have_returned_bond_for_folder_num(unsigned int folder) {
  return 0;
}

void set_selected_bond_to_folder(int folder_number, int arg1) {
  extern int save_selected_bond[];
  if (0 <= folder_number && folder_number < 4)
    save_selected_bond[folder_number] = 0;
}

void sub_GAME_7F01EBF4(unsigned int unused) {}

void sub_GAME_7F01EBFC(unsigned int unused) {}

asm(R"
glabel delete_eeprom_folder
  addiu $sp, $sp, -0x90
  sw    $s0, 0x14($sp)
  move  $s0, $a0
  sw    $ra, 0x1c($sp)
  bltz  $a0, .L7F01ECFC
   sw    $s1, 0x18($sp)
  slti  $at, $a0, 4
  beql  $at, $zero, .L7F01ED00
   lw    $ra, 0x1c($sp)
  jal   get_save_folder_ptr
   nop   
  beqz  $v0, .L7F01ECFC
   move  $s1, $v0
  move  $a0, $s0
  addiu $a1, $sp, 0x88
  jal   get_highest_stage_difficulty_completed_in_folder
   addiu $a2, $sp, 0x84
  lw    $t6, 0x88($sp)
  lw    $t7, 0x84($sp)
  bltzl $t6, .L7F01ED00
   lw    $ra, 0x1c($sp)
  bltz  $t7, .L7F01ECFC
   addiu $v0, $sp, 0x24
  lui   $t8, %hi(D_8002C720) 
  addiu $t8, %lo(D_8002C720) # addiu $t8, $t8, -0x38e0
  addiu $t0, $t8, 0x60
  move  $t1, $v0
.L7F01EC70:
  lw    $at, ($t8)
  addiu $t8, $t8, 0xc
  addiu $t1, $t1, 0xc
  sw    $at, -0xc($t1)
  lw    $at, -8($t8)
  sw    $at, -8($t1)
  lw    $at, -4($t8)
  bne   $t8, $t0, .L7F01EC70
   sw    $at, -4($t1)
  move  $t4, $v0
  move  $t5, $s1
  addiu $t3, $v0, 0x60
.L7F01ECA0:
  lw    $at, ($t4)
  addiu $t4, $t4, 0xc
  addiu $t5, $t5, 0xc
  sw    $at, -0xc($t5)
  lw    $at, -8($t4)
  sw    $at, -8($t5)
  lw    $at, -4($t4)
  bne   $t4, $t3, .L7F01ECA0
   sw    $at, -4($t5)
  move  $a0, $s1
  jal   set_eeprom_to_folder_num
   move  $a1, $s0
  move  $a0, $s1
  jal   toggle_eeprom_flag_set_0x80
   move  $a1, $zero
  move  $a0, $s1
  jal   set_selected_bond
   move  $a1, $s0
  move  $a0, $s0
  jal   set_selected_bond_to_folder
   move  $a1, $s0
  jal   sub_GAME_7F01D7A0
   move  $a0, $s1
.L7F01ECFC:
  lw    $ra, 0x1c($sp)
.L7F01ED00:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x90
");

asm(R"
glabel sub_GAME_7F01ED10
  addiu $sp, $sp, -0x30
  sw    $ra, 0x2c($sp)
  sw    $s5, 0x28($sp)
  sw    $s4, 0x24($sp)
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  jal   get_save_folder_ptr
   sw    $s0, 0x14($sp)
  lui   $s1, (0x05F5E0FF >> 16) # lui $s1, 0x5f5
  move  $s4, $v0
  ori   $s1, (0x05F5E0FF & 0xFFFF) # ori $s1, $s1, 0xe0ff
  move  $s3, $zero
  li    $s5, 20
  li    $s2, 3
  move  $s0, $zero
.L7F01ED50:
  move  $a0, $s4
.L7F01ED54:
  move  $a1, $s3
  move  $a2, $s0
  jal   sub_GAME_7F01DCB0
   move  $a3, $s1
  addiu $s0, $s0, 1
  bnel  $s0, $s2, .L7F01ED54
   move  $a0, $s4
  addiu $s3, $s3, 1
  bnel  $s3, $s5, .L7F01ED50
   move  $s0, $zero
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  lw    $s4, 0x24($sp)
  lw    $s5, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x30
");

asm(R"
glabel sub_GAME_7F01EDA0
  addiu $sp, $sp, -0xa0
  sw    $ra, 0x24($sp)
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  bltz  $a0, .L7F01EEF4
   sw    $s0, 0x14($sp)
  slti  $at, $a0, 4
  beql  $at, $zero, .L7F01EEF8
   lw    $ra, 0x24($sp)
  jal   get_save_folder_ptr
   sw    $a0, 0xa0($sp)
  beqz  $v0, .L7F01EEF4
   sw    $v0, 0x9c($sp)
  addiu $s2, $sp, 0x98
  addiu $s3, $sp, 0x94
  move  $a2, $s3
  move  $a1, $s2
  jal   get_highest_stage_difficulty_completed_in_folder
   lw    $a0, 0xa0($sp)
  lw    $t6, 0x98($sp)
  lw    $t7, 0x94($sp)
  bltzl $t6, .L7F01EEF8
   lw    $ra, 0x24($sp)
  bltz  $t7, .L7F01EEF4
   move  $s0, $zero
  li    $s1, 4
.L7F01EE0C:
  jal   get_save_folder_ptr
   move  $a0, $s0
  beqz  $v0, .L7F01EE4C
   move  $a0, $s0
  move  $a1, $s2
  jal   get_highest_stage_difficulty_completed_in_folder
   move  $a2, $s3
  lw    $t8, 0x98($sp)
  lw    $t9, 0x94($sp)
  bgezl $t8, .L7F01EE44
   addiu $s0, $s0, 1
  bltzl $t9, .L7F01EE50
   slti  $at, $s0, 4
  addiu $s0, $s0, 1
.L7F01EE44:
  bne   $s0, $s1, .L7F01EE0C
   nop   
.L7F01EE4C:
  slti  $at, $s0, 4
.L7F01EE50:
  beqz  $at, .L7F01EEF4
   addiu $s1, $sp, 0x30
  lui   $t0, %hi(D_8002C780) 
  addiu $t0, %lo(D_8002C780) # addiu $t0, $t0, -0x3880
  addiu $t2, $t0, 0x60
  move  $t3, $s1
.L7F01EE68:
  lw    $at, ($t0)
  addiu $t0, $t0, 0xc
  addiu $t3, $t3, 0xc
  sw    $at, -0xc($t3)
  lw    $at, -8($t0)
  sw    $at, -8($t3)
  lw    $at, -4($t0)
  bne   $t0, $t2, .L7F01EE68
   sw    $at, -4($t3)
  jal   get_save_folder_ptr
   move  $a0, $s0
  lw    $t4, 0x9c($sp)
  move  $s2, $v0
  move  $t7, $s1
  addiu $t6, $t4, 0x60
.L7F01EEA4:
  lw    $at, ($t4)
  addiu $t4, $t4, 0xc
  addiu $t7, $t7, 0xc
  sw    $at, -0xc($t7)
  lw    $at, -8($t4)
  sw    $at, -8($t7)
  lw    $at, -4($t4)
  bne   $t4, $t6, .L7F01EEA4
   sw    $at, -4($t7)
  move  $a0, $s1
  jal   set_eeprom_to_folder_num
   move  $a1, $s0
  jal   removed_would_have_returned_bond_for_folder_num
   lw    $a0, 0xa0($sp)
  move  $a0, $s0
  jal   set_selected_bond_to_folder
   move  $a1, $v0
  move  $a0, $s2
  jal   sub_GAME_7F01E504
   move  $a1, $s1
.L7F01EEF4:
  lw    $ra, 0x24($sp)
.L7F01EEF8:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0xa0
");

asm(R"
glabel update_eeprom_to_current_solo_watch_settings
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a0, 0x20($sp)
  jal   sub_GAME_7F0A9358
   move  $s0, $zero
  lw    $t7, 0x20($sp)
  sra   $t6, $v0, 7
  jal   call_sfx_c_700091C8
   sb    $t6, 0xa($t7)
  lw    $t9, 0x20($sp)
  sra   $t8, $v0, 7
  jal   get_cur_player_look_vertical_inverted
   sb    $t8, 0xb($t9)
  beqz  $v0, .L7F01EF54
   nop   
  li    $s0, 1
.L7F01EF54:
  jal   cur_player_get_autoaim
   nop   
  beqz  $v0, .L7F01EF68
   ori   $t0, $s0, 2
  andi  $s0, $t0, 0xffff
.L7F01EF68:
  jal   cur_player_get_aim_control
   nop   
  beqz  $v0, .L7F01EF7C
   ori   $t2, $s0, 4
  andi  $s0, $t2, 0xffff
.L7F01EF7C:
  jal   cur_player_get_sight_onscreen_control
   nop   
  beqz  $v0, .L7F01EF90
   ori   $t4, $s0, 8
  andi  $s0, $t4, 0xffff
.L7F01EF90:
  jal   cur_player_get_lookahead
   nop   
  beqz  $v0, .L7F01EFA4
   ori   $t6, $s0, 0x10
  andi  $s0, $t6, 0xffff
.L7F01EFA4:
  jal   cur_player_get_ammo_onscreen_setting
   nop   
  beqz  $v0, .L7F01EFB8
   ori   $t8, $s0, 0x20
  andi  $s0, $t8, 0xffff
.L7F01EFB8:
  jal   cur_player_get_screen_setting
   nop   
  li    $at, 1
  bne   $v0, $at, .L7F01EFD4
   ori   $t0, $s0, 0x40
  b     .L7F01EFEC
   andi  $s0, $t0, 0xffff
.L7F01EFD4:
  jal   cur_player_get_screen_setting
   nop   
  li    $at, 2
  bne   $v0, $at, .L7F01EFEC
   ori   $t2, $s0, 0x800
  andi  $s0, $t2, 0xffff
.L7F01EFEC:
  jal   get_screen_ratio
   nop   
  beqz  $v0, .L7F01F000
   ori   $t4, $s0, 0x80
  andi  $s0, $t4, 0xffff
.L7F01F000:
  jal   cur_player_get_control_type
   nop   
  lw    $t0, 0x20($sp)
  sll   $t7, $v0, 8
  andi  $t8, $t7, 0x700
  or    $t9, $s0, $t8
  sh    $t9, 0xc($t0)
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel get_screen_ratio_settings_for_mpgame_from_folder
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  jal   get_save_folder_ptr
   sw    $s0, 0x18($sp)
  beqz  $v0, .L7F01F170
   move  $v1, $v0
  lbu   $v0, 0xa($v0)
  sw    $v1, 0x24($sp)
  sll   $t6, $v0, 7
  sra   $t7, $v0, 1
  or    $a0, $t6, $t7
  andi  $t8, $a0, 0xffff
  jal   sub_GAME_7F0A9364
   move  $a0, $t8
  lw    $s0, 0x24($sp)
  lbu   $v0, 0xb($s0)
  sll   $t9, $v0, 7
  sra   $t0, $v0, 1
  or    $a0, $t9, $t0
  andi  $t1, $a0, 0xffff
  jal   sub_GAME_7F0A91A0
   move  $a0, $t1
  lhu   $t2, 0xc($s0)
  jal   getPlayerCount
   sh    $t2, 0x20($sp)
  li    $at, 1
  bne   $v0, $at, .L7F01F0B8
   lhu   $s0, 0x20($sp)
  andi  $a0, $s0, 0x700
  sra   $t3, $a0, 8
  jal   cur_player_set_control_type
   andi  $a0, $t3, 0xffff
  b     .L7F01F0C8
   andi  $a0, $s0, 1
.L7F01F0B8:
  jal   cur_player_set_control_type
   move  $a0, $zero
  lhu   $s0, 0x20($sp)
  andi  $a0, $s0, 1
.L7F01F0C8:
  sltu  $t5, $zero, $a0
  jal   set_cur_player_look_vertical_inverted
   move  $a0, $t5
  andi  $a0, $s0, 2
  sltu  $t6, $zero, $a0
  jal   cur_player_set_autoaim
   move  $a0, $t6
  andi  $a0, $s0, 4
  sltu  $t7, $zero, $a0
  jal   cur_player_set_aim_control
   move  $a0, $t7
  andi  $a0, $s0, 8
  sltu  $t8, $zero, $a0
  jal   cur_player_set_sight_onscreen_control
   move  $a0, $t8
  andi  $a0, $s0, 0x10
  sltu  $t9, $zero, $a0
  jal   cur_player_set_lookahead
   move  $a0, $t9
  andi  $a0, $s0, 0x20
  sltu  $t0, $zero, $a0
  jal   cur_player_set_ammo_onscreen_setting
   move  $a0, $t0
  andi  $t1, $s0, 0x800
  beqz  $t1, .L7F01F140
   andi  $t2, $s0, 0x40
  jal   cur_player_set_screen_setting
   li    $a0, 2
  b     .L7F01F164
   andi  $a0, $s0, 0x80
.L7F01F140:
  beqz  $t2, .L7F01F158
   nop   
  jal   cur_player_set_screen_setting
   li    $a0, 1
  b     .L7F01F164
   andi  $a0, $s0, 0x80
.L7F01F158:
  jal   cur_player_set_screen_setting
   move  $a0, $zero
  andi  $a0, $s0, 0x80
.L7F01F164:
  sltu  $t3, $zero, $a0
  jal   set_screen_ratio
   move  $a0, $t3
.L7F01F170:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel delete_update_eeprom_file
  addiu $sp, $sp, -0xe0
  sw    $ra, 0x14($sp)
  bltz  $a0, .L7F01F28C
   move  $a1, $a0
  slti  $at, $a0, 4
  beql  $at, $zero, .L7F01F290
   lw    $ra, 0x14($sp)
  jal   get_save_folder_ptr
   sw    $a1, 0xe0($sp)
  lui   $t6, %hi(D_8002C7E0) 
  addiu $a2, $sp, 0x7c
  addiu $t6, %lo(D_8002C7E0) # addiu $t6, $t6, -0x3820
  lw    $a1, 0xe0($sp)
  sw    $v0, 0xdc($sp)
  addiu $t9, $t6, 0x60
  move  $t0, $a2
.L7F01F1C4:
  lw    $at, ($t6)
  addiu $t6, $t6, 0xc
  addiu $t0, $t0, 0xc
  sw    $at, -0xc($t0)
  lw    $at, -8($t6)
  sw    $at, -8($t0)
  lw    $at, -4($t6)
  bne   $t6, $t9, .L7F01F1C4
   sw    $at, -4($t0)
  beqz  $v0, .L7F01F224
   move  $t3, $v0
  move  $t4, $a2
  addiu $t2, $v0, 0x60
.L7F01F1F8:
  lw    $at, ($t3)
  addiu $t3, $t3, 0xc
  addiu $t4, $t4, 0xc
  sw    $at, -0xc($t4)
  lw    $at, -8($t3)
  sw    $at, -8($t4)
  lw    $at, -4($t3)
  bne   $t3, $t2, .L7F01F1F8
   sw    $at, -4($t4)
  b     .L7F01F234
   addiu $a0, $sp, 0x1c
.L7F01F224:
  jal   set_eeprom_to_folder_num
   move  $a0, $a2
  addiu $a2, $sp, 0x7c
  addiu $a0, $sp, 0x1c
.L7F01F234:
  move  $t9, $a0
  move  $t7, $a2
  addiu $t8, $a2, 0x60
.L7F01F240:
  lw    $at, ($t7)
  addiu $t7, $t7, 0xc
  addiu $t9, $t9, 0xc
  sw    $at, -0xc($t9)
  lw    $at, -8($t7)
  sw    $at, -8($t9)
  lw    $at, -4($t7)
  bne   $t7, $t8, .L7F01F240
   sw    $at, -4($t9)
  jal   update_eeprom_to_current_solo_watch_settings
   nop   
  addiu $a0, $sp, 0x1c
  addiu $a1, $sp, 0x7c
  jal   _bcmp
   li    $a2, 96
  beqz  $v0, .L7F01F28C
   lw    $a0, 0xdc($sp)
  jal   sub_GAME_7F01E504
   addiu $a1, $sp, 0x1c
.L7F01F28C:
  lw    $ra, 0x14($sp)
.L7F01F290:
  addiu $sp, $sp, 0xe0
  jr    $ra
   nop   
");

asm(R"
glabel copy_eeprom_to_stack_set_folder_num
  addiu $sp, $sp, -0x88
  sw    $s0, 0x14($sp)
  move  $s0, $a0
  sw    $ra, 0x1c($sp)
  bltz  $a0, .L7F01F380
   sw    $s1, 0x18($sp)
  slti  $at, $a0, 4
  beql  $at, $zero, .L7F01F384
   lw    $ra, 0x1c($sp)
  jal   get_save_folder_ptr
   nop   
  lui   $t6, %hi(D_8002C840) 
  addiu $s1, $sp, 0x24
  addiu $t6, %lo(D_8002C840) # addiu $t6, $t6, -0x37c0
  sw    $v0, 0x84($sp)
  addiu $t9, $t6, 0x60
  move  $t0, $s1
.L7F01F2E0:
  lw    $at, ($t6)
  addiu $t6, $t6, 0xc
  addiu $t0, $t0, 0xc
  sw    $at, -0xc($t0)
  lw    $at, -8($t6)
  sw    $at, -8($t0)
  lw    $at, -4($t6)
  bne   $t6, $t9, .L7F01F2E0
   sw    $at, -4($t0)
  beqz  $v0, .L7F01F344
   move  $a0, $s1
  move  $t3, $v0
  move  $t4, $s1
  addiu $t2, $v0, 0x60
.L7F01F318:
  lw    $at, ($t3)
  addiu $t3, $t3, 0xc
  addiu $t4, $t4, 0xc
  sw    $at, -0xc($t4)
  lw    $at, -8($t3)
  sw    $at, -8($t4)
  lw    $at, -4($t3)
  bne   $t3, $t2, .L7F01F318
   sw    $at, -4($t4)
  b     .L7F01F34C
   nop   
.L7F01F344:
  jal   set_eeprom_to_folder_num
   move  $a1, $s0
.L7F01F34C:
  jal   get_selected_bond
   move  $a0, $s1
  sll   $t5, $s0, 2
  lui   $a1, %hi(save_selected_bond)
  addu  $a1, $a1, $t5
  lw    $a1, %lo(save_selected_bond)($a1)
  beql  $v0, $a1, .L7F01F384
   lw    $ra, 0x1c($sp)
  jal   set_selected_bond
   move  $a0, $s1
  lw    $a0, 0x84($sp)
  jal   sub_GAME_7F01E504
   move  $a1, $s1
.L7F01F380:
  lw    $ra, 0x1c($sp)
.L7F01F384:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x88
");

asm(R"
glabel copy_eeprom_from_to
  addiu $sp, $sp, -0x80
  sw    $ra, 0x14($sp)
  jal   get_save_folder_ptr
   sw    $a1, 0x84($sp)
  beqz  $v0, .L7F01F3E4
   lw    $v1, 0x84($sp)
  move  $t8, $v0
  move  $t9, $v1
  addiu $t7, $v0, 0x60
.L7F01F3B8:
  lw    $at, ($t8)
  addiu $t8, $t8, 0xc
  addiu $t9, $t9, 0xc
  sw    $at, -0xc($t9)
  lw    $at, -8($t8)
  sw    $at, -8($t9)
  lw    $at, -4($t8)
  bne   $t8, $t7, .L7F01F3B8
   sw    $at, -4($t9)
  b     .L7F01F450
   lw    $ra, 0x14($sp)
.L7F01F3E4:
  lui   $t0, %hi(blank_eeprom) 
  addiu $v0, $sp, 0x1c
  addiu $t0, %lo(blank_eeprom) # addiu $t0, $t0, -0x3760
  addiu $t2, $t0, 0x60
  move  $t3, $v0
.L7F01F3F8:
  lw    $at, ($t0)
  addiu $t0, $t0, 0xc
  addiu $t3, $t3, 0xc
  sw    $at, -0xc($t3)
  lw    $at, -8($t0)
  sw    $at, -8($t3)
  lw    $at, -4($t0)
  bne   $t0, $t2, .L7F01F3F8
   sw    $at, -4($t3)
  move  $t6, $v0
  move  $t7, $v1
  addiu $t5, $v0, 0x60
.L7F01F428:
  lw    $at, ($t6)
  addiu $t6, $t6, 0xc
  addiu $t7, $t7, 0xc
  sw    $at, -0xc($t7)
  lw    $at, -8($t6)
  sw    $at, -8($t7)
  lw    $at, -4($t6)
  bne   $t6, $t5, .L7F01F428
   sw    $at, -4($t7)
  lw    $ra, 0x14($sp)
.L7F01F450:
  addiu $sp, $sp, 0x80
  jr    $ra
   nop   
");

asm(R"
glabel copy_eepromfile_a0_from_a1_to_buffer
  li    $at, 100
  bne   $a0, $at, .L7F01F498
   lui   $t6, %hi(save6) 
  addiu $t6, %lo(save6) # addiu $t6, $t6, -0x6500
  move  $t9, $a1
  addiu $t8, $a1, 0x60
.L7F01F474:
  lw    $at, ($t9)
  addiu $t9, $t9, 0xc
  addiu $t6, $t6, 0xc
  sw    $at, -0xc($t6)
  lw    $at, -8($t9)
  sw    $at, -8($t6)
  lw    $at, -4($t9)
  bne   $t9, $t8, .L7F01F474
   sw    $at, -4($t6)
.L7F01F498:
  jr    $ra
   nop   
");

asm(R"
glabel check_for_007_mode_unlocked
  addiu $sp, $sp, -0x28
  sw    $ra, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  jal   get_save_folder_ptr
   sw    $s0, 0x18($sp)
  beqz  $v0, .L7F01F514
   move  $s1, $v0
  lbu   $t6, 9($v0)
  move  $s0, $zero
  li    $s2, 20
  andi  $t7, $t6, 1
  beqz  $t7, .L7F01F4E0
   nop   
  b     .L7F01F518
   li    $v0, 1
.L7F01F4E0:
  move  $a0, $s1
.L7F01F4E4:
  move  $a1, $s0
  jal   get_eeprom_stage_completed_for_difficulty
   li    $a2, 2
  beqz  $v0, .L7F01F504
   nop   
  addiu $s0, $s0, 1
  bnel  $s0, $s2, .L7F01F4E4
   move  $a0, $s1
.L7F01F504:
  bnel  $s0, $s2, .L7F01F518
   move  $v0, $zero
  b     .L7F01F518
   li    $v0, 1
.L7F01F514:
  move  $v0, $zero
.L7F01F518:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");
