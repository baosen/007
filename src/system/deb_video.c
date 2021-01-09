// This file contains code to handle TLB paging and debugging code. TODO: Rename
// filename to something more descriptive...
#include <message.h>
#include <thread.h>

void thread5_translate_7F_address(void);

char thread_video_manager_debugthread[0x6B0];
char tlbStack[0x2300];
OSMesgQueue thread5_MesgQ;
unsigned int thread5_MesgBuf;
OSThread *ptr_tlbthread_maybe;
unsigned int dword_CODE_bss_80063660;
void *current_indy_read_buf_resourceID;
unsigned int *ptr_indy_read_buf_string1, *ptr_indy_read_buf_string2;
char indy_read_buffer[0x60];

void init_tlb(void) {
  set_video_buffer_pointers();
  osCreateMesgQueue(&thread5_MesgQ, &thread5_MesgBuf, 1);
  osCreateThread(&thread_video_manager_debugthread, 5,
                 &thread5_translate_7F_address, 0, &tlbStack, 0x28);
  osStartThread(&thread_video_manager_debugthread);
}

asm(R"
glabel thread5_translate_7F_address
  addiu $sp, $sp, -0x40
  sw    $s7, 0x30($sp)
  lui   $s7, %hi(thread5_MesgQ) 
  addiu $s7, %lo(thread5_MesgQ) # addiu $s7, $s7, 0x3640
  sw    $ra, 0x34($sp)
  sw    $a0, 0x40($sp)
  sw    $s6, 0x2c($sp)
  sw    $s5, 0x28($sp)
  sw    $s4, 0x24($sp)
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  sw    $zero, 0x3c($sp)
  li    $a0, 12
  move  $a1, $s7
  jal   osSetEventMesg
   li    $a2, 16
  lui   $at, %hi(dword_CODE_bss_80063660)
  lui   $s6, %hi(__osRunQueue)
  sw    $zero, %lo(dword_CODE_bss_80063660)($at)
  addiu $s6, %lo(__osRunQueue) # addiu $s6, $s6, 0x7728
  li    $s5, 10
  lui   $s4, 0xffc0
  lui   $s3, 0x7f00
  li    $s2, 8
  addiu $s1, $sp, 0x3c
.L70004FC0:
  move  $a0, $s7
.L70004FC4:
  move  $a1, $s1
  jal   osRecvMesg
   li    $a2, 1
  jal   osSetIntMask
   li    $a0, 1
  jal   __osGetCurrFaultedThread
   move  $s0, $v0
  lui   $at, %hi(ptr_tlbthread_maybe)
  beqz  $v0, .L70004FC0
   sw    $v0, %lo(ptr_tlbthread_maybe)($at)
  lw    $t6, 0x120($v0)
  lui   $t0, %hi(ptr_tlbthread_maybe) 
  andi  $t7, $t6, 0x7c
  bne   $s2, $t7, .L7000505C
   nop   
  lw    $t8, 0x124($v0)
  and   $t9, $t8, $s4
  bne   $s3, $t9, .L7000505C
   nop   
  lw    $t0, %lo(ptr_tlbthread_maybe)($t0)
  jal   translate_load_rom_from_TLBaddress
   lw    $a0, 0x124($t0)
  lui   $t1, %hi(ptr_tlbthread_maybe) 
  lw    $t1, %lo(ptr_tlbthread_maybe)($t1)
  lui   $t2, %hi(ptr_tlbthread_maybe) 
  lui   $a1, %hi(ptr_tlbthread_maybe)
  sh    $s5, 0x10($t1)
  lw    $t2, %lo(ptr_tlbthread_maybe)($t2)
  move  $a0, $s6
  sh    $zero, 0x12($t2)
  jal   __osEnqueueThread
   lw    $a1, %lo(ptr_tlbthread_maybe)($a1)
  jal   osSetIntMask
   move  $a0, $s0
  jal   osYieldThread
   nop   
  b     .L70004FC4
   move  $a0, $s7
.L7000505C:
  jal   osSetIntMask
   move  $a0, $s0
.L70005064:
  b     .L70005064
   nop   
  nop   
  nop   
  nop   
  nop   
  nop   
  lw    $ra, 0x34($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  lw    $s4, 0x24($sp)
  lw    $s5, 0x28($sp)
  lw    $s6, 0x2c($sp)
  lw    $s7, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x40
");

/*
 *     V0= SP, A3=SP usage within function range (A1,A0) with initial SP A2
 *     accepts: A0=p->opcode.cur, A1=p->opcode.start, A2=SP w/i function,
 * A3=p->register buffer
 */
asm(R"
glabel debug_related_8
  addiu $sp, $sp, -0x10
  sw    $a0, 0x10($sp)
  sw    $s1, 0xc($sp)
  sw    $s0, 8($sp)
  move  $v1, $a2
  move  $v0, $zero
  move  $t0, $zero
  li    $a0, 32
  move  $t1, $zero
  move  $t2, $a3
.L700050D4:
  addiu $t1, $t1, 4
  sw    $zero, ($t2)
  sw    $zero, 4($t2)
  sw    $zero, 8($t2)
  sw    $zero, 0xc($t2)
  bne   $t1, $a0, .L700050D4
   addiu $t2, $t2, 0x10
  lw    $a0, 0x10($sp)
  lui   $s1, (0x03E00008 >> 16) # lui $s1, 0x3e0
  ori   $s1, (0x03E00008 & 0xFFFF) # ori $s1, $s1, 8
  sltu  $at, $a0, $a1
  bnez  $at, .L700051B8
   li    $s0, 31
  lui   $t5, 0xffe0
  lui   $t4, 0xafa0
  lui   $t3, 0xffff
  lui   $t2, 0x27bd
  lw    $t1, ($a0)
.L7000511C:
  addiu $a0, $a0, -4
  sltu  $at, $a0, $a1
  and   $t7, $t1, $t3
  bne   $t2, $t7, .L70005158
   and   $t8, $t1, $t5
  sll   $t8, $t1, 0x10
  sra   $t9, $t8, 0x10
  bgtz  $t9, .L700051B8
   li    $v0, 1
  sra   $t6, $t9, 2
  sll   $t7, $t6, 2
  beqz  $t0, .L700051B0
   subu  $v1, $v1, $t7
  b     .L700051B8
   nop   
.L70005158:
  bne   $t4, $t8, .L700051A8
   srl   $a2, $t1, 0x10
  andi  $t9, $a2, 0x1f
  sll   $t7, $t1, 0x10
  sra   $t8, $t7, 0x10
  move  $a2, $t9
  sra   $t9, $t8, 2
  sll   $t6, $t9, 2
  sll   $t8, $a2, 2
  addu  $t9, $a3, $t8
  addu  $t7, $t6, $v1
  bne   $s0, $a2, .L70005190
   sw    $t7, ($t9)
  li    $t0, 1
.L70005190:
  beqz  $v0, .L700051B0
   nop   
  beqz  $t0, .L700051B0
   nop   
  b     .L700051B8
   nop   
.L700051A8:
  beq   $t1, $s1, .L700051B8
   nop   
.L700051B0:
  beql  $at, $zero, .L7000511C
   lw    $t1, ($a0)
.L700051B8:
  beqz  $v0, .L700051D0
   lw    $s0, 8($sp)
  beql  $t0, $zero, .L700051D4
   move  $v0, $zero
  b     .L700051D4
   move  $v0, $v1
.L700051D0:
  move  $v0, $zero
.L700051D4:
  lw    $s1, 0xc($sp)
  jr    $ra
   addiu $sp, $sp, 0x10
");

/*
 *     V0=true if opcode that set RA A0 was a JAL or JALR type within bounds
 * (70000450,70020D90) accepts: A0=p->70-mapped TLB function, presumably from RA
 */
asm(R"
glabel was_opcode_In_70000450_70020D90
  andi  $t6, $a0, 3
  bnez  $t6, .L7000524C
  lui   $t7, %hi(_kernelSegmentStart) # $t7, 0x7000
  addiu $t7, %lo(_kernelSegmentStart) # addiu $t7, $t7, 0x450
  sltu  $at, $a0, $t7
  bnez  $at, .L7000524C
  lui   $t8, %hi(_kernelSegmentEnd) # $t8, 0x7002
  addiu $t8, %lo(_kernelSegmentEnd) # addiu $t8, $t8, 0xd90
  sltu  $at, $t8, $a0
  bnezl $at, .L70005250
  move  $v0, $zero
  lw    $v0, -8($a0)
  lui   $at, (0xFC00003C >> 16) # lui $at, 0xfc00
  ori   $at, (0xFC00003C & 0xFFFF) # ori $at, $at, 0x3c
  and   $t9, $v0, $at
  li    $at, 9
  bnel  $t9, $at, .L70005234
  lui   $at, 0xfc00
  jr    $ra
  li    $v0, 1

  lui   $at, 0xfc00
.L70005234:
  and   $t0, $v0, $at
  lui   $at, 0xc00
  bnel  $t0, $at, .L70005250
  move  $v0, $zero
  jr    $ra
  li    $v0, 1

.L7000524C:
  move  $v0, $zero
.L70005250:
  jr    $ra
  nop
");

/*
 *     V0= strlen(A0); used exclusively for scanning ind.rea.buf
 *     accepts: A0=p->string
 */
asm(R"
glabel return_strlen
  lbu   $v0, ($a0)
  move  $v1, $zero
  addiu $a0, $a0, 1
  beqz  $v0, .L7000528C
   nop   
  addiu $v1, $v1, 1
.L70005270:
  slti  $at, $v1, 0x100
  beqz  $at, .L7000528C
   nop   
  lbu   $v0, ($a0)
  addiu $a0, $a0, 1
  bnezl $v0, .L70005270
   addiu $v1, $v1, 1
.L7000528C:
  jr    $ra
   move  $v0, $v1
");

/*
 *     V0= total size of one word, two strings at hardware A0
 *     accepts: A0=hardware address
 */
asm(R"
glabel indy_file_get_address_subsequent_data
  addiu $sp, $sp, -0x20
  sw    $a0, 0x20($sp)
  sw    $ra, 0x14($sp)
  lui   $a0, %hi(indy_read_buffer)
  addiu $a0, %lo(indy_read_buffer) # addiu $a0, $a0, 0x3670
  lw    $a1, 0x20($sp)
  jal   romCopy
   li    $a2, 96
  lui   $t6, %hi(indy_read_buffer) 
  lw    $t6, %lo(indy_read_buffer)($t6)
  lui   $v0, %hi(ptr_indy_read_buf_string1)
  lui   $at, %hi(current_indy_read_buf_resourceID)
  lui   $t7, %hi(indy_read_buffer+4)
  addiu $v0, %lo(ptr_indy_read_buf_string1) # addiu $v0, $v0, 0x3668
  addiu $a0, $t7, %lo(indy_read_buffer+4)
  sw    $t6, %lo(current_indy_read_buf_resourceID)($at)
  jal   return_strlen
   sw    $a0, ($v0)
  lui   $a0, %hi(ptr_indy_read_buf_string1)
  lw    $a0, %lo(ptr_indy_read_buf_string1)($a0)
  lui   $at, %hi(ptr_indy_read_buf_string2)
  addu  $t8, $v0, $a0
  addiu $t9, $t8, 1
  jal   return_strlen
   sw    $t9, %lo(ptr_indy_read_buf_string2)($at)
  lui   $a0, %hi(ptr_indy_read_buf_string2)
  lw    $a0, %lo(ptr_indy_read_buf_string2)($a0)
  jal   return_strlen
   sw    $v0, 0x18($sp)
  lw    $t0, 0x20($sp)
  lw    $t2, 0x18($sp)
  lw    $ra, 0x14($sp)
  addu  $t1, $v0, $t0
  addu  $v1, $t1, $t2
  addiu $v1, $v1, 6
  andi  $t3, $v1, 3
  beqz  $t3, .L70005334
   move  $a0, $v1
  ori   $a0, $v1, 3
  addiu $a0, $a0, 1
.L70005334:
  move  $v0, $a0
  jr    $ra
   addiu $sp, $sp, 0x20
");

/*
 *     scan for and load resourceID A0 from indy.read.buf
 *     accepts: A0=resourceID
 */
asm(R"
glabel scan_load_resourceID_from_indy_read_buf
  addiu $sp, $sp, -0x28
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  lui   $v0, 0xe0
  ori   $s3, $v0, 4
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  lui   $s2, %hi(current_indy_read_buf_resourceID)
  move  $s1, $a0
  sw    $ra, 0x24($sp)
  move  $s0, $s3
  addiu $s2, %lo(current_indy_read_buf_resourceID) # addiu $s2, $s2, 0x3664
.L70005370:
  jal   indy_file_get_address_subsequent_data
   move  $a0, $s0
  lw    $v1, ($s2)
  sltu  $at, $s1, $v1
  bnez  $at, .L700053A0
   nop   
  bnez  $v1, .L70005398
   move  $s3, $s0
  b     .L700053AC
   move  $v0, $zero
.L70005398:
  b     .L70005370
   move  $s0, $v0
.L700053A0:
  jal   indy_file_get_address_subsequent_data
   move  $a0, $s3
  li    $v0, 1
.L700053AC:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

/*
 *     V0= true if valid indy.read.buf.resourceID	[matches 826475BE]
 */
asm(R"
glabel is_valid_indy_read_buf_resourceID
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   indy_file_get_address_subsequent_data
   lui   $a0, 0xe0
  lui   $v0, %hi(current_indy_read_buf_resourceID)
  lw    $v0, %lo(current_indy_read_buf_resourceID)($v0)
  lw    $ra, 0x14($sp)
  lui   $at, (0x826475BE >> 16) # lui $at, 0x8264
  ori   $at, (0x826475BE & 0xFFFF) # ori $at, $at, 0x75be
  xor   $t6, $v0, $at
  sltiu $v0, $t6, 1
  jr    $ra
   addiu $sp, $sp, 0x18
");

void debug_indy_stub(void) {}
void debug_indy_stub_0(void) {}
void debug_indy_stub_1(void) {}

void *return_indy_read_buf_resourceID(void) {
  return current_indy_read_buf_resourceID;
}

/*
 *     V0=hardcoded SP for debug thread A1, corrected for address range A0
 *     accepts: A0=p->address space, A1=entry#
 */
asm(R"
glabel debug_sp_related_11
  lui   $t6, %hi(stack_ptrs_1) 
  addiu $t6, %lo(stack_ptrs_1) # addiu $t6, $t6, 0x36dc
  lw    $at, ($t6)
  addiu $sp, $sp, -0x30
  addiu $a3, $sp, 0x1c
  sw    $at, ($a3)
  lw    $t9, 4($t6)
  lui   $t1, %hi(stack_ptrs_2) 
  addiu $t1, %lo(stack_ptrs_2) # addiu $t1, $t1, 0x36f0
  sw    $t9, 4($a3)
  lw    $at, 8($t6)
  addiu $t0, $sp, 8
  move  $a2, $a0
  sw    $at, 8($a3)
  lw    $t9, 0xc($t6)
  sw    $t9, 0xc($a3)
  lw    $at, 0x10($t6)
  sw    $at, 0x10($a3)
  lw    $at, ($t1)
  sw    $at, ($t0)
  lw    $t4, 4($t1)
  sw    $t4, 4($t0)
  lw    $at, 8($t1)
  sw    $at, 8($t0)
  lw    $t4, 0xc($t1)
  sw    $t4, 0xc($t0)
  lw    $at, 0x10($t1)
  blez  $a1, .L700054A0
   sw    $at, 0x10($t0)
  sltiu $at, $a1, 6
  bnez  $at, .L700054A8
   sll   $v0, $a1, 2
.L700054A0:
  b     .L700054DC
   move  $v0, $zero
.L700054A8:
  lui   $at, 0x8000
  addu  $t5, $a3, $v0
  addu  $t8, $t0, $v0
  sltu  $at, $a2, $at
  lw    $v1, ($t5)
  bnez  $at, .L700054CC
   lw    $a0, ($t8)
  b     .L700054DC
   move  $v0, $a0
.L700054CC:
  lui   $at, 0xf000
  and   $t7, $a2, $at
  subu  $t6, $a0, $v1
  or    $v0, $t7, $t6
.L700054DC:
  jr    $ra
   addiu $sp, $sp, 0x30
");

/*
 *     V0=hardcoded SP for debug thread A1, corrected for address range A0
 *     accepts: A0=p->address space, A1=entry#
 */
asm(R"
glabel debug_sp_related_12
  lui   $t6, %hi(stack_ptrs_3) 
  addiu $t6, %lo(stack_ptrs_3) # addiu $t6, $t6, 0x3704
  lw    $at, ($t6)
  addiu $sp, $sp, -0x18
  addiu $v0, $sp, 4
  sw    $at, ($v0)
  lw    $t9, 4($t6)
  sw    $t9, 4($v0)
  lw    $at, 8($t6)
  sw    $at, 8($v0)
  lw    $t9, 0xc($t6)
  sw    $t9, 0xc($v0)
  lw    $at, 0x10($t6)
  blez  $a1, .L7000552C
   sw    $at, 0x10($v0)
  sltiu $at, $a1, 6
  bnez  $at, .L70005534
   sll   $t0, $a1, 2
.L7000552C:
  b     .L70005558
   move  $v0, $zero
.L70005534:
  lui   $at, 0x8000
  addu  $t1, $v0, $t0
  sltu  $at, $a0, $at
  bnez  $at, .L70005550
   lw    $v1, ($t1)
  b     .L70005558
   move  $v0, $v1
.L70005550:
  lui   $at, 0xf000
  and   $v0, $a0, $at
.L70005558:
  jr    $ra
   addiu $sp, $sp, 0x18
");

// maybe newfile, falls on 0 address and logically does different things

/*
 *     V0= true if F12 a normal single precision float
 *     accepts: F12= single-precision float
 */
asm(R"
glabel _is_normal_single_precision_float
  swc1  $f12, ($sp)
  lw    $a0, ($sp)
  lui   $at, (0x007FFFFF >> 16) # lui $at, 0x7f
  ori   $at, (0x007FFFFF & 0xFFFF) # ori $at, $at, 0xffff
  and   $v0, $a0, $at
  sltiu $t6, $v0, 1
  bnez  $t6, .L7000559C
   move  $v0, $t6
  srl   $v1, $a0, 0x17
  andi  $t7, $v1, 0xff
  sltu  $v0, $zero, $t7
  beqz  $v0, .L7000559C
   nop   
  xori  $v0, $t7, 0xff
  sltu  $v0, $zero, $v0
.L7000559C:
  jr    $ra
   nop   
");

/*
 *     V0= true if A1 a normal single precision float; would have set result as
 * short at A0 accepts: A0=(unused) p->target, A1=single-precision float
 */
asm(R"
glabel is_normal_single_precision_float
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  mtc1  $a1, $f12
  jal   _is_normal_single_precision_float
   sw    $a0, 0x18($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

/*
 *     removed: set normality of single-precision floats A1, A2, A3, SP+10 in
 * table at A0
 */
asm(R"
glabel set_normality_of_single_precision_floats
  mtc1  $a1, $f12
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  mfc1  $a1, $f12
  sw    $a0, 0x18($sp)
  sw    $a2, 0x20($sp)
  jal   is_normal_single_precision_float
   sw    $a3, 0x24($sp)
  lw    $a0, 0x18($sp)
  lw    $a1, 0x20($sp)
  jal   is_normal_single_precision_float
   addiu $a0, $a0, 2
  lw    $a0, 0x18($sp)
  lw    $a1, 0x24($sp)
  jal   is_normal_single_precision_float
   addiu $a0, $a0, 4
  lw    $a0, 0x18($sp)
  lw    $a1, 0x28($sp)
  jal   is_normal_single_precision_float
   addiu $a0, $a0, 6
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

void debug_indy_stub_2(void) {}
