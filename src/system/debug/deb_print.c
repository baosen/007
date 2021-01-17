// This file contains the stderr manager.
#include "cfb.h"

extern unsigned char sp_rmon[];
extern unsigned char sp_idle[];
extern unsigned char sp_shed[];
extern unsigned char sp_main[];
extern unsigned char sp_audi[];
extern unsigned char sp_debug[];

struct debug_processor_error_entry {
  unsigned int val1, val2;
  void *string;
};

unsigned int D_80023300 = 0; // filler.

struct debug_processor_error_entry debug_processor_error_table[] = {
    {0x80000000, 0x80000000, "BD"},
    {0x8000, 0x8000, "IP8"},
    {0x4000, 0x4000, "IP7"},
    {0x2000, 0x2000, "IP6"},
    {0x1000, 0x1000, "IP5"},
    {0x800, 0x800, "IP4"},
    {0x400, 0x400, "IP3"},
    {0x200, 0x200, "IP2"},
    {0x100, 0x100, "IP1"},
    {0x7C, 0, "Int"},
    {0x7C, 4, "TLBmod"},
    {0x7C, 8, "TLBload"},
    {0x7C, 0xC, "TLBstore"},
    {0x7C, 0x10, "Address error on load or instruction fetch"},
    {0x7C, 0x14, "Address error on store"},
    {0x7C, 0x18, "Bus error exception on instruction fetch"},
    {0x7C, 0x1C, "Bus error exception on data reference"},
    {0x7C, 0x20, "Syscall"},
    {0x7C, 0x24, "Brk"},
    {0x7C, 0x28, "Reserved instruction"},
    {0x7C, 0x2C, "Cop unusable"},
    {0x7C, 0x30, "Overflow"},
    {0x7C, 0x34, "Trap"},
    {0x7C, 0x38, "Virtual coherency exception on intruction fetch"},
    {0x7C, 0x3C, "Fp exception"},
    {0x7C, 0x5C, "Watchpoint"},
    {0x7C, 0x7C, "Virtual coherency exception on data reference"},
    {0, 0, ""},
    {0x80000000, 0x80000000, "CU3"},
    {0x40000000, 0x40000000, "CU2"},
    {0x20000000, 0x20000000, "CU1"},
    {0x10000000, 0x10000000, "CU0"},
    {0x8000000, 0x8000000, "RP"},
    {0x4000000, 0x4000000, "FR"},
    {0x2000000, 0x2000000, "RE"},
    {0x400000, 0x400000, "BEV"},
    {0x200000, 0x200000, "TS"},
    {0x100000, 0x100000, "SR"},
    {0x40000, 0x40000, "CH"},
    {0x20000, 0x20000, "CE"},
    {0x10000, 0x10000, "DE"},
    {0x8000, 0x8000, "IM8"},
    {0x4000, 0x4000, "IM7"},
    {0x2000, 0x2000, "IM6"},
    {0x1000, 0x1000, "IM5"},
    {0x800, 0x800, "IM4"},
    {0x400, 0x400, "IM3"},
    {0x200, 0x200, "IM2"},
    {0x100, 0x100, "IM1"},
    {0x80, 0x80, "KX"},
    {0x40, 0x40, "SX"},
    {0x20, 0x20, "UX"},
    {0x18, 0x10, "USR"},
    {0x18, 8, "SUP"},
    {0x18, 0, "KER"},
    {4, 4, "ERL"},
    {2, 2, "EXL"},
    {1, 1, "IE"},
    {0, 0, ""},
    {0x1000000, 0x1000000, "FS"},
    {0x800000, 0x800000, "C"},
    {0x20000, 0x20000, "Unimplemented"},
    {0x10000, 0x10000, "Invalid op"},
    {0x8000, 0x8000, "/ by 0.0"},
    {0x4000, 0x4000, "Overflow"},
    {0x2000, 0x2000, "Underflow"},
    {0x1000, 0x1000, "Inexact op"},
    {0x800, 0x800, "EV"},
    {0x400, 0x400, "EZ"},
    {0x200, 0x200, "EO"},
    {0x100, 0x100, "EU"},
    {0x80, 0x80, "EI"},
    {0x40, 0x40, "FV"},
    {0x20, 0x20, "FZ"},
    {0x10, 0x10, "FO"},
    {8, 8, "FU"},
    {4, 4, "FI"},
    {3, 0, "RN"},
    {3, 1, "RZ"},
    {3, 2, "RP"},
    {3, 3, "RM"},
    {0, 0, ""}};

void *stack_ptrs_1[] = {&sp_rmon, &sp_idle, &sp_shed, &sp_main, &sp_audi};
void *stack_ptrs_2[] = {&sp_idle, &sp_shed, &sp_main, &sp_audi, &sp_debug};
void *stack_ptrs_3[] = {&sp_rmon, &sp_idle, &sp_shed, &sp_main, &sp_audi};

char stderr_buffer[2280] = {'\0'};

unsigned int std_error_font_bitcode[] = {
    0x00000000, 0x22220200, 0x55000000, 0x5F5F500,  0x27427200, 0x05124500,
    0x34255300, 0x22000000, 0x24444420, 0x42222240, 0x06F6F600, 0x272000,
    0x240,      0x70000,    0x200,      0x11224480, 0x25555200, 0x26222700,
    0x25125700, 0x61211600, 0x33557300, 0x64611600, 0x24655200, 0x71112200,
    0x25755200, 0x25531600, 0x200200,   0x200640,   0x1242100,  0x707000,
    0x4212400,  0x7120200,  0x25FF5700, 0x2557D00,  0x6575E00,  0x7445300,
    0x7555600,  0x7565700,  0x7564400,  0x7C95700,  0x5575500,  0x7222700,
    0x3111600,  0x5665500,  0x4445F00,  0xDFF9D00,  0xF777D00,  0x7DD5700,
    0x7564600,  0x7995770,  0x7565500,  0x7461E00,  0x7222200,  0xD999600,
    0xD552200,  0xDF77500,  0xD625500,  0x5622600,  0x7125700,  0x32222230,
    0x44222110, 0x62222260, 0x25000000, 0x700,      0x42200000, 0x67D700,
    0x44755700, 0x788600,   0x117DD700, 0x6FC700,   0x32722700, 0x7DD730,
    0x44755500, 0x2622700,  0x2711130,  0x44766500, 0x62222700, 0xFFFF00,
    0x755D00,   0x6DD600,   0x755740,   0x799710,   0x744600,   0x775700,
    0x2722300,  0x555700,   0x552200,   0x577500,   0x562500,   0x552220,
    0x703700,   0x12242210, 0x2222220,  0x42212240, 0x5A0000};

void *ptr_videobuffer1 = 0, *ptr_videobuffer2 = 0;

unsigned int padding_80024184[4] = {0};

/**
 *     write char A2 to (A0,A1) in stderr
 *     accepts: A0=xpos, A1=ypos, A2=char
 */
asm(R"
glabel write_char_to_pos_stderr
  andi  $t6, $a2, 0xff
  sw    $a2, 8($sp)
  li    $at, 9
  move  $a2, $t6
  beq   $t6, $at, .L70005654
   move  $v0, $t6
  li    $at, 10
  bne   $t6, $at, .L7000565C
   nop   
.L70005654:
  move  $a2, $zero
  move  $v0, $zero
.L7000565C:
  blez  $v0, .L70005668
   slti  $at, $v0, 0x20
  bnez  $at, .L70005674
.L70005668:
   slti  $at, $v0, 0x7f
  bnez  $at, .L70005678
   nop   
.L70005674:
  li    $a2, 63
.L70005678:
  bltz  $a0, .L700056B4
   slti  $at, $a0, 0x48
  beqz  $at, .L700056B4
   nop   
  bltz  $a1, .L700056B4
   slti  $at, $a1, 0x20
  beqz  $at, .L700056B4
   sll   $t7, $a1, 3
  addu  $t7, $t7, $a1
  sll   $t7, $t7, 3
  subu  $t7, $t7, $a1
  addu  $t8, $t7, $a0
  lui   $at, %hi(stderr_buffer)
  addu  $at, $at, $t8
  sb    $a2, %lo(stderr_buffer)($at)
.L700056B4:
  jr    $ra
   nop   
");

// Write a single character A0 to stderr.
asm(R"
glabel __osRdbSend
  addiu $sp, $sp, -0x28
  andi  $a2, $a0, 0xff
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a0, 0x28($sp)
  beqz  $a2, .L700057B8
   move  $v0, $a2
  li    $at, 9
  bne   $a2, $at, .L70005708
   lui   $s0, %hi(stderr_buffer + 0x8E0)
  addiu $s0, %lo(stderr_buffer + 0x8E0) # addiu $s0, $s0, 0x3ff8
.L700056E8:
  jal   __osRdbSend
   li    $a0, 32
  lw    $t6, ($s0)
  andi  $t7, $t6, 7
  bnez  $t7, .L700056E8
   nop   
  b     .L700057BC
   lw    $ra, 0x1c($sp)
.L70005708:
  li    $at, 10
  bne   $v0, $at, .L70005730
   lui   $v1, %hi(stderr_buffer + 0x8E4)
  addiu $v1, %lo(stderr_buffer + 0x8E4) # addiu $v1, $v1, 0x3ffc
  lw    $t8, ($v1)
  lui   $s0, %hi(stderr_buffer + 0x8E0)
  addiu $s0, %lo(stderr_buffer + 0x8E0) # addiu $s0, $s0, 0x3ff8
  addiu $t9, $t8, 1
  sw    $t9, ($v1)
  sw    $zero, ($s0)
.L70005730:
  lui   $v1, %hi(stderr_buffer + 0x8E4)
  addiu $v1, %lo(stderr_buffer + 0x8E4) # addiu $v1, $v1, 0x3ffc
  lw    $a1, ($v1)
  lui   $s0, %hi(stderr_buffer + 0x8E0)
  addiu $s0, %lo(stderr_buffer + 0x8E0) # addiu $s0, $s0, 0x3ff8
  slti  $at, $a1, 0x1f
  bnez  $at, .L70005774
   addiu $a0, $a1, -0x1e
  sw    $v0, 0x24($sp)
  jal   scroll_stderr_oneline
   sb    $a2, 0x2b($sp)
  lui   $v1, %hi(stderr_buffer + 0x8E4)
  addiu $v1, %lo(stderr_buffer + 0x8E4) # addiu $v1, $v1, 0x3ffc
  li    $t0, 30
  lw    $v0, 0x24($sp)
  lbu   $a2, 0x2b($sp)
  sw    $t0, ($v1)
.L70005774:
  li    $at, 10
  beql  $v0, $at, .L700057BC
   lw    $ra, 0x1c($sp)
  lw    $a0, ($s0)
  jal   write_char_to_pos_stderr
   lw    $a1, ($v1)
  lw    $t1, ($s0)
  lui   $v1, %hi(stderr_buffer + 0x8E4)
  addiu $v1, %lo(stderr_buffer + 0x8E4) # addiu $v1, $v1, 0x3ffc
  addiu $t2, $t1, 1
  slti  $at, $t2, 0x47
  bnez  $at, .L700057B8
   sw    $t2, ($s0)
  lw    $t4, ($v1)
  sw    $zero, ($s0)
  addiu $t5, $t4, 1
  sw    $t5, ($v1)
.L700057B8:
  lw    $ra, 0x1c($sp)
.L700057BC:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

/**
 *     scroll stderr down one line
 *     accepts: A0=ypos
 */
asm(R"
glabel scroll_stderr_oneline
  slt   $v0, $zero, $a0
  beqz  $v0, .L70005854
   addiu $a0, $a0, -1
  lui   $t0, %hi(stderr_buffer + 0x899) 
  addiu $t0, %lo(stderr_buffer + 0x899) # addiu $t0, $t0, 0x3fb1
  li    $a3, 71
.L700057E4:
  lui   $t6, %hi(stderr_buffer)
  addiu $a2, $t6, %lo(stderr_buffer)
  move  $v1, $a2
.L700057F0:
  lbu   $t7, 0x47($a2)
  lbu   $t8, 0x48($a2)
  lbu   $t9, 0x49($a2)
  li    $v0, 3
  addiu $a1, $v1, 3
  sb    $t7, ($a2)
  sb    $t8, 1($a2)
  sb    $t9, 2($a2)
.L70005810:
  lbu   $t2, 0x48($a1)
  lbu   $t3, 0x49($a1)
  lbu   $t4, 0x4a($a1)
  lbu   $t1, 0x47($a1)
  addiu $v0, $v0, 4
  addiu $a1, $a1, 4
  sb    $t2, -3($a1)
  sb    $t3, -2($a1)
  sb    $t4, -1($a1)
  bne   $v0, $a3, .L70005810
   sb    $t1, -4($a1)
  addiu $a2, $a2, 0x47
  bne   $a2, $t0, .L700057F0
   addiu $v1, $v1, 0x47
  slt   $v0, $zero, $a0
  bnez  $v0, .L700057E4
   addiu $a0, $a0, -1
.L70005854:
  jr    $ra
   nop   
");

/**
 *     print char A2 to stderr screen position (A0,A1) in video buffer 1
 *     accepts: A0=xpos, A1=ypos, A2=char
 */
asm(R"
glabel print_to_vidbuff1
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  sw    $a1, 0x1c($sp)
  jal   get_video2_settings_txtClipW
   sw    $a2, 0x20($sp)
  lbu   $a1, 0x23($sp)
  bnezl $a1, .L70005888
   slti  $at, $a1, 0x20
  li    $a1, 32
  slti  $at, $a1, 0x20
.L70005888:
  bnez  $at, .L70005974
   slti  $at, $a1, 0x7f
  beqz  $at, .L70005974
   lw    $t6, 0x18($sp)
  lw    $t3, 0x1c($sp)
  lui   $t8, %hi(ptr_videobuffer1) 
  lw    $t8, %lo(ptr_videobuffer1)($t8)
  multu $t3, $v0
  sll   $t7, $t6, 1
  sll   $t6, $a1, 2
  lui   $a0, %hi(stderr_buffer+0x868)
  addu  $a0, $a0, $t6
  addu  $t9, $t7, $t8
  lw    $a0, %lo(stderr_buffer+0x868)($a0)
  lui   $a1, 0x8000
  move  $t0, $zero
  sll   $t1, $v0, 1
  mflo  $t4
  sll   $t5, $t4, 1
  addu  $v1, $t9, $t5
  li    $t2, 7
  li    $a3, 1
  li    $a2, 65535
.L700058E4:
  and   $t7, $a0, $a1
  beqz  $t7, .L700058F8
   sll   $t8, $a0, 1
  b     .L700058FC
   sh    $a2, ($v1)
.L700058F8:
  sh    $a3, ($v1)
.L700058FC:
  and   $t3, $t8, $a1
  addiu $v1, $v1, 2
  beqz  $t3, .L70005914
   move  $a0, $t8
  b     .L70005918
   sh    $a2, ($v1)
.L70005914:
  sh    $a3, ($v1)
.L70005918:
  sll   $t4, $a0, 1
  and   $t9, $t4, $a1
  move  $a0, $t4
  beqz  $t9, .L70005934
   addiu $v1, $v1, 2
  b     .L70005938
   sh    $a2, ($v1)
.L70005934:
  sh    $a3, ($v1)
.L70005938:
  sll   $t5, $a0, 1
  and   $t6, $t5, $a1
  move  $a0, $t5
  beqz  $t6, .L70005954
   addiu $v1, $v1, 2
  b     .L70005958
   sh    $a2, ($v1)
.L70005954:
  sh    $a3, ($v1)
.L70005958:
  addiu $v1, $v1, 2
  addiu $t0, $t0, 1
  sll   $t7, $a0, 1
  addu  $v1, $v1, $t1
  move  $a0, $t7
  bne   $t0, $t2, .L700058E4
   addiu $v1, $v1, -8
.L70005974:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

/**
 *     set pointers to video buffers 1 & 2 to A0 and A1, respectively
 *     sets values to uncached addresses
 *     A0 | A0000000 -> 8002417C
 *     A1 | A0000000 -> 80024180
 */
void set_ptr_video_buffers(int arg0, int arg1) {
  ptr_videobuffer1 = arg0 | 0xa0000000;
  ptr_videobuffer2 = arg1 | 0xa0000000;
}

/**
 *     set pointers to video buffers 1 & 2
 *     calls 70005984: A0=803B5000, A1=803DA800
 */
void set_video_buffer_pointers(void) {
  set_ptr_video_buffers(&cfb_16_a, &cfb_16_b);
}

/**
 *     write stderr to video buffer A0
 *     accepts: A0=p->video buffer
 */
asm(R"
glabel write_stderr_to_buffer
  addiu $sp, $sp, -0x40
  sw    $ra, 0x3c($sp)
  sw    $s0, 0x18($sp)
  move  $s0, $a0
  sw    $fp, 0x38($sp)
  sw    $s7, 0x34($sp)
  sw    $s6, 0x30($sp)
  sw    $s5, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  jal   set_video_buffer_pointers
   sw    $s1, 0x1c($sp)
  lui   $at, 0xa000
  or    $t6, $s0, $at
  lui   $at, %hi(ptr_videobuffer1)
  jal   get_video2_settings_txtClipW
   sw    $t6, %lo(ptr_videobuffer1)($at)
  addiu $s0, $v0, -0xd
  bgez  $s0, .L70005A2C
   sra   $t7, $s0, 2
  addiu $at, $s0, 3
  sra   $t7, $at, 2
.L70005A2C:
  jal   get_video2_settings_txtClipH
   move  $s0, $t7
  addiu $v1, $v0, -0xa
  li    $at, 7
  div   $zero, $v1, $at
  mflo  $v1
  addiu $fp, $v1, -1
  blez  $fp, .L70005AD8
   move  $s5, $zero
  addiu $s6, $s0, -5
  li    $s7, 31
  li    $s4, 304
.L70005A5C:
  blez  $s6, .L70005AC0
   sll   $s0, $zero, 2
  sll   $t9, $s5, 3
  addu  $t9, $t9, $s5
  sll   $t9, $t9, 3
  sll   $s2, $s5, 3
  lui   $t1, %hi(stderr_buffer) 
  addiu $t1, %lo(stderr_buffer) # addiu $t1, $t1, 0x3718
  subu  $s2, $s2, $s5
  subu  $t9, $t9, $s5
  sll   $s3, $s6, 2
  addiu $s3, $s3, 0x14
  addu  $s1, $t9, $t1
  addiu $s2, $s2, 7
  addiu $s0, $s0, 0x14
  move  $a0, $s0
.L70005A9C:
  move  $a1, $s2
  jal   print_to_vidbuff1
   lbu   $a2, ($s1)
  addiu $s0, $s0, 4
  slt   $at, $s0, $s3
  beqz  $at, .L70005AC0
   addiu $s1, $s1, 1
  bnel  $s0, $s4, .L70005A9C
   move  $a0, $s0
.L70005AC0:
  addiu $s5, $s5, 1
  slt   $at, $s5, $fp
  beql  $at, $zero, .L70005ADC
   lw    $ra, 0x3c($sp)
  bne   $s5, $s7, .L70005A5C
   nop   
.L70005AD8:
  lw    $ra, 0x3c($sp)
.L70005ADC:
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
   addiu $sp, $sp, 0x40
");
