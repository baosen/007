extern int matrix_buffer_rarelogo_0;
extern int matrix_buffer_gunbarrel_0;
extern int matrix_buffer_rarelogo_1;
extern int matrix_buffer_rarelogo_2;
extern int matrix_buffer_gunbarrel_1;
extern int matrix_buffer_intro_backdrop;
extern int matrix_buffer_intro_bond;
extern unsigned int D_8002A7D0;

void alloc_intro_matrices(void) {
  D_8002A7D0 = 0;
  matrix_buffer_rarelogo_0 = mempAllocBytesInBank(0x80, 4);
  matrix_buffer_gunbarrel_0 = mempAllocBytesInBank(0x40, 4);
  matrix_buffer_rarelogo_1 = mempAllocBytesInBank(0x80, 4);
  matrix_buffer_rarelogo_2 = mempAllocBytesInBank(0x80, 4);
  matrix_buffer_gunbarrel_1 = mempAllocBytesInBank(0x80, 4);
  matrix_buffer_intro_backdrop = mempAllocBytesInBank(0x80, 4);
  matrix_buffer_intro_bond = mempAllocBytesInBank(0x80, 4);
}
