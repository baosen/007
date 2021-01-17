// This file contains memory allocation code.
typedef struct s_mem_alloc_entry {
  int addr, size;
} s_mem_alloc_entry;

typedef struct s_mem_alloc_table {
  struct s_mem_alloc_entry entries[0x200];
} s_mem_alloc_table;

void *ptr_model_room_buf_secondary;
unsigned int size_modelroom_buf;
struct s_mem_alloc_table ptr_table_allocated_mem_blocks;

void *ptr_mema_c_debug_notice_list = 0;

void memaSwap(char *a, char *b) {
  char *start = *(void **)a,
       *end = *(void **)((char*)a + 4);
  *(int *)a = *(int *)b;
  *(int *)(a + 4) = *(int *)(b + 4);
  *(void **)b = start;
  *(void **)(b + 4) = end;
}

asm(R"
glabel memaMerge
  lw    $t6, 4($a0)
  lw    $t7, 4($a1)
  addu  $t8, $t6, $t7
  sw    $t8, 4($a0)
  sw    $zero, ($a1)
  jr    $ra
  sw    $zero, 4($a1)
");

asm(R"
glabel memaSortMergeEntries
  addiu $sp, $sp, -0x30
  sw    $s4, 0x28($sp)
  sw    $s0, 0x18($sp)
  addiu $s0, $a0, 0x10
  addiu $s4, $a0, 0xfe8
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sltu  $at, $s4, $s0
  sw    $ra, 0x2c($sp)
  move  $s3, $zero
  addiu $s1, $a0, 8
  bnez  $at, .L70009AF4
   move  $s2, $zero
  lw    $t6, 4($s0)
.L70009A8C:
  beql  $t6, $zero, .L70009AE8
   addiu $s0, $s0, 8
  lw    $v0, ($s0)
  move  $a0, $s0
  sltu  $at, $v0, $s2
  beql  $at, $zero, .L70009AB8
   lw    $t7, 4($s1)
  jal   memaSwap
   move  $a1, $s1
  lw    $v0, ($s0)
  lw    $t7, 4($s1)
.L70009AB8:
  move  $a0, $s1
  move  $a1, $s0
  addu  $t8, $t7, $s2
  bnel  $v0, $t8, .L70009AE0
   move  $s1, $s0
  jal   memaMerge
   li    $s3, 1
  move  $s0, $s1
  lw    $v0, ($s1)
  move  $s1, $s0
.L70009AE0:
  move  $s2, $v0
  addiu $s0, $s0, 8
.L70009AE8:
  sltu  $at, $s4, $s0
  beql  $at, $zero, .L70009A8C
   lw    $t6, 4($s0)
.L70009AF4:
  lw    $ra, 0x2c($sp)
  move  $v0, $s3
  lw    $s3, 0x24($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  lw    $s4, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x30
");

void memaSortMergeAllEntries(void) {
  while (memaSortMergeEntries(&ptr_table_allocated_mem_blocks) != 0)
    ;
}

asm(R"
glabel mem_related
  addiu $sp, $sp, -0x28
  sw    $s2, 0x1c($sp)
  sw    $s3, 0x20($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  addiu $s2, $a0, 0x10
  sw    $ra, 0x24($sp)
  move  $s0, $s2
  addiu $s1, $a0, 0xfe8
  move  $s3, $zero
  sltu  $at, $s1, $s2
.L70009B8C:
  bnezl $at, .L70009C10
   addiu $s3, $s3, 1
.L70009B94:
  lw    $a0, 4($s0)
  addiu $a1, $s0, 8
  bnezl $a0, .L70009BB0
   lw    $v0, 8($s0)
  b     .L70009C58
   move  $v0, $s0
  lw    $v0, 8($s0)
.L70009BB0:
  lw    $v1, ($s0)
  sltu  $at, $v0, $v1
  beql  $at, $zero, .L70009BD8
   addu  $t6, $v1, $a0
  jal   memaSwap
   move  $a0, $s0
  lw    $a0, 4($s0)
  lw    $v0, 8($s0)
  lw    $v1, ($s0)
  addu  $t6, $v1, $a0
.L70009BD8:
  bne   $v0, $t6, .L70009BFC
   addiu $a1, $s0, 8
  lw    $t7, 0xc($s0)
  sw    $zero, 8($s0)
  sw    $zero, 0xc($s0)
  addu  $t8, $a0, $t7
  sw    $t8, 4($s0)
  b     .L70009C58
   move  $v0, $a1
.L70009BFC:
  sltu  $at, $s1, $a1
  beqz  $at, .L70009B94
   move  $s0, $a1
  move  $s0, $s2
  addiu $s3, $s3, 1
.L70009C10:
  slti  $at, $s3, 0x1fc
  bnezl $at, .L70009B8C
   sltu  $at, $s1, $s2
  sltu  $at, $s1, $s2
  li    $v0, -1
  bnez  $at, .L70009C54
   move  $v1, $s2
  lw    $a0, 4($s0)
.L70009C30:
  sltu  $at, $a0, $v0
  beql  $at, $zero, .L70009C48
   addiu $s0, $s0, 8
  move  $v1, $s0
  move  $v0, $a0
  addiu $s0, $s0, 8
.L70009C48:
  sltu  $at, $s1, $s0
  beql  $at, $zero, .L70009C30
   lw    $a0, 4($s0)
.L70009C54:
  move  $v0, $v1
.L70009C58:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
glabel memaAllocRoomBuffer
  lui   $t7, %hi(ptr_model_room_buf_secondary) 
  lw    $t7, %lo(ptr_model_room_buf_secondary)($t7)
  lui   $t1, %hi(size_modelroom_buf) 
  lw    $t1, %lo(size_modelroom_buf)($t1)
  subu  $t8, $a0, $t7
  sll   $t9, $t8, 7
  subu  $t9, $t9, $t8
  sll   $t9, $t9, 2
  div   $zero, $t9, $t1
  mflo  $a2
  lui   $t3, %hi(ptr_table_allocated_mem_blocks) 
  addiu $t3, %lo(ptr_table_allocated_mem_blocks) # addiu $t3, $t3, 0x3c28
  sll   $t2, $a2, 3
  addu  $v0, $t2, $t3
  lw    $t0, 0x14($v0)
  addiu $sp, $sp, -0x18
  addiu $a3, $v0, 0x10
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  sw    $a1, 0x1c($sp)
  move  $t6, $a0
  bnez  $t1, .L70009CD4
   nop   
  break 7
.L70009CD4:
  li    $at, -1
  bne   $t1, $at, .L70009CEC
   lui   $at, 0x8000
  bne   $t9, $at, .L70009CEC
   nop   
  break 6
.L70009CEC:
  move  $v1, $a3
  beql  $t0, $zero, .L70009D0C
   lw    $t5, ($v1)
  lw    $t4, 0xc($v1)
.L70009CFC:
  addiu $v1, $v1, 8
  bnezl $t4, .L70009CFC
   lw    $t4, 0xc($v1)
  lw    $t5, ($v1)
.L70009D0C:
  li    $at, -1
  bnel  $t5, $at, .L70009D50
   lw    $t8, 0x18($sp)
  beqz  $t0, .L70009D30
   move  $v1, $a3
  lw    $t6, -4($v1)
.L70009D24:
  addiu $v1, $v1, -8
  bnezl $t6, .L70009D24
   lw    $t6, -4($v1)
.L70009D30:
  lw    $t7, ($v1)
  lui   $a0, %hi(ptr_table_allocated_mem_blocks)
  bnezl $t7, .L70009D50
   lw    $t8, 0x18($sp)
  jal   mem_related
   addiu $a0, %lo(ptr_table_allocated_mem_blocks) # addiu $a0, $a0, 0x3c28
  move  $v1, $v0
  lw    $t8, 0x18($sp)
.L70009D50:
  sw    $t8, ($v1)
  lw    $t9, 0x1c($sp)
  sw    $t9, 4($v1)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

void something_with_mema_c_debug(void) {
  set_debug_notice_list_entry(&ptr_mema_c_debug_notice_list, "mema_c_debug");
}

asm(R"
glabel mempInitMallocTable
  lui   $v1, %hi(ptr_table_allocated_mem_blocks)
  addiu $v1, %lo(ptr_table_allocated_mem_blocks) # addiu $v1, $v1, 0x3c28
  li    $a2, -1
  sw    $a2, 0xff0($v1)
  sw    $a2, 0xff8($v1)
  li    $t6, -1
  lui   $a2, %hi(ptr_table_allocated_mem_blocks + 0xFE8)
  lui   $v0, %hi(ptr_table_allocated_mem_blocks + 0x10)
  sw    $zero, ($v1)
  sw    $zero, 4($v1)
  sw    $zero, 8($v1)
  sw    $zero, 0xc($v1)
  sw    $zero, 0xff4($v1)
  sw    $t6, 0xffc($v1)
  addiu $v0, %lo(ptr_table_allocated_mem_blocks + 0x10) # addiu $v0, $v0, 0x3c38
  addiu $a2, %lo(ptr_table_allocated_mem_blocks + 0xFE8) # addiu $a2, $a2, 0x4c10
.L70009DD8:
  addiu $v0, $v0, 8
  sltu  $at, $a2, $v0
  sw    $zero, -8($v0)
  beqz  $at, .L70009DD8
   sw    $zero, -4($v0)
  lui   $v0, %hi(ptr_model_room_buf_secondary)
  lui   $a2, %hi(size_modelroom_buf)
  addiu $a2, %lo(size_modelroom_buf) # addiu $a2, $a2, 0x3c24
  addiu $v0, %lo(ptr_model_room_buf_secondary) # addiu $v0, $v0, 0x3c20
  sw    $a0, ($v0)
  sw    $a0, 0x10($v1)
  sw    $a1, ($a2)
  jr    $ra
   sw    $a1, 0x14($v1)
");

void mem_related_calls_sort_merge_entries(void) {
  memaSortMergeEntries(&ptr_table_allocated_mem_blocks);
}

asm(R"
glabel mem_related_something_find_first
  addiu $sp, $sp, -0x30
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  move  $s2, $a0
  sw    $s5, 0x28($sp)
  sw    $s0, 0x14($sp)
  lui   $s1, %hi(ptr_table_allocated_mem_blocks + 0x10)
  sw    $ra, 0x2c($sp)
  sw    $s4, 0x24($sp)
  sw    $s3, 0x20($sp)
  addiu $s1, %lo(ptr_table_allocated_mem_blocks + 0x10) # addiu $s1, $s1, 0x3c38
  li    $a0, -1
  move  $a1, $zero
  move  $s0, $zero
  li    $s5, -1
  li    $a2, 16
.L70009E74:
  lw    $v1, 4($s1)
  addiu $s0, $s0, 1
  sltu  $at, $v1, $s2
  bnez  $at, .L70009EBC
   subu  $v0, $v1, $s2
  lw    $t6, ($s1)
  sltu  $at, $v0, $a0
  srl   $t7, $s2, 2
  beq   $s5, $t6, .L70009EC4
   nop   
  beqz  $at, .L70009EBC
   sltiu $at, $v0, 0x40
  move  $a0, $v0
  bnez  $at, .L70009EC4
   move  $a1, $s1
  sltu  $at, $v0, $t7
  bnez  $at, .L70009EC4
   nop   
.L70009EBC:
  bne   $s0, $a2, .L70009E74
   addiu $s1, $s1, 8
.L70009EC4:
  bnezl $a1, .L70009F64
   lw    $v1, ($a1)
  lw    $t8, 4($s1)
  move  $s0, $zero
  li    $s4, 8
  sltu  $at, $t8, $s2
  beqz  $at, .L70009EF8
   lui   $s3, %hi(ptr_table_allocated_mem_blocks)
  lw    $t9, 0xc($s1)
.L70009EE8:
  addiu $s1, $s1, 8
  sltu  $at, $t9, $s2
  bnezl $at, .L70009EE8
   lw    $t9, 0xc($s1)
.L70009EF8:
  lw    $t0, ($s1)
  addiu $s3, %lo(ptr_table_allocated_mem_blocks) # addiu $s3, $s3, 0x3c28
  bnel  $s5, $t0, .L70009F60
   move  $a1, $s1
  lui   $s1, %hi(ptr_table_allocated_mem_blocks + 0x10)
  addiu $s1, %lo(ptr_table_allocated_mem_blocks + 0x10) # addiu $s1, $s1, 0x3c38
.L70009F10:
  jal   memaSortMergeEntries
   move  $a0, $s3
  addiu $s0, $s0, 1
  bne   $s0, $s4, .L70009F10
  nop
  lw    $t1, 0x14($s3)
  sltu  $at, $t1, $s2
  beql  $at, $zero, .L70009F4C
  lw    $t3, ($s1)
  lw    $t2, 0xc($s1)
.L70009F38:
  addiu $s1, $s1, 8
  sltu  $at, $t2, $s2
  bnezl $at, .L70009F38
  lw    $t2, 0xc($s1)
  lw    $t3, ($s1)
.L70009F4C:
  bnel  $s5, $t3, .L70009F60
  move  $a1, $s1
  b     .L70009F84
  move  $v0, $zero
  move  $a1, $s1
.L70009F60:
  lw    $v1, ($a1)
.L70009F64:
  lw    $t5, 4($a1)
  addu  $t4, $v1, $s2
  subu  $t6, $t5, $s2
  sw    $t4, ($a1)
  bnez  $t6, .L70009F80
  sw    $t6, 4($a1)
  sw    $zero, ($a1)
.L70009F80:
  move  $v0, $v1
.L70009F84:
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
glabel mem_related_something_find_first_0
  lui   $t9, %hi(ptr_table_allocated_mem_blocks + 0x10) 
  lw    $t9, %lo(ptr_table_allocated_mem_blocks + 0x10)($t9)
  lui   $t8, %hi(ptr_table_allocated_mem_blocks + 0x10) 
  li    $t2, -1
  addiu $t8, %lo(ptr_table_allocated_mem_blocks + 0x10) # addiu $t8, $t8, 0x3c38
  move  $a3, $a1
  beq   $t2, $t9, .L70009FF4
  move  $v1, $t8
  lw    $a1, ($t8)
.L70009FCC:
  bnel  $a0, $a1, .L70009FE8
  lw    $a1, 8($v1)
  lw    $a2, 4($v1)
  sltu  $at, $a2, $a3
  beql  $at, $zero, .L7000A000
  addu  $t3, $a1, $a3
  lw    $a1, 8($v1)
.L70009FE8:
  addiu $v1, $v1, 8
  bne   $t2, $a1, .L70009FCC
  nop   
.L70009FF4:
  jr    $ra
  move  $v0, $zero
  addu  $t3, $a1, $a3
.L7000A000:
  subu  $t4, $a2, $a3
  sw    $t3, ($v1)
  bnez  $t4, .L7000A014
  sw    $t4, 4($v1)
  sw    $zero, ($v1)
.L7000A014:
  move  $v0, $a0
  jr    $ra
  nop   
");

void mem_related_model_room_buffers_0(unsigned int addr, unsigned int size) {
  memaAllocRoomBuffer(addr, size);
}

asm(R"
glabel mem_related_allocated_table_related
  lui   $v1, %hi(ptr_table_allocated_mem_blocks)
  lui   $v0, %hi(ptr_table_allocated_mem_blocks + 0xFE0)
  addiu $v0, %lo(ptr_table_allocated_mem_blocks + 0xFE0) # addiu $v0, $v0, 0x4c08
  addiu $v1, %lo(ptr_table_allocated_mem_blocks) # addiu $v1, $v1, 0x3c28
  addiu $v1, $v1, 0x20
.L7000A054:
  bnel  $v1, $v0, .L7000A054
  addiu $v1, $v1, 0x20
  jr    $ra
  nop   
");

asm(R"
glabel mem_related_something_first_related
  lui   $t6, %hi(ptr_table_allocated_mem_blocks + 0x10) 
  lw    $t6, %lo(ptr_table_allocated_mem_blocks + 0x10)($t6)
  li    $a2, -1
  lui   $a0, %hi(ptr_table_allocated_mem_blocks + 0x10)
  move  $v0, $zero
  move  $v1, $zero
  beq   $a2, $t6, .L7000A0A8
   addiu $a0, %lo(ptr_table_allocated_mem_blocks + 0x10) # addiu $a0, $a0, 0x3c38
  lw    $a1, 4($a0)
.L7000A088:
  sltu  $at, $v1, $a1
  beqz  $at, .L7000A098
   addu  $v0, $v0, $a1
  move  $v1, $a1
.L7000A098:
  lw    $t7, 8($a0)
  addiu $a0, $a0, 8
  bnel  $a2, $t7, .L7000A088
   lw    $a1, 4($a0)
.L7000A0A8:
  bnez  $v0, .L7000A0BC
   subu  $t8, $v0, $v1
  mtc1  $zero, $f0
  jr    $ra
   nop   

.L7000A0BC:
  mtc1  $t8, $f4
  mtc1  $v0, $f10
  bgez  $t8, .L7000A0DC
   cvt.s.w $f6, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7000A0DC:
  bgez  $v0, .L7000A0F4
   cvt.s.w $f16, $f10
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f18
  nop   
  add.s $f16, $f16, $f18
.L7000A0F4:
  div.s $f0, $f6, $f16
  jr    $ra
   nop   
");

const char aD_3[] = "%d ", a___[] = "...", aD_5[] = "[%d]";

asm(R"
glabel generate_list_alloc_mem
  addiu $sp, $sp, -0x1068
  lui   $a0, %hi(ptr_table_allocated_mem_blocks + 0x10)
  lw    $a0, %lo(ptr_table_allocated_mem_blocks + 0x10)($a0)
  sw    $s5, 0x2c($sp)
  sw    $s0, 0x18($sp)
  li    $s5, -1
  sw    $s2, 0x20($sp)
  lui   $s0, %hi(ptr_table_allocated_mem_blocks + 0x10)
  sw    $ra, 0x3c($sp)
  sw    $fp, 0x38($sp)
  sw    $s7, 0x34($sp)
  sw    $s6, 0x30($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s1, 0x1c($sp)
  lui   $v1, 0x8000
  move  $s2, $zero
  addiu $s0, %lo(ptr_table_allocated_mem_blocks + 0x10) # addiu $s0, $s0, 0x3c38
  beq   $s5, $a0, .L7000A16C
   move  $v0, $zero
.L7000A150:
  lw    $t7, 8($s0)
  lw    $t6, 4($s0)
  addiu $s0, $s0, 8
  bne   $s5, $t7, .L7000A150
   addu  $v0, $v0, $t6
  lui   $s0, %hi(ptr_table_allocated_mem_blocks + 0x10)
  addiu $s0, %lo(ptr_table_allocated_mem_blocks + 0x10) # addiu $s0, $s0, 0x3c38
.L7000A16C:
  lui   $fp, %hi(a___) 
  lui   $s6, %hi(aD_3)
  addiu $s1, $sp, 0x54
  addiu $s6, %lo(aD_3) # addiu $s6, $s6, -0x6e20
  addiu $fp, %lo(a___) # addiu $fp, $fp, -0x6e1c
  move  $s3, $zero
  move  $s4, $zero
  li    $s7, 200
.L7000A18C:
  beq   $s5, $a0, .L7000A1C4
   nop   
  lw    $v0, 4($s0)
.L7000A198:
  sltu  $at, $v0, $v1
  beqz  $at, .L7000A1B4
   sltu  $at, $s3, $v0
  beql  $at, $zero, .L7000A1B8
   lw    $t8, 8($s0)
  move  $s3, $v0
  addiu $s4, $s4, 1
.L7000A1B4:
  lw    $t8, 8($s0)
.L7000A1B8:
  addiu $s0, $s0, 8
  bnel  $s5, $t8, .L7000A198
   lw    $v0, 4($s0)
.L7000A1C4:
  beqz  $s4, .L7000A250
   lui   $s0, %hi(ptr_table_allocated_mem_blocks + 0x10)
  addiu $s0, %lo(ptr_table_allocated_mem_blocks + 0x10) # addiu $s0, $s0, 0x3c38
  beq   $s5, $a0, .L7000A244
   move  $s4, $zero
  lw    $v0, 4($s0)
.L7000A1DC:
  slti  $at, $s2, 0xc8
  bnel  $s3, $v0, .L7000A228
   lw    $t0, 8($s0)
  beqz  $at, .L7000A20C
   move  $a0, $s1
  addiu $a2, $v0, 0x200
  srl   $t9, $a2, 0xa
  move  $a2, $t9
  jal   sprintf
   move  $a1, $s6
  b     .L7000A220
   addu  $s1, $s1, $v0
.L7000A20C:
  bne   $s2, $s7, .L7000A220
   move  $a0, $s1
  jal   sprintf
   move  $a1, $fp
  addu  $s1, $s1, $v0
.L7000A220:
  addiu $s2, $s2, 1
  lw    $t0, 8($s0)
.L7000A228:
  addiu $s0, $s0, 8
  bnel  $s5, $t0, .L7000A1DC
   lw    $v0, 4($s0)
  lui   $s0, %hi(ptr_table_allocated_mem_blocks + 0x10)
  lui   $a0, %hi(ptr_table_allocated_mem_blocks + 0x10)
  lw    $a0, %lo(ptr_table_allocated_mem_blocks + 0x10)($a0)
  addiu $s0, %lo(ptr_table_allocated_mem_blocks + 0x10) # addiu $s0, $s0, 0x3c38
.L7000A244:
  move  $v1, $s3
  b     .L7000A18C
   move  $s3, $zero
.L7000A250:
  slti  $at, $s2, 0xc9
  bnez  $at, .L7000A26C
   move  $a0, $s1
  lui   $a1, %hi(aD_5)
  addiu $a1, %lo(aD_5) # addiu $a1, $a1, -0x6e18
  jal   sprintf
   move  $a2, $s2
.L7000A26C:
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
   addiu $sp, $sp, 0x1068
");

void memaGenerateListsBeforeAfterMerge(void) {
  int count;
  generate_list_alloc_mem();
  for (count = 0; count != 0x1fc; count += 1)
    memaSortMergeEntries(&ptr_table_allocated_mem_blocks);
  generate_list_alloc_mem();
}

asm(R"
glabel mem_related_something_first_related_0
  addiu $sp, $sp, -0x28
  lui   $t7, %hi(ptr_table_allocated_mem_blocks + 0x10) 
  lw    $t7, %lo(ptr_table_allocated_mem_blocks + 0x10)($t7)
  sw    $s3, 0x20($sp)
  lui   $t6, %hi(ptr_table_allocated_mem_blocks + 0x10) 
  li    $s3, -1
  sw    $s2, 0x1c($sp)
  sw    $s0, 0x14($sp)
  addiu $t6, %lo(ptr_table_allocated_mem_blocks + 0x10) # addiu $t6, $t6, 0x3c38
  move  $s2, $a0
  sw    $ra, 0x24($sp)
  sw    $s1, 0x18($sp)
  beq   $s3, $t7, .L7000A354
   move  $s0, $t6
  lw    $s1, ($t6)
  lw    $t8, 4($s0)
.L7000A338:
  move  $a1, $s0
  jalr  $s2
  addu  $a0, $s1, $t8
  lw    $s1, 8($s0)
  addiu $s0, $s0, 8
  bnel  $s3, $s1, .L7000A338
   lw    $t8, 4($s0)
.L7000A354:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
glabel mem_related_0
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  jal   memaSortMergeAllEntries
   sw    $zero, 0x18($sp)
  lui   $t6, %hi(ptr_table_allocated_mem_blocks + 0x10) 
  lw    $t6, %lo(ptr_table_allocated_mem_blocks + 0x10)($t6)
  li    $a1, -1
  lui   $v0, %hi(ptr_table_allocated_mem_blocks + 0x10)
  lw    $a0, 0x18($sp)
  beq   $a1, $t6, .L7000A3C0
   addiu $v0, %lo(ptr_table_allocated_mem_blocks + 0x10) # addiu $v0, $v0, 0x3c38
  lw    $v1, 4($v0)
.L7000A3A0:
  sltu  $at, $a0, $v1
  beql  $at, $zero, .L7000A3B4
   lw    $t7, 8($v0)
  move  $a0, $v1
  lw    $t7, 8($v0)
.L7000A3B4:
  addiu $v0, $v0, 8
  bnel  $a1, $t7, .L7000A3A0
   lw    $v1, 4($v0)
.L7000A3C0:
  beqz  $a0, .L7000A3D0
   lw    $ra, 0x14($sp)
  b     .L7000A3D4
   move  $v0, $a0
.L7000A3D0:
  move  $v0, $zero
.L7000A3D4:
  jr    $ra
   addiu $sp, $sp, 0x20
");

asm(R"
glabel mem_related_1
  addiu $sp, $sp, -0x18
  sltu  $at, $a1, $a2
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  beqz  $at, .L7000A418
   move  $a3, $a1
  addu  $a0, $a0, $a1
  jal   mem_related_something_find_first_0
   subu  $a1, $a2, $a1
  bnez  $v0, .L7000A410
   nop   
  b     .L7000A434
   move  $v0, $zero
.L7000A410:
  b     .L7000A434
   li    $v0, 1
.L7000A418:
  sltu  $at, $a2, $a3
  beqz  $at, .L7000A430
   lw    $t1, 0x18($sp)
  addu  $a0, $t1, $a2
  jal   mem_related_model_room_buffers_0
   subu  $a1, $a3, $a2
.L7000A430:
  li    $v0, 1
.L7000A434:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");
