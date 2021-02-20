#include "lvl.h"

extern unsigned int *ramrom_Dam_1;
extern unsigned int *ramrom_Dam_2;
extern unsigned int *ramrom_Facility_1;
extern unsigned int *ramrom_Facility_2;
extern unsigned int *ramrom_Facility_3;
extern unsigned int *ramrom_Runway_1;
extern unsigned int *ramrom_Runway_2;
extern unsigned int *ramrom_BunkerI_1;
extern unsigned int *ramrom_BunkerI_2;
extern unsigned int *ramrom_Silo_1;
extern unsigned int *ramrom_Silo_2;
extern unsigned int *ramrom_Frigate_1;
extern unsigned int *ramrom_Frigate_2;
extern unsigned int *ramrom_Train;

struct ramrom_struct ramrom_table[] = {
    {&ramrom_Dam_1, 0},      {&ramrom_Dam_2, 0},      {&ramrom_Facility_1, 0},
    {&ramrom_Facility_2, 0}, {&ramrom_Facility_3, 0}, {&ramrom_Runway_1, 0},
    {&ramrom_Runway_2, 0},   {&ramrom_BunkerI_1, 0},  {&ramrom_BunkerI_2, 0},
    {&ramrom_Silo_1, 0},     {&ramrom_Silo_2, 0},     {&ramrom_Frigate_1, 0},
    {&ramrom_Frigate_2, 0},  {&ramrom_Train, 0},      {0, 0}};

int ptr_active_demofile = 0;
int ramrom_blkbuf_2 = 0;
int ramrom_blkbuf_3 = 0;
int is_ramrom_flag = 0;
int ramrom_demo_related_3 = 0;
int ramrom_demo_related_4 = 0;
int recording_ramrom_flag = 0;
int ramrom_demo_related_6 = 0;
int flag_to_record_ramrom = 0;

const char aReplayDemo_D[] = "replay/demo.%d";
const char aReplayDemo_D_1[] = "replay/demo.%d";
const char aReplayDemo_load[] = "replay/demo.load";

void clear_ramrom_block_buffer_heading_ptrs(void) {
  ptr_active_demofile = 0;
  ramrom_blkbuf_2 = 0;
  ramrom_blkbuf_3 = 0;
}

int get_is_ramrom_flag(void) { return is_ramrom_flag; }

int get_recording_ramrom_flag(void) { return recording_ramrom_flag; }

int interface_menu0B_runstage(void) { return ramrom_demo_related_4; }

asm(R"
glabel finalize_ramrom_on_hw
  addiu $sp, $sp, -0x48
  move  $a0, $sp
  addiu $a0, $a0, 0x2f
  ori   $t6, $a0, 0xf
  sw    $ra, 0x14($sp)
  xori  $a0, $t6, 0xf
  sb    $zero, ($a0)
  sb    $zero, 1($a0)
  lui   $a1, %hi(address_demo_loaded)
  lw    $a1, %lo(address_demo_loaded)($a1)
  jal   romWrite
   li    $a2, 16
  lui   $v0, %hi(address_demo_loaded)
  addiu $v0, %lo(address_demo_loaded) # addiu $v0, $v0, -0x3a0c
  lw    $t8, ($v0)
  lui   $a0, %hi(ramrom_data_target)
  addiu $a0, %lo(ramrom_data_target) # addiu $a0, $a0, -0x3d90
  addiu $t9, $t8, 4
  sw    $t9, ($v0)
  lui   $a1, 0xf0
  jal   romCopyAligned
   li    $a2, 240
  lui   $v1, %hi(ptr_active_demofile)
  addiu $v1, %lo(ptr_active_demofile) # addiu $v1, $v1, -0x7b98
  sw    $v0, ($v1)
  lui   $t0, %hi(global_timer) 
  lui   $t1, %hi(clock_timer) 
  lw    $t1, %lo(clock_timer)($t1)
  lw    $t0, %lo(global_timer)($t0)
  lui   $t4, %hi(address_demo_loaded) 
  lui   $a1, 0xf0
  subu  $t2, $t0, $t1
  sw    $t2, 0x7c($v0)
  lw    $t4, %lo(address_demo_loaded)($t4)
  lw    $t6, ($v1)
  li    $a2, 240
  subu  $t5, $t4, $a1
  sw    $t5, 0x80($t6)
  jal   romWrite
   lw    $a0, ($v1)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x48
  jr    $ra
   nop   
");

asm(R"
glabel save_ramrom_to_devtool
  addiu $sp, $sp, -0x130
  sw    $s2, 0x1c($sp)
  sw    $s3, 0x20($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  lui   $s2, %hi(aReplayDemo_D)
  sw    $ra, 0x24($sp)
  addiu $s2, %lo(aReplayDemo_D) # addiu $s2, $s2, -0x48b0
  li    $s0, 1
  addiu $s1, $sp, 0x2c
  addiu $s3, $sp, 0x28
.L7F0BFD8C:
  move  $a0, $s1
  move  $a1, $s2
  jal   sprintf
   move  $a2, $s0
  move  $a0, $s1
  jal   check_file_found_on_indy
   move  $a1, $s3
  beqz  $v0, .L7F0BFDB8
   nop   
  b     .L7F0BFD8C
   addiu $s0, $s0, 1
.L7F0BFDB8:
  lui   $a1, %hi(aReplayDemo_D_1)
  addiu $a1, %lo(aReplayDemo_D_1) # addiu $a1, $a1, -0x48a0
  move  $a0, $s1
  jal   sprintf
   move  $a2, $s0
  lui   $t6, %hi(ptr_active_demofile) 
  lw    $t6, %lo(ptr_active_demofile)($t6)
  move  $a0, $s1
  lui   $a1, 0xf0
  jal   check_file_exported
   lw    $a2, 0x80($t6)
  lw    $ra, 0x24($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x130
");

asm(R"
glabel load_ramrom_from_devtool
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  lui   $a0, %hi(aReplayDemo_load)
  addiu $a0, %lo(aReplayDemo_load) # addiu $a0, $a0, -0x4890
  jal   check_file_found_on_indy
   addiu $a1, $sp, 0x1c
  beqz  $v0, .L7F0BFE4C
   lui   $a0, %hi(aReplayDemo_load)
  addiu $a0, %lo(aReplayDemo_load) # addiu $a0, $a0, -0x4890
  lui   $a1, 0xf0
  jal   indy_loadfile
   lw    $a2, 0x1c($sp)
  lui   $a0, %hi(ramrom_data_target)
  addiu $a0, %lo(ramrom_data_target) # addiu $a0, $a0, -0x3d90
  lui   $a1, 0xf0
  jal   romCopyAligned
   li    $a2, 232
  lui   $at, %hi(ptr_active_demofile)
  sw    $v0, %lo(ptr_active_demofile)($at)
.L7F0BFE4C:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel record_player_input_as_packet
  addiu $sp, $sp, -0x20
  lui   $t6, %hi(ptr_active_demofile) 
  lui   $t7, %hi(ramrom_data_target + 0x1F8) 
  lw    $t6, %lo(ptr_active_demofile)($t6)
  addiu $t7, %lo(ramrom_data_target + 0x1F8) # addiu $t7, $t7, -0x3b98
  addiu $t8, $t7, 0xf
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  ori   $t9, $t8, 0xf
  lui   $t0, %hi(ramrom_blkbuf_3) 
  lui   $t4, %hi(ramrom_blkbuf_2) 
  xori  $t5, $t9, 0xf
  lw    $t1, 0x18($t6)
  addiu $t4, %lo(ramrom_blkbuf_2) # addiu $t4, $t4, -0x7b94
  addiu $t0, %lo(ramrom_blkbuf_3) # addiu $t0, $t0, -0x7b90
  addiu $t6, $t5, 4
  move  $s0, $a2
  move  $s1, $a0
  move  $t2, $zero
  move  $a3, $zero
  sw    $t5, ($t4)
  sw    $t6, ($t0)
  beq   $a1, $a2, .L7F0BFFDC
   move  $v0, $t5
  li    $t3, 20
  addiu $t7, $a1, 1
  div   $zero, $t7, $t3
  mfhi  $a2
  move  $a0, $zero
  bnez  $t3, .L7F0BFEE0
   nop   
  break 7
.L7F0BFEE0:
  li    $at, -1
  bne   $t3, $at, .L7F0BFEF8
   lui   $at, 0x8000
  bne   $t7, $at, .L7F0BFEF8
   nop   
  break 6
.L7F0BFEF8:
  blez  $t1, .L7F0BFF90
   nop   
  multu $t2, $t1
  sll   $t9, $a2, 2
  sll   $t5, $t9, 2
  subu  $t5, $t5, $t9
  sll   $t5, $t5, 1
  addu  $v1, $s1, $t5
  mflo  $a1
  sll   $t8, $a1, 2
  move  $a1, $t8
.L7F0BFF24:
  lw    $t6, ($t0)
  lb    $t9, 2($v1)
  sll   $t8, $a0, 2
  addu  $t7, $a1, $t6
  addu  $v0, $t7, $t8
  sb    $t9, ($v0)
  lb    $t5, 3($v1)
  addiu $a0, $a0, 1
  addiu $v1, $v1, 6
  sb    $t5, 1($v0)
  lhu   $t7, -6($v1)
  lbu   $t6, 1($v0)
  lbu   $t5, ($v0)
  sb    $t7, 2($v0)
  lhu   $t8, -6($v1)
  addu  $t7, $t5, $t6
  sra   $t9, $t8, 8
  lbu   $t8, 2($v0)
  sb    $t9, 3($v0)
  lbu   $t5, 3($v0)
  addu  $t9, $t7, $t8
  addu  $t6, $t9, $t5
  andi  $t7, $t6, 0xff
  addu  $a3, $a3, $t7
  andi  $t8, $a3, 0xff
  bne   $a0, $t1, .L7F0BFF24
   move  $a3, $t8
.L7F0BFF90:
  bne   $a2, $s0, .L7F0BFFA0
   addiu $t2, $t2, 1
  b     .L7F0BFFDC
   lw    $v0, ($t4)
.L7F0BFFA0:
  addiu $t9, $a2, 1
  div   $zero, $t9, $t3
  mfhi  $a2
  move  $a0, $zero
  bnez  $t3, .L7F0BFFBC
   nop   
  break 7
.L7F0BFFBC:
  li    $at, -1
  bne   $t3, $at, .L7F0BFFD4
   lui   $at, 0x8000
  bne   $t9, $at, .L7F0BFFD4
   nop   
  break 6
.L7F0BFFD4:
  b     .L7F0BFEF8
   nop   
.L7F0BFFDC:
  sb    $t2, 1($v0)
  lui   $t5, %hi(D_80048498) 
  lw    $t5, %lo(D_80048498)($t5)
  lw    $t6, ($t4)
  lui   $t9, %hi(randseed + 0x4) 
  lui   $s1, %hi(address_demo_loaded)
  sb    $t5, ($t6)
  lw    $t5, ($t4)
  lw    $t9, %lo(randseed + 0x4)($t9)
  addiu $s1, %lo(address_demo_loaded) # addiu $s1, $s1, -0x3a0c
  sb    $t9, 2($t5)
  lw    $v0, ($t4)
  lbu   $t6, ($v0)
  lbu   $t8, 1($v0)
  lbu   $t7, 2($v0)
  addu  $t9, $t6, $t8
  addu  $t6, $t9, $t7
  sll   $t9, $t1, 2
  multu $t9, $t2
  addu  $t8, $a3, $t6
  sb    $t8, 3($v0)
  lw    $a1, ($s1)
  lw    $a0, ($t4)
  mflo  $s0
  addiu $s0, $s0, 4
  addiu $a2, $s0, 0xf
  ori   $t7, $a2, 0xf
  jal   romWrite
   xori  $a2, $t7, 0xf
  lw    $t6, ($s1)
  addiu $t8, $s0, 1
  lw    $ra, 0x1c($sp)
  ori   $t9, $t8, 1
  xori  $t7, $t9, 1
  lui   $at, %hi(address_demo_loaded)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  addu  $t5, $t6, $t7
  sw    $t5, %lo(address_demo_loaded)($at)
  jr    $ra
   addiu $sp, $sp, 0x20
");

asm(R"
glabel ramrom_replay_handler
  addiu $sp, $sp, -0x38
  lui   $v0, %hi(ramrom_blkbuf_2)
  lw    $v0, %lo(ramrom_blkbuf_2)($v0)
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  lbu   $t2, 1($v0)
  lui   $t6, %hi(ptr_active_demofile) 
  lw    $t6, %lo(ptr_active_demofile)($t6)
  move  $s0, $a1
  move  $s1, $a0
  move  $t0, $zero
  move  $a3, $zero
  blez  $t2, .L7F0C01BC
   lw    $a2, 0x18($t6)
  lui   $a1, %hi(ramrom_blkbuf_3)
  addiu $a1, %lo(ramrom_blkbuf_3) # addiu $a1, $a1, -0x7b90
  li    $t3, 20
  li    $t1, 4
  addiu $t7, $s0, 1
.L7F0C00D0:
  div   $zero, $t7, $t3
  mfhi  $s0
  sll   $t8, $s0, 2
  sll   $t9, $t8, 2
  subu  $t9, $t9, $t8
  sll   $t9, $t9, 1
  bnez  $t3, .L7F0C00F4
   nop   
  break 7
.L7F0C00F4:
  li    $at, -1
  bne   $t3, $at, .L7F0C010C
   lui   $at, 0x8000
  bne   $t7, $at, .L7F0C010C
   nop   
  break 6
.L7F0C010C:
  addu  $v1, $s1, $t9
  move  $a0, $zero
.L7F0C0114:
  slt   $at, $a0, $a2
  beql  $at, $zero, .L7F0C0194
   sb    $zero, 2($v1)
  multu $a3, $a2
  lw    $t6, ($a1)
  sll   $t8, $a0, 2
  mflo  $t4
  sll   $t5, $t4, 2
  addu  $t7, $t5, $t6
  addu  $v0, $t7, $t8
  lb    $t9, ($v0)
  sb    $t9, 2($v1)
  lb    $t4, 1($v0)
  sb    $t4, 3($v1)
  lbu   $t5, 3($v0)
  lbu   $t7, 2($v0)
  sll   $t6, $t5, 8
  or    $t8, $t6, $t7
  sh    $t8, ($v1)
  lbu   $t4, 1($v0)
  lbu   $t9, ($v0)
  lbu   $t6, 2($v0)
  lbu   $t8, 3($v0)
  addu  $t5, $t9, $t4
  addu  $t7, $t5, $t6
  addu  $t9, $t7, $t8
  andi  $t4, $t9, 0xff
  addu  $t0, $t0, $t4
  andi  $t5, $t0, 0xff
  b     .L7F0C019C
   move  $t0, $t5
  sb    $zero, 2($v1)
.L7F0C0194:
  sb    $zero, 3($v1)
  sh    $zero, ($v1)
.L7F0C019C:
  addiu $a0, $a0, 1
  bne   $a0, $t1, .L7F0C0114
   addiu $v1, $v1, 6
  addiu $a3, $a3, 1
  bnel  $a3, $t2, .L7F0C00D0
   addiu $t7, $s0, 1
  lui   $v0, %hi(ramrom_blkbuf_2)
  lw    $v0, %lo(ramrom_blkbuf_2)($v0)
.L7F0C01BC:
  lui   $t7, %hi(randseed + 0x4) 
  lw    $t7, %lo(randseed + 0x4)($t7)
  lbu   $v1, 2($v0)
  andi  $t9, $t7, 0xff
  beql  $t9, $v1, .L7F0C01F0
   lbu   $t4, ($v0)
  jal   ensureCameraModeA
   sb    $t0, 0x23($sp)
  lui   $v0, %hi(ramrom_blkbuf_2)
  lw    $v0, %lo(ramrom_blkbuf_2)($v0)
  lbu   $t0, 0x23($sp)
  lbu   $v1, 2($v0)
  lbu   $t4, ($v0)
.L7F0C01F0:
  lbu   $t5, 1($v0)
  addu  $t6, $t4, $t5
  lbu   $t4, 3($v0)
  addu  $t8, $t6, $v1
  addu  $t0, $t0, $t8
  andi  $t9, $t0, 0xff
  beq   $t9, $t4, .L7F0C0218
   nop   
  jal   ensureCameraModeA
   nop   
.L7F0C0218:
  jal   controller_7000C930
   move  $a0, $zero
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 65535
  beqz  $v0, .L7F0C0248
   nop   
  jal   ensureCameraModeA
   nop   
  li    $t5, 1
  lui   $at, %hi(prev_keypresses)
  sw    $t5, %lo(prev_keypresses)($at)
.L7F0C0248:
  jal   controller_7000C930
   li    $a0, 1
  lw    $ra, 0x1c($sp)
  move  $v0, $s0
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x38
");

asm(R"
glabel iterate_ramrom_entries_handle_camera_out
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lui   $a0, %hi(ramrom_data_target + 0x1F8)
  lui   $a1, %hi(address_demo_loaded)
  lw    $a1, %lo(address_demo_loaded)($a1)
  addiu $a0, %lo(ramrom_data_target + 0x1F8) # addiu $a0, $a0, -0x3b98
  jal   romCopyAligned
   li    $a2, 4
  lui   $a1, %hi(ramrom_blkbuf_2)
  addiu $a1, %lo(ramrom_blkbuf_2) # addiu $a1, $a1, -0x7b94
  sw    $v0, ($a1)
  lbu   $a3, 1($v0)
  move  $v1, $v0
  lui   $t6, %hi(ptr_active_demofile) 
  blez  $a3, .L7F0C02F0
   move  $a0, $a3
  lw    $t6, %lo(ptr_active_demofile)($t6)
  lui   $a1, %hi(address_demo_loaded)
  lw    $a1, %lo(address_demo_loaded)($a1)
  lw    $t7, 0x18($t6)
  lui   $a0, %hi(ramrom_data_target + 0x21E)
  addiu $a0, %lo(ramrom_data_target + 0x21E) # addiu $a0, $a0, -0x3b72
  sll   $t8, $t7, 2
  multu $t8, $a3
  addiu $a1, $a1, 4
  mflo  $a2
  jal   romCopyAligned
   nop   
  lui   $v1, %hi(ramrom_blkbuf_2)
  lw    $v1, %lo(ramrom_blkbuf_2)($v1)
  lui   $at, %hi(ramrom_blkbuf_3)
  sw    $v0, %lo(ramrom_blkbuf_3)($at)
  lbu   $a3, 1($v1)
  move  $a0, $a3
.L7F0C02F0:
  bnez  $a0, .L7F0C0318
   lui   $t1, %hi(ptr_active_demofile) 
  lbu   $t9, ($v1)
  bnez  $t9, .L7F0C0318
   nop   
  jal   ensureCameraModeA
   nop   
  lui   $v1, %hi(ramrom_blkbuf_2)
  b     .L7F0C034C
   lw    $v1, %lo(ramrom_blkbuf_2)($v1)
.L7F0C0318:
  lw    $t1, %lo(ptr_active_demofile)($t1)
  lui   $t0, %hi(address_demo_loaded) 
  lw    $t0, %lo(address_demo_loaded)($t0)
  lw    $t2, 0x18($t1)
  lui   $at, %hi(address_demo_loaded)
  sll   $t3, $t2, 2
  multu $t3, $a3
  mflo  $t4
  addiu $t5, $t4, 5
  ori   $t6, $t5, 1
  xori  $t7, $t6, 1
  addu  $t8, $t0, $t7
  sw    $t8, %lo(address_demo_loaded)($at)
.L7F0C034C:
  jal   set_cpu_cycle_count
   lbu   $a0, ($v1)
  lui   $t9, %hi(ptr_active_demofile) 
  lw    $t9, %lo(ptr_active_demofile)($t9)
  lui   $v0, %hi(global_timer)
  lw    $v0, %lo(global_timer)($v0)
  lw    $v1, 0x7c($t9)
  lui   $t1, %hi(clock_timer) 
  addiu $v1, $v1, -0x3c
  slt   $at, $v0, $v1
  bnezl $at, .L7F0C039C
   lw    $ra, 0x14($sp)
  lw    $t1, %lo(clock_timer)($t1)
  subu  $t2, $v0, $t1
  slt   $at, $t2, $v1
  beql  $at, $zero, .L7F0C039C
   lw    $ra, 0x14($sp)
  jal   ensureCameraModeA
   nop   
  lw    $ra, 0x14($sp)
.L7F0C039C:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel copy_current_ingame_registers_before_ramrom_playback
  addiu $sp, $sp, -0x20
  lui   $t6, %hi(randseed) 
  lui   $t7, %hi(randseed + 0x4) 
  lw    $t7, %lo(randseed + 0x4)($t7)
  lw    $t6, %lo(randseed)($t6)
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $t7, 4($a0)
  sw    $t6, ($a0)
  lui   $t8, %hi(random_val) 
  lui   $t9, %hi(random_val + 0x4) 
  lw    $t9, %lo(random_val + 0x4)($t9)
  lw    $t8, %lo(random_val)($t8)
  lui   $t0, %hi(gamemode) 
  sw    $t9, 0xc($a0)
  sw    $t8, 8($a0)
  lw    $t0, %lo(gamemode)($t0)
  lui   $t1, %hi(selected_num_players) 
  lui   $t2, %hi(scenario) 
  sw    $t0, 0x84($a0)
  lw    $t1, %lo(selected_num_players)($t1)
  lui   $t3, %hi(MP_stage_selected) 
  lui   $t4, %hi(game_length) 
  sw    $t1, 0x8c($a0)
  lw    $t2, %lo(scenario)($t2)
  move  $s0, $a0
  sw    $t2, 0x90($a0)
  lw    $t3, %lo(MP_stage_selected)($t3)
  sw    $t3, 0x94($a0)
  lw    $t4, %lo(game_length)($t4)
  jal   get_mp_weapon_set
   sw    $t4, 0x98($a0)
  lui   $v1, %hi(player_1_char)
  addiu $v1, %lo(player_1_char) # addiu $v1, $v1, -0x4adc
  sw    $v0, 0x9c($s0)
  lw    $t5, ($v1)
  lui   $a1, %hi(handicap_player1)
  addiu $a1, %lo(handicap_player1) # addiu $a1, $a1, -0x6858
  sw    $t5, 0xa0($s0)
  lw    $t6, 4($v1)
  lui   $a2, %hi(controlstyle_player)
  addiu $a2, %lo(controlstyle_player) # addiu $a2, $a2, -0x6848
  sw    $t6, 0xa4($s0)
  lw    $t7, 8($v1)
  move  $a0, $zero
  sw    $t7, 0xa8($s0)
  lw    $t8, 0xc($v1)
  lui   $t7, %hi(aim_sight_adjustment) 
  sw    $t8, 0xac($s0)
  lw    $t9, ($a1)
  sw    $t9, 0xb0($s0)
  lw    $t0, 4($a1)
  sw    $t0, 0xb4($s0)
  lw    $t1, 8($a1)
  sw    $t1, 0xb8($s0)
  lw    $t2, 0xc($a1)
  sw    $t2, 0xbc($s0)
  lw    $t3, ($a2)
  sw    $t3, 0xc0($s0)
  lw    $t4, 4($a2)
  sw    $t4, 0xc4($s0)
  lw    $t5, 8($a2)
  sw    $t5, 0xc8($s0)
  lw    $t6, 0xc($a2)
  sw    $t6, 0xcc($s0)
  lw    $t7, %lo(aim_sight_adjustment)($t7)
  jal   get_players_team_or_scenario_item_flag
   sw    $t7, 0xd0($s0)
  sw    $v0, 0xd4($s0)
  jal   get_players_team_or_scenario_item_flag
   li    $a0, 1
  sw    $v0, 0xd8($s0)
  jal   get_players_team_or_scenario_item_flag
   li    $a0, 2
  sw    $v0, 0xdc($s0)
  jal   get_players_team_or_scenario_item_flag
   li    $a0, 3
  sw    $v0, 0xe0($s0)
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel copy_recorded_ramrom_registers_to_proper_place_ingame
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  lw    $t6, ($a0)
  lw    $t7, 4($a0)
  lui   $at, %hi(randseed)
  sw    $t6, %lo(randseed)($at)
  lui   $at, %hi(randseed + 0x4)
  sw    $t7, %lo(randseed + 0x4)($at)
  lw    $t8, 8($a0)
  lw    $t9, 0xc($a0)
  lui   $at, %hi(random_val)
  sw    $t8, %lo(random_val)($at)
  lui   $at, %hi(random_val + 0x4)
  sw    $t9, %lo(random_val + 0x4)($at)
  lw    $t0, 0x84($a0)
  lui   $at, %hi(gamemode)
  move  $s0, $a0
  sw    $t0, %lo(gamemode)($at)
  lw    $t1, 0x8c($a0)
  lui   $at, %hi(selected_num_players)
  sw    $t1, %lo(selected_num_players)($at)
  lw    $t2, 0x90($a0)
  lui   $at, %hi(scenario)
  sw    $t2, %lo(scenario)($at)
  lw    $t3, 0x94($a0)
  lui   $at, %hi(MP_stage_selected)
  sw    $t3, %lo(MP_stage_selected)($at)
  lw    $t4, 0x98($a0)
  lui   $at, %hi(game_length)
  sw    $t4, %lo(game_length)($at)
  jal   set_mp_weapon_set
   lw    $a0, 0x9c($a0)
  lw    $t5, 0xa0($s0)
  lui   $v0, %hi(player_1_char)
  addiu $v0, %lo(player_1_char) # addiu $v0, $v0, -0x4adc
  sw    $t5, ($v0)
  lw    $t6, 0xa4($s0)
  lui   $v1, %hi(handicap_player1)
  addiu $v1, %lo(handicap_player1) # addiu $v1, $v1, -0x6858
  sw    $t6, 4($v0)
  lw    $t7, 0xa8($s0)
  lui   $a2, %hi(controlstyle_player)
  addiu $a2, %lo(controlstyle_player) # addiu $a2, $a2, -0x6848
  sw    $t7, 8($v0)
  lw    $t8, 0xac($s0)
  lui   $at, %hi(aim_sight_adjustment)
  move  $a0, $zero
  sw    $t8, 0xc($v0)
  lw    $t9, 0xb0($s0)
  sw    $t9, ($v1)
  lw    $t0, 0xb4($s0)
  sw    $t0, 4($v1)
  lw    $t1, 0xb8($s0)
  sw    $t1, 8($v1)
  lw    $t2, 0xbc($s0)
  sw    $t2, 0xc($v1)
  lw    $t3, 0xc0($s0)
  sw    $t3, ($a2)
  lw    $t4, 0xc4($s0)
  sw    $t4, 4($a2)
  lw    $t5, 0xc8($s0)
  sw    $t5, 8($a2)
  lw    $t6, 0xcc($s0)
  sw    $t6, 0xc($a2)
  lw    $t7, 0xd0($s0)
  sw    $t7, %lo(aim_sight_adjustment)($at)
  jal   set_players_team_or_scenario_item_flag
   lw    $a1, 0xd4($s0)
  li    $a0, 1
  jal   set_players_team_or_scenario_item_flag
   lw    $a1, 0xd8($s0)
  li    $a0, 2
  jal   set_players_team_or_scenario_item_flag
   lw    $a1, 0xdc($s0)
  li    $a0, 3
  jal   set_players_team_or_scenario_item_flag
   lw    $a1, 0xe0($s0)
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel test_if_recording_demos_this_stage_load
  lui   $t6, %hi(flag_to_record_ramrom) 
  lw    $t6, %lo(flag_to_record_ramrom)($t6)
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  beqz  $t6, .L7F0C071C
   sw    $s0, 0x18($sp)
  lui   $t7, %hi(ramrom_data_target) 
  addiu $t7, %lo(ramrom_data_target) # addiu $t7, $t7, -0x3d90
  addiu $t8, $t7, 0xf
  lui   $s0, %hi(ptr_active_demofile)
  ori   $t9, $t8, 0xf
  addiu $s0, %lo(ptr_active_demofile) # addiu $s0, $s0, -0x7b98
  xori  $t0, $t9, 0xf
  sw    $t0, ($s0)
  lui   $at, %hi(dword_CODE_bss_8008C5F8)
  sw    $zero, %lo(dword_CODE_bss_8008C5F8)($at)
  lw    $t1, ($s0)
  sw    $a0, 0x10($t1)
  lw    $t2, ($s0)
  jal   get_attached_controller_count
   sw    $a1, 0x14($t2)
  lw    $t3, ($s0)
  lui   $t4, %hi(record_slot_num) 
  sw    $v0, 0x18($t3)
  lw    $t5, ($s0)
  lw    $t4, %lo(record_slot_num)($t4)
  sw    $t4, 0x88($t5)
  lw    $a0, ($s0)
  jal   sub_GAME_7F01D61C
   addiu $a0, $a0, 0x1c
  jal   copy_current_ingame_registers_before_ramrom_playback
   lw    $a0, ($s0)
  li    $v0, 1
  lui   $at, %hi(recording_ramrom_flag)
  sw    $v0, %lo(recording_ramrom_flag)($at)
  lui   $at, %hi(ramrom_demo_related_6)
  lui   $a0, %hi(record_player_input_as_packet) # $a0, 0x7f0c
  sw    $v0, %lo(ramrom_demo_related_6)($at)
  jal   set_ptr_tlb_ramrom_record
   addiu $a0, %lo(record_player_input_as_packet) # addiu $a0, $a0, -0x1a4
  lui   $v0, %hi(address_demo_loaded)
  addiu $v0, %lo(address_demo_loaded) # addiu $v0, $v0, -0x3a0c
  lui   $a1, 0xf0
  sw    $a1, ($v0)
  lw    $a0, ($s0)
  jal   romWrite
   li    $a2, 240
  lui   $v0, %hi(address_demo_loaded)
  addiu $v0, %lo(address_demo_loaded) # addiu $v0, $v0, -0x3a0c
  lw    $t7, ($v0)
  lui   $at, %hi(flag_to_record_ramrom)
  addiu $t8, $t7, 0xe8
  sw    $t8, ($v0)
  b     .L7F0C07A8
   sw    $zero, %lo(flag_to_record_ramrom)($at)
.L7F0C071C:
  lui   $t9, %hi(ramrom_demo_related_4) 
  lw    $t9, %lo(ramrom_demo_related_4)($t9)
  beqz  $t9, .L7F0C07A8
   lui   $s0, %hi(ptr_active_demofile)
  lui   $at, %hi(dword_CODE_bss_8008C5F8)
  addiu $s0, %lo(ptr_active_demofile) # addiu $s0, $s0, -0x7b98
  sw    $zero, %lo(dword_CODE_bss_8008C5F8)($at)
  lw    $t0, ($s0)
  jal   set_selected_difficulty
   lw    $a0, 0x14($t0)
  lw    $t1, ($s0)
  jal   set_solo_and_ptr_briefing
   lw    $a0, 0x10($t1)
  lw    $a0, ($s0)
  jal   sub_GAME_7F01D644
   addiu $a0, $a0, 0x1c
  lui   $a0, %hi(ramrom_data_target + 0x110)
  jal   copy_current_ingame_registers_before_ramrom_playback
   addiu $a0, %lo(ramrom_data_target + 0x110) # addiu $a0, $a0, -0x3c80
  jal   copy_recorded_ramrom_registers_to_proper_place_ingame
   lw    $a0, ($s0)
  li    $v0, 1
  lui   $at, %hi(is_ramrom_flag)
  sw    $v0, %lo(is_ramrom_flag)($at)
  lui   $at, %hi(ramrom_demo_related_3)
  sw    $v0, %lo(ramrom_demo_related_3)($at)
  lw    $t2, ($s0)
  lui   $a0, %hi(ramrom_replay_handler) # $a0, 0x7f0c
  addiu $a0, %lo(ramrom_replay_handler) # addiu $a0, $a0, 0x80
  jal   set_disable_all_rumble_and_something
   lw    $a1, 0x18($t2)
  jal   controller_7000C930
   li    $a0, 1
  lui   $at, %hi(ramrom_demo_related_4)
  sw    $zero, %lo(ramrom_demo_related_4)($at)
.L7F0C07A8:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

void setRamRomRecordSlot(int arg0) {
  flag_to_record_ramrom = 1;
  record_slot_num = arg0;
}

void stop_recording_ramrom(void) {
  if (ramrom_demo_related_6 != 0) {
    finalize_ramrom_on_hw();
    set_ptr_tlb_ramrom_record(0);
    ramrom_demo_related_6 = 0;
    recording_ramrom_flag = 0;
  }
}

asm(R"
glabel replay_recorded_ramrom_at_address
  lui   $v1, %hi(address_demo_loaded)
  addiu $v1, %lo(address_demo_loaded) # addiu $v1, $v1, -0x3a0c
  addiu $sp, $sp, -0x18
  sw    $a0, ($v1)
  sw    $ra, 0x14($sp)
  lui   $a0, %hi(ramrom_data_target)
  addiu $a0, %lo(ramrom_data_target) # addiu $a0, $a0, -0x3d90
  lw    $a1, ($v1)
  jal   romCopyAligned
   li    $a2, 232
  lui   $v1, %hi(address_demo_loaded)
  addiu $v1, %lo(address_demo_loaded) # addiu $v1, $v1, -0x3a0c
  lw    $t6, ($v1)
  lui   $a1, %hi(ptr_active_demofile)
  addiu $a1, %lo(ptr_active_demofile) # addiu $a1, $a1, -0x7b98
  addiu $t7, $t6, 0xe8
  sw    $v0, ($a1)
  sw    $t7, ($v1)
  li    $t8, 1
  lui   $at, %hi(ramrom_demo_related_4)
  sw    $t8, %lo(ramrom_demo_related_4)($at)
  lw    $t9, ($a1)
  jal   set_solo_and_ptr_briefing
   lw    $a0, 0x10($t9)
  lui   $t0, %hi(ptr_active_demofile) 
  lw    $t0, %lo(ptr_active_demofile)($t0)
  jal   set_selected_difficulty
   lw    $a0, 0x14($t0)
  li    $a0, 11
  jal   set_menu_to_mode
   li    $a1, 1
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

void replay_recorded_ramrom_from_indy(void) {
  replay_recorded_ramrom_at_address(0xf00000);
}

void ensureCameraModeA(void) {
  if (get_camera_mode() != 0xa)
    set_camera_mode(0xa);
}

asm(R"
glabel stop_demo_playback
  lui   $t6, %hi(ramrom_demo_related_6) 
  lw    $t6, %lo(ramrom_demo_related_6)($t6)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  beqz  $t6, .L7F0C0924
   lui   $t7, %hi(ramrom_demo_related_3) 
  jal   stop_recording_ramrom
   nop   
  b     .L7F0C0964
   lw    $ra, 0x14($sp)
.L7F0C0924:
  lw    $t7, %lo(ramrom_demo_related_3)($t7)
  lui   $a0, %hi(ramrom_data_target + 0x110)
  beql  $t7, $zero, .L7F0C0964
   lw    $ra, 0x14($sp)
  jal   copy_recorded_ramrom_registers_to_proper_place_ingame
   addiu $a0, %lo(ramrom_data_target + 0x110) # addiu $a0, $a0, -0x3c80
  move  $a0, $zero
  jal   set_disable_all_rumble_and_something
   li    $a1, -1
  jal   controller_7000C930
   move  $a0, $zero
  lui   $at, %hi(ramrom_demo_related_3)
  sw    $zero, %lo(ramrom_demo_related_3)($at)
  lui   $at, %hi(is_ramrom_flag)
  sw    $zero, %lo(is_ramrom_flag)($at)
  lw    $ra, 0x14($sp)
.L7F0C0964:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel select_ramrom_to_play
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  jal   check_egypt_completed_any_folder
   nop   
  lui   $t6, %hi(ramrom_table) 
  lw    $t6, %lo(ramrom_table)($t6)
  move  $a0, $v0
  move  $v1, $zero
  beqz  $t6, .L7F0C09D8
   lui   $t7, %hi(ramrom_table + 0x4) 
  lw    $t7, %lo(ramrom_table + 0x4)($t7)
  lui   $t9, %hi(ramrom_table) 
  addiu $t9, %lo(ramrom_table) # addiu $t9, $t9, -0x7c10
  slt   $at, $v0, $t7
  bnez  $at, .L7F0C09D8
   sll   $t8, $v1, 3
  addu  $v0, $t8, $t9
  lw    $t0, 8($v0)
.L7F0C09B8:
  addiu $v1, $v1, 1
  addiu $v0, $v0, 8
  beqz  $t0, .L7F0C09D8
   nop   
  lw    $t1, 4($v0)
  slt   $at, $a0, $t1
  beql  $at, $zero, .L7F0C09B8
   lw    $t0, 8($v0)
.L7F0C09D8:
  jal   get_random_value
   sw    $v1, 0x1c($sp)
  lw    $v1, 0x1c($sp)
  lui   $a0, %hi(ramrom_table)
  divu  $zero, $v0, $v1
  mfhi  $t2
  sll   $t3, $t2, 3
  addu  $a0, $a0, $t3
  bnez  $v1, .L7F0C0A04
   nop   
  break 7
.L7F0C0A04:
  lw    $a0, %lo(ramrom_table)($a0)
  jal   replay_recorded_ramrom_at_address
   nop   
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

int check_ramrom_flags(void) {
  if (get_is_ramrom_flag() != 0) {
    goto block_2;
  }
  if (get_recording_ramrom_flag()) {
  block_2:
    return *(int *)(ptr_active_demofile + 136);
  }
  return 0;
}
