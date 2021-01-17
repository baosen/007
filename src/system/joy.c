#include <message.h>
#include <thread.h>

const char aJoy_c_debug[] = "joy_c_debug";

char controller_input_index[0x1E0];
int dword_CODE_bss_80065110;
int dword_CODE_bss_80065114;
int dword_CODE_bss_80065118;
int dword_CODE_bss_8006511C;
int dword_CODE_bss_80065120;
int dword_CODE_bss_80065124;
int dword_CODE_bss_80065128;
int dword_CODE_bss_8006512C;
int dword_code_bss_80065130[0x76];
int dword_CODE_bss_80065308;
int dword_CODE_bss_8006530C;
int dword_CODE_bss_80065310;
int dword_CODE_bss_80065314;
int dword_CODE_bss_80065318;
int dword_CODE_bss_8006531C;
int dword_CODE_bss_80065320;
int dword_CODE_bss_80065324;

char contdemoMesg[0x28];

OSMesgQueue contdemoMesgMQ;

OSMesg cont1Mesg;
OSMesgQueue controller1_message_queue;

OSMesg cont2Mesg;
OSMesgQueue controller2_message_queue;

OSMesg cont3Mesg;
OSMesgQueue controller3_message_queue;

OSMesg cont4Mesg;
OSMesgQueue controller4_message_queue;

int player1_controllerstatus, player2_controllerstatus,
    player3_controllerstatus, player4_controllerstatus;

char player1_controller_packet[0x1A8];

int D_800268C0 = 0;
char *ptr_current_point_in_controller_input_index = controller_input_index;
int D_800268C8 = 0;
int D_800268CC = 0;

unsigned char num_controller_plugged_in_flags = 0;
int num_controller_plugged_in_flags_0 = 0;

int controller_1_rumble_inserted = 0;
int controller_2_rumble_inserted = 0;
int controller_3_rumble_inserted = 0;
int controller_4_rumble_inserted = 0;

int controller_1_rumble_state = 0;
int controller_2_rumble_state = 0;
int controller_3_rumble_state = 0;
int controller_4_rumble_state = 0;

int controller_1_rumble_duration = 0;
int controller_2_rumble_duration = 0;
int controller_3_rumble_duration = 0;
int controller_4_rumble_duration = 0;

int controller_1_rumble_pulse = 0;
int controller_2_rumble_pulse = 0;
int controller_3_rumble_pulse = 0;
int controller_4_rumble_pulse = 0;

int enable_controllers = 0;
int D_8002691C = 0;
int D_80026920 = 0;
int disable_all_rumble = 0;
int ptr_to_tlb_ramrom_record = 0;
int D_8002692C = 1;
int pl1_controller_failure_lr = 0;
int pl2_controller_failure_lr = 0;
int pl3_controller_failure_lr = 0;
int pl4_controller_failure_lr = 0;
int pl1_controller_failure_ud = 0;
int pl2_controller_failure_ud = 0;
int pl3_controller_failure_ud = 0;
int pl4_controller_failure_ud = 0;
int pl1_controller_failure_held = 0;
int pl2_controller_failure_held = 0;
int pl3_controller_failure_held = 0;
int pl4_controller_failure_held = 0;
int pl1_controller_failure_pressed = 0;
int pl2_controller_failure_pressed = 0;
int pl3_controller_failure_pressed = 0;
int pl4_controller_failure_pressed = 0;
int D_80026970 = 0;

asm(R"
glabel something_with_joy_c_debug
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lui   $a0, %hi(D_800268C0)
  lui   $a1, %hi(aJoy_c_debug)
  addiu $a1, %lo(aJoy_c_debug) # addiu $a1, $a1, -0x6c70
  jal   set_debug_notice_list_entry
   addiu $a0, %lo(D_800268C0) # addiu $a0, $a0, 0x68c0
  lui   $a0, %hi(controller1_message_queue)
  lui   $a1, %hi(cont1Mesg)
  addiu $a1, %lo(cont1Mesg) # addiu $a1, $a1, 0x5368
  addiu $a0, %lo(controller1_message_queue) # addiu $a0, $a0, 0x5370
  jal   osCreateMesgQueue
   li    $a2, 1
  lui   $a0, %hi(controller2_message_queue)
  lui   $a1, %hi(cont2Mesg)
  addiu $a1, %lo(cont2Mesg) # addiu $a1, $a1, 0x5388
  addiu $a0, %lo(controller2_message_queue) # addiu $a0, $a0, 0x5390
  jal   osCreateMesgQueue
   li    $a2, 1
  lui   $a0, %hi(controller3_message_queue)
  lui   $a1, %hi(cont3Mesg)
  addiu $a1, %lo(cont3Mesg) # addiu $a1, $a1, 0x53a8
  addiu $a0, %lo(controller3_message_queue) # addiu $a0, $a0, 0x53b0
  jal   osCreateMesgQueue
   li    $a2, 1
  lui   $a0, %hi(controller4_message_queue)
  lui   $a1, %hi(cont4Mesg)
  addiu $a1, %lo(cont4Mesg) # addiu $a1, $a1, 0x53c8
  addiu $a0, %lo(controller4_message_queue) # addiu $a0, $a0, 0x53d0
  jal   osCreateMesgQueue
   li    $a2, 1
  lui   $a0, %hi(contdemoMesgMQ)
  lui   $a1, %hi(contdemoMesg)
  addiu $a1, %lo(contdemoMesg) # addiu $a1, $a1, 0x5328
  addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
  jal   osCreateMesgQueue
   li    $a2, 10
  lui   $a1, %hi(contdemoMesgMQ)
  addiu $a1, %lo(contdemoMesgMQ) # addiu $a1, $a1, 0x5350
  li    $a0, 5
  jal   osSetEventMesg
   move  $a2, $zero
  li    $t6, 1
  lui   $at, %hi(enable_controllers)
  sw    $t6, %lo(enable_controllers)($at)
  lui   $at, %hi(disable_all_rumble)
  sw    $zero, %lo(disable_all_rumble)($at)
  lui   $t7, %hi(controller_input_index)
  lui   $at, %hi(ptr_to_tlb_ramrom_record)
  addiu $v0, $t7, %lo(controller_input_index)
  lui   $a1, %hi(contdemoMesg)
  sw    $zero, %lo(ptr_to_tlb_ramrom_record)($at)
  addiu $a1, %lo(contdemoMesg) # addiu $a1, $a1, 0x5328
  move  $v1, $v0
  li    $a0, -1
.L7000B63C:
  sw    $zero, 0x1e0($v1)
  sw    $zero, 0x1e4($v1)
  sw    $zero, 0x1e8($v1)
  sw    $zero, 0x1ec($v1)
  sw    $a0, 0x1f8($v1)
  addiu $v0, $v0, 0x1fc
  addiu $v1, $v1, 0x1fc
  sb    $zero, -0x1e6($v0)
  sb    $zero, -0x1e7($v0)
  sb    $zero, -0x1e8($v0)
  sh    $zero, -0x1ea($v0)
  sb    $zero, -0x1ec($v0)
  sb    $zero, -0x1ed($v0)
  sb    $zero, -0x1ee($v0)
  sh    $zero, -0x1f0($v0)
  sb    $zero, -0x1f2($v0)
  sb    $zero, -0x1f3($v0)
  sb    $zero, -0x1f4($v0)
  sh    $zero, -0x1f6($v0)
  sh    $zero, -0x1fc($v0)
  sb    $zero, -0x1fa($v0)
  sb    $zero, -0x1f9($v0)
  bne   $v0, $a1, .L7000B63C
   sb    $zero, -0x1f8($v0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

void test_controller_presence(void) {
  OSMesg message;

  if (enable_controllers) {
    enum { OS_MESG_NOBLOCK, OS_MESG_BLOCK };

    osSendMesg(&controller1_message_queue, &message, OS_MESG_NOBLOCK);
    osRecvMesg(&controller2_message_queue, &message, OS_MESG_BLOCK);

    controller_check_for_rumble_maybe();

    osSendMesg(&controller3_message_queue, &message, OS_MESG_NOBLOCK);
    osRecvMesg(&controller4_message_queue, &message, OS_MESG_BLOCK);
  }
}

int osPfsChecker(unsigned int *param_1) // OSPfs *param_1
{
  return 3;
}

asm(R"
glabel controller_7000B734
  lui   $t6, %hi(controller_1_rumble_inserted) 
  addiu $t6, %lo(controller_1_rumble_inserted) # addiu $t6, $t6, 0x68d8
  sll   $v0, $a0, 2
  addu  $a3, $v0, $t6
  lw    $t7, ($a3)
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  bltz  $t7, .L7000B800
   move  $a2, $a0
  lui   $t8, %hi(player1_controllerstatus) 
  addiu $t8, %lo(player1_controllerstatus) # addiu $t8, $t8, 0x53e8
  addu  $v1, $v0, $t8
  lhu   $t9, ($v1)
  andi  $t0, $t9, 4
  beql  $t0, $zero, .L7000B804
   lw    $ra, 0x14($sp)
  lbu   $t1, 2($v1)
  lui   $a0, %hi(contdemoMesgMQ)
  addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
  andi  $t2, $t1, 1
  beqz  $t2, .L7000B800
   sll   $t3, $a2, 2
  subu  $t3, $t3, $a2
  sll   $t3, $t3, 2
  addu  $t3, $t3, $a2
  lui   $t4, %hi(player1_controller_packet) 
  addiu $t4, %lo(player1_controller_packet) # addiu $t4, $t4, 0x53f8
  sll   $t3, $t3, 3
  addu  $a1, $t3, $t4
  sw    $a1, 0x20($sp)
  sw    $a2, 0x28($sp)
  jal   osPfsInit
   sw    $a3, 0x1c($sp)
  li    $at, 10
  lw    $a1, 0x20($sp)
  lw    $a2, 0x28($sp)
  beq   $v0, $at, .L7000B7D4
   lw    $a3, 0x1c($sp)
  li    $at, 11
  bne   $v0, $at, .L7000B800
.L7000B7D4:
   lui   $a0, %hi(contdemoMesgMQ)
  addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
  jal   controller_7000CD38
   sw    $a3, 0x1c($sp)
  bnez  $v0, .L7000B7F8
   lw    $a3, 0x1c($sp)
  li    $t5, 1
  b     .L7000B800
   sw    $t5, ($a3)
.L7000B7F8:
  li    $t6, -1
  sw    $t6, ($a3)
.L7000B800:
  lw    $ra, 0x14($sp)
.L7000B804:
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel controller_check_for_rumble_maybe
  lui   $v0, %hi(D_8002692C)
  addiu $v0, %lo(D_8002692C) # addiu $v0, $v0, 0x692c
  lw    $t6, ($v0)
  addiu $sp, $sp, -0x38
  sw    $ra, 0x1c($sp)
  beqz  $t6, .L7000B85C
   sw    $s0, 0x18($sp)
  lui   $a0, %hi(contdemoMesgMQ)
  lui   $a1, %hi(num_controller_plugged_in_flags)
  lui   $a2, %hi(player1_controllerstatus)
  sw    $zero, ($v0)
  addiu $a2, %lo(player1_controllerstatus) # addiu $a2, $a2, 0x53e8
  addiu $a1, %lo(num_controller_plugged_in_flags) # addiu $a1, $a1, 0x68d0
  jal   osContInit
   addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
  li    $t7, 1
  lui   $at, %hi(D_8002691C)
  b     .L7000B8F0
   sw    $t7, %lo(D_8002691C)($at)
.L7000B85C:
  lui   $a0, %hi(contdemoMesgMQ)
  li    $s0, 15
  jal   osContStartQuery
   addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
  lui   $a0, %hi(contdemoMesgMQ)
  addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
  move  $a1, $zero
  jal   osRecvMesg
   li    $a2, 1
  lui   $a0, %hi(player1_controllerstatus)
  jal   osContGetQuery
   addiu $a0, %lo(player1_controllerstatus) # addiu $a0, $a0, 0x53e8
  lui   $t8, %hi(player1_controllerstatus+3) 
  lbu   $t8, %lo(player1_controllerstatus+3)($t8)
  lui   $t0, %hi(player2_controllerstatus+3) 
  lui   $t2, %hi(player3_controllerstatus+3) 
  andi  $t9, $t8, 8
  beqz  $t9, .L7000B8AC
   lui   $t4, %hi(player4_controllerstatus+3) 
  li    $s0, 14
.L7000B8AC:
  lbu   $t0, %lo(player2_controllerstatus+3)($t0)
  lui   $at, %hi(num_controller_plugged_in_flags)
  andi  $t1, $t0, 8
  beqz  $t1, .L7000B8C4
   nop   
  addiu $s0, $s0, -2
.L7000B8C4:
  lbu   $t2, %lo(player3_controllerstatus+3)($t2)
  andi  $t3, $t2, 8
  beqz  $t3, .L7000B8D8
   nop   
  addiu $s0, $s0, -4
.L7000B8D8:
  lbu   $t4, %lo(player4_controllerstatus+3)($t4)
  andi  $t5, $t4, 8
  beqz  $t5, .L7000B8EC
   nop   
  addiu $s0, $s0, -8
.L7000B8EC:
  sb    $s0, %lo(num_controller_plugged_in_flags)($at)
.L7000B8F0:
  move  $s0, $zero
  addiu $s0, $s0, 1
.L7000B8F8:
  sll   $t6, $s0, 0x18
  sra   $s0, $t6, 0x18
  slti  $at, $s0, 4
  bnezl $at, .L7000B8F8
   addiu $s0, $s0, 1
  lui   $a3, %hi(num_controller_plugged_in_flags_0)
  lui   $a2, %hi(controller_1_rumble_inserted)
  addiu $a2, %lo(controller_1_rumble_inserted) # addiu $a2, $a2, 0x68d8
  addiu $a3, %lo(num_controller_plugged_in_flags_0) # addiu $a3, $a3, 0x68d4
  move  $s0, $zero
.L7000B920:
  lui   $t9, %hi(num_controller_plugged_in_flags) 
  lbu   $t9, %lo(num_controller_plugged_in_flags)($t9)
  li    $t8, 1
  sllv  $a1, $t8, $s0
  and   $t0, $t9, $a1
  beqz  $t0, .L7000B9B0
   lbu   $v1, ($a3)
  lui   $t1, %hi(player1_controllerstatus) 
  addiu $t1, %lo(player1_controllerstatus) # addiu $t1, $t1, 0x53e8
  sll   $a0, $s0, 2
  addu  $v0, $a0, $t1
  lhu   $t2, ($v0)
  andi  $t3, $t2, 3
  beql  $t3, $zero, .L7000B9B4
   and   $t9, $v1, $a1
  lbu   $t4, 3($v0)
  sltiu $v0, $v1, 1
  and   $t5, $v0, $a1
  bnezl $t4, .L7000B9B4
   and   $t9, $v1, $a1
  bnez  $t5, .L7000B980
   addu  $t6, $a2, $a0
  lw    $t7, ($t6)
  bgtz  $t7, .L7000B9A4
.L7000B980:
   move  $a0, $s0
  jal   controller_7000B734
   sw    $a1, 0x24($sp)
  lui   $a3, %hi(num_controller_plugged_in_flags_0)
  addiu $a3, %lo(num_controller_plugged_in_flags_0) # addiu $a3, $a3, 0x68d4
  lui   $a2, %hi(controller_1_rumble_inserted)
  addiu $a2, %lo(controller_1_rumble_inserted) # addiu $a2, $a2, 0x68d8
  lbu   $v1, ($a3)
  lw    $a1, 0x24($sp)
.L7000B9A4:
  or    $t8, $v1, $a1
  b     .L7000B9CC
   sb    $t8, ($a3)
.L7000B9B0:
  and   $t9, $v1, $a1
.L7000B9B4:
  beqz  $t9, .L7000B9CC
   xor   $t0, $v1, $a1
  sll   $t1, $s0, 2
  addu  $t2, $a2, $t1
  sb    $t0, ($a3)
  sw    $zero, ($t2)
.L7000B9CC:
  addiu $s0, $s0, 1
  sll   $t3, $s0, 0x18
  sra   $s0, $t3, 0x18
  slti  $at, $s0, 4
  bnez  $at, .L7000B920
   nop   
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   
");

asm(R"
glabel get_attached_controller_count
  lui   $t6, %hi(ptr_current_point_in_controller_input_index) 
  lw    $t6, %lo(ptr_current_point_in_controller_input_index)($t6)
  lui   $v0, %hi(num_controller_plugged_in_flags)
  lw    $v1, 0x1f8($t6)
  bltz  $v1, .L7000BA20
   nop   
  sll   $v0, $v1, 0x18
  sra   $t7, $v0, 0x18
  jr    $ra
   move  $v0, $t7

.L7000BA20:
  lbu   $v0, %lo(num_controller_plugged_in_flags)($v0)
  andi  $t8, $v0, 1
  bnez  $t8, .L7000BA38
   andi  $t9, $v0, 2
  jr    $ra
   move  $v0, $zero

.L7000BA38:
  bnez  $t9, .L7000BA48
   andi  $t0, $v0, 4
  jr    $ra
   li    $v0, 1

.L7000BA48:
  bnez  $t0, .L7000BA58
   andi  $t1, $v0, 8
  jr    $ra
   li    $v0, 2

.L7000BA58:
  bnez  $t1, .L7000BA68
   li    $v0, 4
  jr    $ra
   li    $v0, 3

.L7000BA68:
  jr    $ra
   nop   
");

unsigned char get_num_controllers_plugged_in(void) {
  return num_controller_plugged_in_flags;
}

#ifdef VERSION_US
asm(R"
glabel controller_rumble_related
  addiu $sp, $sp, -0x38
  sw    $s4, 0x28($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $s6, 0x30($sp)
  sw    $s5, 0x2c($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  lui   $s0, %hi(controller_1_rumble_duration)
  lui   $s1, %hi(controller_1_rumble_state)
  lui   $s4, %hi(controller_1_rumble_pulse)
  sw    $ra, 0x34($sp)
  addiu $s4, %lo(controller_1_rumble_pulse) # addiu $s4, $s4, 0x6908
  addiu $s1, %lo(controller_1_rumble_state) # addiu $s1, $s1, 0x68e8
  addiu $s0, %lo(controller_1_rumble_duration) # addiu $s0, $s0, 0x68f8
  move  $s2, $zero
  move  $s3, $zero
  li    $s5, 1
  li    $s6, 4
.L7000BAC8:
  lw    $v0, ($s4)
  lw    $t6, ($s1)
  sll   $t7, $s2, 2
  subu  $t7, $t7, $s2
  beq   $t6, $v0, .L7000BB44
   sll   $t7, $t7, 2
  addu  $t7, $t7, $s2
  lui   $t8, %hi(player1_controller_packet) 
  addiu $t8, %lo(player1_controller_packet) # addiu $t8, $t8, 0x53f8
  sll   $t7, $t7, 3
  bne   $s5, $v0, .L7000BB20
   addu  $a0, $t7, $t8
  jal   controller_7000CAAC
   nop   
  bnez  $v0, .L7000BB10
   lui   $t9, %hi(controller_1_rumble_inserted) 
  b     .L7000BB44
   sw    $s5, ($s1)
.L7000BB10:
  addiu $t9, %lo(controller_1_rumble_inserted) # addiu $t9, $t9, 0x68d8
  addu  $v0, $s3, $t9
  b     .L7000BB44
   sw    $zero, ($v0)
.L7000BB20:
  jal   send_rumble_off_to_PIF
   nop   
  bnez  $v0, .L7000BB38
   lui   $t0, %hi(controller_1_rumble_inserted) 
  b     .L7000BB44
   sw    $zero, ($s1)
.L7000BB38:
  addiu $t0, %lo(controller_1_rumble_inserted) # addiu $t0, $t0, 0x68d8
  addu  $v0, $s3, $t0
  sw    $zero, ($v0)
.L7000BB44:
  lw    $v0, ($s0)
  addiu $s2, $s2, 1
  addiu $s3, $s3, 4
  bgtz  $v0, .L7000BB60
   addiu $s1, $s1, 4
  b     .L7000BB74
   sw    $zero, ($s0)
.L7000BB60:
  addiu $t1, $v0, -1
  bgtz  $t1, .L7000BB74
   sw    $t1, ($s0)
  sw    $zero, ($s0)
  sw    $zero, ($s4)
.L7000BB74:
  addiu $s4, $s4, 4
  bne   $s2, $s6, .L7000BAC8
   addiu $s0, $s0, 4
  lw    $ra, 0x34($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  lw    $s3, 0x24($sp)
  lw    $s4, 0x28($sp)
  lw    $s5, 0x2c($sp)
  lw    $s6, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x38
");
#endif

#ifdef VERSION_JP
asm(R"
glabel controller_rumble_related
  addiu $sp, $sp, -0x40
  sw    $s5, 0x2c($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $fp, 0x38($sp)
  sw    $s7, 0x34($sp)
  sw    $s6, 0x30($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  lui   $s1, %hi(controller_1_rumble_duration) # $s1, 0x8002
  lui   $s2, %hi(controller_1_rumble_state) # $s2, 0x8002
  lui   $s5, %hi(controller_1_rumble_pulse) # $s5, 0x8002
  sw    $ra, 0x3c($sp)
  sw    $s0, 0x18($sp)
  addiu $s5, %lo(controller_1_rumble_pulse) # addiu $s5, $s5, 0x6948
  addiu $s2, %lo(controller_1_rumble_state) # addiu $s2, $s2, 0x6928
  addiu $s1, %lo(controller_1_rumble_duration) # addiu $s1, $s1, 0x6938
  move  $s3, $zero
  move  $s4, $zero
  li    $s6, 1
  li    $s7, 4
  li    $fp, 2
.Ljp7000BAE4:
  lw    $v0, ($s5)
  lw    $t6, ($s2)
  sll   $t7, $s3, 2
  subu  $t7, $t7, $s3
  beq   $t6, $v0, .Ljp7000BBA0
   sll   $t7, $t7, 2
  addu  $t7, $t7, $s3
  lui   $t8, %hi(player1_controller_packet) # $t8, 0x8006
  addiu $t8, %lo(player1_controller_packet) # addiu $t8, $t8, 0x5438
  sll   $t7, $t7, 3
  bne   $s6, $v0, .Ljp7000BB3C
   addu  $s0, $t7, $t8
  jal   controller_7000CAAC
   move  $a0, $s0
  bnez  $v0, .Ljp7000BB2C
   lui   $t9, %hi(controller_1_rumble_inserted) # $t9, 0x8002
  b     .Ljp7000BBA0
   sw    $s6, ($s2)
.Ljp7000BB2C:
  addiu $t9, %lo(controller_1_rumble_inserted) # addiu $t9, $t9, 0x6918
  addu  $v0, $s4, $t9
  b     .Ljp7000BBA0
   sw    $zero, ($v0)
.Ljp7000BB3C:
  bne   $fp, $v0, .Ljp7000BB7C
   lui   $a0, %hi(contdemoMesgMQ) # $a0, 0x8006
  addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5390
  move  $a1, $s0
  jal   controller_7000CD38
   move  $a2, $s3
  beqz  $v0, .Ljp7000BB68
   lui   $t0, %hi(controller_1_rumble_inserted) # $t0, 0x8002
  addiu $t0, %lo(controller_1_rumble_inserted) # addiu $t0, $t0, 0x6918
  addu  $v0, $s4, $t0
  sw    $zero, ($v0)
.Ljp7000BB68:
  jal   send_rumble_off_to_PIF
   move  $a0, $s0
  sw    $zero, ($s2)
  b     .Ljp7000BBA0
   sw    $zero, ($s5)
.Ljp7000BB7C:
  jal   send_rumble_off_to_PIF
   move  $a0, $s0
  bnez  $v0, .Ljp7000BB94
   lui   $t1, %hi(controller_1_rumble_inserted) # $t1, 0x8002
  b     .Ljp7000BBA0
   sw    $zero, ($s2)
.Ljp7000BB94:
  addiu $t1, %lo(controller_1_rumble_inserted) # addiu $t1, $t1, 0x6918
  addu  $v0, $s4, $t1
  sw    $zero, ($v0)
.Ljp7000BBA0:
  lw    $v0, ($s1)
  addiu $s3, $s3, 1
  addiu $s4, $s4, 4
  bgtz  $v0, .Ljp7000BBBC
   addiu $s2, $s2, 4
  b     .Ljp7000BBD0
   sw    $zero, ($s1)
.Ljp7000BBBC:
  addiu $t2, $v0, -1
  bgtz  $t2, .Ljp7000BBD0
   sw    $t2, ($s1)
  sw    $zero, ($s1)
  sw    $zero, ($s5)
.Ljp7000BBD0:
  addiu $s5, $s5, 4
  bne   $s3, $s7, .Ljp7000BAE4
   addiu $s1, $s1, 4
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
   addiu $sp, $sp, 0x40
");
#endif

void set_disable_all_rumble_and_something(int arg0, int arg1) {
  disable_all_rumble = arg0;
  dword_CODE_bss_80065324 = arg1;
}

void set_ptr_tlb_ramrom_record(int arg0) { ptr_to_tlb_ramrom_record = arg0; }

asm(R"
glabel probably_ramrom_related
  lw    $t6, 0x1e0($a0)
  lw    $t7, 0x1e8($a0)
  move  $v0, $zero
  li    $t1, 20
  sw    $t6, 0x1e4($a0)
  sw    $t7, 0x1e0($a0)
  sll   $t8, $v0, 1
.L7000BBE4:
  addu  $v1, $a0, $t8
  sh    $zero, 0x1f0($v1)
  lw    $t9, 0x1e0($a0)
  lw    $a1, 0x1e4($a0)
  beq   $a1, $t9, .L7000BCEC
   addiu $t2, $a1, 1
  div   $zero, $t2, $t1
  sll   $a3, $v0, 2
  mfhi  $a2
  subu  $a3, $a3, $v0
  sll   $a3, $a3, 1
  bnez  $t1, .L7000BC1C
   nop   
  break 7
.L7000BC1C:
  li    $at, -1
  bne   $t1, $at, .L7000BC34
   lui   $at, 0x8000
  bne   $t2, $at, .L7000BC34
   nop   
  break 6
.L7000BC34:
  addiu $t6, $a2, 0x13
.L7000BC38:
  div   $zero, $t6, $t1
  mfhi  $t7
  sll   $t8, $t7, 2
  sll   $t3, $a2, 2
  subu  $t8, $t8, $t7
  subu  $t3, $t3, $a2
  sll   $t8, $t8, 3
  sll   $t3, $t3, 3
  addu  $t9, $a0, $t8
  addu  $t4, $a0, $t3
  addu  $t2, $t9, $a3
  lhu   $t0, ($t2)
  addu  $t5, $t4, $a3
  lhu   $a1, ($t5)
  lhu   $t3, 0x1f0($v1)
  not   $t4, $t0
  bnez  $t1, .L7000BC84
   nop   
  break 7
.L7000BC84:
  li    $at, -1
  bne   $t1, $at, .L7000BC9C
   lui   $at, 0x8000
  bne   $t6, $at, .L7000BC9C
   nop   
  break 6
.L7000BC9C:
  and   $t5, $a1, $t4
  or    $t6, $t3, $t5
  sh    $t6, 0x1f0($v1)
  lw    $t7, 0x1e0($a0)
  addiu $t8, $a2, 1
  beql  $a2, $t7, .L7000BCF0
   addiu $v0, $v0, 1
  div   $zero, $t8, $t1
  mfhi  $a2
  bnez  $t1, .L7000BCCC
   nop   
  break 7
.L7000BCCC:
  li    $at, -1
  bne   $t1, $at, .L7000BCE4
   lui   $at, 0x8000
  bne   $t8, $at, .L7000BCE4
   nop   
  break 6
.L7000BCE4:
  b     .L7000BC38
   addiu $t6, $a2, 0x13
.L7000BCEC:
  addiu $v0, $v0, 1
.L7000BCF0:
  sll   $t9, $v0, 0x18
  sra   $v0, $t9, 0x18
  slti  $at, $v0, 4
  bnezl $at, .L7000BBE4
   sll   $t8, $v0, 1
  jr    $ra
   nop   
");

asm(R"
glabel redirect_to_ramrom_replay_and_record_handlers_if_set
  lui   $v0, %hi(disable_all_rumble)
  lw    $v0, %lo(disable_all_rumble)($v0)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  beqz  $v0, .L7000BD48
   lui   $a0, %hi(dword_CODE_bss_8006512C)
  lui   $a1, %hi(dword_CODE_bss_8006530C)
  lw    $a1, %lo(dword_CODE_bss_8006530C)($a1)
  jalr  $v0
  addiu $a0, %lo(dword_CODE_bss_8006512C) # addiu $a0, $a0, 0x512c
  lui   $at, %hi(dword_CODE_bss_80065314)
  lui   $a0, %hi(dword_CODE_bss_8006512C)
  sw    $v0, %lo(dword_CODE_bss_80065314)($at)
  jal   probably_ramrom_related
   addiu $a0, %lo(dword_CODE_bss_8006512C) # addiu $a0, $a0, 0x512c
.L7000BD48:
  lui   $a0, %hi(controller_input_index)
  jal   probably_ramrom_related
   addiu $a0, %lo(controller_input_index) # addiu $a0, $a0, 0x4f30
  lui   $v0, %hi(ptr_to_tlb_ramrom_record)
  lw    $v0, %lo(ptr_to_tlb_ramrom_record)($v0)
  lui   $a0, %hi(controller_input_index)
  addiu $a0, %lo(controller_input_index) # addiu $a0, $a0, 0x4f30
  beql  $v0, $zero, .L7000BD7C
   lw    $ra, 0x14($sp)
  lw    $a1, 0x1e4($a0)
  jalr  $v0
  lw    $a2, 0x1e0($a0)
  lw    $ra, 0x14($sp)
.L7000BD7C:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel controllerSchedulerRelated
  addiu $sp, $sp, -0x50
  sw    $ra, 0x14($sp)
  lui   $a0, %hi(controller1_message_queue)
  addiu $a0, %lo(controller1_message_queue) # addiu $a0, $a0, 0x5370
  addiu $a1, $sp, 0x4c
  jal   osRecvMesg
   move  $a2, $zero
  bnez  $v0, .L7000BDFC
   lui   $t6, %hi(D_800268C8) 
  lw    $t6, %lo(D_800268C8)($t6)
  lui   $a0, %hi(contdemoMesgMQ)
  addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
  beqz  $t6, .L7000BDD0
   addiu $a1, $sp, 0x4c
  jal   osRecvMesg
   li    $a2, 1
  lui   $at, %hi(D_800268C8)
  sw    $zero, %lo(D_800268C8)($at)
.L7000BDD0:
  lui   $a0, %hi(controller2_message_queue)
  addiu $a0, %lo(controller2_message_queue) # addiu $a0, $a0, 0x5390
  addiu $a1, $sp, 0x4c
  jal   osSendMesg
   move  $a2, $zero
  lui   $v1, %hi(D_800268CC)
  addiu $v1, %lo(D_800268CC) # addiu $v1, $v1, 0x68cc
  lw    $t7, ($v1)
  addiu $t8, $t7, 1
  b     .L7000C0DC
   sw    $t8, ($v1)
.L7000BDFC:
  lui   $a0, %hi(controller3_message_queue)
  addiu $a0, %lo(controller3_message_queue) # addiu $a0, $a0, 0x53b0
  addiu $a1, $sp, 0x4c
  jal   osRecvMesg
   move  $a2, $zero
  bnez  $v0, .L7000BE58
   lui   $a0, %hi(contdemoMesgMQ)
  jal   osContStartReadData
   addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
  li    $t9, 1
  lui   $at, %hi(D_800268C8)
  lui   $a0, %hi(controller4_message_queue)
  sw    $t9, %lo(D_800268C8)($at)
  addiu $a0, %lo(controller4_message_queue) # addiu $a0, $a0, 0x53d0
  addiu $a1, $sp, 0x4c
  jal   osSendMesg
   move  $a2, $zero
  lui   $v1, %hi(D_800268CC)
  addiu $v1, %lo(D_800268CC) # addiu $v1, $v1, 0x68cc
  lw    $t3, ($v1)
  addiu $t4, $t3, -1
  b     .L7000C0DC
   sw    $t4, ($v1)
.L7000BE58:
  lui   $v1, %hi(D_800268CC)
  addiu $v1, %lo(D_800268CC) # addiu $v1, $v1, 0x68cc
  lw    $t5, ($v1)
  lui   $t6, %hi(D_8002691C) 
  bnezl $t5, .L7000C0E0
   lw    $ra, 0x14($sp)
  lw    $t6, %lo(D_8002691C)($t6)
  lui   $a0, %hi(contdemoMesgMQ)
  addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
  beqz  $t6, .L7000C0DC
   addiu $a1, $sp, 0x4c
  jal   osRecvMesg
   move  $a2, $zero
  bnez  $v0, .L7000C0DC
   lui   $a1, %hi(controller_input_index)
  lui   $at, %hi(D_800268C8)
  addiu $a1, %lo(controller_input_index) # addiu $a1, $a1, 0x4f30
  sw    $zero, %lo(D_800268C8)($at)
  lw    $v0, 0x1e8($a1)
  li    $at, 20
  lw    $t8, 0x1e4($a1)
  addiu $v1, $v0, 1
  div   $zero, $v1, $at
  mfhi  $v1
  bnel  $v1, $t8, .L7000BEC8
   sll   $t9, $v1, 2
  move  $v1, $v0
  sll   $t9, $v1, 2
.L7000BEC8:
  subu  $t9, $t9, $v1
  sll   $t9, $t9, 3
  addu  $a0, $a1, $t9
  jal   osContGetReadData
   sw    $v1, 0x40($sp)
  lw    $v0, 0x40($sp)
  li    $at, 20
  lui   $a0, %hi(D_80026920)
  addiu $t3, $v0, 0x13
  div   $zero, $t3, $at
  addiu $a0, %lo(D_80026920) # addiu $a0, $a0, 0x6920
  lw    $t5, ($a0)
  mfhi  $t4
  li    $at, 120
  addiu $t6, $t5, 1
  div   $zero, $t6, $at
  lui   $a1, %hi(controller_input_index)
  addiu $a1, %lo(controller_input_index) # addiu $a1, $a1, 0x4f30
  mfhi  $t8
  sw    $t4, 0x1ec($a1)
  sw    $t6, ($a0)
  bnez  $t8, .L7000BF38
   sw    $v0, 0x1e8($a1)
  jal   controller_check_for_rumble_maybe
   nop   
  lui   $a1, %hi(controller_input_index)
  addiu $a1, %lo(controller_input_index) # addiu $a1, $a1, 0x4f30
  lw    $v0, 0x1e8($a1)
.L7000BF38:
  sll   $t9, $v0, 2
  subu  $t9, $t9, $v0
  sll   $t9, $t9, 3
  addu  $a2, $a1, $t9
  move  $a0, $zero
  li    $a3, 6
.L7000BF50:
  multu $a0, $a3
  mflo  $v0
  addu  $t3, $a2, $v0
  lbu   $v1, 4($t3)
  bnez  $v1, .L7000BF8C
   nop   
  lw    $t4, 0x1ec($a1)
  sll   $t5, $t4, 2
  subu  $t5, $t5, $t4
  sll   $t5, $t5, 3
  addu  $t6, $a1, $t5
  addu  $t7, $t6, $v0
  lbu   $t8, 4($t7)
  bnez  $t8, .L7000BFB8
   nop   
.L7000BF8C:
  beqz  $v1, .L7000BFC8
   addiu $a0, $a0, 1
  lw    $t9, 0x1ec($a1)
  sll   $t3, $t9, 2
  subu  $t3, $t3, $t9
  sll   $t3, $t3, 3
  addu  $t4, $a1, $t3
  addu  $t5, $t4, $v0
  lbu   $t6, 4($t5)
  bnezl $t6, .L7000BFCC
   sll   $t7, $a0, 0x18
.L7000BFB8:
  jal   controller_check_for_rumble_maybe
   nop   
  b     .L7000BFDC
   nop   
.L7000BFC8:
  sll   $t7, $a0, 0x18
.L7000BFCC:
  sra   $a0, $t7, 0x18
  slti  $at, $a0, 4
  bnez  $at, .L7000BF50
   nop   
.L7000BFDC:
  jal   controller_rumble_related
   nop   
  lui   $a0, %hi(contdemoMesgMQ)
  jal   osContStartReadData
   addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
  lui   $v1, %hi(D_80026970)
  lw    $v1, %lo(D_80026970)($v1)
  li    $t9, 1
  lui   $at, %hi(D_800268C8)
  sw    $t9, %lo(D_800268C8)($at)
  lui   $at, %hi(D_80026970)
  addiu $v1, $v1, 1
  sw    $v1, %lo(D_80026970)($at)
  slti  $at, $v1, 0x3c
  bnez  $at, .L7000C0DC
   lui   $t1, %hi(pl1_controller_failure_lr) 
  lui   $a0, %hi(pl1_controller_failure_ud)
  lui   $a1, %hi(pl1_controller_failure_held)
  lui   $v1, %hi(pl1_controller_failure_pressed)
  lui   $t2, %hi(D_80026970) 
  addiu $t2, %lo(D_80026970) # addiu $t2, $t2, 0x6970
  addiu $v1, %lo(pl1_controller_failure_pressed) # addiu $v1, $v1, 0x6960
  addiu $a1, %lo(pl1_controller_failure_held) # addiu $a1, $a1, 0x6950
  addiu $a0, %lo(pl1_controller_failure_ud) # addiu $a0, $a0, 0x6940
  addiu $t1, %lo(pl1_controller_failure_lr) # addiu $t1, $t1, 0x6930
.L7000C040:
  lw    $v0, ($t1)
  bnezl $v0, .L7000C074
   sw    $zero, ($t1)
  lw    $t3, ($a0)
  bnezl $t3, .L7000C074
   sw    $zero, ($t1)
  lw    $t4, ($a1)
  bnezl $t4, .L7000C074
   sw    $zero, ($t1)
  lw    $t5, ($v1)
  beql  $t5, $zero, .L7000C084
   lw    $v0, 4($t1)
  sw    $zero, ($t1)
.L7000C074:
  sw    $zero, ($a0)
  sw    $zero, ($a1)
  sw    $zero, ($v1)
  lw    $v0, 4($t1)
.L7000C084:
  bnezl $v0, .L7000C0B4
   sw    $zero, 4($t1)
  lw    $t6, 4($a0)
  bnezl $t6, .L7000C0B4
   sw    $zero, 4($t1)
  lw    $t7, 4($a1)
  bnezl $t7, .L7000C0B4
   sw    $zero, 4($t1)
  lw    $t8, 4($v1)
  beql  $t8, $zero, .L7000C0C4
   addiu $v1, $v1, 8
  sw    $zero, 4($t1)
.L7000C0B4:
  sw    $zero, 4($a0)
  sw    $zero, 4($a1)
  sw    $zero, 4($v1)
  addiu $v1, $v1, 8
.L7000C0C4:
  addiu $t1, $t1, 8
  addiu $a0, $a0, 8
  bne   $v1, $t2, .L7000C040
   addiu $a1, $a1, 8
  lui   $at, %hi(D_80026970)
  sw    $zero, %lo(D_80026970)($at)
.L7000C0DC:
  lw    $ra, 0x14($sp)
.L7000C0E0:
  addiu $sp, $sp, 0x50
  jr    $ra
   nop   
");

asm(R"
glabel get_cur_controller_horz_stick_pos
  lui   $v1, %hi(ptr_current_point_in_controller_input_index)
  lw    $v1, %lo(ptr_current_point_in_controller_input_index)($v1)
  sw    $a0, ($sp)
  sll   $t6, $a0, 0x18
  lw    $t8, 0x1f8($v1)
  sra   $t7, $t6, 0x18
  move  $a0, $t7
  bgez  $t8, .L7000C144
   lui   $t9, %hi(num_controller_plugged_in_flags) 
  lbu   $t9, %lo(num_controller_plugged_in_flags)($t9)
  lui   $t3, %hi(pl1_controller_failure_lr) 
  addiu $t3, %lo(pl1_controller_failure_lr) # addiu $t3, $t3, 0x6930
  srav  $t0, $t9, $t7
  andi  $t1, $t0, 1
  bnez  $t1, .L7000C144
   sll   $t2, $t7, 2
  addu  $v1, $t2, $t3
  lw    $t4, ($v1)
  move  $v0, $zero
  addiu $t5, $t4, 1
  jr    $ra
   sw    $t5, ($v1)

.L7000C144:
  lw    $t6, 0x1e0($v1)
  sll   $t9, $a0, 2
  subu  $t9, $t9, $a0
  sll   $t7, $t6, 2
  subu  $t7, $t7, $t6
  sll   $t7, $t7, 3
  addu  $t8, $v1, $t7
  sll   $t9, $t9, 1
  addu  $t0, $t8, $t9
  lb    $v0, 2($t0)
  jr    $ra
   nop   
");

asm(R"
glabel controller_7000C174
  lui   $v1, %hi(ptr_current_point_in_controller_input_index)
  lw    $v1, %lo(ptr_current_point_in_controller_input_index)($v1)
  sw    $a0, ($sp)
  sll   $t6, $a0, 0x18
  lw    $t8, 0x1f8($v1)
  sra   $t7, $t6, 0x18
  move  $a0, $t7
  bgez  $t8, .L7000C1CC
   lui   $t9, %hi(num_controller_plugged_in_flags) 
  lbu   $t9, %lo(num_controller_plugged_in_flags)($t9)
  lui   $t3, %hi(pl1_controller_failure_lr) 
  addiu $t3, %lo(pl1_controller_failure_lr) # addiu $t3, $t3, 0x6930
  srav  $t0, $t9, $t7
  andi  $t1, $t0, 1
  bnez  $t1, .L7000C1CC
   sll   $t2, $t7, 2
  addu  $v1, $t2, $t3
  lw    $t4, ($v1)
  move  $v0, $zero
  addiu $t5, $t4, 1
  jr    $ra
   sw    $t5, ($v1)

.L7000C1CC:
  lw    $t6, 0x1e4($v1)
  sll   $t9, $a0, 2
  subu  $t9, $t9, $a0
  sll   $t7, $t6, 2
  subu  $t7, $t7, $t6
  sll   $t7, $t7, 3
  addu  $t8, $v1, $t7
  sll   $t9, $t9, 1
  addu  $t0, $t8, $t9
  lb    $v0, 2($t0)
  jr    $ra
   nop   
");

asm(R"
glabel get_cur_controller_vert_stick_pos
  lui   $v1, %hi(ptr_current_point_in_controller_input_index)
  lw    $v1, %lo(ptr_current_point_in_controller_input_index)($v1)
  sw    $a0, ($sp)
  sll   $t6, $a0, 0x18
  lw    $t8, 0x1f8($v1)
  sra   $t7, $t6, 0x18
  move  $a0, $t7
  bgez  $t8, .L7000C254
   lui   $t9, %hi(num_controller_plugged_in_flags) 
  lbu   $t9, %lo(num_controller_plugged_in_flags)($t9)
  lui   $t3, %hi(pl1_controller_failure_ud) 
  addiu $t3, %lo(pl1_controller_failure_ud) # addiu $t3, $t3, 0x6940
  srav  $t0, $t9, $t7
  andi  $t1, $t0, 1
  bnez  $t1, .L7000C254
   sll   $t2, $t7, 2
  addu  $v1, $t2, $t3
  lw    $t4, ($v1)
  move  $v0, $zero
  addiu $t5, $t4, 1
  jr    $ra
   sw    $t5, ($v1)

.L7000C254:
  lw    $t6, 0x1e0($v1)
  sll   $t9, $a0, 2
  subu  $t9, $t9, $a0
  sll   $t7, $t6, 2
  subu  $t7, $t7, $t6
  sll   $t7, $t7, 3
  addu  $t8, $v1, $t7
  sll   $t9, $t9, 1
  addu  $t0, $t8, $t9
  lb    $v0, 3($t0)
  jr    $ra
   nop   
");

asm(R"
glabel controller_7000C284
  lui   $v1, %hi(ptr_current_point_in_controller_input_index)
  lw    $v1, %lo(ptr_current_point_in_controller_input_index)($v1)
  sw    $a0, ($sp)
  sll   $t6, $a0, 0x18
  lw    $t8, 0x1f8($v1)
  sra   $t7, $t6, 0x18
  move  $a0, $t7
  bgez  $t8, .L7000C2DC
   lui   $t9, %hi(num_controller_plugged_in_flags) 
  lbu   $t9, %lo(num_controller_plugged_in_flags)($t9)
  lui   $t3, %hi(pl1_controller_failure_ud) 
  addiu $t3, %lo(pl1_controller_failure_ud) # addiu $t3, $t3, 0x6940
  srav  $t0, $t9, $t7
  andi  $t1, $t0, 1
  bnez  $t1, .L7000C2DC
   sll   $t2, $t7, 2
  addu  $v1, $t2, $t3
  lw    $t4, ($v1)
  move  $v0, $zero
  addiu $t5, $t4, 1
  jr    $ra
   sw    $t5, ($v1)

.L7000C2DC:
  lw    $t6, 0x1e4($v1)
  sll   $t9, $a0, 2
  subu  $t9, $t9, $a0
  sll   $t7, $t6, 2
  subu  $t7, $t7, $t6
  sll   $t7, $t7, 3
  addu  $t8, $v1, $t7
  sll   $t9, $t9, 1
  addu  $t0, $t8, $t9
  lb    $v0, 3($t0)
  jr    $ra
   nop   
");

asm(R"
glabel get_controller_buttons_held
  lui   $v1, %hi(ptr_current_point_in_controller_input_index)
  lw    $v1, %lo(ptr_current_point_in_controller_input_index)($v1)
  sw    $a0, ($sp)
  sw    $a1, 4($sp)
  lw    $t9, 0x1f8($v1)
  sll   $t6, $a0, 0x18
  sra   $t7, $t6, 0x18
  andi  $t8, $a1, 0xffff
  move  $a1, $t8
  bgez  $t9, .L7000C370
   move  $a0, $t7
  lui   $t0, %hi(num_controller_plugged_in_flags) 
  lbu   $t0, %lo(num_controller_plugged_in_flags)($t0)
  lui   $t4, %hi(pl1_controller_failure_held) 
  addiu $t4, %lo(pl1_controller_failure_held) # addiu $t4, $t4, 0x6950
  srav  $t1, $t0, $t7
  andi  $t2, $t1, 1
  bnez  $t2, .L7000C370
   sll   $t3, $t7, 2
  addu  $v1, $t3, $t4
  lw    $t5, ($v1)
  move  $v0, $zero
  addiu $t6, $t5, 1
  jr    $ra
   sw    $t6, ($v1)

.L7000C370:
  lw    $t7, 0x1e0($v1)
  sll   $t0, $a0, 2
  subu  $t0, $t0, $a0
  sll   $t8, $t7, 2
  subu  $t8, $t8, $t7
  sll   $t8, $t8, 3
  addu  $t9, $v1, $t8
  sll   $t0, $t0, 1
  addu  $t1, $t9, $t0
  lhu   $t2, ($t1)
  and   $v0, $t2, $a1
  andi  $t3, $v0, 0xffff
  move  $v0, $t3
  jr    $ra
   nop   
");

asm(R"
glabel get_controller_buttons_pressed
  lui   $v1, %hi(ptr_current_point_in_controller_input_index)
  lw    $v1, %lo(ptr_current_point_in_controller_input_index)($v1)
  sw    $a0, ($sp)
  sw    $a1, 4($sp)
  lw    $t9, 0x1f8($v1)
  sll   $t6, $a0, 0x18
  sra   $t7, $t6, 0x18
  andi  $t8, $a1, 0xffff
  move  $a1, $t8
  bgez  $t9, .L7000C410
   move  $a0, $t7
  lui   $t0, %hi(num_controller_plugged_in_flags) 
  lbu   $t0, %lo(num_controller_plugged_in_flags)($t0)
  lui   $t4, %hi(pl1_controller_failure_pressed) 
  addiu $t4, %lo(pl1_controller_failure_pressed) # addiu $t4, $t4, 0x6960
  srav  $t1, $t0, $t7
  andi  $t2, $t1, 1
  bnez  $t2, .L7000C410
   sll   $t3, $t7, 2
  addu  $v1, $t3, $t4
  lw    $t5, ($v1)
  move  $v0, $zero
  addiu $t6, $t5, 1
  jr    $ra
   sw    $t6, ($v1)

.L7000C410:
  sll   $t7, $a0, 1
  addu  $t8, $v1, $t7
  lhu   $t9, 0x1f0($t8)
  and   $v0, $t9, $a1
  andi  $t0, $v0, 0xffff
  move  $v0, $t0
  jr    $ra
   nop   
");

asm(R"
glabel controller_7000C430
  sw    $a1, 4($sp)
  andi  $v1, $a1, 0xffff
  li    $a1, 17
  li    $v0, 15
.L7000C440:
  srav  $t7, $v1, $v0
  andi  $t8, $t7, 1
  slt   $t9, $zero, $t8
  multu $t9, $a1
  addiu $v0, $v0, -1
  addiu $a0, $a0, 1
  mflo  $t0
  addiu $t1, $t0, 0x20
  bgez  $v0, .L7000C440
   sb    $t1, -1($a0)
  jr    $ra
   nop   
");

asm(R"
glabel controller_7000C470
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  jal   get_attached_controller_count
   move  $s0, $zero
  blezl $v0, .L7000C4A4
   lw    $ra, 0x1c($sp)
.L7000C48C:
  jal   get_attached_controller_count
   addiu $s0, $s0, 1
  slt   $at, $s0, $v0
  bnez  $at, .L7000C48C
   nop   
  lw    $ra, 0x1c($sp)
.L7000C4A4:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel get_controller_3dstick_L_R
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  sll   $t6, $a0, 0x18
  sra   $a0, $t6, 0x18
  sw    $a1, 0x1c($sp)
  jal   get_cur_controller_horz_stick_pos
   sw    $a2, 0x20($sp)
  addiu $a0, $v0, 0x3c
  slti  $at, $a0, 0x79
  bnez  $at, .L7000C4E8
   lw    $a1, 0x1c($sp)
  li    $a0, 120
.L7000C4E8:
  bgez  $a0, .L7000C4F4
   lw    $t8, 0x20($sp)
  move  $a0, $zero
.L7000C4F4:
  subu  $t9, $t8, $a1
  multu $a0, $t9
  li    $at, 120
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  mflo  $t0
  nop   
  nop   
  div   $zero, $t0, $at
  mflo  $t1
  addu  $v0, $t1, $a1
  jr    $ra
   nop   
");

asm(R"
glabel get_controller_3dstick_U_D
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  sll   $t6, $a0, 0x18
  sra   $a0, $t6, 0x18
  sw    $a1, 0x1c($sp)
  jal   get_cur_controller_vert_stick_pos
   sw    $a2, 0x20($sp)
  addiu $a0, $v0, 0x3c
  slti  $at, $a0, 0x79
  bnez  $at, .L7000C55C
   lw    $a1, 0x1c($sp)
  li    $a0, 120
.L7000C55C:
  bgez  $a0, .L7000C568
   lw    $t8, 0x20($sp)
  move  $a0, $zero
.L7000C568:
  subu  $t9, $t8, $a1
  multu $a0, $t9
  li    $at, 120
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  mflo  $t0
  nop   
  nop   
  div   $zero, $t0, $at
  mflo  $t1
  addu  $v0, $t1, $a1
  jr    $ra
   nop   
");

asm(R"
glabel controller_7000C59C
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  sll   $t6, $a0, 0x18
  sra   $a0, $t6, 0x18
  sw    $a1, 0x1c($sp)
  jal   get_cur_controller_horz_stick_pos
   sw    $a2, 0x20($sp)
  addiu $a0, $v0, 0x3c
  slti  $at, $a0, 0x79
  bnez  $at, .L7000C5D0
   lwc1  $f2, 0x1c($sp)
  li    $a0, 120
.L7000C5D0:
  bgezl $a0, .L7000C5E0
   mtc1  $a0, $f4
  move  $a0, $zero
  mtc1  $a0, $f4
.L7000C5E0:
  li    $at, 0x42F00000 # 120.000000
  mtc1  $at, $f8
  cvt.s.w $f6, $f4
  lwc1  $f16, 0x20($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  sub.s $f18, $f16, $f2
  div.s $f10, $f6, $f8
  mul.s $f4, $f10, $f18
  jr    $ra
   add.s $f0, $f4, $f2
");

asm(R"
glabel controller_7000C60C
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  sll   $t6, $a0, 0x18
  sra   $a0, $t6, 0x18
  sw    $a1, 0x1c($sp)
  jal   get_cur_controller_vert_stick_pos
   sw    $a2, 0x20($sp)
  addiu $a0, $v0, 0x3c
  slti  $at, $a0, 0x79
  bnez  $at, .L7000C640
   lwc1  $f2, 0x1c($sp)
  li    $a0, 120
.L7000C640:
  bgezl $a0, .L7000C650
   mtc1  $a0, $f4
  move  $a0, $zero
  mtc1  $a0, $f4
.L7000C650:
  li    $at, 0x42F00000 # 120.000000
  mtc1  $at, $f8
  cvt.s.w $f6, $f4
  lwc1  $f16, 0x20($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  sub.s $f18, $f16, $f2
  div.s $f10, $f6, $f8
  mul.s $f4, $f10, $f18
  jr    $ra
   add.s $f0, $f4, $f2
");

asm(R"
glabel controller_7000C67C
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  lui   $a0, %hi(controller1_message_queue)
  addiu $a0, %lo(controller1_message_queue) # addiu $a0, $a0, 0x5370
  addiu $a1, $sp, 0x1c
  jal   osSendMesg
   move  $a2, $zero
  lui   $a0, %hi(controller2_message_queue)
  addiu $a0, %lo(controller2_message_queue) # addiu $a0, $a0, 0x5390
  addiu $a1, $sp, 0x1c
  jal   osRecvMesg
   li    $a2, 1
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel controller_7000C6BC
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  lui   $a0, %hi(controller3_message_queue)
  addiu $a0, %lo(controller3_message_queue) # addiu $a0, $a0, 0x53b0
  addiu $a1, $sp, 0x1c
  jal   osSendMesg
   move  $a2, $zero
  lui   $a0, %hi(controller4_message_queue)
  addiu $a0, %lo(controller4_message_queue) # addiu $a0, $a0, 0x53d0
  addiu $a1, $sp, 0x1c
  jal   osRecvMesg
   li    $a2, 1
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel save_7000C6FC
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  jal   controller_7000C67C
   nop   
  lui   $a0, %hi(contdemoMesgMQ)
  jal   osEepromProbe
   addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
  jal   controller_7000C6BC
   sw    $v0, 0x1c($sp)
  lw    $ra, 0x14($sp)
  lw    $v0, 0x1c($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel save_7000C734
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a0, 0x20($sp)
  jal   controller_7000C67C
   sw    $a1, 0x24($sp)
  lui   $a0, %hi(contdemoMesgMQ)
  addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
  lbu   $a1, 0x23($sp)
  jal   osEepromRead
   lw    $a2, 0x24($sp)
  jal   controller_7000C6BC
   sw    $v0, 0x1c($sp)
  lw    $ra, 0x14($sp)
  lw    $v0, 0x1c($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel save_7000C778
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a0, 0x20($sp)
  jal   controller_7000C67C
   sw    $a1, 0x24($sp)
  lui   $a0, %hi(contdemoMesgMQ)
  addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
  lbu   $a1, 0x23($sp)
  jal   osEepromWrite
   lw    $a2, 0x24($sp)
  jal   controller_7000C6BC
   sw    $v0, 0x1c($sp)
  lw    $ra, 0x14($sp)
  lw    $v0, 0x1c($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel save_7000C7BC
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a0, 0x20($sp)
  sw    $a1, 0x24($sp)
  jal   controller_7000C67C
   sw    $a2, 0x28($sp)
  lui   $a0, %hi(contdemoMesgMQ)
  addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
  lbu   $a1, 0x23($sp)
  lw    $a2, 0x24($sp)
  jal   osEepromLongRead
   lw    $a3, 0x28($sp)
  jal   controller_7000C6BC
   sw    $v0, 0x1c($sp)
  lw    $ra, 0x14($sp)
  lw    $v0, 0x1c($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel save_7000C808
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a0, 0x20($sp)
  sw    $a1, 0x24($sp)
  jal   controller_7000C67C
   sw    $a2, 0x28($sp)
  lui   $a0, %hi(contdemoMesgMQ)
  addiu $a0, %lo(contdemoMesgMQ) # addiu $a0, $a0, 0x5350
  lbu   $a1, 0x23($sp)
  lw    $a2, 0x24($sp)
  jal   osEepromLongWrite
   lw    $a3, 0x28($sp)
  jal   controller_7000C6BC
   sw    $v0, 0x1c($sp)
  lw    $ra, 0x14($sp)
  lw    $v0, 0x1c($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel controller_7000C854
  lui   $t6, %hi(disable_all_rumble) 
  lw    $t6, %lo(disable_all_rumble)($t6)
  mtc1  $a1, $f12
  sll   $v1, $a0, 2
  bnez  $t6, .L7000C8D4
   lui   $t7, %hi(controller_1_rumble_inserted)
  addu  $t7, $t7, $v1
  lw    $t7, %lo(controller_1_rumble_inserted)($t7)
  lui   $t1, %hi(controller_1_rumble_state)
  li    $at, 0x42700000 # 60.000000
  blez  $t7, .L7000C8D4
   addu  $t1, $t1, $v1
  mtc1  $at, $f4
  lui   $t8, %hi(controller_1_rumble_duration) 
  addiu $t8, %lo(controller_1_rumble_duration) # addiu $t8, $t8, 0x68f8
  mul.s $f6, $f12, $f4
  addu  $a0, $v1, $t8
  lw    $t0, ($a0)
  li    $t2, 1
  trunc.w.s $f8, $f6
  mfc1  $v0, $f8
  nop   
  slt   $at, $t0, $v0
  beqz  $at, .L7000C8BC
   nop   
  sw    $v0, ($a0)
.L7000C8BC:
  lw    $t1, %lo(controller_1_rumble_state)($t1)
  lui   $at, %hi(controller_1_rumble_pulse)
  addu  $at, $at, $v1
  bnez  $t1, .L7000C8D4
   nop   
  sw    $t2, %lo(controller_1_rumble_pulse)($at)
.L7000C8D4:
  jr    $ra
   nop   
");

#ifdef VERSION_US
asm(R"
glabel reset_cont_rumble_detect
  li    $t6, 1
  lui   $at, %hi(controller_1_rumble_state)
  sw    $t6, %lo(controller_1_rumble_state)($at)
  lui   $at, %hi(controller_1_rumble_pulse)
  sw    $zero, %lo(controller_1_rumble_pulse)($at)
  lui   $at, %hi(controller_2_rumble_state)
  li    $t7, 1
  sw    $t7, %lo(controller_2_rumble_state)($at)
  lui   $at, %hi(controller_2_rumble_pulse)
  sw    $zero, %lo(controller_2_rumble_pulse)($at)
  lui   $at, %hi(controller_3_rumble_state)
  li    $t8, 1
  sw    $t8, %lo(controller_3_rumble_state)($at)
  lui   $at, %hi(controller_3_rumble_pulse)
  sw    $zero, %lo(controller_3_rumble_pulse)($at)
  lui   $at, %hi(controller_4_rumble_state)
  li    $t9, 1
  sw    $t9, %lo(controller_4_rumble_state)($at)
  lui   $at, %hi( controller_4_rumble_pulse)
  jr    $ra
   sw    $zero, %lo( controller_4_rumble_pulse)($at)
");
#endif

#ifdef VERSION_JP
asm(R"
glabel reset_cont_rumble_detect
  lui   $at, %hi(controller_1_rumble_pulse)
  li    $t7, 2
  li    $t6, 2
  sw    $t7, %lo(controller_2_rumble_pulse)($at)
  sw    $t6, %lo(controller_1_rumble_pulse)($at)
  lui   $at, %hi(controller_3_rumble_pulse)
  li    $t8, 2
  li    $t9, 2
  sw    $t9, %lo(controller_4_rumble_pulse)($at)
  jr    $ra
   sw    $t8, %lo( controller_3_rumble_pulse)($at)
");
#endif

void controller_7000C930(int arg0) {
  ptr_current_point_in_controller_input_index =
      (arg0 * 508) + controller_input_index;
}

int controller_7000C954(void) {
  return (ptr_current_point_in_controller_input_index -
          controller_input_index) /
         508;
}
