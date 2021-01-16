void sub_GAME_7F007770(void) {
  int sp3C, sp38, temp_s3 = getPlayerCount(), sp30 = get_cur_playernum(),
                  phi_s0 = 0;
  if (0 < temp_s3) {
    do {
      set_cur_player(phi_s0);
      sub_GAME_7F08DB08(&sp3C, &sp38);
      store_favorite_weapon_current_player(sp3C, sp38);
      phi_s0 += 1;
    } while (phi_s0 != temp_s3);
  }
  set_cur_player(sp30);
}
