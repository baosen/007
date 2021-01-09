// This file contains code to handle memory banks.
typedef struct s_mempBANK {
  int bankstart;
  int nextentry;
  int bankend;
  int data2;
} s_mempBANK;

typedef struct s_mempMVALS {
  unsigned int D_80024410;
  unsigned int D_80024414;
  unsigned int mf;
  unsigned int D_8002441C;
  unsigned int ml;
  unsigned int D_80024424;
  unsigned int me;
  unsigned int D_8002442C;
  unsigned int D_80024430;
} s_mempMVALS;

typedef struct s_mempMEMSTARTS {
  int bank1start;
  int bank2start;
  int bank3start;
  int bank4start;
  int bank5start;
  int bank6start;
  int bank7start;
} s_mempMEMSTARTS;

void something_with_memp_c_debug(void);
void mempCheckMemflagTokens(int bstart, int bsize);
void mempSetBankStarts(int *banks);
unsigned int mempAllocBytesInBank(unsigned int bytes, unsigned char bank);
unsigned int mempAddEntryOfSizeToBank(int ptrdata, int size,
                                      unsigned char bank);
void nulled_mempLoopAllMemBanks(void);
int mempGetBankSizeLeft(unsigned char bank);
unsigned int mempAllocPackedBytesInBank(unsigned int param_1);
void mempResetBank(unsigned char bank);
void mempNullNextEntryInBank(unsigned char bank);

struct s_mempBANK memory_bank_ptrs[0x7];

void *ptr_memp_c_debug_debug_notice_list = 0;
int needmemallocation = 0;
int D_80024408 = 0;
int D_8002440C = 0;

struct s_mempMVALS sdefaultmvals = {
    0,    // D_80024410
    2,    // D_80024414
    0,    // mf
    4,    // D_8002441C
    0x52, // ml
    6,    // D_80024424
    0xF,  // me
    0,    // D_8002442C
    0     // D_80024430
};

struct s_mempMEMSTARTS sdefaultmemstarts = {
    0, // bank1start
    0, // bank2start
    0, // bank3start
    0, // bank4start
    0, // bank5start
    0, // bank6start
    0  // bank7start
};

void something_with_memp_c_debug(void) {
  get_ptr_debug_notice_list_entry(&ptr_memp_c_debug_debug_notice_list,
                                  "memp_c_debug");
}

const char aMf[] = "-mf";
const char aMf_0[] = "-mf";
const char aMl[] = "-ml";
const char aMl_0[] = "-ml";
const char aMe[] = "-me";
const char aMe_0[] = "-me";
/*
 * Initialize memory allocation table and set font and text bank sizes.
 * Accepts: A0=p->buffer, A1=size
 */
asm(R"
glabel checkMemflagTokens
  lui   $v0, %hi(memory_bank_ptrs)
  addiu $v0, %lo(memory_bank_ptrs) # addiu $v0, $v0, 0x3bb0
  addiu $sp, $sp, -0x40
  addu  $t7, $a0, $a1
  lui   $t9, %hi(sdefaultmvals +0x4) 
  sw    $ra, 0x14($sp)
  sw    $a1, 0x44($sp)
  sw    $a0, ($v0)
  sw    $t7, 8($v0)
  addiu $t9, %lo(sdefaultmvals +0x4) # addiu $t9, $t9, 0x4414
  lw    $at, ($t9)
  lw    $t1, 4($t9)
  addiu $t8, $sp, 0x20
  sw    $at, ($t8)
  sw    $t1, 4($t8)
  lw    $t1, 0xc($t9)
  lw    $at, 8($t9)
  lui   $a1, %hi(aMf)
  sw    $t1, 0xc($t8)
  sw    $at, 8($t8)
  lw    $at, 0x10($t9)
  lw    $t1, 0x14($t9)
  addiu $a1, %lo(aMf) # addiu $a1, $a1, -0x6e50
  sw    $at, 0x10($t8)
  sw    $t1, 0x14($t8)
  lw    $t1, 0x1c($t9)
  lw    $at, 0x18($t9)
  li    $a0, 1
  sw    $t1, 0x1c($t8)
  jal   check_token
   sw    $at, 0x18($t8)
  beqz  $v0, .L70009450
   li    $a0, 1
  lui   $a1, %hi(aMf_0)
  jal   check_token
   addiu $a1, %lo(aMf_0) # addiu $a1, $a1, -0x6e4c
  move  $a0, $v0
  move  $a1, $zero
  jal   strtol
   move  $a2, $zero
  sw    $v0, 0x24($sp)
.L70009450:
  lui   $a1, %hi(aMl)
  addiu $a1, %lo(aMl) # addiu $a1, $a1, -0x6e48
  jal   check_token
   li    $a0, 1
  beqz  $v0, .L70009488
   li    $a0, 1
  lui   $a1, %hi(aMl_0)
  jal   check_token
   addiu $a1, %lo(aMl_0) # addiu $a1, $a1, -0x6e44
  move  $a0, $v0
  move  $a1, $zero
  jal   strtol
   move  $a2, $zero
  sw    $v0, 0x2c($sp)
.L70009488:
  lui   $a1, %hi(aMe)
  addiu $a1, %lo(aMe) # addiu $a1, $a1, -0x6e40
  jal   check_token
   li    $a0, 1
  beqz  $v0, .L700094C0
   li    $a0, 1
  lui   $a1, %hi(aMe_0)
  jal   check_token
   addiu $a1, %lo(aMe_0) # addiu $a1, $a1, -0x6e3c
  move  $a0, $v0
  move  $a1, $zero
  jal   strtol
   move  $a2, $zero
  sw    $v0, 0x34($sp)
.L700094C0:
  lw    $v1, 0x34($sp)
  lui   $t2, %hi(j_text_trigger) 
  bnez  $v1, .L700094FC
   nop   
  lw    $t2, %lo(j_text_trigger)($t2)
  sw    $zero, 0x24($sp)
  li    $v0, 296
  beqz  $t2, .L700094EC
   lw    $t3, 0x44($sp)
  b     .L700094EC
   li    $v0, 308
.L700094EC:
  sll   $v1, $v0, 0xa
  subu  $t4, $t3, $v1
  sw    $t4, 0x2c($sp)
  sw    $v1, 0x34($sp)
.L700094FC:
  jal   mempSetBankStarts
   addiu $a0, $sp, 0x20
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x40
  jr    $ra
   nop   
");

/**
 *     initialize allocations using table A0
 *     accepts: A0=p->allocation sizes
 */
asm(R"
glabel mempSetBankStarts
  addiu $sp, $sp, -0x80
  lui   $t6, %hi(sdefaultmemstarts) 
  sw    $ra, 0x24($sp)
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  addiu $t6, %lo(sdefaultmemstarts) # addiu $t6, $t6, 0x4434
  lw    $at, ($t6)
  addiu $s2, $sp, 0x60
  lui   $s3, %hi(memory_bank_ptrs)
  sw    $at, ($s2)
  lw    $t9, 4($t6)
  move  $v0, $a0
  addiu $s3, %lo(memory_bank_ptrs) # addiu $s3, $s3, 0x3bb0
  sw    $t9, 4($s2)
  lw    $at, 8($t6)
  addiu $s0, $sp, 0x60
  addiu $s1, $sp, 0x7c
  sw    $at, 8($s2)
  lw    $t9, 0xc($t6)
  sw    $t9, 0xc($s2)
  lw    $at, 0x10($t6)
  sw    $at, 0x10($s2)
  lw    $t9, 0x14($t6)
  sw    $t9, 0x14($s2)
  lw    $at, 0x18($t6)
  sw    $at, 0x18($s2)
  lw    $v1, ($a0)
  lw    $t0, 4($v0)
.L7000958C:
  sll   $t1, $v1, 2
  addu  $t2, $s2, $t1
  sw    $t0, ($t2)
  lw    $v1, 8($v0)
  addiu $v0, $v0, 8
  bnezl $v1, .L7000958C
   lw    $t0, 4($v0)
  lw    $v1, ($s0)
  addiu $a0, $sp, 0x78
.L700095B0:
  lw    $t4, 4($s0)
  addiu $s0, $s0, 4
  sltu  $at, $s0, $a0
  addu  $v0, $t4, $v1
  move  $v1, $v0
  bnez  $at, .L700095B0
   sw    $v0, ($s0)
  lw    $t5, 8($s3)
  lw    $t8, ($s3)
  lw    $v0, 0x78($sp)
  addiu $s0, $sp, 0x60
  subu  $v1, $t5, $t8
  sra   $t6, $v1, 0x1f
  sra   $t0, $v0, 0x1f
  sw    $t0, 0x30($sp)
  sw    $t6, 0x38($sp)
  sw    $v1, 0x3c($sp)
  sw    $v0, 0x34($sp)
.L700095F8:
  lw    $a1, ($s0)
  lw    $a2, 0x38($sp)
  lw    $a3, 0x3c($sp)
  jal   __ll_mul
   sra   $a0, $a1, 0x1f
  move  $a0, $v0
  move  $a1, $v1
  lw    $a2, 0x30($sp)
  jal   __ll_div
   lw    $a3, 0x34($sp)
  addiu $s0, $s0, 4
  sltu  $at, $s0, $s1
  bnez  $at, .L700095F8
   sw    $v1, -4($s0)
  addiu $s0, $sp, 0x60
  addiu $v0, $sp, 0x7c
.L70009638:
  lw    $t3, ($s0)
  addiu $s0, $s0, 4
  sltu  $at, $s0, $v0
  ori   $t4, $t3, 0xf
  xori  $t5, $t4, 0xf
  bnez  $at, .L70009638
   sw    $t5, -4($s0)
  lw    $a2, ($s3)
  lw    $t8, 0x60($sp)
  lw    $t7, 0x64($sp)
  lui   $at, %hi(memory_bank_ptrs+0x14)
  addu  $t6, $t8, $a2
  sw    $t6, %lo(memory_bank_ptrs+0x10)($at)
  sw    $zero, %lo(memory_bank_ptrs+0x14)($at)
  lui   $at, %hi(memory_bank_ptrs+0x18)
  addu  $v0, $t7, $a2
  sw    $v0, %lo(memory_bank_ptrs+0x18)($at)
  lw    $t0, 0x68($sp)
  lui   $at, %hi(memory_bank_ptrs+0x24)
  sw    $v0, %lo(memory_bank_ptrs+0x20)($at)
  sw    $zero, %lo(memory_bank_ptrs+0x24)($at)
  lui   $at, %hi(memory_bank_ptrs+0x28)
  addu  $t1, $t0, $a2
  sw    $t1, %lo(memory_bank_ptrs+0x28)($at)
  li    $a3, 2
  sll   $t9, $a3, 4
  addu  $v0, $s3, $t9
  sll   $t2, $a3, 2
  addu  $s0, $s2, $t2
  lw    $t8, 8($s0)
  lw    $t6, 0xc($s0)
  lw    $t5, 4($s0)
  lw    $t7, 0x10($s0)
  lw    $t3, ($s0)
  addu  $a0, $t8, $a2
  addu  $a1, $t6, $a2
  addu  $v1, $t5, $a2
  addu  $t0, $t7, $a2
  addu  $t4, $t3, $a2
  sw    $t0, 0x48($v0)
  sw    $v1, 0x20($v0)
  sw    $a1, 0x38($v0)
  sw    $a1, 0x40($v0)
  sw    $a0, 0x28($v0)
  sw    $a0, 0x30($v0)
  sw    $zero, 0x24($v0)
  sw    $zero, 0x34($v0)
  sw    $zero, 0x44($v0)
  sw    $t4, 0x10($v0)
  sw    $zero, 0x14($v0)
  sw    $v1, 0x18($v0)
  lw    $ra, 0x24($sp)
  lw    $s3, 0x20($sp)
  lw    $s2, 0x1c($sp)
  lw    $s1, 0x18($sp)
  lw    $s0, 0x14($sp)
  jr    $ra
   addiu $sp, $sp, 0x80
");

asm(R"
glabel mempAllocBytesInBank
  addiu $sp, $sp, -0x18
  sw    $a1, 0x1c($sp)
  andi  $a3, $a1, 0xff
  lui   $a1, %hi(memory_bank_ptrs)
  lui   $t2, %hi(needmemallocation) 
  addiu $t2, %lo(needmemallocation) # addiu $t2, $t2, 0x4404
  addiu $a1, %lo(memory_bank_ptrs) # addiu $a1, $a1, 0x3bb0
  sw    $ra, 0x14($sp)
  move  $a2, $a0
  sll   $t8, $a3, 4
.L70009748:
  addu  $v1, $a1, $t8
  lw    $v0, 4($v1)
  bnez  $v0, .L7000976C
   move  $t0, $v0
  li    $t9, 1
  lui   $at, %hi(needmemallocation)
  sw    $t9, %lo(needmemallocation)($at)
.L70009764:
  b     .L70009764
   nop   
.L7000976C:
  lw    $a0, 8($v1)
  addu  $t5, $v0, $a2
  sltu  $at, $a0, $v0
  beql  $at, $zero, .L70009794
   sltu  $at, $a0, $t5
  jal   nulled_mempLoopAllMemBanks
   li    $a3, 6
.L70009788:
  b     .L70009788
   nop   
  sltu  $at, $a0, $t5
.L70009794:
  beql  $at, $zero, .L700097E8
   addu  $t5, $v0, $a2
  lw    $t7, 0x64($a1)
  lw    $t6, 0x68($a1)
  li    $a3, 6
  addu  $t8, $t7, $a2
  sltu  $at, $t6, $t8
  bnez  $at, .L700097D4
   nop   
  lw    $v0, ($t2)
  li    $t9, 1
  sw    $t9, ($t2)
  bnezl $v0, .L70009748
   sll   $t8, $a3, 4
  b     .L70009748
   sll   $t8, $a3, 4
.L700097D4:
  jal   nulled_mempLoopAllMemBanks
   nop   
.L700097DC:
  b     .L700097DC
   nop   
  addu  $t5, $v0, $a2
.L700097E8:
  sw    $t5, 4($v1)
  sw    $t0, 0xc($v1)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  move  $v0, $t0
  jr    $ra
   nop   
");

/**
 *     updates bank A2 size registry in light of entry at A0 of size A1
 *     accepts: A0=p->allocated data, A1=size of data, A2=bank#
 */
asm(R"
glabel mempAddEntryOfSizeToBank
  lui   $t7, %hi(needmemallocation) 
  lw    $t7, %lo(needmemallocation)($t7)
  addiu $sp, $sp, -0x18
  sw    $a2, 0x20($sp)
  andi  $t6, $a2, 0xff
  move  $a2, $t6
  sw    $ra, 0x14($sp)
  sw    $a1, 0x1c($sp)
  beqz  $t7, .L70009840
   move  $a3, $a0
  lui   $t8, %hi(memory_bank_ptrs+0x6C) 
  lw    $t8, %lo(memory_bank_ptrs+0x6C)($t8)
  bne   $a0, $t8, .L70009840
   nop   
  li    $a2, 6
.L70009840:
  lui   $t2, %hi(memory_bank_ptrs) 
  addiu $t2, %lo(memory_bank_ptrs) # addiu $t2, $t2, 0x3bb0
  sll   $t9, $a2, 4
  addu  $a1, $t9, $t2
  lw    $a0, 4($a1)
  bnezl $a0, .L70009868
   lw    $a2, 0xc($a1)
.L7000985C:
  b     .L7000985C
   nop   
  lw    $a2, 0xc($a1)
.L70009868:
  lw    $t3, 0x1c($sp)
  beql  $a3, $a2, .L70009880
   subu  $v0, $a0, $a2
  b     .L700098E0
   li    $v0, 2
  subu  $v0, $a0, $a2
.L70009880:
  subu  $v1, $t3, $v0
  bgtz  $v1, .L70009898
   addu  $t4, $a0, $v1
  sw    $t4, 4($a1)
  b     .L700098E0
   li    $v0, 1
.L70009898:
  lw    $v0, 8($a1)
  addu  $t5, $a0, $v1
  sltu  $at, $v0, $a0
  beql  $at, $zero, .L700098C0
   sltu  $at, $v0, $t5
  jal   nulled_mempLoopAllMemBanks
   li    $a2, 6
.L700098B4:
  b     .L700098B4
   nop   
  sltu  $at, $v0, $t5
.L700098C0:
  beqz  $at, .L700098D8
   addu  $t6, $a0, $v1
  jal   nulled_mempLoopAllMemBanks
   li    $a2, 6
.L700098D0:
  b     .L700098D0
   nop   
.L700098D8:
  sw    $t6, 4($a1)
  li    $v0, 1
.L700098E0:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

/**
 * V0=8 -- loop eight times, needlessly; fries AT,T6
 * used by "show mem use", step 1; probably originally listed all eight memory
 * allocations
 */
void nulled_mempLoopAllMemBanks(void) {
  int bank;
  for (bank = 1; bank < 7; bank = (bank + 1) & 0xff)
    ;
}

/**
 * V0= total allocated size of bank A0
 *     accepts: A0=bank#
 */
int mempGetBankSizeLeft(unsigned char bank) {
  if (needmemallocation != 0) {
    bank = 6;
  }
  if ((bank == 4) &&
      (memory_bank_ptrs[4].bankstart == memory_bank_ptrs[4].bankend)) {
    bank = 6;
  }
  return memory_bank_ptrs[bank].bankend - memory_bank_ptrs[bank].nextentry;
}

/**
 * allocate A0 coded #bytes in bank
 * accepts: A0=size/bank# entry (ssssssss ssssssss sssssssss sssssbbb)
 */
unsigned int mempAllocPackedBytesInBank(unsigned int param_1) {
  return mempAllocBytesInBank((param_1 >> 3), (param_1 & 7));
}

/**
 * reset memory bank A0 [0-6]
 * copies base address for memory bank A0 to +4, fry +C
 */
void mempResetBank(unsigned char bank) {
  memory_bank_ptrs[bank].data2 = 0;
  memory_bank_ptrs[bank].nextentry = memory_bank_ptrs[bank].bankstart;
}

void mempNullNextEntryInBank(unsigned char bank) {
  nulled_mempLoopAllMemBanks();
  if (memory_bank_ptrs[bank].nextentry != 0) {
    memory_bank_ptrs[bank].nextentry = 0;
  }
}
