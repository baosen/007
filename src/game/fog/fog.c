struct fog_element {
  unsigned int stageID;
  float blendmultiplier;
  float farfog;
  float nearfog;
  float maxvisrange;
  float maxobfuscationrange;
  float minvisrange;
  unsigned int intensity;
  unsigned int dif_in_light;
  unsigned int far_ambiantlight;
  unsigned char red;
  unsigned char green;
  unsigned char blue;
  unsigned char clouds;
  float cloudrepeat;
  unsigned short skyimageid;
  unsigned short reserved;
  float cloudred;
  float cloudgreen;
  float cloudblue;
  unsigned char iswater;
  unsigned char padding[3];
  float waterrepeat;
  unsigned short waterimageid;
  unsigned short reserved2;
  float waterred;
  float watergreen;
  float waterblue;
  float waterconcavity;
};

struct fog_element2 {
  unsigned int stageID;
  unsigned char red;
  unsigned char green;
  unsigned char blue;
  unsigned char clouds;
  float cloudrepeat;
  unsigned short skyimageid;
  unsigned short reserved;
  float cloudred;
  float cloudgreen;
  float cloudblue;
  unsigned char iswater;
  unsigned char padding[3];
  float waterrepeat;
  unsigned short waterimageid;
  unsigned short reserved2;
  float waterred;
  float watergreen;
  float waterblue;
  float waterconcavity;
};

int sky_enabled;
unsigned int *ptr_nearfog_enviroment_values;
int buffer_far_pervasiveness;
int far_fog;
int D_800825D0;
int D_800825D4;
int flt_CODE_bss_800825D8;
int flt_CODE_bss_800825DC;
int buffer_far_ambiant;
int bg_dif_light;
int env_table_hit;
int env_table_match_start;
int env_table_match_end;
int D_800825F4;
unsigned int dword_CODE_bss_800825F8;

float flt_CODE_bss_800825FC;
float flt_CODE_bss_80082600;
unsigned int DAT_80082604;
unsigned int DAT_80082608;
unsigned int DAT_8008260c;
unsigned int DAT_80082610;
unsigned int DAT_80082614;
unsigned int dword_CODE_bss_80082618;
unsigned int dword_CODE_bss_8008261C;
unsigned char off_CODE_bss_80082620;
unsigned char byte_CODE_bss_80082621;
unsigned char byte_CODE_bss_80082622;
unsigned char byte_CODE_bss_80082623;
unsigned char byte_CODE_bss_80082624;
unsigned char byte_CODE_bss_80082625;
unsigned char byte_CODE_bss_80082626;
unsigned char byte_CODE_bss_80082627;
unsigned char byte_CODE_bss_80082628;
unsigned char byte_CODE_bss_80082629;
unsigned char byte_CODE_bss_8008262a;
unsigned char byte_CODE_bss_8008262b;
unsigned char byte_CODE_bss_8008262c;
unsigned char byte_CODE_bss_8008262d;
unsigned char byte_CODE_bss_8008262e;
unsigned char byte_CODE_bss_8008262f;
unsigned char byte_CODE_bss_80082630;
unsigned char byte_CODE_bss_80082631;
unsigned char byte_CODE_bss_80082632;
unsigned char byte_CODE_bss_80082633;
unsigned char byte_CODE_bss_80082634;
unsigned char byte_CODE_bss_80082635;
unsigned char byte_CODE_bss_80082636;
unsigned char byte_CODE_bss_80082637;
unsigned char byte_CODE_bss_80082638;
unsigned char byte_CODE_bss_80082639;
unsigned char byte_CODE_bss_8008263a;
unsigned char byte_CODE_bss_8008263b;
unsigned char byte_CODE_bss_8008263c;
unsigned char byte_CODE_bss_8008263d;
unsigned char byte_CODE_bss_8008263e;
unsigned char byte_CODE_bss_8008263f;
unsigned char byte_CODE_bss_80082640;
unsigned char byte_CODE_bss_80082641;
unsigned char byte_CODE_bss_80082642;
unsigned char byte_CODE_bss_80082643;
unsigned char byte_CODE_bss_80082644;
unsigned char byte_CODE_bss_80082645;
unsigned char byte_CODE_bss_80082646;
unsigned char byte_CODE_bss_80082647;
unsigned char byte_CODE_bss_80082648;
unsigned char byte_CODE_bss_80082649;
unsigned char byte_CODE_bss_8008264a;
unsigned char byte_CODE_bss_8008264b;
unsigned char byte_CODE_bss_8008264c;
unsigned char byte_CODE_bss_8008264d;
unsigned char byte_CODE_bss_8008264e;
unsigned char byte_CODE_bss_8008264f;
unsigned char byte_CODE_bss_80082650;
unsigned char byte_CODE_bss_80082651;
unsigned char byte_CODE_bss_80082652;
unsigned char byte_CODE_bss_80082653;
unsigned char byte_CODE_bss_80082654;
unsigned char byte_CODE_bss_80082655;
unsigned char byte_CODE_bss_80082656;
unsigned char byte_CODE_bss_80082657;
unsigned char byte_CODE_bss_80082658;
unsigned char byte_CODE_bss_80082659;
unsigned char byte_CODE_bss_8008265a;
unsigned char byte_CODE_bss_8008265b;
unsigned char byte_CODE_bss_8008265c;
unsigned char byte_CODE_bss_8008265d;
unsigned char byte_CODE_bss_8008265e;
unsigned char byte_CODE_bss_8008265f;

int D_80044DC0 = 0;
float near_fog_value = 3.4028235e38;
float near_fog_times_intensity = 0.0;
int ptr_current_data[] = {0x384, 0x3E8, 0, 0, 0, 0, 0, 0, 0,
                          0,     0,     0, 0, 0, 0, 0, 0};

struct fog_element fog_tables[] = {
    {0x16, 15.0, 3500.0,  2000.0, 2500.0, 2000.0, 0.0,   0x3E7, 0x3E4, 0x3E8, 0,
     0,    8,    1,       5000.0, 0,      0,      170.0, 100.0, 40.0,  0,     0,
     0,    0,    -1000.0, 0,      0,      0.0,    0.0,   0.0,   30.0},
    {0x17, 10.0, 10000.0, 2500.0, 5000.0, 800.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0,
     0,    0,    0,       0.0,    0,      0,     0.0, 0.0,   0.0,   0,     0,
     0,    0,    0.0,     0,      0,      0.0,   0.0, 0.0,   0.0},
    {0x18, 10.0, 3000.0,  2000.0, 3000.0, 500.0, 0.0,   0x3E7, 0x3E4, 0x3E8, 0,
     0,    0,    1,       5000.0, 0,      0,     255.0, 255.0, 255.0, 0,     0,
     0,    0,    -1000.0, 0,      0,      0.0,   0.0,   0.0,   0.0},
    {0x19, 10.0, 1500.0, 0.0,    0.0, 0.0, 0.0,   0x3E7, 0x3E4, 0x3E8, 0,
     0,    8,    1,      5000.0, 0,   0,   255.0, 255.0, 255.0, 0,     0,
     0,    0,    0.0,    1,      0,   0.0, 255.0, 255.0, 25.0},
    {0x7D, 20.0, 15000.0, 0.0,    0.0, 0.0, 0.0,   0x3E7, 0x3E4, 0x3E8, 0,
     0,    8,    1,       5000.0, 0,   0,   255.0, 255.0, 255.0, 0,     0,
     0,    0,    0.0,     1,      0,   0.0, 255.0, 255.0, 25.0},
    {0x1D,    10.0,  7500.0, 5000.0, 6000.0, 1000.0, 0.0,    0x3E7,
     0x3E4,   0x3E8, 0x10,   0x18,   0x20,   1,      5000.0, 0,
     0,       225.0, 175.0,  100.0,  0,      0,      0,      0,
     -1000.0, 0,     0,      0.0,    0.0,    0.0,    25.0},
    {0x1E, 10.0, 3000.0,  1600.0, 2000.0, 800.0, 0.0,   0x3E7, 0x3E4, 0x3E8, 0,
     0,    8,    1,       7500.0, 0,      0,     70.0,  199.0, 186.0, 0,     0,
     0,    0,    -1000.0, 1,      0,      0.0,   255.0, 255.0, 25.0},
    {0x1F, 10.0, 5000.0, 0.0,     0.0, 0.0, 0.0,   0x3E7, 0x3E4, 0x3E8, 0x28,
     0,    0,    1,      10000.0, 0,   0,   220.0, 0.0,   20.0,  0,     0,
     0,    0,    0.0,    0,       0,   0.0, 0.0,   0.0,   0.0},
    {0x21,    5.0,   15000.0, 3333.0, 4444.0, 600.0, 0.0,    0x3E7,
     0x3E3,   0x3E8, 0x10,    0x30,   0x60,   1,     5000.0, 0,
     0,       255.0, 255.0,   255.0,  0,      0,     0,      0,
     -1000.0, 0,     0,       0.0,    0.0,    0.0,   0.0},
    {0x3A5,   30.0,  15000.0, 3333.0, 4444.0, 600.0, 0.0,    0x3E7,
     0x3E3,   0x3E8, 0x10,    0x30,   0x60,   1,     5000.0, 0,
     0,       255.0, 255.0,   255.0,  0,      0,     0,      0,
     -1000.0, 0,     0,       0.0,    0.0,    0.0,   0.0},
    {0x22, 10.0, 5000.0,  0.0,    0.0, 0.0, 0.0,   0x3E7, 0x3DE, 0x3E8, 0x10,
     0x20, 0x10, 0,       5000.0, 0,   0,   255.0, 255.0, 255.0, 0,     0,
     0,    0,    -1000.0, 0,      0,   0.0, 0.0,   0.0,   0.0},
    {0x86, 10.0, 1000.0, 0.0,    0.0, 0.0, 0.0,   0x3E7, 0x3DE, 0x3E8, 0x40,
     0x80, 0x40, 0,      5000.0, 0,   0,   255.0, 255.0, 255.0, 0,     0,
     0,    0,    0.0,    0,      0,   0.0, 0.0,   0.0,   0.0},
    {0x23,    10.0,  15000.0, 6000.0, 8000.0, 800.0, 0.0,    0x3E7,
     0x3E4,   0x3E8, 0x10,    0x30,   0x40,   1,     5000.0, 0,
     0,       25.0,  25.0,    25.0,   0,      0,     0,      0,
     -1000.0, 0,     0,       0.0,    0.0,    0.0,   0.0},
    {0x24,  2.0,   2500.0, 4444.0, 5555.0, 800.0, 0.0,     0x3E7,
     0x3E4, 0x3E8, 0x60,   0x60,   0x80,   1,     10000.0, 0,
     0,     240.0, 120.0,  30.0,   0,      0,     0,       0,
     0.0,   1,     0,      0.0,    255.0,  255.0, 7.0},
    {0x25,  10.0,  2500.0, 1500.0, 2500.0, 1000.0, 0.0,    0x3E7,
     0x3E4, 0x3E8, 0x18,   0x20,   0,      0,      5000.0, 0,
     0,     255.0, 255.0,  255.0,  0,      0,      0,      0,
     0.0,   0,     0,      0.0,    0.0,    0.0,    0.0},
    {0x26, 10.0, 6000.0, 0.0,     0.0, 0.0, 0.0,   0x3E7, 0x3E4, 0x3E8, 0x18,
     0x18, 0x28, 1,      10000.0, 0,   0,   160.0, 160.0, 190.0, 0,     0,
     0,    0,    -500.0, 0,       0,   0.0, 0.0,   0.0,   0.0},
    {0x27, 10.0, 6000.0,  0.0,    0.0, 0.0, 0.0,   0x3E7, 0x3E1, 0x3E8, 8,
     0,    8,    0,       5000.0, 0,   0,   255.0, 255.0, 255.0, 0,     0,
     0,    0,    -3000.0, 1,      0,   0.0, 255.0, 255.0, 0.0},
    {0x29,     10.0,  9500.0, 3333.0, 4444.0, 800.0, 0.0,    0x3E7,
     0x3E4,    0x3E8, 0x60,   0x80,   0xA0,   1,     5000.0, 0,
     0,        255.0, 255.0,  0.0,    0,      0,     0,      0,
     -10000.0, 1,     0,      0.0,    255.0,  255.0, 0.0},
    {0x2B,    2.0,   2000.0, 2500.0, 3055.0, 750.0, 0.0,    0x3E7,
     0x3BD,   0x3E8, 0x20,   0x10,   0x10,   1,     5000.0, 0,
     0,       58.0,  17.0,   0.0,    0,      0,     0,      0,
     -1000.0, 1,     0,      0.0,    255.0,  255.0, 20.0},
    {0x3AF,   2.0,   8000.0, 6000.0, 8000.0, 800.0, 0.0,    0x3E7,
     0x3DF,   0x3E8, 0x20,   0x10,   0x10,   1,     5000.0, 0,
     0,       58.0,  17.0,   0.0,    0,      0,     0,      0,
     -1000.0, 1,     0,      0.0,    255.0,  255.0, 0.0},
    {0x1B,    10.0,  10000.0, 1000.0, 15000.0, 750.0, 0.0,    0x3E7,
     0x3E4,   0x41A, 0x10,    0,      0,       1,     5000.0, 0,
     0,       58.0,  17.0,    0.0,    0,       0,     0,      0,
     -1000.0, 1,     0,       0.0,    255.0,   255.0, 0.0},
    {0xD1, 10.0, 2500.0, 0.0, 0.0, 0.0, 0.0,   0x3E7, 0x3E4, 0x3E8, 0x80,
     0x78, 0x70, 0,      0.0, 0,   0,   130.0, 120.0, 110.0, 0,     0,
     0,    0,    0.0,    0,   0,   0.0, 0.0,   0.0,   0.0},
    {0x135, 10.0, 2000.0, 0.0, 0.0, 0.0, 0.0,   0x3E7, 0x3E4, 0x3E8, 0x80,
     0x78,  0x70, 0,      0.0, 0,   0,   130.0, 120.0, 110.0, 0,     0,
     0,     0,    0.0,    0,   0,   0.0, 0.0,   0.0,   0.0},
    {0x199, 10.0, 1500.0, 0.0, 0.0, 0.0, 0.0,   0x3E7, 0x3E4, 0x3E8, 0x80,
     0x78,  0x70, 0,      0.0, 0,   0,   130.0, 120.0, 110.0, 0,     0,
     0,     0,    0.0,    0,   0,   0.0, 0.0,   0.0,   0.0},
    {0xF1,     10.0,  7000.0, 3333.0, 4444.0, 800.0, 0.0,    0x3E7,
     0x3E4,    0x3E8, 0x60,   0x80,   0xA0,   1,     5000.0, 0,
     0,        255.0, 255.0,  0.0,    0,      0,     0,      0,
     -10000.0, 1,     0,      0.0,    255.0,  255.0, 0.0},
    {0x155,    10.0,  5500.0, 3333.0, 4444.0, 800.0, 0.0,    0x3E7,
     0x3E4,    0x3E8, 0x60,   0x80,   0xA0,   1,     5000.0, 0,
     0,        255.0, 255.0,  0.0,    0,      0,     0,      0,
     -10000.0, 1,     0,      0.0,    255.0,  255.0, 0.0},
    {0x1B9,    10.0,  4000.0, 3333.0, 4444.0, 800.0, 0.0,    0x3E7,
     0x3E4,    0x3E8, 0x60,   0x80,   0xA0,   1,     5000.0, 0,
     0,        255.0, 255.0,  0.0,    0,      0,     0,      0,
     -10000.0, 1,     0,      0.0,    255.0,  255.0, 0.0},
    {0xEE, 10.0, 6000.0, 0.0,     0.0, 0.0, 0.0,   0x3E7, 0x3E4, 0x3E8, 0x18,
     0x18, 0x18, 1,      10000.0, 0,   0,   120.0, 120.0, 120.0, 0,     0,
     0,    0,    -500.0, 0,       0,   0.0, 0.0,   0.0,   0.0},
    {0x152, 10.0, 6000.0, 0.0,     0.0, 0.0, 0.0,   0x3E7, 0x3E4, 0x3E8, 0x18,
     0x18,  0x18, 1,      10000.0, 0,   0,   120.0, 120.0, 120.0, 0,     0,
     0,     0,    -500.0, 0,       0,   0.0, 0.0,   0.0,   0.0},
    {0x1B6, 10.0, 6000.0, 0.0,     0.0, 0.0, 0.0,   0x3E7, 0x3E4, 0x3E8, 0x18,
     0x18,  0x18, 1,      10000.0, 0,   0,   120.0, 120.0, 120.0, 0,     0,
     0,     0,    -500.0, 0,       0,   0.0, 0.0,   0.0,   0.0},
    {0xEF, 10.0, 7500.0,  0.0,    0.0, 0.0, 0.0,   0x3E7, 0x3E1, 0x3E8, 8,
     0,    8,    0,       5000.0, 0,   0,   255.0, 255.0, 255.0, 0,     0,
     0,    0,    -3000.0, 1,      0,   0.0, 255.0, 255.0, 0.0},
    {0x153, 10.0, 6000.0,  0.0,    0.0, 0.0, 0.0,   0x3E7, 0x3E1, 0x3E8, 8,
     0,     8,    0,       5000.0, 0,   0,   255.0, 255.0, 255.0, 0,     0,
     0,     0,    -3000.0, 1,      0,   0.0, 255.0, 255.0, 0.0},
    {0x1B7, 10.0, 5000.0,  0.0,    0.0, 0.0, 0.0,   0x3E7, 0x3E1, 0x3E8, 8,
     0,     8,    0,       5000.0, 0,   0,   255.0, 255.0, 255.0, 0,     0,
     0,     0,    -3000.0, 1,      0,   0.0, 255.0, 255.0, 0.0},
    {0xC8, 10.0, 7500.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0,
     0,    0,    0,      0.0, 0,   0,   0.0, 0.0,   0.0,   0,     0,
     0,    0,    0.0,    0,   0,   0.0, 0.0, 0.0,   0.0},
    {0x12C, 10.0, 6000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0,
     0,     0,    0,      0.0, 0,   0,   0.0, 0.0,   0.0,   0,     0,
     0,     0,    0.0,    0,   0,   0.0, 0.0, 0.0,   0.0},
    {0x190, 10.0, 5000.0, 0.0, 0.0, 0.0, 0.0, 0x3E7, 0x3E4, 0x3E8, 0,
     0,     0,    0,      0.0, 0,   0,   0.0, 0.0,   0.0,   0,     0,
     0,     0,    0.0,    0,   0,   0.0, 0.0, 0.0,   0.0},
    {0x28, 10.0, 20000.0, 0.0,    0.0, 0.0, 0.0,   0x3E7, 0x3E4, 0x3E8, 0x18,
     0x50, 0x38, 1,       5000.0, 0,   0,   255.0, 108.0, 0.0,   0,     0,
     0,    0,    -1000.0, 1,      0,   0.0, 255.0, 255.0, 0.0},
    {0xF0, 10.0, 20000.0, 0.0,    0.0, 0.0, 0.0,   0x3E7, 0x3E4, 0x3E8, 0x18,
     0x50, 0x38, 1,       5000.0, 0,   0,   255.0, 108.0, 0.0,   0,     0,
     0,    0,    -1000.0, 1,      0,   0.0, 255.0, 255.0, 0.0},
    {0x154, 10.0, 20000.0, 0.0,    0.0, 0.0, 0.0,   0x3E7, 0x3E4, 0x3E8, 0x18,
     0x50,  0x38, 1,       5000.0, 0,   0,   255.0, 108.0, 0.0,   0,     0,
     0,     0,    -1000.0, 1,      0,   0.0, 255.0, 255.0, 0.0},
    {0x1B8, 10.0, 20000.0, 0.0,    0.0, 0.0, 0.0,   0x3E7, 0x3E4, 0x3E8, 0x18,
     0x50,  0x38, 1,       5000.0, 0,   0,   255.0, 108.0, 0.0,   0,     0,
     0,     0,    -1000.0, 1,      0,   0.0, 255.0, 255.0, 0.0},
    {0xE7, 10.0, 5000.0, 0.0,     0.0, 0.0, 0.0,   0x3E7, 0x3E4, 0x3E8, 0x28,
     0,    0,    1,      10000.0, 0,   0,   220.0, 0.0,   20.0,  0,     0,
     0,    0,    0.0,    0,       0,   0.0, 0.0,   0.0,   0.0},
    {0x14B, 10.0, 5000.0, 0.0,     0.0, 0.0, 0.0,   0x3E7, 0x3E4, 0x3E8, 0x28,
     0,     0,    1,      10000.0, 0,   0,   220.0, 0.0,   20.0,  0,     0,
     0,     0,    0.0,    0,       0,   0.0, 0.0,   0.0,   0.0},
    {0x1AF, 10.0, 5000.0, 0.0,     0.0, 0.0, 0.0,   0x3E7, 0x3E4, 0x3E8, 0x28,
     0,     0,    1,      10000.0, 0,   0,   220.0, 0.0,   20.0,  0,     0,
     0,     0,    0.0,    0,       0,   0.0, 0.0,   0.0,   0.0},
    {0x1C, 10.0, 15000.0, 3000.0, 4000.0, 600.0, 0.0,  0x3E7, 0x3E4, 0x3E8, 0,
     0,    0,    1,       7500.0, 0,      0,     83.0, 72.0,  65.0,  0,     0,
     0,    0,    -5000.0, 0,      0,      0.0,   0.0,  0.0,   0.0},
    {0x80, 30.0, 15000.0, 3000.0, 4000.0, 600.0, 0.0,  0x3E7, 0x3E4, 0x3E8, 0,
     0,    0,    1,       7500.0, 0,      0,     83.0, 72.0,  65.0,  0,     0,
     0,    0,    -5000.0, 0,      0,      0.0,   0.0,  0.0,   0.0},
    {0x20,    10.0,  20000.0, 3000.0, 4000.0, 600.0, 0.0,    0x3E7,
     0x3E4,   0x3E8, 0x10,    0x30,   0x60,   1,     5000.0, 0,
     0,       255.0, 255.0,   255.0,  0,      0,     0,      0,
     -5000.0, 0,     0,       0.0,    0.0,    0.0,   0.0},
    {0x84, 10.0, 10000.0, 3000.0, 4000.0, 600.0, 0.0,  0x3E7, 0x3CC, 0x3E8, 0,
     0,    0,    1,       7500.0, 0,      0,     83.0, 10.0,  10.0,  0,     0,
     0,    0,    -5000.0, 0,      0,      0.0,   0.0,  0.0,   0.0},
    {0}};

struct fog_element2 fog_tables2[] = {
    {0xFFFFFFFF, 0, 0x10, 0x40, 0,   5000.0, 0, 0,   255.0, 255.0, 255.0,
     0,          0, 0,    0,    0.0, 0,      0, 0.0, 0.0,   0.0,   0.0},
    {0x1A, 0x10, 0x30, 0x60, 1,      3000.0, 0, 0,     230.0, 230.0, 230.0,
     1,    0,    0,    0,    -150.0, 2,      0, 255.0, 255.0, 150.0, 0.0},
    {0x36, 0x30, 0x40, 0x10, 0,   5000.0, 0, 0,   255.0, 255.0, 255.0,
     0,    0,    0,    0,    0.0, 0,      0, 0.0, 0.0,   0.0,   0.0},
    {0}};

void sub_GAME_7F0BA720(int a0, int a1) {
  int a = a0;
  int b = a1;
}

int get_ptr_currentdata(void) { return ptr_current_data; }

float get_near_fog_value(void) { return near_fog_value; }

float square_near_fog_value(void) { return near_fog_value * near_fog_value; }

asm(R"
glabel copy_table1_env_to_current
  addiu $sp, $sp, -0x38
  sw    $ra, 0x14($sp)
  lwc1  $f14, 8($a0)
  lwc1  $f12, 4($a0)
  jal   set_page_height
   sw    $a0, 0x38($sp)
  jal   video_related_27
   addiu $a0, $sp, 0x30
  jal   sub_GAME_7F0B4878
   nop   
  lwc1  $f4, 0x30($sp)
  lwc1  $f8, 0x34($sp)
  lw    $a1, 0x38($sp)
  div.s $f6, $f4, $f0
  li    $at, 0x447A0000 # 1000.000000
  lui   $a0, %hi(bg_dif_light)
  addiu $a0, %lo(bg_dif_light) # addiu $a0, $a0, 0x25e4
  lui   $a2, %hi(buffer_far_ambiant)
  addiu $a2, %lo(buffer_far_ambiant) # addiu $a2, $a2, 0x25e0
  lui   $v1, %hi(buffer_far_pervasiveness)
  addiu $v1, %lo(buffer_far_pervasiveness) # addiu $v1, $v1, 0x25c8
  lui   $v0, %hi(ptr_current_data)
  addiu $v0, %lo(ptr_current_data) # addiu $v0, $v0, 0x4dcc
  div.s $f10, $f8, $f0
  swc1  $f6, 0x30($sp)
  mtc1  $at, $f8
  swc1  $f10, 0x34($sp)
  lw    $t6, 0x20($a1)
  mtc1  $t6, $f4
  nop   
  cvt.s.w $f6, $f4
  div.s $f10, $f6, $f8
  mtc1  $at, $f8
  lui   $at, %hi(near_fog_value)
  swc1  $f10, ($a0)
  lw    $t7, 0x24($a1)
  mtc1  $t7, $f4
  addiu $t7, $a1, 0xc
  cvt.s.w $f6, $f4
  lwc1  $f4, 0x34($sp)
  div.s $f10, $f6, $f8
  lwc1  $f6, 0x30($sp)
  sub.s $f14, $f4, $f6
  swc1  $f10, ($a2)
  lwc1  $f16, ($a2)
  mul.s $f8, $f14, $f16
  add.s $f10, $f6, $f8
  swc1  $f10, %lo(near_fog_value)($at)
  lwc1  $f2, ($a0)
  lui   $at, %hi(near_fog_times_intensity)
  mul.s $f4, $f14, $f2
  add.s $f8, $f6, $f4
  swc1  $f8, %lo(near_fog_times_intensity)($at)
  lwc1  $f10, 4($a1)
  li    $at, 0x43000000 # 128.000000
  div.s $f6, $f10, $f0
  sub.s $f10, $f16, $f2
  swc1  $f6, ($v1)
  lwc1  $f4, 8($a1)
  swc1  $f10, 0x18($sp)
  mtc1  $at, $f6
  div.s $f8, $f4, $f0
  lwc1  $f4, 0x18($sp)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f10
  li    $at, 0x43800000 # 256.000000
  lwc1  $f18, ($v1)
  swc1  $f8, 4($v1)
  div.s $f8, $f6, $f4
  lwc1  $f12, 4($v1)
  sub.s $f6, $f10, $f2
  swc1  $f8, 0x20($sp)
  mtc1  $at, $f8
  li    $at, 0x3F800000 # 1.000000
  mul.s $f10, $f6, $f8
  sub.s $f8, $f12, $f18
  swc1  $f8, 0x18($sp)
  mtc1  $at, $f8
  div.s $f6, $f10, $f4
  lwc1  $f10, 0x20($sp)
  li    $at, 0x437F0000 # 255.000000
  neg.s $f4, $f10
  add.s $f10, $f18, $f8
  lwc1  $f8, 0x18($sp)
  swc1  $f6, 0x1c($sp)
  mul.s $f6, $f4, $f12
  nop   
  mul.s $f4, $f6, $f10
  mtc1  $at, $f10
  li    $at, 0x3F800000 # 1.000000
  div.s $f6, $f4, $f8
  mtc1  $at, $f8
  li    $at, 0x437F0000 # 255.000000
  div.s $f4, $f6, $f10
  lwc1  $f10, 0x20($sp)
  add.s $f6, $f12, $f8
  lwc1  $f8, 0x18($sp)
  swc1  $f4, 0x10($v1)
  mul.s $f4, $f6, $f10
  lwc1  $f10, 0x1c($sp)
  div.s $f6, $f4, $f8
  mtc1  $at, $f8
  lui   $at, %hi(ptr_nearfog_enviroment_values)
  add.s $f4, $f6, $f10
  div.s $f6, $f4, $f8
  swc1  $f6, 0x14($v1)
  lw    $t8, 0x20($a1)
  sw    $t8, ($v0)
  lw    $t9, 0x24($a1)
  li    $t8, 1
  sw    $t9, 4($v0)
  lbu   $t0, 0x28($a1)
  sb    $t0, 8($v0)
  lbu   $t1, 0x29($a1)
  sb    $t1, 9($v0)
  lbu   $t2, 0x2a($a1)
  sb    $t2, 0xa($v0)
  lbu   $t3, 0x2b($a1)
  sb    $t3, 0xb($v0)
  lwc1  $f10, 0x2c($a1)
  swc1  $f10, 0xc($v0)
  lh    $t4, 0x30($a1)
  sh    $t4, 0x10($v0)
  lwc1  $f4, 0x34($a1)
  swc1  $f4, 0x14($v0)
  lwc1  $f8, 0x38($a1)
  swc1  $f8, 0x18($v0)
  lwc1  $f6, 0x3c($a1)
  swc1  $f6, 0x1c($v0)
  lbu   $t5, 0x40($a1)
  sb    $t5, 0x20($v0)
  lwc1  $f10, 0x44($a1)
  swc1  $f10, 0x24($v0)
  lh    $t6, 0x48($a1)
  sh    $t6, 0x28($v0)
  lwc1  $f4, 0x4c($a1)
  swc1  $f4, 0x2c($v0)
  lwc1  $f8, 0x50($a1)
  mtc1  $zero, $f4
  swc1  $f8, 0x30($v0)
  lwc1  $f6, 0x54($a1)
  swc1  $f6, 0x34($v0)
  lwc1  $f10, 0x58($a1)
  swc1  $f10, 0x38($v0)
  lwc1  $f8, 0xc($a1)
  c.eq.s $f4, $f8
  nop   
  bc1f  .L7F0BA9B8
   nop   
  lui   $at, %hi(ptr_nearfog_enviroment_values)
  b     .L7F0BA9BC
   sw    $zero, %lo(ptr_nearfog_enviroment_values)($at)
.L7F0BA9B8:
  sw    $t7, %lo(ptr_nearfog_enviroment_values)($at)
.L7F0BA9BC:
  lw    $ra, 0x14($sp)
  lui   $at, %hi(sky_enabled)
  sw    $t8, %lo(sky_enabled)($at)
  jr    $ra
   addiu $sp, $sp, 0x38
");

asm(R"
glabel copy_table2_env_to_current
  lbu   $t6, 4($a0)
  lui   $v0, %hi(ptr_current_data)
  addiu $v0, %lo(ptr_current_data) # addiu $v0, $v0, 0x4dcc
  sb    $t6, 8($v0)
  lbu   $t7, 5($a0)
  sb    $t7, 9($v0)
  lbu   $t8, 6($a0)
  sb    $t8, 0xa($v0)
  lbu   $t9, 7($a0)
  sb    $t9, 0xb($v0)
  lwc1  $f4, 8($a0)
  swc1  $f4, 0xc($v0)
  lh    $t0, 0xc($a0)
  sh    $t0, 0x10($v0)
  lwc1  $f6, 0x10($a0)
  swc1  $f6, 0x14($v0)
  lwc1  $f8, 0x14($a0)
  swc1  $f8, 0x18($v0)
  lwc1  $f10, 0x18($a0)
  swc1  $f10, 0x1c($v0)
  lbu   $t1, 0x1c($a0)
  sb    $t1, 0x20($v0)
  lwc1  $f16, 0x20($a0)
  swc1  $f16, 0x24($v0)
  lh    $t2, 0x24($a0)
  sh    $t2, 0x28($v0)
  lwc1  $f18, 0x28($a0)
  swc1  $f18, 0x2c($v0)
  lwc1  $f4, 0x2c($a0)
  swc1  $f4, 0x30($v0)
  lwc1  $f6, 0x30($a0)
  swc1  $f6, 0x34($v0)
  lwc1  $f8, 0x34($a0)
  jr    $ra
   swc1  $f8, 0x38($v0)
");

void sub_GAME_7F0BAA5C(int a0) { int a = a0; }

asm(R"
.late_rodata
glabel default_near_fog
.word 0x7f7fffff  /*3.4028235e38*/
glabel D_80058D74
.word 0x461c4000  /*10000.0*/
.text
glabel load_enviroment
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  sw    $a1, 0x2c($sp)
  sw    $zero, 0x1c($sp)
  jal   getPlayerCount
   sw    $a0, 0x28($sp)
  li    $at, 1
  lw    $a2, 0x1c($sp)
  lw    $a3, 0x28($sp)
  bne   $v0, $at, .L7F0BAA94
   move  $t0, $v0
  move  $t0, $zero
.L7F0BAA94:
  lui   $at, %hi(default_near_fog)
  lwc1  $f4, %lo(default_near_fog)($at)
  lw    $t6, 0x2c($sp)
  lui   $at, %hi(near_fog_value)
  mtc1  $zero, $f6
  swc1  $f4, %lo(near_fog_value)($at)
  lui   $at, %hi(near_fog_times_intensity)
  beqz  $t6, .L7F0BAB1C
   swc1  $f6, %lo(near_fog_times_intensity)($at)
  lui   $t1, %hi(fog_tables)
  addiu $v1, $t1, %lo(fog_tables)
  lw    $t7, ($v1)
  lui   $t8, %hi(fog_tables) 
  addiu $t8, %lo(fog_tables) # addiu $t8, $t8, 0x4e10
  beqz  $t7, .L7F0BAB1C
   addiu $a0, $a3, 0x384
  lw    $v0, ($t8)
.L7F0BAAD8:
  bne   $a0, $v0, .L7F0BAB0C
   lui   $v0, %hi(env_table_hit)
  addiu $v0, %lo(env_table_hit) # addiu $v0, $v0, 0x25e8
  sw    $v1, ($v0)
  lui   $at, %hi(env_table_match_start)
  sw    $v1, %lo(env_table_match_start)($at)
  lui   $at, %hi(env_table_match_end)
  addiu $t9, $v1, 0x5c
  sw    $t9, %lo(env_table_match_end)($at)
  jal   copy_table1_env_to_current
   lw    $a0, ($v0)
  b     .L7F0BAC9C
   lw    $ra, 0x14($sp)
.L7F0BAB0C:
  lw    $v0, 0x5c($v1)
  addiu $v1, $v1, 0x5c
  bnez  $v0, .L7F0BAAD8
   nop   
.L7F0BAB1C:
  lui   $t1, %hi(fog_tables) 
  addiu $t1, %lo(fog_tables) # addiu $t1, $t1, 0x4e10
  lw    $a1, ($t1)
  lui   $t2, %hi(fog_tables) 
  addiu $t2, %lo(fog_tables) # addiu $t2, $t2, 0x4e10
  beqz  $a1, .L7F0BAB98
   move  $v1, $t1
  sll   $t3, $t0, 2
  subu  $t3, $t3, $t0
  sll   $t3, $t3, 3
  addu  $t3, $t3, $t0
  sll   $t3, $t3, 2
  addu  $a0, $a3, $t3
  lw    $v0, ($t2)
.L7F0BAB54:
  bne   $a0, $v0, .L7F0BAB88
   lui   $v0, %hi(env_table_hit)
  addiu $v0, %lo(env_table_hit) # addiu $v0, $v0, 0x25e8
  sw    $v1, ($v0)
  lui   $at, %hi(env_table_match_start)
  sw    $v1, %lo(env_table_match_start)($at)
  lui   $at, %hi(env_table_match_end)
  addiu $t4, $v1, 0x5c
  sw    $t4, %lo(env_table_match_end)($at)
  jal   copy_table1_env_to_current
   lw    $a0, ($v0)
  b     .L7F0BAC9C
   lw    $ra, 0x14($sp)
.L7F0BAB88:
  lw    $v0, 0x5c($v1)
  addiu $v1, $v1, 0x5c
  bnez  $v0, .L7F0BAB54
   nop   
.L7F0BAB98:
  slti  $at, $t0, 2
  bnezl $at, .L7F0BAC14
   lui   $at, 0x4170
  beqz  $a1, .L7F0BAC10
   move  $v1, $t1
  sll   $a0, $t0, 2
  subu  $a0, $a0, $t0
  sll   $a0, $a0, 3
  lui   $t5, %hi(fog_tables) 
  addiu $t5, %lo(fog_tables) # addiu $t5, $t5, 0x4e10
  addu  $a0, $a0, $t0
  sll   $a0, $a0, 2
  lw    $v0, ($t5)
.L7F0BABCC:
  bne   $a0, $v0, .L7F0BAC00
   lui   $v0, %hi(env_table_hit)
  addiu $v0, %lo(env_table_hit) # addiu $v0, $v0, 0x25e8
  sw    $v1, ($v0)
  lui   $at, %hi(env_table_match_start)
  sw    $v1, %lo(env_table_match_start)($at)
  lui   $at, %hi(env_table_match_end)
  addiu $t6, $v1, 0x5c
  sw    $t6, %lo(env_table_match_end)($at)
  jal   copy_table1_env_to_current
   lw    $a0, ($v0)
  b     .L7F0BAC9C
   lw    $ra, 0x14($sp)
.L7F0BAC00:
  lw    $v0, 0x5c($v1)
  addiu $v1, $v1, 0x5c
  bnez  $v0, .L7F0BABCC
   nop   
.L7F0BAC10:
  li    $at, 0x41700000 # 15.000000
.L7F0BAC14:
  mtc1  $at, $f12
  lui   $at, %hi(D_80058D74)
  lwc1  $f14, %lo(D_80058D74)($at)
  sw    $a2, 0x1c($sp)
  jal   set_page_height
   sw    $a3, 0x28($sp)
  lui   $a0, %hi(fog_tables2)
  lui   $at, %hi(sky_enabled)
  addiu $a0, %lo(fog_tables2) # addiu $a0, $a0, 0x5f50
  sw    $zero, %lo(sky_enabled)($at)
  lw    $t7, ($a0)
  lw    $a2, 0x1c($sp)
  lw    $a3, 0x28($sp)
  beqz  $t7, .L7F0BAC78
   move  $v1, $a0
  lui   $t8, %hi(fog_tables2) 
  addiu $t8, %lo(fog_tables2) # addiu $t8, $t8, 0x5f50
  lw    $v0, ($t8)
.L7F0BAC5C:
  bnel  $a3, $v0, .L7F0BAC6C
   lw    $v0, 0x38($v1)
  move  $a2, $v1
  lw    $v0, 0x38($v1)
.L7F0BAC6C:
  addiu $v1, $v1, 0x38
  bnez  $v0, .L7F0BAC5C
   nop   
.L7F0BAC78:
  bnez  $a2, .L7F0BAC84
   nop   
  move  $a2, $a0
.L7F0BAC84:
  jal   copy_table2_env_to_current
   move  $a0, $a2
  lui   $v0, %hi(env_table_hit)
  addiu $v0, %lo(env_table_hit) # addiu $v0, $v0, 0x25e8
  sw    $zero, ($v0)
  lw    $ra, 0x14($sp)
.L7F0BAC9C:
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel switch_to_solosky2
  lui   $v0, %hi(env_table_match_start)
  lw    $v0, %lo(env_table_match_start)($v0)
  lui   $a0, %hi(dword_CODE_bss_800825F8)
  addiu $a0, %lo(dword_CODE_bss_800825F8) # addiu $a0, $a0, 0x25f8
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  move  $t0, $a0
  move  $t9, $v0
  addiu $t8, $v0, 0x54
.L7F0BACCC:
  lw    $at, ($t9)
  addiu $t9, $t9, 0xc
  addiu $t0, $t0, 0xc
  sw    $at, -0xc($t0)
  lw    $at, -8($t9)
  sw    $at, -8($t0)
  lw    $at, -4($t9)
  bne   $t9, $t8, .L7F0BACCC
   sw    $at, -4($t0)
  lw    $at, ($t9)
  lui   $v1, %hi(env_table_match_end)
  sw    $at, ($t0)
  lw    $t8, 4($t9)
  lui   $at, %hi(flt_CODE_bss_800825FC)
  sw    $t8, 4($t0)
  lw    $v1, %lo(env_table_match_end)($v1)
  lwc1  $f0, 4($v0)
  lwc1  $f4, 4($v1)
  sub.s $f6, $f4, $f0
  mul.s $f8, $f12, $f6
  add.s $f10, $f0, $f8
  swc1  $f10, %lo(flt_CODE_bss_800825FC)($at)
  lwc1  $f2, 8($v0)
  lwc1  $f4, 8($v1)
  lui   $at, %hi(flt_CODE_bss_80082600)
  sub.s $f6, $f4, $f2
  mul.s $f8, $f12, $f6
  add.s $f10, $f2, $f8
  swc1  $f10, %lo(flt_CODE_bss_80082600)($at)
  lw    $t1, 0x20($v0)
  lw    $t2, 0x20($v1)
  lui   $at, %hi(dword_CODE_bss_8008261C)
  mtc1  $t1, $f4
  mtc1  $t2, $f6
  cvt.s.w $f14, $f4
  cvt.s.w $f8, $f6
  sub.s $f10, $f8, $f14
  mul.s $f4, $f12, $f10
  add.s $f6, $f14, $f4
  trunc.w.s $f8, $f6
  mfc1  $t4, $f8
  nop   
  sw    $t4, %lo(dword_CODE_bss_80082618)($at)
  lw    $t5, 0x24($v0)
  lw    $t7, 0x24($v1)
  mtc1  $t5, $f10
  mtc1  $t7, $f4
  cvt.s.w $f16, $f10
  cvt.s.w $f6, $f4
  sub.s $f8, $f6, $f16
  mul.s $f10, $f12, $f8
  add.s $f4, $f16, $f10
  trunc.w.s $f6, $f4
  mfc1  $t8, $f6
  nop   
  sw    $t8, %lo(dword_CODE_bss_8008261C)($at)
  lbu   $t9, 0x28($v0)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t9, $f8
  bgez  $t9, .L7F0BADCC
   cvt.s.w $f18, $f8
  mtc1  $at, $f10
  nop   
  add.s $f18, $f18, $f10
.L7F0BADCC:
  lbu   $t0, 0x28($v1)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t0, $f4
  bgez  $t0, .L7F0BADEC
   cvt.s.w $f6, $f4
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F0BADEC:
  sub.s $f10, $f6, $f18
  li    $t2, 1
  li    $at, 0x4F000000 # 2147483648.000000
  mul.s $f4, $f12, $f10
  add.s $f8, $f18, $f4
  cfc1  $t1, $31
  ctc1  $t2, $31
  nop   
  cvt.w.s $f6, $f8
  cfc1  $t2, $31
  nop   
  andi  $t2, $t2, 0x78
  beql  $t2, $zero, .L7F0BAE6C
   mfc1  $t2, $f6
  mtc1  $at, $f6
  li    $t2, 1
  sub.s $f6, $f8, $f6
  ctc1  $t2, $31
  nop   
  cvt.w.s $f6, $f6
  cfc1  $t2, $31
  nop   
  andi  $t2, $t2, 0x78
  bnez  $t2, .L7F0BAE60
   nop   
  mfc1  $t2, $f6
  lui   $at, 0x8000
  b     .L7F0BAE78
   or    $t2, $t2, $at
.L7F0BAE60:
  b     .L7F0BAE78
   li    $t2, -1
  mfc1  $t2, $f6
.L7F0BAE6C:
  nop   
  bltz  $t2, .L7F0BAE60
   nop   
.L7F0BAE78:
  lui   $at, %hi(off_CODE_bss_80082620)
  sb    $t2, %lo(off_CODE_bss_80082620)($at)
  lbu   $t3, 0x29($v0)
  ctc1  $t1, $31
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t3, $f10
  bgez  $t3, .L7F0BAEA4
   cvt.s.w $f4, $f10
  mtc1  $at, $f8
  nop   
  add.s $f4, $f4, $f8
.L7F0BAEA4:
  swc1  $f4, 0x18($sp)
  lbu   $t4, 0x29($v1)
  lwc1  $f4, 0x18($sp)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t4, $f6
  andi  $t3, $t2, 0xf8
  bgez  $t4, .L7F0BAED0
   cvt.s.w $f10, $f6
  mtc1  $at, $f8
  nop   
  add.s $f10, $f10, $f8
.L7F0BAED0:
  sub.s $f6, $f10, $f4
  li    $t7, 1
  li    $at, 0x4F000000 # 2147483648.000000
  mul.s $f8, $f12, $f6
  add.s $f10, $f4, $f8
  cfc1  $t5, $31
  ctc1  $t7, $31
  nop   
  cvt.w.s $f6, $f10
  cfc1  $t7, $31
  nop   
  andi  $t7, $t7, 0x78
  beql  $t7, $zero, .L7F0BAF50
   mfc1  $t7, $f6
  mtc1  $at, $f6
  li    $t7, 1
  sub.s $f6, $f10, $f6
  ctc1  $t7, $31
  nop   
  cvt.w.s $f6, $f6
  cfc1  $t7, $31
  nop   
  andi  $t7, $t7, 0x78
  bnez  $t7, .L7F0BAF44
   nop   
  mfc1  $t7, $f6
  lui   $at, 0x8000
  b     .L7F0BAF5C
   or    $t7, $t7, $at
.L7F0BAF44:
  b     .L7F0BAF5C
   li    $t7, -1
  mfc1  $t7, $f6
.L7F0BAF50:
  nop   
  bltz  $t7, .L7F0BAF44
   nop   
.L7F0BAF5C:
  lui   $at, %hi(byte_CODE_bss_80082621)
  sb    $t7, %lo(byte_CODE_bss_80082621)($at)
  lbu   $t6, 0x2a($v0)
  ctc1  $t5, $31
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t6, $f4
  andi  $t5, $t7, 0xf8
  bgez  $t6, .L7F0BAF8C
   cvt.s.w $f8, $f4
  mtc1  $at, $f10
  nop   
  add.s $f8, $f8, $f10
.L7F0BAF8C:
  swc1  $f8, 0x1c($sp)
  lbu   $t8, 0x2a($v1)
  lwc1  $f8, 0x1c($sp)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t8, $f6
  bgez  $t8, .L7F0BAFB4
   cvt.s.w $f4, $f6
  mtc1  $at, $f10
  nop   
  add.s $f4, $f4, $f10
.L7F0BAFB4:
  sub.s $f6, $f4, $f8
  li    $t0, 1
  li    $at, 0x4F000000 # 2147483648.000000
  mul.s $f10, $f12, $f6
  add.s $f4, $f8, $f10
  cfc1  $t9, $31
  ctc1  $t0, $31
  nop   
  cvt.w.s $f6, $f4
  cfc1  $t0, $31
  nop   
  andi  $t0, $t0, 0x78
  beql  $t0, $zero, .L7F0BB034
   mfc1  $t0, $f6
  mtc1  $at, $f6
  li    $t0, 1
  sub.s $f6, $f4, $f6
  ctc1  $t0, $31
  nop   
  cvt.w.s $f6, $f6
  cfc1  $t0, $31
  nop   
  andi  $t0, $t0, 0x78
  bnez  $t0, .L7F0BB028
   nop   
  mfc1  $t0, $f6
  lui   $at, 0x8000
  b     .L7F0BB040
   or    $t0, $t0, $at
.L7F0BB028:
  b     .L7F0BB040
   li    $t0, -1
  mfc1  $t0, $f6
.L7F0BB034:
  nop   
  bltz  $t0, .L7F0BB028
   nop   
.L7F0BB040:
  lui   $at, %hi(byte_CODE_bss_80082622)
  sb    $t0, %lo(byte_CODE_bss_80082622)($at)
  ctc1  $t9, $31
  andi  $t8, $t0, 0xf8
  sb    $t3, %lo(off_CODE_bss_80082620)($at)
  sb    $t5, %lo(byte_CODE_bss_80082621)($at)
  jal   copy_table1_env_to_current
   sb    $t8, %lo(byte_CODE_bss_80082622)($at)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0BB070
  lui   $t6, %hi(sky_enabled) 
  lw    $t6, %lo(sky_enabled)($t6)
  bnez  $t6, .L7F0BB088
   nop   
  jr    $ra
   move  $v0, $a0

.L7F0BB088:
  beqz  $a1, .L7F0BB180
   lui   $a3, %hi(ptr_current_data)
  lui   $a3, %hi(ptr_current_data)
  move  $v0, $a0
  lui   $t7, 0xf800
  addiu $a3, %lo(ptr_current_data) # addiu $a3, $a3, 0x4dcc
  sw    $t7, ($v0)
  lbu   $t5, 0xa($a3)
  lbu   $t2, 9($a3)
  lbu   $t9, 8($a3)
  move  $t6, $t5
  sll   $t3, $t2, 0x10
  sll   $t0, $t9, 0x18
  or    $t4, $t0, $t3
  sll   $t7, $t6, 8
  or    $t8, $t4, $t7
  ori   $t9, $t8, 0xff
  addiu $a0, $a0, 8
  lui   $t1, (0xBC000008 >> 16) # lui $t1, 0xbc00
  sw    $t9, 4($v0)
  ori   $t1, (0xBC000008 & 0xFFFF) # ori $t1, $t1, 8
  move  $v1, $a0
  sw    $t1, ($v1)
  lw    $t2, 4($a3)
  lw    $a1, ($a3)
  lui   $t0, (0x0001F400 >> 16) # lui $t0, 1
  ori   $t0, (0x0001F400 & 0xFFFF) # ori $t0, $t0, 0xf400
  subu  $a2, $t2, $a1
  div   $zero, $t0, $a2
  negu  $t4, $a1
  sll   $t7, $t4, 8
  addu  $t8, $t7, $t0
  mflo  $t3
  andi  $t5, $t3, 0xffff
  sll   $t6, $t5, 0x10
  div   $zero, $t8, $a2
  mflo  $t9
  andi  $t1, $t9, 0xffff
  or    $t2, $t6, $t1
  sw    $t2, 4($v1)
  addiu $a0, $a0, 8
  bnez  $a2, .L7F0BB138
   nop   
  break 7
.L7F0BB138:
  li    $at, -1
  bne   $a2, $at, .L7F0BB150
   lui   $at, 0x8000
  bne   $t0, $at, .L7F0BB150
   nop   
  break 6
.L7F0BB150:
  addu  $at, $t0, $zero
  bnez  $a2, .L7F0BB160
   nop   
  break 7
.L7F0BB160:
  li    $at, -1
  bne   $a2, $at, .L7F0BB178
   lui   $at, 0x8000
  bne   $t8, $at, .L7F0BB178
   nop   
  break 6
.L7F0BB178:
  b     .L7F0BB268
   addiu $a1, $a0, 8
.L7F0BB180:
  move  $v0, $a0
  lui   $t0, 0xf800
  addiu $a3, $a3, %lo(ptr_current_data)
  sw    $t0, ($v0)
  lbu   $t1, 0xa($a3)
  lbu   $t8, 9($a3)
  lbu   $t5, 8($a3)
  move  $t2, $t1
  sll   $t9, $t8, 0x10
  sll   $t4, $t5, 0x18
  or    $t6, $t4, $t9
  sll   $t0, $t2, 8
  or    $t3, $t6, $t0
  ori   $t5, $t3, 0xff
  addiu $a0, $a0, 8
  lui   $t7, (0xBC000008 >> 16) # lui $t7, 0xbc00
  sw    $t5, 4($v0)
  ori   $t7, (0xBC000008 & 0xFFFF) # ori $t7, $t7, 8
  move  $v1, $a0
  sw    $t7, ($v1)
  lw    $t8, 4($a3)
  lw    $a1, ($a3)
  lui   $t4, (0x0001F400 >> 16) # lui $t4, 1
  ori   $t4, (0x0001F400 & 0xFFFF) # ori $t4, $t4, 0xf400
  subu  $a2, $t8, $a1
  div   $zero, $t4, $a2
  negu  $t6, $a1
  sll   $t0, $t6, 8
  addu  $t3, $t0, $t4
  mflo  $t9
  andi  $t1, $t9, 0xffff
  sll   $t2, $t1, 0x10
  div   $zero, $t3, $a2
  mflo  $t5
  andi  $t7, $t5, 0xffff
  or    $t8, $t2, $t7
  sw    $t8, 4($v1)
  addiu $a0, $a0, 8
  bnez  $a2, .L7F0BB224
   nop   
  break 7
.L7F0BB224:
  li    $at, -1
  bne   $a2, $at, .L7F0BB23C
   lui   $at, 0x8000
  bne   $t4, $at, .L7F0BB23C
   nop   
  break 6
.L7F0BB23C:
  addu  $at, $t4, $zero
  bnez  $a2, .L7F0BB24C
   nop   
  break 7
.L7F0BB24C:
  li    $at, -1
  bne   $a2, $at, .L7F0BB264
   lui   $at, 0x8000
  bne   $t3, $at, .L7F0BB264
   nop   
  break 6
.L7F0BB264:
  addiu $a1, $a0, 8
.L7F0BB268:
  lui   $t4, 0xb700
  lui   $t9, 1
  sw    $t9, 4($a0)
  sw    $t4, ($a0)
  lui   $t1, (0xBA000402 >> 16) # lui $t1, 0xba00
  ori   $t1, (0xBA000402 & 0xFFFF) # ori $t1, $t1, 0x402
  li    $t6, 32
  sw    $t6, 4($a1)
  sw    $t1, ($a1)
  addiu $v0, $a1, 8
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0BB298
  lui   $t6, %hi(sky_enabled) 
  lw    $t6, %lo(sky_enabled)($t6)
  addiu $v0, $a0, 8
  lui   $t7, 0xb600
  bnez  $t6, .L7F0BB2B8
   lui   $t8, 1
  jr    $ra
   move  $v0, $a0

.L7F0BB2B8:
  sw    $t7, ($a0)
  sw    $t8, 4($a0)
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0BB2C8
  lui   $t6, %hi(sky_enabled) 
  lw    $t6, %lo(sky_enabled)($t6)
  addiu $sp, $sp, -0x30
  sw    $ra, 0x14($sp)
  bnez  $t6, .L7F0BB2E8
   sw    $a1, 0x34($sp)
  b     .L7F0BB388
   li    $v0, 1
.L7F0BB2E8:
  jal   get_BONDdata_position
   sw    $a0, 0x30($sp)
  jal   get_BONDdata_field_10CC
   sw    $v0, 0x1c($sp)
  lw    $v1, 0x1c($sp)
  lw    $a0, 0x30($sp)
  lui   $at, %hi(near_fog_value)
  lwc1  $f6, ($v1)
  lwc1  $f4, ($a0)
  sub.s $f8, $f4, $f6
  swc1  $f8, 0x24($sp)
  lwc1  $f16, 4($v1)
  lwc1  $f10, 4($a0)
  sub.s $f18, $f10, $f16
  lwc1  $f10, 0x24($sp)
  swc1  $f18, 0x28($sp)
  lwc1  $f6, 8($v1)
  lwc1  $f4, 8($a0)
  sub.s $f8, $f4, $f6
  lwc1  $f4, 0x28($sp)
  swc1  $f8, 0x2c($sp)
  lwc1  $f16, ($v0)
  lwc1  $f6, 4($v0)
  mul.s $f18, $f10, $f16
  lwc1  $f16, 8($v0)
  li    $v0, 1
  mul.s $f8, $f4, $f6
  lwc1  $f4, 0x2c($sp)
  mul.s $f6, $f16, $f4
  add.s $f10, $f18, $f8
  lwc1  $f8, 0x34($sp)
  lwc1  $f18, %lo(near_fog_value)($at)
  add.s $f0, $f6, $f10
  add.s $f16, $f18, $f8
  c.lt.s $f16, $f0
  nop   
  bc1f  .L7F0BB388
   nop   
  b     .L7F0BB388
   move  $v0, $zero
.L7F0BB388:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

unsigned int return_nearfog_values(void) {
  return ptr_nearfog_enviroment_values;
}

asm(R"
glabel if_sky_present_convert_values
  lui   $t6, %hi(sky_enabled) 
  lw    $t6, %lo(sky_enabled)($t6)
  bnezl $t6, .L7F0BB3C0
   mtc1  $zero, $f2
  jr    $ra
   li    $v0, 2

  mtc1  $zero, $f2
.L7F0BB3C0:
  lwc1  $f4, 0x18($a0)
  lui   $v0, %hi(ptr_current_data)
  addiu $v0, %lo(ptr_current_data) # addiu $v0, $v0, 0x4dcc
  c.lt.s $f4, $f2
  lui   $v1, %hi(buffer_far_pervasiveness)
  bc1fl .L7F0BB3E8
   lbu   $t7, 8($v0)
  jr    $ra
   li    $v0, 2

  lbu   $t7, 8($v0)
.L7F0BB3E8:
  li    $at, 0x437F0000 # 255.000000
  mtc1  $at, $f12
  mtc1  $t7, $f6
  addiu $v1, $v1, %lo(buffer_far_pervasiveness)
  bgez  $t7, .L7F0BB410
   cvt.s.w $f8, $f6
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f10
  nop   
  add.s $f8, $f8, $f10
.L7F0BB410:
  div.s $f16, $f8, $f12
  li    $at, 0x4F800000 # 4294967296.000000
  swc1  $f16, ($a1)
  lbu   $t8, 9($v0)
  mtc1  $t8, $f18
  bgez  $t8, .L7F0BB438
   cvt.s.w $f4, $f18
  mtc1  $at, $f6
  nop   
  add.s $f4, $f4, $f6
.L7F0BB438:
  div.s $f10, $f4, $f12
  li    $at, 0x4F800000 # 4294967296.000000
  swc1  $f10, 4($a1)
  lbu   $t9, 0xa($v0)
  mtc1  $t9, $f8
  bgez  $t9, .L7F0BB460
   cvt.s.w $f16, $f8
  mtc1  $at, $f18
  nop   
  add.s $f16, $f16, $f18
.L7F0BB460:
  div.s $f6, $f16, $f12
  li    $at, 0x3F800000 # 1.000000
  swc1  $f6, 8($a1)
  lwc1  $f10, 0x18($a0)
  lwc1  $f4, 0x10($v1)
  lwc1  $f18, 0x14($v1)
  div.s $f8, $f4, $f10
  add.s $f16, $f8, $f18
  swc1  $f16, 0xc($a1)
  lwc1  $f0, 0xc($a1)
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F0BB4A4
   mtc1  $at, $f6
  jr    $ra
   li    $v0, 2

  mtc1  $at, $f6
.L7F0BB4A4:
  li    $v0, 1
  c.lt.s $f6, $f0
  nop   
  bc1f  .L7F0BB4C0
   nop   
  jr    $ra
   move  $v0, $zero

.L7F0BB4C0:
  jr    $ra
   nop   
");
