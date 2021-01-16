void set_gu_scale(void) {
  void guScale(unsigned int *m, float x, float y, float z);
  extern unsigned int dword_CODE_bss_8007A100;
  guScale(&dword_CODE_bss_8007A100, 0.1f, 0.1f, 0.1f);
}
