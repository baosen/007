#include "players.h"

char dword_CODE_bss_80083320[0x130];
char dword_CODE_bss_80083450[0x4B0];
char dword_CODE_bss_80083900[0x4B0];
char dword_CODE_bss_80083DB0[0x4B00];

asm(R"
glabel sub_GAME_7F0BC530
  addiu $sp, $sp, -0x28
  sw    $ra, 0x24($sp)
  sw    $s0, 0x18($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  jal   getPlayerCount
   move  $s0, $zero
  blez  $v0, .L7F0BC584
   sll   $t6, $s0, 2
  lui   $t7, %hi(players_p1) 
  addiu $t7, %lo(players_p1) # addiu $t7, $t7, -0x6120
  addu  $s1, $t6, $t7
  li    $s2, -1
  lw    $t8, ($s1)
.L7F0BC568:
  addiu $s0, $s0, 1
  addiu $s1, $s1, 4
  jal   getPlayerCount
   sw    $s2, 0x108c($t8)
  slt   $at, $s0, $v0
  bnezl $at, .L7F0BC568
   lw    $t8, ($s1)
.L7F0BC584:
  lui   $v1, %hi(dword_CODE_bss_80083450)
  lui   $a0, %hi(dword_CODE_bss_80083320)
  lui   $v0, %hi(dword_CODE_bss_80083900)
  lui   $a2, %hi(dword_CODE_bss_80083DB0)
  li    $s2, -1
  addiu $a2, %lo(dword_CODE_bss_80083DB0) # addiu $a2, $a2, 0x3db0
  addiu $v0, %lo(dword_CODE_bss_80083900) # addiu $v0, $v0, 0x3900
  addiu $a0, %lo(dword_CODE_bss_80083320) # addiu $a0, $a0, 0x3320
  addiu $v1, %lo(dword_CODE_bss_80083450) # addiu $v1, $v1, 0x3450
  li    $a1, 2
.L7F0BC5AC:
  addiu $v0, $v0, 4
  sltu  $at, $v0, $a2
  addiu $v1, $v1, 4
  addiu $a0, $a0, 1
  sw    $s2, -4($v1)
  sb    $a1, -1($a0)
  bnez  $at, .L7F0BC5AC
   sw    $s2, -4($v0)
  jal   getMaxNumRooms
   move  $s0, $zero
  blez  $v0, .L7F0BC60C
   sll   $t9, $s0, 2
  addu  $t9, $t9, $s0
  lui   $t0, %hi(array_room_info) 
  addiu $t0, %lo(array_room_info) # addiu $t0, $t0, 0x1414
  sll   $t9, $t9, 4
  addu  $s1, $t9, $t0
  addiu $s0, $s0, 1
.L7F0BC5F4:
  addiu $s1, $s1, 0x50
  jal   getMaxNumRooms
   sh    $s2, -0x1a($s1)
  slt   $at, $s0, $v0
  bnezl $at, .L7F0BC5F4
   addiu $s0, $s0, 1
.L7F0BC60C:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

void sub_GAME_7F0BC624(int param_1) { pPlayer->field_108C = param_1; }

asm(R"
glabel sub_GAME_7F0BC634
  sll   $t6, $a1, 2
  addu  $t6, $t6, $a1
  sll   $t6, $t6, 4
  lui   $at, %hi(array_room_info + 0x10 +38)
  addu  $at, $at, $t6
  sh    $a0, %lo(array_room_info + 0x10 +38)($at)
  lui   $at, %hi(dword_CODE_bss_80083450)
  sll   $t7, $a0, 2
  addu  $at, $at, $t7
  jr    $ra
   sw    $a1, %lo(dword_CODE_bss_80083450)($at)
");

asm(R"
glabel sub_GAME_7F0BC660
  sll   $t6, $a1, 2
  addu  $t6, $t6, $a1
  sll   $t6, $t6, 4
  lui   $at, %hi(array_room_info + 0x10 +38)
  li    $v0, -1
  addu  $at, $at, $t6
  sh    $v0, %lo(array_room_info + 0x10 +38)($at)
  lui   $at, %hi(dword_CODE_bss_80083450)
  sll   $t7, $a0, 2
  addu  $at, $at, $t7
  jr    $ra
   sw    $v0, %lo(dword_CODE_bss_80083450)($at)
");

asm(R"
glabel sub_GAME_7F0BC690
  sll   $v0, $a0, 2
  lui   $a1, %hi(dword_CODE_bss_80083450)
  addu  $a1, $a1, $v0
  lw    $a1, %lo(dword_CODE_bss_80083450)($a1)
  addiu $sp, $sp, -0x20
  li    $at, -1
  beq   $a1, $at, .L7F0BC6C4
   sw    $ra, 0x14($sp)
  sw    $v0, 0x1c($sp)
  jal   sub_GAME_7F0BC660
   sw    $a0, 0x20($sp)
  lw    $v0, 0x1c($sp)
  lw    $a0, 0x20($sp)
.L7F0BC6C4:
  lui   $at, %hi(dword_CODE_bss_80083320)
  addu  $at, $at, $a0
  li    $t6, 2
  lw    $ra, 0x14($sp)
  sb    $t6, %lo(dword_CODE_bss_80083320)($at)
  lui   $at, %hi(dword_CODE_bss_80083900)
  addu  $at, $at, $v0
  li    $t7, -1
  sw    $t7, %lo(dword_CODE_bss_80083900)($at)
  jr    $ra
   addiu $sp, $sp, 0x20
");

asm(R"
glabel sub_GAME_7F0BC6F0
  lui   $v0, %hi(dword_CODE_bss_80083320)
  lui   $a1, %hi(dword_CODE_bss_80083900)
  addiu $a1, %lo(dword_CODE_bss_80083900) # addiu $a1, $a1, 0x3900
  addiu $v0, %lo(dword_CODE_bss_80083320) # addiu $v0, $v0, 0x3320
  move  $v1, $zero
  li    $a2, 300
  li    $a0, -1
.L7F0BC70C:
  lbu   $t6, ($v0)
  sll   $t7, $v1, 2
  addu  $t8, $a1, $t7
  slti  $at, $t6, 2
  bnezl $at, .L7F0BC73C
   lbu   $t0, 1($v0)
  lw    $t9, ($t8)
  bnel  $a0, $t9, .L7F0BC73C
   lbu   $t0, 1($v0)
  jr    $ra
   move  $v0, $v1

  lbu   $t0, 1($v0)
.L7F0BC73C:
  sll   $t1, $v1, 2
  addu  $t2, $a1, $t1
  slti  $at, $t0, 2
  bnezl $at, .L7F0BC768
   lbu   $t4, 2($v0)
  lw    $t3, 4($t2)
  bnel  $a0, $t3, .L7F0BC768
   lbu   $t4, 2($v0)
  jr    $ra
   addiu $v0, $v1, 1

  lbu   $t4, 2($v0)
.L7F0BC768:
  sll   $t5, $v1, 2
  addu  $t6, $a1, $t5
  slti  $at, $t4, 2
  bnezl $at, .L7F0BC794
   lbu   $t8, 3($v0)
  lw    $t7, 8($t6)
  bnel  $a0, $t7, .L7F0BC794
   lbu   $t8, 3($v0)
  jr    $ra
   addiu $v0, $v1, 2

  lbu   $t8, 3($v0)
.L7F0BC794:
  sll   $t9, $v1, 2
  addu  $t0, $a1, $t9
  slti  $at, $t8, 2
  bnezl $at, .L7F0BC7C0
   addiu $v1, $v1, 4
  lw    $t1, 0xc($t0)
  bnel  $a0, $t1, .L7F0BC7C0
   addiu $v1, $v1, 4
  jr    $ra
   addiu $v0, $v1, 3

  addiu $v1, $v1, 4
.L7F0BC7C0:
  bne   $v1, $a2, .L7F0BC70C
   addiu $v0, $v0, 4
  move  $v0, $zero
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0BC7D4
  addiu $sp, $sp, -0x28
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s3, 0x20($sp)
  sw    $s0, 0x14($sp)
  lui   $s1, %hi(dword_CODE_bss_80083900)
  lui   $s2, %hi(dword_CODE_bss_80083320)
  sw    $ra, 0x24($sp)
  addiu $s2, %lo(dword_CODE_bss_80083320) # addiu $s2, $s2, 0x3320
  addiu $s1, %lo(dword_CODE_bss_80083900) # addiu $s1, $s1, 0x3900
  move  $s0, $zero
  li    $s3, 300
.L7F0BC804:
  lw    $t6, ($s1)
  addu  $v0, $s2, $s0
  bltzl $t6, .L7F0BC838
   addiu $s0, $s0, 1
  lbu   $t7, ($v0)
  addiu $t8, $t7, 1
  andi  $t9, $t8, 0xff
  slti  $at, $t9, 2
  bnez  $at, .L7F0BC834
   sb    $t8, ($v0)
  jal   sub_GAME_7F0BC690
   move  $a0, $s0
.L7F0BC834:
  addiu $s0, $s0, 1
.L7F0BC838:
  bne   $s0, $s3, .L7F0BC804
   addiu $s1, $s1, 4
  lw    $ra, 0x24($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
glabel sub_GAME_7F0BC85C
  addiu $sp, $sp, -0x70
  sll   $t7, $a0, 2
  sw    $s0, 0x18($sp)
  addu  $t7, $t7, $a0
  sll   $t7, $t7, 4
  lui   $s0, %hi(array_room_info + 0x10 +38)
  addu  $s0, $s0, $t7
  lh    $s0, %lo(array_room_info + 0x10 +38)($s0)
  li    $v0, -1
  sw    $ra, 0x1c($sp)
  beq   $s0, $v0, .L7F0BC8B8
   sw    $a0, 0x70($sp)
  lui   $t8, %hi(pPlayer) 
  lw    $t8, %lo(pPlayer)($t8)
  sll   $t0, $s0, 2
  lui   $t1, %hi(dword_CODE_bss_80083900)
  addu  $t1, $t1, $t0
  lw    $t1, %lo(dword_CODE_bss_80083900)($t1)
  lw    $t9, 0x108c($t8)
  lui   $at, %hi(dword_CODE_bss_80083320)
  addu  $at, $at, $s0
  beq   $t9, $t1, .L7F0BC8F0
   nop   
.L7F0BC8B8:
  beq   $s0, $v0, .L7F0BC8C8
   move  $a0, $s0
  jal   sub_GAME_7F0BC660
   lw    $a1, 0x70($sp)
.L7F0BC8C8:
  jal   sub_GAME_7F0BC6F0
   nop   
  move  $s0, $v0
  move  $a0, $v0
  jal   sub_GAME_7F0BC634
   lw    $a1, 0x70($sp)
  lui   $at, %hi(dword_CODE_bss_80083320)
  addu  $at, $at, $s0
  b     .L7F0BC8FC
   sb    $zero, %lo(dword_CODE_bss_80083320)($at)
.L7F0BC8F0:
  sb    $zero, %lo(dword_CODE_bss_80083320)($at)
  b     .L7F0BC9B0
   move  $v0, $s0
.L7F0BC8FC:
  lui   $t2, %hi(pPlayer) 
  lw    $t2, %lo(pPlayer)($t2)
  sll   $t4, $s0, 2
  lui   $at, %hi(dword_CODE_bss_80083900)
  lw    $t3, 0x108c($t2)
  addu  $at, $at, $t4
  addiu $a0, $sp, 0x2c
  jal   matrix_4x4_set_identity
   sw    $t3, %lo(dword_CODE_bss_80083900)($at)
  lw    $t6, 0x70($sp)
  lui   $at, %hi(room_data_float2)
  lwc1  $f0, %lo(room_data_float2)($at)
  lui   $t5, %hi(ptr_bgdata_room_fileposition_list) 
  lw    $t5, %lo(ptr_bgdata_room_fileposition_list)($t5)
  sll   $t7, $t6, 2
  subu  $t7, $t7, $t6
  sll   $t7, $t7, 3
  swc1  $f0, 0x2c($sp)
  swc1  $f0, 0x40($sp)
  swc1  $f0, 0x54($sp)
  addu  $v1, $t5, $t7
  lwc1  $f4, 0xc($v1)
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  mul.s $f6, $f4, $f0
  lui   $t0, %hi(dword_CODE_bss_80083DB0) 
  lwc1  $f8, 0x38($v0)
  addiu $t0, %lo(dword_CODE_bss_80083DB0) # addiu $t0, $t0, 0x3db0
  sll   $t8, $s0, 6
  addu  $a1, $t8, $t0
  addiu $a0, $sp, 0x2c
  sub.s $f10, $f6, $f8
  swc1  $f10, 0x5c($sp)
  lwc1  $f16, 0x10($v1)
  lwc1  $f4, 0x3c($v0)
  mul.s $f18, $f16, $f0
  sub.s $f6, $f18, $f4
  swc1  $f6, 0x60($sp)
  lwc1  $f8, 0x14($v1)
  lwc1  $f16, 0x40($v0)
  mul.s $f10, $f8, $f0
  sub.s $f18, $f10, $f16
  jal   sub_GAME_7F058C9C
   swc1  $f18, 0x64($sp)
  move  $v0, $s0
.L7F0BC9B0:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x70
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0BC9C4
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  move  $a2, $a0
  sw    $a2, 0x18($sp)
  jal   sub_GAME_7F0BC85C
   move  $a0, $a1
  lw    $v1, 0x18($sp)
  lui   $t8, %hi(dword_CODE_bss_80083DB0) 
  addiu $t8, %lo(dword_CODE_bss_80083DB0) # addiu $t8, $t8, 0x3db0
  lui   $t6, (0x01020040 >> 16) # lui $t6, 0x102
  sll   $t7, $v0, 6
  addu  $t9, $t7, $t8
  ori   $t6, (0x01020040 & 0xFFFF) # ori $t6, $t6, 0x40
  sw    $t6, ($v1)
  sw    $t9, 4($v1)
  lw    $ra, 0x14($sp)
  addiu $a2, $v1, 8
  move  $v0, $a2
  jr    $ra
   addiu $sp, $sp, 0x18
");

asm(R"
glabel sub_GAME_7F0BCA14
  lui   $t7, %hi(ptr_bgdata_room_fileposition_list) 
  lw    $t7, %lo(ptr_bgdata_room_fileposition_list)($t7)
  sll   $t6, $a0, 2
  subu  $t6, $t6, $a0
  sll   $t6, $t6, 3
  addu  $v0, $t6, $t7
  jr    $ra
   addiu $v0, $v0, 0xc
");

asm(R"
glabel sub_GAME_7F0BCA34
  lui   $v1, %hi(ptr_bgdata_room_fileposition_list)
  addiu $v1, %lo(ptr_bgdata_room_fileposition_list) # addiu $v1, $v1, -0x74
  lw    $t6, ($v1)
  sll   $v0, $a0, 2
  subu  $v0, $v0, $a0
  lui   $a2, %hi(room_data_float2)
  sll   $v0, $v0, 3
  addiu $a2, %lo(room_data_float2) # addiu $a2, $a2, 0x13f8
  addu  $t7, $t6, $v0
  lwc1  $f4, 0xc($t7)
  lwc1  $f6, ($a2)
  mul.s $f8, $f4, $f6
  swc1  $f8, ($a1)
  lw    $t8, ($v1)
  lwc1  $f16, ($a2)
  addu  $t9, $t8, $v0
  lwc1  $f10, 0x10($t9)
  mul.s $f18, $f10, $f16
  swc1  $f18, 4($a1)
  lw    $t0, ($v1)
  lwc1  $f6, ($a2)
  addu  $t1, $t0, $v0
  lwc1  $f4, 0x14($t1)
  mul.s $f8, $f4, $f6
  jr    $ra
   swc1  $f8, 8($a1)
");
