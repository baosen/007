#include "chrai.h"

typedef struct {
  void *ptranimation;
  unsigned short offsettocurcmd, waitcounter;
  unsigned int imagenum;
  float rotation, curzoomx, startzoomx, zoomxtimer, initialzoomx, finalzoomx,
      curzoomy, startzoomy, zoomytimer, initialzoomy, finalzoomy,
      curhorizontalpos, starthorscroll, horscrolltimer, horinitpos, horfinalpos,
      curverpos, startverscroll, verscrolltimer, verinitpos, verfinalpos;
  unsigned char curredcomponant, initredcomponant, finalredcomponant,
      curgreencomponant, initgreencomponant, finalgreencomponant,
      curbluecomponant, initbluecomponant, finalbluecomponant,
      curalphacomponant, initalphacomponant, finalalphacomponant;
  float startcolorshift, colorshifttimer;
} object_animation_controller;

object_animation_controller ptr_monitorimageobjectanimationcontroller = {
    &monitor_animation_microcode,
    0,
    0xFFFF,
    0,
    0.0,
    1.0,
    0.0,
    0.0,
    1.0,
    1.0,
    1.0,
    0.0,
    0.0,
    1.0,
    1.0,
    0.5,
    0.0,
    0.0,
    0.5,
    0.5,
    0.5,
    0.0,
    0.0,
    0.5,
    0.5,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    1.0,
    0.0};
object_animation_controller unknown_object_animation_controller = {
    &dword_D_80031F00,
    0,
    0xFFFF,
    0,
    0,
    1.0,
    0.0,
    0.0,
    1.0,
    1.0,
    1.0,
    0.0,
    0.0,
    1.0,
    1.0,
    0.5,
    0.0,
    0.0,
    0.5,
    0.5,
    0.5,
    0.0,
    0.0,
    0.5,
    0.5,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    1.0};
object_animation_controller taser_object_animation_controller = {
    &dword_D_80031F44,
    0,
    0xFFFF,
    0,
    0,
    1.0,
    0.0,
    0.0,
    1.0,
    1.0,
    1.0,
    0.0,
    0.0,
    1.0,
    1.0,
    0.5,
    0.0,
    0.0,
    0.5,
    0.5,
    0.5,
    0.0,
    0.0,
    0.5,
    0.5,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    1.0};

float unused_8002a3bc = 0.0f;
float scale_1_0_item_related = 1.0f;

asm(R"
glabel init_sound_effects_registers
  lui   $v1, %hi(sfx_related)
  lui   $v0, %hi(ptr_list_object_lookup_indices)
  addiu $v0, %lo(ptr_list_object_lookup_indices) # addiu $v0, $v0, -0x63d0
  addiu $v1, %lo(sfx_related) # addiu $v1, $v1, -0x6490
.L7F0014C0:
  addiu $v1, $v1, 0x60
  sw    $zero, -0x48($v1)
  sw    $zero, -0x30($v1)
  sw    $zero, -0x18($v1)
  bne   $v1, $v0, .L7F0014C0
   sw    $zero, -0x60($v1)
  jr    $ra
   nop   
");

asm(R"
glabel init_load_objpos_table
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  lui   $at, %hi(difficulty)
  lui   $v0, %hi(ptr_obj_pos_list_first_entry)
  swc1  $f4, %lo(difficulty)($at)
  addiu $v0, %lo(ptr_obj_pos_list_first_entry) # addiu $v0, $v0, 0xaa4
  sw    $zero, ($v0)
  lui   $at, %hi(ptr_obj_pos_list_current_entry)
  sw    $zero, %lo(ptr_obj_pos_list_current_entry)($at)
  lui   $at, %hi(dword_CODE_bss_80071DF4)
  lui   $v1, %hi(dword_CODE_bss_80071620)
  sw    $zero, %lo(dword_CODE_bss_80071DF4)($at)
  addiu $v1, %lo(dword_CODE_bss_80071620) # addiu $v1, $v1, 0x1620
  sw    $zero, ($v1)
  lui   $at, %hi(dword_CODE_bss_80071DF0)
  sw    $v1, %lo(dword_CODE_bss_80071DF0)($at)
  lui   $t7, %hi(pos_data_entry) 
  addiu $t7, %lo(pos_data_entry) # addiu $t7, $t7, -0x63c8
  lui   $at, %hi(ptr_obj_pos_list_final_entry)
  sw    $t7, %lo(ptr_obj_pos_list_final_entry)($at)
  lui   $t8, %hi(dword_CODE_bss_80069C6C) 
  addiu $t8, %lo(dword_CODE_bss_80069C6C) # addiu $t8, $t8, -0x6394
  lui   $at, %hi(dword_CODE_bss_80069C5C)
  sw    $t8, %lo(dword_CODE_bss_80069C5C)($at)
  lui   $t9, %hi(dword_CODE_bss_80069CA0) 
  addiu $t9, %lo(dword_CODE_bss_80069CA0) # addiu $t9, $t9, -0x6360
  lui   $at, %hi(dword_CODE_bss_80069C90)
  sw    $t9, %lo(dword_CODE_bss_80069C90)($at)
  lui   $t0, %hi(dword_CODE_bss_80069CD4)
  addiu $sp, $sp, -0x18
  addiu $v0, $t0, %lo(dword_CODE_bss_80069CD4)
  lui   $at, %hi(dword_CODE_bss_80069CC4)
  lui   $v1, %hi(dword_CODE_bss_80069DA4)
  lui   $a0, %hi(dword_CODE_bss_80069D08)
  lui   $a1, %hi(dword_CODE_bss_80069D3C)
  lui   $a2, %hi(dword_CODE_bss_80069D70)
  lui   $a3, %hi(dword_CODE_bss_800716B4)
  sw    $ra, 0x14($sp)
  addiu $a3, %lo(dword_CODE_bss_800716B4) # addiu $a3, $a3, 0x16b4
  addiu $a2, %lo(dword_CODE_bss_80069D70) # addiu $a2, $a2, -0x6290
  addiu $a1, %lo(dword_CODE_bss_80069D3C) # addiu $a1, $a1, -0x62c4
  addiu $a0, %lo(dword_CODE_bss_80069D08) # addiu $a0, $a0, -0x62f8
  addiu $v1, %lo(dword_CODE_bss_80069DA4) # addiu $v1, $v1, -0x625c
  sw    $v0, %lo(dword_CODE_bss_80069CC4)($at)
.L7F001590:
  sw    $v1, 0xc0($v0)
  addiu $v1, $v1, 0xd0
  sw    $a1, 0x58($v0)
  sw    $a2, 0x8c($v0)
  sw    $a0, 0x24($v0)
  addiu $a0, $a0, 0xd0
  addiu $a2, $a2, 0xd0
  addiu $a1, $a1, 0xd0
  bne   $v1, $a3, .L7F001590
   addiu $v0, $v0, 0xd0
  jal   alloc_lookup_buffers
   nop   
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel alloc_lookup_buffers
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  li    $a0, 1024
  jal   mempAllocBytesInBank
   li    $a1, 4
  lui   $a2, %hi(MaxNumRooms)
  lui   $at, %hi(ptr_list_object_lookup_indices)
  sw    $v0, %lo(ptr_list_object_lookup_indices)($at)
  addiu $a2, %lo(MaxNumRooms) # addiu $a2, $a2, 0x42f4
  lw    $a0, ($a2)
  li    $a1, 4
  sll   $t6, $a0, 2
  addiu $a0, $t6, 0xf
  ori   $t7, $a0, 0xf
  jal   mempAllocBytesInBank
   xori  $a0, $t7, 0xf
  lui   $a3, %hi(ptr_room_lookup_buffer_maybe)
  addiu $a3, %lo(ptr_room_lookup_buffer_maybe) # addiu $a3, $a3, 0x1618
  sw    $v0, ($a3)
  li    $a0, 8192
  jal   mempAllocBytesInBank
   li    $a1, 4
  lui   $a0, %hi(dword_CODE_bss_8007161C)
  addiu $a0, %lo(dword_CODE_bss_8007161C) # addiu $a0, $a0, 0x161c
  sw    $v0, ($a0)
  lui   $t9, %hi(ptr_list_object_lookup_indices) 
  lw    $t9, %lo(ptr_list_object_lookup_indices)($t9)
  li    $a1, -1
  lui   $a2, %hi(MaxNumRooms)
  addiu $a2, %lo(MaxNumRooms) # addiu $a2, $a2, 0x42f4
  sh    $a1, ($t9)
  lw    $t3, ($a2)
  lui   $a3, %hi(ptr_room_lookup_buffer_maybe)
  addiu $a3, %lo(ptr_room_lookup_buffer_maybe) # addiu $a3, $a3, 0x1618
  blez  $t3, .L7F00168C
   move  $v1, $zero
  move  $v0, $zero
  lw    $t4, ($a3)
.L7F001668:
  addiu $v1, $v1, 1
  addu  $t5, $t4, $v0
  sh    $a1, ($t5)
  lw    $t6, ($a2)
  addiu $v0, $v0, 2
  slt   $at, $v1, $t6
  bnezl $at, .L7F001668
   lw    $t4, ($a3)
  move  $v1, $zero
.L7F00168C:
  move  $a3, $zero
  li    $t2, 256
  li    $t1, -2
  li    $a2, 32
.L7F00169C:
  lw    $t7, ($a0)
  sll   $t3, $v1, 5
  sll   $t6, $v1, 5
  addu  $t8, $t7, $a3
  sh    $t1, ($t8)
  lw    $t9, ($a0)
  li    $v0, 8
  addu  $t4, $t9, $t3
  sh    $a1, 2($t4)
  lw    $t5, ($a0)
  sll   $t9, $v1, 5
  addu  $t7, $t5, $t6
  sh    $a1, 4($t7)
  lw    $t8, ($a0)
  addu  $t3, $t8, $t9
  sh    $a1, 6($t3)
.L7F0016DC:
  lw    $t4, ($a0)
  sll   $t5, $v1, 5
  sll   $t9, $v1, 5
  addu  $t6, $t4, $t5
  addu  $t7, $t6, $v0
  sh    $a1, ($t7)
  lw    $t8, ($a0)
  sll   $t6, $v1, 5
  addu  $t3, $t8, $t9
  addu  $t4, $t3, $v0
  sh    $a1, 2($t4)
  lw    $t5, ($a0)
  sll   $t3, $v1, 5
  addu  $t7, $t5, $t6
  addu  $t8, $t7, $v0
  sh    $a1, 4($t8)
  lw    $t9, ($a0)
  addu  $t4, $t9, $t3
  addu  $t5, $t4, $v0
  addiu $v0, $v0, 8
  bne   $v0, $a2, .L7F0016DC
   sh    $a1, 6($t5)
  addiu $v1, $v1, 1
  bne   $v1, $t2, .L7F00169C
   addiu $a3, $a3, 0x20
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel reinit_between_menus
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   write_monitor_ani_control_blocks
   nop   
  jal   initialize_temp_mine_table
   nop   
  lui   $at, %hi(alarm_timer)
  sw    $zero, %lo(alarm_timer)($at)
  mtc1  $zero, $f0
  lui   $at, %hi(ptr_alarm_sfx)
  sw    $zero, %lo(ptr_alarm_sfx)($at)
  lui   $at, %hi(toxic_gas_sound_timer)
  swc1  $f0, %lo(toxic_gas_sound_timer)($at)
  lui   $at, %hi(activate_gas_sound_timer)
  lui   $a0, %hi(D_80030AD0)
  sw    $zero, %lo(activate_gas_sound_timer)($at)
  addiu $a0, %lo(D_80030AD0) # addiu $a0, $a0, 0xad0
  lui   $at, %hi(D_80030ADC)
  swc1  $f0, ($a0)
  swc1  $f0, 4($a0)
  swc1  $f0, 8($a0)
  sw    $zero, %lo(D_80030ADC)($at)
  lui   $at, %hi(D_80030AE0)
  swc1  $f0, %lo(D_80030AE0)($at)
  lui   $at, %hi(ptr_gas_sound)
  sw    $zero, %lo(ptr_gas_sound)($at)
  li    $a1, 1
  lui   $at, %hi(clock_drawn_flag)
  sw    $a1, %lo(clock_drawn_flag)($at)
  lui   $at, %hi(clock_enable)
  sw    $zero, %lo(clock_enable)($at)
  lui   $at, %hi(clock_time)
  swc1  $f0, %lo(clock_time)($at)
  lui   $at, %hi(D_80030AF4)
  lui   $v0, %hi(ProjectileData_start_address)
  lui   $v1, %hi(dword_CODE_bss_80072E70)
  sw    $zero, %lo(D_80030AF4)($at)
  addiu $v1, %lo(dword_CODE_bss_80072E70) # addiu $v1, $v1, 0x2e70
  addiu $v0, %lo(ProjectileData_start_address) # addiu $v0, $v0, 0x1e80
.L7F0017EC:
  addiu $v0, $v0, 0x88
  sltu  $at, $v0, $v1
  bnez  $at, .L7F0017EC
   sw    $zero, -0x78($v0)
  lui   $at, %hi(D_80030AF8)
  lui   $v0, %hi(dword_CODE_bss_80072E70)
  lui   $v1, %hi(dword_CODE_bss_80073370)
  sw    $zero, %lo(D_80030AF8)($at)
  addiu $v1, %lo(dword_CODE_bss_80073370) # addiu $v1, $v1, 0x3370
  addiu $v0, %lo(dword_CODE_bss_80072E70) # addiu $v0, $v0, 0x2e70
.L7F001814:
  addiu $v0, $v0, 0x80
  sltu  $at, $v0, $v1
  bnez  $at, .L7F001814
   sw    $zero, -0x70($v0)
  lui   $at, %hi(D_80030AFC)
  lui   $v0, %hi(dword_CODE_bss_80073370)
  lui   $v1, %hi(dword_CODE_bss_80073DC0)
  sw    $zero, %lo(D_80030AFC)($at)
  addiu $v1, %lo(dword_CODE_bss_80073DC0) # addiu $v1, $v1, 0x3dc0
  addiu $v0, %lo(dword_CODE_bss_80073370) # addiu $v0, $v0, 0x3370
.L7F00183C:
  addiu $v0, $v0, 0x84
  sltu  $at, $v0, $v1
  bnez  $at, .L7F00183C
   sw    $zero, -0x74($v0)
  lui   $v0, %hi(dword_CODE_bss_80073DC0)
  lui   $a0, %hi(dword_CODE_bss_80075030)
  addiu $a0, %lo(dword_CODE_bss_80075030) # addiu $a0, $a0, 0x5030
  addiu $v0, %lo(dword_CODE_bss_80073DC0) # addiu $v0, $v0, 0x3dc0
  lui   $v1, 0x8000
.L7F001860:
  addiu $v0, $v0, 0xec
  sltu  $at, $v0, $a0
  sw    $v1, -0xec($v0)
  sw    $zero, -0x54($v0)
  bnez  $at, .L7F001860
   sw    $zero, -0x50($v0)
  lui   $v0, %hi(dword_CODE_bss_80075030)
  lui   $v1, %hi(objinst)
  addiu $v1, %lo(objinst) # addiu $v1, $v1, 0x5b70
  addiu $v0, %lo(dword_CODE_bss_80075030) # addiu $v0, $v0, 0x5030
.L7F001888:
  addiu $v0, $v0, 0x120
  sw    $a1, -0xd8($v0)
  sw    $a1, -0x90($v0)
  sw    $a1, -0x48($v0)
  bne   $v0, $v1, .L7F001888
   sw    $a1, -0x120($v0)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f0
  lui   $at, %hi(D_80030B00)
  sw    $zero, %lo(D_80030B00)($at)
  lui   $at, %hi(D_80030B04)
  sw    $zero, %lo(D_80030B04)($at)
  lui   $at, %hi(D_80030B08)
  sw    $zero, %lo(D_80030B08)($at)
  lui   $at, %hi(D_80030B0C)
  sw    $zero, %lo(D_80030B0C)($at)
  lui   $at, %hi(bodypartshot)
  li    $t6, -1
  sw    $t6, %lo(bodypartshot)($at)
  lui   $at, %hi(D_80030B14)
  swc1  $f0, %lo(D_80030B14)($at)
  lui   $at, %hi(D_80030B18)
  swc1  $f0, %lo(D_80030B18)($at)
  lui   $at, %hi(D_80030B1C)
  swc1  $f0, %lo(D_80030B1C)($at)
  lui   $at, %hi(D_80030B20)
  swc1  $f0, %lo(D_80030B20)($at)
  lw    $ra, 0x14($sp)
  lui   $at, %hi(D_80030B24)
  swc1  $f0, %lo(D_80030B24)($at)
  lui   $at, %hi(solo_ammo_multiplier)
  addiu $sp, $sp, 0x18
  jr    $ra
   swc1  $f0, %lo(solo_ammo_multiplier)($at)
");

asm(R"
glabel sub_GAME_7F001910
  lui   $v0, %hi(D_80030B00)
  addiu $v0, %lo(D_80030B00) # addiu $v0, $v0, 0xb00
  lw    $t6, ($v0)
  sw    $t6, 0xc($a0)
  jr    $ra
   sw    $a0, ($v0)
");

asm(R"
glabel sub_GAME_7F001928
  lui   $v0, %hi(D_80030B04)
  addiu $v0, %lo(D_80030B04) # addiu $v0, $v0, 0xb04
  lw    $t6, ($v0)
  sw    $t6, 0xc($a0)
  jr    $ra
   sw    $a0, ($v0)
");

asm(R"
glabel sub_GAME_7F001940
  lui   $v0, %hi(D_80030B08)
  addiu $v0, %lo(D_80030B08) # addiu $v0, $v0, 0xb08
  lw    $t6, ($v0)
  sw    $t6, 0x10($a0)
  jr    $ra
   sw    $a0, ($v0)
");

asm(R"
glabel write_monitor_ani_control_blocks
  addiu $sp, $sp, -0x160
  lui   $t6, %hi(ptr_monitorimageobjectanimationcontroller)
  addiu $v0, $sp, 0xec
  addiu $t6, $t6, %lo(ptr_monitorimageobjectanimationcontroller)
  addiu $v1, $sp, 0x78
  addiu $a0, $sp, 4
  addiu $t9, $t6, 0x6c
  move  $t0, $v0
.L7F001978:
  lw    $at, ($t6)
  addiu $t6, $t6, 0xc
  addiu $t0, $t0, 0xc
  sw    $at, -0xc($t0)
  lw    $at, -8($t6)
  sw    $at, -8($t0)
  lw    $at, -4($t6)
  bne   $t6, $t9, .L7F001978
   sw    $at, -4($t0)
  lw    $at, ($t6)
  lui   $t1, %hi(dword_CODE_bss_80075B98) 
  addiu $t1, %lo(dword_CODE_bss_80075B98) # addiu $t1, $t1, 0x5b98
  sw    $at, ($t0)
  lw    $t9, 4($t6)
  move  $t5, $v0
  addiu $t4, $v0, 0x6c
  sw    $t9, 4($t0)
.L7F0019BC:
  lw    $at, ($t5)
  addiu $t5, $t5, 0xc
  addiu $t1, $t1, 0xc
  sw    $at, -0xc($t1)
  lw    $at, -8($t5)
  sw    $at, -8($t1)
  lw    $at, -4($t5)
  bne   $t5, $t4, .L7F0019BC
   sw    $at, -4($t1)
  lw    $at, ($t5)
  lui   $t8, %hi(unknown_object_animation_controller) 
  addiu $t8, %lo(unknown_object_animation_controller) # addiu $t8, $t8, -0x5d2c
  sw    $at, ($t1)
  lw    $t4, 4($t5)
  addiu $t6, $t8, 0x6c
  move  $t0, $v1
  sw    $t4, 4($t1)
.L7F001A00:
  lw    $at, ($t8)
  addiu $t8, $t8, 0xc
  addiu $t0, $t0, 0xc
  sw    $at, -0xc($t0)
  lw    $at, -8($t8)
  sw    $at, -8($t0)
  lw    $at, -4($t8)
  bne   $t8, $t6, .L7F001A00
   sw    $at, -4($t0)
  lw    $at, ($t8)
  lui   $t3, %hi(dword_CODE_bss_80075C10) 
  addiu $t3, %lo(dword_CODE_bss_80075C10) # addiu $t3, $t3, 0x5c10
  sw    $at, ($t0)
  lw    $t6, 4($t8)
  move  $t1, $v1
  addiu $t5, $v1, 0x6c
  sw    $t6, 4($t0)
.L7F001A44:
  lw    $at, ($t1)
  addiu $t1, $t1, 0xc
  addiu $t3, $t3, 0xc
  sw    $at, -0xc($t3)
  lw    $at, -8($t1)
  sw    $at, -8($t3)
  lw    $at, -4($t1)
  bne   $t1, $t5, .L7F001A44
   sw    $at, -4($t3)
  lw    $at, ($t1)
  lui   $t9, %hi(taser_object_animation_controller) 
  addiu $t9, %lo(taser_object_animation_controller) # addiu $t9, $t9, -0x5cb8
  sw    $at, ($t3)
  lw    $t5, 4($t1)
  addiu $t8, $t9, 0x6c
  move  $t0, $a0
  sw    $t5, 4($t3)
.L7F001A88:
  lw    $at, ($t9)
  addiu $t9, $t9, 0xc
  addiu $t0, $t0, 0xc
  sw    $at, -0xc($t0)
  lw    $at, -8($t9)
  sw    $at, -8($t0)
  lw    $at, -4($t9)
  bne   $t9, $t8, .L7F001A88
   sw    $at, -4($t0)
  lw    $at, ($t9)
  lui   $t4, %hi(dword_CODE_bss_80075C88) 
  addiu $t4, %lo(dword_CODE_bss_80075C88) # addiu $t4, $t4, 0x5c88
  sw    $at, ($t0)
  lw    $t8, 4($t9)
  move  $t3, $a0
  addiu $t1, $a0, 0x6c
  sw    $t8, 4($t0)
.L7F001ACC:
  lw    $at, ($t3)
  addiu $t3, $t3, 0xc
  addiu $t4, $t4, 0xc
  sw    $at, -0xc($t4)
  lw    $at, -8($t3)
  sw    $at, -8($t4)
  lw    $at, -4($t3)
  bne   $t3, $t1, .L7F001ACC
   sw    $at, -4($t4)
  lw    $at, ($t3)
  sw    $at, ($t4)
  lw    $t1, 4($t3)
  addiu $sp, $sp, 0x160
  jr    $ra
   sw    $t1, 4($t4)
");

asm(R"
glabel initialize_temp_mine_table
  lui   $at, %hi(temp_mine_table)
  sw    $zero, %lo(temp_mine_table)($at)
  lui   $at, %hi(temp_mine_table+0x4)
  lui   $v1, %hi(temp_mine_table+0x8)
  lui   $v0, %hi(gas_damage_flag)
  addiu $v0, %lo(gas_damage_flag) # addiu $v0, $v0, 0x1e78
  addiu $v1, %lo(temp_mine_table+0x8) # addiu $v1, $v1, 0x1e08
  sw    $zero, %lo(temp_mine_table+0x4)($at)
.L7F001B28:
  addiu $v1, $v1, 0x10
  sw    $zero, -0xc($v1)
  sw    $zero, -8($v1)
  sw    $zero, -4($v1)
  bne   $v1, $v0, .L7F001B28
   sw    $zero, -0x10($v1)
  jr    $ra
   nop   
");
