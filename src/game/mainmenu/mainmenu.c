#include "mainmenu.h"
#include "bondtypes.h"
#include "music.h"
#include <gbi.h>
#include <stddef.h>
#include <types.h>

float flt_CODE_bss_800695A0;
float flt_CODE_bss_800695A4;
float flt_CODE_bss_800695A8;
float flt_CODE_bss_800695AC;
float flt_CODE_bss_800695B0;
float flt_CODE_bss_800695B4;
float flt_CODE_bss_800695B8;
float flt_CODE_bss_800695BC;
float flt_CODE_bss_800695C0;
float flt_CODE_bss_800695C4;
float flt_CODE_bss_800695C8;
float flt_CODE_bss_800695CC;
float flt_CODE_bss_800695D0;
float flt_CODE_bss_800695D4;
float flt_CODE_bss_800695D8;
float flt_CODE_bss_800695DC;
float flt_CODE_bss_800695E0;
float flt_CODE_bss_800695E4;
float flt_CODE_bss_800695E8;
float flt_CODE_bss_800695EC;
float flt_CODE_bss_800695F0;
float flt_CODE_bss_800695F4;
float flt_CODE_bss_800695F8;
float flt_CODE_bss_800695FC;
float flt_CODE_bss_80069600;
float flt_CODE_bss_80069604;
float flt_CODE_bss_80069608;
float flt_CODE_bss_8006960C;
float flt_CODE_bss_80069610;
float flt_CODE_bss_80069614;
float flt_CODE_bss_80069618;
float flt_CODE_bss_8006961C;
char dword_CODE_bss_80069620[0x30];

unsigned char CHEAT_80069650;
unsigned char cheat_available;
unsigned char CHEAT_AVAILABLE_INVINCIBLE;
unsigned char CHEAT_AVAILABLE_ALLGUNS;
unsigned char CHEAT_80069654;
unsigned char CHEAT_80069655;
unsigned char CHEAT_80069656;
unsigned char CHEAT_AVAILABLE_LINEMODE;
unsigned char CHEAT_AVAILABLE_2X_HEALTH;
unsigned char CHEAT_AVAILABLE_2X_ARMOR;
unsigned char CHEAT_AVAILABLE_BOND_INVIS;
unsigned char CHEAT_AVAILABLE_INFINITE_AMMO;
unsigned char CHEAT_AVAILABLE_DK_MODE;
unsigned char CHEAT_AVAILABLE_EXTRA_WEAPONS;
unsigned char CHEAT_AVAILABLE_TINY_BOND;
unsigned char CHEAT_AVAILABLE_PAINTBALL;
unsigned char CHEAT_AVAILABLE_10X_HEALTH;
unsigned char CHEAT_AVAILABLE_MAGNUM;
unsigned char CHEAT_AVAILABLE_LASER;
unsigned char CHEAT_AVAILABLE_GOLDENGUN;
unsigned char CHEAT_AVAILABLE_SILVERPP7;
unsigned char CHEAT_AVAILABLE_GOLDPP7;
unsigned char CHEAT_AVAILABLE_MP_INVINCIBILITY;
unsigned char CHEAT_AVAILABLE_NO_MP_RADAR;
unsigned char CHEAT_AVAILABLE_TURBO;
unsigned char CHEAT_AVAILABLE_DEBUG_MODE;
unsigned char CHEAT_AVAILABLE_FAST_ANI;
unsigned char CHEAT_AVAILABLE_SLOW_ANI;
unsigned char CHEAT_AVAILABLE_ENMY_ROCKETS;
unsigned char CHEAT_AVAILABLE_2X_ROCKET;
unsigned char CHEAT_AVAILABLE_2X_GRENADE_LAUNCHER;
unsigned char CHEAT_AVAILABLE_2X_RCP90;
unsigned char CHEAT_AVAILABLE_2X_THROWING_KNIVES;
unsigned char CHEAT_AVAILABLE_2X_HUNTING_KNIVES;
unsigned char CHEAT_AVAILABLE_2X_LASER;
unsigned char CHEAT_80069673;
unsigned char CHEAT_80069674;
unsigned char CHEAT_80069675;
unsigned char CHEAT_80069676;
unsigned char CHEAT_80069677;
unsigned char CHEAT_80069678[0x28];

unsigned char cheat_activated;
unsigned char CHEAT_AVAILABLE_EXTRA_CHARS;
unsigned char cheat_activated_1;
unsigned char cheat_activated_2;
unsigned char CHEAT_AVAILABLE_MAX_AMMO;
unsigned char cheat_activated_4;
unsigned char cheat_activated_5;
unsigned char cheat_activated_6;
unsigned char cheat_activated_7;
unsigned char cheat_activated_8;
unsigned char cheat_activated_9;
unsigned char cheat_activated_10;
unsigned char cheat_activated_11;
unsigned char cheat_activated_12;
unsigned char cheat_activated_13;
unsigned char cheat_activated_14;
unsigned char cheat_activated_15;
unsigned char cheat_activated_16;
unsigned char cheat_activated_17;
unsigned char cheat_activated_18;
unsigned char cheat_activated_19;
unsigned char cheat_activated_20;
unsigned char cheat_activated_21;
unsigned char cheat_activated_22;
unsigned char cheat_activated_23;
unsigned char cheat_activated_24;
unsigned char cheat_activated_25;
unsigned char cheat_activated_26;
unsigned char cheat_activated_27;
unsigned char cheat_activated_28;
unsigned char cheat_activated_29;
unsigned char cheat_activated_30;
unsigned char cheat_activated_31;
unsigned char cheat_activated_32;
unsigned char cheat_activated_33;
unsigned char cheat_activated_34;
unsigned char cheat_activated_35;
unsigned char cheat_activated_36;
unsigned char cheat_activated_37;
unsigned char cheat_activated_38;
unsigned char cheat_activated_39;
unsigned char cheat_activated_40;
unsigned char cheat_activated_41;
unsigned char cheat_activated_42;
unsigned char cheat_activated_43;
unsigned char cheat_activated_44;
unsigned char cheat_activated_45;
unsigned char cheat_activated_46;
unsigned char cheat_activated_47;
unsigned char cheat_activated_48;
unsigned char cheat_activated_49;
unsigned char cheat_activated_50;
unsigned char cheat_activated_51;
unsigned char cheat_activated_52;
unsigned char cheat_activated_53;
unsigned char cheat_activated_54;
unsigned char cheat_activated_55;
unsigned char cheat_activated_56;
unsigned char cheat_activated_57;
unsigned char cheat_activated_58;
unsigned char cheat_activated_59;
unsigned char cheat_activated_60;
unsigned char cheat_activated_61;
unsigned char cheat_activated_62;
unsigned char cheat_activated_63;
unsigned char cheat_activated_64;
unsigned char cheat_activated_65;
unsigned char cheat_activated_66;
unsigned char cheat_activated_67;
unsigned char cheat_activated_68;
unsigned char cheat_activated_69;
unsigned char cheat_activated_70;
unsigned char cheat_activated_71;
unsigned char cheat_activated_72;
unsigned char cheat_activated_73;
unsigned char cheat_activated_74;
unsigned char cheat_activated_75;
unsigned char cheat_activated_76;
unsigned char cheat_activated_77;
unsigned char cheat_activated_78;

int array_favweapon[4][2];

int mp_char_cur_select_player1;
int mp_char_cur_select_player2;
int mp_char_cur_select_player3;
int mp_char_cur_select_player4;
int mp_char_prev_select_player1;
int mp_char_prev_select_player2;
int mp_char_prev_select_player3;
int mp_char_prev_select_player4;
int dword_CODE_bss_80069730;
int dword_CODE_bss_80069734;
int dword_CODE_bss_80069738;
int dword_CODE_bss_8006973C;
int has_selected_char_player1;
int has_selected_char_player2;
int has_selected_char_player3;
int has_selected_char_player4;
int size_mp_select_image_player1;
int size_mp_select_image_player2;
int size_mp_select_image_player3;
int size_mp_select_image_player4;
int dword_CODE_bss_80069760;
int dword_CODE_bss_80069764;
int dword_CODE_bss_80069768;
int dword_CODE_bss_8006976C;
int dword_CODE_bss_80069770;
int dword_CODE_bss_80069774;
int dword_CODE_bss_80069778;
int current_mp_stage_highlighted;
int dword_CODE_bss_80069780;
int mission_difficulty_highlighted;
int teamsize;
int ptrbriefingdata;
int newcheatunlocked;
int highlight_enemy_reaction;
int highlight_enemy_health;
int highlight_enemy_accuracy;
int highlight_enemy_damage;

int dword_CODE_bss_800697A4;

int handicap_player1;
int handicap_player2;
int handicap_player3;
int handicap_player4;
unsigned int controlstyle_player[4];

int highlight_players;
int highlight_scenario;
int highlight_gameselect;
int highlight_gamelength;
int highlight_character;
int highlight_weaponselect;
int highlight_health;
int highlight_controlstyle;
int highlight_aimadjustment;
char dword_CODE_bss_800697F0[0x130];

int current_menu = -1;
int menu_update = -1;
int maybe_prev_menu = -1;
int menu_timer = 0;
int tab_1_selected = 0;
int tab_2_selected = 0;
int tab_3_selected = 0;
int tab_1_highlight = 0;
int tab_2_highlight = 0;
int tab_3_highlight = 0;
int selected_folder_num = 0;
int selected_folder_num_copy = 0;
int gamemode = -1; // GAMEMODE_INTRO;
int selected_stage = -1;
int briefingpage = -1;
int selected_difficulty = -1; // DIFFICULTY_MULTI;
int append_cheat_sp = false;
int append_cheat_mp = false;
float cursor_h_pos = 220.0;
float cursor_v_pos = 165.0;
int final_menu_briefing_page = 2;
int current_menu_briefing_page = 0;
int folder_selection_screen_option_icon = 0;
int folder_selected_for_deletion = -1;
int folder_selected_for_deletion_choice = 1;
int mission_failed_or_aborted = 0;
int mission_kia_flag = 0;
int is_first_time_on_legal_screen = true;
int is_first_time_on_main_menu = true;
int prev_keypresses = 0;
int D_8002A938 = 0;
int maybe_is_in_menu = true;
int screen_size = 0; // SCREEN_SIZE_320x240;
int spectrum_related_flag = 0;
int is_emulating_spectrum = false;
int is_cheat_menu_available = false;
int ptr_logo_and_walletbond_DL = 0;
int ptr_menu_videobuffer = 0;
int something_legalscreen_constructor = 0;
int ptr_folder_object_instance = 0;
int set0_never_used = 0;
int set0_never_used_0 = 0;
int D_8002A968 = 0;
int D_8002A96C = 0;
struct color D_8002A970 = {0x96, 0x96, 0x96, 0};
struct color D_8002A974 = {0x96, 0x96, 0x96, 0};
struct color D_8002A978 = {0xFF, 0xFF, 0xFF, 0};
struct color D_8002A97C = {0xFF, 0xFF, 0xFF, 0};
struct color D_8002A980 = {0x4D, 0x4D, 0x2E, 0};
struct color D_8002A984 = {0};
struct color D_8002A988 = {0xFF, 0xFF, 0xFF, 0};
struct color D_8002A98C = {0xFF, 0xFF, 0xFF, 0};
unsigned int D_8002A990 = 0;
unsigned int D_8002A994 = 0;
unsigned int D_8002A998 = 0;
unsigned int D_8002A99C = 0;
float slider_007_mode_reaction = 0.0f;
float slider_007_mode_health = 1.0f;
float slider_007_mode_accuracy = 1.0f;
float slider_007_mode_damage = 1.0f;
unsigned int D_8002A9B0 = 0xA0000000;
unsigned int D_8002A9B4 = 0x96000000;
unsigned int D_8002A9B8 = 0x28000000;
unsigned int D_8002A9BC = 0x8C000000;
unsigned int D_8002A9C0 = 0;
unsigned int D_8002A9C4 = 0;
unsigned int D_8002A9C8 = 0;

struct legal_screen_text {
  int h_pos, v_pos;
  int flag, flag2;
  short txtID;
  short anonymous_5;
};

struct legal_screen_text D_8002A9CC[] = {
    {220, 30, 1, 1, TEXT(LTITLE, 0x07), 0},
    {34, 83, 0, 1, TEXT(LTITLE, 0x08), 0},
    {226, 84, 0, 1, TEXT(LTITLE, 0x09), 0},
    {226, 97, 0, 1, TEXT(LTITLE, 0x0A), 0},
    {226, 110, 0, 1, TEXT(LTITLE, 0x0B), 0},
    {226, 122, 0, 1, TEXT(LTITLE, 0x0C), 0},
    {227, 134, 0, 1, TEXT(LTITLE, 0x0D), 0},
    {219, 211, 0, 1, TEXT(LTITLE, 0x0E), 0},
    {60, 169, 0, 1, TEXT(LTITLE, 0x0F), 0},
    {60, 201, 0, 1, TEXT(LTITLE, 0x10), 0},
    {99, 266, 0, 1, TEXT(LTITLE, 0x11), 0},
    {80, 280, 0, 1, TEXT(LTITLE, 0x12), 0}};

unsigned int D_8002AABC = 0;

unsigned int D_8002AAC0 = 1;
unsigned int D_8002AAC4 = 3;
unsigned int D_8002AAC8 = 0;
unsigned int D_8002AACC = 0;
unsigned int D_8002AAD0 = 0;
unsigned int D_8002AAD4 = 0;
unsigned int D_8002AAD8 = 0;
unsigned int D_8002AADC = 0;
unsigned int D_8002AAE0 = 0;
unsigned int D_8002AAE4 = 0;
unsigned int D_8002AAE8 = 0;
unsigned int D_8002AAEC = 0;
unsigned int D_8002AAF0 = 0;
unsigned int D_8002AAF4 = 0;
unsigned int D_8002AAF8 = 0;
unsigned int D_8002AAFC = 0;
unsigned int D_8002AB00 = 0;
unsigned int D_8002AB04 = 0;
unsigned int D_8002AB08 = 0;

unsigned int D_8002AB0C = 1;
unsigned int D_8002AB10 = 3;
unsigned int D_8002AB14 = 0;
unsigned int D_8002AB18 = 0;
unsigned int D_8002AB1C = 0;
unsigned int D_8002AB20 = 0;
unsigned int D_8002AB24 = 0;
unsigned int D_8002AB28 = 0;
unsigned int D_8002AB2C = 0;
unsigned int D_8002AB30 = 0;
unsigned int D_8002AB34 = 0;
unsigned int D_8002AB38 = 0;
unsigned int D_8002AB3C = 0;
unsigned int D_8002AB40 = 0;
unsigned int D_8002AB44 = 0;
unsigned int D_8002AB48 = 0;
unsigned int D_8002AB4C = 0;
unsigned int D_8002AB50 = 0;
unsigned int D_8002AB54 = 0;

unsigned int D_8002AB58 = 1;
unsigned int D_8002AB5C = 3;
unsigned int D_8002AB60 = 0;
unsigned int D_8002AB64 = 0;
unsigned int D_8002AB68 = 0;
unsigned int D_8002AB6C = 0;
unsigned int D_8002AB70 = 0;
unsigned int D_8002AB74 = 0;
unsigned int D_8002AB78 = 0;
unsigned int D_8002AB7C = 0;
unsigned int D_8002AB80 = 0;
unsigned int D_8002AB84 = 0;
unsigned int D_8002AB88 = 0;
unsigned int D_8002AB8C = 0;
unsigned int D_8002AB90 = 0;

float D_8002AB94 = -900.0f;
float D_8002AB98 = 800.0f;
float D_8002AB9C = 0.0f;
float D_8002ABA0 = 1800.0f;
float D_8002ABA4 = 800.0f;
float D_8002ABA8 = 0.0f;
float D_8002ABAC = -1800.0f;
float D_8002ABB0 = -200.0f;
float D_8002ABB4 = 0.0f;
float D_8002ABB8 = 900.0f;
float D_8002ABBC = -200.0f;
float D_8002ABC0 = 0.0f;

float folder_option_COPY_left_bound = 0.0f;
float folder_option_COPY_upper_bound = 0.0f;
float folder_option_COPY_right_bound = 0.0f;
float folder_option_COPY_lower_bound = 0.0f;
float folder_option_ERASE_left_bound = 0.0f;
float folder_option_ERASE_upper_bound = 0.0f;
float folder_option_ERASE_right_bound = 0.0f;
float folder_option_ERASE_lower_bound = 0.0f;

struct mission_folder_setup {
  void *string_ptr;
  short folder_text_preset;
  short icon_text_preset;
  int stage_id;
  int unknown;
  int type;
  int mission_num;
  void *briefing_name_ptr;
};

struct mission_folder_setup mission_folder_setup_entries[] = {
    {"1", TEXT(LTITLE, 0x78), 0, LEVELID_NONE, 0, MISSION_HEADER, -1, 0},
    {"i", TEXT(LTITLE, 0x79), 0, LEVELID_DAM, 0, MISSION_PART, 0, "UbriefdamZ"},
    {"ii", TEXT(LTITLE, 0x7A), 0, LEVELID_FACILITY, 0, MISSION_PART, 1,
     "UbriefarkZ"},
    {"iii", TEXT(LTITLE, 0x7B), 0, LEVELID_RUNWAY, 0, MISSION_PART, 2,
     "UbriefrunZ"},
    {"2", TEXT(LTITLE, 0x7C), 0, LEVELID_NONE, 0, MISSION_HEADER, -1, 0},
    {"i", TEXT(LTITLE, 0x7D), 0, LEVELID_SURFACE, 0, MISSION_PART, 3,
     "UbriefsevxZ"},
    {"ii", TEXT(LTITLE, 0x7E), 0, LEVELID_BUNKER1, 0, MISSION_PART, 4,
     "UbriefsevbunkerZ"},
    {"3", TEXT(LTITLE, 0x7F), 0, LEVELID_NONE, 1, MISSION_HEADER, -1, 0},
    {"i", TEXT(LTITLE, 0x80), TEXT(LTITLE, 0x81), LEVELID_SILO, 1, MISSION_PART,
     5, "UbriefsiloZ"},
    {"4", TEXT(LTITLE, 0x82), 0, LEVELID_NONE, 1, MISSION_HEADER, -1, 0},
    {"i", TEXT(LTITLE, 0x83), 0, LEVELID_FRIGATE, 1, MISSION_PART, 6,
     "UbriefdestZ"},
    {"5", TEXT(LTITLE, 0x7C), 0, LEVELID_NONE, 1, MISSION_HEADER, -1, 0},
    {"i", TEXT(LTITLE, 0x7D), 0, LEVELID_SURFACE2, 1, MISSION_PART, 7,
     "UbriefsevxbZ"},
    {"ii", TEXT(LTITLE, 0x7E), 0, LEVELID_BUNKER2, 1, MISSION_PART, 8,
     "UbriefsevbZ"},
    {"6", TEXT(LTITLE, 0x84), 0, LEVELID_NONE, 2, MISSION_HEADER, -1, 0},
    {"i", TEXT(LTITLE, 0x85), TEXT(LTITLE, 0x86), LEVELID_STATUE, 2,
     MISSION_PART, 9, "UbriefstatueZ"},
    {"ii", TEXT(LTITLE, 0x87), TEXT(LTITLE, 0x88), LEVELID_ARCHIVES, 2,
     MISSION_PART, 0xA, "UbriefarchZ"},
    {"iii", TEXT(LTITLE, 0x89), 0, LEVELID_STREETS, 2, MISSION_PART, 0xB,
     "UbriefpeteZ"},
    {"iv", TEXT(LTITLE, 0x8A), 0, LEVELID_DEPOT, 2, MISSION_PART, 0xC,
     "UbriefdepoZ"},
    {"v", TEXT(LTITLE, 0x8B), 0, LEVELID_TRAIN, 2, MISSION_PART, 0xD,
     "UbrieftraZ"},
    {"7", TEXT(LTITLE, 0x8C), 0, LEVELID_NONE, 3, MISSION_HEADER, -1, 0},
    {"i", TEXT(LTITLE, 0x8D), 0, LEVELID_JUNGLE, 3, MISSION_PART, 0xE,
     "UbriefjunZ"},
    {"ii", TEXT(LTITLE, 0x8E), TEXT(LTITLE, 0x8F), LEVELID_CONTROL, 3,
     MISSION_PART, 0xF, "UbriefcontrolZ"},
    {"iii", TEXT(LTITLE, 0x90), TEXT(LTITLE, 0x91), LEVELID_CAVERNS, 3,
     MISSION_PART, 0x10, "UbriefcaveZ"},
    {"iv", TEXT(LTITLE, 0x92), TEXT(LTITLE, 0x93), LEVELID_CRADLE, 3,
     MISSION_PART, 0x11, "UbriefcradZ"},
    {"8", TEXT(LTITLE, 0x94), 0, LEVELID_NONE, 4, MISSION_HEADER, -1, 0},
    {"i", TEXT(LTITLE, 0x95), TEXT(LTITLE, 0x96), LEVELID_AZTEC, 4,
     MISSION_PART, 0x12, "UbriefaztZ"},
    {"9", TEXT(LTITLE, 0x97), 0, LEVELID_NONE, 4, MISSION_HEADER, -1, 0},
    {"i", TEXT(LTITLE, 0x98), TEXT(LTITLE, 0x99), LEVELID_EGYPT, 4,
     MISSION_PART, 0x13, "UbriefcrypZ"},
    {NULL, 0, 0, LEVELID_NONE, -1, MISSION_PART, -1, 0}};

unsigned int unknown_folderselect_constructor = 0x14;
unsigned int D_8002AF30 = 0x14;
unsigned int D_8002AF34 = 0x14;
unsigned int unknown_folderselect_constructor_0 = 0x32;
unsigned int D_8002AF3C = 0x32;
unsigned int D_8002AF40 = 0x32;

unsigned int unknown_folderselect[] = {0, 1, 3, 0, 0, 0, 0, 0,
                                       0, 0, 0, 0, 0, 0, 0, 0};

unsigned int D_8002AF84[] = {0, 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

unsigned int D_8002AFC0 = 0;
unsigned int D_8002AFC4 = 0;
float D_8002AFC8 = 190.0;
float D_8002AFCC = -3300.0;
unsigned int cursor_xpos_table_mission_select[] = {73, 142, 212, 282, 352};
unsigned int cursor_ypos_table_mission_select[] = {62, 131, 201, 270};

struct MP_game_length_settings {
  unsigned short text_preset;
  unsigned short padding;
  int time;
  int points;
};

struct MP_game_length_settings multi_game_lengths[] = {
    {TEXT(LTITLE, 0x2D), 0, 0, 0},                   /* unlimited */
    {TEXT(LTITLE, 0x2E), 0, MINS_TO_TIMER60(5), 0},  /* 5 minutes */
    {TEXT(LTITLE, 0x2F), 0, MINS_TO_TIMER60(10), 0}, /* 10 minutes */
    {TEXT(LTITLE, 0x30), 0, MINS_TO_TIMER60(20), 0}, /* 20 minutes */
    {TEXT(LTITLE, 0x31), 0, 0, 5},                   /* first to 5 points */
    {TEXT(LTITLE, 0x32), 0, 0, 10},                  /* first to 10 points */
    {TEXT(LTITLE, 0x33), 0, 0, 20},                  /* first to 20 points */
    {TEXT(LTITLE, 0x34), 0, 0, 0} /* last person alive wins */
};

struct mp_stage_playercount mp_player_counts[] = {
    {TEXT(LTITLE, 0x35), 2, 4}, {TEXT(LTITLE, 0x36), 2, 4},
    {TEXT(LTITLE, 0x37), 2, 4}, {TEXT(LTITLE, 0x38), 2, 4},
    {TEXT(LTITLE, 0x39), 2, 4}, {TEXT(LTITLE, 0x3A), 4, 4},
    {TEXT(LTITLE, 0x3B), 4, 4}, {TEXT(LTITLE, 0x3C), 3, 3}};

struct mp_stage_setup multi_stage_setups[] = {
    /* unlocked by default */
    {TEXT(LTITLE, 0x9A), TEXT(LTITLE, 0x9B), 16, LEVELID_NONE, -1, 1, 4},
    {TEXT(LTITLE, 0x9C), TEXT(LTITLE, 0x9D), 12, LEVELID_TEMPLE, -1, 1, 4},
    {TEXT(LTITLE, 0x9E), TEXT(LTITLE, 0x9F), 14, LEVELID_COMPLEX, -1, 1, 4},
    {TEXT(LTITLE, 0xA2), TEXT(LTITLE, 0xA3), 15, LEVELID_CAVES, -1, 1, 4},
    {TEXT(LTITLE, 0xA0), TEXT(LTITLE, 0xA1), 13, LEVELID_LIBRARY, -1, 1, 4},
    {TEXT(LTITLE, 0x10D), TEXT(LTITLE, 0x10E), 13, LEVELID_BASEMENT, -1, 1, 4},
    {TEXT(LTITLE, 0x10F), TEXT(LTITLE, 0x110), 13, LEVELID_STACK, -1, 1, 4},
    /* unlocked on level progression */
    {TEXT(LTITLE, 0xA4), TEXT(LTITLE, 0xA5), 04, LEVELID_FACILITY, SP_LEVEL_DAM,
     1, 4},
    {TEXT(LTITLE, 0xA6), TEXT(LTITLE, 0xA7), 00, LEVELID_BUNKER2,
     SP_LEVEL_SURFACE2, 1, 3},
    {TEXT(LTITLE, 0xA8), TEXT(LTITLE, 0xA9), 02, LEVELID_ARCHIVES,
     SP_LEVEL_STATUE, 1, 3},
    {TEXT(LTITLE, 0xAA), TEXT(LTITLE, 0xAB), 01, LEVELID_CAVERNS,
     SP_LEVEL_CONTROL, 1, 3},
    {TEXT(LTITLE, 0xAC), TEXT(LTITLE, 0xAD), 10, LEVELID_EGYPT, SP_LEVEL_AZTEC,
     1, 2}};

unsigned int num_chars_selectable_mp = 8;

#ifdef VERSION_US
struct MP_selectable_chars mp_chr_setup[] = {
    {TEXT(LTITLE, 0xB8), MALE, 0, BODY_Tuxedo,
     HEAD_Male_Pierce_Bond_Tuxedo_DEFAULT, 1.0},
    {TEXT(LTITLE, 0xBF), FEMALE, 9, BODY_Natalya_Skirt,
     HEAD_Male_Pierce_Bond_Tuxedo_DEFAULT, 0.96609998},
    {TEXT(LTITLE, 0xBC), MALE, 6, BODY_Trevelyan_Janus,
     HEAD_Male_Pierce_Bond_Tuxedo_DEFAULT, 1.0},
    {TEXT(LTITLE, 0xBE), FEMALE, 8, BODY_Xenia,
     HEAD_Male_Pierce_Bond_Tuxedo_DEFAULT, 1.0},
    {TEXT(LTITLE, 0xBB), MALE, 5, BODY_Ourumov,
     HEAD_Male_Pierce_Bond_Tuxedo_DEFAULT, 1.0778},
    {TEXT(LTITLE, 0xBA), MALE, 4, BODY_Boris,
     HEAD_Male_Pierce_Bond_Tuxedo_DEFAULT, 0.9702},
    {TEXT(LTITLE, 0xBD), MALE, 7, BODY_Valentin_,
     HEAD_Male_Pierce_Bond_Tuxedo_DEFAULT, 0.93239999},
    {TEXT(LTITLE, 0xB9), MALE, 0xF, BODY_Siberian_Guard_1_Mishkin,
     HEAD_Male_Mishkin, 1.0},
    {TEXT(LTITLE, 0xC2), FEMALE, 0xC, BODY_Mayday,
     HEAD_Male_Pierce_Bond_Tuxedo_DEFAULT, 1.0},
    {TEXT(LTITLE, 0xC1), MALE, 0xB, BODY_Jaws,
     HEAD_Male_Pierce_Bond_Tuxedo_DEFAULT, 1.199},
    {TEXT(LTITLE, 0xC3), MALE, 0xD, BODY_Oddjob,
     HEAD_Male_Pierce_Bond_Tuxedo_DEFAULT, 0.78780001},
    {TEXT(LTITLE, 0xC0), MALE, 0xA, BODY_Baron_Samedi,
     HEAD_Male_Pierce_Bond_Tuxedo_DEFAULT, 1.0},
    {TEXT(LTITLE, 0xFD), MALE, 0xE, BODY_Russian_Soldier, HEAD_Male_Mark, 1.0},
    {TEXT(LTITLE, 0xFC), MALE, 0xE, BODY_Russian_Infantry, HEAD_Male_Karl, 1.0},
    {TEXT(LTITLE, 0x107), MALE, 0xE, BODY_Scientist_1_Male,
     HEAD_Male_Dave_Dr_Doak, 1.0},
    {TEXT(LTITLE, 0x107), FEMALE, 0xE, BODY_Scientist_2_Female,
     HEAD_Female_Sally, 1.0},
    {TEXT(LTITLE, 0x100), MALE, 0xE, BODY_Russian_Commandant, HEAD_Male_Martin,
     1.0},
    {TEXT(LTITLE, 0xFE), MALE, 0xE, BODY_Janus_Marine, HEAD_Male_Steve_Ellis,
     1.0},
    {TEXT(LTITLE, 0x101), MALE, 0xE, BODY_Naval_Officer, HEAD_Male_Duncan, 1.0},
    {TEXT(LTITLE, 0x106), MALE, 0xE, BODY_Helicopter_Pilot, HEAD_Male_Pete,
     1.0},
    {TEXT(LTITLE, 0xFB), MALE, 0xE, BODY_St_Petersburg_Guard, HEAD_Male_Ken,
     1.0},
    {TEXT(LTITLE, 0x108), FEMALE, 0xE, BODY_Civilian_1_Female,
     HEAD_Female_Marion_Rosika, 1.0},
    {TEXT(LTITLE, 0x108), MALE, 0xE, BODY_Civilian_2, HEAD_Male_Graeme, 1.0},
    {TEXT(LTITLE, 0x108), MALE, 0xE, BODY_Civilian_3, HEAD_Male_Grant, 1.0},
    {TEXT(LTITLE, 0x108), MALE, 0xE, BODY_Civilian_4, HEAD_Male_Dwayne, 1.0},
    {TEXT(LTITLE, 0x102), MALE, 0xE, BODY_Siberian_Guard_1_Mishkin,
     HEAD_Male_Lee, 1.0},
    {TEXT(LTITLE, 0x103), MALE, 0xE, BODY_Arctic_Commando, HEAD_Male_Chris,
     1.0},
    {TEXT(LTITLE, 0x102), MALE, 0xE, BODY_Siberian_Guard_2, HEAD_Male_Scott,
     1.0},
    {TEXT(LTITLE, 0x104), MALE, 0xE, BODY_Siberian_Special_Forces,
     HEAD_Male_Alan, 1.0},
    {TEXT(LTITLE, 0xFA), MALE, 0xE, BODY_Jungle_Commando, HEAD_Male_Joel, 1.0},
    {TEXT(LTITLE, 0xFF), MALE, 0xE, BODY_Janus_Special_Forces, HEAD_Male_B,
     1.0},
    {TEXT(LTITLE, 0x105), MALE, 0xE, BODY_Moonraker_Elite_1_Male,
     HEAD_Male_Neil, 1.0},
    {TEXT(LTITLE, 0x105), FEMALE, 0xE, BODY_Moonraker_Elite_2_Female,
     HEAD_Female_Vivien, 1.0},
    {TEXT(LTITLE, 0xC4), FEMALE, 0xE, BODY_Rosika, HEAD_Female_Marion_Rosika,
     0.88529998},
    {TEXT(LTITLE, 0xC5), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Karl, 1.0446},
    {TEXT(LTITLE, 0xC6), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Martin, 1.0446},
    {TEXT(LTITLE, 0xC7), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Mark, 1.0446},
    {TEXT(LTITLE, 0xC8), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Dave_Dr_Doak,
     1.0446},
    {TEXT(LTITLE, 0xC9), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Duncan, 1.0446},
    {TEXT(LTITLE, 0xCA), FEMALE, 0xE, BODY_Tuxedo, HEAD_Male_B, 1.0446},
    {TEXT(LTITLE, 0xCB), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Steve_Ellis, 1.0446},
    {TEXT(LTITLE, 0xCC), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Grant, 1.0446},
    {TEXT(LTITLE, 0xCD), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Graeme, 1.0446},
    {TEXT(LTITLE, 0xCE), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Ken, 1.0446},
    {TEXT(LTITLE, 0xCF), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Alan, 1.0446},
    {TEXT(LTITLE, 0xD0), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Pete, 1.0446},
    {TEXT(LTITLE, 0xD1), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Shaun, 1.0446},
    {TEXT(LTITLE, 0xD2), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Dwayne, 1.0446},
    {TEXT(LTITLE, 0xD3), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Des, 1.0446},
    {TEXT(LTITLE, 0xD4), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Chris, 1.0446},
    {TEXT(LTITLE, 0xD5), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Lee, 1.0446},
    {TEXT(LTITLE, 0xD6), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Neil, 1.0446},
    {TEXT(LTITLE, 0xD7), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Jim, 1.0446},
    {TEXT(LTITLE, 0xD8), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Robin, 1.0446},
    {TEXT(LTITLE, 0xD9), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Steve_H, 1.0446},
    {TEXT(LTITLE, 0xDA), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Terrorist, 1.0446},
    {TEXT(LTITLE, 0xDB), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Biker, 1.0446},
    {TEXT(LTITLE, 0xDC), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Joel, 1.0446},
    {TEXT(LTITLE, 0xDD), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Scott, 1.0446},
    {TEXT(LTITLE, 0xDE), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Joe, 1.0446},
    {TEXT(LTITLE, 0xDF), FEMALE, 0xE, BODY_Tuxedo, HEAD_Female_Sally, 1.0446},
    {TEXT(LTITLE, 0xE0), FEMALE, 0xE, BODY_Tuxedo, HEAD_Female_Marion_Rosika,
     1.0446},
    {TEXT(LTITLE, 0xE1), FEMALE, 0xE, BODY_Tuxedo, HEAD_Female_Mandy, 1.0446},
    {TEXT(LTITLE, 0xE2), FEMALE, 0xE, BODY_Tuxedo, HEAD_Female_Vivien, 1.0446}};
#endif

#ifdef VERSION_JP
struct MP_selectable_chars mp_chr_setup[] = {
    {TEXT(LTITLE, 0xB8), MALE, 0, BODY_Tuxedo,
     HEAD_Male_Pierce_Bond_Tuxedo_DEFAULT, 1.0},
    {TEXT(LTITLE, 0xBF), FEMALE, 9, BODY_Natalya_Skirt,
     HEAD_Male_Pierce_Bond_Tuxedo_DEFAULT, 0.96609998},
    {TEXT(LTITLE, 0xBC), MALE, 6, BODY_Trevelyan_Janus,
     HEAD_Male_Pierce_Bond_Tuxedo_DEFAULT, 1.0},
    {TEXT(LTITLE, 0xBE), FEMALE, 8, BODY_Xenia,
     HEAD_Male_Pierce_Bond_Tuxedo_DEFAULT, 1.0},
    {TEXT(LTITLE, 0xBB), MALE, 5, BODY_Ourumov,
     HEAD_Male_Pierce_Bond_Tuxedo_DEFAULT, 1.0778},
    {TEXT(LTITLE, 0xBA), MALE, 4, BODY_Boris,
     HEAD_Male_Pierce_Bond_Tuxedo_DEFAULT, 0.9702},
    {TEXT(LTITLE, 0xBD), MALE, 7, BODY_Valentin_,
     HEAD_Male_Pierce_Bond_Tuxedo_DEFAULT, 0.93239999},
    {TEXT(LTITLE, 0xB9), MALE, 0xF, BODY_Siberian_Guard_1_Mishkin,
     HEAD_Male_Mishkin, 1.0},
    {TEXT(LTITLE, 0xC2), FEMALE, 0xC, BODY_Mayday,
     HEAD_Male_Pierce_Bond_Tuxedo_DEFAULT, 1.0},
    {TEXT(LTITLE, 0xC1), MALE, 0xB, BODY_Jaws,
     HEAD_Male_Pierce_Bond_Tuxedo_DEFAULT, 1.199},
    {TEXT(LTITLE, 0xC3), MALE, 0xD, BODY_Oddjob,
     HEAD_Male_Pierce_Bond_Tuxedo_DEFAULT, 0.78780001},
    {TEXT(LTITLE, 0xC0), MALE, 0xA, BODY_Baron_Samedi,
     HEAD_Male_Pierce_Bond_Tuxedo_DEFAULT, 1.0},
    {TEXT(LTITLE, 0x11F), MALE, 0xE, BODY_Russian_Soldier, HEAD_Male_Mark, 1.0},
    {TEXT(LTITLE, 0x120), MALE, 0xE, BODY_Russian_Infantry, HEAD_Male_Karl,
     1.0},
    {TEXT(LTITLE, 0x121), MALE, 0xE, BODY_Scientist_1_Male,
     HEAD_Male_Dave_Dr_Doak, 1.0},
    {TEXT(LTITLE, 0x121), FEMALE, 0xE, BODY_Scientist_2_Female,
     HEAD_Female_Sally, 1.0},
    {TEXT(LTITLE, 0x122), MALE, 0xE, BODY_Russian_Commandant, HEAD_Male_Martin,
     1.0},
    {TEXT(LTITLE, 0x123), MALE, 0xE, BODY_Janus_Marine, HEAD_Male_Steve_Ellis,
     1.0},
    {TEXT(LTITLE, 0x124), MALE, 0xE, BODY_Naval_Officer, HEAD_Male_Duncan, 1.0},
    {TEXT(LTITLE, 0x125), MALE, 0xE, BODY_Helicopter_Pilot, HEAD_Male_Pete,
     1.0},
    {TEXT(LTITLE, 0x126), MALE, 0xE, BODY_St_Petersburg_Guard, HEAD_Male_Ken,
     1.0},
    {TEXT(LTITLE, 0x127), FEMALE, 0xE, BODY_Civilian_1_Female,
     HEAD_Female_Marion_Rosika, 1.0},
    {TEXT(LTITLE, 0x127), MALE, 0xE, BODY_Civilian_2, HEAD_Male_Graeme, 1.0},
    {TEXT(LTITLE, 0x127), MALE, 0xE, BODY_Civilian_3, HEAD_Male_Grant, 1.0},
    {TEXT(LTITLE, 0x127), MALE, 0xE, BODY_Civilian_4, HEAD_Male_Dwayne, 1.0},
    {TEXT(LTITLE, 0x128), MALE, 0xE, BODY_Siberian_Guard_1_Mishkin,
     HEAD_Male_Lee, 1.0},
    {TEXT(LTITLE, 0x129), MALE, 0xE, BODY_Arctic_Commando, HEAD_Male_Chris,
     1.0},
    {TEXT(LTITLE, 0x128), MALE, 0xE, BODY_Siberian_Guard_2, HEAD_Male_Scott,
     1.0},
    {TEXT(LTITLE, 0x12A), MALE, 0xE, BODY_Siberian_Special_Forces,
     HEAD_Male_Alan, 1.0},
    {TEXT(LTITLE, 0x12B), MALE, 0xE, BODY_Jungle_Commando, HEAD_Male_Joel, 1.0},
    {TEXT(LTITLE, 0x12C), MALE, 0xE, BODY_Janus_Special_Forces, HEAD_Male_B,
     1.0},
    {TEXT(LTITLE, 0x12D), MALE, 0xE, BODY_Moonraker_Elite_1_Male,
     HEAD_Male_Neil, 1.0},
    {TEXT(LTITLE, 0x12D), FEMALE, 0xE, BODY_Moonraker_Elite_2_Female,
     HEAD_Female_Vivien, 1.0},
    {TEXT(LTITLE, 0xC4), FEMALE, 0xE, BODY_Rosika, HEAD_Female_Marion_Rosika,
     0.88529998},
    {TEXT(LTITLE, 0xC5), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Karl, 1.0446},
    {TEXT(LTITLE, 0xC6), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Martin, 1.0446},
    {TEXT(LTITLE, 0xC7), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Mark, 1.0446},
    {TEXT(LTITLE, 0xC8), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Dave_Dr_Doak,
     1.0446},
    {TEXT(LTITLE, 0xC9), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Duncan, 1.0446},
    {TEXT(LTITLE, 0xCA), FEMALE, 0xE, BODY_Tuxedo, HEAD_Male_B, 1.0446},
    {TEXT(LTITLE, 0xCB), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Steve_Ellis, 1.0446},
    {TEXT(LTITLE, 0xCC), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Grant, 1.0446},
    {TEXT(LTITLE, 0xCD), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Graeme, 1.0446},
    {TEXT(LTITLE, 0xCE), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Ken, 1.0446},
    {TEXT(LTITLE, 0xCF), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Alan, 1.0446},
    {TEXT(LTITLE, 0xD0), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Pete, 1.0446},
    {TEXT(LTITLE, 0xD1), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Shaun, 1.0446},
    {TEXT(LTITLE, 0xD2), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Dwayne, 1.0446},
    {TEXT(LTITLE, 0xD3), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Des, 1.0446},
    {TEXT(LTITLE, 0xD4), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Chris, 1.0446},
    {TEXT(LTITLE, 0xD5), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Lee, 1.0446},
    {TEXT(LTITLE, 0xD6), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Neil, 1.0446},
    {TEXT(LTITLE, 0xD7), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Jim, 1.0446},
    {TEXT(LTITLE, 0xD8), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Robin, 1.0446},
    {TEXT(LTITLE, 0xD9), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Steve_H, 1.0446},
    {TEXT(LTITLE, 0xDA), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Terrorist, 1.0446},
    {TEXT(LTITLE, 0xDB), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Biker, 1.0446},
    {TEXT(LTITLE, 0xDC), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Joel, 1.0446},
    {TEXT(LTITLE, 0xDD), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Scott, 1.0446},
    {TEXT(LTITLE, 0xDE), MALE, 0xE, BODY_Tuxedo, HEAD_Male_Joe, 1.0446},
    {TEXT(LTITLE, 0xDF), FEMALE, 0xE, BODY_Tuxedo, HEAD_Female_Sally, 1.0446},
    {TEXT(LTITLE, 0xE0), FEMALE, 0xE, BODY_Tuxedo, HEAD_Female_Marion_Rosika,
     1.0446},
    {TEXT(LTITLE, 0xE1), FEMALE, 0xE, BODY_Tuxedo, HEAD_Female_Mandy, 1.0446},
    {TEXT(LTITLE, 0xE2), FEMALE, 0xE, BODY_Tuxedo, HEAD_Female_Vivien, 1.0446}};
#endif

struct MP_handicap_menu MP_handicap_table[] = {
    {TEXT(LTITLE, 0x3D), 0, 10.0},       {TEXT(LTITLE, 0x3E), 0, 2.8560996},
    {TEXT(LTITLE, 0x3F), 0, 2.1969998},  {TEXT(LTITLE, 0x40), 0, 1.6899998},
    {TEXT(LTITLE, 0x41), 0, 1.3},        {TEXT(LTITLE, 0x42), 0, 1.0},
    {TEXT(LTITLE, 0x43), 0, 0.76923078}, {TEXT(LTITLE, 0x44), 0, 0.59171599},
    {TEXT(LTITLE, 0x45), 0, 0.45516616}, {TEXT(LTITLE, 0x46), 0, 0.35012782},
    {TEXT(LTITLE, 0x47), 0, 0.1}};

struct MP_controller_configuration_menu MP_controller_configuration_table[] = {
    {0x9D, 0x15, 0, 1}, {0x9D, 0x16, 1, 1}, {0x9D, 0x17, 2, 1},
    {0x9D, 0x18, 3, 1}, {0x9D, 0x19, 4, 2}, {0x9D, 0x1A, 5, 2},
    {0x9D, 0x1B, 6, 2}, {0x9D, 0x1C, 7, 2}};

struct MP_sight_aim_settings mp_sight_adjust_table[] = {{0x9C, 0x48, 0, 0},
                                                        {0x9C, 0x49, 1, 0},
                                                        {0x9C, 0x4A, 0, 1},
                                                        {0x9C, 0x4B, 1, 1}};

int selected_num_players = 0;
int player_1_char = -1;
int player_2_char = -1;
int player_3_char = -1;
int player_4_char = -1;
int MP_stage_selected = MP_STAGE_TEMPLE;
int game_length = 2;
int aim_sight_adjustment = 3;
int scenario = 0;
int unlock_stage_select = 1;
int unlock_game_length = 1;
int unlock_chars = 1;
int unlock_weapon_select = 1;
int unlock_handicap = 1;
int unlock_control_style = 1;
int unlock_aim_sight = 1;

unsigned int D_8002B560 = 0;

struct solo_target_times solo_target_time_array[] = {
    {0, 160, 0}, {0, 0, 125}, {300, 0, 0}, {0, 210, 0}, {0, 0, 240},
    {180, 0, 0}, {0, 270, 0}, {0, 0, 255}, {90, 0, 0},  {0, 195, 0},
    {0, 0, 80},  {105, 0, 0}, {0, 100, 0}, {0, 0, 325}, {225, 0, 0},
    {0, 600, 0}, {0, 0, 570}, {135, 0, 0}, {0, 540, 0}, {0, 0, 360}};

unsigned int D_8002B5DC = 0;
unsigned int D_8002B5E0 = 0;

unsigned int MP_menu_selected_option = 0;
unsigned int do_not_play_intro_movie = 0;
unsigned int randomly_selected_intro_animation = 0;
unsigned int intro_animation_count = 0;
unsigned int objinstance = 0;
unsigned int ptrobjinstance = 0;
unsigned int full_actor_intro = 0;

struct intro_char intro_char_table[] = {
    {BODY_Tuxedo, 0x4E, TEXT(LTITLE, 0xE3), TEXT(LTITLE, 0xE4),
     TEXT(LTITLE, 0xE3), 0, 1},
    {BODY_Special_Operations_Uniform, 0x4A, TEXT(LTITLE, 0xE5),
     TEXT(LTITLE, 0xE8), TEXT(LTITLE, 0xE9), 0, 0},
    {BODY_Natalya_Skirt, 0xFFFFFFFF, TEXT(LTITLE, 0xE5), TEXT(LTITLE, 0xEA),
     TEXT(LTITLE, 0xE3), 0, 0},
    {BODY_Trevelyan_006, 0xFFFFFFFF, TEXT(LTITLE, 0xE5), TEXT(LTITLE, 0xEB),
     TEXT(LTITLE, 0xEC), 0, 0},
    {BODY_Xenia, 0xFFFFFFFF, TEXT(LTITLE, 0xE6), TEXT(LTITLE, 0xED),
     TEXT(LTITLE, 0xEE), 0, 0},
    {BODY_Ourumov, 0xFFFFFFFF, TEXT(LTITLE, 0xE6), TEXT(LTITLE, 0xEF),
     TEXT(LTITLE, 0xF0), 0, 0},
    {BODY_Boris, 0xFFFFFFFF, TEXT(LTITLE, 0xE6), TEXT(LTITLE, 0xF1),
     TEXT(LTITLE, 0xE3), 0, 0},
    {BODY_Valentin_, 0xFFFFFFFF, TEXT(LTITLE, 0xE6), TEXT(LTITLE, 0xF2),
     TEXT(LTITLE, 0xF3), 0, 0},
    {BODY_Siberian_Guard_1_Mishkin, 0x45, TEXT(LTITLE, 0xE6),
     TEXT(LTITLE, 0xF4), TEXT(LTITLE, 0xF5), 0, 0},
    {BODY_Russian_Soldier, 0xFFFFFF9F, TEXT(LTITLE, 0xE3), TEXT(LTITLE, 0xFD),
     TEXT(LTITLE, 0xE3), 0, 1},
    {BODY_Russian_Infantry, 0xFFFFFF9F, TEXT(LTITLE, 0xE3), TEXT(LTITLE, 0xFC),
     TEXT(LTITLE, 0xE3), 0, 1},
    {BODY_Scientist_1_Male, 0xFFFFFF9F, TEXT(LTITLE, 0xE3), TEXT(LTITLE, 0x107),
     TEXT(LTITLE, 0xE3), 0, 1},
    {BODY_Scientist_2_Female, 0xFFFFFF9F, TEXT(LTITLE, 0xE3),
     TEXT(LTITLE, 0x107), TEXT(LTITLE, 0xE3), 0, 1},
    {BODY_Russian_Commandant, 0xFFFFFF9F, TEXT(LTITLE, 0xE3),
     TEXT(LTITLE, 0x100), TEXT(LTITLE, 0xE3), 0, 1},
    {BODY_Janus_Marine, 0xFFFFFF9F, TEXT(LTITLE, 0xE3), TEXT(LTITLE, 0xFE),
     TEXT(LTITLE, 0xE3), 0, 1},
    {BODY_Naval_Officer, 0xFFFFFF9F, TEXT(LTITLE, 0xE3), TEXT(LTITLE, 0x101),
     TEXT(LTITLE, 0xE3), 0, 1},
    {BODY_Helicopter_Pilot, 0xFFFFFFFF, TEXT(LTITLE, 0xE3), TEXT(LTITLE, 0x106),
     TEXT(LTITLE, 0xE3), 0, 1},
    {BODY_St_Petersburg_Guard, 0xFFFFFF9F, TEXT(LTITLE, 0xE3),
     TEXT(LTITLE, 0xFB), TEXT(LTITLE, 0xE3), 0, 1},
    {BODY_Civilian_1_Female, 0xFFFFFF9F, TEXT(LTITLE, 0xE3),
     TEXT(LTITLE, 0x108), TEXT(LTITLE, 0xE3), 0, 1},
    {BODY_Civilian_2, 0xFFFFFF9F, TEXT(LTITLE, 0xE3), TEXT(LTITLE, 0x108),
     TEXT(LTITLE, 0xE3), 0, 1},
    {BODY_Civilian_3, 0xFFFFFF9F, TEXT(LTITLE, 0xE3), TEXT(LTITLE, 0x108),
     TEXT(LTITLE, 0xE3), 0, 1},
    {BODY_Civilian_4, 0xFFFFFF9F, TEXT(LTITLE, 0xE3), TEXT(LTITLE, 0x108),
     TEXT(LTITLE, 0xE3), 0, 1},
    {BODY_Siberian_Guard_1_Mishkin, 0xFFFFFF9F, TEXT(LTITLE, 0xE3),
     TEXT(LTITLE, 0x102), TEXT(LTITLE, 0xE3), 0, 1},
    {BODY_Arctic_Commando, 0xFFFFFF9F, TEXT(LTITLE, 0xE3), TEXT(LTITLE, 0x103),
     TEXT(LTITLE, 0xE3), 0, 1},
    {BODY_Siberian_Guard_2, 0xFFFFFF9F, TEXT(LTITLE, 0xE3), TEXT(LTITLE, 0x102),
     TEXT(LTITLE, 0xE3), 0, 1},
    {BODY_Siberian_Special_Forces, 0xFFFFFFFF, TEXT(LTITLE, 0xE3),
     TEXT(LTITLE, 0x104), TEXT(LTITLE, 0xE3), 0, 1},
    {BODY_Jungle_Commando, 0xFFFFFF9F, TEXT(LTITLE, 0xE3), TEXT(LTITLE, 0xFA),
     TEXT(LTITLE, 0xE3), 0, 1},
    {BODY_Janus_Special_Forces, 0xFFFFFF9F, TEXT(LTITLE, 0xE3),
     TEXT(LTITLE, 0xFF), TEXT(LTITLE, 0xE3), 0, 1},
    {BODY_Moonraker_Elite_1_Male, 0xFFFFFF9F, TEXT(LTITLE, 0xE3),
     TEXT(LTITLE, 0x105), TEXT(LTITLE, 0xE3), 0, 1},
    {BODY_Moonraker_Elite_2_Female, 0xFFFFFF9F, TEXT(LTITLE, 0xE3),
     TEXT(LTITLE, 0x105), TEXT(LTITLE, 0xE3), 0, 1},
    {BODY_Mayday, 0xFFFFFFFF, TEXT(LTITLE, 0xE7), TEXT(LTITLE, 0xF6),
     TEXT(LTITLE, 0xE3), 0, 0},
    {BODY_Jaws, 0xFFFFFFFF, TEXT(LTITLE, 0xE7), TEXT(LTITLE, 0xF7),
     TEXT(LTITLE, 0xE3), 0, 0},
    {BODY_Oddjob, 0xFFFFFFFF, TEXT(LTITLE, 0xE7), TEXT(LTITLE, 0xF8),
     TEXT(LTITLE, 0xE3), 0, 0},
    {BODY_Baron_Samedi, 0xFFFFFFFF, TEXT(LTITLE, 0xE7), TEXT(LTITLE, 0xF9),
     TEXT(LTITLE, 0xE3), 0, 0},
    {0xFFFFFFFF, 0, 0, 0, 0, 0, 0}};

struct intro_animation intro_animation_table[] = {
    {0x3F, 98.0, 1.0, 0},       {0x42, 21.0, 1.0, 1},
    {0x43, 26.0, 1.0, 1},       {0x48, 0.0, 1.0, 1},
    {0x4C, 0.0, 1.0, 1},        {0x59, 0.0, 0.91000003, 1},
    {0x62, 31.0, 1.0, 1},       {0x63, 0.0, 1.0, 1},
    {0x64, 0.0, 1.0, 1},        {0x66, 0.0, 1.0, 1},
    {0x67, 0.0, 1.0, 1},        {0x99, 248.0, 1.0, 0},
    {0xA3, 150.0, 1.0, 0},      {0x46, 0.0, 0.89999998, 1},
    {0x4A, 0.0, 0.89999998, 1}, {0x50, 0.0, 0.89999998, 1},
    {0x61, 51.0, 1.0, 1},       {0x96, 0.0, 0.89999998, 1},
    {0x97, 0.0, 0.89999998, 1}, {0x98, 37.0, 1.0, 2},
    {0xA1, 300.0, 1.0, 2},      {0xA0, 120.0, 1.0, 2},
    {0xFFFFFFFF, 0.0, 0.0, 0}};

unsigned int D_8002BA2C = 0;
unsigned int D_8002BA30 = 0;
unsigned int D_8002BA34 = 0;

PROPS random_rifles_in_intro[] = {PROP_chrkalash,        PROP_chrm16,
                                  PROP_chrfnp90,         PROP_chrautoshot,
                                  PROP_chrgrenadelaunch, PROP_chrsniperrifle};

PROPS random_pistols_in_intro[] = {
    PROP_chrwppk,  PROP_chrwppksil, PROP_chrskorpion, PROP_chruzi,
    PROP_chruzi,   PROP_chrtt33,    PROP_chrtt33,     PROP_chrruger,
    PROP_chrlaser, PROP_chrgolden};

float D_8002BA78 = 0.0f;
float D_8002BA7C = 0.0f;
float D_8002BA80 = 1.0f;

float D_8002BA84 = 0.0f;
float D_8002BA88 = 0.0f;
float D_8002BA8C = 0.0f;

float D_8002BA90 = 0.0f;
float D_8002BA94 = 1.0f;
float D_8002BA98 = 0.0f;

unsigned int D_8002BA9C = 0;
unsigned int D_8002BAA0 = 1;
unsigned int D_8002BAA4 = 3;
unsigned int D_8002BAA8 = 0;
unsigned int D_8002BAAC = 0;
unsigned int D_8002BAB0 = 0;
unsigned int D_8002BAB4 = 0;
unsigned int D_8002BAB8 = 0;
unsigned int D_8002BABC = 0;
unsigned int D_8002BAC0 = 0;
unsigned int D_8002BAC4 = 0;
unsigned int D_8002BAC8 = 0;
unsigned int D_8002BACC = 0;
unsigned int D_8002BAD0 = 0;
unsigned int D_8002BAD4 = 0;
unsigned int D_8002BAD8 = 0;
unsigned int D_8002BADC = 0;

float D_8002BAE0 = 40.0f;
float D_8002BAE4 = 25.0f;
unsigned int D_8002BAE8 = 0;
unsigned int D_8002BAEC = 1;

unsigned short color_palette_entries_50_percent[] = {
    1, 0x1F, 0x3C1, 0x3DF, 0x7801, 0x781F, 0x7BC1, 0x7BDF};

const char asc_D_8004F488[] = "\n";
const char a_[] = ".";
const char asc_D_8004F490[] = "\n";
const char a1_[] = "1.\n";
const char a2_[] = "2.\n";
const char a3_[] = "3.\n";
const char asc_D_8004F4A0[] = "\n";
const char asc_D_8004F4A4[] = ": ";
const char asc_D_8004F4A8[] = "\n";
const char asc_D_8004F4AC[] = ": ";
const char asc_D_8004F4B0[] = "\n";
const char asc_D_8004F4B4[3000] = {0xA, 0};
const char aD_[] = "%d.\n";
const char asc_D_80050074[3000] = {0xA, 0};
const char aD[] = "%d%%\n";
const char aD_0[] = "%d%%\n";
const char aD_1[] = "%d%%\n";
const char aD_2[] = "%d%%\n";
const char aD_7[] = "%d";
const char aA_[] = "a.\n";
const char asc_D_80050C54[3000] = {0xA, 0};

const char a02d02d[] = "%02d:%02d";
const char aS[] = "     [%s]";
const char a02d02d_0[] = "%02d:%02d";
const char aS02d02d[] = "     (%s  %02d:%02d)";
const char D_80051848[] = "";
const char a02d02d_1[] = "%02d:%02d";
const char a_1f[] = "%.1f%%";
const char aX2[] = " x 2\n";
const char aD_8[] = "%d";
const char aDD_0[] = "%d (%d%%)";
const char aDD_1[] = "%d (%d%%)";
const char aDD_2[] = "%d (%d%%)";
const char aDD_3[] = "%d (%d%%)";
const char aD_10[] = "%d";

asm(R"
glabel write_text_at_abs_coord
  lui   $t6, %hi(j_text_trigger) 
  lw    $t6, %lo(j_text_trigger)($t6)
  addiu $sp, $sp, -0x38
  sw    $ra, 0x34($sp)
  beqz  $t6, .L7F0097F8
   lw    $t5, 0x48($sp)
  lui   $t0, %hi(D_8002A9B0) 
  lui   $t2, %hi(D_8002A9B4) 
  lbu   $t2, %lo(D_8002A9B4)($t2)
  lbu   $t0, %lo(D_8002A9B0)($t0)
  lw    $t8, 0x4c($sp)
  lui   $t5, %hi(D_8002A9B8) 
  lbu   $t5, %lo(D_8002A9B8)($t5)
  lw    $t7, 0x48($sp)
  sll   $t3, $t2, 0x10
  sll   $t1, $t0, 0x18
  sw    $t8, 0x14($sp)
  lw    $t9, 0x50($sp)
  lui   $t8, %hi(D_8002A9BC) 
  or    $t4, $t1, $t3
  lbu   $t8, %lo(D_8002A9BC)($t8)
  sll   $t6, $t5, 8
  sw    $t7, 0x10($sp)
  lw    $t3, 0x60($sp)
  lw    $t1, 0x5c($sp)
  lw    $t0, 0x54($sp)
  lw    $t2, 0x58($sp)
  or    $t7, $t4, $t6
  sw    $t9, 0x18($sp)
  or    $t9, $t7, $t8
  sw    $t9, 0x1c($sp)
  sw    $t3, 0x2c($sp)
  sw    $t1, 0x28($sp)
  sw    $t0, 0x20($sp)
  jal   jp_text_write_stuff
   sw    $t2, 0x24($sp)
  b     .L7F009834
   move  $a0, $v0
.L7F0097F8:
  lw    $t4, 0x4c($sp)
  lw    $t6, 0x50($sp)
  lw    $t7, 0x54($sp)
  lw    $t8, 0x58($sp)
  lw    $t9, 0x5c($sp)
  lw    $t0, 0x60($sp)
  sw    $t5, 0x10($sp)
  sw    $t4, 0x14($sp)
  sw    $t6, 0x18($sp)
  sw    $t7, 0x1c($sp)
  sw    $t8, 0x20($sp)
  sw    $t9, 0x24($sp)
  jal   en_text_write_stuff
   sw    $t0, 0x28($sp)
  move  $a0, $v0
.L7F009834:
  lw    $ra, 0x34($sp)
  addiu $sp, $sp, 0x38
  move  $v0, $a0
  jr    $ra
   nop   
");

asm(R"
.late_rodata

glabel cheat_available_table
 .word default_nonmenucheats
 .word cheat_invincible
 .word cheat_allguns
 .word default_nonmenucheats
 .word default_nonmenucheats
 .word default_nonmenucheats
 .word default_nonmenucheats
 .word default_nonmenucheats
 .word default_nonmenucheats
 .word cheat_invisible
 .word cheat_infinite_ammo
 .word cheat_dk_mode
 .word default_nonmenucheats
 .word cheat_tinybond
 .word cheat_paintball
 .word default_nonmenucheats
 .word cheat_unlockcradle
 .word cheat_unlockaztec
 .word cheat_unlockegypt
 .word cheat_silverpp7
 .word cheat_goldpp7
 .word default_nonmenucheats
 .word cheat_noradar
 .word cheat_turbo
 .word default_nonmenucheats
 .word cheat_fast
 .word cheat_slow
 .word cheat_enemyrockets
 .word cheat_2xrocket
 .word cheat_2xgrenadelauncher
 .word cheat_2xrcp90
 .word cheat_2xthrowingknife
 .word cheat_2xhuntingknife
 .word cheat_2xlaser
 .word default_nonmenucheats
 .word default_nonmenucheats
 .word default_nonmenucheats
 .word default_nonmenucheats
 .word default_nonmenucheats
 .word default_nonmenucheats
 .word default_nonmenucheats
 .word default_nonmenucheats
 .word default_nonmenucheats
 .word default_nonmenucheats
 .word default_nonmenucheats
 .word default_nonmenucheats
 .word default_nonmenucheats
 .word default_nonmenucheats
 .word default_nonmenucheats
 .word default_nonmenucheats
 .word default_nonmenucheats
 .word default_nonmenucheats
 .word default_nonmenucheats
 .word default_nonmenucheats
 .word default_nonmenucheats
 .word default_nonmenucheats
 .word default_nonmenucheats
 .word default_nonmenucheats
 .word default_nonmenucheats
 .word default_nonmenucheats
 .word default_nonmenucheats
 .word default_nonmenucheats
 .word default_nonmenucheats
 .word default_nonmenucheats
 /*HACK FIXME*/
/* .word default_nonmenucheats */
/* .word default_nonmenucheats */
/* .word default_nonmenucheats */
/* .word default_nonmenucheats */
/* .word default_nonmenucheats */
/* .word default_nonmenucheats */
/* .word default_nonmenucheats */
/* .word default_nonmenucheats */
/* .word default_nonmenucheats */
/* .word default_nonmenucheats */

.text
glabel check_if_cheat_available
  addiu $t6, $a0, -1
  addiu $sp, $sp, -0x18
  sltiu $at, $t6, 0x4a
  beqz  $at, .L7F009B38
   sw    $ra, 0x14($sp)
  sll   $t6, $t6, 2
  lui   $at, %hi(cheat_available_table)
  addu  $at, $at, $t6
  lw    $t6, %lo(cheat_available_table)($at)
  jr    $t6
   nop   
default_nonmenucheats:
  b     .L7F009B40
   move  $v0, $zero
cheat_invincible:
  lui   $a0, %hi(selected_folder_num)
  jal   get_save_folder_ptr
   lw    $a0, %lo(selected_folder_num)($a0)
  move  $a0, $v0
  jal   check_if_cheat_unlocked
   li    $a1, 1
  b     .L7F009B44
   lw    $ra, 0x14($sp)
cheat_allguns:
  lui   $a0, %hi(selected_folder_num)
  jal   get_save_folder_ptr
   lw    $a0, %lo(selected_folder_num)($a0)
  move  $a0, $v0
  jal   check_if_cheat_unlocked
   li    $a1, 19
  b     .L7F009B44
   lw    $ra, 0x14($sp)
cheat_noradar:
  lui   $a0, %hi(selected_folder_num)
  jal   get_save_folder_ptr
   lw    $a0, %lo(selected_folder_num)($a0)
  move  $a0, $v0
  jal   check_if_cheat_unlocked
   li    $a1, 6
  b     .L7F009B44
   lw    $ra, 0x14($sp)
cheat_fast:
  lui   $a0, %hi(selected_folder_num)
  jal   get_save_folder_ptr
   lw    $a0, %lo(selected_folder_num)($a0)
  move  $a0, $v0
  jal   check_if_cheat_unlocked
   li    $a1, 9
  b     .L7F009B44
   lw    $ra, 0x14($sp)
cheat_invisible:
  lui   $a0, %hi(selected_folder_num)
  jal   get_save_folder_ptr
   lw    $a0, %lo(selected_folder_num)($a0)
  move  $a0, $v0
  jal   check_if_cheat_unlocked
   li    $a1, 10
  b     .L7F009B44
   lw    $ra, 0x14($sp)
cheat_infinite_ammo:
  lui   $a0, %hi(selected_folder_num)
  jal   get_save_folder_ptr
   lw    $a0, %lo(selected_folder_num)($a0)
  move  $a0, $v0
  jal   check_if_cheat_unlocked
   li    $a1, 15
  b     .L7F009B44
   lw    $ra, 0x14($sp)
cheat_dk_mode:
  lui   $a0, %hi(selected_folder_num)
  jal   get_save_folder_ptr
   lw    $a0, %lo(selected_folder_num)($a0)
  move  $a0, $v0
  jal   check_if_cheat_unlocked
   li    $a1, 2
  b     .L7F009B44
   lw    $ra, 0x14($sp)
cheat_tinybond:
  lui   $a0, %hi(selected_folder_num)
  jal   get_save_folder_ptr
   lw    $a0, %lo(selected_folder_num)($a0)
  move  $a0, $v0
  jal   check_if_cheat_unlocked
   li    $a1, 7
  b     .L7F009B44
   lw    $ra, 0x14($sp)
cheat_slow:
  lui   $a0, %hi(selected_folder_num)
  jal   get_save_folder_ptr
   lw    $a0, %lo(selected_folder_num)($a0)
  move  $a0, $v0
  jal   check_if_cheat_unlocked
   li    $a1, 12
  b     .L7F009B44
   lw    $ra, 0x14($sp)
cheat_paintball:
  lui   $a0, %hi(selected_folder_num)
  jal   get_save_folder_ptr
   lw    $a0, %lo(selected_folder_num)($a0)
  move  $a0, $v0
  jal   check_if_cheat_unlocked
   move  $a1, $zero
  b     .L7F009B44
   lw    $ra, 0x14($sp)
cheat_silverpp7:
  lui   $a0, %hi(selected_folder_num)
  jal   get_save_folder_ptr
   lw    $a0, %lo(selected_folder_num)($a0)
  move  $a0, $v0
  jal   check_if_cheat_unlocked
   li    $a1, 13
  b     .L7F009B44
   lw    $ra, 0x14($sp)
cheat_goldpp7:
  lui   $a0, %hi(selected_folder_num)
  jal   get_save_folder_ptr
   lw    $a0, %lo(selected_folder_num)($a0)
  move  $a0, $v0
  jal   check_if_cheat_unlocked
   li    $a1, 17
  b     .L7F009B44
   lw    $ra, 0x14($sp)
cheat_enemyrockets:
  lui   $a0, %hi(selected_folder_num)
  jal   get_save_folder_ptr
   lw    $a0, %lo(selected_folder_num)($a0)
  move  $a0, $v0
  jal   check_if_cheat_unlocked
   li    $a1, 11
  b     .L7F009B44
   lw    $ra, 0x14($sp)
cheat_2xrocket:
  lui   $a0, %hi(selected_folder_num)
  jal   get_save_folder_ptr
   lw    $a0, %lo(selected_folder_num)($a0)
  move  $a0, $v0
  jal   check_if_cheat_unlocked
   li    $a1, 4
  b     .L7F009B44
   lw    $ra, 0x14($sp)
cheat_2xgrenadelauncher:
  lui   $a0, %hi(selected_folder_num)
  jal   get_save_folder_ptr
   lw    $a0, %lo(selected_folder_num)($a0)
  move  $a0, $v0
  jal   check_if_cheat_unlocked
   li    $a1, 3
  b     .L7F009B44
   lw    $ra, 0x14($sp)
cheat_2xrcp90:
  lui   $a0, %hi(selected_folder_num)
  jal   get_save_folder_ptr
   lw    $a0, %lo(selected_folder_num)($a0)
  move  $a0, $v0
  jal   check_if_cheat_unlocked
   li    $a1, 16
  b     .L7F009B44
   lw    $ra, 0x14($sp)
cheat_2xthrowingknife:
  lui   $a0, %hi(selected_folder_num)
  jal   get_save_folder_ptr
   lw    $a0, %lo(selected_folder_num)($a0)
  move  $a0, $v0
  jal   check_if_cheat_unlocked
   li    $a1, 8
  b     .L7F009B44
   lw    $ra, 0x14($sp)
cheat_2xhuntingknife:
  lui   $a0, %hi(selected_folder_num)
  jal   get_save_folder_ptr
   lw    $a0, %lo(selected_folder_num)($a0)
  move  $a0, $v0
  jal   check_if_cheat_unlocked
   li    $a1, 14
  b     .L7F009B44
   lw    $ra, 0x14($sp)
cheat_2xlaser:
  lui   $a0, %hi(selected_folder_num)
  jal   get_save_folder_ptr
   lw    $a0, %lo(selected_folder_num)($a0)
  move  $a0, $v0
  jal   check_if_cheat_unlocked
   li    $a1, 18
  b     .L7F009B44
   lw    $ra, 0x14($sp)
cheat_turbo:
  lui   $a0, %hi(selected_folder_num)
  jal   get_save_folder_ptr
   lw    $a0, %lo(selected_folder_num)($a0)
  move  $a0, $v0
  jal   check_if_cheat_unlocked
   li    $a1, 5
  b     .L7F009B44
   lw    $ra, 0x14($sp)
cheat_unlockcradle:
  lui   $a0, %hi(selected_folder_num)
  jal   check_cradle_completed_in_folder
   lw    $a0, %lo(selected_folder_num)($a0)
  b     .L7F009B44
   lw    $ra, 0x14($sp)
cheat_unlockaztec:
  lui   $a0, %hi(selected_folder_num)
  jal   check_aztec_completed_in_folder_secret_00
   lw    $a0, %lo(selected_folder_num)($a0)
  b     .L7F009B44
   lw    $ra, 0x14($sp)
cheat_unlockegypt:
  lui   $a0, %hi(selected_folder_num)
  jal   check_egypt_completed_in_folder_00
   lw    $a0, %lo(selected_folder_num)($a0)
  b     .L7F009B44
   lw    $ra, 0x14($sp)
def_7F00986C:
.L7F009B38:
  b     .L7F009B38
   nop   
.L7F009B40:
  lw    $ra, 0x14($sp)
.L7F009B44:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

int getplayerfavoredweapon(int player, int hand) {
  return get_ptr_long_watch_text_for_item(array_favweapon[player][hand]);
}

#ifdef VERSION_US
asm(R"
.late_rodata
/*HACK FIXME*/
/*from above to add bytes till fixed*/
.word default_nonmenucheats
.word default_nonmenucheats
.word default_nonmenucheats
.word default_nonmenucheats
.word default_nonmenucheats
.word default_nonmenucheats
.word default_nonmenucheats
.word default_nonmenucheats
.word default_nonmenucheats
.word default_nonmenucheats
/*end from above to add bytes till fixed*/

glabel folder_menu_x_dim
.word 0x3D99999A /* 0.075000003;*/
glabel folder_menu_z_dim
.word 0x3D99999A /* 0.075000003;*/
glabel D_800519D0
.word 0x3D99999A /* 0.075000003;*/
glabel D_800519D4
.word 0x3D99999A /* 0.075000003;*/
glabel tab1_max_x_coord
.word 0x43028000 /* 130.5;*/
glabel tab2_first_x_coord
.word 0x43C78000 /* 399.0;*/
glabel tab2_bottom_y_coord
.word 0x43028000 /* 130.5;*/
glabel D_800519E4
.word 0x3FAAAAAB /* 1.3333334;*/
glabel D_800519E8
.word 0x461C4000 /* 10000.0;*/
glabel D_800519EC
.word 0x3FAAAAAB /* 1.3333334;*/
glabel D_800519F0
.word 0x461C4000 /* 10000.0;*/
glabel D_800519F4
.word 0xBFB2B8C3 /* -1.3962635;*/
glabel D_800519F8
.word 0x3C962FC9 /* 0.018333333;*/
glabel menu01_aspect
.word 0x3FAAAAAB /* 1.3333334;*/
glabel menu01_pageheight
.word 0x461C4000 /* 10000.0;*/
glabel D_80051A04
.word 0x3C8EFA35 /* 0.017453292;*/
glabel D_80051A08
.word 0x3F8CCCCD /* 1.1;*/
glabel D_80051A0C
.word 0x3F8A35E7 /* 1.07977;*/
glabel D_80051A10
.word 0x3FAAAAAB /* 1.3333334;*/
glabel D_80051A14
.word 0x461C4000 /* 10000.0;*/
glabel D_80051A18
.word 0x3F99999A /* 1.2;*/
glabel D_80051A1C
.word 0x3FAAAAAB /* 1.3333334;*/
glabel D_80051A20
.word 0x461C4000 /* 10000.0;*/
glabel D_80051A24
.word 0x3EBD70A4 /* 0.37;*/
glabel D_80051A28
.word 0x438E8000 /* 285.0;*/
glabel D_80051A2C
.word 0x43A78000 /* 335.0;*/
glabel D_80051A30
.word 0x438E8000 /* 285.0;*/
glabel D_80051A34
.word 0x438E8000 /* 285.0;*/
glabel D_80051A38
.word 0x3FAAAAAB /* 1.3333334;*/
glabel D_80051A3C
.word 0x461C4000 /* 10000.0;*/
glabel D_80051A40
.word 0x43898000 /* 275.0;*/
glabel D_80051A44
.word 0x3FAAAAAB /* 1.3333334;*/
glabel D_80051A48
.word 0x461C4000 /* 10000.0;*/
glabel D_80051A4C
.word 0x3FAAAAAB /* 1.3333334;*/
glabel D_80051A50
.word 0x461C4000 /* 10000.0;*/
glabel D_80051A54
.word 0x43898000 /* 275.0;*/
glabel D_80051A58
.word 0x3FAAAAAB /* 1.3333334;*/
glabel D_80051A5C
.word 0x461C4000 /* 10000.0;*/
.text
glabel menu_control_stick_tracking
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  jal   get_cur_controller_horz_stick_pos
   move  $a0, $zero
  move  $a0, $zero
  jal   get_cur_controller_vert_stick_pos
   sb    $v0, 0x1f($sp)
  lb    $a1, 0x1f($sp)
  negu  $v1, $v0
  sll   $t1, $v1, 0x18
  slti  $at, $a1, -5
  beqz  $at, .L7F009BC8
   sra   $t2, $t1, 0x18
  addiu $a1, $a1, 5
  sll   $t7, $a1, 0x18
  b     .L7F009BE4
   sra   $a1, $t7, 0x18
.L7F009BC8:
  slti  $at, $a1, 6
  bnez  $at, .L7F009BE0
   addiu $a1, $a1, -5
  sll   $t9, $a1, 0x18
  b     .L7F009BE4
   sra   $a1, $t9, 0x18
.L7F009BE0:
  move  $a1, $zero
.L7F009BE4:
  slti  $at, $a1, 0x47
  bnezl $at, .L7F009BFC
   slti  $at, $a1, -0x46
  b     .L7F009C08
   li    $a1, 70
  slti  $at, $a1, -0x46
.L7F009BFC:
  beql  $at, $zero, .L7F009C0C
   slti  $at, $t2, -5
  li    $a1, -70
.L7F009C08:
  slti  $at, $t2, -5
.L7F009C0C:
  beqz  $at, .L7F009C24
   move  $v1, $t2
  addiu $v0, $t2, 5
  sll   $t3, $v0, 0x18
  b     .L7F009C40
   sra   $v0, $t3, 0x18
.L7F009C24:
  slti  $at, $v1, 6
  bnez  $at, .L7F009C40
   move  $v0, $zero
  addiu $v0, $v1, -5
  sll   $t5, $v0, 0x18
  b     .L7F009C40
   sra   $v0, $t5, 0x18
.L7F009C40:
  slti  $at, $v0, 0x47
  bnezl $at, .L7F009C58
   slti  $at, $v0, -0x46
  b     .L7F009C64
   li    $v0, 70
  slti  $at, $v0, -0x46
.L7F009C58:
  beqz  $at, .L7F009C64
   nop   
  li    $v0, -70
.L7F009C64:
  blez  $a1, .L7F009CAC
   nop   
  mtc1  $a1, $f4
  lui   $at, %hi(folder_menu_x_dim)
  lwc1  $f8, %lo(folder_menu_x_dim)($at)
  cvt.s.w $f6, $f4
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f16
  lui   $at, %hi(global_timer_delta)
  lwc1  $f4, %lo(global_timer_delta)($at)
  lui   $at, %hi(cursor_h_pos)
  mul.s $f10, $f6, $f8
  lwc1  $f8, %lo(cursor_h_pos)($at)
  add.s $f18, $f10, $f16
  mul.s $f6, $f18, $f4
  add.s $f10, $f8, $f6
  b     .L7F009CF0
   swc1  $f10, %lo(cursor_h_pos)($at)
.L7F009CAC:
  bgez  $a1, .L7F009CF0
   nop   
  mtc1  $a1, $f16
  lui   $at, %hi(folder_menu_z_dim)
  lwc1  $f4, %lo(folder_menu_z_dim)($at)
  cvt.s.w $f18, $f16
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f6
  lui   $at, %hi(global_timer_delta)
  lwc1  $f16, %lo(global_timer_delta)($at)
  lui   $at, %hi(cursor_h_pos)
  mul.s $f8, $f18, $f4
  lwc1  $f4, %lo(cursor_h_pos)($at)
  sub.s $f10, $f8, $f6
  mul.s $f18, $f10, $f16
  add.s $f8, $f4, $f18
  swc1  $f8, %lo(cursor_h_pos)($at)
.L7F009CF0:
  jal   getPlayer_c_screenleft
   sb    $v0, 0x1e($sp)
  jal   getPlayer_c_screenwidth
   swc1  $f0, 0x18($sp)
  lwc1  $f6, 0x18($sp)
  li    $at, 0x41A00000 # 20.000000
  mtc1  $at, $f16
  add.s $f10, $f0, $f6
  lui   $at, %hi(cursor_h_pos)
  lwc1  $f18, %lo(cursor_h_pos)($at)
  lb    $v0, 0x1e($sp)
  sub.s $f4, $f10, $f16
  c.lt.s $f4, $f18
  nop   
  bc1f  .L7F009D64
   nop   
  jal   getPlayer_c_screenleft
   sb    $v0, 0x1e($sp)
  jal   getPlayer_c_screenwidth
   swc1  $f0, 0x18($sp)
  lwc1  $f8, 0x18($sp)
  li    $at, 0x41A00000 # 20.000000
  mtc1  $at, $f10
  add.s $f6, $f0, $f8
  lui   $at, %hi(cursor_h_pos)
  lb    $v0, 0x1e($sp)
  sub.s $f16, $f6, $f10
  b     .L7F009DB4
   swc1  $f16, %lo(cursor_h_pos)($at)
.L7F009D64:
  jal   getPlayer_c_screenleft
   sb    $v0, 0x1e($sp)
  lui   $at, %hi(cursor_h_pos)
  lwc1  $f4, %lo(cursor_h_pos)($at)
  li    $at, 0x41A00000 # 20.000000
  mtc1  $at, $f18
  lb    $v0, 0x1e($sp)
  add.s $f8, $f0, $f18
  c.lt.s $f4, $f8
  nop   
  bc1f  .L7F009DB4
   nop   
  jal   getPlayer_c_screenleft
   sb    $v0, 0x1e($sp)
  li    $at, 0x41A00000 # 20.000000
  mtc1  $at, $f6
  lui   $at, %hi(cursor_h_pos)
  lb    $v0, 0x1e($sp)
  add.s $f10, $f0, $f6
  swc1  $f10, %lo(cursor_h_pos)($at)
.L7F009DB4:
  blez  $v0, .L7F009DFC
   nop   
  mtc1  $v0, $f16
  lui   $at, %hi(D_800519D0)
  lwc1  $f4, %lo(D_800519D0)($at)
  cvt.s.w $f18, $f16
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f6
  lui   $at, %hi(global_timer_delta)
  lwc1  $f16, %lo(global_timer_delta)($at)
  lui   $at, %hi(cursor_v_pos)
  mul.s $f8, $f18, $f4
  lwc1  $f4, %lo(cursor_v_pos)($at)
  add.s $f10, $f8, $f6
  mul.s $f18, $f10, $f16
  add.s $f8, $f4, $f18
  b     .L7F009E40
   swc1  $f8, %lo(cursor_v_pos)($at)
.L7F009DFC:
  bgez  $v0, .L7F009E40
   nop   
  mtc1  $v0, $f6
  lui   $at, %hi(D_800519D4)
  lwc1  $f16, %lo(D_800519D4)($at)
  cvt.s.w $f10, $f6
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f18
  lui   $at, %hi(global_timer_delta)
  lwc1  $f6, %lo(global_timer_delta)($at)
  lui   $at, %hi(cursor_v_pos)
  mul.s $f4, $f10, $f16
  lwc1  $f16, %lo(cursor_v_pos)($at)
  sub.s $f8, $f4, $f18
  mul.s $f10, $f8, $f6
  add.s $f4, $f16, $f10
  swc1  $f4, %lo(cursor_v_pos)($at)
.L7F009E40:
  jal   getPlayer_c_screentop
   nop   
  jal   getPlayer_c_screenheight
   swc1  $f0, 0x18($sp)
  lwc1  $f18, 0x18($sp)
  li    $at, 0x41A00000 # 20.000000
  mtc1  $at, $f6
  add.s $f8, $f0, $f18
  lui   $at, %hi(cursor_v_pos)
  lwc1  $f10, %lo(cursor_v_pos)($at)
  sub.s $f16, $f8, $f6
  c.lt.s $f16, $f10
  nop   
  bc1f  .L7F009EAC
   nop   
  jal   getPlayer_c_screentop
   nop   
  jal   getPlayer_c_screenheight
   swc1  $f0, 0x18($sp)
  lwc1  $f4, 0x18($sp)
  li    $at, 0x41A00000 # 20.000000
  mtc1  $at, $f8
  add.s $f18, $f0, $f4
  lui   $at, %hi(cursor_v_pos)
  sub.s $f6, $f18, $f8
  b     .L7F009EF8
   swc1  $f6, %lo(cursor_v_pos)($at)
.L7F009EAC:
  jal   getPlayer_c_screentop
   nop   
  lui   $at, %hi(cursor_v_pos)
  lwc1  $f16, %lo(cursor_v_pos)($at)
  li    $at, 0x41A00000 # 20.000000
  mtc1  $at, $f10
  nop   
  add.s $f4, $f0, $f10
  c.lt.s $f16, $f4
  nop   
  bc1fl .L7F009EFC
   lw    $ra, 0x14($sp)
  jal   getPlayer_c_screentop
   nop   
  li    $at, 0x41A00000 # 20.000000
  mtc1  $at, $f18
  lui   $at, %hi(cursor_v_pos)
  add.s $f8, $f0, $f18
  swc1  $f8, %lo(cursor_v_pos)($at)
.L7F009EF8:
  lw    $ra, 0x14($sp)
.L7F009EFC:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");
#endif
#ifdef VERSION_JP
asm(R"
.late_rodata
/*HACK FIXME*/
/*from above to add bytes till fixed*/
.word default_nonmenucheats
.word default_nonmenucheats
.word default_nonmenucheats
.word default_nonmenucheats
.word default_nonmenucheats
.word default_nonmenucheats
.word default_nonmenucheats
.word default_nonmenucheats
.word default_nonmenucheats
.word default_nonmenucheats
/*end from above to add bytes till fixed*/

glabel folder_menu_x_dim
.word 0x3D99999A /* 0.075000003;*/
glabel folder_menu_z_dim
.word 0x3D99999A /* 0.075000003;*/
glabel D_800519D0
.word 0x3D99999A /* 0.075000003;*/
glabel D_800519D4
.word 0x3D99999A /* 0.075000003;*/
glabel tab1_max_x_coord
.word 0x43028000 /* 130.5;*/
glabel tab2_first_x_coord
.word 0x43C78000 /* 399.0;*/
glabel tab2_bottom_y_coord
.word 0x43028000 /* 130.5;*/
glabel D_800519E4
.word 0x3FAAAAAB /* 1.3333334;*/
glabel D_800519E8
.word 0x461C4000 /* 10000.0;*/
glabel D_800519EC
.word 0x3FAAAAAB /* 1.3333334;*/
glabel D_800519F0
.word 0x461C4000 /* 10000.0;*/
glabel D_800519F4
.word 0xBFB2B8C3 /* -1.3962635;*/
glabel D_800519F8
.word 0x3C962FC9 /* 0.018333333;*/
glabel menu01_aspect
.word 0x3FAAAAAB /* 1.3333334;*/
glabel menu01_pageheight
.word 0x461C4000 /* 10000.0;*/
glabel D_80051A04
.word 0x3C8EFA35 /* 0.017453292;*/
glabel D_80051A08
.word 0x3F8CCCCD /* 1.1;*/
glabel D_80051A0C
.word 0x3F8A35E7 /* 1.07977;*/
glabel D_80051A10
.word 0x3FAAAAAB /* 1.3333334;*/
glabel D_80051A14
.word 0x461C4000 /* 10000.0;*/
glabel D_80051A18
.word 0x3F99999A /* 1.2;*/
glabel D_80051A1C
.word 0x3FAAAAAB /* 1.3333334;*/
glabel D_80051A20
.word 0x461C4000 /* 10000.0;*/
glabel D_80051A24
.word 0x3EBD70A4 /* 0.37;*/
glabel D_80051A28
.word 0x438E8000 /* 285.0;*/
glabel D_80051A2C
.word 0x43A78000 /* 335.0;*/
glabel D_80051A30
.word 0x438E8000 /* 285.0;*/
glabel D_80051A34
.word 0x438E8000 /* 285.0;*/
glabel D_80051A38
.word 0x3FAAAAAB /* 1.3333334;*/
glabel D_80051A3C
.word 0x461C4000 /* 10000.0;*/
glabel D_80051A40
.word 0x43898000 /* 275.0;*/
glabel D_80051A44
.word 0x3FAAAAAB /* 1.3333334;*/
glabel D_80051A48
.word 0x461C4000 /* 10000.0;*/
glabel D_80051A4C
.word 0x3FAAAAAB /* 1.3333334;*/
glabel D_80051A50
.word 0x461C4000 /* 10000.0;*/
glabel D_80051A54
.word 0x43898000 /* 275.0;*/
glabel D_80051A58
.word 0x3FAAAAAB /* 1.3333334;*/
glabel D_80051A5C
.word 0x461C4000 /* 10000.0;*/
.text
glabel menu_control_stick_tracking
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  jal   get_cur_controller_horz_stick_pos
   move  $a0, $zero
  move  $a0, $zero
  jal   get_cur_controller_vert_stick_pos
   sb    $v0, 0x1f($sp)
  lb    $a1, 0x1f($sp)
  negu  $v1, $v0
  sll   $t1, $v1, 0x18
  slti  $at, $a1, -5
  beqz  $at, .L7F009BE8
   sra   $t2, $t1, 0x18
  addiu $a1, $a1, 5
  sll   $t7, $a1, 0x18
  b     .L7F009C04
   sra   $a1, $t7, 0x18
.L7F009BE8:
  slti  $at, $a1, 6
  bnez  $at, .L7F009C00
   addiu $a1, $a1, -5
  sll   $t9, $a1, 0x18
  b     .L7F009C04
   sra   $a1, $t9, 0x18
.L7F009C00:
  move  $a1, $zero
.L7F009C04:
  slti  $at, $a1, 0x47
  bnezl $at, .L7F009C1C
   slti  $at, $a1, -0x46
  b     .L7F009C28
   li    $a1, 70
  slti  $at, $a1, -0x46
.L7F009C1C:
  beql  $at, $zero, .L7F009C2C
   slti  $at, $t2, -5
  li    $a1, -70
.L7F009C28:
  slti  $at, $t2, -5
.L7F009C2C:
  beqz  $at, .L7F009C44
   move  $v1, $t2
  addiu $v0, $t2, 5
  sll   $t3, $v0, 0x18
  b     .L7F009C60
   sra   $v0, $t3, 0x18
.L7F009C44:
  slti  $at, $v1, 6
  bnez  $at, .L7F009C60
   move  $v0, $zero
  addiu $v0, $v1, -5
  sll   $t5, $v0, 0x18
  b     .L7F009C60
   sra   $v0, $t5, 0x18
.L7F009C60:
  slti  $at, $v0, 0x47
  bnezl $at, .L7F009C78
   slti  $at, $v0, -0x46
  b     .L7F009C84
   li    $v0, 70
  slti  $at, $v0, -0x46
.L7F009C78:
  beqz  $at, .L7F009C84
   nop   
  li    $v0, -70
.L7F009C84:
  blez  $a1, .L7F009CCC
   nop   
  mtc1  $a1, $f4
  lui   $at, %hi(folder_menu_x_dim) # $at, 0x8005
  lwc1  $f8, %lo(folder_menu_x_dim)($at)
  cvt.s.w $f6, $f4
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f16
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  lwc1  $f4, %lo(global_timer_delta)($at)
  lui   $at, %hi(cursor_h_pos) # $at, 0x8003
  mul.s $f10, $f6, $f8
  lwc1  $f8, %lo(cursor_h_pos)($at)
  add.s $f18, $f10, $f16
  mul.s $f6, $f18, $f4
  add.s $f10, $f8, $f6
  b     .L7F009D10
   swc1  $f10, %lo(cursor_h_pos)($at)
.L7F009CCC:
  bgez  $a1, .L7F009D10
   nop   
  mtc1  $a1, $f16
  lui   $at, %hi(folder_menu_z_dim) # $at, 0x8005
  lwc1  $f4, %lo(folder_menu_z_dim)($at)
  cvt.s.w $f18, $f16
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f6
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  lwc1  $f16, %lo(global_timer_delta)($at)
  lui   $at, %hi(cursor_h_pos) # $at, 0x8003
  mul.s $f8, $f18, $f4
  lwc1  $f4, %lo(cursor_h_pos)($at)
  sub.s $f10, $f8, $f6
  mul.s $f18, $f10, $f16
  add.s $f8, $f4, $f18
  swc1  $f8, %lo(cursor_h_pos)($at)
.L7F009D10:
  jal   getPlayer_c_screenleft
   sb    $v0, 0x1e($sp)
  jal   getPlayer_c_screenwidth
   swc1  $f0, 0x18($sp)
  lwc1  $f6, 0x18($sp)
  li    $at, 0x41A00000 # 20.000000
  mtc1  $at, $f16
  add.s $f10, $f0, $f6
  lui   $at, %hi(cursor_h_pos) # $at, 0x8003
  lwc1  $f18, %lo(cursor_h_pos)($at)
  lb    $v0, 0x1e($sp)
  sub.s $f4, $f10, $f16
  c.lt.s $f4, $f18
  nop   
  bc1f  .L7F009D84
   nop   
  jal   getPlayer_c_screenleft
   sb    $v0, 0x1e($sp)
  jal   getPlayer_c_screenwidth
   swc1  $f0, 0x18($sp)
  lwc1  $f8, 0x18($sp)
  li    $at, 0x41A00000 # 20.000000
  mtc1  $at, $f10
  add.s $f6, $f0, $f8
  lui   $at, %hi(cursor_h_pos) # $at, 0x8003
  lb    $v0, 0x1e($sp)
  sub.s $f16, $f6, $f10
  b     .L7F009DD4
   swc1  $f16, %lo(cursor_h_pos)($at)
.L7F009D84:
  jal   getPlayer_c_screenleft
   sb    $v0, 0x1e($sp)
  lui   $at, %hi(cursor_h_pos) # $at, 0x8003
  lwc1  $f4, %lo(cursor_h_pos)($at)
  li    $at, 0x41A00000 # 20.000000
  mtc1  $at, $f18
  lb    $v0, 0x1e($sp)
  add.s $f8, $f0, $f18
  c.lt.s $f4, $f8
  nop   
  bc1f  .L7F009DD4
   nop   
  jal   getPlayer_c_screenleft
   sb    $v0, 0x1e($sp)
  li    $at, 0x41A00000 # 20.000000
  mtc1  $at, $f6
  lui   $at, %hi(cursor_h_pos) # $at, 0x8003
  lb    $v0, 0x1e($sp)
  add.s $f10, $f0, $f6
  swc1  $f10, %lo(cursor_h_pos)($at)
.L7F009DD4:
  blez  $v0, .L7F009E1C
   nop   
  mtc1  $v0, $f16
  lui   $at, %hi(D_800519D0) # $at, 0x8005
  lwc1  $f4, %lo(D_800519D0)($at)
  cvt.s.w $f18, $f16
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f6
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  lwc1  $f16, %lo(global_timer_delta)($at)
  lui   $at, %hi(cursor_v_pos) # $at, 0x8003
  mul.s $f8, $f18, $f4
  lwc1  $f4, %lo(cursor_v_pos)($at)
  add.s $f10, $f8, $f6
  mul.s $f18, $f10, $f16
  add.s $f8, $f4, $f18
  b     .L7F009E60
   swc1  $f8, %lo(cursor_v_pos)($at)
.L7F009E1C:
  bgez  $v0, .L7F009E60
   nop   
  mtc1  $v0, $f6
  lui   $at, %hi(D_800519D4) # $at, 0x8005
  lwc1  $f16, %lo(D_800519D4)($at)
  cvt.s.w $f10, $f6
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f18
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  lwc1  $f6, %lo(global_timer_delta)($at)
  lui   $at, %hi(cursor_v_pos) # $at, 0x8003
  mul.s $f4, $f10, $f16
  lwc1  $f16, %lo(cursor_v_pos)($at)
  sub.s $f8, $f4, $f18
  mul.s $f10, $f8, $f6
  add.s $f4, $f16, $f10
  swc1  $f4, %lo(cursor_v_pos)($at)
.L7F009E60:
  jal   getPlayer_c_screentop
   nop   
  jal   getPlayer_c_screenheight
   swc1  $f0, 0x18($sp)
  lwc1  $f18, 0x18($sp)
  li    $at, 0x41A00000 # 20.000000
  mtc1  $at, $f6
  add.s $f8, $f0, $f18
  lui   $at, %hi(cursor_v_pos) # $at, 0x8003
  lwc1  $f10, %lo(cursor_v_pos)($at)
  sub.s $f16, $f8, $f6
  c.lt.s $f16, $f10
  nop   
  bc1f  .L7F009ECC
   nop   
  jal   getPlayer_c_screentop
   nop   
  jal   getPlayer_c_screenheight
   swc1  $f0, 0x18($sp)
  lwc1  $f4, 0x18($sp)
  li    $at, 0x41A00000 # 20.000000
  mtc1  $at, $f8
  add.s $f18, $f0, $f4
  lui   $at, %hi(cursor_v_pos) # $at, 0x8003
  sub.s $f6, $f18, $f8
  b     .L7F009F18
   swc1  $f6, %lo(cursor_v_pos)($at)
.L7F009ECC:
  jal   getPlayer_c_screentop
   nop   
  lui   $at, %hi(cursor_v_pos) # $at, 0x8003
  lwc1  $f16, %lo(cursor_v_pos)($at)
  li    $at, 0x41A00000 # 20.000000
  mtc1  $at, $f10
  nop   
  add.s $f4, $f0, $f10
  c.lt.s $f16, $f4
  nop   
  bc1fl .L7F009F1C
   lw    $ra, 0x14($sp)
  jal   getPlayer_c_screentop
   nop   
  li    $at, 0x41A00000 # 20.000000
  mtc1  $at, $f18
  lui   $at, %hi(cursor_v_pos) # $at, 0x8003
  add.s $f8, $f0, $f18
  swc1  $f8, %lo(cursor_v_pos)($at)
.L7F009F18:
  lw    $ra, 0x14($sp)
.L7F009F1C:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");
#endif

asm(R"
glabel load_draw_selected_icon_folder_select
  lui   $v0, %hi(folder_selection_screen_option_icon)
  lw    $v0, %lo(folder_selection_screen_option_icon)($v0)
  addiu $sp, $sp, -0x68
  sw    $ra, 0x44($sp)
  sw    $s0, 0x40($sp)
  bnez  $v0, .L7F009F34
   sw    $a0, 0x68($sp)
  lui   $s0, %hi(crosshairimage)
  lw    $s0, %lo(crosshairimage)($s0)
  b     .L7F009F64
   sw    $s0, 0x54($sp)
.L7F009F34:
  li    $at, 1
  bne   $v0, $at, .L7F009F4C
   lui   $s0, %hi(mainfolderimages)
  lw    $s0, %lo(mainfolderimages)($s0)
  b     .L7F009F64
   sw    $s0, 0x54($sp)
.L7F009F4C:
  li    $at, 2
  bne   $v0, $at, .L7F009F64
   lui   $s0, %hi(mainfolderimages)
  lw    $s0, %lo(mainfolderimages)($s0)
  addiu $s0, $s0, 0xc
  sw    $s0, 0x54($sp)
.L7F009F64:
  lw    $s0, 0x54($sp)
  addiu $a0, $sp, 0x68
  li    $a2, 4
  move  $a3, $zero
  sw    $zero, 0x10($sp)
  jal   likely_generate_DL_for_image_declaration
   move  $a1, $s0
  lui   $at, %hi(cursor_h_pos)
  lwc1  $f4, %lo(cursor_h_pos)($at)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f6
  jal   truncf
   add.s $f12, $f4, $f6
  lui   $at, %hi(cursor_v_pos)
  lwc1  $f8, %lo(cursor_v_pos)($at)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f10
  swc1  $f0, 0x60($sp)
  jal   truncf
   add.s $f12, $f8, $f10
  swc1  $f0, 0x64($sp)
  lbu   $t6, 4($s0)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f2
  mtc1  $t6, $f16
  addiu $a0, $sp, 0x68
  bgez  $t6, .L7F009FE4
   cvt.s.w $f18, $f16
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f4
  nop   
  add.s $f18, $f18, $f4
.L7F009FE4:
  mul.s $f6, $f18, $f2
  li    $at, 0x4F800000 # 4294967296.000000
  swc1  $f6, 0x58($sp)
  lbu   $t7, 5($s0)
  mtc1  $t7, $f8
  bgez  $t7, .L7F00A00C
   cvt.s.w $f10, $f8
  mtc1  $at, $f16
  nop   
  add.s $f10, $f10, $f16
.L7F00A00C:
  mul.s $f4, $f10, $f2
  li    $t9, 1
  li    $t0, 255
  li    $t1, 255
  li    $t2, 255
  li    $t3, 220
  addiu $a1, $sp, 0x60
  swc1  $f4, 0x5c($sp)
  lbu   $t8, 5($s0)
  lbu   $a3, 4($s0)
  sw    $t3, 0x2c($sp)
  sw    $t2, 0x28($sp)
  sw    $t1, 0x24($sp)
  sw    $t0, 0x20($sp)
  sw    $t9, 0x1c($sp)
  sw    $zero, 0x18($sp)
  sw    $zero, 0x14($sp)
  sw    $t8, 0x10($sp)
  lbu   $t4, 6($s0)
  sw    $zero, 0x34($sp)
  addiu $a2, $sp, 0x58
  slt   $t5, $zero, $t4
  jal   display_image_at_on_screen_coord
   sw    $t5, 0x30($sp)
  lw    $ra, 0x44($sp)
  lw    $v0, 0x68($sp)
  lw    $s0, 0x40($sp)
  jr    $ra
   addiu $sp, $sp, 0x68
");

asm(R"
glabel add_tab1_start
  addiu $sp, $sp, -0x58
  sw    $s0, 0x38($sp)
  move  $s0, $a0
  sw    $ra, 0x3c($sp)
  jal   get_textptr_for_textID
   li    $a0, 39940
  lui   $at, %hi(dword_CODE_bss_80069770)
  sw    $v0, %lo(dword_CODE_bss_80069770)($at)
  jal   setTextSpacingInverted
   li    $a0, 1
  lui   $t6, %hi(ptrFirstFontTableSmall) 
  lw    $t6, %lo(ptrFirstFontTableSmall)($t6)
  lui   $a2, %hi(dword_CODE_bss_80069770)
  lui   $a3, %hi(ptrSecondFontTableSmall)
  sw    $zero, 0x48($sp)
  sw    $zero, 0x4c($sp)
  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
  lw    $a2, %lo(dword_CODE_bss_80069770)($a2)
  addiu $a0, $sp, 0x4c
  addiu $a1, $sp, 0x48
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t6, 0x10($sp)
  lw    $t8, 0x4c($sp)
  lui   $t1, %hi(tab_1_highlight) 
  lw    $t1, %lo(tab_1_highlight)($t1)
  li    $t0, 411
  li    $t7, 51
  sw    $t7, 0x54($sp)
  bgez  $t8, .L7F00A104
   sra   $t9, $t8, 1
  addiu $at, $t8, 1
  sra   $t9, $at, 1
.L7F00A104:
  subu  $a3, $t0, $t9
  beqz  $t1, .L7F00A13C
   sw    $a3, 0x50($sp)
  subu  $a1, $a3, $t8
  li    $t2, 117
  li    $t3, 50
  sw    $t3, 0x14($sp)
  sw    $t2, 0x10($sp)
  addiu $a1, $a1, 1
  move  $a0, $s0
  li    $a2, 51
  jal   microcode_constructor_related_to_menus
   sw    $a3, 0x50($sp)
  move  $s0, $v0
.L7F00A13C:
  jal   setTextOrientation
   li    $a0, 1
  lw    $t4, 0x48($sp)
  li    $t6, 84
  bgez  $t4, .L7F00A15C
   sra   $t5, $t4, 1
  addiu $at, $t4, 1
  sra   $t5, $at, 1
.L7F00A15C:
  subu  $t7, $t6, $t5
  jal   get_video2_settings_txtClipH
   sw    $t7, 0x54($sp)
  jal   get_video2_settings_txtClipW
   sh    $v0, 0x44($sp)
  lui   $t0, %hi(ptrSecondFontTableSmall) 
  lui   $t9, %hi(ptrFirstFontTableSmall) 
  lw    $t9, %lo(ptrFirstFontTableSmall)($t9)
  lw    $t0, %lo(ptrSecondFontTableSmall)($t0)
  lh    $t8, 0x44($sp)
  lui   $a3, %hi(dword_CODE_bss_80069770)
  li    $t1, 255
  sw    $t1, 0x18($sp)
  lw    $a3, %lo(dword_CODE_bss_80069770)($a3)
  move  $a0, $s0
  addiu $a1, $sp, 0x54
  addiu $a2, $sp, 0x50
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t9, 0x14($sp)
  sw    $t0, 0x10($sp)
  jal   en_text_write_stuff
   sw    $t8, 0x1c($sp)
  move  $s0, $v0
  jal   setTextOrientation
   move  $a0, $zero
  jal   setTextSpacingInverted
   move  $a0, $zero
  lw    $ra, 0x3c($sp)
  move  $v0, $s0
  lw    $s0, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x58
");

unsigned int isontab1(void) {
  if ((390.00000000f < cursor_h_pos) && (cursor_v_pos <= tab1_max_x_coord)) {
    return true;
  }
  return false;
}

asm(R"
glabel add_tab3_previous
  addiu $sp, $sp, -0x58
  sw    $s0, 0x38($sp)
  move  $s0, $a0
  sw    $ra, 0x3c($sp)
  jal   get_textptr_for_textID
   li    $a0, 39942
  lui   $at, %hi(dword_CODE_bss_80069778)
  sw    $v0, %lo(dword_CODE_bss_80069778)($at)
  jal   setTextSpacingInverted
   li    $a0, 1
  lui   $t6, %hi(ptrFirstFontTableSmall) 
  lw    $t6, %lo(ptrFirstFontTableSmall)($t6)
  lui   $a2, %hi(dword_CODE_bss_80069778)
  lui   $a3, %hi(ptrSecondFontTableSmall)
  sw    $zero, 0x48($sp)
  sw    $zero, 0x4c($sp)
  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
  lw    $a2, %lo(dword_CODE_bss_80069778)($a2)
  addiu $a0, $sp, 0x4c
  addiu $a1, $sp, 0x48
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t6, 0x10($sp)
  lw    $t8, 0x4c($sp)
  lui   $t1, %hi(tab_3_highlight) 
  lw    $t1, %lo(tab_3_highlight)($t1)
  li    $t0, 411
  li    $t7, 236
  sw    $t7, 0x54($sp)
  bgez  $t8, .L7F00A2BC
   sra   $t9, $t8, 1
  addiu $at, $t8, 1
  sra   $t9, $at, 1
.L7F00A2BC:
  subu  $a3, $t0, $t9
  beqz  $t1, .L7F00A2F4
   sw    $a3, 0x50($sp)
  subu  $a1, $a3, $t8
  li    $t2, 302
  li    $t3, 50
  sw    $t3, 0x14($sp)
  sw    $t2, 0x10($sp)
  addiu $a1, $a1, 1
  move  $a0, $s0
  li    $a2, 236
  jal   microcode_constructor_related_to_menus
   sw    $a3, 0x50($sp)
  move  $s0, $v0
.L7F00A2F4:
  jal   setTextOrientation
   li    $a0, 1
  lw    $t4, 0x48($sp)
  li    $t6, 269
  bgez  $t4, .L7F00A314
   sra   $t5, $t4, 1
  addiu $at, $t4, 1
  sra   $t5, $at, 1
.L7F00A314:
  subu  $t7, $t6, $t5
  jal   get_video2_settings_txtClipH
   sw    $t7, 0x54($sp)
  jal   get_video2_settings_txtClipW
   sh    $v0, 0x44($sp)
  lui   $t0, %hi(ptrSecondFontTableSmall) 
  lui   $t9, %hi(ptrFirstFontTableSmall) 
  lw    $t9, %lo(ptrFirstFontTableSmall)($t9)
  lw    $t0, %lo(ptrSecondFontTableSmall)($t0)
  lh    $t8, 0x44($sp)
  lui   $a3, %hi(dword_CODE_bss_80069778)
  li    $t1, 255
  sw    $t1, 0x18($sp)
  lw    $a3, %lo(dword_CODE_bss_80069778)($a3)
  move  $a0, $s0
  addiu $a1, $sp, 0x54
  addiu $a2, $sp, 0x50
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t9, 0x14($sp)
  sw    $t0, 0x10($sp)
  jal   en_text_write_stuff
   sw    $t8, 0x1c($sp)
  move  $s0, $v0
  jal   setTextOrientation
   move  $a0, $zero
  jal   setTextSpacingInverted
   move  $a0, $zero
  lw    $ra, 0x3c($sp)
  move  $v0, $s0
  lw    $s0, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x58
");

unsigned int isontab3(void) {
  if ((390.0f < cursor_h_pos) && (223.0f < cursor_v_pos)) {
    return 1;
  } else {
    return 0;
  }
}

void set_cursor_pos_tab2(void) {
  cursor_h_pos = tab2_first_x_coord;
  cursor_v_pos = 144.00000000f;
}

asm(R"
glabel add_tab2_next
  addiu $sp, $sp, -0x58
  sw    $s0, 0x38($sp)
  move  $s0, $a0
  sw    $ra, 0x3c($sp)
  jal   get_textptr_for_textID
   li    $a0, 39941
  lui   $at, %hi(dword_CODE_bss_80069774)
  sw    $v0, %lo(dword_CODE_bss_80069774)($at)
  jal   setTextSpacingInverted
   li    $a0, 1
  lui   $t6, %hi(ptrFirstFontTableSmall) 
  lw    $t6, %lo(ptrFirstFontTableSmall)($t6)
  lui   $a2, %hi(dword_CODE_bss_80069774)
  lui   $a3, %hi(ptrSecondFontTableSmall)
  sw    $zero, 0x48($sp)
  sw    $zero, 0x4c($sp)
  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
  lw    $a2, %lo(dword_CODE_bss_80069774)($a2)
  addiu $a0, $sp, 0x4c
  addiu $a1, $sp, 0x48
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t6, 0x10($sp)
  lw    $t8, 0x4c($sp)
  lui   $t1, %hi(tab_2_highlight) 
  lw    $t1, %lo(tab_2_highlight)($t1)
  li    $t0, 411
  li    $t7, 144
  sw    $t7, 0x54($sp)
  bgez  $t8, .L7F00A498
   sra   $t9, $t8, 1
  addiu $at, $t8, 1
  sra   $t9, $at, 1
.L7F00A498:
  subu  $a3, $t0, $t9
  beqz  $t1, .L7F00A4D0
   sw    $a3, 0x50($sp)
  subu  $a1, $a3, $t8
  li    $t2, 210
  li    $t3, 50
  sw    $t3, 0x14($sp)
  sw    $t2, 0x10($sp)
  addiu $a1, $a1, 1
  move  $a0, $s0
  li    $a2, 144
  jal   microcode_constructor_related_to_menus
   sw    $a3, 0x50($sp)
  move  $s0, $v0
.L7F00A4D0:
  jal   setTextOrientation
   li    $a0, 1
  lw    $t4, 0x48($sp)
  li    $t6, 177
  bgez  $t4, .L7F00A4F0
   sra   $t5, $t4, 1
  addiu $at, $t4, 1
  sra   $t5, $at, 1
.L7F00A4F0:
  subu  $t7, $t6, $t5
  jal   get_video2_settings_txtClipH
   sw    $t7, 0x54($sp)
  jal   get_video2_settings_txtClipW
   sh    $v0, 0x44($sp)
  lui   $t0, %hi(ptrSecondFontTableSmall) 
  lui   $t9, %hi(ptrFirstFontTableSmall) 
  lw    $t9, %lo(ptrFirstFontTableSmall)($t9)
  lw    $t0, %lo(ptrSecondFontTableSmall)($t0)
  lh    $t8, 0x44($sp)
  lui   $a3, %hi(dword_CODE_bss_80069774)
  li    $t1, 255
  sw    $t1, 0x18($sp)
  lw    $a3, %lo(dword_CODE_bss_80069774)($a3)
  move  $a0, $s0
  addiu $a1, $sp, 0x54
  addiu $a2, $sp, 0x50
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t9, 0x14($sp)
  sw    $t0, 0x10($sp)
  jal   en_text_write_stuff
   sw    $t8, 0x1c($sp)
  move  $s0, $v0
  jal   setTextOrientation
   move  $a0, $zero
  jal   setTextSpacingInverted
   move  $a0, $zero
  lw    $ra, 0x3c($sp)
  move  $v0, $s0
  lw    $s0, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x58
");

unsigned int isontab2(void) {
  if (((390.00000000f < cursor_h_pos) &&
       (tab2_bottom_y_coord < cursor_v_pos)) &&
      (cursor_v_pos <= 223.00000000f)) {
    return true;
  }
  return false;
}

asm(R"
glabel init_menu00_legalscreen
  addiu $sp, $sp, -0x30
  sw    $ra, 0x1c($sp)
  jal   musicTrack1Stop
   nop   
  li    $t6, 1
  lui   $at, %hi(maybe_is_in_menu)
  sw    $t6, %lo(maybe_is_in_menu)($at)
  lui   $at, %hi(menu_timer)
  lui   $t8, %hi(D_8002A9C0) 
  sw    $zero, %lo(menu_timer)($at)
  addiu $t8, %lo(D_8002A9C0) # addiu $t8, $t8, -0x5640
  lw    $at, ($t8)
  addiu $t7, $sp, 0x20
  lw    $t1, 4($t8)
  sw    $at, ($t7)
  lw    $at, 8($t8)
  sw    $t1, 4($t7)
  lui   $v0, %hi(PitemZ_entries)
  sw    $at, 8($t7)
  addiu $v0, %lo(PitemZ_entries) # addiu $v0, $v0, -0x5dd8
  lui   $a2, %hi(ptr_logo_and_walletbond_DL)
  lui   $a3, (0x0003C000 >> 16) # lui $a3, 3
  ori   $a3, (0x0003C000 & 0xFFFF) # ori $a3, $a3, 0xc000
  lw    $a2, %lo(ptr_logo_and_walletbond_DL)($a2)
  lw    $a0, 0xef4($v0)
  lw    $a1, 0xef8($v0)
  jal   load_object_fill_header
   sw    $zero, 0x10($sp)
  lui   $a0, %hi(PitemZ_entries+0xEF4)
  jal   set_objuse_flag_compute_grp_nums_set_obj_loaded
   lw    $a0, %lo(PitemZ_entries+0xEF4)($a0)
  lui   $a0, %hi(PitemZ_entries+0xEF4)
  jal   get_obj_instance_controller_for_header
   lw    $a0, %lo(PitemZ_entries+0xEF4)($a0)
  lui   $v1, %hi(something_legalscreen_constructor)
  addiu $v1, %lo(something_legalscreen_constructor) # addiu $v1, $v1, -0x56a8
  sw    $v0, ($v1)
  move  $a0, $v0
  jal   set_obj_instance_controller_scale
   lui   $a1, 0x3f80
  lui   $a0, %hi(something_legalscreen_constructor)
  lw    $a0, %lo(something_legalscreen_constructor)($a0)
  jal   setsuboffset
   addiu $a1, $sp, 0x20
  jal   sub_GAME_7F01DF90
   nop   
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

void update_menu00_legalscreen(void) {
  is_first_time_on_legal_screen = false;
  set_obj_instance_scale_to_zero(something_legalscreen_constructor);
}

asm(R"
glabel interface_menu00_legalscreen
  addiu $sp, $sp, -0x18
  li    $at, 0x42700000 # 60.000000
  sw    $ra, 0x14($sp)
  mtc1  $at, $f12
  jal   setvideo_far
   nop   
  lui   $at, %hi(D_800519E4)
  jal   video_related_21
   lwc1  $f12, %lo(D_800519E4)($at)
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f12
  lui   $at, %hi(D_800519E8)
  jal   set_page_height
   lwc1  $f14, %lo(D_800519E8)($at)
  jal   set_video2_settings_offset_24
   move  $a0, $zero
  lui   $v0, %hi(menu_timer)
  addiu $v0, %lo(menu_timer) # addiu $v0, $v0, -0x5734
  lui   $t7, %hi(clock_timer) 
  lw    $t7, %lo(clock_timer)($t7)
  lw    $t6, ($v0)
  move  $a0, $zero
  addu  $t8, $t6, $t7
  slti  $at, $t8, 0xf1
  bnez  $at, .L7F00A788
   sw    $t8, ($v0)
  jal   get_attached_controller_count
   nop   
  bgtz  $v0, .L7F00A774
   lui   $t0, %hi(is_first_time_on_legal_screen) 
  lw    $t0, %lo(is_first_time_on_legal_screen)($t0)
  li    $a0, 22
  beql  $t0, $zero, .L7F00A778
   li    $a0, 1
  jal   set_menu_to_mode
   li    $a1, 1
  b     .L7F00A7D8
   lw    $ra, 0x14($sp)
.L7F00A774:
  li    $a0, 1
.L7F00A778:
  jal   set_menu_to_mode
   li    $a1, 1
  b     .L7F00A7D8
   lw    $ra, 0x14($sp)
.L7F00A788:
  jal   get_controller_buttons_pressed
   li    $a1, 65535
  beqz  $v0, .L7F00A7D4
   lui   $t1, %hi(is_first_time_on_legal_screen) 
  lw    $t1, %lo(is_first_time_on_legal_screen)($t1)
  lui   $t2, %hi(is_first_time_on_main_menu) 
  bnezl $t1, .L7F00A7D8
   lw    $ra, 0x14($sp)
  lw    $t2, %lo(is_first_time_on_main_menu)($t2)
  li    $a1, 1
  li    $a0, 1
  bnez  $t2, .L7F00A7CC
   nop   
  jal   set_menu_to_mode
   li    $a0, 5
  b     .L7F00A7D8
   lw    $ra, 0x14($sp)
.L7F00A7CC:
  jal   set_menu_to_mode
   li    $a1, 1
.L7F00A7D4:
  lw    $ra, 0x14($sp)
.L7F00A7D8:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel display_aligned_white_text_to_screen
  addiu $sp, $sp, -0x50
  lui   $t6, %hi(ptrFirstFontTableLarge) 
  lw    $t6, %lo(ptrFirstFontTableLarge)($t6)
  sw    $a3, 0x5c($sp)
  sw    $ra, 0x34($sp)
  sw    $a0, 0x50($sp)
  sw    $a1, 0x54($sp)
  sw    $a2, 0x58($sp)
  lui   $a3, %hi(ptrSecondFontTableLarge)
  sw    $zero, 0x48($sp)
  sw    $zero, 0x4c($sp)
  lw    $a3, %lo(ptrSecondFontTableLarge)($a3)
  lw    $a2, 0x64($sp)
  addiu $a1, $sp, 0x48
  addiu $a0, $sp, 0x4c
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t6, 0x10($sp)
  lw    $t7, 0x5c($sp)
  lw    $t8, 0x48($sp)
  lw    $t3, 0x60($sp)
  lw    $t4, 0x4c($sp)
  multu $t7, $t8
  lw    $t1, 0x54($sp)
  lw    $t7, 0x58($sp)
  mflo  $t9
  bgez  $t9, .L7F00A85C
   sra   $t0, $t9, 1
  addiu $at, $t9, 1
  sra   $t0, $at, 1
.L7F00A85C:
  multu $t3, $t4
  subu  $t2, $t1, $t0
  sw    $t2, 0x44($sp)
  mflo  $t5
  bgez  $t5, .L7F00A87C
   sra   $t6, $t5, 1
  addiu $at, $t5, 1
  sra   $t6, $at, 1
.L7F00A87C:
  subu  $t8, $t7, $t6
  jal   get_video2_settings_txtClipW
   sw    $t8, 0x40($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x3c($sp)
  lw    $t9, 0x68($sp)
  lw    $t1, 0x6c($sp)
  lh    $t2, 0x3c($sp)
  li    $t0, -1
  sw    $t0, 0x18($sp)
  lw    $a0, 0x50($sp)
  addiu $a1, $sp, 0x44
  addiu $a2, $sp, 0x40
  lw    $a3, 0x64($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t9, 0x10($sp)
  sw    $t1, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t2, 0x1c($sp)
  lw    $ra, 0x34($sp)
  addiu $sp, $sp, 0x50
  jr    $ra
   nop   
");

asm(R"
glabel constructor_menu00_legalscreen
  addiu $sp, $sp, -0x128
  sw    $s1, 0x34($sp)
  lui   $t6, %hi(D_8002AABC) 
  addiu $s1, $sp, 0xe4
  sw    $s4, 0x40($sp)
  addiu $t6, %lo(D_8002AABC) # addiu $t6, $t6, -0x5544
  move  $s4, $a0
  sw    $ra, 0x44($sp)
  sw    $s3, 0x3c($sp)
  sw    $s2, 0x38($sp)
  sw    $s0, 0x30($sp)
  addiu $t9, $t6, 0x3c
  move  $t0, $s1
.L7F00A914:
  lw    $at, ($t6)
  addiu $t6, $t6, 0xc
  addiu $t0, $t0, 0xc
  sw    $at, -0xc($t0)
  lw    $at, -8($t6)
  sw    $at, -8($t0)
  lw    $at, -4($t6)
  bne   $t6, $t9, .L7F00A914
   sw    $at, -4($t0)
  lw    $at, ($t6)
  move  $a0, $s4
  jal   insert_imageDL
   sw    $at, ($t0)
  mtc1  $zero, $f0
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  addiu $s0, $sp, 0xa0
  mfc1  $a1, $f0
  mfc1  $a2, $f0
  move  $s4, $v0
  move  $a0, $s0
  lui   $a3, 0x457a
  swc1  $f0, 0x10($sp)
  swc1  $f0, 0x14($sp)
  swc1  $f0, 0x18($sp)
  swc1  $f0, 0x1c($sp)
  swc1  $f0, 0x24($sp)
  jal   sub_GAME_7F059694
   swc1  $f4, 0x20($sp)
  lui   $s3, %hi(something_legalscreen_constructor)
  addiu $s3, %lo(something_legalscreen_constructor) # addiu $s3, $s3, -0x56a8
  lw    $t1, ($s3)
  sw    $s0, 0xe4($sp)
  lw    $t2, 8($t1)
  lh    $a0, 0xe($t2)
  sll   $t3, $a0, 6
  jal   sub_GAME_7F0BD714
   move  $a0, $t3
  sw    $v0, 0xf4($sp)
  move  $a0, $s0
  jal   matrix_4x4_copy
   move  $a1, $v0
  lw    $t4, 0xf4($sp)
  lw    $t5, ($s3)
  sw    $t4, 0xc($t5)
  jal   sub_GAME_7F06EFC4
   lw    $a0, ($s3)
  li    $t8, 3
  sw    $t8, 0xec($sp)
  sw    $zero, 0xe8($sp)
  sw    $s4, 0xf0($sp)
  move  $a0, $s1
  jal   subdraw
   lw    $a1, ($s3)
  lw    $v0, ($s3)
  lw    $s4, 0xf0($sp)
  move  $s0, $zero
  lw    $t7, 8($v0)
  move  $s1, $zero
  addiu $s2, $sp, 0x58
  lh    $t9, 0xe($t7)
  blez  $t9, .L7F00AA58
   nop   
  lw    $t6, 0xc($v0)
.L7F00AA14:
  move  $a1, $s2
  jal   matrix_4x4_copy
   addu  $a0, $t6, $s1
  lw    $t0, ($s3)
  sll   $t2, $s0, 6
  move  $a0, $s2
  lw    $t1, 0xc($t0)
  jal   sub_GAME_7F058C9C
   addu  $a1, $t1, $t2
  lw    $v0, ($s3)
  addiu $s0, $s0, 1
  addiu $s1, $s1, 0x40
  lw    $t3, 8($v0)
  lh    $t4, 0xe($t3)
  slt   $at, $s0, $t4
  bnezl $at, .L7F00AA14
   lw    $t6, 0xc($v0)
.L7F00AA58:
  jal   microcode_constructor
   move  $a0, $s4
  lui   $s0, %hi(D_8002A9CC)
  lui   $s1, %hi(D_8002AABC)
  lui   $s3, %hi(ptrFirstFontTableLarge)
  lui   $s2, %hi(ptrSecondFontTableLarge)
  move  $s4, $v0
  addiu $s0, %lo(D_8002A9CC) # addiu $s0, $s0, -0x5634
  addiu $s1, %lo(D_8002AABC) # addiu $s1, $s1, -0x5544
  addiu $s2, %lo(ptrSecondFontTableLarge) # addiu $s2, $s2, 0xeb8
  addiu $s3, %lo(ptrFirstFontTableLarge) # addiu $s3, $s3, 0xeb4
.L7F00AA84:
  jal   get_textptr_for_textID
   lhu   $a0, 0x10($s0)
  lw    $t5, 0xc($s0)
  lw    $a1, ($s0)
  lw    $a2, 4($s0)
  lw    $a3, 8($s0)
  lw    $t8, ($s2)
  lw    $t7, ($s3)
  sw    $v0, 0x14($sp)
  move  $a0, $s4
  sw    $t5, 0x10($sp)
  sw    $t8, 0x18($sp)
  jal   display_aligned_white_text_to_screen
   sw    $t7, 0x1c($sp)
  addiu $s0, $s0, 0x14
  sltu  $at, $s0, $s1
  bnez  $at, .L7F00AA84
   move  $s4, $v0
  lw    $ra, 0x44($sp)
  lw    $s0, 0x30($sp)
  lw    $s1, 0x34($sp)
  lw    $s2, 0x38($sp)
  lw    $s3, 0x3c($sp)
  lw    $s4, 0x40($sp)
  jr    $ra
   addiu $sp, $sp, 0x128
");

void reset_menutimer(void) { menu_timer = 0; }

void dummy7F00AAF8(void) {
  // (function likely stub)
}

asm(R"
glabel interface_menu17_switchscreens
  addiu $sp, $sp, -0x18
  li    $at, 0x42700000 # 60.000000
  sw    $ra, 0x14($sp)
  mtc1  $at, $f12
  jal   setvideo_far
   nop   
  lui   $at, %hi(D_800519EC)
  jal   video_related_21
   lwc1  $f12, %lo(D_800519EC)($at)
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f12
  lui   $at, %hi(D_800519F0)
  jal   set_page_height
   lwc1  $f14, %lo(D_800519F0)($at)
  jal   set_video2_settings_offset_24
   move  $a0, $zero
  lui   $v0, %hi(menu_timer)
  addiu $v0, %lo(menu_timer) # addiu $v0, $v0, -0x5734
  lw    $t6, ($v0)
  lui   $t9, %hi(spectrum_related_flag) 
  addiu $t7, $t6, 1
  slti  $at, $t7, 4
  bnez  $at, .L7F00AB98
   sw    $t7, ($v0)
  lw    $t9, %lo(spectrum_related_flag)($t9)
  lui   $t0, %hi(is_emulating_spectrum) 
  bnezl $t9, .L7F00AB9C
   lw    $ra, 0x14($sp)
  lw    $t0, %lo(is_emulating_spectrum)($t0)
  lui   $v0, %hi(menu_update)
  addiu $v0, %lo(menu_update) # addiu $v0, $v0, -0x573c
  bnezl $t0, .L7F00AB9C
   lw    $ra, 0x14($sp)
  lw    $t1, ($v0)
  lui   $at, %hi(maybe_prev_menu)
  li    $t2, -1
  sw    $t1, %lo(maybe_prev_menu)($at)
  sw    $t2, ($v0)
.L7F00AB98:
  lw    $ra, 0x14($sp)
.L7F00AB9C:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

void constructor_menu17_switchscreens(Gfx *DL) { insert_imageDL(DL); }

asm(R"
glabel init_menu01_nintendo
  addiu $sp, $sp, -0x30
  lui   $at, %hi(menu_timer)
  lui   $t7, %hi(D_8002AAFC) 
  sw    $ra, 0x1c($sp)
  sw    $zero, %lo(menu_timer)($at)
  addiu $t7, %lo(D_8002AAFC) # addiu $t7, $t7, -0x5504
  lw    $at, ($t7)
  addiu $t6, $sp, 0x24
  lw    $t0, 4($t7)
  sw    $at, ($t6)
  lw    $at, 8($t7)
  sw    $t0, 4($t6)
  lui   $v0, %hi(PitemZ_entries)
  sw    $at, 8($t6)
  addiu $v0, %lo(PitemZ_entries) # addiu $v0, $v0, -0x5dd8
  lui   $a2, %hi(ptr_logo_and_walletbond_DL)
  lui   $a3, (0x0003C000 >> 16) # lui $a3, 3
  ori   $a3, (0x0003C000 & 0xFFFF) # ori $a3, $a3, 0xc000
  lw    $a2, %lo(ptr_logo_and_walletbond_DL)($a2)
  lw    $a0, 0xcf0($v0)
  lw    $a1, 0xcf4($v0)
  jal   load_object_fill_header
   sw    $zero, 0x10($sp)
  lui   $a0, %hi(PitemZ_entries+0xCF0)
  jal   set_objuse_flag_compute_grp_nums_set_obj_loaded
   lw    $a0, %lo(PitemZ_entries+0xCF0)($a0)
  lui   $a0, %hi(PitemZ_entries+0xCF0)
  jal   get_obj_instance_controller_for_header
   lw    $a0, %lo(PitemZ_entries+0xCF0)($a0)
  lui   $v1, %hi(something_legalscreen_constructor)
  addiu $v1, %lo(something_legalscreen_constructor) # addiu $v1, $v1, -0x56a8
  sw    $v0, ($v1)
  move  $a0, $v0
  jal   set_obj_instance_controller_scale
   lui   $a1, 0x3f80
  lui   $a0, %hi(something_legalscreen_constructor)
  lw    $a0, %lo(something_legalscreen_constructor)($a0)
  jal   setsuboffset
   addiu $a1, $sp, 0x24
  jal   musicTrack1Play
   li    $a0, 44
  li    $t1, 1
  lui   $at, %hi(maybe_is_in_menu)
  sw    $t1, %lo(maybe_is_in_menu)($at)
  lui   $at, %hi(D_800519F4)
  lwc1  $f4, %lo(D_800519F4)($at)
  lui   $at, %hi(flt_CODE_bss_80069614)
  lw    $ra, 0x1c($sp)
  swc1  $f4, %lo(flt_CODE_bss_80069614)($at)
  lui   $at, %hi(D_800519F8)
  lwc1  $f6, %lo(D_800519F8)($at)
  lui   $at, %hi(flt_CODE_bss_80069618)
  addiu $sp, $sp, 0x30
  jr    $ra
   swc1  $f6, %lo(flt_CODE_bss_80069618)($at)
");

void update_menu01_nintendo(void) {
  set_obj_instance_scale_to_zero(something_legalscreen_constructor);
}

asm(R"
glabel interface_menu01_nintendo
  addiu $sp, $sp, -0x18
  li    $at, 0x42700000 # 60.000000
  sw    $ra, 0x14($sp)
  mtc1  $at, $f12
  jal   setvideo_far
   nop   
  lui   $at, %hi(menu01_aspect)
  jal   video_related_21
   lwc1  $f12, %lo(menu01_aspect)($at)
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f12
  lui   $at, %hi(menu01_pageheight)
  jal   set_page_height
   lwc1  $f14, %lo(menu01_pageheight)($at)
  jal   set_video2_settings_offset_24
   move  $a0, $zero
  lui   $v0, %hi(menu_timer)
  addiu $v0, %lo(menu_timer) # addiu $v0, $v0, -0x5734
  lui   $t7, %hi(clock_timer) 
  lw    $t7, %lo(clock_timer)($t7)
  lw    $t6, ($v0)
  li    $a1, 1
  move  $a0, $zero
  addu  $t8, $t6, $t7
  slti  $at, $t8, 0x1f5
  bnez  $at, .L7F00AD44
   sw    $t8, ($v0)
  jal   set_menu_to_mode
   li    $a0, 2
  b     .L7F00AD8C
   lw    $ra, 0x14($sp)
.L7F00AD44:
  jal   get_controller_buttons_pressed
   li    $a1, 65535
  beqz  $v0, .L7F00AD88
   lui   $t0, %hi(is_first_time_on_main_menu) 
  lw    $t0, %lo(is_first_time_on_main_menu)($t0)
  li    $t1, 1
  lui   $at, %hi(prev_keypresses)
  bnez  $t0, .L7F00AD7C
   li    $a0, 2
  li    $a0, 5
  jal   set_menu_to_mode
   li    $a1, 1
  b     .L7F00AD8C
   lw    $ra, 0x14($sp)
.L7F00AD7C:
  sw    $t1, %lo(prev_keypresses)($at)
  jal   set_menu_to_mode
   li    $a1, 1
.L7F00AD88:
  lw    $ra, 0x14($sp)
.L7F00AD8C:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel constructor_menu01_nintendo
  addiu $sp, $sp, -0x168
  sw    $s2, 0x34($sp)
  lui   $t6, %hi(D_8002AB08) 
  addiu $s2, $sp, 0x128
  addiu $t6, %lo(D_8002AB08) # addiu $t6, $t6, -0x54f8
  sw    $ra, 0x3c($sp)
  sw    $s3, 0x38($sp)
  sw    $s1, 0x30($sp)
  sw    $s0, 0x2c($sp)
  addiu $t9, $t6, 0x3c
  move  $t0, $s2
.L7F00ADC4:
  lw    $at, ($t6)
  addiu $t6, $t6, 0xc
  addiu $t0, $t0, 0xc
  sw    $at, -0xc($t0)
  lw    $at, -8($t6)
  sw    $at, -8($t0)
  lw    $at, -4($t6)
  bne   $t6, $t9, .L7F00ADC4
   sw    $at, -4($t0)
  lw    $at, ($t6)
  jal   insert_imageDL
   sw    $at, ($t0)
  lui   $t1, (0xBC000002 >> 16) # lui $t1, 0xbc00
  lui   $t2, (0x80000040 >> 16) # lui $t2, 0x8000
  lui   $t3, (0x03860010 >> 16) # lui $t3, 0x386
  lui   $t4, %hi(D_8002A990) 
  addiu $t4, %lo(D_8002A990) # addiu $t4, $t4, -0x5670
  ori   $t3, (0x03860010 & 0xFFFF) # ori $t3, $t3, 0x10
  ori   $t2, (0x80000040 & 0xFFFF) # ori $t2, $t2, 0x40
  ori   $t1, (0xBC000002 & 0xFFFF) # ori $t1, $t1, 2
  sw    $t1, ($v0)
  sw    $t2, 4($v0)
  sw    $t3, 8($v0)
  sw    $t4, 0xc($v0)
  addiu $t5, $v0, 0x18
  lui   $a0, %hi(D_8002A988)
  sw    $t5, 0x168($sp)
  lui   $t8, (0x03880010 >> 16) # lui $t8, 0x388
  addiu $a0, %lo(D_8002A988) # addiu $a0, $a0, -0x5678
  ori   $t8, (0x03880010 & 0xFFFF) # ori $t8, $t8, 0x10
  sw    $t8, 0x10($v0)
  sw    $a0, 0x14($v0)
  lui   $t7, %hi(menu_timer) 
  lw    $t7, %lo(menu_timer)($t7)
  li    $a1, 255
  lui   $at, (0xFFFE8F72 >> 16) # lui $at, 0xfffe
  multu $t7, $a1
  ori   $at, (0xFFFE8F72 & 0xFFFF) # ori $at, $at, 0x8f72
  lui   $v0, %hi(flt_CODE_bss_80069614)
  addiu $v0, %lo(flt_CODE_bss_80069614) # addiu $v0, $v0, -0x69ec
  mflo  $t9
  addu  $t6, $t9, $at
  li    $at, 100
  div   $zero, $t6, $at
  mflo  $t0
  subu  $v1, $a1, $t0
  slti  $at, $v1, 0x100
  bnez  $at, .L7F00AE8C
   nop   
  li    $v1, 255
.L7F00AE8C:
  bgez  $v1, .L7F00AE98
   lui   $at, %hi(D_80051A04)
  move  $v1, $zero
.L7F00AE98:
  sb    $v1, 6($a0)
  sb    $v1, 5($a0)
  sb    $v1, 4($a0)
  sb    $v1, 2($a0)
  sb    $v1, 1($a0)
  sb    $v1, ($a0)
  lwc1  $f6, %lo(D_80051A04)($at)
  lwc1  $f4, ($v0)
  addiu $s1, $sp, 0x90
  move  $a1, $s1
  add.s $f8, $f4, $f6
  swc1  $f8, ($v0)
  jal   sub_GAME_7F0585FC
   lwc1  $f12, ($v0)
  lui   $s0, %hi(flt_CODE_bss_80069618)
  addiu $s0, %lo(flt_CODE_bss_80069618) # addiu $s0, $s0, -0x69e8
  lwc1  $f12, ($s0)
  jal   sub_GAME_7F058BB8
   move  $a1, $s1
  lui   $at, %hi(D_80051A08)
  lwc1  $f0, %lo(D_80051A08)($at)
  lui   $at, %hi(D_80051A0C)
  lwc1  $f16, %lo(D_80051A0C)($at)
  lwc1  $f10, ($s0)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  mul.s $f18, $f10, $f16
  lui   $a3, 0x457a
  swc1  $f18, ($s0)
  lwc1  $f4, ($s0)
  c.lt.s $f0, $f4
  nop   
  bc1fl .L7F00AF28
   mtc1  $zero, $f0
  swc1  $f0, ($s0)
  mtc1  $zero, $f0
.L7F00AF28:
  addiu $s0, $sp, 0xe0
  move  $a0, $s0
  mfc1  $a1, $f0
  mfc1  $a2, $f0
  swc1  $f6, 0x20($sp)
  swc1  $f0, 0x10($sp)
  swc1  $f0, 0x14($sp)
  swc1  $f0, 0x18($sp)
  swc1  $f0, 0x1c($sp)
  jal   sub_GAME_7F059694
   swc1  $f0, 0x24($sp)
  move  $a0, $s0
  jal   matrix_4x4_multiply_in_place
   move  $a1, $s1
  move  $a0, $s1
  jal   matrix_4x4_copy
   move  $a1, $s0
  lui   $s3, %hi(something_legalscreen_constructor)
  addiu $s3, %lo(something_legalscreen_constructor) # addiu $s3, $s3, -0x56a8
  lw    $t1, ($s3)
  sw    $s0, 0x128($sp)
  lw    $t2, 8($t1)
  lh    $a0, 0xe($t2)
  sll   $t3, $a0, 6
  jal   sub_GAME_7F0BD714
   move  $a0, $t3
  sw    $v0, 0x138($sp)
  move  $a0, $s0
  jal   matrix_4x4_copy
   move  $a1, $v0
  lw    $t4, 0x138($sp)
  lw    $t5, ($s3)
  sw    $t4, 0xc($t5)
  jal   sub_GAME_7F06EFC4
   lw    $a0, ($s3)
  lw    $t7, 0x168($sp)
  li    $t8, 3
  sw    $t8, 0x130($sp)
  sw    $zero, 0x12c($sp)
  move  $a0, $s2
  lw    $a1, ($s3)
  jal   subdraw
   sw    $t7, 0x134($sp)
  lw    $t9, 0x134($sp)
  lw    $v0, ($s3)
  move  $s0, $zero
  sw    $t9, 0x168($sp)
  lw    $t6, 8($v0)
  move  $s1, $zero
  addiu $s2, $sp, 0x50
  lh    $t0, 0xe($t6)
  blezl $t0, .L7F00B048
   lw    $ra, 0x3c($sp)
  lw    $t1, 0xc($v0)
.L7F00B000:
  move  $a1, $s2
  jal   matrix_4x4_copy
   addu  $a0, $t1, $s1
  lw    $t2, ($s3)
  sll   $t4, $s0, 6
  move  $a0, $s2
  lw    $t3, 0xc($t2)
  jal   sub_GAME_7F058C9C
   addu  $a1, $t3, $t4
  lw    $v0, ($s3)
  addiu $s0, $s0, 1
  addiu $s1, $s1, 0x40
  lw    $t5, 8($v0)
  lh    $t8, 0xe($t5)
  slt   $at, $s0, $t8
  bnezl $at, .L7F00B000
   lw    $t1, 0xc($v0)
  lw    $ra, 0x3c($sp)
.L7F00B048:
  lw    $v0, 0x168($sp)
  lw    $s0, 0x2c($sp)
  lw    $s1, 0x30($sp)
  lw    $s2, 0x34($sp)
  lw    $s3, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x168
");

void init_menu02_rarelogo(void) {
  sub_GAME_7F008B58(ptr_logo_and_walletbond_DL, 0x78000);
  play_sfx_a1(ptr_sfx_buf, 0x102, 0);
}

void update_menu02_rareware(void) {}

void interface_menu02_rareware(void) {
  set_video2_settings_offset_24(0);
  if (sub_GAME_7F008DD0() != 0) {
    set_menu_to_mode(3, 1);
    return;
  }
  if (get_controller_buttons_pressed(0, 0xffff) != 0) {
    if (is_first_time_on_main_menu == 0) {
      set_menu_to_mode(5, 1);
      return;
    }
    prev_keypresses = 1;
    set_menu_to_mode(3, 1);
  }
}

void constructor_menu02_rareware(Gfx *DL) {
  retrieve_display_rareware_logo(DL);
}

void init_menu03_eyeintro(void) {
  sub_GAME_7F008E80(ptr_logo_and_walletbond_DL, 0x78000);
  musicTrack1Play(2);
  maybe_is_in_menu = 1;
}

void update_menu_03_eye(void) { sub_GAME_7F00920C(); }

void interface_menu03_eye(void) {
  set_video2_settings_offset_24(0);
  if (sub_GAME_7F009744() != 0) {
    set_menu_to_mode(4, 1);
    return;
  }
  if (get_controller_buttons_pressed(0, 0xffff) != 0) {
    if (is_first_time_on_main_menu == 0) {
      set_menu_to_mode(5, 1);
      return;
    }
    prev_keypresses = 1;
    set_menu_to_mode(4, 1);
  }
}

void constructor_menu03_eye(Gfx *DL) { sub_GAME_7F009254(DL); }

asm(R"
glabel init_menu04_goldeneyelogo
  addiu $sp, $sp, -0x30
  lui   $at, %hi(menu_timer)
  lui   $t7, %hi(D_8002AB48) 
  sw    $ra, 0x1c($sp)
  sw    $zero, %lo(menu_timer)($at)
  addiu $t7, %lo(D_8002AB48) # addiu $t7, $t7, -0x54b8
  lw    $at, ($t7)
  addiu $t6, $sp, 0x24
  lw    $t0, 4($t7)
  sw    $at, ($t6)
  lw    $at, 8($t7)
  sw    $t0, 4($t6)
  lui   $v0, %hi(PitemZ_entries)
  sw    $at, 8($t6)
  addiu $v0, %lo(PitemZ_entries) # addiu $v0, $v0, -0x5dd8
  lui   $a2, %hi(ptr_logo_and_walletbond_DL)
  lui   $a3, (0x0003C000 >> 16) # lui $a3, 3
  ori   $a3, (0x0003C000 & 0xFFFF) # ori $a3, $a3, 0xc000
  lw    $a2, %lo(ptr_logo_and_walletbond_DL)($a2)
  lw    $a0, 0xcfc($v0)
  lw    $a1, 0xd00($v0)
  jal   load_object_fill_header
   sw    $zero, 0x10($sp)
  lui   $a0, %hi(PitemZ_entries+0xCFC)
  jal   set_objuse_flag_compute_grp_nums_set_obj_loaded
   lw    $a0, %lo(PitemZ_entries+0xCFC)($a0)
  lui   $a0, %hi(PitemZ_entries+0xCFC)
  jal   get_obj_instance_controller_for_header
   lw    $a0, %lo(PitemZ_entries+0xCFC)($a0)
  lui   $v1, %hi(something_legalscreen_constructor)
  addiu $v1, %lo(something_legalscreen_constructor) # addiu $v1, $v1, -0x56a8
  sw    $v0, ($v1)
  move  $a0, $v0
  jal   set_obj_instance_controller_scale
   lui   $a1, 0x3f80
  lui   $a0, %hi(something_legalscreen_constructor)
  lw    $a0, %lo(something_legalscreen_constructor)($a0)
  jal   setsuboffset
   addiu $a1, $sp, 0x24
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

void update_menu04_goldeneye(void) {
  is_first_time_on_main_menu = 0;
  set_obj_instance_scale_to_zero(something_legalscreen_constructor);
}

asm(R"
glabel interface_menu04_goldeneyelogo
  addiu $sp, $sp, -0x18
  li    $at, 0x42700000 # 60.000000
  sw    $ra, 0x14($sp)
  mtc1  $at, $f12
  jal   setvideo_far
   nop   
  lui   $at, %hi(D_80051A10)
  jal   video_related_21
   lwc1  $f12, %lo(D_80051A10)($at)
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f12
  lui   $at, %hi(D_80051A14)
  jal   set_page_height
   lwc1  $f14, %lo(D_80051A14)($at)
  jal   set_video2_settings_offset_24
   move  $a0, $zero
  lui   $v1, %hi(menu_timer)
  addiu $v1, %lo(menu_timer) # addiu $v1, $v1, -0x5734
  lui   $t7, %hi(clock_timer) 
  lw    $t7, %lo(clock_timer)($t7)
  lw    $t6, ($v1)
  lui   $t9, %hi(is_first_time_on_main_menu) 
  addu  $t8, $t6, $t7
  sw    $t8, ($v1)
  lw    $t9, %lo(is_first_time_on_main_menu)($t9)
  slti  $at, $t8, 0xb5
  beql  $t9, $zero, .L7F00B3C8
   lw    $t1, ($v1)
  beqz  $at, .L7F00B3C4
   lui   $t0, %hi(D_8002A938) 
  lw    $t0, %lo(D_8002A938)($t0)
  slti  $at, $t8, 0x5b
  move  $a0, $zero
  beqz  $t0, .L7F00B454
   nop   
  bnez  $at, .L7F00B454
   nop   
.L7F00B3C4:
  lw    $t1, ($v1)
.L7F00B3C8:
  lui   $t2, %hi(prev_keypresses) 
  move  $a0, $zero
  slti  $at, $t1, 0xb5
  bnez  $at, .L7F00B418
   nop   
  lw    $t2, %lo(prev_keypresses)($t2)
  li    $a0, 5
  beqz  $t2, .L7F00B3FC
   nop   
  jal   set_menu_to_mode
   li    $a1, 1
  b     .L7F00B470
   lw    $ra, 0x14($sp)
.L7F00B3FC:
  jal   do_extended_cast_display
   move  $a0, $zero
  li    $a0, 24
  jal   set_menu_to_mode
   li    $a1, 1
  b     .L7F00B470
   lw    $ra, 0x14($sp)
.L7F00B418:
  jal   get_controller_buttons_pressed
   li    $a1, 65535
  bnez  $v0, .L7F00B440
   lui   $t3, %hi(is_first_time_on_main_menu) 
  lw    $t3, %lo(is_first_time_on_main_menu)($t3)
  lui   $t4, %hi(D_8002A938) 
  beql  $t3, $zero, .L7F00B470
   lw    $ra, 0x14($sp)
  lw    $t4, %lo(D_8002A938)($t4)
  beqz  $t4, .L7F00B46C
.L7F00B440:
   li    $a0, 5
  jal   set_menu_to_mode
   li    $a1, 1
  b     .L7F00B470
   lw    $ra, 0x14($sp)
.L7F00B454:
  jal   get_controller_buttons_pressed
   li    $a1, 65535
  beqz  $v0, .L7F00B46C
   li    $t5, 1
  lui   $at, %hi(D_8002A938)
  sw    $t5, %lo(D_8002A938)($at)
.L7F00B46C:
  lw    $ra, 0x14($sp)
.L7F00B470:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel constructor_menu04_goldeneyelogo
  addiu $sp, $sp, -0x180
  sw    $s2, 0x40($sp)
  lui   $t6, %hi(D_8002AB54) 
  addiu $s2, $sp, 0x140
  sw    $s4, 0x48($sp)
  addiu $t6, %lo(D_8002AB54) # addiu $t6, $t6, -0x54ac
  move  $s4, $a0
  sw    $ra, 0x4c($sp)
  sw    $s3, 0x44($sp)
  sw    $s1, 0x3c($sp)
  sw    $s0, 0x38($sp)
  addiu $t9, $t6, 0x3c
  move  $t1, $s2
.L7F00B4B0:
  lw    $at, ($t6)
  addiu $t6, $t6, 0xc
  addiu $t1, $t1, 0xc
  sw    $at, -0xc($t1)
  lw    $at, -8($t6)
  sw    $at, -8($t1)
  lw    $at, -4($t6)
  bne   $t6, $t9, .L7F00B4B0
   sw    $at, -4($t1)
  lw    $at, ($t6)
  move  $a0, $s4
  move  $a1, $zero
  move  $a2, $zero
  move  $a3, $zero
  jal   set_setfillcolor
   sw    $at, ($t1)
  jal   insert_generic_fillrect
   move  $a0, $v0
  move  $s4, $v0
  jal   sub_GAME_7F0BD6F8
   li    $a0, 2
  mtc1  $zero, $f0
  li    $at, 0x457A0000 # 4000.000000
  mtc1  $at, $f4
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  mfc1  $a2, $f0
  mfc1  $a3, $f0
  move  $s0, $v0
  addiu $a0, $sp, 0xb0
  move  $a1, $v0
  swc1  $f0, 0x14($sp)
  swc1  $f0, 0x18($sp)
  swc1  $f0, 0x1c($sp)
  swc1  $f0, 0x20($sp)
  swc1  $f0, 0x28($sp)
  swc1  $f4, 0x10($sp)
  jal   guLookAtReflect
   swc1  $f6, 0x24($sp)
  move  $v0, $s4
  addiu $s4, $s4, 8
  lui   $t2, (0xBC000002 >> 16) # lui $t2, 0xbc00
  lui   $t3, (0x80000040 >> 16) # lui $t3, 0x8000
  ori   $t3, (0x80000040 & 0xFFFF) # ori $t3, $t3, 0x40
  ori   $t2, (0xBC000002 & 0xFFFF) # ori $t2, $t2, 2
  move  $v1, $s4
  addiu $s4, $s4, 8
  sw    $t2, ($v0)
  sw    $t3, 4($v0)
  lui   $t4, (0x03860010 >> 16) # lui $t4, 0x386
  lui   $t5, %hi(D_8002A978) 
  addiu $t5, %lo(D_8002A978) # addiu $t5, $t5, -0x5688
  ori   $t4, (0x03860010 & 0xFFFF) # ori $t4, $t4, 0x10
  move  $a0, $s4
  addiu $s4, $s4, 8
  sw    $t4, ($v1)
  sw    $t5, 4($v1)
  lui   $t8, (0x03880010 >> 16) # lui $t8, 0x388
  lui   $t7, %hi(D_8002A970) 
  addiu $t7, %lo(D_8002A970) # addiu $t7, $t7, -0x5690
  ori   $t8, (0x03880010 & 0xFFFF) # ori $t8, $t8, 0x10
  move  $a1, $s4
  sw    $t8, ($a0)
  sw    $t7, 4($a0)
  lui   $t9, (0x03840010 >> 16) # lui $t9, 0x384
  ori   $t9, (0x03840010 & 0xFFFF) # ori $t9, $t9, 0x10
  mtc1  $zero, $f0
  sw    $t9, ($a1)
  sw    $s0, 4($a1)
  addiu $s4, $s4, 8
  move  $t0, $s4
  lui   $t6, (0x03820010 >> 16) # lui $t6, 0x382
  ori   $t6, (0x03820010 & 0xFFFF) # ori $t6, $t6, 0x10
  addiu $t1, $s0, 0x10
  sw    $t1, 4($t0)
  sw    $t6, ($t0)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  addiu $s1, $sp, 0xf8
  lui   $a3, (0x453B8000 >> 16) # lui $a3, 0x453b
  mfc1  $a1, $f0
  mfc1  $a2, $f0
  addiu $s4, $s4, 8
  ori   $a3, (0x453B8000 & 0xFFFF) # ori $a3, $a3, 0x8000
  move  $a0, $s1
  swc1  $f0, 0x24($sp)
  swc1  $f0, 0x1c($sp)
  swc1  $f0, 0x18($sp)
  swc1  $f0, 0x14($sp)
  swc1  $f0, 0x10($sp)
  jal   sub_GAME_7F059694
   swc1  $f8, 0x20($sp)
  lui   $s3, %hi(something_legalscreen_constructor)
  addiu $s3, %lo(something_legalscreen_constructor) # addiu $s3, $s3, -0x56a8
  lw    $t2, ($s3)
  sw    $s1, 0x140($sp)
  lw    $t3, 8($t2)
  lh    $a0, 0xe($t3)
  sll   $t4, $a0, 6
  jal   sub_GAME_7F0BD714
   move  $a0, $t4
  lui   $at, %hi(D_80051A18)
  sw    $v0, 0x150($sp)
  lwc1  $f12, %lo(D_80051A18)($at)
  jal   matrix_multiply_A1_by_F12
   move  $a1, $s1
  move  $a0, $s1
  jal   matrix_4x4_copy
   lw    $a1, 0x150($sp)
  lw    $t5, 0x150($sp)
  lw    $t8, ($s3)
  sw    $t5, 0xc($t8)
  jal   sub_GAME_7F06EFC4
   lw    $a0, ($s3)
  li    $t7, 3
  sw    $t7, 0x148($sp)
  sw    $zero, 0x144($sp)
  sw    $s4, 0x14c($sp)
  move  $a0, $s2
  jal   subdraw
   lw    $a1, ($s3)
  lw    $v0, ($s3)
  lw    $s4, 0x14c($sp)
  move  $s0, $zero
  lw    $t9, 8($v0)
  move  $s1, $zero
  addiu $s2, $sp, 0x5c
  lh    $t6, 0xe($t9)
  blezl $t6, .L7F00B704
   lw    $ra, 0x4c($sp)
  lw    $t1, 0xc($v0)
.L7F00B6BC:
  move  $a1, $s2
  jal   matrix_4x4_copy
   addu  $a0, $t1, $s1
  lw    $t2, ($s3)
  sll   $t4, $s0, 6
  move  $a0, $s2
  lw    $t3, 0xc($t2)
  jal   sub_GAME_7F058C9C
   addu  $a1, $t3, $t4
  lw    $v0, ($s3)
  addiu $s0, $s0, 1
  addiu $s1, $s1, 0x40
  lw    $t5, 8($v0)
  lh    $t8, 0xe($t5)
  slt   $at, $s0, $t8
  bnezl $at, .L7F00B6BC
   lw    $t1, 0xc($v0)
  lw    $ra, 0x4c($sp)
.L7F00B704:
  move  $v0, $s4
  lw    $s4, 0x48($sp)
  lw    $s0, 0x38($sp)
  lw    $s1, 0x3c($sp)
  lw    $s2, 0x40($sp)
  lw    $s3, 0x44($sp)
  jr    $ra
   addiu $sp, $sp, 0x180
");

asm(R"
glabel disable_all_switches
  addiu $sp, $sp, -0x28
  sw    $ra, 0x24($sp)
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  lw    $v1, 8($a0)
  move  $s2, $a0
  move  $s0, $zero
  lh    $a2, 0xc($v1)
  move  $s1, $zero
  li    $s3, 18
  blezl $a2, .L7F00B7A8
   lw    $ra, 0x24($sp)
.L7F00B75C:
  lw    $t6, 8($v1)
  addu  $t7, $t6, $s1
  lw    $a1, ($t7)
  beql  $a1, $zero, .L7F00B798
   addiu $s0, $s0, 1
  lhu   $t8, ($a1)
  andi  $t9, $t8, 0xff
  bnel  $s3, $t9, .L7F00B798
   addiu $s0, $s0, 1
  jal   extract_id_from_object_structure_microcode
   move  $a0, $s2
  sw    $zero, ($v0)
  lw    $v1, 8($s2)
  lh    $a2, 0xc($v1)
  addiu $s0, $s0, 1
.L7F00B798:
  slt   $at, $s0, $a2
  bnez  $at, .L7F00B75C
   addiu $s1, $s1, 4
  lw    $ra, 0x24($sp)
.L7F00B7A8:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
glabel set_item_visibility_in_objinstance
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a2, 0x20($sp)
  lw    $t6, 8($a0)
  sll   $t8, $a1, 2
  lw    $t7, 8($t6)
  addu  $t9, $t7, $t8
  lw    $a3, ($t9)
  beql  $a3, $zero, .L7F00B7FC
   lw    $ra, 0x14($sp)
  jal   extract_id_from_object_structure_microcode
   move  $a1, $a3
  lw    $t0, 0x20($sp)
  sw    $t0, ($v0)
  lw    $ra, 0x14($sp)
.L7F00B7FC:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

void select_load_bond_picture(int *objinstance, unsigned int bondID) {
  set_item_visibility_in_objinstance(objinstance, 8, 1);
  set_item_visibility_in_objinstance(objinstance, 9, 0);
  set_item_visibility_in_objinstance(objinstance, 10, 0);
  set_item_visibility_in_objinstance(objinstance, 0xb, 0);
  set_item_visibility_in_objinstance(objinstance, 0xf, 1);
  set_item_visibility_in_objinstance(objinstance, 0x10, 0);
  set_item_visibility_in_objinstance(objinstance, 0x11, 0);
  set_item_visibility_in_objinstance(objinstance, 0x12, 0);
}

asm(R"
glabel load_walletbond
  addiu $sp, $sp, -0x38
  lui   $t6, %hi(ptr_folder_object_instance) 
  lw    $t6, %lo(ptr_folder_object_instance)($t6)
  sw    $ra, 0x34($sp)
  sw    $s2, 0x30($sp)
  sw    $s1, 0x2c($sp)
  sw    $s0, 0x28($sp)
  bnez  $t6, .L7F00B974
   sdc1  $f20, 0x20($sp)
  lui   $s2, %hi(PitemZ_entries)
  addiu $s2, %lo(PitemZ_entries) # addiu $s2, $s2, -0x5dd8
  lui   $a2, %hi(ptr_logo_and_walletbond_DL)
  lw    $a2, %lo(ptr_logo_and_walletbond_DL)($a2)
  lw    $a0, 0xd08($s2)
  lw    $a1, 0xd0c($s2)
  li    $a3, 40960
  jal   load_object_fill_header
   sw    $zero, 0x10($sp)
  jal   set_objuse_flag_compute_grp_nums_set_obj_loaded
   lw    $a0, 0xd08($s2)
  li    $at, 0x3F800000 # 1.000000
  lui   $s0, %hi(ptr_folder_object_instance)
  lui   $s1, %hi(D_8002A96C)
  mtc1  $at, $f20
  addiu $s1, %lo(D_8002A96C) # addiu $s1, $s1, -0x5694
  addiu $s0, %lo(ptr_folder_object_instance) # addiu $s0, $s0, -0x56a4
.L7F00B914:
  jal   get_aircraft_obj_instance_controller
   lw    $a0, 0xd08($s2)
  mfc1  $a1, $f20
  sw    $v0, ($s0)
  jal   set_obj_instance_controller_scale
   move  $a0, $v0
  addiu $s0, $s0, 4
  bne   $s0, $s1, .L7F00B914
   nop   
  lw    $t7, 0xd08($s2)
  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
  lw    $t8, 8($t7)
  lw    $v1, 0x54($t8)
  beql  $v1, $zero, .L7F00B978
   lw    $ra, 0x34($sp)
  lw    $v0, 4($v1)
  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
  move  $a1, $zero
  lw    $t0, ($v0)
  lw    $t9, 0x1c($v0)
  li    $a2, 8
  and   $t1, $t0, $at
  jal   sub_GAME_7F0BA640
   addu  $a0, $t9, $t1
.L7F00B974:
  lw    $ra, 0x34($sp)
.L7F00B978:
  ldc1  $f20, 0x20($sp)
  lw    $s0, 0x28($sp)
  lw    $s1, 0x2c($sp)
  lw    $s2, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x38
");

asm(R"
glabel sub_GAME_7F00B990
  addiu $sp, $sp, -0x20
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  lui   $s0, %hi(ptr_folder_object_instance)
  lui   $s1, %hi(D_8002A96C)
  sw    $ra, 0x1c($sp)
  addiu $s1, %lo(D_8002A96C) # addiu $s1, $s1, -0x5694
  addiu $s0, %lo(ptr_folder_object_instance) # addiu $s0, $s0, -0x56a4
  lw    $a0, ($s0)
.L7F00B9B4:
  beql  $a0, $zero, .L7F00B9CC
   addiu $s0, $s0, 4
  jal   set_aircraft_obj_inst_scale_to_zero
   nop   
  sw    $zero, ($s0)
  addiu $s0, $s0, 4
.L7F00B9CC:
  bnel  $s0, $s1, .L7F00B9B4
   lw    $a0, ($s0)
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x20
");

asm(R"
glabel init_menu05_fileselect
  lui   $t7, %hi(ptr_logo_and_walletbond_DL) 
  lw    $t7, %lo(ptr_logo_and_walletbond_DL)($t7)
  li    $at, 40960
  lui   $v0, %hi(selected_folder_num)
  addu  $t8, $t7, $at
  lui   $at, %hi(prev_keypresses)
  addiu $v0, %lo(selected_folder_num) # addiu $v0, $v0, -0x5718
  sw    $zero, %lo(prev_keypresses)($at)
  lw    $t9, ($v0)
  addiu $sp, $sp, -0x28
  lui   $t6, (0x0006E000 >> 16) # lui $t6, 6
  ori   $t6, (0x0006E000 & 0xFFFF) # ori $t6, $t6, 0xe000
  sw    $ra, 0x14($sp)
  sw    $t6, 0x24($sp)
  bgez  $t9, .L7F00BA2C
   sw    $t8, 0x20($sp)
  sw    $zero, ($v0)
.L7F00BA2C:
  lui   $at, %hi(tab_2_selected)
  sw    $zero, %lo(tab_2_selected)($at)
  lui   $at, %hi(tab_3_selected)
  sw    $zero, %lo(tab_3_selected)($at)
  lui   $at, %hi(folder_selected_for_deletion)
  li    $t0, -1
  sw    $t0, %lo(folder_selected_for_deletion)($at)
  lui   $at, %hi(folder_selected_for_deletion_choice)
  li    $t1, 1
  sw    $t1, %lo(folder_selected_for_deletion_choice)($at)
  addiu $a0, $sp, 0x20
  jal   sub_GAME_7F008DE4
   addiu $a1, $sp, 0x24
  jal   load_walletbond
   nop   
  lui   $t2, %hi(maybe_is_in_menu) 
  lw    $t2, %lo(maybe_is_in_menu)($t2)
  beqz  $t2, .L7F00BA88
   nop   
  jal   musicTrack1Play
   li    $a0, 23
  lui   $at, %hi(maybe_is_in_menu)
  sw    $zero, %lo(maybe_is_in_menu)($at)
.L7F00BA88:
  lui   $at, %hi(menu_timer)
  sw    $zero, %lo(menu_timer)($at)
  lui   $at, %hi(cheat_activated_1)
  lui   $v0, %hi(cheat_activated_2)
  lui   $v1, %hi(cheat_activated_74)
  addiu $v1, %lo(cheat_activated_74) # addiu $v1, $v1, -0x6915
  addiu $v0, %lo(cheat_activated_2) # addiu $v0, $v0, -0x695d
  sb    $zero, %lo(CHEAT_AVAILABLE_EXTRA_CHARS)($at)
  sb    $zero, %lo(cheat_activated_1)($at)
.L7F00BAAC:
  addiu $v0, $v0, 4
  sb    $zero, -3($v0)
  sb    $zero, -2($v0)
  sb    $zero, -1($v0)
  bne   $v0, $v1, .L7F00BAAC
   sb    $zero, -4($v0)
  lw    $ra, 0x14($sp)
  lui   $at, %hi(append_cheat_sp)
  sw    $zero, %lo(append_cheat_sp)($at)
  lui   $at, %hi(append_cheat_mp)
  sw    $zero, %lo(append_cheat_mp)($at)
  jr    $ra
   addiu $sp, $sp, 0x28
");

void update_menu05_filesel(void) {
  if ((menu_update == 0) || (maybe_prev_menu == 0)) {
    sub_GAME_7F00B990();
  }
}

asm(R"
glabel get_chapter_briefing_entry
  bltz  $a0, .L7F00BB5C
   move  $v1, $a0
  sll   $t6, $a0, 3
  subu  $t6, $t6, $a0
  lui   $t7, %hi(mission_folder_setup_entries) 
  addiu $t7, %lo(mission_folder_setup_entries) # addiu $t7, $t7, -0x541c
  sll   $t6, $t6, 2
  addu  $v0, $t6, $t7
.L7F00BB3C:
  lw    $t8, 0x10($v0)
  beql  $t8, $zero, .L7F00BB54
   addiu $v1, $v1, -1
  jr    $ra
   move  $v0, $v1

  addiu $v1, $v1, -1
.L7F00BB54:
  bgez  $v1, .L7F00BB3C
   addiu $v0, $v0, -0x1c
.L7F00BB5C:
  li    $v0, -1
  jr    $ra
   nop   
");

asm(R"
glabel toggle_deletion_menu_for_folder
  sll   $t6, $a0, 2
  addiu $sp, $sp, -0x20
  subu  $t6, $t6, $a0
  lui   $t7, %hi(dword_CODE_bss_80069620) 
  sw    $ra, 0x14($sp)
  addiu $t7, %lo(dword_CODE_bss_80069620) # addiu $t7, $t7, -0x69e0
  sll   $t6, $t6, 2
  addu  $a0, $t6, $t7
  jal   sub_GAME_7F077FF4
   addiu $a1, $sp, 0x18
  li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f6
  lwc1  $f4, 0x18($sp)
  lui   $at, %hi(cursor_h_pos)
  lwc1  $f10, 0x1c($sp)
  add.s $f8, $f4, $f6
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  swc1  $f8, %lo(cursor_h_pos)($at)
  li    $at, 0x41A00000 # 20.000000
  mtc1  $at, $f16
  lui   $at, %hi(cursor_v_pos)
  add.s $f18, $f10, $f16
  jr    $ra
   swc1  $f18, %lo(cursor_v_pos)($at)
");

asm(R"
glabel interface_menu05_fileselect
  addiu $sp, $sp, -0x110
  sw    $ra, 0x44($sp)
  sw    $s3, 0x40($sp)
  sw    $s2, 0x3c($sp)
  sw    $s1, 0x38($sp)
  sw    $s0, 0x34($sp)
  sdc1  $f20, 0x28($sp)
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 65535
  bnez  $v0, .L7F00BC4C
   nop   
  jal   get_cur_controller_horz_stick_pos
   move  $a0, $zero
  slti  $at, $v0, -5
  bnez  $at, .L7F00BC4C
   nop   
  jal   get_cur_controller_horz_stick_pos
   move  $a0, $zero
  slti  $at, $v0, 6
  beqz  $at, .L7F00BC4C
   nop   
  jal   get_cur_controller_vert_stick_pos
   move  $a0, $zero
  slti  $at, $v0, -5
  bnez  $at, .L7F00BC4C
   nop   
  jal   get_cur_controller_vert_stick_pos
   move  $a0, $zero
  slti  $at, $v0, 6
  bnez  $at, .L7F00BC58
   lui   $t6, %hi(menu_timer) 
.L7F00BC4C:
  lui   $at, %hi(menu_timer)
  b     .L7F00BC70
   sw    $zero, %lo(menu_timer)($at)
.L7F00BC58:
  lui   $t7, %hi(clock_timer) 
  lw    $t7, %lo(clock_timer)($t7)
  lw    $t6, %lo(menu_timer)($t6)
  lui   $at, %hi(menu_timer)
  addu  $t8, $t6, $t7
  sw    $t8, %lo(menu_timer)($at)
.L7F00BC70:
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f12
  jal   setvideo_far
   nop   
  lui   $at, %hi(D_80051A1C)
  jal   video_related_21
   lwc1  $f12, %lo(D_80051A1C)($at)
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f12
  lui   $at, %hi(D_80051A20)
  jal   set_page_height
   lwc1  $f14, %lo(D_80051A20)($at)
  jal   set_video2_settings_offset_24
   move  $a0, $zero
  lui   $t9, %hi(D_8002AB94) 
  addiu $t9, %lo(D_8002AB94) # addiu $t9, $t9, -0x546c
  lui   $s0, %hi(ptr_folder_object_instance)
  lui   $s1, %hi(dword_CODE_bss_80069620)
  mtc1  $zero, $f20
  addiu $s1, %lo(dword_CODE_bss_80069620) # addiu $s1, $s1, -0x69e0
  addiu $s0, %lo(ptr_folder_object_instance) # addiu $s0, $s0, -0x56a4
  sw    $t9, 0x54($sp)
  move  $s2, $zero
  addiu $s3, $sp, 0x88
.L7F00BCD0:
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  mfc1  $a1, $f20
  mfc1  $a2, $f20
  addiu $a0, $sp, 0xc8
  lui   $a3, 0x457a
  swc1  $f20, 0x10($sp)
  swc1  $f20, 0x14($sp)
  swc1  $f20, 0x18($sp)
  swc1  $f20, 0x1c($sp)
  swc1  $f20, 0x24($sp)
  jal   sub_GAME_7F059694
   swc1  $f4, 0x20($sp)
  lw    $a0, 0x54($sp)
  jal   init_something_copy_posdata_to_it
   move  $a1, $s3
  lui   $at, %hi(D_80051A24)
  lwc1  $f12, %lo(D_80051A24)($at)
  jal   matrix_multiply_A1_by_F12
   move  $a1, $s3
  addiu $a0, $sp, 0xc8
  jal   matrix_4x4_multiply_in_place
   move  $a1, $s3
  lw    $t0, ($s0)
  lw    $t1, 8($t0)
  lh    $a0, 0xe($t1)
  sll   $t2, $a0, 6
  jal   sub_GAME_7F0BD714
   move  $a0, $t2
  lw    $t3, ($s0)
  move  $a0, $s3
  sw    $v0, 0xc($t3)
  lw    $t4, ($s0)
  jal   matrix_4x4_copy
   lw    $a1, 0xc($t4)
  lw    $a0, ($s0)
  lw    $t5, 0xc($a0)
  lwc1  $f6, 0x30($t5)
  swc1  $f6, ($s1)
  lw    $t6, 0xc($a0)
  lwc1  $f8, 0x34($t6)
  swc1  $f8, 4($s1)
  lw    $t7, 0xc($a0)
  lwc1  $f10, 0x38($t7)
  jal   disable_all_switches
   swc1  $f10, 8($s1)
  jal   removed_would_have_returned_bond_for_folder_num
   move  $a0, $s2
  lw    $a0, ($s0)
  jal   select_load_bond_picture
   move  $a1, $v0
  lw    $a0, ($s0)
  li    $a1, 14
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lw    $a0, ($s0)
  li    $a1, 13
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lw    $t8, 0x54($sp)
  addiu $s2, $s2, 1
  li    $at, 4
  addiu $t9, $t8, 0xc
  sw    $t9, 0x54($sp)
  addiu $s0, $s0, 4
  bne   $s2, $at, .L7F00BCD0
   addiu $s1, $s1, 0xc
  lui   $v0, %hi(selected_folder_num)
  addiu $v0, %lo(selected_folder_num) # addiu $v0, $v0, -0x5718
  lw    $a0, ($v0)
  li    $at, 100
  bltz  $a0, .L7F00BE30
   nop   
  bne   $a0, $at, .L7F00BE04
   lui   $t0, %hi(selected_folder_num_copy) 
  lw    $a0, %lo(selected_folder_num_copy)($t0)
  sw    $a0, ($v0)
.L7F00BE04:
  bltz  $a0, .L7F00BE14
   slti  $at, $a0, 4
  bnez  $at, .L7F00BE1C
   nop   
.L7F00BE14:
  sw    $zero, ($v0)
  move  $a0, $zero
.L7F00BE1C:
  jal   toggle_deletion_menu_for_folder
   nop   
  li    $s1, -1
  lui   $at, %hi(selected_folder_num)
  sw    $s1, %lo(selected_folder_num)($at)
.L7F00BE30:
  lui   $t1, %hi(folder_selected_for_deletion) 
  lw    $t1, %lo(folder_selected_for_deletion)($t1)
  li    $s1, -1
  move  $s2, $zero
  bltz  $t1, .L7F00BFEC
   lui   $s0, %hi(ptr_folder_object_instance)
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 546
  beqz  $v0, .L7F00BE90
   lui   $s0, %hi(folder_selected_for_deletion_choice)
  addiu $s0, %lo(folder_selected_for_deletion_choice) # addiu $s0, $s0, -0x56e0
  lw    $t2, ($s0)
  lui   $s3, %hi(ptr_sfx_buf)
  addiu $s3, %lo(ptr_sfx_buf) # addiu $s3, $s3, 0x3720
  bnez  $t2, .L7F00BE90
   li    $t3, 1
  sw    $t3, ($s0)
  lw    $a0, ($s3)
  li    $a1, 18
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F00BED0
   nop   
.L7F00BE90:
  lui   $s0, %hi(folder_selected_for_deletion_choice)
  addiu $s0, %lo(folder_selected_for_deletion_choice) # addiu $s0, $s0, -0x56e0
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 273
  beqz  $v0, .L7F00BED0
   nop   
  lw    $t4, ($s0)
  lui   $s3, %hi(ptr_sfx_buf)
  addiu $s3, %lo(ptr_sfx_buf) # addiu $s3, $s3, 0x3720
  beqz  $t4, .L7F00BED0
   li    $a1, 18
  sw    $zero, ($s0)
  lw    $a0, ($s3)
  jal   play_sfx_a1
   move  $a2, $zero
.L7F00BED0:
  lui   $s3, %hi(ptr_sfx_buf)
  addiu $s3, %lo(ptr_sfx_buf) # addiu $s3, $s3, 0x3720
  jal   get_cur_controller_horz_stick_pos
   move  $a0, $zero
  slti  $at, $v0, -0x2d
  beqz  $at, .L7F00BF14
   nop   
  lw    $t5, ($s0)
  li    $t6, 1
  li    $a1, 18
  bnez  $t5, .L7F00BF14
   move  $a2, $zero
  sw    $t6, ($s0)
  jal   play_sfx_a1
   lw    $a0, ($s3)
  b     .L7F00BF4C
   move  $a0, $zero
.L7F00BF14:
  jal   get_cur_controller_horz_stick_pos
   move  $a0, $zero
  slti  $at, $v0, 0x2e
  bnezl $at, .L7F00BF4C
   move  $a0, $zero
  lw    $t7, ($s0)
  li    $a1, 18
  move  $a2, $zero
  beql  $t7, $zero, .L7F00BF4C
   move  $a0, $zero
  sw    $zero, ($s0)
  jal   play_sfx_a1
   lw    $a0, ($s3)
  move  $a0, $zero
.L7F00BF4C:
  jal   get_controller_buttons_pressed
   li    $a1, 45056
  beql  $v0, $zero, .L7F00BFB4
   move  $a0, $zero
  lw    $t8, ($s0)
  lui   $a0, %hi(folder_selected_for_deletion)
  li    $a1, 118
  bnez  $t8, .L7F00BF90
   move  $a2, $zero
  jal   delete_eeprom_folder
   lw    $a0, %lo(folder_selected_for_deletion)($a0)
  lw    $a0, ($s3)
  li    $a1, 118
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F00BF98
   nop   
.L7F00BF90:
  jal   play_sfx_a1
   lw    $a0, ($s3)
.L7F00BF98:
  lui   $a0, %hi(folder_selected_for_deletion)
  jal   toggle_deletion_menu_for_folder
   lw    $a0, %lo(folder_selected_for_deletion)($a0)
  lui   $at, %hi(folder_selected_for_deletion)
  b     .L7F00C31C
   sw    $s1, %lo(folder_selected_for_deletion)($at)
  move  $a0, $zero
.L7F00BFB4:
  jal   get_controller_buttons_pressed
   li    $a1, 16384
  beqz  $v0, .L7F00C31C
   lui   $a0, %hi(folder_selected_for_deletion)
  jal   toggle_deletion_menu_for_folder
   lw    $a0, %lo(folder_selected_for_deletion)($a0)
  lui   $at, %hi(folder_selected_for_deletion)
  sw    $s1, %lo(folder_selected_for_deletion)($at)
  lw    $a0, ($s3)
  li    $a1, 118
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F00C31C
   nop   
.L7F00BFEC:
  lui   $s1, %hi(dword_CODE_bss_80069620)
  addiu $s1, %lo(dword_CODE_bss_80069620) # addiu $s1, $s1, -0x69e0
  addiu $s0, $s0, %lo(ptr_folder_object_instance)
  addiu $s3, $sp, 0x7c
.L7F00BFFC:
  addiu $t9, $sp, 0x74
  sw    $t9, 0x10($sp)
  lw    $a0, ($s0)
  addiu $a1, $sp, 0x80
  move  $a2, $s3
  jal   sub_GAME_7F03F90C
   addiu $a3, $sp, 0x78
  addiu $t0, $sp, 0x64
  sw    $t0, 0x10($sp)
  move  $a0, $s1
  move  $a1, $s3
  addiu $a2, $sp, 0x74
  jal   sub_GAME_7F03F948
   addiu $a3, $sp, 0x6c
  lui   $at, %hi(cursor_h_pos)
  lwc1  $f2, %lo(cursor_h_pos)($at)
  lwc1  $f16, 0x6c($sp)
  lwc1  $f18, 0x64($sp)
  c.le.s $f16, $f2
  nop   
  bc1fl .L7F00C188
   addiu $s2, $s2, 1
  c.le.s $f2, $f18
  lui   $at, %hi(cursor_v_pos)
  lwc1  $f4, 0x70($sp)
  bc1fl .L7F00C188
   addiu $s2, $s2, 1
  lwc1  $f0, %lo(cursor_v_pos)($at)
  lwc1  $f6, 0x68($sp)
  c.le.s $f4, $f0
  nop   
  bc1fl .L7F00C188
   addiu $s2, $s2, 1
  c.le.s $f0, $f6
  move  $a0, $s2
  addiu $a1, $sp, 0x60
  bc1fl .L7F00C188
   addiu $s2, $s2, 1
  jal   get_highest_stage_difficulty_completed_in_folder
   addiu $a2, $sp, 0x5c
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 45056
  beql  $v0, $zero, .L7F00C188
   addiu $s2, $s2, 1
  lui   $s1, %hi(folder_selection_screen_option_icon)
  addiu $s1, %lo(folder_selection_screen_option_icon) # addiu $s1, $s1, -0x56e8
  lw    $v0, ($s1)
  lui   $s3, %hi(ptr_sfx_buf)
  addiu $s3, %lo(ptr_sfx_buf) # addiu $s3, $s3, 0x3720
  bnez  $v0, .L7F00C0EC
   lui   $at, %hi(selected_folder_num)
  sw    $s2, %lo(selected_folder_num)($at)
  lw    $a0, ($s3)
  li    $a1, 77
  jal   play_sfx_a1
   move  $a2, $zero
  lui   $s3, %hi(ptr_sfx_buf)
  b     .L7F00C1A8
   addiu $s3, %lo(ptr_sfx_buf) # addiu $s3, $s3, 0x3720
.L7F00C0EC:
  li    $at, 1
  bnel  $v0, $at, .L7F00C12C
   li    $at, 2
  jal   sub_GAME_7F01EDA0
   move  $a0, $s2
  lui   $s3, %hi(ptr_sfx_buf)
  addiu $s3, %lo(ptr_sfx_buf) # addiu $s3, $s3, 0x3720
  sw    $zero, ($s1)
  lw    $a0, ($s3)
  li    $a1, 79
  jal   play_sfx_a1
   move  $a2, $zero
  lui   $s3, %hi(ptr_sfx_buf)
  b     .L7F00C1A8
   addiu $s3, %lo(ptr_sfx_buf) # addiu $s3, $s3, 0x3720
  li    $at, 2
.L7F00C12C:
  bne   $v0, $at, .L7F00C178
   nop   
  lw    $t1, 0x60($sp)
  lui   $s3, %hi(ptr_sfx_buf)
  addiu $s3, %lo(ptr_sfx_buf) # addiu $s3, $s3, 0x3720
  bltz  $t1, .L7F00C168
   li    $a1, 18
  lw    $t2, 0x5c($sp)
  lui   $s0, %hi(folder_selected_for_deletion_choice)
  addiu $s0, %lo(folder_selected_for_deletion_choice) # addiu $s0, $s0, -0x56e0
  bltz  $t2, .L7F00C168
   lui   $at, %hi(folder_selected_for_deletion)
  sw    $s2, %lo(folder_selected_for_deletion)($at)
  li    $t3, 1
  sw    $t3, ($s0)
.L7F00C168:
  sw    $zero, ($s1)
  lw    $a0, ($s3)
  jal   play_sfx_a1
   move  $a2, $zero
.L7F00C178:
  lui   $s3, %hi(ptr_sfx_buf)
  b     .L7F00C1A8
   addiu $s3, %lo(ptr_sfx_buf) # addiu $s3, $s3, 0x3720
  addiu $s2, $s2, 1
.L7F00C188:
  li    $at, 4
  addiu $s0, $s0, 4
  bne   $s2, $at, .L7F00BFFC
   addiu $s1, $s1, 0xc
  lui   $s3, %hi(ptr_sfx_buf)
  lui   $s1, %hi(folder_selection_screen_option_icon)
  addiu $s1, %lo(folder_selection_screen_option_icon) # addiu $s1, $s1, -0x56e8
  addiu $s3, %lo(ptr_sfx_buf) # addiu $s3, $s3, 0x3720
.L7F00C1A8:
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 45056
  beqz  $v0, .L7F00C2E0
   lui   $v0, %hi(folder_option_COPY_left_bound)
  addiu $v0, %lo(folder_option_COPY_left_bound) # addiu $v0, $v0, -0x543c
  lui   $at, %hi(cursor_h_pos)
  lwc1  $f2, %lo(cursor_h_pos)($at)
  lwc1  $f8, ($v0)
  c.le.s $f8, $f2
  nop   
  bc1f  .L7F00C23C
   nop   
  lwc1  $f10, 8($v0)
  lui   $at, %hi(cursor_v_pos)
  c.le.s $f2, $f10
  nop   
  bc1f  .L7F00C23C
   nop   
  lwc1  $f0, %lo(cursor_v_pos)($at)
  lwc1  $f16, 4($v0)
  c.le.s $f16, $f0
  nop   
  bc1f  .L7F00C23C
   nop   
  lwc1  $f18, 0xc($v0)
  li    $t4, 1
  li    $a1, 222
  c.le.s $f0, $f18
  move  $a2, $zero
  bc1f  .L7F00C23C
   nop   
  sw    $t4, ($s1)
  jal   play_sfx_a1
   lw    $a0, ($s3)
  b     .L7F00C314
   nop   
.L7F00C23C:
  lui   $v0, %hi(folder_option_ERASE_left_bound)
  addiu $v0, %lo(folder_option_ERASE_left_bound) # addiu $v0, $v0, -0x542c
  lwc1  $f4, ($v0)
  c.le.s $f4, $f2
  nop   
  bc1fl .L7F00C2BC
   lw    $t6, ($s1)
  lwc1  $f6, 8($v0)
  lui   $at, %hi(cursor_v_pos)
  c.le.s $f2, $f6
  nop   
  bc1fl .L7F00C2BC
   lw    $t6, ($s1)
  lwc1  $f0, %lo(cursor_v_pos)($at)
  lwc1  $f8, 4($v0)
  c.le.s $f8, $f0
  nop   
  bc1fl .L7F00C2BC
   lw    $t6, ($s1)
  lwc1  $f10, 0xc($v0)
  li    $t5, 2
  li    $a1, 222
  c.le.s $f0, $f10
  move  $a2, $zero
  bc1fl .L7F00C2BC
   lw    $t6, ($s1)
  sw    $t5, ($s1)
  jal   play_sfx_a1
   lw    $a0, ($s3)
  b     .L7F00C314
   nop   
  lw    $t6, ($s1)
.L7F00C2BC:
  li    $a1, 118
  move  $a2, $zero
  beqz  $t6, .L7F00C314
   nop   
  sw    $zero, ($s1)
  jal   play_sfx_a1
   lw    $a0, ($s3)
  b     .L7F00C314
   nop   
.L7F00C2E0:
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 16384
  beqz  $v0, .L7F00C314
   nop   
  lw    $t7, ($s1)
  li    $a1, 118
  move  $a2, $zero
  beqz  $t7, .L7F00C314
   nop   
  sw    $zero, ($s1)
  jal   play_sfx_a1
   lw    $a0, ($s3)
.L7F00C314:
  jal   menu_control_stick_tracking
   nop   
.L7F00C31C:
  lui   $t8, %hi(selected_folder_num) 
  lw    $t8, %lo(selected_folder_num)($t8)
  bltz  $t8, .L7F00C344
   li    $a0, 6
  jal   set_menu_to_mode
   move  $a1, $zero
  jal   set_menu_cursor_pos_to_setting
   move  $a0, $zero
  b     .L7F00C368
   lw    $ra, 0x44($sp)
.L7F00C344:
  lui   $t9, %hi(menu_timer) 
  lw    $t9, %lo(menu_timer)($t9)
  move  $a0, $zero
  slti  $at, $t9, 0x709
  bnezl $at, .L7F00C368
   lw    $ra, 0x44($sp)
  jal   set_menu_to_mode
   li    $a1, 1
  lw    $ra, 0x44($sp)
.L7F00C368:
  ldc1  $f20, 0x28($sp)
  lw    $s0, 0x34($sp)
  lw    $s1, 0x38($sp)
  lw    $s2, 0x3c($sp)
  lw    $s3, 0x40($sp)
  jr    $ra
   addiu $sp, $sp, 0x110
");

asm(R"
glabel get_ptr_difficulty_name
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  beqz  $a0, .L7F00C3B8
   move  $v1, $zero
  li    $at, 1
  beq   $a0, $at, .L7F00C3C8
   li    $at, 2
  beq   $a0, $at, .L7F00C3D8
   li    $at, 3
  beq   $a0, $at, .L7F00C3E8
   nop   
  b     .L7F00C3F8
   lw    $ra, 0x14($sp)
.L7F00C3B8:
  jal   get_textptr_for_textID
   li    $a0, 39955
  b     .L7F00C3F4
   move  $v1, $v0
.L7F00C3C8:
  jal   get_textptr_for_textID
   li    $a0, 39956
  b     .L7F00C3F4
   move  $v1, $v0
.L7F00C3D8:
  jal   get_textptr_for_textID
   li    $a0, 39957
  b     .L7F00C3F4
   move  $v1, $v0
.L7F00C3E8:
  jal   get_textptr_for_textID
   li    $a0, 39958
  move  $v1, $v0
.L7F00C3F4:
  lw    $ra, 0x14($sp)
.L7F00C3F8:
  addiu $sp, $sp, 0x18
  move  $v0, $v1
  jr    $ra
   nop   
");

asm(R"
glabel constructor_menu05_fileselect
  addiu $sp, $sp, -0x1b8
  lui   $t6, %hi(unknown_folderselect_constructor) 
  sw    $ra, 0x64($sp)
  sw    $fp, 0x60($sp)
  sw    $s7, 0x5c($sp)
  sw    $s6, 0x58($sp)
  sw    $s5, 0x54($sp)
  sw    $s4, 0x50($sp)
  sw    $s3, 0x4c($sp)
  sw    $s2, 0x48($sp)
  sw    $s1, 0x44($sp)
  sw    $s0, 0x40($sp)
  sw    $a0, 0x1b8($sp)
  addiu $t6, %lo(unknown_folderselect_constructor) # addiu $t6, $t6, -0x50d4
  lw    $at, ($t6)
  addiu $s0, $sp, 0x1a8
  lui   $t0, %hi(unknown_folderselect_constructor_0) 
  sw    $at, ($s0)
  lw    $t9, 4($t6)
  addiu $t0, %lo(unknown_folderselect_constructor_0) # addiu $t0, $t0, -0x50c8
  addiu $s1, $sp, 0x19c
  sw    $t9, 4($s0)
  lw    $at, 8($t6)
  sw    $at, 8($s0)
  lw    $at, ($t0)
  sw    $at, ($s1)
  lw    $t3, 4($t0)
  sw    $t3, 4($s1)
  lw    $at, 8($t0)
  sw    $at, 8($s1)
  jal   insert_imageDL
   lw    $a0, 0x1b8($sp)
  addiu $t4, $v0, 8
  sw    $t4, 0x1b8($sp)
  lui   $t5, (0xFC167E2C >> 16) # lui $t5, 0xfc16
  lui   $t8, (0x33FDF6FB >> 16) # lui $t8, 0x33fd
  ori   $t8, (0x33FDF6FB & 0xFFFF) # ori $t8, $t8, 0xf6fb
  ori   $t5, (0xFC167E2C & 0xFFFF) # ori $t5, $t5, 0x7e2c
  sw    $t5, ($v0)
  sw    $t8, 4($v0)
  lw    $t7, 0x1b8($sp)
  lui   $t9, %hi(0xFB00000C) # $t9, 0xfb00
  li    $t2, -236
  addiu $t6, $t7, 8
  sw    $t6, 0x1b8($sp)
  sw    $t2, 4($t7)
  jal   get_video2_settings_txtClipW
   sw    $t9, ($t7)
  mtc1  $v0, $f4
  li    $at, 0xC2A00000 # -80.000000
  mtc1  $at, $f8
  cvt.s.w $f6, $f4
  li    $at, 0x44A00000 # 1280.000000
  mtc1  $at, $f16
  mul.s $f10, $f6, $f8
  jal   truncf
   div.s $f12, $f10, $f16
  trunc.w.s $f18, $f0
  lw    $a0, 0x1b8($sp)
  move  $a2, $s0
  move  $a3, $s1
  mfc1  $a1, $f18
  jal   sub_GAME_7F007CC8
   nop   
  addiu $t0, $v0, 8
  sw    $t0, 0x1b8($sp)
  lui   $t3, 0x100
  lui   $a1, 0x600
  addiu $t3, $t3, 0
  sw    $t3, 4($v0)
  sw    $a1, ($v0)
  lw    $t4, 0x1b8($sp)
  lui   $t8, 0x100
  addiu $t8, $t8, 0x40
  addiu $t5, $t4, 8
  sw    $t5, 0x1b8($sp)
  lui   $s2, %hi(D_8002A968)
  lui   $s4, %hi(unknown_folderselect)
  addiu $s4, %lo(unknown_folderselect) # addiu $s4, $s4, -0x50bc
  addiu $s2, %lo(D_8002A968) # addiu $s2, $s2, -0x5698
  addiu $s3, $sp, 0x108
  sw    $t8, 4($t4)
  sw    $a1, ($t4)
  addiu $a0, $sp, 0x14c
.L7F00C558:
  move  $t2, $a0
  move  $t9, $s4
  addiu $t6, $s4, 0x3c
.L7F00C564:
  lw    $at, ($t9)
  addiu $t9, %lo(0xFB00000C) # addiu $t9, $t9, 0xc
  addiu $t2, $t2, 0xc
  sw    $at, -0xc($t2)
  lw    $at, -8($t9)
  sw    $at, -8($t2)
  lw    $at, -4($t9)
  bne   $t9, $t6, .L7F00C564
   sw    $at, -4($t2)
  lw    $at, ($t9)
  li    $t1, 3
  move  $s1, $zero
  sw    $at, ($t2)
  lw    $t0, 0x1b8($sp)
  sw    $t1, 0x154($sp)
  sw    $zero, 0x150($sp)
  lw    $a1, ($s2)
  jal   subdraw
   sw    $t0, 0x158($sp)
  lw    $t3, 0x158($sp)
  lw    $v0, ($s2)
  move  $s0, $zero
  sw    $t3, 0x1b8($sp)
  lw    $t4, 8($v0)
  lh    $t5, 0xe($t4)
  blez  $t5, .L7F00C618
   nop   
  lw    $t8, 0xc($v0)
.L7F00C5D4:
  move  $a1, $s3
  jal   matrix_4x4_copy
   addu  $a0, $t8, $s0
  lw    $t7, ($s2)
  sll   $t9, $s1, 6
  move  $a0, $s3
  lw    $t6, 0xc($t7)
  jal   sub_GAME_7F058C9C
   addu  $a1, $t6, $t9
  lw    $v0, ($s2)
  addiu $s1, $s1, 1
  addiu $s0, $s0, 0x40
  lw    $t2, 8($v0)
  lh    $t1, 0xe($t2)
  slt   $at, $s1, $t1
  bnezl $at, .L7F00C5D4
   lw    $t8, 0xc($v0)
.L7F00C618:
  lui   $t0, %hi(ptr_folder_object_instance) 
  addiu $t0, %lo(ptr_folder_object_instance) # addiu $t0, $t0, -0x56a4
  addiu $s2, $s2, -4
  sltu  $at, $s2, $t0
  beql  $at, $zero, .L7F00C558
   addiu $a0, $sp, 0x14c
  jal   microcode_constructor
   lw    $a0, 0x1b8($sp)
  sw    $v0, 0x1b8($sp)
  jal   setTextSpacingInverted
   move  $a0, $zero
  lui   $t3, %hi(dword_CODE_bss_80069620) 
  addiu $t3, %lo(dword_CODE_bss_80069620) # addiu $t3, $t3, -0x69e0
  lui   $fp, (0xEBD879FF >> 16) # lui $fp, 0xebd8
  lui   $s4, %hi(ptrFirstFontTableLarge)
  lui   $s3, %hi(ptrSecondFontTableLarge)
  addiu $s3, %lo(ptrSecondFontTableLarge) # addiu $s3, $s3, 0xeb8
  addiu $s4, %lo(ptrFirstFontTableLarge) # addiu $s4, $s4, 0xeb4
  ori   $fp, (0xEBD879FF & 0xFFFF) # ori $fp, $fp, 0x79ff
  sw    $t3, 0x74($sp)
  sw    $zero, 0x1b4($sp)
  addiu $s7, $sp, 0xfc
  addiu $s6, $sp, 0x100
  addiu $s5, $sp, 0xbc
.L7F00C678:
  lw    $a0, 0x74($sp)
  jal   sub_GAME_7F077FF4
   addiu $a1, $sp, 0xe4
  lui   $t4, %hi(folder_selected_for_deletion) 
  lw    $a0, 0x1b4($sp)
  lw    $t4, %lo(folder_selected_for_deletion)($t4)
  addiu $a1, $sp, 0xf0
  bne   $a0, $t4, .L7F00CA60
   nop   
  jal   truncf
   lwc1  $f12, 0xe4($sp)
  trunc.w.s $f4, $f0
  lwc1  $f12, 0xe8($sp)
  mfc1  $s2, $f4
  nop   
  addiu $s2, $s2, -0x31
  jal   truncf
   sw    $s2, 0x100($sp)
  trunc.w.s $f6, $f0
  lw    $a1, 0x100($sp)
  li    $t6, 50
  sw    $t6, 0x14($sp)
  mfc1  $s0, $f6
  lw    $a0, 0x1b8($sp)
  addiu $a3, $a1, 0x63
  addiu $a2, $s0, 0x19
  addiu $t7, $a2, 0x2a
  sw    $t7, 0x10($sp)
  jal   microcode_constructor_related_to_menus
   sw    $a2, 0xfc($sp)
  sw    $v0, 0x1b8($sp)
  jal   get_textptr_for_textID
   li    $a0, 39959
  move  $s1, $v0
  jal   truncf
   lwc1  $f12, 0xe4($sp)
  trunc.w.s $f8, $f0
  lwc1  $f12, 0xe8($sp)
  mfc1  $s2, $f8
  nop   
  addiu $s2, $s2, -0x2f
  jal   truncf
   sw    $s2, 0x100($sp)
  trunc.w.s $f10, $f0
  mfc1  $s0, $f10
  nop   
  addiu $s0, $s0, 0x1e
  jal   get_video2_settings_txtClipW
   sw    $s0, 0xfc($sp)
  sll   $s0, $v0, 0x10
  sra   $t1, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t1
  lw    $t0, ($s3)
  lw    $t3, ($s4)
  lw    $a0, 0x1b8($sp)
  move  $a1, $s6
  move  $a2, $s7
  move  $a3, $s1
  sw    $fp, 0x18($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t0, 0x10($sp)
  jal   en_text_write_stuff
   sw    $t3, 0x14($sp)
  sw    $v0, 0x1b8($sp)
  jal   get_textptr_for_textID
   li    $a0, 39960
  move  $s1, $v0
  jal   truncf
   lwc1  $f12, 0xe4($sp)
  trunc.w.s $f16, $f0
  lwc1  $f12, 0xe8($sp)
  mfc1  $s2, $f16
  nop   
  addiu $s2, $s2, -0x2f
  jal   truncf
   sw    $s2, 0x100($sp)
  trunc.w.s $f18, $f0
  lui   $t8, %hi(folder_selected_for_deletion_choice) 
  lw    $t8, %lo(folder_selected_for_deletion_choice)($t8)
  addiu $a0, $sp, 0xf8
  mfc1  $s0, $f18
  addiu $a1, $sp, 0xf4
  move  $a2, $s1
  addiu $s0, $s0, 0x32
  beqz  $t8, .L7F00C890
   sw    $s0, 0xfc($sp)
  lw    $t7, ($s4)
  sw    $zero, 0xf4($sp)
  sw    $zero, 0xf8($sp)
  lw    $a3, ($s3)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t7, 0x10($sp)
  lw    $s0, 0xfc($sp)
  lw    $s2, 0x100($sp)
  lw    $t6, 0xf4($sp)
  lw    $t9, 0xf8($sp)
  li    $t1, 50
  addu  $a3, $s2, $t6
  addu  $t2, $s0, $t9
  sw    $t2, 0x10($sp)
  addiu $a3, $a3, 3
  sw    $t1, 0x14($sp)
  lw    $a0, 0x1b8($sp)
  addiu $a2, $s0, -1
  jal   microcode_constructor_related_to_menus
   addiu $a1, $s2, -1
  jal   get_video2_settings_txtClipW
   sw    $v0, 0x1b8($sp)
  sll   $s0, $v0, 0x10
  sra   $t0, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t0
  lw    $t3, ($s3)
  lw    $t4, ($s4)
  li    $t5, -1
  sw    $t5, 0x18($sp)
  lw    $a0, 0x1b8($sp)
  move  $a1, $s6
  move  $a2, $s7
  move  $a3, $s1
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t3, 0x10($sp)
  jal   en_text_write_stuff
   sw    $t4, 0x14($sp)
  b     .L7F00C8E4
   sw    $v0, 0x1b8($sp)
.L7F00C890:
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s0, $v0, 0x10
  sra   $t8, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t8
  lw    $t7, ($s3)
  lw    $t6, ($s4)
  lw    $a0, 0x1b8($sp)
  move  $a1, $s6
  move  $a2, $s7
  move  $a3, $s1
  sw    $fp, 0x18($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t7, 0x10($sp)
  jal   en_text_write_stuff
   sw    $t6, 0x14($sp)
  sw    $v0, 0x1b8($sp)
.L7F00C8E4:
  jal   get_textptr_for_textID
   li    $a0, 39961
  move  $s1, $v0
  jal   truncf
   lwc1  $f12, 0xe4($sp)
  lui   $t9, %hi(j_text_trigger) 
  lw    $t9, %lo(j_text_trigger)($t9)
  mov.s $f2, $f0
  trunc.w.s $f4, $f2
  beqz  $t9, .L7F00C918
   li    $v0, -1
  b     .L7F00C918
   li    $v0, 23
.L7F00C918:
  mfc1  $t1, $f4
  lwc1  $f12, 0xe8($sp)
  addu  $s2, $v0, $t1
  addiu $s2, $s2, -1
  jal   truncf
   sw    $s2, 0x100($sp)
  trunc.w.s $f6, $f0
  lui   $t3, %hi(folder_selected_for_deletion_choice) 
  lw    $t3, %lo(folder_selected_for_deletion_choice)($t3)
  addiu $a0, $sp, 0xf8
  mfc1  $s0, $f6
  addiu $a1, $sp, 0xf4
  move  $a2, $s1
  addiu $s0, $s0, 0x32
  beqz  $t3, .L7F00C9B0
   sw    $s0, 0xfc($sp)
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s0, $v0, 0x10
  sra   $t4, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t4
  lw    $t5, ($s3)
  lw    $t8, ($s4)
  lw    $a0, 0x1b8($sp)
  move  $a1, $s6
  move  $a2, $s7
  move  $a3, $s1
  sw    $fp, 0x18($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t5, 0x10($sp)
  jal   en_text_write_stuff
   sw    $t8, 0x14($sp)
  b     .L7F00CD04
   sw    $v0, 0x1b8($sp)
.L7F00C9B0:
  lw    $t7, ($s4)
  sw    $zero, 0xf4($sp)
  sw    $zero, 0xf8($sp)
  lw    $a3, ($s3)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t7, 0x10($sp)
  lw    $s0, 0xfc($sp)
  lw    $s2, 0x100($sp)
  lw    $t6, 0xf4($sp)
  lw    $t9, 0xf8($sp)
  li    $t1, 50
  addu  $a3, $s2, $t6
  addu  $t2, $s0, $t9
  sw    $t2, 0x10($sp)
  addiu $a3, $a3, 3
  sw    $t1, 0x14($sp)
  lw    $a0, 0x1b8($sp)
  addiu $a2, $s0, -1
  jal   microcode_constructor_related_to_menus
   addiu $a1, $s2, -1
  jal   get_video2_settings_txtClipW
   sw    $v0, 0x1b8($sp)
  sll   $s0, $v0, 0x10
  sra   $t0, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t0
  lw    $t3, ($s3)
  lw    $t4, ($s4)
  li    $t5, -1
  sw    $t5, 0x18($sp)
  lw    $a0, 0x1b8($sp)
  move  $a1, $s6
  move  $a2, $s7
  move  $a3, $s1
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t3, 0x10($sp)
  jal   en_text_write_stuff
   sw    $t4, 0x14($sp)
  b     .L7F00CD04
   sw    $v0, 0x1b8($sp)
.L7F00CA60:
  jal   get_highest_stage_difficulty_completed_in_folder
   addiu $a2, $sp, 0xec
  lw    $v0, 0xf0($sp)
  lw    $a0, 0xec($sp)
  bltzl $v0, .L7F00CD08
   lw    $t1, 0x1b4($sp)
  bltzl $a0, .L7F00CD08
   lw    $t1, 0x1b4($sp)
  jal   get_ptr_difficulty_name
   nop   
  beqz  $v0, .L7F00CB6C
   addiu $a0, $sp, 0xd0
  jal   textpointer_load_parse_something
   move  $a1, $v0
  lui   $a1, %hi(asc_D_8004F488)
  addiu $a1, %lo(asc_D_8004F488) # addiu $a1, $a1, -0xb78
  jal   string_append_from_obseg_textbank
   addiu $a0, $sp, 0xd0
  lw    $t8, ($s4)
  sw    $zero, 0xf4($sp)
  sw    $zero, 0xf8($sp)
  addiu $a0, $sp, 0xf8
  addiu $a1, $sp, 0xf4
  addiu $a2, $sp, 0xd0
  lw    $a3, ($s3)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t8, 0x10($sp)
  jal   truncf
   lwc1  $f12, 0xe4($sp)
  trunc.w.s $f8, $f0
  lw    $t9, 0xf4($sp)
  lwc1  $f12, 0xe8($sp)
  mfc1  $t6, $f8
  bgez  $t9, .L7F00CAF8
   sra   $t2, $t9, 1
  addiu $at, $t9, 1
  sra   $t2, $at, 1
.L7F00CAF8:
  subu  $s2, $t6, $t2
  addiu $s2, $s2, -1
  jal   truncf
   sw    $s2, 0x100($sp)
  trunc.w.s $f10, $f0
  mfc1  $s0, $f10
  nop   
  addiu $s0, $s0, 0x15
  jal   get_video2_settings_txtClipW
   sw    $s0, 0xfc($sp)
  sll   $s0, $v0, 0x10
  sra   $t0, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t0
  lw    $t3, ($s3)
  lw    $t4, ($s4)
  lw    $a0, 0x1b8($sp)
  move  $a1, $s6
  move  $a2, $s7
  addiu $a3, $sp, 0xd0
  sw    $fp, 0x18($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t3, 0x10($sp)
  jal   en_text_write_stuff
   sw    $t4, 0x14($sp)
  sw    $v0, 0x1b8($sp)
.L7F00CB6C:
  lw    $a0, 0xec($sp)
  li    $at, 3
  li    $s2, -1
  beq   $a0, $at, .L7F00CD04
   move  $s1, $zero
  jal   get_textptr_for_textID
   li    $a0, 39962
  move  $a0, $s5
  jal   textpointer_load_parse_something
   move  $a1, $v0
  lui   $t5, %hi(mission_folder_setup_entries+0x4) 
  lhu   $t5, %lo(mission_folder_setup_entries+0x4)($t5)
  lui   $s0, %hi(mission_folder_setup_entries)
  addiu $s0, %lo(mission_folder_setup_entries) # addiu $s0, $s0, -0x541c
  beqz  $t5, .L7F00CBDC
   lw    $v0, 0xf0($sp)
  lw    $t8, 0x14($s0)
.L7F00CBB0:
  bnel  $v0, $t8, .L7F00CBCC
   lhu   $t7, 0x20($s0)
  jal   get_chapter_briefing_entry
   move  $a0, $s1
  b     .L7F00CBDC
   move  $s2, $v0
  lhu   $t7, 0x20($s0)
.L7F00CBCC:
  addiu $s1, $s1, 1
  addiu $s0, $s0, 0x1c
  bnezl $t7, .L7F00CBB0
   lw    $t8, 0x14($s0)
.L7F00CBDC:
  sll   $t9, $s1, 3
  subu  $t9, $t9, $s1
  lui   $t6, %hi(mission_folder_setup_entries) 
  addiu $t6, %lo(mission_folder_setup_entries) # addiu $t6, $t6, -0x541c
  sll   $t9, $t9, 2
  bltz  $s2, .L7F00CC24
   addu  $s0, $t9, $t6
  sll   $t2, $s2, 3
  subu  $t2, $t2, $s2
  sll   $t2, $t2, 2
  addu  $t1, $t2, $t6
  lw    $a1, ($t1)
  jal   string_append_from_obseg_textbank
   move  $a0, $s5
  lui   $a1, %hi(a_)
  addiu $a1, %lo(a_) # addiu $a1, $a1, -0xb74
  jal   string_append_from_obseg_textbank
   move  $a0, $s5
.L7F00CC24:
  move  $a0, $s5
  jal   string_append_from_obseg_textbank
   lw    $a1, ($s0)
  lui   $a1, %hi(asc_D_8004F490)
  addiu $a1, %lo(asc_D_8004F490) # addiu $a1, $a1, -0xb70
  jal   string_append_from_obseg_textbank
   move  $a0, $s5
  lw    $t0, ($s4)
  sw    $zero, 0xf4($sp)
  sw    $zero, 0xf8($sp)
  addiu $a0, $sp, 0xf8
  addiu $a1, $sp, 0xf4
  move  $a2, $s5
  lw    $a3, ($s3)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t0, 0x10($sp)
  jal   truncf
   lwc1  $f12, 0xe4($sp)
  trunc.w.s $f16, $f0
  lw    $t5, 0xf4($sp)
  lwc1  $f12, 0xe8($sp)
  mfc1  $t4, $f16
  bgez  $t5, .L7F00CC90
   sra   $t8, $t5, 1
  addiu $at, $t5, 1
  sra   $t8, $at, 1
.L7F00CC90:
  subu  $s2, $t4, $t8
  addiu $s2, $s2, -1
  jal   truncf
   sw    $s2, 0x100($sp)
  trunc.w.s $f18, $f0
  mfc1  $s0, $f18
  nop   
  addiu $s0, $s0, 0x2d
  jal   get_video2_settings_txtClipW
   sw    $s0, 0xfc($sp)
  sll   $s0, $v0, 0x10
  sra   $t9, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t9
  lw    $t2, ($s3)
  lw    $t6, ($s4)
  lw    $a0, 0x1b8($sp)
  move  $a1, $s6
  move  $a2, $s7
  move  $a3, $s5
  sw    $fp, 0x18($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t2, 0x10($sp)
  jal   en_text_write_stuff
   sw    $t6, 0x14($sp)
  sw    $v0, 0x1b8($sp)
.L7F00CD04:
  lw    $t1, 0x1b4($sp)
.L7F00CD08:
  lw    $t3, 0x74($sp)
  li    $at, 4
  addiu $t0, $t1, 1
  addiu $t5, $t3, 0xc
  sw    $t5, 0x74($sp)
  bne   $t0, $at, .L7F00C678
   sw    $t0, 0x1b4($sp)
  jal   setTextSpacingInverted
   move  $a0, $zero
  jal   get_textptr_for_textID
   li    $a0, 39963
  lw    $t4, ($s4)
  move  $s1, $v0
  sw    $zero, 0xf4($sp)
  sw    $zero, 0xf8($sp)
  addiu $a0, $sp, 0xf8
  addiu $a1, $sp, 0xf4
  move  $a2, $v0
  lw    $a3, ($s3)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t4, 0x10($sp)
  lw    $t8, 0xf8($sp)
  li    $fp, 285
  li    $s2, 247
  bgez  $t8, .L7F00CD7C
   sra   $t7, $t8, 1
  addiu $at, $t8, 1
  sra   $t7, $at, 1
.L7F00CD7C:
  subu  $s0, $fp, $t7
  sw    $s0, 0xfc($sp)
  jal   get_video2_settings_txtClipW
   sw    $s2, 0x100($sp)
  sll   $s0, $v0, 0x10
  sra   $t9, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t9
  lw    $t2, ($s3)
  lw    $t6, ($s4)
  li    $t1, -1
  sw    $t1, 0x18($sp)
  lw    $a0, 0x1b8($sp)
  move  $a1, $s6
  move  $a2, $s7
  move  $a3, $s1
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t2, 0x10($sp)
  jal   en_text_write_stuff
   sw    $t6, 0x14($sp)
  lw    $s2, 0x100($sp)
  lw    $t3, 0xf4($sp)
  lui   $s5, %hi(folder_option_COPY_left_bound)
  addiu $s5, %lo(folder_option_COPY_left_bound) # addiu $s5, $s5, -0x543c
  addu  $t5, $s2, $t3
  mtc1  $t5, $f4
  sw    $v0, 0x1b8($sp)
  li    $a0, 39964
  cvt.s.w $f6, $f4
  jal   get_textptr_for_textID
   swc1  $f6, 8($s5)
  lw    $t0, ($s4)
  move  $s1, $v0
  sw    $zero, 0xf4($sp)
  sw    $zero, 0xf8($sp)
  addiu $a0, $sp, 0xf8
  addiu $a1, $sp, 0xf4
  move  $a2, $v0
  lw    $a3, ($s3)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t0, 0x10($sp)
  lw    $t4, 0xf8($sp)
  li    $s2, 357
  sw    $s2, 0x100($sp)
  bgez  $t4, .L7F00CE4C
   sra   $t8, $t4, 1
  addiu $at, $t4, 1
  sra   $t8, $at, 1
.L7F00CE4C:
  subu  $s0, $fp, $t8
  jal   get_video2_settings_txtClipW
   sw    $s0, 0xfc($sp)
  sll   $s0, $v0, 0x10
  sra   $t7, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t7
  lw    $t9, ($s3)
  lw    $t2, ($s4)
  li    $t6, -1
  sw    $t6, 0x18($sp)
  lw    $a0, 0x1b8($sp)
  move  $a1, $s6
  move  $a2, $s7
  move  $a3, $s1
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t9, 0x10($sp)
  jal   en_text_write_stuff
   sw    $t2, 0x14($sp)
  lw    $t1, 0x100($sp)
  lw    $t3, 0xf4($sp)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f0
  addu  $t5, $t1, $t3
  mtc1  $t5, $f8
  lui   $s3, %hi(folder_option_ERASE_left_bound)
  li    $at, 0x43610000 # 225.000000
  cvt.s.w $f10, $f8
  mtc1  $at, $f16
  addiu $s3, %lo(folder_option_ERASE_left_bound) # addiu $s3, $s3, -0x542c
  lui   $s1, %hi(mainfolderimages)
  lui   $at, %hi(D_80051A28)
  addiu $s1, %lo(mainfolderimages) # addiu $s1, $s1, -0x2ed8
  swc1  $f10, 8($s3)
  lwc1  $f18, %lo(D_80051A28)($at)
  lw    $s0, ($s1)
  sw    $v0, 0x1b8($sp)
  swc1  $f16, 0xac($sp)
  swc1  $f18, 0xb0($sp)
  lbu   $t0, 4($s0)
  addiu $s2, $sp, 0x1b8
  mtc1  $t0, $f4
  bgez  $t0, .L7F00CF18
   cvt.s.w $f6, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F00CF18:
  mul.s $f10, $f6, $f0
  swc1  $f10, 0xa4($sp)
  lbu   $t4, 5($s0)
  mtc1  $t4, $f16
  bgez  $t4, .L7F00CF40
   cvt.s.w $f18, $f16
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f4
  nop   
  add.s $f18, $f18, $f4
.L7F00CF40:
  mul.s $f8, $f18, $f0
  move  $a0, $s2
  move  $a1, $s0
  li    $a2, 4
  move  $a3, $zero
  sw    $zero, 0x10($sp)
  jal   likely_generate_DL_for_image_declaration
   swc1  $f8, 0xa8($sp)
  lw    $s0, ($s1)
  li    $t7, 1
  li    $t9, 255
  lbu   $t8, 5($s0)
  lbu   $a3, 4($s0)
  li    $t2, 255
  li    $t6, 255
  li    $t1, 255
  sw    $t1, 0x2c($sp)
  sw    $t6, 0x28($sp)
  sw    $t2, 0x24($sp)
  sw    $t9, 0x20($sp)
  sw    $t7, 0x1c($sp)
  sw    $zero, 0x18($sp)
  sw    $zero, 0x14($sp)
  sw    $t8, 0x10($sp)
  lbu   $t3, 6($s0)
  sw    $zero, 0x34($sp)
  move  $a0, $s2
  slt   $t5, $zero, $t3
  sw    $t5, 0x30($sp)
  addiu $a1, $sp, 0xac
  jal   display_image_at_on_screen_coord
   addiu $a2, $sp, 0xa4
  lwc1  $f6, 0xac($sp)
  lwc1  $f10, 0xa4($sp)
  lwc1  $f4, 0xb0($sp)
  lwc1  $f18, 0xa8($sp)
  sub.s $f16, $f6, $f10
  lwc1  $f10, 0xb0($sp)
  lwc1  $f6, 0xa8($sp)
  sub.s $f8, $f4, $f18
  swc1  $f16, ($s5)
  li    $at, 0x3F000000 # 0.500000
  add.s $f16, $f6, $f10
  mtc1  $at, $f0
  swc1  $f8, 4($s5)
  lui   $at, %hi(D_80051A2C)
  swc1  $f16, 0xc($s5)
  lwc1  $f4, %lo(D_80051A2C)($at)
  lui   $at, %hi(D_80051A30)
  lwc1  $f18, %lo(D_80051A30)($at)
  lw    $s0, ($s1)
  swc1  $f4, 0x9c($sp)
  swc1  $f18, 0xa0($sp)
  lbu   $t0, 0x10($s0)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t0, $f8
  bgez  $t0, .L7F00D034
   cvt.s.w $f6, $f8
  mtc1  $at, $f10
  nop   
  add.s $f6, $f6, $f10
.L7F00D034:
  mul.s $f16, $f6, $f0
  li    $at, 0x4F800000 # 4294967296.000000
  swc1  $f16, 0x94($sp)
  lbu   $t4, 0x11($s0)
  mtc1  $t4, $f4
  bgez  $t4, .L7F00D05C
   cvt.s.w $f18, $f4
  mtc1  $at, $f8
  nop   
  add.s $f18, $f18, $f8
.L7F00D05C:
  mul.s $f10, $f18, $f0
  move  $a0, $s2
  addiu $a1, $s0, 0xc
  li    $a2, 4
  move  $a3, $zero
  sw    $zero, 0x10($sp)
  jal   likely_generate_DL_for_image_declaration
   swc1  $f10, 0x98($sp)
  lw    $s0, ($s1)
  li    $t7, 1
  li    $t9, 255
  lbu   $t8, 0x11($s0)
  lbu   $a3, 0x10($s0)
  li    $t2, 255
  li    $t6, 255
  li    $t1, 255
  sw    $t1, 0x2c($sp)
  sw    $t6, 0x28($sp)
  sw    $t2, 0x24($sp)
  sw    $t9, 0x20($sp)
  sw    $t7, 0x1c($sp)
  sw    $zero, 0x18($sp)
  sw    $zero, 0x14($sp)
  sw    $t8, 0x10($sp)
  lbu   $t3, 0x12($s0)
  sw    $zero, 0x34($sp)
  move  $a0, $s2
  slt   $t5, $zero, $t3
  sw    $t5, 0x30($sp)
  addiu $a1, $sp, 0x9c
  jal   display_image_at_on_screen_coord
   addiu $a2, $sp, 0x94
  lwc1  $f6, 0x9c($sp)
  lwc1  $f16, 0x94($sp)
  lwc1  $f8, 0xa0($sp)
  lwc1  $f18, 0x98($sp)
  sub.s $f4, $f6, $f16
  lwc1  $f16, 0xa0($sp)
  lwc1  $f6, 0x98($sp)
  sub.s $f10, $f8, $f18
  swc1  $f4, ($s3)
  li    $at, 0x42DC0000 # 110.000000
  add.s $f4, $f6, $f16
  mtc1  $at, $f8
  swc1  $f10, 4($s3)
  lui   $at, %hi(D_80051A34)
  swc1  $f4, 0xc($s3)
  lwc1  $f18, %lo(D_80051A34)($at)
  lw    $s0, ($s1)
  swc1  $f8, 0x8c($sp)
  swc1  $f18, 0x90($sp)
  lbu   $t0, 0x1c($s0)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t0, $f10
  bgez  $t0, .L7F00D148
   cvt.s.w $f6, $f10
  mtc1  $at, $f16
  nop   
  add.s $f6, $f6, $f16
.L7F00D148:
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mul.s $f8, $f6, $f4
  swc1  $f8, 0x84($sp)
  lbu   $t4, 0x1d($s0)
  mtc1  $t4, $f18
  bgez  $t4, .L7F00D178
   cvt.s.w $f10, $f18
  mtc1  $at, $f16
  nop   
  add.s $f10, $f10, $f16
.L7F00D178:
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f6
  move  $a0, $s2
  addiu $a1, $s0, 0x18
  mul.s $f4, $f10, $f6
  li    $a2, 4
  move  $a3, $zero
  sw    $zero, 0x10($sp)
  jal   likely_generate_DL_for_image_declaration
   swc1  $f4, 0x88($sp)
  lw    $s0, ($s1)
  li    $t7, 1
  li    $t9, 255
  lbu   $t8, 0x1d($s0)
  lbu   $a3, 0x1c($s0)
  li    $t2, 255
  li    $t6, 255
  li    $t1, 255
  sw    $t1, 0x2c($sp)
  sw    $t6, 0x28($sp)
  sw    $t2, 0x24($sp)
  sw    $t9, 0x20($sp)
  sw    $t7, 0x1c($sp)
  sw    $zero, 0x18($sp)
  sw    $zero, 0x14($sp)
  sw    $t8, 0x10($sp)
  lbu   $t3, 0x1e($s0)
  sw    $zero, 0x34($sp)
  move  $a0, $s2
  slt   $t5, $zero, $t3
  sw    $t5, 0x30($sp)
  addiu $a1, $sp, 0x8c
  jal   display_image_at_on_screen_coord
   addiu $a2, $sp, 0x84
  lui   $t0, %hi(folder_selected_for_deletion) 
  lw    $t0, %lo(folder_selected_for_deletion)($t0)
  bgezl $t0, .L7F00D220
   lw    $ra, 0x64($sp)
  jal   load_draw_selected_icon_folder_select
   lw    $a0, 0x1b8($sp)
  sw    $v0, 0x1b8($sp)
  lw    $ra, 0x64($sp)
.L7F00D220:
  lw    $v0, 0x1b8($sp)
  lw    $s0, 0x40($sp)
  lw    $s1, 0x44($sp)
  lw    $s2, 0x48($sp)
  lw    $s3, 0x4c($sp)
  lw    $s4, 0x50($sp)
  lw    $s5, 0x54($sp)
  lw    $s6, 0x58($sp)
  lw    $s7, 0x5c($sp)
  lw    $fp, 0x60($sp)
  jr    $ra
   addiu $sp, $sp, 0x1b8
");

void init_menu06_modeselect(void) {
  gamemode = -1;
  tab_2_selected = 0;
  tab_3_selected = 0;
  load_walletbond();
  copyCurrentEEPROMtoStack();
}

void update_menu06_modesel(void) {}

asm(R"
glabel interface_menu06_modesel
  addiu $sp, $sp, -0x30
  sw    $s0, 0x18($sp)
  lui   $at, %hi(is_cheat_menu_available)
  lui   $v1, %hi(cheat_available)
  sw    $ra, 0x1c($sp)
  sw    $zero, %lo(is_cheat_menu_available)($at)
  addiu $v1, %lo(cheat_available) # addiu $v1, $v1, -0x69af
  li    $s0, 1
.L7F00D2B8:
  move  $a0, $s0
  jal   check_if_cheat_available
   sw    $v1, 0x24($sp)
  beqz  $v0, .L7F00D2E4
   lw    $v1, 0x24($sp)
  li    $t6, 1
  sb    $t6, ($v1)
  li    $t7, 1
  lui   $at, %hi(is_cheat_menu_available)
  b     .L7F00D2E8
   sw    $t7, %lo(is_cheat_menu_available)($at)
.L7F00D2E4:
  sb    $zero, ($v1)
.L7F00D2E8:
  addiu $s0, $s0, 1
  li    $at, 75
  bne   $s0, $at, .L7F00D2B8
   addiu $v1, $v1, 1
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f12
  jal   setvideo_far
   nop   
  lui   $at, %hi(D_80051A38)
  jal   video_related_21
   lwc1  $f12, %lo(D_80051A38)($at)
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f12
  lui   $at, %hi(D_80051A3C)
  jal   set_page_height
   lwc1  $f14, %lo(D_80051A3C)($at)
  jal   set_video2_settings_offset_24
   move  $a0, $zero
  lui   $s0, %hi(ptr_folder_object_instance)
  addiu $s0, %lo(ptr_folder_object_instance) # addiu $s0, $s0, -0x56a4
  jal   disable_all_switches
   lw    $a0, ($s0)
  lui   $a0, %hi(selected_folder_num)
  jal   removed_would_have_returned_bond_for_folder_num
   lw    $a0, %lo(selected_folder_num)($a0)
  lw    $a0, ($s0)
  jal   select_load_bond_picture
   move  $a1, $v0
  lw    $a0, ($s0)
  move  $a1, $zero
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lw    $a0, ($s0)
  li    $a1, 1
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lw    $a0, ($s0)
  li    $a1, 3
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lw    $a0, ($s0)
  li    $a1, 7
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lw    $a0, ($s0)
  li    $a1, 2
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lui   $s0, %hi(mission_difficulty_highlighted)
  lui   $at, %hi(tab_3_highlight)
  addiu $s0, %lo(mission_difficulty_highlighted) # addiu $s0, $s0, -0x687c
  sw    $zero, %lo(tab_3_highlight)($at)
  li    $t8, -1
  jal   isontab3
   sw    $t8, ($s0)
  beqz  $v0, .L7F00D410
   lui   $t1, %hi(is_cheat_menu_available) 
  li    $t9, 1
  lui   $at, %hi(tab_3_highlight)
  sw    $t9, %lo(tab_3_highlight)($at)
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 45056
  beqz  $v0, .L7F00D51C
   li    $t0, 1
  lui   $at, %hi(tab_3_selected)
  lui   $a0, %hi(ptr_sfx_buf)
  sw    $t0, %lo(tab_3_selected)($at)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 199
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F00D520
   move  $a0, $zero
.L7F00D410:
  lw    $t1, %lo(is_cheat_menu_available)($t1)
  lui   $at, %hi(cursor_v_pos)
  beqz  $t1, .L7F00D478
   nop   
  lwc1  $f4, %lo(cursor_v_pos)($at)
  lui   $at, %hi(D_80051A40)
  lwc1  $f6, %lo(D_80051A40)($at)
  li    $t2, 2
  move  $a0, $zero
  c.le.s $f6, $f4
  li    $a1, 45056
  bc1f  .L7F00D478
   nop   
  jal   get_controller_buttons_pressed
   sw    $t2, ($s0)
  beqz  $v0, .L7F00D51C
   li    $t3, 2
  lui   $at, %hi(gamemode)
  lui   $a0, %hi(ptr_sfx_buf)
  sw    $t3, %lo(gamemode)($at)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 197
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F00D520
   move  $a0, $zero
.L7F00D478:
  lui   $at, %hi(cursor_v_pos)
  lwc1  $f8, %lo(cursor_v_pos)($at)
  li    $at, 0x43730000 # 243.000000
  mtc1  $at, $f10
  nop   
  c.le.s $f10, $f8
  nop   
  bc1fl .L7F00D4F0
   sw    $zero, ($s0)
  jal   get_attached_controller_count
   nop   
  slti  $at, $v0, 2
  bnez  $at, .L7F00D4EC
   li    $t4, 1
  sw    $t4, ($s0)
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 45056
  beqz  $v0, .L7F00D51C
   li    $t5, 1
  lui   $at, %hi(gamemode)
  lui   $a0, %hi(ptr_sfx_buf)
  sw    $t5, %lo(gamemode)($at)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 197
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F00D520
   move  $a0, $zero
.L7F00D4EC:
  sw    $zero, ($s0)
.L7F00D4F0:
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 45056
  beqz  $v0, .L7F00D51C
   lui   $at, %hi(gamemode)
  lui   $a0, %hi(ptr_sfx_buf)
  sw    $zero, %lo(gamemode)($at)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 197
  jal   play_sfx_a1
   move  $a2, $zero
.L7F00D51C:
  move  $a0, $zero
.L7F00D520:
  jal   get_controller_buttons_pressed
   li    $a1, 16384
  beqz  $v0, .L7F00D54C
   li    $t6, 1
  lui   $at, %hi(tab_3_selected)
  lui   $a0, %hi(ptr_sfx_buf)
  sw    $t6, %lo(tab_3_selected)($at)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 199
  jal   play_sfx_a1
   move  $a2, $zero
.L7F00D54C:
  jal   menu_control_stick_tracking
   nop   
  lui   $v0, %hi(gamemode)
  lw    $v0, %lo(gamemode)($v0)
  li    $a0, 7
  li    $at, 1
  bnez  $v0, .L7F00D584
   nop   
  jal   set_menu_to_mode
   move  $a1, $zero
  jal   set_cursor_to_stage_solo
   move  $a0, $zero
  b     .L7F00D5D8
   lw    $ra, 0x1c($sp)
.L7F00D584:
  bne   $v0, $at, .L7F00D59C
   li    $a0, 14
  jal   set_menu_to_mode
   move  $a1, $zero
  b     .L7F00D5D8
   lw    $ra, 0x1c($sp)
.L7F00D59C:
  li    $at, 2
  bne   $v0, $at, .L7F00D5BC
   lui   $t7, %hi(tab_3_selected) 
  li    $a0, 21
  jal   set_menu_to_mode
   move  $a1, $zero
  b     .L7F00D5D8
   lw    $ra, 0x1c($sp)
.L7F00D5BC:
  lw    $t7, %lo(tab_3_selected)($t7)
  li    $a0, 5
  beql  $t7, $zero, .L7F00D5D8
   lw    $ra, 0x1c($sp)
  jal   set_menu_to_mode
   move  $a1, $zero
  lw    $ra, 0x1c($sp)
.L7F00D5D8:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F00D5E8
  addiu $sp, $sp, -0x158
  sw    $s2, 0x34($sp)
  lui   $s2, %hi(selected_folder_num)
  addiu $s2, %lo(selected_folder_num) # addiu $s2, $s2, -0x5718
  lw    $t6, ($s2)
  sw    $s3, 0x38($sp)
  li    $s3, 12
  multu $t6, $s3
  sw    $s1, 0x30($sp)
  lui   $s1, %hi(D_8002AB94)
  addiu $s1, %lo(D_8002AB94) # addiu $s1, $s1, -0x546c
  lui   $t9, %hi(D_8002AF84) 
  addiu $t9, %lo(D_8002AF84) # addiu $t9, $t9, -0x507c
  mtc1  $zero, $f12
  sw    $ra, 0x3c($sp)
  sw    $s0, 0x2c($sp)
  sw    $a0, 0x158($sp)
  mflo  $t7
  addu  $v0, $s1, $t7
  lwc1  $f0, ($v0)
  lwc1  $f2, 4($v0)
  addiu $t2, $t9, 0x3c
  addiu $t8, $sp, 0x10c
.L7F00D644:
  lw    $at, ($t9)
  addiu $t9, $t9, 0xc
  addiu $t8, $t8, 0xc
  sw    $at, -0xc($t8)
  lw    $at, -8($t9)
  sw    $at, -8($t8)
  lw    $at, -4($t9)
  bne   $t9, $t2, .L7F00D644
   sw    $at, -4($t8)
  lw    $at, ($t9)
  addiu $a0, $sp, 0xc8
  sw    $at, ($t8)
  lui   $at, %hi(D_8002AFC4)
  lwc1  $f4, %lo(D_8002AFC4)($at)
  lui   $at, %hi(D_8002AFC8)
  lwc1  $f6, %lo(D_8002AFC8)($at)
  li    $at, 0x457A0000 # 4000.000000
  mtc1  $at, $f8
  lui   $at, %hi(D_8002AFCC)
  lwc1  $f10, %lo(D_8002AFCC)($at)
  add.s $f0, $f0, $f4
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f18
  add.s $f2, $f2, $f6
  mfc1  $a1, $f0
  swc1  $f0, 0x10($sp)
  add.s $f16, $f8, $f10
  mfc1  $a2, $f2
  swc1  $f2, 0x14($sp)
  swc1  $f12, 0x24($sp)
  mfc1  $a3, $f16
  swc1  $f12, 0x1c($sp)
  swc1  $f12, 0x18($sp)
  jal   sub_GAME_7F059694
   swc1  $f18, 0x20($sp)
  lw    $t3, ($s2)
  addiu $s0, $sp, 0x88
  move  $a1, $s0
  multu $t3, $s3
  mflo  $t4
  addu  $a0, $s1, $t4
  jal   init_something_copy_posdata_to_it
   nop   
  li    $at, 0x3E800000 # 0.250000
  mtc1  $at, $f12
  jal   matrix_multiply_A1_by_F12
   move  $a1, $s0
  addiu $a0, $sp, 0xc8
  jal   matrix_4x4_multiply_in_place
   move  $a1, $s0
  lui   $s3, %hi(ptr_folder_object_instance)
  addiu $s3, %lo(ptr_folder_object_instance) # addiu $s3, $s3, -0x56a4
  lw    $t5, ($s3)
  sw    $s0, 0x10c($sp)
  lw    $t6, 8($t5)
  lh    $a0, 0xe($t6)
  sll   $t7, $a0, 6
  jal   sub_GAME_7F0BD714
   move  $a0, $t7
  sw    $v0, 0x11c($sp)
  move  $a0, $s0
  jal   matrix_4x4_copy
   move  $a1, $v0
  lw    $t1, 0x11c($sp)
  lw    $t0, ($s3)
  li    $t2, 3
  addiu $a0, $sp, 0x10c
  sw    $t1, 0xc($t0)
  lw    $t9, 0x158($sp)
  sw    $t2, 0x114($sp)
  sw    $zero, 0x110($sp)
  lw    $a1, ($s3)
  jal   subdraw
   sw    $t9, 0x118($sp)
  lw    $t8, 0x118($sp)
  lw    $v0, ($s3)
  move  $s0, $zero
  sw    $t8, 0x158($sp)
  lw    $t3, 8($v0)
  move  $s1, $zero
  addiu $s2, $sp, 0x48
  lh    $t4, 0xe($t3)
  blezl $t4, .L7F00D7E0
   lw    $ra, 0x3c($sp)
  lw    $t5, 0xc($v0)
.L7F00D798:
  move  $a1, $s2
  jal   matrix_4x4_copy
   addu  $a0, $t5, $s1
  lw    $t6, ($s3)
  sll   $t1, $s0, 6
  move  $a0, $s2
  lw    $t7, 0xc($t6)
  jal   sub_GAME_7F058C9C
   addu  $a1, $t7, $t1
  lw    $v0, ($s3)
  addiu $s0, $s0, 1
  addiu $s1, $s1, 0x40
  lw    $t0, 8($v0)
  lh    $t2, 0xe($t0)
  slt   $at, $s0, $t2
  bnezl $at, .L7F00D798
   lw    $t5, 0xc($v0)
  lw    $ra, 0x3c($sp)
.L7F00D7E0:
  lw    $v0, 0x158($sp)
  lw    $s0, 0x2c($sp)
  lw    $s1, 0x30($sp)
  lw    $s2, 0x34($sp)
  lw    $s3, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x158
");

void set_menu_cursor_pos_to_setting(int arg0) {
  cursor_h_pos = 126.0f;
  cursor_v_pos = (float)((arg0 << 5) + 0xe2);
}

asm(R"
glabel constructor_menu06_modesel
  addiu $sp, $sp, -0x60
  sw    $ra, 0x3c($sp)
  sw    $s0, 0x38($sp)
  move  $a1, $zero
  move  $a2, $zero
  jal   set_setfillcolor
   move  $a3, $zero
  jal   insert_generic_fillrect
   move  $a0, $v0
  jal   sub_GAME_7F00D5E8
   move  $a0, $v0
  jal   microcode_constructor
   move  $a0, $v0
  li    $t6, 150
  li    $t7, 220
  move  $s0, $v0
  sw    $t6, 0x58($sp)
  jal   get_video2_settings_txtClipW
   sw    $t7, 0x54($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lui   $t8, %hi(ptrSecondFontTableLarge) 
  lui   $t9, %hi(ptrFirstFontTableLarge) 
  lw    $t9, %lo(ptrFirstFontTableLarge)($t9)
  lw    $t8, %lo(ptrSecondFontTableLarge)($t8)
  lh    $t1, 0x44($sp)
  lui   $a3, %hi(a1_)
  li    $t0, 255
  sw    $t0, 0x18($sp)
  addiu $a3, %lo(a1_) # addiu $a3, $a3, -0xb6c
  move  $a0, $s0
  addiu $a1, $sp, 0x58
  addiu $a2, $sp, 0x54
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t9, 0x14($sp)
  sw    $t8, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t1, 0x1c($sp)
  lui   $t2, %hi(append_cheat_sp) 
  lw    $t2, %lo(append_cheat_sp)($t2)
  move  $s0, $v0
  beql  $t2, $zero, .L7F00D8E8
   li    $a0, 39965
  b     .L7F00D8E8
   li    $a0, 40053
  li    $a0, 39965
.L7F00D8E8:
  jal   get_textptr_for_textID
   nop   
  lui   $t3, %hi(ptrFirstFontTableLarge) 
  lw    $t3, %lo(ptrFirstFontTableLarge)($t3)
  lui   $a3, %hi(ptrSecondFontTableLarge)
  sw    $v0, 0x5c($sp)
  lw    $a3, %lo(ptrSecondFontTableLarge)($a3)
  addiu $a0, $sp, 0x4c
  addiu $a1, $sp, 0x50
  move  $a2, $v0
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t3, 0x10($sp)
  lui   $t6, %hi(mission_difficulty_highlighted) 
  lw    $t6, %lo(mission_difficulty_highlighted)($t6)
  li    $t4, 170
  li    $t5, 220
  sw    $t4, 0x58($sp)
  bnez  $t6, .L7F00D964
   sw    $t5, 0x54($sp)
  lw    $a3, 0x50($sp)
  li    $t7, 234
  li    $t8, 50
  sw    $t8, 0x14($sp)
  sw    $t7, 0x10($sp)
  move  $a0, $s0
  li    $a1, 148
  li    $a2, 218
  jal   microcode_constructor_related_to_menus
   addiu $a3, $a3, 0xaf
  move  $s0, $v0
.L7F00D964:
  jal   get_video2_settings_txtClipW
   nop   
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lui   $t9, %hi(ptrSecondFontTableLarge) 
  lui   $t0, %hi(ptrFirstFontTableLarge) 
  lw    $t0, %lo(ptrFirstFontTableLarge)($t0)
  lw    $t9, %lo(ptrSecondFontTableLarge)($t9)
  lh    $t2, 0x44($sp)
  li    $t1, 255
  sw    $t1, 0x18($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x58
  addiu $a2, $sp, 0x54
  lw    $a3, 0x5c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t0, 0x14($sp)
  sw    $t9, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t2, 0x1c($sp)
  li    $t3, 150
  li    $t4, 252
  move  $s0, $v0
  sw    $t3, 0x58($sp)
  jal   get_attached_controller_count
   sw    $t4, 0x54($sp)
  slti  $at, $v0, 2
  bnez  $at, .L7F00D9E8
   li    $t5, 255
  b     .L7F00D9F0
   sw    $t5, 0x48($sp)
.L7F00D9E8:
  li    $t6, 112
  sw    $t6, 0x48($sp)
.L7F00D9F0:
  jal   get_video2_settings_txtClipW
   nop   
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lui   $t7, %hi(ptrSecondFontTableLarge) 
  lui   $t8, %hi(ptrFirstFontTableLarge) 
  lw    $t8, %lo(ptrFirstFontTableLarge)($t8)
  lw    $t7, %lo(ptrSecondFontTableLarge)($t7)
  lw    $t9, 0x48($sp)
  lh    $t0, 0x44($sp)
  lui   $a3, %hi(a2_)
  addiu $a3, %lo(a2_) # addiu $a3, $a3, -0xb68
  move  $a0, $s0
  addiu $a1, $sp, 0x58
  addiu $a2, $sp, 0x54
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t8, 0x14($sp)
  sw    $t7, 0x10($sp)
  sw    $t9, 0x18($sp)
  jal   write_text_at_abs_coord
   sw    $t0, 0x1c($sp)
  lui   $t1, %hi(append_cheat_mp) 
  lw    $t1, %lo(append_cheat_mp)($t1)
  move  $s0, $v0
  li    $a0, 39966
  beqz  $t1, .L7F00DA6C
   nop   
  b     .L7F00DA6C
   li    $a0, 40212
.L7F00DA6C:
  jal   get_textptr_for_textID
   nop   
  lui   $t2, %hi(ptrFirstFontTableLarge) 
  lw    $t2, %lo(ptrFirstFontTableLarge)($t2)
  lui   $a3, %hi(ptrSecondFontTableLarge)
  sw    $v0, 0x5c($sp)
  lw    $a3, %lo(ptrSecondFontTableLarge)($a3)
  addiu $a0, $sp, 0x4c
  addiu $a1, $sp, 0x50
  move  $a2, $v0
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t2, 0x10($sp)
  lui   $t5, %hi(mission_difficulty_highlighted) 
  lw    $t5, %lo(mission_difficulty_highlighted)($t5)
  li    $t3, 170
  li    $t4, 252
  li    $at, 1
  sw    $t3, 0x58($sp)
  bne   $t5, $at, .L7F00DAEC
   sw    $t4, 0x54($sp)
  lw    $a3, 0x50($sp)
  li    $t6, 266
  li    $t7, 50
  sw    $t7, 0x14($sp)
  sw    $t6, 0x10($sp)
  move  $a0, $s0
  li    $a1, 148
  li    $a2, 250
  jal   microcode_constructor_related_to_menus
   addiu $a3, $a3, 0xaf
  move  $s0, $v0
.L7F00DAEC:
  jal   get_video2_settings_txtClipW
   nop   
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lui   $t8, %hi(ptrSecondFontTableLarge) 
  lui   $t9, %hi(ptrFirstFontTableLarge) 
  lw    $t9, %lo(ptrFirstFontTableLarge)($t9)
  lw    $t8, %lo(ptrSecondFontTableLarge)($t8)
  lw    $t0, 0x48($sp)
  lh    $t1, 0x44($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x58
  addiu $a2, $sp, 0x54
  lw    $a3, 0x5c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t9, 0x14($sp)
  sw    $t8, 0x10($sp)
  sw    $t0, 0x18($sp)
  jal   write_text_at_abs_coord
   sw    $t1, 0x1c($sp)
  lui   $t2, %hi(is_cheat_menu_available) 
  lw    $t2, %lo(is_cheat_menu_available)($t2)
  move  $s0, $v0
  li    $t3, 150
  beqz  $t2, .L7F00DC9C
   li    $t4, 284
  sw    $t3, 0x58($sp)
  jal   get_video2_settings_txtClipW
   sw    $t4, 0x54($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lui   $t5, %hi(ptrSecondFontTableLarge) 
  lui   $t6, %hi(ptrFirstFontTableLarge) 
  lw    $t6, %lo(ptrFirstFontTableLarge)($t6)
  lw    $t5, %lo(ptrSecondFontTableLarge)($t5)
  lh    $t8, 0x44($sp)
  lui   $a3, %hi(a3_)
  li    $t7, 255
  sw    $t7, 0x18($sp)
  addiu $a3, %lo(a3_) # addiu $a3, $a3, -0xb64
  move  $a0, $s0
  addiu $a1, $sp, 0x58
  addiu $a2, $sp, 0x54
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t6, 0x14($sp)
  sw    $t5, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t8, 0x1c($sp)
  move  $s0, $v0
  jal   get_textptr_for_textID
   li    $a0, 39967
  lui   $t9, %hi(ptrFirstFontTableLarge) 
  lw    $t9, %lo(ptrFirstFontTableLarge)($t9)
  lui   $a3, %hi(ptrSecondFontTableLarge)
  sw    $v0, 0x5c($sp)
  lw    $a3, %lo(ptrSecondFontTableLarge)($a3)
  addiu $a0, $sp, 0x4c
  addiu $a1, $sp, 0x50
  move  $a2, $v0
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t9, 0x10($sp)
  lui   $t2, %hi(mission_difficulty_highlighted) 
  lw    $t2, %lo(mission_difficulty_highlighted)($t2)
  li    $t0, 170
  li    $t1, 284
  li    $at, 2
  sw    $t0, 0x58($sp)
  bne   $t2, $at, .L7F00DC40
   sw    $t1, 0x54($sp)
  lw    $a3, 0x50($sp)
  li    $t3, 298
  li    $t4, 50
  sw    $t4, 0x14($sp)
  sw    $t3, 0x10($sp)
  move  $a0, $s0
  li    $a1, 148
  li    $a2, 282
  jal   microcode_constructor_related_to_menus
   addiu $a3, $a3, 0xaf
  move  $s0, $v0
.L7F00DC40:
  jal   get_video2_settings_txtClipW
   nop   
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lui   $t5, %hi(ptrSecondFontTableLarge) 
  lui   $t6, %hi(ptrFirstFontTableLarge) 
  lw    $t6, %lo(ptrFirstFontTableLarge)($t6)
  lw    $t5, %lo(ptrSecondFontTableLarge)($t5)
  lh    $t8, 0x44($sp)
  li    $t7, 255
  sw    $t7, 0x18($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x58
  addiu $a2, $sp, 0x54
  lw    $a3, 0x5c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t6, 0x14($sp)
  sw    $t5, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t8, 0x1c($sp)
  move  $s0, $v0
.L7F00DC9C:
  jal   add_tab3_previous
   move  $a0, $s0
  jal   load_draw_selected_icon_folder_select
   move  $a0, $v0
  lw    $ra, 0x3c($sp)
  lw    $s0, 0x38($sp)
  addiu $sp, $sp, 0x60
  jr    $ra
   nop   
");

asm(R"
glabel pull_and_display_text_for_folder_a0
  lui   $t6, %hi(mission_folder_setup_entries+4) 
  lhu   $t6, %lo(mission_folder_setup_entries+4)($t6)
  lui   $v0, %hi(mission_folder_setup_entries)
  addiu $v0, %lo(mission_folder_setup_entries) # addiu $v0, $v0, -0x541c
  beqz  $t6, .L7F00DD00
   move  $v1, $zero
  lw    $t7, 0x14($v0)
.L7F00DCDC:
  bnel  $a0, $t7, .L7F00DCF0
   lhu   $t8, 0x20($v0)
  jr    $ra
   move  $v0, $v1
  lhu   $t8, 0x20($v0)
.L7F00DCF0:
  addiu $v1, $v1, 1
  addiu $v0, $v0, 0x1c
  bnezl $t8, .L7F00DCDC
   lw    $t7, 0x14($v0)
.L7F00DD00:
  li    $v0, -1
  jr    $ra
   nop   
");

asm(R"
glabel check_if_stage_completed_on_difficulty
  sll   $t6, $a0, 3
  subu  $t6, $t6, $a0
  sll   $t6, $t6, 2
  lui   $a3, %hi(mission_folder_setup_entries+0x14)
  addu  $a3, $a3, $t6
  lw    $a3, %lo(mission_folder_setup_entries+0x14)($a3)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  bltz  $a3, .L7F00DD4C
   move  $a2, $a1
  lui   $a0, %hi(selected_folder_num)
  lw    $a0, %lo(selected_folder_num)($a0)
  jal   isStageUnlockedAtDifficulty
   move  $a1, $a3
  b     .L7F00DD54
   lw    $ra, 0x14($sp)
.L7F00DD4C:
  move  $v0, $zero
  lw    $ra, 0x14($sp)
.L7F00DD54:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel get_highest_unlocked_difficulty_for_level
  addiu $sp, $sp, -0x30
  sw    $ra, 0x2c($sp)
  sw    $s3, 0x24($sp)
  move  $s3, $a0
  sw    $s4, 0x28($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  jal   pull_and_display_text_for_folder_a0
   sw    $s0, 0x18($sp)
  sll   $t6, $v0, 3
  subu  $t6, $t6, $v0
  sll   $t6, $t6, 2
  lui   $t7, %hi(mission_folder_setup_entries+8)
  addu  $t7, $t7, $t6
  lw    $t7, %lo(mission_folder_setup_entries+8)($t7)
  lui   $s4, %hi(selected_folder_num)
  addiu $s4, %lo(selected_folder_num) # addiu $s4, $s4, -0x5718
  bltz  $t7, .L7F00DE2C
   li    $s1, 2
  jal   check_for_007_mode_unlocked
   lw    $a0, ($s4)
  bnezl $v0, .L7F00DDD0
   li    $s1, 3
  jal   get_debug_007_unlock_flag
   nop   
  beqz  $v0, .L7F00DDD0
   nop   
  li    $s1, 3
.L7F00DDD0:
  bltz  $s1, .L7F00DE2C
   move  $s0, $s1
  lui   $s1, %hi(append_cheat_sp)
  addiu $s1, %lo(append_cheat_sp) # addiu $s1, $s1, -0x5700
  li    $s2, 3
  lw    $a0, ($s4)
.L7F00DDE8:
  move  $a1, $s3
  jal   isStageUnlockedAtDifficulty
   move  $a2, $s0
  lw    $t8, ($s1)
  bnez  $t8, .L7F00DE10
   nop   
  beql  $v0, $zero, .L7F00DE24
   addiu $s0, $s0, -1
  b     .L7F00DE30
   move  $v0, $s0
.L7F00DE10:
  bnel  $v0, $s2, .L7F00DE24
   addiu $s0, $s0, -1
  b     .L7F00DE30
   move  $v0, $s0
  addiu $s0, $s0, -1
.L7F00DE24:
  bgezl $s0, .L7F00DDE8
   lw    $a0, ($s4)
.L7F00DE2C:
  li    $v0, -1
.L7F00DE30:
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  lw    $s3, 0x24($sp)
  lw    $s4, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x30
");

void init_menu07_missionselect(void) {
  selected_stage = -1;
  briefingpage = -1;
  tab_2_selected = 0;
  tab_3_selected = 0;
  if (maybe_is_in_menu != 0) {
    musicTrack1Play(0x17);
    maybe_is_in_menu = 0;
  }
  load_walletbond();
}

void update_menu07_missionsel(void) {}

#ifdef VERSION_US
asm(R"
glabel interface_menu07_missionsel
  addiu $sp, $sp, -0x60
  li    $at, 0x42700000 # 60.000000
  sw    $ra, 0x2c($sp)
  mtc1  $at, $f12
  sw    $s5, 0x28($sp)
  sw    $s4, 0x24($sp)
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  jal   setvideo_far
   sw    $s0, 0x14($sp)
  lui   $at, %hi(D_80051A44)
  jal   video_related_21
   lwc1  $f12, %lo(D_80051A44)($at)
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f12
  lui   $at, %hi(D_80051A48)
  jal   set_page_height
   lwc1  $f14, %lo(D_80051A48)($at)
  jal   set_video2_settings_offset_24
   move  $a0, $zero
  lui   $a0, %hi(ptr_folder_object_instance)
  jal   disable_all_switches
   lw    $a0, %lo(ptr_folder_object_instance)($a0)
  lui   $a0, %hi(ptr_folder_object_instance)
  lw    $a0, %lo(ptr_folder_object_instance)($a0)
  move  $a1, $zero
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lui   $a0, %hi(ptr_folder_object_instance)
  lw    $a0, %lo(ptr_folder_object_instance)($a0)
  li    $a1, 19
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lui   $a0, %hi(ptr_folder_object_instance)
  lw    $a0, %lo(ptr_folder_object_instance)($a0)
  li    $a1, 20
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lui   $at, %hi(tab_3_highlight)
  sw    $zero, %lo(tab_3_highlight)($at)
  lui   $at, %hi(mission_difficulty_highlighted)
  li    $t6, -1
  jal   isontab3
   sw    $t6, %lo(mission_difficulty_highlighted)($at)
  beqz  $v0, .L7F00DF84
   move  $s4, $zero
  li    $t7, 1
  lui   $at, %hi(tab_3_highlight)
  b     .L7F00E0F8
   sw    $t7, %lo(tab_3_highlight)($at)
.L7F00DF84:
  li    $at, 0x3F000000 # 0.500000
  lui   $a0, %hi(cursor_xpos_table_mission_select)
  lui   $v1, %hi(cursor_h_pos)
  mtc1  $at, $f0
  addiu $v1, %lo(cursor_h_pos) # addiu $v1, $v1, -0x56f8
  addiu $a0, %lo(cursor_xpos_table_mission_select) # addiu $a0, $a0, -0x5030
  li    $s3, 5
  slti  $at, $s4, 4
.L7F00DFA4:
  beqz  $at, .L7F00DFEC
   sll   $t8, $s4, 2
  addu  $v0, $a0, $t8
  lw    $t9, 4($v0)
  lw    $t0, ($v0)
  lwc1  $f4, ($v1)
  addu  $t1, $t9, $t0
  mtc1  $t1, $f6
  nop   
  cvt.s.w $f8, $f6
  mul.s $f10, $f8, $f0
  c.lt.s $f4, $f10
  nop   
  bc1t  .L7F00DFEC
   nop   
  addiu $s4, $s4, 1
  bnel  $s4, $s3, .L7F00DFA4
   slti  $at, $s4, 4
.L7F00DFEC:
  lui   $a0, %hi(cursor_ypos_table_mission_select)
  lui   $v1, %hi(cursor_v_pos)
  addiu $v1, %lo(cursor_v_pos) # addiu $v1, $v1, -0x56f4
  addiu $a0, %lo(cursor_ypos_table_mission_select) # addiu $a0, $a0, -0x501c
  move  $s2, $zero
  li    $a1, 4
  slti  $at, $s2, 3
.L7F00E008:
  beqz  $at, .L7F00E050
   sll   $t2, $s2, 2
  addu  $v0, $a0, $t2
  lw    $t3, 4($v0)
  lw    $t4, ($v0)
  lwc1  $f16, ($v1)
  addu  $t5, $t3, $t4
  mtc1  $t5, $f18
  nop   
  cvt.s.w $f6, $f18
  mul.s $f8, $f6, $f0
  c.lt.s $f16, $f8
  nop   
  bc1t  .L7F00E050
   nop   
  addiu $s2, $s2, 1
  bnel  $s2, $a1, .L7F00E008
   slti  $at, $s2, 3
.L7F00E050:
  blez  $s2, .L7F00E098
   sll   $s5, $s2, 2
  addu  $s5, $s5, $s2
.L7F00E05C:
  move  $s1, $zero
  move  $s0, $s5
.L7F00E064:
  jal   get_highest_unlocked_difficulty_for_level
   move  $a0, $s0
  bgezl $v0, .L7F00E084
   slti  $at, $s1, 5
  addiu $s1, $s1, 1
  bne   $s1, $s3, .L7F00E064
   addiu $s0, $s0, 1
  slti  $at, $s1, 5
.L7F00E084:
  bnezl $at, .L7F00E09C
   sll   $s5, $s2, 2
  addiu $s2, $s2, -1
  bgtz  $s2, .L7F00E05C
   addiu $s5, $s5, -5
.L7F00E098:
  sll   $s5, $s2, 2
.L7F00E09C:
  bltz  $s4, .L7F00E0C4
   addu  $s5, $s5, $s2
  addu  $s0, $s5, $s4
.L7F00E0A8:
  jal   get_highest_unlocked_difficulty_for_level
   move  $a0, $s0
  bgez  $v0, .L7F00E0C4
   nop   
  addiu $s4, $s4, -1
  bgez  $s4, .L7F00E0A8
   addiu $s0, $s0, -1
.L7F00E0C4:
  bgez  $s4, .L7F00E0EC
   move  $s0, $s5
  move  $s4, $zero
.L7F00E0D0:
  jal   get_highest_unlocked_difficulty_for_level
   move  $a0, $s0
  bgezl $v0, .L7F00E0F0
   addu  $t6, $s5, $s4
  addiu $s4, $s4, 1
  bne   $s4, $s3, .L7F00E0D0
   addiu $s0, $s0, 1
.L7F00E0EC:
  addu  $t6, $s5, $s4
.L7F00E0F0:
  lui   $at, %hi(mission_difficulty_highlighted)
  sw    $t6, %lo(mission_difficulty_highlighted)($at)
.L7F00E0F8:
  lui   $a0, %hi(ptr_folder_object_instance)
  lw    $a0, %lo(ptr_folder_object_instance)($a0)
  lw    $t7, 8($a0)
  lw    $t8, 8($t7)
  lw    $a1, 0x54($t8)
  beql  $a1, $zero, .L7F00E260
   move  $a0, $zero
  jal   extract_id_from_object_structure_microcode
   lw    $s4, 4($a1)
  move  $s1, $v0
  jal   sub_GAME_7F0BD6C4
   lh    $a0, 0xc($s4)
  sw    $v0, ($s1)
  lh    $t9, 0xc($s4)
  move  $s2, $zero
  move  $s0, $zero
  blez  $t9, .L7F00E25C
   li    $s5, 245
  li    $s3, 110
  lw    $t2, 8($s4)
.L7F00E148:
  lw    $t0, ($s1)
  addu  $t3, $t2, $s0
  lw    $at, ($t3)
  addu  $t1, $t0, $s0
  sw    $at, ($t1)
  lw    $t5, 4($t3)
  sw    $t5, 4($t1)
  lw    $at, 8($t3)
  sw    $at, 8($t1)
  lw    $t5, 0xc($t3)
  sw    $t5, 0xc($t1)
  bgez  $s2, .L7F00E184
   sra   $a0, $s2, 2
  addiu $at, $s2, 3
  sra   $a0, $at, 2
.L7F00E184:
  jal   get_highest_unlocked_difficulty_for_level
   sw    $a0, 0x30($sp)
  li    $v1, 255
  lw    $a0, 0x30($sp)
  bltz  $v0, .L7F00E214
   li    $a1, 15
  lui   $t6, %hi(mission_difficulty_highlighted) 
  lw    $t6, %lo(mission_difficulty_highlighted)($t6)
  bnel  $a0, $t6, .L7F00E1E4
   lw    $t5, ($s1)
  lw    $t7, ($s1)
  addu  $t8, $t7, $s0
  sb    $v1, 0xc($t8)
  lw    $t9, ($s1)
  addu  $t0, $t9, $s0
  sb    $v1, 0xd($t0)
  lw    $t2, ($s1)
  addu  $t4, $t2, $s0
  sb    $v1, 0xe($t4)
  lw    $t1, ($s1)
  addu  $t3, $t1, $s0
  b     .L7F00E244
   sb    $s5, 0xf($t3)
  lw    $t5, ($s1)
.L7F00E1E4:
  addu  $t6, $t5, $s0
  sb    $s3, 0xc($t6)
  lw    $t7, ($s1)
  addu  $t8, $t7, $s0
  sb    $s3, 0xd($t8)
  lw    $t9, ($s1)
  addu  $t0, $t9, $s0
  sb    $s3, 0xe($t0)
  lw    $t2, ($s1)
  addu  $t4, $t2, $s0
  b     .L7F00E244
   sb    $v1, 0xf($t4)
.L7F00E214:
  lw    $t1, ($s1)
  addu  $t3, $t1, $s0
  sb    $a1, 0xc($t3)
  lw    $t5, ($s1)
  addu  $t6, $t5, $s0
  sb    $a1, 0xd($t6)
  lw    $t7, ($s1)
  addu  $t8, $t7, $s0
  sb    $a1, 0xe($t8)
  lw    $t9, ($s1)
  addu  $t0, $t9, $s0
  sb    $v1, 0xf($t0)
.L7F00E244:
  lh    $t2, 0xc($s4)
  addiu $s2, $s2, 1
  addiu $s0, $s0, 0x10
  slt   $at, $s2, $t2
  bnezl $at, .L7F00E148
   lw    $t2, 8($s4)
.L7F00E25C:
  move  $a0, $zero
.L7F00E260:
  jal   get_controller_buttons_pressed
   li    $a1, 45056
  beqz  $v0, .L7F00E314
   move  $a0, $zero
  lui   $t4, %hi(tab_3_highlight) 
  lw    $t4, %lo(tab_3_highlight)($t4)
  li    $t1, 1
  lui   $at, %hi(tab_3_selected)
  beqz  $t4, .L7F00E2A8
   lui   $a0, %hi(mission_difficulty_highlighted)
  lui   $a0, %hi(ptr_sfx_buf)
  sw    $t1, %lo(tab_3_selected)($at)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 199
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F00E340
   nop   
.L7F00E2A8:
  lw    $a0, %lo(mission_difficulty_highlighted)($a0)
  bltz  $a0, .L7F00E340
   nop   
  jal   pull_and_display_text_for_folder_a0
   nop   
  lui   $at, %hi(briefingpage)
  sw    $v0, %lo(briefingpage)($at)
  lui   $t3, %hi(briefingpage) 
  lw    $t3, %lo(briefingpage)($t3)
  lui   $t6, %hi(mission_folder_setup_entries+8)
  lui   $at, %hi(selected_stage)
  sll   $t5, $t3, 3
  subu  $t5, $t5, $t3
  sll   $t5, $t5, 2
  addu  $t6, $t6, $t5
  lw    $t6, %lo(mission_folder_setup_entries+8)($t6)
  li    $t7, 1
  lui   $a0, %hi(ptr_sfx_buf)
  sw    $t6, %lo(selected_stage)($at)
  lui   $at, %hi(tab_2_selected)
  sw    $t7, %lo(tab_2_selected)($at)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 199
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F00E340
   nop   
.L7F00E314:
  jal   get_controller_buttons_pressed
   li    $a1, 16384
  beqz  $v0, .L7F00E340
   li    $t8, 1
  lui   $at, %hi(tab_3_selected)
  lui   $a0, %hi(ptr_sfx_buf)
  sw    $t8, %lo(tab_3_selected)($at)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 199
  jal   play_sfx_a1
   move  $a2, $zero
.L7F00E340:
  jal   menu_control_stick_tracking
   nop   
  lui   $t9, %hi(tab_2_selected) 
  lw    $t9, %lo(tab_2_selected)($t9)
  li    $a0, 8
  lui   $t4, %hi(tab_3_selected) 
  beqz  $t9, .L7F00E39C
   nop   
  jal   set_menu_to_mode
   move  $a1, $zero
  lui   $t0, %hi(briefingpage) 
  lw    $t0, %lo(briefingpage)($t0)
  lui   $a0, %hi(mission_folder_setup_entries+20)
  sll   $t2, $t0, 3
  subu  $t2, $t2, $t0
  sll   $t2, $t2, 2
  addu  $a0, $a0, $t2
  jal   get_highest_unlocked_difficulty_for_level
   lw    $a0, %lo(mission_folder_setup_entries+20)($a0)
  jal   set_cursor_pos_difficulty
   move  $a0, $v0
  b     .L7F00E3C0
   lw    $ra, 0x2c($sp)
.L7F00E39C:
  lw    $t4, %lo(tab_3_selected)($t4)
  li    $a0, 6
  beql  $t4, $zero, .L7F00E3C0
   lw    $ra, 0x2c($sp)
  jal   set_menu_to_mode
   move  $a1, $zero
  jal   set_menu_cursor_pos_to_setting
   move  $a0, $zero
  lw    $ra, 0x2c($sp)
.L7F00E3C0:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  lw    $s4, 0x24($sp)
  lw    $s5, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x60
");
#endif

#ifdef VERSION_JP
asm(R"
glabel interface_menu07_missionsel
  addiu $sp, $sp, -0x60
  li    $at, 0x42700000 # 60.000000
  sw    $ra, 0x2c($sp)
  mtc1  $at, $f12
  sw    $s5, 0x28($sp)
  sw    $s4, 0x24($sp)
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  jal   setvideo_far
   sw    $s0, 0x14($sp)
  lui   $at, %hi(D_80051A44) # $at, 0x8005
  jal   video_related_21
   lwc1  $f12, %lo(D_80051A44)($at)
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f12
  lui   $at, %hi(D_80051A48) # $at, 0x8005
  jal   set_page_height
   lwc1  $f14, %lo(D_80051A48)($at)
  jal   set_video2_settings_offset_24
   move  $a0, $zero
  lui   $a0, %hi(ptr_folder_object_instance) # $a0, 0x8003
  jal   disable_all_switches
   lw    $a0, %lo(ptr_folder_object_instance)($a0)
  lui   $a0, %hi(ptr_folder_object_instance) # $a0, 0x8003
  lw    $a0, %lo(ptr_folder_object_instance)($a0)
  move  $a1, $zero
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lui   $a0, %hi(ptr_folder_object_instance) # $a0, 0x8003
  lw    $a0, %lo(ptr_folder_object_instance)($a0)
  li    $a1, 19
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lui   $a0, %hi(ptr_folder_object_instance) # $a0, 0x8003
  lw    $a0, %lo(ptr_folder_object_instance)($a0)
  li    $a1, 20
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lui   $at, %hi(tab_3_highlight) # $at, 0x8003
  sw    $zero, %lo(tab_3_highlight)($at)
  lui   $at, %hi(mission_difficulty_highlighted) # $at, 0x8007
  li    $t6, -1
  jal   isontab3
   sw    $t6, %lo(mission_difficulty_highlighted)($at)
  beqz  $v0, .L7F00DFA4
   move  $s4, $zero
  li    $t7, 1
  lui   $at, %hi(tab_3_highlight) # $at, 0x8003
  b     .L7F00E118
   sw    $t7, %lo(tab_3_highlight)($at)
.L7F00DFA4:
  li    $at, 0x3F000000 # 0.500000
  lui   $a0, %hi(cursor_xpos_table_mission_select) # $a0, 0x8003
  lui   $v1, %hi(cursor_h_pos) # $v1, 0x8003
  mtc1  $at, $f0
  addiu $v1, %lo(cursor_h_pos) # addiu $v1, $v1, -0x56b8
  addiu $a0, %lo(cursor_xpos_table_mission_select) # addiu $a0, $a0, -0x4ff0
  li    $s3, 5
  slti  $at, $s4, 4
.L7F00DFC4:
  beqz  $at, .L7F00E00C
   sll   $t8, $s4, 2
  addu  $v0, $a0, $t8
  lw    $t9, 4($v0)
  lw    $t0, ($v0)
  lwc1  $f4, ($v1)
  addu  $t1, $t9, $t0
  mtc1  $t1, $f6
  nop   
  cvt.s.w $f8, $f6
  mul.s $f10, $f8, $f0
  c.lt.s $f4, $f10
  nop   
  bc1t  .L7F00E00C
   nop   
  addiu $s4, $s4, 1
  bnel  $s4, $s3, .L7F00DFC4
   slti  $at, $s4, 4
.L7F00E00C:
  lui   $a0, %hi(cursor_ypos_table_mission_select) # $a0, 0x8003
  lui   $v1, %hi(cursor_v_pos) # $v1, 0x8003
  addiu $v1, %lo(cursor_v_pos) # addiu $v1, $v1, -0x56b4
  addiu $a0, %lo(cursor_ypos_table_mission_select) # addiu $a0, $a0, -0x4fdc
  move  $s2, $zero
  li    $a1, 4
  slti  $at, $s2, 3
.L7F00E028:
  beqz  $at, .L7F00E070
   sll   $t2, $s2, 2
  addu  $v0, $a0, $t2
  lw    $t3, 4($v0)
  lw    $t4, ($v0)
  lwc1  $f16, ($v1)
  addu  $t5, $t3, $t4
  mtc1  $t5, $f18
  nop   
  cvt.s.w $f6, $f18
  mul.s $f8, $f6, $f0
  c.lt.s $f16, $f8
  nop   
  bc1t  .L7F00E070
   nop   
  addiu $s2, $s2, 1
  bnel  $s2, $a1, .L7F00E028
   slti  $at, $s2, 3
.L7F00E070:
  blez  $s2, .L7F00E0B8
   sll   $s5, $s2, 2
  addu  $s5, $s5, $s2
.L7F00E07C:
  move  $s1, $zero
  move  $s0, $s5
.L7F00E084:
  jal   get_highest_unlocked_difficulty_for_level
   move  $a0, $s0
  bgezl $v0, .L7F00E0A4
   slti  $at, $s1, 5
  addiu $s1, $s1, 1
  bne   $s1, $s3, .L7F00E084
   addiu $s0, $s0, 1
  slti  $at, $s1, 5
.L7F00E0A4:
  bnezl $at, .L7F00E0BC
   sll   $s5, $s2, 2
  addiu $s2, $s2, -1
  bgtz  $s2, .L7F00E07C
   addiu $s5, $s5, -5
.L7F00E0B8:
  sll   $s5, $s2, 2
.L7F00E0BC:
  bltz  $s4, .L7F00E0E4
   addu  $s5, $s5, $s2
  addu  $s0, $s5, $s4
.L7F00E0C8:
  jal   get_highest_unlocked_difficulty_for_level
   move  $a0, $s0
  bgez  $v0, .L7F00E0E4
   nop   
  addiu $s4, $s4, -1
  bgez  $s4, .L7F00E0C8
   addiu $s0, $s0, -1
.L7F00E0E4:
  bgez  $s4, .L7F00E10C
   move  $s0, $s5
  move  $s4, $zero
.L7F00E0F0:
  jal   get_highest_unlocked_difficulty_for_level
   move  $a0, $s0
  bgezl $v0, .L7F00E110
   addu  $t6, $s5, $s4
  addiu $s4, $s4, 1
  bne   $s4, $s3, .L7F00E0F0
   addiu $s0, $s0, 1
.L7F00E10C:
  addu  $t6, $s5, $s4
.L7F00E110:
  lui   $at, %hi(mission_difficulty_highlighted) # $at, 0x8007
  sw    $t6, %lo(mission_difficulty_highlighted)($at)
.L7F00E118:
  lui   $a0, %hi(ptr_folder_object_instance) # $a0, 0x8003
  lw    $a0, %lo(ptr_folder_object_instance)($a0)
  lw    $t7, 8($a0)
  lw    $t8, 8($t7)
  lw    $a1, 0x54($t8)
  beql  $a1, $zero, .L7F00E280
   move  $a0, $zero
  jal   extract_id_from_object_structure_microcode
   lw    $s4, 4($a1)
  move  $s1, $v0
  jal   sub_GAME_7F0BD6C4
   lh    $a0, 0xc($s4)
  sw    $v0, ($s1)
  lh    $t9, 0xc($s4)
  move  $s2, $zero
  move  $s0, $zero
  blez  $t9, .L7F00E27C
   li    $s5, 245
  li    $s3, 110
  lw    $t2, 8($s4)
.L7F00E168:
  lw    $t0, ($s1)
  addu  $t3, $t2, $s0
  lw    $at, ($t3)
  addu  $t1, $t0, $s0
  sw    $at, ($t1)
  lw    $t5, 4($t3)
  sw    $t5, 4($t1)
  lw    $at, 8($t3)
  sw    $at, 8($t1)
  lw    $t5, 0xc($t3)
  sw    $t5, 0xc($t1)
  bgez  $s2, .L7F00E1A4
   sra   $a0, $s2, 2
  addiu $at, $s2, 3
  sra   $a0, $at, 2
.L7F00E1A4:
  jal   get_highest_unlocked_difficulty_for_level
   sw    $a0, 0x30($sp)
  li    $v1, 255
  lw    $a0, 0x30($sp)
  bltz  $v0, .L7F00E234
   li    $a1, 15
  lui   $t6, %hi(mission_difficulty_highlighted) # $t6, 0x8007
  lw    $t6, %lo(mission_difficulty_highlighted)($t6)
  bnel  $a0, $t6, .L7F00E204
   lw    $t5, ($s1)
  lw    $t7, ($s1)
  addu  $t8, $t7, $s0
  sb    $v1, 0xc($t8)
  lw    $t9, ($s1)
  addu  $t0, $t9, $s0
  sb    $v1, 0xd($t0)
  lw    $t2, ($s1)
  addu  $t4, $t2, $s0
  sb    $v1, 0xe($t4)
  lw    $t1, ($s1)
  addu  $t3, $t1, $s0
  b     .L7F00E264
   sb    $s5, 0xf($t3)
  lw    $t5, ($s1)
.L7F00E204:
  addu  $t6, $t5, $s0
  sb    $s3, 0xc($t6)
  lw    $t7, ($s1)
  addu  $t8, $t7, $s0
  sb    $s3, 0xd($t8)
  lw    $t9, ($s1)
  addu  $t0, $t9, $s0
  sb    $s3, 0xe($t0)
  lw    $t2, ($s1)
  addu  $t4, $t2, $s0
  b     .L7F00E264
   sb    $v1, 0xf($t4)
.L7F00E234:
  lw    $t1, ($s1)
  addu  $t3, $t1, $s0
  sb    $a1, 0xc($t3)
  lw    $t5, ($s1)
  addu  $t6, $t5, $s0
  sb    $a1, 0xd($t6)
  lw    $t7, ($s1)
  addu  $t8, $t7, $s0
  sb    $a1, 0xe($t8)
  lw    $t9, ($s1)
  addu  $t0, $t9, $s0
  sb    $v1, 0xf($t0)
.L7F00E264:
  lh    $t2, 0xc($s4)
  addiu $s2, $s2, 1
  addiu $s0, $s0, 0x10
  slt   $at, $s2, $t2
  bnezl $at, .L7F00E168
   lw    $t2, 8($s4)
.L7F00E27C:
  move  $a0, $zero
.L7F00E280:
  jal   get_controller_buttons_pressed
   li    $a1, 45056
  beqz  $v0, .L7F00E334
   move  $a0, $zero
  lui   $t4, %hi(tab_3_highlight) # $t4, 0x8003
  lw    $t4, %lo(tab_3_highlight)($t4)
  li    $t1, 1
  lui   $at, %hi(tab_3_selected) # $at, 0x8003
  beqz  $t4, .L7F00E2C8
   lui   $a0, %hi(mission_difficulty_highlighted)
  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  sw    $t1, %lo(tab_3_selected)($at)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 199
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F00E360
   nop   
.L7F00E2C8:
  lw    $a0, %lo(mission_difficulty_highlighted)($a0)
  bltz  $a0, .L7F00E360
   nop   
  jal   pull_and_display_text_for_folder_a0
   nop   
  lui   $at, %hi(briefingpage) # $at, 0x8003
  sw    $v0, %lo(briefingpage)($at)
  lui   $t3, %hi(briefingpage) # $t3, 0x8003
  lw    $t3, %lo(briefingpage)($t3)
  lui   $t6, %hi(mission_folder_setup_entries+8)
  lui   $at, %hi(selected_stage) # $at, 0x8003
  sll   $t5, $t3, 3
  subu  $t5, $t5, $t3
  sll   $t5, $t5, 2
  addu  $t6, $t6, $t5
  lw    $t6, %lo(mission_folder_setup_entries+8)($t6)
  li    $t7, 1
  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  sw    $t6, %lo(selected_stage)($at)
  lui   $at, %hi(tab_2_selected) # $at, 0x8003
  sw    $t7, %lo(tab_2_selected)($at)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 199
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F00E360
   nop   
.L7F00E334:
  jal   get_controller_buttons_pressed
   li    $a1, 16384
  beqz  $v0, .L7F00E360
   li    $t8, 1
  lui   $at, %hi(tab_3_selected) # $at, 0x8003
  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  sw    $t8, %lo(tab_3_selected)($at)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 199
  jal   play_sfx_a1
   move  $a2, $zero
.L7F00E360:
  jal   menu_control_stick_tracking
   nop   
  lui   $t9, %hi(tab_2_selected) # $t9, 0x8003
  lw    $t9, %lo(tab_2_selected)($t9)
  li    $a0, 8
  lui   $t1, %hi(tab_3_selected) # $t1, 0x8003
  beqz  $t9, .L7F00E3DC
   nop   
  jal   set_menu_to_mode
   move  $a1, $zero
  lui   $t0, %hi(j_text_trigger) # $t0, 0x8005
  lw    $t0, %lo(j_text_trigger)($t0)
  lui   $t2, %hi(briefingpage) # $t2, 0x8003
  beqz  $t0, .L7F00E3AC
   nop   
  jal   set_cursor_pos_difficulty
   move  $a0, $zero
  b     .L7F00E400
   lw    $ra, 0x2c($sp)
.L7F00E3AC:
  lw    $t2, %lo(briefingpage)($t2)
  lui   $a0, %hi(mission_folder_setup_entries+20)
  sll   $t4, $t2, 3
  subu  $t4, $t4, $t2
  sll   $t4, $t4, 2
  addu  $a0, $a0, $t4
  jal   get_highest_unlocked_difficulty_for_level
   lw    $a0, %lo(mission_folder_setup_entries+20)($a0)
  jal   set_cursor_pos_difficulty
   move  $a0, $v0
  b     .L7F00E400
   lw    $ra, 0x2c($sp)
.L7F00E3DC:
  lw    $t1, %lo(tab_3_selected)($t1)
  li    $a0, 6
  beql  $t1, $zero, .L7F00E400
   lw    $ra, 0x2c($sp)
  jal   set_menu_to_mode
   move  $a1, $zero
  jal   set_menu_cursor_pos_to_setting
   move  $a0, $zero
  lw    $ra, 0x2c($sp)
.L7F00E400:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  lw    $s4, 0x24($sp)
  lw    $s5, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x60

");
#endif

asm(R"
glabel set_cursor_to_stage_solo
  li    $v0, 5
  div   $zero, $a0, $v0
  mfhi  $t6
  sll   $t7, $t6, 2
  lui   $t8, %hi(cursor_xpos_table_mission_select)
  addu  $t8, $t8, $t7
  lw    $t8, %lo(cursor_xpos_table_mission_select)($t8)
  mflo  $t9
  sll   $t0, $t9, 2
  lui   $t1, %hi(cursor_ypos_table_mission_select)
  addu  $t1, $t1, $t0
  lw    $t1, %lo(cursor_ypos_table_mission_select)($t1)
  mtc1  $t8, $f4
  bnez  $v0, .L7F00E420
   nop   
  break 7
.L7F00E420:
  li    $at, -1
  bne   $v0, $at, .L7F00E438
   lui   $at, 0x8000
  bne   $a0, $at, .L7F00E438
   nop   
  break 6
.L7F00E438:
  cvt.s.w $f6, $f4
  mtc1  $t1, $f8
  lui   $at, %hi(cursor_h_pos)
  cvt.s.w $f10, $f8
  swc1  $f6, %lo(cursor_h_pos)($at)
  lui   $at, %hi(cursor_v_pos)
  jr    $ra
   swc1  $f10, %lo(cursor_v_pos)($at)
");

asm(R"
glabel constructor_menu07_missionsel
  addiu $sp, $sp, -0xe0
  sw    $ra, 0x5c($sp)
  sw    $fp, 0x58($sp)
  sw    $s7, 0x54($sp)
  sw    $s6, 0x50($sp)
  sw    $s5, 0x4c($sp)
  sw    $s4, 0x48($sp)
  sw    $s3, 0x44($sp)
  sw    $s2, 0x40($sp)
  sw    $s1, 0x3c($sp)
  sw    $s0, 0x38($sp)
  move  $a1, $zero
  move  $a2, $zero
  jal   set_setfillcolor
   move  $a3, $zero
  jal   insert_generic_fillrect
   move  $a0, $v0
  lui   $t6, 0xf800
  li    $t7, -1
  sw    $t7, 4($v0)
  sw    $t6, ($v0)
  jal   sub_GAME_7F00D5E8
   addiu $a0, $v0, 8
  jal   microcode_constructor
   move  $a0, $v0
  addiu $s1, $sp, 0x90
  move  $s4, $v0
  move  $s2, $s1
  sw    $zero, 0xd8($sp)
.L7F00E4CC:
  lw    $s3, 0xd8($sp)
  move  $s6, $zero
.L7F00E4D4:
  jal   pull_and_display_text_for_folder_a0
   move  $a0, $s3
  move  $s0, $v0
  jal   get_highest_unlocked_difficulty_for_level
   move  $a0, $s3
  bltz  $v0, .L7F00E71C
   lui   $s5, (0x96969600 >> 16) # lui $s5, 0x9696
  lw    $t9, 0xd8($sp)
  lui   $t4, %hi(mission_difficulty_highlighted) 
  lw    $t4, %lo(mission_difficulty_highlighted)($t4)
  lui   $t1, %hi(cursor_xpos_table_mission_select) 
  lui   $t3, %hi(cursor_ypos_table_mission_select) 
  addiu $t3, %lo(cursor_ypos_table_mission_select) # addiu $t3, $t3, -0x501c
  addiu $t1, %lo(cursor_xpos_table_mission_select) # addiu $t1, $t1, -0x5030
  sll   $t2, $s6, 2
  sll   $t0, $t9, 2
  ori   $s5, (0x96969600 & 0xFFFF) # ori $s5, $s5, 0x9600
  addu  $s7, $t0, $t1
  bne   $s3, $t4, .L7F00E528
   addu  $fp, $t2, $t3
  li    $s5, -256
.L7F00E528:
  sll   $t5, $s0, 3
  subu  $t5, $t5, $s0
  lui   $t6, %hi(mission_folder_setup_entries) 
  addiu $t6, %lo(mission_folder_setup_entries) # addiu $t6, $t6, -0x541c
  sll   $t5, $t5, 2
  addu  $v0, $t5, $t6
  lhu   $v1, 6($v0)
  beqz  $v1, .L7F00E568
   nop   
  jal   get_textptr_for_textID
   move  $a0, $v1
  move  $a0, $s2
  jal   textpointer_load_parse_something
   move  $a1, $v0
  b     .L7F00E57C
   nop   
.L7F00E568:
  jal   get_textptr_for_textID
   lhu   $a0, 4($v0)
  move  $a0, $s2
  jal   textpointer_load_parse_something
   move  $a1, $v0
.L7F00E57C:
  lui   $t7, %hi(j_text_trigger) 
  lw    $t7, %lo(j_text_trigger)($t7)
  bnez  $t7, .L7F00E5C4
   nop   
  jal   strlen
   move  $a0, $s2
  addiu $v1, $v0, -1
  bltz  $v1, .L7F00E5C4
   addu  $v0, $s2, $v1
  lbu   $v1, ($v0)
.L7F00E5A4:
  slti  $at, $v1, 0x61
  bnez  $at, .L7F00E5B4
   addiu $t8, $v1, -0x20
  sb    $t8, ($v0)
.L7F00E5B4:
  addiu $v0, $v0, -1
  sltu  $at, $v0, $s1
  beql  $at, $zero, .L7F00E5A4
   lbu   $v1, ($v0)
.L7F00E5C4:
  lui   $a1, %hi(asc_D_8004F4A0)
  addiu $a1, %lo(asc_D_8004F4A0) # addiu $a1, $a1, -0xb60
  jal   string_append_from_obseg_textbank
   move  $a0, $s2
  lui   $t9, %hi(ptrFirstFontTableSmall) 
  lw    $t9, %lo(ptrFirstFontTableSmall)($t9)
  lui   $a3, %hi(ptrSecondFontTableSmall)
  sw    $zero, 0xc4($sp)
  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
  addiu $a0, $sp, 0xc8
  addiu $a1, $sp, 0xc4
  move  $a2, $s2
  sw    $zero, 0x14($sp)
  sw    $zero, 0xc8($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t9, 0x10($sp)
  lw    $v1, 0xc8($sp)
  lw    $t0, ($fp)
  lw    $a1, ($s7)
  lw    $t1, 0xc4($sp)
  subu  $a2, $t0, $v1
  addiu $a2, $a2, 0x1d
  addu  $t2, $a2, $v1
  addiu $a1, $a1, -0x1f
  sw    $a1, 0x8c($sp)
  sw    $t2, 0x10($sp)
  sw    $a2, 0x88($sp)
  move  $a0, $s4
  sw    $zero, 0x14($sp)
  jal   microcode_constructor_related_to_menus
   addu  $a3, $a1, $t1
  jal   get_video2_settings_txtClipW
   move  $s4, $v0
  sll   $s0, $v0, 0x10
  sra   $t3, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t3
  lui   $t4, %hi(ptrSecondFontTableSmall) 
  lui   $t5, %hi(ptrFirstFontTableSmall) 
  lw    $t5, %lo(ptrFirstFontTableSmall)($t5)
  lw    $t4, %lo(ptrSecondFontTableSmall)($t4)
  ori   $t6, $s5, 0xff
  sw    $t6, 0x18($sp)
  move  $a0, $s4
  addiu $a1, $sp, 0x8c
  addiu $a2, $sp, 0x88
  move  $a3, $s2
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t5, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t4, 0x10($sp)
  lw    $v1, 0xc8($sp)
  lw    $t7, ($fp)
  lw    $a1, ($s7)
  move  $s4, $v0
  subu  $a2, $t7, $v1
  addiu $a2, $a2, 0x1d
  addiu $a1, $a1, -0x1f
  sw    $a1, 0x8c($sp)
  jal   get_video2_settings_txtClipW
   sw    $a2, 0x88($sp)
  sll   $s0, $v0, 0x10
  sra   $t8, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t8
  lui   $t9, %hi(ptrSecondFontTableSmall) 
  lui   $t0, %hi(ptrFirstFontTableSmall) 
  lw    $t0, %lo(ptrFirstFontTableSmall)($t0)
  lw    $t9, %lo(ptrSecondFontTableSmall)($t9)
  ori   $t1, $s5, 0x64
  sw    $t1, 0x18($sp)
  move  $a0, $s4
  addiu $a1, $sp, 0x8c
  addiu $a2, $sp, 0x88
  move  $a3, $s2
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t0, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t9, 0x10($sp)
  move  $s4, $v0
.L7F00E71C:
  addiu $s6, $s6, 1
  li    $at, 4
  bne   $s6, $at, .L7F00E4D4
   addiu $s3, $s3, 5
  lw    $t2, 0xd8($sp)
  li    $at, 5
  addiu $t3, $t2, 1
  bne   $t3, $at, .L7F00E4CC
   sw    $t3, 0xd8($sp)
  jal   add_tab3_previous
   move  $a0, $s4
  jal   load_draw_selected_icon_folder_select
   move  $a0, $v0
  lw    $ra, 0x5c($sp)
  lw    $s0, 0x38($sp)
  lw    $s1, 0x3c($sp)
  lw    $s2, 0x40($sp)
  lw    $s3, 0x44($sp)
  lw    $s4, 0x48($sp)
  lw    $s5, 0x4c($sp)
  lw    $s6, 0x50($sp)
  lw    $s7, 0x54($sp)
  lw    $fp, 0x58($sp)
  jr    $ra
   addiu $sp, $sp, 0xe0
");

void init_menu08_difficultyselect(void) {
  selected_difficulty = -1;
  tab_2_selected = 0;
  tab_3_selected = 0;
  load_walletbond();
}

void update_menu08_difficulty(void) {}

asm(R"
glabel interface_menu08_difficulty
  lui   $t6, %hi(briefingpage) 
  lw    $t6, %lo(briefingpage)($t6)
  addiu $sp, $sp, -0x20
  lui   $a0, %hi(mission_folder_setup_entries+0x14)
  sll   $t7, $t6, 3
  subu  $t7, $t7, $t6
  sll   $t7, $t7, 2
  sw    $ra, 0x14($sp)
  addu  $a0, $a0, $t7
  jal   get_highest_unlocked_difficulty_for_level
   lw    $a0, %lo(mission_folder_setup_entries+0x14)($a0)
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f12
  jal   setvideo_far
   sw    $v0, 0x1c($sp)
  lui   $at, %hi(D_80051A4C)
  jal   video_related_21
   lwc1  $f12, %lo(D_80051A4C)($at)
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f12
  lui   $at, %hi(D_80051A50)
  jal   set_page_height
   lwc1  $f14, %lo(D_80051A50)($at)
  jal   set_video2_settings_offset_24
   move  $a0, $zero
  lui   $a0, %hi(ptr_folder_object_instance)
  jal   disable_all_switches
   lw    $a0, %lo(ptr_folder_object_instance)($a0)
  lui   $a0, %hi(ptr_folder_object_instance)
  lw    $a0, %lo(ptr_folder_object_instance)($a0)
  move  $a1, $zero
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lui   $a0, %hi(ptr_folder_object_instance)
  lw    $a0, %lo(ptr_folder_object_instance)($a0)
  li    $a1, 1
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lui   $a0, %hi(ptr_folder_object_instance)
  lw    $a0, %lo(ptr_folder_object_instance)($a0)
  li    $a1, 3
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lui   $a0, %hi(ptr_folder_object_instance)
  lw    $a0, %lo(ptr_folder_object_instance)($a0)
  li    $a1, 4
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lui   $v1, %hi(mission_difficulty_highlighted)
  lui   $at, %hi(tab_3_highlight)
  addiu $v1, %lo(mission_difficulty_highlighted) # addiu $v1, $v1, -0x687c
  sw    $zero, %lo(tab_3_highlight)($at)
  li    $t8, -1
  jal   isontab3
   sw    $t8, ($v1)
  lui   $v1, %hi(mission_difficulty_highlighted)
  beqz  $v0, .L7F00E8B8
   addiu $v1, %lo(mission_difficulty_highlighted) # addiu $v1, $v1, -0x687c
  li    $t9, 1
  lui   $at, %hi(tab_3_highlight)
  b     .L7F00E95C
   sw    $t9, %lo(tab_3_highlight)($at)
.L7F00E8B8:
  lw    $a0, 0x1c($sp)
  lui   $v0, %hi(cursor_v_pos)
  addiu $v0, %lo(cursor_v_pos) # addiu $v0, $v0, -0x56f4
  slti  $at, $a0, 3
  bnez  $at, .L7F00E8F4
   lui   $at, %hi(D_80051A54)
  lwc1  $f6, %lo(D_80051A54)($at)
  lwc1  $f4, ($v0)
  li    $t0, 3
  c.le.s $f6, $f4
  nop   
  bc1f  .L7F00E8F4
   nop   
  b     .L7F00E95C
   sw    $t0, ($v1)
.L7F00E8F4:
  lui   $v0, %hi(cursor_v_pos)
  slti  $at, $a0, 2
  bnez  $at, .L7F00E92C
   addiu $v0, %lo(cursor_v_pos) # addiu $v0, $v0, -0x56f4
  li    $at, 0x43730000 # 243.000000
  mtc1  $at, $f10
  lwc1  $f8, ($v0)
  li    $t1, 2
  c.le.s $f10, $f8
  nop   
  bc1f  .L7F00E92C
   nop   
  b     .L7F00E95C
   sw    $t1, ($v1)
.L7F00E92C:
  blez  $a0, .L7F00E958
   li    $at, 0x43530000 # 211.000000
  lwc1  $f16, ($v0)
  mtc1  $at, $f18
  li    $a3, 1
  c.le.s $f18, $f16
  nop   
  bc1fl .L7F00E95C
   sw    $zero, ($v1)
  b     .L7F00E95C
   sw    $a3, ($v1)
.L7F00E958:
  sw    $zero, ($v1)
.L7F00E95C:
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 45056
  lui   $v1, %hi(mission_difficulty_highlighted)
  addiu $v1, %lo(mission_difficulty_highlighted) # addiu $v1, $v1, -0x687c
  beqz  $v0, .L7F00E9DC
   li    $a3, 1
  lui   $t2, %hi(tab_3_highlight) 
  lw    $t2, %lo(tab_3_highlight)($t2)
  lui   $at, %hi(tab_3_selected)
  lui   $a0, %hi(ptr_sfx_buf)
  beqz  $t2, .L7F00E9A8
   li    $a1, 199
  sw    $a3, %lo(tab_3_selected)($at)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F00EA0C
   nop   
.L7F00E9A8:
  lw    $v0, ($v1)
  lui   $at, %hi(selected_difficulty)
  lui   $a0, %hi(ptr_sfx_buf)
  bltz  $v0, .L7F00EA0C
   li    $a1, 77
  sw    $v0, %lo(selected_difficulty)($at)
  lui   $at, %hi(tab_2_selected)
  sw    $a3, %lo(tab_2_selected)($at)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F00EA0C
   nop   
.L7F00E9DC:
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 16384
  beqz  $v0, .L7F00EA0C
   li    $a3, 1
  lui   $at, %hi(tab_3_selected)
  lui   $a0, %hi(ptr_sfx_buf)
  sw    $a3, %lo(tab_3_selected)($at)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 199
  jal   play_sfx_a1
   move  $a2, $zero
.L7F00EA0C:
  jal   menu_control_stick_tracking
   nop   
  lui   $t3, %hi(tab_2_selected) 
  lw    $t3, %lo(tab_2_selected)($t3)
  lui   $t4, %hi(selected_difficulty) 
  lui   $t5, %hi(tab_3_selected) 
  beqz  $t3, .L7F00EA70
   nop   
  lw    $t4, %lo(selected_difficulty)($t4)
  li    $at, 3
  move  $a1, $zero
  bne   $t4, $at, .L7F00EA58
   li    $a0, 10
  jal   set_menu_to_mode
   li    $a0, 9
  jal   set_cursor_pos_tab2
   nop   
  b     .L7F00EAB0
   lw    $ra, 0x14($sp)
.L7F00EA58:
  jal   set_menu_to_mode
   move  $a1, $zero
  jal   set_cursor_pos_tab2
   nop   
  b     .L7F00EAB0
   lw    $ra, 0x14($sp)
.L7F00EA70:
  lw    $t5, %lo(tab_3_selected)($t5)
  li    $a0, 7
  beql  $t5, $zero, .L7F00EAB0
   lw    $ra, 0x14($sp)
  jal   set_menu_to_mode
   move  $a1, $zero
  lui   $t6, %hi(briefingpage) 
  lw    $t6, %lo(briefingpage)($t6)
  lui   $a0, %hi(mission_folder_setup_entries+20)
  sll   $t7, $t6, 3
  subu  $t7, $t7, $t6
  sll   $t7, $t7, 2
  addu  $a0, $a0, $t7
  jal   set_cursor_to_stage_solo
   lw    $a0, %lo(mission_folder_setup_entries+20)($a0)
  lw    $ra, 0x14($sp)
.L7F00EAB0:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel print_current_solo_briefing_stage_name
  lui   $a2, %hi(selected_difficulty)
  lw    $a2, %lo(selected_difficulty)($a2)
  addiu $sp, $sp, -0x58
  sw    $s0, 0x38($sp)
  move  $s0, $a1
  sw    $ra, 0x3c($sp)
  bltz  $a2, .L7F00EB6C
   sw    $a0, 0x58($sp)
  jal   get_ptr_difficulty_name
   move  $a0, $a2
  move  $a0, $s0
  jal   textpointer_load_parse_something
   move  $a1, $v0
  jal   get_textptr_for_textID
   li    $a0, 39968
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  li    $t6, 55
  li    $t7, 87
  sw    $t6, 0x54($sp)
  jal   get_video2_settings_txtClipW
   sw    $t7, 0x50($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lui   $t8, %hi(ptrSecondFontTableLarge) 
  lui   $t9, %hi(ptrFirstFontTableLarge) 
  lw    $t9, %lo(ptrFirstFontTableLarge)($t9)
  lw    $t8, %lo(ptrSecondFontTableLarge)($t8)
  lh    $t1, 0x44($sp)
  li    $t0, 255
  sw    $t0, 0x18($sp)
  lw    $a0, 0x58($sp)
  addiu $a1, $sp, 0x54
  addiu $a2, $sp, 0x50
  move  $a3, $s0
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t9, 0x14($sp)
  sw    $t8, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t1, 0x1c($sp)
  sw    $v0, 0x58($sp)
.L7F00EB6C:
  lui   $a0, %hi(briefingpage)
  jal   get_chapter_briefing_entry
   lw    $a0, %lo(briefingpage)($a0)
  bltz  $v0, .L7F00EC60
   sw    $v0, 0x4c($sp)
  jal   get_textptr_for_textID
   li    $a0, 39969
  move  $a0, $s0
  jal   textpointer_load_parse_something
   move  $a1, $v0
  lw    $t2, 0x4c($sp)
  lui   $t4, %hi(mission_folder_setup_entries) 
  addiu $t4, %lo(mission_folder_setup_entries) # addiu $t4, $t4, -0x541c
  sll   $t3, $t2, 3
  subu  $t3, $t3, $t2
  sll   $t3, $t3, 2
  addu  $v1, $t3, $t4
  lw    $a1, ($v1)
  sw    $v1, 0x40($sp)
  jal   string_append_from_obseg_textbank
   move  $a0, $s0
  lui   $a1, %hi(asc_D_8004F4A4)
  addiu $a1, %lo(asc_D_8004F4A4) # addiu $a1, $a1, -0xb5c
  jal   string_append_from_obseg_textbank
   move  $a0, $s0
  lw    $t5, 0x40($sp)
  jal   get_textptr_for_textID
   lhu   $a0, 4($t5)
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  lui   $a1, %hi(asc_D_8004F4A8)
  addiu $a1, %lo(asc_D_8004F4A8) # addiu $a1, $a1, -0xb58
  jal   string_append_from_obseg_textbank
   move  $a0, $s0
  li    $t6, 55
  li    $t7, 103
  sw    $t6, 0x54($sp)
  jal   get_video2_settings_txtClipW
   sw    $t7, 0x50($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lui   $t8, %hi(ptrSecondFontTableLarge) 
  lui   $t9, %hi(ptrFirstFontTableLarge) 
  lw    $t9, %lo(ptrFirstFontTableLarge)($t9)
  lw    $t8, %lo(ptrSecondFontTableLarge)($t8)
  lh    $t1, 0x44($sp)
  li    $t0, 255
  sw    $t0, 0x18($sp)
  lw    $a0, 0x58($sp)
  addiu $a1, $sp, 0x54
  addiu $a2, $sp, 0x50
  move  $a3, $s0
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t9, 0x14($sp)
  sw    $t8, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t1, 0x1c($sp)
  sw    $v0, 0x58($sp)
.L7F00EC60:
  jal   get_textptr_for_textID
   li    $a0, 39970
  move  $a0, $s0
  jal   textpointer_load_parse_something
   move  $a1, $v0
  lui   $t2, %hi(briefingpage) 
  lw    $t2, %lo(briefingpage)($t2)
  lui   $a1, %hi(mission_folder_setup_entries)
  move  $a0, $s0
  sll   $t3, $t2, 3
  subu  $t3, $t3, $t2
  sll   $t3, $t3, 2
  addu  $a1, $a1, $t3
  jal   string_append_from_obseg_textbank
   lw    $a1, %lo(mission_folder_setup_entries)($a1)
  lui   $a1, %hi(asc_D_8004F4AC)
  addiu $a1, %lo(asc_D_8004F4AC) # addiu $a1, $a1, -0xb54
  jal   string_append_from_obseg_textbank
   move  $a0, $s0
  lui   $t4, %hi(briefingpage) 
  lw    $t4, %lo(briefingpage)($t4)
  lui   $a0, %hi(mission_folder_setup_entries+0x4)
  sll   $t5, $t4, 3
  subu  $t5, $t5, $t4
  sll   $t5, $t5, 2
  addu  $a0, $a0, $t5
  jal   get_textptr_for_textID
   lhu   $a0, %lo(mission_folder_setup_entries+0x4)($a0)
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  lui   $a1, %hi(asc_D_8004F4B0)
  addiu $a1, %lo(asc_D_8004F4B0) # addiu $a1, $a1, -0xb50
  jal   string_append_from_obseg_textbank
   move  $a0, $s0
  li    $t6, 55
  li    $t7, 119
  sw    $t6, 0x54($sp)
  jal   get_video2_settings_txtClipW
   sw    $t7, 0x50($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lui   $t8, %hi(ptrSecondFontTableLarge) 
  lui   $t9, %hi(ptrFirstFontTableLarge) 
  lw    $t9, %lo(ptrFirstFontTableLarge)($t9)
  lw    $t8, %lo(ptrSecondFontTableLarge)($t8)
  lh    $t1, 0x44($sp)
  li    $t0, 255
  sw    $t0, 0x18($sp)
  lw    $a0, 0x58($sp)
  addiu $a1, $sp, 0x54
  addiu $a2, $sp, 0x50
  move  $a3, $s0
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t9, 0x14($sp)
  sw    $t8, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t1, 0x1c($sp)
  lw    $ra, 0x3c($sp)
  lw    $s0, 0x38($sp)
  addiu $sp, $sp, 0x58
  jr    $ra
   nop   
");

void set_cursor_pos_difficulty(int arg0) {
  cursor_h_pos = 106.0f;
  cursor_v_pos = (float)((arg0 * 0x1e) + 0xba);
}

asm(R"
glabel constructor_menu08_difficulty
  addiu $sp, $sp, -0xc70
  lui   $t6, %hi(briefingpage) 
  lw    $t6, %lo(briefingpage)($t6)
  sw    $a0, 0xc70($sp)
  lui   $a0, %hi(mission_folder_setup_entries+20)
  sll   $t7, $t6, 3
  subu  $t7, $t7, $t6
  sll   $t7, $t7, 2
  sw    $ra, 0x6c($sp)
  addu  $a0, $a0, $t7
  sw    $fp, 0x68($sp)
  sw    $s7, 0x64($sp)
  sw    $s6, 0x60($sp)
  sw    $s5, 0x5c($sp)
  sw    $s4, 0x58($sp)
  sw    $s3, 0x54($sp)
  sw    $s2, 0x50($sp)
  sw    $s1, 0x4c($sp)
  sw    $s0, 0x48($sp)
  sdc1  $f20, 0x40($sp)
  jal   get_highest_unlocked_difficulty_for_level
   lw    $a0, %lo(mission_folder_setup_entries+20)($a0)
  sw    $v0, 0xc68($sp)
  lw    $a0, 0xc70($sp)
  move  $a1, $zero
  move  $a2, $zero
  jal   set_setfillcolor
   move  $a3, $zero
  sw    $v0, 0xc70($sp)
  jal   insert_generic_fillrect
   move  $a0, $v0
  sw    $v0, 0xc70($sp)
  jal   sub_GAME_7F00D5E8
   move  $a0, $v0
  lui   $t9, %hi(asc_D_8004F4B4) 
  addiu $t9, %lo(asc_D_8004F4B4) # addiu $t9, $t9, -0xb4c
  sw    $v0, 0xc70($sp)
  addiu $t3, $t9, 0xbb8
  addiu $t8, $sp, 0xa4
.L7F00EE34:
  lw    $at, ($t9)
  addiu $t9, $t9, 0xc
  addiu $t8, $t8, 0xc
  sw    $at, -0xc($t8)
  lw    $at, -8($t9)
  sw    $at, -8($t8)
  lw    $at, -4($t9)
  bne   $t9, $t3, .L7F00EE34
   sw    $at, -4($t8)
  jal   microcode_constructor
   move  $a0, $v0
  sw    $v0, 0xc70($sp)
  move  $a0, $v0
  jal   print_current_solo_briefing_stage_name
   addiu $a1, $sp, 0xa4
  sw    $v0, 0xc70($sp)
  jal   get_textptr_for_textID
   li    $a0, 39971
  li    $t4, 55
  li    $t5, 143
  move  $s1, $v0
  sw    $t4, 0xc60($sp)
  jal   get_video2_settings_txtClipW
   sw    $t5, 0xc5c($sp)
  sll   $s0, $v0, 0x10
  sra   $t6, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t6
  lui   $s5, %hi(ptrSecondFontTableLarge)
  lui   $s6, %hi(ptrFirstFontTableLarge)
  addiu $s6, %lo(ptrFirstFontTableLarge) # addiu $s6, $s6, 0xeb4
  addiu $s5, %lo(ptrSecondFontTableLarge) # addiu $s5, $s5, 0xeb8
  lw    $t7, ($s5)
  lw    $t2, ($s6)
  li    $t1, 255
  sw    $t1, 0x18($sp)
  lw    $a0, 0xc70($sp)
  addiu $a1, $sp, 0xc60
  addiu $a2, $sp, 0xc5c
  move  $a3, $s1
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t7, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t2, 0x14($sp)
  lui   $t0, %hi(mission_difficulty_highlighted) 
  lw    $t0, %lo(mission_difficulty_highlighted)($t0)
  sw    $v0, 0xc70($sp)
  lw    $a0, 0xc70($sp)
  bltz  $t0, .L7F00EF50
   lui   $t3, %hi(j_text_trigger) 
  lw    $t3, %lo(j_text_trigger)($t3)
  sll   $v1, $t0, 4
  subu  $v1, $v1, $t0
  beqz  $t3, .L7F00EF24
   li    $t9, 126
  b     .L7F00EF28
   li    $v0, 50
.L7F00EF24:
  move  $v0, $zero
.L7F00EF28:
  sll   $v1, $v1, 1
  addiu $t8, $v1, 0xc3
  li    $t4, 50
  sw    $t4, 0x14($sp)
  sw    $t8, 0x10($sp)
  addiu $a2, $v1, 0xb2
  subu  $a1, $t9, $v0
  jal   microcode_constructor_related_to_menus
   li    $a3, 240
  sw    $v0, 0xc70($sp)
.L7F00EF50:
  move  $s1, $zero
  li    $fp, 2
  li    $s7, 1
  li    $s4, 3
  lw    $s2, 0xa0($sp)
.L7F00EF64:
  beqz  $s1, .L7F00EF74
   lw    $t5, 0xc68($sp)
  slt   $at, $t5, $s1
  bnez  $at, .L7F00F174
.L7F00EF74:
   lui   $t6, %hi(j_text_trigger) 
  lw    $t6, %lo(j_text_trigger)($t6)
  sll   $s3, $s1, 4
  subu  $s3, $s3, $s1
  sll   $s3, $s3, 1
  beqz  $t6, .L7F00EFF8
   addiu $s3, $s3, 0xb4
  beqz  $s1, .L7F00EFB8
   nop   
  beq   $s1, $s7, .L7F00EFC8
   nop   
  beq   $s1, $fp, .L7F00EFD8
   nop   
  beq   $s1, $s4, .L7F00EFE8
   nop   
  b     .L7F00F014
   lw    $t2, ($s6)
.L7F00EFB8:
  jal   get_textptr_for_textID
   li    $a0, 40201
  b     .L7F00F010
   move  $s2, $v0
.L7F00EFC8:
  jal   get_textptr_for_textID
   li    $a0, 40202
  b     .L7F00F010
   move  $s2, $v0
.L7F00EFD8:
  jal   get_textptr_for_textID
   li    $a0, 40203
  b     .L7F00F010
   move  $s2, $v0
.L7F00EFE8:
  jal   get_textptr_for_textID
   li    $a0, 40204
  b     .L7F00F010
   move  $s2, $v0
.L7F00EFF8:
  addiu $s2, $sp, 0xa4
  lui   $a1, %hi(aD_)
  addiu $a1, %lo(aD_) # addiu $a1, $a1, 0x6c
  move  $a0, $s2
  jal   sprintf
   addiu $a2, $s1, 1
.L7F00F010:
  lw    $t2, ($s6)
.L7F00F014:
  addiu $a0, $sp, 0x98
  addiu $a1, $sp, 0x9c
  move  $a2, $s2
  lw    $a3, ($s5)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t2, 0x10($sp)
  lui   $t1, %hi(j_text_trigger) 
  lw    $t1, %lo(j_text_trigger)($t1)
  li    $t3, 130
  move  $v0, $zero
  beqz  $t1, .L7F00F054
   nop   
  lw    $v0, 0x9c($sp)
  b     .L7F00F054
   addiu $v0, $v0, -0xa
.L7F00F054:
  subu  $t9, $t3, $v0
  sw    $t9, 0xc60($sp)
  jal   get_video2_settings_txtClipW
   sw    $s3, 0xc5c($sp)
  sll   $s0, $v0, 0x10
  sra   $t8, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t8
  lw    $t4, ($s5)
  lw    $t5, ($s6)
  li    $t6, 255
  sw    $t6, 0x18($sp)
  lw    $a0, 0xc70($sp)
  addiu $a1, $sp, 0xc60
  addiu $a2, $sp, 0xc5c
  move  $a3, $s2
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t4, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t5, 0x14($sp)
  beqz  $s1, .L7F00F0D8
   sw    $v0, 0xc70($sp)
  beq   $s1, $s7, .L7F00F0E8
   nop   
  beq   $s1, $fp, .L7F00F0F8
   nop   
  beq   $s1, $s4, .L7F00F108
   nop   
  b     .L7F00F118
   li    $t7, 150
.L7F00F0D8:
  jal   get_textptr_for_textID
   li    $a0, 39972
  b     .L7F00F114
   move  $s2, $v0
.L7F00F0E8:
  jal   get_textptr_for_textID
   li    $a0, 39973
  b     .L7F00F114
   move  $s2, $v0
.L7F00F0F8:
  jal   get_textptr_for_textID
   li    $a0, 39974
  b     .L7F00F114
   move  $s2, $v0
.L7F00F108:
  jal   get_textptr_for_textID
   li    $a0, 39975
  move  $s2, $v0
.L7F00F114:
  li    $t7, 150
.L7F00F118:
  sw    $t7, 0xc60($sp)
  jal   get_video2_settings_txtClipW
   sw    $s3, 0xc5c($sp)
  sll   $s0, $v0, 0x10
  sra   $t2, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t2
  lw    $t1, ($s5)
  lw    $t3, ($s6)
  li    $t9, 255
  sw    $t9, 0x18($sp)
  lw    $a0, 0xc70($sp)
  addiu $a1, $sp, 0xc60
  addiu $a2, $sp, 0xc5c
  move  $a3, $s2
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t1, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t3, 0x14($sp)
  sw    $v0, 0xc70($sp)
.L7F00F174:
  addiu $s1, $s1, 1
  slti  $at, $s1, 4
  bnez  $at, .L7F00EF64
   nop   
  sw    $s2, 0xa0($sp)
  jal   add_tab3_previous
   lw    $a0, 0xc70($sp)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f20
  sw    $v0, 0xc70($sp)
  move  $s1, $zero
  addiu $s2, $sp, 0xc70
.L7F00F1A4:
  beqz  $s1, .L7F00F1B4
   lw    $t8, 0xc68($sp)
  slt   $at, $t8, $s1
  bnez  $at, .L7F00F2B8
.L7F00F1B4:
   lui   $a0, %hi(briefingpage)
  lw    $a0, %lo(briefingpage)($a0)
  jal   check_if_stage_completed_on_difficulty
   move  $a1, $s1
  bne   $v0, $s4, .L7F00F2B8
   sll   $t4, $s1, 4
  subu  $t4, $t4, $s1
  sll   $t4, $t4, 1
  addiu $t5, $t4, 0xba
  mtc1  $t5, $f6
  li    $at, 0x438C0000 # 280.000000
  mtc1  $at, $f4
  cvt.s.w $f8, $f6
  lui   $s0, %hi(mainfolderimages)
  lw    $s0, %lo(mainfolderimages)($s0)
  swc1  $f4, 0x90($sp)
  li    $at, 0x4F800000 # 4294967296.000000
  addiu $s0, $s0, 0x30
  swc1  $f8, 0x94($sp)
  lbu   $t6, 4($s0)
  mtc1  $t6, $f10
  bgez  $t6, .L7F00F21C
   cvt.s.w $f16, $f10
  mtc1  $at, $f18
  nop   
  add.s $f16, $f16, $f18
.L7F00F21C:
  mul.s $f4, $f16, $f20
  li    $at, 0x4F800000 # 4294967296.000000
  swc1  $f4, 0x88($sp)
  lbu   $t7, 5($s0)
  mtc1  $t7, $f6
  bgez  $t7, .L7F00F244
   cvt.s.w $f8, $f6
  mtc1  $at, $f10
  nop   
  add.s $f8, $f8, $f10
.L7F00F244:
  mul.s $f18, $f8, $f20
  move  $a0, $s2
  move  $a1, $s0
  li    $a2, 4
  move  $a3, $zero
  sw    $zero, 0x10($sp)
  jal   likely_generate_DL_for_image_declaration
   swc1  $f18, 0x8c($sp)
  lbu   $t2, 5($s0)
  lbu   $a3, 4($s0)
  li    $t1, 1
  li    $t3, 180
  li    $t9, 255
  sw    $t9, 0x2c($sp)
  sw    $t3, 0x20($sp)
  sw    $t1, 0x1c($sp)
  sw    $zero, 0x28($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x18($sp)
  sw    $zero, 0x14($sp)
  sw    $t2, 0x10($sp)
  lbu   $t8, 6($s0)
  sw    $zero, 0x34($sp)
  move  $a0, $s2
  slt   $t4, $zero, $t8
  sw    $t4, 0x30($sp)
  addiu $a1, $sp, 0x90
  jal   display_image_at_on_screen_coord
   addiu $a2, $sp, 0x88
.L7F00F2B8:
  addiu $s1, $s1, 1
  bne   $s1, $s4, .L7F00F1A4
   nop   
  jal   load_draw_selected_icon_folder_select
   lw    $a0, 0xc70($sp)
  lw    $ra, 0x6c($sp)
  ldc1  $f20, 0x40($sp)
  lw    $s0, 0x48($sp)
  lw    $s1, 0x4c($sp)
  lw    $s2, 0x50($sp)
  lw    $s3, 0x54($sp)
  lw    $s4, 0x58($sp)
  lw    $s5, 0x5c($sp)
  lw    $s6, 0x60($sp)
  lw    $s7, 0x64($sp)
  lw    $fp, 0x68($sp)
  jr    $ra
   addiu $sp, $sp, 0xc70
");

void init_menu09_007difficultyselect(void) {
  tab_1_selected = 0;
  tab_2_selected = 0;
  tab_3_selected = 0;
  tab_3_highlight = 0;
  tab_2_highlight = 0;
  tab_1_highlight = 0;
  highlight_enemy_reaction = 0;
  highlight_enemy_health = 0;
  highlight_enemy_accuracy = 0;
  highlight_enemy_damage = 0;
  load_walletbond();
}

void update_menu09_007options(void) {}

asm(R"
glabel interface_menu09_007options
  addiu $sp, $sp, -0x18
  li    $at, 0x42700000 # 60.000000
  sw    $ra, 0x14($sp)
  mtc1  $at, $f12
  jal   setvideo_far
   nop   
  lui   $at, %hi(D_80051A58)
  jal   video_related_21
   lwc1  $f12, %lo(D_80051A58)($at)
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f12
  lui   $at, %hi(D_80051A5C)
  jal   set_page_height
   lwc1  $f14, %lo(D_80051A5C)($at)
  jal   set_video2_settings_offset_24
   move  $a0, $zero
  move  $a0, $zero
  jal   get_controller_buttons_held
   li    $a1, 40960
  bnez  $v0, .L7F00F4CC
   lui   $at, %hi(tab_3_highlight)
  sw    $zero, %lo(tab_3_highlight)($at)
  lui   $at, %hi(tab_2_highlight)
  sw    $zero, %lo(tab_2_highlight)($at)
  lui   $at, %hi(tab_1_highlight)
  sw    $zero, %lo(tab_1_highlight)($at)
  lui   $at, %hi(highlight_enemy_reaction)
  sw    $zero, %lo(highlight_enemy_reaction)($at)
  lui   $at, %hi(highlight_enemy_health)
  sw    $zero, %lo(highlight_enemy_health)($at)
  lui   $at, %hi(highlight_enemy_accuracy)
  sw    $zero, %lo(highlight_enemy_accuracy)($at)
  lui   $at, %hi(highlight_enemy_damage)
  jal   isontab3
   sw    $zero, %lo(highlight_enemy_damage)($at)
  beqz  $v0, .L7F00F414
   li    $t6, 1
  lui   $at, %hi(tab_3_highlight)
  b     .L7F00F4CC
   sw    $t6, %lo(tab_3_highlight)($at)
.L7F00F414:
  jal   isontab2
   nop   
  beqz  $v0, .L7F00F430
   li    $v1, 1
  lui   $at, %hi(tab_2_highlight)
  b     .L7F00F4CC
   sw    $v1, %lo(tab_2_highlight)($at)
.L7F00F430:
  jal   isontab1
   nop   
  beqz  $v0, .L7F00F450
   lui   $at, %hi(cursor_v_pos)
  li    $v1, 1
  lui   $at, %hi(cursor_v_pos)
  b     .L7F00F4CC
   sw    $v1, %lo(tab_1_highlight)($at)
.L7F00F450:
  lwc1  $f4, %lo(cursor_v_pos)($at)
  li    $v1, 1
  trunc.w.s $f6, $f4
  mfc1  $v0, $f6
  nop   
  slti  $at, $v0, 0x107
  bnez  $at, .L7F00F478
   lui   $at, %hi(highlight_enemy_reaction)
  b     .L7F00F4CC
   sw    $v1, %lo(highlight_enemy_reaction)($at)
.L7F00F478:
  slti  $at, $v0, 0xe6
  bnez  $at, .L7F00F490
   li    $v1, 1
  lui   $at, %hi(highlight_enemy_damage)
  b     .L7F00F4CC
   sw    $v1, %lo(highlight_enemy_damage)($at)
.L7F00F490:
  slti  $at, $v0, 0xc5
  bnez  $at, .L7F00F4A8
   li    $v1, 1
  lui   $at, %hi(highlight_enemy_accuracy)
  b     .L7F00F4CC
   sw    $v1, %lo(highlight_enemy_accuracy)($at)
.L7F00F4A8:
  slti  $at, $v0, 0xa4
  bnez  $at, .L7F00F4C4
   li    $v1, 1
  li    $v1, 1
  lui   $at, %hi(highlight_enemy_health)
  b     .L7F00F4CC
   sw    $v1, %lo(highlight_enemy_health)($at)
.L7F00F4C4:
  lui   $at, %hi(tab_2_highlight)
  sw    $v1, %lo(tab_2_highlight)($at)
.L7F00F4CC:
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 4096
  beqz  $v0, .L7F00F504
   li    $v1, 1
  lui   $at, %hi(tab_1_selected)
  lui   $a0, %hi(ptr_sfx_buf)
  sw    $v1, %lo(tab_1_selected)($at)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 199
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F00F5B4
   move  $a0, $zero
.L7F00F504:
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 40960
  beqz  $v0, .L7F00F580
   li    $v1, 1
  lui   $t8, %hi(tab_2_highlight) 
  lw    $t8, %lo(tab_2_highlight)($t8)
  lui   $a0, %hi(ptr_sfx_buf)
  li    $a1, 199
  beqz  $t8, .L7F00F53C
   move  $a2, $zero
  lui   $at, %hi(tab_2_selected)
  b     .L7F00F570
   sw    $v1, %lo(tab_2_selected)($at)
.L7F00F53C:
  lui   $t9, %hi(tab_3_highlight) 
  lw    $t9, %lo(tab_3_highlight)($t9)
  lui   $at, %hi(tab_3_selected)
  lui   $t0, %hi(tab_1_highlight) 
  beqz  $t9, .L7F00F55C
   nop   
  b     .L7F00F570
   sw    $v1, %lo(tab_3_selected)($at)
.L7F00F55C:
  lw    $t0, %lo(tab_1_highlight)($t0)
  lui   $at, %hi(tab_1_selected)
  beqz  $t0, .L7F00F570
   nop   
  sw    $v1, %lo(tab_1_selected)($at)
.L7F00F570:
  jal   play_sfx_a1
   lw    $a0, %lo(ptr_sfx_buf)($a0)
  b     .L7F00F5B4
   move  $a0, $zero
.L7F00F580:
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 16384
  beqz  $v0, .L7F00F5B0
   li    $v1, 1
  lui   $at, %hi(tab_3_selected)
  lui   $a0, %hi(ptr_sfx_buf)
  sw    $v1, %lo(tab_3_selected)($at)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 199
  jal   play_sfx_a1
   move  $a2, $zero
.L7F00F5B0:
  move  $a0, $zero
.L7F00F5B4:
  jal   get_controller_buttons_held
   li    $a1, 40960
  beqz  $v0, .L7F00F6B8
   lui   $a0, %hi(ptr_folder_object_instance)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f2
  lui   $at, %hi(cursor_h_pos)
  lwc1  $f8, %lo(cursor_h_pos)($at)
  li    $at, 0x425C0000 # 55.000000
  mtc1  $at, $f10
  li    $at, 0x43960000 # 300.000000
  mtc1  $at, $f18
  sub.s $f16, $f8, $f10
  lui   $t1, %hi(highlight_enemy_reaction) 
  lui   $at, %hi(slider_007_mode_reaction)
  lui   $t2, %hi(highlight_enemy_health) 
  div.s $f0, $f16, $f18
  c.lt.s $f2, $f0
  nop   
  bc1fl .L7F00F610
   mtc1  $zero, $f2
  mov.s $f0, $f2
  mtc1  $zero, $f2
.L7F00F610:
  nop   
  c.lt.s $f0, $f2
  nop   
  bc1f  .L7F00F628
   nop   
  mov.s $f0, $f2
.L7F00F628:
  lw    $t1, %lo(highlight_enemy_reaction)($t1)
  beqz  $t1, .L7F00F63C
   nop   
  b     .L7F00F6B8
   swc1  $f0, %lo(slider_007_mode_reaction)($at)
.L7F00F63C:
  lw    $t2, %lo(highlight_enemy_health)($t2)
  lui   $t3, %hi(highlight_enemy_accuracy) 
  beqz  $t2, .L7F00F668
   nop   
  mul.s $f4, $f0, $f0
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f6
  lui   $at, %hi(slider_007_mode_health)
  mul.s $f8, $f4, $f6
  b     .L7F00F6B8
   swc1  $f8, %lo(slider_007_mode_health)($at)
.L7F00F668:
  lw    $t3, %lo(highlight_enemy_accuracy)($t3)
  lui   $t4, %hi(highlight_enemy_damage) 
  beqz  $t3, .L7F00F694
   nop   
  mul.s $f10, $f0, $f0
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f16
  lui   $at, %hi(slider_007_mode_accuracy)
  mul.s $f18, $f10, $f16
  b     .L7F00F6B8
   swc1  $f18, %lo(slider_007_mode_accuracy)($at)
.L7F00F694:
  lw    $t4, %lo(highlight_enemy_damage)($t4)
  beqz  $t4, .L7F00F6B8
   nop   
  mul.s $f4, $f0, $f0
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f6
  lui   $at, %hi(slider_007_mode_damage)
  mul.s $f8, $f4, $f6
  swc1  $f8, %lo(slider_007_mode_damage)($at)
.L7F00F6B8:
  jal   disable_all_switches
   lw    $a0, %lo(ptr_folder_object_instance)($a0)
  lui   $a0, %hi(ptr_folder_object_instance)
  lw    $a0, %lo(ptr_folder_object_instance)($a0)
  move  $a1, $zero
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lui   $a0, %hi(ptr_folder_object_instance)
  lw    $a0, %lo(ptr_folder_object_instance)($a0)
  li    $a1, 1
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lui   $a0, %hi(ptr_folder_object_instance)
  lw    $a0, %lo(ptr_folder_object_instance)($a0)
  li    $a1, 3
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lui   $a0, %hi(ptr_folder_object_instance)
  lw    $a0, %lo(ptr_folder_object_instance)($a0)
  li    $a1, 6
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  jal   menu_control_stick_tracking
   nop   
  lui   $t5, %hi(tab_1_selected) 
  lw    $t5, %lo(tab_1_selected)($t5)
  li    $a0, 11
  lui   $t6, %hi(tab_2_selected) 
  beqz  $t5, .L7F00F740
   nop   
  jal   set_menu_to_mode
   li    $a1, 1
  b     .L7F00F78C
   lw    $ra, 0x14($sp)
.L7F00F740:
  lw    $t6, %lo(tab_2_selected)($t6)
  li    $a0, 10
  lui   $t7, %hi(tab_3_selected) 
  beqz  $t6, .L7F00F764
   nop   
  jal   set_menu_to_mode
   move  $a1, $zero
  b     .L7F00F78C
   lw    $ra, 0x14($sp)
.L7F00F764:
  lw    $t7, %lo(tab_3_selected)($t7)
  li    $a0, 8
  beql  $t7, $zero, .L7F00F78C
   lw    $ra, 0x14($sp)
  jal   set_menu_to_mode
   move  $a1, $zero
  lui   $a0, %hi(selected_difficulty)
  jal   set_cursor_pos_difficulty
   lw    $a0, %lo(selected_difficulty)($a0)
  lw    $ra, 0x14($sp)
.L7F00F78C:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel constructor_menu09_007options
  addiu $sp, $sp, -0xc18
  sw    $ra, 0x3c($sp)
  sw    $s0, 0x38($sp)
  move  $a1, $zero
  move  $a2, $zero
  jal   set_setfillcolor
   move  $a3, $zero
  jal   insert_generic_fillrect
   move  $a0, $v0
  jal   sub_GAME_7F00D5E8
   move  $a0, $v0
  lui   $t7, %hi(asc_D_80050074) 
  addiu $t7, %lo(asc_D_80050074) # addiu $t7, $t7, 0x74
  addiu $t0, $t7, 0xbb8
  addiu $t6, $sp, 0x54
.L7F00F7D4:
  lw    $at, ($t7)
  addiu $t7, $t7, 0xc
  addiu $t6, $t6, 0xc
  sw    $at, -0xc($t6)
  lw    $at, -8($t7)
  sw    $at, -8($t6)
  lw    $at, -4($t7)
  bne   $t7, $t0, .L7F00F7D4
   sw    $at, -4($t6)
  jal   microcode_constructor
   move  $a0, $v0
  move  $a0, $v0
  jal   print_current_solo_briefing_stage_name
   addiu $a1, $sp, 0x54
  move  $s0, $v0
  jal   get_textptr_for_textID
   li    $a0, 39976
  li    $t1, 55
  li    $v1, 143
  sw    $v0, 0xc14($sp)
  sw    $t1, 0xc10($sp)
  jal   get_video2_settings_txtClipW
   sw    $v1, 0xc0c($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lui   $t2, %hi(ptrSecondFontTableLarge) 
  lui   $t3, %hi(ptrFirstFontTableLarge) 
  lw    $t3, %lo(ptrFirstFontTableLarge)($t3)
  lw    $t2, %lo(ptrSecondFontTableLarge)($t2)
  lh    $t5, 0x44($sp)
  li    $t4, 255
  sw    $t4, 0x18($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0xc10
  addiu $a2, $sp, 0xc0c
  lw    $a3, 0xc14($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t3, 0x14($sp)
  sw    $t2, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t5, 0x1c($sp)
  move  $s0, $v0
  jal   get_textptr_for_textID
   li    $a0, 39978
  li    $t9, 57
  li    $v1, 164
  li    $t8, 192
  li    $t0, 50
  sw    $v0, 0xc14($sp)
  sw    $t9, 0xc10($sp)
  sw    $t0, 0x14($sp)
  sw    $t8, 0x10($sp)
  sw    $v1, 0xc0c($sp)
  move  $a0, $s0
  li    $a1, 55
  li    $a2, 181
  jal   microcode_constructor_related_to_menus
   li    $a3, 355
  lui   $at, %hi(slider_007_mode_health)
  lwc1  $f4, %lo(slider_007_mode_health)($at)
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f6
  move  $s0, $v0
  jal   sqrtf
   div.s $f12, $f4, $f6
  li    $at, 0x43960000 # 300.000000
  mtc1  $at, $f8
  lw    $v1, 0xc0c($sp)
  li    $t1, 100
  mul.s $f10, $f0, $f8
  addiu $t6, $v1, 0x1c
  sw    $t6, 0x10($sp)
  sw    $t1, 0x14($sp)
  move  $a0, $s0
  li    $a1, 55
  addiu $a2, $v1, 0x11
  trunc.w.s $f16, $f10
  mfc1  $a3, $f16
  jal   microcode_constructor_related_to_menus
   addiu $a3, $a3, 0x37
  lui   $t2, %hi(highlight_enemy_health) 
  lw    $t2, %lo(highlight_enemy_health)($t2)
  move  $s0, $v0
  beqz  $t2, .L7F00F95C
   nop   
  lw    $v1, 0xc0c($sp)
  li    $t4, 50
  sw    $t4, 0x14($sp)
  addiu $t3, $v1, 0xe
  sw    $t3, 0x10($sp)
  move  $a0, $v0
  li    $a1, 55
  li    $a3, 199
  jal   microcode_constructor_related_to_menus
   addiu $a2, $v1, -1
  move  $s0, $v0
.L7F00F95C:
  jal   get_video2_settings_txtClipW
   nop   
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lui   $t5, %hi(ptrSecondFontTableLarge) 
  lui   $t9, %hi(ptrFirstFontTableLarge) 
  lw    $t9, %lo(ptrFirstFontTableLarge)($t9)
  lw    $t5, %lo(ptrSecondFontTableLarge)($t5)
  lh    $t0, 0x44($sp)
  li    $t8, 255
  sw    $t8, 0x18($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0xc10
  addiu $a2, $sp, 0xc0c
  lw    $a3, 0xc14($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t9, 0x14($sp)
  sw    $t5, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t0, 0x1c($sp)
  lui   $at, %hi(slider_007_mode_health)
  lwc1  $f18, %lo(slider_007_mode_health)($at)
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f4
  lui   $a1, %hi(aD)
  move  $s0, $v0
  mul.s $f6, $f18, $f4
  addiu $a1, %lo(aD) # addiu $a1, $a1, 0xc2c
  addiu $a0, $sp, 0x54
  trunc.w.s $f8, $f6
  mfc1  $a2, $f8
  jal   sprintf
   nop   
  lui   $t6, %hi(ptrFirstFontTableLarge) 
  lw    $t6, %lo(ptrFirstFontTableLarge)($t6)
  lui   $a3, %hi(ptrSecondFontTableLarge)
  sw    $zero, 0x4c($sp)
  sw    $zero, 0x50($sp)
  lw    $a3, %lo(ptrSecondFontTableLarge)($a3)
  addiu $a0, $sp, 0x50
  addiu $a1, $sp, 0x4c
  addiu $a2, $sp, 0x54
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t6, 0x10($sp)
  lw    $t1, 0x4c($sp)
  li    $t2, 285
  li    $v1, 164
  subu  $t3, $t2, $t1
  sw    $t3, 0xc10($sp)
  jal   get_video2_settings_txtClipW
   sw    $v1, 0xc0c($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lui   $t4, %hi(ptrSecondFontTableLarge) 
  lui   $t5, %hi(ptrFirstFontTableLarge) 
  lw    $t5, %lo(ptrFirstFontTableLarge)($t5)
  lw    $t4, %lo(ptrSecondFontTableLarge)($t4)
  lh    $t8, 0x44($sp)
  li    $t9, 255
  sw    $t9, 0x18($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0xc10
  addiu $a2, $sp, 0xc0c
  addiu $a3, $sp, 0x54
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t5, 0x14($sp)
  sw    $t4, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t8, 0x1c($sp)
  move  $s0, $v0
  jal   get_textptr_for_textID
   li    $a0, 39979
  li    $t0, 57
  li    $v1, 197
  li    $t7, 225
  li    $t6, 50
  sw    $v0, 0xc14($sp)
  sw    $t0, 0xc10($sp)
  sw    $t6, 0x14($sp)
  sw    $t7, 0x10($sp)
  sw    $v1, 0xc0c($sp)
  move  $a0, $s0
  li    $a1, 55
  li    $a2, 214
  jal   microcode_constructor_related_to_menus
   li    $a3, 355
  lui   $at, %hi(slider_007_mode_accuracy)
  lwc1  $f10, %lo(slider_007_mode_accuracy)($at)
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f16
  move  $s0, $v0
  jal   sqrtf
   div.s $f12, $f10, $f16
  li    $at, 0x43960000 # 300.000000
  mtc1  $at, $f18
  lw    $v1, 0xc0c($sp)
  li    $t3, 100
  mul.s $f4, $f0, $f18
  addiu $t1, $v1, 0x1c
  sw    $t1, 0x10($sp)
  sw    $t3, 0x14($sp)
  move  $a0, $s0
  li    $a1, 55
  addiu $a2, $v1, 0x11
  trunc.w.s $f6, $f4
  mfc1  $a3, $f6
  jal   microcode_constructor_related_to_menus
   addiu $a3, $a3, 0x37
  lui   $t4, %hi(highlight_enemy_accuracy) 
  lw    $t4, %lo(highlight_enemy_accuracy)($t4)
  move  $s0, $v0
  beqz  $t4, .L7F00FB60
   nop   
  lw    $v1, 0xc0c($sp)
  li    $t9, 50
  sw    $t9, 0x14($sp)
  addiu $t5, $v1, 0xe
  sw    $t5, 0x10($sp)
  move  $a0, $v0
  li    $a1, 55
  li    $a3, 199
  jal   microcode_constructor_related_to_menus
   addiu $a2, $v1, -1
  move  $s0, $v0
.L7F00FB60:
  jal   get_video2_settings_txtClipW
   nop   
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lui   $t8, %hi(ptrSecondFontTableLarge) 
  lui   $t0, %hi(ptrFirstFontTableLarge) 
  lw    $t0, %lo(ptrFirstFontTableLarge)($t0)
  lw    $t8, %lo(ptrSecondFontTableLarge)($t8)
  lh    $t6, 0x44($sp)
  li    $t7, 255
  sw    $t7, 0x18($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0xc10
  addiu $a2, $sp, 0xc0c
  lw    $a3, 0xc14($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t0, 0x14($sp)
  sw    $t8, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t6, 0x1c($sp)
  lui   $at, %hi(slider_007_mode_accuracy)
  lwc1  $f8, %lo(slider_007_mode_accuracy)($at)
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f10
  lui   $a1, %hi(aD_0)
  move  $s0, $v0
  mul.s $f16, $f8, $f10
  addiu $a1, %lo(aD_0) # addiu $a1, $a1, 0xc34
  addiu $a0, $sp, 0x54
  trunc.w.s $f18, $f16
  mfc1  $a2, $f18
  jal   sprintf
   nop   
  lui   $t1, %hi(ptrFirstFontTableLarge) 
  lw    $t1, %lo(ptrFirstFontTableLarge)($t1)
  lui   $a3, %hi(ptrSecondFontTableLarge)
  sw    $zero, 0x4c($sp)
  sw    $zero, 0x50($sp)
  lw    $a3, %lo(ptrSecondFontTableLarge)($a3)
  addiu $a0, $sp, 0x50
  addiu $a1, $sp, 0x4c
  addiu $a2, $sp, 0x54
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t1, 0x10($sp)
  lw    $t3, 0x4c($sp)
  li    $t4, 285
  li    $v1, 197
  subu  $t5, $t4, $t3
  sw    $t5, 0xc10($sp)
  jal   get_video2_settings_txtClipW
   sw    $v1, 0xc0c($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lui   $t9, %hi(ptrSecondFontTableLarge) 
  lui   $t8, %hi(ptrFirstFontTableLarge) 
  lw    $t8, %lo(ptrFirstFontTableLarge)($t8)
  lw    $t9, %lo(ptrSecondFontTableLarge)($t9)
  lh    $t7, 0x44($sp)
  li    $t0, 255
  sw    $t0, 0x18($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0xc10
  addiu $a2, $sp, 0xc0c
  addiu $a3, $sp, 0x54
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t8, 0x14($sp)
  sw    $t9, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t7, 0x1c($sp)
  move  $s0, $v0
  jal   get_textptr_for_textID
   li    $a0, 39980
  li    $t6, 57
  li    $v1, 230
  li    $t2, 258
  li    $t1, 50
  sw    $v0, 0xc14($sp)
  sw    $t6, 0xc10($sp)
  sw    $t1, 0x14($sp)
  sw    $t2, 0x10($sp)
  sw    $v1, 0xc0c($sp)
  move  $a0, $s0
  li    $a1, 55
  li    $a2, 247
  jal   microcode_constructor_related_to_menus
   li    $a3, 355
  lui   $at, %hi(slider_007_mode_damage)
  lwc1  $f4, %lo(slider_007_mode_damage)($at)
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f6
  move  $s0, $v0
  jal   sqrtf
   div.s $f12, $f4, $f6
  li    $at, 0x43960000 # 300.000000
  mtc1  $at, $f8
  lw    $v1, 0xc0c($sp)
  li    $t5, 100
  mul.s $f10, $f0, $f8
  addiu $t3, $v1, 0x1c
  sw    $t3, 0x10($sp)
  sw    $t5, 0x14($sp)
  move  $a0, $s0
  li    $a1, 55
  addiu $a2, $v1, 0x11
  trunc.w.s $f16, $f10
  mfc1  $a3, $f16
  jal   microcode_constructor_related_to_menus
   addiu $a3, $a3, 0x37
  lui   $t9, %hi(highlight_enemy_damage) 
  lw    $t9, %lo(highlight_enemy_damage)($t9)
  move  $s0, $v0
  beqz  $t9, .L7F00FD64
   nop   
  lw    $v1, 0xc0c($sp)
  li    $t0, 50
  sw    $t0, 0x14($sp)
  addiu $t8, $v1, 0xe
  sw    $t8, 0x10($sp)
  move  $a0, $v0
  li    $a1, 55
  li    $a3, 199
  jal   microcode_constructor_related_to_menus
   addiu $a2, $v1, -1
  move  $s0, $v0
.L7F00FD64:
  jal   get_video2_settings_txtClipW
   nop   
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lui   $t7, %hi(ptrSecondFontTableLarge) 
  lui   $t6, %hi(ptrFirstFontTableLarge) 
  lw    $t6, %lo(ptrFirstFontTableLarge)($t6)
  lw    $t7, %lo(ptrSecondFontTableLarge)($t7)
  lh    $t1, 0x44($sp)
  li    $t2, 255
  sw    $t2, 0x18($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0xc10
  addiu $a2, $sp, 0xc0c
  lw    $a3, 0xc14($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t6, 0x14($sp)
  sw    $t7, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t1, 0x1c($sp)
  lui   $at, %hi(slider_007_mode_damage)
  lwc1  $f18, %lo(slider_007_mode_damage)($at)
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f4
  lui   $a1, %hi(aD_1)
  move  $s0, $v0
  mul.s $f6, $f18, $f4
  addiu $a1, %lo(aD_1) # addiu $a1, $a1, 0xc3c
  addiu $a0, $sp, 0x54
  trunc.w.s $f8, $f6
  mfc1  $a2, $f8
  jal   sprintf
   nop   
  lui   $t3, %hi(ptrFirstFontTableLarge) 
  lw    $t3, %lo(ptrFirstFontTableLarge)($t3)
  lui   $a3, %hi(ptrSecondFontTableLarge)
  sw    $zero, 0x4c($sp)
  sw    $zero, 0x50($sp)
  lw    $a3, %lo(ptrSecondFontTableLarge)($a3)
  addiu $a0, $sp, 0x50
  addiu $a1, $sp, 0x4c
  addiu $a2, $sp, 0x54
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t3, 0x10($sp)
  lw    $t5, 0x4c($sp)
  li    $t9, 285
  li    $v1, 230
  subu  $t8, $t9, $t5
  sw    $t8, 0xc10($sp)
  jal   get_video2_settings_txtClipW
   sw    $v1, 0xc0c($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lui   $t0, %hi(ptrSecondFontTableLarge) 
  lui   $t7, %hi(ptrFirstFontTableLarge) 
  lw    $t7, %lo(ptrFirstFontTableLarge)($t7)
  lw    $t0, %lo(ptrSecondFontTableLarge)($t0)
  lh    $t2, 0x44($sp)
  li    $t6, 255
  sw    $t6, 0x18($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0xc10
  addiu $a2, $sp, 0xc0c
  addiu $a3, $sp, 0x54
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t7, 0x14($sp)
  sw    $t0, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t2, 0x1c($sp)
  move  $s0, $v0
  jal   get_textptr_for_textID
   li    $a0, 39977
  li    $t1, 57
  li    $v1, 263
  li    $t4, 291
  li    $t3, 50
  sw    $v0, 0xc14($sp)
  sw    $t1, 0xc10($sp)
  sw    $t3, 0x14($sp)
  sw    $t4, 0x10($sp)
  sw    $v1, 0xc0c($sp)
  move  $a0, $s0
  li    $a1, 55
  li    $a2, 280
  jal   microcode_constructor_related_to_menus
   li    $a3, 355
  lui   $at, %hi(slider_007_mode_reaction)
  lwc1  $f10, %lo(slider_007_mode_reaction)($at)
  li    $at, 0x43960000 # 300.000000
  mtc1  $at, $f16
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  mul.s $f18, $f10, $f16
  lw    $v1, 0xc0c($sp)
  li    $t8, 100
  sw    $t8, 0x14($sp)
  addiu $t5, $v1, 0x1c
  sw    $t5, 0x10($sp)
  move  $a0, $v0
  mul.s $f6, $f18, $f4
  li    $a1, 55
  addiu $a2, $v1, 0x11
  trunc.w.s $f8, $f6
  mfc1  $a3, $f8
  jal   microcode_constructor_related_to_menus
   addiu $a3, $a3, 0x37
  lui   $t0, %hi(highlight_enemy_reaction) 
  lw    $t0, %lo(highlight_enemy_reaction)($t0)
  move  $s0, $v0
  beqz  $t0, .L7F00FF60
   nop   
  lw    $v1, 0xc0c($sp)
  li    $t6, 50
  sw    $t6, 0x14($sp)
  addiu $t7, $v1, 0xe
  sw    $t7, 0x10($sp)
  move  $a0, $v0
  li    $a1, 55
  li    $a3, 199
  jal   microcode_constructor_related_to_menus
   addiu $a2, $v1, -1
  move  $s0, $v0
.L7F00FF60:
  jal   get_video2_settings_txtClipW
   nop   
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lui   $t2, %hi(ptrSecondFontTableLarge) 
  lui   $t1, %hi(ptrFirstFontTableLarge) 
  lw    $t1, %lo(ptrFirstFontTableLarge)($t1)
  lw    $t2, %lo(ptrSecondFontTableLarge)($t2)
  lh    $t3, 0x44($sp)
  li    $t4, 255
  sw    $t4, 0x18($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0xc10
  addiu $a2, $sp, 0xc0c
  lw    $a3, 0xc14($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t1, 0x14($sp)
  sw    $t2, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t3, 0x1c($sp)
  lui   $at, %hi(slider_007_mode_reaction)
  lwc1  $f10, %lo(slider_007_mode_reaction)($at)
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f16
  lui   $a1, %hi(aD_2)
  move  $s0, $v0
  mul.s $f18, $f10, $f16
  addiu $a1, %lo(aD_2) # addiu $a1, $a1, 0xc44
  addiu $a0, $sp, 0x54
  trunc.w.s $f4, $f18
  mfc1  $a2, $f4
  jal   sprintf
   nop   
  lui   $t5, %hi(ptrFirstFontTableLarge) 
  lw    $t5, %lo(ptrFirstFontTableLarge)($t5)
  lui   $a3, %hi(ptrSecondFontTableLarge)
  sw    $zero, 0x4c($sp)
  sw    $zero, 0x50($sp)
  lw    $a3, %lo(ptrSecondFontTableLarge)($a3)
  addiu $a0, $sp, 0x50
  addiu $a1, $sp, 0x4c
  addiu $a2, $sp, 0x54
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t5, 0x10($sp)
  lw    $t8, 0x4c($sp)
  li    $t0, 285
  li    $v1, 263
  subu  $t7, $t0, $t8
  sw    $t7, 0xc10($sp)
  jal   get_video2_settings_txtClipW
   sw    $v1, 0xc0c($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lui   $t6, %hi(ptrSecondFontTableLarge) 
  lui   $t2, %hi(ptrFirstFontTableLarge) 
  lw    $t2, %lo(ptrFirstFontTableLarge)($t2)
  lw    $t6, %lo(ptrSecondFontTableLarge)($t6)
  lh    $t4, 0x44($sp)
  li    $t1, 255
  sw    $t1, 0x18($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0xc10
  addiu $a2, $sp, 0xc0c
  addiu $a3, $sp, 0x54
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t2, 0x14($sp)
  sw    $t6, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t4, 0x1c($sp)
  jal   add_tab1_start
   move  $a0, $v0
  jal   add_tab3_previous
   move  $a0, $v0
  jal   add_tab2_next
   move  $a0, $v0
  jal   load_draw_selected_icon_folder_select
   move  $a0, $v0
  lw    $ra, 0x3c($sp)
  lw    $s0, 0x38($sp)
  addiu $sp, $sp, 0xc18
  jr    $ra
   nop   
");

asm(R"
glabel get_player_control_style
  sll   $t6, $a0, 2
  lui   $v0, %hi(controlstyle_player)
  addu  $v0, $v0, $t6
  jr    $ra
   lw    $v0, %lo(controlstyle_player)($v0)
");

int check_if_mp_stage_unlocked(int stage) {
  int players;
  if (!multi_stage_setups[stage].min_player) {
    return 0;
  }
  players = get_selected_num_players();
  if (multi_stage_setups[stage].max_player < players) {
    return 0;
  }
  if (multi_stage_setups[stage].unlock_after == -1) {
    return 1;
  }
  if (isStageUnlockedAtDifficulty(selected_folder_num,
                                  multi_stage_setups[stage].unlock_after,
                                  DIFFICULTY_AGENT)) {
    return 1;
  }
  return 0;
}

asm(R"
glabel select_game_length
  lui   $t6, %hi(scenario) 
  lw    $t6, %lo(scenario)($t6)
  li    $at, 2
  lui   $v0, %hi(game_length)
  beq   $t6, $at, .L7F0101B0
   addiu $v0, %lo(game_length) # addiu $v0, $v0, -0x4ac8
  lui   $v0, %hi(game_length)
  addiu $v0, %lo(game_length) # addiu $v0, $v0, -0x4ac8
  lw    $t7, ($v0)
  li    $at, 7
  addiu $t8, $t7, 1
  div   $zero, $t8, $at
  mfhi  $t9
  sw    $t9, ($v0)
  jr    $ra
   nop   
.L7F0101B0:
  lw    $t0, ($v0)
  addiu $t1, $t0, 1
  bgez  $t1, .L7F0101CC
   andi  $t2, $t1, 3
  beqz  $t2, .L7F0101CC
   nop   
  addiu $t2, $t2, -4
.L7F0101CC:
  sw    $t2, ($v0)
  jr    $ra
   nop   
");

asm(R"
glabel copy_aim_settings_to_playerdata
  lui   $t6, %hi(aim_sight_adjustment) 
  lw    $t6, %lo(aim_sight_adjustment)($t6)
  lui   $t8, %hi(mp_sight_adjust_table) 
  addiu $t8, %lo(mp_sight_adjust_table) # addiu $t8, $t8, -0x4af0
  sll   $t7, $t6, 2
  addu  $v0, $t7, $t8
  lbu   $v1, 3($v0)
  lui   $at, %hi(player1_player_data+0x6A)
  sb    $v1, %lo(player1_player_data+0x6A)($at)
  lbu   $a0, 2($v0)
  lui   $at, %hi(player1_player_data+0x6B)
  sb    $a0, %lo(player1_player_data+0x6B)($at)
  lui   $at, %hi(player2_player_data+0x6A)
  sb    $v1, %lo(player2_player_data+0x6A)($at)
  lui   $at, %hi(player2_player_data+0x6B)
  sb    $a0, %lo(player2_player_data+0x6B)($at)
  lui   $at, %hi(player3_player_data+0x6A)
  sb    $v1, %lo(player3_player_data+0x6A)($at)
  lui   $at, %hi(player3_player_data+0x6B)
  sb    $a0, %lo(player3_player_data+0x6B)($at)
  lui   $at, %hi(player4_player_data+0x6A)
  sb    $v1, %lo(player4_player_data+0x6A)($at)
  lui   $at, %hi(player4_player_data+0x6B)
  jr    $ra
   sb    $a0, %lo(player4_player_data+0x6B)($at)
");

asm(R"
glabel advance_aim_settings_selection
  lui   $v0, %hi(aim_sight_adjustment)
  addiu $v0, %lo(aim_sight_adjustment) # addiu $v0, $v0, -0x4ac4
  lw    $t6, ($v0)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  addiu $t7, $t6, 1
  bgez  $t7, .L7F010268
   andi  $t8, $t7, 3
  beqz  $t8, .L7F010268
   nop   
  addiu $t8, $t8, -4
.L7F010268:
  jal   copy_aim_settings_to_playerdata
   sw    $t8, ($v0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

void unlock_all_mp_chars(void) { num_chars_selectable_mp = 0x40; }

int get_selected_num_players(void) {
  if (gamemode == GAMEMODE_MULTI) {
    return selected_num_players;
  }
  return 1;
}

unsigned short get_player_mp_char_head(int player) {
  if ((&player_1_char)[player] < 0) {
    return mp_chr_setup[player].head;
  }
  return mp_chr_setup[(&player_1_char)[player]].head;
}

unsigned char get_player_mp_char_gender(int player) {
  if ((&player_1_char)[player] < 0) {
    return mp_chr_setup[player].gender;
  }
  return mp_chr_setup[(&player_1_char)[player]].gender;
}

unsigned short get_player_mp_char_body(int player) {
  if ((&player_1_char)[player] < 0) {
    return mp_chr_setup[player].body;
  }
  return mp_chr_setup[(&player_1_char)[player]].body;
}

float get_player_mp_handicap(int player) {
  return MP_handicap_table[(&handicap_player1)[player]].damage_modifier;
}

float get_player_mp_char_height(int player) {
  if ((&player_1_char)[player] < 0) {
    return mp_chr_setup[player].pov;
  }
  return mp_chr_setup[(&player_1_char)[player]].pov;
}

int get_mp_timelimit(void) { return multi_game_lengths[game_length].time; }

int get_mp_pointlimit(void) { return multi_game_lengths[game_length].points; }

void reset_mp_options_for_scenario(MPSCENARIOS scenarioid) {
  scenario = scenarioid;

  unlock_stage_select = 1;
  unlock_game_length = 1;
  unlock_chars = 1;
  unlock_weapon_select = 1;
  unlock_handicap = 1;
  unlock_control_style = 1;
  unlock_aim_sight = 1;

  switch (scenario) {
  case SCENARIO_NORMAL:
  case SCENARIO_2v2:
  case SCENARIO_3v1:
  case SCENARIO_2v1:
    if (6 < game_length) {
      game_length = 2;
    }
    if (0xd < get_mp_weapon_set()) {
      set_mp_weapon_set(0xd);
    }
    break;
  case SCENARIO_YOLT:
    game_length = 7;

    if (0xd < get_mp_weapon_set()) {
      set_mp_weapon_set(0xd);
    }
    unlock_game_length = 0;
    break;
  case SCENARIO_TLD:
    if (3 < game_length) {
      game_length = 2;
    }
    if (0xd < get_mp_weapon_set()) {
      set_mp_weapon_set(0xd);
    }
    break;
  case SCENARIO_MWTGG:
    if (6 < game_length) {
      game_length = 2;
    }
    set_mp_weapon_set(0xd);
    unlock_weapon_select = 0;
    break;
  case SCENARIO_LTK:
    if (6 < game_length) {
      game_length = 2;
    }
    set_mp_weapon_set(1);
    unlock_handicap = 0;
  }
}

asm(R"
glabel init_mp_options_for_scenario
  addiu $sp, $sp, -0x20
  sw    $s0, 0x18($sp)
  slti  $at, $a0, 2
  move  $s0, $a0
  beqz  $at, .L7F010624
   sw    $ra, 0x1c($sp)
  li    $s0, 2
.L7F010624:
  lui   $v0, %hi(selected_num_players)
  addiu $v0, %lo(selected_num_players) # addiu $v0, $v0, -0x4ae0
  sw    $s0, ($v0)
  move  $v1, $zero
  blez  $s0, .L7F0106A8
   move  $a2, $s0
  lui   $a1, %hi(player_1_char)
  lui   $t2, %hi(controlstyle_player) 
  lui   $t0, %hi(handicap_player1) 
  addiu $t0, %lo(handicap_player1) # addiu $t0, $t0, -0x6858
  addiu $t2, %lo(controlstyle_player) # addiu $t2, $t2, -0x6848
  addiu $a1, %lo(player_1_char) # addiu $a1, $a1, -0x4adc
  move  $a0, $zero
  li    $t1, 5
  li    $a3, -1
.L7F010660:
  lw    $t6, ($a1)
  addu  $t7, $t0, $a0
  slti  $at, $s0, 3
  bne   $a3, $t6, .L7F01067C
   addu  $v0, $t2, $a0
  sw    $v1, ($a1)
  sw    $t1, ($t7)
.L7F01067C:
  bnez  $at, .L7F010698
   addiu $v1, $v1, 1
  lw    $t8, ($v0)
  slti  $at, $t8, 4
  bnezl $at, .L7F01069C
   slt   $at, $v1, $a2
  sw    $zero, ($v0)
.L7F010698:
  slt   $at, $v1, $a2
.L7F01069C:
  addiu $a0, $a0, 4
  bnez  $at, .L7F010660
   addiu $a1, $a1, 4
.L7F0106A8:
  lui   $t9, %hi(scenario) 
  lw    $t9, %lo(scenario)($t9)
  lui   $t4, %hi(mp_player_counts) 
  addiu $t4, %lo(mp_player_counts) # addiu $t4, $t4, -0x4fac
  sll   $t3, $t9, 2
  addu  $v0, $t3, $t4
  lbu   $t5, 3($v0)
  slt   $at, $t5, $a2
  bnez  $at, .L7F0106E0
   nop   
  lbu   $t6, 2($v0)
  slt   $at, $a2, $t6
  beqz  $at, .L7F0106F0
   nop   
.L7F0106E0:
  jal   reset_mp_options_for_scenario
   move  $a0, $zero
  lui   $a2, %hi(selected_num_players)
  lw    $a2, %lo(selected_num_players)($a2)
.L7F0106F0:
  lui   $v0, %hi(MP_stage_selected)
  addiu $v0, %lo(MP_stage_selected) # addiu $v0, $v0, -0x4acc
  lw    $t7, ($v0)
  lui   $t9, %hi(multi_stage_setups+20)
  li    $t3, 1
  sll   $t8, $t7, 2
  subu  $t8, $t8, $t7
  sll   $t8, $t8, 3
  addu  $t9, $t9, $t8
  lw    $t9, %lo(multi_stage_setups+20)($t9)
  slt   $at, $t9, $a2
  beql  $at, $zero, .L7F01072C
   lw    $ra, 0x1c($sp)
  sw    $t3, ($v0)
  lw    $ra, 0x1c($sp)
.L7F01072C:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

void init_menu0E_mpoptions(void) {
  int numplayers;

  tab_1_selected = false;
  tab_2_selected = false;
  tab_3_selected = false;
  tab_3_highlight = false;
  tab_2_highlight = false;
  tab_1_highlight = false;

  if (maybe_is_in_menu != false) {
    sfx_c_700091E8(0x7fff);
    musicTrack1Vol(0x7fff);
    music1_playing = false;
    musicTrack1Play(M_FOLDERS);
    maybe_is_in_menu = false;
  }

  if (selected_num_players == 0) {
    numplayers = get_attached_controller_count();
    init_mp_options_for_scenario(numplayers);
  }

  if (check_if_mp_stage_unlocked(MP_stage_selected) == false) {
    MP_stage_selected = MP_STAGE_TEMPLE;
  }

  highlight_players = false;
  highlight_scenario = false;
  highlight_gameselect = false;
  highlight_gamelength = false;
  highlight_character = false;
  highlight_weaponselect = false;
  highlight_health = false;
  highlight_controlstyle = false;
  highlight_aimadjustment = false;
  load_walletbond();
}

void update_menu0E_mpoptions(void) {}

asm(R"
.late_rodata
glabel menu0E_aspect
.word 0x3FAAAAAB /*1.3333334;*/
glabel menu0E_pageheight
.word 0x461C4000 /*10000.0;*/

.text
glabel interface_menu0E_mpoptions
  addiu $sp, $sp, -0x40
  li    $at, 0x42700000 # 60.000000
  sw    $ra, 0x14($sp)
  mtc1  $at, $f12
  sw    $zero, 0x3c($sp)
  sw    $zero, 0x38($sp)
  sw    $zero, 0x34($sp)
  sw    $zero, 0x30($sp)
  sw    $zero, 0x2c($sp)
  sw    $zero, 0x28($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x20($sp)
  jal   setvideo_far
   sw    $zero, 0x1c($sp)
  lui   $at, %hi(menu0E_aspect)
  jal   video_related_21
   lwc1  $f12, %lo(menu0E_aspect)($at)
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f12
  lui   $at, %hi(menu0E_pageheight)
  jal   set_page_height
   lwc1  $f14, %lo(menu0E_pageheight)($at)
  jal   set_video2_settings_offset_24
   move  $a0, $zero
  jal   get_attached_controller_count
   nop   
  slti  $at, $v0, 2
  beqz  $at, .L7F0108D0
   li    $a0, 6
  jal   set_menu_to_mode
   move  $a1, $zero
  lui   $a0, %hi(gamemode)
  jal   set_menu_cursor_pos_to_setting
   lw    $a0, %lo(gamemode)($a0)
.L7F0108D0:
  jal   get_attached_controller_count
   nop   
  lui   $t6, %hi(selected_num_players) 
  lw    $t6, %lo(selected_num_players)($t6)
  slt   $at, $v0, $t6
  beql  $at, $zero, .L7F010900
   move  $a0, $zero
  jal   get_attached_controller_count
   nop   
  jal   init_mp_options_for_scenario
   move  $a0, $v0
  move  $a0, $zero
.L7F010900:
  jal   get_controller_buttons_held
   li    $a1, 40960
  bnez  $v0, .L7F010AF4
   lui   $at, %hi(tab_3_highlight)
  sw    $zero, %lo(tab_3_highlight)($at)
  lui   $at, %hi(tab_2_highlight)
  sw    $zero, %lo(tab_2_highlight)($at)
  lui   $at, %hi(tab_1_highlight)
  sw    $zero, %lo(tab_1_highlight)($at)
  lui   $at, %hi(highlight_players)
  sw    $zero, %lo(highlight_players)($at)
  lui   $at, %hi(highlight_scenario)
  sw    $zero, %lo(highlight_scenario)($at)
  lui   $at, %hi(highlight_gameselect)
  sw    $zero, %lo(highlight_gameselect)($at)
  lui   $at, %hi(highlight_gamelength)
  sw    $zero, %lo(highlight_gamelength)($at)
  lui   $at, %hi(highlight_character)
  sw    $zero, %lo(highlight_character)($at)
  lui   $at, %hi(highlight_weaponselect)
  sw    $zero, %lo(highlight_weaponselect)($at)
  lui   $at, %hi(highlight_health)
  sw    $zero, %lo(highlight_health)($at)
  lui   $at, %hi(highlight_controlstyle)
  sw    $zero, %lo(highlight_controlstyle)($at)
  lui   $at, %hi(highlight_aimadjustment)
  jal   isontab3
   sw    $zero, %lo(highlight_aimadjustment)($at)
  beqz  $v0, .L7F010984
   li    $t7, 1
  lui   $at, %hi(tab_3_highlight)
  b     .L7F010AF4
   sw    $t7, %lo(tab_3_highlight)($at)
.L7F010984:
  jal   isontab1
   nop   
  beqz  $v0, .L7F0109A4
   lui   $at, %hi(cursor_v_pos)
  li    $v1, 1
  lui   $at, %hi(tab_1_highlight)
  b     .L7F010AF4
   sw    $v1, %lo(tab_1_highlight)($at)
.L7F0109A4:
  lwc1  $f4, %lo(cursor_v_pos)($at)
  lui   $t9, %hi(unlock_aim_sight) 
  trunc.w.s $f6, $f4
  mfc1  $v0, $f6
  nop   
  slti  $at, $v0, 0x119
  bnezl $at, .L7F0109E4
   slti  $at, $v0, 0x105
  lw    $t9, %lo(unlock_aim_sight)($t9)
  li    $v1, 1
  lui   $at, %hi(highlight_aimadjustment)
  beql  $t9, $zero, .L7F0109E4
   slti  $at, $v0, 0x105
  b     .L7F010AF4
   sw    $v1, %lo(highlight_aimadjustment)($at)
  slti  $at, $v0, 0x105
.L7F0109E4:
  bnez  $at, .L7F010A08
   lui   $t0, %hi(unlock_control_style) 
  lw    $t0, %lo(unlock_control_style)($t0)
  li    $v1, 1
  lui   $at, %hi(highlight_controlstyle)
  beql  $t0, $zero, .L7F010A0C
   slti  $at, $v0, 0xf1
  b     .L7F010AF4
   sw    $v1, %lo(highlight_controlstyle)($at)
.L7F010A08:
  slti  $at, $v0, 0xf1
.L7F010A0C:
  bnez  $at, .L7F010A30
   lui   $t1, %hi(unlock_handicap) 
  lw    $t1, %lo(unlock_handicap)($t1)
  li    $v1, 1
  lui   $at, %hi(highlight_health)
  beql  $t1, $zero, .L7F010A34
   slti  $at, $v0, 0xdd
  b     .L7F010AF4
   sw    $v1, %lo(highlight_health)($at)
.L7F010A30:
  slti  $at, $v0, 0xdd
.L7F010A34:
  bnez  $at, .L7F010A58
   lui   $t2, %hi(unlock_chars) 
  lw    $t2, %lo(unlock_chars)($t2)
  li    $v1, 1
  lui   $at, %hi(highlight_character)
  beql  $t2, $zero, .L7F010A5C
   slti  $at, $v0, 0xc9
  b     .L7F010AF4
   sw    $v1, %lo(highlight_character)($at)
.L7F010A58:
  slti  $at, $v0, 0xc9
.L7F010A5C:
  bnez  $at, .L7F010A80
   lui   $t3, %hi(unlock_weapon_select) 
  lw    $t3, %lo(unlock_weapon_select)($t3)
  li    $v1, 1
  lui   $at, %hi(highlight_weaponselect)
  beql  $t3, $zero, .L7F010A84
   slti  $at, $v0, 0xb5
  b     .L7F010AF4
   sw    $v1, %lo(highlight_weaponselect)($at)
.L7F010A80:
  slti  $at, $v0, 0xb5
.L7F010A84:
  bnez  $at, .L7F010AA8
   lui   $t4, %hi(unlock_game_length) 
  lw    $t4, %lo(unlock_game_length)($t4)
  li    $v1, 1
  lui   $at, %hi(highlight_gamelength)
  beql  $t4, $zero, .L7F010AAC
   slti  $at, $v0, 0xa1
  b     .L7F010AF4
   sw    $v1, %lo(highlight_gamelength)($at)
.L7F010AA8:
  slti  $at, $v0, 0xa1
.L7F010AAC:
  bnez  $at, .L7F010AD0
   lui   $t5, %hi(unlock_stage_select) 
  lw    $t5, %lo(unlock_stage_select)($t5)
  li    $v1, 1
  lui   $at, %hi(highlight_gameselect)
  beql  $t5, $zero, .L7F010AD4
   slti  $at, $v0, 0x8d
  b     .L7F010AF4
   sw    $v1, %lo(highlight_gameselect)($at)
.L7F010AD0:
  slti  $at, $v0, 0x8d
.L7F010AD4:
  bnez  $at, .L7F010AEC
   li    $v1, 1
  li    $v1, 1
  lui   $at, %hi(highlight_scenario)
  b     .L7F010AF4
   sw    $v1, %lo(highlight_scenario)($at)
.L7F010AEC:
  lui   $at, %hi(highlight_players)
  sw    $v1, %lo(highlight_players)($at)
.L7F010AF4:
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 4096
  beqz  $v0, .L7F010B2C
   li    $v1, 1
  lui   $at, %hi(tab_1_selected)
  lui   $a0, %hi(ptr_sfx_buf)
  sw    $v1, %lo(tab_1_selected)($at)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 199
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F010CB0
   nop   
.L7F010B2C:
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 40960
  beqz  $v0, .L7F010C80
   li    $v1, 1
  lui   $t6, %hi(tab_3_highlight) 
  lw    $t6, %lo(tab_3_highlight)($t6)
  lui   $t7, %hi(tab_1_highlight) 
  lui   $a0, %hi(ptr_sfx_buf)
  beqz  $t6, .L7F010B60
   li    $a1, 199
  lui   $at, %hi(tab_3_selected)
  sw    $v1, %lo(tab_3_selected)($at)
.L7F010B60:
  lw    $t7, %lo(tab_1_highlight)($t7)
  lui   $at, %hi(tab_1_selected)
  lui   $t8, %hi(highlight_players) 
  beqz  $t7, .L7F010B7C
   move  $a2, $zero
  b     .L7F010C70
   sw    $v1, %lo(tab_1_selected)($at)
.L7F010B7C:
  lw    $t8, %lo(highlight_players)($t8)
  li    $t9, 1
  lui   $t0, %hi(highlight_scenario) 
  beqz  $t8, .L7F010B98
   nop   
  b     .L7F010C70
   sw    $t9, 0x3c($sp)
.L7F010B98:
  lw    $t0, %lo(highlight_scenario)($t0)
  li    $t1, 1
  lui   $t2, %hi(highlight_gameselect) 
  beqz  $t0, .L7F010BB4
   nop   
  b     .L7F010C70
   sw    $t1, 0x38($sp)
.L7F010BB4:
  lw    $t2, %lo(highlight_gameselect)($t2)
  li    $t3, 1
  lui   $t4, %hi(highlight_gamelength) 
  beqz  $t2, .L7F010BD0
   nop   
  b     .L7F010C70
   sw    $t3, 0x34($sp)
.L7F010BD0:
  lw    $t4, %lo(highlight_gamelength)($t4)
  li    $t5, 1
  lui   $t6, %hi(highlight_character) 
  beqz  $t4, .L7F010BEC
   nop   
  b     .L7F010C70
   sw    $t5, 0x30($sp)
.L7F010BEC:
  lw    $t6, %lo(highlight_character)($t6)
  li    $t7, 1
  lui   $t8, %hi(highlight_weaponselect) 
  beqz  $t6, .L7F010C08
   nop   
  b     .L7F010C70
   sw    $t7, 0x2c($sp)
.L7F010C08:
  lw    $t8, %lo(highlight_weaponselect)($t8)
  li    $t9, 1
  lui   $t0, %hi(highlight_health) 
  beqz  $t8, .L7F010C24
   nop   
  b     .L7F010C70
   sw    $t9, 0x28($sp)
.L7F010C24:
  lw    $t0, %lo(highlight_health)($t0)
  li    $t1, 1
  lui   $t2, %hi(highlight_controlstyle) 
  beqz  $t0, .L7F010C40
   nop   
  b     .L7F010C70
   sw    $t1, 0x24($sp)
.L7F010C40:
  lw    $t2, %lo(highlight_controlstyle)($t2)
  li    $t3, 1
  lui   $t4, %hi(highlight_aimadjustment) 
  beqz  $t2, .L7F010C5C
   nop   
  b     .L7F010C70
   sw    $t3, 0x20($sp)
.L7F010C5C:
  lw    $t4, %lo(highlight_aimadjustment)($t4)
  li    $t5, 1
  beqz  $t4, .L7F010C70
   nop   
  sw    $t5, 0x1c($sp)
.L7F010C70:
  jal   play_sfx_a1
   lw    $a0, %lo(ptr_sfx_buf)($a0)
  b     .L7F010CB0
   nop   
.L7F010C80:
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 16384
  beqz  $v0, .L7F010CB0
   li    $v1, 1
  lui   $at, %hi(tab_3_selected)
  lui   $a0, %hi(ptr_sfx_buf)
  sw    $v1, %lo(tab_3_selected)($at)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 199
  jal   play_sfx_a1
   move  $a2, $zero
.L7F010CB0:
  lui   $a0, %hi(ptr_folder_object_instance)
  jal   disable_all_switches
   lw    $a0, %lo(ptr_folder_object_instance)($a0)
  lui   $a0, %hi(ptr_folder_object_instance)
  lw    $a0, %lo(ptr_folder_object_instance)($a0)
  move  $a1, $zero
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lui   $a0, %hi(ptr_folder_object_instance)
  lw    $a0, %lo(ptr_folder_object_instance)($a0)
  li    $a1, 1
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lui   $a0, %hi(ptr_folder_object_instance)
  lw    $a0, %lo(ptr_folder_object_instance)($a0)
  li    $a1, 3
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lui   $a0, %hi(ptr_folder_object_instance)
  lw    $a0, %lo(ptr_folder_object_instance)($a0)
  li    $a1, 5
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  jal   menu_control_stick_tracking
   nop   
  lui   $t6, %hi(tab_3_selected) 
  lw    $t6, %lo(tab_3_selected)($t6)
  li    $a0, 6
  lui   $t7, %hi(tab_1_selected) 
  beqz  $t6, .L7F010D48
   nop   
  jal   set_menu_to_mode
   move  $a1, $zero
  lui   $a0, %hi(gamemode)
  jal   set_menu_cursor_pos_to_setting
   lw    $a0, %lo(gamemode)($a0)
  b     .L7F010F04
   lw    $ra, 0x14($sp)
.L7F010D48:
  lw    $t7, %lo(tab_1_selected)($t7)
  lui   $t8, %hi(MP_stage_selected) 
  lw    $t3, 0x3c($sp)
  beqz  $t7, .L7F010DF4
   nop   
  lw    $t8, %lo(MP_stage_selected)($t8)
  lui   $v0, %hi(multi_stage_setups+8)
  lui   $at, %hi(selected_stage)
  sll   $t9, $t8, 2
  subu  $t9, $t9, $t8
  sll   $t9, $t9, 3
  addu  $v0, $v0, $t9
  lw    $v0, %lo(multi_stage_setups+8)($v0)
  bgez  $v0, .L7F010DD0
   nop   
.L7F010D84:
  jal   get_random_value
   nop   
  li    $at, 11
  divu  $zero, $v0, $at
  mfhi  $v1
  sll   $t0, $v1, 2
  subu  $t0, $t0, $v1
  sll   $t0, $t0, 3
  lui   $t1, %hi(multi_stage_setups+32)
  addu  $t1, $t1, $t0
  lw    $t1, %lo(multi_stage_setups+32)($t1)
  lui   $at, %hi(selected_stage)
  addiu $a0, $v1, 1
  jal   check_if_mp_stage_unlocked
   sw    $t1, %lo(selected_stage)($at)
  beqz  $v0, .L7F010D84
   nop   
  b     .L7F010DD8
   li    $t2, -1
.L7F010DD0:
  sw    $v0, %lo(selected_stage)($at)
  li    $t2, -1
.L7F010DD8:
  lui   $at, %hi(briefingpage)
  sw    $t2, %lo(briefingpage)($at)
  li    $a0, 11
  jal   set_menu_to_mode
   li    $a1, 1
  b     .L7F010F04
   lw    $ra, 0x14($sp)
.L7F010DF4:
  beqz  $t3, .L7F010E34
   lw    $t4, 0x38($sp)
  jal   get_attached_controller_count
   nop   
  lui   $v1, %hi(selected_num_players)
  lw    $v1, %lo(selected_num_players)($v1)
  addiu $v1, $v1, 1
  slt   $at, $v0, $v1
  beqz  $at, .L7F010E24
   move  $a0, $v1
  b     .L7F010E24
   li    $a0, 2
.L7F010E24:
  jal   init_mp_options_for_scenario
   nop   
  b     .L7F010F04
   lw    $ra, 0x14($sp)
.L7F010E34:
  beqz  $t4, .L7F010E50
   lw    $t5, 0x34($sp)
  li    $a0, 19
  jal   set_menu_to_mode
   move  $a1, $zero
  b     .L7F010F04
   lw    $ra, 0x14($sp)
.L7F010E50:
  beqz  $t5, .L7F010E6C
   lw    $t6, 0x30($sp)
  li    $a0, 18
  jal   set_menu_to_mode
   move  $a1, $zero
  b     .L7F010F04
   lw    $ra, 0x14($sp)
.L7F010E6C:
  beqz  $t6, .L7F010E84
   lw    $t7, 0x2c($sp)
  jal   select_game_length
   nop   
  b     .L7F010F04
   lw    $ra, 0x14($sp)
.L7F010E84:
  beqz  $t7, .L7F010EA0
   lw    $t8, 0x28($sp)
  li    $a0, 15
  jal   set_menu_to_mode
   move  $a1, $zero
  b     .L7F010F04
   lw    $ra, 0x14($sp)
.L7F010EA0:
  beqz  $t8, .L7F010EB8
   lw    $t9, 0x24($sp)
  jal   advance_mp_weapon_set_by_one_save_value
   nop   
  b     .L7F010F04
   lw    $ra, 0x14($sp)
.L7F010EB8:
  beqz  $t9, .L7F010ED4
   lw    $t0, 0x20($sp)
  li    $a0, 16
  jal   set_menu_to_mode
   move  $a1, $zero
  b     .L7F010F04
   lw    $ra, 0x14($sp)
.L7F010ED4:
  beqz  $t0, .L7F010EF0
   lw    $t1, 0x1c($sp)
  li    $a0, 17
  jal   set_menu_to_mode
   move  $a1, $zero
  b     .L7F010F04
   lw    $ra, 0x14($sp)
.L7F010EF0:
  beql  $t1, $zero, .L7F010F04
   lw    $ra, 0x14($sp)
  jal   advance_aim_settings_selection
   nop   
  lw    $ra, 0x14($sp)
.L7F010F04:
  addiu $sp, $sp, 0x40
  jr    $ra
   nop   
");

asm(R"
glabel constructor_menu0E_mpoptions
  addiu $sp, $sp, -0x68
  sw    $ra, 0x3c($sp)
  sw    $s0, 0x38($sp)
  move  $a1, $zero
  move  $a2, $zero
  jal   set_setfillcolor
   move  $a3, $zero
  jal   insert_generic_fillrect
   move  $a0, $v0
  jal   sub_GAME_7F00D5E8
   move  $a0, $v0
  jal   microcode_constructor
   move  $a0, $v0
  move  $s0, $v0
  jal   get_textptr_for_textID
   li    $a0, 40012
  li    $t6, 55
  li    $t7, 95
  sw    $v0, 0x64($sp)
  sw    $t6, 0x58($sp)
  jal   get_video2_settings_txtClipW
   sw    $t7, 0x54($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lui   $t8, %hi(ptrSecondFontTableLarge) 
  lui   $t9, %hi(ptrFirstFontTableLarge) 
  lw    $t9, %lo(ptrFirstFontTableLarge)($t9)
  lw    $t8, %lo(ptrSecondFontTableLarge)($t8)
  lh    $t1, 0x44($sp)
  li    $t0, 255
  sw    $t0, 0x18($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x58
  addiu $a2, $sp, 0x54
  lw    $a3, 0x64($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t9, 0x14($sp)
  sw    $t8, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t1, 0x1c($sp)
  move  $s0, $v0
  jal   get_textptr_for_textID
   li    $a0, 40013
  lui   $t2, %hi(ptrFirstFontTableLarge) 
  lw    $t2, %lo(ptrFirstFontTableLarge)($t2)
  lui   $a3, %hi(ptrSecondFontTableLarge)
  sw    $v0, 0x64($sp)
  lw    $a3, %lo(ptrSecondFontTableLarge)($a3)
  addiu $a0, $sp, 0x50
  addiu $a1, $sp, 0x4c
  move  $a2, $v0
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t2, 0x10($sp)
  lui   $t5, %hi(highlight_players) 
  lw    $t5, %lo(highlight_players)($t5)
  li    $t3, 57
  li    $t4, 121
  sw    $t3, 0x58($sp)
  beqz  $t5, .L7F011038
   sw    $t4, 0x54($sp)
  lw    $a3, 0x4c($sp)
  li    $t6, 135
  li    $t7, 50
  sw    $t7, 0x14($sp)
  sw    $t6, 0x10($sp)
  move  $a0, $s0
  li    $a1, 55
  li    $a2, 120
  jal   microcode_constructor_related_to_menus
   addiu $a3, $a3, 0x3c
  move  $s0, $v0
.L7F011038:
  jal   get_video2_settings_txtClipW
   nop   
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lui   $t8, %hi(ptrSecondFontTableLarge) 
  lui   $t9, %hi(ptrFirstFontTableLarge) 
  lw    $t9, %lo(ptrFirstFontTableLarge)($t9)
  lw    $t8, %lo(ptrSecondFontTableLarge)($t8)
  lh    $t1, 0x44($sp)
  li    $t0, 255
  sw    $t0, 0x18($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x58
  addiu $a2, $sp, 0x54
  lw    $a3, 0x64($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t9, 0x14($sp)
  sw    $t8, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t1, 0x1c($sp)
  move  $s0, $v0
  jal   get_textptr_for_textID
   li    $a0, 40014
  lui   $t2, %hi(ptrFirstFontTableLarge) 
  lw    $t2, %lo(ptrFirstFontTableLarge)($t2)
  lui   $a3, %hi(ptrSecondFontTableLarge)
  sw    $v0, 0x64($sp)
  lw    $a3, %lo(ptrSecondFontTableLarge)($a3)
  addiu $a0, $sp, 0x50
  addiu $a1, $sp, 0x4c
  move  $a2, $v0
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t2, 0x10($sp)
  lui   $t5, %hi(highlight_scenario) 
  lw    $t5, %lo(highlight_scenario)($t5)
  li    $t3, 57
  li    $t4, 141
  sw    $t3, 0x58($sp)
  beqz  $t5, .L7F011110
   sw    $t4, 0x54($sp)
  lw    $a3, 0x4c($sp)
  li    $t6, 155
  li    $t7, 50
  sw    $t7, 0x14($sp)
  sw    $t6, 0x10($sp)
  move  $a0, $s0
  li    $a1, 55
  li    $a2, 140
  jal   microcode_constructor_related_to_menus
   addiu $a3, $a3, 0x3c
  move  $s0, $v0
.L7F011110:
  jal   get_video2_settings_txtClipW
   nop   
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lui   $t8, %hi(ptrSecondFontTableLarge) 
  lui   $t9, %hi(ptrFirstFontTableLarge) 
  lw    $t9, %lo(ptrFirstFontTableLarge)($t9)
  lw    $t8, %lo(ptrSecondFontTableLarge)($t8)
  lh    $t1, 0x44($sp)
  li    $t0, 255
  sw    $t0, 0x18($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x58
  addiu $a2, $sp, 0x54
  lw    $a3, 0x64($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t9, 0x14($sp)
  sw    $t8, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t1, 0x1c($sp)
  move  $s0, $v0
  jal   get_textptr_for_textID
   li    $a0, 40015
  lui   $t2, %hi(ptrFirstFontTableLarge) 
  lw    $t2, %lo(ptrFirstFontTableLarge)($t2)
  lui   $a3, %hi(ptrSecondFontTableLarge)
  sw    $v0, 0x64($sp)
  lw    $a3, %lo(ptrSecondFontTableLarge)($a3)
  addiu $a0, $sp, 0x50
  addiu $a1, $sp, 0x4c
  move  $a2, $v0
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t2, 0x10($sp)
  lui   $t5, %hi(highlight_gameselect) 
  lw    $t5, %lo(highlight_gameselect)($t5)
  li    $t3, 57
  li    $t4, 161
  sw    $t3, 0x58($sp)
  beqz  $t5, .L7F0111E8
   sw    $t4, 0x54($sp)
  lw    $a3, 0x4c($sp)
  li    $t6, 175
  li    $t7, 50
  sw    $t7, 0x14($sp)
  sw    $t6, 0x10($sp)
  move  $a0, $s0
  li    $a1, 55
  li    $a2, 160
  jal   microcode_constructor_related_to_menus
   addiu $a3, $a3, 0x3c
  move  $s0, $v0
.L7F0111E8:
  lui   $t8, %hi(unlock_stage_select) 
  lw    $t8, %lo(unlock_stage_select)($t8)
  beql  $t8, $zero, .L7F011204
   li    $v1, 112
  b     .L7F011204
   li    $v1, 255
  li    $v1, 112
.L7F011204:
  jal   get_video2_settings_txtClipW
   sw    $v1, 0x48($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lui   $t9, %hi(ptrSecondFontTableLarge) 
  lui   $t0, %hi(ptrFirstFontTableLarge) 
  lw    $t0, %lo(ptrFirstFontTableLarge)($t0)
  lw    $t9, %lo(ptrSecondFontTableLarge)($t9)
  lw    $v1, 0x48($sp)
  lh    $t1, 0x44($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x58
  addiu $a2, $sp, 0x54
  lw    $a3, 0x64($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t0, 0x14($sp)
  sw    $t9, 0x10($sp)
  sw    $v1, 0x18($sp)
  jal   write_text_at_abs_coord
   sw    $t1, 0x1c($sp)
  move  $s0, $v0
  jal   get_textptr_for_textID
   li    $a0, 40016
  lui   $t2, %hi(ptrFirstFontTableLarge) 
  lw    $t2, %lo(ptrFirstFontTableLarge)($t2)
  lui   $a3, %hi(ptrSecondFontTableLarge)
  sw    $v0, 0x64($sp)
  lw    $a3, %lo(ptrSecondFontTableLarge)($a3)
  addiu $a0, $sp, 0x50
  addiu $a1, $sp, 0x4c
  move  $a2, $v0
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t2, 0x10($sp)
  lui   $t5, %hi(highlight_gamelength) 
  lw    $t5, %lo(highlight_gamelength)($t5)
  li    $t3, 57
  li    $t4, 181
  sw    $t3, 0x58($sp)
  beqz  $t5, .L7F0112DC
   sw    $t4, 0x54($sp)
  lw    $a3, 0x4c($sp)
  li    $t6, 195
  li    $t7, 50
  sw    $t7, 0x14($sp)
  sw    $t6, 0x10($sp)
  move  $a0, $s0
  li    $a1, 55
  li    $a2, 180
  jal   microcode_constructor_related_to_menus
   addiu $a3, $a3, 0x3c
  move  $s0, $v0
.L7F0112DC:
  lui   $t8, %hi(unlock_game_length) 
  lw    $t8, %lo(unlock_game_length)($t8)
  beql  $t8, $zero, .L7F0112F8
   li    $v1, 112
  b     .L7F0112F8
   li    $v1, 255
  li    $v1, 112
.L7F0112F8:
  jal   get_video2_settings_txtClipW
   sw    $v1, 0x48($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lui   $t9, %hi(ptrSecondFontTableLarge) 
  lui   $t0, %hi(ptrFirstFontTableLarge) 
  lw    $t0, %lo(ptrFirstFontTableLarge)($t0)
  lw    $t9, %lo(ptrSecondFontTableLarge)($t9)
  lw    $v1, 0x48($sp)
  lh    $t1, 0x44($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x58
  addiu $a2, $sp, 0x54
  lw    $a3, 0x64($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t0, 0x14($sp)
  sw    $t9, 0x10($sp)
  sw    $v1, 0x18($sp)
  jal   write_text_at_abs_coord
   sw    $t1, 0x1c($sp)
  move  $s0, $v0
  jal   get_textptr_for_textID
   li    $a0, 40017
  lui   $t2, %hi(ptrFirstFontTableLarge) 
  lw    $t2, %lo(ptrFirstFontTableLarge)($t2)
  lui   $a3, %hi(ptrSecondFontTableLarge)
  sw    $v0, 0x64($sp)
  lw    $a3, %lo(ptrSecondFontTableLarge)($a3)
  addiu $a0, $sp, 0x50
  addiu $a1, $sp, 0x4c
  move  $a2, $v0
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t2, 0x10($sp)
  lui   $t5, %hi(highlight_weaponselect) 
  lw    $t5, %lo(highlight_weaponselect)($t5)
  li    $t3, 57
  li    $t4, 201
  sw    $t3, 0x58($sp)
  beqz  $t5, .L7F0113D0
   sw    $t4, 0x54($sp)
  lw    $a3, 0x4c($sp)
  li    $t6, 215
  li    $t7, 50
  sw    $t7, 0x14($sp)
  sw    $t6, 0x10($sp)
  move  $a0, $s0
  li    $a1, 55
  li    $a2, 200
  jal   microcode_constructor_related_to_menus
   addiu $a3, $a3, 0x3c
  move  $s0, $v0
.L7F0113D0:
  lui   $t8, %hi(unlock_weapon_select) 
  lw    $t8, %lo(unlock_weapon_select)($t8)
  beql  $t8, $zero, .L7F0113EC
   li    $v1, 112
  b     .L7F0113EC
   li    $v1, 255
  li    $v1, 112
.L7F0113EC:
  jal   get_video2_settings_txtClipW
   sw    $v1, 0x48($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lui   $t9, %hi(ptrSecondFontTableLarge) 
  lui   $t0, %hi(ptrFirstFontTableLarge) 
  lw    $t0, %lo(ptrFirstFontTableLarge)($t0)
  lw    $t9, %lo(ptrSecondFontTableLarge)($t9)
  lw    $v1, 0x48($sp)
  lh    $t1, 0x44($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x58
  addiu $a2, $sp, 0x54
  lw    $a3, 0x64($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t0, 0x14($sp)
  sw    $t9, 0x10($sp)
  sw    $v1, 0x18($sp)
  jal   write_text_at_abs_coord
   sw    $t1, 0x1c($sp)
  move  $s0, $v0
  jal   get_textptr_for_textID
   li    $a0, 40018
  lui   $t2, %hi(ptrFirstFontTableLarge) 
  lw    $t2, %lo(ptrFirstFontTableLarge)($t2)
  lui   $a3, %hi(ptrSecondFontTableLarge)
  sw    $v0, 0x64($sp)
  lw    $a3, %lo(ptrSecondFontTableLarge)($a3)
  addiu $a0, $sp, 0x50
  addiu $a1, $sp, 0x4c
  move  $a2, $v0
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t2, 0x10($sp)
  lui   $t5, %hi(highlight_character) 
  lw    $t5, %lo(highlight_character)($t5)
  li    $t3, 57
  li    $t4, 221
  sw    $t3, 0x58($sp)
  beqz  $t5, .L7F0114C4
   sw    $t4, 0x54($sp)
  lw    $a3, 0x4c($sp)
  li    $t6, 235
  li    $t7, 50
  sw    $t7, 0x14($sp)
  sw    $t6, 0x10($sp)
  move  $a0, $s0
  li    $a1, 55
  li    $a2, 220
  jal   microcode_constructor_related_to_menus
   addiu $a3, $a3, 0x3c
  move  $s0, $v0
.L7F0114C4:
  lui   $t8, %hi(unlock_chars) 
  lw    $t8, %lo(unlock_chars)($t8)
  beql  $t8, $zero, .L7F0114E0
   li    $v1, 112
  b     .L7F0114E0
   li    $v1, 255
  li    $v1, 112
.L7F0114E0:
  jal   get_video2_settings_txtClipW
   sw    $v1, 0x48($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lui   $t9, %hi(ptrSecondFontTableLarge) 
  lui   $t0, %hi(ptrFirstFontTableLarge) 
  lw    $t0, %lo(ptrFirstFontTableLarge)($t0)
  lw    $t9, %lo(ptrSecondFontTableLarge)($t9)
  lw    $v1, 0x48($sp)
  lh    $t1, 0x44($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x58
  addiu $a2, $sp, 0x54
  lw    $a3, 0x64($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t0, 0x14($sp)
  sw    $t9, 0x10($sp)
  sw    $v1, 0x18($sp)
  jal   write_text_at_abs_coord
   sw    $t1, 0x1c($sp)
  move  $s0, $v0
  jal   get_textptr_for_textID
   li    $a0, 40019
  lui   $t2, %hi(ptrFirstFontTableLarge) 
  lw    $t2, %lo(ptrFirstFontTableLarge)($t2)
  lui   $a3, %hi(ptrSecondFontTableLarge)
  sw    $v0, 0x64($sp)
  lw    $a3, %lo(ptrSecondFontTableLarge)($a3)
  addiu $a0, $sp, 0x50
  addiu $a1, $sp, 0x4c
  move  $a2, $v0
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t2, 0x10($sp)
  lui   $t5, %hi(highlight_health) 
  lw    $t5, %lo(highlight_health)($t5)
  li    $t3, 57
  li    $t4, 241
  sw    $t3, 0x58($sp)
  beqz  $t5, .L7F0115B8
   sw    $t4, 0x54($sp)
  lw    $a3, 0x4c($sp)
  li    $t6, 255
  li    $t7, 50
  sw    $t7, 0x14($sp)
  sw    $t6, 0x10($sp)
  move  $a0, $s0
  li    $a1, 55
  li    $a2, 240
  jal   microcode_constructor_related_to_menus
   addiu $a3, $a3, 0x3c
  move  $s0, $v0
.L7F0115B8:
  lui   $t8, %hi(unlock_handicap) 
  lw    $t8, %lo(unlock_handicap)($t8)
  beql  $t8, $zero, .L7F0115D4
   li    $v1, 112
  b     .L7F0115D4
   li    $v1, 255
  li    $v1, 112
.L7F0115D4:
  jal   get_video2_settings_txtClipW
   sw    $v1, 0x48($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lui   $t9, %hi(ptrSecondFontTableLarge) 
  lui   $t0, %hi(ptrFirstFontTableLarge) 
  lw    $t0, %lo(ptrFirstFontTableLarge)($t0)
  lw    $t9, %lo(ptrSecondFontTableLarge)($t9)
  lw    $v1, 0x48($sp)
  lh    $t1, 0x44($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x58
  addiu $a2, $sp, 0x54
  lw    $a3, 0x64($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t0, 0x14($sp)
  sw    $t9, 0x10($sp)
  sw    $v1, 0x18($sp)
  jal   write_text_at_abs_coord
   sw    $t1, 0x1c($sp)
  move  $s0, $v0
  jal   get_textptr_for_textID
   li    $a0, 40222
  lui   $t2, %hi(ptrFirstFontTableLarge) 
  lw    $t2, %lo(ptrFirstFontTableLarge)($t2)
  lui   $a3, %hi(ptrSecondFontTableLarge)
  sw    $v0, 0x64($sp)
  lw    $a3, %lo(ptrSecondFontTableLarge)($a3)
  addiu $a0, $sp, 0x50
  addiu $a1, $sp, 0x4c
  move  $a2, $v0
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t2, 0x10($sp)
  lui   $t5, %hi(highlight_controlstyle) 
  lw    $t5, %lo(highlight_controlstyle)($t5)
  li    $t3, 57
  li    $t4, 261
  sw    $t3, 0x58($sp)
  beqz  $t5, .L7F0116AC
   sw    $t4, 0x54($sp)
  lw    $a3, 0x4c($sp)
  li    $t6, 275
  li    $t7, 50
  sw    $t7, 0x14($sp)
  sw    $t6, 0x10($sp)
  move  $a0, $s0
  li    $a1, 55
  li    $a2, 260
  jal   microcode_constructor_related_to_menus
   addiu $a3, $a3, 0x3c
  move  $s0, $v0
.L7F0116AC:
  lui   $t8, %hi(unlock_control_style) 
  lw    $t8, %lo(unlock_control_style)($t8)
  beql  $t8, $zero, .L7F0116C8
   li    $v1, 112
  b     .L7F0116C8
   li    $v1, 255
  li    $v1, 112
.L7F0116C8:
  jal   get_video2_settings_txtClipW
   sw    $v1, 0x48($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lui   $t9, %hi(ptrSecondFontTableLarge) 
  lui   $t0, %hi(ptrFirstFontTableLarge) 
  lw    $t0, %lo(ptrFirstFontTableLarge)($t0)
  lw    $t9, %lo(ptrSecondFontTableLarge)($t9)
  lw    $v1, 0x48($sp)
  lh    $t1, 0x44($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x58
  addiu $a2, $sp, 0x54
  lw    $a3, 0x64($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t0, 0x14($sp)
  sw    $t9, 0x10($sp)
  sw    $v1, 0x18($sp)
  jal   write_text_at_abs_coord
   sw    $t1, 0x1c($sp)
  move  $s0, $v0
  jal   get_textptr_for_textID
   li    $a0, 40020
  lui   $t2, %hi(ptrFirstFontTableLarge) 
  lw    $t2, %lo(ptrFirstFontTableLarge)($t2)
  lui   $a3, %hi(ptrSecondFontTableLarge)
  sw    $v0, 0x64($sp)
  lw    $a3, %lo(ptrSecondFontTableLarge)($a3)
  addiu $a0, $sp, 0x50
  addiu $a1, $sp, 0x4c
  move  $a2, $v0
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t2, 0x10($sp)
  lui   $t5, %hi(highlight_aimadjustment) 
  lw    $t5, %lo(highlight_aimadjustment)($t5)
  li    $t3, 57
  li    $t4, 281
  sw    $t3, 0x58($sp)
  beqz  $t5, .L7F0117A0
   sw    $t4, 0x54($sp)
  lw    $a3, 0x4c($sp)
  li    $t6, 295
  li    $t7, 50
  sw    $t7, 0x14($sp)
  sw    $t6, 0x10($sp)
  move  $a0, $s0
  li    $a1, 55
  li    $a2, 280
  jal   microcode_constructor_related_to_menus
   addiu $a3, $a3, 0x3c
  move  $s0, $v0
.L7F0117A0:
  lui   $t8, %hi(unlock_aim_sight) 
  lw    $t8, %lo(unlock_aim_sight)($t8)
  beql  $t8, $zero, .L7F0117BC
   li    $v1, 112
  b     .L7F0117BC
   li    $v1, 255
  li    $v1, 112
.L7F0117BC:
  jal   get_video2_settings_txtClipW
   sw    $v1, 0x48($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lui   $t9, %hi(ptrSecondFontTableLarge) 
  lui   $t0, %hi(ptrFirstFontTableLarge) 
  lw    $t0, %lo(ptrFirstFontTableLarge)($t0)
  lw    $t9, %lo(ptrSecondFontTableLarge)($t9)
  lw    $v1, 0x48($sp)
  lh    $t1, 0x44($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x58
  addiu $a2, $sp, 0x54
  lw    $a3, 0x64($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t0, 0x14($sp)
  sw    $t9, 0x10($sp)
  sw    $v1, 0x18($sp)
  jal   write_text_at_abs_coord
   sw    $t1, 0x1c($sp)
  lui   $a1, %hi(aD_7)
  lui   $a2, %hi(selected_num_players)
  move  $s0, $v0
  lw    $a2, %lo(selected_num_players)($a2)
  addiu $a1, %lo(aD_7) # addiu $a1, $a1, 0xc4c
  jal   sprintf
   addiu $a0, $sp, 0x5c
  li    $t2, 160
  li    $t3, 121
  sw    $t2, 0x58($sp)
  jal   get_video2_settings_txtClipW
   sw    $t3, 0x54($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lui   $t4, %hi(ptrSecondFontTableLarge) 
  lui   $t5, %hi(ptrFirstFontTableLarge) 
  lw    $t5, %lo(ptrFirstFontTableLarge)($t5)
  lw    $t4, %lo(ptrSecondFontTableLarge)($t4)
  lh    $t7, 0x44($sp)
  li    $t6, 255
  sw    $t6, 0x18($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x58
  addiu $a2, $sp, 0x54
  addiu $a3, $sp, 0x5c
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t5, 0x14($sp)
  sw    $t4, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t7, 0x1c($sp)
  lui   $t8, %hi(scenario) 
  lw    $t8, %lo(scenario)($t8)
  lui   $a0, %hi(mp_player_counts)
  move  $s0, $v0
  sll   $t9, $t8, 2
  addu  $a0, $a0, $t9
  jal   get_textptr_for_textID
   lhu   $a0, %lo(mp_player_counts)($a0)
  li    $t0, 160
  li    $t1, 141
  sw    $v0, 0x64($sp)
  sw    $t0, 0x58($sp)
  jal   get_video2_settings_txtClipW
   sw    $t1, 0x54($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lui   $t2, %hi(ptrSecondFontTableLarge) 
  lui   $t3, %hi(ptrFirstFontTableLarge) 
  lw    $t3, %lo(ptrFirstFontTableLarge)($t3)
  lw    $t2, %lo(ptrSecondFontTableLarge)($t2)
  lh    $t5, 0x44($sp)
  li    $t4, 255
  sw    $t4, 0x18($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x58
  addiu $a2, $sp, 0x54
  lw    $a3, 0x64($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t3, 0x14($sp)
  sw    $t2, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t5, 0x1c($sp)
  lui   $t6, %hi(MP_stage_selected) 
  lw    $t6, %lo(MP_stage_selected)($t6)
  lui   $a0, %hi(multi_stage_setups)
  move  $s0, $v0
  sll   $t7, $t6, 2
  subu  $t7, $t7, $t6
  sll   $t7, $t7, 3
  addu  $a0, $a0, $t7
  jal   get_textptr_for_textID
   lhu   $a0, %lo(multi_stage_setups)($a0)
  lui   $t0, %hi(unlock_stage_select) 
  lw    $t0, %lo(unlock_stage_select)($t0)
  li    $t8, 160
  li    $t9, 161
  sw    $v0, 0x64($sp)
  sw    $t8, 0x58($sp)
  beqz  $t0, .L7F01196C
   sw    $t9, 0x54($sp)
  b     .L7F011970
   li    $v1, 255
.L7F01196C:
  li    $v1, 112
.L7F011970:
  jal   get_video2_settings_txtClipW
   sw    $v1, 0x48($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lui   $t1, %hi(ptrSecondFontTableLarge) 
  lui   $t2, %hi(ptrFirstFontTableLarge) 
  lw    $t2, %lo(ptrFirstFontTableLarge)($t2)
  lw    $t1, %lo(ptrSecondFontTableLarge)($t1)
  lw    $v1, 0x48($sp)
  lh    $t3, 0x44($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x58
  addiu $a2, $sp, 0x54
  lw    $a3, 0x64($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t2, 0x14($sp)
  sw    $t1, 0x10($sp)
  sw    $v1, 0x18($sp)
  jal   write_text_at_abs_coord
   sw    $t3, 0x1c($sp)
  lui   $t4, %hi(game_length) 
  lw    $t4, %lo(game_length)($t4)
  lui   $a0, %hi(multi_game_lengths)
  move  $s0, $v0
  sll   $t5, $t4, 2
  subu  $t5, $t5, $t4
  sll   $t5, $t5, 2
  addu  $a0, $a0, $t5
  jal   get_textptr_for_textID
   lhu   $a0, %lo(multi_game_lengths)($a0)
  lui   $t8, %hi(unlock_game_length) 
  lw    $t8, %lo(unlock_game_length)($t8)
  li    $t6, 160
  li    $t7, 181
  sw    $v0, 0x64($sp)
  sw    $t6, 0x58($sp)
  beqz  $t8, .L7F011A18
   sw    $t7, 0x54($sp)
  b     .L7F011A1C
   li    $v1, 255
.L7F011A18:
  li    $v1, 112
.L7F011A1C:
  jal   get_video2_settings_txtClipW
   sw    $v1, 0x48($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lui   $t9, %hi(ptrSecondFontTableLarge) 
  lui   $t0, %hi(ptrFirstFontTableLarge) 
  lw    $t0, %lo(ptrFirstFontTableLarge)($t0)
  lw    $t9, %lo(ptrSecondFontTableLarge)($t9)
  lw    $v1, 0x48($sp)
  lh    $t1, 0x44($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x58
  addiu $a2, $sp, 0x54
  lw    $a3, 0x64($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t0, 0x14($sp)
  sw    $t9, 0x10($sp)
  sw    $v1, 0x18($sp)
  jal   write_text_at_abs_coord
   sw    $t1, 0x1c($sp)
  jal   get_ptr_current_mp_weapon_set_text_code
   move  $s0, $v0
  jal   get_textptr_for_textID
   lhu   $a0, ($v0)
  lui   $t4, %hi(unlock_weapon_select) 
  lw    $t4, %lo(unlock_weapon_select)($t4)
  li    $t2, 160
  li    $t3, 201
  sw    $v0, 0x64($sp)
  sw    $t2, 0x58($sp)
  beqz  $t4, .L7F011AAC
   sw    $t3, 0x54($sp)
  b     .L7F011AB0
   li    $v1, 255
.L7F011AAC:
  li    $v1, 112
.L7F011AB0:
  jal   get_video2_settings_txtClipW
   sw    $v1, 0x48($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lui   $t5, %hi(ptrSecondFontTableLarge) 
  lui   $t6, %hi(ptrFirstFontTableLarge) 
  lw    $t6, %lo(ptrFirstFontTableLarge)($t6)
  lw    $t5, %lo(ptrSecondFontTableLarge)($t5)
  lw    $v1, 0x48($sp)
  lh    $t7, 0x44($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x58
  addiu $a2, $sp, 0x54
  lw    $a3, 0x64($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t6, 0x14($sp)
  sw    $t5, 0x10($sp)
  sw    $v1, 0x18($sp)
  jal   write_text_at_abs_coord
   sw    $t7, 0x1c($sp)
  lui   $t8, %hi(aim_sight_adjustment) 
  lw    $t8, %lo(aim_sight_adjustment)($t8)
  lui   $a0, %hi(mp_sight_adjust_table)
  move  $s0, $v0
  sll   $t9, $t8, 2
  addu  $a0, $a0, $t9
  jal   get_textptr_for_textID
   lhu   $a0, %lo(mp_sight_adjust_table)($a0)
  lui   $t2, %hi(unlock_aim_sight) 
  lw    $t2, %lo(unlock_aim_sight)($t2)
  li    $t0, 160
  li    $t1, 281
  sw    $v0, 0x64($sp)
  sw    $t0, 0x58($sp)
  beqz  $t2, .L7F011B50
   sw    $t1, 0x54($sp)
  b     .L7F011B54
   li    $v1, 255
.L7F011B50:
  li    $v1, 112
.L7F011B54:
  jal   get_video2_settings_txtClipW
   sw    $v1, 0x48($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lui   $t3, %hi(ptrSecondFontTableLarge) 
  lui   $t4, %hi(ptrFirstFontTableLarge) 
  lw    $t4, %lo(ptrFirstFontTableLarge)($t4)
  lw    $t3, %lo(ptrSecondFontTableLarge)($t3)
  lw    $v1, 0x48($sp)
  lh    $t5, 0x44($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x58
  addiu $a2, $sp, 0x54
  lw    $a3, 0x64($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t4, 0x14($sp)
  sw    $t3, 0x10($sp)
  sw    $v1, 0x18($sp)
  jal   write_text_at_abs_coord
   sw    $t5, 0x1c($sp)
  jal   add_tab3_previous
   move  $a0, $v0
  jal   add_tab1_start
   move  $a0, $v0
  jal   load_draw_selected_icon_folder_select
   move  $a0, $v0
  lw    $ra, 0x3c($sp)
  lw    $s0, 0x38($sp)
  addiu $sp, $sp, 0x68
  jr    $ra
   nop   
");

asm(R"
glabel get_players_who_have_selected_mp_char
  lui   $a1, %hi(selected_num_players)
  lw    $a1, %lo(selected_num_players)($a1)
  move  $a2, $a0
  move  $v1, $zero
  blez  $a1, .L7F011C34
   move  $v0, $zero
  lui   $t6, %hi(has_selected_char_player1)
  sll   $t7, $a1, 2
  lui   $a1, %hi(player_1_char)
  addiu $a0, $t6, %lo(has_selected_char_player1)
  addu  $a3, $t7, $a0
  addiu $a1, %lo(player_1_char) # addiu $a1, $a1, -0x4adc
.L7F011C08:
  lw    $t8, ($a0)
  addiu $a0, $a0, 4
  sltu  $at, $a0, $a3
  beqz  $t8, .L7F011C2C
   addu  $t9, $a1, $v0
  lw    $t0, ($t9)
  bne   $a2, $t0, .L7F011C2C
   nop   
  li    $v1, 1
.L7F011C2C:
  bnez  $at, .L7F011C08
   addiu $v0, $v0, 4
.L7F011C34:
  jr    $ra
   move  $v0, $v1
");

asm(R"
glabel init_menu0f_mpcharsel
  lui   $at, %hi(tab_1_selected)
  sw    $zero, %lo(tab_1_selected)($at)
  lui   $at, %hi(tab_2_selected)
  sw    $zero, %lo(tab_2_selected)($at)
  lui   $at, %hi(tab_3_selected)
  addiu $sp, $sp, -0x30
  sw    $zero, %lo(tab_3_selected)($at)
  lui   $at, %hi(tab_3_highlight)
  sw    $zero, %lo(tab_3_highlight)($at)
  lui   $at, %hi(tab_2_highlight)
  sw    $s4, 0x28($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $zero, %lo(tab_2_highlight)($at)
  sw    $s3, 0x24($sp)
  lui   $at, %hi(tab_1_highlight)
  lui   $s1, %hi(mp_chr_setup)
  lui   $s2, %hi(mpcharselimages)
  lui   $s4, %hi(MP_handicap_table)
  sw    $ra, 0x2c($sp)
  sw    $s0, 0x18($sp)
  sw    $zero, %lo(tab_1_highlight)($at)
  addiu $s4, %lo(MP_handicap_table) # addiu $s4, $s4, -0x4b68
  addiu $s2, %lo(mpcharselimages) # addiu $s2, $s2, -0x2ed0
  addiu $s1, %lo(mp_chr_setup) # addiu $s1, $s1, -0x4e68
  li    $s3, 12
  lbu   $v1, 3($s1)
.L7F011CA8:
  lw    $t7, ($s2)
  sll   $t6, $v1, 2
  multu $t6, $s3
  mflo  $s0
  addu  $v0, $t7, $s0
  lw    $a2, ($v0)
  sltiu $at, $a2, 0xbb8
  beqz  $at, .L7F011CDC
   move  $a0, $a2
  jal   calls_load_image_to_buffer
   move  $a1, $zero
  lw    $t8, ($s2)
  addu  $v0, $t8, $s0
.L7F011CDC:
  lw    $v1, 0xc($v0)
  sltiu $at, $v1, 0xbb8
  beqz  $at, .L7F011CFC
   move  $a0, $v1
  jal   calls_load_image_to_buffer
   move  $a1, $zero
  lw    $t9, ($s2)
  addu  $v0, $t9, $s0
.L7F011CFC:
  lw    $v1, 0x18($v0)
  sltiu $at, $v1, 0xbb8
  beqz  $at, .L7F011D1C
   move  $a0, $v1
  jal   calls_load_image_to_buffer
   move  $a1, $zero
  lw    $t0, ($s2)
  addu  $v0, $t0, $s0
.L7F011D1C:
  lw    $v1, 0x24($v0)
  sltiu $at, $v1, 0xbb8
  beqz  $at, .L7F011D34
   move  $a0, $v1
  jal   calls_load_image_to_buffer
   move  $a1, $zero
.L7F011D34:
  addiu $s1, $s1, 0xc
  sltu  $at, $s1, $s4
  bnezl $at, .L7F011CA8
   lbu   $v1, 3($s1)
  lui   $s1, %hi(num_chars_selectable_mp)
  addiu $s1, %lo(num_chars_selectable_mp) # addiu $s1, $s1, -0x4e6c
  lw    $t1, ($s1)
  li    $at, 64
  lui   $a0, %hi(selected_folder_num)
  beq   $t1, $at, .L7F011DE8
   li    $a1, 17
  lw    $a0, %lo(selected_folder_num)($a0)
  jal   isStageUnlockedAtDifficulty
   move  $a2, $zero
  li    $at, 3
  bne   $v0, $at, .L7F011D84
   li    $t3, 8
  li    $t2, 33
  b     .L7F011DE8
   sw    $t2, ($s1)
.L7F011D84:
  lui   $s2, %hi(player_1_char)
  lui   $s3, %hi(MP_stage_selected)
  sw    $t3, ($s1)
  addiu $s3, %lo(MP_stage_selected) # addiu $s3, $s3, -0x4acc
  addiu $s2, %lo(player_1_char) # addiu $s2, $s2, -0x4adc
  lw    $v0, ($s1)
.L7F011D9C:
  lw    $t4, ($s2)
  slt   $at, $t4, $v0
  bnezl $at, .L7F011DE0
   addiu $s2, $s2, 4
  blez  $v0, .L7F011DD8
   move  $s0, $zero
.L7F011DB4:
  jal   get_players_who_have_selected_mp_char
   move  $a0, $s0
  beql  $v0, $zero, .L7F011DDC
   sw    $s0, ($s2)
  lw    $t5, ($s1)
  addiu $s0, $s0, 1
  slt   $at, $s0, $t5
  bnez  $at, .L7F011DB4
   nop   
.L7F011DD8:
  sw    $s0, ($s2)
.L7F011DDC:
  addiu $s2, $s2, 4
.L7F011DE0:
  bnel  $s2, $s3, .L7F011D9C
   lw    $v0, ($s1)
.L7F011DE8:
  lui   $v0, %hi(player_1_char)
  lw    $v0, %lo(player_1_char)($v0)
  lui   $at, %hi(mp_char_cur_select_player1)
  lui   $v1, %hi(player_2_char)
  sw    $v0, %lo(mp_char_cur_select_player1)($at)
  lui   $at, %hi(mp_char_prev_select_player1)
  sw    $v0, %lo(mp_char_prev_select_player1)($at)
  lui   $at, %hi(dword_CODE_bss_80069730)
  sw    $zero, %lo(dword_CODE_bss_80069730)($at)
  lui   $at, %hi(has_selected_char_player1)
  sw    $zero, %lo(has_selected_char_player1)($at)
  lw    $v1, %lo(player_2_char)($v1)
  lui   $at, %hi(size_mp_select_image_player1)
  sw    $zero, %lo(size_mp_select_image_player1)($at)
  lui   $at, %hi(mp_char_cur_select_player2)
  sw    $v1, %lo(mp_char_cur_select_player2)($at)
  lui   $at, %hi(mp_char_prev_select_player2)
  sw    $v1, %lo(mp_char_prev_select_player2)($at)
  lui   $at, %hi(dword_CODE_bss_80069734)
  sw    $zero, %lo(dword_CODE_bss_80069734)($at)
  lui   $at, %hi(has_selected_char_player2)
  sw    $zero, %lo(has_selected_char_player2)($at)
  lui   $a0, %hi(player_3_char)
  lw    $a0, %lo(player_3_char)($a0)
  lui   $at, %hi(size_mp_select_image_player2)
  sw    $zero, %lo(size_mp_select_image_player2)($at)
  lui   $at, %hi(mp_char_cur_select_player3)
  sw    $a0, %lo(mp_char_cur_select_player3)($at)
  lui   $at, %hi(mp_char_prev_select_player3)
  sw    $a0, %lo(mp_char_prev_select_player3)($at)
  lui   $at, %hi(dword_CODE_bss_80069738)
  sw    $zero, %lo(dword_CODE_bss_80069738)($at)
  lui   $at, %hi(has_selected_char_player3)
  sw    $zero, %lo(has_selected_char_player3)($at)
  lui   $a1, %hi(player_4_char)
  lw    $a1, %lo(player_4_char)($a1)
  lui   $at, %hi(size_mp_select_image_player3)
  sw    $zero, %lo(size_mp_select_image_player3)($at)
  lui   $at, %hi(mp_char_cur_select_player4)
  sw    $a1, %lo(mp_char_cur_select_player4)($at)
  lui   $at, %hi(mp_char_prev_select_player4)
  sw    $a1, %lo(mp_char_prev_select_player4)($at)
  lui   $at, %hi(dword_CODE_bss_8006973C)
  sw    $zero, %lo(dword_CODE_bss_8006973C)($at)
  lui   $at, %hi(has_selected_char_player4)
  sw    $zero, %lo(has_selected_char_player4)($at)
  lui   $at, %hi(size_mp_select_image_player4)
  jal   load_walletbond
   sw    $zero, %lo(size_mp_select_image_player4)($at)
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  lw    $s3, 0x24($sp)
  lw    $s4, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x30
");

void update_menu0F_mpcharsel(void) {}

asm(R"
.late_rodata
glabel D_80051A88
.word 0x3FAAAAAB /*1.3333334;*/
glabel D_80051A8C
.word 0x461C4000 /*10000.0;*/

.text
glabel interface_menu0F_mpcharsel
  addiu $sp, $sp, -0x50
  sw    $ra, 0x3c($sp)
  sw    $fp, 0x38($sp)
  sw    $s7, 0x34($sp)
  sw    $s6, 0x30($sp)
  sw    $s5, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  jal   get_selected_num_players
   sw    $s0, 0x18($sp)
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f12
  sw    $v0, 0x4c($sp)
  jal   setvideo_far
   sw    $zero, 0x44($sp)
  lui   $at, %hi(D_80051A88)
  jal   video_related_21
   lwc1  $f12, %lo(D_80051A88)($at)
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f12
  lui   $at, %hi(D_80051A8C)
  jal   set_page_height
   lwc1  $f14, %lo(D_80051A8C)($at)
  jal   set_video2_settings_offset_24
   move  $a0, $zero
  lw    $t6, 0x4c($sp)
  move  $s6, $zero
  move  $s3, $zero
  blez  $t6, .L7F012228
   lui   $s4, %hi(has_selected_char_player1)
  lui   $s5, %hi(mp_char_prev_select_player1)
  lui   $s1, %hi(mp_char_cur_select_player1)
  lui   $s2, %hi(dword_CODE_bss_80069730)
  lui   $fp, %hi(ptr_sfx_buf) 
  lui   $s7, %hi(size_mp_select_image_player1) 
  addiu $s7, %lo(size_mp_select_image_player1) # addiu $s7, $s7, -0x68b0
  addiu $fp, %lo(ptr_sfx_buf) # addiu $fp, $fp, 0x3720
  addiu $s2, %lo(dword_CODE_bss_80069730) # addiu $s2, $s2, -0x68d0
  addiu $s1, %lo(mp_char_cur_select_player1) # addiu $s1, $s1, -0x68f0
  addiu $s5, %lo(mp_char_prev_select_player1) # addiu $s5, $s5, -0x68e0
  addiu $s4, %lo(has_selected_char_player1) # addiu $s4, $s4, -0x68c0
.L7F011F80:
  lw    $t7, ($s4)
  sll   $a0, $s6, 0x18
  addu  $v0, $s7, $s3
  beqz  $t7, .L7F011FE0
   sra   $t1, $a0, 0x18
  lw    $v1, ($v0)
  move  $a0, $t1
  slti  $at, $v1, 0xb
  beqz  $at, .L7F011FC0
   nop   
  lw    $t8, ($s5)
  lw    $t9, ($s1)
  addiu $t0, $v1, 1
  bne   $t8, $t9, .L7F011FC0
   nop   
  sw    $t0, ($v0)
.L7F011FC0:
  jal   get_controller_buttons_pressed
   li    $a1, 16384
  beqz  $v0, .L7F011FE0
   li    $a1, 199
  sw    $zero, ($s4)
  lw    $a0, ($fp)
  jal   play_sfx_a1
   move  $a2, $zero
.L7F011FE0:
  lw    $a2, ($s4)
  addu  $v0, $s7, $s3
  bnez  $a2, .L7F012004
   nop   
  lw    $v1, ($v0)
  blez  $v1, .L7F012004
   addiu $t2, $v1, -1
  b     .L7F012164
   sw    $t2, ($v0)
.L7F012004:
  bnez  $a2, .L7F012164
   sll   $s0, $s6, 0x18
  sra   $t3, $s0, 0x18
  sll   $a0, $t3, 0x18
  sra   $t4, $a0, 0x18
  move  $a0, $t4
  move  $s0, $t3
  jal   get_controller_buttons_pressed
   li    $a1, 514
  beqz  $v0, .L7F012044
   sll   $a0, $s0, 0x18
  lw    $v0, ($s1)
  blez  $v0, .L7F012164
   addiu $t5, $v0, -1
  b     .L7F012164
   sw    $t5, ($s1)
.L7F012044:
  sra   $t6, $a0, 0x18
  move  $a0, $t6
  jal   get_controller_buttons_pressed
   li    $a1, 257
  beqz  $v0, .L7F012080
   sll   $a0, $s0, 0x18
  lui   $t7, %hi(num_chars_selectable_mp) 
  lw    $t7, %lo(num_chars_selectable_mp)($t7)
  lw    $v0, ($s1)
  addiu $t8, $t7, -1
  slt   $at, $v0, $t8
  beqz  $at, .L7F012164
   addiu $t9, $v0, 1
  b     .L7F012164
   sw    $t9, ($s1)
.L7F012080:
  sra   $t0, $a0, 0x18
  move  $a0, $t0
  jal   get_controller_buttons_pressed
   li    $a1, 45056
  beqz  $v0, .L7F0120DC
   sll   $a0, $s0, 0x18
  jal   get_players_who_have_selected_mp_char
   lw    $a0, ($s1)
  bnez  $v0, .L7F012164
   lui   $at, %hi(player_1_char)
  lw    $t1, ($s1)
  addu  $at, $at, $s3
  li    $v0, 1
  addu  $t2, $s7, $s3
  sw    $t1, %lo(player_1_char)($at)
  sw    $v0, ($t2)
  sw    $v0, ($s4)
  lw    $a0, ($fp)
  li    $a1, 199
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F012168
   lw    $a1, ($s5)
.L7F0120DC:
  sra   $t3, $a0, 0x18
  move  $a0, $t3
  li    $a1, -2
  jal   get_controller_3dstick_L_R
   li    $a2, 1
  blez  $v0, .L7F012128
   sll   $a0, $s0, 0x18
  lw    $t4, ($s2)
  lui   $t5, %hi(num_chars_selectable_mp) 
  bnezl $t4, .L7F012168
   lw    $a1, ($s5)
  lw    $t5, %lo(num_chars_selectable_mp)($t5)
  lw    $v0, ($s1)
  addiu $t6, $t5, -1
  slt   $at, $v0, $t6
  beqz  $at, .L7F012164
   addiu $t7, $v0, 1
  b     .L7F012164
   sw    $t7, ($s1)
.L7F012128:
  sra   $t8, $a0, 0x18
  move  $a0, $t8
  li    $a1, -2
  jal   get_controller_3dstick_L_R
   li    $a2, 1
  slti  $at, $v0, -1
  beql  $at, $zero, .L7F012168
   lw    $a1, ($s5)
  lw    $t9, ($s2)
  bnezl $t9, .L7F012168
   lw    $a1, ($s5)
  lw    $v0, ($s1)
  blez  $v0, .L7F012164
   addiu $t0, $v0, -1
  sw    $t0, ($s1)
.L7F012164:
  lw    $a1, ($s5)
.L7F012168:
  li    $a3, 84
  lw    $t2, ($s1)
  multu $a1, $a3
  lw    $v0, ($s2)
  addiu $s6, $s6, 1
  addiu $s4, $s4, 4
  addiu $s1, $s1, 4
  lw    $a2, -4($s4)
  addu  $t9, $s7, $s3
  addiu $t3, $v0, -0xc
  mflo  $t1
  addu  $v1, $v0, $t1
  nop   
  multu $t2, $a3
  mflo  $a0
  slt   $at, $a0, $v1
  beql  $at, $zero, .L7F0121D0
   slt   $at, $v1, $a0
  bgez  $t3, .L7F0121F4
   sw    $t3, ($s2)
  addiu $t4, $t3, 0x54
  addiu $t5, $a1, -1
  sw    $t4, ($s2)
  b     .L7F0121F4
   sw    $t5, ($s5)
  slt   $at, $v1, $a0
.L7F0121D0:
  beqz  $at, .L7F0121F4
   addiu $t6, $v0, 0xc
  slti  $at, $t6, 0x54
  bnez  $at, .L7F0121F4
   sw    $t6, ($s2)
  addiu $t7, $t6, -0x54
  addiu $t8, $a1, 1
  sw    $t7, ($s2)
  sw    $t8, ($s5)
.L7F0121F4:
  beql  $a2, $zero, .L7F012218
   lw    $t3, 0x4c($sp)
  lw    $t0, ($t9)
  lw    $t1, 0x44($sp)
  li    $at, 11
  bne   $t0, $at, .L7F012214
   addiu $t2, $t1, 1
  sw    $t2, 0x44($sp)
.L7F012214:
  lw    $t3, 0x4c($sp)
.L7F012218:
  addiu $s3, $s3, 4
  addiu $s5, $s5, 4
  bne   $s6, $t3, .L7F011F80
   addiu $s2, $s2, 4
.L7F012228:
  lui   $s0, %hi(ptr_folder_object_instance)
  addiu $s0, %lo(ptr_folder_object_instance) # addiu $s0, $s0, -0x56a4
  jal   disable_all_switches
   lw    $a0, ($s0)
  lw    $a0, ($s0)
  move  $a1, $zero
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lw    $a0, ($s0)
  li    $a1, 42
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  jal   menu_control_stick_tracking
   nop   
  lw    $t4, 0x44($sp)
  lw    $t5, 0x4c($sp)
  bne   $t4, $t5, .L7F012278
   li    $a0, 14
  jal   set_menu_to_mode
   move  $a1, $zero
.L7F012278:
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
   addiu $sp, $sp, 0x50
");

asm(R"
glabel sub_GAME_7F0122A8
  slt   $at, $a1, $a0
  beqz  $at, .L7F0122BC
   slt   $at, $a0, $a2
  bnez  $at, .L7F0122C4
   addiu $t6, $a1, 0x28
.L7F0122BC:
  jr    $ra
   move  $v0, $zero
.L7F0122C4:
  slt   $at, $a0, $t6
  beqz  $at, .L7F0122EC
   addiu $t0, $a2, -0x28
  subu  $t7, $a1, $a0
  sll   $t8, $t7, 2
  subu  $t8, $t8, $t7
  sll   $t8, $t8, 1
  li    $t9, 15
  jr    $ra
   subu  $v0, $t9, $t8
.L7F0122EC:
  slt   $at, $t0, $a0
  beqz  $at, .L7F012314
   li    $v0, 255
  subu  $t1, $a0, $a2
  sll   $t2, $t1, 2
  subu  $t2, $t2, $t1
  sll   $t2, $t2, 1
  li    $t3, 15
  jr    $ra
   subu  $v0, $t3, $t2
.L7F012314:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F01231C
  addiu $sp, $sp, -0xd8
  sw    $ra, 0x4c($sp)
  sw    $fp, 0x48($sp)
  sw    $s7, 0x44($sp)
  sw    $s6, 0x40($sp)
  sw    $s5, 0x3c($sp)
  sw    $s4, 0x38($sp)
  sw    $s3, 0x34($sp)
  sw    $s2, 0x30($sp)
  sw    $s1, 0x2c($sp)
  sw    $s0, 0x28($sp)
  sw    $a0, 0xd8($sp)
  sw    $a1, 0xdc($sp)
  sw    $a2, 0xe0($sp)
  jal   sub_GAME_7F0BD6E0
   sw    $a3, 0xe4($sp)
  jal   sub_GAME_7F0BD6E0
   sw    $v0, 0xd4($sp)
  sw    $v0, 0xd0($sp)
  jal   sub_GAME_7F0BD6C4
   li    $a0, 16
  sw    $v0, 0xcc($sp)
  jal   microcode_constructor
   lw    $a0, 0xd8($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f2
  mtc1  $zero, $f0
  li    $at, 0x43A50000 # 330.000000
  mtc1  $at, $f4
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f6
  mfc1  $a1, $f0
  mfc1  $a3, $f0
  sw    $v0, 0xd8($sp)
  lw    $a0, 0xd4($sp)
  lui   $a2, 0x43dc
  swc1  $f2, 0x14($sp)
  swc1  $f2, 0x1c($sp)
  swc1  $f4, 0x10($sp)
  jal   guOrtho
   swc1  $f6, 0x18($sp)
  mtc1  $zero, $f0
  lui   $a1, (0x40490FDB >> 16) # lui $a1, 0x4049
  ori   $a1, (0x40490FDB & 0xFFFF) # ori $a1, $a1, 0xfdb
  mfc1  $a3, $f0
  lw    $a0, 0xd0($sp)
  lui   $a2, 0x3f80
  jal   guRotate
   swc1  $f0, 0x10($sp)
  lw    $s5, 0xf0($sp)
  lw    $t7, 0xe8($sp)
  li    $t8, 330
  addiu $t6, $s5, 0x23
  addiu $t2, $s5, 0x2a
  subu  $t9, $t8, $t7
  sw    $t9, 0x54($sp)
  sw    $t2, 0x50($sp)
  sw    $t6, 0x58($sp)
  move  $s4, $zero
  lw    $s0, 0xcc($sp)
  li    $fp, 4
  li    $s6, 4096
  move  $s1, $zero
.L7F012418:
  andi  $s7, $s4, 1
.L7F01241C:
  slti  $at, $s1, 2
  bnez  $at, .L7F012430
   move  $s3, $s1
  b     .L7F012430
   addiu $s3, $s1, -1
.L7F012430:
  slti  $at, $s4, 2
  bnez  $at, .L7F012444
   move  $s2, $s4
  b     .L7F012444
   addiu $s2, $s4, -1
.L7F012444:
  jal   get_players_who_have_selected_mp_char
   lw    $a0, 0xec($sp)
  beqz  $v0, .L7F012464
   lw    $t4, 0x58($sp)
  bnezl $s5, .L7F012468
   li    $v0, 255
  b     .L7F012468
   li    $v0, 110
.L7F012464:
  li    $v0, 255
.L7F012468:
  addiu $t3, $s3, -1
  multu $t3, $t4
  lw    $t6, 0xe4($sp)
  addiu $t7, $s2, -1
  mflo  $t5
  addu  $t8, $t5, $t6
  sh    $t8, ($s0)
  lw    $t9, 0x50($sp)
  lw    $t3, 0x54($sp)
  li    $t6, -5
  multu $t7, $t9
  andi  $t8, $s1, 1
  sh    $t6, 4($s0)
  sh    $zero, 6($s0)
  li    $t7, 255
  mflo  $t2
  addu  $t4, $t3, $t2
  addu  $t5, $t4, $s5
  beqz  $t8, .L7F0124C0
   sh    $t5, 2($s0)
  b     .L7F0124C4
   sh    $s6, 8($s0)
.L7F0124C0:
  sh    $zero, 8($s0)
.L7F0124C4:
  beql  $s7, $zero, .L7F0124D8
   sh    $zero, 0xa($s0)
  b     .L7F0124D8
   sh    $s6, 0xa($s0)
  sh    $zero, 0xa($s0)
.L7F0124D8:
  sb    $v0, 0xc($s0)
  sb    $v0, 0xd($s0)
  bnez  $s5, .L7F012500
   sb    $v0, 0xe($s0)
  lh    $a0, ($s0)
  lw    $a1, 0xdc($sp)
  jal   sub_GAME_7F0122A8
   lw    $a2, 0xe0($sp)
  b     .L7F012504
   sb    $v0, 0xf($s0)
.L7F012500:
  sb    $t7, 0xf($s0)
.L7F012504:
  addiu $s1, $s1, 1
  bne   $s1, $fp, .L7F01241C
   addiu $s0, $s0, 0x10
  addiu $s4, $s4, 1
  bnel  $s4, $fp, .L7F012418
   move  $s1, $zero
  lw    $t9, 0xd8($sp)
  lui   $t2, (0x01030040 >> 16) # lui $t2, 0x103
  ori   $t2, (0x01030040 & 0xFFFF) # ori $t2, $t2, 0x40
  addiu $t3, $t9, 8
  sw    $t3, 0xd8($sp)
  sw    $t2, ($t9)
  lw    $t4, 0xd4($sp)
  lui   $t1, 0x8000
  lui   $t7, (0x01020040 >> 16) # lui $t7, 0x102
  addu  $t5, $t4, $t1
  sw    $t5, 4($t9)
  lw    $t6, 0xd8($sp)
  ori   $t7, (0x01020040 & 0xFFFF) # ori $t7, $t7, 0x40
  lui   $t5, (0x04F00100 >> 16) # lui $t5, 0x4f0
  addiu $t8, $t6, 8
  sw    $t8, 0xd8($sp)
  sw    $t7, ($t6)
  lw    $t9, 0xd0($sp)
  ori   $t5, (0x04F00100 & 0xFFFF) # ori $t5, $t5, 0x100
  li    $s3, 12
  addu  $t3, $t9, $t1
  sw    $t3, 4($t6)
  lw    $t2, 0xd8($sp)
  lui   $t9, %hi(mp_chr_setup) 
  addiu $t9, %lo(mp_chr_setup) # addiu $t9, $t9, -0x4e68
  addiu $t4, $t2, 8
  sw    $t4, 0xd8($sp)
  sw    $t5, ($t2)
  lw    $t6, 0xcc($sp)
  lui   $s4, %hi(mpcharselimages)
  addiu $s4, %lo(mpcharselimages) # addiu $s4, $s4, -0x2ed0
  sw    $t6, 4($t2)
  lw    $t8, 0xec($sp)
  lw    $t5, ($s4)
  addiu $s5, $sp, 0xd8
  multu $t8, $s3
  li    $t6, 2
  sw    $t6, 0x10($sp)
  move  $a0, $s5
  li    $a2, 2
  move  $a3, $zero
  mflo  $t7
  addu  $s2, $t7, $t9
  lbu   $t3, 3($s2)
  sll   $t2, $t3, 2
  multu $t2, $s3
  mflo  $t4
  addu  $s0, $t4, $t5
  jal   likely_generate_DL_for_image_declaration
   addiu $a1, $s0, 0x18
  lw    $t8, 0xd8($sp)
  lui   $s1, 0xbf00
  li    $t9, 2600
  addiu $t7, $t8, 8
  sw    $t7, 0xd8($sp)
  sw    $t9, 4($t8)
  sw    $s1, ($t8)
  lw    $t3, 0xd8($sp)
  lui   $t4, (0x00280A32 >> 16) # lui $t4, 0x28
  ori   $t4, (0x00280A32 & 0xFFFF) # ori $t4, $t4, 0xa32
  addiu $t2, $t3, 8
  sw    $t2, 0xd8($sp)
  sw    $t4, 4($t3)
  sw    $s1, ($t3)
  lbu   $t5, 3($s2)
  lw    $t7, ($s4)
  li    $t9, 2
  sll   $t6, $t5, 2
  multu $t6, $s3
  sw    $t9, 0x10($sp)
  move  $a0, $s5
  li    $a2, 2
  move  $a3, $zero
  mflo  $t8
  addu  $s0, $t8, $t7
  jal   likely_generate_DL_for_image_declaration
   addiu $a1, $s0, 0x24
  lw    $t3, 0xd8($sp)
  lui   $t4, (0x00141E3C >> 16) # lui $t4, 0x14
  ori   $t4, (0x00141E3C & 0xFFFF) # ori $t4, $t4, 0x1e3c
  addiu $t2, $t3, 8
  sw    $t2, 0xd8($sp)
  sw    $t4, 4($t3)
  sw    $s1, ($t3)
  lw    $t5, 0xd8($sp)
  lui   $t8, (0x003C1E46 >> 16) # lui $t8, 0x3c
  ori   $t8, (0x003C1E46 & 0xFFFF) # ori $t8, $t8, 0x1e46
  addiu $t6, $t5, 8
  sw    $t6, 0xd8($sp)
  sw    $t8, 4($t5)
  sw    $s1, ($t5)
  lbu   $t7, 3($s2)
  lw    $t2, ($s4)
  li    $t4, 2
  sll   $t9, $t7, 2
  multu $t9, $s3
  sw    $t4, 0x10($sp)
  move  $a0, $s5
  li    $a2, 2
  move  $a3, $zero
  mflo  $t3
  addu  $a1, $t3, $t2
  jal   likely_generate_DL_for_image_declaration
   nop   
  lw    $t5, 0xd8($sp)
  lui   $t8, (0x00505A78 >> 16) # lui $t8, 0x50
  ori   $t8, (0x00505A78 & 0xFFFF) # ori $t8, $t8, 0x5a78
  addiu $t6, $t5, 8
  sw    $t6, 0xd8($sp)
  sw    $t8, 4($t5)
  sw    $s1, ($t5)
  lw    $t7, 0xd8($sp)
  lui   $t3, (0x00785A82 >> 16) # lui $t3, 0x78
  ori   $t3, (0x00785A82 & 0xFFFF) # ori $t3, $t3, 0x5a82
  addiu $t9, $t7, 8
  sw    $t9, 0xd8($sp)
  sw    $t3, 4($t7)
  sw    $s1, ($t7)
  lbu   $t2, 3($s2)
  lw    $t6, ($s4)
  li    $t8, 2
  sll   $t4, $t2, 2
  multu $t4, $s3
  sw    $t8, 0x10($sp)
  move  $a0, $s5
  li    $a2, 2
  move  $a3, $zero
  mflo  $t5
  addu  $s0, $t5, $t6
  jal   likely_generate_DL_for_image_declaration
   addiu $a1, $s0, 0xc
  lw    $t7, 0xd8($sp)
  lui   $t3, (0x00646E8C >> 16) # lui $t3, 0x64
  ori   $t3, (0x00646E8C & 0xFFFF) # ori $t3, $t3, 0x6e8c
  addiu $t9, $t7, 8
  sw    $t9, 0xd8($sp)
  sw    $t3, 4($t7)
  sw    $s1, ($t7)
  lw    $t2, 0xd8($sp)
  lui   $t5, (0x008C6E96 >> 16) # lui $t5, 0x8c
  ori   $t5, (0x008C6E96 & 0xFFFF) # ori $t5, $t5, 0x6e96
  addiu $t4, $t2, 8
  sw    $t4, 0xd8($sp)
  sw    $t5, 4($t2)
  sw    $s1, ($t2)
  lw    $ra, 0x4c($sp)
  lw    $fp, 0x48($sp)
  lw    $s7, 0x44($sp)
  lw    $s6, 0x40($sp)
  lw    $s5, 0x3c($sp)
  lw    $s4, 0x38($sp)
  lw    $s3, 0x34($sp)
  lw    $s2, 0x30($sp)
  lw    $s1, 0x2c($sp)
  lw    $s0, 0x28($sp)
  lw    $v0, 0xd8($sp)
  jr    $ra
   addiu $sp, $sp, 0xd8
");

asm(R"
glabel constructor_menu0F_mpcharsel
  addiu $sp, $sp, -0xe8
  sw    $ra, 0x64($sp)
  sw    $s1, 0x44($sp)
  move  $s1, $a0
  sw    $fp, 0x60($sp)
  sw    $s7, 0x5c($sp)
  sw    $s6, 0x58($sp)
  sw    $s5, 0x54($sp)
  sw    $s4, 0x50($sp)
  sw    $s3, 0x4c($sp)
  sw    $s2, 0x48($sp)
  sw    $s0, 0x40($sp)
  jal   get_selected_num_players
   sdc1  $f20, 0x38($sp)
  sw    $v0, 0xe4($sp)
  move  $a0, $s1
  move  $a1, $zero
  move  $a2, $zero
  jal   set_setfillcolor
   move  $a3, $zero
  jal   insert_generic_fillrect
   move  $a0, $v0
  jal   sub_GAME_7F00D5E8
   move  $a0, $v0
  jal   microcode_constructor
   move  $a0, $v0
  li    $t6, 171
  li    $t7, 144
  sw    $t7, 0x14($sp)
  sw    $t6, 0x10($sp)
  move  $a0, $v0
  li    $a1, 38
  li    $a2, 169
  jal   microcode_constructor_related_to_menus
   li    $a3, 388
  lw    $t0, 0xe4($sp)
  move  $s1, $v0
  move  $a0, $s1
  slti  $at, $t0, 3
  bnez  $at, .L7F01285C
   li    $a1, 212
  li    $t8, 310
  li    $t9, 128
  sw    $t9, 0x14($sp)
  sw    $t8, 0x10($sp)
  li    $a2, 30
  jal   microcode_constructor_related_to_menus
   li    $a3, 214
  move  $s1, $v0
  lw    $t0, 0xe4($sp)
.L7F01285C:
  blez  $t0, .L7F012DF4
   lui   $t1, %hi(has_selected_char_player1) 
  lui   $t2, %hi(mp_char_cur_select_player1) 
  lui   $t3, %hi(dword_CODE_bss_80069730) 
  lui   $t4, %hi(mp_char_prev_select_player1) 
  li    $at, 0x40800000 # 4.000000
  addiu $t4, %lo(mp_char_prev_select_player1) # addiu $t4, $t4, -0x68e0
  addiu $t3, %lo(dword_CODE_bss_80069730) # addiu $t3, $t3, -0x68d0
  addiu $t2, %lo(mp_char_cur_select_player1) # addiu $t2, $t2, -0x68f0
  addiu $t1, %lo(has_selected_char_player1) # addiu $t1, $t1, -0x68c0
  lui   $fp, %hi(size_mp_select_image_player1) 
  mtc1  $at, $f20
  addiu $fp, %lo(size_mp_select_image_player1) # addiu $fp, $fp, -0x68b0
  sw    $t1, 0x88($sp)
  sw    $t2, 0x80($sp)
  sw    $t3, 0x74($sp)
  sw    $t4, 0x70($sp)
  sw    $zero, 0xe0($sp)
.L7F0128A4:
  lw    $t0, 0xe4($sp)
  lw    $a0, 0xe0($sp)
  li    $at, 2
  bne   $t0, $at, .L7F0128D8
   andi  $t5, $a0, 1
  li    $s2, 38
  blez  $a0, .L7F0128CC
   li    $s4, 350
  b     .L7F012908
   li    $s7, 170
.L7F0128CC:
  move  $v1, $zero
  b     .L7F012908
   addiu $s7, $v1, 0x1e
.L7F0128D8:
  slti  $at, $a0, 2
  bnez  $at, .L7F0128EC
   li    $s4, 175
  b     .L7F0128F0
   li    $v1, 140
.L7F0128EC:
  move  $v1, $zero
.L7F0128F0:
  beqz  $t5, .L7F012900
   addiu $s7, $v1, 0x1e
  b     .L7F012904
   li    $v1, 175
.L7F012900:
  move  $v1, $zero
.L7F012904:
  addiu $s2, $v1, 0x26
.L7F012908:
  addiu $t6, $s2, 6
  mtc1  $t6, $f4
  addiu $s0, $s7, 5
  mtc1  $s0, $f16
  cvt.s.w $f6, $f4
  addu  $t7, $s2, $s4
  lui   $at, 0xed00
  addiu $s1, $v0, 8
  cvt.s.w $f18, $f16
  mul.s $f8, $f6, $f20
  trunc.w.s $f10, $f8
  mul.s $f4, $f18, $f20
  mfc1  $t8, $f10
  nop   
  andi  $t9, $t8, 0xfff
  trunc.w.s $f6, $f4
  sll   $t1, $t9, 0xc
  addiu $t9, $t7, -6
  mtc1  $t9, $f8
  mfc1  $t4, $f6
  or    $t2, $t1, $at
  cvt.s.w $f10, $f8
  andi  $t5, $t4, 0xfff
  or    $t6, $t2, $t5
  addiu $t5, $s7, 0x87
  mtc1  $t5, $f4
  sw    $t6, ($v0)
  mul.s $f16, $f10, $f20
  sw    $t7, 0x8c($sp)
  cvt.s.w $f6, $f4
  trunc.w.s $f18, $f16
  mul.s $f8, $f6, $f20
  mfc1  $t3, $f18
  nop   
  andi  $t4, $t3, 0xfff
  trunc.w.s $f10, $f8
  sll   $t2, $t4, 0xc
  mfc1  $t7, $f10
  nop   
  andi  $t8, $t7, 0xfff
  or    $t9, $t2, $t8
  sw    $t9, 4($v0)
  lw    $t1, 0x88($sp)
  sw    $a0, 0xe0($sp)
  lw    $t3, ($t1)
  bnezl $t3, .L7F012A90
   lw    $t6, 0x80($sp)
  lw    $t4, ($fp)
  sw    $a0, 0xe0($sp)
  bnezl $t4, .L7F012A90
   lw    $t6, 0x80($sp)
  jal   get_textptr_for_textID
   li    $a0, 40021
  lui   $t5, %hi(ptrFirstFontTableLarge) 
  lw    $t5, %lo(ptrFirstFontTableLarge)($t5)
  lui   $a3, %hi(ptrSecondFontTableLarge)
  move  $s3, $v0
  lw    $a3, %lo(ptrSecondFontTableLarge)($a3)
  addiu $a0, $sp, 0xbc
  addiu $a1, $sp, 0xb8
  move  $a2, $v0
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t5, 0x10($sp)
  lw    $t2, 0xb8($sp)
  sra   $t6, $s4, 1
  addu  $t7, $t6, $s2
  sra   $t8, $t2, 1
  subu  $t9, $t7, $t8
  sw    $t9, 0xb4($sp)
  sw    $s0, 0xb0($sp)
  jal   microcode_constructor
   move  $a0, $s1
  jal   get_video2_settings_txtClipW
   move  $s1, $v0
  sll   $s0, $v0, 0x10
  sra   $t1, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t1
  lui   $t3, %hi(ptrSecondFontTableLarge) 
  lui   $t4, %hi(ptrFirstFontTableLarge) 
  lw    $t4, %lo(ptrFirstFontTableLarge)($t4)
  lw    $t3, %lo(ptrSecondFontTableLarge)($t3)
  li    $t5, 255
  sw    $t5, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xb4
  addiu $a2, $sp, 0xb0
  move  $a3, $s3
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t4, 0x14($sp)
  jal   write_text_at_abs_coord
   sw    $t3, 0x10($sp)
  move  $s1, $v0
  lw    $t6, 0x80($sp)
.L7F012A90:
  lui   $a0, %hi(mp_chr_setup)
  sra   $t8, $s4, 1
  lw    $t2, ($t6)
  addu  $s6, $t8, $s2
  sll   $t7, $t2, 2
  subu  $t7, $t7, $t2
  sll   $t7, $t7, 2
  addu  $a0, $a0, $t7
  jal   get_textptr_for_textID
   lhu   $a0, %lo(mp_chr_setup)($a0)
  lui   $t9, %hi(ptrFirstFontTableLarge) 
  lw    $t9, %lo(ptrFirstFontTableLarge)($t9)
  lui   $a3, %hi(ptrSecondFontTableLarge)
  move  $s3, $v0
  lw    $a3, %lo(ptrSecondFontTableLarge)($a3)
  addiu $a0, $sp, 0xa8
  addiu $a1, $sp, 0xa4
  move  $a2, $v0
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t9, 0x10($sp)
  lw    $t1, 0xa4($sp)
  addiu $t5, $s7, 0x78
  sw    $t5, 0x9c($sp)
  sra   $t3, $t1, 1
  subu  $t4, $s6, $t3
  sw    $t4, 0xa0($sp)
  jal   microcode_constructor
   move  $a0, $s1
  jal   get_video2_settings_txtClipW
   move  $s1, $v0
  sll   $s0, $v0, 0x10
  sra   $t6, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t6
  lui   $t2, %hi(ptrSecondFontTableLarge) 
  lui   $t7, %hi(ptrFirstFontTableLarge) 
  lw    $t7, %lo(ptrFirstFontTableLarge)($t7)
  lw    $t2, %lo(ptrSecondFontTableLarge)($t2)
  li    $t8, 255
  sw    $t8, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xa0
  addiu $a2, $sp, 0x9c
  move  $a3, $s3
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t7, 0x14($sp)
  jal   write_text_at_abs_coord
   sw    $t2, 0x10($sp)
  lw    $t9, 0x74($sp)
  lw    $t3, 0x70($sp)
  lw    $s4, 0x8c($sp)
  lw    $t1, ($t9)
  addiu $s5, $s7, 0x46
  sw    $s5, 0x10($sp)
  lw    $t5, ($fp)
  lw    $t4, ($t3)
  addiu $s3, $s2, 0xd
  addiu $s4, $s4, -0xe
  move  $a2, $s4
  move  $a1, $s3
  move  $a0, $v0
  subu  $a3, $s6, $t1
  sw    $t5, 0x18($sp)
  jal   sub_GAME_7F01231C
   sw    $t4, 0x14($sp)
  lw    $t6, 0x88($sp)
  move  $s1, $v0
  lw    $t8, 0x70($sp)
  lw    $t2, ($t6)
  lw    $t1, 0x80($sp)
  bnezl $t2, .L7F012BD0
   lw    $t9, ($t8)
  lw    $t7, ($fp)
  beql  $t7, $zero, .L7F012BE0
   lw    $t4, 0x70($sp)
  lw    $t9, ($t8)
.L7F012BD0:
  lw    $t3, ($t1)
  beql  $t9, $t3, .L7F012DB0
   lw    $t3, 0x88($sp)
  lw    $t4, 0x70($sp)
.L7F012BE0:
  move  $a0, $s1
  move  $a1, $s3
  lw    $s0, ($t4)
  move  $a2, $s4
  lw    $t5, 0x74($sp)
  slti  $at, $s0, 3
  bnez  $at, .L7F012C2C
   addiu $t2, $s0, -3
  lw    $t6, ($t5)
  lw    $t7, ($fp)
  sw    $t2, 0x14($sp)
  subu  $a3, $s6, $t6
  addiu $a3, $a3, -0xfc
  sw    $s5, 0x10($sp)
  jal   sub_GAME_7F01231C
   sw    $t7, 0x18($sp)
  lw    $t8, 0x70($sp)
  move  $s1, $v0
  lw    $s0, ($t8)
.L7F012C2C:
  slti  $at, $s0, 2
  bnez  $at, .L7F012C74
   move  $a0, $s1
  lw    $t1, 0x74($sp)
  lw    $t4, ($fp)
  addiu $t3, $s0, -2
  lw    $t9, ($t1)
  sw    $t3, 0x14($sp)
  sw    $s5, 0x10($sp)
  subu  $a3, $s6, $t9
  addiu $a3, $a3, -0xa8
  move  $a1, $s3
  move  $a2, $s4
  jal   sub_GAME_7F01231C
   sw    $t4, 0x18($sp)
  lw    $t5, 0x70($sp)
  move  $s1, $v0
  lw    $s0, ($t5)
.L7F012C74:
  blez  $s0, .L7F012CB8
   move  $a0, $s1
  lw    $t6, 0x74($sp)
  lw    $t8, ($fp)
  addiu $t7, $s0, -1
  lw    $t2, ($t6)
  sw    $t7, 0x14($sp)
  sw    $s5, 0x10($sp)
  subu  $a3, $s6, $t2
  addiu $a3, $a3, -0x54
  move  $a1, $s3
  move  $a2, $s4
  jal   sub_GAME_7F01231C
   sw    $t8, 0x18($sp)
  lw    $t1, 0x70($sp)
  move  $s1, $v0
  lw    $s0, ($t1)
.L7F012CB8:
  lui   $v1, %hi(num_chars_selectable_mp)
  lw    $v1, %lo(num_chars_selectable_mp)($v1)
  move  $a0, $s1
  move  $a1, $s3
  addiu $t9, $v1, -1
  slt   $at, $s0, $t9
  beqz  $at, .L7F012D14
   move  $a2, $s4
  lw    $t3, 0x74($sp)
  lw    $t6, ($fp)
  addiu $t5, $s0, 1
  lw    $t4, ($t3)
  sw    $t5, 0x14($sp)
  sw    $s5, 0x10($sp)
  subu  $a3, $s6, $t4
  addiu $a3, $a3, 0x54
  jal   sub_GAME_7F01231C
   sw    $t6, 0x18($sp)
  lw    $t2, 0x70($sp)
  lui   $v1, %hi(num_chars_selectable_mp)
  lw    $v1, %lo(num_chars_selectable_mp)($v1)
  move  $s1, $v0
  lw    $s0, ($t2)
.L7F012D14:
  addiu $t7, $v1, -2
  slt   $at, $s0, $t7
  beqz  $at, .L7F012D68
   move  $a0, $s1
  lw    $t8, 0x74($sp)
  lw    $t3, ($fp)
  addiu $t9, $s0, 2
  lw    $t1, ($t8)
  sw    $t9, 0x14($sp)
  sw    $s5, 0x10($sp)
  subu  $a3, $s6, $t1
  addiu $a3, $a3, 0xa8
  move  $a1, $s3
  move  $a2, $s4
  jal   sub_GAME_7F01231C
   sw    $t3, 0x18($sp)
  lw    $t4, 0x70($sp)
  lui   $v1, %hi(num_chars_selectable_mp)
  lw    $v1, %lo(num_chars_selectable_mp)($v1)
  move  $s1, $v0
  lw    $s0, ($t4)
.L7F012D68:
  addiu $t5, $v1, -3
  slt   $at, $s0, $t5
  beqz  $at, .L7F012DAC
   move  $a0, $s1
  lw    $t6, 0x74($sp)
  lw    $t8, ($fp)
  addiu $t7, $s0, 3
  lw    $t2, ($t6)
  sw    $t7, 0x14($sp)
  sw    $s5, 0x10($sp)
  subu  $a3, $s6, $t2
  addiu $a3, $a3, 0xfc
  move  $a1, $s3
  move  $a2, $s4
  jal   sub_GAME_7F01231C
   sw    $t8, 0x18($sp)
  move  $s1, $v0
.L7F012DAC:
  lw    $t3, 0x88($sp)
.L7F012DB0:
  lw    $t1, 0xe0($sp)
  lw    $t5, 0x80($sp)
  lw    $t2, 0x74($sp)
  lw    $t8, 0x70($sp)
  addiu $t4, $t3, 4
  lw    $t3, 0xe4($sp)
  addiu $t9, $t1, 1
  addiu $t6, $t5, 4
  addiu $t7, $t2, 4
  addiu $t1, $t8, 4
  sw    $t1, 0x70($sp)
  sw    $t7, 0x74($sp)
  sw    $t6, 0x80($sp)
  sw    $t9, 0xe0($sp)
  sw    $t4, 0x88($sp)
  bne   $t9, $t3, .L7F0128A4
   addiu $fp, $fp, 4
.L7F012DF4:
  jal   combiner_bayer_lod_perspective
   move  $a0, $s1
  lw    $ra, 0x64($sp)
  ldc1  $f20, 0x38($sp)
  lw    $s0, 0x40($sp)
  lw    $s1, 0x44($sp)
  lw    $s2, 0x48($sp)
  lw    $s3, 0x4c($sp)
  lw    $s4, 0x50($sp)
  lw    $s5, 0x54($sp)
  lw    $s6, 0x58($sp)
  lw    $s7, 0x5c($sp)
  lw    $fp, 0x60($sp)
  jr    $ra
   addiu $sp, $sp, 0xe8
");

void init_menu10_mphandicap(void) {
  tab_1_selected = false;
  tab_2_selected = false;
  tab_3_selected = false;
  tab_3_highlight = false;
  tab_2_highlight = false;
  tab_1_highlight = false;
  has_selected_char_player1 = false;
  dword_CODE_bss_80069760 = 0;
  has_selected_char_player2 = false;
  dword_CODE_bss_80069764 = 0;
  has_selected_char_player3 = false;
  dword_CODE_bss_80069768 = 0;
  has_selected_char_player4 = false;
  dword_CODE_bss_8006976C = 0;
  load_walletbond();
}

void update_menu10_mphandicap(void) {}

asm(R"
.late_rodata
glabel D_80051A90
.word 0x3FAAAAAB /*1.3333334;*/
glabel D_80051A94
.word 0x461C4000 /*10000.0;*/

.text
glabel interface_menu10_mphandicap
  addiu $sp, $sp, -0x48
  sw    $ra, 0x3c($sp)
  sw    $fp, 0x38($sp)
  sw    $s7, 0x34($sp)
  sw    $s6, 0x30($sp)
  sw    $s5, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  jal   get_selected_num_players
   sw    $s0, 0x18($sp)
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f12
  sw    $v0, 0x44($sp)
  jal   setvideo_far
   move  $fp, $zero
  lui   $at, %hi(D_80051A90)
  jal   video_related_21
   lwc1  $f12, %lo(D_80051A90)($at)
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f12
  lui   $at, %hi(D_80051A94)
  jal   set_page_height
   lwc1  $f14, %lo(D_80051A94)($at)
  jal   set_video2_settings_offset_24
   move  $a0, $zero
  lw    $t6, 0x44($sp)
  move  $s3, $zero
  move  $s4, $zero
  blez  $t6, .L7F0130FC
   lui   $s1, %hi(has_selected_char_player1)
  lui   $s6, %hi(handicap_player1)
  lui   $s5, %hi(ptr_sfx_buf)
  addiu $s5, %lo(ptr_sfx_buf) # addiu $s5, $s5, 0x3720
  addiu $s6, %lo(handicap_player1) # addiu $s6, $s6, -0x6858
  addiu $s1, %lo(has_selected_char_player1) # addiu $s1, $s1, -0x68c0
  li    $s7, 1
.L7F012F5C:
  lw    $t7, ($s1)
  sll   $a0, $s3, 0x18
  sra   $t8, $a0, 0x18
  beqz  $t7, .L7F012F90
   move  $a0, $t8
  jal   get_controller_buttons_pressed
   li    $a1, 16384
  beqz  $v0, .L7F012F90
   li    $a1, 199
  sw    $zero, ($s1)
  lw    $a0, ($s5)
  jal   play_sfx_a1
   move  $a2, $zero
.L7F012F90:
  lw    $v0, ($s1)
  sll   $s0, $s3, 0x18
  sra   $t9, $s0, 0x18
  bnez  $v0, .L7F0130E0
   move  $s0, $t9
  sll   $a0, $t9, 0x18
  lui   $t1, %hi(dword_CODE_bss_80069760)
  addiu $t1, $t1, %lo(dword_CODE_bss_80069760)
  sra   $t0, $a0, 0x18
  move  $a0, $t0
  addu  $s2, $s4, $t1
  jal   get_controller_buttons_pressed
   li    $a1, 514
  bnez  $v0, .L7F012FF4
   sll   $a0, $s0, 0x18
  sra   $t2, $a0, 0x18
  move  $a0, $t2
  li    $a1, -2
  jal   get_controller_3dstick_L_R
   move  $a2, $s7
  slti  $at, $v0, -1
  beqz  $at, .L7F01300C
   sll   $a0, $s0, 0x18
  lw    $t3, ($s2)
  beqz  $t3, .L7F01300C
.L7F012FF4:
   addu  $v0, $s6, $s4
  lw    $v1, ($v0)
  blez  $v1, .L7F01308C
   addiu $t4, $v1, -1
  b     .L7F01308C
   sw    $t4, ($v0)
.L7F01300C:
  sra   $t5, $a0, 0x18
  move  $a0, $t5
  jal   get_controller_buttons_pressed
   li    $a1, 257
  bnez  $v0, .L7F013048
   sll   $a0, $s0, 0x18
  sra   $t6, $a0, 0x18
  move  $a0, $t6
  li    $a1, -2
  jal   get_controller_3dstick_L_R
   move  $a2, $s7
  blez  $v0, .L7F013064
   sll   $a0, $s0, 0x18
  lw    $t7, ($s2)
  beqz  $t7, .L7F013064
.L7F013048:
   addu  $v0, $s6, $s4
  lw    $v1, ($v0)
  slti  $at, $v1, 0xa
  beqz  $at, .L7F01308C
   addiu $t8, $v1, 1
  b     .L7F01308C
   sw    $t8, ($v0)
.L7F013064:
  sra   $t9, $a0, 0x18
  move  $a0, $t9
  jal   get_controller_buttons_pressed
   li    $a1, 45056
  beqz  $v0, .L7F01308C
   li    $a1, 199
  sw    $s7, ($s1)
  lw    $a0, ($s5)
  jal   play_sfx_a1
   move  $a2, $zero
.L7F01308C:
  sll   $a0, $s0, 0x18
  sra   $t0, $a0, 0x18
  move  $a0, $t0
  li    $a1, -2
  jal   get_controller_3dstick_L_R
   move  $a2, $s7
  li    $at, -1
  beq   $v0, $at, .L7F0130CC
   sll   $a0, $s0, 0x18
  sra   $t1, $a0, 0x18
  move  $a0, $t1
  li    $a1, -2
  jal   get_controller_3dstick_L_R
   move  $a2, $s7
  bnezl $v0, .L7F0130DC
   sw    $zero, ($s2)
.L7F0130CC:
  sw    $s7, ($s2)
  b     .L7F0130E0
   lw    $v0, ($s1)
  sw    $zero, ($s2)
.L7F0130DC:
  lw    $v0, ($s1)
.L7F0130E0:
  beqz  $v0, .L7F0130EC
   lw    $t2, 0x44($sp)
  addiu $fp, $fp, 1
.L7F0130EC:
  addiu $s3, $s3, 1
  addiu $s4, $s4, 4
  bne   $s3, $t2, .L7F012F5C
   addiu $s1, $s1, 4
.L7F0130FC:
  lui   $s0, %hi(ptr_folder_object_instance)
  addiu $s0, %lo(ptr_folder_object_instance) # addiu $s0, $s0, -0x56a4
  jal   disable_all_switches
   lw    $a0, ($s0)
  lw    $a0, ($s0)
  move  $a1, $zero
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lw    $a0, ($s0)
  li    $a1, 42
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  jal   menu_control_stick_tracking
   nop   
  lw    $t3, 0x44($sp)
  li    $a0, 14
  bnel  $fp, $t3, .L7F013150
   lw    $ra, 0x3c($sp)
  jal   set_menu_to_mode
   move  $a1, $zero
  lw    $ra, 0x3c($sp)
.L7F013150:
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
   addiu $sp, $sp, 0x48
");

asm(R"
glabel constructor_menu10_mphandicap
  addiu $sp, $sp, -0xd0
  sw    $ra, 0x64($sp)
  sw    $s1, 0x44($sp)
  move  $s1, $a0
  sw    $fp, 0x60($sp)
  sw    $s7, 0x5c($sp)
  sw    $s6, 0x58($sp)
  sw    $s5, 0x54($sp)
  sw    $s4, 0x50($sp)
  sw    $s3, 0x4c($sp)
  sw    $s2, 0x48($sp)
  sw    $s0, 0x40($sp)
  jal   get_selected_num_players
   sdc1  $f20, 0x38($sp)
  sw    $v0, 0xcc($sp)
  move  $a0, $s1
  move  $a1, $zero
  move  $a2, $zero
  jal   set_setfillcolor
   move  $a3, $zero
  jal   insert_generic_fillrect
   move  $a0, $v0
  jal   sub_GAME_7F00D5E8
   move  $a0, $v0
  jal   microcode_constructor
   move  $a0, $v0
  li    $t6, 171
  li    $t7, 144
  sw    $t7, 0x14($sp)
  sw    $t6, 0x10($sp)
  move  $a0, $v0
  li    $a1, 38
  li    $a2, 169
  jal   microcode_constructor_related_to_menus
   li    $a3, 388
  lw    $t0, 0xcc($sp)
  move  $s1, $v0
  move  $a0, $s1
  slti  $at, $t0, 3
  bnez  $at, .L7F013244
   li    $a1, 212
  li    $t8, 310
  li    $t9, 128
  sw    $t9, 0x14($sp)
  sw    $t8, 0x10($sp)
  li    $a2, 30
  jal   microcode_constructor_related_to_menus
   li    $a3, 214
  move  $s1, $v0
  lw    $t0, 0xcc($sp)
.L7F013244:
  blez  $t0, .L7F013538
   move  $s6, $zero
  lui   $t1, %hi(has_selected_char_player1) 
  lui   $t2, %hi(handicap_player1) 
  li    $at, 0x40800000 # 4.000000
  addiu $t2, %lo(handicap_player1) # addiu $t2, $t2, -0x6858
  addiu $t1, %lo(has_selected_char_player1) # addiu $t1, $t1, -0x68c0
  lui   $fp, %hi(ptrFirstFontTableLarge) 
  lui   $s7, %hi(ptrSecondFontTableLarge) 
  mtc1  $at, $f20
  addiu $s7, %lo(ptrSecondFontTableLarge) # addiu $s7, $s7, 0xeb8
  addiu $fp, %lo(ptrFirstFontTableLarge) # addiu $fp, $fp, 0xeb4
  sw    $t1, 0x74($sp)
  sw    $t2, 0x70($sp)
.L7F01327C:
  lw    $t0, 0xcc($sp)
  li    $at, 2
  li    $s3, 38
  bne   $t0, $at, .L7F0132AC
   andi  $t3, $s6, 1
  blez  $s6, .L7F0132A0
   li    $s5, 350
  b     .L7F0132DC
   li    $s2, 170
.L7F0132A0:
  move  $v1, $zero
  b     .L7F0132DC
   addiu $s2, $v1, 0x1e
.L7F0132AC:
  slti  $at, $s6, 2
  bnez  $at, .L7F0132C0
   li    $s5, 175
  b     .L7F0132C4
   li    $v1, 140
.L7F0132C0:
  move  $v1, $zero
.L7F0132C4:
  beqz  $t3, .L7F0132D4
   addiu $s2, $v1, 0x1e
  b     .L7F0132D8
   li    $v1, 175
.L7F0132D4:
  move  $v1, $zero
.L7F0132D8:
  addiu $s3, $v1, 0x26
.L7F0132DC:
  addiu $t4, $s3, 6
  mtc1  $t4, $f4
  addiu $t1, $s2, 5
  mtc1  $t1, $f16
  cvt.s.w $f6, $f4
  lui   $at, 0xed00
  addiu $s1, $v0, 8
  cvt.s.w $f18, $f16
  mul.s $f8, $f6, $f20
  trunc.w.s $f10, $f8
  mul.s $f4, $f18, $f20
  mfc1  $t6, $f10
  nop   
  andi  $t7, $t6, 0xfff
  trunc.w.s $f6, $f4
  sll   $t8, $t7, 0xc
  addu  $t6, $s3, $s5
  addiu $t7, $t6, -6
  mfc1  $t3, $f6
  mtc1  $t7, $f8
  or    $t9, $t8, $at
  andi  $t4, $t3, 0xfff
  or    $t5, $t9, $t4
  addiu $t9, $s2, 0x87
  cvt.s.w $f10, $f8
  mtc1  $t9, $f4
  sw    $t5, ($v0)
  cvt.s.w $f6, $f4
  mul.s $f16, $f10, $f20
  nop   
  mul.s $f8, $f6, $f20
  trunc.w.s $f18, $f16
  trunc.w.s $f10, $f8
  mfc1  $t1, $f18
  mfc1  $t5, $f10
  andi  $t2, $t1, 0xfff
  sll   $t3, $t2, 0xc
  andi  $t6, $t5, 0xfff
  or    $t7, $t3, $t6
  sw    $t7, 4($v0)
  lw    $t8, 0x74($sp)
  lw    $t1, ($t8)
  bnez  $t1, .L7F013444
   nop   
  jal   get_textptr_for_textID
   li    $a0, 40022
  lw    $t2, ($fp)
  move  $s4, $v0
  addiu $a0, $sp, 0xa4
  addiu $a1, $sp, 0xa0
  move  $a2, $v0
  lw    $a3, ($s7)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t2, 0x10($sp)
  lw    $t7, 0xa4($sp)
  lw    $t5, 0xa0($sp)
  sra   $t9, $s5, 1
  sra   $t8, $t7, 1
  addu  $t4, $t9, $s3
  subu  $t1, $s2, $t8
  sra   $t3, $t5, 1
  subu  $t6, $t4, $t3
  addiu $t2, $t1, 0x37
  sw    $t6, 0x9c($sp)
  sw    $t2, 0x98($sp)
  jal   microcode_constructor
   move  $a0, $s1
  jal   get_video2_settings_txtClipW
   move  $s1, $v0
  sll   $s0, $v0, 0x10
  sra   $t9, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t9
  lw    $t5, ($s7)
  lw    $t4, ($fp)
  li    $t3, 255
  sw    $t3, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0x9c
  addiu $a2, $sp, 0x98
  move  $a3, $s4
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t5, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t4, 0x14($sp)
  move  $s1, $v0
.L7F013444:
  lw    $t6, 0x70($sp)
  lui   $a0, %hi(MP_handicap_table)
  sra   $t1, $s5, 1
  lw    $t7, ($t6)
  addu  $s0, $t1, $s3
  addiu $s4, $s2, 0x46
  sll   $t8, $t7, 3
  addu  $a0, $a0, $t8
  jal   get_textptr_for_textID
   lhu   $a0, %lo(MP_handicap_table)($a0)
  lw    $t2, ($fp)
  move  $s2, $v0
  addiu $a0, $sp, 0x90
  addiu $a1, $sp, 0x8c
  move  $a2, $v0
  lw    $a3, ($s7)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t2, 0x10($sp)
  lw    $t3, 0x90($sp)
  lw    $t9, 0x8c($sp)
  move  $a0, $s1
  sra   $t6, $t3, 1
  subu  $t7, $s4, $t6
  sra   $t5, $t9, 1
  subu  $t4, $s0, $t5
  addiu $t8, $t7, 0xf
  sw    $t4, 0x88($sp)
  jal   microcode_constructor
   sw    $t8, 0x84($sp)
  jal   get_video2_settings_txtClipW
   move  $s1, $v0
  sll   $s0, $v0, 0x10
  sra   $t1, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t1
  lw    $t2, ($s7)
  lw    $t9, ($fp)
  li    $t5, 255
  sw    $t5, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0x88
  addiu $a2, $sp, 0x84
  move  $a3, $s2
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t2, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t9, 0x14($sp)
  lw    $t4, 0x74($sp)
  lw    $t6, 0x70($sp)
  lw    $t8, 0xcc($sp)
  addiu $s6, $s6, 1
  addiu $t3, $t4, 4
  addiu $t7, $t6, 4
  sw    $t7, 0x70($sp)
  sw    $t3, 0x74($sp)
  bne   $s6, $t8, .L7F01327C
   move  $s1, $v0
.L7F013538:
  jal   combiner_bayer_lod_perspective
   move  $a0, $s1
  lw    $ra, 0x64($sp)
  ldc1  $f20, 0x38($sp)
  lw    $s0, 0x40($sp)
  lw    $s1, 0x44($sp)
  lw    $s2, 0x48($sp)
  lw    $s3, 0x4c($sp)
  lw    $s4, 0x50($sp)
  lw    $s5, 0x54($sp)
  lw    $s6, 0x58($sp)
  lw    $s7, 0x5c($sp)
  lw    $fp, 0x60($sp)
  jr    $ra
   addiu $sp, $sp, 0xd0
");

void init_menu11_mpcontrol(void) {
  tab_1_selected = false;
  tab_2_selected = false;
  tab_3_selected = false;
  tab_3_highlight = false;
  tab_2_highlight = false;
  tab_1_highlight = false;
  has_selected_char_player1 = false;
  dword_CODE_bss_80069760 = 0;
  has_selected_char_player2 = false;
  dword_CODE_bss_80069764 = 0;
  has_selected_char_player3 = false;
  dword_CODE_bss_80069768 = 0;
  has_selected_char_player4 = false;
  dword_CODE_bss_8006976C = 0;
  load_walletbond();
}

void update_menu11_mpcontrols(void) {}

#ifdef VERSION_US
asm(R"
.late_rodata
glabel D_80051A98
.word 0x3FAAAAAB /*1.3333334;*/
glabel D_80051A9C
.word 0x461C4000 /*10000.0;*/

.text
glabel interface_menu11_mpcontrols
  addiu $sp, $sp, -0x50
  sw    $ra, 0x3c($sp)
  sw    $fp, 0x38($sp)
  sw    $s7, 0x34($sp)
  sw    $s6, 0x30($sp)
  sw    $s5, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  jal   get_selected_num_players
   sw    $s0, 0x18($sp)
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f12
  move  $s6, $v0
  jal   setvideo_far
   sw    $zero, 0x44($sp)
  lui   $at, %hi(D_80051A98)
  jal   video_related_21
   lwc1  $f12, %lo(D_80051A98)($at)
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f12
  lui   $at, %hi(D_80051A9C)
  jal   set_page_height
   lwc1  $f14, %lo(D_80051A9C)($at)
  jal   set_video2_settings_offset_24
   move  $a0, $zero
  blez  $s6, .L7F013900
   move  $s1, $zero
  lui   $s2, %hi(has_selected_char_player1)
  lui   $s3, %hi(controlstyle_player)
  addiu $s3, %lo(controlstyle_player) # addiu $s3, $s3, -0x6848
  addiu $s2, %lo(has_selected_char_player1) # addiu $s2, $s2, -0x68c0
  move  $s5, $zero
  li    $fp, 1
  li    $s7, 2
.L7F013698:
  lw    $t6, ($s2)
  sll   $a0, $s1, 0x18
  sra   $t7, $a0, 0x18
  beqz  $t6, .L7F0136D0
   move  $a0, $t7
  jal   get_controller_buttons_pressed
   li    $a1, 16384
  beqz  $v0, .L7F0136D0
   lui   $a0, %hi(ptr_sfx_buf)
  sw    $zero, ($s2)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 199
  jal   play_sfx_a1
   move  $a2, $zero
.L7F0136D0:
  lw    $v0, ($s2)
  sll   $s0, $s1, 0x18
  sra   $t8, $s0, 0x18
  bnez  $v0, .L7F0138E0
   move  $s0, $t8
  sll   $a0, $t8, 0x18
  lui   $t0, %hi(dword_CODE_bss_80069760)
  addiu $t0, $t0, %lo(dword_CODE_bss_80069760)
  sra   $t9, $a0, 0x18
  move  $a0, $t9
  addu  $s4, $s5, $t0
  jal   get_controller_buttons_pressed
   li    $a1, 514
  bnez  $v0, .L7F013734
   sll   $a0, $s0, 0x18
  sra   $t1, $a0, 0x18
  move  $a0, $t1
  li    $a1, -2
  jal   get_controller_3dstick_L_R
   move  $a2, $fp
  slti  $at, $v0, -1
  beqz  $at, .L7F0137A8
   sll   $a0, $s0, 0x18
  lw    $t2, ($s4)
  beqz  $t2, .L7F0137A8
.L7F013734:
   addu  $v1, $s3, $s5
  lw    $v0, ($v1)
  blezl $v0, .L7F013890
   sll   $a0, $s0, 0x18
  bne   $s6, $s7, .L7F01376C
   addiu $t4, $v0, -1
  bnel  $s1, $fp, .L7F013770
   sw    $t4, ($v1)
  lw    $t3, ($s3)
  slti  $at, $t3, 4
  bnez  $at, .L7F01376C
   slti  $at, $v0, 5
  bnez  $at, .L7F013770
   nop   
.L7F01376C:
  sw    $t4, ($v1)
.L7F013770:
  bnel  $s6, $s7, .L7F013890
   sll   $a0, $s0, 0x18
  bnezl $s1, .L7F013890
   sll   $a0, $s0, 0x18
  lw    $t5, ($s3)
  slti  $at, $t5, 4
  beql  $at, $zero, .L7F013890
   sll   $a0, $s0, 0x18
  lw    $t6, 4($s3)
  slti  $at, $t6, 4
  bnezl $at, .L7F013890
   sll   $a0, $s0, 0x18
  b     .L7F01388C
   sw    $zero, 4($s3)
.L7F0137A8:
  sra   $t7, $a0, 0x18
  move  $a0, $t7
  jal   get_controller_buttons_pressed
   li    $a1, 257
  bnez  $v0, .L7F0137E8
   sll   $a0, $s0, 0x18
  sra   $t8, $a0, 0x18
  move  $a0, $t8
  li    $a1, -2
  jal   get_controller_3dstick_L_R
   move  $a2, $fp
  blez  $v0, .L7F013860
   sll   $a0, $s0, 0x18
  lw    $t9, ($s4)
  beql  $t9, $zero, .L7F013864
   sra   $t5, $a0, 0x18
.L7F0137E8:
  bne   $s6, $s7, .L7F0137F8
   addu  $v1, $s3, $s5
  beql  $s1, $zero, .L7F01380C
   lw    $v0, ($v1)
.L7F0137F8:
  lw    $v0, ($v1)
  slti  $at, $v0, 4
  bnezl $at, .L7F013850
   slti  $at, $v0, 3
  lw    $v0, ($v1)
.L7F01380C:
  slti  $at, $v0, 7
  beqz  $at, .L7F01388C
   addiu $t0, $v0, 1
  bnez  $s1, .L7F01388C
   sw    $t0, ($v1)
  lw    $t1, ($s3)
  li    $at, 4
  bnel  $t1, $at, .L7F013890
   sll   $a0, $s0, 0x18
  lw    $t2, 4($s3)
  li    $t3, 4
  slti  $at, $t2, 4
  beql  $at, $zero, .L7F013890
   sll   $a0, $s0, 0x18
  b     .L7F01388C
   sw    $t3, 4($s3)
  slti  $at, $v0, 3
.L7F013850:
  beqz  $at, .L7F01388C
   addiu $t4, $v0, 1
  b     .L7F01388C
   sw    $t4, ($v1)
.L7F013860:
  sra   $t5, $a0, 0x18
.L7F013864:
  move  $a0, $t5
  jal   get_controller_buttons_pressed
   li    $a1, 45056
  beqz  $v0, .L7F01388C
   lui   $a0, %hi(ptr_sfx_buf)
  sw    $fp, ($s2)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 199
  jal   play_sfx_a1
   move  $a2, $zero
.L7F01388C:
  sll   $a0, $s0, 0x18
.L7F013890:
  sra   $t6, $a0, 0x18
  move  $a0, $t6
  li    $a1, -2
  jal   get_controller_3dstick_L_R
   move  $a2, $fp
  li    $at, -1
  beq   $v0, $at, .L7F0138CC
   sll   $a0, $s0, 0x18
  sra   $t7, $a0, 0x18
  move  $a0, $t7
  li    $a1, -2
  jal   get_controller_3dstick_L_R
   move  $a2, $fp
  bnezl $v0, .L7F0138DC
   sw    $zero, ($s4)
.L7F0138CC:
  sw    $fp, ($s4)
  b     .L7F0138E0
   lw    $v0, ($s2)
  sw    $zero, ($s4)
.L7F0138DC:
  lw    $v0, ($s2)
.L7F0138E0:
  beqz  $v0, .L7F0138F4
   addiu $s1, $s1, 1
  lw    $t8, 0x44($sp)
  addiu $t9, $t8, 1
  sw    $t9, 0x44($sp)
.L7F0138F4:
  addiu $s5, $s5, 4
  bne   $s1, $s6, .L7F013698
   addiu $s2, $s2, 4
.L7F013900:
  lui   $s0, %hi(ptr_folder_object_instance)
  addiu $s0, %lo(ptr_folder_object_instance) # addiu $s0, $s0, -0x56a4
  jal   disable_all_switches
   lw    $a0, ($s0)
  lw    $a0, ($s0)
  move  $a1, $zero
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lw    $a0, ($s0)
  li    $a1, 42
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  jal   menu_control_stick_tracking
   nop   
  lw    $t0, 0x44($sp)
  li    $a0, 14
  bnel  $t0, $s6, .L7F013954
   lw    $ra, 0x3c($sp)
  jal   set_menu_to_mode
   move  $a1, $zero
  lw    $ra, 0x3c($sp)
.L7F013954:
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
   addiu $sp, $sp, 0x50
");
#endif

#ifdef VERSION_JP
asm(R"
.late_rodata
glabel D_80051A98
.word 0x3FAAAAAB /*1.3333334;*/
glabel D_80051A9C
.word 0x461C4000 /*10000.0;*/
.text
glabel interface_menu11_mpcontrols
  addiu $sp, $sp, -0x60
  sw    $ra, 0x3c($sp)
  sw    $fp, 0x38($sp)
  sw    $s7, 0x34($sp)
  sw    $s6, 0x30($sp)
  sw    $s5, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  jal   get_selected_num_players
   sw    $s0, 0x18($sp)
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f12
  move  $s7, $v0
  jal   setvideo_far
   sw    $zero, 0x54($sp)
  lui   $at, %hi(D_80051A98) # $at, 0x8005
  jal   video_related_21
   lwc1  $f12, %lo(D_80051A98)($at)
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f12
  lui   $at, %hi(D_80051A9C) # $at, 0x8005
  jal   set_page_height
   lwc1  $f14, %lo(D_80051A9C)($at)
  jal   set_video2_settings_offset_24
   move  $a0, $zero
  blez  $s7, .L7F0139B0
   move  $s2, $zero
  lui   $s3, %hi(has_selected_char_player1) # $s3, 0x8007
  lui   $s0, %hi(controlstyle_player) # $s0, 0x8007
  addiu $s0, %lo(controlstyle_player) # addiu $s0, $s0, -0x6808
  addiu $s3, %lo(has_selected_char_player1) # addiu $s3, $s3, -0x6880
  move  $s6, $zero
  li    $fp, 2
  li    $s4, 4
.L7F0136D8:
  lw    $t6, ($s3)
  sll   $a0, $s2, 0x18
  sra   $t7, $a0, 0x18
  beqz  $t6, .L7F013710
   move  $a0, $t7
  jal   get_controller_buttons_pressed
   li    $a1, 16384
  beqz  $v0, .L7F013710
   lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  sw    $zero, ($s3)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 199
  jal   play_sfx_a1
   move  $a2, $zero
.L7F013710:
  lw    $v0, ($s3)
  sll   $s1, $s2, 0x18
  sra   $t8, $s1, 0x18
  bnez  $v0, .L7F013990
   move  $s1, $t8
  sll   $a0, $t8, 0x18
  lui   $t0, %hi(dword_CODE_bss_80069760) # $t0, 0x8007
  addiu $t0, %lo(dword_CODE_bss_80069760) # addiu $t0, $t0, -0x6860
  sra   $t9, $a0, 0x18
  move  $a0, $t9
  addu  $s5, $s6, $t0
  jal   get_controller_buttons_pressed
   li    $a1, 514
  bnez  $v0, .L7F013774
   sll   $a0, $s1, 0x18
  sra   $t1, $a0, 0x18
  move  $a0, $t1
  li    $a1, -2
  jal   get_controller_3dstick_L_R
   li    $a2, 1
  slti  $at, $v0, -1
  beqz  $at, .L7F013818
   sll   $a0, $s1, 0x18
  lw    $t2, ($s5)
  beqz  $t2, .L7F013818
.L7F013774:
   addu  $v1, $s0, $s6
  lw    $t3, ($v1)
  blez  $t3, .L7F013908
   nop   
  bne   $s7, $fp, .L7F0137C4
   li    $at, 1
  bnel  $s2, $at, .L7F0137C8
   lw    $t6, ($v1)
  jal   get_attached_controller_count
   sw    $v1, 0x40($sp)
  bne   $v0, $s4, .L7F0137C4
   lw    $v1, 0x40($sp)
  lw    $t4, ($s0)
  slti  $at, $t4, 4
  bnezl $at, .L7F0137C8
   lw    $t6, ($v1)
  lw    $t5, ($v1)
  slti  $at, $t5, 5
  bnez  $at, .L7F0137D0
   nop   
.L7F0137C4:
  lw    $t6, ($v1)
.L7F0137C8:
  addiu $t7, $t6, -1
  sw    $t7, ($v1)
.L7F0137D0:
  bne   $s7, $fp, .L7F013908
   nop   
  bnez  $s2, .L7F013908
   nop   
  jal   get_attached_controller_count
   nop   
  bne   $v0, $s4, .L7F013908
   nop   
  lw    $t8, ($s0)
  slti  $at, $t8, 4
  beqz  $at, .L7F013908
   nop   
  lw    $t9, 4($s0)
  slti  $at, $t9, 4
  bnez  $at, .L7F013908
   nop   
  b     .L7F013908
   sw    $zero, 4($s0)
.L7F013818:
  sra   $t0, $a0, 0x18
  move  $a0, $t0
  jal   get_controller_buttons_pressed
   li    $a1, 257
  bnez  $v0, .L7F013858
   sll   $a0, $s1, 0x18
  sra   $t1, $a0, 0x18
  move  $a0, $t1
  li    $a1, -2
  jal   get_controller_3dstick_L_R
   li    $a2, 1
  blez  $v0, .L7F0138D8
   sll   $a0, $s1, 0x18
  lw    $t2, ($s5)
  beql  $t2, $zero, .L7F0138DC
   sra   $t7, $a0, 0x18
.L7F013858:
  bne   $s7, $fp, .L7F013878
   addu  $v1, $s0, $s6
  bnezl $s2, .L7F01387C
   lw    $v0, ($v1)
  jal   get_attached_controller_count
   sw    $v1, 0x40($sp)
  beq   $v0, $s4, .L7F013888
   lw    $v1, 0x40($sp)
.L7F013878:
  lw    $v0, ($v1)
.L7F01387C:
  slti  $at, $v0, 4
  bnezl $at, .L7F0138C8
   slti  $at, $v0, 3
.L7F013888:
  lw    $v0, ($v1)
  slti  $at, $v0, 7
  beqz  $at, .L7F013908
   addiu $t3, $v0, 1
  bnez  $s2, .L7F013908
   sw    $t3, ($v1)
  lw    $t4, ($s0)
  bne   $s4, $t4, .L7F013908
   nop   
  lw    $t5, 4($s0)
  slti  $at, $t5, 4
  beqz  $at, .L7F013908
   nop   
  b     .L7F013908
   sw    $s4, 4($s0)
  slti  $at, $v0, 3
.L7F0138C8:
  beqz  $at, .L7F013908
   addiu $t6, $v0, 1
  b     .L7F013908
   sw    $t6, ($v1)
.L7F0138D8:
  sra   $t7, $a0, 0x18
.L7F0138DC:
  move  $a0, $t7
  jal   get_controller_buttons_pressed
   li    $a1, 45056
  beqz  $v0, .L7F013908
   li    $t8, 1
  sw    $t8, ($s3)
  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 199
  jal   play_sfx_a1
   move  $a2, $zero
.L7F013908:
  jal   get_attached_controller_count
   nop   
  beq   $v0, $s4, .L7F013940
   sll   $a0, $s1, 0x18
  lw    $t9, ($s0)
  slti  $at, $t9, 4
  bnezl $at, .L7F013930
   lw    $t0, 4($s0)
  sw    $zero, ($s0)
  lw    $t0, 4($s0)
.L7F013930:
  slti  $at, $t0, 4
  bnezl $at, .L7F013944
   sra   $t1, $a0, 0x18
  sw    $zero, 4($s0)
.L7F013940:
  sra   $t1, $a0, 0x18
.L7F013944:
  move  $a0, $t1
  li    $a1, -2
  jal   get_controller_3dstick_L_R
   li    $a2, 1
  li    $at, -1
  beq   $v0, $at, .L7F013978
   sll   $a0, $s1, 0x18
  sra   $t2, $a0, 0x18
  move  $a0, $t2
  li    $a1, -2
  jal   get_controller_3dstick_L_R
   li    $a2, 1
  bnez  $v0, .L7F013988
.L7F013978:
   li    $t3, 1
  sw    $t3, ($s5)
  b     .L7F013990
   lw    $v0, ($s3)
.L7F013988:
  sw    $zero, ($s5)
  lw    $v0, ($s3)
.L7F013990:
  beqz  $v0, .L7F0139A4
   addiu $s2, $s2, 1
  lw    $t4, 0x54($sp)
  addiu $t5, $t4, 1
  sw    $t5, 0x54($sp)
.L7F0139A4:
  addiu $s6, $s6, 4
  bne   $s2, $s7, .L7F0136D8
   addiu $s3, $s3, 4
.L7F0139B0:
  lui   $s0, %hi(ptr_folder_object_instance) # $s0, 0x8003
  addiu $s0, %lo(ptr_folder_object_instance) # addiu $s0, $s0, -0x5664
  jal   disable_all_switches
   lw    $a0, ($s0)
  lw    $a0, ($s0)
  move  $a1, $zero
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lw    $a0, ($s0)
  li    $a1, 42
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  jal   menu_control_stick_tracking
   nop   
  lw    $t6, 0x54($sp)
  li    $a0, 14
  bnel  $t6, $s7, .L7F013A04
   lw    $ra, 0x3c($sp)
  jal   set_menu_to_mode
   move  $a1, $zero
  lw    $ra, 0x3c($sp)
.L7F013A04:
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
   addiu $sp, $sp, 0x60

");
#endif

asm(R"
glabel constructor_menu11_mpcontrol
  addiu $sp, $sp, -0xd0
  sw    $ra, 0x64($sp)
  sw    $s1, 0x44($sp)
  move  $s1, $a0
  sw    $fp, 0x60($sp)
  sw    $s7, 0x5c($sp)
  sw    $s6, 0x58($sp)
  sw    $s5, 0x54($sp)
  sw    $s4, 0x50($sp)
  sw    $s3, 0x4c($sp)
  sw    $s2, 0x48($sp)
  sw    $s0, 0x40($sp)
  jal   get_selected_num_players
   sdc1  $f20, 0x38($sp)
  sw    $v0, 0xcc($sp)
  move  $a0, $s1
  move  $a1, $zero
  move  $a2, $zero
  jal   set_setfillcolor
   move  $a3, $zero
  jal   insert_generic_fillrect
   move  $a0, $v0
  jal   sub_GAME_7F00D5E8
   move  $a0, $v0
  jal   microcode_constructor
   move  $a0, $v0
  li    $t6, 171
  li    $t7, 144
  sw    $t7, 0x14($sp)
  sw    $t6, 0x10($sp)
  move  $a0, $v0
  li    $a1, 38
  li    $a2, 169
  jal   microcode_constructor_related_to_menus
   li    $a3, 388
  lw    $t0, 0xcc($sp)
  move  $s1, $v0
  move  $a0, $s1
  slti  $at, $t0, 3
  bnez  $at, .L7F013A48
   li    $a1, 212
  li    $t8, 310
  li    $t9, 128
  sw    $t9, 0x14($sp)
  sw    $t8, 0x10($sp)
  li    $a2, 30
  jal   microcode_constructor_related_to_menus
   li    $a3, 214
  move  $s1, $v0
  lw    $t0, 0xcc($sp)
.L7F013A48:
  blez  $t0, .L7F013D3C
   move  $s6, $zero
  lui   $t1, %hi(has_selected_char_player1) 
  lui   $t2, %hi(controlstyle_player) 
  li    $at, 0x40800000 # 4.000000
  addiu $t2, %lo(controlstyle_player) # addiu $t2, $t2, -0x6848
  addiu $t1, %lo(has_selected_char_player1) # addiu $t1, $t1, -0x68c0
  lui   $fp, %hi(ptrFirstFontTableLarge) 
  lui   $s7, %hi(ptrSecondFontTableLarge) 
  mtc1  $at, $f20
  addiu $s7, %lo(ptrSecondFontTableLarge) # addiu $s7, $s7, 0xeb8
  addiu $fp, %lo(ptrFirstFontTableLarge) # addiu $fp, $fp, 0xeb4
  sw    $t1, 0x74($sp)
  sw    $t2, 0x70($sp)
.L7F013A80:
  lw    $t0, 0xcc($sp)
  li    $at, 2
  li    $s3, 38
  bne   $t0, $at, .L7F013AB0
   andi  $t3, $s6, 1
  blez  $s6, .L7F013AA4
   li    $s5, 350
  b     .L7F013AE0
   li    $s2, 170
.L7F013AA4:
  move  $v1, $zero
  b     .L7F013AE0
   addiu $s2, $v1, 0x1e
.L7F013AB0:
  slti  $at, $s6, 2
  bnez  $at, .L7F013AC4
   li    $s5, 175
  b     .L7F013AC8
   li    $v1, 140
.L7F013AC4:
  move  $v1, $zero
.L7F013AC8:
  beqz  $t3, .L7F013AD8
   addiu $s2, $v1, 0x1e
  b     .L7F013ADC
   li    $v1, 175
.L7F013AD8:
  move  $v1, $zero
.L7F013ADC:
  addiu $s3, $v1, 0x26
.L7F013AE0:
  addiu $t4, $s3, 6
  mtc1  $t4, $f4
  addiu $t1, $s2, 5
  mtc1  $t1, $f16
  cvt.s.w $f6, $f4
  lui   $at, 0xed00
  addiu $s1, $v0, 8
  cvt.s.w $f18, $f16
  mul.s $f8, $f6, $f20
  trunc.w.s $f10, $f8
  mul.s $f4, $f18, $f20
  mfc1  $t6, $f10
  nop   
  andi  $t7, $t6, 0xfff
  trunc.w.s $f6, $f4
  sll   $t8, $t7, 0xc
  addu  $t6, $s3, $s5
  addiu $t7, $t6, -6
  mfc1  $t3, $f6
  mtc1  $t7, $f8
  or    $t9, $t8, $at
  andi  $t4, $t3, 0xfff
  or    $t5, $t9, $t4
  addiu $t9, $s2, 0x87
  cvt.s.w $f10, $f8
  mtc1  $t9, $f4
  sw    $t5, ($v0)
  cvt.s.w $f6, $f4
  mul.s $f16, $f10, $f20
  nop   
  mul.s $f8, $f6, $f20
  trunc.w.s $f18, $f16
  trunc.w.s $f10, $f8
  mfc1  $t1, $f18
  mfc1  $t5, $f10
  andi  $t2, $t1, 0xfff
  sll   $t3, $t2, 0xc
  andi  $t6, $t5, 0xfff
  or    $t7, $t3, $t6
  sw    $t7, 4($v0)
  lw    $t8, 0x74($sp)
  lw    $t1, ($t8)
  bnez  $t1, .L7F013C48
   nop   
  jal   get_textptr_for_textID
   li    $a0, 40221
  lw    $t2, ($fp)
  move  $s4, $v0
  addiu $a0, $sp, 0xa4
  addiu $a1, $sp, 0xa0
  move  $a2, $v0
  lw    $a3, ($s7)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t2, 0x10($sp)
  lw    $t7, 0xa4($sp)
  lw    $t5, 0xa0($sp)
  sra   $t9, $s5, 1
  sra   $t8, $t7, 1
  addu  $t4, $t9, $s3
  subu  $t1, $s2, $t8
  sra   $t3, $t5, 1
  subu  $t6, $t4, $t3
  addiu $t2, $t1, 0x37
  sw    $t6, 0x9c($sp)
  sw    $t2, 0x98($sp)
  jal   microcode_constructor
   move  $a0, $s1
  jal   get_video2_settings_txtClipW
   move  $s1, $v0
  sll   $s0, $v0, 0x10
  sra   $t9, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t9
  lw    $t5, ($s7)
  lw    $t4, ($fp)
  li    $t3, 255
  sw    $t3, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0x9c
  addiu $a2, $sp, 0x98
  move  $a3, $s4
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t5, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t4, 0x14($sp)
  move  $s1, $v0
.L7F013C48:
  lw    $t6, 0x70($sp)
  lui   $a0, %hi(MP_controller_configuration_table)
  sra   $t1, $s5, 1
  lw    $t7, ($t6)
  addu  $s0, $t1, $s3
  addiu $s4, $s2, 0x46
  sll   $t8, $t7, 2
  addu  $a0, $a0, $t8
  jal   get_textptr_for_textID
   lhu   $a0, %lo(MP_controller_configuration_table)($a0)
  lw    $t2, ($fp)
  move  $s2, $v0
  addiu $a0, $sp, 0x90
  addiu $a1, $sp, 0x8c
  move  $a2, $v0
  lw    $a3, ($s7)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t2, 0x10($sp)
  lw    $t3, 0x90($sp)
  lw    $t9, 0x8c($sp)
  move  $a0, $s1
  sra   $t6, $t3, 1
  subu  $t7, $s4, $t6
  sra   $t5, $t9, 1
  subu  $t4, $s0, $t5
  addiu $t8, $t7, 0xf
  sw    $t4, 0x88($sp)
  jal   microcode_constructor
   sw    $t8, 0x84($sp)
  jal   get_video2_settings_txtClipW
   move  $s1, $v0
  sll   $s0, $v0, 0x10
  sra   $t1, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t1
  lw    $t2, ($s7)
  lw    $t9, ($fp)
  li    $t5, 255
  sw    $t5, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0x88
  addiu $a2, $sp, 0x84
  move  $a3, $s2
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t2, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t9, 0x14($sp)
  lw    $t4, 0x74($sp)
  lw    $t6, 0x70($sp)
  lw    $t8, 0xcc($sp)
  addiu $s6, $s6, 1
  addiu $t3, $t4, 4
  addiu $t7, $t6, 4
  sw    $t7, 0x70($sp)
  sw    $t3, 0x74($sp)
  bne   $s6, $t8, .L7F013A80
   move  $s1, $v0
.L7F013D3C:
  jal   combiner_bayer_lod_perspective
   move  $a0, $s1
  lw    $ra, 0x64($sp)
  ldc1  $f20, 0x38($sp)
  lw    $s0, 0x40($sp)
  lw    $s1, 0x44($sp)
  lw    $s2, 0x48($sp)
  lw    $s3, 0x4c($sp)
  lw    $s4, 0x50($sp)
  lw    $s5, 0x54($sp)
  lw    $s6, 0x58($sp)
  lw    $s7, 0x5c($sp)
  lw    $fp, 0x60($sp)
  jr    $ra
   addiu $sp, $sp, 0xd0
");

void init_menu12_mpstage(void) {
  tab_1_selected = false;
  tab_2_selected = false;
  tab_3_selected = false;
  tab_3_highlight = false;
  tab_2_highlight = false;
  tab_1_highlight = false;
  current_mp_stage_highlighted = MP_STAGE_RANDOM;
  load_walletbond();
}

void update_menu12_mpstage(void) {}

asm(R"
.late_rodata
glabel D_80051AA0
.word 0x3FAAAAAB /*1.3333334;*/
glabel D_80051AA4
.word 0x461C4000 /*10000.0;*/

.text
glabel interface_menu12_mpstage
  addiu $sp, $sp, -0x20
  li    $at, 0x42700000 # 60.000000
  sw    $ra, 0x1c($sp)
  mtc1  $at, $f12
  jal   setvideo_far
   sw    $s0, 0x18($sp)
  lui   $at, %hi(D_80051AA0)
  jal   video_related_21
   lwc1  $f12, %lo(D_80051AA0)($at)
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f12
  lui   $at, %hi(D_80051AA4)
  jal   set_page_height
   lwc1  $f14, %lo(D_80051AA4)($at)
  jal   set_video2_settings_offset_24
   move  $a0, $zero
  move  $a0, $zero
  jal   get_controller_buttons_held
   li    $a1, 45056
  bnez  $v0, .L7F013F18
   lui   $at, %hi(tab_3_highlight)
  sw    $zero, %lo(tab_3_highlight)($at)
  lui   $at, %hi(tab_2_highlight)
  sw    $zero, %lo(tab_2_highlight)($at)
  lui   $at, %hi(tab_1_highlight)
  jal   isontab3
   sw    $zero, %lo(tab_1_highlight)($at)
  beqz  $v0, .L7F013E58
   lui   $at, %hi(cursor_v_pos)
  li    $t6, 1
  lui   $at, %hi(tab_3_highlight)
  b     .L7F013F18
   sw    $t6, %lo(tab_3_highlight)($at)
.L7F013E58:
  lwc1  $f4, %lo(cursor_v_pos)($at)
  lui   $s0, %hi(current_mp_stage_highlighted)
  addiu $s0, %lo(current_mp_stage_highlighted) # addiu $s0, $s0, -0x6884
  trunc.w.s $f6, $f4
  mfc1  $v0, $f6
  nop   
  slti  $at, $v0, 0xf0
  bnezl $at, .L7F013E88
   slti  $at, $v0, 0xaa
  b     .L7F013E98
   li    $v1, 2
  slti  $at, $v0, 0xaa
.L7F013E88:
  bnez  $at, .L7F013E98
   move  $v1, $zero
  b     .L7F013E98
   li    $v1, 1
.L7F013E98:
  lui   $at, %hi(cursor_h_pos)
  lwc1  $f8, %lo(cursor_h_pos)($at)
  sll   $t9, $v1, 2
  trunc.w.s $f10, $f8
  mfc1  $v0, $f10
  nop   
  slti  $at, $v0, 0x124
  bnezl $at, .L7F013EC8
   slti  $at, $v0, 0xcf
  b     .L7F013EEC
   li    $v0, 3
  slti  $at, $v0, 0xcf
.L7F013EC8:
  bnezl $at, .L7F013EDC
   slti  $at, $v0, 0x7a
  b     .L7F013EEC
   li    $v0, 2
  slti  $at, $v0, 0x7a
.L7F013EDC:
  bnez  $at, .L7F013EEC
   move  $v0, $zero
  b     .L7F013EEC
   li    $v0, 1
.L7F013EEC:
  addu  $a0, $t9, $v0
  jal   check_if_mp_stage_unlocked
   sw    $a0, ($s0)
  bnez  $v0, .L7F013F18
   nop   
  lw    $t1, ($s0)
.L7F013F04:
  addiu $a0, $t1, -1
  jal   check_if_mp_stage_unlocked
   sw    $a0, ($s0)
  beql  $v0, $zero, .L7F013F04
   lw    $t1, ($s0)
.L7F013F18:
  lui   $s0, %hi(current_mp_stage_highlighted)
  addiu $s0, %lo(current_mp_stage_highlighted) # addiu $s0, $s0, -0x6884
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 45056
  beqz  $v0, .L7F013F84
   li    $v1, 1
  lui   $t3, %hi(tab_3_highlight) 
  lw    $t3, %lo(tab_3_highlight)($t3)
  lui   $a0, %hi(ptr_sfx_buf)
  li    $a1, 199
  beqz  $t3, .L7F013F58
   move  $a2, $zero
  lui   $at, %hi(tab_3_selected)
  b     .L7F013F74
   sw    $v1, %lo(tab_3_selected)($at)
.L7F013F58:
  lw    $v0, ($s0)
  lui   $at, %hi(tab_2_selected)
  bltz  $v0, .L7F013F74
   nop   
  sw    $v1, %lo(tab_2_selected)($at)
  lui   $at, %hi(MP_stage_selected)
  sw    $v0, %lo(MP_stage_selected)($at)
.L7F013F74:
  jal   play_sfx_a1
   lw    $a0, %lo(ptr_sfx_buf)($a0)
  b     .L7F013FB4
   nop   
.L7F013F84:
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 16384
  beqz  $v0, .L7F013FB4
   li    $v1, 1
  lui   $at, %hi(tab_3_selected)
  lui   $a0, %hi(ptr_sfx_buf)
  sw    $v1, %lo(tab_3_selected)($at)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 199
  jal   play_sfx_a1
   move  $a2, $zero
.L7F013FB4:
  lui   $s0, %hi(ptr_folder_object_instance)
  addiu $s0, %lo(ptr_folder_object_instance) # addiu $s0, $s0, -0x56a4
  jal   disable_all_switches
   lw    $a0, ($s0)
  lw    $a0, ($s0)
  move  $a1, $zero
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lw    $a0, ($s0)
  li    $a1, 42
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lw    $a0, ($s0)
  li    $a1, 3
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  jal   menu_control_stick_tracking
   nop   
  lui   $t4, %hi(tab_2_selected) 
  lw    $t4, %lo(tab_2_selected)($t4)
  li    $a0, 14
  lui   $t5, %hi(tab_3_selected) 
  beqz  $t4, .L7F014024
   nop   
  jal   set_menu_to_mode
   move  $a1, $zero
  b     .L7F014040
   lw    $ra, 0x1c($sp)
.L7F014024:
  lw    $t5, %lo(tab_3_selected)($t5)
  li    $a0, 14
  beql  $t5, $zero, .L7F014040
   lw    $ra, 0x1c($sp)
  jal   set_menu_to_mode
   move  $a1, $zero
  lw    $ra, 0x1c($sp)
.L7F014040:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel constructor_menu12_mpstage
  addiu $sp, $sp, -0x138
  sw    $ra, 0x74($sp)
  sw    $fp, 0x70($sp)
  sw    $s7, 0x6c($sp)
  sw    $s6, 0x68($sp)
  sw    $s5, 0x64($sp)
  sw    $s4, 0x60($sp)
  sw    $s3, 0x5c($sp)
  sw    $s2, 0x58($sp)
  sw    $s1, 0x54($sp)
  sw    $s0, 0x50($sp)
  sdc1  $f22, 0x48($sp)
  sdc1  $f20, 0x40($sp)
  sw    $a0, 0x138($sp)
  move  $a1, $zero
  move  $a2, $zero
  jal   set_setfillcolor
   move  $a3, $zero
  sw    $v0, 0x138($sp)
  jal   insert_generic_fillrect
   move  $a0, $v0
  sw    $v0, 0x138($sp)
  jal   sub_GAME_7F00D5E8
   move  $a0, $v0
  sw    $v0, 0x138($sp)
  jal   microcode_constructor
   move  $a0, $v0
  lui   $s2, (0x101010FF >> 16) # lui $s2, 0x1010
  sw    $v0, 0x138($sp)
  ori   $s2, (0x101010FF & 0xFFFF) # ori $s2, $s2, 0x10ff
  li    $s1, 108
  li    $s0, 160
  li    $s3, 370
.L7F0140D4:
  lw    $a0, 0x138($sp)
  li    $a1, 37
  move  $a2, $s1
  li    $a3, 389
  sw    $s0, 0x10($sp)
  jal   microcode_constructor_related_to_menus
   sw    $s2, 0x14($sp)
  addiu $s0, $s0, 0x46
  addiu $s1, $s1, 0x46
  bne   $s0, $s3, .L7F0140D4
   sw    $v0, 0x138($sp)
  jal   combiner_bayer_lod_perspective
   move  $a0, $v0
  addiu $t6, $v0, 8
  sw    $t6, 0x138($sp)
  lui   $t7, (0xBA000C02 >> 16) # lui $t7, 0xba00
  ori   $t7, (0xBA000C02 & 0xFFFF) # ori $t7, $t7, 0xc02
  sw    $t7, ($v0)
  sw    $zero, 4($v0)
  lui   $s0, %hi(mainfolderimages)
  lw    $s0, %lo(mainfolderimages)($s0)
  addiu $s3, $sp, 0x138
  li    $t8, 2
  addiu $s0, $s0, 0x3c
  move  $a1, $s0
  sw    $t8, 0x10($sp)
  move  $a0, $s3
  li    $a2, 1
  jal   likely_generate_DL_for_image_declaration
   move  $a3, $zero
  li    $at, 0x43300000 # 176.000000
  mtc1  $at, $f2
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f12
  li    $at, 0x42140000 # 37.000000
  mtc1  $at, $f4
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f8
  add.s $f6, $f2, $f4
  li    $at, 0x428C0000 # 70.000000
  mtc1  $at, $f22
  add.s $f0, $f12, $f8
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f20
  swc1  $f6, 0x100($sp)
  swc1  $f0, 0x104($sp)
  move  $s1, $zero
  addiu $s4, $sp, 0xf8
  addiu $s2, $sp, 0x100
  swc1  $f2, 0xf8($sp)
  swc1  $f12, 0xfc($sp)
.L7F0141A0:
  li    $t9, 18
  li    $t1, 1
  li    $t2, 107
  li    $t3, 103
  li    $t4, 83
  li    $t5, 255
  sw    $t5, 0x2c($sp)
  sw    $t4, 0x28($sp)
  sw    $t3, 0x24($sp)
  sw    $t2, 0x20($sp)
  sw    $t1, 0x1c($sp)
  sw    $t9, 0x10($sp)
  sw    $zero, 0x14($sp)
  sw    $zero, 0x18($sp)
  lbu   $t6, 6($s0)
  sw    $zero, 0x34($sp)
  move  $a0, $s3
  slt   $t7, $zero, $t6
  sw    $t7, 0x30($sp)
  move  $a1, $s2
  move  $a2, $s4
  jal   display_image_at_on_screen_coord
   li    $a3, 752
  lwc1  $f10, 0x104($sp)
  li    $t8, 18
  li    $t9, 1
  add.s $f16, $f10, $f20
  li    $t1, 107
  li    $t2, 103
  li    $t3, 83
  li    $t4, 255
  swc1  $f16, 0x104($sp)
  sw    $t4, 0x2c($sp)
  sw    $t3, 0x28($sp)
  sw    $t2, 0x24($sp)
  sw    $t1, 0x20($sp)
  sw    $t9, 0x1c($sp)
  sw    $t8, 0x10($sp)
  sw    $zero, 0x14($sp)
  sw    $zero, 0x18($sp)
  lbu   $t5, 6($s0)
  sw    $zero, 0x34($sp)
  move  $a0, $s3
  slt   $t6, $zero, $t5
  sw    $t6, 0x30($sp)
  move  $a1, $s2
  move  $a2, $s4
  jal   display_image_at_on_screen_coord
   li    $a3, 752
  lwc1  $f0, 0x104($sp)
  addiu $s1, $s1, 1
  li    $at, 3
  sub.s $f0, $f0, $f20
  add.s $f0, $f0, $f22
  bne   $s1, $at, .L7F0141A0
   swc1  $f0, 0x104($sp)
  li    $at, 0x42080000 # 34.000000
  mtc1  $at, $f18
  li    $at, 0x41B00000 # 22.000000
  mtc1  $at, $f0
  li    $at, 0x42D80000 # 108.000000
  mtc1  $at, $f4
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f8
  add.s $f6, $f0, $f4
  li    $at, 0x42AA0000 # 85.000000
  lui   $s6, %hi(multi_stage_setups)
  mtc1  $at, $f20
  add.s $f10, $f6, $f8
  move  $s1, $zero
  addiu $s6, %lo(multi_stage_setups) # addiu $s6, $s6, -0x4f8c
  sw    $zero, 0xb4($sp)
  swc1  $f10, 0xdc($sp)
  li    $fp, 12
  li    $s7, 24
  addiu $s5, $sp, 0xd0
  addiu $s4, $sp, 0xd8
  swc1  $f18, 0xd0($sp)
  swc1  $f0, 0xd4($sp)
.L7F0142DC:
  li    $at, 0x42AC0000 # 86.000000
  mtc1  $at, $f16
  move  $s2, $zero
  swc1  $f16, 0xd8($sp)
.L7F0142EC:
  slti  $at, $s1, 0xc
  beql  $at, $zero, .L7F0144DC
   lwc1  $f18, 0xd8($sp)
  multu $s1, $s7
  lui   $t2, %hi(mpstageselimages) 
  lw    $t2, %lo(mpstageselimages)($t2)
  li    $t3, 2
  move  $a0, $s3
  li    $a2, 1
  move  $a3, $zero
  mflo  $t7
  addu  $t8, $s6, $t7
  lw    $t9, 4($t8)
  sw    $t3, 0x10($sp)
  multu $t9, $fp
  mflo  $t1
  addu  $s0, $t1, $t2
  jal   likely_generate_DL_for_image_declaration
   move  $a1, $s0
  lui   $t4, %hi(current_mp_stage_highlighted) 
  lw    $t4, %lo(current_mp_stage_highlighted)($t4)
  lw    $t5, 0x138($sp)
  lui   $t7, (0xBA001402 >> 16) # lui $t7, 0xba00
  bne   $s1, $t4, .L7F01440C
   addiu $t6, $t5, 8
  sw    $t6, 0x138($sp)
  ori   $t7, (0xBA001402 & 0xFFFF) # ori $t7, $t7, 0x1402
  lui   $t8, 0x10
  sw    $t8, 4($t5)
  sw    $t7, ($t5)
  lw    $t9, 0x138($sp)
  lui   $t2, 0xf800
  li    $t3, -246
  addiu $t1, $t9, 8
  sw    $t1, 0x138($sp)
  sw    $t3, 4($t9)
  sw    $t2, ($t9)
  lw    $t4, 0x138($sp)
  lui   $t7, (0xC4112048 >> 16) # lui $t7, 0xc411
  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
  addiu $t5, $t4, 8
  sw    $t5, 0x138($sp)
  ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
  ori   $t7, (0xC4112048 & 0xFFFF) # ori $t7, $t7, 0x2048
  sw    $t7, 4($t4)
  sw    $t6, ($t4)
  li    $t4, 255
  li    $t2, 255
  li    $t9, 1
  li    $t3, 255
  li    $t1, 255
  li    $t8, 44
  sw    $t8, 0x10($sp)
  sw    $t1, 0x20($sp)
  sw    $t3, 0x28($sp)
  sw    $t9, 0x1c($sp)
  sw    $t2, 0x24($sp)
  sw    $t4, 0x2c($sp)
  sw    $zero, 0x18($sp)
  sw    $zero, 0x14($sp)
  lbu   $t5, 6($s0)
  li    $t7, 1
  sw    $t7, 0x34($sp)
  slt   $t6, $zero, $t5
  sw    $t6, 0x30($sp)
  move  $a0, $s3
  move  $a1, $s4
  move  $a2, $s5
  jal   display_image_at_on_screen_coord
   li    $a3, 68
  b     .L7F0144DC
   lwc1  $f18, 0xd8($sp)
.L7F01440C:
  jal   check_if_mp_stage_unlocked
   move  $a0, $s1
  beqz  $v0, .L7F014480
   move  $a0, $s3
  li    $t8, 44
  li    $t9, 1
  li    $t1, 110
  li    $t2, 110
  li    $t3, 110
  li    $t4, 255
  sw    $t4, 0x2c($sp)
  sw    $t3, 0x28($sp)
  sw    $t2, 0x24($sp)
  sw    $t1, 0x20($sp)
  sw    $t9, 0x1c($sp)
  sw    $t8, 0x10($sp)
  sw    $zero, 0x14($sp)
  sw    $zero, 0x18($sp)
  lbu   $t5, 6($s0)
  sw    $zero, 0x34($sp)
  move  $a0, $s3
  slt   $t6, $zero, $t5
  sw    $t6, 0x30($sp)
  move  $a1, $s4
  move  $a2, $s5
  jal   display_image_at_on_screen_coord
   li    $a3, 68
  b     .L7F0144DC
   lwc1  $f18, 0xd8($sp)
.L7F014480:
  li    $t7, 44
  li    $t8, 1
  li    $t9, 15
  li    $t1, 15
  li    $t2, 15
  li    $t3, 255
  sw    $t3, 0x2c($sp)
  sw    $t2, 0x28($sp)
  sw    $t1, 0x24($sp)
  sw    $t9, 0x20($sp)
  sw    $t8, 0x1c($sp)
  sw    $t7, 0x10($sp)
  sw    $zero, 0x14($sp)
  sw    $zero, 0x18($sp)
  lbu   $t4, 6($s0)
  sw    $zero, 0x34($sp)
  move  $a1, $s4
  slt   $t5, $zero, $t4
  sw    $t5, 0x30($sp)
  move  $a2, $s5
  jal   display_image_at_on_screen_coord
   li    $a3, 68
  lwc1  $f18, 0xd8($sp)
.L7F0144DC:
  addiu $s2, $s2, 1
  li    $at, 4
  add.s $f4, $f18, $f20
  addiu $s1, $s1, 1
  bne   $s2, $at, .L7F0142EC
   swc1  $f4, 0xd8($sp)
  lwc1  $f6, 0xdc($sp)
  lw    $t6, 0xb4($sp)
  li    $at, 3
  add.s $f8, $f6, $f22
  addiu $t7, $t6, 1
  sw    $t7, 0xb4($sp)
  bne   $t7, $at, .L7F0142DC
   swc1  $f8, 0xdc($sp)
  jal   microcode_constructor
   lw    $a0, 0x138($sp)
  li    $t8, 151
  lui   $fp, %hi(ptrSecondFontTableSmall) 
  sw    $v0, 0x138($sp)
  move  $s5, $zero
  sw    $t8, 0x90($sp)
  addiu $fp, %lo(ptrSecondFontTableSmall) # addiu $fp, $fp, 0xeb0
  sw    $zero, 0x9c($sp)
.L7F014538:
  li    $s6, 86
  move  $s7, $zero
.L7F014540:
  slti  $at, $s5, 0xc
  beql  $at, $zero, .L7F0146D0
   addiu $s7, $s7, 1
  jal   check_if_mp_stage_unlocked
   move  $a0, $s5
  beqz  $v0, .L7F0146CC
   lui   $s2, (0x96969600 >> 16) # lui $s2, 0x9696
  lui   $t2, %hi(current_mp_stage_highlighted) 
  lw    $t2, %lo(current_mp_stage_highlighted)($t2)
  sll   $t9, $s5, 2
  subu  $t9, $t9, $s5
  lui   $t1, %hi(multi_stage_setups) 
  addiu $t1, %lo(multi_stage_setups) # addiu $t1, $t1, -0x4f8c
  sll   $t9, $t9, 3
  ori   $s2, (0x96969600 & 0xFFFF) # ori $s2, $s2, 0x9600
  bne   $s5, $t2, .L7F014588
   addu  $s3, $t9, $t1
  li    $s2, -256
.L7F014588:
  jal   get_textptr_for_textID
   lhu   $a0, 2($s3)
  lui   $t3, %hi(ptrFirstFontTableSmall) 
  lw    $t3, %lo(ptrFirstFontTableSmall)($t3)
  addiu $a0, $sp, 0x128
  addiu $a1, $sp, 0x124
  move  $a2, $v0
  lw    $a3, ($fp)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t3, 0x10($sp)
  lw    $v1, 0x128($sp)
  lw    $t4, 0x90($sp)
  lw    $t5, 0x124($sp)
  addiu $s4, $s6, -0x1f
  subu  $a2, $t4, $v1
  addu  $t6, $a2, $v1
  move  $a1, $s4
  sw    $t6, 0x10($sp)
  sw    $a2, 0x12c($sp)
  sw    $s4, 0x130($sp)
  lw    $a0, 0x138($sp)
  sw    $zero, 0x14($sp)
  jal   microcode_constructor_related_to_menus
   addu  $a3, $s4, $t5
  sw    $v0, 0x138($sp)
  jal   get_textptr_for_textID
   lhu   $a0, 2($s3)
  jal   get_video2_settings_txtClipW
   move  $s1, $v0
  sll   $s0, $v0, 0x10
  sra   $t7, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t7
  lui   $t9, %hi(ptrFirstFontTableSmall) 
  lw    $t9, %lo(ptrFirstFontTableSmall)($t9)
  lw    $t8, ($fp)
  ori   $t1, $s2, 0xff
  sw    $t1, 0x18($sp)
  lw    $a0, 0x138($sp)
  addiu $a1, $sp, 0x130
  addiu $a2, $sp, 0x12c
  move  $a3, $s1
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t9, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t8, 0x10($sp)
  lw    $v1, 0x128($sp)
  lw    $t2, 0x90($sp)
  sw    $v0, 0x138($sp)
  lhu   $a0, 2($s3)
  subu  $a2, $t2, $v1
  sw    $a2, 0x12c($sp)
  jal   get_textptr_for_textID
   sw    $s4, 0x130($sp)
  jal   get_video2_settings_txtClipW
   move  $s1, $v0
  sll   $s0, $v0, 0x10
  sra   $t3, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t3
  lui   $t5, %hi(ptrFirstFontTableSmall) 
  lw    $t5, %lo(ptrFirstFontTableSmall)($t5)
  lw    $t4, ($fp)
  ori   $t6, $s2, 0x64
  sw    $t6, 0x18($sp)
  lw    $a0, 0x138($sp)
  addiu $a1, $sp, 0x130
  addiu $a2, $sp, 0x12c
  move  $a3, $s1
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t5, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t4, 0x10($sp)
  sw    $v0, 0x138($sp)
.L7F0146CC:
  addiu $s7, $s7, 1
.L7F0146D0:
  li    $at, 4
  addiu $s6, $s6, 0x55
  bne   $s7, $at, .L7F014540
   addiu $s5, $s5, 1
  lw    $t9, 0x9c($sp)
  lw    $t7, 0x90($sp)
  li    $at, 3
  addiu $t1, $t9, 1
  addiu $t8, $t7, 0x46
  sw    $t1, 0x9c($sp)
  bne   $t1, $at, .L7F014538
   sw    $t8, 0x90($sp)
  jal   microcode_constructor
   lw    $a0, 0x138($sp)
  sw    $v0, 0x138($sp)
  jal   add_tab3_previous
   move  $a0, $v0
  sw    $v0, 0x138($sp)
  jal   load_draw_selected_icon_folder_select
   move  $a0, $v0
  lw    $ra, 0x74($sp)
  ldc1  $f20, 0x40($sp)
  ldc1  $f22, 0x48($sp)
  lw    $s0, 0x50($sp)
  lw    $s1, 0x54($sp)
  lw    $s2, 0x58($sp)
  lw    $s3, 0x5c($sp)
  lw    $s4, 0x60($sp)
  lw    $s5, 0x64($sp)
  lw    $s6, 0x68($sp)
  lw    $s7, 0x6c($sp)
  lw    $fp, 0x70($sp)
  jr    $ra
   addiu $sp, $sp, 0x138
");

MPSCENARIOS get_scenario(void) { return scenario; }

void init_menu13_mpscenariosel(void) {
  tab_1_selected = false;
  tab_2_selected = false;
  tab_3_selected = false;
  tab_3_highlight = false;
  tab_2_highlight = false;
  tab_1_highlight = false;
  load_walletbond();
}

void update_menu13_mpscenario(void) {}

asm(R"
.late_rodata
glabel D_80051AA8
.word 0x3FAAAAAB /*1.3333334;*/
glabel D_80051AAC
.word 0x461C4000 /*10000.0;*/

.text
glabel interface_menu13_mpscenario
  addiu $sp, $sp, -0x30
  li    $at, 0x42700000 # 60.000000
  sw    $ra, 0x24($sp)
  mtc1  $at, $f12
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  jal   setvideo_far
   sw    $zero, 0x2c($sp)
  lui   $at, %hi(D_80051AA8)
  jal   video_related_21
   lwc1  $f12, %lo(D_80051AA8)($at)
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f12
  lui   $at, %hi(D_80051AAC)
  jal   set_page_height
   lwc1  $f14, %lo(D_80051AAC)($at)
  jal   set_video2_settings_offset_24
   move  $a0, $zero
  move  $a0, $zero
  jal   get_controller_buttons_held
   li    $a1, 40960
  bnez  $v0, .L7F0148D4
   lui   $at, %hi(tab_3_highlight)
  sw    $zero, %lo(tab_3_highlight)($at)
  lui   $at, %hi(tab_2_highlight)
  sw    $zero, %lo(tab_2_highlight)($at)
  lui   $at, %hi(tab_1_highlight)
  jal   isontab3
   sw    $zero, %lo(tab_1_highlight)($at)
  beqz  $v0, .L7F014850
   li    $t7, 1
  li    $t6, 1
  lui   $at, %hi(tab_3_highlight)
  sw    $t6, %lo(tab_3_highlight)($at)
  lui   $at, %hi(dword_CODE_bss_80069780)
  b     .L7F0148D4
   sw    $zero, %lo(dword_CODE_bss_80069780)($at)
.L7F014850:
  lui   $at, %hi(dword_CODE_bss_80069780)
  sw    $t7, %lo(dword_CODE_bss_80069780)($at)
  li    $s1, 7
  li    $s2, 285
.L7F014860:
  lui   $at, %hi(cursor_v_pos)
  lwc1  $f4, %lo(cursor_v_pos)($at)
  lui   $t1, %hi(mp_player_counts) 
  addiu $t1, %lo(mp_player_counts) # addiu $t1, $t1, -0x4fac
  trunc.w.s $f6, $f4
  sll   $t0, $s1, 2
  mfc1  $t9, $f6
  nop   
  slt   $at, $t9, $s2
  bnezl $at, .L7F0148CC
   addiu $s1, $s1, -1
  jal   get_selected_num_players
   addu  $s0, $t0, $t1
  lbu   $t2, 2($s0)
  slt   $at, $v0, $t2
  bnezl $at, .L7F0148CC
   addiu $s1, $s1, -1
  jal   get_selected_num_players
   nop   
  lbu   $t3, 3($s0)
  slt   $at, $t3, $v0
  bnez  $at, .L7F0148C8
   addiu $t4, $s1, 1
  lui   $at, %hi(dword_CODE_bss_80069780)
  b     .L7F0148D4
   sw    $t4, %lo(dword_CODE_bss_80069780)($at)
.L7F0148C8:
  addiu $s1, $s1, -1
.L7F0148CC:
  bnez  $s1, .L7F014860
   addiu $s2, $s2, -0x16
.L7F0148D4:
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 45056
  beqz  $v0, .L7F014970
   move  $a0, $zero
  lui   $t5, %hi(tab_3_highlight) 
  lw    $t5, %lo(tab_3_highlight)($t5)
  li    $t6, 1
  lui   $at, %hi(tab_3_selected)
  beqz  $t5, .L7F014908
   lui   $a0, %hi(dword_CODE_bss_80069780)
  b     .L7F014954
   sw    $t6, %lo(tab_3_selected)($at)
.L7F014908:
  lw    $a0, %lo(dword_CODE_bss_80069780)($a0)
  li    $at, 5
  addiu $a0, $a0, -1
  beq   $a0, $at, .L7F01492C
   li    $at, 6
  beq   $a0, $at, .L7F01492C
   li    $at, 7
  bne   $a0, $at, .L7F014940
   nop   
.L7F01492C:
  jal   reset_mp_options_for_scenario
   nop   
  li    $t7, 1
  b     .L7F014954
   sw    $t7, 0x2c($sp)
.L7F014940:
  jal   reset_mp_options_for_scenario
   nop   
  li    $t8, 1
  lui   $at, %hi(tab_3_selected)
  sw    $t8, %lo(tab_3_selected)($at)
.L7F014954:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 199
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F01499C
   nop   
.L7F014970:
  jal   get_controller_buttons_pressed
   li    $a1, 16384
  beqz  $v0, .L7F01499C
   li    $t9, 1
  lui   $at, %hi(tab_3_selected)
  lui   $a0, %hi(ptr_sfx_buf)
  sw    $t9, %lo(tab_3_selected)($at)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 199
  jal   play_sfx_a1
   move  $a2, $zero
.L7F01499C:
  lui   $s0, %hi(ptr_folder_object_instance)
  addiu $s0, %lo(ptr_folder_object_instance) # addiu $s0, $s0, -0x56a4
  jal   disable_all_switches
   lw    $a0, ($s0)
  lw    $a0, ($s0)
  move  $a1, $zero
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lw    $a0, ($s0)
  li    $a1, 1
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lw    $a0, ($s0)
  li    $a1, 3
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lw    $a0, ($s0)
  li    $a1, 6
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  jal   menu_control_stick_tracking
   nop   
  lw    $t0, 0x2c($sp)
  li    $a0, 20
  lui   $t1, %hi(tab_3_selected) 
  beqz  $t0, .L7F014A18
   nop   
  jal   set_menu_to_mode
   move  $a1, $zero
  b     .L7F014A34
   lw    $ra, 0x24($sp)
.L7F014A18:
  lw    $t1, %lo(tab_3_selected)($t1)
  li    $a0, 14
  beql  $t1, $zero, .L7F014A34
   lw    $ra, 0x24($sp)
  jal   set_menu_to_mode
   move  $a1, $zero
  lw    $ra, 0x24($sp)
.L7F014A34:
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x30
");

asm(R"
glabel constructor_menu13_mpscenario
  addiu $sp, $sp, -0x98
  sw    $ra, 0x5c($sp)
  sw    $fp, 0x58($sp)
  sw    $s7, 0x54($sp)
  sw    $s6, 0x50($sp)
  sw    $s5, 0x4c($sp)
  sw    $s4, 0x48($sp)
  sw    $s3, 0x44($sp)
  sw    $s2, 0x40($sp)
  sw    $s1, 0x3c($sp)
  sw    $s0, 0x38($sp)
  move  $a1, $zero
  move  $a2, $zero
  jal   set_setfillcolor
   move  $a3, $zero
  jal   insert_generic_fillrect
   move  $a0, $v0
  jal   sub_GAME_7F00D5E8
   move  $a0, $v0
  jal   microcode_constructor
   move  $a0, $v0
  move  $s4, $v0
  jal   get_textptr_for_textID
   li    $a0, 40023
  li    $t6, 55
  li    $v1, 102
  move  $s6, $v0
  sw    $t6, 0x88($sp)
  jal   get_video2_settings_txtClipW
   sw    $v1, 0x84($sp)
  sll   $s0, $v0, 0x10
  sra   $t7, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t7
  lui   $s7, %hi(ptrSecondFontTableLarge) 
  lui   $fp, %hi(ptrFirstFontTableLarge) 
  addiu $fp, %lo(ptrFirstFontTableLarge) # addiu $fp, $fp, 0xeb4
  addiu $s7, %lo(ptrSecondFontTableLarge) # addiu $s7, $s7, 0xeb8
  lw    $t8, ($s7)
  lw    $t9, ($fp)
  li    $t0, 255
  sw    $t0, 0x18($sp)
  move  $a0, $s4
  addiu $a1, $sp, 0x88
  addiu $a2, $sp, 0x84
  move  $a3, $s6
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t8, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t9, 0x14($sp)
  lui   $s1, %hi(mp_player_counts)
  move  $s4, $v0
  addiu $s1, %lo(mp_player_counts) # addiu $s1, $s1, -0x4fac
  move  $s2, $zero
  li    $s5, 131
.L7F014B30:
  jal   get_selected_num_players
   li    $s3, 255
  lbu   $t1, 3($s1)
  slt   $at, $t1, $v0
  bnezl $at, .L7F014B64
   li    $s3, 112
  jal   get_selected_num_players
   nop   
  lbu   $t2, 2($s1)
  slt   $at, $v0, $t2
  beqz  $at, .L7F014B64
   nop   
  li    $s3, 112
.L7F014B64:
  jal   get_textptr_for_textID
   lhu   $a0, ($s1)
  lw    $t3, ($fp)
  move  $s6, $v0
  addiu $a0, $sp, 0x7c
  addiu $a1, $sp, 0x78
  move  $a2, $v0
  lw    $a3, ($s7)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t3, 0x10($sp)
  lui   $t6, %hi(dword_CODE_bss_80069780) 
  lw    $t6, %lo(dword_CODE_bss_80069780)($t6)
  li    $t4, 57
  addiu $t5, $s2, 1
  sw    $t4, 0x88($sp)
  move  $v1, $s5
  bne   $t5, $t6, .L7F014BE0
   sw    $s5, 0x84($sp)
  lw    $a3, 0x78($sp)
  addiu $t7, $v1, 0xe
  li    $t8, 50
  sw    $t8, 0x14($sp)
  sw    $t7, 0x10($sp)
  move  $a0, $s4
  li    $a1, 55
  addiu $a2, $v1, -1
  sw    $v1, 0x84($sp)
  jal   microcode_constructor_related_to_menus
   addiu $a3, $a3, 0x3c
  move  $s4, $v0
.L7F014BE0:
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s0, $v0, 0x10
  sra   $t9, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t9
  lw    $t0, ($s7)
  lw    $t1, ($fp)
  move  $a0, $s4
  addiu $a1, $sp, 0x88
  addiu $a2, $sp, 0x84
  move  $a3, $s6
  sw    $s3, 0x18($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t0, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t1, 0x14($sp)
  addiu $s2, $s2, 1
  li    $at, 8
  addiu $s1, $s1, 4
  addiu $s5, $s5, 0x16
  bne   $s2, $at, .L7F014B30
   move  $s4, $v0
  jal   add_tab3_previous
   move  $a0, $v0
  jal   load_draw_selected_icon_folder_select
   move  $a0, $v0
  lw    $ra, 0x5c($sp)
  lw    $s0, 0x38($sp)
  lw    $s1, 0x3c($sp)
  lw    $s2, 0x40($sp)
  lw    $s3, 0x44($sp)
  lw    $s4, 0x48($sp)
  lw    $s5, 0x4c($sp)
  lw    $s6, 0x50($sp)
  lw    $s7, 0x54($sp)
  lw    $fp, 0x58($sp)
  jr    $ra
   addiu $sp, $sp, 0x98
");

asm(R"
glabel get_players_team_or_scenario_item_flag
  sll   $t6, $a0, 3
  subu  $t6, $t6, $a0
  sll   $t6, $t6, 4
  lui   $v0, %hi(player1_player_data+105)
  addu  $v0, $v0, $t6
  jr    $ra
   lbu   $v0, %lo(player1_player_data+105)($v0)
");

asm(R"
glabel set_players_team_or_scenario_item_flag
  sll   $t6, $a0, 3
  subu  $t6, $t6, $a0
  sll   $t6, $t6, 4
  lui   $at, %hi(player1_player_data+105)
  addu  $at, $at, $t6
  jr    $ra
   sb    $a1, %lo(player1_player_data+105)($at)
");

void init_menu14_mpteamsel(void) {
  tab_1_selected = false;
  tab_2_selected = false;
  tab_3_selected = false;
  tab_3_highlight = false;
  tab_2_highlight = false;
  tab_1_highlight = false;
  if (scenario == SCENARIO_2v1) {
    teamsize = 2;
  } else {
    teamsize = 3;
  }
  D_8002B560 = 0;
  load_walletbond();
}

void update_menu14_mpteams(void) {}

asm(R"
.late_rodata
glabel D_80051AB0
.word 0x3FAAAAAB /*1.3333334;*/
glabel D_80051AB4
.word 0x461C4000 /*10000.0;*/

.text
glabel interface_menu14_mpteams
  addiu $sp, $sp, -0x20
  li    $at, 0x42700000 # 60.000000
  sw    $ra, 0x1c($sp)
  mtc1  $at, $f12
  sw    $s1, 0x18($sp)
  jal   setvideo_far
   sw    $s0, 0x14($sp)
  lui   $at, %hi(D_80051AB0)
  jal   video_related_21
   lwc1  $f12, %lo(D_80051AB0)($at)
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f12
  lui   $at, %hi(D_80051AB4)
  jal   set_page_height
   lwc1  $f14, %lo(D_80051AB4)($at)
  jal   set_video2_settings_offset_24
   move  $a0, $zero
  lui   $v0, %hi(D_8002B560)
  addiu $v0, %lo(D_8002B560) # addiu $v0, $v0, -0x4aa0
  lw    $t6, ($v0)
  li    $at, 20
  move  $a0, $zero
  addiu $t7, $t6, 1
  div   $zero, $t7, $at
  mfhi  $t8
  sw    $t8, ($v0)
  jal   get_controller_buttons_pressed
   li    $a1, 257
  bnez  $v0, .L7F014DD0
   move  $a0, $zero
  li    $a1, -2
  jal   get_controller_3dstick_L_R
   li    $a2, 1
  blez  $v0, .L7F014E50
.L7F014DD0:
   lui   $t9, %hi(scenario) 
  lw    $t9, %lo(scenario)($t9)
  li    $at, 7
  lui   $s1, %hi(teamsize)
  bne   $t9, $at, .L7F014E20
   addiu $s1, %lo(teamsize) # addiu $s1, $s1, -0x6878
  lui   $s1, %hi(teamsize)
  addiu $s1, %lo(teamsize) # addiu $s1, $s1, -0x6878
  lw    $t0, ($s1)
  li    $t2, 1
  lui   $a0, %hi(ptr_sfx_buf)
  andi  $t1, $t0, 1
  bnez  $t1, .L7F01503C
   li    $a1, 199
  sw    $t2, ($s1)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F01503C
   nop   
.L7F014E20:
  lw    $v0, ($s1)
  lui   $a0, %hi(ptr_sfx_buf)
  li    $a1, 199
  andi  $t3, $v0, 1
  bnez  $t3, .L7F01503C
   addiu $t4, $v0, 1
  sw    $t4, ($s1)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F01503C
   nop   
.L7F014E50:
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 2056
  bnez  $v0, .L7F014E74
   move  $a0, $zero
  li    $a1, -2
  jal   get_controller_3dstick_U_D
   li    $a2, 1
  blez  $v0, .L7F014EF4
.L7F014E74:
   lui   $t5, %hi(scenario) 
  lw    $t5, %lo(scenario)($t5)
  li    $at, 5
  lui   $s1, %hi(teamsize)
  bne   $t5, $at, .L7F014EC4
   addiu $s1, %lo(teamsize) # addiu $s1, $s1, -0x6878
  lui   $s1, %hi(teamsize)
  addiu $s1, %lo(teamsize) # addiu $s1, $s1, -0x6878
  lw    $t6, ($s1)
  li    $t8, 1
  lui   $a0, %hi(ptr_sfx_buf)
  andi  $t7, $t6, 2
  beqz  $t7, .L7F01503C
   li    $a1, 199
  sw    $t8, ($s1)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F01503C
   nop   
.L7F014EC4:
  lw    $v0, ($s1)
  lui   $a0, %hi(ptr_sfx_buf)
  li    $a1, 199
  andi  $t9, $v0, 2
  beqz  $t9, .L7F01503C
   addiu $t0, $v0, -2
  sw    $t0, ($s1)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F01503C
   nop   
.L7F014EF4:
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 514
  bnez  $v0, .L7F014F1C
   move  $a0, $zero
  li    $a1, -2
  jal   get_controller_3dstick_L_R
   li    $a2, 1
  slti  $at, $v0, -1
  beqz  $at, .L7F014F9C
.L7F014F1C:
   lui   $t1, %hi(scenario) 
  lw    $t1, %lo(scenario)($t1)
  li    $at, 5
  lui   $s1, %hi(teamsize)
  bne   $t1, $at, .L7F014F6C
   addiu $s1, %lo(teamsize) # addiu $s1, $s1, -0x6878
  lui   $s1, %hi(teamsize)
  addiu $s1, %lo(teamsize) # addiu $s1, $s1, -0x6878
  lw    $t2, ($s1)
  li    $t4, 2
  lui   $a0, %hi(ptr_sfx_buf)
  andi  $t3, $t2, 1
  beqz  $t3, .L7F01503C
   li    $a1, 199
  sw    $t4, ($s1)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F01503C
   nop   
.L7F014F6C:
  lw    $v0, ($s1)
  lui   $a0, %hi(ptr_sfx_buf)
  li    $a1, 199
  andi  $t5, $v0, 1
  beqz  $t5, .L7F01503C
   addiu $t6, $v0, -1
  sw    $t6, ($s1)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F01503C
   nop   
.L7F014F9C:
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 1028
  bnez  $v0, .L7F014FC4
   move  $a0, $zero
  li    $a1, -2
  jal   get_controller_3dstick_U_D
   li    $a2, 1
  slti  $at, $v0, -1
  beqz  $at, .L7F01503C
.L7F014FC4:
   lui   $t7, %hi(scenario) 
  lw    $t7, %lo(scenario)($t7)
  li    $at, 7
  lui   $s1, %hi(teamsize)
  bne   $t7, $at, .L7F015014
   addiu $s1, %lo(teamsize) # addiu $s1, $s1, -0x6878
  lui   $s1, %hi(teamsize)
  addiu $s1, %lo(teamsize) # addiu $s1, $s1, -0x6878
  lw    $t8, ($s1)
  li    $t0, 2
  lui   $a0, %hi(ptr_sfx_buf)
  andi  $t9, $t8, 2
  bnez  $t9, .L7F01503C
   li    $a1, 199
  sw    $t0, ($s1)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F01503C
   nop   
.L7F015014:
  lw    $v0, ($s1)
  lui   $a0, %hi(ptr_sfx_buf)
  li    $a1, 199
  andi  $t1, $v0, 2
  bnez  $t1, .L7F01503C
   addiu $t2, $v0, 2
  sw    $t2, ($s1)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   move  $a2, $zero
.L7F01503C:
  lui   $s0, %hi(ptr_folder_object_instance)
  addiu $s0, %lo(ptr_folder_object_instance) # addiu $s0, $s0, -0x56a4
  lui   $s1, %hi(teamsize)
  addiu $s1, %lo(teamsize) # addiu $s1, $s1, -0x6878
  jal   disable_all_switches
   lw    $a0, ($s0)
  lw    $a0, ($s0)
  move  $a1, $zero
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lw    $a0, ($s0)
  li    $a1, 42
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  jal   menu_control_stick_tracking
   nop   
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 45056
  beqz  $v0, .L7F015124
   move  $s0, $zero
.L7F015090:
  lui   $t3, %hi(scenario) 
  lw    $t3, %lo(scenario)($t3)
  li    $at, 5
  bnel  $t3, $at, .L7F0150D8
   lw    $t5, ($s1)
  beqz  $s0, .L7F0150BC
   nop   
  lw    $t4, ($s1)
  li    $a1, 1
  bne   $s0, $t4, .L7F0150C4
   nop   
.L7F0150BC:
  b     .L7F0150C4
   move  $a1, $zero
.L7F0150C4:
  jal   set_players_team_or_scenario_item_flag
   move  $a0, $s0
  b     .L7F0150F8
   addiu $s0, $s0, 1
  lw    $t5, ($s1)
.L7F0150D8:
  li    $a1, 1
  beq   $s0, $t5, .L7F0150EC
   nop   
  b     .L7F0150EC
   move  $a1, $zero
.L7F0150EC:
  jal   set_players_team_or_scenario_item_flag
   move  $a0, $s0
  addiu $s0, $s0, 1
.L7F0150F8:
  li    $at, 4
  bne   $s0, $at, .L7F015090
   nop   
  li    $a0, 14
  jal   set_menu_to_mode
   move  $a1, $zero
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 199
  jal   play_sfx_a1
   move  $a2, $zero
.L7F015124:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x20
");

asm(R"
glabel constructor_menu14_mpteams
  addiu $sp, $sp, -0xd0
  sw    $ra, 0x64($sp)
  sw    $s5, 0x54($sp)
  move  $s5, $a0
  sw    $fp, 0x60($sp)
  sw    $s7, 0x5c($sp)
  sw    $s6, 0x58($sp)
  sw    $s4, 0x50($sp)
  sw    $s3, 0x4c($sp)
  sw    $s2, 0x48($sp)
  sw    $s1, 0x44($sp)
  sw    $s0, 0x40($sp)
  jal   get_selected_num_players
   sdc1  $f20, 0x38($sp)
  sw    $v0, 0xcc($sp)
  move  $a0, $s5
  move  $a1, $zero
  move  $a2, $zero
  jal   set_setfillcolor
   move  $a3, $zero
  jal   insert_generic_fillrect
   move  $a0, $v0
  jal   sub_GAME_7F00D5E8
   move  $a0, $v0
  jal   microcode_constructor
   move  $a0, $v0
  li    $t6, 171
  li    $t7, 144
  sw    $t7, 0x14($sp)
  sw    $t6, 0x10($sp)
  move  $a0, $v0
  li    $a1, 38
  li    $a2, 169
  jal   microcode_constructor_related_to_menus
   li    $a3, 388
  lw    $t8, 0xcc($sp)
  move  $s5, $v0
  move  $a0, $v0
  slti  $at, $t8, 3
  bnez  $at, .L7F0151FC
   li    $a1, 212
  li    $t9, 310
  li    $t0, 128
  sw    $t0, 0x14($sp)
  sw    $t9, 0x10($sp)
  li    $a2, 30
  jal   microcode_constructor_related_to_menus
   li    $a3, 214
  move  $s5, $v0
.L7F0151FC:
  lw    $t1, 0xcc($sp)
  move  $s4, $zero
  li    $at, 0x40800000 # 4.000000
  blez  $t1, .L7F0154D4
   lui   $s7, %hi(ptrSecondFontTableLarge) 
  lui   $fp, %hi(ptrFirstFontTableLarge) 
  mtc1  $at, $f20
  addiu $fp, %lo(ptrFirstFontTableLarge) # addiu $fp, $fp, 0xeb4
  addiu $s7, %lo(ptrSecondFontTableLarge) # addiu $s7, $s7, 0xeb8
  slti  $at, $s4, 2
.L7F015224:
  bnez  $at, .L7F015234
   andi  $t2, $s4, 1
  b     .L7F015238
   li    $v0, 140
.L7F015234:
  move  $v0, $zero
.L7F015238:
  beqz  $t2, .L7F015248
   addiu $s6, $v0, 0x1e
  b     .L7F01524C
   li    $v0, 175
.L7F015248:
  move  $v0, $zero
.L7F01524C:
  addiu $t3, $v0, 0x2c
  mtc1  $t3, $f4
  addiu $s0, $s6, 5
  mtc1  $s0, $f16
  cvt.s.w $f6, $f4
  addiu $t3, $v0, 0xcf
  addiu $t9, $s6, 0x87
  lui   $at, 0xed00
  move  $v1, $s5
  cvt.s.w $f18, $f16
  mul.s $f8, $f6, $f20
  addiu $s1, $v0, 0x7d
  sltiu $s2, $s4, 1
  addiu $s5, $s5, 8
  mul.s $f4, $f18, $f20
  trunc.w.s $f10, $f8
  mtc1  $t3, $f8
  trunc.w.s $f6, $f4
  mfc1  $t5, $f10
  mtc1  $t9, $f4
  cvt.s.w $f10, $f8
  mfc1  $t0, $f6
  andi  $t6, $t5, 0xfff
  sll   $t7, $t6, 0xc
  or    $t8, $t7, $at
  cvt.s.w $f6, $f4
  mul.s $f16, $f10, $f20
  andi  $t1, $t0, 0xfff
  or    $t2, $t8, $t1
  sw    $t2, ($v1)
  mul.s $f8, $f6, $f20
  trunc.w.s $f18, $f16
  trunc.w.s $f10, $f8
  mfc1  $t5, $f18
  mfc1  $t8, $f10
  andi  $t6, $t5, 0xfff
  sll   $t7, $t6, 0xc
  andi  $t1, $t8, 0xfff
  or    $t2, $t7, $t1
  sw    $t2, 4($v1)
  beqz  $s2, .L7F015388
   sw    $s1, 0xb4($sp)
  jal   get_textptr_for_textID
   li    $a0, 40024
  lw    $t3, ($fp)
  move  $s3, $v0
  addiu $a0, $sp, 0xa4
  addiu $a1, $sp, 0xa0
  move  $a2, $v0
  lw    $a3, ($s7)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t3, 0x10($sp)
  lw    $t4, 0xa0($sp)
  sw    $s0, 0x98($sp)
  sra   $t5, $t4, 1
  subu  $t6, $s1, $t5
  jal   get_video2_settings_txtClipW
   sw    $t6, 0x9c($sp)
  sll   $s0, $v0, 0x10
  sra   $t9, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t9
  lw    $t0, ($s7)
  lw    $t8, ($fp)
  li    $t7, 255
  sw    $t7, 0x18($sp)
  move  $a0, $s5
  addiu $a1, $sp, 0x9c
  addiu $a2, $sp, 0x98
  move  $a3, $s3
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t0, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t8, 0x14($sp)
  move  $s5, $v0
.L7F015388:
  lui   $t1, %hi(scenario) 
  lw    $t1, %lo(scenario)($t1)
  li    $at, 5
  lui   $t3, %hi(teamsize) 
  bne   $t1, $at, .L7F0153C0
   nop   
  bnez  $s2, .L7F0153B8
   move  $v0, $s2
  lui   $t2, %hi(teamsize) 
  lw    $t2, %lo(teamsize)($t2)
  xor   $v0, $s4, $t2
  sltiu $v0, $v0, 1
.L7F0153B8:
  b     .L7F0153CC
   move  $s0, $v0
.L7F0153C0:
  lw    $t3, %lo(teamsize)($t3)
  xor   $s0, $s4, $t3
  sltu  $s0, $zero, $s0
.L7F0153CC:
  beqz  $s0, .L7F0153E4
   nop   
  jal   get_textptr_for_textID
   li    $a0, 40025
  b     .L7F0153F0
   move  $s1, $v0
.L7F0153E4:
  jal   get_textptr_for_textID
   li    $a0, 40026
  move  $s1, $v0
.L7F0153F0:
  beqz  $s0, .L7F015404
   addiu $a0, $sp, 0x90
  lui   $s2, (0xFF0000FF >> 16) # lui $s2, 0xff00
  b     .L7F015408
   ori   $s2, (0xFF0000FF & 0xFFFF) # ori $s2, $s2, 0xff
.L7F015404:
  li    $s2, 65535
.L7F015408:
  lw    $t4, ($fp)
  addiu $a1, $sp, 0x8c
  move  $a2, $s1
  lw    $a3, ($s7)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t4, 0x10($sp)
  lw    $t8, 0x90($sp)
  lw    $t6, 0x8c($sp)
  lw    $t5, 0xb4($sp)
  lui   $v0, %hi(teamsize)
  lw    $v0, %lo(teamsize)($v0)
  sra   $t7, $t8, 1
  subu  $t1, $s6, $t7
  sra   $t9, $t6, 1
  addiu $t2, $t1, 0x46
  subu  $t0, $t5, $t9
  sw    $t0, 0x88($sp)
  bne   $s4, $v0, .L7F015470
   sw    $t2, 0x84($sp)
  bne   $s4, $v0, .L7F0154C4
   lui   $t3, %hi(D_8002B560) 
  lw    $t3, %lo(D_8002B560)($t3)
  slti  $at, $t3, 0xa
  beql  $at, $zero, .L7F0154C8
   lw    $t9, 0xcc($sp)
.L7F015470:
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s0, $v0, 0x10
  sra   $t4, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t4
  lw    $t6, ($s7)
  lw    $t5, ($fp)
  move  $a0, $s5
  addiu $a1, $sp, 0x88
  addiu $a2, $sp, 0x84
  move  $a3, $s1
  sw    $s2, 0x18($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t6, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t5, 0x14($sp)
  move  $s5, $v0
.L7F0154C4:
  lw    $t9, 0xcc($sp)
.L7F0154C8:
  addiu $s4, $s4, 1
  bnel  $s4, $t9, .L7F015224
   slti  $at, $s4, 2
.L7F0154D4:
  jal   combiner_bayer_lod_perspective
   move  $a0, $s5
  lw    $ra, 0x64($sp)
  ldc1  $f20, 0x38($sp)
  lw    $s0, 0x40($sp)
  lw    $s1, 0x44($sp)
  lw    $s2, 0x48($sp)
  lw    $s3, 0x4c($sp)
  lw    $s4, 0x50($sp)
  lw    $s5, 0x54($sp)
  lw    $s6, 0x58($sp)
  lw    $s7, 0x5c($sp)
  lw    $fp, 0x60($sp)
  jr    $ra
   addiu $sp, $sp, 0xd0
");

asm(R"
glabel set_briefing_page
  lui   $v0, %hi(current_menu_briefing_page)
  addiu $v0, %lo(current_menu_briefing_page) # addiu $v0, $v0, -0x56ec
  jr    $ra
   sw    $a0, ($v0)
");

asm(R"
glabel load_briefing_text_for_stage
  lui   $t6, %hi(briefingpage) 
  lw    $t6, %lo(briefingpage)($t6)
  addiu $sp, $sp, -0x28
  sw    $s0, 0x18($sp)
  lui   $s0, %hi(ptr_logo_and_walletbond_DL)
  lw    $s0, %lo(ptr_logo_and_walletbond_DL)($s0)
  sll   $t7, $t6, 3
  subu  $t7, $t7, $t6
  li    $at, 40960
  sll   $t7, $t7, 2
  lui   $a0, %hi(mission_folder_setup_entries+24)
  sw    $ra, 0x1c($sp)
  addu  $a0, $a0, $t7
  addu  $s0, $s0, $at
  move  $a2, $s0
  lw    $a0, %lo(mission_folder_setup_entries+24)($a0)
  li    $a1, 1
  jal   _load_resource_named_to_buffer
   li    $a3, 512
  lui   $t9, %hi(briefingpage) 
  lw    $t9, %lo(briefingpage)($t9)
  lui   $t8, (0x0006DE00 >> 16) # lui $t8, 6
  lui   $a0, %hi(mission_folder_setup_entries+8)
  sll   $t0, $t9, 3
  subu  $t0, $t0, $t9
  sll   $t0, $t0, 2
  lui   $at, %hi(ptrbriefingdata)
  ori   $t8, (0x0006DE00 & 0xFFFF) # ori $t8, $t8, 0xde00
  addu  $a0, $a0, $t0
  sw    $v0, %lo(ptrbriefingdata)($at)
  addiu $s0, $s0, 0x200
  sw    $t8, 0x20($sp)
  jal   get_textbank_number_for_stagenum
   lw    $a0, %lo(mission_folder_setup_entries+8)($a0)
  move  $a0, $v0
  move  $a1, $s0
  jal   load_briefing_text_bank
   lw    $a2, 0x20($sp)
  lui   $v1, %hi(ptrbriefingdata)
  lw    $v1, %lo(ptrbriefingdata)($v1)
  move  $v0, $zero
  li    $a0, 40
.L7F0155C8:
  lhu   $t1, 8($v1)
  addiu $v0, $v0, 4
  beql  $t1, $zero, .L7F0155E4
   lw    $ra, 0x1c($sp)
  bne   $v0, $a0, .L7F0155C8
   addiu $v1, $v1, 4
  lw    $ra, 0x1c($sp)
.L7F0155E4:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

void init_menu0A_briefing(void) {
  tab_2_selected = 0;
  tab_3_selected = 0;
  final_menu_briefing_page = 5;
  set_briefing_page(0);
  load_walletbond();
  load_briefing_text_for_stage();
}

void update_menu0A_briefing(void) {
  blank_text_bank(get_textbank_number_for_stagenum(
      mission_folder_setup_entries[briefingpage].stage_id));
  if (-1 < menu_update) {
    sub_GAME_7F00B990();
  }
}

asm(R"
.late_rodata
glabel D_80051AB8
.word 0x3FAAAAAB /*1.3333334;*/
glabel D_80051ABC
.word 0x461C4000 /*10000.0;*/
.text
glabel interface_menu0A_briefing
  addiu $sp, $sp, -0x18
  li    $at, 0x42700000 # 60.000000
  sw    $ra, 0x14($sp)
  mtc1  $at, $f12
  jal   setvideo_far
   nop   
  lui   $at, %hi(D_80051AB8)
  jal   video_related_21
   lwc1  $f12, %lo(D_80051AB8)($at)
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f12
  lui   $at, %hi(D_80051ABC)
  jal   set_page_height
   lwc1  $f14, %lo(D_80051ABC)($at)
  jal   set_video2_settings_offset_24
   move  $a0, $zero
  lui   $at, %hi(tab_3_highlight)
  sw    $zero, %lo(tab_3_highlight)($at)
  lui   $at, %hi(tab_2_highlight)
  sw    $zero, %lo(tab_2_highlight)($at)
  lui   $at, %hi(tab_1_highlight)
  jal   isontab3
   sw    $zero, %lo(tab_1_highlight)($at)
  beqz  $v0, .L7F01570C
   li    $v1, 1
  lui   $at, %hi(tab_3_highlight)
  b     .L7F01579C
   sw    $v1, %lo(tab_3_highlight)($at)
.L7F01570C:
  jal   isontab2
   nop   
  beqz  $v0, .L7F015744
   lui   $t6, %hi(current_menu_briefing_page) 
  lui   $t7, %hi(final_menu_briefing_page) 
  lw    $t7, %lo(final_menu_briefing_page)($t7)
  lw    $t6, %lo(current_menu_briefing_page)($t6)
  li    $v1, 1
  addiu $t8, $t7, -1
  slt   $at, $t6, $t8
  beqz  $at, .L7F015744
   lui   $at, %hi(tab_2_highlight)
  b     .L7F01579C
   sw    $v1, %lo(tab_2_highlight)($at)
.L7F015744:
  jal   isontab1
   nop   
  beqz  $v0, .L7F015764
   lui   $t9, %hi(current_menu_briefing_page) 
  li    $v1, 1
  lui   $at, %hi(tab_1_highlight)
  b     .L7F01579C
   sw    $v1, %lo(tab_1_highlight)($at)
.L7F015764:
  lui   $t0, %hi(final_menu_briefing_page) 
  lw    $t0, %lo(final_menu_briefing_page)($t0)
  lw    $t9, %lo(current_menu_briefing_page)($t9)
  li    $v1, 1
  addiu $t1, $t0, -1
  slt   $at, $t9, $t1
  beqz  $at, .L7F015794
   nop   
  li    $v1, 1
  lui   $at, %hi(tab_2_highlight)
  b     .L7F01579C
   sw    $v1, %lo(tab_2_highlight)($at)
.L7F015794:
  lui   $at, %hi(tab_1_highlight)
  sw    $v1, %lo(tab_1_highlight)($at)
.L7F01579C:
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 4096
  beqz  $v0, .L7F0157D4
   li    $v1, 1
  lui   $at, %hi(tab_2_selected)
  lui   $a0, %hi(ptr_sfx_buf)
  sw    $v1, %lo(tab_2_selected)($at)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 199
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F0158D0
   nop   
.L7F0157D4:
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 40960
  beqz  $v0, .L7F015880
   li    $v1, 1
  lui   $t2, %hi(tab_2_highlight) 
  lw    $t2, %lo(tab_2_highlight)($t2)
  lui   $a0, %hi(current_menu_briefing_page)
  lui   $t3, %hi(tab_3_highlight) 
  beqz  $t2, .L7F015814
   nop   
  lw    $a0, %lo(current_menu_briefing_page)($a0)
  jal   set_briefing_page
   addiu $a0, $a0, 1
  b     .L7F015864
   nop   
.L7F015814:
  lw    $t3, %lo(tab_3_highlight)($t3)
  lui   $v0, %hi(current_menu_briefing_page)
  lui   $t4, %hi(tab_1_highlight) 
  beqz  $t3, .L7F015850
   nop   
  lw    $v0, %lo(current_menu_briefing_page)($v0)
  lui   $at, %hi(tab_3_selected)
  blez  $v0, .L7F015848
   nop   
  jal   set_briefing_page
   addiu $a0, $v0, -1
  b     .L7F015864
   nop   
.L7F015848:
  b     .L7F015864
   sw    $v1, %lo(tab_3_selected)($at)
.L7F015850:
  lw    $t4, %lo(tab_1_highlight)($t4)
  lui   $at, %hi(tab_2_selected)
  beqz  $t4, .L7F015864
   nop   
  sw    $v1, %lo(tab_2_selected)($at)
.L7F015864:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 199
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F0158D0
   nop   
.L7F015880:
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 16384
  beqz  $v0, .L7F0158D0
   li    $v1, 1
  lui   $v0, %hi(current_menu_briefing_page)
  lw    $v0, %lo(current_menu_briefing_page)($v0)
  lui   $at, %hi(tab_3_selected)
  blez  $v0, .L7F0158B8
   nop   
  jal   set_briefing_page
   addiu $a0, $v0, -1
  b     .L7F0158BC
   nop   
.L7F0158B8:
  sw    $v1, %lo(tab_3_selected)($at)
.L7F0158BC:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 199
  jal   play_sfx_a1
   move  $a2, $zero
.L7F0158D0:
  lui   $a0, %hi(ptr_folder_object_instance)
  jal   disable_all_switches
   lw    $a0, %lo(ptr_folder_object_instance)($a0)
  lui   $a2, %hi(current_menu_briefing_page)
  lw    $a2, %lo(current_menu_briefing_page)($a2)
  lui   $a0, %hi(ptr_folder_object_instance)
  lw    $a0, %lo(ptr_folder_object_instance)($a0)
  sltiu $t5, $a2, 1
  move  $a2, $t5
  jal   set_item_visibility_in_objinstance
   li    $a1, 12
  lui   $t7, %hi(briefingpage) 
  lw    $t7, %lo(briefingpage)($t7)
  lui   $a2, %hi(current_menu_briefing_page)
  lw    $a2, %lo(current_menu_briefing_page)($a2)
  sll   $t6, $t7, 3
  subu  $t6, $t6, $t7
  sll   $t6, $t6, 2
  lui   $a1, %hi(mission_folder_setup_entries+20)
  addu  $a1, $a1, $t6
  lw    $a1, %lo(mission_folder_setup_entries+20)($a1)
  lui   $a0, %hi(ptr_folder_object_instance)
  sltiu $t8, $a2, 1
  move  $a2, $t8
  lw    $a0, %lo(ptr_folder_object_instance)($a0)
  jal   set_item_visibility_in_objinstance
   addiu $a1, $a1, 0x16
  lui   $a0, %hi(ptr_folder_object_instance)
  lw    $a0, %lo(ptr_folder_object_instance)($a0)
  move  $a1, $zero
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lui   $a0, %hi(ptr_folder_object_instance)
  lw    $a0, %lo(ptr_folder_object_instance)($a0)
  li    $a1, 1
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lui   $a0, %hi(ptr_folder_object_instance)
  lw    $a0, %lo(ptr_folder_object_instance)($a0)
  li    $a1, 3
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lui   $a0, %hi(ptr_folder_object_instance)
  lw    $a0, %lo(ptr_folder_object_instance)($a0)
  li    $a1, 6
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  jal   menu_control_stick_tracking
   nop   
  lui   $t0, %hi(tab_2_selected) 
  lw    $t0, %lo(tab_2_selected)($t0)
  li    $a0, 11
  lui   $t9, %hi(tab_3_selected) 
  beqz  $t0, .L7F0159BC
   nop   
  jal   set_menu_to_mode
   li    $a1, 1
  b     .L7F0159FC
   lw    $ra, 0x14($sp)
.L7F0159BC:
  lw    $t9, %lo(tab_3_selected)($t9)
  li    $a0, 7
  beql  $t9, $zero, .L7F0159FC
   lw    $ra, 0x14($sp)
  jal   set_menu_to_mode
   move  $a1, $zero
  lui   $t1, %hi(briefingpage) 
  lw    $t1, %lo(briefingpage)($t1)
  lui   $a0, %hi(mission_folder_setup_entries+20)
  sll   $t2, $t1, 3
  subu  $t2, $t2, $t1
  sll   $t2, $t2, 2
  addu  $a0, $a0, $t2
  jal   set_cursor_to_stage_solo
   lw    $a0, %lo(mission_folder_setup_entries+20)($a0)
  lw    $ra, 0x14($sp)
.L7F0159FC:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel print_objectives_and_status_to_menu
  addiu $sp, $sp, -0xa0
  sw    $s5, 0x4c($sp)
  sw    $s4, 0x48($sp)
  sw    $fp, 0x58($sp)
  sw    $s6, 0x50($sp)
  sw    $s3, 0x44($sp)
  lui   $s4, %hi(ptrSecondFontTableLarge)
  lui   $s5, %hi(ptrFirstFontTableLarge)
  move  $s3, $a2
  move  $s6, $a0
  sw    $ra, 0x5c($sp)
  sw    $s7, 0x54($sp)
  sw    $s2, 0x40($sp)
  sw    $s1, 0x3c($sp)
  sw    $s0, 0x38($sp)
  sw    $a1, 0xa4($sp)
  sw    $a3, 0xac($sp)
  sw    $zero, 0x98($sp)
  move  $fp, $zero
  addiu $s5, %lo(ptrFirstFontTableLarge) # addiu $s5, $s5, 0xeb4
  addiu $s4, %lo(ptrSecondFontTableLarge) # addiu $s4, $s4, 0xeb8
  move  $t0, $zero
  move  $t1, $zero
.L7F015A64:
  lui   $t6, %hi(ptrbriefingdata) 
  lw    $t6, %lo(ptrbriefingdata)($t6)
  lui   $t7, %hi(selected_difficulty) 
  addu  $v0, $t6, $t1
  lhu   $v1, 8($v0)
  beql  $v1, $zero, .L7F015D34
   addiu $t0, $t0, 1
  lw    $t7, %lo(selected_difficulty)($t7)
  lhu   $t8, 0xa($v0)
  move  $a0, $v1
  move  $s7, $zero
  slt   $at, $t7, $t8
  bnezl $at, .L7F015D34
   addiu $t0, $t0, 1
  sw    $t1, 0x6c($sp)
  jal   get_textptr_for_textID
   sw    $t0, 0x9c($sp)
  lui   $a1, %hi(aA_)
  move  $s1, $v0
  addiu $a1, %lo(aA_) # addiu $a1, $a1, 0xc50
  jal   textpointer_load_parse_something
   move  $a0, $s3
  lbu   $t9, ($s3)
  lw    $t2, 0x98($sp)
  addiu $a0, $sp, 0x94
  addiu $a1, $sp, 0x90
  addu  $t3, $t9, $t2
  sb    $t3, ($s3)
  lw    $t4, ($s5)
  sw    $zero, 0x94($sp)
  sw    $zero, 0x90($sp)
  sw    $zero, 0x14($sp)
  lw    $a3, ($s4)
  move  $a2, $s3
  jal   sub_GAME_7F0AE98C
   sw    $t4, 0x10($sp)
  lw    $t6, 0x94($sp)
  lw    $t8, 0xa4($sp)
  li    $t5, 55
  multu $t6, $fp
  sw    $t5, 0x8c($sp)
  mflo  $t7
  addu  $t9, $t7, $t8
  addu  $t2, $t9, $s7
  jal   get_video2_settings_txtClipW
   sw    $t2, 0x88($sp)
  sll   $s0, $v0, 0x10
  sra   $t3, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t3
  lw    $t4, ($s4)
  lw    $t5, ($s5)
  li    $t6, 255
  sw    $t6, 0x18($sp)
  move  $a0, $s6
  addiu $a1, $sp, 0x8c
  addiu $a2, $sp, 0x88
  move  $a3, $s3
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t4, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t5, 0x14($sp)
  lw    $t8, 0x94($sp)
  lw    $t2, 0xa4($sp)
  lw    $t5, 0xac($sp)
  multu $t8, $fp
  li    $t7, 75
  move  $s6, $v0
  sw    $t7, 0x8c($sp)
  li    $a0, 320
  move  $a1, $s1
  move  $a2, $s3
  mflo  $t9
  addu  $t3, $t9, $t2
  addu  $t4, $t3, $s7
  beqz  $t5, .L7F015BD8
   sw    $t4, 0x88($sp)
  jal   setTextWordWrap
   li    $a0, 2
  lw    $t6, ($s5)
  li    $a0, 220
  move  $a1, $s1
  move  $a2, $s3
  lw    $a3, ($s4)
  jal   sub_GAME_7F0AEB64
   sw    $t6, 0x10($sp)
  jal   setTextWordWrap
   move  $a0, $zero
  b     .L7F015BE8
   nop   
.L7F015BD8:
  lw    $t7, ($s5)
  lw    $a3, ($s4)
  jal   sub_GAME_7F0AEB64
   sw    $t7, 0x10($sp)
.L7F015BE8:
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s0, $v0, 0x10
  sra   $t8, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t8
  lw    $t9, ($s4)
  lw    $t2, ($s5)
  li    $t3, 255
  sw    $t3, 0x18($sp)
  move  $a0, $s6
  addiu $a1, $sp, 0x8c
  addiu $a2, $sp, 0x88
  move  $a3, $s3
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t9, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t2, 0x14($sp)
  lw    $t4, 0xac($sp)
  move  $s6, $v0
  beqz  $t4, .L7F015D10
   nop   
  jal   get_status_of_objective
   lw    $a0, 0x9c($sp)
  beqz  $v0, .L7F015C88
   li    $at, 1
  beq   $v0, $at, .L7F015C78
   li    $a0, 40027
  li    $at, 2
  beql  $v0, $at, .L7F015C8C
   lui   $s2, 0x7800
  b     .L7F015C8C
   lui   $s2, 0x7800
.L7F015C78:
  jal   get_textptr_for_textID
   li    $s2, 255
  b     .L7F015C9C
   move  $s1, $v0
.L7F015C88:
  lui   $s2, (0x780000FF >> 16) # lui $s2, 0x7800
.L7F015C8C:
  ori   $s2, (0x780000FF & 0xFFFF) # ori $s2, $s2, 0xff
  jal   get_textptr_for_textID
   li    $a0, 40028
  move  $s1, $v0
.L7F015C9C:
  lw    $t6, 0x94($sp)
  lw    $t8, 0xa4($sp)
  li    $t5, 310
  multu $t6, $fp
  sw    $t5, 0x8c($sp)
  mflo  $t7
  addu  $t9, $t7, $t8
  addu  $t2, $t9, $s7
  jal   get_video2_settings_txtClipW
   sw    $t2, 0x88($sp)
  sll   $s0, $v0, 0x10
  sra   $t3, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t3
  lw    $t4, ($s4)
  lw    $t5, ($s5)
  move  $a0, $s6
  addiu $a1, $sp, 0x8c
  addiu $a2, $sp, 0x88
  move  $a3, $s1
  sw    $s2, 0x18($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t4, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t5, 0x14($sp)
  move  $s6, $v0
.L7F015D10:
  jal   sub_GAME_7F0AC0E8
   move  $a0, $s3
  lw    $t6, 0x98($sp)
  addu  $fp, $fp, $v0
  lw    $t1, 0x6c($sp)
  addiu $t7, $t6, 1
  sw    $t7, 0x98($sp)
  lw    $t0, 0x9c($sp)
  addiu $t0, $t0, 1
.L7F015D34:
  li    $at, 10
  bne   $t0, $at, .L7F015A64
   addiu $t1, $t1, 4
  lw    $ra, 0x5c($sp)
  move  $v0, $s6
  lw    $s6, 0x50($sp)
  lw    $s0, 0x38($sp)
  lw    $s1, 0x3c($sp)
  lw    $s2, 0x40($sp)
  lw    $s3, 0x44($sp)
  lw    $s4, 0x48($sp)
  lw    $s5, 0x4c($sp)
  lw    $s7, 0x54($sp)
  lw    $fp, 0x58($sp)
  jr    $ra
   addiu $sp, $sp, 0xa0
");

asm(R"
.late_rodata
glabel jpt_briefingpage_name
 .word .L7F015E14
 .word .L7F015E24
 .word .L7F015E34
 .word .L7F015E44
 .word .L7F015E54

.text
glabel constructor_menu0A_briefing
  addiu $sp, $sp, -0xc10
  sw    $ra, 0x3c($sp)
  sw    $s0, 0x38($sp)
  move  $a1, $zero
  move  $a2, $zero
  jal   set_setfillcolor
   move  $a3, $zero
  jal   insert_generic_fillrect
   move  $a0, $v0
  jal   sub_GAME_7F00D5E8
   move  $a0, $v0
  lui   $t7, %hi(asc_D_80050C54) 
  addiu $t7, %lo(asc_D_80050C54) # addiu $t7, $t7, 0xc54
  addiu $t0, $t7, 0xbb8
  addiu $t6, $sp, 0x4c
.L7F015DB0:
  lw    $at, ($t7)
  addiu $t7, $t7, 0xc
  addiu $t6, $t6, 0xc
  sw    $at, -0xc($t6)
  lw    $at, -8($t7)
  sw    $at, -8($t6)
  lw    $at, -4($t7)
  bne   $t7, $t0, .L7F015DB0
   sw    $at, -4($t6)
  jal   microcode_constructor
   move  $a0, $v0
  move  $a0, $v0
  jal   print_current_solo_briefing_stage_name
   addiu $a1, $sp, 0x4c
  lui   $t1, %hi(current_menu_briefing_page) 
  lw    $t1, %lo(current_menu_briefing_page)($t1)
  move  $s0, $v0
  sltiu $at, $t1, 5
  beqz  $at, .L7F015E60
   sll   $t1, $t1, 2
  lui   $at, %hi(jpt_briefingpage_name)
  addu  $at, $at, $t1
  lw    $t1, %lo(jpt_briefingpage_name)($at)
  jr    $t1
   nop   
.L7F015E14:
  jal   get_textptr_for_textID
   li    $a0, 40029
  b     .L7F015E60
   sw    $v0, 0xc0c($sp)
.L7F015E24:
  jal   get_textptr_for_textID
   li    $a0, 40030
  b     .L7F015E60
   sw    $v0, 0xc0c($sp)
.L7F015E34:
  jal   get_textptr_for_textID
   li    $a0, 40031
  b     .L7F015E60
   sw    $v0, 0xc0c($sp)
.L7F015E44:
  jal   get_textptr_for_textID
   li    $a0, 40032
  b     .L7F015E60
   sw    $v0, 0xc0c($sp)
.L7F015E54:
  jal   get_textptr_for_textID
   li    $a0, 40033
  sw    $v0, 0xc0c($sp)
def_7F015E0C:
.L7F015E60:
  li    $t2, 55
  li    $t3, 143
  sw    $t2, 0xc08($sp)
  jal   get_video2_settings_txtClipW
   sw    $t3, 0xc04($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x48($sp)
  lui   $t4, %hi(ptrSecondFontTableLarge) 
  lui   $t5, %hi(ptrFirstFontTableLarge) 
  lw    $t5, %lo(ptrFirstFontTableLarge)($t5)
  lw    $t4, %lo(ptrSecondFontTableLarge)($t4)
  lh    $t8, 0x48($sp)
  li    $t9, 255
  sw    $t9, 0x18($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0xc08
  addiu $a2, $sp, 0xc04
  lw    $a3, 0xc0c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t5, 0x14($sp)
  sw    $t4, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t8, 0x1c($sp)
  lui   $v1, %hi(current_menu_briefing_page)
  lw    $v1, %lo(current_menu_briefing_page)($v1)
  move  $s0, $v0
  li    $at, 1
  bnez  $v1, .L7F015EF4
   move  $a0, $v0
  li    $a1, 167
  addiu $a2, $sp, 0x4c
  jal   print_objectives_and_status_to_menu
   move  $a3, $zero
  b     .L7F016014
   move  $s0, $v0
.L7F015EF4:
  beq   $v1, $at, .L7F015F28
   lui   $t0, %hi(ptrbriefingdata) 
  li    $at, 2
  beq   $v1, $at, .L7F015F3C
   lui   $t7, %hi(ptrbriefingdata) 
  li    $at, 3
  beq   $v1, $at, .L7F015F50
   lui   $t6, %hi(ptrbriefingdata) 
  li    $at, 4
  beq   $v1, $at, .L7F015F64
   lui   $t1, %hi(ptrbriefingdata) 
  b     .L7F015F74
   nop   
.L7F015F28:
  lw    $t0, %lo(ptrbriefingdata)($t0)
  jal   get_textptr_for_textID
   lhu   $a0, ($t0)
  b     .L7F015F74
   sw    $v0, 0xc0c($sp)
.L7F015F3C:
  lw    $t7, %lo(ptrbriefingdata)($t7)
  jal   get_textptr_for_textID
   lhu   $a0, 2($t7)
  b     .L7F015F74
   sw    $v0, 0xc0c($sp)
.L7F015F50:
  lw    $t6, %lo(ptrbriefingdata)($t6)
  jal   get_textptr_for_textID
   lhu   $a0, 4($t6)
  b     .L7F015F74
   sw    $v0, 0xc0c($sp)
.L7F015F64:
  lw    $t1, %lo(ptrbriefingdata)($t1)
  jal   get_textptr_for_textID
   lhu   $a0, 6($t1)
  sw    $v0, 0xc0c($sp)
.L7F015F74:
  lui   $t4, %hi(ptrFirstFontTableLarge) 
  lw    $t4, %lo(ptrFirstFontTableLarge)($t4)
  li    $t2, 55
  li    $t3, 167
  lui   $a3, %hi(ptrSecondFontTableLarge)
  sw    $t2, 0xc08($sp)
  sw    $t3, 0xc04($sp)
  lw    $a3, %lo(ptrSecondFontTableLarge)($a3)
  li    $a0, 320
  lw    $a1, 0xc0c($sp)
  addiu $a2, $sp, 0x4c
  jal   sub_GAME_7F0AEB64
   sw    $t4, 0x10($sp)
  jal   setTextOverlapCorrection
   li    $a0, 8
  jal   get_video2_settings_txtClipW
   nop   
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x48($sp)
  lui   $t5, %hi(ptrSecondFontTableLarge) 
  lui   $t9, %hi(ptrFirstFontTableLarge) 
  lw    $t9, %lo(ptrFirstFontTableLarge)($t9)
  lw    $t5, %lo(ptrSecondFontTableLarge)($t5)
  lh    $t0, 0x48($sp)
  li    $t8, 255
  sw    $t8, 0x18($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0xc08
  addiu $a2, $sp, 0xc04
  addiu $a3, $sp, 0x4c
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t9, 0x14($sp)
  sw    $t5, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t0, 0x1c($sp)
  move  $s0, $v0
  jal   setTextOverlapCorrection
   li    $a0, -1
.L7F016014:
  jal   add_tab1_start
   move  $a0, $s0
  jal   add_tab3_previous
   move  $a0, $v0
  lui   $t7, %hi(current_menu_briefing_page) 
  lw    $t7, %lo(current_menu_briefing_page)($t7)
  move  $s0, $v0
  slti  $at, $t7, 4
  beqz  $at, .L7F016048
   nop   
  jal   add_tab2_next
   move  $a0, $v0
  move  $s0, $v0
.L7F016048:
  jal   load_draw_selected_icon_folder_select
   move  $a0, $s0
  lw    $ra, 0x3c($sp)
  lw    $s0, 0x38($sp)
  addiu $sp, $sp, 0xc10
  jr    $ra
   nop   
");

void init_menu0B_runstage(void) {
  set_loaded_stage(selected_stage);
  set_difficulty(selected_difficulty);
}

void init_menu0C_missionfailed(void) {
  tab_2_selected = false;
  tab_3_selected = false;
  load_walletbond();
  load_briefing_text_for_stage();
  set_cursor_pos_tab2();
  if (maybe_is_in_menu != false) {
    sfx_c_700091E8(0x7fff);
    musicTrack1Vol(0x7fff);
    music1_playing = false;
    musicTrack1Play(M_FOLDERS);
    maybe_is_in_menu = false;
  }
}

void update_menu0C_missionfailed(void) {}

asm(R"
.late_rodata
glabel menu0C_aspect
.word 0x3FAAAAAB /*1.3333334;*/
glabel menu0C_pageheight
.word 0x461C4000 /*10000.0;*/
.text
glabel interface_menu0C_missionfailed
  addiu $sp, $sp, -0x18
  li    $at, 0x42700000 # 60.000000
  sw    $ra, 0x14($sp)
  mtc1  $at, $f12
  jal   setvideo_far
   nop   
  lui   $at, %hi(menu0C_aspect)
  jal   video_related_21
   lwc1  $f12, %lo(menu0C_aspect)($at)
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f12
  lui   $at, %hi(menu0C_pageheight)
  jal   set_page_height
   lwc1  $f14, %lo(menu0C_pageheight)($at)
  jal   set_video2_settings_offset_24
   move  $a0, $zero
  lui   $at, %hi(tab_2_highlight)
  sw    $zero, %lo(tab_2_highlight)($at)
  lui   $at, %hi(tab_3_highlight)
  jal   isontab3
   sw    $zero, %lo(tab_3_highlight)($at)
  beqz  $v0, .L7F016178
   li    $v1, 1
  lui   $at, %hi(tab_3_highlight)
  b     .L7F0161A0
   sw    $v1, %lo(tab_3_highlight)($at)
.L7F016178:
  jal   isontab2
   nop   
  beqz  $v0, .L7F016198
   li    $v1, 1
  li    $v1, 1
  lui   $at, %hi(tab_2_highlight)
  b     .L7F0161A0
   sw    $v1, %lo(tab_2_highlight)($at)
.L7F016198:
  lui   $at, %hi(tab_2_highlight)
  sw    $v1, %lo(tab_2_highlight)($at)
.L7F0161A0:
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 45056
  beqz  $v0, .L7F016214
   li    $v1, 1
  lui   $t6, %hi(tab_3_highlight) 
  lw    $t6, %lo(tab_3_highlight)($t6)
  lui   $at, %hi(tab_3_selected)
  lui   $a0, %hi(ptr_sfx_buf)
  beqz  $t6, .L7F0161E8
   lui   $t7, %hi(tab_2_highlight) 
  sw    $v1, %lo(tab_3_selected)($at)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 199
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F016244
   nop   
.L7F0161E8:
  lw    $t7, %lo(tab_2_highlight)($t7)
  lui   $at, %hi(tab_2_selected)
  lui   $a0, %hi(ptr_sfx_buf)
  beqz  $t7, .L7F016244
   li    $a1, 199
  sw    $v1, %lo(tab_2_selected)($at)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F016244
   nop   
.L7F016214:
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 16384
  beqz  $v0, .L7F016244
   li    $v1, 1
  lui   $at, %hi(tab_3_selected)
  lui   $a0, %hi(ptr_sfx_buf)
  sw    $v1, %lo(tab_3_selected)($at)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 199
  jal   play_sfx_a1
   move  $a2, $zero
.L7F016244:
  lui   $a0, %hi(ptr_folder_object_instance)
  jal   disable_all_switches
   lw    $a0, %lo(ptr_folder_object_instance)($a0)
  lui   $a0, %hi(ptr_folder_object_instance)
  lw    $a0, %lo(ptr_folder_object_instance)($a0)
  move  $a1, $zero
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lui   $a0, %hi(ptr_folder_object_instance)
  lw    $a0, %lo(ptr_folder_object_instance)($a0)
  li    $a1, 1
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lui   $a0, %hi(ptr_folder_object_instance)
  lw    $a0, %lo(ptr_folder_object_instance)($a0)
  li    $a1, 3
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lui   $a0, %hi(ptr_folder_object_instance)
  lw    $a0, %lo(ptr_folder_object_instance)($a0)
  li    $a1, 6
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  jal   menu_control_stick_tracking
   nop   
  lui   $t8, %hi(tab_2_selected) 
  lw    $t8, %lo(tab_2_selected)($t8)
  li    $a0, 13
  lui   $t9, %hi(tab_3_selected) 
  beqz  $t8, .L7F0162D0
   nop   
  jal   set_menu_to_mode
   move  $a1, $zero
  b     .L7F016310
   lw    $ra, 0x14($sp)
.L7F0162D0:
  lw    $t9, %lo(tab_3_selected)($t9)
  li    $a0, 7
  beql  $t9, $zero, .L7F016310
   lw    $ra, 0x14($sp)
  jal   set_menu_to_mode
   move  $a1, $zero
  lui   $t0, %hi(briefingpage) 
  lw    $t0, %lo(briefingpage)($t0)
  lui   $a0, %hi(mission_folder_setup_entries+200)
  sll   $t1, $t0, 3
  subu  $t1, $t1, $t0
  sll   $t1, $t1, 2
  addu  $a0, $a0, $t1
  jal   set_cursor_to_stage_solo
   lw    $a0, %lo(mission_folder_setup_entries+20)($a0)
  lw    $ra, 0x14($sp)
.L7F016310:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F01631C
  addiu $sp, $sp, -0x30
  lui   $t6, %hi(mission_failed_or_aborted) 
  lw    $t6, %lo(mission_failed_or_aborted)($t6)
  sw    $ra, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  bnez  $t6, .L7F01635C
   sw    $s0, 0x18($sp)
  lui   $t7, %hi(mission_kia_flag) 
  lw    $t7, %lo(mission_kia_flag)($t7)
  move  $s0, $zero
  move  $s1, $zero
  beqz  $t7, .L7F016364
   li    $s4, 10
.L7F01635C:
  b     .L7F0163CC
   move  $v0, $zero
.L7F016364:
  lui   $s2, %hi(ptrbriefingdata)
  addiu $s2, %lo(ptrbriefingdata) # addiu $s2, $s2, -0x6874
  li    $s3, 1
.L7F016370:
  lw    $t8, ($s2)
  addu  $t9, $t8, $s1
  lhu   $t0, 8($t9)
  beql  $t0, $zero, .L7F0163C0
   addiu $s0, $s0, 1
  jal   get_current_difficulty
   nop   
  lw    $t1, ($s2)
  addu  $t2, $t1, $s1
  lhu   $t3, 0xa($t2)
  slt   $at, $v0, $t3
  bnezl $at, .L7F0163C0
   addiu $s0, $s0, 1
  jal   get_status_of_objective
   move  $a0, $s0
  beql  $v0, $s3, .L7F0163C0
   addiu $s0, $s0, 1
  b     .L7F0163CC
   move  $v0, $zero
  addiu $s0, $s0, 1
.L7F0163C0:
  bne   $s0, $s4, .L7F016370
   addiu $s1, $s1, 4
  li    $v0, 1
.L7F0163CC:
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  lw    $s3, 0x24($sp)
  lw    $s4, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x30
");

asm(R"
glabel constructor_menu0C_missionfailed
  addiu $sp, $sp, -0xc18
  sw    $ra, 0x3c($sp)
  sw    $s0, 0x38($sp)
  move  $a1, $zero
  move  $a2, $zero
  jal   set_setfillcolor
   move  $a3, $zero
  jal   insert_generic_fillrect
   move  $a0, $v0
  jal   sub_GAME_7F00D5E8
   move  $a0, $v0
  jal   microcode_constructor
   move  $a0, $v0
  move  $a0, $v0
  jal   print_current_solo_briefing_stage_name
   addiu $a1, $sp, 0x58
  sw    $v0, 0xc18($sp)
  jal   get_textptr_for_textID
   li    $a0, 40034
  li    $t6, 55
  li    $t7, 143
  move  $s0, $v0
  sw    $t6, 0xc14($sp)
  jal   get_video2_settings_txtClipW
   sw    $t7, 0xc10($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lui   $t8, %hi(ptrSecondFontTableLarge) 
  lui   $t9, %hi(ptrFirstFontTableLarge) 
  lw    $t9, %lo(ptrFirstFontTableLarge)($t9)
  lw    $t8, %lo(ptrSecondFontTableLarge)($t8)
  lh    $t1, 0x44($sp)
  li    $t0, 255
  sw    $t0, 0x18($sp)
  lw    $a0, 0xc18($sp)
  addiu $a1, $sp, 0xc14
  addiu $a2, $sp, 0xc10
  move  $a3, $s0
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t9, 0x14($sp)
  sw    $t8, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t1, 0x1c($sp)
  sw    $v0, 0xc18($sp)
  jal   get_textptr_for_textID
   li    $a0, 40035
  lui   $t2, %hi(ptrFirstFontTableLarge) 
  lw    $t2, %lo(ptrFirstFontTableLarge)($t2)
  lui   $a3, %hi(ptrSecondFontTableLarge)
  move  $s0, $v0
  sw    $zero, 0x48($sp)
  sw    $zero, 0x4c($sp)
  lw    $a3, %lo(ptrSecondFontTableLarge)($a3)
  addiu $a0, $sp, 0x4c
  addiu $a1, $sp, 0x48
  move  $a2, $v0
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t2, 0x10($sp)
  li    $t3, 55
  li    $t4, 167
  sw    $t3, 0xc14($sp)
  jal   get_video2_settings_txtClipW
   sw    $t4, 0xc10($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lui   $t5, %hi(ptrSecondFontTableLarge) 
  lui   $t6, %hi(ptrFirstFontTableLarge) 
  lw    $t6, %lo(ptrFirstFontTableLarge)($t6)
  lw    $t5, %lo(ptrSecondFontTableLarge)($t5)
  lh    $t8, 0x44($sp)
  li    $t7, 255
  sw    $t7, 0x18($sp)
  lw    $a0, 0xc18($sp)
  addiu $a1, $sp, 0xc14
  addiu $a2, $sp, 0xc10
  move  $a3, $s0
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t6, 0x14($sp)
  sw    $t5, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t8, 0x1c($sp)
  lui   $t9, %hi(mission_kia_flag) 
  lw    $t9, %lo(mission_kia_flag)($t9)
  sw    $v0, 0xc18($sp)
  lui   $t0, %hi(mission_failed_or_aborted) 
  beqz  $t9, .L7F016574
   nop   
  jal   get_textptr_for_textID
   li    $a0, 40036
  lui   $v1, (0x780000FF >> 16) # lui $v1, 0x7800
  move  $s0, $v0
  b     .L7F0165D0
   ori   $v1, (0x780000FF & 0xFFFF) # ori $v1, $v1, 0xff
.L7F016574:
  lw    $t0, %lo(mission_failed_or_aborted)($t0)
  beqz  $t0, .L7F016598
   nop   
  jal   get_textptr_for_textID
   li    $a0, 40037
  lui   $v1, (0x780000FF >> 16) # lui $v1, 0x7800
  move  $s0, $v0
  b     .L7F0165D0
   ori   $v1, (0x780000FF & 0xFFFF) # ori $v1, $v1, 0xff
.L7F016598:
  jal   sub_GAME_7F01631C
   nop   
  beqz  $v0, .L7F0165BC
   nop   
  jal   get_textptr_for_textID
   li    $a0, 40038
  move  $s0, $v0
  b     .L7F0165D0
   li    $v1, 255
.L7F0165BC:
  jal   get_textptr_for_textID
   li    $a0, 40039
  lui   $v1, (0x780000FF >> 16) # lui $v1, 0x7800
  move  $s0, $v0
  ori   $v1, (0x780000FF & 0xFFFF) # ori $v1, $v1, 0xff
.L7F0165D0:
  lw    $t1, 0x48($sp)
  li    $t3, 167
  sw    $t3, 0xc10($sp)
  addiu $t2, $t1, 0x37
  sw    $t2, 0xc14($sp)
  jal   get_video2_settings_txtClipW
   sw    $v1, 0x50($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lui   $t4, %hi(ptrSecondFontTableLarge) 
  lui   $t5, %hi(ptrFirstFontTableLarge) 
  lw    $t5, %lo(ptrFirstFontTableLarge)($t5)
  lw    $t4, %lo(ptrSecondFontTableLarge)($t4)
  lw    $v1, 0x50($sp)
  lh    $t6, 0x44($sp)
  lw    $a0, 0xc18($sp)
  addiu $a1, $sp, 0xc14
  addiu $a2, $sp, 0xc10
  move  $a3, $s0
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t5, 0x14($sp)
  sw    $t4, 0x10($sp)
  sw    $v1, 0x18($sp)
  jal   write_text_at_abs_coord
   sw    $t6, 0x1c($sp)
  move  $a0, $v0
  li    $a1, 191
  addiu $a2, $sp, 0x58
  jal   print_objectives_and_status_to_menu
   li    $a3, 1
  jal   add_tab2_next
   move  $a0, $v0
  jal   add_tab3_previous
   move  $a0, $v0
  jal   load_draw_selected_icon_folder_select
   move  $a0, $v0
  lw    $ra, 0x3c($sp)
  lw    $s0, 0x38($sp)
  addiu $sp, $sp, 0xc18
  jr    $ra
   nop   
");

void init_menu0D_missioncomplete(void) {
  tab_2_selected = 0;
  tab_3_selected = 0;
  load_walletbond();
  load_briefing_text_for_stage();
  if (newcheatunlocked != 0) {
    play_sfx_a1(ptr_sfx_buf, 0x102, 0);
  }
}

void update_menu0D_missioncomplete(void) {}

asm(R"
.late_rodata
glabel menu0D_aspect
.word 0x3FAAAAAB /*1.3333334;*/
glabel menu0D_pageheight
.word 0x461C4000 /*10000.0;*/

.text
glabel interface_menu0D_missioncomplete
  addiu $sp, $sp, -0x18
  li    $at, 0x42700000 # 60.000000
  sw    $ra, 0x14($sp)
  mtc1  $at, $f12
  jal   setvideo_far
   nop   
  lui   $at, %hi(menu0D_aspect)
  jal   video_related_21
   lwc1  $f12, %lo(menu0D_aspect)($at)
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f12
  lui   $at, %hi(menu0D_pageheight)
  jal   set_page_height
   lwc1  $f14, %lo(menu0D_pageheight)($at)
  jal   set_video2_settings_offset_24
   move  $a0, $zero
  lui   $at, %hi(tab_3_highlight)
  sw    $zero, %lo(tab_3_highlight)($at)
  lui   $at, %hi(tab_2_highlight)
  jal   isontab3
   sw    $zero, %lo(tab_2_highlight)($at)
  beqz  $v0, .L7F016740
   li    $v1, 1
  lui   $at, %hi(tab_3_highlight)
  b     .L7F016768
   sw    $v1, %lo(tab_3_highlight)($at)
.L7F016740:
  jal   isontab2
   nop   
  beqz  $v0, .L7F016760
   li    $v1, 1
  li    $v1, 1
  lui   $at, %hi(tab_2_highlight)
  b     .L7F016768
   sw    $v1, %lo(tab_2_highlight)($at)
.L7F016760:
  lui   $at, %hi(tab_2_highlight)
  sw    $v1, %lo(tab_2_highlight)($at)
.L7F016768:
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 45056
  beqz  $v0, .L7F0167DC
   li    $v1, 1
  lui   $t6, %hi(tab_2_highlight) 
  lw    $t6, %lo(tab_2_highlight)($t6)
  lui   $at, %hi(tab_2_selected)
  lui   $a0, %hi(ptr_sfx_buf)
  beqz  $t6, .L7F0167B0
   lui   $t7, %hi(tab_3_highlight) 
  sw    $v1, %lo(tab_2_selected)($at)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 199
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F01680C
   nop   
.L7F0167B0:
  lw    $t7, %lo(tab_3_highlight)($t7)
  lui   $at, %hi(tab_3_selected)
  lui   $a0, %hi(ptr_sfx_buf)
  beqz  $t7, .L7F01680C
   li    $a1, 199
  sw    $v1, %lo(tab_3_selected)($at)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F01680C
   nop   
.L7F0167DC:
  move  $a0, $zero
  jal   get_controller_buttons_pressed
   li    $a1, 16384
  beqz  $v0, .L7F01680C
   li    $v1, 1
  lui   $at, %hi(tab_3_selected)
  lui   $a0, %hi(ptr_sfx_buf)
  sw    $v1, %lo(tab_3_selected)($at)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 199
  jal   play_sfx_a1
   move  $a2, $zero
.L7F01680C:
  lui   $a0, %hi(ptr_folder_object_instance)
  jal   disable_all_switches
   lw    $a0, %lo(ptr_folder_object_instance)($a0)
  lui   $a0, %hi(ptr_folder_object_instance)
  lw    $a0, %lo(ptr_folder_object_instance)($a0)
  move  $a1, $zero
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lui   $a0, %hi(ptr_folder_object_instance)
  lw    $a0, %lo(ptr_folder_object_instance)($a0)
  li    $a1, 1
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lui   $a0, %hi(ptr_folder_object_instance)
  lw    $a0, %lo(ptr_folder_object_instance)($a0)
  li    $a1, 3
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lui   $a0, %hi(ptr_folder_object_instance)
  lw    $a0, %lo(ptr_folder_object_instance)($a0)
  li    $a1, 6
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  jal   menu_control_stick_tracking
   nop   
  lui   $t8, %hi(tab_2_selected) 
  lw    $t8, %lo(tab_2_selected)($t8)
  lui   $t1, %hi(tab_3_selected) 
  beqz  $t8, .L7F0169B4
   nop   
  jal   sub_GAME_7F01631C
   nop   
  beqz  $v0, .L7F0169A0
   lui   $t9, %hi(append_cheat_sp) 
  lw    $t9, %lo(append_cheat_sp)($t9)
  lui   $t0, %hi(briefingpage) 
  addiu $t0, %lo(briefingpage) # addiu $t0, $t0, -0x5708
  bnezl $t9, .L7F0169A4
   li    $a0, 10
  lw    $a1, ($t0)
  li    $a3, 28
  lui   $a2, %hi(mission_folder_setup_entries)
  multu $a1, $a3
  addiu $a2, %lo(mission_folder_setup_entries) # addiu $a2, $a2, -0x541c
  li    $at, 17
  li    $a0, 11
  mflo  $t1
  addu  $t2, $a2, $t1
  lw    $v0, 0x14($t2)
  bnel  $v0, $at, .L7F0168F4
   slti  $at, $v0, 0x12
  jal   set_menu_to_mode
   li    $a1, 1
  li    $t3, 54
  lui   $at, %hi(selected_stage)
  b     .L7F0169F8
   sw    $t3, %lo(selected_stage)($at)
  slti  $at, $v0, 0x12
.L7F0168F4:
  bnez  $at, .L7F01693C
   addiu $v1, $a1, 1
  li    $a0, 7
  jal   set_menu_to_mode
   move  $a1, $zero
  lui   $t0, %hi(briefingpage) 
  addiu $t0, %lo(briefingpage) # addiu $t0, $t0, -0x5708
  lw    $t4, ($t0)
  li    $a3, 28
  lui   $a2, %hi(mission_folder_setup_entries)
  multu $t4, $a3
  addiu $a2, %lo(mission_folder_setup_entries) # addiu $a2, $a2, -0x541c
  mflo  $t5
  addu  $t6, $a2, $t5
  jal   set_cursor_to_stage_solo
   lw    $a0, 0x14($t6)
  b     .L7F0169FC
   lw    $ra, 0x14($sp)
.L7F01693C:
  multu $v1, $a3
  move  $a1, $zero
  mflo  $t7
  addu  $v0, $a2, $t7
  lhu   $a0, 4($v0)
  beqz  $a0, .L7F016978
   nop   
  lw    $t8, 8($v0)
.L7F01695C:
  bgez  $t8, .L7F016978
   nop   
  lhu   $a0, 0x20($v0)
  addiu $v1, $v1, 1
  addiu $v0, $v0, 0x1c
  bnezl $a0, .L7F01695C
   lw    $t8, 8($v0)
.L7F016978:
  beqz  $a0, .L7F016990
   nop   
  lw    $t9, 8($v0)
  sw    $v1, ($t0)
  lui   $at, %hi(selected_stage)
  sw    $t9, %lo(selected_stage)($at)
.L7F016990:
  jal   set_menu_to_mode
   li    $a0, 10
  b     .L7F0169FC
   lw    $ra, 0x14($sp)
.L7F0169A0:
  li    $a0, 10
.L7F0169A4:
  jal   set_menu_to_mode
   move  $a1, $zero
  b     .L7F0169FC
   lw    $ra, 0x14($sp)
.L7F0169B4:
  lw    $t1, %lo(tab_3_selected)($t1)
  li    $a0, 7
  beql  $t1, $zero, .L7F0169FC
   lw    $ra, 0x14($sp)
  jal   set_menu_to_mode
   move  $a1, $zero
  lui   $t0, %hi(briefingpage) 
  addiu $t0, %lo(briefingpage) # addiu $t0, $t0, -0x5708
  lw    $t2, ($t0)
  li    $a3, 28
  lui   $a2, %hi(mission_folder_setup_entries)
  multu $t2, $a3
  addiu $a2, %lo(mission_folder_setup_entries) # addiu $a2, $a2, -0x541c
  mflo  $t3
  addu  $t4, $a2, $t3
  jal   set_cursor_to_stage_solo
   lw    $a0, 0x14($t4)
.L7F0169F8:
  lw    $ra, 0x14($sp)
.L7F0169FC:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel constructor_menu0D_missioncomplete
  addiu $sp, $sp, -0xc68
  sw    $ra, 0x3c($sp)
  sw    $s1, 0x38($sp)
  sw    $s0, 0x34($sp)
  move  $a1, $zero
  move  $a2, $zero
  jal   set_setfillcolor
   move  $a3, $zero
  jal   insert_generic_fillrect
   move  $a0, $v0
  jal   sub_GAME_7F00D5E8
   move  $a0, $v0
  jal   microcode_constructor
   move  $a0, $v0
  jal   get_mission_timer
   move  $s1, $v0
  jal   get_curplay_killcount
   sw    $v0, 0x98($sp)
  sw    $v0, 0x94($sp)
  jal   get_curplayer_shot_register
   move  $a0, $zero
  sw    $v0, 0x90($sp)
  jal   get_curplayer_shot_register
   li    $a0, 1
  sw    $v0, 0x8c($sp)
  jal   get_curplayer_shot_register
   li    $a0, 2
  sw    $v0, 0x88($sp)
  jal   get_curplayer_shot_register
   li    $a0, 3
  sw    $v0, 0x84($sp)
  jal   get_curplayer_shot_register
   li    $a0, 4
  sw    $v0, 0x80($sp)
  jal   get_curplayer_shot_register
   li    $a0, 5
  sw    $v0, 0x7c($sp)
  jal   get_curplayer_shot_register
   li    $a0, 6
  lw    $t6, 0x8c($sp)
  lw    $t7, 0x88($sp)
  lw    $t9, 0x84($sp)
  lw    $t3, 0x80($sp)
  lw    $t5, 0x7c($sp)
  addu  $t8, $t6, $t7
  addu  $t2, $t8, $t9
  addu  $t4, $t2, $t3
  addu  $a2, $t4, $t5
  addu  $t6, $a2, $v0
  bgtz  $a2, .L7F016AD8
   sw    $t6, 0x74($sp)
  li    $a2, 1
.L7F016AD8:
  move  $a0, $s1
  addiu $a1, $sp, 0xa8
  jal   print_current_solo_briefing_stage_name
   sw    $a2, 0x70($sp)
  move  $s1, $v0
  jal   get_textptr_for_textID
   li    $a0, 40040
  li    $t7, 55
  li    $t8, 143
  sw    $v0, 0xa4($sp)
  sw    $t7, 0xc64($sp)
  jal   get_video2_settings_txtClipW
   sw    $t8, 0xc60($sp)
  sll   $s0, $v0, 0x10
  sra   $t9, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t9
  lui   $t2, %hi(ptrSecondFontTableLarge) 
  lui   $t3, %hi(ptrFirstFontTableLarge) 
  lw    $t3, %lo(ptrFirstFontTableLarge)($t3)
  lw    $t2, %lo(ptrSecondFontTableLarge)($t2)
  li    $t4, 255
  sw    $t4, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xc64
  addiu $a2, $sp, 0xc60
  lw    $a3, 0xa4($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t3, 0x14($sp)
  jal   write_text_at_abs_coord
   sw    $t2, 0x10($sp)
  lui   $t5, %hi(ptrFirstFontTableLarge) 
  lw    $t5, %lo(ptrFirstFontTableLarge)($t5)
  lui   $a3, %hi(ptrSecondFontTableLarge)
  move  $s1, $v0
  sw    $zero, 0x9c($sp)
  sw    $zero, 0xa0($sp)
  lw    $a3, %lo(ptrSecondFontTableLarge)($a3)
  addiu $a0, $sp, 0xa0
  addiu $a1, $sp, 0x9c
  lw    $a2, 0xa4($sp)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t5, 0x10($sp)
  jal   get_textptr_for_textID
   li    $a0, 40041
  li    $t6, 55
  li    $t7, 167
  sw    $v0, 0xa4($sp)
  sw    $t6, 0xc64($sp)
  jal   get_video2_settings_txtClipW
   sw    $t7, 0xc60($sp)
  sll   $s0, $v0, 0x10
  sra   $t8, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t8
  lui   $t9, %hi(ptrSecondFontTableLarge) 
  lui   $t2, %hi(ptrFirstFontTableLarge) 
  lw    $t2, %lo(ptrFirstFontTableLarge)($t2)
  lw    $t9, %lo(ptrSecondFontTableLarge)($t9)
  li    $t3, 255
  sw    $t3, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xc64
  addiu $a2, $sp, 0xc60
  lw    $a3, 0xa4($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t2, 0x14($sp)
  jal   write_text_at_abs_coord
   sw    $t9, 0x10($sp)
  lui   $a0, %hi(selected_folder_num)
  move  $s1, $v0
  jal   get_save_folder_ptr
   lw    $a0, %lo(selected_folder_num)($a0)
  lui   $t4, %hi(briefingpage) 
  lw    $t4, %lo(briefingpage)($t4)
  lui   $s0, %hi(mission_folder_setup_entries)
  addiu $s0, %lo(mission_folder_setup_entries) # addiu $s0, $s0, -0x541c
  sll   $t5, $t4, 3
  subu  $t5, $t5, $t4
  sll   $t5, $t5, 2
  addu  $t6, $s0, $t5
  lui   $a2, %hi(selected_difficulty)
  lw    $a2, %lo(selected_difficulty)($a2)
  lw    $a1, 0x14($t6)
  jal   get_eeprom_stage_complete_time_for_difficulty
   move  $a0, $v0
  beqz  $v0, .L7F016C60
   move  $t1, $v0
  slti  $at, $v0, 0x3ff
  bnez  $at, .L7F016C64
   nop   
.L7F016C60:
  li    $t1, -1
.L7F016C64:
  lui   $v0, %hi(selected_difficulty)
  lw    $v0, %lo(selected_difficulty)($v0)
  li    $t0, 60
  lui   $t7, %hi(briefingpage) 
  slti  $at, $v0, 3
  bnez  $at, .L7F016C88
   lui   $t6, %hi(solo_target_time_array)
  b     .L7F016C8C
   li    $v1, 2
.L7F016C88:
  move  $v1, $v0
.L7F016C8C:
  lw    $t7, %lo(briefingpage)($t7)
  sll   $t4, $v1, 1
  lui   $a1, %hi(a02d02d)
  sll   $t8, $t7, 3
  subu  $t8, $t8, $t7
  lw    $t7, 0x98($sp)
  sll   $t8, $t8, 2
  addu  $t9, $s0, $t8
  div   $zero, $t7, $t0
  mflo  $v0
  lw    $t2, 0x14($t9)
  sb    $zero, 0xa8($sp)
  div   $zero, $v0, $t0
  sll   $t3, $t2, 2
  subu  $t3, $t3, $t2
  sll   $t3, $t3, 1
  addu  $t5, $t3, $t4
  addu  $t6, $t6, $t5
  lh    $t6, %lo(solo_target_time_array)($t6)
  mfhi  $a3
  mflo  $a2
  sw    $t1, 0x64($sp)
  addiu $a1, %lo(a02d02d) # addiu $a1, $a1, 0x180c
  addiu $a0, $sp, 0xa8
  sw    $t6, 0x60($sp)
  bnez  $t0, .L7F016CFC
   nop   
  break 7
.L7F016CFC:
  li    $at, -1
  bne   $t0, $at, .L7F016D14
   lui   $at, 0x8000
  bne   $t7, $at, .L7F016D14
   nop   
  break 6
.L7F016D14:
  bnez  $t0, .L7F016D20
   nop   
  break 7
.L7F016D20:
  li    $at, -1
  bne   $t0, $at, .L7F016D38
   lui   $at, 0x8000
  bne   $v0, $at, .L7F016D38
   nop   
  break 6
.L7F016D38:
  jal   sprintf
   nop   
  li    $t8, 130
  li    $t9, 167
  sw    $t8, 0xc64($sp)
  jal   get_video2_settings_txtClipW
   sw    $t9, 0xc60($sp)
  sll   $s0, $v0, 0x10
  sra   $t2, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t2
  lui   $t3, %hi(ptrSecondFontTableLarge) 
  lui   $t4, %hi(ptrFirstFontTableLarge) 
  lw    $t4, %lo(ptrFirstFontTableLarge)($t4)
  lw    $t3, %lo(ptrSecondFontTableLarge)($t3)
  li    $t5, 255
  sw    $t5, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xc64
  addiu $a2, $sp, 0xc60
  addiu $a3, $sp, 0xa8
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t4, 0x14($sp)
  jal   write_text_at_abs_coord
   sw    $t3, 0x10($sp)
  lui   $t6, %hi(newcheatunlocked) 
  lw    $t6, %lo(newcheatunlocked)($t6)
  move  $s1, $v0
  beql  $t6, $zero, .L7F016E44
   lw    $t3, 0x60($sp)
  sb    $zero, 0xa8($sp)
  jal   get_textptr_for_textID
   li    $a0, 40211
  lui   $a1, %hi(aS)
  addiu $a1, %lo(aS) # addiu $a1, $a1, 0x1818
  addiu $a0, $sp, 0xa8
  jal   sprintf
   move  $a2, $v0
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s0, $v0, 0x10
  sra   $t7, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t7
  lui   $t8, %hi(ptrSecondFontTableLarge) 
  lui   $t9, %hi(ptrFirstFontTableLarge) 
  lw    $t9, %lo(ptrFirstFontTableLarge)($t9)
  lw    $t8, %lo(ptrSecondFontTableLarge)($t8)
  lui   $t2, (0xA00000FF >> 16) # lui $t2, 0xa000
  ori   $t2, (0xA00000FF & 0xFFFF) # ori $t2, $t2, 0xff
  sw    $t2, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xc64
  addiu $a2, $sp, 0xc60
  addiu $a3, $sp, 0xa8
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t9, 0x14($sp)
  jal   write_text_at_abs_coord
   sw    $t8, 0x10($sp)
  move  $s1, $v0
  lw    $t3, 0x60($sp)
.L7F016E44:
  blez  $t3, .L7F01708C
   lui   $t4, %hi(selected_difficulty) 
  lw    $t4, %lo(selected_difficulty)($t4)
  li    $at, 3
  beql  $t4, $at, .L7F017090
   lw    $v0, 0x64($sp)
  jal   get_textptr_for_textID
   li    $a0, 40210
  lw    $t6, 0xa0($sp)
  li    $t5, 55
  sw    $v0, 0xa4($sp)
  addiu $t7, $t6, 0xa9
  sw    $t5, 0xc64($sp)
  jal   get_video2_settings_txtClipW
   sw    $t7, 0xc60($sp)
  sll   $s0, $v0, 0x10
  sra   $t8, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t8
  lui   $t9, %hi(ptrSecondFontTableLarge) 
  lui   $t2, %hi(ptrFirstFontTableLarge) 
  lw    $t2, %lo(ptrFirstFontTableLarge)($t2)
  lw    $t9, %lo(ptrSecondFontTableLarge)($t9)
  li    $t3, 255
  sw    $t3, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xc64
  addiu $a2, $sp, 0xc60
  lw    $a3, 0xa4($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t2, 0x14($sp)
  jal   write_text_at_abs_coord
   sw    $t9, 0x10($sp)
  lw    $t4, 0x60($sp)
  li    $v1, 60
  lui   $a1, %hi(a02d02d_0)
  div   $zero, $t4, $v1
  mfhi  $a3
  mflo  $a2
  move  $s1, $v0
  sb    $zero, 0xa8($sp)
  addiu $a1, %lo(a02d02d_0) # addiu $a1, $a1, 0x1824
  addiu $a0, $sp, 0xa8
  bnez  $v1, .L7F016F08
   nop   
  break 7
.L7F016F08:
  li    $at, -1
  bne   $v1, $at, .L7F016F20
   lui   $at, 0x8000
  bne   $t4, $at, .L7F016F20
   nop   
  break 6
.L7F016F20:
  jal   sprintf
   nop   
  lw    $t6, 0xa0($sp)
  li    $t5, 130
  sw    $t5, 0xc64($sp)
  addiu $t7, $t6, 0xa9
  jal   get_video2_settings_txtClipW
   sw    $t7, 0xc60($sp)
  sll   $s0, $v0, 0x10
  sra   $t8, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t8
  lui   $t9, %hi(ptrSecondFontTableLarge) 
  lui   $t2, %hi(ptrFirstFontTableLarge) 
  lw    $t2, %lo(ptrFirstFontTableLarge)($t2)
  lw    $t9, %lo(ptrSecondFontTableLarge)($t9)
  li    $t3, 255
  sw    $t3, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xc64
  addiu $a2, $sp, 0xc60
  addiu $a3, $sp, 0xa8
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t2, 0x14($sp)
  jal   write_text_at_abs_coord
   sw    $t9, 0x10($sp)
  lw    $v1, 0x64($sp)
  move  $s1, $v0
  bltz  $v1, .L7F0171B4
   slti  $at, $v1, 0x3ff
  beqz  $at, .L7F0171B4
   nop   
  bltz  $v1, .L7F017018
   sb    $zero, 0xa8($sp)
  jal   get_textptr_for_textID
   li    $a0, 40209
  lw    $v1, 0x64($sp)
  li    $t0, 60
  lui   $a1, %hi(aS02d02d)
  div   $zero, $v1, $t0
  mfhi  $t4
  mflo  $a3
  sw    $t4, 0x10($sp)
  addiu $a1, %lo(aS02d02d) # addiu $a1, $a1, 0x1830
  addiu $a0, $sp, 0xa8
  move  $a2, $v0
  bnez  $t0, .L7F016FF0
   nop   
  break 7
.L7F016FF0:
  li    $at, -1
  bne   $t0, $at, .L7F017008
   lui   $at, 0x8000
  bne   $v1, $at, .L7F017008
   nop   
  break 6
.L7F017008:
  jal   sprintf
   nop   
  b     .L7F017028
   nop   
.L7F017018:
  lui   $a1, %hi(D_80051848)
  addiu $a1, %lo(D_80051848) # addiu $a1, $a1, 0x1848
  jal   sprintf
   addiu $a0, $sp, 0xa8
.L7F017028:
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s0, $v0, 0x10
  sra   $t5, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t5
  lui   $t6, %hi(ptrSecondFontTableLarge) 
  lui   $t7, %hi(ptrFirstFontTableLarge) 
  lw    $t7, %lo(ptrFirstFontTableLarge)($t7)
  lw    $t6, %lo(ptrSecondFontTableLarge)($t6)
  li    $t8, 255
  sw    $t8, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xc64
  addiu $a2, $sp, 0xc60
  addiu $a3, $sp, 0xa8
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t7, 0x14($sp)
  jal   write_text_at_abs_coord
   sw    $t6, 0x10($sp)
  b     .L7F0171B4
   move  $s1, $v0
.L7F01708C:
  lw    $v0, 0x64($sp)
.L7F017090:
  bltz  $v0, .L7F0171B4
   slti  $at, $v0, 0x3ff
  beqz  $at, .L7F0171B4
   nop   
  jal   get_textptr_for_textID
   li    $a0, 40209
  lw    $t2, 0xa0($sp)
  li    $t9, 55
  sw    $v0, 0xa4($sp)
  addiu $t3, $t2, 0xa9
  sw    $t9, 0xc64($sp)
  jal   get_video2_settings_txtClipW
   sw    $t3, 0xc60($sp)
  sll   $s0, $v0, 0x10
  sra   $t4, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t4
  lui   $t5, %hi(ptrSecondFontTableLarge) 
  lui   $t6, %hi(ptrFirstFontTableLarge) 
  lw    $t6, %lo(ptrFirstFontTableLarge)($t6)
  lw    $t5, %lo(ptrSecondFontTableLarge)($t5)
  li    $t7, 255
  sw    $t7, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xc64
  addiu $a2, $sp, 0xc60
  lw    $a3, 0xa4($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t6, 0x14($sp)
  jal   write_text_at_abs_coord
   sw    $t5, 0x10($sp)
  lw    $t8, 0x64($sp)
  li    $at, 60
  lui   $a1, %hi(a02d02d_1)
  div   $zero, $t8, $at
  mfhi  $a3
  mflo  $a2
  move  $s1, $v0
  sb    $zero, 0xa8($sp)
  addiu $a1, %lo(a02d02d_1) # addiu $a1, $a1, 0x184c
  jal   sprintf
   addiu $a0, $sp, 0xa8
  lw    $t2, 0xa0($sp)
  li    $t9, 130
  sw    $t9, 0xc64($sp)
  addiu $t3, $t2, 0xa9
  jal   get_video2_settings_txtClipW
   sw    $t3, 0xc60($sp)
  sll   $s0, $v0, 0x10
  sra   $t4, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t4
  lui   $t5, %hi(ptrSecondFontTableLarge) 
  lui   $t6, %hi(ptrFirstFontTableLarge) 
  lw    $t6, %lo(ptrFirstFontTableLarge)($t6)
  lw    $t5, %lo(ptrSecondFontTableLarge)($t5)
  li    $t7, 255
  sw    $t7, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xc64
  addiu $a2, $sp, 0xc60
  addiu $a3, $sp, 0xa8
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t6, 0x14($sp)
  jal   write_text_at_abs_coord
   sw    $t5, 0x10($sp)
  move  $s1, $v0
.L7F0171B4:
  jal   get_textptr_for_textID
   li    $a0, 40042
  li    $t8, 55
  li    $t9, 204
  sw    $v0, 0xa4($sp)
  sw    $t8, 0xc64($sp)
  jal   get_video2_settings_txtClipW
   sw    $t9, 0xc60($sp)
  sll   $s0, $v0, 0x10
  sra   $t2, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t2
  lui   $t3, %hi(ptrSecondFontTableLarge) 
  lui   $t4, %hi(ptrFirstFontTableLarge) 
  lw    $t4, %lo(ptrFirstFontTableLarge)($t4)
  lw    $t3, %lo(ptrSecondFontTableLarge)($t3)
  li    $t5, 255
  sw    $t5, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xc64
  addiu $a2, $sp, 0xc60
  lw    $a3, 0xa4($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t4, 0x14($sp)
  jal   write_text_at_abs_coord
   sw    $t3, 0x10($sp)
  lw    $v1, 0x90($sp)
  move  $s1, $v0
  addiu $a0, $sp, 0xa8
  blezl $v1, .L7F017268
   mtc1  $zero, $f0
  lw    $t6, 0x74($sp)
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f8
  mtc1  $t6, $f4
  mtc1  $v1, $f16
  cvt.s.w $f6, $f4
  cvt.s.w $f18, $f16
  mul.s $f10, $f6, $f8
  b     .L7F01726C
   div.s $f0, $f10, $f18
  mtc1  $zero, $f0
.L7F017268:
  nop   
.L7F01726C:
  cvt.d.s $f4, $f0
  lui   $a1, %hi(a_1f)
  mfc1  $a3, $f4
  mfc1  $a2, $f5
  jal   sprintf
   addiu $a1, %lo(a_1f) # addiu $a1, $a1, 0x1858
  li    $t7, 130
  li    $t8, 204
  sw    $t7, 0xc64($sp)
  jal   get_video2_settings_txtClipW
   sw    $t8, 0xc60($sp)
  sll   $s0, $v0, 0x10
  sra   $t9, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t9
  lui   $t2, %hi(ptrSecondFontTableLarge) 
  lui   $t3, %hi(ptrFirstFontTableLarge) 
  lw    $t3, %lo(ptrFirstFontTableLarge)($t3)
  lw    $t2, %lo(ptrSecondFontTableLarge)($t2)
  li    $t4, 255
  sw    $t4, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xc64
  addiu $a2, $sp, 0xc60
  addiu $a3, $sp, 0xa8
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t3, 0x14($sp)
  jal   write_text_at_abs_coord
   sw    $t2, 0x10($sp)
  move  $s1, $v0
  jal   get_textptr_for_textID
   li    $a0, 40043
  li    $t5, 55
  li    $t6, 220
  sw    $v0, 0xa4($sp)
  sw    $t5, 0xc64($sp)
  jal   get_video2_settings_txtClipW
   sw    $t6, 0xc60($sp)
  sll   $s0, $v0, 0x10
  sra   $t7, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t7
  lui   $t8, %hi(ptrSecondFontTableLarge) 
  lui   $t9, %hi(ptrFirstFontTableLarge) 
  lw    $t9, %lo(ptrFirstFontTableLarge)($t9)
  lw    $t8, %lo(ptrSecondFontTableLarge)($t8)
  li    $t2, 255
  sw    $t2, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xc64
  addiu $a2, $sp, 0xc60
  lw    $a3, 0xa4($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t9, 0x14($sp)
  jal   write_text_at_abs_coord
   sw    $t8, 0x10($sp)
  move  $s1, $v0
  move  $a0, $zero
  jal   getplayerfavoredweapon
   move  $a1, $zero
  addiu $a0, $sp, 0xa8
  jal   textpointer_load_parse_something
   move  $a1, $v0
  lui   $a0, %hi(array_favweapon)
  addiu $a0, %lo(array_favweapon) # addiu $a0, $a0, -0x6910
  lw    $v1, ($a0)
  blezl $v1, .L7F0173C4
   li    $t6, 190
  lw    $t3, 4($a0)
  bnel  $t3, $v1, .L7F0173C4
   li    $t6, 190
  jal   strlen
   addiu $a0, $sp, 0xa8
  addiu $t4, $v0, -1
  addiu $t5, $sp, 0xa8
  lui   $a1, %hi(aX2)
  addiu $a1, %lo(aX2) # addiu $a1, $a1, 0x1860
  jal   sprintf
   addu  $a0, $t4, $t5
  li    $t6, 190
.L7F0173C4:
  li    $t7, 220
  sw    $t6, 0xc64($sp)
  jal   get_video2_settings_txtClipW
   sw    $t7, 0xc60($sp)
  sll   $s0, $v0, 0x10
  sra   $t8, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t8
  lui   $t9, %hi(ptrSecondFontTableLarge) 
  lui   $t2, %hi(ptrFirstFontTableLarge) 
  lw    $t2, %lo(ptrFirstFontTableLarge)($t2)
  lw    $t9, %lo(ptrSecondFontTableLarge)($t9)
  li    $t3, 255
  sw    $t3, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xc64
  addiu $a2, $sp, 0xc60
  addiu $a3, $sp, 0xa8
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t2, 0x14($sp)
  jal   write_text_at_abs_coord
   sw    $t9, 0x10($sp)
  move  $s1, $v0
  jal   get_textptr_for_textID
   li    $a0, 40044
  li    $t4, 55
  li    $t5, 244
  sw    $v0, 0xa4($sp)
  sw    $t4, 0xc64($sp)
  jal   get_video2_settings_txtClipW
   sw    $t5, 0xc60($sp)
  sll   $s0, $v0, 0x10
  sra   $t6, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t6
  lui   $t7, %hi(ptrSecondFontTableLarge) 
  lui   $t8, %hi(ptrFirstFontTableLarge) 
  lw    $t8, %lo(ptrFirstFontTableLarge)($t8)
  lw    $t7, %lo(ptrSecondFontTableLarge)($t7)
  li    $t9, 255
  sw    $t9, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xc64
  addiu $a2, $sp, 0xc60
  lw    $a3, 0xa4($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t8, 0x14($sp)
  jal   write_text_at_abs_coord
   sw    $t7, 0x10($sp)
  lui   $a1, %hi(aD_8)
  move  $s1, $v0
  addiu $a1, %lo(aD_8) # addiu $a1, $a1, 0x1868
  addiu $a0, $sp, 0xa8
  jal   sprintf
   lw    $a2, 0x90($sp)
  li    $t2, 130
  li    $t3, 244
  sw    $t2, 0xc64($sp)
  jal   get_video2_settings_txtClipW
   sw    $t3, 0xc60($sp)
  sll   $s0, $v0, 0x10
  sra   $t4, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t4
  lui   $t5, %hi(ptrSecondFontTableLarge) 
  lui   $t6, %hi(ptrFirstFontTableLarge) 
  lw    $t6, %lo(ptrFirstFontTableLarge)($t6)
  lw    $t5, %lo(ptrSecondFontTableLarge)($t5)
  li    $t7, 255
  sw    $t7, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xc64
  addiu $a2, $sp, 0xc60
  addiu $a3, $sp, 0xa8
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t6, 0x14($sp)
  jal   write_text_at_abs_coord
   sw    $t5, 0x10($sp)
  move  $s1, $v0
  jal   get_textptr_for_textID
   li    $a0, 40045
  li    $t8, 180
  li    $t9, 244
  sw    $v0, 0xa4($sp)
  sw    $t8, 0xc64($sp)
  jal   get_video2_settings_txtClipW
   sw    $t9, 0xc60($sp)
  sll   $s0, $v0, 0x10
  sra   $t2, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t2
  lui   $t3, %hi(ptrSecondFontTableLarge) 
  lui   $t4, %hi(ptrFirstFontTableLarge) 
  lw    $t4, %lo(ptrFirstFontTableLarge)($t4)
  lw    $t3, %lo(ptrSecondFontTableLarge)($t3)
  li    $t5, 255
  sw    $t5, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xc64
  addiu $a2, $sp, 0xc60
  lw    $a3, 0xa4($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t4, 0x14($sp)
  jal   write_text_at_abs_coord
   sw    $t3, 0x10($sp)
  lw    $t7, 0x8c($sp)
  lw    $t6, 0x70($sp)
  li    $at, 0x42C80000 # 100.000000
  mtc1  $t7, $f8
  mtc1  $at, $f10
  mtc1  $t6, $f6
  cvt.s.w $f16, $f8
  li    $at, 0x3F000000 # 0.500000
  move  $s1, $v0
  cvt.s.w $f0, $f6
  mul.s $f18, $f16, $f10
  mtc1  $at, $f6
  swc1  $f0, 0x48($sp)
  div.s $f4, $f18, $f0
  jal   truncf
   add.s $f12, $f4, $f6
  trunc.w.s $f8, $f0
  lui   $a1, %hi(aDD_0)
  addiu $a1, %lo(aDD_0) # addiu $a1, $a1, 0x186c
  addiu $a0, $sp, 0xa8
  mfc1  $a3, $f8
  jal   sprintf
   lw    $a2, 0x8c($sp)
  li    $t9, 300
  li    $t2, 244
  sw    $t9, 0xc64($sp)
  jal   get_video2_settings_txtClipW
   sw    $t2, 0xc60($sp)
  sll   $s0, $v0, 0x10
  sra   $t3, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t3
  lui   $t4, %hi(ptrSecondFontTableLarge) 
  lui   $t5, %hi(ptrFirstFontTableLarge) 
  lw    $t5, %lo(ptrFirstFontTableLarge)($t5)
  lw    $t4, %lo(ptrSecondFontTableLarge)($t4)
  li    $t6, 255
  sw    $t6, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xc64
  addiu $a2, $sp, 0xc60
  addiu $a3, $sp, 0xa8
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t5, 0x14($sp)
  jal   write_text_at_abs_coord
   sw    $t4, 0x10($sp)
  move  $s1, $v0
  jal   get_textptr_for_textID
   li    $a0, 40046
  lw    $t8, 0xa0($sp)
  li    $t7, 180
  sw    $v0, 0xa4($sp)
  addiu $t9, $t8, 0xf4
  sw    $t7, 0xc64($sp)
  jal   get_video2_settings_txtClipW
   sw    $t9, 0xc60($sp)
  sll   $s0, $v0, 0x10
  sra   $t2, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t2
  lui   $t3, %hi(ptrSecondFontTableLarge) 
  lui   $t4, %hi(ptrFirstFontTableLarge) 
  lw    $t4, %lo(ptrFirstFontTableLarge)($t4)
  lw    $t3, %lo(ptrSecondFontTableLarge)($t3)
  li    $t5, 255
  sw    $t5, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xc64
  addiu $a2, $sp, 0xc60
  lw    $a3, 0xa4($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t4, 0x14($sp)
  jal   write_text_at_abs_coord
   sw    $t3, 0x10($sp)
  lw    $t6, 0x88($sp)
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f18
  mtc1  $t6, $f16
  lwc1  $f6, 0x48($sp)
  li    $at, 0x3F000000 # 0.500000
  cvt.s.w $f10, $f16
  mtc1  $at, $f16
  move  $s1, $v0
  mul.s $f4, $f10, $f18
  div.s $f8, $f4, $f6
  jal   truncf
   add.s $f12, $f8, $f16
  trunc.w.s $f10, $f0
  lui   $a1, %hi(aDD_1)
  addiu $a1, %lo(aDD_1) # addiu $a1, $a1, 0x1878
  addiu $a0, $sp, 0xa8
  mfc1  $a3, $f10
  jal   sprintf
   lw    $a2, 0x88($sp)
  lw    $t9, 0xa0($sp)
  li    $t8, 300
  sw    $t8, 0xc64($sp)
  addiu $t2, $t9, 0xf4
  jal   get_video2_settings_txtClipW
   sw    $t2, 0xc60($sp)
  sll   $s0, $v0, 0x10
  sra   $t3, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t3
  lui   $t4, %hi(ptrSecondFontTableLarge) 
  lui   $t5, %hi(ptrFirstFontTableLarge) 
  lw    $t5, %lo(ptrFirstFontTableLarge)($t5)
  lw    $t4, %lo(ptrSecondFontTableLarge)($t4)
  li    $t6, 255
  sw    $t6, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xc64
  addiu $a2, $sp, 0xc60
  addiu $a3, $sp, 0xa8
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t5, 0x14($sp)
  jal   write_text_at_abs_coord
   sw    $t4, 0x10($sp)
  move  $s1, $v0
  jal   get_textptr_for_textID
   li    $a0, 40047
  lw    $t8, 0xa0($sp)
  li    $t7, 180
  sw    $v0, 0xa4($sp)
  sll   $t9, $t8, 1
  addiu $t2, $t9, 0xf4
  sw    $t7, 0xc64($sp)
  jal   get_video2_settings_txtClipW
   sw    $t2, 0xc60($sp)
  sll   $s0, $v0, 0x10
  sra   $t3, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t3
  lui   $t4, %hi(ptrSecondFontTableLarge) 
  lui   $t5, %hi(ptrFirstFontTableLarge) 
  lw    $t5, %lo(ptrFirstFontTableLarge)($t5)
  lw    $t4, %lo(ptrSecondFontTableLarge)($t4)
  li    $t6, 255
  sw    $t6, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xc64
  addiu $a2, $sp, 0xc60
  lw    $a3, 0xa4($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t5, 0x14($sp)
  jal   write_text_at_abs_coord
   sw    $t4, 0x10($sp)
  lw    $t7, 0x84($sp)
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f6
  mtc1  $t7, $f18
  lwc1  $f16, 0x48($sp)
  li    $at, 0x3F000000 # 0.500000
  cvt.s.w $f4, $f18
  mtc1  $at, $f18
  move  $s1, $v0
  mul.s $f8, $f4, $f6
  div.s $f10, $f8, $f16
  jal   truncf
   add.s $f12, $f10, $f18
  trunc.w.s $f4, $f0
  lui   $a1, %hi(aDD_2)
  addiu $a1, %lo(aDD_2) # addiu $a1, $a1, 0x1884
  addiu $a0, $sp, 0xa8
  mfc1  $a3, $f4
  jal   sprintf
   lw    $a2, 0x84($sp)
  lw    $t2, 0xa0($sp)
  li    $t9, 300
  sw    $t9, 0xc64($sp)
  sll   $t3, $t2, 1
  addiu $t4, $t3, 0xf4
  jal   get_video2_settings_txtClipW
   sw    $t4, 0xc60($sp)
  sll   $s0, $v0, 0x10
  sra   $t5, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t5
  lui   $t6, %hi(ptrSecondFontTableLarge) 
  lui   $t7, %hi(ptrFirstFontTableLarge) 
  lw    $t7, %lo(ptrFirstFontTableLarge)($t7)
  lw    $t6, %lo(ptrSecondFontTableLarge)($t6)
  li    $t8, 255
  sw    $t8, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xc64
  addiu $a2, $sp, 0xc60
  addiu $a3, $sp, 0xa8
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t7, 0x14($sp)
  jal   write_text_at_abs_coord
   sw    $t6, 0x10($sp)
  move  $s1, $v0
  jal   get_textptr_for_textID
   li    $a0, 40048
  lw    $t2, 0xa0($sp)
  li    $t9, 180
  sw    $v0, 0xa4($sp)
  sll   $t3, $t2, 2
  subu  $t3, $t3, $t2
  addiu $t4, $t3, 0xf4
  sw    $t9, 0xc64($sp)
  jal   get_video2_settings_txtClipW
   sw    $t4, 0xc60($sp)
  sll   $s0, $v0, 0x10
  sra   $t5, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t5
  lui   $t6, %hi(ptrSecondFontTableLarge) 
  lui   $t7, %hi(ptrFirstFontTableLarge) 
  lw    $t7, %lo(ptrFirstFontTableLarge)($t7)
  lw    $t6, %lo(ptrSecondFontTableLarge)($t6)
  li    $t8, 255
  sw    $t8, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xc64
  addiu $a2, $sp, 0xc60
  lw    $a3, 0xa4($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t7, 0x14($sp)
  jal   write_text_at_abs_coord
   sw    $t6, 0x10($sp)
  lw    $t9, 0x7c($sp)
  lw    $t2, 0x80($sp)
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f16
  addu  $s0, $t9, $t2
  mtc1  $s0, $f6
  lwc1  $f18, 0x48($sp)
  li    $at, 0x3F000000 # 0.500000
  cvt.s.w $f8, $f6
  mtc1  $at, $f6
  move  $s1, $v0
  mul.s $f10, $f8, $f16
  div.s $f4, $f10, $f18
  jal   truncf
   add.s $f12, $f4, $f6
  trunc.w.s $f8, $f0
  lui   $a1, %hi(aDD_3)
  addiu $a1, %lo(aDD_3) # addiu $a1, $a1, 0x1890
  addiu $a0, $sp, 0xa8
  mfc1  $a3, $f8
  jal   sprintf
   move  $a2, $s0
  lw    $t5, 0xa0($sp)
  li    $t4, 300
  sw    $t4, 0xc64($sp)
  sll   $t6, $t5, 2
  subu  $t6, $t6, $t5
  addiu $t7, $t6, 0xf4
  jal   get_video2_settings_txtClipW
   sw    $t7, 0xc60($sp)
  sll   $s0, $v0, 0x10
  sra   $t8, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t8
  lui   $t9, %hi(ptrSecondFontTableLarge) 
  lui   $t2, %hi(ptrFirstFontTableLarge) 
  lw    $t2, %lo(ptrFirstFontTableLarge)($t2)
  lw    $t9, %lo(ptrSecondFontTableLarge)($t9)
  li    $t3, 255
  sw    $t3, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xc64
  addiu $a2, $sp, 0xc60
  addiu $a3, $sp, 0xa8
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t2, 0x14($sp)
  jal   write_text_at_abs_coord
   sw    $t9, 0x10($sp)
  move  $s1, $v0
  jal   get_textptr_for_textID
   li    $a0, 40049
  lw    $t5, 0xa0($sp)
  li    $t4, 55
  sw    $v0, 0xa4($sp)
  addiu $t6, $t5, 0xf4
  sw    $t4, 0xc64($sp)
  jal   get_video2_settings_txtClipW
   sw    $t6, 0xc60($sp)
  sll   $s0, $v0, 0x10
  sra   $t7, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t7
  lui   $t8, %hi(ptrSecondFontTableLarge) 
  lui   $t9, %hi(ptrFirstFontTableLarge) 
  lw    $t9, %lo(ptrFirstFontTableLarge)($t9)
  lw    $t8, %lo(ptrSecondFontTableLarge)($t8)
  li    $t2, 255
  sw    $t2, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xc64
  addiu $a2, $sp, 0xc60
  lw    $a3, 0xa4($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t9, 0x14($sp)
  jal   write_text_at_abs_coord
   sw    $t8, 0x10($sp)
  lui   $a1, %hi(aD_10)
  move  $s1, $v0
  addiu $a1, %lo(aD_10) # addiu $a1, $a1, 0x189c
  addiu $a0, $sp, 0xa8
  jal   sprintf
   lw    $a2, 0x94($sp)
  lw    $t4, 0xa0($sp)
  li    $t3, 130
  sw    $t3, 0xc64($sp)
  addiu $t5, $t4, 0xf4
  jal   get_video2_settings_txtClipW
   sw    $t5, 0xc60($sp)
  sll   $s0, $v0, 0x10
  sra   $t6, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t6
  lui   $t7, %hi(ptrSecondFontTableLarge) 
  lui   $t8, %hi(ptrFirstFontTableLarge) 
  lw    $t8, %lo(ptrFirstFontTableLarge)($t8)
  lw    $t7, %lo(ptrSecondFontTableLarge)($t7)
  li    $t9, 255
  sw    $t9, 0x18($sp)
  move  $a0, $s1
  addiu $a1, $sp, 0xc64
  addiu $a2, $sp, 0xc60
  addiu $a3, $sp, 0xa8
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t8, 0x14($sp)
  jal   write_text_at_abs_coord
   sw    $t7, 0x10($sp)
  jal   add_tab2_next
   move  $a0, $v0
  jal   add_tab3_previous
   move  $a0, $v0
  jal   load_draw_selected_icon_folder_select
   move  $a0, $v0
  lw    $ra, 0x3c($sp)
  lw    $s0, 0x34($sp)
  lw    $s1, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0xc68
");

asm(R"
glabel init_menu15_cheat
  lui   $at, %hi(tab_1_selected)
  sw    $zero, %lo(tab_1_selected)($at)
  lui   $at, %hi(tab_2_selected)
  sw    $zero, %lo(tab_2_selected)($at)
  lui   $at, %hi(tab_3_selected)
  sw    $zero, %lo(tab_3_selected)($at)
  lui   $at, %hi(tab_3_highlight)
  sw    $zero, %lo(tab_3_highlight)($at)
  lui   $at, %hi(tab_2_highlight)
  sw    $zero, %lo(tab_2_highlight)($at)
  lui   $a1, %hi(D_8002B5DC)
  lui   $at, %hi(tab_1_highlight)
  addiu $a1, %lo(D_8002B5DC) # addiu $a1, $a1, -0x4a24
  addiu $sp, $sp, -0x18
  sw    $zero, %lo(tab_1_highlight)($at)
  lui   $a0, %hi(cheat_available)
  lui   $a2, %hi(dword_CODE_bss_800697F0)
  sw    $ra, 0x14($sp)
  sw    $zero, ($a1)
  addiu $a2, %lo(dword_CODE_bss_800697F0) # addiu $a2, $a2, -0x6810
  addiu $a0, %lo(cheat_available) # addiu $a0, $a0, -0x69af
  li    $v1, 1
  li    $a3, 75
.L7F017BAC:
  lbu   $t6, ($a0)
  beql  $t6, $zero, .L7F017BD4
   addiu $v1, $v1, 1
  lw    $v0, ($a1)
  sll   $t7, $v0, 2
  addu  $t8, $a2, $t7
  sw    $v1, ($t8)
  addiu $t9, $v0, 1
  sw    $t9, ($a1)
  addiu $v1, $v1, 1
.L7F017BD4:
  bne   $v1, $a3, .L7F017BAC
   addiu $a0, $a0, 1
  jal   load_walletbond
   nop   
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel update_menu15_cheat
  addiu $sp, $sp, -0x30
  sw    $s1, 0x1c($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s0, 0x18($sp)
  lui   $s1, %hi(CHEAT_AVAILABLE_EXTRA_CHARS)
  sw    $ra, 0x2c($sp)
  move  $s3, $zero
  move  $s4, $zero
  addiu $s1, %lo(CHEAT_AVAILABLE_EXTRA_CHARS) # addiu $s1, $s1, -0x695f
  li    $s0, 1
  li    $s2, 75
.L7F017C28:
  lbu   $t6, ($s1)
  move  $a0, $s0
  beql  $t6, $zero, .L7F017C50
   addiu $s0, $s0, 1
  jal   cheatCheckIfMPCheat
   li    $s3, 1
  beql  $v0, $zero, .L7F017C50
   addiu $s0, $s0, 1
  li    $s4, 1
  addiu $s0, $s0, 1
.L7F017C50:
  bne   $s0, $s2, .L7F017C28
   addiu $s1, $s1, 1
  lui   $at, %hi(append_cheat_sp)
  sw    $s3, %lo(append_cheat_sp)($at)
  lw    $ra, 0x2c($sp)
  lui   $at, %hi(append_cheat_mp)
  sw    $s4, %lo(append_cheat_mp)($at)
  lw    $s4, 0x28($sp)
  lw    $s3, 0x24($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x30
");

asm(R"
.late_rodata
glabel menu15_aspect
.word 0x3FAAAAAB /*1.3333334;*/
glabel menu15_pageheight
.word 0x461C4000 /*10000.0;*/
.text
glabel interface_menu15_cheat
  addiu $sp, $sp, -0x18
  li    $at, 0x42700000 # 60.000000
  sw    $ra, 0x14($sp)
  mtc1  $at, $f12
  jal   setvideo_far
   nop   
  lui   $at, %hi(menu15_aspect)
  jal   video_related_21
   lwc1  $f12, %lo(menu15_aspect)($at)
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f12
  lui   $at, %hi(menu15_pageheight)
  jal   set_page_height
   lwc1  $f14, %lo(menu15_pageheight)($at)
  jal   set_video2_settings_offset_24
   move  $a0, $zero
  lui   $at, %hi(MP_menu_selected_option)
  sw    $zero, %lo(MP_menu_selected_option)($at)
  move  $a0, $zero
  jal   get_controller_buttons_held
   li    $a1, 40960
  bnez  $v0, .L7F017E04
   lui   $at, %hi(tab_3_highlight)
  sw    $zero, %lo(tab_3_highlight)($at)
  lui   $at, %hi(tab_2_highlight)
  sw    $zero, %lo(tab_2_highlight)($at)
  lui   $at, %hi(tab_1_highlight)
  sw    $zero, %lo(tab_1_highlight)($at)
  lui   $at, %hi(D_8002B5E0)
  jal   isontab3
   sw    $zero, %lo(D_8002B5E0)($at)
  beqz  $v0, .L7F017D1C
   lui   $a1, %hi(D_8002B5DC)
  li    $t6, 1
  lui   $at, %hi(tab_3_highlight)
  b     .L7F017E04
   sw    $t6, %lo(tab_3_highlight)($at)
.L7F017D1C:
  lw    $a1, %lo(D_8002B5DC)($a1)
  lui   $t1, %hi(D_8002B5E0) 
  slti  $at, $a1, 0xd
  bnez  $at, .L7F017D9C
   lui   $at, %hi(cursor_h_pos)
  lwc1  $f4, %lo(cursor_h_pos)($at)
  addiu $v1, $a1, -0xd
  trunc.w.s $f6, $f4
  mfc1  $t8, $f6
  nop   
  slti  $at, $t8, 0xdc
  bnez  $at, .L7F017D9C
   nop   
  bltz  $v1, .L7F017D9C
   lui   $at, %hi(cursor_v_pos)
  lwc1  $f8, %lo(cursor_v_pos)($at)
  sll   $v0, $v1, 2
  addu  $v0, $v0, $v1
  trunc.w.s $f10, $f8
  sll   $v0, $v0, 2
  addiu $v0, $v0, 0x35
  mfc1  $a0, $f10
  nop   
.L7F017D78:
  slt   $at, $a0, $v0
  bnez  $at, .L7F017D90
   addiu $t0, $v1, 0xc
  lui   $at, %hi(D_8002B5E0)
  b     .L7F017D9C
   sw    $t0, %lo(D_8002B5E0)($at)
.L7F017D90:
  addiu $v1, $v1, -1
  bgez  $v1, .L7F017D78
   addiu $v0, $v0, -0x14
.L7F017D9C:
  lw    $t1, %lo(D_8002B5E0)($t1)
  slti  $at, $a1, 0xd
  bnezl $t1, .L7F017E08
   move  $a0, $zero
  bnez  $at, .L7F017DBC
   addiu $v1, $a1, -1
  b     .L7F017DBC
   li    $v1, 11
.L7F017DBC:
  bltz  $v1, .L7F017E04
   lui   $at, %hi(cursor_v_pos)
  lwc1  $f16, %lo(cursor_v_pos)($at)
  sll   $v0, $v1, 2
  addu  $v0, $v0, $v1
  trunc.w.s $f18, $f16
  sll   $v0, $v0, 2
  addiu $v0, $v0, 0x35
  mfc1  $a0, $f18
  nop   
.L7F017DE4:
  slt   $at, $a0, $v0
  bnez  $at, .L7F017DF8
   lui   $at, %hi(D_8002B5E0)
  b     .L7F017E04
   sw    $v1, %lo(D_8002B5E0)($at)
.L7F017DF8:
  addiu $v1, $v1, -1
  bgez  $v1, .L7F017DE4
   addiu $v0, $v0, -0x14
.L7F017E04:
  move  $a0, $zero
.L7F017E08:
  jal   get_controller_buttons_pressed
   li    $a1, 40960
  beqz  $v0, .L7F017E5C
   move  $a0, $zero
  lui   $t3, %hi(tab_3_highlight) 
  lw    $t3, %lo(tab_3_highlight)($t3)
  lui   $a0, %hi(ptr_sfx_buf)
  li    $a1, 199
  beqz  $t3, .L7F017E40
   move  $a2, $zero
  li    $t4, 1
  lui   $at, %hi(tab_3_selected)
  b     .L7F017E4C
   sw    $t4, %lo(tab_3_selected)($at)
.L7F017E40:
  li    $t5, 1
  lui   $at, %hi(MP_menu_selected_option)
  sw    $t5, %lo(MP_menu_selected_option)($at)
.L7F017E4C:
  jal   play_sfx_a1
   lw    $a0, %lo(ptr_sfx_buf)($a0)
  b     .L7F017E88
   nop   
.L7F017E5C:
  jal   get_controller_buttons_pressed
   li    $a1, 16384
  beqz  $v0, .L7F017E88
   li    $t6, 1
  lui   $at, %hi(tab_3_selected)
  lui   $a0, %hi(ptr_sfx_buf)
  sw    $t6, %lo(tab_3_selected)($at)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 199
  jal   play_sfx_a1
   move  $a2, $zero
.L7F017E88:
  lui   $a0, %hi(ptr_folder_object_instance)
  jal   disable_all_switches
   lw    $a0, %lo(ptr_folder_object_instance)($a0)
  lui   $a0, %hi(ptr_folder_object_instance)
  lw    $a0, %lo(ptr_folder_object_instance)($a0)
  move  $a1, $zero
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lui   $a0, %hi(ptr_folder_object_instance)
  lw    $a0, %lo(ptr_folder_object_instance)($a0)
  li    $a1, 42
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  lui   $a0, %hi(ptr_folder_object_instance)
  lw    $a0, %lo(ptr_folder_object_instance)($a0)
  li    $a1, 6
  jal   set_item_visibility_in_objinstance
   li    $a2, 1
  jal   menu_control_stick_tracking
   nop   
  lui   $t7, %hi(tab_3_selected) 
  lw    $t7, %lo(tab_3_selected)($t7)
  li    $a0, 6
  lui   $t8, %hi(MP_menu_selected_option) 
  beqz  $t7, .L7F017F0C
   nop   
  jal   set_menu_to_mode
   move  $a1, $zero
  lui   $a0, %hi(gamemode)
  jal   set_menu_cursor_pos_to_setting
   lw    $a0, %lo(gamemode)($a0)
  b     .L7F017F50
   lw    $ra, 0x14($sp)
.L7F017F0C:
  lw    $t8, %lo(MP_menu_selected_option)($t8)
  lui   $t9, %hi(D_8002B5E0) 
  beql  $t8, $zero, .L7F017F50
   lw    $ra, 0x14($sp)
  lw    $t9, %lo(D_8002B5E0)($t9)
  lui   $v1, %hi(dword_CODE_bss_800697F0)
  lui   $t1, %hi(cheat_activated) 
  sll   $t0, $t9, 2
  addu  $v1, $v1, $t0
  lw    $v1, %lo(dword_CODE_bss_800697F0)($v1)
  addiu $t1, %lo(cheat_activated) # addiu $t1, $t1, -0x6960
  li    $t3, 1
  addu  $v0, $v1, $t1
  lbu   $t2, ($v0)
  subu  $t4, $t3, $t2
  sb    $t4, ($v0)
  lw    $ra, 0x14($sp)
.L7F017F50:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel constructor_menu15_cheat
  addiu $sp, $sp, -0x98
  sw    $ra, 0x5c($sp)
  sw    $fp, 0x58($sp)
  sw    $s7, 0x54($sp)
  sw    $s6, 0x50($sp)
  sw    $s5, 0x4c($sp)
  sw    $s4, 0x48($sp)
  sw    $s3, 0x44($sp)
  sw    $s2, 0x40($sp)
  sw    $s1, 0x3c($sp)
  sw    $s0, 0x38($sp)
  move  $a1, $zero
  move  $a2, $zero
  jal   set_setfillcolor
   move  $a3, $zero
  jal   insert_generic_fillrect
   move  $a0, $v0
  jal   sub_GAME_7F00D5E8
   move  $a0, $v0
  jal   microcode_constructor
   move  $a0, $v0
  lui   $v1, %hi(D_8002B5DC)
  lw    $v1, %lo(D_8002B5DC)($v1)
  move  $s4, $v0
  move  $fp, $zero
  slti  $at, $v1, 0xd
  bnez  $at, .L7F017FD4
   move  $s1, $v1
  b     .L7F017FD4
   li    $s1, 12
.L7F017FD4:
  blez  $s1, .L7F0181F0
   sll   $t6, $fp, 2
  sll   $s5, $fp, 2
  addu  $s5, $s5, $fp
  lui   $t7, %hi(dword_CODE_bss_800697F0) 
  addiu $t7, %lo(dword_CODE_bss_800697F0) # addiu $t7, $t7, -0x6810
  sll   $s5, $s5, 2
  lui   $s7, %hi(ptrFirstFontTableLarge) 
  lui   $s6, %hi(ptrSecondFontTableLarge)
  addiu $s6, %lo(ptrSecondFontTableLarge) # addiu $s6, $s6, 0xeb8
  addiu $s7, %lo(ptrFirstFontTableLarge) # addiu $s7, $s7, 0xeb4
  addiu $s5, $s5, 0x35
  addu  $s3, $t6, $t7
.L7F018008:
  jal   cheatGetMenuTextPointer
   lw    $a0, ($s3)
  lw    $t8, ($s7)
  move  $s2, $v0
  addiu $a0, $sp, 0x80
  addiu $a1, $sp, 0x7c
  move  $a2, $v0
  lw    $a3, ($s6)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t8, 0x10($sp)
  lui   $t9, %hi(D_8002B5E0) 
  lw    $t9, %lo(D_8002B5E0)($t9)
  li    $v0, 55
  sw    $v0, 0x88($sp)
  bne   $fp, $t9, .L7F018090
   sw    $s5, 0x84($sp)
  jal   isontab3
   nop   
  bnez  $v0, .L7F018090
   lw    $v1, 0x84($sp)
  lw    $v0, 0x88($sp)
  lw    $t0, 0x7c($sp)
  addiu $t1, $v1, 0xe
  li    $t2, 50
  addu  $a3, $v0, $t0
  addiu $a3, $a3, 5
  sw    $t2, 0x14($sp)
  sw    $t1, 0x10($sp)
  move  $a0, $s4
  addiu $a2, $v1, -1
  jal   microcode_constructor_related_to_menus
   addiu $a1, $v0, -2
  move  $s4, $v0
.L7F018090:
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s0, $v0, 0x10
  sra   $t3, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t3
  lw    $t4, ($s6)
  lw    $t5, ($s7)
  li    $t6, 255
  sw    $t6, 0x18($sp)
  move  $a0, $s4
  addiu $a1, $sp, 0x88
  addiu $a2, $sp, 0x84
  move  $a3, $s2
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t4, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t5, 0x14($sp)
  lw    $t7, ($s3)
  lui   $t8, %hi(cheat_activated)
  move  $s4, $v0
  addu  $t8, $t8, $t7
  lbu   $t8, %lo(cheat_activated)($t8)
  li    $s1, 40052
  beqz  $t8, .L7F01810C
   nop   
  b     .L7F01810C
   li    $s1, 40051
.L7F01810C:
  jal   get_textptr_for_textID
   move  $a0, $s1
  lw    $t9, ($s7)
  move  $s2, $v0
  addiu $a0, $sp, 0x80
  addiu $a1, $sp, 0x7c
  move  $a2, $v0
  lw    $a3, ($s6)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t9, 0x10($sp)
  lw    $t0, ($s3)
  lui   $t1, %hi(cheat_activated)
  li    $v0, 179
  addu  $t1, $t1, $t0
  lbu   $t1, %lo(cheat_activated)($t1)
  sw    $v0, 0x88($sp)
  sw    $s5, 0x84($sp)
  beqz  $t1, .L7F018168
   li    $s1, 255
  lui   $s1, (0xA00000FF >> 16) # lui $s1, 0xa000
  b     .L7F018168
   ori   $s1, (0xA00000FF & 0xFFFF) # ori $s1, $s1, 0xff
.L7F018168:
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s0, $v0, 0x10
  sra   $t2, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t2
  lw    $t3, ($s6)
  lw    $t4, ($s7)
  move  $a0, $s4
  addiu $a1, $sp, 0x88
  addiu $a2, $sp, 0x84
  move  $a3, $s2
  sw    $s1, 0x18($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t3, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t4, 0x14($sp)
  lui   $v1, %hi(D_8002B5DC)
  lw    $v1, %lo(D_8002B5DC)($v1)
  addiu $fp, $fp, 1
  addiu $s3, $s3, 4
  slti  $at, $v1, 0xd
  addiu $s5, $s5, 0x14
  bnez  $at, .L7F0181E0
   move  $s4, $v0
  b     .L7F0181E4
   li    $s1, 12
.L7F0181E0:
  move  $s1, $v1
.L7F0181E4:
  slt   $at, $fp, $s1
  bnez  $at, .L7F018008
   nop   
.L7F0181F0:
  lui   $s6, %hi(ptrSecondFontTableLarge)
  lui   $s7, %hi(ptrFirstFontTableLarge) 
  slti  $at, $v1, 0xd
  addiu $s7, %lo(ptrFirstFontTableLarge) # addiu $s7, $s7, 0xeb4
  bnez  $at, .L7F0183F8
   addiu $s6, %lo(ptrSecondFontTableLarge) # addiu $s6, $s6, 0xeb8
  addiu $t5, $v1, -0xc
  blez  $t5, .L7F0183F8
   move  $fp, $zero
  lui   $s3, %hi(dword_CODE_bss_800697F0)
  addiu $s3, %lo(dword_CODE_bss_800697F0) # addiu $s3, $s3, -0x6810
  li    $s5, 53
.L7F018220:
  jal   cheatGetMenuTextPointer
   lw    $a0, 0x30($s3)
  lw    $t6, ($s7)
  move  $s2, $v0
  addiu $a0, $sp, 0x80
  addiu $a1, $sp, 0x7c
  move  $a2, $v0
  lw    $a3, ($s6)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t6, 0x10($sp)
  lui   $t8, %hi(D_8002B5E0) 
  lw    $t8, %lo(D_8002B5E0)($t8)
  li    $v0, 220
  addiu $t7, $fp, 0xc
  sw    $v0, 0x88($sp)
  bne   $t7, $t8, .L7F0182AC
   sw    $s5, 0x84($sp)
  jal   isontab3
   nop   
  bnez  $v0, .L7F0182AC
   lw    $v1, 0x84($sp)
  lw    $v0, 0x88($sp)
  lw    $t9, 0x7c($sp)
  addiu $t0, $v1, 0xe
  li    $t1, 50
  addu  $a3, $v0, $t9
  addiu $a3, $a3, 5
  sw    $t1, 0x14($sp)
  sw    $t0, 0x10($sp)
  move  $a0, $s4
  addiu $a2, $v1, -1
  jal   microcode_constructor_related_to_menus
   addiu $a1, $v0, -2
  move  $s4, $v0
.L7F0182AC:
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s0, $v0, 0x10
  sra   $t2, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t2
  lw    $t3, ($s6)
  lw    $t4, ($s7)
  li    $t5, 255
  sw    $t5, 0x18($sp)
  move  $a0, $s4
  addiu $a1, $sp, 0x88
  addiu $a2, $sp, 0x84
  move  $a3, $s2
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t3, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t4, 0x14($sp)
  lw    $t6, 0x30($s3)
  lui   $t7, %hi(cheat_activated)
  move  $s4, $v0
  addu  $t7, $t7, $t6
  lbu   $t7, %lo(cheat_activated)($t7)
  li    $s1, 40052
  beqz  $t7, .L7F018328
   nop   
  b     .L7F018328
   li    $s1, 40051
.L7F018328:
  jal   get_textptr_for_textID
   move  $a0, $s1
  lw    $t8, ($s7)
  move  $s2, $v0
  addiu $a0, $sp, 0x80
  addiu $a1, $sp, 0x7c
  move  $a2, $v0
  lw    $a3, ($s6)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t8, 0x10($sp)
  lw    $t9, 0x30($s3)
  lui   $t0, %hi(cheat_activated)
  li    $v0, 344
  addu  $t0, $t0, $t9
  lbu   $t0, %lo(cheat_activated)($t0)
  sw    $v0, 0x88($sp)
  sw    $s5, 0x84($sp)
  beqz  $t0, .L7F018384
   li    $s1, 255
  lui   $s1, (0xA00000FF >> 16) # lui $s1, 0xa000
  b     .L7F018384
   ori   $s1, (0xA00000FF & 0xFFFF) # ori $s1, $s1, 0xff
.L7F018384:
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s0, $v0, 0x10
  sra   $t1, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t1
  lw    $t2, ($s6)
  lw    $t3, ($s7)
  move  $a0, $s4
  addiu $a1, $sp, 0x88
  addiu $a2, $sp, 0x84
  move  $a3, $s2
  sw    $s1, 0x18($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t2, 0x10($sp)
  jal   write_text_at_abs_coord
   sw    $t3, 0x14($sp)
  lui   $t4, %hi(D_8002B5DC) 
  lw    $t4, %lo(D_8002B5DC)($t4)
  addiu $fp, $fp, 1
  addiu $s3, $s3, 4
  addiu $t5, $t4, -0xc
  slt   $at, $fp, $t5
  addiu $s5, $s5, 0x14
  bnez  $at, .L7F018220
   move  $s4, $v0
.L7F0183F8:
  jal   add_tab3_previous
   move  $a0, $s4
  jal   load_draw_selected_icon_folder_select
   move  $a0, $v0
  lw    $ra, 0x5c($sp)
  lw    $s0, 0x38($sp)
  lw    $s1, 0x3c($sp)
  lw    $s2, 0x40($sp)
  lw    $s3, 0x44($sp)
  lw    $s4, 0x48($sp)
  lw    $s5, 0x4c($sp)
  lw    $s6, 0x50($sp)
  lw    $s7, 0x54($sp)
  lw    $fp, 0x58($sp)
  jr    $ra
   addiu $sp, $sp, 0x98
");

void init_menu16_nocontroller(void) {}

void update_menu16_nocontrollers(void) {}

void interface_menu16_nocontrollers(void) {}

#ifdef VERSION_US
asm(R"
glabel constructor_menu16_nocontrollers
  addiu $sp, $sp, -0x60
  sw    $ra, 0x34($sp)
  jal   get_num_controllers_plugged_in
   sw    $a0, 0x60($sp)
  andi  $t6, $v0, 8
  move  $t0, $zero
  beqz  $t6, .L7F018474
   move  $v1, $v0
  li    $t0, 1
.L7F018474:
  andi  $t7, $v1, 4
  beqz  $t7, .L7F018484
   andi  $t8, $v1, 2
  addiu $t0, $t0, 1
.L7F018484:
  beqz  $t8, .L7F018490
   lw    $a0, 0x60($sp)
  addiu $t0, $t0, 1
.L7F018490:
  jal   insert_imageDL
   sw    $t0, 0x44($sp)
  jal   microcode_constructor
   move  $a0, $v0
  lw    $t0, 0x44($sp)
  sw    $v0, 0x60($sp)
  li    $at, 1
  beql  $t0, $zero, .L7F0184CC
   li    $a0, 40054
  beq   $t0, $at, .L7F0184C8
   li    $at, 2
  beq   $t0, $at, .L7F0184C8
   li    $at, 3
  bne   $t0, $at, .L7F0184DC
.L7F0184C8:
   li    $a0, 40054
.L7F0184CC:
  jal   get_textptr_for_textID
   sw    $t0, 0x44($sp)
  lw    $t0, 0x44($sp)
  sw    $v0, 0x4c($sp)
.L7F0184DC:
  lui   $t9, %hi(ptrFirstFontTableLarge) 
  lw    $t9, %lo(ptrFirstFontTableLarge)($t9)
  lui   $a3, %hi(ptrSecondFontTableLarge)
  lw    $a3, %lo(ptrSecondFontTableLarge)($a3)
  addiu $a0, $sp, 0x5c
  addiu $a1, $sp, 0x58
  lw    $a2, 0x4c($sp)
  sw    $zero, 0x14($sp)
  sw    $t0, 0x44($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t9, 0x10($sp)
  lw    $t1, 0x58($sp)
  lw    $t5, 0x5c($sp)
  li    $t3, 220
  li    $t7, 153
  sra   $t2, $t1, 1
  sra   $t6, $t5, 1
  subu  $t4, $t3, $t2
  subu  $t8, $t7, $t6
  sw    $t4, 0x54($sp)
  jal   get_video2_settings_txtClipW
   sw    $t8, 0x50($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x3c($sp)
  lui   $t9, %hi(ptrSecondFontTableLarge) 
  lui   $t1, %hi(ptrFirstFontTableLarge) 
  lw    $t1, %lo(ptrFirstFontTableLarge)($t1)
  lw    $t9, %lo(ptrSecondFontTableLarge)($t9)
  lh    $t2, 0x3c($sp)
  li    $t3, -1
  sw    $t3, 0x18($sp)
  lw    $a0, 0x60($sp)
  addiu $a1, $sp, 0x54
  addiu $a2, $sp, 0x50
  lw    $a3, 0x4c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t1, 0x14($sp)
  sw    $t9, 0x10($sp)
  jal   en_text_write_stuff
   sw    $t2, 0x1c($sp)
  lw    $t0, 0x44($sp)
  sw    $v0, 0x60($sp)
  li    $at, 1
  beqz  $t0, .L7F0185B0
   nop   
  beq   $t0, $at, .L7F0185B0
   li    $at, 2
  beq   $t0, $at, .L7F0185B0
   li    $at, 3
  bne   $t0, $at, .L7F0185BC
   nop   
.L7F0185B0:
  jal   get_textptr_for_textID
   li    $a0, 40055
  sw    $v0, 0x4c($sp)
.L7F0185BC:
  lui   $t4, %hi(ptrFirstFontTableLarge) 
  lw    $t4, %lo(ptrFirstFontTableLarge)($t4)
  lui   $a3, %hi(ptrSecondFontTableLarge)
  lw    $a3, %lo(ptrSecondFontTableLarge)($a3)
  addiu $a0, $sp, 0x5c
  addiu $a1, $sp, 0x58
  lw    $a2, 0x4c($sp)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t4, 0x10($sp)
  lw    $t5, 0x58($sp)
  lw    $t9, 0x5c($sp)
  li    $t6, 220
  li    $t3, 177
  sra   $t7, $t5, 1
  sra   $t1, $t9, 1
  subu  $t8, $t6, $t7
  subu  $t2, $t3, $t1
  sw    $t8, 0x54($sp)
  jal   get_video2_settings_txtClipW
   sw    $t2, 0x50($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x3c($sp)
  lui   $t4, %hi(ptrSecondFontTableLarge) 
  lui   $t5, %hi(ptrFirstFontTableLarge) 
  lw    $t5, %lo(ptrFirstFontTableLarge)($t5)
  lw    $t4, %lo(ptrSecondFontTableLarge)($t4)
  lh    $t7, 0x3c($sp)
  li    $t6, -1
  sw    $t6, 0x18($sp)
  lw    $a0, 0x60($sp)
  addiu $a1, $sp, 0x54
  addiu $a2, $sp, 0x50
  lw    $a3, 0x4c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t5, 0x14($sp)
  sw    $t4, 0x10($sp)
  jal   en_text_write_stuff
   sw    $t7, 0x1c($sp)
  lw    $ra, 0x34($sp)
  addiu $sp, $sp, 0x60
  jr    $ra
   nop   
");

#ifdef VERSION_JP
asm(R"
glabel constructor_menu16_nocontrollers
  addiu $sp, $sp, -0x60
  sw    $ra, 0x34($sp)
  jal   get_num_controllers_plugged_in
   sw    $a0, 0x60($sp)
  andi  $t6, $v0, 8
  move  $t0, $zero
  beqz  $t6, .L7F018524
   move  $v1, $v0
  li    $t0, 1
.L7F018524:
  andi  $t7, $v1, 4
  beqz  $t7, .L7F018534
   andi  $t8, $v1, 2
  addiu $t0, $t0, 1
.L7F018534:
  beqz  $t8, .L7F018540
   lw    $a0, 0x60($sp)
  addiu $t0, $t0, 1
.L7F018540:
  jal   insert_imageDL
   sw    $t0, 0x44($sp)
  jal   microcode_constructor
   move  $a0, $v0
  lw    $t0, 0x44($sp)
  sw    $v0, 0x60($sp)
  li    $at, 1
  beqz  $t0, .L7F01857C
   li    $a0, 40054
  beq   $t0, $at, .L7F01857C
   li    $at, 2
  beq   $t0, $at, .L7F01857C
   li    $at, 3
  bne   $t0, $at, .L7F01858C
   nop   
.L7F01857C:
  jal   get_textptr_for_textID
   sw    $t0, 0x44($sp)
  lw    $t0, 0x44($sp)
  sw    $v0, 0x4c($sp)
.L7F01858C:
  lui   $t9, %hi(ptrFirstFontTableLarge) # $t9, 0x8004
  lw    $t9, %lo(ptrFirstFontTableLarge)($t9)
  lui   $a3, %hi(ptrSecondFontTableLarge) # $a3, 0x8004
  lw    $a3, %lo(ptrSecondFontTableLarge)($a3)
  addiu $a0, $sp, 0x5c
  addiu $a1, $sp, 0x58
  lw    $a2, 0x4c($sp)
  sw    $zero, 0x14($sp)
  sw    $t0, 0x44($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t9, 0x10($sp)
  lw    $t1, 0x58($sp)
  lw    $t5, 0x5c($sp)
  lui   $t9, %hi(j_text_trigger) # $t9, 0x8005
  lw    $t9, %lo(j_text_trigger)($t9)
  li    $t3, 220
  li    $t7, 153
  sra   $t2, $t1, 1
  sra   $t6, $t5, 1
  subu  $t4, $t3, $t2
  subu  $t8, $t7, $t6
  lw    $t0, 0x44($sp)
  sw    $t4, 0x54($sp)
  beqz  $t9, .L7F018660
   sw    $t8, 0x50($sp)
  jal   get_video2_settings_txtClipW
   sw    $t0, 0x44($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x3c($sp)
  lui   $t1, %hi(ptrSecondFontTableLarge) # $t1, 0x8004
  lui   $t3, %hi(ptrFirstFontTableLarge) # $t3, 0x8004
  lw    $t3, %lo(ptrFirstFontTableLarge)($t3)
  lw    $t1, %lo(ptrSecondFontTableLarge)($t1)
  lh    $t5, 0x3c($sp)
  lui   $t4, (0x008000FF >> 16) # lui $t4, 0x80
  ori   $t4, (0x008000FF & 0xFFFF) # ori $t4, $t4, 0xff
  li    $t2, -1
  sw    $t2, 0x18($sp)
  sw    $t4, 0x1c($sp)
  lw    $a0, 0x60($sp)
  addiu $a1, $sp, 0x54
  addiu $a2, $sp, 0x50
  lw    $a3, 0x4c($sp)
  sw    $v0, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $zero, 0x2c($sp)
  sw    $t3, 0x14($sp)
  sw    $t1, 0x10($sp)
  jal   jp_text_write_stuff
   sw    $t5, 0x20($sp)
  lw    $t0, 0x44($sp)
  b     .L7F0186C0
   sw    $v0, 0x60($sp)
.L7F018660:
  jal   get_video2_settings_txtClipW
   sw    $t0, 0x44($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x3c($sp)
  lui   $t7, %hi(ptrSecondFontTableLarge) # $t7, 0x8004
  lui   $t6, %hi(ptrFirstFontTableLarge) # $t6, 0x8004
  lw    $t6, %lo(ptrFirstFontTableLarge)($t6)
  lw    $t7, %lo(ptrSecondFontTableLarge)($t7)
  lh    $t9, 0x3c($sp)
  li    $t8, -1
  sw    $t8, 0x18($sp)
  lw    $a0, 0x60($sp)
  addiu $a1, $sp, 0x54
  addiu $a2, $sp, 0x50
  lw    $a3, 0x4c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t6, 0x14($sp)
  sw    $t7, 0x10($sp)
  jal   en_text_write_stuff
   sw    $t9, 0x1c($sp)
  lw    $t0, 0x44($sp)
  sw    $v0, 0x60($sp)
.L7F0186C0:
  beqz  $t0, .L7F0186E0
   li    $at, 1
  beq   $t0, $at, .L7F0186E0
   li    $at, 2
  beq   $t0, $at, .L7F0186E0
   li    $at, 3
  bne   $t0, $at, .L7F0186EC
   nop   
.L7F0186E0:
  jal   get_textptr_for_textID
   li    $a0, 40055
  sw    $v0, 0x4c($sp)
.L7F0186EC:
  lui   $t1, %hi(ptrFirstFontTableLarge) # $t1, 0x8004
  lw    $t1, %lo(ptrFirstFontTableLarge)($t1)
  lui   $a3, %hi(ptrSecondFontTableLarge) # $a3, 0x8004
  lw    $a3, %lo(ptrSecondFontTableLarge)($a3)
  addiu $a0, $sp, 0x5c
  addiu $a1, $sp, 0x58
  lw    $a2, 0x4c($sp)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t1, 0x10($sp)
  lw    $t3, 0x58($sp)
  lw    $t7, 0x5c($sp)
  lui   $t1, %hi(j_text_trigger) # $t1, 0x8005
  lw    $t1, %lo(j_text_trigger)($t1)
  li    $t4, 220
  li    $t8, 177
  sra   $t2, $t3, 1
  sra   $t6, $t7, 1
  subu  $t5, $t4, $t2
  subu  $t9, $t8, $t6
  sw    $t5, 0x54($sp)
  beqz  $t1, .L7F0187B4
   sw    $t9, 0x50($sp)
  jal   get_video2_settings_txtClipW
   nop   
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x3c($sp)
  lui   $t3, %hi(ptrSecondFontTableLarge) # $t3, 0x8004
  lui   $t4, %hi(ptrFirstFontTableLarge) # $t4, 0x8004
  lw    $t4, %lo(ptrFirstFontTableLarge)($t4)
  lw    $t3, %lo(ptrSecondFontTableLarge)($t3)
  lh    $t7, 0x3c($sp)
  lui   $t5, (0x008000FF >> 16) # lui $t5, 0x80
  ori   $t5, (0x008000FF & 0xFFFF) # ori $t5, $t5, 0xff
  li    $t2, -1
  sw    $t2, 0x18($sp)
  sw    $t5, 0x1c($sp)
  lw    $a0, 0x60($sp)
  addiu $a1, $sp, 0x54
  addiu $a2, $sp, 0x50
  lw    $a3, 0x4c($sp)
  sw    $v0, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $zero, 0x2c($sp)
  sw    $t4, 0x14($sp)
  sw    $t3, 0x10($sp)
  jal   jp_text_write_stuff
   sw    $t7, 0x20($sp)
  b     .L7F018810
   sw    $v0, 0x60($sp)
.L7F0187B4:
  jal   get_video2_settings_txtClipW
   nop   
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x3c($sp)
  lui   $t8, %hi(ptrSecondFontTableLarge) # $t8, 0x8004
  lui   $t6, %hi(ptrFirstFontTableLarge) # $t6, 0x8004
  lw    $t6, %lo(ptrFirstFontTableLarge)($t6)
  lw    $t8, %lo(ptrSecondFontTableLarge)($t8)
  lh    $t1, 0x3c($sp)
  li    $t9, -1
  sw    $t9, 0x18($sp)
  lw    $a0, 0x60($sp)
  addiu $a1, $sp, 0x54
  addiu $a2, $sp, 0x50
  lw    $a3, 0x4c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t6, 0x14($sp)
  sw    $t8, 0x10($sp)
  jal   en_text_write_stuff
   sw    $t1, 0x1c($sp)
  sw    $v0, 0x60($sp)
.L7F018810:
  lw    $ra, 0x34($sp)
  lw    $v0, 0x60($sp)
  addiu $sp, $sp, 0x60
  jr    $ra
   nop   
");
#endif

#endif

asm(R"
glabel do_extended_cast_display
  lui   $at, %hi(full_actor_intro)
  beqz  $a0, .L7F018688
   sw    $a0, %lo(full_actor_intro)($at)
  lui   $at, %hi(do_not_play_intro_movie)
  jr    $ra
   sw    $zero, %lo(do_not_play_intro_movie)($at)
.L7F018688:
  li    $t6, 1
  lui   $at, %hi(do_not_play_intro_movie)
  sw    $t6, %lo(do_not_play_intro_movie)($at)
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel jpt_intro_bond_head
 .word set_body_mp_choice_maybe
 .word set_body_default
 .word set_body_jungle
 .word set_body_snowsuit
 .word set_body_5
glabel D_80051B00
.word 0x40C90FDB /*6.2831855;*/
glabel D_80051B04
.word 0x4020D97C /*2.5132742;*/
glabel D_80051B08
.word 0x3FAAAAAB /*1.3333334;*/
glabel D_80051B0C
.word 0x40C90FDB /*6.2831855;*/
glabel D_80051B10
.word 0x3E4CCCCD /*0.2;*/
glabel D_80051B14
.word 0x3E4CCCCD /*0.2;*/
glabel D_80051B18
.word 0x3E4CCCCD /*0.2;*/
glabel D_80051B1C
.word 0x3E4CCCCD /*0.2;*/
glabel D_80051B20
.word 0x3D4CCCD0 /*0.050000012;*/
glabel D_80051B24
.word 0x3D4CCCD0 /*0.050000012;*/
glabel D_80051B28
.word 0x3F733333 /*0.94999999;*/
glabel D_80051B2C
.word 0x3F733333 /*0.94999999;*/
glabel D_80051B30
.word 0x3F733333 /*0.94999999;*/
glabel D_80051B34
.word 0x3D4CCCD0 /*0.050000012;*/
glabel D_80051B38
.word 0x40490FDB /*3.1415927;*/
glabel D_80051B3C
.word 0x3FAAAAAB /*1.3333334;*/
glabel D_80051B40
.word 0x461C4000 /*10000.0;*/
glabel D_80051B44
.word 0x3FAAAAAB /*1.3333334;*/
glabel D_80051B48
.word 0x3FAAAAAB /*1.3333334;*/
.text
glabel init_menu18_displaycast
  lui   $t6, %hi(ptr_logo_and_walletbond_DL) 
  lw    $t6, %lo(ptr_logo_and_walletbond_DL)($t6)
  addiu $sp, $sp, -0xb8
  lui   $t8, %hi(D_8002BA2C) 
  sw    $ra, 0x1c($sp)
  addiu $t8, %lo(D_8002BA2C) # addiu $t8, $t8, -0x45d4
  sw    $t6, 0xb4($sp)
  lw    $at, ($t8)
  addiu $t7, $sp, 0xa0
  lw    $t1, 4($t8)
  sw    $at, ($t7)
  lw    $at, 8($t8)
  sw    $t1, 4($t7)
  sw    $at, 8($t7)
  jal   get_random_value
   sw    $zero, 0x7c($sp)
  lui   $t3, %hi(full_actor_intro) 
  lw    $t3, %lo(full_actor_intro)($t3)
  andi  $t2, $v0, 1
  sw    $t2, 0x70($sp)
  beqz  $t3, .L7F018718
   lui   $t4, %hi(do_not_play_intro_movie) 
  lw    $t4, %lo(do_not_play_intro_movie)($t4)
  bnez  $t4, .L7F018718
   nop   
  jal   musicTrack1Vol
   li    $a0, 32767
  lui   $at, %hi(music1_playing)
  sw    $zero, %lo(music1_playing)($at)
  jal   musicTrack1Play
   li    $a0, 2
.L7F018718:
  lui   $a0, %hi(intro_animation_table)
  addiu $a0, %lo(intro_animation_table) # addiu $a0, $a0, -0x4744
  sll   $t5, $zero, 4
  addu  $t6, $a0, $t5
  lw    $t0, ($t6)
  lui   $v1, %hi(intro_animation_count)
  addiu $v1, %lo(intro_animation_count) # addiu $v1, $v1, -0x4a10
  sw    $zero, ($v1)
  bltz  $t0, .L7F018760
   move  $v0, $zero
  addiu $t9, $v0, 1
.L7F018744:
  sll   $t7, $t9, 4
  addu  $t8, $a0, $t7
  lw    $t1, ($t8)
  sw    $t9, ($v1)
  move  $v0, $t9
  bgezl $t1, .L7F018744
   addiu $t9, $v0, 1
.L7F018760:
  jal   get_random_value
   nop   
  lui   $v1, %hi(intro_animation_count)
  addiu $v1, %lo(intro_animation_count) # addiu $v1, $v1, -0x4a10
  lw    $t2, ($v1)
  lui   $t4, %hi(do_not_play_intro_movie) 
  lw    $t4, %lo(do_not_play_intro_movie)($t4)
  divu  $zero, $v0, $t2
  mfhi  $t3
  lui   $at, %hi(randomly_selected_intro_animation)
  sw    $t3, %lo(randomly_selected_intro_animation)($at)
  lui   $t7, %hi(randomly_selected_intro_animation) 
  sll   $t5, $t4, 2
  lw    $t7, %lo(randomly_selected_intro_animation)($t7)
  lui   $t6, %hi(intro_char_table) 
  addu  $t5, $t5, $t4
  sll   $t5, $t5, 2
  addiu $t6, %lo(intro_char_table) # addiu $t6, $t6, -0x4a00
  addu  $a0, $t5, $t6
  lw    $t0, ($a0)
  lui   $t1, %hi(intro_animation_table+12)
  sll   $t8, $t7, 4
  addu  $t1, $t1, $t8
  lw    $t9, 4($a0)
  lw    $t1, %lo(intro_animation_table+12)($t1)
  li    $at, 22
  bnez  $t2, .L7F0187D4
   nop   
  break 7
.L7F0187D4:
  sw    $t0, 0x8c($sp)
  move  $t2, $t0
  sw    $t9, 0x88($sp)
  bne   $t0, $at, .L7F01886C
   sw    $t1, 0x6c($sp)
  jal   get_random_value
   nop   
  li    $at, 5
  divu  $zero, $v0, $at
  mfhi  $t3
  sltiu $at, $t3, 5
  beqz  $at, .L7F0188C0
   sll   $t3, $t3, 2
  lui   $at, %hi(jpt_intro_bond_head)
  addu  $at, $at, $t3
  lw    $t3, %lo(jpt_intro_bond_head)($at)
  jr    $t3
   nop   
set_body_default:
  li    $t4, 23
  li    $t5, 75
  sw    $t5, 0x88($sp)
  b     .L7F0188C0
   sw    $t4, 0x8c($sp)
set_body_jungle:
  li    $t6, 24
  li    $t0, 75
  sw    $t0, 0x88($sp)
  b     .L7F0188C0
   sw    $t6, 0x8c($sp)
set_body_snowsuit:
  li    $t9, 25
  li    $t7, 75
  sw    $t7, 0x88($sp)
  b     .L7F0188C0
   sw    $t9, 0x8c($sp)
set_body_5:
  li    $t8, 5
  li    $t1, 78
  sw    $t1, 0x88($sp)
  b     .L7F0188C0
   sw    $t8, 0x8c($sp)
.L7F01886C:
  lw    $t2, 0x8c($sp)
  li    $at, 16
  lw    $t5, 0x8c($sp)
  bnel  $t2, $at, .L7F0188A0
   li    $at, 9
  jal   get_random_value
   nop   
  andi  $t3, $v0, 1
  beqz  $t3, .L7F0188C0
   li    $t4, 79
  b     .L7F0188C0
   sw    $t4, 0x8c($sp)
  li    $at, 9
.L7F0188A0:
  bnel  $t5, $at, .L7F0188C4
   lw    $t9, 0x88($sp)
  jal   get_random_value
   nop   
  andi  $t6, $v0, 1
  beqz  $t6, .L7F0188C0
   li    $t0, 8
  sw    $t0, 0x8c($sp)
set_body_mp_choice_maybe:
.L7F0188C0:
  lw    $t9, 0x88($sp)
.L7F0188C4:
  li    $at, -97
  bnel  $t9, $at, .L7F0188E0
   lw    $t7, 0xb4($sp)
  jal   get_random_head
   lw    $a0, 0x8c($sp)
  sw    $v0, 0x88($sp)
  lw    $t7, 0xb4($sp)
.L7F0188E0:
  lui   $v0, (0x00031160 >> 16) # lui $v0, 3
  ori   $v0, (0x00031160 & 0xFFFF) # ori $v0, $v0, 0x1160
  addu  $a0, $t7, $v0
  addiu $a0, $a0, 0x3f
  ori   $t8, $a0, 0x3f
  xori  $a0, $t8, 0x3f
  sw    $v0, 0xb0($sp)
  li    $a1, 440
  jal   zbufSetBuffer
   li    $a2, 330
  lui   $a2, (0x00019000 >> 16) # lui $a2, 1
  ori   $a2, (0x00019000 & 0xFFFF) # ori $a2, $a2, 0x9000
  addiu $a0, $sp, 0x90
  jal   sub_GAME_7F0CBAF4
   lw    $a1, 0xb4($sp)
  lw    $t2, 0x8c($sp)
  lui   $t4, %hi(c_item_entries) 
  lw    $a2, 0xb4($sp)
  sll   $t3, $t2, 2
  addu  $t3, $t3, $t2
  lw    $a3, 0xb0($sp)
  lui   $v1, (0x00019000 >> 16) # lui $v1, 1
  sll   $t3, $t3, 2
  addiu $t4, %lo(c_item_entries) # addiu $t4, $t4, -0x21f0
  ori   $v1, (0x00019000 & 0xFFFF) # ori $v1, $v1, 0x9000
  addu  $v0, $t3, $t4
  lw    $a0, ($v0)
  addiu $t5, $sp, 0x90
  addu  $a2, $a2, $v1
  subu  $a3, $a3, $v1
  sw    $a3, 0xb0($sp)
  sw    $a2, 0xb4($sp)
  sw    $t5, 0x10($sp)
  lw    $a1, 4($v0)
  sw    $v0, 0x24($sp)
  jal   load_object_fill_header
   sw    $a0, 0x80($sp)
  lw    $v0, 0x24($sp)
  jal   get_pc_buffer_remaining_value
   lw    $a0, 4($v0)
  addiu $v1, $v0, 0x3f
  lw    $t9, 0xb0($sp)
  lw    $t8, 0xb4($sp)
  ori   $t6, $v1, 0x3f
  lw    $t2, 0x88($sp)
  xori  $t0, $t6, 0x3f
  subu  $t7, $t9, $t0
  addu  $t1, $t8, $t0
  sw    $t7, 0xb0($sp)
  bltz  $t2, .L7F018A18
   sw    $t1, 0xb4($sp)
  sll   $t3, $t2, 2
  addu  $t3, $t3, $t2
  lui   $t4, %hi(c_item_entries) 
  addiu $t4, %lo(c_item_entries) # addiu $t4, $t4, -0x21f0
  sll   $t3, $t3, 2
  addu  $v0, $t3, $t4
  lw    $a0, ($v0)
  addiu $t5, $sp, 0x90
  sw    $t5, 0x10($sp)
  lw    $a1, 4($v0)
  sw    $v0, 0x24($sp)
  move  $a2, $t1
  move  $a3, $t7
  jal   load_object_fill_header
   sw    $a0, 0x7c($sp)
  lw    $v0, 0x24($sp)
  jal   get_pc_buffer_remaining_value
   lw    $a0, 4($v0)
  addiu $v1, $v0, 0x3f
  lw    $t9, 0xb0($sp)
  lw    $t2, 0xb4($sp)
  ori   $t6, $v1, 0x3f
  xori  $t0, $t6, 0x3f
  subu  $t8, $t9, $t0
  addu  $t3, $t2, $t0
  sw    $t8, 0xb0($sp)
  sw    $t3, 0xb4($sp)
.L7F018A18:
  lw    $a0, 0x8c($sp)
  lw    $a1, 0x88($sp)
  lw    $a2, 0x80($sp)
  lw    $a3, 0x7c($sp)
  jal   sub_GAME_7F0234A8
   sw    $zero, 0x10($sp)
  lui   $v1, %hi(objinstance)
  addiu $v1, %lo(objinstance) # addiu $v1, $v1, -0x4a0c
  lui   $a1, (0x3DCCCCCD >> 16) # lui $a1, 0x3dcc
  sw    $v0, ($v1)
  ori   $a1, (0x3DCCCCCD & 0xFFFF) # ori $a1, $a1, 0xcccd
  jal   set_obj_instance_controller_scale
   move  $a0, $v0
  lw    $t4, 0x6c($sp)
  li    $at, 2
  beqz  $t4, .L7F018C40
   nop   
  bne   $t4, $at, .L7F018AC0
   addiu $t8, $sp, 0x2c
  lui   $t7, %hi(random_rifles_in_intro) 
  addiu $t7, %lo(random_rifles_in_intro) # addiu $t7, $t7, -0x45c8
  lw    $at, ($t7)
  lw    $t6, 4($t7)
  addiu $t1, $sp, 0x54
  sw    $at, ($t1)
  sw    $t6, 4($t1)
  lw    $t6, 0xc($t7)
  lw    $at, 8($t7)
  sw    $t6, 0xc($t1)
  sw    $at, 8($t1)
  lw    $at, 0x10($t7)
  lw    $t6, 0x14($t7)
  sw    $at, 0x10($t1)
  jal   get_random_value
   sw    $t6, 0x14($t1)
  li    $at, 6
  divu  $zero, $v0, $at
  mfhi  $t0
  sll   $t9, $t0, 2
  addu  $v1, $sp, $t9
  b     .L7F018B14
   lw    $v1, 0x54($v1)
.L7F018AC0:
  lui   $t2, %hi(random_pistols_in_intro) 
  addiu $t2, %lo(random_pistols_in_intro) # addiu $t2, $t2, -0x45b0
  addiu $t4, $t2, 0x24
.L7F018ACC:
  lw    $at, ($t2)
  addiu $t2, $t2, 0xc
  addiu $t8, $t8, 0xc
  sw    $at, -0xc($t8)
  lw    $at, -8($t2)
  sw    $at, -8($t8)
  lw    $at, -4($t2)
  bne   $t2, $t4, .L7F018ACC
   sw    $at, -4($t8)
  lw    $at, ($t2)
  jal   get_random_value
   sw    $at, ($t8)
  li    $at, 10
  divu  $zero, $v0, $at
  mfhi  $t5
  sll   $t1, $t5, 2
  addu  $v1, $sp, $t1
  lw    $v1, 0x2c($v1)
.L7F018B14:
  li    $at, 190
  bnel  $v1, $at, .L7F018B38
   li    $at, 187
  jal   check_cradle_completed_any_folder
   sw    $v1, 0x84($sp)
  bnez  $v0, .L7F018B34
   lw    $v1, 0x84($sp)
  li    $v1, 191
.L7F018B34:
  li    $at, 187
.L7F018B38:
  bnel  $v1, $at, .L7F018B58
   li    $at, 208
  jal   check_aztec_completed_any_folder_secret_00
   sw    $v1, 0x84($sp)
  bnez  $v0, .L7F018B54
   lw    $v1, 0x84($sp)
  li    $v1, 191
.L7F018B54:
  li    $at, 208
.L7F018B58:
  bnel  $v1, $at, .L7F018B78
   sll   $t7, $v1, 2
  jal   check_egypt_completed_any_folder_00
   sw    $v1, 0x84($sp)
  bnez  $v0, .L7F018B74
   lw    $v1, 0x84($sp)
  li    $v1, 191
.L7F018B74:
  sll   $t7, $v1, 2
.L7F018B78:
  subu  $t7, $t7, $v1
  lui   $t6, %hi(PitemZ_entries) 
  addiu $t6, %lo(PitemZ_entries) # addiu $t6, $t6, -0x5dd8
  sll   $t7, $t7, 2
  addu  $v0, $t7, $t6
  lw    $a0, ($v0)
  addiu $t0, $sp, 0x90
  sw    $t0, 0x10($sp)
  lw    $a1, 4($v0)
  sw    $v0, 0x24($sp)
  lw    $a2, 0xb4($sp)
  lw    $a3, 0xb0($sp)
  jal   load_object_fill_header
   sw    $a0, 0x78($sp)
  lw    $v0, 0x24($sp)
  jal   get_pc_buffer_remaining_value
   lw    $a0, 4($v0)
  jal   set_objuse_flag_compute_grp_nums_set_obj_loaded
   lw    $a0, 0x78($sp)
  jal   get_obj_instance_controller_for_header
   lw    $a0, 0x78($sp)
  lui   $v1, %hi(ptrobjinstance)
  addiu $v1, %lo(ptrobjinstance) # addiu $v1, $v1, -0x4a08
  lui   $a1, (0x3DCCCCCD >> 16) # lui $a1, 0x3dcc
  sw    $v0, ($v1)
  ori   $a1, (0x3DCCCCCD & 0xFFFF) # ori $a1, $a1, 0xcccd
  jal   set_obj_instance_controller_scale
   move  $a0, $v0
  lui   $v1, %hi(ptrobjinstance)
  lui   $a2, %hi(objinstance)
  addiu $a2, %lo(objinstance) # addiu $a2, $a2, -0x4a0c
  addiu $v1, %lo(ptrobjinstance) # addiu $v1, $v1, -0x4a08
  lw    $t3, ($v1)
  lw    $t9, ($a2)
  li    $v0, 3
  sw    $t9, 0x18($t3)
  lw    $t4, 0x70($sp)
  beqz  $t4, .L7F018C1C
   nop   
  b     .L7F018C1C
   li    $v0, 5
.L7F018C1C:
  lw    $t2, ($a2)
  sll   $t1, $v0, 2
  lw    $t0, ($v1)
  lw    $t8, 8($t2)
  lw    $t5, 8($t8)
  addu  $t7, $t5, $t1
  lw    $t6, ($t7)
  b     .L7F018C54
   sw    $t6, 0x1c($t0)
.L7F018C40:
  lui   $v1, %hi(ptrobjinstance)
  addiu $v1, %lo(ptrobjinstance) # addiu $v1, $v1, -0x4a08
  lui   $a2, %hi(objinstance)
  addiu $a2, %lo(objinstance) # addiu $a2, $a2, -0x4a0c
  sw    $zero, ($v1)
.L7F018C54:
  lui   $a1, (0x3DCCCCCD >> 16) # lui $a1, 0x3dcc
  ori   $a1, (0x3DCCCCCD & 0xFFFF) # ori $a1, $a1, 0xcccd
  jal   sub_GAME_7F06CE84
   lw    $a0, ($a2)
  lui   $a0, %hi(objinstance)
  lw    $a0, %lo(objinstance)($a0)
  jal   setsuboffset
   addiu $a1, $sp, 0xa0
  lui   $a0, %hi(objinstance)
  lw    $a0, %lo(objinstance)($a0)
  jal   setsubroty
   li    $a1, 0
  lui   $a0, %hi(objinstance)
  lw    $a0, %lo(objinstance)($a0)
  lui   $a1, 0x3f00
  jal   sub_GAME_7F06FF18
   li    $a2, 0
  lui   $t9, %hi(randomly_selected_intro_animation) 
  lw    $t9, %lo(randomly_selected_intro_animation)($t9)
  lui   $t4, %hi(intro_animation_table) 
  addiu $t4, %lo(intro_animation_table) # addiu $t4, $t4, -0x4744
  sll   $t3, $t9, 4
  addu  $v0, $t3, $t4
  lw    $t2, ($v0)
  lwc1  $f4, 8($v0)
  mtc1  $zero, $f6
  lui   $a1, %hi(animation_table_ptrs1)
  sll   $t8, $t2, 2
  addu  $a1, $a1, $t8
  lui   $a0, %hi(objinstance)
  lw    $a0, %lo(objinstance)($a0)
  lw    $a1, %lo(animation_table_ptrs1)($a1)
  lw    $a3, 4($v0)
  lw    $a2, 0x70($sp)
  swc1  $f4, 0x10($sp)
  jal   sub_GAME_7F06FCA8
   swc1  $f6, 0x14($sp)
  lui   $at, %hi(menu_timer)
  jal   get_random_value
   sw    $zero, %lo(menu_timer)($at)
  mtc1  $v0, $f8
  bgez  $v0, .L7F018D10
   cvt.s.w $f10, $f8
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f16
  nop   
  add.s $f10, $f10, $f16
.L7F018D10:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f18
  li    $at, 0x42A00000 # 80.000000
  mtc1  $at, $f6
  mul.s $f4, $f10, $f18
  li    $at, 0x428C0000 # 70.000000
  mtc1  $at, $f16
  lui   $at, %hi(flt_CODE_bss_800695A4)
  mul.s $f8, $f4, $f6
  add.s $f10, $f8, $f16
  jal   get_random_value
   swc1  $f10, %lo(flt_CODE_bss_800695A4)($at)
  mtc1  $v0, $f18
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F018D5C
   cvt.s.w $f4, $f18
  mtc1  $at, $f6
  nop   
  add.s $f4, $f4, $f6
.L7F018D5C:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f8
  li    $at, 0x42A00000 # 80.000000
  mtc1  $at, $f10
  mul.s $f16, $f4, $f8
  li    $at, 0x428C0000 # 70.000000
  mtc1  $at, $f6
  lui   $at, %hi(flt_CODE_bss_800695A8)
  mul.s $f18, $f16, $f10
  add.s $f4, $f18, $f6
  jal   get_random_value
   swc1  $f4, %lo(flt_CODE_bss_800695A8)($at)
  mtc1  $v0, $f8
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F018DA8
   cvt.s.w $f16, $f8
  mtc1  $at, $f10
  nop   
  add.s $f16, $f16, $f10
.L7F018DA8:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f18
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f4
  mul.s $f6, $f16, $f18
  lui   $at, %hi(D_80051B00)
  lwc1  $f10, %lo(D_80051B00)($at)
  lui   $at, %hi(flt_CODE_bss_800695B0)
  sub.s $f8, $f6, $f4
  mul.s $f16, $f8, $f10
  jal   get_random_value
   swc1  $f16, %lo(flt_CODE_bss_800695B0)($at)
  mtc1  $v0, $f18
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F018DF4
   cvt.s.w $f6, $f18
  mtc1  $at, $f4
  nop   
  add.s $f6, $f6, $f4
.L7F018DF4:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f8
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f16
  mul.s $f10, $f6, $f8
  lui   $at, %hi(D_80051B04)
  lwc1  $f4, %lo(D_80051B04)($at)
  lui   $at, %hi(flt_CODE_bss_800695B4)
  sub.s $f18, $f10, $f16
  mul.s $f6, $f18, $f4
  jal   get_random_value
   swc1  $f6, %lo(flt_CODE_bss_800695B4)($at)
  mtc1  $v0, $f8
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F018E40
   cvt.s.w $f10, $f8
  mtc1  $at, $f16
  nop   
  add.s $f10, $f10, $f16
.L7F018E40:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f18
  li    $at, 0x43480000 # 200.000000
  mtc1  $at, $f6
  mul.s $f4, $f10, $f18
  li    $at, 0xC2C80000 # -100.000000
  mtc1  $at, $f16
  lui   $at, %hi(flt_CODE_bss_800695BC)
  mul.s $f8, $f4, $f6
  add.s $f10, $f8, $f16
  jal   get_random_value
   swc1  $f10, %lo(flt_CODE_bss_800695BC)($at)
  mtc1  $v0, $f18
  lui   $v1, %hi(flt_CODE_bss_800695E8)
  mtc1  $zero, $f0
  addiu $v1, %lo(flt_CODE_bss_800695E8) # addiu $v1, $v1, -0x6a18
  bgez  $v0, .L7F018E98
   cvt.s.w $f4, $f18
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f6
  nop   
  add.s $f4, $f4, $f6
.L7F018E98:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f8
  li    $at, 0x43480000 # 200.000000
  mtc1  $at, $f10
  mul.s $f16, $f4, $f8
  li    $at, 0xC2C80000 # -100.000000
  mtc1  $at, $f6
  lui   $at, %hi(flt_CODE_bss_800695C0)
  lw    $ra, 0x1c($sp)
  li    $t5, 1
  mul.s $f18, $f16, $f10
  add.s $f4, $f18, $f6
  swc1  $f4, %lo(flt_CODE_bss_800695C0)($at)
  lui   $at, %hi(flt_CODE_bss_800695A4)
  lwc1  $f8, %lo(flt_CODE_bss_800695A4)($at)
  lui   $at, %hi(flt_CODE_bss_800695A0)
  swc1  $f8, %lo(flt_CODE_bss_800695A0)($at)
  lui   $at, %hi(flt_CODE_bss_800695B0)
  lwc1  $f16, %lo(flt_CODE_bss_800695B0)($at)
  lui   $at, %hi(flt_CODE_bss_800695AC)
  swc1  $f16, %lo(flt_CODE_bss_800695AC)($at)
  lui   $at, %hi(flt_CODE_bss_800695BC)
  lwc1  $f10, %lo(flt_CODE_bss_800695BC)($at)
  lui   $at, %hi(flt_CODE_bss_800695B8)
  addiu $sp, $sp, 0xb8
  swc1  $f10, %lo(flt_CODE_bss_800695B8)($at)
  lui   $at, %hi(flt_CODE_bss_800695E4)
  sw    $t5, %lo(flt_CODE_bss_800695E4)($at)
  swc1  $f0, ($v1)
  swc1  $f0, 4($v1)
  jr    $ra
   swc1  $f0, 8($v1)
");

void update_menu18_displaycast(void) {
  if (objinstance != 0) {
    set_aircraft_obj_inst_scale_to_zero(objinstance);
  }
  if (ptrobjinstance != 0) {
    set_obj_instance_scale_to_zero(ptrobjinstance);
  }
}

asm(R"
glabel interface_menu18_displaycast
  addiu $sp, $sp, -0x28
  li    $at, 0x42380000 # 46.000000
  sw    $ra, 0x24($sp)
  mtc1  $at, $f12
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  jal   setvideo_far
   sw    $s0, 0x14($sp)
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f12
  li    $at, 0x44FA0000 # 2000.000000
  mtc1  $at, $f14
  jal   set_page_height
   nop   
  jal   set_video2_settings_offset_24
   li    $a0, 1
  lui   $at, %hi(D_80051B08)
  jal   video_related_21
   lwc1  $f12, %lo(D_80051B08)($at)
  li    $a0, 440
  jal   set_cur_player_screen_size
   li    $a1, 330
  li    $a0, 440
  jal   set_video2_width_height
   li    $a1, 330
  move  $a0, $zero
  jal   set_cur_player_viewport_size
   move  $a1, $zero
  move  $a0, $zero
  jal   set_video2_ulx_uly
   move  $a1, $zero
  lui   $v0, %hi(menu_timer)
  addiu $v0, %lo(menu_timer) # addiu $v0, $v0, -0x5734
  lui   $t7, %hi(clock_timer) 
  lw    $t7, %lo(clock_timer)($t7)
  lw    $t6, ($v0)
  lui   $s0, %hi(do_not_play_intro_movie)
  move  $a0, $zero
  addu  $t8, $t6, $t7
  slti  $at, $t8, 0xb5
  bnez  $at, .L7F0192E4
   sw    $t8, ($v0)
  addiu $s0, %lo(do_not_play_intro_movie) # addiu $s0, $s0, -0x4a18
  lw    $t0, ($s0)
  lui   $s1, %hi(intro_char_table)
  addiu $s1, %lo(intro_char_table) # addiu $s1, $s1, -0x4a00
  addiu $t1, $t0, 1
  sw    $t1, ($s0)
  li    $s3, 10000
  li    $s2, 20
.L7F01902C:
  lw    $v1, ($s0)
  lui   $t4, %hi(full_actor_intro) 
  multu $v1, $s2
  mflo  $t2
  addu  $v0, $s1, $t2
  lw    $t3, 0x10($v0)
  beql  $t3, $zero, .L7F019068
   lw    $t6, ($v0)
  lw    $t4, %lo(full_actor_intro)($t4)
  addiu $t5, $v1, 1
  bnezl $t4, .L7F019068
   lw    $t6, ($v0)
  b     .L7F01902C
   sw    $t5, ($s0)
  lw    $t6, ($v0)
.L7F019068:
  li    $at, 39
  bnel  $t6, $at, .L7F019098
   lw    $t9, ($s0)
  jal   check_aztec_completed_any_folder_secret_00
   nop   
  bnezl $v0, .L7F019098
   lw    $t9, ($s0)
  lw    $t7, ($s0)
  addiu $t8, $t7, 1
  b     .L7F01902C
   sw    $t8, ($s0)
  lw    $t9, ($s0)
.L7F019098:
  li    $at, 40
  multu $t9, $s2
  mflo  $t0
  addu  $t1, $s1, $t0
  lw    $t2, ($t1)
  bnel  $t2, $at, .L7F0190D8
   lw    $t5, ($s0)
  jal   check_aztec_completed_any_folder_secret_00
   nop   
  bnezl $v0, .L7F0190D8
   lw    $t5, ($s0)
  lw    $t3, ($s0)
  addiu $t4, $t3, 1
  b     .L7F01902C
   sw    $t4, ($s0)
  lw    $t5, ($s0)
.L7F0190D8:
  li    $at, 14
  multu $t5, $s2
  mflo  $t6
  addu  $t7, $s1, $t6
  lw    $t8, ($t7)
  bnel  $t8, $at, .L7F01913C
   lw    $t2, ($s0)
  jal   check_aztec_completed_any_folder_secret_00
   nop   
  bnezl $v0, .L7F01913C
   lw    $t2, ($s0)
  jal   get_random_value
   nop   
  divu  $zero, $v0, $s3
  mfhi  $t9
  bnez  $s3, .L7F019120
   nop   
  break 7
.L7F019120:
  beql  $t9, $zero, .L7F01913C
   lw    $t2, ($s0)
  lw    $t0, ($s0)
  addiu $t1, $t0, 1
  b     .L7F01902C
   sw    $t1, ($s0)
  lw    $t2, ($s0)
.L7F01913C:
  li    $at, 13
  multu $t2, $s2
  mflo  $t3
  addu  $t4, $s1, $t3
  lw    $t5, ($t4)
  bnel  $t5, $at, .L7F0191A0
   lw    $t9, ($s0)
  jal   check_aztec_completed_any_folder_secret_00
   nop   
  bnezl $v0, .L7F0191A0
   lw    $t9, ($s0)
  jal   get_random_value
   nop   
  divu  $zero, $v0, $s3
  mfhi  $t6
  bnez  $s3, .L7F019184
   nop   
  break 7
.L7F019184:
  beql  $t6, $zero, .L7F0191A0
   lw    $t9, ($s0)
  lw    $t7, ($s0)
  addiu $t8, $t7, 1
  b     .L7F01902C
   sw    $t8, ($s0)
  lw    $t9, ($s0)
.L7F0191A0:
  li    $at, 15
  multu $t9, $s2
  mflo  $t0
  addu  $t1, $s1, $t0
  lw    $t2, ($t1)
  bnel  $t2, $at, .L7F019204
   lw    $t6, ($s0)
  jal   check_egypt_completed_any_folder_00
   nop   
  bnezl $v0, .L7F019204
   lw    $t6, ($s0)
  jal   get_random_value
   nop   
  divu  $zero, $v0, $s3
  mfhi  $t3
  bnez  $s3, .L7F0191E8
   nop   
  break 7
.L7F0191E8:
  beql  $t3, $zero, .L7F019204
   lw    $t6, ($s0)
  lw    $t4, ($s0)
  addiu $t5, $t4, 1
  b     .L7F01902C
   sw    $t5, ($s0)
  lw    $t6, ($s0)
.L7F019204:
  li    $at, 12
  multu $t6, $s2
  mflo  $t7
  addu  $t8, $s1, $t7
  lw    $t9, ($t8)
  bnel  $t9, $at, .L7F019268
   lw    $v1, ($s0)
  jal   check_egypt_completed_any_folder_00
   nop   
  bnezl $v0, .L7F019268
   lw    $v1, ($s0)
  jal   get_random_value
   nop   
  divu  $zero, $v0, $s3
  mfhi  $t0
  bnez  $s3, .L7F01924C
   nop   
  break 7
.L7F01924C:
  beql  $t0, $zero, .L7F019268
   lw    $v1, ($s0)
  lw    $t1, ($s0)
  addiu $t2, $t1, 1
  b     .L7F01902C
   sw    $t2, ($s0)
  lw    $v1, ($s0)
.L7F019268:
  li    $a0, 24
  lui   $t6, %hi(full_actor_intro) 
  multu $v1, $s2
  mflo  $t3
  addu  $t4, $s1, $t3
  lw    $t5, ($t4)
  bgez  $t5, .L7F019290
   nop   
  sw    $zero, ($s0)
  move  $v1, $zero
.L7F019290:
  blez  $v1, .L7F0192A8
   nop   
  jal   set_menu_to_mode
   li    $a1, 1
  b     .L7F019310
   lw    $ra, 0x24($sp)
.L7F0192A8:
  lw    $t6, %lo(full_actor_intro)($t6)
  li    $a0, 7
  beqz  $t6, .L7F0192D4
   nop   
  jal   set_menu_to_mode
   li    $a1, 1
  jal   set_cursor_to_stage_solo
   li    $a0, 17
  lui   $at, %hi(full_actor_intro)
  b     .L7F01930C
   sw    $zero, %lo(full_actor_intro)($at)
.L7F0192D4:
  jal   select_ramrom_to_play
   nop   
  b     .L7F019310
   lw    $ra, 0x24($sp)
.L7F0192E4:
  jal   get_controller_buttons_pressed
   li    $a1, 65535
  beqz  $v0, .L7F01930C
   lui   $t7, %hi(full_actor_intro) 
  lw    $t7, %lo(full_actor_intro)($t7)
  li    $a0, 5
  bnezl $t7, .L7F019310
   lw    $ra, 0x24($sp)
  jal   set_menu_to_mode
   li    $a1, 1
.L7F01930C:
  lw    $ra, 0x24($sp)
.L7F019310:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
glabel constructor_menu18_displaycast
  addiu $sp, $sp, -0x250
  lui   $t6, %hi(D_8002BA78) 
  sw    $ra, 0x4c($sp)
  sw    $s4, 0x48($sp)
  sw    $s3, 0x44($sp)
  sw    $s2, 0x40($sp)
  sw    $s1, 0x3c($sp)
  sw    $s0, 0x38($sp)
  addiu $t6, %lo(D_8002BA78) # addiu $t6, $t6, -0x4588
  lw    $at, ($t6)
  addiu $t7, $sp, 0x244
  lw    $t4, 4($t6)
  sw    $at, ($t7)
  lw    $at, 8($t6)
  lui   $t5, %hi(D_8002BA84) 
  addiu $t5, %lo(D_8002BA84) # addiu $t5, $t5, -0x457c
  sw    $t4, 4($t7)
  sw    $at, 8($t7)
  lw    $at, ($t5)
  addiu $t9, $sp, 0x238
  lw    $t7, 4($t5)
  sw    $at, ($t9)
  lw    $at, 8($t5)
  lui   $t4, %hi(D_8002BA90) 
  addiu $t4, %lo(D_8002BA90) # addiu $t4, $t4, -0x4570
  sw    $t7, 4($t9)
  sw    $at, 8($t9)
  lw    $at, ($t4)
  addiu $t6, $sp, 0x22c
  lw    $t9, 4($t4)
  sw    $at, ($t6)
  lw    $at, 8($t4)
  lui   $t7, %hi(D_8002BA9C) 
  addiu $t7, %lo(D_8002BA9C) # addiu $t7, $t7, -0x4564
  sw    $t9, 4($t6)
  sw    $at, 8($t6)
  move  $s3, $a0
  addiu $t6, $t7, 0x3c
  addiu $t5, $sp, 0x1a8
.L7F0193C4:
  lw    $at, ($t7)
  addiu $t7, $t7, 0xc
  addiu $t5, $t5, 0xc
  sw    $at, -0xc($t5)
  lw    $at, -8($t7)
  sw    $at, -8($t5)
  lw    $at, -4($t7)
  bne   $t7, $t6, .L7F0193C4
   sw    $at, -4($t5)
  lw    $at, ($t7)
  lui   $v0, %hi(menu_timer)
  lui   $t9, %hi(D_8002BADC) 
  sw    $at, ($t5)
  lw    $v0, %lo(menu_timer)($v0)
  li    $at, 0x43340000 # 180.000000
  mtc1  $at, $f18
  mtc1  $v0, $f14
  addiu $t9, %lo(D_8002BADC) # addiu $t9, $t9, -0x4524
  lw    $at, ($t9)
  cvt.s.w $f0, $f14
  lw    $t6, 4($t9)
  addiu $t4, $sp, 0x134
  sw    $at, ($t4)
  lw    $at, 8($t9)
  sw    $t6, 4($t4)
  div.s $f16, $f0, $f18
  bltz  $v0, .L7F019440
   sw    $at, 8($t4)
  slti  $at, $v0, 0xb4
  bnezl $at, .L7F019450
   slti  $at, $v0, 0x1e
.L7F019440:
  mtc1  $zero, $f4
  b     .L7F0194A8
   swc1  $f4, 0x144($sp)
  slti  $at, $v0, 0x1e
.L7F019450:
  beqz  $at, .L7F01946C
   li    $at, 0x41F00000 # 30.000000
  mtc1  $at, $f10
  nop   
  div.s $f8, $f0, $f10
  b     .L7F0194A8
   swc1  $f8, 0x144($sp)
.L7F01946C:
  slti  $at, $v0, 0x97
  bnez  $at, .L7F019498
   li    $t7, 180
  subu  $t5, $t7, $v0
  mtc1  $t5, $f6
  li    $at, 0x41F00000 # 30.000000
  mtc1  $at, $f10
  cvt.s.w $f4, $f6
  div.s $f8, $f4, $f10
  b     .L7F0194A8
   swc1  $f8, 0x144($sp)
.L7F019498:
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  nop   
  swc1  $f6, 0x144($sp)
.L7F0194A8:
  move  $a0, $s3
  move  $a1, $zero
  move  $a2, $zero
  move  $a3, $zero
  jal   set_setfillcolor
   swc1  $f16, 0x148($sp)
  jal   insert_generic_fillrect
   move  $a0, $v0
  lui   $at, %hi(flt_CODE_bss_800695A4)
  lwc1  $f0, %lo(flt_CODE_bss_800695A4)($at)
  lui   $at, %hi(flt_CODE_bss_800695A8)
  lwc1  $f4, %lo(flt_CODE_bss_800695A8)($at)
  lwc1  $f16, 0x148($sp)
  lui   $s1, %hi(flt_CODE_bss_800695A0)
  sub.s $f10, $f4, $f0
  addiu $s1, %lo(flt_CODE_bss_800695A0) # addiu $s1, $s1, -0x6a60
  lui   $at, %hi(flt_CODE_bss_800695B0)
  lui   $s0, %hi(flt_CODE_bss_800695AC)
  mul.s $f8, $f10, $f16
  addiu $s0, %lo(flt_CODE_bss_800695AC) # addiu $s0, $s0, -0x6a54
  lui   $s2, %hi(flt_CODE_bss_800695B8)
  addiu $s2, %lo(flt_CODE_bss_800695B8) # addiu $s2, $s2, -0x6a48
  move  $s3, $v0
  add.s $f6, $f8, $f0
  swc1  $f6, ($s1)
  lwc1  $f2, %lo(flt_CODE_bss_800695B0)($at)
  lui   $at, %hi(flt_CODE_bss_800695B4)
  lwc1  $f4, %lo(flt_CODE_bss_800695B4)($at)
  lui   $at, %hi(flt_CODE_bss_800695BC)
  sub.s $f10, $f4, $f2
  mul.s $f8, $f10, $f16
  add.s $f6, $f8, $f2
  swc1  $f6, ($s0)
  lwc1  $f12, %lo(flt_CODE_bss_800695BC)($at)
  lui   $at, %hi(flt_CODE_bss_800695C0)
  lwc1  $f4, %lo(flt_CODE_bss_800695C0)($at)
  lwc1  $f14, ($s0)
  sub.s $f10, $f4, $f12
  mtc1  $zero, $f4
  mul.s $f8, $f10, $f16
  c.lt.s $f14, $f4
  add.s $f6, $f8, $f12
  bc1f  .L7F01956C
   swc1  $f6, ($s2)
  lui   $at, %hi(D_80051B0C)
  lwc1  $f10, %lo(D_80051B0C)($at)
  add.s $f8, $f14, $f10
  swc1  $f8, ($s0)
  lwc1  $f14, ($s0)
.L7F01956C:
  jal   sinf
   mov.s $f12, $f14
  swc1  $f0, 0x78($sp)
  jal   cosf
   lwc1  $f12, ($s0)
  lui   $at, %hi(D_80051B10)
  lwc1  $f6, %lo(D_80051B10)($at)
  lwc1  $f2, ($s1)
  lwc1  $f8, 0x78($sp)
  mul.s $f4, $f0, $f6
  lwc1  $f12, ($s0)
  mul.s $f10, $f4, $f2
  nop   
  mul.s $f6, $f2, $f8
  lwc1  $f8, ($s2)
  swc1  $f8, 0x248($sp)
  add.s $f4, $f10, $f6
  jal   cosf
   swc1  $f4, 0x244($sp)
  swc1  $f0, 0x78($sp)
  jal   sinf
   lwc1  $f12, ($s0)
  lwc1  $f2, ($s1)
  lwc1  $f10, 0x78($sp)
  lui   $at, %hi(D_80051B14)
  lwc1  $f4, %lo(D_80051B14)($at)
  mul.s $f6, $f2, $f10
  lwc1  $f12, ($s0)
  mul.s $f8, $f0, $f4
  nop   
  mul.s $f10, $f8, $f2
  sub.s $f4, $f6, $f10
  jal   cosf
   swc1  $f4, 0x24c($sp)
  lui   $at, %hi(D_80051B18)
  lwc1  $f8, %lo(D_80051B18)($at)
  lwc1  $f10, ($s1)
  lwc1  $f12, ($s0)
  mul.s $f6, $f0, $f8
  lwc1  $f8, 0x238($sp)
  mul.s $f4, $f6, $f10
  add.s $f6, $f8, $f4
  jal   sinf
   swc1  $f6, 0x238($sp)
  lui   $at, %hi(D_80051B1C)
  lwc1  $f8, %lo(D_80051B1C)($at)
  neg.s $f10, $f0
  lwc1  $f6, ($s1)
  mul.s $f4, $f10, $f8
  lwc1  $f8, 0x240($sp)
  li    $a0, 2
  mul.s $f10, $f4, $f6
  add.s $f4, $f8, $f10
  jal   sub_GAME_7F0BD6F8
   swc1  $f4, 0x240($sp)
  mtc1  $zero, $f0
  li    $at, 0x457A0000 # 4000.000000
  mtc1  $at, $f6
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  mfc1  $a2, $f0
  mfc1  $a3, $f0
  move  $s0, $v0
  addiu $a0, $sp, 0xe0
  move  $a1, $v0
  swc1  $f0, 0x14($sp)
  swc1  $f0, 0x18($sp)
  swc1  $f0, 0x1c($sp)
  swc1  $f0, 0x20($sp)
  swc1  $f0, 0x28($sp)
  swc1  $f6, 0x10($sp)
  jal   guLookAtReflect
   swc1  $f8, 0x24($sp)
  move  $v0, $s3
  addiu $s3, $s3, 8
  lui   $t3, (0xBC000002 >> 16) # lui $t3, 0xbc00
  lui   $t8, (0x80000040 >> 16) # lui $t8, 0x8000
  ori   $t8, (0x80000040 & 0xFFFF) # ori $t8, $t8, 0x40
  ori   $t3, (0xBC000002 & 0xFFFF) # ori $t3, $t3, 2
  move  $v1, $s3
  addiu $s3, $s3, 8
  sw    $t3, ($v0)
  sw    $t8, 4($v0)
  lui   $t4, (0x03860010 >> 16) # lui $t4, 0x386
  lui   $t9, %hi(D_8002A978) 
  addiu $t9, %lo(D_8002A978) # addiu $t9, $t9, -0x5688
  ori   $t4, (0x03860010 & 0xFFFF) # ori $t4, $t4, 0x10
  move  $a0, $s3
  addiu $s3, $s3, 8
  sw    $t4, ($v1)
  sw    $t9, 4($v1)
  lui   $t6, (0x03880010 >> 16) # lui $t6, 0x388
  lui   $t7, %hi(D_8002A970) 
  addiu $t7, %lo(D_8002A970) # addiu $t7, $t7, -0x5690
  ori   $t6, (0x03880010 & 0xFFFF) # ori $t6, $t6, 0x10
  move  $a1, $s3
  sw    $t6, ($a0)
  sw    $t7, 4($a0)
  lui   $t5, (0x03840010 >> 16) # lui $t5, 0x384
  ori   $t5, (0x03840010 & 0xFFFF) # ori $t5, $t5, 0x10
  sw    $t5, ($a1)
  sw    $s0, 4($a1)
  addiu $s3, $s3, 8
  move  $a3, $s3
  lui   $t3, (0x03820010 >> 16) # lui $t3, 0x382
  ori   $t3, (0x03820010 & 0xFFFF) # ori $t3, $t3, 0x10
  addiu $t8, $s0, 0x10
  lui   $s4, %hi(objinstance)
  addiu $s4, %lo(objinstance) # addiu $s4, $s4, -0x4a0c
  sw    $t8, 4($a3)
  sw    $t3, ($a3)
  lui   $a1, %hi(clock_timer)
  addiu $s3, $s3, 8
  lw    $a1, %lo(clock_timer)($a1)
  lw    $a0, ($s4)
  jal   sub_GAME_7F070AEC
   li    $a2, 1
  jal   set_80036084
   li    $a0, 1
  jal   sub_GAME_7F073FC8
   move  $a0, $zero
  jal   subcalcpos
   lw    $a0, ($s4)
  lui   $a3, %hi(ptrobjinstance)
  lw    $a3, %lo(ptrobjinstance)($a3)
  beqz  $a3, .L7F019790
   nop   
  lw    $t4, 8($a3)
  lw    $t9, 8($t4)
  lw    $a1, ($t9)
  beqz  $a1, .L7F019790
   nop   
  jal   extract_id_from_object_structure_microcode
   move  $a0, $a3
  sh    $zero, ($v0)
  lui   $a3, %hi(ptrobjinstance)
  lw    $a3, %lo(ptrobjinstance)($a3)
.L7F019790:
  beql  $a3, $zero, .L7F0197BC
   lw    $t5, ($s4)
  lw    $t6, 8($a3)
  lw    $t7, 8($t6)
  lw    $a1, 8($t7)
  beql  $a1, $zero, .L7F0197BC
   lw    $t5, ($s4)
  jal   extract_id_from_object_structure_microcode
   move  $a0, $a3
  sw    $zero, ($v0)
  lw    $t5, ($s4)
.L7F0197BC:
  lw    $t3, 8($t5)
  lh    $a0, 0xe($t3)
  sll   $t8, $a0, 6
  jal   sub_GAME_7F0BD714
   move  $a0, $t8
  addiu $s2, $sp, 0x1e8
  sw    $v0, 0x1b8($sp)
  jal   matrix_4x4_set_identity
   move  $a0, $s2
  sw    $s2, 0x1a8($sp)
  addiu $a0, $sp, 0x1a8
  jal   subcalcmatrices
   lw    $a1, ($s4)
  lw    $a0, ($s4)
  jal   getsuboffset
   addiu $a1, $sp, 0x128
  lui   $a2, %hi(flt_CODE_bss_800695E4)
  addiu $a2, %lo(flt_CODE_bss_800695E4) # addiu $a2, $a2, -0x6a1c
  lw    $v0, ($a2)
  move  $s1, $zero
  lui   $v1, %hi(clock_timer)
  beqz  $v0, .L7F019828
   nop   
  lwc1  $f10, 0x12c($sp)
  lui   $s0, %hi(flt_CODE_bss_800695E8)
  addiu $s0, %lo(flt_CODE_bss_800695E8) # addiu $s0, $s0, -0x6a18
  swc1  $f10, 4($s0)
.L7F019828:
  lui   $s0, %hi(flt_CODE_bss_800695E8)
  addiu $s0, %lo(flt_CODE_bss_800695E8) # addiu $s0, $s0, -0x6a18
  lwc1  $f4, ($s0)
  lwc1  $f6, 0x128($sp)
  lui   $at, %hi(global_timer_delta)
  swc1  $f4, 0x6c($sp)
  lwc1  $f8, 0x6c($sp)
  lwc1  $f4, 4($s0)
  lwc1  $f18, %lo(global_timer_delta)($at)
  sub.s $f10, $f6, $f8
  swc1  $f4, 0x64($sp)
  lwc1  $f8, 0x64($sp)
  lwc1  $f6, 0x12c($sp)
  lwc1  $f4, 8($s0)
  div.s $f2, $f10, $f18
  swc1  $f4, 0x60($sp)
  sub.s $f10, $f6, $f8
  lwc1  $f8, 0x60($sp)
  lwc1  $f6, 0x130($sp)
  div.s $f12, $f10, $f18
  sub.s $f10, $f6, $f8
  beqz  $v0, .L7F0198AC
   div.s $f14, $f10, $f18
  lui   $at, %hi(D_80051B20)
  lwc1  $f16, %lo(D_80051B20)($at)
  lui   $v0, %hi(flt_CODE_bss_80069608)
  addiu $v0, %lo(flt_CODE_bss_80069608) # addiu $v0, $v0, -0x69f8
  div.s $f4, $f2, $f16
  div.s $f6, $f12, $f16
  swc1  $f4, ($v0)
  div.s $f8, $f14, $f16
  swc1  $f6, 4($v0)
  swc1  $f8, 8($v0)
.L7F0198AC:
  lw    $v1, %lo(clock_timer)($v1)
  lui   $v0, %hi(flt_CODE_bss_80069608)
  lui   $at, %hi(D_80051B24)
  lwc1  $f16, %lo(D_80051B24)($at)
  addiu $v0, %lo(flt_CODE_bss_80069608) # addiu $v0, $v0, -0x69f8
  swc1  $f2, 0x134($sp)
  swc1  $f12, 0x138($sp)
  blez  $v1, .L7F019960
   swc1  $f14, 0x13c($sp)
  lui   $at, %hi(D_80051B28)
  lwc1  $f0, %lo(D_80051B28)($at)
  lwc1  $f4, ($v0)
  addiu $s1, $s1, 1
  slt   $at, $s1, $v1
  mul.s $f10, $f0, $f4
  beqz  $at, .L7F01992C
   lwc1  $f8, 4($v0)
.L7F0198F0:
  mul.s $f6, $f0, $f8
  add.s $f4, $f2, $f10
  lwc1  $f8, 8($v0)
  addiu $s1, $s1, 1
  slt   $at, $s1, $v1
  mul.s $f10, $f0, $f8
  swc1  $f4, ($v0)
  add.s $f6, $f12, $f6
  lwc1  $f4, ($v0)
  swc1  $f6, 4($v0)
  add.s $f6, $f14, $f10
  mul.s $f10, $f0, $f4
  lwc1  $f8, 4($v0)
  bnez  $at, .L7F0198F0
   swc1  $f6, 8($v0)
.L7F01992C:
  mul.s $f6, $f0, $f8
  lwc1  $f8, 8($v0)
  add.s $f4, $f2, $f10
  mul.s $f10, $f0, $f8
  swc1  $f4, ($v0)
  add.s $f6, $f12, $f6
  swc1  $f6, 4($v0)
  add.s $f6, $f14, $f10
  swc1  $f6, 8($v0)
  swc1  $f14, 0x13c($sp)
  swc1  $f12, 0x138($sp)
  swc1  $f2, 0x134($sp)
  move  $s1, $zero
.L7F019960:
  lwc1  $f4, ($v0)
  lwc1  $f8, 4($v0)
  lui   $v1, %hi(flt_CODE_bss_800695F8)
  mul.s $f6, $f4, $f16
  lwc1  $f4, 8($v0)
  addiu $v1, %lo(flt_CODE_bss_800695F8) # addiu $v1, $v1, -0x6a08
  mul.s $f10, $f8, $f16
  lwc1  $f8, 0x6c($sp)
  lw    $t4, ($s4)
  addiu $a1, $sp, 0x134
  swc1  $f6, ($v1)
  mul.s $f6, $f4, $f16
  swc1  $f10, 4($v1)
  lwc1  $f10, ($v1)
  mul.s $f4, $f10, $f18
  swc1  $f6, 8($v1)
  lwc1  $f10, 0x64($sp)
  add.s $f6, $f8, $f4
  lwc1  $f8, 4($v1)
  mul.s $f4, $f8, $f18
  swc1  $f6, ($s0)
  lwc1  $f8, 0x60($sp)
  add.s $f6, $f10, $f4
  lwc1  $f10, 8($v1)
  mul.s $f4, $f10, $f18
  swc1  $f6, 4($s0)
  add.s $f6, $f8, $f4
  swc1  $f6, 8($s0)
  jal   sub_GAME_7F058474
   lw    $a0, 0xc($t4)
  lwc1  $f10, 4($s0)
  lwc1  $f4, 8($s0)
  lui   $a2, %hi(flt_CODE_bss_800695E4)
  addiu $a2, %lo(flt_CODE_bss_800695E4) # addiu $a2, $a2, -0x6a1c
  lw    $t9, ($a2)
  lui   $at, %hi(D_80051B30)
  swc1  $f10, 0x64($sp)
  swc1  $f4, 0x60($sp)
  lwc1  $f2, 0x134($sp)
  lwc1  $f12, 0x138($sp)
  lwc1  $f14, 0x13c($sp)
  lwc1  $f18, ($s0)
  lwc1  $f8, 0x64($sp)
  lwc1  $f6, 0x60($sp)
  lwc1  $f0, %lo(D_80051B30)($at)
  lui   $at, %hi(D_80051B34)
  lwc1  $f16, %lo(D_80051B34)($at)
  sub.s $f2, $f2, $f18
  sub.s $f12, $f12, $f8
  beqz  $t9, .L7F019A50
   sub.s $f14, $f14, $f6
  div.s $f10, $f2, $f16
  lui   $v0, %hi(flt_CODE_bss_800695D8)
  addiu $v0, %lo(flt_CODE_bss_800695D8) # addiu $v0, $v0, -0x6a28
  sw    $zero, ($a2)
  div.s $f8, $f12, $f16
  swc1  $f10, ($v0)
  div.s $f4, $f14, $f16
  swc1  $f8, 4($v0)
  swc1  $f4, 8($v0)
.L7F019A50:
  lui   $v1, %hi(clock_timer)
  lw    $v1, %lo(clock_timer)($v1)
  lui   $v0, %hi(flt_CODE_bss_800695D8)
  addiu $v0, %lo(flt_CODE_bss_800695D8) # addiu $v0, $v0, -0x6a28
  blezl $v1, .L7F019AE8
   lwc1  $f10, ($v0)
  lwc1  $f4, ($v0)
  addiu $s1, $s1, 1
  slt   $at, $s1, $v1
  mul.s $f8, $f0, $f4
  beqz  $at, .L7F019ABC
   lwc1  $f10, 4($v0)
.L7F019A80:
  mul.s $f6, $f0, $f10
  add.s $f4, $f2, $f8
  lwc1  $f10, 8($v0)
  addiu $s1, $s1, 1
  slt   $at, $s1, $v1
  mul.s $f8, $f0, $f10
  swc1  $f4, ($v0)
  add.s $f6, $f12, $f6
  lwc1  $f4, ($v0)
  swc1  $f6, 4($v0)
  add.s $f6, $f14, $f8
  mul.s $f8, $f0, $f4
  lwc1  $f10, 4($v0)
  bnez  $at, .L7F019A80
   swc1  $f6, 8($v0)
.L7F019ABC:
  mul.s $f6, $f0, $f10
  lwc1  $f10, 8($v0)
  add.s $f4, $f2, $f8
  mul.s $f8, $f0, $f10
  swc1  $f4, ($v0)
  add.s $f6, $f12, $f6
  swc1  $f6, 4($v0)
  add.s $f6, $f14, $f8
  swc1  $f6, 8($v0)
  move  $s1, $zero
  lwc1  $f10, ($v0)
.L7F019AE8:
  lwc1  $f4, 4($v0)
  lui   $v1, %hi(flt_CODE_bss_800695C8)
  mul.s $f8, $f10, $f16
  lwc1  $f10, 8($v0)
  addiu $v1, %lo(flt_CODE_bss_800695C8) # addiu $v1, $v1, -0x6a38
  mul.s $f6, $f4, $f16
  li    $at, 0x41200000 # 10.000000
  lwc1  $f0, 0x23c($sp)
  move  $a0, $s2
  swc1  $f8, ($v1)
  mul.s $f8, $f10, $f16
  lwc1  $f4, ($v1)
  swc1  $f6, 4($v1)
  lwc1  $f10, 4($v1)
  lwc1  $f6, 0x64($sp)
  add.s $f2, $f18, $f4
  mtc1  $at, $f4
  swc1  $f8, 8($v1)
  add.s $f8, $f6, $f10
  lwc1  $f10, 0x60($sp)
  swc1  $f6, 0x50($sp)
  li    $at, 0x42520000 # 52.500000
  sub.s $f12, $f8, $f4
  lwc1  $f8, 8($v1)
  lwc1  $f4, 0x238($sp)
  swc1  $f10, 0x54($sp)
  add.s $f14, $f10, $f8
  lwc1  $f10, 0x50($sp)
  lwc1  $f6, 0x244($sp)
  add.s $f8, $f4, $f2
  lwc1  $f4, 0x240($sp)
  swc1  $f14, 0x13c($sp)
  add.s $f6, $f6, $f18
  swc1  $f8, 0x238($sp)
  swc1  $f8, 0x50($sp)
  mtc1  $at, $f8
  add.s $f4, $f4, $f14
  swc1  $f6, 0x244($sp)
  mfc1  $a1, $f6
  add.s $f10, $f10, $f8
  lwc1  $f8, 0x248($sp)
  swc1  $f4, 0x240($sp)
  swc1  $f4, 0x58($sp)
  add.s $f8, $f8, $f10
  lwc1  $f10, 0x24c($sp)
  lwc1  $f4, 0x54($sp)
  add.s $f0, $f0, $f12
  swc1  $f8, 0x248($sp)
  mfc1  $a2, $f8
  add.s $f10, $f10, $f4
  lwc1  $f4, 0x50($sp)
  lwc1  $f8, 0x22c($sp)
  lwc1  $f6, 0x58($sp)
  swc1  $f10, 0x24c($sp)
  mfc1  $a3, $f10
  swc1  $f4, 0x10($sp)
  lwc1  $f4, 0x234($sp)
  lwc1  $f10, 0x230($sp)
  swc1  $f0, 0x14($sp)
  swc1  $f0, 0x23c($sp)
  swc1  $f12, 0x138($sp)
  swc1  $f2, 0x134($sp)
  swc1  $f8, 0x1c($sp)
  swc1  $f6, 0x18($sp)
  swc1  $f4, 0x24($sp)
  jal   sub_GAME_7F059694
   swc1  $f10, 0x20($sp)
  lw    $t6, ($s4)
  sw    $s2, 0x1a8($sp)
  lw    $t7, 8($t6)
  lh    $a0, 0xe($t7)
  sll   $t5, $a0, 6
  jal   sub_GAME_7F0BD714
   move  $a0, $t5
  sw    $v0, 0x1b8($sp)
  addiu $a0, $sp, 0x1a8
  jal   subcalcmatrices
   lw    $a1, ($s4)
  lui   $a3, %hi(ptrobjinstance)
  lw    $a3, %lo(ptrobjinstance)($a3)
  beql  $a3, $zero, .L7F019CC0
   li    $t8, 7
  lw    $a0, ($s4)
  lw    $a1, 0x1c($a3)
  jal   sub_GAME_7F06C660
   move  $a2, $zero
  lw    $t8, ($s4)
  sw    $v0, 0x1a8($sp)
  lui   $a3, %hi(ptrobjinstance)
  lw    $t4, 8($t8)
  lw    $a3, %lo(ptrobjinstance)($a3)
  addiu $s2, $sp, 0x160
  lw    $t9, 8($t4)
  lw    $t3, 0x1c($a3)
  move  $a1, $s2
  lw    $t6, 0x14($t9)
  lui   $at, %hi(D_80051B38)
  bnel  $t3, $t6, .L7F019C98
   lw    $t7, 8($a3)
  jal   sub_GAME_7F058688
   lwc1  $f12, %lo(D_80051B38)($at)
  lw    $a0, 0x1a8($sp)
  jal   matrix_4x4_multiply_in_place
   move  $a1, $s2
  lui   $a3, %hi(ptrobjinstance)
  lw    $a3, %lo(ptrobjinstance)($a3)
  sw    $s2, 0x1a8($sp)
  lw    $t7, 8($a3)
.L7F019C98:
  lh    $a0, 0xe($t7)
  sll   $t5, $a0, 6
  jal   sub_GAME_7F0BD714
   move  $a0, $t5
  lui   $a1, %hi(ptrobjinstance)
  sw    $v0, 0x1b8($sp)
  lw    $a1, %lo(ptrobjinstance)($a1)
  jal   instcalcmatrices
   addiu $a0, $sp, 0x1a8
  li    $t8, 7
.L7F019CC0:
  li    $t4, 1
  li    $t9, 3
  addiu $s2, $sp, 0x160
  sw    $t8, 0x1d8($sp)
  sw    $t4, 0x1ac($sp)
  sw    $s3, 0x1b4($sp)
  sw    $t9, 0x1b0($sp)
  addiu $a0, $sp, 0x1a8
  jal   subdraw
   lw    $a1, ($s4)
  lui   $a3, %hi(ptrobjinstance)
  lw    $a3, %lo(ptrobjinstance)($a3)
  beqz  $a3, .L7F019D00
   addiu $a0, $sp, 0x1a8
  jal   subdraw
   move  $a1, $a3
.L7F019D00:
  lw    $s3, 0x1b4($sp)
  jal   set_80036084
   move  $a0, $zero
  lw    $v0, ($s4)
  lw    $t3, 8($v0)
  lh    $t6, 0xe($t3)
  blez  $t6, .L7F019D68
   move  $s0, $zero
  lw    $t7, 0xc($v0)
.L7F019D24:
  move  $a1, $s2
  jal   matrix_4x4_copy
   addu  $a0, $t7, $s0
  lw    $t5, ($s4)
  sll   $t4, $s1, 6
  move  $a0, $s2
  lw    $t8, 0xc($t5)
  jal   sub_GAME_7F058C9C
   addu  $a1, $t8, $t4
  lw    $v0, ($s4)
  addiu $s1, $s1, 1
  addiu $s0, $s0, 0x40
  lw    $t9, 8($v0)
  lh    $t3, 0xe($t9)
  slt   $at, $s1, $t3
  bnezl $at, .L7F019D24
   lw    $t7, 0xc($v0)
.L7F019D68:
  lui   $a3, %hi(ptrobjinstance)
  lw    $a3, %lo(ptrobjinstance)($a3)
  beql  $a3, $zero, .L7F019DE4
   move  $v0, $s3
  lw    $t6, 8($a3)
  move  $s1, $zero
  move  $s0, $zero
  lh    $t7, 0xe($t6)
  blezl $t7, .L7F019DE4
   move  $v0, $s3
  lw    $t5, 0xc($a3)
.L7F019D94:
  move  $a1, $s2
  jal   matrix_4x4_copy
   addu  $a0, $t5, $s0
  lui   $t8, %hi(ptrobjinstance) 
  lw    $t8, %lo(ptrobjinstance)($t8)
  sll   $t9, $s1, 6
  move  $a0, $s2
  lw    $t4, 0xc($t8)
  jal   sub_GAME_7F058C9C
   addu  $a1, $t4, $t9
  lui   $a3, %hi(ptrobjinstance)
  lw    $a3, %lo(ptrobjinstance)($a3)
  addiu $s1, $s1, 1
  addiu $s0, $s0, 0x40
  lw    $t3, 8($a3)
  lh    $t6, 0xe($t3)
  slt   $at, $s1, $t6
  bnezl $at, .L7F019D94
   lw    $t5, 0xc($a3)
  move  $v0, $s3
.L7F019DE4:
  lui   $t5, (0x006E0528 >> 16) # lui $t5, 0x6e
  ori   $t5, (0x006E0528 & 0xFFFF) # ori $t5, $t5, 0x528
  lui   $t7, 0xed00
  sw    $t7, ($v0)
  sw    $t5, 4($v0)
  addiu $s3, $s3, 8
  lui   $a3, 0xe700
  addiu $a0, $s3, 8
  sw    $a3, ($s3)
  sw    $zero, 4($s3)
  lui   $t8, (0xBA001402 >> 16) # lui $t8, 0xba00
  ori   $t8, (0xBA001402 & 0xFFFF) # ori $t8, $t8, 0x1402
  sw    $t8, ($a0)
  sw    $zero, 4($a0)
  addiu $a1, $a0, 8
  lui   $t0, (0xBA000602 >> 16) # lui $t0, 0xba00
  ori   $t0, (0xBA000602 & 0xFFFF) # ori $t0, $t0, 0x602
  addiu $a2, $a1, 8
  li    $t4, 192
  lui   $t1, (0xBA001301 >> 16) # lui $t1, 0xba00
  sw    $t4, 4($a1)
  sw    $t0, ($a1)
  ori   $t1, (0xBA001301 & 0xFFFF) # ori $t1, $t1, 0x1301
  addiu $v0, $a2, 8
  sw    $t1, ($a2)
  sw    $zero, 4($a2)
  lui   $t9, (0xB9000002 >> 16) # lui $t9, 0xb900
  ori   $t9, (0xB9000002 & 0xFFFF) # ori $t9, $t9, 2
  addiu $v1, $v0, 8
  lui   $t2, (0xBA001001 >> 16) # lui $t2, 0xba00
  sw    $t9, ($v0)
  sw    $zero, 4($v0)
  ori   $t2, (0xBA001001 & 0xFFFF) # ori $t2, $t2, 0x1001
  addiu $s3, $v1, 8
  sw    $t2, ($v1)
  sw    $zero, 4($v1)
  move  $a0, $s3
  lui   $t3, (0xBA000C02 >> 16) # lui $t3, 0xba00
  ori   $t3, (0xBA000C02 & 0xFFFF) # ori $t3, $t3, 0xc02
  li    $t6, 8192
  sw    $t6, 4($a0)
  sw    $t3, ($a0)
  addiu $a1, $s3, 8
  lui   $t7, (0xBA000903 >> 16) # lui $t7, 0xba00
  ori   $t7, (0xBA000903 & 0xFFFF) # ori $t7, $t7, 0x903
  sw    $t7, ($a1)
  addiu $a2, $a1, 8
  li    $t5, 3072
  sw    $t5, 4($a1)
  lui   $t8, (0xBA000E02 >> 16) # lui $t8, 0xba00
  ori   $t8, (0xBA000E02 & 0xFFFF) # ori $t8, $t8, 0xe02
  addiu $v0, $a2, 8
  sw    $t8, ($a2)
  sw    $zero, 4($a2)
  lui   $t9, (0x00504340 >> 16) # lui $t9, 0x50
  lui   $t4, (0xB900031D >> 16) # lui $t4, 0xb900
  ori   $t4, (0xB900031D & 0xFFFF) # ori $t4, $t4, 0x31d
  ori   $t9, (0x00504340 & 0xFFFF) # ori $t9, $t9, 0x4340
  addiu $v1, $v0, 8
  sw    $t9, 4($v0)
  sw    $t4, ($v0)
  lui   $t3, (0xFCFFFFFF >> 16) # lui $t3, 0xfcff
  lui   $t6, (0xFFFDF6FB >> 16) # lui $t6, 0xfffd
  ori   $t6, (0xFFFDF6FB & 0xFFFF) # ori $t6, $t6, 0xf6fb
  ori   $t3, (0xFCFFFFFF & 0xFFFF) # ori $t3, $t3, 0xffff
  sw    $t3, ($v1)
  sw    $t6, 4($v1)
  addiu $a0, $v1, 8
  lui   $t7, 0xfa00
  sw    $t7, ($a0)
  li    $at, 0x437F0000 # 255.000000
  mtc1  $at, $f6
  lwc1  $f8, 0x144($sp)
  li    $t4, 255
  addiu $s3, $a0, 8
  mul.s $f0, $f6, $f8
  lui   $t6, (0xF66E0528 >> 16) # lui $t6, 0xf66e
  ori   $t6, (0xF66E0528 & 0xFFFF) # ori $t6, $t6, 0x528
  addiu $a2, $s3, 8
  addiu $v0, $a2, 8
  addiu $v1, $v0, 8
  li    $t7, 64
  trunc.w.s $f10, $f0
  lui   $t5, 8
  addiu $a1, $v1, 8
  mfc1  $t8, $f10
  nop   
  subu  $t9, $t4, $t8
  andi  $t3, $t9, 0xff
  sw    $t3, 4($a0)
  sw    $zero, 4($s3)
  sw    $t6, ($s3)
  sw    $zero, 4($a2)
  sw    $a3, ($a2)
  sw    $t7, 4($v0)
  sw    $t0, ($v0)
  sw    $t5, 4($v1)
  sw    $t1, ($v1)
  lui   $t4, 1
  sw    $t4, 4($a1)
  sw    $t2, ($a1)
  addiu $a0, $a1, 8
  jal   microcode_constructor
   swc1  $f0, 0x70($sp)
  lui   $t8, %hi(full_actor_intro) 
  lw    $t8, %lo(full_actor_intro)($t8)
  move  $s3, $v0
  bnez  $t8, .L7F01A110
   lui   $t9, %hi(do_not_play_intro_movie) 
  lw    $t9, %lo(do_not_play_intro_movie)($t9)
  lui   $a0, %hi(intro_char_table+8)
  sll   $t3, $t9, 2
  addu  $t3, $t3, $t9
  sll   $t3, $t3, 2
  addu  $a0, $a0, $t3
  jal   get_textptr_for_textID
   lhu   $a0, %lo(intro_char_table+8)($a0)
  lui   $t6, %hi(ptrFirstFontTableLarge) 
  lw    $t6, %lo(ptrFirstFontTableLarge)($t6)
  lui   $s4, %hi(ptrSecondFontTableLarge)
  addiu $s4, %lo(ptrSecondFontTableLarge) # addiu $s4, $s4, 0xeb8
  move  $s1, $v0
  lw    $a3, ($s4)
  addiu $a0, $sp, 0x150
  addiu $a1, $sp, 0x154
  move  $a2, $v0
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t6, 0x10($sp)
  lw    $v0, 0x154($sp)
  lw    $t8, 0x150($sp)
  li    $t5, 315
  bgez  $v0, .L7F01A004
   sra   $t7, $v0, 1
  addiu $at, $v0, 1
  sra   $t7, $at, 1
.L7F01A004:
  subu  $a1, $t5, $t7
  li    $t4, 108
  addu  $a3, $a1, $v0
  addiu $t9, $t8, 0x6d
  sw    $t4, 0x158($sp)
  sw    $t9, 0x10($sp)
  addiu $a3, $a3, 1
  sw    $a1, 0x15c($sp)
  move  $a0, $s3
  li    $a2, 108
  jal   microcode_constructor_related_to_menus
   sw    $zero, 0x14($sp)
  jal   get_video2_settings_txtClipW
   move  $s3, $v0
  sll   $s0, $v0, 0x10
  sra   $t3, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t3
  cfc1  $t7, $31
  li    $t4, 1
  ctc1  $t4, $31
  lwc1  $f4, 0x70($sp)
  lui   $t5, %hi(ptrFirstFontTableLarge) 
  lw    $t5, %lo(ptrFirstFontTableLarge)($t5)
  cvt.w.s $f6, $f4
  lw    $t6, ($s4)
  move  $a0, $s3
  addiu $a1, $sp, 0x15c
  cfc1  $t4, $31
  addiu $a2, $sp, 0x158
  move  $a3, $s1
  andi  $t4, $t4, 0x78
  sw    $t5, 0x14($sp)
  beqz  $t4, .L7F01A0D8
   sw    $t6, 0x10($sp)
  li    $at, 0x4F000000 # 2147483648.000000
  mtc1  $at, $f6
  li    $t4, 1
  sub.s $f6, $f4, $f6
  ctc1  $t4, $31
  nop   
  cvt.w.s $f6, $f6
  cfc1  $t4, $31
  nop   
  andi  $t4, $t4, 0x78
  bnez  $t4, .L7F01A0D0
   nop   
  mfc1  $t4, $f6
  lui   $at, 0x8000
  b     .L7F01A0E8
   or    $t4, $t4, $at
.L7F01A0D0:
  b     .L7F01A0E8
   li    $t4, -1
.L7F01A0D8:
  mfc1  $t4, $f6
  nop   
  bltz  $t4, .L7F01A0D0
   nop   
.L7F01A0E8:
  li    $at, -256
  or    $t8, $t4, $at
  ctc1  $t7, $31
  sw    $t8, 0x18($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  jal   en_text_write_stuff
   sw    $zero, 0x28($sp)
  move  $s3, $v0
.L7F01A110:
  cfc1  $t6, $31
  li    $s2, 1
  ctc1  $s2, $31
  lwc1  $f8, 0x70($sp)
  lui   $t9, %hi(do_not_play_intro_movie) 
  lw    $t9, %lo(do_not_play_intro_movie)($t9)
  cvt.w.s $f10, $f8
  lui   $a0, %hi(intro_char_table+10)
  sll   $t3, $t9, 2
  addu  $t3, $t3, $t9
  cfc1  $s2, $31
  sll   $t3, $t3, 2
  lui   $s4, %hi(ptrSecondFontTableLarge)
  addu  $a0, $a0, $t3
  andi  $s2, $s2, 0x78
  addiu $s4, %lo(ptrSecondFontTableLarge) # addiu $s4, $s4, 0xeb8
  beqz  $s2, .L7F01A1A0
   lhu   $a0, %lo(intro_char_table+10)($a0)
  li    $at, 0x4F000000 # 2147483648.000000
  mtc1  $at, $f10
  li    $s2, 1
  sub.s $f10, $f8, $f10
  ctc1  $s2, $31
  nop   
  cvt.w.s $f10, $f10
  cfc1  $s2, $31
  nop   
  andi  $s2, $s2, 0x78
  bnez  $s2, .L7F01A198
   nop   
  mfc1  $s2, $f10
  lui   $at, 0x8000
  b     .L7F01A1B0
   or    $s2, $s2, $at
.L7F01A198:
  b     .L7F01A1B0
   li    $s2, -1
.L7F01A1A0:
  mfc1  $s2, $f10
  nop   
  bltz  $s2, .L7F01A198
   nop   
.L7F01A1B0:
  li    $at, -256
  or    $t5, $s2, $at
  ctc1  $t6, $31
  jal   get_textptr_for_textID
   move  $s2, $t5
  lui   $t7, %hi(ptrFirstFontTableLarge) 
  lw    $t7, %lo(ptrFirstFontTableLarge)($t7)
  move  $s1, $v0
  addiu $a0, $sp, 0x150
  addiu $a1, $sp, 0x154
  move  $a2, $v0
  lw    $a3, ($s4)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t7, 0x10($sp)
  lw    $v0, 0x154($sp)
  lw    $t3, 0x150($sp)
  li    $t8, 315
  bgez  $v0, .L7F01A208
   sra   $t4, $v0, 1
  addiu $at, $v0, 1
  sra   $t4, $at, 1
.L7F01A208:
  subu  $a1, $t8, $t4
  li    $t9, 152
  addu  $a3, $a1, $v0
  addiu $t6, $t3, 0x99
  sw    $t9, 0x158($sp)
  sw    $t6, 0x10($sp)
  addiu $a3, $a3, 1
  sw    $a1, 0x15c($sp)
  move  $a0, $s3
  li    $a2, 152
  jal   microcode_constructor_related_to_menus
   sw    $zero, 0x14($sp)
  jal   get_video2_settings_txtClipW
   move  $s3, $v0
  sll   $s0, $v0, 0x10
  sra   $t5, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t5
  lui   $t8, %hi(ptrFirstFontTableLarge) 
  lw    $t8, %lo(ptrFirstFontTableLarge)($t8)
  lw    $t7, ($s4)
  move  $a0, $s3
  addiu $a1, $sp, 0x15c
  addiu $a2, $sp, 0x158
  move  $a3, $s1
  sw    $s2, 0x18($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t8, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t7, 0x10($sp)
  lui   $t4, %hi(do_not_play_intro_movie) 
  lw    $t4, %lo(do_not_play_intro_movie)($t4)
  lui   $a0, %hi(intro_char_table+12)
  move  $s3, $v0
  sll   $t9, $t4, 2
  addu  $t9, $t9, $t4
  sll   $t9, $t9, 2
  addu  $a0, $a0, $t9
  jal   get_textptr_for_textID
   lhu   $a0, %lo(intro_char_table+12)($a0)
  lui   $t3, %hi(ptrFirstFontTableLarge) 
  lw    $t3, %lo(ptrFirstFontTableLarge)($t3)
  move  $s1, $v0
  addiu $a0, $sp, 0x150
  addiu $a1, $sp, 0x154
  move  $a2, $v0
  lw    $a3, ($s4)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t3, 0x10($sp)
  lw    $v0, 0x154($sp)
  lw    $t8, 0x150($sp)
  li    $t5, 315
  bgez  $v0, .L7F01A2F8
   sra   $t6, $v0, 1
  addiu $at, $v0, 1
  sra   $t6, $at, 1
.L7F01A2F8:
  subu  $a1, $t5, $t6
  li    $t7, 174
  addu  $a3, $a1, $v0
  addiu $t4, $t8, 0xaf
  sw    $t7, 0x158($sp)
  sw    $t4, 0x10($sp)
  addiu $a3, $a3, 1
  sw    $a1, 0x15c($sp)
  move  $a0, $s3
  li    $a2, 174
  jal   microcode_constructor_related_to_menus
   sw    $zero, 0x14($sp)
  jal   get_video2_settings_txtClipW
   move  $s3, $v0
  sll   $s0, $v0, 0x10
  sra   $t9, $s0, 0x10
  jal   get_video2_settings_txtClipH
   move  $s0, $t9
  lui   $t5, %hi(ptrFirstFontTableLarge) 
  lw    $t5, %lo(ptrFirstFontTableLarge)($t5)
  lw    $t3, ($s4)
  move  $a0, $s3
  addiu $a1, $sp, 0x15c
  addiu $a2, $sp, 0x158
  move  $a3, $s1
  sw    $s2, 0x18($sp)
  sw    $s0, 0x1c($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t5, 0x14($sp)
  jal   en_text_write_stuff
   sw    $t3, 0x10($sp)
  lw    $ra, 0x4c($sp)
  lw    $s0, 0x38($sp)
  lw    $s1, 0x3c($sp)
  lw    $s2, 0x40($sp)
  lw    $s3, 0x44($sp)
  lw    $s4, 0x48($sp)
  jr    $ra
   addiu $sp, $sp, 0x250
");

asm(R"
glabel init_menu19_spectrum
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  move  $s0, $zero
  li    $a0, 2
  jal   get_controller_buttons_held
   li    $a1, 2
  bnez  $v0, .L7F01A464
   li    $a0, 2
  jal   get_controller_buttons_held
   li    $a1, 1
  beqz  $v0, .L7F01A3D8
   li    $a0, 2
  b     .L7F01A464
   li    $s0, 1
.L7F01A3D8:
  jal   get_controller_buttons_held
   li    $a1, 8
  beqz  $v0, .L7F01A3F0
   li    $a0, 2
  b     .L7F01A464
   li    $s0, 2
.L7F01A3F0:
  jal   get_controller_buttons_held
   li    $a1, 4
  beqz  $v0, .L7F01A408
   li    $a0, 2
  b     .L7F01A464
   li    $s0, 3
.L7F01A408:
  jal   get_controller_buttons_held
   li    $a1, 512
  beqz  $v0, .L7F01A420
   li    $a0, 2
  b     .L7F01A464
   li    $s0, 4
.L7F01A420:
  jal   get_controller_buttons_held
   li    $a1, 256
  beqz  $v0, .L7F01A438
   li    $a0, 2
  b     .L7F01A464
   li    $s0, 5
.L7F01A438:
  jal   get_controller_buttons_held
   li    $a1, 2048
  beqz  $v0, .L7F01A450
   li    $a0, 2
  b     .L7F01A464
   li    $s0, 6
.L7F01A450:
  jal   get_controller_buttons_held
   li    $a1, 1024
  beqz  $v0, .L7F01A464
   nop   
  li    $s0, 7
.L7F01A464:
  jal   init_spectrum_game
   move  $a0, $s0
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

void update_menu19_spectrum(void) {}

asm(R"
glabel interface_menu19_spectrum
  addiu $sp, $sp, -0x18
  li    $at, 0x42700000 # 60.000000
  sw    $ra, 0x14($sp)
  mtc1  $at, $f12
  jal   setvideo_far
   nop   
  lui   $at, %hi(D_80051B3C)
  jal   video_related_21
   lwc1  $f12, %lo(D_80051B3C)($at)
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f12
  lui   $at, %hi(D_80051B40)
  jal   set_page_height
   lwc1  $f14, %lo(D_80051B40)($at)
  jal   set_video2_settings_offset_24
   move  $a0, $zero
  jal   run_spectrum_game
   nop   
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel constructor_menu19_spectrum
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   insert_imageDL
   nop   
  lui   $t6, (0xBA001402 >> 16) # lui $t6, 0xba00
  lui   $t2, (0xFFFCF87C >> 16) # lui $t2, 0xfffc
  ori   $t6, (0xBA001402 & 0xFFFF) # ori $t6, $t6, 0x1402
  lui   $t7, (0xB900031D >> 16) # lui $t7, 0xb900
  lui   $t8, (0x00552048 >> 16) # lui $t8, 0x55
  lui   $t9, 0xb600
  li    $t0, 516
  ori   $t2, (0xFFFCF87C & 0xFFFF) # ori $t2, $t2, 0xf87c
  lui   $t1, (0xFCFFFFFF >> 16) # lui $t1, 0xfcff
  lui   $t3, (0xBA000C02 >> 16) # lui $t3, 0xba00
  sw    $t6, ($v0)
  ori   $t8, (0x00552048 & 0xFFFF) # ori $t8, $t8, 0x2048
  ori   $t7, (0xB900031D & 0xFFFF) # ori $t7, $t7, 0x31d
  sw    $t0, 0x14($v0)
  sw    $t9, 0x10($v0)
  ori   $t1, (0xFCFFFFFF & 0xFFFF) # ori $t1, $t1, 0xffff
  sw    $t2, 0x1c($v0)
  ori   $t3, (0xBA000C02 & 0xFFFF) # ori $t3, $t3, 0xc02
  sw    $t7, 8($v0)
  sw    $t8, 0xc($v0)
  sw    $t1, 0x18($v0)
  sw    $t3, 0x20($v0)
  lui   $t5, %hi(color_palette_entries_50_percent) 
  lui   $t6, (0xF5000300 >> 16) # lui $t6, 0xf500
  lui   $t9, (0xF0000FF0 >> 16) # lui $t9, 0xf000
  lui   $t0, (0x0701CFF0 >> 16) # lui $t0, 0x701
  lui   $t2, (0xBA000E02 >> 16) # lui $t2, 0xba00
  addiu $t5, %lo(color_palette_entries_50_percent) # addiu $t5, $t5, -0x4510
  lui   $t4, 0xfd50
  ori   $t6, (0xF5000300 & 0xFFFF) # ori $t6, $t6, 0x300
  lui   $t7, 0x700
  lui   $t8, 0xe600
  ori   $t0, (0x0701CFF0 & 0xFFFF) # ori $t0, $t0, 0xcff0
  ori   $t9, (0xF0000FF0 & 0xFFFF) # ori $t9, $t9, 0xff0
  lui   $t1, 0xe700
  ori   $t2, (0xBA000E02 & 0xFFFF) # ori $t2, $t2, 0xe02
  li    $t3, 32768
  sw    $zero, 4($v0)
  sw    $zero, 0x24($v0)
  sw    $t4, 0x28($v0)
  sw    $t5, 0x2c($v0)
  sw    $t7, 0x34($v0)
  sw    $t6, 0x30($v0)
  sw    $t8, 0x38($v0)
  sw    $zero, 0x3c($v0)
  sw    $t9, 0x40($v0)
  sw    $t0, 0x44($v0)
  sw    $t1, 0x48($v0)
  sw    $zero, 0x4c($v0)
  sw    $t3, 0x54($v0)
  sw    $t2, 0x50($v0)
  jal   spectrum_draw_screen
   addiu $a0, $v0, 0x58
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel set_menu_to_mode
  li    $at, 11
  beq   $a0, $at, .L7F01A5E8
   li    $t6, 1
  li    $at, 25
  bne   $a0, $at, .L7F01A5F0
.L7F01A5E8:
   lui   $at, %hi(is_emulating_spectrum)
  sw    $t6, %lo(is_emulating_spectrum)($at)
.L7F01A5F0:
  beqz  $a1, .L7F01A604
   lui   $at, %hi(maybe_prev_menu)
  lui   $at, %hi(menu_update)
  jr    $ra
   sw    $a0, %lo(menu_update)($at)
.L7F01A604:
  sw    $a0, %lo(maybe_prev_menu)($at)
  jr    $ra
   nop   
");

MENU get_currentmenu(void) { return current_menu; }

asm(R"
.late_rodata
glabel jpt_menu_update
 .word menu_legal_screen_update
 .word menu_nintendo_logo_update
 .word menu_rareware_logo_update
 .word menu_eye_intro_update
 .word menu_goldeneye_logo_update
 .word menu_file_select_update
 .word menu_mode_select_update
 .word menu_mission_select_update
 .word menu_difficulty_update
 .word menu_007_options_update
 .word menu_briefing_update
 .word menu_switch_screen_update
 .word menu_mission_failed_update
 .word menu_mission_complete_update
 .word menu_mp_options_update
 .word menu_mp_char_select_update
 .word menu_mp_handicap_update
 .word menu_mp_control_style_update
 .word menu_mp_stage_select_update
 .word menu_mp_scenario_select_update
 .word menu_mp_teams_update
 .word menu_cheat_update
 .word menu_no_controllers_update
 .word menu_switch_screen_update
 .word menu_display_cast_update
 .word menu_spectrum_emu_update

 glabel jpt_menu_init
 .word menu_legal_screen_init
 .word menu_nintendo_logo_init
 .word menu_rareware_logo_init
 .word menu_eye_intro_init
 .word menu_goldeneye_logo_init
 .word menu_file_select_init
 .word menu_mode_select_init
 .word menu_mission_select_init
 .word menu_difficulty_init
 .word menu_007_options_init
 .word menu_briefing_init
 .word menu_runstage_init
 .word menu_mission_failed_init
 .word menu_mission_complete_init
 .word menu_mp_options_init
 .word menu_mp_char_select_init
 .word menu_mp_handicap_init
 .word menu_mp_control_style_init
 .word menu_mp_stage_select_init
 .word menu_mp_scenario_select_init
 .word menu_mp_teams_init
 .word menu_cheat_init
 .word menu_no_controllers_init
 .word menu_switch_screens_init
 .word menu_display_cast_init
 .word menu_spectrum_emu_init

glabel jpt_menu_interface
 .word menu00_legal_interface
 .word menu01_nintendo_interface
 .word menu02_rareware_interface
 .word menu03_eye_interface
 .word menu04_goldeneye_interface
 .word menu05_filesel_interface
 .word menu06_modesel_interface
 .word menu07_missionsel_interface
 .word menu08_difficulty_interface
 .word menu09_007options_interface
 .word menu0A_briefing_interface
 .word menu0B_runstage_interface
 .word menu0C_missionfailed_interface
 .word menu0D_missioncomplete_interface
 .word menu0E_mpoptions_interface
 .word menu0F_mpcharsel_interface
 .word menu10_mphandicap_interface
 .word menu11_mpcontrol_interface
 .word menu12_mpstage_interface
 .word menu13_mpscenario_interface
 .word menu14_mpteams_interface
 .word menu15_cheat_interface
 .word menu16_nocontrollers_interface
 .word menu17_switchscreen_interface
 .word menu18_displaycast_interface
 .word menu19_spectrum_interface
.text
glabel menu_init
  lui   $t6, %hi(current_menu) 
  lw    $t6, %lo(current_menu)($t6)
  addiu $sp, $sp, -0x18
  li    $at, 23
  bne   $t6, $at, .L7F01A6A4
   sw    $ra, 0x14($sp)
  lui   $t7, %hi(spectrum_related_flag) 
  lw    $t7, %lo(spectrum_related_flag)($t7)
  lui   $t0, %hi(is_emulating_spectrum) 
  beqz  $t7, .L7F01A674
   nop   
  jal   get_video_settings2_frameb
   nop   
  lui   $t8, %hi(cfb_16_b) # $t8, 0x803e
  addiu $t8, %lo(cfb_16_b) # addiu $t8, $t8, -0x5800
  bne   $v0, $t8, .L7F01A6A4
   li    $t9, 1
  lui   $at, %hi(screen_size)
  sw    $t9, %lo(screen_size)($at)
  lui   $at, %hi(spectrum_related_flag)
  b     .L7F01A6A4
   sw    $zero, %lo(spectrum_related_flag)($at)
.L7F01A674:
  lw    $t0, %lo(is_emulating_spectrum)($t0)
  beqz  $t0, .L7F01A6A4
   nop   
  jal   get_video_settings2_frameb
   nop   
  lui   $t1, %hi(cfb_16_a) # $t1, 0x803b
  addiu $t1, %lo(cfb_16_a) # addiu $t1, $t1, 0x5000
  bne   $v0, $t1, .L7F01A6A4
   lui   $at, %hi(screen_size)
  sw    $zero, %lo(screen_size)($at)
  lui   $at, %hi(is_emulating_spectrum)
  sw    $zero, %lo(is_emulating_spectrum)($at)
.L7F01A6A4:
  lui   $t2, %hi(screen_size) 
  lw    $t2, %lo(screen_size)($t2)
  lui   $at, %hi(D_80051B48)
  beqz  $t2, .L7F01A734
   nop   
  jal   get_video_settings2_frameb
   nop   
  lui   $t3, %hi(cfb_16_b) # $t3, 0x803e
  addiu $t3, %lo(cfb_16_b) # addiu $t3, $t3, -0x5800
  bne   $v0, $t3, .L7F01A6D8
   lui   $a0, %hi(ptr_menu_videobuffer)
  jal   set_video2buf_frameb
   lw    $a0, %lo(ptr_menu_videobuffer)($a0)
.L7F01A6D8:
  lui   $at, %hi(D_80051B48)
  jal   video_related_21
   lwc1  $f12, %lo(D_80051B44)($at)
  li    $a0, 440
  jal   set_video2_text_clip_size
   li    $a1, 330
  li    $a0, 440
  jal   set_video2_settings_offset_18_1A
   li    $a1, 330
  li    $a0, 440
  jal   set_cur_player_screen_size
   li    $a1, 330
  li    $a0, 440
  jal   set_video2_width_height
   li    $a1, 330
  move  $a0, $zero
  jal   set_cur_player_viewport_size
   move  $a1, $zero
  move  $a0, $zero
  jal   set_video2_ulx_uly
   move  $a1, $zero
  b     .L7F01A784
   nop   
.L7F01A734:
  jal   video_related_21
   lwc1  $f12, %lo(D_80051B48)($at)
  li    $a0, 320
  jal   set_video2_text_clip_size
   li    $a1, 240
  li    $a0, 320
  jal   set_video2_settings_offset_18_1A
   li    $a1, 240
  li    $a0, 320
  jal   set_cur_player_screen_size
   li    $a1, 240
  li    $a0, 320
  jal   set_video2_width_height
   li    $a1, 240
  move  $a0, $zero
  jal   set_cur_player_viewport_size
   move  $a1, $zero
  move  $a0, $zero
  jal   set_video2_ulx_uly
   move  $a1, $zero
.L7F01A784:
  lui   $v0, %hi(menu_update)
  lw    $v0, %lo(menu_update)($v0)
  lui   $a0, %hi(current_menu)
  addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
  bgez  $v0, .L7F01A7A8
   lui   $t4, %hi(maybe_prev_menu) 
  lw    $t4, %lo(maybe_prev_menu)($t4)
  bltz  $t4, .L7F01AA80
   nop   
.L7F01A7A8:
  lw    $v1, ($a0)
  li    $at, 23
  beq   $v1, $at, .L7F01AA80
   sltiu $at, $v1, 0x1a
  beqz  $at, .L7F01AA70
   sll   $t5, $v1, 2
  lui   $at, %hi(jpt_menu_update)
  addu  $at, $at, $t5
  lw    $t5, %lo(jpt_menu_update)($at)
  jr    $t5
   nop   
menu_legal_screen_update:
  jal   update_menu00_legalscreen
   nop   
  lui   $v0, %hi(menu_update)
  lui   $a0, %hi(current_menu)
  addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
  b     .L7F01AA70
   lw    $v0, %lo(menu_update)($v0)
menu_nintendo_logo_update:
  jal   update_menu01_nintendo
   nop   
  lui   $v0, %hi(menu_update)
  lui   $a0, %hi(current_menu)
  addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
  b     .L7F01AA70
   lw    $v0, %lo(menu_update)($v0)
menu_rareware_logo_update:
  jal   update_menu02_rareware
   nop   
  lui   $v0, %hi(menu_update)
  lui   $a0, %hi(current_menu)
  addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
  b     .L7F01AA70
   lw    $v0, %lo(menu_update)($v0)
menu_eye_intro_update:
  jal   update_menu_03_eye
   nop   
  lui   $v0, %hi(menu_update)
  lui   $a0, %hi(current_menu)
  addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
  b     .L7F01AA70
   lw    $v0, %lo(menu_update)($v0)
menu_goldeneye_logo_update:
  jal   update_menu04_goldeneye
   nop   
  lui   $v0, %hi(menu_update)
  lui   $a0, %hi(current_menu)
  addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
  b     .L7F01AA70
   lw    $v0, %lo(menu_update)($v0)
menu_file_select_update:
  jal   update_menu05_filesel
   nop   
  lui   $v0, %hi(menu_update)
  lui   $a0, %hi(current_menu)
  addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
  b     .L7F01AA70
   lw    $v0, %lo(menu_update)($v0)
menu_mode_select_update:
  jal   update_menu06_modesel
   nop   
  lui   $v0, %hi(menu_update)
  lui   $a0, %hi(current_menu)
  addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
  b     .L7F01AA70
   lw    $v0, %lo(menu_update)($v0)
menu_mission_select_update:
  jal   update_menu07_missionsel
   nop   
  lui   $v0, %hi(menu_update)
  lui   $a0, %hi(current_menu)
  addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
  b     .L7F01AA70
   lw    $v0, %lo(menu_update)($v0)
menu_difficulty_update:
  jal   update_menu08_difficulty
   nop   
  lui   $v0, %hi(menu_update)
  lui   $a0, %hi(current_menu)
  addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
  b     .L7F01AA70
   lw    $v0, %lo(menu_update)($v0)
menu_007_options_update:
  jal   update_menu09_007options
   nop   
  lui   $v0, %hi(menu_update)
  lui   $a0, %hi(current_menu)
  addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
  b     .L7F01AA70
   lw    $v0, %lo(menu_update)($v0)
menu_briefing_update:
  jal   update_menu0A_briefing
   nop   
  lui   $v0, %hi(menu_update)
  lui   $a0, %hi(current_menu)
  addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
  b     .L7F01AA70
   lw    $v0, %lo(menu_update)($v0)
menu_mission_failed_update:
  jal   update_menu0C_missionfailed
   nop   
  lui   $v0, %hi(menu_update)
  lui   $a0, %hi(current_menu)
  addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
  b     .L7F01AA70
   lw    $v0, %lo(menu_update)($v0)
menu_mission_complete_update:
  jal   update_menu0D_missioncomplete
   nop   
  lui   $v0, %hi(menu_update)
  lui   $a0, %hi(current_menu)
  addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
  b     .L7F01AA70
   lw    $v0, %lo(menu_update)($v0)
menu_mp_options_update:
  jal   update_menu0E_mpoptions
   nop   
  lui   $v0, %hi(menu_update)
  lui   $a0, %hi(current_menu)
  addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
  b     .L7F01AA70
   lw    $v0, %lo(menu_update)($v0)
menu_mp_scenario_select_update:
  jal   update_menu13_mpscenario
   nop   
  lui   $v0, %hi(menu_update)
  lui   $a0, %hi(current_menu)
  addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
  b     .L7F01AA70
   lw    $v0, %lo(menu_update)($v0)
menu_mp_char_select_update:
  jal   update_menu0F_mpcharsel
   nop   
  lui   $v0, %hi(menu_update)
  lui   $a0, %hi(current_menu)
  addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
  b     .L7F01AA70
   lw    $v0, %lo(menu_update)($v0)
menu_mp_teams_update:
  jal   update_menu14_mpteams
   nop   
  lui   $v0, %hi(menu_update)
  lui   $a0, %hi(current_menu)
  addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
  b     .L7F01AA70
   lw    $v0, %lo(menu_update)($v0)
menu_mp_handicap_update:
  jal   update_menu10_mphandicap
   nop   
  lui   $v0, %hi(menu_update)
  lui   $a0, %hi(current_menu)
  addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
  b     .L7F01AA70
   lw    $v0, %lo(menu_update)($v0)
menu_mp_control_style_update:
  jal   update_menu11_mpcontrols
   nop   
  lui   $v0, %hi(menu_update)
  lui   $a0, %hi(current_menu)
  addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
  b     .L7F01AA70
   lw    $v0, %lo(menu_update)($v0)
menu_mp_stage_select_update:
  jal   update_menu12_mpstage
   nop   
  lui   $v0, %hi(menu_update)
  lui   $a0, %hi(current_menu)
  addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
  b     .L7F01AA70
   lw    $v0, %lo(menu_update)($v0)
menu_cheat_update:
  jal   update_menu15_cheat
   nop   
  lui   $v0, %hi(menu_update)
  lui   $a0, %hi(current_menu)
  addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
  b     .L7F01AA70
   lw    $v0, %lo(menu_update)($v0)
menu_no_controllers_update:
  jal   update_menu16_nocontrollers
   nop   
  lui   $v0, %hi(menu_update)
  lui   $a0, %hi(current_menu)
  addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
  b     .L7F01AA70
   lw    $v0, %lo(menu_update)($v0)
menu_display_cast_update:
  jal   update_menu18_displaycast
   nop   
  lui   $v0, %hi(menu_update)
  lui   $a0, %hi(current_menu)
  addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
  b     .L7F01AA70
   lw    $v0, %lo(menu_update)($v0)
menu_spectrum_emu_update:
  jal   update_menu19_spectrum
   nop   
  lui   $v0, %hi(menu_update)
  lui   $a0, %hi(current_menu)
  addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
  lw    $v0, %lo(menu_update)($v0)
menu_switch_screen_update:
.L7F01AA70:
  bltz  $v0, .L7F01AA80
   li    $t6, 23
  jal   reset_menutimer
   sw    $t6, ($a0)
.L7F01AA80:
  lui   $v0, %hi(maybe_prev_menu)
  lw    $v0, %lo(maybe_prev_menu)($v0)
  lui   $a0, %hi(current_menu)
  addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
  bltz  $v0, .L7F01ACB8
   li    $t7, -1
  sw    $v0, ($a0)
  lui   $at, %hi(maybe_prev_menu)
  sw    $t7, %lo(maybe_prev_menu)($at)
  lw    $t8, ($a0)
  sltiu $at, $t8, 0x1a
  beqz  $at, .L7F01ACB8
   sll   $t8, $t8, 2
  lui   $at, %hi(jpt_menu_init)
  addu  $at, $at, $t8
  lw    $t8, %lo(jpt_menu_init)($at)
  jr    $t8
   nop   
menu_legal_screen_init:
  jal   init_menu00_legalscreen
   nop   
  lui   $a0, %hi(current_menu)
  b     .L7F01ACB8
   addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
menu_nintendo_logo_init:
  jal   init_menu01_nintendo
   nop   
  lui   $a0, %hi(current_menu)
  b     .L7F01ACB8
   addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
menu_rareware_logo_init:
  jal   init_menu02_rarelogo
   nop   
  lui   $a0, %hi(current_menu)
  b     .L7F01ACB8
   addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
menu_eye_intro_init:
  jal   init_menu03_eyeintro
   nop   
  lui   $a0, %hi(current_menu)
  b     .L7F01ACB8
   addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
menu_goldeneye_logo_init:
  jal   init_menu04_goldeneyelogo
   nop   
  lui   $a0, %hi(current_menu)
  b     .L7F01ACB8
   addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
menu_file_select_init:
  jal   init_menu05_fileselect
   nop   
  lui   $a0, %hi(current_menu)
  b     .L7F01ACB8
   addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
menu_mode_select_init:
  jal   init_menu06_modeselect
   nop   
  lui   $a0, %hi(current_menu)
  b     .L7F01ACB8
   addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
menu_mission_select_init:
  jal   init_menu07_missionselect
   nop   
  lui   $a0, %hi(current_menu)
  b     .L7F01ACB8
   addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
menu_difficulty_init:
  jal   init_menu08_difficultyselect
   nop   
  lui   $a0, %hi(current_menu)
  b     .L7F01ACB8
   addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
menu_007_options_init:
  jal   init_menu09_007difficultyselect
   nop   
  lui   $a0, %hi(current_menu)
  b     .L7F01ACB8
   addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
menu_briefing_init:
  jal   init_menu0A_briefing
   nop   
  lui   $a0, %hi(current_menu)
  b     .L7F01ACB8
   addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
menu_runstage_init:
  jal   init_menu0B_runstage
   nop   
  lui   $a0, %hi(current_menu)
  b     .L7F01ACB8
   addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
menu_mission_failed_init:
  jal   init_menu0C_missionfailed
   nop   
  lui   $a0, %hi(current_menu)
  b     .L7F01ACB8
   addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
menu_mission_complete_init:
  jal   init_menu0D_missioncomplete
   nop   
  lui   $a0, %hi(current_menu)
  b     .L7F01ACB8
   addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
menu_mp_options_init:
  jal   init_menu0E_mpoptions
   nop   
  lui   $a0, %hi(current_menu)
  b     .L7F01ACB8
   addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
menu_mp_scenario_select_init:
  jal   init_menu13_mpscenariosel
   nop   
  lui   $a0, %hi(current_menu)
  b     .L7F01ACB8
   addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
menu_mp_char_select_init:
  jal   init_menu0f_mpcharsel
   nop   
  lui   $a0, %hi(current_menu)
  b     .L7F01ACB8
   addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
menu_mp_teams_init:
  jal   init_menu14_mpteamsel
   nop   
  lui   $a0, %hi(current_menu)
  b     .L7F01ACB8
   addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
menu_mp_handicap_init:
  jal   init_menu10_mphandicap
   nop   
  lui   $a0, %hi(current_menu)
  b     .L7F01ACB8
   addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
menu_mp_control_style_init:
  jal   init_menu11_mpcontrol
   nop   
  lui   $a0, %hi(current_menu)
  b     .L7F01ACB8
   addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
menu_mp_stage_select_init:
  jal   init_menu12_mpstage
   nop   
  lui   $a0, %hi(current_menu)
  b     .L7F01ACB8
   addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
menu_cheat_init:
  jal   init_menu15_cheat
   nop   
  lui   $a0, %hi(current_menu)
  b     .L7F01ACB8
   addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
menu_no_controllers_init:
  jal   init_menu16_nocontroller
   nop   
  lui   $a0, %hi(current_menu)
  b     .L7F01ACB8
   addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
menu_display_cast_init:
  jal   init_menu18_displaycast
   nop   
  lui   $a0, %hi(current_menu)
  b     .L7F01ACB8
   addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
menu_spectrum_emu_init:
  jal   init_menu19_spectrum
   nop   
  lui   $a0, %hi(current_menu)
  addiu $a0, %lo(current_menu) # addiu $a0, $a0, -0x5740
menu_switch_screens_init:
.L7F01ACB8:
  lw    $t9, ($a0)
  sltiu $at, $t9, 0x1a
  beqz  $at, .L7F01AEEC
   sll   $t9, $t9, 2
  lui   $at, %hi(jpt_menu_interface)
  addu  $at, $at, $t9
  lw    $t9, %lo(jpt_menu_interface)($at)
  jr    $t9
   nop   
menu00_legal_interface:
  jal   interface_menu00_legalscreen
   nop   
  b     .L7F01AEF0
   lw    $ra, 0x14($sp)
menu17_switchscreen_interface:
  jal   interface_menu17_switchscreens
   nop   
  b     .L7F01AEF0
   lw    $ra, 0x14($sp)
menu01_nintendo_interface:
  jal   interface_menu01_nintendo
   nop   
  b     .L7F01AEF0
   lw    $ra, 0x14($sp)
menu02_rareware_interface:
  jal   interface_menu02_rareware
   nop   
  b     .L7F01AEF0
   lw    $ra, 0x14($sp)
menu03_eye_interface:
  jal   interface_menu03_eye
   nop   
  b     .L7F01AEF0
   lw    $ra, 0x14($sp)
menu04_goldeneye_interface:
  jal   interface_menu04_goldeneyelogo
   nop   
  b     .L7F01AEF0
   lw    $ra, 0x14($sp)
menu05_filesel_interface:
  jal   interface_menu05_fileselect
   nop   
  b     .L7F01AEF0
   lw    $ra, 0x14($sp)
menu06_modesel_interface:
  jal   interface_menu06_modesel
   nop   
  b     .L7F01AEF0
   lw    $ra, 0x14($sp)
menu07_missionsel_interface:
  jal   interface_menu07_missionsel
   nop   
  b     .L7F01AEF0
   lw    $ra, 0x14($sp)
menu08_difficulty_interface:
  jal   interface_menu08_difficulty
   nop   
  b     .L7F01AEF0
   lw    $ra, 0x14($sp)
menu09_007options_interface:
  jal   interface_menu09_007options
   nop   
  b     .L7F01AEF0
   lw    $ra, 0x14($sp)
menu0A_briefing_interface:
  jal   interface_menu0A_briefing
   nop   
  b     .L7F01AEF0
   lw    $ra, 0x14($sp)
menu0C_missionfailed_interface:
  jal   interface_menu0C_missionfailed
   nop   
  b     .L7F01AEF0
   lw    $ra, 0x14($sp)
menu0D_missioncomplete_interface:
  jal   interface_menu0D_missioncomplete
   nop   
  b     .L7F01AEF0
   lw    $ra, 0x14($sp)
menu0E_mpoptions_interface:
  jal   interface_menu0E_mpoptions
   nop   
  b     .L7F01AEF0
   lw    $ra, 0x14($sp)
menu13_mpscenario_interface:
  jal   interface_menu13_mpscenario
   nop   
  b     .L7F01AEF0
   lw    $ra, 0x14($sp)
menu0F_mpcharsel_interface:
  jal   interface_menu0F_mpcharsel
   nop   
  b     .L7F01AEF0
   lw    $ra, 0x14($sp)
menu14_mpteams_interface:
  jal   interface_menu14_mpteams
   nop   
  b     .L7F01AEF0
   lw    $ra, 0x14($sp)
menu10_mphandicap_interface:
  jal   interface_menu10_mphandicap
   nop   
  b     .L7F01AEF0
   lw    $ra, 0x14($sp)
menu11_mpcontrol_interface:
  jal   interface_menu11_mpcontrols
   nop   
  b     .L7F01AEF0
   lw    $ra, 0x14($sp)
menu12_mpstage_interface:
  jal   interface_menu12_mpstage
   nop   
  b     .L7F01AEF0
   lw    $ra, 0x14($sp)
menu15_cheat_interface:
  jal   interface_menu15_cheat
   nop   
  b     .L7F01AEF0
   lw    $ra, 0x14($sp)
menu16_nocontrollers_interface:
  jal   interface_menu16_nocontrollers
   nop   
  b     .L7F01AEF0
   lw    $ra, 0x14($sp)
menu18_displaycast_interface:
  jal   interface_menu18_displaycast
   nop   
  b     .L7F01AEF0
   lw    $ra, 0x14($sp)
menu19_spectrum_interface:
  jal   interface_menu19_spectrum
   nop   
  b     .L7F01AEF0
   lw    $ra, 0x14($sp)
menu0B_runstage_interface:
  jal   interface_menu0B_runstage
   nop   
  beqz  $v0, .L7F01AE90
   lui   $t0, %hi(gamemode) 
  move  $a0, $zero
  jal   set_menu_to_mode
   li    $a1, 1
  b     .L7F01AEF0
   lw    $ra, 0x14($sp)
.L7F01AE90:
  lw    $t0, %lo(gamemode)($t0)
  li    $at, 1
  li    $a0, 14
  bne   $t0, $at, .L7F01AEB4
   lui   $t1, %hi(selected_stage) 
  jal   set_menu_to_mode
   li    $a1, 1
  b     .L7F01AEF0
   lw    $ra, 0x14($sp)
.L7F01AEB4:
  lw    $t1, %lo(selected_stage)($t1)
  li    $at, 54
  li    $a0, 12
  bne   $t1, $at, .L7F01AEE4
   nop   
  jal   do_extended_cast_display
   li    $a0, 1
  li    $a0, 24
  jal   set_menu_to_mode
   li    $a1, 1
  b     .L7F01AEF0
   lw    $ra, 0x14($sp)
.L7F01AEE4:
  jal   set_menu_to_mode
   li    $a1, 1
.L7F01AEEC:
  lw    $ra, 0x14($sp)
.L7F01AEF0:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel jpt_menu_constructor
 .word menu00_legal_constructor
 .word menu01_nintendo_constructor
 .word menu02_rareware_constructor
 .word menu03_eyeintro_constructor
 .word menu04_goldeneye_constructor
 .word menu05_fileselect_constructor
 .word menu06_modesel_constructor
 .word menu07_missionsel_constructor
 .word menu08_difficulty_constructor
 .word menu09_007options_constructor
 .word menu0A_briefing_constructor
 .word menu0B_runstage_constructor
 .word menu0C_missionfailed_constructor
 .word menu0D_missioncomplete_constructor
 .word menu0E_mpoptions_constructor
 .word menu0F_mpcharsel_constructor
 .word menu10_mphandicap_constructor
 .word menu11_mpcontrol_constructor
 .word menu12_mpstage_constructor
 .word menu13_mpscenario_constructor
 .word menu14_mpteams_constructor
 .word menu15_cheat_constructor
 .word menu16_nocontrollers_constructor
 .word menu17_switchscreens_constructor
 .word menu18_displaycast_constructor
 .word menu19_spectrum_constructor

.text
glabel menu_jump_constructor_handler
  lui   $t6, %hi(current_menu) 
  lw    $t6, %lo(current_menu)($t6)
  addiu $sp, $sp, -0x20
  sw    $s0, 0x18($sp)
  sltiu $at, $t6, 0x1a
  move  $s0, $a0
  beqz  $at, menu0B_runstage_constructor
   sw    $ra, 0x1c($sp)
  sll   $t6, $t6, 2
  lui   $at, %hi(jpt_menu_constructor)
  addu  $at, $at, $t6
  lw    $t6, %lo(jpt_menu_constructor)($at)
  jr    $t6
   nop   
glabel menu00_legal_constructor
  jal   constructor_menu00_legalscreen
   move  $a0, $s0
  b     menu0B_runstage_constructor
   move  $s0, $v0
glabel menu17_switchscreens_constructor
  jal   constructor_menu17_switchscreens
   move  $a0, $s0
  b     menu0B_runstage_constructor
   move  $s0, $v0
glabel menu01_nintendo_constructor
  jal   constructor_menu01_nintendo
   move  $a0, $s0
  b     menu0B_runstage_constructor
   move  $s0, $v0
glabel menu02_rareware_constructor
  jal   constructor_menu02_rareware
   move  $a0, $s0
  b     menu0B_runstage_constructor
   move  $s0, $v0
glabel menu03_eyeintro_constructor
  jal   constructor_menu03_eye
   move  $a0, $s0
  b     menu0B_runstage_constructor
   move  $s0, $v0
glabel menu04_goldeneye_constructor
  jal   constructor_menu04_goldeneyelogo
   move  $a0, $s0
  b     menu0B_runstage_constructor
   move  $s0, $v0
glabel menu05_fileselect_constructor
  jal   constructor_menu05_fileselect
   move  $a0, $s0
  b     menu0B_runstage_constructor
   move  $s0, $v0
glabel menu06_modesel_constructor
  jal   constructor_menu06_modesel
   move  $a0, $s0
  b     menu0B_runstage_constructor
   move  $s0, $v0
glabel menu07_missionsel_constructor
  jal   constructor_menu07_missionsel
   move  $a0, $s0
  b     menu0B_runstage_constructor
   move  $s0, $v0
glabel menu08_difficulty_constructor
  jal   constructor_menu08_difficulty
   move  $a0, $s0
  b     menu0B_runstage_constructor
   move  $s0, $v0
glabel menu09_007options_constructor
  jal   constructor_menu09_007options
   move  $a0, $s0
  b     menu0B_runstage_constructor
   move  $s0, $v0
glabel menu0A_briefing_constructor
  jal   constructor_menu0A_briefing
   move  $a0, $s0
  b     menu0B_runstage_constructor
   move  $s0, $v0
glabel menu0C_missionfailed_constructor
  jal   constructor_menu0C_missionfailed
   move  $a0, $s0
  b     menu0B_runstage_constructor
   move  $s0, $v0
glabel menu0D_missioncomplete_constructor
  jal   constructor_menu0D_missioncomplete
   move  $a0, $s0
  b     menu0B_runstage_constructor
   move  $s0, $v0
glabel menu0E_mpoptions_constructor
  jal   constructor_menu0E_mpoptions
   move  $a0, $s0
  b     menu0B_runstage_constructor
   move  $s0, $v0
glabel menu13_mpscenario_constructor
  jal   constructor_menu13_mpscenario
   move  $a0, $s0
  b     menu0B_runstage_constructor
   move  $s0, $v0
glabel menu0F_mpcharsel_constructor
  jal   constructor_menu0F_mpcharsel
   move  $a0, $s0
  b     menu0B_runstage_constructor
   move  $s0, $v0
glabel menu14_mpteams_constructor
  jal   constructor_menu14_mpteams
   move  $a0, $s0
  b     menu0B_runstage_constructor
   move  $s0, $v0
glabel menu10_mphandicap_constructor
  jal   constructor_menu10_mphandicap
   move  $a0, $s0
  b     menu0B_runstage_constructor
   move  $s0, $v0
glabel menu11_mpcontrol_constructor
  jal   constructor_menu11_mpcontrol
   move  $a0, $s0
  b     menu0B_runstage_constructor
   move  $s0, $v0
glabel menu12_mpstage_constructor
  jal   constructor_menu12_mpstage
   move  $a0, $s0
  b     menu0B_runstage_constructor
   move  $s0, $v0
glabel menu15_cheat_constructor
  jal   constructor_menu15_cheat
   move  $a0, $s0
  b     menu0B_runstage_constructor
   move  $s0, $v0
glabel menu16_nocontrollers_constructor
  jal   constructor_menu16_nocontrollers
   move  $a0, $s0
  b     menu0B_runstage_constructor
   move  $s0, $v0
glabel menu18_displaycast_constructor
  jal   constructor_menu18_displaycast
   move  $a0, $s0
  b     menu0B_runstage_constructor
   move  $s0, $v0
glabel menu19_spectrum_constructor
  jal   constructor_menu19_spectrum
   move  $a0, $s0
  move  $s0, $v0
glabel menu0B_runstage_constructor
  lw    $ra, 0x1c($sp)
  move  $v0, $s0
  lw    $s0, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x20
");
