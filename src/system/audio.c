// This file contains the audio code.
#include "sched.h"

extern unsigned char sp_audi[];

unsigned int D_800230F0 = 0;
unsigned int audFrameCt = 0;
unsigned int nextDMA = 0;
unsigned int curAcmdList = 0;
unsigned long long D_80023100[] = {
    {0x000600001900}, {0x0000000000A0}, {0x2666FFFFD99A}, {0x000000000000},
    {0x000000000000}, {0x00A000000140}, {0x2666FFFFD99A}, {0x2B8400000000},
    {0x000000002500}, {0x032000000A00}, {0x4000FFFFC000}, {0x11EB00000000},
    {0x000000003000}, {0x0C80000015E0}, {0x4000FFFFC000}, {0x11EB00000000},
    {0x000000003500}, {0x0D20000012C0}, {0x2000FFFFE000}, {0x000000000000},
    {0x000000004000}, {0x000000001720}, {0x32C8FFFFCD38}, {0x00000000017C},
    {0x000A00004500},
};

int firstTime = 1;

int dword_CODE_bss_8005E4B0[2];
int dword_CODE_bss_8005E4B8[2];
int dword_CODE_bss_8005E4C0;
int dword_CODE_bss_8005E4C4;
int dword_CODE_bss_8005E4C8;
int dword_CODE_bss_8005E4CC;
int dword_CODE_bss_8005E4D0[2];
int dword_CODE_bss_8005E4D8[2];
char dword_CODE_bss_8005E4E0[0x38];
char _am[0x284];

OSScClient audi_client[2];
int dmaState_initialized;
int dmaState_firstUsed;
int dmaState_firstFree[2];
char dmaBuffs[0x500];
int minFrameSize, frameSize, maxFrameSize;
int cmdLen;

OSIoMesg audDMAIOMesgBuf[0x40];
OSMesgQueue audDMAMessageQ;
char audDMAMessageBuf[0x108];

asm(R"
glabel amCreateAudioMgr
  addiu $sp, $sp, -0x118
  sw    $s3, 0x2c($sp)
  lui   $t6, %hi(__amDmaNew) # $t6, 0x7000
  sw    $ra, 0x34($sp)
  sw    $s4, 0x30($sp)
  sw    $s2, 0x28($sp)
  sw    $s1, 0x24($sp)
  sw    $s0, 0x20($sp)
  addiu $t6, %lo(__amDmaNew) # addiu $t6, $t6, 0x25d8
  move  $s3, $a0
  sw    $t6, 0x10($a0)
  jal   osAiSetFrequency
   li    $a0, 22050
  sll   $t7, $v0, 1
  mtc1  $t7, $f4
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f8
  cvt.s.w $f6, $f4
  li    $t9, 1
  lui   $a0, %hi(frameSize)
  lui   $s4, %hi(maxFrameSize)
  addiu $a0, %lo(frameSize) # addiu $a0, $a0, -0x133c
  sw    $v0, 0x18($s3)
  div.s $f0, $f6, $f8
  addiu $s4, %lo(maxFrameSize) # addiu $s4, $s4, -0x1338
  cfc1  $t8, $31
  ctc1  $t9, $31
  nop   
  cvt.w.s $f10, $f0
  cfc1  $t9, $31
  nop   
  andi  $t9, $t9, 0x78
  beqz  $t9, .L70001C9C
   li    $at, 0x4F000000 # 2147483648.000000
  mtc1  $at, $f10
  li    $t9, 1
  sub.s $f10, $f0, $f10
  ctc1  $t9, $31
  nop   
  cvt.w.s $f10, $f10
  cfc1  $t9, $31
  nop   
  andi  $t9, $t9, 0x78
  bnez  $t9, .L70001C94
   nop   
  mfc1  $t9, $f10
  lui   $at, 0x8000
  b     .L70001CAC
   or    $t9, $t9, $at
.L70001C94:
  b     .L70001CAC
   li    $t9, -1
.L70001C9C:
  mfc1  $t9, $f10
  nop   
  bltz  $t9, .L70001C94
   nop   
.L70001CAC:
  move  $v1, $t9
  ctc1  $t8, $31
  mtc1  $v1, $f16
  sw    $t9, ($a0)
  bgez  $t9, .L70001CD4
   cvt.s.w $f18, $f16
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f4
  nop   
  add.s $f18, $f18, $f4
.L70001CD4:
  c.lt.s $f18, $f0
  nop   
  bc1f  .L70001CEC
   addiu $t0, $v1, 1
  sw    $t0, ($a0)
  move  $v1, $t0
.L70001CEC:
  andi  $t1, $v1, 0xf
  beqz  $t1, .L70001D04
   li    $at, -16
  and   $t2, $v1, $at
  addiu $v1, $t2, 0x10
  sw    $v1, ($a0)
.L70001D04:
  addiu $t4, $v1, -0x10
  lui   $at, %hi(minFrameSize)
  sw    $t4, %lo(minFrameSize)($at)
  addiu $t5, $v1, 0x35
  sw    $t5, ($s4)
  lbu   $t6, 0x1c($s3)
  li    $at, 6
  lui   $a0, %hi(_am+0x238)
  bne   $t6, $at, .L70001D90
   addiu $a0, %lo(_am+0x238) # addiu $a0, $a0, -0x18b0
  lui   $t7, %hi(D_80023100) 
  addiu $v0, $sp, 0x48
  addiu $t7, %lo(D_80023100) # addiu $t7, $t7, 0x3100
  addiu $t9, $t7, 0xc0
  move  $t0, $v0
.L70001D40:
  lw    $at, ($t7)
  addiu $t7, $t7, 0xc
  addiu $t0, $t0, 0xc
  sw    $at, -0xc($t0)
  lw    $at, -8($t7)
  sw    $at, -8($t0)
  lw    $at, -4($t7)
  bne   $t7, $t9, .L70001D40
   sw    $at, -4($t0)
  lw    $at, ($t7)
  lui   $a0, %hi(_am+0x238)
  addiu $a0, %lo(_am+0x238) # addiu $a0, $a0, -0x18b0
  sw    $at, ($t0)
  lw    $t9, 4($t7)
  move  $a1, $s3
  sw    $t9, 4($t0)
  jal   alInit
   sw    $v0, 0x20($s3)
  b     .L70001D98
   nop   
.L70001D90:
  jal   alInit
   move  $a1, $s3
.L70001D98:
  lui   $s0, %hi(_am)
  lui   $s1, %hi(_am+0xC)
  addiu $s1, %lo(_am+0xC) # addiu $s1, $s1, -0x1adc
  addiu $s0, %lo(_am) # addiu $s0, $s0, -0x1ae8
.L70001DA8:
  lw    $a2, 0x14($s3)
  li    $t1, 96
  sw    $t1, 0x10($sp)
  move  $a0, $zero
  move  $a1, $zero
  jal   alHeapDBAlloc
   li    $a3, 1
  lw    $t2, ($s4)
  sw    $v0, 8($s0)
  lw    $a2, 0x14($s3)
  sll   $t3, $t2, 2
  sw    $t3, 0x10($sp)
  move  $a0, $zero
  move  $a1, $zero
  jal   alHeapDBAlloc
   li    $a3, 1
  lw    $t4, 8($s0)
  addiu $s0, $s0, 4
  sltu  $at, $s0, $s1
  bnez  $at, .L70001DA8
   sw    $v0, ($t4)
  lui   $a0, %hi(_am+0x200)
  lui   $a1, %hi(_am+0x218)
  addiu $a1, %lo(_am+0x218) # addiu $a1, $a1, -0x18d0
  addiu $a0, %lo(_am+0x200) # addiu $a0, $a0, -0x18e8
  jal   osCreateMesgQueue
   li    $a2, 8
  lui   $a0, %hi(_am+0x1C8)
  lui   $a1, %hi(_am+0x1E0)
  addiu $a1, %lo(_am+0x1E0) # addiu $a1, $a1, -0x1908
  addiu $a0, %lo(_am+0x1C8) # addiu $a0, $a0, -0x1920
  jal   osCreateMesgQueue
   li    $a2, 8
  lui   $a0, %hi(audDMAMessageQ)
  lui   $a1, %hi(audDMAMessageBuf)
  addiu $a1, %lo(audDMAMessageBuf) # addiu $a1, $a1, -0xd18
  addiu $a0, %lo(audDMAMessageQ) # addiu $a0, $a0, -0xd30
  jal   osCreateMesgQueue
   li    $a2, 64
  lui   $v0, %hi(dmaBuffs)
  addiu $v0, %lo(dmaBuffs) # addiu $v0, $v0, -0x1840
  lui   $s1, %hi(dmaBuffs)
  lui   $s0, %hi(dmaBuffs+20)
  sw    $zero, 4($v0)
  sw    $zero, ($v0)
  addiu $s0, $s0, %lo(dmaBuffs+20)
  addiu $s1, %lo(dmaBuffs) # addiu $s1, $s1, -0x1840
  move  $s2, $zero
.L70001E68:
  move  $a0, $s0
  jal   alLink
   move  $a1, $s1
  lw    $a2, 0x14($s3)
  li    $t5, 512
  sw    $t5, 0x10($sp)
  move  $a0, $zero
  move  $a1, $zero
  jal   alHeapDBAlloc
   li    $a3, 1
  addiu $s2, $s2, 1
  slti  $at, $s2, 0x3f
  addiu $s1, $s1, 0x14
  addiu $s0, $s0, 0x14
  bnez  $at, .L70001E68
   sw    $v0, -4($s1)
  lw    $a2, 0x14($s3)
  li    $t6, 512
  sw    $t6, 0x10($sp)
  move  $a0, $zero
  move  $a1, $zero
  jal   alHeapDBAlloc
   li    $a3, 1
  sw    $v0, 0x10($s1)
  lui   $s1, %hi(_am+0x8)
  lui   $s0, %hi(_am)
  addiu $s0, %lo(_am) # addiu $s0, $s0, -0x1ae8
  addiu $s1, %lo(_am+0x8) # addiu $s1, $s1, -0x1ae0
.L70001ED8:
  lw    $a2, 0x14($s3)
  li    $t8, 24000
  sw    $t8, 0x10($sp)
  move  $a0, $zero
  move  $a1, $zero
  jal   alHeapDBAlloc
   li    $a3, 1
  addiu $s0, $s0, 4
  bne   $s0, $s1, .L70001ED8
   sw    $v0, -4($s0)
  lui   $a0, %hi(sp_audi) # $a0, 0x803b
  addiu $a0, %lo(sp_audi) # addiu $a0, $a0, 0x3950
  jal   set_stack_entry
   li    $a1, 4096
  lui   $a0, %hi(_am+0x18)
  lui   $a2, %hi(_amMain) # $a2, 0x7000
  li    $t9, 20
  sw    $t9, 0x14($sp)
  addiu $a2, %lo(_amMain) # addiu $a2, $a2, 0x1f7c
  addiu $a0, %lo(_am+0x18) # addiu $a0, $a0, -0x1ad0
  li    $a1, 4
  move  $a3, $zero
  jal   osCreateThread
   sw    $v0, 0x10($sp)
  lw    $ra, 0x34($sp)
  lw    $s0, 0x20($sp)
  lw    $s1, 0x24($sp)
  lw    $s2, 0x28($sp)
  lw    $s3, 0x2c($sp)
  lw    $s4, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x118
");

void startAudioThread(void) { osStartThread((char *)&_am + 24); }

asm(R"
glabel _amMain
  addiu $sp, $sp, -0x70
  sw    $s6, 0x30($sp)
  lui   $s6, %hi(_am+0x1C8)
  sw    $a0, 0x70($sp)
  addiu $s6, %lo(_am+0x1C8) # addiu $s6, $s6, -0x1920
  sw    $ra, 0x3c($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  lui   $a0, %hi(sc)
  lui   $a1, %hi(audi_client)
  sw    $fp, 0x38($sp)
  sw    $s7, 0x34($sp)
  sw    $s5, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s0, 0x18($sp)
  move  $s1, $zero
  move  $s2, $zero
  sw    $zero, 0x64($sp)
  sw    $zero, 0x60($sp)
  addiu $a1, %lo(audi_client) # addiu $a1, $a1, -0x1860
  addiu $a0, %lo(sc) # addiu $a0, $a0, -0x25c0
  move  $a2, $s6
  jal   osScAddClient
   li    $a3, 1
  lui   $s5, %hi(dword_CODE_bss_8005E4E0)
  lui   $s4, %hi(dword_CODE_bss_8005E4D8)
  lui   $s3, %hi(dword_CODE_bss_8005E4B8)
  lui   $s0, %hi(dword_CODE_bss_8005E4D0)
  addiu $s0, %lo(dword_CODE_bss_8005E4D0) # addiu $s0, $s0, -0x1b30
  addiu $s3, %lo(dword_CODE_bss_8005E4B8) # addiu $s3, $s3, -0x1b48
  addiu $s4, %lo(dword_CODE_bss_8005E4D8) # addiu $s4, $s4, -0x1b28
  addiu $s5, %lo(dword_CODE_bss_8005E4E0) # addiu $s5, $s5, -0x1b20
  li    $fp, 1
  addiu $s7, $sp, 0x64
  move  $a0, $s6
.L7000200C:
  move  $a1, $s7
  jal   osRecvMesg
   move  $a2, $fp
  lw    $t6, 0x64($sp)
  li    $at, 5
  lh    $a0, ($t6)
  beq   $a0, $fp, .L70002044
   nop   
  beq   $a0, $at, .L700021F4
   li    $at, 10
  beql  $a0, $at, .L70002200
   move  $s2, $fp
  b     .L70002200
   nop   
.L70002044:
  jal   osGetTime
   nop   
  sw    $v0, ($s4)
  sw    $v1, 4($s4)
  jal   video_related_3
   lui   $a0, 3
  lui   $t7, %hi(audFrameCt) 
  lw    $t7, %lo(audFrameCt)($t7)
  li    $at, 3
  lui   $a0, %hi(_am+8)
  divu  $zero, $t7, $at
  mfhi  $t8
  sll   $t9, $t8, 2
  addu  $a0, $a0, $t9
  lw    $a0, %lo(_am+8)($a0)
  jal   _amHandleFrameMsg
   lw    $a1, 0x60($sp)
  addiu $s1, $s1, 1
  jal   video_related_3
   lui   $a0, 6
  jal   osGetTime
   nop   
  lw    $t2, ($s4)
  lw    $t3, 4($s4)
  sw    $v0, ($s5)
  subu  $t8, $v0, $t2
  sltu  $at, $v1, $t3
  subu  $t8, $t8, $at
  sw    $v1, 4($s5)
  lui   $at, %hi(dword_CODE_bss_8005E4C0)
  subu  $t9, $v1, $t3
  sw    $t9, %lo(dword_CODE_bss_8005E4C4)($at)
  sw    $t8, %lo(dword_CODE_bss_8005E4C0)($at)
  li    $at, 240
  div   $zero, $s1, $at
  mfhi  $t0
  sw    $t9, 0x44($sp)
  sw    $t8, 0x40($sp)
  sw    $v0, 0x50($sp)
  sw    $v1, 0x54($sp)
  sw    $t2, 0x48($sp)
  bnez  $t0, .L7000215C
   sw    $t3, 0x4c($sp)
  lw    $a0, ($s0)
  lw    $a1, 4($s0)
  li    $a2, 0
  jal   __ull_div
   li    $a3, 240
  lui   $at, %hi(dword_CODE_bss_8005E4CC)
  sw    $v0, %lo(dword_CODE_bss_8005E4C8)($at)
  sw    $v1, %lo(dword_CODE_bss_8005E4CC)($at)
  lw    $t9, 4($s4)
  lw    $t8, ($s4)
  lw    $t7, 4($s5)
  lw    $t6, ($s5)
  li    $t2, 0
  sltu  $at, $t7, $t9
  subu  $t0, $t6, $t8
  subu  $t0, $t0, $at
  li    $t3, 0
  li    $t4, 0
  li    $t5, 0
  subu  $t1, $t7, $t9
  sw    $t1, 0x44($sp)
  sw    $t5, 4($s3)
  sw    $t4, ($s3)
  sw    $t3, 4($s0)
  sw    $t0, 0x40($sp)
  b     .L7000219C
   sw    $t2, ($s0)
.L7000215C:
  lw    $t3, 4($s0)
  lw    $t5, 0x54($sp)
  lw    $t2, ($s0)
  lw    $t4, 0x50($sp)
  addu  $t7, $t3, $t5
  lw    $t8, 0x48($sp)
  lw    $t9, 0x4c($sp)
  sltu  $at, $t7, $t5
  addu  $t6, $at, $t2
  addu  $t6, $t6, $t4
  subu  $t0, $t6, $t8
  sltu  $at, $t7, $t9
  subu  $t0, $t0, $at
  subu  $t1, $t7, $t9
  sw    $t1, 4($s0)
  sw    $t0, ($s0)
.L7000219C:
  lw    $t2, ($s3)
  lw    $t4, 0x40($sp)
  lw    $t3, 4($s3)
  lw    $t5, 0x44($sp)
  sltu  $at, $t4, $t2
  bnez  $at, .L700021D4
   lui   $a0, %hi(_am+0x200)
  sltu  $at, $t2, $t4
  bnez  $at, .L700021CC
   sltu  $at, $t3, $t5
  beqz  $at, .L700021D4
   nop   
.L700021CC:
  sw    $t4, ($s3)
  sw    $t5, 4($s3)
.L700021D4:
  addiu $a0, %lo(_am+0x200) # addiu $a0, $a0, -0x18e8
  addiu $a1, $sp, 0x60
  jal   osRecvMesg
   move  $a2, $fp
  jal   __amHandleDoneMsg
   lw    $a0, 0x60($sp)
  b     .L70002200
   nop   
.L700021F4:
  b     .L70002200
   move  $s2, $fp
  move  $s2, $fp
.L70002200:
  beql  $s2, $zero, .L7000200C
   move  $a0, $s6
  lui   $a0, %hi(_am+0x238)
  jal   alClose
   addiu $a0, %lo(_am+0x238) # addiu $a0, $a0, -0x18b0
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
   addiu $sp, $sp, 0x70
");

// accepts: A0=, A1=p->audio packet
asm(R"
glabel _amHandleFrameMsg
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  move  $s0, $a0
  jal   __clearAudioDMA
   sw    $a1, 0x2c($sp)
  jal   osVirtualToPhysical
   lw    $a0, ($s0)
  lw    $v1, 0x2c($sp)
  sw    $v0, 0x24($sp)
  beqz  $v1, .L70002288
   nop   
  lh    $a1, 4($v1)
  lw    $a0, ($v1)
  sll   $t6, $a1, 2
  jal   osAiSetNextBuffer
   move  $a1, $t6
.L70002288:
  jal   osAiGetLength
   nop   
  lui   $t7, %hi(frameSize) 
  lw    $t7, %lo(frameSize)($t7)
  srl   $t8, $v0, 2
  lui   $v1, %hi(minFrameSize)
  subu  $t9, $t7, $t8
  addiu $t0, $t9, 0x35
  andi  $t1, $t0, 0xfff0
  sh    $t1, 4($s0)
  lw    $v1, %lo(minFrameSize)($v1)
  lh    $a3, 4($s0)
  lui   $t4, %hi(curAcmdList) 
  sll   $t2, $v1, 0x10
  sra   $t3, $t2, 0x10
  slt   $at, $a3, $t3
  beqz  $at, .L700022D8
   lui   $a0, %hi(_am)
  sh    $v1, 4($s0)
  lh    $a3, 4($s0)
.L700022D8:
  lw    $t4, %lo(curAcmdList)($t4)
  lui   $a1, %hi(cmdLen)
  addiu $a1, %lo(cmdLen) # addiu $a1, $a1, -0x1334
  sll   $t5, $t4, 2
  addu  $a0, $a0, $t5
  lw    $a0, %lo(_am)($a0)
  jal   alAudioFrame
   lw    $a2, 0x24($sp)
  lui   $t6, %hi(_am+0x200) 
  li    $v1, 2
  lui   $a2, %hi(curAcmdList)
  addiu $t6, %lo(_am+0x200) # addiu $t6, $t6, -0x18e8
  addiu $a2, %lo(curAcmdList) # addiu $a2, $a2, 0x30fc
  sw    $zero, 8($s0)
  sw    $t6, 0x58($s0)
  sw    $s0, 0x5c($s0)
  sw    $v1, 0x10($s0)
  lw    $t7, ($a2)
  lui   $a3, %hi(_am)
  addiu $a3, %lo(_am) # addiu $a3, $a3, -0x1ae8
  sll   $t8, $t7, 2
  addu  $t9, $a3, $t8
  lw    $t0, ($t9)
  lui   $a1, %hi(rspbootTextStart)
  lui   $t8, %hi(gsp3DTextStart) 
  sw    $t0, 0x48($s0)
  lw    $t1, ($a2)
  addiu $a1, %lo(rspbootTextStart) # addiu $a1, $a1, 0xd90
  addiu $t8, %lo(gsp3DTextStart) # addiu $t8, $t8, 0xe60
  sll   $t2, $t1, 2
  addu  $t3, $a3, $t2
  lw    $t4, ($t3)
  lui   $t0, %hi(aspMainTextStart) 
  lui   $t1, %hi(aspMainDataStart) 
  subu  $t5, $v0, $t4
  sra   $t6, $t5, 3
  sll   $t7, $t6, 3
  subu  $t9, $t8, $a1
  addiu $t0, %lo(aspMainTextStart) # addiu $t0, $t0, 0x2280
  addiu $t1, %lo(aspMainDataStart) # addiu $t1, $t1, -0x2fe0
  li    $t2, 2048
  lui   $a0, %hi(sc)
  sw    $t7, 0x4c($s0)
  sw    $v1, 0x18($s0)
  sw    $a1, 0x20($s0)
  sw    $t9, 0x24($s0)
  sw    $zero, 0x1c($s0)
  sw    $t0, 0x28($s0)
  sw    $t1, 0x30($s0)
  sw    $t2, 0x34($s0)
  sw    $zero, 0x50($s0)
  sw    $zero, 0x54($s0)
  jal   osScGetCmdQ
   addiu $a0, %lo(sc) # addiu $a0, $a0, -0x25c0
  move  $a0, $v0
  addiu $a1, $s0, 8
  jal   osSendMesg
   move  $a2, $zero
  lui   $v1, %hi(curAcmdList)
  addiu $v1, %lo(curAcmdList) # addiu $v1, $v1, 0x30fc
  lw    $t3, ($v1)
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  xori  $t4, $t3, 1
  sw    $t4, ($v1)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
glabel __amHandleDoneMsg
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   osAiGetLength
   sw    $a0, 0x18($sp)
  sra   $t6, $v0, 2
  bnez  $t6, .L70002414
   lui   $t7, %hi(firstTime) 
  lw    $t7, %lo(firstTime)($t7)
  lui   $at, %hi(firstTime)
  bnezl $t7, .L70002418
   lw    $ra, 0x14($sp)
  sw    $zero, %lo(firstTime)($at)
.L70002414:
  lw    $ra, 0x14($sp)
.L70002418:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel __amDMA
  lui   $t1, %hi(dmaState_initialized) 
  addiu $t1, %lo(dmaState_initialized) # addiu $t1, $t1, -0x1850
  lw    $t0, 4($t1)
  addiu $sp, $sp, -0x50
  sw    $s0, 0x28($sp)
  sw    $a2, 0x58($sp)
  andi  $t2, $a0, 1
  sw    $ra, 0x2c($sp)
  move  $a3, $a0
  move  $a2, $zero
  sw    $t2, 0x48($sp)
  beqz  $t0, .L700024A8
   move  $s0, $t0
  lw    $v0, 8($s0)
.L7000245C:
  addu  $t6, $a3, $a1
  sltu  $at, $a3, $v0
  bnez  $at, .L700024A8
   addiu $v1, $v0, 0x200
  slt   $at, $v1, $t6
  bnez  $at, .L7000249C
   move  $a2, $s0
  lw    $t8, 0x10($s0)
  lui   $t7, %hi(audFrameCt) 
  lw    $t7, %lo(audFrameCt)($t7)
  addu  $t9, $t8, $a3
  subu  $a0, $t9, $v0
  jal   osVirtualToPhysical
   sw    $t7, 0xc($s0)
  b     .L700025C8
   lw    $ra, 0x2c($sp)
.L7000249C:
  lw    $s0, ($s0)
  bnezl $s0, .L7000245C
   lw    $v0, 8($s0)
.L700024A8:
  lw    $s0, 8($t1)
  bnez  $s0, .L700024D8
   move  $a0, $s0
  bnezl $a2, .L700024C4
   lw    $a0, 0x10($a2)
  move  $a2, $t0
  lw    $a0, 0x10($a2)
.L700024C4:
  jal   osVirtualToPhysical
   sw    $t2, 0x30($sp)
  lw    $t2, 0x30($sp)
  b     .L700025C4
   addu  $v0, $v0, $t2
.L700024D8:
  lw    $t3, ($s0)
  sw    $a3, 0x50($sp)
  sw    $a2, 0x38($sp)
  jal   alUnlink
   sw    $t3, 8($t1)
  lw    $a2, 0x38($sp)
  lui   $t1, %hi(dmaState_initialized) 
  addiu $t1, %lo(dmaState_initialized) # addiu $t1, $t1, -0x1850
  beqz  $a2, .L70002518
   lw    $a3, 0x50($sp)
  move  $a0, $s0
  move  $a1, $a2
  jal   alLink
   sw    $a3, 0x50($sp)
  b     .L70002544
   lw    $a3, 0x50($sp)
.L70002518:
  lw    $t0, 4($t1)
  beql  $t0, $zero, .L7000253C
   sw    $s0, 4($t1)
  sw    $s0, 4($t1)
  sw    $t0, ($s0)
  sw    $zero, 4($s0)
  b     .L70002544
   sw    $s0, 4($t0)
  sw    $s0, 4($t1)
.L7000253C:
  sw    $zero, ($s0)
  sw    $zero, 4($s0)
.L70002544:
  lw    $t4, 0x48($sp)
  lui   $t5, %hi(audFrameCt) 
  lui   $t0, %hi(nextDMA) 
  subu  $a3, $a3, $t4
  sw    $a3, 8($s0)
  lw    $t5, %lo(audFrameCt)($t5)
  addiu $t0, %lo(nextDMA) # addiu $t0, $t0, 0x30f8
  lw    $v1, 0x10($s0)
  sw    $t5, 0xc($s0)
  lw    $v0, ($t0)
  lui   $t7, %hi(audDMAIOMesgBuf) 
  lui   $t9, %hi(audDMAMessageQ) 
  sll   $t6, $v0, 2
  subu  $t6, $t6, $v0
  sll   $t6, $t6, 3
  addiu $t9, %lo(audDMAMessageQ) # addiu $t9, $t9, -0xd30
  addiu $t7, %lo(audDMAIOMesgBuf) # addiu $t7, $t7, -0x1330
  li    $t8, 512
  addiu $t3, $v0, 1
  sw    $t3, ($t0)
  sw    $t8, 0x14($sp)
  addu  $a0, $t6, $t7
  sw    $t9, 0x18($sp)
  li    $a1, 1
  move  $a2, $zero
  sw    $v1, 0x4c($sp)
  jal   osPiStartDma
   sw    $v1, 0x10($sp)
  jal   osVirtualToPhysical
   lw    $a0, 0x4c($sp)
  lw    $t4, 0x48($sp)
  addu  $v0, $v0, $t4
.L700025C4:
  lw    $ra, 0x2c($sp)
.L700025C8:
  lw    $s0, 0x28($sp)
  addiu $sp, $sp, 0x50
  jr    $ra
   nop   
");

asm(R"
glabel __amDmaNew
  lui   $v1, %hi(dmaState_initialized)
  addiu $v1, %lo(dmaState_initialized) # addiu $v1, $v1, -0x1850
  lbu   $t6, ($v1)
  lui   $v0, %hi(__amDMA) # $v0, 0x7000
  lui   $t7, %hi(dmaBuffs) 
  bnez  $t6, .L70002608
   addiu $v0, %lo(__amDMA) # addiu $v0, $v0, 0x2424
  addiu $t7, %lo(dmaBuffs) # addiu $t7, $t7, -0x1840
  li    $t8, 1
  sw    $zero, 4($v1)
  sw    $t7, 8($v1)
  sb    $t8, ($v1)
.L70002608:
  jr    $ra
   sw    $v1, ($a0)
");

asm(R"
glabel __clearAudioDMA
  addiu $sp, $sp, -0x48
  sw    $s4, 0x28($sp)
  lui   $s4, %hi(nextDMA)
  addiu $s4, %lo(nextDMA) # addiu $s4, $s4, 0x30f8
  lw    $t6, ($s4)
  sw    $s0, 0x18($sp)
  sw    $ra, 0x2c($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $zero, 0x40($sp)
  beqz  $t6, .L70002674
   move  $s0, $zero
  lui   $s1, %hi(audDMAMessageQ)
  addiu $s1, %lo(audDMAMessageQ) # addiu $s1, $s1, -0xd30
  addiu $s2, $sp, 0x40
  move  $a0, $s1
.L70002654:
  move  $a1, $s2
  jal   osRecvMesg
   move  $a2, $zero
  lw    $t7, ($s4)
  addiu $s0, $s0, 1
  sltu  $at, $s0, $t7
  bnezl $at, .L70002654
   move  $a0, $s1
.L70002674:
  lui   $s2, %hi(dmaState_initialized)
  addiu $s2, %lo(dmaState_initialized) # addiu $s2, $s2, -0x1850
  lw    $s0, 4($s2)
  lui   $s3, %hi(audFrameCt)
  addiu $s3, %lo(audFrameCt) # addiu $s3, $s3, 0x30f4
  beqz  $s0, .L700026F4
   nop   
.L70002690:
  lw    $t9, 0xc($s0)
  lw    $t8, ($s3)
  lw    $v0, ($s0)
  addiu $t0, $t9, 1
  sltu  $at, $t0, $t8
  beqz  $at, .L700026EC
   move  $s1, $v0
  lw    $t1, 4($s2)
  bne   $s0, $t1, .L700026BC
   nop   
  sw    $v0, 4($s2)
.L700026BC:
  jal   alUnlink
   move  $a0, $s0
  lw    $a1, 8($s2)
  beql  $a1, $zero, .L700026E4
   sw    $s0, 8($s2)
  jal   alLink
   move  $a0, $s0
  b     .L700026EC
   nop   
  sw    $s0, 8($s2)
.L700026E4:
  sw    $zero, ($s0)
  sw    $zero, 4($s0)
.L700026EC:
  bnez  $s1, .L70002690
   move  $s0, $s1
.L700026F4:
  lui   $s3, %hi(audFrameCt)
  addiu $s3, %lo(audFrameCt) # addiu $s3, $s3, 0x30f4
  lw    $t2, ($s3)
  lw    $ra, 0x2c($sp)
  sw    $zero, ($s4)
  addiu $t3, $t2, 1
  sw    $t3, ($s3)
  lw    $s3, 0x24($sp)
  lw    $s4, 0x28($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x48
");
