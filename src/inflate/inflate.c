// This file is modified from inflate.c found in gzip 1.2.4 from 1993.
#include <stddef.h>
#include <types.h>

#define GETBYTE() (inbuf[inptr++])
#define NEXTBYTE() (unsigned char)GETBYTE()
#define NEEDBITS(n)                                                            \
  {                                                                            \
    while (k < (n)) {                                                          \
      b |= ((unsigned int)NEXTBYTE()) << k;                                    \
      k += 8;                                                                  \
    }                                                                          \
  }
#define DUMPBITS(n)                                                            \
  {                                                                            \
    b >>= (n);                                                                 \
    k -= (n);                                                                  \
  }

unsigned char *inbuf = NULL;
unsigned char *outbuf = NULL;

unsigned int inptr = 0;
unsigned int wp = 0; // current position in slide.

unsigned char *huftlist = NULL;

/* Tables for deflate from PKZIP's appnote.txt. */
unsigned char border[] = {/* Order of the bit length code lengths */
                          16, 17, 18, 0, 8,  7, 9,  6, 10, 5,
                          11, 4,  12, 3, 13, 2, 14, 1, 15};
unsigned short cplens[] = {/* Copy lengths for literal codes 257..285 */
                           3,  4,   5,   6,   7,   8,   9,   10, 11, 13, 15,
                           17, 19,  23,  27,  31,  35,  43,  51, 59, 67, 83,
                           99, 115, 131, 163, 195, 227, 258, 0,  0};
/* note: see note #13 above about the 258 in this list. */
unsigned char cplext[] =
    {/* Extra bits for literal codes 257..285 */
     0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2,  2, 2,
     3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 0, 99, 99}; /* 99==invalid */
unsigned short cpdist[] = {/* Copy offsets for distance codes 0..29 */
                           1,    2,    3,    4,     5,     7,    9,    13,
                           17,   25,   33,   49,    65,    97,   129,  193,
                           257,  385,  513,  769,   1025,  1537, 2049, 3073,
                           4097, 6145, 8193, 12289, 16385, 24577};
unsigned char cpdext[] = {/* Extra bits for distance codes */
                          0, 0, 0, 0, 1, 1, 2, 2,  3,  3,  4,  4,  5,  5,  6,
                          6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13};

unsigned long bb = 0; // bit buffer.
unsigned int bk = 0;  // bits in bit buffer.

/* And'ing with mask[n] masks the lower n bits */
unsigned short mask_bits[] = {
    0x0000, 0x0001, 0x0003, 0x0007, 0x000F, 0x001F, 0x003F, 0x007F, 0x00FF,
    0x01FF, 0x03FF, 0x07FF, 0x0FFF, 0x1FFF, 0x3FFF, 0x7FFF, 0xFFFF,
};

unsigned int lbits = 9;
unsigned int dbits = 6;
unsigned int hufts = 0;

asm(R"
glabel huft_build
  addiu $sp, $sp, -0x5f0
  sw    $s2, 0x10($sp)
  move  $s2, $a0
  sw    $ra, 0x2c($sp)
  sw    $fp, 0x28($sp)
  sw    $s7, 0x24($sp)
  sw    $s6, 0x20($sp)
  sw    $s5, 0x1c($sp)
  sw    $s4, 0x18($sp)
  sw    $s3, 0x14($sp)
  sw    $s1, 0xc($sp)
  sw    $s0, 8($sp)
  sw    $a2, 0x5f8($sp)
  sw    $a3, 0x5fc($sp)
  sw    $zero, 0x5a8($sp)
  addiu $v1, $sp, 0x5ac
  addiu $v0, $sp, 0x5ec
.L70200044:
  addiu $v1, $v1, 0x10
  sw    $zero, -0xc($v1)
  sw    $zero, -8($v1)
  sw    $zero, -4($v1)
  bne   $v1, $v0, .L70200044
   sw    $zero, -0x10($v1)
  andi  $v0, $a1, 3
  negu  $v0, $v0
  move  $ra, $s2
  beqz  $v0, .L702000A0
   move  $s0, $a1
  addu  $v1, $v0, $a1
  addiu $a0, $sp, 0x5a8
.L70200078:
  lw    $t6, ($ra)
  addiu $s0, $s0, -1
  addiu $ra, $ra, 4
  sll   $t7, $t6, 2
  addu  $v0, $a0, $t7
  lw    $t8, ($v0)
  addiu $t9, $t8, 1
  bne   $v1, $s0, .L70200078
   sw    $t9, ($v0)
  beqz  $s0, .L70200110
.L702000A0:
   addiu $a0, $sp, 0x5a8
.L702000A4:
  lw    $t6, ($ra)
  addiu $s0, $s0, -4
  addiu $ra, $ra, 0x10
  sll   $t7, $t6, 2
  addu  $v0, $a0, $t7
  lw    $t8, ($v0)
  addiu $t9, $t8, 1
  sw    $t9, ($v0)
  lw    $t6, -0xc($ra)
  sll   $t7, $t6, 2
  addu  $v0, $a0, $t7
  lw    $t8, ($v0)
  addiu $t9, $t8, 1
  sw    $t9, ($v0)
  lw    $t6, -8($ra)
  sll   $t7, $t6, 2
  addu  $v0, $a0, $t7
  lw    $t8, ($v0)
  addiu $t9, $t8, 1
  sw    $t9, ($v0)
  lw    $t6, -4($ra)
  sll   $t7, $t6, 2
  addu  $v0, $a0, $t7
  lw    $t8, ($v0)
  addiu $t9, $t8, 1
  bnez  $s0, .L702000A4
   sw    $t9, ($v0)
.L70200110:
  lw    $t6, 0x5a8($sp)
  lw    $a2, 0x608($sp)
  li    $a3, 1
  bne   $a1, $t6, .L7020013C
   addiu $t0, $sp, 0x5ac
  lw    $s6, 0x604($sp)
  lw    $a2, 0x608($sp)
  move  $v0, $zero
  sw    $zero, ($s6)
  b     .L70200624
   sw    $zero, ($a2)
.L7020013C:
  lw    $s1, ($a2)
  li    $v0, 17
.L70200144:
  lw    $t7, ($t0)
  bnezl $t7, .L70200160
   sltu  $at, $s1, $a3
  addiu $a3, $a3, 1
  bne   $a3, $v0, .L70200144
   addiu $t0, $t0, 4
  sltu  $at, $s1, $a3
.L70200160:
  beqz  $at, .L7020016C
   move  $s5, $a3
  move  $s1, $a3
.L7020016C:
  li    $s0, 16
  addiu $v0, $sp, 0x5e8
.L70200174:
  lw    $t8, ($v0)
  bnezl $t8, .L70200190
   sltu  $at, $s0, $s1
  addiu $s0, $s0, -1
  bnez  $s0, .L70200174
   addiu $v0, $v0, -4
  sltu  $at, $s0, $s1
.L70200190:
  beqz  $at, .L7020019C
   sw    $s0, 0x5a0($sp)
  move  $s1, $s0
.L7020019C:
  li    $t9, 1
  sltu  $at, $a3, $s0
  sw    $s1, ($a2)
  beqz  $at, .L702001D8
   sllv  $v1, $t9, $a3
  sll   $t6, $s0, 2
  addiu $t7, $sp, 0x5a8
  addu  $a2, $t6, $t7
.L702001BC:
  lw    $t8, ($t0)
  addiu $t0, $t0, 4
  sltu  $at, $t0, $a2
  subu  $v1, $v1, $t8
  sll   $t9, $v1, 1
  bnez  $at, .L702001BC
   move  $v1, $t9
.L702001D8:
  lw    $t0, ($v0)
  addiu $s0, $s0, -1
  move  $a3, $zero
  subu  $v1, $v1, $t0
  addu  $t6, $t0, $v1
  sw    $t6, ($v0)
  sw    $zero, 0x78($sp)
  addiu $ra, $sp, 0x5ac
  addiu $a2, $sp, 0x7c
  sw    $a1, 0x5f4($sp)
  beqz  $s0, .L70200290
   addiu $v0, $v0, -4
  andi  $t0, $s0, 3
  negu  $t0, $t0
  beqz  $t0, .L7020024C
   sw    $a1, 0x5f4($sp)
  addu  $t1, $t0, $s0
  sll   $t7, $t1, 2
  addiu $t8, $sp, 0x5a8
  addu  $a1, $t7, $t8
.L70200228:
  lw    $t9, ($ra)
  addiu $v0, $v0, -4
  addiu $a2, $a2, 4
  addu  $a3, $a3, $t9
  sw    $a3, -4($a2)
  bne   $a1, $v0, .L70200228
   addiu $ra, $ra, 4
  addiu $t6, $sp, 0x5a8
  beq   $v0, $t6, .L70200290
.L7020024C:
   addiu $a1, $sp, 0x5a8
.L70200250:
  lw    $t8, ($ra)
  addiu $v0, $v0, -0x10
  addiu $a2, $a2, 0x10
  addu  $a3, $a3, $t8
  sw    $a3, -0x10($a2)
  lw    $t9, 4($ra)
  addiu $ra, $ra, 0x10
  addu  $a3, $a3, $t9
  sw    $a3, -0xc($a2)
  lw    $t6, -8($ra)
  addu  $a3, $a3, $t6
  sw    $a3, -8($a2)
  lw    $t7, -4($ra)
  addu  $a3, $a3, $t7
  bne   $v0, $a1, .L70200250
   sw    $a3, -4($a2)
.L70200290:
  lw    $t3, 0x5f4($sp)
  move  $ra, $s2
  move  $s0, $zero
  addiu $t1, $sp, 0xbc
  addiu $a2, $sp, 0x74
  lw    $a3, ($ra)
.L702002A8:
  addiu $ra, $ra, 4
  beqz  $a3, .L702002D0
   sll   $t9, $a3, 2
  addu  $v0, $a2, $t9
  lw    $a1, ($v0)
  sll   $t6, $a1, 2
  addu  $t7, $t1, $t6
  sw    $s0, ($t7)
  addiu $t8, $a1, 1
  sw    $t8, ($v0)
.L702002D0:
  addiu $s0, $s0, 1
  sltu  $at, $s0, $t3
  bnezl $at, .L702002A8
   lw    $a3, ($ra)
  lw    $t9, 0x5a0($sp)
  sw    $v1, 0x6c($sp)
  move  $s0, $zero
  slt   $at, $t9, $s5
  sw    $zero, 0x74($sp)
  move  $ra, $t1
  li    $t4, -1
  negu  $t2, $s1
  sw    $zero, 0x53c($sp)
  move  $a2, $zero
  bnez  $at, .L70200608
   move  $t0, $zero
  sll   $t6, $s5, 2
  addiu $t7, $sp, 0x5a8
  addu  $t8, $t6, $t7
  lui   $fp, %hi(huftlist) # $fp, 0x7020
  lui   $s3, %hi(hufts) # $s3, 0x7020
  addiu $s3, %lo(hufts) # addiu $s3, $s3, 0x1598
  addiu $fp, %lo(huftlist) # addiu $fp, $fp, 0x1490
  sw    $t8, 0x50($sp)
  lw    $s6, 0x604($sp)
  addiu $s4, $sp, 0x57c
.L70200338:
  lw    $t9, 0x50($sp)
  lw    $t7, 0x5f4($sp)
  sll   $t5, $t4, 2
  lw    $s7, ($t9)
  addiu $t6, $sp, 0x74
  sll   $t8, $t7, 2
  move  $a1, $s7
  beqz  $s7, .L702005E8
   addiu $s7, $s7, -1
  addu  $t3, $t5, $t6
  addiu $t9, $sp, 0xbc
  addu  $t6, $t8, $t9
  li    $t8, 1
  addiu $t7, $s5, 0x1f
  sllv  $t9, $t8, $t7
  sw    $t9, 0x34($sp)
  sw    $t6, 0x38($sp)
.L7020037C:
  addu  $v1, $t2, $s1
  slt   $at, $v1, $s5
  beqz  $at, .L702004A4
   addiu $s2, $s7, 1
  addiu $t6, $sp, 0x53c
  addu  $t1, $t5, $t6
  lw    $t8, 0x5a0($sp)
.L70200398:
  addiu $t4, $t4, 1
  addiu $t5, $t5, 4
  subu  $t0, $t8, $v1
  sltu  $at, $s1, $t0
  addiu $t1, $t1, 4
  addiu $t3, $t3, 4
  beqz  $at, .L702003BC
   move  $t2, $v1
  move  $t0, $s1
.L702003BC:
  subu  $v0, $s5, $t2
  li    $t7, 1
  sllv  $a0, $t7, $v0
  sltu  $at, $s2, $a0
  beqz  $at, .L7020041C
   move  $a3, $v0
  addiu $a3, $v0, 1
  subu  $v1, $a0, $s7
  sll   $t9, $s5, 2
  addiu $t6, $sp, 0x5a8
  sltu  $at, $a3, $t0
  addiu $v1, $v1, -1
  beqz  $at, .L7020041C
   addu  $a2, $t9, $t6
.L702003F4:
  lw    $a0, 4($a2)
  sll   $v0, $v1, 1
  addiu $a2, $a2, 4
  sltu  $at, $a0, $v0
  beql  $at, $zero, .L70200420
   lw    $v1, ($s3)
  addiu $a3, $a3, 1
  sltu  $at, $a3, $t0
  bnez  $at, .L702003F4
   subu  $v1, $v0, $a0
.L7020041C:
  lw    $v1, ($s3)
.L70200420:
  lw    $t9, ($fp)
  li    $t8, 1
  sllv  $t0, $t8, $a3
  sll   $t7, $v1, 3
  addu  $t6, $v1, $t0
  addiu $t8, $t6, 1
  addu  $a2, $t7, $t9
  sw    $t8, ($s3)
  addiu $a0, $a2, 8
  sw    $a0, ($s6)
  sw    $zero, 4($a2)
  addiu $s6, $a2, 4
  move  $a2, $a0
  beqz  $t4, .L70200494
   sw    $a0, ($t1)
  sw    $s0, ($t3)
  addiu $t7, $a3, 0x10
  sb    $s1, 0x57d($sp)
  sb    $t7, 0x57c($sp)
  sw    $a0, 0x580($sp)
  lw    $t9, -4($t1)
  subu  $t6, $t2, $s1
  lw    $at, ($s4)
  srlv  $t8, $s0, $t6
  sll   $t7, $t8, 3
  addu  $t6, $t9, $t7
  sw    $at, ($t6)
  lw    $t7, 4($s4)
  sw    $t7, 4($t6)
.L70200494:
  addu  $v1, $t2, $s1
  slt   $at, $v1, $s5
  bnezl $at, .L70200398
   lw    $t8, 0x5a0($sp)
.L702004A4:
  lw    $t8, 0x38($sp)
  li    $t9, 1
  subu  $v1, $s5, $t2
  sllv  $a1, $t9, $t2
  sltu  $at, $ra, $t8
  sb    $v1, 0x57d($sp)
  bnez  $at, .L702004D0
   addiu $a1, $a1, -1
  li    $t6, 99
  b     .L7020054C
   sb    $t6, 0x57c($sp)
.L702004D0:
  lw    $v0, ($ra)
  lw    $t7, 0x5f8($sp)
  lw    $a0, 0x5f8($sp)
  lw    $t9, 0x600($sp)
  sltu  $at, $v0, $t7
  beqz  $at, .L70200514
   sltiu $at, $v0, 0x100
  beqz  $at, .L70200500
   li    $t8, 15
  li    $t9, 16
  b     .L70200504
   sb    $t9, 0x57c($sp)
.L70200500:
  sb    $t8, 0x57c($sp)
.L70200504:
  lw    $t6, ($ra)
  addiu $ra, $ra, 4
  b     .L7020054C
   sh    $t6, 0x580($sp)
.L70200514:
  subu  $t7, $v0, $a0
  addu  $t8, $t7, $t9
  lbu   $t6, ($t8)
  lw    $t7, 0x5fc($sp)
  addiu $ra, $ra, 4
  sb    $t6, 0x57c($sp)
  lw    $t9, -4($ra)
  sll   $t8, $t9, 1
  sll   $t9, $a0, 1
  addu  $t6, $t7, $t8
  negu  $t7, $t9
  addu  $t8, $t6, $t7
  lhu   $t9, ($t8)
  sh    $t9, 0x580($sp)
.L7020054C:
  srlv  $a3, $s0, $t2
  sltu  $at, $a3, $t0
  beqz  $at, .L70200584
   li    $t6, 1
  sllv  $v0, $t6, $v1
.L70200560:
  lw    $at, ($s4)
  sll   $t7, $a3, 3
  addu  $t8, $a2, $t7
  sw    $at, ($t8)
  lw    $t6, 4($s4)
  addu  $a3, $a3, $v0
  sltu  $at, $a3, $t0
  bnez  $at, .L70200560
   sw    $t6, 4($t8)
.L70200584:
  lw    $a3, 0x34($sp)
  lw    $v0, ($t3)
  and   $t7, $s0, $a3
  beqz  $t7, .L702005A8
.L70200594:
   srl   $t9, $a3, 1
  xor   $s0, $s0, $a3
  and   $t8, $s0, $t9
  bnez  $t8, .L70200594
   move  $a3, $t9
.L702005A8:
  xor   $s0, $s0, $a3
  and   $t6, $s0, $a1
  beq   $t6, $v0, .L702005E0
   move  $a1, $s7
.L702005B8:
  subu  $t2, $t2, $s1
  li    $t7, 1
  sllv  $t9, $t7, $t2
  lw    $t7, -4($t3)
  addiu $t8, $t9, -1
  and   $t6, $s0, $t8
  addiu $t4, $t4, -1
  addiu $t5, $t5, -4
  bne   $t6, $t7, .L702005B8
   addiu $t3, $t3, -4
.L702005E0:
  bnez  $s7, .L7020037C
   addiu $s7, $s7, -1
.L702005E8:
  lw    $t9, 0x50($sp)
  lw    $t6, 0x5a0($sp)
  addiu $s5, $s5, 1
  addiu $t8, $t9, 4
  slt   $at, $t6, $s5
  beqz  $at, .L70200338
   sw    $t8, 0x50($sp)
  sw    $s6, 0x604($sp)
.L70200608:
  lw    $v0, 0x6c($sp)
  sltu  $t7, $zero, $v0
  beqz  $t7, .L70200624
   move  $v0, $t7
  lw    $v0, 0x5a0($sp)
  xori  $t9, $v0, 1
  sltu  $v0, $zero, $t9
.L70200624:
  lw    $ra, 0x2c($sp)
  lw    $s0, 8($sp)
  lw    $s1, 0xc($sp)
  lw    $s2, 0x10($sp)
  lw    $s3, 0x14($sp)
  lw    $s4, 0x18($sp)
  lw    $s5, 0x1c($sp)
  lw    $s6, 0x20($sp)
  lw    $s7, 0x24($sp)
  lw    $fp, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x5f0
");

asm(R"
glabel inflate_codes
  addiu $sp, $sp, -0x10
  lui   $t3, %hi(mask_bits) # $t3, 0x7020
  addiu $t3, %lo(mask_bits) # addiu $t3, $t3, 0x156c
  sw    $s1, 8($sp)
  sw    $s0, 4($sp)
  sll   $t6, $a2, 1
  sll   $t8, $a3, 1
  move  $s0, $a2
  move  $s1, $a3
  lui   $t1, %hi(bb) # $t1, 0x7020
  lui   $t0, %hi(bk) # $t0, 0x7020
  lui   $v1, %hi(wp) # $v1, 0x7020
  addu  $t7, $t3, $t6
  addu  $t9, $t3, $t8
  lui   $a3, %hi(inptr) # $a3, 0x7020
  lui   $a2, %hi(outbuf) # $a2, 0x7020
  sw    $s2, 0xc($sp)
  sw    $a0, 0x10($sp)
  sw    $a1, 0x14($sp)
  lw    $t1, %lo(bb)($t1)
  lw    $t0, %lo(bk)($t0)
  lw    $v1, %lo(wp)($v1)
  lhu   $t4, ($t7)
  lhu   $t5, ($t9)
  addiu $a2, %lo(outbuf) # addiu $a2, $a2, 0x1484
  addiu $a3, %lo(inptr) # addiu $a3, $a3, 0x1488
.L702006BC:
  sltu  $at, $t0, $s0
.L702006C0:
  beqz  $at, .L702006F4
   lui   $v0, %hi(inbuf) # $v0, 0x7020
  lw    $v0, %lo(inbuf)($v0)
.L702006CC:
  lw    $s2, ($a3)
  addu  $t6, $v0, $s2
  lbu   $t7, ($t6)
  addiu $t9, $s2, 1
  sw    $t9, ($a3)
  sllv  $t8, $t7, $t0
  addiu $t0, $t0, 8
  sltu  $at, $t0, $s0
  bnez  $at, .L702006CC
   or    $t1, $t1, $t8
.L702006F4:
  lw    $t8, 0x10($sp)
  and   $t6, $t1, $t4
  sll   $t7, $t6, 3
  addu  $a1, $t7, $t8
  lbu   $a0, ($a1)
  sltiu $at, $a0, 0x11
  bnezl $at, .L7020078C
   lbu   $v0, 1($a1)
  lbu   $v0, 1($a1)
.L70200718:
  addiu $a0, $a0, -0x10
  subu  $t0, $t0, $v0
  sltu  $at, $t0, $a0
  beqz  $at, .L7020075C
   srlv  $t1, $t1, $v0
  lui   $v0, %hi(inbuf) # $v0, 0x7020
  lw    $v0, %lo(inbuf)($v0)
.L70200734:
  lw    $s2, ($a3)
  addu  $t9, $v0, $s2
  lbu   $t6, ($t9)
  addiu $t8, $s2, 1
  sw    $t8, ($a3)
  sllv  $t7, $t6, $t0
  addiu $t0, $t0, 8
  sltu  $at, $t0, $a0
  bnez  $at, .L70200734
   or    $t1, $t1, $t7
.L7020075C:
  sll   $t9, $a0, 1
  addu  $t6, $t3, $t9
  lhu   $t7, ($t6)
  lw    $t6, 4($a1)
  and   $t8, $t7, $t1
  sll   $t9, $t8, 3
  addu  $a1, $t9, $t6
  lbu   $a0, ($a1)
  sltiu $at, $a0, 0x11
  beql  $at, $zero, .L70200718
   lbu   $v0, 1($a1)
  lbu   $v0, 1($a1)
.L7020078C:
  li    $at, 16
  srlv  $t1, $t1, $v0
  bne   $a0, $at, .L702007B4
   subu  $t0, $t0, $v0
  lw    $t8, ($a2)
  lhu   $t7, 4($a1)
  addu  $t9, $t8, $v1
  addiu $v1, $v1, 1
  b     .L702006BC
   sb    $t7, ($t9)
.L702007B4:
  li    $at, 15
  beq   $a0, $at, .L70200A18
   lui   $v0, %hi(inbuf) # $v0, 0x7020
  sltu  $at, $t0, $a0
  beql  $at, $zero, .L702007FC
   sll   $t6, $a0, 1
  lw    $v0, %lo(inbuf)($v0)
.L702007D0:
  lw    $s2, ($a3)
  addu  $t6, $v0, $s2
  lbu   $t8, ($t6)
  addiu $t9, $s2, 1
  sw    $t9, ($a3)
  sllv  $t7, $t8, $t0
  addiu $t0, $t0, 8
  sltu  $at, $t0, $a0
  bnez  $at, .L702007D0
   or    $t1, $t1, $t7
  sll   $t6, $a0, 1
.L702007FC:
  addu  $t8, $t3, $t6
  lhu   $t7, ($t8)
  lhu   $t6, 4($a1)
  subu  $t0, $t0, $a0
  sltu  $at, $t0, $s1
  and   $t9, $t7, $t1
  srlv  $t1, $t1, $a0
  beqz  $at, .L70200850
   addu  $t2, $t9, $t6
  lui   $v0, %hi(inbuf) # $v0, 0x7020
  lw    $v0, %lo(inbuf)($v0)
.L70200828:
  lw    $s2, ($a3)
  addu  $t8, $v0, $s2
  lbu   $t7, ($t8)
  addiu $t6, $s2, 1
  sw    $t6, ($a3)
  sllv  $t9, $t7, $t0
  addiu $t0, $t0, 8
  sltu  $at, $t0, $s1
  bnez  $at, .L70200828
   or    $t1, $t1, $t9
.L70200850:
  lw    $t9, 0x14($sp)
  and   $t8, $t1, $t5
  sll   $t7, $t8, 3
  addu  $a1, $t7, $t9
  lbu   $a0, ($a1)
  sltiu $at, $a0, 0x11
  bnezl $at, .L702008E8
   lbu   $v0, 1($a1)
  lbu   $v0, 1($a1)
.L70200874:
  addiu $a0, $a0, -0x10
  subu  $t0, $t0, $v0
  sltu  $at, $t0, $a0
  beqz  $at, .L702008B8
   srlv  $t1, $t1, $v0
  lui   $v0, %hi(inbuf) # $v0, 0x7020
  lw    $v0, %lo(inbuf)($v0)
.L70200890:
  lw    $s2, ($a3)
  addu  $t6, $v0, $s2
  lbu   $t8, ($t6)
  addiu $t9, $s2, 1
  sw    $t9, ($a3)
  sllv  $t7, $t8, $t0
  addiu $t0, $t0, 8
  sltu  $at, $t0, $a0
  bnez  $at, .L70200890
   or    $t1, $t1, $t7
.L702008B8:
  sll   $t6, $a0, 1
  addu  $t8, $t3, $t6
  lhu   $t7, ($t8)
  lw    $t8, 4($a1)
  and   $t9, $t7, $t1
  sll   $t6, $t9, 3
  addu  $a1, $t6, $t8
  lbu   $a0, ($a1)
  sltiu $at, $a0, 0x11
  beql  $at, $zero, .L70200874
   lbu   $v0, 1($a1)
  lbu   $v0, 1($a1)
.L702008E8:
  subu  $t0, $t0, $v0
  sltu  $at, $t0, $a0
  beqz  $at, .L70200928
   srlv  $t1, $t1, $v0
  lui   $v0, %hi(inbuf) # $v0, 0x7020
  lw    $v0, %lo(inbuf)($v0)
.L70200900:
  lw    $s2, ($a3)
  addu  $t7, $v0, $s2
  lbu   $t9, ($t7)
  addiu $t8, $s2, 1
  sw    $t8, ($a3)
  sllv  $t6, $t9, $t0
  addiu $t0, $t0, 8
  sltu  $at, $t0, $a0
  bnez  $at, .L70200900
   or    $t1, $t1, $t6
.L70200928:
  lhu   $t7, 4($a1)
  sll   $t6, $a0, 1
  addu  $t8, $t3, $t6
  subu  $t9, $v1, $t7
  lhu   $t7, ($t8)
  subu  $t0, $t0, $a0
  and   $t6, $t7, $t1
  subu  $v0, $t9, $t6
  srlv  $t1, $t1, $a0
  move  $a0, $t2
.L70200950:
  andi  $s2, $a0, 3
  negu  $s2, $s2
  beqz  $s2, .L70200990
   move  $t2, $zero
  addu  $a1, $s2, $a0
.L70200964:
  lw    $s2, ($a2)
  addiu $a0, $a0, -1
  addu  $t8, $v0, $s2
  lbu   $t7, ($t8)
  addu  $t9, $s2, $v1
  addiu $v1, $v1, 1
  addiu $v0, $v0, 1
  bne   $a1, $a0, .L70200964
   sb    $t7, ($t9)
  beqz  $a0, .L70200A08
   nop   
.L70200990:
  lw    $s2, ($a2)
  addiu $a0, $a0, -4
  addu  $t6, $v0, $s2
  lbu   $t8, ($t6)
  addu  $t7, $s2, $v1
  addiu $v0, $v0, 1
  sb    $t8, ($t7)
  lw    $s2, ($a2)
  addiu $v1, $v1, 1
  addu  $t9, $v0, $s2
  lbu   $t6, ($t9)
  addu  $t8, $s2, $v1
  addiu $v0, $v0, 1
  sb    $t6, ($t8)
  lw    $s2, ($a2)
  addiu $v1, $v1, 1
  addu  $t7, $v0, $s2
  lbu   $t9, ($t7)
  addu  $t6, $s2, $v1
  addiu $v0, $v0, 1
  sb    $t9, ($t6)
  lw    $s2, ($a2)
  addiu $v1, $v1, 1
  addu  $t8, $v0, $s2
  lbu   $t7, ($t8)
  addu  $t9, $s2, $v1
  addiu $v1, $v1, 1
  addiu $v0, $v0, 1
  bnez  $a0, .L70200990
   sb    $t7, ($t9)
.L70200A08:
  bnezl $t2, .L70200950
   move  $a0, $t2
  b     .L702006C0
   sltu  $at, $t0, $s0
.L70200A18:
  lui   $at, %hi(wp) # $at, 0x7020
  sw    $v1, %lo(wp)($at)
  lui   $at, %hi(bb) # $at, 0x7020
  sw    $t1, %lo(bb)($at)
  lui   $at, %hi(bk) # $at, 0x7020
  lw    $s0, 4($sp)
  lw    $s1, 8($sp)
  lw    $s2, 0xc($sp)
  sw    $t0, %lo(bk)($at)
  addiu $sp, $sp, 0x10
  jr    $ra
   move  $v0, $zero
");

int inflate_stored(void) {
  int n;                   /* number of bytes in block */
  int w;                   /* current window position */
  register unsigned int b; /* bit buffer */
  register unsigned int k; /* number of bits in bit buffer */

  /* make local copies of globals */
  b = bb; /* initialize bit buffer */
  k = bk;
  w = wp; /* initialize window position */

  /* go to byte boundary */
  n = k & 7;
  DUMPBITS(n);

  /* get the length and its complement */
  NEEDBITS(16)
  n = (b & 0xffff);
  DUMPBITS(16)

  NEEDBITS(16)
  DUMPBITS(16)

  /* read and output the compressed data */
  while (n--) {
    NEEDBITS(8)
    outbuf[w++] = (unsigned char)b;

    DUMPBITS(8)
  }

  /* restore the globals from the locals */
  wp = w; /* restore global window pointer */
  bb = b; /* restore global bit buffer */
  bk = k;
  return 0;
}

asm(R"
glabel inflate_fixed
  addiu $sp, $sp, -0x4c0
  sw    $ra, 0x24($sp)
  addiu $v0, $sp, 0x2c
  addiu $a0, $sp, 0x26c
  li    $v1, 8
.L70200BB0:
  addiu $v0, $v0, 0x10
  sw    $v1, -0xc($v0)
  sw    $v1, -8($v0)
  sw    $v1, -4($v0)
  bne   $v0, $a0, .L70200BB0
   sw    $v1, -0x10($v0)
  addiu $t6, $sp, 0x42c
  sltu  $at, $v0, $t6
  beqz  $at, .L70200BF0
   addiu $t7, $sp, 0x48c
  addiu $a1, $sp, 0x42c
  li    $a0, 9
.L70200BE0:
  addiu $v0, $v0, 4
  sltu  $at, $v0, $a1
  bnez  $at, .L70200BE0
   sw    $a0, -4($v0)
.L70200BF0:
  sltu  $at, $v0, $t7
  beqz  $at, .L70200C14
   addiu $t8, $sp, 0x4ac
  addiu $a1, $sp, 0x48c
  li    $a0, 7
.L70200C04:
  addiu $v0, $v0, 4
  sltu  $at, $v0, $a1
  bnez  $at, .L70200C04
   sw    $a0, -4($v0)
.L70200C14:
  sltu  $at, $v0, $t8
  beqz  $at, .L70200C34
   li    $t9, 7
  addiu $a0, $sp, 0x4ac
.L70200C24:
  addiu $v0, $v0, 4
  sltu  $at, $v0, $a0
  bnez  $at, .L70200C24
   sw    $v1, -4($v0)
.L70200C34:
  lui   $t0, %hi(cplext) # $t0, 0x7020
  addiu $t0, %lo(cplext) # addiu $t0, $t0, 0x14e8
  lui   $a3, %hi(cplens) # $a3, 0x7020
  addiu $t1, $sp, 0x4b8
  addiu $t2, $sp, 0x4b0
  sw    $t9, 0x4b0($sp)
  sw    $t2, 0x18($sp)
  sw    $t1, 0x14($sp)
  addiu $a3, %lo(cplens) # addiu $a3, $a3, 0x14a8
  sw    $t0, 0x10($sp)
  addiu $a0, $sp, 0x2c
  li    $a1, 288
  jal   huft_build
   li    $a2, 257
  li    $t3, 5
  li    $t4, 5
  sw    $t4, 0x30($sp)
  sw    $t3, 0x2c($sp)
  addiu $v0, $sp, 0x34
  addiu $a0, $sp, 0xa4
  li    $v1, 5
.L70200C88:
  addiu $v0, $v0, 0x10
  sw    $v1, -0xc($v0)
  sw    $v1, -8($v0)
  sw    $v1, -4($v0)
  bne   $v0, $a0, .L70200C88
   sw    $v1, -0x10($v0)
  lui   $t6, %hi(cpdext) # $t6, 0x7020
  li    $t5, 5
  addiu $t6, %lo(cpdext) # addiu $t6, $t6, 0x1544
  lui   $a3, %hi(cpdist) # $a3, 0x7020
  addiu $t7, $sp, 0x4b4
  addiu $t8, $sp, 0x4ac
  sw    $t5, 0x4ac($sp)
  sw    $t8, 0x18($sp)
  sw    $t7, 0x14($sp)
  addiu $a3, %lo(cpdist) # addiu $a3, $a3, 0x1508
  sw    $t6, 0x10($sp)
  addiu $a0, $sp, 0x2c
  li    $a1, 30
  jal   huft_build
   move  $a2, $zero
  lw    $a0, 0x4b8($sp)
  lw    $a1, 0x4b4($sp)
  lw    $a2, 0x4b0($sp)
  jal   inflate_codes
   lw    $a3, 0x4ac($sp)
  lw    $ra, 0x24($sp)
  addiu $sp, $sp, 0x4c0
  move  $v0, $zero
  jr    $ra
   nop   
");

struct huft {
  unsigned char e; /* number of extra bits or operation */
  unsigned char b; /* number of bits in this code or subcode */
  union {
    unsigned short n; /* literal, length base, or distance base */
    struct huft *t;   /* pointer to next level of table */
  } v;
};

int inflate_dynamic(void) {
  int i; /* temporary variables */
  unsigned int j;
  unsigned int l;            /* last length */
  unsigned int m;            /* mask for bit lengths table */
  unsigned int n;            /* number of lengths to get */
  struct huft *tl;           /* literal/length code table */
  struct huft *td;           /* distance code table */
  int bl;                    /* lookup bits for tl */
  int bd;                    /* lookup bits for td */
  unsigned int nb;           /* number of bit length codes */
  unsigned int nl;           /* number of literal/length codes */
  unsigned int nd;           /* number of distance codes */
  register unsigned int k;   /* number of bits in bit buffer */
  register unsigned int b;   /* bit buffer */
  unsigned int ll[286 + 30]; /* literal/length and distance code lengths */

  /* make local bit buffer */
  b = bb;
  k = bk;

  /* read in table lengths */
  NEEDBITS(5)
  nl = 257 + (b & 0x1f); /* number of literal/length codes */
  DUMPBITS(5)
  NEEDBITS(5)
  nd = 1 + (b & 0x1f); /* number of distance codes */
  DUMPBITS(5)
  NEEDBITS(4)
  nb = 4 + (b & 0xf); /* number of bit length codes */
  DUMPBITS(4)

  /* read in bit-length-code lengths */
  for (j = 0; j < nb; j++) {
    NEEDBITS(3)
    ll[border[j]] = b & 7;
    DUMPBITS(3)
  }

  for (; j < 19; j++) {
    ll[border[j]] = 0;
  }

  /* build decoding table for trees--single level, 7 bit lookup */
  bl = 7;

  huft_build(ll, 19, 19, NULL, NULL, &tl, &bl);

  /* read in literal and distance code lengths */
  n = nl + nd;
  m = mask_bits[bl];
  i = l = 0;

  while (i < n) {
    NEEDBITS(bl)
    j = (td = tl + (b & m))->b;
    DUMPBITS(j)

    j = td->v.n;

    if (j < 16) {         /* length of code in bits (0..15) */
      ll[i++] = l = j;    /* save last length in l */
    } else if (j == 16) { /* repeat last length 3 to 6 times */
      NEEDBITS(2)
      j = 3 + (b & 3);
      DUMPBITS(2)

      while (j--) {
        ll[i++] = l;
      }
    } else if (j == 17) { /* 3 to 10 zero length codes */
      NEEDBITS(3)
      j = 3 + (b & 7);
      DUMPBITS(3)

      while (j--) {
        ll[i++] = 0;
      }

      l = 0;
    } else { /* j == 18: 11 to 138 zero length codes */
      NEEDBITS(7)
      j = 11 + (b & 0x7f);
      DUMPBITS(7)

      while (j--) {
        ll[i++] = 0;
      }

      l = 0;
    }
  }

  /* restore the global bit buffer */
  bb = b;
  bk = k;

  /* build the decoding tables for literal/length and distance codes */
  bl = lbits;

  huft_build(ll, nl, 257, cplens, cplext, &tl, &bl);

  bd = dbits;

  huft_build(ll + nl, nd, 0, cpdist, cpdext, &td, &bd);

  /* decompress until an end-of-block code */
  inflate_codes(tl, td, bl, bd);

  return 0;
}

int inflate_block(int *e) {
  unsigned int t;               /* block type */
  register unsigned int b = bb; /* bit buffer */
  register unsigned int k = bk; /* number of bits in bit buffer */

  /* make local bit buffer */
  b = bb;
  k = bk;

  /* read in last block bit */
  NEEDBITS(1)
  *e = b & 1;
  DUMPBITS(1)

  /* read in last block type */
  NEEDBITS(2)
  t = b & 3;
  DUMPBITS(2)

  /* restore the global bit buffer */
  bb = b;
  bk = k;

  /* inflate that block type */
  if (t == 2) {
    return inflate_dynamic();
  }

  if (t == 0) {
    return inflate_stored();
  }

  if (t == 1) {
    return inflate_fixed();
  }

  /* bad block type */
  return 2;
}

int inflate() /* decompress an inflated entry */
{
  int e;          /* last block flag */
  int r;          /* result code */
  unsigned int h; /* maximum struct huft's malloc'ed */

  /* initialize window, bit buffer */
  wp = 0;
  bk = 0;
  bb = 0;

  /* decompress until the last block */
  h = 0;
  do {
    hufts = 0;
    if ((r = inflate_block(&e)) != 0)
      return r;
    if (hufts > h)
      h = hufts;
  } while (!e);

  /* Undo too much lookahead. The next read will be byte aligned so we
   * can discard unused bits in the last meaningful byte. */
  while (bk >= 8) {
    bk -= 8;
    inptr--;
  }

  return 0;
}

unsigned int decompress_entry(unsigned char *source, unsigned char *target,
                              unsigned char *buffer) {
  inbuf = source;
  outbuf = target;
  huftlist = buffer;
  inbuf += 2;
  wp = 0;
  inptr = 0;
  inflate();
  return wp;
}
