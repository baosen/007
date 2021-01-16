#include "chr.h"
#include "bondtypes.h"
#include <stddef.h>
#include <types.h>

float animation_rate = 0;
int D_8002C904 = 0;
int D_8002C908 = 0;
int D_8002C90C = 0;
int D_8002C910 = 0;

struct animation_something D_8002C914 = {0, 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0};
struct animation_something D_8002C940 = {1,    1,          0, 17.0,       3, 0,
                                         34.0, D_8002CE54, 0, D_8002DF10, 0};
struct animation_something D_8002C96C = {2,    1,          0, 17.0,       3, 0,
                                         39.0, D_8002CEE0, 0, D_8002DF64, 0};
struct animation_something D_8002C998 = {3,    1,          0, 21.0,       3, 0,
                                         43.0, D_8002CF6C, 0, D_8002DFB8, 0};
struct animation_something D_8002C9C4 = {4,    1,          0, 17.0,       3, 0,
                                         34.0, D_8002D014, 0, D_8002E028, 0};
struct animation_something D_8002C9F0 = {5,    1,          0, 17.0,       3, 0,
                                         39.0, D_8002D0A0, 0, D_8002E07C, 0};
struct animation_something D_8002CA1C = {6,    1,          0, 21.0,       3, 0,
                                         43.0, D_8002D12C, 0, D_8002E0D0, 0};
struct animation_something D_8002CA48 = {7,    1,          0, 21.0,       3, 0,
                                         52.0, D_8002D1D4, 0, D_8002E140, 0};
struct animation_something D_8002CA74 = {8,    1,          0, 21.0,       3, 0,
                                         43.0, D_8002D3B0, 0, D_8002E23C, 0};
struct animation_something D_8002CAA0 = {9,    1,          0, 17.0,       3, 0,
                                         34.0, D_8002D6DC, 0, D_8002E300, 0};
struct animation_something D_8002CACC = {0xA,  1,          0, 17.0,       3, 0,
                                         43.0, D_8002D768, 0, D_8002E354, 0};
struct animation_something D_8002CAF8 = {0xB,  1,          0, 21.0,       3, 0,
                                         52.0, D_8002D7F4, 0, D_8002E3A8, 0};
struct animation_something D_8002CB24 = {0xC,  1,          0, 17.0,       3, 0,
                                         34.0, D_8002D880, 0, D_8002E418, 0};
struct animation_something D_8002CB50 = {0xD,  1,          0, 17.0,       3, 0,
                                         43.0, D_8002D90C, 0, D_8002E46C, 0};
struct animation_something D_8002CB7C = {0xE,  1,          0, 21.0,       3, 0,
                                         52.0, D_8002D998, 0, D_8002E4C0, 0};
struct animation_something D_8002CBA8 = {0xF,  1,          0, 26.0,       3, 0,
                                         60.0, D_8002DA24, 0, D_8002E530, 0};
struct animation_something D_8002CBD4 = {0x64, 1,          0, 26.0,       0, 0,
                                         0.0,  D_8002DCE0, 0, D_8002E5BC, 0};
struct animation_something D_8002CC00 = {0x6E, 1,    0, 21.0, 0, 0,
                                         0.0,  NULL, 0, NULL, 0};
struct animation_something D_8002CC2C = {0xFFFFFFFF, 0,    0, 0.0,  0, 0,
                                         0.0,        NULL, 0, NULL, 0};

int D_8002CC58 = 0;
int show_patrols_flag = false;
int player1_guardID = 0x1388;
int ptr_guard_data = 0;
int num_guards = 0;
int D_8002CC6C[] = {0, 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int D_8002CCA8 = 0;
int D_8002CCAC = 0;
int D_8002CCB0 = 0;
int D_8002CCB4 = 0;
unsigned char D_8002CCB8 = 0x5A;

unsigned int D_8002CCBC = 0;
unsigned int D_8002CCC0[] = {1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int D_8002CCF8 = 0;
int D_8002CCFC = 0;
int num_bodies = 0;
int num_male_heads = 0;
int num_female_heads = 0;

int list_of_bodies[] = {
    BODY_Jungle_Commando,
    BODY_St_Petersburg_Guard,
    BODY_Russian_Soldier,
    BODY_Russian_Infantry,
    BODY_Janus_Special_Forces,
    BODY_Tuxedo,
    BODY_Boris,
    BODY_Ourumov,
    BODY_Trevelyan_Janus,
    BODY_Valentin_,
    BODY_Xenia,
    BODY_Baron_Samedi,
    BODY_Jaws,
    BODY_Mayday,
    BODY_Oddjob,
    BODY_Natalya_Skirt,
    BODY_Janus_Marine,
    BODY_Russian_Commandant,
    BODY_Siberian_Guard_1_Mishkin,
    BODY_Naval_Officer,
    BODY_Siberian_Special_Forces,
    BODY_Special_Operations_Uniform,
    BODY_Formal_Wear,
    BODY_Jungle_Fatigues,
    BODY_Unused_Female,
    BODY_Rosika,
    BODY_Scientist_2_Female,
    BODY_Civilian_1_Female,
    BODY_Unused_Male_1,
    BODY_Unused_Male_2,
    BODY_Civilian_4,
    BODY_Civilian_2,
    BODY_Civilian_3,
    BODY_Scientist_1_Male,
    BODY_Tuxedo,
    BODY_Tuxedo,
    BODY_Tuxedo,
    BODY_Helicopter_Pilot,
    BODY_Siberian_Guard_2,
    BODY_Arctic_Commando,
    BODY_Moonraker_Elite_1_Male,
    BODY_Moonraker_Elite_2_Female,
    -1,
};

int random_male_heads[] = {HEAD_Male_Jim,         HEAD_Male_Chris,
                           HEAD_Male_Lee,         HEAD_Male_Graeme,
                           HEAD_Male_Steve_H,     HEAD_Male_Neil,
                           HEAD_Male_Robin,       HEAD_Male_Des,
                           HEAD_Male_Grant,       HEAD_Male_Dave_Dr_Doak,
                           HEAD_Male_Karl,        HEAD_Male_Alan,
                           HEAD_Male_Pete,        HEAD_Male_Martin,
                           HEAD_Male_Mark,        HEAD_Male_Duncan,
                           HEAD_Male_Shaun,       HEAD_Male_Dwayne,
                           HEAD_Male_B,           HEAD_Male_Steve_Ellis,
                           HEAD_Male_Joel,        HEAD_Male_Scott,
                           HEAD_Male_Joe_Altered, HEAD_Male_Ken,
                           HEAD_Male_Joe,         -1};

int random_female_heads[] = {HEAD_Female_Sally, HEAD_Female_Marion_Rosika,
                             HEAD_Female_Mandy, HEAD_Female_Vivien, -1};

int current_random_body = 0;
int current_random_male_head = 0;
int current_random_female_head = 0;
float ai_accuracy_modifier = 1.0f;
float ai_damage_modifier = 1.0f;
float ai_health_modifier = 1.0f;
float ai_reaction_speed = 1.0f;
float setting_007_5 = 0.0f;

struct struck_animation_table D_8002CE54[] = {
    {0x35C8, 0, -1.0, 0.5, 0, 27.0, -1.0},
    {0x36D8, 0, -1.0, 0.5, 0, 26.0, -1.0},
    {0x33AC, 1, -1.0, 0.5, 0, 25.0, -1.0},
    {0x34D4, 1, -1.0, 0.5, 0, 23.0, -1.0},
    {0, 0, 0.0, 0.5, 0, -1.0, -1.0}};

struct struck_animation_table D_8002CEE0[] = {
    {0x35C8, 0, -1.0, 0.5, 0, 27.0, -1.0},
    {0x36D8, 0, -1.0, 0.5, 0, 26.0, -1.0},
    {0x33AC, 1, -1.0, 0.5, 0, 25.0, -1.0},
    {0x34D4, 1, -1.0, 0.5, 0, 23.0, -1.0},
    {0, 0, 0.0, 0.5, 0, -1.0, -1.0}};

struct struck_animation_table D_8002CF6C[] = {
    {0x35C8, 0, -1.0, 0.5, 1, 27.0, -1.0},
    {0x36D8, 0, -1.0, 0.5, 1, 26.0, -1.0},
    {0x33AC, 1, -1.0, 0.5, 1, 25.0, -1.0},
    {0x34D4, 1, -1.0, 0.5, 1, 23.0, -1.0},
    {0x540C, 1, -1.0, 0.5, 0, -1.0, -1.0},
    {0, 0, 0.0, 0.5, 0, -1.0, -1.0}};

struct struck_animation_table D_8002D014[] = {
    {0x33AC, 0, -1.0, 0.5, 0, 25.0, -1.0},
    {0x34D4, 0, -1.0, 0.5, 0, 23.0, -1.0},
    {0x35C8, 1, -1.0, 0.5, 0, 27.0, -1.0},
    {0x36D8, 1, -1.0, 0.5, 0, 26.0, -1.0},
    {0, 0, 0.0, 0.5, 0, -1.0, -1.0}};

struct struck_animation_table D_8002D0A0[] = {
    {0x33AC, 0, -1.0, 0.5, 0, 25.0, -1.0},
    {0x34D4, 0, -1.0, 0.5, 0, 23.0, -1.0},
    {0x35C8, 1, -1.0, 0.5, 0, 27.0, -1.0},
    {0x36D8, 1, -1.0, 0.5, 0, 26.0, -1.0},
    {0, 0, 0.0, 0.5, 0, -1.0, -1.0}};

struct struck_animation_table D_8002D12C[] = {
    {0x33AC, 0, -1.0, 0.5, 1, 25.0, -1.0},
    {0x34D4, 0, -1.0, 0.5, 1, 23.0, -1.0},
    {0x35C8, 1, -1.0, 0.5, 1, 27.0, -1.0},
    {0x36D8, 1, -1.0, 0.5, 1, 26.0, -1.0},
    {0x540C, 0, -1.0, 0.5, 0, -1.0, -1.0},
    {0, 0, 0.0, 0.5, 0, -1.0, -1.0}};

struct struck_animation_table D_8002D1D4[] = {
    {0x30B8, 0, -1.0, 0.5, 0, 55.0, 39.0},
    {0x30B8, 1, -1.0, 0.5, 0, 55.0, 39.0},
    {0x31DC, 0, -1.0, 0.5, 0, 36.0, -1.0},
    {0x31DC, 1, -1.0, 0.5, 0, 36.0, -1.0},
    {0x32C8, 0, -1.0, 0.5, 1, 29.0, -1.0},
    {0x32C8, 1, -1.0, 0.5, 1, 29.0, -1.0},
    {0x384C, 0, -1.0, 0.5, 0, 97.0, 64.0},
    {0x384C, 1, -1.0, 0.5, 0, 97.0, 64.0},
    {0x3AF0, 0, -1.0, 0.5, 0, 31.0, -1.0},
    {0x3AF0, 1, -1.0, 0.5, 0, 31.0, -1.0},
    {0x3C10, 0, -1.0, 0.5, 0, 36.0, -1.0},
    {0x3C10, 1, -1.0, 0.5, 0, 36.0, -1.0},
    {0x3D04, 0, -1.0, 0.5, 0, 28.0, -1.0},
    {0x3D04, 1, -1.0, 0.5, 0, 28.0, -1.0},
    {0x282C, 0, -1.0, 0.5, 0, 79.0, 415.0},
    {0x282C, 1, -1.0, 0.5, 0, 79.0, 415.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}};

struct struck_animation_table D_8002D3B0[] = {
    {0x30B8, 0, -1.0, 0.5, 0, 55.0, 39.0},
    {0x30B8, 1, -1.0, 0.5, 0, 55.0, 39.0},
    {0x31DC, 0, -1.0, 0.5, 0, 36.0, -1.0},
    {0x31DC, 1, -1.0, 0.5, 0, 36.0, -1.0},
    {0x32C8, 0, -1.0, 0.5, 1, 29.0, -1.0},
    {0x32C8, 1, -1.0, 0.5, 1, 29.0, -1.0},
    {0x33AC, 0, -1.0, 0.5, 1, 25.0, -1.0},
    {0x33AC, 1, -1.0, 0.5, 1, 25.0, -1.0},
    {0x34D4, 0, -1.0, 0.5, 1, 23.0, -1.0},
    {0x34D4, 1, -1.0, 0.5, 1, 23.0, -1.0},
    {0x35C8, 0, -1.0, 0.5, 1, 27.0, -1.0},
    {0x35C8, 1, -1.0, 0.5, 1, 27.0, -1.0},
    {0x36D8, 0, -1.0, 0.5, 1, 26.0, -1.0},
    {0x36D8, 1, -1.0, 0.5, 1, 26.0, -1.0},
    {0x384C, 0, -1.0, 0.5, 0, 97.0, 64.0},
    {0x384C, 1, -1.0, 0.5, 0, 97.0, 64.0},
    {0x39C0, 0, -1.0, 0.5, 0, 94.0, 66.0},
    {0x39C0, 1, -1.0, 0.5, 0, 94.0, 66.0},
    {0x3AF0, 0, -1.0, 0.5, 0, 31.0, -1.0},
    {0x3AF0, 1, -1.0, 0.5, 0, 31.0, -1.0},
    {0x3C10, 0, -1.0, 0.5, 0, 36.0, -1.0},
    {0x3C10, 1, -1.0, 0.5, 0, 36.0, -1.0},
    {0x3D04, 0, -1.0, 0.5, 0, 28.0, -1.0},
    {0x3D04, 1, -1.0, 0.5, 0, 28.0, -1.0},
    {0x2E64, 0, -1.0, 0.5, 0, 87.0, 203.0},
    {0x2E64, 1, -1.0, 0.5, 0, 87.0, 203.0},
    {0x51C4, 0, -1.0, 0.5, 0, -1.0, -1.0},
    {0x51C4, 1, -1.0, 0.5, 0, -1.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}};

struct struck_animation_table D_8002D6DC[] = {
    {0x35C8, 0, -1.0, 0.5, 0, 27.0, -1.0},
    {0x36D8, 0, -1.0, 0.5, 0, 26.0, -1.0},
    {0x33AC, 1, -1.0, 0.5, 0, 25.0, -1.0},
    {0x34D4, 1, -1.0, 0.5, 0, 23.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}};

struct struck_animation_table D_8002D768[] = {
    {0x35C8, 0, -1.0, 0.5, 0, 27.0, -1.0},
    {0x36D8, 0, -1.0, 0.5, 0, 26.0, -1.0},
    {0x33AC, 1, -1.0, 0.5, 0, 25.0, -1.0},
    {0x34D4, 1, -1.0, 0.5, 0, 23.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}};

struct struck_animation_table D_8002D7F4[] = {
    {0x35C8, 0, -1.0, 0.5, 1, 27.0, -1.0},
    {0x36D8, 0, -1.0, 0.5, 1, 26.0, -1.0},
    {0x33AC, 1, -1.0, 0.5, 1, 25.0, -1.0},
    {0x34D4, 1, -1.0, 0.5, 1, 23.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}};

struct struck_animation_table D_8002D880[] = {
    {0x33AC, 0, -1.0, 0.5, 0, 25.0, -1.0},
    {0x34D4, 0, -1.0, 0.5, 0, 23.0, -1.0},
    {0x35C8, 1, -1.0, 0.5, 0, 27.0, -1.0},
    {0x36D8, 1, -1.0, 0.5, 0, 26.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}};

struct struck_animation_table D_8002D90C[] = {
    {0x33AC, 0, -1.0, 0.5, 0, 25.0, -1.0},
    {0x34D4, 0, -1.0, 0.5, 0, 23.0, -1.0},
    {0x35C8, 1, -1.0, 0.5, 0, 27.0, -1.0},
    {0x36D8, 1, -1.0, 0.5, 0, 26.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}};

struct struck_animation_table D_8002D998[] = {
    {0x33AC, 0, -1.0, 0.5, 1, 25.0, -1.0},
    {0x34D4, 0, -1.0, 0.5, 1, 23.0, -1.0},
    {0x35C8, 1, -1.0, 0.5, 1, 27.0, -1.0},
    {0x36D8, 1, -1.0, 0.5, 1, 26.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}};

struct struck_animation_table D_8002DA24[] = {
    {0x30B8, 0, -1.0, 0.5, 0, 55.0, 39.0},
    {0x30B8, 1, -1.0, 0.5, 0, 55.0, 39.0},
    {0x31DC, 0, -1.0, 0.5, 0, 36.0, -1.0},
    {0x31DC, 1, -1.0, 0.5, 0, 36.0, -1.0},
    {0x32C8, 0, -1.0, 0.5, 1, 29.0, -1.0},
    {0x32C8, 1, -1.0, 0.5, 1, 29.0, -1.0},
    {0x33AC, 0, -1.0, 0.5, 1, 25.0, -1.0},
    {0x33AC, 1, -1.0, 0.5, 1, 25.0, -1.0},
    {0x34D4, 0, -1.0, 0.5, 1, 23.0, -1.0},
    {0x34D4, 1, -1.0, 0.5, 1, 23.0, -1.0},
    {0x35C8, 0, -1.0, 0.5, 1, 27.0, -1.0},
    {0x35C8, 1, -1.0, 0.5, 1, 27.0, -1.0},
    {0x36D8, 0, -1.0, 0.5, 1, 26.0, -1.0},
    {0x36D8, 1, -1.0, 0.5, 1, 26.0, -1.0},
    {0x384C, 0, -1.0, 0.5, 0, 97.0, 64.0},
    {0x384C, 1, -1.0, 0.5, 0, 97.0, 64.0},
    {0x39C0, 0, -1.0, 0.5, 0, 94.0, 66.0},
    {0x39C0, 1, -1.0, 0.5, 0, 94.0, 66.0},
    {0x3AF0, 0, -1.0, 0.5, 0, 31.0, -1.0},
    {0x3AF0, 1, -1.0, 0.5, 0, 31.0, -1.0},
    {0x3C10, 0, -1.0, 0.5, 0, 36.0, -1.0},
    {0x3C10, 1, -1.0, 0.5, 0, 36.0, -1.0},
    {0x3D04, 0, -1.0, 0.5, 0, 28.0, -1.0},
    {0x3D04, 1, -1.0, 0.5, 0, 28.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}};

struct struck_animation_table D_8002DCE0[] = {
    {0x30B8, 0, -1.0, 0.5, 0, 55.0, 39.0},
    {0x30B8, 1, -1.0, 0.5, 0, 55.0, 39.0},
    {0x31DC, 0, -1.0, 0.5, 0, 36.0, -1.0},
    {0x31DC, 1, -1.0, 0.5, 0, 36.0, -1.0},
    {0x32C8, 0, -1.0, 0.5, 1, 29.0, -1.0},
    {0x32C8, 1, -1.0, 0.5, 1, 29.0, -1.0},
    {0x384C, 0, -1.0, 0.5, 0, 97.0, 64.0},
    {0x384C, 1, -1.0, 0.5, 0, 97.0, 64.0},
    {0x39C0, 0, -1.0, 0.5, 0, 94.0, 66.0},
    {0x39C0, 1, -1.0, 0.5, 0, 94.0, 66.0},
    {0x3AF0, 0, -1.0, 0.5, 0, 31.0, -1.0},
    {0x3AF0, 1, -1.0, 0.5, 0, 31.0, -1.0},
    {0x3C10, 0, -1.0, 0.5, 0, 36.0, -1.0},
    {0x3C10, 1, -1.0, 0.5, 0, 36.0, -1.0},
    {0x3D04, 0, -1.0, 0.5, 0, 28.0, -1.0},
    {0x3D04, 1, -1.0, 0.5, 0, 28.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}};

struct struck_animation_table D_8002DEBC[] = {
    {0x2F94, 0, -1.0, 0.5, 0, 67.0, 54.0},
    {0x2F94, 1, -1.0, 0.5, 0, 67.0, 54.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}};

struct struck_animation_table D_8002DF10[] = {
    {0x1F84, 0, -1.0, 0.5, 0, -1.0, -1.0},
    {0x2134, 1, -1.0, 0.5, 0, -1.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}};

struct struck_animation_table D_8002DF64[] = {
    {0x1F84, 0, -1.0, 0.5, 0, -1.0, -1.0},
    {0x2134, 1, -1.0, 0.5, 0, -1.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}};

struct struck_animation_table D_8002DFB8[] = {
    {0x1F84, 0, -1.0, 0.5, 0, -1.0, -1.0},
    {0x2134, 1, -1.0, 0.5, 0, -1.0, -1.0},
    {0x540C, 1, 20.0, 0.40000001, 0, -1.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}};

struct struck_animation_table D_8002E028[] = {
    {0x2134, 0, -1.0, 0.5, 0, -1.0, -1.0},
    {0x1F84, 1, -1.0, 0.5, 0, -1.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}};

struct struck_animation_table D_8002E07C[] = {
    {0x2134, 0, -1.0, 0.5, 0, -1.0, -1.0},
    {0x1F84, 1, -1.0, 0.5, 0, -1.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}};

struct struck_animation_table D_8002E0D0[] = {
    {0x2134, 0, -1.0, 0.5, 0, -1.0, -1.0},
    {0x1F84, 1, -1.0, 0.5, 0, -1.0, -1.0},
    {0x540C, 0, 20.0, 0.40000001, 0, -1.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}};

struct struck_animation_table D_8002E140[] = {
    {0x282C, 0, 20.0, 0.5, 0, -1.0, -1.0},
    {0x282C, 1, 30.0, 0.5, 0, -1.0, -1.0},
    {0x39C0, 0, 20.0, 0.5, 0, -1.0, -1.0},
    {0x39C0, 1, 20.0, 0.5, 0, -1.0, -1.0},
    {0x30B8, 0, 15.0, 0.5, 0, -1.0, -1.0},
    {0x30B8, 1, 15.0, 0.5, 0, -1.0, -1.0},
    {0x3AF0, 0, 10.0, 0.25, 0, -1.0, -1.0},
    {0x3AF0, 1, 10.0, 0.25, 0, -1.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}};

struct struck_animation_table D_8002E23C[] = {
    {0x2E64, 0, 15.0, 0.5, 0, 87.0, 203.0},
    {0x2E64, 1, 15.0, 0.5, 0, 87.0, 203.0},
    {0x39C0, 0, 20.0, 0.5, 0, -1.0, -1.0},
    {0x39C0, 1, 20.0, 0.5, 0, -1.0, -1.0},
    {0x30B8, 0, 15.0, 0.5, 0, -1.0, -1.0},
    {0x30B8, 1, 15.0, 0.5, 0, -1.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}};

struct struck_animation_table D_8002E300[] = {
    {0x1C9C, 0, -1.0, 0.5, 0, -1.0, -1.0},
    {0x1E40, 1, -1.0, 0.5, 0, -1.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}};

struct struck_animation_table D_8002E354[] = {
    {0x1A6C, 0, -1.0, 0.5, 0, -1.0, -1.0},
    {0x1B54, 1, -1.0, 0.5, 0, -1.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}};

struct struck_animation_table D_8002E3A8[] = {
    {0x186C, 0, -1.0, 0.5, 0, -1.0, -1.0},
    {0x1984, 1, -1.0, 0.5, 0, -1.0, -1.0},
    {0x39C0, 0, 20.0, 0.5, 0, -1.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}};

struct struck_animation_table D_8002E418[] = {
    {0x1E40, 0, -1.0, 0.5, 0, -1.0, -1.0},
    {0x1C9C, 1, -1.0, 0.5, 0, -1.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}};

struct struck_animation_table D_8002E46C[] = {
    {0x1B54, 0, -1.0, 0.5, 0, -1.0, -1.0},
    {0x1A6C, 1, -1.0, 0.5, 0, -1.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}};

struct struck_animation_table D_8002E4C0[] = {
    {0x1984, 0, -1.0, 0.5, 0, -1.0, -1.0},
    {0x186C, 1, -1.0, 0.5, 0, -1.0, -1.0},
    {0x39C0, 1, 20.0, 0.5, 0, -1.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}};

struct struck_animation_table D_8002E530[] = {
    {0x39C0, 0, 20.0, 0.5, 0, -1.0, -1.0},
    {0x39C0, 1, 20.0, 0.5, 0, -1.0, -1.0},
    {0x30B8, 0, 15.0, 0.5, 0, -1.0, -1.0},
    {0x30B8, 1, 15.0, 0.5, 0, -1.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}};

struct struck_animation_table D_8002E5BC[] = {
    {0x39C0, 0, 20.0, 0.5, 0, -1.0, -1.0},
    {0x39C0, 1, 20.0, 0.5, 0, -1.0, -1.0},
    {0x30B8, 0, 15.0, 0.5, 0, -1.0, -1.0},
    {0x30B8, 1, 15.0, 0.5, 0, -1.0, -1.0},
    {0, 0, -1.0, 0.5, 0, -1.0, -1.0}};

struct explosion_death_animation D_8002E648[] = {
    {0x98C8, 0, 0.5, 9.0, 18.0, 29.0, -1.0},
    {0x98C8, 1, 0.5, 9.0, 18.0, 29.0, -1.0},
    {0xA1B8, 0, 0.5, 11.0, 19.0, 31.0, -1.0},
    {0xA1B8, 1, 0.5, 11.0, 19.0, 31.0, -1.0},
    {0xA094, 0, 0.5, 6.0, 20.0, 27.0, -1.0},
    {0xA094, 1, 0.5, 6.0, 20.0, 27.0, -1.0},
    {0xA424, 0, 0.5, 29.0, 36.0, 48.0, -1.0},
    {0xA424, 1, 0.5, 29.0, 36.0, 48.0, -1.0},
    {0xA538, 0, 0.5, 29.0, 38.0, 49.0, -1.0},
    {0xA538, 1, 0.5, 29.0, 38.0, 49.0, -1.0},
    {0xA650, 0, 0.5, 19.0, 30.0, 42.0, -1.0},
    {0xA650, 1, 0.5, 19.0, 30.0, 42.0, -1.0},
    {0x9A2C, 0, 0.5, 9.0, 21.0, 29.0, 55.0},
    {0x9A2C, 1, 0.5, 9.0, 21.0, 29.0, 55.0},
    {0x9D5C, 0, 0.5, 6.0, 18.0, 27.0, -1.0},
    {0x9D5C, 1, 0.5, 6.0, 18.0, 27.0, -1.0},
    {0x9E44, 0, 0.5, 6.0, 19.0, 29.0, -1.0},
    {0x9E44, 1, 0.5, 6.0, 19.0, 29.0, -1.0},
    {0x9B48, 0, 0.5, 8.0, 14.0, 25.0, -1.0},
    {0x9B48, 1, 0.5, 8.0, 14.0, 25.0, -1.0},
    {0x9C4C, 0, 0.5, 8.0, 19.0, 25.0, -1.0},
    {0x9C4C, 1, 0.5, 8.0, 19.0, 25.0, -1.0},
    {0x9F48, 0, 0.5, 12.0, 21.0, 29.0, -1.0},
    {0x9F48, 1, 0.5, 12.0, 21.0, 29.0, -1.0},
    {0xA2F8, 0, 0.5, 22.0, 30.0, 41.0, -1.0},
    {0xA2F8, 1, 0.5, 22.0, 30.0, 41.0, -1.0},
    {0, 0, 0.5, 0.0, 0.0, 0.0, -1.0},
};

unsigned char expl_forward[] = {0x0, 0x01, 0x02, 0x03, 0x4, 0x05, 0x00, 0x00};
unsigned char expl_f_left[] = {0x7, 0x09, 0x0B, 0x00};
unsigned char expl_f_right[] = {0x06, 0x08, 0x0A, 0x00};
unsigned char expl_left[] = {0x0C, 0x0F, 0x11, 0x00};
unsigned char expl_right[] = {0x0D, 0x0E, 0x10, 0x00};
unsigned char expl_back[] = {0x14, 0x15, 0x16, 0x17};
unsigned char expl_b_right[] = {0x12, 0x18, 0x00, 0x00};
unsigned char expl_b_left[] = {0x13, 0x19, 0x00, 0x00};

struct explosion_animation explosion_animation_table[] = {
    {expl_forward, 6}, {expl_f_left, 3}, {expl_left, 3},  {expl_b_right, 2},
    {expl_back, 4},    {expl_b_left, 2}, {expl_right, 3}, {expl_f_right, 3}};

struct weapon_firing_animation_table rifle_firing_animation_group1[] = {
    {0x214, 28.0, 0, 0, 0, -1.0, 23.0, 54.0, -1.0, -1.0, 18.0, 54.0, 0.87266463,
     -0.52359879, 1.0471976, -0.34906587, 1.6, 1.8},
    {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
     0.0, 0.0}};

void *ptr_rifle_firing_animation_group1[] = {&rifle_firing_animation_group1,
                                             ((void *)-1)};

struct weapon_firing_animation_table rifle_firing_animation_group2[] = {
    {0x144, 37.0, 0, 0, 0, -1.0, 30.0, 81.0, -1.0, -1.0, 25.0, 81.0, 0.87266463,
     -0.69813174, 0.69813174, -0.69813174, 1.6, 1.75},
    {0x318, 27.0, 0, 0, 0, -1.0, 22.0, 61.0, -1.0, -1.0, 17.0, 61.0, 0.87266463,
     -0.2617994, 0.69813174, -0.69813174, 2.0, 1.0},
    {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
     0.0, 0.0}};

void *ptr_rifle_firing_animation_group2[] = {&rifle_firing_animation_group2,
                                             ((void *)-1)};

struct weapon_firing_animation_table rifle_firing_animation_group5[] = {
    {0x144, 37.0, 0, 0, 0, -1.0, 30.0, 81.0, -1.0, -1.0, 25.0, 81.0, 0.87266463,
     -0.69813174, 0.69813174, -0.69813174, 1.6, 1.75},
    {0x318, 27.0, 0, 0, 0, -1.0, 22.0, 61.0, -1.0, -1.0, 17.0, 61.0, 0.87266463,
     -0.2617994, 0.69813174, -0.69813174, 2.0, 1.0},
    {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
     0.0, 0.0}};

void *ptr_rifle_firing_animation_group5[] = {&rifle_firing_animation_group5,
                                             ((void *)-1)};

struct weapon_firing_animation_table rifle_firing_animation_group3[] = {
    {0x3C4, 19.0, 0, 1.5707964, 0, -1.0, 19.0, 61.0, -1.0, -1.0, 14.0, 61.0,
     0.87266463, -0.34906587, 0.43633232, -1.0471976, 2.5, 2.5},
    {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
     0.0, 0.0}};

void *ptr_rifle_firing_animation_group3[] = {&rifle_firing_animation_group3,
                                             ((void *)-1)};

struct weapon_firing_animation_table rifle_firing_animation_group4[] = {
    {0x814, 27.0, 0, 0, 0, -1.0, 39.0, 74.0, -1.0, -1.0, 34.0, 74.0, 0.87266463,
     -0.69813174, 0.78539819, -0.69813174, 1.5, 1.5},
    {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
     0.0, 0.0}};

void *ptr_rifle_firing_animation_group4[] = {&rifle_firing_animation_group4,
                                             ((void *)-1)};

void *ptr_rifle_firing_animation_groups[] = {
    &ptr_rifle_firing_animation_group1, &ptr_rifle_firing_animation_group2,
    &ptr_rifle_firing_animation_group2, &ptr_rifle_firing_animation_group2,
    &ptr_rifle_firing_animation_group2, &ptr_rifle_firing_animation_group2,
    &ptr_rifle_firing_animation_group2, &ptr_rifle_firing_animation_group2,
    &ptr_rifle_firing_animation_group2, &ptr_rifle_firing_animation_group2,
    &ptr_rifle_firing_animation_group3, &ptr_rifle_firing_animation_group3,
    &ptr_rifle_firing_animation_group3, &ptr_rifle_firing_animation_group3,
    &ptr_rifle_firing_animation_group3, &ptr_rifle_firing_animation_group3,
    &ptr_rifle_firing_animation_group4, &ptr_rifle_firing_animation_group4,
    &ptr_rifle_firing_animation_group4, &ptr_rifle_firing_animation_group4,
    &ptr_rifle_firing_animation_group4, &ptr_rifle_firing_animation_group4,
    &ptr_rifle_firing_animation_group5, &ptr_rifle_firing_animation_group5,
    &ptr_rifle_firing_animation_group5, &ptr_rifle_firing_animation_group5,
    &ptr_rifle_firing_animation_group5, &ptr_rifle_firing_animation_group5,
    &ptr_rifle_firing_animation_group5, &ptr_rifle_firing_animation_group5,
    &ptr_rifle_firing_animation_group5, &ptr_rifle_firing_animation_group1};

struct weapon_firing_animation_table pistol_firing_animation_group1[] = {
    {0x60D4, 26.0, 0, 0, 12.0, 140.0, 58.0, 92.0, 60.0, 79.0, 20.0, 120.0,
     0.87266463, -0.69813174, 0.69813174, -0.69813174, 0.0, 0.0},
    {0x6484, 0.0, 0, 0, 17.0, 100.0, 25.0, 87.0, 30.0, 55.0, 20.0, 93.0,
     0.87266463, -0.69813174, 0.69813174, -1.0471976, 0.0, 0.0},
    {0x6554, 0.0, 0, 0, 12.0, 64.0, 19.0, 51.0, 24.0, 46.0, 14.0, 58.0,
     0.87266463, -0.69813174, 0.52359879, -0.78539819, 0.0, 0.0},
    {0x6644, 22.0, 0, 0, 4.0, 69.0, 22.0, 49.0, 22.0, 33.0, 8.0, 58.0,
     0.87266463, -0.69813174, 0.43633232, -0.78539819, 0.0, 0.0},
    {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
     0.0, 0.0}};

void *ptr_pistol_firing_animation_group1[] = {&pistol_firing_animation_group1,
                                              ((void *)-1)};

struct weapon_firing_animation_table pistol_firing_animation_group2[] = {
    {0x60D4, 26.0, 0, 0, 12.0, 140.0, 58.0, 92.0, 60.0, 79.0, 20.0, 120.0,
     0.87266463, -0.69813174, 0.69813174, -0.69813174, 0.0, 0.0},
    {0x6644, 22.0, 0, 0, 4.0, 69.0, 22.0, 49.0, 22.0, 33.0, 8.0, 58.0,
     0.87266463, -0.69813174, 0.43633232, -0.78539819, 0.0, 0.0},
    {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
     0.0, 0.0}};

void *ptr_pistol_firing_animation_group2[] = {&pistol_firing_animation_group2,
                                              ((void *)-1)};

struct weapon_firing_animation_table pistol_firing_animation_group3[] = {
    {0x60D4, 26.0, 0, 0, 12.0, 140.0, 58.0, 92.0, 60.0, 79.0, 20.0, 120.0,
     0.87266463, -0.69813174, 0.69813174, -0.69813174, 0.0, 0.0},
    {0x6644, 22.0, 0, 0, 4.0, 69.0, 22.0, 49.0, 22.0, 33.0, 8.0, 58.0,
     0.87266463, -0.69813174, 0.43633232, -0.78539819, 0.0, 0.0},
    {0x694C, 0.0, 0, 1.5707964, 7.0, 130.0, 45.0, 93.0, 56.0, 73.0, 26.0, 107.0,
     0.87266463, -0.69813174, 0.34906587, -0.52359879, 0.0, 0.0},
    {0x6A18, 15.0, 0, 1.5707964, 5.0, 76.0, 20.0, 31.0, 31.0, 38.0, 15.0, 49.0,
     0.87266463, -0.69813174, 0.52359879, -1.0471976, 0.0, 0.0},
    {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
     0.0, 0.0}};

void *ptr_pistol_firing_animation_group3[] = {&pistol_firing_animation_group3,
                                              ((void *)-1)};

struct weapon_firing_animation_table pistol_firing_animation_group6[] = {
    {0x60D4, 26.0, 0, 0, 12.0, 140.0, 58.0, 92.0, 60.0, 79.0, 20.0, 120.0,
     0.87266463, -0.69813174, 0.69813174, -0.69813174, 0.0, 0.0},
    {0x6644, 22.0, 0, 0, 4.0, 69.0, 22.0, 49.0, 22.0, 33.0, 8.0, 58.0,
     0.87266463, -0.69813174, 0.43633232, -0.78539819, 0.0, 0.0},
    {0x6738, 0.0, 0, 4.712389, 7.0, 139.0, 54.0, 105.0, 61.0, 88.0, 26.0, 120.0,
     0.87266463, -0.69813174, 0.69813174, -0.61086529, 0.0, 0.0},
    {0x6808, 19.0, 0, 4.712389, 4.0, 79.0, 21.0, 50.0, 26.0, 42.0, 10.0, 64.0,
     0.87266463, -0.69813174, 0.69813174, -0.61086529, 0.0, 0.0},
    {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
     0.0, 0.0}};

void *ptr_pistol_firing_animation_group6[] = {&pistol_firing_animation_group6,
                                              ((void *)-1)};

struct weapon_firing_animation_table pistol_firing_animation_group4[] = {
    {0x6A18, 19.0, 0, 1.5707964, 5.0, 76.0, 20.0, 31.0, 31.0, 38.0, 15.0, 49.0,
     0.87266463, -0.69813174, 0.52359879, -1.0471976, 0.0, 0.0},
    {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
     0.0, 0.0}};

void *ptr_pistol_firing_animation_group4[] = {&pistol_firing_animation_group4,
                                              ((void *)-1)};

struct weapon_firing_animation_table pistol_firing_animation_group5[] = {
    {0x6808, 19.0, 0, 4.712389, 4.0, 79.0, 21.0, 50.0, 26.0, 42.0, 10.0, 64.0,
     0.87266463, -0.69813174, 0.69813174, -0.61086529, 0.0, 0.0},
    {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
     0.0, 0.0}};

void *ptr_pistol_firing_animation_group5[] = {&pistol_firing_animation_group5,
                                              ((void *)-1)};

void *ptr_pistol_firing_animation_groups[] = {
    &ptr_pistol_firing_animation_group1, &ptr_pistol_firing_animation_group1,
    &ptr_pistol_firing_animation_group2, &ptr_pistol_firing_animation_group2,
    &ptr_pistol_firing_animation_group2, &ptr_pistol_firing_animation_group3,
    &ptr_pistol_firing_animation_group3, &ptr_pistol_firing_animation_group3,
    &ptr_pistol_firing_animation_group3, &ptr_pistol_firing_animation_group3,
    &ptr_pistol_firing_animation_group4, &ptr_pistol_firing_animation_group4,
    &ptr_pistol_firing_animation_group4, &ptr_pistol_firing_animation_group4,
    &ptr_pistol_firing_animation_group4, &ptr_pistol_firing_animation_group4,
    &ptr_pistol_firing_animation_group5, &ptr_pistol_firing_animation_group5,
    &ptr_pistol_firing_animation_group5, &ptr_pistol_firing_animation_group5,
    &ptr_pistol_firing_animation_group5, &ptr_pistol_firing_animation_group5,
    &ptr_pistol_firing_animation_group6, &ptr_pistol_firing_animation_group6,
    &ptr_pistol_firing_animation_group6, &ptr_pistol_firing_animation_group6,
    &ptr_pistol_firing_animation_group6, &ptr_pistol_firing_animation_group2,
    &ptr_pistol_firing_animation_group2, &ptr_pistol_firing_animation_group2,
    &ptr_pistol_firing_animation_group1, &ptr_pistol_firing_animation_group1};

struct weapon_firing_animation_table doubles_firing_animation_group1[] = {
    {0x8E1C, 26.0, 0, 0, 7.0, 92.0, 28.0, 68.0, -1.0, -1.0, 11.0, 73.0,
     0.87266463, -0.69813174, 0.69813174, -0.69813174, 0.0, 0.0},
    {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
     0.0, 0.0}};

void *ptr_doubles_firing_animation_group1[] = {doubles_firing_animation_group1,
                                               ((void *)-1)};

struct weapon_firing_animation_table doubles_firing_animation_group2[] = {
    {0x8F2C, 26.0, 0, 1.5707964, 9.0, 112.0, 38.0, 87.0, -1.0, -1.0, 19.0, 98.0,
     0.87266463, -0.69813174, 0.43633232, -0.43633232, 0.0, 0.0},
    {0x9194, 25.0, 0, 1.5707964, 10.0, 112.0, 32.0, 86.0, -1.0, -1.0, 19.0,
     97.0, 0.87266463, -0.69813174, 0.43633232, -0.43633232, 0.0, 0.0},
    {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
     0.0, 0.0}};

void *ptr_doubles_firing_animation_group2[] = {doubles_firing_animation_group2,
                                               ((void *)-1)};

struct weapon_firing_animation_table doubles_firing_animation_group3[] = {
    {0x9084, 39.0, 0, 4.712389, 22.0, 127.0, 44.0, 102.0, -1.0, -1.0, 28.0,
     112.0, 0.87266463, -0.69813174, 0.43633232, -0.43633232, 0.0, 0.0},
    {0x92EC, 39.0, 0, 4.712389, 23.0, 130.0, 46.0, 100.0, -1.0, -1.0, 30.0,
     110.0, 0.87266463, -0.69813174, 0.43633232, -0.43633232, 0.0, 0.0},
    {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
     0.0, 0.0}};

void *ptr_doubles_firing_animation_group3[] = {doubles_firing_animation_group3,
                                               ((void *)-1)};

void *ptr_doubles_firing_animation_groups[] = {
    &ptr_doubles_firing_animation_group1, &ptr_doubles_firing_animation_group1,
    &ptr_doubles_firing_animation_group1, &ptr_doubles_firing_animation_group1,
    &ptr_doubles_firing_animation_group1, &ptr_doubles_firing_animation_group2,
    &ptr_doubles_firing_animation_group2, &ptr_doubles_firing_animation_group2,
    &ptr_doubles_firing_animation_group2, &ptr_doubles_firing_animation_group2,
    &ptr_doubles_firing_animation_group2, &ptr_doubles_firing_animation_group2,
    &ptr_doubles_firing_animation_group2, &ptr_doubles_firing_animation_group2,
    &ptr_doubles_firing_animation_group2, &ptr_doubles_firing_animation_group2,
    &ptr_doubles_firing_animation_group3, &ptr_doubles_firing_animation_group3,
    &ptr_doubles_firing_animation_group3, &ptr_doubles_firing_animation_group3,
    &ptr_doubles_firing_animation_group3, &ptr_doubles_firing_animation_group3,
    &ptr_doubles_firing_animation_group3, &ptr_doubles_firing_animation_group3,
    &ptr_doubles_firing_animation_group3, &ptr_doubles_firing_animation_group3,
    &ptr_doubles_firing_animation_group3, &ptr_doubles_firing_animation_group1,
    &ptr_doubles_firing_animation_group1, &ptr_doubles_firing_animation_group1,
    &ptr_doubles_firing_animation_group1, &ptr_doubles_firing_animation_group1};

struct weapon_firing_animation_table crouched_rifle_firing_animation_group1[] =
    {
        {0x990, 27.0, 0, 0, 0, -1.0, 35.0, 75.0, -1.0, -1.0, 31.0, 75.0,
         0.87266463, -0.69813174, 0.90757126, -0.69813174, 1.5, 1.5},
};

struct weapon_firing_animation_table crouched_rifle_firing_animation_groupA[] =
    {{0xB84, 24.0, 0, 0, 0, -1.0, 46.0, 98.0, -1.0, -1.0, 41.0, 98.0,
      0.87266463, -0.52359879, 1.134464, -0.69813174, 1.6, 1.6},
     {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0}};

void *ptr_crouched_rifle_firing_animation_group1[] = {
    &crouched_rifle_firing_animation_group1, ((void *)-1)};

struct weapon_firing_animation_table crouched_rifle_firing_animation_group2[] =
    {{0xDB4, 26.0, 0, 0, 0, -1.0, 34.0, 87.0, -1.0, -1.0, 29.0, 87.0,
      0.87266463, -0.52359879, 0.69813174, -0.95993108, 1.6, 2.0},
     {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0}};

void *ptr_crouched_rifle_firing_animation_group2[] = {
    &crouched_rifle_firing_animation_group2, ((void *)-1)};

struct weapon_firing_animation_table crouched_rifle_firing_animation_group3[] =
    {{0x1028, 28.0, 0, 0, 0, -1.0, 36.0, 88.0, -1.0, -1.0, 31.0, 88.0,
      0.87266463, -0.69813174, 0.87266463, -0.43633232, 1.6, 1.5},
     {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0}};

void *ptr_crouched_rifle_firing_animation_group3[] = {
    &crouched_rifle_firing_animation_group3, ((void *)-1)};

void *ptr_crouched_rifle_firing_animation_groups[] = {
    &ptr_crouched_rifle_firing_animation_group1,
    &ptr_crouched_rifle_firing_animation_group1,
    &ptr_crouched_rifle_firing_animation_group1,
    &ptr_crouched_rifle_firing_animation_group1,
    &ptr_crouched_rifle_firing_animation_group1,
    &ptr_crouched_rifle_firing_animation_group1,
    &ptr_crouched_rifle_firing_animation_group1,
    &ptr_crouched_rifle_firing_animation_group1,
    &ptr_crouched_rifle_firing_animation_group1,
    &ptr_crouched_rifle_firing_animation_group1,
    &ptr_crouched_rifle_firing_animation_group2,
    &ptr_crouched_rifle_firing_animation_group2,
    &ptr_crouched_rifle_firing_animation_group2,
    &ptr_crouched_rifle_firing_animation_group2,
    &ptr_crouched_rifle_firing_animation_group2,
    &ptr_crouched_rifle_firing_animation_group2,
    &ptr_crouched_rifle_firing_animation_group3,
    &ptr_crouched_rifle_firing_animation_group3,
    &ptr_crouched_rifle_firing_animation_group3,
    &ptr_crouched_rifle_firing_animation_group3,
    &ptr_crouched_rifle_firing_animation_group3,
    &ptr_crouched_rifle_firing_animation_group3,
    &ptr_crouched_rifle_firing_animation_group1,
    &ptr_crouched_rifle_firing_animation_group1,
    &ptr_crouched_rifle_firing_animation_group1,
    &ptr_crouched_rifle_firing_animation_group1,
    &ptr_crouched_rifle_firing_animation_group1,
    &ptr_crouched_rifle_firing_animation_group1,
    &ptr_crouched_rifle_firing_animation_group1,
    &ptr_crouched_rifle_firing_animation_group1,
    &ptr_crouched_rifle_firing_animation_group1,
    &ptr_crouched_rifle_firing_animation_group1};

struct weapon_firing_animation_table crouched_pistol_firing_animation_group1[] =
    {{0x6C18, 25.0, 0, 0, 12.0, 132.0, 55.0, 87.0, 67.0, 87.0, 26.0, 111.0,
      0.87266463, -0.69813174, 0.61086529, -0.78539819, 0.0, 0.0},
     {0x6D50, 26.0, 0, 0, 8.0, 89.0, 31.0, 63.0, 41.0, 51.0, 21.0, 80.0,
      0.87266463, -0.69813174, 0.34906587, -1.134464, 0.0, 0.0},
     {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0}};

void *ptr_crouched_pistol_firing_animation_group1[] = {
    &crouched_pistol_firing_animation_group1, ((void *)-1)};

struct weapon_firing_animation_table crouched_pistol_firing_animation_group2[] =
    {{0x71D0, 47.0, 0, 1.5707964, 7.0, 128.0, 33.0, 86.0, 47.0, 74.0, 23.0,
      106.0, 0.87266463, -0.52359879, 0.52359879, -0.78539819, 0.0, 0.0},
     {0x7304, 18.0, 0, 1.5707964, 7.0, 78.0, 28.0, 52.0, 35.0, 45.0, 15.0, 66.0,
      0.87266463, -0.087266468, 0.69813174, -0.78539819, 1.5, 1.0},
     {0x7430, 20.0, 0, 1.5707964, 13.0, 92.0, 37.0, 67.0, 42.0, 55.0, 25.0,
      84.0, 0.87266463, -0.52359879, 0.34906587, -0.69813174, 0.0, 0.0},
     {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0}};

void *ptr_crouched_pistol_firing_animation_group2[] = {
    &crouched_pistol_firing_animation_group2, ((void *)-1)};

struct weapon_firing_animation_table crouched_pistol_firing_animation_group3[] =
    {{0x6F08, 28.0, 0, 4.712389, 15.0, 124.0, 38.0, 97.0, 60.0, 84.0, 20.0,
      106.0, 0.87266463, -0.69813174, 0.52359879, -0.87266463, 0.0, 0.0},
     {0x700C, 23.0, 0, 4.712389, 0, 85.0, 32.0, 38.0, 38.0, 60.0, 14.0, 71.0,
      0.87266463, -0.69813174, 0.61086529, -0.95993108, 0.0, 0.0},
     {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0}};

void *ptr_crouched_pistol_firing_animation_group3[] = {
    &crouched_pistol_firing_animation_group3, ((void *)-1)};

void *ptr_crouched_pistol_firing_animation_groups[] = {
    &ptr_crouched_pistol_firing_animation_group1,
    &ptr_crouched_pistol_firing_animation_group1,
    &ptr_crouched_pistol_firing_animation_group1,
    &ptr_crouched_pistol_firing_animation_group1,
    &ptr_crouched_pistol_firing_animation_group1,
    &ptr_crouched_pistol_firing_animation_group1,
    &ptr_crouched_pistol_firing_animation_group1,
    &ptr_crouched_pistol_firing_animation_group1,
    &ptr_crouched_pistol_firing_animation_group1,
    &ptr_crouched_pistol_firing_animation_group1,
    &ptr_crouched_pistol_firing_animation_group2,
    &ptr_crouched_pistol_firing_animation_group2,
    &ptr_crouched_pistol_firing_animation_group2,
    &ptr_crouched_pistol_firing_animation_group2,
    &ptr_crouched_pistol_firing_animation_group2,
    &ptr_crouched_pistol_firing_animation_group2,
    &ptr_crouched_pistol_firing_animation_group3,
    &ptr_crouched_pistol_firing_animation_group3,
    &ptr_crouched_pistol_firing_animation_group3,
    &ptr_crouched_pistol_firing_animation_group3,
    &ptr_crouched_pistol_firing_animation_group3,
    &ptr_crouched_pistol_firing_animation_group3,
    &ptr_crouched_pistol_firing_animation_group1,
    &ptr_crouched_pistol_firing_animation_group1,
    &ptr_crouched_pistol_firing_animation_group1,
    &ptr_crouched_pistol_firing_animation_group1,
    &ptr_crouched_pistol_firing_animation_group1,
    &ptr_crouched_pistol_firing_animation_group1,
    &ptr_crouched_pistol_firing_animation_group1,
    &ptr_crouched_pistol_firing_animation_group1,
    &ptr_crouched_pistol_firing_animation_group1,
    &ptr_crouched_pistol_firing_animation_group1};

struct weapon_firing_animation_table
    crouched_doubles_firing_animation_group1[] = {
        {0x8698, 22.0, 0, 0, 10.0, 111.0, 34.0, 87.0, -1.0, -1.0, 17.0, 104.0,
         0.87266463, -0.69813174, 0.61086529, -0.78539819, 0.0, 0.0},
        {0x8AAC, 25.0, 0, 0, 9.0, 92.0, 33.0, 62.0, -1.0, -1.0, 18.0, 69.0,
         0.87266463, -0.69813174, 0.61086529, -0.78539819, 0.0, 0.0},
        {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
         0.0, 0.0, 0.0}};

void *ptr_crouched_doubles_firing_animation_group1[] = {
    &crouched_doubles_firing_animation_group1, ((void *)-1)};

struct weapon_firing_animation_table
    crouched_doubles_firing_animation_group2[] = {
        {0x8800, 28.0, 0, 1.5707964, 15.0, 108.0, 34.0, 73.0, -1.0, -1.0, 17.0,
         93.0, 0.87266463, -0.69813174, 0.52359879, -0.78539819, 0.0, 0.0},
        {0x8BF0, 19.0, 0, 1.5707964, 3.0, 95.0, 30.0, 64.0, -1.0, -1.0, 14.0,
         71.0, 0.87266463, -0.69813174, 0.52359879, -0.78539819, 1.5, 1.0},
        {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
         0.0, 0.0, 0.0}};

void *ptr_crouched_doubles_firing_animation_group2[] = {
    &crouched_doubles_firing_animation_group2, ((void *)-1)};

struct weapon_firing_animation_table
    crouched_doubles_firing_animation_group3[] = {
        {0x8978, 31.0, 0, 4.712389, 14.0, 111.0, 40.0, 83.0, -1.0, -1.0, 21.0,
         94.0, 0.87266463, -0.69813174, 0.52359879, -0.78539819, 0.0, 0.0},
        {0x8D28, 26.0, 0, 4.712389, 7.0, 89.0, 34.0, 60.0, -1.0, -1.0, 20.0,
         68.0, 0.87266463, -0.69813174, 0.52359879, -0.78539819, 0.0, 0.0},
        {0, 0.0, 0, 0, 0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
         0.0, 0.0, 0.0}};

void *ptr_crouched_doubles_firing_animation_group3[] = {
    &crouched_doubles_firing_animation_group3, ((void *)-1)};

void *ptr_crouched_doubles_firing_animation_groups[] = {
    &ptr_crouched_doubles_firing_animation_group1,
    &ptr_crouched_doubles_firing_animation_group1,
    &ptr_crouched_doubles_firing_animation_group1,
    &ptr_crouched_doubles_firing_animation_group1,
    &ptr_crouched_doubles_firing_animation_group1,
    &ptr_crouched_doubles_firing_animation_group1,
    &ptr_crouched_doubles_firing_animation_group1,
    &ptr_crouched_doubles_firing_animation_group1,
    &ptr_crouched_doubles_firing_animation_group1,
    &ptr_crouched_doubles_firing_animation_group1,
    &ptr_crouched_doubles_firing_animation_group2,
    &ptr_crouched_doubles_firing_animation_group2,
    &ptr_crouched_doubles_firing_animation_group2,
    &ptr_crouched_doubles_firing_animation_group2,
    &ptr_crouched_doubles_firing_animation_group2,
    &ptr_crouched_doubles_firing_animation_group2,
    &ptr_crouched_doubles_firing_animation_group3,
    &ptr_crouched_doubles_firing_animation_group3,
    &ptr_crouched_doubles_firing_animation_group3,
    &ptr_crouched_doubles_firing_animation_group3,
    &ptr_crouched_doubles_firing_animation_group3,
    &ptr_crouched_doubles_firing_animation_group3,
    &ptr_crouched_doubles_firing_animation_group1,
    &ptr_crouched_doubles_firing_animation_group1,
    &ptr_crouched_doubles_firing_animation_group1,
    &ptr_crouched_doubles_firing_animation_group1,
    &ptr_crouched_doubles_firing_animation_group1,
    &ptr_crouched_doubles_firing_animation_group1,
    &ptr_crouched_doubles_firing_animation_group1,
    &ptr_crouched_doubles_firing_animation_group1,
    &ptr_crouched_doubles_firing_animation_group1,
    &ptr_crouched_doubles_firing_animation_group1};

struct weapon_firing_animation_table D_80030078 = {
    0x1334,     76.0,        0.0,        0.0,         20.0, -1.0,
    98.0,       161.0,       -1.0,       -1.0,        93.0, 161.0,
    0.87266463, -0.52359879, 0.69813174, -0.69813174, 1.7,  2.0};
struct weapon_firing_animation_table D_800300C0 = {
    0x1578,     58.0,        0.0,        0.0,         10.0, -1.0,
    77.0,       104.0,       -1.0,       -1.0,        72.0, 104.0,
    0.87266463, -0.34906587, 0.61086529, -0.69813174, 1.55, 1.5};
struct weapon_firing_animation_table D_80030108 = {
    0x17B4,     61.0,        0.0,        0.0,         10.0, -1.0,
    83.0,       128.0,       -1.0,       -1.0,        78.0, 128.0,
    0.87266463, -0.52359879, 0.87266463, -0.52359879, 1.2,  1.3};
struct weapon_firing_animation_table D_80030150 = {
    0x3FA0,     63.0,        0.0,        0.0,         10.0, -1.0,
    73.0,       114.0,       -1.0,       -1.0,        68.0, 114.0,
    0.87266463, -0.52359879, 0.61086529, -0.61086529, 1.65, 1.5};
struct weapon_firing_animation_table D_80030198 = {
    0x1334,     76.0,        0.0,        0.0,         20.0, 76.0,
    98.0,       161.0,       -1.0,       -1.0,        93.0, 161.0,
    0.87266463, -0.52359879, 0.69813174, -0.69813174, 1.7,  2.0};
struct weapon_firing_animation_table D_800301E0 = {
    0x1578,     58.0,        0.0,        0.0,         10.0, 63.0,
    77.0,       104.0,       -1.0,       -1.0,        72.0, 104.0,
    0.87266463, -0.34906587, 0.61086529, -0.69813174, 1.55, 1.5};
struct weapon_firing_animation_table D_80030228 = {
    0x17B4,     61.0,        0.0,        0.0,         10.0, 56.0,
    83.0,       128.0,       -1.0,       -1.0,        78.0, 128.0,
    0.87266463, -0.52359879, 0.87266463, -0.52359879, 1.2,  1.3};
struct weapon_firing_animation_table D_80030270 = {
    0x3FA0,     63.0,        0.0,        0.0,         10.0, 50.0,
    73.0,       114.0,       -1.0,       -1.0,        68.0, 114.0,
    0.87266463, -0.52359879, 0.61086529, -0.61086529, 1.65, 1.5};
struct weapon_firing_animation_table D_800302B8 = {
    0x6554,     0.0,         0.0,        0.0,         7.0,  64.0,
    19.0,       51.0,        24.0,       46.0,        14.0, 58.0,
    0.87266463, -0.69813174, 0.52359879, -0.78539819, 0.0,  0.0};
struct weapon_firing_animation_table D_80030300 = {
    0x6A18,     0.0,         0.0,        1.5707964,  14.0, 76.0,
    26.0,       31.0,        31.0,       38.0,       15.0, 49.0,
    0.87266463, -0.69813174, 0.52359879, -1.0471976, 0.0,  0.0};
struct weapon_firing_animation_table D_80030348 = {
    0x6D50,     26.0,        0.0,        0.0,       25.0, 89.0,
    41.0,       63.0,        41.0,       51.0,      21.0, 80.0,
    0.87266463, -0.69813174, 0.34906587, -1.134464, 0.0,  0.0};
struct weapon_firing_animation_table D_80030390 = {
    0x7304,     18.0,         0.0,        1.5707964,   11.0, 78.0,
    33.0,       52.0,         35.0,       45.0,        15.0, 66.0,
    0.87266463, -0.087266468, 0.69813174, -0.78539819, 1.5,  1.0};
struct weapon_firing_animation_table D_800303D8 = {
    0x8E1C,     26.0,        0.0,        0.0,         7.0,  92.0,
    28.0,       68.0,        -1.0,       -1.0,        11.0, 73.0,
    0.87266463, -0.69813174, 0.69813174, -0.69813174, 0.0,  0.0};
struct weapon_firing_animation_table D_80030420 = {
    0x8F2C,     26.0,        0.0,        1.5707964,   9.0,  112.0,
    38.0,       87.0,        -1.0,       -1.0,        19.0, 98.0,
    0.87266463, -0.69813174, 0.43633232, -0.43633232, 0.0,  0.0};
struct weapon_firing_animation_table D_80030468 = {
    0x8698,     22.0,        0.0,        0.0,         10.0, 11.0,
    34.0,       87.0,        -1.0,       -1.0,        17.0, 104.0,
    0.87266463, -0.69813174, 0.61086529, -0.78539819, 0.0,  0.0};
struct weapon_firing_animation_table D_800304B0 = {
    0x8800,     28.0,        0.0,        1.5707964,   15.0, 108.0,
    34.0,       73.0,        -1.0,       -1.0,        17.0, 93.0,
    0.87266463, -0.69813174, 0.52359879, -0.78539819, 0.0,  0.0};
struct weapon_firing_animation_table D_800304F8 = {
    0x8E1C,     26.0,        0.0,        0.0,         7.0,  92.0,
    28.0,       68.0,        -1.0,       -1.0,        11.0, 73.0,
    0.87266463, -0.69813174, 0.69813174, -0.69813174, 0.0,  0.0};
struct weapon_firing_animation_table D_80030540 = {
    0x9194,     25.0,        0.0,        1.5707964,   10.0, 112.0,
    32.0,       86.0,        -1.0,       -1.0,        19.0, 97.0,
    0.87266463, -0.69813174, 0.43633232, -0.43633232, 0.0,  0.0};
struct weapon_firing_animation_table D_80030588 = {
    0x8AAC,     25.0,        0.0,        0.0,         9.0,  92.0,
    33.0,       62.0,        -1.0,       -1.0,        18.0, 69.0,
    0.87266463, -0.69813174, 0.61086529, -0.78539819, 0.0,  0.0};
struct weapon_firing_animation_table D_800305D0 = {
    0x8BF0,     19.0,        0.0,        1.5707964,   3.0,  95.0,
    30.0,       64.0,        -1.0,       -1.0,        14.0, 71.0,
    0.87266463, -0.69813174, 0.52359879, -0.78539819, 1.5,  1.0};
struct weapon_firing_animation_table D_80030618 = {
    0,   0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0,  0.0, 0.0, 0.0};

struct weapon_firing_animation_table D_80030660 = {
    0x4574,     0.0,         0.0,        0.0,         0.0, -1.0,
    0.0,        0.0,         -1.0,       -1.0,        0.0, 0.0,
    0.87266463, -0.52359879, 0.52359879, -0.52359879, 1.4, 1.3};
struct weapon_firing_animation_table D_800306A8 = {
    0x45CC,     0.0,         0.0,        0.0,         0.0, -1.0,
    0.0,        0.0,         -1.0,       -1.0,        0.0, 0.0,
    0.87266463, -0.52359879, 0.52359879, -0.52359879, 1.1, 1.2};
struct weapon_firing_animation_table D_800306F0 = {
    0x74A4,     0.0,         0.0,        0.0,         0.0, -1.0,
    0.0,        0.0,         -1.0,       -1.0,        0.0, 0.0,
    0.87266463, -0.52359879, 0.52359879, -0.52359879, 0.0, 0.0};
struct weapon_firing_animation_table D_80030738 = {
    0x75EC,     0.0,         0.0,        0.0,         0.0, -1.0,
    0.0,        0.0,         -1.0,       -1.0,        0.0, 0.0,
    0.87266463, -0.52359879, 0.52359879, -0.52359879, 0.0, 0.0};
struct weapon_firing_animation_table D_80030780 = {
    0x8274,     0.0,         0.0,        0.0,         0.0, -1.0,
    0.0,        0.0,         -1.0,       -1.0,        0.0, 0.0,
    0.87266463, -0.52359879, 0.52359879, -0.52359879, 0.0, 0.0};
struct weapon_firing_animation_table D_800307C8 = {
    0x8340,     0.0,         0.0,        0.0,         0.0, -1.0,
    0.0,        0.0,         -1.0,       -1.0,        0.0, 0.0,
    0.87266463, -0.52359879, 0.52359879, -0.52359879, 0.0, 0.0};
struct weapon_firing_animation_table D_80030810 = {
    0x82E0,     0.0,         0.0,        0.0,         0.0, -1.0,
    0.0,        0.0,         -1.0,       -1.0,        0.0, 0.0,
    0.87266463, -0.52359879, 0.52359879, -0.52359879, 0.0, 0.0};
struct weapon_firing_animation_table D_80030858 = {
    0x83A4,     0.0,         0.0,        0.0,         0.0, -1.0,
    0.0,        0.0,         -1.0,       -1.0,        0.0, 0.0,
    0.87266463, -0.52359879, 0.52359879, -0.52359879, 0.0, 0.0};
struct weapon_firing_animation_table D_800308A0 = {
    0x76B8,     0.0,         0.0,        1.5707964,   0.0, -1.0,
    0.0,        0.0,         -1.0,       -1.0,        0.0, 0.0,
    0.87266463, -0.52359879, 0.52359879, -0.52359879, 0.0, 0.0};
struct weapon_firing_animation_table D_800308E8 = {
    0x7650,     0.0,         0.0,        4.712389,    0.0, -1.0,
    0.0,        0.0,         -1.0,       -1.0,        0.0, 0.0,
    0.87266463, -0.52359879, 0.52359879, -0.52359879, 0.0, 0.0};
struct weapon_firing_animation_table D_80030930 = {
    0,   0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0,  0.0, 0.0, 0.0};

int objectiveregisters1 = 0;
int objectiveregisters2 = 0;
int objectiveregisters3 = 0;
int D_80030984 = 0;
int D_80030988 = 0;
int D_8003098C = 0;
int D_80030990 = 0;
int D_80030994 = 0;
int D_80030998 = 0;
int D_8003099C = 0;
int D_800309A0 = 0;
int D_800309A4 = 0;
int D_800309A8 = 0;
int D_800309AC = 0;
int D_800309B0 = 0;
int D_800309B4 = 0;
int D_800309B8 = 0;
int D_800309BC = 0;
int D_800309C0 = 0;
int D_800309C4 = 0;
int D_800309C8 = 0;
int D_800309CC = 0;
int D_800309D0 = 0;
int D_800309D4 = 0;
int D_800309D8 = 0;
int D_800309DC = 0;
int D_800309E0 = 0;
int D_800309E4 = 0;
int D_800309E8 = 0;
int D_800309EC = 0;
int D_800309F0 = 0;
int D_800309F4 = 0;

short male_guard_yelps[] = {0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C,
                            0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93,
                            0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A,
                            0x9B, 0x9C, 0x9D, 0x9E, 0};

short female_guard_yelps[] = {0xD, 0xE, 0xF, 0};

int male_guard_yelp_counter = 0;
int female_guard_yelp_counter = 0;

short metal_ricochet_SFX[] = {0xEF, 0x48, 0x49};

int D_80030A44 = 0;
int D_80030A48 = 0;
int D_80030A4C = 0;

short body_hit_SFX[] = {0x7B, 0x7C, 0x7D, 0x7E, 0x7F, 0x80,
                        0x81, 0x82, 0x83, 0x84, 0x85};

int D_80030A68 = 0;

int get_numguards(void) { return num_guards; }

void get_ptr_allocated_block_for_vertices(int param_1) {
  sub_GAME_7F0BD714(param_1 << 4);
}

void set_show_patrols_flag(int flag) { show_patrols_flag = flag; }

int get_show_patrols_flag(void) { return show_patrols_flag; }

asm(R"
glabel sub_GAME_7F01F574
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  lw    $t6, 0x14($a0)
  move  $s0, $a0
  addiu $a0, $a0, 0x14
  beqz  $t6, .L7F01F5CC
   lui   $a3, 0x3f80
  lw    $a1, 8($s0)
  jal   sub_GAME_7F0B20D0
   lw    $a2, 0x10($s0)
  bgezl $v0, .L7F01F5C4
   mtc1  $zero, $f0
  lw    $a0, 0x14($s0)
  lw    $a1, 8($s0)
  jal   sub_GAME_7F0B2970
   lw    $a2, 0x10($s0)
  b     .L7F01F5D8
   lw    $ra, 0x1c($sp)
  mtc1  $zero, $f0
.L7F01F5C4:
  b     .L7F01F5D8
   lw    $ra, 0x1c($sp)
.L7F01F5CC:
  mtc1  $zero, $f0
  nop   
  lw    $ra, 0x1c($sp)
.L7F01F5D8:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel set_or_unset_GUARDdata_flag
  beql  $a1, $zero, .L7F01F604
   lhu   $t8, 0x12($a0)
  lhu   $t6, 0x12($a0)
  andi  $t7, $t6, 0xfeff
  jr    $ra
   sh    $t7, 0x12($a0)

  lhu   $t8, 0x12($a0)
.L7F01F604:
  ori   $t9, $t8, 0x100
  sh    $t9, 0x12($a0)
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F01F614
  addiu $sp, $sp, -0x98
  sw    $s1, 0x30($sp)
  sw    $s0, 0x2c($sp)
  move  $s0, $a2
  move  $s1, $a3
  sw    $ra, 0x34($sp)
  sw    $a0, 0x98($sp)
  sw    $a1, 0x9c($sp)
  sw    $zero, 0x94($sp)
  sw    $a1, 0x90($sp)
  lw    $a0, 0x18($a0)
  addiu $a1, $sp, 0x84
  addiu $a3, $sp, 0x88
  jal   sub_GAME_7F023160
   addiu $a2, $sp, 0x8c
  lw    $a0, 0x98($sp)
  jal   set_or_unset_GUARDdata_flag
   move  $a1, $zero
  jal   sub_GAME_7F0B1CC4
   nop   
  lwc1  $f4, 8($s1)
  lw    $a1, ($s0)
  lw    $a2, 8($s0)
  lw    $a3, ($s1)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f16
  lwc1  $f6, 0x8c($sp)
  lwc1  $f8, 0x88($sp)
  mtc1  $zero, $f10
  li    $t8, 31
  sw    $t8, 0x14($sp)
  addiu $a0, $sp, 0x90
  swc1  $f4, 0x10($sp)
  swc1  $f6, 0x18($sp)
  swc1  $f16, 0x24($sp)
  swc1  $f8, 0x1c($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f10, 0x20($sp)
  beqz  $v0, .L7F01F708
   addiu $a0, $sp, 0x90
  lwc1  $f18, 0x8c($sp)
  lwc1  $f4, 0x88($sp)
  lw    $a1, ($s1)
  lw    $a2, 8($s1)
  li    $t9, 31
  sw    $t9, 0x10($sp)
  lw    $a3, 0x84($sp)
  swc1  $f18, 0x14($sp)
  jal   sub_GAME_7F0B18B8
   swc1  $f4, 0x18($sp)
  bgez  $v0, .L7F01F708
   lw    $t0, 0xa8($sp)
  beqz  $t0, .L7F01F6FC
   lw    $t1, 0x98($sp)
  sb    $zero, 9($t1)
  lui   $t2, %hi(global_timer) 
  lw    $t2, %lo(global_timer)($t2)
  sw    $t2, 0xcc($t1)
.L7F01F6FC:
  lw    $t3, 0x90($sp)
  b     .L7F01FBD8
   sw    $t3, 0x94($sp)
.L7F01F708:
  sw    $zero, 0x4c($sp)
  addiu $a0, $sp, 0x78
  jal   sub_GAME_7F0B28B0
   addiu $a1, $sp, 0x6c
  beql  $v0, $zero, .L7F01FBDC
   lw    $a0, 0x98($sp)
  lwc1  $f6, ($s1)
  lwc1  $f8, ($s0)
  sub.s $f10, $f6, $f8
  lwc1  $f8, 0x6c($sp)
  lwc1  $f6, 0x78($sp)
  swc1  $f10, 0x60($sp)
  lwc1  $f18, 8($s0)
  lwc1  $f16, 8($s1)
  c.eq.s $f6, $f8
  lwc1  $f10, 0x80($sp)
  sub.s $f4, $f16, $f18
  lwc1  $f16, 0x74($sp)
  bc1f  .L7F01F768
   swc1  $f4, 0x68($sp)
  c.eq.s $f10, $f16
  nop   
  bc1tl .L7F01F804
   lw    $t6, 0x4c($sp)
.L7F01F768:
  lwc1  $f6, 0x74($sp)
  lwc1  $f8, 0x80($sp)
  lwc1  $f18, 0x6c($sp)
  lwc1  $f4, 0x78($sp)
  sub.s $f2, $f6, $f8
  li    $t4, 1
  sw    $t4, 0x4c($sp)
  sub.s $f0, $f18, $f4
  mul.s $f10, $f2, $f2
  swc1  $f2, 0x5c($sp)
  mul.s $f16, $f0, $f0
  swc1  $f0, 0x54($sp)
  jal   sqrtf
   add.s $f12, $f10, $f16
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f18
  lwc1  $f4, 0x54($sp)
  lwc1  $f8, 0x5c($sp)
  div.s $f2, $f18, $f0
  lwc1  $f16, 0x68($sp)
  lw    $t5, 0x9c($sp)
  mul.s $f6, $f4, $f2
  lwc1  $f4, 0x60($sp)
  mul.s $f10, $f8, $f2
  swc1  $f6, 0x54($sp)
  mul.s $f18, $f10, $f16
  swc1  $f10, 0x5c($sp)
  mul.s $f8, $f4, $f6
  lwc1  $f4, ($s0)
  add.s $f12, $f18, $f8
  mul.s $f16, $f6, $f12
  add.s $f18, $f16, $f4
  mul.s $f8, $f10, $f12
  swc1  $f18, 0x40($sp)
  lwc1  $f6, 8($s0)
  sw    $t5, 0x90($sp)
  add.s $f16, $f8, $f6
  swc1  $f16, 0x48($sp)
  lw    $t6, 0x4c($sp)
.L7F01F804:
  addiu $a0, $sp, 0x90
  lw    $a3, 0x40($sp)
  beqz  $t6, .L7F01F8AC
   lwc1  $f4, 0x48($sp)
  lw    $a1, ($s0)
  lw    $a2, 8($s0)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  lwc1  $f18, 0x8c($sp)
  lwc1  $f10, 0x88($sp)
  mtc1  $zero, $f8
  li    $t7, 31
  sw    $t7, 0x14($sp)
  swc1  $f4, 0x10($sp)
  swc1  $f18, 0x18($sp)
  swc1  $f6, 0x24($sp)
  swc1  $f10, 0x1c($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f8, 0x20($sp)
  beqz  $v0, .L7F01F8AC
   addiu $a0, $sp, 0x90
  lwc1  $f16, 0x8c($sp)
  lwc1  $f4, 0x88($sp)
  li    $t8, 31
  sw    $t8, 0x10($sp)
  lw    $a1, 0x40($sp)
  lw    $a2, 0x48($sp)
  lw    $a3, 0x84($sp)
  swc1  $f16, 0x14($sp)
  jal   sub_GAME_7F0B18B8
   swc1  $f4, 0x18($sp)
  bgez  $v0, .L7F01F8AC
   lwc1  $f18, 0x40($sp)
  swc1  $f18, ($s1)
  lwc1  $f10, 0x48($sp)
  li    $t9, 2
  swc1  $f10, 8($s1)
  lw    $t0, 0x98($sp)
  sb    $t9, 9($t0)
  lw    $t2, 0x90($sp)
  b     .L7F01FBD8
   sw    $t2, 0x94($sp)
.L7F01F8AC:
  lwc1  $f8, 0x78($sp)
  lwc1  $f6, ($s1)
  lwc1  $f4, 0x80($sp)
  sub.s $f16, $f8, $f6
  lwc1  $f6, 0x84($sp)
  swc1  $f16, 0x54($sp)
  lwc1  $f18, 8($s1)
  mul.s $f0, $f6, $f6
  sub.s $f10, $f4, $f18
  mul.s $f18, $f10, $f10
  swc1  $f10, 0x5c($sp)
  mul.s $f6, $f16, $f16
  lwc1  $f16, 0x6c($sp)
  add.s $f10, $f18, $f6
  c.le.s $f10, $f0
  nop   
  bc1fl .L7F01FA50
   lwc1  $f6, ($s1)
  lwc1  $f16, ($s0)
  lwc1  $f6, 0x80($sp)
  c.eq.s $f8, $f16
  nop   
  bc1fl .L7F01F924
   lwc1  $f10, 8($s0)
  lwc1  $f18, 8($s0)
  c.eq.s $f4, $f18
  nop   
  bc1tl .L7F01FBDC
   lw    $a0, 0x98($sp)
  lwc1  $f10, 8($s0)
.L7F01F924:
  lwc1  $f4, 0x78($sp)
  sub.s $f8, $f6, $f10
  neg.s $f16, $f8
  swc1  $f16, 0x54($sp)
  lwc1  $f18, ($s0)
  sub.s $f6, $f4, $f18
  mul.s $f10, $f6, $f6
  swc1  $f6, 0x5c($sp)
  mul.s $f8, $f16, $f16
  jal   sqrtf
   add.s $f12, $f10, $f8
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  lwc1  $f18, 0x54($sp)
  lwc1  $f16, 0x5c($sp)
  div.s $f2, $f4, $f0
  lwc1  $f8, 0x68($sp)
  lw    $t1, 0x9c($sp)
  li    $t3, 31
  addiu $a0, $sp, 0x90
  mul.s $f6, $f18, $f2
  lwc1  $f18, 0x60($sp)
  mul.s $f10, $f16, $f2
  swc1  $f6, 0x54($sp)
  mul.s $f4, $f10, $f8
  swc1  $f10, 0x5c($sp)
  mul.s $f16, $f18, $f6
  lwc1  $f18, ($s0)
  add.s $f12, $f4, $f16
  mul.s $f8, $f6, $f12
  add.s $f4, $f8, $f18
  mul.s $f16, $f10, $f12
  lwc1  $f10, 0x88($sp)
  lwc1  $f18, 0x8c($sp)
  swc1  $f4, 0x40($sp)
  lwc1  $f6, 8($s0)
  sw    $t1, 0x90($sp)
  mfc1  $a3, $f4
  add.s $f8, $f16, $f6
  mtc1  $at, $f6
  mtc1  $zero, $f16
  swc1  $f8, 0x48($sp)
  lw    $a2, 8($s0)
  lw    $a1, ($s0)
  sw    $t3, 0x14($sp)
  swc1  $f8, 0x10($sp)
  swc1  $f10, 0x1c($sp)
  swc1  $f18, 0x18($sp)
  swc1  $f6, 0x24($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f16, 0x20($sp)
  beqz  $v0, .L7F01FBD8
   addiu $a0, $sp, 0x90
  lwc1  $f4, 0x8c($sp)
  lwc1  $f8, 0x88($sp)
  li    $t4, 31
  sw    $t4, 0x10($sp)
  lw    $a1, 0x40($sp)
  lw    $a2, 0x48($sp)
  lw    $a3, 0x84($sp)
  swc1  $f4, 0x14($sp)
  jal   sub_GAME_7F0B18B8
   swc1  $f8, 0x18($sp)
  bgez  $v0, .L7F01FBD8
   lwc1  $f18, 0x40($sp)
  swc1  $f18, ($s1)
  lwc1  $f10, 0x48($sp)
  li    $t5, 2
  swc1  $f10, 8($s1)
  lw    $t6, 0x98($sp)
  sb    $t5, 9($t6)
  lw    $t7, 0x90($sp)
  b     .L7F01FBD8
   sw    $t7, 0x94($sp)
  lwc1  $f6, ($s1)
.L7F01FA50:
  lwc1  $f8, 0x74($sp)
  sub.s $f4, $f16, $f6
  swc1  $f4, 0x54($sp)
  lwc1  $f18, 8($s1)
  sub.s $f10, $f8, $f18
  mul.s $f6, $f10, $f10
  swc1  $f10, 0x5c($sp)
  mul.s $f18, $f4, $f4
  add.s $f10, $f6, $f18
  c.le.s $f10, $f0
  nop   
  bc1fl .L7F01FBDC
   lw    $a0, 0x98($sp)
  lwc1  $f4, ($s0)
  lwc1  $f18, 0x74($sp)
  c.eq.s $f16, $f4
  nop   
  bc1fl .L7F01FAB4
   lwc1  $f10, 8($s0)
  lwc1  $f6, 8($s0)
  c.eq.s $f8, $f6
  nop   
  bc1tl .L7F01FBDC
   lw    $a0, 0x98($sp)
  lwc1  $f10, 8($s0)
.L7F01FAB4:
  lwc1  $f8, 0x6c($sp)
  sub.s $f16, $f18, $f10
  neg.s $f4, $f16
  swc1  $f4, 0x54($sp)
  lwc1  $f6, ($s0)
  sub.s $f18, $f8, $f6
  mul.s $f10, $f18, $f18
  swc1  $f18, 0x5c($sp)
  mul.s $f16, $f4, $f4
  jal   sqrtf
   add.s $f12, $f10, $f16
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  lwc1  $f6, 0x54($sp)
  lwc1  $f4, 0x5c($sp)
  div.s $f2, $f8, $f0
  lwc1  $f16, 0x68($sp)
  lw    $t8, 0x9c($sp)
  li    $t9, 31
  addiu $a0, $sp, 0x90
  mul.s $f18, $f6, $f2
  lwc1  $f6, 0x60($sp)
  mul.s $f10, $f4, $f2
  swc1  $f18, 0x54($sp)
  mul.s $f8, $f10, $f16
  swc1  $f10, 0x5c($sp)
  mul.s $f4, $f6, $f18
  lwc1  $f6, ($s0)
  add.s $f12, $f8, $f4
  mul.s $f16, $f18, $f12
  add.s $f8, $f16, $f6
  mul.s $f4, $f10, $f12
  lwc1  $f10, 0x88($sp)
  lwc1  $f6, 0x8c($sp)
  swc1  $f8, 0x40($sp)
  lwc1  $f18, 8($s0)
  sw    $t8, 0x90($sp)
  mfc1  $a3, $f8
  add.s $f16, $f4, $f18
  mtc1  $at, $f18
  mtc1  $zero, $f4
  swc1  $f16, 0x48($sp)
  lw    $a2, 8($s0)
  lw    $a1, ($s0)
  sw    $t9, 0x14($sp)
  swc1  $f16, 0x10($sp)
  swc1  $f10, 0x1c($sp)
  swc1  $f6, 0x18($sp)
  swc1  $f18, 0x24($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f4, 0x20($sp)
  beqz  $v0, .L7F01FBD8
   addiu $a0, $sp, 0x90
  lwc1  $f8, 0x8c($sp)
  lwc1  $f16, 0x88($sp)
  li    $t0, 31
  sw    $t0, 0x10($sp)
  lw    $a1, 0x40($sp)
  lw    $a2, 0x48($sp)
  lw    $a3, 0x84($sp)
  swc1  $f8, 0x14($sp)
  jal   sub_GAME_7F0B18B8
   swc1  $f16, 0x18($sp)
  bgez  $v0, .L7F01FBD8
   lwc1  $f6, 0x40($sp)
  swc1  $f6, ($s1)
  lwc1  $f10, 0x48($sp)
  li    $t2, 2
  swc1  $f10, 8($s1)
  lw    $t1, 0x98($sp)
  sb    $t2, 9($t1)
  lw    $t3, 0x90($sp)
  sw    $t3, 0x94($sp)
.L7F01FBD8:
  lw    $a0, 0x98($sp)
.L7F01FBDC:
  jal   set_or_unset_GUARDdata_flag
   li    $a1, 1
  lw    $t4, 0x94($sp)
  lw    $t6, 0x98($sp)
  bnez  $t4, .L7F01FBF8
   li    $t5, 1
  sb    $t5, 9($t6)
.L7F01FBF8:
  lw    $ra, 0x34($sp)
  lw    $v0, 0x94($sp)
  lw    $s0, 0x2c($sp)
  lw    $s1, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x98
");

#ifdef VERSION_US
asm(R"
.late_rodata
glabel D_80051D10
.word 0x3dccccd0 /*0.10000002*/
glabel D_80051D14
.word 0x3dccccd0 /*0.10000002*/
glabel D_80051D18
.word 0x3f666666 /*0.89999998*/
glabel D_80051D1C
.word 0x3dcccccd /*0.1*/
glabel D_80051D20
.word 0x3dccccd0 /*0.10000002*/
glabel D_80051D24
.word 0xbdcccccd /*-0.1*/
glabel D_80051D28
.word 0x40c90fdb /*6.2831855*/
glabel D_80051D2C
.word 0x40c90fdb /*6.2831855*/
glabel D_80051D30
.word 0x3f860a92 /*1.0471976*/
glabel D_80051D34
.word 0xbf5f66f3 /*-0.87266463*/
glabel D_80051D38
.word 0x3f5f66f3 /*0.87266463*/
glabel D_80051D3C
.word 0x3f860a92 /*1.0471976*/
glabel D_80051D40
.word 0xbf5f66f3 /*-0.87266463*/
glabel D_80051D44
.word 0x40c90fdb /*6.2831855*/
glabel D_80051D48
.word 0x40c90fdb /*6.2831855*/
glabel D_80051D4C
.word 0x40c90fdb /*6.2831855*/
glabel D_80051D50
.word 0x40c90fdb /*6.2831855*/
glabel D_80051D54
.word 0x40c90fdb /*6.2831855*/
glabel D_80051D58
.word 0x3ca3d70a /*0.02*/
glabel D_80051D5C
.word 0x3ca3d70a /*0.02*/
glabel D_80051D60
.word 0x3ca3d70a /*0.02*/
glabel D_80051D64
.word 0x3ca3d70a /*0.02*/
glabel D_80051D68
.word 0x3ca3d70a /*0.02*/
glabel D_80051D6C
.word 0x3ca3d70a /*0.02*/
glabel D_80051D70
.word 0x3f7eb852 /*0.995*/
glabel D_80051D74
.word 0x3f80a3d7 /*1.005*/
glabel D_80051D78
.word 0x3f7eb852 /*0.995*/
glabel D_80051D7C
.word 0x3f80a3d7 /*1.005*/
glabel D_80051D80
.word 0x3f7eb852 /*0.995*/
glabel D_80051D84
.word 0x3f80a3d7 /*1.005*/
glabel D_80051D88
.word 0x41aa6666 /*21.299999*/

.text
glabel sub_GAME_7F01FC10
  addiu $sp, $sp, -0x38
  sw    $ra, 0x24($sp)
  sw    $s1, 0x20($sp)
  sw    $s0, 0x1c($sp)
  sw    $a0, 0x38($sp)
  sw    $a1, 0x3c($sp)
  sw    $a3, 0x44($sp)
  lw    $s0, 4($a0)
  sw    $zero, 0x30($sp)
  mtc1  $zero, $f12
  lw    $t7, 0x18($s0)
  move  $s1, $a2
  move  $v1, $a1
  lw    $t8, 0x14($t7)
  mov.s $f14, $f12
  beql  $t8, $zero, .L7F01FF80
   lw    $t5, 0x44($sp)
  lb    $t9, 7($s0)
  li    $at, 4
  bne   $t9, $at, .L7F01FD10
   nop   
  lwc1  $f2, 0x38($s0)
  lui   $v0, %hi(global_timer_delta)
  addiu $v0, %lo(global_timer_delta) # addiu $v0, $v0, -0x7c88
  c.lt.s $f12, $f2
  nop   
  bc1f  .L7F01FD10
   nop   
  lwc1  $f4, 0xa4($a0)
  lwc1  $f6, ($v0)
  lwc1  $f10, 0x3c($s0)
  mul.s $f8, $f4, $f6
  sub.s $f18, $f2, $f10
  lwc1  $f10, 0x40($s0)
  lwc1  $f6, ($a2)
  mul.s $f4, $f8, $f18
  div.s $f0, $f4, $f2
  lwc1  $f4, 4($a2)
  mul.s $f8, $f10, $f0
  add.s $f18, $f6, $f8
  swc1  $f18, ($a2)
  lwc1  $f10, 0x44($s0)
  lwc1  $f18, 8($a2)
  mul.s $f6, $f10, $f0
  add.s $f8, $f4, $f6
  swc1  $f8, 4($a2)
  lwc1  $f10, 0x48($s0)
  mul.s $f4, $f10, $f0
  add.s $f6, $f18, $f4
  swc1  $f6, 8($a2)
  lw    $t0, 0x38($sp)
  lwc1  $f8, ($v0)
  lwc1  $f4, 0x3c($s0)
  lwc1  $f10, 0xa4($t0)
  mul.s $f18, $f8, $f10
  lwc1  $f8, 0x38($s0)
  add.s $f6, $f4, $f18
  swc1  $f6, 0x3c($s0)
  lwc1  $f10, 0x3c($s0)
  c.lt.s $f8, $f10
  nop   
  bc1f  .L7F01FD10
   nop   
  swc1  $f12, 0x38($s0)
.L7F01FD10:
  lui   $v0, %hi(global_timer_delta)
  addiu $v0, %lo(global_timer_delta) # addiu $v0, $v0, -0x7c88
  lwc1  $f18, ($v0)
  lwc1  $f4, 0xb0($s0)
  lwc1  $f8, ($s1)
  li    $t2, 1
  mul.s $f6, $f4, $f18
  move  $a0, $s0
  move  $a3, $s1
  add.s $f10, $f8, $f6
  lwc1  $f6, 8($s1)
  swc1  $f10, ($s1)
  lwc1  $f18, ($v0)
  lwc1  $f4, 0xb8($s0)
  mul.s $f8, $f4, $f18
  add.s $f10, $f6, $f8
  swc1  $f10, 8($s1)
  lw    $t1, 0x18($s0)
  lw    $a2, 0x3c($sp)
  lw    $a1, 0x14($t1)
  sw    $v1, 0x28($sp)
  jal   sub_GAME_7F01F614
   sw    $t2, 0x10($sp)
  beqz  $v0, .L7F01FD88
   lw    $v1, 0x28($sp)
  lw    $t3, 0x18($s0)
  li    $t4, 1
  move  $v1, $s1
  sw    $v0, 0x14($t3)
  sw    $t4, 0x30($sp)
.L7F01FD88:
  lw    $t5, 0x14($s0)
  andi  $t7, $t5, 0x1000
  bnezl $t7, .L7F01FF7C
   lwc1  $f14, 0xac($s0)
  lw    $t8, 0x18($s0)
  lw    $a1, ($v1)
  lw    $a2, 8($v1)
  jal   sub_GAME_7F0B2970
   lw    $a0, 0x14($t8)
  lw    $t9, 0x14($s0)
  mtc1  $zero, $f12
  mov.s $f14, $f0
  andi  $t6, $t9, 1
  beqz  $t6, .L7F01FE10
   swc1  $f0, 0xac($s0)
  lw    $a0, 0x38($sp)
  lw    $t0, 8($a0)
  lw    $a1, ($t0)
  jal   extract_id_from_object_structure_microcode
   swc1  $f14, 0x2c($sp)
  lw    $t1, 0x14($s0)
  lwc1  $f2, 0xac($s0)
  li    $at, -2
  lwc1  $f14, 0x2c($sp)
  and   $t2, $t1, $at
  sw    $t2, 0x14($s0)
  lui   $at, %hi(D_80051D10)
  swc1  $f2, 0xa8($s0)
  lwc1  $f4, %lo(D_80051D10)($at)
  div.s $f18, $f2, $f4
  swc1  $f18, 0xa4($s0)
  lwc1  $f6, 0x28($v0)
  b     .L7F01FF60
   swc1  $f6, 0x38($v0)
.L7F01FE10:
  lwc1  $f8, 0xb4($s0)
  addiu $a0, $s0, 0xa8
  addiu $a1, $s0, 0xb4
  c.eq.s $f12, $f8
  lui   $a2, %hi(global_timer_delta)
  bc1f  .L7F01FE44
   nop   
  lwc1  $f2, 0xac($s0)
  lwc1  $f0, 0xa8($s0)
  c.lt.s $f2, $f0
  nop   
  bc1fl .L7F01FE8C
   c.le.s $f0, $f2
.L7F01FE44:
  lw    $a2, %lo(global_timer_delta)($a2)
  jal   sub_GAME_7F057D44
   swc1  $f14, 0x2c($sp)
  lwc1  $f2, 0xac($s0)
  lwc1  $f0, 0xa8($s0)
  mtc1  $zero, $f12
  lwc1  $f14, 0x2c($sp)
  c.le.s $f0, $f2
  lui   $at, %hi(D_80051D14)
  bc1fl .L7F01FE8C
   c.le.s $f0, $f2
  swc1  $f2, 0xa8($s0)
  lwc1  $f10, %lo(D_80051D14)($at)
  swc1  $f12, 0xb4($s0)
  lwc1  $f0, 0xa8($s0)
  div.s $f4, $f2, $f10
  swc1  $f4, 0xa4($s0)
  c.le.s $f0, $f2
.L7F01FE8C:
  lui   $v1, %hi(clock_timer)
  addiu $v1, %lo(clock_timer) # addiu $v1, $v1, -0x7c8c
  bc1fl .L7F01FF64
   lwc1  $f6, 0xa8($s0)
  lw    $t3, ($v1)
  move  $v0, $zero
  lui   $at, %hi(D_80051D18)
  blez  $t3, .L7F01FEF0
   nop   
  lwc1  $f0, %lo(D_80051D18)($at)
  lwc1  $f18, 0xa4($s0)
.L7F01FEB8:
  lwc1  $f10, 0xb0($s0)
  addiu $v0, $v0, 1
  mul.s $f6, $f18, $f0
  lwc1  $f18, 0xb8($s0)
  mul.s $f4, $f10, $f0
  add.s $f8, $f6, $f2
  mul.s $f6, $f18, $f0
  swc1  $f4, 0xb0($s0)
  swc1  $f8, 0xa4($s0)
  swc1  $f6, 0xb8($s0)
  lw    $t4, ($v1)
  slt   $at, $v0, $t4
  bnezl $at, .L7F01FEB8
   lwc1  $f18, 0xa4($s0)
.L7F01FEF0:
  lui   $at, %hi(D_80051D1C)
  lwc1  $f2, %lo(D_80051D1C)($at)
  lui   $at, %hi(D_80051D20)
  lwc1  $f10, %lo(D_80051D20)($at)
  lwc1  $f8, 0xa4($s0)
  lwc1  $f0, 0xb0($s0)
  lui   $at, %hi(D_80051D24)
  mul.s $f4, $f8, $f10
  c.lt.s $f0, $f2
  nop   
  bc1f  .L7F01FF60
   swc1  $f4, 0xa8($s0)
  lwc1  $f16, %lo(D_80051D24)($at)
  c.lt.s $f16, $f0
  nop   
  bc1fl .L7F01FF64
   lwc1  $f6, 0xa8($s0)
  lwc1  $f0, 0xb8($s0)
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F01FF64
   lwc1  $f6, 0xa8($s0)
  c.lt.s $f16, $f0
  nop   
  bc1fl .L7F01FF64
   lwc1  $f6, 0xa8($s0)
  swc1  $f12, 0xb8($s0)
  swc1  $f12, 0xb0($s0)
.L7F01FF60:
  lwc1  $f6, 0xa8($s0)
.L7F01FF64:
  lwc1  $f18, 4($s1)
  sub.s $f8, $f6, $f14
  add.s $f10, $f18, $f8
  b     .L7F01FF7C
   swc1  $f10, 4($s1)
  lwc1  $f14, 0xac($s0)
.L7F01FF7C:
  lw    $t5, 0x44($sp)
.L7F01FF80:
  li    $v0, 1
  swc1  $f14, ($t5)
  lw    $t7, 0x30($sp)
  lw    $t8, 0x3c($sp)
  bnezl $t7, .L7F01FFB0
   lw    $ra, 0x24($sp)
  lwc1  $f4, ($t8)
  swc1  $f4, ($s1)
  lw    $t9, 0x3c($sp)
  lwc1  $f6, 8($t9)
  swc1  $f6, 8($s1)
  lw    $ra, 0x24($sp)
.L7F01FFB0:
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x38
");
#endif

#ifdef VERSION_JP
asm(R"
.late_rodata
glabel D_80051D10
.word 0x3dccccd0 /*0.10000002*/
glabel D_80051D14
.word 0x3dccccd0 /*0.10000002*/
glabel D_80051D18
.word 0x3f666666 /*0.89999998*/
glabel D_80051D1C
.word 0x3dcccccd /*0.1*/
glabel D_80051D20
.word 0x3dccccd0 /*0.10000002*/
glabel D_80051D24
.word 0xbdcccccd /*-0.1*/
glabel D_80051D28
.word 0x40c90fdb /*6.2831855*/
glabel D_80051D2C
.word 0x40c90fdb /*6.2831855*/
glabel D_80051D30
.word 0x3f860a92 /*1.0471976*/
glabel D_80051D34
.word 0xbf5f66f3 /*-0.87266463*/
glabel D_80051D38
.word 0x3f5f66f3 /*0.87266463*/
glabel D_80051D3C
.word 0x3f860a92 /*1.0471976*/
glabel D_80051D40
.word 0xbf5f66f3 /*-0.87266463*/
glabel D_80051D44
.word 0x40c90fdb /*6.2831855*/
glabel D_80051D48
.word 0x40c90fdb /*6.2831855*/
glabel D_80051D4C
.word 0x40c90fdb /*6.2831855*/
glabel D_80051D50
.word 0x40c90fdb /*6.2831855*/
glabel D_80051D54
.word 0x40c90fdb /*6.2831855*/

glabel D_jp80051D88
.word 0x3f4ccccd

glabel D_80051D58
.word 0x3ca3d70a /*0.02*/
glabel D_80051D5C
.word 0x3ca3d70a /*0.02*/
glabel D_80051D60
.word 0x3ca3d70a /*0.02*/
glabel D_80051D64
.word 0x3ca3d70a /*0.02*/
glabel D_80051D68
.word 0x3ca3d70a /*0.02*/
glabel D_80051D6C
.word 0x3ca3d70a /*0.02*/
glabel D_80051D70
.word 0x3f7eb852 /*0.995*/
glabel D_80051D74
.word 0x3f80a3d7 /*1.005*/
glabel D_80051D78
.word 0x3f7eb852 /*0.995*/
glabel D_80051D7C
.word 0x3f80a3d7 /*1.005*/
glabel D_80051D80
.word 0x3f7eb852 /*0.995*/
glabel D_80051D84
.word 0x3f80a3d7 /*1.005*/
glabel D_80051D88
.word 0x41aa6666 /*21.299999*/

.text
glabel sub_GAME_7F01FC10
  addiu $sp, $sp, -0x38
  sw    $ra, 0x24($sp)
  sw    $s1, 0x20($sp)
  sw    $s0, 0x1c($sp)
  sw    $a0, 0x38($sp)
  sw    $a1, 0x3c($sp)
  sw    $a3, 0x44($sp)
  lw    $s0, 4($a0)
  sw    $zero, 0x30($sp)
  mtc1  $zero, $f12
  lw    $t7, 0x18($s0)
  move  $s1, $a2
  move  $v1, $a1
  lw    $t8, 0x14($t7)
  mov.s $f14, $f12
  beql  $t8, $zero, .L7F01FF80
   lw    $t5, 0x44($sp)
  lb    $t9, 7($s0)
  li    $at, 4
  bne   $t9, $at, .L7F01FD10
   nop   
  lwc1  $f2, 0x38($s0)
  lui   $v0, %hi(jp_global_timer_delta)
  addiu $v0, %lo(jp_global_timer_delta) # addiu $v0, $v0, -0x7c88
  c.lt.s $f12, $f2
  nop   
  bc1f  .L7F01FD10
   nop   
  lwc1  $f4, 0xa4($a0)
  lwc1  $f6, ($v0)
  lwc1  $f10, 0x3c($s0)
  mul.s $f8, $f4, $f6
  sub.s $f18, $f2, $f10
  lwc1  $f10, 0x40($s0)
  lwc1  $f6, ($a2)
  mul.s $f4, $f8, $f18
  div.s $f0, $f4, $f2
  lwc1  $f4, 4($a2)
  mul.s $f8, $f10, $f0
  add.s $f18, $f6, $f8
  swc1  $f18, ($a2)
  lwc1  $f10, 0x44($s0)
  lwc1  $f18, 8($a2)
  mul.s $f6, $f10, $f0
  add.s $f8, $f4, $f6
  swc1  $f8, 4($a2)
  lwc1  $f10, 0x48($s0)
  mul.s $f4, $f10, $f0
  add.s $f6, $f18, $f4
  swc1  $f6, 8($a2)
  lw    $t0, 0x38($sp)
  lwc1  $f8, ($v0)
  lwc1  $f4, 0x3c($s0)
  lwc1  $f10, 0xa4($t0)
  mul.s $f18, $f8, $f10
  lwc1  $f8, 0x38($s0)
  add.s $f6, $f4, $f18
  swc1  $f6, 0x3c($s0)
  lwc1  $f10, 0x3c($s0)
  c.lt.s $f8, $f10
  nop   
  bc1f  .L7F01FD10
   nop   
  swc1  $f12, 0x38($s0)
.L7F01FD10:
  lui   $v0, %hi(global_timer_delta)
  addiu $v0, %lo(global_timer_delta) # addiu $v0, $v0, -0x7c88
  lwc1  $f18, ($v0)
  lwc1  $f4, 0xb0($s0)
  lwc1  $f8, ($s1)
  li    $t2, 1
  mul.s $f6, $f4, $f18
  move  $a0, $s0
  move  $a3, $s1
  add.s $f10, $f8, $f6
  lwc1  $f6, 8($s1)
  swc1  $f10, ($s1)
  lwc1  $f18, ($v0)
  lwc1  $f4, 0xb8($s0)
  mul.s $f8, $f4, $f18
  add.s $f10, $f6, $f8
  swc1  $f10, 8($s1)
  lw    $t1, 0x18($s0)
  lw    $a2, 0x3c($sp)
  lw    $a1, 0x14($t1)
  sw    $v1, 0x28($sp)
  jal   sub_GAME_7F01F614
   sw    $t2, 0x10($sp)
  beqz  $v0, .L7F01FD88
   lw    $v1, 0x28($sp)
  lw    $t3, 0x18($s0)
  li    $t4, 1
  move  $v1, $s1
  sw    $v0, 0x14($t3)
  sw    $t4, 0x30($sp)
.L7F01FD88:
  lw    $t5, 0x14($s0)
  andi  $t7, $t5, 0x1000
  bnezl $t7, .L7F01FF7C
   lwc1  $f14, 0xac($s0)
  lw    $t8, 0x18($s0)
  lw    $a1, ($v1)
  lw    $a2, 8($v1)
  jal   sub_GAME_7F0B2970
   lw    $a0, 0x14($t8)
  lw    $t9, 0x14($s0)
  mtc1  $zero, $f12
  mov.s $f14, $f0
  andi  $t6, $t9, 1
  beqz  $t6, .L7F01FE10
   swc1  $f0, 0xac($s0)
  lw    $a0, 0x38($sp)
  lw    $t0, 8($a0)
  lw    $a1, ($t0)
  jal   extract_id_from_object_structure_microcode
   swc1  $f14, 0x2c($sp)
  lw    $t1, 0x14($s0)
  lwc1  $f2, 0xac($s0)
  li    $at, -2
  lwc1  $f14, 0x2c($sp)
  and   $t2, $t1, $at
  sw    $t2, 0x14($s0)
  lui   $at, %hi(D_80051D10)
  swc1  $f2, 0xa8($s0)
  lwc1  $f4, %lo(D_80051D10)($at)
  div.s $f18, $f2, $f4
  swc1  $f18, 0xa4($s0)
  lwc1  $f6, 0x28($v0)
  b     .L7F01FF60
   swc1  $f6, 0x38($v0)
.L7F01FE10:
  lwc1  $f8, 0xb4($s0)
  addiu $a0, $s0, 0xa8
  addiu $a1, $s0, 0xb4
  c.eq.s $f12, $f8
  lui   $a2, %hi(global_timer_delta)
  bc1f  .L7F01FE44
   nop   
  lwc1  $f2, 0xac($s0)
  lwc1  $f0, 0xa8($s0)
  c.lt.s $f2, $f0
  nop   
  bc1fl .L7F01FE8C
   c.le.s $f0, $f2
.L7F01FE44:
  lw    $a2, %lo(global_timer_delta)($a2)
  jal   sub_GAME_7F057D44
   swc1  $f14, 0x2c($sp)
  lwc1  $f2, 0xac($s0)
  lwc1  $f0, 0xa8($s0)
  mtc1  $zero, $f12
  lwc1  $f14, 0x2c($sp)
  c.le.s $f0, $f2
  lui   $at, %hi(D_80051D14)
  bc1fl .L7F01FE8C
   c.le.s $f0, $f2
  swc1  $f2, 0xa8($s0)
  lwc1  $f10, %lo(D_80051D14)($at)
  swc1  $f12, 0xb4($s0)
  lwc1  $f0, 0xa8($s0)
  div.s $f4, $f2, $f10
  swc1  $f4, 0xa4($s0)
  c.le.s $f0, $f2
.L7F01FE8C:
  lui   $v1, %hi(clock_timer)
  addiu $v1, %lo(clock_timer) # addiu $v1, $v1, -0x7c8c
  bc1fl .L7F01FF64
   lwc1  $f6, 0xa8($s0)
  lw    $t3, ($v1)
  move  $v0, $zero
  lui   $at, %hi(D_80051D18)
  blez  $t3, .L7F01FEF0
   nop   
  lwc1  $f0, %lo(D_80051D18)($at)
  lwc1  $f18, 0xa4($s0)
.L7F01FEB8:
  lwc1  $f10, 0xb0($s0)
  addiu $v0, $v0, 1
  mul.s $f6, $f18, $f0
  lwc1  $f18, 0xb8($s0)
  mul.s $f4, $f10, $f0
  add.s $f8, $f6, $f2
  mul.s $f6, $f18, $f0
  swc1  $f4, 0xb0($s0)
  swc1  $f8, 0xa4($s0)
  swc1  $f6, 0xb8($s0)
  lw    $t4, ($v1)
  slt   $at, $v0, $t4
  bnezl $at, .L7F01FEB8
   lwc1  $f18, 0xa4($s0)
.L7F01FEF0:
  lui   $at, %hi(D_80051D1C)
  lwc1  $f2, %lo(D_80051D1C)($at)
  lui   $at, %hi(D_80051D20)
  lwc1  $f10, %lo(D_80051D20)($at)
  lwc1  $f8, 0xa4($s0)
  lwc1  $f0, 0xb0($s0)
  lui   $at, %hi(D_80051D24)
  mul.s $f4, $f8, $f10
  c.lt.s $f0, $f2
  nop   
  bc1f  .L7F01FF60
   swc1  $f4, 0xa8($s0)
  lwc1  $f16, %lo(D_80051D24)($at)
  c.lt.s $f16, $f0
  nop   
  bc1fl .L7F01FF64
   lwc1  $f6, 0xa8($s0)
  lwc1  $f0, 0xb8($s0)
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F01FF64
   lwc1  $f6, 0xa8($s0)
  c.lt.s $f16, $f0
  nop   
  bc1fl .L7F01FF64
   lwc1  $f6, 0xa8($s0)
  swc1  $f12, 0xb8($s0)
  swc1  $f12, 0xb0($s0)
.L7F01FF60:
  lwc1  $f6, 0xa8($s0)
.L7F01FF64:
  lwc1  $f18, 4($s1)
  sub.s $f8, $f6, $f14
  add.s $f10, $f18, $f8
  b     .L7F01FF7C
   swc1  $f10, 4($s1)
  lwc1  $f14, 0xac($s0)
.L7F01FF7C:
  lw    $t5, 0x44($sp)
.L7F01FF80:
  li    $v0, 1
  swc1  $f14, ($t5)
  lw    $t7, 0x30($sp)
  lw    $t8, 0x3c($sp)
  bnezl $t7, .L7F01FFB0
   lw    $ra, 0x24($sp)
  lwc1  $f4, ($t8)
  swc1  $f4, ($s1)
  lw    $t9, 0x3c($sp)
  lwc1  $f6, 8($t9)
  swc1  $f6, 8($s1)
  lw    $ra, 0x24($sp)
.L7F01FFB0:
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x38
");
#endif

asm(R"
glabel get_next_available_guardID
  lui   $a0, %hi(num_guards)
  lw    $a0, %lo(num_guards)($a0)
  move  $v1, $zero
  move  $v0, $zero
  blez  $a0, .L7F020010
   lui   $a1, %hi(ptr_guard_data)
  sll   $a2, $a0, 4
  subu  $a2, $a2, $a0
  sll   $a2, $a2, 3
  subu  $a2, $a2, $a0
  sll   $a2, $a2, 2
  lw    $a1, %lo(ptr_guard_data)($a1)
.L7F01FFF0:
  lw    $t6, 0x1c($a1)
  addiu $v0, $v0, 0x1dc
  slt   $at, $v0, $a2
  bnez  $t6, .L7F020008
   nop   
  addiu $v1, $v1, 1
.L7F020008:
  bnez  $at, .L7F01FFF0
   addiu $a1, $a1, 0x1dc
.L7F020010:
  jr    $ra
   move  $v0, $v1
");

asm(R"
glabel sub_GAME_7F020018
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  jal   get_007_health_mod
   sw    $a1, 0x1c($sp)
  lwc1  $f4, 0x1c($sp)
  lw    $t6, 0x18($sp)
  mul.s $f6, $f0, $f4
  swc1  $f6, 0x100($t6)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F02004C
  jr    $ra
   lwc1  $f0, 0x100($a0)
");

asm(R"
glabel sub_GAME_7F020054
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  jal   get_007_health_mod
   sw    $a1, 0x1c($sp)
  lwc1  $f6, 0x1c($sp)
  lw    $v0, 0x18($sp)
  mul.s $f8, $f6, $f0
  lwc1  $f4, 0xfc($v0)
  sub.s $f10, $f4, $f8
  swc1  $f10, 0xfc($v0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F020090
  mtc1  $zero, $f12
  lwc1  $f2, 0xfc($a0)
  c.lt.s $f2, $f12
  nop   
  bc1fl .L7F0200B4
   mov.s $f0, $f12
  jr    $ra
   neg.s $f0, $f2

  mov.s $f0, $f12
.L7F0200B4:
  jr    $ra
   nop   
");

asm(R"
glabel init_GUARDdata_with_set_values
  addiu $sp, $sp, -0x30
  sdc1  $f20, 0x10($sp)
  mtc1  $a3, $f20
  lui   $a3, %hi(num_guards)
  lw    $a3, %lo(num_guards)($a3)
  sw    $s3, 0x28($sp)
  sw    $s2, 0x24($sp)
  sw    $s1, 0x20($sp)
  sw    $s0, 0x1c($sp)
  move  $s1, $a0
  move  $s2, $a1
  move  $s3, $a2
  sw    $ra, 0x2c($sp)
  move  $s0, $zero
  blez  $a3, .L7F020130
   move  $v0, $zero
  lui   $a1, %hi(ptr_guard_data)
  lw    $a1, %lo(ptr_guard_data)($a1)
  move  $a0, $zero
  move  $v1, $a1
.L7F02010C:
  lw    $t6, 0x1c($v1)
  addiu $v0, $v0, 1
  slt   $at, $v0, $a3
  bnez  $t6, .L7F020128
   addiu $v1, $v1, 0x1dc
  b     .L7F020130
   addu  $s0, $a0, $a1
.L7F020128:
  bnez  $at, .L7F02010C
   addiu $a0, $a0, 0x1dc
.L7F020130:
  li    $t7, 3
  sb    $t7, ($s1)
  sw    $s0, 4($s1)
  lwc1  $f4, ($s3)
  lui   $a1, %hi(sub_GAME_7F01FC10) # $a1, 0x7f02
  addiu $a1, %lo(sub_GAME_7F01FC10) # addiu $a1, $a1, -0x3f0
  swc1  $f4, 8($s1)
  lwc1  $f6, 4($s3)
  move  $a0, $s2
  swc1  $f6, 0xc($s1)
  lwc1  $f8, 8($s3)
  swc1  $f8, 0x10($s1)
  lw    $t8, 0x40($sp)
  jal   sub_GAME_7F06FF5C
   sw    $t8, 0x14($s1)
  li    $t9, 10
  sh    $t9, ($s2)
  sw    $s0, 4($s2)
  move  $a0, $s2
  jal   setsuboffset
   move  $a1, $s3
  mfc1  $a1, $f20
  jal   setsubroty
   move  $a0, $s2
  mtc1  $zero, $f20
  lui   $a1, %hi(animation_rate)
  lw    $a1, %lo(animation_rate)($a1)
  mfc1  $a2, $f20
  jal   sub_GAME_7F06FF18
   move  $a0, $s2
  lui   $v0, %hi(player1_guardID)
  addiu $v0, %lo(player1_guardID) # addiu $v0, $v0, -0x33a0
  lw    $t0, ($v0)
  lui   $t3, %hi(global_timer) 
  li    $at, 0x437A0000 # 250.000000
  sh    $t0, ($s0)
  lw    $t1, ($v0)
  mtc1  $at, $f10
  li    $at, 0x3F800000 # 1.000000
  addiu $t2, $t1, 1
  sw    $t2, ($v0)
  sb    $zero, 6($s0)
  sb    $zero, 0xf($s0)
  sw    $s1, 0x18($s0)
  sw    $s2, 0x1c($s0)
  sw    $zero, 0x20($s0)
  sb    $zero, 0xb($s0)
  sw    $zero, 0xc8($s0)
  sb    $zero, 9($s0)
  lw    $t3, %lo(global_timer)($t3)
  mtc1  $at, $f16
  sw    $zero, 0xd4($s0)
  swc1  $f20, 0xd8($s0)
  swc1  $f20, 0xdc($s0)
  swc1  $f20, 0xe0($s0)
  sw    $zero, 0xe4($s0)
  sw    $zero, 0xe8($s0)
  sw    $zero, 0xf0($s0)
  sb    $zero, 0xa($s0)
  swc1  $f20, 0x13c($s0)
  swc1  $f20, 0xfc($s0)
  swc1  $f10, 0xd0($s0)
  sw    $t3, 0xcc($s0)
  jal   get_007_health_mod
   swc1  $f16, 0xec($s0)
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f18
  move  $a0, $s1
  addiu $a1, $s0, 0xf8
  mul.s $f4, $f0, $f18
  jal   set_color_shading_from_tile
   swc1  $f4, 0x100($s0)
  lbu   $t4, 0xf8($s0)
  lbu   $t5, 0xf9($s0)
  lbu   $t6, 0xfa($s0)
  lbu   $t7, 0xfb($s0)
  li    $t8, 255
  li    $t9, 1
  sb    $t8, 0xc($s0)
  sw    $zero, 0x168($s0)
  sw    $zero, 0x16c($s0)
  sw    $zero, 0x170($s0)
  sw    $zero, 0x174($s0)
  sw    $zero, 0x178($s0)
  sw    $zero, 0x17c($s0)
  sw    $t9, 0x14($s0)
  sh    $zero, 0x12($s0)
  swc1  $f20, 0xa4($s0)
  swc1  $f20, 0xa8($s0)
  swc1  $f20, 0xac($s0)
  swc1  $f20, 0xb0($s0)
  swc1  $f20, 0xb4($s0)
  swc1  $f20, 0xb8($s0)
  sb    $t4, 0xf4($s0)
  sb    $t5, 0xf5($s0)
  sb    $t6, 0xf6($s0)
  sb    $t7, 0xf7($s0)
  lwc1  $f6, ($s3)
  li    $v0, -1
  li    $at, 0x41A00000 # 20.000000
  swc1  $f6, 0xbc($s0)
  lwc1  $f8, 4($s3)
  mtc1  $at, $f16
  li    $at, 0x43390000 # 185.000000
  swc1  $f8, 0xc0($s0)
  lwc1  $f10, 8($s3)
  sb    $zero, 7($s0)
  sb    $zero, 8($s0)
  swc1  $f10, 0xc4($s0)
  lw    $t0, 0x44($sp)
  mtc1  $at, $f18
  addiu $a1, $s1, 8
  sh    $zero, 0x108($s0)
  sh    $v0, 0x10a($s0)
  sb    $zero, 0x10c($s0)
  sb    $zero, 0x10d($s0)
  sb    $zero, 0x10e($s0)
  sb    $zero, 0x10f($s0)
  sw    $zero, 0x110($s0)
  sh    $v0, 0x114($s0)
  sh    $v0, 0x118($s0)
  sh    $v0, 0x11a($s0)
  sh    $v0, 0x116($s0)
  sb    $v0, 0x180($s0)
  sb    $v0, 0x1ac($s0)
  sb    $zero, 4($s0)
  sb    $zero, 5($s0)
  sb    $zero, 0x10($s0)
  sb    $zero, 2($s0)
  sb    $zero, 3($s0)
  sb    $zero, 0xd($s0)
  sb    $v0, 0x11($s0)
  swc1  $f20, 0x140($s0)
  swc1  $f20, 0x144($s0)
  swc1  $f20, 0x148($s0)
  swc1  $f20, 0x14c($s0)
  swc1  $f20, 0x150($s0)
  swc1  $f20, 0x154($s0)
  swc1  $f20, 0x158($s0)
  swc1  $f20, 0x15c($s0)
  sb    $zero, 0xe($s0)
  sw    $zero, 0x160($s0)
  sw    $zero, 0x164($s0)
  sw    $zero, 0x1d8($s0)
  move  $a2, $a1
  move  $a0, $s2
  addiu $a3, $s0, 0xac
  swc1  $f16, 0x24($s0)
  sw    $t0, 0x104($s0)
  jal   sub_GAME_7F01FC10
   swc1  $f18, 0x28($s0)
  jal   sub_GAME_7F020D94
   move  $a0, $s0
  lw    $ra, 0x2c($sp)
  move  $v0, $s1
  lw    $s1, 0x20($sp)
  ldc1  $f20, 0x10($sp)
  lw    $s0, 0x1c($sp)
  lw    $s2, 0x24($sp)
  lw    $s3, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x30
");

asm(R"
glabel replace_GUARDdata_with_actual_values
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $a0, 0x20($sp)
  sw    $a1, 0x24($sp)
  sw    $a2, 0x28($sp)
  jal   remove_last_obj_pos_data_entry
   sw    $a3, 0x2c($sp)
  beqz  $v0, .L7F020400
   move  $a0, $v0
  lw    $t6, 0x2c($sp)
  lw    $t7, 0x30($sp)
  lw    $a1, 0x20($sp)
  lw    $a2, 0x24($sp)
  lw    $a3, 0x28($sp)
  sw    $t6, 0x10($sp)
  jal   init_GUARDdata_with_set_values
   sw    $t7, 0x14($sp)
  move  $a0, $v0
.L7F020400:
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x20
  move  $v0, $a0
  jr    $ra
   nop   
");

asm(R"
glabel disable_sounds_attached_to_player_then_something
  addiu $sp, $sp, -0x30
  sw    $ra, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  lw    $s2, 4($a0)
  move  $s0, $a0
  lw    $t6, 0x1c($s2)
  sw    $t6, 0x28($sp)
  lw    $a1, 0x168($s2)
  beql  $a1, $zero, .L7F020460
   lw    $a0, 0x16c($s2)
  jal   sfxGetArg0Unk3F
   move  $a0, $a1
  beql  $v0, $zero, .L7F020460
   lw    $a0, 0x16c($s2)
  jal   sfxDeactivate
   lw    $a0, 0x168($s2)
  lw    $a0, 0x16c($s2)
.L7F020460:
  beql  $a0, $zero, .L7F020484
   lw    $a0, 0x170($s2)
  jal   sfxGetArg0Unk3F
   nop   
  beql  $v0, $zero, .L7F020484
   lw    $a0, 0x170($s2)
  jal   sfxDeactivate
   lw    $a0, 0x16c($s2)
  lw    $a0, 0x170($s2)
.L7F020484:
  beql  $a0, $zero, .L7F0204A8
   lw    $a0, 0x174($s2)
  jal   sfxGetArg0Unk3F
   nop   
  beql  $v0, $zero, .L7F0204A8
   lw    $a0, 0x174($s2)
  jal   sfxDeactivate
   lw    $a0, 0x170($s2)
  lw    $a0, 0x174($s2)
.L7F0204A8:
  beqz  $a0, .L7F0204C8
   nop   
  jal   sfxGetArg0Unk3F
   nop   
  beqz  $v0, .L7F0204C8
   nop   
  jal   sfxDeactivate
   lw    $a0, 0x174($s2)
.L7F0204C8:
  jal   sub_GAME_7F050DE8
   lw    $a0, 0x28($sp)
  jal   sub_GAME_7F03E18C
   move  $a0, $s0
  lw    $a0, 0x20($s0)
  beqz  $a0, .L7F020504
   nop   
.L7F0204E4:
  lw    $s1, 4($a0)
  jal   sub_GAME_7F04C044
   lw    $s0, 0x24($a0)
  move  $a0, $s1
  jal   sub_GAME_7F041024
   li    $a1, 1
  bnez  $s0, .L7F0204E4
   move  $a0, $s0
.L7F020504:
  jal   set_aircraft_obj_inst_scale_to_zero
   lw    $a0, 0x28($sp)
  lw    $a0, 0x20($s2)
  li    $t7, -1
  sw    $zero, 0x1c($s2)
  beqz  $a0, .L7F020528
   sh    $t7, ($s2)
  jal   sub_GAME_7F06B248
   nop   
.L7F020528:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x30
");

asm(R"
glabel animation_speed_related
  addiu $sp, $sp, -0x30
  sw    $s3, 0x28($sp)
  lui   $s3, %hi(animation_rate)
  addiu $s3, %lo(animation_rate) # addiu $s3, $s3, -0x3700
  swc1  $f12, ($s3)
  lui   $v0, %hi(num_guards)
  lw    $v0, %lo(num_guards)($v0)
  sw    $s1, 0x20($sp)
  sw    $ra, 0x2c($sp)
  sw    $s2, 0x24($sp)
  sw    $s0, 0x1c($sp)
  sdc1  $f20, 0x10($sp)
  blez  $v0, .L7F0205C4
   move  $s1, $zero
  li    $at, 0x44160000 # 600.000000
  lui   $s2, %hi(ptr_guard_data)
  mtc1  $at, $f20
  addiu $s2, %lo(ptr_guard_data) # addiu $s2, $s2, -0x339c
  move  $s0, $zero
.L7F02058C:
  lw    $t6, ($s2)
  addu  $t7, $t6, $s0
  lw    $a0, 0x1c($t7)
  beql  $a0, $zero, .L7F0205B8
   addiu $s1, $s1, 1
  mfc1  $a2, $f20
  jal   sub_GAME_7F06FF18
   lw    $a1, ($s3)
  lui   $v0, %hi(num_guards)
  lw    $v0, %lo(num_guards)($v0)
  addiu $s1, $s1, 1
.L7F0205B8:
  slt   $at, $s1, $v0
  bnez  $at, .L7F02058C
   addiu $s0, $s0, 0x1dc
.L7F0205C4:
  lw    $ra, 0x2c($sp)
  ldc1  $f20, 0x10($sp)
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  lw    $s2, 0x24($sp)
  lw    $s3, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x30
");

float get_animation_rate(void) { return animation_rate; }

#ifdef VERSION_US
asm(R"
glabel sub_GAME_7F0205F0
  lb    $v0, 0xe($a0)
  slti  $at, $v0, 2
  bnezl $at, .L7F0206B0
   lwc1  $f18, 0x150($a0)
  mtc1  $v0, $f6
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f2
  cvt.s.w $f8, $f6
  lui   $at, %hi(global_timer_delta)
  lwc1  $f4, %lo(global_timer_delta)($at)
  div.s $f0, $f4, $f8
  c.lt.s $f2, $f0
  nop   
  bc1fl .L7F020634
   lwc1  $f2, 0x140($a0)
  mov.s $f0, $f2
  lwc1  $f2, 0x140($a0)
.L7F020634:
  lwc1  $f10, 0x150($a0)
  lwc1  $f12, 0x144($a0)
  lwc1  $f8, 0x154($a0)
  sub.s $f18, $f10, $f2
  lwc1  $f14, 0x148($a0)
  lwc1  $f16, 0x14c($a0)
  sub.s $f10, $f8, $f12
  mul.s $f6, $f18, $f0
  lui   $t7, %hi(clock_timer) 
  lb    $t6, 0xe($a0)
  mul.s $f18, $f10, $f0
  add.s $f4, $f2, $f6
  add.s $f6, $f12, $f18
  swc1  $f4, 0x140($a0)
  lwc1  $f4, 0x158($a0)
  swc1  $f6, 0x144($a0)
  sub.s $f8, $f4, $f14
  lwc1  $f6, 0x15c($a0)
  sub.s $f4, $f6, $f16
  mul.s $f10, $f8, $f0
  nop   
  mul.s $f8, $f4, $f0
  add.s $f18, $f14, $f10
  add.s $f10, $f16, $f8
  swc1  $f18, 0x148($a0)
  swc1  $f10, 0x14c($a0)
  lw    $t7, %lo(clock_timer)($t7)
  subu  $t8, $t6, $t7
  jr    $ra
   sb    $t8, 0xe($a0)

  lwc1  $f18, 0x150($a0)
.L7F0206B0:
  lwc1  $f6, 0x154($a0)
  lwc1  $f4, 0x158($a0)
  lwc1  $f8, 0x15c($a0)
  swc1  $f18, 0x140($a0)
  swc1  $f6, 0x144($a0)
  swc1  $f4, 0x148($a0)
  swc1  $f8, 0x14c($a0)
  jr    $ra
   nop   
");
#endif

#ifdef VERSION_JP
asm(R"
glabel sub_GAME_7F0205F0
  lb    $v0, 0xe($a0)
  slti  $at, $v0, 2
  bnezl $at, .L7F0206B0
   lwc1  $f18, 0x150($a0)
  mtc1  $v0, $f6
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f2
  cvt.s.w $f8, $f6
  lui   $at, %hi(jp_global_timer_delta)
  lwc1  $f4, %lo(jp_global_timer_delta)($at)
  div.s $f0, $f4, $f8
  c.lt.s $f2, $f0
  nop   
  bc1fl .L7F020634
   lwc1  $f2, 0x140($a0)
  mov.s $f0, $f2
  lwc1  $f2, 0x140($a0)
.L7F020634:
  lwc1  $f10, 0x150($a0)
  lwc1  $f12, 0x144($a0)
  lwc1  $f8, 0x154($a0)
  sub.s $f18, $f10, $f2
  lwc1  $f14, 0x148($a0)
  lwc1  $f16, 0x14c($a0)
  sub.s $f10, $f8, $f12
  mul.s $f6, $f18, $f0
  lui   $t7, %hi(clock_timer) 
  lb    $t6, 0xe($a0)
  mul.s $f18, $f10, $f0
  add.s $f4, $f2, $f6
  add.s $f6, $f12, $f18
  swc1  $f4, 0x140($a0)
  lwc1  $f4, 0x158($a0)
  swc1  $f6, 0x144($a0)
  sub.s $f8, $f4, $f14
  lwc1  $f6, 0x15c($a0)
  sub.s $f4, $f6, $f16
  mul.s $f10, $f8, $f0
  nop   
  mul.s $f8, $f4, $f0
  add.s $f18, $f14, $f10
  add.s $f10, $f16, $f8
  swc1  $f18, 0x148($a0)
  swc1  $f10, 0x14c($a0)
  lw    $t7, %lo(clock_timer)($t7)
  subu  $t8, $t6, $t7
  jr    $ra
   sb    $t8, 0xe($a0)

  lwc1  $f18, 0x150($a0)
.L7F0206B0:
  lwc1  $f6, 0x154($a0)
  lwc1  $f4, 0x158($a0)
  lwc1  $f8, 0x15c($a0)
  swc1  $f18, 0x140($a0)
  swc1  $f6, 0x144($a0)
  swc1  $f4, 0x148($a0)
  swc1  $f8, 0x14c($a0)
  jr    $ra
   nop   
");
#endif

asm(R"
glabel sub_GAME_7F0206D4
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lb    $t6, 0x11($a0)
  bgezl $t6, .L7F020788
   lw    $ra, 0x14($sp)
  lhu   $t8, 0x12($a0)
  li    $t7, 1
  sb    $t7, 0x11($a0)
  andi  $t9, $t8, 0xfff
  sh    $t9, 0x12($a0)
  jal   get_random_value
   sw    $a0, 0x18($sp)
  li    $at, 3
  divu  $zero, $v0, $at
  mfhi  $v1
  lw    $a0, 0x18($sp)
  bnez  $v1, .L7F02072C
   li    $at, 1
  lhu   $t0, 0x12($a0)
  ori   $t1, $t0, 0x1000
  b     .L7F020740
   sh    $t1, 0x12($a0)
.L7F02072C:
  bne   $v1, $at, .L7F020740
   nop   
  lhu   $t2, 0x12($a0)
  ori   $t3, $t2, 0x2000
  sh    $t3, 0x12($a0)
.L7F020740:
  jal   get_random_value
   sw    $a0, 0x18($sp)
  li    $at, 3
  divu  $zero, $v0, $at
  mfhi  $v1
  lw    $a0, 0x18($sp)
  bnez  $v1, .L7F020770
   li    $at, 1
  lhu   $t4, 0x12($a0)
  ori   $t5, $t4, 0x4000
  b     .L7F020784
   sh    $t5, 0x12($a0)
.L7F020770:
  bnel  $v1, $at, .L7F020788
   lw    $ra, 0x14($sp)
  lhu   $t6, 0x12($a0)
  ori   $t7, $t6, 0x8000
  sh    $t7, 0x12($a0)
.L7F020784:
  lw    $ra, 0x14($sp)
.L7F020788:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F020794
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lb    $t6, 0x11($a0)
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f0
  mtc1  $t6, $f4
  lui   $at, %hi(D_80051D2C)
  cvt.s.w $f2, $f4
  c.lt.s $f2, $f0
  nop   
  bc1fl .L7F0207F4
   sub.s $f18, $f2, $f0
  lui   $at, %hi(D_80051D28)
  lwc1  $f6, %lo(D_80051D28)($at)
  li    $at, 0x3E800000 # 0.250000
  mtc1  $at, $f10
  mul.s $f8, $f2, $f6
  nop   
  mul.s $f16, $f8, $f10
  jal   sinf
   div.s $f12, $f16, $f0
  b     .L7F020828
   mov.s $f2, $f0
  sub.s $f18, $f2, $f0
.L7F0207F4:
  lwc1  $f4, %lo(D_80051D2C)($at)
  li    $at, 0x3E800000 # 0.250000
  mtc1  $at, $f8
  mul.s $f6, $f18, $f4
  li    $at, 0x41A00000 # 20.000000
  mtc1  $at, $f16
  mul.s $f10, $f6, $f8
  jal   sinf
   div.s $f12, $f10, $f16
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f18
  nop   
  sub.s $f2, $f18, $f0
.L7F020828:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  mov.s $f0, $f2
  jr    $ra
   nop   
");

#ifdef VERSION_JP
asm(R"
glabel jp_only_7F0209EC
  lui   $t6, %hi(j_text_trigger) # $t6, 0x8005
  lw    $t6, %lo(j_text_trigger)($t6)
  li    $at, 6
  bnez  $t6, .L7F020A08
   nop   
  jr    $ra
   li    $v0, 1

.L7F020A08:
  beq   $a0, $at, .L7F020AA4
   move  $v0, $zero
  li    $at, 7
  beq   $a0, $at, .L7F020AA4
   li    $at, 8
  beq   $a0, $at, .L7F020AA4
   li    $at, 9
  beq   $a0, $at, .L7F020AA4
   li    $at, 10
  beq   $a0, $at, .L7F020AA4
   li    $at, 11
  beq   $a0, $at, .L7F020AA4
   li    $at, 12
  beq   $a0, $at, .L7F020AA4
   li    $at, 13
  beq   $a0, $at, .L7F020AA4
   li    $at, 14
  beq   $a0, $at, .L7F020AA4
   li    $at, 15
  beq   $a0, $at, .L7F020AA4
   li    $at, 16
  beq   $a0, $at, .L7F020AA4
   li    $at, 79
  beq   $a0, $at, .L7F020AA4
   li    $at, 74
  beq   $a1, $at, .L7F020AA4
   li    $at, 75
  beq   $a1, $at, .L7F020AA4
   li    $at, 76
  beq   $a1, $at, .L7F020AA4
   li    $at, 77
  beq   $a1, $at, .L7F020AA4
   li    $at, 78
  beq   $a1, $at, .L7F020AA4
   li    $at, 69
  beq   $a1, $at, .L7F020AA4
   nop   
  jr    $ra
   li    $v0, 1

.L7F020AA4:
  jr    $ra
   nop     
");
#endif

#ifdef VERSION_US
asm(R"
glabel sub_GAME_7F02083C
  addiu $sp, $sp, -0x98
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  sw    $ra, 0x14($sp)
  move  $a2, $a0
  sw    $a1, 0x9c($sp)
  sw    $a2, 0x98($sp)
  li    $a0, 12
  jal   cheatCheckIfOn
   swc1  $f4, 0x94($sp)
  beqz  $v0, .L7F0208A0
   lw    $a2, 0x98($sp)
  bnez  $a2, .L7F020884
   li    $v1, 2
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f6
  b     .L7F0208A0
   swc1  $f6, 0x94($sp)
.L7F020884:
  beq   $a2, $v1, .L7F020890
   li    $a1, 3
  bne   $a2, $a1, .L7F0208A0
.L7F020890:
   li    $at, 0x40200000 # 2.500000
  mtc1  $at, $f8
  nop   
  swc1  $f8, 0x94($sp)
.L7F0208A0:
  li    $v1, 2
  beq   $a2, $v1, .L7F0208C4
   li    $a1, 3
  beq   $a2, $a1, .L7F0208C4
   li    $a3, 1
  beql  $a2, $a3, .L7F0208C8
   mtc1  $zero, $f18
  bnezl $a2, .L7F020D88
   lw    $ra, 0x14($sp)
.L7F0208C4:
  mtc1  $zero, $f18
.L7F0208C8:
  li    $a3, 1
  lui   $t6, %hi(dword_CODE_bss_80069B60) 
  mov.s $f14, $f18
  mov.s $f12, $f18
  bne   $a2, $a1, .L7F0208EC
   swc1  $f18, 0x88($sp)
  lw    $t6, %lo(dword_CODE_bss_80069B60)($t6)
  b     .L7F0209F4
   lwc1  $f14, 0x144($t6)
.L7F0208EC:
  bne   $a2, $v1, .L7F020900
   lui   $t7, %hi(dword_CODE_bss_80069B60) 
  lw    $t7, %lo(dword_CODE_bss_80069B60)($t7)
  b     .L7F0209F4
   lwc1  $f14, 0x140($t7)
.L7F020900:
  bne   $a2, $a3, .L7F020974
   lui   $a0, %hi(dword_CODE_bss_80069B60)
  lw    $a0, %lo(dword_CODE_bss_80069B60)($a0)
  lui   $at, %hi(D_80051D30)
  lhu   $t8, 0x12($a0)
  lwc1  $f14, 0x148($a0)
  andi  $t9, $t8, 0x400
  beqz  $t9, .L7F02096C
   nop   
  lwc1  $f0, %lo(D_80051D30)($at)
  lui   $at, %hi(D_80051D34)
  c.lt.s $f0, $f14
  nop   
  bc1f  .L7F020944
   nop   
  b     .L7F02096C
   sub.s $f14, $f14, $f0
.L7F020944:
  lwc1  $f0, %lo(D_80051D34)($at)
  lui   $at, %hi(D_80051D38)
  c.lt.s $f14, $f0
  nop   
  bc1fl .L7F02096C
   mov.s $f14, $f18
  lwc1  $f10, %lo(D_80051D38)($at)
  b     .L7F02096C
   add.s $f14, $f14, $f10
  mov.s $f14, $f18
.L7F02096C:
  b     .L7F0209F4
   lwc1  $f12, 0x14c($a0)
.L7F020974:
  bnez  $a2, .L7F0209F4
   lui   $a0, %hi(dword_CODE_bss_80069B60)
  lw    $a0, %lo(dword_CODE_bss_80069B60)($a0)
  lhu   $v0, 0x12($a0)
  andi  $t0, $v0, 0x400
  beql  $t0, $zero, .L7F0209DC
   lw    $t1, 0x1c($a0)
  beqz  $t0, .L7F0209F4
   lwc1  $f14, 0x148($a0)
  lui   $at, %hi(D_80051D3C)
  lwc1  $f0, %lo(D_80051D3C)($at)
  lui   $at, %hi(D_80051D40)
  c.lt.s $f0, $f14
  nop   
  bc1f  .L7F0209BC
   nop   
  b     .L7F0209F4
   mov.s $f14, $f0
.L7F0209BC:
  lwc1  $f0, %lo(D_80051D40)($at)
  c.lt.s $f14, $f0
  nop   
  bc1f  .L7F0209F4
   nop   
  b     .L7F0209F4
   mov.s $f14, $f0
  lw    $t1, 0x1c($a0)
.L7F0209DC:
  lb    $t2, 0x24($t1)
  beql  $t2, $zero, .L7F0209F4
   lwc1  $f14, 0x144($a0)
  b     .L7F0209F4
   lwc1  $f14, 0x140($a0)
  lwc1  $f14, 0x144($a0)
.L7F0209F4:
  lui   $a0, %hi(dword_CODE_bss_80069B60)
  lw    $a0, %lo(dword_CODE_bss_80069B60)($a0)
  lb    $t3, 0x11($a0)
  bltzl $t3, .L7F020B58
   c.eq.s $f14, $f18
  beql  $a2, $a1, .L7F020A1C
   swc1  $f12, 0x8c($sp)
  bne   $a2, $v1, .L7F020A88
   nop   
  swc1  $f12, 0x8c($sp)
.L7F020A1C:
  jal   sub_GAME_7F020794
   swc1  $f14, 0x90($sp)
  lui   $at, %hi(D_80051D44)
  lwc1  $f4, %lo(D_80051D44)($at)
  li    $at, 0x41700000 # 15.000000
  mtc1  $at, $f8
  mul.s $f6, $f0, $f4
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f4
  lui   $a0, %hi(dword_CODE_bss_80069B60)
  lw    $a0, %lo(dword_CODE_bss_80069B60)($a0)
  lwc1  $f14, 0x90($sp)
  mtc1  $zero, $f18
  mul.s $f10, $f6, $f8
  lhu   $v0, 0x12($a0)
  lwc1  $f12, 0x8c($sp)
  andi  $t4, $v0, 0x1000
  andi  $t5, $v0, 0x2000
  div.s $f2, $f10, $f4
  beqz  $t4, .L7F020A78
   sub.s $f14, $f14, $f2
  b     .L7F020B54
   sub.s $f12, $f12, $f2
.L7F020A78:
  beql  $t5, $zero, .L7F020B58
   c.eq.s $f14, $f18
  b     .L7F020B54
   add.s $f12, $f12, $f2
.L7F020A88:
  bnel  $a2, $a3, .L7F020B58
   c.eq.s $f14, $f18
  swc1  $f12, 0x8c($sp)
  jal   sub_GAME_7F020794
   swc1  $f14, 0x90($sp)
  lui   $at, %hi(D_80051D48)
  lwc1  $f6, %lo(D_80051D48)($at)
  li    $at, 0x41700000 # 15.000000
  mtc1  $at, $f8
  mul.s $f16, $f0, $f6
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f4
  lui   $a0, %hi(dword_CODE_bss_80069B60)
  lw    $a0, %lo(dword_CODE_bss_80069B60)($a0)
  lwc1  $f14, 0x90($sp)
  mtc1  $zero, $f18
  mul.s $f10, $f16, $f8
  lhu   $v0, 0x12($a0)
  lwc1  $f12, 0x8c($sp)
  li    $at, 0x41200000 # 10.000000
  andi  $t6, $v0, 0x1000
  andi  $t7, $v0, 0x2000
  andi  $t8, $v0, 0x4000
  div.s $f2, $f10, $f4
  andi  $t9, $v0, 0x8000
  beqz  $t6, .L7F020AFC
   add.s $f14, $f14, $f2
  b     .L7F020B08
   add.s $f12, $f12, $f2
.L7F020AFC:
  beqz  $t7, .L7F020B08
   nop   
  sub.s $f12, $f12, $f2
.L7F020B08:
  beqz  $t8, .L7F020B30
   nop   
  mtc1  $at, $f6
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f10
  mul.s $f8, $f16, $f6
  div.s $f4, $f8, $f10
  add.s $f6, $f18, $f4
  b     .L7F020B54
   swc1  $f6, 0x88($sp)
.L7F020B30:
  beqz  $t9, .L7F020B54
   li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f8
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f4
  mul.s $f10, $f16, $f8
  div.s $f6, $f10, $f4
  sub.s $f8, $f18, $f6
  swc1  $f8, 0x88($sp)
.L7F020B54:
  c.eq.s $f14, $f18
.L7F020B58:
  nop   
  bc1fl .L7F020BA4
   swc1  $f12, 0x8c($sp)
  c.eq.s $f12, $f18
  lwc1  $f10, 0x88($sp)
  bc1fl .L7F020BA4
   swc1  $f12, 0x8c($sp)
  c.eq.s $f10, $f18
  lwc1  $f4, 0x94($sp)
  li    $at, 0x3F800000 # 1.000000
  bc1fl .L7F020BA4
   swc1  $f12, 0x8c($sp)
  mtc1  $at, $f6
  nop   
  c.eq.s $f4, $f6
  nop   
  bc1tl .L7F020D88
   lw    $ra, 0x14($sp)
  swc1  $f12, 0x8c($sp)
.L7F020BA4:
  jal   sub_GAME_7F02C190
   swc1  $f14, 0x90($sp)
  lwc1  $f14, 0x90($sp)
  mtc1  $zero, $f18
  lwc1  $f12, 0x8c($sp)
  swc1  $f0, 0x70($sp)
  c.lt.s $f14, $f18
  lui   $at, %hi(D_80051D4C)
  bc1f  .L7F020BD4
   nop   
  b     .L7F020BDC
   neg.s $f14, $f14
.L7F020BD4:
  lwc1  $f8, %lo(D_80051D4C)($at)
  sub.s $f14, $f8, $f14
.L7F020BDC:
  c.lt.s $f12, $f18
  lui   $at, %hi(D_80051D50)
  bc1fl .L7F020BF8
   swc1  $f12, 0x8c($sp)
  lwc1  $f10, %lo(D_80051D50)($at)
  add.s $f12, $f12, $f10
  swc1  $f12, 0x8c($sp)
.L7F020BF8:
  jal   sub_GAME_7F078444
   swc1  $f14, 0x90($sp)
  move  $a0, $v0
  jal   sub_GAME_7F058098
   lw    $a1, 0x9c($sp)
  lw    $v0, 0x9c($sp)
  lwc1  $f14, 0x90($sp)
  mtc1  $zero, $f18
  lwc1  $f4, 0x30($v0)
  lwc1  $f12, 0x8c($sp)
  c.eq.s $f14, $f18
  swc1  $f4, 0x74($sp)
  lwc1  $f6, 0x34($v0)
  addiu $a1, $sp, 0x30
  swc1  $f6, 0x78($sp)
  lwc1  $f8, 0x38($v0)
  swc1  $f8, 0x7c($sp)
  swc1  $f18, 0x30($v0)
  swc1  $f18, 0x34($v0)
  bc1f  .L7F020C60
   swc1  $f18, 0x38($v0)
  lwc1  $f10, 0x88($sp)
  c.eq.s $f10, $f18
  nop   
  bc1t  .L7F020D1C
   nop   
.L7F020C60:
  lwc1  $f4, 0x70($sp)
  lui   $at, %hi(D_80051D54)
  sub.s $f12, $f12, $f4
  c.lt.s $f12, $f18
  nop   
  bc1f  .L7F020C84
   nop   
  lwc1  $f6, %lo(D_80051D54)($at)
  add.s $f12, $f12, $f6
.L7F020C84:
  jal   sub_GAME_7F0585FC
   swc1  $f14, 0x90($sp)
  addiu $a0, $sp, 0x30
  jal   sub_GAME_7F058098
   lw    $a1, 0x9c($sp)
  lwc1  $f14, 0x90($sp)
  mtc1  $zero, $f18
  addiu $a1, $sp, 0x30
  c.eq.s $f14, $f18
  nop   
  bc1tl .L7F020CD4
   lwc1  $f8, 0x88($sp)
  jal   sub_GAME_7F058570
   mov.s $f12, $f14
  addiu $a0, $sp, 0x30
  jal   sub_GAME_7F058098
   lw    $a1, 0x9c($sp)
  mtc1  $zero, $f18
  nop   
  lwc1  $f8, 0x88($sp)
.L7F020CD4:
  addiu $a1, $sp, 0x30
  c.eq.s $f8, $f18
  nop   
  bc1tl .L7F020D00
   lwc1  $f12, 0x70($sp)
  jal   sub_GAME_7F058688
   mov.s $f12, $f8
  addiu $a0, $sp, 0x30
  jal   sub_GAME_7F058098
   lw    $a1, 0x9c($sp)
  lwc1  $f12, 0x70($sp)
.L7F020D00:
  jal   sub_GAME_7F0585FC
   addiu $a1, $sp, 0x30
  addiu $a0, $sp, 0x30
  jal   sub_GAME_7F058098
   lw    $a1, 0x9c($sp)
  b     .L7F020D34
   lui   $at, 0x3f80
.L7F020D1C:
  jal   sub_GAME_7F0585FC
   addiu $a1, $sp, 0x30
  addiu $a0, $sp, 0x30
  jal   sub_GAME_7F058098
   lw    $a1, 0x9c($sp)
  li    $at, 0x3F800000 # 1.000000
.L7F020D34:
  mtc1  $at, $f4
  lwc1  $f10, 0x94($sp)
  lw    $a1, 0x9c($sp)
  c.eq.s $f10, $f4
  nop   
  bc1tl .L7F020D5C
   lwc1  $f6, 0x74($sp)
  jal   matrix_multiply_A1_by_F12
   mov.s $f12, $f10
  lwc1  $f6, 0x74($sp)
.L7F020D5C:
  lw    $t0, 0x9c($sp)
  swc1  $f6, 0x30($t0)
  lwc1  $f8, 0x78($sp)
  swc1  $f8, 0x34($t0)
  lwc1  $f4, 0x7c($sp)
  jal   get_BONDdata_field_10CC
   swc1  $f4, 0x38($t0)
  move  $a0, $v0
  jal   sub_GAME_7F058098
   lw    $a1, 0x9c($sp)
  lw    $ra, 0x14($sp)
.L7F020D88:
  addiu $sp, $sp, 0x98
  jr    $ra
   nop   
");
#endif

#ifdef VERSION_JP
asm(R"
glabel sub_GAME_7F02083C
  addiu $sp, $sp, -0x98
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  sw    $ra, 0x14($sp)
  move  $a3, $a0
  sw    $a1, 0x9c($sp)
  sw    $a3, 0x98($sp)
  li    $a0, 12
  jal   cheatCheckIfOn
   swc1  $f4, 0x94($sp)
  beqz  $v0, .L7F020B48
   lw    $a3, 0x98($sp)
  lui   $a2, %hi(dword_CODE_bss_80069B60) # $a2, 0x8007
  lw    $a2, %lo(dword_CODE_bss_80069B60)($a2)
  lb    $a0, 0xf($a2)
  lb    $a1, 6($a2)
  jal   jp_only_7F0209EC
   sw    $a3, 0x98($sp)
  beqz  $v0, .L7F020B48
   lw    $a3, 0x98($sp)
  bnez  $a3, .L7F020B14
   li    $v1, 2
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f6
  b     .L7F020B48
   swc1  $f6, 0x94($sp)
.L7F020B14:
  beq   $a3, $v1, .L7F020B20
   li    $a1, 3
  bne   $a3, $a1, .L7F020B48
.L7F020B20:
   lui   $t6, %hi(dword_CODE_bss_80069B60) # $t6, 0x8007
  lw    $t6, %lo(dword_CODE_bss_80069B60)($t6)
  li    $at, 0x40200000 # 2.500000
  lw    $t7, 0x14($t6)
  sll   $t8, $t7, 4
  bltzl $t8, .L7F020B4C
   li    $v1, 2
  mtc1  $at, $f8
  nop   
  swc1  $f8, 0x94($sp)
.L7F020B48:
  li    $v1, 2
.L7F020B4C:
  beq   $a3, $v1, .L7F020B6C
   li    $a1, 3
  beq   $a3, $a1, .L7F020B6C
   li    $a0, 1
  beql  $a3, $a0, .L7F020B70
   mtc1  $zero, $f18
  bnezl $a3, .L7F021020
   lw    $ra, 0x14($sp)
.L7F020B6C:
  mtc1  $zero, $f18
.L7F020B70:
  lui   $a2, %hi(dword_CODE_bss_80069B60) # $a2, 0x8007
  li    $a0, 1
  lw    $a2, %lo(dword_CODE_bss_80069B60)($a2)
  mov.s $f14, $f18
  mov.s $f12, $f18
  bne   $a3, $a1, .L7F020B94
   swc1  $f18, 0x88($sp)
  b     .L7F020C90
   lwc1  $f14, 0x144($a2)
.L7F020B94:
  bne   $a3, $v1, .L7F020BA4
   nop   
  b     .L7F020C90
   lwc1  $f14, 0x140($a2)
.L7F020BA4:
  bne   $a3, $a0, .L7F020C14
   nop   
  lhu   $t9, 0x12($a2)
  lwc1  $f14, 0x148($a2)
  lui   $at, %hi(D_80051D30) # $at, 0x8005
  andi  $t0, $t9, 0x400
  beqz  $t0, .L7F020C0C
   nop   
  lwc1  $f0, %lo(D_80051D30)($at)
  lui   $at, %hi(D_80051D34) # $at, 0x8005
  c.lt.s $f0, $f14
  nop   
  bc1f  .L7F020BE4
   nop   
  b     .L7F020C0C
   sub.s $f14, $f14, $f0
.L7F020BE4:
  lwc1  $f0, %lo(D_80051D34)($at)
  lui   $at, %hi(D_80051D38) # $at, 0x8005
  c.lt.s $f14, $f0
  nop   
  bc1fl .L7F020C0C
   mov.s $f14, $f18
  lwc1  $f10, %lo(D_80051D38)($at)
  b     .L7F020C0C
   add.s $f14, $f14, $f10
  mov.s $f14, $f18
.L7F020C0C:
  b     .L7F020C90
   lwc1  $f12, 0x14c($a2)
.L7F020C14:
  bnezl $a3, .L7F020C94
   lb    $t4, 0x11($a2)
  lhu   $v0, 0x12($a2)
  andi  $t1, $v0, 0x400
  beql  $t1, $zero, .L7F020C78
   lw    $t2, 0x1c($a2)
  beqz  $t1, .L7F020C90
   lwc1  $f14, 0x148($a2)
  lui   $at, %hi(D_80051D3C) # $at, 0x8005
  lwc1  $f0, %lo(D_80051D3C)($at)
  lui   $at, %hi(D_80051D40) # $at, 0x8005
  c.lt.s $f0, $f14
  nop   
  bc1f  .L7F020C58
   nop   
  b     .L7F020C90
   mov.s $f14, $f0
.L7F020C58:
  lwc1  $f0, %lo(D_80051D40)($at)
  c.lt.s $f14, $f0
  nop   
  bc1fl .L7F020C94
   lb    $t4, 0x11($a2)
  b     .L7F020C90
   mov.s $f14, $f0
  lw    $t2, 0x1c($a2)
.L7F020C78:
  lb    $t3, 0x24($t2)
  beql  $t3, $zero, .L7F020C90
   lwc1  $f14, 0x144($a2)
  b     .L7F020C90
   lwc1  $f14, 0x140($a2)
  lwc1  $f14, 0x144($a2)
.L7F020C90:
  lb    $t4, 0x11($a2)
.L7F020C94:
  bltzl $t4, .L7F020DF0
   c.eq.s $f14, $f18
  beql  $a3, $a1, .L7F020CB0
   move  $a0, $a2
  bne   $a3, $v1, .L7F020D20
   nop   
  move  $a0, $a2
.L7F020CB0:
  swc1  $f12, 0x8c($sp)
  jal   sub_GAME_7F020794
   swc1  $f14, 0x90($sp)
  lui   $at, %hi(D_80051D44) # $at, 0x8005
  lwc1  $f4, %lo(D_80051D44)($at)
  li    $at, 0x41700000 # 15.000000
  mtc1  $at, $f8
  mul.s $f6, $f0, $f4
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f4
  lui   $a2, %hi(dword_CODE_bss_80069B60) # $a2, 0x8007
  lw    $a2, %lo(dword_CODE_bss_80069B60)($a2)
  lwc1  $f14, 0x90($sp)
  mtc1  $zero, $f18
  mul.s $f10, $f6, $f8
  lhu   $v0, 0x12($a2)
  lwc1  $f12, 0x8c($sp)
  andi  $t5, $v0, 0x1000
  andi  $t6, $v0, 0x2000
  div.s $f2, $f10, $f4
  beqz  $t5, .L7F020D10
   sub.s $f14, $f14, $f2
  b     .L7F020DEC
   sub.s $f12, $f12, $f2
.L7F020D10:
  beql  $t6, $zero, .L7F020DF0
   c.eq.s $f14, $f18
  b     .L7F020DEC
   add.s $f12, $f12, $f2
.L7F020D20:
  bne   $a3, $a0, .L7F020DEC
   move  $a0, $a2
  swc1  $f12, 0x8c($sp)
  jal   sub_GAME_7F020794
   swc1  $f14, 0x90($sp)
  lui   $at, %hi(D_80051D48) # $at, 0x8005
  lwc1  $f6, %lo(D_80051D48)($at)
  li    $at, 0x41700000 # 15.000000
  mtc1  $at, $f8
  mul.s $f16, $f0, $f6
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f4
  lui   $a2, %hi(dword_CODE_bss_80069B60) # $a2, 0x8007
  lw    $a2, %lo(dword_CODE_bss_80069B60)($a2)
  lwc1  $f14, 0x90($sp)
  mtc1  $zero, $f18
  mul.s $f10, $f16, $f8
  lhu   $v0, 0x12($a2)
  lwc1  $f12, 0x8c($sp)
  li    $at, 0x41200000 # 10.000000
  andi  $t7, $v0, 0x1000
  andi  $t8, $v0, 0x2000
  andi  $t9, $v0, 0x4000
  div.s $f2, $f10, $f4
  andi  $t0, $v0, 0x8000
  beqz  $t7, .L7F020D94
   add.s $f14, $f14, $f2
  b     .L7F020DA0
   add.s $f12, $f12, $f2
.L7F020D94:
  beqz  $t8, .L7F020DA0
   nop   
  sub.s $f12, $f12, $f2
.L7F020DA0:
  beqz  $t9, .L7F020DC8
   nop   
  mtc1  $at, $f6
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f10
  mul.s $f8, $f16, $f6
  div.s $f4, $f8, $f10
  add.s $f6, $f18, $f4
  b     .L7F020DEC
   swc1  $f6, 0x88($sp)
.L7F020DC8:
  beqz  $t0, .L7F020DEC
   li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f8
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f4
  mul.s $f10, $f16, $f8
  div.s $f6, $f10, $f4
  sub.s $f8, $f18, $f6
  swc1  $f8, 0x88($sp)
.L7F020DEC:
  c.eq.s $f14, $f18
.L7F020DF0:
  move  $a0, $a2
  bc1fl .L7F020E3C
   swc1  $f12, 0x8c($sp)
  c.eq.s $f12, $f18
  lwc1  $f10, 0x88($sp)
  bc1fl .L7F020E3C
   swc1  $f12, 0x8c($sp)
  c.eq.s $f10, $f18
  lwc1  $f4, 0x94($sp)
  li    $at, 0x3F800000 # 1.000000
  bc1fl .L7F020E3C
   swc1  $f12, 0x8c($sp)
  mtc1  $at, $f6
  nop   
  c.eq.s $f4, $f6
  nop   
  bc1tl .L7F021020
   lw    $ra, 0x14($sp)
  swc1  $f12, 0x8c($sp)
.L7F020E3C:
  jal   sub_GAME_7F02C190
   swc1  $f14, 0x90($sp)
  lwc1  $f14, 0x90($sp)
  mtc1  $zero, $f18
  lwc1  $f12, 0x8c($sp)
  swc1  $f0, 0x70($sp)
  c.lt.s $f14, $f18
  lui   $at, %hi(D_80051D4C) # $at, 0x8005
  bc1f  .L7F020E6C
   nop   
  b     .L7F020E74
   neg.s $f14, $f14
.L7F020E6C:
  lwc1  $f8, %lo(D_80051D4C)($at)
  sub.s $f14, $f8, $f14
.L7F020E74:
  c.lt.s $f12, $f18
  lui   $at, %hi(D_80051D50) # $at, 0x8005
  bc1fl .L7F020E90
   swc1  $f12, 0x8c($sp)
  lwc1  $f10, %lo(D_80051D50)($at)
  add.s $f12, $f12, $f10
  swc1  $f12, 0x8c($sp)
.L7F020E90:
  jal   sub_GAME_7F078444
   swc1  $f14, 0x90($sp)
  move  $a0, $v0
  jal   sub_GAME_7F058098
   lw    $a1, 0x9c($sp)
  lw    $v0, 0x9c($sp)
  lwc1  $f14, 0x90($sp)
  mtc1  $zero, $f18
  lwc1  $f4, 0x30($v0)
  lwc1  $f12, 0x8c($sp)
  c.eq.s $f14, $f18
  swc1  $f4, 0x74($sp)
  lwc1  $f6, 0x34($v0)
  addiu $a1, $sp, 0x30
  swc1  $f6, 0x78($sp)
  lwc1  $f8, 0x38($v0)
  swc1  $f8, 0x7c($sp)
  swc1  $f18, 0x30($v0)
  swc1  $f18, 0x34($v0)
  bc1f  .L7F020EF8
   swc1  $f18, 0x38($v0)
  lwc1  $f10, 0x88($sp)
  c.eq.s $f10, $f18
  nop   
  bc1t  .L7F020FB4
   nop   
.L7F020EF8:
  lwc1  $f4, 0x70($sp)
  lui   $at, %hi(D_80051D54) # $at, 0x8005
  sub.s $f12, $f12, $f4
  c.lt.s $f12, $f18
  nop   
  bc1f  .L7F020F1C
   nop   
  lwc1  $f6, %lo(D_80051D54)($at)
  add.s $f12, $f12, $f6
.L7F020F1C:
  jal   sub_GAME_7F0585FC
   swc1  $f14, 0x90($sp)
  addiu $a0, $sp, 0x30
  jal   sub_GAME_7F058098
   lw    $a1, 0x9c($sp)
  lwc1  $f14, 0x90($sp)
  mtc1  $zero, $f18
  addiu $a1, $sp, 0x30
  c.eq.s $f14, $f18
  nop   
  bc1tl .L7F020F6C
   lwc1  $f8, 0x88($sp)
  jal   sub_GAME_7F058570
   mov.s $f12, $f14
  addiu $a0, $sp, 0x30
  jal   sub_GAME_7F058098
   lw    $a1, 0x9c($sp)
  mtc1  $zero, $f18
  nop   
  lwc1  $f8, 0x88($sp)
.L7F020F6C:
  addiu $a1, $sp, 0x30
  c.eq.s $f8, $f18
  nop   
  bc1tl .L7F020F98
   lwc1  $f12, 0x70($sp)
  jal   sub_GAME_7F058688
   mov.s $f12, $f8
  addiu $a0, $sp, 0x30
  jal   sub_GAME_7F058098
   lw    $a1, 0x9c($sp)
  lwc1  $f12, 0x70($sp)
.L7F020F98:
  jal   sub_GAME_7F0585FC
   addiu $a1, $sp, 0x30
  addiu $a0, $sp, 0x30
  jal   sub_GAME_7F058098
   lw    $a1, 0x9c($sp)
  b     .L7F020FCC
   lui   $at, 0x3f80
.L7F020FB4:
  jal   sub_GAME_7F0585FC
   addiu $a1, $sp, 0x30
  addiu $a0, $sp, 0x30
  jal   sub_GAME_7F058098
   lw    $a1, 0x9c($sp)
  li    $at, 0x3F800000 # 1.000000
.L7F020FCC:
  mtc1  $at, $f4
  lwc1  $f10, 0x94($sp)
  lw    $a1, 0x9c($sp)
  c.eq.s $f10, $f4
  nop   
  bc1tl .L7F020FF4
   lwc1  $f6, 0x74($sp)
  jal   matrix_multiply_A1_by_F12
   mov.s $f12, $f10
  lwc1  $f6, 0x74($sp)
.L7F020FF4:
  lw    $t1, 0x9c($sp)
  swc1  $f6, 0x30($t1)
  lwc1  $f8, 0x78($sp)
  swc1  $f8, 0x34($t1)
  lwc1  $f4, 0x7c($sp)
  jal   get_BONDdata_field_10CC
   swc1  $f4, 0x38($t1)
  move  $a0, $v0
  jal   sub_GAME_7F058098
   lw    $a1, 0x9c($sp)
  lw    $ra, 0x14($sp)
.L7F021020:
  addiu $sp, $sp, 0x98
  jr    $ra
   nop   
    
");
#endif

asm(R"
glabel sub_GAME_7F020D94
  addiu $sp, $sp, -0x38
  sw    $ra, 0x14($sp)
  move  $a1, $a0
  lw    $a0, 0x18($a0)
  li    $at, 0x42480000 # 50.000000
  mtc1  $at, $f0
  lwc1  $f4, 8($a0)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  sub.s $f6, $f4, $f0
  li    $at, 0x42C80000 # 100.000000
  swc1  $f6, 0x28($sp)
  lwc1  $f8, 0xac($a1)
  sub.s $f16, $f8, $f10
  swc1  $f16, 0x2c($sp)
  lwc1  $f18, 0x10($a0)
  mtc1  $at, $f16
  sub.s $f4, $f18, $f0
  swc1  $f4, 0x30($sp)
  lwc1  $f6, 8($a0)
  add.s $f8, $f6, $f0
  swc1  $f8, 0x1c($sp)
  lwc1  $f10, 0xc($a0)
  add.s $f18, $f10, $f16
  swc1  $f18, 0x20($sp)
  lwc1  $f4, 0x10($a0)
  sw    $a0, 0x34($sp)
  add.s $f6, $f4, $f0
  jal   sub_GAME_7F03E18C
   swc1  $f6, 0x24($sp)
  li    $at, 0x42480000 # 50.000000
  mtc1  $at, $f0
  lw    $a0, 0x34($sp)
  addiu $a1, $sp, 0x28
  mfc1  $a3, $f0
  jal   sub_GAME_7F03E27C
   addiu $a2, $sp, 0x1c
  jal   sub_GAME_7F03E210
   lw    $a0, 0x34($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F020E40
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  sw    $a1, 0x2c($sp)
  lw    $t6, 0x18($a0)
  lw    $s0, 0x1c($a0)
  move  $s1, $a0
  sw    $t6, 0x20($sp)
  lhu   $t7, 0x12($a0)
  move  $a0, $s0
  andi  $t8, $t7, 0x800
  bnez  $t8, .L7F020EC4
   nop   
  jal   getsuboffset
   addiu $a1, $s1, 0xbc
  move  $a0, $s0
  lw    $a1, 0x2c($sp)
  jal   sub_GAME_7F070AEC
   li    $a2, 1
  jal   subcalcpos
   move  $a0, $s0
  lw    $a0, 0x20($sp)
  jal   set_color_shading_from_tile
   addiu $a1, $s1, 0xf8
  lw    $a1, 0x20($sp)
  move  $a0, $s0
  jal   getsuboffset
   addiu $a1, $a1, 8
  jal   sub_GAME_7F020D94
   move  $a0, $s1
  b     .L7F020EE0
   lw    $ra, 0x1c($sp)
.L7F020EC4:
  jal   subcalcpos
   move  $a0, $s0
  lw    $a1, 0x20($sp)
  move  $a0, $s0
  jal   getsuboffset
   addiu $a1, $a1, 8
  lw    $ra, 0x1c($sp)
.L7F020EE0:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

#ifdef VERSION_US
asm(R"
glabel sub_GAME_7F020EF0
  addiu $sp, $sp, -0x158
  lui   $t7, %hi(D_8002CC6C) 
  addiu $t7, %lo(D_8002CC6C) # addiu $t7, $t7, -0x3394
  sw    $ra, 0x24($sp)
  sw    $s0, 0x20($sp)
  sw    $a0, 0x158($sp)
  addiu $t0, $t7, 0x3c
  addiu $t6, $sp, 0x118
.L7F020F10:
  lw    $at, ($t7)
  addiu $t7, $t7, 0xc
  addiu $t6, $t6, 0xc
  sw    $at, -0xc($t6)
  lw    $at, -8($t7)
  sw    $at, -8($t6)
  lw    $at, -4($t7)
  bne   $t7, $t0, .L7F020F10
   sw    $at, -4($t6)
  lw    $at, ($t7)
  lui   $t4, %hi(clock_timer) 
  li    $t3, 1
  sw    $at, ($t6)
  lw    $t1, 0x158($sp)
  lw    $t4, %lo(clock_timer)($t4)
  lui   $t8, %hi(D_8002C904) 
  lw    $s0, 4($t1)
  lw    $t2, 0x1c($s0)
  sw    $t3, 0x108($sp)
  sw    $t4, 0x104($sp)
  sw    $t2, 0x110($sp)
  lw    $v0, 0x14($s0)
  andi  $t5, $v0, 0x400
  beqz  $t5, .L7F020F7C
   sll   $t9, $v0, 0xd
  bgezl $t9, .L7F02104C
   lhu   $t8, 0x12($s0)
.L7F020F7C:
  lw    $t8, %lo(D_8002C904)($t8)
  lui   $t0, %hi(D_8002C908) 
  beqz  $t8, .L7F021000
   nop   
  lw    $t0, %lo(D_8002C908)($t0)
  lui   $t6, %hi(animation_table_ptrs1)
  li    $at, 1
  sll   $t7, $t0, 2
  addu  $t6, $t6, $t7
  lw    $t6, %lo(animation_table_ptrs1)($t6)
  beq   $t6, $at, .L7F02101C
   nop   
  jal   sub_GAME_7F06F5AC
   lw    $a0, 0x110($sp)
  lui   $t1, %hi(D_8002C908) 
  lw    $t1, %lo(D_8002C908)($t1)
  lui   $a1, %hi(animation_table_ptrs1)
  lw    $a0, 0x110($sp)
  sll   $t2, $t1, 2
  addu  $a1, $a1, $t2
  lw    $a1, %lo(animation_table_ptrs1)($a1)
  move  $a2, $zero
  beq   $v0, $a1, .L7F02101C
   nop   
  mtc1  $zero, $f0
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f4
  mfc1  $a3, $f0
  swc1  $f0, 0x14($sp)
  jal   sub_GAME_7F06FCA8
   swc1  $f4, 0x10($sp)
  b     .L7F02101C
   nop   
.L7F021000:
  jal   manage_actions
   move  $a0, $s0
  lw    $t3, 0x1c($s0)
  bnez  $t3, .L7F02101C
   nop   
  b     .L7F021B0C
   li    $v0, 1
.L7F02101C:
  lui   $t4, %hi(D_8002C90C) 
  lw    $t4, %lo(D_8002C90C)($t4)
  lui   $t5, %hi(D_8002C910) 
  beql  $t4, $zero, .L7F02104C
   lhu   $t8, 0x12($s0)
  lw    $t5, %lo(D_8002C910)($t5)
  sw    $zero, 0x104($sp)
  li    $t9, 1
  beql  $t5, $zero, .L7F02104C
   lhu   $t8, 0x12($s0)
  sw    $t9, 0x104($sp)
  lhu   $t8, 0x12($s0)
.L7F02104C:
  andi  $t0, $t8, 0x20
  beql  $t0, $zero, .L7F02106C
   lw    $v0, 0x160($s0)
  jal   disable_sounds_attached_to_player_then_something
   lw    $a0, 0x158($sp)
  b     .L7F021B0C
   li    $v0, 1
  lw    $v0, 0x160($s0)
.L7F02106C:
  beql  $v0, $zero, .L7F021094
   lw    $v0, 0x164($s0)
  lw    $a0, 4($v0)
  lw    $t7, 0x64($a0)
  andi  $t6, $t7, 4
  beql  $t6, $zero, .L7F021094
   lw    $v0, 0x164($s0)
  jal   sub_GAME_7F041024
   li    $a1, 1
  lw    $v0, 0x164($s0)
.L7F021094:
  beql  $v0, $zero, .L7F0210BC
   lw    $v0, 0x14($s0)
  lw    $a0, 4($v0)
  lw    $t1, 0x64($a0)
  andi  $t2, $t1, 4
  beql  $t2, $zero, .L7F0210BC
   lw    $v0, 0x14($s0)
  jal   sub_GAME_7F041024
   li    $a1, 1
  lw    $v0, 0x14($s0)
.L7F0210BC:
  lw    $t4, 0x158($sp)
  andi  $t3, $v0, 0x400
  beql  $t3, $zero, .L7F0210DC
   lbu   $t5, ($t4)
  sw    $zero, 0x10c($sp)
  b     .L7F0213C8
   lb    $v1, 7($s0)
  lbu   $t5, ($t4)
.L7F0210DC:
  li    $at, 6
  bnel  $t5, $at, .L7F021118
   sll   $t7, $v0, 8
  jal   sub_GAME_7F09B15C
   move  $a0, $t4
  sll   $t9, $v0, 2
  lui   $t8, %hi(ptr_BONDdata_p1)
  addu  $t8, $t8, $t9
  lw    $t8, %lo(ptr_BONDdata_p1)($t8)
  li    $at, 1
  lw    $t0, ($t8)
  beql  $t0, $at, .L7F021120
   li    $t6, 1
  lw    $v0, 0x14($s0)
  sll   $t7, $v0, 8
.L7F021118:
  bgez  $t7, .L7F021178
   li    $t6, 1
.L7F021120:
  sw    $t6, 0x10c($sp)
  lb    $t1, 7($s0)
  li    $at, 3
  move  $a0, $s0
  bne   $t1, $at, .L7F021168
   nop   
  lw    $t2, 0x2c($s0)
  bnez  $t2, .L7F021168
   nop   
  lw    $t3, 0x3c($s0)
  lw    $a1, 0x104($sp)
  move  $a2, $zero
  beqz  $t3, .L7F021168
   nop   
  jal   sub_GAME_7F070AEC
   lw    $a0, 0x110($sp)
  b     .L7F021170
   nop   
.L7F021168:
  jal   sub_GAME_7F020E40
   lw    $a1, 0x104($sp)
.L7F021170:
  b     .L7F0213C8
   lb    $v1, 7($s0)
.L7F021178:
  lb    $v1, 7($s0)
  li    $a2, 14
  li    $at, 15
  beq   $a2, $v1, .L7F021194
   nop   
  bnel  $v1, $at, .L7F021294
   li    $at, 3
.L7F021194:
  bnel  $a2, $v1, .L7F0211AC
   li    $at, 15
  lb    $t5, 0x38($s0)
  li    $at, 6
  beq   $t5, $at, .L7F0211C4
   li    $at, 15
.L7F0211AC:
  bne   $v1, $at, .L7F021228
   move  $a0, $s0
  lb    $t4, 0x5c($s0)
  li    $at, 6
  bne   $t4, $at, .L7F021228
   nop   
.L7F0211C4:
  jal   getinstsize
   lw    $a0, 0x110($sp)
  lw    $a0, 0x158($sp)
  mfc1  $a2, $f0
  li    $a3, 1
  addiu $a1, $a0, 8
  jal   sub_GAME_7F054D6C
   sw    $a1, 0x30($sp)
  beqz  $v0, .L7F021288
   sw    $v0, 0x10c($sp)
  lw    $a0, 0x110($sp)
  jal   getsuboffset
   addiu $a1, $s0, 0xbc
  jal   subcalcpos
   lw    $a0, 0x110($sp)
  lw    $a0, 0x158($sp)
  jal   set_color_shading_from_tile
   addiu $a1, $s0, 0xf8
  lw    $a0, 0x110($sp)
  jal   getsuboffset
   lw    $a1, 0x30($sp)
  jal   sub_GAME_7F020D94
   move  $a0, $s0
  b     .L7F021288
   nop   
.L7F021228:
  jal   sub_GAME_7F020E40
   lw    $a1, 0x104($sp)
  jal   getinstsize
   lw    $a0, 0x110($sp)
  lw    $a0, 0x158($sp)
  mfc1  $a2, $f0
  li    $a3, 1
  jal   sub_GAME_7F054D6C
   addiu $a1, $a0, 8
  beqz  $v0, .L7F021288
   sw    $v0, 0x10c($sp)
  lb    $v1, 7($s0)
  li    $at, 14
  lui   $t0, %hi(global_timer) 
  bnel  $v1, $at, .L7F021278
   li    $at, 15
  lw    $t0, %lo(global_timer)($t0)
  b     .L7F021288
   sw    $t0, 0x78($s0)
  li    $at, 15
.L7F021278:
  bne   $v1, $at, .L7F021288
   lui   $t7, %hi(global_timer) 
  lw    $t7, %lo(global_timer)($t7)
  sw    $t7, 0x9c($s0)
.L7F021288:
  b     .L7F0213C8
   lb    $v1, 7($s0)
  li    $at, 3
.L7F021294:
  bnel  $v1, $at, .L7F021308
   li    $at, 1
  lw    $t6, 0x2c($s0)
  bnezl $t6, .L7F021308
   li    $at, 1
  jal   getinstsize
   lw    $a0, 0x110($sp)
  lw    $a0, 0x158($sp)
  mfc1  $a2, $f0
  li    $a3, 1
  jal   sub_GAME_7F054D6C
   addiu $a1, $a0, 8
  beqz  $v0, .L7F0212EC
   sw    $v0, 0x10c($sp)
  lw    $t2, 0x3c($s0)
  move  $a0, $s0
  bnezl $t2, .L7F0212F0
   lw    $a0, 0x110($sp)
  jal   sub_GAME_7F020E40
   lw    $a1, 0x104($sp)
  b     .L7F0212FC
   nop   
.L7F0212EC:
  lw    $a0, 0x110($sp)
.L7F0212F0:
  lw    $a1, 0x104($sp)
  jal   sub_GAME_7F070AEC
   move  $a2, $zero
.L7F0212FC:
  b     .L7F0213C8
   lb    $v1, 7($s0)
  li    $at, 1
.L7F021308:
  bne   $v1, $at, .L7F02137C
   andi  $t0, $v0, 0x4000
  jal   getinstsize
   lw    $a0, 0x110($sp)
  lw    $a0, 0x158($sp)
  mfc1  $a2, $f0
  li    $a3, 1
  jal   sub_GAME_7F054D6C
   addiu $a1, $a0, 8
  bnez  $v0, .L7F021344
   sw    $v0, 0x10c($sp)
  lw    $t5, 0x14($s0)
  lw    $t9, 0x110($sp)
  andi  $t4, $t5, 1
  beqz  $t4, .L7F021358
.L7F021344:
   move  $a0, $s0
  jal   sub_GAME_7F020E40
   lw    $a1, 0x104($sp)
  b     .L7F021374
   nop   
.L7F021358:
  lw    $t8, 0x54($t9)
  move  $a0, $t9
  lw    $a1, 0x104($sp)
  beqz  $t8, .L7F021374
   nop   
  jal   sub_GAME_7F070AEC
   move  $a2, $zero
.L7F021374:
  b     .L7F0213C8
   lb    $v1, 7($s0)
.L7F02137C:
  beqz  $t0, .L7F02139C
   move  $a0, $s0
  lw    $a0, 0x110($sp)
  lw    $a1, 0x104($sp)
  jal   sub_GAME_7F070AEC
   move  $a2, $zero
  b     .L7F0213A4
   nop   
.L7F02139C:
  jal   sub_GAME_7F020E40
   lw    $a1, 0x104($sp)
.L7F0213A4:
  jal   getinstsize
   lw    $a0, 0x110($sp)
  lw    $a0, 0x158($sp)
  mfc1  $a2, $f0
  li    $a3, 1
  jal   sub_GAME_7F054D6C
   addiu $a1, $a0, 8
  sw    $v0, 0x10c($sp)
  lb    $v1, 7($s0)
.L7F0213C8:
  li    $at, 1
  bne   $v1, $at, .L7F0213F4
   lw    $t6, 0x110($sp)
  lw    $t1, 0x54($t6)
  lw    $t2, 0x158($sp)
  bnezl $t1, .L7F0213F8
   lhu   $t5, 0x12($s0)
  lbu   $t3, ($t2)
  li    $at, 6
  bne   $t3, $at, .L7F021400
   nop   
.L7F0213F4:
  lhu   $t5, 0x12($s0)
.L7F0213F8:
  ori   $t4, $t5, 0x200
  sh    $t4, 0x12($s0)
.L7F021400:
  jal   sub_GAME_7F0205F0
   move  $a0, $s0
  lw    $a0, 0x20($s0)
  beql  $a0, $zero, .L7F021424
   lw    $t8, 0x10c($sp)
  jal   sub_GAME_7F06B248
   nop   
  sw    $zero, 0x20($s0)
  lw    $t8, 0x10c($sp)
.L7F021424:
  addiu $t9, $s0, 0xf8
  beql  $t8, $zero, .L7F021A34
   lw    $v0, 0x160($s0)
  jal   get_debug_chrnum_flag
   sw    $t9, 0x30($sp)
  lw    $v0, 0x158($sp)
  li    $a0, 12
  lbu   $t0, 1($v0)
  ori   $t7, $t0, 2
  sb    $t7, 1($v0)
  lw    $t6, 0x14($s0)
  ori   $t1, $t6, 8
  jal   cheatCheckIfOn
   sw    $t1, 0x14($s0)
  beqz  $v0, .L7F021470
   li    $at, 0x3EA00000 # 0.312500
  mtc1  $at, $f12
  jal   set_float_80036088
   nop   
.L7F021470:
  lui   $t2, %hi(sub_GAME_7F02083C) # $t2, 0x7f02
  addiu $t2, %lo(sub_GAME_7F02083C) # addiu $t2, $t2, 0x83c
  lui   $at, %hi(D_80036090)
  sw    $t2, %lo(D_80036090)($at)
  lui   $at, %hi(dword_CODE_bss_80069B60)
  jal   get_BONDdata_field_10CC
   sw    $s0, %lo(dword_CODE_bss_80069B60)($at)
  lw    $t3, 0x110($sp)
  sw    $v0, 0x118($sp)
  lw    $t5, 8($t3)
  lh    $a0, 0xe($t5)
  sll   $t4, $a0, 6
  jal   sub_GAME_7F0BD714
   move  $a0, $t4
  lui   $a1, %hi(dword_CODE_bss_80069B60)
  addiu $a1, %lo(dword_CODE_bss_80069B60) # addiu $a1, $a1, -0x64a0
  lw    $v1, ($a1)
  sw    $v0, 0x128($sp)
  lb    $a0, 0x11($v1)
  bltz  $a0, .L7F0214EC
   lui   $t8, %hi(clock_timer) 
  lw    $t8, %lo(clock_timer)($t8)
  li    $t7, -1
  addu  $t9, $a0, $t8
  sb    $t9, 0x11($v1)
  lw    $v1, ($a1)
  lb    $t0, 0x11($v1)
  slti  $at, $t0, 0x1e
  bnezl $at, .L7F0214F0
   addiu $a0, $sp, 0x118
  sb    $t7, 0x11($v1)
.L7F0214EC:
  addiu $a0, $sp, 0x118
.L7F0214F0:
  jal   subcalcmatrices
   lw    $a1, 0x110($sp)
  lui   $at, %hi(D_80036090)
  sw    $zero, %lo(D_80036090)($at)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f12
  jal   set_float_80036088
   nop   
  addiu $a0, $s0, 0xf4
  jal   update_color_shading
   lw    $a1, 0x30($sp)
  jal   sub_GAME_7F06C768
   lw    $a0, 0x110($sp)
  lw    $t6, 0x158($sp)
  move  $a0, $zero
  swc1  $f0, 0x18($t6)
  jal   sub_GAME_7F06B120
   lw    $a1, 0x110($sp)
  sw    $v0, 0x20($s0)
  addiu $a2, $s0, 0x20
  sw    $a2, 0x30($sp)
  lw    $a0, 0x158($sp)
  jal   sub_GAME_7F0523F8
   move  $a1, $zero
  lw    $a2, 0x30($sp)
  lw    $a0, 0x158($sp)
  jal   sub_GAME_7F0523F8
   li    $a1, 1
  lw    $v0, 0x1d8($s0)
  beql  $v0, $zero, .L7F0219D0
   lw    $t5, 0x110($sp)
  lw    $a3, 4($v0)
  lbu   $t1, 1($v0)
  move  $a2, $zero
  lw    $v1, 0x14($a3)
  ori   $t2, $t1, 2
  sb    $t2, 1($v0)
  lw    $a1, 0x1c($v1)
  lw    $a0, 0x110($sp)
  sw    $a3, 0x100($sp)
  jal   sub_GAME_7F06C660
   sw    $v1, 0xfc($sp)
  lw    $t3, 0xfc($sp)
  sw    $v0, 0x118($sp)
  lw    $t5, 8($t3)
  lh    $a0, 0xe($t5)
  sll   $t4, $a0, 6
  jal   sub_GAME_7F0BD714
   move  $a0, $t4
  sw    $v0, 0x128($sp)
  addiu $a0, $sp, 0x118
  jal   instcalcmatrices
   lw    $a1, 0xfc($sp)
  lb    $v0, 6($s0)
  slti  $at, $v0, 0x2a
  bnez  $at, .L7F021998
   slti  $at, $v0, 0x46
  beqz  $at, .L7F021998
   lui   $t9, %hi(D_8002CCAC) 
  addiu $t9, %lo(D_8002CCAC) # addiu $t9, $t9, -0x3354
  lw    $at, ($t9)
  addiu $t8, $sp, 0xf0
  lw    $t7, 4($t9)
  sw    $at, ($t8)
  lw    $at, 8($t9)
  sw    $t7, 4($t8)
  sw    $at, 8($t8)
  jal   get_hat_model
   lw    $a0, 0x1d8($s0)
  sw    $v0, 0x60($sp)
  lb    $a0, 6($s0)
  sll   $t1, $v0, 2
  subu  $t1, $t1, $v0
  addiu $a0, $a0, -0x2a
  sll   $t6, $a0, 3
  addu  $t6, $t6, $a0
  sll   $t6, $t6, 4
  sll   $t1, $t1, 3
  lui   $t3, %hi(headHat_array_8003E464) 
  addiu $t3, %lo(headHat_array_8003E464) # addiu $t3, $t3, -0x1b9c
  addu  $t2, $t6, $t1
  addu  $v1, $t2, $t3
  jal   get_debug_render_raster
   sw    $v1, 0x58($sp)
  bnez  $v0, .L7F0218EC
   lw    $v1, 0x58($sp)
  sw    $zero, 0x54($sp)
  move  $a0, $zero
  li    $a1, 32
  jal   get_controller_buttons_held
   sw    $v1, 0x58($sp)
  beqz  $v0, .L7F02179C
   lw    $v1, 0x58($sp)
  move  $a0, $zero
  li    $a1, 32768
  jal   get_controller_buttons_held
   sw    $v1, 0x58($sp)
  beqz  $v0, .L7F021698
   lw    $v1, 0x58($sp)
  lui   $at, %hi(D_80051D58)
  lwc1  $f8, %lo(D_80051D58)($at)
  lwc1  $f6, 8($v1)
  li    $t5, 1
  sub.s $f10, $f6, $f8
  swc1  $f10, 8($v1)
  sw    $t5, 0x54($sp)
.L7F021698:
  move  $a0, $zero
  li    $a1, 16384
  jal   get_controller_buttons_held
   sw    $v1, 0x58($sp)
  beqz  $v0, .L7F0216CC
   lw    $v1, 0x58($sp)
  lui   $at, %hi(D_80051D5C)
  lwc1  $f18, %lo(D_80051D5C)($at)
  lwc1  $f16, 8($v1)
  li    $t4, 1
  add.s $f4, $f16, $f18
  swc1  $f4, 8($v1)
  sw    $t4, 0x54($sp)
.L7F0216CC:
  move  $a0, $zero
  li    $a1, 4
  jal   get_controller_buttons_held
   sw    $v1, 0x58($sp)
  beqz  $v0, .L7F021700
   lw    $v1, 0x58($sp)
  lui   $at, %hi(D_80051D60)
  lwc1  $f8, %lo(D_80051D60)($at)
  lwc1  $f6, 4($v1)
  li    $t0, 1
  sub.s $f10, $f6, $f8
  swc1  $f10, 4($v1)
  sw    $t0, 0x54($sp)
.L7F021700:
  move  $a0, $zero
  li    $a1, 8
  jal   get_controller_buttons_held
   sw    $v1, 0x58($sp)
  beqz  $v0, .L7F021734
   lw    $v1, 0x58($sp)
  lui   $at, %hi(D_80051D64)
  lwc1  $f18, %lo(D_80051D64)($at)
  lwc1  $f16, 4($v1)
  li    $t8, 1
  add.s $f4, $f16, $f18
  swc1  $f4, 4($v1)
  sw    $t8, 0x54($sp)
.L7F021734:
  move  $a0, $zero
  li    $a1, 2
  jal   get_controller_buttons_held
   sw    $v1, 0x58($sp)
  beqz  $v0, .L7F021768
   lw    $v1, 0x58($sp)
  lui   $at, %hi(D_80051D68)
  lwc1  $f8, %lo(D_80051D68)($at)
  lwc1  $f6, ($v1)
  li    $t9, 1
  sub.s $f10, $f6, $f8
  swc1  $f10, ($v1)
  sw    $t9, 0x54($sp)
.L7F021768:
  move  $a0, $zero
  li    $a1, 1
  jal   get_controller_buttons_held
   sw    $v1, 0x58($sp)
  beqz  $v0, .L7F02179C
   lw    $v1, 0x58($sp)
  lui   $at, %hi(D_80051D6C)
  lwc1  $f18, %lo(D_80051D6C)($at)
  lwc1  $f16, ($v1)
  li    $t7, 1
  add.s $f4, $f16, $f18
  swc1  $f4, ($v1)
  sw    $t7, 0x54($sp)
.L7F02179C:
  move  $a0, $zero
  li    $a1, 16
  jal   get_controller_buttons_held
   sw    $v1, 0x58($sp)
  beqz  $v0, .L7F0218EC
   lw    $v1, 0x58($sp)
  move  $a0, $zero
  li    $a1, 32768
  jal   get_controller_buttons_held
   sw    $v1, 0x58($sp)
  beqz  $v0, .L7F0217E8
   lw    $v1, 0x58($sp)
  lui   $at, %hi(D_80051D70)
  lwc1  $f8, %lo(D_80051D70)($at)
  lwc1  $f6, 0x14($v1)
  li    $t6, 1
  mul.s $f10, $f6, $f8
  swc1  $f10, 0x14($v1)
  sw    $t6, 0x54($sp)
.L7F0217E8:
  move  $a0, $zero
  li    $a1, 16384
  jal   get_controller_buttons_held
   sw    $v1, 0x58($sp)
  beqz  $v0, .L7F02181C
   lw    $v1, 0x58($sp)
  lui   $at, %hi(D_80051D74)
  lwc1  $f18, %lo(D_80051D74)($at)
  lwc1  $f16, 0x14($v1)
  li    $t1, 1
  mul.s $f4, $f16, $f18
  swc1  $f4, 0x14($v1)
  sw    $t1, 0x54($sp)
.L7F02181C:
  move  $a0, $zero
  li    $a1, 4
  jal   get_controller_buttons_held
   sw    $v1, 0x58($sp)
  beqz  $v0, .L7F021850
   lw    $v1, 0x58($sp)
  lui   $at, %hi(D_80051D78)
  lwc1  $f8, %lo(D_80051D78)($at)
  lwc1  $f6, 0x10($v1)
  li    $t2, 1
  mul.s $f10, $f6, $f8
  swc1  $f10, 0x10($v1)
  sw    $t2, 0x54($sp)
.L7F021850:
  move  $a0, $zero
  li    $a1, 8
  jal   get_controller_buttons_held
   sw    $v1, 0x58($sp)
  beqz  $v0, .L7F021884
   lw    $v1, 0x58($sp)
  lui   $at, %hi(D_80051D7C)
  lwc1  $f18, %lo(D_80051D7C)($at)
  lwc1  $f16, 0x10($v1)
  li    $t3, 1
  mul.s $f4, $f16, $f18
  swc1  $f4, 0x10($v1)
  sw    $t3, 0x54($sp)
.L7F021884:
  move  $a0, $zero
  li    $a1, 2
  jal   get_controller_buttons_held
   sw    $v1, 0x58($sp)
  beqz  $v0, .L7F0218B8
   lw    $v1, 0x58($sp)
  lui   $at, %hi(D_80051D80)
  lwc1  $f8, %lo(D_80051D80)($at)
  lwc1  $f6, 0xc($v1)
  li    $t5, 1
  mul.s $f10, $f6, $f8
  swc1  $f10, 0xc($v1)
  sw    $t5, 0x54($sp)
.L7F0218B8:
  move  $a0, $zero
  li    $a1, 1
  jal   get_controller_buttons_held
   sw    $v1, 0x58($sp)
  beqz  $v0, .L7F0218EC
   lw    $v1, 0x58($sp)
  lui   $at, %hi(D_80051D84)
  lwc1  $f18, %lo(D_80051D84)($at)
  lwc1  $f16, 0xc($v1)
  li    $t4, 1
  mul.s $f4, $f16, $f18
  swc1  $f4, 0xc($v1)
  sw    $t4, 0x54($sp)
.L7F0218EC:
  lui   $at, %hi(D_80051D88)
  lwc1  $f0, %lo(D_80051D88)($at)
  lwc1  $f6, ($v1)
  addiu $a0, $sp, 0xf0
  addiu $a1, $sp, 0xa4
  mul.s $f8, $f6, $f0
  swc1  $f8, 0xf0($sp)
  lwc1  $f10, 4($v1)
  mul.s $f16, $f10, $f0
  swc1  $f16, 0xf4($sp)
  lwc1  $f18, 8($v1)
  mul.s $f4, $f18, $f0
  swc1  $f4, 0xf8($sp)
  lwc1  $f6, 0xc($v1)
  swc1  $f6, 0xec($sp)
  lwc1  $f8, 0x10($v1)
  swc1  $f8, 0xe8($sp)
  lwc1  $f10, 0x14($v1)
  jal   init_something_copy_posdata_to_it
   swc1  $f10, 0xe4($sp)
  lwc1  $f12, 0xec($sp)
  jal   sub_GAME_7F0589B4
   addiu $a1, $sp, 0xa4
  lwc1  $f12, 0xe8($sp)
  jal   sub_GAME_7F0589E4
   addiu $a1, $sp, 0xa4
  lwc1  $f12, 0xe4($sp)
  jal   sub_GAME_7F058A4C
   addiu $a1, $sp, 0xa4
  lw    $t0, 0xfc($sp)
  addiu $a1, $sp, 0xa4
  addiu $a2, $sp, 0x64
  jal   sub_GAME_7F05818C
   lw    $a0, 0xc($t0)
  lw    $t8, 0xfc($sp)
  addiu $a0, $sp, 0x64
  jal   sub_GAME_7F058020
   lw    $a1, 0xc($t8)
  lw    $t9, 0x60($sp)
  li    $at, 2
  bnel  $t9, $at, .L7F02199C
   lhu   $t7, 0x12($s0)
  sw    $zero, 0x108($sp)
.L7F021998:
  lhu   $t7, 0x12($s0)
.L7F02199C:
  lw    $t1, 0x100($sp)
  lw    $a1, 0xfc($sp)
  andi  $t6, $t7, 1
  beqz  $t6, .L7F0219C0
   nop   
  lw    $t2, 0x64($t1)
  andi  $t3, $t2, 0x80
  bnezl $t3, .L7F0219D0
   lw    $t5, 0x110($sp)
.L7F0219C0:
  jal   sub_GAME_7F06B120
   lw    $a0, 0x20($s0)
  sw    $v0, 0x20($s0)
  lw    $t5, 0x110($sp)
.L7F0219D0:
  lw    $t4, 8($t5)
  lw    $t0, 8($t4)
  lw    $a1, 0x10($t0)
  beqz  $a1, .L7F021A18
   nop   
  jal   extract_id_from_object_structure_microcode
   move  $a0, $t5
  lw    $v1, ($v0)
  beqz  $v1, .L7F021A18
   nop   
  lw    $t8, 8($v1)
  lw    $a1, 4($t8)
  beqz  $a1, .L7F021A18
   nop   
  jal   extract_id_from_object_structure_microcode
   lw    $a0, 0x110($sp)
  lw    $t9, 0x108($sp)
  sw    $t9, ($v0)
.L7F021A18:
  jal   sub_GAME_7F06B29C
   lw    $a0, 0x20($s0)
  jal   sub_GAME_7F06BB28
   lw    $a0, 0x20($s0)
  b     .L7F021AAC
   sw    $v0, 0x20($s0)
  lw    $v0, 0x160($s0)
.L7F021A34:
  beql  $v0, $zero, .L7F021A4C
   lw    $v0, 0x164($s0)
  lbu   $t7, 1($v0)
  andi  $t6, $t7, 0xfffd
  sb    $t6, 1($v0)
  lw    $v0, 0x164($s0)
.L7F021A4C:
  li    $v1, -3
  beql  $v0, $zero, .L7F021A68
   lw    $v0, 0x1d8($s0)
  lbu   $t1, 1($v0)
  and   $t2, $t1, $v1
  sb    $t2, 1($v0)
  lw    $v0, 0x1d8($s0)
.L7F021A68:
  beql  $v0, $zero, .L7F021A80
   lw    $t0, 0x158($sp)
  lbu   $t3, 1($v0)
  and   $t4, $t3, $v1
  sb    $t4, 1($v0)
  lw    $t0, 0x158($sp)
.L7F021A80:
  lbu   $t5, 1($t0)
  and   $t8, $t5, $v1
  sb    $t8, 1($t0)
  lbu   $t9, 0xf8($s0)
  lbu   $t7, 0xf9($s0)
  lbu   $t6, 0xfa($s0)
  lbu   $t1, 0xfb($s0)
  sb    $t9, 0xf4($s0)
  sb    $t7, 0xf5($s0)
  sb    $t6, 0xf6($s0)
  sb    $t1, 0xf7($s0)
.L7F021AAC:
  lw    $t2, 0x14($s0)
  andi  $t3, $t2, 0x400
  bnezl $t3, .L7F021B0C
   move  $v0, $zero
  lhu   $v0, 0x12($s0)
  lw    $t5, 0x158($sp)
  andi  $t4, $v0, 1
  beqz  $t4, .L7F021B00
   nop   
  lw    $a0, 0x20($t5)
  beql  $a0, $zero, .L7F021AFC
   andi  $t8, $v0, 0xfffe
  lw    $v1, 0x24($a0)
.L7F021AE0:
  jal   sub_GAME_7F04C130
   sw    $v1, 0x3c($sp)
  lw    $a0, 0x3c($sp)
  bnezl $a0, .L7F021AE0
   lw    $v1, 0x24($a0)
  lhu   $v0, 0x12($s0)
  andi  $t8, $v0, 0xfffe
.L7F021AFC:
  sh    $t8, 0x12($s0)
.L7F021B00:
  jal   sub_GAME_7F02E26C
   move  $a0, $s0
  move  $v0, $zero
.L7F021B0C:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0x158
  jr    $ra
   nop   
");
#endif

#ifdef VERSION_JP
asm(R"
glabel sub_GAME_7F020EF0
  addiu $sp, $sp, -0x158
  lui   $t7, %hi(D_8002CC6C) # $t7, 0x8003
  addiu $t7, %lo(D_8002CC6C) # addiu $t7, $t7, -0x3354
  sw    $ra, 0x24($sp)
  sw    $s0, 0x20($sp)
  sw    $a0, 0x158($sp)
  addiu $t0, $t7, 0x3c
  addiu $t6, $sp, 0x118
.Ljp7F0211A8:
  lw    $at, ($t7)
  addiu $t7, $t7, 0xc
  addiu $t6, $t6, 0xc
  sw    $at, -0xc($t6)
  lw    $at, -8($t7)
  sw    $at, -8($t6)
  lw    $at, -4($t7)
  bne   $t7, $t0, .Ljp7F0211A8
   sw    $at, -4($t6)
  lw    $at, ($t7)
  lui   $t4, %hi(clock_timer) # $t4, 0x8005
  li    $t3, 1
  sw    $at, ($t6)
  lw    $t1, 0x158($sp)
  lw    $t4, %lo(clock_timer)($t4)
  lui   $t8, %hi(D_8002C904) # $t8, 0x8003
  lw    $s0, 4($t1)
  lw    $t2, 0x1c($s0)
  sw    $t3, 0x108($sp)
  sw    $t4, 0x104($sp)
  sw    $t2, 0x110($sp)
  lw    $v0, 0x14($s0)
  andi  $t5, $v0, 0x400
  beqz  $t5, .Ljp7F021214
   sll   $t9, $v0, 0xd
  bgezl $t9, .Ljp7F0212E4
   lhu   $t8, 0x12($s0)
.Ljp7F021214:
  lw    $t8, %lo(D_8002C904)($t8)
  lui   $t0, %hi(D_8002C908) # $t0, 0x8003
  beqz  $t8, .Ljp7F021298
   nop   
  lw    $t0, %lo(D_8002C908)($t0)
  lui   $t6, %hi(animation_table_ptrs1)
  li    $at, 1
  sll   $t7, $t0, 2
  addu  $t6, $t6, $t7
  lw    $t6, %lo(animation_table_ptrs1)($t6)
  beq   $t6, $at, .Ljp7F0212B4
   nop   
  jal   sub_GAME_7F06F5AC
   lw    $a0, 0x110($sp)
  lui   $t1, %hi(D_8002C908) # $t1, 0x8003
  lw    $t1, %lo(D_8002C908)($t1)
  lui   $a1, %hi(animation_table_ptrs1)
  lw    $a0, 0x110($sp)
  sll   $t2, $t1, 2
  addu  $a1, $a1, $t2
  lw    $a1, %lo(animation_table_ptrs1)($a1)
  move  $a2, $zero
  beq   $v0, $a1, .Ljp7F0212B4
   nop   
  mtc1  $zero, $f0
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f4
  mfc1  $a3, $f0
  swc1  $f0, 0x14($sp)
  jal   sub_GAME_7F06FCA8
   swc1  $f4, 0x10($sp)
  b     .Ljp7F0212B4
   nop   
.Ljp7F021298:
  jal   manage_actions
   move  $a0, $s0
  lw    $t3, 0x1c($s0)
  bnez  $t3, .Ljp7F0212B4
   nop   
  b     .Ljp7F021DF4
   li    $v0, 1
.Ljp7F0212B4:
  lui   $t4, %hi(D_8002C90C) # $t4, 0x8003
  lw    $t4, %lo(D_8002C90C)($t4)
  lui   $t5, %hi(D_8002C910) # $t5, 0x8003
  beql  $t4, $zero, .Ljp7F0212E4
   lhu   $t8, 0x12($s0)
  lw    $t5, %lo(D_8002C910)($t5)
  sw    $zero, 0x104($sp)
  li    $t9, 1
  beql  $t5, $zero, .Ljp7F0212E4
   lhu   $t8, 0x12($s0)
  sw    $t9, 0x104($sp)
  lhu   $t8, 0x12($s0)
.Ljp7F0212E4:
  andi  $t0, $t8, 0x20
  beql  $t0, $zero, .Ljp7F021304
   lw    $v0, 0x160($s0)
  jal   disable_sounds_attached_to_player_then_something
   lw    $a0, 0x158($sp)
  b     .Ljp7F021DF4
   li    $v0, 1
  lw    $v0, 0x160($s0)
.Ljp7F021304:
  beql  $v0, $zero, .Ljp7F02132C
   lw    $v0, 0x164($s0)
  lw    $a0, 4($v0)
  lw    $t7, 0x64($a0)
  andi  $t6, $t7, 4
  beql  $t6, $zero, .Ljp7F02132C
   lw    $v0, 0x164($s0)
  jal   sub_GAME_7F041024
   li    $a1, 1
  lw    $v0, 0x164($s0)
.Ljp7F02132C:
  beql  $v0, $zero, .Ljp7F021354
   lw    $v0, 0x14($s0)
  lw    $a0, 4($v0)
  lw    $t1, 0x64($a0)
  andi  $t2, $t1, 4
  beql  $t2, $zero, .Ljp7F021354
   lw    $v0, 0x14($s0)
  jal   sub_GAME_7F041024
   li    $a1, 1
  lw    $v0, 0x14($s0)
.Ljp7F021354:
  lw    $t4, 0x158($sp)
  andi  $t3, $v0, 0x400
  beql  $t3, $zero, .Ljp7F021374
   lbu   $t5, ($t4)
  sw    $zero, 0x10c($sp)
  b     .Ljp7F021660
   lb    $v1, 7($s0)
  lbu   $t5, ($t4)
.Ljp7F021374:
  li    $at, 6
  bnel  $t5, $at, .Ljp7F0213B0
   sll   $t7, $v0, 8
  jal   sub_GAME_7F09B15C
   move  $a0, $t4
  sll   $t9, $v0, 2
  lui   $t8, %hi(ptr_BONDdata_p1)
  addu  $t8, $t8, $t9
  lw    $t8, %lo(ptr_BONDdata_p1)($t8)
  li    $at, 1
  lw    $t0, ($t8)
  beql  $t0, $at, .Ljp7F0213B8
   li    $t6, 1
  lw    $v0, 0x14($s0)
  sll   $t7, $v0, 8
.Ljp7F0213B0:
  bgez  $t7, .Ljp7F021410
   li    $t6, 1
.Ljp7F0213B8:
  sw    $t6, 0x10c($sp)
  lb    $t1, 7($s0)
  li    $at, 3
  move  $a0, $s0
  bne   $t1, $at, .Ljp7F021400
   nop   
  lw    $t2, 0x2c($s0)
  bnez  $t2, .Ljp7F021400
   nop   
  lw    $t3, 0x3c($s0)
  lw    $a1, 0x104($sp)
  move  $a2, $zero
  beqz  $t3, .Ljp7F021400
   nop   
  jal   sub_GAME_7F070AEC
   lw    $a0, 0x110($sp)
  b     .Ljp7F021408
   nop   
.Ljp7F021400:
  jal   sub_GAME_7F020E40
   lw    $a1, 0x104($sp)
.Ljp7F021408:
  b     .Ljp7F021660
   lb    $v1, 7($s0)
.Ljp7F021410:
  lb    $v1, 7($s0)
  li    $a2, 14
  li    $at, 15
  beq   $a2, $v1, .Ljp7F02142C
   nop   
  bnel  $v1, $at, .Ljp7F02152C
   li    $at, 3
.Ljp7F02142C:
  bnel  $a2, $v1, .Ljp7F021444
   li    $at, 15
  lb    $t5, 0x38($s0)
  li    $at, 6
  beq   $t5, $at, .Ljp7F02145C
   li    $at, 15
.Ljp7F021444:
  bne   $v1, $at, .Ljp7F0214C0
   move  $a0, $s0
  lb    $t4, 0x5c($s0)
  li    $at, 6
  bne   $t4, $at, .Ljp7F0214C0
   nop   
.Ljp7F02145C:
  jal   getinstsize
   lw    $a0, 0x110($sp)
  lw    $a0, 0x158($sp)
  mfc1  $a2, $f0
  li    $a3, 1
  addiu $a1, $a0, 8
  jal   sub_GAME_7F054D6C
   sw    $a1, 0x30($sp)
  beqz  $v0, .Ljp7F021520
   sw    $v0, 0x10c($sp)
  lw    $a0, 0x110($sp)
  jal   getsuboffset
   addiu $a1, $s0, 0xbc
  jal   subcalcpos
   lw    $a0, 0x110($sp)
  lw    $a0, 0x158($sp)
  jal   set_color_shading_from_tile
   addiu $a1, $s0, 0xf8
  lw    $a0, 0x110($sp)
  jal   getsuboffset
   lw    $a1, 0x30($sp)
  jal   sub_GAME_7F020D94
   move  $a0, $s0
  b     .Ljp7F021520
   nop   
.Ljp7F0214C0:
  jal   sub_GAME_7F020E40
   lw    $a1, 0x104($sp)
  jal   getinstsize
   lw    $a0, 0x110($sp)
  lw    $a0, 0x158($sp)
  mfc1  $a2, $f0
  li    $a3, 1
  jal   sub_GAME_7F054D6C
   addiu $a1, $a0, 8
  beqz  $v0, .Ljp7F021520
   sw    $v0, 0x10c($sp)
  lb    $v1, 7($s0)
  li    $at, 14
  lui   $t0, %hi(global_timer) # $t0, 0x8005
  bnel  $v1, $at, .Ljp7F021510
   li    $at, 15
  lw    $t0, %lo(global_timer)($t0)
  b     .Ljp7F021520
   sw    $t0, 0x78($s0)
  li    $at, 15
.Ljp7F021510:
  bne   $v1, $at, .Ljp7F021520
   lui   $t7, %hi(global_timer) # $t7, 0x8005
  lw    $t7, %lo(global_timer)($t7)
  sw    $t7, 0x9c($s0)
.Ljp7F021520:
  b     .Ljp7F021660
   lb    $v1, 7($s0)
  li    $at, 3
.Ljp7F02152C:
  bnel  $v1, $at, .Ljp7F0215A0
   li    $at, 1
  lw    $t6, 0x2c($s0)
  bnezl $t6, .Ljp7F0215A0
   li    $at, 1
  jal   getinstsize
   lw    $a0, 0x110($sp)
  lw    $a0, 0x158($sp)
  mfc1  $a2, $f0
  li    $a3, 1
  jal   sub_GAME_7F054D6C
   addiu $a1, $a0, 8
  beqz  $v0, .Ljp7F021584
   sw    $v0, 0x10c($sp)
  lw    $t2, 0x3c($s0)
  move  $a0, $s0
  bnezl $t2, .Ljp7F021588
   lw    $a0, 0x110($sp)
  jal   sub_GAME_7F020E40
   lw    $a1, 0x104($sp)
  b     .Ljp7F021594
   nop   
.Ljp7F021584:
  lw    $a0, 0x110($sp)
.Ljp7F021588:
  lw    $a1, 0x104($sp)
  jal   sub_GAME_7F070AEC
   move  $a2, $zero
.Ljp7F021594:
  b     .Ljp7F021660
   lb    $v1, 7($s0)
  li    $at, 1
.Ljp7F0215A0:
  bne   $v1, $at, .Ljp7F021614
   andi  $t0, $v0, 0x4000
  jal   getinstsize
   lw    $a0, 0x110($sp)
  lw    $a0, 0x158($sp)
  mfc1  $a2, $f0
  li    $a3, 1
  jal   sub_GAME_7F054D6C
   addiu $a1, $a0, 8
  bnez  $v0, .Ljp7F0215DC
   sw    $v0, 0x10c($sp)
  lw    $t5, 0x14($s0)
  lw    $t9, 0x110($sp)
  andi  $t4, $t5, 1
  beqz  $t4, .Ljp7F0215F0
.Ljp7F0215DC:
   move  $a0, $s0
  jal   sub_GAME_7F020E40
   lw    $a1, 0x104($sp)
  b     .Ljp7F02160C
   nop   
.Ljp7F0215F0:
  lw    $t8, 0x54($t9)
  move  $a0, $t9
  lw    $a1, 0x104($sp)
  beqz  $t8, .Ljp7F02160C
   nop   
  jal   sub_GAME_7F070AEC
   move  $a2, $zero
.Ljp7F02160C:
  b     .Ljp7F021660
   lb    $v1, 7($s0)
.Ljp7F021614:
  beqz  $t0, .Ljp7F021634
   move  $a0, $s0
  lw    $a0, 0x110($sp)
  lw    $a1, 0x104($sp)
  jal   sub_GAME_7F070AEC
   move  $a2, $zero
  b     .Ljp7F02163C
   nop   
.Ljp7F021634:
  jal   sub_GAME_7F020E40
   lw    $a1, 0x104($sp)
.Ljp7F02163C:
  jal   getinstsize
   lw    $a0, 0x110($sp)
  lw    $a0, 0x158($sp)
  mfc1  $a2, $f0
  li    $a3, 1
  jal   sub_GAME_7F054D6C
   addiu $a1, $a0, 8
  sw    $v0, 0x10c($sp)
  lb    $v1, 7($s0)
.Ljp7F021660:
  li    $at, 1
  bne   $v1, $at, .Ljp7F02168C
   lw    $t6, 0x110($sp)
  lw    $t1, 0x54($t6)
  lw    $t2, 0x158($sp)
  bnezl $t1, .Ljp7F021690
   lhu   $t5, 0x12($s0)
  lbu   $t3, ($t2)
  li    $at, 6
  bne   $t3, $at, .Ljp7F021698
   nop   
.Ljp7F02168C:
  lhu   $t5, 0x12($s0)
.Ljp7F021690:
  ori   $t4, $t5, 0x200
  sh    $t4, 0x12($s0)
.Ljp7F021698:
  jal   sub_GAME_7F0205F0
   move  $a0, $s0
  lw    $a0, 0x20($s0)
  beql  $a0, $zero, .Ljp7F0216BC
   lw    $t8, 0x10c($sp)
  jal   sub_GAME_7F06B248
   nop   
  sw    $zero, 0x20($s0)
  lw    $t8, 0x10c($sp)
.Ljp7F0216BC:
  addiu $t9, $s0, 0xf8
  beql  $t8, $zero, .Ljp7F021D1C
   lw    $v0, 0x160($s0)
  jal   get_debug_chrnum_flag
   sw    $t9, 0x2c($sp)
  lw    $v0, 0x158($sp)
  li    $a0, 12
  lbu   $t0, 1($v0)
  ori   $t7, $t0, 2
  sb    $t7, 1($v0)
  lw    $t6, 0x14($s0)
  ori   $t1, $t6, 8
  jal   cheatCheckIfOn
   sw    $t1, 0x14($s0)
  beqz  $v0, .Ljp7F021758
   nop   
  lb    $a0, 0xf($s0)
  jal   jp_only_7F0209EC
   lb    $a1, 6($s0)
  beqz  $v0, .Ljp7F021758
   li    $at, 0x3EA00000 # 0.312500
  mtc1  $at, $f12
  jal   set_float_80036088
   nop   
  lw    $v0, 0x14($s0)
  lui   $at, (0xEFFFFFFF >> 16) # lui $at, 0xefff
  ori   $at, (0xEFFFFFFF & 0xFFFF) # ori $at, $at, 0xffff
  sll   $t2, $v0, 3
  bgez  $t2, .Ljp7F021758
   and   $t3, $v0, $at
  lw    $a0, 0x1c($s0)
  sw    $t3, 0x14($s0)
  lui   $at, %hi(D_jp80051D88) # $at, 0x8005
  lwc1  $f8, %lo(D_jp80051D88)($at)
  lwc1  $f6, 0x14($a0)
  div.s $f10, $f6, $f8
  mfc1  $a1, $f10
  jal   set_obj_instance_controller_scale
   nop   
.Ljp7F021758:
  lui   $t5, %hi(sub_GAME_7F02083C) # $t5, 0x7f02
  addiu $t5, %lo(sub_GAME_7F02083C) # addiu $t5, $t5, 0xaac
  lui   $at, %hi(D_80036090) # $at, 0x8003
  sw    $t5, %lo(D_80036090)($at)
  lui   $at, %hi(dword_CODE_bss_80069B60) # $at, 0x8007
  jal   get_BONDdata_field_10CC
   sw    $s0, %lo(dword_CODE_bss_80069B60)($at)
  lw    $t4, 0x110($sp)
  sw    $v0, 0x118($sp)
  lw    $t8, 8($t4)
  lh    $a0, 0xe($t8)
  sll   $t9, $a0, 6
  jal   sub_GAME_7F0BD714
   move  $a0, $t9
  lui   $a1, %hi(dword_CODE_bss_80069B60) # $a1, 0x8007
  addiu $a1, %lo(dword_CODE_bss_80069B60) # addiu $a1, $a1, -0x6460
  lw    $v1, ($a1)
  sw    $v0, 0x128($sp)
  lb    $a0, 0x11($v1)
  bltz  $a0, .Ljp7F0217D4
   lui   $t0, %hi(clock_timer) # $t0, 0x8005
  lw    $t0, %lo(clock_timer)($t0)
  li    $t1, -1
  addu  $t7, $a0, $t0
  sb    $t7, 0x11($v1)
  lw    $v1, ($a1)
  lb    $t6, 0x11($v1)
  slti  $at, $t6, 0x1e
  bnezl $at, .Ljp7F0217D8
   addiu $a0, $sp, 0x118
  sb    $t1, 0x11($v1)
.Ljp7F0217D4:
  addiu $a0, $sp, 0x118
.Ljp7F0217D8:
  jal   subcalcmatrices
   lw    $a1, 0x110($sp)
  lui   $at, %hi(D_80036090) # $at, 0x8003
  sw    $zero, %lo(D_80036090)($at)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f12
  jal   set_float_80036088
   nop   
  addiu $a0, $s0, 0xf4
  jal   update_color_shading
   lw    $a1, 0x2c($sp)
  jal   sub_GAME_7F06C768
   lw    $a0, 0x110($sp)
  lw    $t2, 0x158($sp)
  move  $a0, $zero
  swc1  $f0, 0x18($t2)
  jal   sub_GAME_7F06B120
   lw    $a1, 0x110($sp)
  sw    $v0, 0x20($s0)
  addiu $a2, $s0, 0x20
  sw    $a2, 0x30($sp)
  lw    $a0, 0x158($sp)
  jal   sub_GAME_7F0523F8
   move  $a1, $zero
  lw    $a2, 0x30($sp)
  lw    $a0, 0x158($sp)
  jal   sub_GAME_7F0523F8
   li    $a1, 1
  lw    $v0, 0x1d8($s0)
  beql  $v0, $zero, .Ljp7F021CB8
   lw    $t8, 0x110($sp)
  lw    $a3, 4($v0)
  lbu   $t3, 1($v0)
  move  $a2, $zero
  lw    $v1, 0x14($a3)
  ori   $t5, $t3, 2
  sb    $t5, 1($v0)
  lw    $a1, 0x1c($v1)
  lw    $a0, 0x110($sp)
  sw    $a3, 0x100($sp)
  jal   sub_GAME_7F06C660
   sw    $v1, 0xfc($sp)
  lw    $t4, 0xfc($sp)
  sw    $v0, 0x118($sp)
  lw    $t8, 8($t4)
  lh    $a0, 0xe($t8)
  sll   $t9, $a0, 6
  jal   sub_GAME_7F0BD714
   move  $a0, $t9
  sw    $v0, 0x128($sp)
  addiu $a0, $sp, 0x118
  jal   instcalcmatrices
   lw    $a1, 0xfc($sp)
  lb    $v0, 6($s0)
  slti  $at, $v0, 0x2a
  bnez  $at, .Ljp7F021C80
   slti  $at, $v0, 0x46
  beqz  $at, .Ljp7F021C80
   lui   $t7, %hi(D_8002CCAC) # $t7, 0x8003
  addiu $t7, %lo(D_8002CCAC) # addiu $t7, $t7, -0x3314
  lw    $at, ($t7)
  addiu $t0, $sp, 0xf0
  lw    $t1, 4($t7)
  sw    $at, ($t0)
  lw    $at, 8($t7)
  sw    $t1, 4($t0)
  sw    $at, 8($t0)
  jal   get_hat_model
   lw    $a0, 0x1d8($s0)
  sw    $v0, 0x60($sp)
  lb    $a0, 6($s0)
  sll   $t3, $v0, 2
  subu  $t3, $t3, $v0
  addiu $a0, $a0, -0x2a
  sll   $t2, $a0, 3
  addu  $t2, $t2, $a0
  sll   $t2, $t2, 4
  sll   $t3, $t3, 3
  lui   $t4, %hi(headHat_array_8003E464) # $t4, 0x8004
  addiu $t4, %lo(headHat_array_8003E464) # addiu $t4, $t4, -0x1b6c
  addu  $t5, $t2, $t3
  addu  $v1, $t5, $t4
  jal   get_debug_render_raster
   sw    $v1, 0x58($sp)
  bnez  $v0, .Ljp7F021BD4
   lw    $v1, 0x58($sp)
  sw    $zero, 0x54($sp)
  move  $a0, $zero
  li    $a1, 32
  jal   get_controller_buttons_held
   sw    $v1, 0x58($sp)
  beqz  $v0, .Ljp7F021A84
   lw    $v1, 0x58($sp)
  move  $a0, $zero
  li    $a1, 32768
  jal   get_controller_buttons_held
   sw    $v1, 0x58($sp)
  beqz  $v0, .Ljp7F021980
   lw    $v1, 0x58($sp)
  lui   $at, %hi(D_80051D58) # $at, 0x8005
  lwc1  $f18, %lo(D_80051D58)($at)
  lwc1  $f16, 8($v1)
  li    $t8, 1
  sub.s $f4, $f16, $f18
  swc1  $f4, 8($v1)
  sw    $t8, 0x54($sp)
.Ljp7F021980:
  move  $a0, $zero
  li    $a1, 16384
  jal   get_controller_buttons_held
   sw    $v1, 0x58($sp)
  beqz  $v0, .Ljp7F0219B4
   lw    $v1, 0x58($sp)
  lui   $at, %hi(D_80051D5C) # $at, 0x8005
  lwc1  $f8, %lo(D_80051D5C)($at)
  lwc1  $f6, 8($v1)
  li    $t9, 1
  add.s $f10, $f6, $f8
  swc1  $f10, 8($v1)
  sw    $t9, 0x54($sp)
.Ljp7F0219B4:
  move  $a0, $zero
  li    $a1, 4
  jal   get_controller_buttons_held
   sw    $v1, 0x58($sp)
  beqz  $v0, .Ljp7F0219E8
   lw    $v1, 0x58($sp)
  lui   $at, %hi(D_80051D60) # $at, 0x8005
  lwc1  $f18, %lo(D_80051D60)($at)
  lwc1  $f16, 4($v1)
  li    $t6, 1
  sub.s $f4, $f16, $f18
  swc1  $f4, 4($v1)
  sw    $t6, 0x54($sp)
.Ljp7F0219E8:
  move  $a0, $zero
  li    $a1, 8
  jal   get_controller_buttons_held
   sw    $v1, 0x58($sp)
  beqz  $v0, .Ljp7F021A1C
   lw    $v1, 0x58($sp)
  lui   $at, %hi(D_80051D64) # $at, 0x8005
  lwc1  $f8, %lo(D_80051D64)($at)
  lwc1  $f6, 4($v1)
  li    $t0, 1
  add.s $f10, $f6, $f8
  swc1  $f10, 4($v1)
  sw    $t0, 0x54($sp)
.Ljp7F021A1C:
  move  $a0, $zero
  li    $a1, 2
  jal   get_controller_buttons_held
   sw    $v1, 0x58($sp)
  beqz  $v0, .Ljp7F021A50
   lw    $v1, 0x58($sp)
  lui   $at, %hi(D_80051D68) # $at, 0x8005
  lwc1  $f18, %lo(D_80051D68)($at)
  lwc1  $f16, ($v1)
  li    $t7, 1
  sub.s $f4, $f16, $f18
  swc1  $f4, ($v1)
  sw    $t7, 0x54($sp)
.Ljp7F021A50:
  move  $a0, $zero
  li    $a1, 1
  jal   get_controller_buttons_held
   sw    $v1, 0x58($sp)
  beqz  $v0, .Ljp7F021A84
   lw    $v1, 0x58($sp)
  lui   $at, %hi(D_80051D6C) # $at, 0x8005
  lwc1  $f8, %lo(D_80051D6C)($at)
  lwc1  $f6, ($v1)
  li    $t1, 1
  add.s $f10, $f6, $f8
  swc1  $f10, ($v1)
  sw    $t1, 0x54($sp)
.Ljp7F021A84:
  move  $a0, $zero
  li    $a1, 16
  jal   get_controller_buttons_held
   sw    $v1, 0x58($sp)
  beqz  $v0, .Ljp7F021BD4
   lw    $v1, 0x58($sp)
  move  $a0, $zero
  li    $a1, 32768
  jal   get_controller_buttons_held
   sw    $v1, 0x58($sp)
  beqz  $v0, .Ljp7F021AD0
   lw    $v1, 0x58($sp)
  lui   $at, %hi(D_80051D70) # $at, 0x8005
  lwc1  $f18, %lo(D_80051D70)($at)
  lwc1  $f16, 0x14($v1)
  li    $t2, 1
  mul.s $f4, $f16, $f18
  swc1  $f4, 0x14($v1)
  sw    $t2, 0x54($sp)
.Ljp7F021AD0:
  move  $a0, $zero
  li    $a1, 16384
  jal   get_controller_buttons_held
   sw    $v1, 0x58($sp)
  beqz  $v0, .Ljp7F021B04
   lw    $v1, 0x58($sp)
  lui   $at, %hi(D_80051D74) # $at, 0x8005
  lwc1  $f8, %lo(D_80051D74)($at)
  lwc1  $f6, 0x14($v1)
  li    $t3, 1
  mul.s $f10, $f6, $f8
  swc1  $f10, 0x14($v1)
  sw    $t3, 0x54($sp)
.Ljp7F021B04:
  move  $a0, $zero
  li    $a1, 4
  jal   get_controller_buttons_held
   sw    $v1, 0x58($sp)
  beqz  $v0, .Ljp7F021B38
   lw    $v1, 0x58($sp)
  lui   $at, %hi(D_80051D78) # $at, 0x8005
  lwc1  $f18, %lo(D_80051D78)($at)
  lwc1  $f16, 0x10($v1)
  li    $t5, 1
  mul.s $f4, $f16, $f18
  swc1  $f4, 0x10($v1)
  sw    $t5, 0x54($sp)
.Ljp7F021B38:
  move  $a0, $zero
  li    $a1, 8
  jal   get_controller_buttons_held
   sw    $v1, 0x58($sp)
  beqz  $v0, .Ljp7F021B6C
   lw    $v1, 0x58($sp)
  lui   $at, %hi(D_80051D7C) # $at, 0x8005
  lwc1  $f8, %lo(D_80051D7C)($at)
  lwc1  $f6, 0x10($v1)
  li    $t4, 1
  mul.s $f10, $f6, $f8
  swc1  $f10, 0x10($v1)
  sw    $t4, 0x54($sp)
.Ljp7F021B6C:
  move  $a0, $zero
  li    $a1, 2
  jal   get_controller_buttons_held
   sw    $v1, 0x58($sp)
  beqz  $v0, .Ljp7F021BA0
   lw    $v1, 0x58($sp)
  lui   $at, %hi(D_80051D80) # $at, 0x8005
  lwc1  $f18, %lo(D_80051D80)($at)
  lwc1  $f16, 0xc($v1)
  li    $t8, 1
  mul.s $f4, $f16, $f18
  swc1  $f4, 0xc($v1)
  sw    $t8, 0x54($sp)
.Ljp7F021BA0:
  move  $a0, $zero
  li    $a1, 1
  jal   get_controller_buttons_held
   sw    $v1, 0x58($sp)
  beqz  $v0, .Ljp7F021BD4
   lw    $v1, 0x58($sp)
  lui   $at, %hi(D_80051D84) # $at, 0x8005
  lwc1  $f8, %lo(D_80051D84)($at)
  lwc1  $f6, 0xc($v1)
  li    $t9, 1
  mul.s $f10, $f6, $f8
  swc1  $f10, 0xc($v1)
  sw    $t9, 0x54($sp)
.Ljp7F021BD4:
  lui   $at, %hi(D_80051D88) # $at, 0x8005
  lwc1  $f0, %lo(D_80051D88)($at)
  lwc1  $f16, ($v1)
  addiu $a0, $sp, 0xf0
  addiu $a1, $sp, 0xa4
  mul.s $f18, $f16, $f0
  swc1  $f18, 0xf0($sp)
  lwc1  $f4, 4($v1)
  mul.s $f6, $f4, $f0
  swc1  $f6, 0xf4($sp)
  lwc1  $f8, 8($v1)
  mul.s $f10, $f8, $f0
  swc1  $f10, 0xf8($sp)
  lwc1  $f16, 0xc($v1)
  swc1  $f16, 0xec($sp)
  lwc1  $f18, 0x10($v1)
  swc1  $f18, 0xe8($sp)
  lwc1  $f4, 0x14($v1)
  jal   init_something_copy_posdata_to_it
   swc1  $f4, 0xe4($sp)
  lwc1  $f12, 0xec($sp)
  jal   sub_GAME_7F0589B4
   addiu $a1, $sp, 0xa4
  lwc1  $f12, 0xe8($sp)
  jal   sub_GAME_7F0589E4
   addiu $a1, $sp, 0xa4
  lwc1  $f12, 0xe4($sp)
  jal   sub_GAME_7F058A4C
   addiu $a1, $sp, 0xa4
  lw    $t6, 0xfc($sp)
  addiu $a1, $sp, 0xa4
  addiu $a2, $sp, 0x64
  jal   sub_GAME_7F05818C
   lw    $a0, 0xc($t6)
  lw    $t0, 0xfc($sp)
  addiu $a0, $sp, 0x64
  jal   sub_GAME_7F058020
   lw    $a1, 0xc($t0)
  lw    $t7, 0x60($sp)
  li    $at, 2
  bnel  $t7, $at, .Ljp7F021C84
   lhu   $t1, 0x12($s0)
  sw    $zero, 0x108($sp)
.Ljp7F021C80:
  lhu   $t1, 0x12($s0)
.Ljp7F021C84:
  lw    $t3, 0x100($sp)
  lw    $a1, 0xfc($sp)
  andi  $t2, $t1, 1
  beqz  $t2, .Ljp7F021CA8
   nop   
  lw    $t5, 0x64($t3)
  andi  $t4, $t5, 0x80
  bnezl $t4, .Ljp7F021CB8
   lw    $t8, 0x110($sp)
.Ljp7F021CA8:
  jal   sub_GAME_7F06B120
   lw    $a0, 0x20($s0)
  sw    $v0, 0x20($s0)
  lw    $t8, 0x110($sp)
.Ljp7F021CB8:
  lw    $t9, 8($t8)
  lw    $t6, 8($t9)
  lw    $a1, 0x10($t6)
  beqz  $a1, .Ljp7F021D00
   nop   
  jal   extract_id_from_object_structure_microcode
   move  $a0, $t8
  lw    $v1, ($v0)
  beqz  $v1, .Ljp7F021D00
   nop   
  lw    $t0, 8($v1)
  lw    $a1, 4($t0)
  beqz  $a1, .Ljp7F021D00
   nop   
  jal   extract_id_from_object_structure_microcode
   lw    $a0, 0x110($sp)
  lw    $t7, 0x108($sp)
  sw    $t7, ($v0)
.Ljp7F021D00:
  jal   sub_GAME_7F06B29C
   lw    $a0, 0x20($s0)
  jal   sub_GAME_7F06BB28
   lw    $a0, 0x20($s0)
  b     .Ljp7F021D94
   sw    $v0, 0x20($s0)
  lw    $v0, 0x160($s0)
.Ljp7F021D1C:
  beql  $v0, $zero, .Ljp7F021D34
   lw    $v0, 0x164($s0)
  lbu   $t1, 1($v0)
  andi  $t2, $t1, 0xfffd
  sb    $t2, 1($v0)
  lw    $v0, 0x164($s0)
.Ljp7F021D34:
  li    $v1, -3
  beql  $v0, $zero, .Ljp7F021D50
   lw    $v0, 0x1d8($s0)
  lbu   $t3, 1($v0)
  and   $t5, $t3, $v1
  sb    $t5, 1($v0)
  lw    $v0, 0x1d8($s0)
.Ljp7F021D50:
  beql  $v0, $zero, .Ljp7F021D68
   lw    $t6, 0x158($sp)
  lbu   $t4, 1($v0)
  and   $t9, $t4, $v1
  sb    $t9, 1($v0)
  lw    $t6, 0x158($sp)
.Ljp7F021D68:
  lbu   $t8, 1($t6)
  and   $t0, $t8, $v1
  sb    $t0, 1($t6)
  lbu   $t7, 0xf8($s0)
  lbu   $t1, 0xf9($s0)
  lbu   $t2, 0xfa($s0)
  lbu   $t3, 0xfb($s0)
  sb    $t7, 0xf4($s0)
  sb    $t1, 0xf5($s0)
  sb    $t2, 0xf6($s0)
  sb    $t3, 0xf7($s0)
.Ljp7F021D94:
  lw    $t5, 0x14($s0)
  andi  $t4, $t5, 0x400
  bnezl $t4, .Ljp7F021DF4
   move  $v0, $zero
  lhu   $v0, 0x12($s0)
  lw    $t8, 0x158($sp)
  andi  $t9, $v0, 1
  beqz  $t9, .Ljp7F021DE8
   nop   
  lw    $a0, 0x20($t8)
  beql  $a0, $zero, .Ljp7F021DE4
   andi  $t0, $v0, 0xfffe
  lw    $v1, 0x24($a0)
.Ljp7F021DC8:
  jal   sub_GAME_7F04C130
   sw    $v1, 0x3c($sp)
  lw    $a0, 0x3c($sp)
  bnezl $a0, .Ljp7F021DC8
   lw    $v1, 0x24($a0)
  lhu   $v0, 0x12($s0)
  andi  $t0, $v0, 0xfffe
.Ljp7F021DE4:
  sh    $t0, 0x12($s0)
.Ljp7F021DE8:
  jal   sub_GAME_7F02E26C
   move  $a0, $s0
  move  $v0, $zero
.Ljp7F021DF4:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0x158
  jr    $ra
   nop   
    
");
#endif

asm(R"
glabel sub_GAME_7F021B20
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  lw    $t6, 0x18($a0)
  move  $s1, $a0
  lw    $s0, 0x20($t6)
  beql  $s0, $zero, .L7F021B98
   lhu   $t2, 0x12($s1)
  lw    $t7, 0x1d8($s1)
.L7F021B48:
  beql  $s0, $t7, .L7F021B8C
   lw    $s0, 0x24($s0)
  lw    $t8, 0x164($s1)
  beql  $s0, $t8, .L7F021B8C
   lw    $s0, 0x24($s0)
  lw    $t9, 0x160($s1)
  beql  $s0, $t9, .L7F021B8C
   lw    $s0, 0x24($s0)
  lw    $v0, 4($s0)
  move  $a0, $s0
  lw    $t0, 8($v0)
  andi  $t1, $t0, 0x2000
  bnezl $t1, .L7F021B8C
   lw    $s0, 0x24($s0)
  jal   sub_GAME_7F04BFD0
   li    $a1, 1
  lw    $s0, 0x24($s0)
.L7F021B8C:
  bnezl $s0, .L7F021B48
   lw    $t7, 0x1d8($s1)
  lhu   $t2, 0x12($s1)
.L7F021B98:
  ori   $t3, $t2, 1
  sh    $t3, 0x12($s1)
  lw    $ra, 0x1c($sp)
  lw    $s1, 0x18($sp)
  lw    $s0, 0x14($sp)
  jr    $ra
   addiu $sp, $sp, 0x20
");

asm(R"
glabel sub_GAME_7F021BB4
  lbu   $t6, ($a0)
  lui   $v0, %hi(D_8002CCB8)
  addiu $v0, %lo(D_8002CCB8) # addiu $v0, $v0, -0x3348
  sb    $t6, ($v0)
  lbu   $t7, 1($a0)
  sb    $t7, 1($v0)
  lbu   $t8, 2($a0)
  jr    $ra
   sb    $t8, 2($v0)
");

asm(R"
glabel sub_GAME_7F021BD8
  lui   $v0, %hi(D_8002CCB8)
  addiu $v0, %lo(D_8002CCB8) # addiu $v0, $v0, -0x3348
  lbu   $t6, ($v0)
  sb    $t6, ($a0)
  lbu   $t7, 1($v0)
  sb    $t7, 1($a0)
  lbu   $t8, 2($v0)
  jr    $ra
   sb    $t8, 2($a0)
");

asm(R"
glabel sub_GAME_7F021BFC
  addiu $sp, $sp, -0xd8
  sw    $ra, 0x24($sp)
  sw    $s0, 0x20($sp)
  sw    $a0, 0xd8($sp)
  sw    $a1, 0xdc($sp)
  sw    $a2, 0xe0($sp)
  lw    $s0, 4($a0)
  lbu   $t7, 0xc($s0)
  lw    $a3, 0x1c($s0)
  sw    $t7, 0xb4($sp)
  lw    $t8, 0x14($s0)
  sll   $t9, $t8, 5
  bltzl $t9, .L7F021C70
   lw    $t5, 0xb4($sp)
  jal   getinstsize
   move  $a0, $a3
  mfc1  $a1, $f0
  jal   sub_GAME_7F054B80
   lw    $a0, 0xd8($sp)
  lw    $t2, 0xb4($sp)
  mtc1  $t2, $f4
  nop   
  cvt.s.w $f6, $f4
  mul.s $f8, $f6, $f0
  trunc.w.s $f10, $f8
  mfc1  $t4, $f10
  nop   
  sw    $t4, 0xb4($sp)
  lw    $t5, 0xb4($sp)
.L7F021C70:
  lw    $t8, 0xe0($sp)
  addiu $a1, $sp, 0xc0
  slti  $at, $t5, 0xff
  bnez  $at, .L7F021C98
   nop   
  lw    $t6, 0x14($s0)
  lw    $t2, 0xe0($sp)
  sll   $t7, $t6, 0xe
  bgez  $t7, .L7F021CB0
   nop   
.L7F021C98:
  bnez  $t8, .L7F021CA8
   li    $t9, 3
  b     .L7F022064
   lw    $v0, 0xdc($sp)
.L7F021CA8:
  b     .L7F021CC8
   sw    $t9, 0xb8($sp)
.L7F021CB0:
  bnez  $t2, .L7F021CC4
   li    $t4, 2
  li    $t3, 1
  b     .L7F021CC8
   sw    $t3, 0xb8($sp)
.L7F021CC4:
  sw    $t4, 0xb8($sp)
.L7F021CC8:
  jal   if_sky_present_convert_values
   lw    $a0, 0xd8($sp)
  beqz  $v0, .L7F022048
   sw    $v0, 0xbc($sp)
  lw    $t5, 0xb4($sp)
  lui   $t7, %hi(D_8002CCBC) 
  addiu $t7, %lo(D_8002CCBC) # addiu $t7, $t7, -0x3344
  blez  $t5, .L7F022048
   addiu $t6, $sp, 0x70
  addiu $t9, $t7, 0x3c
.L7F021CF0:
  lw    $at, ($t7)
  addiu $t7, $t7, 0xc
  addiu $t6, $t6, 0xc
  sw    $at, -0xc($t6)
  lw    $at, -8($t7)
  sw    $at, -8($t6)
  lw    $at, -4($t7)
  bne   $t7, $t9, .L7F021CF0
   sw    $at, -4($t6)
  lw    $at, ($t7)
  li    $t2, 80
  move  $a3, $zero
  sw    $at, ($t6)
  sw    $t2, 0x4c($sp)
  lw    $v0, 0x160($s0)
  lw    $v1, 0x164($s0)
  lw    $a2, 0x1d8($s0)
  move  $t0, $zero
  beqz  $v0, .L7F021D44
   move  $t1, $zero
  lw    $a3, 4($v0)
.L7F021D44:
  beqz  $v1, .L7F021D50
   lw    $a0, 0xd8($sp)
  lw    $t0, 4($v1)
.L7F021D50:
  beqz  $a2, .L7F021D5C
   addiu $a1, $sp, 0x60
  lw    $t1, 4($a2)
.L7F021D5C:
  sw    $v0, 0x48($sp)
  sw    $v1, 0x44($sp)
  sw    $a2, 0x40($sp)
  sw    $a3, 0x3c($sp)
  sw    $t0, 0x38($sp)
  jal   sub_GAME_7F054A64
   sw    $t1, 0x34($sp)
  blez  $v0, .L7F021DB0
   nop   
  lw    $t3, 0x14($s0)
  lw    $a0, 0xdc($sp)
  lw    $a1, 0x60($sp)
  sll   $t4, $t3, 8
  bltz  $t4, .L7F021DB0
   lw    $a2, 0x64($sp)
  lwc1  $f16, 0x6c($sp)
  lw    $a3, 0x68($sp)
  jal   sub_GAME_7F0B4FF4
   swc1  $f16, 0x10($sp)
  b     .L7F021DBC
   lw    $t5, 0xb8($sp)
.L7F021DB0:
  jal   sub_GAME_7F0B4FB4
   lw    $a0, 0xdc($sp)
  lw    $t5, 0xb8($sp)
.L7F021DBC:
  li    $t8, 1
  sw    $t8, 0x74($sp)
  sw    $v0, 0x7c($sp)
  sw    $t5, 0x78($sp)
  lw    $t9, 0x14($s0)
  lw    $t6, 0xbc($sp)
  li    $at, 1
  andi  $t7, $t9, 0x2000
  beqz  $t7, .L7F021DEC
   nop   
  b     .L7F021E20
   sw    $zero, 0x4c($sp)
.L7F021DEC:
  bne   $t6, $at, .L7F021E20
   lwc1  $f4, 0xcc($sp)
  li    $t2, 80
  mtc1  $t2, $f8
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f18
  cvt.s.w $f10, $f8
  sub.s $f6, $f18, $f4
  mul.s $f16, $f6, $f10
  trunc.w.s $f18, $f16
  mfc1  $t4, $f18
  nop   
  sw    $t4, 0x4c($sp)
.L7F021E20:
  jal   sub_GAME_7F073FC8
   lw    $a0, 0x4c($sp)
  lbu   $t5, 0xf4($s0)
  addiu $a0, $sp, 0x50
  lw    $a1, 0xbc($sp)
  sw    $t5, 0x50($sp)
  lbu   $t8, 0xf5($s0)
  addiu $a2, $sp, 0xc0
  sw    $t8, 0x54($sp)
  lbu   $t9, 0xf6($s0)
  sw    $t9, 0x58($sp)
  lbu   $t7, 0xf7($s0)
  jal   sub_GAME_7F040384
   sw    $t7, 0x5c($sp)
  lui   $v0, %hi(D_8002CCB8)
  addiu $v0, %lo(D_8002CCB8) # addiu $v0, $v0, -0x3348
  lbu   $t6, 2($v0)
  lbu   $t3, ($v0)
  lbu   $t8, 1($v0)
  sll   $t2, $t6, 8
  lw    $t6, 0x50($sp)
  sll   $t4, $t3, 0x18
  lw    $t7, 0x5c($sp)
  or    $t5, $t2, $t4
  sll   $t9, $t8, 0x10
  lw    $t4, 0x54($sp)
  or    $v1, $t5, $t9
  sll   $t3, $t6, 0x18
  lw    $t9, 0x58($sp)
  or    $t2, $t7, $t3
  lw    $t3, 0xb4($sp)
  sll   $t8, $t4, 0x10
  or    $t5, $t2, $t8
  sll   $t6, $t9, 8
  or    $t7, $t5, $t6
  slti  $at, $t3, 0xff
  beqz  $at, .L7F021ED0
   sw    $t7, 0xa8($sp)
  lbu   $t2, 0xb7($sp)
  li    $t4, 8
  sw    $t4, 0xa0($sp)
  or    $v1, $v1, $t2
  b     .L7F021EDC
   sw    $v1, 0xa4($sp)
.L7F021ED0:
  li    $t8, 7
  sw    $v1, 0xa4($sp)
  sw    $t8, 0xa0($sp)
.L7F021EDC:
  lui   $v0, %hi(pPlayersPerm)
  lw    $v0, %lo(pPlayersPerm)($v0)
  addiu $a0, $sp, 0x70
  lw    $t9, 0x34($v0)
  addiu $t5, $t9, 1
  sw    $t5, 0x34($v0)
  jal   drawjointlist
   lw    $a1, 0x20($s0)
  lw    $t7, 0x3c($sp)
  lw    $t6, 0x7c($sp)
  lw    $a2, 0xe0($sp)
  beqz  $t7, .L7F021F38
   sw    $t6, 0xdc($sp)
  lbu   $t3, 2($t7)
  li    $t4, 1
  sllv  $t2, $t4, $a2
  andi  $t8, $t2, 0xff
  and   $t9, $t3, $t8
  beqz  $t9, .L7F021F38
   move  $a0, $t6
  jal   sub_GAME_7F0A1A94
   lw    $a1, 0x48($sp)
  sw    $v0, 0xdc($sp)
.L7F021F38:
  lw    $t5, 0x38($sp)
  lw    $a2, 0xe0($sp)
  li    $t4, 1
  beql  $t5, $zero, .L7F021F78
   lw    $t9, 0x34($sp)
  lbu   $t7, 2($t5)
  sllv  $t2, $t4, $a2
  andi  $t3, $t2, 0xff
  and   $t8, $t7, $t3
  beqz  $t8, .L7F021F74
   lw    $a0, 0xdc($sp)
  jal   sub_GAME_7F0A1A94
   lw    $a1, 0x44($sp)
  sw    $v0, 0xdc($sp)
  lw    $a2, 0xe0($sp)
.L7F021F74:
  lw    $t9, 0x34($sp)
.L7F021F78:
  li    $t5, 1
  beqz  $t9, .L7F021FAC
   nop   
  lbu   $t6, 2($t9)
  sllv  $t4, $t5, $a2
  andi  $t2, $t4, 0xff
  and   $t7, $t6, $t2
  beqz  $t7, .L7F021FAC
   lw    $a0, 0xdc($sp)
  jal   sub_GAME_7F0A1A94
   lw    $a1, 0x40($sp)
  sw    $v0, 0xdc($sp)
  lw    $a2, 0xe0($sp)
.L7F021FAC:
  beql  $a2, $zero, .L7F02204C
   lw    $a2, 0xe0($sp)
  lw    $v0, 0x1c($s0)
  lw    $t3, 8($v0)
  lw    $a0, 0xc($v0)
  jal   sub_GAME_7F08BD48
   lh    $a1, 0xe($t3)
  lw    $t8, 0x3c($sp)
  beql  $t8, $zero, .L7F021FFC
   lw    $t6, 0x38($sp)
  lw    $t9, 0x64($t8)
  andi  $t5, $t9, 0x800
  bnezl $t5, .L7F021FFC
   lw    $t6, 0x38($sp)
  lw    $v0, 0x14($t8)
  lw    $t4, 8($v0)
  lw    $a0, 0xc($v0)
  jal   sub_GAME_7F08BD48
   lh    $a1, 0xe($t4)
  lw    $t6, 0x38($sp)
.L7F021FFC:
  beql  $t6, $zero, .L7F02202C
   lw    $t9, 0x34($sp)
  lw    $t2, 0x64($t6)
  andi  $t7, $t2, 0x800
  bnezl $t7, .L7F02202C
   lw    $t9, 0x34($sp)
  lw    $v0, 0x14($t6)
  lw    $t3, 8($v0)
  lw    $a0, 0xc($v0)
  jal   sub_GAME_7F08BD48
   lh    $a1, 0xe($t3)
  lw    $t9, 0x34($sp)
.L7F02202C:
  beql  $t9, $zero, .L7F02204C
   lw    $a2, 0xe0($sp)
  lw    $v0, 0x14($t9)
  lw    $t5, 8($v0)
  lw    $a0, 0xc($v0)
  jal   sub_GAME_7F08BD48
   lh    $a1, 0xe($t5)
.L7F022048:
  lw    $a2, 0xe0($sp)
.L7F02204C:
  beql  $a2, $zero, .L7F022064
   lw    $v0, 0xdc($sp)
  jal   sub_GAME_7F06B248
   lw    $a0, 0x20($s0)
  sw    $zero, 0x20($s0)
  lw    $v0, 0xdc($sp)
.L7F022064:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0xd8
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F022078
  lui   $t3, %hi(D_8002C914) 
  addiu $t3, %lo(D_8002C914) # addiu $t3, $t3, -0x36ec
  lw    $t6, ($t3)
  addiu $sp, $sp, -0x50
  li    $t1, -1
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a0, 0x50($sp)
  sw    $a3, 0x5c($sp)
  move  $t2, $zero
  beq   $t1, $t6, .L7F0220D8
   move  $t0, $zero
  lui   $t7, %hi(D_8002C914)
  addiu $v0, $t7, %lo(D_8002C914)
  lw    $v1, ($v0)
.L7F0220B4:
  bnel  $a1, $v1, .L7F0220C8
   lw    $v1, 0x2c($v0)
  b     .L7F0220D8
   move  $t2, $t0
  lw    $v1, 0x2c($v0)
.L7F0220C8:
  addiu $t0, $t0, 1
  addiu $v0, $v0, 0x2c
  bne   $t1, $v1, .L7F0220B4
   nop   
.L7F0220D8:
  sll   $t8, $t2, 2
  subu  $t8, $t8, $t2
  sll   $t8, $t8, 2
  subu  $t8, $t8, $t2
  sll   $t8, $t8, 2
  addu  $s0, $t3, $t8
  lw    $t9, 0x10($s0)
  beql  $t9, $zero, .L7F0221A8
   lw    $a1, 4($s0)
  jal   get_random_value
   sw    $a2, 0x58($sp)
  andi  $t4, $v0, 4
  bnez  $t4, .L7F0221A4
   lw    $a2, 0x58($sp)
  lwc1  $f2, ($a2)
  lwc1  $f14, 4($a2)
  lwc1  $f0, 8($a2)
  mul.s $f4, $f2, $f2
  sw    $a2, 0x58($sp)
  mul.s $f6, $f14, $f14
  add.s $f8, $f4, $f6
  mul.s $f10, $f0, $f0
  jal   sqrtf
   add.s $f12, $f10, $f8
  li    $at, 0x42280000 # 42.000000
  mtc1  $at, $f16
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  div.s $f18, $f16, $f0
  lw    $a2, 0x58($sp)
  lwc1  $f6, ($a2)
  add.s $f2, $f18, $f4
  mul.s $f10, $f6, $f2
  swc1  $f10, 0x3c($sp)
  lwc1  $f8, 4($a2)
  mul.s $f16, $f8, $f2
  swc1  $f16, 0x40($sp)
  lwc1  $f18, 8($a2)
  mul.s $f4, $f18, $f2
  jal   sub_GAME_7F078444
   swc1  $f4, 0x44($sp)
  move  $a0, $v0
  jal   sub_GAME_7F058474
   addiu $a1, $sp, 0x3c
  lw    $t5, 0x50($sp)
  addiu $a0, $sp, 0x3c
  lw    $a1, 0x10($s0)
  lw    $t6, 0x14($t5)
  lw    $a2, 0x18($s0)
  jal   sub_GAME_7F0A3E1C
   lbu   $a3, 3($t6)
.L7F0221A4:
  lw    $a1, 4($s0)
.L7F0221A8:
  lw    $t7, 0x50($sp)
  beql  $a1, $zero, .L7F0221CC
   lw    $ra, 0x1c($sp)
  lw    $t8, 0x14($t7)
  lw    $a0, 0x5c($sp)
  lw    $a2, 0xc($s0)
  jal   sub_GAME_7F0A3E1C
   lbu   $a3, 3($t8)
  lw    $ra, 0x1c($sp)
.L7F0221CC:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x50
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0221DC
  addiu $sp, $sp, -0xb0
  sw    $ra, 0x34($sp)
  sw    $s6, 0x30($sp)
  sw    $s5, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a1, 0xb4($sp)
  lwc1  $f4, ($a3)
  lui   $s1, (0x7FFFFFFF >> 16) # lui $s1, 0x7fff
  move  $s2, $a2
  trunc.w.s $f6, $f4
  move  $s6, $a0
  move  $s4, $zero
  move  $s5, $zero
  mfc1  $t7, $f6
  ori   $s1, (0x7FFFFFFF & 0xFFFF) # ori $s1, $s1, 0xffff
  move  $s0, $a2
  sw    $t7, 0xa4($sp)
  lwc1  $f8, 4($a3)
  trunc.w.s $f10, $f8
  mfc1  $t9, $f10
  nop   
  sw    $t9, 0xa8($sp)
  lwc1  $f16, 8($a3)
  trunc.w.s $f18, $f16
  mfc1  $t3, $f18
  beqz  $a2, .L7F0223C0
   sw    $t3, 0xac($sp)
  lhu   $s3, ($s0)
.L7F02225C:
  li    $at, 8
  move  $a0, $s6
  andi  $t4, $s3, 0xff
  beq   $t4, $at, .L7F02232C
   move  $s3, $t4
  li    $at, 18
  beq   $t4, $at, .L7F02233C
   move  $a0, $s6
  li    $at, 23
  beq   $t4, $at, .L7F02234C
   move  $a0, $s6
  li    $at, 24
  bne   $t4, $at, .L7F022358
   lw    $t1, 0x14($s0)
  lw    $v0, 4($s0)
  move  $a2, $zero
  lh    $t0, 0xe($v0)
  blez  $t0, .L7F022358
   nop   
  lw    $a1, 0x10($v0)
.L7F0222AC:
  lw    $t5, 0xa4($sp)
  lh    $t6, ($a1)
  lw    $t7, 0xa8($sp)
  lh    $t8, 2($a1)
  subu  $v0, $t5, $t6
  multu $v0, $v0
  subu  $v1, $t7, $t8
  lw    $t9, 0xac($sp)
  lh    $t2, 4($a1)
  subu  $a0, $t9, $t2
  mflo  $t3
  nop   
  nop   
  multu $v1, $v1
  mflo  $t4
  addu  $t5, $t3, $t4
  nop   
  multu $a0, $a0
  mflo  $t6
  addu  $a3, $t5, $t6
  slt   $at, $a3, $s1
  beql  $at, $zero, .L7F022318
   addiu $a2, $a2, 1
  move  $s1, $a3
  move  $s4, $s0
  move  $s5, $a2
  addiu $a2, $a2, 1
.L7F022318:
  slt   $at, $a2, $t0
  bnez  $at, .L7F0222AC
   addiu $a1, $a1, 0x10
  b     .L7F022358
   nop   
.L7F02232C:
  jal   sub_GAME_7F06E970
   move  $a1, $s0
  b     .L7F022358
   lw    $t1, 0x14($s0)
.L7F02233C:
  jal   process_12_handle_switch
   move  $a1, $s0
  b     .L7F022358
   lw    $t1, 0x14($s0)
.L7F02234C:
  jal   process_17_pointer_to_head
   move  $a1, $s0
  lw    $t1, 0x14($s0)
.L7F022358:
  beqz  $t1, .L7F022380
   nop   
  beq   $s0, $s2, .L7F022378
   li    $at, 10
  beq   $s3, $at, .L7F022380
   li    $at, 17
  beq   $s3, $at, .L7F022380
   nop   
.L7F022378:
  b     .L7F0223B8
   move  $s0, $t1
.L7F022380:
  beqz  $s0, .L7F0223B8
   nop   
.L7F022388:
  bnel  $s0, $s2, .L7F02239C
   lw    $v0, 0xc($s0)
  b     .L7F0223B8
   move  $s0, $zero
  lw    $v0, 0xc($s0)
.L7F02239C:
  beql  $v0, $zero, .L7F0223B0
   lw    $s0, 8($s0)
  b     .L7F0223B8
   move  $s0, $v0
  lw    $s0, 8($s0)
.L7F0223B0:
  bnez  $s0, .L7F022388
   nop   
.L7F0223B8:
  bnezl $s0, .L7F02225C
   lhu   $s3, ($s0)
.L7F0223C0:
  beqz  $s4, .L7F022620
   move  $a0, $s6
  lw    $s0, 4($s4)
  jal   extract_id_from_object_structure_microcode
   move  $a1, $s4
  move  $s4, $v0
  move  $s1, $zero
  move  $s3, $zero
  jal   get_random_value
   sw    $zero, 0x60($sp)
  li    $at, 50
  divu  $zero, $v0, $at
  lw    $t7, 0xb4($sp)
  mfhi  $v1
  addiu $v1, $v1, 0x14
  li    $at, 8
  bne   $t7, $at, .L7F02240C
   move  $s2, $v1
  addiu $s2, $v1, 0x64
.L7F02240C:
  lw    $t8, 0xb4($sp)
  li    $at, 15
  move  $a0, $s6
  bnel  $t8, $at, .L7F022428
   lw    $t9, 0x10($s0)
  addiu $s2, $s2, 0x32
  lw    $t9, 0x10($s0)
.L7F022428:
  sll   $t0, $s5, 4
  addu  $t2, $t9, $t0
  lw    $v0, 8($t2)
  beqz  $v0, .L7F022460
   move  $a1, $v0
  lw    $s1, 4($v0)
  jal   extract_id_from_object_structure_microcode
   sw    $t0, 0x3c($sp)
  lw    $t0, 0x3c($sp)
  lw    $t3, 0x10($s0)
  move  $s3, $v0
  addu  $t4, $t3, $t0
  lh    $t5, 0xc($t4)
  sw    $t5, 0x60($sp)
.L7F022460:
  lw    $t6, 8($s0)
  lw    $t7, ($s4)
  li    $a1, 52428
  move  $a2, $zero
  bne   $t6, $t7, .L7F0224E8
   move  $a3, $zero
  lh    $a0, 0xc($s0)
  jal   sub_GAME_7F09BE4C
   sw    $t0, 0x3c($sp)
  beqz  $v0, .L7F0224E8
   lw    $t0, 0x3c($sp)
  sw    $v0, ($s4)
  lh    $t8, 0xc($s0)
  move  $v1, $zero
  move  $a0, $zero
  blez  $t8, .L7F0224E8
   move  $a1, $v0
  lw    $t9, 8($s0)
.L7F0224A8:
  addiu $v1, $v1, 1
  addiu $a1, $a1, 0x10
  addu  $t2, $t9, $a0
  lw    $at, ($t2)
  addiu $a0, $a0, 0x10
  sw    $at, -0x10($a1)
  lw    $t4, 4($t2)
  sw    $t4, -0xc($a1)
  lw    $at, 8($t2)
  sw    $at, -8($a1)
  lw    $t4, 0xc($t2)
  sw    $t4, -4($a1)
  lh    $t5, 0xc($s0)
  slt   $at, $v1, $t5
  bnezl $at, .L7F0224A8
   lw    $t9, 8($s0)
.L7F0224E8:
  beql  $s3, $zero, .L7F02257C
   lw    $t6, 8($s0)
  lw    $t6, 8($s1)
  lw    $t7, ($s3)
  li    $a1, 52428
  move  $a2, $zero
  bne   $t6, $t7, .L7F022578
   move  $a3, $zero
  lh    $a0, 0xc($s1)
  jal   sub_GAME_7F09BE4C
   sw    $t0, 0x3c($sp)
  beqz  $v0, .L7F022578
   lw    $t0, 0x3c($sp)
  sw    $v0, ($s3)
  lh    $t8, 0xc($s1)
  move  $v1, $zero
  move  $a0, $zero
  blez  $t8, .L7F022578
   move  $a1, $v0
  lw    $t9, 8($s1)
.L7F022538:
  addiu $v1, $v1, 1
  addiu $a1, $a1, 0x10
  addu  $t3, $t9, $a0
  lw    $at, ($t3)
  addiu $a0, $a0, 0x10
  sw    $at, -0x10($a1)
  lw    $t4, 4($t3)
  sw    $t4, -0xc($a1)
  lw    $at, 8($t3)
  sw    $at, -8($a1)
  lw    $t4, 0xc($t3)
  sw    $t4, -4($a1)
  lh    $t5, 0xc($s1)
  slt   $at, $v1, $t5
  bnezl $at, .L7F022538
   lw    $t9, 8($s1)
.L7F022578:
  lw    $t6, 8($s0)
.L7F02257C:
  lw    $t7, ($s4)
  beq   $t6, $t7, .L7F0225C4
   nop   
  lw    $t8, 0x10($s0)
  addu  $t9, $t8, $t0
  lh    $v0, 6($t9)
  bltz  $v0, .L7F0225C4
   nop   
  lw    $t2, ($s4)
.L7F0225A0:
  sll   $t3, $v0, 4
  sll   $t6, $v0, 1
  addu  $t4, $t2, $t3
  sb    $s2, 0xf($t4)
  lw    $t5, 0x14($s0)
  addu  $t7, $t5, $t6
  lh    $v0, ($t7)
  bgezl $v0, .L7F0225A0
   lw    $t2, ($s4)
.L7F0225C4:
  beql  $s3, $zero, .L7F022624
   lw    $ra, 0x34($sp)
  lw    $t8, 8($s1)
  lw    $t9, ($s3)
  lw    $t3, 0x60($sp)
  beql  $t8, $t9, .L7F022624
   lw    $ra, 0x34($sp)
  lw    $t2, 0x10($s1)
  sll   $t4, $t3, 4
  addu  $t5, $t2, $t4
  lh    $v0, 6($t5)
  bltzl $v0, .L7F022624
   lw    $ra, 0x34($sp)
  lw    $t6, ($s3)
.L7F0225FC:
  sll   $t7, $v0, 4
  sll   $t3, $v0, 1
  addu  $t8, $t6, $t7
  sb    $s2, 0xf($t8)
  lw    $t9, 0x14($s1)
  addu  $t2, $t9, $t3
  lh    $v0, ($t2)
  bgezl $v0, .L7F0225FC
   lw    $t6, ($s3)
.L7F022620:
  lw    $ra, 0x34($sp)
.L7F022624:
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  lw    $s3, 0x24($sp)
  lw    $s4, 0x28($sp)
  lw    $s5, 0x2c($sp)
  lw    $s6, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0xb0
");

asm(R"
glabel sub_GAME_7F022648
  addiu $sp, $sp, -0xf0
  sw    $ra, 0x44($sp)
  sw    $s2, 0x40($sp)
  sw    $s1, 0x3c($sp)
  sw    $s0, 0x38($sp)
  sw    $a0, 0xf0($sp)
  lw    $v0, 4($a0)
  li    $at, 5
  move  $s2, $a1
  lb    $t7, 7($v0)
  beql  $t7, $at, .L7F02296C
   lw    $ra, 0x44($sp)
  lw    $s0, 0x1c($v0)
  sw    $v0, 0xec($sp)
  jal   getinstsize
   move  $a0, $s0
  lw    $v0, 0xf0($sp)
  swc1  $f0, 0xe4($sp)
  lbu   $t8, 1($v0)
  andi  $t9, $t8, 2
  beql  $t9, $zero, .L7F02296C
   lw    $ra, 0x44($sp)
  lwc1  $f4, 0x18($v0)
  lwc1  $f8, 0x34($s2)
  move  $s1, $zero
  sub.s $f6, $f4, $f0
  move  $a0, $s0
  c.lt.s $f6, $f8
  nop   
  bc1fl .L7F02296C
   lw    $ra, 0x44($sp)
  sw    $zero, 0xdc($sp)
  sw    $zero, 0xd8($sp)
  sw    $zero, 0xd4($sp)
  jal   getsubmatrix
   sw    $zero, 0x9c($sp)
  mtc1  $zero, $f12
  sw    $v0, 0x98($sp)
  move  $a1, $zero
  lw    $a2, 0xec($sp)
.L7F0226E8:
  lw    $v1, 0x160($a2)
  beql  $v1, $zero, .L7F022738
   addiu $a1, $a1, 4
  lw    $v0, 4($v1)
  lw    $a0, 0x14($v0)
  swc1  $f12, 0x94($sp)
  sw    $a2, 0x50($sp)
  jal   getinstsize
   sw    $a1, 0x54($sp)
  lwc1  $f10, 0x14($s0)
  lwc1  $f12, 0x94($sp)
  lw    $a1, 0x54($sp)
  mul.s $f2, $f0, $f10
  lw    $a2, 0x50($sp)
  c.lt.s $f12, $f2
  nop   
  bc1fl .L7F022738
   addiu $a1, $a1, 4
  mov.s $f12, $f2
  addiu $a1, $a1, 4
.L7F022738:
  li    $at, 8
  bne   $a1, $at, .L7F0226E8
   addiu $a2, $a2, 4
  lwc1  $f0, 0xe4($sp)
  lw    $a2, 0x98($sp)
  addiu $s0, $s2, 0xc
  add.s $f0, $f0, $f12
  move  $a1, $s0
  move  $a0, $s2
  addiu $a2, $a2, 0x30
  mfc1  $a3, $f0
  jal   sub_GAME_7F041074
   nop   
  beqz  $v0, .L7F02277C
   li    $t0, 1
  sw    $t0, 0xd4($sp)
  li    $s1, 1
.L7F02277C:
  beqz  $s1, .L7F022820
   lw    $t1, 0xec($sp)
  lw    $t2, 0x20($t1)
  addiu $t3, $sp, 0xd8
  sw    $t3, 0x10($sp)
  addiu $a0, $sp, 0x80
  move  $a1, $s2
  move  $a2, $s0
  addiu $a3, $sp, 0xdc
  jal   sub_GAME_7F06C010
   sw    $t2, 0x80($sp)
  li    $at, 100
  beq   $v0, $at, .L7F0227BC
   move  $s1, $v0
  li    $at, 110
  bne   $v0, $at, .L7F022820
.L7F0227BC:
   addiu $t4, $sp, 0xa4
.L7F0227C0:
  addiu $t5, $sp, 0xa0
  addiu $t6, $sp, 0x9c
  sw    $t6, 0x18($sp)
  sw    $t5, 0x14($sp)
  sw    $t4, 0x10($sp)
  lw    $a0, 0xdc($sp)
  lw    $a1, 0xd8($sp)
  move  $a2, $s2
  jal   sub_GAME_7F04D9B0
   move  $a3, $s0
  bnez  $v0, .L7F022820
   addiu $a0, $sp, 0x80
  addiu $t7, $sp, 0xd8
  sw    $t7, 0x10($sp)
  move  $a1, $s2
  move  $a2, $s0
  jal   probably_damage_detail_blood_effect_related
   addiu $a3, $sp, 0xdc
  li    $at, 100
  beq   $v0, $at, .L7F0227BC
   move  $s1, $v0
  li    $at, 110
  beql  $v0, $at, .L7F0227C0
   addiu $t4, $sp, 0xa4
.L7F022820:
  blezl $s1, .L7F022928
   lw    $t4, 0xd4($sp)
  lwc1  $f16, 0xc($s2)
  swc1  $f16, 0x74($sp)
  lwc1  $f18, 0x10($s2)
  swc1  $f18, 0x78($sp)
  lwc1  $f4, 0x14($s2)
  jal   sub_GAME_7F078444
   swc1  $f4, 0x7c($sp)
  move  $a0, $v0
  jal   sub_GAME_7F0583D8
   addiu $a1, $sp, 0x74
  lw    $a0, 0xdc($sp)
  lw    $a1, 0xd8($sp)
  jal   sub_GAME_7F06C660
   move  $a2, $zero
  lwc1  $f6, 0x30($v0)
  lwc1  $f8, ($s2)
  sub.s $f10, $f6, $f8
  swc1  $f10, 0x60($sp)
  lwc1  $f18, 4($s2)
  lwc1  $f16, 0x34($v0)
  sub.s $f4, $f16, $f18
  lwc1  $f16, 0x60($sp)
  swc1  $f4, 0x64($sp)
  lwc1  $f8, 8($s2)
  lwc1  $f6, 0x38($v0)
  mul.s $f18, $f16, $f16
  lwc1  $f4, 0x64($sp)
  sub.s $f10, $f6, $f8
  mul.s $f6, $f4, $f4
  swc1  $f10, 0x68($sp)
  lwc1  $f10, 0x68($sp)
  mul.s $f16, $f10, $f10
  add.s $f8, $f18, $f6
  jal   sqrtf
   add.s $f12, $f16, $f8
  lwc1  $f4, 0x14($s2)
  lwc1  $f6, 8($s2)
  lwc1  $f10, 0x34($s2)
  mul.s $f18, $f4, $f0
  move  $a0, $s2
  lw    $a1, 0xf0($sp)
  move  $a3, $s1
  lw    $t8, 0xd8($sp)
  addiu $t9, $sp, 0xa4
  li    $t3, 1
  add.s $f2, $f18, $f6
  neg.s $f2, $f2
  c.lt.s $f2, $f10
  nop   
  bc1fl .L7F022928
   lw    $t4, 0xd4($sp)
  lw    $t0, 0xa0($sp)
  lw    $t1, 0x9c($sp)
  lw    $t2, 0xdc($sp)
  mfc1  $a2, $f2
  sw    $t8, 0x10($sp)
  sw    $t9, 0x14($sp)
  sw    $t3, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t0, 0x18($sp)
  sw    $t1, 0x1c($sp)
  jal   sub_GAME_7F03B9C0
   sw    $t2, 0x20($sp)
  lw    $t4, 0xd4($sp)
.L7F022928:
  lw    $t5, 0xf0($sp)
  beql  $t4, $zero, .L7F02296C
   lw    $ra, 0x44($sp)
  lwc1  $f16, 0x34($s2)
  lwc1  $f8, 0x18($t5)
  lw    $t6, 0xec($sp)
  c.le.s $f8, $f16
  nop   
  bc1fl .L7F02296C
   lw    $ra, 0x44($sp)
  lw    $t7, 0x14($t6)
  lb    $t9, 0xa($t6)
  ori   $t8, $t7, 4
  addiu $t0, $t9, 1
  sw    $t8, 0x14($t6)
  sb    $t0, 0xa($t6)
  lw    $ra, 0x44($sp)
.L7F02296C:
  lw    $s0, 0x38($sp)
  lw    $s1, 0x3c($sp)
  lw    $s2, 0x40($sp)
  jr    $ra
   addiu $sp, $sp, 0xf0
");

asm(R"
glabel sub_GAME_7F022980
  addiu $sp, $sp, -0xf8
  sw    $ra, 0x4c($sp)
  sw    $s6, 0x48($sp)
  sw    $s5, 0x44($sp)
  sw    $s4, 0x40($sp)
  sw    $s3, 0x3c($sp)
  sw    $s2, 0x38($sp)
  sw    $s1, 0x34($sp)
  sw    $s0, 0x30($sp)
  sdc1  $f20, 0x28($sp)
  lwc1  $f4, ($a1)
  lwc1  $f6, 0xc($a0)
  lwc1  $f10, 0x14($a0)
  lwc1  $f18, ($a0)
  mul.s $f8, $f4, $f6
  lw    $t6, 4($a1)
  move  $s1, $a1
  move  $s4, $a0
  lw    $s6, 4($t6)
  div.s $f16, $f8, $f10
  sub.s $f4, $f18, $f16
  swc1  $f4, 0x98($sp)
  lwc1  $f6, ($a1)
  lwc1  $f8, 0x10($a0)
  lwc1  $f18, 0x14($a0)
  lwc1  $f4, 4($a0)
  mul.s $f10, $f6, $f8
  div.s $f16, $f10, $f18
  sub.s $f6, $f4, $f16
  lwc1  $f4, 0x98($sp)
  swc1  $f6, 0x9c($sp)
  lwc1  $f10, ($a1)
  lwc1  $f8, 8($a0)
  mul.s $f16, $f4, $f4
  lwc1  $f6, 0x9c($sp)
  sub.s $f18, $f8, $f10
  mul.s $f8, $f6, $f6
  swc1  $f18, 0xa0($sp)
  lwc1  $f18, 0xa0($sp)
  mul.s $f4, $f18, $f18
  add.s $f10, $f16, $f8
  jal   sqrtf
   add.s $f12, $f4, $f10
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  li    $at, 0x42280000 # 42.000000
  mtc1  $at, $f16
  lwc1  $f18, 0x98($sp)
  lwc1  $f10, 0x9c($sp)
  div.s $f8, $f16, $f0
  sub.s $f2, $f6, $f8
  lwc1  $f6, 0xa0($sp)
  mul.s $f4, $f18, $f2
  nop   
  mul.s $f16, $f10, $f2
  nop   
  mul.s $f8, $f6, $f2
  swc1  $f4, 0xa8($sp)
  swc1  $f16, 0xac($sp)
  jal   sub_GAME_7F078444
   swc1  $f8, 0xb0($sp)
  addiu $s0, $sp, 0xa8
  move  $a1, $s0
  jal   sub_GAME_7F058474
   move  $a0, $v0
  jal   sub_GAME_7F067B4C
   move  $a0, $s0
  lw    $a0, 0x18($s4)
  lw    $a1, 4($s1)
  jal   recall_joy2_hits_edit_detail_edit_flag
   li    $a2, -1
  lw    $a0, 4($s1)
  lw    $a1, 8($s1)
  addiu $a2, $sp, 0x98
  jal   sub_GAME_7F022078
   move  $a3, $s0
  lw    $a1, 8($s1)
  lw    $a3, 0x18($s4)
  li    $t7, 1
  sw    $t7, 0x10($sp)
  move  $a0, $s6
  jal   handles_shot_actors
   addiu $a2, $s4, 0x28
  beql  $v0, $zero, .L7F022DF4
   lw    $ra, 0x4c($sp)
  lw    $v0, 8($s1)
  li    $at, 100
  lui   $s5, %hi(D_8004E86C)
  bne   $v0, $at, .L7F022C40
   addiu $s5, %lo(D_8004E86C) # addiu $s5, $s5, -0x1794
  move  $s2, $zero
  move  $s3, $s6
.L7F022AF0:
  lw    $s0, 0x160($s3)
  beql  $s0, $zero, .L7F022C2C
   addiu $s2, $s2, 4
  lw    $v1, 4($s0)
  lw    $t8, 0x48($s1)
  lw    $t9, 0x14($v1)
  bnel  $t8, $t9, .L7F022C2C
   addiu $s2, $s2, 4
  lb    $v0, 0x80($v1)
  li    $at, 26
  move  $a0, $s0
  beq   $v0, $at, .L7F022B54
   li    $at, 87
  beq   $v0, $at, .L7F022B54
   li    $at, 86
  beq   $v0, $at, .L7F022B54
   li    $at, 27
  beq   $v0, $at, .L7F022B54
   li    $at, 33
  beq   $v0, $at, .L7F022B54
   li    $at, 29
  beq   $v0, $at, .L7F022B54
   li    $at, 28
  bnel  $v0, $at, .L7F022B9C
   lh    $v0, 0x3a($s1)
.L7F022B54:
  jal   sub_GAME_7F04BFD0
   li    $a1, 1
  lhu   $t1, 0x12($s6)
  ori   $t2, $t1, 1
  sh    $t2, 0x12($s6)
  jal   sub_GAME_7F05DF84
   lw    $a0, 0x18($s4)
  jal   get_cur_playernum
   mov.s $f20, $f0
  lw    $a0, 4($s0)
  mfc1  $a1, $f20
  lw    $a3, 0x18($s4)
  sw    $v0, 0x10($sp)
  jal   maybe_detonate_object
   addiu $a2, $sp, 0x98
  b     .L7F022C2C
   addiu $s2, $s2, 4
  lh    $v0, 0x3a($s1)
.L7F022B9C:
  addiu $a0, $s1, 0x10
  addiu $a1, $s1, 0x1c
  bgez  $v0, .L7F022BB4
   sll   $t3, $v0, 3
  b     .L7F022BD0
   lw    $v1, ($s5)
.L7F022BB4:
  lui   $t4, %hi(image_entries)
  addu  $t4, $t4, $t3
  lbu   $t4, %lo(image_entries)($t4)
  andi  $t5, $t4, 0xf
  sll   $t6, $t5, 2
  addu  $t7, $s5, $t6
  lw    $v1, ($t7)
.L7F022BD0:
  sw    $v1, 0x88($sp)
  sw    $a0, 0x54($sp)
  jal   get_random_value
   sw    $a1, 0x50($sp)
  lw    $v1, 0x88($sp)
  lw    $a0, 0x54($sp)
  lw    $a1, 0x50($sp)
  lh    $t8, 0xa($v1)
  lw    $t9, 4($v1)
  li    $a3, 1
  divu  $zero, $v0, $t8
  mfhi  $t0
  addu  $t1, $t9, $t0
  lbu   $a2, ($t1)
  sw    $s0, 0x10($sp)
  lw    $t2, 0x40($s1)
  bnez  $t8, .L7F022C1C
   nop   
  break 7
.L7F022C1C:
  sw    $zero, 0x18($sp)
  jal   sub_GAME_7F0A108C
   sw    $t2, 0x14($sp)
  addiu $s2, $s2, 4
.L7F022C2C:
  li    $at, 8
  bne   $s2, $at, .L7F022AF0
   addiu $s3, $s3, 4
  b     .L7F022DF4
   lw    $ra, 0x4c($sp)
.L7F022C40:
  li    $at, 110
  bne   $v0, $at, .L7F022CE4
   move  $a2, $zero
  lh    $v0, 0x3a($s1)
  lui   $s5, %hi(D_8004E86C)
  lui   $t4, %hi(image_entries)
  bgez  $v0, .L7F022C6C
   sll   $t3, $v0, 3
  addiu $s5, %lo(D_8004E86C) # addiu $s5, $s5, -0x1794
  b     .L7F022C8C
   lw    $s0, ($s5)
.L7F022C6C:
  addu  $t4, $t4, $t3
  lbu   $t4, %lo(image_entries)($t4)
  lui   $s5, %hi(D_8004E86C)
  addiu $s5, %lo(D_8004E86C) # addiu $s5, $s5, -0x1794
  andi  $t5, $t4, 0xf
  sll   $t6, $t5, 2
  addu  $t7, $s5, $t6
  lw    $s0, ($t7)
.L7F022C8C:
  jal   get_random_value
   nop   
  lh    $t8, 0xa($s0)
  lw    $t9, 4($s0)
  lw    $t2, 0x1d8($s6)
  divu  $zero, $v0, $t8
  mfhi  $v1
  addu  $t1, $t9, $v1
  lbu   $a2, ($t1)
  sw    $t2, 0x10($sp)
  lw    $t3, 0x40($s1)
  bnez  $t8, .L7F022CC4
   nop   
  break 7
.L7F022CC4:
  sw    $zero, 0x18($sp)
  addiu $a0, $s1, 0x10
  addiu $a1, $s1, 0x1c
  li    $a3, 1
  jal   sub_GAME_7F0A108C
   sw    $t3, 0x14($sp)
  b     .L7F022DF4
   lw    $ra, 0x4c($sp)
.L7F022CE4:
  lw    $a0, 0x48($s1)
  jal   sub_GAME_7F06C660
   lw    $a1, 0xc($s1)
  lwc1  $f18, 0x98($sp)
  lwc1  $f4, 0x9c($sp)
  lwc1  $f10, 0xa0($sp)
  swc1  $f18, 0x70($sp)
  swc1  $f4, 0x74($sp)
  swc1  $f10, 0x78($sp)
  lwc1  $f16, 0x30($v0)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f20
  sub.s $f6, $f18, $f16
  move  $s0, $v0
  mul.s $f8, $f6, $f20
  add.s $f16, $f18, $f8
  swc1  $f16, 0x70($sp)
  lwc1  $f6, 0x34($v0)
  sub.s $f18, $f4, $f6
  mul.s $f8, $f18, $f20
  add.s $f16, $f4, $f8
  swc1  $f16, 0x74($sp)
  lwc1  $f6, 0x38($v0)
  sub.s $f18, $f10, $f6
  mul.s $f4, $f18, $f20
  add.s $f8, $f10, $f4
  swc1  $f8, 0x78($sp)
  lw    $a1, 0xc($s1)
  jal   getjointsize
   lw    $a0, 0x48($s1)
  mul.s $f16, $f0, $f20
  lwc1  $f6, 0xc($s4)
  lwc1  $f10, 0x70($sp)
  mul.s $f18, $f16, $f6
  sub.s $f4, $f10, $f18
  swc1  $f4, 0x70($sp)
  lw    $a1, 0xc($s1)
  jal   getjointsize
   lw    $a0, 0x48($s1)
  mul.s $f8, $f0, $f20
  lwc1  $f16, 0x10($s4)
  lwc1  $f10, 0x74($sp)
  mul.s $f6, $f8, $f16
  sub.s $f18, $f10, $f6
  swc1  $f18, 0x74($sp)
  lw    $a1, 0xc($s1)
  jal   getjointsize
   lw    $a0, 0x48($s1)
  mul.s $f4, $f0, $f20
  lwc1  $f8, 0x14($s4)
  lwc1  $f10, 0x78($sp)
  addiu $s2, $sp, 0xb4
  move  $a1, $s2
  move  $a0, $s0
  mul.s $f16, $f4, $f8
  sub.s $f6, $f10, $f16
  jal   sub_GAME_7F059E64
   swc1  $f6, 0x78($sp)
  addiu $s0, $sp, 0x70
  move  $a1, $s0
  jal   sub_GAME_7F058474
   move  $a0, $s2
  lw    $a0, 0x48($s1)
  lw    $a1, 8($s1)
  lw    $a2, 0xc($s1)
  jal   sub_GAME_7F0221DC
   move  $a3, $s0
  lw    $ra, 0x4c($sp)
.L7F022DF4:
  ldc1  $f20, 0x28($sp)
  lw    $s0, 0x30($sp)
  lw    $s1, 0x34($sp)
  lw    $s2, 0x38($sp)
  lw    $s3, 0x3c($sp)
  lw    $s4, 0x40($sp)
  lw    $s5, 0x44($sp)
  lw    $s6, 0x48($sp)
  jr    $ra
   addiu $sp, $sp, 0xf8
");

asm(R"
glabel sub_GAME_7F022E1C
  jr    $ra
   swc1  $f12, ($sp)
");

void sub_GAME_7F022E24(int param_1) { D_8002C904 = param_1; }

asm(R"
glabel sub_GAME_7F022E30
  lui   $v1, %hi(D_8002C908)
  addiu $v1, %lo(D_8002C908) # addiu $v1, $v1, -0x36f8
  lw    $t6, ($v1)
  lui   $a0, %hi(animation_table_ptrs1)
  addiu $a0, %lo(animation_table_ptrs1) # addiu $a0, $a0, -0x6294
  addiu $t7, $t6, -1
  bgez  $t7, .L7F022E88
   sw    $t7, ($v1)
  sll   $t9, $zero, 2
  addu  $t0, $a0, $t9
  lw    $t1, 4($t0)
  sw    $zero, ($v1)
  move  $v0, $zero
  beqz  $t1, .L7F022E88
   addiu $t2, $v0, 1
.L7F022E6C:
  sll   $t3, $t2, 2
  addu  $t4, $a0, $t3
  lw    $t5, 4($t4)
  sw    $t2, ($v1)
  move  $v0, $t2
  bnezl $t5, .L7F022E6C
   addiu $t2, $v0, 1
.L7F022E88:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F022E90
  lui   $v0, %hi(D_8002C908)
  addiu $v0, %lo(D_8002C908) # addiu $v0, $v0, -0x36f8
  lw    $t6, ($v0)
  lui   $t0, %hi(animation_table_ptrs1)
  addiu $t7, $t6, 1
  sll   $t9, $t7, 2
  sw    $t7, ($v0)
  addu  $t0, $t0, $t9
  lw    $t0, %lo(animation_table_ptrs1)($t0)
  bnez  $t0, .L7F022EC0
   nop   
  sw    $zero, ($v0)
.L7F022EC0:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F022EC8
  lui   $v1, %hi(D_8002C90C)
  addiu $v1, %lo(D_8002C90C) # addiu $v1, $v1, -0x36f4
  lw    $v0, ($v1)
  sltiu $t6, $v0, 1
  jr    $ra
   sw    $t6, ($v1)
");

void sub_GAME_7F022EE0(int param_1) { D_8002C910 = param_1; }

asm(R"
glabel sub_GAME_7F022EEC
  addiu $sp, $sp, -0x40
  sw    $s4, 0x38($sp)
  lui   $s4, %hi(num_guards)
  addiu $s4, %lo(num_guards) # addiu $s4, $s4, -0x3398
  lw    $t6, ($s4)
  sw    $s2, 0x30($sp)
  sdc1  $f22, 0x20($sp)
  mov.s $f22, $f12
  sw    $ra, 0x3c($sp)
  sw    $s3, 0x34($sp)
  sw    $s1, 0x2c($sp)
  sw    $s0, 0x28($sp)
  sdc1  $f20, 0x18($sp)
  blez  $t6, .L7F022FA0
   move  $s2, $zero
  lui   $s3, %hi(ptr_guard_data)
  addiu $s3, %lo(ptr_guard_data) # addiu $s3, $s3, -0x339c
  move  $s1, $zero
  lw    $s0, ($s3)
.L7F022F38:
  li    $at, 0x42C80000 # 100.000000
  addu  $t7, $s0, $s1
  lw    $t8, 0x1c($t7)
  beql  $t8, $zero, .L7F022F8C
   lw    $t0, ($s4)
  mtc1  $at, $f4
  addu  $a0, $s1, $s0
  mul.s $f20, $f22, $f4
  jal   sub_GAME_7F032DE4
   nop   
  lw    $s0, ($s3)
  addu  $t9, $s0, $s1
  lwc1  $f6, 0xec($t9)
  mul.s $f8, $f6, $f20
  c.lt.s $f0, $f8
  nop   
  bc1fl .L7F022F8C
   lw    $t0, ($s4)
  jal   sub_GAME_7F029C00
   addu  $a0, $s1, $s0
  lw    $t0, ($s4)
.L7F022F8C:
  addiu $s2, $s2, 1
  addiu $s1, $s1, 0x1dc
  slt   $at, $s2, $t0
  bnezl $at, .L7F022F38
   lw    $s0, ($s3)
.L7F022FA0:
  lw    $ra, 0x3c($sp)
  ldc1  $f20, 0x18($sp)
  ldc1  $f22, 0x20($sp)
  lw    $s0, 0x28($sp)
  lw    $s1, 0x2c($sp)
  lw    $s2, 0x30($sp)
  lw    $s3, 0x34($sp)
  lw    $s4, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x40
");

asm(R"
glabel check_if_guardnum_loaded_get_ptr_GUARDdata
  lui   $v1, %hi(num_guards)
  lw    $v1, %lo(num_guards)($v1)
  move  $a3, $a0
  lui   $a0, %hi(ptr_guard_data)
  blez  $v1, .L7F023020
   move  $v0, $zero
  lw    $a0, %lo(ptr_guard_data)($a0)
  move  $a1, $zero
  move  $a2, $a0
.L7F022FEC:
  lw    $t6, 0x1c($a2)
  addiu $v0, $v0, 1
  slt   $at, $v0, $v1
  beql  $t6, $zero, .L7F023018
   addiu $a1, $a1, 0x1dc
  lh    $t7, ($a2)
  bnel  $a3, $t7, .L7F023018
   addiu $a1, $a1, 0x1dc
  jr    $ra
   addu  $v0, $a1, $a0

  addiu $a1, $a1, 0x1dc
.L7F023018:
  bnez  $at, .L7F022FEC
   addiu $a2, $a2, 0x1dc
.L7F023020:
  move  $v0, $zero
  jr    $ra
   nop   
");

asm(R"
glabel something_with_weaponpos_of_guarddata_hand
  sll   $t6, $a1, 2
  addu  $t7, $a0, $t6
  jr    $ra
   lw    $v0, 0x160($t7)
");

asm(R"
glabel is_weapon_in_guarddata_hand
  addiu $sp, $sp, -0x20
  sll   $t6, $a1, 2
  sw    $ra, 0x14($sp)
  addu  $t7, $a0, $t6
  lw    $v1, 0x160($t7)
  beql  $v1, $zero, .L7F02307C
   lw    $ra, 0x14($sp)
  lw    $v0, 4($v1)
  li    $a1, 512
  lb    $a0, 0x80($v0)
  jal   check_special_attributes
   sw    $v1, 0x1c($sp)
  bnez  $v0, .L7F023078
   lw    $v1, 0x1c($sp)
  move  $v1, $zero
.L7F023078:
  lw    $ra, 0x14($sp)
.L7F02307C:
  addiu $sp, $sp, 0x20
  move  $v0, $v1
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F02308C
  lw    $v0, 4($a0)
  li    $t0, 4
  li    $at, 5
  lb    $v1, 7($v0)
  beql  $t0, $v1, .L7F023158
   sw    $zero, ($a2)
  beql  $v1, $at, .L7F023158
   sw    $zero, ($a2)
  lw    $t6, 0x14($v0)
  lui   $at, (0x00010400 >> 16) # lui $at, 1
  ori   $at, (0x00010400 & 0xFFFF) # ori $at, $at, 0x400
  and   $t7, $t6, $at
  bnezl $t7, .L7F023158
   sw    $zero, ($a2)
  lhu   $t8, 0x12($v0)
  addiu $t1, $v0, 0x11c
  andi  $t9, $t8, 0x100
  bnezl $t9, .L7F023158
   sw    $zero, ($a2)
  sw    $t0, ($a2)
  sw    $t1, ($a1)
  lwc1  $f4, 8($a0)
  lwc1  $f0, 0x24($v0)
  add.s $f6, $f4, $f0
  swc1  $f6, 0x11c($v0)
  lwc1  $f8, 0x10($a0)
  swc1  $f8, 0x120($v0)
  lwc1  $f10, 8($a0)
  swc1  $f10, 0x124($v0)
  lwc1  $f16, 0x10($a0)
  add.s $f18, $f16, $f0
  swc1  $f18, 0x128($v0)
  lwc1  $f4, 8($a0)
  sub.s $f6, $f4, $f0
  lwc1  $f4, 0xac($v0)
  swc1  $f6, 0x12c($v0)
  lwc1  $f8, 0x10($a0)
  swc1  $f8, 0x130($v0)
  lwc1  $f10, 8($a0)
  swc1  $f10, 0x134($v0)
  lwc1  $f16, 0x10($a0)
  lw    $v1, 0x10($sp)
  sub.s $f18, $f16, $f0
  swc1  $f18, 0x138($v0)
  swc1  $f4, ($v1)
  lwc1  $f8, 0x28($v0)
  lwc1  $f6, ($v1)
  add.s $f10, $f6, $f8
  jr    $ra
   swc1  $f10, ($a3)

  sw    $zero, ($a2)
.L7F023158:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F023160
  lw    $v0, 4($a0)
  li    $at, 0x41A00000 # 20.000000
  mtc1  $at, $f0
  lwc1  $f4, 0x24($v0)
  swc1  $f4, ($a1)
  lwc1  $f6, 0x28($v0)
  sub.s $f8, $f6, $f0
  swc1  $f8, ($a2)
  jr    $ra
   swc1  $f0, ($a3)
");

float sub_GAME_7F023188(unsigned int *a0[]) {
  float *ret = a0[1];
  return *(ret + 43);
}

asm(R"
glabel sub_GAME_7F023194
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $a1, 0x24($sp)
  sw    $a3, 0x2c($sp)
  lbu   $t6, 1($a0)
  lw    $v1, 4($a0)
  andi  $t7, $t6, 2
  beql  $t7, $zero, .L7F023280
   move  $v0, $zero
  lb    $v0, 7($v1)
  li    $at, 4
  beq   $v0, $at, .L7F02327C
   li    $at, 5
  beql  $v0, $at, .L7F023280
   move  $v0, $zero
  lw    $t8, 0x14($v1)
  andi  $t9, $t8, 0x800
  bnezl $t9, .L7F023280
   move  $v0, $zero
  lw    $a0, 0x1c($v1)
  li    $at, 0x3E800000 # 0.250000
  mtc1  $at, $f14
  lw    $v0, 0xc($a0)
  mtc1  $zero, $f12
  addiu $t0, $v0, 0x40
  lwc1  $f0, 0x38($t0)
  lwc1  $f4, 0x38($v0)
  sub.s $f6, $f4, $f0
  mul.s $f8, $f6, $f14
  add.s $f10, $f8, $f0
  c.lt.s $f10, $f12
  swc1  $f10, 8($a1)
  bc1fl .L7F023280
   move  $v0, $zero
  lwc1  $f0, 0x30($t0)
  lwc1  $f16, 0x30($v0)
  sub.s $f18, $f16, $f0
  mul.s $f4, $f18, $f14
  add.s $f6, $f4, $f0
  swc1  $f6, ($a1)
  lwc1  $f8, 0x34($v0)
  lwc1  $f2, 0x34($t0)
  sub.s $f10, $f8, $f2
  mul.s $f16, $f10, $f14
  add.s $f18, $f16, $f2
  swc1  $f18, 4($a1)
  lw    $t3, 0x2c($sp)
  addiu $a1, $a2, 4
  swc1  $f12, 4($t3)
  swc1  $f12, ($t3)
  swc1  $f12, ($a2)
  swc1  $f12, 4($a2)
  lw    $t4, 0x2c($sp)
  addiu $a3, $t4, 4
  jal   sub_GAME_7F03F90C
   sw    $t4, 0x10($sp)
  b     .L7F023280
   li    $v0, 1
.L7F02327C:
  move  $v0, $zero
.L7F023280:
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");
