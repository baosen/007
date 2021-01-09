// This file contains TLB management code.
unsigned int maybe_cur_TLB_entries = 0;
unsigned int tlb_segment_num = 0;

char TLB_managment_table_start[0x800];
char TLB_manager_mapping_table_start[0xB4];
unsigned int TLB_manager_mapping_table_end;
unsigned int ptr_TLBallocatedblock;

// Establishes 7F- TLB buffer and management table.
asm(R"
glabel establish_TLB_buffer_management_table
  lui   $v1, %hi(TLB_managment_table_start)
  lui   $v0, %hi(TLB_manager_mapping_table_start)
  addiu $v0, %lo(TLB_manager_mapping_table_start) # addiu $v0, $v0, -0x1c10
  addiu $v1, %lo(TLB_managment_table_start) # addiu $v1, $v1, -0x2410
  li    $a0, 1
.L700017F4:
  addiu $v1, $v1, 0x10
  sltu  $at, $v1, $v0
  sw    $a0, -0x10($v1)
  bnez  $at, .L700017F4
   sw    $zero, -0xc($v1)
  lui   $at, %hi(TLB_manager_mapping_table_start + 2)
  lui   $v1, %hi(TLB_manager_mapping_table_start + 4)
  lui   $v0, %hi(TLB_manager_mapping_table_end)
  addiu $v0, %lo(TLB_manager_mapping_table_end) # addiu $v0, $v0, -0x1b5c
  addiu $v1, %lo(TLB_manager_mapping_table_start + 4) # addiu $v1, $v1, -0x1c0c
  sb    $zero, %lo(TLB_manager_mapping_table_start + 1)($at)
  sb    $a0, %lo(TLB_manager_mapping_table_start)($at)
  sb    $zero, %lo(TLB_manager_mapping_table_start + 3)($at)
  sb    $a0, %lo(TLB_manager_mapping_table_start + 2)($at)
.L7000182C:
  addiu $v1, $v1, 8
  sb    $zero, -5($v1)
  sb    $a0, -6($v1)
  sb    $zero, -3($v1)
  sb    $a0, -4($v1)
  sb    $zero, -1($v1)
  sb    $a0, -2($v1)
  sb    $zero, -7($v1)
  bne   $v1, $v0, .L7000182C
   sb    $a0, -8($v1)
  lui   $t6, %hi(sp_boot) # $t6, 0x803b
  addiu $t6, %lo(sp_boot) # addiu $t6, $t6, -0x4c00
  li    $at, -8192
  and   $t7, $t6, $at
  lui   $at, (0xFFF4C000 >> 16) # lui $at, 0xfff4
  ori   $at, (0xFFF4C000 & 0xFFFF) # ori $at, $at, 0xc000
  addu  $t8, $t7, $at
  lui   $at, %hi(ptr_TLBallocatedblock)
  sw    $t8, %lo(ptr_TLBallocatedblock)($at)
  lui   $at, (0xFFC08000 >> 16) # lui $at, 0xffc0
  lui   $t9, %hi(TLB_managment_table_start) 
  addiu $t9, %lo(TLB_managment_table_start) # addiu $t9, $t9, -0x2410
  ori   $at, (0xFFC08000 & 0xFFFF) # ori $at, $at, 0x8000
  addu  $t0, $t9, $at
  lui   $at, %hi(TLB_manager_mapping_table_end)
  jr    $ra
   sw    $t0, %lo(TLB_manager_mapping_table_end)($at)
");

asm(R"
glabel mp_tlb_related
  lui   $v1, %hi(maybe_cur_TLB_entries)
  addiu $v1, %lo(maybe_cur_TLB_entries) # addiu $v1, $v1, 0x30d0
  lw    $v0, ($v1)
  slti  $at, $v0, 0x33
  beqz  $at, .L700018B8
   slti  $at, $v0, 0x1a
  beqz  $at, .L700018B8
   nop   
.L700018B8:
  jr    $ra
   sw    $zero, ($v1)
");

/**
 * searches TLB index for an entry matching A0
 *	V0=index of match or 80000000 if not found
 *	accepts: A0=TLB pointer
 */
int return_TLB_index_for_entry(int entry) {
  int index = 0;
  while (index != 0x20) {
    if (__osGetTLBHi(index) == entry) {
      return index;
    }
    index++;
  };
  return -0x80000000;
}

/**
 * find and remove TLB entry A0
 *	accepts: A0=TLB pointer
 *	redirects to 700018C0, 7000D3D0
 */
void find_remove_TLB_entry(unsigned int entry) {
  int index = return_TLB_index_for_entry(entry);

  if ((index & 0x80000000))
    return;

  osUnmapTLB(index);
}

/**
 * remove index A0 TLB entry from table at 8005E3F0
 *	table format:
 *		0x0	1 if dirty
 *		0x1	chunk # (7F000000 | chunk<<D)
 */
asm(R"
glabel remove_TLB_entry_from_table
  lui   $t7, %hi(TLB_manager_mapping_table_start) 
  addiu $t7, %lo(TLB_manager_mapping_table_start) # addiu $t7, $t7, -0x1c10
  sll   $t6, $a0, 1
  addu  $v1, $t6, $t7
  lbu   $t8, ($v1)
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  bnezl $t8, .L700019CC
   lw    $ra, 0x14($sp)
  lbu   $a0, 1($v1)
  lui   $at, 0x7f00
  sw    $v1, 0x18($sp)
  sll   $t9, $a0, 0xd
  jal   return_TLB_index_for_entry
   or    $a0, $t9, $at
  sll   $t1, $v0, 0
  lw    $v1, 0x18($sp)
  bltz  $t1, .L700019AC
   move  $a0, $v0
  jal   osUnmapTLB
   sw    $v1, 0x18($sp)
  lw    $v1, 0x18($sp)
.L700019AC:
  lbu   $t2, 1($v1)
  lui   $at, %hi(TLB_managment_table_start)
  li    $v0, 1
  sll   $t3, $t2, 4
  addu  $at, $at, $t3
  sw    $v0, %lo(TLB_managment_table_start)($at)
  sb    $v0, ($v1)
  lw    $ra, 0x14($sp)
.L700019CC:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

/**
 * loads ROM range for 7F- TLB entries
 */
asm(R"
glabel translate_load_rom_from_TLBaddress
  lui   $v0, %hi(maybe_cur_TLB_entries)
  addiu $v0, %lo(maybe_cur_TLB_entries) # addiu $v0, $v0, 0x30d0
  lw    $t6, ($v0)
  lui   $at, (0x7FFFE000 >> 16) # lui $at, 0x7fff
  addiu $sp, $sp, -0x50
  ori   $at, (0x7FFFE000 & 0xFFFF) # ori $at, $at, 0xe000
  sw    $ra, 0x1c($sp)
  and   $a0, $a0, $at
  addiu $t7, $t6, 1
  sw    $s0, 0x18($sp)
  sw    $t7, ($v0)
  jal   find_remove_TLB_entry
   sw    $a0, 0x28($sp)
  jal   return_tlb_random_value
   nop   
  li    $at, 90
  divu  $zero, $v0, $at
  mfhi  $a0
  lui   $v1, %hi(tlb_segment_num)
  addiu $v1, %lo(tlb_segment_num) # addiu $v1, $v1, 0x30d4
  sw    $a0, ($v1)
  jal   remove_TLB_entry_from_table
   move  $s0, $a0
  lw    $v0, 0x28($sp)
  lui   $t9, %hi(ptr_TLBallocatedblock) 
  lw    $t9, %lo(ptr_TLBallocatedblock)($t9)
  lui   $at, (0x00FFE000 >> 16) # lui $at, 0xff
  ori   $at, (0x00FFE000 & 0xFFFF) # ori $at, $at, 0xe000
  sll   $t0, $s0, 0xd
  lui   $t2, %hi(_textRomSegmentStart) # $t2, 3
  and   $t1, $v0, $at
  addiu $t2, %lo(_textRomSegmentStart) # addiu $t2, $t2, 0x4b30
  addu  $a0, $t9, $t0
  sw    $a0, 0x34($sp)
  addu  $a1, $t1, $t2
  move  $v0, $t1
  sw    $t1, 0x24($sp)
  jal   romCopy
   li    $a2, 8192
  lui   $a0, 0x4000
  jal   osInvalICache
   lui   $a1, 0x4000
  lui   $a0, 0x8000
  jal   osInvalICache
   lui   $a1, 0x1000
  lw    $a1, 0x24($sp)
  lui   $t5, %hi(TLB_managment_table_start) 
  addiu $t5, %lo(TLB_managment_table_start) # addiu $t5, $t5, -0x2410
  srl   $t3, $a1, 0xd
  sll   $t4, $t3, 4
  addu  $a2, $t4, $t5
  sw    $s0, 4($a2)
  sw    $a2, 0x20($sp)
  sw    $t3, 0x28($sp)
  jal   osVirtualToPhysical
   lw    $a0, 0x34($sp)
  lw    $ra, 0x1c($sp)
  srl   $t6, $v0, 0xc
  sll   $t9, $s0, 1
  lui   $t0, %hi(TLB_manager_mapping_table_start) 
  lw    $a1, 0x28($sp)
  lw    $a2, 0x20($sp)
  sll   $t7, $t6, 6
  addiu $t0, %lo(TLB_manager_mapping_table_start) # addiu $t0, $t0, -0x1c10
  ori   $t8, $t7, 0x1f
  addu  $v1, $t9, $t0
  lw    $s0, 0x18($sp)
  sb    $zero, ($v1)
  addiu $sp, $sp, 0x50
  sb    $a1, 1($v1)
  jr    $ra
   sw    $t8, ($a2)
");

/**
 * V0=p->TLB memory, or alternately end of free memory [8005E4A8]
 */
unsigned int *return_ptr_TLBallocatedblock(void) {
  return ptr_TLBallocatedblock;
}
