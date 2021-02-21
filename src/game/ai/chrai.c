#include "chrai.h"

struct sound_effect sound_effects[8];
void *ptr_list_object_lookup_indices;
unsigned int num_obj_position_data_entries;

unsigned char pos_data_entry[0x24];
unsigned char dword_CODE_bss_80069C5C;
unsigned char dword_CODE_bss_80069C5D;
unsigned char dword_CODE_bss_80069C5E;
unsigned char dword_CODE_bss_80069C5F;
unsigned char dword_CODE_bss_80069C60;
unsigned char dword_CODE_bss_80069C61;
unsigned char dword_CODE_bss_80069C62;
unsigned char dword_CODE_bss_80069C63;
unsigned char dword_CODE_bss_80069C64;
unsigned char dword_CODE_bss_80069C65;
unsigned char dword_CODE_bss_80069C66;
unsigned char dword_CODE_bss_80069C67;
unsigned char dword_CODE_bss_80069C68;
unsigned char dword_CODE_bss_80069C69;
unsigned char dword_CODE_bss_80069C6A;
unsigned char dword_CODE_bss_80069C6B;
unsigned char dword_CODE_bss_80069C6C;
unsigned char dword_CODE_bss_80069C6D;
unsigned char dword_CODE_bss_80069C6E;
unsigned char dword_CODE_bss_80069C6F;
unsigned char dword_CODE_bss_80069C70[0x20];
unsigned char dword_CODE_bss_80069C90[0xC];
unsigned char dword_CODE_bss_80069CA0[0x24];
unsigned int dword_CODE_bss_80069CC4;
unsigned int dword_CODE_bss_80069CC8;
unsigned int dword_CODE_bss_80069CCC;
unsigned int dword_CODE_bss_80069CD0;
unsigned int dword_CODE_bss_80069CD4;
unsigned int dword_CODE_bss_80069CD8;
unsigned int dword_CODE_bss_80069CDC;
unsigned char dword_CODE_bss_80069CE0[0x28];
unsigned char dword_CODE_bss_80069D08[0x34];
unsigned char dword_CODE_bss_80069D3C;
unsigned char dword_CODE_bss_80069D3D;
unsigned char dword_CODE_bss_80069D3E;
unsigned char dword_CODE_bss_80069D3F;
unsigned char dword_CODE_bss_80069D40[0x30];
unsigned char dword_CODE_bss_80069D70[0x34];
unsigned char dword_CODE_bss_80069DA4;
unsigned char dword_CODE_bss_80069DA5;
unsigned char dword_CODE_bss_80069DA6;
unsigned char dword_CODE_bss_80069DA7;
unsigned char dword_CODE_bss_80069DA8[0x7870];
void *ptr_room_lookup_buffer_maybe;
unsigned int dword_CODE_bss_8007161C;

char dword_CODE_bss_80071620[0x94];
char dword_CODE_bss_800716B4;
char dword_CODE_bss_800716B5;
char dword_CODE_bss_800716B6;
char dword_CODE_bss_800716B7;
char dword_CODE_bss_800716B8[0x738];
unsigned int dword_CODE_bss_80071DF0;
unsigned int dword_CODE_bss_80071DF4;
unsigned int dword_CODE_bss_80071DF8;
unsigned int dword_CODE_bss_80071DFC;
char temp_mine_table[0x78];

float gas_damage_flag;
unsigned int gas_cutoff_flag;
char ProjectileData_start_address[0xFF0];
char dword_CODE_bss_80072E70[0x500];
char dword_CODE_bss_80073370[0xA50];
char dword_CODE_bss_80073DC0[0x1270];
char dword_CODE_bss_80075030[0xB40];
unsigned int objinst;
unsigned int dword_CODE_bss_80075B74;
float flt_CODE_bss_80075B78;
float flt_CODE_bss_80075B7C;
float flt_CODE_bss_80075B80;
float flt_CODE_bss_80075B84;
float flt_CODE_bss_80075B88;
float flt_CODE_bss_80075B8C;
float flt_CODE_bss_80075B90;
float flt_CODE_bss_80075B94;
char dword_CODE_bss_80075B98[0x6C];
unsigned int dword_CODE_bss_80075C04;
unsigned int dword_CODE_bss_80075C08;
unsigned int dword_CODE_bss_80075C0C;
char dword_CODE_bss_80075C10[0x78];
char dword_CODE_bss_80075C88[0x78];

void *ptr_setup_path_tbl;
void *ptr_setup_path_link;
void *ptr_setup_intro;
struct object_standard *ptr_setup_objects;
void *ptr_setup_path_sets;
void *ptr_setup_actions;
void *ptr_0xxxpresets;
void *ptr_2xxxpresets;
unsigned int dword_CODE_bss_80075D20;
unsigned int dword_CODE_bss_80075D24;
unsigned int dword_CODE_bss_80075D28;

int D_80030A70 = 0;
int D_80030A74 = 0;
int D_80030A78 = 0;
int D_80030A7C = 0;
int D_80030A80 = 0;
int D_80030A84 = 0;
int D_80030A88 = 0;
int D_80030A8C = 0;
int D_80030A90 = 0;
int D_80030A94 = 0;
int D_80030A98 = 0;
int D_80030A9C = 0;
int *ptr_obj_pos_list_current_entry = 0;
int *ptr_obj_pos_list_first_entry = 0;
int *ptr_obj_pos_list_final_entry = 0;
float difficulty = 1.0;
int D_80030AB0 = 0;
int D_80030AB4 = 0;
int D_80030AB8 = 0;
int D_80030ABC = 0;

asm(R"
glabel set_sound_effect_source_to_location
  sll   $t6, $a0, 2
  addiu $sp, $sp, -0x28
  subu  $t6, $t6, $a0
  lui   $t7, %hi(sound_effects) 
  sw    $s0, 0x18($sp)
  addiu $t7, %lo(sound_effects) # addiu $t7, $t7, -0x6490
  sll   $t6, $t6, 3
  addu  $s0, $t6, $t7
  lw    $a1, ($s0)
  sw    $ra, 0x1c($sp)
  beql  $a1, $zero, .L7F0348D0
   sw    $zero, 4($s0)
  jal   sfxGetArg0Unk3F
   move  $a0, $a1
  beql  $v0, $zero, .L7F0348D0
   sw    $zero, 4($s0)
  lw    $a0, 0x10($s0)
  beql  $a0, $zero, .L7F034800
   lw    $v0, 0x14($s0)
  jal   sub_GAME_7F0539E4
   nop   
  b     .L7F034820
   sw    $v0, 0xc($s0)
  lw    $v0, 0x14($s0)
.L7F034800:
  beql  $v0, $zero, .L7F034824
   lw    $v1, 8($s0)
  lw    $t8, 0x10($v0)
  beql  $t8, $zero, .L7F034824
   lw    $v1, 8($s0)
  jal   sub_GAME_7F0539E4
   addiu $a0, $v0, 0x58
  sw    $v0, 0xc($s0)
.L7F034820:
  lw    $v1, 8($s0)
.L7F034824:
  lw    $a1, 0xc($s0)
  lui   $a0, %hi(clock_timer)
  bltz  $v1, .L7F034890
   move  $a2, $a1
  lw    $a0, %lo(clock_timer)($a0)
  slt   $at, $a0, $v1
  beqz  $at, .L7F03488C
   subu  $t2, $v1, $a0
  lw    $v0, 4($s0)
  subu  $t9, $a1, $v0
  multu $t9, $a0
  mflo  $t0
  nop   
  nop   
  div   $zero, $t0, $v1
  mflo  $t1
  addu  $a2, $t1, $v0
  bnez  $v1, .L7F034874
   nop   
  break 7
.L7F034874:
  li    $at, -1
  bne   $v1, $at, .L7F03488C
   lui   $at, 0x8000
  bne   $t0, $at, .L7F03488C
   nop   
  break 6
.L7F03488C:
  sw    $t2, 8($s0)
.L7F034890:
  jal   get_controls_locked_flag
   sw    $a2, 0x24($sp)
  beqz  $v0, .L7F0348A4
   lw    $a2, 0x24($sp)
  move  $a2, $zero
.L7F0348A4:
  lw    $t3, 4($s0)
  li    $a1, 8
  beql  $a2, $t3, .L7F0348D4
   lw    $ra, 0x1c($sp)
  lw    $a0, ($s0)
  jal   sfx_c_70009184
   sw    $a2, 0x24($sp)
  lw    $a2, 0x24($sp)
  b     .L7F0348D0
   sw    $a2, 4($s0)
  sw    $zero, 4($s0)
.L7F0348D0:
  lw    $ra, 0x1c($sp)
.L7F0348D4:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

void loop_set_sound_effect_all_slots(void) {
  int i = 0;
  do {
    set_sound_effect_source_to_location(i);
    i += 1;
  } while (i != 8);
}

asm(R"
glabel set_sound_effect_to_slot
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a1, 0x24($sp)
  bltz  $a0, .L7F03499C
   move  $a2, $zero
  slti  $at, $a0, 8
  beqz  $at, .L7F03499C
   sll   $t6, $a0, 2
  subu  $t6, $t6, $a0
  lui   $t7, %hi(sound_effects) 
  addiu $t7, %lo(sound_effects) # addiu $t7, $t7, -0x6490
  sll   $t6, $t6, 3
  addu  $v1, $t6, $t7
  lw    $a1, ($v1)
  beqz  $a1, .L7F03497C
   move  $a0, $a1
  sw    $v1, 0x18($sp)
  jal   sfxGetArg0Unk3F
   sw    $zero, 0x1c($sp)
  lw    $v1, 0x18($sp)
  bnez  $v0, .L7F03499C
   lw    $a2, 0x1c($sp)
.L7F03497C:
  li    $v0, 32767
  li    $t8, -1
  move  $a2, $v1
  sw    $v0, 0xc($v1)
  sw    $v0, 4($v1)
  sw    $t8, 8($v1)
  sw    $zero, 0x10($v1)
  sw    $zero, 0x14($v1)
.L7F03499C:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   lh    $a1, 0x26($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0349BC
  addiu $sp, $sp, -0x18
  bltz  $a0, .L7F0349EC
   sw    $ra, 0x14($sp)
  slti  $at, $a0, 8
  beqz  $at, .L7F0349EC
   sll   $t6, $a0, 2
  subu  $t6, $t6, $a0
  sll   $t6, $t6, 3
  lui   $a0, %hi(sound_effects)
  addu  $a0, $a0, $t6
  jal   sfxDeactivate
   lw    $a0, %lo(sound_effects)($a0)
.L7F0349EC:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel jpt_actionblock_lengths
.word action00_length
.word action01_length
.word locret_CODE_7F034A34
.word locret_CODE_7F034A3C
.word locret_CODE_7F034A44
.word locret_CODE_7F034A4C
.word locret_CODE_7F034A54
.word locret_CODE_7F034A5C
.word locret_CODE_7F034A64
.word locret_CODE_7F034A6C
.word locret_CODE_7F034A74
.word locret_CODE_7F034A7C
.word locret_CODE_7F034A84
.word locret_CODE_7F034A8C
.word locret_CODE_7F034A94
.word locret_CODE_7F034A9C
.word locret_CODE_7F034AA4
.word locret_CODE_7F034AAC
.word locret_CODE_7F034AB4
.word locret_CODE_7F034ABC
.word locret_CODE_7F034AC4
.word locret_CODE_7F034ACC
.word locret_CODE_7F034AE4
.word locret_CODE_7F034AEC
.word locret_CODE_7F034AF4
.word locret_CODE_7F034AFC
.word locret_CODE_7F034B04
.word locret_CODE_7F034B0C
.word locret_CODE_7F034B14
.word locret_CODE_7F034B1C
.word locret_CODE_7F034B24
.word locret_CODE_7F034B2C
.word locret_CODE_7F034B34
.word locret_CODE_7F034B3C
.word locret_CODE_7F034B44
.word locret_CODE_7F034B4C
.word locret_CODE_7F034B54
.word locret_CODE_7F034B5C
.word locret_CODE_7F034B64
.word locret_CODE_7F034B6C
.word locret_CODE_7F034B74
.word locret_CODE_7F034B7C
.word locret_CODE_7F034B84
.word locret_CODE_7F034B8C
.word locret_CODE_7F034B94
.word locret_CODE_7F034B9C
.word locret_CODE_7F034BA4
.word locret_CODE_7F034BAC
.word locret_CODE_7F034BB4
.word locret_CODE_7F034BBC
.word locret_CODE_7F034BC4
.word locret_CODE_7F034BCC
.word locret_CODE_7F034BD4
.word locret_CODE_7F034BDC
.word locret_CODE_7F034BE4
.word locret_CODE_7F034BEC
.word locret_CODE_7F034BF4
.word locret_CODE_7F034BFC
.word locret_CODE_7F034C04
.word locret_CODE_7F034C0C
.word locret_CODE_7F034C14
.word locret_CODE_7F034C1C
.word locret_CODE_7F034C24
.word locret_CODE_7F034C2C
.word locret_CODE_7F034C34
.word locret_CODE_7F034C3C
.word locret_CODE_7F034C44
.word locret_CODE_7F034C4C
.word locret_CODE_7F034C54
.word locret_CODE_7F034C5C
.word locret_CODE_7F034C64
.word locret_CODE_7F034C6C
.word locret_CODE_7F034C74
.word locret_CODE_7F034C7C
.word locret_CODE_7F034C84
.word locret_CODE_7F034C8C
.word locret_CODE_7F034C94
.word locret_CODE_7F034C9C
.word locret_CODE_7F034CA4
.word locret_CODE_7F034CAC
.word locret_CODE_7F034CB4
.word locret_CODE_7F034CBC
.word locret_CODE_7F034CC4
.word locret_CODE_7F034CCC
.word locret_CODE_7F034CD4
.word locret_CODE_7F034CDC
.word locret_CODE_7F034CE4
.word locret_CODE_7F034CEC
.word locret_CODE_7F034CF4
.word locret_CODE_7F034CFC
.word locret_CODE_7F034D04
.word locret_CODE_7F034D0C
.word locret_CODE_7F034D14
.word locret_CODE_7F034D1C
.word locret_CODE_7F034D24
.word locret_CODE_7F034D2C
.word locret_CODE_7F034D34
.word locret_CODE_7F034D3C
.word locret_CODE_7F034D44
.word locret_CODE_7F034D4C
.word locret_CODE_7F034D54
.word locret_CODE_7F034D5C
.word locret_CODE_7F034D64
.word locret_CODE_7F034D6C
.word locret_CODE_7F034D74
.word locret_CODE_7F034D7C
.word locret_CODE_7F034D84
.word locret_CODE_7F034D8C
.word locret_CODE_7F034D94
.word locret_CODE_7F034D9C
.word locret_CODE_7F034DA4
.word locret_CODE_7F034DAC
.word locret_CODE_7F034DB4
.word locret_CODE_7F034DBC
.word locret_CODE_7F034DC4
.word locret_CODE_7F034DCC
.word locret_CODE_7F034DD4
.word locret_CODE_7F034DDC
.word locret_CODE_7F034DE4
.word locret_CODE_7F034DEC
.word locret_CODE_7F034DF4
.word locret_CODE_7F034DFC
.word locret_CODE_7F034E04
.word locret_CODE_7F034E0C
.word locret_CODE_7F034E14
.word locret_CODE_7F034E1C
.word locret_CODE_7F034E24
.word locret_CODE_7F034E2C
.word locret_CODE_7F034E34
.word locret_CODE_7F034E3C
.word locret_CODE_7F034E44
.word locret_CODE_7F034E4C
.word locret_CODE_7F034E54
.word locret_CODE_7F034E5C
.word locret_CODE_7F034E64
.word locret_CODE_7F034E6C
.word locret_CODE_7F034E74
.word locret_CODE_7F034E7C
.word locret_CODE_7F034E84
.word locret_CODE_7F034E8C
.word locret_CODE_7F034E94
.word locret_CODE_7F034E9C
.word locret_CODE_7F034EA4
.word locret_CODE_7F034EAC
.word locret_CODE_7F034EB4
.word locret_CODE_7F034EBC
.word locret_CODE_7F034EC4
.word locret_CODE_7F034ECC
.word locret_CODE_7F034ED4
.word locret_CODE_7F034EDC
.word locret_CODE_7F034EE4
.word locret_CODE_7F034EEC
.word locret_CODE_7F034EF4
.word locret_CODE_7F034EFC
.word locret_CODE_7F034F04
.word locret_CODE_7F034F0C
.word locret_CODE_7F034F14
.word locret_CODE_7F034F1C
.word locret_CODE_7F034F24
.word locret_CODE_7F034F2C
.word locret_CODE_7F034F34
.word locret_CODE_7F034F3C
.word locret_CODE_7F034F44
.word locret_CODE_7F034F4C
.word locret_CODE_7F034F54
.word locret_CODE_7F034F5C
.word locret_CODE_7F034F64
.word locret_CODE_7F034F6C
.word locret_CODE_7F034F74
.word locret_CODE_7F034F7C
.word locret_CODE_7F034F84
.word locret_CODE_7F034F8C
.word locret_CODE_7F034F94
.word actionAD_length

.text
glabel get_length_of_action_block #(CurrentActionByte)
  addu  $v0, $a0, $a1      #v0 = CurrentActionByte
  lbu   $t6, ($v0)         #t6= Action = byte(v0)
  sltiu $at, $t6, 0xfd               #if not Action less than AI_CMDS_TOTAL
  beqz  $at, ActionLengthSwitchElse  #   Action << 2
   sll   $t6, $t6, 2                 #   return 1 //goto ActionLengthSwitchElse
  lui   $at, %hi(jpt_actionblock_lengths)                  #else
  addu  $at, $at, $t6      # at = 8005 + t6
  lw    $t6, %lo(jpt_actionblock_lengths)($at)             # Switch Action
  jr    $t6                # jump to address held at 80052100+at = Select Case t6
   nop   
action00_length:
  jr    $ra
   li    $v0, 2 #return 2
action01_length:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034A34:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034A3C:
  jr    $ra
   li    $v0, 1
locret_CODE_7F034A44:
  jr    $ra
   li    $v0, 1
locret_CODE_7F034A4C:
  jr    $ra
   li    $v0, 4
locret_CODE_7F034A54:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034A5C:
  jr    $ra
   li    $v0, 1
locret_CODE_7F034A64:
  jr    $ra
   li    $v0, 1
locret_CODE_7F034A6C:
  jr    $ra
   li    $v0, 1
locret_CODE_7F034A74:
  jr    $ra
   li    $v0, 9
locret_CODE_7F034A7C:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034A84:
  jr    $ra
   li    $v0, 1
locret_CODE_7F034A8C:
  jr    $ra
   li    $v0, 1
locret_CODE_7F034A94:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034A9C:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034AA4:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034AAC:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034AB4:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034ABC:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034AC4:
  jr    $ra
   li    $v0, 6
locret_CODE_7F034ACC:
  jr    $ra
   li    $v0, 6
locret_CODE_7F034AD4:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034ADC:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034AE4:
  jr    $ra
   li    $v0, 6
locret_CODE_7F034AEC:
  jr    $ra
   li    $v0, 6
locret_CODE_7F034AF4:
  jr    $ra
   li    $v0, 4
locret_CODE_7F034AFC:
  jr    $ra
   li    $v0, 4
locret_CODE_7F034B04:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034B0C:
  jr    $ra
   li    $v0, 5
locret_CODE_7F034B14:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034B1C:
  jr    $ra
   li    $v0, 1
locret_CODE_7F034B24:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034B2C:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034B34:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034B3C:
  jr    $ra
   li    $v0, 1
locret_CODE_7F034B44:
  jr    $ra
   li    $v0, 1
locret_CODE_7F034B4C:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034B54:
  jr    $ra
   li    $v0, 4
locret_CODE_7F034B5C:
  jr    $ra
   li    $v0, 1
locret_CODE_7F034B64:
  jr    $ra
   li    $v0, 1
locret_CODE_7F034B6C:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034B74:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034B7C:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034B84:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034B8C:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034B94:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034B9C:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034BA4:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034BAC:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034BB4:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034BBC:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034BC4:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034BCC:
  jr    $ra
   li    $v0, 1
locret_CODE_7F034BD4:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034BDC:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034BE4:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034BEC:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034BF4:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034BFC:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034C04:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034C0C:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034C14:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034C1C:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034C24:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034C2C:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034C34:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034C3C:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034C44:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034C4C:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034C54:
  jr    $ra
   li    $v0, 4
locret_CODE_7F034C5C:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034C64:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034C6C:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034C74:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034C7C:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034C84:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034C8C:
  jr    $ra
   li    $v0, 4
locret_CODE_7F034C94:
  jr    $ra
   li    $v0, 4
locret_CODE_7F034C9C:
  jr    $ra
   li    $v0, 7
locret_CODE_7F034CA4:
  jr    $ra
   li    $v0, 7
locret_CODE_7F034CAC:
  jr    $ra
   li    $v0, 5
locret_CODE_7F034CB4:
  jr    $ra
   li    $v0, 5
locret_CODE_7F034CBC:
  jr    $ra
   li    $v0, 4
locret_CODE_7F034CC4:
  jr    $ra
   li    $v0, 6
locret_CODE_7F034CCC:
  jr    $ra
   li    $v0, 6
locret_CODE_7F034CD4:
  jr    $ra
   li    $v0, 5
locret_CODE_7F034CDC:
  jr    $ra
   li    $v0, 4
locret_CODE_7F034CE4:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034CEC:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034CF4:
  jr    $ra
   li    $v0, 4
locret_CODE_7F034CFC:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034D04:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034D0C:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034D14:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034D1C:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034D24:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034D2C:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034D34:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034D3C:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034D44:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034D4C:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034D54:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034D5C:
  jr    $ra
   li    $v0, 4
locret_CODE_7F034D64:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034D6C:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034D74:
  jr    $ra
   li    $v0, 4
locret_CODE_7F034D7C:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034D84:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034D8C:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034D94:
  jr    $ra
   li    $v0, 4
locret_CODE_7F034D9C:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034DA4:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034DAC:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034DB4:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034DBC:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034DC4:
  jr    $ra
   li    $v0, 4
locret_CODE_7F034DCC:
  jr    $ra
   li    $v0, 4
locret_CODE_7F034DD4:
  jr    $ra
   li    $v0, 4
locret_CODE_7F034DDC:
  jr    $ra
   li    $v0, 4
locret_CODE_7F034DE4:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034DEC:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034DF4:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034DFC:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034E04:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034E0C:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034E14:
  jr    $ra
   li    $v0, 4
locret_CODE_7F034E1C:
  jr    $ra
   li    $v0, 4
locret_CODE_7F034E24:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034E2C:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034E34:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034E3C:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034E44:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034E4C:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034E54:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034E5C:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034E64:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034E6C:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034E74:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034E7C:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034E84:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034E8C:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034E94:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034E9C:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034EA4:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034EAC:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034EB4:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034EBC:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034EC4:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034ECC:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034ED4:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034EDC:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034EE4:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034EEC:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034EF4:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034EFC:
  jr    $ra
   li    $v0, 4
locret_CODE_7F034F04:
  jr    $ra
   li    $v0, 5
locret_CODE_7F034F0C:
  jr    $ra
   li    $v0, 5
locret_CODE_7F034F14:
  jr    $ra
   li    $v0, 6
locret_CODE_7F034F1C:
  jr    $ra
   li    $v0, 5
locret_CODE_7F034F24:
  jr    $ra
   li    $v0, 5
locret_CODE_7F034F2C:
  jr    $ra
   li    $v0, 6
locret_CODE_7F034F34:
  jr    $ra
   li    $v0, 6
locret_CODE_7F034F3C:
  jr    $ra
   li    $v0, 6
locret_CODE_7F034F44:
  jr    $ra
   li    $v0, 7
locret_CODE_7F034F4C:
  jr    $ra
   li    $v0, 6
locret_CODE_7F034F54:
  jr    $ra
   li    $v0, 6
locret_CODE_7F034F5C:
  jr    $ra
   li    $v0, 7
locret_CODE_7F034F64:
  jr    $ra
   li    $v0, 6
locret_CODE_7F034F6C:
  jr    $ra
   li    $v0, 6
locret_CODE_7F034F74:
  jr    $ra
   li    $v0, 7
locret_CODE_7F034F7C:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034F84:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034F8C:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034F94:
  jr    $ra
   li    $v0, 4
locret_CODE_7F034F9C:
  jr    $ra
   li    $v0, 1
locret_CODE_7F034FA4:
  jr    $ra
   li    $v0, 1
locret_CODE_7F034FAC:
  jr    $ra
   li    $v0, 1
locret_CODE_7F034FB4:
  jr    $ra
   li    $v0, 1
locret_CODE_7F034FBC:
  jr    $ra
   li    $v0, 2
locret_CODE_7F034FC4:
  jr    $ra
   li    $v0, 5
locret_CODE_7F034FCC:
  jr    $ra
   li    $v0, 5
locret_CODE_7F034FD4:
  jr    $ra
   li    $v0, 1
locret_CODE_7F034FDC:
  jr    $ra
   li    $v0, 1
locret_CODE_7F034FE4:
  jr    $ra
   li    $v0, 3
locret_CODE_7F034FEC:
  jr    $ra
   li    $v0, 1
locret_CODE_7F034FF4:
  jr    $ra
   li    $v0, 1
locret_CODE_7F034FFC:
  jr    $ra
   li    $v0, 2
locret_CODE_7F035004:
  jr    $ra
   li    $v0, 4
locret_CODE_7F03500C:
  jr    $ra
   li    $v0, 4
locret_CODE_7F035014:
  jr    $ra
   li    $v0, 12
locret_CODE_7F03501C:
  jr    $ra
   li    $v0, 11
locret_CODE_7F035024:
  jr    $ra
   li    $v0, 9
locret_CODE_7F03502C:
  jr    $ra
   li    $v0, 8
locret_CODE_7F035034:
  jr    $ra
   li    $v0, 5
locret_CODE_7F03503C:
  jr    $ra
   li    $v0, 3
locret_CODE_7F035044:
  jr    $ra
   li    $v0, 3
locret_CODE_7F03504C:
  jr    $ra
   li    $v0, 4
locret_CODE_7F035054:
  jr    $ra
   li    $v0, 5
locret_CODE_7F03505C:
  jr    $ra
   li    $v0, 6
locret_CODE_7F035064:
  jr    $ra
   li    $v0, 6
locret_CODE_7F03506C:
  jr    $ra
   li    $v0, 6
locret_CODE_7F035074:
  jr    $ra
   li    $v0, 2
locret_CODE_7F03507C:
  jr    $ra
   li    $v0, 5
locret_CODE_7F035084:
  jr    $ra
   li    $v0, 2
locret_CODE_7F03508C:
  jr    $ra
   li    $v0, 5
locret_CODE_7F035094:
  jr    $ra
   li    $v0, 5
locret_CODE_7F03509C:
  jr    $ra
   li    $v0, 2
locret_CODE_7F0350A4:
  jr    $ra
   li    $v0, 2
locret_CODE_7F0350AC:
  jr    $ra
   li    $v0, 4
locret_CODE_7F0350B4:
  jr    $ra
   li    $v0, 2
locret_CODE_7F0350BC:
  jr    $ra
   li    $v0, 1
locret_CODE_7F0350C4:
  jr    $ra
   li    $v0, 1
locret_CODE_7F0350CC:
  jr    $ra
   li    $v0, 3
locret_CODE_7F0350D4:
  jr    $ra
   li    $v0, 6
locret_CODE_7F0350DC:
  jr    $ra
   li    $v0, 4
locret_CODE_7F0350E4:
  jr    $ra
   li    $v0, 2
locret_CODE_7F0350EC:
  jr    $ra
   li    $v0, 1
locret_CODE_7F0350F4:
  jr    $ra
   li    $v0, 5
locret_CODE_7F0350FC:
  jr    $ra
   li    $v0, 1
locret_CODE_7F035104:
  jr    $ra
   li    $v0, 1
locret_CODE_7F03510C:
  jr    $ra
   li    $v0, 2
locret_CODE_7F035114:
  jr    $ra
   li    $v0, 1
locret_CODE_7F03511C:
  jr    $ra
   li    $v0, 1
locret_CODE_7F035124:
  jr    $ra
   li    $v0, 2
locret_CODE_7F03512C:
  jr    $ra
   li    $v0, 3
locret_CODE_7F035134:
  jr    $ra
   li    $v0, 3
locret_CODE_7F03513C:
  jr    $ra
   li    $v0, 4
locret_CODE_7F035144:
  jr    $ra
   li    $v0, 2
locret_CODE_7F03514C:
  jr    $ra
   li    $v0, 2
locret_CODE_7F035154:
  jr    $ra
   li    $v0, 3
locret_CODE_7F03515C:
  jr    $ra
   li    $v0, 5
locret_CODE_7F035164:
  jr    $ra
   li    $v0, 1
locret_CODE_7F03516C:
  jr    $ra
   li    $v0, 1
locret_CODE_7F035174:
  jr    $ra
   li    $v0, 2
locret_CODE_7F03517C:
  jr    $ra
   li    $v0, 1
locret_CODE_7F035184:
  jr    $ra
   li    $v0, 1
locret_CODE_7F03518C:
  jr    $ra
   li    $v0, 13
locret_CODE_7F035194:
  jr    $ra
   li    $v0, 1
locret_CODE_7F03519C:
  jr    $ra
   li    $v0, 2
locret_CODE_7F0351A4:
  jr    $ra
   li    $v0, 2
locret_CODE_7F0351AC:
  jr    $ra
   li    $v0, 3
locret_CODE_7F0351B4:
  jr    $ra
   li    $v0, 2
locret_CODE_7F0351BC:
  jr    $ra
   li    $v0, 4
locret_CODE_7F0351C4:
  jr    $ra
   li    $v0, 2
locret_CODE_7F0351CC:
  jr    $ra
   li    $v0, 1
locret_CODE_7F0351D4:
  jr    $ra
   li    $v0, 3
locret_CODE_7F0351DC:
  jr    $ra
   li    $v0, 3
locret_CODE_7F0351E4:
  jr    $ra
   li    $v0, 1
locret_CODE_7F0351EC:
  jr    $ra
   li    $v0, 1
locret_CODE_7F0351F4:
  jr    $ra
   li    $v0, 1
actionFC_length:
  jr    $ra
   li    $v0, 2

actionAD_length:
  lbu   $t7, 1($v0)
  addiu $v1, $a1, 1
  addu  $v0, $a0, $v1
  beql  $t7, $zero, .L7F035230
   subu  $v0, $v1, $a1
  lbu   $t8, 1($v0)
.L7F03521C:
  addiu $v1, $v1, 1
  addiu $v0, $v0, 1
  bnezl $t8, .L7F03521C
   lbu   $t8, 1($v0)
  subu  $v0, $v1, $a1
.L7F035230:
  jr    $ra
   addiu $v0, $v0, 1

invalid_type:
ActionLengthSwitchElse:
  li    $v0, 1
  jr    $ra
   nop   
");

asm(R"
.late_rodata
/*HACK FIXME */
.word locret_CODE_7F034F9C
.word locret_CODE_7F034FA4
.word locret_CODE_7F034FAC
.word locret_CODE_7F034FB4
.word locret_CODE_7F034FBC
.word locret_CODE_7F034FC4
.word locret_CODE_7F034FCC
.word locret_CODE_7F034FD4
.word locret_CODE_7F034FDC
.word locret_CODE_7F034FE4
.word locret_CODE_7F034FEC
.word locret_CODE_7F034FF4
.word locret_CODE_7F034FFC
.word locret_CODE_7F035004

.text
glabel sub_GAME_7F035244
  lui   $t0, %hi(ptr_setup_path_tbl) 
  addiu $t0, %lo(ptr_setup_path_tbl) # addiu $t0, $t0, 0x5d00
  lw    $v0, 0x14($t0) #v0 = ptr_setup_actions
  move  $a3, $a1
  lui   $t9, %hi(D_8003744C)
  beqz  $v0, .L7F0352A8
   nop   
  lw    $t6, ($v0)
  move  $v1, $zero
  move  $a1, $v0
  beqz  $t6, .L7F0352A8
   nop   
  lw    $a2, ($v0)
.L7F035278:
  bnel  $a0, $a2, .L7F035298
   lw    $a2, 8($a1)
  sw    $zero, ($a3)
  lw    $t7, 0x14($t0)
  addu  $t8, $t7, $v1
  jr    $ra
   lw    $v0, 4($t8)

  lw    $a2, 8($a1)
.L7F035298:
  addiu $v1, $v1, 8
  addiu $a1, $a1, 8
  bnez  $a2, .L7F035278
   nop   
.L7F0352A8:
  lw    $t9, %lo(D_8003744C)($t9)
  lui   $t1, %hi(D_8003744C)
  addiu $v1, $t1, %lo(D_8003744C)
  beqz  $t9, .L7F0352E4
   li    $t2, 1
  lw    $v0, ($v1)
.L7F0352C0:
  bnel  $a0, $v0, .L7F0352D8
   lw    $v0, 8($v1)
  sw    $t2, ($a3)
  jr    $ra
   lw    $v0, 4($v1)

  lw    $v0, 8($v1)
.L7F0352D8:
  addiu $v1, $v1, 8
  bnez  $v0, .L7F0352C0
   nop   
.L7F0352E4:
  li    $v0, -1
  jr    $ra
   nop   
");

asm(R"
.late_rodata
/*HACK FIXME */
.word locret_CODE_7F03500C
.word locret_CODE_7F035014
.word locret_CODE_7F03501C
.word locret_CODE_7F035024
.word locret_CODE_7F03502C
.word locret_CODE_7F035034
.word locret_CODE_7F03503C
.word locret_CODE_7F035044
.word locret_CODE_7F03504C
.word locret_CODE_7F035054
.word locret_CODE_7F03505C
.word locret_CODE_7F035064
.word locret_CODE_7F03506C

.text
glabel true_if_sucessfully_performing_action
  addiu $sp, $sp, -0x48
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  move  $s0, $a1						# Args 1,0 to save 0,1
  move  $s1, $a0
  andi  $s2, $a2, 0xff				# save 2 = Arg 2 AND 255 - convert to lower byte?
  sw    $ra, 0x2c($sp)
  sw    $a2, 0x50($sp)				# save a bunch of stuff
  li    $s3, 2
  li    $s4, 4
.L7F035324:	 														/* Begining*/
  addu  $v0, $s1, $s0					# *v0 = a0 + a1 # command+commandLength?
  lbu   $v1, ($v0)					# v1 = Byte(v0)
  move  $a0, $s1
  bne   $s3, $v1, .L7F03534C			# goto not2 if not v1 = label_ID
   nop
  lbu   $t6, 1($v0)					# t6 = byte(v0[4])
  bne   $s2, $t6, .L7F035368			# goto AICMDlength if not s2 = t6
   nop
  b     .L7F035378					# save 0 = v0 goto return
   move  $v0, $s0
.L7F03534C: 														/* Not2*/
  bne   $s4, $v1, .L7F035368			# goto AICMDlength if not v1 = ai_list_end_ID
   nop   
  move  $a0, $s1
  jal   sub_GAME_7F035244
   addiu $a1, $sp, 0x3c
  b     .L7F035378					# goto return
   move  $v0, $zero
.L7F035368: 														/* AICMDlength*/
  jal   get_length_of_action_block
   move  $a1, $s0
  b     .L7F035324					# goto begining
   addu  $s0, $s0, $v0
.L7F035378: 														/* return*/
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  lw    $s3, 0x24($sp)
  lw    $s4, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x48
");

asm(R"
.late_rodata
/*HACK FIXME */
.word locret_CODE_7F035074
.word locret_CODE_7F03507C
.word locret_CODE_7F035084
.word locret_CODE_7F03508C
.word locret_CODE_7F035094
.word locret_CODE_7F03509C
.word locret_CODE_7F0350A4
.word locret_CODE_7F0350AC
.word locret_CODE_7F0350B4
.word locret_CODE_7F0350BC
.word locret_CODE_7F0350C4
.word locret_CODE_7F0350CC

.text
glabel LoadNext_PrevActionBlock
  slti  $at, $a0, 0x401
  bnez  $at, .L7F0353F0
   lui   $t9, %hi(D_8003744C)
  lui   $v0, %hi(ptr_setup_actions)
  lw    $v0, %lo(ptr_setup_actions)($v0)
  beql  $v0, $zero, .L7F03542C #if <= 0 return
   move  $v0, $zero
  lw    $t6, ($v0)
  move  $v1, $v0
  beql  $t6, $zero, .L7F03542C
   move  $v0, $zero
  lw    $t7, 4($v1)
.L7F0353C8:
  bnel  $a0, $t7, .L7F0353DC
   lw    $t8, 8($v1)
  jr    $ra
   lw    $v0, ($v1)

  lw    $t8, 8($v1)
.L7F0353DC:
  addiu $v1, $v1, 8
  bnezl $t8, .L7F0353C8
   lw    $t7, 4($v1)
  b     .L7F03542C
   move  $v0, $zero
.L7F0353F0:
  lw    $t9, %lo(D_8003744C)($t9)
  lui   $v1, %hi(D_8003744C)
  addiu $v1, %lo(D_8003744C) # addiu $v1, $v1, 0x744c
  beql  $t9, $zero, .L7F03542C
   move  $v0, $zero
  lw    $t0, 4($v1)
.L7F035408:
  bnel  $a0, $t0, .L7F03541C
   lw    $t1, 8($v1)
  jr    $ra
   lw    $v0, ($v1)

  lw    $t1, 8($v1)
.L7F03541C:
  addiu $v1, $v1, 8
  bnezl $t1, .L7F035408
   lw    $t0, 4($v1)
  move  $v0, $zero
.L7F03542C:
  jr    $ra
   nop   
");

asm(R"
.late_rodata
/*HACK FIXME */
.word locret_CODE_7F0350D4
.word locret_CODE_7F0350DC
.word locret_CODE_7F0350E4
.word locret_CODE_7F0350EC
.word locret_CODE_7F0350F4
.word locret_CODE_7F0350FC

.text
glabel get_ptr_path_for_pathnum
  lui   $a1, %hi(ptr_setup_path_sets)
  lw    $a1, %lo(ptr_setup_path_sets)($a1)
  move  $v1, $zero
  lw    $t6, ($a1)
  move  $v0, $a1
  beql  $t6, $zero, .L7F03547C
   move  $v0, $zero
  lbu   $t7, 4($v0)
.L7F035454:
  bne   $a0, $t7, .L7F035464
   sll   $t8, $v1, 3
  jr    $ra
   addu  $v0, $t8, $a1

.L7F035464:
  lw    $t9, 8($v0)
  addiu $v1, $v1, 1
  addiu $v0, $v0, 8
  bnezl $t9, .L7F035454
   lbu   $t7, 4($v0)
  move  $v0, $zero
.L7F03547C:
  jr    $ra
   nop   
");

#ifdef VERSION_US
asm(R"
.late_rodata
/*HACK FIXME */
.word locret_CODE_7F035104
.word locret_CODE_7F03510C
.word locret_CODE_7F035114
.word locret_CODE_7F03511C
.word locret_CODE_7F035124
.word locret_CODE_7F03512C
.word locret_CODE_7F035134
.word locret_CODE_7F03513C
.word locret_CODE_7F035144
.word locret_CODE_7F03514C
.word locret_CODE_7F035154
.word locret_CODE_7F03515C
.word locret_CODE_7F034ADC
.word locret_CODE_7F034AD4
.word locret_CODE_7F035164
.word locret_CODE_7F03516C
.word locret_CODE_7F035174
.word locret_CODE_7F03517C
.word locret_CODE_7F035184
.word locret_CODE_7F03518C
.word locret_CODE_7F035194
.word locret_CODE_7F03519C
.word locret_CODE_7F0351A4
.word locret_CODE_7F0351AC
.word locret_CODE_7F0351B4
.word locret_CODE_7F0351BC
.word locret_CODE_7F0351C4
.word locret_CODE_7F0351CC
.word locret_CODE_7F0351D4
.word locret_CODE_7F0351DC
.word locret_CODE_7F0351E4
.word locret_CODE_7F0351EC
.word locret_CODE_7F0351F4
.word actionFC_length
.late_rodata
glabel D_800524F4
.word 0x40c90fdb /*6.2831855*/
/*D:800524F8*/
glabel jpt_800524F8
.word Action00_GoToLabel
.word Action01_GoToLabelFromTop
.word Action02_Label
.word action03_Leave_The_Routine_When_Return_Continue_From_Spot_1
.word Action04_End_1
.word action05_Jump_To_Function_4
.word action06_Set_Return_Subroutine_for_0007_Command_3
.word action07_Jump_to_Return_Subroutine_1
.word action08_Reset_Animation_1
.word action09_Guard_Kneels_1
.word action0A_Animation_9
.word action0B_If_Guard_WastingTime_SwatFlies_RVL_2
.word action0C_Guard_Gestures_1
.word action0D_Guard_Looks_Around_When_Shot_At_1
.word action0E_Guard_Steps_Sideways_RVL_2
.word action0F_Guard_Hops_Sideways_RVL_2
.word action10_Guard_Runs_Sideways_RVL_2
.word action11_Guard_Walks_Firing_RVL_2
.word action12_Guard_Runs_Firing_RVL_2
.word action13_Guard_Rolls_On_Ground_Then_Fires_Crouched_RVL_2
.word action14_Guard_Aims_Shoots_at_Bond_Guard_Pad_RVL_6
.word action15_Guard_Kneels_Aims_Shoots_at_Bond_Guard_Pad_RVL_6
.word action16_Guard_Shoots_Guards_Without_Animation_Change_RVL_6
.word action17_Guard_Constantly_Angles_To_Face_RVL_6
.word action18_Shoot_Guard_ID_In_Style_With_Weapon_Type_num_4
.word action19_Guard_ID1_Shoots_Guard_ID2_In_Style_4
.word action1A_Guard_Throws_Grenade_RVL_2
.word action1B_Drop_Weapon_Inventory_num_RVL_5
.word action1C_Guard_Jogs_To_Preset_3
.word action1D_Guard_Jogs_To_Predefined_Preset_2328_1
.word action1E_Guard_Walks_To_Preset_3
.word action1F_Guard_Runs__To_Preset_3
.word action20_Activate_Path_2
.word action21_Guard_Surrenders_1
.word action22_Guard_Set_To_Move_Fades_And_Disappear_1
.word action23_Eliminate_Guard_ID_2
.word action24_Activate_Object_At_Preset_RVL_If_Successful_4
.word action25_Sound_Alarm_1
.word action26_Turn_Off_Alarm_1
.word action27_Return_False_Invalid_Type_2
.word action28_Jog_To_Bond_Return_Loop_When_Reached_Bond_2
.word action29_Walk_To_Bond_Return_Loop_When_Reached_Bond_2
.word action2A_Run_To_Bond_Return_Loop_When_Reached_Bond_2
.word action2B_Return_False_Invalid_Type_2
.word action2C_Jog_To_Character_Position_RVL_On_Arrival_3
.word action2D_Walk_To_Character_Position_RVL_On_Arrival_3
.word action2E_Run_To_Character_Position_RVL_On_Arrival_3
.word action2F_When_Guard_Stops_Moving_RVL_2
.word action30_Detect_If_Guard_Killed_RVL_If_So_3
.word action31_If_GuardID_Finish_DeathAnimation_RVL_3
.word action32_If_Bond_In_Sight_RVL_2
.word action33_Seed_Random_Byte_1
.word action34_If_Seeded_Byte_LTV_Go_Into_RVL_3
.word action35_If_Seeded_Byte_GTV_Go_Into_RVL_3
.word action36_If_Alarm_Activated_RVL_Plus_Stack_2
.word action37_If_Alarm_Activated_RVL_2
.word action38_If_Toxic_Gas_Released_RVL_2
.word action39_If_Guard_Heard_Gunfire_RVL_2
.word action3A_If_Bond_Shoots_Another_Guard_RVL_2
.word action3B_If_Guard_Killed_In_Front_Of_Guard_RVL_2
.word action3C_If_Guard_In_Firing_Range_RVL_2
.word action3D___Unused___Unknown___2
.word action3E_If_Shot_Current_Guard_RVL_2
.word action3F_If_Heard_Bond_RVL_2
.word action40_If_Another_Guard_In_Same_Room_As_Guard_ID_RVL_3
.word action41_If_Guard_Has_Been_On_Screen_RVL_2
.word action42_If_Current_Guard_On_Screen_In_Loaded_Room_RVL_2
.word action43_If_Guard_In_A_Room_Currently_Loaded_RVL_2
.word action44_If_Room_Containing_Preset_Is_Loaded_RVL_4
.word action45_Go_To_RVL_If_Bond_Has_Guard_At_Gunpoint_2
.word action46_If_Fired_A_Shot_RVL_2
.word action47_If_Distance_Between_Bond_And_Guard_LTV_RVL_3
.word action48_If_Distance_Between_Bond_And_Guard_GTV_RVL_3
.word action49_Test_if_Actor_and_Player_CCWAngle_LTV_RVL_Unused_3
.word action4A_Test_if_Actor_and_Player_CCWAngle_GTV_RVL_Unused_3
.word action4B_RVL_If_In_Proximity_Of_Bond_4
.word action4C_RVL_If_Not_In_Proximity_Of_Bond_4
.word action4D_When_Guard_In_Proximity_Of_Preset_RVL_7
.word action4E_When_Guard_Not_In_Proximity_Of_Preset_RVL_7
.word action4F_If_Current_Guard_Is_In_Units_Of_Guard_ID_RVL_5
.word action50_If_Current_Guard_Is_Not_In_Units_Of_Guard_ID_RVL_5
.word action51_SetClosestGuardUnitsGuardID_Then_RVL_IfSuccess_4
.word action52_GoIntoRVLIf_In_Units_Of_Preset_6
.word action53_GoIntoRVLIf_Not_In_Units_Of_Preset_6
.word action54_GoIntoRVLIf_Guard_Is_At_Preset_5
.word action55_GoIntoRVLIf_Entered_Room_with_Preset_4
.word action56_GoIntoRVLIf_16_Object_num_Collected_3
.word action57_GoIntoRVLIf_Specified_Weapon_Deposited_3
.word action58_GoIntoRVLIf_SpecifiedWeaponDeposited_On16Object_4
.word action59_GoIntoRVLIf_Specified_Weapon_Is_Out_3
.word action5A_GoIntoRVLIf_Type_16_Object_num_Loaded_3
.word action5B_GoIntoRVLIf_16_Object_num_Not_Destroyed_3
.word action5C_GoIntoRVLIf_16_Object_num_Activated_3
.word action5D_GoIntoRVLIf_Gadget_Used_On_16_Object_num_3
.word action5E_16_Object_Activates_2
.word action5F_16_Object_Explodes_2
.word action60_Guard_Drops_16_Object_num_2
.word action61_Kill_Guard_num_2
.word action62_Guard_num_Throws_Equipment_2
.word action63_Guard_Gives_Bond_16_Object_num_2
.word action64_Type_16_Object_Equipped_On_Guard_3
.word action65_Object_Moved_To_Preset_4
.word action66_Open_Door_2
.word action67_Close_Door_2
.word action68_Check_Door_Status_RVL_If_Met_4
.word action69_If_16_Object_Is_Valid_Door_RVL_3
.word action6A_Set_Bits_To_Lock_On_Type_16_Door_3
.word action6B_Unset_Bits_To_Lock_On_Type_16_Door_3
.word action6C_If_Tagged_Locked_Door_16_Objects_Toggled_RVL_4
.word action6D_If_Objective_num_Complete_RVL_3
.word action6E_If_Guard_2328_Preset_RVL_3
.word action6F_If_Guard_2328_Preset_Set_RVL_3
.word action70_Go_Into_RVL_Difficulty_LTV_3
.word action71_GoIntoRVLIf_Difficulty_GTV_3
.word action72_Go_To_RVL_If_Time_LTV_4
.word action73_Go_To_RVL_If_Time_GTV_4
.word action74_Go_To_RVL_If_Power_On_Time_LTV_4
.word action75_Go_To_RVL_If_Power_On_Time_GTV_4
.word action76_Go_To_RVL_If_Stage_Number_LTV_3
.word action77_Go_To_RVL_If_Stage_Number_GTV_3
.word action78_Go_To_RVL_If_Guard_Shot_LTV_3
.word action79_Go_To_RVL_If_Guard_Shot_GTV_3
.word action7A_Go_To_RVL_If_Number_Near_Miss_Gunshots_LTV_3
.word action7B_Go_To_RVL_If_Number_Near_Miss_Gunshots_GTV_3
.word action7C_If_Guard_Health_Below_Value_RVL_4
.word action7D_If_Guard_Health_Above_Value_RVL_4
.word action7E_If_Guard_nums_Bitflag_01000000_Set_RVL_3
.word action7F_If_Health_Below_Value_RVL_3
.word action80_If_Health_Above_Value_RVL_3
.word action81_Set_User_Byte_num1_2
.word action82_Add_Value_To_User_Byte_num1_Max_To_FF_2
.word action83_Subtract_Value_To_User_Byte_num1_Min_To_0_2
.word action84_If_Value_GreaterThan_User_Byte_num1_RVL_3
.word action85_If_User_Byte_num1_LessThan_Random_Value_RVL_2
.word action86_Set_User_Byte_num2_2
.word action87_Add_Value_To_User_Byte_num2_Max_To_FF_2
.word action88_Subtract_Value_To_User_Byte_num2_Min_To_0_2
.word action89_If_Value_GreaterThan_User_Byte_num2_RVL_3
.word action8A_If_User_Byte_num2_LessThan_Random_Value_RVL_2
.word action8B_Set_Guard_Hearing_Distance_3
.word action8C_Set_Guard_Visible_Distance_2
.word action8D_Set_Guard_Grenade_Probability_2
.word action8E_Set_Guard_ID_2
.word action8F_Set_Guard_Health_3
.word action90_Set_Guard_Armor_Amount_3
.word action91_Set_Character_Reaction_Speed_2
.word action92_Set_Character_Injury_Recovery_Speed_2
.word action93_Set_Character_Accuracy_2
.word action94_Mask_Guard_Type_With_Value_2
.word action95_Unmask_Guard_Type_With_Value_2
.word action96_If_Guard_Type_Value_Is_Set_RVL_3
.word action97_Mask_Guard_Type_Flags_With_Value_3
.word action98_Unmask_Guard_Type_Flags_With_Value_3
.word action99_If_Guard_Type_Flags_Set_RVL_4
.word action9A_Set_Objective_Bits_5
.word action9B_Unset_Objective_Value_5
.word action9C_Check_If_Objective_Value_Return_Loop_If_So_6
.word action9D_Set_Guard_Bit_Tags_5
.word action9E_Unset_Guard_Bit_Tags_5
.word action9F_Check_Guard_Bits_If_Same_RVL_6
.word actionA0_Set_Guard_ID_Bits_6
.word actionA1_Unset_Guard_ID_Bits_6
.word actionA2_Check_Guard_Bits_If_Same_RVL_7
.word actionA3_Set_State_Bits_16_Type_Object_6
.word actionA4_Unset_State_Bits_16_Type_Object_6
.word actionA5_Check_State_Bits_16_Type_Object_If_Same_RVL_7
.word actionA6_Set_16_Object_States_More_6
.word actionA7_Unset_16_Object_States_More_6
.word actionA8_Check_16_Object_States_More_If_Same_RVL_7
.word actionA9_Sets_To_Guard_ID_Fc_Current_Guard_2
.word actionAA_Sets_FC_Value_For_Guard_ID_To_Guard_ID_3
.word actionAB_Set_Current_Guards_2328_Value_To_Preset_3
.word actionAC_Set_Guard_ID_numS_2328_Value_To_Preset_4
.word actionAD_Debug_Comment_20
.word actionAE_Reset_Cycle_Counter_And_Enable_It_1
.word actionAF_Reset_Cycle_Counter_1
.word actionB0_Disable_Cycle_Counter_1
.word actionB1_Enable_Cycle_Counter_1
.word actionB2_Check_Cycle_Counter_Enable_Status_2
.word actionB3_If_Cycle_Counter_LTV_RVL_5
.word actionB4_If_Cycle_Counter_GTV_RVL_5
.word actionB5_Show_Timer_1
.word actionB6_Hide_Timer_Silent_Countdown_1
.word actionB7_Set_Timer_X_Seconds__Doesnt_Show_Timer_Yet_3
.word actionB8_Stop_Timer_1
.word actionB9_Start_Timer_1
.word actionBA_Check_Timer_Enabled_Status_RVL_If_Enabled_2
.word actionBB_Detect_If_Timer_Below_Certain_Point_RVL_If_So_4
.word actionBC_Detect_If_Timer_Above_Certain_Point_RVL_If_So_4
.word actionBD_Spawn_Guard_C
.word actionBE_Respawn_Guard_with_ID_B
.word actionBF_Spawn_Weapon_9
.word actionC0_Spawn_Hat_8
.word actionC1_GuardIDDoesAV_If_Gunfire_RVL_WhenComplete_5
.word actionC2_Display_Text_Preset_Bottom_Screen_3
.word actionC3_Display_Text_Preset_Top_Screen_3
.word actionC4_Play_Sound_Effect_num_In_Slot_num_0_7_4
.word actionC5_EmanateSoundSlotnumFrom16ObjectWithAudibleRV_5
.word actionC6_EmanateSoundSlotnumFromPresetWithAudibleRV_6
.word actionC7_Sound_In_Slot_num_Crecendos_To_Volume_Over_ms_6
.word actionC8_Sound_In_Slot_num_Fades_To_Volume_Over_ms_6
.word actionC9_Shut_Off_Sound_In_Slot_Number_2
.word actionCA_If_Value_GreaterThan_Volume_7FFF_Max_RVL_5
.word actionCB_Set_Object_Path_27_Type_Object_2
.word actionCC_Set_Speed_Moving_Vehicle_27_Type_Object_5
.word actionCD_Set_Speed_Aircraft_Rotor_5
.word actionCE_Detect_If_Currently_In_Intro_Camera_RVL_If_So_2
.word actionCF_Detect_If_Currently_In_Intro_Swirl_RVL_If_So_2
.word actionD0_Change_Animation_Type_Of_Type_16_Monitor_4
.word actionD1_If_Bond_In_Tank_RVL_2
.word actionD2_Exit_Level_1
.word actionD3_Return_From_Camera_Scene_1
.word actionD4_Camera_Looks_At_Bond_From_Preset_3
.word actionD5_Go_To_Camera_Position_6
.word actionD6_If_Less_Than_Elevation_RVL_4
.word actionD7_Disable_Text_Variable_2
.word actionD8_Enable_All_On_Screen_Displays_1
.word actionD9_GuardIDMovedToPresetReturnLoopIfSuccessful_5
.word actionDA_Fade_Out_From_Cut_Scene_1
.word actionDB_Fade_In_From_Black_Reset_DA_1
.word actionDC_RVL_When_Fade_Complete_2
.word actionDD_Remove_All_Guards_1
.word actionDE_Bring_Removed_Guards_Back_1
.word actionDF_Open_Type_16_Door_Used_Cut_Scenes_2
.word actionE0_Guard_ID_Draws_Weapon_num_3
.word actionE1_If_Fewer_than_This_Many_Players_Playing_RVL_3
.word actionE2_If_Ammo_Value_In_Type_Is_LTV_RVL_4
.word actionE3_Draw_Weapon_From_Inventory_In_Game_2
.word actionE4_Draw_Weapon_From_Inventory_Cut_Scene_2
.word actionE5_Set_Bonds_Speed_3
.word actionE6_If_16_Object_And_Preset_Are_In_Same_Room_RVL_5
.word actionE7_If_Guard_Moving_And_Shooting_RVL_2
.word actionE8_If_Guard_Is_Shooting_RVL_2
.word actionE9_Instantly_Switch_Sky_To_Sky_2_1
.word actionEA_Stop_Game_Time_1
.word actionEB_If_Key_Pressed_RVL_2
.word actionEC_Disable_Player_Pickups_1
.word actionED_Hide_First_Person_Display_1
.word actionEE_Cuba_Circular_Camera_Aim_D
.word actionEF_Trigger_Credits_1
.word actionF0_RVL_If_Credits_Completed_2
.word actionF1_If_All_Objectives_Complete_RVL_2
.word actionF2_Check_Current_Folder_Bond_RVL_3
.word actionF3_If_Player_Pickups_Disabled_RVL_2
.word actionF4_PlaysValuenum1ThemeSlot03ForValuenum2Seconds_4
.word actionF5_Turn_Off_Music_In_Slot_num_0_3_2
.word actionF6_Trigger_Explosions_Around_Bond_1
.word actionF7_If_Number_Of_Hostages_Scientists_Killed_RVL_3
.word actionF8_If_Guard_ID_00200000_Flag_Set_Unset_And_Return_3
.word actionF9_Set_Killed_In_Action_Automatic_Mission_Failure_1
.word actionFA_Guard_Fawns_On_Shoulder_1
.word actionFB_SwitchToSkyValuenumAndActivateGasContainersIfExist_
.word actionFC_Launch_Shuttle_2

glabel D_800528EC
.word 0x3dcccccd /*0.1*/
glabel D_800528F0
.word 0x3dcccccd /*0.1*/
glabel D_800528F4
.word 0x3dcccccd /*0.1*/
glabel D_800528F8
.word 0x3dcccccd /*0.1*/

glabel jpt_800528FC
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word .L7F038C24
.word .L7F038C24
.word .L7F038C24
.word .L7F038C24
.word .L7F038C24
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C

glabel D_80052974
.word 0x3c888888 /*0.016666666*/
glabel D_80052978
.word 0x3e955555 /*0.29166666*/
.word 0

.text
glabel parse_handle_actionblocks
  addiu $sp, $sp, -0x7b8
  sw    $s7, 0x6c($sp)
  sw    $s6, 0x68($sp) 				 #free s2 for CurrentActionByte ?
  li    $at, 3 						 #ai_sleep
  sw    $ra, 0x74($sp)
  sw    $fp, 0x70($sp)
  sw    $s5, 0x64($sp)
  sw    $s4, 0x60($sp)
  sw    $s3, 0x5c($sp)
  sw    $s2, 0x58($sp) 				 #free s2 for CurrentActionByteSize ?
  sw    $s1, 0x54($sp)
  sw    $s0, 0x50($sp)
  sdc1  $f26, 0x48($sp)
  sdc1  $f24, 0x40($sp)
  sdc1  $f22, 0x38($sp)
  sdc1  $f20, 0x30($sp)
  move  $s7, $zero
  move  $a2, $zero
  move  $v1, $zero
  bne   $a1, $at, .L7F0354E0
   move  $s6, $zero
  b     .L7F035514
   move  $s7, $a0
.L7F0354E0:
  li    $at, 1
  bne   $a1, $at, .L7F035514
   nop   
  lbu   $v0, 3($a0)
  li    $at, 39
  bnel  $v0, $at, .L7F035508
   li    $at, 40
  b     .L7F035514
   move  $a2, $a0
  li    $at, 40
.L7F035508:
  bne   $v0, $at, .L7F035514
   nop   
  move  $v1, $a0
.L7F035514:
  beqz  $s7, .L7F03552C
   lui   $at, %hi(D_800524F4)
  lhu   $s2, 0x108($s7) 				 # Load Size of command
  lw    $s6, 0x104($s7) 				 # load command
  b     .L7F035558
   sw    $s2, 0x7a4($sp) 				 # save command size
.L7F03552C:
  beqz  $a2, .L7F035544
   nop   
  lhu   $s2, 0x84($a2)
  lw    $s6, 0x80($a2)
  b     .L7F035558
   sw    $s2, 0x7a4($sp)
.L7F035544:
  beqz  $v1, .L7F035558
   nop   
  lhu   $s2, 0x84($v1)
  lw    $s6, 0x80($v1)
  sw    $s2, 0x7a4($sp)
.L7F035558:
  beqz  $s6, Action04_End_1
   lw    $s2, 0x7a4($sp)
  lwc1  $f26, %lo(D_800524F4)($at)
  li    $at, 0x41200000				 # 10.000000
  mtc1  $at, $f24
  li    $at, 0x42700000 				# 60.000000
  lui   $fp, %hi(ptr_guard_data) 
  mtc1  $at, $f22
  mtc1  $zero, $f20
  addiu $fp, %lo(ptr_guard_data) 		# addiu $fp, $fp, -0x339c
  addu  $s1, $s6, $s2
  sw    $v1, 0x7ac($sp)
  sw    $a2, 0x7b0($sp)
GetByteS1_ParseCommandByte_SwitchCase:								/*GetCommandByte(cmd)*/
  lbu   $t6, ($s1) #t6 = byte(s1)
ParseCommandByte_SwitchCase:
  move  $a0, $s6
  sltiu $at, $t6, 0xfd				# if Cmd !< AI_CMDS_TOTAL  then 
  beqz  $at, GetCmdLength				#    Cmd<<2  goto GetCmdLength
   sll   $t6, $t6, 2
  lui   $at, %hi(jpt_800524F8)
  addu  $at, $at, $t6					# else //get cmd
  lw    $t6, %lo(jpt_800524F8)($at)	#    switch t6(look up table for switch 0x800524f8)
  jr    $t6							# return cmd
   nop   
Action00_GoToLabel: 					                            #case 0
  move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action #(command, commandsize, nextcommand[4])
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase	# GetCommandByte(currcmd + currcmdLength); 
   addu  $s1, $s6, $v0
Action01_GoToLabelFromTop: 			                                #case 1
  move  $a0, $s6
  move  $a1, $zero
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase	   #break
   addu  $s1, $s6, $v0
Action02_Label:                                                     #case 2
  addiu $s2, $s2, 2				    # s2++  PC ?    # CurrentActionByte += 2
  b     GetByteS1_ParseCommandByte_SwitchCase         # s1 +=2; goto 58c
   addiu $s1, $s1, 2
action03_Leave_The_Routine_When_Return_Continue_From_Spot_1:
  beqz  $s7, .L7F03560C				# s2++  PC?
   addiu $s2, $s2, 1					# if s7 = 0 goto 0c      If actionblock not initilised else ?
  sw    $s6, 0x104($s7)				# s7.104 = s6
  b     Action04_End_1				# s7.108 = unsigned short(s2)
   sh    $s2, 0x108($s7)				# goto end1 (load return addr)
.L7F03560C:
  lw    $t7, 0x7b0($sp)
  lw    $t8, 0x7ac($sp)
  beqz  $t7, .L7F035628				# if t7 = 0 goto 28
   nop   
  sw    $s6, 0x80($t7)				#else t7.80 = s6
  b     Action04_End_1				# t7.84 = unsigned short(s2)
   sh    $s2, 0x84($t7)				# end1 (load return addr)
.L7F035628:
  beql  $t8, $zero, Action04_End_2    # load return addr (same as end1 (sp.74))
   lw    $ra, 0x74($sp)				# if t8 = 0 goto end2 (skip return addr)
  sw    $s6, 0x80($t8)				# else t8.80 = s6
  b     Action04_End_1				# t8.84 = unsigned short(s2)
   sh    $s2, 0x84($t8)				# end1(load return addr)
action05_Jump_To_Function_4:
  lbu   $t9, 2($s1)
  lbu   $t2, 3($s1)
  lbu   $a1, 1($s1)
  sll   $t1, $t9, 8
  or    $v1, $t1, $t2
  andi  $t3, $v1, 0xffff
  li    $at, 253
  bne   $a1, $at, .L7F035678
   move  $v1, $t3
  move  $a0, $t3
  jal   LoadNext_PrevActionBlock
   move  $s2, $zero
  move  $s6, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   move  $s1, $v0
.L7F035678:
  move  $a0, $s7
  jal   get_handle_for_guard_id
   sh    $v1, 0x792($sp)
  lhu   $v1, 0x792($sp)
  beqz  $v0, .L7F0356A4
   move  $s0, $v0
  jal   LoadNext_PrevActionBlock
   move  $a0, $v1
  sw    $v0, 0x104($s0)
  sh    $zero, 0x108($s0)
  sb    $zero, 8($s0)
.L7F0356A4:
  addiu $s2, $s2, 4
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
action06_Set_Return_Subroutine_for_0007_Command_3:
  lbu   $t4, 1($s1)
  lbu   $t6, 2($s1)
  lw    $t8, 0x7b0($sp)
  sll   $t5, $t4, 8
  or    $v0, $t5, $t6
  andi  $t7, $v0, 0xffff
  beqz  $s7, .L7F0356E0
   move  $v0, $t7
  sh    $t7, 0x10a($s7)
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
.L7F0356E0:
  beqz  $t8, .L7F0356F8
   lw    $t9, 0x7ac($sp)
  sh    $v0, 0x86($t8)
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
.L7F0356F8:
  beqz  $t9, .L7F035704
   addiu $s2, $s2, 3
  sh    $v0, 0x86($t9)
.L7F035704:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action07_Jump_to_Return_Subroutine_1:
  beqz  $s7, .L7F035728
   move  $s2, $zero
  jal   LoadNext_PrevActionBlock
   lh    $a0, 0x10a($s7)
  move  $s6, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   move  $s1, $v0
.L7F035728:
  lw    $t1, 0x7b0($sp)
  lw    $t2, 0x7ac($sp)
  beqz  $t1, .L7F03574C
   nop   
  jal   LoadNext_PrevActionBlock
   lh    $a0, 0x86($t1)
  move  $s6, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   move  $s1, $v0
.L7F03574C:
  beqz  $t2, .L7F035760
   nop   
  jal   LoadNext_PrevActionBlock
   lh    $a0, 0x86($t2)
  move  $s6, $v0
.L7F035760:
  b     GetByteS1_ParseCommandByte_SwitchCase
   move  $s1, $s6
action08_Reset_Animation_1:
  jal   sub_GAME_7F0335D4
   move  $a0, $s7
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
action09_Guard_Kneels_1:
  jal   check_if_able_to_then_kneel
   move  $a0, $s7
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
action0A_Animation_9:
  lbu   $t3, 1($s1)
  lbu   $t5, 2($s1)
  li    $at, 65535
  sll   $t4, $t3, 8
  or    $t6, $t4, $t5
  sw    $t6, 0x77c($sp)
  lbu   $t7, 3($s1)
  lbu   $t1, 5($s1)
  lbu   $t9, 4($s1)
  lbu   $t3, 6($s1)
  sll   $t8, $t7, 8
  sll   $t2, $t1, 8
  or    $s0, $t8, $t9
  or    $t4, $t2, $t3
  bne   $s0, $at, .L7F0357D4
   sw    $t4, 0x774($sp)
  move  $s0, $zero
.L7F0357D4:
  lw    $s3, 0x774($sp)
  li    $at, 65535
  move  $a0, $s7
  bne   $s3, $at, .L7F0357EC
   lw    $t7, 0x7ac($sp)
  li    $s3, -1
.L7F0357EC:
  beqz  $s7, .L7F035820
   nop   
  lbu   $t5, 7($s1)
  lw    $a1, 0x77c($sp)
  move  $a2, $s0
  sw    $t5, 0x10($sp)
  lbu   $t6, 8($s1)
  move  $a3, $s3
  jal   check_if_able_to_then_perform_animation
   sw    $t6, 0x14($sp)
  addiu $s2, $s2, 9
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 9
.L7F035820:
  beqz  $t7, .L7F035890
   li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f6
  lw    $a0, 0x14($t7)
  mtc1  $s0, $f4
  swc1  $f6, 0x10($sp)
  lbu   $t1, 8($s1)
  cvt.s.w $f4, $f4
  lw    $t8, 0x77c($sp)
  mtc1  $t1, $f8
  lui   $a1, %hi(animation_table_ptrs2)
  sll   $t9, $t8, 2
  cvt.s.w $f10, $f8
  addu  $a1, $a1, $t9
  mfc1  $a3, $f4
  lw    $a1, %lo(animation_table_ptrs2)($a1)
  move  $a2, $zero
  jal   sub_GAME_7F06FCA8
   swc1  $f10, 0x14($sp)
  bltzl $s3, .L7F035894
   addiu $s2, $s2, 9
  mtc1  $s3, $f16
  lw    $t2, 0x7ac($sp)
  cvt.s.w $f16, $f16
  lw    $a0, 0x14($t2)
  mfc1  $a1, $f16
  jal   sub_GAME_7F06FDE8
   nop   
.L7F035890:
  addiu $s2, $s2, 9
.L7F035894:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 9
action0B_If_Guard_WastingTime_SwatFlies_RVL_2:
  lb    $t3, 7($s7)
  li    $at, 3
  move  $a0, $s6
  bne   $t3, $at, .L7F0358C4
   move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F0358C4:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action0C_Guard_Gestures_1:
  jal   check_if_able_to_then_shuffle_feet
   move  $a0, $s7
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
action0D_Guard_Looks_Around_When_Shot_At_1:
  jal   check_if_able_to_then_look_flustered
   move  $a0, $s7
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
action2F_When_Guard_Stops_Moving_RVL_2:
  jal   check_if_actor_stationary
   move  $a0, $s7
  beqz  $v0, .L7F035920
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F035920:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action30_Detect_If_Guard_Killed_RVL_If_So_3:
  move  $a0, $s7
  jal   get_handle_for_guard_id
   lbu   $a1, 1($s1)
  beqz  $v0, .L7F03594C
   move  $a0, $v0
  jal   true_if_actor_dying_fading
   nop   
  beqz  $v0, .L7F035968
.L7F03594C:
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F035968:
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action31_If_GuardID_Finish_DeathAnimation_RVL_3:
  move  $a0, $s7
  jal   get_handle_for_guard_id
   lbu   $a1, 1($s1)
  beqz  $v0, .L7F035990
   move  $a0, $s6
  lw    $t4, 0x1c($v0)
  bnez  $t4, .L7F0359A8
.L7F035990:
   move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F0359A8:
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action32_If_Bond_In_Sight_RVL_2:
  jal   sub_GAME_7F029D70
   move  $a0, $s7
  beqz  $v0, .L7F0359DC
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F0359DC:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action0E_Guard_Steps_Sideways_RVL_2:
  jal   actor_steps_sideways
   move  $a0, $s7
  beqz  $v0, .L7F035A10
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F035A10:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action0F_Guard_Hops_Sideways_RVL_2:
  jal   actor_hops_sideways
   move  $a0, $s7
  beqz  $v0, .L7F035A44
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F035A44:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action10_Guard_Runs_Sideways_RVL_2:
  jal   actor_runs_sideways
   move  $a0, $s7
  beqz  $v0, .L7F035A78
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F035A78:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action11_Guard_Walks_Firing_RVL_2:
  jal   actor_walks_and_fires
   move  $a0, $s7
  beqz  $v0, .L7F035AAC
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F035AAC:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action12_Guard_Runs_Firing_RVL_2:
  jal   actor_runs_and_fires
   move  $a0, $s7
  beqz  $v0, .L7F035AE0
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F035AE0:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action13_Guard_Rolls_On_Ground_Then_Fires_Crouched_RVL_2:
  jal   actor_rolls_fires_crouched
   move  $a0, $s7
  beqz  $v0, .L7F035B14
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F035B14:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action14_Guard_Aims_Shoots_at_Bond_Guard_Pad_RVL_6:
  lbu   $t5, 3($s1)
  lbu   $t8, 1($s1)
  lbu   $t7, 4($s1)
  lbu   $t1, 2($s1)
  sll   $t6, $t5, 8
  sll   $t9, $t8, 8
  move  $a0, $s7
  or    $a2, $t6, $t7
  jal   actor_aim_at_actor
   or    $a1, $t9, $t1
  beqz  $v0, .L7F035B68
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 5($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F035B68:
  addiu $s2, $s2, 6
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 6
action15_Guard_Kneels_Aims_Shoots_at_Bond_Guard_Pad_RVL_6:
  lbu   $t2, 3($s1)
  lbu   $t5, 1($s1)
  lbu   $t4, 4($s1)
  lbu   $t7, 2($s1)
  sll   $t3, $t2, 8
  sll   $t6, $t5, 8
  move  $a0, $s7
  or    $a2, $t3, $t4
  jal   actor_kneel_aim_at_actor
   or    $a1, $t6, $t7
  beqz  $v0, .L7F035BBC
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 5($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F035BBC:
  addiu $s2, $s2, 6
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 6
actionE7_If_Guard_Moving_And_Shooting_RVL_2:
  lb    $t8, 7($s7)
  li    $at, 8
  bnel  $t8, $at, .L7F035C14
   addiu $s2, $s2, 2
  lw    $t9, 0x58($s7)
  bnezl $t9, .L7F035C14
   addiu $s2, $s2, 2
  lw    $t1, 0x4c($s7)
  move  $a0, $s6
  move  $a1, $s2
  andi  $t2, $t1, 0x40
  beql  $t2, $zero, .L7F035C14
   addiu $s2, $s2, 2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 2
.L7F035C14:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
actionE8_If_Guard_Is_Shooting_RVL_2:
  lb    $t3, 7($s7)
  li    $at, 8
  move  $a0, $s6
  bne   $t3, $at, .L7F035C44
   move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F035C44:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action16_Guard_Shoots_Guards_Without_Animation_Change_RVL_6:
  lbu   $t4, 3($s1)
  lbu   $t7, 1($s1)
  lbu   $t6, 4($s1)
  lbu   $t9, 2($s1)
  sll   $t5, $t4, 8
  sll   $t8, $t7, 8
  move  $a0, $s7
  or    $a2, $t5, $t6
  jal   sub_GAME_7F02AAF4
   or    $a1, $t8, $t9
  beqz  $v0, .L7F035C98
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 5($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F035C98:
  addiu $s2, $s2, 6
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 6
action17_Guard_Constantly_Angles_To_Face_RVL_6:
  lbu   $t1, 3($s1)
  lbu   $t4, 1($s1)
  lbu   $t3, 4($s1)
  lbu   $t6, 2($s1)
  sll   $t2, $t1, 8
  sll   $t5, $t4, 8
  move  $a0, $s7
  or    $a2, $t2, $t3
  jal   check_set_actor_standing_still
   or    $a1, $t5, $t6
  beqz  $v0, .L7F035CEC
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 5($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F035CEC:
  addiu $s2, $s2, 6
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 6
action18_Shoot_Guard_ID_In_Style_With_Weapon_Type_num_4:
  move  $a0, $s7
  jal   get_handle_for_guard_id
   lbu   $a1, 1($s1)
  lui   $t8, %hi(D_80030A70) 
  addiu $t8, %lo(D_80030A70) # addiu $t8, $t8, 0xa70
  lw    $at, ($t8)
  addiu $t7, $sp, 0x6f4
  lw    $t1, 4($t8)
  sw    $at, ($t7)
  lw    $at, 8($t8)
  move  $a0, $v0
  sw    $t1, 4($t7)
  beqz  $v0, .L7F035D50
   sw    $at, 8($t7)
  lw    $t2, 0x18($v0)
  beql  $t2, $zero, .L7F035D54
   addiu $s2, $s2, 4
  lb    $a1, 2($s1)
  lbu   $a3, 3($s1)
  sw    $zero, 0x10($sp)
  jal   handles_shot_actors
   addiu $a2, $sp, 0x6f4
.L7F035D50:
  addiu $s2, $s2, 4
.L7F035D54:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
action19_Guard_ID1_Shoots_Guard_ID2_In_Style_4:
  move  $a0, $s7
  jal   get_handle_for_guard_id
   lbu   $a1, 1($s1)
  move  $s0, $v0
  move  $a0, $s7
  jal   get_handle_for_guard_id
   lbu   $a1, 2($s1)
  beqz  $s0, .L7F035E6C
   sw    $v0, 0x6e8($sp)
  beqz  $v0, .L7F035E6C
   move  $s3, $v0
  lw    $t3, 0x18($s0)
  beql  $t3, $zero, .L7F035E70
   addiu $s2, $s2, 4
  lw    $t4, 0x18($v0)
  move  $a0, $s0
  beql  $t4, $zero, .L7F035E70
   addiu $s2, $s2, 4
  jal   is_weapon_in_guarddata_hand
   move  $a1, $zero
  lui   $t6, %hi(D_80030A7C) 
  addiu $t6, %lo(D_80030A7C) # addiu $t6, $t6, 0xa7c
  lw    $at, ($t6)
  addiu $t5, $sp, 0x6d4
  lw    $t7, 4($t6)
  sw    $at, ($t5)
  lw    $at, 8($t6)
  move  $v1, $v0
  sw    $t7, 4($t5)
  bnez  $v0, .L7F035DE8
   sw    $at, 8($t5)
  move  $a0, $s0
  jal   is_weapon_in_guarddata_hand
   li    $a1, 1
  move  $v1, $v0
.L7F035DE8:
  beql  $v0, $zero, .L7F035E70
   addiu $s2, $s2, 4
  lw    $t8, 0x18($s3)
  lw    $t1, 0x18($s0)
  addiu $a0, $sp, 0x6d4
  lwc1  $f18, 8($t8)
  lwc1  $f4, 8($t1)
  addiu $a1, $sp, 0x6d8
  addiu $a2, $sp, 0x6dc
  sub.s $f6, $f18, $f4
  swc1  $f6, 0x6d4($sp)
  lw    $t3, 0x18($s0)
  lw    $t2, 0x18($s3)
  lwc1  $f10, 0xc($t3)
  lwc1  $f8, 0xc($t2)
  sub.s $f16, $f8, $f10
  swc1  $f16, 0x6d8($sp)
  lw    $t9, 0x18($s0)
  lw    $t4, 0x18($s3)
  lwc1  $f4, 0x10($t9)
  lwc1  $f18, 0x10($t4)
  sw    $v1, 0x6e4($sp)
  sub.s $f6, $f18, $f4
  jal   guNormalize
   swc1  $f6, 0x6dc($sp)
  lw    $v1, 0x6e4($sp)
  lb    $a1, 3($s1)
  move  $a0, $s3
  lw    $v0, 4($v1)
  addiu $a2, $sp, 0x6d4
  lb    $a3, 0x80($v0)
  jal   handles_shot_actors
   sw    $zero, 0x10($sp)
.L7F035E6C:
  addiu $s2, $s2, 4
.L7F035E70:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
action1A_Guard_Throws_Grenade_RVL_2:
  jal   actor_draws_throws_grenade_at_player_if_possible
   move  $a0, $s7
  beqz  $v0, .L7F035EA0
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F035EA0:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action1B_Drop_Weapon_Inventory_num_RVL_5:
  lbu   $t5, 1($s1)
  lbu   $t7, 2($s1)
  move  $a0, $s7
  sll   $t6, $t5, 8
  or    $v0, $t6, $t7
  andi  $a1, $v0, 0xffff
  jal   actor_drops_itemtype_setting_timer
   lbu   $a2, 3($s1)
  beqz  $v0, .L7F035EEC
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 4($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F035EEC:
  addiu $s2, $s2, 5
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 5
action21_Guard_Surrenders_1:
  jal   check_if_able_to_then_surrender
   move  $a0, $s7
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
action22_Guard_Set_To_Move_Fades_And_Disappear_1:
  jal   sub_GAME_7F0333A0
   move  $a0, $s7
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
action23_Eliminate_Guard_ID_2:
  move  $a0, $s7
  jal   get_handle_for_guard_id
   lbu   $a1, 1($s1)
  beqz  $v0, .L7F035F4C
   addiu $s2, $s2, 2
  lw    $t1, 0x18($v0)
  beqz  $t1, .L7F035F4C
   nop   
  lhu   $t2, 0x12($v0)
  ori   $t3, $t2, 0x20
  sh    $t3, 0x12($v0)
.L7F035F4C:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action24_Activate_Object_At_Preset_RVL_If_Successful_4:
  lbu   $t4, 1($s1)
  lbu   $t5, 2($s1)
  move  $a0, $s7
  sll   $t9, $t4, 8
  or    $v0, $t9, $t5
  jal   sub_GAME_7F034514
   andi  $a1, $v0, 0xffff
  beqz  $v0, .L7F035F90
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 3($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F035F90:
  addiu $s2, $s2, 4
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
action25_Sound_Alarm_1:
  jal   start_alarm
   nop   
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
action26_Turn_Off_Alarm_1:
  jal   stop_alarm
   nop   
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
action27_Return_False_Invalid_Type_2:
  jal   removed_animation_routine_27
   move  $a0, $s7
  beqz  $v0, .L7F035FEC
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F035FEC:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action28_Jog_To_Bond_Return_Loop_When_Reached_Bond_2:
  move  $a0, $s7
  jal   actor_move_to_curplayer_at_speed
   li    $a1, 1
  beqz  $v0, .L7F036024
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036024:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action29_Walk_To_Bond_Return_Loop_When_Reached_Bond_2:
  move  $a0, $s7
  jal   actor_move_to_curplayer_at_speed
   move  $a1, $zero
  beqz  $v0, .L7F03605C
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F03605C:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action2A_Run_To_Bond_Return_Loop_When_Reached_Bond_2:
  move  $a0, $s7
  jal   actor_move_to_curplayer_at_speed
   li    $a1, 2
  beqz  $v0, .L7F036094
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036094:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action2B_Return_False_Invalid_Type_2:
  jal   removed_animation_routine_2B
   move  $a0, $s7
  beqz  $v0, .L7F0360C8
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F0360C8:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action2C_Jog_To_Character_Position_RVL_On_Arrival_3:
  move  $a0, $s7
  lbu   $a1, 1($s1)
  jal   actor_move_to_actorID_at_speed
   li    $a2, 1
  beqz  $v0, .L7F036104
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036104:
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action2D_Walk_To_Character_Position_RVL_On_Arrival_3:
  move  $a0, $s7
  lbu   $a1, 1($s1)
  jal   actor_move_to_actorID_at_speed
   move  $a2, $zero
  beqz  $v0, .L7F036140
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036140:
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action2E_Run_To_Character_Position_RVL_On_Arrival_3:
  move  $a0, $s7
  lbu   $a1, 1($s1)
  jal   actor_move_to_actorID_at_speed
   li    $a2, 2
  beqz  $v0, .L7F03617C
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F03617C:
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action33_Seed_Random_Byte_1:
  jal   get_random_value
   nop   
  sb    $v0, 0x10f($s7)
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
action34_If_Seeded_Byte_LTV_Go_Into_RVL_3:
  lbu   $t8, 0x10f($s7)
  lbu   $t1, 1($s1)
  move  $a0, $s6
  move  $a1, $s2
  slt   $at, $t8, $t1
  beql  $at, $zero, .L7F0361D4
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F0361D4:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action35_If_Seeded_Byte_GTV_Go_Into_RVL_3:
  lbu   $t2, 1($s1)
  lbu   $t3, 0x10f($s7)
  move  $a0, $s6
  move  $a1, $s2
  slt   $at, $t2, $t3
  beql  $at, $zero, .L7F036210
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F036210:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action1C_Guard_Jogs_To_Preset_3:
  lbu   $t4, 1($s1)
  lbu   $t5, 2($s1)
  move  $a0, $s7
  sll   $t9, $t4, 8
  or    $v0, $t9, $t5
  andi  $a1, $v0, 0xffff
  jal   actor_moves_to_preset_at_speed
   li    $a2, 1
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action1D_Guard_Jogs_To_Predefined_Preset_2328_1:
  move  $a0, $s7
  lh    $a1, 0x114($s7)
  jal   actor_moves_to_preset_at_speed
   li    $a2, 1
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
action1E_Guard_Walks_To_Preset_3:
  lbu   $t7, 1($s1)
  lbu   $t1, 2($s1)
  move  $a0, $s7
  sll   $t8, $t7, 8
  or    $v0, $t8, $t1
  andi  $a1, $v0, 0xffff
  jal   actor_moves_to_preset_at_speed
   move  $a2, $zero
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action1F_Guard_Runs__To_Preset_3:
  lbu   $t3, 1($s1)
  lbu   $t9, 2($s1)
  move  $a0, $s7
  sll   $t4, $t3, 8
  or    $v0, $t4, $t9
  andi  $a1, $v0, 0xffff
  jal   actor_moves_to_preset_at_speed
   li    $a2, 2
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action20_Activate_Path_2:
  jal   get_ptr_path_for_pathnum
   lbu   $a0, 1($s1)
  move  $a0, $s7
  jal   if_actor_able_set_on_path
   move  $a1, $v0
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action36_If_Alarm_Activated_RVL_Plus_Stack_2:
  jal   alarm_timer_related
   move  $a0, $s7
  beqz  $v0, .L7F036300
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036300:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action37_If_Alarm_Activated_RVL_2:
  jal   is_alarm_on
   nop   
  beqz  $v0, .L7F036334
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036334:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action38_If_Toxic_Gas_Released_RVL_2:
  jal   check_if_toxic_gas_activated
   nop   
  beqz  $v0, .L7F036368
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036368:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action39_If_Guard_Heard_Gunfire_RVL_2:
  jal   check_if_actor_02_flag_set
   move  $a0, $s7
  beqz  $v0, .L7F03639C
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F03639C:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action3A_If_Bond_Shoots_Another_Guard_RVL_2:
  jal   check_if_actor_FA_target_set
   move  $a0, $s7
  beqz  $v0, .L7F0363D0
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F0363D0:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action3B_If_Guard_Killed_In_Front_Of_Guard_RVL_2:
  jal   check_if_actor_FB_target_set
   move  $a0, $s7
  beqz  $v0, .L7F036404
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036404:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action3C_If_Guard_In_Firing_Range_RVL_2:
  jal   sub_GAME_7F0294BC
   move  $a0, $s7
  beqz  $v0, .L7F036438
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036438:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action3D___Unused___Unknown___2:
  jal   sub_GAME_7F033DC4
   move  $a0, $s7
  beqz  $v0, .L7F03646C
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F03646C:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action3E_If_Shot_Current_Guard_RVL_2:
  jal   sub_GAME_7F032B68
   move  $a0, $s7
  beqz  $v0, .L7F0364A0
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F0364A0:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action3F_If_Heard_Bond_RVL_2:
  jal   sub_GAME_7F032BA0
   move  $a0, $s7
  beqz  $v0, .L7F0364D4
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F0364D4:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action40_If_Another_Guard_In_Same_Room_As_Guard_ID_RVL_3:
  move  $a0, $s7
  jal   get_handle_for_guard_id
   lbu   $a1, 1($s1)
  beql  $v0, $zero, .L7F036538
   addiu $s2, $s2, 3
  lw    $t6, 0x18($v0)
  beql  $t6, $zero, .L7F036538
   addiu $s2, $s2, 3
  lw    $v0, 0x18($v0)
  move  $a0, $s7
  addiu $a1, $v0, 8
  jal   check_if_position_in_same_room
   lw    $a2, 0x14($v0)
  beqz  $v0, .L7F036534
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036534:
  addiu $s2, $s2, 3
.L7F036538:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action41_If_Guard_Has_Been_On_Screen_RVL_2:
  lw    $t7, 0x14($s7)
  move  $a0, $s6
  move  $a1, $s2
  andi  $t8, $t7, 8
  bnezl $t8, .L7F036570
   addiu $s2, $s2, 2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 2
.L7F036570:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action42_If_Current_Guard_On_Screen_In_Loaded_Room_RVL_2:
  lw    $t1, 0x18($s7)
  move  $a0, $s6
  move  $a1, $s2
  lbu   $t2, 1($t1)
  andi  $t3, $t2, 2
  beql  $t3, $zero, .L7F0365AC
   addiu $s2, $s2, 2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 2
.L7F0365AC:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action43_If_Guard_In_A_Room_Currently_Loaded_RVL_2:
  lw    $t4, 0x18($s7)
  jal   sub_GAME_7F0B2FD8
   lw    $a0, 0x14($t4)
  jal   sub_GAME_7F0B5E50
   move  $a0, $v0
  beqz  $v0, .L7F0365E8
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F0365E8:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action44_If_Room_Containing_Preset_Is_Loaded_RVL_4:
  lbu   $t9, 1($s1)
  lbu   $t6, 2($s1)
  move  $a0, $s7
  sll   $t5, $t9, 8
  or    $v0, $t5, $t6
  jal   check_if_room_for_preset_loaded
   andi  $a1, $v0, 0xffff
  beqz  $v0, .L7F036630
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 3($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036630:
  addiu $s2, $s2, 4
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
action45_Go_To_RVL_If_Bond_Has_Guard_At_Gunpoint_2:
  jal   sub_GAME_7F0333F8
   move  $a0, $s7
  beqz  $v0, .L7F036664
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036664:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action46_If_Fired_A_Shot_RVL_2:
  jal   check_if_actor_invisible
   move  $a0, $s7
  beqz  $v0, .L7F036698
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036698:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action47_If_Distance_Between_Bond_And_Guard_LTV_RVL_3:
  jal   sub_GAME_7F032C4C
   move  $a0, $s7
  lbu   $t8, 1($s1)
  li    $at, 0x4F800000 # 4294967296.000000
  move  $a0, $s6
  mtc1  $t8, $f8
  move  $a1, $s2
  bgez  $t8, .L7F0366D4
   cvt.s.w $f10, $f8
  mtc1  $at, $f16
  nop   
  add.s $f10, $f10, $f16
.L7F0366D4:
  mul.s $f18, $f10, $f26
  li    $at, 0x3B800000 # 0.003906
  mtc1  $at, $f4
  nop   
  mul.s $f6, $f18, $f4
  c.lt.s $f0, $f6
  nop   
  bc1fl .L7F036710
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F036710:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action48_If_Distance_Between_Bond_And_Guard_GTV_RVL_3:
  jal   sub_GAME_7F032C4C
   move  $a0, $s7
  lbu   $t1, 1($s1)
  li    $at, 0x4F800000 # 4294967296.000000
  move  $a0, $s6
  mtc1  $t1, $f8
  move  $a1, $s2
  bgez  $t1, .L7F036748
   cvt.s.w $f16, $f8
  mtc1  $at, $f10
  nop   
  add.s $f16, $f16, $f10
.L7F036748:
  mul.s $f18, $f16, $f26
  li    $at, 0x3B800000 # 0.003906
  mtc1  $at, $f4
  nop   
  mul.s $f6, $f18, $f4
  c.lt.s $f6, $f0
  nop   
  bc1fl .L7F036784
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F036784:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action49_Test_if_Actor_and_Player_CCWAngle_LTV_RVL_Unused_3:
  jal   get_angle_between_actor_cur_player
   move  $a0, $s7
  lbu   $t2, 1($s1)
  li    $at, 0x4F800000 # 4294967296.000000
  move  $a0, $s6
  mtc1  $t2, $f8
  move  $a1, $s2
  bgez  $t2, .L7F0367BC
   cvt.s.w $f10, $f8
  mtc1  $at, $f16
  nop   
  add.s $f10, $f10, $f16
.L7F0367BC:
  mul.s $f18, $f10, $f26
  li    $at, 0x3B800000 # 0.003906
  mtc1  $at, $f4
  nop   
  mul.s $f6, $f18, $f4
  c.lt.s $f0, $f6
  nop   
  bc1fl .L7F0367F8
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F0367F8:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action4A_Test_if_Actor_and_Player_CCWAngle_GTV_RVL_Unused_3:
  jal   get_angle_between_actor_cur_player
   move  $a0, $s7
  lbu   $t3, 1($s1)
  li    $at, 0x4F800000 # 4294967296.000000
  move  $a0, $s6
  mtc1  $t3, $f8
  move  $a1, $s2
  bgez  $t3, .L7F036830
   cvt.s.w $f16, $f8
  mtc1  $at, $f10
  nop   
  add.s $f16, $f16, $f10
.L7F036830:
  mul.s $f18, $f16, $f26
  li    $at, 0x3B800000 # 0.003906
  mtc1  $at, $f4
  nop   
  mul.s $f6, $f18, $f4
  c.lt.s $f6, $f0
  nop   
  bc1fl .L7F03686C
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F03686C:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action4B_RVL_If_In_Proximity_Of_Bond_4:
  lbu   $t4, 1($s1)
  lbu   $t5, 2($s1)
  move  $a0, $s7
  sll   $t9, $t4, 8
  or    $t6, $t9, $t5
  mtc1  $t6, $f8
  nop   
  cvt.s.w $f10, $f8
  mul.s $f16, $f10, $f24
  jal   sub_GAME_7F032DE4
   swc1  $f16, 0x5fc($sp)
  lwc1  $f18, 0x5fc($sp)
  move  $a0, $s6
  move  $a1, $s2
  c.lt.s $f0, $f18
  nop   
  bc1fl .L7F0368D4
   addiu $s2, $s2, 4
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 3($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 4
.L7F0368D4:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
action4C_RVL_If_Not_In_Proximity_Of_Bond_4:
  lbu   $t7, 1($s1)
  lbu   $t1, 2($s1)
  move  $a0, $s7
  sll   $t8, $t7, 8
  or    $t2, $t8, $t1
  mtc1  $t2, $f4
  nop   
  cvt.s.w $f6, $f4
  mul.s $f8, $f6, $f24
  jal   sub_GAME_7F032DE4
   swc1  $f8, 0x5f4($sp)
  lwc1  $f10, 0x5f4($sp)
  move  $a0, $s6
  move  $a1, $s2
  c.lt.s $f10, $f0
  nop   
  bc1fl .L7F03693C
   addiu $s2, $s2, 4
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 3($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 4
.L7F03693C:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
action4D_When_Guard_In_Proximity_Of_Preset_RVL_7:
  move  $a0, $s7
  jal   get_handle_for_guard_id
   lbu   $a1, 1($s1)
  lbu   $t6, 2($s1)
  lbu   $t8, 3($s1)
  lbu   $t3, 4($s1)
  sll   $t7, $t6, 8
  or    $t1, $t7, $t8
  mtc1  $t1, $f16
  lbu   $t9, 5($s1)
  sll   $t4, $t3, 8
  cvt.s.w $f18, $f16
  or    $v1, $t4, $t9
  andi  $t5, $v1, 0xffff
  move  $a0, $v0
  move  $a1, $t5
  mul.s $f2, $f18, $f24
  beql  $v0, $zero, .L7F0369CC
   addiu $s2, $s2, 7
  jal   sub_GAME_7F032E48
   swc1  $f2, 0x5e4($sp)
  lwc1  $f2, 0x5e4($sp)
  move  $a0, $s6
  move  $a1, $s2
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F0369CC
   addiu $s2, $s2, 7
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 6($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 7
.L7F0369CC:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 7
action4E_When_Guard_Not_In_Proximity_Of_Preset_RVL_7:
  move  $a0, $s7
  jal   get_handle_for_guard_id
   lbu   $a1, 1($s1)
  lbu   $t5, 2($s1)
  lbu   $t7, 3($s1)
  lbu   $t2, 4($s1)
  sll   $t6, $t5, 8
  or    $t8, $t6, $t7
  mtc1  $t8, $f4
  lbu   $t4, 5($s1)
  sll   $t3, $t2, 8
  cvt.s.w $f6, $f4
  or    $v1, $t3, $t4
  andi  $t9, $v1, 0xffff
  move  $a0, $v0
  move  $a1, $t9
  mul.s $f2, $f6, $f24
  beql  $v0, $zero, .L7F036A5C
   addiu $s2, $s2, 7
  jal   sub_GAME_7F032E48
   swc1  $f2, 0x5d4($sp)
  lwc1  $f2, 0x5d4($sp)
  move  $a0, $s6
  move  $a1, $s2
  c.lt.s $f2, $f0
  nop   
  bc1fl .L7F036A5C
   addiu $s2, $s2, 7
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 6($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 7
.L7F036A5C:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 7
action4F_If_Current_Guard_Is_In_Units_Of_Guard_ID_RVL_5:
  lbu   $t1, 1($s1)
  lbu   $t3, 2($s1)
  move  $a0, $s7
  sll   $t2, $t1, 8
  or    $t4, $t2, $t3
  mtc1  $t4, $f8
  nop   
  cvt.s.w $f10, $f8
  mul.s $f16, $f10, $f24
  swc1  $f16, 0x5cc($sp)
  jal   get_distance_between_actor_and_actorID
   lbu   $a1, 3($s1)
  lwc1  $f18, 0x5cc($sp)
  move  $a0, $s6
  move  $a1, $s2
  c.lt.s $f0, $f18
  nop   
  bc1fl .L7F036AC8
   addiu $s2, $s2, 5
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 4($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 5
.L7F036AC8:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 5
action50_If_Current_Guard_Is_Not_In_Units_Of_Guard_ID_RVL_5:
  lbu   $t9, 1($s1)
  lbu   $t6, 2($s1)
  move  $a0, $s7
  sll   $t5, $t9, 8
  or    $t7, $t5, $t6
  mtc1  $t7, $f4
  nop   
  cvt.s.w $f6, $f4
  mul.s $f8, $f6, $f24
  swc1  $f8, 0x5c4($sp)
  jal   get_distance_between_actor_and_actorID
   lbu   $a1, 3($s1)
  lwc1  $f10, 0x5c4($sp)
  move  $a0, $s6
  move  $a1, $s2
  c.lt.s $f10, $f0
  nop   
  bc1fl .L7F036B34
   addiu $s2, $s2, 5
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 4($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 5
.L7F036B34:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 5
action51_SetClosestGuardUnitsGuardID_Then_RVL_IfSuccess_4:
  lbu   $t8, 1($s1)
  lbu   $t2, 2($s1)
  move  $a0, $s7
  sll   $t1, $t8, 8
  or    $t3, $t1, $t2
  mtc1  $t3, $f16
  nop   
  cvt.s.w $f18, $f16
  mul.s $f0, $f18, $f24
  mfc1  $a1, $f0
  jal   sub_GAME_7F033B38
   nop   
  beqz  $v0, .L7F036B8C
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 3($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036B8C:
  addiu $s2, $s2, 4
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
action52_GoIntoRVLIf_In_Units_Of_Preset_6:
  lbu   $t7, 1($s1)
  lbu   $t1, 2($s1)
  lbu   $t4, 3($s1)
  sll   $t8, $t7, 8
  or    $t2, $t8, $t1
  mtc1  $t2, $f4
  lbu   $t5, 4($s1)
  sll   $t9, $t4, 8
  cvt.s.w $f6, $f4
  or    $v0, $t9, $t5
  andi  $a1, $v0, 0xffff
  move  $a0, $s7
  mul.s $f8, $f6, $f24
  jal   get_distance_between_actor_and_preset
   swc1  $f8, 0x5b0($sp)
  lwc1  $f10, 0x5b0($sp)
  move  $a0, $s6
  move  $a1, $s2
  c.lt.s $f0, $f10
  nop   
  bc1fl .L7F036C08
   addiu $s2, $s2, 6
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 5($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 6
.L7F036C08:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 6
action53_GoIntoRVLIf_Not_In_Units_Of_Preset_6:
  lbu   $t6, 1($s1)
  lbu   $t8, 2($s1)
  lbu   $t3, 3($s1)
  sll   $t7, $t6, 8
  or    $t1, $t7, $t8
  mtc1  $t1, $f16
  lbu   $t9, 4($s1)
  sll   $t4, $t3, 8
  cvt.s.w $f18, $f16
  or    $v0, $t4, $t9
  andi  $a1, $v0, 0xffff
  move  $a0, $s7
  mul.s $f4, $f18, $f24
  jal   get_distance_between_actor_and_preset
   swc1  $f4, 0x5a4($sp)
  lwc1  $f6, 0x5a4($sp)
  move  $a0, $s6
  move  $a1, $s2
  c.lt.s $f6, $f0
  nop   
  bc1fl .L7F036C80
   addiu $s2, $s2, 6
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 5($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 6
.L7F036C80:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 6
action54_GoIntoRVLIf_Guard_Is_At_Preset_5:
  lbu   $t2, 2($s1)
  lbu   $t4, 3($s1)
  move  $a0, $s7
  sll   $t3, $t2, 8
  or    $v0, $t3, $t4
  andi  $a2, $v0, 0xffff
  jal   check_if_actorID_is_at_preset
   lbu   $a1, 1($s1)
  beqz  $v0, .L7F036CC8
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 4($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036CC8:
  addiu $s2, $s2, 5
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 5
action55_GoIntoRVLIf_Entered_Room_with_Preset_4:
  lbu   $t5, 1($s1)
  lbu   $t7, 2($s1)
  move  $a0, $s7
  sll   $t6, $t5, 8
  or    $v0, $t6, $t7
  jal   check_if_actor_is_at_preset
   andi  $a1, $v0, 0xffff
  beqz  $v0, .L7F036D10
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 3($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036D10:
  addiu $s2, $s2, 4
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
action56_GoIntoRVLIf_16_Object_num_Collected_3:
  jal   get_handle_to_tagged_object
   lbu   $a0, 1($s1)
  beql  $v0, $zero, .L7F036D64
   addiu $s2, $s2, 3
  lw    $t1, 0x10($v0)
  beql  $t1, $zero, .L7F036D64
   addiu $s2, $s2, 3
  jal   sub_GAME_7F08CFE0
   lw    $a0, 0x10($v0)
  beqz  $v0, .L7F036D60
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036D60:
  addiu $s2, $s2, 3
.L7F036D64:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action57_GoIntoRVLIf_Specified_Weapon_Deposited_3:
  jal   check_if_item_deposited
   lbu   $a0, 1($s1)
  beqz  $v0, .L7F036D94
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036D94:
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action58_GoIntoRVLIf_SpecifiedWeaponDeposited_On16Object_4:
  lbu   $a0, 2($s1)
  jal   get_handle_to_tagged_object
   move  $s0, $zero
  beqz  $v0, .L7F036E04
   move  $a1, $s2
  lw    $a0, 0x10($v0)
  beqz  $a0, .L7F036E04
   nop   
  lw    $v1, 0x20($a0)
  beqz  $v1, .L7F036E04
   nop   
  lbu   $t2, ($v1)
.L7F036DD0:
  li    $at, 4
  bnel  $t2, $at, .L7F036DFC
   lw    $v1, 0x24($v1)
  lw    $v0, 4($v1)
  lbu   $t3, 1($s1)
  lb    $t4, 0x80($v0)
  bnel  $t3, $t4, .L7F036DFC
   lw    $v1, 0x24($v1)
  b     .L7F036E04
   li    $s0, 1
  lw    $v1, 0x24($v1)
.L7F036DFC:
  bnezl $v1, .L7F036DD0
   lbu   $t2, ($v1)
.L7F036E04:
  beqz  $s0, .L7F036E20
   move  $a0, $s6
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 3($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036E20:
  addiu $s2, $s2, 4
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
action59_GoIntoRVLIf_Specified_Weapon_Is_Out_3:
  jal   get_item_in_hand
   move  $a0, $zero
  lbu   $t9, 1($s1)
  beql  $v0, $t9, .L7F036E54
   move  $a0, $s6
  jal   get_item_in_hand
   li    $a0, 1
  lbu   $t5, 1($s1)
  bne   $v0, $t5, .L7F036E6C
   move  $a0, $s6
.L7F036E54:
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036E6C:
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action5A_GoIntoRVLIf_Type_16_Object_num_Loaded_3:
  jal   get_handle_to_tagged_object
   lbu   $a0, 1($s1)
  beql  $v0, $zero, .L7F036EB4
   addiu $s2, $s2, 3
  lw    $t6, 0x10($v0)
  move  $a0, $s6
  move  $a1, $s2
  beql  $t6, $zero, .L7F036EB4
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F036EB4:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action5B_GoIntoRVLIf_16_Object_num_Not_Destroyed_3:
  jal   get_handle_to_tagged_object
   lbu   $a0, 1($s1)
  beqz  $v0, .L7F036F00
   move  $a0, $v0
  lw    $t7, 0x10($v0)
  beql  $t7, $zero, .L7F036F04
   addiu $s2, $s2, 3
  jal   check_if_object_has_not_been_destroyed
   nop   
  beqz  $v0, .L7F036F00
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036F00:
  addiu $s2, $s2, 3
.L7F036F04:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action5C_GoIntoRVLIf_16_Object_num_Activated_3:
  jal   get_handle_to_tagged_object
   lbu   $a0, 1($s1)
  beql  $v0, $zero, .L7F036F68
   addiu $s2, $s2, 3
  lw    $t8, 0x10($v0)
  beql  $t8, $zero, .L7F036F68
   addiu $s2, $s2, 3
  lw    $t1, 0x64($v0)
  li    $at, -16385
  andi  $t2, $t1, 0x4000
  beql  $t2, $zero, .L7F036F68
   addiu $s2, $s2, 3
  lw    $t3, 0x64($v0)
  move  $a0, $s6
  move  $a1, $s2
  and   $t4, $t3, $at
  sw    $t4, 0x64($v0)
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F036F68:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action5D_GoIntoRVLIf_Gadget_Used_On_16_Object_num_3:
  jal   get_handle_to_tagged_object
   lbu   $a0, 1($s1)
  beql  $v0, $zero, .L7F036FC8
   addiu $s2, $s2, 3
  lw    $t9, 0x10($v0)
  beql  $t9, $zero, .L7F036FC8
   addiu $s2, $s2, 3
  lbu   $t5, 2($v0)
  andi  $t6, $t5, 0x40
  beql  $t6, $zero, .L7F036FC8
   addiu $s2, $s2, 3
  lbu   $t7, 2($v0)
  move  $a0, $s6
  move  $a1, $s2
  andi  $t8, $t7, 0xffbf
  sb    $t8, 2($v0)
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F036FC8:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action5E_16_Object_Activates_2:
  jal   get_handle_to_tagged_object
   lbu   $a0, 1($s1)
  beqz  $v0, .L7F03702C
   move  $a1, $v0
  lw    $a0, 0x10($v0)
  beql  $a0, $zero, .L7F037030
   addiu $s2, $s2, 2
  lbu   $v1, ($a0)
  li    $at, 2
  bnel  $v1, $at, .L7F037014
   li    $at, 1
  jal   sub_GAME_7F05599C
   lw    $a0, 0x10($v0)
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
  li    $at, 1
.L7F037014:
  beq   $v1, $at, .L7F037024
   li    $at, 4
  bnel  $v1, $at, .L7F037030
   addiu $s2, $s2, 2
.L7F037024:
  jal   sub_GAME_7F04F170
   lw    $a0, 0x10($a1)
.L7F03702C:
  addiu $s2, $s2, 2
.L7F037030:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action5F_16_Object_Explodes_2:
  jal   get_handle_to_tagged_object
   lbu   $a0, 1($s1)
  beqz  $v0, .L7F0370A8
   move  $s0, $v0
  lw    $t1, 0x10($v0)
  beql  $t1, $zero, .L7F0370AC
   addiu $s2, $s2, 2
  jal   do_something_if_object_destroyed
   move  $a0, $v0
  bnezl $v0, .L7F0370AC
   addiu $s2, $s2, 2
  lwc1  $f8, 0x74($s0)
  lwc1  $f10, 0x70($s0)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f18
  sub.s $f16, $f8, $f10
  li    $at, 0x437A0000 # 250.000000
  mtc1  $at, $f6
  li    $t2, -1
  add.s $f4, $f16, $f18
  sw    $t2, 0x10($sp)
  move  $a0, $s0
  addiu $a2, $s0, 0x58
  div.s $f0, $f4, $f6
  li    $a3, 29
  mfc1  $a1, $f0
  jal   maybe_detonate_object
   nop   
.L7F0370A8:
  addiu $s2, $s2, 2
.L7F0370AC:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action60_Guard_Drops_16_Object_num_2:
  jal   get_handle_to_tagged_object
   lbu   $a0, 1($s1)
  beqz  $v0, .L7F03710C
   move  $a2, $v0
  lw    $a0, 0x10($v0)
  beql  $a0, $zero, .L7F037110
   addiu $s2, $s2, 2
  lw    $v1, 0x1c($a0)
  beql  $v1, $zero, .L7F037110
   addiu $s2, $s2, 2
  lbu   $t3, ($v1)
  li    $at, 3
  bnel  $t3, $at, .L7F037110
   addiu $s2, $s2, 2
  lw    $a0, 0x10($v0)
  li    $a1, 2
  lw    $t4, 0x1c($a0)
  jal   sub_GAME_7F04BFD0
   lw    $s0, 4($t4)
  lhu   $t9, 0x12($s0)
  ori   $t5, $t9, 1
  sh    $t5, 0x12($s0)
.L7F03710C:
  addiu $s2, $s2, 2
.L7F037110:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action61_Kill_Guard_num_2:
  move  $a0, $s7
  jal   get_handle_for_guard_id
   lbu   $a1, 1($s1)
  beqz  $v0, .L7F037140
   move  $a0, $v0
  lw    $t6, 0x18($v0)
  beql  $t6, $zero, .L7F037144
   addiu $s2, $s2, 2
  jal   sub_GAME_7F021B20
   nop   
.L7F037140:
  addiu $s2, $s2, 2
.L7F037144:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action62_Guard_num_Throws_Equipment_2:
  move  $a0, $s7
  jal   get_handle_for_guard_id
   lbu   $a1, 1($s1)
  beqz  $v0, .L7F0371B0
   move  $s0, $v0
  lw    $t7, 0x18($v0)
  beql  $t7, $zero, .L7F0371B4
   addiu $s2, $s2, 2
  lw    $t8, 0x160($v0)
  li    $a1, 1
  beql  $t8, $zero, .L7F037194
   lw    $a0, 0x164($s0)
  jal   sub_GAME_7F04BFD0
   lw    $a0, 0x160($v0)
  lhu   $t1, 0x12($s0)
  ori   $t2, $t1, 1
  sh    $t2, 0x12($s0)
  lw    $a0, 0x164($s0)
.L7F037194:
  beql  $a0, $zero, .L7F0371B4
   addiu $s2, $s2, 2
  jal   sub_GAME_7F04BFD0
   li    $a1, 1
  lhu   $t3, 0x12($s0)
  ori   $t4, $t3, 1
  sh    $t4, 0x12($s0)
.L7F0371B0:
  addiu $s2, $s2, 2
.L7F0371B4:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action63_Guard_Gives_Bond_16_Object_num_2:
  jal   get_handle_to_tagged_object
   lbu   $a0, 1($s1)
  beqz  $v0, .L7F0371F0
   move  $s0, $v0
  lw    $t9, 0x10($v0)
  move  $a1, $zero
  beql  $t9, $zero, .L7F0371F4
   addiu $s2, $s2, 2
  jal   collect_or_interact_object
   lw    $a0, 0x10($v0)
  lw    $a0, 0x10($s0)
  jal   sub_GAME_7F03C2BC
   move  $a1, $v0
.L7F0371F0:
  addiu $s2, $s2, 2
.L7F0371F4:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action64_Type_16_Object_Equipped_On_Guard_3:
  jal   get_handle_to_tagged_object
   lbu   $a0, 1($s1)
  move  $s0, $v0
  move  $a0, $s7
  jal   get_handle_for_guard_id
   lbu   $a1, 2($s1)
  beqz  $s0, .L7F037294
   move  $s3, $v0
  lw    $a0, 0x10($s0)
  beql  $a0, $zero, .L7F037298
   addiu $s2, $s2, 3
  beql  $v0, $zero, .L7F037298
   addiu $s2, $s2, 3
  lw    $t5, 0x1c($a0)
  beqz  $t5, .L7F03724C
   nop   
  jal   sub_GAME_7F04C044
   nop   
  b     .L7F037268
   lbu   $t6, 3($s0)
.L7F03724C:
  jal   sub_GAME_7F03E18C
   nop   
  jal   sub_GAME_7F03A538
   lw    $a0, 0x10($s0)
  jal   unset_stateflag_0x04_for_posdata
   lw    $a0, 0x10($s0)
  lbu   $t6, 3($s0)
.L7F037268:
  li    $at, 8
  move  $a0, $s0
  bnel  $t6, $at, .L7F03728C
   lw    $a0, 0x10($s0)
  jal   sub_GAME_7F051E1C
   move  $a1, $s3
  bnezl $v0, .L7F037298
   addiu $s2, $s2, 3
  lw    $a0, 0x10($s0)
.L7F03728C:
  jal   sub_GAME_7F03A5A4
   lw    $a1, 0x18($s3)
.L7F037294:
  addiu $s2, $s2, 3
.L7F037298:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action65_Object_Moved_To_Preset_4:
  jal   get_handle_to_tagged_object
   lbu   $a0, 1($s1)
  sw    $v0, 0x500($sp)
  lbu   $t7, 2($s1)
  lbu   $t1, 3($s1)
  sll   $t8, $t7, 8
  or    $v1, $t8, $t1
  beqz  $v0, .L7F0373B0
   andi  $t2, $v1, 0xffff
  lw    $t3, 0x10($v0)
  move  $s3, $v0
  slti  $at, $t2, 0x2710
  beql  $t3, $zero, .L7F0373B4
   addiu $s2, $s2, 4
  beqz  $at, .L7F037304
   move  $v0, $t2
  sll   $t4, $t2, 2
  subu  $t4, $t4, $t2
  sll   $t4, $t4, 2
  lui   $t9, %hi(ptr_0xxxpresets) 
  lw    $t9, %lo(ptr_0xxxpresets)($t9)
  subu  $t4, $t4, $t2
  sll   $t4, $t4, 2
  b     .L7F037328
   addu  $s0, $t4, $t9
.L7F037304:
  lui   $t6, %hi(ptr_2xxxpresets) 
  lw    $t6, %lo(ptr_2xxxpresets)($t6)
  sll   $t5, $v0, 4
  addu  $t5, $t5, $v0
  sll   $t5, $t5, 2
  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
  addu  $s0, $t5, $t6
  addu  $s0, $s0, $at
.L7F037328:
  lwc1  $f8, 0x18($s0)
  mfc1  $a1, $f20
  mfc1  $a2, $f20
  neg.s $f10, $f8
  mfc1  $a3, $f20
  swc1  $f10, 0x10($sp)
  lwc1  $f16, 0x1c($s0)
  addiu $a0, $sp, 0x4b8
  neg.s $f18, $f16
  swc1  $f18, 0x14($sp)
  lwc1  $f4, 0x20($s0)
  neg.s $f6, $f4
  swc1  $f6, 0x18($sp)
  lwc1  $f8, 0xc($s0)
  swc1  $f8, 0x1c($sp)
  lwc1  $f10, 0x10($s0)
  swc1  $f10, 0x20($sp)
  lwc1  $f16, 0x14($s0)
  jal   sub_GAME_7F059908
   swc1  $f16, 0x24($sp)
  lw    $v0, 0x14($s3)
  addiu $a1, $sp, 0x4b8
  beql  $v0, $zero, .L7F037394
   lw    $a3, 0x28($s0)
  jal   matrix_multiply_A1_by_F12
   lwc1  $f12, 0x14($v0)
  lw    $a3, 0x28($s0)
.L7F037394:
  sw    $s0, 0x10($sp)
  move  $a0, $s3
  move  $a1, $s0
  jal   sub_GAME_7F04088C
   addiu $a2, $sp, 0x4b8
  jal   sub_GAME_7F056CA0
   move  $a0, $s3
.L7F0373B0:
  addiu $s2, $s2, 4
.L7F0373B4:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
action66_Open_Door_2:
  jal   get_handle_to_tagged_object
   lbu   $a0, 1($s1)
  beqz  $v0, .L7F0373F4
   move  $a2, $v0
  lw    $a0, 0x10($v0)
  beql  $a0, $zero, .L7F0373F8
   addiu $s2, $s2, 2
  lbu   $t7, ($a0)
  li    $at, 2
  move  $a0, $v0
  bnel  $t7, $at, .L7F0373F8
   addiu $s2, $s2, 2
  jal   set_door_state
   li    $a1, 1
.L7F0373F4:
  addiu $s2, $s2, 2
.L7F0373F8:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action67_Close_Door_2:
  jal   get_handle_to_tagged_object
   lbu   $a0, 1($s1)
  beqz  $v0, .L7F037438
   move  $a2, $v0
  lw    $a0, 0x10($v0)
  beql  $a0, $zero, .L7F03743C
   addiu $s2, $s2, 2
  lbu   $t8, ($a0)
  li    $at, 2
  move  $a0, $v0
  bnel  $t8, $at, .L7F03743C
   addiu $s2, $s2, 2
  jal   set_door_state
   li    $a1, 2
.L7F037438:
  addiu $s2, $s2, 2
.L7F03743C:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action68_Check_Door_Status_RVL_If_Met_4:
  lbu   $a0, 1($s1)
  jal   get_handle_to_tagged_object
   move  $s0, $zero
  beqz  $v0, .L7F0374F0
   move  $a0, $s6
  lw    $t1, 0x10($v0)
  beqz  $t1, .L7F0374F0
   nop   
  lbu   $t2, 3($v0)
  li    $at, 1
  bne   $t2, $at, .L7F0374F0
   nop   
  lb    $v1, 0xbc($v0)
  li    $at, 1
  bnez  $v1, .L7F0374B8
   nop   
  lwc1  $f18, 0xb4($v0)
  c.le.s $f18, $f20
  nop   
  bc1fl .L7F0374AC
   lbu   $s0, 2($s1)
  lbu   $s0, 2($s1)
  andi  $t3, $s0, 1
  b     .L7F0374F0
   sltu  $s0, $zero, $t3
  lbu   $s0, 2($s1)
.L7F0374AC:
  andi  $t9, $s0, 2
  b     .L7F0374F0
   sltu  $s0, $zero, $t9
.L7F0374B8:
  beq   $v1, $at, .L7F0374C8
   li    $at, 3
  bnel  $v1, $at, .L7F0374DC
   li    $at, 2
.L7F0374C8:
  lbu   $s0, 2($s1)
  andi  $t6, $s0, 8
  b     .L7F0374F0
   sltu  $s0, $zero, $t6
  li    $at, 2
.L7F0374DC:
  bne   $v1, $at, .L7F0374F0
   nop   
  lbu   $s0, 2($s1)
  andi  $t8, $s0, 4
  sltu  $s0, $zero, $t8
.L7F0374F0:
  beqz  $s0, .L7F03750C
   move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 3($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F03750C:
  addiu $s2, $s2, 4
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
action69_If_16_Object_Is_Valid_Door_RVL_3:
  jal   get_handle_to_tagged_object
   lbu   $a0, 1($s1)
  beql  $v0, $zero, .L7F037574
   addiu $s2, $s2, 3
  lw    $t2, 0x10($v0)
  beql  $t2, $zero, .L7F037574
   addiu $s2, $s2, 3
  lbu   $t3, 3($v0)
  li    $at, 1
  bnel  $t3, $at, .L7F037574
   addiu $s2, $s2, 3
  lw    $t4, 0x64($v0)
  move  $a0, $s6
  move  $a1, $s2
  andi  $t9, $t4, 0x200
  beql  $t9, $zero, .L7F037574
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F037574:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action6A_Set_Bits_To_Lock_On_Type_16_Door_3:
  jal   get_handle_to_tagged_object
   lbu   $a0, 1($s1)
  beqz  $v0, .L7F0375B8
   addiu $s2, $s2, 3
  lw    $a0, 0x10($v0)
  beqz  $a0, .L7F0375B8
   nop   
  lbu   $t5, ($a0)
  li    $at, 2
  bne   $t5, $at, .L7F0375B8
   nop   
  lbu   $v1, 2($s1)
  lw    $t6, 0x9c($v0)
  or    $t7, $t6, $v1
  sw    $t7, 0x9c($v0)
.L7F0375B8:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action6B_Unset_Bits_To_Lock_On_Type_16_Door_3:
  jal   get_handle_to_tagged_object
   lbu   $a0, 1($s1)
  beqz  $v0, .L7F037600
   addiu $s2, $s2, 3
  lw    $a0, 0x10($v0)
  beqz  $a0, .L7F037600
   nop   
  lbu   $t8, ($a0)
  li    $at, 2
  bne   $t8, $at, .L7F037600
   nop   
  lbu   $v1, 2($s1)
  lw    $t1, 0x9c($v0)
  not   $t2, $v1
  and   $t3, $t1, $t2
  sw    $t3, 0x9c($v0)
.L7F037600:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action6C_If_Tagged_Locked_Door_16_Objects_Toggled_RVL_4:
  lbu   $a0, 1($s1)
  jal   get_handle_to_tagged_object
   move  $s0, $zero
  beqz  $v0, .L7F037650
   move  $a1, $s2
  lw    $a0, 0x10($v0)
  beqz  $a0, .L7F037650
   nop   
  lbu   $t4, ($a0)
  li    $at, 2
  bne   $t4, $at, .L7F037650
   nop   
  lbu   $v1, 2($s1)
  lw    $t9, 0x9c($v0)
  and   $t5, $t9, $v1
  bne   $v1, $t5, .L7F037650
   nop   
  li    $s0, 1
.L7F037650:
  beqz  $s0, .L7F03766C
   move  $a0, $s6
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 3($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F03766C:
  addiu $s2, $s2, 4
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
action6D_If_Objective_num_Complete_RVL_3:
  jal   add_objective
   nop   
  lbu   $a1, 1($s1)
  slt   $at, $a1, $v0
  beql  $at, $zero, .L7F0376C0
   addiu $s2, $s2, 3
  jal   get_status_of_objective
   move  $a0, $a1
  li    $at, 1
  bne   $v0, $at, .L7F0376BC
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F0376BC:
  addiu $s2, $s2, 3
.L7F0376C0:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action6E_If_Guard_2328_Preset_RVL_3:
  move  $a0, $s7
  jal   check_2328_preset_set_with_method
   lbu   $a1, 1($s1)
  beqz  $v0, .L7F0376F4
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F0376F4:
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action6F_If_Guard_2328_Preset_Set_RVL_3:
  move  $a0, $s7
  jal   sub_GAME_7F033AAC
   lbu   $a1, 1($s1)
  beqz  $v0, .L7F03772C
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F03772C:
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action78_Go_To_RVL_If_Guard_Shot_LTV_3:
  jal   get_times_actor_shot
   move  $a0, $s7
  lbu   $t6, 1($s1)
  move  $a0, $s6
  move  $a1, $s2
  slt   $at, $v0, $t6
  beql  $at, $zero, .L7F037770
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F037770:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action79_Go_To_RVL_If_Guard_Shot_GTV_3:
  jal   get_times_actor_shot
   move  $a0, $s7
  lbu   $t7, 1($s1)
  move  $a0, $s6
  move  $a1, $s2
  slt   $at, $t7, $v0
  beql  $at, $zero, .L7F0377B0
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F0377B0:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action7A_Go_To_RVL_If_Number_Near_Miss_Gunshots_LTV_3:
  jal   get_num_shots_near_actor
   move  $a0, $s7
  lbu   $t8, 1($s1)
  move  $a0, $s6
  move  $a1, $s2
  slt   $at, $v0, $t8
  beql  $at, $zero, .L7F0377F0
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F0377F0:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action7B_Go_To_RVL_If_Number_Near_Miss_Gunshots_GTV_3:
  jal   get_num_shots_near_actor
   move  $a0, $s7
  lbu   $t1, 1($s1)
  move  $a0, $s6
  move  $a1, $s2
  slt   $at, $t1, $v0
  beql  $at, $zero, .L7F037830
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F037830:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action7C_If_Guard_Health_Below_Value_RVL_4:
  lbu   $t2, 2($s1)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t2, $f4
  bgez  $t2, .L7F037858
   cvt.s.w $f6, $f4
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F037858:
  lui   $at, %hi(D_800528EC)
  lwc1  $f10, %lo(D_800528EC)($at)
  move  $a0, $s7
  mul.s $f16, $f6, $f10
  swc1  $f16, 0x438($sp)
  jal   get_handle_for_guard_id
   lbu   $a1, 1($s1)
  beql  $v0, $zero, .L7F0378BC
   addiu $s2, $s2, 4
  lwc1  $f18, 0x100($v0)
  lwc1  $f4, 0xfc($v0)
  lwc1  $f6, 0x438($sp)
  move  $a0, $s6
  sub.s $f8, $f18, $f4
  move  $a1, $s2
  c.lt.s $f8, $f6
  nop   
  bc1fl .L7F0378BC
   addiu $s2, $s2, 4
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 3($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 4
.L7F0378BC:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
action7D_If_Guard_Health_Above_Value_RVL_4:
  lbu   $t3, 2($s1)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t3, $f10
  bgez  $t3, .L7F0378E4
   cvt.s.w $f16, $f10
  mtc1  $at, $f18
  nop   
  add.s $f16, $f16, $f18
.L7F0378E4:
  lui   $at, %hi(D_800528F0)
  lwc1  $f4, %lo(D_800528F0)($at)
  move  $a0, $s7
  mul.s $f8, $f16, $f4
  swc1  $f8, 0x42c($sp)
  jal   get_handle_for_guard_id
   lbu   $a1, 1($s1)
  beql  $v0, $zero, .L7F037948
   addiu $s2, $s2, 4
  lwc1  $f10, 0x100($v0)
  lwc1  $f18, 0xfc($v0)
  lwc1  $f6, 0x42c($sp)
  move  $a0, $s6
  sub.s $f16, $f10, $f18
  move  $a1, $s2
  c.lt.s $f6, $f16
  nop   
  bc1fl .L7F037948
   addiu $s2, $s2, 4
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 3($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 4
.L7F037948:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
action7E_If_Guard_nums_Bitflag_01000000_Set_RVL_3:
  move  $a0, $s7
  jal   get_handle_for_guard_id
   lbu   $a1, 1($s1)
  beql  $v0, $zero, .L7F0379A4
   addiu $s2, $s2, 3
  lw    $t4, 0x14($v0)
  li    $at, -257
  andi  $t9, $t4, 0x100
  beql  $t9, $zero, .L7F0379A4
   addiu $s2, $s2, 3
  lw    $t5, 0x14($v0)
  move  $a0, $s6
  move  $a1, $s2
  and   $t6, $t5, $at
  sw    $t6, 0x14($v0)
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F0379A4:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action7F_If_Health_Below_Value_RVL_3:
  lbu   $t7, 1($s1)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t7, $f4
  bgez  $t7, .L7F0379CC
   cvt.s.w $f8, $f4
  mtc1  $at, $f10
  nop   
  add.s $f8, $f8, $f10
.L7F0379CC:
  li    $at, 0x437F0000 # 255.000000
  mtc1  $at, $f18
  nop   
  div.s $f6, $f8, $f18
  jal   get_BONDdata_watch_health
   swc1  $f6, 0x418($sp)
  lwc1  $f16, 0x418($sp)
  move  $a0, $s6
  move  $a1, $s2
  c.lt.s $f0, $f16
  nop   
  bc1fl .L7F037A18
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F037A18:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action80_If_Health_Above_Value_RVL_3:
  lbu   $t8, 1($s1)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t8, $f4
  bgez  $t8, .L7F037A40
   cvt.s.w $f10, $f4
  mtc1  $at, $f8
  nop   
  add.s $f10, $f10, $f8
.L7F037A40:
  li    $at, 0x437F0000 # 255.000000
  mtc1  $at, $f18
  nop   
  div.s $f6, $f10, $f18
  jal   get_BONDdata_watch_health
   swc1  $f6, 0x410($sp)
  lwc1  $f16, 0x410($sp)
  move  $a0, $s6
  move  $a1, $s2
  c.lt.s $f16, $f0
  nop   
  bc1fl .L7F037A8C
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F037A8C:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action70_Go_Into_RVL_Difficulty_LTV_3:
  jal   get_current_difficulty
   nop   
  lbu   $t1, 1($s1)
  move  $a0, $s6
  move  $a1, $s2
  slt   $at, $v0, $t1
  beql  $at, $zero, .L7F037ACC
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F037ACC:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action71_GoIntoRVLIf_Difficulty_GTV_3:
  jal   get_current_difficulty
   nop   
  lbu   $t2, 1($s1)
  move  $a0, $s6
  move  $a1, $s2
  slt   $at, $t2, $v0
  beql  $at, $zero, .L7F037B0C
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F037B0C:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action72_Go_To_RVL_If_Time_LTV_4:
  lbu   $t3, 1($s1)
  lbu   $t9, 2($s1)
  sll   $t4, $t3, 8
  or    $t5, $t4, $t9
  mtc1  $t5, $f4
  nop   
  cvt.s.w $f8, $f4
  jal   get_cur_mp_sec
   swc1  $f8, 0x400($sp)
  lwc1  $f10, 0x400($sp)
  move  $a0, $s6
  move  $a1, $s2
  c.lt.s $f0, $f10
  nop   
  bc1fl .L7F037B6C
   addiu $s2, $s2, 4
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 3($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 4
.L7F037B6C:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
action73_Go_To_RVL_If_Time_GTV_4:
  lbu   $t6, 1($s1)
  lbu   $t8, 2($s1)
  sll   $t7, $t6, 8
  or    $t1, $t7, $t8
  mtc1  $t1, $f18
  nop   
  cvt.s.w $f6, $f18
  jal   get_cur_mp_sec
   swc1  $f6, 0x3f8($sp)
  lwc1  $f16, 0x3f8($sp)
  move  $a0, $s6
  move  $a1, $s2
  c.lt.s $f16, $f0
  nop   
  bc1fl .L7F037BCC
   addiu $s2, $s2, 4
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 3($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 4
.L7F037BCC:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
action74_Go_To_RVL_If_Power_On_Time_LTV_4:
  lbu   $t2, 1($s1)
  lbu   $t4, 2($s1)
  sll   $t3, $t2, 8
  or    $t9, $t3, $t4
  mtc1  $t9, $f4
  nop   
  cvt.s.w $f8, $f4
  mul.s $f10, $f8, $f22
  jal   get_cur_mp_min
   swc1  $f10, 0x3f0($sp)
  lwc1  $f18, 0x3f0($sp)
  move  $a0, $s6
  move  $a1, $s2
  c.lt.s $f0, $f18
  nop   
  bc1fl .L7F037C30
   addiu $s2, $s2, 4
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 3($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 4
.L7F037C30:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
action75_Go_To_RVL_If_Power_On_Time_GTV_4:
  lbu   $t5, 1($s1)
  lbu   $t7, 2($s1)
  sll   $t6, $t5, 8
  or    $t8, $t6, $t7
  mtc1  $t8, $f6
  nop   
  cvt.s.w $f16, $f6
  mul.s $f4, $f16, $f22
  jal   get_cur_mp_min
   swc1  $f4, 0x3e8($sp)
  lwc1  $f8, 0x3e8($sp)
  move  $a0, $s6
  move  $a1, $s2
  c.lt.s $f8, $f0
  nop   
  bc1fl .L7F037C94
   addiu $s2, $s2, 4
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 3($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 4
.L7F037C94:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
action76_Go_To_RVL_If_Stage_Number_LTV_3:
  jal   get_stage_num
   nop   
  lbu   $t1, 1($s1)
  move  $a0, $s6
  move  $a1, $s2
  slt   $at, $v0, $t1
  beql  $at, $zero, .L7F037CD4
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F037CD4:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action77_Go_To_RVL_If_Stage_Number_GTV_3:
  jal   get_stage_num
   nop   
  lbu   $t2, 1($s1)
  move  $a0, $s6
  move  $a1, $s2
  slt   $at, $t2, $v0
  beql  $at, $zero, .L7F037D14
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F037D14:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action81_Set_User_Byte_num1_2:
  lbu   $t3, 1($s1)
  addiu $s2, $s2, 2
  addiu $s1, $s1, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   sb    $t3, 0x10c($s7)
action82_Add_Value_To_User_Byte_num1_Max_To_FF_2:
  lbu   $a1, 1($s1)
  lbu   $v0, 0x10c($s7)
  li    $t4, 255
  subu  $t9, $t4, $a1
  slt   $at, $t9, $v0
  beqz  $at, .L7F037D60
   addu  $t6, $v0, $a1
  li    $t5, 255
  sb    $t5, 0x10c($s7)
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
.L7F037D60:
  sb    $t6, 0x10c($s7)
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action83_Subtract_Value_To_User_Byte_num1_Min_To_0_2:
  lbu   $v0, 0x10c($s7)
  lbu   $a1, 1($s1)
  slt   $at, $v0, $a1
  beqz  $at, .L7F037D94
   subu  $t7, $v0, $a1
  sb    $zero, 0x10c($s7)
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
.L7F037D94:
  sb    $t7, 0x10c($s7)
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action84_If_Value_GreaterThan_User_Byte_num1_RVL_3:
  lbu   $t8, 0x10c($s7)
  lbu   $t1, 1($s1)
  move  $a0, $s6
  move  $a1, $s2
  slt   $at, $t8, $t1
  beql  $at, $zero, .L7F037DD8
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F037DD8:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action85_If_User_Byte_num1_LessThan_Random_Value_RVL_2:
  lbu   $t2, 0x10c($s7)
  lbu   $t3, 0x10f($s7)
  move  $a0, $s6
  move  $a1, $s2
  slt   $at, $t2, $t3
  beql  $at, $zero, .L7F037E14
   addiu $s2, $s2, 2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 2
.L7F037E14:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action86_Set_User_Byte_num2_2:
  lbu   $t4, 1($s1)
  addiu $s2, $s2, 2
  addiu $s1, $s1, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   sb    $t4, 0x10d($s7)
action87_Add_Value_To_User_Byte_num2_Max_To_FF_2:
  lbu   $a1, 1($s1)
  lbu   $v0, 0x10d($s7)
  li    $t9, 255
  subu  $t5, $t9, $a1
  slt   $at, $t5, $v0
  beqz  $at, .L7F037E60
   addu  $t7, $v0, $a1
  li    $t6, 255
  sb    $t6, 0x10d($s7)
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
.L7F037E60:
  sb    $t7, 0x10d($s7)
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action88_Subtract_Value_To_User_Byte_num2_Min_To_0_2:
  lbu   $v0, 0x10d($s7)
  lbu   $a1, 1($s1)
  slt   $at, $v0, $a1
  beqz  $at, .L7F037E94
   subu  $t8, $v0, $a1
  sb    $zero, 0x10d($s7)
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
.L7F037E94:
  sb    $t8, 0x10d($s7)
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action89_If_Value_GreaterThan_User_Byte_num2_RVL_3:
  lbu   $t1, 0x10d($s7)
  lbu   $t2, 1($s1)
  move  $a0, $s6
  move  $a1, $s2
  slt   $at, $t1, $t2
  beql  $at, $zero, .L7F037ED8
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F037ED8:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action8A_If_User_Byte_num2_LessThan_Random_Value_RVL_2:
  lbu   $t3, 0x10d($s7)
  lbu   $t4, 0x10f($s7)
  move  $a0, $s6
  move  $a1, $s2
  slt   $at, $t3, $t4
  beql  $at, $zero, .L7F037F14
   addiu $s2, $s2, 2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 2
.L7F037F14:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action8B_Set_Guard_Hearing_Distance_3:
  lbu   $t9, 1($s1)
  lbu   $t6, 2($s1)
  li    $at, 0x447A0000 # 1000.000000
  sll   $t5, $t9, 8
  or    $t7, $t5, $t6
  mtc1  $t7, $f10
  mtc1  $at, $f6
  addiu $s2, $s2, 3
  cvt.s.w $f18, $f10
  addiu $s1, $s1, 3
  div.s $f0, $f18, $f6
  b     GetByteS1_ParseCommandByte_SwitchCase
   swc1  $f0, 0xec($s7)
action8C_Set_Guard_Visible_Distance_2:
  lbu   $t8, 1($s1)
  li    $at, 0x4F800000 # 4294967296.000000
  addiu $s2, $s2, 2
  mtc1  $t8, $f16
  addiu $s1, $s1, 2
  bgez  $t8, .L7F037F78
   cvt.s.w $f4, $f16
  mtc1  $at, $f8
  nop   
  add.s $f4, $f4, $f8
.L7F037F78:
  b     GetByteS1_ParseCommandByte_SwitchCase
   swc1  $f4, 0xd0($s7)
action8D_Set_Guard_Grenade_Probability_2:
  lbu   $t1, 1($s1)
  addiu $s2, $s2, 2
  addiu $s1, $s1, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   sb    $t1, 0x10($s7)
action8E_Set_Guard_ID_2:
  lbu   $t2, 1($s1)
  addiu $s2, $s2, 2
  addiu $s1, $s1, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   sh    $t2, ($s7)
action8F_Set_Guard_Health_3:
  lbu   $t3, 1($s1)
  lbu   $t9, 2($s1)
  lui   $at, %hi(D_800528F4)
  sll   $t4, $t3, 8
  or    $t5, $t4, $t9
  mtc1  $t5, $f10
  lwc1  $f6, %lo(D_800528F4)($at)
  move  $a0, $s7
  cvt.s.w $f18, $f10
  mul.s $f0, $f18, $f6
  mfc1  $a1, $f0
  jal   sub_GAME_7F020018
   nop   
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action90_Set_Guard_Armor_Amount_3:
  lbu   $t6, 1($s1)
  lbu   $t8, 2($s1)
  lui   $at, %hi(D_800528F8)
  sll   $t7, $t6, 8
  or    $t1, $t7, $t8
  mtc1  $t1, $f16
  lwc1  $f4, %lo(D_800528F8)($at)
  move  $a0, $s7
  cvt.s.w $f8, $f16
  mul.s $f0, $f8, $f4
  mfc1  $a1, $f0
  jal   sub_GAME_7F020054
   nop   
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action91_Set_Character_Reaction_Speed_2:
  lb    $t2, 1($s1)
  addiu $s2, $s2, 2
  addiu $s1, $s1, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   sb    $t2, 3($s7)
action92_Set_Character_Injury_Recovery_Speed_2:
  lb    $t3, 1($s1)
  addiu $s2, $s2, 2
  addiu $s1, $s1, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   sb    $t3, 0xd($s7)
action93_Set_Character_Accuracy_2:
  lb    $t4, 1($s1)
  addiu $s2, $s2, 2
  addiu $s1, $s1, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   sb    $t4, 2($s7)
action94_Mask_Guard_Type_With_Value_2:
  move  $a0, $s7
  jal   sub_GAME_7F033218
   lbu   $a1, 1($s1)
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action95_Unmask_Guard_Type_With_Value_2:
  move  $a0, $s7
  jal   sub_GAME_7F03322C
   lbu   $a1, 1($s1)
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action96_If_Guard_Type_Value_Is_Set_RVL_3:
  move  $a0, $s7
  jal   sub_GAME_7F033244
   lbu   $a1, 1($s1)
  beqz  $v0, .L7F0380C0
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F0380C0:
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action97_Mask_Guard_Type_Flags_With_Value_3:
  move  $a0, $s7
  lbu   $a1, 1($s1)
  jal   sub_GAME_7F033260
   lbu   $a2, 2($s1)
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action98_Unmask_Guard_Type_Flags_With_Value_3:
  move  $a0, $s7
  lbu   $a1, 1($s1)
  jal   sub_GAME_7F033290
   lbu   $a2, 2($s1)
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action99_If_Guard_Type_Flags_Set_RVL_4:
  move  $a0, $s7
  lbu   $a1, 1($s1)
  jal   sub_GAME_7F0332C0
   lbu   $a2, 2($s1)
  beqz  $v0, .L7F038134
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 3($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F038134:
  addiu $s2, $s2, 4
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
action9A_Set_Objective_Bits_5:
  lbu   $t9, 1($s1)
  lbu   $t6, 2($s1)
  lbu   $t1, 3($s1)
  sll   $t5, $t9, 0x18
  sll   $t7, $t6, 0x10
  lbu   $t4, 4($s1)
  or    $t8, $t5, $t7
  sll   $t2, $t1, 8
  or    $t3, $t8, $t2
  move  $a0, $s7
  jal   toggle_objective_bitflags
   or    $a1, $t3, $t4
  addiu $s2, $s2, 5
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 5
action9B_Unset_Objective_Value_5:
  lbu   $t9, 1($s1)
  lbu   $t5, 2($s1)
  lbu   $t8, 3($s1)
  sll   $t6, $t9, 0x18
  sll   $t7, $t5, 0x10
  lbu   $t4, 4($s1)
  or    $t1, $t6, $t7
  sll   $t2, $t8, 8
  or    $t3, $t1, $t2
  move  $a0, $s7
  jal   untoggle_objective_bitflags
   or    $a1, $t3, $t4
  addiu $s2, $s2, 5
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 5
action9C_Check_If_Objective_Value_Return_Loop_If_So_6:
  lbu   $t9, 1($s1)
  lbu   $t6, 2($s1)
  lbu   $t1, 3($s1)
  sll   $t5, $t9, 0x18
  sll   $t7, $t6, 0x10
  lbu   $t4, 4($s1)
  or    $t8, $t5, $t7
  sll   $t2, $t1, 8
  or    $t3, $t8, $t2
  move  $a0, $s7
  jal   check_if_objective_bitflags_set
   or    $a1, $t3, $t4
  beqz  $v0, .L7F038208
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 5($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F038208:
  addiu $s2, $s2, 6
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 6
action9D_Set_Guard_Bit_Tags_5:
  lbu   $t9, 1($s1)
  lbu   $t5, 2($s1)
  lbu   $t8, 3($s1)
  sll   $t6, $t9, 0x18
  lbu   $t4, 4($s1)
  sll   $t7, $t5, 0x10
  lw    $t9, 0x14($s7)
  or    $t1, $t6, $t7
  sll   $t2, $t8, 8
  or    $t3, $t1, $t2
  or    $v0, $t3, $t4
  or    $t5, $t9, $v0
  sw    $t5, 0x14($s7)
  addiu $s2, $s2, 5
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 5
action9E_Unset_Guard_Bit_Tags_5:
  lbu   $t6, 1($s1)
  lbu   $t8, 2($s1)
  lbu   $t3, 3($s1)
  lbu   $t5, 4($s1)
  sll   $t7, $t6, 0x18
  sll   $t1, $t8, 0x10
  or    $t2, $t7, $t1
  sll   $t4, $t3, 8
  lw    $t6, 0x14($s7)
  or    $t9, $t2, $t4
  or    $v0, $t9, $t5
  not   $t8, $v0
  and   $t7, $t6, $t8
  sw    $t7, 0x14($s7)
  addiu $s2, $s2, 5
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 5
action9F_Check_Guard_Bits_If_Same_RVL_6:
  lbu   $t1, 1($s1)
  lbu   $t2, 2($s1)
  lbu   $t5, 3($s1)
  sll   $t3, $t1, 0x18
  lbu   $t7, 4($s1)
  sll   $t4, $t2, 0x10
  lw    $t1, 0x14($s7)
  or    $t9, $t3, $t4
  sll   $t6, $t5, 8
  or    $t8, $t9, $t6
  or    $v0, $t8, $t7
  and   $t2, $t1, $v0
  bne   $v0, $t2, .L7F0382E8
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 5($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F0382E8:
  addiu $s2, $s2, 6
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 6
actionA0_Set_Guard_ID_Bits_6:
  lbu   $t3, 2($s1)
  lbu   $t5, 3($s1)
  lbu   $t8, 4($s1)
  sll   $t4, $t3, 0x18
  sll   $t9, $t5, 0x10
  lbu   $t2, 5($s1)
  or    $t6, $t4, $t9
  sll   $t7, $t8, 8
  or    $t1, $t6, $t7
  move  $a0, $s7
  lbu   $a1, 1($s1)
  jal   get_handle_for_guard_id
   or    $s0, $t1, $t2
  beqz  $v0, .L7F03833C
   addiu $s2, $s2, 6
  lw    $t3, 0x14($v0)
  or    $t5, $t3, $s0
  sw    $t5, 0x14($v0)
.L7F03833C:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 6
actionA1_Unset_Guard_ID_Bits_6:
  lbu   $t4, 2($s1)
  lbu   $t8, 3($s1)
  lbu   $t1, 4($s1)
  sll   $t9, $t4, 0x18
  sll   $t6, $t8, 0x10
  lbu   $t5, 5($s1)
  or    $t7, $t9, $t6
  sll   $t2, $t1, 8
  or    $t3, $t7, $t2
  move  $a0, $s7
  lbu   $a1, 1($s1)
  jal   get_handle_for_guard_id
   or    $s0, $t3, $t5
  beqz  $v0, .L7F038390
   addiu $s2, $s2, 6
  lw    $t4, 0x14($v0)
  not   $t8, $s0
  and   $t9, $t4, $t8
  sw    $t9, 0x14($v0)
.L7F038390:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 6
actionA2_Check_Guard_Bits_If_Same_RVL_7:
  lbu   $t6, 2($s1)
  lbu   $t7, 3($s1)
  lbu   $t5, 4($s1)
  sll   $t1, $t6, 0x18
  sll   $t2, $t7, 0x10
  lbu   $t9, 5($s1)
  or    $t3, $t1, $t2
  sll   $t4, $t5, 8
  or    $t8, $t3, $t4
  move  $a0, $s7
  lbu   $a1, 1($s1)
  jal   get_handle_for_guard_id
   or    $s0, $t8, $t9
  beql  $v0, $zero, .L7F038404
   addiu $s2, $s2, 7
  lw    $t6, 0x14($v0)
  move  $a0, $s6
  move  $a1, $s2
  and   $t7, $t6, $s0
  bnel  $s0, $t7, .L7F038404
   addiu $s2, $s2, 7
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 6($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 7
.L7F038404:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 7
actionA3_Set_State_Bits_16_Type_Object_6:
  lbu   $t1, 2($s1)
  lbu   $t5, 3($s1)
  lbu   $t8, 4($s1)
  sll   $t2, $t1, 0x18
  sll   $t3, $t5, 0x10
  lbu   $t7, 5($s1)
  or    $t4, $t2, $t3
  sll   $t9, $t8, 8
  or    $t6, $t4, $t9
  lbu   $a0, 1($s1)
  jal   get_handle_to_tagged_object
   or    $s0, $t6, $t7
  beqz  $v0, .L7F03845C
   addiu $s2, $s2, 6
  lw    $t1, 0x10($v0)
  beqz  $t1, .L7F03845C
   nop   
  lw    $t5, 8($v0)
  or    $t2, $t5, $s0
  sw    $t2, 8($v0)
.L7F03845C:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 6
actionA4_Unset_State_Bits_16_Type_Object_6:
  lbu   $t3, 2($s1)
  lbu   $t4, 3($s1)
  lbu   $t7, 4($s1)
  sll   $t8, $t3, 0x18
  sll   $t9, $t4, 0x10
  lbu   $t2, 5($s1)
  or    $t6, $t8, $t9
  sll   $t1, $t7, 8
  or    $t5, $t6, $t1
  lbu   $a0, 1($s1)
  jal   get_handle_to_tagged_object
   or    $s0, $t5, $t2
  beqz  $v0, .L7F0384B8
   addiu $s2, $s2, 6
  lw    $t3, 0x10($v0)
  beqz  $t3, .L7F0384B8
   nop   
  lw    $t4, 8($v0)
  not   $t8, $s0
  and   $t9, $t4, $t8
  sw    $t9, 8($v0)
.L7F0384B8:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 6
actionA5_Check_State_Bits_16_Type_Object_If_Same_RVL_7:
  lbu   $t7, 2($s1)
  lbu   $t1, 3($s1)
  lbu   $t3, 4($s1)
  sll   $t6, $t7, 0x18
  sll   $t5, $t1, 0x10
  lbu   $t9, 5($s1)
  or    $t2, $t6, $t5
  sll   $t4, $t3, 8
  or    $t8, $t2, $t4
  lbu   $a0, 1($s1)
  jal   get_handle_to_tagged_object
   or    $s0, $t8, $t9
  beql  $v0, $zero, .L7F038534
   addiu $s2, $s2, 7
  lw    $t7, 0x10($v0)
  beql  $t7, $zero, .L7F038534
   addiu $s2, $s2, 7
  lw    $t1, 8($v0)
  move  $a0, $s6
  move  $a1, $s2
  and   $t6, $t1, $s0
  bnel  $s0, $t6, .L7F038534
   addiu $s2, $s2, 7
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 6($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 7
.L7F038534:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 7
actionA6_Set_16_Object_States_More_6:
  lbu   $t5, 2($s1)
  lbu   $t2, 3($s1)
  lbu   $t9, 4($s1)
  sll   $t3, $t5, 0x18
  sll   $t4, $t2, 0x10
  lbu   $t6, 5($s1)
  or    $t8, $t3, $t4
  sll   $t7, $t9, 8
  or    $t1, $t8, $t7
  lbu   $a0, 1($s1)
  jal   get_handle_to_tagged_object
   or    $s0, $t1, $t6
  beqz  $v0, .L7F03858C
   addiu $s2, $s2, 6
  lw    $t5, 0x10($v0)
  beqz  $t5, .L7F03858C
   nop   
  lw    $t2, 0xc($v0)
  or    $t3, $t2, $s0
  sw    $t3, 0xc($v0)
.L7F03858C:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 6
actionA7_Unset_16_Object_States_More_6:
  lbu   $t4, 2($s1)
  lbu   $t8, 3($s1)
  lbu   $t6, 4($s1)
  sll   $t9, $t4, 0x18
  sll   $t7, $t8, 0x10
  lbu   $t3, 5($s1)
  or    $t1, $t9, $t7
  sll   $t5, $t6, 8
  or    $t2, $t1, $t5
  lbu   $a0, 1($s1)
  jal   get_handle_to_tagged_object
   or    $s0, $t2, $t3
  beqz  $v0, .L7F0385E8
   addiu $s2, $s2, 6
  lw    $t4, 0x10($v0)
  beqz  $t4, .L7F0385E8
   nop   
  lw    $t8, 0xc($v0)
  not   $t9, $s0
  and   $t7, $t8, $t9
  sw    $t7, 0xc($v0)
.L7F0385E8:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 6
actionA8_Check_16_Object_States_More_If_Same_RVL_7:
  lbu   $t6, 2($s1)
  lbu   $t5, 3($s1)
  lbu   $t4, 4($s1)
  sll   $t1, $t6, 0x18
  sll   $t2, $t5, 0x10
  lbu   $t7, 5($s1)
  or    $t3, $t1, $t2
  sll   $t8, $t4, 8
  or    $t9, $t3, $t8
  lbu   $a0, 1($s1)
  jal   get_handle_to_tagged_object
   or    $s0, $t9, $t7
  beql  $v0, $zero, .L7F038664
   addiu $s2, $s2, 7
  lw    $t6, 0x10($v0)
  beql  $t6, $zero, .L7F038664
   addiu $s2, $s2, 7
  lw    $t5, 0xc($v0)
  move  $a0, $s6
  move  $a1, $s2
  and   $t1, $t5, $s0
  bnel  $s0, $t1, .L7F038664
   addiu $s2, $s2, 7
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 6($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 7
.L7F038664:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 7
actionA9_Sets_To_Guard_ID_Fc_Current_Guard_2:
  move  $a0, $s7
  jal   sub_GAME_7F033CF4
   lbu   $a1, 1($s1)
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
actionAA_Sets_FC_Value_For_Guard_ID_To_Guard_ID_3:
  move  $a0, $s7
  lbu   $a1, 1($s1)
  jal   sub_GAME_7F033D1C
   lbu   $a2, 2($s1)
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
actionAB_Set_Current_Guards_2328_Value_To_Preset_3:
  lbu   $t2, 1($s1)
  lbu   $t3, 2($s1)
  lw    $t9, 0x7ac($sp)
  sll   $t4, $t2, 8
  or    $v0, $t4, $t3
  andi  $t8, $v0, 0xffff
  beqz  $s7, .L7F0386D8
   move  $v0, $t8
  move  $a0, $s7
  jal   sub_GAME_7F033D5C
   move  $a1, $t8
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
.L7F0386D8:
  beqz  $t9, .L7F0386E4
   addiu $s2, $s2, 3
  sh    $v0, 6($t9)
.L7F0386E4:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
actionAC_Set_Guard_ID_numS_2328_Value_To_Preset_4:
  lbu   $t7, 2($s1)
  lbu   $t5, 3($s1)
  move  $a0, $s7
  sll   $t6, $t7, 8
  or    $v0, $t6, $t5
  andi  $a2, $v0, 0xffff
  jal   sub_GAME_7F033D84
   lbu   $a1, 1($s1)
  addiu $s2, $s2, 4
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
actionAD_Debug_Comment_20:
  move  $a0, $s6
  jal   get_length_of_action_block
   move  $a1, $s2
  addu  $s2, $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $s2
actionAE_Reset_Cycle_Counter_And_Enable_It_1:
  jal   reset_and_start_loop_counter
   move  $a0, $s7
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionAF_Reset_Cycle_Counter_1:
  sw    $zero, 0x110($s7)
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionB0_Disable_Cycle_Counter_1:
  lhu   $t2, 0x12($s7)
  addiu $s2, $s2, 1
  addiu $s1, $s1, 1
  andi  $t4, $t2, 0xffbf
  b     GetByteS1_ParseCommandByte_SwitchCase
   sh    $t4, 0x12($s7)
actionB1_Enable_Cycle_Counter_1:
  lhu   $t3, 0x12($s7)
  addiu $s2, $s2, 1
  addiu $s1, $s1, 1
  ori   $t8, $t3, 0x40
  b     GetByteS1_ParseCommandByte_SwitchCase
   sh    $t8, 0x12($s7)
actionB2_Check_Cycle_Counter_Enable_Status_2:
  lhu   $t9, 0x12($s7)
  move  $a0, $s6
  move  $a1, $s2
  andi  $t7, $t9, 0x40
  bnezl $t7, .L7F0387B4
   addiu $s2, $s2, 2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 2
.L7F0387B4:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
actionB3_If_Cycle_Counter_LTV_RVL_5:
  lbu   $t6, 1($s1)
  lbu   $t1, 2($s1)
  lbu   $t3, 3($s1)
  sll   $t5, $t6, 0x10
  sll   $t2, $t1, 8
  or    $t4, $t5, $t2
  or    $t8, $t4, $t3
  mtc1  $t8, $f10
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $t8, .L7F0387F4
   cvt.s.w $f18, $f10
  mtc1  $at, $f6
  nop   
  add.s $f18, $f18, $f6
.L7F0387F4:
  div.s $f16, $f18, $f22
  move  $a0, $s7
  jal   get_loop_counter_time_in_seconds
   swc1  $f16, 0x2b0($sp)
  lwc1  $f8, 0x2b0($sp)
  move  $a0, $s6
  move  $a1, $s2
  c.lt.s $f0, $f8
  nop   
  bc1fl .L7F038838
   addiu $s2, $s2, 5
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 4($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 5
.L7F038838:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 5
actionB4_If_Cycle_Counter_GTV_RVL_5:
  lbu   $t9, 1($s1)
  lbu   $t6, 2($s1)
  lbu   $t2, 3($s1)
  sll   $t7, $t9, 0x10
  sll   $t1, $t6, 8
  or    $t5, $t7, $t1
  or    $t4, $t5, $t2
  mtc1  $t4, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $t4, .L7F038878
   cvt.s.w $f10, $f4
  mtc1  $at, $f6
  nop   
  add.s $f10, $f10, $f6
.L7F038878:
  div.s $f18, $f10, $f22
  move  $a0, $s7
  jal   get_loop_counter_time_in_seconds
   swc1  $f18, 0x2a8($sp)
  lwc1  $f16, 0x2a8($sp)
  move  $a0, $s6
  move  $a1, $s2
  c.lt.s $f16, $f0
  nop   
  bc1fl .L7F0388BC
   addiu $s2, $s2, 5
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 4($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 5
.L7F0388BC:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 5
actionB5_Show_Timer_1:
  li    $a0, 1
  jal   set_unset_clock_lock_bits
   li    $a1, 1
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionB6_Hide_Timer_Silent_Countdown_1:
  li    $a0, 1
  jal   set_unset_clock_lock_bits
   move  $a1, $zero
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionB7_Set_Timer_X_Seconds__Doesnt_Show_Timer_Yet_3:
  lbu   $t3, 1($s1)
  lbu   $t9, 2($s1)
  sll   $t8, $t3, 8
  or    $t6, $t8, $t9
  mtc1  $t6, $f8
  nop   
  cvt.s.w $f0, $f8
  mul.s $f12, $f0, $f22
  jal   set_clock_time
   nop   
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
actionB8_Stop_Timer_1:
  jal   set_clock_enable
   move  $a0, $zero
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionB9_Start_Timer_1:
  jal   set_clock_enable
   li    $a0, 1
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionBA_Check_Timer_Enabled_Status_RVL_If_Enabled_2:
  jal   get_clock_enable
   nop   
  bnez  $v0, .L7F038978
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F038978:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
actionBB_Detect_If_Timer_Below_Certain_Point_RVL_If_So_4:
  lbu   $t7, 1($s1)
  lbu   $t5, 2($s1)
  sll   $t1, $t7, 8
  or    $t2, $t1, $t5
  mtc1  $t2, $f4
  nop   
  cvt.s.w $f6, $f4
  jal   get_clock_time
   swc1  $f6, 0x294($sp)
  lwc1  $f10, 0x294($sp)
  move  $a0, $s6
  move  $a1, $s2
  mul.s $f18, $f10, $f22
  c.lt.s $f0, $f18
  nop   
  bc1fl .L7F0389E0
   addiu $s2, $s2, 4
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 3($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 4
.L7F0389E0:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
actionBC_Detect_If_Timer_Above_Certain_Point_RVL_If_So_4:
  lbu   $t4, 1($s1)
  lbu   $t8, 2($s1)
  sll   $t3, $t4, 8
  or    $t9, $t3, $t8
  mtc1  $t9, $f16
  nop   
  cvt.s.w $f8, $f16
  jal   get_clock_time
   swc1  $f8, 0x28c($sp)
  lwc1  $f4, 0x28c($sp)
  move  $a0, $s6
  move  $a1, $s2
  mul.s $f6, $f4, $f22
  c.lt.s $f6, $f0
  nop   
  bc1fl .L7F038A44
   addiu $s2, $s2, 4
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 3($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 4
.L7F038A44:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
actionBD_Spawn_Guard_C:
  lbu   $t6, 3($s1)
  lbu   $t1, 4($s1)
  lbu   $t2, 7($s1)
  sll   $t7, $t6, 8
  lbu   $t3, 8($s1)
  or    $s0, $t7, $t1
  lbu   $t6, 9($s1)
  andi  $t5, $s0, 0xffff
  move  $s0, $t5
  lbu   $t5, 0xa($s1)
  sll   $t4, $t2, 0x18
  sll   $t8, $t3, 0x10
  or    $t9, $t4, $t8
  sll   $t7, $t6, 8
  or    $t1, $t9, $t7
  or    $t2, $t1, $t5
  sw    $t2, 0x280($sp)
  lbu   $t3, 5($s1)
  lbu   $t8, 6($s1)
  sll   $t4, $t3, 8
  or    $v0, $t4, $t8
  jal   LoadNext_PrevActionBlock
   andi  $a0, $v0, 0xffff
  lw    $t9, 0x280($sp)
  lbu   $a1, 1($s1)
  lb    $a2, 2($s1)
  sw    $v0, 0x10($sp)
  move  $a0, $s7
  move  $a3, $s0
  jal   guard_constructor_BD
   sw    $t9, 0x14($sp)
  beqz  $v0, .L7F038AE8
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 0xb($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F038AE8:
  addiu $s2, $s2, 0xc
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 0xc
actionBE_Respawn_Guard_with_ID_B:
  lbu   $t7, 6($s1)
  lbu   $t5, 7($s1)
  lbu   $t4, 8($s1)
  sll   $t1, $t7, 0x18
  sll   $t2, $t5, 0x10
  lbu   $t7, 4($s1)
  or    $t3, $t1, $t2
  lbu   $t1, 5($s1)
  lbu   $t9, 9($s1)
  sll   $t8, $t4, 8
  sll   $t5, $t7, 8
  or    $t6, $t3, $t8
  or    $v0, $t5, $t1
  andi  $a0, $v0, 0xffff
  jal   LoadNext_PrevActionBlock
   or    $s0, $t6, $t9
  lbu   $a1, 1($s1)
  lb    $a2, 2($s1)
  lbu   $a3, 3($s1)
  sw    $s0, 0x14($sp)
  sw    $v0, 0x10($sp)
  jal   guard_constructor_BE
   move  $a0, $s7
  beqz  $v0, .L7F038B70
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 0xa($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F038B70:
  addiu $s2, $s2, 0xb
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 0xb
actionBF_Spawn_Weapon_9:
  lbu   $t4, 4($s1)
  lbu   $t8, 5($s1)
  lbu   $t7, 6($s1)
  sll   $t3, $t4, 0x18
  lbu   $t4, 1($s1)
  sll   $t6, $t8, 0x10
  or    $t9, $t3, $t6
  lbu   $t2, 7($s1)
  lbu   $t3, 2($s1)
  sll   $t5, $t7, 8
  or    $t1, $t9, $t5
  sll   $t8, $t4, 8
  move  $v1, $zero
  or    $s0, $t1, $t2
  beqz  $s7, .L7F038C54
   or    $s3, $t8, $t3
  lw    $t6, 0x18($s7)
  beqz  $t6, .L7F038C54
   nop   
  lw    $t7, 0x1c($s7)
  beqz  $t7, .L7F038C54
   nop   
  jal   cheatCheckIfOn
   li    $a0, 28
  beql  $v0, $zero, .L7F038C40
   move  $a0, $s7
  lbu   $a2, 3($s1)
  addiu $t9, $a2, -2
  sltiu $at, $t9, 0x1e
  beqz  $at, .L7F038C24
   sll   $t9, $t9, 2
  lui   $at, %hi(jpt_800528FC)
  addu  $at, $at, $t9
  lw    $t9, %lo(jpt_800528FC)($at)
.L7F038C04:
  jr    $t9
   nop   
loc_CODE_7F038C0C:
  move  $a0, $s7
  li    $a1, 211
  li    $a2, 25
  jal   actor_draws_weapon_with_model
   move  $a3, $s0
  lbu   $a2, 3($s1)
.L7F038C24:
  move  $a0, $s7
  move  $a1, $s3
  jal   actor_draws_weapon_with_model
   move  $a3, $s0
  b     .L7F038C54
   move  $v1, $v0
  move  $a0, $s7
.L7F038C40:
  move  $a1, $s3
  lbu   $a2, 3($s1)
  jal   actor_draws_weapon_with_model
   move  $a3, $s0
  move  $v1, $v0
.L7F038C54:
  beqz  $v1, .L7F038C74
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 8($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F038C74:
  addiu $s2, $s2, 9
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 9
actionC0_Spawn_Hat_8:
  lbu   $t5, 3($s1)
  lbu   $t2, 4($s1)
  lbu   $t3, 5($s1)
  sll   $t1, $t5, 0x18
  lbu   $t5, 1($s1)
  sll   $t4, $t2, 0x10
  or    $t8, $t1, $t4
  lbu   $t9, 6($s1)
  lbu   $t1, 2($s1)
  sll   $t6, $t3, 8
  or    $t7, $t8, $t6
  sll   $t2, $t5, 8
  move  $v1, $zero
  or    $a2, $t7, $t9
  beqz  $s7, .L7F038CE4
   or    $a1, $t2, $t1
  lw    $t4, 0x18($s7)
  beqz  $t4, .L7F038CE4
   nop   
  lw    $t3, 0x1c($s7)
  beqz  $t3, .L7F038CE4
   nop   
  jal   sub_GAME_7F0510C0
   move  $a0, $s7
  move  $v1, $v0
.L7F038CE4:
  beqz  $v1, .L7F038D04
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 7($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F038D04:
  addiu $s2, $s2, 8
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 8
actionC1_GuardIDDoesAV_If_Gunfire_RVL_WhenComplete_5:
  lbu   $t8, 2($s1)
  lbu   $t7, 3($s1)
  sw    $zero, 0x20c($sp)
  sll   $t6, $t8, 8
  or    $v0, $t6, $t7
  andi  $a0, $v0, 0xffff
  sw    $zero, 0x210($sp)
  sw    $zero, 0x234($sp)
  move  $s3, $zero
  jal   LoadNext_PrevActionBlock
   move  $s4, $zero
  move  $s0, $v0
  move  $a0, $s7
  jal   get_handle_for_guard_id
   lbu   $a1, 1($s1)
  beqz  $v0, .L7F038E94
   move  $s5, $v0
  lw    $t5, 0x14($v0)
  move  $a0, $s7
  andi  $t2, $t5, 2
  beql  $t2, $zero, .L7F038E98
   lw    $t1, 0x234($sp)
  lb    $a1, 0xf($v0)
  lh    $a3, ($v0)
  sw    $zero, 0x14($sp)
  sw    $s0, 0x10($sp)
  jal   guard_constructor_BE
   li    $a2, -1
  beql  $v0, $zero, .L7F038E98
   lw    $t1, 0x234($sp)
  lw    $t1, 4($v0)
  move  $a0, $s7
  sw    $t1, 0x218($sp)
  lh    $s0, ($s5)
  addiu $s0, $s0, 0x2710
  jal   get_handle_for_guard_id
   move  $a1, $s0
  bnez  $v0, .L7F038DB4
   move  $a0, $s5
  lw    $t4, 0x218($sp)
  sh    $s0, ($t4)
.L7F038DB4:
  jal   something_with_weaponpos_of_guarddata_hand
   move  $a1, $zero
  beql  $v0, $zero, .L7F038DF0
   move  $a0, $s5
  lw    $s4, 4($v0)
  lw    $a0, 0x218($sp)
  move  $a3, $zero
  lh    $a1, 4($s4)
  jal   actor_draws_weapon_with_model
   lb    $a2, 0x80($s4)
  beql  $v0, $zero, .L7F038DF0
   move  $a0, $s5
  lw    $t3, 4($v0)
  sw    $t3, 0x20c($sp)
  move  $a0, $s5
.L7F038DF0:
  jal   something_with_weaponpos_of_guarddata_hand
   li    $a1, 1
  beqz  $v0, .L7F038E28
   nop   
  lw    $s3, 4($v0)
  lw    $a0, 0x218($sp)
  lui   $a3, 0x1000
  lh    $a1, 4($s3)
  jal   actor_draws_weapon_with_model
   lb    $a2, 0x80($s3)
  beqz  $v0, .L7F038E28
   nop   
  lw    $t8, 4($v0)
  sw    $t8, 0x210($sp)
.L7F038E28:
  beql  $s3, $zero, .L7F038E70
   lw    $v1, 0x1d8($s5)
  beqz  $s4, .L7F038E6C
   lw    $t6, 0x210($sp)
  beqz  $t6, .L7F038E6C
   lw    $t7, 0x20c($sp)
  beql  $t7, $zero, .L7F038E70
   lw    $v1, 0x1d8($s5)
  lw    $t9, 0x84($s3)
  bnel  $s4, $t9, .L7F038E70
   lw    $v1, 0x1d8($s5)
  lw    $t5, 0x84($s4)
  move  $a0, $t6
  bnel  $s3, $t5, .L7F038E70
   lw    $v1, 0x1d8($s5)
  jal   link_objects
   move  $a1, $t7
.L7F038E6C:
  lw    $v1, 0x1d8($s5)
.L7F038E70:
  lw    $a0, 0x218($sp)
  beql  $v1, $zero, .L7F038E90
   li    $t2, 1
  lw    $v0, 4($v1)
  move  $a2, $zero
  jal   sub_GAME_7F0510C0
   lh    $a1, 4($v0)
  li    $t2, 1
.L7F038E90:
  sw    $t2, 0x234($sp)
.L7F038E94:
  lw    $t1, 0x234($sp)
.L7F038E98:
  move  $a0, $s6
  move  $a1, $s2
  beql  $t1, $zero, .L7F038EC0
   addiu $s2, $s2, 5
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 4($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 5
.L7F038EC0:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 5
actionC2_Display_Text_Preset_Bottom_Screen_3:
  lbu   $t4, 1($s1)
  lbu   $t8, 2($s1)
  sll   $t3, $t4, 8
  jal   get_textptr_for_textID
   or    $a0, $t3, $t8
  jal   display_string_in_lower_left_corner
   move  $a0, $v0
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
actionC3_Display_Text_Preset_Top_Screen_3:
  lbu   $t9, 1($s1)
  lbu   $t6, 2($s1)
  sll   $t5, $t9, 8
  jal   get_textptr_for_textID
   or    $a0, $t5, $t6
  jal   display_string_at_top_of_screen
   move  $a0, $v0
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
actionC4_Play_Sound_Effect_num_In_Slot_num_0_7_4:
  lbu   $t7, 1($s1)
  lbu   $t1, 2($s1)
  lb    $a0, 3($s1)
  sll   $t2, $t7, 8
  or    $a1, $t2, $t1
  sll   $t4, $a1, 0x10
  jal   set_sound_effect_to_slot
   sra   $a1, $t4, 0x10
  addiu $s2, $s2, 4
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
actionC9_Shut_Off_Sound_In_Slot_Number_2:
  jal   sub_GAME_7F0349BC
   lb    $a0, 1($s1)
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
actionC7_Sound_In_Slot_num_Crecendos_To_Volume_Over_ms_6:
  lbu   $t8, 2($s1)
  lbu   $t5, 3($s1)
  lbu   $t2, 4($s1)
  lbu   $t4, 5($s1)
  lb    $v1, 1($s1)
  sll   $t9, $t8, 8
  or    $a0, $t9, $t5
  sll   $t1, $t2, 8
  sll   $t6, $a0, 0x10
  or    $a1, $t1, $t4
  sra   $a0, $t6, 0x10
  bltz  $v1, .L7F038FFC
   andi  $t3, $a1, 0xffff
  slti  $at, $v1, 8
  beqz  $at, .L7F038FFC
   li    $a3, 24
  multu $v1, $a3
  lui   $a2, %hi(sound_effects)
  addiu $a2, %lo(sound_effects) # addiu $a2, $a2, -0x6490
  move  $v0, $t3
  mflo  $t8
  addu  $t9, $a2, $t8
  sw    $t3, 8($t9)
  lb    $t5, 1($s1)
  multu $t5, $a3
  mflo  $t6
  addu  $t7, $a2, $t6
  sw    $a0, 0xc($t7)
  lb    $t2, 1($s1)
  multu $t2, $a3
  mflo  $t1
  addu  $t4, $a2, $t1
  sw    $zero, 0x10($t4)
  lb    $t3, 1($s1)
  multu $t3, $a3
  mflo  $t8
  addu  $t9, $a2, $t8
  bnez  $v0, .L7F038FFC
   sw    $zero, 0x14($t9)
  jal   set_sound_effect_source_to_location
   lb    $a0, 1($s1)
.L7F038FFC:
  addiu $s2, $s2, 6
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 6
actionC8_Sound_In_Slot_num_Fades_To_Volume_Over_ms_6:
  lbu   $t5, 2($s1)
  lbu   $t7, 3($s1)
  lbu   $t1, 4($s1)
  lbu   $t3, 5($s1)
  sll   $t6, $t5, 8
  lb    $v1, 1($s1)
  or    $t2, $t6, $t7
  mtc1  $t2, $f10
  sll   $t4, $t1, 8
  or    $v0, $t4, $t3
  andi  $t8, $v0, 0xffff
  bltz  $v1, .L7F0390B8
   cvt.s.w $f12, $f10
  slti  $at, $v1, 8
  beqz  $at, .L7F0390B8
   sll   $t9, $v1, 2
  subu  $t9, $t9, $v1
  sll   $t9, $t9, 3
  lui   $at, %hi(sound_effects+8)
  addu  $at, $at, $t9
  sw    $t8, %lo(sound_effects+8)($at)
  jal   sub_GAME_7F0539B8
   move  $s0, $t8
  lb    $t5, 1($s1)
  li    $a0, 24
  lui   $v1, %hi(sound_effects)
  multu $t5, $a0
  addiu $v1, %lo(sound_effects) # addiu $v1, $v1, -0x6490
  mflo  $t6
  addu  $t7, $v1, $t6
  sw    $v0, 0xc($t7)
  lb    $t2, 1($s1)
  multu $t2, $a0
  mflo  $t1
  addu  $t4, $v1, $t1
  sw    $zero, 0x10($t4)
  lb    $t3, 1($s1)
  multu $t3, $a0
  mflo  $t8
  addu  $t9, $v1, $t8
  bnez  $s0, .L7F0390B8
   sw    $zero, 0x14($t9)
  jal   set_sound_effect_source_to_location
   lb    $a0, 1($s1)
.L7F0390B8:
  addiu $s2, $s2, 6
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 6
actionC5_EmanateSoundSlotnumFrom16ObjectWithAudibleRV_5:
  jal   get_handle_to_tagged_object
   lbu   $a0, 2($s1)
  lbu   $t5, 3($s1)
  lbu   $t7, 4($s1)
  lb    $v1, 1($s1)
  sll   $t6, $t5, 8
  or    $a1, $t6, $t7
  bltz  $v1, .L7F039154
   andi  $t2, $a1, 0xffff
  slti  $at, $v1, 8
  beql  $at, $zero, .L7F039158
   addiu $s2, $s2, 5
  beqz  $v0, .L7F039154
   sll   $t1, $v1, 2
  subu  $t1, $t1, $v1
  sll   $t1, $t1, 3
  lui   $at, %hi(sound_effects+8)
  addu  $at, $at, $t1
  sw    $t2, %lo(sound_effects+8)($at)
  lb    $t4, 1($s1)
  lui   $at, %hi(sound_effects+16)
  sll   $t3, $t4, 2
  subu  $t3, $t3, $t4
  sll   $t3, $t3, 3
  addu  $at, $at, $t3
  sw    $zero, %lo(sound_effects+16)($at)
  lb    $t8, 1($s1)
  lui   $at, %hi(sound_effects+20)
  sll   $t9, $t8, 2
  subu  $t9, $t9, $t8
  sll   $t9, $t9, 3
  addu  $at, $at, $t9
  bnez  $t2, .L7F039154
   sw    $v0, %lo(sound_effects+20)($at)
  jal   set_sound_effect_source_to_location
   lb    $a0, 1($s1)
.L7F039154:
  addiu $s2, $s2, 5
.L7F039158:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 5
actionC6_EmanateSoundSlotnumFromPresetWithAudibleRV_6:
  lbu   $t5, 2($s1)
  lbu   $t7, 3($s1)
  lbu   $t1, 4($s1)
  lbu   $t3, 5($s1)
  sll   $t6, $t5, 8
  or    $v0, $t6, $t7
  sll   $t4, $t1, 8
  andi  $t2, $v0, 0xffff
  or    $a1, $t4, $t3
  andi  $t8, $a1, 0xffff
  slti  $at, $t2, 0x2710
  move  $a1, $t8
  beqz  $at, .L7F0391BC
   move  $v1, $t2
  sll   $t9, $t2, 2
  subu  $t9, $t9, $t2
  sll   $t9, $t9, 2
  lui   $t5, %hi(ptr_0xxxpresets) 
  lw    $t5, %lo(ptr_0xxxpresets)($t5)
  subu  $t9, $t9, $t2
  sll   $t9, $t9, 2
  b     .L7F0391E0
   addu  $a0, $t9, $t5
.L7F0391BC:
  lui   $t7, %hi(ptr_2xxxpresets) 
  lw    $t7, %lo(ptr_2xxxpresets)($t7)
  sll   $t6, $v1, 4
  addu  $t6, $t6, $v1
  sll   $t6, $t6, 2
  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
  addu  $a0, $t6, $t7
  addu  $a0, $a0, $at
.L7F0391E0:
  lb    $v1, 1($s1)
  bltz  $v1, .L7F039254
   slti  $at, $v1, 8
  beql  $at, $zero, .L7F039258
   addiu $s2, $s2, 6
  beqz  $a0, .L7F039254
   sll   $t2, $v1, 2
  subu  $t2, $t2, $v1
  sll   $t2, $t2, 3
  lui   $at, %hi(sound_effects+8)
  addu  $at, $at, $t2
  sw    $a1, %lo(sound_effects+8)($at)
  lb    $t1, 1($s1)
  lui   $at, %hi(sound_effects+16)
  sll   $t4, $t1, 2
  subu  $t4, $t4, $t1
  sll   $t4, $t4, 3
  addu  $at, $at, $t4
  sw    $a0, %lo(sound_effects+16)($at)
  lb    $t3, 1($s1)
  lui   $at, %hi(sound_effects+20)
  sll   $t8, $t3, 2
  subu  $t8, $t8, $t3
  sll   $t8, $t8, 3
  addu  $at, $at, $t8
  bnez  $a1, .L7F039254
   sw    $zero, %lo(sound_effects+20)($at)
  jal   set_sound_effect_source_to_location
   lb    $a0, 1($s1)
.L7F039254:
  addiu $s2, $s2, 6
.L7F039258:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 6
actionCA_If_Value_GreaterThan_Volume_7FFF_Max_RVL_5:
  lbu   $t9, 2($s1)
  lbu   $t6, 3($s1)
  lb    $v1, 1($s1)
  sll   $t5, $t9, 8
  or    $v0, $t5, $t6
  sll   $t7, $v0, 0x10
  bltz  $v1, .L7F0392C8
   sra   $t2, $t7, 0x10
  slti  $at, $v1, 8
  beqz  $at, .L7F0392C8
   sll   $t1, $v1, 2
  subu  $t1, $t1, $v1
  sll   $t1, $t1, 3
  lui   $t4, %hi(sound_effects+4)
  addu  $t4, $t4, $t1
  lw    $t4, %lo(sound_effects+4)($t4)
  move  $a0, $s6
  move  $a1, $s2
  slt   $at, $t4, $t2
  beql  $at, $zero, .L7F0392CC
   addiu $s2, $s2, 5
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 4($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F0392C8:
  addiu $s2, $s2, 5
.L7F0392CC:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 5
actionCB_Set_Object_Path_27_Type_Object_2:
  jal   get_ptr_path_for_pathnum
   lbu   $a0, 1($s1)
  lw    $t3, 0x7b0($sp)
  addiu $s2, $s2, 2
  beqz  $t3, .L7F0392F4
   nop   
  sw    $v0, 0xa4($t3)
  sw    $zero, 0xa8($t3)
.L7F0392F4:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
actionCC_Set_Speed_Moving_Vehicle_27_Type_Object_5:
  lbu   $t7, 1($s1)
  lbu   $t1, 2($s1)
  li    $at, 0x42C80000 # 100.000000
  sll   $t2, $t7, 8
  or    $t4, $t2, $t1
  mtc1  $t4, $f16
  mtc1  $at, $f4
  lbu   $t8, 3($s1)
  cvt.s.w $f8, $f16
  lbu   $t5, 4($s1)
  sll   $t9, $t8, 8
  lw    $t3, 0x7b0($sp)
  li    $at, 0x46700000 # 15360.000000
  or    $t6, $t9, $t5
  mul.s $f6, $f8, $f4
  mtc1  $t6, $f18
  mtc1  $at, $f10
  addiu $s2, $s2, 5
  cvt.s.w $f0, $f18
  beqz  $t3, .L7F039358
   div.s $f2, $f6, $f10
  swc1  $f2, 0x94($t3)
  swc1  $f0, 0x98($t3)
.L7F039358:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 5
actionCD_Set_Speed_Aircraft_Rotor_5:
  lbu   $t7, 1($s1)
  lbu   $t1, 2($s1)
  lbu   $t8, 3($s1)
  sll   $t2, $t7, 8
  or    $t4, $t2, $t1
  mtc1  $t4, $f16
  lbu   $t5, 4($s1)
  sll   $t9, $t8, 8
  cvt.s.w $f8, $f16
  lw    $t3, 0x7ac($sp)
  li    $at, 0x45610000 # 3600.000000
  or    $t6, $t9, $t5
  mtc1  $t6, $f18
  mtc1  $at, $f6
  mul.s $f4, $f8, $f26
  addiu $s2, $s2, 5
  cvt.s.w $f0, $f18
  beqz  $t3, .L7F0393B4
   div.s $f2, $f4, $f6
  swc1  $f2, 0x90($t3)
  swc1  $f0, 0x94($t3)
.L7F0393B4:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 5
actionCE_Detect_If_Currently_In_Intro_Camera_RVL_If_So_2:
  jal   get_camera_mode
   nop   
  li    $at, 1
  beql  $v0, $at, .L7F0393E4
   move  $a0, $s6
  jal   get_camera_mode
   nop   
  li    $at, 2
  bne   $v0, $at, .L7F0393FC
   move  $a0, $s6
.L7F0393E4:
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F0393FC:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
actionCF_Detect_If_Currently_In_Intro_Swirl_RVL_If_So_2:
  jal   get_camera_mode
   nop   
  li    $at, 3
  bne   $v0, $at, .L7F039434
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F039434:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
actionD0_Change_Animation_Type_Of_Type_16_Monitor_4:
  jal   get_handle_to_tagged_object
   lbu   $a0, 1($s1)
  beqz  $v0, .L7F0394C0
   move  $a2, $v0
  lw    $t8, 0x10($v0)
  beql  $t8, $zero, .L7F0394C4
   addiu $s2, $s2, 4
  lbu   $v1, 3($v0)
  li    $at, 10
  addiu $a0, $v0, 0x80
  bnel  $v1, $at, .L7F039488
   li    $at, 11
  jal   set_ptr_monitor_img_to_obj_ani_slot
   lbu   $a1, 3($s1)
  addiu $s2, $s2, 4
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
  li    $at, 11
.L7F039488:
  bnel  $v1, $at, .L7F0394C4
   addiu $s2, $s2, 4
  lbu   $v0, 2($s1)
  slti  $at, $v0, 4
  beqz  $at, .L7F0394C0
   sll   $t9, $v0, 3
  subu  $t9, $t9, $v0
  sll   $t9, $t9, 2
  addu  $t9, $t9, $v0
  sll   $t9, $t9, 2
  addu  $a0, $a2, $t9
  addiu $a0, $a0, 0x80
  jal   set_ptr_monitor_img_to_obj_ani_slot
   lbu   $a1, 3($s1)
.L7F0394C0:
  addiu $s2, $s2, 4
.L7F0394C4:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
actionD1_If_Bond_In_Tank_RVL_2:
  jal   get_intank_flag
   nop   
  li    $at, 1
  bne   $v0, $at, .L7F0394F8
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F0394F8:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
actionD2_Exit_Level_1:
  lui   $t5, %hi(camera_8003642C) 
  lw    $t5, %lo(camera_8003642C)($t5)
  lui   $t6, %hi(camera_80036434) 
  beqz  $t5, .L7F03953C
   nop   
  lw    $t6, %lo(camera_80036434)($t6)
  li    $t7, 1
  lui   $at, %hi(camera_80036434)
  bnezl $t6, .L7F039548
   addiu $s2, $s2, 1
  sw    $t7, %lo(camera_80036434)($at)
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
.L7F03953C:
  jal   return_to_title_from_level_end
   nop   
  addiu $s2, $s2, 1
.L7F039548:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionD3_Return_From_Camera_Scene_1:
  jal   set_camera_mode
   li    $a0, 8
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionD4_Camera_Looks_At_Bond_From_Preset_3:
  lbu   $t2, 1($s1)
  lbu   $t4, 2($s1)
  lui   $t7, %hi(ptr_2xxxpresets) 
  sll   $t1, $t2, 8
  or    $v0, $t1, $t4
  andi  $t3, $v0, 0xffff
  slti  $at, $t3, 0x2710
  beqz  $at, .L7F0395B4
   move  $v1, $t3
  sll   $t8, $t3, 2
  subu  $t8, $t8, $t3
  lui   $t9, %hi(ptr_0xxxpresets) 
  lw    $t9, %lo(ptr_0xxxpresets)($t9)
  sll   $t8, $t8, 2
  subu  $t8, $t8, $t3
  sll   $t8, $t8, 2
  lui   $at, %hi(dword_CODE_bss_800799F8)
  addu  $t5, $t8, $t9
  b     .L7F0395DC
   sw    $t5, %lo(dword_CODE_bss_800799F8)($at)
.L7F0395B4:
  lw    $t7, %lo(ptr_2xxxpresets)($t7)
  sll   $t6, $v1, 4
  addu  $t6, $t6, $v1
  sll   $t6, $t6, 2
  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
  addu  $t2, $t6, $t7
  addu  $t1, $t2, $at
  lui   $at, %hi(dword_CODE_bss_800799F8)
  sw    $t1, %lo(dword_CODE_bss_800799F8)($at)
.L7F0395DC:
  jal   set_camera_mode
   li    $a0, 7
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
actionD5_Go_To_Camera_Position_6:
  jal   sub_GAME_7F057080
   lbu   $a0, 1($s1)
  beqz  $v0, .L7F039664
   move  $s0, $v0
  jal   check_if_object_type_has_been_loaded
   move  $a0, $v0
  bltzl $v0, .L7F039668
   addiu $s2, $s2, 6
  lh    $t4, 6($s0)
  jal   sub_GAME_7F056A88
   addu  $a0, $t4, $v0
  lui   $at, %hi(dword_CODE_bss_800799F8)
  sw    $zero, %lo(dword_CODE_bss_800799F8)($at)
  lui   $at, %hi(dword_CODE_bss_800799FC)
  sw    $v0, %lo(dword_CODE_bss_800799FC)($at)
  lbu   $t3, 2($s1)
  lbu   $t9, 3($s1)
  lui   $at, %hi(dword_CODE_bss_80079A18)
  sll   $t8, $t3, 8
  or    $t5, $t8, $t9
  sw    $t5, %lo(dword_CODE_bss_80079A18)($at)
  lbu   $t6, 4($s1)
  lbu   $t2, 5($s1)
  lui   $at, %hi(dword_CODE_bss_80079A1C)
  sll   $t7, $t6, 8
  or    $t1, $t7, $t2
  sw    $t1, %lo(dword_CODE_bss_80079A1C)($at)
  jal   set_camera_mode
   li    $a0, 7
.L7F039664:
  addiu $s2, $s2, 6
.L7F039668:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 6
actionD6_If_Less_Than_Elevation_RVL_4:
  lbu   $t4, 1($s1)
  lbu   $t8, 2($s1)
  sll   $t3, $t4, 8
  or    $t9, $t3, $t8
  sll   $t5, $t9, 0x10
  sra   $t6, $t5, 0x10
  mtc1  $t6, $f10
  nop   
  cvt.s.w $f18, $f10
  jal   get_curplayer_positiondata
   swc1  $f18, 0x14c($sp)
  lwc1  $f16, 0xc($v0)
  lwc1  $f8, 0x14c($sp)
  move  $a0, $s6
  move  $a1, $s2
  c.lt.s $f16, $f8
  nop   
  bc1fl .L7F0396D4
   addiu $s2, $s2, 4
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 3($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 4
.L7F0396D4:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
actionD7_Disable_Text_Variable_2:
  li    $a0, 4
  jal   set_unset_bitflags
   move  $a1, $zero
  li    $a0, 2
  jal   set_unset_ammo_on_screen_setting
   move  $a1, $zero
  lbu   $a1, 1($s1)
  andi  $t7, $a1, 2
  bnezl $t7, .L7F039714
   andi  $t2, $a1, 1
  jal   set_flags_in_BONDdata_stationary_intro_cam
   li    $a0, 2
  lbu   $a1, 1($s1)
  andi  $t2, $a1, 1
.L7F039714:
  bnezl $t2, .L7F03972C
   andi  $t1, $a1, 4
  jal   sub_GAME_7F08A944
   li    $a0, 2
  lbu   $a1, 1($s1)
  andi  $t1, $a1, 4
.L7F03972C:
  bnez  $t1, .L7F03973C
   li    $a0, 16
  jal   set_unset_clock_lock_bits
   move  $a1, $zero
.L7F03973C:
  lui   $at, %hi(D_800364B0)
  sw    $zero, %lo(D_800364B0)($at)
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
actionD8_Enable_All_On_Screen_Displays_1:
  li    $a0, 4
  jal   set_unset_bitflags
   li    $a1, 1
  li    $a0, 2
  jal   set_unset_ammo_on_screen_setting
   li    $a1, 1
  jal   unset_flags_in_BONDdata_stationary_intro_cam
   li    $a0, 2
  jal   sub_GAME_7F08A928
   li    $a0, 2
  li    $a0, 16
  jal   set_unset_clock_lock_bits
   li    $a1, 1
  li    $t4, 1
  lui   $at, %hi(D_800364B0)
  sw    $t4, %lo(D_800364B0)($at)
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionD9_GuardIDMovedToPresetReturnLoopIfSuccessful_5:
  lbu   $t3, 2($s1)
  lbu   $t9, 3($s1)
  move  $a0, $s7
  sll   $t8, $t3, 8
  lbu   $a1, 1($s1)
  move  $s4, $zero
  jal   get_handle_for_guard_id
   or    $s3, $t8, $t9
  beqz  $v0, .L7F039938
   move  $s0, $v0
  move  $a0, $s7
  jal   sub_GAME_7F032F94
   move  $a1, $s3
  slti  $at, $v0, 0x2710
  beqz  $at, .L7F039800
   sll   $t7, $v0, 4
  sll   $t5, $v0, 2
  subu  $t5, $t5, $v0
  sll   $t5, $t5, 2
  lui   $t6, %hi(ptr_0xxxpresets) 
  lw    $t6, %lo(ptr_0xxxpresets)($t6)
  subu  $t5, $t5, $v0
  sll   $t5, $t5, 2
  b     .L7F039820
   addu  $v1, $t5, $t6
.L7F039800:
  lui   $t2, %hi(ptr_2xxxpresets) 
  lw    $t2, %lo(ptr_2xxxpresets)($t2)
  addu  $t7, $t7, $v0
  sll   $t7, $t7, 2
  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
  addu  $v1, $t7, $t2
  addu  $v1, $v1, $at
.L7F039820:
  lwc1  $f12, 0x18($v1)
  lwc1  $f14, 0x20($v1)
  jal   convert_angle_using_inverse
   sw    $v1, 0x134($sp)
  lw    $v1, 0x134($sp)
  swc1  $f0, 0x130($sp)
  move  $a1, $zero
  lwc1  $f4, ($v1)
  swc1  $f4, 0x124($sp)
  lwc1  $f6, 4($v1)
  swc1  $f6, 0x128($sp)
  lwc1  $f10, 8($v1)
  swc1  $f10, 0x12c($sp)
  lw    $t1, 0x28($v1)
  sw    $t1, 0x120($sp)
  jal   sub_GAME_7F03D058
   lw    $a0, 0x18($s0)
  addiu $a0, $sp, 0x124
  addiu $a1, $sp, 0x120
  lw    $a2, 0x130($sp)
  jal   sub_GAME_7F033F48
   li    $a3, 1
  beqz  $v0, .L7F03992C
   lwc1  $f18, 0x124($sp)
  lw    $t4, 0x18($s0)
  swc1  $f18, 8($t4)
  lw    $t3, 0x18($s0)
  lwc1  $f16, 0x128($sp)
  swc1  $f16, 0xc($t3)
  lw    $t8, 0x18($s0)
  lwc1  $f8, 0x12c($sp)
  swc1  $f8, 0x10($t8)
  lw    $t5, 0x18($s0)
  lw    $t9, 0x120($sp)
  sw    $t9, 0x14($t5)
  lw    $t6, 0x14($s0)
  lw    $a0, 0x1c($s0)
  ori   $t7, $t6, 1
  sw    $t7, 0x14($s0)
  jal   setsubroty
   lw    $a1, 0x130($sp)
  lw    $a0, 0x1c($s0)
  jal   setsuboffset
   addiu $a1, $sp, 0x124
  jal   sub_GAME_7F020D94
   move  $a0, $s0
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lw    $t1, 0x18($s0)
  lwc1  $f4, 0x124($sp)
  lw    $t2, 0xa8($v0)
  lui   $t4, %hi(pPlayer) 
  li    $s4, 1
  bne   $t2, $t1, .L7F03992C
   nop   
  swc1  $f4, 0x48c($v0)
  lw    $t4, %lo(pPlayer)($t4)
  lwc1  $f6, 0x128($sp)
  lui   $t3, %hi(pPlayer) 
  lui   $t9, %hi(pPlayer) 
  swc1  $f6, 0x490($t4)
  lw    $t3, %lo(pPlayer)($t3)
  lwc1  $f10, 0x12c($sp)
  swc1  $f10, 0x494($t3)
  lw    $t9, %lo(pPlayer)($t9)
  lw    $t8, 0x120($sp)
  sw    $t8, 0x488($t9)
.L7F03992C:
  lw    $a0, 0x18($s0)
  jal   sub_GAME_7F03D058
   li    $a1, 1
.L7F039938:
  beqz  $s4, .L7F039958
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 4($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F039958:
  addiu $s2, $s2, 5
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 5
actionDA_Fade_Out_From_Cut_Scene_1:
  lui   $t5, %hi(stop_time_flag) 
  lw    $t5, %lo(stop_time_flag)($t5)
  li    $at, 2
  move  $a0, $zero
  beq   $t5, $at, .L7F039998
   move  $a1, $zero
  mfc1  $a3, $f20
  jal   set_rgba_tint
   move  $a2, $zero
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f14
  jal   fade_to_over_seconds
   mov.s $f12, $f22
.L7F039998:
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionDB_Fade_In_From_Black_Reset_DA_1:
  lui   $t6, %hi(stop_time_flag) 
  lw    $t6, %lo(stop_time_flag)($t6)
  li    $at, 2
  move  $a0, $zero
  beq   $t6, $at, .L7F0399D4
   move  $a1, $zero
  move  $a2, $zero
  jal   set_rgba_tint
   li    $a3, 0x3F800000 # 1.000000
  mov.s $f12, $f22
  jal   fade_to_over_seconds
   mov.s $f14, $f20
.L7F0399D4:
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionDC_RVL_When_Fade_Complete_2:
  lui   $t7, %hi(pPlayer) 
  lw    $t7, %lo(pPlayer)($t7)
  move  $a0, $s6
  move  $a1, $s2
  lwc1  $f18, 0x3e4($t7)
  c.lt.s $f18, $f20
  nop   
  bc1fl .L7F039A1C
   addiu $s2, $s2, 2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 2
.L7F039A1C:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
actionDD_Remove_All_Guards_1:
  jal   get_numguards
   nop   
  addiu $v1, $v0, -1
  bltz  $v1, .L7F039A78
   addiu $s2, $s2, 1
  sll   $v0, $v1, 4
  subu  $v0, $v0, $v1
  sll   $v0, $v0, 3
  subu  $v0, $v0, $v1
  sll   $v0, $v0, 2
  lw    $t2, ($fp)
.L7F039A50:
  addu  $v1, $t2, $v0
  lw    $t1, 0x1c($v1)
  addiu $v0, $v0, -0x1dc
  beqz  $t1, .L7F039A70
   nop   
  lw    $t4, 0x14($v1)
  ori   $t3, $t4, 0x400
  sw    $t3, 0x14($v1)
.L7F039A70:
  bgezl $v0, .L7F039A50
   lw    $t2, ($fp)
.L7F039A78:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionDE_Bring_Removed_Guards_Back_1:
  jal   get_numguards
   nop   
  addiu $v1, $v0, -1
  bltz  $v1, .L7F039AC8
   move  $a0, $v1
  sll   $v1, $v1, 4
  subu  $v1, $v1, $a0
  sll   $v1, $v1, 3
  subu  $v1, $v1, $a0
  sll   $v1, $v1, 2
  li    $a0, -1025
.L7F039AAC:
  lw    $t8, ($fp)
  addu  $v0, $t8, $v1
  lw    $t9, 0x14($v0)
  addiu $v1, $v1, -0x1dc
  and   $t5, $t9, $a0
  bgez  $v1, .L7F039AAC
   sw    $t5, 0x14($v0)
.L7F039AC8:
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionDF_Open_Type_16_Door_Used_Cut_Scenes_2:
  jal   get_handle_to_tagged_object
   lbu   $a0, 1($s1)
  beqz  $v0, .L7F039B24
   move  $a0, $v0
  lw    $t6, 0x10($v0)
  beql  $t6, $zero, .L7F039B28
   addiu $s2, $s2, 2
  lwc1  $f16, 0x84($v0)
  swc1  $f20, 0xb8($v0)
  lui   $t7, %hi(global_timer) 
  swc1  $f16, 0xb4($v0)
  lw    $t7, %lo(global_timer)($t7)
  sb    $zero, 0xbc($v0)
  sw    $t7, 0xec($v0)
  jal   sub_GAME_7F052B00
   sw    $v0, 0x10c($sp)
  jal   sub_GAME_7F053598
   lw    $a0, 0x10c($sp)
  jal   sub_GAME_7F053B10
   lw    $a0, 0x10c($sp)
.L7F039B24:
  addiu $s2, $s2, 2
.L7F039B28:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
actionE0_Guard_ID_Draws_Weapon_num_3:
  move  $a0, $s7
  jal   get_handle_for_guard_id
   lbu   $a1, 1($s1)
  beqz  $v0, .L7F039B4C
   move  $a0, $v0
  jal   set_0x4_in_runtime_flags_for_item_in_guards_hand
   lbu   $a1, 2($s1)
.L7F039B4C:
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
actionE1_If_Fewer_than_This_Many_Players_Playing_RVL_3:
  jal   getPlayerCount
   nop   
  lb    $t2, 1($s1)
  move  $a0, $s6
  move  $a1, $s2
  slt   $at, $v0, $t2
  beql  $at, $zero, .L7F039B90
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F039B90:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
actionE2_If_Ammo_Value_In_Type_Is_LTV_RVL_4:
  jal   check_cur_player_ammo_amount_total
   lb    $a0, 1($s1)
  lb    $t1, 2($s1)
  move  $a0, $s6
  move  $a1, $s2
  slt   $at, $v0, $t1
  beql  $at, $zero, .L7F039BD0
   addiu $s2, $s2, 4
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 3($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 4
.L7F039BD0:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
actionE3_Draw_Weapon_From_Inventory_In_Game_2:
  move  $a0, $zero
  jal   draw_item_in_hand_has_more_ammo
   lb    $a1, 1($s1)
  li    $a0, 1
  jal   draw_item_in_hand_has_more_ammo
   move  $a1, $zero
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
actionE4_Draw_Weapon_From_Inventory_Cut_Scene_2:
  move  $a0, $zero
  jal   remove_hands_item
   lb    $a1, 1($s1)
  li    $a0, 1
  jal   remove_hands_item
   move  $a1, $zero
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
actionE5_Set_Bonds_Speed_3:
  lb    $t4, 1($s1)
  lui   $v0, %hi(flt_CODE_bss_80079990)
  addiu $v0, %lo(flt_CODE_bss_80079990) # addiu $v0, $v0, -0x6670
  mtc1  $t4, $f8
  swc1  $f20, 4($v0)
  addiu $s2, $s2, 3
  cvt.s.w $f4, $f8
  addiu $s1, $s1, 3
  swc1  $f4, ($v0)
  lb    $t3, -1($s1)
  mtc1  $t3, $f6
  nop   
  cvt.s.w $f10, $f6
  b     GetByteS1_ParseCommandByte_SwitchCase
   swc1  $f10, 8($v0)
actionE6_If_16_Object_And_Preset_Are_In_Same_Room_RVL_5:
  lbu   $t8, 2($s1)
  lbu   $t5, 3($s1)
  lbu   $a0, 1($s1)
  sll   $t9, $t8, 8
  or    $s0, $t9, $t5
  andi  $t6, $s0, 0xffff
  jal   get_handle_to_tagged_object
   move  $s0, $t6
  slti  $at, $s0, 0x2710
  beqz  $at, .L7F039CAC
   move  $v1, $s0
  sll   $t7, $v1, 2
  subu  $t7, $t7, $v1
  sll   $t7, $t7, 2
  lui   $t2, %hi(ptr_0xxxpresets) 
  lw    $t2, %lo(ptr_0xxxpresets)($t2)
  subu  $t7, $t7, $v1
  sll   $t7, $t7, 2
  b     .L7F039CD0
   addu  $a0, $t7, $t2
.L7F039CAC:
  lui   $t4, %hi(ptr_2xxxpresets) 
  lw    $t4, %lo(ptr_2xxxpresets)($t4)
  sll   $t1, $v1, 4
  addu  $t1, $t1, $v1
  sll   $t1, $t1, 2
  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
  addu  $a0, $t1, $t4
  addu  $a0, $a0, $at
.L7F039CD0:
  lw    $v1, 0x28($a0)
  beql  $v1, $zero, .L7F039D24
   addiu $s2, $s2, 5
  beql  $v0, $zero, .L7F039D24
   addiu $s2, $s2, 5
  lw    $a0, 0x10($v0)
  beql  $a0, $zero, .L7F039D24
   addiu $s2, $s2, 5
  lw    $t3, 0x14($a0)
  lbu   $t9, 3($v1)
  move  $a0, $s6
  lbu   $t8, 3($t3)
  move  $a1, $s2
  bnel  $t8, $t9, .L7F039D24
   addiu $s2, $s2, 5
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 4($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 5
.L7F039D24:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 5
actionE9_Instantly_Switch_Sky_To_Sky_2_1:
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f12
  jal   switch_to_solosky2
   nop   
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionEA_Stop_Game_Time_1:
  lui   $t5, %hi(stop_time_flag) 
  lw    $t5, %lo(stop_time_flag)($t5)
  li    $t6, 1
  lui   $at, %hi(stop_time_flag)
  bnez  $t5, .L7F039D64
   addiu $s2, $s2, 1
  sw    $t6, %lo(stop_time_flag)($at)
.L7F039D64:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionEB_If_Key_Pressed_RVL_2:
  lui   $t7, %hi(pPlayer) 
  lw    $t7, %lo(pPlayer)($t7)
  move  $a0, $s6
  move  $a1, $s2
  lw    $t2, 0xd8($t7)
  beql  $t2, $zero, .L7F039DA0
   addiu $s2, $s2, 2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 2
.L7F039DA0:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
actionEC_Disable_Player_Pickups_1:
  li    $t1, 1
  lui   $at, %hi(disable_player_pickups_flag)
  sw    $t1, %lo(disable_player_pickups_flag)($at)
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionED_Hide_First_Person_Display_1:
  jal   remove_item_in_hand
   move  $a0, $zero
  jal   remove_item_in_hand
   li    $a0, 1
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionEE_Cuba_Circular_Camera_Aim_D:
  lbu   $t9, 3($s1)
  lbu   $t6, 4($s1)
  lbu   $t4, 1($s1)
  sll   $t5, $t9, 8
  or    $v1, $t5, $t6
  sll   $t7, $v1, 0x10
  lbu   $t5, 7($s1)
  sra   $v1, $t7, 0x10
  lbu   $t7, 8($s1)
  lbu   $t8, 2($s1)
  sll   $t6, $t5, 8
  lbu   $t9, 0xb($s1)
  or    $a2, $t6, $t7
  lbu   $t6, 0xc($s1)
  sll   $t3, $t4, 8
  lbu   $t1, 5($s1)
  or    $v0, $t3, $t8
  lbu   $t3, 6($s1)
  sll   $t5, $t9, 8
  or    $t0, $t5, $t6
  mtc1  $t0, $f18
  sll   $t4, $t1, 8
  or    $a1, $t4, $t3
  sll   $t8, $a1, 0x10
  cvt.s.w $f16, $f18
  sra   $a1, $t8, 0x10
  mtc1  $a1, $f6
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f0
  cvt.s.w $f10, $f6
  mul.s $f8, $f16, $f26
  lbu   $t2, 9($s1)
  lbu   $t4, 0xa($s1)
  lui   $at, %hi(dword_CODE_bss_800799F8)
  sw    $zero, %lo(dword_CODE_bss_800799F8)($at)
  mul.s $f18, $f10, $f26
  lui   $at, %hi(dword_CODE_bss_800799FC)
  sw    $zero, %lo(dword_CODE_bss_800799FC)($at)
  sll   $t1, $t2, 8
  lui   $at, %hi(flt_CODE_bss_80079A00)
  or    $a3, $t1, $t4
  div.s $f4, $f8, $f0
  mtc1  $v0, $f8
  mtc1  $v1, $f6
  sll   $t3, $a3, 0x10
  sra   $a3, $t3, 0x10
  cvt.s.w $f10, $f6
  li    $a0, 7
  div.s $f16, $f18, $f0
  swc1  $f4, %lo(flt_CODE_bss_80079A00)($at)
  mtc1  $a3, $f18
  lui   $at, %hi(flt_CODE_bss_80079A04)
  cvt.s.w $f4, $f8
  swc1  $f16, %lo(flt_CODE_bss_80079A04)($at)
  cvt.s.w $f16, $f18
  lui   $at, %hi(flt_CODE_bss_80079A08)
  swc1  $f4, %lo(flt_CODE_bss_80079A08)($at)
  lui   $at, %hi(flt_CODE_bss_80079A0C)
  swc1  $f10, %lo(flt_CODE_bss_80079A0C)($at)
  lui   $at, %hi(flt_CODE_bss_80079A10)
  swc1  $f16, %lo(flt_CODE_bss_80079A10)($at)
  lui   $at, %hi(dword_CODE_bss_80079A14)
  jal   set_camera_mode
   sw    $a2, %lo(dword_CODE_bss_80079A14)($at)
  addiu $s2, $s2, 0xd
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 0xd
actionEF_Trigger_Credits_1:
  li    $t7, 1
  lui   $at, %hi(D_8003643C)
  sw    $t7, %lo(D_8003643C)($at)
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionF0_RVL_If_Credits_Completed_2:
  lui   $t2, %hi(D_8003643C) 
  lw    $t2, %lo(D_8003643C)($t2)
  li    $at, 2
  move  $a0, $s6
  bne   $t2, $at, .L7F039F2C
   move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F039F2C:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
actionF1_If_All_Objectives_Complete_RVL_2:
  jal   check_objectives_complete
   nop   
  beqz  $v0, .L7F039F60
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F039F60:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
actionF2_Check_Current_Folder_Bond_RVL_3:
  jal   getSelectedFolderBond
   nop   
  lb    $t1, 1($s1)
  move  $a0, $s6
  move  $a1, $s2
  bnel  $v0, $t1, .L7F039FA0
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F039FA0:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
actionF3_If_Player_Pickups_Disabled_RVL_2:
  lui   $t4, %hi(disable_player_pickups_flag) 
  lw    $t4, %lo(disable_player_pickups_flag)($t4)
  move  $a0, $s6
  move  $a1, $s2
  beql  $t4, $zero, .L7F039FD8
   addiu $s2, $s2, 2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 2
.L7F039FD8:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
actionF4_PlaysValuenum1ThemeSlot03ForValuenum2Seconds_4:
  move  $v0, $s1
  addiu $s1, $s1, 4
  addiu $s2, $s2, 4
  lb    $a0, 1($v0)
  lbu   $a1, 2($v0)
  jal   set_musicslot_time
   lbu   $a2, 3($v0)
  b     ParseCommandByte_SwitchCase
   lbu   $t6, ($s1)
actionF5_Turn_Off_Music_In_Slot_num_0_3_2:
  move  $v0, $s1
  addiu $s1, $s1, 2
  addiu $s2, $s2, 2
  jal   reset_music_in_slot
   lb    $a0, 1($v0)
  b     ParseCommandByte_SwitchCase
   lbu   $t6, ($s1)
actionF6_Trigger_Explosions_Around_Bond_1:
  jal   trigger_explosions_around_player
   move  $a0, $zero
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionF7_If_Number_Of_Hostages_Scientists_Killed_RVL_3:
  jal   get_civilian_casualties
   nop   
  lbu   $t3, 1($s1)
  move  $a0, $s6
  move  $a1, $s2
  slt   $at, $t3, $v0
  beql  $at, $zero, .L7F03A06C
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F03A06C:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
actionF8_If_Guard_ID_00200000_Flag_Set_Unset_And_Return_3:
  move  $a0, $s7
  jal   get_handle_for_guard_id
   lbu   $a1, 1($s1)
  beql  $v0, $zero, .L7F03A0CC
   addiu $s2, $s2, 3
  lw    $t8, 0x14($v0)
  lui   $at, (0xFFDFFFFF >> 16) # lui $at, 0xffdf
  ori   $at, (0xFFDFFFFF & 0xFFFF) # ori $at, $at, 0xffff
  sll   $t9, $t8, 0xa
  bgezl $t9, .L7F03A0CC
   addiu $s2, $s2, 3
  lw    $t5, 0x14($v0)
  move  $a0, $s6
  move  $a1, $s2
  and   $t6, $t5, $at
  sw    $t6, 0x14($v0)
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F03A0CC:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
actionF9_Set_Killed_In_Action_Automatic_Mission_Failure_1:
  li    $t7, 1
  lui   $at, %hi(mission_kia_flag)
  sw    $t7, %lo(mission_kia_flag)($at)
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionFA_Guard_Fawns_On_Shoulder_1:
  jal   check_if_able_to_then_fawn_on_shoulder
   move  $a0, $s7
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionFB_SwitchToSkyValuenumAndActivateGasContainersIfExist_:
  lui   $t2, %hi(D_80030A88) 
  addiu $t2, %lo(D_80030A88) # addiu $t2, $t2, 0xa88
  lw    $at, ($t2)
  addiu $a0, $sp, 0x90
  sw    $at, ($a0)
  lw    $t3, 4($t2)
  sw    $t3, 4($a0)
  lw    $at, 8($t2)
  jal   init_trigger_toxic_gas_effect
   sw    $at, 8($a0)
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionFC_Launch_Shuttle_2:
  jal   get_handle_to_tagged_object
   lbu   $a0, 1($s1)
  beql  $v0, $zero, .L7F03A1E4
   addiu $s2, $s2, 2
  lw    $t8, 0x10($v0)
  beql  $t8, $zero, .L7F03A1E4
   addiu $s2, $s2, 2
  lw    $a0, 0x10($v0)
  jal   sub_GAME_7F03FDA8
   sw    $v0, 0x88($sp)
  lw    $v1, 0x88($sp)
  lw    $t9, 0x64($v1)
  andi  $t5, $t9, 0x80
  beql  $t5, $zero, .L7F03A1E4
   addiu $s2, $s2, 2
  lw    $v0, 0x6c($v1)
  lw    $t6, ($v0)
  ori   $t7, $t6, 0x601
  sw    $t7, ($v0)
  lw    $a0, 0x10($v1)
  jal   sub_GAME_7F03FE14
   sw    $v1, 0x88($sp)
  lw    $v1, 0x88($sp)
  lw    $a0, 0x6c($v1)
  jal   matrix_4x4_set_identity
   addiu $a0, $a0, 0x20
  lw    $v1, 0x88($sp)
  lui   $at, %hi(D_80052974)
  lw    $t4, 0x6c($v1)
  swc1  $f20, 4($t4)
  lwc1  $f8, %lo(D_80052974)($at)
  lw    $t1, 0x6c($v1)
  lui   $at, %hi(D_80052978)
  swc1  $f8, 8($t1)
  lw    $t2, 0x6c($v1)
  swc1  $f20, 0xc($t2)
  lw    $t3, 0x6c($v1)
  swc1  $f20, 0x10($t3)
  lwc1  $f4, %lo(D_80052978)($at)
  lw    $t8, 0x6c($v1)
  swc1  $f4, 0x14($t8)
  lw    $t9, 0x6c($v1)
  swc1  $f20, 0x18($t9)
  addiu $s2, $s2, 2
.L7F03A1E4:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
GetCmdLength:
  jal   get_length_of_action_block
   move  $a1, $s2                    # 
  addu  $s2, $s2, $v0                # CurrentActionByte += get_length_of_action_block(CurrentActionByte)
  b     GetByteS1_ParseCommandByte_SwitchCase                  # s1 = CurrentActionByte + s6
   addu  $s1, $s6, $s2              # goto 58c

Action04_End_1:
  lw    $ra, 0x74($sp)
Action04_End_2:
  ldc1  $f20, 0x30($sp)
  ldc1  $f22, 0x38($sp)
  ldc1  $f24, 0x40($sp)
  ldc1  $f26, 0x48($sp)
  lw    $s0, 0x50($sp)
  lw    $s1, 0x54($sp)
  lw    $s2, 0x58($sp)    #load s2 with value before entering actionblock
  lw    $s3, 0x5c($sp)
  lw    $s4, 0x60($sp)
  lw    $s5, 0x64($sp)
  lw    $s6, 0x68($sp)
  lw    $s7, 0x6c($sp)
  lw    $fp, 0x70($sp)
  jr    $ra
   addiu $sp, $sp, 0x7b8
");
#endif

#ifdef VERSION_JP
asm(R"
.late_rodata
/*HACK FIXME */
.word locret_CODE_7F035104
.word locret_CODE_7F03510C
.word locret_CODE_7F035114
.word locret_CODE_7F03511C
.word locret_CODE_7F035124
.word locret_CODE_7F03512C
.word locret_CODE_7F035134
.word locret_CODE_7F03513C
.word locret_CODE_7F035144
.word locret_CODE_7F03514C
.word locret_CODE_7F035154
.word locret_CODE_7F03515C
.word locret_CODE_7F034ADC
.word locret_CODE_7F034AD4
.word locret_CODE_7F035164
.word locret_CODE_7F03516C
.word locret_CODE_7F035174
.word locret_CODE_7F03517C
.word locret_CODE_7F035184
.word locret_CODE_7F03518C
.word locret_CODE_7F035194
.word locret_CODE_7F03519C
.word locret_CODE_7F0351A4
.word locret_CODE_7F0351AC
.word locret_CODE_7F0351B4
.word locret_CODE_7F0351BC
.word locret_CODE_7F0351C4
.word locret_CODE_7F0351CC
.word locret_CODE_7F0351D4
.word locret_CODE_7F0351DC
.word locret_CODE_7F0351E4
.word locret_CODE_7F0351EC
.word locret_CODE_7F0351F4
.word actionFC_length
.late_rodata
glabel D_800524F4
.word 0x40c90fdb /*6.2831855*/
/*D:800524F8*/
glabel jpt_800524F8
.word Action00_GoToLabel
.word Action01_GoToLabelFromTop
.word Action02_Label
.word action03_Leave_The_Routine_When_Return_Continue_From_Spot_1
.word Action04_End_1
.word action05_Jump_To_Function_4
.word action06_Set_Return_Subroutine_for_0007_Command_3
.word action07_Jump_to_Return_Subroutine_1
.word action08_Reset_Animation_1
.word action09_Guard_Kneels_1
.word action0A_Animation_9
.word action0B_If_Guard_WastingTime_SwatFlies_RVL_2
.word action0C_Guard_Gestures_1
.word action0D_Guard_Looks_Around_When_Shot_At_1
.word action0E_Guard_Steps_Sideways_RVL_2
.word action0F_Guard_Hops_Sideways_RVL_2
.word action10_Guard_Runs_Sideways_RVL_2
.word action11_Guard_Walks_Firing_RVL_2
.word action12_Guard_Runs_Firing_RVL_2
.word action13_Guard_Rolls_On_Ground_Then_Fires_Crouched_RVL_2
.word action14_Guard_Aims_Shoots_at_Bond_Guard_Pad_RVL_6
.word action15_Guard_Kneels_Aims_Shoots_at_Bond_Guard_Pad_RVL_6
.word action16_Guard_Shoots_Guards_Without_Animation_Change_RVL_6
.word action17_Guard_Constantly_Angles_To_Face_RVL_6
.word action18_Shoot_Guard_ID_In_Style_With_Weapon_Type_num_4
.word action19_Guard_ID1_Shoots_Guard_ID2_In_Style_4
.word action1A_Guard_Throws_Grenade_RVL_2
.word action1B_Drop_Weapon_Inventory_num_RVL_5
.word action1C_Guard_Jogs_To_Preset_3
.word action1D_Guard_Jogs_To_Predefined_Preset_2328_1
.word action1E_Guard_Walks_To_Preset_3
.word action1F_Guard_Runs__To_Preset_3
.word action20_Activate_Path_2
.word action21_Guard_Surrenders_1
.word action22_Guard_Set_To_Move_Fades_And_Disappear_1
.word action23_Eliminate_Guard_ID_2
.word action24_Activate_Object_At_Preset_RVL_If_Successful_4
.word action25_Sound_Alarm_1
.word action26_Turn_Off_Alarm_1
.word action27_Return_False_Invalid_Type_2
.word action28_Jog_To_Bond_Return_Loop_When_Reached_Bond_2
.word action29_Walk_To_Bond_Return_Loop_When_Reached_Bond_2
.word action2A_Run_To_Bond_Return_Loop_When_Reached_Bond_2
.word action2B_Return_False_Invalid_Type_2
.word action2C_Jog_To_Character_Position_RVL_On_Arrival_3
.word action2D_Walk_To_Character_Position_RVL_On_Arrival_3
.word action2E_Run_To_Character_Position_RVL_On_Arrival_3
.word action2F_When_Guard_Stops_Moving_RVL_2
.word action30_Detect_If_Guard_Killed_RVL_If_So_3
.word action31_If_GuardID_Finish_DeathAnimation_RVL_3
.word action32_If_Bond_In_Sight_RVL_2
.word action33_Seed_Random_Byte_1
.word action34_If_Seeded_Byte_LTV_Go_Into_RVL_3
.word action35_If_Seeded_Byte_GTV_Go_Into_RVL_3
.word action36_If_Alarm_Activated_RVL_Plus_Stack_2
.word action37_If_Alarm_Activated_RVL_2
.word action38_If_Toxic_Gas_Released_RVL_2
.word action39_If_Guard_Heard_Gunfire_RVL_2
.word action3A_If_Bond_Shoots_Another_Guard_RVL_2
.word action3B_If_Guard_Killed_In_Front_Of_Guard_RVL_2
.word action3C_If_Guard_In_Firing_Range_RVL_2
.word action3D___Unused___Unknown___2
.word action3E_If_Shot_Current_Guard_RVL_2
.word action3F_If_Heard_Bond_RVL_2
.word action40_If_Another_Guard_In_Same_Room_As_Guard_ID_RVL_3
.word action41_If_Guard_Has_Been_On_Screen_RVL_2
.word action42_If_Current_Guard_On_Screen_In_Loaded_Room_RVL_2
.word action43_If_Guard_In_A_Room_Currently_Loaded_RVL_2
.word action44_If_Room_Containing_Preset_Is_Loaded_RVL_4
.word action45_Go_To_RVL_If_Bond_Has_Guard_At_Gunpoint_2
.word action46_If_Fired_A_Shot_RVL_2
.word action47_If_Distance_Between_Bond_And_Guard_LTV_RVL_3
.word action48_If_Distance_Between_Bond_And_Guard_GTV_RVL_3
.word action49_Test_if_Actor_and_Player_CCWAngle_LTV_RVL_Unused_3
.word action4A_Test_if_Actor_and_Player_CCWAngle_GTV_RVL_Unused_3
.word action4B_RVL_If_In_Proximity_Of_Bond_4
.word action4C_RVL_If_Not_In_Proximity_Of_Bond_4
.word action4D_When_Guard_In_Proximity_Of_Preset_RVL_7
.word action4E_When_Guard_Not_In_Proximity_Of_Preset_RVL_7
.word action4F_If_Current_Guard_Is_In_Units_Of_Guard_ID_RVL_5
.word action50_If_Current_Guard_Is_Not_In_Units_Of_Guard_ID_RVL_5
.word action51_SetClosestGuardUnitsGuardID_Then_RVL_IfSuccess_4
.word action52_GoIntoRVLIf_In_Units_Of_Preset_6
.word action53_GoIntoRVLIf_Not_In_Units_Of_Preset_6
.word action54_GoIntoRVLIf_Guard_Is_At_Preset_5
.word action55_GoIntoRVLIf_Entered_Room_with_Preset_4
.word action56_GoIntoRVLIf_16_Object_num_Collected_3
.word action57_GoIntoRVLIf_Specified_Weapon_Deposited_3
.word action58_GoIntoRVLIf_SpecifiedWeaponDeposited_On16Object_4
.word action59_GoIntoRVLIf_Specified_Weapon_Is_Out_3
.word action5A_GoIntoRVLIf_Type_16_Object_num_Loaded_3
.word action5B_GoIntoRVLIf_16_Object_num_Not_Destroyed_3
.word action5C_GoIntoRVLIf_16_Object_num_Activated_3
.word action5D_GoIntoRVLIf_Gadget_Used_On_16_Object_num_3
.word action5E_16_Object_Activates_2
.word action5F_16_Object_Explodes_2
.word action60_Guard_Drops_16_Object_num_2
.word action61_Kill_Guard_num_2
.word action62_Guard_num_Throws_Equipment_2
.word action63_Guard_Gives_Bond_16_Object_num_2
.word action64_Type_16_Object_Equipped_On_Guard_3
.word action65_Object_Moved_To_Preset_4
.word action66_Open_Door_2
.word action67_Close_Door_2
.word action68_Check_Door_Status_RVL_If_Met_4
.word action69_If_16_Object_Is_Valid_Door_RVL_3
.word action6A_Set_Bits_To_Lock_On_Type_16_Door_3
.word action6B_Unset_Bits_To_Lock_On_Type_16_Door_3
.word action6C_If_Tagged_Locked_Door_16_Objects_Toggled_RVL_4
.word action6D_If_Objective_num_Complete_RVL_3
.word action6E_If_Guard_2328_Preset_RVL_3
.word action6F_If_Guard_2328_Preset_Set_RVL_3
.word action70_Go_Into_RVL_Difficulty_LTV_3
.word action71_GoIntoRVLIf_Difficulty_GTV_3
.word action72_Go_To_RVL_If_Time_LTV_4
.word action73_Go_To_RVL_If_Time_GTV_4
.word action74_Go_To_RVL_If_Power_On_Time_LTV_4
.word action75_Go_To_RVL_If_Power_On_Time_GTV_4
.word action76_Go_To_RVL_If_Stage_Number_LTV_3
.word action77_Go_To_RVL_If_Stage_Number_GTV_3
.word action78_Go_To_RVL_If_Guard_Shot_LTV_3
.word action79_Go_To_RVL_If_Guard_Shot_GTV_3
.word action7A_Go_To_RVL_If_Number_Near_Miss_Gunshots_LTV_3
.word action7B_Go_To_RVL_If_Number_Near_Miss_Gunshots_GTV_3
.word action7C_If_Guard_Health_Below_Value_RVL_4
.word action7D_If_Guard_Health_Above_Value_RVL_4
.word action7E_If_Guard_nums_Bitflag_01000000_Set_RVL_3
.word action7F_If_Health_Below_Value_RVL_3
.word action80_If_Health_Above_Value_RVL_3
.word action81_Set_User_Byte_num1_2
.word action82_Add_Value_To_User_Byte_num1_Max_To_FF_2
.word action83_Subtract_Value_To_User_Byte_num1_Min_To_0_2
.word action84_If_Value_GreaterThan_User_Byte_num1_RVL_3
.word action85_If_User_Byte_num1_LessThan_Random_Value_RVL_2
.word action86_Set_User_Byte_num2_2
.word action87_Add_Value_To_User_Byte_num2_Max_To_FF_2
.word action88_Subtract_Value_To_User_Byte_num2_Min_To_0_2
.word action89_If_Value_GreaterThan_User_Byte_num2_RVL_3
.word action8A_If_User_Byte_num2_LessThan_Random_Value_RVL_2
.word action8B_Set_Guard_Hearing_Distance_3
.word action8C_Set_Guard_Visible_Distance_2
.word action8D_Set_Guard_Grenade_Probability_2
.word action8E_Set_Guard_ID_2
.word action8F_Set_Guard_Health_3
.word action90_Set_Guard_Armor_Amount_3
.word action91_Set_Character_Reaction_Speed_2
.word action92_Set_Character_Injury_Recovery_Speed_2
.word action93_Set_Character_Accuracy_2
.word action94_Mask_Guard_Type_With_Value_2
.word action95_Unmask_Guard_Type_With_Value_2
.word action96_If_Guard_Type_Value_Is_Set_RVL_3
.word action97_Mask_Guard_Type_Flags_With_Value_3
.word action98_Unmask_Guard_Type_Flags_With_Value_3
.word action99_If_Guard_Type_Flags_Set_RVL_4
.word action9A_Set_Objective_Bits_5
.word action9B_Unset_Objective_Value_5
.word action9C_Check_If_Objective_Value_Return_Loop_If_So_6
.word action9D_Set_Guard_Bit_Tags_5
.word action9E_Unset_Guard_Bit_Tags_5
.word action9F_Check_Guard_Bits_If_Same_RVL_6
.word actionA0_Set_Guard_ID_Bits_6
.word actionA1_Unset_Guard_ID_Bits_6
.word actionA2_Check_Guard_Bits_If_Same_RVL_7
.word actionA3_Set_State_Bits_16_Type_Object_6
.word actionA4_Unset_State_Bits_16_Type_Object_6
.word actionA5_Check_State_Bits_16_Type_Object_If_Same_RVL_7
.word actionA6_Set_16_Object_States_More_6
.word actionA7_Unset_16_Object_States_More_6
.word actionA8_Check_16_Object_States_More_If_Same_RVL_7
.word actionA9_Sets_To_Guard_ID_Fc_Current_Guard_2
.word actionAA_Sets_FC_Value_For_Guard_ID_To_Guard_ID_3
.word actionAB_Set_Current_Guards_2328_Value_To_Preset_3
.word actionAC_Set_Guard_ID_numS_2328_Value_To_Preset_4
.word actionAD_Debug_Comment_20
.word actionAE_Reset_Cycle_Counter_And_Enable_It_1
.word actionAF_Reset_Cycle_Counter_1
.word actionB0_Disable_Cycle_Counter_1
.word actionB1_Enable_Cycle_Counter_1
.word actionB2_Check_Cycle_Counter_Enable_Status_2
.word actionB3_If_Cycle_Counter_LTV_RVL_5
.word actionB4_If_Cycle_Counter_GTV_RVL_5
.word actionB5_Show_Timer_1
.word actionB6_Hide_Timer_Silent_Countdown_1
.word actionB7_Set_Timer_X_Seconds__Doesnt_Show_Timer_Yet_3
.word actionB8_Stop_Timer_1
.word actionB9_Start_Timer_1
.word actionBA_Check_Timer_Enabled_Status_RVL_If_Enabled_2
.word actionBB_Detect_If_Timer_Below_Certain_Point_RVL_If_So_4
.word actionBC_Detect_If_Timer_Above_Certain_Point_RVL_If_So_4
.word actionBD_Spawn_Guard_C
.word actionBE_Respawn_Guard_with_ID_B
.word actionBF_Spawn_Weapon_9
.word actionC0_Spawn_Hat_8
.word actionC1_GuardIDDoesAV_If_Gunfire_RVL_WhenComplete_5
.word actionC2_Display_Text_Preset_Bottom_Screen_3
.word actionC3_Display_Text_Preset_Top_Screen_3
.word actionC4_Play_Sound_Effect_num_In_Slot_num_0_7_4
.word actionC5_EmanateSoundSlotnumFrom16ObjectWithAudibleRV_5
.word actionC6_EmanateSoundSlotnumFromPresetWithAudibleRV_6
.word actionC7_Sound_In_Slot_num_Crecendos_To_Volume_Over_ms_6
.word actionC8_Sound_In_Slot_num_Fades_To_Volume_Over_ms_6
.word actionC9_Shut_Off_Sound_In_Slot_Number_2
.word actionCA_If_Value_GreaterThan_Volume_7FFF_Max_RVL_5
.word actionCB_Set_Object_Path_27_Type_Object_2
.word actionCC_Set_Speed_Moving_Vehicle_27_Type_Object_5
.word actionCD_Set_Speed_Aircraft_Rotor_5
.word actionCE_Detect_If_Currently_In_Intro_Camera_RVL_If_So_2
.word actionCF_Detect_If_Currently_In_Intro_Swirl_RVL_If_So_2
.word actionD0_Change_Animation_Type_Of_Type_16_Monitor_4
.word actionD1_If_Bond_In_Tank_RVL_2
.word actionD2_Exit_Level_1
.word actionD3_Return_From_Camera_Scene_1
.word actionD4_Camera_Looks_At_Bond_From_Preset_3
.word actionD5_Go_To_Camera_Position_6
.word actionD6_If_Less_Than_Elevation_RVL_4
.word actionD7_Disable_Text_Variable_2
.word actionD8_Enable_All_On_Screen_Displays_1
.word actionD9_GuardIDMovedToPresetReturnLoopIfSuccessful_5
.word actionDA_Fade_Out_From_Cut_Scene_1
.word actionDB_Fade_In_From_Black_Reset_DA_1
.word actionDC_RVL_When_Fade_Complete_2
.word actionDD_Remove_All_Guards_1
.word actionDE_Bring_Removed_Guards_Back_1
.word actionDF_Open_Type_16_Door_Used_Cut_Scenes_2
.word actionE0_Guard_ID_Draws_Weapon_num_3
.word actionE1_If_Fewer_than_This_Many_Players_Playing_RVL_3
.word actionE2_If_Ammo_Value_In_Type_Is_LTV_RVL_4
.word actionE3_Draw_Weapon_From_Inventory_In_Game_2
.word actionE4_Draw_Weapon_From_Inventory_Cut_Scene_2
.word actionE5_Set_Bonds_Speed_3
.word actionE6_If_16_Object_And_Preset_Are_In_Same_Room_RVL_5
.word actionE7_If_Guard_Moving_And_Shooting_RVL_2
.word actionE8_If_Guard_Is_Shooting_RVL_2
.word actionE9_Instantly_Switch_Sky_To_Sky_2_1
.word actionEA_Stop_Game_Time_1
.word actionEB_If_Key_Pressed_RVL_2
.word actionEC_Disable_Player_Pickups_1
.word actionED_Hide_First_Person_Display_1
.word actionEE_Cuba_Circular_Camera_Aim_D
.word actionEF_Trigger_Credits_1
.word actionF0_RVL_If_Credits_Completed_2
.word actionF1_If_All_Objectives_Complete_RVL_2
.word actionF2_Check_Current_Folder_Bond_RVL_3
.word actionF3_If_Player_Pickups_Disabled_RVL_2
.word actionF4_PlaysValuenum1ThemeSlot03ForValuenum2Seconds_4
.word actionF5_Turn_Off_Music_In_Slot_num_0_3_2
.word actionF6_Trigger_Explosions_Around_Bond_1
.word actionF7_If_Number_Of_Hostages_Scientists_Killed_RVL_3
.word actionF8_If_Guard_ID_00200000_Flag_Set_Unset_And_Return_3
.word actionF9_Set_Killed_In_Action_Automatic_Mission_Failure_1
.word actionFA_Guard_Fawns_On_Shoulder_1
.word actionFB_SwitchToSkyValuenumAndActivateGasContainersIfExist_
.word actionFC_Launch_Shuttle_2

glabel D_800528EC
.word 0x3dcccccd /*0.1*/
glabel D_800528F0
.word 0x3dcccccd /*0.1*/
glabel D_800528F4
.word 0x3dcccccd /*0.1*/
glabel D_800528F8
.word 0x3dcccccd /*0.1*/

glabel jpt_800528FC
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word .L7F038C24
.word .L7F038C24
.word .L7F038C24
.word .L7F038C24
.word .L7F038C24
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C
.word loc_CODE_7F038C0C

glabel D_80052974
.word 0x3c888888 /*0.016666666*/
glabel D_80052978
.word 0x3e955555 /*0.29166666*/
.word 0

.text
glabel parse_handle_actionblocks
  addiu $sp, $sp, -0x7b8
  sw    $s7, 0x6c($sp)
  sw    $s6, 0x68($sp) 				 #free s2 for CurrentActionByte ?
  li    $at, 3 						 #ai_sleep
  sw    $ra, 0x74($sp)
  sw    $fp, 0x70($sp)
  sw    $s5, 0x64($sp)
  sw    $s4, 0x60($sp)
  sw    $s3, 0x5c($sp)
  sw    $s2, 0x58($sp) 				 #free s2 for CurrentActionByteSize ?
  sw    $s1, 0x54($sp)
  sw    $s0, 0x50($sp)
  sdc1  $f26, 0x48($sp)
  sdc1  $f24, 0x40($sp)
  sdc1  $f22, 0x38($sp)
  sdc1  $f20, 0x30($sp)
  move  $s7, $zero
  move  $a2, $zero
  move  $v1, $zero
  bne   $a1, $at, .L7F0354E0
   move  $s6, $zero
  b     .L7F035514
   move  $s7, $a0
.L7F0354E0:
  li    $at, 1
  bne   $a1, $at, .L7F035514
   nop   
  lbu   $v0, 3($a0)
  li    $at, 39
  bnel  $v0, $at, .L7F035508
   li    $at, 40
  b     .L7F035514
   move  $a2, $a0
  li    $at, 40
.L7F035508:
  bne   $v0, $at, .L7F035514
   nop   
  move  $v1, $a0
.L7F035514:
  beqz  $s7, .L7F03552C
   lui   $at, %hi(D_800524F4)
  lhu   $s2, 0x108($s7) 				 # Load Size of command
  lw    $s6, 0x104($s7) 				 # load command
  b     .L7F035558
   sw    $s2, 0x7a4($sp) 				 # save command size
.L7F03552C:
  beqz  $a2, .L7F035544
   nop   
  lhu   $s2, 0x84($a2)
  lw    $s6, 0x80($a2)
  b     .L7F035558
   sw    $s2, 0x7a4($sp)
.L7F035544:
  beqz  $v1, .L7F035558
   nop   
  lhu   $s2, 0x84($v1)
  lw    $s6, 0x80($v1)
  sw    $s2, 0x7a4($sp)
.L7F035558:
  beqz  $s6, Action04_End_1
   lw    $s2, 0x7a4($sp)
  lwc1  $f26, %lo(D_800524F4)($at)
  li    $at, 0x41200000				 # 10.000000
  mtc1  $at, $f24
  li    $at, 0x42700000 				# 60.000000
  lui   $fp, %hi(ptr_guard_data) 
  mtc1  $at, $f22
  mtc1  $zero, $f20
  addiu $fp, %lo(ptr_guard_data) 		# addiu $fp, $fp, -0x339c
  addu  $s1, $s6, $s2
  sw    $v1, 0x7ac($sp)
  sw    $a2, 0x7b0($sp)
GetByteS1_ParseCommandByte_SwitchCase:								/*GetCommandByte(cmd)*/
  lbu   $t6, ($s1) #t6 = byte(s1)
ParseCommandByte_SwitchCase:
  move  $a0, $s6
  sltiu $at, $t6, 0xfd				# if Cmd !< AI_CMDS_TOTAL  then 
  beqz  $at, GetCmdLength				#    Cmd<<2  goto GetCmdLength
   sll   $t6, $t6, 2
  lui   $at, %hi(jpt_800524F8)
  addu  $at, $at, $t6					# else //get cmd
  lw    $t6, %lo(jpt_800524F8)($at)	#    switch t6(look up table for switch 0x800524f8)
  jr    $t6							# return cmd
   nop   
Action00_GoToLabel: 					                            #case 0
  move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action #(command, commandsize, nextcommand[4])
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase	# GetCommandByte(currcmd + currcmdLength); 
   addu  $s1, $s6, $v0
Action01_GoToLabelFromTop: 			                                #case 1
  move  $a0, $s6
  move  $a1, $zero
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase	   #break
   addu  $s1, $s6, $v0
Action02_Label:                                                     #case 2
  addiu $s2, $s2, 2				    # s2++  PC ?    # CurrentActionByte += 2
  b     GetByteS1_ParseCommandByte_SwitchCase         # s1 +=2; goto 58c
   addiu $s1, $s1, 2
action03_Leave_The_Routine_When_Return_Continue_From_Spot_1:
  beqz  $s7, .L7F03560C				# s2++  PC?
   addiu $s2, $s2, 1					# if s7 = 0 goto 0c      If actionblock not initilised else ?
  sw    $s6, 0x104($s7)				# s7.104 = s6
  b     Action04_End_1				# s7.108 = unsigned short(s2)
   sh    $s2, 0x108($s7)				# goto end1 (load return addr)
.L7F03560C:
  lw    $t7, 0x7b0($sp)
  lw    $t8, 0x7ac($sp)
  beqz  $t7, .L7F035628				# if t7 = 0 goto 28
   nop   
  sw    $s6, 0x80($t7)				#else t7.80 = s6
  b     Action04_End_1				# t7.84 = unsigned short(s2)
   sh    $s2, 0x84($t7)				# end1 (load return addr)
.L7F035628:
  beql  $t8, $zero, Action04_End_2    # load return addr (same as end1 (sp.74))
   lw    $ra, 0x74($sp)				# if t8 = 0 goto end2 (skip return addr)
  sw    $s6, 0x80($t8)				# else t8.80 = s6
  b     Action04_End_1				# t8.84 = unsigned short(s2)
   sh    $s2, 0x84($t8)				# end1(load return addr)
action05_Jump_To_Function_4:
  lbu   $t9, 2($s1)
  lbu   $t2, 3($s1)
  lbu   $a1, 1($s1)
  sll   $t1, $t9, 8
  or    $v1, $t1, $t2
  andi  $t3, $v1, 0xffff
  li    $at, 253
  bne   $a1, $at, .L7F035678
   move  $v1, $t3
  move  $a0, $t3
  jal   LoadNext_PrevActionBlock
   move  $s2, $zero
  move  $s6, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   move  $s1, $v0
.L7F035678:
  move  $a0, $s7
  jal   get_handle_for_guard_id
   sh    $v1, 0x792($sp)
  lhu   $v1, 0x792($sp)
  beqz  $v0, .L7F0356A4
   move  $s0, $v0
  jal   LoadNext_PrevActionBlock
   move  $a0, $v1
  sw    $v0, 0x104($s0)
  sh    $zero, 0x108($s0)
  sb    $zero, 8($s0)
.L7F0356A4:
  addiu $s2, $s2, 4
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
action06_Set_Return_Subroutine_for_0007_Command_3:
  lbu   $t4, 1($s1)
  lbu   $t6, 2($s1)
  lw    $t8, 0x7b0($sp)
  sll   $t5, $t4, 8
  or    $v0, $t5, $t6
  andi  $t7, $v0, 0xffff
  beqz  $s7, .L7F0356E0
   move  $v0, $t7
  sh    $t7, 0x10a($s7)
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
.L7F0356E0:
  beqz  $t8, .L7F0356F8
   lw    $t9, 0x7ac($sp)
  sh    $v0, 0x86($t8)
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
.L7F0356F8:
  beqz  $t9, .L7F035704
   addiu $s2, $s2, 3
  sh    $v0, 0x86($t9)
.L7F035704:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action07_Jump_to_Return_Subroutine_1:
  beqz  $s7, .L7F035728
   move  $s2, $zero
  jal   LoadNext_PrevActionBlock
   lh    $a0, 0x10a($s7)
  move  $s6, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   move  $s1, $v0
.L7F035728:
  lw    $t1, 0x7b0($sp)
  lw    $t2, 0x7ac($sp)
  beqz  $t1, .L7F03574C
   nop   
  jal   LoadNext_PrevActionBlock
   lh    $a0, 0x86($t1)
  move  $s6, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   move  $s1, $v0
.L7F03574C:
  beqz  $t2, .L7F035760
   nop   
  jal   LoadNext_PrevActionBlock
   lh    $a0, 0x86($t2)
  move  $s6, $v0
.L7F035760:
  b     GetByteS1_ParseCommandByte_SwitchCase
   move  $s1, $s6
action08_Reset_Animation_1:
  jal   sub_GAME_7F0335D4
   move  $a0, $s7
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
action09_Guard_Kneels_1:
  jal   check_if_able_to_then_kneel
   move  $a0, $s7
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
action0A_Animation_9:
  lbu   $t3, 1($s1)
  lbu   $t5, 2($s1)
  li    $at, 65535
  sll   $t4, $t3, 8
  or    $t6, $t4, $t5
  sw    $t6, 0x77c($sp)
  lbu   $t7, 3($s1)
  lbu   $t1, 5($s1)
  lbu   $t9, 4($s1)
  lbu   $t3, 6($s1)
  sll   $t8, $t7, 8
  sll   $t2, $t1, 8
  or    $s0, $t8, $t9
  or    $t4, $t2, $t3
  bne   $s0, $at, .L7F0357D4
   sw    $t4, 0x774($sp)
  move  $s0, $zero
.L7F0357D4:
  lw    $s3, 0x774($sp)
  li    $at, 65535
  move  $a0, $s7
  bne   $s3, $at, .L7F0357EC
   lw    $t7, 0x7ac($sp)
  li    $s3, -1
.L7F0357EC:
  beqz  $s7, .L7F035820
   nop   
  lbu   $t5, 7($s1)
  lw    $a1, 0x77c($sp)
  move  $a2, $s0
  sw    $t5, 0x10($sp)
  lbu   $t6, 8($s1)
  move  $a3, $s3
  jal   check_if_able_to_then_perform_animation
   sw    $t6, 0x14($sp)
  addiu $s2, $s2, 9
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 9
.L7F035820:
  beqz  $t7, .L7F035890
   li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f6
  lw    $a0, 0x14($t7)
  mtc1  $s0, $f4
  swc1  $f6, 0x10($sp)
  lbu   $t1, 8($s1)
  cvt.s.w $f4, $f4
  lw    $t8, 0x77c($sp)
  mtc1  $t1, $f8
  lui   $a1, %hi(animation_table_ptrs2)
  sll   $t9, $t8, 2
  cvt.s.w $f10, $f8
  addu  $a1, $a1, $t9
  mfc1  $a3, $f4
  lw    $a1, %lo(animation_table_ptrs2)($a1)
  move  $a2, $zero
  jal   sub_GAME_7F06FCA8
   swc1  $f10, 0x14($sp)
  bltzl $s3, .L7F035894
   addiu $s2, $s2, 9
  mtc1  $s3, $f16
  lw    $t2, 0x7ac($sp)
  cvt.s.w $f16, $f16
  lw    $a0, 0x14($t2)
  mfc1  $a1, $f16
  jal   sub_GAME_7F06FDE8
   nop   
.L7F035890:
  addiu $s2, $s2, 9
.L7F035894:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 9
action0B_If_Guard_WastingTime_SwatFlies_RVL_2:
  lb    $t3, 7($s7)
  li    $at, 3
  move  $a0, $s6
  bne   $t3, $at, .L7F0358C4
   move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F0358C4:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action0C_Guard_Gestures_1:
  jal   check_if_able_to_then_shuffle_feet
   move  $a0, $s7
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
action0D_Guard_Looks_Around_When_Shot_At_1:
  jal   check_if_able_to_then_look_flustered
   move  $a0, $s7
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
action2F_When_Guard_Stops_Moving_RVL_2:
  jal   check_if_actor_stationary
   move  $a0, $s7
  beqz  $v0, .L7F035920
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F035920:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action30_Detect_If_Guard_Killed_RVL_If_So_3:
  move  $a0, $s7
  jal   get_handle_for_guard_id
   lbu   $a1, 1($s1)
  beqz  $v0, .L7F03594C
   move  $a0, $v0
  jal   true_if_actor_dying_fading
   nop   
  beqz  $v0, .L7F035968
.L7F03594C:
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F035968:
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action31_If_GuardID_Finish_DeathAnimation_RVL_3:
  move  $a0, $s7
  jal   get_handle_for_guard_id
   lbu   $a1, 1($s1)
  beqz  $v0, .L7F035990
   move  $a0, $s6
  lw    $t4, 0x1c($v0)
  bnez  $t4, .L7F0359A8
.L7F035990:
   move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F0359A8:
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action32_If_Bond_In_Sight_RVL_2:
  jal   sub_GAME_7F029D70
   move  $a0, $s7
  beqz  $v0, .L7F0359DC
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F0359DC:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action0E_Guard_Steps_Sideways_RVL_2:
  jal   actor_steps_sideways
   move  $a0, $s7
  beqz  $v0, .L7F035A10
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F035A10:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action0F_Guard_Hops_Sideways_RVL_2:
  jal   actor_hops_sideways
   move  $a0, $s7
  beqz  $v0, .L7F035A44
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F035A44:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action10_Guard_Runs_Sideways_RVL_2:
  jal   actor_runs_sideways
   move  $a0, $s7
  beqz  $v0, .L7F035A78
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F035A78:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action11_Guard_Walks_Firing_RVL_2:
  jal   actor_walks_and_fires
   move  $a0, $s7
  beqz  $v0, .L7F035AAC
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F035AAC:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action12_Guard_Runs_Firing_RVL_2:
  jal   actor_runs_and_fires
   move  $a0, $s7
  beqz  $v0, .L7F035AE0
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F035AE0:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action13_Guard_Rolls_On_Ground_Then_Fires_Crouched_RVL_2:
  jal   actor_rolls_fires_crouched
   move  $a0, $s7
  beqz  $v0, .L7F035B14
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F035B14:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action14_Guard_Aims_Shoots_at_Bond_Guard_Pad_RVL_6:
  lbu   $t5, 3($s1)
  lbu   $t8, 1($s1)
  lbu   $t7, 4($s1)
  lbu   $t1, 2($s1)
  sll   $t6, $t5, 8
  sll   $t9, $t8, 8
  move  $a0, $s7
  or    $a2, $t6, $t7
  jal   actor_aim_at_actor
   or    $a1, $t9, $t1
  beqz  $v0, .L7F035B68
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 5($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F035B68:
  addiu $s2, $s2, 6
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 6
action15_Guard_Kneels_Aims_Shoots_at_Bond_Guard_Pad_RVL_6:
  lbu   $t2, 3($s1)
  lbu   $t5, 1($s1)
  lbu   $t4, 4($s1)
  lbu   $t7, 2($s1)
  sll   $t3, $t2, 8
  sll   $t6, $t5, 8
  move  $a0, $s7
  or    $a2, $t3, $t4
  jal   actor_kneel_aim_at_actor
   or    $a1, $t6, $t7
  beqz  $v0, .L7F035BBC
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 5($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F035BBC:
  addiu $s2, $s2, 6
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 6
actionE7_If_Guard_Moving_And_Shooting_RVL_2:
  lb    $t8, 7($s7)
  li    $at, 8
  bnel  $t8, $at, .L7F035C14
   addiu $s2, $s2, 2
  lw    $t9, 0x58($s7)
  bnezl $t9, .L7F035C14
   addiu $s2, $s2, 2
  lw    $t1, 0x4c($s7)
  move  $a0, $s6
  move  $a1, $s2
  andi  $t2, $t1, 0x40
  beql  $t2, $zero, .L7F035C14
   addiu $s2, $s2, 2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 2
.L7F035C14:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
actionE8_If_Guard_Is_Shooting_RVL_2:
  lb    $t3, 7($s7)
  li    $at, 8
  move  $a0, $s6
  bne   $t3, $at, .L7F035C44
   move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F035C44:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action16_Guard_Shoots_Guards_Without_Animation_Change_RVL_6:
  lbu   $t4, 3($s1)
  lbu   $t7, 1($s1)
  lbu   $t6, 4($s1)
  lbu   $t9, 2($s1)
  sll   $t5, $t4, 8
  sll   $t8, $t7, 8
  move  $a0, $s7
  or    $a2, $t5, $t6
  jal   sub_GAME_7F02AAF4
   or    $a1, $t8, $t9
  beqz  $v0, .L7F035C98
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 5($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F035C98:
  addiu $s2, $s2, 6
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 6
action17_Guard_Constantly_Angles_To_Face_RVL_6:
  lbu   $t1, 3($s1)
  lbu   $t4, 1($s1)
  lbu   $t3, 4($s1)
  lbu   $t6, 2($s1)
  sll   $t2, $t1, 8
  sll   $t5, $t4, 8
  move  $a0, $s7
  or    $a2, $t2, $t3
  jal   check_set_actor_standing_still
   or    $a1, $t5, $t6
  beqz  $v0, .L7F035CEC
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 5($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F035CEC:
  addiu $s2, $s2, 6
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 6
action18_Shoot_Guard_ID_In_Style_With_Weapon_Type_num_4:
  move  $a0, $s7
  jal   get_handle_for_guard_id
   lbu   $a1, 1($s1)
  lui   $t8, %hi(D_80030A70) 
  addiu $t8, %lo(D_80030A70) # addiu $t8, $t8, 0xa70
  lw    $at, ($t8)
  addiu $t7, $sp, 0x6f4
  lw    $t1, 4($t8)
  sw    $at, ($t7)
  lw    $at, 8($t8)
  move  $a0, $v0
  sw    $t1, 4($t7)
  beqz  $v0, .L7F035D50
   sw    $at, 8($t7)
  lw    $t2, 0x18($v0)
  beql  $t2, $zero, .L7F035D54
   addiu $s2, $s2, 4
  lb    $a1, 2($s1)
  lbu   $a3, 3($s1)
  sw    $zero, 0x10($sp)
  jal   handles_shot_actors
   addiu $a2, $sp, 0x6f4
.L7F035D50:
  addiu $s2, $s2, 4
.L7F035D54:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
action19_Guard_ID1_Shoots_Guard_ID2_In_Style_4:
  move  $a0, $s7
  jal   get_handle_for_guard_id
   lbu   $a1, 1($s1)
  move  $s0, $v0
  move  $a0, $s7
  jal   get_handle_for_guard_id
   lbu   $a1, 2($s1)
  beqz  $s0, .L7F035E6C
   sw    $v0, 0x6e8($sp)
  beqz  $v0, .L7F035E6C
   move  $s3, $v0
  lw    $t3, 0x18($s0)
  beql  $t3, $zero, .L7F035E70
   addiu $s2, $s2, 4
  lw    $t4, 0x18($v0)
  move  $a0, $s0
  beql  $t4, $zero, .L7F035E70
   addiu $s2, $s2, 4
  jal   is_weapon_in_guarddata_hand
   move  $a1, $zero
  lui   $t6, %hi(D_80030A7C) 
  addiu $t6, %lo(D_80030A7C) # addiu $t6, $t6, 0xa7c
  lw    $at, ($t6)
  addiu $t5, $sp, 0x6d4
  lw    $t7, 4($t6)
  sw    $at, ($t5)
  lw    $at, 8($t6)
  move  $v1, $v0
  sw    $t7, 4($t5)
  bnez  $v0, .L7F035DE8
   sw    $at, 8($t5)
  move  $a0, $s0
  jal   is_weapon_in_guarddata_hand
   li    $a1, 1
  move  $v1, $v0
.L7F035DE8:
  beql  $v0, $zero, .L7F035E70
   addiu $s2, $s2, 4
  lw    $t8, 0x18($s3)
  lw    $t1, 0x18($s0)
  addiu $a0, $sp, 0x6d4
  lwc1  $f18, 8($t8)
  lwc1  $f4, 8($t1)
  addiu $a1, $sp, 0x6d8
  addiu $a2, $sp, 0x6dc
  sub.s $f6, $f18, $f4
  swc1  $f6, 0x6d4($sp)
  lw    $t3, 0x18($s0)
  lw    $t2, 0x18($s3)
  lwc1  $f10, 0xc($t3)
  lwc1  $f8, 0xc($t2)
  sub.s $f16, $f8, $f10
  swc1  $f16, 0x6d8($sp)
  lw    $t9, 0x18($s0)
  lw    $t4, 0x18($s3)
  lwc1  $f4, 0x10($t9)
  lwc1  $f18, 0x10($t4)
  sw    $v1, 0x6e4($sp)
  sub.s $f6, $f18, $f4
  jal   guNormalize
   swc1  $f6, 0x6dc($sp)
  lw    $v1, 0x6e4($sp)
  lb    $a1, 3($s1)
  move  $a0, $s3
  lw    $v0, 4($v1)
  addiu $a2, $sp, 0x6d4
  lb    $a3, 0x80($v0)
  jal   handles_shot_actors
   sw    $zero, 0x10($sp)
.L7F035E6C:
  addiu $s2, $s2, 4
.L7F035E70:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
action1A_Guard_Throws_Grenade_RVL_2:
  jal   actor_draws_throws_grenade_at_player_if_possible
   move  $a0, $s7
  beqz  $v0, .L7F035EA0
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F035EA0:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action1B_Drop_Weapon_Inventory_num_RVL_5:
  lbu   $t5, 1($s1)
  lbu   $t7, 2($s1)
  move  $a0, $s7
  sll   $t6, $t5, 8
  or    $v0, $t6, $t7
  andi  $a1, $v0, 0xffff
  jal   actor_drops_itemtype_setting_timer
   lbu   $a2, 3($s1)
  beqz  $v0, .L7F035EEC
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 4($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F035EEC:
  addiu $s2, $s2, 5
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 5
action21_Guard_Surrenders_1:
  jal   check_if_able_to_then_surrender
   move  $a0, $s7
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
action22_Guard_Set_To_Move_Fades_And_Disappear_1:
  jal   sub_GAME_7F0333A0
   move  $a0, $s7
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
action23_Eliminate_Guard_ID_2:
  move  $a0, $s7
  jal   get_handle_for_guard_id
   lbu   $a1, 1($s1)
  beqz  $v0, .L7F035F4C
   addiu $s2, $s2, 2
  lw    $t1, 0x18($v0)
  beqz  $t1, .L7F035F4C
   nop   
  lhu   $t2, 0x12($v0)
  ori   $t3, $t2, 0x20
  sh    $t3, 0x12($v0)
.L7F035F4C:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action24_Activate_Object_At_Preset_RVL_If_Successful_4:
  lbu   $t4, 1($s1)
  lbu   $t5, 2($s1)
  move  $a0, $s7
  sll   $t9, $t4, 8
  or    $v0, $t9, $t5
  jal   sub_GAME_7F034514
   andi  $a1, $v0, 0xffff
  beqz  $v0, .L7F035F90
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 3($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F035F90:
  addiu $s2, $s2, 4
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
action25_Sound_Alarm_1:
  jal   start_alarm
   nop   
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
action26_Turn_Off_Alarm_1:
  jal   stop_alarm
   nop   
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
action27_Return_False_Invalid_Type_2:
  jal   removed_animation_routine_27
   move  $a0, $s7
  beqz  $v0, .L7F035FEC
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F035FEC:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action28_Jog_To_Bond_Return_Loop_When_Reached_Bond_2:
  move  $a0, $s7
  jal   actor_move_to_curplayer_at_speed
   li    $a1, 1
  beqz  $v0, .L7F036024
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036024:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action29_Walk_To_Bond_Return_Loop_When_Reached_Bond_2:
  move  $a0, $s7
  jal   actor_move_to_curplayer_at_speed
   move  $a1, $zero
  beqz  $v0, .L7F03605C
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F03605C:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action2A_Run_To_Bond_Return_Loop_When_Reached_Bond_2:
  move  $a0, $s7
  jal   actor_move_to_curplayer_at_speed
   li    $a1, 2
  beqz  $v0, .L7F036094
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036094:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action2B_Return_False_Invalid_Type_2:
  jal   removed_animation_routine_2B
   move  $a0, $s7
  beqz  $v0, .L7F0360C8
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F0360C8:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action2C_Jog_To_Character_Position_RVL_On_Arrival_3:
  move  $a0, $s7
  lbu   $a1, 1($s1)
  jal   actor_move_to_actorID_at_speed
   li    $a2, 1
  beqz  $v0, .L7F036104
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036104:
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action2D_Walk_To_Character_Position_RVL_On_Arrival_3:
  move  $a0, $s7
  lbu   $a1, 1($s1)
  jal   actor_move_to_actorID_at_speed
   move  $a2, $zero
  beqz  $v0, .L7F036140
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036140:
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action2E_Run_To_Character_Position_RVL_On_Arrival_3:
  move  $a0, $s7
  lbu   $a1, 1($s1)
  jal   actor_move_to_actorID_at_speed
   li    $a2, 2
  beqz  $v0, .L7F03617C
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F03617C:
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action33_Seed_Random_Byte_1:
  jal   get_random_value
   nop   
  sb    $v0, 0x10f($s7)
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
action34_If_Seeded_Byte_LTV_Go_Into_RVL_3:
  lbu   $t8, 0x10f($s7)
  lbu   $t1, 1($s1)
  move  $a0, $s6
  move  $a1, $s2
  slt   $at, $t8, $t1
  beql  $at, $zero, .L7F0361D4
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F0361D4:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action35_If_Seeded_Byte_GTV_Go_Into_RVL_3:
  lbu   $t2, 1($s1)
  lbu   $t3, 0x10f($s7)
  move  $a0, $s6
  move  $a1, $s2
  slt   $at, $t2, $t3
  beql  $at, $zero, .L7F036210
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F036210:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action1C_Guard_Jogs_To_Preset_3:
  lbu   $t4, 1($s1)
  lbu   $t5, 2($s1)
  move  $a0, $s7
  sll   $t9, $t4, 8
  or    $v0, $t9, $t5
  andi  $a1, $v0, 0xffff
  jal   actor_moves_to_preset_at_speed
   li    $a2, 1
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action1D_Guard_Jogs_To_Predefined_Preset_2328_1:
  move  $a0, $s7
  lh    $a1, 0x114($s7)
  jal   actor_moves_to_preset_at_speed
   li    $a2, 1
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
action1E_Guard_Walks_To_Preset_3:
  lbu   $t7, 1($s1)
  lbu   $t1, 2($s1)
  move  $a0, $s7
  sll   $t8, $t7, 8
  or    $v0, $t8, $t1
  andi  $a1, $v0, 0xffff
  jal   actor_moves_to_preset_at_speed
   move  $a2, $zero
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action1F_Guard_Runs__To_Preset_3:
  lbu   $t3, 1($s1)
  lbu   $t9, 2($s1)
  move  $a0, $s7
  sll   $t4, $t3, 8
  or    $v0, $t4, $t9
  andi  $a1, $v0, 0xffff
  jal   actor_moves_to_preset_at_speed
   li    $a2, 2
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action20_Activate_Path_2:
  jal   get_ptr_path_for_pathnum
   lbu   $a0, 1($s1)
  move  $a0, $s7
  jal   if_actor_able_set_on_path
   move  $a1, $v0
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action36_If_Alarm_Activated_RVL_Plus_Stack_2:
  jal   alarm_timer_related
   move  $a0, $s7
  beqz  $v0, .L7F036300
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036300:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action37_If_Alarm_Activated_RVL_2:
  jal   is_alarm_on
   nop   
  beqz  $v0, .L7F036334
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036334:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action38_If_Toxic_Gas_Released_RVL_2:
  jal   check_if_toxic_gas_activated
   nop   
  beqz  $v0, .L7F036368
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036368:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action39_If_Guard_Heard_Gunfire_RVL_2:
  jal   check_if_actor_02_flag_set
   move  $a0, $s7
  beqz  $v0, .L7F03639C
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F03639C:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action3A_If_Bond_Shoots_Another_Guard_RVL_2:
  jal   check_if_actor_FA_target_set
   move  $a0, $s7
  beqz  $v0, .L7F0363D0
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F0363D0:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action3B_If_Guard_Killed_In_Front_Of_Guard_RVL_2:
  jal   check_if_actor_FB_target_set
   move  $a0, $s7
  beqz  $v0, .L7F036404
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036404:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action3C_If_Guard_In_Firing_Range_RVL_2:
  jal   sub_GAME_7F0294BC
   move  $a0, $s7
  beqz  $v0, .L7F036438
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036438:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action3D___Unused___Unknown___2:
  jal   sub_GAME_7F033DC4
   move  $a0, $s7
  beqz  $v0, .L7F03646C
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F03646C:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action3E_If_Shot_Current_Guard_RVL_2:
  jal   sub_GAME_7F032B68
   move  $a0, $s7
  beqz  $v0, .L7F0364A0
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F0364A0:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action3F_If_Heard_Bond_RVL_2:
  jal   sub_GAME_7F032BA0
   move  $a0, $s7
  beqz  $v0, .L7F0364D4
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F0364D4:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action40_If_Another_Guard_In_Same_Room_As_Guard_ID_RVL_3:
  move  $a0, $s7
  jal   get_handle_for_guard_id
   lbu   $a1, 1($s1)
  beql  $v0, $zero, .L7F036538
   addiu $s2, $s2, 3
  lw    $t6, 0x18($v0)
  beql  $t6, $zero, .L7F036538
   addiu $s2, $s2, 3
  lw    $v0, 0x18($v0)
  move  $a0, $s7
  addiu $a1, $v0, 8
  jal   check_if_position_in_same_room
   lw    $a2, 0x14($v0)
  beqz  $v0, .L7F036534
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036534:
  addiu $s2, $s2, 3
.L7F036538:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action41_If_Guard_Has_Been_On_Screen_RVL_2:
  lw    $t7, 0x14($s7)
  move  $a0, $s6
  move  $a1, $s2
  andi  $t8, $t7, 8
  bnezl $t8, .L7F036570
   addiu $s2, $s2, 2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 2
.L7F036570:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action42_If_Current_Guard_On_Screen_In_Loaded_Room_RVL_2:
  lw    $t1, 0x18($s7)
  move  $a0, $s6
  move  $a1, $s2
  lbu   $t2, 1($t1)
  andi  $t3, $t2, 2
  beql  $t3, $zero, .L7F0365AC
   addiu $s2, $s2, 2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 2
.L7F0365AC:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action43_If_Guard_In_A_Room_Currently_Loaded_RVL_2:
  lw    $t4, 0x18($s7)
  jal   sub_GAME_7F0B2FD8
   lw    $a0, 0x14($t4)
  jal   sub_GAME_7F0B5E50
   move  $a0, $v0
  beqz  $v0, .L7F0365E8
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F0365E8:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action44_If_Room_Containing_Preset_Is_Loaded_RVL_4:
  lbu   $t9, 1($s1)
  lbu   $t6, 2($s1)
  move  $a0, $s7
  sll   $t5, $t9, 8
  or    $v0, $t5, $t6
  jal   check_if_room_for_preset_loaded
   andi  $a1, $v0, 0xffff
  beqz  $v0, .L7F036630
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 3($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036630:
  addiu $s2, $s2, 4
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
action45_Go_To_RVL_If_Bond_Has_Guard_At_Gunpoint_2:
  jal   sub_GAME_7F0333F8
   move  $a0, $s7
  beqz  $v0, .L7F036664
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036664:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action46_If_Fired_A_Shot_RVL_2:
  jal   check_if_actor_invisible
   move  $a0, $s7
  beqz  $v0, .L7F036698
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036698:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action47_If_Distance_Between_Bond_And_Guard_LTV_RVL_3:
  jal   sub_GAME_7F032C4C
   move  $a0, $s7
  lbu   $t8, 1($s1)
  li    $at, 0x4F800000 # 4294967296.000000
  move  $a0, $s6
  mtc1  $t8, $f8
  move  $a1, $s2
  bgez  $t8, .L7F0366D4
   cvt.s.w $f10, $f8
  mtc1  $at, $f16
  nop   
  add.s $f10, $f10, $f16
.L7F0366D4:
  mul.s $f18, $f10, $f26
  li    $at, 0x3B800000 # 0.003906
  mtc1  $at, $f4
  nop   
  mul.s $f6, $f18, $f4
  c.lt.s $f0, $f6
  nop   
  bc1fl .L7F036710
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F036710:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action48_If_Distance_Between_Bond_And_Guard_GTV_RVL_3:
  jal   sub_GAME_7F032C4C
   move  $a0, $s7
  lbu   $t1, 1($s1)
  li    $at, 0x4F800000 # 4294967296.000000
  move  $a0, $s6
  mtc1  $t1, $f8
  move  $a1, $s2
  bgez  $t1, .L7F036748
   cvt.s.w $f16, $f8
  mtc1  $at, $f10
  nop   
  add.s $f16, $f16, $f10
.L7F036748:
  mul.s $f18, $f16, $f26
  li    $at, 0x3B800000 # 0.003906
  mtc1  $at, $f4
  nop   
  mul.s $f6, $f18, $f4
  c.lt.s $f6, $f0
  nop   
  bc1fl .L7F036784
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F036784:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action49_Test_if_Actor_and_Player_CCWAngle_LTV_RVL_Unused_3:
  jal   get_angle_between_actor_cur_player
   move  $a0, $s7
  lbu   $t2, 1($s1)
  li    $at, 0x4F800000 # 4294967296.000000
  move  $a0, $s6
  mtc1  $t2, $f8
  move  $a1, $s2
  bgez  $t2, .L7F0367BC
   cvt.s.w $f10, $f8
  mtc1  $at, $f16
  nop   
  add.s $f10, $f10, $f16
.L7F0367BC:
  mul.s $f18, $f10, $f26
  li    $at, 0x3B800000 # 0.003906
  mtc1  $at, $f4
  nop   
  mul.s $f6, $f18, $f4
  c.lt.s $f0, $f6
  nop   
  bc1fl .L7F0367F8
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F0367F8:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action4A_Test_if_Actor_and_Player_CCWAngle_GTV_RVL_Unused_3:
  jal   get_angle_between_actor_cur_player
   move  $a0, $s7
  lbu   $t3, 1($s1)
  li    $at, 0x4F800000 # 4294967296.000000
  move  $a0, $s6
  mtc1  $t3, $f8
  move  $a1, $s2
  bgez  $t3, .L7F036830
   cvt.s.w $f16, $f8
  mtc1  $at, $f10
  nop   
  add.s $f16, $f16, $f10
.L7F036830:
  mul.s $f18, $f16, $f26
  li    $at, 0x3B800000 # 0.003906
  mtc1  $at, $f4
  nop   
  mul.s $f6, $f18, $f4
  c.lt.s $f6, $f0
  nop   
  bc1fl .L7F03686C
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F03686C:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action4B_RVL_If_In_Proximity_Of_Bond_4:
  lbu   $t4, 1($s1)
  lbu   $t5, 2($s1)
  move  $a0, $s7
  sll   $t9, $t4, 8
  or    $t6, $t9, $t5
  mtc1  $t6, $f8
  nop   
  cvt.s.w $f10, $f8
  mul.s $f16, $f10, $f24
  jal   sub_GAME_7F032DE4
   swc1  $f16, 0x5fc($sp)
  lwc1  $f18, 0x5fc($sp)
  move  $a0, $s6
  move  $a1, $s2
  c.lt.s $f0, $f18
  nop   
  bc1fl .L7F0368D4
   addiu $s2, $s2, 4
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 3($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 4
.L7F0368D4:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
action4C_RVL_If_Not_In_Proximity_Of_Bond_4:
  lbu   $t7, 1($s1)
  lbu   $t1, 2($s1)
  move  $a0, $s7
  sll   $t8, $t7, 8
  or    $t2, $t8, $t1
  mtc1  $t2, $f4
  nop   
  cvt.s.w $f6, $f4
  mul.s $f8, $f6, $f24
  jal   sub_GAME_7F032DE4
   swc1  $f8, 0x5f4($sp)
  lwc1  $f10, 0x5f4($sp)
  move  $a0, $s6
  move  $a1, $s2
  c.lt.s $f10, $f0
  nop   
  bc1fl .L7F03693C
   addiu $s2, $s2, 4
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 3($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 4
.L7F03693C:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
action4D_When_Guard_In_Proximity_Of_Preset_RVL_7:
  move  $a0, $s7
  jal   get_handle_for_guard_id
   lbu   $a1, 1($s1)
  lbu   $t6, 2($s1)
  lbu   $t8, 3($s1)
  lbu   $t3, 4($s1)
  sll   $t7, $t6, 8
  or    $t1, $t7, $t8
  mtc1  $t1, $f16
  lbu   $t9, 5($s1)
  sll   $t4, $t3, 8
  cvt.s.w $f18, $f16
  or    $v1, $t4, $t9
  andi  $t5, $v1, 0xffff
  move  $a0, $v0
  move  $a1, $t5
  mul.s $f2, $f18, $f24
  beql  $v0, $zero, .L7F0369CC
   addiu $s2, $s2, 7
  jal   sub_GAME_7F032E48
   swc1  $f2, 0x5e4($sp)
  lwc1  $f2, 0x5e4($sp)
  move  $a0, $s6
  move  $a1, $s2
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F0369CC
   addiu $s2, $s2, 7
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 6($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 7
.L7F0369CC:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 7
action4E_When_Guard_Not_In_Proximity_Of_Preset_RVL_7:
  move  $a0, $s7
  jal   get_handle_for_guard_id
   lbu   $a1, 1($s1)
  lbu   $t5, 2($s1)
  lbu   $t7, 3($s1)
  lbu   $t2, 4($s1)
  sll   $t6, $t5, 8
  or    $t8, $t6, $t7
  mtc1  $t8, $f4
  lbu   $t4, 5($s1)
  sll   $t3, $t2, 8
  cvt.s.w $f6, $f4
  or    $v1, $t3, $t4
  andi  $t9, $v1, 0xffff
  move  $a0, $v0
  move  $a1, $t9
  mul.s $f2, $f6, $f24
  beql  $v0, $zero, .L7F036A5C
   addiu $s2, $s2, 7
  jal   sub_GAME_7F032E48
   swc1  $f2, 0x5d4($sp)
  lwc1  $f2, 0x5d4($sp)
  move  $a0, $s6
  move  $a1, $s2
  c.lt.s $f2, $f0
  nop   
  bc1fl .L7F036A5C
   addiu $s2, $s2, 7
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 6($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 7
.L7F036A5C:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 7
action4F_If_Current_Guard_Is_In_Units_Of_Guard_ID_RVL_5:
  lbu   $t1, 1($s1)
  lbu   $t3, 2($s1)
  move  $a0, $s7
  sll   $t2, $t1, 8
  or    $t4, $t2, $t3
  mtc1  $t4, $f8
  nop   
  cvt.s.w $f10, $f8
  mul.s $f16, $f10, $f24
  swc1  $f16, 0x5cc($sp)
  jal   get_distance_between_actor_and_actorID
   lbu   $a1, 3($s1)
  lwc1  $f18, 0x5cc($sp)
  move  $a0, $s6
  move  $a1, $s2
  c.lt.s $f0, $f18
  nop   
  bc1fl .L7F036AC8
   addiu $s2, $s2, 5
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 4($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 5
.L7F036AC8:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 5
action50_If_Current_Guard_Is_Not_In_Units_Of_Guard_ID_RVL_5:
  lbu   $t9, 1($s1)
  lbu   $t6, 2($s1)
  move  $a0, $s7
  sll   $t5, $t9, 8
  or    $t7, $t5, $t6
  mtc1  $t7, $f4
  nop   
  cvt.s.w $f6, $f4
  mul.s $f8, $f6, $f24
  swc1  $f8, 0x5c4($sp)
  jal   get_distance_between_actor_and_actorID
   lbu   $a1, 3($s1)
  lwc1  $f10, 0x5c4($sp)
  move  $a0, $s6
  move  $a1, $s2
  c.lt.s $f10, $f0
  nop   
  bc1fl .L7F036B34
   addiu $s2, $s2, 5
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 4($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 5
.L7F036B34:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 5
action51_SetClosestGuardUnitsGuardID_Then_RVL_IfSuccess_4:
  lbu   $t8, 1($s1)
  lbu   $t2, 2($s1)
  move  $a0, $s7
  sll   $t1, $t8, 8
  or    $t3, $t1, $t2
  mtc1  $t3, $f16
  nop   
  cvt.s.w $f18, $f16
  mul.s $f0, $f18, $f24
  mfc1  $a1, $f0
  jal   sub_GAME_7F033B38
   nop   
  beqz  $v0, .L7F036B8C
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 3($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036B8C:
  addiu $s2, $s2, 4
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
action52_GoIntoRVLIf_In_Units_Of_Preset_6:
  lbu   $t7, 1($s1)
  lbu   $t1, 2($s1)
  lbu   $t4, 3($s1)
  sll   $t8, $t7, 8
  or    $t2, $t8, $t1
  mtc1  $t2, $f4
  lbu   $t5, 4($s1)
  sll   $t9, $t4, 8
  cvt.s.w $f6, $f4
  or    $v0, $t9, $t5
  andi  $a1, $v0, 0xffff
  move  $a0, $s7
  mul.s $f8, $f6, $f24
  jal   get_distance_between_actor_and_preset
   swc1  $f8, 0x5b0($sp)
  lwc1  $f10, 0x5b0($sp)
  move  $a0, $s6
  move  $a1, $s2
  c.lt.s $f0, $f10
  nop   
  bc1fl .L7F036C08
   addiu $s2, $s2, 6
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 5($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 6
.L7F036C08:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 6
action53_GoIntoRVLIf_Not_In_Units_Of_Preset_6:
  lbu   $t6, 1($s1)
  lbu   $t8, 2($s1)
  lbu   $t3, 3($s1)
  sll   $t7, $t6, 8
  or    $t1, $t7, $t8
  mtc1  $t1, $f16
  lbu   $t9, 4($s1)
  sll   $t4, $t3, 8
  cvt.s.w $f18, $f16
  or    $v0, $t4, $t9
  andi  $a1, $v0, 0xffff
  move  $a0, $s7
  mul.s $f4, $f18, $f24
  jal   get_distance_between_actor_and_preset
   swc1  $f4, 0x5a4($sp)
  lwc1  $f6, 0x5a4($sp)
  move  $a0, $s6
  move  $a1, $s2
  c.lt.s $f6, $f0
  nop   
  bc1fl .L7F036C80
   addiu $s2, $s2, 6
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 5($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 6
.L7F036C80:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 6
action54_GoIntoRVLIf_Guard_Is_At_Preset_5:
  lbu   $t2, 2($s1)
  lbu   $t4, 3($s1)
  move  $a0, $s7
  sll   $t3, $t2, 8
  or    $v0, $t3, $t4
  andi  $a2, $v0, 0xffff
  jal   check_if_actorID_is_at_preset
   lbu   $a1, 1($s1)
  beqz  $v0, .L7F036CC8
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 4($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036CC8:
  addiu $s2, $s2, 5
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 5
action55_GoIntoRVLIf_Entered_Room_with_Preset_4:
  lbu   $t5, 1($s1)
  lbu   $t7, 2($s1)
  move  $a0, $s7
  sll   $t6, $t5, 8
  or    $v0, $t6, $t7
  jal   check_if_actor_is_at_preset
   andi  $a1, $v0, 0xffff
  beqz  $v0, .L7F036D10
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 3($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036D10:
  addiu $s2, $s2, 4
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
action56_GoIntoRVLIf_16_Object_num_Collected_3:
  jal   get_handle_to_tagged_object
   lbu   $a0, 1($s1)
  beql  $v0, $zero, .L7F036D64
   addiu $s2, $s2, 3
  lw    $t1, 0x10($v0)
  beql  $t1, $zero, .L7F036D64
   addiu $s2, $s2, 3
  jal   sub_GAME_7F08CFE0
   lw    $a0, 0x10($v0)
  beqz  $v0, .L7F036D60
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036D60:
  addiu $s2, $s2, 3
.L7F036D64:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action57_GoIntoRVLIf_Specified_Weapon_Deposited_3:
  jal   check_if_item_deposited
   lbu   $a0, 1($s1)
  beqz  $v0, .L7F036D94
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036D94:
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action58_GoIntoRVLIf_SpecifiedWeaponDeposited_On16Object_4:
  lbu   $a0, 2($s1)
  jal   get_handle_to_tagged_object
   move  $s0, $zero
  beqz  $v0, .L7F036E04
   move  $a1, $s2
  lw    $a0, 0x10($v0)
  beqz  $a0, .L7F036E04
   nop   
  lw    $v1, 0x20($a0)
  beqz  $v1, .L7F036E04
   nop   
  lbu   $t2, ($v1)
.L7F036DD0:
  li    $at, 4
  bnel  $t2, $at, .L7F036DFC
   lw    $v1, 0x24($v1)
  lw    $v0, 4($v1)
  lbu   $t3, 1($s1)
  lb    $t4, 0x80($v0)
  bnel  $t3, $t4, .L7F036DFC
   lw    $v1, 0x24($v1)
  b     .L7F036E04
   li    $s0, 1
  lw    $v1, 0x24($v1)
.L7F036DFC:
  bnezl $v1, .L7F036DD0
   lbu   $t2, ($v1)
.L7F036E04:
  beqz  $s0, .L7F036E20
   move  $a0, $s6
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 3($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036E20:
  addiu $s2, $s2, 4
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
action59_GoIntoRVLIf_Specified_Weapon_Is_Out_3:
  jal   get_item_in_hand
   move  $a0, $zero
  lbu   $t9, 1($s1)
  beql  $v0, $t9, .L7F036E54
   move  $a0, $s6
  jal   get_item_in_hand
   li    $a0, 1
  lbu   $t5, 1($s1)
  bne   $v0, $t5, .L7F036E6C
   move  $a0, $s6
.L7F036E54:
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036E6C:
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action5A_GoIntoRVLIf_Type_16_Object_num_Loaded_3:
  jal   get_handle_to_tagged_object
   lbu   $a0, 1($s1)
  beql  $v0, $zero, .L7F036EB4
   addiu $s2, $s2, 3
  lw    $t6, 0x10($v0)
  move  $a0, $s6
  move  $a1, $s2
  beql  $t6, $zero, .L7F036EB4
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F036EB4:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action5B_GoIntoRVLIf_16_Object_num_Not_Destroyed_3:
  jal   get_handle_to_tagged_object
   lbu   $a0, 1($s1)
  beqz  $v0, .L7F036F00
   move  $a0, $v0
  lw    $t7, 0x10($v0)
  beql  $t7, $zero, .L7F036F04
   addiu $s2, $s2, 3
  jal   check_if_object_has_not_been_destroyed
   nop   
  beqz  $v0, .L7F036F00
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F036F00:
  addiu $s2, $s2, 3
.L7F036F04:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action5C_GoIntoRVLIf_16_Object_num_Activated_3:
  jal   get_handle_to_tagged_object
   lbu   $a0, 1($s1)
  beql  $v0, $zero, .L7F036F68
   addiu $s2, $s2, 3
  lw    $t8, 0x10($v0)
  beql  $t8, $zero, .L7F036F68
   addiu $s2, $s2, 3
  lw    $t1, 0x64($v0)
  li    $at, -16385
  andi  $t2, $t1, 0x4000
  beql  $t2, $zero, .L7F036F68
   addiu $s2, $s2, 3
  lw    $t3, 0x64($v0)
  move  $a0, $s6
  move  $a1, $s2
  and   $t4, $t3, $at
  sw    $t4, 0x64($v0)
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F036F68:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action5D_GoIntoRVLIf_Gadget_Used_On_16_Object_num_3:
  jal   get_handle_to_tagged_object
   lbu   $a0, 1($s1)
  beql  $v0, $zero, .L7F036FC8
   addiu $s2, $s2, 3
  lw    $t9, 0x10($v0)
  beql  $t9, $zero, .L7F036FC8
   addiu $s2, $s2, 3
  lbu   $t5, 2($v0)
  andi  $t6, $t5, 0x40
  beql  $t6, $zero, .L7F036FC8
   addiu $s2, $s2, 3
  lbu   $t7, 2($v0)
  move  $a0, $s6
  move  $a1, $s2
  andi  $t8, $t7, 0xffbf
  sb    $t8, 2($v0)
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F036FC8:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action5E_16_Object_Activates_2:
  jal   get_handle_to_tagged_object
   lbu   $a0, 1($s1)
  beqz  $v0, .L7F03702C
   move  $a1, $v0
  lw    $a0, 0x10($v0)
  beql  $a0, $zero, .L7F037030
   addiu $s2, $s2, 2
  lbu   $v1, ($a0)
  li    $at, 2
  bnel  $v1, $at, .L7F037014
   li    $at, 1
  jal   sub_GAME_7F05599C
   lw    $a0, 0x10($v0)
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
  li    $at, 1
.L7F037014:
  beq   $v1, $at, .L7F037024
   li    $at, 4
  bnel  $v1, $at, .L7F037030
   addiu $s2, $s2, 2
.L7F037024:
  jal   sub_GAME_7F04F170
   lw    $a0, 0x10($a1)
.L7F03702C:
  addiu $s2, $s2, 2
.L7F037030:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action5F_16_Object_Explodes_2:
  jal   get_handle_to_tagged_object
   lbu   $a0, 1($s1)
  beqz  $v0, .L7F0370A8
   move  $s0, $v0
  lw    $t1, 0x10($v0)
  beql  $t1, $zero, .L7F0370AC
   addiu $s2, $s2, 2
  jal   do_something_if_object_destroyed
   move  $a0, $v0
  bnezl $v0, .L7F0370AC
   addiu $s2, $s2, 2
  lwc1  $f8, 0x74($s0)
  lwc1  $f10, 0x70($s0)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f18
  sub.s $f16, $f8, $f10
  li    $at, 0x437A0000 # 250.000000
  mtc1  $at, $f6
  li    $t2, -1
  add.s $f4, $f16, $f18
  sw    $t2, 0x10($sp)
  move  $a0, $s0
  addiu $a2, $s0, 0x58
  div.s $f0, $f4, $f6
  li    $a3, 29
  mfc1  $a1, $f0
  jal   maybe_detonate_object
   nop   
.L7F0370A8:
  addiu $s2, $s2, 2
.L7F0370AC:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action60_Guard_Drops_16_Object_num_2:
  jal   get_handle_to_tagged_object
   lbu   $a0, 1($s1)
  beqz  $v0, .L7F03710C
   move  $a2, $v0
  lw    $a0, 0x10($v0)
  beql  $a0, $zero, .L7F037110
   addiu $s2, $s2, 2
  lw    $v1, 0x1c($a0)
  beql  $v1, $zero, .L7F037110
   addiu $s2, $s2, 2
  lbu   $t3, ($v1)
  li    $at, 3
  bnel  $t3, $at, .L7F037110
   addiu $s2, $s2, 2
  lw    $a0, 0x10($v0)
  li    $a1, 2
  lw    $t4, 0x1c($a0)
  jal   sub_GAME_7F04BFD0
   lw    $s0, 4($t4)
  lhu   $t9, 0x12($s0)
  ori   $t5, $t9, 1
  sh    $t5, 0x12($s0)
.L7F03710C:
  addiu $s2, $s2, 2
.L7F037110:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action61_Kill_Guard_num_2:
  move  $a0, $s7
  jal   get_handle_for_guard_id
   lbu   $a1, 1($s1)
  beqz  $v0, .L7F037140
   move  $a0, $v0
  lw    $t6, 0x18($v0)
  beql  $t6, $zero, .L7F037144
   addiu $s2, $s2, 2
  jal   sub_GAME_7F021B20
   nop   
.L7F037140:
  addiu $s2, $s2, 2
.L7F037144:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action62_Guard_num_Throws_Equipment_2:
  move  $a0, $s7
  jal   get_handle_for_guard_id
   lbu   $a1, 1($s1)
  beqz  $v0, .L7F0371B0
   move  $s0, $v0
  lw    $t7, 0x18($v0)
  beql  $t7, $zero, .L7F0371B4
   addiu $s2, $s2, 2
  lw    $t8, 0x160($v0)
  li    $a1, 1
  beql  $t8, $zero, .L7F037194
   lw    $a0, 0x164($s0)
  jal   sub_GAME_7F04BFD0
   lw    $a0, 0x160($v0)
  lhu   $t1, 0x12($s0)
  ori   $t2, $t1, 1
  sh    $t2, 0x12($s0)
  lw    $a0, 0x164($s0)
.L7F037194:
  beql  $a0, $zero, .L7F0371B4
   addiu $s2, $s2, 2
  jal   sub_GAME_7F04BFD0
   li    $a1, 1
  lhu   $t3, 0x12($s0)
  ori   $t4, $t3, 1
  sh    $t4, 0x12($s0)
.L7F0371B0:
  addiu $s2, $s2, 2
.L7F0371B4:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action63_Guard_Gives_Bond_16_Object_num_2:
  jal   get_handle_to_tagged_object
   lbu   $a0, 1($s1)
  beqz  $v0, .L7F0371F0
   move  $s0, $v0
  lw    $t9, 0x10($v0)
  move  $a1, $zero
  beql  $t9, $zero, .L7F0371F4
   addiu $s2, $s2, 2
  jal   collect_or_interact_object
   lw    $a0, 0x10($v0)
  lw    $a0, 0x10($s0)
  jal   sub_GAME_7F03C2BC
   move  $a1, $v0
.L7F0371F0:
  addiu $s2, $s2, 2
.L7F0371F4:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action64_Type_16_Object_Equipped_On_Guard_3:
  jal   get_handle_to_tagged_object
   lbu   $a0, 1($s1)
  move  $s0, $v0
  move  $a0, $s7
  jal   get_handle_for_guard_id
   lbu   $a1, 2($s1)
  beqz  $s0, .L7F037294
   move  $s3, $v0
  lw    $a0, 0x10($s0)
  beql  $a0, $zero, .L7F037298
   addiu $s2, $s2, 3
  beql  $v0, $zero, .L7F037298
   addiu $s2, $s2, 3
  lw    $t5, 0x1c($a0)
  beqz  $t5, .L7F03724C
   nop   
  jal   sub_GAME_7F04C044
   nop   
  b     .L7F037268
   lbu   $t6, 3($s0)
.L7F03724C:
  jal   sub_GAME_7F03E18C
   nop   
  jal   sub_GAME_7F03A538
   lw    $a0, 0x10($s0)
  jal   unset_stateflag_0x04_for_posdata
   lw    $a0, 0x10($s0)
  lbu   $t6, 3($s0)
.L7F037268:
  li    $at, 8
  move  $a0, $s0
  bnel  $t6, $at, .L7F03728C
   lw    $a0, 0x10($s0)
  jal   sub_GAME_7F051E1C
   move  $a1, $s3
  bnezl $v0, .L7F037298
   addiu $s2, $s2, 3
  lw    $a0, 0x10($s0)
.L7F03728C:
  jal   sub_GAME_7F03A5A4
   lw    $a1, 0x18($s3)
.L7F037294:
  addiu $s2, $s2, 3
.L7F037298:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action65_Object_Moved_To_Preset_4:
  jal   get_handle_to_tagged_object
   lbu   $a0, 1($s1)
  sw    $v0, 0x500($sp)
  lbu   $t7, 2($s1)
  lbu   $t1, 3($s1)
  sll   $t8, $t7, 8
  or    $v1, $t8, $t1
  beqz  $v0, .L7F0373B0
   andi  $t2, $v1, 0xffff
  lw    $t3, 0x10($v0)
  move  $s3, $v0
  slti  $at, $t2, 0x2710
  beql  $t3, $zero, .L7F0373B4
   addiu $s2, $s2, 4
  beqz  $at, .L7F037304
   move  $v0, $t2
  sll   $t4, $t2, 2
  subu  $t4, $t4, $t2
  sll   $t4, $t4, 2
  lui   $t9, %hi(ptr_0xxxpresets) 
  lw    $t9, %lo(ptr_0xxxpresets)($t9)
  subu  $t4, $t4, $t2
  sll   $t4, $t4, 2
  b     .L7F037328
   addu  $s0, $t4, $t9
.L7F037304:
  lui   $t6, %hi(ptr_2xxxpresets) 
  lw    $t6, %lo(ptr_2xxxpresets)($t6)
  sll   $t5, $v0, 4
  addu  $t5, $t5, $v0
  sll   $t5, $t5, 2
  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
  addu  $s0, $t5, $t6
  addu  $s0, $s0, $at
.L7F037328:
  lwc1  $f8, 0x18($s0)
  mfc1  $a1, $f20
  mfc1  $a2, $f20
  neg.s $f10, $f8
  mfc1  $a3, $f20
  swc1  $f10, 0x10($sp)
  lwc1  $f16, 0x1c($s0)
  addiu $a0, $sp, 0x4b8
  neg.s $f18, $f16
  swc1  $f18, 0x14($sp)
  lwc1  $f4, 0x20($s0)
  neg.s $f6, $f4
  swc1  $f6, 0x18($sp)
  lwc1  $f8, 0xc($s0)
  swc1  $f8, 0x1c($sp)
  lwc1  $f10, 0x10($s0)
  swc1  $f10, 0x20($sp)
  lwc1  $f16, 0x14($s0)
  jal   sub_GAME_7F059908
   swc1  $f16, 0x24($sp)
  lw    $v0, 0x14($s3)
  addiu $a1, $sp, 0x4b8
  beql  $v0, $zero, .L7F037394
   lw    $a3, 0x28($s0)
  jal   matrix_multiply_A1_by_F12
   lwc1  $f12, 0x14($v0)
  lw    $a3, 0x28($s0)
.L7F037394:
  sw    $s0, 0x10($sp)
  move  $a0, $s3
  move  $a1, $s0
  jal   sub_GAME_7F04088C
   addiu $a2, $sp, 0x4b8
  jal   sub_GAME_7F056CA0
   move  $a0, $s3
.L7F0373B0:
  addiu $s2, $s2, 4
.L7F0373B4:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
action66_Open_Door_2:
  jal   get_handle_to_tagged_object
   lbu   $a0, 1($s1)
  beqz  $v0, .L7F0373F4
   move  $a2, $v0
  lw    $a0, 0x10($v0)
  beql  $a0, $zero, .L7F0373F8
   addiu $s2, $s2, 2
  lbu   $t7, ($a0)
  li    $at, 2
  move  $a0, $v0
  bnel  $t7, $at, .L7F0373F8
   addiu $s2, $s2, 2
  jal   set_door_state
   li    $a1, 1
.L7F0373F4:
  addiu $s2, $s2, 2
.L7F0373F8:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action67_Close_Door_2:
  jal   get_handle_to_tagged_object
   lbu   $a0, 1($s1)
  beqz  $v0, .L7F037438
   move  $a2, $v0
  lw    $a0, 0x10($v0)
  beql  $a0, $zero, .L7F03743C
   addiu $s2, $s2, 2
  lbu   $t8, ($a0)
  li    $at, 2
  move  $a0, $v0
  bnel  $t8, $at, .L7F03743C
   addiu $s2, $s2, 2
  jal   set_door_state
   li    $a1, 2
.L7F037438:
  addiu $s2, $s2, 2
.L7F03743C:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action68_Check_Door_Status_RVL_If_Met_4:
  lbu   $a0, 1($s1)
  jal   get_handle_to_tagged_object
   move  $s0, $zero
  beqz  $v0, .L7F0374F0
   move  $a0, $s6
  lw    $t1, 0x10($v0)
  beqz  $t1, .L7F0374F0
   nop   
  lbu   $t2, 3($v0)
  li    $at, 1
  bne   $t2, $at, .L7F0374F0
   nop   
  lb    $v1, 0xbc($v0)
  li    $at, 1
  bnez  $v1, .L7F0374B8
   nop   
  lwc1  $f18, 0xb4($v0)
  c.le.s $f18, $f20
  nop   
  bc1fl .L7F0374AC
   lbu   $s0, 2($s1)
  lbu   $s0, 2($s1)
  andi  $t3, $s0, 1
  b     .L7F0374F0
   sltu  $s0, $zero, $t3
  lbu   $s0, 2($s1)
.L7F0374AC:
  andi  $t9, $s0, 2
  b     .L7F0374F0
   sltu  $s0, $zero, $t9
.L7F0374B8:
  beq   $v1, $at, .L7F0374C8
   li    $at, 3
  bnel  $v1, $at, .L7F0374DC
   li    $at, 2
.L7F0374C8:
  lbu   $s0, 2($s1)
  andi  $t6, $s0, 8
  b     .L7F0374F0
   sltu  $s0, $zero, $t6
  li    $at, 2
.L7F0374DC:
  bne   $v1, $at, .L7F0374F0
   nop   
  lbu   $s0, 2($s1)
  andi  $t8, $s0, 4
  sltu  $s0, $zero, $t8
.L7F0374F0:
  beqz  $s0, .L7F03750C
   move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 3($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F03750C:
  addiu $s2, $s2, 4
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
action69_If_16_Object_Is_Valid_Door_RVL_3:
  jal   get_handle_to_tagged_object
   lbu   $a0, 1($s1)
  beql  $v0, $zero, .L7F037574
   addiu $s2, $s2, 3
  lw    $t2, 0x10($v0)
  beql  $t2, $zero, .L7F037574
   addiu $s2, $s2, 3
  lbu   $t3, 3($v0)
  li    $at, 1
  bnel  $t3, $at, .L7F037574
   addiu $s2, $s2, 3
  lw    $t4, 0x64($v0)
  move  $a0, $s6
  move  $a1, $s2
  andi  $t9, $t4, 0x200
  beql  $t9, $zero, .L7F037574
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F037574:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action6A_Set_Bits_To_Lock_On_Type_16_Door_3:
  jal   get_handle_to_tagged_object
   lbu   $a0, 1($s1)
  beqz  $v0, .L7F0375B8
   addiu $s2, $s2, 3
  lw    $a0, 0x10($v0)
  beqz  $a0, .L7F0375B8
   nop   
  lbu   $t5, ($a0)
  li    $at, 2
  bne   $t5, $at, .L7F0375B8
   nop   
  lbu   $v1, 2($s1)
  lw    $t6, 0x9c($v0)
  or    $t7, $t6, $v1
  sw    $t7, 0x9c($v0)
.L7F0375B8:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action6B_Unset_Bits_To_Lock_On_Type_16_Door_3:
  jal   get_handle_to_tagged_object
   lbu   $a0, 1($s1)
  beqz  $v0, .L7F037600
   addiu $s2, $s2, 3
  lw    $a0, 0x10($v0)
  beqz  $a0, .L7F037600
   nop   
  lbu   $t8, ($a0)
  li    $at, 2
  bne   $t8, $at, .L7F037600
   nop   
  lbu   $v1, 2($s1)
  lw    $t1, 0x9c($v0)
  not   $t2, $v1
  and   $t3, $t1, $t2
  sw    $t3, 0x9c($v0)
.L7F037600:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action6C_If_Tagged_Locked_Door_16_Objects_Toggled_RVL_4:
  lbu   $a0, 1($s1)
  jal   get_handle_to_tagged_object
   move  $s0, $zero
  beqz  $v0, .L7F037650
   move  $a1, $s2
  lw    $a0, 0x10($v0)
  beqz  $a0, .L7F037650
   nop   
  lbu   $t4, ($a0)
  li    $at, 2
  bne   $t4, $at, .L7F037650
   nop   
  lbu   $v1, 2($s1)
  lw    $t9, 0x9c($v0)
  and   $t5, $t9, $v1
  bne   $v1, $t5, .L7F037650
   nop   
  li    $s0, 1
.L7F037650:
  beqz  $s0, .L7F03766C
   move  $a0, $s6
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 3($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F03766C:
  addiu $s2, $s2, 4
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
action6D_If_Objective_num_Complete_RVL_3:
  jal   add_objective
   nop   
  lbu   $a1, 1($s1)
  slt   $at, $a1, $v0
  beql  $at, $zero, .L7F0376C0
   addiu $s2, $s2, 3
  jal   get_status_of_objective
   move  $a0, $a1
  li    $at, 1
  bne   $v0, $at, .L7F0376BC
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F0376BC:
  addiu $s2, $s2, 3
.L7F0376C0:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action6E_If_Guard_2328_Preset_RVL_3:
  move  $a0, $s7
  jal   check_2328_preset_set_with_method
   lbu   $a1, 1($s1)
  beqz  $v0, .L7F0376F4
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F0376F4:
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action6F_If_Guard_2328_Preset_Set_RVL_3:
  move  $a0, $s7
  jal   sub_GAME_7F033AAC
   lbu   $a1, 1($s1)
  beqz  $v0, .L7F03772C
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F03772C:
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action78_Go_To_RVL_If_Guard_Shot_LTV_3:
  jal   get_times_actor_shot
   move  $a0, $s7
  lbu   $t6, 1($s1)
  move  $a0, $s6
  move  $a1, $s2
  slt   $at, $v0, $t6
  beql  $at, $zero, .L7F037770
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F037770:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action79_Go_To_RVL_If_Guard_Shot_GTV_3:
  jal   get_times_actor_shot
   move  $a0, $s7
  lbu   $t7, 1($s1)
  move  $a0, $s6
  move  $a1, $s2
  slt   $at, $t7, $v0
  beql  $at, $zero, .L7F0377B0
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F0377B0:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action7A_Go_To_RVL_If_Number_Near_Miss_Gunshots_LTV_3:
  jal   get_num_shots_near_actor
   move  $a0, $s7
  lbu   $t8, 1($s1)
  move  $a0, $s6
  move  $a1, $s2
  slt   $at, $v0, $t8
  beql  $at, $zero, .L7F0377F0
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F0377F0:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action7B_Go_To_RVL_If_Number_Near_Miss_Gunshots_GTV_3:
  jal   get_num_shots_near_actor
   move  $a0, $s7
  lbu   $t1, 1($s1)
  move  $a0, $s6
  move  $a1, $s2
  slt   $at, $t1, $v0
  beql  $at, $zero, .L7F037830
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F037830:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action7C_If_Guard_Health_Below_Value_RVL_4:
  lbu   $t2, 2($s1)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t2, $f4
  bgez  $t2, .L7F037858
   cvt.s.w $f6, $f4
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F037858:
  lui   $at, %hi(D_800528EC)
  lwc1  $f10, %lo(D_800528EC)($at)
  move  $a0, $s7
  mul.s $f16, $f6, $f10
  swc1  $f16, 0x438($sp)
  jal   get_handle_for_guard_id
   lbu   $a1, 1($s1)
  beql  $v0, $zero, .L7F0378BC
   addiu $s2, $s2, 4
  lwc1  $f18, 0x100($v0)
  lwc1  $f4, 0xfc($v0)
  lwc1  $f6, 0x438($sp)
  move  $a0, $s6
  sub.s $f8, $f18, $f4
  move  $a1, $s2
  c.lt.s $f8, $f6
  nop   
  bc1fl .L7F0378BC
   addiu $s2, $s2, 4
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 3($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 4
.L7F0378BC:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
action7D_If_Guard_Health_Above_Value_RVL_4:
  lbu   $t3, 2($s1)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t3, $f10
  bgez  $t3, .L7F0378E4
   cvt.s.w $f16, $f10
  mtc1  $at, $f18
  nop   
  add.s $f16, $f16, $f18
.L7F0378E4:
  lui   $at, %hi(D_800528F0)
  lwc1  $f4, %lo(D_800528F0)($at)
  move  $a0, $s7
  mul.s $f8, $f16, $f4
  swc1  $f8, 0x42c($sp)
  jal   get_handle_for_guard_id
   lbu   $a1, 1($s1)
  beql  $v0, $zero, .L7F037948
   addiu $s2, $s2, 4
  lwc1  $f10, 0x100($v0)
  lwc1  $f18, 0xfc($v0)
  lwc1  $f6, 0x42c($sp)
  move  $a0, $s6
  sub.s $f16, $f10, $f18
  move  $a1, $s2
  c.lt.s $f6, $f16
  nop   
  bc1fl .L7F037948
   addiu $s2, $s2, 4
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 3($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 4
.L7F037948:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
action7E_If_Guard_nums_Bitflag_01000000_Set_RVL_3:
  move  $a0, $s7
  jal   get_handle_for_guard_id
   lbu   $a1, 1($s1)
  beql  $v0, $zero, .L7F0379A4
   addiu $s2, $s2, 3
  lw    $t4, 0x14($v0)
  li    $at, -257
  andi  $t9, $t4, 0x100
  beql  $t9, $zero, .L7F0379A4
   addiu $s2, $s2, 3
  lw    $t5, 0x14($v0)
  move  $a0, $s6
  move  $a1, $s2
  and   $t6, $t5, $at
  sw    $t6, 0x14($v0)
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F0379A4:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action7F_If_Health_Below_Value_RVL_3:
  lbu   $t7, 1($s1)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t7, $f4
  bgez  $t7, .L7F0379CC
   cvt.s.w $f8, $f4
  mtc1  $at, $f10
  nop   
  add.s $f8, $f8, $f10
.L7F0379CC:
  li    $at, 0x437F0000 # 255.000000
  mtc1  $at, $f18
  nop   
  div.s $f6, $f8, $f18
  jal   get_BONDdata_watch_health
   swc1  $f6, 0x418($sp)
  lwc1  $f16, 0x418($sp)
  move  $a0, $s6
  move  $a1, $s2
  c.lt.s $f0, $f16
  nop   
  bc1fl .L7F037A18
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F037A18:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action80_If_Health_Above_Value_RVL_3:
  lbu   $t8, 1($s1)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t8, $f4
  bgez  $t8, .L7F037A40
   cvt.s.w $f10, $f4
  mtc1  $at, $f8
  nop   
  add.s $f10, $f10, $f8
.L7F037A40:
  li    $at, 0x437F0000 # 255.000000
  mtc1  $at, $f18
  nop   
  div.s $f6, $f10, $f18
  jal   get_BONDdata_watch_health
   swc1  $f6, 0x410($sp)
  lwc1  $f16, 0x410($sp)
  move  $a0, $s6
  move  $a1, $s2
  c.lt.s $f16, $f0
  nop   
  bc1fl .L7F037A8C
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F037A8C:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action70_Go_Into_RVL_Difficulty_LTV_3:
  jal   get_current_difficulty
   nop   
  lbu   $t1, 1($s1)
  move  $a0, $s6
  move  $a1, $s2
  slt   $at, $v0, $t1
  beql  $at, $zero, .L7F037ACC
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F037ACC:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action71_GoIntoRVLIf_Difficulty_GTV_3:
  jal   get_current_difficulty
   nop   
  lbu   $t2, 1($s1)
  move  $a0, $s6
  move  $a1, $s2
  slt   $at, $t2, $v0
  beql  $at, $zero, .L7F037B0C
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F037B0C:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action72_Go_To_RVL_If_Time_LTV_4:
  lbu   $t3, 1($s1)
  lbu   $t9, 2($s1)
  sll   $t4, $t3, 8
  or    $t5, $t4, $t9
  mtc1  $t5, $f4
  nop   
  cvt.s.w $f8, $f4
  jal   get_cur_mp_sec
   swc1  $f8, 0x400($sp)
  lwc1  $f10, 0x400($sp)
  move  $a0, $s6
  move  $a1, $s2
  c.lt.s $f0, $f10
  nop   
  bc1fl .L7F037B6C
   addiu $s2, $s2, 4
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 3($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 4
.L7F037B6C:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
action73_Go_To_RVL_If_Time_GTV_4:
  lbu   $t6, 1($s1)
  lbu   $t8, 2($s1)
  sll   $t7, $t6, 8
  or    $t1, $t7, $t8
  mtc1  $t1, $f18
  nop   
  cvt.s.w $f6, $f18
  jal   get_cur_mp_sec
   swc1  $f6, 0x3f8($sp)
  lwc1  $f16, 0x3f8($sp)
  move  $a0, $s6
  move  $a1, $s2
  c.lt.s $f16, $f0
  nop   
  bc1fl .L7F037BCC
   addiu $s2, $s2, 4
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 3($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 4
.L7F037BCC:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
action74_Go_To_RVL_If_Power_On_Time_LTV_4:
  lbu   $t2, 1($s1)
  lbu   $t4, 2($s1)
  sll   $t3, $t2, 8
  or    $t9, $t3, $t4
  mtc1  $t9, $f4
  nop   
  cvt.s.w $f8, $f4
  mul.s $f10, $f8, $f22
  jal   get_cur_mp_min
   swc1  $f10, 0x3f0($sp)
  lwc1  $f18, 0x3f0($sp)
  move  $a0, $s6
  move  $a1, $s2
  c.lt.s $f0, $f18
  nop   
  bc1fl .L7F037C30
   addiu $s2, $s2, 4
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 3($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 4
.L7F037C30:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
action75_Go_To_RVL_If_Power_On_Time_GTV_4:
  lbu   $t5, 1($s1)
  lbu   $t7, 2($s1)
  sll   $t6, $t5, 8
  or    $t8, $t6, $t7
  mtc1  $t8, $f6
  nop   
  cvt.s.w $f16, $f6
  mul.s $f4, $f16, $f22
  jal   get_cur_mp_min
   swc1  $f4, 0x3e8($sp)
  lwc1  $f8, 0x3e8($sp)
  move  $a0, $s6
  move  $a1, $s2
  c.lt.s $f8, $f0
  nop   
  bc1fl .L7F037C94
   addiu $s2, $s2, 4
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 3($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 4
.L7F037C94:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
action76_Go_To_RVL_If_Stage_Number_LTV_3:
  jal   get_stage_num
   nop   
  lbu   $t1, 1($s1)
  move  $a0, $s6
  move  $a1, $s2
  slt   $at, $v0, $t1
  beql  $at, $zero, .L7F037CD4
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F037CD4:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action77_Go_To_RVL_If_Stage_Number_GTV_3:
  jal   get_stage_num
   nop   
  lbu   $t2, 1($s1)
  move  $a0, $s6
  move  $a1, $s2
  slt   $at, $t2, $v0
  beql  $at, $zero, .L7F037D14
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F037D14:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action81_Set_User_Byte_num1_2:
  lbu   $t3, 1($s1)
  addiu $s2, $s2, 2
  addiu $s1, $s1, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   sb    $t3, 0x10c($s7)
action82_Add_Value_To_User_Byte_num1_Max_To_FF_2:
  lbu   $a1, 1($s1)
  lbu   $v0, 0x10c($s7)
  li    $t4, 255
  subu  $t9, $t4, $a1
  slt   $at, $t9, $v0
  beqz  $at, .L7F037D60
   addu  $t6, $v0, $a1
  li    $t5, 255
  sb    $t5, 0x10c($s7)
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
.L7F037D60:
  sb    $t6, 0x10c($s7)
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action83_Subtract_Value_To_User_Byte_num1_Min_To_0_2:
  lbu   $v0, 0x10c($s7)
  lbu   $a1, 1($s1)
  slt   $at, $v0, $a1
  beqz  $at, .L7F037D94
   subu  $t7, $v0, $a1
  sb    $zero, 0x10c($s7)
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
.L7F037D94:
  sb    $t7, 0x10c($s7)
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action84_If_Value_GreaterThan_User_Byte_num1_RVL_3:
  lbu   $t8, 0x10c($s7)
  lbu   $t1, 1($s1)
  move  $a0, $s6
  move  $a1, $s2
  slt   $at, $t8, $t1
  beql  $at, $zero, .L7F037DD8
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F037DD8:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action85_If_User_Byte_num1_LessThan_Random_Value_RVL_2:
  lbu   $t2, 0x10c($s7)
  lbu   $t3, 0x10f($s7)
  move  $a0, $s6
  move  $a1, $s2
  slt   $at, $t2, $t3
  beql  $at, $zero, .L7F037E14
   addiu $s2, $s2, 2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 2
.L7F037E14:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action86_Set_User_Byte_num2_2:
  lbu   $t4, 1($s1)
  addiu $s2, $s2, 2
  addiu $s1, $s1, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   sb    $t4, 0x10d($s7)
action87_Add_Value_To_User_Byte_num2_Max_To_FF_2:
  lbu   $a1, 1($s1)
  lbu   $v0, 0x10d($s7)
  li    $t9, 255
  subu  $t5, $t9, $a1
  slt   $at, $t5, $v0
  beqz  $at, .L7F037E60
   addu  $t7, $v0, $a1
  li    $t6, 255
  sb    $t6, 0x10d($s7)
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
.L7F037E60:
  sb    $t7, 0x10d($s7)
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action88_Subtract_Value_To_User_Byte_num2_Min_To_0_2:
  lbu   $v0, 0x10d($s7)
  lbu   $a1, 1($s1)
  slt   $at, $v0, $a1
  beqz  $at, .L7F037E94
   subu  $t8, $v0, $a1
  sb    $zero, 0x10d($s7)
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
.L7F037E94:
  sb    $t8, 0x10d($s7)
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action89_If_Value_GreaterThan_User_Byte_num2_RVL_3:
  lbu   $t1, 0x10d($s7)
  lbu   $t2, 1($s1)
  move  $a0, $s6
  move  $a1, $s2
  slt   $at, $t1, $t2
  beql  $at, $zero, .L7F037ED8
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F037ED8:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action8A_If_User_Byte_num2_LessThan_Random_Value_RVL_2:
  lbu   $t3, 0x10d($s7)
  lbu   $t4, 0x10f($s7)
  move  $a0, $s6
  move  $a1, $s2
  slt   $at, $t3, $t4
  beql  $at, $zero, .L7F037F14
   addiu $s2, $s2, 2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 2
.L7F037F14:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action8B_Set_Guard_Hearing_Distance_3:
  lbu   $t9, 1($s1)
  lbu   $t6, 2($s1)
  li    $at, 0x447A0000 # 1000.000000
  sll   $t5, $t9, 8
  or    $t7, $t5, $t6
  mtc1  $t7, $f10
  mtc1  $at, $f6
  addiu $s2, $s2, 3
  cvt.s.w $f18, $f10
  addiu $s1, $s1, 3
  div.s $f0, $f18, $f6
  b     GetByteS1_ParseCommandByte_SwitchCase
   swc1  $f0, 0xec($s7)
action8C_Set_Guard_Visible_Distance_2:
  lbu   $t8, 1($s1)
  li    $at, 0x4F800000 # 4294967296.000000
  addiu $s2, $s2, 2
  mtc1  $t8, $f16
  addiu $s1, $s1, 2
  bgez  $t8, .L7F037F78
   cvt.s.w $f4, $f16
  mtc1  $at, $f8
  nop   
  add.s $f4, $f4, $f8
.L7F037F78:
  b     GetByteS1_ParseCommandByte_SwitchCase
   swc1  $f4, 0xd0($s7)
action8D_Set_Guard_Grenade_Probability_2:
  lbu   $t1, 1($s1)
  addiu $s2, $s2, 2
  addiu $s1, $s1, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   sb    $t1, 0x10($s7)
action8E_Set_Guard_ID_2:
  lbu   $t2, 1($s1)
  addiu $s2, $s2, 2
  addiu $s1, $s1, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   sh    $t2, ($s7)
action8F_Set_Guard_Health_3:
  lbu   $t3, 1($s1)
  lbu   $t9, 2($s1)
  lui   $at, %hi(D_800528F4)
  sll   $t4, $t3, 8
  or    $t5, $t4, $t9
  mtc1  $t5, $f10
  lwc1  $f6, %lo(D_800528F4)($at)
  move  $a0, $s7
  cvt.s.w $f18, $f10
  mul.s $f0, $f18, $f6
  mfc1  $a1, $f0
  jal   sub_GAME_7F020018
   nop   
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action90_Set_Guard_Armor_Amount_3:
  lbu   $t6, 1($s1)
  lbu   $t8, 2($s1)
  lui   $at, %hi(D_800528F8)
  sll   $t7, $t6, 8
  or    $t1, $t7, $t8
  mtc1  $t1, $f16
  lwc1  $f4, %lo(D_800528F8)($at)
  move  $a0, $s7
  cvt.s.w $f8, $f16
  mul.s $f0, $f8, $f4
  mfc1  $a1, $f0
  jal   sub_GAME_7F020054
   nop   
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action91_Set_Character_Reaction_Speed_2:
  lb    $t2, 1($s1)
  addiu $s2, $s2, 2
  addiu $s1, $s1, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   sb    $t2, 3($s7)
action92_Set_Character_Injury_Recovery_Speed_2:
  lb    $t3, 1($s1)
  addiu $s2, $s2, 2
  addiu $s1, $s1, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   sb    $t3, 0xd($s7)
action93_Set_Character_Accuracy_2:
  lb    $t4, 1($s1)
  addiu $s2, $s2, 2
  addiu $s1, $s1, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   sb    $t4, 2($s7)
action94_Mask_Guard_Type_With_Value_2:
  move  $a0, $s7
  jal   sub_GAME_7F033218
   lbu   $a1, 1($s1)
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action95_Unmask_Guard_Type_With_Value_2:
  move  $a0, $s7
  jal   sub_GAME_7F03322C
   lbu   $a1, 1($s1)
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
action96_If_Guard_Type_Value_Is_Set_RVL_3:
  move  $a0, $s7
  jal   sub_GAME_7F033244
   lbu   $a1, 1($s1)
  beqz  $v0, .L7F0380C0
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F0380C0:
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action97_Mask_Guard_Type_Flags_With_Value_3:
  move  $a0, $s7
  lbu   $a1, 1($s1)
  jal   sub_GAME_7F033260
   lbu   $a2, 2($s1)
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action98_Unmask_Guard_Type_Flags_With_Value_3:
  move  $a0, $s7
  lbu   $a1, 1($s1)
  jal   sub_GAME_7F033290
   lbu   $a2, 2($s1)
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
action99_If_Guard_Type_Flags_Set_RVL_4:
  move  $a0, $s7
  lbu   $a1, 1($s1)
  jal   sub_GAME_7F0332C0
   lbu   $a2, 2($s1)
  beqz  $v0, .L7F038134
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 3($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F038134:
  addiu $s2, $s2, 4
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
action9A_Set_Objective_Bits_5:
  lbu   $t9, 1($s1)
  lbu   $t6, 2($s1)
  lbu   $t1, 3($s1)
  sll   $t5, $t9, 0x18
  sll   $t7, $t6, 0x10
  lbu   $t4, 4($s1)
  or    $t8, $t5, $t7
  sll   $t2, $t1, 8
  or    $t3, $t8, $t2
  move  $a0, $s7
  jal   toggle_objective_bitflags
   or    $a1, $t3, $t4
  addiu $s2, $s2, 5
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 5
action9B_Unset_Objective_Value_5:
  lbu   $t9, 1($s1)
  lbu   $t5, 2($s1)
  lbu   $t8, 3($s1)
  sll   $t6, $t9, 0x18
  sll   $t7, $t5, 0x10
  lbu   $t4, 4($s1)
  or    $t1, $t6, $t7
  sll   $t2, $t8, 8
  or    $t3, $t1, $t2
  move  $a0, $s7
  jal   untoggle_objective_bitflags
   or    $a1, $t3, $t4
  addiu $s2, $s2, 5
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 5
action9C_Check_If_Objective_Value_Return_Loop_If_So_6:
  lbu   $t9, 1($s1)
  lbu   $t6, 2($s1)
  lbu   $t1, 3($s1)
  sll   $t5, $t9, 0x18
  sll   $t7, $t6, 0x10
  lbu   $t4, 4($s1)
  or    $t8, $t5, $t7
  sll   $t2, $t1, 8
  or    $t3, $t8, $t2
  move  $a0, $s7
  jal   check_if_objective_bitflags_set
   or    $a1, $t3, $t4
  beqz  $v0, .L7F038208
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 5($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F038208:
  addiu $s2, $s2, 6
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 6
action9D_Set_Guard_Bit_Tags_5:
  lbu   $t9, 1($s1)
  lbu   $t5, 2($s1)
  lbu   $t8, 3($s1)
  sll   $t6, $t9, 0x18
  lbu   $t4, 4($s1)
  sll   $t7, $t5, 0x10
  lw    $t9, 0x14($s7)
  or    $t1, $t6, $t7
  sll   $t2, $t8, 8
  or    $t3, $t1, $t2
  or    $v0, $t3, $t4
  or    $t5, $t9, $v0
  sw    $t5, 0x14($s7)
  addiu $s2, $s2, 5
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 5
action9E_Unset_Guard_Bit_Tags_5:
  lbu   $t6, 1($s1)
  lbu   $t8, 2($s1)
  lbu   $t3, 3($s1)
  lbu   $t5, 4($s1)
  sll   $t7, $t6, 0x18
  sll   $t1, $t8, 0x10
  or    $t2, $t7, $t1
  sll   $t4, $t3, 8
  lw    $t6, 0x14($s7)
  or    $t9, $t2, $t4
  or    $v0, $t9, $t5
  not   $t8, $v0
  and   $t7, $t6, $t8
  sw    $t7, 0x14($s7)
  addiu $s2, $s2, 5
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 5
action9F_Check_Guard_Bits_If_Same_RVL_6:
  lbu   $t1, 1($s1)
  lbu   $t2, 2($s1)
  lbu   $t5, 3($s1)
  sll   $t3, $t1, 0x18
  lbu   $t7, 4($s1)
  sll   $t4, $t2, 0x10
  lw    $t1, 0x14($s7)
  or    $t9, $t3, $t4
  sll   $t6, $t5, 8
  or    $t8, $t9, $t6
  or    $v0, $t8, $t7
  and   $t2, $t1, $v0
  bne   $v0, $t2, .L7F0382E8
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 5($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F0382E8:
  addiu $s2, $s2, 6
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 6
actionA0_Set_Guard_ID_Bits_6:
  lbu   $t3, 2($s1)
  lbu   $t5, 3($s1)
  lbu   $t8, 4($s1)
  sll   $t4, $t3, 0x18
  sll   $t9, $t5, 0x10
  lbu   $t2, 5($s1)
  or    $t6, $t4, $t9
  sll   $t7, $t8, 8
  or    $t1, $t6, $t7
  move  $a0, $s7
  lbu   $a1, 1($s1)
  jal   get_handle_for_guard_id
   or    $s0, $t1, $t2
  beqz  $v0, .L7F03833C
   addiu $s2, $s2, 6
  lw    $t3, 0x14($v0)
  or    $t5, $t3, $s0
  sw    $t5, 0x14($v0)
.L7F03833C:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 6
actionA1_Unset_Guard_ID_Bits_6:
  lbu   $t4, 2($s1)
  lbu   $t8, 3($s1)
  lbu   $t1, 4($s1)
  sll   $t9, $t4, 0x18
  sll   $t6, $t8, 0x10
  lbu   $t5, 5($s1)
  or    $t7, $t9, $t6
  sll   $t2, $t1, 8
  or    $t3, $t7, $t2
  move  $a0, $s7
  lbu   $a1, 1($s1)
  jal   get_handle_for_guard_id
   or    $s0, $t3, $t5
  beqz  $v0, .L7F038390
   addiu $s2, $s2, 6
  lw    $t4, 0x14($v0)
  not   $t8, $s0
  and   $t9, $t4, $t8
  sw    $t9, 0x14($v0)
.L7F038390:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 6
actionA2_Check_Guard_Bits_If_Same_RVL_7:
  lbu   $t6, 2($s1)
  lbu   $t7, 3($s1)
  lbu   $t5, 4($s1)
  sll   $t1, $t6, 0x18
  sll   $t2, $t7, 0x10
  lbu   $t9, 5($s1)
  or    $t3, $t1, $t2
  sll   $t4, $t5, 8
  or    $t8, $t3, $t4
  move  $a0, $s7
  lbu   $a1, 1($s1)
  jal   get_handle_for_guard_id
   or    $s0, $t8, $t9
  beql  $v0, $zero, .L7F038404
   addiu $s2, $s2, 7
  lw    $t6, 0x14($v0)
  move  $a0, $s6
  move  $a1, $s2
  and   $t7, $t6, $s0
  bnel  $s0, $t7, .L7F038404
   addiu $s2, $s2, 7
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 6($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 7
.L7F038404:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 7
actionA3_Set_State_Bits_16_Type_Object_6:
  lbu   $t1, 2($s1)
  lbu   $t5, 3($s1)
  lbu   $t8, 4($s1)
  sll   $t2, $t1, 0x18
  sll   $t3, $t5, 0x10
  lbu   $t7, 5($s1)
  or    $t4, $t2, $t3
  sll   $t9, $t8, 8
  or    $t6, $t4, $t9
  lbu   $a0, 1($s1)
  jal   get_handle_to_tagged_object
   or    $s0, $t6, $t7
  beqz  $v0, .L7F03845C
   addiu $s2, $s2, 6
  lw    $t1, 0x10($v0)
  beqz  $t1, .L7F03845C
   nop   
  lw    $t5, 8($v0)
  or    $t2, $t5, $s0
  sw    $t2, 8($v0)
.L7F03845C:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 6
actionA4_Unset_State_Bits_16_Type_Object_6:
  lbu   $t3, 2($s1)
  lbu   $t4, 3($s1)
  lbu   $t7, 4($s1)
  sll   $t8, $t3, 0x18
  sll   $t9, $t4, 0x10
  lbu   $t2, 5($s1)
  or    $t6, $t8, $t9
  sll   $t1, $t7, 8
  or    $t5, $t6, $t1
  lbu   $a0, 1($s1)
  jal   get_handle_to_tagged_object
   or    $s0, $t5, $t2
  beqz  $v0, .L7F0384B8
   addiu $s2, $s2, 6
  lw    $t3, 0x10($v0)
  beqz  $t3, .L7F0384B8
   nop   
  lw    $t4, 8($v0)
  not   $t8, $s0
  and   $t9, $t4, $t8
  sw    $t9, 8($v0)
.L7F0384B8:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 6
actionA5_Check_State_Bits_16_Type_Object_If_Same_RVL_7:
  lbu   $t7, 2($s1)
  lbu   $t1, 3($s1)
  lbu   $t3, 4($s1)
  sll   $t6, $t7, 0x18
  sll   $t5, $t1, 0x10
  lbu   $t9, 5($s1)
  or    $t2, $t6, $t5
  sll   $t4, $t3, 8
  or    $t8, $t2, $t4
  lbu   $a0, 1($s1)
  jal   get_handle_to_tagged_object
   or    $s0, $t8, $t9
  beql  $v0, $zero, .L7F038534
   addiu $s2, $s2, 7
  lw    $t7, 0x10($v0)
  beql  $t7, $zero, .L7F038534
   addiu $s2, $s2, 7
  lw    $t1, 8($v0)
  move  $a0, $s6
  move  $a1, $s2
  and   $t6, $t1, $s0
  bnel  $s0, $t6, .L7F038534
   addiu $s2, $s2, 7
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 6($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 7
.L7F038534:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 7
actionA6_Set_16_Object_States_More_6:
  lbu   $t5, 2($s1)
  lbu   $t2, 3($s1)
  lbu   $t9, 4($s1)
  sll   $t3, $t5, 0x18
  sll   $t4, $t2, 0x10
  lbu   $t6, 5($s1)
  or    $t8, $t3, $t4
  sll   $t7, $t9, 8
  or    $t1, $t8, $t7
  lbu   $a0, 1($s1)
  jal   get_handle_to_tagged_object
   or    $s0, $t1, $t6
  beqz  $v0, .L7F03858C
   addiu $s2, $s2, 6
  lw    $t5, 0x10($v0)
  beqz  $t5, .L7F03858C
   nop   
  lw    $t2, 0xc($v0)
  or    $t3, $t2, $s0
  sw    $t3, 0xc($v0)
.L7F03858C:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 6
actionA7_Unset_16_Object_States_More_6:
  lbu   $t4, 2($s1)
  lbu   $t8, 3($s1)
  lbu   $t6, 4($s1)
  sll   $t9, $t4, 0x18
  sll   $t7, $t8, 0x10
  lbu   $t3, 5($s1)
  or    $t1, $t9, $t7
  sll   $t5, $t6, 8
  or    $t2, $t1, $t5
  lbu   $a0, 1($s1)
  jal   get_handle_to_tagged_object
   or    $s0, $t2, $t3
  beqz  $v0, .L7F0385E8
   addiu $s2, $s2, 6
  lw    $t4, 0x10($v0)
  beqz  $t4, .L7F0385E8
   nop   
  lw    $t8, 0xc($v0)
  not   $t9, $s0
  and   $t7, $t8, $t9
  sw    $t7, 0xc($v0)
.L7F0385E8:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 6
actionA8_Check_16_Object_States_More_If_Same_RVL_7:
  lbu   $t6, 2($s1)
  lbu   $t5, 3($s1)
  lbu   $t4, 4($s1)
  sll   $t1, $t6, 0x18
  sll   $t2, $t5, 0x10
  lbu   $t7, 5($s1)
  or    $t3, $t1, $t2
  sll   $t8, $t4, 8
  or    $t9, $t3, $t8
  lbu   $a0, 1($s1)
  jal   get_handle_to_tagged_object
   or    $s0, $t9, $t7
  beql  $v0, $zero, .L7F038664
   addiu $s2, $s2, 7
  lw    $t6, 0x10($v0)
  beql  $t6, $zero, .L7F038664
   addiu $s2, $s2, 7
  lw    $t5, 0xc($v0)
  move  $a0, $s6
  move  $a1, $s2
  and   $t1, $t5, $s0
  bnel  $s0, $t1, .L7F038664
   addiu $s2, $s2, 7
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 6($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 7
.L7F038664:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 7
actionA9_Sets_To_Guard_ID_Fc_Current_Guard_2:
  move  $a0, $s7
  jal   sub_GAME_7F033CF4
   lbu   $a1, 1($s1)
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
actionAA_Sets_FC_Value_For_Guard_ID_To_Guard_ID_3:
  move  $a0, $s7
  lbu   $a1, 1($s1)
  jal   sub_GAME_7F033D1C
   lbu   $a2, 2($s1)
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
actionAB_Set_Current_Guards_2328_Value_To_Preset_3:
  lbu   $t2, 1($s1)
  lbu   $t3, 2($s1)
  lw    $t9, 0x7ac($sp)
  sll   $t4, $t2, 8
  or    $v0, $t4, $t3
  andi  $t8, $v0, 0xffff
  beqz  $s7, .L7F0386D8
   move  $v0, $t8
  move  $a0, $s7
  jal   sub_GAME_7F033D5C
   move  $a1, $t8
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
.L7F0386D8:
  beqz  $t9, .L7F0386E4
   addiu $s2, $s2, 3
  sh    $v0, 6($t9)
.L7F0386E4:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
actionAC_Set_Guard_ID_numS_2328_Value_To_Preset_4:
  lbu   $t7, 2($s1)
  lbu   $t5, 3($s1)
  move  $a0, $s7
  sll   $t6, $t7, 8
  or    $v0, $t6, $t5
  andi  $a2, $v0, 0xffff
  jal   sub_GAME_7F033D84
   lbu   $a1, 1($s1)
  addiu $s2, $s2, 4
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
actionAD_Debug_Comment_20:
  move  $a0, $s6
  jal   get_length_of_action_block
   move  $a1, $s2
  addu  $s2, $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $s2
actionAE_Reset_Cycle_Counter_And_Enable_It_1:
  jal   reset_and_start_loop_counter
   move  $a0, $s7
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionAF_Reset_Cycle_Counter_1:
  sw    $zero, 0x110($s7)
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionB0_Disable_Cycle_Counter_1:
  lhu   $t2, 0x12($s7)
  addiu $s2, $s2, 1
  addiu $s1, $s1, 1
  andi  $t4, $t2, 0xffbf
  b     GetByteS1_ParseCommandByte_SwitchCase
   sh    $t4, 0x12($s7)
actionB1_Enable_Cycle_Counter_1:
  lhu   $t3, 0x12($s7)
  addiu $s2, $s2, 1
  addiu $s1, $s1, 1
  ori   $t8, $t3, 0x40
  b     GetByteS1_ParseCommandByte_SwitchCase
   sh    $t8, 0x12($s7)
actionB2_Check_Cycle_Counter_Enable_Status_2:
  lhu   $t9, 0x12($s7)
  move  $a0, $s6
  move  $a1, $s2
  andi  $t7, $t9, 0x40
  bnezl $t7, .L7F0387B4
   addiu $s2, $s2, 2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 2
.L7F0387B4:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
actionB3_If_Cycle_Counter_LTV_RVL_5:
  lbu   $t6, 1($s1)
  lbu   $t1, 2($s1)
  lbu   $t3, 3($s1)
  sll   $t5, $t6, 0x10
  sll   $t2, $t1, 8
  or    $t4, $t5, $t2
  or    $t8, $t4, $t3
  mtc1  $t8, $f10
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $t8, .L7F0387F4
   cvt.s.w $f18, $f10
  mtc1  $at, $f6
  nop   
  add.s $f18, $f18, $f6
.L7F0387F4:
  div.s $f16, $f18, $f22
  move  $a0, $s7
  jal   get_loop_counter_time_in_seconds
   swc1  $f16, 0x2b0($sp)
  lwc1  $f8, 0x2b0($sp)
  move  $a0, $s6
  move  $a1, $s2
  c.lt.s $f0, $f8
  nop   
  bc1fl .L7F038838
   addiu $s2, $s2, 5
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 4($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 5
.L7F038838:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 5
actionB4_If_Cycle_Counter_GTV_RVL_5:
  lbu   $t9, 1($s1)
  lbu   $t6, 2($s1)
  lbu   $t2, 3($s1)
  sll   $t7, $t9, 0x10
  sll   $t1, $t6, 8
  or    $t5, $t7, $t1
  or    $t4, $t5, $t2
  mtc1  $t4, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $t4, .L7F038878
   cvt.s.w $f10, $f4
  mtc1  $at, $f6
  nop   
  add.s $f10, $f10, $f6
.L7F038878:
  div.s $f18, $f10, $f22
  move  $a0, $s7
  jal   get_loop_counter_time_in_seconds
   swc1  $f18, 0x2a8($sp)
  lwc1  $f16, 0x2a8($sp)
  move  $a0, $s6
  move  $a1, $s2
  c.lt.s $f16, $f0
  nop   
  bc1fl .L7F0388BC
   addiu $s2, $s2, 5
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 4($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 5
.L7F0388BC:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 5
actionB5_Show_Timer_1:
  li    $a0, 1
  jal   set_unset_clock_lock_bits
   li    $a1, 1
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionB6_Hide_Timer_Silent_Countdown_1:
  li    $a0, 1
  jal   set_unset_clock_lock_bits
   move  $a1, $zero
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionB7_Set_Timer_X_Seconds__Doesnt_Show_Timer_Yet_3:
  lbu   $t3, 1($s1)
  lbu   $t9, 2($s1)
  sll   $t8, $t3, 8
  or    $t6, $t8, $t9
  mtc1  $t6, $f8
  nop   
  cvt.s.w $f0, $f8
  mul.s $f12, $f0, $f22
  jal   set_clock_time
   nop   
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
actionB8_Stop_Timer_1:
  jal   set_clock_enable
   move  $a0, $zero
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionB9_Start_Timer_1:
  jal   set_clock_enable
   li    $a0, 1
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionBA_Check_Timer_Enabled_Status_RVL_If_Enabled_2:
  jal   get_clock_enable
   nop   
  bnez  $v0, .L7F038978
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F038978:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
actionBB_Detect_If_Timer_Below_Certain_Point_RVL_If_So_4:
  lbu   $t7, 1($s1)
  lbu   $t5, 2($s1)
  sll   $t1, $t7, 8
  or    $t2, $t1, $t5
  mtc1  $t2, $f4
  nop   
  cvt.s.w $f6, $f4
  jal   get_clock_time
   swc1  $f6, 0x294($sp)
  lwc1  $f10, 0x294($sp)
  move  $a0, $s6
  move  $a1, $s2
  mul.s $f18, $f10, $f22
  c.lt.s $f0, $f18
  nop   
  bc1fl .L7F0389E0
   addiu $s2, $s2, 4
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 3($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 4
.L7F0389E0:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
actionBC_Detect_If_Timer_Above_Certain_Point_RVL_If_So_4:
  lbu   $t4, 1($s1)
  lbu   $t8, 2($s1)
  sll   $t3, $t4, 8
  or    $t9, $t3, $t8
  mtc1  $t9, $f16
  nop   
  cvt.s.w $f8, $f16
  jal   get_clock_time
   swc1  $f8, 0x28c($sp)
  lwc1  $f4, 0x28c($sp)
  move  $a0, $s6
  move  $a1, $s2
  mul.s $f6, $f4, $f22
  c.lt.s $f6, $f0
  nop   
  bc1fl .L7F038A44
   addiu $s2, $s2, 4
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 3($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 4
.L7F038A44:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
actionBD_Spawn_Guard_C:
  lbu   $t6, 3($s1)
  lbu   $t1, 4($s1)
  lbu   $t2, 7($s1)
  sll   $t7, $t6, 8
  lbu   $t3, 8($s1)
  or    $s0, $t7, $t1
  lbu   $t6, 9($s1)
  andi  $t5, $s0, 0xffff
  move  $s0, $t5
  lbu   $t5, 0xa($s1)
  sll   $t4, $t2, 0x18
  sll   $t8, $t3, 0x10
  or    $t9, $t4, $t8
  sll   $t7, $t6, 8
  or    $t1, $t9, $t7
  or    $t2, $t1, $t5
  sw    $t2, 0x280($sp)
  lbu   $t3, 5($s1)
  lbu   $t8, 6($s1)
  sll   $t4, $t3, 8
  or    $v0, $t4, $t8
  jal   LoadNext_PrevActionBlock
   andi  $a0, $v0, 0xffff
  lw    $t9, 0x280($sp)
  lbu   $a1, 1($s1)
  lb    $a2, 2($s1)
  sw    $v0, 0x10($sp)
  move  $a0, $s7
  move  $a3, $s0
  jal   guard_constructor_BD
   sw    $t9, 0x14($sp)
  beqz  $v0, .L7F038AE8
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 0xb($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F038AE8:
  addiu $s2, $s2, 0xc
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 0xc
actionBE_Respawn_Guard_with_ID_B:
  lbu   $t7, 6($s1)
  lbu   $t5, 7($s1)
  lbu   $t4, 8($s1)
  sll   $t1, $t7, 0x18
  sll   $t2, $t5, 0x10
  lbu   $t7, 4($s1)
  or    $t3, $t1, $t2
  lbu   $t1, 5($s1)
  lbu   $t9, 9($s1)
  sll   $t8, $t4, 8
  sll   $t5, $t7, 8
  or    $t6, $t3, $t8
  or    $v0, $t5, $t1
  andi  $a0, $v0, 0xffff
  jal   LoadNext_PrevActionBlock
   or    $s0, $t6, $t9
  lbu   $a1, 1($s1)
  lb    $a2, 2($s1)
  lbu   $a3, 3($s1)
  sw    $s0, 0x14($sp)
  sw    $v0, 0x10($sp)
  jal   guard_constructor_BE
   move  $a0, $s7
  beqz  $v0, .L7F038B70
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 0xa($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F038B70:
  addiu $s2, $s2, 0xb
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 0xb
actionBF_Spawn_Weapon_9:
  lbu   $t4, 4($s1)
  lbu   $t8, 5($s1)
  lbu   $t7, 6($s1)
  sll   $t3, $t4, 0x18
  lbu   $t4, 1($s1)
  sll   $t6, $t8, 0x10
  or    $t9, $t3, $t6
  lbu   $t2, 7($s1)
  lbu   $t3, 2($s1)
  sll   $t5, $t7, 8
  or    $t1, $t9, $t5
  sll   $t8, $t4, 8
  move  $v1, $zero
  or    $s0, $t1, $t2
  beqz  $s7, .L7F038C54
   or    $s3, $t8, $t3
  lw    $t6, 0x18($s7)
  beqz  $t6, .L7F038C54
   nop   
  lw    $t7, 0x1c($s7)
  beqz  $t7, .L7F038C54
   nop   
  jal   cheatCheckIfOn
   li    $a0, 28
  beql  $v0, $zero, .L7F038C40
   move  $a0, $s7
  lbu   $a2, 3($s1)
  addiu $t9, $a2, -2
  sltiu $at, $t9, 0x1e
  beqz  $at, .L7F038C24
   sll   $t9, $t9, 2
  lui   $at, %hi(jpt_800528FC)
  addu  $at, $at, $t9
  lw    $t9, %lo(jpt_800528FC)($at)
.L7F038C04:
  jr    $t9
   nop   
loc_CODE_7F038C0C:
  move  $a0, $s7
  li    $a1, 211
  li    $a2, 25
  jal   actor_draws_weapon_with_model
   move  $a3, $s0
  lbu   $a2, 3($s1)
.L7F038C24:
  move  $a0, $s7
  move  $a1, $s3
  jal   actor_draws_weapon_with_model
   move  $a3, $s0
  b     .L7F038C54
   move  $v1, $v0
  move  $a0, $s7
.L7F038C40:
  move  $a1, $s3
  lbu   $a2, 3($s1)
  jal   actor_draws_weapon_with_model
   move  $a3, $s0
  move  $v1, $v0
.L7F038C54:
  beqz  $v1, .L7F038C74
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 8($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F038C74:
  addiu $s2, $s2, 9
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 9
actionC0_Spawn_Hat_8:
  lbu   $t5, 3($s1)
  lbu   $t2, 4($s1)
  lbu   $t3, 5($s1)
  sll   $t1, $t5, 0x18
  lbu   $t5, 1($s1)
  sll   $t4, $t2, 0x10
  or    $t8, $t1, $t4
  lbu   $t9, 6($s1)
  lbu   $t1, 2($s1)
  sll   $t6, $t3, 8
  or    $t7, $t8, $t6
  sll   $t2, $t5, 8
  move  $v1, $zero
  or    $a2, $t7, $t9
  beqz  $s7, .L7F038CE4
   or    $a1, $t2, $t1
  lw    $t4, 0x18($s7)
  beqz  $t4, .L7F038CE4
   nop   
  lw    $t3, 0x1c($s7)
  beqz  $t3, .L7F038CE4
   nop   
  jal   sub_GAME_7F0510C0
   move  $a0, $s7
  move  $v1, $v0
.L7F038CE4:
  beqz  $v1, .L7F038D04
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 7($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F038D04:
  addiu $s2, $s2, 8
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 8
actionC1_GuardIDDoesAV_If_Gunfire_RVL_WhenComplete_5:
  lbu   $t8, 2($s1)
  lbu   $t7, 3($s1)
  sw    $zero, 0x20c($sp)
  sll   $t6, $t8, 8
  or    $v0, $t6, $t7
  andi  $a0, $v0, 0xffff
  sw    $zero, 0x210($sp)
  sw    $zero, 0x234($sp)
  move  $s3, $zero
  jal   LoadNext_PrevActionBlock
   move  $s4, $zero
  move  $s0, $v0
  move  $a0, $s7
  jal   get_handle_for_guard_id
   lbu   $a1, 1($s1)
  beqz  $v0, .L7F038E94
   move  $s5, $v0
  lw    $t5, 0x14($v0)
  move  $a0, $s7
  andi  $t2, $t5, 2
  beql  $t2, $zero, .L7F038E98
   lw    $t1, 0x234($sp)
  lb    $a1, 0xf($v0)
  lh    $a3, ($v0)
  sw    $zero, 0x14($sp)
  sw    $s0, 0x10($sp)
  jal   guard_constructor_BE
   li    $a2, -1
  beql  $v0, $zero, .L7F038E98
   lw    $t1, 0x234($sp)
  lw    $t1, 4($v0)
  move  $a0, $s7
  sw    $t1, 0x218($sp)
  lh    $s0, ($s5)
  addiu $s0, $s0, 0x2710
  jal   get_handle_for_guard_id
   move  $a1, $s0
  bnez  $v0, .L7F038DB4
   move  $a0, $s5
  lw    $t4, 0x218($sp)
  sh    $s0, ($t4)
.L7F038DB4:
  jal   something_with_weaponpos_of_guarddata_hand
   move  $a1, $zero
  beql  $v0, $zero, .L7F038DF0
   move  $a0, $s5
  lw    $s4, 4($v0)
  lw    $a0, 0x218($sp)
  move  $a3, $zero
  lh    $a1, 4($s4)
  jal   actor_draws_weapon_with_model
   lb    $a2, 0x80($s4)
  beql  $v0, $zero, .L7F038DF0
   move  $a0, $s5
  lw    $t3, 4($v0)
  sw    $t3, 0x20c($sp)
  move  $a0, $s5
.L7F038DF0:
  jal   something_with_weaponpos_of_guarddata_hand
   li    $a1, 1
  beqz  $v0, .L7F038E28
   nop   
  lw    $s3, 4($v0)
  lw    $a0, 0x218($sp)
  lui   $a3, 0x1000
  lh    $a1, 4($s3)
  jal   actor_draws_weapon_with_model
   lb    $a2, 0x80($s3)
  beqz  $v0, .L7F038E28
   nop   
  lw    $t8, 4($v0)
  sw    $t8, 0x210($sp)
.L7F038E28:
  beql  $s3, $zero, .L7F038E70
   lw    $v1, 0x1d8($s5)
  beqz  $s4, .L7F038E6C
   lw    $t6, 0x210($sp)
  beqz  $t6, .L7F038E6C
   lw    $t7, 0x20c($sp)
  beql  $t7, $zero, .L7F038E70
   lw    $v1, 0x1d8($s5)
  lw    $t9, 0x84($s3)
  bnel  $s4, $t9, .L7F038E70
   lw    $v1, 0x1d8($s5)
  lw    $t5, 0x84($s4)
  move  $a0, $t6
  bnel  $s3, $t5, .L7F038E70
   lw    $v1, 0x1d8($s5)
  jal   link_objects
   move  $a1, $t7
.L7F038E6C:
  lw    $v1, 0x1d8($s5)
.L7F038E70:
  lw    $a0, 0x218($sp)
  beql  $v1, $zero, .L7F038E90
   li    $t2, 1
  lw    $v0, 4($v1)
  move  $a2, $zero
  jal   sub_GAME_7F0510C0
   lh    $a1, 4($v0)
  li    $t2, 1
.L7F038E90:
  sw    $t2, 0x234($sp)
.L7F038E94:
  lw    $t1, 0x234($sp)
.L7F038E98:
  move  $a0, $s6
  move  $a1, $s2
  beql  $t1, $zero, .L7F038EC0
   addiu $s2, $s2, 5
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 4($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 5
.L7F038EC0:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 5
actionC2_Display_Text_Preset_Bottom_Screen_3:
  lbu   $t4, 1($s1)
  lbu   $t8, 2($s1)
  sll   $t3, $t4, 8
  jal   get_textptr_for_textID
   or    $a0, $t3, $t8
  jal   jp_display_string_in_lower_left_corner
   move  $a0, $v0
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
actionC3_Display_Text_Preset_Top_Screen_3:
  lbu   $t9, 1($s1)
  lbu   $t6, 2($s1)
  sll   $t5, $t9, 8
  jal   get_textptr_for_textID
   or    $a0, $t5, $t6
  jal   display_string_at_top_of_screen
   move  $a0, $v0
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
actionC4_Play_Sound_Effect_num_In_Slot_num_0_7_4:
  lbu   $t7, 1($s1)
  lbu   $t1, 2($s1)
  lb    $a0, 3($s1)
  sll   $t2, $t7, 8
  or    $a1, $t2, $t1
  sll   $t4, $a1, 0x10
  jal   set_sound_effect_to_slot
   sra   $a1, $t4, 0x10
  addiu $s2, $s2, 4
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
actionC9_Shut_Off_Sound_In_Slot_Number_2:
  jal   sub_GAME_7F0349BC
   lb    $a0, 1($s1)
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
actionC7_Sound_In_Slot_num_Crecendos_To_Volume_Over_ms_6:
  lbu   $t8, 2($s1)
  lbu   $t5, 3($s1)
  lbu   $t2, 4($s1)
  lbu   $t4, 5($s1)
  lb    $v1, 1($s1)
  sll   $t9, $t8, 8
  or    $a0, $t9, $t5
  sll   $t1, $t2, 8
  sll   $t6, $a0, 0x10
  or    $a1, $t1, $t4
  sra   $a0, $t6, 0x10
  bltz  $v1, .L7F038FFC
   andi  $t3, $a1, 0xffff
  slti  $at, $v1, 8
  beqz  $at, .L7F038FFC
   li    $a3, 24
  multu $v1, $a3
  lui   $a2, %hi(sound_effects)
  addiu $a2, %lo(sound_effects) # addiu $a2, $a2, -0x6490
  move  $v0, $t3
  mflo  $t8
  addu  $t9, $a2, $t8
  sw    $t3, 8($t9)
  lb    $t5, 1($s1)
  multu $t5, $a3
  mflo  $t6
  addu  $t7, $a2, $t6
  sw    $a0, 0xc($t7)
  lb    $t2, 1($s1)
  multu $t2, $a3
  mflo  $t1
  addu  $t4, $a2, $t1
  sw    $zero, 0x10($t4)
  lb    $t3, 1($s1)
  multu $t3, $a3
  mflo  $t8
  addu  $t9, $a2, $t8
  bnez  $v0, .L7F038FFC
   sw    $zero, 0x14($t9)
  jal   set_sound_effect_source_to_location
   lb    $a0, 1($s1)
.L7F038FFC:
  addiu $s2, $s2, 6
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 6
actionC8_Sound_In_Slot_num_Fades_To_Volume_Over_ms_6:
  lbu   $t5, 2($s1)
  lbu   $t7, 3($s1)
  lbu   $t1, 4($s1)
  lbu   $t3, 5($s1)
  sll   $t6, $t5, 8
  lb    $v1, 1($s1)
  or    $t2, $t6, $t7
  mtc1  $t2, $f10
  sll   $t4, $t1, 8
  or    $v0, $t4, $t3
  andi  $t8, $v0, 0xffff
  bltz  $v1, .L7F0390B8
   cvt.s.w $f12, $f10
  slti  $at, $v1, 8
  beqz  $at, .L7F0390B8
   sll   $t9, $v1, 2
  subu  $t9, $t9, $v1
  sll   $t9, $t9, 3
  lui   $at, %hi(sound_effects+8)
  addu  $at, $at, $t9
  sw    $t8, %lo(sound_effects+8)($at)
  jal   sub_GAME_7F0539B8
   move  $s0, $t8
  lb    $t5, 1($s1)
  li    $a0, 24
  lui   $v1, %hi(sound_effects)
  multu $t5, $a0
  addiu $v1, %lo(sound_effects) # addiu $v1, $v1, -0x6490
  mflo  $t6
  addu  $t7, $v1, $t6
  sw    $v0, 0xc($t7)
  lb    $t2, 1($s1)
  multu $t2, $a0
  mflo  $t1
  addu  $t4, $v1, $t1
  sw    $zero, 0x10($t4)
  lb    $t3, 1($s1)
  multu $t3, $a0
  mflo  $t8
  addu  $t9, $v1, $t8
  bnez  $s0, .L7F0390B8
   sw    $zero, 0x14($t9)
  jal   set_sound_effect_source_to_location
   lb    $a0, 1($s1)
.L7F0390B8:
  addiu $s2, $s2, 6
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 6
actionC5_EmanateSoundSlotnumFrom16ObjectWithAudibleRV_5:
  jal   get_handle_to_tagged_object
   lbu   $a0, 2($s1)
  lbu   $t5, 3($s1)
  lbu   $t7, 4($s1)
  lb    $v1, 1($s1)
  sll   $t6, $t5, 8
  or    $a1, $t6, $t7
  bltz  $v1, .L7F039154
   andi  $t2, $a1, 0xffff
  slti  $at, $v1, 8
  beql  $at, $zero, .L7F039158
   addiu $s2, $s2, 5
  beqz  $v0, .L7F039154
   sll   $t1, $v1, 2
  subu  $t1, $t1, $v1
  sll   $t1, $t1, 3
  lui   $at, %hi(sound_effects+8)
  addu  $at, $at, $t1
  sw    $t2, %lo(sound_effects+8)($at)
  lb    $t4, 1($s1)
  lui   $at, %hi(sound_effects+16)
  sll   $t3, $t4, 2
  subu  $t3, $t3, $t4
  sll   $t3, $t3, 3
  addu  $at, $at, $t3
  sw    $zero, %lo(sound_effects+16)($at)
  lb    $t8, 1($s1)
  lui   $at, %hi(sound_effects+20)
  sll   $t9, $t8, 2
  subu  $t9, $t9, $t8
  sll   $t9, $t9, 3
  addu  $at, $at, $t9
  bnez  $t2, .L7F039154
   sw    $v0, %lo(sound_effects+20)($at)
  jal   set_sound_effect_source_to_location
   lb    $a0, 1($s1)
.L7F039154:
  addiu $s2, $s2, 5
.L7F039158:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 5
actionC6_EmanateSoundSlotnumFromPresetWithAudibleRV_6:
  lbu   $t5, 2($s1)
  lbu   $t7, 3($s1)
  lbu   $t1, 4($s1)
  lbu   $t3, 5($s1)
  sll   $t6, $t5, 8
  or    $v0, $t6, $t7
  sll   $t4, $t1, 8
  andi  $t2, $v0, 0xffff
  or    $a1, $t4, $t3
  andi  $t8, $a1, 0xffff
  slti  $at, $t2, 0x2710
  move  $a1, $t8
  beqz  $at, .L7F0391BC
   move  $v1, $t2
  sll   $t9, $t2, 2
  subu  $t9, $t9, $t2
  sll   $t9, $t9, 2
  lui   $t5, %hi(ptr_0xxxpresets) 
  lw    $t5, %lo(ptr_0xxxpresets)($t5)
  subu  $t9, $t9, $t2
  sll   $t9, $t9, 2
  b     .L7F0391E0
   addu  $a0, $t9, $t5
.L7F0391BC:
  lui   $t7, %hi(ptr_2xxxpresets) 
  lw    $t7, %lo(ptr_2xxxpresets)($t7)
  sll   $t6, $v1, 4
  addu  $t6, $t6, $v1
  sll   $t6, $t6, 2
  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
  addu  $a0, $t6, $t7
  addu  $a0, $a0, $at
.L7F0391E0:
  lb    $v1, 1($s1)
  bltz  $v1, .L7F039254
   slti  $at, $v1, 8
  beql  $at, $zero, .L7F039258
   addiu $s2, $s2, 6
  beqz  $a0, .L7F039254
   sll   $t2, $v1, 2
  subu  $t2, $t2, $v1
  sll   $t2, $t2, 3
  lui   $at, %hi(sound_effects+8)
  addu  $at, $at, $t2
  sw    $a1, %lo(sound_effects+8)($at)
  lb    $t1, 1($s1)
  lui   $at, %hi(sound_effects+16)
  sll   $t4, $t1, 2
  subu  $t4, $t4, $t1
  sll   $t4, $t4, 3
  addu  $at, $at, $t4
  sw    $a0, %lo(sound_effects+16)($at)
  lb    $t3, 1($s1)
  lui   $at, %hi(sound_effects+20)
  sll   $t8, $t3, 2
  subu  $t8, $t8, $t3
  sll   $t8, $t8, 3
  addu  $at, $at, $t8
  bnez  $a1, .L7F039254
   sw    $zero, %lo(sound_effects+20)($at)
  jal   set_sound_effect_source_to_location
   lb    $a0, 1($s1)
.L7F039254:
  addiu $s2, $s2, 6
.L7F039258:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 6
actionCA_If_Value_GreaterThan_Volume_7FFF_Max_RVL_5:
  lbu   $t9, 2($s1)
  lbu   $t6, 3($s1)
  lb    $v1, 1($s1)
  sll   $t5, $t9, 8
  or    $v0, $t5, $t6
  sll   $t7, $v0, 0x10
  bltz  $v1, .L7F0392C8
   sra   $t2, $t7, 0x10
  slti  $at, $v1, 8
  beqz  $at, .L7F0392C8
   sll   $t1, $v1, 2
  subu  $t1, $t1, $v1
  sll   $t1, $t1, 3
  lui   $t4, %hi(sound_effects+4)
  addu  $t4, $t4, $t1
  lw    $t4, %lo(sound_effects+4)($t4)
  move  $a0, $s6
  move  $a1, $s2
  slt   $at, $t4, $t2
  beql  $at, $zero, .L7F0392CC
   addiu $s2, $s2, 5
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 4($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F0392C8:
  addiu $s2, $s2, 5
.L7F0392CC:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 5
actionCB_Set_Object_Path_27_Type_Object_2:
  jal   get_ptr_path_for_pathnum
   lbu   $a0, 1($s1)
  lw    $t3, 0x7b0($sp)
  addiu $s2, $s2, 2
  beqz  $t3, .L7F0392F4
   nop   
  sw    $v0, 0xa4($t3)
  sw    $zero, 0xa8($t3)
.L7F0392F4:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
actionCC_Set_Speed_Moving_Vehicle_27_Type_Object_5:
  lbu   $t7, 1($s1)
  lbu   $t1, 2($s1)
  li    $at, 0x42C80000 # 100.000000
  sll   $t2, $t7, 8
  or    $t4, $t2, $t1
  mtc1  $t4, $f16
  mtc1  $at, $f4
  lbu   $t8, 3($s1)
  cvt.s.w $f8, $f16
  lbu   $t5, 4($s1)
  sll   $t9, $t8, 8
  lw    $t3, 0x7b0($sp)
  li    $at, 0x46700000 # 15360.000000
  or    $t6, $t9, $t5
  mul.s $f6, $f8, $f4
  mtc1  $t6, $f18
  mtc1  $at, $f10
  addiu $s2, $s2, 5
  cvt.s.w $f0, $f18
  beqz  $t3, .L7F039358
   div.s $f2, $f6, $f10
  swc1  $f2, 0x94($t3)
  swc1  $f0, 0x98($t3)
.L7F039358:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 5
actionCD_Set_Speed_Aircraft_Rotor_5:
  lbu   $t7, 1($s1)
  lbu   $t1, 2($s1)
  lbu   $t8, 3($s1)
  sll   $t2, $t7, 8
  or    $t4, $t2, $t1
  mtc1  $t4, $f16
  lbu   $t5, 4($s1)
  sll   $t9, $t8, 8
  cvt.s.w $f8, $f16
  lw    $t3, 0x7ac($sp)
  li    $at, 0x45610000 # 3600.000000
  or    $t6, $t9, $t5
  mtc1  $t6, $f18
  mtc1  $at, $f6
  mul.s $f4, $f8, $f26
  addiu $s2, $s2, 5
  cvt.s.w $f0, $f18
  beqz  $t3, .L7F0393B4
   div.s $f2, $f4, $f6
  swc1  $f2, 0x90($t3)
  swc1  $f0, 0x94($t3)
.L7F0393B4:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 5
actionCE_Detect_If_Currently_In_Intro_Camera_RVL_If_So_2:
  jal   get_camera_mode
   nop   
  li    $at, 1
  beql  $v0, $at, .L7F0393E4
   move  $a0, $s6
  jal   get_camera_mode
   nop   
  li    $at, 2
  bne   $v0, $at, .L7F0393FC
   move  $a0, $s6
.L7F0393E4:
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F0393FC:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
actionCF_Detect_If_Currently_In_Intro_Swirl_RVL_If_So_2:
  jal   get_camera_mode
   nop   
  li    $at, 3
  bne   $v0, $at, .L7F039434
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F039434:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
actionD0_Change_Animation_Type_Of_Type_16_Monitor_4:
  jal   get_handle_to_tagged_object
   lbu   $a0, 1($s1)
  beqz  $v0, .L7F0394C0
   move  $a2, $v0
  lw    $t8, 0x10($v0)
  beql  $t8, $zero, .L7F0394C4
   addiu $s2, $s2, 4
  lbu   $v1, 3($v0)
  li    $at, 10
  addiu $a0, $v0, 0x80
  bnel  $v1, $at, .L7F039488
   li    $at, 11
  jal   set_ptr_monitor_img_to_obj_ani_slot
   lbu   $a1, 3($s1)
  addiu $s2, $s2, 4
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
  li    $at, 11
.L7F039488:
  bnel  $v1, $at, .L7F0394C4
   addiu $s2, $s2, 4
  lbu   $v0, 2($s1)
  slti  $at, $v0, 4
  beqz  $at, .L7F0394C0
   sll   $t9, $v0, 3
  subu  $t9, $t9, $v0
  sll   $t9, $t9, 2
  addu  $t9, $t9, $v0
  sll   $t9, $t9, 2
  addu  $a0, $a2, $t9
  addiu $a0, $a0, 0x80
  jal   set_ptr_monitor_img_to_obj_ani_slot
   lbu   $a1, 3($s1)
.L7F0394C0:
  addiu $s2, $s2, 4
.L7F0394C4:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
actionD1_If_Bond_In_Tank_RVL_2:
  jal   get_intank_flag
   nop   
  li    $at, 1
  bne   $v0, $at, .L7F0394F8
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F0394F8:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
actionD2_Exit_Level_1:
  lui   $t5, %hi(camera_8003642C) 
  lw    $t5, %lo(camera_8003642C)($t5)
  lui   $t6, %hi(camera_80036434) 
  beqz  $t5, .L7F03953C
   nop   
  lw    $t6, %lo(camera_80036434)($t6)
  li    $t7, 1
  lui   $at, %hi(camera_80036434)
  bnezl $t6, .L7F039548
   addiu $s2, $s2, 1
  sw    $t7, %lo(camera_80036434)($at)
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
.L7F03953C:
  jal   return_to_title_from_level_end
   nop   
  addiu $s2, $s2, 1
.L7F039548:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionD3_Return_From_Camera_Scene_1:
  jal   set_camera_mode
   li    $a0, 8
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionD4_Camera_Looks_At_Bond_From_Preset_3:
  lbu   $t2, 1($s1)
  lbu   $t4, 2($s1)
  lui   $t7, %hi(ptr_2xxxpresets) 
  sll   $t1, $t2, 8
  or    $v0, $t1, $t4
  andi  $t3, $v0, 0xffff
  slti  $at, $t3, 0x2710
  beqz  $at, .L7F0395B4
   move  $v1, $t3
  sll   $t8, $t3, 2
  subu  $t8, $t8, $t3
  lui   $t9, %hi(ptr_0xxxpresets) 
  lw    $t9, %lo(ptr_0xxxpresets)($t9)
  sll   $t8, $t8, 2
  subu  $t8, $t8, $t3
  sll   $t8, $t8, 2
  lui   $at, %hi(dword_CODE_bss_800799F8)
  addu  $t5, $t8, $t9
  b     .L7F0395DC
   sw    $t5, %lo(dword_CODE_bss_800799F8)($at)
.L7F0395B4:
  lw    $t7, %lo(ptr_2xxxpresets)($t7)
  sll   $t6, $v1, 4
  addu  $t6, $t6, $v1
  sll   $t6, $t6, 2
  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
  addu  $t2, $t6, $t7
  addu  $t1, $t2, $at
  lui   $at, %hi(dword_CODE_bss_800799F8)
  sw    $t1, %lo(dword_CODE_bss_800799F8)($at)
.L7F0395DC:
  jal   set_camera_mode
   li    $a0, 7
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
actionD5_Go_To_Camera_Position_6:
  jal   sub_GAME_7F057080
   lbu   $a0, 1($s1)
  beqz  $v0, .L7F039664
   move  $s0, $v0
  jal   check_if_object_type_has_been_loaded
   move  $a0, $v0
  bltzl $v0, .L7F039668
   addiu $s2, $s2, 6
  lh    $t4, 6($s0)
  jal   sub_GAME_7F056A88
   addu  $a0, $t4, $v0
  lui   $at, %hi(dword_CODE_bss_800799F8)
  sw    $zero, %lo(dword_CODE_bss_800799F8)($at)
  lui   $at, %hi(dword_CODE_bss_800799FC)
  sw    $v0, %lo(dword_CODE_bss_800799FC)($at)
  lbu   $t3, 2($s1)
  lbu   $t9, 3($s1)
  lui   $at, %hi(dword_CODE_bss_80079A18)
  sll   $t8, $t3, 8
  or    $t5, $t8, $t9
  sw    $t5, %lo(dword_CODE_bss_80079A18)($at)
  lbu   $t6, 4($s1)
  lbu   $t2, 5($s1)
  lui   $at, %hi(dword_CODE_bss_80079A1C)
  sll   $t7, $t6, 8
  or    $t1, $t7, $t2
  sw    $t1, %lo(dword_CODE_bss_80079A1C)($at)
  jal   set_camera_mode
   li    $a0, 7
.L7F039664:
  addiu $s2, $s2, 6
.L7F039668:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 6
actionD6_If_Less_Than_Elevation_RVL_4:
  lbu   $t4, 1($s1)
  lbu   $t8, 2($s1)
  sll   $t3, $t4, 8
  or    $t9, $t3, $t8
  sll   $t5, $t9, 0x10
  sra   $t6, $t5, 0x10
  mtc1  $t6, $f10
  nop   
  cvt.s.w $f18, $f10
  jal   get_curplayer_positiondata
   swc1  $f18, 0x14c($sp)
  lwc1  $f16, 0xc($v0)
  lwc1  $f8, 0x14c($sp)
  move  $a0, $s6
  move  $a1, $s2
  c.lt.s $f16, $f8
  nop   
  bc1fl .L7F0396D4
   addiu $s2, $s2, 4
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 3($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 4
.L7F0396D4:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
actionD7_Disable_Text_Variable_2:
  li    $a0, 4
  jal   set_unset_bitflags
   move  $a1, $zero
  li    $a0, 2
  jal   set_unset_ammo_on_screen_setting
   move  $a1, $zero
  lbu   $a1, 1($s1)
  andi  $t7, $a1, 2
  bnezl $t7, .L7F039714
   andi  $t2, $a1, 1
  jal   set_flags_in_BONDdata_stationary_intro_cam
   li    $a0, 2
  lbu   $a1, 1($s1)
  andi  $t2, $a1, 1
.L7F039714:
  bnezl $t2, .L7F03972C
   andi  $t1, $a1, 4
  jal   sub_GAME_7F08A944
   li    $a0, 2
  lbu   $a1, 1($s1)
  andi  $t1, $a1, 4
.L7F03972C:
  bnez  $t1, .L7F03973C
   li    $a0, 16
  jal   set_unset_clock_lock_bits
   move  $a1, $zero
.L7F03973C:
  lui   $at, %hi(D_800364B0)
  sw    $zero, %lo(D_800364B0)($at)
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
actionD8_Enable_All_On_Screen_Displays_1:
  li    $a0, 4
  jal   set_unset_bitflags
   li    $a1, 1
  li    $a0, 2
  jal   set_unset_ammo_on_screen_setting
   li    $a1, 1
  jal   unset_flags_in_BONDdata_stationary_intro_cam
   li    $a0, 2
  jal   sub_GAME_7F08A928
   li    $a0, 2
  li    $a0, 16
  jal   set_unset_clock_lock_bits
   li    $a1, 1
  li    $t4, 1
  lui   $at, %hi(D_800364B0)
  sw    $t4, %lo(D_800364B0)($at)
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionD9_GuardIDMovedToPresetReturnLoopIfSuccessful_5:
  lbu   $t3, 2($s1)
  lbu   $t9, 3($s1)
  move  $a0, $s7
  sll   $t8, $t3, 8
  lbu   $a1, 1($s1)
  move  $s4, $zero
  jal   get_handle_for_guard_id
   or    $s3, $t8, $t9
  beqz  $v0, .L7F039938
   move  $s0, $v0
  move  $a0, $s7
  jal   sub_GAME_7F032F94
   move  $a1, $s3
  slti  $at, $v0, 0x2710
  beqz  $at, .L7F039800
   sll   $t7, $v0, 4
  sll   $t5, $v0, 2
  subu  $t5, $t5, $v0
  sll   $t5, $t5, 2
  lui   $t6, %hi(ptr_0xxxpresets) 
  lw    $t6, %lo(ptr_0xxxpresets)($t6)
  subu  $t5, $t5, $v0
  sll   $t5, $t5, 2
  b     .L7F039820
   addu  $v1, $t5, $t6
.L7F039800:
  lui   $t2, %hi(ptr_2xxxpresets) 
  lw    $t2, %lo(ptr_2xxxpresets)($t2)
  addu  $t7, $t7, $v0
  sll   $t7, $t7, 2
  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
  addu  $v1, $t7, $t2
  addu  $v1, $v1, $at
.L7F039820:
  lwc1  $f12, 0x18($v1)
  lwc1  $f14, 0x20($v1)
  jal   convert_angle_using_inverse
   sw    $v1, 0x134($sp)
  lw    $v1, 0x134($sp)
  swc1  $f0, 0x130($sp)
  move  $a1, $zero
  lwc1  $f4, ($v1)
  swc1  $f4, 0x124($sp)
  lwc1  $f6, 4($v1)
  swc1  $f6, 0x128($sp)
  lwc1  $f10, 8($v1)
  swc1  $f10, 0x12c($sp)
  lw    $t1, 0x28($v1)
  sw    $t1, 0x120($sp)
  jal   sub_GAME_7F03D058
   lw    $a0, 0x18($s0)
  addiu $a0, $sp, 0x124
  addiu $a1, $sp, 0x120
  lw    $a2, 0x130($sp)
  jal   sub_GAME_7F033F48
   li    $a3, 1
  beqz  $v0, .L7F03992C
   lwc1  $f18, 0x124($sp)
  lw    $t4, 0x18($s0)
  swc1  $f18, 8($t4)
  lw    $t3, 0x18($s0)
  lwc1  $f16, 0x128($sp)
  swc1  $f16, 0xc($t3)
  lw    $t8, 0x18($s0)
  lwc1  $f8, 0x12c($sp)
  swc1  $f8, 0x10($t8)
  lw    $t5, 0x18($s0)
  lw    $t9, 0x120($sp)
  sw    $t9, 0x14($t5)
  lw    $t6, 0x14($s0)
  lw    $a0, 0x1c($s0)
  ori   $t7, $t6, 1
  sw    $t7, 0x14($s0)
  jal   setsubroty
   lw    $a1, 0x130($sp)
  lw    $a0, 0x1c($s0)
  jal   setsuboffset
   addiu $a1, $sp, 0x124
  jal   sub_GAME_7F020D94
   move  $a0, $s0
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lw    $t1, 0x18($s0)
  lwc1  $f4, 0x124($sp)
  lw    $t2, 0xa8($v0)
  lui   $t4, %hi(pPlayer) 
  li    $s4, 1
  bne   $t2, $t1, .L7F03992C
   nop   
  swc1  $f4, 0x48c($v0)
  lw    $t4, %lo(pPlayer)($t4)
  lwc1  $f6, 0x128($sp)
  lui   $t3, %hi(pPlayer) 
  lui   $t9, %hi(pPlayer) 
  swc1  $f6, 0x490($t4)
  lw    $t3, %lo(pPlayer)($t3)
  lwc1  $f10, 0x12c($sp)
  swc1  $f10, 0x494($t3)
  lw    $t9, %lo(pPlayer)($t9)
  lw    $t8, 0x120($sp)
  sw    $t8, 0x488($t9)
.L7F03992C:
  lw    $a0, 0x18($s0)
  jal   sub_GAME_7F03D058
   li    $a1, 1
.L7F039938:
  beqz  $s4, .L7F039958
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 4($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F039958:
  addiu $s2, $s2, 5
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 5
actionDA_Fade_Out_From_Cut_Scene_1:
  lui   $t5, %hi(stop_time_flag) 
  lw    $t5, %lo(stop_time_flag)($t5)
  li    $at, 2
  move  $a0, $zero
  beq   $t5, $at, .L7F039998
   move  $a1, $zero
  mfc1  $a3, $f20
  jal   set_rgba_tint
   move  $a2, $zero
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f14
  jal   fade_to_over_seconds
   mov.s $f12, $f22
.L7F039998:
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionDB_Fade_In_From_Black_Reset_DA_1:
  lui   $t6, %hi(stop_time_flag) 
  lw    $t6, %lo(stop_time_flag)($t6)
  li    $at, 2
  move  $a0, $zero
  beq   $t6, $at, .L7F0399D4
   move  $a1, $zero
  move  $a2, $zero
  jal   set_rgba_tint
   li    $a3, 0x3F800000 # 1.000000
  mov.s $f12, $f22
  jal   fade_to_over_seconds
   mov.s $f14, $f20
.L7F0399D4:
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionDC_RVL_When_Fade_Complete_2:
  lui   $t7, %hi(pPlayer) 
  lw    $t7, %lo(pPlayer)($t7)
  move  $a0, $s6
  move  $a1, $s2
  lwc1  $f18, 0x3e4($t7)
  c.lt.s $f18, $f20
  nop   
  bc1fl .L7F039A1C
   addiu $s2, $s2, 2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 2
.L7F039A1C:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
actionDD_Remove_All_Guards_1:
  jal   get_numguards
   nop   
  addiu $v1, $v0, -1
  bltz  $v1, .L7F039A78
   addiu $s2, $s2, 1
  sll   $v0, $v1, 4
  subu  $v0, $v0, $v1
  sll   $v0, $v0, 3
  subu  $v0, $v0, $v1
  sll   $v0, $v0, 2
  lw    $t2, ($fp)
.L7F039A50:
  addu  $v1, $t2, $v0
  lw    $t1, 0x1c($v1)
  addiu $v0, $v0, -0x1dc
  beqz  $t1, .L7F039A70
   nop   
  lw    $t4, 0x14($v1)
  ori   $t3, $t4, 0x400
  sw    $t3, 0x14($v1)
.L7F039A70:
  bgezl $v0, .L7F039A50
   lw    $t2, ($fp)
.L7F039A78:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionDE_Bring_Removed_Guards_Back_1:
  jal   get_numguards
   nop   
  addiu $v1, $v0, -1
  bltz  $v1, .L7F039AC8
   move  $a0, $v1
  sll   $v1, $v1, 4
  subu  $v1, $v1, $a0
  sll   $v1, $v1, 3
  subu  $v1, $v1, $a0
  sll   $v1, $v1, 2
  li    $a0, -1025
.L7F039AAC:
  lw    $t8, ($fp)
  addu  $v0, $t8, $v1
  lw    $t9, 0x14($v0)
  addiu $v1, $v1, -0x1dc
  and   $t5, $t9, $a0
  bgez  $v1, .L7F039AAC
   sw    $t5, 0x14($v0)
.L7F039AC8:
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionDF_Open_Type_16_Door_Used_Cut_Scenes_2:
  jal   get_handle_to_tagged_object
   lbu   $a0, 1($s1)
  beqz  $v0, .L7F039B24
   move  $a0, $v0
  lw    $t6, 0x10($v0)
  beql  $t6, $zero, .L7F039B28
   addiu $s2, $s2, 2
  lwc1  $f16, 0x84($v0)
  swc1  $f20, 0xb8($v0)
  lui   $t7, %hi(global_timer) 
  swc1  $f16, 0xb4($v0)
  lw    $t7, %lo(global_timer)($t7)
  sb    $zero, 0xbc($v0)
  sw    $t7, 0xec($v0)
  jal   sub_GAME_7F052B00
   sw    $v0, 0x10c($sp)
  jal   sub_GAME_7F053598
   lw    $a0, 0x10c($sp)
  jal   sub_GAME_7F053B10
   lw    $a0, 0x10c($sp)
.L7F039B24:
  addiu $s2, $s2, 2
.L7F039B28:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
actionE0_Guard_ID_Draws_Weapon_num_3:
  move  $a0, $s7
  jal   get_handle_for_guard_id
   lbu   $a1, 1($s1)
  beqz  $v0, .L7F039B4C
   move  $a0, $v0
  jal   set_0x4_in_runtime_flags_for_item_in_guards_hand
   lbu   $a1, 2($s1)
.L7F039B4C:
  addiu $s2, $s2, 3
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
actionE1_If_Fewer_than_This_Many_Players_Playing_RVL_3:
  jal   getPlayerCount
   nop   
  lb    $t2, 1($s1)
  move  $a0, $s6
  move  $a1, $s2
  slt   $at, $v0, $t2
  beql  $at, $zero, .L7F039B90
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F039B90:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
actionE2_If_Ammo_Value_In_Type_Is_LTV_RVL_4:
  jal   check_cur_player_ammo_amount_total
   lb    $a0, 1($s1)
  lb    $t1, 2($s1)
  move  $a0, $s6
  move  $a1, $s2
  slt   $at, $v0, $t1
  beql  $at, $zero, .L7F039BD0
   addiu $s2, $s2, 4
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 3($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 4
.L7F039BD0:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 4
actionE3_Draw_Weapon_From_Inventory_In_Game_2:
  move  $a0, $zero
  jal   draw_item_in_hand_has_more_ammo
   lb    $a1, 1($s1)
  li    $a0, 1
  jal   draw_item_in_hand_has_more_ammo
   move  $a1, $zero
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
actionE4_Draw_Weapon_From_Inventory_Cut_Scene_2:
  move  $a0, $zero
  jal   remove_hands_item
   lb    $a1, 1($s1)
  li    $a0, 1
  jal   remove_hands_item
   move  $a1, $zero
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
actionE5_Set_Bonds_Speed_3:
  lb    $t4, 1($s1)
  lui   $v0, %hi(flt_CODE_bss_80079990)
  addiu $v0, %lo(flt_CODE_bss_80079990) # addiu $v0, $v0, -0x6670
  mtc1  $t4, $f8
  swc1  $f20, 4($v0)
  addiu $s2, $s2, 3
  cvt.s.w $f4, $f8
  addiu $s1, $s1, 3
  swc1  $f4, ($v0)
  lb    $t3, -1($s1)
  mtc1  $t3, $f6
  nop   
  cvt.s.w $f10, $f6
  b     GetByteS1_ParseCommandByte_SwitchCase
   swc1  $f10, 8($v0)
actionE6_If_16_Object_And_Preset_Are_In_Same_Room_RVL_5:
  lbu   $t8, 2($s1)
  lbu   $t5, 3($s1)
  lbu   $a0, 1($s1)
  sll   $t9, $t8, 8
  or    $s0, $t9, $t5
  andi  $t6, $s0, 0xffff
  jal   get_handle_to_tagged_object
   move  $s0, $t6
  slti  $at, $s0, 0x2710
  beqz  $at, .L7F039CAC
   move  $v1, $s0
  sll   $t7, $v1, 2
  subu  $t7, $t7, $v1
  sll   $t7, $t7, 2
  lui   $t2, %hi(ptr_0xxxpresets) 
  lw    $t2, %lo(ptr_0xxxpresets)($t2)
  subu  $t7, $t7, $v1
  sll   $t7, $t7, 2
  b     .L7F039CD0
   addu  $a0, $t7, $t2
.L7F039CAC:
  lui   $t4, %hi(ptr_2xxxpresets) 
  lw    $t4, %lo(ptr_2xxxpresets)($t4)
  sll   $t1, $v1, 4
  addu  $t1, $t1, $v1
  sll   $t1, $t1, 2
  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
  addu  $a0, $t1, $t4
  addu  $a0, $a0, $at
.L7F039CD0:
  lw    $v1, 0x28($a0)
  beql  $v1, $zero, .L7F039D24
   addiu $s2, $s2, 5
  beql  $v0, $zero, .L7F039D24
   addiu $s2, $s2, 5
  lw    $a0, 0x10($v0)
  beql  $a0, $zero, .L7F039D24
   addiu $s2, $s2, 5
  lw    $t3, 0x14($a0)
  lbu   $t9, 3($v1)
  move  $a0, $s6
  lbu   $t8, 3($t3)
  move  $a1, $s2
  bnel  $t8, $t9, .L7F039D24
   addiu $s2, $s2, 5
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 4($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 5
.L7F039D24:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 5
actionE9_Instantly_Switch_Sky_To_Sky_2_1:
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f12
  jal   switch_to_solosky2
   nop   
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionEA_Stop_Game_Time_1:
  lui   $t5, %hi(stop_time_flag) 
  lw    $t5, %lo(stop_time_flag)($t5)
  li    $t6, 1
  lui   $at, %hi(stop_time_flag)
  bnez  $t5, .L7F039D64
   addiu $s2, $s2, 1
  sw    $t6, %lo(stop_time_flag)($at)
.L7F039D64:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionEB_If_Key_Pressed_RVL_2:
  lui   $t7, %hi(pPlayer) 
  lw    $t7, %lo(pPlayer)($t7)
  move  $a0, $s6
  move  $a1, $s2
  lw    $t2, 0xd8($t7)
  beql  $t2, $zero, .L7F039DA0
   addiu $s2, $s2, 2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 2
.L7F039DA0:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
actionEC_Disable_Player_Pickups_1:
  li    $t1, 1
  lui   $at, %hi(disable_player_pickups_flag)
  sw    $t1, %lo(disable_player_pickups_flag)($at)
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionED_Hide_First_Person_Display_1:
  jal   remove_item_in_hand
   move  $a0, $zero
  jal   remove_item_in_hand
   li    $a0, 1
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionEE_Cuba_Circular_Camera_Aim_D:
  lbu   $t9, 3($s1)
  lbu   $t6, 4($s1)
  lbu   $t4, 1($s1)
  sll   $t5, $t9, 8
  or    $v1, $t5, $t6
  sll   $t7, $v1, 0x10
  lbu   $t5, 7($s1)
  sra   $v1, $t7, 0x10
  lbu   $t7, 8($s1)
  lbu   $t8, 2($s1)
  sll   $t6, $t5, 8
  lbu   $t9, 0xb($s1)
  or    $a2, $t6, $t7
  lbu   $t6, 0xc($s1)
  sll   $t3, $t4, 8
  lbu   $t1, 5($s1)
  or    $v0, $t3, $t8
  lbu   $t3, 6($s1)
  sll   $t5, $t9, 8
  or    $t0, $t5, $t6
  mtc1  $t0, $f18
  sll   $t4, $t1, 8
  or    $a1, $t4, $t3
  sll   $t8, $a1, 0x10
  cvt.s.w $f16, $f18
  sra   $a1, $t8, 0x10
  mtc1  $a1, $f6
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f0
  cvt.s.w $f10, $f6
  mul.s $f8, $f16, $f26
  lbu   $t2, 9($s1)
  lbu   $t4, 0xa($s1)
  lui   $at, %hi(dword_CODE_bss_800799F8)
  sw    $zero, %lo(dword_CODE_bss_800799F8)($at)
  mul.s $f18, $f10, $f26
  lui   $at, %hi(dword_CODE_bss_800799FC)
  sw    $zero, %lo(dword_CODE_bss_800799FC)($at)
  sll   $t1, $t2, 8
  lui   $at, %hi(flt_CODE_bss_80079A00)
  or    $a3, $t1, $t4
  div.s $f4, $f8, $f0
  mtc1  $v0, $f8
  mtc1  $v1, $f6
  sll   $t3, $a3, 0x10
  sra   $a3, $t3, 0x10
  cvt.s.w $f10, $f6
  li    $a0, 7
  div.s $f16, $f18, $f0
  swc1  $f4, %lo(flt_CODE_bss_80079A00)($at)
  mtc1  $a3, $f18
  lui   $at, %hi(flt_CODE_bss_80079A04)
  cvt.s.w $f4, $f8
  swc1  $f16, %lo(flt_CODE_bss_80079A04)($at)
  cvt.s.w $f16, $f18
  lui   $at, %hi(flt_CODE_bss_80079A08)
  swc1  $f4, %lo(flt_CODE_bss_80079A08)($at)
  lui   $at, %hi(flt_CODE_bss_80079A0C)
  swc1  $f10, %lo(flt_CODE_bss_80079A0C)($at)
  lui   $at, %hi(flt_CODE_bss_80079A10)
  swc1  $f16, %lo(flt_CODE_bss_80079A10)($at)
  lui   $at, %hi(dword_CODE_bss_80079A14)
  jal   set_camera_mode
   sw    $a2, %lo(dword_CODE_bss_80079A14)($at)
  addiu $s2, $s2, 0xd
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 0xd
actionEF_Trigger_Credits_1:
  li    $t7, 1
  lui   $at, %hi(D_8003643C)
  sw    $t7, %lo(D_8003643C)($at)
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionF0_RVL_If_Credits_Completed_2:
  lui   $t2, %hi(D_8003643C) 
  lw    $t2, %lo(D_8003643C)($t2)
  li    $at, 2
  move  $a0, $s6
  bne   $t2, $at, .L7F039F2C
   move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F039F2C:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
actionF1_If_All_Objectives_Complete_RVL_2:
  jal   check_objectives_complete
   nop   
  beqz  $v0, .L7F039F60
   move  $a0, $s6
  move  $a1, $s2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
.L7F039F60:
  addiu $s2, $s2, 2
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
actionF2_Check_Current_Folder_Bond_RVL_3:
  jal   getSelectedFolderBond
   nop   
  lb    $t1, 1($s1)
  move  $a0, $s6
  move  $a1, $s2
  bnel  $v0, $t1, .L7F039FA0
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F039FA0:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
actionF3_If_Player_Pickups_Disabled_RVL_2:
  lui   $t4, %hi(disable_player_pickups_flag) 
  lw    $t4, %lo(disable_player_pickups_flag)($t4)
  move  $a0, $s6
  move  $a1, $s2
  beql  $t4, $zero, .L7F039FD8
   addiu $s2, $s2, 2
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 1($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 2
.L7F039FD8:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
actionF4_PlaysValuenum1ThemeSlot03ForValuenum2Seconds_4:
  move  $v0, $s1
  addiu $s1, $s1, 4
  addiu $s2, $s2, 4
  lb    $a0, 1($v0)
  lbu   $a1, 2($v0)
  jal   set_musicslot_time
   lbu   $a2, 3($v0)
  b     ParseCommandByte_SwitchCase
   lbu   $t6, ($s1)
actionF5_Turn_Off_Music_In_Slot_num_0_3_2:
  move  $v0, $s1
  addiu $s1, $s1, 2
  addiu $s2, $s2, 2
  jal   reset_music_in_slot
   lb    $a0, 1($v0)
  b     ParseCommandByte_SwitchCase
   lbu   $t6, ($s1)
actionF6_Trigger_Explosions_Around_Bond_1:
  jal   trigger_explosions_around_player
   move  $a0, $zero
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionF7_If_Number_Of_Hostages_Scientists_Killed_RVL_3:
  jal   get_civilian_casualties
   nop   
  lbu   $t3, 1($s1)
  move  $a0, $s6
  move  $a1, $s2
  slt   $at, $t3, $v0
  beql  $at, $zero, .L7F03A06C
   addiu $s2, $s2, 3
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F03A06C:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
actionF8_If_Guard_ID_00200000_Flag_Set_Unset_And_Return_3:
  move  $a0, $s7
  jal   get_handle_for_guard_id
   lbu   $a1, 1($s1)
  beql  $v0, $zero, .L7F03A0CC
   addiu $s2, $s2, 3
  lw    $t8, 0x14($v0)
  lui   $at, (0xFFDFFFFF >> 16) # lui $at, 0xffdf
  ori   $at, (0xFFDFFFFF & 0xFFFF) # ori $at, $at, 0xffff
  sll   $t9, $t8, 0xa
  bgezl $t9, .L7F03A0CC
   addiu $s2, $s2, 3
  lw    $t5, 0x14($v0)
  move  $a0, $s6
  move  $a1, $s2
  and   $t6, $t5, $at
  sw    $t6, 0x14($v0)
  jal   true_if_sucessfully_performing_action
   lbu   $a2, 2($s1)
  move  $s2, $v0
  b     GetByteS1_ParseCommandByte_SwitchCase
   addu  $s1, $s6, $v0
  addiu $s2, $s2, 3
.L7F03A0CC:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 3
actionF9_Set_Killed_In_Action_Automatic_Mission_Failure_1:
  li    $t7, 1
  lui   $at, %hi(mission_kia_flag)
  sw    $t7, %lo(mission_kia_flag)($at)
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionFA_Guard_Fawns_On_Shoulder_1:
  jal   check_if_able_to_then_fawn_on_shoulder
   move  $a0, $s7
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionFB_SwitchToSkyValuenumAndActivateGasContainersIfExist_:
  lui   $t2, %hi(D_80030A88) 
  addiu $t2, %lo(D_80030A88) # addiu $t2, $t2, 0xa88
  lw    $at, ($t2)
  addiu $a0, $sp, 0x90
  sw    $at, ($a0)
  lw    $t3, 4($t2)
  sw    $t3, 4($a0)
  lw    $at, 8($t2)
  jal   init_trigger_toxic_gas_effect
   sw    $at, 8($a0)
  addiu $s2, $s2, 1
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 1
actionFC_Launch_Shuttle_2:
  jal   get_handle_to_tagged_object
   lbu   $a0, 1($s1)
  beql  $v0, $zero, .L7F03A1E4
   addiu $s2, $s2, 2
  lw    $t8, 0x10($v0)
  beql  $t8, $zero, .L7F03A1E4
   addiu $s2, $s2, 2
  lw    $a0, 0x10($v0)
  jal   sub_GAME_7F03FDA8
   sw    $v0, 0x88($sp)
  lw    $v1, 0x88($sp)
  lw    $t9, 0x64($v1)
  andi  $t5, $t9, 0x80
  beql  $t5, $zero, .L7F03A1E4
   addiu $s2, $s2, 2
  lw    $v0, 0x6c($v1)
  lw    $t6, ($v0)
  ori   $t7, $t6, 0x601
  sw    $t7, ($v0)
  lw    $a0, 0x10($v1)
  jal   sub_GAME_7F03FE14
   sw    $v1, 0x88($sp)
  lw    $v1, 0x88($sp)
  lw    $a0, 0x6c($v1)
  jal   matrix_4x4_set_identity
   addiu $a0, $a0, 0x20
  lw    $v1, 0x88($sp)
  lui   $at, %hi(D_80052974)
  lw    $t4, 0x6c($v1)
  swc1  $f20, 4($t4)
  lwc1  $f8, %lo(D_80052974)($at)
  lw    $t1, 0x6c($v1)
  lui   $at, %hi(D_80052978)
  swc1  $f8, 8($t1)
  lw    $t2, 0x6c($v1)
  swc1  $f20, 0xc($t2)
  lw    $t3, 0x6c($v1)
  swc1  $f20, 0x10($t3)
  lwc1  $f4, %lo(D_80052978)($at)
  lw    $t8, 0x6c($v1)
  swc1  $f4, 0x14($t8)
  lw    $t9, 0x6c($v1)
  swc1  $f20, 0x18($t9)
  addiu $s2, $s2, 2
.L7F03A1E4:
  b     GetByteS1_ParseCommandByte_SwitchCase
   addiu $s1, $s1, 2
GetCmdLength:
  jal   get_length_of_action_block
   move  $a1, $s2                    # 
  addu  $s2, $s2, $v0                # CurrentActionByte += get_length_of_action_block(CurrentActionByte)
  b     GetByteS1_ParseCommandByte_SwitchCase                  # s1 = CurrentActionByte + s6
   addu  $s1, $s6, $s2              # goto 58c

Action04_End_1:
  lw    $ra, 0x74($sp)
Action04_End_2:
  ldc1  $f20, 0x30($sp)
  ldc1  $f22, 0x38($sp)
  ldc1  $f24, 0x40($sp)
  ldc1  $f26, 0x48($sp)
  lw    $s0, 0x50($sp)
  lw    $s1, 0x54($sp)
  lw    $s2, 0x58($sp)    #load s2 with value before entering actionblock
  lw    $s3, 0x5c($sp)
  lw    $s4, 0x60($sp)
  lw    $s5, 0x64($sp)
  lw    $s6, 0x68($sp)
  lw    $s7, 0x6c($sp)
  lw    $fp, 0x70($sp)
  jr    $ra
   addiu $sp, $sp, 0x7b8
");
#endif

asm(R"
glabel sub_GAME_7F03A240
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  jal   get_ptr_obj_pos_list_current_entry
   sw    $zero, 0x1c($sp)
  lw    $a2, 0x1c($sp)
  beqz  $v0, .L7F03A294
   move  $a1, $v0
  lui   $t1, %hi(dword_CODE_bss_80071620) 
  addiu $t1, %lo(dword_CODE_bss_80071620) # addiu $t1, $t1, 0x1620
  li    $v0, 6
  lbu   $t6, 1($a1)
.L7F03A26C:
  sll   $t8, $a2, 2
  addu  $t9, $t1, $t8
  andi  $t7, $t6, 6
  bnel  $v0, $t7, .L7F03A28C
   lw    $a1, 0x24($a1)
  sw    $a1, ($t9)
  addiu $a2, $a2, 1
  lw    $a1, 0x24($a1)
.L7F03A28C:
  bnezl $a1, .L7F03A26C
   lbu   $t6, 1($a1)
.L7F03A294:
  lui   $t1, %hi(dword_CODE_bss_80071620) 
  lui   $at, %hi(dword_CODE_bss_80071DF4)
  addiu $t1, %lo(dword_CODE_bss_80071620) # addiu $t1, $t1, 0x1620
  sw    $a2, %lo(dword_CODE_bss_80071DF4)($at)
  sll   $t2, $a2, 2
  addu  $t3, $t1, $t2
  sll   $t4, $a2, 2
  sw    $zero, ($t3)
  addu  $t5, $t1, $t4
  lui   $at, %hi(dword_CODE_bss_80071DF0)
  sw    $t5, %lo(dword_CODE_bss_80071DF0)($at)
  blez  $a2, .L7F03A3F4
   move  $t0, $zero
  li    $at, 0xCF800000 # -4294967296.000000
  mtc1  $at, $f14
  nop   
  slt   $at, $t0, $a2
.L7F03A2D8:
  li    $a0, -1
  mov.s $f12, $f14
  beqz  $at, .L7F03A3C4
   move  $v0, $t0
  subu  $v1, $a2, $t0
  andi  $a3, $v1, 3
  beqz  $a3, .L7F03A330
   addu  $a1, $a3, $t0
  sll   $t6, $v0, 2
  addu  $v1, $t1, $t6
.L7F03A300:
  lw    $t7, ($v1)
  lwc1  $f2, 0x18($t7)
  c.lt.s $f12, $f2
  nop   
  bc1fl .L7F03A324
   addiu $v0, $v0, 1
  mov.s $f12, $f2
  move  $a0, $v0
  addiu $v0, $v0, 1
.L7F03A324:
  bne   $a1, $v0, .L7F03A300
   addiu $v1, $v1, 4
  beq   $v0, $a2, .L7F03A3C4
.L7F03A330:
   sll   $t8, $v0, 2
  addu  $v1, $t1, $t8
.L7F03A338:
  lw    $t9, ($v1)
  lwc1  $f2, 0x18($t9)
  c.lt.s $f12, $f2
  nop   
  bc1fl .L7F03A35C
   lw    $t2, 4($v1)
  mov.s $f12, $f2
  move  $a0, $v0
  lw    $t2, 4($v1)
.L7F03A35C:
  lwc1  $f0, 0x18($t2)
  c.lt.s $f12, $f0
  nop   
  bc1fl .L7F03A37C
   lw    $t3, 8($v1)
  mov.s $f12, $f0
  addiu $a0, $v0, 1
  lw    $t3, 8($v1)
.L7F03A37C:
  lwc1  $f0, 0x18($t3)
  c.lt.s $f12, $f0
  nop   
  bc1fl .L7F03A39C
   lw    $t4, 0xc($v1)
  mov.s $f12, $f0
  addiu $a0, $v0, 2
  lw    $t4, 0xc($v1)
.L7F03A39C:
  lwc1  $f0, 0x18($t4)
  c.lt.s $f12, $f0
  nop   
  bc1fl .L7F03A3BC
   addiu $v0, $v0, 4
  mov.s $f12, $f0
  addiu $a0, $v0, 3
  addiu $v0, $v0, 4
.L7F03A3BC:
  bne   $v0, $a2, .L7F03A338
   addiu $v1, $v1, 0x10
.L7F03A3C4:
  bltz  $a0, .L7F03A3E8
   sll   $t5, $t0, 2
  sll   $t6, $a0, 2
  addu  $v1, $t1, $t6
  lw    $t7, ($v1)
  addu  $v0, $t1, $t5
  lw    $a1, ($v0)
  sw    $t7, ($v0)
  sw    $a1, ($v1)
.L7F03A3E8:
  addiu $t0, $t0, 1
  bnel  $t0, $a2, .L7F03A2D8
   slt   $at, $t0, $a2
.L7F03A3F4:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel set_stateflag_0x04_for_posdata
  lbu   $t6, 1($a0)
  ori   $t7, $t6, 4
  jr    $ra
   sb    $t7, 1($a0)
");

asm(R"
glabel unset_stateflag_0x04_for_posdata
  lbu   $t6, 1($a0)
  andi  $t7, $t6, 0xfffb
  jr    $ra
   sb    $t7, 1($a0)
");

int *get_ptr_obj_pos_list_current_entry(void) {
  return ptr_obj_pos_list_current_entry;
}

asm(R"
glabel remove_last_obj_pos_data_entry
  lui   $a1, %hi(ptr_obj_pos_list_final_entry)
  addiu $a1, %lo(ptr_obj_pos_list_final_entry) # addiu $a1, $a1, 0xaa8
  lw    $v1, ($a1)
  beql  $v1, $zero, .L7F03A47C
   move  $v0, $zero
  lw    $t6, 0x24($v1)
  li    $t7, 255
  move  $v0, $v1
  sw    $t6, ($a1)
  sw    $zero, 0x24($v1)
  sw    $zero, 0x28($v1)
  sw    $zero, 0x1c($v1)
  sw    $zero, 0x20($v1)
  sb    $zero, 1($v1)
  sw    $zero, 0x14($v1)
  sh    $zero, 2($v1)
  jr    $ra
   sb    $t7, 0x2c($v1)

  move  $v0, $zero
.L7F03A47C:
  jr    $ra
   nop   
");

asm(R"
glabel set_last_obj_pos_data
  lui   $v0, %hi(ptr_obj_pos_list_final_entry)
  addiu $v0, %lo(ptr_obj_pos_list_final_entry) # addiu $v0, $v0, 0xaa8
  lw    $t6, ($v0)
  sw    $zero, 0x28($a0)
  sw    $zero, 0x14($a0)
  sw    $t6, 0x24($a0)
  jr    $ra
   sw    $a0, ($v0)
");

asm(R"
glabel set_current_objposdata_plus_0x28
  lui   $v1, %hi(ptr_obj_pos_list_current_entry)
  addiu $v1, %lo(ptr_obj_pos_list_current_entry) # addiu $v1, $v1, 0xaa0
  lw    $v0, ($v1)
  beqz  $v0, .L7F03A4D0
   nop   
  sw    $a0, 0x28($v0)
  lw    $t6, ($v1)
  sw    $zero, 0x28($a0)
  sw    $t6, 0x24($a0)
  jr    $ra
   sw    $a0, ($v1)

.L7F03A4D0:
  lui   $v0, %hi(ptr_obj_pos_list_first_entry)
  sw    $zero, 0x24($a0)
  sw    $zero, 0x28($a0)
  addiu $v0, %lo(ptr_obj_pos_list_first_entry) # addiu $v0, $v0, 0xaa4
  sw    $a0, ($v0)
  sw    $a0, ($v1)
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F03A4F0
  lui   $v1, %hi(ptr_obj_pos_list_first_entry)
  addiu $v1, %lo(ptr_obj_pos_list_first_entry) # addiu $v1, $v1, 0xaa4
  lw    $v0, ($v1)
  lui   $at, %hi(ptr_obj_pos_list_current_entry)
  beql  $v0, $zero, .L7F03A524
   sw    $zero, 0x24($a0)
  sw    $a0, 0x24($v0)
  lw    $t6, ($v1)
  sw    $zero, 0x24($a0)
  sw    $t6, 0x28($a0)
  jr    $ra
   sw    $a0, ($v1)

  sw    $zero, 0x24($a0)
.L7F03A524:
  sw    $zero, 0x28($a0)
  sw    $a0, ($v1)
  sw    $a0, %lo(ptr_obj_pos_list_current_entry)($at)
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F03A538
  lui   $v0, %hi(ptr_obj_pos_list_current_entry)
  addiu $v0, %lo(ptr_obj_pos_list_current_entry) # addiu $v0, $v0, 0xaa0
  lw    $t6, ($v0)
  bne   $a0, $t6, .L7F03A554
   nop   
  lw    $t7, 0x24($a0)
  sw    $t7, ($v0)
.L7F03A554:
  lui   $v0, %hi(ptr_obj_pos_list_first_entry)
  addiu $v0, %lo(ptr_obj_pos_list_first_entry) # addiu $v0, $v0, 0xaa4
  lw    $t8, ($v0)
  bnel  $a0, $t8, .L7F03A574
   lw    $v0, 0x24($a0)
  lw    $t9, 0x28($a0)
  sw    $t9, ($v0)
  lw    $v0, 0x24($a0)
.L7F03A574:
  beql  $v0, $zero, .L7F03A588
   lw    $v0, 0x28($a0)
  lw    $t0, 0x28($a0)
  sw    $t0, 0x28($v0)
  lw    $v0, 0x28($a0)
.L7F03A588:
  beql  $v0, $zero, .L7F03A59C
   sw    $zero, 0x24($a0)
  lw    $t1, 0x24($a0)
  sw    $t1, 0x24($v0)
  sw    $zero, 0x24($a0)
.L7F03A59C:
  jr    $ra
   sw    $zero, 0x28($a0)
");

asm(R"
glabel sub_GAME_7F03A5A4
  sw    $a1, 0x1c($a0)
  lw    $v0, 0x20($a1)
  beql  $v0, $zero, .L7F03A5C0
   sw    $v0, 0x24($a0)
  sw    $a0, 0x28($v0)
  lw    $v0, 0x20($a1)
  sw    $v0, 0x24($a0)
.L7F03A5C0:
  sw    $zero, 0x28($a0)
  sw    $zero, 0x14($a0)
  jr    $ra
   sw    $a0, 0x20($a1)
");

asm(R"
glabel sub_GAME_7F03A5D0
  lw    $v0, 0x1c($a0)
  beqz  $v0, .L7F03A624
   nop   
  lw    $t6, 0x20($v0)
  bnel  $a0, $t6, .L7F03A5F4
   lw    $v0, 0x24($a0)
  lw    $t7, 0x24($a0)
  sw    $t7, 0x20($v0)
  lw    $v0, 0x24($a0)
.L7F03A5F4:
  beql  $v0, $zero, .L7F03A608
   lw    $v0, 0x28($a0)
  lw    $t8, 0x28($a0)
  sw    $t8, 0x28($v0)
  lw    $v0, 0x28($a0)
.L7F03A608:
  beql  $v0, $zero, .L7F03A61C
   sw    $zero, 0x1c($a0)
  lw    $t9, 0x24($a0)
  sw    $t9, 0x24($v0)
  sw    $zero, 0x1c($a0)
.L7F03A61C:
  sw    $zero, 0x24($a0)
  sw    $zero, 0x28($a0)
.L7F03A624:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F03A62C
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  lbu   $v0, ($a1)
  li    $at, 3
  move  $s0, $a0
  bne   $v0, $at, .L7F03A660
   move  $a3, $a1
  move  $a0, $a1
  jal   sub_GAME_7F021BFC
   move  $a1, $s0
  b     .L7F03A6E0
   move  $s0, $v0
.L7F03A660:
  li    $at, 1
  beq   $v0, $at, .L7F03A680
   move  $a0, $a3
  li    $at, 4
  beq   $v0, $at, .L7F03A680
   li    $at, 2
  bnel  $v0, $at, .L7F03A694
   li    $at, 7
.L7F03A680:
  jal   sub_GAME_7F04B150
   move  $a1, $s0
  b     .L7F03A6E0
   move  $s0, $v0
  li    $at, 7
.L7F03A694:
  bne   $v0, $at, .L7F03A6AC
   move  $a0, $a3
  jal   sub_GAME_7F09D5A0
   move  $a1, $s0
  b     .L7F03A6E0
   move  $s0, $v0
.L7F03A6AC:
  li    $at, 8
  bne   $v0, $at, .L7F03A6C8
   move  $a0, $a3
  jal   sub_GAME_7F09F03C
   move  $a1, $s0
  b     .L7F03A6E0
   move  $s0, $v0
.L7F03A6C8:
  li    $at, 6
  bne   $v0, $at, .L7F03A6E0
   move  $a0, $a3
  jal   sub_GAME_7F08BCC0
   move  $a1, $s0
  move  $s0, $v0
.L7F03A6E0:
  lw    $ra, 0x1c($sp)
  move  $v0, $s0
  lw    $s0, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x20
");

asm(R"
glabel sub_GAME_7F03A6F4
  addiu $sp, $sp, -0x70
  sw    $ra, 0x34($sp)
  sw    $s7, 0x30($sp)
  sw    $s5, 0x28($sp)
  sw    $s4, 0x24($sp)
  move  $s4, $a0
  move  $s5, $a2
  move  $s7, $a1
  sw    $s6, 0x2c($sp)
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  jal   get_stage_num
   sw    $s0, 0x14($sp)
  li    $at, 54
  bne   $v0, $at, .L7F03A754
   nop   
  bnez  $s5, .L7F03A748
   li    $at, 2
  b     .L7F03A950
   move  $v0, $s4
.L7F03A748:
  bne   $s5, $at, .L7F03A754
   nop   
  move  $s5, $zero
.L7F03A754:
  beqz  $s5, .L7F03A764
   li    $at, 2
  bne   $s5, $at, .L7F03A86C
   lui   $s3, %hi(dword_CODE_bss_80071620)
.L7F03A764:
  lui   $s3, %hi(dword_CODE_bss_80071DF0)
  lw    $s3, %lo(dword_CODE_bss_80071DF0)($s3)
  lui   $t6, %hi(dword_CODE_bss_80071620) 
  addiu $t6, %lo(dword_CODE_bss_80071620) # addiu $t6, $t6, 0x1620
  addiu $s3, $s3, -4
  sltu  $at, $s3, $t6
  bnez  $at, .L7F03A948
   addiu $s6, $sp, 0x48
  lw    $s2, ($s3)
.L7F03A788:
  beqz  $s2, .L7F03A84C
   nop   
  bnez  $s5, .L7F03A7B0
   move  $s1, $zero
  lbu   $t7, 1($s2)
  andi  $t8, $t7, 0x21
  bnezl $t8, .L7F03A7B4
   li    $at, 2
  b     .L7F03A7D4
   li    $s1, 1
.L7F03A7B0:
  li    $at, 2
.L7F03A7B4:
  bne   $s5, $at, .L7F03A7D4
   nop   
  lbu   $t9, 1($s2)
  li    $at, 1
  andi  $t0, $t9, 0x21
  bne   $t0, $at, .L7F03A7D4
   nop   
  li    $s1, 1
.L7F03A7D4:
  beqz  $s1, .L7F03A84C
   move  $a0, $s2
  move  $s1, $zero
  move  $a1, $s6
  jal   sub_GAME_7F03CB8C
   move  $s0, $s6
  lw    $t1, 0x48($sp)
  addiu $t2, $sp, 0x48
  bltz  $t1, .L7F03A834
   nop   
  lw    $a0, ($t2)
.L7F03A800:
  jal   sub_GAME_7F0B5E50
   nop   
  beql  $v0, $zero, .L7F03A828
   lw    $a0, 4($s0)
  lw    $t3, ($s0)
  bne   $s7, $t3, .L7F03A834
   nop   
  b     .L7F03A834
   li    $s1, 1
  lw    $a0, 4($s0)
.L7F03A828:
  addiu $s0, $s0, 4
  bgez  $a0, .L7F03A800
   nop   
.L7F03A834:
  beqz  $s1, .L7F03A84C
   move  $a0, $s4
  move  $a1, $s2
  jal   sub_GAME_7F03A62C
   move  $a2, $zero
  move  $s4, $v0
.L7F03A84C:
  lui   $t4, %hi(dword_CODE_bss_80071620) 
  addiu $t4, %lo(dword_CODE_bss_80071620) # addiu $t4, $t4, 0x1620
  addiu $s3, $s3, -4
  sltu  $at, $s3, $t4
  beql  $at, $zero, .L7F03A788
   lw    $s2, ($s3)
  b     .L7F03A948
   nop   
.L7F03A86C:
  lui   $s5, %hi(dword_CODE_bss_80071DF0)
  addiu $s5, %lo(dword_CODE_bss_80071DF0) # addiu $s5, $s5, 0x1df0
  lw    $t5, ($s5)
  lui   $t6, %hi(dword_CODE_bss_80071620+1) 
  addiu $t6, %lo(dword_CODE_bss_80071620+1) # addiu $t6, $t6, 0x1621
  sltu  $at, $t5, $t6
  bnez  $at, .L7F03A948
   addiu $s3, $s3, %lo(dword_CODE_bss_80071620)
  addiu $s6, $sp, 0x48
  lw    $s2, ($s3)
.L7F03A894:
  move  $s1, $zero
  move  $a1, $s6
  beqz  $s2, .L7F03A934
   move  $a0, $s2
  jal   sub_GAME_7F03CB8C
   move  $s0, $s6
  lw    $t7, 0x48($sp)
  addiu $t8, $sp, 0x48
  bltz  $t7, .L7F03A8F4
   nop   
  lw    $a0, ($t8)
.L7F03A8C0:
  jal   sub_GAME_7F0B5E50
   nop   
  beql  $v0, $zero, .L7F03A8E8
   lw    $a0, 4($s0)
  lw    $t9, ($s0)
  bne   $s7, $t9, .L7F03A8F4
   nop   
  b     .L7F03A8F4
   li    $s1, 1
  lw    $a0, 4($s0)
.L7F03A8E8:
  addiu $s0, $s0, 4
  bgez  $a0, .L7F03A8C0
   nop   
.L7F03A8F4:
  beql  $s1, $zero, .L7F03A938
   lw    $t2, ($s5)
  lbu   $t0, 1($s2)
  move  $a0, $s4
  move  $a1, $s2
  andi  $t1, $t0, 0x20
  beql  $t1, $zero, .L7F03A924
   move  $a0, $s4
  jal   sub_GAME_7F03A62C
   move  $a2, $zero
  move  $s4, $v0
  move  $a0, $s4
.L7F03A924:
  move  $a1, $s2
  jal   sub_GAME_7F03A62C
   li    $a2, 1
  move  $s4, $v0
.L7F03A934:
  lw    $t2, ($s5)
.L7F03A938:
  addiu $s3, $s3, 4
  sltu  $at, $s3, $t2
  bnezl $at, .L7F03A894
   lw    $s2, ($s3)
.L7F03A948:
  jal   sub_GAME_7F0B4FB4
   move  $a0, $s4
.L7F03A950:
  lw    $ra, 0x34($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  lw    $s4, 0x24($sp)
  lw    $s5, 0x28($sp)
  lw    $s6, 0x2c($sp)
  lw    $s7, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x70
");

asm(R"
glabel sub_GAME_7F03A97C
  sll   $t6, $a0, 2
  addu  $t6, $t6, $a0
  lui   $t7, %hi(array_room_info) 
  addiu $t7, %lo(array_room_info) # addiu $t7, $t7, 0x1414
  sll   $t6, $t6, 4
  addu  $v0, $t6, $t7
  lw    $t8, 0x2c($v0)
  addiu $sp, $sp, -0x38
  sw    $ra, 0x14($sp)
  sw    $a1, 0x3c($sp)
  beqz  $t8, .L7F03AA30
   sw    $a2, 0x40($sp)
  lwc1  $f4, 0x38($v0)
  lwc1  $f8, 0x3c($v0)
  lwc1  $f16, 0x40($v0)
  trunc.w.s $f6, $f4
  lwc1  $f4, 0x44($v0)
  move  $a0, $a1
  trunc.w.s $f10, $f8
  lwc1  $f8, 0x48($v0)
  mfc1  $t0, $f6
  trunc.w.s $f18, $f16
  lwc1  $f16, 0x4c($v0)
  mfc1  $t2, $f10
  trunc.w.s $f6, $f4
  mfc1  $t4, $f18
  sw    $t0, 0x20($sp)
  trunc.w.s $f10, $f8
  mfc1  $t6, $f6
  move  $a1, $a2
  trunc.w.s $f18, $f16
  mfc1  $t8, $f10
  addiu $a2, $sp, 0x20
  addiu $a3, $sp, 0x2c
  mfc1  $t0, $f18
  sw    $t2, 0x24($sp)
  sw    $t4, 0x28($sp)
  sw    $t6, 0x2c($sp)
  sw    $t8, 0x30($sp)
  jal   sub_GAME_7F0B6CEC
   sw    $t0, 0x34($sp)
  beql  $v0, $zero, .L7F03AA34
   move  $v0, $zero
  b     .L7F03AA34
   li    $v0, 1
.L7F03AA30:
  move  $v0, $zero
.L7F03AA34:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F03AA44
  addiu $sp, $sp, -0x58
  sw    $ra, 0x2c($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  move  $s1, $a1
  move  $s2, $a2
  move  $s3, $a3
  sw    $s4, 0x28($sp)
  sw    $s0, 0x18($sp)
  jal   get_room_data_float1
   sw    $a0, 0x58($sp)
  jal   sub_GAME_7F0B4878
   swc1  $f0, 0x34($sp)
  lwc1  $f4, ($s2)
  lwc1  $f6, ($s1)
  li    $s0, 1
  sub.s $f8, $f4, $f6
  swc1  $f8, 0x40($sp)
  lwc1  $f16, 4($s1)
  lwc1  $f10, 4($s2)
  sub.s $f18, $f10, $f16
  lwc1  $f10, 0x34($sp)
  swc1  $f18, 0x44($sp)
  lwc1  $f6, 8($s1)
  lwc1  $f4, 8($s2)
  mul.s $f2, $f0, $f10
  sub.s $f8, $f4, $f6
  swc1  $f8, 0x48($sp)
  lwc1  $f16, ($s1)
  mul.s $f18, $f16, $f2
  swc1  $f18, 0x4c($sp)
  lwc1  $f4, 4($s1)
  mul.s $f6, $f4, $f2
  swc1  $f6, 0x50($sp)
  lwc1  $f8, 8($s1)
  mul.s $f10, $f8, $f2
  jal   getMaxNumRooms
   swc1  $f10, 0x54($sp)
  slti  $at, $v0, 2
  bnez  $at, .L7F03AB38
   addu  $s1, $s3, $s0
  li    $s4, 1
  addiu $s3, $sp, 0x40
  addiu $s2, $sp, 0x4c
  lbu   $t6, ($s1)
.L7F03AAFC:
  move  $a0, $s0
  move  $a1, $s2
  bnezl $t6, .L7F03AB24
   addiu $s0, $s0, 1
  jal   sub_GAME_7F03A97C
   move  $a2, $s3
  bnezl $v0, .L7F03AB24
   addiu $s0, $s0, 1
  sb    $s4, ($s1)
  addiu $s0, $s0, 1
.L7F03AB24:
  jal   getMaxNumRooms
   addiu $s1, $s1, 1
  slt   $at, $s0, $v0
  bnezl $at, .L7F03AAFC
   lbu   $t6, ($s1)
.L7F03AB38:
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  lw    $s3, 0x24($sp)
  lw    $s4, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x58
");

asm(R"
glabel sub_GAME_7F03AB58
  addiu $sp, $sp, -0x220
  sw    $ra, 0x3c($sp)
  sw    $s2, 0x24($sp)
  move  $s2, $a0
  sw    $s7, 0x38($sp)
  sw    $s6, 0x34($sp)
  sw    $s5, 0x30($sp)
  sw    $s4, 0x2c($sp)
  sw    $s3, 0x28($sp)
  sw    $s1, 0x20($sp)
  sw    $s0, 0x1c($sp)
  sdc1  $f20, 0x10($sp)
  sw    $a1, 0x224($sp)
  sw    $a2, 0x228($sp)
  jal   get_room_data_float2
   sw    $a3, 0x22c($sp)
  mov.s $f20, $f0
  addiu $a0, $sp, 0x90
  jal   sub_GAME_7F0B8E98
   li    $a1, 100
  blez  $v0, .L7F03ADC0
   addiu $s0, $sp, 0x90
  sll   $t7, $v0, 2
  addu  $s4, $t7, $s0
  li    $s7, 1
  lw    $s6, 0x230($sp)
  addiu $s3, $sp, 0x54
  lw    $s1, 0x234($sp)
  lw    $t8, ($s0)
.L7F03ABCC:
  addu  $v0, $t8, $s6
  lbu   $t9, ($v0)
  bnezl $t9, .L7F03ADB4
   addiu $s0, $s0, 4
  sb    $s7, ($v0)
  lw    $a2, 0x228($sp)
  lw    $a1, 0x22c($sp)
  jal   sub_GAME_7F03A97C
   lw    $a0, ($s0)
  beqz  $v0, .L7F03ADB0
   move  $a0, $s2
  lw    $a1, 0x224($sp)
  lw    $a2, ($s0)
  jal   sub_GAME_7F0B7A78
   move  $a3, $s3
  beqz  $v0, .L7F03ADB0
   lwc1  $f4, 0x54($sp)
  mul.s $f6, $f4, $f20
  lwc1  $f8, 0x58($sp)
  lwc1  $f16, 0x5c($sp)
  lw    $t0, 0x238($sp)
  mul.s $f10, $f8, $f20
  lw    $v0, ($s0)
  move  $t4, $s3
  mul.s $f18, $f16, $f20
  swc1  $f6, 0x54($sp)
  move  $t5, $s1
  addiu $t3, $s3, 0x30
  swc1  $f10, 0x58($sp)
  blez  $t0, .L7F03AD88
   swc1  $f18, 0x5c($sp)
  lwc1  $f0, ($s1)
  lwc1  $f2, ($s2)
  c.le.s $f2, $f0
  nop   
  bc1fl .L7F03AC84
   c.le.s $f0, $f2
  c.le.s $f2, $f6
  nop   
  bc1fl .L7F03AC84
   c.le.s $f0, $f2
  c.lt.s $f6, $f0
  nop   
  bc1tl .L7F03ACB4
   lwc1  $f0, 4($s1)
  c.le.s $f0, $f2
.L7F03AC84:
  lwc1  $f4, 0x54($sp)
  bc1fl .L7F03ADB4
   addiu $s0, $s0, 4
  c.le.s $f4, $f2
  nop   
  bc1fl .L7F03ADB4
   addiu $s0, $s0, 4
  c.lt.s $f0, $f4
  nop   
  bc1fl .L7F03ADB4
   addiu $s0, $s0, 4
  lwc1  $f0, 4($s1)
.L7F03ACB4:
  lwc1  $f2, 4($s2)
  lwc1  $f8, 0x58($sp)
  c.le.s $f2, $f0
  nop   
  bc1fl .L7F03ACF0
   c.le.s $f0, $f2
  c.le.s $f2, $f8
  nop   
  bc1fl .L7F03ACF0
   c.le.s $f0, $f2
  c.lt.s $f8, $f0
  nop   
  bc1tl .L7F03AD20
   lwc1  $f0, 8($s1)
  c.le.s $f0, $f2
.L7F03ACF0:
  lwc1  $f10, 0x58($sp)
  bc1fl .L7F03ADB4
   addiu $s0, $s0, 4
  c.le.s $f10, $f2
  nop   
  bc1fl .L7F03ADB4
   addiu $s0, $s0, 4
  c.lt.s $f0, $f10
  nop   
  bc1fl .L7F03ADB4
   addiu $s0, $s0, 4
  lwc1  $f0, 8($s1)
.L7F03AD20:
  lwc1  $f2, 8($s2)
  lwc1  $f16, 0x5c($sp)
  c.le.s $f2, $f0
  nop   
  bc1fl .L7F03AD5C
   c.le.s $f0, $f2
  c.le.s $f2, $f16
  nop   
  bc1fl .L7F03AD5C
   c.le.s $f0, $f2
  c.lt.s $f16, $f0
  nop   
  bc1tl .L7F03AD8C
   sw    $v0, 0x238($sp)
  c.le.s $f0, $f2
.L7F03AD5C:
  lwc1  $f18, 0x5c($sp)
  bc1fl .L7F03ADB4
   addiu $s0, $s0, 4
  c.le.s $f18, $f2
  nop   
  bc1fl .L7F03ADB4
   addiu $s0, $s0, 4
  c.lt.s $f0, $f18
  nop   
  bc1fl .L7F03ADB4
   addiu $s0, $s0, 4
.L7F03AD88:
  sw    $v0, 0x238($sp)
.L7F03AD8C:
  lw    $at, ($t4)
  addiu $t4, $t4, 0xc
  addiu $t5, $t5, 0xc
  sw    $at, -0xc($t5)
  lw    $at, -8($t4)
  sw    $at, -8($t5)
  lw    $at, -4($t4)
  bne   $t4, $t3, .L7F03AD8C
   sw    $at, -4($t5)
.L7F03ADB0:
  addiu $s0, $s0, 4
.L7F03ADB4:
  sltu  $at, $s0, $s4
  bnezl $at, .L7F03ABCC
   lw    $t8, ($s0)
.L7F03ADC0:
  lw    $ra, 0x3c($sp)
  lw    $v0, 0x238($sp)
  ldc1  $f20, 0x10($sp)
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  lw    $s2, 0x24($sp)
  lw    $s3, 0x28($sp)
  lw    $s4, 0x2c($sp)
  lw    $s5, 0x30($sp)
  lw    $s6, 0x34($sp)
  lw    $s7, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x220
");

asm(R"
glabel sub_GAME_7F03ADF4
  addiu $sp, $sp, -0x2f8
  sw    $fp, 0x38($sp)
  sw    $s7, 0x34($sp)
  sw    $s6, 0x30($sp)
  sw    $s5, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s2, 0x20($sp)
  sw    $s0, 0x18($sp)
  sw    $ra, 0x3c($sp)
  sw    $s3, 0x24($sp)
  sw    $s1, 0x1c($sp)
  sw    $a1, 0x2fc($sp)
  sw    $a2, 0x300($sp)
  sw    $a3, 0x304($sp)
  sb    $a0, 0x1f8($sp)
  li    $s0, 1
  addiu $s2, $sp, 0x64
  addiu $s4, $sp, 0x1f8
  move  $s5, $zero
  addiu $s6, $sp, 0x1f8
  lw    $s7, 0x30c($sp)
  lw    $fp, 0x308($sp)
.L7F03AE4C:
  lbu   $s3, ($s6)
  li    $t7, 1
  move  $a1, $fp
  addu  $v0, $s7, $s3
  lbu   $t6, ($v0)
  move  $a0, $s3
  bnezl $t6, .L7F03AEA4
   move  $a0, $s3
  sb    $t7, ($v0)
  jal   sub_GAME_7F03A97C
   lw    $a2, 0x304($sp)
  beqz  $v0, .L7F03AEA0
   lw    $a0, 0x2fc($sp)
  lw    $a1, 0x300($sp)
  move  $a2, $s3
  jal   sub_GAME_7F0B7A78
   lw    $a3, 0x310($sp)
  beql  $v0, $zero, .L7F03AEA4
   move  $a0, $s3
  b     .L7F03AF2C
   move  $v0, $s3
.L7F03AEA0:
  move  $a0, $s3
.L7F03AEA4:
  move  $a1, $s2
  li    $a2, 100
  jal   sub_GAME_7F0B8EFC
   move  $s1, $zero
  blez  $v0, .L7F03AF18
   move  $a1, $v0
.L7F03AEBC:
  blez  $s0, .L7F03AEEC
   move  $v1, $zero
  sll   $t8, $s1, 2
  addu  $t9, $s2, $t8
  lw    $a0, ($t9)
  addiu $v0, $sp, 0x1f8
.L7F03AED4:
  lbu   $t0, ($v0)
  beq   $t0, $a0, .L7F03AEEC
   nop   
  addiu $v1, $v1, 1
  bne   $v1, $s0, .L7F03AED4
   addiu $v0, $v0, 1
.L7F03AEEC:
  bne   $v1, $s0, .L7F03AF08
   sll   $t1, $s1, 2
  addu  $t2, $s2, $t1
  lw    $t3, ($t2)
  addu  $t4, $s4, $s0
  addiu $s0, $s0, 1
  sb    $t3, ($t4)
.L7F03AF08:
  addiu $s1, $s1, 1
  slt   $at, $s1, $a1
  bnez  $at, .L7F03AEBC
   nop   
.L7F03AF18:
  addiu $s5, $s5, 1
  slt   $at, $s5, $s0
  bnez  $at, .L7F03AE4C
   addiu $s6, $s6, 1
  move  $v0, $zero
.L7F03AF2C:
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
   addiu $sp, $sp, 0x2f8
");

asm(R"
glabel sub_GAME_7F03AF5C
  addiu $sp, $sp, -0xc0
  sdc1  $f26, 0x30($sp)
  li    $at, 0x4F800000 # 4294967296.000000
  sw    $ra, 0x64($sp)
  sw    $fp, 0x60($sp)
  sw    $s7, 0x5c($sp)
  sw    $s3, 0x4c($sp)
  mtc1  $at, $f26
  move  $s3, $a1
  move  $fp, $a3
  sw    $s6, 0x58($sp)
  sw    $s5, 0x54($sp)
  sw    $s4, 0x50($sp)
  sw    $s2, 0x48($sp)
  sw    $s1, 0x44($sp)
  sw    $s0, 0x40($sp)
  sdc1  $f28, 0x38($sp)
  sdc1  $f24, 0x28($sp)
  sdc1  $f22, 0x20($sp)
  sdc1  $f20, 0x18($sp)
  sw    $a0, 0xc0($sp)
  sw    $a2, 0xc8($sp)
  jal   get_room_data_float2
   move  $s7, $zero
  mov.s $f24, $f0
  jal   getMaxNumRooms
   li    $s1, 1
  slti  $at, $v0, 2
  bnez  $at, .L7F03B114
   lw    $t6, 0xd4($sp)
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f28
  addu  $s2, $t6, $s1
  addiu $s6, $sp, 0x88
  li    $s5, 1
  lw    $s4, 0xd0($sp)
  lw    $s0, 0xd8($sp)
  lbu   $t7, ($s2)
.L7F03AFF4:
  move  $a0, $s1
  move  $a1, $s4
  bnez  $t7, .L7F03B0FC
   move  $a2, $fp
  jal   sub_GAME_7F03A97C
   sb    $s5, ($s2)
  beqz  $v0, .L7F03B0FC
   move  $a0, $s3
  lw    $a1, 0xc8($sp)
  move  $a2, $s1
  jal   sub_GAME_7F0B7A78
   move  $a3, $s6
  beqz  $v0, .L7F03B0FC
   lwc1  $f4, 0x88($sp)
  mul.s $f6, $f4, $f24
  lwc1  $f10, 0x8c($sp)
  lwc1  $f8, ($s3)
  lwc1  $f4, 0x90($sp)
  mul.s $f16, $f10, $f24
  lwc1  $f18, 4($s3)
  lh    $a0, 0xb2($sp)
  sub.s $f0, $f6, $f8
  mul.s $f6, $f4, $f24
  lwc1  $f8, 8($s3)
  sub.s $f2, $f16, $f18
  mul.s $f10, $f0, $f0
  nop   
  mul.s $f16, $f2, $f2
  sub.s $f12, $f6, $f8
  mul.s $f4, $f12, $f12
  add.s $f18, $f10, $f16
  add.s $f22, $f18, $f4
  jal   check_if_imageID_is_light
   mov.s $f20, $f22
  beqz  $v0, .L7F03B088
   lwc1  $f6, 0x88($sp)
  sub.s $f20, $f22, $f28
.L7F03B088:
  c.lt.s $f20, $f26
  nop   
  bc1fl .L7F03B100
   addiu $s1, $s1, 1
  swc1  $f6, ($s0)
  lwc1  $f8, 0x8c($sp)
  mov.s $f26, $f20
  move  $s7, $s1
  swc1  $f8, 4($s0)
  lwc1  $f10, 0x90($sp)
  swc1  $f10, 8($s0)
  lwc1  $f16, 0x94($sp)
  swc1  $f16, 0xc($s0)
  lwc1  $f18, 0x98($sp)
  swc1  $f18, 0x10($s0)
  lwc1  $f4, 0x9c($sp)
  swc1  $f4, 0x14($s0)
  lw    $t8, 0xa0($sp)
  sw    $t8, 0x18($s0)
  lw    $t9, 0xa4($sp)
  sw    $t9, 0x1c($s0)
  lw    $t0, 0xa8($sp)
  sw    $t0, 0x20($s0)
  lh    $t1, 0xb2($sp)
  sh    $t1, 0x2a($s0)
  lw    $t2, 0xac($sp)
  sw    $t2, 0x24($s0)
  lh    $t3, 0xb0($sp)
  sh    $t3, 0x28($s0)
.L7F03B0FC:
  addiu $s1, $s1, 1
.L7F03B100:
  jal   getMaxNumRooms
   addiu $s2, $s2, 1
  slt   $at, $s1, $v0
  bnezl $at, .L7F03AFF4
   lbu   $t7, ($s2)
.L7F03B114:
  lw    $ra, 0x64($sp)
  move  $v0, $s7
  lw    $s7, 0x5c($sp)
  ldc1  $f20, 0x18($sp)
  ldc1  $f22, 0x20($sp)
  ldc1  $f24, 0x28($sp)
  ldc1  $f26, 0x30($sp)
  ldc1  $f28, 0x38($sp)
  lw    $s0, 0x40($sp)
  lw    $s1, 0x44($sp)
  lw    $s2, 0x48($sp)
  lw    $s3, 0x4c($sp)
  lw    $s4, 0x50($sp)
  lw    $s5, 0x54($sp)
  lw    $s6, 0x58($sp)
  lw    $fp, 0x60($sp)
  jr    $ra
   addiu $sp, $sp, 0xc0
");

asm(R"
glabel sub_GAME_7F03B15C
  addiu $sp, $sp, -0x578
  sw    $ra, 0x34($sp)
  sw    $s0, 0x28($sp)
  move  $s0, $a0
  sw    $s2, 0x30($sp)
  sw    $s1, 0x2c($sp)
  sw    $zero, 0x56c($sp)
  sw    $zero, 0x55c($sp)
  sw    $zero, 0x554($sp)
  jal   get_curplayer_positiondata
   sw    $zero, 0x544($sp)
  lw    $t6, 0x14($v0)
  addiu $s2, $sp, 0x194
  move  $s1, $v0
  sw    $zero, 0x18c($sp)
  move  $a0, $s2
  addiu $a1, $sp, 0x1a0
  move  $a2, $s0
  jal   sub_GAME_7F0681CC
   sw    $t6, 0x4f8($sp)
  jal   get_item_in_hand
   move  $a0, $s0
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f4
  sw    $v0, 0x1ac($sp)
  addiu $v0, $sp, 0x4b4
  sw    $zero, 0x1d0($sp)
  sw    $zero, 0x1d4($sp)
  sw    $zero, 0x1d8($sp)
  sw    $zero, 0x220($sp)
  sw    $zero, 0x224($sp)
  sw    $zero, 0x228($sp)
  addiu $s0, $sp, 0x234
  swc1  $f4, 0x1c8($sp)
.L7F03B1E4:
  addiu $s0, $s0, 0x140
  sw    $zero, -0xb4($s0)
  sw    $zero, -0xb0($s0)
  sw    $zero, -0xac($s0)
  sw    $zero, -0x64($s0)
  sw    $zero, -0x60($s0)
  sw    $zero, -0x5c($s0)
  sw    $zero, -0x14($s0)
  sw    $zero, -0x10($s0)
  sw    $zero, -0xc($s0)
  sw    $zero, -0x104($s0)
  sw    $zero, -0x100($s0)
  bne   $s0, $v0, .L7F03B1E4
   sw    $zero, -0xfc($s0)
  lwc1  $f6, 0x194($sp)
  lwc1  $f8, 0x198($sp)
  lwc1  $f10, 0x19c($sp)
  swc1  $f6, 0x1b0($sp)
  swc1  $f8, 0x1b4($sp)
  jal   sub_GAME_7F078444
   swc1  $f10, 0x1b8($sp)
  move  $a0, $v0
  jal   sub_GAME_7F058474
   addiu $a1, $sp, 0x1b0
  lwc1  $f16, 0x1a0($sp)
  lwc1  $f18, 0x1a4($sp)
  lwc1  $f4, 0x1a8($sp)
  swc1  $f16, 0x1bc($sp)
  swc1  $f18, 0x1c0($sp)
  jal   sub_GAME_7F078444
   swc1  $f4, 0x1c4($sp)
  move  $a0, $v0
  jal   sub_GAME_7F0583D8
   addiu $a1, $sp, 0x1bc
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f0
  lwc1  $f6, 0x1bc($sp)
  lwc1  $f10, 0x1b0($sp)
  lwc1  $f18, 0x1c0($sp)
  mul.s $f8, $f6, $f0
  lwc1  $f6, 0x1b4($sp)
  mfc1  $a3, $f10
  mul.s $f4, $f18, $f0
  addiu $a0, $sp, 0x4f8
  add.s $f16, $f8, $f10
  add.s $f8, $f4, $f6
  swc1  $f16, 0x4ec($sp)
  lwc1  $f16, 0x1c4($sp)
  lwc1  $f4, 0x1b8($sp)
  swc1  $f8, 0x4f0($sp)
  mul.s $f18, $f16, $f0
  add.s $f6, $f18, $f4
  swc1  $f6, 0x4f4($sp)
  lw    $a2, 0x10($s1)
  lw    $a1, 8($s1)
  jal   sub_GAME_7F0B0BE4
   swc1  $f4, 0x10($sp)
  beql  $v0, $zero, .L7F03B5B0
   lw    $t9, 0x1ac($sp)
  jal   get_room_data_float1
   nop   
  jal   sub_GAME_7F0B4878
   swc1  $f0, 0x48($sp)
  lwc1  $f2, 0x48($sp)
  mul.s $f8, $f0, $f2
  jal   get_BONDdata_position
   swc1  $f8, 0x6c($sp)
  jal   sub_GAME_7F0B1CC4
   move  $s0, $v0
  lwc1  $f16, 0x4f4($sp)
  addiu $a0, $sp, 0x4f8
  lw    $a1, 0x1b0($sp)
  lw    $a2, 0x1b8($sp)
  lw    $a3, 0x4ec($sp)
  jal   sub_GAME_7F0B0BE4
   swc1  $f16, 0x10($sp)
  bnez  $v0, .L7F03B338
   lwc1  $f18, 0x4ec($sp)
  addiu $a0, $sp, 0x1b0
  addiu $a1, $sp, 0x1bc
  jal   sub_GAME_7F02624C
   addiu $a2, $sp, 0x560
  li    $t7, 1
  b     .L7F03B34C
   sw    $t7, 0x56c($sp)
.L7F03B338:
  lwc1  $f6, 0x4f0($sp)
  lwc1  $f10, 0x4f4($sp)
  swc1  $f18, 0x560($sp)
  swc1  $f6, 0x564($sp)
  swc1  $f10, 0x568($sp)
.L7F03B34C:
  lwc1  $f4, 0x560($sp)
  lwc1  $f8, ($s0)
  lwc1  $f18, 0x564($sp)
  lwc1  $f0, 0x6c($sp)
  sub.s $f16, $f4, $f8
  lwc1  $f4, 0x568($sp)
  lw    $a0, 0x4f8($sp)
  swc1  $f16, 0x70($sp)
  lwc1  $f6, 4($s0)
  sub.s $f10, $f18, $f6
  swc1  $f10, 0x74($sp)
  lwc1  $f8, 8($s0)
  sub.s $f16, $f4, $f8
  swc1  $f16, 0x78($sp)
  lwc1  $f18, ($s0)
  mul.s $f6, $f18, $f0
  swc1  $f6, 0x7c($sp)
  lwc1  $f10, 4($s0)
  mul.s $f4, $f10, $f0
  swc1  $f4, 0x80($sp)
  lwc1  $f8, 8($s0)
  sw    $a0, 0x55c($sp)
  mul.s $f16, $f8, $f0
  jal   sub_GAME_7F0B2FD8
   swc1  $f16, 0x84($sp)
  move  $s1, $v0
  addiu $v0, $sp, 0x18c
  addiu $v1, $sp, 0x8c
.L7F03B3BC:
  addiu $v1, $v1, 4
  sb    $zero, -3($v1)
  sb    $zero, -2($v1)
  sb    $zero, -1($v1)
  bne   $v1, $v0, .L7F03B3BC
   sb    $zero, -4($v1)
  move  $a0, $s0
  addiu $a1, $sp, 0x560
  move  $a2, $s1
  jal   sub_GAME_7F0B7A78
   addiu $a3, $sp, 0x510
  beqz  $v0, .L7F03B3F4
   li    $t9, 1
  sw    $s1, 0x544($sp)
.L7F03B3F4:
  addu  $t0, $sp, $s1
  sb    $t9, 0x8c($t0)
  lw    $t1, 0x544($sp)
  lui   $t2, %hi(ptr_bgdata_portals) 
  bgtzl $t1, .L7F03B4A4
   lw    $t0, 0x544($sp)
  lw    $t2, %lo(ptr_bgdata_portals)($t2)
  lw    $t3, ($t2)
  beqz  $t3, .L7F03B460
   nop   
  jal   get_curplayer_positiondata
   nop   
  jal   sub_GAME_7F0B2FD8
   lw    $a0, 0x14($v0)
  addiu $t4, $sp, 0x7c
  addiu $t5, $sp, 0x8c
  addiu $t6, $sp, 0x510
  sw    $t6, 0x18($sp)
  sw    $t5, 0x14($sp)
  sw    $t4, 0x10($sp)
  move  $a0, $v0
  move  $a1, $s0
  addiu $a2, $sp, 0x560
  jal   sub_GAME_7F03ADF4
   addiu $a3, $sp, 0x70
  b     .L7F03B4A0
   sw    $v0, 0x544($sp)
.L7F03B460:
  jal   get_curplayer_positiondata
   nop   
  jal   sub_GAME_7F0B2FD8
   lw    $a0, 0x14($v0)
  addiu $t7, $sp, 0x7c
  addiu $t8, $sp, 0x8c
  addiu $t9, $sp, 0x510
  sw    $t9, 0x18($sp)
  sw    $t8, 0x14($sp)
  sw    $t7, 0x10($sp)
  move  $a0, $v0
  move  $a1, $s0
  addiu $a2, $sp, 0x560
  jal   sub_GAME_7F03AF5C
   addiu $a3, $sp, 0x70
  sw    $v0, 0x544($sp)
.L7F03B4A0:
  lw    $t0, 0x544($sp)
.L7F03B4A4:
  blezl $t0, .L7F03B4E4
   lw    $t3, 0x544($sp)
  jal   get_room_data_float2
   nop   
  lwc1  $f18, 0x510($sp)
  lwc1  $f10, 0x514($sp)
  lwc1  $f8, 0x518($sp)
  mul.s $f6, $f18, $f0
  nop   
  mul.s $f4, $f10, $f0
  nop   
  mul.s $f16, $f8, $f0
  swc1  $f6, 0x510($sp)
  swc1  $f4, 0x514($sp)
  swc1  $f16, 0x518($sp)
  lw    $t3, 0x544($sp)
.L7F03B4E4:
  addiu $t1, $sp, 0x8c
  addiu $t2, $sp, 0x510
  sw    $t2, 0x14($sp)
  sw    $t1, 0x10($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x560
  addiu $a2, $sp, 0x70
  addiu $a3, $sp, 0x7c
  jal   sub_GAME_7F03AB58
   sw    $t3, 0x18($sp)
  blez  $v0, .L7F03B54C
   sw    $v0, 0x544($sp)
  lwc1  $f18, 0x510($sp)
  lh    $t5, 0x53a($sp)
  lwc1  $f16, 0x514($sp)
  lwc1  $f14, 0x518($sp)
  li    $t4, 1
  sw    $t4, 0x554($sp)
  sw    $t5, 0x540($sp)
  swc1  $f18, 0x548($sp)
  swc1  $f18, 0x500($sp)
  swc1  $f16, 0x54c($sp)
  swc1  $f16, 0x504($sp)
  swc1  $f14, 0x550($sp)
  b     .L7F03B570
   swc1  $f14, 0x508($sp)
.L7F03B54C:
  lwc1  $f18, 0x4ec($sp)
  lwc1  $f6, 0x4f0($sp)
  lwc1  $f10, 0x4f4($sp)
  li    $t6, -1
  sw    $s1, 0x544($sp)
  sw    $t6, 0x540($sp)
  swc1  $f18, 0x500($sp)
  swc1  $f6, 0x504($sp)
  swc1  $f10, 0x508($sp)
.L7F03B570:
  lw    $t7, 0x56c($sp)
  lw    $t8, 0x554($sp)
  bnez  $t7, .L7F03B588
   nop   
  beql  $t8, $zero, .L7F03B5B0
   lw    $t9, 0x1ac($sp)
.L7F03B588:
  jal   get_BONDdata_field_10CC
   nop   
  move  $a0, $v0
  jal   sub_GAME_7F058474
   addiu $a1, $sp, 0x500
  lwc1  $f4, 0x508($sp)
  neg.s $f8, $f4
  swc1  $f8, 0x50c($sp)
  swc1  $f8, 0x1c8($sp)
  lw    $t9, 0x1ac($sp)
.L7F03B5B0:
  li    $at, 23
  lwc1  $f18, 0x1c8($sp)
  bne   $t9, $at, .L7F03B5E8
   lui   $s1, %hi(dword_CODE_bss_80071DF0)
  li    $at, 0x43960000 # 300.000000
  mtc1  $at, $f16
  li    $at, 0x43960000 # 300.000000
  c.lt.s $f16, $f18
  nop   
  bc1f  .L7F03B5E8
   nop   
  mtc1  $at, $f6
  nop   
  swc1  $f6, 0x1c8($sp)
.L7F03B5E8:
  lw    $s1, %lo(dword_CODE_bss_80071DF0)($s1)
  lui   $t0, %hi(dword_CODE_bss_80071620) 
  addiu $t0, %lo(dword_CODE_bss_80071620) # addiu $t0, $t0, 0x1620
  addiu $s1, $s1, -4
  sltu  $at, $s1, $t0
  bnezl $at, .L7F03B6A8
   addiu $s0, $sp, 0x194
  lw    $s0, ($s1)
.L7F03B608:
  beqz  $s0, .L7F03B68C
   nop   
  lbu   $v0, ($s0)
  li    $at, 3
  beq   $v0, $at, .L7F03B64C
   li    $at, 6
  bnel  $v0, $at, .L7F03B664
   lbu   $v0, ($s0)
  lw    $t1, 4($s0)
  beql  $t1, $zero, .L7F03B664
   lbu   $v0, ($s0)
  jal   sub_GAME_7F09B15C
   move  $a0, $s0
  jal   get_cur_playernum
   sw    $v0, 0x4c($sp)
  lw    $t2, 0x4c($sp)
  beq   $v0, $t2, .L7F03B660
.L7F03B64C:
   move  $a0, $s0
  jal   sub_GAME_7F022648
   move  $a1, $s2
  b     .L7F03B68C
   nop   
.L7F03B660:
  lbu   $v0, ($s0)
.L7F03B664:
  li    $at, 1
  move  $a0, $s0
  beq   $v0, $at, .L7F03B684
   li    $at, 4
  beq   $v0, $at, .L7F03B684
   li    $at, 2
  bne   $v0, $at, .L7F03B68C
   nop   
.L7F03B684:
  jal   sub_GAME_7F04E9BC
   move  $a1, $s2
.L7F03B68C:
  lui   $t3, %hi(dword_CODE_bss_80071620) 
  addiu $t3, %lo(dword_CODE_bss_80071620) # addiu $t3, $t3, 0x1620
  addiu $s1, $s1, -4
  sltu  $at, $s1, $t3
  beql  $at, $zero, .L7F03B608
   lw    $s0, ($s1)
  addiu $s0, $sp, 0x194
.L7F03B6A8:
  addiu $s1, $sp, 0x4b4
  lw    $v1, 0x3c($s0)
.L7F03B6B0:
  beql  $v1, $zero, .L7F03B744
   addiu $s0, $s0, 0x50
  lbu   $v0, ($v1)
  li    $at, 3
  move  $a0, $s2
  beq   $v0, $at, .L7F03B6D4
   li    $at, 6
  bnel  $v0, $at, .L7F03B6E8
   li    $at, 1
.L7F03B6D4:
  jal   sub_GAME_7F022980
   addiu $a1, $s0, 0x38
  b     .L7F03B710
   lw    $t4, 0x84($s0)
  li    $at, 1
.L7F03B6E8:
  beq   $v0, $at, .L7F03B704
   move  $a0, $s2
  li    $at, 4
  beq   $v0, $at, .L7F03B704
   li    $at, 2
  bnel  $v0, $at, .L7F03B710
   lw    $t4, 0x84($s0)
.L7F03B704:
  jal   sub_GAME_7F04EA68
   addiu $a1, $s0, 0x38
  lw    $t4, 0x84($s0)
.L7F03B710:
  lw    $t5, 0x18c($sp)
  beqz  $t4, .L7F03B740
   addiu $t6, $t5, 1
  sw    $t6, 0x18c($sp)
  jal   sub_GAME_7F05E038
   lw    $a0, 0x1ac($sp)
  lw    $t7, 0x18c($sp)
  slt   $at, $t7, $v0
  bnezl $at, .L7F03B744
   addiu $s0, $s0, 0x50
  sw    $zero, 0x554($sp)
  sw    $zero, 0x56c($sp)
.L7F03B740:
  addiu $s0, $s0, 0x50
.L7F03B744:
  bnel  $s0, $s1, .L7F03B6B0
   lw    $v1, 0x3c($s0)
  lw    $t8, 0x554($sp)
  lw    $t9, 0x56c($sp)
  lw    $t0, 0x1ac($sp)
  bnez  $t8, .L7F03B764
   li    $at, 23
  beqz  $t9, .L7F03B9A8
.L7F03B764:
   move  $s0, $zero
  bne   $t0, $at, .L7F03B790
   li    $s1, 1
  li    $at, 0x43960000 # 300.000000
  mtc1  $at, $f10
  lwc1  $f4, 0x50c($sp)
  c.lt.s $f10, $f4
  nop   
  bc1fl .L7F03B794
   lw    $t1, 0x554($sp)
  move  $s1, $zero
.L7F03B790:
  lw    $t1, 0x554($sp)
.L7F03B794:
  lh    $t2, 0x53a($sp)
  lw    $t4, 0x56c($sp)
  beqz  $t1, .L7F03B870
   nop   
  bgez  $t2, .L7F03B7B8
   lh    $t3, 0x53a($sp)
  lui   $s0, %hi(D_8004E86C)
  b     .L7F03B7DC
   lw    $s0, %lo(D_8004E86C)($s0)
.L7F03B7B8:
  sll   $t4, $t3, 3
  lui   $t5, %hi(image_entries)
  addu  $t5, $t5, $t4
  lbu   $t5, %lo(image_entries)($t5)
  lui   $s0, %hi(D_8004E86C)
  andi  $t6, $t5, 0xf
  sll   $t7, $t6, 2
  addu  $s0, $s0, $t7
  lw    $s0, %lo(D_8004E86C)($s0)
.L7F03B7DC:
  beqz  $s1, .L7F03B868
   nop   
  lh    $t8, 0xa($s0)
  lw    $t9, 0x1ac($sp)
  li    $at, 23
  blez  $t8, .L7F03B84C
   nop   
  beq   $t9, $at, .L7F03B84C
   nop   
  jal   get_random_value
   nop   
  lh    $t0, 0xa($s0)
  lw    $t1, 4($s0)
  li    $t3, -1
  divu  $zero, $v0, $t0
  mfhi  $v1
  addu  $t2, $t1, $v1
  lbu   $a2, ($t2)
  bnez  $t0, .L7F03B830
   nop   
  break 7
.L7F03B830:
  sw    $zero, 0x18($sp)
  sw    $t3, 0x14($sp)
  sw    $zero, 0x10($sp)
  addiu $a0, $sp, 0x548
  addiu $a1, $sp, 0x51c
  jal   sub_GAME_7F0A108C
   lh    $a3, 0x546($sp)
.L7F03B84C:
  jal   check_if_imageID_is_light
   lh    $a0, 0x53a($sp)
  beqz  $v0, .L7F03B868
   lw    $a0, 0x534($sp)
  lh    $a1, 0x538($sp)
  jal   sub_GAME_7F0BBE0C
   lw    $a2, 0x544($sp)
.L7F03B868:
  b     .L7F03B8BC
   addiu $s0, $sp, 0x548
.L7F03B870:
  beqz  $t4, .L7F03B8BC
   li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f0
  lwc1  $f8, 0x1bc($sp)
  lwc1  $f18, 0x1b0($sp)
  lwc1  $f10, 0x1c0($sp)
  mul.s $f16, $f8, $f0
  lwc1  $f8, 0x1b4($sp)
  addiu $s0, $sp, 0x560
  mul.s $f4, $f10, $f0
  lwc1  $f10, 0x1b8($sp)
  add.s $f6, $f16, $f18
  lwc1  $f18, 0x1c4($sp)
  add.s $f16, $f4, $f8
  swc1  $f6, 0x560($sp)
  mul.s $f6, $f18, $f0
  swc1  $f16, 0x564($sp)
  add.s $f4, $f6, $f10
  swc1  $f4, 0x568($sp)
.L7F03B8BC:
  beql  $s0, $zero, .L7F03B9AC
   lw    $ra, 0x34($sp)
  beqz  $s1, .L7F03B93C
   lw    $a0, 0x1ac($sp)
  move  $a1, $s0
  jal   recall_joy2_hits_edit_flag
   lw    $a2, 0x540($sp)
  lw    $t5, 0x540($sp)
  lui   $v0, %hi(image_entries)
  li    $at, 5
  sll   $t6, $t5, 3
  addu  $v0, $v0, $t6
  lbu   $v0, %lo(image_entries)($v0)
  andi  $t7, $v0, 0xf
  beq   $t7, $at, .L7F03B93C
   li    $at, 6
  beq   $t7, $at, .L7F03B93C
   lw    $t8, 0x544($sp)
  li    $t9, 255
  sb    $t8, 0x50($sp)
  jal   get_cur_playernum
   sb    $t9, 0x51($sp)
  addiu $t0, $sp, 0x50
  sw    $t0, 0x18($sp)
  move  $a0, $zero
  move  $a1, $s0
  lw    $a2, 0x55c($sp)
  li    $a3, 1
  sw    $zero, 0x10($sp)
  sw    $v0, 0x14($sp)
  jal   sub_GAME_7F09C250
   sw    $zero, 0x1c($sp)
.L7F03B93C:
  li    $at, 0x41D00000 # 26.000000
  mtc1  $at, $f0
  lwc1  $f16, 0x1bc($sp)
  lwc1  $f8, ($s0)
  lwc1  $f10, 4($s0)
  mul.s $f18, $f0, $f16
  move  $a0, $s0
  sub.s $f6, $f8, $f18
  lwc1  $f18, 8($s0)
  swc1  $f6, ($s0)
  lwc1  $f4, 0x1c0($sp)
  mul.s $f16, $f0, $f4
  sub.s $f8, $f10, $f16
  swc1  $f8, 4($s0)
  lwc1  $f6, 0x1c4($sp)
  mul.s $f4, $f0, $f6
  sub.s $f10, $f18, $f4
  jal   sub_GAME_7F067B4C
   swc1  $f10, 8($s0)
  li    $at, 0x41D00000 # 26.000000
  mtc1  $at, $f0
  beqz  $s1, .L7F03B9A8
   move  $a0, $s0
  mfc1  $a2, $f0
  li    $a1, 1
  jal   sub_GAME_7F0A3E1C
   lh    $a3, 0x546($sp)
.L7F03B9A8:
  lw    $ra, 0x34($sp)
.L7F03B9AC:
  lw    $s0, 0x28($sp)
  lw    $s1, 0x2c($sp)
  lw    $s2, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x578
");

asm(R"
glabel sub_GAME_7F03B9C0
  addiu $sp, $sp, -0x30
  lw    $t6, 0x54($sp)
  mtc1  $a2, $f14
  sw    $ra, 0x14($sp)
  sw    $a0, 0x30($sp)
  sw    $a1, 0x34($sp)
  beqz  $t6, .L7F03BC20
   sw    $a3, 0x3c($sp)
  mtc1  $zero, $f12
  move  $a2, $zero
  move  $a1, $zero
  move  $v1, $zero
  move  $v0, $a0
  mov.s $f2, $f12
.L7F03B9F8:
  lw    $t7, 0x3c($v0)
  beql  $t7, $zero, .L7F03BA38
   addiu $v1, $v1, 1
  lw    $t8, 0x84($v0)
  beql  $t8, $zero, .L7F03BA38
   addiu $v1, $v1, 1
  lwc1  $f0, 0x38($v0)
  addiu $a1, $a1, 1
  c.lt.s $f2, $f0
  nop   
  bc1fl .L7F03BA38
   addiu $v1, $v1, 1
  mov.s $f12, $f2
  mov.s $f2, $f0
  move  $a2, $v1
  addiu $v1, $v1, 1
.L7F03BA38:
  slti  $at, $v1, 0xa
  bnez  $at, .L7F03B9F8
   addiu $v0, $v0, 0x50
  lw    $t9, 0x30($sp)
  lw    $a0, 0x18($t9)
  swc1  $f14, 0x38($sp)
  swc1  $f12, 0x20($sp)
  sw    $a2, 0x24($sp)
  jal   sub_GAME_7F05E038
   sw    $a1, 0x1c($sp)
  lw    $a1, 0x1c($sp)
  lw    $a2, 0x24($sp)
  lw    $a3, 0x30($sp)
  slt   $at, $a1, $v0
  lwc1  $f12, 0x20($sp)
  bnez  $at, .L7F03BBE0
   lwc1  $f14, 0x38($sp)
  sll   $t0, $a2, 2
  c.lt.s $f12, $f14
  addu  $t0, $t0, $a2
  sll   $t0, $t0, 4
  addu  $t1, $a3, $t0
  sw    $zero, 0x3c($t1)
  bc1f  .L7F03BAA0
   swc1  $f12, 0x34($a3)
  swc1  $f14, 0x34($a3)
.L7F03BAA0:
  lw    $t2, 0x3c($a3)
  move  $v0, $a3
  li    $a0, 160
  beqz  $t2, .L7F03BAD8
   li    $v1, 800
  lw    $t3, 0x84($v0)
  bnezl $t3, .L7F03BADC
   lw    $t4, 0x8c($v0)
  lwc1  $f4, 0x38($v0)
  c.lt.s $f12, $f4
  nop   
  bc1fl .L7F03BADC
   lw    $t4, 0x8c($v0)
  sw    $zero, 0x3c($v0)
.L7F03BAD8:
  lw    $t4, 0x8c($v0)
.L7F03BADC:
  beql  $t4, $zero, .L7F03BB0C
   addiu $v0, $a3, 0xa0
  lw    $t5, 0xd4($v0)
  bnezl $t5, .L7F03BB0C
   addiu $v0, $a3, 0xa0
  lwc1  $f6, 0x88($v0)
  c.lt.s $f12, $f6
  nop   
  bc1fl .L7F03BB0C
   addiu $v0, $a3, 0xa0
  sw    $zero, 0x8c($v0)
  addiu $v0, $a3, 0xa0
.L7F03BB0C:
  lw    $t6, 0x3c($v0)
  addiu $a0, $a0, 0x140
  beql  $t6, $zero, .L7F03BB44
   lw    $t8, 0x8c($v0)
  lw    $t7, 0x84($v0)
  bnezl $t7, .L7F03BB44
   lw    $t8, 0x8c($v0)
  lwc1  $f8, 0x38($v0)
  c.lt.s $f12, $f8
  nop   
  bc1fl .L7F03BB44
   lw    $t8, 0x8c($v0)
  sw    $zero, 0x3c($v0)
  lw    $t8, 0x8c($v0)
.L7F03BB44:
  beql  $t8, $zero, .L7F03BB74
   lw    $t0, 0xdc($v0)
  lw    $t9, 0xd4($v0)
  bnezl $t9, .L7F03BB74
   lw    $t0, 0xdc($v0)
  lwc1  $f10, 0x88($v0)
  c.lt.s $f12, $f10
  nop   
  bc1fl .L7F03BB74
   lw    $t0, 0xdc($v0)
  sw    $zero, 0x8c($v0)
  lw    $t0, 0xdc($v0)
.L7F03BB74:
  beql  $t0, $zero, .L7F03BBA4
   lw    $t2, 0x12c($v0)
  lw    $t1, 0x124($v0)
  bnezl $t1, .L7F03BBA4
   lw    $t2, 0x12c($v0)
  lwc1  $f16, 0xd8($v0)
  c.lt.s $f12, $f16
  nop   
  bc1fl .L7F03BBA4
   lw    $t2, 0x12c($v0)
  sw    $zero, 0xdc($v0)
  lw    $t2, 0x12c($v0)
.L7F03BBA4:
  beqz  $t2, .L7F03BBD0
   nop   
  lw    $t3, 0x174($v0)
  bnez  $t3, .L7F03BBD0
   nop   
  lwc1  $f18, 0x128($v0)
  c.lt.s $f12, $f18
  nop   
  bc1f  .L7F03BBD0
   nop   
  sw    $zero, 0x12c($v0)
.L7F03BBD0:
  bne   $a0, $v1, .L7F03BB0C
   addiu $v0, $v0, 0x140
  b     .L7F03BC24
   lw    $t5, 0x58($sp)
.L7F03BBE0:
  lw    $a0, 0x18($a3)
  swc1  $f14, 0x38($sp)
  jal   sub_GAME_7F05E038
   sw    $a1, 0x1c($sp)
  lw    $a1, 0x1c($sp)
  lw    $a3, 0x30($sp)
  lwc1  $f14, 0x38($sp)
  addiu $t4, $a1, 1
  bnel  $t4, $v0, .L7F03BC24
   lw    $t5, 0x58($sp)
  lwc1  $f4, 0x34($a3)
  c.lt.s $f14, $f4
  nop   
  bc1fl .L7F03BC24
   lw    $t5, 0x58($sp)
  swc1  $f14, 0x34($a3)
.L7F03BC20:
  lw    $t5, 0x58($sp)
.L7F03BC24:
  lw    $t6, 0x30($sp)
  beql  $t5, $zero, .L7F03BD4C
   move  $a0, $zero
  lw    $v0, 0x18($t6)
  li    $at, 18
  beq   $v0, $at, .L7F03BD48
   li    $at, 20
  beql  $v0, $at, .L7F03BD4C
   move  $a0, $zero
  lw    $v1, 0x3c($t6)
  move  $v0, $t6
  beql  $v1, $zero, .L7F03BC74
   lw    $t7, 0x8c($v0)
  lwc1  $f6, 0x38($t6)
  c.lt.s $f14, $f6
  nop   
  bc1fl .L7F03BC74
   lw    $t7, 0x8c($v0)
  sw    $zero, 0x3c($t6)
  lw    $t7, 0x8c($v0)
.L7F03BC74:
  beql  $t7, $zero, .L7F03BC98
   lw    $v0, 0x30($sp)
  lwc1  $f8, 0x88($v0)
  c.lt.s $f14, $f8
  nop   
  bc1fl .L7F03BC98
   lw    $v0, 0x30($sp)
  sw    $zero, 0x8c($v0)
  lw    $v0, 0x30($sp)
.L7F03BC98:
  li    $a0, 160
  li    $v1, 800
  addiu $v0, $v0, 0xa0
.L7F03BCA4:
  lw    $t8, 0x3c($v0)
  addiu $a0, $a0, 0x140
  beql  $t8, $zero, .L7F03BCD0
   lw    $t9, 0x8c($v0)
  lwc1  $f10, 0x38($v0)
  c.lt.s $f14, $f10
  nop   
  bc1fl .L7F03BCD0
   lw    $t9, 0x8c($v0)
  sw    $zero, 0x3c($v0)
  lw    $t9, 0x8c($v0)
.L7F03BCD0:
  beql  $t9, $zero, .L7F03BCF4
   lw    $t0, 0xdc($v0)
  lwc1  $f16, 0x88($v0)
  c.lt.s $f14, $f16
  nop   
  bc1fl .L7F03BCF4
   lw    $t0, 0xdc($v0)
  sw    $zero, 0x8c($v0)
  lw    $t0, 0xdc($v0)
.L7F03BCF4:
  beql  $t0, $zero, .L7F03BD18
   lw    $t1, 0x12c($v0)
  lwc1  $f18, 0xd8($v0)
  c.lt.s $f14, $f18
  nop   
  bc1fl .L7F03BD18
   lw    $t1, 0x12c($v0)
  sw    $zero, 0xdc($v0)
  lw    $t1, 0x12c($v0)
.L7F03BD18:
  beqz  $t1, .L7F03BD38
   nop   
  lwc1  $f4, 0x128($v0)
  c.lt.s $f14, $f4
  nop   
  bc1f  .L7F03BD38
   nop   
  sw    $zero, 0x12c($v0)
.L7F03BD38:
  bne   $a0, $v1, .L7F03BCA4
   addiu $v0, $v0, 0x140
  lw    $t2, 0x30($sp)
  swc1  $f14, 0x34($t2)
.L7F03BD48:
  move  $a0, $zero
.L7F03BD4C:
  lw    $v0, 0x30($sp)
  li    $v1, 800
.L7F03BD54:
  lw    $t3, 0x3c($v0)
  addiu $a0, $a0, 0x50
  bnez  $t3, .L7F03BDD4
   nop   
  swc1  $f14, 0x38($v0)
  lw    $t4, 0x34($sp)
  move  $t0, $v0
  sw    $t4, 0x3c($v0)
  lw    $t5, 0x3c($sp)
  sw    $t5, 0x40($v0)
  lw    $t6, 0x40($sp)
  sw    $t6, 0x44($v0)
  lw    $t7, 0x44($sp)
  addiu $t9, $t7, 0x30
.L7F03BD8C:
  lw    $at, ($t7)
  addiu $t7, $t7, 0xc
  addiu $t0, $t0, 0xc
  sw    $at, 0x3c($t0)
  lw    $at, -8($t7)
  sw    $at, 0x40($t0)
  lw    $at, -4($t7)
  bne   $t7, $t9, .L7F03BD8C
   sw    $at, 0x44($t0)
  lw    $t1, 0x48($sp)
  sw    $t1, 0x78($v0)
  lw    $t2, 0x4c($sp)
  sw    $t2, 0x7c($v0)
  lw    $t3, 0x50($sp)
  sw    $t3, 0x80($v0)
  lw    $t4, 0x54($sp)
  b     .L7F03BDDC
   sw    $t4, 0x84($v0)
.L7F03BDD4:
  bne   $a0, $v1, .L7F03BD54
   addiu $v0, $v0, 0x50
.L7F03BDDC:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F03BDEC
  addiu $sp, $sp, -0xc8
  sw    $ra, 0x64($sp)
  sw    $s6, 0x60($sp)
  move  $s6, $a1
  sw    $s5, 0x5c($sp)
  sw    $s4, 0x58($sp)
  sw    $s3, 0x54($sp)
  sw    $s2, 0x50($sp)
  sw    $s1, 0x4c($sp)
  sw    $s0, 0x48($sp)
  sdc1  $f24, 0x40($sp)
  sdc1  $f22, 0x38($sp)
  sdc1  $f20, 0x30($sp)
  sw    $a0, 0xc8($sp)
  jal   get_curplayer_positiondata
   sw    $zero, 0xbc($sp)
  lui   $a0, %hi(pPlayer)
  move  $s4, $v0
  jal   sub_GAME_7F089780
   lw    $a0, %lo(pPlayer)($a0)
  lui   $s3, %hi(dword_CODE_bss_80071DF0)
  lw    $s3, %lo(dword_CODE_bss_80071DF0)($s3)
  lui   $t6, %hi(dword_CODE_bss_80071620) 
  addiu $t6, %lo(dword_CODE_bss_80071620) # addiu $t6, $t6, 0x1620
  addiu $s3, $s3, -4
  sltu  $at, $s3, $t6
  bnez  $at, .L7F03C094
   mov.s $f24, $f0
  mtc1  $zero, $f22
  addiu $s5, $sp, 0x78
  lw    $s0, ($s3)
.L7F03BE68:
  li    $at, 0x43FA0000 # 500.000000
  beqz  $s0, .L7F03C07C
   nop   
  lwc1  $f4, 0x18($s0)
  mtc1  $at, $f6
  nop   
  c.lt.s $f4, $f6
  nop   
  bc1f  .L7F03C07C
   nop   
  lbu   $v0, ($s0)
  li    $at, 3
  beq   $v0, $at, .L7F03BEC8
   li    $at, 6
  bne   $v0, $at, .L7F03C07C
   nop   
  lw    $t7, 4($s0)
  beqz  $t7, .L7F03C07C
   nop   
  jal   sub_GAME_7F09B15C
   move  $a0, $s0
  jal   get_cur_playernum
   move  $s1, $v0
  beq   $v0, $s1, .L7F03C07C
.L7F03BEC8:
   li    $at, 0x42480000 # 50.000000
  mtc1  $at, $f20
  jal   getCurrentWeaponOrItem
   lw    $s2, 4($s0)
  li    $at, 17
  bne   $v0, $at, .L7F03BEF0
   addiu $a1, $sp, 0xac
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f20
  nop   
.L7F03BEF0:
  lw    $a0, 0x1c($s2)
  addiu $a2, $sp, 0xa8
  jal   sub_GAME_7F03F748
   move  $a3, $zero
  lwc1  $f8, 0xac($sp)
  lwc1  $f10, 0xa8($sp)
  c.le.s $f22, $f8
  nop   
  bc1f  .L7F03C07C
   nop   
  c.le.s $f10, $f22
  addiu $a1, $sp, 0xa4
  addiu $a2, $sp, 0xa0
  li    $a3, 1
  bc1f  .L7F03C07C
   nop   
  jal   sub_GAME_7F03F748
   lw    $a0, 0x1c($s2)
  lwc1  $f16, 0xa4($sp)
  lwc1  $f18, 0xa0($sp)
  c.le.s $f22, $f16
  nop   
  bc1f  .L7F03C07C
   nop   
  c.le.s $f18, $f22
  addiu $a1, $sp, 0x9c
  addiu $a2, $sp, 0x98
  li    $a3, 2
  bc1f  .L7F03C07C
   nop   
  jal   sub_GAME_7F03F748
   lw    $a0, 0x1c($s2)
  lwc1  $f4, 0x98($sp)
  lwc1  $f6, 0x9c($sp)
  c.le.s $f4, $f22
  nop   
  bc1f  .L7F03C07C
   nop   
  neg.s $f8, $f20
  addiu $a0, $sp, 0x90
  c.le.s $f8, $f6
  li    $t9, 19
  bc1f  .L7F03C07C
   nop   
  lw    $t8, 0x14($s4)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f16
  sw    $t8, 0x90($sp)
  lwc1  $f10, 0x10($s0)
  lw    $a3, 8($s0)
  lw    $a2, 0x10($s4)
  lw    $a1, 8($s4)
  swc1  $f22, 0x20($sp)
  swc1  $f24, 0x1c($sp)
  swc1  $f24, 0x18($sp)
  sw    $t9, 0x14($sp)
  swc1  $f16, 0x24($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f10, 0x10($sp)
  beqz  $v0, .L7F03C07C
   lw    $t0, 0x90($sp)
  lw    $t1, 0x14($s0)
  bne   $t0, $t1, .L7F03C07C
   nop   
  jal   sub_GAME_7F0799F0
   li    $s1, 15
  li    $at, 1
  bne   $v0, $at, .L7F03C00C
   nop   
  b     .L7F03C020
   li    $s1, 200
.L7F03C00C:
  jal   sub_GAME_7F0799F0
   nop   
  bnezl $v0, .L7F03C024
   addiu $a0, $sp, 0x84
  li    $s1, 201
.L7F03C020:
  addiu $a0, $sp, 0x84
.L7F03C024:
  move  $a1, $s5
  jal   sub_GAME_7F0681CC
   lw    $a2, 0xc8($sp)
  jal   sub_GAME_7F078444
   nop   
  move  $a0, $v0
  jal   sub_GAME_7F0583D8
   move  $a1, $s5
  li    $t2, 1
  sw    $t2, 0x10($sp)
  move  $a0, $s2
  move  $a1, $s1
  move  $a2, $s5
  jal   handles_shot_actors
   move  $a3, $s6
  beqz  $v0, .L7F03C07C
   move  $a0, $s6
  li    $t3, 1
  sw    $t3, 0xbc($sp)
  move  $a1, $s0
  jal   recall_joy2_hits_edit_detail_edit_flag
   li    $a2, -1
.L7F03C07C:
  lui   $t4, %hi(dword_CODE_bss_80071620) 
  addiu $t4, %lo(dword_CODE_bss_80071620) # addiu $t4, $t4, 0x1620
  addiu $s3, $s3, -4
  sltu  $at, $s3, $t4
  beql  $at, $zero, .L7F03BE68
   lw    $s0, ($s3)
.L7F03C094:
  lw    $t5, 0xbc($sp)
  li    $at, 1
  bnezl $t5, .L7F03C0C0
   lw    $ra, 0x64($sp)
  bne   $s6, $at, .L7F03C0BC
   lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 105
  jal   play_sfx_a1
   move  $a2, $zero
.L7F03C0BC:
  lw    $ra, 0x64($sp)
.L7F03C0C0:
  ldc1  $f20, 0x30($sp)
  ldc1  $f22, 0x38($sp)
  ldc1  $f24, 0x40($sp)
  lw    $s0, 0x48($sp)
  lw    $s1, 0x4c($sp)
  lw    $s2, 0x50($sp)
  lw    $s3, 0x54($sp)
  lw    $s4, 0x58($sp)
  lw    $s5, 0x5c($sp)
  lw    $s6, 0x60($sp)
  jr    $ra
   addiu $sp, $sp, 0xc8
");

asm(R"
glabel sub_GAME_7F03C0F0
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  jal   get_hands_firing_status
   move  $s0, $a0
  beql  $v0, $zero, .L7F03C284
   lw    $ra, 0x1c($sp)
  jal   get_item_in_hand
   move  $a0, $s0
  li    $at, 30
  bne   $v0, $at, .L7F03C130
   move  $a2, $v0
  jal   trigger_remote_mine_detonation
   nop   
  b     .L7F03C284
   lw    $ra, 0x1c($sp)
.L7F03C130:
  li    $at, 24
  beq   $v0, $at, .L7F03C280
   li    $at, 25
  beq   $v0, $at, .L7F03C280
   li    $at, 26
  beq   $v0, $at, .L7F03C280
   li    $at, 3
  beq   $v0, $at, .L7F03C280
   li    $at, 29
  beq   $v0, $at, .L7F03C280
   li    $at, 28
  beq   $v0, $at, .L7F03C280
   li    $at, 27
  beq   $v0, $at, .L7F03C280
   li    $at, 35
  beq   $v0, $at, .L7F03C280
   li    $at, 36
  beq   $v0, $at, .L7F03C280
   li    $at, 33
  beq   $v0, $at, .L7F03C280
   li    $at, 47
  beq   $v0, $at, .L7F03C280
   li    $at, 48
  beq   $v0, $at, .L7F03C280
   li    $at, 61
  beq   $v0, $at, .L7F03C280
   li    $at, 88
  beq   $v0, $at, .L7F03C280
   li    $at, 34
  beq   $v0, $at, .L7F03C280
   li    $at, 32
  bnel  $v0, $at, .L7F03C1C8
   li    $at, 1
  jal   sub_GAME_7F05FB64
   move  $a0, $s0
  b     .L7F03C284
   lw    $ra, 0x1c($sp)
  li    $at, 1
.L7F03C1C8:
  beq   $v0, $at, .L7F03C1DC
   move  $a0, $s0
  li    $at, 2
  bnel  $v0, $at, .L7F03C1F0
   li    $at, 15
.L7F03C1DC:
  jal   sub_GAME_7F03BDEC
   move  $a1, $a2
  b     .L7F03C284
   lw    $ra, 0x1c($sp)
  li    $at, 15
.L7F03C1F0:
  beq   $v0, $at, .L7F03C204
   move  $a0, $a2
  li    $at, 16
  bnel  $v0, $at, .L7F03C23C
   li    $at, 40
.L7F03C204:
  jal   inc_curplayer_hitcount_with_weapon
   move  $a1, $zero
  move  $v0, $zero
  move  $a0, $s0
.L7F03C214:
  jal   sub_GAME_7F03B15C
   sw    $v0, 0x20($sp)
  lw    $v0, 0x20($sp)
  li    $at, 5
  addiu $v0, $v0, 1
  bnel  $v0, $at, .L7F03C214
   move  $a0, $s0
  b     .L7F03C284
   lw    $ra, 0x1c($sp)
  li    $at, 40
.L7F03C23C:
  bnel  $v0, $at, .L7F03C258
   li    $at, 60
  jal   sub_GAME_7F057898
   nop   
  b     .L7F03C284
   lw    $ra, 0x1c($sp)
  li    $at, 60
.L7F03C258:
  bne   $v0, $at, .L7F03C270
   move  $a0, $a2
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  b     .L7F03C280
   sw    $zero, 0x1270($t6)
.L7F03C270:
  jal   inc_curplayer_hitcount_with_weapon
   move  $a1, $zero
  jal   sub_GAME_7F03B15C
   move  $a0, $s0
.L7F03C280:
  lw    $ra, 0x1c($sp)
.L7F03C284:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F03C294
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F03C0F0
   move  $a0, $zero
  jal   sub_GAME_7F03C0F0
   li    $a0, 1
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F03C2BC
  addiu $sp, $sp, -0x20
  sw    $s0, 0x18($sp)
  li    $v1, 1
  move  $s0, $a0
  bne   $a1, $v1, .L7F03C374
   sw    $ra, 0x1c($sp)
  lbu   $v0, ($a0)
  li    $at, 4
  beql  $v0, $at, .L7F03C2F0
   lw    $v1, 4($s0)
  bne   $v1, $v0, .L7F03C34C
   nop   
  lw    $v1, 4($s0)
.L7F03C2F0:
  li    $t8, 1200
  li    $at, -5
  lbu   $t6, 2($v1)
  move  $a0, $s0
  andi  $t7, $t6, 4
  beqz  $t7, .L7F03C34C
   nop   
  sh    $t8, 2($s0)
  lw    $t9, 0x64($v1)
  lbu   $t3, 2($v1)
  mtc1  $zero, $f4
  ori   $t0, $t9, 0x800
  sw    $t0, 0x64($v1)
  and   $t2, $t0, $at
  andi  $t4, $t3, 0xff7f
  sw    $t2, 0x64($v1)
  sb    $t4, 2($v1)
  jal   sub_GAME_7F03E18C
   swc1  $f4, 0x70($v1)
  jal   unset_stateflag_0x04_for_posdata
   move  $a0, $s0
  b     .L7F03C3EC
   lw    $ra, 0x1c($sp)
.L7F03C34C:
  jal   sub_GAME_7F03E18C
   move  $a0, $s0
  jal   sub_GAME_7F03A538
   move  $a0, $s0
  jal   unset_stateflag_0x04_for_posdata
   move  $a0, $s0
  jal   set_last_obj_pos_data
   move  $a0, $s0
  b     .L7F03C3EC
   lw    $ra, 0x1c($sp)
.L7F03C374:
  li    $at, 2
  bnel  $a1, $at, .L7F03C3A4
   li    $at, 4
  jal   sub_GAME_7F03E18C
   move  $a0, $s0
  jal   sub_GAME_7F03A538
   move  $a0, $s0
  jal   unset_stateflag_0x04_for_posdata
   move  $a0, $s0
  b     .L7F03C3EC
   lw    $ra, 0x1c($sp)
  li    $at, 4
.L7F03C3A4:
  bnel  $a1, $at, .L7F03C3EC
   lw    $ra, 0x1c($sp)
  jal   sub_GAME_7F03E18C
   move  $a0, $s0
  jal   sub_GAME_7F03A538
   move  $a0, $s0
  jal   unset_stateflag_0x04_for_posdata
   move  $a0, $s0
  jal   sub_GAME_7F04C044
   move  $a0, $s0
  jal   sub_GAME_7F040CF0
   move  $a0, $s0
  jal   get_curplayer_positiondata
   nop   
  move  $a0, $s0
  jal   sub_GAME_7F03A5A4
   move  $a1, $v0
  lw    $ra, 0x1c($sp)
.L7F03C3EC:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F03C3FC
  addiu $sp, $sp, -0x38
  sw    $s0, 0x14($sp)
  lui   $s0, %hi(dword_CODE_bss_80071DF0)
  lw    $s0, %lo(dword_CODE_bss_80071DF0)($s0)
  sw    $s7, 0x30($sp)
  lui   $s7, %hi(dword_CODE_bss_80071620) 
  lui   $at, %hi(dword_CODE_bss_80071DF8)
  addiu $s7, %lo(dword_CODE_bss_80071620) # addiu $s7, $s7, 0x1620
  sw    $zero, %lo(dword_CODE_bss_80071DF8)($at)
  addiu $s0, $s0, -4
  sltu  $at, $s0, $s7
  sw    $ra, 0x34($sp)
  sw    $s6, 0x2c($sp)
  sw    $s5, 0x28($sp)
  sw    $s4, 0x24($sp)
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  bnez  $at, .L7F03C4BC
   li    $v1, 1
  li    $s4, 2
  li    $s3, 4
  li    $s2, 1
  li    $s1, 3
  lw    $a0, ($s0)
.L7F03C460:
  beql  $a0, $zero, .L7F03C4B0
   addiu $s0, $s0, -4
  lbu   $v0, ($a0)
  beq   $s1, $v0, .L7F03C4A8
   nop   
  beq   $s2, $v0, .L7F03C484
   nop   
  bne   $s3, $v0, .L7F03C494
   nop   
.L7F03C484:
  jal   sub_GAME_7F04EF58
   nop   
  b     .L7F03C4A8
   move  $v1, $v0
.L7F03C494:
  bne   $s4, $v0, .L7F03C4A8
   nop   
  jal   sub_GAME_7F055804
   nop   
  move  $v1, $v0
.L7F03C4A8:
  beqz  $v1, .L7F03C4BC
   addiu $s0, $s0, -4
.L7F03C4B0:
  sltu  $at, $s0, $s7
  beql  $at, $zero, .L7F03C460
   lw    $a0, ($s0)
.L7F03C4BC:
  lw    $ra, 0x34($sp)
  lui   $v0, %hi(dword_CODE_bss_80071DF8)
  lw    $v0, %lo(dword_CODE_bss_80071DF8)($v0)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  lw    $s4, 0x24($sp)
  lw    $s5, 0x28($sp)
  lw    $s6, 0x2c($sp)
  lw    $s7, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x38
");

asm(R"
.late_rodata
/*D:80052980*/
glabel jpt_80052980
.word loc_CODE_7F03C534
.word loc_CODE_7F03C544
.word def_7F03C52C
.word loc_CODE_7F03C534
.word def_7F03C52C
.word def_7F03C52C
.word def_7F03C52C
.word def_7F03C52C

.text
glabel sub_GAME_7F03C4F0
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F03C3FC
   nop   
  sw    $v0, 0x1c($sp)
  beqz  $v0, .L7F03C560
   move  $a1, $zero
  lbu   $t6, ($v0)
  addiu $t7, $t6, -1
  sltiu $at, $t7, 8
  beqz  $at, .L7F03C550
   sll   $t7, $t7, 2
  lui   $at, %hi(jpt_80052980)
  addu  $at, $at, $t7
  lw    $t7, %lo(jpt_80052980)($at)
  jr    $t7
   nop   
loc_CODE_7F03C534:
  jal   sub_GAME_7F04F170
   lw    $a0, 0x1c($sp)
  b     .L7F03C550
   move  $a1, $v0
loc_CODE_7F03C544:
  jal   sub_GAME_7F055C40
   lw    $a0, 0x1c($sp)
  move  $a1, $v0
def_7F03C52C:
.L7F03C550:
  jal   sub_GAME_7F03C2BC
   lw    $a0, 0x1c($sp)
  b     .L7F03C564
   move  $v0, $zero
.L7F03C560:
  li    $v0, 1
.L7F03C564:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F03C574
  addiu $sp, $sp, -0x48
  sw    $ra, 0x2c($sp)
  sw    $s2, 0x24($sp)
  move  $s2, $a0
  sw    $s3, 0x28($sp)
  sw    $s1, 0x20($sp)
  sw    $s0, 0x1c($sp)
  jal   getPlayerCount
   sdc1  $f20, 0x10($sp)
  li    $t6, 1
  move  $s3, $v0
  sw    $t6, 0x30($sp)
  blez  $v0, .L7F03C624
   move  $s0, $zero
  li    $at, 0x43C80000 # 400.000000
  lui   $s1, %hi(players_p1)
  mtc1  $at, $f20
  addiu $s1, %lo(players_p1) # addiu $s1, $s1, -0x6120
.L7F03C5BC:
  lw    $t7, ($s1)
  lwc1  $f6, 8($s2)
  lwc1  $f10, 0xc($s2)
  lw    $v0, 0xa8($t7)
  lwc1  $f18, 0x10($s2)
  lwc1  $f4, 8($v0)
  lwc1  $f8, 0xc($v0)
  lwc1  $f16, 0x10($v0)
  sub.s $f0, $f4, $f6
  sub.s $f2, $f8, $f10
  mul.s $f4, $f0, $f0
  sub.s $f14, $f16, $f18
  mul.s $f6, $f2, $f2
  add.s $f8, $f4, $f6
  mul.s $f10, $f14, $f14
  jal   sqrtf
   add.s $f12, $f8, $f10
  c.lt.s $f0, $f20
  addiu $s0, $s0, 1
  slt   $at, $s0, $s3
  bc1f  .L7F03C61C
   nop   
  b     .L7F03C624
   sw    $zero, 0x30($sp)
.L7F03C61C:
  bnez  $at, .L7F03C5BC
   addiu $s1, $s1, 4
.L7F03C624:
  lw    $ra, 0x2c($sp)
  lw    $v0, 0x30($sp)
  ldc1  $f20, 0x10($sp)
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  lw    $s2, 0x24($sp)
  lw    $s3, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x48
");

asm(R"
glabel handle_mp_respawn_and_some_things
  addiu $sp, $sp, -0x58
  sw    $ra, 0x24($sp)
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  jal   sub_GAME_7F03291C
   sw    $s0, 0x14($sp)
  jal   get_ptr_obj_pos_list_current_entry
   nop   
  beqz  $v0, .L7F03CA14
   move  $s1, $v0
.L7F03C674:
  lw    $t6, 0x24($s1)
  li    $at, 3
  move  $s2, $zero
  sw    $t6, 0x4c($sp)
  lbu   $v0, ($s1)
  bnel  $v0, $at, .L7F03C6B0
   li    $at, 1
  lw    $s0, 4($s1)
  jal   sub_GAME_7F062B00
   addiu $a0, $s0, 0x180
  jal   sub_GAME_7F062B00
   addiu $a0, $s0, 0x1ac
  b     .L7F03C9C4
   li    $at, 5
  li    $at, 1
.L7F03C6B0:
  beq   $v0, $at, .L7F03C6C8
   li    $at, 4
  beq   $v0, $at, .L7F03C6C8
   li    $at, 2
  bnel  $v0, $at, .L7F03C90C
   li    $at, 7
.L7F03C6C8:
  lh    $v0, 2($s1)
  lw    $s0, 4($s1)
  move  $s3, $zero
  blez  $v0, .L7F03C8E4
   slti  $at, $v0, 0x3c
  bnez  $at, .L7F03C6E8
   li    $v1, 1
  move  $v1, $zero
.L7F03C6E8:
  lui   $t7, %hi(clock_timer) 
  lw    $t7, %lo(clock_timer)($t7)
  subu  $t8, $v0, $t7
  sh    $t8, 2($s1)
  lh    $t9, 2($s1)
  slti  $at, $t9, 0x3c
  beql  $at, $zero, .L7F03C730
   lh    $v0, 2($s1)
  bnez  $v1, .L7F03C72C
   move  $a0, $s1
  jal   sub_GAME_7F03C574
   sw    $v1, 0x38($sp)
  bnez  $v0, .L7F03C72C
   lw    $v1, 0x38($sp)
  lh    $t0, 2($s1)
  addiu $t1, $t0, 0x3c
  sh    $t1, 2($s1)
.L7F03C72C:
  lh    $v0, 2($s1)
.L7F03C730:
  bgtz  $v0, .L7F03C770
   slti  $at, $v0, 0x3c
  sh    $zero, 2($s1)
  lbu   $t2, 2($s0)
  andi  $t3, $t2, 0x10
  beql  $t3, $zero, .L7F03C760
   lw    $t6, 0x64($s0)
  lw    $t4, 0x64($s0)
  ori   $t5, $t4, 0x1000
  b     .L7F03C8E4
   sw    $t5, 0x64($s0)
  lw    $t6, 0x64($s0)
.L7F03C760:
  li    $at, -4097
  and   $t7, $t6, $at
  b     .L7F03C8E4
   sw    $t7, 0x64($s0)
.L7F03C770:
  beql  $at, $zero, .L7F03C8E8
   lbu   $t9, 3($s0)
  bnezl $v1, .L7F03C8E8
   lbu   $t9, 3($s0)
  mtc1  $zero, $f0
  lwc1  $f4, 0x70($s0)
  c.eq.s $f0, $f4
  nop   
  bc1fl .L7F03C868
   lbu   $t0, 2($s0)
  lbu   $t8, 2($s0)
  andi  $t9, $t8, 0x80
  bnezl $t9, .L7F03C868
   lbu   $t0, 2($s0)
  lw    $t0, 8($s0)
  andi  $t1, $t0, 0x8000
  beqz  $t1, .L7F03C840
   nop   
  jal   sub_GAME_7F03E18C
   move  $a0, $s1
  jal   sub_GAME_7F03A538
   move  $a0, $s1
  lw    $t2, 0x64($s0)
  li    $at, -2049
  move  $a0, $s1
  and   $t3, $t2, $at
  jal   sub_GAME_7F056BA8
   sw    $t3, 0x64($s0)
  sw    $v0, 0x30($sp)
  lh    $t4, 6($s0)
  jal   sub_GAME_7F0BDF04
   sw    $t4, 0x2c($sp)
  lw    $t5, 0x30($sp)
  lw    $t6, 0x2c($sp)
  move  $a0, $v0
  jal   sub_GAME_7F056EA0
   addu  $a1, $t5, $t6
  beql  $v0, $zero, .L7F03C8B0
   lbu   $t8, 3($s0)
  lw    $t7, 0x10($v0)
  beql  $t7, $zero, .L7F03C8B0
   lbu   $t8, 3($s0)
  lw    $a0, 0x14($s0)
  lw    $a1, 0x14($a0)
  jal   set_obj_instance_controller_scale
   sw    $v0, 0x28($sp)
  lw    $v1, 0x28($sp)
  lw    $a0, 0x10($s0)
  jal   sub_GAME_7F03A5A4
   lw    $a1, 0x10($v1)
  b     .L7F03C8AC
   li    $s3, 1
.L7F03C840:
  jal   set_stateflag_0x04_for_posdata
   move  $a0, $s1
  jal   sub_GAME_7F03E134
   move  $a0, $s1
  lw    $t8, 0x64($s0)
  li    $at, -2049
  and   $t9, $t8, $at
  b     .L7F03C8AC
   sw    $t9, 0x64($s0)
  lbu   $t0, 2($s0)
.L7F03C868:
  andi  $t1, $t0, 8
  beql  $t1, $zero, .L7F03C888
   lw    $t4, 8($s0)
  lw    $t2, 8($s0)
  ori   $t3, $t2, 0x100
  b     .L7F03C894
   sw    $t3, 8($s0)
  lw    $t4, 8($s0)
.L7F03C888:
  li    $at, -257
  and   $t5, $t4, $at
  sw    $t5, 8($s0)
.L7F03C894:
  lbu   $t6, 2($s0)
  swc1  $f0, 0x70($s0)
  lw    $a0, 0x14($s0)
  andi  $t7, $t6, 0xff7f
  jal   sub_GAME_7F050DE8
   sb    $t7, 2($s0)
.L7F03C8AC:
  lbu   $t8, 3($s0)
.L7F03C8B0:
  li    $at, 21
  lui   $a0, %hi(ptr_sfx_buf)
  bne   $t8, $at, .L7F03C8C8
   li    $a1, 82
  lwc1  $f6, 0x80($s0)
  swc1  $f6, 0x84($s0)
.L7F03C8C8:
  bnez  $s3, .L7F03C8E4
   move  $a2, $zero
  jal   play_sfx_a1
   lw    $a0, %lo(ptr_sfx_buf)($a0)
  move  $a0, $v0
  jal   sub_GAME_7F053A10
   addiu $a1, $s1, 8
.L7F03C8E4:
  lbu   $t9, 3($s0)
.L7F03C8E8:
  li    $at, 13
  bnel  $t9, $at, .L7F03C9C4
   li    $at, 5
  lw    $v0, 4($s1)
  jal   sub_GAME_7F062B00
   lw    $a0, 0xcc($v0)
  b     .L7F03C9C4
   li    $at, 5
  li    $at, 7
.L7F03C90C:
  bnel  $v0, $at, .L7F03C928
   li    $at, 8
  jal   sub_GAME_7F09CEE8
   move  $a0, $s1
  b     .L7F03C9C0
   move  $s2, $v0
  li    $at, 8
.L7F03C928:
  bnel  $v0, $at, .L7F03C944
   li    $at, 6
  jal   sub_GAME_7F09E8AC
   move  $a0, $s1
  b     .L7F03C9C0
   move  $s2, $v0
  li    $at, 6
.L7F03C944:
  bnel  $v0, $at, .L7F03C9C4
   li    $at, 5
  jal   sub_GAME_7F09B15C
   move  $a0, $s1
  sll   $t0, $v0, 2
  lui   $a0, %hi(players_p1)
  addu  $a0, $a0, $t0
  lw    $a0, %lo(players_p1)($a0)
  jal   sub_GAME_7F062B00
   addiu $a0, $a0, 0xa54
  jal   sub_GAME_7F09B15C
   move  $a0, $s1
  sll   $t1, $v0, 2
  lui   $a0, %hi(players_p1)
  addu  $a0, $a0, $t1
  lw    $a0, %lo(players_p1)($a0)
  jal   sub_GAME_7F062B00
   addiu $a0, $a0, 0xdfc
  lw    $t2, 4($s1)
  beql  $t2, $zero, .L7F03C9C4
   li    $at, 5
  jal   getPlayerCount
   nop   
  slti  $at, $v0, 2
  bnezl $at, .L7F03C9C4
   li    $at, 5
  lw    $s0, 4($s1)
  jal   sub_GAME_7F062B00
   addiu $a0, $s0, 0x180
  jal   sub_GAME_7F062B00
   addiu $a0, $s0, 0x1ac
.L7F03C9C0:
  li    $at, 5
.L7F03C9C4:
  bnel  $s2, $at, .L7F03C9D8
   li    $at, 3
  b     .L7F03CA0C
   lw    $s0, 0x4c($sp)
  li    $at, 3
.L7F03C9D8:
  bne   $s2, $at, .L7F03CA00
   lw    $s0, 0x24($s1)
  jal   sub_GAME_7F03A538
   move  $a0, $s1
  jal   sub_GAME_7F03A4F0
   move  $a0, $s1
  bnez  $s0, .L7F03CA0C
   nop   
  b     .L7F03CA0C
   move  $s0, $s1
.L7F03CA00:
  move  $a0, $s1
  jal   sub_GAME_7F03C2BC
   move  $a1, $s2
.L7F03CA0C:
  bnez  $s0, .L7F03C674
   move  $s1, $s0
.L7F03CA14:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x58
");

asm(R"
glabel determing_type_of_object_and_detection
  addiu $sp, $sp, -0x28
  sw    $ra, 0x24($sp)
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  jal   get_ptr_obj_pos_list_current_entry
   sw    $s0, 0x14($sp)
  beqz  $v0, .L7F03CB40
   move  $s0, $v0
  li    $s3, 3
.L7F03CA58:
  lbu   $v0, ($s0)
  move  $a1, $zero
  lw    $s2, 0x24($s0)
  bne   $s3, $v0, .L7F03CA7C
   li    $at, 1
  jal   sub_GAME_7F020EF0
   move  $a0, $s0
  b     .L7F03CAF4
   move  $a1, $v0
.L7F03CA7C:
  beq   $v0, $at, .L7F03CA94
   li    $at, 4
  beq   $v0, $at, .L7F03CA94
   li    $at, 2
  bnel  $v0, $at, .L7F03CAA8
   li    $at, 7
.L7F03CA94:
  jal   object_interaction
   move  $a0, $s0
  b     .L7F03CAF4
   move  $a1, $v0
  li    $at, 7
.L7F03CAA8:
  bnel  $v0, $at, .L7F03CAC4
   li    $at, 8
  jal   sub_GAME_7F09D4EC
   move  $a0, $s0
  b     .L7F03CAF4
   move  $a1, $v0
  li    $at, 8
.L7F03CAC4:
  bnel  $v0, $at, .L7F03CAE0
   li    $at, 6
  jal   sub_GAME_7F09EF9C
   move  $a0, $s0
  b     .L7F03CAF4
   move  $a1, $v0
  li    $at, 6
.L7F03CAE0:
  bnel  $v0, $at, .L7F03CAF8
   li    $at, 5
  jal   sub_GAME_7F08B0F0
   move  $a0, $s0
  move  $a1, $v0
.L7F03CAF4:
  li    $at, 5
.L7F03CAF8:
  bne   $a1, $at, .L7F03CB08
   nop   
  b     .L7F03CB38
   move  $s1, $s2
.L7F03CB08:
  bne   $a1, $s3, .L7F03CB30
   lw    $s1, 0x24($s0)
  jal   sub_GAME_7F03A538
   move  $a0, $s0
  jal   sub_GAME_7F03A4F0
   move  $a0, $s0
  bnez  $s1, .L7F03CB38
   nop   
  b     .L7F03CB38
   move  $s1, $s0
.L7F03CB30:
  jal   sub_GAME_7F03C2BC
   move  $a0, $s0
.L7F03CB38:
  bnez  $s1, .L7F03CA58
   move  $s0, $s1
.L7F03CB40:
  jal   get_cur_playernum
   nop   
  jal   sub_GAME_7F09B4D8
   move  $a0, $v0
  bnezl $v0, .L7F03CB74
   lw    $ra, 0x24($sp)
  jal   handle_alarm_gas_timer_calldamage
   nop   
  jal   loop_set_sound_effect_all_slots
   nop   
  jal   sub_GAME_7F03E4F0
   nop   
  lw    $ra, 0x24($sp)
.L7F03CB74:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
glabel sub_GAME_7F03CB8C
  lw    $v0, 0x14($a0)
  li    $t6, -1
  bnezl $v0, .L7F03CBA8
   lbu   $t7, ($a0)
  jr    $ra
   sw    $t6, ($a1)

  lbu   $t7, ($a0)
.L7F03CBA8:
  li    $at, 6
  li    $t3, -1
  bnel  $t7, $at, .L7F03CBDC
   lbu   $t2, 0x2c($a0)
  lw    $t8, 4($a0)
  li    $t1, -1
  bnezl $t8, .L7F03CBDC
   lbu   $t2, 0x2c($a0)
  lbu   $t9, 3($v0)
  sw    $t1, 4($a1)
  jr    $ra
   sw    $t9, ($a1)

  lbu   $t2, 0x2c($a0)
.L7F03CBDC:
  li    $t0, 255
  move  $v0, $zero
  beq   $t0, $t2, .L7F03CC0C
   move  $v1, $a1
  move  $a2, $a0
  lbu   $a3, 0x2c($a0)
.L7F03CBF4:
  sw    $a3, ($v1)
  lbu   $a3, 0x2d($a2)
  addiu $v0, $v0, 1
  addiu $v1, $v1, 4
  bne   $t0, $a3, .L7F03CBF4
   addiu $a2, $a2, 1
.L7F03CC0C:
  sll   $t4, $v0, 2
  addu  $t5, $a1, $t4
  sw    $t3, ($t5)
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F03CC20
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $zero, ($a1)
  sw    $zero, ($a2)
  lbu   $v0, ($a0)
  li    $at, 3
  lw    $t6, 0x30($sp)
  bnel  $v0, $at, .L7F03CC58
   li    $at, 6
  jal   sub_GAME_7F02308C
   sw    $t6, 0x10($sp)
  b     .L7F03CCA4
   lw    $ra, 0x1c($sp)
  li    $at, 6
.L7F03CC58:
  bne   $v0, $at, .L7F03CC70
   lw    $t7, 0x30($sp)
  jal   sub_GAME_7F08A0B0
   sw    $t7, 0x10($sp)
  b     .L7F03CCA4
   lw    $ra, 0x1c($sp)
.L7F03CC70:
  li    $at, 4
  beq   $v0, $at, .L7F03CCA0
   li    $at, 1
  beq   $v0, $at, .L7F03CC90
   lw    $t8, 0x30($sp)
  li    $at, 2
  bne   $v0, $at, .L7F03CCA0
   nop   
.L7F03CC90:
  jal   sub_GAME_7F04F244
   sw    $t8, 0x10($sp)
  b     .L7F03CCA4
   lw    $ra, 0x1c($sp)
.L7F03CCA0:
  lw    $ra, 0x1c($sp)
.L7F03CCA4:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F03CCB0
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  addiu $t6, $sp, 0x20
  sw    $t6, 0x10($sp)
  jal   sub_GAME_7F03CC20
   addiu $a3, $sp, 0x24
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F03CCD8
  bgtz  $a2, .L7F03CCE8
   li    $v0, -1
  jr    $ra
   move  $v0, $zero

.L7F03CCE8:
  blez  $a2, .L7F03CF7C
   move  $v1, $zero
  andi  $a3, $a2, 1
  beqz  $a3, .L7F03CD9C
   li    $t1, -1
  li    $t6, 1
  div   $zero, $t6, $a2
  mfhi  $t7
  sll   $t8, $t7, 3
  addu  $v1, $a1, $t8
  lwc1  $f4, 4($v1)
  lwc1  $f2, 4($a1)
  lwc1  $f12, ($a1)
  lwc1  $f8, ($a0)
  sub.s $f6, $f4, $f2
  mtc1  $zero, $f18
  bnez  $a2, .L7F03CD34
   nop   
  break 7
.L7F03CD34:
  li    $at, -1
  bne   $a2, $at, .L7F03CD4C
   lui   $at, 0x8000
  bne   $t6, $at, .L7F03CD4C
   nop   
  break 6
.L7F03CD4C:
  sub.s $f10, $f8, $f12
  lwc1  $f8, 8($a0)
  move  $a3, $a1
  mul.s $f4, $f6, $f10
  lwc1  $f10, ($v1)
  sub.s $f6, $f8, $f2
  li    $v1, 1
  sub.s $f8, $f10, $f12
  mul.s $f10, $f6, $f8
  sub.s $f0, $f4, $f10
  c.eq.s $f0, $f18
  nop   
  bc1t  .L7F03CD98
   nop   
  c.lt.s $f18, $f0
  move  $v0, $zero
  bc1f  .L7F03CD98
   nop   
  li    $v0, 1
.L7F03CD98:
  beq   $v1, $a2, .L7F03CF7C
.L7F03CD9C:
   sll   $t9, $v1, 3
  mtc1  $zero, $f18
  addu  $a3, $a1, $t9
  lwc1  $f12, ($a0)
  lwc1  $f16, 8($a0)
.L7F03CDB0:
  addiu $t2, $v1, 1
  div   $zero, $t2, $a2
  mfhi  $t3
  sll   $t4, $t3, 3
  addu  $a0, $a1, $t4
  lwc1  $f6, 4($a0)
  lwc1  $f2, 4($a3)
  lwc1  $f14, ($a3)
  bnez  $a2, .L7F03CDDC
   nop   
  break 7
.L7F03CDDC:
  li    $at, -1
  bne   $a2, $at, .L7F03CDF4
   lui   $at, 0x8000
  bne   $t2, $at, .L7F03CDF4
   nop   
  break 6
.L7F03CDF4:
  sub.s $f8, $f6, $f2
  sub.s $f4, $f12, $f14
  sub.s $f6, $f16, $f2
  mul.s $f10, $f8, $f4
  lwc1  $f8, ($a0)
  addiu $a0, $v1, 2
  sub.s $f4, $f8, $f14
  mul.s $f8, $f6, $f4
  sub.s $f0, $f10, $f8
  c.eq.s $f0, $f18
  nop   
  bc1t  .L7F03CE94
   nop   
  beql  $v1, $zero, .L7F03CE3C
   c.lt.s $f18, $f0
  bgez  $v0, .L7F03CE54
   nop   
  c.lt.s $f18, $f0
.L7F03CE3C:
  move  $v0, $zero
  bc1f  .L7F03CE94
   nop   
  li    $v0, 1
  b     .L7F03CE94
   nop   
.L7F03CE54:
  beqz  $v0, .L7F03CE74
   nop   
  c.lt.s $f0, $f18
  nop   
  bc1f  .L7F03CE74
   nop   
  jr    $ra
   move  $v0, $zero

.L7F03CE74:
  bnez  $v0, .L7F03CE94
   nop   
  c.lt.s $f18, $f0
  nop   
  bc1f  .L7F03CE94
   nop   
  jr    $ra
   move  $v0, $zero

.L7F03CE94:
  div   $zero, $a0, $a2
  mfhi  $t5
  sll   $t6, $t5, 3
  addu  $t0, $a1, $t6
  lwc1  $f6, 4($t0)
  lwc1  $f2, 0xc($a3)
  lwc1  $f14, 8($a3)
  bnez  $a2, .L7F03CEBC
   nop   
  break 7
.L7F03CEBC:
  li    $at, -1
  bne   $a2, $at, .L7F03CED4
   lui   $at, 0x8000
  bne   $a0, $at, .L7F03CED4
   nop   
  break 6
.L7F03CED4:
  sub.s $f4, $f6, $f2
  addiu $a3, $a3, 0x10
  sub.s $f10, $f12, $f14
  sub.s $f6, $f16, $f2
  mul.s $f8, $f4, $f10
  lwc1  $f4, ($t0)
  sub.s $f10, $f4, $f14
  mul.s $f4, $f6, $f10
  sub.s $f0, $f8, $f4
  c.eq.s $f0, $f18
  nop   
  bc1t  .L7F03CF74
   nop   
  beql  $v1, $t1, .L7F03CF1C
   c.lt.s $f18, $f0
  bgez  $v0, .L7F03CF34
   nop   
  c.lt.s $f18, $f0
.L7F03CF1C:
  move  $v0, $zero
  bc1f  .L7F03CF74
   nop   
  li    $v0, 1
  b     .L7F03CF74
   nop   
.L7F03CF34:
  beqz  $v0, .L7F03CF54
   nop   
  c.lt.s $f0, $f18
  nop   
  bc1f  .L7F03CF54
   nop   
  jr    $ra
   move  $v0, $zero

.L7F03CF54:
  bnez  $v0, .L7F03CF74
   nop   
  c.lt.s $f18, $f0
  nop   
  bc1f  .L7F03CF74
   nop   
  jr    $ra
   move  $v0, $zero

.L7F03CF74:
  bne   $a0, $a2, .L7F03CDB0
   move  $v1, $a0
.L7F03CF7C:
  li    $v0, 1
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F03CF88
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lbu   $v0, ($a0)
  li    $at, 3
  bnel  $v0, $at, .L7F03CFB4
   li    $at, 6
  jal   sub_GAME_7F023160
   nop   
  b     .L7F03CFDC
   lw    $ra, 0x14($sp)
  li    $at, 6
.L7F03CFB4:
  bnel  $v0, $at, .L7F03CFD0
   mtc1  $zero, $f4
  jal   sub_GAME_7F08A274
   nop   
  b     .L7F03CFDC
   lw    $ra, 0x14($sp)
  mtc1  $zero, $f4
.L7F03CFD0:
  nop   
  swc1  $f4, ($a1)
  lw    $ra, 0x14($sp)
.L7F03CFDC:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F03CFE8
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lbu   $v0, ($a0)
  li    $at, 3
  bnel  $v0, $at, .L7F03D014
   li    $at, 6
  jal   sub_GAME_7F023188
   nop   
  b     .L7F03D04C
   lw    $ra, 0x14($sp)
  li    $at, 6
.L7F03D014:
  bnel  $v0, $at, .L7F03D044
   mtc1  $zero, $f0
  jal   sub_GAME_7F09B15C
   nop   
  sll   $t6, $v0, 2
  lui   $a0, %hi(players_p1)
  addu  $a0, $a0, $t6
  jal   sub_GAME_7F089778
   lw    $a0, %lo(players_p1)($a0)
  b     .L7F03D04C
   lw    $ra, 0x14($sp)
  mtc1  $zero, $f0
.L7F03D044:
  nop   
  lw    $ra, 0x14($sp)
.L7F03D04C:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F03D058
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lbu   $v0, ($a0)
  li    $at, 3
  move  $a2, $a0
  bnel  $v0, $at, .L7F03D088
   li    $at, 6
  jal   set_or_unset_GUARDdata_flag
   lw    $a0, 4($a0)
  b     .L7F03D0C8
   lw    $ra, 0x14($sp)
  li    $at, 6
.L7F03D088:
  bnel  $v0, $at, .L7F03D0A4
   li    $at, 1
  jal   sub_GAME_7F08A03C
   move  $a0, $a2
  b     .L7F03D0C8
   lw    $ra, 0x14($sp)
  li    $at, 1
.L7F03D0A4:
  beq   $v0, $at, .L7F03D0BC
   li    $at, 2
  beq   $v0, $at, .L7F03D0BC
   li    $at, 4
  bnel  $v0, $at, .L7F03D0C8
   lw    $ra, 0x14($sp)
.L7F03D0BC:
  jal   sub_GAME_7F04F218
   move  $a0, $a2
  lw    $ra, 0x14($sp)
.L7F03D0C8:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
.late_rodata
/*D:800529A0*/
glabel jpt_800529A0
.word loc_CODE_7F03D144
.word def_7F03D13C
.word def_7F03D13C
.word loc_CODE_7F03D154
.word def_7F03D13C
.word def_7F03D13C
.word def_7F03D13C
.word def_7F03D13C
.text
glabel sub_GAME_7F03D0D4
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  jal   get_intank_flag
   sw    $s0, 0x14($sp)
  bnez  $v0, .L7F03D174
   lui   $t6, %hi(disable_player_pickups_flag) 
  lw    $t6, %lo(disable_player_pickups_flag)($t6)
  bnezl $t6, .L7F03D178
   lw    $ra, 0x1c($sp)
  jal   get_ptr_obj_pos_list_current_entry
   nop   
  beqz  $v0, .L7F03D174
   move  $s1, $v0
.L7F03D10C:
  lh    $t7, 2($s1)
  move  $a1, $zero
  bgtzl $t7, .L7F03D164
   lw    $s0, 0x24($s1)
  lbu   $t8, ($s1)
  addiu $t9, $t8, -1
  sltiu $at, $t9, 8
  beqz  $at, .L7F03D160
   sll   $t9, $t9, 2
  lui   $at, %hi(jpt_800529A0)
  addu  $at, $at, $t9
  lw    $t9, %lo(jpt_800529A0)($at)
  jr    $t9
   nop   
loc_CODE_7F03D144:
  jal   object_collectability_routines
   move  $a0, $s1
  b     .L7F03D160
   move  $a1, $v0
loc_CODE_7F03D154:
  jal   redirect_object_collectability_routines
   move  $a0, $s1
  move  $a1, $v0
def_7F03D13C:
.L7F03D160:
  lw    $s0, 0x24($s1)
.L7F03D164:
  jal   sub_GAME_7F03C2BC
   move  $a0, $s1
  bnez  $s0, .L7F03D10C
   move  $s1, $s0
.L7F03D174:
  lw    $ra, 0x1c($sp)
.L7F03D178:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x20
");

asm(R"
.late_rodata
glabel D_800529C0
.word 0x3e333333 /*0.175*/
glabel D_800529C4
.word 0x3f533333 /*0.82499999*/
.text
glabel sub_GAME_7F03D188
  addiu $sp, $sp, -0xb0
  sw    $ra, 0x2c($sp)
  sw    $a0, 0xb0($sp)
  sw    $a1, 0xb4($sp)
  sw    $a2, 0xb8($sp)
  jal   getPlayer_c_screentop
   sw    $a3, 0xbc($sp)
  jal   getPlayer_c_screenheight
   swc1  $f0, 0x40($sp)
  lui   $at, %hi(D_800529C0)
  lwc1  $f4, %lo(D_800529C0)($at)
  lwc1  $f8, 0x40($sp)
  mul.s $f6, $f0, $f4
  add.s $f10, $f6, $f8
  jal   getPlayer_c_screentop
   swc1  $f10, 0x70($sp)
  jal   getPlayer_c_screenheight
   swc1  $f0, 0x40($sp)
  lui   $at, %hi(D_800529C4)
  lwc1  $f16, %lo(D_800529C4)($at)
  lwc1  $f4, 0x40($sp)
  mul.s $f18, $f0, $f16
  add.s $f6, $f18, $f4
  jal   getPlayer_c_screenleft
   swc1  $f6, 0x6c($sp)
  jal   getPlayer_c_screenwidth
   swc1  $f0, 0x40($sp)
  li    $at, 0x3E800000 # 0.250000
  mtc1  $at, $f8
  lwc1  $f16, 0x40($sp)
  mul.s $f10, $f0, $f8
  add.s $f18, $f10, $f16
  jal   getPlayer_c_screenleft
   swc1  $f18, 0x68($sp)
  jal   getPlayer_c_screenwidth
   swc1  $f0, 0x40($sp)
  li    $at, 0x3F400000 # 0.750000
  mtc1  $at, $f4
  lwc1  $f8, 0x40($sp)
  li    $at, 0xC0000000 # -2.000000
  mul.s $f6, $f0, $f4
  mtc1  $at, $f16
  lw    $a0, 0xb4($sp)
  addiu $a1, $sp, 0xa8
  swc1  $f16, 0x60($sp)
  add.s $f10, $f6, $f8
  jal   sub_GAME_7F077FF4
   swc1  $f10, 0x64($sp)
  lw    $t6, 0xb8($sp)
  lw    $v0, 0xb4($sp)
  addiu $a0, $sp, 0x9c
  lwc1  $f18, ($t6)
  addiu $a1, $sp, 0x94
  swc1  $f18, 0x9c($sp)
  lwc1  $f4, 4($v0)
  swc1  $f4, 0xa0($sp)
  lwc1  $f6, 8($v0)
  jal   sub_GAME_7F077FF4
   swc1  $f6, 0xa4($sp)
  lw    $t7, 0xb8($sp)
  lw    $v0, 0xb4($sp)
  addiu $a0, $sp, 0x9c
  lwc1  $f8, 4($t7)
  addiu $a1, $sp, 0x8c
  swc1  $f8, 0x9c($sp)
  lwc1  $f10, 4($v0)
  swc1  $f10, 0xa0($sp)
  lwc1  $f16, 8($v0)
  jal   sub_GAME_7F077FF4
   swc1  $f16, 0xa4($sp)
  lw    $v0, 0xb4($sp)
  lw    $t8, 0xbc($sp)
  addiu $a0, $sp, 0x9c
  lwc1  $f18, ($v0)
  addiu $a1, $sp, 0x84
  swc1  $f18, 0x9c($sp)
  lwc1  $f4, 4($t8)
  swc1  $f4, 0xa0($sp)
  lwc1  $f6, 8($v0)
  jal   sub_GAME_7F077FF4
   swc1  $f6, 0xa4($sp)
  lw    $t9, 0xb4($sp)
  lw    $t0, 0xbc($sp)
  addiu $a0, $sp, 0x9c
  lwc1  $f8, ($t9)
  addiu $a1, $sp, 0x7c
  swc1  $f8, 0x9c($sp)
  lwc1  $f10, ($t0)
  swc1  $f10, 0xa0($sp)
  lwc1  $f16, 8($t9)
  jal   sub_GAME_7F077FF4
   swc1  $f16, 0xa4($sp)
  lwc1  $f18, 0x80($sp)
  lwc1  $f4, 0x70($sp)
  lwc1  $f6, 0x6c($sp)
  lwc1  $f8, 0x88($sp)
  c.le.s $f4, $f18
  nop   
  bc1fl .L7F03D77C
   lw    $ra, 0x2c($sp)
  c.le.s $f8, $f6
  addiu $a0, $sp, 0x78
  addiu $a1, $sp, 0x74
  bc1fl .L7F03D77C
   lw    $ra, 0x2c($sp)
  jal   sub_GAME_7F068008
   sw    $zero, 0x5c($sp)
  jal   truncf
   lwc1  $f12, 0x94($sp)
  swc1  $f0, 0x94($sp)
  jal   sub_GAME_7F05C440
   lwc1  $f12, 0x8c($sp)
  jal   redirect_get_BONDdata_autoaim_x
   swc1  $f0, 0x8c($sp)
  beqz  $v0, .L7F03D4C4
   lwc1  $f0, 0x78($sp)
  lwc1  $f10, 0x64($sp)
  lwc1  $f16, 0x94($sp)
  lwc1  $f18, 0x8c($sp)
  lwc1  $f4, 0x68($sp)
  c.le.s $f16, $f10
  nop   
  bc1fl .L7F03D508
   lw    $t1, 0x5c($sp)
  c.le.s $f4, $f18
  li    $at, 0x3FC00000 # 1.500000
  bc1fl .L7F03D508
   lw    $t1, 0x5c($sp)
  sub.s $f6, $f18, $f16
  mtc1  $at, $f8
  nop   
  mul.s $f10, $f6, $f8
  jal   getPlayerCount
   swc1  $f10, 0x58($sp)
  li    $at, 1
  bne   $v0, $at, .L7F03D3BC
   lwc1  $f4, 0x58($sp)
  lui    $at, %hi(difficulty)
  lwc1  $f18, %lo(difficulty)($at)
  mul.s $f16, $f4, $f18
  swc1  $f16, 0x58($sp)
.L7F03D3BC:
  jal   getPlayer_c_screenwidth
   nop   
  jal   getPlayer_c_screenleft
   swc1  $f0, 0x38($sp)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f6
  lwc1  $f8, 0x38($sp)
  lwc1  $f18, 0x8c($sp)
  lwc1  $f16, 0x94($sp)
  mul.s $f10, $f6, $f8
  mtc1  $at, $f8
  add.s $f6, $f18, $f16
  lwc1  $f18, 0x58($sp)
  move  $v0, $zero
  add.s $f4, $f0, $f10
  mul.s $f10, $f6, $f8
  sub.s $f16, $f10, $f18
  c.le.s $f16, $f4
  nop   
  bc1f  .L7F03D414
   nop   
  li    $v0, 1
.L7F03D414:
  beqz  $v0, .L7F03D4BC
   nop   
  jal   getPlayer_c_screenwidth
   nop   
  jal   getPlayer_c_screenleft
   swc1  $f0, 0x30($sp)
  lwc1  $f6, 0x8c($sp)
  lwc1  $f8, 0x94($sp)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f12
  add.s $f10, $f6, $f8
  lwc1  $f6, 0x30($sp)
  lwc1  $f4, 0x58($sp)
  move  $v0, $zero
  mul.s $f18, $f10, $f12
  nop   
  mul.s $f8, $f12, $f6
  add.s $f16, $f18, $f4
  lwc1  $f18, 0x68($sp)
  add.s $f10, $f0, $f8
  c.le.s $f10, $f16
  nop   
  bc1f  .L7F03D478
   nop   
  li    $v0, 1
.L7F03D478:
  beqz  $v0, .L7F03D4BC
   nop   
  lwc1  $f2, 0xa8($sp)
  move  $v0, $zero
  lwc1  $f4, 0x64($sp)
  c.le.s $f18, $f2
  nop   
  bc1f  .L7F03D4A0
   nop   
  li    $v0, 1
.L7F03D4A0:
  beqz  $v0, .L7F03D4BC
   nop   
  c.le.s $f2, $f4
  move  $v0, $zero
  bc1f  .L7F03D4BC
   nop   
  li    $v0, 1
.L7F03D4BC:
  b     .L7F03D504
   sw    $v0, 0x5c($sp)
.L7F03D4C4:
  lwc1  $f6, 0x94($sp)
  move  $v0, $zero
  lwc1  $f8, 0x8c($sp)
  c.le.s $f6, $f0
  nop   
  bc1f  .L7F03D4E4
   nop   
  li    $v0, 1
.L7F03D4E4:
  beql  $v0, $zero, .L7F03D504
   sw    $v0, 0x5c($sp)
  c.le.s $f0, $f8
  move  $v0, $zero
  bc1fl .L7F03D504
   sw    $v0, 0x5c($sp)
  li    $v0, 1
  sw    $v0, 0x5c($sp)
.L7F03D504:
  lw    $t1, 0x5c($sp)
.L7F03D508:
  beql  $t1, $zero, .L7F03D77C
   lw    $ra, 0x2c($sp)
  jal   get_curplayer_positiondata
   nop   
  sw    $v0, 0x54($sp)
  lw    $t2, 0x14($v0)
  lui   $a0, %hi(pPlayer)
  lw    $a0, %lo(pPlayer)($a0)
  jal   sub_GAME_7F089780
   sw    $t2, 0x50($sp)
  lw    $a0, 0x54($sp)
  move  $a1, $zero
  jal   sub_GAME_7F08A03C
   swc1  $f0, 0x4c($sp)
  lw    $v0, 0x54($sp)
  lw    $v1, 0xb0($sp)
  lwc1  $f2, 0x4c($sp)
  lw    $a1, 8($v0)
  lwc1  $f16, 0x10($v1)
  lw    $a2, 0x10($v0)
  lw    $a3, 8($v1)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f18
  mtc1  $zero, $f10
  li    $t3, 19
  sw    $t3, 0x14($sp)
  addiu $a0, $sp, 0x50
  swc1  $f2, 0x1c($sp)
  swc1  $f2, 0x18($sp)
  swc1  $f16, 0x10($sp)
  swc1  $f18, 0x24($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f10, 0x20($sp)
  beqz  $v0, .L7F03D76C
   lw    $t5, 0xb0($sp)
  lw    $t4, 0x50($sp)
  lw    $t6, 0x14($t5)
  lwc1  $f2, 0xac($sp)
  lwc1  $f4, 0x70($sp)
  bne   $t4, $t6, .L7F03D76C
   lw    $t7, 0xc0($sp)
  c.lt.s $f2, $f4
  mov.s $f0, $f2
  lwc1  $f6, 0x6c($sp)
  bc1fl .L7F03D5CC
   c.lt.s $f6, $f2
  b     .L7F03D5DC
   mov.s $f0, $f4
  c.lt.s $f6, $f2
.L7F03D5CC:
  nop   
  bc1f  .L7F03D5DC
   nop   
  mov.s $f0, $f6
.L7F03D5DC:
  jal   redirect_get_BONDdata_autoaim_x
   swc1  $f0, 4($t7)
  beqz  $v0, .L7F03D628
   lwc1  $f2, 0xa8($sp)
  lwc1  $f8, 0x68($sp)
  mov.s $f0, $f2
  lwc1  $f16, 0x64($sp)
  c.lt.s $f2, $f8
  lw    $t8, 0xc0($sp)
  bc1fl .L7F03D614
   c.lt.s $f16, $f2
  b     .L7F03D624
   mov.s $f0, $f8
  c.lt.s $f16, $f2
.L7F03D614:
  nop   
  bc1fl .L7F03D628
   swc1  $f0, ($t8)
  mov.s $f0, $f16
.L7F03D624:
  swc1  $f0, ($t8)
.L7F03D628:
  jal   getPlayer_c_screenwidth
   nop   
  jal   getPlayer_c_screenleft
   swc1  $f0, 0x38($sp)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f10
  lwc1  $f18, 0x38($sp)
  lwc1  $f8, 0x94($sp)
  mul.s $f4, $f10, $f18
  add.s $f6, $f0, $f4
  c.le.s $f8, $f6
  nop   
  bc1f  .L7F03D6A8
   nop   
  jal   getPlayer_c_screenwidth
   nop   
  jal   getPlayer_c_screenleft
   swc1  $f0, 0x30($sp)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f10
  lwc1  $f18, 0x30($sp)
  lwc1  $f16, 0x8c($sp)
  li    $at, 0x3F800000 # 1.000000
  mul.s $f4, $f10, $f18
  add.s $f6, $f0, $f4
  c.le.s $f6, $f16
  nop   
  bc1f  .L7F03D6A8
   nop   
  mtc1  $at, $f8
  b     .L7F03D76C
   swc1  $f8, 0x60($sp)
.L7F03D6A8:
  jal   getPlayer_c_screenwidth
   nop   
  jal   getPlayer_c_screenleft
   swc1  $f0, 0x38($sp)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f10
  lwc1  $f18, 0x38($sp)
  lwc1  $f6, 0x94($sp)
  mul.s $f4, $f10, $f18
  add.s $f16, $f0, $f4
  c.le.s $f6, $f16
  nop   
  bc1f  .L7F03D728
   nop   
  jal   getPlayer_c_screenwidth
   nop   
  jal   getPlayer_c_screenleft
   swc1  $f0, 0x38($sp)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f8
  lwc1  $f10, 0x38($sp)
  lwc1  $f16, 0x8c($sp)
  li    $at, 0x3F800000 # 1.000000
  mul.s $f18, $f8, $f10
  lwc1  $f8, 0x58($sp)
  add.s $f4, $f0, $f18
  mtc1  $at, $f18
  sub.s $f6, $f4, $f16
  div.s $f10, $f6, $f8
  sub.s $f4, $f18, $f10
  b     .L7F03D76C
   swc1  $f4, 0x60($sp)
.L7F03D728:
  jal   getPlayer_c_screenleft
   nop   
  jal   getPlayer_c_screenwidth
   swc1  $f0, 0x40($sp)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f16
  lwc1  $f8, 0x40($sp)
  lwc1  $f10, 0x94($sp)
  mul.s $f6, $f0, $f16
  lwc1  $f16, 0x58($sp)
  li    $at, 0x3F800000 # 1.000000
  add.s $f18, $f6, $f8
  mtc1  $at, $f8
  sub.s $f4, $f10, $f18
  div.s $f6, $f4, $f16
  sub.s $f10, $f8, $f6
  swc1  $f10, 0x60($sp)
.L7F03D76C:
  lw    $a0, 0x54($sp)
  jal   sub_GAME_7F08A03C
   li    $a1, 1
  lw    $ra, 0x2c($sp)
.L7F03D77C:
  lwc1  $f0, 0x60($sp)
  addiu $sp, $sp, 0xb0
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F03D78C
  addiu $sp, $sp, -0xa8
  lui   $t7, %hi(D_80030AB0) 
  sw    $ra, 0x4c($sp)
  sw    $s6, 0x48($sp)
  sw    $s5, 0x44($sp)
  sw    $s4, 0x40($sp)
  sw    $s3, 0x3c($sp)
  sw    $s2, 0x38($sp)
  sw    $s1, 0x34($sp)
  sw    $s0, 0x30($sp)
  sdc1  $f22, 0x28($sp)
  sdc1  $f20, 0x20($sp)
  addiu $t7, %lo(D_80030AB0) # addiu $t7, $t7, 0xab0
  lw    $at, ($t7)
  lw    $t0, 4($t7)
  addiu $t6, $sp, 0x9c
  move  $s6, $zero
  sw    $at, ($t6)
  jal   redirect_get_BONDdata_autoaim_y
   sw    $t0, 4($t6)
  beqz  $v0, .L7F03D8FC
   li    $at, 0xBF800000 # -1.000000
  lui   $s2, %hi(dword_CODE_bss_80071DF0)
  lw    $s2, %lo(dword_CODE_bss_80071DF0)($s2)
  lui   $t1, %hi(dword_CODE_bss_80071620) 
  mtc1  $at, $f20
  addiu $t1, %lo(dword_CODE_bss_80071620) # addiu $t1, $t1, 0x1620
  addiu $s2, $s2, -4
  sltu  $at, $s2, $t1
  bnez  $at, .L7F03D8FC
   addiu $s5, $sp, 0x78
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f22
  addiu $s4, $sp, 0x80
  addiu $s3, $sp, 0x88
  lw    $s0, ($s2)
.L7F03D81C:
  beqz  $s0, .L7F03D8E4
   nop   
  lbu   $v0, ($s0)
  li    $at, 3
  beq   $v0, $at, .L7F03D860
   li    $at, 6
  bne   $v0, $at, .L7F03D8E4
   nop   
  lw    $t2, 4($s0)
  beqz  $t2, .L7F03D8E4
   nop   
  jal   sub_GAME_7F09B15C
   move  $a0, $s0
  jal   get_cur_playernum
   move  $s1, $v0
  beq   $v0, $s1, .L7F03D8E4
   nop   
.L7F03D860:
  lw    $s1, 4($s0)
  move  $a1, $zero
  jal   something_with_weaponpos_of_guarddata_hand
   move  $a0, $s1
  bnez  $v0, .L7F03D884
   move  $a0, $s1
  jal   something_with_weaponpos_of_guarddata_hand
   li    $a1, 1
  beqz  $v0, .L7F03D8E4
.L7F03D884:
   move  $a0, $s0
  move  $a1, $s3
  move  $a2, $s4
  jal   sub_GAME_7F023194
   move  $a3, $s5
  beqz  $v0, .L7F03D8E4
   move  $a0, $s0
  addiu $t3, $sp, 0x6c
  sw    $t3, 0x10($sp)
  move  $a1, $s3
  move  $a2, $s4
  jal   sub_GAME_7F03D188
   move  $a3, $s5
  c.lt.s $f20, $f0
  lwc1  $f4, 0x6c($sp)
  bc1f  .L7F03D8E4
   nop   
  c.le.s $f22, $f0
  lwc1  $f6, 0x70($sp)
  mov.s $f20, $f0
  move  $s6, $s0
  swc1  $f4, 0x9c($sp)
  bc1t  .L7F03D8FC
   swc1  $f6, 0xa0($sp)
.L7F03D8E4:
  lui   $t4, %hi(dword_CODE_bss_80071620) 
  addiu $t4, %lo(dword_CODE_bss_80071620) # addiu $t4, $t4, 0x1620
  addiu $s2, $s2, -4
  sltu  $at, $s2, $t4
  beql  $at, $zero, .L7F03D81C
   lw    $s0, ($s2)
.L7F03D8FC:
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f22
  beql  $s6, $zero, .L7F03D9A0
   mtc1  $zero, $f20
  jal   getPlayer_c_screentop
   nop   
  jal   getPlayer_c_screenheight
   mov.s $f20, $f0
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f16
  lwc1  $f8, 0xa0($sp)
  move  $a0, $s6
  mul.s $f18, $f0, $f16
  sub.s $f10, $f8, $f20
  div.s $f4, $f10, $f18
  sub.s $f6, $f4, $f22
  mfc1  $a1, $f6
  jal   sub_GAME_7F07C5F0
   nop   
  jal   redirect_get_BONDdata_autoaim_x
   nop   
  beql  $v0, $zero, .L7F03D9C0
   lw    $ra, 0x4c($sp)
  jal   getPlayer_c_screenleft
   nop   
  jal   getPlayer_c_screenwidth
   mov.s $f20, $f0
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f10
  lwc1  $f8, 0x9c($sp)
  move  $a0, $s6
  mul.s $f18, $f0, $f10
  sub.s $f16, $f8, $f20
  div.s $f4, $f16, $f18
  sub.s $f6, $f4, $f22
  mfc1  $a1, $f6
  jal   sub_GAME_7F07C6C8
   nop   
  b     .L7F03D9C0
   lw    $ra, 0x4c($sp)
  mtc1  $zero, $f20
.L7F03D9A0:
  move  $a0, $zero
  mfc1  $a1, $f20
  jal   sub_GAME_7F07C5F0
   nop   
  mfc1  $a1, $f20
  jal   sub_GAME_7F07C6C8
   move  $a0, $zero
  lw    $ra, 0x4c($sp)
.L7F03D9C0:
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
   addiu $sp, $sp, 0xa8
");

asm(R"
glabel sub_GAME_7F03D9EC
  lw    $v0, 4($a0)
  mtc1  $zero, $f4
  lwc1  $f0, 0xb4($v0)
  c.le.s $f0, $f4
  nop   
  bc1fl .L7F03DA14
   lwc1  $f6, 0x84($v0)
  b     .L7F03DA30
   li    $v1, 4096
  lwc1  $f6, 0x84($v0)
.L7F03DA14:
  li    $v1, 16384
  c.le.s $f6, $f0
  nop   
  bc1f  .L7F03DA30
   nop   
  b     .L7F03DA30
   li    $v1, 8192
.L7F03DA30:
  lw    $t6, 0xc($v0)
  ori   $t8, $v1, 0x8000
  sll   $t7, $t6, 2
  bgez  $t7, .L7F03DA48
   nop   
  move  $v1, $t8
.L7F03DA48:
  jr    $ra
   move  $v0, $v1
");

asm(R"
glabel sub_GAME_7F03DA50
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  lbu   $v0, ($a0)
  li    $at, 2
  li    $a2, 1
  bne   $v0, $at, .L7F03DABC
   andi  $t6, $a1, 0x100
  beqz  $t6, .L7F03DA8C
   andi  $t9, $a1, 2
  lw    $v0, 4($a0)
  lw    $t7, 8($v0)
  sll   $t8, $t7, 5
  bgez  $t8, .L7F03DA8C
   nop   
  move  $a2, $zero
.L7F03DA8C:
  bnezl $t9, .L7F03DB60
   lw    $ra, 0x14($sp)
  sw    $a1, 0x24($sp)
  jal   sub_GAME_7F03D9EC
   sw    $a2, 0x1c($sp)
  lw    $a1, 0x24($sp)
  lw    $a2, 0x1c($sp)
  and   $t0, $v0, $a1
  bnezl $t0, .L7F03DB60
   lw    $ra, 0x14($sp)
  b     .L7F03DB5C
   move  $a2, $zero
.L7F03DABC:
  li    $at, 6
  bne   $v0, $at, .L7F03DAD8
   andi  $t1, $a1, 4
  bnezl $t1, .L7F03DB60
   lw    $ra, 0x14($sp)
  b     .L7F03DB5C
   move  $a2, $zero
.L7F03DAD8:
  li    $at, 3
  bne   $v0, $at, .L7F03DAF8
   andi  $t3, $a1, 0x100
  andi  $t2, $a1, 8
  bnezl $t2, .L7F03DB60
   lw    $ra, 0x14($sp)
  b     .L7F03DB5C
   move  $a2, $zero
.L7F03DAF8:
  beqz  $t3, .L7F03DB14
   lw    $v0, 4($a0)
  lw    $t4, 8($v0)
  sll   $t5, $t4, 5
  bgezl $t5, .L7F03DB18
   andi  $t6, $a1, 0x200
  move  $a2, $zero
.L7F03DB14:
  andi  $t6, $a1, 0x200
.L7F03DB18:
  beqz  $t6, .L7F03DB30
   lw    $v1, 8($v0)
  sll   $t7, $v1, 0xe
  bltzl $t7, .L7F03DB34
   andi  $t8, $v1, 0x800
  move  $a2, $zero
.L7F03DB30:
  andi  $t8, $v1, 0x800
.L7F03DB34:
  beqz  $t8, .L7F03DB50
   andi  $t0, $a1, 1
  andi  $t9, $a1, 0x10
  bnezl $t9, .L7F03DB60
   lw    $ra, 0x14($sp)
  b     .L7F03DB5C
   move  $a2, $zero
.L7F03DB50:
  bnezl $t0, .L7F03DB60
   lw    $ra, 0x14($sp)
  move  $a2, $zero
.L7F03DB5C:
  lw    $ra, 0x14($sp)
.L7F03DB60:
  addiu $sp, $sp, 0x20
  move  $v0, $a2
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F03DB70
  lw    $v1, ($a0)
  move  $v0, $a0
  bltzl $v1, .L7F03DBC4
   move  $v0, $zero
  lw    $a3, ($a1)
  move  $a0, $a1
.L7F03DB88:
  bltz  $a3, .L7F03DBB0
   move  $a2, $a3
.L7F03DB90:
  bnel  $v1, $a2, .L7F03DBA4
   lw    $a2, 4($a0)
  jr    $ra
   li    $v0, 1

  lw    $a2, 4($a0)
.L7F03DBA4:
  addiu $a0, $a0, 4
  bgez  $a2, .L7F03DB90
   nop   
.L7F03DBB0:
  lw    $v1, 4($v0)
  addiu $v0, $v0, 4
  bgezl $v1, .L7F03DB88
   move  $a0, $a1
  move  $v0, $zero
.L7F03DBC4:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F03DBCC
  lui   $t7, %hi(dword_CODE_bss_8007161C) 
  lw    $t7, %lo(dword_CODE_bss_8007161C)($t7)
  sll   $t8, $a1, 5
  sw    $a0, ($sp)
  addu  $v1, $t7, $t8
  lh    $t9, ($v1)
  sll   $a2, $a0, 0x10
  sra   $t6, $a2, 0x10
  move  $a2, $t6
  bgez  $t9, .L7F03DC04
   move  $a0, $v1
  sh    $t6, ($a0)
  jr    $ra
   li    $v0, 1

.L7F03DC04:
  lh    $t0, 2($a0)
  li    $v0, 1
  bgezl $t0, .L7F03DC20
   lh    $t1, 4($a0)
  jr    $ra
   sh    $a2, 2($a0)

  lh    $t1, 4($a0)
.L7F03DC20:
  addiu $a1, $v1, 6
  li    $v0, 30
  bgezl $t1, .L7F03DC40
   li    $a0, 6
  sh    $a2, 4($a0)
  jr    $ra
   li    $v0, 1

  li    $a0, 6
.L7F03DC40:
  lh    $t2, ($a1)
  addiu $a0, $a0, 8
  bgezl $t2, .L7F03DC60
   lh    $t3, 2($a1)
  sh    $a2, ($a1)
  jr    $ra
   li    $v0, 1

  lh    $t3, 2($a1)
.L7F03DC60:
  bgezl $t3, .L7F03DC78
   lh    $t4, 4($a1)
  sh    $a2, 2($a1)
  jr    $ra
   li    $v0, 1

  lh    $t4, 4($a1)
.L7F03DC78:
  bgezl $t4, .L7F03DC90
   lh    $t5, 6($a1)
  sh    $a2, 4($a1)
  jr    $ra
   li    $v0, 1

  lh    $t5, 6($a1)
.L7F03DC90:
  bgez  $t5, .L7F03DCA4
   nop   
  sh    $a2, 6($a1)
  jr    $ra
   li    $v0, 1

.L7F03DCA4:
  bne   $a0, $v0, .L7F03DC40
   addiu $a1, $a1, 8
  move  $v0, $zero
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F03DCB8
  move  $a2, $a0
  lui   $v0, %hi(dword_CODE_bss_8007161C)
  lw    $v0, %lo(dword_CODE_bss_8007161C)($v0)
  li    $a0, -2
  move  $v1, $zero
  li    $a3, 256
.L7F03DCD0:
  lh    $t6, ($v0)
  bnel  $a0, $t6, .L7F03DD88
   addiu $v1, $v1, 1
  lui   $v0, %hi(dword_CODE_bss_8007161C)
  addiu $v0, %lo(dword_CODE_bss_8007161C) # addiu $v0, $v0, 0x161c
  move  $a0, $zero
  li    $t0, 32
  li    $a3, -1
.L7F03DCF0:
  lw    $t7, ($v0)
  sll   $t8, $v1, 5
  sll   $t3, $v1, 5
  addu  $t9, $t7, $t8
  addu  $t1, $t9, $a0
  sh    $a3, ($t1)
  lw    $t2, ($v0)
  sll   $t7, $v1, 5
  addu  $t4, $t2, $t3
  addu  $t5, $t4, $a0
  sh    $a3, 2($t5)
  lw    $t6, ($v0)
  sll   $t2, $v1, 5
  addu  $t8, $t6, $t7
  addu  $t9, $t8, $a0
  sh    $a3, 4($t9)
  lw    $t1, ($v0)
  addu  $t3, $t1, $t2
  addu  $t4, $t3, $a0
  addiu $a0, $a0, 8
  bne   $a0, $t0, .L7F03DCF0
   sh    $a3, 6($t4)
  bltz  $a1, .L7F03DD68
   nop   
  lw    $t5, ($v0)
  sll   $t6, $a1, 5
  move  $v0, $v1
  addu  $t7, $t5, $t6
  jr    $ra
   sh    $v1, 0x1e($t7)

.L7F03DD68:
  lui   $t8, %hi(ptr_room_lookup_buffer_maybe) 
  lw    $t8, %lo(ptr_room_lookup_buffer_maybe)($t8)
  sll   $t9, $a2, 1
  addu  $t1, $t8, $t9
  sh    $v1, ($t1)
  jr    $ra
   move  $v0, $v1

  addiu $v1, $v1, 1
.L7F03DD88:
  bne   $v1, $a3, .L7F03DCD0
   addiu $v0, $v0, 0x20
  li    $v0, -1
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F03DD9C
  addiu $sp, $sp, -0x28
  sw    $a1, 0x2c($sp)
  lh    $t6, 0x2e($sp)
  sw    $ra, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a0, 0x28($sp)
  bltz  $t6, .L7F03DE7C
   li    $a2, -1
  lh    $t8, 0x2e($sp)
  lui   $t7, %hi(ptr_room_lookup_buffer_maybe) 
  lw    $t7, %lo(ptr_room_lookup_buffer_maybe)($t7)
  sll   $t9, $t8, 1
  lui   $t2, %hi(pos_data_entry) 
  addu  $t0, $t7, $t9
  lh    $s0, ($t0)
  addiu $t2, %lo(pos_data_entry) # addiu $t2, $t2, -0x63c8
  subu  $s1, $a0, $t2
  bltz  $s0, .L7F03DE40
   li    $at, 52
  div   $zero, $s1, $at
  mflo  $t3
  sll   $t4, $t3, 0x10
  lui   $s2, %hi(dword_CODE_bss_8007161C)
  addiu $s2, %lo(dword_CODE_bss_8007161C) # addiu $s2, $s2, 0x161c
  sra   $s1, $t4, 0x10
  sll   $a0, $s1, 0x10
.L7F03DE0C:
  sra   $t6, $a0, 0x10
  move  $a0, $t6
  jal   sub_GAME_7F03DBCC
   move  $a1, $s0
  bnezl $v0, .L7F03DE80
   lw    $ra, 0x24($sp)
  lw    $t8, ($s2)
  sll   $t7, $s0, 5
  move  $a2, $s0
  addu  $t9, $t8, $t7
  lh    $s0, 0x1e($t9)
  bgezl $s0, .L7F03DE0C
   sll   $a0, $s1, 0x10
.L7F03DE40:
  lh    $a0, 0x2e($sp)
  jal   sub_GAME_7F03DCB8
   move  $a1, $a2
  bltz  $v0, .L7F03DE7C
   lw    $t0, 0x28($sp)
  lui   $t1, %hi(pos_data_entry) 
  addiu $t1, %lo(pos_data_entry) # addiu $t1, $t1, -0x63c8
  subu  $a0, $t0, $t1
  li    $at, 52
  div   $zero, $a0, $at
  mflo  $t2
  sll   $t3, $t2, 0x10
  sra   $a0, $t3, 0x10
  jal   sub_GAME_7F03DBCC
   move  $a1, $v0
.L7F03DE7C:
  lw    $ra, 0x24($sp)
.L7F03DE80:
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
glabel sub_GAME_7F03DE94
  addiu $sp, $sp, -0x10
  sll   $t6, $a1, 0x10
  sra   $t7, $t6, 0x10
  sw    $s1, 0xc($sp)
  sw    $s0, 8($sp)
  sw    $a1, 0x14($sp)
  move  $a2, $zero
  bltz  $t7, .L7F03E124
   li    $t1, -1
  lui   $t3, %hi(ptr_room_lookup_buffer_maybe) 
  addiu $t3, %lo(ptr_room_lookup_buffer_maybe) # addiu $t3, $t3, 0x1618
  lw    $t8, ($t3)
  sll   $t2, $t7, 1
  lui   $t6, %hi(pos_data_entry) 
  addu  $t9, $t8, $t2
  lh    $v1, ($t9)
  addiu $t6, %lo(pos_data_entry) # addiu $t6, $t6, -0x63c8
  subu  $a0, $a0, $t6
  bltz  $v1, .L7F03E124
   lui   $t5, %hi(dword_CODE_bss_8007161C) 
  li    $at, 52
  div   $zero, $a0, $at
  mflo  $t7
  sll   $t8, $t7, 0x10
  lui   $a3, %hi(dword_CODE_bss_8007161C)
  addiu $a3, %lo(dword_CODE_bss_8007161C) # addiu $a3, $a3, 0x161c
  sra   $a0, $t8, 0x10
  lw    $t5, %lo(dword_CODE_bss_8007161C)($t5)
  li    $t4, -2
  li    $t0, 30
  li    $a1, -1
  sll   $t6, $v1, 5
.L7F03DF14:
  addu  $s0, $t5, $t6
  lh    $s1, ($s0)
  move  $v0, $zero
  sll   $t6, $v1, 5
  bne   $a0, $s1, .L7F03DF40
   sll   $t8, $v1, 5
  sh    $a1, ($s0)
  lw    $t7, ($a3)
  li    $a2, 1
  b     .L7F03DF4C
   addu  $s0, $t7, $t8
.L7F03DF40:
  bltzl $s1, .L7F03DF50
   lh    $t5, 2($s0)
  li    $v0, 1
.L7F03DF4C:
  lh    $t5, 2($s0)
.L7F03DF50:
  bne   $a0, $t5, .L7F03DF6C
   nop   
  sh    $a1, 2($s0)
  lw    $t9, ($a3)
  li    $a2, 1
  b     .L7F03DF80
   addu  $s0, $t9, $t6
.L7F03DF6C:
  bnezl $v0, .L7F03DF84
   lh    $t5, 4($s0)
  bltzl $t5, .L7F03DF84
   lh    $t5, 4($s0)
  li    $v0, 1
.L7F03DF80:
  lh    $t5, 4($s0)
.L7F03DF84:
  bne   $a0, $t5, .L7F03DF98
   nop   
  sh    $a1, 4($s0)
  b     .L7F03DFAC
   li    $a2, 1
.L7F03DF98:
  bnezl $v0, .L7F03DFB0
   li    $s0, 6
  bltzl $t5, .L7F03DFB0
   li    $s0, 6
  li    $v0, 1
.L7F03DFAC:
  li    $s0, 6
.L7F03DFB0:
  lw    $t7, ($a3)
.L7F03DFB4:
  sll   $t8, $v1, 5
  addu  $t9, $t7, $t8
  addu  $t5, $t9, $s0
  lh    $s1, ($t5)
  bne   $a0, $s1, .L7F03DFE8
   nop   
  sh    $a1, ($t5)
  lw    $t6, ($a3)
  sll   $t7, $v1, 5
  li    $a2, 1
  addu  $t8, $t6, $t7
  b     .L7F03DFFC
   addu  $t5, $t8, $s0
.L7F03DFE8:
  bnezl $v0, .L7F03E000
   lh    $s1, 2($t5)
  bltzl $s1, .L7F03E000
   lh    $s1, 2($t5)
  li    $v0, 1
.L7F03DFFC:
  lh    $s1, 2($t5)
.L7F03E000:
  bne   $a0, $s1, .L7F03E024
   nop   
  sh    $a1, 2($t5)
  lw    $t9, ($a3)
  sll   $t6, $v1, 5
  li    $a2, 1
  addu  $t7, $t9, $t6
  b     .L7F03E038
   addu  $t5, $t7, $s0
.L7F03E024:
  bnezl $v0, .L7F03E03C
   lh    $s1, 4($t5)
  bltzl $s1, .L7F03E03C
   lh    $s1, 4($t5)
  li    $v0, 1
.L7F03E038:
  lh    $s1, 4($t5)
.L7F03E03C:
  bne   $a0, $s1, .L7F03E060
   nop   
  sh    $a1, 4($t5)
  lw    $t8, ($a3)
  sll   $t9, $v1, 5
  li    $a2, 1
  addu  $t6, $t8, $t9
  b     .L7F03E074
   addu  $t5, $t6, $s0
.L7F03E060:
  bnezl $v0, .L7F03E078
   lh    $s1, 6($t5)
  bltzl $s1, .L7F03E078
   lh    $s1, 6($t5)
  li    $v0, 1
.L7F03E074:
  lh    $s1, 6($t5)
.L7F03E078:
  addiu $s0, $s0, 8
  bne   $a0, $s1, .L7F03E090
   nop   
  sh    $a1, 6($t5)
  b     .L7F03E0A4
   li    $a2, 1
.L7F03E090:
  bnez  $v0, .L7F03E0A4
   nop   
  bltz  $s1, .L7F03E0A4
   nop   
  li    $v0, 1
.L7F03E0A4:
  bnel  $s0, $t0, .L7F03DFB4
   lw    $t7, ($a3)
  bnezl $v0, .L7F03E104
   move  $t1, $v1
  lw    $t7, ($a3)
  sll   $v0, $v1, 5
  addu  $t8, $t7, $v0
  bltz  $t1, .L7F03E0E4
   sh    $t4, ($t8)
  lw    $t5, ($a3)
  sll   $t7, $t1, 5
  addu  $t9, $t5, $v0
  lh    $t6, 0x1e($t9)
  addu  $t8, $t5, $t7
  b     .L7F03E104
   sh    $t6, 0x1e($t8)
.L7F03E0E4:
  lw    $t9, ($a3)
  lw    $t8, ($t3)
  addu  $t7, $t9, $v0
  lh    $t6, 0x1e($t7)
  addu  $t9, $t8, $t2
  b     .L7F03E104
   sh    $t6, ($t9)
  move  $t1, $v1
.L7F03E104:
  bnezl $a2, .L7F03E128
   lw    $s0, 8($sp)
  lw    $t5, ($a3)
  sll   $t7, $v1, 5
  addu  $t8, $t5, $t7
  lh    $v1, 0x1e($t8)
  bgezl $v1, .L7F03DF14
   sll   $t6, $v1, 5
.L7F03E124:
  lw    $s0, 8($sp)
.L7F03E128:
  lw    $s1, 0xc($sp)
  jr    $ra
   addiu $sp, $sp, 0x10
");

asm(R"
glabel sub_GAME_7F03E134
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lbu   $v0, ($a0)
  li    $at, 3
  move  $a1, $a0
  bnel  $v0, $at, .L7F03E164
   li    $at, 1
  jal   sub_GAME_7F020D94
   lw    $a0, 4($a0)
  b     .L7F03E180
   lw    $ra, 0x14($sp)
  li    $at, 1
.L7F03E164:
  beq   $v0, $at, .L7F03E174
   li    $at, 4
  bnel  $v0, $at, .L7F03E180
   lw    $ra, 0x14($sp)
.L7F03E174:
  jal   sub_GAME_7F056CA0
   lw    $a0, 4($a1)
  lw    $ra, 0x14($sp)
.L7F03E180:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F03E18C
  addiu $sp, $sp, -0x28
  sw    $ra, 0x24($sp)
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  lbu   $s0, 0x2c($a0)
  li    $s2, 255
  move  $s3, $a0
  beq   $s2, $s0, .L7F03E1DC
   addiu $s1, $a0, 0x2c
  sll   $a1, $s0, 0x10
.L7F03E1BC:
  sra   $t6, $a1, 0x10
  move  $a1, $t6
  jal   sub_GAME_7F03DE94
   move  $a0, $s3
  lbu   $s0, 1($s1)
  addiu $s1, $s1, 1
  bnel  $s2, $s0, .L7F03E1BC
   sll   $a1, $s0, 0x10
.L7F03E1DC:
  lbu   $t7, 1($s3)
  li    $t9, 255
  andi  $t8, $t7, 0x10
  bnezl $t8, .L7F03E1F8
   lw    $ra, 0x24($sp)
  sb    $t9, 0x2c($s3)
  lw    $ra, 0x24($sp)
.L7F03E1F8:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
glabel sub_GAME_7F03E210
  addiu $sp, $sp, -0x28
  sw    $ra, 0x24($sp)
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  lbu   $s0, 0x2c($a0)
  li    $s3, 255
  move  $s2, $a0
  beq   $s3, $s0, .L7F03E260
   addiu $s1, $a0, 0x2c
  sll   $a1, $s0, 0x10
.L7F03E240:
  sra   $t6, $a1, 0x10
  move  $a1, $t6
  jal   sub_GAME_7F03DD9C
   move  $a0, $s2
  lbu   $s0, 1($s1)
  addiu $s1, $s1, 1
  bnel  $s3, $s0, .L7F03E240
   sll   $a1, $s0, 0x10
.L7F03E260:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
glabel sub_GAME_7F03E27C
  addiu $sp, $sp, -0x70
  sw    $ra, 0x2c($sp)
  sw    $s0, 0x28($sp)
  sw    $a1, 0x74($sp)
  sw    $a2, 0x78($sp)
  sw    $zero, 0x48($sp)
  lbu   $t6, 1($a0)
  mtc1  $a3, $f12
  move  $s0, $a0
  andi  $t7, $t6, 8
  beqz  $t7, .L7F03E348
   move  $v1, $zero
  lbu   $v0, ($a0)
  li    $at, 1
  addiu $a2, $s0, 0x2c
  beq   $v0, $at, .L7F03E2D0
   li    $at, 4
  beq   $v0, $at, .L7F03E2D0
   li    $at, 2
  bne   $v0, $at, .L7F03E2D4
   nop   
.L7F03E2D0:
  lw    $v1, 4($s0)
.L7F03E2D4:
  beqz  $v1, .L7F03E308
   nop   
  lw    $t8, 0x64($v1)
  andi  $t9, $t8, 0x80
  beqz  $t9, .L7F03E308
   nop   
  lw    $v0, 0x6c($v1)
  lw    $t1, ($v0)
  andi  $t2, $t1, 8
  beqz  $t2, .L7F03E308
   nop   
  b     .L7F03E308
   addiu $a2, $v0, 0xcc
.L7F03E308:
  lbu   $t3, ($a2)
  li    $a1, 255
  move  $t0, $zero
  beq   $a1, $t3, .L7F03E33C
   addiu $v0, $sp, 0x50
  move  $v1, $a2
  lbu   $a0, ($a2)
.L7F03E324:
  sw    $a0, ($v0)
  lbu   $a0, 1($v1)
  addiu $t0, $t0, 1
  addiu $v0, $v0, 4
  bne   $a1, $a0, .L7F03E324
   addiu $v1, $v1, 1
.L7F03E33C:
  sw    $t0, 0x48($sp)
  b     .L7F03E384
   move  $t0, $zero
.L7F03E348:
  lw    $t4, 0x14($s0)
  sw    $zero, 0x48($sp)
  mfc1  $a3, $f12
  sw    $t4, 0x4c($sp)
  lw    $a2, 0x10($s0)
  lw    $a1, 8($s0)
  addiu $t5, $sp, 0x50
  addiu $t6, $sp, 0x48
  li    $t7, 7
  sw    $t7, 0x18($sp)
  sw    $t6, 0x14($sp)
  sw    $t5, 0x10($sp)
  jal   sub_GAME_7F0B21B0
   addiu $a0, $sp, 0x4c
  move  $t0, $zero
.L7F03E384:
  li    $t8, 7
  sw    $t8, 0x10($sp)
  lw    $a0, 0x74($sp)
  lw    $a1, 0x78($sp)
  addiu $a2, $sp, 0x50
  addiu $a3, $sp, 0x48
  jal   sub_GAME_7F0BA2D4
   sw    $t0, 0x44($sp)
  lw    $t9, 0x48($sp)
  lw    $t0, 0x44($sp)
  addiu $v0, $sp, 0x50
  blez  $t9, .L7F03E3E0
   li    $t3, 255
  move  $v1, $s0
  lw    $t1, ($v0)
.L7F03E3C0:
  addiu $t0, $t0, 1
  addiu $v0, $v0, 4
  sb    $t1, 0x2c($v1)
  lw    $t2, 0x48($sp)
  addiu $v1, $v1, 1
  slt   $at, $t0, $t2
  bnezl $at, .L7F03E3C0
   lw    $t1, ($v0)
.L7F03E3E0:
  addu  $t4, $s0, $t0
  sb    $t3, 0x2c($t4)
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x28($sp)
  addiu $sp, $sp, 0x70
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F03E3FC
  lw    $v1, ($a0)
  lui   $t1, %hi(ptr_list_object_lookup_indices) 
  addiu $t1, %lo(ptr_list_object_lookup_indices) # addiu $t1, $t1, -0x63d0
  bltz  $v1, .L7F03E4CC
   lw    $v0, ($t1)
  lui   $t2, %hi(ptr_room_lookup_buffer_maybe) 
  addiu $t2, %lo(ptr_room_lookup_buffer_maybe) # addiu $t2, $t2, 0x1618
  li    $t3, 30
  lw    $t6, ($t2)
.L7F03E420:
  sll   $t7, $v1, 1
  lui   $a2, %hi(dword_CODE_bss_8007161C)
  addu  $t8, $t6, $t7
  lh    $a1, ($t8)
  bltzl $a1, .L7F03E4C0
   lw    $v1, 4($a0)
  lw    $a2, %lo(dword_CODE_bss_8007161C)($a2)
  move  $a3, $zero
.L7F03E440:
  sll   $t9, $a1, 5
.L7F03E444:
  addu  $t4, $a2, $t9
  addu  $t5, $t4, $a3
  lh    $v1, ($t5)
  addiu $a3, $a3, 2
  bltz  $v1, .L7F03E4A0
   nop   
  lw    $t0, ($t1)
  sltu  $at, $t0, $v0
  beqz  $at, .L7F03E488
   nop   
  lh    $t6, ($t0)
.L7F03E470:
  beq   $v1, $t6, .L7F03E488
   nop   
  addiu $t0, $t0, 2
  sltu  $at, $t0, $v0
  bnezl $at, .L7F03E470
   lh    $t6, ($t0)
.L7F03E488:
  bne   $t0, $v0, .L7F03E4A0
   nop   
  sh    $v1, ($v0)
  lui   $a2, %hi(dword_CODE_bss_8007161C)
  lw    $a2, %lo(dword_CODE_bss_8007161C)($a2)
  addiu $v0, $v0, 2
.L7F03E4A0:
  bnel  $a3, $t3, .L7F03E444
   sll   $t9, $a1, 5
  sll   $t7, $a1, 5
  addu  $t8, $a2, $t7
  lh    $a1, 0x1e($t8)
  bgezl $a1, .L7F03E440
   move  $a3, $zero
  lw    $v1, 4($a0)
.L7F03E4C0:
  addiu $a0, $a0, 4
  bgezl $v1, .L7F03E420
   lw    $t6, ($t2)
.L7F03E4CC:
  li    $t9, -1
  sh    $t9, ($v0)
  lw    $t4, ($t1)
  addiu $v0, $v0, 2
  lui   $at, %hi(num_obj_position_data_entries)
  subu  $t5, $v0, $t4
  sra   $t6, $t5, 1
  jr    $ra
   sw    $t6, %lo(num_obj_position_data_entries)($at)
");

asm(R"
glabel sub_GAME_7F03E4F0
  lui   $v1, %hi(MaxNumRooms)
  lw    $v1, %lo(MaxNumRooms)($v1)
  addiu $sp, $sp, -0x18
  sw    $s3, 0x14($sp)
  sw    $s2, 0x10($sp)
  sw    $s1, 0xc($sp)
  sw    $s0, 8($sp)
  blez  $v1, .L7F03E680
   move  $v0, $zero
  lui   $t5, %hi(dword_CODE_bss_8007161C) 
  lui   $t4, %hi(ptr_room_lookup_buffer_maybe) 
  addiu $t4, %lo(ptr_room_lookup_buffer_maybe) # addiu $t4, $t4, 0x1618
  addiu $t5, %lo(dword_CODE_bss_8007161C) # addiu $t5, $t5, 0x161c
  move  $a1, $zero
  li    $s3, 30
  li    $s2, -2
  li    $s1, 30
  li    $s0, -1
.L7F03E538:
  lw    $t6, ($t4)
  addiu $v0, $v0, 1
  addu  $t7, $t6, $a1
  lh    $a0, ($t7)
  bltzl $a0, .L7F03E678
   slt   $at, $v0, $v1
  lw    $t8, ($t5)
  sll   $t9, $a0, 5
  addu  $t6, $t8, $t9
  lh    $a2, 0x1e($t6)
  bltz  $a2, .L7F03E674
   move  $t0, $zero
.L7F03E568:
  lw    $v1, ($t5)
.L7F03E56C:
  sll   $t7, $a0, 5
  sll   $t6, $a2, 5
  addu  $t8, $v1, $t7
  addu  $a3, $t8, $t0
  lh    $t9, ($a3)
  addiu $t0, $t0, 2
  move  $t2, $zero
  bgez  $t9, .L7F03E63C
   addu  $t3, $v1, $t6
.L7F03E590:
  lh    $v1, ($t3)
  bltzl $v1, .L7F03E5BC
   addiu $t2, $t2, 2
  sh    $v1, ($a3)
  lw    $t7, ($t5)
  sll   $t8, $a2, 5
  addu  $t9, $t7, $t8
  addu  $t6, $t9, $t2
  b     .L7F03E5C4
   sh    $s0, ($t6)
  addiu $t2, $t2, 2
.L7F03E5BC:
  bne   $t2, $s3, .L7F03E590
   addiu $t3, $t3, 2
.L7F03E5C4:
  slti  $at, $t2, 0x1e
  beqz  $at, .L7F03E5FC
   nop   
  lw    $t7, ($t5)
  sll   $t8, $a2, 5
  addu  $t9, $t7, $t8
  addu  $t3, $t9, $t2
.L7F03E5E0:
  lh    $t6, ($t3)
  bgez  $t6, .L7F03E5FC
   nop   
  addiu $t2, $t2, 2
  slti  $at, $t2, 0x1e
  bnez  $at, .L7F03E5E0
   addiu $t3, $t3, 2
.L7F03E5FC:
  bnel  $t2, $s1, .L7F03E640
   slti  $at, $t0, 0x1e
  lw    $t7, ($t5)
  sll   $t1, $a2, 5
  sll   $a3, $a0, 5
  addu  $t8, $t7, $t1
  sh    $s2, ($t8)
  lw    $v1, ($t5)
  addu  $t9, $v1, $t1
  lh    $t6, 0x1e($t9)
  addu  $t7, $v1, $a3
  sh    $t6, 0x1e($t7)
  lw    $t8, ($t5)
  addu  $t9, $t8, $a3
  lh    $a2, 0x1e($t9)
  bltz  $a2, .L7F03E648
.L7F03E63C:
   slti  $at, $t0, 0x1e
.L7F03E640:
  bnezl $at, .L7F03E56C
   lw    $v1, ($t5)
.L7F03E648:
  bltz  $a2, .L7F03E664
   nop   
  lw    $t6, ($t5)
  sll   $t7, $a2, 5
  move  $a0, $a2
  addu  $t8, $t6, $t7
  lh    $a2, 0x1e($t8)
.L7F03E664:
  bgezl $a2, .L7F03E568
   move  $t0, $zero
  lui   $v1, %hi(MaxNumRooms)
  lw    $v1, %lo(MaxNumRooms)($v1)
.L7F03E674:
  slt   $at, $v0, $v1
.L7F03E678:
  bnez  $at, .L7F03E538
   addiu $a1, $a1, 2
.L7F03E680:
  lw    $s0, 8($sp)
  lw    $s1, 0xc($sp)
  lw    $s2, 0x10($sp)
  lw    $s3, 0x14($sp)
  jr    $ra
   addiu $sp, $sp, 0x18
");

asm(R"
glabel removed_debug_roomblocks_feature
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F03E6A0
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  lw    $v0, 4($a0)
  move  $s1, $a0
  lui   $s0, %hi(D_80030B00)
  lw    $t6, 0x64($v0)
  andi  $t7, $t6, 1
  beql  $t7, $zero, .L7F03E708
   lw    $ra, 0x1c($sp)
  lw    $s0, %lo(D_80030B00)($s0)
  beql  $s0, $zero, .L7F03E708
   lw    $ra, 0x1c($sp)
  lw    $t8, 4($s0)
.L7F03E6DC:
  bnel  $s1, $t8, .L7F03E6FC
   lw    $s0, 0xc($s0)
  lw    $a0, 8($s0)
  beql  $a0, $zero, .L7F03E6FC
   lw    $s0, 0xc($s0)
  jal   sub_GAME_7F05599C
   nop   
  lw    $s0, 0xc($s0)
.L7F03E6FC:
  bnezl $s0, .L7F03E6DC
   lw    $t8, 4($s0)
  lw    $ra, 0x1c($sp)
.L7F03E708:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x20
");

asm(R"
glabel sub_GAME_7F03E718
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  lw    $t6, 0x64($a0)
  move  $s1, $a0
  lui   $s0, %hi(D_80030B04)
  andi  $t7, $t6, 0x2000
  beql  $t7, $zero, .L7F03E798
   li    $v0, 1
  lw    $s0, %lo(D_80030B04)($s0)
  beql  $s0, $zero, .L7F03E798
   li    $v0, 1
  lw    $t8, 4($s0)
.L7F03E750:
  bnel  $s1, $t8, .L7F03E78C
   lw    $s0, 0xc($s0)
  lw    $a0, 8($s0)
  beql  $a0, $zero, .L7F03E78C
   lw    $s0, 0xc($s0)
  lw    $t9, 0x10($a0)
  beql  $t9, $zero, .L7F03E78C
   lw    $s0, 0xc($s0)
  jal   check_if_object_has_not_been_destroyed
   nop   
  beql  $v0, $zero, .L7F03E78C
   lw    $s0, 0xc($s0)
  b     .L7F03E798
   move  $v0, $zero
  lw    $s0, 0xc($s0)
.L7F03E78C:
  bnezl $s0, .L7F03E750
   lw    $t8, 4($s0)
  li    $v0, 1
.L7F03E798:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x20
");

asm(R"
glabel sub_GAME_7F03E7AC
  lw    $t6, 0xc($a0)
  lui   $v0, %hi(D_80030B08)
  andi  $t7, $t6, 0x400
  beql  $t7, $zero, .L7F03E828
   li    $v0, 1
  lw    $v0, %lo(D_80030B08)($v0)
  li    $at, 0x3F000000 # 0.500000
  beql  $v0, $zero, .L7F03E828
   li    $v0, 1
  mtc1  $at, $f0
  nop   
  lw    $t8, 4($v0)
.L7F03E7DC:
  bnel  $a0, $t8, .L7F03E81C
   lw    $v0, 0x10($v0)
  lw    $v1, 0xc($v0)
  beql  $v1, $zero, .L7F03E81C
   lw    $v0, 0x10($v0)
  lw    $t9, 0x10($v1)
  beql  $t9, $zero, .L7F03E81C
   lw    $v0, 0x10($v0)
  lwc1  $f4, 0xb4($v1)
  c.le.s $f4, $f0
  nop   
  bc1fl .L7F03E81C
   lw    $v0, 0x10($v0)
  jr    $ra
   move  $v0, $zero

  lw    $v0, 0x10($v0)
.L7F03E81C:
  bnezl $v0, .L7F03E7DC
   lw    $t8, 4($v0)
  li    $v0, 1
.L7F03E828:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F03E830
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lw    $v0, 0x10($a0)
  lw    $a0, 0x14($v0)
  lw    $a1, 8($v0)
  jal   sub_GAME_7F0B2970
   lw    $a2, 0x10($v0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F03E85C
  jr    $ra
   lwc1  $f0, 4($a0)
");

asm(R"
glabel sub_GAME_7F03E864
  jr    $ra
   lwc1  $f0, 0xc($a0)
");

asm(R"
glabel sub_GAME_7F03E86C
  jr    $ra
   lwc1  $f0, 0x10($a0)
");

asm(R"
glabel sub_GAME_7F03E874
  jr    $ra
   lwc1  $f0, 0x14($a0)
");

asm(R"
glabel sub_GAME_7F03E87C
  mtc1  $zero, $f12
  lwc1  $f0, ($a1)
  c.le.s $f12, $f0
  nop   
  bc1fl .L7F03E8A8
   lwc1  $f8, 8($a0)
  lwc1  $f4, 4($a0)
  mul.s $f6, $f4, $f0
  b     .L7F03E8B0
   add.s $f2, $f12, $f6
  lwc1  $f8, 8($a0)
.L7F03E8A8:
  mul.s $f10, $f8, $f0
  add.s $f2, $f12, $f10
.L7F03E8B0:
  lwc1  $f0, 0x10($a1)
  c.le.s $f12, $f0
  nop   
  bc1fl .L7F03E8D8
   lwc1  $f4, 0x10($a0)
  lwc1  $f16, 0xc($a0)
  mul.s $f18, $f16, $f0
  b     .L7F03E8E0
   add.s $f2, $f2, $f18
  lwc1  $f4, 0x10($a0)
.L7F03E8D8:
  mul.s $f6, $f4, $f0
  add.s $f2, $f2, $f6
.L7F03E8E0:
  lwc1  $f0, 0x20($a1)
  c.le.s $f12, $f0
  nop   
  bc1fl .L7F03E90C
   lwc1  $f16, 0x18($a0)
  lwc1  $f8, 0x14($a0)
  mul.s $f10, $f8, $f0
  add.s $f2, $f2, $f10
  jr    $ra
   mov.s $f0, $f2

  lwc1  $f16, 0x18($a0)
.L7F03E90C:
  mul.s $f18, $f16, $f0
  add.s $f2, $f2, $f18
  jr    $ra
   mov.s $f0, $f2
");

asm(R"
glabel sub_GAME_7F03E91C
  mtc1  $zero, $f12
  lwc1  $f0, ($a1)
  c.le.s $f0, $f12
  nop   
  bc1fl .L7F03E948
   lwc1  $f8, 8($a0)
  lwc1  $f4, 4($a0)
  mul.s $f6, $f4, $f0
  b     .L7F03E950
   add.s $f2, $f12, $f6
  lwc1  $f8, 8($a0)
.L7F03E948:
  mul.s $f10, $f8, $f0
  add.s $f2, $f12, $f10
.L7F03E950:
  lwc1  $f0, 0x10($a1)
  c.le.s $f0, $f12
  nop   
  bc1fl .L7F03E978
   lwc1  $f4, 0x10($a0)
  lwc1  $f16, 0xc($a0)
  mul.s $f18, $f16, $f0
  b     .L7F03E980
   add.s $f2, $f2, $f18
  lwc1  $f4, 0x10($a0)
.L7F03E978:
  mul.s $f6, $f4, $f0
  add.s $f2, $f2, $f6
.L7F03E980:
  lwc1  $f0, 0x20($a1)
  c.le.s $f0, $f12
  nop   
  bc1fl .L7F03E9AC
   lwc1  $f16, 0x18($a0)
  lwc1  $f8, 0x14($a0)
  mul.s $f10, $f8, $f0
  add.s $f2, $f2, $f10
  jr    $ra
   mov.s $f0, $f2

  lwc1  $f16, 0x18($a0)
.L7F03E9AC:
  mul.s $f18, $f16, $f0
  add.s $f2, $f2, $f18
  jr    $ra
   mov.s $f0, $f2
");

asm(R"
glabel sub_GAME_7F03E9BC
  mtc1  $zero, $f12
  lwc1  $f0, 4($a1)
  c.le.s $f12, $f0
  nop   
  bc1fl .L7F03E9E8
   lwc1  $f8, 8($a0)
  lwc1  $f4, 4($a0)
  mul.s $f6, $f4, $f0
  b     .L7F03E9F0
   add.s $f2, $f12, $f6
  lwc1  $f8, 8($a0)
.L7F03E9E8:
  mul.s $f10, $f8, $f0
  add.s $f2, $f12, $f10
.L7F03E9F0:
  lwc1  $f0, 0x14($a1)
  c.le.s $f12, $f0
  nop   
  bc1fl .L7F03EA18
   lwc1  $f4, 0x10($a0)
  lwc1  $f16, 0xc($a0)
  mul.s $f18, $f16, $f0
  b     .L7F03EA20
   add.s $f2, $f2, $f18
  lwc1  $f4, 0x10($a0)
.L7F03EA18:
  mul.s $f6, $f4, $f0
  add.s $f2, $f2, $f6
.L7F03EA20:
  lwc1  $f0, 0x24($a1)
  c.le.s $f12, $f0
  nop   
  bc1fl .L7F03EA4C
   lwc1  $f16, 0x18($a0)
  lwc1  $f8, 0x14($a0)
  mul.s $f10, $f8, $f0
  add.s $f2, $f2, $f10
  jr    $ra
   mov.s $f0, $f2

  lwc1  $f16, 0x18($a0)
.L7F03EA4C:
  mul.s $f18, $f16, $f0
  add.s $f2, $f2, $f18
  jr    $ra
   mov.s $f0, $f2
");

asm(R"
glabel sub_GAME_7F03EA5C
  mtc1  $zero, $f12
  lwc1  $f0, 4($a1)
  c.le.s $f0, $f12
  nop   
  bc1fl .L7F03EA88
   lwc1  $f8, 8($a0)
  lwc1  $f4, 4($a0)
  mul.s $f6, $f4, $f0
  b     .L7F03EA90
   add.s $f2, $f12, $f6
  lwc1  $f8, 8($a0)
.L7F03EA88:
  mul.s $f10, $f8, $f0
  add.s $f2, $f12, $f10
.L7F03EA90:
  lwc1  $f0, 0x14($a1)
  c.le.s $f0, $f12
  nop   
  bc1fl .L7F03EAB8
   lwc1  $f4, 0x10($a0)
  lwc1  $f16, 0xc($a0)
  mul.s $f18, $f16, $f0
  b     .L7F03EAC0
   add.s $f2, $f2, $f18
  lwc1  $f4, 0x10($a0)
.L7F03EAB8:
  mul.s $f6, $f4, $f0
  add.s $f2, $f2, $f6
.L7F03EAC0:
  lwc1  $f0, 0x24($a1)
  c.le.s $f0, $f12
  nop   
  bc1fl .L7F03EAEC
   lwc1  $f16, 0x18($a0)
  lwc1  $f8, 0x14($a0)
  mul.s $f10, $f8, $f0
  add.s $f2, $f2, $f10
  jr    $ra
   mov.s $f0, $f2

  lwc1  $f16, 0x18($a0)
.L7F03EAEC:
  mul.s $f18, $f16, $f0
  add.s $f2, $f2, $f18
  jr    $ra
   mov.s $f0, $f2
");

asm(R"
glabel sub_GAME_7F03EAFC
  mtc1  $zero, $f12
  lwc1  $f0, 8($a1)
  c.le.s $f12, $f0
  nop   
  bc1fl .L7F03EB28
   lwc1  $f8, 8($a0)
  lwc1  $f4, 4($a0)
  mul.s $f6, $f4, $f0
  b     .L7F03EB30
   add.s $f2, $f12, $f6
  lwc1  $f8, 8($a0)
.L7F03EB28:
  mul.s $f10, $f8, $f0
  add.s $f2, $f12, $f10
.L7F03EB30:
  lwc1  $f0, 0x18($a1)
  c.le.s $f12, $f0
  nop   
  bc1fl .L7F03EB58
   lwc1  $f4, 0x10($a0)
  lwc1  $f16, 0xc($a0)
  mul.s $f18, $f16, $f0
  b     .L7F03EB60
   add.s $f2, $f2, $f18
  lwc1  $f4, 0x10($a0)
.L7F03EB58:
  mul.s $f6, $f4, $f0
  add.s $f2, $f2, $f6
.L7F03EB60:
  lwc1  $f0, 0x28($a1)
  c.le.s $f12, $f0
  nop   
  bc1fl .L7F03EB8C
   lwc1  $f16, 0x18($a0)
  lwc1  $f8, 0x14($a0)
  mul.s $f10, $f8, $f0
  add.s $f2, $f2, $f10
  jr    $ra
   mov.s $f0, $f2

  lwc1  $f16, 0x18($a0)
.L7F03EB8C:
  mul.s $f18, $f16, $f0
  add.s $f2, $f2, $f18
  jr    $ra
   mov.s $f0, $f2
");

asm(R"
glabel sub_GAME_7F03EB9C
  mtc1  $zero, $f12
  lwc1  $f0, 8($a1)
  c.le.s $f0, $f12
  nop   
  bc1fl .L7F03EBC8
   lwc1  $f8, 8($a0)
  lwc1  $f4, 4($a0)
  mul.s $f6, $f4, $f0
  b     .L7F03EBD0
   add.s $f2, $f12, $f6
  lwc1  $f8, 8($a0)
.L7F03EBC8:
  mul.s $f10, $f8, $f0
  add.s $f2, $f12, $f10
.L7F03EBD0:
  lwc1  $f0, 0x18($a1)
  c.le.s $f0, $f12
  nop   
  bc1fl .L7F03EBF8
   lwc1  $f4, 0x10($a0)
  lwc1  $f16, 0xc($a0)
  mul.s $f18, $f16, $f0
  b     .L7F03EC00
   add.s $f2, $f2, $f18
  lwc1  $f4, 0x10($a0)
.L7F03EBF8:
  mul.s $f6, $f4, $f0
  add.s $f2, $f2, $f6
.L7F03EC00:
  lwc1  $f0, 0x28($a1)
  c.le.s $f0, $f12
  nop   
  bc1fl .L7F03EC2C
   lwc1  $f16, 0x18($a0)
  lwc1  $f8, 0x14($a0)
  mul.s $f10, $f8, $f0
  add.s $f2, $f2, $f10
  jr    $ra
   mov.s $f0, $f2

  lwc1  $f16, 0x18($a0)
.L7F03EC2C:
  mul.s $f18, $f16, $f0
  add.s $f2, $f2, $f18
  jr    $ra
   mov.s $f0, $f2
");

asm(R"
glabel sub_GAME_7F03EC3C
  mtc1  $zero, $f0
  lwc1  $f4, 8($a1)
  c.le.s $f4, $f0
  nop   
  bc1fl .L7F03EC64
   lwc1  $f8, 8($a0)
  lwc1  $f6, 4($a0)
  b     .L7F03EC68
   swc1  $f6, ($a2)
  lwc1  $f8, 8($a0)
.L7F03EC64:
  swc1  $f8, ($a2)
.L7F03EC68:
  lwc1  $f10, 0x18($a1)
  c.le.s $f10, $f0
  nop   
  bc1fl .L7F03EC8C
   lwc1  $f18, 0x10($a0)
  lwc1  $f16, 0xc($a0)
  b     .L7F03EC90
   swc1  $f16, 4($a2)
  lwc1  $f18, 0x10($a0)
.L7F03EC8C:
  swc1  $f18, 4($a2)
.L7F03EC90:
  lwc1  $f4, 0x28($a1)
  c.le.s $f4, $f0
  nop   
  bc1fl .L7F03ECB4
   lwc1  $f8, 0x18($a0)
  lwc1  $f6, 0x14($a0)
  jr    $ra
   swc1  $f6, 8($a2)

  lwc1  $f8, 0x18($a0)
.L7F03ECB4:
  swc1  $f8, 8($a2)
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F03ECC0
  addiu $sp, $sp, -0x1e0
  sw    $a2, 0x1e8($sp)
  lw    $a2, 0x1f8($sp)
  swc1  $f14, 0x1e4($sp)
  sw    $a3, 0x1ec($sp)
  lwc1  $f4, ($a2)
  cvt.d.s $f0, $f12
  addiu $t6, $sp, 0x160
  cvt.d.s $f6, $f4
  sll   $t9, $zero, 4
  sdc1  $f6, 0xf0($sp)
  lwc1  $f10, 8($a2)
  addu  $t1, $t9, $t6
  move  $t2, $zero
  cvt.d.s $f8, $f10
  sll   $t9, $t2, 4
  sdc1  $f8, 0xe8($sp)
  lwc1  $f4, 0x10($a2)
  addiu $t6, $sp, 0x160
  addu  $t0, $t9, $t6
  cvt.d.s $f6, $f4
  move  $a0, $zero
  sdc1  $f6, 0xe0($sp)
  lwc1  $f10, 0x18($a2)
  sll   $t9, $a0, 4
  addiu $t6, $sp, 0x160
  cvt.d.s $f8, $f10
  addu  $a3, $t9, $t6
  sdc1  $f8, 0xd8($sp)
  lwc1  $f6, 0x28($a2)
  lwc1  $f4, 0x20($a2)
  ldc1  $f8, 0xf0($sp)
  cvt.d.s $f10, $f6
  lwc1  $f6, 0x1e8($sp)
  sdc1  $f10, 0xc8($sp)
  ldc1  $f10, 0xe0($sp)
  cvt.d.s $f18, $f4
  mul.d $f4, $f8, $f0
  cvt.d.s $f2, $f6
  sdc1  $f10, 8($sp)
  sdc1  $f8, ($sp)
  mul.d $f6, $f10, $f2
  lwc1  $f10, 0x1f0($sp)
  move  $t3, $zero
  sll   $t9, $t3, 4
  cvt.d.s $f16, $f10
  sdc1  $f4, 0xa0($sp)
  mul.d $f10, $f18, $f16
  sdc1  $f4, 0x10($sp)
  add.d $f8, $f4, $f6
  sdc1  $f6, 0x98($sp)
  sdc1  $f6, 0x18($sp)
  addiu $t6, $sp, 0x160
  sdc1  $f8, 0x38($sp)
  move  $v0, $zero
  add.d $f4, $f8, $f10
  sdc1  $f10, 0x90($sp)
  addiu $a1, $sp, 0x170
  li    $v1, 1
  sdc1  $f4, 0x160($sp)
  ldc1  $f4, 0xe8($sp)
  addu  $t4, $t9, $t6
  addiu $t5, $sp, 0x130
  mul.d $f4, $f4, $f0
  sdc1  $f4, 0x88($sp)
  ldc1  $f4, 0xd8($sp)
  mul.d $f4, $f4, $f2
  sdc1  $f4, 0x80($sp)
  ldc1  $f6, 0x80($sp)
  ldc1  $f4, 0x88($sp)
  add.d $f4, $f4, $f6
  ldc1  $f6, 0xc8($sp)
  sdc1  $f4, 0x78($sp)
  mul.d $f4, $f6, $f16
  ldc1  $f6, 0x78($sp)
  add.d $f6, $f6, $f4
  sdc1  $f4, 0x70($sp)
  lwc1  $f4, 0x1f4($sp)
  sdc1  $f6, 0x168($sp)
  cvt.d.s $f6, $f4
  sdc1  $f6, 0xa8($sp)
  mul.d $f6, $f18, $f6
  ldc1  $f4, 0xa8($sp)
  sdc1  $f6, 0x68($sp)
  add.d $f6, $f8, $f6
  ldc1  $f8, 0xc8($sp)
  mul.d $f12, $f8, $f4
  sdc1  $f6, 0x170($sp)
  ldc1  $f6, 0x78($sp)
  lwc1  $f4, 0x1ec($sp)
  cvt.d.s $f0, $f4
  add.d $f8, $f6, $f12
  ldc1  $f6, 8($sp)
  mul.d $f14, $f6, $f0
  sdc1  $f8, 0x178($sp)
  ldc1  $f8, 0x10($sp)
  ldc1  $f6, 0xd8($sp)
  mul.d $f16, $f6, $f0
  add.d $f2, $f8, $f14
  ldc1  $f8, 0x88($sp)
  sdc1  $f14, 0x38($sp)
  add.d $f4, $f2, $f10
  add.d $f18, $f8, $f16
  sdc1  $f4, 0x180($sp)
  ldc1  $f4, 0x70($sp)
  ldc1  $f8, 0x68($sp)
  sdc1  $f18, 0x30($sp)
  add.d $f6, $f18, $f4
  add.d $f4, $f2, $f8
  sdc1  $f6, 0x188($sp)
  ldc1  $f6, ($sp)
  add.d $f8, $f18, $f12
  sdc1  $f4, 0x190($sp)
  lwc1  $f4, 0x1e4($sp)
  sdc1  $f8, 0x198($sp)
  cvt.d.s $f0, $f4
  ldc1  $f4, 0xe8($sp)
  mul.d $f8, $f6, $f0
  ldc1  $f6, 0x18($sp)
  mul.d $f14, $f4, $f0
  sdc1  $f8, 0x88($sp)
  add.d $f2, $f8, $f6
  ldc1  $f6, 0x80($sp)
  add.d $f8, $f2, $f10
  add.d $f18, $f14, $f6
  sdc1  $f8, 0x1a0($sp)
  ldc1  $f8, 0x70($sp)
  ldc1  $f6, 0x68($sp)
  add.d $f4, $f18, $f8
  add.d $f8, $f2, $f6
  ldc1  $f6, 0x88($sp)
  sdc1  $f4, 0x1a8($sp)
  add.d $f4, $f18, $f12
  sdc1  $f8, 0x1b0($sp)
  ldc1  $f8, 0x38($sp)
  add.d $f2, $f14, $f16
  sdc1  $f4, 0x1b8($sp)
  add.d $f0, $f6, $f8
  ldc1  $f6, 0x70($sp)
  add.d $f4, $f0, $f10
  ldc1  $f10, 0x68($sp)
  add.d $f8, $f2, $f6
  sdc1  $f4, 0x1c0($sp)
  add.d $f6, $f2, $f12
  sdc1  $f8, 0x1c8($sp)
  add.d $f4, $f0, $f10
  sdc1  $f6, 0x1d8($sp)
  sdc1  $f4, 0x1d0($sp)
  ldc1  $f0, ($t1)
.L7F03EF14:
  ldc1  $f2, ($a1)
  sll   $t7, $v1, 4
  addiu $t8, $sp, 0x160
  c.lt.d $f2, $f0
  nop   
  bc1tl .L7F03EF5C
   addu  $t1, $t7, $t8
  c.eq.d $f2, $f0
  nop   
  bc1fl .L7F03EF68
   addiu $v1, $v1, 1
  ldc1  $f8, 8($a1)
  ldc1  $f10, 8($t1)
  c.lt.d $f8, $f10
  nop   
  bc1fl .L7F03EF68
   addiu $v1, $v1, 1
  addu  $t1, $t7, $t8
.L7F03EF5C:
  ldc1  $f0, ($t1)
  move  $v0, $v1
  addiu $v1, $v1, 1
.L7F03EF68:
  slti  $at, $v1, 8
  bnez  $at, .L7F03EF14
   addiu $a1, $a1, 0x10
  li    $v1, 1
  addiu $a1, $sp, 0x170
.L7F03EF7C:
  ldc1  $f12, 8($t0)
  ldc1  $f2, 8($a1)
  sll   $t7, $v1, 4
  addiu $t8, $sp, 0x160
  c.lt.d $f12, $f2
  nop   
  bc1tl .L7F03EFC8
   move  $t2, $v1
  c.eq.d $f2, $f12
  nop   
  bc1fl .L7F03EFD0
   addiu $v1, $v1, 1
  ldc1  $f4, ($a1)
  ldc1  $f6, ($t0)
  c.lt.d $f4, $f6
  nop   
  bc1fl .L7F03EFD0
   addiu $v1, $v1, 1
  move  $t2, $v1
.L7F03EFC8:
  addu  $t0, $t7, $t8
  addiu $v1, $v1, 1
.L7F03EFD0:
  slti  $at, $v1, 8
  bnez  $at, .L7F03EF7C
   addiu $a1, $a1, 0x10
  li    $v1, 1
  addiu $a1, $sp, 0x170
.L7F03EFE4:
  ldc1  $f16, ($a3)
  ldc1  $f2, ($a1)
  sll   $t7, $v1, 4
  addiu $t8, $sp, 0x160
  c.lt.d $f16, $f2
  nop   
  bc1tl .L7F03F030
   move  $a0, $v1
  c.eq.d $f2, $f16
  nop   
  bc1fl .L7F03F038
   addiu $v1, $v1, 1
  ldc1  $f8, 8($a3)
  ldc1  $f10, 8($a1)
  c.lt.d $f8, $f10
  nop   
  bc1fl .L7F03F038
   addiu $v1, $v1, 1
  move  $a0, $v1
.L7F03F030:
  addu  $a3, $t7, $t8
  addiu $v1, $v1, 1
.L7F03F038:
  slti  $at, $v1, 8
  bnez  $at, .L7F03EFE4
   addiu $a1, $a1, 0x10
  li    $v1, 1
  addiu $a1, $sp, 0x170
.L7F03F04C:
  ldc1  $f2, 8($a1)
  ldc1  $f12, 8($t4)
  sll   $t7, $v1, 4
  addiu $t8, $sp, 0x160
  c.lt.d $f2, $f12
  nop   
  bc1tl .L7F03F098
   move  $t3, $v1
  c.eq.d $f2, $f12
  nop   
  bc1fl .L7F03F0A0
   addiu $v1, $v1, 1
  ldc1  $f4, ($t4)
  ldc1  $f6, ($a1)
  c.lt.d $f4, $f6
  nop   
  bc1fl .L7F03F0A0
   addiu $v1, $v1, 1
  move  $t3, $v1
.L7F03F098:
  addu  $t4, $t7, $t8
  addiu $v1, $v1, 1
.L7F03F0A0:
  slti  $at, $v1, 8
  bnez  $at, .L7F03F04C
   addiu $a1, $a1, 0x10
  move  $a1, $zero
  move  $v1, $zero
.L7F03F0B4:
  beql  $v1, $v0, .L7F03F0E4
   addiu $v1, $v1, 1
  beql  $v1, $a0, .L7F03F0E4
   addiu $v1, $v1, 1
  beql  $v1, $t2, .L7F03F0E4
   addiu $v1, $v1, 1
  beq   $v1, $t3, .L7F03F0E0
   sll   $t9, $a1, 2
  addu  $t6, $t5, $t9
  sw    $v1, ($t6)
  addiu $a1, $a1, 1
.L7F03F0E0:
  addiu $v1, $v1, 1
.L7F03F0E4:
  slti  $at, $v1, 8
  bnez  $at, .L7F03F0B4
   nop   
  cvt.s.d $f8, $f0
  lw    $t2, 0x1fc($sp)
  li    $a1, 1
  addiu $v0, $sp, 0x130
  swc1  $f8, ($t2)
  ldc1  $f10, 8($t1)
  addiu $t5, $sp, 0x140
  addiu $a0, $sp, 0x160
  cvt.s.d $f4, $f10
  swc1  $f4, 4($t2)
  ldc1  $f8, ($t1)
  ldc1  $f6, 8($t1)
  ldc1  $f2, ($t4)
  ldc1  $f12, 8($t4)
  sub.d $f16, $f8, $f2
  sub.d $f14, $f6, $f12
  lw    $v1, ($v0)
.L7F03F134:
  sll   $t7, $v1, 4
  addu  $t3, $a0, $t7
  ldc1  $f0, ($t3)
  ldc1  $f6, 8($t3)
  sub.d $f10, $f0, $f2
  sub.d $f8, $f6, $f12
  mul.d $f4, $f10, $f14
  nop   
  mul.d $f10, $f8, $f16
  c.lt.d $f4, $f10
  nop   
  bc1f  .L7F03F18C
   nop   
  cvt.s.d $f6, $f0
  addiu $v0, $t2, 8
  li    $a1, 2
  swc1  $f6, ($v0)
  ldc1  $f8, 8($t3)
  cvt.s.d $f4, $f8
  swc1  $f4, 4($v0)
  b     .L7F03F19C
   ldc1  $f2, ($t4)
.L7F03F18C:
  addiu $v0, $v0, 4
  sltu  $at, $v0, $t5
  bnezl $at, .L7F03F134
   lw    $v1, ($v0)
.L7F03F19C:
  cvt.s.d $f10, $f2
  sll   $t8, $a1, 3
  addu  $t3, $t2, $t8
  addiu $t3, $t3, 8
  swc1  $f10, -8($t3)
  ldc1  $f6, 8($t4)
  addiu $a1, $a1, 1
  addiu $v0, $sp, 0x130
  cvt.s.d $f8, $f6
  addiu $t5, $sp, 0x140
  swc1  $f8, -4($t3)
  ldc1  $f10, ($t4)
  ldc1  $f4, 8($t4)
  ldc1  $f0, 8($a3)
  ldc1  $f16, ($a3)
  sub.d $f12, $f4, $f0
  sub.d $f14, $f10, $f16
  lw    $v1, ($v0)
.L7F03F1E4:
  sll   $t9, $v1, 4
  addu  $t4, $a0, $t9
  ldc1  $f2, ($t4)
  ldc1  $f4, 8($t4)
  sub.d $f6, $f2, $f16
  sub.d $f10, $f4, $f0
  mul.d $f8, $f6, $f12
  nop   
  mul.d $f6, $f10, $f14
  c.lt.d $f8, $f6
  nop   
  bc1f  .L7F03F23C
   nop   
  cvt.s.d $f4, $f2
  addiu $a1, $a1, 1
  addiu $t3, $t3, 8
  swc1  $f4, -8($t3)
  ldc1  $f10, 8($t4)
  cvt.s.d $f8, $f10
  swc1  $f8, -4($t3)
  b     .L7F03F24C
   ldc1  $f16, ($a3)
.L7F03F23C:
  addiu $v0, $v0, 4
  sltu  $at, $v0, $t5
  bnezl $at, .L7F03F1E4
   lw    $v1, ($v0)
.L7F03F24C:
  cvt.s.d $f6, $f16
  addiu $a1, $a1, 1
  addiu $t3, $t3, 8
  addiu $v0, $sp, 0x130
  swc1  $f6, -8($t3)
  ldc1  $f4, 8($a3)
  addiu $t4, $sp, 0x140
  cvt.s.d $f10, $f4
  swc1  $f10, -4($t3)
  ldc1  $f6, ($a3)
  ldc1  $f8, 8($a3)
  ldc1  $f14, ($t0)
  ldc1  $f12, 8($t0)
  sub.d $f18, $f6, $f14
  sub.d $f2, $f8, $f12
  lw    $v1, ($v0)
.L7F03F28C:
  sll   $t6, $v1, 4
  addu  $a3, $a0, $t6
  ldc1  $f0, ($a3)
  ldc1  $f8, 8($a3)
  sub.d $f4, $f0, $f14
  sub.d $f6, $f8, $f12
  mul.d $f10, $f4, $f2
  nop   
  mul.d $f4, $f6, $f18
  c.lt.d $f10, $f4
  nop   
  bc1f  .L7F03F2E4
   nop   
  cvt.s.d $f8, $f0
  addiu $a1, $a1, 1
  addiu $t3, $t3, 8
  swc1  $f8, -8($t3)
  ldc1  $f6, 8($a3)
  cvt.s.d $f10, $f6
  swc1  $f10, -4($t3)
  b     .L7F03F2F4
   ldc1  $f14, ($t0)
.L7F03F2E4:
  addiu $v0, $v0, 4
  sltu  $at, $v0, $t4
  bnezl $at, .L7F03F28C
   lw    $v1, ($v0)
.L7F03F2F4:
  cvt.s.d $f4, $f14
  addiu $a1, $a1, 1
  addiu $t3, $t3, 8
  addiu $v0, $sp, 0x130
  swc1  $f4, -8($t3)
  ldc1  $f8, 8($t0)
  cvt.s.d $f6, $f8
  swc1  $f6, -4($t3)
  ldc1  $f4, ($t0)
  ldc1  $f10, 8($t0)
  ldc1  $f2, 8($t1)
  ldc1  $f0, ($t1)
  addiu $t0, $sp, 0x140
  sub.d $f16, $f10, $f2
  sub.d $f18, $f4, $f0
  lw    $v1, ($v0)
.L7F03F334:
  sll   $t7, $v1, 4
  addu  $a3, $a0, $t7
  ldc1  $f12, ($a3)
  ldc1  $f10, 8($a3)
  sub.d $f8, $f12, $f0
  sub.d $f4, $f10, $f2
  mul.d $f6, $f8, $f16
  nop   
  mul.d $f8, $f4, $f18
  c.lt.d $f6, $f8
  nop   
  bc1f  .L7F03F388
   nop   
  cvt.s.d $f10, $f12
  addiu $a1, $a1, 1
  move  $v1, $zero
  swc1  $f10, ($t3)
  ldc1  $f4, 8($a3)
  cvt.s.d $f6, $f4
  b     .L7F03F39C
   swc1  $f6, 4($t3)
.L7F03F388:
  addiu $v0, $v0, 4
  sltu  $at, $v0, $t0
  bnezl $at, .L7F03F334
   lw    $v1, ($v0)
  move  $v1, $zero
.L7F03F39C:
  lw    $t8, 0x200($sp)
  blez  $a1, .L7F03F538
   sw    $a1, ($t8)
  andi  $a3, $a1, 3
  beqz  $a3, .L7F03F418
   move  $a0, $a3
  sll   $t9, $v1, 3
  addu  $v0, $t2, $t9
  addiu $v1, $v1, 1
  beq   $a0, $v1, .L7F03F3F4
   lwc1  $f18, ($v0)
.L7F03F3C8:
  lwc1  $f16, 0x30($a2)
  lwc1  $f14, 4($v0)
  addiu $v1, $v1, 1
  add.s $f16, $f18, $f16
  lwc1  $f18, 8($v0)
  addiu $v0, $v0, 8
  swc1  $f16, -8($v0)
  lwc1  $f16, 0x38($a2)
  add.s $f16, $f14, $f16
  bne   $a0, $v1, .L7F03F3C8
   swc1  $f16, -4($v0)
.L7F03F3F4:
  lwc1  $f16, 0x30($a2)
  lwc1  $f14, 4($v0)
  addiu $v0, $v0, 8
  add.s $f16, $f18, $f16
  swc1  $f16, -8($v0)
  lwc1  $f16, 0x38($a2)
  add.s $f16, $f14, $f16
  swc1  $f16, -4($v0)
  beq   $v1, $a1, .L7F03F538
.L7F03F418:
   sll   $t6, $v1, 3
  sll   $t7, $a1, 3
  addu  $a0, $t7, $t2
  addu  $v0, $t2, $t6
  addiu $v0, $v0, 0x20
  beq   $v0, $a0, .L7F03F4BC
   lwc1  $f18, -0x20($v0)
.L7F03F434:
  lwc1  $f16, 0x30($a2)
  lwc1  $f14, -0x1c($v0)
  lwc1  $f12, -0x18($v0)
  add.s $f16, $f18, $f16
  lwc1  $f10, -0x14($v0)
  lwc1  $f8, -0x10($v0)
  lwc1  $f6, -0xc($v0)
  swc1  $f16, -0x20($v0)
  lwc1  $f16, 0x38($a2)
  lwc1  $f4, -8($v0)
  lwc1  $f2, -4($v0)
  add.s $f16, $f14, $f16
  lwc1  $f18, ($v0)
  addiu $v0, $v0, 0x20
  swc1  $f16, -0x3c($v0)
  lwc1  $f16, 0x30($a2)
  add.s $f16, $f12, $f16
  swc1  $f16, -0x38($v0)
  lwc1  $f16, 0x38($a2)
  add.s $f16, $f10, $f16
  swc1  $f16, -0x34($v0)
  lwc1  $f16, 0x30($a2)
  add.s $f16, $f8, $f16
  swc1  $f16, -0x30($v0)
  lwc1  $f16, 0x38($a2)
  add.s $f16, $f6, $f16
  swc1  $f16, -0x2c($v0)
  lwc1  $f16, 0x30($a2)
  add.s $f16, $f4, $f16
  swc1  $f16, -0x28($v0)
  lwc1  $f16, 0x38($a2)
  add.s $f16, $f2, $f16
  bne   $v0, $a0, .L7F03F434
   swc1  $f16, -0x24($v0)
.L7F03F4BC:
  lwc1  $f16, 0x30($a2)
  lwc1  $f14, -0x1c($v0)
  lwc1  $f12, -0x18($v0)
  add.s $f16, $f18, $f16
  lwc1  $f10, -0x14($v0)
  lwc1  $f8, -0x10($v0)
  lwc1  $f6, -0xc($v0)
  swc1  $f16, -0x20($v0)
  lwc1  $f16, 0x38($a2)
  lwc1  $f4, -8($v0)
  lwc1  $f2, -4($v0)
  add.s $f16, $f14, $f16
  swc1  $f16, -0x1c($v0)
  lwc1  $f16, 0x30($a2)
  add.s $f16, $f12, $f16
  swc1  $f16, -0x18($v0)
  lwc1  $f16, 0x38($a2)
  add.s $f16, $f10, $f16
  swc1  $f16, -0x14($v0)
  lwc1  $f16, 0x30($a2)
  add.s $f16, $f8, $f16
  swc1  $f16, -0x10($v0)
  lwc1  $f16, 0x38($a2)
  add.s $f16, $f6, $f16
  swc1  $f16, -0xc($v0)
  lwc1  $f16, 0x30($a2)
  add.s $f16, $f4, $f16
  swc1  $f16, -8($v0)
  lwc1  $f16, 0x38($a2)
  add.s $f16, $f2, $f16
  swc1  $f16, -4($v0)
.L7F03F538:
  jr    $ra
   addiu $sp, $sp, 0x1e0
");

asm(R"
glabel sub_GAME_7F03F540
  addiu $sp, $sp, -0x30
  sw    $ra, 0x2c($sp)
  sw    $a2, 0x38($sp)
  sw    $a3, 0x3c($sp)
  lwc1  $f4, 0x14($a0)
  lw    $a3, 0x10($a0)
  lw    $a2, 0xc($a0)
  lwc1  $f14, 8($a0)
  lwc1  $f12, 4($a0)
  swc1  $f4, 0x10($sp)
  lwc1  $f6, 0x18($a0)
  lw    $t7, 0x3c($sp)
  lw    $t6, 0x38($sp)
  sw    $a1, 0x18($sp)
  swc1  $f6, 0x14($sp)
  sw    $t7, 0x20($sp)
  jal   sub_GAME_7F03ECC0
   sw    $t6, 0x1c($sp)
  lw    $ra, 0x2c($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F03F598
  addiu $sp, $sp, -0x28
  sdc1  $f20, 8($sp)
  lwc1  $f6, ($a2)
  lwc1  $f4, ($a0)
  lwc1  $f10, 4($a2)
  lwc1  $f8, 4($a0)
  sub.s $f0, $f4, $f6
  lwc1  $f4, 8($a2)
  lwc1  $f18, 8($a0)
  sub.s $f2, $f8, $f10
  lwc1  $f8, 0x20($a2)
  lwc1  $f6, 0x10($a2)
  sub.s $f12, $f18, $f4
  lwc1  $f4, 0x14($a2)
  mul.s $f10, $f6, $f8
  lwc1  $f18, 0x1c($a2)
  mtc1  $a1, $f20
  mul.s $f6, $f18, $f4
  sub.s $f8, $f10, $f6
  swc1  $f8, 0x10($sp)
  lwc1  $f4, 0x18($a2)
  lwc1  $f18, 0x14($a2)
  lwc1  $f6, 0x20($a2)
  lwc1  $f8, 0xc($a2)
  mul.s $f10, $f18, $f4
  nop   
  mul.s $f18, $f6, $f8
  sub.s $f4, $f10, $f18
  swc1  $f4, 0x14($sp)
  lwc1  $f8, 0x1c($a2)
  lwc1  $f6, 0xc($a2)
  lwc1  $f18, 0x18($a2)
  lwc1  $f4, 0x10($a2)
  mul.s $f10, $f6, $f8
  nop   
  mul.s $f6, $f18, $f4
  sub.s $f8, $f10, $f6
  swc1  $f8, 0x18($sp)
  lwc1  $f18, 0x18($a2)
  lwc1  $f10, 0x1c($a2)
  mul.s $f4, $f0, $f18
  lwc1  $f18, 0x20($a2)
  mul.s $f6, $f2, $f10
  add.s $f8, $f4, $f6
  mul.s $f10, $f18, $f12
  lwc1  $f4, 0x40($a2)
  add.s $f6, $f4, $f20
  add.s $f14, $f10, $f8
  c.lt.s $f6, $f14
  nop   
  bc1t  .L7F03F680
   nop   
  lwc1  $f18, 0x3c($a2)
  sub.s $f10, $f18, $f20
  c.lt.s $f14, $f10
  nop   
  bc1fl .L7F03F68C
   lwc1  $f8, 0xc($a2)
.L7F03F680:
  b     .L7F03F73C
   move  $v0, $zero
  lwc1  $f8, 0xc($a2)
.L7F03F68C:
  lwc1  $f6, 0x10($a2)
  mul.s $f4, $f0, $f8
  lwc1  $f8, 0x14($a2)
  mul.s $f18, $f2, $f6
  add.s $f10, $f4, $f18
  mul.s $f6, $f8, $f12
  lwc1  $f4, 0x38($a2)
  add.s $f18, $f4, $f20
  add.s $f14, $f6, $f10
  c.lt.s $f18, $f14
  nop   
  bc1t  .L7F03F6E0
   nop   
  lwc1  $f8, 0x34($a2)
  lwc1  $f10, 0x10($sp)
  lwc1  $f18, 0x14($sp)
  sub.s $f6, $f8, $f20
  c.lt.s $f14, $f6
  nop   
  bc1f  .L7F03F6E8
   nop   
.L7F03F6E0:
  b     .L7F03F73C
   move  $v0, $zero
.L7F03F6E8:
  mul.s $f4, $f0, $f10
  lwc1  $f10, 0x18($sp)
  mul.s $f8, $f2, $f18
  add.s $f6, $f4, $f8
  mul.s $f18, $f10, $f12
  lwc1  $f4, 0x30($a2)
  add.s $f8, $f4, $f20
  add.s $f16, $f18, $f6
  c.lt.s $f8, $f16
  nop   
  bc1t  .L7F03F734
   nop   
  lwc1  $f10, 0x2c($a2)
  li    $v0, 1
  sub.s $f18, $f10, $f20
  c.lt.s $f16, $f18
  nop   
  bc1f  .L7F03F73C
   nop   
.L7F03F734:
  b     .L7F03F73C
   move  $v0, $zero
.L7F03F73C:
  ldc1  $f20, 8($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
glabel sub_GAME_7F03F748
  addiu $sp, $sp, -0x48
  sw    $ra, 0x44($sp)
  sw    $fp, 0x40($sp)
  sw    $s7, 0x3c($sp)
  sw    $s6, 0x38($sp)
  sw    $s5, 0x34($sp)
  sw    $s4, 0x30($sp)
  sw    $s3, 0x2c($sp)
  sw    $s2, 0x28($sp)
  sw    $s1, 0x24($sp)
  sw    $s0, 0x20($sp)
  sdc1  $f20, 0x18($sp)
  sw    $a0, 0x48($sp)
  lw    $t7, 8($a0)
  move  $s4, $a3
  move  $s5, $a1
  lw    $s0, ($t7)
  move  $s6, $a2
  li    $s3, 1
  beqz  $s0, .L7F03F8D8
   li    $fp, 1
  li    $s7, 10
  lhu   $v0, ($s0)
.L7F03F7A4:
  lw    $a0, 0x48($sp)
  move  $a1, $s0
  andi  $t8, $v0, 0xff
  bne   $t8, $s7, .L7F03F894
   move  $a2, $zero
  jal   sub_GAME_7F06C660
   lw    $s2, 4($s0)
  bnez  $s4, .L7F03F7F4
   move  $s1, $v0
  move  $a0, $s2
  jal   sub_GAME_7F03E91C
   move  $a1, $v0
  lwc1  $f4, 0x30($s1)
  move  $a0, $s2
  move  $a1, $s1
  jal   sub_GAME_7F03E87C
   add.s $f20, $f4, $f0
  lwc1  $f6, 0x30($s1)
  b     .L7F03F84C
   add.s $f2, $f6, $f0
.L7F03F7F4:
  bne   $s4, $fp, .L7F03F828
   move  $a0, $s2
  move  $a0, $s2
  jal   sub_GAME_7F03EA5C
   move  $a1, $s1
  lwc1  $f8, 0x34($s1)
  move  $a0, $s2
  move  $a1, $s1
  jal   sub_GAME_7F03E9BC
   add.s $f20, $f8, $f0
  lwc1  $f10, 0x34($s1)
  b     .L7F03F84C
   add.s $f2, $f10, $f0
.L7F03F828:
  jal   sub_GAME_7F03EB9C
   move  $a1, $s1
  lwc1  $f16, 0x38($s1)
  move  $a0, $s2
  move  $a1, $s1
  jal   sub_GAME_7F03EAFC
   add.s $f20, $f16, $f0
  lwc1  $f18, 0x38($s1)
  add.s $f2, $f18, $f0
.L7F03F84C:
  bnez  $s3, .L7F03F868
   sltu  $v0, $zero, $s3
  lwc1  $f4, ($s5)
  c.lt.s $f4, $f20
  nop   
  bc1f  .L7F03F86C
   nop   
.L7F03F868:
  swc1  $f20, ($s5)
.L7F03F86C:
  bnez  $v0, .L7F03F888
   move  $s3, $zero
  lwc1  $f6, ($s6)
  c.lt.s $f2, $f6
  nop   
  bc1f  .L7F03F88C
   nop   
.L7F03F888:
  swc1  $f2, ($s6)
.L7F03F88C:
  b     .L7F03F898
   lw    $v0, 0x14($s0)
.L7F03F894:
  lw    $v0, 0x14($s0)
.L7F03F898:
  beqz  $v0, .L7F03F8A8
   nop   
  b     .L7F03F8D0
   move  $s0, $v0
.L7F03F8A8:
  beqz  $s0, .L7F03F8D0
   nop   
  lw    $v0, 0xc($s0)
.L7F03F8B4:
  beql  $v0, $zero, .L7F03F8C8
   lw    $s0, 8($s0)
  b     .L7F03F8D0
   move  $s0, $v0
  lw    $s0, 8($s0)
.L7F03F8C8:
  bnezl $s0, .L7F03F8B4
   lw    $v0, 0xc($s0)
.L7F03F8D0:
  bnezl $s0, .L7F03F7A4
   lhu   $v0, ($s0)
.L7F03F8D8:
  lw    $ra, 0x44($sp)
  ldc1  $f20, 0x18($sp)
  lw    $s0, 0x20($sp)
  lw    $s1, 0x24($sp)
  lw    $s2, 0x28($sp)
  lw    $s3, 0x2c($sp)
  lw    $s4, 0x30($sp)
  lw    $s5, 0x34($sp)
  lw    $s6, 0x38($sp)
  lw    $s7, 0x3c($sp)
  lw    $fp, 0x40($sp)
  jr    $ra
   addiu $sp, $sp, 0x48
");

asm(R"
glabel sub_GAME_7F03F90C
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a3, 0x24($sp)
  sw    $a0, 0x18($sp)
  jal   sub_GAME_7F03F748
   move  $a3, $zero
  lw    $a0, 0x18($sp)
  lw    $a1, 0x24($sp)
  lw    $a2, 0x28($sp)
  jal   sub_GAME_7F03F748
   li    $a3, 1
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F03F948
  addiu $sp, $sp, -0x38
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a1, 0x3c($sp)
  sw    $a2, 0x40($sp)
  sw    $a3, 0x44($sp)
  lwc1  $f4, ($a1)
  move  $s0, $a0
  addiu $a1, $sp, 0x24
  swc1  $f4, 0x2c($sp)
  lwc1  $f6, 4($a0)
  swc1  $f6, 0x30($sp)
  lwc1  $f8, 8($a0)
  addiu $a0, $sp, 0x2c
  jal   sub_GAME_7F077FF4
   swc1  $f8, 0x34($sp)
  lwc1  $f10, 0x24($sp)
  lw    $t7, 0x44($sp)
  addiu $a0, $sp, 0x2c
  addiu $a1, $sp, 0x24
  swc1  $f10, ($t7)
  lw    $t8, 0x3c($sp)
  lwc1  $f16, 4($t8)
  swc1  $f16, 0x2c($sp)
  lwc1  $f18, 4($s0)
  swc1  $f18, 0x30($sp)
  lwc1  $f4, 8($s0)
  jal   sub_GAME_7F077FF4
   swc1  $f4, 0x34($sp)
  lwc1  $f6, 0x24($sp)
  lw    $t9, 0x48($sp)
  addiu $a0, $sp, 0x2c
  addiu $a1, $sp, 0x24
  swc1  $f6, ($t9)
  lwc1  $f8, ($s0)
  lw    $t0, 0x40($sp)
  swc1  $f8, 0x2c($sp)
  lwc1  $f10, 4($t0)
  swc1  $f10, 0x30($sp)
  lwc1  $f16, 8($s0)
  jal   sub_GAME_7F077FF4
   swc1  $f16, 0x34($sp)
  lwc1  $f18, 0x28($sp)
  lw    $t1, 0x44($sp)
  addiu $a0, $sp, 0x2c
  addiu $a1, $sp, 0x24
  swc1  $f18, 4($t1)
  lwc1  $f4, ($s0)
  lw    $t2, 0x40($sp)
  swc1  $f4, 0x2c($sp)
  lwc1  $f6, ($t2)
  swc1  $f6, 0x30($sp)
  lwc1  $f8, 8($s0)
  jal   sub_GAME_7F077FF4
   swc1  $f8, 0x34($sp)
  lwc1  $f10, 0x28($sp)
  lw    $t3, 0x48($sp)
  swc1  $f10, 4($t3)
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   
");

asm(R"
glabel scan_position_data_table_for_normal_object_at_preset
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   get_ptr_obj_pos_list_current_entry
   sw    $a0, 0x18($sp)
  lw    $a1, 0x18($sp)
  beqz  $v0, .L7F03FA9C
   move  $v1, $v0
  li    $v0, 1
  lbu   $t6, ($v1)
.L7F03FA68:
  bnel  $v0, $t6, .L7F03FA94
   lw    $v1, 0x24($v1)
  lw    $a0, 4($v1)
  sll   $t7, $a1, 0x10
  sra   $t8, $t7, 0x10
  lh    $t9, 6($a0)
  bnel  $t8, $t9, .L7F03FA94
   lw    $v1, 0x24($v1)
  b     .L7F03FAA0
   move  $v0, $a0
  lw    $v1, 0x24($v1)
.L7F03FA94:
  bnezl $v1, .L7F03FA68
   lbu   $t6, ($v1)
.L7F03FA9C:
  move  $v0, $zero
.L7F03FAA0:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F03FAB0
  addiu $sp, $sp, -0x40
  sw    $ra, 0x2c($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  move  $s1, $a1
  move  $s2, $a0
  sw    $s5, 0x28($sp)
  sw    $s4, 0x24($sp)
  sw    $s3, 0x20($sp)
  jal   get_ptr_obj_pos_list_current_entry
   sw    $s0, 0x14($sp)
  beqz  $v0, .L7F03FB48
   move  $s0, $v0
  addiu $s5, $sp, 0x34
  addiu $s4, $sp, 0x38
  li    $s3, 1
  lbu   $t6, ($s0)
.L7F03FAF4:
  bnel  $s3, $t6, .L7F03FB40
   lw    $s0, 0x24($s0)
  lw    $t7, 0x14($s0)
  move  $a0, $s0
  move  $a1, $s4
  lbu   $t8, 3($t7)
  bnel  $s1, $t8, .L7F03FB40
   lw    $s0, 0x24($s0)
  jal   sub_GAME_7F03CCB0
   move  $a2, $s5
  move  $a0, $s2
  lw    $a1, 0x38($sp)
  jal   sub_GAME_7F03CCD8
   lw    $a2, 0x34($sp)
  beql  $v0, $zero, .L7F03FB40
   lw    $s0, 0x24($s0)
  b     .L7F03FB4C
   lw    $v0, 4($s0)
  lw    $s0, 0x24($s0)
.L7F03FB40:
  bnezl $s0, .L7F03FAF4
   lbu   $t6, ($s0)
.L7F03FB48:
  move  $v0, $zero
.L7F03FB4C:
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  lw    $s4, 0x24($sp)
  lw    $s5, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x40
");
