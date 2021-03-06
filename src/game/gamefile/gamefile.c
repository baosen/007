#include "bondconstants.h"
#include "mainmenu.h"

// EEPROM masks for in-game settings.
#define OPTION_INVERTLOOK 0x0001
#define OPTION_AUTOAIM 0x0002
#define OPTION_AIMCONTROL 0x0004
#define OPTION_SIGHTONSCREEN 0x0008
#define OPTION_LOOKAHEAD 0x0010
#define OPTION_DISPLAYAMMO 0x0020
#define OPTION_SCREENWIDE 0x0040
#define OPTION_SCREENRATIO 0x0080
#define OPTION_CONTROLTYPE 0x0700
#define OPTION_SCREENCINEMA 0x0800

#define DEFAULT_OPTIONS                                                        \
  (OPTION_AUTOAIM | OPTION_SIGHTONSCREEN | OPTION_LOOKAHEAD |                  \
   OPTION_DISPLAYAMMO)

typedef struct {
  int chksum1, chksum2;
  char completion_bitflags;
  char flag_007;
  char music_vol;
  char sfx_vol;
  short options;
  char unlocked_cheats_1, unlocked_cheats_2, unlocked_cheats_3;
  char padding;
  unsigned char time_dam_agent[5];
  unsigned char field_0x17[5];
  unsigned char field_0x1c[5];
  unsigned char field_0x21[5];
  unsigned char field_0x26[5];
  unsigned char field_0x2b[5];
  unsigned char field_0x30[5];
  unsigned char field_0x35[5];
  unsigned char field_0x3a[5];
  unsigned char field_0x3f[5];
  unsigned char field_0x44[5];
  unsigned char field_0x49[5];
  unsigned char field_0x4e[5];
  unsigned char field_0x53[5];
  unsigned char field_0x58[5];
  unsigned char field_0x5d[3];
} save;

unsigned char
removed_would_have_returned_bond_for_folder_num(unsigned int folder);

save save1, save2, save3, save4, save5, save6;

unsigned int dword_CODE_bss_80069B60;

unsigned int save_selected_bond[4] = {0};

save D_8002C520 = {0,    0,    0x80, 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS,
                   0x00, 0x00, 0,    0,    0,    0,    0};
save D_8002C580 = {0,    0,    0x80, 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS,
                   0x00, 0x00, 0,    0,    0,    0,    0};
save D_8002C5E0 = {0,    0,    0x80, 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS,
                   0x00, 0x00, 0,    0,    0,    0,    0};

unsigned int D_8002C640 = 0;
unsigned int D_8002C644 = 0;
unsigned int flt_8002C648 = 0x42000000;
unsigned int dword_8002C64C = 0;
unsigned int dword_8002C650 = 0;
unsigned int dword_8002C654 = 0;
unsigned int dword_8002C658 = 0;
unsigned int dword_8002C65C = 0;

save D_8002C660 = {0,    0,    0x80, 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS,
                   0x00, 0x00, 0,    0,    0,    0,    0};
save D_8002C6C0 = {0,    0,    0x80, 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS,
                   0x00, 0x00, 0,    0,    0,    0,    0,
                   0,    0,    0,    0,    0,    0,    0,
                   0,    0,    0,    0,    0,    0,    0,
                   0};
save D_8002C720 = {0,    0,    0x80, 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS,
                   0x00, 0x00, 0,    0,    0,    0,    0,
                   0,    0,    0,    0,    0,    0,    0,
                   0,    0,    0,    0,    0,    0,    0,
                   0};
save D_8002C780 = {0,    0,    0x80, 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS,
                   0x00, 0x00, 0,    0,    0,    0,    0,
                   0,    0,    0,    0,    0,    0,    0,
                   0,    0,    0,    0,    0,    0,    0,
                   0};
save D_8002C7E0 = {0,    0,    0x80, 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS,
                   0x00, 0x00, 0,    0,    0,    0,    0,
                   0,    0,    0,    0,    0,    0,    0,
                   0,    0,    0,    0,    0,    0,    0,
                   0};
save D_8002C840 = {0,    0,    0x80, 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS,
                   0x00, 0x00, 0,    0,    0,    0,    0,
                   0,    0,    0,    0,    0,    0,    0,
                   0,    0,    0,    0,    0,    0,    0,
                   0};
save blank_eeprom = {0,    0,    0x80, 0x00, 0xFF, 0xFF, DEFAULT_OPTIONS,
                     0x00, 0x00, 0,    0,    0,    0,    0,
                     0,    0,    0,    0,    0,    0,    0,
                     0,    0,    0,    0,    0,    0,    0,
                     0};

float get_007_reaction_speed(void) {
  if (get_current_difficulty() == DIFFICULTY_007)
    return slider_007_mode_reaction;
  return 0.f;
}

float get_007_health_mod(void) {
  if (get_current_difficulty() == DIFFICULTY_007)
    return slider_007_mode_health;
  return 1.f;
}

float get_007_damage_mod(void) {
  if (get_current_difficulty() == DIFFICULTY_007)
    return slider_007_mode_accuracy;
  return 1.f;
}

float get_007_accuracy_mod(void) {
  if (get_current_difficulty() == DIFFICULTY_007)
    return slider_007_mode_damage;
  return 1.f;
}

#ifdef VERSION_US
asm(R"
glabel end_of_mission_briefing
  lui   $v0, %hi(briefingpage)
  lw    $v0, %lo(briefingpage)($v0)
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  bltz  $v0, .L7F01D4F0
   lui   $v1, %hi(selected_difficulty)
  lw    $v1, %lo(selected_difficulty)($v1)
  li    $at, 3
  lui   $t6, %hi(append_cheat_sp) 
  beql  $v1, $at, .L7F01D4F4
   lw    $ra, 0x14($sp)
  lw    $t6, %lo(append_cheat_sp)($t6)
  sll   $t7, $v0, 3
  subu  $t7, $t7, $v0
  bnez  $t6, .L7F01D4F0
   sll   $t7, $t7, 2
  lui   $t8, %hi(mission_folder_setup_entries+0x14)
  addu  $t8, $t8, $t7
  lw    $t8, %lo(mission_folder_setup_entries+0x14)($t8)
  sll   $t0, $v1, 1
  lui   $t2, %hi(solo_target_time_array)
  sll   $t9, $t8, 2
  subu  $t9, $t9, $t8
  sll   $t9, $t9, 1
  addu  $t1, $t9, $t0
  addu  $t2, $t2, $t1
  lh    $t2, %lo(solo_target_time_array)($t2)
  jal   get_mission_timer
   sh    $t2, 0x1e($sp)
  li    $at, 60
  div   $zero, $v0, $at
  lui   $t3, %hi(briefingpage) 
  lw    $t3, %lo(briefingpage)($t3)
  lui   $a1, %hi(mission_folder_setup_entries+0x14)
  mflo  $a3
  sll   $t4, $t3, 3
  subu  $t4, $t4, $t3
  sll   $t4, $t4, 2
  addu  $a1, $a1, $t4
  lui   $a0, %hi(selected_folder_num)
  lui   $a2, %hi(selected_difficulty)
  lw    $a2, %lo(selected_difficulty)($a2)
  lw    $a0, %lo(selected_folder_num)($a0)
  jal   unlock_stage_in_folder_on_difficulty
   lw    $a1, %lo(mission_folder_setup_entries+0x14)($a1)
  jal   get_mission_timer
   nop   
  li    $at, 60
  div   $zero, $v0, $at
  lh    $t5, 0x1e($sp)
  mflo  $t6
  lui   $a0, %hi(selected_folder_num)
  slt   $at, $t5, $t6
  bnez  $at, .L7F01D4E8
   nop   
  jal   get_save_folder_ptr
   lw    $a0, %lo(selected_folder_num)($a0)
  lui   $t7, %hi(briefingpage) 
  lw    $t7, %lo(briefingpage)($t7)
  lui   $a1, %hi(mission_folder_setup_entries+0x14)
  move  $a0, $v0
  sll   $t8, $t7, 3
  subu  $t8, $t8, $t7
  sll   $t8, $t8, 2
  addu  $a1, $a1, $t8
  jal   check_if_cheat_unlocked
   lw    $a1, %lo(mission_folder_setup_entries+0x14)($a1)
  bnez  $v0, .L7F01D4E8
   lui   $a0, %hi(selected_folder_num)
  lui   $t9, %hi(briefingpage) 
  lw    $t9, %lo(briefingpage)($t9)
  lui   $a1, %hi(mission_folder_setup_entries+0x14)
  lw    $a0, %lo(selected_folder_num)($a0)
  sll   $t0, $t9, 3
  subu  $t0, $t0, $t9
  sll   $t0, $t0, 2
  addu  $a1, $a1, $t0
  jal   sub_GAME_7F01E760
   lw    $a1, %lo(mission_folder_setup_entries+0x14)($a1)
  li    $t1, 1
  lui   $at, %hi(newcheatunlocked)
  b     .L7F01D4F0
   sw    $t1, %lo(newcheatunlocked)($at)
.L7F01D4E8:
  lui   $at, %hi(newcheatunlocked)
  sw    $zero, %lo(newcheatunlocked)($at)
.L7F01D4F0:
  lw    $ra, 0x14($sp)
.L7F01D4F4:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");
#endif

#ifdef VERSION_JP
asm(R"
glabel end_of_mission_briefing
  lui   $v0, %hi(briefingpage) # $v0, 0x8003
  lw    $v0, %lo(briefingpage)($v0)
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  bltz  $v0, .L7F01D694
   lui   $v1, %hi(selected_difficulty) # $v1, 0x8003
  lw    $v1, %lo(selected_difficulty)($v1)
  li    $at, 3
  lui   $t6, %hi(append_cheat_sp) # $t6, 0x8003
  beql  $v1, $at, .L7F01D698
   lw    $ra, 0x14($sp)
  lw    $t6, %lo(append_cheat_sp)($t6)
  sll   $t7, $v0, 3
  subu  $t7, $t7, $v0
  bnez  $t6, .L7F01D694
   sll   $t7, $t7, 2
  lui   $t8, %hi(mission_folder_setup_entries+0x14)
  addu  $t8, $t8, $t7
  lw    $t8, %lo(mission_folder_setup_entries+0x14)($t8)
  sll   $t0, $v1, 1
  lui   $t2, %hi(solo_target_time_array)
  sll   $t9, $t8, 2
  subu  $t9, $t9, $t8
  sll   $t9, $t9, 1
  addu  $t1, $t9, $t0
  addu  $t2, $t2, $t1
  lh    $t2, %lo(solo_target_time_array)($t2)
  jal   get_mission_timer
   sh    $t2, 0x1e($sp)
  li    $at, 60
  div   $zero, $v0, $at
  lui   $t3, %hi(briefingpage) # $t3, 0x8003
  lw    $t3, %lo(briefingpage)($t3)
  lui   $a1, %hi(mission_folder_setup_entries+0x14)
  mflo  $a3
  sll   $t4, $t3, 3
  subu  $t4, $t4, $t3
  sll   $t4, $t4, 2
  addu  $a1, $a1, $t4
  lui   $a0, %hi(selected_folder_num) # $a0, 0x8003
  lui   $a2, %hi(selected_difficulty) # $a2, 0x8003
  lw    $a2, %lo(selected_difficulty)($a2)
  lw    $a0, %lo(selected_folder_num)($a0)
  jal   unlock_stage_in_folder_on_difficulty
   lw    $a1, %lo(mission_folder_setup_entries+0x14)($a1)
  jal   get_mission_timer
   nop   
  li    $at, 60
  div   $zero, $v0, $at
  lh    $t5, 0x1e($sp)
  mflo  $t6
  lui   $a0, %hi(selected_folder_num) # $a0, 0x8003
  slt   $at, $t5, $t6
  bnezl $at, .L7F01D698
   lw    $ra, 0x14($sp)
  jal   get_save_folder_ptr
   lw    $a0, %lo(selected_folder_num)($a0)
  lui   $t7, %hi(briefingpage) # $t7, 0x8003
  lw    $t7, %lo(briefingpage)($t7)
  lui   $a1, %hi(mission_folder_setup_entries+0x14)
  move  $a0, $v0
  sll   $t8, $t7, 3
  subu  $t8, $t8, $t7
  sll   $t8, $t8, 2
  addu  $a1, $a1, $t8
  jal   check_if_cheat_unlocked
   lw    $a1, %lo(mission_folder_setup_entries+0x14)($a1)
  bnez  $v0, .L7F01D694
   lui   $a0, %hi(selected_folder_num) # $a0, 0x8003
  lui   $t9, %hi(briefingpage) # $t9, 0x8003
  lw    $t9, %lo(briefingpage)($t9)
  lui   $a1, %hi(mission_folder_setup_entries+0x14)
  lw    $a0, %lo(selected_folder_num)($a0)
  sll   $t0, $t9, 3
  subu  $t0, $t0, $t9
  sll   $t0, $t0, 2
  addu  $a1, $a1, $t0
  jal   sub_GAME_7F01E760
   lw    $a1, %lo(mission_folder_setup_entries+0x14)($a1)
  li    $t1, 1
  lui   $at, %hi(newcheatunlocked) # $at, 0x8007
  sw    $t1, %lo(newcheatunlocked)($at)
.L7F01D694:
  lw    $ra, 0x14($sp)
.L7F01D698:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop    
");
#endif

void sub_GAME_7F01D500(void) {
  get_screen_ratio_settings_for_mpgame_from_folder(selected_folder_num);
}

void deleteCurrentSelectedFolder(void) {
  delete_update_eeprom_file(selected_folder_num);
}

void copyCurrentEEPROMtoStack(void) {
  copy_eeprom_to_stack_set_folder_num(selected_folder_num);
}

unsigned char getSelectedFolderBond(void) {
  return removed_would_have_returned_bond_for_folder_num(selected_folder_num);
}

void set_selected_folder_num(unsigned int foldernum) {
  selected_folder_num = foldernum;
}

asm(R"
glabel set_selected_difficulty
  beqz  $a0, .L7F01D5C4
  li    $v0, 1
  beq   $a0, $v0, .L7F01D5D0
  lui   $at, %hi(selected_difficulty)
  li    $v0, 2
  beq   $a0, $v0, .L7F01D5D8
  lui   $at, %hi(selected_difficulty)
  li    $v0, 3
  beq   $a0, $v0, .L7F01D5E0
  lui   $at, %hi(selected_difficulty)
.L7F01D5C4:
  lui   $at, %hi(selected_difficulty)
  jr    $ra
  sw    $zero, %lo(selected_difficulty)($at)
.L7F01D5D0:
  jr    $ra
  sw    $v0, %lo(selected_difficulty)($at)
.L7F01D5D8:
  jr    $ra
  sw    $v0, %lo(selected_difficulty)($at)
.L7F01D5E0:
  sw    $v0, %lo(selected_difficulty)($at)
  jr    $ra
  nop   
");

void set_solo_and_ptr_briefing(LEVELID stage) {
  gamemode = GAMEMODE_SOLO;
  selected_stage = stage;
  briefingpage = pull_and_display_text_for_folder_a0(stage);
}

void sub_GAME_7F01D61C(struct save_file *savefile) {
  copy_eeprom_from_to(selected_folder_num, savefile);
}

void sub_GAME_7F01D644(int arg0) {
  selected_folder_num_copy = selected_folder_num;
  selected_folder_num = 0x64;
  copy_eepromfile_a0_from_a1_to_buffer(selected_folder_num, arg0);
}

void store_favorite_weapon_current_player(unsigned int right,
                                          unsigned int left) {
  unsigned int playerNum = get_cur_playernum();
  array_favweapon[playerNum][0] = right;
  array_favweapon[playerNum][1] = left;
}
