#include <types.h>

struct mcm_layout {
  int xpos, ypos;
};

int get_debug_render_raster(void);
int get_debug_freeze_processing(void);
int get_debug_limit_controller_input(void);
void set_debug_limit_controller_input(void);
int get_memusage_display_flag(void);
int get_debug_do_draw_bg(void);
int get_debug_do_draw_obj(void);
int get_debug_stanhit_flag(void);
int get_debug_stanregion_flag(void);
int get_turbo_mode_flag(void);
int get_debug_man_pos_flag(void);
int get_debug_testingmanpos_flag(void);
void set_debug_testingmanpos_flag(int flag);
int get_debug_joy2skyedit_flag(void);
int get_debug_joy2hitsedit_flag(void);
int get_debug_joy2detailedit_flag(void);
int get_debug_explosioninfo_flag(void);
int get_debug_prroomloads_flag(void);
int get_debug_VisCVG_flag(void);
void set_debug_VisCVG_flag(int flag);
int get_debug_007_unlock_flag(void);
int get_debug_enable_agent_levels_flag(void);
int get_debug_enable_all_levels_flag(void);
int get_debug_fast_bond_flag(void);
void set_debug_fast_bond_flag(int flag);
int get_debug_all_obj_complete_flag(void);
int get_debug_portal_flag(void);
int get_debug_chrnum_flag(void);
int get_debug_gunwatchpos_flag(void);
int get_debug_profile_flag(void);
int get_debug_taskgrab_val(void);
void debug_menu_processor(void);

unsigned int D_80036BA0 = 0;
int mcm_column_groupings[] = {8, 0x13, 0x1E, 0x2B, 0x32, 0x39, 0x45, 0x4D, -1};

struct mcm_layout mcm_onscreen_positions[] = {
    {8, 5},       {8, 6},       {8, 7},       {8, 8},       {8, 9},
    {8, 0xA},     {8, 0xB},     {8, 0xC},     {0x19, 5},    {0x19, 6},
    {0x19, 7},    {0x19, 8},    {0x19, 9},    {0x19, 0xA},  {0x19, 0xB},
    {0x19, 0xC},  {0x19, 0xD},  {0x19, 0xE},  {0x19, 0xF},  {0x28, 5},
    {0x28, 6},    {0x28, 7},    {0x28, 8},    {0x28, 9},    {0x28, 0xA},
    {0x28, 0xB},  {0x28, 0xC},  {0x28, 0xD},  {0x28, 0xE},  {0x28, 0xF},
    {0x39, 5},    {0x39, 6},    {0x39, 7},    {0x39, 8},    {0x39, 9},
    {0x39, 0xA},  {0x39, 0xB},  {0x39, 0xC},  {0x39, 0xD},  {0x39, 0xE},
    {0x39, 0xF},  {0x39, 0x10}, {0x39, 0x11}, {8, 0x14},    {8, 0x15},
    {8, 0x16},    {8, 0x17},    {8, 0x18},    {8, 0x19},    {8, 0x1A},
    {0x19, 0x14}, {0x19, 0x15}, {0x19, 0x16}, {0x19, 0x17}, {0x19, 0x18},
    {0x19, 0x19}, {0x19, 0x1A}, {0x28, 0x14}, {0x28, 0x15}, {0x28, 0x16},
    {0x28, 0x17}, {0x28, 0x18}, {0x28, 0x19}, {0x28, 0x1A}, {0x28, 0x1B},
    {0x28, 0x1C}, {0x28, 0x1D}, {0x28, 0x1E}, {0x28, 0x1F}, {0x39, 0x14},
    {0x39, 0x15}, {0x39, 0x16}, {0x39, 0x17}, {0x39, 0x18}, {0x39, 0x19},
    {0x39, 0x1A}, {0x39, 0x1B}};

char *mcm_strings[] = {"move view",
                       "stan view",
                       "bond view",
                       "level",
                       "region",
                       "scale",
                       "play title",
                       "bond die",
                       "select anim",
                       "gun pos",
                       "flash colour",
                       "hit colour",
                       "music",
                       "sfx",
                       "invincible",
                       "visible",
                       "collisions",
                       "all guns",
                       "max ammo",
                       "display speed",
                       "background",
                       "props",
                       "stan hit",
                       "stan region",
                       "stan problems",
                       "print man pos",
                       "port close",
                       "port inf",
                       "port approx",
                       "pr room loads",
                       "show mem use",
                       "show mem bars",
                       "grab rgb",
                       "grab jpeg",
                       "grab task",
                       "rnd walk",
                       "record ramrom",
                       "record 1",
                       "record 2",
                       "record 3",
                       "replay ramrom",
                       "save ramrom",
                       "load ramrom",
                       "auto y aim",
                       "auto x aim",
                       "007",
                       "agent",
                       "all",
                       "fast",
                       "objectives",
                       "marg top",
                       "marg bot",
                       "marg left",
                       "marg right",
                       "marg reset",
                       "screen size",
                       "screen pos",
                       "show patrols",
                       "intro",
                       "intro edit",
                       "intro pos",
                       "world pos",
                       "gun key pos",
                       "vis cvg",
                       "chr num",
                       "room blocks",
                       "profile",
                       "obj load",
                       "weapon load",
                       "joy2 sky edit",
                       "joy2 hits edit",
                       "joy2 detail edit",
                       "explosion info",
                       "magic fog",
                       "gun watch pos",
                       "testing man pos",
                       "fog"};

int debug_render_raster = 2;
int debug_freeze_processing = 2;
int debug_limit_controller_input = 2;
int debug_unknown = 2;
int memusage_display_flag = false;
int debug_do_draw_bg = true;
int debug_do_draw_obj = true;
int debug_unknown2 = 1;
int debug_stanhit_flag = false;
int debug_stanregion_flag = false;
int turbo_mode_flag = false;
int debug_man_pos_flag = 0;
int debug_prroomloads_flag = 0;
int debug_joy2skyedit_flag = 0;
int debug_joy2hitsedit_flag = 0;
int debug_joy2detailedit_flag = 0;
int debug_explosioninfo_flag = 0;
int debug_VisCVG_flag = 0;
int debug_007_unlock_flag = 0;
int debug_enable_agent_levels_flag = 0;
int debug_enable_all_levels_flag = 0;
int debug_chrnum_flag = 0;
int debug_gunwatchpos_flags = 0;
int debug_profile_flag = 0;
int debug_enable_taskgrab_flag = 0;
int debug_testingmanpos_flag = 0;
int debug_fast_bond_flag = 0;
int debug_all_obj_complete_flag = 0;
int debug_portal_flag = 0;

unsigned int dword_D_80036FD8[] = {0x80500000, 0x40000, 0x7F000000, 0x7F100000};

unsigned int dword_D_80036FE8[] = {0x80600000, 0x40000, 0x70000000, 0x70100000};

int show_debug_menu_flag = 0;
int grab_rgb_screenshot_flag = 0;
int grab_jpeg_screenshot_flag = 0;
int player_pos_x = 0, player_pos_y = 0, player_pos_z = 0;

void display_debug_menu_text_onscreen(void) {
  init_debug_menu_values((char *)mcm_strings, mcm_onscreen_positions,
                         mcm_column_groupings);
}

asm(R"
glabel sub_GAME_7F0904C4
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F0916F4
   nop   
  jal   get_highlighted_debug_option
   nop   
  lw    $ra, 0x14($sp)
  lui   $v1, %hi(debug_unknown)
  lui   $a0, %hi(debug_freeze_processing)
  addiu $a0, %lo(debug_freeze_processing) # addiu $a0, $a0, 0x6f68
  addiu $v1, %lo(debug_unknown) # addiu $v1, $v1, 0x6f70
  sw    $v0, ($v1)
  sw    $v0, ($a0)
  lui   $at, %hi(debug_render_raster)
  sw    $v0, %lo(debug_render_raster)($at)
  jr    $ra
   addiu $sp, $sp, 0x18
");

asm(R"
glabel sub_GAME_7F090508
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   maybe_solo_intro_camera_handler
   nop   
  jal   get_highlighted_debug_option
   nop   
  lw    $ra, 0x14($sp)
  lui   $v1, %hi(debug_unknown)
  lui   $a0, %hi(debug_freeze_processing)
  addiu $a0, %lo(debug_freeze_processing) # addiu $a0, $a0, 0x6f68
  addiu $v1, %lo(debug_unknown) # addiu $v1, $v1, 0x6f70
  sw    $v0, ($v1)
  sw    $v0, ($a0)
  lui   $at, %hi(debug_render_raster)
  sw    $v0, %lo(debug_render_raster)($at)
  jr    $ra
   addiu $sp, $sp, 0x18
");

asm(R"
glabel sub_GAME_7F09054C
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   maybe_solo_intro_camera_handler
   nop   
  jal   get_highlighted_debug_option
   nop   
  lw    $ra, 0x14($sp)
  lui   $v1, %hi(debug_unknown)
  lui   $a0, %hi(debug_freeze_processing)
  addiu $a0, %lo(debug_freeze_processing) # addiu $a0, $a0, 0x6f68
  addiu $v1, %lo(debug_unknown) # addiu $v1, $v1, 0x6f70
  sw    $v0, ($v1)
  sw    $v0, ($a0)
  lui   $at, %hi(debug_render_raster)
  sw    $v0, %lo(debug_render_raster)($at)
  jr    $ra
   addiu $sp, $sp, 0x18
");

void removed_do_debug_profile_flag_false(void) {}

void removed_do_debug_profile_flag_true(void) {}

asm(R"
.late_rodata
glabel jpt_debug_menu_options
.word debug_stanview
.word debug_bondview
.word .L7F090798
.word debug_level
.word .L7F0907BC
.word debug_scale
.word debug_playtitle
.word debug_bonddie
.word debug_selectanim
.word debug_gunpos
.word debug_flashcolor
.word debug_hitcolor
.word debug_music
.word debug_sfx
.word debug_invincible
.word debug_visible
.word debug_collisions
.word debug_allguns
.word debug_maxammo
.word debug_displayspeed
.word debug_dodrawbg
.word debug_dodrawobj
.word debug_stanhit
.word debug_stanregion
.word debug_turbo
.word debug_printmanpos
.word portal_close_inf_approx
.word portal_close_inf_approx
.word portal_close_inf_approx
.word debug_prroomloads
.word debug_showmemuse
.word debug_showmembars
.word debug_grabrgb
.word debug_grabjpeg
.word debug_taskgrab
.word def_7F090770
.word debug_recordramrom
.word debug_ramrom_record1
.word debug_ramrom_record2
.word debug_ramrom_record3
.word debug_replayramrom
.word debug_saveramrom
.word debug_loadramrom
.word debug_autoyaim
.word debug_autoxaim
.word debug_007
.word debug_agent
.word debug_all
.word fast_bond_debug
.word debug_objectives
.word def_7F090770
.word def_7F090770
.word def_7F090770
.word def_7F090770
.word def_7F090770
.word .L7F090834
.word debug_screenpos
.word debug_showpatrols
.word debug_intro
.word debug_introedit
.word debug_intropos
.word debug_worldpos
.word debug_chrkeypos
.word debug_viscvg
.word debug_chrnum
.word debug_roomblocks
.word debug_profile
.word debug_objload
.word debug_weaponload
.word debug_joy2skyedit
.word debug_joy2hitsedit
.word debug_joy2detailedit
.word debug_explosioninfo
.word debug_magicfog
.word debug_gunwatchpos
.word debug_testingmanpos
.word debug_fog

glabel jpt_80055830
.word def_7F090EA8
.word def_7F090EA8
.word def_7F090EA8
.word def_7F090EA8
.word def_7F090EA8

.text
glabel debug_menu_processor
  addiu $sp, $sp, -0x60
  lui   $v1, %hi(grab_rgb_screenshot_flag)
  lw    $v1, %lo(grab_rgb_screenshot_flag)($v1)
  sw    $ra, 0x14($sp)
  sw    $a0, 0x60($sp)
  sw    $a1, 0x64($sp)
  sw    $a2, 0x68($sp)
  beqz  $v1, .L7F0905F4
   sw    $a3, 0x6c($sp)
  xori  $v0, $v1, 3
  addiu $v1, $v1, 1
  lui   $at, %hi(grab_rgb_screenshot_flag)
  bnez  $v0, .L7F0905F4
   sw    $v1, %lo(grab_rgb_screenshot_flag)($at)
  jal   indy_grab_rgb_32bit
   nop   
  lui   $at, %hi(grab_rgb_screenshot_flag)
  jal   set_coloroutputmode_16bit
   sw    $zero, %lo(grab_rgb_screenshot_flag)($at)
  jal   osViBlack
   move  $a0, $zero
.L7F0905F4:
  lui   $v1, %hi(grab_jpeg_screenshot_flag)
  lw    $v1, %lo(grab_jpeg_screenshot_flag)($v1)
  lui   $at, %hi(grab_jpeg_screenshot_flag)
  beqz  $v1, .L7F090630
   xori  $v0, $v1, 3
  addiu $v1, $v1, 1
  bnez  $v0, .L7F090630
   sw    $v1, %lo(grab_jpeg_screenshot_flag)($at)
  jal   indy_grab_jpg_32bit
   nop   
  lui   $at, %hi(grab_jpeg_screenshot_flag)
  jal   set_coloroutputmode_16bit
   sw    $zero, %lo(grab_jpeg_screenshot_flag)($at)
  jal   osViBlack
   move  $a0, $zero
.L7F090630:
  lui   $t6, %hi(show_debug_menu_flag) 
  lw    $t6, %lo(show_debug_menu_flag)($t6)
  lui   $a0, %hi(debug_limit_controller_input)
  lui   $at, %hi(show_debug_menu_flag)
  bnez  $t6, .L7F090684
   addiu $a0, %lo(debug_limit_controller_input) # addiu $a0, $a0, 0x6f6c
  lhu   $a0, 0x6a($sp)
  andi  $v1, $a0, 8
  sltu  $v0, $zero, $v1
  beqz  $v0, .L7F090668
   nop   
  andi  $v0, $a0, 4
  sltu  $t8, $zero, $v0
  move  $v0, $t8
.L7F090668:
  beqz  $v0, .L7F090678
   sw    $v0, %lo(show_debug_menu_flag)($at)
  jal   stop_recording_ramrom
   nop   
.L7F090678:
  lui   $v0, %hi(show_debug_menu_flag)
  b     .L7F090EEC
   lw    $v0, %lo(show_debug_menu_flag)($v0)
.L7F090684:
  lw    $v0, ($a0)
  li    $v1, -2
  lui   $at, %hi(debug_unknown)
  beql  $v1, $v0, .L7F0906A4
   lhu   $t9, 0x6e($sp)
  sw    $v0, %lo(debug_unknown)($at)
  sw    $v1, ($a0)
  lhu   $t9, 0x6e($sp)
.L7F0906A4:
  andi  $t0, $t9, 0x200
  beqz  $t0, .L7F0906C8
   sw    $t9, 0x18($sp)
  jal   sub_GAME_7F09039C
   nop   
  lui   $a0, %hi(debug_limit_controller_input)
  addiu $a0, %lo(debug_limit_controller_input) # addiu $a0, $a0, 0x6f6c
  li    $v1, -2
  sw    $v1, ($a0)
.L7F0906C8:
  lw    $t1, 0x18($sp)
  andi  $t2, $t1, 0x100
  beql  $t2, $zero, .L7F0906F4
   lw    $t3, 0x18($sp)
  jal   sub_GAME_7F0902C0
   nop   
  lui   $a0, %hi(debug_limit_controller_input)
  addiu $a0, %lo(debug_limit_controller_input) # addiu $a0, $a0, 0x6f6c
  li    $v1, -2
  sw    $v1, ($a0)
  lw    $t3, 0x18($sp)
.L7F0906F4:
  andi  $t4, $t3, 0x800
  beql  $t4, $zero, .L7F09071C
   lw    $t5, 0x18($sp)
  jal   sub_GAME_7F0901C8
   nop   
  lui   $a0, %hi(debug_limit_controller_input)
  addiu $a0, %lo(debug_limit_controller_input) # addiu $a0, $a0, 0x6f6c
  li    $v1, -2
  sw    $v1, ($a0)
  lw    $t5, 0x18($sp)
.L7F09071C:
  andi  $t6, $t5, 0x400
  beql  $t6, $zero, .L7F090744
   lw    $t7, 0x18($sp)
  jal   sub_GAME_7F090248
   nop   
  lui   $a0, %hi(debug_limit_controller_input)
  addiu $a0, %lo(debug_limit_controller_input) # addiu $a0, $a0, 0x6f6c
  li    $v1, -2
  sw    $v1, ($a0)
  lw    $t7, 0x18($sp)
.L7F090744:
  andi  $t8, $t7, 0x9000
  beql  $t8, $zero, .L7F090E78
   lw    $t8, 0x18($sp)
  jal   get_highlighted_debug_option
   nop   
  sltiu $at, $v0, 0x4d
  beqz  $at, .L7F090E74
   sll   $t9, $v0, 2
  lui   $at, %hi(jpt_debug_menu_options)
  addu  $at, $at, $t9
  lw    $t9, %lo(jpt_debug_menu_options)($at)
  jr    $t9
   nop   
debug_stanview:
  jal   sub_GAME_7F0904C4
   nop   
  b     .L7F090E78
   lw    $t8, 0x18($sp)
debug_bondview:
  jal   sub_GAME_7F090508
   nop   
  b     .L7F090E78
   lw    $t8, 0x18($sp)
.L7F090798:
  jal   sub_GAME_7F09054C
   nop   
  b     .L7F090E78
   lw    $t8, 0x18($sp)
debug_level:
  jal   get_highlighted_debug_option
   nop   
  lui   $at, %hi(debug_unknown)
  b     .L7F090E74
   sw    $v0, %lo(debug_unknown)($at)
.L7F0907BC:
  jal   get_highlighted_debug_option
   nop   
  lui   $at, %hi(debug_unknown)
  b     .L7F090E74
   sw    $v0, %lo(debug_unknown)($at)
debug_scale:
  jal   get_highlighted_debug_option
   nop   
  lui   $at, %hi(debug_unknown)
  b     .L7F090E74
   sw    $v0, %lo(debug_unknown)($at)
debug_selectanim:
  jal   get_highlighted_debug_option
   nop   
  lui   $at, %hi(debug_unknown)
  b     .L7F090E74
   sw    $v0, %lo(debug_unknown)($at)
debug_gunpos:
  jal   get_highlighted_debug_option
   nop   
  lui   $at, %hi(debug_unknown)
  b     .L7F090E74
   sw    $v0, %lo(debug_unknown)($at)
debug_flashcolor:
  jal   get_highlighted_debug_option
   nop   
  lui   $at, %hi(debug_unknown)
  b     .L7F090E74
   sw    $v0, %lo(debug_unknown)($at)
debug_hitcolor:
  jal   get_highlighted_debug_option
   nop   
  lui   $at, %hi(debug_unknown)
  b     .L7F090E74
   sw    $v0, %lo(debug_unknown)($at)
.L7F090834:
  jal   get_highlighted_debug_option
   nop   
  lui   $at, %hi(debug_unknown)
  b     .L7F090E74
   sw    $v0, %lo(debug_unknown)($at)
debug_screenpos:
  jal   get_highlighted_debug_option
   nop   
  lui   $at, %hi(debug_unknown)
  b     .L7F090E74
   sw    $v0, %lo(debug_unknown)($at)
debug_music:
  jal   get_highlighted_debug_option
   nop   
  lui   $at, %hi(debug_unknown)
  b     .L7F090E74
   sw    $v0, %lo(debug_unknown)($at)
portal_close_inf_approx:
  lui   $v0, %hi(debug_portal_flag)
  addiu $v0, %lo(debug_portal_flag) # addiu $v0, $v0, 0x6fd4
  lw    $t0, ($v0)
  xori  $t1, $t0, 1
  b     .L7F090E74
   sw    $t1, ($v0)
debug_sfx:
  jal   get_highlighted_debug_option
   nop   
  lui   $at, %hi(debug_unknown)
  b     .L7F090E74
   sw    $v0, %lo(debug_unknown)($at)
debug_invincible:
  jal   get_bondata_invincible_flag
   nop   
  jal   set_bondata_invincible_flag
   sltiu $a0, $v0, 1
  b     .L7F090E78
   lw    $t8, 0x18($sp)
debug_visible:
  jal   get_invisible_to_guards_flag
   nop   
  jal   set_invisible_to_guards_flag
   sltiu $a0, $v0, 1
  b     .L7F090E78
   lw    $t8, 0x18($sp)
debug_collisions:
  jal   get_obj_collision_flag
   nop   
  jal   set_obj_collision_flag
   sltiu $a0, $v0, 1
  b     .L7F090E78
   lw    $t8, 0x18($sp)
debug_allguns:
  jal   getPlayerCount
   sw    $zero, 0x5c($sp)
  blezl $v0, .L7F090E78
   lw    $t8, 0x18($sp)
.L7F0908F4:
  jal   set_cur_player
   lw    $a0, 0x5c($sp)
  jal   get_BONDdata_allguns_flag
   nop   
  jal   set_BONDdata_allguns_flag
   sltiu $a0, $v0, 1
  lw    $t2, 0x5c($sp)
  addiu $t3, $t2, 1
  jal   getPlayerCount
   sw    $t3, 0x5c($sp)
  lw    $t4, 0x5c($sp)
  slt   $at, $t4, $v0
  bnez  $at, .L7F0908F4
   nop   
  b     .L7F090E78
   lw    $t8, 0x18($sp)
debug_maxammo:
  jal   get_cur_playernum
   nop   
  sw    $v0, 0x54($sp)
  jal   getPlayerCount
   sw    $zero, 0x58($sp)
  blez  $v0, .L7F090980
   nop   
.L7F090950:
  jal   set_cur_player
   lw    $a0, 0x58($sp)
  jal   set_max_ammo_for_cur_player
   nop   
  lw    $t5, 0x58($sp)
  addiu $t6, $t5, 1
  jal   getPlayerCount
   sw    $t6, 0x58($sp)
  lw    $t7, 0x58($sp)
  slt   $at, $t7, $v0
  bnez  $at, .L7F090950
   nop   
.L7F090980:
  jal   set_cur_player
   lw    $a0, 0x54($sp)
  b     .L7F090E78
   lw    $t8, 0x18($sp)
debug_displayspeed:
  lui   $v0, %hi(memusage_display_flag)
  addiu $v0, %lo(memusage_display_flag) # addiu $v0, $v0, 0x6f74
  lw    $t8, ($v0)
  xori  $t9, $t8, 1
  bnez  $t9, .L7F090E74
   sw    $t9, ($v0)
  jal   blank_debug_buffer_chars
   nop   
  b     .L7F090E78
   lw    $t8, 0x18($sp)
debug_dodrawbg:
  lui   $v0, %hi(debug_do_draw_bg)
  addiu $v0, %lo(debug_do_draw_bg) # addiu $v0, $v0, 0x6f78
  lw    $t1, ($v0)
  xori  $t2, $t1, 1
  b     .L7F090E74
   sw    $t2, ($v0)
debug_dodrawobj:
  lui   $v0, %hi(debug_do_draw_obj)
  addiu $v0, %lo(debug_do_draw_obj) # addiu $v0, $v0, 0x6f7c
  lw    $t3, ($v0)
  xori  $t4, $t3, 1
  b     .L7F090E74
   sw    $t4, ($v0)
debug_stanhit:
  lui   $v0, %hi(debug_stanhit_flag)
  addiu $v0, %lo(debug_stanhit_flag) # addiu $v0, $v0, 0x6f84
  lw    $t5, ($v0)
  xori  $t6, $t5, 1
  b     .L7F090E74
   sw    $t6, ($v0)
debug_stanregion:
  lui   $v0, %hi(debug_stanregion_flag)
  addiu $v0, %lo(debug_stanregion_flag) # addiu $v0, $v0, 0x6f88
  lw    $t7, ($v0)
  xori  $t8, $t7, 1
  b     .L7F090E74
   sw    $t8, ($v0)
debug_turbo:
  lui   $v0, %hi(turbo_mode_flag)
  addiu $v0, %lo(turbo_mode_flag) # addiu $v0, $v0, 0x6f8c
  lw    $t9, ($v0)
  xori  $t0, $t9, 1
  b     .L7F090E74
   sw    $t0, ($v0)
debug_printmanpos:
  lui   $v0, %hi(debug_man_pos_flag)
  addiu $v0, %lo(debug_man_pos_flag) # addiu $v0, $v0, 0x6f90
  lw    $t1, ($v0)
  xori  $t2, $t1, 1
  b     .L7F090E74
   sw    $t2, ($v0)
debug_testingmanpos:
  lui   $v0, %hi(debug_testingmanpos_flag)
  addiu $v0, %lo(debug_testingmanpos_flag) # addiu $v0, $v0, 0x6fc8
  lw    $t3, ($v0)
  xori  $t4, $t3, 1
  b     .L7F090E74
   sw    $t4, ($v0)
debug_playtitle:
  jal   set_loaded_stage
   li    $a0, 90
  b     .L7F090E78
   lw    $t8, 0x18($sp)
debug_bonddie:
  jal   kill_current_player
   nop   
  b     .L7F090E78
   lw    $t8, 0x18($sp)
debug_prroomloads:
  lui   $v0, %hi(debug_prroomloads_flag)
  addiu $v0, %lo(debug_prroomloads_flag) # addiu $v0, $v0, 0x6f94
  lw    $t5, ($v0)
  xori  $t6, $t5, 1
  b     .L7F090E74
   sw    $t6, ($v0)
debug_showmemuse:
  jal   enable_show_mem_use_flag
   nop   
  b     .L7F090E78
   lw    $t8, 0x18($sp)
debug_showmembars:
  jal   mem_bars_flag_toggle
   nop   
  b     .L7F090E78
   lw    $t8, 0x18($sp)
debug_grabrgb:
  li    $v1, 1
  lui   $at, %hi(grab_rgb_screenshot_flag)
  sw    $v1, %lo(grab_rgb_screenshot_flag)($at)
  jal   osViBlack
   li    $a0, 1
  jal   set_coloroutputmode_32bit
   nop   
  b     .L7F090E78
   lw    $t8, 0x18($sp)
debug_grabjpeg:
  li    $v1, 1
  lui   $at, %hi(grab_jpeg_screenshot_flag)
  sw    $v1, %lo(grab_jpeg_screenshot_flag)($at)
  jal   osViBlack
   li    $a0, 1
  jal   set_coloroutputmode_32bit
   nop   
  b     .L7F090E78
   lw    $t8, 0x18($sp)
debug_taskgrab:
  lui   $v0, %hi(debug_enable_taskgrab_flag)
  addiu $v0, %lo(debug_enable_taskgrab_flag) # addiu $v0, $v0, 0x6fc4
  lw    $t7, ($v0)
  xori  $t8, $t7, 1
  b     .L7F090E74
   sw    $t8, ($v0)
debug_recordramrom:
  jal   setRamRomRecordSlot
   move  $a0, $zero
  b     .L7F090E78
   lw    $t8, 0x18($sp)
debug_ramrom_record1:
  jal   setRamRomRecordSlot
   li    $a0, 1
  b     .L7F090E78
   lw    $t8, 0x18($sp)
debug_ramrom_record2:
  jal   setRamRomRecordSlot
   li    $a0, 2
  b     .L7F090E78
   lw    $t8, 0x18($sp)
debug_ramrom_record3:
  jal   setRamRomRecordSlot
   li    $a0, 3
  b     .L7F090E78
   lw    $t8, 0x18($sp)
debug_replayramrom:
  jal   replay_recorded_ramrom_from_indy
   nop   
  b     .L7F090E78
   lw    $t8, 0x18($sp)
debug_saveramrom:
  jal   save_ramrom_to_devtool
   nop   
  b     .L7F090E78
   lw    $t8, 0x18($sp)
debug_loadramrom:
  jal   load_ramrom_from_devtool
   nop   
  b     .L7F090E78
   lw    $t8, 0x18($sp)
debug_autoyaim:
  jal   get_BONDdata_autoaim_y
   nop   
  jal   set_BONDdata_autoaim_y
   sltiu $a0, $v0, 1
  b     .L7F090E78
   lw    $t8, 0x18($sp)
debug_autoxaim:
  jal   get_BONDdata_autoaim_x
   nop   
  jal   set_BONDdata_autoaim_x
   sltiu $a0, $v0, 1
  b     .L7F090E78
   lw    $t8, 0x18($sp)
debug_007:
  lui   $v0, %hi(debug_007_unlock_flag)
  addiu $v0, %lo(debug_007_unlock_flag) # addiu $v0, $v0, 0x6fac
  lw    $t9, ($v0)
  xori  $t0, $t9, 1
  b     .L7F090E74
   sw    $t0, ($v0)
debug_agent:
  lui   $v0, %hi(debug_enable_agent_levels_flag)
  addiu $v0, %lo(debug_enable_agent_levels_flag) # addiu $v0, $v0, 0x6fb0
  lw    $t1, ($v0)
  xori  $t2, $t1, 1
  b     .L7F090E74
   sw    $t2, ($v0)
debug_all:
  lui   $v0, %hi(debug_enable_all_levels_flag)
  addiu $v0, %lo(debug_enable_all_levels_flag) # addiu $v0, $v0, 0x6fb4
  lw    $t3, ($v0)
  xori  $t4, $t3, 1
  b     .L7F090E74
   sw    $t4, ($v0)
fast_bond_debug:
  lui   $v0, %hi(debug_fast_bond_flag)
  addiu $v0, %lo(debug_fast_bond_flag) # addiu $v0, $v0, 0x6fcc
  lw    $t5, ($v0)
  xori  $t6, $t5, 1
  b     .L7F090E74
   sw    $t6, ($v0)
debug_objectives:
  lui   $v0, %hi(debug_all_obj_complete_flag)
  addiu $v0, %lo(debug_all_obj_complete_flag) # addiu $v0, $v0, 0x6fd0
  lw    $t7, ($v0)
  xori  $t8, $t7, 1
  b     .L7F090E74
   sw    $t8, ($v0)
debug_showpatrols:
  jal   get_show_patrols_flag
   nop   
  jal   set_show_patrols_flag
   sltiu $a0, $v0, 1
  b     .L7F090E78
   lw    $t8, 0x18($sp)
debug_intro:
  jal   set_camera_mode
   li    $a0, 3
  b     .L7F090E78
   lw    $t8, 0x18($sp)
debug_intropos:
  lui   $t9, %hi(debug_render_raster) 
  lw    $t9, %lo(debug_render_raster)($t9)
  bnezl $t9, .L7F090E78
   lw    $t8, 0x18($sp)
  jal   sub_GAME_7F091618
   nop   
  b     .L7F090E78
   lw    $t8, 0x18($sp)
debug_worldpos:
  lui   $t0, %hi(debug_render_raster) 
  lw    $t0, %lo(debug_render_raster)($t0)
  bnez  $t0, .L7F090C98
   nop   
  jal   sub_GAME_7F09166C
   nop   
  b     .L7F090E78
   lw    $t8, 0x18($sp)
.L7F090C98:
  jal   get_curplayer_positiondata
   nop   
  beqz  $v0, .L7F090E74
   move  $v1, $v0
  lui   $v0, %hi(player_pos_x)
  addiu $v0, %lo(player_pos_x) # addiu $v0, $v0, 0x7004
  lwc1  $f6, ($v0)
  lwc1  $f4, 8($v1)
  lwc1  $f10, 4($v0)
  lwc1  $f8, 0xc($v1)
  sub.s $f0, $f4, $f6
  lwc1  $f18, 8($v0)
  lwc1  $f16, 0x10($v1)
  sub.s $f2, $f8, $f10
  mul.s $f4, $f0, $f0
  sw    $v1, 0x50($sp)
  sub.s $f14, $f16, $f18
  mul.s $f6, $f2, $f2
  add.s $f8, $f4, $f6
  mul.s $f10, $f14, $f14
  jal   sqrtf
   add.s $f12, $f8, $f10
  lw    $v1, 0x50($sp)
  lui   $v0, %hi(player_pos_x)
  addiu $v0, %lo(player_pos_x) # addiu $v0, $v0, 0x7004
  lwc1  $f16, 8($v1)
  swc1  $f16, ($v0)
  lwc1  $f18, 0xc($v1)
  swc1  $f18, 4($v0)
  lwc1  $f4, 0x10($v1)
  b     .L7F090E74
   swc1  $f4, 8($v0)
debug_chrkeypos:
  jal   get_highlighted_debug_option
   nop   
  lui   $at, %hi(debug_unknown)
  b     .L7F090E74
   sw    $v0, %lo(debug_unknown)($at)
debug_chrnum:
  lui   $v0, %hi(debug_chrnum_flag)
  addiu $v0, %lo(debug_chrnum_flag) # addiu $v0, $v0, 0x6fb8
  lw    $t1, ($v0)
  xori  $t2, $t1, 1
  b     .L7F090E74
   sw    $t2, ($v0)
debug_viscvg:
  lui   $v0, %hi(debug_VisCVG_flag)
  addiu $v0, %lo(debug_VisCVG_flag) # addiu $v0, $v0, 0x6fa8
  lw    $t3, ($v0)
  xori  $t4, $t3, 1
  b     .L7F090E74
   sw    $t4, ($v0)
debug_joy2skyedit:
  lui   $v0, %hi(debug_joy2skyedit_flag)
  addiu $v0, %lo(debug_joy2skyedit_flag) # addiu $v0, $v0, 0x6f98
  lw    $t5, ($v0)
  xori  $t6, $t5, 1
  b     .L7F090E74
   sw    $t6, ($v0)
debug_joy2hitsedit:
  lui   $v0, %hi(debug_joy2hitsedit_flag)
  addiu $v0, %lo(debug_joy2hitsedit_flag) # addiu $v0, $v0, 0x6f9c
  lw    $t7, ($v0)
  xori  $t8, $t7, 1
  b     .L7F090E74
   sw    $t8, ($v0)
debug_joy2detailedit:
  lui   $v0, %hi(debug_joy2detailedit_flag)
  addiu $v0, %lo(debug_joy2detailedit_flag) # addiu $v0, $v0, 0x6fa0
  lw    $t9, ($v0)
  xori  $t0, $t9, 1
  b     .L7F090E74
   sw    $t0, ($v0)
debug_explosioninfo:
  lui   $v0, %hi(debug_explosioninfo_flag)
  addiu $v0, %lo(debug_explosioninfo_flag) # addiu $v0, $v0, 0x6fa4
  lw    $t1, ($v0)
  xori  $t2, $t1, 1
  b     .L7F090E74
   sw    $t2, ($v0)
debug_magicfog:
  jal   get_highlighted_debug_option
   nop   
  lui   $at, %hi(debug_unknown)
  b     .L7F090E74
   sw    $v0, %lo(debug_unknown)($at)
debug_fog:
  jal   get_highlighted_debug_option
   nop   
  lui   $at, %hi(debug_unknown)
  b     .L7F090E74
   sw    $v0, %lo(debug_unknown)($at)
debug_gunwatchpos:
  lui   $v0, %hi(debug_gunwatchpos_flags)
  addiu $v0, %lo(debug_gunwatchpos_flags) # addiu $v0, $v0, 0x6fbc
  lw    $t3, ($v0)
  xori  $t4, $t3, 1
  b     .L7F090E74
   sw    $t4, ($v0)
debug_roomblocks:
  jal   removed_debug_roomblocks_feature
   nop   
  b     .L7F090E78
   lw    $t8, 0x18($sp)
debug_profile:
  lui   $v0, %hi(debug_profile_flag)
  addiu $v0, %lo(debug_profile_flag) # addiu $v0, $v0, 0x6fc0
  lw    $t5, ($v0)
  xori  $t6, $t5, 1
  beqz  $t6, .L7F090E34
   sw    $t6, ($v0)
  jal   removed_do_debug_profile_flag_false
   nop   
  b     .L7F090E78
   lw    $t8, 0x18($sp)
.L7F090E34:
  jal   removed_do_debug_profile_flag_true
   nop   
  b     .L7F090E78
   lw    $t8, 0x18($sp)
debug_objload:
  jal   debug_object_load_all_models
   nop   
  b     .L7F090E78
   lw    $t8, 0x18($sp)
debug_weaponload:
  jal   debug_weapon_load_table
   nop   
  b     .L7F090E78
   lw    $t8, 0x18($sp)
debug_introedit:
  jal   get_highlighted_debug_option
   nop   
  lui   $at, %hi(debug_unknown)
  sw    $v0, %lo(debug_unknown)($at)
def_7F090770:
.L7F090E74:
  lw    $t8, 0x18($sp)
.L7F090E78:
  andi  $t9, $t8, 3
  beql  $t9, $zero, .L7F090EB4
   lw    $t1, 0x18($sp)
  jal   get_highlighted_debug_option
   nop   
  addiu $t0, $v0, -0x32
  sltiu $at, $t0, 5
  beqz  $at, .L7F090EB0
   sll   $t0, $t0, 2
  lui   $at, %hi(jpt_80055830)
  addu  $at, $at, $t0
  lw    $t0, %lo(jpt_80055830)($at)
  jr    $t0
   nop   
def_7F090EA8:
.L7F090EB0:
  lw    $t1, 0x18($sp)
.L7F090EB4:
  lui   $t3, %hi(show_debug_menu_flag) 
  andi  $t2, $t1, 0x1000
  beqz  $t2, .L7F090EE4
   nop   
  lw    $t3, %lo(show_debug_menu_flag)($t3)
  li    $at, 1
  bne   $t3, $at, .L7F090EDC
   nop   
  jal   blank_debug_buffer_chars
   nop   
.L7F090EDC:
  lui   $at, %hi(show_debug_menu_flag)
  sw    $zero, %lo(show_debug_menu_flag)($at)
.L7F090EE4:
  lui   $v0, %hi(show_debug_menu_flag)
  lw    $v0, %lo(show_debug_menu_flag)($v0)
.L7F090EEC:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x60
  jr    $ra
   nop   
");

int get_debug_render_raster(void) { return debug_render_raster; }

int get_debug_freeze_processing(void) { return debug_freeze_processing; }

int get_debug_limit_controller_input(void) {
  return debug_limit_controller_input;
}

void set_debug_limit_controller_input(void) {
  debug_limit_controller_input = debug_unknown;
}

int get_memusage_display_flag(void) { return memusage_display_flag; }

int get_debug_do_draw_bg(void) { return debug_do_draw_bg; }

int get_debug_do_draw_obj(void) { return debug_do_draw_obj; }

int get_debug_stanhit_flag(void) { return debug_stanhit_flag; }

int get_debug_stanregion_flag(void) { return debug_stanregion_flag; }

int get_turbo_mode_flag(void) { return turbo_mode_flag; }

int get_debug_man_pos_flag(void) { return debug_man_pos_flag; }

int get_debug_testingmanpos_flag(void) { return debug_testingmanpos_flag; }

void set_debug_testingmanpos_flag(int flag) { debug_testingmanpos_flag = flag; }

int get_debug_joy2skyedit_flag(void) { return debug_joy2skyedit_flag; }

int get_debug_joy2hitsedit_flag(void) { return debug_joy2hitsedit_flag; }

int get_debug_joy2detailedit_flag(void) { return debug_joy2detailedit_flag; }

int get_debug_explosioninfo_flag(void) { return debug_explosioninfo_flag; }

int get_debug_prroomloads_flag(void) { return debug_prroomloads_flag; }

// Get Current Status of VisCVG (True/False)
int get_debug_VisCVG_flag(void) { return debug_VisCVG_flag; }

// Set VisCVG (True/False)
void set_debug_VisCVG_flag(int flag) { debug_VisCVG_flag = flag; }

int get_debug_007_unlock_flag(void) { return debug_007_unlock_flag; }

int get_debug_enable_agent_levels_flag(void) {
  return debug_enable_agent_levels_flag;
}

int get_debug_enable_all_levels_flag(void) {
  return debug_enable_all_levels_flag;
}

int get_debug_fast_bond_flag(void) { return debug_fast_bond_flag; }

void set_debug_fast_bond_flag(int flag) { debug_fast_bond_flag = flag; }

int get_debug_all_obj_complete_flag(void) {
  return debug_all_obj_complete_flag;
}

int get_debug_portal_flag(void) { return debug_portal_flag; }

int get_debug_chrnum_flag(void) { return debug_chrnum_flag; }

int get_debug_gunwatchpos_flag(void) { return debug_gunwatchpos_flags; }

int get_debug_profile_flag(void) { return debug_profile_flag; }

int get_debug_taskgrab_val(void) { return debug_enable_taskgrab_flag; }
