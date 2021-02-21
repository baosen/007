#ifndef _MAINMENU_H_
#define _MAINMENU_H_

extern int array_favweapon[4][2];

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
extern struct color stru_D_8002A970;
extern struct color stru_D_8002A974;
extern struct color stru_D_8002A978;
extern struct color stru_D_8002A97C;
extern struct color stru_D_8002A980;
extern struct color stru_D_8002A984;
extern struct color stru_D_8002A988;
extern struct color stru_D_8002A98C;
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
