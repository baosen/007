#include "bondtypes.h"

struct objective_entry *objective_ptrs[10];
unsigned int dword_CODE_bss_80075D58, dword_CODE_bss_80075D5C;
char dword_CODE_bss_80075D60[0x20];
unsigned int *ptr_last_tag_entry_type16, *ptr_last_briefing_setup_entry_type23,
    *ptr_last_enter_room_subobject_entry_type20,
    *ptr_last_deposit_in_room_subobject_entry_type21,
    *ptr_last_photo_obj_in_room_subobject_entry_type1E;

int num_objective_ptrs[] = {0xFFFFFFFF, 0};

const unsigned int D_80053610[13] = {0};
const unsigned int aSAC[] = {0x25732080, 0x25632000};
const char aSC[] = "%s %c: ";

asm(R"
glabel sub_GAME_7F057080
  lui   $v1, %hi(ptr_last_tag_entry_type16)
  lw    $v1, %lo(ptr_last_tag_entry_type16)($v1)
  andi  $v0, $a0, 0xffff
  beql  $v1, $zero, .L7F0570B8
   move  $v0, $zero
  lhu   $t6, 4($v1)
.L7F057098:
  bnel  $v0, $t6, .L7F0570AC
   lw    $v1, 8($v1)
  jr    $ra
   move  $v0, $v1

  lw    $v1, 8($v1)
.L7F0570AC:
  bnezl $v1, .L7F057098
   lhu   $t6, 4($v1)
  move  $v0, $zero
.L7F0570B8:
  jr    $ra
   nop   
");

asm(R"
glabel get_handle_to_tagged_object
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F057080
   nop   
  beqz  $v0, .L7F0570DC
   move  $v1, $zero
  lw    $v1, 0xc($v0)
.L7F0570DC:
  beqz  $v1, .L7F0570F8
   lw    $ra, 0x14($sp)
  lw    $t6, 0x64($v1)
  andi  $t7, $t6, 0x10
  bnezl $t7, .L7F0570FC
   move  $v0, $v1
  move  $v1, $zero
.L7F0570F8:
  move  $v0, $v1
.L7F0570FC:
  jr    $ra
   addiu $sp, $sp, 0x18
");

asm(R"
glabel get_ptr_text_for_watch_breifing_page
  lui   $v0, %hi(ptr_last_briefing_setup_entry_type23)
  lw    $v0, %lo(ptr_last_briefing_setup_entry_type23)($v0)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  move  $a1, $a0
  beqz  $v0, .L7F057150
   move  $v1, $zero
  lw    $t6, 4($v0)
.L7F057124:
  bnel  $a1, $t6, .L7F057148
   lw    $v0, 0xc($v0)
  lhu   $a0, 0xa($v0)
  jal   get_textptr_for_textID
   sw    $a1, 0x18($sp)
  lw    $a1, 0x18($sp)
  b     .L7F057150
   move  $v1, $v0
  lw    $v0, 0xc($v0)
.L7F057148:
  bnezl $v0, .L7F057124
   lw    $t6, 4($v0)
.L7F057150:
  bnezl $v1, .L7F057198
   lw    $ra, 0x14($sp)
  bnez  $a1, .L7F057170
   li    $at, 1
  jal   get_textptr_for_textID
   li    $a0, 45097
  b     .L7F057194
   move  $v1, $v0
.L7F057170:
  bne   $a1, $at, .L7F057188
   nop   
  jal   get_textptr_for_textID
   li    $a0, 45098
  b     .L7F057194
   move  $v1, $v0
.L7F057188:
  jal   get_textptr_for_textID
   li    $a0, 45099
  move  $v1, $v0
.L7F057194:
  lw    $ra, 0x14($sp)
.L7F057198:
  addiu $sp, $sp, 0x18
  move  $v0, $v1
  jr    $ra
   nop   
");

int add_objective(void) { return num_objective_ptrs[0] + 1; }

unsigned char *get_text_for_objective(int objective) {
  unsigned char *textptr;

  if ((objective < 10) && (objective_ptrs[objective] != 0)) {
    return get_textptr_for_textID(objective_ptrs[objective]->text);
  }
  return 0;
}

asm(R"
glabel get_difficulty_for_objective
  slti  $at, $a0, 0xa
  beqz  $at, .L7F05722C
   sll   $t6, $a0, 2
  lui   $v1, %hi(objective_ptrs)
  addu  $v1, $v1, $t6
  lw    $v1, %lo(objective_ptrs)($v1)
  beql  $v1, $zero, .L7F057230
   move  $v0, $zero
  jr    $ra
   lb    $v0, 0xf($v1)

.L7F05722C:
  move  $v0, $zero
.L7F057230:
  jr    $ra
   nop   
");

asm(R"
.late_rodata
/*D:80053654*/
glabel jpt_objectives_microcode_handler
.word objective_microcode_type_17_18_1F_default
.word objective_microcode_type_17_18_1F_default
.word objective_microcode_type_19_destroy_object
.word objective_microcode_type_1A_complete_if_true
.word objective_microcode_type_1B_fail_if_true
.word objective_microcode_type_1C_collect_object
.word objective_microcode_type_1D_deposit_object
.word objective_microcode_type_1E_photograph_object
.word objective_microcode_type_17_18_1F_default
.word objective_microcode_type_20_enter_room
.word objective_microcode_type_21_deposit_object_in_room
.word objective_microcode_type_22_use_key_analyzer_on_object
.word 0,0,0

.text
glabel get_status_of_objective
  addiu $sp, $sp, -0x30
  sw    $s3, 0x24($sp)
  slti  $at, $a0, 0xa
  sw    $ra, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  beqz  $at, .L7F057484
   li    $s3, 1
  sll   $v0, $a0, 2
  lui   $a0, %hi(objective_ptrs)
  addu  $a0, $a0, $v0
  lw    $a0, %lo(objective_ptrs)($a0)
  bnezl $a0, .L7F05728C
   lbu   $v1, 3($a0)
  lui   $s3, %hi(dword_CODE_bss_80075D58)
  addu  $s3, $s3, $v0
  b     .L7F057484
   lw    $s3, %lo(dword_CODE_bss_80075D58)($s3)
  lbu   $v1, 3($a0)
.L7F05728C:
  li    $at, 24
  move  $s2, $a0
  beq   $v1, $at, .L7F057484
   li    $s4, 1
  addiu $t6, $v1, -0x17
.L7F0572A0:
  sltiu $at, $t6, 0xc
  beqz  $at, .L7F057438
   move  $s1, $s4
  sll   $t6, $t6, 2
  lui   $at, %hi(jpt_objectives_microcode_handler)
  addu  $at, $at, $t6
  lw    $t6, %lo(jpt_objectives_microcode_handler)($at)
  jr    $t6
   nop   
objective_microcode_type_19_destroy_object:
  jal   get_handle_to_tagged_object
   lw    $a0, 4($s2)
  beqz  $v0, .L7F057438
   move  $a0, $v0
  lw    $t7, 0x10($v0)
  beqz  $t7, .L7F057438
   nop   
  jal   check_if_object_has_not_been_destroyed
   nop   
  beqz  $v0, .L7F057438
   nop   
  b     .L7F057438
   move  $s1, $zero
objective_microcode_type_1A_complete_if_true:
  move  $a0, $zero
  jal   check_if_objective_bitflags_set
   lw    $a1, 4($s2)
  bnez  $v0, .L7F057438
   nop   
  b     .L7F057438
   move  $s1, $zero
objective_microcode_type_1B_fail_if_true:
  move  $a0, $zero
  jal   check_if_objective_bitflags_set
   lw    $a1, 4($s2)
  beqz  $v0, .L7F057438
   nop   
  b     .L7F057438
   li    $s1, 2
objective_microcode_type_1C_collect_object:
  jal   get_handle_to_tagged_object
   lw    $a0, 4($s2)
  beqz  $v0, .L7F05735C
   move  $s0, $v0
  lw    $t8, 0x10($v0)
  beqz  $t8, .L7F05735C
   nop   
  jal   check_if_object_has_not_been_destroyed
   move  $a0, $v0
  bnez  $v0, .L7F057364
   nop   
.L7F05735C:
  b     .L7F057438
   li    $s1, 2
.L7F057364:
  jal   sub_GAME_7F08CFE0
   lw    $a0, 0x10($s0)
  bnez  $v0, .L7F057438
   nop   
  b     .L7F057438
   move  $s1, $zero
objective_microcode_type_1D_deposit_object:
  jal   get_handle_to_tagged_object
   lw    $a0, 4($s2)
  beqz  $v0, .L7F057438
   nop   
  lw    $t9, 0x10($v0)
  beqz  $t9, .L7F057438
   nop   
  jal   sub_GAME_7F08CFE0
   move  $a0, $t9
  beqz  $v0, .L7F057438
   nop   
  b     .L7F057438
   move  $s1, $zero
objective_microcode_type_1E_photograph_object:
  jal   get_handle_to_tagged_object
   lw    $a0, 4($s2)
  lw    $t0, 8($s2)
  move  $a0, $v0
  bnez  $t0, .L7F057438
   nop   
  beqz  $v0, .L7F0573EC
   nop   
  lw    $t1, 0x10($v0)
  beqz  $t1, .L7F0573EC
   nop   
  jal   check_if_object_has_not_been_destroyed
   nop   
  bnez  $v0, .L7F0573F4
   nop   
.L7F0573EC:
  b     .L7F057438
   li    $s1, 2
.L7F0573F4:
  b     .L7F057438
   move  $s1, $zero
objective_microcode_type_20_enter_room:
  lw    $t2, 8($s2)
  bnez  $t2, .L7F057438
   nop   
  b     .L7F057438
   move  $s1, $zero
objective_microcode_type_21_deposit_object_in_room:
  lw    $t3, 0xc($s2)
  bnez  $t3, .L7F057438
   nop   
  b     .L7F057438
   move  $s1, $zero
objective_microcode_type_22_use_key_analyzer_on_object:
  jal   get_keyanalyzer_flag
   nop   
  bnez  $v0, .L7F057438
   nop   
  move  $s1, $zero
objective_microcode_type_17_18_1F_default:
.L7F057438:
  bne   $s3, $s4, .L7F057450
   nop   
  beq   $s1, $s4, .L7F057464
   nop   
  b     .L7F057464
   move  $s3, $s1
.L7F057450:
  bnez  $s3, .L7F057464
   li    $at, 2
  bne   $s1, $at, .L7F057464
   nop   
  move  $s3, $s1
.L7F057464:
  jal   get_size_of_setup_object_type
   move  $a0, $s2
  sll   $t4, $v0, 2
  addu  $s2, $t4, $s2
  lbu   $v1, 3($s2)
  li    $at, 24
  bnel  $v1, $at, .L7F0572A0
   addiu $t6, $v1, -0x17
.L7F057484:
  jal   get_debug_all_obj_complete_flag
   nop   
  beqz  $v0, .L7F057498
   lw    $s0, 0x18($sp)
  li    $s3, 1
.L7F057498:
  lw    $ra, 0x2c($sp)
  move  $v0, $s3
  lw    $s3, 0x24($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  lw    $s4, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x30
");

unsigned int check_objectives_complete(void) {
  DIFFICULTY objdiff;
  DIFFICULTY curdiff;
  int objective;

  for (objective = 0; objective < add_objective(); objective++) {
    objdiff = get_difficulty_for_objective(objective);
    curdiff = get_current_difficulty();
    if ((objdiff <= curdiff) && (get_status_of_objective(objective) != 1)) {
      return 0;
    }
  }
  return 1;
}

#ifdef VERSION_JP
void FUN_7f057a40(void) {
  num_objective_ptrs[1] = 1;
  return;
}
#endif

#ifdef VERSION_US
asm(R"
glabel display_objective_status_text_on_status_change
  addiu $sp, $sp, -0x90
  sw    $s6, 0x30($sp)
  sw    $s3, 0x24($sp)
  lui   $t6, %hi(D_80053610) 
  addiu $s3, $sp, 0x54
  lui   $s6, %hi(num_objective_ptrs)
  sw    $s4, 0x28($sp)
  addiu $t6, %lo(D_80053610) # addiu $t6, $t6, 0x3610
  addiu $s6, %lo(num_objective_ptrs) # addiu $s6, $s6, 0x22f0
  sw    $ra, 0x3c($sp)
  sw    $fp, 0x38($sp)
  sw    $s7, 0x34($sp)
  sw    $s5, 0x2c($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  move  $s4, $zero
  addiu $t9, $t6, 0x30
  move  $t0, $s3
.L7F05758C:
  lw    $at, ($t6)
  addiu $t6, $t6, 0xc
  addiu $t0, $t0, 0xc
  sw    $at, -0xc($t0)
  lw    $at, -8($t6)
  sw    $at, -8($t0)
  lw    $at, -4($t6)
  bne   $t6, $t9, .L7F05758C
   sw    $at, -4($t0)
  lhu   $at, ($t6)
  lui   $s5, %hi(dword_CODE_bss_80075D58)
  lui   $fp, %hi(aSAC) 
  sh    $at, ($t0)
  lw    $t1, ($s6)
  addiu $fp, %lo(aSAC) # addiu $fp, $fp, 0x3644
  addiu $s5, %lo(dword_CODE_bss_80075D58) # addiu $s5, $s5, 0x5d58
  bltz  $t1, .L7F057714
   move  $s2, $zero
  lui   $s7, %hi(j_text_trigger) 
  addiu $s7, %lo(j_text_trigger) # addiu $s7, $s7, -0x7b30
.L7F0575DC:
  jal   get_status_of_objective
   move  $a0, $s2
  lw    $t2, ($s5)
  move  $s1, $v0
  move  $a0, $s2
  beq   $v0, $t2, .L7F0576DC
   nop   
  jal   get_difficulty_for_objective
   sw    $v0, ($s5)
  jal   get_current_difficulty
   move  $s0, $v0
  slt   $at, $v0, $s0
  bnez  $at, .L7F0576DC
   nop   
  lw    $t3, ($s7)
  addiu $s0, $s4, 0x1a
  li    $a0, 45100
  beqz  $t3, .L7F05764C
   nop   
  jal   get_textptr_for_textID
   li    $a0, 45100
  move  $a0, $s3
  move  $a1, $fp
  move  $a2, $v0
  jal   sprintf
   move  $a3, $s0
  b     .L7F057670
   li    $at, 1
.L7F05764C:
  jal   get_textptr_for_textID
   addiu $s0, $s4, 0x61
  lui   $a1, %hi(aSC)
  addiu $a1, %lo(aSC) # addiu $a1, $a1, 0x364c
  move  $a0, $s3
  move  $a2, $v0
  jal   sprintf
   move  $a3, $s0
  li    $at, 1
.L7F057670:
  bne   $s1, $at, .L7F057694
   nop   
  jal   get_textptr_for_textID
   li    $a0, 45101
  move  $a0, $s3
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F0576D4
   nop   
.L7F057694:
  bnez  $s1, .L7F0576B8
   li    $at, 2
  jal   get_textptr_for_textID
   li    $a0, 45102
  move  $a0, $s3
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F0576D4
   nop   
.L7F0576B8:
  bne   $s1, $at, .L7F0576D4
   nop   
  jal   get_textptr_for_textID
   li    $a0, 45103
  move  $a0, $s3
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
.L7F0576D4:
  jal   display_string_in_lower_left_corner
   move  $a0, $s3
.L7F0576DC:
  jal   get_difficulty_for_objective
   move  $a0, $s2
  jal   get_current_difficulty
   move  $s0, $v0
  slt   $at, $v0, $s0
  bnezl $at, .L7F057700
   lw    $t4, ($s6)
  addiu $s4, $s4, 1
  lw    $t4, ($s6)
.L7F057700:
  addiu $s2, $s2, 1
  addiu $s5, $s5, 4
  slt   $at, $t4, $s2
  beqz  $at, .L7F0575DC
   nop   
.L7F057714:
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
   addiu $sp, $sp, 0x90
");
#endif

#ifdef VERSION_JP
asm(R"
glabel display_objective_status_text_on_status_change
  addiu $sp, $sp, -0x90
  sw    $s3, 0x24($sp)
  lui   $t6, %hi(D_80053610) # $t6, 0x8005
  addiu $s3, $sp, 0x54
  sw    $s5, 0x2c($sp)
  addiu $t6, %lo(D_80053610) # addiu $t6, $t6, 0x3640
  sw    $ra, 0x3c($sp)
  sw    $fp, 0x38($sp)
  sw    $s7, 0x34($sp)
  sw    $s6, 0x30($sp)
  sw    $s4, 0x28($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  move  $s5, $zero
  addiu $t9, $t6, 0x30
  move  $t0, $s3
.L7F057A94:
  lw    $at, ($t6)
  addiu $t6, $t6, 0xc
  addiu $t0, $t0, 0xc
  sw    $at, -0xc($t0)
  lw    $at, -8($t6)
  sw    $at, -8($t0)
  lw    $at, -4($t6)
  bne   $t6, $t9, .L7F057A94
   sw    $at, -4($t0)
  lhu   $at, ($t6)
  lui   $t1, %hi(num_objective_ptrs+4) # $t1, 0x8003
  lui   $s6, %hi(num_objective_ptrs) # $s6, 0x8003
  sh    $at, ($t0)
  lw    $t1, %lo(num_objective_ptrs+4)($t1)
  addiu $s6, %lo(num_objective_ptrs) # addiu $s6, $s6, 0x2330
  bnezl $t1, .L7F057C34
   lw    $ra, 0x3c($sp)
  lw    $t2, ($s6)
  lui   $s4, %hi(dword_CODE_bss_80075D58) # $s4, 0x8007
  addiu $s4, %lo(dword_CODE_bss_80075D58) # addiu $s4, $s4, 0x5d98
  bltz  $t2, .L7F057C30
   move  $s2, $zero
  lui   $s7, %hi(j_text_trigger) # $s7, 0x8005
  addiu $s7, %lo(j_text_trigger) # addiu $s7, $s7, -0x7b00
  li    $fp, 1
.L7F057AF8:
  jal   get_status_of_objective
   move  $a0, $s2
  lw    $t3, ($s4)
  move  $s1, $v0
  move  $a0, $s2
  beq   $v0, $t3, .L7F057BF8
   nop   
  jal   get_difficulty_for_objective
   sw    $v0, ($s4)
  jal   get_current_difficulty
   move  $s0, $v0
  slt   $at, $v0, $s0
  bnez  $at, .L7F057BF8
   nop   
  lw    $t4, ($s7)
  addiu $s0, $s5, 0x1a
  li    $a0, 45100
  beqz  $t4, .L7F057B6C
   nop   
  jal   get_textptr_for_textID
   li    $a0, 45100
  lui   $a1, %hi(aSAC) # $a1, 0x8005
  addiu $a1, %lo(aSAC) # addiu $a1, $a1, 0x3674
  move  $a0, $s3
  move  $a2, $v0
  jal   sprintf
   move  $a3, $s0
  b     .L7F057B8C
   nop   
.L7F057B6C:
  jal   get_textptr_for_textID
   addiu $s0, $s5, 0x61
  lui   $a1, %hi(aSC) # $a1, 0x8005
  addiu $a1, %lo(aSC) # addiu $a1, $a1, 0x367c
  move  $a0, $s3
  move  $a2, $v0
  jal   sprintf
   move  $a3, $s0
.L7F057B8C:
  bne   $s1, $fp, .L7F057BB0
   nop   
  jal   get_textptr_for_textID
   li    $a0, 45101
  move  $a0, $s3
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F057BF0
   nop   
.L7F057BB0:
  bnez  $s1, .L7F057BD4
   li    $at, 2
  jal   get_textptr_for_textID
   li    $a0, 45102
  move  $a0, $s3
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F057BF0
   nop   
.L7F057BD4:
  bne   $s1, $at, .L7F057BF0
   nop   
  jal   get_textptr_for_textID
   li    $a0, 45103
  move  $a0, $s3
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
.L7F057BF0:
  jal   jp_display_string_in_lower_left_corner
   move  $a0, $s3
.L7F057BF8:
  jal   get_difficulty_for_objective
   move  $a0, $s2
  jal   get_current_difficulty
   move  $s0, $v0
  slt   $at, $v0, $s0
  bnezl $at, .L7F057C1C
   lw    $t5, ($s6)
  addiu $s5, $s5, 1
  lw    $t5, ($s6)
.L7F057C1C:
  addiu $s2, $s2, 1
  addiu $s4, $s4, 4
  slt   $at, $t5, $s2
  beqz  $at, .L7F057AF8
   nop   
.L7F057C30:
  lw    $ra, 0x3c($sp)
.L7F057C34:
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
   addiu $sp, $sp, 0x90
");
#endif

asm(R"
glabel sub_GAME_7F057744
  lui   $v0, %hi(ptr_last_enter_room_subobject_entry_type20)
  lw    $v0, %lo(ptr_last_enter_room_subobject_entry_type20)($v0)
  lui   $t2, (0xFFF59FC0 >> 16) # lui $t2, 0xfff5
  move  $a1, $a0
  beqz  $v0, .L7F0577E0
   ori   $t2, (0xFFF59FC0 & 0xFFFF) # ori $t2, $t2, 0x9fc0
  lui   $a3, %hi(ptr_setup_path_tbl)
  addiu $a3, %lo(ptr_setup_path_tbl) # addiu $a3, $a3, 0x5d00
  li    $t1, 68
  li    $t0, 1
  li    $a2, 44
  lw    $t6, 8($v0)
.L7F057774:
  bnezl $t6, .L7F0577D8
   lw    $v0, 0xc($v0)
  lw    $v1, 4($v0)
  sltiu $at, $v1, 0x2710
  beqz  $at, .L7F0577A4
   nop   
  multu $v1, $a2
  lw    $t8, 0x18($a3)
  mflo  $t7
  addu  $a0, $t7, $t8
  b     .L7F0577BC
   lw    $v1, 0x28($a0)
.L7F0577A4:
  multu $v1, $t1
  lw    $t3, 0x1c($a3)
  mflo  $t9
  addu  $t4, $t9, $t3
  addu  $a0, $t4, $t2
  lw    $v1, 0x28($a0)
.L7F0577BC:
  beql  $v1, $zero, .L7F0577D8
   lw    $v0, 0xc($v0)
  lbu   $t5, 3($v1)
  bnel  $a1, $t5, .L7F0577D8
   lw    $v0, 0xc($v0)
  sw    $t0, 8($v0)
  lw    $v0, 0xc($v0)
.L7F0577D8:
  bnezl $v0, .L7F057774
   lw    $t6, 8($v0)
.L7F0577E0:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0577E8
  lui   $v0, %hi(ptr_last_deposit_in_room_subobject_entry_type21)
  lw    $v0, %lo(ptr_last_deposit_in_room_subobject_entry_type21)($v0)
  lui   $t3, (0xFFF59FC0 >> 16) # lui $t3, 0xfff5
  move  $a2, $a1
  beqz  $v0, .L7F057890
   ori   $t3, (0xFFF59FC0 & 0xFFFF) # ori $t3, $t3, 0x9fc0
  lui   $t0, %hi(ptr_setup_path_tbl) 
  addiu $t0, %lo(ptr_setup_path_tbl) # addiu $t0, $t0, 0x5d00
  li    $t2, 68
  li    $t1, 1
  li    $a3, 44
  lw    $t6, 0xc($v0)
.L7F057818:
  bnezl $t6, .L7F057888
   lw    $v0, 0x10($v0)
  lw    $t7, 4($v0)
  bnel  $a0, $t7, .L7F057888
   lw    $v0, 0x10($v0)
  lw    $v1, 8($v0)
  sltiu $at, $v1, 0x2710
  beqz  $at, .L7F057854
   nop   
  multu $v1, $a3
  lw    $t9, 0x18($t0)
  mflo  $t8
  addu  $a1, $t8, $t9
  b     .L7F05786C
   lw    $v1, 0x28($a1)
.L7F057854:
  multu $v1, $t2
  lw    $t5, 0x1c($t0)
  mflo  $t4
  addu  $t6, $t4, $t5
  addu  $a1, $t6, $t3
  lw    $v1, 0x28($a1)
.L7F05786C:
  beql  $v1, $zero, .L7F057888
   lw    $v0, 0x10($v0)
  lbu   $t7, 3($v1)
  bnel  $a2, $t7, .L7F057888
   lw    $v0, 0x10($v0)
  sw    $t1, 0xc($v0)
  lw    $v0, 0x10($v0)
.L7F057888:
  bnezl $v0, .L7F057818
   lw    $t6, 0xc($v0)
.L7F057890:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F057898
  addiu $sp, $sp, -0x98
  sw    $s1, 0x34($sp)
  lui   $s1, %hi(ptr_last_photo_obj_in_room_subobject_entry_type1E)
  lw    $s1, %lo(ptr_last_photo_obj_in_room_subobject_entry_type1E)($s1)
  sw    $ra, 0x4c($sp)
  sw    $s6, 0x48($sp)
  sw    $s5, 0x44($sp)
  sw    $s4, 0x40($sp)
  sw    $s3, 0x3c($sp)
  sw    $s2, 0x38($sp)
  sw    $s0, 0x30($sp)
  sdc1  $f22, 0x28($sp)
  beqz  $s1, .L7F057A90
   sdc1  $f20, 0x20($sp)
  mtc1  $zero, $f22
  li    $s6, 1
  addiu $s5, $sp, 0x64
  addiu $s4, $sp, 0x74
  addiu $s3, $sp, 0x7c
  addiu $s2, $sp, 0x84
  lw    $t6, 8($s1)
.L7F0578EC:
  bnezl $t6, .L7F057A88
   lw    $s1, 0xc($s1)
  jal   get_handle_to_tagged_object
   lw    $a0, 4($s1)
  beqz  $v0, .L7F057A84
   move  $s0, $v0
  lw    $v1, 0x10($v0)
  beql  $v1, $zero, .L7F057A88
   lw    $s1, 0xc($s1)
  lbu   $t7, 1($v1)
  andi  $t8, $t7, 2
  beql  $t8, $zero, .L7F057A88
   lw    $s1, 0xc($s1)
  lwc1  $f4, 0x18($v1)
  c.le.s $f22, $f4
  nop   
  bc1fl .L7F057A88
   lw    $s1, 0xc($s1)
  jal   check_if_object_has_not_been_destroyed
   move  $a0, $v0
  beqz  $v0, .L7F057A84
   move  $a1, $s2
  lw    $a0, 0x10($s0)
  move  $a2, $s3
  jal   sub_GAME_7F050D30
   move  $a3, $s4
  beqz  $v0, .L7F057A84
   move  $a0, $s2
  move  $a1, $s3
  move  $a2, $s4
  addiu $a3, $sp, 0x6c
  jal   sub_GAME_7F03F948
   sw    $s5, 0x10($sp)
  jal   getPlayer_c_screenleft
   nop   
  lwc1  $f6, 0x6c($sp)
  c.lt.s $f0, $f6
  nop   
  bc1fl .L7F057A88
   lw    $s1, 0xc($s1)
  jal   getPlayer_c_screenleft
   nop   
  jal   getPlayer_c_screenwidth
   mov.s $f20, $f0
  add.s $f10, $f0, $f20
  lwc1  $f8, 0x6c($sp)
  c.lt.s $f8, $f10
  nop   
  bc1fl .L7F057A88
   lw    $s1, 0xc($s1)
  jal   getPlayer_c_screenleft
   nop   
  lwc1  $f16, 0x64($sp)
  c.lt.s $f0, $f16
  nop   
  bc1fl .L7F057A88
   lw    $s1, 0xc($s1)
  jal   getPlayer_c_screenleft
   nop   
  jal   getPlayer_c_screenwidth
   mov.s $f20, $f0
  add.s $f4, $f0, $f20
  lwc1  $f18, 0x64($sp)
  c.lt.s $f18, $f4
  nop   
  bc1fl .L7F057A88
   lw    $s1, 0xc($s1)
  jal   getPlayer_c_screentop
   nop   
  lwc1  $f6, 0x70($sp)
  c.lt.s $f0, $f6
  nop   
  bc1fl .L7F057A88
   lw    $s1, 0xc($s1)
  jal   getPlayer_c_screentop
   nop   
  jal   getPlayer_c_screenheight
   mov.s $f20, $f0
  add.s $f10, $f0, $f20
  lwc1  $f8, 0x70($sp)
  c.lt.s $f8, $f10
  nop   
  bc1fl .L7F057A88
   lw    $s1, 0xc($s1)
  jal   getPlayer_c_screentop
   nop   
  lwc1  $f16, 0x68($sp)
  c.lt.s $f0, $f16
  nop   
  bc1fl .L7F057A88
   lw    $s1, 0xc($s1)
  jal   getPlayer_c_screentop
   nop   
  jal   getPlayer_c_screenheight
   mov.s $f20, $f0
  add.s $f4, $f0, $f20
  lwc1  $f18, 0x68($sp)
  c.lt.s $f18, $f4
  nop   
  bc1fl .L7F057A88
   lw    $s1, 0xc($s1)
  sw    $s6, 8($s1)
.L7F057A84:
  lw    $s1, 0xc($s1)
.L7F057A88:
  bnezl $s1, .L7F0578EC
   lw    $t6, 8($s1)
.L7F057A90:
  lw    $ra, 0x4c($sp)
  ldc1  $f20, 0x20($sp)
  ldc1  $f22, 0x28($sp)
  lw    $s0, 0x30($sp)
  lw    $s1, 0x34($sp)
  lw    $s2, 0x38($sp)
  lw    $s3, 0x3c($sp)
  lw    $s4, 0x40($sp)
  lw    $s5, 0x44($sp)
  lw    $s6, 0x48($sp)
  jr    $ra
   addiu $sp, $sp, 0x98
");
