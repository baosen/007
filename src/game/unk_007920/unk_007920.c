void sub_GAME_7F007920(void) {
  extern int dword_CODE_bss_8007A160;
  extern int dword_CODE_bss_8007A164;
  int iVar1 = 0, iVar2 = 0;
  if (0 < dword_CODE_bss_8007A160) {
    do {
      iVar1 = iVar1 + 1;
      *(int *)(dword_CODE_bss_8007A164 + iVar2) = 0;
      iVar2 = iVar2 + 0x68;
    } while (iVar1 < dword_CODE_bss_8007A160);
  }
}
