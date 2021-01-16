#include "indy_commands.h"

int D_8004EAC0 = 0;
int indy_status = 0x103;
int indy_ready = 0;
int D_8004EACC = 0x0;
int D_8004EAD0 = 0x0;

asm(R"
glabel sub_GAME_7F0D0180
  addiu $sp, $sp, -0x18
  lui   $v1, (0x000186A0 >> 16) # lui $v1, 1
  sw    $ra, 0x14($sp)
  ori   $v1, (0x000186A0 & 0xFFFF) # ori $v1, $v1, 0x86a0
  move  $v0, $zero
  addiu $v0, $v0, 4
.L7F0D0198:
  bnel  $v0, $v1, .L7F0D0198
   addiu $v0, $v0, 4
  jal   rmon_debug_stub_0
   nop   
  lui   $v1, (0x000186A0 >> 16) # lui $v1, 1
  ori   $v1, (0x000186A0 & 0xFFFF) # ori $v1, $v1, 0x86a0
  move  $v0, $zero
  addiu $v0, $v0, 4
.L7F0D01B8:
  bnel  $v0, $v1, .L7F0D01B8
   addiu $v0, $v0, 4
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0D01D0
  addiu $sp, $sp, -0x18
  lui   $v1, (0x000186A0 >> 16) # lui $v1, 1
  sw    $ra, 0x14($sp)
  ori   $v1, (0x000186A0 & 0xFFFF) # ori $v1, $v1, 0x86a0
  move  $v0, $zero
  addiu $v0, $v0, 4
.L7F0D01E8:
  bnel  $v0, $v1, .L7F0D01E8
   addiu $v0, $v0, 4
  jal   rmon_debug_stub
   nop   
  lui   $v1, (0x000186A0 >> 16) # lui $v1, 1
  ori   $v1, (0x000186A0 & 0xFFFF) # ori $v1, $v1, 0x86a0
  move  $v0, $zero
  addiu $v0, $v0, 4
.L7F0D0208:
  bnel  $v0, $v1, .L7F0D0208
   addiu $v0, $v0, 4
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel postindyresourcecommand
  addiu $sp, $sp, -0x540
  addiu $v0, $sp, 0x40
  andi  $t7, $a0, 7
  sw    $ra, 0x14($sp)
  sw    $a0, 0x540($sp)
  move  $a2, $a1
  move  $v1, $v0
  beqz  $t7, .L7F0D02EC
   move  $a3, $v0
  sltiu $at, $a1, 0x501
  bnez  $at, .L7F0D0258
   andi  $t8, $v0, 7
  b     .L7F0D0348
   move  $v0, $zero
.L7F0D0258:
  beqz  $t8, .L7F0D0268
   lui   $t0, %hi(indy_status) 
  addiu $a3, $sp, 0x44
  move  $v1, $a3
.L7F0D0268:
  addu  $a0, $v1, $a2
  sltu  $at, $v1, $a0
  beqz  $at, .L7F0D0290
   lw    $v0, 0x540($sp)
.L7F0D0278:
  lbu   $t9, ($v0)
  addiu $v1, $v1, 1
  sltu  $at, $v1, $a0
  addiu $v0, $v0, 1
  bnez  $at, .L7F0D0278
   sb    $t9, -1($v1)
.L7F0D0290:
  lw    $t0, %lo(indy_status)($t0)
  addiu $a1, $a2, 3
  li    $at, -4
  andi  $t1, $t0, 0x20
  beqz  $t1, .L7F0D02D8
   and   $t2, $a1, $at
  beqz  $a2, .L7F0D02D8
   move  $v0, $zero
  andi  $a0, $a2, 3
  beqz  $a0, .L7F0D02CC
   move  $v1, $a0
  addiu $v0, $v0, 1
.L7F0D02C0:
  bnel  $v1, $v0, .L7F0D02C0
   addiu $v0, $v0, 1
  beq   $v0, $a2, .L7F0D02D8
.L7F0D02CC:
   addiu $v0, $v0, 4
.L7F0D02D0:
  bnel  $v0, $a2, .L7F0D02D0
   addiu $v0, $v0, 4
.L7F0D02D8:
  move  $a0, $a3
  jal   sub_GAME_7F0D01D0
   move  $a1, $t2
  b     .L7F0D0348
   li    $v0, 1
.L7F0D02EC:
  lui   $t3, %hi(indy_status) 
  lw    $t3, %lo(indy_status)($t3)
  addiu $a1, $a2, 3
  li    $at, -4
  andi  $t4, $t3, 0x20
  beqz  $t4, .L7F0D0338
   and   $t5, $a1, $at
  beqz  $a2, .L7F0D0338
   move  $v0, $zero
  andi  $a0, $a2, 3
  beqz  $a0, .L7F0D032C
   move  $v1, $a0
  addiu $v0, $v0, 1
.L7F0D0320:
  bnel  $v1, $v0, .L7F0D0320
   addiu $v0, $v0, 1
  beq   $v0, $a2, .L7F0D0338
.L7F0D032C:
   addiu $v0, $v0, 4
.L7F0D0330:
  bnel  $v0, $a2, .L7F0D0330
   addiu $v0, $v0, 4
.L7F0D0338:
  lw    $a0, 0x540($sp)
  jal   sub_GAME_7F0D01D0
   move  $a1, $t5
  li    $v0, 1
.L7F0D0348:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x540
  jr    $ra
   nop   
");

unsigned int send2indyresourcecommands(struct indy_resource_entry *entry1,
                                       unsigned int size1,
                                       struct indy_resource_entry *entry2,
                                       unsigned int size2) {
  postindyresourcecommand(entry1, size1);
  postindyresourcecommand(entry2, size2);
  return 1;
}

void post_type1_indyrescmd_sizenextcmd(int readsize, int writesize) {
  struct indy_resource_entry cmd;
  cmd.resourceID = 0x9abf1623;
  cmd.type = 1;
  cmd.size = 0x14;
  cmd.readsize = readsize;
  cmd.writesize = writesize;
  postindyresourcecommand(&cmd, 0x14);
}

void post_type2_indyrescmd_cmds_rdy_to_proc(int readsize, int writesize) {
  struct indy_resource_entry cmd;
  cmd.resourceID = 0x9abf1623;
  cmd.type = 2;
  cmd.size = 0x14;
  cmd.readsize = readsize;
  cmd.writesize = writesize;
  postindyresourcecommand(&cmd, 0x14);
}

void post_type0_indyrescmd_init(int readsize, int writesize) {
  struct indy_resource_entry cmd;
  cmd.resourceID = 0x9abf1623;
  cmd.type = 0;
  cmd.size = 0x14;
  cmd.readsize = readsize;
  cmd.writesize = writesize;
  postindyresourcecommand(&cmd, 0x14);
}

asm(R"
glabel post_type3_indyrescmd
  addiu $sp, $sp, -304
  sw    $a1, 308($sp)
  lui   $t6, (0x9ABF1623 >> 16) # lui $t6, 0x9abf
  sw    $a1, 44($sp)
  sw    $ra, 20($sp)
  sw    $a2, 312($sp)
  ori   $t6, (0x9ABF1623 & 0xFFFF) # ori $t6, $t6, 0x1623
  li    $t7, 3
  li    $t8, 276
  sw    $a0, 40($sp)
  move  $a1, $a2
  sw    $t6, 28($sp)
  sw    $t7, 32($sp)
  sw    $t8, 36($sp)
  li    $a2, 256
  jal   something_with_strings
  addiu $a0, $sp, 48
  sb    $zero, 303($sp)
  addiu $a0, $sp, 28
  jal   postindyresourcecommand
  li    $a1, 276
  lw    $ra, 20($sp)
  addiu $sp, $sp, 304
  jr    $ra
  nop   
");
/*
void post_type3_indyrescmd(int rsize,int wsize,char *strptr)
{
    struct indy_resource_entry_type3 cmd;
    cmd.entry.resourceID = 0x9abf1623;
    cmd.entry.type = 3;
    cmd.entry.size = 0x114;
    cmd.entry.readsize = rsize;
    cmd.entry.writesize = wsize;
    something_with_strings(cmd.strbuffer,strptr,0x100);
    cmd.strbuffer[255] = '\0';
    postindyresourcecommand(&cmd.entry,0x114);
}
*/

void post_type4_indyrescmd_data_recieved(int readsize, int writesize,
                                         int data) {
  struct indy_resource_entry_type4 cmd;
  cmd.entry.resourceID = 0x9abf1623;
  cmd.entry.type = 4;
  cmd.entry.size = 0x18;
  cmd.entry.readsize = readsize;
  cmd.entry.writesize = writesize;
  cmd.data = data;
  postindyresourcecommand(&cmd.entry, 0x18);
}

asm(R"
glabel post_type5_indyrescmd_printfsend
  addiu $sp, $sp, -0x130
  sw    $a1, 0x134($sp)
  lui   $t6, (0x9ABF1623 >> 16) # lui $t6, 0x9abf
  sw    $a1, 0x2c($sp)
  sw    $ra, 0x14($sp)
  sw    $a2, 0x138($sp)
  ori   $t6, (0x9ABF1623 & 0xFFFF) # ori $t6, $t6, 0x1623
  li    $t7, 5
  li    $t8, 276
  sw    $a0, 0x28($sp)
  move  $a1, $a2
  sw    $t6, 0x1c($sp)
  sw    $t7, 0x20($sp)
  sw    $t8, 0x24($sp)
  li    $a2, 256
  jal   something_with_strings
   addiu $a0, $sp, 0x30
  sb    $zero, 0x12f($sp)
  addiu $a0, $sp, 0x1c
  jal   postindyresourcecommand
   li    $a1, 276
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x130
  jr    $ra
   nop   
");

void post_type6_indyrescmd_printfrecieved(int readsize, int writesize,
                                          unsigned int data1,
                                          unsigned int data2) {
  struct indy_resource_entry_type6 cmd;
  cmd.entry.resourceID = 0x9abf1623;
  cmd.entry.type = 6;
  cmd.entry.size = 0x1c;
  cmd.entry.readsize = readsize;
  cmd.entry.writesize = writesize;
  cmd.data1 = data1;
  cmd.data2 = data2;
  postindyresourcecommand(&cmd.entry, 0x1c);
}

asm(R"
glabel post_type7_indyrescmd_log_send
  addiu $sp, $sp, -0x130
  sw    $a1, 0x134($sp)
  lui   $t6, (0x9ABF1623 >> 16) # lui $t6, 0x9abf
  sw    $a1, 0x28($sp)
  sw    $ra, 0x14($sp)
  sw    $a0, 0x130($sp)
  sw    $a2, 0x138($sp)
  ori   $t6, (0x9ABF1623 & 0xFFFF) # ori $t6, $t6, 0x1623
  li    $t7, 7
  li    $t8, 280
  sw    $a0, 0x24($sp)
  move  $a1, $a2
  sw    $a3, 0x13c($sp)
  sw    $t6, 0x18($sp)
  sw    $t7, 0x1c($sp)
  sw    $t8, 0x20($sp)
  li    $a2, 256
  jal   something_with_strings
   addiu $a0, $sp, 0x2c
  lw    $t1, 0x13c($sp)
  sb    $zero, 0x12b($sp)
  addiu $a0, $sp, 0x18
  li    $a1, 280
  jal   postindyresourcecommand
   sw    $t1, 0x12c($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x130
  jr    $ra
   nop   
");

asm(R"
glabel post_type8_indyrescmd_log_recieved
  addiu $sp, $sp, -0x38
  sw    $a3, 0x44($sp)
  lw    $a3, 0x48($sp)
  li    $at, -4
  lw    $t4, 0x44($sp)
  addiu $t8, $a3, 3
  lui   $t6, (0x9ABF1623 >> 16) # lui $t6, 0x9abf
  and   $t9, $t8, $at
  sw    $ra, 0x14($sp)
  sw    $a0, 0x38($sp)
  sw    $a1, 0x3c($sp)
  sw    $a2, 0x40($sp)
  ori   $t6, (0x9ABF1623 & 0xFFFF) # ori $t6, $t6, 0x1623
  li    $t7, 8
  addiu $t0, $t9, 0x20
  sw    $a0, 0x24($sp)
  sw    $a1, 0x28($sp)
  sw    $a2, 0x2c($sp)
  sw    $t6, 0x18($sp)
  sw    $t7, 0x1c($sp)
  sw    $t0, 0x20($sp)
  lw    $a2, 0x4c($sp)
  li    $a1, 32
  addiu $a0, $sp, 0x18
  sw    $a3, 0x34($sp)
  jal   send2indyresourcecommands
   sw    $t4, 0x30($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   
");

asm(R"
glabel post_type9_indyrescmd_app_command_ready
  addiu $sp, $sp, -0x130
  addiu $t9, $a3, 3
  li    $at, -4
  sw    $a1, 0x134($sp)
  lui   $t6, (0x9ABF1623 >> 16) # lui $t6, 0x9abf
  and   $t0, $t9, $at
  sw    $a1, 0x2c($sp)
  sw    $ra, 0x14($sp)
  sw    $a0, 0x130($sp)
  sw    $a2, 0x138($sp)
  ori   $t6, (0x9ABF1623 & 0xFFFF) # ori $t6, $t6, 0x1623
  li    $t7, 9
  addiu $t1, $t0, 0x114
  sw    $a0, 0x28($sp)
  move  $a1, $a2
  sw    $a3, 0x13c($sp)
  sw    $t6, 0x1c($sp)
  sw    $t7, 0x20($sp)
  sw    $t1, 0x24($sp)
  li    $a2, 256
  jal   something_with_strings
   addiu $a0, $sp, 0x30
  sb    $zero, 0x12f($sp)
  addiu $a0, $sp, 0x1c
  li    $a1, 276
  lw    $a2, 0x140($sp)
  jal   send2indyresourcecommands
   lw    $a3, 0x13c($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x130
  jr    $ra
   nop   
");

void post_typeA_indyrescmd_app_command_recieved(int readsize, int writesize,
                                                unsigned int data) {
  struct indy_resource_entry_type4 cmd;
  cmd.entry.resourceID = 0x9abf1623;
  cmd.entry.type = 10;
  cmd.entry.size = 0x18;
  cmd.entry.readsize = readsize;
  cmd.entry.writesize = writesize;
  cmd.data = data;
  postindyresourcecommand(&cmd.entry, 0x18);
}

asm(R"
glabel post_typeF_indyrescmd_fault_send
  addiu $sp, $sp, -0x138
  sw    $a1, 0x13c($sp)
  lui   $t6, (0x9ABF1623 >> 16) # lui $t6, 0x9abf
  sw    $a1, 0x2c($sp)
  sw    $ra, 0x14($sp)
  sw    $a0, 0x138($sp)
  sw    $a2, 0x140($sp)
  ori   $t6, (0x9ABF1623 & 0xFFFF) # ori $t6, $t6, 0x1623
  li    $t7, 15
  li    $t8, 284
  sw    $a0, 0x28($sp)
  move  $a1, $a2
  sw    $a3, 0x144($sp)
  sw    $t6, 0x1c($sp)
  sw    $t7, 0x20($sp)
  sw    $t8, 0x24($sp)
  li    $a2, 256
  jal   something_with_strings
   addiu $a0, $sp, 0x30
  lw    $t1, 0x144($sp)
  lw    $t2, 0x148($sp)
  sb    $zero, 0x12f($sp)
  addiu $a0, $sp, 0x1c
  li    $a1, 284
  sw    $t1, 0x130($sp)
  jal   postindyresourcecommand
   sw    $t2, 0x134($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x138
  jr    $ra
   nop   
");

asm(R"
glabel post_type10_indyrescmd_fault_ack_by_host
  addiu $sp, $sp, -0x38
  lw    $t1, 0x48($sp)
  lui   $t6, (0x9ABF1623 >> 16) # lui $t6, 0x9abf
  sw    $ra, 0x14($sp)
  sw    $a0, 0x38($sp)
  sw    $a1, 0x3c($sp)
  ori   $t6, (0x9ABF1623 & 0xFFFF) # ori $t6, $t6, 0x1623
  li    $t7, 16
  li    $t8, 32
  sw    $a0, 0x24($sp)
  sw    $a1, 0x28($sp)
  sw    $t6, 0x18($sp)
  sw    $t7, 0x1c($sp)
  sw    $t8, 0x20($sp)
  sw    $a2, 0x2c($sp)
  sw    $a3, 0x30($sp)
  li    $a1, 32
  addiu $a0, $sp, 0x18
  jal   postindyresourcecommand
   sw    $t1, 0x34($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   
");

asm(R"
glabel post_typeD_indyrescmd_prof_send_filename
  addiu $sp, $sp, -0x138
  sw    $a1, 0x13c($sp)
  lui   $t6, (0x9ABF1623 >> 16) # lui $t6, 0x9abf
  sw    $a1, 0x2c($sp)
  sw    $ra, 0x14($sp)
  sw    $a0, 0x138($sp)
  sw    $a2, 0x140($sp)
  ori   $t6, (0x9ABF1623 & 0xFFFF) # ori $t6, $t6, 0x1623
  li    $t7, 13
  li    $t8, 284
  sw    $a0, 0x28($sp)
  move  $a1, $a2
  sw    $a3, 0x144($sp)
  sw    $t6, 0x1c($sp)
  sw    $t7, 0x20($sp)
  sw    $t8, 0x24($sp)
  li    $a2, 256
  jal   something_with_strings
   addiu $a0, $sp, 0x30
  lw    $t1, 0x144($sp)
  lw    $t2, 0x148($sp)
  sb    $zero, 0x12f($sp)
  addiu $a0, $sp, 0x1c
  li    $a1, 284
  sw    $t1, 0x130($sp)
  jal   postindyresourcecommand
   sw    $t2, 0x134($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x138
  jr    $ra
   nop   
");

void post_typeE_indyrescmd_prof_recv(int readsize, int writesize,
                                     unsigned int data) {
  struct indy_resource_entry_type4 cmd;
  cmd.entry.resourceID = 0x9abf1623;
  cmd.entry.type = 0xe;
  cmd.entry.size = 0x18;
  cmd.entry.readsize = readsize;
  cmd.entry.writesize = writesize;
  cmd.data = data;
  postindyresourcecommand(&cmd.entry, 0x18);
}

asm(R"
glabel post_typeB_indyrescmd_host_prof_req
  addiu $sp, $sp, -0x430
  sw    $a1, 0x434($sp)
  lui   $t6, (0x9ABF1623 >> 16) # lui $t6, 0x9abf
  sw    $a1, 0x2c($sp)
  sw    $ra, 0x14($sp)
  sw    $a2, 0x438($sp)
  ori   $t6, (0x9ABF1623 & 0xFFFF) # ori $t6, $t6, 0x1623
  li    $t7, 11
  li    $t8, 1044
  sw    $a0, 0x28($sp)
  move  $a1, $a2
  sw    $t6, 0x1c($sp)
  sw    $t7, 0x20($sp)
  sw    $t8, 0x24($sp)
  li    $a2, 1024
  jal   something_with_strings
   addiu $a0, $sp, 0x30
  sb    $zero, 0x42f($sp)
  addiu $a0, $sp, 0x1c
  jal   postindyresourcecommand
   li    $a1, 1044
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x430
  jr    $ra
   nop   
");

void post_typeC_indyrescmd_prof_send(int readsize, int writesize,
                                     unsigned int data) {
  struct indy_resource_entry_type4 cmd;
  cmd.entry.resourceID = 0x9abf1623;
  cmd.entry.type = 0xc;
  cmd.entry.size = 0x18;
  cmd.entry.readsize = readsize;
  cmd.entry.writesize = writesize;
  cmd.data = data;
  postindyresourcecommand(&cmd.entry, 0x18);
}

void post_typeA_indyrescmd_app_data_recieved(int readsize, int writesize,
                                             unsigned int data) {
  struct indy_resource_entry_type4 cmd;
  cmd.entry.resourceID = 0x9abf1623;
  cmd.entry.type = 10;
  cmd.entry.size = 0x18;
  cmd.entry.readsize = readsize;
  cmd.entry.writesize = writesize;
  cmd.data = data;
  postindyresourcecommand(&cmd.entry, 0x18);
}

unsigned int post_indy__res_cmd_initialize_seq(void) {
  post_type1_indyrescmd_sizenextcmd(0x14, 0x14);
  post_type0_indyrescmd_init(0x14, 0x14);
  post_type2_indyrescmd_cmds_rdy_to_proc(0, 0);
  return 1;
}

unsigned int post_indyrescmd_game_data_send(char *strptr) {
  post_type1_indyrescmd_sizenextcmd(0x114, 0x114);
  post_type3_indyrescmd(0x14, 0x14, strptr);
  post_type2_indyrescmd_cmds_rdy_to_proc(0, 0);
  return 1;
}

unsigned int post_indyrescmd_debug_data_recv(unsigned int data) {
  post_type1_indyrescmd_sizenextcmd(0x18, 0x18);
  post_type4_indyrescmd_data_recieved(0x14, 0x14, data);
  post_type2_indyrescmd_cmds_rdy_to_proc(0, 0);
  return 1;
}

unsigned int post_indyrescmd_game_printf_send(char *strptr) {
  post_type1_indyrescmd_sizenextcmd(0x114, 0x114);
  post_type5_indyrescmd_printfsend(0x14, 0x14, strptr);
  post_type2_indyrescmd_cmds_rdy_to_proc(0, 0);
  return 1;
}

unsigned int post_indyrescmd_debug_printf_recv(unsigned int data1,
                                               unsigned int data2) {
  post_type1_indyrescmd_sizenextcmd(0x1c, 0x1c);
  post_type6_indyrescmd_printfrecieved(0x14, 0x14, data1, data2);
  post_type2_indyrescmd_cmds_rdy_to_proc(0, 0);
  return 1;
}

unsigned int post_indyrescmd_req_filename_size(unsigned char *filename,
                                               unsigned int size) {
  post_type1_indyrescmd_sizenextcmd(0x118, 0x118);
  post_type7_indyrescmd_log_send(0x14, 0x14, filename, size);
  post_type2_indyrescmd_cmds_rdy_to_proc(0, 0);
  return 1;
}

unsigned int post_indyrescmd_1_8_2(unsigned int data1, unsigned int data2,
                                   unsigned int size2,
                                   struct indy_resource_entry *cmd2) {
  post_type1_indyrescmd_sizenextcmd((size2 + 3 & 0xfffffffc) + 0x20, 0x20);
  post_type8_indyrescmd_log_recieved(0x14, 0x14, data1, data2, size2, cmd2);
  post_type2_indyrescmd_cmds_rdy_to_proc(0, 0);
  return 1;
}

unsigned int
post_indyrescmd_send_capture_data(char *string, unsigned int size,
                                  struct indy_resource_entry *data) {
  post_type1_indyrescmd_sizenextcmd((size + 3 & 0xfffffffc) + 0x114, 0x114);
  post_type9_indyrescmd_app_command_ready(0x14, 0x14, string, size, data);
  post_type2_indyrescmd_cmds_rdy_to_proc(0, 0);
  return 1;
}

unsigned int post_indyrescmd_recv_capture_data_success(unsigned int data) {
  post_type1_indyrescmd_sizenextcmd(0x18, 0x18);
  post_typeA_indyrescmd_app_command_recieved(0x14, 0x14, data);
  post_type2_indyrescmd_cmds_rdy_to_proc(0, 0);
  return 1;
}

unsigned int post_indyrescmd_request_ramrom_file(char *strptr,
                                                 unsigned int ptarget,
                                                 unsigned int filesize) {
  post_type1_indyrescmd_sizenextcmd(0x11c, 0x11c);
  post_typeF_indyrescmd_fault_send(0x14, 0x14, strptr, filesize, ptarget);
  post_type2_indyrescmd_cmds_rdy_to_proc(0, 0);
  return 1;
}

unsigned int post_indyrescmd_1_10_2(unsigned int param_1, unsigned int param_2,
                                    unsigned int param_3) {
  post_type1_indyrescmd_sizenextcmd(0x20, 0x20);
  post_type10_indyrescmd_fault_ack_by_host(0x14, 0x14, param_1, param_2,
                                           param_3);
  post_type2_indyrescmd_cmds_rdy_to_proc(0, 0);
  return 1;
}

unsigned int post_indyrescmd_game_prof_sendfile(char *strptr,
                                                unsigned char *phwaddr,
                                                unsigned int size) {
  post_type1_indyrescmd_sizenextcmd(0x11c, 0x11c);
  post_typeD_indyrescmd_prof_send_filename(0x14, 0x14, strptr, size, phwaddr);
  post_type2_indyrescmd_cmds_rdy_to_proc(0, 0);
  return 1;
}

unsigned int post_indyrescmd_host_prof_recv(unsigned int data) {
  post_type1_indyrescmd_sizenextcmd(0x18, 0x18);
  post_typeE_indyrescmd_prof_recv(0x14, 0x14, data);
  post_type2_indyrescmd_cmds_rdy_to_proc(0, 0);
  return 1;
}

unsigned int post_indyrescmd_1_B_2(char *strptr) {
  post_type1_indyrescmd_sizenextcmd(0x414, 0x414);
  post_typeB_indyrescmd_host_prof_req(0x14, 0x14, strptr);
  post_type2_indyrescmd_cmds_rdy_to_proc(0, 0);
  return 1;
}

unsigned int post_indyrescmd_1_C_2(unsigned int data) {
  post_type1_indyrescmd_sizenextcmd(0x18, 0x18);
  post_typeC_indyrescmd_prof_send(0x14, 0x14, data);
  post_type2_indyrescmd_cmds_rdy_to_proc(0, 0);
  return 1;
}

unsigned int post_indyrescmd_1_A_2(unsigned int data) {
  post_type1_indyrescmd_sizenextcmd(0x18, 0x18);
  post_typeA_indyrescmd_app_data_recieved(0x14, 0x14, data);
  post_type2_indyrescmd_cmds_rdy_to_proc(0, 0);
  return 1;
}

asm(R"
glabel post_indyrescmd_read_command
  addiu $sp, $sp, -0x440
  addiu $v0, $sp, 0x40
  andi  $t7, $a0, 7
  sw    $ra, 0x14($sp)
  sw    $a0, 0x440($sp)
  move  $a2, $a1
  move  $v1, $v0
  beqz  $t7, .L7F0D1030
   move  $a3, $v0
  sltiu $at, $a1, 0x401
  bnez  $at, .L7F0D0F84
   andi  $t8, $v0, 7
  b     .L7F0D1098
   move  $v0, $zero
.L7F0D0F84:
  beqz  $t8, .L7F0D0F94
   addiu $a1, $a2, 3
  addiu $v1, $sp, 0x44
  move  $a3, $v1
.L7F0D0F94:
  li    $at, -4
  and   $t9, $a1, $at
  move  $a1, $t9
  move  $a0, $a3
  sw    $v1, 0x3c($sp)
  jal   sub_GAME_7F0D0180
   sw    $a2, 0x444($sp)
  lw    $v1, 0x3c($sp)
  lw    $a2, 0x444($sp)
  lw    $v0, 0x440($sp)
  lui   $t1, %hi(indy_status) 
  addu  $a0, $v1, $a2
  sltu  $at, $v1, $a0
  beqz  $at, .L7F0D0FE8
   nop   
.L7F0D0FD0:
  lbu   $t0, ($v1)
  addiu $v1, $v1, 1
  sltu  $at, $v1, $a0
  addiu $v0, $v0, 1
  bnez  $at, .L7F0D0FD0
   sb    $t0, -1($v0)
.L7F0D0FE8:
  lw    $t1, %lo(indy_status)($t1)
  andi  $t2, $t1, 0x10
  beqz  $t2, .L7F0D1028
   nop   
  beqz  $a2, .L7F0D1028
   move  $v0, $zero
  andi  $a0, $a2, 3
  beqz  $a0, .L7F0D101C
   move  $v1, $a0
  addiu $v0, $v0, 1
.L7F0D1010:
  bnel  $v1, $v0, .L7F0D1010
   addiu $v0, $v0, 1
  beq   $v0, $a2, .L7F0D1028
.L7F0D101C:
   addiu $v0, $v0, 4
.L7F0D1020:
  bnel  $v0, $a2, .L7F0D1020
   addiu $v0, $v0, 4
.L7F0D1028:
  b     .L7F0D1098
   li    $v0, 1
.L7F0D1030:
  addiu $a1, $a2, 3
  li    $at, -4
  and   $t3, $a1, $at
  move  $a1, $t3
  lw    $a0, 0x440($sp)
  jal   sub_GAME_7F0D0180
   sw    $a2, 0x444($sp)
  lui   $t4, %hi(indy_status) 
  lw    $t4, %lo(indy_status)($t4)
  lw    $a2, 0x444($sp)
  andi  $t5, $t4, 0x10
  beql  $t5, $zero, .L7F0D1098
   li    $v0, 1
  beqz  $a2, .L7F0D1094
   move  $v0, $zero
  andi  $a0, $a2, 3
  beqz  $a0, .L7F0D1088
   move  $v1, $a0
  addiu $v0, $v0, 1
.L7F0D107C:
  bnel  $v1, $v0, .L7F0D107C
   addiu $v0, $v0, 1
  beq   $v0, $a2, .L7F0D1094
.L7F0D1088:
   addiu $v0, $v0, 4
.L7F0D108C:
  bnel  $v0, $a2, .L7F0D108C
   addiu $v0, $v0, 4
.L7F0D1094:
  li    $v0, 1
.L7F0D1098:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x440
  jr    $ra
   nop   
");

unsigned int post_indyrescmd_read_2commands(unsigned char *buffer1,
                                            unsigned int size1,
                                            unsigned char *buffer2,
                                            unsigned int size2) {
  sub_GAME_7F0D0180(buffer1, size1 + 3 & 0xfffffffc);
  sub_GAME_7F0D0180(buffer2, size2 + 3 & 0xfffffffc);
  return 1;
}

asm(R"
glabel post_indyrescmd_istype1_correctsize
  addiu $sp, $sp, -0x30
  sw    $ra, 0x14($sp)
  sw    $a0, 0x30($sp)
  sw    $a1, 0x34($sp)
  li    $a1, 20
  jal   post_indyrescmd_read_command
   addiu $a0, $sp, 0x1c
  lw    $t6, 0x1c($sp)
  lui   $at, (0x9ABF1623 >> 16) # lui $at, 0x9abf
  ori   $at, (0x9ABF1623 & 0xFFFF) # ori $at, $at, 0x1623
  beq   $t6, $at, .L7F0D1138
   lw    $v0, 0x30($sp)
  b     .L7F0D119C
   move  $v0, $zero
.L7F0D1138:
  lw    $t7, 0x20($sp)
  li    $at, 1
  lw    $t8, 0x24($sp)
  beql  $t7, $at, .L7F0D1158
   li    $at, 20
  b     .L7F0D119C
   move  $v0, $zero
  li    $at, 20
.L7F0D1158:
  beq   $t8, $at, .L7F0D1168
   nop   
  b     .L7F0D119C
   move  $v0, $zero
.L7F0D1168:
  beqz  $v0, .L7F0D1180
   lw    $t9, 0x28($sp)
  beql  $t9, $v0, .L7F0D1184
   lw    $t0, 0x2c($sp)
  b     .L7F0D119C
   move  $v0, $zero
.L7F0D1180:
  lw    $t0, 0x2c($sp)
.L7F0D1184:
  lw    $t1, 0x34($sp)
  li    $v0, 1
  beq   $t0, $t1, .L7F0D119C
   nop   
  b     .L7F0D119C
   move  $v0, $zero
.L7F0D119C:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
glabel post_indyrescmd_istype2_correctvalue
  addiu $sp, $sp, -0x30
  sw    $ra, 0x14($sp)
  sw    $a0, 0x30($sp)
  sw    $a1, 0x34($sp)
  li    $a1, 20
  jal   post_indyrescmd_read_command
   addiu $a0, $sp, 0x1c
  lw    $t6, 0x1c($sp)
  lui   $at, (0x9ABF1623 >> 16) # lui $at, 0x9abf
  ori   $at, (0x9ABF1623 & 0xFFFF) # ori $at, $at, 0x1623
  beq   $t6, $at, .L7F0D11E4
   lw    $ra, 0x14($sp)
  b     .L7F0D1240
   move  $v0, $zero
.L7F0D11E4:
  lw    $t7, 0x20($sp)
  li    $at, 2
  lw    $t8, 0x24($sp)
  beql  $t7, $at, .L7F0D1204
   li    $at, 20
  b     .L7F0D1240
   move  $v0, $zero
  li    $at, 20
.L7F0D1204:
  beq   $t8, $at, .L7F0D1214
   lw    $t9, 0x28($sp)
  b     .L7F0D1240
   move  $v0, $zero
.L7F0D1214:
  lw    $t0, 0x30($sp)
  lw    $t1, 0x2c($sp)
  lw    $t2, 0x34($sp)
  beq   $t9, $t0, .L7F0D1230
   nop   
  b     .L7F0D1240
   move  $v0, $zero
.L7F0D1230:
  beq   $t1, $t2, .L7F0D1240
   li    $v0, 1
  b     .L7F0D1240
   move  $v0, $zero
.L7F0D1240:
  jr    $ra
   addiu $sp, $sp, 0x30
");

asm(R"
glabel post_indyrescmd_istype4_correctvalue
  addiu $sp, $sp, -0x30
  sw    $ra, 0x14($sp)
  sw    $a0, 0x30($sp)
  sw    $a1, 0x34($sp)
  sw    $a2, 0x38($sp)
  li    $a1, 24
  jal   post_indyrescmd_read_command
   addiu $a0, $sp, 0x18
  lw    $t6, 0x18($sp)
  lui   $at, (0x9ABF1623 >> 16) # lui $at, 0x9abf
  ori   $at, (0x9ABF1623 & 0xFFFF) # ori $at, $at, 0x1623
  beq   $t6, $at, .L7F0D1284
   lw    $t7, 0x1c($sp)
  b     .L7F0D12E4
   move  $v0, $zero
.L7F0D1284:
  li    $at, 4
  beq   $t7, $at, .L7F0D1298
   lw    $t8, 0x20($sp)
  b     .L7F0D12E4
   move  $v0, $zero
.L7F0D1298:
  li    $at, 24
  beq   $t8, $at, .L7F0D12AC
   lw    $t9, 0x24($sp)
  b     .L7F0D12E4
   move  $v0, $zero
.L7F0D12AC:
  lw    $t0, 0x30($sp)
  lw    $t1, 0x28($sp)
  lw    $t2, 0x34($sp)
  beq   $t9, $t0, .L7F0D12C8
   nop   
  b     .L7F0D12E4
   move  $v0, $zero
.L7F0D12C8:
  beq   $t1, $t2, .L7F0D12D8
   lw    $t3, 0x2c($sp)
  b     .L7F0D12E4
   move  $v0, $zero
.L7F0D12D8:
  lw    $t4, 0x38($sp)
  li    $v0, 1
  sw    $t3, ($t4)
.L7F0D12E4:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
glabel post_indyrescmd_istype6_correctvalue
  addiu $sp, $sp, -0x38
  sw    $ra, 0x14($sp)
  sw    $a0, 0x38($sp)
  sw    $a1, 0x3c($sp)
  sw    $a2, 0x40($sp)
  sw    $a3, 0x44($sp)
  li    $a1, 28
  jal   post_indyrescmd_read_command
   addiu $a0, $sp, 0x1c
  lw    $t6, 0x1c($sp)
  lui   $at, (0x9ABF1623 >> 16) # lui $at, 0x9abf
  ori   $at, (0x9ABF1623 & 0xFFFF) # ori $at, $at, 0x1623
  beq   $t6, $at, .L7F0D1334
   lw    $t7, 0x20($sp)
  b     .L7F0D13A0
   move  $v0, $zero
.L7F0D1334:
  li    $at, 6
  beq   $t7, $at, .L7F0D1348
   lw    $t8, 0x24($sp)
  b     .L7F0D13A0
   move  $v0, $zero
.L7F0D1348:
  li    $at, 28
  beq   $t8, $at, .L7F0D135C
   lw    $t9, 0x28($sp)
  b     .L7F0D13A0
   move  $v0, $zero
.L7F0D135C:
  lw    $t0, 0x38($sp)
  lw    $t1, 0x2c($sp)
  lw    $t2, 0x3c($sp)
  beq   $t9, $t0, .L7F0D1378
   nop   
  b     .L7F0D13A0
   move  $v0, $zero
.L7F0D1378:
  beq   $t1, $t2, .L7F0D1388
   lw    $t3, 0x30($sp)
  b     .L7F0D13A0
   move  $v0, $zero
.L7F0D1388:
  lw    $t4, 0x40($sp)
  li    $v0, 1
  sw    $t3, ($t4)
  lw    $t6, 0x44($sp)
  lw    $t5, 0x34($sp)
  sw    $t5, ($t6)
.L7F0D13A0:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   
");

asm(R"
glabel post_indyrescmd_istype8_correctvalue
  addiu $sp, $sp, -0x38
  sw    $ra, 0x14($sp)
  sw    $a0, 0x38($sp)
  sw    $a1, 0x3c($sp)
  sw    $a2, 0x40($sp)
  sw    $a3, 0x44($sp)
  li    $a1, 32
  jal   post_indyrescmd_read_command
   addiu $a0, $sp, 0x18
  lw    $t6, 0x18($sp)
  lui   $at, (0x9ABF1623 >> 16) # lui $at, 0x9abf
  ori   $at, (0x9ABF1623 & 0xFFFF) # ori $at, $at, 0x1623
  beq   $t6, $at, .L7F0D13F0
   lw    $t7, 0x1c($sp)
  b     .L7F0D1488
   move  $v0, $zero
.L7F0D13F0:
  li    $at, 8
  beq   $t7, $at, .L7F0D1404
   lw    $t9, 0x34($sp)
  b     .L7F0D1488
   move  $v0, $zero
.L7F0D1404:
  lw    $t8, 0x20($sp)
  li    $v0, -4
  addiu $t0, $t9, 3
  and   $t1, $t0, $v0
  addiu $t2, $t1, 0x20
  beq   $t8, $t2, .L7F0D1428
   lw    $t3, 0x24($sp)
  b     .L7F0D1488
   move  $v0, $zero
.L7F0D1428:
  lw    $t4, 0x38($sp)
  lw    $t5, 0x28($sp)
  lw    $t6, 0x3c($sp)
  beq   $t3, $t4, .L7F0D1444
   nop   
  b     .L7F0D1488
   move  $v0, $zero
.L7F0D1444:
  beq   $t5, $t6, .L7F0D1454
   lw    $t7, 0x2c($sp)
  b     .L7F0D1488
   move  $v0, $zero
.L7F0D1454:
  lw    $t9, 0x40($sp)
  sw    $t7, ($t9)
  lw    $t1, 0x44($sp)
  lw    $t0, 0x30($sp)
  sw    $t0, ($t1)
  lw    $t8, 0x34($sp)
  lw    $t2, 0x48($sp)
  addiu $t3, $t8, 3
  sw    $t8, ($t2)
  lw    $a0, 0x4c($sp)
  jal   post_indyrescmd_read_command
   and   $a1, $t3, $v0
  li    $v0, 1
.L7F0D1488:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   
");

asm(R"
glabel post_indyrescmd_istypeA_correctvalue
  addiu $sp, $sp, -0x30
  sw    $ra, 0x14($sp)
  sw    $a0, 0x30($sp)
  sw    $a1, 0x34($sp)
  sw    $a2, 0x38($sp)
  li    $a1, 24
  jal   post_indyrescmd_read_command
   addiu $a0, $sp, 0x18
  lw    $t6, 0x18($sp)
  lui   $at, (0x9ABF1623 >> 16) # lui $at, 0x9abf
  ori   $at, (0x9ABF1623 & 0xFFFF) # ori $at, $at, 0x1623
  beq   $t6, $at, .L7F0D14D4
   lw    $t7, 0x1c($sp)
  b     .L7F0D1534
   move  $v0, $zero
.L7F0D14D4:
  li    $at, 10
  beq   $t7, $at, .L7F0D14E8
   lw    $t8, 0x20($sp)
  b     .L7F0D1534
   move  $v0, $zero
.L7F0D14E8:
  li    $at, 24
  beq   $t8, $at, .L7F0D14FC
   lw    $t9, 0x24($sp)
  b     .L7F0D1534
   move  $v0, $zero
.L7F0D14FC:
  lw    $t0, 0x30($sp)
  lw    $t1, 0x28($sp)
  lw    $t2, 0x34($sp)
  beq   $t9, $t0, .L7F0D1518
   nop   
  b     .L7F0D1534
   move  $v0, $zero
.L7F0D1518:
  beq   $t1, $t2, .L7F0D1528
   lw    $t3, 0x2c($sp)
  b     .L7F0D1534
   move  $v0, $zero
.L7F0D1528:
  lw    $t4, 0x38($sp)
  li    $v0, 1
  sw    $t3, ($t4)
.L7F0D1534:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
glabel post_indyrescmd_istype10_correctvalue
  addiu $sp, $sp, -0x38
  sw    $ra, 0x14($sp)
  sw    $a0, 0x38($sp)
  sw    $a1, 0x3c($sp)
  sw    $a2, 0x40($sp)
  sw    $a3, 0x44($sp)
  li    $a1, 32
  jal   post_indyrescmd_read_command
   addiu $a0, $sp, 0x18
  lw    $t6, 0x18($sp)
  lui   $at, (0x9ABF1623 >> 16) # lui $at, 0x9abf
  ori   $at, (0x9ABF1623 & 0xFFFF) # ori $at, $at, 0x1623
  beq   $t6, $at, .L7F0D1584
   lw    $t7, 0x1c($sp)
  b     .L7F0D15FC
   move  $v0, $zero
.L7F0D1584:
  li    $at, 16
  beq   $t7, $at, .L7F0D1598
   lw    $t8, 0x20($sp)
  b     .L7F0D15FC
   move  $v0, $zero
.L7F0D1598:
  li    $at, 32
  beq   $t8, $at, .L7F0D15AC
   lw    $t9, 0x24($sp)
  b     .L7F0D15FC
   move  $v0, $zero
.L7F0D15AC:
  lw    $t0, 0x38($sp)
  lw    $t1, 0x28($sp)
  lw    $t2, 0x3c($sp)
  beq   $t9, $t0, .L7F0D15C8
   nop   
  b     .L7F0D15FC
   move  $v0, $zero
.L7F0D15C8:
  beq   $t1, $t2, .L7F0D15D8
   lw    $t3, 0x2c($sp)
  b     .L7F0D15FC
   move  $v0, $zero
.L7F0D15D8:
  lw    $t4, 0x40($sp)
  li    $v0, 1
  sw    $t3, ($t4)
  lw    $t6, 0x44($sp)
  lw    $t5, 0x30($sp)
  sw    $t5, ($t6)
  lw    $t8, 0x48($sp)
  lw    $t7, 0x34($sp)
  sw    $t7, ($t8)
.L7F0D15FC:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   
");

asm(R"
glabel post_indyrescmd_istypeE_correctvalue
  addiu $sp, $sp, -0x30
  sw    $ra, 0x14($sp)
  sw    $a0, 0x30($sp)
  sw    $a1, 0x34($sp)
  sw    $a2, 0x38($sp)
  li    $a1, 24
  jal   post_indyrescmd_read_command
   addiu $a0, $sp, 0x18
  lw    $t6, 0x18($sp)
  lui   $at, (0x9ABF1623 >> 16) # lui $at, 0x9abf
  ori   $at, (0x9ABF1623 & 0xFFFF) # ori $at, $at, 0x1623
  beq   $t6, $at, .L7F0D1648
   lw    $t7, 0x1c($sp)
  b     .L7F0D16A8
   move  $v0, $zero
.L7F0D1648:
  li    $at, 14
  beq   $t7, $at, .L7F0D165C
   lw    $t8, 0x20($sp)
  b     .L7F0D16A8
   move  $v0, $zero
.L7F0D165C:
  li    $at, 24
  beq   $t8, $at, .L7F0D1670
   lw    $t9, 0x24($sp)
  b     .L7F0D16A8
   move  $v0, $zero
.L7F0D1670:
  lw    $t0, 0x30($sp)
  lw    $t1, 0x28($sp)
  lw    $t2, 0x34($sp)
  beq   $t9, $t0, .L7F0D168C
   nop   
  b     .L7F0D16A8
   move  $v0, $zero
.L7F0D168C:
  beq   $t1, $t2, .L7F0D169C
   lw    $t3, 0x2c($sp)
  b     .L7F0D16A8
   move  $v0, $zero
.L7F0D169C:
  lw    $t4, 0x38($sp)
  li    $v0, 1
  sw    $t3, ($t4)
.L7F0D16A8:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
glabel post_indyrescmd_istypeC_correctvalue
  addiu $sp, $sp, -0x30
  sw    $ra, 0x14($sp)
  sw    $a0, 0x30($sp)
  sw    $a1, 0x34($sp)
  sw    $a2, 0x38($sp)
  li    $a1, 24
  jal   post_indyrescmd_read_command
   addiu $a0, $sp, 0x18
  lw    $t6, 0x18($sp)
  lui   $at, (0x9ABF1623 >> 16) # lui $at, 0x9abf
  ori   $at, (0x9ABF1623 & 0xFFFF) # ori $at, $at, 0x1623
  beq   $t6, $at, .L7F0D16F4
   lw    $t7, 0x1c($sp)
  b     .L7F0D1754
   move  $v0, $zero
.L7F0D16F4:
  li    $at, 12
  beq   $t7, $at, .L7F0D1708
   lw    $t8, 0x20($sp)
  b     .L7F0D1754
   move  $v0, $zero
.L7F0D1708:
  li    $at, 24
  beq   $t8, $at, .L7F0D171C
   lw    $t9, 0x24($sp)
  b     .L7F0D1754
   move  $v0, $zero
.L7F0D171C:
  lw    $t0, 0x30($sp)
  lw    $t1, 0x28($sp)
  lw    $t2, 0x34($sp)
  beq   $t9, $t0, .L7F0D1738
   nop   
  b     .L7F0D1754
   move  $v0, $zero
.L7F0D1738:
  beq   $t1, $t2, .L7F0D1748
   lw    $t3, 0x2c($sp)
  b     .L7F0D1754
   move  $v0, $zero
.L7F0D1748:
  lw    $t4, 0x38($sp)
  li    $v0, 1
  sw    $t3, ($t4)
.L7F0D1754:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

unsigned int response_indyrescmd_1_4_2(unsigned char *response) {
  post_indyrescmd_istype1_correctsize(0x18, 0x18);
  post_indyrescmd_istype4_correctvalue(0x14, 0x14, response);
  post_indyrescmd_istype2_correctvalue(0, 0);
  return 1;
}

unsigned int response_indyrescmd_1_6_2(unsigned char *response1,
                                       unsigned char *response2) {
  post_indyrescmd_istype1_correctsize(0x1c, 0x1c);
  post_indyrescmd_istype6_correctvalue(0x14, 0x14, response1, response2);
  post_indyrescmd_istype2_correctvalue(0, 0);
  return 1;
}

unsigned int response_indyrescmd_1_8_2(unsigned char *response1,
                                       unsigned char *response2,
                                       unsigned int childsize,
                                       unsigned char *child) {
  post_indyrescmd_istype1_correctsize(0, 0x20);
  post_indyrescmd_istype8_correctvalue(0x14, 0x14, response1, response2,
                                       childsize, child);
  post_indyrescmd_istype2_correctvalue(0, 0);
  return 1;
}

unsigned int response_indyrescmd_1_A_2(unsigned char *param_1) {
  post_indyrescmd_istype1_correctsize(0x18, 0x18);
  post_indyrescmd_istypeA_correctvalue(0x14, 0x14, param_1);
  post_indyrescmd_istype2_correctvalue(0, 0);
  return 1;
}

unsigned int response_indyrescmd_1_10_2(unsigned int *param_1,
                                        unsigned int *param_2,
                                        unsigned int *param_3) {
  post_indyrescmd_istype1_correctsize(0x20, 0x20);
  post_indyrescmd_istype10_correctvalue(0x14, 0x14, param_1, param_2, param_3);
  post_indyrescmd_istype2_correctvalue(0, 0);
  return 1;
}

unsigned int response_indyrescmd_1_E_2(unsigned char *response) {
  post_indyrescmd_istype1_correctsize(0x18, 0x18);
  post_indyrescmd_istypeE_correctvalue(0x14, 0x14, response);
  post_indyrescmd_istype2_correctvalue(0, 0);
  return 1;
}

unsigned int response_indyrescmd_1_C_2(unsigned char *response) {
  post_indyrescmd_istype1_correctsize(0x18, 0x18);
  post_indyrescmd_istypeC_correctvalue(0x14, 0x14, response);
  post_indyrescmd_istype2_correctvalue(0, 0);
  return 1;
}

asm(R"
glabel response_indyrescmd_curr_matches_expected
  addiu $sp, $sp, -0x30
  sw    $ra, 0x14($sp)
  sw    $a0, 0x30($sp)
  sw    $a1, 0x34($sp)
  li    $a1, 20
  jal   post_indyrescmd_read_command
   addiu $a0, $sp, 0x1c
  lw    $t6, 0x1c($sp)
  lui   $at, (0x9ABF1623 >> 16) # lui $at, 0x9abf
  ori   $at, (0x9ABF1623 & 0xFFFF) # ori $at, $at, 0x1623
  lw    $v0, 0x30($sp)
  beq   $t6, $at, .L7F0D19D4
   lw    $v1, 0x34($sp)
  b     .L7F0D1A08
   move  $v0, $zero
.L7F0D19D4:
  beqz  $v0, .L7F0D19EC
   lw    $t7, 0x28($sp)
  beq   $t7, $v0, .L7F0D19EC
   nop   
  b     .L7F0D1A08
   move  $v0, $zero
.L7F0D19EC:
  beqz  $v1, .L7F0D1A04
   lw    $t8, 0x2c($sp)
  beql  $t8, $v1, .L7F0D1A08
   li    $v0, 1
  b     .L7F0D1A08
   move  $v0, $zero
.L7F0D1A04:
  li    $v0, 1
.L7F0D1A08:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");
