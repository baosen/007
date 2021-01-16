void sub_GAME_7F007770(void) {
  int sp3C, sp38, player_count = getPlayerCount(),
                  current_player = get_cur_playernum(), i = 0;
  if (0 < player_count) {
    do {
      set_cur_player(i);
      sub_GAME_7F08DB08(&sp3C, &sp38);
      store_favorite_weapon_current_player(sp3C, sp38);
      i += 1;
    } while (i != player_count);
  }
  set_cur_player(current_player);
}
