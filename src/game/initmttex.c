void set_mt_tex_alloc(void) {
  extern int dword_CODE_bss_8008D090;
  extern int bytes;
  extern int ptr_texture_alloc_start;

  dword_CODE_bss_8008D090 = 0;
  if (check_token(1, "-mt") != 0) {
    bytes = (int)(strtol(check_token(1, "-mt"), 0, 0) << 0xA);
  }
  sub_GAME_7F0CBAF4(&ptr_texture_alloc_start, mempAllocBytesInBank(bytes, 4),
                    bytes);
}
