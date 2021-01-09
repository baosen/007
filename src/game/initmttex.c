asm(R"
.late_rodata
glabel str_Mt
.word 0x2d6d7400 /*-mt*/
glabel str_Mt_0
.word 0x2d6d7400 /*-mt*/

.text
glabel set_mt_tex_alloc
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lui   $at, %hi(dword_CODE_bss_8008D090)
  lui   $a1, %hi(str_Mt)
  sw    $zero, %lo(dword_CODE_bss_8008D090)($at)
  addiu $a1, %lo(str_Mt) # addiu $a1, $a1, -0xe00
  jal   check_token
   li    $a0, 1
  beqz  $v0, .L7F007370
   li    $a0, 1
  lui   $a1, %hi(str_Mt_0)
  jal   check_token
   addiu $a1, %lo(str_Mt_0) # addiu $a1, $a1, -0xdfc
  move  $a0, $v0
  move  $a1, $zero
  jal   strtol
   move  $a2, $zero
  sll   $t6, $v0, 0xa
  lui   $at, %hi(bytes)
  sw    $t6, %lo(bytes)($at)
.L7F007370:
  lui   $a0, %hi(bytes)
  lw    $a0, %lo(bytes)($a0)
  jal   mempAllocBytesInBank
   li    $a1, 4
  lui   $a0, %hi(ptr_texture_alloc_start)
  lui   $a2, %hi(bytes)
  lw    $a2, %lo(bytes)($a2)
  addiu $a0, %lo(ptr_texture_alloc_start) # addiu $a0, $a0, -0x38e0
  jal   sub_GAME_7F0CBAF4
   move  $a1, $v0
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");
