// This file contains debug notification code.
void *D_800232E0[2] = {0};
void *debug_notice_list[4] = {0};

extern char dword_CODE_bss_80060890[];
char *debug_notice_list_data = &dword_CODE_bss_80060890;

/*
 * V0=p->match in debug.notice.list [800232E8] or NULL if not found
 * accepts: A0=p->name, A1=p->data
 */
asm(R"
glabel is_already_in_debug_notice_list
  addiu $sp, $sp, -0x20
  sw    $s0, 0x14($sp)
  lui   $s0, %hi(debug_notice_list)
  lw    $s0, %lo(debug_notice_list)($s0)
  sw    $s1, 0x18($sp)
  move  $s1, $a0
  beqz  $s0, .L70004D68
   sw    $ra, 0x1c($sp)
  lw    $a0, 8($s0)
.L70004D44:
  jal   something_with_strings_0
   move  $a1, $s1
  bnezl $v0, .L70004D60
   lw    $s0, ($s0)
  b     .L70004D6C
   move  $v0, $s0
  lw    $s0, ($s0)
.L70004D60:
  bnezl $s0, .L70004D44
   lw    $a0, 8($s0)
.L70004D68:
  move  $v0, $zero
.L70004D6C:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x20
");

/**
 *     V0=p->entry of size A0 allocated in debug.notice.list; entry allocated in
 * block 6 on failure accepts: A0=size
 */
asm(R"
glabel get_entry_of_size_in_debug_notice_list
  lui   $v0, %hi(debug_notice_list_data)
  lw    $v0, %lo(debug_notice_list_data)($v0)
  lui   $t6, %hi(thread_video_manager_debugthread) 
  addiu $t6, %lo(thread_video_manager_debugthread) # addiu $t6, $t6, 0xc90
  move  $v1, $v0
  addu  $v0, $v0, $a0
  addiu $sp, $sp, -0x18
  sltu  $at, $t6, $v0
  beqz  $at, .L70004DC4
   sw    $ra, 0x14($sp)
  subu  $v0, $v0, $a0
  lui   $at, %hi(debug_notice_list_data)
  sw    $v0, %lo(debug_notice_list_data)($at)
  jal   mempAllocBytesInBank
   li    $a1, 6
  b     .L70004DD4
   lw    $ra, 0x14($sp)
.L70004DC4:
  lui   $at, %hi(debug_notice_list_data)
  sw    $v0, %lo(debug_notice_list_data)($at)
  move  $v0, $v1
  lw    $ra, 0x14($sp)
.L70004DD4:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

/**
 *     V0=p->new entry added in debug.notice.list
 *     accepts: A0=p->name, A1=p->data
 */
asm(R"
glabel add_new_entry_to_debug_notice_list
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  sw    $a1, 0x1c($sp)
  jal   get_entry_of_size_in_debug_notice_list
   li    $a0, 16
  lui   $v1, %hi(debug_notice_list)
  addiu $v1, %lo(debug_notice_list) # addiu $v1, $v1, 0x32e8
  lw    $t6, ($v1)
  sw    $t6, ($v0)
  lw    $t7, 0x1c($sp)
  sw    $t7, 4($v0)
  lw    $t8, 0x18($sp)
  sw    $t8, 8($v0)
  lw    $ra, 0x14($sp)
  sw    $v0, ($v1)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

extern void set_debug_notice_list_entry(void *arg0, char *string);

void add_debug_notice_deb_c_debug(void) {
  set_debug_notice_list_entry(&D_800232E0, "deb_c_debug");
  init_tlb();
}

void set_debug_notice_list_entry(void *data, char *string) {
  if (!is_already_in_debug_notice_list(string))
    add_new_entry_to_debug_notice_list(string, data);
}

/**
 *     V0=0; scan debug.notice.list until a NULL pointer
 *     likely this would have executed some function for each entry...
 */
asm(R"
glabel scan_debug_notice_list_till_NULL
  lui   $v0, %hi(debug_notice_list)
  lw    $v0, %lo(debug_notice_list)($v0)
  beqz  $v0, .L70004EB4
   nop   
  lw    $v0, ($v0)
.L70004EAC:
  bnezl $v0, .L70004EAC
   lw    $v0, ($v0)
.L70004EB4:
  jr    $ra
   nop   
");

void debug_stubbed_70004EBC(void) {}

void debug_removed(int arg0, int arg1, int arg2) {}
