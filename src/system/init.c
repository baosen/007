// This file contains the initial bootstrap code that is ran before entering the
// main game code.
#include "sched.h"
#include <libultra.h>
#include <stddef.h>
#include <types.h>

extern unsigned char sp_rmon[];
extern unsigned char sp_idle[];
extern unsigned char sp_main[];
extern unsigned int unknown_init_val;
extern unsigned int cart_hw_address;

struct debug_handler_entry {
  void *address;
  char *ptr_name;
};

OSThread rmonThread, idleThread, mainThread, schedulerThread;
OSMesgQueue gfxFrameMsgQ;
OSMesg gfxFrameMsgBuf[32];
OSMesgQueue *sched_cmdQ;

// - Inflates the main code and data payload from segment.
// - Initializes N64OS.
// - Initializes TLB index.
// - Invalidate caches.
// - Setups R4300's floating-point control/status-register.
// - Setups RSP's stack memory.
// - Starts main thread loop.
asm(R"
glabel init
  addiu $sp, $sp, -0x40
  sw    $ra, 0x24($sp)
  sw    $s1, 0x20($sp)
  jal   get_csegmentSegmentStart
   sw    $s0, 0x1c($sp)

  jal   get_cdataRomSegmentStart
   move  $s0, $v0

  jal   get_cdataRomSegmentEnd
   sw    $v0, 0x34($sp)

  lw    $t6, 0x34($sp)
  jal   get_inflateRomSegmentStart
   subu  $s1, $v0, $t6

  jal   get_inflateRomSegmentEnd
   sw    $v0, 0x28($sp)

  lw    $t7, 0x28($sp)
  lui   $t2, 0x7020
  move  $a1, $s0
  subu  $t8, $v0, $t7
  addu  $a0, $s1, $t8
  addiu $v1, $a0, -1
  bltz  $v1, .L7000058C
   lui   $a2, 0x8030
  lui   $t9, 0x7020
  subu  $a0, $t9, $s1
  addu  $v0, $s0, $v1

.L70000574:
  lbu   $t0, ($v0)
  addu  $t1, $a0, $v1
  addiu $v1, $v1, -1
  addiu $v0, $v0, -1
  bgez  $v1, .L70000574
   sb    $t0, ($t1)

.L7000058C:
  jal   jump_decompressfile
   subu  $a0, $t2, $s1
  lui   $t3, %hi(_inflateRomSegmentStart) # $t3, 3
  lui   $t4, %hi(_kernelRomSegmentStart) # $t4, 0
  addiu $t4, %lo(_kernelRomSegmentStart) # addiu $t4, $t4, 0x1050
  addiu $t3, %lo(_inflateRomSegmentStart) # addiu $t3, $t3, 0x3590
  lui   $at, (0x000FFFB1 >> 16) # lui $at, 0xf
  ori   $at, (0x000FFFB1 & 0xFFFF) # ori $at, $at, 0xffb1
  subu  $v0, $t3, $t4
  slt   $at, $v0, $at
  bnez  $at, .L70000604
  lui   $at, (0xFFF00050 >> 16) # lui $at, 0xfff0

  ori   $at, (0xFFF00050 & 0xFFFF) # ori $at, $at, 0x50
  lui   $a1, %hi(0x00101000) # $a1, 0x10
  lui   $a2, %hi(0x70100400) # $a2, 0x7010
  addiu $a2, %lo(0x70100400) # addiu $a2, $a2, 0x400
  addiu $a1, %lo(0x00101000) # addiu $a1, $a1, 0x1000
  addu  $a3, $v0, $at
  jal   osPiRawStartDma
  move  $a0, $zero

  jal   osPiGetStatus
  nop   

  andi  $t5, $v0, 1
  beqz  $t5, .L70000604
   nop   

.L700005F0:
  jal   osPiGetStatus
   nop   
  andi  $t6, $v0, 1
  bnez  $t6, .L700005F0
   nop   

.L70000604:
  jal   osInitialize
   nop   

  jal   set_hardwire_TLB_to_2
   nop   

  lui   $s0, %hi(0x80000000)
  lui   $v0, %hi(resolve_TLBaddress_for_InvalidHit) # $v0, 0x7000
  lui   $a0, (0x80000080 >> 16) # lui $a0, 0x8000
  addiu $v0, %lo(resolve_TLBaddress_for_InvalidHit) # addiu $v0, $v0, 0x1b60
  move  $v1, $s0
  ori   $a0, (0x80000080 & 0xFFFF) # ori $a0, $a0, 0x80

.L7000062C:
  lw    $t7, ($v0)
  addiu $v1, $v1, 0x10
  addiu $v0, $v0, 0x10
  sw    $t7, -0x10($v1)
  lw    $t8, -0xc($v0)
  sw    $t8, -0xc($v1)
  lw    $t9, -8($v0)
  sw    $t9, -8($v1)
  lw    $t0, -4($v0)
  bne   $v1, $a0, .L7000062C
   sw    $t0, -4($v1)
  jal   osWritebackDCacheAll
  nop

  move  $a0, $s0
  jal   osInvalICache
  li    $a1, 16384
  li    $s0, 2
  li    $s1, 32

.L70000674:
  jal   osUnmapTLB
  move  $a0, $s0

  addiu $s0, 1 # addiu $s0, $s0, 1
  bne   $s0, $s1, .L70000674
  nop

  jal   __osGetFpcCsr
  nop

  jal   __osSetFpcCsr
  ori   $a0, $v0, 0xe80

  lui   $a0, %hi(sp_main) # $a0, 0x803b
  addiu $a0, %lo(sp_main) # addiu $a0, $a0, -0x46b0
  jal   set_stack_entry
  li    $a1, 32768

  lui   $s0, %hi(mainThread)
  addiu $s0, %lo(mainThread) # addiu $s0, $s0, -0x29c0
  lui   $a2, %hi(mainproc) # $a2, 0x7000
  li    $t4, 10
  sw    $t4, 0x14($sp)
  addiu $a2, %lo(mainproc) # addiu $a2, $a2, 0x89c
  move  $a0, $s0
  li    $a1, 3
  move  $a3, $zero
  jal   osCreateThread
  sw    $v0, 0x10($sp)

  jal   osStartThread
  move  $a0, $s0

  lw    $ra, 0x24($sp)
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  jr    $ra
  addiu $sp, $sp, 0x40
");

void *set_stack_entry(unsigned char *stack, unsigned int size) {
  return stack + size - 8;
}

void init_audio_rsp_microcode(void) { // unused.
  unknown_init_val = 1;
  cart_hw_address = 0x10000000;
}

void idleproc(void *arg) {
  for (;;)
    ;
}

void start_idle_thread(void) {
  osCreateThread(&idleThread, (OSId)1, idleproc, 0,
                 set_stack_entry(&sp_idle, 0x40), (OSPri)0);
  osStartThread(&idleThread);
}

// Indy board detection thread; now forcably returns INDI_NOT_DETECTED (1).
void start_rmon_thread(void) {
  void thread0_rmon(void);
  osCreateThread(&rmonThread, (OSId)0, thread0_rmon, 0,
                 set_stack_entry(&sp_rmon, 0x300), (OSPri)250);
  osStartThread(&rmonThread);
}

// Setups an RCP task scheduler responsible for executing audio and graphics
// tasks on the RCP.
void setup_rcp_scheduler(void) {
  osCreateMesgQueue(&gfxFrameMsgQ, &gfxFrameMsgBuf, 32);
#define NUMBER_OF_FIELDS 1
  if (TV_TYPE_MPAL == osTvType) {
    osCreateScheduler(&sc, &schedulerThread, OS_VI_MPAL_LAN1, NUMBER_OF_FIELDS);
  } else {
    osCreateScheduler(
        &sc, &schedulerThread,
        OS_VI_NTSC_LAN1, // Set the VI manager's video mode to NTSC.
        NUMBER_OF_FIELDS);
  }
  osScAddClient(&sc, &gfxClient, &gfxFrameMsgQ, 0);
  sched_cmdQ = osScGetCmdQ(&sc);
}

// Main thread function.
void mainproc(void *args) {
  start_idle_thread();
  start_nulled_entry();
  start_pi_manager();
  start_rmon_thread();
  if (check_boot_switches())
    osStopThread(NULL); // NULL sets the currently running thread.
  osSetThreadPri(NULL, 10);
  setup_rcp_scheduler();
  start_game();
}

// V0= p->last entry in copy of debug handler code/name table. Copies table from
// 8002304C-80023084 to stack.
asm(R"
glabel setuplastentryofdebughandler
  addiu $sp, $sp, -0x40
  lui   $t6, %hi(debug_handler_table) 
  addiu $v1, $sp, 8
  addiu $t6, %lo(debug_handler_table) # addiu $t6, $t6, 0x304c
  addiu $t9, $t6, 0x30
  move  $t0, $v1
.L70000920:
  lw    $at, ($t6)
  addiu $t6, $t6, 0xc
  addiu $t0, $t0, 0xc
  sw    $at, -0xc($t0)
  lw    $at, -8($t6)
  sw    $at, -8($t0)
  lw    $at, -4($t6)
  bne   $t6, $t9, .L70000920
   sw    $at, -4($t0)
  lw    $at, ($t6)
  move  $v0, $v1
  sw    $at, ($t0)
  lw    $t9, 4($t6)
  sw    $t9, 4($t0)
  lw    $t1, 8($v0)
.L7000095C:
  addiu $v0, $v0, 8
  bnezl $t1, .L7000095C
   lw    $t1, 8($v0)
  jr    $ra
   addiu $sp, $sp, 0x40
");
