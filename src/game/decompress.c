const unsigned int
    rz_header_bytes[] =
        {
            0x11720000, 0x11720000, 0x11720000, 0x11720000,
            0x11720000, 0x11720000, 0x11720000, 0x11720000,
            0x11720000, 0x11720000}; // This definately isn't proper way this
                                     // data was represented, but works for now.

asm(R"
glabel decompressdata
  lui   $a3, %hi(dword_CODE_bss_8008D350)
  addiu $a3, %lo(dword_CODE_bss_8008D350) # addiu $a3, $a3, -0x2cb0
  sw    $a0, ($a3)
  lui   $at, %hi(dword_CODE_bss_8008D354)
  sw    $a1, %lo(dword_CODE_bss_8008D354)($at)
  addiu $sp, $sp, -0x18
  lui   $at, %hi(dword_CODE_bss_8008D360)
  sw    $ra, 0x14($sp)
  sw    $a2, %lo(dword_CODE_bss_8008D360)($at)
  lui   $t6, %hi(rz_header_bytes) 
  lbu   $t6, %lo(rz_header_bytes)($t6)
  lbu   $v0, ($a0)
  lui   $t8, %hi(rz_header_bytes+0x5) 
  lui   $t9, %hi(rz_header_bytes+0x8) 
  bne   $v0, $t6, .L7F0CE840
   lui   $t2, %hi(rz_header_bytes+0x18) 
  lbu   $t7, 1($a0)
  lbu   $t8, %lo(rz_header_bytes+0x5)($t8)
  beql  $t7, $t8, .L7F0CE864
   lw    $t4, ($a3)
.L7F0CE840:
  lbu   $v1, -1($a0)
  lbu   $t9, %lo(rz_header_bytes+0x8)($t9)
  bnel  $v1, $t9, .L7F0CE854
   lbu   $t1, -2($a0)
  lbu   $t1, -2($a0)
.L7F0CE854:
  lbu   $t2, %lo(rz_header_bytes+0x18)($t2)
  bnel  $t1, $t2, .L7F0CE864
   lw    $t4, ($a3)
  lw    $t4, ($a3)
.L7F0CE864:
  lui   $at, %hi(dword_CODE_bss_8008D35C)
  addiu $t5, $t4, 2
  sw    $t5, ($a3)
  sw    $zero, %lo(dword_CODE_bss_8008D35C)($at)
  lui   $at, %hi(dword_CODE_bss_8008D358)
  jal   loop_to_decompress_entire_file
   sw    $zero, %lo(dword_CODE_bss_8008D358)($at)
  lw    $ra, 0x14($sp)
  lui   $v0, %hi(dword_CODE_bss_8008D35C)
  lw    $v0, %lo(dword_CODE_bss_8008D35C)($v0)
  jr    $ra
   addiu $sp, $sp, 0x18
");

asm(R"
glabel sub_GAME_7F0CE894
  lui   $t6, %hi(dword_CODE_bss_8008D350) 
  lui   $t7, %hi(dword_CODE_bss_8008D358) 
  lw    $t7, %lo(dword_CODE_bss_8008D358)($t7)
  lw    $t6, %lo(dword_CODE_bss_8008D350)($t6)
  jr    $ra
   addu  $v0, $t6, $t7
");
