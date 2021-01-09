char light_fixture_table[0x4B0];
short cur_entry_lightfixture_table;
short index_of_cur_entry_lightfixture_table;
char word_CODE_bss_80082B18[0x800];
int dword_CODE_bss_80083318;

int D_80046030[8] = {0};

asm(R"
glabel init_lightfixture_tables
  lui   $v1, %hi(light_fixture_table)
  lui   $v0, %hi(cur_entry_lightfixture_table)
  addiu $v0, %lo(cur_entry_lightfixture_table) # addiu $v0, $v0, 0x2b10
  addiu $v1, %lo(light_fixture_table) # addiu $v1, $v1, 0x2660
.L7F0BB4E0:
  addiu $v1, $v1, 0xc
  sltu  $at, $v1, $v0
  bnez  $at, .L7F0BB4E0
   sh    $zero, -0xc($v1)
  lui   $v1, %hi(word_CODE_bss_80082B18)
  lui   $v0, %hi(dword_CODE_bss_80083318)
  addiu $v0, %lo(dword_CODE_bss_80083318) # addiu $v0, $v0, 0x3318
  addiu $v1, %lo(word_CODE_bss_80082B18) # addiu $v1, $v1, 0x2b18
.L7F0BB500:
  addiu $v1, $v1, 0x10
  sh    $zero, -0xc($v1)
  sh    $zero, -8($v1)
  sh    $zero, -4($v1)
  bne   $v1, $v0, .L7F0BB500
   sh    $zero, -0x10($v1)
  lui   $at, %hi(D_80046030)
  jr    $ra
   sw    $zero, %lo(D_80046030)($at)
");

asm(R"
glabel get_index_of_current_entry_in_init_lightfixture_table
  lui   $v0, %hi(light_fixture_table)
  addiu $v0, %lo(light_fixture_table) # addiu $v0, $v0, 0x2660
  move  $v1, $zero
  li    $a0, 100
.L7F0BB534:
  lh    $t6, ($v0)
  bnezl $t6, .L7F0BB54C
   lh    $t7, 0xc($v0)
  jr    $ra
   move  $v0, $v1

  lh    $t7, 0xc($v0)
.L7F0BB54C:
  bnezl $t7, .L7F0BB560
   lh    $t8, 0x18($v0)
  jr    $ra
   addiu $v0, $v1, 1

  lh    $t8, 0x18($v0)
.L7F0BB560:
  bnezl $t8, .L7F0BB574
   lh    $t9, 0x24($v0)
  jr    $ra
   addiu $v0, $v1, 2

  lh    $t9, 0x24($v0)
.L7F0BB574:
  bnezl $t9, .L7F0BB588
   addiu $v1, $v1, 4
  jr    $ra
   addiu $v0, $v1, 3

  addiu $v1, $v1, 4
.L7F0BB588:
  bne   $v1, $a0, .L7F0BB534
   addiu $v0, $v0, 0x30
  li    $v0, 100
  jr    $ra
   nop   
");

asm(R"
glabel add_entry_to_init_lightfixture_table
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   get_index_of_current_entry_in_init_lightfixture_table
   sw    $a0, 0x18($sp)
  lui   $a0, %hi(cur_entry_lightfixture_table)
  addiu $a0, %lo(cur_entry_lightfixture_table) # addiu $a0, $a0, 0x2b10
  sh    $v0, ($a0)
  lh    $v1, ($a0)
  li    $at, 100
  lui   $t7, %hi(light_fixture_table) 
  beq   $v1, $at, .L7F0BB5F0
   sll   $t6, $v1, 2
  subu  $t6, $t6, $v1
  lui   $t8, %hi(index_of_cur_entry_lightfixture_table) 
  lh    $t8, %lo(index_of_cur_entry_lightfixture_table)($t8)
  lw    $t9, 0x18($sp)
  sll   $t6, $t6, 2
  addiu $t7, %lo(light_fixture_table) # addiu $t7, $t7, 0x2660
  addu  $v0, $t6, $t7
  sh    $t8, ($v0)
  sw    $t9, 4($v0)
.L7F0BB5F0:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel save_ptrDL_enpoint_to_current_init_lightfixture_table
  lui   $v0, %hi(cur_entry_lightfixture_table)
  lh    $v0, %lo(cur_entry_lightfixture_table)($v0)
  li    $at, 100
  beq   $v0, $at, .L7F0BB628
   sll   $t6, $v0, 2
  subu  $t6, $t6, $v0
  sll   $t6, $t6, 2
  lui   $at, %hi(light_fixture_table+8)
  addu  $at, $at, $t6
  sw    $a0, %lo(light_fixture_table+8)($at)
.L7F0BB628:
  jr    $ra
   nop   
");

asm(R"
glabel check_if_imageID_is_light
  li    $at, 201
  beq   $a0, $at, .L7F0BB684
   li    $at, 203
  beq   $a0, $at, .L7F0BB684
   li    $at, 205
  beq   $a0, $at, .L7F0BB684
   li    $at, 252
  beq   $a0, $at, .L7F0BB684
   li    $at, 254
  beq   $a0, $at, .L7F0BB684
   li    $at, 255
  beq   $a0, $at, .L7F0BB684
   li    $at, 256
  beq   $a0, $at, .L7F0BB684
   li    $at, 428
  beq   $a0, $at, .L7F0BB684
   li    $at, 982
  beq   $a0, $at, .L7F0BB684
   li    $at, 1383
  bne   $a0, $at, .L7F0BB68C
   move  $v0, $zero
.L7F0BB684:
  jr    $ra
   li    $v0, 1

.L7F0BB68C:
  jr    $ra
   nop   
");

asm(R"
glabel return_ptr_vertex_of_entry_room
  lb    $t6, ($a0)
  li    $v0, 4
  sll   $t9, $a1, 2
  beq   $v0, $t6, .L7F0BB6B8
   addu  $t9, $t9, $a1
  lb    $t7, -8($a0)
.L7F0BB6AC:
  addiu $a0, $a0, -8
  bnel  $v0, $t7, .L7F0BB6AC
   lb    $t7, -8($a0)
.L7F0BB6B8:
  lw    $v1, 4($a0)
  lui   $at, 0xff00
  sll   $t9, $t9, 4
  and   $t8, $v1, $at
  lui   $at, 0xe00
  bne   $t8, $at, .L7F0BB6EC
   lui   $t0, %hi(array_room_info + 0x4)
  addu  $t0, $t0, $t9
  lw    $t0, %lo(array_room_info + 0x4)($t0)
  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
  and   $t1, $v1, $at
  addu  $v1, $t0, $t1
.L7F0BB6EC:
  jr    $ra
   move  $v0, $v1
");

asm(R"
.late_rodata
/*D:80058D80*/
glabel jpt_80058D80
.word .L7F0BB714
.word .L7F0BB7C0
.word .L7F0BB7EC
.word .L7F0BB818
.word .L7F0BB844
.text
glabel sub_GAME_7F0BB6F4
  sltiu $at, $a1, 5
  beqz  $at, .L7F0BB86C
   sll   $t6, $a1, 2
  lui   $at, %hi(jpt_80058D80)
  addu  $at, $at, $t6
  lw    $t6, %lo(jpt_80058D80)($at)
  jr    $t6
   nop   
.L7F0BB714:
  li    $v0, 10
  lbu   $t7, 5($a0)
  div   $zero, $t7, $v0
  mflo  $t8
  sw    $t8, ($a2)
  lbu   $t9, 6($a0)
  bnez  $v0, .L7F0BB738
   nop   
  break 7
.L7F0BB738:
  li    $at, -1
  bne   $v0, $at, .L7F0BB750
   lui   $at, 0x8000
  bne   $t7, $at, .L7F0BB750
   nop   
  break 6
.L7F0BB750:
  div   $zero, $t9, $v0
  mflo  $t0
  sw    $t0, ($a3)
  lbu   $t1, 7($a0)
  bnez  $v0, .L7F0BB76C
   nop   
  break 7
.L7F0BB76C:
  li    $at, -1
  bne   $v0, $at, .L7F0BB784
   lui   $at, 0x8000
  bne   $t9, $at, .L7F0BB784
   nop   
  break 6
.L7F0BB784:
  div   $zero, $t1, $v0
  lw    $t3, 0x10($sp)
  mflo  $t2
  bnez  $v0, .L7F0BB79C
   nop   
  break 7
.L7F0BB79C:
  li    $at, -1
  bne   $v0, $at, .L7F0BB7B4
   lui   $at, 0x8000
  bne   $t1, $at, .L7F0BB7B4
   nop   
  break 6
.L7F0BB7B4:
  sw    $t2, ($t3)
  jr    $ra
   nop   
.L7F0BB7C0:
  lw    $t4, 4($a0)
  andi  $t5, $t4, 0xf
  sw    $t5, ($a2)
  lbu   $t6, 7($a0)
  srl   $t7, $t6, 4
  sw    $t7, ($a3)
  lw    $t8, ($a0)
  lw    $t0, 0x10($sp)
  andi  $t9, $t8, 0xf
  jr    $ra
   sw    $t9, ($t0)
.L7F0BB7EC:
  lbu   $t1, 6($a0)
  andi  $t2, $t1, 0xf
  sw    $t2, ($a2)
  lhu   $t3, 6($a0)
  srl   $t4, $t3, 0xc
  sw    $t4, ($a3)
  lbu   $t5, 3($a0)
  lw    $t7, 0x10($sp)
  srl   $t6, $t5, 4
  jr    $ra
   sw    $t6, ($t7)
.L7F0BB818:
  lhu   $t8, 4($a0)
  andi  $t9, $t8, 0xf
  sw    $t9, ($a2)
  lbu   $t0, 5($a0)
  srl   $t1, $t0, 4
  sw    $t1, ($a3)
  lbu   $t2, 2($a0)
  lw    $t4, 0x10($sp)
  andi  $t3, $t2, 0xf
  jr    $ra
   sw    $t3, ($t4)
.L7F0BB844:
  lbu   $t5, 4($a0)
  andi  $t6, $t5, 0xf
  sw    $t6, ($a2)
  lw    $t7, 4($a0)
  srl   $t8, $t7, 0x1c
  sw    $t8, ($a3)
  lhu   $t9, 2($a0)
  lw    $t1, 0x10($sp)
  srl   $t0, $t9, 0xc
  sw    $t0, ($t1)
def_7F0BB70C:
.L7F0BB86C:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0BB874
  addiu $sp, $sp, -0x30
  sw    $ra, 0x1c($sp)
  sw    $a2, 0x38($sp)
  sw    $a3, 0x3c($sp)
  addiu $t6, $sp, 0x24
  sw    $a0, 0x30($sp)
  sw    $t6, 0x10($sp)
  addiu $a3, $sp, 0x28
  jal   sub_GAME_7F0BB6F4
   addiu $a2, $sp, 0x2c
  lw    $a0, 0x30($sp)
  jal   return_ptr_vertex_of_entry_room
   lw    $a1, 0x38($sp)
  lw    $t7, 0x2c($sp)
  lw    $a1, 0x3c($sp)
  lw    $v1, 0x40($sp)
  sll   $t8, $t7, 4
  addu  $t9, $v0, $t8
  lh    $t0, ($t9)
  lw    $a0, 0x44($sp)
  sh    $t0, ($a1)
  lw    $t1, 0x2c($sp)
  sll   $t2, $t1, 4
  addu  $t3, $v0, $t2
  lh    $t4, 2($t3)
  sh    $t4, 2($a1)
  lw    $t5, 0x2c($sp)
  sll   $t6, $t5, 4
  addu  $t7, $v0, $t6
  lh    $t8, 4($t7)
  sh    $t8, 4($a1)
  lw    $t9, 0x28($sp)
  sll   $t0, $t9, 4
  addu  $t1, $v0, $t0
  lh    $t2, ($t1)
  sh    $t2, ($v1)
  lw    $t3, 0x28($sp)
  sll   $t4, $t3, 4
  addu  $t5, $v0, $t4
  lh    $t6, 2($t5)
  sh    $t6, 2($v1)
  lw    $t7, 0x28($sp)
  sll   $t8, $t7, 4
  addu  $t9, $v0, $t8
  lh    $t0, 4($t9)
  sh    $t0, 4($v1)
  lw    $t1, 0x24($sp)
  sll   $t2, $t1, 4
  addu  $t3, $v0, $t2
  lh    $t4, ($t3)
  sh    $t4, ($a0)
  lw    $t5, 0x24($sp)
  sll   $t6, $t5, 4
  addu  $t7, $v0, $t6
  lh    $t8, 2($t7)
  sh    $t8, 2($a0)
  lw    $t9, 0x24($sp)
  sll   $t0, $t9, 4
  addu  $t1, $v0, $t0
  lh    $t2, 4($t1)
  sh    $t2, 4($a0)
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0BB978
  sll   $t6, $a0, 2
  addu  $t6, $t6, $a0
  sll   $t6, $t6, 4
  lui   $v0, %hi(array_room_info + 0x4)
  addu  $v0, $v0, $t6
  lui   $a1, %hi(word_CODE_bss_80082B18)
  lui   $a2, %hi(dword_CODE_bss_80083318)
  lw    $v0, %lo(array_room_info + 0x4)($v0)
  addiu $a2, %lo(dword_CODE_bss_80083318) # addiu $a2, $a2, 0x3318
  addiu $a1, %lo(word_CODE_bss_80082B18) # addiu $a1, $a1, 0x2b18
  lhu   $t7, ($a1)
.L7F0BB9A4:
  bnel  $a0, $t7, .L7F0BBA10
   addiu $a1, $a1, 4
  lhu   $t8, 2($a1)
  sll   $t9, $t8, 4
  addu  $v1, $v0, $t9
  lbu   $t0, 0xc($v1)
  srl   $t1, $t0, 2
  sb    $t1, 0xc($v1)
  lhu   $t2, 2($a1)
  sll   $t3, $t2, 4
  addu  $v1, $v0, $t3
  lbu   $t4, 0xd($v1)
  srl   $t5, $t4, 2
  sb    $t5, 0xd($v1)
  lhu   $t6, 2($a1)
  sll   $t7, $t6, 4
  addu  $v1, $v0, $t7
  lbu   $t8, 0xe($v1)
  srl   $t9, $t8, 2
  sb    $t9, 0xe($v1)
  lhu   $t0, 2($a1)
  sll   $t1, $t0, 4
  addu  $v1, $v0, $t1
  lbu   $t2, 0xf($v1)
  srl   $t3, $t2, 2
  sb    $t3, 0xf($v1)
  addiu $a1, $a1, 4
.L7F0BBA10:
  bnel  $a1, $a2, .L7F0BB9A4
   lhu   $t7, ($a1)
  jr    $ra
   nop   

");

asm(R"
glabel sub_GAME_7F0BBA20
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  jal   sub_GAME_7F0BBADC
   sw    $a1, 0x1c($sp)
  lw    $a0, 0x18($sp)
  bnez  $v0, .L7F0BBACC
   lw    $a2, 0x1c($sp)
  sll   $t6, $a2, 2
  lui   $a1, %hi(D_80046030)
  addu  $t6, $t6, $a2
  addiu $a1, %lo(D_80046030) # addiu $a1, $a1, 0x6030
  sll   $t6, $t6, 4
  lui   $t7, %hi(array_room_info + 0x4)
  lw    $t9, ($a1)
  addu  $t7, $t7, $t6
  lw    $t7, %lo(array_room_info + 0x4)($t7)
  lui   $t1, %hi(word_CODE_bss_80082B18) 
  addiu $t1, %lo(word_CODE_bss_80082B18) # addiu $t1, $t1, 0x2b18
  sll   $t0, $t9, 2
  addu  $v0, $t0, $t1
  subu  $v1, $a0, $t7
  srl   $t8, $v1, 4
  sh    $a2, ($v0)
  sh    $t8, 2($v0)
  lbu   $t2, 0xc($a0)
  lbu   $t4, 0xd($a0)
  lbu   $t6, 0xe($a0)
  lbu   $t8, 0xf($a0)
  srl   $t3, $t2, 2
  srl   $t5, $t4, 2
  srl   $t7, $t6, 2
  srl   $t9, $t8, 2
  sb    $t3, 0xc($a0)
  sb    $t5, 0xd($a0)
  sb    $t7, 0xe($a0)
  sb    $t9, 0xf($a0)
  lw    $t0, ($a1)
  addiu $t1, $t0, 1
  slti  $at, $t1, 0x200
  bnez  $at, .L7F0BBACC
   sw    $t1, ($a1)
  sw    $zero, ($a1)
.L7F0BBACC:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0BBADC
  sll   $t6, $a1, 2
  addu  $t6, $t6, $a1
  sll   $t6, $t6, 4
  lui   $t7, %hi(array_room_info + 0x4)
  addu  $t7, $t7, $t6
  lw    $t7, %lo(array_room_info + 0x4)($t7)
  lui   $a2, %hi(word_CODE_bss_80082B18)
  lui   $v1, %hi(dword_CODE_bss_80083318)
  subu  $v0, $a0, $t7
  srl   $t8, $v0, 4
  move  $v0, $t8
  addiu $v1, %lo(dword_CODE_bss_80083318) # addiu $v1, $v1, 0x3318
  addiu $a2, %lo(word_CODE_bss_80082B18) # addiu $a2, $a2, 0x2b18
  lhu   $t9, ($a2)
.L7F0BBB14:
  bnel  $a1, $t9, .L7F0BBB34
   lhu   $t1, 4($a2)
  lhu   $t0, 2($a2)
  bnel  $v0, $t0, .L7F0BBB34
   lhu   $t1, 4($a2)
  jr    $ra
   li    $v0, 1

  lhu   $t1, 4($a2)
.L7F0BBB34:
  bnel  $a1, $t1, .L7F0BBB54
   lhu   $t3, 8($a2)
  lhu   $t2, 6($a2)
  bnel  $v0, $t2, .L7F0BBB54
   lhu   $t3, 8($a2)
  jr    $ra
   li    $v0, 1

  lhu   $t3, 8($a2)
.L7F0BBB54:
  bnel  $a1, $t3, .L7F0BBB74
   lhu   $t5, 0xc($a2)
  lhu   $t4, 0xa($a2)
  bnel  $v0, $t4, .L7F0BBB74
   lhu   $t5, 0xc($a2)
  jr    $ra
   li    $v0, 1

  lhu   $t5, 0xc($a2)
.L7F0BBB74:
  bnel  $a1, $t5, .L7F0BBB94
   addiu $a2, $a2, 0x10
  lhu   $t6, 0xe($a2)
  bnel  $v0, $t6, .L7F0BBB94
   addiu $a2, $a2, 0x10
  jr    $ra
   li    $v0, 1

  addiu $a2, $a2, 0x10
.L7F0BBB94:
  bnel  $a2, $v1, .L7F0BBB14
   lhu   $t9, ($a2)
  move  $v0, $zero
  jr    $ra
   nop  
");

asm(R"
glabel sub_GAME_7F0BBBA8
  addiu $sp, $sp, -0x38
  sw    $ra, 0x1c($sp)
  sw    $a2, 0x40($sp)
  addiu $t6, $sp, 0x28
  sw    $a0, 0x38($sp)
  sw    $t6, 0x10($sp)
  addiu $a2, $sp, 0x30
  jal   sub_GAME_7F0BB6F4
   addiu $a3, $sp, 0x2c
  lw    $a0, 0x38($sp)
  jal   return_ptr_vertex_of_entry_room
   lw    $a1, 0x40($sp)
  lw    $t7, 0x30($sp)
  sw    $v0, 0x24($sp)
  lw    $a1, 0x40($sp)
  sll   $t8, $t7, 4
  jal   sub_GAME_7F0BBA20
   addu  $a0, $t8, $v0
  lw    $t9, 0x2c($sp)
  lw    $t1, 0x24($sp)
  lw    $a1, 0x40($sp)
  sll   $t0, $t9, 4
  jal   sub_GAME_7F0BBA20
   addu  $a0, $t0, $t1
  lw    $t2, 0x28($sp)
  lw    $t4, 0x24($sp)
  lw    $a1, 0x40($sp)
  sll   $t3, $t2, 4
  jal   sub_GAME_7F0BBA20
   addu  $a0, $t3, $t4
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0BBC30
  addiu $sp, $sp, -0x40
  sw    $ra, 0x1c($sp)
  sw    $a2, 0x48($sp)
  addiu $t6, $sp, 0x30
  sw    $a0, 0x40($sp)
  sw    $t6, 0x10($sp)
  addiu $a2, $sp, 0x38
  jal   sub_GAME_7F0BB6F4
   addiu $a3, $sp, 0x34
  lw    $a0, 0x40($sp)
  jal   return_ptr_vertex_of_entry_room
   lw    $a1, 0x48($sp)
  lw    $t7, 0x34($sp)
  sw    $v0, 0x2c($sp)
  lw    $a1, 0x48($sp)
  sll   $t8, $t7, 4
  jal   sub_GAME_7F0BBADC
   addu  $a0, $t8, $v0
  lw    $t9, 0x38($sp)
  lw    $t1, 0x2c($sp)
  sw    $v0, 0x24($sp)
  sll   $t0, $t9, 4
  lw    $a1, 0x48($sp)
  jal   sub_GAME_7F0BBADC
   addu  $a0, $t0, $t1
  lw    $t2, 0x30($sp)
  lw    $t4, 0x2c($sp)
  sw    $v0, 0x28($sp)
  sll   $t3, $t2, 4
  lw    $a1, 0x48($sp)
  jal   sub_GAME_7F0BBADC
   addu  $a0, $t3, $t4
  lw    $t5, 0x28($sp)
  lw    $ra, 0x1c($sp)
  lw    $t7, 0x24($sp)
  addu  $t6, $v0, $t5
  addiu $sp, $sp, 0x40
  jr    $ra
   addu  $v0, $t6, $t7
");

asm(R"
glabel sub_GAME_7F0BBCCC
  addiu $sp, $sp, -0x48
  sw    $fp, 0x40($sp)
  sw    $s6, 0x38($sp)
  sw    $s3, 0x2c($sp)
  sdc1  $f20, 0x18($sp)
  li    $at, 0x42C80000 # 100.000000
  sw    $s7, 0x3c($sp)
  sw    $s5, 0x34($sp)
  sw    $s4, 0x30($sp)
  lui   $s3, %hi(word_CODE_bss_80082B18)
  lui   $s6, %hi(array_room_info)
  lui   $fp, %hi(dword_CODE_bss_80083318) 
  mtc1  $at, $f20
  move  $s4, $a0
  move  $s5, $a1
  sw    $ra, 0x44($sp)
  sw    $s2, 0x28($sp)
  sw    $s1, 0x24($sp)
  sw    $s0, 0x20($sp)
  addiu $fp, %lo(dword_CODE_bss_80083318) # addiu $fp, $fp, 0x3318
  addiu $s6, %lo(array_room_info) # addiu $s6, $s6, 0x1414
  addiu $s3, %lo(word_CODE_bss_80082B18) # addiu $s3, $s3, 0x2b18
  li    $s7, 80
  lhu   $t6, ($s3)
.L7F0BBD2C:
  bnel  $s5, $t6, .L7F0BBDCC
   addiu $s3, $s3, 4
  multu $s5, $s7
  lhu   $t7, 2($s3)
  lh    $t3, ($s4)
  lh    $t5, 2($s4)
  sll   $t8, $t7, 4
  lh    $t7, 4($s4)
  mflo  $t9
  addu  $t0, $s6, $t9
  lw    $t1, 4($t0)
  addu  $v0, $t8, $t1
  lh    $t2, ($v0)
  lh    $t4, 2($v0)
  lh    $t6, 4($v0)
  subu  $s0, $t2, $t3
  subu  $s1, $t4, $t5
  bgez  $s0, .L7F0BBD7C
   subu  $s2, $t6, $t7
  negu  $s0, $s0
.L7F0BBD7C:
  bgez  $s1, .L7F0BBD88
   nop   
  negu  $s1, $s1
.L7F0BBD88:
  bgez  $s2, .L7F0BBD94
   nop   
  negu  $s2, $s2
.L7F0BBD94:
  jal   get_room_data_float1
   nop   
  mul.s $f4, $f0, $f20
  addu  $t9, $s0, $s1
  addu  $t0, $t9, $s2
  trunc.w.s $f6, $f4
  mfc1  $t1, $f6
  nop   
  slt   $at, $t0, $t1
  beql  $at, $zero, .L7F0BBDCC
   addiu $s3, $s3, 4
  b     .L7F0BBDD8
   li    $v0, 1
  addiu $s3, $s3, 4
.L7F0BBDCC:
  bnel  $s3, $fp, .L7F0BBD2C
   lhu   $t6, ($s3)
  move  $v0, $zero
.L7F0BBDD8:
  lw    $ra, 0x44($sp)
  ldc1  $f20, 0x18($sp)
  lw    $s0, 0x20($sp)
  lw    $s1, 0x24($sp)
  lw    $s2, 0x28($sp)
  lw    $s3, 0x2c($sp)
  lw    $s4, 0x30($sp)
  lw    $s5, 0x34($sp)
  lw    $s6, 0x38($sp)
  lw    $s7, 0x3c($sp)
  lw    $fp, 0x40($sp)
  jr    $ra
   addiu $sp, $sp, 0x48
");

asm(R"
glabel sub_GAME_7F0BBE0C
  addiu $sp, $sp, -0xf8
  sw    $s2, 0x44($sp)
  sw    $s1, 0x40($sp)
  sw    $s0, 0x3c($sp)
  lui   $s2, %hi(light_fixture_table)
  lui   $v0, %hi(cur_entry_lightfixture_table)
  move  $s0, $a0
  move  $s1, $a1
  sw    $ra, 0x5c($sp)
  sw    $s7, 0x58($sp)
  sw    $s6, 0x54($sp)
  sw    $s5, 0x50($sp)
  sw    $s4, 0x4c($sp)
  sw    $s3, 0x48($sp)
  sdc1  $f26, 0x30($sp)
  sdc1  $f24, 0x28($sp)
  sdc1  $f22, 0x20($sp)
  sdc1  $f20, 0x18($sp)
  move  $a3, $a2
  addiu $v0, %lo(cur_entry_lightfixture_table) # addiu $v0, $v0, 0x2b10
  addiu $s2, %lo(light_fixture_table) # addiu $s2, $s2, 0x2660
  lh    $a2, ($s2)
.L7F0BBE64:
  bnel  $a3, $a2, .L7F0BC480
   addiu $s2, $s2, 0xc
  lw    $t6, 4($s2)
  sltu  $at, $s0, $t6
  bnezl $at, .L7F0BC480
   addiu $s2, $s2, 0xc
  lw    $t7, 8($s2)
  sltu  $at, $s0, $t7
  beqz  $at, .L7F0BC47C
   move  $a0, $s0
  jal   sub_GAME_7F0BBC30
   move  $a1, $s1
  bnez  $v0, .L7F0BC488
   move  $a0, $s0
  move  $a1, $s1
  jal   sub_GAME_7F0BBBA8
   lh    $a2, ($s2)
  addiu $t8, $sp, 0xe8
  addiu $t9, $sp, 0xe0
  sw    $t9, 0x14($sp)
  sw    $t8, 0x10($sp)
  move  $a0, $s0
  move  $a1, $s1
  lh    $a2, ($s2)
  jal   sub_GAME_7F0BB874
   addiu $a3, $sp, 0xf0
  lh    $v0, 0xf0($sp)
  lh    $a1, 0xe8($sp)
  lh    $a2, 0xe0($sp)
  lh    $v1, 0xf2($sp)
  subu  $s0, $v0, $a1
  sll   $t3, $s0, 0x10
  sra   $s0, $t3, 0x10
  multu $s0, $s0
  lh    $a3, 0xea($sp)
  subu  $s4, $v0, $a2
  sll   $t5, $s4, 0x10
  sra   $s4, $t5, 0x10
  subu  $s1, $v1, $a3
  sll   $t9, $s1, 0x10
  sra   $s1, $t9, 0x10
  lh    $t0, 0xe2($sp)
  lh    $a0, 0xf4($sp)
  mflo  $t5
  lh    $t1, 0xec($sp)
  subu  $s7, $a1, $a2
  multu $s1, $s1
  subu  $t6, $a3, $t0
  sll   $t7, $s7, 0x10
  sh    $t6, 0xb4($sp)
  sra   $s7, $t7, 0x10
  subu  $s3, $a0, $t1
  sll   $t7, $s3, 0x10
  sra   $s3, $t7, 0x10
  lh    $t2, 0xe4($sp)
  subu  $s5, $v1, $t0
  mflo  $t6
  subu  $s6, $a0, $t2
  sll   $t9, $s6, 0x10
  multu $s3, $s3
  sra   $s6, $t9, 0x10
  addu  $t7, $t5, $t6
  sll   $t4, $s5, 0x10
  sra   $s5, $t4, 0x10
  subu  $t4, $t1, $t2
  sh    $t4, 0xae($sp)
  mflo  $t8
  addu  $t9, $t7, $t8
  mtc1  $t9, $f4
  jal   sqrtf
   cvt.s.w $f12, $f4
  jal   get_room_data_float2
   mov.s $f20, $f0
  multu $s4, $s4
  mul.s $f6, $f0, $f20
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f26
  nop   
  div.s $f8, $f26, $f6
  mflo  $t3
  nop   
  nop   
  multu $s5, $s5
  mflo  $t4
  addu  $t5, $t3, $t4
  nop   
  multu $s6, $s6
  swc1  $f8, 0xa8($sp)
  mflo  $t6
  addu  $t7, $t5, $t6
  mtc1  $t7, $f10
  jal   sqrtf
   cvt.s.w $f12, $f10
  jal   get_room_data_float2
   mov.s $f20, $f0
  multu $s7, $s7
  lh    $v0, 0xb4($sp)
  mul.s $f16, $f0, $f20
  lh    $v1, 0xae($sp)
  div.s $f18, $f26, $f16
  mflo  $t8
  nop   
  nop   
  multu $v0, $v0
  mflo  $t9
  addu  $t3, $t8, $t9
  nop   
  multu $v1, $v1
  swc1  $f18, 0xa4($sp)
  mflo  $t4
  addu  $t5, $t3, $t4
  mtc1  $t5, $f4
  jal   sqrtf
   cvt.s.w $f12, $f4
  jal   get_room_data_float2
   mov.s $f20, $f0
  mul.s $f6, $f0, $f20
  lh    $a0, ($s2)
  addiu $a1, $sp, 0x94
  div.s $f8, $f26, $f6
  jal   sub_GAME_7F0BCA34
   swc1  $f8, 0xa0($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f24
  mtc1  $zero, $f22
  nop   
  c.lt.s $f22, $f24
  mov.s $f20, $f22
  bc1fl .L7F0BC14C
   c.lt.s $f22, $f24
  mtc1  $s0, $f10
  mtc1  $s1, $f18
  mtc1  $s3, $f6
  cvt.s.w $f16, $f10
  addiu $s0, $sp, 0x88
  cvt.s.w $f4, $f18
  swc1  $f16, 0x6c($sp)
  cvt.s.w $f8, $f6
  swc1  $f4, 0x68($sp)
  swc1  $f8, 0x64($sp)
.L7F0BC094:
  jal   get_room_data_float2
   nop   
  lh    $a1, 0xe8($sp)
  lwc1  $f18, 0x6c($sp)
  mtc1  $a1, $f10
  mul.s $f4, $f18, $f20
  cvt.s.w $f16, $f10
  lwc1  $f10, 0x94($sp)
  add.s $f6, $f16, $f4
  mul.s $f8, $f6, $f0
  add.s $f18, $f10, $f8
  jal   get_room_data_float2
   swc1  $f18, 0x88($sp)
  lh    $a3, 0xea($sp)
  lwc1  $f6, 0x68($sp)
  mtc1  $a3, $f16
  mul.s $f10, $f6, $f20
  cvt.s.w $f4, $f16
  lwc1  $f16, 0x98($sp)
  add.s $f8, $f4, $f10
  mul.s $f18, $f8, $f0
  add.s $f6, $f16, $f18
  jal   get_room_data_float2
   swc1  $f6, 0x8c($sp)
  lh    $t1, 0xec($sp)
  lwc1  $f8, 0x64($sp)
  mfc1  $a1, $f22
  mtc1  $t1, $f4
  mul.s $f16, $f8, $f20
  mfc1  $a2, $f26
  move  $a0, $s0
  cvt.s.w $f10, $f4
  lwc1  $f4, 0x9c($sp)
  add.s $f18, $f10, $f16
  mul.s $f6, $f18, $f0
  add.s $f8, $f4, $f6
  jal   sub_GAME_7F0A2160
   swc1  $f8, 0x90($sp)
  lwc1  $f10, 0xa8($sp)
  add.s $f20, $f20, $f10
  c.lt.s $f20, $f24
  nop   
  bc1t  .L7F0BC094
   nop   
  mov.s $f20, $f22
  c.lt.s $f22, $f24
.L7F0BC14C:
  addiu $s0, $sp, 0x88
  bc1fl .L7F0BC234
   c.lt.s $f22, $f24
  mtc1  $s4, $f16
  mtc1  $s5, $f4
  mtc1  $s6, $f8
  cvt.s.w $f18, $f16
  cvt.s.w $f6, $f4
  swc1  $f18, 0x6c($sp)
  cvt.s.w $f10, $f8
  swc1  $f6, 0x68($sp)
  swc1  $f10, 0x64($sp)
.L7F0BC17C:
  jal   get_room_data_float2
   nop   
  lh    $a2, 0xe0($sp)
  lwc1  $f4, 0x6c($sp)
  mtc1  $a2, $f16
  mul.s $f6, $f4, $f20
  cvt.s.w $f18, $f16
  lwc1  $f16, 0x94($sp)
  add.s $f8, $f18, $f6
  mul.s $f10, $f8, $f0
  add.s $f4, $f16, $f10
  jal   get_room_data_float2
   swc1  $f4, 0x88($sp)
  lh    $t0, 0xe2($sp)
  lwc1  $f8, 0x68($sp)
  mtc1  $t0, $f18
  mul.s $f16, $f8, $f20
  cvt.s.w $f6, $f18
  lwc1  $f18, 0x98($sp)
  add.s $f10, $f6, $f16
  mul.s $f4, $f10, $f0
  add.s $f8, $f18, $f4
  jal   get_room_data_float2
   swc1  $f8, 0x8c($sp)
  lh    $t2, 0xe4($sp)
  lwc1  $f10, 0x64($sp)
  mfc1  $a1, $f22
  mtc1  $t2, $f6
  mul.s $f18, $f10, $f20
  mfc1  $a2, $f26
  move  $a0, $s0
  cvt.s.w $f16, $f6
  lwc1  $f6, 0x9c($sp)
  add.s $f4, $f16, $f18
  mul.s $f8, $f4, $f0
  add.s $f10, $f6, $f8
  jal   sub_GAME_7F0A2160
   swc1  $f10, 0x90($sp)
  lwc1  $f16, 0xa4($sp)
  add.s $f20, $f20, $f16
  c.lt.s $f20, $f24
  nop   
  bc1t  .L7F0BC17C
   nop   
  mov.s $f20, $f22
  c.lt.s $f22, $f24
.L7F0BC234:
  nop   
  bc1fl .L7F0BC320
   lw    $s3, 4($s2)
  lh    $t6, 0xb4($sp)
  lh    $t7, 0xae($sp)
  mtc1  $s7, $f18
  mtc1  $t6, $f6
  mtc1  $t7, $f10
  cvt.s.w $f4, $f18
  cvt.s.w $f8, $f6
  swc1  $f4, 0x6c($sp)
  cvt.s.w $f16, $f10
  swc1  $f8, 0x68($sp)
  swc1  $f16, 0x64($sp)
.L7F0BC26C:
  jal   get_room_data_float2
   nop   
  lh    $a2, 0xe0($sp)
  lwc1  $f6, 0x6c($sp)
  mtc1  $a2, $f18
  mul.s $f8, $f6, $f20
  cvt.s.w $f4, $f18
  lwc1  $f18, 0x94($sp)
  add.s $f10, $f4, $f8
  mul.s $f16, $f10, $f0
  add.s $f6, $f18, $f16
  jal   get_room_data_float2
   swc1  $f6, 0x88($sp)
  lh    $t0, 0xe2($sp)
  lwc1  $f10, 0x68($sp)
  mtc1  $t0, $f4
  mul.s $f18, $f10, $f20
  cvt.s.w $f8, $f4
  lwc1  $f4, 0x98($sp)
  add.s $f16, $f8, $f18
  mul.s $f6, $f16, $f0
  add.s $f10, $f4, $f6
  jal   get_room_data_float2
   swc1  $f10, 0x8c($sp)
  lh    $t2, 0xe4($sp)
  lwc1  $f16, 0x64($sp)
  mfc1  $a1, $f22
  mtc1  $t2, $f8
  mul.s $f4, $f16, $f20
  mfc1  $a2, $f26
  move  $a0, $s0
  cvt.s.w $f18, $f8
  lwc1  $f8, 0x9c($sp)
  add.s $f6, $f18, $f4
  mul.s $f10, $f6, $f0
  add.s $f16, $f8, $f10
  jal   sub_GAME_7F0A2160
   swc1  $f16, 0x90($sp)
  lwc1  $f18, 0xa0($sp)
  add.s $f20, $f20, $f18
  c.lt.s $f20, $f24
  nop   
  bc1t  .L7F0BC26C
   nop   
  lw    $s3, 4($s2)
.L7F0BC320:
  lw    $v1, 8($s2)
  li    $s7, 4
  addiu $s6, $sp, 0xc8
  sltu  $at, $s3, $v1
  beqz  $at, .L7F0BC488
   addiu $s5, $sp, 0xd0
  addiu $s4, $sp, 0xd8
  lb    $v0, ($s3)
.L7F0BC340:
  li    $at, -65
  move  $s0, $zero
  bne   $v0, $at, .L7F0BC3CC
   move  $a0, $s3
  move  $a1, $zero
  lh    $a2, ($s2)
  move  $a3, $s4
  sw    $s5, 0x10($sp)
  jal   sub_GAME_7F0BB874
   sw    $s6, 0x14($sp)
  move  $a0, $s4
  jal   sub_GAME_7F0BBCCC
   lh    $a1, ($s2)
  beqz  $v0, .L7F0BC384
   move  $a0, $s5
  b     .L7F0BC3B0
   li    $s0, 1
.L7F0BC384:
  jal   sub_GAME_7F0BBCCC
   lh    $a1, ($s2)
  beqz  $v0, .L7F0BC39C
   move  $a0, $s6
  b     .L7F0BC3B0
   li    $s0, 1
.L7F0BC39C:
  jal   sub_GAME_7F0BBCCC
   lh    $a1, ($s2)
  beqz  $v0, .L7F0BC3B0
   nop   
  li    $s0, 1
.L7F0BC3B0:
  beqz  $s0, .L7F0BC3C4
   move  $a0, $s3
  move  $a1, $zero
  jal   sub_GAME_7F0BBBA8
   lh    $a2, ($s2)
.L7F0BC3C4:
  b     .L7F0BC464
   lw    $v1, 8($s2)
.L7F0BC3CC:
  li    $at, -79
  bne   $v0, $at, .L7F0BC464
   move  $v0, $zero
.L7F0BC3D8:
  addiu $s1, $v0, 1
  move  $s0, $zero
  move  $a1, $s1
  move  $a0, $s3
  lh    $a2, ($s2)
  move  $a3, $s4
  sw    $s5, 0x10($sp)
  jal   sub_GAME_7F0BB874
   sw    $s6, 0x14($sp)
  move  $a0, $s4
  jal   sub_GAME_7F0BBCCC
   lh    $a1, ($s2)
  beqz  $v0, .L7F0BC418
   move  $a0, $s5
  b     .L7F0BC444
   li    $s0, 1
.L7F0BC418:
  jal   sub_GAME_7F0BBCCC
   lh    $a1, ($s2)
  beqz  $v0, .L7F0BC430
   move  $a0, $s6
  b     .L7F0BC444
   li    $s0, 1
.L7F0BC430:
  jal   sub_GAME_7F0BBCCC
   lh    $a1, ($s2)
  beqz  $v0, .L7F0BC444
   nop   
  li    $s0, 1
.L7F0BC444:
  beqz  $s0, .L7F0BC458
   move  $a0, $s3
  move  $a1, $s1
  jal   sub_GAME_7F0BBBA8
   lh    $a2, ($s2)
.L7F0BC458:
  bne   $s1, $s7, .L7F0BC3D8
   move  $v0, $s1
  lw    $v1, 8($s2)
.L7F0BC464:
  addiu $s3, $s3, 8
  sltu  $at, $s3, $v1
  bnezl $at, .L7F0BC340
   lb    $v0, ($s3)
  b     .L7F0BC48C
   lw    $ra, 0x5c($sp)
.L7F0BC47C:
  addiu $s2, $s2, 0xc
.L7F0BC480:
  bnel  $s2, $v0, .L7F0BBE64
   lh    $a2, ($s2)
.L7F0BC488:
  lw    $ra, 0x5c($sp)
.L7F0BC48C:
  ldc1  $f20, 0x18($sp)
  ldc1  $f22, 0x20($sp)
  ldc1  $f24, 0x28($sp)
  ldc1  $f26, 0x30($sp)
  lw    $s0, 0x3c($sp)
  lw    $s1, 0x40($sp)
  lw    $s2, 0x44($sp)
  lw    $s3, 0x48($sp)
  lw    $s4, 0x4c($sp)
  lw    $s5, 0x50($sp)
  lw    $s6, 0x54($sp)
  lw    $s7, 0x58($sp)
  jr    $ra
   addiu $sp, $sp, 0xf8
");

asm(R"
glabel sub_GAME_7F0BC4C4
  lui   $v1, %hi(light_fixture_table)
  lui   $v0, %hi(cur_entry_lightfixture_table)
  addiu $v0, %lo(cur_entry_lightfixture_table) # addiu $v0, $v0, 0x2b10
  addiu $v1, %lo(light_fixture_table) # addiu $v1, $v1, 0x2660
  lh    $t6, ($v1)
.L7F0BC4D8:
  bnel  $a0, $t6, .L7F0BC4E8
   lh    $t7, 0xc($v1)
  sh    $zero, ($v1)
  lh    $t7, 0xc($v1)
.L7F0BC4E8:
  bnel  $a0, $t7, .L7F0BC4F8
   lh    $t8, 0x18($v1)
  sh    $zero, 0xc($v1)
  lh    $t8, 0x18($v1)
.L7F0BC4F8:
  bnel  $a0, $t8, .L7F0BC508
   lh    $t9, 0x24($v1)
  sh    $zero, 0x18($v1)
  lh    $t9, 0x24($v1)
.L7F0BC508:
  bnel  $a0, $t9, .L7F0BC518
   addiu $v1, $v1, 0x30
  sh    $zero, 0x24($v1)
  addiu $v1, $v1, 0x30
.L7F0BC518:
  bnel  $v1, $v0, .L7F0BC4D8
   lh    $t6, ($v1)
  lui   $at, %hi(index_of_cur_entry_lightfixture_table)
  jr    $ra
   sh    $a0, %lo(index_of_cur_entry_lightfixture_table)($at)
");
