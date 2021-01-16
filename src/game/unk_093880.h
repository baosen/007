#ifndef _UNK_093880_H_
#define _UNK_093880_H_
#include "player.h"

typedef struct {
  int shots_fired;
  int head_hits;
  int body_hits;
  int leg_hits;
  int other_hit_weapon;
  int other_hit_hat;
  int other_hit_objects;
  int kill_count;
  int killed_gg_owner_count;
  int killed_p1;
  int killed_p2;
  int killed_p3;
  int killed_p4;
  int time_other_players_on_screen;
  float distance_traveled;
  int damage_to_backside;
  float body_armor_pickups;
  int min_time_between_kills;
  int max_time_between_kills;
  int longest_inning;
  int shortest_inning;
  int most_killed_one_life;
  int most_killed_one_time;
  float handicap;
  int flag_counter;
  float player_perspective_height;
  char order_out_in_yolt;
  char have_token_or_goldengun;
  char autoaim;
  char sight;
  int killed_civilians;
} player_statistics;

extern player_statistics player1_player_data;
extern player_statistics player2_player_data;
extern player_statistics player3_player_data;
extern player_statistics player4_player_data;
extern player_statistics *pPlayersPerm;

#endif
