#ifndef _MAINMENU_H_
#define _MAINMENU_H_

struct legal_screen_text {
    int h_pos, v_pos;
    int flag, flag2;
    short txtID;
    short anonymous_5;
};

struct mission_folder_setup {
    void * string_ptr;
    short folder_text_preset;
    short icon_text_preset;
    int stage_id;
    int unknown;
    int type;
    int mission_num;
    void * briefing_name_ptr;
};

struct MP_game_length_settings {
    unsigned short text_preset;
    unsigned short padding;
    int time;
    int points;
};

struct mp_stage_playercount {
    short stage;
    char min, max;
};

struct mp_stage_setup {
    short folder_text_preset;
    short select_screen_text_preset;
    int photo;
    int stage_id;
    int unlock_after;
    int min_player, max_player;
};

struct MP_selectable_chars {
    short text_preset;
    char gender;
    char select_photo;
    short body;
    short head;
    float pov;
};

struct MP_handicap_menu {
    short text_preset;
    short padding;
    float damage_modifier;
};

struct MP_controller_configuration_menu {
    char anonymous_0;
    char field_1;
    char field_2;
    char field_3;
};

struct MP_sight_aim_settings {
    char anonymous_0;
    char field_1;
    char sight;
    char autoaim;
};

struct intro_char {
    int body;
    int head;
    short text1;
    short text2;
    short text3;
    short RESERVED;
    int flag;
};

struct intro_animation {
    int animID;
    float startframeoffset;
    float playback_speed;
    int camera_preset;
};

struct solo_target_times {
    unsigned short agent_time;
    unsigned short secret_agent_time;
    unsigned short OO_agent_time;
};

extern float flt_CODE_bss_800695A0;
extern float flt_CODE_bss_800695A4;
extern float flt_CODE_bss_800695A8;
extern float flt_CODE_bss_800695AC;
extern float flt_CODE_bss_800695B0;
extern float flt_CODE_bss_800695B4;
extern float flt_CODE_bss_800695B8;
extern float flt_CODE_bss_800695BC;
extern float flt_CODE_bss_800695C0;
extern float flt_CODE_bss_800695C8;
extern float flt_CODE_bss_800695CC;
extern float flt_CODE_bss_800695D0;
extern float flt_CODE_bss_800695D8;
extern float flt_CODE_bss_800695DC;
extern float flt_CODE_bss_800695E0;
extern float flt_CODE_bss_800695E4;
extern float flt_CODE_bss_800695E8;
extern float flt_CODE_bss_800695EC;
extern float flt_CODE_bss_800695F0;
extern float flt_CODE_bss_800695F8;
extern float flt_CODE_bss_800695FC;
extern float flt_CODE_bss_80069600;
extern float flt_CODE_bss_80069608;
extern float flt_CODE_bss_8006960C;
extern float flt_CODE_bss_80069610;
extern float flt_CODE_bss_80069614;
extern float flt_CODE_bss_80069618;

extern unsigned char cheat_activated;
extern unsigned char CHEAT_AVAILABLE_EXTRA_CHARS;
extern unsigned char cheat_activated_1;
extern unsigned char cheat_activated_2;
extern unsigned char CHEAT_AVAILABLE_MAX_AMMO;
extern unsigned char cheat_activated_4;
extern unsigned char cheat_activated_5;
extern unsigned char cheat_activated_6;
extern unsigned char cheat_activated_7;
extern unsigned char cheat_activated_8;
extern unsigned char cheat_activated_9;
extern unsigned char cheat_activated_10;
extern unsigned char cheat_activated_11;
extern unsigned char cheat_activated_12;
extern unsigned char cheat_activated_13;
extern unsigned char cheat_activated_14;
extern unsigned char cheat_activated_15;
extern unsigned char cheat_activated_16;
extern unsigned char cheat_activated_17;
extern unsigned char cheat_activated_18;
extern unsigned char cheat_activated_19;
extern unsigned char cheat_activated_20;
extern unsigned char cheat_activated_21;
extern unsigned char cheat_activated_22;
extern unsigned char cheat_activated_23;
extern unsigned char cheat_activated_24;
extern unsigned char cheat_activated_25;
extern unsigned char cheat_activated_26;
extern unsigned char cheat_activated_27;
extern unsigned char cheat_activated_28;
extern unsigned char cheat_activated_29;
extern unsigned char cheat_activated_30;
extern unsigned char cheat_activated_31;
extern unsigned char cheat_activated_32;
extern unsigned char cheat_activated_33;
extern unsigned char cheat_activated_34;
extern unsigned char cheat_activated_35;
extern unsigned char cheat_activated_36;
extern unsigned char cheat_activated_37;
extern unsigned char cheat_activated_38;
extern unsigned char cheat_activated_39;
extern unsigned char cheat_activated_40;
extern unsigned char cheat_activated_41;
extern unsigned char cheat_activated_42;
extern unsigned char cheat_activated_43;
extern unsigned char cheat_activated_44;
extern unsigned char cheat_activated_45;
extern unsigned char cheat_activated_46;
extern unsigned char cheat_activated_47;
extern unsigned char cheat_activated_48;
extern unsigned char cheat_activated_49;
extern unsigned char cheat_activated_50;
extern unsigned char cheat_activated_51;
extern unsigned char cheat_activated_52;
extern unsigned char cheat_activated_53;
extern unsigned char cheat_activated_54;
extern unsigned char cheat_activated_55;
extern unsigned char cheat_activated_56;
extern unsigned char cheat_activated_57;
extern unsigned char cheat_activated_58;
extern unsigned char cheat_activated_59;
extern unsigned char cheat_activated_60;
extern unsigned char cheat_activated_61;
extern unsigned char cheat_activated_62;
extern unsigned char cheat_activated_63;
extern unsigned char cheat_activated_64;
extern unsigned char cheat_activated_65;
extern unsigned char cheat_activated_66;
extern unsigned char cheat_activated_67;
extern unsigned char cheat_activated_68;
extern unsigned char cheat_activated_69;
extern unsigned char cheat_activated_70;
extern unsigned char cheat_activated_71;
extern unsigned char cheat_activated_72;
extern unsigned char cheat_activated_73;
extern unsigned char cheat_activated_74;
extern unsigned char cheat_activated_75;
extern unsigned char cheat_activated_76;
extern unsigned char cheat_activated_77;
extern unsigned char cheat_activated_78;

extern int array_favweapon[4][2];
extern int mp_char_cur_select_player1;
extern int mp_char_cur_select_player2;
extern int mp_char_cur_select_player3;
extern int mp_char_cur_select_player4;
extern int mp_char_prev_select_player1;
extern int mp_char_prev_select_player2;
extern int mp_char_prev_select_player3;
extern int mp_char_prev_select_player4;
extern int dword_CODE_bss_80069730;
extern int dword_CODE_bss_80069734;
extern int dword_CODE_bss_80069738;
extern int dword_CODE_bss_8006973C;
extern int has_selected_char_player1;
extern int has_selected_char_player2;
extern int has_selected_char_player3;
extern int has_selected_char_player4;
extern int size_mp_select_image_player1;
extern int size_mp_select_image_player2;
extern int size_mp_select_image_player3;
extern int size_mp_select_image_player4;
extern int handicap_player1;
extern int handicap_player2;
extern int handicap_player3;
extern int handicap_player4;
extern int dword_CODE_bss_80069770;
extern int dword_CODE_bss_80069774;
extern int dword_CODE_bss_80069778;
extern int current_mp_stage_highlighted;
extern int dword_CODE_bss_80069780;
extern int mission_difficulty_highlighted;
extern int teamsize;
extern int ptrbriefingdata;
extern int newcheatunlocked;
extern int highlight_enemy_reaction;
extern int highlight_enemy_health;
extern int highlight_enemy_accuracy;
extern int highlight_enemy_damage;

extern int handicap_player1;
extern int handicap_player2;
extern int handicap_player3;
extern int handicap_player4;
extern unsigned int controlstyle_player[];

extern int highlight_players;
extern int highlight_scenario;
extern int highlight_gameselect;
extern int highlight_gamelength;
extern int highlight_character;
extern int highlight_weaponselect;
extern int highlight_health;
extern int highlight_controlstyle;
extern int highlight_aimadjustment;

extern int current_menu;
extern int menu_update;
extern int maybe_prev_menu;
extern int menu_timer;
extern int tab_1_selected;
extern int tab_2_selected;
extern int tab_3_selected;
extern int tab_1_highlight;
extern int tab_2_highlight;
extern int tab_3_highlight;

extern float tab2_first_x_coord;
extern float tab1_max_x_coord;
extern float tab2_bottom_y_coord;

extern int selected_folder_num;
extern int selected_folder_num_copy;
extern int gamemode;
extern int selected_stage;
extern int briefingpage;
extern int selected_difficulty;
extern int append_cheat_sp;
extern int append_cheat_mp;
extern float cursor_h_pos;
extern float cursor_v_pos;
extern int final_menu_briefing_page;
extern int current_menu_briefing_page;
extern int folder_selection_screen_option_icon;
extern int folder_selected_for_deletion;
extern int folder_selected_for_deletion_choice;
extern int mission_failed_or_aborted;
extern int mission_kia_flag;
extern int is_first_time_on_legal_screen;
extern int is_first_time_on_main_menu;
extern int prev_keypresses;
extern int dword_D_8002A938;
extern int maybe_is_in_menu;
extern int screen_size;
extern int spectrum_related_flag;
extern int is_emulating_spectrum;
extern int is_cheat_menu_available;
extern int ptr_logo_and_walletbond_DL;
extern int ptr_menu_videobuffer;
extern int something_legalscreen_constructor;
extern int ptr_folder_object_instance;
extern int set0_never_used;
extern int set0_never_used_0;
extern int D_8002A968;
extern int dword_D_8002A96C;
extern struct rgba_val stru_D_8002A970;
extern struct rgba_val stru_D_8002A974;
extern struct rgba_val stru_D_8002A978;
extern struct rgba_val stru_D_8002A97C;
extern struct rgba_val stru_D_8002A980;
extern struct rgba_val stru_D_8002A984;
extern struct rgba_val stru_D_8002A988;
extern struct rgba_val stru_D_8002A98C;
extern unsigned int dword_D_8002A990;
extern unsigned int dword_D_8002A994;
extern unsigned int dword_D_8002A998;
extern unsigned int dword_D_8002A99C;
extern float slider_007_mode_reaction;
extern float slider_007_mode_health;
extern float slider_007_mode_damage;
extern float slider_007_mode_accuracy;

extern int selected_num_players;
extern int player_1_char;
extern int player_2_char;
extern int player_3_char;
extern int player_4_char;
extern int MP_stage_selected;
extern int game_length;
extern int aim_sight_adjustment;
extern int scenario;

extern int unlock_stage_select;
extern int unlock_game_length;
extern int unlock_chars;
extern int unlock_weapon_select;
extern int unlock_handicap;
extern int unlock_control_style;
extern int unlock_aim_sight;

extern unsigned int do_not_play_intro_movie;
extern unsigned int randomly_selected_intro_animation;
extern unsigned int intro_animation_count;
extern unsigned int objinstance;
extern unsigned int ptrobjinstance;
extern unsigned int full_actor_intro;

#endif
