int *ptr_mgfx0_alloc_start;
int *ptr_mgfx1_alloc_start;
int *ptr_mgfx_end;
int D_8008C23C;
int *ptr_mvtx0_alloc_start;
int *ptr_mvtx1_alloc_start;
int *ptr_mvtx_end;
int *ptr_mvtx_cur_pos;
int bank_in_mgfx_alloc_table;
int dword_CODE_bss_8008C254;

int D_800482E0 = 0;
int D_800482E4[] = {0x10000, 0x18000, 0x20000};
int D_800482F0[] = {0x28000, 0x10000, 0x18000, 0x20000, 0x28000};

char membars_string1[] = ">>>>>>>>>>>>>>>>>>>>>>>>>";
char membars_string2[] = "=========================";
char membars_string3[] = "-------------------------";

void something_with_dyn_c_debug(void) {
  get_ptr_debug_notice_list_entry(&D_800482E0, "dyn_c_debug");
}

const char aMgfx[] = "-mgfx";
const char aMgfx_1[] = "-mgfx";
const char aMvtx[] = "-mvtx";
const char aMvtx_0[] = "-mvtx";

asm(R"
glabel set_vtx_gfx_mem_alloc
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  lui   $a1, %hi(aMgfx)
  addiu $a1, %lo(aMgfx) # addiu $a1, $a1, -0x4974
  jal   check_token
   li    $a0, 1
  beqz  $v0, .L7F0BD4F0
   nop   
  jal   getPlayerCount
   nop   
  lui   $a1, %hi(aMgfx_1)
  addiu $a1, %lo(aMgfx_1) # addiu $a1, $a1, -0x496c
  sw    $v0, 0x18($sp)
  jal   check_token
   li    $a0, 1
  move  $a0, $v0
  move  $a1, $zero
  jal   strtol
   move  $a2, $zero
  lw    $t7, 0x18($sp)
  lui   $at, %hi(D_800482E0)
  sll   $t6, $v0, 0xa
  sll   $t8, $t7, 2
  addu  $at, $at, $t8
  sw    $t6, %lo(D_800482E0)($at)
.L7F0BD4F0:
  lui   $a1, %hi(aMvtx)
  addiu $a1, %lo(aMvtx) # addiu $a1, $a1, -0x4964
  jal   check_token
   li    $a0, 1
  beqz  $v0, .L7F0BD54C
   nop   
  jal   getPlayerCount
   nop   
  lui   $a1, %hi(aMvtx_0)
  addiu $a1, %lo(aMvtx_0) # addiu $a1, $a1, -0x495c
  sw    $v0, 0x18($sp)
  jal   check_token
   li    $a0, 1
  move  $a0, $v0
  move  $a1, $zero
  jal   strtol
   move  $a2, $zero
  lw    $t0, 0x18($sp)
  lui   $at, %hi(D_800482F0)
  sll   $t9, $v0, 0xa
  sll   $t1, $t0, 2
  addu  $at, $at, $t1
  sw    $t9, %lo(D_800482F0)($at)
.L7F0BD54C:
  jal   getPlayerCount
   nop   
  sll   $t2, $v0, 2
  lui   $a0, %hi(D_800482E0)
  addu  $a0, $a0, $t2
  lw    $a0, %lo(D_800482E0)($a0)
  li    $a1, 4
  sll   $t3, $a0, 1
  jal   mempAllocBytesInBank
   move  $a0, $t3
  lui   $at, %hi(ptr_mgfx0_alloc_start)
  jal   getPlayerCount
   sw    $v0, %lo(ptr_mgfx0_alloc_start)($at)
  lui   $v1, %hi(ptr_mgfx0_alloc_start)
  sll   $t4, $v0, 2
  lui   $t5, %hi(D_800482E0)
  addu  $t5, $t5, $t4
  addiu $v1, %lo(ptr_mgfx0_alloc_start) # addiu $v1, $v1, -0x3dd0
  lw    $t7, ($v1)
  lw    $t5, %lo(D_800482E0)($t5)
  addu  $t6, $t5, $t7
  jal   getPlayerCount
   sw    $t6, 4($v1)
  lui   $v1, %hi(ptr_mgfx0_alloc_start)
  sll   $t8, $v0, 2
  lui   $t0, %hi(D_800482E0)
  addu  $t0, $t0, $t8
  addiu $v1, %lo(ptr_mgfx0_alloc_start) # addiu $v1, $v1, -0x3dd0
  lw    $t9, 4($v1)
  lw    $t0, %lo(D_800482E0)($t0)
  addu  $t1, $t0, $t9
  jal   getPlayerCount
   sw    $t1, 8($v1)
  sll   $t2, $v0, 2
  lui   $a0, %hi(D_800482F0)
  addu  $a0, $a0, $t2
  lw    $a0, %lo(D_800482F0)($a0)
  li    $a1, 4
  sll   $t3, $a0, 1
  jal   mempAllocBytesInBank
   move  $a0, $t3
  lui   $v1, %hi(ptr_mvtx0_alloc_start)
  addiu $v1, %lo(ptr_mvtx0_alloc_start) # addiu $v1, $v1, -0x3dc0
  jal   getPlayerCount
   sw    $v0, ($v1)
  lui   $v1, %hi(ptr_mvtx0_alloc_start)
  sll   $t4, $v0, 2
  lui   $t5, %hi(D_800482F0)
  addu  $t5, $t5, $t4
  addiu $v1, %lo(ptr_mvtx0_alloc_start) # addiu $v1, $v1, -0x3dc0
  lw    $t7, ($v1)
  lw    $t5, %lo(D_800482F0)($t5)
  addu  $t6, $t5, $t7
  jal   getPlayerCount
   sw    $t6, 4($v1)
  lui   $v1, %hi(ptr_mvtx0_alloc_start)
  sll   $t8, $v0, 2
  lui   $t0, %hi(D_800482F0)
  addu  $t0, $t0, $t8
  addiu $v1, %lo(ptr_mvtx0_alloc_start) # addiu $v1, $v1, -0x3dc0
  lw    $t9, 4($v1)
  lw    $t0, %lo(D_800482F0)($t0)
  lui   $at, %hi(bank_in_mgfx_alloc_table)
  lw    $ra, 0x14($sp)
  addu  $t1, $t0, $t9
  sw    $t1, 8($v1)
  sb    $zero, %lo(bank_in_mgfx_alloc_table)($at)
  lui   $at, %hi(dword_CODE_bss_8008C254)
  sw    $zero, %lo(dword_CODE_bss_8008C254)($at)
  lw    $t2, ($v1)
  lui   $at, %hi(ptr_mvtx_cur_pos)
  addiu $sp, $sp, 0x20
  jr    $ra
   sw    $t2, %lo(ptr_mvtx_cur_pos)($at)
");

asm(R"
glabel get_ptr_displaylist
  lui   $t7, %hi(bank_in_mgfx_alloc_table) 
  lbu   $t7, %lo(bank_in_mgfx_alloc_table)($t7)
  lui   $v0, %hi(ptr_mgfx0_alloc_start)
  li    $t6, 1
  sll   $t8, $t7, 2
  lui   $at, %hi(dword_CODE_bss_8008C254)
  addu  $v0, $v0, $t8
  sw    $t6, %lo(dword_CODE_bss_8008C254)($at)
  jr    $ra
   lw    $v0, %lo(ptr_mgfx0_alloc_start)($v0)
");

asm(R"
glabel allocate_something_in_mgfx
  lui   $t6, %hi(bank_in_mgfx_alloc_table) 
  lbu   $t6, %lo(bank_in_mgfx_alloc_table)($t6)
  lui   $t8, %hi(ptr_mgfx1_alloc_start)
  sll   $t7, $t6, 2
  addu  $t8, $t8, $t7
  lw    $t8, %lo(ptr_mgfx1_alloc_start)($t8)
  subu  $v0, $t8, $a0
  sra   $t9, $v0, 3
  jr    $ra
   move  $v0, $t9
");

asm(R"
glabel sub_GAME_7F0BD6C4
  lui   $a2, %hi(ptr_mvtx_cur_pos)
  addiu $a2, %lo(ptr_mvtx_cur_pos) # addiu $a2, $a2, -0x3db4
  lw    $v0, ($a2)
  sll   $t6, $a0, 4
  addu  $t7, $v0, $t6
  jr    $ra
   sw    $t7, ($a2)
");

asm(R"
glabel sub_GAME_7F0BD6E0
  lui   $a1, %hi(ptr_mvtx_cur_pos)
  addiu $a1, %lo(ptr_mvtx_cur_pos) # addiu $a1, $a1, -0x3db4
  lw    $v0, ($a1)
  addiu $t6, $v0, 0x40
  jr    $ra
   sw    $t6, ($a1)
");

asm(R"
glabel sub_GAME_7F0BD6F8
  lui   $a2, %hi(ptr_mvtx_cur_pos)
  addiu $a2, %lo(ptr_mvtx_cur_pos) # addiu $a2, $a2, -0x3db4
  lw    $v0, ($a2)
  sll   $t6, $a0, 4
  addu  $t7, $v0, $t6
  jr    $ra
   sw    $t7, ($a2)
");

asm(R"
glabel sub_GAME_7F0BD714
  lui   $a2, %hi(ptr_mvtx_cur_pos)
  addiu $a2, %lo(ptr_mvtx_cur_pos) # addiu $a2, $a2, -0x3db4
  lw    $v0, ($a2)
  addiu $a0, $a0, 0xf
  ori   $t6, $a0, 0xf
  xori  $t7, $t6, 0xf
  addu  $t8, $v0, $t7
  jr    $ra
   sw    $t8, ($a2)
");

asm(R"
glabel allocate_something_in_mvtx
  lui   $v0, %hi(bank_in_mgfx_alloc_table)
  addiu $v0, %lo(bank_in_mgfx_alloc_table) # addiu $v0, $v0, -0x3db0
  lbu   $t6, ($v0)
  lui   $at, %hi(dword_CODE_bss_8008C254)
  lui   $t0, %hi(ptr_mvtx0_alloc_start)
  xori  $t7, $t6, 1
  sb    $t7, ($v0)
  sw    $zero, %lo(dword_CODE_bss_8008C254)($at)
  lbu   $t8, ($v0)
  lui   $at, %hi(ptr_mvtx_cur_pos)
  sll   $t9, $t8, 2
  addu  $t0, $t0, $t9
  lw    $t0, %lo(ptr_mvtx0_alloc_start)($t0)
  jr    $ra
   sw    $t0, %lo(ptr_mvtx_cur_pos)($at)
");

void removed_debug_routine(int arg0) {}

asm(R"
glabel num_microcode_cmds_that_fit
  lui   $t6, %hi(bank_in_mgfx_alloc_table) 
  lbu   $t6, %lo(bank_in_mgfx_alloc_table)($t6)
  lui   $t8, %hi(ptr_mgfx1_alloc_start)
  sll   $t7, $t6, 2
  addu  $t8, $t8, $t7
  lw    $t8, %lo(ptr_mgfx1_alloc_start)($t8)
  subu  $v0, $t8, $a0
  sra   $t9, $v0, 3
  jr    $ra
   move  $v0, $t9
");

asm(R"
glabel sub_GAME_7F0BD7A4
  lui   $t6, %hi(bank_in_mgfx_alloc_table) 
  lbu   $t6, %lo(bank_in_mgfx_alloc_table)($t6)
  lui   $t8, %hi(ptr_mvtx1_alloc_start)
  lui   $t9, %hi(ptr_mvtx_cur_pos) 
  sll   $t7, $t6, 2
  addu  $t8, $t8, $t7
  lw    $t8, %lo(ptr_mvtx1_alloc_start)($t8)
  lw    $t9, %lo(ptr_mvtx_cur_pos)($t9)
  jr    $ra
   subu  $v0, $t8, $t9
");

asm(R"
glabel compute_membar_display_string
  mtc1  $a1, $f12
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a2, 0x20($sp)
  jal   strlen
   swc1  $f12, 0x1c($sp)
  lwc1  $f12, 0x1c($sp)
  lwc1  $f4, 0x20($sp)
  mtc1  $zero, $f0
  lw    $ra, 0x14($sp)
  div.s $f12, $f12, $f4
  c.lt.s $f12, $f0
  nop   
  bc1f  .L7F0BD808
   nop   
.L7F0BD808:
  jr    $ra
   addiu $sp, $sp, 0x18
");

asm(R"
glabel draw_membars
  lui   $v0, %hi(bank_in_mgfx_alloc_table)
  lbu   $v0, %lo(bank_in_mgfx_alloc_table)($v0)
  lui   $t0, %hi(ptr_mgfx0_alloc_start) 
  addiu $t0, %lo(ptr_mgfx0_alloc_start) # addiu $t0, $t0, -0x3dd0
  sll   $t6, $v0, 2
  addu  $t7, $t0, $t6
  sll   $t1, $v0, 2
  lw    $v1, 4($t7)
  addu  $t2, $t0, $t1
  lw    $t3, ($t2)
  move  $a3, $a0
  subu  $t8, $v1, $a3
  subu  $t4, $v1, $t3
  sra   $t5, $t4, 3
  sra   $t9, $t8, 3
  mtc1  $t9, $f4
  mtc1  $t5, $f6
  addiu $sp, $sp, -0x18
  cvt.s.w $f4, $f4
  sw    $ra, 0x14($sp)
  lui   $a0, %hi(membars_string2)
  addiu $a0, %lo(membars_string2) # addiu $a0, $a0, -0x7ce0
  cvt.s.w $f6, $f6
  mfc1  $a1, $f4
  mfc1  $a2, $f6
  jal   compute_membar_display_string
   nop   
  lui   $v0, %hi(bank_in_mgfx_alloc_table)
  lbu   $v0, %lo(bank_in_mgfx_alloc_table)($v0)
  lui   $a3, %hi(ptr_mvtx0_alloc_start)
  addiu $a3, %lo(ptr_mvtx0_alloc_start) # addiu $a3, $a3, -0x3dc0
  sll   $t6, $v0, 2
  addu  $t7, $a3, $t6
  sll   $t1, $v0, 2
  lw    $v1, 4($t7)
  addu  $t2, $a3, $t1
  lui   $t8, %hi(ptr_mvtx_cur_pos) 
  lw    $t8, %lo(ptr_mvtx_cur_pos)($t8)
  lw    $t3, ($t2)
  lui   $a0, %hi(membars_string2)
  subu  $t9, $v1, $t8
  subu  $t4, $v1, $t3
  mtc1  $t4, $f10
  mtc1  $t9, $f8
  addiu $a0, %lo(membars_string2) # addiu $a0, $a0, -0x7ce0
  cvt.s.w $f10, $f10
  cvt.s.w $f8, $f8
  mfc1  $a2, $f10
  mfc1  $a1, $f8
  jal   compute_membar_display_string
   nop   
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");
