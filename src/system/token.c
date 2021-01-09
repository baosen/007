#include <message.h>

OSMesg boot_token_from_indy[160];
int strstr_numstings = 1;
int strstr_ptrcurrent_string = 0;
unsigned int D_80024478[34] = {0};

const char str_empty[] = "", aD_6[] = "-d", aS_2[] = "-s", aJ[] = "-j";

asm(R"
glabel check_string_something
  lui   $a1, %hi(strstr_ptrcurrent_string)
  lui   $a2, %hi(strstr_numstings)
  lui   $t6, %hi(str_empty) 
  addiu $a2, %lo(strstr_numstings) # addiu $a2, $a2, 0x4470
  addiu $a1, %lo(strstr_ptrcurrent_string) # addiu $a1, $a1, 0x4474
  addiu $t6, %lo(str_empty) # addiu $t6, $t6, -0x6e10
  li    $t7, 1
  sw    $t6, ($a1)
  sw    $t7, ($a2)
  lbu   $v0, ($a0)
  li    $a3, 32
  beqz  $v0, .L7000A584
   nop   
.L7000A524:
  bnel  $a3, $v0, .L7000A544
   lw    $v1, ($a2)
  lbu   $t8, 1($a0)
.L7000A530:
  sb    $zero, ($a0)
  addiu $a0, $a0, 1
  beql  $a3, $t8, .L7000A530
   lbu   $t8, 1($a0)
  lw    $v1, ($a2)
.L7000A544:
  sll   $t9, $v1, 2
  addu  $t0, $a1, $t9
  sw    $a0, ($t0)
  addiu $t1, $v1, 1
  sw    $t1, ($a2)
  lbu   $v0, ($a0)
  slti  $at, $v0, 0x21
  bnez  $at, .L7000A57C
   nop   
  lbu   $v0, 1($a0)
.L7000A56C:
  addiu $a0, $a0, 1
  slti  $at, $v0, 0x21
  beql  $at, $zero, .L7000A56C
   lbu   $v0, 1($a0)
.L7000A57C:
  bnez  $v0, .L7000A524
   nop   
.L7000A584:
  jr    $ra
   move  $v0, $a0
");

void strtok(int arg0) {
  textpointer_load_parse_something(&boot_token_from_indy, arg0);
  check_string_something(&boot_token_from_indy);
}

asm(R"
glabel check_boot_switches
  addiu $sp, $sp, -0x38
  sw    $s1, 0x1c($sp)
  sw    $ra, 0x24($sp)
  lui   $s1, 0xff
  sw    $s2, 0x20($sp)
  sw    $s0, 0x18($sp)
  sw    $zero, 0x28($sp)
  jal   rmon_debug_is_final_build
   ori $s1, $s1, 0xb000
  beqz  $v0, .L7000A5F8
   lui   $s0, %hi(boot_token_from_indy)
  lui   $at, %hi(boot_token_from_indy)
  b     .L7000A61C
   sw    $zero, %lo(boot_token_from_indy)($at)
.L7000A5F8:
  lui   $s2, %hi(piCmdBuf)
  addiu $s2, %lo(piCmdBuf) # addiu $s2, $s2, 0x4eb0
  addiu $s0, %lo(boot_token_from_indy) # addiu $s0, $s0, 0x4c30
.L7000A604:
  move  $a0, $s1
  jal   osPiReadIo
   move  $a1, $s0
  addiu $s0, $s0, 4
  bne   $s0, $s2, .L7000A604
   addiu $s1, $s1, 4
.L7000A61C:
  lui   $a0, %hi(boot_token_from_indy)
  jal   check_string_something
   addiu $a0, %lo(boot_token_from_indy) # addiu $a0, $a0, 0x4c30
  lui   $a1, %hi(aD_6)
  addiu $a1, %lo(aD_6) # addiu $a1, $a1, -0x6e0c
  jal   check_token
   li    $a0, 1
  beqz  $v0, .L7000A648
   li    $a0, 1
  li    $t6, 1
  sw    $t6, 0x28($sp)
.L7000A648:
  lui   $a1, %hi(aS_2)
  jal   check_token
   addiu $a1, %lo(aS_2) # addiu $a1, $a1, -0x6e08
  beqz  $v0, .L7000A668
   li    $a0, 1
  li    $t7, 1
  lui   $at, %hi(bootswitch_sound)
  sb    $t7, %lo(bootswitch_sound)($at)
.L7000A668:
  lui   $a1, %hi(aJ)
  jal   check_token
   addiu $a1, %lo(aJ) # addiu $a1, $a1, -0x6e04
  beqz  $v0, .L7000A684
   li    $t8, 1
  lui   $at, %hi(j_text_trigger)
  sw    $t8, %lo(j_text_trigger)($at)
.L7000A684:
  lw    $ra, 0x24($sp)
  lw    $v0, 0x28($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x38
");

asm(R"
glabel check_token
  addiu $sp, $sp, -0x30
  sw    $s2, 0x1c($sp)
  move  $s2, $a0
  sw    $ra, 0x2c($sp)
  sw    $s4, 0x24($sp)
  move  $s4, $a1
  sw    $s5, 0x28($sp)
  sw    $s3, 0x20($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  jal   strlen
   move  $a0, $a1
  lui   $s5, %hi(strstr_numstings)
  addiu $s5, %lo(strstr_numstings) # addiu $s5, $s5, 0x4470
  lw    $t6, ($s5)
  move  $s3, $v0
  li    $s1, 1
  slti  $at, $t6, 2
  bnez  $at, .L7000A73C
   lui   $s0, %hi(D_80024478)
  addiu $s0, %lo(D_80024478) # addiu $s0, $s0, 0x4478
  move  $a0, $s4
.L7000A6F8:
  lw    $a1, ($s0)
  jal   string_related
   move  $a2, $s3
  bnezl $v0, .L7000A728
   lw    $t8, ($s5)
  addiu $s2, $s2, -1
  bnezl $s2, .L7000A728
   lw    $t8, ($s5)
  lw    $t7, ($s0)
  b     .L7000A740
   addu  $v0, $t7, $s3
  lw    $t8, ($s5)
.L7000A728:
  addiu $s1, $s1, 1
  addiu $s0, $s0, 4
  slt   $at, $s1, $t8
  bnezl $at, .L7000A6F8
   move  $a0, $s4
.L7000A73C:
  move  $v0, $zero
.L7000A740:
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  lw    $s4, 0x24($sp)
  lw    $s5, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x30
");
