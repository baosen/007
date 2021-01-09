// This file contains the scheduler. It is based on code included in Nintendo
// 64's SDK, but has been modified by Rare.
#include "sched.h"
#include "cfb.h"
#include <stddef.h>
#include <types.h>

unsigned int stderr_unused = 0;
unsigned int stderr_enabled = 0;
unsigned int stderr_active = 0;
unsigned int stderr_permitted = 0;
unsigned int userCompareValue = 45000000;
unsigned int currentcount = 0;
unsigned int setby_DPCfill_0 = 0;
unsigned int setby_DPCfill_1 = 0;

float something_with_osVI_0 = 0.0;
float something_with_osVI_4 = 1.0;
float something_with_osVI_8 = 1.0;
float something_with_osVI_C = 1.0;
float something_with_osVI_10 = 1.0;
float something_with_osVI_14 = 0.0;
float something_with_osVI_18 = 0.0;

unsigned int D_800230CC = 1;

OSSched sc;
OSScClient gfxClient[3];

char target_for_counters_maybe[0x10];
char dword_CODE_bss_8005DB40[0xB0];

void activate_stderr(unsigned int flag) { stderr_active = flag; }
void enable_stderr(unsigned int flag) { stderr_enabled = flag; }
void permit_stderr(unsigned int flag) { stderr_permitted = flag; }
void setUserCompareValue(unsigned int value) { userCompareValue = value; }

// Test to display stderr and update Count.
void CheckDisplayErrorBuffer(unsigned int *buffer) {
  if ((stderr_permitted && stderr_active) || stderr_enabled) {
    write_stderr_to_buffer(buffer);
    currentcount = osGetCount();
  }
}

// Test to display stderr every 16th frame.
void CheckDisplayErrorBufferEvery16Frames(unsigned int framecount) {
  if (!(framecount & 0xf)) {
    if ((stderr_permitted && stderr_active) || stderr_enabled) {
      if (userCompareValue < (osGetCount() - currentcount)) {
        write_stderr_to_buffer(cfb_16_a);
        write_stderr_to_buffer(cfb_16_b);
      }
    }
  }
}

// Not 100% on name, came from osInitialize's call to function store current
// Count to 800230A4.
void osCreateLog(void) { currentcount = osGetCount(); }

// Thread management.
asm(R"
glabel osCreateScheduler
  addiu $sp, $sp, -0x28
  sw    $ra, 0x24($sp)
  sw    $s1, 0x20($sp)
  sw    $s0, 0x1c($sp)
  sw    $a1, 0x2c($sp)
  sw    $a2, 0x30($sp)
  sw    $a3, 0x34($sp)
  li    $t6, 1
  li    $t7, 5
  sw    $zero, 0xc8($a0)
  sw    $zero, 0xcc($a0)
  sw    $zero, 0xb4($a0)
  sw    $zero, 0xd0($a0)
  sw    $zero, 0xb8($a0)
  sw    $zero, 0xbc($a0)
  sw    $zero, 0xc0($a0)
  sw    $zero, 0xc4($a0)
  sh    $t6, ($a0)
  sh    $t7, 0x20($a0)
  lw    $t8, 0x2c($sp)
  move  $s0, $a0
  addiu $s1, $a0, 0x40
  sw    $t8, 0xb0($a0)
  move  $a0, $s1
  addiu $a1, $s0, 0x58
  jal   osCreateMesgQueue
   li    $a2, 8
  addiu $a0, $s0, 0x78
  addiu $a1, $s0, 0x90
  jal   osCreateMesgQueue
   li    $a2, 8
  jal   osCreateViManager
   li    $a0, 254
  lbu   $t9, 0x33($sp)
  lui   $t1, %hi(osViModeTable) 
  lui   $v1, %hi(viMode)
  sll   $t0, $t9, 2
  addu  $t0, $t0, $t9
  sll   $t0, $t0, 4
  addiu $t1, %lo(osViModeTable) # addiu $t1, $t1, 0x69c0
  addiu $v1, %lo(viMode) # addiu $v1, $v1, 0x87c
  addu  $t2, $t0, $t1
  sw    $t2, ($v1)
  lw    $t3, 0x1c($t2)
  lui   $at, %hi(viMode+0x4)
  li    $a0, 4
  sw    $t3, %lo(viMode+0x4)($at)
  lw    $t4, 0x30($t2)
  lui   $at, %hi(viMode+0x8)
  move  $a1, $s1
  sw    $t4, %lo(viMode+0x8)($at)
  lw    $t5, 0x44($t2)
  lui   $at, %hi(viMode+0xC)
  li    $a2, 667
  jal   osSetEventMesg
   sw    $t5, %lo(viMode+0xC)($at)
  li    $a0, 9
  move  $a1, $s1
  jal   osSetEventMesg
   li    $a2, 668
  li    $a0, 14
  move  $a1, $s1
  jal   osSetEventMesg
   li    $a2, 669
  move  $a0, $s1
  li    $a1, 666
  jal   osViSetEvent
   lw    $a2, 0x34($sp)
  jal   osCreateLog
   nop   
  lui   $a0, %hi(sp_shed) # $a0, 0x803b
  addiu $a0, %lo(sp_shed) # addiu $a0, $a0, -0x48b0
  jal   set_stack_entry
   li    $a1, 512
  lw    $a0, 0xb0($s0)
  lui   $a2, %hi(__scMain) # $a2, 0x7000
  li    $t6, 30
  sw    $t6, 0x14($sp)
  addiu $a2, %lo(__scMain) # addiu $a2, $a2, 0xd00
  sw    $v0, 0x10($sp)
  li    $a1, 2
  jal   osCreateThread
   move  $a3, $s0
  jal   osStartThread
   lw    $a0, 0xb0($s0)
  lw    $ra, 0x24($sp)
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

void osScAddClient(OSSched *sc, OSScClient *c, OSMesgQueue *msgQ,
                   OSScClient *next) {
  OSIntMask mask;

  mask = osSetIntMask(1);

  c->msgQ = msgQ;
  c[1].next = next;
  c->next = sc->clientList;
  sc->clientList = c;

  osSetIntMask(mask);
}

void osScRemoveClient(OSSched *sc, OSScClient *c) {
  OSScClient *client = sc->clientList, *prev = NULL;
  OSIntMask mask = osSetIntMask(1);

  while (client != NULL) {
    if (client == c) {
      if (prev)
        prev->next = c->next;
      else
        sc->clientList = c->next;
      break;
    }
    prev = client;
    client = client->next;
  }

  osSetIntMask(mask);
}

OSMesgQueue *osScGetCmdQ(OSSched *sc) { return &sc->cmdQ; }

asm(R"
glabel __scMain
  addiu $sp, $sp, -0x50
  sw    $s5, 0x28($sp)
  sw    $s4, 0x24($sp)
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s0, 0x14($sp)
  move  $s2, $a0
  sw    $ra, 0x2c($sp)
  sw    $s1, 0x18($sp)
  sw    $zero, 0x4c($sp)
  move  $s0, $zero
  addiu $s3, $a0, 0x40
  addiu $s4, $sp, 0x4c
  li    $s5, 666
  move  $a0, $s3
.L70000D3C:
  move  $a1, $s4
  jal   osRecvMesg
   li    $a2, 1
  lw    $t6, 0x4c($sp)
  li    $at, 667
  beq   $t6, $s5, .L70000D78
   nop   
  beq   $t6, $at, .L70000D88
   li    $at, 668
  beq   $t6, $at, .L70000D98
   li    $at, 669
  beq   $t6, $at, .L70000DA8
   nop   
  b     .L70000DE0
   nop   
.L70000D78:
  jal   __scHandleRetrace
   move  $a0, $s2
  b     .L70000DE0
   nop   
.L70000D88:
  jal   __scHandleRSP
   move  $a0, $s2
  b     .L70000DE0
   nop   
.L70000D98:
  jal   __scHandleRDP
   move  $a0, $s2
  b     .L70000DE0
   nop   
.L70000DA8:
  jal   reset_cont_rumble_detect
   nop   
  lw    $s0, 0xb4($s2)
  addiu $s1, $s2, 0x20
  beql  $s0, $zero, .L70000DE0
   li    $s0, 1
  lw    $a0, 4($s0)
.L70000DC4:
  move  $a1, $s1
  jal   osSendMesg
   move  $a2, $zero
  lw    $s0, ($s0)
  bnezl $s0, .L70000DC4
   lw    $a0, 4($s0)
  li    $s0, 1
.L70000DE0:
  beql  $s0, $zero, .L70000D3C
   move  $a0, $s3
  lui   $t7, %hi(osTvType) 
  lw    $t7, %lo(osTvType)($t7)
  li    $at, 2
  lui   $a0, %hi(osViModeTable_osViModeNtscLan1)
  bne   $t7, $at, .L70000E14
   nop   
  lui   $a0, %hi(osViModeTable_osViModeMpalLan1)
  jal   osViSetMode
   addiu $a0, %lo(osViModeTable_osViModeMpalLan1) # addiu $a0, $a0, 0x7320
  b     .L70000E20
   lui   $at, 0x3f80
.L70000E14:
  jal   osViSetMode
   addiu $a0, $a0, %lo(osViModeTable_osViModeNtscLan1)
  li    $at, 0x3F800000 # 1.000000
.L70000E20:
  mtc1  $at, $f12
  jal   osViSetXScale
   nop   
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f12
  jal   osViSetYScale
   nop   
  jal   osViRepeatLine
   move  $a0, $zero
  jal   osViBlack
   li    $a0, 1
  move  $a0, $s3
.L70000E50:
  move  $a1, $s4
  jal   osRecvMesg
   li    $a2, 1
  lw    $t8, 0x4c($sp)
  bnel  $t8, $s5, .L70000E50
   move  $a0, $s3
  jal   controllerSchedulerRelated
   nop   
  b     .L70000E50
   move  $a0, $s3
  nop   
  nop   
  nop   
  nop   
  nop   
  nop   
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  lw    $s4, 0x24($sp)
  lw    $s5, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x50
");

asm(R"
glabel __scHandleRetrace
  addiu $sp, $sp, -0x40
  sw    $ra, 0x24($sp)
  sw    $s1, 0x18($sp)
  move  $s1, $a0
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s0, 0x14($sp)
  sw    $zero, 0x3c($sp)
  sw    $zero, 0x30($sp)
  jal   video_related_1
   sw    $zero, 0x2c($sp)
  lw    $t6, 0xd0($s1)
  addiu $t7, $t6, 1
  jal   video_related_7
   sw    $t7, 0xd0($s1)
  jal   controllerSchedulerRelated
   nop   
  jal   music_related_15
   nop   
  addiu $s3, $sp, 0x3c
  addiu $s2, $s1, 0x78
  move  $a0, $s2
  move  $a1, $s3
  jal   osRecvMesg
   move  $a2, $zero
  li    $s0, -1
  beq   $v0, $s0, .L70000F44
   move  $a0, $s1
.L70000F24:
  jal   __scAppendList
   lw    $a1, 0x3c($sp)
  move  $a0, $s2
  move  $a1, $s3
  jal   osRecvMesg
   move  $a2, $zero
  bnel  $v0, $s0, .L70000F24
   move  $a0, $s1
.L70000F44:
  lw    $t8, 0xd4($s1)
  move  $a0, $s1
  addiu $a1, $sp, 0x30
  beql  $t8, $zero, .L70000F78
   lw    $t0, 0xc8($s1)
  lw    $t9, 0xc8($s1)
  beql  $t9, $zero, .L70000F78
   lw    $t0, 0xc8($s1)
  jal   __scYield
   move  $a0, $s1
  b     .L70000FB0
   lw    $s0, 0xb4($s1)
  lw    $t0, 0xc8($s1)
.L70000F78:
  lw    $t3, 0xcc($s1)
  addiu $a2, $sp, 0x2c
  sltiu $t1, $t0, 1
  sll   $t2, $t1, 1
  sltiu $t4, $t3, 1
  or    $s0, $t2, $t4
  jal   __scSchedule
   move  $a3, $s0
  beq   $v0, $s0, .L70000FAC
   move  $a0, $s1
  lw    $a1, 0x30($sp)
  jal   __scExec
   lw    $a2, 0x2c($sp)
.L70000FAC:
  lw    $s0, 0xb4($s1)
.L70000FB0:
  beqz  $s0, .L70000FF0
   nop   
  lw    $t5, 8($s0)
.L70000FBC:
  move  $a1, $s1
  move  $a2, $zero
  beqz  $t5, .L70000FDC
   nop   
  lw    $t6, 0xd0($s1)
  andi  $t7, $t6, 1
  bnezl $t7, .L70000FE8
   lw    $s0, ($s0)
.L70000FDC:
  jal   osSendMesg
   lw    $a0, 4($s0)
  lw    $s0, ($s0)
.L70000FE8:
  bnezl $s0, .L70000FBC
   lw    $t5, 8($s0)
.L70000FF0:
  jal   CheckDisplayErrorBufferEvery16Frames
   lw    $a0, 0xd0($s1)
  lw    $ra, 0x24($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x40
");

asm(R"
glabel __scHandleRSP
  addiu $sp, $sp, -0x30
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $zero, 0x28($sp)
  sw    $zero, 0x24($sp)
  lw    $a1, 0xc8($a0)
  move  $s0, $a0
  sw    $zero, 0xc8($a0)
  lui   $a0, (0x00010001 >> 16) # lui $a0, 1
  ori   $a0, (0x00010001 & 0xFFFF) # ori $a0, $a0, 1
  jal   video_related_3
   sw    $a1, 0x2c($sp)
  lw    $a1, 0x2c($sp)
  lw    $t6, 4($a1)
  addiu $a0, $a1, 0x10
  andi  $t7, $t6, 0x10
  beql  $t7, $zero, .L700010AC
   lw    $t4, 4($a1)
  jal   osSpTaskYielded
   sw    $a1, 0x2c($sp)
  beqz  $v0, .L700010A8
   lw    $a1, 0x2c($sp)
  lw    $t8, 4($a1)
  lw    $t0, 8($a1)
  li    $at, 3
  ori   $t9, $t8, 0x20
  andi  $t1, $t0, 7
  bne   $t1, $at, .L700010C0
   sw    $t9, 4($a1)
  lw    $t2, 0xbc($s0)
  sw    $t2, ($a1)
  lw    $t3, 0xc4($s0)
  sw    $a1, 0xbc($s0)
  bnezl $t3, .L700010C4
   lw    $t6, 0xc8($s0)
  b     .L700010C0
   sw    $a1, 0xc4($s0)
.L700010A8:
  lw    $t4, 4($a1)
.L700010AC:
  li    $at, -3
  move  $a0, $s0
  and   $t5, $t4, $at
  jal   __scTaskComplete
   sw    $t5, 4($a1)
.L700010C0:
  lw    $t6, 0xc8($s0)
.L700010C4:
  lw    $t9, 0xcc($s0)
  move  $a0, $s0
  sltiu $t7, $t6, 1
  sll   $t8, $t7, 1
  sltiu $t0, $t9, 1
  or    $a3, $t8, $t0
  sw    $a3, 0x20($sp)
  addiu $a1, $sp, 0x28
  jal   __scSchedule
   addiu $a2, $sp, 0x24
  lw    $a3, 0x20($sp)
  move  $a0, $s0
  lw    $a1, 0x28($sp)
  beql  $v0, $a3, .L7000110C
   lw    $ra, 0x1c($sp)
  jal   __scExec
   lw    $a2, 0x24($sp)
  lw    $ra, 0x1c($sp)
.L7000110C:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

// Returns the target for DP Cmd clock, buffer counter, pipe counter, and tmem
// counter.
char *get_counters(void) { return &target_for_counters_maybe; }

asm(R"
glabel __scHandleRDP
  addiu $sp, $sp, -0x30
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $zero, 0x28($sp)
  sw    $zero, 0x24($sp)
  lw    $t6, 0xcc($a0)
  move  $s0, $a0
  lui   $a0, (0x00010002 >> 16) # lui $a0, 1
  beql  $t6, $zero, .L700011D0
   lw    $ra, 0x1c($sp)
  jal   video_related_3
   ori   $a0, (0x00010002 & 0xFFFF) # ori $a0, $a0, 2
  lui   $a0, %hi(target_for_counters_maybe)
  jal   osDpGetCounters
   addiu $a0, %lo(target_for_counters_maybe) # addiu $a0, $a0, -0x24d0
  lw    $a1, 0xcc($s0)
  sw    $zero, 0xcc($s0)
  li    $at, -2
  lw    $t7, 4($a1)
  move  $a0, $s0
  and   $t8, $t7, $at
  jal   __scTaskComplete
   sw    $t8, 4($a1)
  lw    $t9, 0xc8($s0)
  lw    $t2, 0xcc($s0)
  move  $a0, $s0
  sltiu $t0, $t9, 1
  sll   $t1, $t0, 1
  sltiu $t3, $t2, 1
  or    $a3, $t1, $t3
  sw    $a3, 0x20($sp)
  addiu $a1, $sp, 0x28
  jal   __scSchedule
   addiu $a2, $sp, 0x24
  lw    $a3, 0x20($sp)
  move  $a0, $s0
  lw    $a1, 0x28($sp)
  beql  $v0, $a3, .L700011D0
   lw    $ra, 0x1c($sp)
  jal   __scExec
   lw    $a2, 0x24($sp)
  lw    $ra, 0x1c($sp)
.L700011D0:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

OSScTask *__scTaskReady(OSScTask *t) {
  void *a, *b;
  if (t) {
    if ((a = osViGetCurrentFramebuffer()) != (b = osViGetNextFramebuffer()))
      return 0;
    return t;
  }
  return 0;
}

asm(R"
glabel __scTaskComplete
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a0, 0x20($sp)
  lw    $t6, 4($a1)
  move  $s0, $a1
  li    $a2, 1
  andi  $t7, $t6, 3
  bnez  $t7, .L700013C4
   move  $v0, $zero
  lw    $a0, 0x50($a1)
  jal   osSendMesg
   lw    $a1, 0x54($a1)
  lw    $t8, 0x10($s0)
  li    $at, 1
  bne   $t8, $at, .L700013BC
   nop   
  lw    $v0, 8($s0)
  andi  $t9, $v0, 0x40
  beqz  $t9, .L700013BC
   andi  $t0, $v0, 0x20
  beqz  $t0, .L700013BC
   lui   $t1, %hi(D_800230CC) 
  lw    $t1, %lo(D_800230CC)($t1)
  beqz  $t1, .L700012A8
   nop   
  jal   osViBlack
   move  $a0, $zero
  lui   $at, %hi(D_800230CC)
  sw    $zero, %lo(D_800230CC)($at)
.L700012A8:
  lui   $v1, %hi(something_with_osVI_0)
  lw    $v1, %lo(something_with_osVI_0)($v1)
  lui   $t3, %hi(something_with_osVI_14)
  lui   $a0, (0x00080401 >> 16) # lui $a0, 8
  sll   $t2, $v1, 2
  addu  $t3, $t3, $t2
  lw    $t3, %lo(something_with_osVI_14)($t3)
  move  $v1, $t2
  beqz  $t3, .L70001358
   nop   
  jal   osSetIntMask
   ori   $a0, (0x00080401 & 0xFFFF) # ori $a0, $a0, 0x401
  lui   $v1, %hi(something_with_osVI_0)
  lw    $v1, %lo(something_with_osVI_0)($v1)
  lui   $t7, %hi(dword_CODE_bss_8005DB40) 
  addiu $t7, %lo(dword_CODE_bss_8005DB40) # addiu $t7, $t7, -0x24c0
  sll   $t6, $v1, 2
  addu  $t6, $t6, $v1
  sll   $t6, $t6, 4
  lui   $t5, %hi(sc+416)
  sll   $t4, $v1, 2
  addu  $t5, $t5, $t4
  addu  $t8, $t6, $t7
  addiu $t1, $t8, 0x48
  lw    $t5, %lo(sc+416)($t5)
.L7000130C:
  lw    $at, ($t8)
  addiu $t8, $t8, 0xc
  addiu $t5, $t5, 0xc
  sw    $at, -0xc($t5)
  lw    $at, -8($t8)
  sw    $at, -8($t5)
  lw    $at, -4($t8)
  bne   $t8, $t1, .L7000130C
   sw    $at, -4($t5)
  lw    $at, ($t8)
  move  $a0, $v0
  sw    $at, ($t5)
  lw    $t1, 4($t8)
  jal   osSetIntMask
   sw    $t1, 4($t5)
  lui   $v1, %hi(something_with_osVI_0)
  lw    $v1, %lo(something_with_osVI_0)($v1)
  sll   $t2, $v1, 2
  move  $v1, $t2
.L70001358:
  lui   $at, %hi(something_with_osVI_4)
  addu  $at, $at, $v1
  jal   osViSetXScale
   lwc1  $f12, %lo(something_with_osVI_4)($at)
  lui   $t3, %hi(something_with_osVI_0) 
  lw    $t3, %lo(something_with_osVI_0)($t3)
  lui   $at, %hi(something_with_osVI_C)
  sll   $t4, $t3, 2
  addu  $at, $at, $t4
  jal   osViSetYScale
   lwc1  $f12, %lo(something_with_osVI_C)($at)
  lui   $t6, %hi(something_with_osVI_0) 
  lw    $t6, %lo(something_with_osVI_0)($t6)
  lui   $at, %hi(something_with_osVI_0)
  addiu $t7, $t6, 1
  bgez  $t7, .L700013A8
   andi  $t0, $t7, 1
  beqz  $t0, .L700013A8
   nop   
  addiu $t0, $t0, -2
.L700013A8:
  sw    $t0, %lo(something_with_osVI_0)($at)
  jal   CheckDisplayErrorBuffer
   lw    $a0, 0xc($s0)
  jal   osViSwapBuffer
   lw    $a0, 0xc($s0)
.L700013BC:
  b     .L700013C4
   li    $v0, 1
.L700013C4:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

void __scAppendList(OSSched *sc, OSScTask *t) {
  long type = t->list.t.type;
  if (type == M_AUDTASK) {
    if (sc->audioListTail)
      sc->audioListTail->next = t;
    else
      sc->audioListHead = t;

    sc->audioListTail = t;
    sc->doAudio = 1;
  } else {
    if (sc->gfxListTail)
      sc->gfxListTail->next = t;
    else
      sc->gfxListHead = t;

    sc->gfxListTail = t;
  }
  t->next = NULL;
  t->state = t->flags & OS_SC_RCP_MASK;
}

/**
 * (DPC fill)
 */
asm(R"
glabel __scExec
  addiu $sp, $sp, -0x28
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  move  $s0, $a1
  move  $s1, $a2
  sw    $ra, 0x1c($sp)
  beqz  $a1, .L7000150C
   sw    $a0, 0x28($sp)
  lw    $v0, 0x10($a1)
  li    $at, 2
  bnel  $v0, $at, .L70001480
   li    $at, 2
  jal   osWritebackDCacheAll
   nop   
  lw    $v0, 0x10($s0)
  li    $at, 2
.L70001480:
  beql  $v0, $at, .L700014A8
   li    $at, 2
  lw    $t6, 4($s0)
  andi  $t7, $t6, 0x10
  bnezl $t7, .L700014A8
   li    $at, 2
  jal   osDpSetStatus
   li    $a0, 960
  lw    $v0, 0x10($s0)
  li    $at, 2
.L700014A8:
  bne   $v0, $at, .L700014C4
   lui   $a0, 4
  lui   $a0, (0x00030001 >> 16) # lui $a0, 3
  jal   video_related_3
   ori   $a0, (0x00030001 & 0xFFFF) # ori $a0, $a0, 1
  b     .L700014DC
   lw    $t8, 4($s0)
.L700014C4:
  jal   video_related_3
   ori   $a0, (0x00030001 & 0xFFFF) # ori $a0, $a0, 1
  lui   $a0, (0x00020002 >> 16) # lui $a0, 2
  jal   video_related_3
   ori   $a0, (0x00020002 & 0xFFFF) # ori $a0, $a0, 2
  lw    $t8, 4($s0)
.L700014DC:
  li    $at, -49
  addiu $a0, $s0, 0x10
  and   $t9, $t8, $at
  sw    $t9, 4($s0)
  jal   osSpTaskLoad
   sw    $a0, 0x20($sp)
  jal   osSpTaskStartGo
   lw    $a0, 0x20($sp)
  lw    $t0, 0x28($sp)
  bne   $s0, $s1, .L7000150C
   sw    $s0, 0xc8($t0)
  sw    $s1, 0xcc($t0)
.L7000150C:
  beql  $s1, $zero, .L70001550
   lw    $ra, 0x1c($sp)
  beql  $s1, $s0, .L70001550
   lw    $ra, 0x1c($sp)
  lw    $t1, 0x3c($s1)
  lw    $a0, 0x38($s1)
  lw    $a2, ($t1)
  jal   osDpSetNextBuffer
   lw    $a3, 4($t1)
  li    $t2, 1
  lui   $at, %hi(setby_DPCfill_0)
  lw    $t3, 0x28($sp)
  sw    $t2, %lo(setby_DPCfill_0)($at)
  lui   $at, %hi(setby_DPCfill_1)
  sw    $zero, %lo(setby_DPCfill_1)($at)
  sw    $s1, 0xcc($t3)
  lw    $ra, 0x1c($sp)
.L70001550:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

void __scYield(OSSched *sc) {
  if (sc->curRSPTask->list.t.type == M_GFXTASK) {
    sc->curRSPTask->state |= 0x0010;
    osSpTaskYield();
  }
}

asm(R"
.late_rodata
glabel jpt_80028400
    .word .L70001758
    .word .L70001704
    .word .L7000167C
    .word .L70001758
    .word .L70001758
    .word .L70001704
    .word .L70001704

.text
glabel __scSchedule
  addiu $sp, $sp, -0x28
  sw    $s1, 0x18($sp)
  move  $s1, $a0
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x14($sp)
  li    $t0, -3
.L700015B4:
  lw    $t6, 0xd4($s1)
  move  $v1, $a3
  lw    $s0, 0xbc($s1)
  beqz  $t6, .L7000161C
   lw    $v0, 0xb8($s1)
  andi  $t7, $a3, 2
  beql  $t7, $zero, .L70001620
   move  $a0, $s0
  beql  $s0, $zero, .L700015FC
   sw    $v0, ($a1)
  lw    $t8, 8($s0)
  and   $v1, $a3, $t0
  andi  $t9, $t8, 0x10
  beql  $t9, $zero, .L700015FC
   sw    $v0, ($a1)
  b     .L70001758
   sw    $s0, ($a1)
  sw    $v0, ($a1)
.L700015FC:
  lw    $t2, 0xb8($s1)
  sw    $zero, 0xd4($s1)
  and   $v1, $a3, $t0
  lw    $t3, ($t2)
  bnez  $t3, .L70001758
   sw    $t3, 0xb8($s1)
  b     .L70001758
   sw    $zero, 0xc0($s1)
.L7000161C:
  move  $a0, $s0
.L70001620:
  sw    $v1, 0x24($sp)
  sw    $a1, 0x2c($sp)
  sw    $a2, 0x30($sp)
  jal   __scTaskReady
   sw    $a3, 0x34($sp)
  lw    $v1, 0x24($sp)
  lw    $a1, 0x2c($sp)
  lw    $a2, 0x30($sp)
  lw    $a3, 0x34($sp)
  li    $t0, -3
  beqz  $v0, .L70001758
   li    $t1, -2
  lw    $t5, 8($s0)
  andi  $t6, $t5, 7
  addiu $t7, $t6, -1
  sltiu $at, $t7, 7
  beqz  $at, .L70001758
   sll   $t7, $t7, 2
  lui   $at, %hi(jpt_80028400)
  addu  $at, $at, $t7
  lw    $t7, %lo(jpt_80028400)($at) # lw    $t7, -0x7c00($at)
  jr    $t7
   nop   
.L7000167C:
  lw    $t8, 4($s0)
  andi  $t2, $a3, 2
  li    $at, 3
  andi  $t9, $t8, 0x20
  beqz  $t9, .L700016D4
   nop   
  beqz  $t2, .L70001758
   nop   
  sw    $s0, ($a1)
  lw    $t3, 4($s0)
  and   $v1, $a3, $t0
  andi  $t4, $t3, 1
  beql  $t4, $zero, .L700016C0
   lw    $t5, 0xbc($s1)
  sw    $s0, ($a2)
  and   $v1, $v1, $t1
  lw    $t5, 0xbc($s1)
.L700016C0:
  lw    $t6, ($t5)
  bnez  $t6, .L70001758
   sw    $t6, 0xbc($s1)
  b     .L70001758
   sw    $zero, 0xc4($s1)
.L700016D4:
  bne   $a3, $at, .L70001758
   nop   
  sw    $s0, ($a2)
  sw    $s0, ($a1)
  lw    $t8, 0xbc($s1)
  li    $at, -4
  and   $v1, $a3, $at
  lw    $t9, ($t8)
  bnez  $t9, .L70001758
   sw    $t9, 0xbc($s1)
  b     .L70001758
   sw    $zero, 0xc4($s1)
.L70001704:
  lw    $v0, 4($s0)
  andi  $t4, $a3, 2
  andi  $t3, $v0, 2
  beqz  $t3, .L7000172C
   andi  $t5, $v0, 1
  beqz  $t4, .L70001758
   nop   
  sw    $s0, ($a1)
  b     .L70001758
   and   $v1, $a3, $t0
.L7000172C:
  beqz  $t5, .L70001758
   andi  $t6, $a3, 1
  beqz  $t6, .L70001758
   nop   
  sw    $s0, ($a2)
  lw    $t7, 0xbc($s1)
  and   $v1, $a3, $t1
  lw    $t8, ($t7)
  bnez  $t8, .L70001758
   sw    $t8, 0xbc($s1)
  sw    $zero, 0xc4($s1)
.L70001758:
  beql  $v1, $a3, .L7000176C
   lw    $ra, 0x1c($sp)
  b     .L700015B4
   move  $a3, $v1
  lw    $ra, 0x1c($sp)
.L7000176C:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   move  $v0, $v1
");
