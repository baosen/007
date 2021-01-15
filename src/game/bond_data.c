#include "chr.h"
#include <stddef.h>

float flt_CODE_bss_80079940;
float flt_CODE_bss_80079944;
float flt_CODE_bss_80079948;
float flt_CODE_bss_8007994C;
float flt_CODE_bss_80079950;
float flt_CODE_bss_80079954;
float flt_CODE_bss_80079958;
float flt_CODE_bss_8007995C;
float flt_CODE_bss_80079960;
float flt_CODE_bss_80079964;
float flt_CODE_bss_80079968;
float flt_CODE_bss_8007996C;
float flt_CODE_bss_80079970;
float flt_CODE_bss_80079974;
float flt_CODE_bss_80079978;
float flt_CODE_bss_8007997C;
float flt_CODE_bss_80079980;
float flt_CODE_bss_80079984;
float flt_CODE_bss_80079988;
float flt_CODE_bss_8007998C;
float flt_CODE_bss_80079990;
float flt_CODE_bss_80079994;
float flt_CODE_bss_80079998;
int dword_CODE_bss_8007999C;
int dword_CODE_bss_800799A0;
int dword_CODE_bss_800799A4;
float flt_CODE_bss_800799A8;
float flt_CODE_bss_800799AC;
float flt_CODE_bss_800799B0;
int dword_CODE_bss_800799B4;
int dword_CODE_bss_800799B8;
float flt_CODE_bss_800799BC;
float flt_CODE_bss_800799C0;
float flt_CODE_bss_800799C4;
float flt_CODE_bss_800799C8;
float flt_CODE_bss_800799CC;
float flt_CODE_bss_800799D0;
float flt_CODE_bss_800799D4;
float flt_CODE_bss_800799D8;
float flt_CODE_bss_800799DC;
int starting_right_weapon, starting_left_weapon;
float flt_CODE_bss_800799E8;
float flt_CODE_bss_800799EC;
float flt_CODE_bss_800799F0;
int dword_CODE_bss_800799F4;
int dword_CODE_bss_800799F8;
int dword_CODE_bss_800799FC;
float flt_CODE_bss_80079A00;
float flt_CODE_bss_80079A04;
float flt_CODE_bss_80079A08;
float flt_CODE_bss_80079A0C;
float flt_CODE_bss_80079A10;
int dword_CODE_bss_80079A14;
int dword_CODE_bss_80079A18;
int dword_CODE_bss_80079A1C;
int mission_timer;
float watch_time_0;
char dword_CODE_bss_80079A28[0x200];

#ifdef VERSION_JP
char dword_CODE_bss_jp80079Cd8[0x30];
#endif

char dword_CODE_bss_80079C28[0x40];
int dword_CODE_bss_80079C68;
int dword_CODE_bss_80079C6C;
char dword_CODE_bss_80079C70[0x130];
int dword_CODE_bss_80079DA0;
int dword_CODE_bss_80079DA4;
char dword_CODE_bss_80079DA8[0x20];
char dword_CODE_bss_80079DC8[0x3C];
int flt_CODE_bss_80079E04;
int flt_CODE_bss_80079E08;
int flt_CODE_bss_80079E0C;
int flt_CODE_bss_80079E10;

int D_80036420 = 0;
int camera_80036424 = 0;
int resolution = 0;
int camera_8003642C = 0;
int camera_80036430 = 0;
int camera_80036434 = 0;
int camera_80036438 = 0;
int D_8003643C = 0;
int D_80036440 = 0;
int D_80036444 = 0;
int in_tank_flag = 0;
int D_8003644C = 0;
int ptr_playerstank = 0;
int D_80036454 = 0;
int SFX_80036458 = 0;
int SFX_8003645C = 0;
int D_80036460 = 0;
int D_80036464 = 0;
int D_80036468 = 0;
int D_8003646C = 0;
int D_80036470 = 0;
int D_80036474 = 0;
int D_80036478 = 0;
int D_8003647C = 0;
int D_80036480 = 0;
int D_80036484 = 0;
int D_80036488 = 0;
int D_8003648C = 0;
int D_80036490 = 0;
int cameramode = 0;
int enable_move_after_cinema = 0;
int D_8003649C = 0;
int stop_time_flag = 0;
int D_800364A4 = 0;
int D_800364A8 = 1;
int D_800364AC = 0;
int D_800364B0 = 1;
int disable_player_pickups_flag = 0;
int D_800364B8 = 0;
int D_800364BC = 0;
int ptr_random06cam_entry = 0;
int invisible_to_guards_flag = 1;
int obj_collision_flag = 1;
float D_800364CC = 1.0;
float D_800364D0 = 1.0;
float D_800364D4 = 1.0;
int D_800364D8[] = {0x30B8, 0x31DC, 0x32C8, 0x33AC, 0x34D4, 0x35C8, 0x36D8,
                    0x384C, 0x39C0, 0x3AF0, 0x3C10, 0x3D04, 0};

int D_8003650C = 0;
int D_80036510 = 0;
int D_80036514 = 0;

struct {
  int anonymous_0;
  float anonymous_1, anonymous_2, anonymous_3;
} stage_intro_anim_table[] = {
    {0x5744, 95.0, -1.0, 0.02}, {0x6254, 7.0, 40.0, 0.5},
    {0x78C8, 0.0, -1.0, 0.5},   {0x7AA8, 0.0, -1.0, 0.5},
    {0x7C4C, 0.0, -1.0, 0.5},   {0x7D04, 0.0, -1.0, 0.5},
    {0x7F0C, 0.0, -1.0, 0.5},   {0x7FB4, 0.0, -1.0, 0.5},
    {0xD89C, 0.0, -1.0, 0.5}};

float watch_transition_time = 0.90909088;

unsigned int dummy_08_pp7_obj[] = {
    0x01000008, 0x00bf4000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x3f800000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3f800000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3f800000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x3f800000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x447a0000,
    0xffffff00, 0xffffff00, 0x04ffffff};
unsigned int D_80036630 = 0;

#ifdef VERSION_US
unsigned int D_80036634[] = {
    0x0, 0xA, 0x3C, 0x3F19999A, 0x0, 0x5, 0x28, 0x3F800000, 0xFF, 0xFF, 0xFF,
    0x0, 0xA, 0x3C, 0x3F19999A, 0x0, 0x5, 0x28, 0x3F800000, 0xFF, 0xFF, 0xFF,
    0x0, 0xA, 0x32, 0x3F19999A, 0x0, 0x5, 0x1E, 0x3F4CCCCD, 0xFF, 0xFF, 0xFF,
    0x0, 0xA, 0x28, 0x3F19999A, 0x0, 0x5, 0x19, 0x3F19999A, 0xFF, 0xFF, 0xFF,
    0x0, 0xA, 0x23, 0x3F19999A, 0x0, 0x5, 0x16, 0x3F0CCCCD, 0xFF, 0xFF, 0xFF,
    0x0, 0xA, 0x1E, 0x3F19999A, 0x0, 0x5, 0x13, 0x3F000000, 0xFF, 0xFF, 0xFF,
    0x0, 0xA, 0x1E, 0x3F19999A, 0x0, 0x5, 0x11, 0x3EE66666, 0xFF, 0xFF, 0xFF,
    0x0, 0xA, 0x1E, 0x3F19999A, 0x0, 0x5, 0xF,  0x3ECCCCCD, 0xFF, 0xFF, 0xFF};
#endif

#ifdef VERSION_JP
unsigned int D_80036634[] = {
    0x0,        0x41200000, 0x42700000, 0x3F19999A, 0x0,        0x40A00000,
    0x42200000, 0x3F800000, 0xFF,       0xFF,       0xFF,       0x0,
    0x41200000, 0x42700000, 0x3F19999A, 0x0,        0x40A00000, 0x42200000,
    0x3F800000, 0xFF,       0xFF,       0xFF,       0x0,        0x41200000,
    0x42480000, 0x3F19999A, 0x0,        0x40A00000, 0x41F00000, 0x3F4CCCCD,
    0xFF,       0xFF,       0xFF,       0x0,        0x41200000, 0x42200000,
    0x3F19999A, 0x0,        0x40A00000, 0x41C80000, 0x3F19999A, 0xFF,
    0xFF,       0xFF,       0x0,        0x41200000, 0x420C0000, 0x3F19999A,
    0x0,        0x40A00000, 0x41B00000, 0x3F0CCCCD, 0xFF,       0xFF,
    0xFF,       0x0,        0x41200000, 0x41F00000, 0x3F19999A, 0x0,
    0x40A00000, 0x41980000, 0x3F000000, 0xFF,       0xFF,       0xFF,
    0x0,        0x41200000, 0x41F00000, 0x3F19999A, 0x0,        0x40A00000,
    0x41880000, 0x3EE66666, 0xFF,       0xFF,       0xFF,       0x0,
    0x41200000, 0x41F00000, 0x3F19999A, 0x0,        0x40A00000, 0x41700000,
    0x3ECCCCCD, 0xFF,       0xFF,       0xFF};
#endif

unsigned int D_80036794 = 0;
unsigned int D_80036798 = 0x00000028;

unsigned int D_8003679C[] = {
    0x00000064, 0x00000000, 0x0000001E, 0x00000050, 0x00000000, 0x00000014,
    0x0000003C, 0x00000000, 0x00000014, 0x0000003C, 0x00000000, 0x00000014,
    0x0000003C, 0x00000000, 0x00000014, 0x00000032, 0x00000000, 0x00000014,
    0x00000032, 0x00000000, 0x00000014, 0x00000032};

int D_800367F4 = 0;
int D_800367F8 = 0;
int D_800367FC = 0;
int D_80036800 = 0;
int D_80036804 = 0;
int D_80036808 = 0;
int D_8003680C = 0;
int D_80036810 = 0;
int D_80036814 = 0x3F800000;
int D_80036818 = 0;
int D_8003681C = 0x3F800000;
int D_80036820 = 0;
int D_80036824 = 0;
int D_80036828 = 0;
int D_8003682C = 0;
int D_80036830 = 0;
int D_80036834 = 0;
int D_80036838 = 0;
int D_8003683C[] = {0, 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int D_80036878 = 0;
int D_8003687C = 0;

int D_80036880 = 0;
int D_80036884 = 0;
int D_80036888 = 0;

int D_8003688C = 0;
int D_80036890 = 0;
int D_80036894 = 0;
int status_bar_text_buffer_index = 0;
int display_statusbar = 0;

#ifndef VERSION_JP
int copy_1stfonttable = 0;
int copy_2ndfonttable = 0;
#endif

int upper_text_buffer_index = 0;
int display_upper_text_window = 0;
int upper_text_window_timer = 0xFFFFFFFF;
int D_800368B4 = 0;
unsigned short D_800368B8[] = {0x6E00, 0x006E, 0x6500, 0x6500, 0x73, 0x6500,
                               0x7300, 0x0073, 0x7700, 0x7700, 0x6E, 0x7700,
                               0x6E00, 0x0000, 0x0000, 0x0000};

struct {
  struct weapon_firing_animation_table *pointer;
  unsigned int anim;
  float x, y, z;
} firing_animation_groups[] = {
    {pistol_firing_animation_group1, 0, 0.1, 79.0, 87.0},
    {&D_800306F0, 0, 0.5, 0.0, -1.0},
    {&D_80030738, 0, 0.5, 0.0, -1.0},
    {&D_800308A0, 0, 0.5, 0.0, -1.0},
    {&D_800308E8, 0, 0.5, 0.0, -1.0},
    {crouched_pistol_firing_animation_group1, 0, 0.1, 56.0, 68.0},
    {rifle_firing_animation_group1, 0, 0.050000001, 35.0, 40.0},
    {&D_80030660, 0, 0.5, 0.0, -1.0},
    {&D_800306A8, 0, 0.5, 0.0, -1.0},
    {&D_800308A0, 0, 0.5, 0.0, -1.0},
    {&D_800308E8, 0, 0.5, 0.0, -1.0},
    {crouched_rifle_firing_animation_groupA, 0, 0.1, 45.0, 55.0},
    {NULL, 0x8194, 0.25, 0.0, -1.0},
    {NULL, 0x8204, 0.5, 0.0, -1.0},
    {NULL, 0x777C, 0.5, 0.0, -1.0},
    {&D_800308A0, 0, 0.5, 0.0, -1.0},
    {&D_800308E8, 0, 0.5, 0.0, -1.0},
    {NULL, 0x6C18, 0.050000001, 28.0, 29.0},
    {doubles_firing_animation_group1, 0, 0.1, 32.0, 42.0},
    {&D_80030780, 0, 0.5, 0.0, -1.0},
    {&D_800307C8, 0, 0.5, 0.0, -1.0},
    {&D_800308A0, 0, 0.5, 0.0, -1.0},
    {&D_800308A0, 0, 0.5, 0.0, -1.0},
    {crouched_doubles_firing_animation_group1, 0, 0.1, 37.0, 47.0}};

int D_80036AB8 = 2;
int D_80036ABC = 0xFFFFFFFF;
float D_80036AC0 = 1.0;
float D_80036AC4 = 0.1;
