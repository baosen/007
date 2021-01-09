#ifndef _ULTRA64_SPTASK_H_
#define _ULTRA64_SPTASK_H_

/* Task Types */
enum { M_GFXTASK = 1, M_AUDTASK, M_VIDTASK };
enum { M_HVQTASK = 6, M_HVQMTASK };

// gGfxSPTaskYieldBuffer has to be changed for this too
#if (defined(F3DEX_GBI) || defined(F3DLP_GBI) || defined(F3DEX_GBI_2))
#define OS_YIELD_DATA_SIZE 0xc00
#else
#define OS_YIELD_DATA_SIZE 0x900
#endif
#define OS_YIELD_AUDIO_SIZE 0x400

/* Flags */
enum { M_TASK_FLAG0 = 1, M_TASK_FLAG1 };

/* SpStatus */
#define SPSTATUS_CLEAR_HALT 0x00000001
#define SPSTATUS_SET_HALT 0x00000002
#define SPSTATUS_CLEAR_BROKE 0x00000004
#define SPSTATUS_CLEAR_INTR 0x00000008
#define SPSTATUS_SET_INTR 0x00000010
#define SPSTATUS_CLEAR_SSTEP 0x00000020
#define SPSTATUS_SET_SSTEP 0x00000040
#define SPSTATUS_CLEAR_INTR_ON_BREAK 0x00000080
#define SPSTATUS_SET_INTR_ON_BREAK 0x00000100
#define SPSTATUS_CLEAR_SIGNAL0 0x00000200
#define SPSTATUS_SET_SIGNAL0 0x00000400
#define SPSTATUS_CLEAR_SIGNAL1 0x00000800
#define SPSTATUS_SET_SIGNAL1 0x00001000
#define SPSTATUS_CLEAR_SIGNAL2 0x00002000
#define SPSTATUS_SET_SIGNAL2 0x00004000
#define SPSTATUS_CLEAR_SIGNAL3 0x00008000
#define SPSTATUS_SET_SIGNAL3 0x00010000
#define SPSTATUS_CLEAR_SIGNAL4 0x00020000
#define SPSTATUS_SET_SIGNAL4 0x00040000
#define SPSTATUS_CLEAR_SIGNAL5 0x00080000
#define SPSTATUS_SET_SIGNAL5 0x00100000
#define SPSTATUS_CLEAR_SIGNAL6 0x00200000
#define SPSTATUS_SET_SIGNAL6 0x00800000
#define SPSTATUS_CLEAR_SIGNAL7 0x01000000
#define SPSTATUS_SET_SIGNAL7 0x02000000

#define SPSTATUS_HALT 0x0001
#define SPSTATUS_BROKE 0x0002
#define SPSTATUS_DMA_BUSY 0x0004
#define SPSTATUS_DMA_FULL 0x0008
#define SPSTATUS_IO_FULL 0x0010
#define SPSTATUS_SINGLE_STEP 0x0020
#define SPSTATUS_INTERRUPT_ON_BREAK 0x0040
#define SPSTATUS_SIGNAL0_SET 0x0080
#define SPSTATUS_SIGNAL1_SET 0x0100
#define SPSTATUS_SIGNAL2_SET 0x0200
#define SPSTATUS_SIGNAL3_SET 0x0400
#define SPSTATUS_SIGNAL4_SET 0x0800
#define SPSTATUS_SIGNAL5_SET 0x1000
#define SPSTATUS_SIGNAL6_SET 0x2000
#define SPSTATUS_SIGNAL7_SET 0x4000

typedef struct {
  unsigned int type;
  unsigned int flags;

  unsigned long long *ucode_boot;
  unsigned int ucode_boot_size;

  unsigned long long *ucode;
  unsigned int ucode_size;

  unsigned long long *ucode_data;
  unsigned int ucode_data_size;

  unsigned long long *dram_stack;
  unsigned int dram_stack_size;

  unsigned long long *output_buff;
  unsigned long long *output_buff_size;

  unsigned long long *data_ptr;
  unsigned int data_size;

  unsigned long long *yield_data_ptr;
  unsigned int yield_data_size;
} OSTask_t;

typedef union {
  OSTask_t t;
  long long int force_structure_alignment;
} OSTask;

typedef unsigned int OSYieldResult;

#define osSpTaskStart(p)                                                       \
  osSpTaskLoad(p);                                                             \
  osSpTaskStartGo(p);

void osSpTaskLoad(OSTask *task);
void osSpTaskStartGo(OSTask *task);
void osSpTaskYield(void);
OSYieldResult osSpTaskYielded(OSTask *task);

#endif
