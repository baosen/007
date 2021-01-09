#include "indy_commands.h"
#include <types.h>

void init_indy_if_ready(void);

int init_indy_if_not_ready(void) {
  if (indy_ready != true) {
    indy_ready = true;
    init_indy_if_ready();
  }
}

void nullsub_48(void) {}

void init_indy_if_ready(void) {
  if (indy_ready != false)
    post_indy__res_cmd_initialize_seq();
}

asm(R"
glabel load_resource_on_indy
  lui   $t6, %hi(indy_ready) 
  lw    $t6, %lo(indy_ready)($t6)
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  beqz  $t6, .L7F0CFFD0
   sw    $a1, 0x2c($sp)
  jal   post_indyrescmd_req_filename_size
   lui   $a1, 0x40
  addiu $a0, $sp, 0x20
  addiu $a1, $sp, 0x1c
  addiu $a2, $sp, 0x18
  jal   response_indyrescmd_1_8_2
   lw    $a3, 0x2c($sp)
.L7F0CFFD0:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel indy_send_capture_data
  lui   $t6, %hi(indy_ready) 
  lw    $t6, %lo(indy_ready)($t6)
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  beqz  $t6, .L7F0D000C
   sw    $a1, 0x24($sp)
  move  $a1, $a2
  jal   post_indyrescmd_send_capture_data
   lw    $a2, 0x24($sp)
  jal   response_indyrescmd_1_A_2
   addiu $a0, $sp, 0x1c
.L7F0D000C:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

void indy_loadfile(void) {
  int sp24, sp20, sp1C;
  if (indy_ready != false) {
    post_indyrescmd_request_ramrom_file();
    response_indyrescmd_1_10_2(&sp24, &sp20, &sp1C);
  }
}

asm(R"
glabel check_file_exported
  lui   $t6, %hi(indy_ready) 
  lw    $t6, %lo(indy_ready)($t6)
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  beqz  $t6, .L7F0D0088
   sw    $a1, 0x24($sp)
  move  $a1, $a2
  jal   post_indyrescmd_game_prof_sendfile
   lw    $a2, 0x24($sp)
  jal   response_indyrescmd_1_E_2
   addiu $a0, $sp, 0x1c
.L7F0D0088:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel check_file_found_on_indy
  lui   $t6, %hi(indy_ready) 
  lw    $t6, %lo(indy_ready)($t6)
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  bnez  $t6, .L7F0D00B8
   sw    $a1, 0x24($sp)
  b     .L7F0D00D0
   move  $v0, $zero
.L7F0D00B8:
  jal   post_indyrescmd_game_printf_send
   nop   
  addiu $a0, $sp, 0x1c
  jal   response_indyrescmd_1_6_2
   lw    $a1, 0x24($sp)
  lw    $v0, 0x1c($sp)
.L7F0D00D0:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel response_from_command_string
  lui   $t6, %hi(indy_ready) 
  lw    $t6, %lo(indy_ready)($t6)
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  bnez  $t6, .L7F0D0100
   nop   
  b     .L7F0D0114
   move  $v0, $zero
.L7F0D0100:
  jal   post_indyrescmd_1_B_2
   nop   
  jal   response_indyrescmd_1_C_2
   addiu $a0, $sp, 0x1c
  lw    $v0, 0x1c($sp)
.L7F0D0114:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

void sub_GAME_7F0D0124(void) {
  if (indy_ready != false)
    rmon_debug_returns_neg_1();
}

void send_indy_close_port_cmd(void) {
  response_from_command_string("sleep 5; /etc/killall ghost gload");
}
