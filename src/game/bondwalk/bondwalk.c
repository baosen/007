#include "color.h"
#include "chrobjdata.h"
#include "player.h"
#include <stddef.h>
#include <types.h>

struct weapon_stats {
  float field_0;
  float pos_x, pos_y, pos_z;
  float field_10;
  float field_14;
  float field_18;
  int ammotype;
  short mag_size;
  unsigned char automatic_firing_rate;
  signed char single_firing_rate;
  unsigned char objects_shoot_through;
  unsigned char sound_trigger_rate;
  short sound;
  struct Gitemheader *ptr_cartridge_struct;
  float destruction_amount;
  float inaccuracy;
  float zoom;
  float field_38;
  float field_3C;
  float sway;
  int recoilspeed;
  float recoil_back, recoil_up, bolt_recoil_back;
  float loudness, loudness2;
  float field_5C;
  float field_60;
  float field_64;
  float field_68;
  unsigned int bitflags;
};

struct gitem_data_struct {
  struct Gitemheader *item_header;
  char *item_file_name;
  int has_no_model;
  struct weapon_stats *item_weapon_stats;
  unsigned short upper_watch_text, lower_watch_text;
  float watch_pos_x, watch_pos_y, watch_pos_z;
  float x_rotation, y_rotation;
  unsigned short weapon_of_choice_text, watch_equipment_text;
  float equip_watch_x, equip_watch_y, equip_watch_z;
};

struct ejected_cart {
  struct Gitemheader *header;
  char *text;
};

int dword_CODE_bss_80075DB0;
int dword_CODE_bss_80075DB4;
int dword_CODE_bss_80075DB8;
int dword_CODE_bss_80075DBC;
int dword_CODE_bss_80075DC0;
int dword_CODE_bss_80075DC4;
char dword_CODE_bss_80075DC8[0x9C];
int dword_CODE_bss_80075E64;
char dword_CODE_bss_80075E68[0xBE0];
int dword_CODE_bss_80076A48;

struct color D_80032440[] = {{0x96, 0x96, 0x96, 0}, {0x96, 0x96, 0x96, 0}};
struct color D_80032448[] = {
    {0xFF, 0xFF, 0xFF, 0}, {0xFF, 0xFF, 0xFF, 0}, {0xB2, 0x4D, 0x2E, 0}};
unsigned int D_80032454 = 0;
unsigned int D_80032458 = 0;
unsigned int size_item_buffer[] = {0x14820, 0x14820};
unsigned int D_80032464[] = {0x7530, 0x7530};
struct ejected_cart ejected_cartridge[] = {{&GcartridgeZ_struct, "GcartridgeZ"},
                                           {&GcartrifleZ_struct, "GcartrifleZ"},
                                           {&GcartblueZ_struct, "GcartblueZ"},
                                           {&GcartshellZ_struct, "GcartshellZ"},
                                           {0, ""}};

#if defined(VERSION_US) || defined(VERSION_EU)
#define SCALEVAL1 0.80000001
#define SCALEVAL_KNIFE 0.80000001
#define SCALEVAL_SKORPIAN 0.80000001
#define SCALEVAL_AK47 0.80000001
#define SCALEVAL_UZI 0.80000001
#define SCALEVAL_P90 0.80000001
#define SCALEVAL_RUGER 0.80000001
#define SCALEVAL_LAUNCHER 0.80000001
#elif VERSION_JP
#define SCALEVAL1 0.8812
#define SCALEVAL_KNIFE 0.8228
#define SCALEVAL_SKORPIAN 0.8695
#define SCALEVAL_AK47 0.893
#define SCALEVAL_UZI 0.8578
#define SCALEVAL_P90 0.8461
#define SCALEVAL_RUGER 0.8344
#define SCALEVAL_LAUNCHER 0.9048
#else
#error "No region defined"
#endif

struct weapon_stats default_weaponstats = {
    1.0, 0.0, 0.0, 0.0,  3.0, 3.0, 8.5, 0,         0,          0xFF, 0x00,
    1,   0,   0,   NULL, 1.0, 0.0, 0.0, SCALEVAL1, 0.89999998, 1.0,  0xFF,
    0.0, 0.0, 0.0, 0.0,  0.0, 0.0, 2.0, 4.0,       0.0,        0x110};
struct weapon_stats GfistZ_stats = {1.0,
                                    11.0,
                                    -50.0,
                                    -33.0,
                                    3.0,
                                    3.0,
                                    8.5,
                                    0,
                                    0,
                                    0xFF,
                                    0x06,
                                    1,
                                    0,
                                    0,
                                    NULL,
                                    2.0,
                                    0.0,
                                    0.0,
                                    SCALEVAL_KNIFE,
                                    0.85000002,
                                    1.0,
                                    0,
                                    0.0,
                                    0.0,
                                    0.0,
                                    0.0,
                                    1.0,
                                    1.0,
                                    2.0,
                                    4.0,
                                    0.0,
                                    0x64D91};
struct weapon_stats GknifeZ_stats = {1.0,
                                     14.0,
                                     -24.799999,
                                     -34.0,
                                     3.0,
                                     3.0,
                                     8.5,
                                     0,
                                     0,
                                     0xFF,
                                     0x06,
                                     1,
                                     0,
                                     0,
                                     NULL,
                                     3.0,
                                     0.0,
                                     0.0,
                                     SCALEVAL_KNIFE,
                                     0.85000002,
                                     1.0,
                                     0,
                                     0.0,
                                     0.0,
                                     0.0,
                                     0.0,
                                     1.0,
                                     1.0,
                                     2.0,
                                     4.0,
                                     0.0,
                                     0x160D91};
struct weapon_stats GthrowknifeZ_stats = {1.0,
                                          14.0,
                                          -24.799999,
                                          -34.0,
                                          3.0,
                                          3.0,
                                          8.5,
                                          0xA,
                                          1,
                                          0xFF,
                                          0x06,
                                          1,
                                          0,
                                          0,
                                          NULL,
                                          3.0,
                                          0.0,
                                          0.0,
                                          SCALEVAL_KNIFE,
                                          0.85000002,
                                          1.0,
                                          0,
                                          0.0,
                                          0.0,
                                          0.0,
                                          0.0,
                                          1.0,
                                          1.0,
                                          2.0,
                                          4.0,
                                          1.0,
                                          0x560D83};
struct weapon_stats GwppkZ_stats = {1.0,
                                    11.0,
                                    -20.799999,
                                    -33.5,
                                    3.0,
                                    3.0,
                                    8.5,
                                    1,
                                    7,
                                    0xFF,
                                    0x10,
                                    1,
                                    0,
                                    0x6B,
                                    &GcartridgeZ_struct,
                                    1.0,
                                    1.0,
                                    0.0,
                                    SCALEVAL_KNIFE,
                                    0.85000002,
                                    1.0,
                                    0x4080300,
                                    3.0,
                                    10.0,
                                    29.999998,
                                    1.0,
                                    12.0,
                                    2.0,
                                    2.0,
                                    4.0,
                                    0.0,
                                    0x170FB9};
struct weapon_stats GwppksilZ_stats = {1.0,
                                       11.0,
                                       -20.799999,
                                       -33.5,
                                       3.0,
                                       3.0,
                                       8.5,
                                       1,
                                       7,
                                       0xFF,
                                       0x10,
                                       1,
                                       0,
                                       0x2E,
                                       &GcartridgeZ_struct,
                                       1.0,
                                       3.0,
                                       0.0,
                                       SCALEVAL_KNIFE,
                                       0.85000002,
                                       1.0,
                                       0x4080300,
                                       1.5,
                                       5.0,
                                       29.999998,
                                       0.0,
                                       5.0,
                                       1.0,
                                       2.0,
                                       4.0,
                                       0.0,
                                       0x170FB9};
struct weapon_stats Gtt33Z_stats = {1.0,
                                    11.0,
                                    -20.799999,
                                    -33.5,
                                    3.0,
                                    3.0,
                                    8.5,
                                    1,
                                    8,
                                    0xFF,
                                    0x10,
                                    1,
                                    0,
                                    0x70,
                                    &GcartridgeZ_struct,
                                    1.0,
                                    6.0,
                                    0.0,
                                    SCALEVAL_KNIFE,
                                    0.85000002,
                                    1.0,
                                    0x4080300,
                                    5.0,
                                    10.0,
                                    59.999996,
                                    2.0,
                                    16.0,
                                    3.0,
                                    2.0,
                                    4.0,
                                    0.0,
                                    0x170FB9};
struct weapon_stats GskorpianZ_stats = {2.0,
                                        11.5,
                                        -25.0,
                                        -27.5,
                                        3.0,
                                        5.0,
                                        10.0,
                                        1,
                                        0x14,
                                        0x03,
                                        0x00,
                                        1,
                                        0xB,
                                        0x6A,
                                        &GcartridgeZ_struct,
                                        0.60000002,
                                        15.0,
                                        0.0,
                                        SCALEVAL_SKORPIAN,
                                        0.88999999,
                                        1.0,
                                        6,
                                        0.0,
                                        0.0,
                                        0.0,
                                        2.0,
                                        20.0,
                                        2.0,
                                        2.0,
                                        4.0,
                                        0.0,
                                        0x170B79};
struct weapon_stats Gak47Z_stats = {
    2.0,  11.0,      -19.0, -16.0,         3.0,
    3.0,  8.5,       3,     0x1E,          0x03,
    0x00, 1,         4,     0x6D,          &GcartrifleZ_struct,
    1.0,  10.0,      30.0,  SCALEVAL_AK47, 0.91000003,
    1.0,  0x40C0006, 4.5,   2.0,           0.0,
    2.0,  20.0,      2.0,   2.0,           4.0,
    3.0,  0x171A7C};
struct weapon_stats GuziZ_stats = {
    3.0,  11.0,      -24.5, -37.0,        3.0,
    8.0,  15.0,      1,     0x20,         0x02,
    0x00, 1,         4,     0x6E,         &GcartridgeZ_struct,
    1.0,  9.0,       0.0,   SCALEVAL_UZI, 0.88,
    1.0,  0x6120006, 4.0,   3.0,          0.0,
    2.0,  20.0,      2.0,   2.0,          4.0,
    0.0,  0x171B79};
struct weapon_stats Gmp5kZ_stats = {2.0,
                                    11.0,
                                    -26.4,
                                    -35.0,
                                    3.0,
                                    8.0,
                                    15.0,
                                    1,
                                    0x1E,
                                    0x03,
                                    0x00,
                                    1,
                                    4,
                                    0x75,
                                    &GcartridgeZ_struct,
                                    1.0,
                                    7.0,
                                    0.0,
                                    SCALEVAL_SKORPIAN,
                                    0.88999999,
                                    1.0,
                                    0x6120006,
                                    4.0,
                                    3.0,
                                    0.0,
                                    2.0,
                                    20.0,
                                    2.0,
                                    2.0,
                                    4.0,
                                    0.0,
                                    0x171A79};
struct weapon_stats Gmp5ksilZ_stats = {2.0,
                                       11.0,
                                       -26.4,
                                       -35.0,
                                       3.0,
                                       8.0,
                                       15.0,
                                       1,
                                       0x1E,
                                       0x03,
                                       0x00,
                                       1,
                                       4,
                                       0x2E,
                                       &GcartridgeZ_struct,
                                       1.0,
                                       9.0,
                                       0.0,
                                       SCALEVAL_SKORPIAN,
                                       0.88999999,
                                       1.0,
                                       0x6120006,
                                       3.5,
                                       2.0,
                                       0.0,
                                       0.0,
                                       7.0,
                                       1.2,
                                       2.0,
                                       4.0,
                                       0.0,
                                       0x171A79};
struct weapon_stats GspectreZ_stats = {2.0,
                                       11.0,
                                       -21.9,
                                       -35.0,
                                       3.0,
                                       8.0,
                                       15.0,
                                       1,
                                       0x32,
                                       0x03,
                                       0x00,
                                       1,
                                       4,
                                       0x6D,
                                       &GcartridgeZ_struct,
                                       1.4,
                                       12.0,
                                       0.0,
                                       SCALEVAL_SKORPIAN,
                                       0.88999999,
                                       1.0,
                                       0x40C0006,
                                       4.5,
                                       2.0,
                                       0.0,
                                       2.0,
                                       20.0,
                                       2.0,
                                       2.0,
                                       4.0,
                                       0.0,
                                       0x171A79};
struct weapon_stats Gm16Z_stats = {
    6.0,  11.0,      -19.200001, -21.5,         3.0,
    3.0,  8.5,       3,          0x1E,          0x02,
    0x00, 2,         5,          0x71,          &GcartblueZ_struct,
    1.4,  6.0,       20.0,       SCALEVAL_AK47, 0.91000003,
    0.5,  0x6120208, 5.0,        2.0,           0.0,
    2.0,  20.0,      2.0,        2.0,           4.0,
    4.0,  0x171A7C};
struct weapon_stats Gfnp90Z_stats = {
    4.0,  12.5,      -25.299999, -32.5,        3.0,
    8.0,  15.0,      1,          0x50,         0x02,
    0x00, 3,         2,          0xFD,         &GcartridgeZ_struct,
    1.8,  6.0,       0.0,        SCALEVAL_P90, 0.87,
    1.0,  0x4080003, 3.5,        2.0,          0.0,
    2.0,  20.0,      2.0,        2.0,          4.0,
    4.0,  0x171A78};
struct weapon_stats GshotgunZ_stats = {
    4.0,        11.0,      -20.6, -19.5,     3.0,
    3.0,        8.5,       4,     5,         0xFF,
    0x0A,       1,         0,     0x79,      &GcartshellZ_struct,
    0.40000001, 20.0,      0.0,   SCALEVAL1, 0.89999998,
    1.0,        0x812080C, 9.0,   10.0,      0.0,
    2.0,        25.0,      4.0,   2.0,       4.0,
    5.0,        0x170AF9};
struct weapon_stats GautoshotZ_stats = {
    4.0,  12.0, -24.1,     -19.0,      3.0, 3.0,       8.5,  4,
    5,    0xFF, 0x0A,      1,          0,   0x74,      NULL, 0.60000002,
    16.0, 0.0,  SCALEVAL1, 0.89999998, 1.0, 0x812080C, 4.5,  3.0,
    0.0,  2.0,  20.0,      3.0,        2.0, 4.0,       5.0,  0x170AF9};
struct weapon_stats GsniperrifleZ_stats = {6.0,
                                           11.0,
                                           -20.700001,
                                           -31.5,
                                           3.0,
                                           3.0,
                                           8.5,
                                           3,
                                           8,
                                           0xFF,
                                           0x10,
                                           1,
                                           0,
                                           0x2E,
                                           &GcartblueZ_struct,
                                           1.0,
                                           0.0,
                                           15.0,
                                           SCALEVAL_AK47,
                                           0.91000003,
                                           0.25,
                                           0,
                                           0.0,
                                           0.0,
                                           0.0,
                                           0.0,
                                           7.0,
                                           1.2,
                                           2.0,
                                           4.0,
                                           0.0,
                                           0x178A70};
struct weapon_stats GrugerZ_stats = {
    2.0, 12.0, -20.799999,     -33.5,      3.0, 3.0,       8.5,  0xC,
    6,   0xFF, 0x14,           0xA,        0,   0x6F,      NULL, 2.0,
    0.0, 0.0,  SCALEVAL_RUGER, 0.86000001, 1.0, 0x81000FF, 12.0, 35.0,
    0.0, 2.0,  20.0,           3.0,        2.0, 4.0,       6.0,  0x170FB9};
struct weapon_stats GgoldengunZ_stats = {1.0,
                                         11.0,
                                         -20.799999,
                                         -33.5,
                                         3.0,
                                         3.0,
                                         8.5,
                                         0xD,
                                         1,
                                         0xFF,
                                         0x00,
                                         1,
                                         0,
                                         0x75,
                                         NULL,
                                         100.0,
                                         0.0,
                                         0.0,
                                         SCALEVAL_KNIFE,
                                         0.85000002,
                                         1.0,
                                         0x40800FF,
                                         5.0,
                                         10.0,
                                         0.0,
                                         1.0,
                                         9.0,
                                         1.5,
                                         2.0,
                                         4.0,
                                         0.0,
                                         0x170F99};
struct weapon_stats GsilverwppkZ_stats = {1.0,
                                          11.0,
                                          -20.799999,
                                          -33.5,
                                          3.0,
                                          3.0,
                                          8.5,
                                          1,
                                          7,
                                          0xFF,
                                          0x10,
                                          0xA,
                                          0,
                                          0x6B,
                                          &GcartridgeZ_struct,
                                          2.0,
                                          1.0,
                                          0.0,
                                          SCALEVAL_KNIFE,
                                          0.85000002,
                                          1.0,
                                          0x4080300,
                                          3.0,
                                          10.0,
                                          29.999998,
                                          1.0,
                                          12.0,
                                          2.0,
                                          2.0,
                                          4.0,
                                          0.0,
                                          0x170FB9};
struct weapon_stats GgoldwppkZ_stats = {1.0,
                                        11.0,
                                        -20.799999,
                                        -33.5,
                                        3.0,
                                        3.0,
                                        8.5,
                                        1,
                                        7,
                                        0xFF,
                                        0x10,
                                        1,
                                        0,
                                        0x6B,
                                        &GcartridgeZ_struct,
                                        100.0,
                                        1.0,
                                        0.0,
                                        SCALEVAL_KNIFE,
                                        0.85000002,
                                        1.0,
                                        0x4080300,
                                        3.0,
                                        10.0,
                                        29.999998,
                                        1.0,
                                        12.0,
                                        2.0,
                                        2.0,
                                        4.0,
                                        0.0,
                                        0x170FB9};
struct weapon_stats GlaserZ_stats = {1.0,
                                     11.0,
                                     -19.5,
                                     -28.0,
                                     3.0,
                                     3.0,
                                     8.5,
                                     0,
                                     0,
                                     0xFF,
                                     0x06,
                                     2,
                                     0,
                                     0xE4,
                                     NULL,
                                     2.0,
                                     0.0,
                                     0.0,
                                     SCALEVAL_SKORPIAN,
                                     0.88999999,
                                     1.0,
                                     0x6000606,
                                     0.0,
                                     0.0,
                                     0.0,
                                     2.0,
                                     16.0,
                                     2.0,
                                     2.0,
                                     4.0,
                                     2.0,
                                     0x170B99};
struct weapon_stats GwatchlaserZ_stats = {1.0,
                                          -2.0,
                                          -21.5,
                                          -19.0,
                                          3.0,
                                          3.0,
                                          8.5,
                                          0x18,
                                          0x3E8,
                                          0xFF,
                                          0x00,
                                          1,
                                          0,
                                          0,
                                          NULL,
                                          2.0,
                                          0.0,
                                          0.0,
                                          SCALEVAL_SKORPIAN,
                                          0.88999999,
                                          1.0,
                                          0xFF,
                                          0.0,
                                          0.0,
                                          0.0,
                                          1.0,
                                          4.0,
                                          0.2,
                                          1.0,
                                          4.0,
                                          0.0,
                                          0x600F91};
struct weapon_stats GgrenadelaunchZ_stats = {1.0,
                                             9.5,
                                             -18.0,
                                             -18.5,
                                             3.0,
                                             3.0,
                                             8.5,
                                             0xB,
                                             6,
                                             0xFF,
                                             0x14,
                                             1,
                                             0,
                                             0xC,
                                             NULL,
                                             1.0,
                                             0.0,
                                             0.0,
                                             SCALEVAL_LAUNCHER,
                                             0.92000002,
                                             1.0,
                                             0x81000FF,
                                             10.5,
                                             15.0,
                                             0.0,
                                             2.0,
                                             20.0,
                                             2.0,
                                             2.0,
                                             4.0,
                                             0.0,
                                             0x120AF1};
struct weapon_stats GrocketlaunchZ_stats = {1.0,
                                            10.5,
                                            -22.200001,
                                            -14.5,
                                            3.0,
                                            3.0,
                                            8.5,
                                            6,
                                            1,
                                            0xFF,
                                            0x14,
                                            1,
                                            0,
                                            0,
                                            NULL,
                                            1.0,
                                            0.0,
                                            0.0,
                                            SCALEVAL_LAUNCHER,
                                            0.92000002,
                                            0.5,
                                            0xFF,
                                            0.0,
                                            0.0,
                                            0.0,
                                            2.0,
                                            25.0,
                                            10.0,
                                            2.0,
                                            4.0,
                                            0.0,
                                            0x120FF1};
struct weapon_stats GgrenadeZ_stats = {1.0,
                                       11.0,
                                       -41.799999,
                                       -33.0,
                                       3.0,
                                       3.0,
                                       8.5,
                                       5,
                                       1,
                                       0xFF,
                                       0x00,
                                       1,
                                       0,
                                       0,
                                       NULL,
                                       1.0,
                                       0.0,
                                       0.0,
                                       SCALEVAL_KNIFE,
                                       0.85000002,
                                       1.0,
                                       0xFF,
                                       0.0,
                                       0.0,
                                       0.0,
                                       0.0,
                                       2.0,
                                       2.0,
                                       2.0,
                                       4.0,
                                       0.0,
                                       0x422982};
struct weapon_stats GtimedmineZ_stats = {1.0,
                                         11.0,
                                         -21.0,
                                         -37.0,
                                         3.0,
                                         3.0,
                                         8.5,
                                         9,
                                         1,
                                         0xFF,
                                         0x06,
                                         1,
                                         0,
                                         0,
                                         NULL,
                                         1.0,
                                         0.0,
                                         0.0,
                                         SCALEVAL_KNIFE,
                                         0.85000002,
                                         1.0,
                                         0,
                                         0.0,
                                         0.0,
                                         0.0,
                                         0.0,
                                         2.0,
                                         2.0,
                                         2.0,
                                         4.0,
                                         0.0,
                                         0x422D82};
struct weapon_stats GproximitymineZ_stats = {1.0,
                                             11.0,
                                             -21.0,
                                             -37.0,
                                             3.0,
                                             3.0,
                                             8.5,
                                             8,
                                             1,
                                             0xFF,
                                             0x06,
                                             1,
                                             0,
                                             0,
                                             NULL,
                                             1.0,
                                             0.0,
                                             0.0,
                                             SCALEVAL_KNIFE,
                                             0.85000002,
                                             1.0,
                                             0,
                                             0.0,
                                             0.0,
                                             0.0,
                                             0.0,
                                             2.0,
                                             2.0,
                                             2.0,
                                             4.0,
                                             0.0,
                                             0x422D82};
struct weapon_stats GremotemineZ_stats = {1.0,
                                          11.0,
                                          -21.0,
                                          -37.0,
                                          3.0,
                                          3.0,
                                          8.5,
                                          7,
                                          1,
                                          0xFF,
                                          0x06,
                                          1,
                                          0,
                                          0,
                                          NULL,
                                          1.0,
                                          0.0,
                                          0.0,
                                          SCALEVAL_KNIFE,
                                          0.85000002,
                                          1.0,
                                          0,
                                          0.0,
                                          0.0,
                                          0.0,
                                          0.0,
                                          2.0,
                                          2.0,
                                          2.0,
                                          4.0,
                                          0.0,
                                          0x422D82};
struct weapon_stats GtriggerZ_stats = {1.0,
                                       -2.0,
                                       -21.5,
                                       -19.0,
                                       3.0,
                                       3.0,
                                       8.5,
                                       0,
                                       0,
                                       0xFF,
                                       0xFF,
                                       1,
                                       0,
                                       0,
                                       NULL,
                                       1.0,
                                       0.0,
                                       0.0,
                                       SCALEVAL_KNIFE,
                                       0.85000002,
                                       1.0,
                                       0,
                                       0.0,
                                       0.0,
                                       0.0,
                                       0.0,
                                       0.0,
                                       2.0,
                                       2.0,
                                       4.0,
                                       0.0,
                                       0x890};
struct weapon_stats GtaserZ_stats = {
    1.0, 16.0, -16.700001, -22.0,      3.0, 3.0,  8.5,  0,
    0,   0xFF, 0x00,       1,          0,   0x64, NULL, 1.0,
    0.0, 0.0,  SCALEVAL1,  0.89999998, 1.0, 0xFF, 0.0,  0.0,
    0.0, 2.0,  10.0,       2.0,        2.0, 4.0,  0.0,  0x620F70};
struct weapon_stats GtankZ_stats = {1.0,
                                    8.0,
                                    -19.200001,
                                    -11.5,
                                    3.0,
                                    3.0,
                                    8.5,
                                    0x1C,
                                    1,
                                    0xFF,
                                    0x14,
                                    1,
                                    0,
                                    0xB,
                                    NULL,
                                    1.0,
                                    0.0,
                                    0.0,
                                    SCALEVAL_LAUNCHER,
                                    0.92000002,
                                    1.0,
                                    0x780078FF,
                                    0.0,
                                    0.0,
                                    0.0,
                                    2.0,
                                    25.0,
                                    10.0,
                                    2.0,
                                    4.0,
                                    0.0,
                                    0x76781};
struct weapon_stats GbombcaseZ_stats = {1.0,
                                        11.0,
                                        -21.0,
                                        -37.0,
                                        3.0,
                                        3.0,
                                        8.5,
                                        0x10,
                                        1,
                                        0xFF,
                                        0x06,
                                        1,
                                        0,
                                        0,
                                        NULL,
                                        1.0,
                                        0.0,
                                        0.0,
                                        SCALEVAL_KNIFE,
                                        0.85000002,
                                        1.0,
                                        0,
                                        0.0,
                                        0.0,
                                        0.0,
                                        0.0,
                                        2.0,
                                        2.0,
                                        2.0,
                                        4.0,
                                        0.0,
                                        0x402D82};
struct weapon_stats GplastiqueZ_stats = {1.0,
                                         11.0,
                                         -21.0,
                                         -37.0,
                                         3.0,
                                         3.0,
                                         8.5,
                                         0x17,
                                         1,
                                         0xFF,
                                         0x06,
                                         1,
                                         0,
                                         0,
                                         NULL,
                                         1.0,
                                         0.0,
                                         0.0,
                                         SCALEVAL_KNIFE,
                                         0.85000002,
                                         1.0,
                                         0,
                                         0.0,
                                         0.0,
                                         0.0,
                                         0.0,
                                         2.0,
                                         2.0,
                                         2.0,
                                         4.0,
                                         0.0,
                                         0x422D82};
struct weapon_stats GflarepistolZ_stats = {1.0,
                                           9.5,
                                           -18.0,
                                           -18.5,
                                           3.0,
                                           3.0,
                                           8.5,
                                           0x11,
                                           1,
                                           0xFF,
                                           0x14,
                                           1,
                                           0,
                                           0xC,
                                           NULL,
                                           1.0,
                                           0.0,
                                           0.0,
                                           SCALEVAL_LAUNCHER,
                                           0.92000002,
                                           1.0,
                                           0x81000FF,
                                           10.5,
                                           15.0,
                                           0.0,
                                           2.0,
                                           20.0,
                                           2.0,
                                           2.0,
                                           4.0,
                                           0.0,
                                           0xAF1};
struct weapon_stats GpitongunZ_stats = {1.0,
                                        9.5,
                                        -18.0,
                                        -18.5,
                                        3.0,
                                        3.0,
                                        8.5,
                                        0x12,
                                        1,
                                        0xFF,
                                        0x14,
                                        1,
                                        0,
                                        0xC,
                                        NULL,
                                        1.0,
                                        0.0,
                                        0.0,
                                        SCALEVAL_LAUNCHER,
                                        0.92000002,
                                        1.0,
                                        0x81000FF,
                                        10.5,
                                        15.0,
                                        0.0,
                                        2.0,
                                        20.0,
                                        2.0,
                                        2.0,
                                        4.0,
                                        0.0,
                                        0xAF1};
struct weapon_stats GbugZ_stats = {1.0,
                                   11.0,
                                   -21.0,
                                   -37.0,
                                   3.0,
                                   3.0,
                                   8.5,
                                   0x14,
                                   1,
                                   0xFF,
                                   0x00,
                                   1,
                                   0,
                                   0,
                                   NULL,
                                   1.0,
                                   0.0,
                                   0.0,
                                   SCALEVAL_KNIFE,
                                   0.85000002,
                                   1.0,
                                   0xFF,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   2.0,
                                   2.0,
                                   4.0,
                                   0.0,
                                   0x402982};
struct weapon_stats GmicrocameraZ_stats = {1.0,
                                           11.0,
                                           -21.0,
                                           -37.0,
                                           3.0,
                                           3.0,
                                           8.5,
                                           0x15,
                                           1,
                                           0xFF,
                                           0x00,
                                           1,
                                           0,
                                           0,
                                           NULL,
                                           1.0,
                                           0.0,
                                           0.0,
                                           SCALEVAL_KNIFE,
                                           0.85000002,
                                           1.0,
                                           0xFF,
                                           0.0,
                                           0.0,
                                           0.0,
                                           0.0,
                                           0.0,
                                           2.0,
                                           2.0,
                                           4.0,
                                           0.0,
                                           0x402982};
struct weapon_stats GwatchmagnetattractZ_stats = {1.0,
                                                  11.0,
                                                  -41.799999,
                                                  -33.0,
                                                  3.0,
                                                  3.0,
                                                  8.5,
                                                  0x19,
                                                  0xA,
                                                  0xFF,
                                                  0xFF,
                                                  1,
                                                  0,
                                                  0,
                                                  NULL,
                                                  1.0,
                                                  0.0,
                                                  0.0,
                                                  SCALEVAL_KNIFE,
                                                  0.85000002,
                                                  1.0,
                                                  0xFF,
                                                  0.0,
                                                  0.0,
                                                  0.0,
                                                  0.0,
                                                  0.0,
                                                  1.0,
                                                  1.0,
                                                  4.0,
                                                  0.0,
                                                  0x602980};
struct weapon_stats GgoldeneyekeyZ_stats = {1.0,
                                            11.0,
                                            -41.799999,
                                            -33.0,
                                            3.0,
                                            3.0,
                                            8.5,
                                            0x16,
                                            1,
                                            0xFF,
                                            0x00,
                                            1,
                                            0,
                                            0,
                                            NULL,
                                            1.0,
                                            0.0,
                                            0.0,
                                            SCALEVAL_KNIFE,
                                            0.85000002,
                                            1.0,
                                            0xFF,
                                            0.0,
                                            0.0,
                                            0.0,
                                            0.0,
                                            0.0,
                                            2.0,
                                            2.0,
                                            4.0,
                                            0.0,
                                            0x482982};
struct weapon_stats GcameraZ_stats = {1.0,
                                      11.0,
                                      -41.799999,
                                      -33.0,
                                      3.0,
                                      3.0,
                                      8.5,
                                      0,
                                      0,
                                      0xFF,
                                      0xFF,
                                      1,
                                      0,
                                      0xF4,
                                      NULL,
                                      1.0,
                                      0.0,
                                      20.0,
                                      SCALEVAL_KNIFE,
                                      0.85000002,
                                      1.0,
                                      0xFF,
                                      0.0,
                                      0.0,
                                      0.0,
                                      0.0,
                                      0.0,
                                      1.0,
                                      1.0,
                                      1.0,
                                      0.0,
                                      0xA990};
struct weapon_stats Csuit_lf_handz_stats = {
    1.0, 0.0, 0.0, 0.0,  3.0, 3.0, 8.5, 0,         0,          0xFF, 0x00,
    1,   0,   0,   NULL, 1.0, 0.0, 0.0, SCALEVAL1, 0.89999998, 1.0,  0xFF,
    0.0, 0.0, 0.0, 0.0,  0.0, 2.0, 2.0, 4.0,       0.0,        0x110};
struct weapon_stats GjoypadZ_stats = {
    1.0, 0.0, 0.0, 0.0,  3.0, 3.0, 8.5, 0,         0,          0xFF, 0x00,
    1,   0,   0,   NULL, 1.0, 0.0, 0.0, SCALEVAL1, 0.89999998, 1.0,  0xFF,
    0.0, 0.0, 0.0, 0.0,  0.0, 2.0, 2.0, 4.0,       0.0,        0x110};
struct weapon_stats stru_D_800337D4 = {
    1.0, 0.0, 0.0, 0.0,  3.0, 3.0, 8.5, 6,         0,          0xFF, 0x00,
    1,   0,   0,   NULL, 1.0, 0.0, 0.0, SCALEVAL1, 0.89999998, 1.0,  0xFF,
    0.0, 0.0, 0.0, 0.0,  0.0, 2.0, 2.0, 4.0,       0.0,        0x110};
struct weapon_stats stru_D_80033844 = {
    1.0, 0.0, 0.0, 0.0,  3.0, 3.0, 8.5, 0xB,       0,          0xFF, 0x00,
    1,   0,   0,   NULL, 1.0, 0.0, 0.0, SCALEVAL1, 0.89999998, 1.0,  0xFF,
    0.0, 0.0, 0.0, 0.0,  0.0, 2.0, 2.0, 4.0,       0.0,        0x110};
struct weapon_stats stru_D_800338B4 = {1.0,
                                       11.0,
                                       -41.799999,
                                       -33.0,
                                       3.0,
                                       3.0,
                                       8.5,
                                       0x1D,
                                       0,
                                       0xFF,
                                       0x00,
                                       1,
                                       0,
                                       0,
                                       NULL,
                                       1.0,
                                       0.0,
                                       0.0,
                                       SCALEVAL_KNIFE,
                                       0.85000002,
                                       1.0,
                                       0xFF,
                                       0.0,
                                       0.0,
                                       0.0,
                                       0.0,
                                       0.0,
                                       2.0,
                                       2.0,
                                       4.0,
                                       0.0,
                                       0x82182};

struct gitem_data_struct gitem_structs[] = {
    {NULL, NULL, 1, NULL, 0x9883, 0x9811, 0.0, 0.0, 1000.0, 0.0, 0.0, 0x9811,
     0x9811, 10.0, 10.0, 1000.0},
    {&GfistZ_header, "GfistZ", 0, &GfistZ_stats, 0x9883, 0x9876, 0.0, 0.0,
     1000.0, 0.0, 0.0, 0x9876, 0x98CD, 10.0, 10.0, 1000.0},
    {&GknifeZ_header, "GknifeZ", 0, &GknifeZ_stats, 0x9883, 0x9846, 200.0, 39.0,
     1327.0, 0.0, 0.0, 0x9840, 0x98A8, 38.0, 118.0, 800.0},
    {&GthrowknifeZ_struct, "GthrowknifeZ", 0, &GthrowknifeZ_stats, 0x9871,
     0x9806, 200.0, 51.0, 1327.0, 0.0, 0.0, 0x9870, 0x98CA, 38.0, 118.0, 800.0},
    {&GwppkZ_struct, "GwppkZ", 0, &GwppkZ_stats, 0x9857, 0x9801, 20.0, 97.0,
     579.0, 0.0, 0.0, 0x9856, 0x98BA, 94.0, 2.0, 356.0},
    {&GwppksilZ_struct, "GwppksilZ", 0, &GwppksilZ_stats, 0x9803, 0x9810, 26.0,
     162.0, 668.0, 0.0, 0.0, 0x9855, 0x98B9, 169.0, 5.0, 535.0},
    {&Gtt33Z_struct, "Gtt33Z", 0, &Gtt33Z_stats, 0x9804, 0x9832, 22.0, 128.0,
     709.0, 0.0, 0.0, 0x982A, 0x989A, 124.0, 14.0, 455.0},
    {&GskorpianZ_struct, "GskorpionZ", 0, &GskorpianZ_stats, 0x9883, 0x986B,
     46.0, 124.0, 785.0, 0.0, 0.0, 0x986B, 0x98C6, 124.0, 32.0, 545.0},
    {&Gak47Z_struct, "Gak47Z", 0, &Gak47Z_stats, 0x9808, 0x9868, -29.0, 307.0,
     1410.0, 0.0, 0.0, 0x9842, 0x98AB, 304.0, -31.0, 1020.0},
    {&GuziZ_struct, "GuziZ", 0, &GuziZ_stats, 0x9883, 0x9882, -18.0, 57.0,
     1198.0, 0.0, 0.0, 0x9882, 0x98D7, 68.0, -49.0, 667.0},
    {&Gmp5kZ_struct, "Gmp5kZ", 0, &Gmp5kZ_stats, 0x9800, 0x982F, 12.0, 112.0,
     1300.0, 0.0, 0.0, 0x9829, 0x9896, 123.0, -2.0, 628.0},
    {&Gmp5ksilZ_struct, "Gmp5ksilZ", 0, &Gmp5ksilZ_stats, 0x9800, 0x9810, 14.0,
     227.0, 1300.0, 0.0, 0.0, 0x9828, 0x9895, 226.0, -10.0, 834.0},
    {&GspectreZ_struct, "GspectreZ", 0, &GspectreZ_stats, 0x9883, 0x9858, -4.0,
     144.0, 1128.0, 0.0, 0.0, 0x9858, 0x98B4, 146.0, -18.0, 801.0},
    {&Gm16Z_struct, "Gm16Z", 0, &Gm16Z_stats, 0x9875, 0x9812, 25.0, 251.0,
     1796.0, 0.0, 0.0, 0x9874, 0x9884, 246.0, -45.0, 1497.0},
    {&Gfnp90Z_struct, "Gfnp90Z", 0, &Gfnp90Z_stats, 0x9883, 0x985E, 88.0, -44.0,
     1107.0, 0.0, 0.0, 0x985E, 0x98BC, -44.0, 31.0, 867.0},
    {&GshotgunZ_struct, "GshotgunZ", 0, &GshotgunZ_stats, 0x9883, 0x9864, 39.0,
     283.0, 1224.0, 0.0, 0.0, 0x9864, 0x98C1, 284.0, -22.0, 999.0},
    {&GautoshotZ_struct, "GautoshotZ", 0, &GautoshotZ_stats, 0x9816, 0x980C,
     73.0, 285.0, 1224.0, 0.0, 0.0, 0x9815, 0x9886, 284.0, 4.0, 980.0},
    {&GsniperrifleZ_struct, "GsniperrifleZ", 0, &GsniperrifleZ_stats, 0x9867,
     0x980A, 49.0, 265.0, 1760.0, 0.0, 0.0, 0x9866, 0x98C3, 268.0, 14.0,
     1497.0},
    {&GrugerZ_struct, "GrugerZ", 0, &GrugerZ_stats, 0x9826, 0x984C, 47.0, 184.0,
     769.0, 0.0, 0.0, 0x9825, 0x9893, 182.0, 36.0, 604.0},
    {&GgoldengunZ_struct, "GgoldengunZ", 0, &GgoldengunZ_stats, 0x983B, 0x9805,
     29.0, 146.0, 629.0, 0.0, 0.0, 0x9839, 0x98A3, 144.0, 18.0, 464.0},
    {&GsilverwppkZ_struct, "GsilverwppkZ", 0, &GsilverwppkZ_stats, 0x9883,
     0x9865, 20.0, 97.0, 579.0, 0.0, 0.0, 0x9865, 0x98C2, 94.0, 2.0, 356.0},
    {&GgoldwppkZ_struct, "GgoldwppkZ", 0, &GgoldwppkZ_stats, 0x9883, 0x9838,
     20.0, 97.0, 579.0, 0.0, 0.0, 0x9838, 0x98A2, 94.0, 2.0, 356.0},
    {&GlaserZ_struct, "GlaserZ", 0, &GlaserZ_stats, 0x9852, 0x9847, 67.0, 106.0,
     738.0, 0.0, 0.0, 0x9851, 0x98AC, 103.0, 21.0, 545.0},
    {&GwatchlaserZ_struct, "GwatchlaserZ", 0, &GwatchlaserZ_stats, 0x987F,
     0x9847, 82.0, 0.0, 2857.0, 0.0, 90.0, 0x987B, 0x98D2, 0.0, -40.0, 1383.0},
    {&GgrenadelaunchZ_struct, "GgrenadelaunchZ", 0, &GgrenadelaunchZ_stats,
     0x983D, 0x9848, 27.0, 279.0, 1152.0, 0.0, 0.0, 0x983C, 0x98A5, 284.0,
     -22.0, 960.0},
    {&GrocketlaunchZ_struct, "GrocketlaunchZ", 0, &GrocketlaunchZ_stats, 0x980B,
     0x9848, 111.0, -50.0, 1624.0, 0.0, 0.0, 0x9861, 0x98BF, -42.0, 16.0,
     1381.0},
    {&GgrenadeZ_struct, "GgrenadeZ", 0, &GgrenadeZ_stats, 0x9883, 0x983D, 180.0,
     0.0, 2745.0, 0.0, 90.0, 0x983E, 0x98A6, 0.0, 48.0, 1468.0},
    {&GtimedmineZ_struct, "GtimedmineZ", 0, &GtimedmineZ_stats, 0x9809, 0x980F,
     8.0, 0.0, 364.0, 90.0, 0.0, 0x9872, 0x98CB, 0.0, -3.0, 179.0},
    {&GproximitymineZ_struct, "GproximitymineZ", 0, &GproximitymineZ_stats,
     0x9802, 0x980D, 8.0, 0.0, 364.0, 90.0, 0.0, 0x985D, 0x98BB, 0.0, -3.0,
     179.0},
    {&GremotemineZ_struct, "GremotemineZ", 0, &GremotemineZ_stats, 0x9807,
     0x980E, 8.0, 0.0, 364.0, 90.0, 0.0, 0x9860, 0x98BE, 0.0, -3.0, 179.0},
    {&GtriggerZ_struct, "GtriggerZ", 0, &GtriggerZ_stats, 0x9883, 0x982E, 82.0,
     0.0, 2857.0, 0.0, 90.0, 0x982E, 0x989B, 0.0, -40.0, 1383.0},
    {&GtaserZ_struct, "GtaserZ", 0, &GtaserZ_stats, 0x9883, 0x986F, 107.0, 49.0,
     568.0, 0.0, 0.0, 0x986F, 0x98C9, 64.0, 80.0, 333.0},
    {NULL, NULL, 0, &GtankZ_stats, 0x9883, 0x986E, 20.0, 97.0, 579.0, 0.0, 0.0,
     0x986E, 0x98C8, 94.0, 2.0, 356.0},
    {&GbombcaseZ_struct, "GbombcaseZ", 0, &GbombcaseZ_stats, 0x9883, 0x981A,
     16.0, 0.0, 568.0, 0.0, 90.0, 0x981A, 0x988A, 0.0, -8.0, 323.0},
    {&GplastiqueZ_struct, "GplastiqueZ", 0, &GplastiqueZ_stats, 0x9883, 0x985B,
     28.0, 0.0, 1062.0, 80.0, 90.0, 0x985B, 0x98B7, 0.0, -16.0, 739.0},
    {&GflarepistolZ_struct, "GflarepistolZ", 0, &GflarepistolZ_stats, 0x9883,
     0x9834, 0.0, 0.0, 1000.0, 0.0, 0.0, 0x9834, 0x989F, 0.0, 0.0, 1000.0},
    {&GpitongunZ_struct, "GpitongunZ", 0, &GpitongunZ_stats, 0x9883, 0x9859,
     0.0, 0.0, 1000.0, 0.0, 0.0, 0x9859, 0x98B5, 0.0, 0.0, 1000.0},
    {&GbungeeZ_struct, "GbungeeZ", 1, NULL, 0x9883, 0x981F, 0.0, 0.0, 1000.0,
     0.0, 0.0, 0x981F, 0x988F, 0.0, 0.0, 1000.0},
    {&GdoordecoderZ_struct, "GdoordecoderZ", 1, NULL, 0x9883, 0x9830, 12.0, 0.0,
     364.0, 90.0, 90.0, 0x9830, 0x989C, 0.0, -6.0, 199.0},
    {&GbombdefuserZ_struct, "GbombdefuserZ", 1, NULL, 0x9883, 0x981B, 14.0, 0.0,
     379.0, 90.0, 90.0, 0x981B, 0x988B, 0.0, 0.0, 279.0},
    {&GcameraZ_struct, "GcameraZ", 0, &GcameraZ_stats, 0x9883, 0x9820, 4.0, 0.0,
     195.0, 20.0, 90.0, 0x9820, 0x9890, 0.0, -2.0, 144.0},
    {&GlockexploderZ_struct, "GlockexploderZ", 1, NULL, 0x9883, 0x984A, 0.0,
     0.0, 1000.0, 0.0, 0.0, 0x984A, 0x98AE, 0.0, 0.0, 1000.0},
    {&GdoorexploderZ_struct, "GdoorexploderZ", 1, NULL, 0x9883, 0x9831, 0.0,
     0.0, 1000.0, 0.0, 0.0, 0x9831, 0x989D, 0.0, 0.0, 1000.0},
    {&GbriefcaseZ_struct, "GbriefcaseZ", 1, NULL, 0x9883, 0x981C, 16.0, 0.0,
     568.0, 0.0, 90.0, 0x981C, 0x988C, 0.0, -8.0, 323.0},
    {&GweaponcaseZ_struct, "GweaponcaseZ", 1, NULL, 0x9883, 0x9880, 16.0, 0.0,
     568.0, 0.0, 90.0, 0x9880, 0x98D5, 0.0, -8.0, 323.0},
    {&GsafecrackercaseZ_struct, "GsafecrackercaseZ", 1, NULL, 0x9883, 0x9863,
     16.0, 0.0, 568.0, 0.0, 90.0, 0x9862, 0x98C0, 0.0, -8.0, 323.0},
    {&GkeyanalysercaseZ_struct, "GkeyanalysercaseZ", 1, NULL, 0x9883, 0x9844,
     16.0, 0.0, 568.0, 0.0, 90.0, 0x9843, 0x98A9, 0.0, -8.0, 323.0},
    {&GbugZ_struct, "GbugZ", 0, &GbugZ_stats, 0x9883, 0x981E, 16.0, 0.0, 513.0,
     0.0, 90.0, 0x981E, 0x988E, 0.0, -6.0, 387.0},
    {&GmicrocameraZ_struct, "GmicrocameraZ", 0, &GmicrocameraZ_stats, 0x9883,
     0x984E, 8.0, 0.0, 310.0, 0.0, 270.0, 0x984E, 0x98B0, 0.0, -8.0, 229.0},
    {&GbugdetectorZ_struct, "GbugdetectorZ", 1, NULL, 0x9883, 0x981D, 0.0, 0.0,
     1000.0, 0.0, 0.0, 0x981D, 0x988D, 0.0, 0.0, 1000.0},
    {&GexplosivefloppyZ_struct, "GexplosivefloppyZ", 1, NULL, 0x9883, 0x9833,
     12.0, 0.0, 336.0, 0.0, 90.0, 0x9833, 0x989E, 0.0, -4.0, 176.0},
    {&GpolarizedglassesZ_struct, "GpolarizedglassesZ", 1, NULL, 0x9883, 0x985C,
     2.0, 0.0, 183.0, 15.0, 90.0, 0x985C, 0x98B8, 0.0, 0.0, 147.0},
    {&GdarkglassesZ_struct, "GdarkglassesZ", 1, NULL, 0x9883, 0x982B, 0.0, 0.0,
     1000.0, 0.0, 0.0, 0x982B, 0x9897, 0.0, 0.0, 1000.0},
    {&GcreditcardZ_struct, "GcreditcardZ", 1, NULL, 0x9883, 0x9827, 0.0, 0.0,
     1000.0, 0.0, 0.0, 0x9827, 0x9894, 0.0, 0.0, 1000.0},
    {&GgaskeyringZ_struct, "GgaskeyringZ", 1, NULL, 0x9883, 0x9835, 26.0, 0.0,
     769.0, 90.0, 90.0, 0x9835, 0x98A0, 0.0, -8.0, 387.0},
    {&GdatathiefZ_struct, "GdatathiefZ", 1, NULL, 0x9883, 0x982D, 16.0, 0.0,
     474.0, 80.0, 0.0, 0x982D, 0x9899, 0.0, -6.0, 350.0},
    {&GwatchidentifierZ_struct, "GwatchidentifierZ", 1, NULL, 0x987F, 0x9841,
     82.0, 0.0, 2857.0, 0.0, 90.0, 0x987A, 0x98D1, 0.0, -40.0, 1383.0},
    {&GwatchcommunicatorZ_struct, "GwatchcommunicatorZ", 1, NULL, 0x987F,
     0x9823, 82.0, 0.0, 2857.0, 0.0, 90.0, 0x9878, 0x98CF, 0.0, -40.0, 1383.0},
    {&GwatchgeigercounterZ_struct, "GwatchgeigercounterZ", 1, NULL, 0x987F,
     0x9836, 82.0, 0.0, 2857.0, 0.0, 90.0, 0x9879, 0x98D0, 0.0, -40.0, 1383.0},
    {&GwatchmagnetrepelZ_struct, "GwatchmagnetrepelZ", 1, NULL, 0x987F, 0x984B,
     82.0, 0.0, 2857.0, 0.0, 90.0, 0x987D, 0x98D4, 0.0, -40.0, 1383.0},
    {&GwatchmagnetattractZ_struct, "GwatchmagnetattractZ", 0,
     &GwatchmagnetattractZ_stats, 0x987E, 0x9813, 80.0, 0.0, 3036.0, 0.0, 90.0,
     0x987C, 0x98D3, 0.0, -40.0, 1383.0},
    {&GgoldeneyekeyZ_struct, "GgoldeneyekeyZ", 0, &GgoldeneyekeyZ_stats, 0x9883,
     0x983A, 18.0, 0.0, 560.0, 80.0, 0.0, 0x983A, 0x98A4, 0.0, -4.0, 310.0},
    {&GblackboxZ_struct, "GblackboxZ", 1, NULL, 0x9883, 0x9817, 18.0, 0.0,
     545.0, 0.0, 90.0, 0x9817, 0x9887, 0.0, -8.0, 380.0},
    {&GcircuitboardZ_struct, "GcircuitboardZ", 1, NULL, 0x9883, 0x9821, 20.0,
     0.0, 568.0, 80.0, 0.0, 0x9821, 0x9891, 0.0, 0.0, 394.0},
    {&GclipboardZ_struct, "GclipboardZ", 1, NULL, 0x9883, 0x9822, 40.0, 0.0,
     1151.0, 80.0, 90.0, 0x9822, 0x9892, 0.0, -20.0, 580.0},
    {&GstafflistZ_struct, "GstafflistZ", 1, NULL, 0x9883, 0x986C, 44.0, 0.0,
     1274.0, 80.0, 90.0, 0x986C, 0x98C7, 0.0, -16.0, 681.0},
    {&GdossierredZ_struct, "GdossierredZ", 1, NULL, 0x9883, 0x985F, 38.0, 0.0,
     1084.0, 350.0, 90.0, 0x985F, 0x98BD, 0.0, -12.0, 580.0},
    {&GplansZ_struct, "GplansZ", 1, NULL, 0x9883, 0x985A, 18.0, 0.0, 464.0,
     350.0, 90.0, 0x985A, 0x98B6, 0.0, -2.0, 253.0},
    {&GspyfileZ_struct, "GspyfileZ", 1, NULL, 0x9883, 0x986A, 0.0, 0.0, 1000.0,
     0.0, 0.0, 0x986A, 0x98C5, 0.0, 0.0, 1000.0},
    {&GblueprintsZ_struct, "GblueprintsZ", 1, NULL, 0x9883, 0x9818, 18.0, 0.0,
     579.0, 350.0, 90.0, 0x9818, 0x9888, 0.0, -8.0, 364.0},
    {&GmapZ_struct, "GmapZ", 1, NULL, 0x9883, 0x984D, 18.0, 0.0, 579.0, 350.0,
     90.0, 0x984D, 0x98AF, 0.0, -6.0, 364.0},
    {&GaudiotapeZ_struct, "GaudiotapeZ", 1, NULL, 0x9883, 0x9814, 16.0, 0.0,
     428.0, 90.0, 90.0, 0x9814, 0x9885, 0.0, -2.0, 292.0},
    {&GvideotapeZ_struct, "GvideotapeZ", 1, NULL, 0x9883, 0x9877, 26.0, 0.0,
     753.0, 90.0, 0.0, 0x9877, 0x98CE, 0.0, -8.0, 395.0},
    {&GdattapeZ_struct, "GdattapeZ", 1, NULL, 0x9883, 0x982C, 14.0, 0.0, 387.0,
     90.0, 90.0, 0x982C, 0x9898, 0.0, 0.0, 238.0},
    {&GspooltapeZ_struct, "GspooltapeZ", 1, NULL, 0x9883, 0x9869, 0.0, 0.0,
     1000.0, 0.0, 0.0, 0x9869, 0x98C4, 0.0, 0.0, 1000.0},
    {&GmicrofilmZ_struct, "GmicrofilmZ", 1, NULL, 0x9883, 0x9850, 0.0, 0.0,
     1000.0, 0.0, 0.0, 0x9850, 0x98B2, 0.0, 0.0, 1000.0},
    {&GmicrocodeZ_struct, "GmicrocodeZ", 1, NULL, 0x9883, 0x984F, 0.0, 0.0,
     1000.0, 0.0, 0.0, 0x984F, 0x98B1, 0.0, 0.0, 1000.0},
    {&GlectreZ_struct, "GlectreZ", 1, NULL, 0x9883, 0x9849, 0.0, 0.0, 1000.0,
     0.0, 0.0, 0x9849, 0x98AD, 0.0, 0.0, 1000.0},
    {&GmoneyZ_struct, "GmoneyZ", 1, NULL, 0x9883, 0x9853, 0.0, 0.0, 1000.0, 0.0,
     0.0, 0x9853, 0x98B3, 0.0, 0.0, 1000.0},
    {&GgoldbarZ_struct, "GgoldbarZ", 1, NULL, 0x9883, 0x9837, 0.0, 0.0, 1000.0,
     0.0, 0.0, 0x9837, 0x98A1, 0.0, 0.0, 1000.0},
    {&GheroinZ_struct, "GheroinZ", 1, NULL, 0x9883, 0x983F, 0.0, 0.0, 1000.0,
     0.0, 0.0, 0x983F, 0x98A7, 0.0, 0.0, 1000.0},
    {&GkeycardZ_struct, "GkeycardZ", 1, NULL, 0x9883, 0x9845, 24.0, 0.0, 556.0,
     80.0, 90.0, 0x9845, 0x98AA, 0.0, -6.0, 411.0},
    {&GkeyyaleZ_struct, "GkeyyaleZ", 1, NULL, 0x9883, 0x9881, 64.0, 0.0, 1912.0,
     260.0, 90.0, 0x9881, 0x98D6, 0.0, -18.0, 1568.0},
    {&GkeyboltZ_struct, "GkeyboltZ", 1, NULL, 0x9883, 0x9819, 78.0, 0.0, 3518.0,
     80.0, 90.0, 0x9819, 0x9889, 0.0, -12.0, 2582.0},
    {(struct Gitemheader *)&Csuit_lf_handz_struct, "Csuit_lf_handZ", 0,
     &Csuit_lf_handz_stats, 0x9883, 0x986D, 0.0, 0.0, 1000.0, 0.0, 0.0, 0x9883,
     0x9883, 10.0, 10.0, 1000.0},
    {&GjoypadZ_struct, "GjoypadZ", 0, &GjoypadZ_stats, 0x9883, 0x9824, 0.0, 0.0,
     1000.0, 0.0, 0.0, 0x9883, 0x9883, 10.0, 10.0, 1000.0},
    {NULL, NULL, 0, &stru_D_800337D4, 0x9883, 0x9854, 0.0, 0.0, 1000.0, 0.0,
     0.0, 0x9883, 0x9883, 10.0, 10.0, 1000.0},
    {NULL, NULL, 0, &stru_D_80033844, 0x9883, 0x9854, 0.0, 0.0, 1000.0, 0.0,
     0.0, 0x9883, 0x9883, 10.0, 10.0, 1000.0},
    {NULL, NULL, 0, &stru_D_800338B4, 0x9883, 0x9873, 12.0, 0.0, 528.0, 80.0,
     0.0, 0x9873, 0x98CC, 0.0, -4.0, 310.0}};

unsigned int cartridges_eject = 0;
unsigned int D_80034CA0 = 0;

unsigned int D_80034CA4[] = {
    0x0,        0x0,        0x0,        0x0,        0x0,        0x0,
    0x0,        0x3F000000, 0x41000000, 0x0,        0x0,        0x0,
    0x0,        0x0,        0x0,        0x0,        0x3F000000, 0x41000000,
    0x0,        0x40C00000, 0xBFC00000, 0x0,        0x40B487B1, 0x3E70C0AD,
    0x3E0AE536, 0x3F000000, 0x41000000, 0x0,        0x41480000, 0xC0600000,
    0x0,        0x40C159EC, 0x3D374BC7, 0x3F0E4378, 0x3F000000, 0x41000000,
    0x0,        0xC1200000, 0xC1300000, 0x0,        0x3F9ED962, 0x3EA24C40,
    0x3F8B0DF1, 0x3F000000, 0x41000000, 0x0,        0xC1600000, 0xC1700000,
    0x0,        0x3FEA4780, 0x40C498E3, 0x3FA316D3, 0x3F000000, 0x41200000,
    0x0,        0xBF800000, 0xC1100000, 0x0,        0x3EC4BBA1, 0x3EB87C42,
    0x3DD75968, 0x3F000000, 0x41200000, 0x0,        0x0,        0x0,
    0x0,        0x0,        0x0,        0x0,        0x3F000000, 0x41A00000,
    0x0,        0x0,        0x0,        0x0,        0x0,        0x0,
    0x0,        0x3F000000, 0x41A00000, 0x1,        0x0,        0x0,
    0x0,        0x0,        0x0,        0x0,        0,          0};

unsigned int D_80034E0C[] = {
    0x0,        0x0,        0x0,        0x0,        0x0,        0x0,
    0x0,        0x3F000000, 0x41000000, 0x0,        0x0,        0x0,
    0x0,        0x0,        0x0,        0x0,        0x3F000000, 0x41000000,
    0x0,        0xC1080000, 0xC0C00000, 0x0,        0x40AF7506, 0x40BAB4B9,
    0x40C2A5C2, 0x3F000000, 0x41000000, 0x0,        0xC0400000, 0xC0600000,
    0x0,        0x3ECE08F2, 0x40B75721, 0x40B62409, 0x3F000000, 0x41000000,
    0x0,        0xBF000000, 0xC1080000, 0x0,        0x3F9DFD7A, 0x40B768CD,
    0x40B37BDF, 0x3F000000, 0x41000000, 0x0,        0x40E00000, 0xC1E40000,
    0xBFC00000, 0x3FA74949, 0x40B63EBC, 0x40B6443D, 0x3F000000, 0x41200000,
    0x0,        0xBFC00000, 0xC1100000, 0x0,        0x3D8ADEEC, 0x40C84E72,
    0x3E506749, 0x3F000000, 0x41200000, 0x0,        0x0,        0x0,
    0x0,        0x0,        0x0,        0x0,        0x3F000000, 0x41A00000,
    0x0,        0x0,        0x0,        0x0,        0x0,        0x0,
    0x0,        0x3F000000, 0x41A00000, 0x1,        0x0,        0x0,
    0x0,        0x0,        0x0,        0x0,        0x0,        0x0};

unsigned int D_80034F74[] = {
    0x0,        0x0,        0x0,        0x0,        0x0,        0x0,
    0x0,        0x3F000000, 0x41000000, 0x0,        0x0,        0x0,
    0x0,        0x0,        0x0,        0x0,        0x3F000000, 0x41000000,
    0x0,        0x0,        0x0,        0x40900000, 0x40B2719D, 0x0,
    0x0,        0x3F000000, 0x41000000, 0x0,        0x0,        0x0,
    0x41A40000, 0x40A8630B, 0x0,        0x0,        0x3F000000, 0x41000000,
    0x0,        0x0,        0x40400000, 0x40B00000, 0x3D008312, 0x0,
    0x0,        0x3F000000, 0x41000000, 0x1,        0x0,        0x0,
    0x0,        0x0,        0x0,        0x0,        0x0,        0x0};

unsigned int D_8003504C[] = {

    0x0,        0x0,        0x0,        0x40900000, 0x40B2719D, 0x0,
    0x0,        0x3F000000, 0x41000000, 0x0,        0x0,        0x0,
    0x41A40000, 0x40A8630B, 0x0,        0x0,        0x3F000000, 0x41000000,
    0x0,        0x0,        0x40400000, 0x40B00000, 0x3D008312, 0x0,
    0x0,        0x3F000000, 0x41000000, 0x0,        0x0,        0xC1A00000,
    0x41900000, 0x3F4913C7, 0x0,        0x0,        0x3F000000, 0x41A00000,
    0x0,        0x0,        0xC1A00000, 0x41900000, 0x3F4913C7, 0x0,
    0x0,        0x3F000000, 0x41A00000, 0x1,        0x0,        0x0,
    0x0,        0x0,        0x0,        0x0,        0x0,        0x0};

unsigned int D_80035124[] = {
    0x0,        0x0,        0x0,        0x0,        0x0,        0x0,
    0x0,        0x3F000000, 0x40800000, 0x0,        0x0,        0x0,
    0x0,        0x0,        0x0,        0x0,        0x3F000000, 0x40800000,
    0x0,        0x41200000, 0x41480000, 0x418C0000, 0x0,        0x0,
    0x0,        0x3F000000, 0x40800000, 0x0,        0x41200000, 0x420A0000,
    0x41CC0000, 0x0,        0x0,        0x0,        0x3F000000, 0x41200000,
    0x0,        0x41200000, 0x420A0000, 0x41CC0000, 0x0,        0x0,
    0x0,        0x3F000000, 0x41200000, 0x1,        0x0,        0x0,
    0x0,        0x0,        0x0,        0x0,        0x0,        0x0};

unsigned int D_800351FC[] = {
    0x0,        0x41200000, 0x420A0000, 0x41CC0000, 0x0,        0x0,
    0x0,        0x3F000000, 0x41200000, 0x0,        0x41200000, 0x420A0000,
    0x41CC0000, 0x0,        0x0,        0x0,        0x3F000000, 0x41200000,
    0x0,        0x41200000, 0x41480000, 0x418C0000, 0x0,        0x0,
    0x0,        0x3F000000, 0x41200000, 0x0,        0x0,        0x0,
    0x0,        0x0,        0x0,        0x0,        0x3F000000, 0x41200000,
    0x0,        0x0,        0x0,        0x0,        0x0,        0x0,
    0x0,        0x3F000000, 0x41200000, 0x1,        0x0,        0x0,
    0x0,        0x0,        0x0,        0x0,        0x0,        0x0};

unsigned int D_800352D4[] = {
    0x0,        0x0,        0x0,        0x0,        0x0,        0x0,
    0x0,        0x3F000000, 0x40800000, 0x0,        0x0,        0x0,
    0x0,        0x0,        0x0,        0x0,        0x3F000000, 0x40800000,
    0x0,        0x0,        0x0,        0x40900000, 0x40B2719D, 0x0,
    0x0,        0x3F000000, 0x40800000, 0x0,        0x0,        0x0,
    0x41A40000, 0x40A8630B, 0x0,        0x0,        0x3F000000, 0x41000000,
    0x0,        0x0,        0x40400000, 0x40B00000, 0x3D008312, 0x0,
    0x0,        0x3F000000, 0x41000000, 0x1,        0x0,        0x0,
    0x0,        0x0,        0x0,        0x0,        0x0,        0x0};

unsigned int D_800353AC[63] = {
    0x0,        0x0,        0x0,        0x40900000, 0x40B2719D, 0x0,
    0x0,        0x3F000000, 0x41000000, 0x0,        0x0,        0x0,
    0x41A40000, 0x40A8630B, 0x0,        0x0,        0x3F000000, 0x41000000,
    0x0,        0x0,        0x40400000, 0x40B00000, 0x3D008312, 0x0,
    0x0,        0x3F000000, 0x41000000, 0x0,        0x0,        0xC1A00000,
    0x41900000, 0x3F4913C7, 0x0,        0x0,        0x3F000000, 0x41000000,
    0x0,        0x0,        0x0,        0x0,        0x0,        0x0,
    0x0,        0x3F000000, 0x41A00000, 0x0,        0x0,        0x0,
    0x0,        0x0,        0x0,        0x0,        0x3F000000, 0x41A00000,
    0x1,        0x0,        0x0,        0x0,        0x0,        0x0,
    0x0,        0x0,        0x0};

unsigned int D_800354A8[90] = {
    0x0,        0x0,        0x0,        0x0,        0x0,        0x0,
    0x0,        0x3F000000, 0x41200000, 0x0,        0x0,        0x0,
    0x0,        0x0,        0x0,        0x0,        0x3F000000, 0x41200000,
    0x0,        0x40C00000, 0x41B80000, 0x0,        0x40BD4D94, 0x3DAFC8B0,
    0x3E60BFE4, 0x3F000000, 0x41200000, 0x0,        0x41900000, 0x420C0000,
    0x41180000, 0x409FF132, 0x3DAC729F, 0x3E89B457, 0x3F000000, 0x41200000,
    0x0,        0xC1A00000, 0x41CC0000, 0x40800000, 0x3E012CF1, 0x3E9BCB1D,
    0x3F0C4CCF, 0x3F000000, 0x41200000, 0x0,        0xC1E00000, 0xC0800000,
    0x40000000, 0x3F01BF05, 0x3F03C558, 0x3EF7DBB1, 0x3F000000, 0x3F800000,
    0x0,        0xC1E00000, 0xC0800000, 0x40000000, 0x3F01BF05, 0x3F03C558,
    0x3EF7DBB1, 0x3F000000, 0x3F800000, 0x0,        0x0,        0x0,
    0x0,        0x0,        0x0,        0x0,        0x3F000000, 0x41A00000,
    0x0,        0x0,        0x0,        0x0,        0x0,        0x0,
    0x0,        0x3F000000, 0x41A00000, 0x1,        0x0,        0x0,
    0x0,        0x0,        0x0,        0x0,        0x0,        0x0};

unsigned int D_80035610[90] = {
    0x0,        0x0,        0x0,        0x0,        0x0,        0x0,
    0x0,        0x3F000000, 0x41200000, 0x0,        0x0,        0x0,
    0x0,        0x0,        0x0,        0x0,        0x3F000000, 0x41200000,
    0x0,        0xC0C00000, 0x41B80000, 0x0,        0x40A2C750, 0x40C43392,
    0x40B1199C, 0x3F000000, 0x41200000, 0x0,        0xC1900000, 0x420C0000,
    0x41180000, 0x409C2EAE, 0x3D902BC7, 0x40B12824, 0x3F000000, 0x41200000,
    0x0,        0x41000000, 0x41CC0000, 0x40800000, 0x3DDB927D, 0x40C1FEDC,
    0x40ACEF69, 0x3F000000, 0x41200000, 0x0,        0x41E00000, 0xC0800000,
    0x40000000, 0x3DDB927D, 0x40C1FEDC, 0x40ACEF69, 0x3F000000, 0x3F800000,
    0x0,        0x41E00000, 0xC0800000, 0x40000000, 0x3DDB927D, 0x40C1FEDC,
    0x40ACEF69, 0x3F000000, 0x3F800000, 0x0,        0x0,        0x0,
    0x0,        0x0,        0x0,        0x0,        0x3F000000, 0x41A00000,
    0x0,        0x0,        0x0,        0x0,        0x0,        0x0,
    0x0,        0x3F000000, 0x41A00000, 0x1,        0x0,        0x0,
    0x0,        0x0,        0x0,        0x0,        0x0,        0x0};

unsigned int D_80035778[99] = {
    0x0,        0x0,        0x0,        0x0,        0x0,        0x0,
    0x0,        0x3F000000, 0x41100000, 0x0,        0x0,        0x0,
    0x0,        0x0,        0x0,        0x0,        0x3F000000, 0x41000000,
    0x0,        0x41180000, 0xBF000000, 0x40600000, 0x3E9504E6, 0x40B2B333,
    0x40C6CBA3, 0x3F000000, 0x41000000, 0x0,        0x41900000, 0x40F00000,
    0x40600000, 0x3EE0F55E, 0x40BE3F16, 0x40BFCC1D, 0x3F000000, 0x41000000,
    0x0,        0xC1100000, 0x41080000, 0x40B00000, 0x3F346DF8, 0x3E472043,
    0x40C563EB, 0x3F000000, 0x40E00000, 0x0,        0xC1E80000, 0xC0B00000,
    0x40B00000, 0x40120985, 0x3F8D9CFA, 0x3FBEB841, 0x3F000000, 0x40E00000,
    0x0,        0xC2660000, 0xC1DC0000, 0x40B00000, 0x40120985, 0x3F8D9CFA,
    0x3FBEB841, 0x3F000000, 0x40E00000, 0x0,        0xC19C0000, 0xC1A00000,
    0x40B00000, 0x3F9CD307, 0x3F39E0D6, 0x3F9AF8A5, 0x3F000000, 0x41700000,
    0x0,        0x0,        0x0,        0x0,        0x0,        0x0,
    0x0,        0x3F000000, 0x41A00000, 0x0,        0x0,        0x0,
    0x0,        0x0,        0x0,        0x0,        0x3F000000, 0x41A00000,
    0x1,        0x0,        0x0,        0x0,        0x0,        0x0,
    0x0,        0x0,        0x0};

unsigned int D_80035904[99] = {
    0x0,        0x0,        0x0,        0x0,        0x0,        0x0,
    0x0,        0x3F000000, 0x41100000, 0x0,        0x0,        0x0,
    0x0,        0x0,        0x0,        0x0,        0x3F000000, 0x41000000,
    0x0,        0xC1780000, 0x3F000000, 0x41700000, 0x3F6F3B21, 0x3F2027FA,
    0x3E652B0A, 0x3F000000, 0x41000000, 0x0,        0xC1B80000, 0x40000000,
    0x41400000, 0x3FE69C24, 0x3F730C35, 0x3F21781C, 0x3F000000, 0x41000000,
    0x0,        0xC1900000, 0xBF000000, 0x40800000, 0x3F590B0F, 0x3F6CBD66,
    0x3D9E9A70, 0x3F000000, 0x40E00000, 0x0,        0x41280000, 0x40A00000,
    0x40200000, 0x3E6AE968, 0x3E7B99D4, 0x3DCAE18B, 0x3F000000, 0x40E00000,
    0x0,        0x41900000, 0x40A00000, 0x40200000, 0x3D0666ED, 0x40C6B2E4,
    0x3E0A4E38, 0x3F000000, 0x40E00000, 0x0,        0x41180000, 0x40600000,
    0xBFC00000, 0x40C8BE5E, 0x40C02F79, 0x3DB7BC7F, 0x3F000000, 0x40E00000,
    0x0,        0x0,        0x0,        0x0,        0x0,        0x0,
    0x0,        0x3F000000, 0x41A00000, 0x0,        0x0,        0x0,
    0x0,        0x0,        0x0,        0x0,        0x3F000000, 0x41A00000,
    0x1,        0x0,        0x0,        0x0,        0x0,        0x0,
    0x0,        0x0,        0x0};

unsigned int D_80035A90[54] = {
    0x0,        0x0,        0x0,        0x0,        0x0,        0x0,
    0x0,        0x3F000000, 0x41000000, 0x0,        0x0,        0x0,
    0x0,        0x0,        0x0,        0x0,        0x3F000000, 0x41000000,
    0x0,        0x3F000000, 0xC0C00000, 0xC1000000, 0x3EE101F3, 0x3E8EC2AD,
    0x3E47DCBE, 0x3F000000, 0x41000000, 0x0,        0xC0000000, 0xC1000000,
    0xC1200000, 0x3F8D0308, 0x3EEBE7D1, 0x3F122A80, 0x3F000000, 0x41000000,
    0x0,        0xC0000000, 0xC1000000, 0xC1200000, 0x3F8D0308, 0x3EEBE7D1,
    0x3F122A80, 0x3F000000, 0x41000000, 0x1,        0x0,        0x0,
    0x0,        0x0,        0x0,        0x0,        0x0,        0x0};

unsigned int D_80035B68[54] = {
    0x0,        0xC0000000, 0xC1000000, 0xC1200000, 0x3F8D0308, 0x3EEBE7D1,
    0x3F122A80, 0x3F000000, 0x41000000, 0x0,        0xC0000000, 0xC1000000,
    0xC1200000, 0x3F8D0308, 0x3EEBE7D1, 0x3F122A80, 0x3F000000, 0x41000000,
    0x0,        0x3F000000, 0xC0C00000, 0xC1000000, 0x3EE101F3, 0x3E8EC2AD,
    0x3E47DCBE, 0x3F000000, 0x41000000, 0x0,        0x0,        0x0,
    0x0,        0x0,        0x0,        0x0,        0x3F000000, 0x41000000,
    0x0,        0x0,        0x0,        0x0,        0x0,        0x0,
    0x0,        0x3F000000, 0x41000000, 0x1,        0x0,        0x0,
    0x0,        0x0,        0x0,        0x0,        0x0,        0x0};

unsigned int D_80035C40 = 0;
unsigned int D_80035C44 = 0;
unsigned int D_80035C48 = 0;
unsigned int D_80035C4C = 0;
unsigned int D_80035C50 = 0;
unsigned int D_80035C54 = 0;
unsigned int D_80035C58 = 0;
unsigned int D_80035C5C = 0;

float D_80035C60 = -1.0;
float D_80035C64 = 0.0;
float D_80035C68 = 1.0;
float D_80035C6C = 0.0;
float D_80035C70 = 6.2536321;
float D_80035C74 = 6.2592888;
float D_80035C78 = 0.204238;
float D_80035C7C = 0.25044999;
float D_80035C80 = 0.90482301;
float D_80035C84 = 0.28716999;
float D_80035C88 = 1.715736;
float D_80035C8C = 0.37460899;
float D_80035C90 = 0.92193699;

float D_80035C94 = 0;

unsigned int D_80035C98 = 0;
unsigned int D_80035C9C = 0;
unsigned int D_80035CA0 = 0;
int D_80035CA4 = 0xFFFFFFFF;
unsigned int D_80035CA8 = 0;
unsigned int D_80035CAC = 0;
unsigned int D_80035CB0 = 0;
unsigned int D_80035CB4 = 0;
unsigned int D_80035CB8 = 0;
unsigned int D_80035CBC = 0;
unsigned int D_80035CC0 = 0;
unsigned int D_80035CC4[] = {1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
unsigned int D_80035D00 = 0;
unsigned int D_80035D04[] = {1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
unsigned int D_80035D44[] = {1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
unsigned short D_80035E04[] = {0x1B, 0x1C, 0x1D, 0x1E, 0x1B, 0x1C,
                               0x1D, 0x1E, 0x1B, 0x1C, 0x1D, 0x1E,
                               0x23, 0x24, 0x25, 0x26, 0x27, 0x28};
unsigned short D_80035E28[] = {0x29, 0x2A};
unsigned short D_80035E2C[] = {0x2F, 0x30};
unsigned short D_80035E30[] = {0x31, 0};
unsigned short D_80035E34[] = {0x45, 0x45};
unsigned short D_80035E38[] = {0x5C, 0x5D};
unsigned short D_80035E3C[] = {
    0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x17, 0x18, 0x19, 0x1A,
    0x17, 0x18, 0x19, 0x1A, 0x1F, 0x20, 0x20, 0x21, 0x1F, 0x20, 0x20, 0x21,
    0x1F, 0x20, 0x20, 0x21, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A};
unsigned short D_80035E84[] = {0xA4, 0xA5};
unsigned short D_80035E88[] = {0xA6, 0xA7};
unsigned short D_80035E8C[] = {0xA8, 0};
unsigned short D_80035E90[] = {0x5C, 0x5D};
unsigned short D_80035E94[] = {0x5F, 0x60};
unsigned short D_80035E98[] = {0x61, 0};
unsigned int D_80035E9C = 0;
unsigned int D_80035EA0 = 0;
unsigned int D_80035EA4 = 0;
unsigned int D_80035EA8 = 0;
unsigned int D_80035EAC = 0;
unsigned int D_80035EB0[] = {0, 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
unsigned int dword_D_80035EEC = 0;
unsigned short ammo_related[] = {
    0, 0,     0,     0,     0,      0, 0, 0x320, 0x200, 0xC84, 0,      0,
    0, 0xC8,  0,     0,     0,      0, 0, 0x190, 0x200, 0xC90, 0xC000, 0,
    0, 0x64,  0x200, 0xC9C, 0,      0, 0, 0xC,   0x200, 0xCD8, 0,      0,
    0, 3,     0x200, 0xCC0, 0xC000, 0, 0, 0xA,   0x200, 0xCFC, 0x3F80, 0,
    0, 0xA,   0x200, 0xD14, 0x3F80, 0, 0, 0xA,   0x200, 0xD08, 0x3F80, 0,
    0, 0xA,   0x200, 0xCA8, 0,      0, 0, 0xC,   0x200, 0xCB4, 0,      0,
    0, 0xC8,  0x200, 0xCE4, 0,      0, 0, 0x64,  0x200, 0xCF0, 0,      0,
    0, 0x32,  0,     0,     0,      0, 0, 0xA,   0,     0,     0,      0,
    0, 2,     0,     0,     0,      0, 0, 8,     0,     0,     0,      0,
    0, 6,     0,     0,     0,      0, 0, 0xA,   0,     0,     0,      0,
    0, 0xA,   0,     0,     0,      0, 0, 0xA,   0,     0,     0,      0,
    0, 1,     0,     0,     0,      0, 0, 0xA,   0,     0,     0,      0,
    0, 0x3E8, 0,     0,     0,      0, 0, 0xA,   0,     0,     0,      0,
    0, 0xA,   0,     0,     0,      0, 0, 0xA,   0,     0,     0,      0,
    0, 0x32,  0x200, 0xD20, 0xBF80, 0, 0, 1,     0,     0,     0,      0,
    0, 0,     0,     0};

// i may belong to objecthandler.c
unsigned int D_80036060 = 0;

const char aD_9[] = "%d\n";
const char aSD[] = "%s: %d\n";
const char aSDS[] = "%s %d %s\n";
const char aSD_0[] = "%s: %d\n";

void set_cartridges_eject(unsigned int uParm1) { cartridges_eject = uParm1; }

unsigned int get_cartridges_eject(void) { return cartridges_eject; }

void nullsub_73(void) {}

asm(R"
glabel sub_GAME_7F05C540
  lui   $t6, %hi(D_80034CA0) 
  lw    $t6, %lo(D_80034CA0)($t6)
  lui   $t8, %hi(D_80035904) 
  addiu $t8, %lo(D_80035904) # addiu $t8, $t8, 0x5904
  sll   $t7, $t6, 3
  addu  $t7, $t7, $t6
  sll   $t7, $t7, 2
  addu  $v0, $t7, $t8
  lwc1  $f4, 4($v0)
  lwc1  $f6, ($a0)
  lwc1  $f10, 8($v0)
  add.s $f8, $f4, $f6
  lwc1  $f4, 0xc($v0)
  swc1  $f8, 4($v0)
  lwc1  $f16, 4($a0)
  add.s $f18, $f10, $f16
  swc1  $f18, 8($v0)
  lwc1  $f6, 8($a0)
  add.s $f8, $f4, $f6
  jr    $ra
   swc1  $f8, 0xc($v0)
");

asm(R"
glabel sub_GAME_7F05C594
  lui   $t6, %hi(D_80034CA0) 
  lw    $t6, %lo(D_80034CA0)($t6)
  addiu $sp, $sp, -0x58
  lui   $t9, %hi(D_80035904) 
  sll   $t7, $t6, 3
  addu  $t7, $t7, $t6
  sll   $t7, $t7, 2
  sw    $ra, 0x14($sp)
  sw    $a0, 0x58($sp)
  addiu $t8, $t7, 0x10
  addiu $t9, %lo(D_80035904) # addiu $t9, $t9, 0x5904
  addu  $a0, $t8, $t9
  jal   sub_GAME_7F058714
   addiu $a1, $sp, 0x18
  lw    $a0, 0x58($sp)
  jal   matrix_4x4_multiply_in_place
   addiu $a1, $sp, 0x18
  lui   $t0, %hi(D_80034CA0) 
  lw    $t0, %lo(D_80034CA0)($t0)
  lui   $t3, %hi(D_80035904) 
  addiu $t3, %lo(D_80035904) # addiu $t3, $t3, 0x5904
  sll   $t1, $t0, 3
  addu  $t1, $t1, $t0
  sll   $t1, $t1, 2
  addiu $t2, $t1, 0x10
  addu  $a1, $t2, $t3
  jal   sub_GAME_7F058860
   addiu $a0, $sp, 0x18
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x58
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F05C614
  lui   $t6, %hi(cartridges_eject) 
  lw    $t6, %lo(cartridges_eject)($t6)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  beqz  $t6, .L7F05C6A8
   lui   $v0, %hi(pPlayer)
  addiu $v0, %lo(pPlayer) # addiu $v0, $v0, -0x5f50
  lw    $t8, ($v0)
  li    $t7, 1
  lui   $t9, %hi(D_80034CA0) 
  sw    $t7, 0x92c($t8)
  lw    $t9, %lo(D_80034CA0)($t9)
  lw    $a1, ($v0)
  lui   $t2, %hi(D_80035904) 
  sll   $t0, $t9, 3
  addu  $t0, $t0, $t9
  sll   $t0, $t0, 2
  addiu $t1, $t0, 0x10
  addiu $t2, %lo(D_80035904) # addiu $t2, $t2, 0x5904
  addu  $a0, $t1, $t2
  jal   sub_GAME_7F058714
   addiu $a1, $a1, 0x8ec
  lui   $t3, %hi(D_80034CA0) 
  lw    $t3, %lo(D_80034CA0)($t3)
  lui   $a1, %hi(pPlayer)
  lw    $a1, %lo(pPlayer)($a1)
  sll   $t4, $t3, 3
  addu  $t4, $t4, $t3
  sll   $t4, $t4, 2
  lui   $t6, %hi(D_80035904) 
  addiu $t6, %lo(D_80035904) # addiu $t6, $t6, 0x5904
  addiu $t5, $t4, 4
  addu  $a0, $t5, $t6
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   addiu $a1, $a1, 0x8ec
  lui   $at, %hi(cartridges_eject)
  sw    $zero, %lo(cartridges_eject)($at)
.L7F05C6A8:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F05C6B8
  lui   $v0, %hi(D_80034CA0)
  addiu $v0, %lo(D_80034CA0) # addiu $v0, $v0, 0x4ca0
  lw    $t6, ($v0)
  lui   $t0, %hi(D_80035904)
  addiu $t7, $t6, 1
  sll   $t9, $t7, 3
  addu  $t9, $t9, $t7
  sll   $t9, $t9, 2
  sw    $t7, ($v0)
  addu  $t0, $t0, $t9
  lw    $t0, %lo(D_80035904)($t0)
  andi  $t1, $t0, 1
  beqz  $t1, .L7F05C6F4
   nop   
  sw    $zero, ($v0)
.L7F05C6F4:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F05C6FC
  addiu $sp, $sp, -0xa0
  sw    $ra, 0x2c($sp)
  sw    $s0, 0x28($sp)
  sw    $a2, 0xa8($sp)
  sw    $a3, 0xac($sp)
  mtc1  $a1, $f12
  lwc1  $f4, 0x44($a0)
  li    $v0, 1
  addiu $s0, $a0, 0x24
  c.le.s $f4, $f12
  nop   
  bc1fl .L7F05C764
   sll   $t8, $v0, 3
  lwc1  $f0, 0x20($s0)
  lw    $t6, 0x6c($s0)
.L7F05C738:
  sub.s $f12, $f12, $f0
  addiu $v0, $v0, 1
  andi  $t7, $t6, 1
  bnez  $t7, .L7F05C760
   addiu $s0, $s0, 0x24
  lwc1  $f0, 0x20($s0)
  c.le.s $f0, $f12
  nop   
  bc1tl .L7F05C738
   lw    $t6, 0x6c($s0)
.L7F05C760:
  sll   $t8, $v0, 3
.L7F05C764:
  addu  $t8, $t8, $v0
  sll   $t8, $t8, 2
  addu  $s0, $a0, $t8
  lw    $t9, 0x48($s0)
  andi  $t0, $t9, 1
  beqz  $t0, .L7F05C79C
   addiu $a0, $s0, 0x10
  jal   sub_GAME_7F058714
   lw    $a1, 0xa8($sp)
  addiu $a0, $s0, 4
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   lw    $a1, 0xa8($sp)
  b     .L7F05C8A0
   move  $v0, $zero
.L7F05C79C:
  lwc1  $f6, 0x20($s0)
  addiu $a0, $s0, -0x14
  addiu $a1, $sp, 0x68
  div.s $f8, $f12, $f6
  swc1  $f8, 0x98($sp)
  lwc1  $f10, 0x1c($s0)
  jal   sub_GAME_7F05B3F4
   swc1  $f10, 0x94($sp)
  addiu $a0, $s0, 0x10
  jal   sub_GAME_7F05B3F4
   addiu $a1, $sp, 0x58
  addiu $a0, $s0, 0x34
  jal   sub_GAME_7F05B3F4
   addiu $a1, $sp, 0x48
  addiu $a0, $s0, 0x58
  jal   sub_GAME_7F05B3F4
   addiu $a1, $sp, 0x38
  addiu $a0, $sp, 0x58
  jal   sub_GAME_7F05BE10
   addiu $a1, $sp, 0x48
  addiu $a0, $sp, 0x48
  jal   sub_GAME_7F05BE10
   addiu $a1, $sp, 0x38
  addiu $a0, $sp, 0x58
  jal   sub_GAME_7F05BE10
   addiu $a1, $sp, 0x68
  lwc1  $f16, 0x98($sp)
  addiu $t1, $sp, 0x78
  sw    $t1, 0x14($sp)
  addiu $a0, $sp, 0x68
  addiu $a1, $sp, 0x58
  addiu $a2, $sp, 0x48
  addiu $a3, $sp, 0x38
  jal   sub_GAME_7F05C2F0
   swc1  $f16, 0x10($sp)
  lwc1  $f18, 0x98($sp)
  lwc1  $f4, 0x94($sp)
  addiu $t2, $sp, 0x88
  sw    $t2, 0x18($sp)
  addiu $a0, $s0, -0x20
  addiu $a1, $s0, 4
  addiu $a2, $s0, 0x28
  addiu $a3, $s0, 0x4c
  swc1  $f18, 0x10($sp)
  jal   sub_GAME_7F05B024
   swc1  $f4, 0x14($sp)
  lw    $t3, 0xac($sp)
  li    $at, 1
  lwc1  $f6, 0x88($sp)
  bne   $t3, $at, .L7F05C888
   addiu $a0, $sp, 0x78
  lwc1  $f10, 0x78($sp)
  lwc1  $f18, 0x7c($sp)
  neg.s $f8, $f6
  neg.s $f16, $f10
  neg.s $f4, $f18
  swc1  $f8, 0x88($sp)
  swc1  $f16, 0x78($sp)
  swc1  $f4, 0x7c($sp)
.L7F05C888:
  jal   sub_GAME_7F05B628
   lw    $a1, 0xa8($sp)
  addiu $a0, $sp, 0x88
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   lw    $a1, 0xa8($sp)
  li    $v0, 1
.L7F05C8A0:
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x28($sp)
  addiu $sp, $sp, 0xa0
  jr    $ra
   nop   
");

struct weapon_stats *get_ptr_item_statistics(int item) {
  if (gitem_structs[item].has_no_model ==
      0) { /* weapon has model, return stats struct */
    return gitem_structs[item].item_weapon_stats;
  }
  return &default_weaponstats; /* no model, return defaults */
}

asm(R"
glabel copy_item_in_hand
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  jal   get_item_in_hand
   move  $a0, $zero
  jal   get_ptr_item_statistics
   move  $a0, $v0
  lw    $v1, 0x18($sp)
  lwc1  $f4, 4($v0)
  swc1  $f4, ($v1)
  lwc1  $f6, 8($v0)
  swc1  $f6, 4($v1)
  lwc1  $f8, 0xc($v0)
  swc1  $f8, 8($v1)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel copy_item_in_hand_to_main_list
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  jal   get_item_in_hand
   move  $a0, $zero
  jal   get_ptr_item_statistics
   move  $a0, $v0
  lw    $v1, 0x18($sp)
  lwc1  $f4, ($v1)
  swc1  $f4, 4($v0)
  lwc1  $f6, 4($v1)
  swc1  $f6, 8($v0)
  lwc1  $f8, 8($v1)
  swc1  $f8, 0xc($v0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80053C14
.word 0x3da3d70a /*0.079999998*/
glabel D_80053C18
.word 0x3dcccccd /*0.1*/
glabel D_80053C1C
.word 0x3dcccccd /*0.1*/
glabel D_80053C20
.word 0x3dcccccd /*0.1*/
.text
glabel unknown_takes_playerhand
  addiu $sp, $sp, -0x70
  sw    $ra, 0x3c($sp)
  sw    $s1, 0x2c($sp)
  move  $s1, $a0
  sw    $s4, 0x38($sp)
  sw    $s3, 0x34($sp)
  sw    $s2, 0x30($sp)
  sw    $s0, 0x28($sp)
  sdc1  $f22, 0x20($sp)
  jal   get_item_in_hand
   sdc1  $f20, 0x18($sp)
  jal   get_ptr_item_statistics
   move  $a0, $v0
  sll   $s4, $s1, 3
  subu  $s4, $s4, $s1
  lui   $s3, %hi(pPlayer)
  sll   $s4, $s4, 2
  addiu $s3, %lo(pPlayer) # addiu $s3, $s3, -0x5f50
  addu  $s4, $s4, $s1
  lw    $t7, ($s3)
  sll   $s4, $s4, 2
  addu  $s4, $s4, $s1
  sll   $s4, $s4, 3
  addu  $v1, $t7, $s4
  lw    $t8, 0xa08($v1)
  sll   $a0, $s1, 2
  addiu $t6, $sp, 0x68
  addiu $t9, $t8, 2
  lwc1  $f20, 0x40($v0)
  addu  $s0, $a0, $t6
  bgez  $t9, .L7F05CA0C
   andi  $t0, $t9, 3
  beqz  $t0, .L7F05CA0C
   nop   
  addiu $t0, $t0, -4
.L7F05CA0C:
  sw    $t0, ($s0)
  lw    $t2, 0xa08($v1)
  addiu $t1, $sp, 0x60
  addu  $a1, $a0, $t1
  addiu $t3, $t2, 1
  bgez  $t3, .L7F05CA34
   andi  $t4, $t3, 3
  beqz  $t4, .L7F05CA34
   nop   
  addiu $t4, $t4, -4
.L7F05CA34:
  sw    $t4, ($a1)
  jal   get_random_value
   sw    $t4, 0xa08($v1)
  mtc1  $v0, $f4
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f22
  li    $s2, 12
  bgez  $v0, .L7F05CA68
   cvt.s.w $f6, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F05CA68:
  mul.s $f10, $f6, $f22
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f16
  lui   $at, %hi(D_80053C14)
  lwc1  $f4, %lo(D_80053C14)($at)
  lw    $t9, ($s0)
  sll   $t7, $s1, 3
  sub.s $f18, $f10, $f16
  multu $t9, $s2
  subu  $t7, $t7, $s1
  sll   $t7, $t7, 2
  mul.s $f8, $f18, $f4
  addu  $t7, $t7, $s1
  lw    $t6, ($s3)
  sll   $t7, $t7, 2
  addu  $t7, $t7, $s1
  sll   $t7, $t7, 3
  addu  $t8, $t6, $t7
  mul.s $f6, $f8, $f20
  mflo  $t0
  addu  $t1, $t8, $t0
  jal   get_random_value
   swc1  $f6, 0x9a8($t1)
  mtc1  $v0, $f10
  bgez  $v0, .L7F05CAE0
   cvt.s.w $f16, $f10
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f18
  nop   
  add.s $f16, $f16, $f18
.L7F05CAE0:
  mul.s $f4, $f16, $f22
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f8
  lui   $at, %hi(D_80053C18)
  lwc1  $f10, %lo(D_80053C18)($at)
  lw    $t5, ($s0)
  sll   $t3, $s1, 3
  sub.s $f6, $f4, $f8
  multu $t5, $s2
  subu  $t3, $t3, $s1
  sll   $t3, $t3, 2
  mul.s $f18, $f6, $f10
  addu  $t3, $t3, $s1
  lw    $t2, ($s3)
  sll   $t3, $t3, 2
  addu  $t3, $t3, $s1
  sll   $t3, $t3, 3
  addu  $t4, $t2, $t3
  mul.s $f16, $f18, $f20
  mflo  $t6
  addu  $t7, $t4, $t6
  sll   $t8, $s1, 3
  subu  $t8, $t8, $s1
  sll   $t8, $t8, 2
  addu  $t8, $t8, $s1
  swc1  $f16, 0x9ac($t7)
  lw    $t1, ($s0)
  lw    $t9, ($s3)
  sll   $t8, $t8, 2
  multu $t1, $s2
  addu  $t8, $t8, $s1
  sll   $t8, $t8, 3
  li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f4
  addu  $t0, $t9, $t8
  mflo  $t2
  addu  $t3, $t0, $t2
  jal   get_random_value
   swc1  $f4, 0x9b0($t3)
  mtc1  $v0, $f8
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F05CB98
   cvt.s.w $f6, $f8
  mtc1  $at, $f10
  nop   
  add.s $f6, $f6, $f10
.L7F05CB98:
  mul.s $f18, $f6, $f22
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f16
  lui   $at, %hi(D_80053C1C)
  lwc1  $f8, %lo(D_80053C1C)($at)
  lw    $t7, ($s0)
  sll   $t4, $s1, 3
  sub.s $f4, $f18, $f16
  multu $t7, $s2
  subu  $t4, $t4, $s1
  sll   $t4, $t4, 2
  mul.s $f10, $f4, $f8
  addu  $t4, $t4, $s1
  lw    $t5, ($s3)
  sll   $t4, $t4, 2
  addu  $t4, $t4, $s1
  sll   $t4, $t4, 3
  addu  $t6, $t5, $t4
  mul.s $f6, $f10, $f20
  mflo  $t9
  addu  $t8, $t6, $t9
  sll   $t0, $s1, 3
  subu  $t0, $t0, $s1
  sll   $t0, $t0, 2
  addu  $t0, $t0, $s1
  swc1  $f6, 0x9d8($t8)
  lw    $t3, ($s0)
  lw    $t1, ($s3)
  sll   $t0, $t0, 2
  multu $t3, $s2
  addu  $t0, $t0, $s1
  sll   $t0, $t0, 3
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f18
  addu  $t2, $t1, $t0
  mflo  $t5
  addu  $t4, $t2, $t5
  jal   get_random_value
   swc1  $f18, 0x9dc($t4)
  mtc1  $v0, $f16
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F05CC50
   cvt.s.w $f4, $f16
  mtc1  $at, $f8
  nop   
  add.s $f4, $f4, $f8
.L7F05CC50:
  mul.s $f10, $f4, $f22
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f6
  lui   $at, %hi(D_80053C20)
  lwc1  $f16, %lo(D_80053C20)($at)
  lw    $t8, ($s0)
  sll   $t6, $s1, 3
  sub.s $f18, $f10, $f6
  multu $t8, $s2
  subu  $t6, $t6, $s1
  sll   $t6, $t6, 2
  mul.s $f8, $f18, $f16
  addu  $t6, $t6, $s1
  lw    $t7, ($s3)
  sll   $t6, $t6, 2
  addu  $t6, $t6, $s1
  sll   $t6, $t6, 3
  addu  $t9, $t7, $t6
  mul.s $f4, $f8, $f20
  mflo  $t1
  addu  $t0, $t9, $t1
  jal   get_random_value
   swc1  $f4, 0x9e0($t0)
  mtc1  $v0, $f10
  sll   $t2, $s1, 3
  bgez  $v0, .L7F05CCCC
   cvt.s.w $f6, $f10
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f18
  nop   
  add.s $f6, $f6, $f18
.L7F05CCCC:
  mul.s $f16, $f6, $f22
  lw    $t4, ($s0)
  li    $at, 0x3F400000 # 0.750000
  mtc1  $at, $f8
  multu $t4, $s2
  subu  $t2, $t2, $s1
  sll   $t2, $t2, 2
  mul.s $f4, $f16, $f8
  li    $at, 0x3FC00000 # 1.500000
  mtc1  $at, $f10
  addu  $t2, $t2, $s1
  lw    $t3, ($s3)
  sll   $t2, $t2, 2
  addu  $t2, $t2, $s1
  add.s $f18, $f4, $f10
  sll   $t2, $t2, 3
  mflo  $t7
  addu  $t5, $t3, $t2
  addu  $t6, $t5, $t7
  jal   get_random_value
   swc1  $f18, 0x978($t6)
  lw    $t8, ($s3)
  mtc1  $v0, $f16
  li    $at, 0x40000000 # 2.000000
  mtc1  $at, $f6
  addu  $v1, $t8, $s4
  bgez  $v0, .L7F05CD4C
   cvt.s.w $f8, $f16
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f4
  nop   
  add.s $f8, $f8, $f4
.L7F05CD4C:
  mul.s $f10, $f8, $f22
  lw    $t9, ($s0)
  lwc1  $f16, 0xa14($v1)
  multu $t9, $s2
  add.s $f18, $f6, $f10
  mul.s $f4, $f16, $f18
  mflo  $t1
  addu  $t0, $v1, $t1
  jal   get_random_value
   swc1  $f4, 0x97c($t0)
  mtc1  $v0, $f8
  sll   $t2, $s1, 3
  bgez  $v0, .L7F05CD94
   cvt.s.w $f6, $f8
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f10
  nop   
  add.s $f6, $f6, $f10
.L7F05CD94:
  mul.s $f16, $f6, $f22
  lw    $t5, ($s0)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f18
  multu $t5, $s2
  li    $at, 0x40200000 # 2.500000
  mtc1  $at, $f8
  sub.s $f4, $f16, $f18
  subu  $t2, $t2, $s1
  sll   $t2, $t2, 2
  addu  $t2, $t2, $s1
  mul.s $f10, $f4, $f8
  lw    $t3, ($s3)
  sll   $t2, $t2, 2
  addu  $t2, $t2, $s1
  sll   $t2, $t2, 3
  mflo  $t7
  addu  $t4, $t3, $t2
  addu  $t6, $t4, $t7
  swc1  $f10, 0x980($t6)
  lw    $a0, ($s3)
  li    $v0, 2
  addu  $v1, $a0, $s4
  lw    $a1, 0xa18($v1)
  bgez  $a1, .L7F05CE6C
   nop   
  lw    $t1, ($s0)
  sll   $t8, $s1, 3
  subu  $t8, $t8, $s1
  multu $t1, $s2
  sll   $t8, $t8, 2
  addu  $t8, $t8, $s1
  sll   $t8, $t8, 2
  addu  $t8, $t8, $s1
  sll   $t8, $t8, 3
  addu  $t9, $a0, $t8
  li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f16
  li    $a1, -2
  mflo  $t0
  addu  $v0, $t9, $t0
  lwc1  $f6, 0x978($v0)
  li    $t5, 1
  mul.s $f18, $f6, $f16
  swc1  $f18, 0x978($v0)
  lw    $t3, ($s3)
  addu  $v1, $t3, $s4
  lw    $t2, 0xa18($v1)
  bne   $a1, $t2, .L7F05CE64
   nop   
  b     .L7F05CE80
   sw    $t5, 0xa18($v1)
.L7F05CE64:
  b     .L7F05CE80
   sw    $a1, 0xa18($v1)
.L7F05CE6C:
  bne   $v0, $a1, .L7F05CE7C
   li    $t4, -1
  b     .L7F05CE80
   sw    $t4, 0xa18($v1)
.L7F05CE7C:
  sw    $v0, 0xa18($v1)
.L7F05CE80:
  lw    $t7, ($s3)
  addu  $v1, $t7, $s4
  lwc1  $f4, 0xa14($v1)
  neg.s $f8, $f4
  swc1  $f8, 0xa14($v1)
  lw    $ra, 0x3c($sp)
  lw    $s4, 0x38($sp)
  lw    $s3, 0x34($sp)
  lw    $s2, 0x30($sp)
  lw    $s1, 0x2c($sp)
  lw    $s0, 0x28($sp)
  ldc1  $f22, 0x20($sp)
  ldc1  $f20, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x70
");

asm(R"
glabel sub_GAME_7F05CEBC
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  sll   $t7, $a0, 2
  addu  $v1, $t6, $t7
  lw    $v0, 0x7f8($v1)
  slt   $t8, $zero, $v0
  bnez  $t8, .L7F05CEF8
   move  $v0, $t8
  lw    $v0, 0x800($v1)
  sltiu $t9, $v0, 1
  beqz  $t9, .L7F05CEF8
   move  $v0, $t9
  lw    $v0, 0x2a44($v1)
  slti  $t0, $v0, 0
  move  $v0, $t0
.L7F05CEF8:
  jr    $ra
   nop   
");

asm(R"
glabel get_itemtype_in_hand
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  sll   $t7, $a0, 2
  addu  $t8, $t6, $t7
  jr    $ra
   lw    $v0, 0x800($t8)
");

asm(R"
glabel get_ptr_itemheader_in_hand
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  sll   $t7, $a0, 5
  addu  $v0, $t6, $t7
  jr    $ra
   addiu $v0, $v0, 0x810
");

asm(R"
glabel getPlayerWeaponBufferForHand
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  sll   $t7, $a0, 2
  addu  $t8, $t6, $t7
  jr    $ra
   lw    $v0, 0x808($t8)
");

unsigned int getSizeBufferWeaponInHand(int hand) {
  return size_item_buffer[hand];
}

asm(R"
glabel remove_item_in_hand
  lui   $v1, %hi(pPlayer)
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $t6, ($v1)
  sll   $v0, $a0, 2
  li    $t0, -1
  addu  $t7, $t6, $v0
  sw    $zero, 0x7f8($t7)
  lw    $t8, ($v1)
  li    $t3, 1
  addu  $t9, $t8, $v0
  sw    $zero, 0x800($t9)
  lw    $t1, ($v1)
  addu  $t2, $t1, $v0
  sw    $t0, 0x2a44($t2)
  lw    $t4, ($v1)
  addu  $t5, $t4, $v0
  jr    $ra
   sw    $t3, 0x2a50($t5)
");

asm(R"
glabel place_item_in_hand_swap_and_make_visible
  lui   $a2, %hi(pPlayer)
  addiu $a2, %lo(pPlayer) # addiu $a2, $a2, -0x5f50
  lw    $t6, ($a2)
  sll   $v0, $a0, 2
  addu  $v1, $t6, $v0
  lw    $t7, 0x2a50($v1)
  bnez  $t7, .L7F05D010
   nop   
  lw    $t8, 0x7f8($v1)
  bltzl $t8, .L7F05CFF8
   lw    $t3, 0x800($v1)
  lw    $t9, 0x800($v1)
  li    $t0, -1
  beq   $a1, $t9, .L7F05D010
   nop   
  sw    $t0, 0x7f8($v1)
  lw    $t1, ($a2)
  addu  $t2, $t1, $v0
  jr    $ra
   sw    $a1, 0x2a44($t2)

  lw    $t3, 0x800($v1)
.L7F05CFF8:
  li    $t4, 1
  beql  $a1, $t3, .L7F05D010
   sw    $t4, 0x7f8($v1)
  jr    $ra
   sw    $a1, 0x2a44($v1)

  sw    $t4, 0x7f8($v1)
.L7F05D010:
  jr    $ra
   nop   
");

asm(R"
glabel get_ptr_item_text_call_line
  li    $at, 1
  bne   $a0, $at, .L7F05D030
   lui   $v0,  %hi(gitem_structs+4)
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  lw    $a0, 0x2a38($t6)
.L7F05D030:
  sll   $t7, $a0, 3
  subu  $t7, $t7, $a0
  sll   $t7, $t7, 3
  addu  $v0, $v0, $t7
  jr    $ra
   lw    $v0, %lo(gitem_structs+4)($v0)
");

asm(R"
glabel get_ptr_weapon_model_header_line
  li    $at, 1
  bne   $a0, $at, .L7F05D060
   lui   $v0, %hi(gitem_structs)
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  lw    $a0, 0x2a38($t6)
.L7F05D060:
  sll   $t7, $a0, 3
  subu  $t7, $t7, $a0
  sll   $t7, $t7, 3
  addu  $v0, $v0, $t7
  jr    $ra
   lw    $v0, %lo(gitem_structs)($v0)
");

asm(R"
glabel getCurrentWeaponOrItem
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  jr    $ra
   lw    $v0, 0x2a38($t6)
");

asm(R"
glabel used_to_load_1st_person_model_on_demand
  addiu $sp, $sp, -0x50
  sw    $s0, 0x1c($sp)
  lui   $s0, %hi(pPlayer)
  addiu $s0, %lo(pPlayer) # addiu $s0, $s0, -0x5f50
  lw    $t7, ($s0)
  sll   $a1, $a0, 2
  sw    $ra, 0x24($sp)
  sw    $s1, 0x20($sp)
  sw    $a0, 0x50($sp)
  addu  $v0, $t7, $a1
  lw    $v1, 0x7f8($v0)
  bgezl $v1, .L7F05D324
   lw    $ra, 0x24($sp)
  lw    $t8, 0x2a50($v0)
  slti  $at, $v1, -2
  bnezl $t8, .L7F05D324
   lw    $ra, 0x24($sp)
  bnezl $at, .L7F05D0E4
   lw    $s1, 0x2a44($v0)
  lw    $t9, 0x800($v0)
  bnezl $t9, .L7F05D31C
   addiu $t6, $v1, -1
  lw    $s1, 0x2a44($v0)
.L7F05D0E4:
  sw    $a1, 0x38($sp)
  jal   get_ptr_item_text_call_line
   move  $a0, $s1
  sw    $v0, 0x48($sp)
  jal   get_ptr_weapon_model_header_line
   move  $a0, $s1
  lw    $t3, 0x48($sp)
  sw    $v0, 0x44($sp)
  beql  $t3, $zero, .L7F05D2E8
   lw    $v0, 0x38($sp)
  beql  $v0, $zero, .L7F05D2E8
   lw    $v0, 0x38($sp)
  jal   getPlayerWeaponBufferForHand
   lw    $a0, 0x50($sp)
  sw    $v0, 0x40($sp)
  jal   getSizeBufferWeaponInHand
   lw    $a0, 0x50($sp)
  lw    $t6, 0x44($sp)
  lw    $t2, 0x50($sp)
  lw    $t4, ($s0)
  lw    $at, ($t6)
  sll   $t1, $t2, 5
  addu  $t5, $t4, $t1
  sw    $at, 0x810($t5)
  lw    $t9, 4($t6)
  move  $a3, $v0
  sll   $v1, $t2, 4
  sw    $t9, 0x814($t5)
  lw    $at, 8($t6)
  sw    $at, 0x818($t5)
  lw    $t9, 0xc($t6)
  sw    $t9, 0x81c($t5)
  lw    $at, 0x10($t6)
  sw    $at, 0x820($t5)
  lw    $t9, 0x14($t6)
  sw    $t9, 0x824($t5)
  lw    $at, 0x18($t6)
  sw    $at, 0x828($t5)
  lw    $t9, 0x1c($t6)
  li    $at, 84
  bne   $s1, $at, .L7F05D1F4
   sw    $t9, 0x82c($t5)
  lw    $a1, 0x40($sp)
  lw    $t3, ($s0)
  li    $at, 48496
  addu  $a1, $a1, $at
  lui   $at, (0xFFFF4290 >> 16) # lui $at, 0xffff
  ori   $at, (0xFFFF4290 & 0xFFFF) # ori $at, $at, 0x4290
  addu  $a0, $t3, $v1
  addiu $a0, $a0, 0x850
  addu  $a2, $v0, $at
  sw    $v1, 0x30($sp)
  jal   sub_GAME_7F0CBAF4
   sw    $t1, 0x34($sp)
  lw    $v1, 0x30($sp)
  lw    $v0, ($s0)
  lw    $t1, 0x34($sp)
  lw    $a1, 0x48($sp)
  addu  $t4, $v0, $v1
  addiu $t8, $t4, 0x850
  addu  $a0, $v0, $t1
  addiu $a0, $a0, 0x810
  sw    $t8, 0x10($sp)
  lw    $a2, 0x40($sp)
  jal   load_object_fill_header
   li    $a3, 48496
  b     .L7F05D2E8
   lw    $v0, 0x38($sp)
.L7F05D1F4:
  li    $at, 30
  beq   $s1, $at, .L7F05D20C
   sll   $v1, $t2, 4
  li    $at, 23
  bne   $s1, $at, .L7F05D274
   lw    $t3, 0x38($sp)
.L7F05D20C:
  lw    $a1, 0x40($sp)
  lw    $t7, ($s0)
  li    $at, 45008
  addu  $a1, $a1, $at
  lui   $at, (0xFFFF5030 >> 16) # lui $at, 0xffff
  ori   $at, (0xFFFF5030 & 0xFFFF) # ori $at, $at, 0x5030
  addu  $a0, $t7, $v1
  addiu $a0, $a0, 0x850
  addu  $a2, $a3, $at
  sw    $v1, 0x30($sp)
  jal   sub_GAME_7F0CBAF4
   sw    $t1, 0x34($sp)
  lw    $v1, 0x30($sp)
  lw    $v0, ($s0)
  lw    $t1, 0x34($sp)
  lw    $a1, 0x48($sp)
  addu  $t5, $v0, $v1
  addiu $t6, $t5, 0x850
  addu  $a0, $v0, $t1
  addiu $a0, $a0, 0x810
  sw    $t6, 0x10($sp)
  lw    $a2, 0x40($sp)
  jal   load_object_fill_header
   li    $a3, 45008
  b     .L7F05D2E8
   lw    $v0, 0x38($sp)
.L7F05D274:
  lui   $t4, %hi(D_80032464) 
  addiu $t4, %lo(D_80032464) # addiu $t4, $t4, 0x2464
  lw    $t9, ($s0)
  addu  $t0, $t3, $t4
  lw    $v0, ($t0)
  lw    $t8, 0x40($sp)
  sll   $v1, $t2, 4
  addu  $a0, $t9, $v1
  addiu $a0, $a0, 0x850
  sw    $v1, 0x30($sp)
  sw    $t0, 0x2c($sp)
  sw    $t1, 0x34($sp)
  subu  $a2, $a3, $v0
  jal   sub_GAME_7F0CBAF4
   addu  $a1, $v0, $t8
  lw    $v1, 0x30($sp)
  lw    $v0, ($s0)
  lw    $t1, 0x34($sp)
  lw    $t0, 0x2c($sp)
  addu  $t7, $v0, $v1
  addiu $t5, $t7, 0x850
  addu  $a0, $v0, $t1
  addiu $a0, $a0, 0x810
  sw    $t5, 0x10($sp)
  lw    $a1, 0x48($sp)
  lw    $a2, 0x40($sp)
  jal   load_object_fill_header
   lw    $a3, ($t0)
  lw    $v0, 0x38($sp)
.L7F05D2E8:
  lw    $t9, ($s0)
  li    $t6, 1
  li    $t7, -1
  addu  $t3, $t9, $v0
  sw    $t6, 0x7f8($t3)
  lw    $t4, ($s0)
  addu  $t8, $t4, $v0
  sw    $s1, 0x800($t8)
  lw    $t5, ($s0)
  addu  $t9, $t5, $v0
  b     .L7F05D320
   sw    $t7, 0x2a44($t9)
  addiu $t6, $v1, -1
.L7F05D31C:
  sw    $t6, 0x7f8($v0)
.L7F05D320:
  lw    $ra, 0x24($sp)
.L7F05D324:
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x50
");

asm(R"
glabel sub_GAME_7F05D334
  addiu $sp, $sp, -0x28
  sw    $s3, 0x20($sp)
  sw    $s0, 0x14($sp)
  move  $s0, $a0
  move  $s3, $a1
  sw    $ra, 0x24($sp)
  sw    $s2, 0x1c($sp)
  blez  $a1, .L7F05D3AC
   sw    $s1, 0x18($sp)
  li    $s1, 33
  addiu $t6, $s0, 1
.L7F05D360:
  div   $zero, $t6, $s1
  mfhi  $s0
  move  $a0, $s0
  bnez  $s1, .L7F05D378
   nop   
  break 7
.L7F05D378:
  li    $at, -1
  bne   $s1, $at, .L7F05D390
   lui   $at, 0x8000
  bne   $t6, $at, .L7F05D390
   nop   
  break 6
.L7F05D390:
  jal   check_if_item_available
   nop   
  beql  $v0, $zero, .L7F05D360
   addiu $t6, $s0, 1
  addiu $s3, $s3, -1
  bgtzl $s3, .L7F05D360
   addiu $t6, $s0, 1
.L7F05D3AC:
  bgez  $s3, .L7F05D414
   li    $s1, 33
  li    $s2, 32
  addiu $s0, $s0, -1
.L7F05D3BC:
  bgez  $s0, .L7F05D3F8
   li    $t7, -1
  subu  $t8, $t7, $s0
  div   $zero, $t8, $s1
  mfhi  $t9
  subu  $s0, $s2, $t9
  bnez  $s1, .L7F05D3E0
   nop   
  break 7
.L7F05D3E0:
  li    $at, -1
  bne   $s1, $at, .L7F05D3F8
   lui   $at, 0x8000
  bne   $t8, $at, .L7F05D3F8
   nop   
  break 6
.L7F05D3F8:
  jal   check_if_item_available
   move  $a0, $s0
  beql  $v0, $zero, .L7F05D3BC
   addiu $s0, $s0, -1
  addiu $s3, $s3, 1
  bltzl $s3, .L7F05D3BC
   addiu $s0, $s0, -1
.L7F05D414:
  lw    $ra, 0x24($sp)
  move  $v0, $s0
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
glabel get_next_weapon_in_cycle_for_hand
  sll   $t7, $a0, 3
  subu  $t7, $t7, $a0
  sll   $t7, $t7, 2
  addu  $t7, $t7, $a0
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  sll   $t7, $t7, 2
  addu  $t7, $t7, $a0
  addiu $sp, $sp, -0x18
  sll   $t7, $t7, 3
  sw    $ra, 0x14($sp)
  addu  $v1, $t6, $t7
  lw    $v0, 0x894($v1)
  li    $at, 5
  bnel  $v0, $at, .L7F05D4B8
   li    $at, 6
  bgez  $a1, .L7F05D488
   nop   
  lw    $t8, 0x8b8($v1)
  bgtz  $t8, .L7F05D49C
   nop   
.L7F05D488:
  blez  $a1, .L7F05D4AC
   nop   
  lw    $t9, 0x8b8($v1)
  bgez  $t9, .L7F05D4AC
   nop   
.L7F05D49C:
  jal   get_item_in_hand
   nop   
  b     .L7F05D4D4
   lw    $ra, 0x14($sp)
.L7F05D4AC:
  b     .L7F05D4D0
   lw    $v0, 0x8ac($v1)
  li    $at, 6
.L7F05D4B8:
  bne   $v0, $at, .L7F05D4C8
   nop   
  b     .L7F05D4D0
   lw    $v0, 0x8ac($v1)
.L7F05D4C8:
  jal   get_item_in_hand
   nop   
.L7F05D4D0:
  lw    $ra, 0x14($sp)
.L7F05D4D4:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F05D4E0
  sll   $a3, $a0, 3
  subu  $a3, $a3, $a0
  lui   $t0, %hi(pPlayer) 
  sll   $a3, $a3, 2
  addiu $t0, %lo(pPlayer) # addiu $t0, $t0, -0x5f50
  addu  $a3, $a3, $a0
  lw    $t6, ($t0)
  addiu $sp, $sp, -0x20
  sll   $a3, $a3, 2
  addu  $a3, $a3, $a0
  sll   $a3, $a3, 3
  sw    $ra, 0x14($sp)
  sw    $a1, 0x24($sp)
  sw    $a2, 0x28($sp)
  addu  $v0, $t6, $a3
  lw    $v1, 0x894($v0)
  li    $at, 5
  beq   $v1, $at, .L7F05D534
   li    $at, 6
  bnel  $v1, $at, .L7F05D590
   move  $a1, $zero
.L7F05D534:
  lw    $t7, 0x890($v0)
  sw    $t7, 0x8b0($v0)
  sw    $a3, 0x1c($sp)
  jal   getPlayerCount
   sw    $a0, 0x20($sp)
  lui   $t0, %hi(pPlayer) 
  li    $at, 1
  addiu $t0, %lo(pPlayer) # addiu $t0, $t0, -0x5f50
  lw    $a0, 0x20($sp)
  bne   $v0, $at, .L7F05D578
   lw    $a3, 0x1c($sp)
  lw    $t8, ($t0)
  addu  $v0, $t8, $a3
  lw    $t9, 0x8b0($v0)
  addiu $t1, $t9, 0x11
  b     .L7F05D58C
   sw    $t1, 0x8b0($v0)
.L7F05D578:
  lw    $t2, ($t0)
  addu  $v0, $t2, $a3
  lw    $t3, 0x8b0($v0)
  addiu $t4, $t3, 0xd
  sw    $t4, 0x8b0($v0)
.L7F05D58C:
  move  $a1, $zero
.L7F05D590:
  jal   get_next_weapon_in_cycle_for_hand
   sw    $a3, 0x1c($sp)
  lw    $t5, 0x24($sp)
  lui   $t0, %hi(pPlayer) 
  addiu $t0, %lo(pPlayer) # addiu $t0, $t0, -0x5f50
  beq   $v0, $t5, .L7F05D600
   lw    $a3, 0x1c($sp)
  lw    $t6, ($t0)
  li    $at, 5
  addu  $v0, $t6, $a3
  lw    $v1, 0x894($v0)
  beq   $v1, $at, .L7F05D5D8
   li    $at, 6
  beq   $v1, $at, .L7F05D5D8
   li    $t7, 5
  sw    $t7, 0x898($v0)
  lw    $t8, ($t0)
  addu  $v0, $t8, $a3
.L7F05D5D8:
  lw    $t9, 0x24($sp)
  li    $t1, 1
  sw    $t9, 0x8ac($v0)
  lw    $t2, ($t0)
  addu  $t3, $t2, $a3
  sw    $t1, 0x8b4($t3)
  lw    $t5, ($t0)
  lw    $t4, 0x28($sp)
  addu  $t6, $t5, $a3
  sw    $t4, 0x8b8($t6)
.L7F05D600:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F05D610
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  jal   get_next_weapon_in_cycle_for_hand
   move  $a1, $zero
  move  $a0, $v0
  jal   sub_GAME_7F05D334
   li    $a1, 1
  lw    $a0, 0x18($sp)
  move  $a1, $v0
  jal   sub_GAME_7F05D4E0
   move  $a2, $zero
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F05D650
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  jal   get_next_weapon_in_cycle_for_hand
   move  $a1, $zero
  move  $a0, $v0
  jal   sub_GAME_7F05D334
   li    $a1, -1
  lw    $a0, 0x18($sp)
  move  $a1, $v0
  jal   sub_GAME_7F05D4E0
   move  $a2, $zero
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F05D690
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  move  $a0, $zero
  jal   draw_item_in_hand_has_more_ammo
   lw    $a1, 0x878($t6)
  lui   $t7, %hi(pPlayer) 
  lw    $t7, %lo(pPlayer)($t7)
  li    $a0, 1
  jal   draw_item_in_hand_has_more_ammo
   lw    $a1, 0xc20($t7)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel advance_through_inventory
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  move  $a0, $zero
  jal   get_next_weapon_in_cycle_for_hand
   li    $a1, 1
  sw    $v0, 0x24($sp)
  li    $a0, 1
  jal   get_next_weapon_in_cycle_for_hand
   li    $a1, 1
  lw    $t6, 0x24($sp)
  sw    $v0, 0x20($sp)
  slti  $at, $t6, 0x21
  beqz  $at, .L7F05D710
   slti  $at, $v0, 0x21
  bnez  $at, .L7F05D72C
   addiu $a0, $sp, 0x24
.L7F05D710:
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lw    $t7, 0x878($v0)
  sw    $t7, 0x24($sp)
  lw    $t8, 0xc20($v0)
  b     .L7F05D738
   sw    $t8, 0x20($sp)
.L7F05D72C:
  addiu $a1, $sp, 0x20
  jal   sub_GAME_7F08C86C
   move  $a2, $zero
.L7F05D738:
  move  $a0, $zero
  lw    $a1, 0x24($sp)
  jal   sub_GAME_7F05D4E0
   li    $a2, 1
  li    $a0, 1
  lw    $a1, 0x20($sp)
  jal   sub_GAME_7F05D4E0
   li    $a2, 1
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel backstep_through_inventory
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  move  $a0, $zero
  jal   get_next_weapon_in_cycle_for_hand
   li    $a1, -1
  sw    $v0, 0x24($sp)
  li    $a0, 1
  jal   get_next_weapon_in_cycle_for_hand
   li    $a1, -1
  lw    $t6, 0x24($sp)
  sw    $v0, 0x20($sp)
  slti  $at, $t6, 0x21
  beqz  $at, .L7F05D7A8
   slti  $at, $v0, 0x21
  bnez  $at, .L7F05D7C4
   addiu $a0, $sp, 0x24
.L7F05D7A8:
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lw    $t7, 0x878($v0)
  sw    $t7, 0x24($sp)
  lw    $t8, 0xc20($v0)
  b     .L7F05D7D0
   sw    $t8, 0x20($sp)
.L7F05D7C4:
  addiu $a1, $sp, 0x20
  jal   sub_GAME_7F08CB10
   move  $a2, $zero
.L7F05D7D0:
  move  $a0, $zero
  lw    $a1, 0x24($sp)
  jal   sub_GAME_7F05D4E0
   li    $a2, -1
  li    $a0, 1
  lw    $a1, 0x20($sp)
  jal   sub_GAME_7F05D4E0
   li    $a2, -1
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel autoadvance_on_deplete_all_ammo
  addiu $sp, $sp, -0x30
  sw    $ra, 0x14($sp)
  move  $a0, $zero
  jal   get_next_weapon_in_cycle_for_hand
   li    $a1, 1
  sw    $v0, 0x2c($sp)
  sw    $v0, 0x24($sp)
  li    $a0, 1
  jal   get_next_weapon_in_cycle_for_hand
   li    $a1, 1
  lw    $t6, 0x24($sp)
  move  $v1, $v0
  sw    $v0, 0x20($sp)
  slti  $at, $t6, 0x21
  beqz  $at, .L7F05D848
   slti  $at, $v0, 0x21
  bnez  $at, .L7F05D864
   lw    $t9, 0x24($sp)
.L7F05D848:
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lw    $t7, 0x878($v0)
  sw    $t7, 0x24($sp)
  lw    $t8, 0xc20($v0)
  b     .L7F05D8E4
   sw    $t8, 0x20($sp)
.L7F05D864:
  li    $at, 29
  bne   $t9, $at, .L7F05D890
   li    $a0, 30
  jal   check_if_item_available
   sw    $v1, 0x28($sp)
  beqz  $v0, .L7F05D890
   lw    $v1, 0x28($sp)
  li    $t0, 30
  sw    $t0, 0x24($sp)
  b     .L7F05D8E4
   sw    $zero, 0x20($sp)
.L7F05D890:
  addiu $a0, $sp, 0x24
  addiu $a1, $sp, 0x20
  li    $a2, 1
  jal   sub_GAME_7F08C86C
   sw    $v1, 0x28($sp)
  lw    $v0, 0x2c($sp)
  lw    $t1, 0x24($sp)
  lw    $v1, 0x28($sp)
  addiu $a0, $sp, 0x24
  slt   $at, $t1, $v0
  bnez  $at, .L7F05D8D4
   addiu $a1, $sp, 0x20
  bne   $t1, $v0, .L7F05D8E4
   lw    $t2, 0x20($sp)
  slt   $at, $v1, $t2
  bnezl $at, .L7F05D8E8
   move  $a0, $zero
.L7F05D8D4:
  sw    $v0, 0x24($sp)
  sw    $v1, 0x20($sp)
  jal   sub_GAME_7F08CB10
   li    $a2, 1
.L7F05D8E4:
  move  $a0, $zero
.L7F05D8E8:
  lw    $a1, 0x24($sp)
  jal   sub_GAME_7F05D4E0
   li    $a2, 1
  li    $a0, 1
  lw    $a1, 0x20($sp)
  jal   sub_GAME_7F05D4E0
   li    $a2, 1
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
glabel draw_item_in_hand_has_more_ammo
  sll   $v0, $a0, 3
  subu  $v0, $v0, $a0
  lui   $v1, %hi(pPlayer)
  sll   $v0, $v0, 2
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  addu  $v0, $v0, $a0
  lw    $t7, ($v1)
  sll   $v0, $v0, 2
  addu  $v0, $v0, $a0
  sll   $v0, $v0, 3
  li    $t6, 5
  addu  $t8, $t7, $v0
  sw    $t6, 0x898($t8)
  lw    $t9, ($v1)
  addu  $t0, $t9, $v0
  sw    $a1, 0x8ac($t0)
  lw    $t1, ($v1)
  addu  $t2, $t1, $v0
  jr    $ra
   sw    $zero, 0x8b4($t2)
");

asm(R"
glabel attempt_reload_item_in_hand
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   get_item_in_hand
   sw    $a0, 0x18($sp)
  jal   get_ammo_type_for_weapon
   move  $a0, $v0
  beqz  $v0, .L7F05D9C0
   lw    $t7, 0x18($sp)
  sll   $t8, $t7, 3
  subu  $t8, $t8, $t7
  sll   $t8, $t8, 2
  addu  $t8, $t8, $t7
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  sll   $t8, $t8, 2
  addu  $t8, $t8, $t7
  sll   $t8, $t8, 3
  addu  $v0, $t6, $t8
  lw    $t9, 0x898($v0)
  li    $t0, 9
  bnezl $t9, .L7F05D9C4
   lw    $ra, 0x14($sp)
  sw    $t0, 0x898($v0)
.L7F05D9C0:
  lw    $ra, 0x14($sp)
.L7F05D9C4:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel get_item_in_hand
  sll   $t7, $a0, 3
  subu  $t7, $t7, $a0
  sll   $t7, $t7, 2
  addu  $t7, $t7, $a0
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  sll   $t7, $t7, 2
  addu  $t7, $t7, $a0
  sll   $t7, $t7, 3
  addu  $t8, $t6, $t7
  jr    $ra
   lw    $v0, 0x870($t8)
");

asm(R"
glabel draw_item_in_hand
  sll   $v0, $a0, 3
  subu  $v0, $v0, $a0
  lui   $v1, %hi(pPlayer)
  sll   $v0, $v0, 2
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  addu  $v0, $v0, $a0
  lw    $t7, ($v1)
  sll   $v0, $v0, 2
  addu  $v0, $v0, $a0
  sll   $v0, $v0, 3
  li    $t6, 14
  addu  $t8, $t7, $v0
  sw    $t6, 0x898($t8)
  lw    $t9, ($v1)
  addu  $t0, $t9, $v0
  jr    $ra
   sw    $a1, 0x8ac($t0)
");

asm(R"
glabel return_ammo_in_hand
  sll   $t7, $a0, 3
  subu  $t7, $t7, $a0
  sll   $t7, $t7, 2
  addu  $t7, $t7, $a0
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  sll   $t7, $t7, 2
  addu  $t7, $t7, $a0
  sll   $t7, $t7, 3
  addu  $v1, $t6, $t7
  lw    $a1, 0x874($v1)
  bltzl $a1, .L7F05DA84
   lw    $v0, 0x870($v1)
  jr    $ra
   move  $v0, $a1

  lw    $v0, 0x870($v1)
.L7F05DA84:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F05DA8C
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  jal   place_item_in_hand_swap_and_make_visible
   sw    $a1, 0x1c($sp)
  lw    $t8, 0x18($sp)
  lui   $t7, %hi(pPlayer) 
  lw    $t7, %lo(pPlayer)($t7)
  sll   $t9, $t8, 3
  subu  $t9, $t9, $t8
  sll   $t9, $t9, 2
  addu  $t9, $t9, $t8
  sll   $t9, $t9, 2
  lw    $t6, 0x1c($sp)
  addu  $t9, $t9, $t8
  sll   $t9, $t9, 3
  addu  $t0, $t7, $t9
  sw    $t6, 0x874($t0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F05DAE4
  sll   $v0, $a0, 3
  subu  $v0, $v0, $a0
  sll   $v0, $v0, 2
  addu  $v0, $v0, $a0
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  sll   $v0, $v0, 2
  addu  $v0, $v0, $a0
  addiu $sp, $sp, -0x20
  sll   $v0, $v0, 3
  sw    $ra, 0x14($sp)
  addu  $v1, $t6, $v0
  lw    $t7, 0x874($v1)
  bltzl $t7, .L7F05DB48
   lw    $ra, 0x14($sp)
  lw    $a1, 0x870($v1)
  jal   place_item_in_hand_swap_and_make_visible
   sw    $v0, 0x1c($sp)
  lui   $t9, %hi(pPlayer) 
  lw    $v0, 0x1c($sp)
  lw    $t9, %lo(pPlayer)($t9)
  li    $t8, -1
  addu  $t0, $t9, $v0
  sw    $t8, 0x874($t0)
  lw    $ra, 0x14($sp)
.L7F05DB48:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel remove_hands_item
  addiu $sp, $sp, -0x28
  sll   $t6, $a0, 3
  sw    $s1, 0x18($sp)
  subu  $t6, $t6, $a0
  lui   $s1, %hi(pPlayer)
  sll   $t6, $t6, 2
  addiu $s1, %lo(pPlayer) # addiu $s1, $s1, -0x5f50
  addu  $t6, $t6, $a0
  lw    $t7, ($s1)
  sll   $t6, $t6, 2
  sw    $s0, 0x14($sp)
  addu  $t6, $t6, $a0
  sll   $s0, $t6, 3
  sw    $ra, 0x1c($sp)
  sw    $a0, 0x28($sp)
  sw    $a1, 0x2c($sp)
  addu  $t8, $t7, $s0
  lw    $a0, 0x870($t8)
  jal   get_ammo_type_for_weapon
   sw    $a0, 0x24($sp)
  lw    $v1, ($s1)
  lw    $a2, 0x24($sp)
  move  $a3, $v0
  addu  $a0, $v1, $s0
  lw    $t9, 0x874($a0)
  lw    $a1, 0x2c($sp)
  bgezl $t9, .L7F05DBE8
   lw    $a1, 0x89c($a0)
  lw    $a0, 0x28($sp)
  sw    $a2, 0x24($sp)
  jal   place_item_in_hand_swap_and_make_visible
   sw    $v0, 0x20($sp)
  lw    $v1, ($s1)
  lw    $a2, 0x24($sp)
  lw    $a3, 0x20($sp)
  addu  $a0, $v1, $s0
  lw    $a1, 0x89c($a0)
.L7F05DBE8:
  sll   $t0, $a3, 2
  addu  $v0, $v1, $t0
  blez  $a1, .L7F05DC04
   slti  $at, $a2, 0x21
  lw    $t1, 0x1130($v0)
  addu  $t2, $t1, $a1
  sw    $t2, 0x1130($v0)
.L7F05DC04:
  beqz  $at, .L7F05DC18
   nop   
  lw    $t3, ($s1)
  addu  $t4, $t3, $s0
  sw    $a2, 0x878($t4)
.L7F05DC18:
  jal   getPlayerCount
   nop   
  slti  $at, $v0, 2
  bnez  $at, .L7F05DC34
   nop   
  jal   sub_GAME_7F09B368
   lw    $a0, 0x28($sp)
.L7F05DC34:
  jal   sub_GAME_7F05FB00
   lw    $a0, 0x28($sp)
  lw    $t6, ($s1)
  lw    $t5, 0x2c($sp)
  addu  $t7, $t6, $s0
  sw    $t5, 0x870($t7)
  lw    $t8, ($s1)
  addu  $t9, $t8, $s0
  sw    $zero, 0x89c($t9)
  lw    $t0, ($s1)
  addu  $t1, $t0, $s0
  sw    $zero, 0xa4c($t1)
  lw    $t2, ($s1)
  addu  $t3, $t2, $s0
  jal   calculate_equip_cur_item
   sw    $zero, 0xa50($t3)
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
glabel get_hands_firing_status
  sll   $t7, $a0, 3
  subu  $t7, $t7, $a0
  sll   $t7, $t7, 2
  addu  $t7, $t7, $a0
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  sll   $t7, $t7, 2
  addu  $t7, $t7, $a0
  sll   $t7, $t7, 3
  addu  $t8, $t6, $t7
  jr    $ra
   lb    $v0, 0x87c($t8)
");

asm(R"
glabel sub_GAME_7F05DCB8
  sll   $t7, $a0, 3
  subu  $t7, $t7, $a0
  sll   $t7, $t7, 2
  addu  $t7, $t7, $a0
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  sll   $t7, $t7, 2
  addu  $t7, $t7, $a0
  sll   $t7, $t7, 3
  addu  $t8, $t6, $t7
  jr    $ra
   lwc1  $f0, 0xa34($t8)
");

asm(R"
glabel sub_GAME_7F05DCE8
  addiu $sp, $sp, -0x18
  bnez  $a0, .L7F05DD0C
   sw    $ra, 0x14($sp)
  jal   return_ammo_in_hand
   move  $a0, $zero
  jal   get_ptr_item_statistics
   move  $a0, $v0
  b     .L7F05DD24
   lwc1  $f2, 4($v0)
.L7F05DD0C:
  jal   return_ammo_in_hand
   li    $a0, 1
  jal   get_ptr_item_statistics
   move  $a0, $v0
  lwc1  $f2, 4($v0)
  neg.s $f2, $f2
.L7F05DD24:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  mov.s $f0, $f2
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F05DD38
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   return_ammo_in_hand
   move  $a0, $zero
  li    $at, 17
  bne   $v0, $at, .L7F05DD60
   lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  b     .L7F05DD94
   lwc1  $f0, 0x1084($t6)
.L7F05DD60:
  jal   return_ammo_in_hand
   move  $a0, $zero
  li    $at, 40
  bne   $v0, $at, .L7F05DD80
   lui   $t7, %hi(pPlayer) 
  lw    $t7, %lo(pPlayer)($t7)
  b     .L7F05DD94
   lwc1  $f0, 0x1088($t7)
.L7F05DD80:
  jal   return_ammo_in_hand
   move  $a0, $zero
  jal   get_ptr_item_statistics
   move  $a0, $v0
  lwc1  $f0, 0x34($v0)
.L7F05DD94:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80053C24
.word 0x3dcccccd /*0.1*/
glabel D_80053C28
.word 0x3dcccccd /*0.1*/
.text
glabel sub_GAME_7F05DDA4
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  swc1  $f12, 0x18($sp)
  jal   return_ammo_in_hand
   move  $a0, $zero
  li    $at, 17
  bne   $v0, $at, .L7F05DE1C
   lwc1  $f4, 0x18($sp)
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f0
  lui   $at, %hi(D_80053C24)
  lwc1  $f6, %lo(D_80053C24)($at)
  lui   $v1, %hi(pPlayer)
  li    $at, 0x3F800000 # 1.000000
  mul.s $f8, $f4, $f6
  mtc1  $at, $f10
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $v0, ($v1)
  lwc1  $f18, 0x1084($v0)
  add.s $f16, $f10, $f8
  mul.s $f4, $f18, $f16
  swc1  $f4, 0x1084($v0)
  lw    $v0, ($v1)
  lwc1  $f6, 0x1084($v0)
  c.lt.s $f0, $f6
  nop   
  bc1fl .L7F05DE88
   lw    $ra, 0x14($sp)
  b     .L7F05DE84
   swc1  $f0, 0x1084($v0)
.L7F05DE1C:
  jal   return_ammo_in_hand
   move  $a0, $zero
  li    $at, 40
  bne   $v0, $at, .L7F05DE84
   lwc1  $f10, 0x18($sp)
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f0
  lui   $at, %hi(D_80053C28)
  lwc1  $f8, %lo(D_80053C28)($at)
  lui   $v1, %hi(pPlayer)
  li    $at, 0x3F800000 # 1.000000
  mul.s $f18, $f10, $f8
  mtc1  $at, $f16
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $v0, ($v1)
  lwc1  $f6, 0x1088($v0)
  add.s $f4, $f16, $f18
  mul.s $f10, $f6, $f4
  swc1  $f10, 0x1088($v0)
  lw    $v0, ($v1)
  lwc1  $f8, 0x1088($v0)
  c.lt.s $f0, $f8
  nop   
  bc1fl .L7F05DE88
   lw    $ra, 0x14($sp)
  swc1  $f0, 0x1088($v0)
.L7F05DE84:
  lw    $ra, 0x14($sp)
.L7F05DE88:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80053C2C
.word 0x3dcccccd /*0.1*/
glabel D_80053C30
.word 0x3dcccccd /*0.1*/
.text
glabel sub_GAME_7F05DE94
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  swc1  $f12, 0x18($sp)
  jal   return_ammo_in_hand
   move  $a0, $zero
  li    $at, 17
  bne   $v0, $at, .L7F05DF0C
   lwc1  $f4, 0x18($sp)
  li    $at, 0x40E00000 # 7.000000
  mtc1  $at, $f0
  lui   $at, %hi(D_80053C2C)
  lwc1  $f6, %lo(D_80053C2C)($at)
  lui   $v1, %hi(pPlayer)
  li    $at, 0x3F800000 # 1.000000
  mul.s $f8, $f4, $f6
  mtc1  $at, $f10
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $v0, ($v1)
  lwc1  $f18, 0x1084($v0)
  add.s $f16, $f10, $f8
  div.s $f4, $f18, $f16
  swc1  $f4, 0x1084($v0)
  lw    $v0, ($v1)
  lwc1  $f6, 0x1084($v0)
  c.lt.s $f6, $f0
  nop   
  bc1fl .L7F05DF78
   lw    $ra, 0x14($sp)
  b     .L7F05DF74
   swc1  $f0, 0x1084($v0)
.L7F05DF0C:
  jal   return_ammo_in_hand
   move  $a0, $zero
  li    $at, 40
  bne   $v0, $at, .L7F05DF74
   lwc1  $f10, 0x18($sp)
  li    $at, 0x40E00000 # 7.000000
  mtc1  $at, $f0
  lui   $at, %hi(D_80053C30)
  lwc1  $f8, %lo(D_80053C30)($at)
  lui   $v1, %hi(pPlayer)
  li    $at, 0x3F800000 # 1.000000
  mul.s $f18, $f10, $f8
  mtc1  $at, $f16
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $v0, ($v1)
  lwc1  $f6, 0x1088($v0)
  add.s $f4, $f16, $f18
  div.s $f10, $f6, $f4
  swc1  $f10, 0x1088($v0)
  lw    $v0, ($v1)
  lwc1  $f8, 0x1088($v0)
  c.lt.s $f8, $f0
  nop   
  bc1fl .L7F05DF78
   lw    $ra, 0x14($sp)
  swc1  $f0, 0x1088($v0)
.L7F05DF74:
  lw    $ra, 0x14($sp)
.L7F05DF78:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F05DF84
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   get_ptr_item_statistics
   nop   
  lw    $ra, 0x14($sp)
  lwc1  $f0, 0x2c($v0)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F05DFA8
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   get_ptr_item_statistics
   nop   
  lw    $ra, 0x14($sp)
  lwc1  $f0, 0x68($v0)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

signed char get_automatic_firing_rate(int item) {
  return get_ptr_item_statistics(item)->automatic_firing_rate;
}

unsigned char get_sound_trigger_rate(int item) {
  return get_ptr_item_statistics(item)->sound_trigger_rate;
}

asm(R"
glabel sub_GAME_7F05E014
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   get_ptr_item_statistics
   nop   
  lw    $ra, 0x14($sp)
  lhu   $v0, 0x26($v0)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F05E038
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   get_ptr_item_statistics
   nop   
  lw    $ra, 0x14($sp)
  lbu   $v0, 0x24($v0)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel check_if_have_ammo_for_item
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  jal   check_special_attributes
   lui   $a1, 4
  beql  $v0, $zero, .L7F05E0A4
   move  $v0, $zero
  jal   get_ammo_type_for_weapon
   lw    $a0, 0x18($sp)
  beqz  $v0, .L7F05E098
   nop   
  jal   get_ammo_count_for_weapon
   lw    $a0, 0x18($sp)
  blezl $v0, .L7F05E0A4
   move  $v0, $zero
.L7F05E098:
  b     .L7F05E0A4
   li    $v0, 1
  move  $v0, $zero
.L7F05E0A4:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel check_special_attributes
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   get_ptr_item_statistics
   sw    $a1, 0x1c($sp)
  lw    $t6, 0x6c($v0)
  lw    $t7, 0x1c($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  and   $v0, $t6, $t7
  sltu  $t8, $zero, $v0
  jr    $ra
   move  $v0, $t8
");

asm(R"
.late_rodata
glabel D_80053C34
.word 0x3f4ccccd /*0.80000001*/
glabel D_80053C38
.word 0x3dcccccd /*0.1*/
glabel D_80053C3C
.word 0x3dcccccd /*0.1*/
glabel D_80053C40
.word 0x40c90fdb /*6.2831855*/
glabel D_80053C44
.word 0x40333333 /*2.8*/
glabel D_80053C48
.word 0x3f4ccccd /*0.80000001*/
glabel D_80053C4C
.word 0x3e4ccccd /*0.2*/
glabel D_80053C50
.word 0x3dcccccd /*0.1*/
glabel D_80053C54
.word 0x3e99999a /*0.30000001*/
glabel D_80053C58
.word 0x3e99999a /*0.30000001*/
glabel D_80053C5C
.word 0x3f733333 /*0.94999999*/
glabel D_80053C60
.word 0x3f733333 /*0.94999999*/
glabel D_80053C64
.word 0x3d4cccd0 /*0.050000012*/
glabel D_80053C68
.word 0x3c888889 /*0.016666668*/
glabel D_80053C6C
.word 0x3e4ccccd /*0.2*/
glabel D_80053C70
.word 0x3dcccccd /*0.1*/
glabel D_80053C74
.word 0xbdcccccd /*-0.1*/
.text
glabel sub_GAME_7F05E0E4
  addiu $sp, $sp, -0x68
  sw    $a2, 0x70($sp)
  lwc1  $f4, 0x70($sp)
  mtc1  $zero, $f6
  sdc1  $f22, 0x20($sp)
  mov.s $f22, $f12
  c.lt.s $f4, $f6
  sw    $ra, 0x2c($sp)
  sw    $s0, 0x28($sp)
  sdc1  $f20, 0x18($sp)
  sw    $a3, 0x74($sp)
  bc1f  .L7F05E11C
   mov.s $f16, $f4
  neg.s $f16, $f4
.L7F05E11C:
  lui   $at, %hi(D_80053C34)
  lwc1  $f8, %lo(D_80053C34)($at)
  lui   $s0, %hi(pPlayer)
  addiu $s0, %lo(pPlayer) # addiu $s0, $s0, -0x5f50
  c.lt.s $f8, $f14
  li    $at, 0x3F800000 # 1.000000
  bc1f  .L7F05E14C
   nop   
  mtc1  $at, $f20
  lw    $t6, ($s0)
  b     .L7F05E1DC
   swc1  $f20, 0xfc0($t6)
.L7F05E14C:
  lui   $at, %hi(D_80053C3C)
  lwc1  $f0, %lo(D_80053C3C)($at)
  c.lt.s $f0, $f14
  nop   
  bc1f  .L7F05E1C4
   nop   
  sub.s $f10, $f14, $f0
  lui   $at, %hi(D_80053C40)
  lwc1  $f18, %lo(D_80053C40)($at)
  lui   $at, %hi(D_80053C44)
  lwc1  $f4, %lo(D_80053C44)($at)
  mul.s $f6, $f10, $f18
  swc1  $f16, 0x50($sp)
  jal   cosf
   div.s $f12, $f6, $f4
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f20
  lui   $at, %hi(D_80053C48)
  lwc1  $f8, %lo(D_80053C48)($at)
  sub.s $f10, $f20, $f0
  lui   $at, %hi(D_80053C4C)
  lwc1  $f6, %lo(D_80053C4C)($at)
  lui   $s0, %hi(pPlayer)
  mul.s $f18, $f8, $f10
  addiu $s0, %lo(pPlayer) # addiu $s0, $s0, -0x5f50
  lw    $t7, ($s0)
  lwc1  $f16, 0x50($sp)
  add.s $f4, $f18, $f6
  b     .L7F05E1DC
   swc1  $f4, 0xfc0($t7)
.L7F05E1C4:
  lui   $s0, %hi(pPlayer)
  addiu $s0, %lo(pPlayer) # addiu $s0, $s0, -0x5f50
  lw    $t8, ($s0)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f20
  swc1  $f0, 0xfc0($t8)
.L7F05E1DC:
  jal   get_BONDdata_bondfadefracnew
   swc1  $f16, 0x50($sp)
  lui   $at, %hi(D_80053C54)
  lwc1  $f8, %lo(D_80053C54)($at)
  lw    $v1, ($s0)
  lwc1  $f16, 0x50($sp)
  mul.s $f10, $f0, $f8
  lwc1  $f2, 0xfc0($v1)
  c.lt.s $f2, $f10
  nop   
  bc1fl .L7F05E238
   lui   $at, 0x3f00
  jal   get_BONDdata_bondfadefracnew
   swc1  $f16, 0x50($sp)
  lui   $at, %hi(D_80053C58)
  lwc1  $f18, %lo(D_80053C58)($at)
  lw    $t9, ($s0)
  lwc1  $f16, 0x50($sp)
  mul.s $f6, $f0, $f18
  swc1  $f6, 0xfc0($t9)
  lw    $v1, ($s0)
  lwc1  $f2, 0xfc0($v1)
  li    $at, 0x3F000000 # 0.500000
.L7F05E238:
  mtc1  $at, $f4
  lui   $a0, %hi(clock_timer)
  addiu $a0, %lo(clock_timer) # addiu $a0, $a0, -0x7c8c
  mul.s $f0, $f4, $f16
  c.lt.s $f2, $f0
  nop   
  bc1fl .L7F05E260
   lw    $t0, ($a0)
  swc1  $f0, 0xfc0($v1)
  lw    $t0, ($a0)
.L7F05E260:
  move  $v0, $zero
  blez  $t0, .L7F05E2A0
   lui   $at, %hi(D_80053C5C)
  lwc1  $f0, %lo(D_80053C5C)($at)
  lw    $v1, ($s0)
.L7F05E274:
  addiu $v0, $v0, 1
  lwc1  $f8, 0x1080($v1)
  lwc1  $f18, 0xfc0($v1)
  mul.s $f10, $f8, $f0
  add.s $f6, $f10, $f18
  swc1  $f6, 0x1080($v1)
  lw    $t1, ($a0)
  slt   $at, $v0, $t1
  bnezl $at, .L7F05E274
   lw    $v1, ($s0)
  move  $v0, $zero
.L7F05E2A0:
  lw    $v1, ($s0)
  lui   $at, %hi(D_80053C60)
  lwc1  $f0, %lo(D_80053C60)($at)
  lui   $at, %hi(D_80053C64)
  lwc1  $f12, %lo(D_80053C64)($at)
  lwc1  $f4, 0x1080($v1)
  lui   $at, %hi(D_80053C68)
  mul.s $f8, $f4, $f12
  swc1  $f8, 0xfc0($v1)
  lwc1  $f10, %lo(D_80053C68)($at)
  mul.s $f2, $f10, $f16
  c.lt.s $f22, $f2
  nop   
  bc1fl .L7F05E2E4
   lw    $t2, ($a0)
  mov.s $f22, $f2
  lw    $t2, ($a0)
.L7F05E2E4:
  blezl $t2, .L7F05E318
   lw    $v1, ($s0)
  lw    $v1, ($s0)
.L7F05E2F0:
  addiu $v0, $v0, 1
  lwc1  $f18, 0x107c($v1)
  mul.s $f6, $f18, $f0
  add.s $f4, $f6, $f22
  swc1  $f4, 0x107c($v1)
  lw    $t3, ($a0)
  slt   $at, $v0, $t3
  bnezl $at, .L7F05E2F0
   lw    $v1, ($s0)
  lw    $v1, ($s0)
.L7F05E318:
  lui   $at, %hi(global_timer_delta)
  lwc1  $f0, %lo(global_timer_delta)($at)
  lwc1  $f8, 0x107c($v1)
  mul.s $f22, $f8, $f12
  nop   
  mul.s $f10, $f22, $f0
  swc1  $f10, 0x4c($sp)
  lwc1  $f6, 0x4c($sp)
  lwc1  $f18, 0xa0c($v1)
  add.s $f4, $f18, $f6
  swc1  $f4, 0x60($sp)
  lwc1  $f8, 0x60($sp)
  c.le.s $f20, $f8
  nop   
  bc1f  .L7F05E39C
   nop   
.L7F05E358:
  jal   unknown_takes_playerhand
   move  $a0, $zero
  lwc1  $f10, 0x60($sp)
  lw    $v1, ($s0)
  sub.s $f18, $f10, $f20
  swc1  $f18, 0x60($sp)
  lw    $t4, 0x1078($v1)
  addiu $t5, $t4, 1
  sw    $t5, 0x1078($v1)
  lwc1  $f6, 0x60($sp)
  c.le.s $f20, $f6
  nop   
  bc1t  .L7F05E358
   nop   
  lui   $at, %hi(global_timer_delta)
  lwc1  $f0, %lo(global_timer_delta)($at)
  lw    $v1, ($s0)
.L7F05E39C:
  lwc1  $f4, 0x1074($v1)
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f22
  add.s $f8, $f4, $f0
  swc1  $f8, 0x1074($v1)
  lw    $v1, ($s0)
  lwc1  $f10, 0x1074($v1)
  c.lt.s $f22, $f10
  nop   
  bc1fl .L7F05E428
   lwc1  $f0, 0x1070($v1)
  mtc1  $zero, $f18
  jal   get_random_value
   swc1  $f18, 0x1074($v1)
  mtc1  $v0, $f6
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F05E3F0
   cvt.s.w $f4, $f6
  mtc1  $at, $f8
  nop   
  add.s $f4, $f4, $f8
.L7F05E3F0:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f10
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f6
  mul.s $f18, $f4, $f10
  lui   $at, %hi(D_80053C6C)
  lwc1  $f4, %lo(D_80053C6C)($at)
  lw    $t6, ($s0)
  sub.s $f8, $f18, $f6
  mul.s $f10, $f8, $f4
  div.s $f18, $f10, $f22
  swc1  $f18, 0x1070($t6)
  lw    $v1, ($s0)
  lwc1  $f0, 0x1070($v1)
.L7F05E428:
  lwc1  $f8, 0x4c($sp)
  mtc1  $zero, $f6
  li    $at, 0x3F000000 # 0.500000
  add.s $f4, $f0, $f8
  mtc1  $at, $f8
  c.lt.s $f6, $f4
  nop   
  bc1fl .L7F05E460
   lwc1  $f0, 0x106c($v1)
  lwc1  $f10, 0x106c($v1)
  add.s $f18, $f10, $f0
  swc1  $f18, 0x106c($v1)
  lw    $v1, ($s0)
  lwc1  $f0, 0x106c($v1)
.L7F05E460:
  c.lt.s $f8, $f0
  nop   
  bc1f  .L7F05E488
   li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f6
  nop   
  swc1  $f6, 0x106c($v1)
  lw    $v1, ($s0)
  b     .L7F05E514
   lwc1  $f0, 0x106c($v1)
.L7F05E488:
  li    $at, 0xBF000000 # -0.500000
  mtc1  $at, $f2
  lui   $at, %hi(D_80053C70)
  c.lt.s $f0, $f2
  nop   
  bc1f  .L7F05E4B4
   nop   
  swc1  $f2, 0x106c($v1)
  lw    $v1, ($s0)
  b     .L7F05E514
   lwc1  $f0, 0x106c($v1)
.L7F05E4B4:
  lwc1  $f12, %lo(D_80053C70)($at)
  lui   $at, %hi(D_80053C74)
  c.lt.s $f0, $f12
  nop   
  bc1fl .L7F05E518
   lw    $t7, 0x1078($v1)
  lwc1  $f2, %lo(D_80053C74)($at)
  c.lt.s $f2, $f0
  nop   
  bc1fl .L7F05E518
   lw    $t7, 0x1078($v1)
  mtc1  $zero, $f4
  nop   
  c.lt.s $f4, $f0
  nop   
  bc1fl .L7F05E50C
   swc1  $f12, 0x106c($v1)
  swc1  $f2, 0x106c($v1)
  lw    $v1, ($s0)
  b     .L7F05E514
   lwc1  $f0, 0x106c($v1)
  swc1  $f12, 0x106c($v1)
.L7F05E50C:
  lw    $v1, ($s0)
  lwc1  $f0, 0x106c($v1)
.L7F05E514:
  lw    $t7, 0x1078($v1)
.L7F05E518:
  lwc1  $f10, 0x60($sp)
  mtc1  $t7, $f18
  nop   
  cvt.s.w $f8, $f18
  add.s $f6, $f10, $f8
  add.s $f4, $f6, $f0
  c.le.s $f20, $f4
  swc1  $f4, 0x64($sp)
  bc1fl .L7F05E57C
   lui   $at, 0xbfe0
.L7F05E540:
  jal   unknown_takes_playerhand
   li    $a0, 1
  lwc1  $f18, 0x64($sp)
  lw    $v1, ($s0)
  sub.s $f10, $f18, $f20
  swc1  $f10, 0x64($sp)
  lw    $t8, 0x1078($v1)
  addiu $t9, $t8, -1
  sw    $t9, 0x1078($v1)
  lwc1  $f8, 0x64($sp)
  c.le.s $f20, $f8
  nop   
  bc1t  .L7F05E540
   nop   
  li    $at, 0xBFE00000 # -1.750000
.L7F05E57C:
  mtc1  $at, $f6
  lwc1  $f4, 0x74($sp)
  li    $at, 0xC0000000 # -2.000000
  mtc1  $at, $f18
  lwc1  $f10, 0x70($sp)
  mul.s $f0, $f6, $f4
  move  $v0, $zero
  addiu $v1, $sp, 0x60
  mul.s $f2, $f18, $f10
  addiu $a0, $sp, 0x68
.L7F05E5A4:
  lw    $t0, ($s0)
  lwc1  $f8, ($v1)
  addiu $v1, $v1, 4
  addu  $t1, $t0, $v0
  swc1  $f8, 0xa0c($t1)
  lw    $t2, ($s0)
  addu  $t3, $t2, $v0
  swc1  $f0, 0xa1c($t3)
  lw    $t4, ($s0)
  addu  $t5, $t4, $v0
  addiu $v0, $v0, 0x3a8
  bne   $v1, $a0, .L7F05E5A4
   swc1  $f2, 0xa20($t5)
  lw    $ra, 0x2c($sp)
  ldc1  $f20, 0x18($sp)
  ldc1  $f22, 0x20($sp)
  lw    $s0, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x68
");

asm(R"
glabel sub_GAME_7F05E5F0
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  swc1  $f12, 0x18($sp)
  jal   cosf
   lwc1  $f12, 0x18($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  li    $at, 0x40A00000 # 5.000000
  mtc1  $at, $f8
  sub.s $f6, $f4, $f0
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  mul.s $f10, $f6, $f8
  swc1  $f10, 0xa30($t6)
  jal   cosf
   lwc1  $f12, 0x18($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f16
  li    $at, 0x40A00000 # 5.000000
  mtc1  $at, $f4
  sub.s $f18, $f16, $f0
  lui   $t7, %hi(pPlayer) 
  lw    $t7, %lo(pPlayer)($t7)
  mul.s $f6, $f18, $f4
  swc1  $f6, 0xdd8($t7)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80053C78
.word 0x3db2b8c3 /*0.087266468*/
glabel D_80053C7C
.word 0x3e32b8c3 /*0.17453294*/
.text
glabel get_value_if_watch_is_on_hand_or_not
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   get_item_in_hand
   sw    $a0, 0x18($sp)
  li    $at, 30
  beq   $v0, $at, .L7F05E690
   nop   
  jal   get_item_in_hand
   lw    $a0, 0x18($sp)
  li    $at, 23
  bne   $v0, $at, .L7F05E69C
.L7F05E690:
   lui   $at, %hi(D_80053C78)
  b     .L7F05E6A4
   lwc1  $f0, %lo(D_80053C78)($at)
.L7F05E69C:
  lui   $at, %hi(D_80053C7C)
  lwc1  $f0, %lo(D_80053C7C)($at)
.L7F05E6A4:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80053C80
.word 0x3cee4baf /*0.029088823*/
glabel D_80053C84
.word 0x3c8efa36 /*0.017453294*/
.text
glabel sub_GAME_7F05E6B4
  addiu $sp, $sp, -0x20
  beqz  $a1, .L7F05E778
   sw    $ra, 0x14($sp)
  jal   get_value_if_watch_is_on_hand_or_not
   sw    $a0, 0x20($sp)
  lw    $a0, 0x20($sp)
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  sll   $v1, $a0, 3
  subu  $v1, $v1, $a0
  sll   $v1, $v1, 2
  addu  $v1, $v1, $a0
  sll   $v1, $v1, 2
  addu  $v1, $v1, $a0
  sll   $v1, $v1, 3
  addu  $v0, $t6, $v1
  lwc1  $f2, 0xa84($v0)
  lui   $at, %hi(D_80053C80)
  c.lt.s $f2, $f0
  nop   
  bc1fl .L7F05E728
   sw    $v1, 0x1c($sp)
  lwc1  $f4, %lo(D_80053C80)($at)
  lui   $at, %hi(global_timer_delta)
  lwc1  $f6, %lo(global_timer_delta)($at)
  mul.s $f8, $f4, $f6
  add.s $f10, $f2, $f8
  swc1  $f10, 0xa84($v0)
  sw    $v1, 0x1c($sp)
.L7F05E728:
  jal   get_value_if_watch_is_on_hand_or_not
   sw    $a0, 0x20($sp)
  lui   $t7, %hi(pPlayer) 
  lw    $t7, %lo(pPlayer)($t7)
  lw    $v1, 0x1c($sp)
  lw    $a0, 0x20($sp)
  addu  $t8, $t7, $v1
  lwc1  $f16, 0xa84($t8)
  c.lt.s $f0, $f16
  nop   
  bc1fl .L7F05E7FC
   lw    $ra, 0x14($sp)
  jal   get_value_if_watch_is_on_hand_or_not
   sw    $v1, 0x1c($sp)
  lui   $t9, %hi(pPlayer) 
  lw    $t9, %lo(pPlayer)($t9)
  lw    $v1, 0x1c($sp)
  addu  $t0, $t9, $v1
  b     .L7F05E7F8
   swc1  $f0, 0xa84($t0)
.L7F05E778:
  sll   $v1, $a0, 3
  subu  $v1, $v1, $a0
  sll   $v1, $v1, 2
  addu  $v1, $v1, $a0
  lui   $t1, %hi(pPlayer) 
  lw    $t1, %lo(pPlayer)($t1)
  sll   $v1, $v1, 2
  addu  $v1, $v1, $a0
  sll   $v1, $v1, 3
  addu  $v0, $t1, $v1
  mtc1  $zero, $f0
  lwc1  $f2, 0xa84($v0)
  lui   $at, %hi(D_80053C84)
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F05E7E8
   c.lt.s $f2, $f0
  lwc1  $f18, %lo(D_80053C84)($at)
  lui   $at, %hi(global_timer_delta)
  lwc1  $f4, %lo(global_timer_delta)($at)
  lui   $t2, %hi(pPlayer) 
  mul.s $f6, $f18, $f4
  sub.s $f8, $f2, $f6
  swc1  $f8, 0xa84($v0)
  lw    $t2, %lo(pPlayer)($t2)
  addu  $v0, $t2, $v1
  lwc1  $f2, 0xa84($v0)
  c.lt.s $f2, $f0
.L7F05E7E8:
  nop   
  bc1fl .L7F05E7FC
   lw    $ra, 0x14($sp)
  swc1  $f0, 0xa84($v0)
.L7F05E7F8:
  lw    $ra, 0x14($sp)
.L7F05E7FC:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F05E808
  sll   $t8, $a0, 3
  subu  $t8, $t8, $a0
  sll   $t8, $t8, 2
  addu  $t8, $t8, $a0
  lui   $t7, %hi(pPlayer) 
  lw    $t7, %lo(pPlayer)($t7)
  sll   $t8, $t8, 2
  addu  $t8, $t8, $a0
  sll   $t8, $t8, 3
  li    $t6, 1
  addu  $t9, $t7, $t8
  jr    $ra
   sw    $t6, 0xa8c($t9)
");

asm(R"
.late_rodata
glabel D_80053C88
.word 0x3e2aaaab /*0.16666667*/
.text
glabel sub_GAME_7F05E83C
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   return_ammo_in_hand
   sw    $a0, 0x18($sp)
  jal   get_ptr_item_statistics
   move  $a0, $v0
  lw    $a0, 0x18($sp)
  lui   $a1, %hi(pPlayer)
  addiu $a1, %lo(pPlayer) # addiu $a1, $a1, -0x5f50
  sll   $t6, $a0, 3
  subu  $t6, $t6, $a0
  sll   $t6, $t6, 2
  addu  $t6, $t6, $a0
  lw    $t7, ($a1)
  sll   $t6, $t6, 2
  addu  $t6, $t6, $a0
  sll   $t6, $t6, 3
  addu  $v1, $t7, $t6
  lw    $t8, 0xa8c($v1)
  lwc1  $f2, 0x50($v0)
  move  $a0, $t6
  beql  $t8, $zero, .L7F05E904
   lw    $t2, 0x89c($v1)
  lwc1  $f0, 0xa88($v1)
  li    $at, 0x3E800000 # 0.250000
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F05E8E0
   c.le.s $f2, $f0
  mtc1  $at, $f4
  lui   $at, %hi(global_timer_delta)
  lwc1  $f8, %lo(global_timer_delta)($at)
  mul.s $f6, $f2, $f4
  nop   
  mul.s $f10, $f6, $f8
  add.s $f16, $f0, $f10
  swc1  $f16, 0xa88($v1)
  lw    $t9, ($a1)
  addu  $v1, $t9, $t6
  lwc1  $f0, 0xa88($v1)
  c.le.s $f2, $f0
.L7F05E8E0:
  nop   
  bc1fl .L7F05E96C
   lw    $ra, 0x14($sp)
  swc1  $f2, 0xa88($v1)
  lw    $t0, ($a1)
  addu  $t1, $t0, $a0
  b     .L7F05E968
   sw    $zero, 0xa8c($t1)
  lw    $t2, 0x89c($v1)
.L7F05E904:
  blezl $t2, .L7F05E96C
   lw    $ra, 0x14($sp)
  mtc1  $zero, $f12
  lwc1  $f0, 0xa88($v1)
  lui   $at, %hi(D_80053C88)
  c.lt.s $f12, $f0
  nop   
  bc1fl .L7F05E958
   c.lt.s $f0, $f12
  lwc1  $f18, %lo(D_80053C88)($at)
  lui   $at, %hi(global_timer_delta)
  lwc1  $f6, %lo(global_timer_delta)($at)
  mul.s $f4, $f2, $f18
  lui   $t3, %hi(pPlayer) 
  mul.s $f8, $f4, $f6
  sub.s $f10, $f0, $f8
  swc1  $f10, 0xa88($v1)
  lw    $t3, %lo(pPlayer)($t3)
  addu  $v1, $t3, $a0
  lwc1  $f0, 0xa88($v1)
  c.lt.s $f0, $f12
.L7F05E958:
  nop   
  bc1fl .L7F05E96C
   lw    $ra, 0x14($sp)
  swc1  $f12, 0xa88($v1)
.L7F05E968:
  lw    $ra, 0x14($sp)
.L7F05E96C:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F05E978
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  lw    $v1, 8($a0)
  move  $s0, $a0
  move  $s1, $a1
  lw    $a2, 8($v1)
  lw    $a3, 0x20($a2)
  beql  $a3, $zero, .L7F05E9BC
   lw    $a1, 0x24($a2)
  jal   extract_id_from_object_structure_microcode
   move  $a1, $a3
  sw    $s1, ($v0)
  lw    $v1, 8($s0)
  lw    $a2, 8($v1)
  lw    $a1, 0x24($a2)
.L7F05E9BC:
  beql  $a1, $zero, .L7F05E9DC
   lw    $a1, 0x28($a2)
  jal   extract_id_from_object_structure_microcode
   move  $a0, $s0
  sw    $s1, ($v0)
  lw    $v1, 8($s0)
  lw    $a2, 8($v1)
  lw    $a1, 0x28($a2)
.L7F05E9DC:
  beql  $a1, $zero, .L7F05E9FC
   lw    $a1, 0x2c($a2)
  jal   extract_id_from_object_structure_microcode
   move  $a0, $s0
  sw    $s1, ($v0)
  lw    $v1, 8($s0)
  lw    $a2, 8($v1)
  lw    $a1, 0x2c($a2)
.L7F05E9FC:
  beql  $a1, $zero, .L7F05EA1C
   lw    $a1, 0x30($a2)
  jal   extract_id_from_object_structure_microcode
   move  $a0, $s0
  sw    $s1, ($v0)
  lw    $v1, 8($s0)
  lw    $a2, 8($v1)
  lw    $a1, 0x30($a2)
.L7F05EA1C:
  beql  $a1, $zero, .L7F05EA3C
   lw    $a1, 0x34($a2)
  jal   extract_id_from_object_structure_microcode
   move  $a0, $s0
  sw    $s1, ($v0)
  lw    $v1, 8($s0)
  lw    $a2, 8($v1)
  lw    $a1, 0x34($a2)
.L7F05EA3C:
  beql  $a1, $zero, .L7F05EA58
   lh    $t6, 0xc($v1)
  jal   extract_id_from_object_structure_microcode
   move  $a0, $s0
  sw    $s1, ($v0)
  lw    $v1, 8($s0)
  lh    $t6, 0xc($v1)
.L7F05EA58:
  slti  $at, $t6, 0x24
  bnezl $at, .L7F05EA84
   lw    $ra, 0x1c($sp)
  lw    $t7, 8($v1)
  lw    $a1, 0x8c($t7)
  beql  $a1, $zero, .L7F05EA84
   lw    $ra, 0x1c($sp)
  jal   extract_id_from_object_structure_microcode
   move  $a0, $s0
  sw    $s1, ($v0)
  lw    $ra, 0x1c($sp)
.L7F05EA84:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x20
");

asm(R"
glabel sub_GAME_7F05EA94
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a1, 0x1c($sp)
  lw    $v0, 8($a0)
  lh    $t6, 0xc($v0)
  slti  $at, $t6, 0x10
  bnezl $at, .L7F05EB00
   lw    $ra, 0x14($sp)
  lw    $v1, 8($v0)
  lw    $a1, 0x38($v1)
  beql  $a1, $zero, .L7F05EAE4
   lw    $a1, 0x3c($v1)
  jal   extract_id_from_object_structure_microcode
   sw    $a0, 0x18($sp)
  lw    $t7, 0x1c($sp)
  lw    $a0, 0x18($sp)
  sw    $t7, ($v0)
  lw    $t8, 8($a0)
  lw    $v1, 8($t8)
  lw    $a1, 0x3c($v1)
.L7F05EAE4:
  beql  $a1, $zero, .L7F05EB00
   lw    $ra, 0x14($sp)
  jal   extract_id_from_object_structure_microcode
   nop   
  lw    $t9, 0x1c($sp)
  sw    $t9, ($v0)
  lw    $ra, 0x14($sp)
.L7F05EB00:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F05EB0C
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  sw    $a1, 0x24($sp)
  sw    $a2, 0x28($sp)
  sw    $a3, 0x2c($sp)
  lw    $s1, 0x10($a0)
  move  $s0, $a0
  beql  $s1, $zero, .L7F05EC0C
   lw    $ra, 0x1c($sp)
  jal   set_current_objposdata_plus_0x28
   move  $a0, $s1
  jal   set_stateflag_0x04_for_posdata
   move  $a0, $s1
  lw    $t6, 0x14($s0)
  lw    $a1, 0x2c($sp)
  jal   matrix_multiply_A1_by_F12
   lwc1  $f12, 0x14($t6)
  move  $a0, $s0
  lw    $a1, 0x24($sp)
  lw    $a2, 0x2c($sp)
  jal   sub_GAME_7F040754
   lw    $a3, 0x28($sp)
  jal   sub_GAME_7F056CA0
   move  $a0, $s0
  jal   sub_GAME_7F040484
   move  $a0, $s0
  jal   sub_GAME_7F03FDA8
   move  $a0, $s1
  lw    $t7, 0x64($s0)
  andi  $t8, $t7, 0x80
  beql  $t8, $zero, .L7F05EC0C
   lw    $ra, 0x1c($sp)
  lw    $v0, 0x6c($s0)
  move  $a0, $s1
  lw    $t9, ($v0)
  ori   $t0, $t9, 0x41
  sw    $t0, ($v0)
  lw    $t2, 0x6c($s0)
  lw    $t1, 0x38($sp)
  jal   sub_GAME_7F03FE14
   sw    $t1, 0x88($t2)
  lw    $a1, 0x6c($s0)
  lw    $a0, 0x34($sp)
  jal   matrix_4x4_copy
   addiu $a1, $a1, 0x20
  lw    $v0, 0x30($sp)
  lw    $t3, 0x6c($s0)
  lui   $t7, %hi(D_80048380) 
  lwc1  $f4, ($v0)
  swc1  $f4, 4($t3)
  lw    $t4, 0x6c($s0)
  lwc1  $f6, 4($v0)
  swc1  $f6, 8($t4)
  lw    $t5, 0x6c($s0)
  lwc1  $f8, 8($v0)
  swc1  $f8, 0xc($t5)
  lw    $t6, 0x6c($s0)
  sw    $s0, 0xe4($t6)
  lw    $t8, 0x6c($s0)
  lw    $t7, %lo(D_80048380)($t7)
  sw    $t7, 0xe8($t8)
  lw    $ra, 0x1c($sp)
.L7F05EC0C:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x20
");

asm(R"
glabel sub_GAME_7F05EC1C
  addiu $sp, $sp, -0xd8
  sw    $ra, 0x3c($sp)
  sw    $s2, 0x38($sp)
  sw    $s1, 0x34($sp)
  sw    $s0, 0x30($sp)
  sw    $a2, 0xe0($sp)
  sw    $a3, 0xe4($sp)
  lw    $v0, 0x10($a0)
  move  $s1, $a1
  move  $s2, $a0
  beql  $v0, $zero, .L7F05EE10
   lw    $ra, 0x3c($sp)
  jal   get_curplayer_positiondata
   nop   
  lui   $a0, %hi(pPlayer)
  move  $s0, $v0
  jal   sub_GAME_7F089778
   lw    $a0, %lo(pPlayer)($a0)
  sw    $zero, 0xb0($sp)
  lwc1  $f12, 0xc($s0)
  lwc1  $f2, 4($s1)
  move  $a0, $s0
  move  $a1, $zero
  c.lt.s $f2, $f12
  nop   
  bc1fl .L7F05EC98
   sub.s $f14, $f2, $f0
  sub.s $f14, $f12, $f0
  b     .L7F05EC9C
   sub.s $f16, $f2, $f0
  sub.s $f14, $f2, $f0
.L7F05EC98:
  sub.s $f16, $f12, $f0
.L7F05EC9C:
  lw    $t6, 0x14($s0)
  swc1  $f16, 0xb4($sp)
  swc1  $f14, 0xb8($sp)
  jal   sub_GAME_7F08A03C
   sw    $t6, 0xc4($sp)
  lwc1  $f4, 8($s1)
  lw    $a1, 8($s0)
  lw    $a2, 0x10($s0)
  lw    $a3, ($s1)
  li    $at, 0x3F800000 # 1.000000
  lwc1  $f14, 0xb8($sp)
  lwc1  $f16, 0xb4($sp)
  mtc1  $at, $f8
  mtc1  $zero, $f6
  li    $t7, 31
  sw    $t7, 0x14($sp)
  addiu $a0, $sp, 0xc4
  swc1  $f4, 0x10($sp)
  swc1  $f14, 0x18($sp)
  swc1  $f16, 0x1c($sp)
  swc1  $f8, 0x24($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f6, 0x20($sp)
  beqz  $v0, .L7F05ED1C
   move  $a0, $s0
  lwc1  $f10, ($s1)
  swc1  $f10, 0xc8($sp)
  lwc1  $f18, 4($s1)
  swc1  $f18, 0xcc($sp)
  lwc1  $f4, 8($s1)
  b     .L7F05ED44
   swc1  $f4, 0xd0($sp)
.L7F05ED1C:
  lw    $t8, 0x14($s0)
  li    $t9, 1
  sw    $t8, 0xc4($sp)
  lwc1  $f6, 8($s0)
  swc1  $f6, 0xc8($sp)
  lwc1  $f8, 0xc($s0)
  swc1  $f8, 0xcc($sp)
  lwc1  $f10, 0x10($s0)
  sw    $t9, 0xb0($sp)
  swc1  $f10, 0xd0($sp)
.L7F05ED44:
  jal   sub_GAME_7F08A03C
   li    $a1, 1
  lw    $t0, 0xe4($sp)
  lw    $t1, 0xe8($sp)
  move  $a0, $s2
  addiu $a1, $sp, 0xc8
  lw    $a2, 0xc4($sp)
  lw    $a3, 0xe0($sp)
  sw    $s0, 0x18($sp)
  sw    $t0, 0x10($sp)
  jal   sub_GAME_7F05EB0C
   sw    $t1, 0x14($sp)
  lw    $t2, 0x64($s2)
  lw    $t4, 0xb0($sp)
  andi  $t3, $t2, 0x80
  beql  $t3, $zero, .L7F05EE10
   lw    $ra, 0x3c($sp)
  beqz  $t4, .L7F05EDC4
   nop   
  lw    $v0, 0x6c($s2)
  lw    $t5, ($v0)
  ori   $t6, $t5, 0x100
  sw    $t6, ($v0)
  lw    $t7, 0x6c($s2)
  lwc1  $f18, ($s1)
  swc1  $f18, 0xd4($t7)
  lw    $t8, 0x6c($s2)
  lwc1  $f4, 4($s1)
  swc1  $f4, 0xd8($t8)
  lw    $t9, 0x6c($s2)
  lwc1  $f6, 8($s1)
  swc1  $f6, 0xdc($t9)
.L7F05EDC4:
  jal   get_cur_players_room
   nop   
  li    $t0, 255
  sb    $v0, 0xa8($sp)
  jal   get_BONDdata_position3
   sb    $t0, 0xa9($sp)
  lw    $a3, 0x6c($s2)
  addiu $t1, $sp, 0x54
  addiu $t2, $sp, 0x50
  li    $t3, 20
  sw    $t3, 0x18($sp)
  sw    $t2, 0x14($sp)
  sw    $t1, 0x10($sp)
  move  $a0, $v0
  addiu $a1, $sp, 0xc8
  addiu $a2, $sp, 0xa8
  jal   sub_GAME_7F0B4AB4
   addiu $a3, $a3, 0xcc
  lw    $ra, 0x3c($sp)
.L7F05EE10:
  lw    $s0, 0x30($sp)
  lw    $s1, 0x34($sp)
  lw    $s2, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0xd8
");

asm(R"
.late_rodata
glabel D_80053C8C
.word 0x41855555 /*16.666666*/
glabel D_80053C90
.word 0x3e99999a /*0.30000001*/
glabel D_80053C94
.word 0x3e088888 /*0.13333333*/
.text
glabel sub_GAME_7F05EE24
  addiu $sp, $sp, -0x140
  sw    $ra, 0x24($sp)
  sw    $s0, 0x20($sp)
  jal   get_curplayer_positiondata
   sw    $a0, 0x140($sp)
  jal   get_BONDdata_field408
   move  $s0, $v0
  sw    $v0, 0x80($sp)
  jal   get_item_in_hand
   lw    $a0, 0x140($sp)
  sw    $v0, 0x38($sp)
  addiu $a0, $sp, 0xf0
  jal   sub_GAME_7F057C14
   addiu $a1, $sp, 0xfc
  addiu $a0, $sp, 0x94
  addiu $a1, $sp, 0x88
  jal   sub_GAME_7F0681CC
   lw    $a2, 0x140($sp)
  jal   sub_GAME_7F078444
   nop   
  move  $a0, $v0
  jal   sub_GAME_7F0583D8
   addiu $a1, $sp, 0x88
  lui   $at, %hi(D_80053C8C)
  lwc1  $f0, %lo(D_80053C8C)($at)
  lwc1  $f4, 0x88($sp)
  lwc1  $f8, 0x8c($sp)
  li    $at, 0x40A00000 # 5.000000
  mul.s $f6, $f4, $f0
  lwc1  $f4, 0x90($sp)
  mtc1  $at, $f16
  mul.s $f10, $f8, $f0
  lui   $t6, %hi(clock_timer) 
  lw    $t6, %lo(clock_timer)($t6)
  mul.s $f8, $f4, $f0
  swc1  $f6, 0xf0($sp)
  lw    $v0, 0x80($sp)
  add.s $f18, $f10, $f16
  swc1  $f8, 0xf8($sp)
  blez  $t6, .L7F05EF18
   swc1  $f18, 0xf4($sp)
  lwc1  $f10, 8($s0)
  lwc1  $f16, ($v0)
  lui   $at, %hi(global_timer_delta)
  lwc1  $f0, %lo(global_timer_delta)($at)
  sub.s $f4, $f10, $f16
  div.s $f10, $f4, $f0
  add.s $f16, $f6, $f10
  swc1  $f16, 0xf0($sp)
  lwc1  $f6, 4($v0)
  lwc1  $f4, 0xc($s0)
  sub.s $f10, $f4, $f6
  div.s $f16, $f10, $f0
  add.s $f4, $f18, $f16
  swc1  $f4, 0xf4($sp)
  lwc1  $f10, 8($v0)
  lwc1  $f6, 0x10($s0)
  sub.s $f18, $f6, $f10
  div.s $f16, $f18, $f0
  add.s $f4, $f8, $f16
  swc1  $f4, 0xf8($sp)
.L7F05EF18:
  lw    $s0, 0x140($sp)
  lui   $t8, %hi(pPlayer) 
  lw    $t8, %lo(pPlayer)($t8)
  sll   $t7, $s0, 3
  subu  $t7, $t7, $s0
  sll   $t7, $t7, 2
  addu  $t7, $t7, $s0
  sll   $t7, $t7, 2
  addu  $t7, $t7, $s0
  sll   $s0, $t7, 3
  addu  $v0, $t8, $s0
  lwc1  $f6, 0xb08($v0)
  addiu $a0, $sp, 0xa0
  swc1  $f6, 0xe0($sp)
  lwc1  $f10, 0xb0c($v0)
  swc1  $f10, 0xe4($sp)
  lwc1  $f18, 0xb10($v0)
  jal   matrix_4x4_set_identity
   swc1  $f18, 0xe8($sp)
  lui   $t9, %hi(pPlayer) 
  lw    $t9, %lo(pPlayer)($t9)
  addiu $a1, $sp, 0x40
  addu  $a0, $t9, $s0
  jal   matrix_4x4_copy
   addiu $a0, $a0, 0xad8
  mtc1  $zero, $f0
  addiu $a0, $sp, 0x40
  addiu $a1, $sp, 0xa0
  swc1  $f0, 0x70($sp)
  swc1  $f0, 0x74($sp)
  jal   matrix_4x4_multiply_in_place
   swc1  $f0, 0x78($sp)
  li    $a0, 196
  jal   create_new_item_instance_of_model
   lw    $a1, 0x38($sp)
  beqz  $v0, .L7F05F088
   move  $s0, $v0
  lui   $t0, %hi(pPlayer) 
  lw    $t0, %lo(pPlayer)($t0)
  li    $t2, 240
  lw    $t1, 0x105c($t0)
  subu  $t3, $t2, $t1
  sh    $t3, 0x82($v0)
  lh    $t4, 0x82($v0)
  bgezl $t4, .L7F05EFD8
   lw    $t5, 0x64($s0)
  sh    $zero, 0x82($v0)
  lw    $t5, 0x64($s0)
.L7F05EFD8:
  lui   $at, (0xFFF9FFFF >> 16) # lui $at, 0xfff9
  ori   $at, (0xFFF9FFFF & 0xFFFF) # ori $at, $at, 0xffff
  and   $t6, $t5, $at
  jal   get_cur_playernum
   sw    $t6, 0x64($s0)
  lw    $t7, 0x64($s0)
  sll   $t8, $v0, 0x11
  addiu $t0, $sp, 0xfc
  or    $t9, $t7, $t8
  sw    $t9, 0x64($s0)
  sw    $t0, 0x10($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0xe0
  addiu $a2, $sp, 0xa0
  jal   sub_GAME_7F05EC1C
   addiu $a3, $sp, 0xf0
  lw    $t2, 0x64($s0)
  andi  $t1, $t2, 0x80
  beql  $t1, $zero, .L7F05F08C
   lw    $ra, 0x24($sp)
  lw    $v0, 0x6c($s0)
  lui   $at, %hi(D_80053C90)
  li    $t7, 60
  lw    $t3, ($v0)
  lui   $a0, %hi(ptr_sfx_buf)
  li    $a1, 4
  ori   $t4, $t3, 2
  sw    $t4, ($v0)
  lw    $t5, 0x6c($s0)
  lwc1  $f8, %lo(D_80053C90)($at)
  lui   $at, %hi(D_80053C94)
  move  $a2, $zero
  swc1  $f8, 0x8c($t5)
  lw    $t6, 0x6c($s0)
  lwc1  $f16, %lo(D_80053C94)($at)
  swc1  $f16, 0x94($t6)
  lw    $t8, 0x6c($s0)
  sw    $t7, 0xbc($t8)
  jal   play_sfx_a1
   lw    $a0, %lo(ptr_sfx_buf)($a0)
  beqz  $v0, .L7F05F088
   move  $a0, $v0
  jal   sub_GAME_7F053A10
   addiu $a1, $s0, 0x58
.L7F05F088:
  lw    $ra, 0x24($sp)
.L7F05F08C:
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0x140
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80053C98
.word 0x4096cbe4 /*4.712389*/
glabel D_80053C9C
.word 0x40490fdb /*3.1415927*/
glabel D_80053CA0
.word 0x4141999a /*12.1*/
glabel D_80053CA4
.word 0x3dcccccd /*0.1*/
.text
glabel sub_GAME_7F05F09C
  addiu $sp, $sp, -0x130
  sw    $ra, 0x1c($sp)
  jal   get_curplayer_positiondata
   sw    $a0, 0x130($sp)
  jal   get_BONDdata_field408
   sw    $v0, 0x34($sp)
  sw    $v0, 0x30($sp)
  addiu $a0, $sp, 0xe0
  jal   sub_GAME_7F057C14
   addiu $a1, $sp, 0xec
  addiu $a0, $sp, 0x84
  addiu $a1, $sp, 0x78
  jal   sub_GAME_7F0681CC
   lw    $a2, 0x130($sp)
  jal   sub_GAME_7F078444
   nop   
  move  $a0, $v0
  jal   sub_GAME_7F0583D8
   addiu $a1, $sp, 0x78
  li    $at, 0x41C80000 # 25.000000
  mtc1  $at, $f0
  lwc1  $f4, 0x78($sp)
  lwc1  $f8, 0x7c($sp)
  li    $at, 0x40A00000 # 5.000000
  mul.s $f6, $f4, $f0
  lwc1  $f4, 0x80($sp)
  mtc1  $at, $f16
  mul.s $f10, $f8, $f0
  lui   $t6, %hi(clock_timer) 
  lw    $t6, %lo(clock_timer)($t6)
  mul.s $f8, $f4, $f0
  swc1  $f6, 0xe0($sp)
  add.s $f18, $f10, $f16
  swc1  $f8, 0xe8($sp)
  blez  $t6, .L7F05F184
   swc1  $f18, 0xe4($sp)
  lw    $v0, 0x30($sp)
  lw    $v1, 0x34($sp)
  lui   $at, %hi(global_timer_delta)
  lwc1  $f16, ($v0)
  lwc1  $f10, 8($v1)
  lwc1  $f0, %lo(global_timer_delta)($at)
  sub.s $f4, $f10, $f16
  div.s $f10, $f4, $f0
  add.s $f16, $f6, $f10
  swc1  $f16, 0xe0($sp)
  lwc1  $f6, 4($v0)
  lwc1  $f4, 0xc($v1)
  sub.s $f10, $f4, $f6
  div.s $f16, $f10, $f0
  add.s $f4, $f18, $f16
  swc1  $f4, 0xe4($sp)
  lwc1  $f10, 8($v0)
  lwc1  $f6, 0x10($v1)
  sub.s $f18, $f6, $f10
  div.s $f16, $f18, $f0
  add.s $f4, $f8, $f16
  swc1  $f4, 0xe8($sp)
.L7F05F184:
  lw    $v1, 0x130($sp)
  lui   $t8, %hi(pPlayer) 
  lw    $t8, %lo(pPlayer)($t8)
  sll   $t7, $v1, 3
  subu  $t7, $t7, $v1
  sll   $t7, $t7, 2
  addu  $t7, $t7, $v1
  sll   $t7, $t7, 2
  addu  $t7, $t7, $v1
  sll   $t7, $t7, 3
  addu  $v0, $t8, $t7
  lwc1  $f6, 0xb08($v0)
  lui   $at, %hi(D_80053C98)
  lwc1  $f12, %lo(D_80053C98)($at)
  swc1  $f6, 0xd0($sp)
  lwc1  $f10, 0xb0c($v0)
  addiu $a1, $sp, 0x90
  swc1  $f10, 0xd4($sp)
  lwc1  $f18, 0xb10($v0)
  sw    $t7, 0x28($sp)
  jal   sub_GAME_7F058688
   swc1  $f18, 0xd8($sp)
  lui   $at, %hi(D_80053C9C)
  lwc1  $f12, %lo(D_80053C9C)($at)
  jal   sub_GAME_7F058570
   addiu $a1, $sp, 0x38
  addiu $a0, $sp, 0x38
  jal   matrix_4x4_multiply_in_place
   addiu $a1, $sp, 0x90
  lui   $t9, %hi(pPlayer) 
  lw    $t9, %lo(pPlayer)($t9)
  lw    $t0, 0x28($sp)
  addiu $a1, $sp, 0x38
  addu  $a0, $t9, $t0
  jal   matrix_4x4_copy
   addiu $a0, $a0, 0xad8
  mtc1  $zero, $f0
  addiu $a0, $sp, 0x38
  addiu $a1, $sp, 0x90
  swc1  $f0, 0x68($sp)
  swc1  $f0, 0x6c($sp)
  jal   matrix_4x4_multiply_in_place
   swc1  $f0, 0x70($sp)
  jal   get_random_value
   nop   
  mtc1  $v0, $f8
  addiu $a0, $sp, 0xec
  bgez  $v0, .L7F05F258
   cvt.s.w $f16, $f8
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f4
  nop   
  add.s $f16, $f16, $f4
.L7F05F258:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f6
  lui   $at, %hi(D_80053CA0)
  lwc1  $f18, %lo(D_80053CA0)($at)
  mul.s $f10, $f16, $f6
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f4
  lwc1  $f6, 0xa8($sp)
  lw    $a2, 0xa0($sp)
  lw    $a3, 0xa4($sp)
  swc1  $f6, 0x10($sp)
  add.s $f8, $f10, $f18
  div.s $f16, $f4, $f8
  mfc1  $a1, $f16
  jal   guRotateF
   nop   
  li    $a0, 186
  jal   create_new_item_instance_of_model
   li    $a1, 3
  beql  $v0, $zero, .L7F05F34C
   lw    $ra, 0x1c($sp)
  lw    $t1, 0x64($v0)
  lui   $at, (0xFFF9FFFF >> 16) # lui $at, 0xfff9
  ori   $at, (0xFFF9FFFF & 0xFFFF) # ori $at, $at, 0xffff
  and   $t2, $t1, $at
  sw    $t2, 0x64($v0)
  jal   get_cur_playernum
   sw    $v0, 0x12c($sp)
  lw    $a0, 0x12c($sp)
  sll   $t4, $v0, 0x11
  addiu $t6, $sp, 0xec
  lw    $t3, 0x64($a0)
  addiu $a1, $sp, 0xd0
  addiu $a2, $sp, 0x90
  or    $t5, $t3, $t4
  sw    $t5, 0x64($a0)
  sw    $t6, 0x10($sp)
  jal   sub_GAME_7F05EC1C
   addiu $a3, $sp, 0xe0
  lw    $a0, 0x12c($sp)
  lw    $t7, 0x64($a0)
  andi  $t8, $t7, 0x80
  beqz  $t8, .L7F05F340
   nop   
  lw    $v0, 0x6c($a0)
  lui   $at, %hi(D_80053CA4)
  li    $t2, 60
  lw    $t9, ($v0)
  ori   $t0, $t9, 2
  sw    $t0, ($v0)
  lw    $t1, 0x6c($a0)
  lwc1  $f10, %lo(D_80053CA4)($at)
  swc1  $f10, 0x8c($t1)
  lw    $t3, 0x6c($a0)
  sw    $t2, 0xbc($t3)
  lw    $t4, 0x64($a0)
  ori   $t5, $t4, 0x20
  sw    $t5, 0x64($a0)
.L7F05F340:
  jal   sub_GAME_7F043650
   nop   
  lw    $ra, 0x1c($sp)
.L7F05F34C:
  addiu $sp, $sp, 0x130
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80053CA8
.word 0x41855555 /*16.666666*/
glabel D_80053CAC
.word 0x40d55555 /*6.6666665*/
/*D:80053CB0*/
glabel jpt_player_thrown_object
.word thrown_item_timed_mine
.word thrown_item_proximity_mine
.word create_instance
.word create_instance
.word create_instance
.word create_instance
.word thrown_item_bombcase
.word thrown_item_plastique
.word create_instance
.word create_instance
.word create_instance
.word create_instance
.word create_instance
.word create_instance
.word create_instance
.word create_instance
.word create_instance
.word create_instance
.word create_instance
.word create_instance
.word thrown_item_bug
.word thrown_item_micro_camera
.word create_instance
.word create_instance
.word create_instance
.word create_instance
.word create_instance
.word create_instance
.word create_instance
.word create_instance
.word create_instance
.word create_instance
.word create_instance
.word create_instance
.word thrown_item_GE_key

/*D:80053D3C*/
glabel jpt_temp_obj_for_itemtype
.word generate_temp_timed_mine
.word generate_temp_proximity_mine
.word generate_temp_remote_mine
.word generate_temp_default
.word generate_temp_default
.word generate_temp_default
.word generate_temp_bombcase
.word generate_temp_static_thrown
.word generate_temp_default
.word generate_temp_default
.word generate_temp_default
.word generate_temp_default
.word generate_temp_default
.word generate_temp_default
.word generate_temp_default
.word generate_temp_default
.word generate_temp_default
.word generate_temp_default
.word generate_temp_default
.word generate_temp_default
.word generate_temp_static_thrown
.word generate_temp_static_thrown
.word generate_temp_default
.word generate_temp_default
.word generate_temp_default
.word generate_temp_default
.word generate_temp_default
.word generate_temp_default
.word generate_temp_default
.word generate_temp_default
.word generate_temp_default
.word generate_temp_default
.word generate_temp_default
.word generate_temp_default
.word generate_temp_static_thrown

glabel D_80053DC8
.word 0x3dcccccd /*0.1*/
.text
glabel generate_player_thrown_object
  addiu $sp, $sp, -0x140
  lui   $at, %hi(D_80053CA8)
  lwc1  $f4, %lo(D_80053CA8)($at)
  sw    $ra, 0x24($sp)
  sw    $s0, 0x20($sp)
  sw    $a0, 0x140($sp)
  move  $s0, $zero
  jal   get_curplayer_positiondata
   swc1  $f4, 0xec($sp)
  jal   get_BONDdata_field408
   sw    $v0, 0x84($sp)
  sw    $v0, 0x80($sp)
  jal   get_item_in_hand
   lw    $a0, 0x140($sp)
  li    $at, 61
  bne   $v0, $at, .L7F05F3A8
   sw    $v0, 0x38($sp)
  lui   $at, %hi(D_80053CAC)
  lwc1  $f6, %lo(D_80053CAC)($at)
  swc1  $f6, 0xec($sp)
.L7F05F3A8:
  addiu $a0, $sp, 0xf0
  jal   sub_GAME_7F057C14
   addiu $a1, $sp, 0xfc
  addiu $a0, $sp, 0x94
  addiu $a1, $sp, 0x88
  jal   sub_GAME_7F0681CC
   lw    $a2, 0x140($sp)
  jal   sub_GAME_7F078444
   nop   
  move  $a0, $v0
  jal   sub_GAME_7F0583D8
   addiu $a1, $sp, 0x88
  lwc1  $f0, 0xec($sp)
  lwc1  $f8, 0x88($sp)
  lwc1  $f16, 0x8c($sp)
  li    $at, 0x40A00000 # 5.000000
  mul.s $f10, $f8, $f0
  lwc1  $f8, 0x90($sp)
  mtc1  $at, $f4
  mul.s $f18, $f16, $f0
  lui   $t6, %hi(clock_timer) 
  lw    $t6, %lo(clock_timer)($t6)
  mul.s $f16, $f8, $f0
  swc1  $f10, 0xf0($sp)
  lw    $v0, 0x80($sp)
  lw    $v1, 0x84($sp)
  add.s $f6, $f18, $f4
  swc1  $f16, 0xf8($sp)
  blez  $t6, .L7F05F470
   swc1  $f6, 0xf4($sp)
  lwc1  $f18, 8($v1)
  lwc1  $f4, ($v0)
  lui   $at, %hi(global_timer_delta)
  lwc1  $f0, %lo(global_timer_delta)($at)
  sub.s $f8, $f18, $f4
  div.s $f18, $f8, $f0
  add.s $f4, $f10, $f18
  swc1  $f4, 0xf0($sp)
  lwc1  $f10, 4($v0)
  lwc1  $f8, 0xc($v1)
  sub.s $f18, $f8, $f10
  div.s $f4, $f18, $f0
  add.s $f8, $f6, $f4
  swc1  $f8, 0xf4($sp)
  lwc1  $f18, 8($v0)
  lwc1  $f10, 0x10($v1)
  sub.s $f6, $f10, $f18
  div.s $f4, $f6, $f0
  add.s $f8, $f16, $f4
  swc1  $f8, 0xf8($sp)
.L7F05F470:
  lw    $v1, 0x140($sp)
  lui   $t8, %hi(pPlayer) 
  lw    $t8, %lo(pPlayer)($t8)
  sll   $t7, $v1, 3
  subu  $t7, $t7, $v1
  sll   $t7, $t7, 2
  addu  $t7, $t7, $v1
  sll   $t7, $t7, 2
  addu  $t7, $t7, $v1
  sll   $t7, $t7, 3
  addu  $v0, $t8, $t7
  lwc1  $f10, 0xb08($v0)
  addiu $a0, $sp, 0xa0
  swc1  $f10, 0xe0($sp)
  lwc1  $f18, 0xb0c($v0)
  swc1  $f18, 0xe4($sp)
  lwc1  $f6, 0xb10($v0)
  sw    $t7, 0x2c($sp)
  jal   matrix_4x4_set_identity
   swc1  $f6, 0xe8($sp)
  lui   $t9, %hi(pPlayer) 
  lw    $v1, 0x2c($sp)
  lw    $t9, %lo(pPlayer)($t9)
  addiu $a1, $sp, 0x40
  addu  $a0, $t9, $v1
  jal   matrix_4x4_copy
   addiu $a0, $a0, 0xad8
  mtc1  $zero, $f0
  addiu $a0, $sp, 0x40
  addiu $a1, $sp, 0xa0
  swc1  $f0, 0x70($sp)
  swc1  $f0, 0x74($sp)
  jal   matrix_4x4_multiply_in_place
   swc1  $f0, 0x78($sp)
  lw    $a1, 0x38($sp)
  li    $at, 61
  bne   $a1, $at, .L7F05F538
   nop   
  jal   sub_GAME_7F08C570
   move  $a0, $a1
  move  $s0, $v0
  jal   sub_GAME_7F08C61C
   lw    $a0, 0x38($sp)
  beqz  $s0, .L7F05F52C
   nop   
  jal   sub_GAME_7F04C044
   lw    $a0, 0x10($s0)
.L7F05F52C:
  jal   sub_GAME_7F05D690
   nop   
  lw    $a1, 0x38($sp)
.L7F05F538:
  bnez  $s0, .L7F05F5A8
   addiu $t0, $a1, -0x1b
  sltiu $at, $t0, 0x23
  beqz  $at, .L7F05F598
   li    $a0, 199
  sll   $t0, $t0, 2
  lui   $at, %hi(jpt_player_thrown_object)
  addu  $at, $at, $t0
  lw    $t0, %lo(jpt_player_thrown_object)($at)
  jr    $t0
   nop   
thrown_item_proximity_mine:
  b     .L7F05F598
   li    $a0, 200
thrown_item_timed_mine:
  b     .L7F05F598
   li    $a0, 201
thrown_item_bombcase:
  b     .L7F05F598
   li    $a0, 226
thrown_item_bug:
  b     .L7F05F598
   li    $a0, 245
thrown_item_micro_camera:
  b     .L7F05F598
   li    $a0, 246
thrown_item_GE_key:
  b     .L7F05F598
   li    $a0, 248
thrown_item_plastique:
  li    $a0, 273
create_instance:
.L7F05F598:
  jal   create_new_item_instance_of_model
   nop   
  move  $s0, $v0
  lw    $a1, 0x38($sp)
.L7F05F5A8:
  beqz  $s0, .L7F05F728
   addiu $t1, $a1, -0x1b
  sltiu $at, $t1, 0x23
  beqz  $at, .L7F05F67C
   sll   $t1, $t1, 2
  lui   $at, %hi(jpt_temp_obj_for_itemtype)
  addu  $at, $at, $t1
  lw    $t1, %lo(jpt_temp_obj_for_itemtype)($at)
  jr    $t1
   nop   
generate_temp_remote_mine:
  jal   getPlayerCount
   nop   
  li    $at, 1
  bne   $v0, $at, .L7F05F5F0
   li    $t3, 180
  li    $t2, 300
  b     .L7F05F684
   sh    $t2, 0x82($s0)
.L7F05F5F0:
  b     .L7F05F684
   sh    $t3, 0x82($s0)
generate_temp_proximity_mine:
  jal   getPlayerCount
   nop   
  li    $at, 1
  bne   $v0, $at, .L7F05F618
   li    $t5, 180
  li    $t4, 300
  b     .L7F05F684
   sh    $t4, 0x82($s0)
.L7F05F618:
  b     .L7F05F684
   sh    $t5, 0x82($s0)
generate_temp_timed_mine:
  jal   getPlayerCount
   nop   
  li    $at, 1
  bne   $v0, $at, .L7F05F640
   li    $t7, 180
  li    $t6, 300
  b     .L7F05F684
   sh    $t6, 0x82($s0)
.L7F05F640:
  b     .L7F05F684
   sh    $t7, 0x82($s0)
generate_temp_bombcase:
  jal   getPlayerCount
   nop   
  li    $at, 1
  bne   $v0, $at, .L7F05F668
   li    $t9, 180
  li    $t8, 300
  b     .L7F05F684
   sh    $t8, 0x82($s0)
.L7F05F668:
  b     .L7F05F684
   sh    $t9, 0x82($s0)
generate_temp_static_thrown:
  li    $t0, 1
  b     .L7F05F684
   sh    $t0, 0x82($s0)
generate_temp_default:
.L7F05F67C:
  li    $t1, 240
  sh    $t1, 0x82($s0)
.L7F05F684:
  lw    $t2, 0x64($s0)
  lui   $at, (0xFFF9FFFF >> 16) # lui $at, 0xfff9
  ori   $at, (0xFFF9FFFF & 0xFFFF) # ori $at, $at, 0xffff
  and   $t3, $t2, $at
  jal   get_cur_playernum
   sw    $t3, 0x64($s0)
  lw    $t4, 0x64($s0)
  sll   $t5, $v0, 0x11
  addiu $t7, $sp, 0xfc
  or    $t6, $t4, $t5
  sw    $t6, 0x64($s0)
  sw    $t7, 0x10($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0xe0
  addiu $a2, $sp, 0xa0
  jal   sub_GAME_7F05EC1C
   addiu $a3, $sp, 0xf0
  lw    $t8, 0x64($s0)
  andi  $t9, $t8, 0x80
  beql  $t9, $zero, .L7F05F72C
   lw    $ra, 0x24($sp)
  lw    $v0, 0x6c($s0)
  lui   $at, %hi(D_80053DC8)
  li    $t3, 60
  lw    $t0, ($v0)
  lui   $a0, %hi(ptr_sfx_buf)
  li    $a1, 4
  ori   $t1, $t0, 2
  sw    $t1, ($v0)
  lw    $t2, 0x6c($s0)
  lwc1  $f16, %lo(D_80053DC8)($at)
  move  $a2, $zero
  swc1  $f16, 0x8c($t2)
  lw    $t4, 0x6c($s0)
  sw    $t3, 0xbc($t4)
  jal   play_sfx_a1
   lw    $a0, %lo(ptr_sfx_buf)($a0)
  beqz  $v0, .L7F05F728
   move  $a0, $v0
  jal   sub_GAME_7F053A10
   addiu $a1, $s0, 0x58
.L7F05F728:
  lw    $ra, 0x24($sp)
.L7F05F72C:
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0x140
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80053DCC
.word 0x42055555 /*33.333332*/
glabel D_80053DD0
.word 0x3e99999a /*0.30000001*/
glabel D_80053DD4
.word 0x3e088888 /*0.13333333*/
.text
glabel sub_GAME_7F05F73C
  sll   $t6, $a0, 3
  subu  $t6, $t6, $a0
  sll   $t6, $t6, 2
  addu  $t6, $t6, $a0
  lui   $t7, %hi(pPlayer) 
  lw    $t7, %lo(pPlayer)($t7)
  sll   $t6, $t6, 2
  addu  $t6, $t6, $a0
  addiu $sp, $sp, -0xe8
  sll   $t6, $t6, 3
  addu  $t8, $t7, $t6
  sw    $ra, 0x1c($sp)
  addiu $t9, $t8, 0x870
  sw    $a0, 0xe8($sp)
  sw    $t9, 0xe0($sp)
  jal   get_curplayer_positiondata
   sw    $t6, 0x28($sp)
  jal   get_BONDdata_field408
   sw    $v0, 0x34($sp)
  sw    $v0, 0x30($sp)
  jal   matrix_4x4_set_identity
   addiu $a0, $sp, 0xa0
  addiu $a0, $sp, 0x44
  addiu $a1, $sp, 0x38
  jal   sub_GAME_7F0681CC
   lw    $a2, 0xe8($sp)
  jal   sub_GAME_7F078444
   nop   
  move  $a0, $v0
  jal   sub_GAME_7F0583D8
   addiu $a1, $sp, 0x38
  lui   $at, %hi(D_80053DCC)
  lwc1  $f0, %lo(D_80053DCC)($at)
  lwc1  $f4, 0x38($sp)
  lwc1  $f8, 0x3c($sp)
  lwc1  $f16, 0x40($sp)
  mul.s $f6, $f4, $f0
  lui   $t0, %hi(clock_timer) 
  lw    $t0, %lo(clock_timer)($t0)
  mul.s $f10, $f8, $f0
  lw    $v0, 0x30($sp)
  lw    $v1, 0x34($sp)
  mul.s $f18, $f16, $f0
  swc1  $f6, 0x94($sp)
  lui   $t1, %hi(pPlayer) 
  swc1  $f10, 0x98($sp)
  blez  $t0, .L7F05F84C
   swc1  $f18, 0x9c($sp)
  lwc1  $f4, 8($v1)
  lwc1  $f8, ($v0)
  lui   $at, %hi(global_timer_delta)
  lwc1  $f0, %lo(global_timer_delta)($at)
  sub.s $f16, $f4, $f8
  div.s $f4, $f16, $f0
  add.s $f8, $f6, $f4
  swc1  $f8, 0x94($sp)
  lwc1  $f6, 4($v0)
  lwc1  $f16, 0xc($v1)
  sub.s $f4, $f16, $f6
  div.s $f8, $f4, $f0
  add.s $f16, $f10, $f8
  swc1  $f16, 0x98($sp)
  lwc1  $f4, 8($v0)
  lwc1  $f6, 0x10($v1)
  sub.s $f10, $f6, $f4
  div.s $f8, $f10, $f0
  add.s $f16, $f18, $f8
  swc1  $f16, 0x9c($sp)
.L7F05F84C:
  lw    $t1, %lo(pPlayer)($t1)
  lw    $t2, 0x28($sp)
  addiu $a1, $sp, 0x50
  addu  $a0, $t1, $t2
  jal   matrix_4x4_copy
   addiu $a0, $a0, 0xad8
  mtc1  $zero, $f0
  li    $a0, 203
  li    $a1, 87
  swc1  $f0, 0x80($sp)
  swc1  $f0, 0x84($sp)
  jal   create_new_item_instance_of_model
   swc1  $f0, 0x88($sp)
  beqz  $v0, .L7F05F918
   li    $t3, 1200
  lw    $t4, 0x64($v0)
  lui   $at, (0xFFF9FFFF >> 16) # lui $at, 0xfff9
  ori   $at, (0xFFF9FFFF & 0xFFFF) # ori $at, $at, 0xffff
  and   $t5, $t4, $at
  sh    $t3, 0x82($v0)
  sw    $t5, 0x64($v0)
  jal   get_cur_playernum
   sw    $v0, 0xe4($sp)
  lw    $a0, 0xe4($sp)
  sll   $t7, $v0, 0x11
  addiu $t9, $sp, 0xa0
  lw    $t6, 0x64($a0)
  addiu $a2, $sp, 0x50
  addiu $a3, $sp, 0x94
  or    $t8, $t6, $t7
  sw    $t8, 0x64($a0)
  lw    $a1, 0xe0($sp)
  sw    $t9, 0x10($sp)
  jal   sub_GAME_7F05EC1C
   addiu $a1, $a1, 0x2e8
  lw    $a0, 0xe4($sp)
  lui   $at, %hi(D_80053DD0)
  lw    $t0, 0x64($a0)
  andi  $t1, $t0, 0x80
  beql  $t1, $zero, .L7F05F91C
   lw    $ra, 0x1c($sp)
  lwc1  $f6, %lo(D_80053DD0)($at)
  lw    $t2, 0x6c($a0)
  lui   $at, %hi(D_80053DD4)
  li    $t4, 60
  swc1  $f6, 0x8c($t2)
  lw    $t3, 0x6c($a0)
  lwc1  $f4, %lo(D_80053DD4)($at)
  swc1  $f4, 0x94($t3)
  lw    $t5, 0x6c($a0)
  sw    $t4, 0xbc($t5)
.L7F05F918:
  lw    $ra, 0x1c($sp)
.L7F05F91C:
  addiu $sp, $sp, 0xe8
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F05F928
  sll   $t7, $a0, 3
  subu  $t7, $t7, $a0
  addiu $sp, $sp, -0x80
  sll   $t7, $t7, 2
  addu  $t7, $t7, $a0
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  sll   $t7, $t7, 2
  addu  $t7, $t7, $a0
  sll   $t7, $t7, 3
  sw    $ra, 0x24($sp)
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  addu  $v0, $t6, $t7
  lw    $s0, 0xa90($v0)
  addiu $v0, $v0, 0x870
  beql  $s0, $zero, .L7F05FA64
   lw    $ra, 0x24($sp)
  lw    $s3, 0x10($s0)
  beql  $s3, $zero, .L7F05FA64
   lw    $ra, 0x24($sp)
  jal   get_curplayer_positiondata
   sw    $v0, 0x7c($sp)
  lw    $a0, 0x7c($sp)
  addiu $s2, $sp, 0x34
  sw    $v0, 0x30($sp)
  lw    $s1, 0x14($s0)
  move  $a1, $s2
  jal   matrix_4x4_copy
   addiu $a0, $a0, 0x268
  mtc1  $zero, $f0
  move  $a1, $s2
  swc1  $f0, 0x64($sp)
  swc1  $f0, 0x68($sp)
  swc1  $f0, 0x6c($sp)
  lw    $t8, 0x14($s0)
  jal   matrix_multiply_A1_by_F12
   lwc1  $f12, 0x14($t8)
  lw    $a1, 0x7c($sp)
  lw    $t9, 0x30($sp)
  move  $a0, $s0
  move  $a2, $s2
  addiu $a1, $a1, 0x2e8
  jal   sub_GAME_7F040754
   lw    $a3, 0x14($t9)
  jal   sub_GAME_7F040484
   move  $a0, $s0
  lw    $t0, 8($s1)
  lh    $a0, 0xe($t0)
  sll   $t1, $a0, 6
  jal   sub_GAME_7F0BD714
   move  $a0, $t1
  sw    $v0, 0xc($s1)
  addiu $a0, $s0, 0x18
  jal   matrix_4x4_copy
   move  $a1, $s2
  addiu $a0, $s0, 0x58
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   move  $a1, $s2
  jal   get_BONDdata_field_10CC
   nop   
  move  $a0, $v0
  move  $a1, $s2
  jal   matrix_4x4_multiply_homogeneous
   lw    $a2, 0xc($s1)
  lw    $t2, 8($s1)
  move  $a0, $s1
  jal   sub_GAME_7F06EEA4
   lw    $a1, ($t2)
  lbu   $t3, 1($s3)
  ori   $t4, $t3, 2
  sb    $t4, 1($s3)
  lw    $t5, 0xc($s1)
  lwc1  $f4, 0x38($t5)
  neg.s $f6, $f4
  swc1  $f6, 0x18($s3)
  lw    $ra, 0x24($sp)
.L7F05FA64:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x80
");

asm(R"
glabel sub_GAME_7F05FA7C
  sll   $t7, $a0, 3
  subu  $t7, $t7, $a0
  sll   $t7, $t7, 2
  addu  $t7, $t7, $a0
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  sll   $t7, $t7, 2
  addu  $t7, $t7, $a0
  addiu $sp, $sp, -0x20
  sll   $t7, $t7, 3
  sw    $ra, 0x14($sp)
  addu  $v1, $t6, $t7
  lw    $t8, 0xa90($v1)
  addiu $v1, $v1, 0x870
  bnezl $t8, .L7F05FAF4
   lw    $ra, 0x14($sp)
  lw    $t9, 0x2c($v1)
  li    $a0, 202
  li    $a1, 86
  blezl $t9, .L7F05FAF4
   lw    $ra, 0x14($sp)
  jal   create_new_item_instance_of_model
   sw    $v1, 0x1c($sp)
  beqz  $v0, .L7F05FAF0
   lw    $v1, 0x1c($sp)
  sw    $v0, 0x220($v1)
  sw    $zero, 0x224($v1)
  li    $t0, 1
  sh    $t0, 0x82($v0)
.L7F05FAF0:
  lw    $ra, 0x14($sp)
.L7F05FAF4:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F05FB00
  sll   $t7, $a0, 3
  subu  $t7, $t7, $a0
  sll   $t7, $t7, 2
  addu  $t7, $t7, $a0
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  sll   $t7, $t7, 2
  addu  $t7, $t7, $a0
  addiu $sp, $sp, -0x20
  sll   $t7, $t7, 3
  sw    $ra, 0x14($sp)
  addu  $v0, $t6, $t7
  lw    $a2, 0xa90($v0)
  addiu $v0, $v0, 0x870
  li    $a1, 1
  beqz  $a2, .L7F05FB54
   move  $a0, $a2
  jal   sub_GAME_7F041024
   sw    $v0, 0x1c($sp)
  lw    $v0, 0x1c($sp)
  sw    $zero, 0x220($v0)
.L7F05FB54:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80053DD8
.word 0x42855555 /*66.666664*/
glabel D_80053DDC
.word 0x3f8e38e3 /*1.111111*/
.text
glabel sub_GAME_7F05FB64
  sll   $t6, $a0, 3
  subu  $t6, $t6, $a0
  sll   $t6, $t6, 2
  addu  $t6, $t6, $a0
  lui   $t7, %hi(pPlayer) 
  lw    $t7, %lo(pPlayer)($t7)
  sll   $t6, $t6, 2
  addu  $t6, $t6, $a0
  addiu $sp, $sp, -0x108
  sll   $t6, $t6, 3
  addu  $t8, $t7, $t6
  sw    $ra, 0x1c($sp)
  addiu $t9, $t8, 0x870
  sw    $a0, 0x108($sp)
  sw    $t9, 0x100($sp)
  jal   get_curplayer_positiondata
   sw    $t6, 0x24($sp)
  jal   get_BONDdata_field408
   sw    $v0, 0x48($sp)
  sw    $v0, 0x44($sp)
  jal   get_item_in_hand
   lw    $a0, 0x108($sp)
  sw    $v0, 0x40($sp)
  jal   matrix_4x4_set_identity
   addiu $a0, $sp, 0xc0
  lw    $t0, 0x40($sp)
  li    $at, 32
  addiu $a0, $sp, 0x58
  bne   $t0, $at, .L7F05FD50
   addiu $a1, $sp, 0x4c
  jal   get_ptr_for_players_tank
   nop   
  beqz  $v0, .L7F05FC0C
   sw    $v0, 0x30($sp)
  lbu   $t1, 1($v0)
  andi  $t2, $t1, 2
  beql  $t2, $zero, .L7F05FC10
   addiu $a0, $sp, 0x58
  jal   sub_GAME_7F07CEB0
   addiu $a0, $sp, 0x4c
  b     .L7F05FC2C
   nop   
.L7F05FC0C:
  addiu $a0, $sp, 0x58
.L7F05FC10:
  jal   sub_GAME_7F068190
   addiu $a1, $sp, 0x4c
  jal   sub_GAME_7F078444
   nop   
  move  $a0, $v0
  jal   sub_GAME_7F0583D8
   addiu $a1, $sp, 0x4c
.L7F05FC2C:
  lui   $at, %hi(D_80053DD8)
  lwc1  $f0, %lo(D_80053DD8)($at)
  lwc1  $f4, 0x4c($sp)
  lwc1  $f8, 0x50($sp)
  lwc1  $f16, 0x54($sp)
  mul.s $f6, $f4, $f0
  lui   $t3, %hi(clock_timer) 
  lw    $t3, %lo(clock_timer)($t3)
  mul.s $f10, $f8, $f0
  lw    $v0, 0x48($sp)
  lw    $v1, 0x44($sp)
  mul.s $f18, $f16, $f0
  swc1  $f6, 0xb4($sp)
  swc1  $f10, 0xb8($sp)
  blez  $t3, .L7F05FCBC
   swc1  $f18, 0xbc($sp)
  lwc1  $f4, 8($v0)
  lwc1  $f8, ($v1)
  lui   $at, %hi(global_timer_delta)
  lwc1  $f0, %lo(global_timer_delta)($at)
  sub.s $f16, $f4, $f8
  div.s $f4, $f16, $f0
  add.s $f8, $f6, $f4
  swc1  $f8, 0xb4($sp)
  lwc1  $f6, 4($v1)
  lwc1  $f16, 0xc($v0)
  sub.s $f4, $f16, $f6
  div.s $f8, $f4, $f0
  add.s $f16, $f10, $f8
  swc1  $f16, 0xb8($sp)
  lwc1  $f4, 8($v1)
  lwc1  $f6, 0x10($v0)
  sub.s $f10, $f6, $f4
  div.s $f8, $f10, $f0
  add.s $f16, $f18, $f8
  swc1  $f16, 0xbc($sp)
.L7F05FCBC:
  lw    $v1, 0x30($sp)
  lw    $v0, 0x48($sp)
  beql  $v1, $zero, .L7F05FD2C
   lwc1  $f18, 8($v0)
  lbu   $t4, 1($v1)
  andi  $t5, $t4, 2
  beql  $t5, $zero, .L7F05FD2C
   lwc1  $f18, 8($v0)
  lw    $v0, 4($v1)
  lw    $t6, 0x14($v0)
  lw    $t7, 0xc($t6)
  lwc1  $f6, 0x130($t7)
  swc1  $f6, 0x34($sp)
  lw    $t8, 0x14($v0)
  lw    $t9, 0xc($t8)
  lwc1  $f4, 0x134($t9)
  swc1  $f4, 0x38($sp)
  lw    $t0, 0x14($v0)
  lw    $t1, 0xc($t0)
  lwc1  $f10, 0x138($t1)
  jal   sub_GAME_7F078444
   swc1  $f10, 0x3c($sp)
  move  $a0, $v0
  jal   sub_GAME_7F058474
   addiu $a1, $sp, 0x34
  b     .L7F05FD40
   nop   
  lwc1  $f18, 8($v0)
.L7F05FD2C:
  swc1  $f18, 0x34($sp)
  lwc1  $f8, 0xc($v0)
  swc1  $f8, 0x38($sp)
  lwc1  $f16, 0x10($v0)
  swc1  $f16, 0x3c($sp)
.L7F05FD40:
  jal   sub_GAME_7F09C7AC
   nop   
  b     .L7F05FE34
   nop   
.L7F05FD50:
  jal   sub_GAME_7F0681CC
   lw    $a2, 0x108($sp)
  jal   sub_GAME_7F078444
   nop   
  move  $a0, $v0
  jal   sub_GAME_7F0583D8
   addiu $a1, $sp, 0x4c
  lw    $a2, 0x100($sp)
  lui   $at, %hi(D_80053DDC)
  lwc1  $f2, %lo(D_80053DDC)($at)
  lwc1  $f6, 0x2e8($a2)
  lwc1  $f18, 0x4c($sp)
  lwc1  $f16, 0x50($sp)
  swc1  $f6, 0x34($sp)
  lwc1  $f4, 0x2ec($a2)
  mul.s $f8, $f18, $f2
  lui   $at, %hi(global_timer_delta)
  swc1  $f4, 0x38($sp)
  lwc1  $f10, 0x2f0($a2)
  mul.s $f6, $f16, $f2
  lwc1  $f4, 0x54($sp)
  swc1  $f10, 0x3c($sp)
  lwc1  $f0, %lo(global_timer_delta)($at)
  mul.s $f10, $f4, $f2
  lui   $t2, %hi(clock_timer) 
  lw    $t2, %lo(clock_timer)($t2)
  mul.s $f18, $f8, $f0
  swc1  $f8, 0xa4($sp)
  swc1  $f6, 0xa8($sp)
  mul.s $f16, $f6, $f0
  swc1  $f10, 0xac($sp)
  lw    $v0, 0x44($sp)
  mul.s $f4, $f10, $f0
  swc1  $f18, 0xb4($sp)
  lw    $v1, 0x48($sp)
  swc1  $f16, 0xb8($sp)
  blez  $t2, .L7F05FE34
   swc1  $f4, 0xbc($sp)
  lwc1  $f8, 8($v1)
  lwc1  $f6, ($v0)
  sub.s $f10, $f8, $f6
  div.s $f4, $f10, $f0
  add.s $f8, $f18, $f4
  swc1  $f8, 0xb4($sp)
  lwc1  $f10, 4($v0)
  lwc1  $f6, 0xc($v1)
  sub.s $f18, $f6, $f10
  div.s $f4, $f18, $f0
  add.s $f8, $f16, $f4
  lwc1  $f4, 0xbc($sp)
  swc1  $f8, 0xb8($sp)
  lwc1  $f10, 8($v0)
  lwc1  $f6, 0x10($v1)
  sub.s $f18, $f6, $f10
  div.s $f16, $f18, $f0
  add.s $f8, $f4, $f16
  swc1  $f8, 0xbc($sp)
.L7F05FE34:
  lui   $t3, %hi(pPlayer) 
  lw    $t3, %lo(pPlayer)($t3)
  lw    $t4, 0x24($sp)
  addiu $a1, $sp, 0x64
  addu  $a0, $t3, $t4
  jal   matrix_4x4_copy
   addiu $a0, $a0, 0xad8
  mtc1  $zero, $f0
  lw    $v1, 0x100($sp)
  li    $t5, 1
  swc1  $f0, 0x94($sp)
  swc1  $f0, 0x98($sp)
  swc1  $f0, 0x9c($sp)
  lw    $v0, 0x220($v1)
  li    $a0, 202
  beqz  $v0, .L7F05FE84
   nop   
  move  $a0, $v0
  b     .L7F05FE90
   sw    $t5, 0x224($v1)
.L7F05FE84:
  jal   create_new_item_instance_of_model
   li    $a1, 86
  move  $a0, $v0
.L7F05FE90:
  beqz  $a0, .L7F05FFB8
   li    $t6, -1
  lw    $t7, 0x64($a0)
  lui   $at, (0xFFF9FFFF >> 16) # lui $at, 0xfff9
  ori   $at, (0xFFF9FFFF & 0xFFFF) # ori $at, $at, 0xffff
  and   $t8, $t7, $at
  sh    $t6, 0x82($a0)
  sw    $t8, 0x64($a0)
  jal   get_cur_playernum
   sw    $a0, 0x104($sp)
  lw    $a0, 0x104($sp)
  sll   $t0, $v0, 0x11
  addiu $t2, $sp, 0xc0
  lw    $t9, 0x64($a0)
  addiu $a1, $sp, 0x34
  addiu $a2, $sp, 0x64
  or    $t1, $t9, $t0
  sw    $t1, 0x64($a0)
  sw    $t2, 0x10($sp)
  jal   sub_GAME_7F05EC1C
   addiu $a3, $sp, 0xb4
  lw    $a0, 0x104($sp)
  lw    $t3, 0x64($a0)
  andi  $t4, $t3, 0x80
  beql  $t4, $zero, .L7F05FFBC
   lw    $ra, 0x1c($sp)
  lw    $v0, 0x6c($a0)
  li    $at, 32
  lw    $t5, ($v0)
  ori   $t6, $t5, 0x80
  sw    $t6, ($v0)
  lw    $t7, 0x40($sp)
  beql  $t7, $at, .L7F05FFBC
   lw    $ra, 0x1c($sp)
  lw    $v0, 0x6c($a0)
  li    $t4, 60
  li    $a1, 1
  lw    $t8, ($v0)
  ori   $t9, $t8, 0x20
  sw    $t9, ($v0)
  lw    $t0, 0x6c($a0)
  lwc1  $f6, 0x5c($a0)
  swc1  $f6, 0xb0($t0)
  lw    $v0, 0x6c($a0)
  lwc1  $f10, 8($v0)
  swc1  $f10, 0xb4($v0)
  lw    $t1, 0x6c($a0)
  lwc1  $f18, 0xa4($sp)
  swc1  $f18, 0x10($t1)
  lw    $t2, 0x6c($a0)
  lwc1  $f4, 0xa8($sp)
  swc1  $f4, 0x14($t2)
  lw    $t3, 0x6c($a0)
  lwc1  $f16, 0xac($sp)
  swc1  $f16, 0x18($t3)
  lw    $t5, 0x6c($a0)
  sw    $t4, 0xbc($t5)
  lw    $v0, 0x6c($a0)
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $t6, 0x98($v0)
  addiu $a2, $v0, 0x98
  bnezl $t6, .L7F05FFA0
   lw    $t7, 0x9c($v0)
  jal   play_sfx_a1
   lw    $a0, %lo(ptr_sfx_buf)($a0)
  b     .L7F05FFBC
   lw    $ra, 0x1c($sp)
  lw    $t7, 0x9c($v0)
.L7F05FFA0:
  lui   $a0, %hi(ptr_sfx_buf)
  li    $a1, 1
  bnez  $t7, .L7F05FFB8
   addiu $a2, $v0, 0x9c
  jal   play_sfx_a1
   lw    $a0, %lo(ptr_sfx_buf)($a0)
.L7F05FFB8:
  lw    $ra, 0x1c($sp)
.L7F05FFBC:
  addiu $sp, $sp, 0x108
  jr    $ra
   nop   
");

#ifdef VERSION_US
asm(R"
.late_rodata
glabel D_80053DE0
.word 0x3f733333 /*0.94999999*/
glabel D_80053DE4
.word 0x3d4cccd0 /*0.050000012*/
glabel D_80053DE8
.word 0x3f19999a /*0.60000002*/
glabel D_80053DEC
.word 0x3e99999a /*0.30000001*/
glabel D_80053DF0
.word 0x3f19999a /*0.60000002*/
glabel D_80053DF4
.word 0x3e99999a /*0.30000001*/
glabel D_80053DF8
.word 0x3f19999a /*0.60000002*/
glabel D_80053DFC
.word 0x3e99999a /*0.30000001*/
glabel D_80053E00
.word 0x41de6666 /*27.799999*/
glabel D_80053E04
.word 0x3dccccce /*0.10000001*/
glabel D_80053E08
.word 0x40c90fdb /*6.2831855*/
glabel D_80053E0C
.word 0x40c90fdb /*6.2831855*/
glabel D_80053E10
.word 0x40c90fdb /*6.2831855*/
glabel D_80053E14
.word 0x3f060a92 /*0.52359879*/
glabel D_80053E18
.word 0x3f060a92 /*0.52359879*/
glabel D_80053E1C
.word 0x40c90fdb /*6.2831855*/
glabel D_80053E20
.word 0x40c90fdb /*6.2831855*/
glabel D_80053E24
.word 0x3dccccce /*0.10000001*/
glabel D_80053E28
.word 0x3dccccce /*0.10000001*/
glabel D_80053E2C
.word 0x40c90fdb /*6.2831855*/
glabel D_80053E30
.word 0x40c90fdb /*6.2831855*/
glabel D_80053E34
.word 0x40c90fdb /*6.2831855*/

/*D:80053E38*/
glabel jpt_weapon_bullet_type
.word weapon_bullet_type_pistol
.word weapon_bullet_type_pistol
.word weapon_bullet_type_pistol
.word weapon_bullet_type_pistol
.word weapon_bullet_type_pistol
.word weapon_bullet_type_pistol
.word weapon_bullet_type_pistol
.word weapon_bullet_type_pistol
.word weapon_bullet_type_pistol
.word weapon_bullet_type_pistol
.word weapon_bullet_type_pistol
.word weapon_bullet_type_shotgun_mine
.word weapon_bullet_type_shotgun_mine
.word weapon_bullet_type_pistol
.word weapon_bullet_type_pistol
.word weapon_bullet_type_pistol
.word weapon_bullet_type_pistol
.word weapon_bullet_type_pistol
.word weapon_bullet_type_none
.word weapon_bullet_type_none

.text
glabel handles_firing_or_throwing_weapon_in_hand
  addiu $sp, $sp, -0x2a8
  lui   $t7, %hi(D_80035C40) 
  sw    $ra, 0x34($sp)
  sw    $s0, 0x30($sp)
  addiu $t7, %lo(D_80035C40) # addiu $t7, $t7, 0x5c40
  lw    $at, ($t7)
  addiu $t6, $sp, 0x194
  lw    $t5, 4($t7)
  sw    $at, ($t6)
  lw    $at, 8($t7)
  sll   $t8, $a0, 3
  subu  $t8, $t8, $a0
  sll   $t8, $t8, 2
  addu  $t8, $t8, $a0
  lui   $t9, %hi(pPlayer) 
  sw    $t5, 4($t6)
  sw    $at, 8($t6)
  lw    $t9, %lo(pPlayer)($t9)
  sll   $t8, $t8, 2
  addu  $t8, $t8, $a0
  sll   $t8, $t8, 3
  addu  $s0, $t9, $t8
  sw    $zero, 0x10c($sp)
  sw    $zero, 0x108($sp)
  addiu $s0, $s0, 0x870
  jal   return_ammo_in_hand
   sw    $a0, 0x2a8($sp)
  sw    $v0, 0xfc($sp)
  jal   get_ptr_item_statistics
   move  $a0, $v0
  lw    $t6, 0x2a8($sp)
  sw    $v0, 0xf8($sp)
  bnez  $t6, .L7F060100
   nop   
  jal   return_ammo_in_hand
   li    $a0, 1
  move  $a0, $v0
  jal   check_special_attributes
   li    $a1, 2048
  beqz  $v0, .L7F0600BC
   lui   $at, %hi(global_timer_delta)
  lui   $at, %hi(global_timer_delta)
  lwc1  $f0, %lo(global_timer_delta)($at)
  li    $at, 0x43700000 # 240.000000
  mtc1  $at, $f6
  add.s $f4, $f0, $f0
  lwc1  $f10, 0x1c4($s0)
  li    $at, 0x40000000 # 2.000000
  mtc1  $at, $f18
  div.s $f8, $f4, $f6
  li    $at, 0x40000000 # 2.000000
  add.s $f16, $f10, $f8
  swc1  $f16, 0x1c4($s0)
  lwc1  $f4, 0x1c4($s0)
  c.lt.s $f18, $f4
  nop   
  bc1f  .L7F0601A8
   nop   
  mtc1  $at, $f6
  b     .L7F0601A8
   swc1  $f6, 0x1c4($s0)
.L7F0600BC:
  lwc1  $f0, %lo(global_timer_delta)($at)
  li    $at, 0x43700000 # 240.000000
  mtc1  $at, $f8
  add.s $f10, $f0, $f0
  lwc1  $f18, 0x1c4($s0)
  div.s $f16, $f10, $f8
  mtc1  $zero, $f10
  sub.s $f4, $f18, $f16
  swc1  $f4, 0x1c4($s0)
  lwc1  $f6, 0x1c4($s0)
  c.lt.s $f6, $f10
  nop   
  bc1f  .L7F0601A8
   nop   
  mtc1  $zero, $f8
  b     .L7F0601A8
   swc1  $f8, 0x1c4($s0)
.L7F060100:
  jal   return_ammo_in_hand
   move  $a0, $zero
  move  $a0, $v0
  jal   check_special_attributes
   li    $a1, 2048
  beqz  $v0, .L7F060164
   lui   $at, %hi(global_timer_delta)
  li    $at, 0xC0000000 # -2.000000
  mtc1  $at, $f2
  lui   $at, %hi(global_timer_delta)
  lwc1  $f0, %lo(global_timer_delta)($at)
  li    $at, 0x43700000 # 240.000000
  mtc1  $at, $f16
  add.s $f18, $f0, $f0
  lwc1  $f6, 0x1c4($s0)
  div.s $f4, $f18, $f16
  sub.s $f10, $f6, $f4
  swc1  $f10, 0x1c4($s0)
  lwc1  $f8, 0x1c4($s0)
  c.lt.s $f8, $f2
  nop   
  bc1f  .L7F0601A8
   nop   
  b     .L7F0601A8
   swc1  $f2, 0x1c4($s0)
.L7F060164:
  lwc1  $f0, %lo(global_timer_delta)($at)
  li    $at, 0x43700000 # 240.000000
  mtc1  $at, $f16
  add.s $f18, $f0, $f0
  lwc1  $f4, 0x1c4($s0)
  mtc1  $zero, $f8
  div.s $f6, $f18, $f16
  add.s $f10, $f4, $f6
  swc1  $f10, 0x1c4($s0)
  lwc1  $f18, 0x1c4($s0)
  c.lt.s $f8, $f18
  nop   
  bc1f  .L7F0601A8
   nop   
  mtc1  $zero, $f16
  nop   
  swc1  $f16, 0x1c4($s0)
.L7F0601A8:
  lui   $t7, %hi(D_80035C4C) 
  addiu $t7, %lo(D_80035C4C) # addiu $t7, $t7, 0x5c4c
  lw    $at, ($t7)
  addiu $t4, $sp, 0xe0
  lui   $t6, %hi(D_80035C58) 
  sw    $at, ($t4)
  lw    $t9, 4($t7)
  addiu $t6, %lo(D_80035C58) # addiu $t6, $t6, 0x5c58
  addiu $t8, $sp, 0xd4
  sw    $t9, 4($t4)
  lw    $at, 8($t7)
  lui   $t5, %hi(D_80035C64) 
  addiu $t5, %lo(D_80035C64) # addiu $t5, $t5, 0x5c64
  sw    $at, 8($t4)
  lw    $at, ($t6)
  lw    $t7, 4($t6)
  addiu $t9, $sp, 0xc8
  sw    $at, ($t8)
  lw    $at, 8($t6)
  sw    $t7, 4($t8)
  li    $v1, 12
  sw    $at, 8($t8)
  lw    $at, ($t5)
  lw    $t6, 4($t5)
  sw    $at, ($t9)
  lw    $at, 8($t5)
  sw    $t6, 4($t9)
  sw    $at, 8($t9)
  lw    $v0, 0x198($s0)
  lwc1  $f4, 0x19c($s0)
  sw    $t4, 0x14($sp)
  addiu $t7, $v0, 3
  bgez  $t7, .L7F06023C
   andi  $t8, $t7, 3
  beqz  $t8, .L7F06023C
   nop   
  addiu $t8, $t8, -4
.L7F06023C:
  multu $t8, $v1
  addiu $t6, $v0, 1
  swc1  $f4, 0x10($sp)
  mflo  $t9
  addu  $t0, $s0, $t9
  addiu $t9, $v0, 2
  multu $v0, $v1
  addiu $a0, $t0, 0x108
  sw    $t0, 0x44($sp)
  mflo  $t5
  addu  $t1, $s0, $t5
  addiu $a1, $t1, 0x108
  bgez  $t6, .L7F060280
   andi  $t7, $t6, 3
  beqz  $t7, .L7F060280
   nop   
  addiu $t7, $t7, -4
.L7F060280:
  multu $t7, $v1
  sw    $t1, 0x40($sp)
  mflo  $t8
  addu  $t2, $s0, $t8
  addiu $a2, $t2, 0x108
  bgez  $t9, .L7F0602A8
   andi  $t5, $t9, 3
  beqz  $t5, .L7F0602A8
   nop   
  addiu $t5, $t5, -4
.L7F0602A8:
  multu $t5, $v1
  sw    $t2, 0x3c($sp)
  mflo  $t6
  addu  $t3, $s0, $t6
  addiu $a3, $t3, 0x108
  jal   sub_GAME_7F05AEFC
   sw    $t3, 0x38($sp)
  lw    $a0, 0x44($sp)
  lw    $a1, 0x40($sp)
  lw    $a2, 0x3c($sp)
  lw    $a3, 0x38($sp)
  lwc1  $f6, 0x19c($s0)
  addiu $t7, $sp, 0xd4
  sw    $t7, 0x14($sp)
  addiu $a0, $a0, 0x138
  addiu $a1, $a1, 0x138
  addiu $a2, $a2, 0x138
  addiu $a3, $a3, 0x138
  jal   sub_GAME_7F05AEFC
   swc1  $f6, 0x10($sp)
  lw    $a0, 0x44($sp)
  lw    $a1, 0x40($sp)
  lw    $a2, 0x3c($sp)
  lw    $a3, 0x38($sp)
  lwc1  $f10, 0x19c($s0)
  addiu $t8, $sp, 0xc8
  sw    $t8, 0x14($sp)
  addiu $a0, $a0, 0x168
  addiu $a1, $a1, 0x168
  addiu $a2, $a2, 0x168
  addiu $a3, $a3, 0x168
  jal   sub_GAME_7F05AEFC
   swc1  $f10, 0x10($sp)
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lwc1  $f8, 0xe0($sp)
  lwc1  $f4, 0xe4($sp)
  lwc1  $f18, 0xfc0($v0)
  lw    $a0, 0x2a8($sp)
  mul.s $f16, $f8, $f18
  lwc1  $f8, 0xe8($sp)
  swc1  $f16, 0xe0($sp)
  lwc1  $f6, 0xfc0($v0)
  mul.s $f10, $f4, $f6
  swc1  $f10, 0xe4($sp)
  lwc1  $f18, 0xfc0($v0)
  mul.s $f4, $f8, $f18
  swc1  $f4, 0xe8($sp)
  lwc1  $f6, 0x1ac($s0)
  add.s $f8, $f16, $f6
  swc1  $f8, 0xe0($sp)
  lwc1  $f18, 0x1b0($s0)
  add.s $f4, $f10, $f18
  jal   sub_GAME_7F05DCB8
   swc1  $f4, 0xe4($sp)
  lwc1  $f16, 0xe0($sp)
  lui   $v0, %hi(clock_timer)
  addiu $v0, %lo(clock_timer) # addiu $v0, $v0, -0x7c8c
  add.s $f6, $f16, $f0
  lw    $t9, ($v0)
  move  $v1, $zero
  blez  $t9, .L7F060474
   swc1  $f6, 0xe0($sp)
  lui   $at, %hi(D_80053DE0)
  lwc1  $f0, %lo(D_80053DE0)($at)
  lwc1  $f10, 0xe4($s0)
.L7F0603B0:
  lwc1  $f8, 0xe0($sp)
  lwc1  $f6, 0xe8($s0)
  mul.s $f18, $f0, $f10
  addiu $v1, $v1, 1
  mul.s $f10, $f0, $f6
  add.s $f4, $f8, $f18
  swc1  $f4, 0xe4($s0)
  lwc1  $f16, 0xe4($sp)
  lwc1  $f4, 0xec($s0)
  add.s $f8, $f16, $f10
  mul.s $f6, $f0, $f4
  swc1  $f8, 0xe8($s0)
  lwc1  $f18, 0xe8($sp)
  lwc1  $f8, 0xf0($s0)
  add.s $f16, $f18, $f6
  mul.s $f4, $f0, $f8
  swc1  $f16, 0xec($s0)
  lwc1  $f10, 0xd4($sp)
  lwc1  $f16, 0xf4($s0)
  add.s $f18, $f10, $f4
  mul.s $f8, $f0, $f16
  swc1  $f18, 0xf0($s0)
  lwc1  $f6, 0xd8($sp)
  lwc1  $f18, 0xf8($s0)
  add.s $f10, $f6, $f8
  mul.s $f16, $f0, $f18
  swc1  $f10, 0xf4($s0)
  lwc1  $f4, 0xdc($sp)
  lwc1  $f10, 0xfc($s0)
  add.s $f6, $f4, $f16
  mul.s $f18, $f0, $f10
  swc1  $f6, 0xf8($s0)
  lwc1  $f8, 0xc8($sp)
  lwc1  $f6, 0x100($s0)
  add.s $f4, $f8, $f18
  mul.s $f10, $f0, $f6
  swc1  $f4, 0xfc($s0)
  lwc1  $f16, 0xcc($sp)
  lwc1  $f4, 0x104($s0)
  add.s $f8, $f16, $f10
  mul.s $f6, $f0, $f4
  swc1  $f8, 0x100($s0)
  lwc1  $f18, 0xd0($sp)
  add.s $f16, $f18, $f6
  swc1  $f16, 0x104($s0)
  lw    $t5, ($v0)
  slt   $at, $v1, $t5
  bnezl $at, .L7F0603B0
   lwc1  $f10, 0xe4($s0)
.L7F060474:
  lui   $at, %hi(D_80053DE4)
  lwc1  $f0, %lo(D_80053DE4)($at)
  lwc1  $f10, 0xe4($s0)
  lwc1  $f4, 0xe8($s0)
  lwc1  $f6, 0xec($s0)
  mul.s $f8, $f10, $f0
  lwc1  $f10, 0xf0($s0)
  lw    $a0, 0x2a8($sp)
  mul.s $f18, $f4, $f0
  lwc1  $f4, 0xf4($s0)
  mul.s $f16, $f6, $f0
  swc1  $f8, 0xc0($s0)
  lwc1  $f6, 0xf8($s0)
  mul.s $f8, $f10, $f0
  swc1  $f18, 0xc4($s0)
  lwc1  $f10, 0xfc($s0)
  mul.s $f18, $f4, $f0
  swc1  $f16, 0xc8($s0)
  lwc1  $f4, 0x100($s0)
  mul.s $f16, $f6, $f0
  swc1  $f8, 0xcc($s0)
  lwc1  $f6, 0x104($s0)
  mul.s $f8, $f10, $f0
  swc1  $f18, 0xd0($s0)
  mul.s $f18, $f4, $f0
  swc1  $f16, 0xd4($s0)
  mul.s $f16, $f6, $f0
  swc1  $f8, 0xd8($s0)
  swc1  $f18, 0xdc($s0)
  bnez  $a0, .L7F060510
   swc1  $f16, 0xe0($s0)
  jal   sub_GAME_7F05DCE8
   nop   
  lwc1  $f8, 0xc0($s0)
  lwc1  $f10, 0x1b8($s0)
  add.s $f4, $f0, $f8
  add.s $f18, $f10, $f4
  b     .L7F06052C
   swc1  $f18, 0x194($sp)
.L7F060510:
  jal   sub_GAME_7F05DCE8
   nop   
  lwc1  $f6, 0xc0($s0)
  lwc1  $f8, 0x1b8($s0)
  add.s $f16, $f0, $f6
  sub.s $f10, $f16, $f8
  swc1  $f10, 0x194($sp)
.L7F06052C:
  lw    $t6, 0xf8($sp)
  lwc1  $f18, 0xc4($s0)
  lwc1  $f16, 0x1bc($s0)
  lwc1  $f4, 8($t6)
  lw    $a0, 0xfc($sp)
  li    $at, 25
  add.s $f6, $f4, $f18
  add.s $f8, $f16, $f6
  swc1  $f8, 0x198($sp)
  lwc1  $f4, 0xc8($s0)
  lwc1  $f10, 0xc($t6)
  lwc1  $f16, 0x1c0($s0)
  add.s $f18, $f10, $f4
  add.s $f6, $f16, $f18
  beq   $a0, $at, .L7F06057C
   swc1  $f6, 0x19c($sp)
  li    $at, 30
  beq   $a0, $at, .L7F06057C
   li    $at, 23
  bne   $a0, $at, .L7F06061C
.L7F06057C:
   lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  li    $at, 0xC2C80000 # -100.000000
  mtc1  $at, $f0
  lwc1  $f10, 0xa0($v0)
  lwc1  $f8, 0x198($sp)
  li    $at, 0x40400000 # 3.000000
  div.s $f4, $f10, $f0
  mtc1  $at, $f18
  li    $at, 25
  add.s $f16, $f8, $f4
  lwc1  $f4, 0x19c($sp)
  swc1  $f16, 0x198($sp)
  lwc1  $f6, 0xa0($v0)
  mul.s $f10, $f18, $f6
  div.s $f8, $f10, $f0
  add.s $f16, $f4, $f8
  bne   $a0, $at, .L7F060614
   swc1  $f16, 0x19c($sp)
  jal   cur_player_get_screen_setting
   nop   
  li    $at, 1
  beql  $v0, $at, .L7F060604
   lui   $at, 0x4040
  jal   cur_player_get_screen_setting
   nop   
  li    $at, 2
  beql  $v0, $at, .L7F060604
   lui   $at, 0x4040
  jal   get_screen_ratio
   nop   
  li    $at, 1
  bne   $v0, $at, .L7F060614
   li    $at, 0x40400000 # 3.000000
.L7F060604:
  mtc1  $at, $f6
  lwc1  $f18, 0x198($sp)
  sub.s $f10, $f18, $f6
  swc1  $f10, 0x198($sp)
.L7F060614:
  b     .L7F0606C8
   lw    $a0, 0xfc($sp)
.L7F06061C:
  li    $at, 31
  bne   $a0, $at, .L7F06067C
   lui   $v0, %hi(pPlayer)
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  li    $at, 0xC2C80000 # -100.000000
  mtc1  $at, $f0
  li    $at, 0x40200000 # 2.500000
  mtc1  $at, $f4
  lwc1  $f8, 0xa0($v0)
  lwc1  $f6, 0x198($sp)
  li    $at, 0x40F00000 # 7.500000
  mul.s $f16, $f4, $f8
  mtc1  $at, $f4
  div.s $f18, $f16, $f0
  add.s $f10, $f6, $f18
  lwc1  $f18, 0x19c($sp)
  swc1  $f10, 0x198($sp)
  lwc1  $f8, 0xa0($v0)
  mul.s $f16, $f4, $f8
  div.s $f6, $f16, $f0
  add.s $f10, $f18, $f6
  b     .L7F0606C8
   swc1  $f10, 0x19c($sp)
.L7F06067C:
  lw    $v0, %lo(pPlayer)($v0)
  li    $at, 0xC2C80000 # -100.000000
  mtc1  $at, $f0
  li    $at, 0x40A00000 # 5.000000
  mtc1  $at, $f4
  lwc1  $f8, 0xa0($v0)
  lwc1  $f6, 0x198($sp)
  li    $at, 0x41700000 # 15.000000
  mul.s $f16, $f4, $f8
  mtc1  $at, $f4
  div.s $f18, $f16, $f0
  add.s $f10, $f6, $f18
  lwc1  $f18, 0x19c($sp)
  swc1  $f10, 0x198($sp)
  lwc1  $f8, 0xa0($v0)
  mul.s $f16, $f4, $f8
  div.s $f6, $f16, $f0
  add.s $f10, $f18, $f6
  swc1  $f10, 0x19c($sp)
.L7F0606C8:
  lb    $t7, 0xc($s0)
  beqz  $t7, .L7F0607EC
   nop   
  jal   check_special_attributes
   li    $a1, 32
  beqz  $v0, .L7F0607EC
   lw    $a0, 0xfc($sp)
  jal   check_special_attributes
   li    $a1, 64
  beqz  $v0, .L7F060748
   nop   
  jal   get_random_value
   nop   
  mtc1  $v0, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F060718
   cvt.s.w $f8, $f4
  mtc1  $at, $f16
  nop   
  add.s $f8, $f8, $f16
.L7F060718:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f18
  lui   $at, %hi(D_80053DE8)
  lwc1  $f10, %lo(D_80053DE8)($at)
  mul.s $f6, $f8, $f18
  lui   $at, %hi(D_80053DEC)
  lwc1  $f16, %lo(D_80053DEC)($at)
  lwc1  $f18, 0x194($sp)
  mul.s $f4, $f6, $f10
  sub.s $f8, $f16, $f4
  add.s $f6, $f18, $f8
  swc1  $f6, 0x194($sp)
.L7F060748:
  jal   get_random_value
   nop   
  mtc1  $v0, $f10
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F06076C
   cvt.s.w $f16, $f10
  mtc1  $at, $f4
  nop   
  add.s $f16, $f16, $f4
.L7F06076C:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f18
  lui   $at, %hi(D_80053DF0)
  lwc1  $f6, %lo(D_80053DF0)($at)
  mul.s $f8, $f16, $f18
  lui   $at, %hi(D_80053DF4)
  lwc1  $f4, %lo(D_80053DF4)($at)
  lwc1  $f18, 0x198($sp)
  mul.s $f10, $f8, $f6
  sub.s $f16, $f4, $f10
  add.s $f8, $f18, $f16
  jal   get_random_value
   swc1  $f8, 0x198($sp)
  mtc1  $v0, $f6
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F0607BC
   cvt.s.w $f4, $f6
  mtc1  $at, $f10
  nop   
  add.s $f4, $f4, $f10
.L7F0607BC:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f18
  lui   $at, %hi(D_80053DF8)
  lwc1  $f8, %lo(D_80053DF8)($at)
  mul.s $f16, $f4, $f18
  lui    $at, %hi(D_80053DFC)
  lwc1  $f10, %lo(D_80053DFC)($at)
  lwc1  $f18, 0x19c($sp)
  mul.s $f6, $f16, $f8
  sub.s $f4, $f10, $f6
  add.s $f16, $f18, $f4
  swc1  $f16, 0x19c($sp)
.L7F0607EC:
  jal   getPlayer_c_screenwidth
   nop   
  jal   getPlayer_c_screenwidth
   swc1  $f0, 0x48($sp)
  jal   getPlayer_c_screenleft
   swc1  $f0, 0x4c($sp)
  li    $at, 0x3F000000 # 0.500000
  lui   $t8, %hi(pPlayer) 
  lw    $t8, %lo(pPlayer)($t8)
  mtc1  $at, $f2
  lwc1  $f6, 0x4c($sp)
  lwc1  $f8, 0xffc($t8)
  lw    $t9, 0xf8($sp)
  mul.s $f18, $f6, $f2
  sub.s $f10, $f8, $f0
  lwc1  $f16, 0x18($t9)
  lwc1  $f6, 0x48($sp)
  sub.s $f4, $f10, $f18
  mul.s $f8, $f4, $f16
  lwc1  $f4, 0x194($sp)
  mul.s $f10, $f6, $f2
  div.s $f18, $f8, $f10
  add.s $f16, $f4, $f18
  jal   getPlayer_c_screentop
   swc1  $f16, 0x194($sp)
  jal   getPlayer_c_screenheight
   swc1  $f0, 0x50($sp)
  li    $at, 0x3F000000 # 0.500000
  lui   $t5, %hi(pPlayer) 
  lw    $t5, %lo(pPlayer)($t5)
  mtc1  $at, $f6
  lwc1  $f4, 0x50($sp)
  lwc1  $f10, 0x1000($t5)
  mul.s $f8, $f0, $f6
  sub.s $f18, $f10, $f4
  c.lt.s $f8, $f18
  nop   
  bc1f  .L7F0608EC
   nop   
  jal   getPlayer_c_screenheight
   nop   
  jal   getPlayer_c_screenheight
   swc1  $f0, 0x48($sp)
  jal   getPlayer_c_screentop
   swc1  $f0, 0x4c($sp)
  li    $at, 0x3F000000 # 0.500000
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  mtc1  $at, $f2
  lwc1  $f10, 0x4c($sp)
  lwc1  $f16, 0x1000($t6)
  lw    $t7, 0xf8($sp)
  mul.s $f4, $f10, $f2
  sub.s $f6, $f16, $f0
  lwc1  $f18, 0x14($t7)
  lwc1  $f10, 0x48($sp)
  sub.s $f8, $f6, $f4
  mul.s $f16, $f8, $f18
  lwc1  $f8, 0x198($sp)
  mul.s $f6, $f10, $f2
  div.s $f4, $f16, $f6
  sub.s $f18, $f8, $f4
  b     .L7F060950
   swc1  $f18, 0x198($sp)
.L7F0608EC:
  jal   getPlayer_c_screenheight
   nop   
  jal   getPlayer_c_screenheight
   swc1  $f0, 0x48($sp)
  jal   getPlayer_c_screentop
   swc1  $f0, 0x4c($sp)
  li    $at, 0x3F000000 # 0.500000
  lui   $t8, %hi(pPlayer) 
  lw    $t8, %lo(pPlayer)($t8)
  mtc1  $at, $f16
  lwc1  $f10, 0x4c($sp)
  lwc1  $f8, 0x1000($t8)
  lw    $t9, 0xf8($sp)
  mul.s $f6, $f10, $f16
  sub.s $f4, $f8, $f0
  lwc1  $f10, 0x10($t9)
  lwc1  $f8, 0x48($sp)
  sub.s $f18, $f4, $f6
  mtc1  $at, $f4
  mul.s $f16, $f18, $f10
  lwc1  $f10, 0x198($sp)
  mul.s $f6, $f8, $f4
  div.s $f18, $f16, $f6
  sub.s $f8, $f10, $f18
  swc1  $f8, 0x198($sp)
.L7F060950:
  jal   sub_GAME_7F05C614
   nop   
  jal   matrix_4x4_set_identity
   addiu $a0, $sp, 0x154
  lw    $v0, 0xfc($sp)
  li    $at, 30
  beq   $v0, $at, .L7F060974
   li    $at, 23
  bne   $v0, $at, .L7F0609B4
.L7F060974:
   lui   $t5, %hi(D_80035C70) 
  addiu $t5, %lo(D_80035C70) # addiu $t5, $t5, 0x5c70
  lw    $at, ($t5)
  addiu $a0, $sp, 0xb8
  addiu $a1, $sp, 0x1a4
  sw    $at, ($a0)
  lw    $t7, 4($t5)
  sw    $t7, 4($a0)
  lw    $at, 8($t5)
  jal   sub_GAME_7F058714
   sw    $at, 8($a0)
  addiu $a0, $sp, 0x1a4
  jal   matrix_4x4_multiply_homogeneous_in_place
   addiu $a1, $sp, 0x154
  b     .L7F060A94
   lw    $t5, 0xbc($s0)
.L7F0609B4:
  li    $at, 31
  bne   $v0, $at, .L7F0609FC
   lui   $t8, %hi(D_80035C7C) 
  addiu $t8, %lo(D_80035C7C) # addiu $t8, $t8, 0x5c7c
  lw    $at, ($t8)
  addiu $a0, $sp, 0xac
  addiu $a1, $sp, 0x1a4
  sw    $at, ($a0)
  lw    $t6, 4($t8)
  sw    $t6, 4($a0)
  lw    $at, 8($t8)
  jal   sub_GAME_7F058714
   sw    $at, 8($a0)
  addiu $a0, $sp, 0x1a4
  jal   matrix_4x4_multiply_homogeneous_in_place
   addiu $a1, $sp, 0x154
  b     .L7F060A94
   lw    $t5, 0xbc($s0)
.L7F0609FC:
  li    $at, 1
  bne   $v0, $at, .L7F060A90
   lui   $t5, %hi(pPlayer) 
  lw    $t5, %lo(pPlayer)($t5)
  li    $at, 17
  lui   $t9, %hi(D_80035C88) 
  lw    $t7, 0x2a38($t5)
  addiu $t9, %lo(D_80035C88) # addiu $t9, $t9, 0x5c88
  bnel  $t7, $at, .L7F060A94
   lw    $t5, 0xbc($s0)
  lw    $at, ($t9)
  addiu $a0, $sp, 0xa0
  addiu $a1, $sp, 0x1a4
  sw    $at, ($a0)
  lw    $t6, 4($t9)
  sw    $t6, 4($a0)
  lw    $at, 8($t9)
  jal   sub_GAME_7F058714
   sw    $at, 8($a0)
  addiu $a0, $sp, 0x1a4
  jal   matrix_4x4_multiply_homogeneous_in_place
   addiu $a1, $sp, 0x154
  li    $at, 0xC0200000 # -2.500000
  mtc1  $at, $f16
  lwc1  $f4, 0x194($sp)
  lui   $at, %hi(D_80053E00)
  lwc1  $f18, %lo(D_80053E00)($at)
  add.s $f6, $f4, $f16
  li    $at, 0x40000000 # 2.000000
  lwc1  $f10, 0x198($sp)
  mtc1  $at, $f16
  lwc1  $f4, 0x19c($sp)
  swc1  $f6, 0x194($sp)
  add.s $f8, $f10, $f18
  add.s $f6, $f4, $f16
  swc1  $f8, 0x198($sp)
  swc1  $f6, 0x19c($sp)
.L7F060A90:
  lw    $t5, 0xbc($s0)
.L7F060A94:
  beql  $t5, $zero, .L7F060AF4
   mtc1  $zero, $f4
  lwc1  $f10, 0x194($sp)
  lwc1  $f18, 0xac($s0)
  lwc1  $f4, 0x198($sp)
  addiu $a0, $s0, 0x7c
  add.s $f8, $f10, $f18
  lwc1  $f10, 0x19c($sp)
  addiu $a1, $sp, 0x154
  swc1  $f8, 0x194($sp)
  lwc1  $f16, 0xb0($s0)
  add.s $f6, $f4, $f16
  swc1  $f6, 0x198($sp)
  lwc1  $f18, 0xb4($s0)
  add.s $f8, $f10, $f18
  jal   matrix_4x4_multiply_homogeneous_in_place
   swc1  $f8, 0x19c($sp)
  mtc1  $zero, $f0
  nop   
  swc1  $f0, 0x184($sp)
  swc1  $f0, 0x188($sp)
  b     .L7F060B14
   swc1  $f0, 0x18c($sp)
  mtc1  $zero, $f4
.L7F060AF4:
  mtc1  $zero, $f16
  mtc1  $zero, $f6
  mtc1  $zero, $f10
  mtc1  $zero, $f0
  swc1  $f4, 0x78($s0)
  swc1  $f16, 0x6c($s0)
  swc1  $f6, 0x70($s0)
  swc1  $f10, 0x74($s0)
.L7F060B14:
  lwc1  $f18, 0xcc($s0)
  mfc1  $a1, $f0
  mfc1  $a2, $f0
  swc1  $f18, 0x10($sp)
  lwc1  $f8, 0xd0($s0)
  mfc1  $a3, $f0
  addiu $a0, $sp, 0x1a4
  swc1  $f8, 0x14($sp)
  lwc1  $f4, 0xd4($s0)
  swc1  $f4, 0x18($sp)
  lwc1  $f16, 0xd8($s0)
  swc1  $f16, 0x1c($sp)
  lwc1  $f6, 0xdc($s0)
  swc1  $f6, 0x20($sp)
  lwc1  $f10, 0xe0($s0)
  jal   sub_GAME_7F059908
   swc1  $f10, 0x24($sp)
  addiu $a0, $sp, 0x1a4
  jal   matrix_4x4_multiply_homogeneous_in_place
   addiu $a1, $sp, 0x154
  lwc1  $f18, 0x194($sp)
  lwc1  $f8, 0x1c8($s0)
  lwc1  $f16, 0x198($sp)
  lwc1  $f6, 0x1cc($s0)
  sub.s $f4, $f18, $f8
  lwc1  $f8, 0x1d0($s0)
  lwc1  $f18, 0x19c($sp)
  sub.s $f10, $f16, $f6
  mfc1  $a2, $f4
  addiu $a0, $sp, 0x1a4
  sub.s $f4, $f18, $f8
  mfc1  $a3, $f10
  li    $a1, 0
  jal   sub_GAME_7F059CE8
   swc1  $f4, 0x10($sp)
  addiu $a0, $sp, 0x1a4
  jal   matrix_4x4_multiply_homogeneous_in_place
   addiu $a1, $sp, 0x154
  addiu $a0, $sp, 0x154
  jal   matrix_4x4_copy
   addiu $a1, $sp, 0x264
  addiu $a0, $sp, 0x194
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   addiu $a1, $sp, 0x264
  addiu $a1, $s0, 0x228
  sw    $a1, 0x44($sp)
  jal   matrix_4x4_copy
   addiu $a0, $sp, 0x264
  addiu $a0, $s0, 0x268
  sw    $a0, 0x40($sp)
  jal   matrix_4x4_copy
   addiu $a1, $s0, 0x2a8
  jal   sub_GAME_7F078444
   nop   
  move  $a0, $v0
  lw    $a1, 0x44($sp)
  jal   matrix_4x4_multiply_homogeneous
   lw    $a2, 0x40($sp)
  li    $t7, 1
  sb    $t7, 0xf($s0)
  jal   get_ptr_weapon_model_header_line
   lw    $a0, 0xfc($sp)
  beqz  $v0, .L7F060C6C
   lw    $a0, 0xfc($sp)
  jal   check_special_attributes
   li    $a1, 2048
  beqz  $v0, .L7F060C6C
   lw    $a0, 0xfc($sp)
  jal   check_special_attributes
   li    $a1, 8192
  bnezl $v0, .L7F060C70
   sb    $zero, 0xf($s0)
  lw    $v0, 0x24($s0)
  li    $at, 6
  beq   $v0, $at, .L7F060C6C
   li    $at, 7
  beql  $v0, $at, .L7F060C70
   sb    $zero, 0xf($s0)
  jal   sub_GAME_7F05CEBC
   lw    $a0, 0x2a8($sp)
  beql  $v0, $zero, .L7F060C70
   sb    $zero, 0xf($s0)
  jal   get_itemtype_in_hand
   lw    $a0, 0x2a8($sp)
  bnezl $v0, .L7F060C74
   lw    $t8, 0x2c($s0)
.L7F060C6C:
  sb    $zero, 0xf($s0)
.L7F060C70:
  lw    $t8, 0x2c($s0)
.L7F060C74:
  lw    $a0, 0xfc($sp)
  bgtzl $t8, .L7F060C98
   lb    $t9, 0xf($s0)
  jal   check_special_attributes
   li    $a1, 2
  beql  $v0, $zero, .L7F060C98
   lb    $t9, 0xf($s0)
  sb    $zero, 0xf($s0)
  lb    $t9, 0xf($s0)
.L7F060C98:
  lui   $t6, %hi(pPlayer) 
  lw    $t5, 0x2a8($sp)
  beql  $t9, $zero, .L7F0617D8
   lw    $t7, 0xfc($sp)
  lw    $t6, %lo(pPlayer)($t6)
  sll   $t7, $t5, 5
  move  $v1, $zero
  addu  $v0, $t6, $t7
  lh    $a0, 0x81e($v0)
  addiu $v0, $v0, 0x810
  sw    $v0, 0x1a0($sp)
  sll   $t8, $a0, 6
  move  $a0, $t8
  jal   sub_GAME_7F0BD714
   sw    $zero, 0x100($sp)
  lw    $t9, 0x1a0($sp)
  sw    $v0, 0x2a4($sp)
  lw    $v1, 0x100($sp)
  lh    $t5, 0xe($t9)
  blez  $t5, .L7F060D1C
   move  $a0, $v0
  sw    $v1, 0x100($sp)
.L7F060CF0:
  jal   matrix_4x4_set_identity
   sw    $a0, 0x44($sp)
  lw    $t6, 0x1a0($sp)
  lw    $v1, 0x100($sp)
  lw    $a0, 0x44($sp)
  lh    $t7, 0xe($t6)
  addiu $v1, $v1, 1
  addiu $a0, $a0, 0x40
  slt   $at, $v1, $t7
  bnezl $at, .L7F060CF0
   sw    $v1, 0x100($sp)
.L7F060D1C:
  jal   set_objuse_flag_compute_grp_nums_set_obj_loaded
   lw    $a0, 0x1a0($sp)
  addiu $a0, $s0, 0x2f8
  lw    $a1, 0x1a0($sp)
  sw    $a0, 0x44($sp)
  jal   sub_GAME_7F075F68
   addiu $a2, $s0, 0x318
  lw    $a0, 0x44($sp)
  jal   sub_GAME_7F05E978
   li    $a1, 1
  lw    $a0, 0x44($sp)
  jal   sub_GAME_7F05EA94
   lb    $a1, 0xe($s0)
  lw    $t8, 0x1a0($sp)
  lw    $v0, 8($t8)
  lw    $a0, 4($v0)
  beql  $a0, $zero, .L7F060D80
   lw    $v1, 0xc($v0)
  lw    $v1, 4($a0)
  lhu   $t9, 4($v1)
  sll   $t5, $t9, 2
  addu  $t6, $s0, $t5
  addiu $t7, $t6, 0x318
  sw    $t7, 0x10c($sp)
  lw    $v1, 0xc($v0)
.L7F060D80:
  beql  $v1, $zero, .L7F060D94
   lw    $t9, 0x2a4($sp)
  lw    $t8, 4($v1)
  sw    $t8, 0x108($sp)
  lw    $t9, 0x2a4($sp)
.L7F060D94:
  li    $a1, 1024
  sw    $t9, 0x304($s0)
  jal   check_special_attributes
   lw    $a0, 0xfc($sp)
  beqz  $v0, .L7F060DC8
   nop   
  lw    $t5, 0x2a8($sp)
  li    $at, 1
  bne   $t5, $at, .L7F060DC8
   li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f12
  jal   sub_GAME_7F0589B4
   addiu $a1, $sp, 0x264
.L7F060DC8:
  lui   $at, %hi(D_80053E04)
  lwc1  $f12, %lo(D_80053E04)($at)
  jal   matrix_multiply_A1_by_F12
   addiu $a1, $sp, 0x264
  addiu $a0, $sp, 0x264
  jal   matrix_4x4_copy
   lw    $a1, 0x2a4($sp)
  lw    $t7, 0x1a0($sp)
  lui   $t6, %hi(weapon_gun_revolver) 
  addiu $t6, %lo(weapon_gun_revolver) # addiu $t6, $t6, -0x3894
  lw    $t8, 4($t7)
  bnel  $t6, $t8, .L7F060FD8
   lw    $v0, 0x10c($sp)
  lw    $v0, 8($t7)
  lw    $t9, 0xfc($sp)
  li    $at, 18
  lw    $v1, 0x10($v0)
  addiu $a1, $sp, 0x1a4
  beql  $v1, $zero, .L7F060F18
   lw    $v1, 0x14($v0)
  mtc1  $zero, $f12
  bne   $t9, $at, .L7F060EA4
   lw    $a0, 4($v1)
  lw    $t5, 0x24($s0)
  li    $at, 1
  bnel  $t5, $at, .L7F060E78
   lw    $t8, 0x2c($s0)
  lw    $t8, 0x2c($s0)
  lw    $t6, 0x20($s0)
  lui   $at, %hi(D_80053E08)
  sll   $t7, $t8, 2
  subu  $t7, $t7, $t8
  sll   $t7, $t7, 1
  subu  $t9, $t6, $t7
  addiu $t5, $t9, 0x1e
  mtc1  $t5, $f16
  lwc1  $f10, %lo(D_80053E08)($at)
  li    $at, 0x42100000 # 36.000000
  cvt.s.w $f6, $f16
  mtc1  $at, $f8
  mul.s $f18, $f6, $f10
  b     .L7F060EE4
   div.s $f12, $f18, $f8
  lw    $t8, 0x2c($s0)
.L7F060E78:
  li    $t6, 6
  lui   $at, %hi(D_80053E0C)
  subu  $t7, $t6, $t8
  mtc1  $t7, $f4
  lwc1  $f6, %lo(D_80053E0C)($at)
  li    $at, 0x40C00000 # 6.000000
  cvt.s.w $f16, $f4
  mtc1  $at, $f18
  mul.s $f10, $f16, $f6
  b     .L7F060EE4
   div.s $f12, $f10, $f18
.L7F060EA4:
  lw    $t9, 0x24($s0)
  li    $at, 1
  bne   $t9, $at, .L7F060EE4
   nop   
  lw    $v0, 0x20($s0)
  slti  $at, $v0, 6
  beqz  $at, .L7F060EE4
   nop   
  mtc1  $v0, $f8
  lui   $at, %hi(D_80053E10)
  lwc1  $f16, %lo(D_80053E10)($at)
  cvt.s.w $f4, $f8
  li    $at, 0x42100000 # 36.000000
  mtc1  $at, $f10
  mul.s $f6, $f4, $f16
  div.s $f12, $f6, $f10
.L7F060EE4:
  jal   sub_GAME_7F058688
   sw    $a0, 0x9c($sp)
  lw    $a0, 0x9c($sp)
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   addiu $a1, $sp, 0x1a4
  lw    $a2, 0x2a4($sp)
  addiu $a0, $sp, 0x264
  addiu $a1, $sp, 0x1a4
  jal   matrix_4x4_multiply
   addiu $a2, $a2, 0xc0
  lw    $t5, 0x1a0($sp)
  lw    $v0, 8($t5)
  lw    $v1, 0x14($v0)
.L7F060F18:
  beql  $v1, $zero, .L7F060FD8
   lw    $v0, 0x10c($sp)
  lw    $t6, 0x24($s0)
  li    $at, 1
  lw    $a0, 4($v1)
  bne   $t6, $at, .L7F060FB8
   addiu $a1, $sp, 0x1a4
  lw    $v0, 0x20($s0)
  li    $t8, 6
  slti  $at, $v0, 3
  beqz  $at, .L7F060F74
   subu  $t7, $t8, $v0
  mtc1  $v0, $f18
  lui   $at, %hi(D_80053E14)
  lwc1  $f16, %lo(D_80053E14)($at)
  cvt.s.w $f8, $f18
  li    $at, 0x40C00000 # 6.000000
  mtc1  $at, $f10
  neg.s $f4, $f8
  mul.s $f0, $f4, $f16
  add.s $f6, $f0, $f0
  b     .L7F060F9C
   div.s $f12, $f6, $f10
.L7F060F74:
  mtc1  $t7, $f18
  lui   $at, %hi(D_80053E18)
  lwc1  $f16, %lo(D_80053E18)($at)
  cvt.s.w $f8, $f18
  li    $at, 0x40C00000 # 6.000000
  mtc1  $at, $f10
  neg.s $f4, $f8
  mul.s $f0, $f4, $f16
  add.s $f6, $f0, $f0
  div.s $f12, $f6, $f10
.L7F060F9C:
  jal   sub_GAME_7F058570
   sw    $a0, 0x94($sp)
  lw    $a0, 0x94($sp)
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   addiu $a1, $sp, 0x1a4
  b     .L7F060FC4
   lw    $a2, 0x2a4($sp)
.L7F060FB8:
  jal   init_something_copy_posdata_to_it
   addiu $a1, $sp, 0x1a4
  lw    $a2, 0x2a4($sp)
.L7F060FC4:
  addiu $a0, $sp, 0x264
  addiu $a1, $sp, 0x1a4
  jal   matrix_4x4_multiply
   addiu $a2, $a2, 0x100
  lw    $v0, 0x10c($sp)
.L7F060FD8:
  beql  $v0, $zero, .L7F060FE8
   lw    $t9, 0x108($sp)
  sw    $zero, ($v0)
  lw    $t9, 0x108($sp)
.L7F060FE8:
  beql  $t9, $zero, .L7F0614F4
   lwc1  $f16, 0x260($s0)
  jal   get_random_value
   nop   
  mtc1  $v0, $f18
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F061014
   cvt.s.w $f8, $f18
  mtc1  $at, $f4
  nop   
  add.s $f8, $f8, $f4
.L7F061014:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f16
  li    $at, 0x3E800000 # 0.250000
  mtc1  $at, $f10
  mul.s $f6, $f8, $f16
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  lw    $t5, 0xf8($sp)
  lw    $a0, 0xfc($sp)
  li    $a1, 1
  mul.s $f18, $f6, $f10
  add.s $f8, $f18, $f4
  swc1  $f8, 0x80($sp)
  lwc1  $f16, ($t5)
  jal   check_special_attributes
   swc1  $f16, 0x7c($sp)
  beqz  $v0, .L7F0610B8
   lw    $a0, 0x108($sp)
  jal   get_random_value
   nop   
  mtc1  $v0, $f6
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F061080
   cvt.s.w $f10, $f6
  mtc1  $at, $f18
  nop   
  add.s $f10, $f10, $f18
.L7F061080:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f4
  lui   $at, %hi(D_80053E1C)
  lwc1  $f16, %lo(D_80053E1C)($at)
  mul.s $f8, $f10, $f4
  addiu $a1, $sp, 0x224
  mul.s $f12, $f8, $f16
  jal   sub_GAME_7F058688
   nop   
  lw    $a0, 0x108($sp)
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   addiu $a1, $sp, 0x224
  b     .L7F0610C4
   lwc1  $f12, 0x80($sp)
.L7F0610B8:
  jal   init_something_copy_posdata_to_it
   addiu $a1, $sp, 0x224
  lwc1  $f12, 0x80($sp)
.L7F0610C4:
  jal   matrix_multiply_A1_by_F12
   addiu $a1, $sp, 0x224
  lwc1  $f12, 0x7c($sp)
  jal   sub_GAME_7F058A14
   addiu $a1, $sp, 0x224
  addiu $a0, $sp, 0x264
  jal   matrix_4x4_multiply_in_place
   addiu $a1, $sp, 0x224
  lw    $a1, 0x2a4($sp)
  addiu $a0, $sp, 0x224
  jal   matrix_4x4_copy
   addiu $a1, $a1, 0x40
  lwc1  $f6, 0x254($sp)
  swc1  $f6, 0x2e8($s0)
  lwc1  $f18, 0x258($sp)
  swc1  $f18, 0x2ec($s0)
  lwc1  $f10, 0x25c($sp)
  jal   sub_GAME_7F078444
   swc1  $f10, 0x2f0($s0)
  move  $a0, $v0
  jal   sub_GAME_7F058474
   addiu $a1, $s0, 0x2e8
  lwc1  $f4, 0x25c($sp)
  lb    $t6, 0xd($s0)
  neg.s $f8, $f4
  beqz  $t6, .L7F0614E4
   swc1  $f8, 0x2f4($s0)
  lw    $t8, 0x10c($sp)
  li    $t7, 1
  beql  $t8, $zero, .L7F061148
   lw    $t9, 0x1a0($sp)
  sw    $t7, ($t8)
  lw    $t9, 0x1a0($sp)
.L7F061148:
  lw    $t5, 8($t9)
  lw    $v1, 8($t5)
  beql  $v1, $zero, .L7F061308
   lw    $t7, 0x1a0($sp)
  lw    $v0, 4($v1)
  lwc1  $f6, 0x224($sp)
  lwc1  $f4, 0x234($sp)
  lwc1  $f16, ($v0)
  lwc1  $f10, 4($v0)
  mul.s $f18, $f16, $f6
  lwc1  $f6, 8($v0)
  mul.s $f8, $f10, $f4
  lwc1  $f10, 0x244($sp)
  mul.s $f4, $f6, $f10
  add.s $f16, $f18, $f8
  lwc1  $f8, 0x254($sp)
  add.s $f18, $f16, $f4
  lwc1  $f16, 0x228($sp)
  add.s $f6, $f8, $f18
  lwc1  $f18, 0x238($sp)
  swc1  $f6, 0x84($sp)
  lwc1  $f10, ($v0)
  lwc1  $f8, 4($v0)
  mul.s $f4, $f10, $f16
  lwc1  $f16, 8($v0)
  mul.s $f6, $f8, $f18
  lwc1  $f8, 0x248($sp)
  mul.s $f18, $f16, $f8
  add.s $f10, $f4, $f6
  lwc1  $f6, 0x258($sp)
  add.s $f4, $f10, $f18
  lwc1  $f10, 0x22c($sp)
  add.s $f16, $f6, $f4
  lwc1  $f4, 0x23c($sp)
  swc1  $f16, 0x88($sp)
  lwc1  $f8, ($v0)
  lwc1  $f6, 4($v0)
  mul.s $f18, $f8, $f10
  lwc1  $f10, 8($v0)
  mul.s $f16, $f6, $f4
  lwc1  $f6, 0x24c($sp)
  mul.s $f4, $f10, $f6
  add.s $f8, $f18, $f16
  lwc1  $f16, 0x25c($sp)
  add.s $f18, $f8, $f4
  add.s $f10, $f16, $f18
  jal   get_random_value
   swc1  $f10, 0x8c($sp)
  mtc1  $v0, $f6
  addiu $a0, $sp, 0x1e4
  bgez  $v0, .L7F061228
   cvt.s.w $f8, $f6
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f4
  nop   
  add.s $f8, $f8, $f4
.L7F061228:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f16
  lui   $at, %hi(D_80053E20)
  lwc1  $f10, %lo(D_80053E20)($at)
  mul.s $f18, $f8, $f16
  lwc1  $f16, 0x88($sp)
  lwc1  $f4, 0x84($sp)
  neg.s $f8, $f4
  mul.s $f6, $f18, $f10
  lwc1  $f10, 0x8c($sp)
  neg.s $f18, $f16
  mfc1  $a2, $f8
  mfc1  $a3, $f18
  mfc1  $a1, $f6
  neg.s $f6, $f10
  jal   sub_GAME_7F059CE8
   swc1  $f6, 0x10($sp)
  lui   $at, %hi(D_80053E24)
  lwc1  $f4, %lo(D_80053E24)($at)
  lwc1  $f8, 0x80($sp)
  addiu $a1, $sp, 0x1e4
  mul.s $f12, $f4, $f8
  jal   matrix_multiply_A1_by_F12
   nop   
  lwc1  $f16, 0x194($sp)
  lwc1  $f18, 0x1c8($s0)
  lwc1  $f6, 0x198($sp)
  lwc1  $f4, 0x1cc($s0)
  sub.s $f10, $f16, $f18
  lwc1  $f18, 0x1d0($s0)
  lwc1  $f16, 0x19c($sp)
  sub.s $f8, $f6, $f4
  mfc1  $a2, $f10
  addiu $a0, $sp, 0x114
  sub.s $f10, $f16, $f18
  mfc1  $a3, $f8
  li    $a1, 0
  jal   sub_GAME_7F059B58
   swc1  $f10, 0x10($sp)
  addiu $a0, $sp, 0x114
  jal   matrix_4x4_multiply_in_place
   addiu $a1, $sp, 0x1e4
  lwc1  $f12, 0x7c($sp)
  jal   sub_GAME_7F058B80
   addiu $a1, $sp, 0x1e4
  addiu $a0, $sp, 0x154
  jal   matrix_4x4_multiply_in_place
   addiu $a1, $sp, 0x1e4
  addiu $a0, $sp, 0x84
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   addiu $a1, $sp, 0x1e4
  lw    $a1, 0x2a4($sp)
  addiu $a0, $sp, 0x1e4
  jal   matrix_4x4_copy
   addiu $a1, $a1, 0x80
  lw    $t7, 0x1a0($sp)
.L7F061308:
  lui   $t6, %hi(weapon_gun_kf7) 
  addiu $t6, %lo(weapon_gun_kf7) # addiu $t6, $t6, -0x3854
  lw    $t8, 4($t7)
  bnel  $t6, $t8, .L7F0614E8
   lw    $t8, 0x1a0($sp)
  lw    $t9, 8($t7)
  lw    $v1, 0x10($t9)
  beql  $v1, $zero, .L7F0614E8
   lw    $t8, 0x1a0($sp)
  lw    $v0, 4($v1)
  lwc1  $f4, 0x224($sp)
  lwc1  $f18, 0x234($sp)
  lwc1  $f6, ($v0)
  lwc1  $f16, 4($v0)
  lui   $at, %hi(D_80053E28)
  mul.s $f8, $f6, $f4
  lwc1  $f4, 8($v0)
  lw    $t5, 0x2a4($sp)
  mul.s $f10, $f16, $f18
  lwc1  $f16, 0x244($sp)
  addiu $t6, $t5, 0xc0
  mul.s $f18, $f4, $f16
  add.s $f6, $f8, $f10
  lwc1  $f10, 0x254($sp)
  add.s $f8, $f6, $f18
  lwc1  $f6, 0x228($sp)
  add.s $f4, $f10, $f8
  lwc1  $f8, 0x238($sp)
  swc1  $f4, 0x84($sp)
  lwc1  $f16, ($v0)
  lwc1  $f10, 4($v0)
  mul.s $f18, $f16, $f6
  lwc1  $f6, 8($v0)
  mul.s $f4, $f10, $f8
  lwc1  $f10, 0x248($sp)
  mul.s $f8, $f6, $f10
  add.s $f16, $f18, $f4
  lwc1  $f4, 0x258($sp)
  add.s $f18, $f16, $f8
  lwc1  $f16, 0x22c($sp)
  add.s $f6, $f4, $f18
  lwc1  $f18, 0x23c($sp)
  swc1  $f6, 0x88($sp)
  lwc1  $f10, ($v0)
  lwc1  $f4, 4($v0)
  mul.s $f8, $f10, $f16
  lwc1  $f16, 8($v0)
  sw    $t6, 0x40($sp)
  mul.s $f6, $f4, $f18
  lwc1  $f4, 0x24c($sp)
  mul.s $f18, $f16, $f4
  lwc1  $f4, %lo(D_80053E28)($at)
  add.s $f10, $f8, $f6
  lwc1  $f6, 0x25c($sp)
  add.s $f8, $f10, $f18
  lwc1  $f10, 0x80($sp)
  mul.s $f18, $f4, $f10
  add.s $f16, $f6, $f8
  swc1  $f16, 0x8c($sp)
  jal   get_random_value
   swc1  $f18, 0x38($sp)
  mtc1  $v0, $f6
  addiu $a0, $sp, 0x1e4
  bgez  $v0, .L7F06141C
   cvt.s.w $f8, $f6
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f16
  nop   
  add.s $f8, $f8, $f16
.L7F06141C:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f4
  lui   $at, %hi(D_80053E2C)
  lwc1  $f18, %lo(D_80053E2C)($at)
  mul.s $f10, $f8, $f4
  lwc1  $f4, 0x88($sp)
  lwc1  $f16, 0x84($sp)
  neg.s $f8, $f16
  mul.s $f6, $f10, $f18
  lwc1  $f18, 0x8c($sp)
  neg.s $f10, $f4
  mfc1  $a2, $f8
  mfc1  $a3, $f10
  mfc1  $a1, $f6
  neg.s $f6, $f18
  jal   sub_GAME_7F059CE8
   swc1  $f6, 0x10($sp)
  lwc1  $f12, 0x38($sp)
  jal   matrix_multiply_A1_by_F12
   addiu $a1, $sp, 0x1e4
  lwc1  $f16, 0x194($sp)
  lwc1  $f8, 0x1c8($s0)
  lwc1  $f10, 0x198($sp)
  lwc1  $f18, 0x1cc($s0)
  sub.s $f4, $f16, $f8
  lwc1  $f8, 0x1d0($s0)
  lwc1  $f16, 0x19c($sp)
  sub.s $f6, $f10, $f18
  mfc1  $a2, $f4
  addiu $a0, $sp, 0x114
  sub.s $f4, $f16, $f8
  mfc1  $a3, $f6
  li    $a1, 0
  jal   sub_GAME_7F059B58
   swc1  $f4, 0x10($sp)
  addiu $a0, $sp, 0x114
  jal   matrix_4x4_multiply_in_place
   addiu $a1, $sp, 0x1e4
  lwc1  $f12, 0x7c($sp)
  jal   sub_GAME_7F058B80
   addiu $a1, $sp, 0x1e4
  addiu $a0, $sp, 0x154
  jal   matrix_4x4_multiply_in_place
   addiu $a1, $sp, 0x1e4
  addiu $a0, $sp, 0x84
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   addiu $a1, $sp, 0x1e4
  addiu $a0, $sp, 0x1e4
  jal   matrix_4x4_copy
   lw    $a1, 0x40($sp)
.L7F0614E4:
  lw    $t8, 0x1a0($sp)
.L7F0614E8:
  b     .L7F06151C
   lw    $v0, 8($t8)
  lwc1  $f16, 0x260($s0)
.L7F0614F4:
  lwc1  $f10, 0x298($s0)
  lwc1  $f18, 0x29c($s0)
  lwc1  $f6, 0x2a0($s0)
  neg.s $f8, $f16
  swc1  $f10, 0x2e8($s0)
  swc1  $f8, 0x2f4($s0)
  swc1  $f18, 0x2ec($s0)
  swc1  $f6, 0x2f0($s0)
  lw    $t7, 0x1a0($sp)
  lw    $v0, 8($t7)
.L7F06151C:
  lw    $a0, 0x18($v0)
  beql  $a0, $zero, .L7F061630
   lw    $t5, 0x1a0($sp)
  lw    $t9, 4($a0)
  move  $a1, $zero
  jal   sub_GAME_7F06C570
   sw    $t9, 0x70($sp)
  sw    $v0, 0x6c($sp)
  lw    $a1, 0x10($s0)
  jal   sub_GAME_7F05E6B4
   lw    $a0, 0x2a8($sp)
  lw    $t5, 0x1a0($sp)
  lw    $a0, 0x70($sp)
  addiu $a2, $sp, 0x1a4
  lh    $t6, 0xc($t5)
  slti  $at, $t6, 0x1d
  bnez  $at, .L7F061608
   nop   
  lw    $t8, 8($t5)
  lw    $v1, 0x70($t8)
  beqz  $v1, .L7F061608
   nop   
  lw    $v0, 4($v1)
  lw    $a0, 0x2a8($sp)
  jal   get_value_if_watch_is_on_hand_or_not
   sw    $v0, 0x68($sp)
  lui   $at, %hi(D_80053E30)
  lwc1  $f10, %lo(D_80053E30)($at)
  lwc1  $f4, 0x214($s0)
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f16
  add.s $f18, $f4, $f10
  lui   $at, %hi(D_80053E34)
  lwc1  $f4, %lo(D_80053E34)($at)
  lw    $v0, 0x68($sp)
  sub.s $f6, $f18, $f0
  addiu $a0, $sp, 0x1a4
  lwc1  $f18, ($v0)
  mul.s $f8, $f6, $f16
  lwc1  $f6, 0xc($v0)
  sub.s $f16, $f18, $f6
  lwc1  $f6, 0x14($v0)
  lwc1  $f18, 8($v0)
  div.s $f10, $f8, $f4
  lwc1  $f4, 0x10($v0)
  lwc1  $f8, 4($v0)
  mfc1  $a2, $f16
  sub.s $f16, $f18, $f6
  swc1  $f16, 0x10($sp)
  mfc1  $a1, $f10
  sub.s $f10, $f8, $f4
  mfc1  $a3, $f10
  jal   guRotateF
   nop   
  lw    $a0, 0x70($sp)
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   addiu $a1, $sp, 0x1a4
  b     .L7F061614
   lw    $t7, 0x6c($sp)
.L7F061608:
  jal   sub_GAME_7F0584D0
   lw    $a1, 0x214($s0)
  lw    $t7, 0x6c($sp)
.L7F061614:
  lw    $t6, 0x2a4($sp)
  addiu $a0, $sp, 0x264
  sll   $t9, $t7, 6
  addiu $a1, $sp, 0x1a4
  jal   matrix_4x4_multiply_homogeneous
   addu  $a2, $t9, $t6
  lw    $t5, 0x1a0($sp)
.L7F061630:
  lw    $a0, 0x44($sp)
  lh    $t8, 0xc($t5)
  move  $a1, $t5
  slti  $at, $t8, 0x1e
  bnezl $at, .L7F061654
   lw    $t7, 0x1a0($sp)
  jal   seems_to_load_cuff_microcode
   li    $a2, 29
  lw    $t7, 0x1a0($sp)
.L7F061654:
  lw    $t9, 8($t7)
  lw    $a0, 0x1c($t9)
  beql  $a0, $zero, .L7F0616BC
   lw    $t9, 0x1a0($sp)
  lw    $t6, 4($a0)
  move  $a1, $zero
  jal   sub_GAME_7F06C570
   sw    $t6, 0x64($sp)
  sw    $v0, 0x60($sp)
  jal   sub_GAME_7F05E83C
   lw    $a0, 0x2a8($sp)
  lw    $a0, 0x64($sp)
  jal   init_something_copy_posdata_to_it
   addiu $a1, $sp, 0x1a4
  lwc1  $f8, 0x1dc($sp)
  lwc1  $f4, 0x218($s0)
  lw    $t8, 0x60($sp)
  lw    $t7, 0x2a4($sp)
  sub.s $f10, $f8, $f4
  sll   $t5, $t8, 6
  addiu $a0, $sp, 0x264
  addiu $a1, $sp, 0x1a4
  swc1  $f10, 0x1dc($sp)
  jal   matrix_4x4_multiply
   addu  $a2, $t5, $t7
  lw    $t9, 0x1a0($sp)
.L7F0616BC:
  move  $v1, $zero
  move  $a2, $zero
  lh    $t6, 0xc($t9)
  li    $a3, 5
  slti  $at, $t6, 0x13
  bnez  $at, .L7F06177C
   nop   
.L7F0616D8:
  lw    $t8, 0x1a0($sp)
  lw    $a0, 0x44($sp)
  lw    $t5, 8($t8)
  addu  $t7, $t5, $a2
  lw    $a1, 0x48($t7)
  beql  $a1, $zero, .L7F061728
   lw    $t5, 0x1a0($sp)
  sw    $v1, 0x5c($sp)
  jal   extract_id_from_object_structure_microcode
   sw    $a2, 0x40($sp)
  lw    $v1, 0x5c($sp)
  lw    $a2, 0x40($sp)
  beqz  $v0, .L7F061724
   li    $a3, 5
  lw    $t9, 0x34($s0)
  subu  $t6, $a3, $v1
  slt   $t8, $t9, $t6
  xori  $t8, $t8, 1
  sw    $t8, ($v0)
.L7F061724:
  lw    $t5, 0x1a0($sp)
.L7F061728:
  lw    $a0, 0x44($sp)
  lw    $t7, 8($t5)
  addu  $t9, $t7, $a2
  lw    $a1, 0x5c($t9)
  beql  $a1, $zero, .L7F061774
   addiu $v1, $v1, 1
  sw    $v1, 0x5c($sp)
  jal   extract_id_from_object_structure_microcode
   sw    $a2, 0x40($sp)
  lw    $v1, 0x5c($sp)
  lw    $a2, 0x40($sp)
  beqz  $v0, .L7F061770
   li    $a3, 5
  lw    $t6, 0x34($s0)
  subu  $t8, $a3, $v1
  slt   $t5, $t6, $t8
  xori  $t5, $t5, 1
  sw    $t5, ($v0)
.L7F061770:
  addiu $v1, $v1, 1
.L7F061774:
  bne   $v1, $a3, .L7F0616D8
   addiu $a2, $a2, 4
.L7F06177C:
  jal   sub_GAME_7F06EFC4
   lw    $a0, 0x44($sp)
  lb    $t7, 0xc($s0)
  lw    $t9, 0xfc($sp)
  beqz  $t7, .L7F0617D4
   addiu $t6, $t9, -4
  sltiu $at, $t6, 0x14
  beqz  $at, .L7F0617D4
   sll   $t6, $t6, 2
  lui   $at, %hi(jpt_weapon_bullet_type)
  addu  $at, $at, $t6
  lw    $t6, %lo(jpt_weapon_bullet_type)($at)
  jr    $t6
   nop   
weapon_bullet_type_pistol:
  jal   sub_GAME_7F061BF4
   lw    $a0, 0x2a8($sp)
  lw    $t8, 0x30($s0)
  addiu $t5, $t8, 1
  b     .L7F0617D4
   sw    $t5, 0x30($s0)
weapon_bullet_type_none:
  jal   sub_GAME_7F061BF4
   lw    $a0, 0x2a8($sp)
weapon_bullet_type_shotgun_mine:
.L7F0617D4:
  lw    $t7, 0xfc($sp)
.L7F0617D8:
  li    $at, 25
  bnel  $t7, $at, .L7F0617F0
   lb    $t9, 0xc($s0)
  jal   sub_GAME_7F05F928
   lw    $a0, 0x2a8($sp)
  lb    $t9, 0xc($s0)
.L7F0617F0:
  lui   $a0, %hi(pPlayer)
  beql  $t9, $zero, .L7F061910
   lw    $ra, 0x34($sp)
  jal   sub_GAME_7F089778
   lw    $a0, %lo(pPlayer)($a0)
  mfc1  $a1, $f0
  jal   sub_GAME_7F068508
   lw    $a0, 0x2a8($sp)
  lw    $t6, 0xfc($sp)
  li    $at, 24
  lw    $t8, 0xfc($sp)
  bnel  $t6, $at, .L7F061838
   li    $at, 26
  jal   sub_GAME_7F05F73C
   lw    $a0, 0x2a8($sp)
  b     .L7F061910
   lw    $ra, 0x34($sp)
  li    $at, 26
.L7F061838:
  bne   $t8, $at, .L7F061850
   lw    $t5, 0xfc($sp)
  jal   sub_GAME_7F05EE24
   lw    $a0, 0x2a8($sp)
  b     .L7F061910
   lw    $ra, 0x34($sp)
.L7F061850:
  li    $at, 25
  bne   $t5, $at, .L7F06186C
   lw    $t7, 0xfc($sp)
  jal   sub_GAME_7F05FB64
   lw    $a0, 0x2a8($sp)
  b     .L7F061910
   lw    $ra, 0x34($sp)
.L7F06186C:
  li    $at, 3
  bne   $t7, $at, .L7F061888
   lw    $t9, 0xfc($sp)
  jal   sub_GAME_7F05F09C
   lw    $a0, 0x2a8($sp)
  b     .L7F061910
   lw    $ra, 0x34($sp)
.L7F061888:
  li    $at, 29
  beq   $t9, $at, .L7F0618CC
   li    $at, 28
  beq   $t9, $at, .L7F0618CC
   li    $at, 27
  beq   $t9, $at, .L7F0618CC
   li    $at, 33
  beq   $t9, $at, .L7F0618CC
   li    $at, 47
  beq   $t9, $at, .L7F0618CC
   li    $at, 48
  beq   $t9, $at, .L7F0618CC
   li    $at, 61
  beq   $t9, $at, .L7F0618CC
   li    $at, 34
  bne   $t9, $at, .L7F0618DC
   lw    $t6, 0xfc($sp)
.L7F0618CC:
  jal   generate_player_thrown_object
   lw    $a0, 0x2a8($sp)
  b     .L7F061910
   lw    $ra, 0x34($sp)
.L7F0618DC:
  li    $at, 35
  bne   $t6, $at, .L7F0618F8
   lw    $t8, 0xfc($sp)
  jal   sub_GAME_7F05F73C
   lw    $a0, 0x2a8($sp)
  b     .L7F061910
   lw    $ra, 0x34($sp)
.L7F0618F8:
  li    $at, 36
  bnel  $t8, $at, .L7F061910
   lw    $ra, 0x34($sp)
  jal   sub_GAME_7F05F73C
   lw    $a0, 0x2a8($sp)
  lw    $ra, 0x34($sp)
.L7F061910:
  lw    $s0, 0x30($sp)
  addiu $sp, $sp, 0x2a8
  jr    $ra
   nop   
");

#ifdef VERSION_JP
asm(R"
.late_rodata
glabel D_80053DE0
.word 0x3f733333 /*0.94999999*/
glabel D_80053DE4
.word 0x3d4cccd0 /*0.050000012*/
glabel D_80053DE8
.word 0x3f19999a /*0.60000002*/
glabel D_80053DEC
.word 0x3e99999a /*0.30000001*/
glabel D_80053DF0
.word 0x3f19999a /*0.60000002*/
glabel D_80053DF4
.word 0x3e99999a /*0.30000001*/
glabel D_80053DF8
.word 0x3f19999a /*0.60000002*/
glabel D_80053DFC
.word 0x3e99999a /*0.30000001*/
glabel D_80053E00
.word 0x41de6666 /*27.799999*/
glabel D_80053E04
.word 0x3dccccce /*0.10000001*/
glabel D_80053E08
.word 0x40c90fdb /*6.2831855*/
glabel D_80053E0C
.word 0x40c90fdb /*6.2831855*/
glabel D_80053E10
.word 0x40c90fdb /*6.2831855*/
glabel D_80053E14
.word 0x3f060a92 /*0.52359879*/
glabel D_80053E18
.word 0x3f060a92 /*0.52359879*/
glabel D_80053E1C
.word 0x40c90fdb /*6.2831855*/
glabel D_80053E20
.word 0x40c90fdb /*6.2831855*/
glabel D_80053E24
.word 0x3dccccce /*0.10000001*/
glabel D_80053E28
.word 0x3dccccce /*0.10000001*/
glabel D_80053E2C
.word 0x40c90fdb /*6.2831855*/
glabel D_80053E30
.word 0x40c90fdb /*6.2831855*/
glabel D_80053E34
.word 0x40c90fdb /*6.2831855*/

/*D:80053E38*/
glabel jpt_weapon_bullet_type
.word weapon_bullet_type_pistol
.word weapon_bullet_type_pistol
.word weapon_bullet_type_pistol
.word weapon_bullet_type_pistol
.word weapon_bullet_type_pistol
.word weapon_bullet_type_pistol
.word weapon_bullet_type_pistol
.word weapon_bullet_type_pistol
.word weapon_bullet_type_pistol
.word weapon_bullet_type_pistol
.word weapon_bullet_type_pistol
.word weapon_bullet_type_shotgun_mine
.word weapon_bullet_type_shotgun_mine
.word weapon_bullet_type_pistol
.word weapon_bullet_type_pistol
.word weapon_bullet_type_pistol
.word weapon_bullet_type_pistol
.word weapon_bullet_type_pistol
.word weapon_bullet_type_none
.word weapon_bullet_type_none
.text
glabel handles_firing_or_throwing_weapon_in_hand
  addiu $sp, $sp, -0x2a8
  lui   $t7, %hi(D_80035C40) # $t7, 0x8003
  sw    $ra, 0x34($sp)
  sw    $s0, 0x30($sp)
  addiu $t7, %lo(D_80035C40) # addiu $t7, $t7, 0x5c80
  lw    $at, ($t7)
  addiu $t6, $sp, 0x194
  lw    $t5, 4($t7)
  sw    $at, ($t6)
  lw    $at, 8($t7)
  sll   $t8, $a0, 3
  subu  $t8, $t8, $a0
  sll   $t8, $t8, 2
  addu  $t8, $t8, $a0
  lui   $t9, %hi(pPlayer) # $t9, 0x8008
  sw    $t5, 4($t6)
  sw    $at, 8($t6)
  lw    $t9, %lo(pPlayer)($t9)
  sll   $t8, $t8, 2
  addu  $t8, $t8, $a0
  sll   $t8, $t8, 3
  addu  $s0, $t9, $t8
  sw    $zero, 0x10c($sp)
  sw    $zero, 0x108($sp)
  addiu $s0, $s0, 0x870
  jal   return_ammo_in_hand
   sw    $a0, 0x2a8($sp)
  sw    $v0, 0xfc($sp)
  jal   get_ptr_item_statistics
   move  $a0, $v0
  lw    $t6, 0x2a8($sp)
  sw    $v0, 0xf8($sp)
  bnez  $t6, .Ljp7F060620
   nop   
  jal   return_ammo_in_hand
   li    $a0, 1
  move  $a0, $v0
  jal   check_special_attributes
   li    $a1, 2048
  beqz  $v0, .Ljp7F0605DC
   lui   $at, %hi(global_timer_delta)
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  lwc1  $f0, %lo(global_timer_delta)($at)
  li    $at, 0x43700000 # 240.000000
  mtc1  $at, $f6
  add.s $f4, $f0, $f0
  lwc1  $f10, 0x1c4($s0)
  li    $at, 0x40000000 # 2.000000
  mtc1  $at, $f18
  div.s $f8, $f4, $f6
  li    $at, 0x40000000 # 2.000000
  add.s $f16, $f10, $f8
  swc1  $f16, 0x1c4($s0)
  lwc1  $f4, 0x1c4($s0)
  c.lt.s $f18, $f4
  nop   
  bc1f  .Ljp7F0606C8
   nop   
  mtc1  $at, $f6
  b     .Ljp7F0606C8
   swc1  $f6, 0x1c4($s0)
.Ljp7F0605DC:
  lwc1  $f0, %lo(global_timer_delta)($at)
  li    $at, 0x43700000 # 240.000000
  mtc1  $at, $f8
  add.s $f10, $f0, $f0
  lwc1  $f18, 0x1c4($s0)
  div.s $f16, $f10, $f8
  mtc1  $zero, $f10
  sub.s $f4, $f18, $f16
  swc1  $f4, 0x1c4($s0)
  lwc1  $f6, 0x1c4($s0)
  c.lt.s $f6, $f10
  nop   
  bc1f  .Ljp7F0606C8
   nop   
  mtc1  $zero, $f8
  b     .Ljp7F0606C8
   swc1  $f8, 0x1c4($s0)
.Ljp7F060620:
  jal   return_ammo_in_hand
   move  $a0, $zero
  move  $a0, $v0
  jal   check_special_attributes
   li    $a1, 2048
  beqz  $v0, .Ljp7F060684
   lui   $at, %hi(global_timer_delta)
  li    $at, 0xC0000000 # -2.000000
  mtc1  $at, $f2
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  lwc1  $f0, %lo(global_timer_delta)($at)
  li    $at, 0x43700000 # 240.000000
  mtc1  $at, $f16
  add.s $f18, $f0, $f0
  lwc1  $f6, 0x1c4($s0)
  div.s $f4, $f18, $f16
  sub.s $f10, $f6, $f4
  swc1  $f10, 0x1c4($s0)
  lwc1  $f8, 0x1c4($s0)
  c.lt.s $f8, $f2
  nop   
  bc1f  .Ljp7F0606C8
   nop   
  b     .Ljp7F0606C8
   swc1  $f2, 0x1c4($s0)
.Ljp7F060684:
  lwc1  $f0, %lo(global_timer_delta)($at)
  li    $at, 0x43700000 # 240.000000
  mtc1  $at, $f16
  add.s $f18, $f0, $f0
  lwc1  $f4, 0x1c4($s0)
  mtc1  $zero, $f8
  div.s $f6, $f18, $f16
  add.s $f10, $f4, $f6
  swc1  $f10, 0x1c4($s0)
  lwc1  $f18, 0x1c4($s0)
  c.lt.s $f8, $f18
  nop   
  bc1f  .Ljp7F0606C8
   nop   
  mtc1  $zero, $f16
  nop   
  swc1  $f16, 0x1c4($s0)
.Ljp7F0606C8:
  lui   $t7, %hi(D_80035C4C) # $t7, 0x8003
  addiu $t7, %lo(D_80035C4C) # addiu $t7, $t7, 0x5c8c
  lw    $at, ($t7)
  addiu $t4, $sp, 0xe0
  lui   $t6, %hi(D_80035C58) # $t6, 0x8003
  sw    $at, ($t4)
  lw    $t9, 4($t7)
  addiu $t6, %lo(D_80035C58) # addiu $t6, $t6, 0x5c98
  addiu $t8, $sp, 0xd4
  sw    $t9, 4($t4)
  lw    $at, 8($t7)
  lui   $t5, %hi(D_80035C64) # $t5, 0x8003
  addiu $t5, %lo(D_80035C64) # addiu $t5, $t5, 0x5ca4
  sw    $at, 8($t4)
  lw    $at, ($t6)
  lw    $t7, 4($t6)
  addiu $t9, $sp, 0xc8
  sw    $at, ($t8)
  lw    $at, 8($t6)
  sw    $t7, 4($t8)
  li    $v1, 12
  sw    $at, 8($t8)
  lw    $at, ($t5)
  lw    $t6, 4($t5)
  sw    $at, ($t9)
  lw    $at, 8($t5)
  sw    $t6, 4($t9)
  sw    $at, 8($t9)
  lw    $v0, 0x198($s0)
  lwc1  $f4, 0x19c($s0)
  sw    $t4, 0x14($sp)
  addiu $t7, $v0, 3
  bgez  $t7, .Ljp7F06075C
   andi  $t8, $t7, 3
  beqz  $t8, .Ljp7F06075C
   nop   
  addiu $t8, $t8, -4
.Ljp7F06075C:
  multu $t8, $v1
  addiu $t6, $v0, 1
  swc1  $f4, 0x10($sp)
  mflo  $t9
  addu  $t0, $s0, $t9
  addiu $t9, $v0, 2
  multu $v0, $v1
  addiu $a0, $t0, 0x108
  sw    $t0, 0x44($sp)
  mflo  $t5
  addu  $t1, $s0, $t5
  addiu $a1, $t1, 0x108
  bgez  $t6, .Ljp7F0607A0
   andi  $t7, $t6, 3
  beqz  $t7, .Ljp7F0607A0
   nop   
  addiu $t7, $t7, -4
.Ljp7F0607A0:
  multu $t7, $v1
  sw    $t1, 0x40($sp)
  mflo  $t8
  addu  $t2, $s0, $t8
  addiu $a2, $t2, 0x108
  bgez  $t9, .Ljp7F0607C8
   andi  $t5, $t9, 3
  beqz  $t5, .Ljp7F0607C8
   nop   
  addiu $t5, $t5, -4
.Ljp7F0607C8:
  multu $t5, $v1
  sw    $t2, 0x3c($sp)
  mflo  $t6
  addu  $t3, $s0, $t6
  addiu $a3, $t3, 0x108
  jal   sub_GAME_7F05AEFC
   sw    $t3, 0x38($sp)
  lw    $a0, 0x44($sp)
  lw    $a1, 0x40($sp)
  lw    $a2, 0x3c($sp)
  lw    $a3, 0x38($sp)
  lwc1  $f6, 0x19c($s0)
  addiu $t7, $sp, 0xd4
  sw    $t7, 0x14($sp)
  addiu $a0, $a0, 0x138
  addiu $a1, $a1, 0x138
  addiu $a2, $a2, 0x138
  addiu $a3, $a3, 0x138
  jal   sub_GAME_7F05AEFC
   swc1  $f6, 0x10($sp)
  lw    $a0, 0x44($sp)
  lw    $a1, 0x40($sp)
  lw    $a2, 0x3c($sp)
  lw    $a3, 0x38($sp)
  lwc1  $f10, 0x19c($s0)
  addiu $t8, $sp, 0xc8
  sw    $t8, 0x14($sp)
  addiu $a0, $a0, 0x168
  addiu $a1, $a1, 0x168
  addiu $a2, $a2, 0x168
  addiu $a3, $a3, 0x168
  jal   sub_GAME_7F05AEFC
   swc1  $f10, 0x10($sp)
  lui   $v0, %hi(pPlayer) # $v0, 0x8008
  lw    $v0, %lo(pPlayer)($v0)
  lwc1  $f8, 0xe0($sp)
  lwc1  $f4, 0xe4($sp)
  lwc1  $f18, 0xfc0($v0)
  lw    $a0, 0x2a8($sp)
  mul.s $f16, $f8, $f18
  lwc1  $f8, 0xe8($sp)
  swc1  $f16, 0xe0($sp)
  lwc1  $f6, 0xfc0($v0)
  mul.s $f10, $f4, $f6
  swc1  $f10, 0xe4($sp)
  lwc1  $f18, 0xfc0($v0)
  mul.s $f4, $f8, $f18
  swc1  $f4, 0xe8($sp)
  lwc1  $f6, 0x1ac($s0)
  add.s $f8, $f16, $f6
  swc1  $f8, 0xe0($sp)
  lwc1  $f18, 0x1b0($s0)
  add.s $f4, $f10, $f18
  jal   sub_GAME_7F05DCB8
   swc1  $f4, 0xe4($sp)
  lwc1  $f16, 0xe0($sp)
  lui   $v0, %hi(clock_timer) # $v0, 0x8005
  addiu $v0, %lo(clock_timer) # addiu $v0, $v0, -0x7c5c
  add.s $f6, $f16, $f0
  lw    $t9, ($v0)
  move  $v1, $zero
  blez  $t9, .Ljp7F060994
   swc1  $f6, 0xe0($sp)
  lui   $at, %hi(D_80053DE0) # $at, 0x8005
  lwc1  $f0, %lo(D_80053DE0)($at)
  lwc1  $f10, 0xe4($s0)
.Ljp7F0608D0:
  lwc1  $f8, 0xe0($sp)
  lwc1  $f6, 0xe8($s0)
  mul.s $f18, $f0, $f10
  addiu $v1, $v1, 1
  mul.s $f10, $f0, $f6
  add.s $f4, $f8, $f18
  swc1  $f4, 0xe4($s0)
  lwc1  $f16, 0xe4($sp)
  lwc1  $f4, 0xec($s0)
  add.s $f8, $f16, $f10
  mul.s $f6, $f0, $f4
  swc1  $f8, 0xe8($s0)
  lwc1  $f18, 0xe8($sp)
  lwc1  $f8, 0xf0($s0)
  add.s $f16, $f18, $f6
  mul.s $f4, $f0, $f8
  swc1  $f16, 0xec($s0)
  lwc1  $f10, 0xd4($sp)
  lwc1  $f16, 0xf4($s0)
  add.s $f18, $f10, $f4
  mul.s $f8, $f0, $f16
  swc1  $f18, 0xf0($s0)
  lwc1  $f6, 0xd8($sp)
  lwc1  $f18, 0xf8($s0)
  add.s $f10, $f6, $f8
  mul.s $f16, $f0, $f18
  swc1  $f10, 0xf4($s0)
  lwc1  $f4, 0xdc($sp)
  lwc1  $f10, 0xfc($s0)
  add.s $f6, $f4, $f16
  mul.s $f18, $f0, $f10
  swc1  $f6, 0xf8($s0)
  lwc1  $f8, 0xc8($sp)
  lwc1  $f6, 0x100($s0)
  add.s $f4, $f8, $f18
  mul.s $f10, $f0, $f6
  swc1  $f4, 0xfc($s0)
  lwc1  $f16, 0xcc($sp)
  lwc1  $f4, 0x104($s0)
  add.s $f8, $f16, $f10
  mul.s $f6, $f0, $f4
  swc1  $f8, 0x100($s0)
  lwc1  $f18, 0xd0($sp)
  add.s $f16, $f18, $f6
  swc1  $f16, 0x104($s0)
  lw    $t5, ($v0)
  slt   $at, $v1, $t5
  bnezl $at, .Ljp7F0608D0
   lwc1  $f10, 0xe4($s0)
.Ljp7F060994:
  lui   $at, %hi(D_80053DE4) # $at, 0x8005
  lwc1  $f0, %lo(D_80053DE4)($at)
  lwc1  $f10, 0xe4($s0)
  lwc1  $f4, 0xe8($s0)
  lwc1  $f6, 0xec($s0)
  mul.s $f8, $f10, $f0
  lwc1  $f10, 0xf0($s0)
  lw    $a0, 0x2a8($sp)
  mul.s $f18, $f4, $f0
  lwc1  $f4, 0xf4($s0)
  mul.s $f16, $f6, $f0
  swc1  $f8, 0xc0($s0)
  lwc1  $f6, 0xf8($s0)
  mul.s $f8, $f10, $f0
  swc1  $f18, 0xc4($s0)
  lwc1  $f10, 0xfc($s0)
  mul.s $f18, $f4, $f0
  swc1  $f16, 0xc8($s0)
  lwc1  $f4, 0x100($s0)
  mul.s $f16, $f6, $f0
  swc1  $f8, 0xcc($s0)
  lwc1  $f6, 0x104($s0)
  mul.s $f8, $f10, $f0
  swc1  $f18, 0xd0($s0)
  mul.s $f18, $f4, $f0
  swc1  $f16, 0xd4($s0)
  mul.s $f16, $f6, $f0
  swc1  $f8, 0xd8($s0)
  swc1  $f18, 0xdc($s0)
  bnez  $a0, .Ljp7F060A30
   swc1  $f16, 0xe0($s0)
  jal   sub_GAME_7F05DCE8
   nop   
  lwc1  $f8, 0xc0($s0)
  lwc1  $f10, 0x1b8($s0)
  add.s $f4, $f0, $f8
  add.s $f18, $f10, $f4
  b     .Ljp7F060A4C
   swc1  $f18, 0x194($sp)
.Ljp7F060A30:
  jal   sub_GAME_7F05DCE8
   nop   
  lwc1  $f6, 0xc0($s0)
  lwc1  $f8, 0x1b8($s0)
  add.s $f16, $f0, $f6
  sub.s $f10, $f16, $f8
  swc1  $f10, 0x194($sp)
.Ljp7F060A4C:
  lw    $t6, 0xf8($sp)
  lwc1  $f18, 0xc4($s0)
  lwc1  $f16, 0x1bc($s0)
  lwc1  $f4, 8($t6)
  lw    $a0, 0xfc($sp)
  li    $at, 25
  add.s $f6, $f4, $f18
  add.s $f8, $f16, $f6
  swc1  $f8, 0x198($sp)
  lwc1  $f4, 0xc8($s0)
  lwc1  $f10, 0xc($t6)
  lwc1  $f16, 0x1c0($s0)
  add.s $f18, $f10, $f4
  add.s $f6, $f16, $f18
  beq   $a0, $at, .Ljp7F060A9C
   swc1  $f6, 0x19c($sp)
  li    $at, 30
  beq   $a0, $at, .Ljp7F060A9C
   li    $at, 23
  bne   $a0, $at, .Ljp7F060B3C
.Ljp7F060A9C:
   lui   $v0, %hi(pPlayer) # $v0, 0x8008
  lw    $v0, %lo(pPlayer)($v0)
  li    $at, 0xC2C80000 # -100.000000
  mtc1  $at, $f0
  lwc1  $f10, 0xa0($v0)
  lwc1  $f8, 0x198($sp)
  li    $at, 0x40400000 # 3.000000
  div.s $f4, $f10, $f0
  mtc1  $at, $f18
  li    $at, 25
  add.s $f16, $f8, $f4
  lwc1  $f4, 0x19c($sp)
  swc1  $f16, 0x198($sp)
  lwc1  $f6, 0xa0($v0)
  mul.s $f10, $f18, $f6
  div.s $f8, $f10, $f0
  add.s $f16, $f4, $f8
  bne   $a0, $at, .Ljp7F060B34
   swc1  $f16, 0x19c($sp)
  jal   cur_player_get_screen_setting
   nop   
  li    $at, 1
  beql  $v0, $at, .Ljp7F060B24
   lui   $at, 0x4040
  jal   cur_player_get_screen_setting
   nop   
  li    $at, 2
  beql  $v0, $at, .Ljp7F060B24
   lui   $at, 0x4040
  jal   get_screen_ratio
   nop   
  li    $at, 1
  bne   $v0, $at, .Ljp7F060B34
   li    $at, 0x40400000 # 3.000000
.Ljp7F060B24:
  mtc1  $at, $f6
  lwc1  $f18, 0x198($sp)
  sub.s $f10, $f18, $f6
  swc1  $f10, 0x198($sp)
.Ljp7F060B34:
  b     .Ljp7F060BE8
   lw    $a0, 0xfc($sp)
.Ljp7F060B3C:
  li    $at, 31
  bne   $a0, $at, .Ljp7F060B9C
   lui   $v0, %hi(pPlayer)
  lui   $v0, %hi(pPlayer) # $v0, 0x8008
  lw    $v0, %lo(pPlayer)($v0)
  li    $at, 0xC2C80000 # -100.000000
  mtc1  $at, $f0
  li    $at, 0x40200000 # 2.500000
  mtc1  $at, $f4
  lwc1  $f8, 0xa0($v0)
  lwc1  $f6, 0x198($sp)
  li    $at, 0x40F00000 # 7.500000
  mul.s $f16, $f4, $f8
  mtc1  $at, $f4
  div.s $f18, $f16, $f0
  add.s $f10, $f6, $f18
  lwc1  $f18, 0x19c($sp)
  swc1  $f10, 0x198($sp)
  lwc1  $f8, 0xa0($v0)
  mul.s $f16, $f4, $f8
  div.s $f6, $f16, $f0
  add.s $f10, $f18, $f6
  b     .Ljp7F060BE8
   swc1  $f10, 0x19c($sp)
.Ljp7F060B9C:
  lw    $v0, %lo(pPlayer)($v0)
  li    $at, 0xC2C80000 # -100.000000
  mtc1  $at, $f0
  li    $at, 0x40A00000 # 5.000000
  mtc1  $at, $f4
  lwc1  $f8, 0xa0($v0)
  lwc1  $f6, 0x198($sp)
  li    $at, 0x41700000 # 15.000000
  mul.s $f16, $f4, $f8
  mtc1  $at, $f4
  div.s $f18, $f16, $f0
  add.s $f10, $f6, $f18
  lwc1  $f18, 0x19c($sp)
  swc1  $f10, 0x198($sp)
  lwc1  $f8, 0xa0($v0)
  mul.s $f16, $f4, $f8
  div.s $f6, $f16, $f0
  add.s $f10, $f18, $f6
  swc1  $f10, 0x19c($sp)
.Ljp7F060BE8:
  lb    $t7, 0xc($s0)
  beqz  $t7, .Ljp7F060D0C
   nop   
  jal   check_special_attributes
   li    $a1, 32
  beqz  $v0, .Ljp7F060D0C
   lw    $a0, 0xfc($sp)
  jal   check_special_attributes
   li    $a1, 64
  beqz  $v0, .Ljp7F060C68
   nop   
  jal   get_random_value
   nop   
  mtc1  $v0, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .Ljp7F060C38
   cvt.s.w $f8, $f4
  mtc1  $at, $f16
  nop   
  add.s $f8, $f8, $f16
.Ljp7F060C38:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f18
  lui   $at, %hi(D_80053DE8) # $at, 0x8005
  lwc1  $f10, %lo(D_80053DE8)($at)
  mul.s $f6, $f8, $f18
  lui   $at, %hi(D_80053DEC) # $at, 0x8005
  lwc1  $f16, %lo(D_80053DEC)($at)
  lwc1  $f18, 0x194($sp)
  mul.s $f4, $f6, $f10
  sub.s $f8, $f16, $f4
  add.s $f6, $f18, $f8
  swc1  $f6, 0x194($sp)
.Ljp7F060C68:
  jal   get_random_value
   nop   
  mtc1  $v0, $f10
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .Ljp7F060C8C
   cvt.s.w $f16, $f10
  mtc1  $at, $f4
  nop   
  add.s $f16, $f16, $f4
.Ljp7F060C8C:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f18
  lui   $at, %hi(D_80053DF0) # $at, 0x8005
  lwc1  $f6, %lo(D_80053DF0)($at)
  mul.s $f8, $f16, $f18
  lui   $at, %hi(D_80053DF4) # $at, 0x8005
  lwc1  $f4, %lo(D_80053DF4)($at)
  lwc1  $f18, 0x198($sp)
  mul.s $f10, $f8, $f6
  sub.s $f16, $f4, $f10
  add.s $f8, $f18, $f16
  jal   get_random_value
   swc1  $f8, 0x198($sp)
  mtc1  $v0, $f6
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .Ljp7F060CDC
   cvt.s.w $f4, $f6
  mtc1  $at, $f10
  nop   
  add.s $f4, $f4, $f10
.Ljp7F060CDC:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f18
  lui   $at, %hi(D_80053DF8) # $at, 0x8005
  lwc1  $f8, %lo(D_80053DF8)($at)
  mul.s $f16, $f4, $f18
  lui    $at, %hi(D_80053DFC)
  lwc1  $f10, %lo(D_80053DFC)($at)
  lwc1  $f18, 0x19c($sp)
  mul.s $f6, $f16, $f8
  sub.s $f4, $f10, $f6
  add.s $f16, $f18, $f4
  swc1  $f16, 0x19c($sp)
.Ljp7F060D0C:
  jal   getPlayer_c_screenwidth
   nop   
  jal   getPlayer_c_screenwidth
   swc1  $f0, 0x48($sp)
  jal   getPlayer_c_screenleft
   swc1  $f0, 0x4c($sp)
  li    $at, 0x3F000000 # 0.500000
  lui   $t8, %hi(pPlayer) # $t8, 0x8008
  lw    $t8, %lo(pPlayer)($t8)
  mtc1  $at, $f2
  lwc1  $f6, 0x4c($sp)
  lwc1  $f8, 0xffc($t8)
  lw    $t9, 0xf8($sp)
  mul.s $f18, $f6, $f2
  sub.s $f10, $f8, $f0
  lwc1  $f16, 0x18($t9)
  lwc1  $f6, 0x48($sp)
  sub.s $f4, $f10, $f18
  mul.s $f8, $f4, $f16
  lwc1  $f4, 0x194($sp)
  mul.s $f10, $f6, $f2
  div.s $f18, $f8, $f10
  add.s $f16, $f4, $f18
  jal   getPlayer_c_screentop
   swc1  $f16, 0x194($sp)
  jal   getPlayer_c_screenheight
   swc1  $f0, 0x50($sp)
  li    $at, 0x3F000000 # 0.500000
  lui   $t5, %hi(pPlayer) # $t5, 0x8008
  lw    $t5, %lo(pPlayer)($t5)
  mtc1  $at, $f6
  lwc1  $f4, 0x50($sp)
  lwc1  $f10, 0x1000($t5)
  mul.s $f8, $f0, $f6
  sub.s $f18, $f10, $f4
  c.lt.s $f8, $f18
  nop   
  bc1f  .Ljp7F060E0C
   nop   
  jal   getPlayer_c_screenheight
   nop   
  jal   getPlayer_c_screenheight
   swc1  $f0, 0x48($sp)
  jal   getPlayer_c_screentop
   swc1  $f0, 0x4c($sp)
  li    $at, 0x3F000000 # 0.500000
  lui   $t6, %hi(pPlayer) # $t6, 0x8008
  lw    $t6, %lo(pPlayer)($t6)
  mtc1  $at, $f2
  lwc1  $f10, 0x4c($sp)
  lwc1  $f16, 0x1000($t6)
  lw    $t7, 0xf8($sp)
  mul.s $f4, $f10, $f2
  sub.s $f6, $f16, $f0
  lwc1  $f18, 0x14($t7)
  lwc1  $f10, 0x48($sp)
  sub.s $f8, $f6, $f4
  mul.s $f16, $f8, $f18
  lwc1  $f8, 0x198($sp)
  mul.s $f6, $f10, $f2
  div.s $f4, $f16, $f6
  sub.s $f18, $f8, $f4
  b     .Ljp7F060E70
   swc1  $f18, 0x198($sp)
.Ljp7F060E0C:
  jal   getPlayer_c_screenheight
   nop   
  jal   getPlayer_c_screenheight
   swc1  $f0, 0x48($sp)
  jal   getPlayer_c_screentop
   swc1  $f0, 0x4c($sp)
  li    $at, 0x3F000000 # 0.500000
  lui   $t8, %hi(pPlayer) # $t8, 0x8008
  lw    $t8, %lo(pPlayer)($t8)
  mtc1  $at, $f16
  lwc1  $f10, 0x4c($sp)
  lwc1  $f8, 0x1000($t8)
  lw    $t9, 0xf8($sp)
  mul.s $f6, $f10, $f16
  sub.s $f4, $f8, $f0
  lwc1  $f10, 0x10($t9)
  lwc1  $f8, 0x48($sp)
  sub.s $f18, $f4, $f6
  mtc1  $at, $f4
  mul.s $f16, $f18, $f10
  lwc1  $f10, 0x198($sp)
  mul.s $f6, $f8, $f4
  div.s $f18, $f16, $f6
  sub.s $f8, $f10, $f18
  swc1  $f8, 0x198($sp)
.Ljp7F060E70:
  jal   sub_GAME_7F05C614
   nop   
  jal   matrix_4x4_set_identity
   addiu $a0, $sp, 0x154
  lw    $v0, 0xfc($sp)
  li    $at, 30
  beq   $v0, $at, .Ljp7F060E94
   li    $at, 23
  bne   $v0, $at, .Ljp7F060ED4
.Ljp7F060E94:
   lui   $t5, %hi(D_80035C70) # $t5, 0x8003
  addiu $t5, %lo(D_80035C70) # addiu $t5, $t5, 0x5cb0
  lw    $at, ($t5)
  addiu $a0, $sp, 0xb8
  addiu $a1, $sp, 0x1a4
  sw    $at, ($a0)
  lw    $t7, 4($t5)
  sw    $t7, 4($a0)
  lw    $at, 8($t5)
  jal   sub_GAME_7F058714
   sw    $at, 8($a0)
  addiu $a0, $sp, 0x1a4
  jal   matrix_4x4_multiply_homogeneous_in_place
   addiu $a1, $sp, 0x154
  b     .Ljp7F060FB4
   lw    $t5, 0xbc($s0)
.Ljp7F060ED4:
  li    $at, 31
  bne   $v0, $at, .Ljp7F060F1C
   lui   $t8, %hi(D_80035C7C) # $t8, 0x8003
  addiu $t8, %lo(D_80035C7C) # addiu $t8, $t8, 0x5cbc
  lw    $at, ($t8)
  addiu $a0, $sp, 0xac
  addiu $a1, $sp, 0x1a4
  sw    $at, ($a0)
  lw    $t6, 4($t8)
  sw    $t6, 4($a0)
  lw    $at, 8($t8)
  jal   sub_GAME_7F058714
   sw    $at, 8($a0)
  addiu $a0, $sp, 0x1a4
  jal   matrix_4x4_multiply_homogeneous_in_place
   addiu $a1, $sp, 0x154
  b     .Ljp7F060FB4
   lw    $t5, 0xbc($s0)
.Ljp7F060F1C:
  li    $at, 1
  bne   $v0, $at, .Ljp7F060FB0
   lui   $t5, %hi(pPlayer) # $t5, 0x8008
  lw    $t5, %lo(pPlayer)($t5)
  li    $at, 17
  lui   $t9, %hi(D_80035C88) # $t9, 0x8003
  lw    $t7, 0x2a38($t5)
  addiu $t9, %lo(D_80035C88) # addiu $t9, $t9, 0x5cc8
  bnel  $t7, $at, .Ljp7F060FB4
   lw    $t5, 0xbc($s0)
  lw    $at, ($t9)
  addiu $a0, $sp, 0xa0
  addiu $a1, $sp, 0x1a4
  sw    $at, ($a0)
  lw    $t6, 4($t9)
  sw    $t6, 4($a0)
  lw    $at, 8($t9)
  jal   sub_GAME_7F058714
   sw    $at, 8($a0)
  addiu $a0, $sp, 0x1a4
  jal   matrix_4x4_multiply_homogeneous_in_place
   addiu $a1, $sp, 0x154
  li    $at, 0xC0200000 # -2.500000
  mtc1  $at, $f16
  lwc1  $f4, 0x194($sp)
  lui   $at, %hi(D_80053E00) # $at, 0x8005
  lwc1  $f18, %lo(D_80053E00)($at)
  add.s $f6, $f4, $f16
  li    $at, 0x40000000 # 2.000000
  lwc1  $f10, 0x198($sp)
  mtc1  $at, $f16
  lwc1  $f4, 0x19c($sp)
  swc1  $f6, 0x194($sp)
  add.s $f8, $f10, $f18
  add.s $f6, $f4, $f16
  swc1  $f8, 0x198($sp)
  swc1  $f6, 0x19c($sp)
.Ljp7F060FB0:
  lw    $t5, 0xbc($s0)
.Ljp7F060FB4:
  beql  $t5, $zero, .Ljp7F061014
   mtc1  $zero, $f4
  lwc1  $f10, 0x194($sp)
  lwc1  $f18, 0xac($s0)
  lwc1  $f4, 0x198($sp)
  addiu $a0, $s0, 0x7c
  add.s $f8, $f10, $f18
  lwc1  $f10, 0x19c($sp)
  addiu $a1, $sp, 0x154
  swc1  $f8, 0x194($sp)
  lwc1  $f16, 0xb0($s0)
  add.s $f6, $f4, $f16
  swc1  $f6, 0x198($sp)
  lwc1  $f18, 0xb4($s0)
  add.s $f8, $f10, $f18
  jal   matrix_4x4_multiply_homogeneous_in_place
   swc1  $f8, 0x19c($sp)
  mtc1  $zero, $f0
  nop   
  swc1  $f0, 0x184($sp)
  swc1  $f0, 0x188($sp)
  b     .Ljp7F061034
   swc1  $f0, 0x18c($sp)
  mtc1  $zero, $f4
.Ljp7F061014:
  mtc1  $zero, $f16
  mtc1  $zero, $f6
  mtc1  $zero, $f10
  mtc1  $zero, $f0
  swc1  $f4, 0x78($s0)
  swc1  $f16, 0x6c($s0)
  swc1  $f6, 0x70($s0)
  swc1  $f10, 0x74($s0)
.Ljp7F061034:
  lwc1  $f18, 0xcc($s0)
  mfc1  $a1, $f0
  mfc1  $a2, $f0
  swc1  $f18, 0x10($sp)
  lwc1  $f8, 0xd0($s0)
  mfc1  $a3, $f0
  addiu $a0, $sp, 0x1a4
  swc1  $f8, 0x14($sp)
  lwc1  $f4, 0xd4($s0)
  swc1  $f4, 0x18($sp)
  lwc1  $f16, 0xd8($s0)
  swc1  $f16, 0x1c($sp)
  lwc1  $f6, 0xdc($s0)
  swc1  $f6, 0x20($sp)
  lwc1  $f10, 0xe0($s0)
  jal   sub_GAME_7F059908
   swc1  $f10, 0x24($sp)
  addiu $a0, $sp, 0x1a4
  jal   matrix_4x4_multiply_homogeneous_in_place
   addiu $a1, $sp, 0x154
  lwc1  $f18, 0x194($sp)
  lwc1  $f8, 0x1c8($s0)
  lwc1  $f16, 0x198($sp)
  lwc1  $f6, 0x1cc($s0)
  sub.s $f4, $f18, $f8
  lwc1  $f8, 0x1d0($s0)
  lwc1  $f18, 0x19c($sp)
  sub.s $f10, $f16, $f6
  mfc1  $a2, $f4
  addiu $a0, $sp, 0x1a4
  sub.s $f4, $f18, $f8
  mfc1  $a3, $f10
  li    $a1, 0
  jal   sub_GAME_7F059CE8
   swc1  $f4, 0x10($sp)
  addiu $a0, $sp, 0x1a4
  jal   matrix_4x4_multiply_homogeneous_in_place
   addiu $a1, $sp, 0x154
  addiu $a0, $sp, 0x154
  jal   matrix_4x4_copy
   addiu $a1, $sp, 0x264
  addiu $a0, $sp, 0x194
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   addiu $a1, $sp, 0x264
  addiu $a1, $s0, 0x228
  sw    $a1, 0x44($sp)
  jal   matrix_4x4_copy
   addiu $a0, $sp, 0x264
  addiu $a0, $s0, 0x268
  sw    $a0, 0x40($sp)
  jal   matrix_4x4_copy
   addiu $a1, $s0, 0x2a8
  jal   sub_GAME_7F078444
   nop   
  move  $a0, $v0
  lw    $a1, 0x44($sp)
  jal   matrix_4x4_multiply_homogeneous
   lw    $a2, 0x40($sp)
  li    $t7, 1
  sb    $t7, 0xf($s0)
  jal   get_ptr_weapon_model_header_line
   lw    $a0, 0xfc($sp)
  beqz  $v0, .Ljp7F06118C
   lw    $a0, 0xfc($sp)
  jal   check_special_attributes
   li    $a1, 2048
  beqz  $v0, .Ljp7F06118C
   lw    $a0, 0xfc($sp)
  jal   check_special_attributes
   li    $a1, 8192
  bnezl $v0, .Ljp7F061190
   sb    $zero, 0xf($s0)
  lw    $v0, 0x24($s0)
  li    $at, 6
  beq   $v0, $at, .Ljp7F06118C
   li    $at, 7
  beql  $v0, $at, .Ljp7F061190
   sb    $zero, 0xf($s0)
  jal   sub_GAME_7F05CEBC
   lw    $a0, 0x2a8($sp)
  beql  $v0, $zero, .Ljp7F061190
   sb    $zero, 0xf($s0)
  jal   get_itemtype_in_hand
   lw    $a0, 0x2a8($sp)
  bnezl $v0, .Ljp7F061194
   lw    $t8, 0x2c($s0)
.Ljp7F06118C:
  sb    $zero, 0xf($s0)
.Ljp7F061190:
  lw    $t8, 0x2c($s0)
.Ljp7F061194:
  lw    $a0, 0xfc($sp)
  bgtzl $t8, .Ljp7F0611B8
   lb    $t9, 0xf($s0)
  jal   check_special_attributes
   li    $a1, 2
  beql  $v0, $zero, .Ljp7F0611B8
   lb    $t9, 0xf($s0)
  sb    $zero, 0xf($s0)
  lb    $t9, 0xf($s0)
.Ljp7F0611B8:
  lui   $t6, %hi(pPlayer) 
  lw    $t5, 0x2a8($sp)
  beql  $t9, $zero, .Ljp7F061D04
   lw    $t6, 0xfc($sp)
  lw    $t6, %lo(pPlayer)($t6)
  sll   $t7, $t5, 5
  move  $v1, $zero
  addu  $v0, $t6, $t7
  lh    $a0, 0x81e($v0)
  addiu $v0, $v0, 0x810
  sw    $v0, 0x1a0($sp)
  sll   $t8, $a0, 6
  move  $a0, $t8
  jal   sub_GAME_7F0BD714
   sw    $zero, 0x100($sp)
  lw    $t9, 0x1a0($sp)
  sw    $v0, 0x2a4($sp)
  lw    $v1, 0x100($sp)
  lh    $t5, 0xe($t9)
  blez  $t5, .Ljp7F06123C
   move  $a0, $v0
  sw    $v1, 0x100($sp)
.Ljp7F061210:
  jal   matrix_4x4_set_identity
   sw    $a0, 0x44($sp)
  lw    $t6, 0x1a0($sp)
  lw    $v1, 0x100($sp)
  lw    $a0, 0x44($sp)
  lh    $t7, 0xe($t6)
  addiu $v1, $v1, 1
  addiu $a0, $a0, 0x40
  slt   $at, $v1, $t7
  bnezl $at, .Ljp7F061210
   sw    $v1, 0x100($sp)
.Ljp7F06123C:
  jal   set_objuse_flag_compute_grp_nums_set_obj_loaded
   lw    $a0, 0x1a0($sp)
  addiu $a0, $s0, 0x2f8
  lw    $a1, 0x1a0($sp)
  sw    $a0, 0x44($sp)
  jal   sub_GAME_7F075F68
   addiu $a2, $s0, 0x318
  lw    $a0, 0x44($sp)
  jal   sub_GAME_7F05E978
   li    $a1, 1
  lw    $a0, 0x44($sp)
  jal   sub_GAME_7F05EA94
   lb    $a1, 0xe($s0)
  lw    $t8, 0x1a0($sp)
  lw    $v0, 8($t8)
  lw    $a0, 4($v0)
  beql  $a0, $zero, .Ljp7F0612A0
   lw    $v1, 0xc($v0)
  lw    $v1, 4($a0)
  lhu   $t9, 4($v1)
  sll   $t5, $t9, 2
  addu  $t6, $s0, $t5
  addiu $t7, $t6, 0x318
  sw    $t7, 0x10c($sp)
  lw    $v1, 0xc($v0)
.Ljp7F0612A0:
  beql  $v1, $zero, .Ljp7F0612B4
   lw    $t9, 0x2a4($sp)
  lw    $t8, 4($v1)
  sw    $t8, 0x108($sp)
  lw    $t9, 0x2a4($sp)
.Ljp7F0612B4:
  li    $a1, 1024
  sw    $t9, 0x304($s0)
  jal   check_special_attributes
   lw    $a0, 0xfc($sp)
  beqz  $v0, .Ljp7F0612E8
   nop   
  lw    $t5, 0x2a8($sp)
  li    $at, 1
  bne   $t5, $at, .Ljp7F0612E8
   li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f12
  jal   sub_GAME_7F0589B4
   addiu $a1, $sp, 0x264
.Ljp7F0612E8:
  lui   $at, %hi(D_80053E04) # $at, 0x8005
  lwc1  $f12, %lo(D_80053E04)($at)
  jal   matrix_multiply_A1_by_F12
   addiu $a1, $sp, 0x264
  addiu $a0, $sp, 0x264
  jal   matrix_4x4_copy
   lw    $a1, 0x2a4($sp)
  lw    $t7, 0x1a0($sp)
  lui   $t6, %hi(weapon_gun_revolver) # $t6, 0x8004
  addiu $t6, %lo(weapon_gun_revolver) # addiu $t6, $t6, -0x3864
  lw    $t8, 4($t7)
  bnel  $t6, $t8, .Ljp7F0614F8
   lw    $v0, 0x10c($sp)
  lw    $v0, 8($t7)
  lw    $t9, 0xfc($sp)
  li    $at, 18
  lw    $v1, 0x10($v0)
  addiu $a1, $sp, 0x1a4
  beql  $v1, $zero, .Ljp7F061438
   lw    $v1, 0x14($v0)
  mtc1  $zero, $f12
  bne   $t9, $at, .Ljp7F0613C4
   lw    $a0, 4($v1)
  lw    $t5, 0x24($s0)
  li    $at, 1
  bnel  $t5, $at, .Ljp7F061398
   lw    $t8, 0x2c($s0)
  lw    $t8, 0x2c($s0)
  lw    $t6, 0x20($s0)
  lui   $at, %hi(D_80053E08) # $at, 0x8005
  sll   $t7, $t8, 2
  subu  $t7, $t7, $t8
  sll   $t7, $t7, 1
  subu  $t9, $t6, $t7
  addiu $t5, $t9, 0x1e
  mtc1  $t5, $f16
  lwc1  $f10, %lo(D_80053E08)($at)
  li    $at, 0x42100000 # 36.000000
  cvt.s.w $f6, $f16
  mtc1  $at, $f8
  mul.s $f18, $f6, $f10
  b     .Ljp7F061404
   div.s $f12, $f18, $f8
  lw    $t8, 0x2c($s0)
.Ljp7F061398:
  li    $t6, 6
  lui   $at, %hi(D_80053E0C) # $at, 0x8005
  subu  $t7, $t6, $t8
  mtc1  $t7, $f4
  lwc1  $f6, %lo(D_80053E0C)($at)
  li    $at, 0x40C00000 # 6.000000
  cvt.s.w $f16, $f4
  mtc1  $at, $f18
  mul.s $f10, $f16, $f6
  b     .Ljp7F061404
   div.s $f12, $f10, $f18
.Ljp7F0613C4:
  lw    $t9, 0x24($s0)
  li    $at, 1
  bne   $t9, $at, .Ljp7F061404
   nop   
  lw    $v0, 0x20($s0)
  slti  $at, $v0, 6
  beqz  $at, .Ljp7F061404
   nop   
  mtc1  $v0, $f8
  lui   $at, %hi(D_80053E10) # $at, 0x8005
  lwc1  $f16, %lo(D_80053E10)($at)
  cvt.s.w $f4, $f8
  li    $at, 0x42100000 # 36.000000
  mtc1  $at, $f10
  mul.s $f6, $f4, $f16
  div.s $f12, $f6, $f10
.Ljp7F061404:
  jal   sub_GAME_7F058688
   sw    $a0, 0x9c($sp)
  lw    $a0, 0x9c($sp)
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   addiu $a1, $sp, 0x1a4
  lw    $a2, 0x2a4($sp)
  addiu $a0, $sp, 0x264
  addiu $a1, $sp, 0x1a4
  jal   matrix_4x4_multiply
   addiu $a2, $a2, 0xc0
  lw    $t5, 0x1a0($sp)
  lw    $v0, 8($t5)
  lw    $v1, 0x14($v0)
.Ljp7F061438:
  beql  $v1, $zero, .Ljp7F0614F8
   lw    $v0, 0x10c($sp)
  lw    $t6, 0x24($s0)
  li    $at, 1
  lw    $a0, 4($v1)
  bne   $t6, $at, .Ljp7F0614D8
   addiu $a1, $sp, 0x1a4
  lw    $v0, 0x20($s0)
  li    $t8, 6
  slti  $at, $v0, 3
  beqz  $at, .Ljp7F061494
   subu  $t7, $t8, $v0
  mtc1  $v0, $f18
  lui   $at, %hi(D_80053E14) # $at, 0x8005
  lwc1  $f16, %lo(D_80053E14)($at)
  cvt.s.w $f8, $f18
  li    $at, 0x40C00000 # 6.000000
  mtc1  $at, $f10
  neg.s $f4, $f8
  mul.s $f0, $f4, $f16
  add.s $f6, $f0, $f0
  b     .Ljp7F0614BC
   div.s $f12, $f6, $f10
.Ljp7F061494:
  mtc1  $t7, $f18
  lui   $at, %hi(D_80053E18) # $at, 0x8005
  lwc1  $f16, %lo(D_80053E18)($at)
  cvt.s.w $f8, $f18
  li    $at, 0x40C00000 # 6.000000
  mtc1  $at, $f10
  neg.s $f4, $f8
  mul.s $f0, $f4, $f16
  add.s $f6, $f0, $f0
  div.s $f12, $f6, $f10
.Ljp7F0614BC:
  jal   sub_GAME_7F058570
   sw    $a0, 0x94($sp)
  lw    $a0, 0x94($sp)
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   addiu $a1, $sp, 0x1a4
  b     .Ljp7F0614E4
   lw    $a2, 0x2a4($sp)
.Ljp7F0614D8:
  jal   init_something_copy_posdata_to_it
   addiu $a1, $sp, 0x1a4
  lw    $a2, 0x2a4($sp)
.Ljp7F0614E4:
  addiu $a0, $sp, 0x264
  addiu $a1, $sp, 0x1a4
  jal   matrix_4x4_multiply
   addiu $a2, $a2, 0x100
  lw    $v0, 0x10c($sp)
.Ljp7F0614F8:
  beql  $v0, $zero, .Ljp7F061508
   lw    $t9, 0x108($sp)
  sw    $zero, ($v0)
  lw    $t9, 0x108($sp)
.Ljp7F061508:
  beql  $t9, $zero, .Ljp7F061A14
   lwc1  $f16, 0x260($s0)
  jal   get_random_value
   nop   
  mtc1  $v0, $f18
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .Ljp7F061534
   cvt.s.w $f8, $f18
  mtc1  $at, $f4
  nop   
  add.s $f8, $f8, $f4
.Ljp7F061534:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f16
  li    $at, 0x3E800000 # 0.250000
  mtc1  $at, $f10
  mul.s $f6, $f8, $f16
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  lw    $t5, 0xf8($sp)
  lw    $a0, 0xfc($sp)
  li    $a1, 1
  mul.s $f18, $f6, $f10
  add.s $f8, $f18, $f4
  swc1  $f8, 0x80($sp)
  lwc1  $f16, ($t5)
  jal   check_special_attributes
   swc1  $f16, 0x7c($sp)
  beqz  $v0, .Ljp7F0615D8
   lw    $a0, 0x108($sp)
  jal   get_random_value
   nop   
  mtc1  $v0, $f6
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .Ljp7F0615A0
   cvt.s.w $f10, $f6
  mtc1  $at, $f18
  nop   
  add.s $f10, $f10, $f18
.Ljp7F0615A0:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f4
  lui   $at, %hi(D_80053E1C) # $at, 0x8005
  lwc1  $f16, %lo(D_80053E1C)($at)
  mul.s $f8, $f10, $f4
  addiu $a1, $sp, 0x224
  mul.s $f12, $f8, $f16
  jal   sub_GAME_7F058688
   nop   
  lw    $a0, 0x108($sp)
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   addiu $a1, $sp, 0x224
  b     .Ljp7F0615E4
   lwc1  $f12, 0x80($sp)
.Ljp7F0615D8:
  jal   init_something_copy_posdata_to_it
   addiu $a1, $sp, 0x224
  lwc1  $f12, 0x80($sp)
.Ljp7F0615E4:
  jal   matrix_multiply_A1_by_F12
   addiu $a1, $sp, 0x224
  lwc1  $f12, 0x7c($sp)
  jal   sub_GAME_7F058A14
   addiu $a1, $sp, 0x224
  addiu $a0, $sp, 0x264
  jal   matrix_4x4_multiply_in_place
   addiu $a1, $sp, 0x224
  lw    $a1, 0x2a4($sp)
  addiu $a0, $sp, 0x224
  jal   matrix_4x4_copy
   addiu $a1, $a1, 0x40
  lwc1  $f6, 0x254($sp)
  swc1  $f6, 0x2e8($s0)
  lwc1  $f18, 0x258($sp)
  swc1  $f18, 0x2ec($s0)
  lwc1  $f10, 0x25c($sp)
  jal   sub_GAME_7F078444
   swc1  $f10, 0x2f0($s0)
  move  $a0, $v0
  jal   sub_GAME_7F058474
   addiu $a1, $s0, 0x2e8
  lwc1  $f4, 0x25c($sp)
  lb    $t6, 0xd($s0)
  neg.s $f8, $f4
  beqz  $t6, .Ljp7F061A04
   swc1  $f8, 0x2f4($s0)
  lw    $t8, 0x10c($sp)
  li    $t7, 1
  beql  $t8, $zero, .Ljp7F061668
   lw    $t9, 0x1a0($sp)
  sw    $t7, ($t8)
  lw    $t9, 0x1a0($sp)
.Ljp7F061668:
  lw    $t5, 8($t9)
  lw    $v1, 8($t5)
  beql  $v1, $zero, .Ljp7F061828
   lw    $t7, 0x1a0($sp)
  lw    $v0, 4($v1)
  lwc1  $f6, 0x224($sp)
  lwc1  $f4, 0x234($sp)
  lwc1  $f16, ($v0)
  lwc1  $f10, 4($v0)
  mul.s $f18, $f16, $f6
  lwc1  $f6, 8($v0)
  mul.s $f8, $f10, $f4
  lwc1  $f10, 0x244($sp)
  mul.s $f4, $f6, $f10
  add.s $f16, $f18, $f8
  lwc1  $f8, 0x254($sp)
  add.s $f18, $f16, $f4
  lwc1  $f16, 0x228($sp)
  add.s $f6, $f8, $f18
  lwc1  $f18, 0x238($sp)
  swc1  $f6, 0x84($sp)
  lwc1  $f10, ($v0)
  lwc1  $f8, 4($v0)
  mul.s $f4, $f10, $f16
  lwc1  $f16, 8($v0)
  mul.s $f6, $f8, $f18
  lwc1  $f8, 0x248($sp)
  mul.s $f18, $f16, $f8
  add.s $f10, $f4, $f6
  lwc1  $f6, 0x258($sp)
  add.s $f4, $f10, $f18
  lwc1  $f10, 0x22c($sp)
  add.s $f16, $f6, $f4
  lwc1  $f4, 0x23c($sp)
  swc1  $f16, 0x88($sp)
  lwc1  $f8, ($v0)
  lwc1  $f6, 4($v0)
  mul.s $f18, $f8, $f10
  lwc1  $f10, 8($v0)
  mul.s $f16, $f6, $f4
  lwc1  $f6, 0x24c($sp)
  mul.s $f4, $f10, $f6
  add.s $f8, $f18, $f16
  lwc1  $f16, 0x25c($sp)
  add.s $f18, $f8, $f4
  add.s $f10, $f16, $f18
  jal   get_random_value
   swc1  $f10, 0x8c($sp)
  mtc1  $v0, $f6
  addiu $a0, $sp, 0x1e4
  bgez  $v0, .Ljp7F061748
   cvt.s.w $f8, $f6
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f4
  nop   
  add.s $f8, $f8, $f4
.Ljp7F061748:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f16
  lui   $at, %hi(D_80053E20) # $at, 0x8005
  lwc1  $f10, %lo(D_80053E20)($at)
  mul.s $f18, $f8, $f16
  lwc1  $f16, 0x88($sp)
  lwc1  $f4, 0x84($sp)
  neg.s $f8, $f4
  mul.s $f6, $f18, $f10
  lwc1  $f10, 0x8c($sp)
  neg.s $f18, $f16
  mfc1  $a2, $f8
  mfc1  $a3, $f18
  mfc1  $a1, $f6
  neg.s $f6, $f10
  jal   sub_GAME_7F059CE8
   swc1  $f6, 0x10($sp)
  lui   $at, %hi(D_80053E24) # $at, 0x8005
  lwc1  $f4, %lo(D_80053E24)($at)
  lwc1  $f8, 0x80($sp)
  addiu $a1, $sp, 0x1e4
  mul.s $f12, $f4, $f8
  jal   matrix_multiply_A1_by_F12
   nop   
  lwc1  $f16, 0x194($sp)
  lwc1  $f18, 0x1c8($s0)
  lwc1  $f6, 0x198($sp)
  lwc1  $f4, 0x1cc($s0)
  sub.s $f10, $f16, $f18
  lwc1  $f18, 0x1d0($s0)
  lwc1  $f16, 0x19c($sp)
  sub.s $f8, $f6, $f4
  mfc1  $a2, $f10
  addiu $a0, $sp, 0x114
  sub.s $f10, $f16, $f18
  mfc1  $a3, $f8
  li    $a1, 0
  jal   sub_GAME_7F059B58
   swc1  $f10, 0x10($sp)
  addiu $a0, $sp, 0x114
  jal   matrix_4x4_multiply_in_place
   addiu $a1, $sp, 0x1e4
  lwc1  $f12, 0x7c($sp)
  jal   sub_GAME_7F058B80
   addiu $a1, $sp, 0x1e4
  addiu $a0, $sp, 0x154
  jal   matrix_4x4_multiply_in_place
   addiu $a1, $sp, 0x1e4
  addiu $a0, $sp, 0x84
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   addiu $a1, $sp, 0x1e4
  lw    $a1, 0x2a4($sp)
  addiu $a0, $sp, 0x1e4
  jal   matrix_4x4_copy
   addiu $a1, $a1, 0x80
  lw    $t7, 0x1a0($sp)
.Ljp7F061828:
  lui   $t6, %hi(weapon_gun_kf7) # $t6, 0x8004
  addiu $t6, %lo(weapon_gun_kf7) # addiu $t6, $t6, -0x3824
  lw    $t8, 4($t7)
  bnel  $t6, $t8, .Ljp7F061A08
   lw    $t8, 0x1a0($sp)
  lw    $t9, 8($t7)
  lw    $v1, 0x10($t9)
  beql  $v1, $zero, .Ljp7F061A08
   lw    $t8, 0x1a0($sp)
  lw    $v0, 4($v1)
  lwc1  $f4, 0x224($sp)
  lwc1  $f18, 0x234($sp)
  lwc1  $f6, ($v0)
  lwc1  $f16, 4($v0)
  lui   $at, %hi(D_80053E28) # $at, 0x8005
  mul.s $f8, $f6, $f4
  lwc1  $f4, 8($v0)
  lw    $t5, 0x2a4($sp)
  mul.s $f10, $f16, $f18
  lwc1  $f16, 0x244($sp)
  addiu $t6, $t5, 0xc0
  mul.s $f18, $f4, $f16
  add.s $f6, $f8, $f10
  lwc1  $f10, 0x254($sp)
  add.s $f8, $f6, $f18
  lwc1  $f6, 0x228($sp)
  add.s $f4, $f10, $f8
  lwc1  $f8, 0x238($sp)
  swc1  $f4, 0x84($sp)
  lwc1  $f16, ($v0)
  lwc1  $f10, 4($v0)
  mul.s $f18, $f16, $f6
  lwc1  $f6, 8($v0)
  mul.s $f4, $f10, $f8
  lwc1  $f10, 0x248($sp)
  mul.s $f8, $f6, $f10
  add.s $f16, $f18, $f4
  lwc1  $f4, 0x258($sp)
  add.s $f18, $f16, $f8
  lwc1  $f16, 0x22c($sp)
  add.s $f6, $f4, $f18
  lwc1  $f18, 0x23c($sp)
  swc1  $f6, 0x88($sp)
  lwc1  $f10, ($v0)
  lwc1  $f4, 4($v0)
  mul.s $f8, $f10, $f16
  lwc1  $f16, 8($v0)
  sw    $t6, 0x40($sp)
  mul.s $f6, $f4, $f18
  lwc1  $f4, 0x24c($sp)
  mul.s $f18, $f16, $f4
  lwc1  $f4, %lo(D_80053E28)($at)
  add.s $f10, $f8, $f6
  lwc1  $f6, 0x25c($sp)
  add.s $f8, $f10, $f18
  lwc1  $f10, 0x80($sp)
  mul.s $f18, $f4, $f10
  add.s $f16, $f6, $f8
  swc1  $f16, 0x8c($sp)
  jal   get_random_value
   swc1  $f18, 0x38($sp)
  mtc1  $v0, $f6
  addiu $a0, $sp, 0x1e4
  bgez  $v0, .Ljp7F06193C
   cvt.s.w $f8, $f6
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f16
  nop   
  add.s $f8, $f8, $f16
.Ljp7F06193C:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f4
  lui   $at, %hi(D_80053E2C) # $at, 0x8005
  lwc1  $f18, %lo(D_80053E2C)($at)
  mul.s $f10, $f8, $f4
  lwc1  $f4, 0x88($sp)
  lwc1  $f16, 0x84($sp)
  neg.s $f8, $f16
  mul.s $f6, $f10, $f18
  lwc1  $f18, 0x8c($sp)
  neg.s $f10, $f4
  mfc1  $a2, $f8
  mfc1  $a3, $f10
  mfc1  $a1, $f6
  neg.s $f6, $f18
  jal   sub_GAME_7F059CE8
   swc1  $f6, 0x10($sp)
  lwc1  $f12, 0x38($sp)
  jal   matrix_multiply_A1_by_F12
   addiu $a1, $sp, 0x1e4
  lwc1  $f16, 0x194($sp)
  lwc1  $f8, 0x1c8($s0)
  lwc1  $f10, 0x198($sp)
  lwc1  $f18, 0x1cc($s0)
  sub.s $f4, $f16, $f8
  lwc1  $f8, 0x1d0($s0)
  lwc1  $f16, 0x19c($sp)
  sub.s $f6, $f10, $f18
  mfc1  $a2, $f4
  addiu $a0, $sp, 0x114
  sub.s $f4, $f16, $f8
  mfc1  $a3, $f6
  li    $a1, 0
  jal   sub_GAME_7F059B58
   swc1  $f4, 0x10($sp)
  addiu $a0, $sp, 0x114
  jal   matrix_4x4_multiply_in_place
   addiu $a1, $sp, 0x1e4
  lwc1  $f12, 0x7c($sp)
  jal   sub_GAME_7F058B80
   addiu $a1, $sp, 0x1e4
  addiu $a0, $sp, 0x154
  jal   matrix_4x4_multiply_in_place
   addiu $a1, $sp, 0x1e4
  addiu $a0, $sp, 0x84
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   addiu $a1, $sp, 0x1e4
  addiu $a0, $sp, 0x1e4
  jal   matrix_4x4_copy
   lw    $a1, 0x40($sp)
.Ljp7F061A04:
  lw    $t8, 0x1a0($sp)
.Ljp7F061A08:
  b     .Ljp7F061A3C
   lw    $v0, 8($t8)
  lwc1  $f16, 0x260($s0)
.Ljp7F061A14:
  lwc1  $f10, 0x298($s0)
  lwc1  $f18, 0x29c($s0)
  lwc1  $f6, 0x2a0($s0)
  neg.s $f8, $f16
  swc1  $f10, 0x2e8($s0)
  swc1  $f8, 0x2f4($s0)
  swc1  $f18, 0x2ec($s0)
  swc1  $f6, 0x2f0($s0)
  lw    $t7, 0x1a0($sp)
  lw    $v0, 8($t7)
.Ljp7F061A3C:
  lw    $a0, 0x18($v0)
  beql  $a0, $zero, .Ljp7F061B50
   lw    $t5, 0x1a0($sp)
  lw    $t9, 4($a0)
  move  $a1, $zero
  jal   sub_GAME_7F06C570
   sw    $t9, 0x70($sp)
  sw    $v0, 0x6c($sp)
  lw    $a1, 0x10($s0)
  jal   sub_GAME_7F05E6B4
   lw    $a0, 0x2a8($sp)
  lw    $t5, 0x1a0($sp)
  lw    $a0, 0x70($sp)
  addiu $a2, $sp, 0x1a4
  lh    $t6, 0xc($t5)
  slti  $at, $t6, 0x1d
  bnez  $at, .Ljp7F061B28
   nop   
  lw    $t8, 8($t5)
  lw    $v1, 0x70($t8)
  beqz  $v1, .Ljp7F061B28
   nop   
  lw    $v0, 4($v1)
  lw    $a0, 0x2a8($sp)
  jal   get_value_if_watch_is_on_hand_or_not
   sw    $v0, 0x68($sp)
  lui   $at, %hi(D_80053E30) # $at, 0x8005
  lwc1  $f10, %lo(D_80053E30)($at)
  lwc1  $f4, 0x214($s0)
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f16
  add.s $f18, $f4, $f10
  lui   $at, %hi(D_80053E34) # $at, 0x8005
  lwc1  $f4, %lo(D_80053E34)($at)
  lw    $v0, 0x68($sp)
  sub.s $f6, $f18, $f0
  addiu $a0, $sp, 0x1a4
  lwc1  $f18, ($v0)
  mul.s $f8, $f6, $f16
  lwc1  $f6, 0xc($v0)
  sub.s $f16, $f18, $f6
  lwc1  $f6, 0x14($v0)
  lwc1  $f18, 8($v0)
  div.s $f10, $f8, $f4
  lwc1  $f4, 0x10($v0)
  lwc1  $f8, 4($v0)
  mfc1  $a2, $f16
  sub.s $f16, $f18, $f6
  swc1  $f16, 0x10($sp)
  mfc1  $a1, $f10
  sub.s $f10, $f8, $f4
  mfc1  $a3, $f10
  jal   guRotateF
   nop   
  lw    $a0, 0x70($sp)
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   addiu $a1, $sp, 0x1a4
  b     .Ljp7F061B34
   lw    $t7, 0x6c($sp)
.Ljp7F061B28:
  jal   sub_GAME_7F0584D0
   lw    $a1, 0x214($s0)
  lw    $t7, 0x6c($sp)
.Ljp7F061B34:
  lw    $t6, 0x2a4($sp)
  addiu $a0, $sp, 0x264
  sll   $t9, $t7, 6
  addiu $a1, $sp, 0x1a4
  jal   matrix_4x4_multiply_homogeneous
   addu  $a2, $t9, $t6
  lw    $t5, 0x1a0($sp)
.Ljp7F061B50:
  lw    $a0, 0x44($sp)
  lh    $t8, 0xc($t5)
  move  $a1, $t5
  slti  $at, $t8, 0x1e
  bnezl $at, .Ljp7F061B74
   lw    $t7, 0x1a0($sp)
  jal   seems_to_load_cuff_microcode
   li    $a2, 29
  lw    $t7, 0x1a0($sp)
.Ljp7F061B74:
  lw    $t9, 8($t7)
  lw    $a0, 0x1c($t9)
  beql  $a0, $zero, .Ljp7F061BDC
   lw    $t9, 0x1a0($sp)
  lw    $t6, 4($a0)
  move  $a1, $zero
  jal   sub_GAME_7F06C570
   sw    $t6, 0x64($sp)
  sw    $v0, 0x60($sp)
  jal   sub_GAME_7F05E83C
   lw    $a0, 0x2a8($sp)
  lw    $a0, 0x64($sp)
  jal   init_something_copy_posdata_to_it
   addiu $a1, $sp, 0x1a4
  lwc1  $f8, 0x1dc($sp)
  lwc1  $f4, 0x218($s0)
  lw    $t8, 0x60($sp)
  lw    $t7, 0x2a4($sp)
  sub.s $f10, $f8, $f4
  sll   $t5, $t8, 6
  addiu $a0, $sp, 0x264
  addiu $a1, $sp, 0x1a4
  swc1  $f10, 0x1dc($sp)
  jal   matrix_4x4_multiply
   addu  $a2, $t5, $t7
  lw    $t9, 0x1a0($sp)
.Ljp7F061BDC:
  move  $v1, $zero
  move  $a2, $zero
  lh    $t6, 0xc($t9)
  li    $a3, 5
  slti  $at, $t6, 0x13
  bnez  $at, .Ljp7F061C9C
   nop   
.Ljp7F061BF8:
  lw    $t8, 0x1a0($sp)
  lw    $a0, 0x44($sp)
  lw    $t5, 8($t8)
  addu  $t7, $t5, $a2
  lw    $a1, 0x48($t7)
  beql  $a1, $zero, .Ljp7F061C48
   lw    $t5, 0x1a0($sp)
  sw    $v1, 0x5c($sp)
  jal   extract_id_from_object_structure_microcode
   sw    $a2, 0x40($sp)
  lw    $v1, 0x5c($sp)
  lw    $a2, 0x40($sp)
  beqz  $v0, .Ljp7F061C44
   li    $a3, 5
  lw    $t9, 0x34($s0)
  subu  $t6, $a3, $v1
  slt   $t8, $t9, $t6
  xori  $t8, $t8, 1
  sw    $t8, ($v0)
.Ljp7F061C44:
  lw    $t5, 0x1a0($sp)
.Ljp7F061C48:
  lw    $a0, 0x44($sp)
  lw    $t7, 8($t5)
  addu  $t9, $t7, $a2
  lw    $a1, 0x5c($t9)
  beql  $a1, $zero, .Ljp7F061C94
   addiu $v1, $v1, 1
  sw    $v1, 0x5c($sp)
  jal   extract_id_from_object_structure_microcode
   sw    $a2, 0x40($sp)
  lw    $v1, 0x5c($sp)
  lw    $a2, 0x40($sp)
  beqz  $v0, .Ljp7F061C90
   li    $a3, 5
  lw    $t6, 0x34($s0)
  subu  $t8, $a3, $v1
  slt   $t5, $t6, $t8
  xori  $t5, $t5, 1
  sw    $t5, ($v0)
.Ljp7F061C90:
  addiu $v1, $v1, 1
.Ljp7F061C94:
  bne   $v1, $a3, .Ljp7F061BF8
   addiu $a2, $a2, 4
.Ljp7F061C9C:
  jal   sub_GAME_7F06EFC4
   lw    $a0, 0x44($sp)
  lb    $t7, 0xc($s0)
  lw    $t9, 0xfc($sp)
  beqz  $t7, weapon_bullet_type_shotgun_mine
   addiu $t6, $t9, -4
  sltiu $at, $t6, 0x14
  beqz  $at, weapon_bullet_type_shotgun_mine
   sll   $t6, $t6, 2
  lui   $at, %hi(jpt_weapon_bullet_type)
  addu  $at, $at, $t6
  lw    $t6, %lo(jpt_weapon_bullet_type)($at)
  jr    $t6
   nop   
weapon_bullet_type_pistol:
  jal   sub_GAME_7F061BF4
   lw    $a0, 0x2a8($sp)
  lw    $t8, 0x30($s0)
  addiu $t5, $t8, 1
  b     weapon_bullet_type_shotgun_mine
   sw    $t5, 0x30($s0)
weapon_bullet_type_none:
  lw    $t7, 0x30($s0)
  addiu $t9, $t7, 1
  sw    $t9, 0x30($s0)
  jal   sub_GAME_7F061BF4
   lw    $a0, 0x2a8($sp)
weapon_bullet_type_shotgun_mine:
  lw    $t6, 0xfc($sp)
.Ljp7F061D04:
  li    $at, 25
  bnel  $t6, $at, .Ljp7F061D1C
   lb    $t8, 0xc($s0)
  jal   sub_GAME_7F05F928
   lw    $a0, 0x2a8($sp)
  lb    $t8, 0xc($s0)
.Ljp7F061D1C:
  lui   $a0, %hi(pPlayer) # $a0, 0x8008
  beql  $t8, $zero, .Ljp7F061E3C
   lw    $ra, 0x34($sp)
  jal   sub_GAME_7F089778
   lw    $a0, %lo(pPlayer)($a0)
  mfc1  $a1, $f0
  jal   sub_GAME_7F068508
   lw    $a0, 0x2a8($sp)
  lw    $t5, 0xfc($sp)
  li    $at, 24
  lw    $t7, 0xfc($sp)
  bnel  $t5, $at, .Ljp7F061D64
   li    $at, 26
  jal   sub_GAME_7F05F73C
   lw    $a0, 0x2a8($sp)
  b     .Ljp7F061E3C
   lw    $ra, 0x34($sp)
  li    $at, 26
.Ljp7F061D64:
  bne   $t7, $at, .Ljp7F061D7C
   lw    $t9, 0xfc($sp)
  jal   sub_GAME_7F05EE24
   lw    $a0, 0x2a8($sp)
  b     .Ljp7F061E3C
   lw    $ra, 0x34($sp)
.Ljp7F061D7C:
  li    $at, 25
  bne   $t9, $at, .Ljp7F061D98
   lw    $t6, 0xfc($sp)
  jal   sub_GAME_7F05FB64
   lw    $a0, 0x2a8($sp)
  b     .Ljp7F061E3C
   lw    $ra, 0x34($sp)
.Ljp7F061D98:
  li    $at, 3
  bne   $t6, $at, .Ljp7F061DB4
   lw    $t8, 0xfc($sp)
  jal   sub_GAME_7F05F09C
   lw    $a0, 0x2a8($sp)
  b     .Ljp7F061E3C
   lw    $ra, 0x34($sp)
.Ljp7F061DB4:
  li    $at, 29
  beq   $t8, $at, .Ljp7F061DF8
   li    $at, 28
  beq   $t8, $at, .Ljp7F061DF8
   li    $at, 27
  beq   $t8, $at, .Ljp7F061DF8
   li    $at, 33
  beq   $t8, $at, .Ljp7F061DF8
   li    $at, 47
  beq   $t8, $at, .Ljp7F061DF8
   li    $at, 48
  beq   $t8, $at, .Ljp7F061DF8
   li    $at, 61
  beq   $t8, $at, .Ljp7F061DF8
   li    $at, 34
  bne   $t8, $at, .Ljp7F061E08
   lw    $t5, 0xfc($sp)
.Ljp7F061DF8:
  jal   generate_player_thrown_object
   lw    $a0, 0x2a8($sp)
  b     .Ljp7F061E3C
   lw    $ra, 0x34($sp)
.Ljp7F061E08:
  li    $at, 35
  bne   $t5, $at, .Ljp7F061E24
   lw    $t7, 0xfc($sp)
  jal   sub_GAME_7F05F73C
   lw    $a0, 0x2a8($sp)
  b     .Ljp7F061E3C
   lw    $ra, 0x34($sp)
.Ljp7F061E24:
  li    $at, 36
  bnel  $t7, $at, .Ljp7F061E3C
   lw    $ra, 0x34($sp)
  jal   sub_GAME_7F05F73C
   lw    $a0, 0x2a8($sp)
  lw    $ra, 0x34($sp)
.Ljp7F061E3C:
  lw    $s0, 0x30($sp)
  addiu $sp, $sp, 0x2a8
  jr    $ra
   nop   
");
#endif

#endif

asm(R"
glabel sub_GAME_7F061920
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   handles_firing_or_throwing_weapon_in_hand
   move  $a0, $zero
  jal   handles_firing_or_throwing_weapon_in_hand
   li    $a0, 1
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80053E88
.word 0x461c4000 /*10000.0*/
glabel D_80053E8C
.word 0x453b8000 /*3000.0*/
glabel D_80053E90
.word 0x3f19999a /*0.60000002*/
glabel D_80053E94
.word 0x3e99999a /*0.30000001*/
glabel D_80053E98
.word 0xbdcccccd /*-0.1*/
glabel D_80053E9C
.word 0x453b8000 /*3000.0*/
glabel D_80053EA0
.word 0x453b8000 /*3000.0*/
glabel D_80053EA4
.word 0x3e4ccccd /*0.2*/
.text
glabel sub_GAME_7F061948
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  lwc1  $f4, ($a2)
  swc1  $f4, 4($a0)
  lwc1  $f6, 4($a2)
  swc1  $f6, 8($a0)
  lwc1  $f8, 8($a2)
  swc1  $f8, 0xc($a0)
  lwc1  $f16, ($a2)
  lwc1  $f10, ($a3)
  sub.s $f18, $f10, $f16
  swc1  $f18, 0x10($a0)
  lwc1  $f6, 4($a2)
  lwc1  $f4, 4($a3)
  lwc1  $f2, 0x10($a0)
  sub.s $f8, $f4, $f6
  mul.s $f4, $f2, $f2
  swc1  $f8, 0x14($a0)
  lwc1  $f16, 8($a2)
  lwc1  $f10, 8($a3)
  lwc1  $f14, 0x14($a0)
  sub.s $f18, $f10, $f16
  mul.s $f6, $f14, $f14
  swc1  $f18, 0x18($a0)
  lwc1  $f0, 0x18($a0)
  sw    $a1, 0x24($sp)
  sw    $a0, 0x20($sp)
  mul.s $f10, $f0, $f0
  add.s $f8, $f4, $f6
  jal   sqrtf
   add.s $f12, $f10, $f8
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f16
  lw    $a0, 0x20($sp)
  lw    $a1, 0x24($sp)
  div.s $f2, $f16, $f0
  lwc1  $f18, 0x10($a0)
  lwc1  $f6, 0x14($a0)
  lwc1  $f8, 0x18($a0)
  li    $v0, 23
  mov.s $f12, $f0
  lui   $at, %hi(D_80053E88)
  mul.s $f4, $f18, $f2
  nop   
  mul.s $f10, $f6, $f2
  nop   
  mul.s $f16, $f8, $f2
  swc1  $f4, 0x10($a0)
  swc1  $f10, 0x14($a0)
  bne   $a1, $v0, .L7F061A38
   swc1  $f16, 0x18($a0)
  li    $at, 0x43960000 # 300.000000
  mtc1  $at, $f2
  nop   
  c.lt.s $f2, $f0
  nop   
  bc1fl .L7F061A54
   lui   $at, %hi(0x43FA3E88) # $at, 0x43fa
  b     .L7F061A50
   mov.s $f12, $f2
.L7F061A38:
  lwc1  $f2, %lo(D_80053E88)($at)
  c.lt.s $f2, $f0
  nop   
  bc1fl .L7F061A54
   lui   $at, 0x43fa
  mov.s $f12, $f2
.L7F061A50:
  li    $at, 0x43FA0000 # 500.000000
.L7F061A54:
  mtc1  $at, $f0
  sb    $zero, ($a0)
  sb    $a1, 1($a0)
  c.lt.s $f12, $f0
  swc1  $f12, 0x1c($a0)
  li    $at, 22
  bc1f  .L7F061A78
   nop   
  mov.s $f12, $f0
.L7F061A78:
  bne   $a1, $at, .L7F061B14
   lui   $at, %hi(D_80053E8C)
  lwc1  $f2, %lo(D_80053E8C)($at)
  li    $at, 0x3E800000 # 0.250000
  mtc1  $at, $f18
  lui   $at, %hi(D_80053E90)
  mul.s $f4, $f18, $f12
  swc1  $f4, 0x20($a0)
  lwc1  $f6, %lo(D_80053E90)($at)
  mul.s $f0, $f6, $f12
  c.lt.s $f2, $f0
  swc1  $f0, 0x24($a0)
  bc1fl .L7F061AB8
   sw    $a0, 0x20($sp)
  swc1  $f2, 0x24($a0)
  sw    $a0, 0x20($sp)
.L7F061AB8:
  jal   get_random_value
   swc1  $f12, 0x1c($sp)
  mtc1  $v0, $f10
  lw    $a0, 0x20($sp)
  lwc1  $f12, 0x1c($sp)
  bgez  $v0, .L7F061AE4
   cvt.s.w $f8, $f10
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f16
  nop   
  add.s $f8, $f8, $f16
.L7F061AE4:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f18
  lui   $at, %hi(D_80053E94)
  lwc1  $f6, %lo(D_80053E94)($at)
  mul.s $f4, $f8, $f18
  lui   $at, %hi(D_80053E98)
  lwc1  $f16, %lo(D_80053E98)($at)
  mul.s $f10, $f4, $f6
  sub.s $f8, $f16, $f10
  mul.s $f18, $f8, $f12
  b     .L7F061BC4
   swc1  $f18, 0x28($a0)
.L7F061B14:
  bne   $a1, $v0, .L7F061B4C
   lui   $at, %hi(D_80053EA0)
  lui   $at, %hi(D_80053E9C)
  lwc1  $f2, %lo(D_80053E9C)($at)
  add.s $f4, $f12, $f12
  mtc1  $zero, $f6
  swc1  $f12, 0x24($a0)
  c.lt.s $f2, $f12
  swc1  $f4, 0x20($a0)
  bc1f  .L7F061B44
   nop   
  swc1  $f2, 0x24($a0)
.L7F061B44:
  b     .L7F061BC4
   swc1  $f6, 0x28($a0)
.L7F061B4C:
  lwc1  $f2, %lo(D_80053EA0)($at)
  lui   $at, %hi(D_80053EA4)
  lwc1  $f16, %lo(D_80053EA4)($at)
  mul.s $f0, $f16, $f12
  c.lt.s $f2, $f0
  swc1  $f0, 0x20($a0)
  swc1  $f0, 0x24($a0)
  bc1f  .L7F061B74
   nop   
  swc1  $f2, 0x24($a0)
.L7F061B74:
  jal   get_random_value
   sw    $a0, 0x20($sp)
  mtc1  $v0, $f10
  lw    $a0, 0x20($sp)
  bgez  $v0, .L7F061B9C
   cvt.s.w $f8, $f10
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f18
  nop   
  add.s $f8, $f8, $f18
.L7F061B9C:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f4
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f16
  mul.s $f0, $f8, $f4
  lwc1  $f18, 0x20($a0)
  add.s $f6, $f0, $f0
  sub.s $f10, $f6, $f16
  mul.s $f8, $f10, $f18
  swc1  $f8, 0x28($a0)
.L7F061BC4:
  lwc1  $f4, 0x28($a0)
  lwc1  $f6, 0x1c($a0)
  li    $t6, -1
  c.le.s $f6, $f4
  nop   
  bc1fl .L7F061BE8
   lw    $ra, 0x14($sp)
  sb    $t6, ($a0)
  lw    $ra, 0x14($sp)
.L7F061BE8:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80053EA8
.word 0x3db2b8c3 /*0.087266468*/
.text
glabel sub_GAME_7F061BF4
  sll   $t7, $a0, 3
  subu  $t7, $t7, $a0
  sll   $t7, $t7, 2
  addu  $t7, $t7, $a0
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  addiu $sp, $sp, -0x60
  sll   $t7, $t7, 2
  addu  $t7, $t7, $a0
  sw    $s0, 0x14($sp)
  sll   $t7, $t7, 3
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  addu  $s0, $t6, $t7
  move  $s1, $a0
  jal   get_BONDdata_field_10CC
   addiu $s0, $s0, 0x870
  lwc1  $f4, 0x39c($s0)
  lwc1  $f6, 8($v0)
  lwc1  $f10, 0x3a0($s0)
  lwc1  $f16, 0x18($v0)
  mul.s $f8, $f4, $f6
  lwc1  $f6, 0x3a4($s0)
  mul.s $f18, $f10, $f16
  lwc1  $f10, 0x28($v0)
  mul.s $f16, $f6, $f10
  lwc1  $f6, 0x2f4($s0)
  add.s $f4, $f8, $f18
  lwc1  $f18, 0x38($v0)
  add.s $f8, $f4, $f16
  add.s $f0, $f18, $f8
  neg.s $f0, $f0
  c.lt.s $f0, $f6
  nop   
  bc1tl .L7F061E08
   lw    $ra, 0x1c($sp)
  jal   get_item_in_hand
   move  $a0, $s1
  addiu $a3, $s0, 0x39c
  sw    $a3, 0x28($sp)
  addiu $a0, $s0, 0x1e4
  move  $a1, $v0
  jal   sub_GAME_7F061948
   addiu $a2, $s0, 0x2e8
  lui   $t8, %hi(pPlayer) 
  lw    $t8, %lo(pPlayer)($t8)
  lw    $t9, 0xa8($t8)
  lw    $t0, 4($t9)
  beql  $t0, $zero, .L7F061E08
   lw    $ra, 0x1c($sp)
  jal   getPlayerCount
   nop   
  slti  $at, $v0, 2
  bnez  $at, .L7F061E04
   lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  sll   $a3, $s1, 2
  subu  $a3, $a3, $s1
  lw    $t1, 0xa8($v1)
  sll   $a3, $a3, 2
  addu  $v0, $v1, $a3
  lw    $t2, 4($t1)
  addiu $a0, $sp, 0x40
  addiu $a1, $sp, 0x44
  sw    $t2, 0x4c($sp)
  lwc1  $f4, 0x2a18($v0)
  lwc1  $f10, 0x39c($s0)
  addiu $a2, $sp, 0x48
  sub.s $f16, $f10, $f4
  swc1  $f16, 0x40($sp)
  lwc1  $f8, 0x2a1c($v0)
  lwc1  $f18, 0x3a0($s0)
  sub.s $f6, $f18, $f8
  swc1  $f6, 0x44($sp)
  lwc1  $f4, 0x2a20($v0)
  lwc1  $f10, 0x3a4($s0)
  sw    $a3, 0x24($sp)
  sub.s $f16, $f10, $f4
  jal   guNormalize
   swc1  $f16, 0x48($sp)
  lwc1  $f18, 0x39c($s0)
  lwc1  $f8, 0x2e8($s0)
  addiu $a0, $sp, 0x34
  addiu $a1, $sp, 0x38
  sub.s $f6, $f18, $f8
  addiu $a2, $sp, 0x3c
  swc1  $f6, 0x34($sp)
  lwc1  $f4, 0x2ec($s0)
  lwc1  $f10, 0x3a0($s0)
  sub.s $f16, $f10, $f4
  swc1  $f16, 0x38($sp)
  lwc1  $f8, 0x2f0($s0)
  lwc1  $f18, 0x3a4($s0)
  sub.s $f6, $f18, $f8
  jal   guNormalize
   swc1  $f6, 0x3c($sp)
  lwc1  $f10, 0x40($sp)
  lwc1  $f4, 0x34($sp)
  lwc1  $f18, 0x44($sp)
  lwc1  $f8, 0x38($sp)
  mul.s $f16, $f10, $f4
  lwc1  $f4, 0x3c($sp)
  mul.s $f6, $f18, $f8
  lwc1  $f18, 0x48($sp)
  mul.s $f8, $f4, $f18
  add.s $f10, $f16, $f6
  jal   sub_GAME_7F05ACB0
   add.s $f12, $f8, $f10
  lui   $at, %hi(D_80053EA8)
  lwc1  $f16, %lo(D_80053EA8)($at)
  c.lt.s $f16, $f0
  nop   
  bc1tl .L7F061E08
   lw    $ra, 0x1c($sp)
  jal   get_item_in_hand
   move  $a0, $s1
  sll   $t4, $s1, 2
  subu  $t4, $t4, $s1
  lui   $t5, %hi(pPlayer) 
  lw    $t5, %lo(pPlayer)($t5)
  lw    $t3, 0x4c($sp)
  lw    $t6, 0x24($sp)
  sll   $t4, $t4, 2
  subu  $t4, $t4, $s1
  sll   $t4, $t4, 2
  addu  $a0, $t3, $t4
  addu  $a2, $t5, $t6
  addiu $a2, $a2, 0x2a18
  addiu $a0, $a0, 0x180
  move  $a1, $v0
  jal   sub_GAME_7F061948
   lw    $a3, 0x28($sp)
.L7F061E04:
  lw    $ra, 0x1c($sp)
.L7F061E08:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x60
");

asm(R"
.late_rodata
glabel D_80053EAC
.word 0x3fb50481 /*1.4141999*/
glabel D_80053EB0
.word 0x3dcccccd /*0.1*/
glabel D_80053EB4
.word 0x3f666666 /*0.89999998*/
glabel D_80053EB8
.word 0x3f666666 /*0.89999998*/
glabel D_80053EBC
.word 0x3f666666 /*0.89999998*/
glabel D_80053EC0
.word 0x3f666666 /*0.89999998*/
glabel D_80053EC4
.word 0x3f666666 /*0.89999998*/
glabel D_80053EC8
.word 0x3f666666 /*0.89999998*/
glabel D_80053ECC
.word 0x3fb50481 /*1.4141999*/
glabel D_80053ED0
.word 0x3f666666 /*0.89999998*/
.text
glabel sub_GAME_7F061E18
  addiu $sp, $sp, -0x160
  sw    $ra, 0x2c($sp)
  sw    $s1, 0x28($sp)
  sw    $s0, 0x24($sp)
  sdc1  $f20, 0x18($sp)
  sw    $a0, 0x160($sp)
  sw    $a2, 0x168($sp)
  lb    $t3, ($a1)
  lui   $t6, %hi(D_80035C98) 
  move  $s1, $a1
  bltz  $t3, .L7F062AE4
   addiu $t6, %lo(D_80035C98) # addiu $t6, $t6, 0x5c98
  lw    $at, ($t6)
  lw    $t9, 4($t6)
  addiu $t1, $sp, 0x108
  sw    $at, ($t1)
  sw    $t9, 4($t1)
  lw    $t9, 0xc($t6)
  lw    $at, 8($t6)
  sw    $t9, 0xc($t1)
  jal   get_BONDdata_position
   sw    $at, 8($t1)
  sw    $v0, 0xf8($sp)
  lui   $t5, %hi(D_80035CA8) 
  addiu $t5, %lo(D_80035CA8) # addiu $t5, $t5, 0x5ca8
  lw    $at, ($t5)
  lwc1  $f0, 0x28($s1)
  lwc1  $f20, 0x24($s1)
  addiu $t7, $sp, 0xc4
  sw    $at, ($t7)
  lw    $at, 8($t5)
  lw    $t3, 4($t5)
  lui   $t1, %hi(D_80035CB4) 
  addiu $t1, %lo(D_80035CB4) # addiu $t1, $t1, 0x5cb4
  sw    $at, 8($t7)
  sw    $t3, 4($t7)
  lw    $at, ($t1)
  addiu $t8, $sp, 0xb8
  lw    $t2, 4($t1)
  sw    $at, ($t8)
  lw    $at, 8($t1)
  sw    $t2, 4($t8)
  lui   $t4, %hi(flareimage3) 
  sw    $at, 8($t8)
  lui   $at, %hi(D_80053EAC)
  lwc1  $f4, %lo(D_80053EAC)($at)
  lw    $t4, %lo(flareimage3)($t4)
  swc1  $f0, 0xe8($sp)
  swc1  $f4, 0xb4($sp)
  jal   get_BONDdata_field_10CC
   sw    $t4, 0xb0($sp)
  sw    $v0, 0xa8($sp)
  lb    $v1, 1($s1)
  li    $at, 22
  lwc1  $f0, 0xe8($sp)
  bne   $v1, $at, .L7F061F14
   li    $at, 0x42480000 # 50.000000
  mtc1  $at, $f18
  lui   $t7, %hi(flareimage4) 
  lw    $t7, %lo(flareimage4)($t7)
  swc1  $f18, 0xf4($sp)
  b     .L7F061FA8
   sw    $t7, 0xb0($sp)
.L7F061F14:
  li    $at, 23
  bne   $v1, $at, .L7F061F98
   lui   $t5, %hi(flareimage4) 
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f6
  lw    $t5, %lo(flareimage4)($t5)
  swc1  $f0, 0xe8($sp)
  swc1  $f6, 0xf4($sp)
  jal   get_random_value
   sw    $t5, 0xb0($sp)
  li    $at, 50
  divu  $zero, $v0, $at
  mfhi  $t3
  addiu $t9, $t3, 0x96
  jal   get_random_value
   sb    $t9, 0x117($sp)
  li    $at, 5
  divu  $zero, $v0, $at
  mfhi  $t6
  lwc1  $f0, 0xe8($sp)
  bnezl $t6, .L7F061FAC
   lwc1  $f4, 4($s1)
  jal   get_random_value
   swc1  $f0, 0xe8($sp)
  li    $at, 100
  divu  $zero, $v0, $at
  mfhi  $t8
  li    $t1, 255
  subu  $v1, $t1, $t8
  sb    $v1, 0x115($sp)
  sb    $v1, 0x114($sp)
  b     .L7F061FA8
   lwc1  $f0, 0xe8($sp)
.L7F061F98:
  li    $at, 0x41F00000 # 30.000000
  mtc1  $at, $f10
  nop   
  swc1  $f10, 0xf4($sp)
.L7F061FA8:
  lwc1  $f4, 4($s1)
.L7F061FAC:
  mtc1  $zero, $f14
  swc1  $f4, 0xfc($sp)
  lwc1  $f8, 8($s1)
  c.lt.s $f14, $f0
  swc1  $f8, 0x100($sp)
  lwc1  $f6, 0xc($s1)
  bc1f  .L7F06200C
   swc1  $f6, 0x104($sp)
  lwc1  $f4, 0x10($s1)
  lwc1  $f10, 0xfc($sp)
  mul.s $f8, $f0, $f4
  lwc1  $f4, 0x100($sp)
  add.s $f6, $f10, $f8
  swc1  $f6, 0xfc($sp)
  lwc1  $f10, 0x14($s1)
  mul.s $f8, $f0, $f10
  lwc1  $f10, 0x104($sp)
  add.s $f6, $f4, $f8
  swc1  $f6, 0x100($sp)
  lwc1  $f4, 0x18($s1)
  mul.s $f8, $f0, $f4
  add.s $f6, $f10, $f8
  b     .L7F062014
   swc1  $f6, 0x104($sp)
.L7F06200C:
  add.s $f20, $f20, $f0
  mov.s $f0, $f14
.L7F062014:
  add.s $f4, $f0, $f20
  lwc1  $f2, 0x1c($s1)
  c.lt.s $f2, $f4
  nop   
  bc1fl .L7F062034
   lwc1  $f12, 0x18($s1)
  sub.s $f20, $f2, $f0
  lwc1  $f12, 0x18($s1)
.L7F062034:
  lwc1  $f10, 0x104($sp)
  lw    $v0, 0xf8($sp)
  mul.s $f8, $f20, $f12
  lwc1  $f2, 0x14($s1)
  lwc1  $f4, 8($v0)
  swc1  $f10, 0x30($sp)
  add.s $f6, $f10, $f8
  lwc1  $f10, 4($v0)
  sub.s $f8, $f4, $f6
  mul.s $f4, $f2, $f8
  lwc1  $f8, 0x100($sp)
  mul.s $f6, $f2, $f20
  add.s $f6, $f6, $f8
  sub.s $f10, $f10, $f6
  mul.s $f6, $f10, $f12
  sub.s $f10, $f4, $f6
  lwc1  $f4, 0xfc($sp)
  swc1  $f10, 0xd0($sp)
  lwc1  $f0, 0x10($s1)
  lwc1  $f12, 0x18($s1)
  swc1  $f8, 0x34($sp)
  mul.s $f6, $f20, $f0
  lwc1  $f8, ($v0)
  swc1  $f10, 0x38($sp)
  lwc1  $f10, 0x30($sp)
  add.s $f6, $f4, $f6
  sub.s $f8, $f8, $f6
  mul.s $f6, $f12, $f8
  nop   
  mul.s $f8, $f12, $f20
  add.s $f8, $f8, $f10
  lwc1  $f10, 8($v0)
  sub.s $f10, $f10, $f8
  mul.s $f8, $f10, $f0
  sub.s $f10, $f6, $f8
  lwc1  $f6, 0x34($sp)
  swc1  $f10, 0xd4($sp)
  lwc1  $f2, 0x14($s1)
  lwc1  $f0, 0x10($s1)
  mul.s $f8, $f20, $f2
  add.s $f6, $f6, $f8
  lwc1  $f8, 4($v0)
  sub.s $f8, $f8, $f6
  mul.s $f6, $f0, $f8
  nop   
  mul.s $f8, $f0, $f20
  add.s $f8, $f8, $f4
  lwc1  $f4, ($v0)
  sub.s $f4, $f4, $f8
  mul.s $f8, $f4, $f2
  sub.s $f4, $f6, $f8
  lwc1  $f6, 0x38($sp)
  c.eq.s $f14, $f6
  swc1  $f4, 0xd8($sp)
  bc1f  .L7F062130
   nop   
  c.eq.s $f14, $f10
  nop   
  bc1fl .L7F062134
   addiu $a0, $sp, 0xd0
  c.eq.s $f14, $f4
  nop   
  bc1t  .L7F06216C
.L7F062130:
   addiu $a0, $sp, 0xd0
.L7F062134:
  addiu $a1, $sp, 0xd4
  jal   guNormalize
   addiu $a2, $sp, 0xd8
  lwc1  $f0, 0xf4($sp)
  lwc1  $f8, 0xd0($sp)
  lwc1  $f10, 0xd4($sp)
  mul.s $f6, $f8, $f0
  lwc1  $f8, 0xd8($sp)
  mul.s $f4, $f10, $f0
  swc1  $f6, 0xd0($sp)
  mul.s $f6, $f8, $f0
  swc1  $f4, 0xd4($sp)
  b     .L7F06217C
   swc1  $f6, 0xd8($sp)
.L7F06216C:
  lwc1  $f10, 0xf4($sp)
  swc1  $f14, 0xd0($sp)
  swc1  $f14, 0xd8($sp)
  swc1  $f10, 0xd4($sp)
.L7F06217C:
  lwc1  $f4, 0x14($s1)
  lwc1  $f8, 0xd8($sp)
  lwc1  $f10, 0xd4($sp)
  addiu $a0, $sp, 0xdc
  mul.s $f6, $f4, $f8
  lwc1  $f4, 0x18($s1)
  addiu $a1, $sp, 0xe0
  addiu $a2, $sp, 0xe4
  mul.s $f4, $f10, $f4
  sub.s $f6, $f6, $f4
  swc1  $f6, 0xdc($sp)
  lwc1  $f4, 0x18($s1)
  lwc1  $f6, 0xd0($sp)
  swc1  $f10, 0x38($sp)
  lwc1  $f10, 0x10($s1)
  mul.s $f4, $f4, $f6
  nop   
  mul.s $f8, $f8, $f10
  sub.s $f10, $f4, $f8
  lwc1  $f8, 0x38($sp)
  swc1  $f10, 0xe0($sp)
  lwc1  $f4, 0x10($s1)
  mul.s $f10, $f4, $f8
  lwc1  $f4, 0x14($s1)
  mul.s $f8, $f6, $f4
  sub.s $f6, $f10, $f8
  jal   guNormalize
   swc1  $f6, 0xe4($sp)
  lwc1  $f0, 0xf4($sp)
  lwc1  $f4, 0xdc($sp)
  lwc1  $f8, 0xe0($sp)
  li    $at, 22
  mul.s $f10, $f4, $f0
  lwc1  $f4, 0xe4($sp)
  mul.s $f6, $f8, $f0
  swc1  $f10, 0xdc($sp)
  mul.s $f10, $f4, $f0
  swc1  $f6, 0xe0($sp)
  swc1  $f10, 0xe4($sp)
  lb    $t2, 1($s1)
  bne   $t2, $at, .L7F062234
   nop   
  jal   sub_GAME_7F0BD6C4
   li    $a0, 8
  b     .L7F062240
   move  $s0, $v0
.L7F062234:
  jal   sub_GAME_7F0BD6C4
   li    $a0, 4
  move  $s0, $v0
.L7F062240:
  jal   sub_GAME_7F0BD6E0
   nop   
  sw    $v0, 0x158($sp)
  addiu $a0, $sp, 0xfc
  jal   init_something_copy_posdata_to_it
   addiu $a1, $sp, 0x118
  lui   $at, %hi(D_80053EB0)
  lwc1  $f12, %lo(D_80053EB0)($at)
  jal   matrix_multiply_A1_by_F12
   addiu $a1, $sp, 0x118
  lw    $a0, 0xa8($sp)
  jal   matrix_4x4_multiply_homogeneous_in_place
   addiu $a1, $sp, 0x118
  addiu $a0, $sp, 0x118
  jal   sub_GAME_7F058C9C
   lw    $a1, 0x158($sp)
  addiu $v0, $sp, 0x108
  lw    $at, ($v0)
  sw    $at, ($s0)
  lw    $t5, 4($v0)
  sw    $t5, 4($s0)
  lw    $at, 8($v0)
  sw    $at, 8($s0)
  lw    $t5, 0xc($v0)
  sw    $t5, 0xc($s0)
  lw    $at, ($v0)
  sw    $at, 0x10($s0)
  lw    $t6, 4($v0)
  sw    $t6, 0x14($s0)
  lw    $at, 8($v0)
  sw    $at, 0x18($s0)
  lw    $t6, 0xc($v0)
  sw    $t6, 0x1c($s0)
  lw    $at, ($v0)
  sw    $at, 0x20($s0)
  lw    $t2, 4($v0)
  sw    $t2, 0x24($s0)
  lw    $at, 8($v0)
  sw    $at, 0x28($s0)
  lw    $t2, 0xc($v0)
  sw    $t2, 0x2c($s0)
  lw    $at, ($v0)
  sw    $at, 0x30($s0)
  lw    $t5, 4($v0)
  sw    $t5, 0x34($s0)
  lw    $at, 8($v0)
  sw    $at, 0x38($s0)
  lw    $t5, 0xc($v0)
  li    $at, 22
  sw    $t5, 0x3c($s0)
  lb    $v1, 1($s1)
  bnel  $v1, $at, .L7F06239C
   li    $at, 23
  lw    $at, ($v0)
  sw    $at, 0x40($s0)
  lw    $t3, 4($v0)
  sw    $t3, 0x44($s0)
  lw    $at, 8($v0)
  sw    $at, 0x48($s0)
  lw    $t3, 0xc($v0)
  sw    $t3, 0x4c($s0)
  lw    $at, ($v0)
  sw    $at, 0x50($s0)
  lw    $t8, 4($v0)
  sw    $t8, 0x54($s0)
  lw    $at, 8($v0)
  sw    $at, 0x58($s0)
  lw    $t8, 0xc($v0)
  sw    $t8, 0x5c($s0)
  lw    $at, ($v0)
  sw    $at, 0x60($s0)
  lw    $t2, 4($v0)
  sw    $t2, 0x64($s0)
  lw    $at, 8($v0)
  sw    $at, 0x68($s0)
  lw    $t2, 0xc($v0)
  sw    $t2, 0x6c($s0)
  lw    $at, ($v0)
  sw    $at, 0x70($s0)
  lw    $t7, 4($v0)
  sw    $t7, 0x74($s0)
  lw    $at, 8($v0)
  sw    $at, 0x78($s0)
  lw    $t7, 0xc($v0)
  sw    $t7, 0x7c($s0)
  lb    $v1, 1($s1)
  li    $at, 23
.L7F06239C:
  bnel  $v1, $at, .L7F0624DC
   lui   $at, 0x4120
  lwc1  $f8, 0x10($s1)
  lwc1  $f4, 0xfc($sp)
  lw    $a0, 0xa8($sp)
  mul.s $f6, $f8, $f20
  addiu $a1, $sp, 0x9c
  add.s $f10, $f6, $f4
  lwc1  $f4, 0x100($sp)
  swc1  $f10, 0x9c($sp)
  lwc1  $f8, 0x14($s1)
  mul.s $f6, $f8, $f20
  add.s $f10, $f6, $f4
  lwc1  $f4, 0x104($sp)
  swc1  $f10, 0xa0($sp)
  lwc1  $f8, 0x18($s1)
  mul.s $f6, $f8, $f20
  add.s $f10, $f6, $f4
  jal   sub_GAME_7F058474
   swc1  $f10, 0xa4($sp)
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f6
  lwc1  $f8, 0xf4($sp)
  lwc1  $f14, 0xa4($sp)
  addiu $a0, $sp, 0x88
  div.s $f0, $f8, $f6
  addiu $a2, $sp, 0x90
  neg.s $f2, $f14
  mfc1  $a1, $f2
  swc1  $f0, 0x8c($sp)
  jal   sub_GAME_7F0780F0
   swc1  $f0, 0x88($sp)
  li    $at, 0x40000000 # 2.000000
  lwc1  $f16, 0x90($sp)
  mtc1  $at, $f4
  li    $at, 0x3F000000 # 0.500000
  c.lt.s $f16, $f4
  nop   
  bc1f  .L7F062470
   nop   
  mtc1  $at, $f10
  lwc1  $f2, 0x9c($sp)
  lwc1  $f12, 0xa0($sp)
  mul.s $f0, $f16, $f10
  lwc1  $f14, 0xa4($sp)
  mul.s $f2, $f2, $f0
  nop   
  mul.s $f12, $f12, $f0
  nop   
  mul.s $f14, $f14, $f0
  swc1  $f2, 0x9c($sp)
  swc1  $f12, 0xa0($sp)
  swc1  $f14, 0xa4($sp)
.L7F062470:
  jal   sub_GAME_7F078444
   nop   
  move  $a0, $v0
  jal   sub_GAME_7F058474
   addiu $a1, $sp, 0x9c
  lwc1  $f2, 0x9c($sp)
  lwc1  $f8, 0xfc($sp)
  lwc1  $f12, 0xa0($sp)
  lwc1  $f6, 0x100($sp)
  sub.s $f2, $f2, $f8
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f0
  sub.s $f12, $f12, $f6
  lwc1  $f14, 0xa4($sp)
  lwc1  $f4, 0x104($sp)
  mul.s $f10, $f2, $f0
  swc1  $f12, 0xa0($sp)
  sub.s $f14, $f14, $f4
  mul.s $f8, $f12, $f0
  swc1  $f2, 0x9c($sp)
  mul.s $f6, $f14, $f0
  swc1  $f10, 0xc4($sp)
  swc1  $f14, 0xa4($sp)
  swc1  $f8, 0xc8($sp)
  b     .L7F06250C
   swc1  $f6, 0xcc($sp)
  li    $at, 0x41200000 # 10.000000
.L7F0624DC:
  mtc1  $at, $f4
  lwc1  $f10, 0x10($s1)
  mul.s $f0, $f20, $f4
  nop   
  mul.s $f8, $f10, $f0
  swc1  $f8, 0xc4($sp)
  lwc1  $f6, 0x14($s1)
  mul.s $f4, $f6, $f0
  swc1  $f4, 0xc8($sp)
  lwc1  $f10, 0x18($s1)
  mul.s $f8, $f10, $f0
  swc1  $f8, 0xcc($sp)
.L7F06250C:
  lwc1  $f6, 0xd0($sp)
  lw    $a1, 0xb0($sp)
  lui   $at, %hi(D_80053EB4)
  trunc.w.s $f4, $f6
  mfc1  $t9, $f4
  nop   
  sh    $t9, ($s0)
  lwc1  $f10, 0xd4($sp)
  trunc.w.s $f8, $f10
  mfc1  $t6, $f8
  nop   
  sh    $t6, 2($s0)
  lwc1  $f6, 0xd8($sp)
  trunc.w.s $f4, $f6
  mfc1  $t1, $f4
  nop   
  sh    $t1, 4($s0)
  lbu   $t2, 4($a1)
  sh    $zero, 0xa($s0)
  sll   $t4, $t2, 5
  sh    $t4, 8($s0)
  lwc1  $f10, 0xd0($sp)
  neg.s $f8, $f10
  trunc.w.s $f6, $f8
  mfc1  $t5, $f6
  nop   
  sh    $t5, 0x10($s0)
  lwc1  $f4, 0xd4($sp)
  neg.s $f10, $f4
  trunc.w.s $f8, $f10
  mfc1  $t3, $f8
  nop   
  sh    $t3, 0x12($s0)
  lwc1  $f6, 0xd8($sp)
  sh    $zero, 0x18($s0)
  sh    $zero, 0x1a($s0)
  neg.s $f4, $f6
  trunc.w.s $f10, $f4
  mfc1  $t8, $f10
  nop   
  sh    $t8, 0x14($s0)
  lwc1  $f8, 0xd0($sp)
  lwc1  $f6, %lo(D_80053EB4)($at)
  lwc1  $f10, 0xc4($sp)
  lui   $at, %hi(D_80053EB8)
  mul.s $f4, $f8, $f6
  add.s $f8, $f4, $f10
  trunc.w.s $f6, $f8
  mfc1  $t2, $f6
  nop   
  sh    $t2, 0x20($s0)
  lwc1  $f4, 0xd4($sp)
  lwc1  $f10, %lo(D_80053EB8)($at)
  lwc1  $f6, 0xc8($sp)
  lui   $at, %hi(D_80053EBC)
  mul.s $f8, $f4, $f10
  add.s $f4, $f8, $f6
  trunc.w.s $f10, $f4
  mfc1  $t7, $f10
  nop   
  sh    $t7, 0x22($s0)
  lwc1  $f8, 0xd8($sp)
  lwc1  $f6, %lo(D_80053EBC)($at)
  lwc1  $f10, 0xcc($sp)
  lui   $at, %hi(D_80053EC0)
  mul.s $f4, $f8, $f6
  add.s $f8, $f4, $f10
  trunc.w.s $f6, $f8
  mfc1  $t9, $f6
  nop   
  sh    $t9, 0x24($s0)
  lbu   $t3, 4($a1)
  sll   $t6, $t3, 5
  sh    $t6, 0x28($s0)
  lbu   $t8, 5($a1)
  sll   $t1, $t8, 5
  sh    $t1, 0x2a($s0)
  lwc1  $f10, %lo(D_80053EC0)($at)
  lwc1  $f4, 0xd0($sp)
  lwc1  $f6, 0xc4($sp)
  lui   $at, %hi(D_80053EC4)
  mul.s $f8, $f4, $f10
  sub.s $f4, $f6, $f8
  trunc.w.s $f10, $f4
  mfc1  $t4, $f10
  nop   
  sh    $t4, 0x30($s0)
  lwc1  $f8, %lo(D_80053EC4)($at)
  lwc1  $f6, 0xd4($sp)
  lwc1  $f10, 0xc8($sp)
  lui   $at, %hi(D_80053EC8)
  mul.s $f4, $f6, $f8
  sub.s $f6, $f10, $f4
  trunc.w.s $f8, $f6
  mfc1  $t5, $f8
  nop   
  sh    $t5, 0x32($s0)
  lwc1  $f4, %lo(D_80053EC8)($at)
  lwc1  $f10, 0xd8($sp)
  lwc1  $f8, 0xcc($sp)
  sh    $zero, 0x38($s0)
  mul.s $f6, $f10, $f4
  li    $at, 22
  sub.s $f10, $f8, $f6
  trunc.w.s $f4, $f10
  mfc1  $t3, $f4
  nop   
  sh    $t3, 0x34($s0)
  lbu   $t6, 5($a1)
  sll   $t8, $t6, 5
  sh    $t8, 0x3a($s0)
  lb    $t1, 1($s1)
  lwc1  $f8, 0xfc($sp)
  lw    $t2, 0xf8($sp)
  bnel  $t1, $at, .L7F06298C
   lw    $t4, 0x160($sp)
  lwc1  $f12, ($t2)
  lwc1  $f2, 4($t2)
  lwc1  $f6, 0x100($sp)
  sub.s $f14, $f12, $f8
  lwc1  $f0, 8($t2)
  swc1  $f8, 0x38($sp)
  sub.s $f16, $f2, $f6
  mul.s $f4, $f14, $f14
  lwc1  $f10, 0x104($sp)
  lui   $at, %hi(D_80053ECC)
  mul.s $f8, $f16, $f16
  sub.s $f18, $f0, $f10
  add.s $f4, $f4, $f8
  mul.s $f8, $f18, $f18
  add.s $f4, $f4, $f8
  swc1  $f4, 0x78($sp)
  lwc1  $f8, 0x10($s1)
  swc1  $f6, 0x34($sp)
  lwc1  $f6, 0x38($sp)
  mul.s $f8, $f8, $f20
  add.s $f8, $f8, $f6
  lwc1  $f6, 0x14($s1)
  sub.s $f14, $f12, $f8
  mul.s $f8, $f6, $f20
  lwc1  $f6, 0x34($sp)
  add.s $f8, $f8, $f6
  lwc1  $f6, 0x18($s1)
  sub.s $f16, $f2, $f8
  mul.s $f8, $f6, $f20
  add.s $f6, $f8, $f10
  mul.s $f8, $f14, $f14
  nop   
  mul.s $f10, $f16, $f16
  sub.s $f18, $f0, $f6
  add.s $f6, $f8, $f10
  mul.s $f8, $f18, $f18
  add.s $f10, $f6, $f8
  lwc1  $f6, 0xc4($sp)
  c.lt.s $f10, $f4
  nop   
  bc1f  .L7F0627AC
   nop   
  lwc1  $f4, %lo(D_80053ECC)($at)
  swc1  $f6, 0xb8($sp)
  lui   $at, %hi(D_80053ED0)
  lwc1  $f6, %lo(D_80053ED0)($at)
  lwc1  $f8, 0xc8($sp)
  lwc1  $f10, 0xcc($sp)
  mul.s $f0, $f4, $f6
  swc1  $f8, 0xbc($sp)
  swc1  $f10, 0xc0($sp)
  swc1  $f0, 0xb4($sp)
.L7F0627AC:
  lwc1  $f0, 0xb4($sp)
  lwc1  $f8, 0xdc($sp)
  lwc1  $f4, 0xb8($sp)
  lui   $t0, %hi(flareimage5) 
  mul.s $f10, $f8, $f0
  addiu $t0, %lo(flareimage5) # addiu $t0, $t0, -0x2f28
  add.s $f6, $f10, $f4
  trunc.w.s $f8, $f6
  mfc1  $t7, $f8
  nop   
  sh    $t7, 0x40($s0)
  lwc1  $f10, 0xe0($sp)
  lwc1  $f6, 0xbc($sp)
  mul.s $f4, $f10, $f0
  add.s $f8, $f4, $f6
  trunc.w.s $f10, $f8
  mfc1  $t9, $f10
  nop   
  sh    $t9, 0x42($s0)
  lwc1  $f4, 0xe4($sp)
  lwc1  $f8, 0xc0($sp)
  mul.s $f6, $f4, $f0
  add.s $f10, $f6, $f8
  trunc.w.s $f4, $f10
  mfc1  $t6, $f4
  nop   
  sh    $t6, 0x44($s0)
  lw    $t8, ($t0)
  lbu   $t1, 4($t8)
  sll   $t2, $t1, 5
  sh    $t2, 0x48($s0)
  lw    $t4, ($t0)
  lbu   $t7, 5($t4)
  sll   $t5, $t7, 5
  sh    $t5, 0x4a($s0)
  lwc1  $f8, 0xdc($sp)
  lwc1  $f6, 0xb8($sp)
  mul.s $f10, $f8, $f0
  sub.s $f4, $f6, $f10
  trunc.w.s $f8, $f4
  mfc1  $t3, $f8
  nop   
  sh    $t3, 0x50($s0)
  lwc1  $f10, 0xe0($sp)
  lwc1  $f6, 0xbc($sp)
  mul.s $f4, $f10, $f0
  sub.s $f8, $f6, $f4
  trunc.w.s $f10, $f8
  mfc1  $t8, $f10
  nop   
  sh    $t8, 0x52($s0)
  lwc1  $f4, 0xe4($sp)
  lwc1  $f6, 0xc0($sp)
  sh    $zero, 0x58($s0)
  mul.s $f8, $f4, $f0
  sh    $zero, 0x5a($s0)
  sub.s $f10, $f6, $f8
  trunc.w.s $f4, $f10
  mfc1  $t2, $f4
  nop   
  sh    $t2, 0x54($s0)
  lwc1  $f6, 0xd0($sp)
  lwc1  $f10, 0xb8($sp)
  mul.s $f8, $f6, $f0
  add.s $f4, $f8, $f10
  trunc.w.s $f6, $f4
  mfc1  $t7, $f6
  nop   
  sh    $t7, 0x60($s0)
  lwc1  $f8, 0xd4($sp)
  lwc1  $f4, 0xbc($sp)
  mul.s $f10, $f8, $f0
  add.s $f6, $f10, $f4
  trunc.w.s $f8, $f6
  mfc1  $t9, $f8
  nop   
  sh    $t9, 0x62($s0)
  lwc1  $f10, 0xd8($sp)
  lwc1  $f6, 0xc0($sp)
  sh    $zero, 0x68($s0)
  mul.s $f4, $f10, $f0
  add.s $f8, $f4, $f6
  trunc.w.s $f10, $f8
  mfc1  $t6, $f10
  nop   
  sh    $t6, 0x64($s0)
  lw    $t8, ($t0)
  lbu   $t1, 5($t8)
  sll   $t2, $t1, 5
  sh    $t2, 0x6a($s0)
  lwc1  $f6, 0xd0($sp)
  lwc1  $f4, 0xb8($sp)
  mul.s $f8, $f6, $f0
  sub.s $f10, $f4, $f8
  trunc.w.s $f6, $f10
  mfc1  $t7, $f6
  nop   
  sh    $t7, 0x70($s0)
  lwc1  $f8, 0xd4($sp)
  lwc1  $f4, 0xbc($sp)
  mul.s $f10, $f8, $f0
  sub.s $f6, $f4, $f10
  trunc.w.s $f8, $f6
  mfc1  $t9, $f8
  nop   
  sh    $t9, 0x72($s0)
  lwc1  $f10, 0xd8($sp)
  lwc1  $f4, 0xc0($sp)
  mul.s $f6, $f10, $f0
  sub.s $f8, $f4, $f6
  trunc.w.s $f10, $f8
  mfc1  $t6, $f10
  nop   
  sh    $t6, 0x74($s0)
  lw    $t8, ($t0)
  lbu   $t1, 4($t8)
  sh    $zero, 0x7a($s0)
  sll   $t2, $t1, 5
  sh    $t2, 0x78($s0)
  lw    $t4, 0x160($sp)
.L7F06298C:
  lui   $t5, 0xb600
  li    $t9, 8192
  addiu $t7, $t4, 8
  sw    $t7, 0x160($sp)
  sw    $t9, 4($t4)
  sw    $t5, ($t4)
  lw    $t3, 0x160($sp)
  lui   $t8, (0x01020040 >> 16) # lui $t8, 0x102
  ori   $t8, (0x01020040 & 0xFFFF) # ori $t8, $t8, 0x40
  addiu $t6, $t3, 8
  sw    $t6, 0x160($sp)
  sw    $t8, ($t3)
  lw    $a0, 0x158($sp)
  jal   osVirtualToPhysical
   sw    $t3, 0x6c($sp)
  lw    $v1, 0x6c($sp)
  lui   $t0, %hi(flareimage5) 
  li    $at, 22
  sw    $v0, 4($v1)
  lb    $t1, 1($s1)
  addiu $t0, %lo(flareimage5) # addiu $t0, $t0, -0x2f28
  lw    $a1, 0xb0($sp)
  bne   $t1, $at, .L7F062A8C
   addiu $a0, $sp, 0x160
  li    $t2, 2
  sw    $t2, 0x10($sp)
  addiu $a0, $sp, 0x160
  lw    $a1, ($t0)
  li    $a2, 4
  jal   likely_generate_DL_for_image_declaration
   lw    $a3, 0x168($sp)
  lw    $s1, 0x160($sp)
  lui   $t5, (0x04700080 >> 16) # lui $t5, 0x470
  ori   $t5, (0x04700080 & 0xFFFF) # ori $t5, $t5, 0x80
  addiu $t7, $s1, 8
  sw    $t7, 0x160($sp)
  move  $a0, $s0
  jal   osVirtualToPhysical
   sw    $t5, ($s1)
  sw    $v0, 4($s1)
  lw    $t9, 0x160($sp)
  lui   $t6, (0xB1000076 >> 16) # lui $t6, 0xb100          # gSP4Triangles(8,8,6,5,1,7,2,0,0,0,0,0
  ori   $t6, (0xB1000076 & 0xFFFF) # ori $t6, $t6, 0x76
  addiu $t3, $t9, 8
  sw    $t3, 0x160($sp)
  li    $t8, 21588
  sw    $t8, 4($t9)                                       # ),
  sw    $t6, ($t9)
  li    $t1, 2
  sw    $t1, 0x10($sp)
  lw    $a3, 0x168($sp)
  lw    $a1, 0xb0($sp)
  addiu $a0, $sp, 0x160
  jal   likely_generate_DL_for_image_declaration
   li    $a2, 4
  lw    $t2, 0x160($sp)
  lui   $t7, (0xB1000013 >> 16) # lui $t7, 0xb100          # gSP4Triangles(0,2,3,3,2,1,1,0,0,0,0
  ori   $t7, (0xB1000013 & 0xFFFF) # ori $t7, $t7, 0x13
  addiu $t4, $t2, 8
  sw    $t4, 0x160($sp)
  li    $t5, 12320
  sw    $t5, 4($t2)
  b     .L7F062AE4
   sw    $t7, ($t2)                                        # ),
.L7F062A8C:
  li    $t9, 2
  sw    $t9, 0x10($sp)
  li    $a2, 4
  jal   likely_generate_DL_for_image_declaration
   lw    $a3, 0x168($sp)
  lw    $s1, 0x160($sp)
  lui   $t8, (0x04300040 >> 16) # lui $t8, 0x430
  ori   $t8, (0x04300040 & 0xFFFF) # ori $t8, $t8, 0x40
  addiu $t6, $s1, 8
  sw    $t6, 0x160($sp)
  move  $a0, $s0
  jal   osVirtualToPhysical
   sw    $t8, ($s1)
  sw    $v0, 4($s1)
  lw    $t1, 0x160($sp)
  lui   $t4, (0xB1000013 >> 16) # lui $t4, 0xb100
  ori   $t4, (0xB1000013 & 0xFFFF) # ori $t4, $t4, 0x13
  addiu $t2, $t1, 8
  sw    $t2, 0x160($sp)
  li    $t7, 12320
  sw    $t7, 4($t1)
  sw    $t4, ($t1)
.L7F062AE4:
  lw    $ra, 0x2c($sp)
  lw    $v0, 0x160($sp)
  ldc1  $f20, 0x18($sp)
  lw    $s0, 0x24($sp)
  lw    $s1, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x160
");

#ifdef VERSION_US
asm(R"
glabel sub_GAME_7F062B00
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lb    $t6, ($a0)
  lui   $t7, %hi(clock_timer) 
  bltzl $t6, .L7F062BD8
   lw    $ra, 0x14($sp)
  lw    $t7, %lo(clock_timer)($t7)
  slti  $at, $t7, 3
  beqz  $at, .L7F062B44
   lui   $at, %hi(global_timer_delta)
  lwc1  $f6, %lo(global_timer_delta)($at)
  lwc1  $f4, 0x20($a0)
  lwc1  $f10, 0x28($a0)
  mul.s $f8, $f4, $f6
  add.s $f16, $f10, $f8
  b     .L7F062BA4
   swc1  $f16, 0x28($a0)
.L7F062B44:
  jal   get_random_value
   sw    $a0, 0x18($sp)
  mtc1  $v0, $f18
  lw    $a0, 0x18($sp)
  bgez  $v0, .L7F062B6C
   cvt.s.w $f4, $f18
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f6
  nop   
  add.s $f4, $f4, $f6
.L7F062B6C:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f10
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f16
  mul.s $f8, $f4, $f10
  li    $at, 0x40000000 # 2.000000
  mtc1  $at, $f6
  lwc1  $f10, 0x20($a0)
  mul.s $f18, $f8, $f16
  lwc1  $f16, 0x28($a0)
  add.s $f4, $f6, $f18
  mul.s $f8, $f10, $f4
  add.s $f6, $f16, $f8
  swc1  $f6, 0x28($a0)
.L7F062BA4:
  lwc1  $f18, 0x28($a0)
  lwc1  $f10, 0x1c($a0)
  li    $t8, -1
  c.le.s $f10, $f18
  nop   
  bc1fl .L7F062BCC
   lb    $t9, ($a0)
  b     .L7F062BD4
   sb    $t8, ($a0)
  lb    $t9, ($a0)
.L7F062BCC:
  addiu $t0, $t9, 1
  sb    $t0, ($a0)
.L7F062BD4:
  lw    $ra, 0x14($sp)
.L7F062BD8:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");
#ifdef VERSION_JP
asm(R"
glabel sub_GAME_7F062B00
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lb    $t6, ($a0)
  lui   $t7, %hi(clock_timer) 
  bltzl $t6, .L7F062BD8
   lw    $ra, 0x14($sp)
  lw    $t7, %lo(clock_timer)($t7)
  slti  $at, $t7, 3
  beqz  $at, .L7F062B44
   lui   $at, %hi(jp_global_timer_delta)
  lwc1  $f6, %lo(jp_global_timer_delta)($at)
  lwc1  $f4, 0x20($a0)
  lwc1  $f10, 0x28($a0)
  mul.s $f8, $f4, $f6
  add.s $f16, $f10, $f8
  b     .L7F062BA4
   swc1  $f16, 0x28($a0)
.L7F062B44:
  jal   get_random_value
   sw    $a0, 0x18($sp)
  mtc1  $v0, $f18
  lw    $a0, 0x18($sp)
  bgez  $v0, .L7F062B6C
   cvt.s.w $f4, $f18
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f6
  nop   
  add.s $f4, $f4, $f6
.L7F062B6C:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f10
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f16
  mul.s $f8, $f4, $f10
  li    $at, 0x40000000 # 2.000000
  mtc1  $at, $f6
  lwc1  $f10, 0x20($a0)
  mul.s $f18, $f8, $f16
  lwc1  $f16, 0x28($a0)
  add.s $f4, $f6, $f18
  mul.s $f8, $f10, $f4
  add.s $f6, $f16, $f8
  swc1  $f6, 0x28($a0)
.L7F062BA4:
  lwc1  $f18, 0x28($a0)
  lwc1  $f10, 0x1c($a0)
  li    $t8, -1
  c.le.s $f10, $f18
  nop   
  bc1fl .L7F062BCC
   lb    $t9, ($a0)
  b     .L7F062BD4
   sb    $t8, ($a0)
  lb    $t9, ($a0)
.L7F062BCC:
  addiu $t0, $t9, 1
  sb    $t0, ($a0)
.L7F062BD4:
  lw    $ra, 0x14($sp)
.L7F062BD8:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");
#endif
#endif

asm(R"
glabel sub_GAME_7F062BE4
  addiu $sp, $sp, -0xd0
  sw    $s7, 0x3c($sp)
  lui   $t7, %hi(D_80035CC0) 
  addiu $s7, $sp, 0x8c
  sw    $ra, 0x44($sp)
  sw    $fp, 0x40($sp)
  sw    $s6, 0x38($sp)
  sw    $s5, 0x34($sp)
  sw    $s4, 0x30($sp)
  sw    $s3, 0x2c($sp)
  sw    $s2, 0x28($sp)
  sw    $s1, 0x24($sp)
  sw    $s0, 0x20($sp)
  sw    $a0, 0xd0($sp)
  addiu $t7, %lo(D_80035CC0) # addiu $t7, $t7, 0x5cc0
  lw    $s0, ($a0)
  addiu $t0, $t7, 0x3c
  move  $t1, $s7
.L7F062C2C:
  lw    $at, ($t7)
  addiu $t7, $t7, 0xc
  addiu $t1, $t1, 0xc
  sw    $at, -0xc($t1)
  lw    $at, -8($t7)
  sw    $at, -8($t1)
  lw    $at, -4($t7)
  bne   $t7, $t0, .L7F062C2C
   sw    $at, -4($t1)
  lw    $at, ($t7)
  lui   $fp, %hi(pPlayer) 
  addiu $fp, %lo(pPlayer) # addiu $fp, $fp, -0x5f50
  move  $s5, $zero
  move  $s6, $zero
  sw    $at, ($t1)
.L7F062C68:
  lw    $t2, ($fp)
  move  $a0, $s5
  addu  $s3, $t2, $s6
  jal   return_ammo_in_hand
   addiu $s3, $s3, 0x870
  lb    $t3, 0xf($s3)
  move  $s4, $v0
  li    $at, 23
  beql  $t3, $zero, .L7F062FC0
   addiu $s5, $s5, 1
  beq   $v0, $at, .L7F062CA8
   move  $a0, $s0
  addiu $a1, $s3, 0x1e4
  jal   sub_GAME_7F061E18
   move  $a2, $zero
  move  $s0, $v0
.L7F062CA8:
  li    $at, 19
  beq   $s4, $at, .L7F062CE0
   move  $v0, $s0
  li    $at, 18
  beq   $s4, $at, .L7F062CE0
   li    $at, 2
  beq   $s4, $at, .L7F062CE0
   li    $at, 3
  beq   $s4, $at, .L7F062CE0
   li    $at, 20
  beq   $s4, $at, .L7F062CE0
   li    $at, 21
  bnel  $s4, $at, .L7F062D7C
   lui   $t3, 0xbc00
.L7F062CE0:
  addiu $s0, $s0, 8
  lui   $t4, (0xBC000002 >> 16) # lui $t4, 0xbc00
  lui   $t5, (0x80000040 >> 16) # lui $t5, 0x8000
  ori   $t5, (0x80000040 & 0xFFFF) # ori $t5, $t5, 0x40
  ori   $t4, (0xBC000002 & 0xFFFF) # ori $t4, $t4, 2
  move  $v1, $s0
  addiu $s0, $s0, 8
  sw    $t4, ($v0)
  sw    $t5, 4($v0)
  lui   $t6, (0x03860010 >> 16) # lui $t6, 0x386
  lui   $t9, %hi(D_80032448) 
  addiu $t9, %lo(D_80032448) # addiu $t9, $t9, 0x2448
  ori   $t6, (0x03860010 & 0xFFFF) # ori $t6, $t6, 0x10
  move  $a0, $s0
  sw    $t6, ($v1)
  sw    $t9, 4($v1)
  lui   $t8, (0x03880010 >> 16) # lui $t8, 0x388
  lui   $t0, %hi(D_80032440) 
  addiu $t0, %lo(D_80032440) # addiu $t0, $t0, 0x2440
  ori   $t8, (0x03880010 & 0xFFFF) # ori $t8, $t8, 0x10
  addiu $s0, $s0, 8
  lui   $t7, (0x03840010 >> 16) # lui $t7, 0x384
  sw    $t8, ($a0)
  sw    $t0, 4($a0)
  ori   $t7, (0x03840010 & 0xFFFF) # ori $t7, $t7, 0x10
  move  $s1, $s0
  sw    $t7, ($s1)
  jal   sub_GAME_7F078474
   addiu $s0, $s0, 8
  lui   $t1, (0x03820010 >> 16) # lui $t1, 0x382
  ori   $t1, (0x03820010 & 0xFFFF) # ori $t1, $t1, 0x10
  sw    $v0, 4($s1)
  move  $s2, $s0
  sw    $t1, ($s2)
  jal   sub_GAME_7F078474
   addiu $s0, $s0, 8
  addiu $t2, $v0, 0x10
  sw    $t2, 4($s2)
  lui   $t3, (0xBC00000E >> 16) # lui $t3, 0xbc00
.L7F062D7C:
  li    $at, 0x43960000 # 300.000000
  mtc1  $at, $f14
  ori   $t3, (0xBC00000E & 0xFFFF) # ori $t3, $t3, 0xe
  move  $s1, $s0
  mtc1  $zero, $f12
  sw    $t3, ($s1)
  jal   sub_GAME_7F05997C
   addiu $s0, $s0, 8
  sw    $v0, 4($s1)
  lw    $v1, 0x300($s3)
  lh    $t4, 0xc($v1)
  slti  $at, $t4, 0x11
  bnezl $at, .L7F062E64
   lw    $v0, ($fp)
  lw    $v0, 8($v1)
  addiu $s1, $s3, 0x2f8
  move  $a0, $s1
  lw    $t5, 0x40($v0)
  beql  $t5, $zero, .L7F062E64
   lw    $v0, ($fp)
  jal   extract_id_from_object_structure_microcode
   lw    $a1, 0x44($v0)
  beqz  $v0, .L7F062DE4
   li    $at, 25
  li    $t6, 1
  sw    $t6, ($v0)
.L7F062DE4:
  bne   $s4, $at, .L7F062E34
   move  $a0, $s1
  lui   $a0, %hi(dword_CODE_bss_80075C10)
  lui   $a1, %hi(crosshairimage)
  lw    $a1, %lo(crosshairimage)($a1)
  jal   save_img_index_to_obj_ani_slot
   addiu $a0, %lo(dword_CODE_bss_80075C10) # addiu $a0, $a0, 0x5c10
  lw    $t9, 0x300($s3)
  lui   $a2, %hi(dword_CODE_bss_80075C10)
  li    $t0, 4
  lw    $t8, 8($t9)
  addiu $a2, %lo(dword_CODE_bss_80075C10) # addiu $a2, $a2, 0x5c10
  move  $a0, $s1
  lw    $a1, 0x40($t8)
  sw    $t0, 0x14($sp)
  sw    $zero, 0x10($sp)
  jal   process_monitor_animation_microcode
   move  $a3, $s0
  b     .L7F062E60
   move  $s0, $v0
.L7F062E34:
  lw    $t7, 0x300($s3)
  lui   $a2, %hi(dword_CODE_bss_80075C88)
  li    $t2, 1
  lw    $t1, 8($t7)
  addiu $a2, %lo(dword_CODE_bss_80075C88) # addiu $a2, $a2, 0x5c88
  move  $a3, $s0
  lw    $a1, 0x40($t1)
  sw    $t2, 0x14($sp)
  jal   process_monitor_animation_microcode
   sw    $zero, 0x10($sp)
  move  $s0, $v0
.L7F062E60:
  lw    $v0, ($fp)
.L7F062E64:
  li    $t3, 4
  sw    $s0, 0x98($sp)
  sw    $t3, 0xbc($sp)
  lbu   $t5, 0xfdc($v0)
  lbu   $t8, 0xfdd($v0)
  lbu   $t4, 0xfdf($v0)
  lbu   $t1, 0xfde($v0)
  sll   $t6, $t5, 0x18
  sll   $t0, $t8, 0x10
  or    $t9, $t4, $t6
  or    $t7, $t9, $t0
  sll   $t2, $t1, 8
  or    $t3, $t7, $t2
  sw    $t3, 0xc0($sp)
  sw    $zero, 0x90($sp)
  jal   sub_GAME_7F058C64
   addiu $s1, $s3, 0x2f8
  li    $at, 25
  bnel  $s4, $at, .L7F062EF4
   move  $a0, $s4
  lw    $v0, 0x220($s3)
  beql  $v0, $zero, .L7F062EF4
   move  $a0, $s4
  lw    $s0, 0x14($v0)
  move  $a0, $s7
  jal   subdraw
   move  $a1, $s0
  lw    $t5, 8($s0)
  lw    $a0, 0xc($s0)
  jal   sub_GAME_7F08BD48
   lh    $a1, 0xe($t5)
  lw    $t4, 0x224($s3)
  beql  $t4, $zero, .L7F062EF4
   move  $a0, $s4
  sw    $zero, 0x220($s3)
  move  $a0, $s4
.L7F062EF4:
  jal   check_special_attributes
   li    $a1, 1024
  beqz  $v0, .L7F062F38
   move  $a0, $s7
  lw    $t6, 0x98($sp)
  lui   $t9, 0xb600
  li    $t0, 12288
  addiu $t8, $t6, 8
  sw    $t8, 0x98($sp)
  sw    $t0, 4($t6)
  bnez  $s5, .L7F062F30
   sw    $t9, ($t6)
  li    $t1, 3
  b     .L7F062F38
   sw    $t1, 0xc8($sp)
.L7F062F30:
  li    $t7, 2
  sw    $t7, 0xc8($sp)
.L7F062F38:
  jal   subdraw
   move  $a1, $s1
  lw    $s0, 0x98($sp)
  move  $a0, $s4
  jal   check_special_attributes
   li    $a1, 1024
  beqz  $v0, .L7F062F6C
   lui   $t2, 0xb600
  move  $v0, $s0
  li    $t3, 12288
  sw    $t3, 4($v0)
  sw    $t2, ($v0)
  addiu $s0, $s0, 8
.L7F062F6C:
  lw    $t5, 0x300($s3)
  lw    $a0, 0x304($s3)
  jal   sub_GAME_7F08BD48
   lh    $a1, 0xe($t5)
  jal   sub_GAME_7F058C88
   nop   
  lui   $t4, (0xBC00000E >> 16) # lui $t4, 0xbc00
  ori   $t4, (0xBC00000E & 0xFFFF) # ori $t4, $t4, 0xe
  move  $s1, $s0
  sw    $t4, ($s1)
  jal   get_80060824
   addiu $s0, $s0, 8
  li    $at, 23
  bne   $s4, $at, .L7F062FBC
   sw    $v0, 4($s1)
  move  $a0, $s0
  addiu $a1, $s3, 0x1e4
  jal   sub_GAME_7F061E18
   move  $a2, $zero
  move  $s0, $v0
.L7F062FBC:
  addiu $s5, $s5, 1
.L7F062FC0:
  li    $at, 2
  bne   $s5, $at, .L7F062C68
   addiu $s6, $s6, 0x3a8
  lw    $t6, 0xd0($sp)
  sw    $s0, ($t6)
  lw    $ra, 0x44($sp)
  lw    $fp, 0x40($sp)
  lw    $s7, 0x3c($sp)
  lw    $s6, 0x38($sp)
  lw    $s5, 0x34($sp)
  lw    $s4, 0x30($sp)
  lw    $s3, 0x2c($sp)
  lw    $s2, 0x28($sp)
  lw    $s1, 0x24($sp)
  lw    $s0, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0xd0
");

asm(R"
glabel set_enviro_fog_for_items_in_solo_watch_menu
  addiu $sp, $sp, -0x198
  lui   $t7, %hi(D_80035D00) 
  addiu $t7, %lo(D_80035D00) # addiu $t7, $t7, 0x5d00
  sw    $ra, 0x24($sp)
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  sw    $a0, 0x198($sp)
  sw    $a2, 0x1a0($sp)
  sw    $a3, 0x1a4($sp)
  addiu $t0, $t7, 0x3c
  addiu $t6, $sp, 0x158
.L7F063038:
  lw    $at, ($t7)
  addiu $t7, $t7, 0xc
  addiu $t6, $t6, 0xc
  sw    $at, -0xc($t6)
  lw    $at, -8($t7)
  sw    $at, -8($t6)
  lw    $at, -4($t7)
  bne   $t7, $t0, .L7F063038
   sw    $at, -4($t6)
  lw    $at, ($t7)
  move  $a0, $zero
  sw    $at, ($t6)
  li    $at, 30
  beq   $a1, $at, .L7F06307C
   li    $at, 23
  bne   $a1, $at, .L7F063080
   nop   
.L7F06307C:
  li    $a1, 60
.L7F063080:
  jal   sub_GAME_7F05DA8C
   sw    $a1, 0x19c($sp)
  jal   sub_GAME_7F05CEBC
   move  $a0, $zero
  beqz  $v0, .L7F0630A8
   nop   
  jal   get_itemtype_in_hand
   move  $a0, $zero
  bnez  $v0, .L7F0630B0
   lui   $s2, %hi(pPlayer)
.L7F0630A8:
  b     .L7F0634BC
   lw    $v0, 0x198($sp)
.L7F0630B0:
  lw    $s2, %lo(pPlayer)($s2)
  lw    $a0, 0x19c($sp)
  jal   get_ptr_weapon_model_header_line
   addiu $s2, $s2, 0x810
  beqz  $v0, .L7F0634B8
   lw    $a0, 0x19c($sp)
  jal   check_special_attributes
   li    $a1, 16384
  bnezl $v0, .L7F0634BC
   lw    $v0, 0x198($sp)
  lh    $a0, 0xe($s2)
  sll   $t1, $a0, 6
  jal   sub_GAME_7F0BD714
   move  $a0, $t1
  lh    $t2, 0xe($s2)
  move  $s0, $v0
  move  $s1, $zero
  blez  $t2, .L7F06311C
   sll   $t3, $s1, 6
.L7F0630FC:
  jal   matrix_4x4_set_identity
   addu  $a0, $t3, $s0
  lh    $t4, 0xe($s2)
  addiu $s1, $s1, 1
  slt   $at, $s1, $t4
  bnezl $at, .L7F0630FC
   sll   $t3, $s1, 6
  move  $s1, $zero
.L7F06311C:
  sw    $s0, 0x144($sp)
  jal   set_objuse_flag_compute_grp_nums_set_obj_loaded
   move  $a0, $s2
  addiu $s3, $sp, 0x138
  move  $a0, $s3
  move  $a1, $s2
  jal   sub_GAME_7F075F68
   addiu $a2, $sp, 0xb8
  move  $a0, $s3
  jal   sub_GAME_7F05E978
   move  $a1, $zero
  move  $a0, $s3
  jal   sub_GAME_7F05EA94
   li    $a1, 1
  lw    $t5, 8($s2)
  lw    $a1, 4($t5)
  beql  $a1, $zero, .L7F06317C
   lw    $a0, 0x1a0($sp)
  jal   extract_id_from_object_structure_microcode
   move  $a0, $s3
  beql  $v0, $zero, .L7F06317C
   lw    $a0, 0x1a0($sp)
  sw    $zero, ($v0)
  lw    $a0, 0x1a0($sp)
.L7F06317C:
  jal   matrix_4x4_copy
   move  $a1, $s0
  lw    $t8, 4($s2)
  lui   $t9, %hi(weapon_gun_revolver) 
  addiu $t9, %lo(weapon_gun_revolver) # addiu $t9, $t9, -0x3894
  bnel  $t9, $t8, .L7F0631F4
   lw    $v0, 8($s2)
  lw    $v0, 8($s2)
  addiu $a1, $sp, 0x74
  lw    $v1, 0x10($v0)
  beql  $v1, $zero, .L7F0631CC
   lw    $v1, 0x14($v0)
  jal   init_something_copy_posdata_to_it
   lw    $a0, 4($v1)
  lw    $a0, 0x1a0($sp)
  addiu $a1, $sp, 0x74
  jal   matrix_4x4_multiply
   addiu $a2, $s0, 0xc0
  lw    $v0, 8($s2)
  lw    $v1, 0x14($v0)
.L7F0631CC:
  addiu $a1, $sp, 0x74
  beql  $v1, $zero, .L7F0631F4
   lw    $v0, 8($s2)
  jal   init_something_copy_posdata_to_it
   lw    $a0, 4($v1)
  lw    $a0, 0x1a0($sp)
  addiu $a1, $sp, 0x74
  jal   matrix_4x4_multiply
   addiu $a2, $s0, 0x100
  lw    $v0, 8($s2)
.L7F0631F4:
  lw    $a0, 0x18($v0)
  beql  $a0, $zero, .L7F063240
   lw    $a0, 0x1c($v0)
  lw    $t0, 4($a0)
  move  $a1, $zero
  jal   sub_GAME_7F06C570
   sw    $t0, 0x5c($sp)
  sw    $v0, 0x58($sp)
  lw    $a0, 0x5c($sp)
  jal   init_something_copy_posdata_to_it
   addiu $a1, $sp, 0x74
  lw    $t7, 0x58($sp)
  lw    $a0, 0x1a0($sp)
  addiu $a1, $sp, 0x74
  sll   $t6, $t7, 6
  jal   matrix_4x4_multiply
   addu  $a2, $t6, $s0
  lw    $v0, 8($s2)
  lw    $a0, 0x1c($v0)
.L7F063240:
  beql  $a0, $zero, .L7F063284
   lh    $t4, 0xc($s2)
  lw    $t1, 4($a0)
  move  $a1, $zero
  jal   sub_GAME_7F06C570
   sw    $t1, 0x54($sp)
  sw    $v0, 0x50($sp)
  lw    $a0, 0x54($sp)
  jal   init_something_copy_posdata_to_it
   addiu $a1, $sp, 0x74
  lw    $t2, 0x50($sp)
  lw    $a0, 0x1a0($sp)
  addiu $a1, $sp, 0x74
  sll   $t3, $t2, 6
  jal   matrix_4x4_multiply
   addu  $a2, $t3, $s0
  lh    $t4, 0xc($s2)
.L7F063284:
  move  $s0, $zero
  slti  $at, $t4, 0x13
  bnez  $at, .L7F0632F4
   nop   
  lw    $t5, 8($s2)
.L7F063298:
  addu  $t9, $t5, $s0
  lw    $a1, 0x48($t9)
  beql  $a1, $zero, .L7F0632C0
   lw    $t0, 8($s2)
  jal   extract_id_from_object_structure_microcode
   move  $a0, $s3
  beqz  $v0, .L7F0632BC
   li    $t8, 1
  sw    $t8, ($v0)
.L7F0632BC:
  lw    $t0, 8($s2)
.L7F0632C0:
  addu  $t7, $t0, $s0
  lw    $a1, 0x5c($t7)
  beql  $a1, $zero, .L7F0632E8
   addiu $s0, $s0, 4
  jal   extract_id_from_object_structure_microcode
   move  $a0, $s3
  beqz  $v0, .L7F0632E4
   li    $t6, 1
  sw    $t6, ($v0)
.L7F0632E4:
  addiu $s0, $s0, 4
.L7F0632E8:
  li    $at, 20
  bnel  $s0, $at, .L7F063298
   lw    $t5, 8($s2)
.L7F0632F4:
  jal   sub_GAME_7F06EFC4
   move  $a0, $s3
  lw    $v0, 0x19c($sp)
  li    $at, 19
  lui   $t1, (0xBC000002 >> 16) # lui $t1, 0xbc00
  beq   $v0, $at, .L7F06333C
   ori   $t1, (0xBC000002 & 0xFFFF) # ori $t1, $t1, 2
  li    $at, 18
  beq   $v0, $at, .L7F06333C
   li    $at, 2
  beq   $v0, $at, .L7F06333C
   li    $at, 3
  beq   $v0, $at, .L7F06333C
   li    $at, 20
  beq   $v0, $at, .L7F06333C
   li    $at, 21
  bnel  $v0, $at, .L7F0633D8
   lh    $t2, 0xc($s2)
.L7F06333C:
  lw    $v0, 0x198($sp)
  lui   $t2, (0x80000040 >> 16) # lui $t2, 0x8000
  ori   $t2, (0x80000040 & 0xFFFF) # ori $t2, $t2, 0x40
  addiu $v1, $v0, 8
  lui   $t3, (0x03860010 >> 16) # lui $t3, 0x386
  lui   $t4, %hi(D_80032448) 
  sw    $t2, 4($v0)
  sw    $t1, ($v0)
  addiu $t4, %lo(D_80032448) # addiu $t4, $t4, 0x2448
  ori   $t3, (0x03860010 & 0xFFFF) # ori $t3, $t3, 0x10
  addiu $a0, $v1, 8
  sw    $t3, ($v1)
  sw    $t4, 4($v1)
  lui   $t5, (0x03880010 >> 16) # lui $t5, 0x388
  lui   $t9, %hi(D_80032440) 
  addiu $t9, %lo(D_80032440) # addiu $t9, $t9, 0x2440
  ori   $t5, (0x03880010 & 0xFFFF) # ori $t5, $t5, 0x10
  addiu $s0, $a0, 8
  lui   $t8, (0x03840010 >> 16) # lui $t8, 0x384
  sw    $t5, ($a0)
  sw    $t9, 4($a0)
  ori   $t8, (0x03840010 & 0xFFFF) # ori $t8, $t8, 0x10
  sw    $t8, ($s0)
  addiu $a1, $s0, 8
  jal   sub_GAME_7F078474
   sw    $a1, 0x198($sp)
  sw    $v0, 4($s0)
  lw    $t0, 0x198($sp)
  lui   $t6, (0x03820010 >> 16) # lui $t6, 0x382
  ori   $t6, (0x03820010 & 0xFFFF) # ori $t6, $t6, 0x10
  addiu $t7, $t0, 8
  sw    $t7, 0x198($sp)
  sw    $t6, ($t0)
  jal   sub_GAME_7F078474
   sw    $t0, 0x34($sp)
  lw    $v1, 0x34($sp)
  addiu $t1, $v0, 0x10
  sw    $t1, 4($v1)
  lh    $t2, 0xc($s2)
.L7F0633D8:
  slti  $at, $t2, 0x11
  bnezl $at, .L7F063410
   lw    $v0, 0x1a4($sp)
  lw    $v0, 8($s2)
  move  $a0, $s3
  lw    $t3, 0x40($v0)
  beql  $t3, $zero, .L7F063410
   lw    $v0, 0x1a4($sp)
  jal   extract_id_from_object_structure_microcode
   lw    $a1, 0x44($v0)
  beql  $v0, $zero, .L7F063410
   lw    $v0, 0x1a4($sp)
  sw    $zero, ($v0)
  lw    $v0, 0x1a4($sp)
.L7F063410:
  lw    $t4, 0x198($sp)
  addiu $a0, $sp, 0x158
  slti  $at, $v0, 0xff
  bnez  $at, .L7F063438
   sw    $t4, 0x164($sp)
  lw    $t9, 0x1a8($sp)
  li    $t5, 4
  sw    $t5, 0x188($sp)
  b     .L7F06344C
   sw    $t9, 0x18c($sp)
.L7F063438:
  lw    $t0, 0x1a8($sp)
  li    $t8, 5
  sw    $t8, 0x188($sp)
  sw    $v0, 0x18c($sp)
  sw    $t0, 0x190($sp)
.L7F06344C:
  sw    $zero, 0x15c($sp)
  jal   subdraw
   move  $a1, $s3
  lw    $t7, 0x164($sp)
  jal   sub_GAME_7F058C64
   sw    $t7, 0x198($sp)
  lh    $t6, 0xe($s2)
  move  $s0, $zero
  blez  $t6, .L7F0634B0
   nop   
  lw    $t1, 0x144($sp)
.L7F063478:
  addiu $a1, $sp, 0x74
  jal   matrix_4x4_copy
   addu  $a0, $t1, $s0
  lw    $t3, 0x144($sp)
  sll   $t2, $s1, 6
  addiu $a0, $sp, 0x74
  jal   sub_GAME_7F058C9C
   addu  $a1, $t2, $t3
  lh    $t4, 0xe($s2)
  addiu $s1, $s1, 1
  addiu $s0, $s0, 0x40
  slt   $at, $s1, $t4
  bnezl $at, .L7F063478
   lw    $t1, 0x144($sp)
.L7F0634B0:
  jal   sub_GAME_7F058C88
   nop   
.L7F0634B8:
  lw    $v0, 0x198($sp)
.L7F0634BC:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x198
");

asm(R"
glabel sub_GAME_7F0634D8
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  li    $t6, -256
  jal   set_enviro_fog_for_items_in_solo_watch_menu
   sw    $t6, 0x10($sp)
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0634FC
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F0634D8
   li    $a3, 255
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F06351C
  addiu $sp, $sp, -0x60
  sw    $s0, 0x18($sp)
  lw    $s0, 0x78($sp)
  sw    $ra, 0x1c($sp)
  sw    $a1, 0x64($sp)
  sw    $a2, 0x68($sp)
  sw    $a3, 0x6c($sp)
  jal   init_something_copy_posdata_to_it
   move  $a1, $s0
  lw    $a0, 0x64($sp)
  jal   matrix_4x4_multiply_in_place
   move  $a1, $s0
  lw    $a0, 0x68($sp)
  jal   matrix_4x4_multiply_in_place
   move  $a1, $s0
  lw    $a0, 0x6c($sp)
  jal   matrix_4x4_multiply_in_place
   move  $a1, $s0
  lw    $a0, 0x70($sp)
  jal   init_something_copy_posdata_to_it
   addiu $a1, $sp, 0x20
  addiu $a0, $sp, 0x20
  jal   matrix_4x4_multiply_in_place
   move  $a1, $s0
  lw    $a0, 0x74($sp)
  jal   matrix_4x4_multiply_in_place
   move  $a1, $s0
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x60
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80053ED4
.word 0x40c90fdb /*6.2831855*/
glabel D_80053ED8
.word 0x3f19999a /*0.60000002*/
glabel D_80053EDC
.word 0x40c90fdb /*6.2831855*/
glabel D_80053EE0
.word 0x3f19999a /*0.60000002*/
glabel D_80053EE4
.word 0xbf860a92 /*-1.0471976*/
glabel D_80053EE8
.word 0x40c90fdb /*6.2831855*/
glabel D_80053EEC
.word 0x3f19999a /*0.60000002*/
glabel D_80053EF0
.word 0x40c90fdb /*6.2831855*/
glabel D_80053EF4
.word 0x3f19999a /*0.60000002*/
glabel D_80053EF8
.word 0xbe32b8c3 /*-0.17453294*/
glabel D_80053EFC
.word 0x3f860a92 /*1.0471976*/
glabel D_80053F00
.word 0x3e32b8c3 /*0.17453294*/
glabel D_80053F04
.word 0x3f860a92 /*1.0471976*/
glabel D_80053F08
.word 0xbe32b8c3 /*-0.17453294*/
glabel D_80053F0C
.word 0x3e32b8c3 /*0.17453294*/
glabel D_80053F10
.word 0x3e32b8c3 /*0.17453294*/
glabel D_80053F14
.word 0xbe32b8c3 /*-0.17453294*/
glabel D_80053F18
.word 0xbf65c8fa /*-0.89759791*/
glabel D_80053F1C
.word 0xbe32b8c3 /*-0.17453294*/
glabel D_80053F20
.word 0x40490fdb /*3.1415927*/
.text
glabel sub_GAME_7F06359C
  addiu $sp, $sp, -0x538
  lui   $t7, %hi(D_80035D04+0x3C) 
  sw    $s3, 0x54($sp)
  sw    $s2, 0x50($sp)
  addiu $t7, %lo(D_80035D04+0x3C) # addiu $t7, $t7, 0x5d40
  move  $s2, $a2
  move  $s3, $a3
  sw    $ra, 0x6c($sp)
  sw    $fp, 0x68($sp)
  sw    $s7, 0x64($sp)
  sw    $s6, 0x60($sp)
  sw    $s5, 0x5c($sp)
  sw    $s4, 0x58($sp)
  sw    $s1, 0x4c($sp)
  sw    $s0, 0x48($sp)
  sdc1  $f24, 0x40($sp)
  sdc1  $f22, 0x38($sp)
  sdc1  $f20, 0x30($sp)
  sw    $a0, 0x538($sp)
  sw    $a1, 0x53c($sp)
  addiu $t0, $t7, 0x3c
  addiu $t6, $sp, 0x4f8
.L7F0635F4:
  lw    $at, ($t7)
  addiu $t7, $t7, 0xc
  addiu $t6, $t6, 0xc
  sw    $at, -0xc($t6)
  lw    $at, -8($t7)
  sw    $at, -8($t6)
  lw    $at, -4($t7)
  bne   $t7, $t0, .L7F0635F4
   sw    $at, -4($t6)
  lw    $at, ($t7)
  move  $a0, $zero
  li    $a1, 85
  jal   sub_GAME_7F05DA8C
   sw    $at, ($t6)
  jal   sub_GAME_7F05CEBC
   move  $a0, $zero
  beqz  $v0, .L7F06364C
   nop   
  jal   get_itemtype_in_hand
   move  $a0, $zero
  bnez  $v0, .L7F063654
   nop   
.L7F06364C:
  b     .L7F064328
   lw    $v0, 0x538($sp)
.L7F063654:
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lh    $a0, 0x81e($v0)
  addiu $v0, $v0, 0x810
  sw    $v0, 0x3d8($sp)
  sll   $t1, $a0, 6
  jal   sub_GAME_7F0BD714
   move  $a0, $t1
  move  $s7, $v0
  jal   set_objuse_flag_compute_grp_nums_set_obj_loaded
   lw    $a0, 0x3d8($sp)
  lw    $a1, 0x3d8($sp)
  addiu $a0, $sp, 0x4d8
  jal   sub_GAME_7F075F68
   addiu $a2, $sp, 0x460
  sw    $s7, 0x4e4($sp)
  lw    $a0, 0x53c($sp)
  jal   matrix_4x4_copy
   move  $a1, $s7
  li    $t2, 4
  sw    $t2, 0x70($sp)
  li    $s1, 1
  lw    $s4, 0x54c($sp)
.L7F0636B0:
  lw    $t3, 0x3d8($sp)
  lw    $t5, 0x70($sp)
  li    $at, 2
  lw    $t4, 8($t3)
  addiu $a1, $sp, 0x41c
  addu  $t9, $t4, $t5
  lw    $t8, ($t9)
  bne   $s1, $at, .L7F06377C
   lw    $s0, 4($t8)
  jal   get_cur_controller_horz_stick_pos
   lb    $a0, ($s4)
  mtc1  $v0, $f4
  lui   $at, %hi(D_80053ED4)
  lwc1  $f10, %lo(D_80053ED4)($at)
  cvt.s.w $f6, $f4
  lui   $at, %hi(D_80053ED8)
  lwc1  $f18, %lo(D_80053ED8)($at)
  li    $at, 0x43B40000 # 360.000000
  addiu $a1, $sp, 0x41c
  neg.s $f8, $f6
  mtc1  $at, $f6
  mul.s $f16, $f8, $f10
  nop   
  mul.s $f4, $f16, $f18
  jal   sub_GAME_7F058688
   div.s $f12, $f4, $f6
  jal   get_cur_controller_vert_stick_pos
   lb    $a0, ($s4)
  mtc1  $v0, $f8
  lui   $at, %hi(D_80053EDC)
  lwc1  $f18, %lo(D_80053EDC)($at)
  cvt.s.w $f10, $f8
  lui   $at, %hi(D_80053EE0)
  lwc1  $f6, %lo(D_80053EE0)($at)
  li    $at, 0x43B40000 # 360.000000
  addiu $a1, $sp, 0x3dc
  neg.s $f16, $f10
  mtc1  $at, $f10
  mul.s $f4, $f16, $f18
  nop   
  mul.s $f8, $f4, $f6
  jal   sub_GAME_7F058570
   div.s $f12, $f8, $f10
  addiu $a0, $sp, 0x3dc
  jal   matrix_4x4_multiply_in_place
   addiu $a1, $sp, 0x41c
  move  $a0, $s0
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   addiu $a1, $sp, 0x41c
  b     .L7F063788
   sll   $t0, $s1, 6
.L7F06377C:
  jal   init_something_copy_posdata_to_it
   move  $a0, $s0
  sll   $t0, $s1, 6
.L7F063788:
  addu  $a2, $t0, $s7
  lw    $a0, 0x53c($sp)
  jal   matrix_4x4_multiply
   addiu $a1, $sp, 0x41c
  lw    $t7, 0x70($sp)
  addiu $s1, $s1, 1
  slti  $at, $s1, 0xd
  addiu $t6, $t7, 4
  bnez  $at, .L7F0636B0
   sw    $t6, 0x70($sp)
  jal   sub_GAME_7F06EFC4
   addiu $a0, $sp, 0x4d8
  lw    $t1, 0x538($sp)
  slti  $at, $s2, 0xff
  bnez  $at, .L7F0637D4
   sw    $t1, 0x504($sp)
  li    $t2, 1
  b     .L7F0637E8
   sw    $t2, 0x528($sp)
.L7F0637D4:
  li    $t3, 5
  li    $t4, -256
  sw    $t3, 0x528($sp)
  sw    $s2, 0x52c($sp)
  sw    $t4, 0x530($sp)
.L7F0637E8:
  li    $t5, 1
  sw    $t5, 0x4fc($sp)
  addiu $a0, $sp, 0x4f8
  jal   subdraw
   addiu $a1, $sp, 0x4d8
  lw    $t9, 0x504($sp)
  jal   sub_GAME_7F058C64
   sw    $t9, 0x538($sp)
  lw    $t8, 0x3d8($sp)
  move  $s1, $zero
  move  $s0, $zero
  lh    $t0, 0xe($t8)
  blez  $t0, .L7F063860
   nop   
  lw    $t7, 0x4e4($sp)
.L7F063824:
  addiu $a1, $sp, 0x41c
  jal   matrix_4x4_copy
   addu  $a0, $t7, $s0
  lw    $t1, 0x4e4($sp)
  sll   $t6, $s1, 6
  addiu $a0, $sp, 0x41c
  jal   sub_GAME_7F058C9C
   addu  $a1, $t6, $t1
  lw    $t2, 0x3d8($sp)
  addiu $s1, $s1, 1
  addiu $s0, $s0, 0x40
  lh    $t3, 0xe($t2)
  slt   $at, $s1, $t3
  bnezl $at, .L7F063824
   lw    $t7, 0x4e4($sp)
.L7F063860:
  jal   sub_GAME_7F058C88
   nop   
  beqz  $s3, .L7F064324
   lw    $t4, 0x3d8($sp)
  lw    $t5, 8($t4)
  move  $s1, $zero
  lw    $a1, 0x34($t5)
  beql  $a1, $zero, .L7F063894
   lw    $t9, 0x3d8($sp)
  jal   extract_id_from_object_structure_microcode
   addiu $a0, $sp, 0x4d8
  sw    $zero, ($v0)
  lw    $t9, 0x3d8($sp)
.L7F063894:
  lh    $a0, 0xe($t9)
  sll   $t8, $a0, 6
  jal   sub_GAME_7F0BD714
   move  $a0, $t8
  lui   $at, %hi(D_80053EE4)
  lwc1  $f22, %lo(D_80053EE4)($at)
  li    $at, 0xC1200000 # -10.000000
  mtc1  $at, $f20
  mtc1  $zero, $f24
  move  $s7, $v0
  sw    $v0, 0x4e4($sp)
  lw    $fp, 0x548($sp)
  addiu $s6, $sp, 0x1cc
  addiu $s5, $sp, 0x20c
  addiu $s3, $sp, 0x24c
  addiu $s2, $sp, 0x28c
  addiu $s0, $sp, 0x38c
  li    $at, 0xC0A00000 # -5.000000
.L7F0638DC:
  mtc1  $at, $f0
  li    $at, 0xC3280000 # -168.000000
  mtc1  $at, $f2
  li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f16
  mfc1  $a1, $f0
  mfc1  $a3, $f2
  move  $a0, $s5
  lui   $a2, 0x44fa
  swc1  $f24, 0x14($sp)
  swc1  $f24, 0x1c($sp)
  swc1  $f24, 0x20($sp)
  swc1  $f0, 0x10($sp)
  swc1  $f2, 0x18($sp)
  jal   sub_GAME_7F059694
   swc1  $f16, 0x24($sp)
  li    $at, 0xC0A00000 # -5.000000
  mtc1  $at, $f0
  li    $at, 0xC3280000 # -168.000000
  mtc1  $at, $f2
  li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f18
  mfc1  $a1, $f0
  mfc1  $a3, $f2
  move  $a0, $s0
  lui   $a2, 0x44fa
  swc1  $f24, 0x14($sp)
  swc1  $f24, 0x1c($sp)
  swc1  $f24, 0x20($sp)
  swc1  $f0, 0x10($sp)
  swc1  $f2, 0x18($sp)
  jal   sub_GAME_7F059694
   swc1  $f18, 0x24($sp)
  jal   matrix_4x4_set_identity
   move  $a0, $s3
  jal   matrix_4x4_set_identity
   move  $a0, $s6
  move  $a0, $s6
  jal   matrix_4x4_copy
   addiu $a1, $sp, 0x2cc
  li    $at, 2
  bnel  $s1, $at, .L7F063A78
   li    $at, 11
  lw    $at, 0x58($fp)
  addiu $a0, $sp, 0x1c0
  addiu $a1, $sp, 0x34c
  sw    $at, ($a0)
  lw    $t7, 0x5c($fp)
  sw    $t7, 4($a0)
  lw    $at, 0x60($fp)
  jal   init_something_copy_posdata_to_it
   sw    $at, 8($a0)
  jal   get_cur_controller_horz_stick_pos
   lb    $a0, ($s4)
  mtc1  $v0, $f4
  lui   $at, %hi(D_80053EE8)
  lwc1  $f10, %lo(D_80053EE8)($at)
  cvt.s.w $f6, $f4
  lui   $at, %hi(D_80053EEC)
  lwc1  $f18, %lo(D_80053EEC)($at)
  li    $at, 0x43B40000 # 360.000000
  addiu $a1, $sp, 0x41c
  neg.s $f8, $f6
  mtc1  $at, $f6
  mul.s $f16, $f8, $f10
  nop   
  mul.s $f4, $f16, $f18
  jal   sub_GAME_7F058688
   div.s $f12, $f4, $f6
  jal   get_cur_controller_vert_stick_pos
   lb    $a0, ($s4)
  mtc1  $v0, $f8
  lui   $at, %hi(D_80053EF0)
  lwc1  $f18, %lo(D_80053EF0)($at)
  cvt.s.w $f10, $f8
  lui   $at, %hi(D_80053EF4)
  lwc1  $f6, %lo(D_80053EF4)($at)
  li    $at, 0x43B40000 # 360.000000
  addiu $a1, $sp, 0x3dc
  neg.s $f16, $f10
  mtc1  $at, $f10
  mul.s $f4, $f16, $f18
  nop   
  mul.s $f8, $f4, $f6
  jal   sub_GAME_7F058570
   div.s $f12, $f8, $f10
  addiu $a0, $sp, 0x3dc
  jal   matrix_4x4_multiply_in_place
   addiu $a1, $sp, 0x41c
  addiu $a0, $sp, 0x34c
  jal   matrix_4x4_multiply_in_place
   addiu $a1, $sp, 0x41c
  move  $a0, $s5
  addiu $a1, $sp, 0x41c
  jal   matrix_4x4_multiply
   addiu $a2, $sp, 0x30c
  sll   $t6, $s1, 6
  addu  $a1, $t6, $s7
  jal   matrix_4x4_copy
   addiu $a0, $sp, 0x30c
  b     .L7F064290
   addiu $s1, $s1, 1
  li    $at, 11
.L7F063A78:
  bne   $s1, $at, .L7F063B28
   lui   $t2, %hi(D_80035D44+0x3C) 
  addiu $t2, %lo(D_80035D44+0x3C) # addiu $t2, $t2, 0x5d80
  lw    $at, ($t2)
  addiu $t1, $sp, 0x1a8
  lw    $t4, 4($t2)
  sw    $at, ($t1)
  lw    $at, 8($t2)
  sw    $t4, 4($t1)
  addiu $t5, $sp, 0x1b4
  sw    $at, 8($t1)
  lw    $at, 0xc4($fp)
  li    $a1, 16
  sw    $at, ($t5)
  lw    $t8, 0xc8($fp)
  sw    $t8, 4($t5)
  lw    $at, 0xcc($fp)
  sw    $at, 8($t5)
  jal   get_controller_buttons_held
   lb    $a0, ($s4)
  beqz  $v0, .L7F063ADC
   lui   $at, %hi(D_80053EF8)
  lwc1  $f12, %lo(D_80053EF8)($at)
  jal   sub_GAME_7F0585FC
   move  $a1, $s3
.L7F063ADC:
  lui   $at, %hi(D_80053EFC)
  lwc1  $f12, %lo(D_80053EFC)($at)
  jal   sub_GAME_7F058570
   move  $a1, $s2
  addiu $t0, $sp, 0x1b4
  sw    $t0, 0x10($sp)
  addiu $a0, $sp, 0x1a8
  move  $a1, $s3
  move  $a2, $s2
  move  $a3, $s6
  sw    $s5, 0x14($sp)
  jal   sub_GAME_7F06351C
   sw    $s0, 0x18($sp)
  sll   $t7, $s1, 6
  addu  $a1, $t7, $s7
  jal   matrix_4x4_copy
   move  $a0, $s0
  b     .L7F064290
   addiu $s1, $s1, 1
.L7F063B28:
  li    $at, 4
  bne   $s1, $at, .L7F063BD4
   lui   $t3, %hi(D_80035D44+0x48) 
  addiu $t3, %lo(D_80035D44+0x48) # addiu $t3, $t3, 0x5d8c
  lw    $at, ($t3)
  addiu $t6, $sp, 0x190
  lw    $t2, 4($t3)
  sw    $at, ($t6)
  lw    $at, 8($t3)
  sw    $t2, 4($t6)
  addiu $t4, $sp, 0x19c
  sw    $at, 8($t6)
  lw    $at, 0x70($fp)
  li    $a1, 8
  sw    $at, ($t4)
  lw    $t5, 0x74($fp)
  sw    $t5, 4($t4)
  lw    $at, 0x78($fp)
  sw    $at, 8($t4)
  jal   get_controller_buttons_held
   lb    $a0, ($s4)
  beqz  $v0, .L7F063B90
   mov.s $f12, $f22
  lwc1  $f16, 0x194($sp)
  add.s $f18, $f16, $f20
  swc1  $f18, 0x194($sp)
.L7F063B90:
  jal   sub_GAME_7F058570
   move  $a1, $s2
  addiu $t8, $sp, 0x19c
  sw    $t8, 0x10($sp)
  addiu $a0, $sp, 0x190
  move  $a1, $s3
  move  $a2, $s2
  move  $a3, $s6
  sw    $s5, 0x14($sp)
  jal   sub_GAME_7F06351C
   sw    $s0, 0x18($sp)
  sll   $t0, $s1, 6
  addu  $a1, $t0, $s7
  jal   matrix_4x4_copy
   move  $a0, $s0
  b     .L7F064290
   addiu $s1, $s1, 1
.L7F063BD4:
  li    $at, 5
  bne   $s1, $at, .L7F063C80
   lui   $t1, %hi(D_80035D44+0x54) 
  addiu $t1, %lo(D_80035D44+0x54) # addiu $t1, $t1, 0x5d98
  lw    $at, ($t1)
  addiu $t7, $sp, 0x178
  lw    $t3, 4($t1)
  sw    $at, ($t7)
  lw    $at, 8($t1)
  sw    $t3, 4($t7)
  addiu $t2, $sp, 0x184
  sw    $at, 8($t7)
  lw    $at, 0x7c($fp)
  li    $a1, 4
  sw    $at, ($t2)
  lw    $t4, 0x80($fp)
  sw    $t4, 4($t2)
  lw    $at, 0x84($fp)
  sw    $at, 8($t2)
  jal   get_controller_buttons_held
   lb    $a0, ($s4)
  beqz  $v0, .L7F063C3C
   mov.s $f12, $f22
  lwc1  $f4, 0x17c($sp)
  add.s $f6, $f4, $f20
  swc1  $f6, 0x17c($sp)
.L7F063C3C:
  jal   sub_GAME_7F058570
   move  $a1, $s2
  addiu $t5, $sp, 0x184
  sw    $t5, 0x10($sp)
  addiu $a0, $sp, 0x178
  move  $a1, $s3
  move  $a2, $s2
  move  $a3, $s6
  sw    $s5, 0x14($sp)
  jal   sub_GAME_7F06351C
   sw    $s0, 0x18($sp)
  sll   $t8, $s1, 6
  addu  $a1, $t8, $s7
  jal   matrix_4x4_copy
   move  $a0, $s0
  b     .L7F064290
   addiu $s1, $s1, 1
.L7F063C80:
  li    $at, 6
  bne   $s1, $at, .L7F063D2C
   lui   $t6, %hi(D_80035D44+0x60) 
  addiu $t6, %lo(D_80035D44+0x60) # addiu $t6, $t6, 0x5da4
  lw    $at, ($t6)
  addiu $t0, $sp, 0x160
  lw    $t1, 4($t6)
  sw    $at, ($t0)
  lw    $at, 8($t6)
  sw    $t1, 4($t0)
  addiu $t3, $sp, 0x16c
  sw    $at, 8($t0)
  lw    $at, 0x88($fp)
  li    $a1, 2
  sw    $at, ($t3)
  lw    $t2, 0x8c($fp)
  sw    $t2, 4($t3)
  lw    $at, 0x90($fp)
  sw    $at, 8($t3)
  jal   get_controller_buttons_held
   lb    $a0, ($s4)
  beqz  $v0, .L7F063CE8
   mov.s $f12, $f22
  lwc1  $f8, 0x164($sp)
  add.s $f10, $f8, $f20
  swc1  $f10, 0x164($sp)
.L7F063CE8:
  jal   sub_GAME_7F058570
   move  $a1, $s2
  addiu $t4, $sp, 0x16c
  sw    $t4, 0x10($sp)
  addiu $a0, $sp, 0x160
  move  $a1, $s3
  move  $a2, $s2
  move  $a3, $s6
  sw    $s5, 0x14($sp)
  jal   sub_GAME_7F06351C
   sw    $s0, 0x18($sp)
  sll   $t5, $s1, 6
  addu  $a1, $t5, $s7
  jal   matrix_4x4_copy
   move  $a0, $s0
  b     .L7F064290
   addiu $s1, $s1, 1
.L7F063D2C:
  li    $at, 7
  bne   $s1, $at, .L7F063DD8
   lui   $t7, %hi(D_80035D44+0x6C) 
  addiu $t7, %lo(D_80035D44+0x6C) # addiu $t7, $t7, 0x5db0
  lw    $at, ($t7)
  addiu $t8, $sp, 0x148
  lw    $t6, 4($t7)
  sw    $at, ($t8)
  lw    $at, 8($t7)
  sw    $t6, 4($t8)
  addiu $t1, $sp, 0x154
  sw    $at, 8($t8)
  lw    $at, 0x94($fp)
  li    $a1, 1
  sw    $at, ($t1)
  lw    $t3, 0x98($fp)
  sw    $t3, 4($t1)
  lw    $at, 0x9c($fp)
  sw    $at, 8($t1)
  jal   get_controller_buttons_held
   lb    $a0, ($s4)
  beqz  $v0, .L7F063D94
   mov.s $f12, $f22
  lwc1  $f16, 0x14c($sp)
  add.s $f18, $f16, $f20
  swc1  $f18, 0x14c($sp)
.L7F063D94:
  jal   sub_GAME_7F058570
   move  $a1, $s2
  addiu $t2, $sp, 0x154
  sw    $t2, 0x10($sp)
  addiu $a0, $sp, 0x148
  move  $a1, $s3
  move  $a2, $s2
  move  $a3, $s6
  sw    $s5, 0x14($sp)
  jal   sub_GAME_7F06351C
   sw    $s0, 0x18($sp)
  sll   $t4, $s1, 6
  addu  $a1, $t4, $s7
  jal   matrix_4x4_copy
   move  $a0, $s0
  b     .L7F064290
   addiu $s1, $s1, 1
.L7F063DD8:
  li    $at, 9
  bne   $s1, $at, .L7F063E84
   lui   $t0, %hi(D_80035D44+0x78) 
  addiu $t0, %lo(D_80035D44+0x78) # addiu $t0, $t0, 0x5dbc
  lw    $at, ($t0)
  addiu $t5, $sp, 0x130
  lw    $t7, 4($t0)
  sw    $at, ($t5)
  lw    $at, 8($t0)
  sw    $t7, 4($t5)
  addiu $t6, $sp, 0x13c
  sw    $at, 8($t5)
  lw    $at, 0xac($fp)
  li    $a1, 16384
  sw    $at, ($t6)
  lw    $t1, 0xb0($fp)
  sw    $t1, 4($t6)
  lw    $at, 0xb4($fp)
  sw    $at, 8($t6)
  jal   get_controller_buttons_held
   lb    $a0, ($s4)
  beqz  $v0, .L7F063E40
   mov.s $f12, $f22
  lwc1  $f4, 0x134($sp)
  add.s $f6, $f4, $f20
  swc1  $f6, 0x134($sp)
.L7F063E40:
  jal   sub_GAME_7F058570
   move  $a1, $s2
  addiu $t3, $sp, 0x13c
  sw    $t3, 0x10($sp)
  addiu $a0, $sp, 0x130
  move  $a1, $s3
  move  $a2, $s2
  move  $a3, $s6
  sw    $s5, 0x14($sp)
  jal   sub_GAME_7F06351C
   sw    $s0, 0x18($sp)
  sll   $t2, $s1, 6
  addu  $a1, $t2, $s7
  jal   matrix_4x4_copy
   move  $a0, $s0
  b     .L7F064290
   addiu $s1, $s1, 1
.L7F063E84:
  li    $at, 8
  bne   $s1, $at, .L7F063F30
   lui   $t8, %hi(D_80035D44+0x84) 
  addiu $t8, %lo(D_80035D44+0x84) # addiu $t8, $t8, 0x5dc8
  lw    $at, ($t8)
  addiu $t4, $sp, 0x118
  lw    $t0, 4($t8)
  sw    $at, ($t4)
  lw    $at, 8($t8)
  sw    $t0, 4($t4)
  addiu $t7, $sp, 0x124
  sw    $at, 8($t4)
  lw    $at, 0xa0($fp)
  li    $a1, 32768
  sw    $at, ($t7)
  lw    $t6, 0xa4($fp)
  sw    $t6, 4($t7)
  lw    $at, 0xa8($fp)
  sw    $at, 8($t7)
  jal   get_controller_buttons_held
   lb    $a0, ($s4)
  beqz  $v0, .L7F063EEC
   mov.s $f12, $f22
  lwc1  $f8, 0x11c($sp)
  add.s $f10, $f8, $f20
  swc1  $f10, 0x11c($sp)
.L7F063EEC:
  jal   sub_GAME_7F058570
   move  $a1, $s2
  addiu $t1, $sp, 0x124
  sw    $t1, 0x10($sp)
  addiu $a0, $sp, 0x118
  move  $a1, $s3
  move  $a2, $s2
  move  $a3, $s6
  sw    $s5, 0x14($sp)
  jal   sub_GAME_7F06351C
   sw    $s0, 0x18($sp)
  sll   $t3, $s1, 6
  addu  $a1, $t3, $s7
  jal   matrix_4x4_copy
   move  $a0, $s0
  b     .L7F064290
   addiu $s1, $s1, 1
.L7F063F30:
  li    $at, 10
  bne   $s1, $at, .L7F063FE4
   lui   $t5, %hi(D_80035D44+0x90) 
  addiu $t5, %lo(D_80035D44+0x90) # addiu $t5, $t5, 0x5dd4
  lw    $at, ($t5)
  addiu $t2, $sp, 0x100
  lw    $t8, 4($t5)
  sw    $at, ($t2)
  lw    $at, 8($t5)
  sw    $t8, 4($t2)
  addiu $t0, $sp, 0x10c
  sw    $at, 8($t2)
  lw    $at, 0xb8($fp)
  li    $a1, 32
  sw    $at, ($t0)
  lw    $t7, 0xbc($fp)
  sw    $t7, 4($t0)
  lw    $at, 0xc0($fp)
  sw    $at, 8($t0)
  jal   get_controller_buttons_held
   lb    $a0, ($s4)
  beqz  $v0, .L7F063F98
   lui   $at, %hi(D_80053F00)
  lwc1  $f12, %lo(D_80053F00)($at)
  jal   sub_GAME_7F0585FC
   move  $a1, $s3
.L7F063F98:
  lui   $at, %hi(D_80053F04)
  lwc1  $f12, %lo(D_80053F04)($at)
  jal   sub_GAME_7F058570
   move  $a1, $s2
  addiu $t6, $sp, 0x10c
  sw    $t6, 0x10($sp)
  addiu $a0, $sp, 0x100
  move  $a1, $s3
  move  $a2, $s2
  move  $a3, $s6
  sw    $s5, 0x14($sp)
  jal   sub_GAME_7F06351C
   sw    $s0, 0x18($sp)
  sll   $t1, $s1, 6
  addu  $a1, $t1, $s7
  jal   matrix_4x4_copy
   move  $a0, $s0
  b     .L7F064290
   addiu $s1, $s1, 1
.L7F063FE4:
  li    $at, 3
  bne   $s1, $at, .L7F06411C
   lui   $t4, %hi(D_80035D44+0x9C) 
  addiu $t4, %lo(D_80035D44+0x9C) # addiu $t4, $t4, 0x5de0
  lw    $at, ($t4)
  addiu $t3, $sp, 0xa8
  lw    $t5, 4($t4)
  sw    $at, ($t3)
  lw    $at, 8($t4)
  sw    $t5, 4($t3)
  addiu $t8, $sp, 0xf4
  sw    $at, 8($t3)
  lw    $at, 0x64($fp)
  addiu $a0, $sp, 0xb4
  sw    $at, ($t8)
  lw    $t0, 0x68($fp)
  sw    $t0, 4($t8)
  lw    $at, 0x6c($fp)
  jal   matrix_4x4_set_identity
   sw    $at, 8($t8)
  lb    $a0, ($s4)
  jal   get_controller_buttons_held
   li    $a1, 2048
  beqz  $v0, .L7F064060
   li    $a1, 1024
  lui   $at, %hi(D_80053F08)
  lwc1  $f12, %lo(D_80053F08)($at)
  jal   sub_GAME_7F058570
   move  $a1, $s3
  b     .L7F064080
   lb    $a0, ($s4)
.L7F064060:
  jal   get_controller_buttons_held
   lb    $a0, ($s4)
  beqz  $v0, .L7F06407C
   lui   $at, %hi(D_80053F0C)
  lwc1  $f12, %lo(D_80053F0C)($at)
  jal   sub_GAME_7F058570
   move  $a1, $s3
.L7F06407C:
  lb    $a0, ($s4)
.L7F064080:
  jal   get_controller_buttons_held
   li    $a1, 512
  beqz  $v0, .L7F0640A8
   li    $a1, 256
  lui   $at, %hi(D_80053F10)
  lwc1  $f12, %lo(D_80053F10)($at)
  jal   sub_GAME_7F058688
   addiu $a1, $sp, 0xb4
  b     .L7F0640C8
   addiu $a0, $sp, 0xb4
.L7F0640A8:
  jal   get_controller_buttons_held
   lb    $a0, ($s4)
  beqz  $v0, .L7F0640C4
   lui   $at, %hi(D_80053F14)
  lwc1  $f12, %lo(D_80053F14)($at)
  jal   sub_GAME_7F058688
   addiu $a1, $sp, 0xb4
.L7F0640C4:
  addiu $a0, $sp, 0xb4
.L7F0640C8:
  jal   matrix_4x4_multiply_in_place
   move  $a1, $s3
  lui   $at, %hi(D_80053F18)
  lwc1  $f12, %lo(D_80053F18)($at)
  jal   sub_GAME_7F058570
   move  $a1, $s2
  addiu $t7, $sp, 0xf4
  sw    $t7, 0x10($sp)
  addiu $a0, $sp, 0xa8
  move  $a1, $s3
  move  $a2, $s2
  move  $a3, $s6
  sw    $s5, 0x14($sp)
  jal   sub_GAME_7F06351C
   sw    $s0, 0x18($sp)
  sll   $t6, $s1, 6
  addu  $a1, $t6, $s7
  jal   matrix_4x4_copy
   move  $a0, $s0
  b     .L7F064290
   addiu $s1, $s1, 1
.L7F06411C:
  li    $at, 1
  bne   $s1, $at, .L7F0641C8
   lui   $t2, %hi(D_80035D44+0xA8) 
  addiu $t2, %lo(D_80035D44+0xA8) # addiu $t2, $t2, 0x5dec
  lw    $at, ($t2)
  addiu $t1, $sp, 0x90
  lw    $t4, 4($t2)
  sw    $at, ($t1)
  lw    $at, 8($t2)
  sw    $t4, 4($t1)
  addiu $t5, $sp, 0x9c
  sw    $at, 8($t1)
  lw    $at, 0x4c($fp)
  li    $a1, 4096
  sw    $at, ($t5)
  lw    $t8, 0x50($fp)
  sw    $t8, 4($t5)
  lw    $at, 0x54($fp)
  sw    $at, 8($t5)
  jal   get_controller_buttons_held
   lb    $a0, ($s4)
  beqz  $v0, .L7F064184
   mov.s $f12, $f22
  lwc1  $f16, 0x94($sp)
  add.s $f18, $f16, $f20
  swc1  $f18, 0x94($sp)
.L7F064184:
  jal   sub_GAME_7F058570
   move  $a1, $s2
  addiu $t0, $sp, 0x9c
  sw    $t0, 0x10($sp)
  addiu $a0, $sp, 0x90
  move  $a1, $s3
  move  $a2, $s2
  move  $a3, $s6
  sw    $s5, 0x14($sp)
  jal   sub_GAME_7F06351C
   sw    $s0, 0x18($sp)
  sll   $t7, $s1, 6
  addu  $a1, $t7, $s7
  jal   matrix_4x4_copy
   move  $a0, $s0
  b     .L7F064290
   addiu $s1, $s1, 1
.L7F0641C8:
  li    $at, 12
  bne   $s1, $at, .L7F064280
   lw    $a0, 0x53c($sp)
  lui   $t3, %hi(D_80035D44+0xB4) 
  addiu $t3, %lo(D_80035D44+0xB4) # addiu $t3, $t3, 0x5df8
  lw    $at, ($t3)
  addiu $t6, $sp, 0x78
  lw    $t2, 4($t3)
  sw    $at, ($t6)
  lw    $at, 8($t3)
  sw    $t2, 4($t6)
  addiu $t4, $sp, 0x84
  sw    $at, 8($t6)
  lw    $at, 0xd0($fp)
  li    $a1, 8192
  sw    $at, ($t4)
  lw    $t5, 0xd4($fp)
  sw    $t5, 4($t4)
  lw    $at, 0xd8($fp)
  sw    $at, 8($t4)
  jal   get_controller_buttons_held
   lb    $a0, ($s4)
  beqz  $v0, .L7F064234
   lui   $at, %hi(D_80053F1C)
  lwc1  $f12, %lo(D_80053F1C)($at)
  jal   sub_GAME_7F058570
   move  $a1, $s3
.L7F064234:
  lui   $at, %hi(D_80053F20)
  lwc1  $f12, %lo(D_80053F20)($at)
  jal   sub_GAME_7F058688
   move  $a1, $s2
  addiu $t8, $sp, 0x84
  sw    $t8, 0x10($sp)
  addiu $a0, $sp, 0x78
  move  $a1, $s3
  move  $a2, $s2
  move  $a3, $s6
  sw    $s5, 0x14($sp)
  jal   sub_GAME_7F06351C
   sw    $s0, 0x18($sp)
  sll   $t0, $s1, 6
  addu  $a1, $t0, $s7
  jal   matrix_4x4_copy
   move  $a0, $s0
  b     .L7F064290
   addiu $s1, $s1, 1
.L7F064280:
  sll   $t7, $s1, 6
  jal   matrix_4x4_copy
   addu  $a1, $t7, $s7
  addiu $s1, $s1, 1
.L7F064290:
  slti  $at, $s1, 0xd
  bnezl $at, .L7F0638DC
   lui   $at, 0xc0a0
  jal   sub_GAME_7F06EFC4
   addiu $a0, $sp, 0x4d8
  lw    $t1, 0x538($sp)
  addiu $a0, $sp, 0x4f8
  addiu $a1, $sp, 0x4d8
  jal   subdraw
   sw    $t1, 0x504($sp)
  lw    $t6, 0x504($sp)
  jal   sub_GAME_7F058C64
   sw    $t6, 0x538($sp)
  lw    $t3, 0x3d8($sp)
  move  $s1, $zero
  move  $s0, $zero
  lh    $t2, 0xe($t3)
  blez  $t2, .L7F06431C
   nop   
  lw    $t9, 0x4e4($sp)
.L7F0642E0:
  addiu $a1, $sp, 0x41c
  jal   matrix_4x4_copy
   addu  $a0, $t9, $s0
  lw    $t5, 0x4e4($sp)
  sll   $t4, $s1, 6
  addiu $a0, $sp, 0x41c
  jal   sub_GAME_7F058C9C
   addu  $a1, $t4, $t5
  lw    $t8, 0x3d8($sp)
  addiu $s1, $s1, 1
  addiu $s0, $s0, 0x40
  lh    $t0, 0xe($t8)
  slt   $at, $s1, $t0
  bnezl $at, .L7F0642E0
   lw    $t9, 0x4e4($sp)
.L7F06431C:
  jal   sub_GAME_7F058C88
   nop   
.L7F064324:
  lw    $v0, 0x538($sp)
.L7F064328:
  lw    $ra, 0x6c($sp)
  ldc1  $f20, 0x30($sp)
  ldc1  $f22, 0x38($sp)
  ldc1  $f24, 0x40($sp)
  lw    $s0, 0x48($sp)
  lw    $s1, 0x4c($sp)
  lw    $s2, 0x50($sp)
  lw    $s3, 0x54($sp)
  lw    $s4, 0x58($sp)
  lw    $s5, 0x5c($sp)
  lw    $s6, 0x60($sp)
  lw    $s7, 0x64($sp)
  lw    $fp, 0x68($sp)
  jr    $ra
   addiu $sp, $sp, 0x538
");

asm(R"
glabel sub_GAME_7F064364
  addiu $sp, $sp, -0x20
  sw    $a3, 0x2c($sp)
  lw    $t6, 0x2c($sp)
  lw    $t7, 0x30($sp)
  move  $a3, $a2
  sw    $ra, 0x1c($sp)
  sw    $a2, 0x28($sp)
  li    $a2, 255
  sw    $t6, 0x10($sp)
  jal   sub_GAME_7F06359C
   sw    $t7, 0x14($sp)
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0643A0
  lui   $t6, %hi(dword_CODE_bss_80075DB8) 
  lw    $t6, %lo(dword_CODE_bss_80075DB8)($t6)
  lui   $t7, %hi(dword_CODE_bss_80075DBC)
  lui   $v0, %hi(dword_CODE_bss_80075DB8)
  bnez  $t6, .L7F0643C0
   nop   
  jr    $ra
   addiu $v0, $v0, %lo(dword_CODE_bss_80075DB8)

.L7F0643C0:
  lw    $t7, %lo(dword_CODE_bss_80075DBC)($t7)
  lui   $t8, %hi(dword_CODE_bss_80075DC0)
  lui   $v0, %hi(dword_CODE_bss_80075DBC)
  bnez  $t7, .L7F0643DC
   nop   
  jr    $ra
   addiu $v0, $v0, %lo(dword_CODE_bss_80075DBC)

.L7F0643DC:
  lw    $t8, %lo(dword_CODE_bss_80075DC0)($t8)
  lui   $t9, %hi(dword_CODE_bss_80075DC4)
  lui   $v0, %hi(dword_CODE_bss_80075DC0)
  bnez  $t8, .L7F0643F8
   nop   
  jr    $ra
   addiu $v0, $v0, %lo(dword_CODE_bss_80075DC0)

.L7F0643F8:
  lw    $t9, %lo(dword_CODE_bss_80075DC4)($t9)
  move  $v0, $zero
  bnez  $t9, .L7F064414
   nop   
  lui   $v0, %hi(dword_CODE_bss_80075DC4)
  jr    $ra
   addiu $v0, $v0, %lo(dword_CODE_bss_80075DC4)

.L7F064414:
  jr    $ra
   nop   
");

#ifdef VERSION_US
asm(R"
glabel recall_joy2_hits_edit_detail_edit_flag
  addiu $sp, $sp, -0x70
  move  $a3, $a0
  sw    $ra, 0x14($sp)
  addiu $a0, $a1, 8
  sw    $a1, 0x74($sp)
  sw    $a2, 0x78($sp)
  sw    $a0, 0x24($sp)
  jal   sub_GAME_7F0539E4
   sw    $a3, 0x70($sp)
  jal   get_random_value
   sw    $v0, 0x6c($sp)
  jal   get_random_value
   sw    $v0, 0x68($sp)
  lw    $t6, 0x78($sp)
  lui   $at, %hi(D_800483C4)
  sw    $v0, 0x64($sp)
  jal   get_debug_joy2hitsedit_flag
   sw    $t6, %lo(D_800483C4)($at)
  bnez  $v0, .L7F064478
   lw    $a3, 0x70($sp)
  jal   get_debug_joy2detailedit_flag
   sw    $a3, 0x70($sp)
  lw    $a3, 0x70($sp)
.L7F064478:
  li    $at, 29
  beq   $a3, $at, .L7F064710
   li    $at, 28
  beq   $a3, $at, .L7F064710
   li    $at, 27
  beq   $a3, $at, .L7F064710
   li    $at, 33
  beq   $a3, $at, .L7F064710
   li    $at, 47
  beq   $a3, $at, .L7F064710
   li    $at, 48
  beq   $a3, $at, .L7F064710
   li    $at, 34
  beq   $a3, $at, .L7F064710
   li    $at, 23
  beq   $a3, $at, .L7F064710
   li    $at, 60
  beql  $a3, $at, .L7F064714
   lw    $ra, 0x14($sp)
  jal   sub_GAME_7F0643A0
   sw    $a3, 0x70($sp)
  lw    $a3, 0x70($sp)
  beqz  $v0, .L7F064674
   move  $a2, $v0
  lw    $t7, 0x74($sp)
  li    $at, 3
  lbu   $v0, ($t7)
  beq   $v0, $at, .L7F0645A4
   li    $at, 6
  beq   $v0, $at, .L7F0645A4
   li    $at, 22
  bne   $a3, $at, .L7F064518
   addiu $v0, $sp, 0x38
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 91
  jal   play_sfx_a1
   sw    $a2, 0x60($sp)
  b     .L7F064584
   lw    $t7, 0x60($sp)
.L7F064518:
  lui   $t8, %hi(D_80035E04) 
  addiu $t8, %lo(D_80035E04) # addiu $t8, $t8, 0x5e04
  addiu $t1, $t8, 0x24
  move  $t2, $v0
.L7F064528:
  lw    $at, ($t8)
  addiu $t8, $t8, 0xc
  addiu $t2, $t2, 0xc
  sw    $at, -0xc($t2)
  lw    $at, -8($t8)
  sw    $at, -8($t2)
  lw    $at, -4($t8)
  bne   $t8, $t1, .L7F064528
   sw    $at, -4($t2)
  lw    $at, ($t8)
  lui   $a0, %hi(ptr_sfx_buf)
  sw    $at, ($t2)
  lw    $t3, 0x68($sp)
  li    $at, 20
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  divu  $zero, $t3, $at
  mfhi  $t4
  sll   $t5, $t4, 1
  addu  $t6, $v0, $t5
  lh    $a1, ($t6)
  jal   play_sfx_a1
   sw    $a2, 0x60($sp)
  lw    $t7, 0x60($sp)
.L7F064584:
  li    $a1, 8
  lw    $a0, ($t7)
  beqz  $a0, .L7F064674
   nop   
  jal   sfx_c_70009184
   lw    $a2, 0x6c($sp)
  b     .L7F064674
   nop   
.L7F0645A4:
  li    $at, 2
  bne   $a3, $at, .L7F0645C8
   lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 74
  jal   play_sfx_a1
   sw    $a2, 0x60($sp)
  b     .L7F06465C
   lw    $t3, 0x60($sp)
.L7F0645C8:
  li    $at, 1
  bne   $a3, $at, .L7F064624
   lui   $t5, %hi(D_80035E34) 
  lui   $t0, %hi(D_80035E2C) 
  addiu $t0, %lo(D_80035E2C) # addiu $t0, $t0, 0x5e2c
  lw    $at, ($t0)
  addiu $v0, $sp, 0x30
  lui   $a0, %hi(ptr_sfx_buf)
  sw    $at, ($v0)
  lhu   $at, 4($t0)
  sh    $at, 4($v0)
  lw    $t8, 0x68($sp)
  li    $at, 3
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  divu  $zero, $t8, $at
  mfhi  $t2
  sll   $t3, $t2, 1
  addu  $t4, $v0, $t3
  lh    $a1, ($t4)
  jal   play_sfx_a1
   sw    $a2, 0x60($sp)
  b     .L7F06465C
   lw    $t3, 0x60($sp)
.L7F064624:
  addiu $t5, %lo(D_80035E34) # addiu $t5, $t5, 0x5e34
  lw    $at, ($t5)
  addiu $v0, $sp, 0x2c
  lui   $a0, %hi(ptr_sfx_buf)
  sw    $at, ($v0)
  lw    $t0, 0x68($sp)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  andi  $t1, $t0, 1
  sll   $t8, $t1, 1
  addu  $t2, $v0, $t8
  lh    $a1, ($t2)
  jal   play_sfx_a1
   sw    $a2, 0x60($sp)
  lw    $t3, 0x60($sp)
.L7F06465C:
  li    $a1, 8
  lw    $a0, ($t3)
  beqz  $a0, .L7F064674
   nop   
  jal   sfx_c_70009184
   lw    $a2, 0x6c($sp)
.L7F064674:
  jal   sub_GAME_7F0643A0
   nop   
  beqz  $v0, .L7F064710
   sw    $v0, 0x60($sp)
  lw    $t4, 0x78($sp)
  lui   $t6, %hi(image_entries)
  bltz  $t4, .L7F064710
   sll   $t7, $t4, 3
  addu  $t6, $t6, $t7
  lw    $t6, %lo(image_entries)($t6)
  lui   $v0, %hi(D_8004E86C)
  srl   $t5, $t6, 0x1c
  sll   $t9, $t5, 2
  addu  $v0, $v0, $t9
  lw    $v0, %lo(D_8004E86C)($v0)
  beql  $v0, $zero, .L7F064714
   lw    $ra, 0x14($sp)
  lh    $a3, 8($v0)
  lw    $t0, 0x64($sp)
  lui   $a0, %hi(ptr_sfx_buf)
  blez  $a3, .L7F0646F8
   lw    $a2, 0x60($sp)
  divu  $zero, $t0, $a3
  lw    $t1, ($v0)
  mfhi  $v1
  sll   $t8, $v1, 1
  bnez  $a3, .L7F0646E8
   nop   
  break 7
.L7F0646E8:
  addu  $t2, $t1, $t8
  lh    $a1, ($t2)
  jal   play_sfx_a1
   lw    $a0, %lo(ptr_sfx_buf)($a0)
.L7F0646F8:
  lw    $t3, 0x60($sp)
  lw    $a0, ($t3)
  beql  $a0, $zero, .L7F064714
   lw    $ra, 0x14($sp)
  jal   sub_GAME_7F053A10
   lw    $a1, 0x24($sp)
.L7F064710:
  lw    $ra, 0x14($sp)
.L7F064714:
  addiu $sp, $sp, 0x70
  jr    $ra
   nop   
");

#ifdef VERSION_JP
asm(R"
glabel recall_joy2_hits_edit_detail_edit_flag
  addiu $sp, $sp, -0x70
  move  $a3, $a0
  sw    $ra, 0x14($sp)
  addiu $a0, $a1, 8
  sw    $a1, 0x74($sp)
  sw    $a2, 0x78($sp)
  sw    $a0, 0x24($sp)
  jal   sub_GAME_7F0539E4
   sw    $a3, 0x70($sp)
  jal   get_random_value
   sw    $v0, 0x6c($sp)
  jal   get_random_value
   sw    $v0, 0x68($sp)
  lw    $t6, 0x78($sp)
  lui   $at, %hi(D_800483C4) # $at, 0x8005
  sw    $v0, 0x64($sp)
  jal   get_debug_joy2hitsedit_flag
   sw    $t6, %lo(D_800483C4)($at)
  bnez  $v0, .L7F0649A4
   lw    $a3, 0x70($sp)
  jal   get_debug_joy2detailedit_flag
   sw    $a3, 0x70($sp)
  lw    $a3, 0x70($sp)
.L7F0649A4:
  li    $at, 29
  beq   $a3, $at, .L7F064C48
   li    $at, 28
  beq   $a3, $at, .L7F064C48
   li    $at, 27
  beq   $a3, $at, .L7F064C48
   li    $at, 33
  beq   $a3, $at, .L7F064C48
   li    $at, 47
  beq   $a3, $at, .L7F064C48
   li    $at, 48
  beq   $a3, $at, .L7F064C48
   li    $at, 34
  beq   $a3, $at, .L7F064C48
   li    $at, 23
  beq   $a3, $at, .L7F064C48
   li    $at, 60
  beq   $a3, $at, .L7F064C48
   lui   $t7, %hi(clock_timer) # $t7, 0x8005
  lw    $t7, %lo(clock_timer)($t7)
  blezl $t7, .L7F064C4C
   lw    $ra, 0x14($sp)
  jal   sub_GAME_7F0643A0
   sw    $a3, 0x70($sp)
  lw    $a3, 0x70($sp)
  beqz  $v0, .L7F064BAC
   move  $a2, $v0
  lw    $t8, 0x74($sp)
  li    $at, 3
  lbu   $v0, ($t8)
  beq   $v0, $at, .L7F064ADC
   li    $at, 6
  beq   $v0, $at, .L7F064ADC
   li    $at, 22
  bne   $a3, $at, .L7F064A50
   addiu $v0, $sp, 0x38
  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 91
  jal   play_sfx_a1
   sw    $a2, 0x60($sp)
  b     .L7F064ABC
   lw    $t8, 0x60($sp)
.L7F064A50:
  lui   $t9, %hi(D_80035E04) # $t9, 0x8003
  addiu $t9, %lo(D_80035E04) # addiu $t9, $t9, 0x5e44
  addiu $t2, $t9, 0x24
  move  $t3, $v0
.L7F064A60:
  lw    $at, ($t9)
  addiu $t9, $t9, 0xc
  addiu $t3, $t3, 0xc
  sw    $at, -0xc($t3)
  lw    $at, -8($t9)
  sw    $at, -8($t3)
  lw    $at, -4($t9)
  bne   $t9, $t2, .L7F064A60
   sw    $at, -4($t3)
  lw    $at, ($t9)
  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  sw    $at, ($t3)
  lw    $t4, 0x68($sp)
  li    $at, 20
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  divu  $zero, $t4, $at
  mfhi  $t5
  sll   $t6, $t5, 1
  addu  $t7, $v0, $t6
  lh    $a1, ($t7)
  jal   play_sfx_a1
   sw    $a2, 0x60($sp)
  lw    $t8, 0x60($sp)
.L7F064ABC:
  li    $a1, 8
  lw    $a0, ($t8)
  beqz  $a0, .L7F064BAC
   nop   
  jal   sfx_c_70009184
   lw    $a2, 0x6c($sp)
  b     .L7F064BAC
   nop   
.L7F064ADC:
  li    $at, 2
  bne   $a3, $at, .L7F064B00
   lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 74
  jal   play_sfx_a1
   sw    $a2, 0x60($sp)
  b     .L7F064B94
   lw    $t4, 0x60($sp)
.L7F064B00:
  li    $at, 1
  bne   $a3, $at, .L7F064B5C
   lui   $t6, %hi(D_80035E34) # $t6, 0x8003
  lui   $t1, %hi(D_80035E2C) # $t1, 0x8003
  addiu $t1, %lo(D_80035E2C) # addiu $t1, $t1, 0x5e6c
  lw    $at, ($t1)
  addiu $v0, $sp, 0x30
  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  sw    $at, ($v0)
  lhu   $at, 4($t1)
  sh    $at, 4($v0)
  lw    $t9, 0x68($sp)
  li    $at, 3
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  divu  $zero, $t9, $at
  mfhi  $t3
  sll   $t4, $t3, 1
  addu  $t5, $v0, $t4
  lh    $a1, ($t5)
  jal   play_sfx_a1
   sw    $a2, 0x60($sp)
  b     .L7F064B94
   lw    $t4, 0x60($sp)
.L7F064B5C:
  addiu $t6, %lo(D_80035E34) # addiu $t6, $t6, 0x5e74
  lw    $at, ($t6)
  addiu $v0, $sp, 0x2c
  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  sw    $at, ($v0)
  lw    $t1, 0x68($sp)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  andi  $t2, $t1, 1
  sll   $t9, $t2, 1
  addu  $t3, $v0, $t9
  lh    $a1, ($t3)
  jal   play_sfx_a1
   sw    $a2, 0x60($sp)
  lw    $t4, 0x60($sp)
.L7F064B94:
  li    $a1, 8
  lw    $a0, ($t4)
  beqz  $a0, .L7F064BAC
   nop   
  jal   sfx_c_70009184
   lw    $a2, 0x6c($sp)
.L7F064BAC:
  jal   sub_GAME_7F0643A0
   nop   
  beqz  $v0, .L7F064C48
   sw    $v0, 0x60($sp)
  lw    $t5, 0x78($sp)
  lui   $t7, %hi(image_entries)
  bltz  $t5, .L7F064C48
   sll   $t8, $t5, 3
  addu  $t7, $t7, $t8
  lw    $t7, %lo(image_entries)($t7)
  lui   $v0, %hi(D_8004E86C)
  srl   $t6, $t7, 0x1c
  sll   $t0, $t6, 2
  addu  $v0, $v0, $t0
  lw    $v0, %lo(D_8004E86C)($v0)
  beql  $v0, $zero, .L7F064C4C
   lw    $ra, 0x14($sp)
  lh    $a3, 8($v0)
  lw    $t1, 0x64($sp)
  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  blez  $a3, .L7F064C30
   lw    $a2, 0x60($sp)
  divu  $zero, $t1, $a3
  lw    $t2, ($v0)
  mfhi  $v1
  sll   $t9, $v1, 1
  bnez  $a3, .L7F064C20
   nop   
  break 7
.L7F064C20:
  addu  $t3, $t2, $t9
  lh    $a1, ($t3)
  jal   play_sfx_a1
   lw    $a0, %lo(ptr_sfx_buf)($a0)
.L7F064C30:
  lw    $t4, 0x60($sp)
  lw    $a0, ($t4)
  beql  $a0, $zero, .L7F064C4C
   lw    $ra, 0x14($sp)
  jal   sub_GAME_7F053A10
   lw    $a1, 0x24($sp)
.L7F064C48:
  lw    $ra, 0x14($sp)
.L7F064C4C:
  addiu $sp, $sp, 0x70
  jr    $ra
   nop     
");
#endif

#endif

#ifdef VERSION_US
asm(R"
glabel sub_GAME_7F064720
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F0643A0
   sw    $a0, 0x20($sp)
  beqz  $v0, .L7F064764
   move  $a2, $v0
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 70
  jal   play_sfx_a1
   sw    $v0, 0x1c($sp)
  lw    $a2, 0x1c($sp)
  lw    $a0, ($a2)
  beql  $a0, $zero, .L7F064768
   lw    $ra, 0x14($sp)
  jal   sub_GAME_7F053A10
   lw    $a1, 0x20($sp)
.L7F064764:
  lw    $ra, 0x14($sp)
.L7F064768:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

#ifdef VERSION_JP
asm(R"
glabel sub_GAME_7F064720
  lui   $t6, %hi(clock_timer) # $t6, 0x8005
  lw    $t6, %lo(clock_timer)($t6)
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  blez  $t6, .L7F064CAC
   sw    $a0, 0x20($sp)
  jal   sub_GAME_7F0643A0
   nop   
  beqz  $v0, .L7F064CAC
   move  $a2, $v0
  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 70
  jal   play_sfx_a1
   sw    $v0, 0x1c($sp)
  lw    $a2, 0x1c($sp)
  lw    $a0, ($a2)
  beql  $a0, $zero, .L7F064CB0
   lw    $ra, 0x14($sp)
  jal   sub_GAME_7F053A10
   lw    $a1, 0x20($sp)
.L7F064CAC:
  lw    $ra, 0x14($sp)
.L7F064CB0:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop      
");
#endif

#endif

#ifdef VERSION_US
asm(R"
glabel recall_joy2_hits_edit_flag
  addiu $sp, $sp, -0x80
  sw    $ra, 0x14($sp)
  sw    $a0, 0x80($sp)
  sw    $a1, 0x84($sp)
  jal   get_random_value
   sw    $a2, 0x88($sp)
  jal   get_random_value
   sw    $v0, 0x78($sp)
  lw    $t6, 0x88($sp)
  lui   $at, %hi(D_800483C4)
  sw    $v0, 0x74($sp)
  jal   get_debug_joy2hitsedit_flag
   sw    $t6, %lo(D_800483C4)($at)
  jal   sub_GAME_7F0643A0
   nop   
  beqz  $v0, .L7F064888
   move  $a2, $v0
  lw    $v0, 0x80($sp)
  li    $at, 23
  beq   $v0, $at, .L7F064874
   li    $at, 22
  bne   $v0, $at, .L7F064810
   lui   $t4, %hi(D_80035E3C) 
  lui   $t7, %hi(D_80035E38) 
  addiu $t7, %lo(D_80035E38) # addiu $t7, $t7, 0x5e38
  lw    $at, ($t7)
  addiu $v0, $sp, 0x70
  lui   $a0, %hi(ptr_sfx_buf)
  sw    $at, ($v0)
  lw    $t0, 0x78($sp)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  andi  $t1, $t0, 1
  sll   $t2, $t1, 1
  addu  $t3, $v0, $t2
  lh    $a1, ($t3)
  jal   play_sfx_a1
   sw    $a2, 0x7c($sp)
  b     .L7F064874
   lw    $a2, 0x7c($sp)
.L7F064810:
  addiu $v0, $sp, 0x28
  addiu $t4, %lo(D_80035E3C) # addiu $t4, $t4, 0x5e3c
  addiu $t8, $t4, 0x48
  move  $t7, $v0
.L7F064820:
  lw    $at, ($t4)
  addiu $t4, $t4, 0xc
  addiu $t7, $t7, 0xc
  sw    $at, -0xc($t7)
  lw    $at, -8($t4)
  sw    $at, -8($t7)
  lw    $at, -4($t4)
  bne   $t4, $t8, .L7F064820
   sw    $at, -4($t7)
  lw    $t9, 0x78($sp)
  li    $at, 36
  lui   $a0, %hi(ptr_sfx_buf)
  divu  $zero, $t9, $at
  mfhi  $t0
  sll   $t1, $t0, 1
  addu  $t2, $v0, $t1
  lh    $a1, ($t2)
  sw    $a2, 0x7c($sp)
  jal   play_sfx_a1
   lw    $a0, %lo(ptr_sfx_buf)($a0)
  lw    $a2, 0x7c($sp)
.L7F064874:
  lw    $a0, ($a2)
  beqz  $a0, .L7F064888
   nop   
  jal   sub_GAME_7F053A10
   lw    $a1, 0x84($sp)
.L7F064888:
  jal   sub_GAME_7F0643A0
   nop   
  beqz  $v0, .L7F064924
   move  $a2, $v0
  lw    $t3, 0x88($sp)
  lui   $t5, %hi(image_entries)
  bltz  $t3, .L7F064924
   sll   $t6, $t3, 3
  addu  $t5, $t5, $t6
  lw    $t5, %lo(image_entries)($t5)
  lui   $v0, %hi(D_8004E86C)
  srl   $t8, $t5, 0x1c
  sll   $t4, $t8, 2
  addu  $v0, $v0, $t4
  lw    $v0, %lo(D_8004E86C)($v0)
  lh    $a3, 8($v0)
  blezl $a3, .L7F064928
   lw    $ra, 0x14($sp)
  beqz  $v0, .L7F064910
   lw    $t7, 0x74($sp)
  divu  $zero, $t7, $a3
  lw    $t9, ($v0)
  mfhi  $v1
  sll   $t0, $v1, 1
  addu  $t1, $t9, $t0
  bnez  $a3, .L7F0648F8
   nop   
  break 7
.L7F0648F8:
  lh    $a1, ($t1)
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   sw    $a2, 0x7c($sp)
  lw    $a2, 0x7c($sp)
.L7F064910:
  lw    $a0, ($a2)
  beql  $a0, $zero, .L7F064928
   lw    $ra, 0x14($sp)
  jal   sub_GAME_7F053A10
   lw    $a1, 0x84($sp)
.L7F064924:
  lw    $ra, 0x14($sp)
.L7F064928:
  addiu $sp, $sp, 0x80
  jr    $ra
   nop   
");

#ifdef VERSION_JP
asm(R"
glabel recall_joy2_hits_edit_flag
  addiu $sp, $sp, -0x80
  sw    $ra, 0x14($sp)
  sw    $a0, 0x80($sp)
  sw    $a1, 0x84($sp)
  jal   get_random_value
   sw    $a2, 0x88($sp)
  jal   get_random_value
   sw    $v0, 0x78($sp)
  lw    $t6, 0x88($sp)
  lui   $at, %hi(D_800483C4) # $at, 0x8005
  sw    $v0, 0x74($sp)
  jal   get_debug_joy2hitsedit_flag
   sw    $t6, %lo(D_800483C4)($at)
  lui   $t7, %hi(clock_timer) # $t7, 0x8005
  lw    $t7, %lo(clock_timer)($t7)
  blezl $t7, .L7F064E80
   lw    $ra, 0x14($sp)
  jal   sub_GAME_7F0643A0
   nop   
  beqz  $v0, .L7F064DE0
   move  $a2, $v0
  lw    $v0, 0x80($sp)
  li    $at, 23
  beq   $v0, $at, .L7F064DCC
   li    $at, 22
  bne   $v0, $at, .L7F064D68
   lui   $t5, %hi(D_80035E3C) # $t5, 0x8003
  lui   $t8, %hi(D_80035E38) # $t8, 0x8003
  addiu $t8, %lo(D_80035E38) # addiu $t8, $t8, 0x5e78
  lw    $at, ($t8)
  addiu $v0, $sp, 0x70
  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  sw    $at, ($v0)
  lw    $t1, 0x78($sp)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  andi  $t2, $t1, 1
  sll   $t3, $t2, 1
  addu  $t4, $v0, $t3
  lh    $a1, ($t4)
  jal   play_sfx_a1
   sw    $a2, 0x7c($sp)
  b     .L7F064DCC
   lw    $a2, 0x7c($sp)
.L7F064D68:
  addiu $v0, $sp, 0x28
  addiu $t5, %lo(D_80035E3C) # addiu $t5, $t5, 0x5e7c
  addiu $t9, $t5, 0x48
  move  $t8, $v0
.L7F064D78:
  lw    $at, ($t5)
  addiu $t5, $t5, 0xc
  addiu $t8, $t8, 0xc
  sw    $at, -0xc($t8)
  lw    $at, -8($t5)
  sw    $at, -8($t8)
  lw    $at, -4($t5)
  bne   $t5, $t9, .L7F064D78
   sw    $at, -4($t8)
  lw    $t0, 0x78($sp)
  li    $at, 36
  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  divu  $zero, $t0, $at
  mfhi  $t1
  sll   $t2, $t1, 1
  addu  $t3, $v0, $t2
  lh    $a1, ($t3)
  sw    $a2, 0x7c($sp)
  jal   play_sfx_a1
   lw    $a0, %lo(ptr_sfx_buf)($a0)
  lw    $a2, 0x7c($sp)
.L7F064DCC:
  lw    $a0, ($a2)
  beqz  $a0, .L7F064DE0
   nop   
  jal   sub_GAME_7F053A10
   lw    $a1, 0x84($sp)
.L7F064DE0:
  jal   sub_GAME_7F0643A0
   nop   
  beqz  $v0, .L7F064E7C
   move  $a2, $v0
  lw    $t4, 0x88($sp)
  lui   $t6, %hi(image_entries)
  bltz  $t4, .L7F064E7C
   sll   $t7, $t4, 3
  addu  $t6, $t6, $t7
  lw    $t6, %lo(image_entries)($t6)
  lui   $v0, %hi(D_8004E86C)
  srl   $t9, $t6, 0x1c
  sll   $t5, $t9, 2
  addu  $v0, $v0, $t5
  lw    $v0, %lo(D_8004E86C)($v0)
  lh    $a3, 8($v0)
  blezl $a3, .L7F064E80
   lw    $ra, 0x14($sp)
  beqz  $v0, .L7F064E68
   lw    $t8, 0x74($sp)
  divu  $zero, $t8, $a3
  lw    $t0, ($v0)
  mfhi  $v1
  sll   $t1, $v1, 1
  addu  $t2, $t0, $t1
  bnez  $a3, .L7F064E50
   nop   
  break 7
.L7F064E50:
  lh    $a1, ($t2)
  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   sw    $a2, 0x7c($sp)
  lw    $a2, 0x7c($sp)
.L7F064E68:
  lw    $a0, ($a2)
  beql  $a0, $zero, .L7F064E80
   lw    $ra, 0x14($sp)
  jal   sub_GAME_7F053A10
   lw    $a1, 0x84($sp)
.L7F064E7C:
  lw    $ra, 0x14($sp)
.L7F064E80:
  addiu $sp, $sp, 0x80
  jr    $ra
   nop      
");
#endif

#endif

#ifdef VERSION_US
asm(R"
glabel sub_GAME_7F064934
  addiu $sp, $sp, -0x28
  li    $at, 22
  beq   $a0, $at, .L7F06499C
   sw    $ra, 0x14($sp)
  li    $at, 23
  beq   $a0, $at, .L7F06499C
   lui   $t7, %hi(D_80035E84) 
  addiu $t7, %lo(D_80035E84) # addiu $t7, $t7, 0x5e84
  lw    $at, ($t7)
  addiu $t6, $sp, 0x1c
  lw    $t9, 4($t7)
  sw    $at, ($t6)
  lhu   $at, 8($t7)
  sw    $t9, 4($t6)
  jal   get_random_value
   sh    $at, 8($t6)
  li    $at, 5
  divu  $zero, $v0, $at
  mfhi  $t0
  sll   $t1, $t0, 1
  addu  $a1, $sp, $t1
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  lh    $a1, 0x1c($a1)
  jal   play_sfx_a1
   move  $a2, $zero
.L7F06499C:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

#ifdef VERSION_JP
asm(R"
glabel sub_GAME_7F064934
  lui   $t6, %hi(clock_timer) # $t6, 0x8005
  lw    $t6, %lo(clock_timer)($t6)
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  blez  $t6, .L7F064F00
   li    $at, 22
  beq   $a0, $at, .L7F064F00
   li    $at, 23
  beq   $a0, $at, .L7F064F00
   lui   $t8, %hi(D_80035E84) # $t8, 0x8003
  addiu $t8, %lo(D_80035E84) # addiu $t8, $t8, 0x5ec4
  lw    $at, ($t8)
  addiu $t7, $sp, 0x1c
  lw    $t0, 4($t8)
  sw    $at, ($t7)
  lhu   $at, 8($t8)
  sw    $t0, 4($t7)
  jal   get_random_value
   sh    $at, 8($t7)
  li    $at, 5
  divu  $zero, $v0, $at
  mfhi  $t1
  sll   $t2, $t1, 1
  addu  $a1, $sp, $t2
  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  lh    $a1, 0x1c($a1)
  jal   play_sfx_a1
   move  $a2, $zero
.L7F064F00:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop       
");
#endif

#endif

asm(R"
glabel sub_GAME_7F0649AC
  li    $at, 0xC2700000 # -60.000000
  mtc1  $at, $f0
  li    $at, 25
  bne   $a0, $at, .L7F0649D0
   mov.s $f2, $f0
  li    $at, 0x41A00000 # 20.000000
  mtc1  $at, $f4
  nop   
  sub.s $f2, $f0, $f4
.L7F0649D0:
  jr    $ra
   mov.s $f0, $f2
");

asm(R"
glabel sub_GAME_7F0649D8
  sll   $t7, $a0, 3
  subu  $t7, $t7, $a0
  sll   $t7, $t7, 2
  addu  $t7, $t7, $a0
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  sll   $t7, $t7, 2
  addiu $sp, $sp, -0x38
  addu  $t7, $t7, $a0
  sw    $s1, 0x18($sp)
  sll   $t7, $t7, 3
  sw    $ra, 0x1c($sp)
  addu  $s1, $t6, $t7
  sw    $s0, 0x14($sp)
  addiu $s1, $s1, 0x870
  jal   get_item_in_hand
   sw    $a0, 0x38($sp)
  lw    $t8, 0x2c($s1)
  move  $s0, $v0
  lw    $a0, 0x38($sp)
  jal   get_ammo_in_hands_weapon
   sw    $t8, 0x2c($sp)
  sw    $v0, 0x28($sp)
  jal   get_ptr_item_statistics
   move  $a0, $s0
  lw    $t9, 0x28($sp)
  lw    $t0, 0x2c($sp)
  lh    $a0, 0x20($v0)
  move  $a2, $v0
  addu  $v1, $t9, $t0
  slt   $at, $v1, $a0
  bnez  $at, .L7F064A64
   lui   $a1, 0x20
  b     .L7F064A68
   sw    $a0, 0x2c($s1)
.L7F064A64:
  sw    $v1, 0x2c($s1)
.L7F064A68:
  move  $a0, $s0
  jal   check_special_attributes
   sw    $a2, 0x24($sp)
  beqz  $v0, .L7F064A98
   lw    $a2, 0x24($sp)
  lw    $t2, 0x1c($a2)
  lui   $t1, %hi(pPlayer) 
  lw    $t1, %lo(pPlayer)($t1)
  sll   $t3, $t2, 2
  addu  $t4, $t1, $t3
  b     .L7F064AC4
   sw    $zero, 0x1130($t4)
.L7F064A98:
  lw    $t6, 0x1c($a2)
  lui   $t5, %hi(pPlayer) 
  lw    $t5, %lo(pPlayer)($t5)
  sll   $t7, $t6, 2
  lw    $t9, 0x2c($s1)
  addu  $v0, $t5, $t7
  lw    $t8, 0x1130($v0)
  lw    $t2, 0x2c($sp)
  subu  $t0, $t8, $t9
  addu  $t1, $t0, $t2
  sw    $t1, 0x1130($v0)
.L7F064AC4:
  li    $at, 25
  bnel  $s0, $at, .L7F064AE4
   li    $at, 15
  jal   sub_GAME_7F05FA7C
   lw    $a0, 0x38($sp)
  b     .L7F064B18
   lw    $ra, 0x1c($sp)
  li    $at, 15
.L7F064AE4:
  beq   $s0, $at, .L7F064AF4
   li    $at, 16
  bnel  $s0, $at, .L7F064B18
   lw    $ra, 0x1c($sp)
.L7F064AF4:
  jal   get_ammo_in_hands_weapon
   lw    $a0, 0x38($sp)
  slti  $at, $v0, 5
  bnez  $at, .L7F064B10
   li    $t3, 5
  b     .L7F064B14
   sw    $t3, 0x34($s1)
.L7F064B10:
  sw    $v0, 0x34($s1)
.L7F064B14:
  lw    $ra, 0x1c($sp)
.L7F064B18:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x38
");

#ifdef VERSION_US
asm(R"
.late_rodata
/*D:80053F24*/
glabel jpt_80053F24
.word Weapon_function_slapper
.word Weapon_function_hunting_knife
.word Weapon_function_throwing_knife
.word Weapon_function_guns
.word Weapon_function_guns
.word Weapon_function_guns
.word Weapon_function_guns
.word Weapon_function_guns
.word Weapon_function_guns
.word Weapon_function_guns
.word Weapon_function_guns
.word Weapon_function_guns
.word Weapon_function_guns
.word Weapon_function_guns
.word Weapon_function_guns
.word Weapon_function_guns
.word Weapon_function_guns
.word Weapon_function_magnum
.word Weapon_function_guns
.word Weapon_function_guns
.word Weapon_function_guns
.word Weapon_function_guns
.word Weapon_function_guns
.word Weapon_function_magnum
.word Weapon_function_guns
.word Weapon_function_grenades
.word Weapon_function_throwable_item
.word Weapon_function_throwable_item
.word Weapon_function_throwable_item
.word Weapon_function_guns
.word Weapon_function_tazer
.word Weapon_function_guns
.word Weapon_function_throwable_item
.word Weapon_function_throwable_item
.word Weapon_function_guns
.word Weapon_function_guns
.word Weapon_function_key
.word Weapon_function_key
.word Weapon_function_key
.word Weapon_function_camera
.word Weapon_function_key
.word Weapon_function_key
.word Weapon_function_collectible
.word Weapon_function_key
.word Weapon_function_key
.word Weapon_function_key
.word Weapon_function_throwable_item
.word Weapon_function_throwable_item
.word Weapon_function_key
.word Weapon_function_key
.word Weapon_function_key
.word Weapon_function_key
.word Weapon_function_key
.word Weapon_function_key
.word Weapon_function_key
.word Weapon_function_key
.word Weapon_function_key
.word Weapon_function_key
.word Weapon_function_key
.word Weapon_function_guns
.word Weapon_function_throwable_item
.word Weapon_function_collectible
.word Weapon_function_collectible
.word Weapon_function_collectible
.word Weapon_function_collectible
.word Weapon_function_collectible
.word Weapon_function_collectible
.word Weapon_function_collectible
.word Weapon_function_collectible
.word Weapon_function_collectible
.word Weapon_function_collectible
.word Weapon_function_collectible
.word Weapon_function_key
.word Weapon_function_collectible
.word Weapon_function_collectible
.word Weapon_function_collectible
.word Weapon_function_collectible
.word Weapon_function_collectible
.word Weapon_function_collectible
.word Weapon_function_collectible
.word Weapon_function_key
.word Weapon_function_key
.word Weapon_function_key
.word Weapon_function_collectible
.word Weapon_function_collectible
.word Weapon_function_collectible
.word Weapon_function_collectible
.word Weapon_function_collectible

/*D:80054084*/
glabel jpt_80054084
.word Weapon_shooting_noammo
.word Weapon_shooting_throwable
.word Weapon_shooting_pistol
.word Weapon_shooting_pistol
.word Weapon_shooting_pistol
.word Weapon_shooting_machinegun
.word Weapon_shooting_machinegun
.word Weapon_shooting_machinegun
.word Weapon_shooting_machinegun
.word Weapon_shooting_machinegun
.word Weapon_shooting_machinegun
.word Weapon_shooting_machinegun
.word Weapon_shooting_machinegun
.word Weapon_shooting_pistol
.word Weapon_shooting_pistol
.word Weapon_shooting_pistol
.word Weapon_shooting_pistol
.word Weapon_shooting_pistol
.word Weapon_shooting_pistol
.word Weapon_shooting_pistol
.word Weapon_shooting_pistol
.word Weapon_shooting_pistol
.word Weapon_shooting_pistol
.word Weapon_shooting_pistol
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_pistol
.word Weapon_shooting_tazer
.word Weapon_shooting_pistol
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_pistol
.word Weapon_shooting_pistol
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_watch_magnet
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_watch_magnet

glabel D_80054170
.word 0x40c90fdb /*6.2831855*/
glabel D_80054174
.word 0x3fc90fdb /*1.5707964*/
glabel D_80054178
.word 0x40c90fdb /*6.2831855*/
glabel D_8005417C
.word 0x40490fdb /*3.1415927*/
glabel D_80054180
.word 0x3fc90fdb /*1.5707964*/
glabel D_80054184
.word 0x3f32b8c3 /*0.69813174*/
glabel D_80054188
.word 0x3f32b8c3 /*0.69813174*/
glabel D_8005418C
.word 0x3f32b8c3 /*0.69813174*/
glabel D_80054190
.word 0x3f32b8c3 /*0.69813174*/

/*D:80054194*/
glabel jpt_80054194
.word weapon_switchstyle_NONE
.word weapon_switchstyle_NONE
.word weapon_playsfx_knife
.word weapon_playsfx_knife
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_F2
.word weapon_switchstyle_NONE
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_switchstyle_NONE
.word weapon_playsfx_mine
.word weapon_playsfx_mine
.word weapon_playsfx_mine
.word weapon_switchstyle_NONE
.word weapon_switchstyle_NONE
.word weapon_switchstyle_NONE
.word weapon_switchstyle_NONE
.word weapon_switchstyle_NONE
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_switchstyle_NONE
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_switchstyle_NONE
.word weapon_switchstyle_NONE
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_switchstyle_NONE
.word weapon_switchstyle_NONE

glabel D_8005428C
.word 0x3f32b8c3 /*0.69813174*/
glabel D_80054290
.word 0x3f32b8c3 /*0.69813174*/

/*D:80054294*/
glabel jpt_80054294
.word weapon_reload_none_sfx
.word weapon_reload_none_sfx
.word weapon_reload_none_sfx
.word weapon_reload_none_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_none_sfx
.word weapon_reload_none_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_none_sfx
.word weapon_reload_none_sfx
.word weapon_reload_none_sfx
.word weapon_reload_none_sfx
.word weapon_reload_none_sfx
.word weapon_reload_none_sfx
.word weapon_reload_none_sfx
.word weapon_reload_none_sfx
.word weapon_reload_none_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_none_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_none_sfx
.word weapon_reload_none_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_none_sfx
.word weapon_reload_none_sfx

glabel D_8005438C
.word 0x3f32b8c3 /*0.69813174*/
glabel D_80054390
.word 0x3f32b8c3 /*0.69813174*/
glabel D_80054394
.word 0x3f32b8c3 /*0.69813174*/
glabel D_80054398
.word 0x3f32b8c3 /*0.69813174*/
glabel D_8005439C
.word 0x3f32b8c3 /*0.69813174*/
glabel D_800543A0
.word 0x3f32b8c3 /*0.69813174*/
glabel D_800543A4
.word 0x3f32b8c3 /*0.69813174*/
glabel D_800543A8
.word 0x3f32b8c3 /*0.69813174*/
glabel D_800543AC
.word 0x3f32b8c3 /*0.69813174*/

.text
glabel handle_weapon_id_values_possibly_1st_person_animation
  sll   $v0, $a0, 3
  subu  $v0, $v0, $a0
  sll   $v0, $v0, 2
  addiu $sp, $sp, -0x1d0
  addu  $v0, $v0, $a0
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  sll   $v0, $v0, 2
  addu  $v0, $v0, $a0
  sw    $s0, 0x1c($sp)
  sll   $v0, $v0, 3
  sw    $ra, 0x24($sp)
  addu  $s0, $t6, $v0
  sw    $s1, 0x20($sp)
  sw    $a1, 0x1d4($sp)
  addiu $s0, $s0, 0x870
  sw    $v0, 0x38($sp)
  jal   return_ammo_in_hand
   sw    $a0, 0x1d0($sp)
  move  $s1, $v0
  jal   get_ammo_type_for_weapon
   move  $a0, $v0
  lw    $v1, 0x1d4($sp)
  lw    $t7, 0x10($s0)
  move  $a2, $v0
  sw    $v1, 0x10($s0)
  bnez  $v1, .L7F064BA0
   sw    $t7, 0x14($s0)
  li    $t8, 1
  sw    $t8, 0x18($s0)
.L7F064BA0:
  sb    $zero, 0xc($s0)
  sb    $zero, 0xd($s0)
  lui   $v0, %hi(clock_timer)
  lw    $v0, %lo(clock_timer)($v0)
  blezl $v0, .L7F064BD4
   lw    $t6, 0x24($s0)
  lw    $t9, 0x20($s0)
  lw    $t4, 0x1c($s0)
  addu  $t3, $t9, $v0
  addiu $t5, $t4, 1
  sw    $t3, 0x20($s0)
  sw    $t5, 0x1c($s0)
  lw    $t6, 0x24($s0)
.L7F064BD4:
  sw    $zero, 0xbc($s0)
  bnezl $t6, .L7F064DA4
   lw    $v0, 0x24($s0)
  lw    $t7, 0x10($s0)
  beql  $t7, $zero, .L7F064C2C
   lw    $v0, 0x28($s0)
  beqz  $s1, .L7F064C28
   move  $a0, $s1
  li    $a1, 16
  jal   check_special_attributes
   sw    $a2, 0x1c4($sp)
  bnez  $v0, .L7F064C10
   lw    $a2, 0x1c4($sp)
  lw    $t8, 0x2c($s0)
  blez  $t8, .L7F064C28
.L7F064C10:
   li    $t9, 1
  sw    $t9, 0x24($s0)
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
  b     .L7F064C40
   sw    $zero, 0x18($s0)
.L7F064C28:
  lw    $v0, 0x28($s0)
.L7F064C2C:
  beql  $v0, $zero, .L7F064C44
   lw    $t3, 0x24($s0)
  sw    $v0, 0x24($s0)
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
.L7F064C40:
  lw    $t3, 0x24($s0)
.L7F064C44:
  sw    $zero, 0x28($s0)
  bnezl $t3, .L7F064DA4
   lw    $v0, 0x24($s0)
  lw    $t4, 0x2c($s0)
  bnezl $t4, .L7F064DA4
   lw    $v0, 0x24($s0)
  beql  $a2, $zero, .L7F064DA4
   lw    $v0, 0x24($s0)
  jal   get_controls_locked_flag
   sw    $a2, 0x1c4($sp)
  bnez  $v0, .L7F064DA0
   lw    $a2, 0x1c4($sp)
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lui   $t6, %hi(D_80032458) 
  lw    $t5, 0x29c4($v0)
  bnezl $t5, .L7F064DA4
   lw    $v0, 0x24($s0)
  lw    $t6, %lo(D_80032458)($t6)
  li    $at, 1
  beqz  $t6, .L7F064CBC
   nop   
  bne   $a2, $at, .L7F064CBC
   sll   $t7, $a2, 2
  addu  $v1, $v0, $t7
  lw    $t8, 0x1130($v1)
  li    $t9, 1
  bgtz  $t8, .L7F064CBC
   nop   
  sw    $t9, 0x1130($v1)
.L7F064CBC:
  jal   get_ammo_in_hands_weapon
   lw    $a0, 0x1d0($sp)
  blez  $v0, .L7F064CE0
   lui   $t4, %hi(pPlayer) 
  li    $t3, 9
  sw    $t3, 0x24($s0)
  sw    $zero, 0x20($s0)
  b     .L7F064DA0
   sw    $zero, 0x1c($s0)
.L7F064CE0:
  lw    $t4, %lo(pPlayer)($t4)
  lw    $t6, 0x1d0($sp)
  li    $t7, 1
  lw    $t5, 0xfc8($t4)
  subu  $a0, $t7, $t6
  beql  $t5, $zero, .L7F064DA4
   lw    $v0, 0x24($s0)
  jal   return_ammo_in_hand
   sw    $a0, 0x3c($sp)
  lui   $t8, %hi(pPlayer) 
  lw    $t8, %lo(pPlayer)($t8)
  lw    $t9, 0x38($sp)
  move  $a0, $v0
  subu  $v1, $t8, $t9
  lw    $t3, 0xc3c($v1)
  addiu $v1, $v1, 0xc18
  bnezl $t3, .L7F064DA4
   lw    $v0, 0x24($s0)
  lw    $t4, 0x28($v1)
  bnezl $t4, .L7F064DA4
   lw    $v0, 0x24($s0)
  beqz  $v0, .L7F064D6C
   nop   
  lw    $t5, 0x2c($v1)
  bnezl $t5, .L7F064DA4
   lw    $v0, 0x24($s0)
  jal   get_ammo_type_for_weapon
   sw    $v1, 0x1bc($sp)
  beqz  $v0, .L7F064DA0
   lw    $v1, 0x1bc($sp)
  lw    $a0, 0x3c($sp)
  jal   get_ammo_in_hands_weapon
   sw    $v1, 0x1bc($sp)
  bgtz  $v0, .L7F064DA0
   lw    $v1, 0x1bc($sp)
.L7F064D6C:
  jal   autoadvance_on_deplete_all_ammo
   sw    $v1, 0x1bc($sp)
  lw    $v1, 0x1bc($sp)
  lw    $t7, 0x28($s0)
  sw    $zero, 0x1c($s0)
  sw    $zero, 0x20($s0)
  sw    $zero, 0x28($s0)
  sw    $t7, 0x24($s0)
  lw    $t6, 0x28($v1)
  sw    $zero, 0x1c($v1)
  sw    $zero, 0x20($v1)
  sw    $zero, 0x28($v1)
  sw    $t6, 0x24($v1)
.L7F064DA0:
  lw    $v0, 0x24($s0)
.L7F064DA4:
  li    $at, 1
  bne   $v0, $at, .L7F064FA4
   addiu $t8, $s1, -1
  sltiu $at, $t8, 0x58
  beqz  $at, .L7F064F90
   sll   $t8, $t8, 2
  lui   $at, %hi(jpt_80053F24)
  addu  $at, $at, $t8
  lw    $t8, %lo(jpt_80053F24)($at)
  jr    $t8
   nop   
Weapon_function_magnum:
  lw    $t9, 0x20($s0)
  li    $t3, 2
  slti  $at, $t9, 6
  bnezl $at, .L7F064FA0
   sw    $zero, 0x398($s0)
  sw    $t3, 0x24($s0)
  sw    $zero, 0x20($s0)
  b     .L7F064F9C
   sw    $zero, 0x1c($s0)
Weapon_function_camera:
  lw    $t4, 0x1c($s0)
  move  $a0, $zero
  move  $a1, $zero
  bnez  $t4, .L7F064E18
   move  $a2, $zero
  jal   set_rgba_tint
   lui   $a3, 0x3f80
  b     .L7F064FA0
   sw    $zero, 0x398($s0)
.L7F064E18:
  lw    $t5, 0x20($s0)
  li    $at, 0x41000000 # 8.000000
  move  $a1, $zero
  blez  $t5, .L7F064F9C
   move  $a2, $zero
  mtc1  $zero, $f4
  mtc1  $at, $f12
  move  $a3, $zero
  jal   sub_GAME_7F0807E0
   swc1  $f4, 0x10($sp)
  li    $t7, 2
  sw    $t7, 0x24($s0)
  sw    $zero, 0x20($s0)
  b     .L7F064F9C
   sw    $zero, 0x1c($s0)
Weapon_function_guns:
  li    $t6, 2
  sw    $t6, 0x24($s0)
  sw    $zero, 0x20($s0)
  b     .L7F064F9C
   sw    $zero, 0x1c($s0)
Weapon_function_throwable_item:
  li    $t8, 28
  sw    $t8, 0x24($s0)
  sw    $zero, 0x20($s0)
  b     .L7F064F9C
   sw    $zero, 0x1c($s0)
Weapon_function_hunting_knife:
  jal   get_random_value
   nop   
  andi  $t9, $v0, 1
  bnez  $t9, .L7F064E9C
   li    $t4, 20
  li    $t3, 17
  b     .L7F064EA0
   sw    $t3, 0x24($s0)
.L7F064E9C:
  sw    $t4, 0x24($s0)
.L7F064EA0:
  sw    $zero, 0x20($s0)
  b     .L7F064F9C
   sw    $zero, 0x1c($s0)
Weapon_function_grenades:
  lw    $t5, 0x18($s0)
  lui   $t8, %hi(pPlayer) 
  bnezl $t5, .L7F064ED0
   lw    $t6, 0x20($s0)
  lw    $t7, 0x20($s0)
  slti  $at, $t7, 0xf0
  bnezl $at, .L7F064FA0
   sw    $zero, 0x398($s0)
  lw    $t6, 0x20($s0)
.L7F064ED0:
  lw    $t8, %lo(pPlayer)($t8)
  li    $t9, 26
  sw    $t6, 0x105c($t8)
  sw    $t9, 0x24($s0)
  sw    $zero, 0x1c($s0)
  b     .L7F064F9C
   sw    $zero, 0x20($s0)
Weapon_function_slapper:
  jal   get_random_value
   nop   
  andi  $t3, $v0, 1
  bnez  $t3, .L7F064F0C
   li    $t5, 32
  li    $t4, 30
  b     .L7F064F10
   sw    $t4, 0x24($s0)
.L7F064F0C:
  sw    $t5, 0x24($s0)
.L7F064F10:
  sw    $zero, 0x20($s0)
  b     .L7F064F9C
   sw    $zero, 0x1c($s0)
Weapon_function_throwing_knife:
  li    $t7, 23
  sw    $t7, 0x24($s0)
  sw    $zero, 0x20($s0)
  b     .L7F064F9C
   sw    $zero, 0x1c($s0)
Weapon_function_tazer:
  lw    $t6, 0x20($s0)
  lui   $a0, %hi(D_80035A90)
  addiu $a0, %lo(D_80035A90) # addiu $a0, $a0, 0x5a90
  mtc1  $t6, $f6
  addiu $a2, $s0, 0x7c
  lw    $a3, 0x1d0($sp)
  cvt.s.w $f0, $f6
  mfc1  $a1, $f0
  jal   sub_GAME_7F05C6FC
   nop   
  beqz  $v0, .L7F064F6C
   li    $t9, 2
  li    $t8, 1
  b     .L7F064F9C
   sw    $t8, 0xbc($s0)
.L7F064F6C:
  sw    $t9, 0x24($s0)
  sw    $zero, 0x20($s0)
  b     .L7F064F9C
   sw    $zero, 0x1c($s0)
Weapon_function_key:
  li    $t3, 36
  sw    $t3, 0x24($s0)
  sw    $zero, 0x20($s0)
  b     .L7F064F9C
   sw    $zero, 0x1c($s0)
Weapon_function_collectible:
.L7F064F90:
  sw    $zero, 0x24($s0)
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
.L7F064F9C:
  sw    $zero, 0x398($s0)
.L7F064FA0:
  lw    $v0, 0x24($s0)
.L7F064FA4:
  li    $at, 2
  bnel  $v0, $at, .L7F06554C
   lw    $t3, 0x24($s0)
  jal   get_ammo_type_for_weapon
   move  $a0, $s1
  beqz  $v0, .L7F064FC8
   addiu $t5, $s1, -2
  lw    $t4, 0x2c($s0)
  blez  $t4, .L7F0654E8
.L7F064FC8:
   sltiu $at, $t5, 0x3b
  beqz  $at, .L7F06528C
   sll   $t5, $t5, 2
  lui   $at, %hi(jpt_80054084)
  addu  $at, $at, $t5
  lw    $t5, %lo(jpt_80054084)($at)
  jr    $t5
   nop   
Weapon_shooting_watch_magnet:
  lw    $t7, 0x1c($s0)
  li    $t9, 3
  bnezl $t7, .L7F065028
   sw    $t9, 0x24($s0)
  jal   get_controls_locked_flag
   nop   
  sltiu $a1, $v0, 1
  beqz  $a1, .L7F06501C
   lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  lw    $a1, 0x29c4($t6)
  sltiu $t8, $a1, 1
  move  $a1, $t8
.L7F06501C:
  b     .L7F06528C
   sb    $a1, 0xc($s0)
  sw    $t9, 0x24($s0)
.L7F065028:
  sw    $zero, 0x20($s0)
  b     .L7F06528C
   sw    $zero, 0x1c($s0)
Weapon_shooting_pistol:
  lw    $t3, 0x1c($s0)
  li    $t9, 3
  bnezl $t3, .L7F0650B8
   sw    $t9, 0x24($s0)
  jal   getPlayerCount
   nop   
  li    $at, 1
  beql  $v0, $at, .L7F065078
   li    $t7, 1
  jal   checkGamePaused
   nop   
  bnez  $v0, .L7F06507C
   lui   $t4, %hi(pPlayer) 
  lw    $t4, %lo(pPlayer)($t4)
  lw    $t5, 0x29c4($t4)
  bnez  $t5, .L7F06507C
   li    $t7, 1
.L7F065078:
  sb    $t7, 0xd($s0)
.L7F06507C:
  jal   get_controls_locked_flag
   nop   
  sltiu $a1, $v0, 1
  beqz  $a1, .L7F0650A0
   lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  lw    $a1, 0x29c4($t6)
  sltiu $t8, $a1, 1
  move  $a1, $t8
.L7F0650A0:
  sb    $a1, 0xc($s0)
  jal   sub_GAME_7F05E808
   lw    $a0, 0x1d0($sp)
  b     .L7F065290
   lb    $t7, 0xc($s0)
  sw    $t9, 0x24($s0)
.L7F0650B8:
  sw    $zero, 0x20($s0)
  b     .L7F06528C
   sw    $zero, 0x1c($s0)
Weapon_shooting_machinegun:
  lw    $t3, 0x1c($s0)
  beqz  $t3, .L7F065118
   nop   
  lw    $t4, 0x10($s0)
  move  $a0, $s1
  bnez  $t4, .L7F065118
   nop   
  jal   check_special_attributes
   li    $a1, 4
  beql  $v0, $zero, .L7F0651C0
   li    $t6, 3
  jal   get_BONDdata_is_aiming
   nop   
  bnezl $v0, .L7F0651C0
   li    $t6, 3
  lw    $t5, 0x398($s0)
  li    $at, 3
  div   $zero, $t5, $at
  mfhi  $t7
  beql  $t7, $zero, .L7F0651C0
   li    $t6, 3
.L7F065118:
  jal   get_automatic_firing_rate
   move  $a0, $s1
  lw    $t6, 0x1c($s0)
  div   $zero, $t6, $v0
  mfhi  $t8
  bnez  $v0, .L7F065138
   nop   
  break 7
.L7F065138:
  li    $at, -1
  bne   $v0, $at, .L7F065150
   lui   $at, 0x8000
  bne   $t6, $at, .L7F065150
   nop   
  break 6
.L7F065150:
  bnezl $t8, .L7F065290
   lb    $t7, 0xc($s0)
  jal   getPlayerCount
   nop   
  li    $at, 1
  beql  $v0, $at, .L7F06518C
   li    $t4, 1
  jal   checkGamePaused
   nop   
  bnez  $v0, .L7F065190
   lui   $t9, %hi(pPlayer) 
  lw    $t9, %lo(pPlayer)($t9)
  lw    $t3, 0x29c4($t9)
  bnez  $t3, .L7F065190
   li    $t4, 1
.L7F06518C:
  sb    $t4, 0xd($s0)
.L7F065190:
  jal   get_controls_locked_flag
   nop   
  sltiu $a1, $v0, 1
  beqz  $a1, .L7F0651B4
   lui   $t5, %hi(pPlayer) 
  lw    $t5, %lo(pPlayer)($t5)
  lw    $a1, 0x29c4($t5)
  sltiu $t7, $a1, 1
  move  $a1, $t7
.L7F0651B4:
  b     .L7F06528C
   sb    $a1, 0xc($s0)
  li    $t6, 3
.L7F0651C0:
  sw    $t6, 0x24($s0)
  sw    $zero, 0x20($s0)
  b     .L7F06528C
   sw    $zero, 0x1c($s0)
Weapon_shooting_noammo:
  lw    $t8, 0x1c($s0)
  beql  $t8, $zero, .L7F0651F0
   sb    $zero, 0xc($s0)
  lw    $t9, 0x10($s0)
  li    $t4, 3
  beql  $t9, $zero, .L7F065200
   sw    $t4, 0x24($s0)
  sb    $zero, 0xc($s0)
.L7F0651F0:
  lb    $t3, 0xc($s0)
  b     .L7F06528C
   sb    $t3, 0xd($s0)
  sw    $t4, 0x24($s0)
.L7F065200:
  sw    $zero, 0x20($s0)
  b     .L7F06528C
   sw    $zero, 0x1c($s0)
Weapon_shooting_tazer:
  lw    $t5, 0x1c($s0)
  lui   $a0, %hi(D_80035B68)
  addiu $a0, %lo(D_80035B68) # addiu $a0, $a0, 0x5b68
  beqz  $t5, .L7F06522C
   li    $a1, 0
  lw    $t7, 0x10($s0)
  li    $t5, 3
  beqz  $t7, .L7F065280
.L7F06522C:
   addiu $a2, $s0, 0x7c
  jal   sub_GAME_7F05C6FC
   lw    $a3, 0x1d0($sp)
  lw    $t9, 0x1c($s0)
  sb    $zero, 0xc($s0)
  lb    $t8, 0xc($s0)
  li    $t6, 1
  sw    $t6, 0xbc($s0)
  bnez  $t9, .L7F06528C
   sb    $t8, 0xd($s0)
  jal   get_controls_locked_flag
   nop   
  sltiu $a1, $v0, 1
  beqz  $a1, .L7F065278
   lui   $t3, %hi(pPlayer) 
  lw    $t3, %lo(pPlayer)($t3)
  lw    $a1, 0x29c4($t3)
  sltiu $t4, $a1, 1
  move  $a1, $t4
.L7F065278:
  b     .L7F06528C
   sb    $a1, 0xc($s0)
.L7F065280:
  sw    $t5, 0x24($s0)
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
Weapon_shooting_throwable:
.L7F06528C:
  lb    $t7, 0xc($s0)
.L7F065290:
  li    $at, 40
  beql  $t7, $zero, .L7F065310
   lw    $t5, 0x24($s0)
  beql  $s1, $at, .L7F0652F8
   lw    $t8, 0x2c($s0)
  jal   get_cur_playernum
   nop   
  lui   $a1, (0x3DCCCCCD >> 16) # lui $a1, 0x3dcc
  ori   $a1, (0x3DCCCCCD & 0xFFFF) # ori $a1, $a1, 0xcccd
  jal   controller_7000C854
   move  $a0, $v0
  jal   cur_player_get_control_type
   nop   
  slti  $at, $v0, 4
  bnezl $at, .L7F0652F8
   lw    $t8, 0x2c($s0)
  jal   get_cur_playernum
   nop   
  jal   getPlayerCount
   sw    $v0, 0x48($sp)
  lw    $t6, 0x48($sp)
  lui   $a1, (0x3DCCCCCD >> 16) # lui $a1, 0x3dcc
  ori   $a1, (0x3DCCCCCD & 0xFFFF) # ori $a1, $a1, 0xcccd
  jal   controller_7000C854
   addu  $a0, $v0, $t6
  lw    $t8, 0x2c($s0)
.L7F0652F8:
  lw    $t3, 0x398($s0)
  addiu $t9, $t8, -1
  addiu $t4, $t3, 1
  sw    $t9, 0x2c($s0)
  sw    $t4, 0x398($s0)
  lw    $t5, 0x24($s0)
.L7F065310:
  li    $at, 2
  move  $a0, $s1
  bnel  $t5, $at, .L7F06554C
   lw    $t3, 0x24($s0)
  jal   get_sound_trigger_rate
   sw    $zero, 0x1b4($sp)
  blez  $v0, .L7F065388
   lui   $t7, %hi(pPlayer) 
  lw    $t6, 0x38($sp)
  lw    $t7, %lo(pPlayer)($t7)
  lui   $v0, %hi(global_timer)
  negu  $t8, $t6
  addu  $t9, $t7, $t8
  lw    $t3, 0xdf8($t9)
  lw    $v0, %lo(global_timer)($v0)
  beq   $v0, $t3, .L7F06539C
   nop   
  lw    $t4, 0x1dc($s0)
  slt   $at, $t4, $v0
  beqz  $at, .L7F06539C
   nop   
  jal   get_sound_trigger_rate
   move  $a0, $s1
  lui   $t5, %hi(global_timer) 
  lw    $t5, %lo(global_timer)($t5)
  li    $t7, 1
  addu  $t6, $v0, $t5
  sw    $t6, 0x1dc($s0)
  b     .L7F06539C
   sw    $t7, 0x1b4($sp)
.L7F065388:
  lb    $t8, 0xc($s0)
  li    $t9, 1
  beqz  $t8, .L7F06539C
   nop   
  sw    $t9, 0x1b4($sp)
.L7F06539C:
  jal   getPlayerCount
   nop   
  li    $at, 1
  beql  $v0, $at, .L7F0653D4
   lw    $t5, 0x1b4($sp)
  jal   checkGamePaused
   nop   
  bnez  $v0, .L7F065548
   lui   $t3, %hi(pPlayer) 
  lw    $t3, %lo(pPlayer)($t3)
  lw    $t4, 0x29c4($t3)
  bnezl $t4, .L7F06554C
   lw    $t3, 0x24($s0)
  lw    $t5, 0x1b4($sp)
.L7F0653D4:
  beql  $t5, $zero, .L7F0654AC
   li    $at, 23
  lw    $a0, 0x1d4($s0)
  beql  $a0, $zero, .L7F065404
   lw    $a0, 0x1d8($s0)
  jal   sfxGetArg0Unk3F
   nop   
  beql  $v0, $zero, .L7F065404
   lw    $a0, 0x1d8($s0)
  jal   sfxDeactivate
   lw    $a0, 0x1d4($s0)
  lw    $a0, 0x1d8($s0)
.L7F065404:
  beqz  $a0, .L7F065424
   nop   
  jal   sfxGetArg0Unk3F
   nop   
  beqz  $v0, .L7F065424
   nop   
  jal   sfxDeactivate
   lw    $a0, 0x1d8($s0)
.L7F065424:
  jal   sub_GAME_7F05E014
   move  $a0, $s1
  beql  $v0, $zero, .L7F0654AC
   li    $at, 23
  lw    $t6, 0x1d4($s0)
  bnezl $t6, .L7F065470
   lw    $t8, 0x1d8($s0)
  jal   sub_GAME_7F05E014
   move  $a0, $s1
  sll   $a1, $v0, 0x10
  sra   $t7, $a1, 0x10
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  move  $a1, $t7
  jal   play_sfx_a1
   addiu $a2, $s0, 0x1d4
  b     .L7F06549C
   nop   
  lw    $t8, 0x1d8($s0)
.L7F065470:
  bnez  $t8, .L7F06549C
   nop   
  jal   sub_GAME_7F05E014
   move  $a0, $s1
  sll   $a1, $v0, 0x10
  sra   $t9, $a1, 0x10
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  move  $a1, $t9
  jal   play_sfx_a1
   addiu $a2, $s0, 0x1d8
.L7F06549C:
  lui   $t3, %hi(global_timer) 
  lw    $t3, %lo(global_timer)($t3)
  sw    $t3, 0x1e0($s0)
  li    $at, 23
.L7F0654AC:
  bne   $s1, $at, .L7F065548
   lui   $t4, %hi(D_80035E90) 
  lw    $t4, %lo(D_80035E90)($t4)
  jal   get_random_value
   sw    $t4, 0x1b0($sp)
  andi  $t5, $v0, 1
  sll   $t6, $t5, 1
  addu  $a1, $sp, $t6
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  lh    $a1, 0x1b0($a1)
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F06554C
   lw    $t3, 0x24($s0)
.L7F0654E8:
  lw    $t7, 0x1c($s0)
  li    $t8, 3
  li    $t9, 13
  blezl $t7, .L7F065510
   sw    $t9, 0x24($s0)
  sw    $t8, 0x24($s0)
  sw    $zero, 0x20($s0)
  b     .L7F065548
   sw    $zero, 0x1c($s0)
  sw    $t9, 0x24($s0)
.L7F065510:
  sw    $zero, 0x20($s0)
  jal   getPlayerCount
   sw    $zero, 0x1c($s0)
  li    $at, 1
  beq   $v0, $at, .L7F065534
   nop   
  jal   checkGamePaused
   nop   
  bnez  $v0, .L7F065548
.L7F065534:
   lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 89
  jal   play_sfx_a1
   move  $a2, $zero
.L7F065548:
  lw    $t3, 0x24($s0)
.L7F06554C:
  li    $at, 3
  bne   $t3, $at, .L7F0658A8
   li    $at, 31
  bne   $s1, $at, .L7F0655A8
   nop   
  lw    $t4, 0x20($s0)
  lui   $a0, %hi(D_80035B68)
  addiu $a0, %lo(D_80035B68) # addiu $a0, $a0, 0x5b68
  mtc1  $t4, $f8
  addiu $a2, $s0, 0x7c
  lw    $a3, 0x1d0($sp)
  cvt.s.w $f0, $f8
  mfc1  $a1, $f0
  jal   sub_GAME_7F05C6FC
   nop   
  beqz  $v0, .L7F065598
   li    $t5, 1
  b     .L7F0658A8
   sw    $t5, 0xbc($s0)
.L7F065598:
  sw    $zero, 0x24($s0)
  sw    $zero, 0x20($s0)
  b     .L7F0658A8
   sw    $zero, 0x1c($s0)
.L7F0655A8:
  jal   get_ptr_item_statistics
   move  $a0, $s1
  lw    $a1, 0x18($s0)
  move  $t2, $v0
  lb    $a3, 0x44($v0)
  beqz  $a1, .L7F0655D8
   lb    $t1, 0x45($v0)
  lw    $t6, 0x20($s0)
  addu  $t7, $a3, $t1
  slt   $at, $t6, $t7
  beql  $at, $zero, .L7F065604
   sw    $zero, 0x24($s0)
.L7F0655D8:
  lb    $a0, 0x23($v0)
  lw    $v1, 0x20($s0)
  addu  $t0, $a3, $t1
  bltz  $a0, .L7F065610
   nop   
  bnez  $a1, .L7F065610
   addu  $t8, $t0, $a0
  slt   $at, $v1, $t8
  bnez  $at, .L7F065610
   nop   
  sw    $zero, 0x24($s0)
.L7F065604:
  sw    $zero, 0x20($s0)
  b     .L7F0658A8
   sw    $zero, 0x1c($s0)
.L7F065610:
  beql  $a1, $zero, .L7F065670
   slt   $at, $v1, $t0
  lw    $t9, 0x10($s0)
  beql  $t9, $zero, .L7F065670
   slt   $at, $v1, $t0
  lb    $a2, 0x46($v0)
  slt   $at, $v1, $a2
  bnezl $at, .L7F065670
   slt   $at, $v1, $t0
  lb    $a0, 0x47($v0)
  bltz  $a0, .L7F06566C
   addu  $a1, $v1, $a0
  slt   $at, $a1, $t0
  beqz  $at, .L7F06566C
   slt   $at, $a1, $a2
  bnez  $at, .L7F06566C
   li    $t3, 4
  sw    $t3, 0x24($s0)
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
  lb    $t4, 0x47($v0)
  b     .L7F0658A8
   sw    $t4, 0x38($s0)
.L7F06566C:
  slt   $at, $v1, $t0
.L7F065670:
  beqz  $at, .L7F0658A8
   addiu $t5, $s0, 0x7c
  lwc1  $f2, 0x48($v0)
  lwc1  $f0, 0x4c($v0)
  bnez  $v1, .L7F0656AC
   sw    $t5, 0x30($sp)
  lwc1  $f10, 0x78($s0)
  lwc1  $f4, 0x6c($s0)
  lwc1  $f6, 0x70($s0)
  lwc1  $f8, 0x74($s0)
  lw    $v1, 0x20($s0)
  swc1  $f10, 0x58($s0)
  swc1  $f4, 0x4c($s0)
  swc1  $f6, 0x50($s0)
  swc1  $f8, 0x54($s0)
.L7F0656AC:
  slt   $at, $v1, $a3
  beqz  $at, .L7F065760
   lui   $at, %hi(D_80054170)
  lwc1  $f12, %lo(D_80054170)($at)
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f4
  mul.s $f10, $f0, $f12
  div.s $f6, $f10, $f4
  sub.s $f8, $f12, $f6
  swc1  $f8, 0x68($s0)
  swc1  $f2, 0x198($sp)
  sw    $t2, 0x1a8($sp)
  sw    $a3, 0x1a4($sp)
  jal   sub_GAME_7F05DCE8
   lw    $a0, 0x1d0($sp)
  lwc1  $f10, 0x1c8($s0)
  lwc1  $f2, 0x198($sp)
  li    $at, 0x447A0000 # 1000.000000
  sub.s $f4, $f0, $f10
  mtc1  $at, $f14
  lw    $t2, 0x1a8($sp)
  mtc1  $zero, $f10
  mul.s $f6, $f4, $f2
  lw    $a3, 0x1a4($sp)
  swc1  $f10, 0x60($s0)
  lw    $t6, 0x20($s0)
  lui   $at, %hi(D_80054174)
  div.s $f8, $f6, $f14
  lwc1  $f6, 0x1d0($s0)
  swc1  $f8, 0x5c($s0)
  lwc1  $f4, 0xc($t2)
  sub.s $f8, $f4, $f6
  mtc1  $t6, $f6
  mul.s $f10, $f8, $f2
  cvt.s.w $f8, $f6
  mtc1  $a3, $f6
  div.s $f4, $f10, $f14
  swc1  $f4, 0x64($s0)
  lwc1  $f10, %lo(D_80054174)($at)
  mul.s $f4, $f8, $f10
  cvt.s.w $f8, $f6
  jal   sinf
   div.s $f12, $f4, $f8
  b     .L7F065824
   mov.s $f2, $f0
.L7F065760:
  lui   $at, %hi(D_80054178)
  lwc1  $f12, %lo(D_80054178)($at)
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f6
  mul.s $f10, $f0, $f12
  div.s $f4, $f10, $f6
  sub.s $f8, $f12, $f4
  swc1  $f8, 0x68($s0)
  swc1  $f2, 0x198($sp)
  sw    $t2, 0x1a8($sp)
  sw    $t1, 0x1a0($sp)
  sw    $a3, 0x1a4($sp)
  jal   sub_GAME_7F05DCE8
   lw    $a0, 0x1d0($sp)
  lwc1  $f10, 0x1c8($s0)
  lwc1  $f2, 0x198($sp)
  li    $at, 0x447A0000 # 1000.000000
  sub.s $f6, $f0, $f10
  mtc1  $at, $f14
  lw    $t2, 0x1a8($sp)
  mtc1  $zero, $f10
  mul.s $f4, $f6, $f2
  lw    $a3, 0x1a4($sp)
  lw    $t1, 0x1a0($sp)
  swc1  $f10, 0x60($s0)
  lw    $t7, 0x20($s0)
  lui    $at, %hi(D_8005417C)
  div.s $f8, $f4, $f14
  lwc1  $f4, 0x1d0($s0)
  subu  $t8, $t7, $a3
  swc1  $f8, 0x5c($s0)
  lwc1  $f6, 0xc($t2)
  sub.s $f8, $f6, $f4
  mtc1  $t8, $f4
  mul.s $f10, $f8, $f2
  cvt.s.w $f8, $f4
  mtc1  $t1, $f4
  div.s $f6, $f10, $f14
  swc1  $f6, 0x64($s0)
  lwc1  $f10, %lo(D_8005417C)($at)
  mul.s $f6, $f8, $f10
  cvt.s.w $f8, $f4
  jal   cosf
   div.s $f12, $f6, $f8
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f10
  mtc1  $at, $f6
  mul.s $f4, $f0, $f10
  add.s $f2, $f4, $f6
.L7F065824:
  lwc1  $f12, 0x58($s0)
  lwc1  $f14, 0x68($s0)
  mfc1  $a2, $f2
  jal   sub_GAME_7F06D0CC
   swc1  $f2, 0x190($sp)
  lwc1  $f14, 0x4c($s0)
  lwc1  $f8, 0x5c($s0)
  lwc1  $f2, 0x190($sp)
  lwc1  $f16, 0x50($s0)
  sub.s $f10, $f8, $f14
  lwc1  $f8, 0x60($s0)
  lwc1  $f18, 0x54($s0)
  li    $t9, 1
  mul.s $f4, $f10, $f2
  sub.s $f10, $f8, $f16
  lwc1  $f8, 0x64($s0)
  swc1  $f0, 0x78($s0)
  sw    $t9, 0xbc($s0)
  mov.s $f12, $f0
  add.s $f6, $f4, $f14
  mul.s $f4, $f10, $f2
  sub.s $f10, $f8, $f18
  swc1  $f6, 0x6c($s0)
  add.s $f6, $f4, $f16
  mul.s $f4, $f10, $f2
  swc1  $f6, 0x70($s0)
  add.s $f6, $f4, $f18
  swc1  $f6, 0x74($s0)
  jal   sub_GAME_7F058570
   lw    $a1, 0x30($sp)
  addiu $a0, $s0, 0x6c
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   lw    $a1, 0x30($sp)
.L7F0658A8:
  lw    $v0, 0x24($s0)
  li    $at, 4
  bnel  $v0, $at, .L7F065A00
   li    $at, 13
  lw    $v1, 0x20($s0)
  bnezl $v1, .L7F06590C
   lw    $v0, 0x38($s0)
  lwc1  $f8, 0x78($s0)
  lwc1  $f10, 0x6c($s0)
  lwc1  $f4, 0x70($s0)
  lwc1  $f6, 0x74($s0)
  swc1  $f8, 0x58($s0)
  swc1  $f10, 0x4c($s0)
  swc1  $f4, 0x50($s0)
  swc1  $f6, 0x54($s0)
  mtc1  $zero, $f8
  mtc1  $zero, $f10
  mtc1  $zero, $f4
  mtc1  $zero, $f6
  lw    $v1, 0x20($s0)
  swc1  $f8, 0x68($s0)
  swc1  $f10, 0x5c($s0)
  swc1  $f4, 0x60($s0)
  swc1  $f6, 0x64($s0)
  lw    $v0, 0x38($s0)
.L7F06590C:
  slt   $at, $v1, $v0
  beqz  $at, .L7F0659EC
   subu  $t3, $v0, $v1
  mtc1  $t3, $f8
  lui   $at, %hi(D_80054180)
  lwc1  $f4, %lo(D_80054180)($at)
  cvt.s.w $f10, $f8
  mtc1  $v0, $f8
  addiu $t4, $s0, 0x7c
  addiu $t5, $s0, 0x6c
  sw    $t5, 0x34($sp)
  sw    $t4, 0x30($sp)
  mul.s $f6, $f10, $f4
  cvt.s.w $f10, $f8
  jal   cosf
   div.s $f12, $f6, $f10
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f16
  nop   
  mul.s $f4, $f0, $f16
  add.s $f2, $f4, $f16
  swc1  $f2, 0x18c($sp)
  mfc1  $a2, $f2
  lwc1  $f14, 0x68($s0)
  jal   sub_GAME_7F06D0CC
   lwc1  $f12, 0x58($s0)
  lwc1  $f14, 0x4c($s0)
  lwc1  $f8, 0x5c($s0)
  lwc1  $f2, 0x18c($sp)
  lwc1  $f16, 0x50($s0)
  sub.s $f6, $f8, $f14
  lwc1  $f8, 0x60($s0)
  lwc1  $f18, 0x54($s0)
  li    $t6, 1
  mul.s $f10, $f6, $f2
  sub.s $f6, $f8, $f16
  lwc1  $f8, 0x64($s0)
  swc1  $f0, 0x78($s0)
  sw    $t6, 0xbc($s0)
  mov.s $f12, $f0
  add.s $f4, $f10, $f14
  mul.s $f10, $f6, $f2
  sub.s $f6, $f8, $f18
  swc1  $f4, 0x6c($s0)
  add.s $f4, $f10, $f16
  mul.s $f10, $f6, $f2
  swc1  $f4, 0x70($s0)
  add.s $f4, $f10, $f18
  swc1  $f4, 0x74($s0)
  jal   sub_GAME_7F058570
   lw    $a1, 0x30($sp)
  lw    $a0, 0x34($sp)
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   lw    $a1, 0x30($sp)
  b     .L7F0659FC
   lw    $v0, 0x24($s0)
.L7F0659EC:
  sw    $zero, 0x24($s0)
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
  move  $v0, $zero
.L7F0659FC:
  li    $at, 13
.L7F065A00:
  bnel  $v0, $at, .L7F065A50
   lw    $v0, 0x24($s0)
  lw    $t7, 0x1c($s0)
  bnezl $t7, .L7F065A20
   lw    $a1, 0x18($s0)
  jal   sub_GAME_7F05E808
   lw    $a0, 0x1d0($sp)
  lw    $a1, 0x18($s0)
.L7F065A20:
  bnezl $a1, .L7F065A44
   sw    $zero, 0x24($s0)
  bnezl $a1, .L7F065A50
   lw    $v0, 0x24($s0)
  lw    $t8, 0x20($s0)
  slti  $at, $t8, 0x14
  bnezl $at, .L7F065A50
   lw    $v0, 0x24($s0)
  sw    $zero, 0x24($s0)
.L7F065A44:
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
  lw    $v0, 0x24($s0)
.L7F065A50:
  li    $a1, 5
  li    $a0, 16
  bnel  $a1, $v0, .L7F065BD4
   li    $a2, 6
  jal   getPlayerCount
   sw    $a0, 0x188($sp)
  slti  $at, $v0, 2
  bnez  $at, .L7F065A78
   lw    $a0, 0x188($sp)
  li    $a0, 12
.L7F065A78:
  lw    $t9, 0x1c($s0)
  bnezl $t9, .L7F065AB0
   lw    $v1, 0x20($s0)
  jal   getPlayerCount
   sw    $a0, 0x188($sp)
  li    $at, 1
  bne   $v0, $at, .L7F065AA4
   lw    $a0, 0x188($sp)
  li    $t3, 17
  b     .L7F065AAC
   sw    $t3, 0x40($s0)
.L7F065AA4:
  li    $t4, 13
  sw    $t4, 0x40($s0)
.L7F065AAC:
  lw    $v1, 0x20($s0)
.L7F065AB0:
  slt   $at, $v1, $a0
  bnezl $at, .L7F065B50
   mtc1  $v1, $f8
  jal   get_ammo_type_for_weapon
   move  $a0, $s1
  lui   $t5, %hi(pPlayer) 
  lw    $t5, %lo(pPlayer)($t5)
  sll   $t6, $v0, 2
  lw    $t8, 0x2c($s0)
  addu  $v1, $t5, $t6
  lw    $t7, 0x1130($v1)
  addu  $t9, $t7, $t8
  sw    $t9, 0x1130($v1)
  jal   getPlayerCount
   sw    $zero, 0x2c($s0)
  slti  $at, $v0, 2
  bnez  $at, .L7F065B00
   nop   
  jal   sub_GAME_7F09B368
   lw    $a0, 0x1d0($sp)
.L7F065B00:
  jal   sub_GAME_7F05FB00
   lw    $a0, 0x1d0($sp)
  li    $t3, 6
  sw    $t3, 0x24($s0)
  jal   check_if_item_available
   li    $a0, 17
  beqz  $v0, .L7F065B34
   li    $a1, 5
  lui   $t5, %hi(pPlayer) 
  lw    $t5, %lo(pPlayer)($t5)
  li    $t4, 17
  b     .L7F065B44
   sw    $t4, 0x2a38($t5)
.L7F065B34:
  lui   $t7, %hi(pPlayer) 
  lw    $t7, %lo(pPlayer)($t7)
  li    $t6, 1
  sw    $t6, 0x2a38($t7)
.L7F065B44:
  b     .L7F065BD0
   lw    $v0, 0x24($s0)
  mtc1  $v1, $f8
.L7F065B50:
  lui   $at, %hi(D_80054184)
  lwc1  $f10, %lo(D_80054184)($at)
  cvt.s.w $f6, $f8
  mtc1  $a0, $f8
  li    $t8, 1
  sw    $t8, 0xbc($s0)
  addiu $a1, $s0, 0x7c
  mul.s $f4, $f6, $f10
  cvt.s.w $f6, $f8
  div.s $f12, $f4, $f6
  jal   sub_GAME_7F058570
   swc1  $f12, 0x184($sp)
  mtc1  $zero, $f10
  nop   
  swc1  $f10, 0xac($s0)
  jal   cosf
   lwc1  $f12, 0x184($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  li    $at, 0xC2700000 # -60.000000
  mtc1  $at, $f6
  sub.s $f4, $f8, $f0
  mul.s $f10, $f4, $f6
  swc1  $f10, 0xb0($s0)
  jal   sinf
   lwc1  $f12, 0x184($sp)
  li    $at, 0x41700000 # 15.000000
  mtc1  $at, $f8
  lw    $v0, 0x24($s0)
  li    $a1, 5
  mul.s $f4, $f0, $f8
  swc1  $f4, 0xb4($s0)
.L7F065BD0:
  li    $a2, 6
.L7F065BD4:
  beq   $a2, $v0, .L7F065BE4
   li    $at, 7
  bnel  $v0, $at, .L7F065D78
   li    $at, 8
.L7F065BE4:
  lw    $t9, 0x44($s0)
  beqz  $t9, .L7F065C04
   nop   
  lw    $t3, 0x20($s0)
  lw    $t4, 0x40($s0)
  slt   $at, $t3, $t4
  bnezl $at, .L7F065CF8
   lw    $v0, 0x24($s0)
.L7F065C04:
  bne   $a2, $v0, .L7F065CD8
   lui   $t5, %hi(pPlayer) 
  lw    $t5, %lo(pPlayer)($t5)
  lw    $t6, 0x38($sp)
  subu  $v1, $t5, $t6
  lw    $v0, 0xc3c($v1)
  addiu $v1, $v1, 0xc18
  beql  $a2, $v0, .L7F065CB8
   lw    $a0, 0x1d0($sp)
  beql  $a1, $v0, .L7F065CB8
   lw    $a0, 0x1d0($sp)
  lw    $a0, 0x28($v1)
  li    $at, 14
  beql  $a1, $a0, .L7F065CB8
   lw    $a0, 0x1d0($sp)
  beq   $v0, $at, .L7F065CB4
   li    $at, 15
  beq   $v0, $at, .L7F065CB4
   li    $at, 16
  beq   $v0, $at, .L7F065CB4
   li    $at, 14
  beq   $a0, $at, .L7F065CB4
   lw    $t7, 0x1d0($sp)
  bnez  $t7, .L7F065C94
   nop   
  jal   get_item_in_hand
   li    $a0, 1
  lw    $a0, 0x3c($s0)
  jal   check_if_item_for_hand_available
   move  $a1, $v0
  bnez  $v0, .L7F065CB4
   li    $a0, 1
  jal   draw_item_in_hand_has_more_ammo
   move  $a1, $zero
  b     .L7F065CB8
   lw    $a0, 0x1d0($sp)
.L7F065C94:
  jal   get_item_in_hand
   move  $a0, $zero
  move  $a0, $v0
  jal   check_if_item_for_hand_available
   lw    $a1, 0x3c($s0)
  bnezl $v0, .L7F065CB8
   lw    $a0, 0x1d0($sp)
  sw    $zero, 0x3c($s0)
.L7F065CB4:
  lw    $a0, 0x1d0($sp)
.L7F065CB8:
  jal   remove_hands_item
   lw    $a1, 0x3c($s0)
  jal   return_ammo_in_hand
   lw    $a0, 0x1d0($sp)
  li    $t8, 7
  move  $s1, $v0
  b     .L7F065CF4
   sw    $t8, 0x24($s0)
.L7F065CD8:
  jal   sub_GAME_7F05CEBC
   lw    $a0, 0x1d0($sp)
  beqz  $v0, .L7F065CF4
   li    $t9, 8
  sw    $t9, 0x24($s0)
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
.L7F065CF4:
  lw    $v0, 0x24($s0)
.L7F065CF8:
  li    $a2, 6
  li    $at, 7
  beq   $a2, $v0, .L7F065D10
   li    $t3, 1
  bnel  $v0, $at, .L7F065D78
   li    $at, 8
.L7F065D10:
  sw    $t3, 0xbc($s0)
  lui   $at, %hi(D_80054188)
  lwc1  $f12, %lo(D_80054188)($at)
  jal   sub_GAME_7F058570
   addiu $a1, $s0, 0x7c
  mtc1  $zero, $f6
  lui   $at, %hi(D_8005418C)
  swc1  $f6, 0xac($s0)
  jal   cosf
   lwc1  $f12, %lo(D_8005418C)($at)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  li    $at, 0xC2700000 # -60.000000
  mtc1  $at, $f4
  sub.s $f8, $f10, $f0
  lui   $at, %hi(D_80054190)
  mul.s $f6, $f8, $f4
  swc1  $f6, 0xb0($s0)
  jal   sinf
   lwc1  $f12, %lo(D_80054190)($at)
  li    $at, 0x41700000 # 15.000000
  mtc1  $at, $f10
  lw    $v0, 0x24($s0)
  mul.s $f8, $f0, $f10
  swc1  $f8, 0xb4($s0)
  li    $at, 8
.L7F065D78:
  bne   $v0, $at, .L7F065F9C
   li    $t4, 23
  jal   getPlayerCount
   sw    $t4, 0x178($sp)
  slti  $at, $v0, 2
  bnez  $at, .L7F065D98
   li    $t5, 12
  sw    $t5, 0x178($sp)
.L7F065D98:
  lw    $t6, 0x1c($s0)
  bnezl $t6, .L7F065EC0
   lw    $t6, 0x20($s0)
  jal   getPlayerCount
   nop   
  slti  $at, $v0, 2
  bnez  $at, .L7F065DC0
   nop   
  jal   sub_GAME_7F09B398
   lw    $a0, 0x1d0($sp)
.L7F065DC0:
  jal   sub_GAME_7F0649D8
   lw    $a0, 0x1d0($sp)
  lui   $t7, %hi(pPlayer) 
  lw    $t7, %lo(pPlayer)($t7)
  lui   $t8, %hi(clock_timer) 
  lui   $t9, %hi(pPlayer) 
  sw    $zero, 0xfc8($t7)
  lw    $t8, %lo(clock_timer)($t8)
  blezl $t8, .L7F065EC0
   lw    $t6, 0x20($s0)
  lw    $t9, %lo(pPlayer)($t9)
  li    $at, 1
  lw    $t3, ($t9)
  beql  $t3, $at, .L7F065EC0
   lw    $t6, 0x20($s0)
  jal   sub_GAME_7F05CEBC
   lw    $a0, 0x1d0($sp)
  beqz  $v0, .L7F065EBC
   lui   $t4, %hi(disable_player_pickups_flag) 
  lw    $t4, %lo(disable_player_pickups_flag)($t4)
  slti  $at, $s1, 0x3e
  bnezl $t4, .L7F065EC0
   lw    $t6, 0x20($s0)
  bnez  $at, .L7F065E34
   li    $at, 88
  beql  $s1, $at, .L7F065EC0
   lw    $t6, 0x20($s0)
  b     .L7F065EA8
   nop   
.L7F065E34:
  sltiu $at, $s1, 0x3e
  beqz  $at, .L7F065EA8
   sll   $t5, $s1, 2
  lui   $at, %hi(jpt_80054194)
  addu  $at, $at, $t5
  lw    $t5, %lo(jpt_80054194)($at)
  jr    $t5
   nop   
weapon_playsfx_F2:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 242
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F065EC0
   lw    $t6, 0x20($s0)
weapon_playsfx_knife:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 233
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F065EC0
   lw    $t6, 0x20($s0)
weapon_playsfx_mine:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 235
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F065EC0
   lw    $t6, 0x20($s0)
weapon_playsfx_gun:
.L7F065EA8:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 232
  jal   play_sfx_a1
   move  $a2, $zero
weapon_switchstyle_NONE:
.L7F065EBC:
  lw    $t6, 0x20($s0)
.L7F065EC0:
  lw    $t7, 0x178($sp)
  slt   $at, $t6, $t7
  beql  $at, $zero, .L7F065F04
   sw    $zero, 0x24($s0)
  jal   get_ptr_weapon_model_header_line
   move  $a0, $s1
  beqz  $v0, .L7F065F00
   move  $a0, $s1
  jal   check_special_attributes
   li    $a1, 2048
  beqz  $v0, .L7F065F00
   move  $a0, $s1
  jal   check_special_attributes
   li    $a1, 8192
  beqz  $v0, .L7F065F14
   lw    $t8, 0x178($sp)
.L7F065F00:
  sw    $zero, 0x24($s0)
.L7F065F04:
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
  b     .L7F065F9C
   move  $v0, $zero
.L7F065F14:
  lw    $t9, 0x20($s0)
  lui   $at, %hi(D_8005428C)
  lwc1  $f10, %lo(D_8005428C)($at)
  subu  $t3, $t8, $t9
  mtc1  $t3, $f4
  li    $t4, 1
  sw    $t4, 0xbc($s0)
  cvt.s.w $f6, $f4
  mtc1  $t8, $f4
  addiu $a1, $s0, 0x7c
  mul.s $f8, $f6, $f10
  cvt.s.w $f6, $f4
  div.s $f12, $f8, $f6
  jal   sub_GAME_7F058570
   swc1  $f12, 0x174($sp)
  mtc1  $zero, $f10
  nop   
  swc1  $f10, 0xac($s0)
  jal   cosf
   lwc1  $f12, 0x174($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  li    $at, 0xC2700000 # -60.000000
  mtc1  $at, $f6
  sub.s $f8, $f4, $f0
  mul.s $f10, $f8, $f6
  swc1  $f10, 0xb0($s0)
  jal   sinf
   lwc1  $f12, 0x174($sp)
  li    $at, 0x41700000 # 15.000000
  mtc1  $at, $f4
  lw    $v0, 0x24($s0)
  mul.s $f8, $f0, $f4
  swc1  $f8, 0xb4($s0)
.L7F065F9C:
  li    $at, 9
  bnel  $v0, $at, .L7F066004
   li    $at, 10
  jal   get_ptr_item_statistics
   move  $a0, $s1
  lw    $t5, 0x2c($s0)
  lh    $t6, 0x20($v0)
  move  $a0, $s1
  slt   $at, $t5, $t6
  bnez  $at, .L7F065FD8
   nop   
  jal   check_special_attributes
   lui   $a1, 0x20
  beql  $v0, $zero, .L7F065FF4
   sw    $zero, 0x24($s0)
.L7F065FD8:
  jal   get_ammo_in_hands_weapon
   lw    $a0, 0x1d0($sp)
  blez  $v0, .L7F065FF0
   li    $v0, 10
  b     .L7F066000
   sw    $v0, 0x24($s0)
.L7F065FF0:
  sw    $zero, 0x24($s0)
.L7F065FF4:
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
  move  $v0, $zero
.L7F066000:
  li    $at, 10
.L7F066004:
  bnel  $v0, $at, .L7F066128
   li    $at, 11
  lw    $v1, 0x20($s0)
  li    $v0, 11
  li    $t8, 17
  slti  $at, $v1, 0x10
  beql  $at, $zero, .L7F066034
   sw    $v0, 0x24($s0)
  lb    $t9, 0xf($s0)
  bnezl $t9, .L7F066048
   mtc1  $v1, $f6
  sw    $v0, 0x24($s0)
.L7F066034:
  sw    $t8, 0x40($s0)
  sw    $zero, 0x20($s0)
  b     .L7F066124
   sw    $zero, 0x1c($s0)
  mtc1  $v1, $f6
.L7F066048:
  li    $at, 0x41800000 # 16.000000
  mtc1  $at, $f2
  cvt.s.w $f10, $f6
  lui   $at, %hi(D_80054290)
  lwc1  $f4, %lo(D_80054290)($at)
  li    $t4, 1
  addiu $a1, $s0, 0x7c
  mul.s $f8, $f10, $f4
  div.s $f6, $f8, $f2
  swc1  $f6, 0x128($sp)
  sw    $t4, 0xbc($s0)
  lw    $t5, 0x1d0($sp)
  bnezl $t5, .L7F0660A0
   mtc1  $zero, $f4
  mtc1  $zero, $f10
  sw    $a1, 0x30($sp)
  div.s $f12, $f10, $f2
  jal   sub_GAME_7F058688
   swc1  $f12, 0x3c($sp)
  b     .L7F0660B8
   lwc1  $f12, 0x128($sp)
  mtc1  $zero, $f4
.L7F0660A0:
  sw    $a1, 0x30($sp)
  div.s $f0, $f4, $f2
  neg.s $f12, $f0
  jal   sub_GAME_7F058688
   swc1  $f0, 0x3c($sp)
  lwc1  $f12, 0x128($sp)
.L7F0660B8:
  jal   sub_GAME_7F058570
   addiu $a1, $sp, 0x12c
  addiu $a0, $sp, 0x12c
  jal   matrix_4x4_multiply_in_place
   lw    $a1, 0x30($sp)
  jal   sinf
   lwc1  $f12, 0x3c($sp)
  mtc1  $zero, $f8
  move  $a0, $s1
  jal   sub_GAME_7F0649AC
   swc1  $f8, 0xac($s0)
  swc1  $f0, 0x40($sp)
  jal   cosf
   lwc1  $f12, 0x128($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  lwc1  $f4, 0x40($sp)
  sub.s $f10, $f6, $f0
  mul.s $f8, $f10, $f4
  swc1  $f8, 0xb0($s0)
  jal   sinf
   lwc1  $f12, 0x128($sp)
  li    $at, 0x41700000 # 15.000000
  mtc1  $at, $f6
  lw    $v0, 0x24($s0)
  mul.s $f10, $f0, $f6
  swc1  $f10, 0xb4($s0)
.L7F066124:
  li    $at, 11
.L7F066128:
  bnel  $v0, $at, .L7F0662B8
   li    $at, 12
  lw    $t6, 0x1c($s0)
  lui   $t7, %hi(pPlayer) 
  bnezl $t6, .L7F0661C4
   lw    $t4, 0x20($s0)
  lw    $t7, %lo(pPlayer)($t7)
  li    $at, 1
  lw    $t9, ($t7)
  beql  $t9, $at, .L7F0661C4
   lw    $t4, 0x20($s0)
  jal   sub_GAME_7F05CEBC
   lw    $a0, 0x1d0($sp)
  beqz  $v0, .L7F0661C0
   lui   $t3, %hi(disable_player_pickups_flag) 
  lw    $t3, %lo(disable_player_pickups_flag)($t3)
  slti  $at, $s1, 0x3e
  bnezl $t3, .L7F0661C4
   lw    $t4, 0x20($s0)
  bnez  $at, .L7F06618C
   li    $at, 88
  beql  $s1, $at, .L7F0661C4
   lw    $t4, 0x20($s0)
  b     .L7F0661AC
   nop   
.L7F06618C:
  sltiu $at, $s1, 0x3e
  beqz  $at, .L7F0661AC
   sll   $t8, $s1, 2
  lui   $at, %hi(jpt_80054294)
  addu  $at, $at, $t8
  lw    $t8, %lo(jpt_80054294)($at)
  jr    $t8
   nop   
weapon_reload_gun_sfx:
.L7F0661AC:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 50
  jal   play_sfx_a1
   move  $a2, $zero
weapon_reload_none_sfx:
.L7F0661C0:
  lw    $t4, 0x20($s0)
.L7F0661C4:
  lw    $t5, 0x40($s0)
  li    $t9, 1
  slt   $at, $t4, $t5
  bnezl $at, .L7F066200
   sw    $t9, 0xbc($s0)
  lw    $t6, 0x1c($s0)
  li    $v0, 12
  slti  $at, $t6, 2
  bnezl $at, .L7F066200
   sw    $t9, 0xbc($s0)
  sw    $v0, 0x24($s0)
  sw    $zero, 0x20($s0)
  b     .L7F0662B4
   sw    $zero, 0x1c($s0)
  sw    $t9, 0xbc($s0)
.L7F066200:
  lw    $t3, 0x1d0($sp)
  addiu $a1, $s0, 0x7c
  bnezl $t3, .L7F066228
   mtc1  $zero, $f12
  mtc1  $zero, $f12
  jal   sub_GAME_7F058688
   sw    $a1, 0x30($sp)
  b     .L7F066234
   nop   
  mtc1  $zero, $f12
.L7F066228:
  sw    $a1, 0x30($sp)
  jal   sub_GAME_7F058688
   neg.s $f12, $f12
.L7F066234:
  lui   $at, %hi(D_8005438C)
  lwc1  $f12, %lo(D_8005438C)($at)
  jal   sub_GAME_7F058570
   addiu $a1, $sp, 0xe4
  addiu $a0, $sp, 0xe4
  jal   matrix_4x4_multiply_in_place
   lw    $a1, 0x30($sp)
  mtc1  $zero, $f12
  jal   sinf
   nop   
  mtc1  $zero, $f4
  move  $a0, $s1
  jal   sub_GAME_7F0649AC
   swc1  $f4, 0xac($s0)
  lui   $at, %hi(D_80054390)
  lwc1  $f12, %lo(D_80054390)($at)
  jal   cosf
   swc1  $f0, 0x40($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  lwc1  $f10, 0x40($sp)
  lui   $at, %hi(D_80054394)
  sub.s $f6, $f8, $f0
  mul.s $f4, $f6, $f10
  swc1  $f4, 0xb0($s0)
  jal   sinf
   lwc1  $f12, %lo(D_80054394)($at)
  li    $at, 0x41700000 # 15.000000
  mtc1  $at, $f8
  lw    $v0, 0x24($s0)
  mul.s $f6, $f0, $f8
  swc1  $f6, 0xb4($s0)
.L7F0662B4:
  li    $at, 12
.L7F0662B8:
  bnel  $v0, $at, .L7F066424
   li    $at, 14
  lw    $t8, 0x1c($s0)
  bnezl $t8, .L7F0662E4
   lw    $t5, 0x20($s0)
  jal   sub_GAME_7F0649D8
   lw    $a0, 0x1d0($sp)
  lui   $t4, %hi(pPlayer) 
  lw    $t4, %lo(pPlayer)($t4)
  sw    $zero, 0xfc8($t4)
  lw    $t5, 0x20($s0)
.L7F0662E4:
  slti  $at, $t5, 0x17
  beql  $at, $zero, .L7F066324
   sw    $zero, 0x24($s0)
  jal   get_ptr_weapon_model_header_line
   move  $a0, $s1
  beqz  $v0, .L7F066320
   move  $a0, $s1
  jal   check_special_attributes
   li    $a1, 2048
  beqz  $v0, .L7F066320
   move  $a0, $s1
  jal   check_special_attributes
   li    $a1, 8192
  beql  $v0, $zero, .L7F066338
   lw    $t6, 0x20($s0)
.L7F066320:
  sw    $zero, 0x24($s0)
.L7F066324:
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
  b     .L7F066420
   move  $v0, $zero
  lw    $t6, 0x20($s0)
.L7F066338:
  li    $t7, 23
  li    $at, 0x41B80000 # 23.000000
  subu  $t9, $t7, $t6
  mtc1  $t9, $f10
  mtc1  $at, $f2
  lui   $at, %hi(D_80054398)
  cvt.s.w $f4, $f10
  lwc1  $f8, %lo(D_80054398)($at)
  li    $t3, 1
  addiu $a1, $s0, 0x7c
  mul.s $f6, $f4, $f8
  div.s $f10, $f6, $f2
  swc1  $f10, 0x98($sp)
  sw    $t3, 0xbc($s0)
  lw    $t8, 0x1d0($sp)
  bnezl $t8, .L7F06639C
   mtc1  $zero, $f8
  mtc1  $zero, $f4
  sw    $a1, 0x30($sp)
  div.s $f12, $f4, $f2
  jal   sub_GAME_7F058688
   swc1  $f12, 0x3c($sp)
  b     .L7F0663B4
   lwc1  $f12, 0x98($sp)
  mtc1  $zero, $f8
.L7F06639C:
  sw    $a1, 0x30($sp)
  div.s $f0, $f8, $f2
  neg.s $f12, $f0
  jal   sub_GAME_7F058688
   swc1  $f0, 0x3c($sp)
  lwc1  $f12, 0x98($sp)
.L7F0663B4:
  jal   sub_GAME_7F058570
   addiu $a1, $sp, 0x9c
  addiu $a0, $sp, 0x9c
  jal   matrix_4x4_multiply_in_place
   lw    $a1, 0x30($sp)
  jal   sinf
   lwc1  $f12, 0x3c($sp)
  mtc1  $zero, $f6
  move  $a0, $s1
  jal   sub_GAME_7F0649AC
   swc1  $f6, 0xac($s0)
  swc1  $f0, 0x40($sp)
  jal   cosf
   lwc1  $f12, 0x98($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  lwc1  $f8, 0x40($sp)
  sub.s $f4, $f10, $f0
  mul.s $f6, $f4, $f8
  swc1  $f6, 0xb0($s0)
  jal   sinf
   lwc1  $f12, 0x98($sp)
  li    $at, 0x41700000 # 15.000000
  mtc1  $at, $f10
  lw    $v0, 0x24($s0)
  mul.s $f4, $f0, $f10
  swc1  $f4, 0xb4($s0)
.L7F066420:
  li    $at, 14
.L7F066424:
  bnel  $v0, $at, .L7F0664E0
   li    $at, 15
  lw    $v1, 0x20($s0)
  li    $v0, 15
  slti  $at, $v1, 0x10
  beql  $at, $zero, .L7F066450
   sw    $v0, 0x24($s0)
  lb    $t4, 0xf($s0)
  bnezl $t4, .L7F066460
   mtc1  $v1, $f8
  sw    $v0, 0x24($s0)
.L7F066450:
  sw    $zero, 0x20($s0)
  b     .L7F0664DC
   sw    $zero, 0x1c($s0)
  mtc1  $v1, $f8
.L7F066460:
  lui   $at, %hi(D_8005439C)
  lwc1  $f10, %lo(D_8005439C)($at)
  cvt.s.w $f6, $f8
  li    $at, 0x41800000 # 16.000000
  mtc1  $at, $f8
  li    $t7, 1
  sw    $t7, 0xbc($s0)
  addiu $a1, $s0, 0x7c
  mul.s $f4, $f6, $f10
  div.s $f12, $f4, $f8
  jal   sub_GAME_7F058570
   swc1  $f12, 0x94($sp)
  mtc1  $zero, $f6
  nop   
  swc1  $f6, 0xac($s0)
  jal   cosf
   lwc1  $f12, 0x94($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  li    $at, 0xC2700000 # -60.000000
  mtc1  $at, $f8
  sub.s $f4, $f10, $f0
  mul.s $f6, $f4, $f8
  swc1  $f6, 0xb0($s0)
  jal   sinf
   lwc1  $f12, 0x94($sp)
  li    $at, 0x41700000 # 15.000000
  mtc1  $at, $f10
  lw    $v0, 0x24($s0)
  mul.s $f4, $f0, $f10
  swc1  $f4, 0xb4($s0)
.L7F0664DC:
  li    $at, 15
.L7F0664E0:
  bnel  $v0, $at, .L7F0665A8
   li    $at, 16
  lw    $t6, 0x1c($s0)
  beql  $t6, $zero, .L7F066508
   lw    $a0, 0x1d0($sp)
  jal   sub_GAME_7F05CEBC
   lw    $a0, 0x1d0($sp)
  bnez  $v0, .L7F06651C
   nop   
  lw    $a0, 0x1d0($sp)
.L7F066508:
  jal   sub_GAME_7F05DA8C
   lw    $a1, 0x3c($s0)
  jal   return_ammo_in_hand
   lw    $a0, 0x1d0($sp)
  move  $s1, $v0
.L7F06651C:
  jal   sub_GAME_7F05CEBC
   lw    $a0, 0x1d0($sp)
  beqz  $v0, .L7F066540
   li    $t3, 1
  li    $v0, 16
  sw    $v0, 0x24($s0)
  sw    $zero, 0x20($s0)
  b     .L7F0665A4
   sw    $zero, 0x1c($s0)
.L7F066540:
  sw    $t3, 0xbc($s0)
  lui   $at, %hi(D_800543A0)
  lwc1  $f12, %lo(D_800543A0)($at)
  jal   sub_GAME_7F058570
   addiu $a1, $s0, 0x7c
  mtc1  $zero, $f8
  lui   $at, %hi(D_800543A4)
  swc1  $f8, 0xac($s0)
  jal   cosf
   lwc1  $f12, %lo(D_800543A4)($at)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  li    $at, 0xC2700000 # -60.000000
  mtc1  $at, $f4
  sub.s $f10, $f6, $f0
  lui   $at, %hi(D_800543A8)
  mul.s $f8, $f10, $f4
  swc1  $f8, 0xb0($s0)
  jal   sinf
   lwc1  $f12, %lo(D_800543A8)($at)
  li    $at, 0x41700000 # 15.000000
  mtc1  $at, $f6
  lw    $v0, 0x24($s0)
  mul.s $f10, $f0, $f6
  swc1  $f10, 0xb4($s0)
.L7F0665A4:
  li    $at, 16
.L7F0665A8:
  bnel  $v0, $at, .L7F0666DC
   li    $at, 17
  lw    $t8, 0x1c($s0)
  slti  $at, $s1, 0x21
  bnezl $t8, .L7F0665FC
   lw    $t5, 0x20($s0)
  beql  $at, $zero, .L7F0665FC
   lw    $t5, 0x20($s0)
  jal   getPlayerCount
   nop   
  slti  $at, $v0, 2
  bnez  $at, .L7F0665E4
   nop   
  jal   sub_GAME_7F09B398
   lw    $a0, 0x1d0($sp)
.L7F0665E4:
  jal   sub_GAME_7F0649D8
   lw    $a0, 0x1d0($sp)
  lui   $t4, %hi(pPlayer) 
  lw    $t4, %lo(pPlayer)($t4)
  sw    $zero, 0xfc8($t4)
  lw    $t5, 0x20($s0)
.L7F0665FC:
  slti  $at, $t5, 0x17
  beql  $at, $zero, .L7F06663C
   sw    $zero, 0x24($s0)
  jal   get_ptr_weapon_model_header_line
   move  $a0, $s1
  beqz  $v0, .L7F066638
   move  $a0, $s1
  jal   check_special_attributes
   li    $a1, 2048
  beqz  $v0, .L7F066638
   move  $a0, $s1
  jal   check_special_attributes
   li    $a1, 8192
  beql  $v0, $zero, .L7F066650
   lw    $t7, 0x20($s0)
.L7F066638:
  sw    $zero, 0x24($s0)
.L7F06663C:
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
  b     .L7F0666D8
   move  $v0, $zero
  lw    $t7, 0x20($s0)
.L7F066650:
  li    $t6, 23
  lui   $at, %hi(D_800543AC)
  subu  $t9, $t6, $t7
  mtc1  $t9, $f4
  lwc1  $f6, %lo(D_800543AC)($at)
  li    $at, 0x41B80000 # 23.000000
  cvt.s.w $f8, $f4
  mtc1  $at, $f4
  li    $t3, 1
  sw    $t3, 0xbc($s0)
  addiu $a1, $s0, 0x7c
  mul.s $f10, $f8, $f6
  div.s $f12, $f10, $f4
  jal   sub_GAME_7F058570
   swc1  $f12, 0x8c($sp)
  mtc1  $zero, $f8
  nop   
  swc1  $f8, 0xac($s0)
  jal   cosf
   lwc1  $f12, 0x8c($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  li    $at, 0xC2700000 # -60.000000
  mtc1  $at, $f4
  sub.s $f10, $f6, $f0
  mul.s $f8, $f10, $f4
  swc1  $f8, 0xb0($s0)
  jal   sinf
   lwc1  $f12, 0x8c($sp)
  li    $at, 0x41700000 # 15.000000
  mtc1  $at, $f6
  lw    $v0, 0x24($s0)
  mul.s $f10, $f0, $f6
  swc1  $f10, 0xb4($s0)
.L7F0666D8:
  li    $at, 17
.L7F0666DC:
  beq   $v0, $at, .L7F06670C
   li    $at, 18
  beq   $v0, $at, .L7F06670C
   li    $a0, 19
  beq   $a0, $v0, .L7F06670C
   li    $at, 20
  beq   $v0, $at, .L7F06670C
   li    $at, 21
  beq   $v0, $at, .L7F06670C
   li    $at, 22
  bnel  $v0, $at, .L7F066860
   li    $at, 30
.L7F06670C:
  lw    $v1, 0x20($s0)
  addiu $t8, $s0, 0x7c
  li    $at, 17
  mtc1  $v1, $f4
  li    $a0, 19
  sw    $t8, 0x30($sp)
  cvt.s.w $f8, $f4
  beq   $v0, $at, .L7F066738
   swc1  $f8, 0x88($sp)
  li    $at, 20
  bne   $v0, $at, .L7F0667B0
.L7F066738:
   slti  $at, $v1, 0x10
  bnez  $at, .L7F0667B0
   lui   $t5, %hi(D_80035E94) 
  addiu $t5, %lo(D_80035E94) # addiu $t5, $t5, 0x5e94
  lw    $at, ($t5)
  addiu $t4, $sp, 0x7c
  sw    $at, ($t4)
  lhu   $at, 4($t5)
  jal   get_random_value
   sh    $at, 4($t4)
  li    $at, 3
  divu  $zero, $v0, $at
  mfhi  $t9
  sll   $t3, $t9, 1
  addu  $a1, $sp, $t3
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  lh    $a1, 0x7c($a1)
  jal   play_sfx_a1
   move  $a2, $zero
  lw    $t8, 0x24($s0)
  li    $at, 17
  li    $v0, 21
  bne   $t8, $at, .L7F0667AC
   li    $a0, 19
  li    $v0, 18
  sw    $v0, 0x24($s0)
  b     .L7F0667B0
   li    $a0, 19
.L7F0667AC:
  sw    $v0, 0x24($s0)
.L7F0667B0:
  beq   $a0, $v0, .L7F0667FC
   li    $at, 22
  beql  $v0, $at, .L7F066800
   li    $at, 17
  lw    $t5, 0x20($s0)
  li    $t7, 1
  slti  $at, $t5, 0x18
  bnez  $at, .L7F0667FC
   li    $at, 17
  beq   $v0, $at, .L7F0667E8
   sb    $t7, 0xc($s0)
  li    $at, 18
  bnel  $v0, $at, .L7F0667F8
   li    $v0, 22
.L7F0667E8:
  sw    $a0, 0x24($s0)
  b     .L7F0667FC
   move  $v0, $a0
  li    $v0, 22
.L7F0667F8:
  sw    $v0, 0x24($s0)
.L7F0667FC:
  li    $at, 17
.L7F066800:
  beq   $v0, $at, .L7F066818
   lw    $a1, 0x88($sp)
  li    $at, 18
  beq   $v0, $at, .L7F066818
   nop   
  bne   $a0, $v0, .L7F066824
.L7F066818:
   lui   $a0, %hi(D_80034CA4)
  b     .L7F06682C
   addiu $a0, %lo(D_80034CA4) # addiu $a0, $a0, 0x4ca4
.L7F066824:
  lui   $a0, %hi(D_80034E0C)
  addiu $a0, %lo(D_80034E0C) # addiu $a0, $a0, 0x4e0c
.L7F06682C:
  lw    $a2, 0x30($sp)
  jal   sub_GAME_7F05C6FC
   lw    $a3, 0x1d0($sp)
  beqz  $v0, .L7F06684C
   li    $t3, 1
  sw    $t3, 0xbc($s0)
  b     .L7F06685C
   lw    $v0, 0x24($s0)
.L7F06684C:
  sw    $zero, 0x24($s0)
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
  move  $v0, $zero
.L7F06685C:
  li    $at, 30
.L7F066860:
  beq   $v0, $at, .L7F066880
   li    $a1, 31
  beq   $a1, $v0, .L7F066880
   li    $at, 32
  beq   $v0, $at, .L7F066880
   li    $a0, 33
  bnel  $a0, $v0, .L7F066980
   li    $at, 26
.L7F066880:
  lw    $v1, 0x20($s0)
  li    $at, 30
  li    $a0, 33
  mtc1  $v1, $f6
  li    $a1, 31
  addiu $a2, $s0, 0x7c
  beq   $v0, $at, .L7F0668A8
   cvt.s.w $f0, $f6
  bne   $a1, $v0, .L7F0668F4
   li    $at, 32
.L7F0668A8:
  lui   $t8, %hi(pPlayer) 
  lw    $t8, %lo(pPlayer)($t8)
  li    $at, 17
  lui   $t4, %hi(D_80035778) 
  lw    $t6, 0x2a38($t8)
  lui   $t5, %hi(D_800354A8) 
  addiu $t4, %lo(D_80035778) # addiu $t4, $t4, 0x5778
  bne   $t6, $at, .L7F0668D4
   addiu $t5, %lo(D_800354A8) # addiu $t5, $t5, 0x54a8
  b     .L7F0668D8
   sw    $t4, 0x74($sp)
.L7F0668D4:
  sw    $t5, 0x74($sp)
.L7F0668D8:
  beq   $a1, $v0, .L7F066948
   slti  $at, $v1, 0x1e
  bnez  $at, .L7F066948
   li    $t7, 1
  sb    $t7, 0xc($s0)
  b     .L7F066948
   sw    $a1, 0x24($s0)
.L7F0668F4:
  beq   $v0, $at, .L7F066904
   lui   $t9, %hi(pPlayer) 
  bnel  $a0, $v0, .L7F06694C
   mfc1  $a1, $f0
.L7F066904:
  lw    $t9, %lo(pPlayer)($t9)
  li    $at, 17
  lui   $t8, %hi(D_80035904) 
  lw    $t3, 0x2a38($t9)
  lui   $t6, %hi(D_80035610) 
  addiu $t8, %lo(D_80035904) # addiu $t8, $t8, 0x5904
  bne   $t3, $at, .L7F06692C
   addiu $t6, %lo(D_80035610) # addiu $t6, $t6, 0x5610
  b     .L7F066930
   sw    $t8, 0x74($sp)
.L7F06692C:
  sw    $t6, 0x74($sp)
.L7F066930:
  beq   $a0, $v0, .L7F066948
   slti  $at, $v1, 0x1e
  bnez  $at, .L7F066948
   li    $t4, 1
  sb    $t4, 0xc($s0)
  sw    $a0, 0x24($s0)
.L7F066948:
  mfc1  $a1, $f0
.L7F06694C:
  lw    $a0, 0x74($sp)
  jal   sub_GAME_7F05C6FC
   lw    $a3, 0x1d0($sp)
  beqz  $v0, .L7F06696C
   li    $t5, 1
  sw    $t5, 0xbc($s0)
  b     .L7F06697C
   lw    $v0, 0x24($s0)
.L7F06696C:
  sw    $zero, 0x24($s0)
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
  move  $v0, $zero
.L7F06697C:
  li    $at, 26
.L7F066980:
  bnel  $v0, $at, .L7F066A10
   li    $at, 27
  lw    $t7, 0x2c($s0)
  move  $v0, $zero
  blezl $t7, .L7F066A04
   sw    $zero, 0x24($s0)
  lw    $t9, 0x20($s0)
  lui   $a0, %hi(D_80035124)
  addiu $a0, %lo(D_80035124) # addiu $a0, $a0, 0x5124
  mtc1  $t9, $f10
  addiu $a2, $s0, 0x7c
  lw    $a3, 0x1d0($sp)
  cvt.s.w $f0, $f10
  mfc1  $a1, $f0
  jal   sub_GAME_7F05C6FC
   nop   
  beqz  $v0, .L7F0669D4
   li    $t8, 1
  li    $t3, 1
  b     .L7F0669F8
   sw    $t3, 0xbc($s0)
.L7F0669D4:
  lw    $t6, 0x2c($s0)
  li    $t5, 27
  sb    $zero, 0xe($s0)
  addiu $t4, $t6, -1
  sb    $t8, 0xc($s0)
  sw    $t4, 0x2c($s0)
  sw    $t5, 0x24($s0)
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
.L7F0669F8:
  b     .L7F066A0C
   lw    $v0, 0x24($s0)
  sw    $zero, 0x24($s0)
.L7F066A04:
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
.L7F066A0C:
  li    $at, 27
.L7F066A10:
  bnel  $v0, $at, .L7F066A70
   li    $at, 23
  lw    $t7, 0x20($s0)
  lui   $a0, %hi(D_800351FC)
  addiu $a0, %lo(D_800351FC) # addiu $a0, $a0, 0x51fc
  mtc1  $t7, $f4
  addiu $a2, $s0, 0x7c
  lw    $a3, 0x1d0($sp)
  cvt.s.w $f0, $f4
  mfc1  $a1, $f0
  jal   sub_GAME_7F05C6FC
   nop   
  beqz  $v0, .L7F066A58
   li    $t3, 1
  li    $t9, 1
  sw    $t9, 0xbc($s0)
  b     .L7F066A6C
   lw    $v0, 0x24($s0)
.L7F066A58:
  sb    $t3, 0xe($s0)
  sw    $zero, 0x24($s0)
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
  move  $v0, $zero
.L7F066A6C:
  li    $at, 23
.L7F066A70:
  bnel  $v0, $at, .L7F066B24
   li    $at, 24
  lw    $t8, 0x2c($s0)
  move  $v0, $zero
  blezl $t8, .L7F066B18
   sw    $zero, 0x24($s0)
  lw    $t6, 0x18($s0)
  li    $t4, 24
  beql  $t6, $zero, .L7F066AA4
   lw    $t5, 0x20($s0)
  b     .L7F066B0C
   sw    $t4, 0x24($s0)
  lw    $t5, 0x20($s0)
.L7F066AA4:
  lui   $a0, %hi(D_80034F74)
  addiu $a2, $s0, 0x7c
  mtc1  $t5, $f8
  sw    $a2, 0x30($sp)
  addiu $a0, %lo(D_80034F74) # addiu $a0, $a0, 0x4f74
  cvt.s.w $f0, $f8
  lw    $a3, 0x1d0($sp)
  mfc1  $a1, $f0
  jal   sub_GAME_7F05C6FC
   nop   
  beqz  $v0, .L7F066AE0
   lui   $a0, %hi(D_8003504C)
  li    $t7, 1
  b     .L7F066B0C
   sw    $t7, 0xbc($s0)
.L7F066AE0:
  addiu $a0, %lo(D_8003504C) # addiu $a0, $a0, 0x504c
  li    $a1, 0
  lw    $a2, 0x30($sp)
  jal   sub_GAME_7F05C6FC
   lw    $a3, 0x1d0($sp)
  beqz  $v0, .L7F066B08
   li    $t3, 24
  li    $t9, 1
  b     .L7F066B0C
   sw    $t9, 0xbc($s0)
.L7F066B08:
  sw    $t3, 0x24($s0)
.L7F066B0C:
  b     .L7F066B20
   lw    $v0, 0x24($s0)
  sw    $zero, 0x24($s0)
.L7F066B18:
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
.L7F066B20:
  li    $at, 24
.L7F066B24:
  bnel  $v0, $at, .L7F066BB4
   li    $at, 25
  lw    $t8, 0x2c($s0)
  move  $v0, $zero
  blezl $t8, .L7F066BA8
   sw    $zero, 0x24($s0)
  lw    $t6, 0x20($s0)
  lui   $a0, %hi(D_80034F74)
  addiu $a0, %lo(D_80034F74) # addiu $a0, $a0, 0x4f74
  mtc1  $t6, $f6
  addiu $a2, $s0, 0x7c
  lw    $a3, 0x1d0($sp)
  cvt.s.w $f0, $f6
  mfc1  $a1, $f0
  jal   sub_GAME_7F05C6FC
   nop   
  beqz  $v0, .L7F066B78
   li    $t5, 1
  li    $t4, 1
  b     .L7F066B9C
   sw    $t4, 0xbc($s0)
.L7F066B78:
  lw    $t7, 0x2c($s0)
  li    $t3, 25
  sb    $zero, 0xe($s0)
  addiu $t9, $t7, -1
  sb    $t5, 0xc($s0)
  sw    $t9, 0x2c($s0)
  sw    $t3, 0x24($s0)
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
.L7F066B9C:
  b     .L7F066BB0
   lw    $v0, 0x24($s0)
  sw    $zero, 0x24($s0)
.L7F066BA8:
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
.L7F066BB0:
  li    $at, 25
.L7F066BB4:
  bnel  $v0, $at, .L7F066C14
   li    $at, 28
  lw    $t8, 0x20($s0)
  lui   $a0, %hi(D_8003504C)
  addiu $a0, %lo(D_8003504C) # addiu $a0, $a0, 0x504c
  mtc1  $t8, $f10
  addiu $a2, $s0, 0x7c
  lw    $a3, 0x1d0($sp)
  cvt.s.w $f0, $f10
  mfc1  $a1, $f0
  jal   sub_GAME_7F05C6FC
   nop   
  beqz  $v0, .L7F066BFC
   li    $t4, 1
  li    $t6, 1
  sw    $t6, 0xbc($s0)
  b     .L7F066C10
   lw    $v0, 0x24($s0)
.L7F066BFC:
  sb    $t4, 0xe($s0)
  sw    $zero, 0x24($s0)
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
  move  $v0, $zero
.L7F066C10:
  li    $at, 28
.L7F066C14:
  bnel  $v0, $at, .L7F066CB8
   li    $at, 29
  lw    $t5, 0x2c($s0)
  move  $a0, $s1
  bgtzl $t5, .L7F066C40
   lw    $t7, 0x20($s0)
  jal   check_special_attributes
   li    $a1, 16
  beql  $v0, $zero, .L7F066CA8
   sw    $zero, 0x24($s0)
  lw    $t7, 0x20($s0)
.L7F066C40:
  lui   $a0, %hi(D_800352D4)
  addiu $a0, %lo(D_800352D4) # addiu $a0, $a0, 0x52d4
  mtc1  $t7, $f4
  addiu $a2, $s0, 0x7c
  lw    $a3, 0x1d0($sp)
  cvt.s.w $f0, $f4
  mfc1  $a1, $f0
  jal   sub_GAME_7F05C6FC
   nop   
  beqz  $v0, .L7F066C78
   li    $t3, 1
  li    $t9, 1
  b     .L7F066C9C
   sw    $t9, 0xbc($s0)
.L7F066C78:
  lw    $t8, 0x2c($s0)
  li    $t4, 29
  sb    $zero, 0xe($s0)
  addiu $t6, $t8, -1
  sb    $t3, 0xc($s0)
  sw    $t6, 0x2c($s0)
  sw    $t4, 0x24($s0)
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
.L7F066C9C:
  b     .L7F066CB4
   lw    $v0, 0x24($s0)
  sw    $zero, 0x24($s0)
.L7F066CA8:
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
  move  $v0, $zero
.L7F066CB4:
  li    $at, 29
.L7F066CB8:
  bnel  $v0, $at, .L7F066D18
   li    $at, 36
  lw    $t5, 0x20($s0)
  lui   $a0, %hi(D_800353AC)
  addiu $a0, %lo(D_800353AC) # addiu $a0, $a0, 0x53ac
  mtc1  $t5, $f8
  addiu $a2, $s0, 0x7c
  lw    $a3, 0x1d0($sp)
  cvt.s.w $f0, $f8
  mfc1  $a1, $f0
  jal   sub_GAME_7F05C6FC
   nop   
  beqz  $v0, .L7F066D00
   li    $t9, 1
  li    $t7, 1
  sw    $t7, 0xbc($s0)
  b     .L7F066D14
   lw    $v0, 0x24($s0)
.L7F066D00:
  sb    $t9, 0xe($s0)
  sw    $zero, 0x24($s0)
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
  move  $v0, $zero
.L7F066D14:
  li    $at, 36
.L7F066D18:
  bne   $v0, $at, .L7F066E50
   li    $at, 46
  bnel  $s1, $at, .L7F066D48
   li    $at, 44
  lw    $t3, 0x1c($s0)
  bnez  $t3, .L7F066D3C
   nop   
  jal   sub_GAME_7F066E64
   nop   
.L7F066D3C:
  b     .L7F066E3C
   lw    $a1, 0x18($s0)
  li    $at, 44
.L7F066D48:
  bnel  $s1, $at, .L7F066D70
   li    $at, 39
  lw    $t8, 0x1c($s0)
  bnez  $t8, .L7F066D64
   nop   
  jal   sub_GAME_7F066F08
   nop   
.L7F066D64:
  b     .L7F066E3C
   lw    $a1, 0x18($s0)
  li    $at, 39
.L7F066D70:
  beq   $s1, $at, .L7F066D98
   li    $at, 55
  beq   $s1, $at, .L7F066D98
   li    $at, 38
  beq   $s1, $at, .L7F066D98
   li    $at, 50
  beq   $s1, $at, .L7F066D98
   li    $at, 73
  bnel  $s1, $at, .L7F066DD0
   li    $at, 51
.L7F066D98:
  lw    $t6, 0x1c($s0)
  bnez  $t6, .L7F066DC4
   nop   
  jal   sub_GAME_7F03C3FC
   nop   
  beqz  $v0, .L7F066DC4
   nop   
  lw    $v1, 4($v0)
  lbu   $t4, 2($v1)
  ori   $t5, $t4, 0x40
  sb    $t5, 2($v1)
.L7F066DC4:
  b     .L7F066E3C
   lw    $a1, 0x18($s0)
  li    $at, 51
.L7F066DD0:
  beq   $s1, $at, .L7F066E3C
   lw    $a1, 0x18($s0)
  li    $at, 52
  beq   $s1, $at, .L7F066E3C
   li    $at, 58
  beq   $s1, $at, .L7F066E3C
   li    $at, 59
  beq   $s1, $at, .L7F066E3C
   li    $at, 81
  beq   $s1, $at, .L7F066E3C
   li    $at, 82
  beq   $s1, $at, .L7F066E3C
   li    $at, 83
  beq   $s1, $at, .L7F066E3C
   li    $at, 45
  beq   $s1, $at, .L7F066E3C
   li    $at, 41
  beq   $s1, $at, .L7F066E3C
   li    $at, 42
  beq   $s1, $at, .L7F066E3C
   li    $at, 53
  beq   $s1, $at, .L7F066E3C
   li    $at, 54
  beq   $s1, $at, .L7F066E3C
   li    $at, 37
  beq   $s1, $at, .L7F066E3C
   nop   
.L7F066E3C:
  beql  $a1, $zero, .L7F066E54
   lw    $ra, 0x24($sp)
  sw    $zero, 0x24($s0)
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
.L7F066E50:
  lw    $ra, 0x24($sp)
.L7F066E54:
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x1d0
");

#ifdef VERSION_JP
asm(R"
    .late_rodata
/*D:80053F24*/
glabel jpt_80053F24
.word Weapon_function_slapper
.word Weapon_function_hunting_knife
.word Weapon_function_throwing_knife
.word Weapon_function_guns
.word Weapon_function_guns
.word Weapon_function_guns
.word Weapon_function_guns
.word Weapon_function_guns
.word Weapon_function_guns
.word Weapon_function_guns
.word Weapon_function_guns
.word Weapon_function_guns
.word Weapon_function_guns
.word Weapon_function_guns
.word Weapon_function_guns
.word Weapon_function_guns
.word Weapon_function_guns
.word Weapon_function_magnum
.word Weapon_function_guns
.word Weapon_function_guns
.word Weapon_function_guns
.word Weapon_function_guns
.word Weapon_function_guns
.word Weapon_function_magnum
.word Weapon_function_guns
.word Weapon_function_grenades
.word Weapon_function_throwable_item
.word Weapon_function_throwable_item
.word Weapon_function_throwable_item
.word Weapon_function_guns
.word Weapon_function_tazer
.word Weapon_function_guns
.word Weapon_function_throwable_item
.word Weapon_function_throwable_item
.word Weapon_function_guns
.word Weapon_function_guns
.word Weapon_function_key
.word Weapon_function_key
.word Weapon_function_key
.word Weapon_function_camera
.word Weapon_function_key
.word Weapon_function_key
.word Weapon_function_collectible
.word Weapon_function_key
.word Weapon_function_key
.word Weapon_function_key
.word Weapon_function_throwable_item
.word Weapon_function_throwable_item
.word Weapon_function_key
.word Weapon_function_key
.word Weapon_function_key
.word Weapon_function_key
.word Weapon_function_key
.word Weapon_function_key
.word Weapon_function_key
.word Weapon_function_key
.word Weapon_function_key
.word Weapon_function_key
.word Weapon_function_key
.word Weapon_function_guns
.word Weapon_function_throwable_item
.word Weapon_function_collectible
.word Weapon_function_collectible
.word Weapon_function_collectible
.word Weapon_function_collectible
.word Weapon_function_collectible
.word Weapon_function_collectible
.word Weapon_function_collectible
.word Weapon_function_collectible
.word Weapon_function_collectible
.word Weapon_function_collectible
.word Weapon_function_collectible
.word Weapon_function_key
.word Weapon_function_collectible
.word Weapon_function_collectible
.word Weapon_function_collectible
.word Weapon_function_collectible
.word Weapon_function_collectible
.word Weapon_function_collectible
.word Weapon_function_collectible
.word Weapon_function_key
.word Weapon_function_key
.word Weapon_function_key
.word Weapon_function_collectible
.word Weapon_function_collectible
.word Weapon_function_collectible
.word Weapon_function_collectible
.word Weapon_function_collectible

/*D:80054084*/
glabel jpt_80054084
.word Weapon_shooting_noammo
.word Weapon_shooting_throwable
.word Weapon_shooting_pistol
.word Weapon_shooting_pistol
.word Weapon_shooting_pistol
.word Weapon_shooting_machinegun
.word Weapon_shooting_machinegun
.word Weapon_shooting_machinegun
.word Weapon_shooting_machinegun
.word Weapon_shooting_machinegun
.word Weapon_shooting_machinegun
.word Weapon_shooting_machinegun
.word Weapon_shooting_machinegun
.word Weapon_shooting_pistol
.word Weapon_shooting_pistol
.word Weapon_shooting_pistol
.word Weapon_shooting_pistol
.word Weapon_shooting_pistol
.word Weapon_shooting_pistol
.word Weapon_shooting_pistol
.word Weapon_shooting_pistol
.word Weapon_shooting_pistol
.word Weapon_shooting_pistol
.word Weapon_shooting_pistol
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_pistol
.word Weapon_shooting_tazer
.word Weapon_shooting_pistol
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_pistol
.word Weapon_shooting_pistol
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_watch_magnet
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_throwable
.word Weapon_shooting_watch_magnet

glabel D_80054170
.word 0x40c90fdb /*6.2831855*/
glabel D_80054174
.word 0x3fc90fdb /*1.5707964*/
glabel D_80054178
.word 0x40c90fdb /*6.2831855*/
glabel D_8005417C
.word 0x40490fdb /*3.1415927*/
glabel D_80054180
.word 0x3fc90fdb /*1.5707964*/
glabel D_80054184
.word 0x3f32b8c3 /*0.69813174*/
glabel D_80054188
.word 0x3f32b8c3 /*0.69813174*/
glabel D_8005418C
.word 0x3f32b8c3 /*0.69813174*/
glabel D_80054190
.word 0x3f32b8c3 /*0.69813174*/

/*D:80054194*/
glabel jpt_80054194
.word weapon_switchstyle_NONE
.word weapon_switchstyle_NONE
.word weapon_playsfx_knife
.word weapon_playsfx_knife
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_F2
.word weapon_switchstyle_NONE
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_switchstyle_NONE
.word weapon_playsfx_mine
.word weapon_playsfx_mine
.word weapon_playsfx_mine
.word weapon_switchstyle_NONE
.word weapon_switchstyle_NONE
.word weapon_switchstyle_NONE
.word weapon_switchstyle_NONE
.word weapon_switchstyle_NONE
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_switchstyle_NONE
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_switchstyle_NONE
.word weapon_switchstyle_NONE
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_playsfx_gun
.word weapon_switchstyle_NONE
.word weapon_switchstyle_NONE

glabel D_8005428C
.word 0x3f32b8c3 /*0.69813174*/
glabel D_80054290
.word 0x3f32b8c3 /*0.69813174*/

/*D:80054294*/
glabel jpt_80054294
.word weapon_reload_none_sfx
.word weapon_reload_none_sfx
.word weapon_reload_none_sfx
.word weapon_reload_none_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_none_sfx
.word weapon_reload_none_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_none_sfx
.word weapon_reload_none_sfx
.word weapon_reload_none_sfx
.word weapon_reload_none_sfx
.word weapon_reload_none_sfx
.word weapon_reload_none_sfx
.word weapon_reload_none_sfx
.word weapon_reload_none_sfx
.word weapon_reload_none_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_none_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_none_sfx
.word weapon_reload_none_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_gun_sfx
.word weapon_reload_none_sfx
.word weapon_reload_none_sfx

glabel D_8005438C
.word 0x3floatb8c3 /*0.69813174*/
glabel D_80054390
.word 0x3floatb8c3 /*0.69813174*/
glabel D_80054394
.word 0x3floatb8c3 /*0.69813174*/
glabel D_80054398
.word 0x3floatb8c3 /*0.69813174*/
glabel D_8005439C
.word 0x3floatb8c3 /*0.69813174*/
glabel D_800543A0
.word 0x3floatb8c3 /*0.69813174*/
glabel D_800543A4
.word 0x3floatb8c3 /*0.69813174*/
glabel D_800543A8
.word 0x3floatb8c3 /*0.69813174*/
glabel D_800543AC
.word 0x3floatb8c3 /*0.69813174*/
.text
glabel handle_weapon_id_values_possibly_1st_person_animation
  sll   $v0, $a0, 3
  subu  $v0, $v0, $a0
  sll   $v0, $v0, 2
  addiu $sp, $sp, -0x1e0
  addu  $v0, $v0, $a0
  lui   $t6, %hi(pPlayer) # $t6, 0x8008
  lw    $t6, %lo(pPlayer)($t6)
  sll   $v0, $v0, 2
  addu  $v0, $v0, $a0
  sw    $s0, 0x1c($sp)
  sll   $v0, $v0, 3
  sw    $ra, 0x24($sp)
  addu  $s0, $t6, $v0
  sw    $s1, 0x20($sp)
  sw    $a1, 0x1e4($sp)
  addiu $s0, $s0, 0x870
  sw    $v0, 0x3c($sp)
  jal   return_ammo_in_hand
   sw    $a0, 0x1e0($sp)
  move  $s1, $v0
  jal   get_ammo_type_for_weapon
   move  $a0, $v0
  lw    $v1, 0x1e4($sp)
  lw    $t7, 0x10($s0)
  move  $a2, $v0
  sw    $v1, 0x10($s0)
  bnez  $v1, .Ljp7F065104
   sw    $t7, 0x14($s0)
  li    $t8, 1
  sw    $t8, 0x18($s0)
.Ljp7F065104:
  sb    $zero, 0xc($s0)
  sb    $zero, 0xd($s0)
  lui   $v0, %hi(clock_timer) # $v0, 0x8005
  lw    $v0, %lo(clock_timer)($v0)
  blezl $v0, .Ljp7F065138
   lw    $t9, 0x24($s0)
  lw    $t9, 0x20($s0)
  lw    $t7, 0x1c($s0)
  addu  $t6, $t9, $v0
  addiu $t8, $t7, 1
  sw    $t6, 0x20($s0)
  sw    $t8, 0x1c($s0)
  lw    $t9, 0x24($s0)
.Ljp7F065138:
  sw    $zero, 0xbc($s0)
  bnez  $t9, .Ljp7F065334
   li    $at, 22
  bnel  $s1, $at, .Ljp7F065160
   lw    $t7, 0x10($s0)
  lw    $t6, 0x18($s0)
  beql  $t6, $zero, .Ljp7F065160
   lw    $t7, 0x10($s0)
  sw    $zero, 0x30($s0)
  lw    $t7, 0x10($s0)
.Ljp7F065160:
  beql  $t7, $zero, .Ljp7F0651C0
   lw    $v0, 0x28($s0)
  beqz  $s1, .Ljp7F0651BC
   move  $a0, $s1
  li    $a1, 16
  jal   check_special_attributes
   sw    $a2, 0x1d4($sp)
  bnez  $v0, .Ljp7F06518C
   lw    $a2, 0x1d4($sp)
  lw    $t8, 0x2c($s0)
  blez  $t8, .Ljp7F0651BC
.Ljp7F06518C:
   li    $at, 22
  bne   $s1, $at, .Ljp7F0651A8
   li    $t6, 1
  lw    $t9, 0x30($s0)
  slti  $at, $t9, 0xc8
  beql  $at, $zero, .Ljp7F0651C0
   lw    $v0, 0x28($s0)
.Ljp7F0651A8:
  sw    $t6, 0x24($s0)
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
  b     .Ljp7F0651D4
   sw    $zero, 0x18($s0)
.Ljp7F0651BC:
  lw    $v0, 0x28($s0)
.Ljp7F0651C0:
  beql  $v0, $zero, .Ljp7F0651D8
   lw    $t7, 0x24($s0)
  sw    $v0, 0x24($s0)
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
.Ljp7F0651D4:
  lw    $t7, 0x24($s0)
.Ljp7F0651D8:
  sw    $zero, 0x28($s0)
  bnezl $t7, .Ljp7F065338
   lw    $v0, 0x24($s0)
  lw    $t8, 0x2c($s0)
  bnezl $t8, .Ljp7F065338
   lw    $v0, 0x24($s0)
  beql  $a2, $zero, .Ljp7F065338
   lw    $v0, 0x24($s0)
  jal   get_controls_locked_flag
   sw    $a2, 0x1d4($sp)
  bnez  $v0, .Ljp7F065334
   lw    $a2, 0x1d4($sp)
  lui   $v0, %hi(pPlayer) # $v0, 0x8008
  lw    $v0, %lo(pPlayer)($v0)
  lui   $t6, %hi(D_80032458) # $t6, 0x8003
  lw    $t9, 0x29c4($v0)
  bnezl $t9, .Ljp7F065338
   lw    $v0, 0x24($s0)
  lw    $t6, %lo(D_80032458)($t6)
  li    $at, 1
  beqz  $t6, .Ljp7F065250
   nop   
  bne   $a2, $at, .Ljp7F065250
   sll   $t7, $a2, 2
  addu  $v1, $v0, $t7
  lw    $t8, 0x1130($v1)
  li    $t9, 1
  bgtz  $t8, .Ljp7F065250
   nop   
  sw    $t9, 0x1130($v1)
.Ljp7F065250:
  jal   get_ammo_in_hands_weapon
   lw    $a0, 0x1e0($sp)
  blez  $v0, .Ljp7F065274
   lui   $t7, %hi(pPlayer) # $t7, 0x8008
  li    $t6, 9
  sw    $t6, 0x24($s0)
  sw    $zero, 0x20($s0)
  b     .Ljp7F065334
   sw    $zero, 0x1c($s0)
.Ljp7F065274:
  lw    $t7, %lo(pPlayer)($t7)
  lw    $t9, 0x1e0($sp)
  li    $t6, 1
  lw    $t8, 0xfc8($t7)
  subu  $a0, $t6, $t9
  beql  $t8, $zero, .Ljp7F065338
   lw    $v0, 0x24($s0)
  jal   return_ammo_in_hand
   sw    $a0, 0x40($sp)
  lui   $t7, %hi(pPlayer) # $t7, 0x8008
  lw    $t7, %lo(pPlayer)($t7)
  lw    $t8, 0x3c($sp)
  move  $a0, $v0
  subu  $v1, $t7, $t8
  lw    $t6, 0xc3c($v1)
  addiu $v1, $v1, 0xc18
  bnezl $t6, .Ljp7F065338
   lw    $v0, 0x24($s0)
  lw    $t9, 0x28($v1)
  bnezl $t9, .Ljp7F065338
   lw    $v0, 0x24($s0)
  beqz  $v0, .Ljp7F065300
   nop   
  lw    $t7, 0x2c($v1)
  bnezl $t7, .Ljp7F065338
   lw    $v0, 0x24($s0)
  jal   get_ammo_type_for_weapon
   sw    $v1, 0x1cc($sp)
  beqz  $v0, .Ljp7F065334
   lw    $v1, 0x1cc($sp)
  lw    $a0, 0x40($sp)
  jal   get_ammo_in_hands_weapon
   sw    $v1, 0x1cc($sp)
  bgtz  $v0, .Ljp7F065334
   lw    $v1, 0x1cc($sp)
.Ljp7F065300:
  jal   autoadvance_on_deplete_all_ammo
   sw    $v1, 0x1cc($sp)
  lw    $v1, 0x1cc($sp)
  lw    $t8, 0x28($s0)
  sw    $zero, 0x1c($s0)
  sw    $zero, 0x20($s0)
  sw    $zero, 0x28($s0)
  sw    $t8, 0x24($s0)
  lw    $t6, 0x28($v1)
  sw    $zero, 0x1c($v1)
  sw    $zero, 0x20($v1)
  sw    $zero, 0x28($v1)
  sw    $t6, 0x24($v1)
.Ljp7F065334:
  lw    $v0, 0x24($s0)
.Ljp7F065338:
  li    $at, 1
  bne   $v0, $at, .Ljp7F065538
   addiu $t9, $s1, -1
  sltiu $at, $t9, 0x58
  beqz  $at, Weapon_function_collectible
   sll   $t9, $t9, 2
  lui   $at, %hi(jpt_80053F24)
  addu  $at, $at, $t9
  lw    $t9, %lo(jpt_80053F24)($at)
  jr    $t9
   nop   
Weapon_function_magnum:
  lw    $t7, 0x20($s0)
  li    $t8, 2
  slti  $at, $t7, 6
  bnezl $at, .Ljp7F065534
   sw    $zero, 0x398($s0)
  sw    $t8, 0x24($s0)
  sw    $zero, 0x20($s0)
  b     .Ljp7F065530
   sw    $zero, 0x1c($s0)
Weapon_function_camera:
  lw    $t6, 0x1c($s0)
  move  $a0, $zero
  move  $a1, $zero
  bnez  $t6, .Ljp7F0653AC
   move  $a2, $zero
  jal   set_rgba_tint
   lui   $a3, 0x3f80
  b     .Ljp7F065534
   sw    $zero, 0x398($s0)
.Ljp7F0653AC:
  lw    $t9, 0x20($s0)
  li    $at, 0x41000000 # 8.000000
  move  $a1, $zero
  blez  $t9, .Ljp7F065530
   move  $a2, $zero
  mtc1  $zero, $f4
  mtc1  $at, $f12
  move  $a3, $zero
  jal   sub_GAME_7F0807E0
   swc1  $f4, 0x10($sp)
  li    $t7, 2
  sw    $t7, 0x24($s0)
  sw    $zero, 0x20($s0)
  b     .Ljp7F065530
   sw    $zero, 0x1c($s0)
Weapon_function_guns:
  li    $t8, 2
  sw    $t8, 0x24($s0)
  sw    $zero, 0x20($s0)
  b     .Ljp7F065530
   sw    $zero, 0x1c($s0)
Weapon_function_throwable_item:
  li    $t6, 28
  sw    $t6, 0x24($s0)
  sw    $zero, 0x20($s0)
  b     .Ljp7F065530
   sw    $zero, 0x1c($s0)
Weapon_function_hunting_knife:
  jal   get_random_value
   nop   
  andi  $t9, $v0, 1
  bnez  $t9, .Ljp7F065430
   li    $t8, 20
  li    $t7, 17
  b     .Ljp7F065434
   sw    $t7, 0x24($s0)
.Ljp7F065430:
  sw    $t8, 0x24($s0)
.Ljp7F065434:
  sw    $zero, 0x20($s0)
  b     .Ljp7F065530
   sw    $zero, 0x1c($s0)
Weapon_function_grenades:
  lw    $t6, 0x18($s0)
  lui   $t8, %hi(pPlayer) # $t8, 0x8008
  bnezl $t6, .Ljp7F065464
   lw    $t7, 0x20($s0)
  lw    $t9, 0x20($s0)
  slti  $at, $t9, 0xf0
  bnezl $at, .Ljp7F065534
   sw    $zero, 0x398($s0)
  lw    $t7, 0x20($s0)
.Ljp7F065464:
  lw    $t8, %lo(pPlayer)($t8)
  li    $t6, 26
  sw    $t7, 0x105c($t8)
  sw    $t6, 0x24($s0)
  sw    $zero, 0x1c($s0)
  b     .Ljp7F065530
   sw    $zero, 0x20($s0)
Weapon_function_slapper:
  jal   get_random_value
   nop   
  andi  $t9, $v0, 1
  bnez  $t9, .Ljp7F0654A0
   li    $t8, 32
  li    $t7, 30
  b     .Ljp7F0654A4
   sw    $t7, 0x24($s0)
.Ljp7F0654A0:
  sw    $t8, 0x24($s0)
.Ljp7F0654A4:
  sw    $zero, 0x20($s0)
  b     .Ljp7F065530
   sw    $zero, 0x1c($s0)
Weapon_function_throwing_knife:
  li    $t6, 23
  sw    $t6, 0x24($s0)
  sw    $zero, 0x20($s0)
  b     .Ljp7F065530
   sw    $zero, 0x1c($s0)
Weapon_function_tazer:
  lw    $t9, 0x20($s0)
  lui   $a0, %hi(D_80035A90) # $a0, 0x8003
  addiu $a0, %lo(D_80035A90) # addiu $a0, $a0, 0x5ad0
  mtc1  $t9, $f6
  addiu $a2, $s0, 0x7c
  lw    $a3, 0x1e0($sp)
  cvt.s.w $f0, $f6
  mfc1  $a1, $f0
  jal   sub_GAME_7F05C6FC
   nop   
  beqz  $v0, .Ljp7F065500
   li    $t8, 2
  li    $t7, 1
  b     .Ljp7F065530
   sw    $t7, 0xbc($s0)
.Ljp7F065500:
  sw    $t8, 0x24($s0)
  sw    $zero, 0x20($s0)
  b     .Ljp7F065530
   sw    $zero, 0x1c($s0)
Weapon_function_key:
  li    $t6, 36
  sw    $t6, 0x24($s0)
  sw    $zero, 0x20($s0)
  b     .Ljp7F065530
   sw    $zero, 0x1c($s0)
Weapon_function_collectible:
  sw    $zero, 0x24($s0)
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
.Ljp7F065530:
  sw    $zero, 0x398($s0)
.Ljp7F065534:
  lw    $v0, 0x24($s0)
.Ljp7F065538:
  li    $at, 2
  bnel  $v0, $at, .Ljp7F065AF0
   lw    $t6, 0x24($s0)
  jal   get_ammo_type_for_weapon
   move  $a0, $s1
  beqz  $v0, .Ljp7F06555C
   addiu $t7, $s1, -2
  lw    $t9, 0x2c($s0)
  blez  $t9, .Ljp7F065A7C
.Ljp7F06555C:
   sltiu $at, $t7, 0x3b
  beqz  $at, Weapon_shooting_throwable
   sll   $t7, $t7, 2
  lui   $at, %hi(jpt_80054084)
  addu  $at, $at, $t7
  lw    $t7, %lo(jpt_80054084)($at)
  jr    $t7
   nop   
Weapon_shooting_watch_magnet:
  lw    $t8, 0x1c($s0)
  li    $t7, 3
  bnezl $t8, .Ljp7F0655BC
   sw    $t7, 0x24($s0)
  jal   get_controls_locked_flag
   nop   
  sltiu $a1, $v0, 1
  beqz  $a1, .Ljp7F0655B0
   lui   $t6, %hi(pPlayer) # $t6, 0x8008
  lw    $t6, %lo(pPlayer)($t6)
  lw    $a1, 0x29c4($t6)
  sltiu $t9, $a1, 1
  move  $a1, $t9
.Ljp7F0655B0:
  b     Weapon_shooting_throwable
   sb    $a1, 0xc($s0)
  sw    $t7, 0x24($s0)
.Ljp7F0655BC:
  sw    $zero, 0x20($s0)
  b     Weapon_shooting_throwable
   sw    $zero, 0x1c($s0)
Weapon_shooting_pistol:
  lw    $t8, 0x1c($s0)
  li    $t9, 3
  bnezl $t8, .Ljp7F06564C
   sw    $t9, 0x24($s0)
  jal   getPlayerCount
   nop   
  li    $at, 1
  beql  $v0, $at, .Ljp7F06560C
   li    $t7, 1
  jal   checkGamePaused
   nop   
  bnez  $v0, .Ljp7F065610
   lui   $t6, %hi(pPlayer) # $t6, 0x8008
  lw    $t6, %lo(pPlayer)($t6)
  lw    $t9, 0x29c4($t6)
  bnez  $t9, .Ljp7F065610
   li    $t7, 1
.Ljp7F06560C:
  sb    $t7, 0xd($s0)
.Ljp7F065610:
  jal   get_controls_locked_flag
   nop   
  sltiu $a1, $v0, 1
  beqz  $a1, .Ljp7F065634
   lui   $t8, %hi(pPlayer) # $t8, 0x8008
  lw    $t8, %lo(pPlayer)($t8)
  lw    $a1, 0x29c4($t8)
  sltiu $t6, $a1, 1
  move  $a1, $t6
.Ljp7F065634:
  sb    $a1, 0xc($s0)
  jal   sub_GAME_7F05E808
   lw    $a0, 0x1e0($sp)
  b     .Ljp7F065824
   lb    $t7, 0xc($s0)
  sw    $t9, 0x24($s0)
.Ljp7F06564C:
  sw    $zero, 0x20($s0)
  b     Weapon_shooting_throwable
   sw    $zero, 0x1c($s0)
Weapon_shooting_machinegun:
  lw    $t7, 0x1c($s0)
  beqz  $t7, .Ljp7F0656AC
   nop   
  lw    $t8, 0x10($s0)
  move  $a0, $s1
  bnez  $t8, .Ljp7F0656AC
   nop   
  jal   check_special_attributes
   li    $a1, 4
  beql  $v0, $zero, .Ljp7F065754
   li    $t9, 3
  jal   get_BONDdata_is_aiming
   nop   
  bnezl $v0, .Ljp7F065754
   li    $t9, 3
  lw    $t6, 0x398($s0)
  li    $at, 3
  div   $zero, $t6, $at
  mfhi  $t9
  beql  $t9, $zero, .Ljp7F065754
   li    $t9, 3
.Ljp7F0656AC:
  jal   get_automatic_firing_rate
   move  $a0, $s1
  lw    $t7, 0x1c($s0)
  div   $zero, $t7, $v0
  mfhi  $t8
  bnez  $v0, .Ljp7F0656CC
   nop   
  break 7
.Ljp7F0656CC:
  li    $at, -1
  bne   $v0, $at, .Ljp7F0656E4
   lui   $at, 0x8000
  bne   $t7, $at, .Ljp7F0656E4
   nop   
  break 6
.Ljp7F0656E4:
  bnezl $t8, .Ljp7F065824
   lb    $t7, 0xc($s0)
  jal   getPlayerCount
   nop   
  li    $at, 1
  beql  $v0, $at, .Ljp7F065720
   li    $t7, 1
  jal   checkGamePaused
   nop   
  bnez  $v0, .Ljp7F065724
   lui   $t6, %hi(pPlayer) # $t6, 0x8008
  lw    $t6, %lo(pPlayer)($t6)
  lw    $t9, 0x29c4($t6)
  bnez  $t9, .Ljp7F065724
   li    $t7, 1
.Ljp7F065720:
  sb    $t7, 0xd($s0)
.Ljp7F065724:
  jal   get_controls_locked_flag
   nop   
  sltiu $a1, $v0, 1
  beqz  $a1, .Ljp7F065748
   lui   $t8, %hi(pPlayer) # $t8, 0x8008
  lw    $t8, %lo(pPlayer)($t8)
  lw    $a1, 0x29c4($t8)
  sltiu $t6, $a1, 1
  move  $a1, $t6
.Ljp7F065748:
  b     Weapon_shooting_throwable
   sb    $a1, 0xc($s0)
  li    $t9, 3
.Ljp7F065754:
  sw    $t9, 0x24($s0)
  sw    $zero, 0x20($s0)
  b     Weapon_shooting_throwable
   sw    $zero, 0x1c($s0)
Weapon_shooting_noammo:
  lw    $t7, 0x1c($s0)
  beql  $t7, $zero, .Ljp7F065784
   sb    $zero, 0xc($s0)
  lw    $t8, 0x10($s0)
  li    $t9, 3
  beql  $t8, $zero, .Ljp7F065794
   sw    $t9, 0x24($s0)
  sb    $zero, 0xc($s0)
.Ljp7F065784:
  lb    $t6, 0xc($s0)
  b     Weapon_shooting_throwable
   sb    $t6, 0xd($s0)
  sw    $t9, 0x24($s0)
.Ljp7F065794:
  sw    $zero, 0x20($s0)
  b     Weapon_shooting_throwable
   sw    $zero, 0x1c($s0)
Weapon_shooting_tazer:
  lw    $t7, 0x1c($s0)
  lui   $a0, %hi(D_80035B68) # $a0, 0x8003
  addiu $a0, %lo(D_80035B68) # addiu $a0, $a0, 0x5ba8
  beqz  $t7, .Ljp7F0657C0
   li    $a1, 0
  lw    $t8, 0x10($s0)
  li    $t9, 3
  beqz  $t8, .Ljp7F065814
.Ljp7F0657C0:
   addiu $a2, $s0, 0x7c
  jal   sub_GAME_7F05C6FC
   lw    $a3, 0x1e0($sp)
  lw    $t7, 0x1c($s0)
  sb    $zero, 0xc($s0)
  lb    $t9, 0xc($s0)
  li    $t6, 1
  sw    $t6, 0xbc($s0)
  bnez  $t7, Weapon_shooting_throwable
   sb    $t9, 0xd($s0)
  jal   get_controls_locked_flag
   nop   
  sltiu $a1, $v0, 1
  beqz  $a1, .Ljp7F06580C
   lui   $t8, %hi(pPlayer) # $t8, 0x8008
  lw    $t8, %lo(pPlayer)($t8)
  lw    $a1, 0x29c4($t8)
  sltiu $t6, $a1, 1
  move  $a1, $t6
.Ljp7F06580C:
  b     Weapon_shooting_throwable
   sb    $a1, 0xc($s0)
.Ljp7F065814:
  sw    $t9, 0x24($s0)
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
Weapon_shooting_throwable:
  lb    $t7, 0xc($s0)
.Ljp7F065824:
  li    $at, 40
  beql  $t7, $zero, .Ljp7F0658A4
   lw    $t6, 0x24($s0)
  beql  $s1, $at, .Ljp7F06588C
   lw    $t6, 0x2c($s0)
  jal   get_cur_playernum
   nop   
  lui   $a1, (0x3DCCCCCD >> 16) # lui $a1, 0x3dcc
  ori   $a1, (0x3DCCCCCD & 0xFFFF) # ori $a1, $a1, 0xcccd
  jal   controller_7000C854
   move  $a0, $v0
  jal   cur_player_get_control_type
   nop   
  slti  $at, $v0, 4
  bnezl $at, .Ljp7F06588C
   lw    $t6, 0x2c($s0)
  jal   get_cur_playernum
   nop   
  jal   getPlayerCount
   sw    $v0, 0x4c($sp)
  lw    $t8, 0x4c($sp)
  lui   $a1, (0x3DCCCCCD >> 16) # lui $a1, 0x3dcc
  ori   $a1, (0x3DCCCCCD & 0xFFFF) # ori $a1, $a1, 0xcccd
  jal   controller_7000C854
   addu  $a0, $v0, $t8
  lw    $t6, 0x2c($s0)
.Ljp7F06588C:
  lw    $t7, 0x398($s0)
  addiu $t9, $t6, -1
  addiu $t8, $t7, 1
  sw    $t9, 0x2c($s0)
  sw    $t8, 0x398($s0)
  lw    $t6, 0x24($s0)
.Ljp7F0658A4:
  li    $at, 2
  move  $a0, $s1
  bnel  $t6, $at, .Ljp7F065AF0
   lw    $t6, 0x24($s0)
  jal   get_sound_trigger_rate
   sw    $zero, 0x1c4($sp)
  blez  $v0, .Ljp7F06591C
   lui   $t9, %hi(pPlayer) # $t9, 0x8008
  lw    $t7, 0x3c($sp)
  lw    $t9, %lo(pPlayer)($t9)
  lui   $v0, %hi(global_timer) # $v0, 0x8005
  negu  $t8, $t7
  addu  $t6, $t9, $t8
  lw    $t7, 0xdf8($t6)
  lw    $v0, %lo(global_timer)($v0)
  beq   $v0, $t7, .Ljp7F065930
   nop   
  lw    $t9, 0x1dc($s0)
  slt   $at, $t9, $v0
  beqz  $at, .Ljp7F065930
   nop   
  jal   get_sound_trigger_rate
   move  $a0, $s1
  lui   $t8, %hi(global_timer) # $t8, 0x8005
  lw    $t8, %lo(global_timer)($t8)
  li    $t7, 1
  addu  $t6, $v0, $t8
  sw    $t6, 0x1dc($s0)
  b     .Ljp7F065930
   sw    $t7, 0x1c4($sp)
.Ljp7F06591C:
  lb    $t9, 0xc($s0)
  li    $t8, 1
  beqz  $t9, .Ljp7F065930
   nop   
  sw    $t8, 0x1c4($sp)
.Ljp7F065930:
  jal   getPlayerCount
   nop   
  li    $at, 1
  beql  $v0, $at, .Ljp7F065968
   lw    $t9, 0x1c4($sp)
  jal   checkGamePaused
   nop   
  bnez  $v0, .Ljp7F065AEC
   lui   $t6, %hi(pPlayer) # $t6, 0x8008
  lw    $t6, %lo(pPlayer)($t6)
  lw    $t7, 0x29c4($t6)
  bnezl $t7, .Ljp7F065AF0
   lw    $t6, 0x24($s0)
  lw    $t9, 0x1c4($sp)
.Ljp7F065968:
  beql  $t9, $zero, .Ljp7F065A40
   li    $at, 23
  lw    $a0, 0x1d4($s0)
  beql  $a0, $zero, .Ljp7F065998
   lw    $a0, 0x1d8($s0)
  jal   sfxGetArg0Unk3F
   nop   
  beql  $v0, $zero, .Ljp7F065998
   lw    $a0, 0x1d8($s0)
  jal   sfxDeactivate
   lw    $a0, 0x1d4($s0)
  lw    $a0, 0x1d8($s0)
.Ljp7F065998:
  beqz  $a0, .Ljp7F0659B8
   nop   
  jal   sfxGetArg0Unk3F
   nop   
  beqz  $v0, .Ljp7F0659B8
   nop   
  jal   sfxDeactivate
   lw    $a0, 0x1d8($s0)
.Ljp7F0659B8:
  jal   sub_GAME_7F05E014
   move  $a0, $s1
  beql  $v0, $zero, .Ljp7F065A40
   li    $at, 23
  lw    $t8, 0x1d4($s0)
  bnezl $t8, .Ljp7F065A04
   lw    $t7, 0x1d8($s0)
  jal   sub_GAME_7F05E014
   move  $a0, $s1
  sll   $a1, $v0, 0x10
  sra   $t6, $a1, 0x10
  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  move  $a1, $t6
  jal   play_sfx_a1
   addiu $a2, $s0, 0x1d4
  b     .Ljp7F065A30
   nop   
  lw    $t7, 0x1d8($s0)
.Ljp7F065A04:
  bnez  $t7, .Ljp7F065A30
   nop   
  jal   sub_GAME_7F05E014
   move  $a0, $s1
  sll   $a1, $v0, 0x10
  sra   $t9, $a1, 0x10
  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  move  $a1, $t9
  jal   play_sfx_a1
   addiu $a2, $s0, 0x1d8
.Ljp7F065A30:
  lui   $t8, %hi(global_timer) # $t8, 0x8005
  lw    $t8, %lo(global_timer)($t8)
  sw    $t8, 0x1e0($s0)
  li    $at, 23
.Ljp7F065A40:
  bne   $s1, $at, .Ljp7F065AEC
   lui   $t6, %hi(D_80035E90) # $t6, 0x8003
  lw    $t6, %lo(D_80035E90)($t6)
  jal   get_random_value
   sw    $t6, 0x1c0($sp)
  andi  $t7, $v0, 1
  sll   $t9, $t7, 1
  addu  $a1, $sp, $t9
  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  lh    $a1, 0x1c0($a1)
  jal   play_sfx_a1
   move  $a2, $zero
  b     .Ljp7F065AF0
   lw    $t6, 0x24($s0)
.Ljp7F065A7C:
  lw    $t8, 0x1c($s0)
  li    $t6, 3
  li    $t7, 13
  blezl $t8, .Ljp7F065AA4
   sw    $t7, 0x24($s0)
  sw    $t6, 0x24($s0)
  sw    $zero, 0x20($s0)
  b     .Ljp7F065AEC
   sw    $zero, 0x1c($s0)
  sw    $t7, 0x24($s0)
.Ljp7F065AA4:
  sw    $zero, 0x20($s0)
  jal   getPlayerCount
   sw    $zero, 0x1c($s0)
  li    $at, 1
  beq   $v0, $at, .Ljp7F065AD8
   nop   
  jal   checkGamePaused
   nop   
  bnez  $v0, .Ljp7F065AEC
   lui   $t9, %hi(pPlayer) # $t9, 0x8008
  lw    $t9, %lo(pPlayer)($t9)
  lw    $t8, 0x29c4($t9)
  bnez  $t8, .Ljp7F065AEC
.Ljp7F065AD8:
   lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 89
  jal   play_sfx_a1
   move  $a2, $zero
.Ljp7F065AEC:
  lw    $t6, 0x24($s0)
.Ljp7F065AF0:
  li    $at, 3
  bne   $t6, $at, .Ljp7F065E4C
   li    $at, 31
  bne   $s1, $at, .Ljp7F065B4C
   nop   
  lw    $t7, 0x20($s0)
  lui   $a0, %hi(D_80035B68) # $a0, 0x8003
  addiu $a0, %lo(D_80035B68) # addiu $a0, $a0, 0x5ba8
  mtc1  $t7, $f8
  addiu $a2, $s0, 0x7c
  lw    $a3, 0x1e0($sp)
  cvt.s.w $f0, $f8
  mfc1  $a1, $f0
  jal   sub_GAME_7F05C6FC
   nop   
  beqz  $v0, .Ljp7F065B3C
   li    $t9, 1
  b     .Ljp7F065E4C
   sw    $t9, 0xbc($s0)
.Ljp7F065B3C:
  sw    $zero, 0x24($s0)
  sw    $zero, 0x20($s0)
  b     .Ljp7F065E4C
   sw    $zero, 0x1c($s0)
.Ljp7F065B4C:
  jal   get_ptr_item_statistics
   move  $a0, $s1
  lw    $a1, 0x18($s0)
  lb    $t2, 0x47($v0)
  lb    $a0, 0x23($v0)
  move  $t5, $v0
  lb    $a2, 0x44($v0)
  lb    $t3, 0x45($v0)
  lb    $t0, 0x46($v0)
  move  $t1, $t2
  beqz  $a1, .Ljp7F065B90
   move  $t4, $a0
  lw    $t8, 0x20($s0)
  addu  $t6, $a2, $t3
  slt   $at, $t8, $t6
  beql  $at, $zero, .Ljp7F065BB4
   sw    $zero, 0x24($s0)
.Ljp7F065B90:
  lw    $v1, 0x20($s0)
  bltz  $a0, .Ljp7F065BC0
   addu  $a3, $a2, $t3
  bnez  $a1, .Ljp7F065BC0
   addu  $t7, $a3, $t4
  slt   $at, $v1, $t7
  bnez  $at, .Ljp7F065BC0
   nop   
  sw    $zero, 0x24($s0)
.Ljp7F065BB4:
  sw    $zero, 0x20($s0)
  b     .Ljp7F065E4C
   sw    $zero, 0x1c($s0)
.Ljp7F065BC0:
  beql  $a1, $zero, .Ljp7F065C14
   slt   $at, $v1, $a3
  lw    $t9, 0x10($s0)
  slt   $at, $v1, $t0
  beql  $t9, $zero, .Ljp7F065C14
   slt   $at, $v1, $a3
  bnezl $at, .Ljp7F065C14
   slt   $at, $v1, $a3
  bltz  $t2, .Ljp7F065C10
   addu  $a0, $v1, $t1
  slt   $at, $a0, $a3
  beqz  $at, .Ljp7F065C10
   slt   $at, $a0, $t0
  bnez  $at, .Ljp7F065C10
   li    $t8, 4
  sw    $t8, 0x24($s0)
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
  b     .Ljp7F065E4C
   sw    $t1, 0x38($s0)
.Ljp7F065C10:
  slt   $at, $v1, $a3
.Ljp7F065C14:
  beqz  $at, .Ljp7F065E4C
   addiu $t6, $s0, 0x7c
  lwc1  $f2, 0x48($v0)
  lwc1  $f0, 0x4c($v0)
  bnez  $v1, .Ljp7F065C50
   sw    $t6, 0x34($sp)
  lwc1  $f10, 0x78($s0)
  lwc1  $f4, 0x6c($s0)
  lwc1  $f6, 0x70($s0)
  lwc1  $f8, 0x74($s0)
  lw    $v1, 0x20($s0)
  swc1  $f10, 0x58($s0)
  swc1  $f4, 0x4c($s0)
  swc1  $f6, 0x50($s0)
  swc1  $f8, 0x54($s0)
.Ljp7F065C50:
  slt   $at, $v1, $a2
  beqz  $at, .Ljp7F065D04
   lui   $at, %hi(D_80054170) # $at, 0x8005
  lwc1  $f12, %lo(D_80054170)($at)
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f4
  mul.s $f10, $f0, $f12
  div.s $f6, $f10, $f4
  sub.s $f8, $f12, $f6
  swc1  $f8, 0x68($s0)
  swc1  $f2, 0x19c($sp)
  sw    $t5, 0x1b8($sp)
  sw    $a2, 0x1b4($sp)
  jal   sub_GAME_7F05DCE8
   lw    $a0, 0x1e0($sp)
  lwc1  $f10, 0x1c8($s0)
  lwc1  $f2, 0x19c($sp)
  li    $at, 0x447A0000 # 1000.000000
  sub.s $f4, $f0, $f10
  mtc1  $at, $f14
  lw    $t5, 0x1b8($sp)
  mtc1  $zero, $f10
  mul.s $f6, $f4, $f2
  lw    $a2, 0x1b4($sp)
  swc1  $f10, 0x60($s0)
  lw    $t7, 0x20($s0)
  lui   $at, %hi(D_80054174) # $at, 0x8005
  div.s $f8, $f6, $f14
  lwc1  $f6, 0x1d0($s0)
  swc1  $f8, 0x5c($s0)
  lwc1  $f4, 0xc($t5)
  sub.s $f8, $f4, $f6
  mtc1  $t7, $f6
  mul.s $f10, $f8, $f2
  cvt.s.w $f8, $f6
  mtc1  $a2, $f6
  div.s $f4, $f10, $f14
  swc1  $f4, 0x64($s0)
  lwc1  $f10, %lo(D_80054174)($at)
  mul.s $f4, $f8, $f10
  cvt.s.w $f8, $f6
  jal   sinf
   div.s $f12, $f4, $f8
  b     .Ljp7F065DC8
   mov.s $f2, $f0
.Ljp7F065D04:
  lui   $at, %hi(D_80054178) # $at, 0x8005
  lwc1  $f12, %lo(D_80054178)($at)
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f6
  mul.s $f10, $f0, $f12
  div.s $f4, $f10, $f6
  sub.s $f8, $f12, $f4
  swc1  $f8, 0x68($s0)
  swc1  $f2, 0x19c($sp)
  sw    $t5, 0x1b8($sp)
  sw    $t3, 0x1b0($sp)
  sw    $a2, 0x1b4($sp)
  jal   sub_GAME_7F05DCE8
   lw    $a0, 0x1e0($sp)
  lwc1  $f10, 0x1c8($s0)
  lwc1  $f2, 0x19c($sp)
  li    $at, 0x447A0000 # 1000.000000
  sub.s $f6, $f0, $f10
  mtc1  $at, $f14
  lw    $t5, 0x1b8($sp)
  mtc1  $zero, $f10
  mul.s $f4, $f6, $f2
  lw    $a2, 0x1b4($sp)
  lw    $t3, 0x1b0($sp)
  swc1  $f10, 0x60($s0)
  lw    $t9, 0x20($s0)
  lui    $at, %hi(D_8005417C)
  div.s $f8, $f4, $f14
  lwc1  $f4, 0x1d0($s0)
  subu  $t8, $t9, $a2
  swc1  $f8, 0x5c($s0)
  lwc1  $f6, 0xc($t5)
  sub.s $f8, $f6, $f4
  mtc1  $t8, $f4
  mul.s $f10, $f8, $f2
  cvt.s.w $f8, $f4
  mtc1  $t3, $f4
  div.s $f6, $f10, $f14
  swc1  $f6, 0x64($s0)
  lwc1  $f10, %lo(D_8005417C)($at)
  mul.s $f6, $f8, $f10
  cvt.s.w $f8, $f4
  jal   cosf
   div.s $f12, $f6, $f8
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f10
  mtc1  $at, $f6
  mul.s $f4, $f0, $f10
  add.s $f2, $f4, $f6
.Ljp7F065DC8:
  lwc1  $f12, 0x58($s0)
  lwc1  $f14, 0x68($s0)
  mfc1  $a2, $f2
  jal   sub_GAME_7F06D0CC
   swc1  $f2, 0x194($sp)
  lwc1  $f14, 0x4c($s0)
  lwc1  $f8, 0x5c($s0)
  lwc1  $f2, 0x194($sp)
  lwc1  $f16, 0x50($s0)
  sub.s $f10, $f8, $f14
  lwc1  $f8, 0x60($s0)
  lwc1  $f18, 0x54($s0)
  li    $t6, 1
  mul.s $f4, $f10, $f2
  sub.s $f10, $f8, $f16
  lwc1  $f8, 0x64($s0)
  swc1  $f0, 0x78($s0)
  sw    $t6, 0xbc($s0)
  mov.s $f12, $f0
  add.s $f6, $f4, $f14
  mul.s $f4, $f10, $f2
  sub.s $f10, $f8, $f18
  swc1  $f6, 0x6c($s0)
  add.s $f6, $f4, $f16
  mul.s $f4, $f10, $f2
  swc1  $f6, 0x70($s0)
  add.s $f6, $f4, $f18
  swc1  $f6, 0x74($s0)
  jal   sub_GAME_7F058570
   lw    $a1, 0x34($sp)
  addiu $a0, $s0, 0x6c
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   lw    $a1, 0x34($sp)
.Ljp7F065E4C:
  lw    $v0, 0x24($s0)
  li    $at, 4
  bnel  $v0, $at, .Ljp7F065FA4
   li    $at, 13
  lw    $v1, 0x20($s0)
  bnezl $v1, .Ljp7F065EB0
   lw    $v0, 0x38($s0)
  lwc1  $f8, 0x78($s0)
  lwc1  $f10, 0x6c($s0)
  lwc1  $f4, 0x70($s0)
  lwc1  $f6, 0x74($s0)
  swc1  $f8, 0x58($s0)
  swc1  $f10, 0x4c($s0)
  swc1  $f4, 0x50($s0)
  swc1  $f6, 0x54($s0)
  mtc1  $zero, $f8
  mtc1  $zero, $f10
  mtc1  $zero, $f4
  mtc1  $zero, $f6
  lw    $v1, 0x20($s0)
  swc1  $f8, 0x68($s0)
  swc1  $f10, 0x5c($s0)
  swc1  $f4, 0x60($s0)
  swc1  $f6, 0x64($s0)
  lw    $v0, 0x38($s0)
.Ljp7F065EB0:
  slt   $at, $v1, $v0
  beqz  $at, .Ljp7F065F90
   subu  $t7, $v0, $v1
  mtc1  $t7, $f8
  lui   $at, %hi(D_80054180) # $at, 0x8005
  lwc1  $f4, %lo(D_80054180)($at)
  cvt.s.w $f10, $f8
  mtc1  $v0, $f8
  addiu $t9, $s0, 0x7c
  addiu $t8, $s0, 0x6c
  sw    $t8, 0x38($sp)
  sw    $t9, 0x34($sp)
  mul.s $f6, $f10, $f4
  cvt.s.w $f10, $f8
  jal   cosf
   div.s $f12, $f6, $f10
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f16
  nop   
  mul.s $f4, $f0, $f16
  add.s $f2, $f4, $f16
  swc1  $f2, 0x190($sp)
  mfc1  $a2, $f2
  lwc1  $f14, 0x68($s0)
  jal   sub_GAME_7F06D0CC
   lwc1  $f12, 0x58($s0)
  lwc1  $f14, 0x4c($s0)
  lwc1  $f8, 0x5c($s0)
  lwc1  $f2, 0x190($sp)
  lwc1  $f16, 0x50($s0)
  sub.s $f6, $f8, $f14
  lwc1  $f8, 0x60($s0)
  lwc1  $f18, 0x54($s0)
  li    $t6, 1
  mul.s $f10, $f6, $f2
  sub.s $f6, $f8, $f16
  lwc1  $f8, 0x64($s0)
  swc1  $f0, 0x78($s0)
  sw    $t6, 0xbc($s0)
  mov.s $f12, $f0
  add.s $f4, $f10, $f14
  mul.s $f10, $f6, $f2
  sub.s $f6, $f8, $f18
  swc1  $f4, 0x6c($s0)
  add.s $f4, $f10, $f16
  mul.s $f10, $f6, $f2
  swc1  $f4, 0x70($s0)
  add.s $f4, $f10, $f18
  swc1  $f4, 0x74($s0)
  jal   sub_GAME_7F058570
   lw    $a1, 0x34($sp)
  lw    $a0, 0x38($sp)
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   lw    $a1, 0x34($sp)
  b     .Ljp7F065FA0
   lw    $v0, 0x24($s0)
.Ljp7F065F90:
  sw    $zero, 0x24($s0)
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
  move  $v0, $zero
.Ljp7F065FA0:
  li    $at, 13
.Ljp7F065FA4:
  bnel  $v0, $at, .Ljp7F065FF4
   lw    $v0, 0x24($s0)
  lw    $t7, 0x1c($s0)
  bnezl $t7, .Ljp7F065FC4
   lw    $a1, 0x18($s0)
  jal   sub_GAME_7F05E808
   lw    $a0, 0x1e0($sp)
  lw    $a1, 0x18($s0)
.Ljp7F065FC4:
  bnezl $a1, .Ljp7F065FE8
   sw    $zero, 0x24($s0)
  bnezl $a1, .Ljp7F065FF4
   lw    $v0, 0x24($s0)
  lw    $t9, 0x20($s0)
  slti  $at, $t9, 0x14
  bnezl $at, .Ljp7F065FF4
   lw    $v0, 0x24($s0)
  sw    $zero, 0x24($s0)
.Ljp7F065FE8:
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
  lw    $v0, 0x24($s0)
.Ljp7F065FF4:
  li    $a1, 5
  li    $a0, 16
  bnel  $a1, $v0, .Ljp7F066178
   li    $a2, 6
  jal   getPlayerCount
   sw    $a0, 0x18c($sp)
  slti  $at, $v0, 2
  bnez  $at, .Ljp7F06601C
   lw    $a0, 0x18c($sp)
  li    $a0, 12
.Ljp7F06601C:
  lw    $t8, 0x1c($s0)
  bnezl $t8, .Ljp7F066054
   lw    $v1, 0x20($s0)
  jal   getPlayerCount
   sw    $a0, 0x18c($sp)
  li    $at, 1
  bne   $v0, $at, .Ljp7F066048
   lw    $a0, 0x18c($sp)
  li    $t6, 17
  b     .Ljp7F066050
   sw    $t6, 0x40($s0)
.Ljp7F066048:
  li    $t7, 13
  sw    $t7, 0x40($s0)
.Ljp7F066050:
  lw    $v1, 0x20($s0)
.Ljp7F066054:
  slt   $at, $v1, $a0
  bnezl $at, .Ljp7F0660F4
   mtc1  $v1, $f8
  jal   get_ammo_type_for_weapon
   move  $a0, $s1
  lui   $t9, %hi(pPlayer) # $t9, 0x8008
  lw    $t9, %lo(pPlayer)($t9)
  sll   $t8, $v0, 2
  lw    $t7, 0x2c($s0)
  addu  $v1, $t9, $t8
  lw    $t6, 0x1130($v1)
  addu  $t9, $t6, $t7
  sw    $t9, 0x1130($v1)
  jal   getPlayerCount
   sw    $zero, 0x2c($s0)
  slti  $at, $v0, 2
  bnez  $at, .Ljp7F0660A4
   nop   
  jal   sub_GAME_7F09B368
   lw    $a0, 0x1e0($sp)
.Ljp7F0660A4:
  jal   sub_GAME_7F05FB00
   lw    $a0, 0x1e0($sp)
  li    $t8, 6
  sw    $t8, 0x24($s0)
  jal   check_if_item_available
   li    $a0, 17
  beqz  $v0, .Ljp7F0660D8
   li    $a1, 5
  lui   $t7, %hi(pPlayer) # $t7, 0x8008
  lw    $t7, %lo(pPlayer)($t7)
  li    $t6, 17
  b     .Ljp7F0660E8
   sw    $t6, 0x2a38($t7)
.Ljp7F0660D8:
  lui   $t8, %hi(pPlayer) # $t8, 0x8008
  lw    $t8, %lo(pPlayer)($t8)
  li    $t9, 1
  sw    $t9, 0x2a38($t8)
.Ljp7F0660E8:
  b     .Ljp7F066174
   lw    $v0, 0x24($s0)
  mtc1  $v1, $f8
.Ljp7F0660F4:
  lui   $at, %hi(D_80054184) # $at, 0x8005
  lwc1  $f10, %lo(D_80054184)($at)
  cvt.s.w $f6, $f8
  mtc1  $a0, $f8
  li    $t6, 1
  sw    $t6, 0xbc($s0)
  addiu $a1, $s0, 0x7c
  mul.s $f4, $f6, $f10
  cvt.s.w $f6, $f8
  div.s $f12, $f4, $f6
  jal   sub_GAME_7F058570
   swc1  $f12, 0x188($sp)
  mtc1  $zero, $f10
  nop   
  swc1  $f10, 0xac($s0)
  jal   cosf
   lwc1  $f12, 0x188($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  li    $at, 0xC2700000 # -60.000000
  mtc1  $at, $f6
  sub.s $f4, $f8, $f0
  mul.s $f10, $f4, $f6
  swc1  $f10, 0xb0($s0)
  jal   sinf
   lwc1  $f12, 0x188($sp)
  li    $at, 0x41700000 # 15.000000
  mtc1  $at, $f8
  lw    $v0, 0x24($s0)
  li    $a1, 5
  mul.s $f4, $f0, $f8
  swc1  $f4, 0xb4($s0)
.Ljp7F066174:
  li    $a2, 6
.Ljp7F066178:
  beq   $a2, $v0, .Ljp7F066188
   li    $at, 7
  bnel  $v0, $at, .Ljp7F06631C
   li    $at, 8
.Ljp7F066188:
  lw    $t7, 0x44($s0)
  beqz  $t7, .Ljp7F0661A8
   nop   
  lw    $t9, 0x20($s0)
  lw    $t8, 0x40($s0)
  slt   $at, $t9, $t8
  bnezl $at, .Ljp7F06629C
   lw    $v0, 0x24($s0)
.Ljp7F0661A8:
  bne   $a2, $v0, .Ljp7F06627C
   lui   $t6, %hi(pPlayer) # $t6, 0x8008
  lw    $t6, %lo(pPlayer)($t6)
  lw    $t7, 0x3c($sp)
  subu  $v1, $t6, $t7
  lw    $v0, 0xc3c($v1)
  addiu $v1, $v1, 0xc18
  beql  $a2, $v0, .Ljp7F06625C
   lw    $a0, 0x1e0($sp)
  beql  $a1, $v0, .Ljp7F06625C
   lw    $a0, 0x1e0($sp)
  lw    $a0, 0x28($v1)
  li    $at, 14
  beql  $a1, $a0, .Ljp7F06625C
   lw    $a0, 0x1e0($sp)
  beq   $v0, $at, .Ljp7F066258
   li    $at, 15
  beq   $v0, $at, .Ljp7F066258
   li    $at, 16
  beq   $v0, $at, .Ljp7F066258
   li    $at, 14
  beq   $a0, $at, .Ljp7F066258
   lw    $t9, 0x1e0($sp)
  bnez  $t9, .Ljp7F066238
   nop   
  jal   get_item_in_hand
   li    $a0, 1
  lw    $a0, 0x3c($s0)
  jal   check_if_item_for_hand_available
   move  $a1, $v0
  bnez  $v0, .Ljp7F066258
   li    $a0, 1
  jal   draw_item_in_hand_has_more_ammo
   move  $a1, $zero
  b     .Ljp7F06625C
   lw    $a0, 0x1e0($sp)
.Ljp7F066238:
  jal   get_item_in_hand
   move  $a0, $zero
  move  $a0, $v0
  jal   check_if_item_for_hand_available
   lw    $a1, 0x3c($s0)
  bnezl $v0, .Ljp7F06625C
   lw    $a0, 0x1e0($sp)
  sw    $zero, 0x3c($s0)
.Ljp7F066258:
  lw    $a0, 0x1e0($sp)
.Ljp7F06625C:
  jal   remove_hands_item
   lw    $a1, 0x3c($s0)
  jal   return_ammo_in_hand
   lw    $a0, 0x1e0($sp)
  li    $t8, 7
  move  $s1, $v0
  b     .Ljp7F066298
   sw    $t8, 0x24($s0)
.Ljp7F06627C:
  jal   sub_GAME_7F05CEBC
   lw    $a0, 0x1e0($sp)
  beqz  $v0, .Ljp7F066298
   li    $t6, 8
  sw    $t6, 0x24($s0)
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
.Ljp7F066298:
  lw    $v0, 0x24($s0)
.Ljp7F06629C:
  li    $a2, 6
  li    $at, 7
  beq   $a2, $v0, .Ljp7F0662B4
   li    $t7, 1
  bnel  $v0, $at, .Ljp7F06631C
   li    $at, 8
.Ljp7F0662B4:
  sw    $t7, 0xbc($s0)
  lui   $at, %hi(D_80054188) # $at, 0x8005
  lwc1  $f12, %lo(D_80054188)($at)
  jal   sub_GAME_7F058570
   addiu $a1, $s0, 0x7c
  mtc1  $zero, $f6
  lui   $at, %hi(D_8005418C) # $at, 0x8005
  swc1  $f6, 0xac($s0)
  jal   cosf
   lwc1  $f12, %lo(D_8005418C)($at)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  li    $at, 0xC2700000 # -60.000000
  mtc1  $at, $f4
  sub.s $f8, $f10, $f0
  lui   $at, %hi(D_80054190) # $at, 0x8005
  mul.s $f6, $f8, $f4
  swc1  $f6, 0xb0($s0)
  jal   sinf
   lwc1  $f12, %lo(D_80054190)($at)
  li    $at, 0x41700000 # 15.000000
  mtc1  $at, $f10
  lw    $v0, 0x24($s0)
  mul.s $f8, $f0, $f10
  swc1  $f8, 0xb4($s0)
  li    $at, 8
.Ljp7F06631C:
  bne   $v0, $at, .Ljp7F066554
   li    $t9, 23
  jal   getPlayerCount
   sw    $t9, 0x17c($sp)
  slti  $at, $v0, 2
  bnez  $at, .Ljp7F06633C
   li    $t8, 12
  sw    $t8, 0x17c($sp)
.Ljp7F06633C:
  lw    $t6, 0x1c($s0)
  bnezl $t6, .Ljp7F066478
   lw    $t7, 0x20($s0)
  jal   getPlayerCount
   nop   
  slti  $at, $v0, 2
  bnez  $at, .Ljp7F066364
   nop   
  jal   sub_GAME_7F09B398
   lw    $a0, 0x1e0($sp)
.Ljp7F066364:
  jal   sub_GAME_7F0649D8
   lw    $a0, 0x1e0($sp)
  lui   $t7, %hi(pPlayer) # $t7, 0x8008
  lw    $t7, %lo(pPlayer)($t7)
  lui   $t9, %hi(clock_timer) # $t9, 0x8005
  lui   $t8, %hi(pPlayer) # $t8, 0x8008
  sw    $zero, 0xfc8($t7)
  lw    $t9, %lo(clock_timer)($t9)
  blezl $t9, .Ljp7F066478
   lw    $t7, 0x20($s0)
  lw    $t8, %lo(pPlayer)($t8)
  li    $at, 1
  lw    $t6, ($t8)
  beql  $t6, $at, .Ljp7F066478
   lw    $t7, 0x20($s0)
  jal   sub_GAME_7F05CEBC
   lw    $a0, 0x1e0($sp)
  beqz  $v0, weapon_switchstyle_NONE
   lui   $t7, %hi(disable_player_pickups_flag) # $t7, 0x8003
  lw    $t7, %lo(disable_player_pickups_flag)($t7)
  lui   $t9, %hi(pPlayer) # $t9, 0x8008
  bnezl $t7, .Ljp7F066478
   lw    $t7, 0x20($s0)
  lw    $t9, %lo(pPlayer)($t9)
  slti  $at, $s1, 0x3e
  lw    $t8, 0xd8($t9)
  bnezl $t8, .Ljp7F066478
   lw    $t7, 0x20($s0)
  bnez  $at, .Ljp7F0663EC
   li    $at, 88
  beql  $s1, $at, .Ljp7F066478
   lw    $t7, 0x20($s0)
  b     weapon_playsfx_gun
   nop   
.Ljp7F0663EC:
  sltiu $at, $s1, 0x3e
  beqz  $at, weapon_playsfx_gun
   sll   $t6, $s1, 2
  lui   $at, %hi(jpt_80054194)
  addu  $at, $at, $t6
  lw    $t6, %lo(jpt_80054194)($at)
  jr    $t6
   nop   
weapon_playsfx_F2:
  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 242
  jal   play_sfx_a1
   move  $a2, $zero
  b     .Ljp7F066478
   lw    $t7, 0x20($s0)
weapon_playsfx_knife:
  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 233
  jal   play_sfx_a1
   move  $a2, $zero
  b     .Ljp7F066478
   lw    $t7, 0x20($s0)
weapon_playsfx_mine:
  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 235
  jal   play_sfx_a1
   move  $a2, $zero
  b     .Ljp7F066478
   lw    $t7, 0x20($s0)
weapon_playsfx_gun:
  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 232
  jal   play_sfx_a1
   move  $a2, $zero
weapon_switchstyle_NONE:
  lw    $t7, 0x20($s0)
.Ljp7F066478:
  lw    $t9, 0x17c($sp)
  slt   $at, $t7, $t9
  beql  $at, $zero, .Ljp7F0664BC
   sw    $zero, 0x24($s0)
  jal   get_ptr_weapon_model_header_line
   move  $a0, $s1
  beqz  $v0, .Ljp7F0664B8
   move  $a0, $s1
  jal   check_special_attributes
   li    $a1, 2048
  beqz  $v0, .Ljp7F0664B8
   move  $a0, $s1
  jal   check_special_attributes
   li    $a1, 8192
  beqz  $v0, .Ljp7F0664CC
   lw    $t8, 0x17c($sp)
.Ljp7F0664B8:
  sw    $zero, 0x24($s0)
.Ljp7F0664BC:
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
  b     .Ljp7F066554
   move  $v0, $zero
.Ljp7F0664CC:
  lw    $t6, 0x20($s0)
  lui   $at, %hi(D_8005428C) # $at, 0x8005
  lwc1  $f10, %lo(D_8005428C)($at)
  subu  $t7, $t8, $t6
  mtc1  $t7, $f4
  li    $t9, 1
  sw    $t9, 0xbc($s0)
  cvt.s.w $f6, $f4
  mtc1  $t8, $f4
  addiu $a1, $s0, 0x7c
  mul.s $f8, $f6, $f10
  cvt.s.w $f6, $f4
  div.s $f12, $f8, $f6
  jal   sub_GAME_7F058570
   swc1  $f12, 0x178($sp)
  mtc1  $zero, $f10
  nop   
  swc1  $f10, 0xac($s0)
  jal   cosf
   lwc1  $f12, 0x178($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  li    $at, 0xC2700000 # -60.000000
  mtc1  $at, $f6
  sub.s $f8, $f4, $f0
  mul.s $f10, $f8, $f6
  swc1  $f10, 0xb0($s0)
  jal   sinf
   lwc1  $f12, 0x178($sp)
  li    $at, 0x41700000 # 15.000000
  mtc1  $at, $f4
  lw    $v0, 0x24($s0)
  mul.s $f8, $f0, $f4
  swc1  $f8, 0xb4($s0)
.Ljp7F066554:
  li    $at, 9
  bnel  $v0, $at, .Ljp7F0665BC
   li    $at, 10
  jal   get_ptr_item_statistics
   move  $a0, $s1
  lw    $t6, 0x2c($s0)
  lh    $t7, 0x20($v0)
  move  $a0, $s1
  slt   $at, $t6, $t7
  bnez  $at, .Ljp7F066590
   nop   
  jal   check_special_attributes
   lui   $a1, 0x20
  beql  $v0, $zero, .Ljp7F0665AC
   sw    $zero, 0x24($s0)
.Ljp7F066590:
  jal   get_ammo_in_hands_weapon
   lw    $a0, 0x1e0($sp)
  blez  $v0, .Ljp7F0665A8
   li    $v0, 10
  b     .Ljp7F0665B8
   sw    $v0, 0x24($s0)
.Ljp7F0665A8:
  sw    $zero, 0x24($s0)
.Ljp7F0665AC:
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
  move  $v0, $zero
.Ljp7F0665B8:
  li    $at, 10
.Ljp7F0665BC:
  bnel  $v0, $at, .Ljp7F0666E0
   li    $at, 11
  lw    $v1, 0x20($s0)
  li    $v0, 11
  li    $t7, 17
  slti  $at, $v1, 0x10
  beql  $at, $zero, .Ljp7F0665EC
   sw    $v0, 0x24($s0)
  lb    $t9, 0xf($s0)
  bnezl $t9, .Ljp7F066600
   mtc1  $v1, $f6
  sw    $v0, 0x24($s0)
.Ljp7F0665EC:
  sw    $t7, 0x40($s0)
  sw    $zero, 0x20($s0)
  b     .Ljp7F0666DC
   sw    $zero, 0x1c($s0)
  mtc1  $v1, $f6
.Ljp7F066600:
  li    $at, 0x41800000 # 16.000000
  mtc1  $at, $f2
  cvt.s.w $f10, $f6
  lui   $at, %hi(D_80054290) # $at, 0x8005
  lwc1  $f4, %lo(D_80054290)($at)
  li    $t8, 1
  addiu $a1, $s0, 0x7c
  mul.s $f8, $f10, $f4
  div.s $f6, $f8, $f2
  swc1  $f6, 0x12c($sp)
  sw    $t8, 0xbc($s0)
  lw    $t9, 0x1e0($sp)
  bnezl $t9, .Ljp7F066658
   mtc1  $zero, $f4
  mtc1  $zero, $f10
  sw    $a1, 0x34($sp)
  div.s $f12, $f10, $f2
  jal   sub_GAME_7F058688
   swc1  $f12, 0x40($sp)
  b     .Ljp7F066670
   lwc1  $f12, 0x12c($sp)
  mtc1  $zero, $f4
.Ljp7F066658:
  sw    $a1, 0x34($sp)
  div.s $f0, $f4, $f2
  neg.s $f12, $f0
  jal   sub_GAME_7F058688
   swc1  $f0, 0x40($sp)
  lwc1  $f12, 0x12c($sp)
.Ljp7F066670:
  jal   sub_GAME_7F058570
   addiu $a1, $sp, 0x130
  addiu $a0, $sp, 0x130
  jal   matrix_4x4_multiply_in_place
   lw    $a1, 0x34($sp)
  jal   sinf
   lwc1  $f12, 0x40($sp)
  mtc1  $zero, $f8
  move  $a0, $s1
  jal   sub_GAME_7F0649AC
   swc1  $f8, 0xac($s0)
  swc1  $f0, 0x44($sp)
  jal   cosf
   lwc1  $f12, 0x12c($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  lwc1  $f4, 0x44($sp)
  sub.s $f10, $f6, $f0
  mul.s $f8, $f10, $f4
  swc1  $f8, 0xb0($s0)
  jal   sinf
   lwc1  $f12, 0x12c($sp)
  li    $at, 0x41700000 # 15.000000
  mtc1  $at, $f6
  lw    $v0, 0x24($s0)
  mul.s $f10, $f0, $f6
  swc1  $f10, 0xb4($s0)
.Ljp7F0666DC:
  li    $at, 11
.Ljp7F0666E0:
  bnel  $v0, $at, .Ljp7F066890
   li    $at, 12
  lw    $t6, 0x1c($s0)
  lui   $t7, %hi(clock_timer) # $t7, 0x8005
  bnezl $t6, .Ljp7F0667A0
   lw    $t6, 0x20($s0)
  lw    $t7, %lo(clock_timer)($t7)
  lui   $t8, %hi(pPlayer) # $t8, 0x8008
  blezl $t7, .Ljp7F0667A0
   lw    $t6, 0x20($s0)
  lw    $t8, %lo(pPlayer)($t8)
  li    $at, 1
  lw    $t9, ($t8)
  beql  $t9, $at, .Ljp7F0667A0
   lw    $t6, 0x20($s0)
  jal   sub_GAME_7F05CEBC
   lw    $a0, 0x1e0($sp)
  beqz  $v0, weapon_reload_none_sfx
   lui   $t6, %hi(disable_player_pickups_flag) # $t6, 0x8003
  lw    $t6, %lo(disable_player_pickups_flag)($t6)
  lui   $t7, %hi(pPlayer) # $t7, 0x8008
  bnezl $t6, .Ljp7F0667A0
   lw    $t6, 0x20($s0)
  lw    $t7, %lo(pPlayer)($t7)
  slti  $at, $s1, 0x3e
  lw    $t8, 0xd8($t7)
  bnezl $t8, .Ljp7F0667A0
   lw    $t6, 0x20($s0)
  bnez  $at, .Ljp7F066768
   li    $at, 88
  beql  $s1, $at, .Ljp7F0667A0
   lw    $t6, 0x20($s0)
  b     weapon_reload_gun_sfx
   nop   
.Ljp7F066768:
  sltiu $at, $s1, 0x3e
  beqz  $at, weapon_reload_gun_sfx
   sll   $t9, $s1, 2
  lui   $at, %hi(jpt_80054294)
  addu  $at, $at, $t9
  lw    $t9, %lo(jpt_80054294)($at)
  jr    $t9
   nop   
weapon_reload_gun_sfx:
  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 50
  jal   play_sfx_a1
   move  $a2, $zero
weapon_reload_none_sfx:
  lw    $t6, 0x20($s0)
.Ljp7F0667A0:
  lw    $t7, 0x40($s0)
  slt   $at, $t6, $t7
  bnez  $at, .Ljp7F0667D4
   li    $t6, 1
  lw    $t8, 0x1c($s0)
  li    $v0, 12
  slti  $at, $t8, 2
  bnezl $at, .Ljp7F0667D8
   sw    $t6, 0xbc($s0)
  sw    $v0, 0x24($s0)
  sw    $zero, 0x20($s0)
  b     .Ljp7F06688C
   sw    $zero, 0x1c($s0)
.Ljp7F0667D4:
  sw    $t6, 0xbc($s0)
.Ljp7F0667D8:
  lw    $t7, 0x1e0($sp)
  addiu $a1, $s0, 0x7c
  bnezl $t7, .Ljp7F066800
   mtc1  $zero, $f12
  mtc1  $zero, $f12
  jal   sub_GAME_7F058688
   sw    $a1, 0x34($sp)
  b     .Ljp7F06680C
   nop   
  mtc1  $zero, $f12
.Ljp7F066800:
  sw    $a1, 0x34($sp)
  jal   sub_GAME_7F058688
   neg.s $f12, $f12
.Ljp7F06680C:
  lui   $at, %hi(D_8005438C) # $at, 0x8005
  lwc1  $f12, %lo(D_8005438C)($at)
  jal   sub_GAME_7F058570
   addiu $a1, $sp, 0xe8
  addiu $a0, $sp, 0xe8
  jal   matrix_4x4_multiply_in_place
   lw    $a1, 0x34($sp)
  mtc1  $zero, $f12
  jal   sinf
   nop   
  mtc1  $zero, $f4
  move  $a0, $s1
  jal   sub_GAME_7F0649AC
   swc1  $f4, 0xac($s0)
  lui   $at, %hi(D_80054390) # $at, 0x8005
  lwc1  $f12, %lo(D_80054390)($at)
  jal   cosf
   swc1  $f0, 0x44($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  lwc1  $f10, 0x44($sp)
  lui   $at, %hi(D_80054394) # $at, 0x8005
  sub.s $f6, $f8, $f0
  mul.s $f4, $f6, $f10
  swc1  $f4, 0xb0($s0)
  jal   sinf
   lwc1  $f12, %lo(D_80054394)($at)
  li    $at, 0x41700000 # 15.000000
  mtc1  $at, $f8
  lw    $v0, 0x24($s0)
  mul.s $f6, $f0, $f8
  swc1  $f6, 0xb4($s0)
.Ljp7F06688C:
  li    $at, 12
.Ljp7F066890:
  bnel  $v0, $at, .Ljp7F0669FC
   li    $at, 14
  lw    $t8, 0x1c($s0)
  bnezl $t8, .Ljp7F0668BC
   lw    $t6, 0x20($s0)
  jal   sub_GAME_7F0649D8
   lw    $a0, 0x1e0($sp)
  lui   $t9, %hi(pPlayer) # $t9, 0x8008
  lw    $t9, %lo(pPlayer)($t9)
  sw    $zero, 0xfc8($t9)
  lw    $t6, 0x20($s0)
.Ljp7F0668BC:
  slti  $at, $t6, 0x17
  beql  $at, $zero, .Ljp7F0668FC
   sw    $zero, 0x24($s0)
  jal   get_ptr_weapon_model_header_line
   move  $a0, $s1
  beqz  $v0, .Ljp7F0668F8
   move  $a0, $s1
  jal   check_special_attributes
   li    $a1, 2048
  beqz  $v0, .Ljp7F0668F8
   move  $a0, $s1
  jal   check_special_attributes
   li    $a1, 8192
  beql  $v0, $zero, .Ljp7F066910
   lw    $t7, 0x20($s0)
.Ljp7F0668F8:
  sw    $zero, 0x24($s0)
.Ljp7F0668FC:
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
  b     .Ljp7F0669F8
   move  $v0, $zero
  lw    $t7, 0x20($s0)
.Ljp7F066910:
  li    $t8, 23
  li    $at, 0x41B80000 # 23.000000
  subu  $t9, $t8, $t7
  mtc1  $t9, $f10
  mtc1  $at, $f2
  lui   $at, %hi(D_80054398) # $at, 0x8005
  cvt.s.w $f4, $f10
  lwc1  $f8, %lo(D_80054398)($at)
  li    $t6, 1
  addiu $a1, $s0, 0x7c
  mul.s $f6, $f4, $f8
  div.s $f10, $f6, $f2
  swc1  $f10, 0x9c($sp)
  sw    $t6, 0xbc($s0)
  lw    $t8, 0x1e0($sp)
  bnezl $t8, .Ljp7F066974
   mtc1  $zero, $f8
  mtc1  $zero, $f4
  sw    $a1, 0x34($sp)
  div.s $f12, $f4, $f2
  jal   sub_GAME_7F058688
   swc1  $f12, 0x40($sp)
  b     .Ljp7F06698C
   lwc1  $f12, 0x9c($sp)
  mtc1  $zero, $f8
.Ljp7F066974:
  sw    $a1, 0x34($sp)
  div.s $f0, $f8, $f2
  neg.s $f12, $f0
  jal   sub_GAME_7F058688
   swc1  $f0, 0x40($sp)
  lwc1  $f12, 0x9c($sp)
.Ljp7F06698C:
  jal   sub_GAME_7F058570
   addiu $a1, $sp, 0xa0
  addiu $a0, $sp, 0xa0
  jal   matrix_4x4_multiply_in_place
   lw    $a1, 0x34($sp)
  jal   sinf
   lwc1  $f12, 0x40($sp)
  mtc1  $zero, $f6
  move  $a0, $s1
  jal   sub_GAME_7F0649AC
   swc1  $f6, 0xac($s0)
  swc1  $f0, 0x44($sp)
  jal   cosf
   lwc1  $f12, 0x9c($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  lwc1  $f8, 0x44($sp)
  sub.s $f4, $f10, $f0
  mul.s $f6, $f4, $f8
  swc1  $f6, 0xb0($s0)
  jal   sinf
   lwc1  $f12, 0x9c($sp)
  li    $at, 0x41700000 # 15.000000
  mtc1  $at, $f10
  lw    $v0, 0x24($s0)
  mul.s $f4, $f0, $f10
  swc1  $f4, 0xb4($s0)
.Ljp7F0669F8:
  li    $at, 14
.Ljp7F0669FC:
  bnel  $v0, $at, .Ljp7F066AB8
   li    $at, 15
  lw    $v1, 0x20($s0)
  li    $v0, 15
  slti  $at, $v1, 0x10
  beql  $at, $zero, .Ljp7F066A28
   sw    $v0, 0x24($s0)
  lb    $t7, 0xf($s0)
  bnezl $t7, .Ljp7F066A38
   mtc1  $v1, $f8
  sw    $v0, 0x24($s0)
.Ljp7F066A28:
  sw    $zero, 0x20($s0)
  b     .Ljp7F066AB4
   sw    $zero, 0x1c($s0)
  mtc1  $v1, $f8
.Ljp7F066A38:
  lui   $at, %hi(D_8005439C) # $at, 0x8005
  lwc1  $f10, %lo(D_8005439C)($at)
  cvt.s.w $f6, $f8
  li    $at, 0x41800000 # 16.000000
  mtc1  $at, $f8
  li    $t6, 1
  sw    $t6, 0xbc($s0)
  addiu $a1, $s0, 0x7c
  mul.s $f4, $f6, $f10
  div.s $f12, $f4, $f8
  jal   sub_GAME_7F058570
   swc1  $f12, 0x98($sp)
  mtc1  $zero, $f6
  nop   
  swc1  $f6, 0xac($s0)
  jal   cosf
   lwc1  $f12, 0x98($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  li    $at, 0xC2700000 # -60.000000
  mtc1  $at, $f8
  sub.s $f4, $f10, $f0
  mul.s $f6, $f4, $f8
  swc1  $f6, 0xb0($s0)
  jal   sinf
   lwc1  $f12, 0x98($sp)
  li    $at, 0x41700000 # 15.000000
  mtc1  $at, $f10
  lw    $v0, 0x24($s0)
  mul.s $f4, $f0, $f10
  swc1  $f4, 0xb4($s0)
.Ljp7F066AB4:
  li    $at, 15
.Ljp7F066AB8:
  bnel  $v0, $at, .Ljp7F066B80
   li    $at, 16
  lw    $t8, 0x1c($s0)
  beql  $t8, $zero, .Ljp7F066AE0
   lw    $a0, 0x1e0($sp)
  jal   sub_GAME_7F05CEBC
   lw    $a0, 0x1e0($sp)
  bnez  $v0, .Ljp7F066AF4
   nop   
  lw    $a0, 0x1e0($sp)
.Ljp7F066AE0:
  jal   sub_GAME_7F05DA8C
   lw    $a1, 0x3c($s0)
  jal   return_ammo_in_hand
   lw    $a0, 0x1e0($sp)
  move  $s1, $v0
.Ljp7F066AF4:
  jal   sub_GAME_7F05CEBC
   lw    $a0, 0x1e0($sp)
  beqz  $v0, .Ljp7F066B18
   li    $t9, 1
  li    $v0, 16
  sw    $v0, 0x24($s0)
  sw    $zero, 0x20($s0)
  b     .Ljp7F066B7C
   sw    $zero, 0x1c($s0)
.Ljp7F066B18:
  sw    $t9, 0xbc($s0)
  lui   $at, %hi(D_800543A0) # $at, 0x8005
  lwc1  $f12, %lo(D_800543A0)($at)
  jal   sub_GAME_7F058570
   addiu $a1, $s0, 0x7c
  mtc1  $zero, $f8
  lui   $at, %hi(D_800543A4) # $at, 0x8005
  swc1  $f8, 0xac($s0)
  jal   cosf
   lwc1  $f12, %lo(D_800543A4)($at)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  li    $at, 0xC2700000 # -60.000000
  mtc1  $at, $f4
  sub.s $f10, $f6, $f0
  lui   $at, %hi(D_800543A8) # $at, 0x8005
  mul.s $f8, $f10, $f4
  swc1  $f8, 0xb0($s0)
  jal   sinf
   lwc1  $f12, %lo(D_800543A8)($at)
  li    $at, 0x41700000 # 15.000000
  mtc1  $at, $f6
  lw    $v0, 0x24($s0)
  mul.s $f10, $f0, $f6
  swc1  $f10, 0xb4($s0)
.Ljp7F066B7C:
  li    $at, 16
.Ljp7F066B80:
  bnel  $v0, $at, .Ljp7F066CB4
   li    $at, 17
  lw    $t6, 0x1c($s0)
  slti  $at, $s1, 0x21
  bnezl $t6, .Ljp7F066BD4
   lw    $t7, 0x20($s0)
  beql  $at, $zero, .Ljp7F066BD4
   lw    $t7, 0x20($s0)
  jal   getPlayerCount
   nop   
  slti  $at, $v0, 2
  bnez  $at, .Ljp7F066BBC
   nop   
  jal   sub_GAME_7F09B398
   lw    $a0, 0x1e0($sp)
.Ljp7F066BBC:
  jal   sub_GAME_7F0649D8
   lw    $a0, 0x1e0($sp)
  lui   $t8, %hi(pPlayer) # $t8, 0x8008
  lw    $t8, %lo(pPlayer)($t8)
  sw    $zero, 0xfc8($t8)
  lw    $t7, 0x20($s0)
.Ljp7F066BD4:
  slti  $at, $t7, 0x17
  beql  $at, $zero, .Ljp7F066C14
   sw    $zero, 0x24($s0)
  jal   get_ptr_weapon_model_header_line
   move  $a0, $s1
  beqz  $v0, .Ljp7F066C10
   move  $a0, $s1
  jal   check_special_attributes
   li    $a1, 2048
  beqz  $v0, .Ljp7F066C10
   move  $a0, $s1
  jal   check_special_attributes
   li    $a1, 8192
  beql  $v0, $zero, .Ljp7F066C28
   lw    $t9, 0x20($s0)
.Ljp7F066C10:
  sw    $zero, 0x24($s0)
.Ljp7F066C14:
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
  b     .Ljp7F066CB0
   move  $v0, $zero
  lw    $t9, 0x20($s0)
.Ljp7F066C28:
  li    $t6, 23
  lui   $at, %hi(D_800543AC) # $at, 0x8005
  subu  $t8, $t6, $t9
  mtc1  $t8, $f4
  lwc1  $f6, %lo(D_800543AC)($at)
  li    $at, 0x41B80000 # 23.000000
  cvt.s.w $f8, $f4
  mtc1  $at, $f4
  li    $t7, 1
  sw    $t7, 0xbc($s0)
  addiu $a1, $s0, 0x7c
  mul.s $f10, $f8, $f6
  div.s $f12, $f10, $f4
  jal   sub_GAME_7F058570
   swc1  $f12, 0x90($sp)
  mtc1  $zero, $f8
  nop   
  swc1  $f8, 0xac($s0)
  jal   cosf
   lwc1  $f12, 0x90($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  li    $at, 0xC2700000 # -60.000000
  mtc1  $at, $f4
  sub.s $f10, $f6, $f0
  mul.s $f8, $f10, $f4
  swc1  $f8, 0xb0($s0)
  jal   sinf
   lwc1  $f12, 0x90($sp)
  li    $at, 0x41700000 # 15.000000
  mtc1  $at, $f6
  lw    $v0, 0x24($s0)
  mul.s $f10, $f0, $f6
  swc1  $f10, 0xb4($s0)
.Ljp7F066CB0:
  li    $at, 17
.Ljp7F066CB4:
  beq   $v0, $at, .Ljp7F066CE4
   li    $at, 18
  beq   $v0, $at, .Ljp7F066CE4
   li    $a0, 19
  beq   $a0, $v0, .Ljp7F066CE4
   li    $at, 20
  beq   $v0, $at, .Ljp7F066CE4
   li    $at, 21
  beq   $v0, $at, .Ljp7F066CE4
   li    $at, 22
  bnel  $v0, $at, .Ljp7F066E38
   li    $at, 30
.Ljp7F066CE4:
  lw    $v1, 0x20($s0)
  addiu $t6, $s0, 0x7c
  li    $at, 17
  mtc1  $v1, $f4
  li    $a0, 19
  sw    $t6, 0x34($sp)
  cvt.s.w $f8, $f4
  beq   $v0, $at, .Ljp7F066D10
   swc1  $f8, 0x8c($sp)
  li    $at, 20
  bne   $v0, $at, .Ljp7F066D88
.Ljp7F066D10:
   slti  $at, $v1, 0x10
  bnez  $at, .Ljp7F066D88
   lui   $t8, %hi(D_80035E94) # $t8, 0x8003
  addiu $t8, %lo(D_80035E94) # addiu $t8, $t8, 0x5ed4
  lw    $at, ($t8)
  addiu $t9, $sp, 0x80
  sw    $at, ($t9)
  lhu   $at, 4($t8)
  jal   get_random_value
   sh    $at, 4($t9)
  li    $at, 3
  divu  $zero, $v0, $at
  mfhi  $t7
  sll   $t9, $t7, 1
  addu  $a1, $sp, $t9
  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  lh    $a1, 0x80($a1)
  jal   play_sfx_a1
   move  $a2, $zero
  lw    $t8, 0x24($s0)
  li    $at, 17
  li    $v0, 21
  bne   $t8, $at, .Ljp7F066D84
   li    $a0, 19
  li    $v0, 18
  sw    $v0, 0x24($s0)
  b     .Ljp7F066D88
   li    $a0, 19
.Ljp7F066D84:
  sw    $v0, 0x24($s0)
.Ljp7F066D88:
  beq   $a0, $v0, .Ljp7F066DD4
   li    $at, 22
  beql  $v0, $at, .Ljp7F066DD8
   li    $at, 17
  lw    $t9, 0x20($s0)
  li    $t8, 1
  slti  $at, $t9, 0x18
  bnez  $at, .Ljp7F066DD4
   li    $at, 17
  beq   $v0, $at, .Ljp7F066DC0
   sb    $t8, 0xc($s0)
  li    $at, 18
  bnel  $v0, $at, .Ljp7F066DD0
   li    $v0, 22
.Ljp7F066DC0:
  sw    $a0, 0x24($s0)
  b     .Ljp7F066DD4
   move  $v0, $a0
  li    $v0, 22
.Ljp7F066DD0:
  sw    $v0, 0x24($s0)
.Ljp7F066DD4:
  li    $at, 17
.Ljp7F066DD8:
  beq   $v0, $at, .Ljp7F066DF0
   lw    $a1, 0x8c($sp)
  li    $at, 18
  beq   $v0, $at, .Ljp7F066DF0
   nop   
  bne   $a0, $v0, .Ljp7F066DFC
.Ljp7F066DF0:
   lui   $a0, %hi(D_80034CA4) # $a0, 0x8003
  b     .Ljp7F066E04
   addiu $a0, %lo(D_80034CA4) # addiu $a0, $a0, 0x4ce4
.Ljp7F066DFC:
  lui   $a0, %hi(D_80034E0C) # $a0, 0x8003
  addiu $a0, %lo(D_80034E0C) # addiu $a0, $a0, 0x4e4c
.Ljp7F066E04:
  lw    $a2, 0x34($sp)
  jal   sub_GAME_7F05C6FC
   lw    $a3, 0x1e0($sp)
  beqz  $v0, .Ljp7F066E24
   li    $t7, 1
  sw    $t7, 0xbc($s0)
  b     .Ljp7F066E34
   lw    $v0, 0x24($s0)
.Ljp7F066E24:
  sw    $zero, 0x24($s0)
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
  move  $v0, $zero
.Ljp7F066E34:
  li    $at, 30
.Ljp7F066E38:
  beq   $v0, $at, .Ljp7F066E58
   li    $a1, 31
  beq   $a1, $v0, .Ljp7F066E58
   li    $at, 32
  beq   $v0, $at, .Ljp7F066E58
   li    $a0, 33
  bnel  $a0, $v0, .Ljp7F066F58
   li    $at, 26
.Ljp7F066E58:
  lw    $v1, 0x20($s0)
  li    $at, 30
  li    $a0, 33
  mtc1  $v1, $f6
  li    $a1, 31
  addiu $a2, $s0, 0x7c
  beq   $v0, $at, .Ljp7F066E80
   cvt.s.w $f0, $f6
  bne   $a1, $v0, .Ljp7F066ECC
   li    $at, 32
.Ljp7F066E80:
  lui   $t9, %hi(pPlayer) # $t9, 0x8008
  lw    $t9, %lo(pPlayer)($t9)
  li    $at, 17
  lui   $t6, %hi(D_80035778) # $t6, 0x8003
  lw    $t8, 0x2a38($t9)
  lui   $t7, %hi(D_800354A8) # $t7, 0x8003
  addiu $t6, %lo(D_80035778) # addiu $t6, $t6, 0x57b8
  bne   $t8, $at, .Ljp7F066EAC
   addiu $t7, %lo(D_800354A8) # addiu $t7, $t7, 0x54e8
  b     .Ljp7F066EB0
   sw    $t6, 0x78($sp)
.Ljp7F066EAC:
  sw    $t7, 0x78($sp)
.Ljp7F066EB0:
  beq   $a1, $v0, .Ljp7F066F20
   slti  $at, $v1, 0x1e
  bnez  $at, .Ljp7F066F20
   li    $t9, 1
  sb    $t9, 0xc($s0)
  b     .Ljp7F066F20
   sw    $a1, 0x24($s0)
.Ljp7F066ECC:
  beq   $v0, $at, .Ljp7F066EDC
   lui   $t8, %hi(pPlayer) # $t8, 0x8008
  bnel  $a0, $v0, .Ljp7F066F24
   mfc1  $a1, $f0
.Ljp7F066EDC:
  lw    $t8, %lo(pPlayer)($t8)
  li    $at, 17
  lui   $t7, %hi(D_80035904) # $t7, 0x8003
  lw    $t6, 0x2a38($t8)
  lui   $t9, %hi(D_80035610) # $t9, 0x8003
  addiu $t7, %lo(D_80035904) # addiu $t7, $t7, 0x5944
  bne   $t6, $at, .Ljp7F066F04
   addiu $t9, %lo(D_80035610) # addiu $t9, $t9, 0x5650
  b     .Ljp7F066F08
   sw    $t7, 0x78($sp)
.Ljp7F066F04:
  sw    $t9, 0x78($sp)
.Ljp7F066F08:
  beq   $a0, $v0, .Ljp7F066F20
   slti  $at, $v1, 0x1e
  bnez  $at, .Ljp7F066F20
   li    $t8, 1
  sb    $t8, 0xc($s0)
  sw    $a0, 0x24($s0)
.Ljp7F066F20:
  mfc1  $a1, $f0
.Ljp7F066F24:
  lw    $a0, 0x78($sp)
  jal   sub_GAME_7F05C6FC
   lw    $a3, 0x1e0($sp)
  beqz  $v0, .Ljp7F066F44
   li    $t6, 1
  sw    $t6, 0xbc($s0)
  b     .Ljp7F066F54
   lw    $v0, 0x24($s0)
.Ljp7F066F44:
  sw    $zero, 0x24($s0)
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
  move  $v0, $zero
.Ljp7F066F54:
  li    $at, 26
.Ljp7F066F58:
  bnel  $v0, $at, .Ljp7F066FE8
   li    $at, 27
  lw    $t7, 0x2c($s0)
  move  $v0, $zero
  blezl $t7, .Ljp7F066FDC
   sw    $zero, 0x24($s0)
  lw    $t9, 0x20($s0)
  lui   $a0, %hi(D_80035124) # $a0, 0x8003
  addiu $a0, %lo(D_80035124) # addiu $a0, $a0, 0x5164
  mtc1  $t9, $f10
  addiu $a2, $s0, 0x7c
  lw    $a3, 0x1e0($sp)
  cvt.s.w $f0, $f10
  mfc1  $a1, $f0
  jal   sub_GAME_7F05C6FC
   nop   
  beqz  $v0, .Ljp7F066FAC
   li    $t6, 1
  li    $t8, 1
  b     .Ljp7F066FD0
   sw    $t8, 0xbc($s0)
.Ljp7F066FAC:
  lw    $t7, 0x2c($s0)
  li    $t8, 27
  sb    $zero, 0xe($s0)
  addiu $t9, $t7, -1
  sb    $t6, 0xc($s0)
  sw    $t9, 0x2c($s0)
  sw    $t8, 0x24($s0)
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
.Ljp7F066FD0:
  b     .Ljp7F066FE4
   lw    $v0, 0x24($s0)
  sw    $zero, 0x24($s0)
.Ljp7F066FDC:
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
.Ljp7F066FE4:
  li    $at, 27
.Ljp7F066FE8:
  bnel  $v0, $at, .Ljp7F067048
   li    $at, 23
  lw    $t6, 0x20($s0)
  lui   $a0, %hi(D_800351FC) # $a0, 0x8003
  addiu $a0, %lo(D_800351FC) # addiu $a0, $a0, 0x523c
  mtc1  $t6, $f4
  addiu $a2, $s0, 0x7c
  lw    $a3, 0x1e0($sp)
  cvt.s.w $f0, $f4
  mfc1  $a1, $f0
  jal   sub_GAME_7F05C6FC
   nop   
  beqz  $v0, .Ljp7F067030
   li    $t9, 1
  li    $t7, 1
  sw    $t7, 0xbc($s0)
  b     .Ljp7F067044
   lw    $v0, 0x24($s0)
.Ljp7F067030:
  sb    $t9, 0xe($s0)
  sw    $zero, 0x24($s0)
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
  move  $v0, $zero
.Ljp7F067044:
  li    $at, 23
.Ljp7F067048:
  bnel  $v0, $at, .Ljp7F0670FC
   li    $at, 24
  lw    $t8, 0x2c($s0)
  move  $v0, $zero
  blezl $t8, .Ljp7F0670F0
   sw    $zero, 0x24($s0)
  lw    $t6, 0x18($s0)
  li    $t7, 24
  beql  $t6, $zero, .Ljp7F06707C
   lw    $t9, 0x20($s0)
  b     .Ljp7F0670E4
   sw    $t7, 0x24($s0)
  lw    $t9, 0x20($s0)
.Ljp7F06707C:
  lui   $a0, %hi(D_80034F74) # $a0, 0x8003
  addiu $a2, $s0, 0x7c
  mtc1  $t9, $f8
  sw    $a2, 0x34($sp)
  addiu $a0, %lo(D_80034F74) # addiu $a0, $a0, 0x4fb4
  cvt.s.w $f0, $f8
  lw    $a3, 0x1e0($sp)
  mfc1  $a1, $f0
  jal   sub_GAME_7F05C6FC
   nop   
  beqz  $v0, .Ljp7F0670B8
   lui   $a0, %hi(D_8003504C) # $a0, 0x8003
  li    $t8, 1
  b     .Ljp7F0670E4
   sw    $t8, 0xbc($s0)
.Ljp7F0670B8:
  addiu $a0, %lo(D_8003504C) # addiu $a0, $a0, 0x508c
  li    $a1, 0
  lw    $a2, 0x34($sp)
  jal   sub_GAME_7F05C6FC
   lw    $a3, 0x1e0($sp)
  beqz  $v0, .Ljp7F0670E0
   li    $t7, 24
  li    $t6, 1
  b     .Ljp7F0670E4
   sw    $t6, 0xbc($s0)
.Ljp7F0670E0:
  sw    $t7, 0x24($s0)
.Ljp7F0670E4:
  b     .Ljp7F0670F8
   lw    $v0, 0x24($s0)
  sw    $zero, 0x24($s0)
.Ljp7F0670F0:
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
.Ljp7F0670F8:
  li    $at, 24
.Ljp7F0670FC:
  bnel  $v0, $at, .Ljp7F06718C
   li    $at, 25
  lw    $t9, 0x2c($s0)
  move  $v0, $zero
  blezl $t9, .Ljp7F067180
   sw    $zero, 0x24($s0)
  lw    $t8, 0x20($s0)
  lui   $a0, %hi(D_80034F74) # $a0, 0x8003
  addiu $a0, %lo(D_80034F74) # addiu $a0, $a0, 0x4fb4
  mtc1  $t8, $f6
  addiu $a2, $s0, 0x7c
  lw    $a3, 0x1e0($sp)
  cvt.s.w $f0, $f6
  mfc1  $a1, $f0
  jal   sub_GAME_7F05C6FC
   nop   
  beqz  $v0, .Ljp7F067150
   li    $t7, 1
  li    $t6, 1
  b     .Ljp7F067174
   sw    $t6, 0xbc($s0)
.Ljp7F067150:
  lw    $t9, 0x2c($s0)
  li    $t6, 25
  sb    $zero, 0xe($s0)
  addiu $t8, $t9, -1
  sb    $t7, 0xc($s0)
  sw    $t8, 0x2c($s0)
  sw    $t6, 0x24($s0)
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
.Ljp7F067174:
  b     .Ljp7F067188
   lw    $v0, 0x24($s0)
  sw    $zero, 0x24($s0)
.Ljp7F067180:
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
.Ljp7F067188:
  li    $at, 25
.Ljp7F06718C:
  bnel  $v0, $at, .Ljp7F0671EC
   li    $at, 28
  lw    $t7, 0x20($s0)
  lui   $a0, %hi(D_8003504C) # $a0, 0x8003
  addiu $a0, %lo(D_8003504C) # addiu $a0, $a0, 0x508c
  mtc1  $t7, $f10
  addiu $a2, $s0, 0x7c
  lw    $a3, 0x1e0($sp)
  cvt.s.w $f0, $f10
  mfc1  $a1, $f0
  jal   sub_GAME_7F05C6FC
   nop   
  beqz  $v0, .Ljp7F0671D4
   li    $t8, 1
  li    $t9, 1
  sw    $t9, 0xbc($s0)
  b     .Ljp7F0671E8
   lw    $v0, 0x24($s0)
.Ljp7F0671D4:
  sb    $t8, 0xe($s0)
  sw    $zero, 0x24($s0)
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
  move  $v0, $zero
.Ljp7F0671E8:
  li    $at, 28
.Ljp7F0671EC:
  bnel  $v0, $at, .Ljp7F067290
   li    $at, 29
  lw    $t6, 0x2c($s0)
  move  $a0, $s1
  bgtzl $t6, .Ljp7F067218
   lw    $t7, 0x20($s0)
  jal   check_special_attributes
   li    $a1, 16
  beql  $v0, $zero, .Ljp7F067280
   sw    $zero, 0x24($s0)
  lw    $t7, 0x20($s0)
.Ljp7F067218:
  lui   $a0, %hi(D_800352D4) # $a0, 0x8003
  addiu $a0, %lo(D_800352D4) # addiu $a0, $a0, 0x5314
  mtc1  $t7, $f4
  addiu $a2, $s0, 0x7c
  lw    $a3, 0x1e0($sp)
  cvt.s.w $f0, $f4
  mfc1  $a1, $f0
  jal   sub_GAME_7F05C6FC
   nop   
  beqz  $v0, .Ljp7F067250
   li    $t8, 1
  li    $t9, 1
  b     .Ljp7F067274
   sw    $t9, 0xbc($s0)
.Ljp7F067250:
  lw    $t6, 0x2c($s0)
  li    $t9, 29
  sb    $zero, 0xe($s0)
  addiu $t7, $t6, -1
  sb    $t8, 0xc($s0)
  sw    $t7, 0x2c($s0)
  sw    $t9, 0x24($s0)
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
.Ljp7F067274:
  b     .Ljp7F06728C
   lw    $v0, 0x24($s0)
  sw    $zero, 0x24($s0)
.Ljp7F067280:
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
  move  $v0, $zero
.Ljp7F06728C:
  li    $at, 29
.Ljp7F067290:
  bnel  $v0, $at, .Ljp7F0672F0
   li    $at, 36
  lw    $t8, 0x20($s0)
  lui   $a0, %hi(D_800353AC) # $a0, 0x8003
  addiu $a0, %lo(D_800353AC) # addiu $a0, $a0, 0x53ec
  mtc1  $t8, $f8
  addiu $a2, $s0, 0x7c
  lw    $a3, 0x1e0($sp)
  cvt.s.w $f0, $f8
  mfc1  $a1, $f0
  jal   sub_GAME_7F05C6FC
   nop   
  beqz  $v0, .Ljp7F0672D8
   li    $t7, 1
  li    $t6, 1
  sw    $t6, 0xbc($s0)
  b     .Ljp7F0672EC
   lw    $v0, 0x24($s0)
.Ljp7F0672D8:
  sb    $t7, 0xe($s0)
  sw    $zero, 0x24($s0)
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
  move  $v0, $zero
.Ljp7F0672EC:
  li    $at, 36
.Ljp7F0672F0:
  bne   $v0, $at, .Ljp7F067428
   li    $at, 46
  bnel  $s1, $at, .Ljp7F067320
   li    $at, 44
  lw    $t9, 0x1c($s0)
  bnez  $t9, .Ljp7F067314
   nop   
  jal   sub_GAME_7F066E64
   nop   
.Ljp7F067314:
  b     .Ljp7F067414
   lw    $a1, 0x18($s0)
  li    $at, 44
.Ljp7F067320:
  bnel  $s1, $at, .Ljp7F067348
   li    $at, 39
  lw    $t8, 0x1c($s0)
  bnez  $t8, .Ljp7F06733C
   nop   
  jal   sub_GAME_7F066F08
   nop   
.Ljp7F06733C:
  b     .Ljp7F067414
   lw    $a1, 0x18($s0)
  li    $at, 39
.Ljp7F067348:
  beq   $s1, $at, .Ljp7F067370
   li    $at, 55
  beq   $s1, $at, .Ljp7F067370
   li    $at, 38
  beq   $s1, $at, .Ljp7F067370
   li    $at, 50
  beq   $s1, $at, .Ljp7F067370
   li    $at, 73
  bnel  $s1, $at, .Ljp7F0673A8
   li    $at, 51
.Ljp7F067370:
  lw    $t6, 0x1c($s0)
  bnez  $t6, .Ljp7F06739C
   nop   
  jal   sub_GAME_7F03C3FC
   nop   
  beqz  $v0, .Ljp7F06739C
   nop   
  lw    $v1, 4($v0)
  lbu   $t7, 2($v1)
  ori   $t9, $t7, 0x40
  sb    $t9, 2($v1)
.Ljp7F06739C:
  b     .Ljp7F067414
   lw    $a1, 0x18($s0)
  li    $at, 51
.Ljp7F0673A8:
  beq   $s1, $at, .Ljp7F067414
   lw    $a1, 0x18($s0)
  li    $at, 52
  beq   $s1, $at, .Ljp7F067414
   li    $at, 58
  beq   $s1, $at, .Ljp7F067414
   li    $at, 59
  beq   $s1, $at, .Ljp7F067414
   li    $at, 81
  beq   $s1, $at, .Ljp7F067414
   li    $at, 82
  beq   $s1, $at, .Ljp7F067414
   li    $at, 83
  beq   $s1, $at, .Ljp7F067414
   li    $at, 45
  beq   $s1, $at, .Ljp7F067414
   li    $at, 41
  beq   $s1, $at, .Ljp7F067414
   li    $at, 42
  beq   $s1, $at, .Ljp7F067414
   li    $at, 53
  beq   $s1, $at, .Ljp7F067414
   li    $at, 54
  beq   $s1, $at, .Ljp7F067414
   li    $at, 37
  beq   $s1, $at, .Ljp7F067414
   nop   
.Ljp7F067414:
  beql  $a1, $zero, .Ljp7F06742C
   lw    $ra, 0x24($sp)
  sw    $zero, 0x24($s0)
  sw    $zero, 0x20($s0)
  sw    $zero, 0x1c($s0)
.Ljp7F067428:
  lw    $ra, 0x24($sp)
.Ljp7F06742C:
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x1e0   
");
#endif

#endif

#ifdef VERSION_US
asm(R"
glabel sub_GAME_7F066E64
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F08CF0C
   nop   
  beqz  $v0, .L7F066ED0
   nop   
  jal   get_textptr_for_textID
   li    $a0, 39128
  jal   display_string_in_lower_left_corner
   move  $a0, $v0
  lui   $t7, %hi(pPlayer) 
  lw    $t7, %lo(pPlayer)($t7)
  li    $t6, 1
  lui   $a0, %hi(ptr_sfx_buf)
  sw    $t6, 0x1060($t7)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 245
  jal   play_sfx_a1
   move  $a2, $zero
  move  $a0, $zero
  jal   draw_item_in_hand_has_more_ammo
   li    $a1, 61
  li    $a0, 1
  jal   draw_item_in_hand_has_more_ammo
   move  $a1, $zero
  b     .L7F066EEC
   lw    $ra, 0x14($sp)
.L7F066ED0:
  jal   get_textptr_for_textID
   li    $a0, 39129
  jal   display_string_in_lower_left_corner
   move  $a0, $v0
  jal   sub_GAME_7F05D690
   nop   
  lw    $ra, 0x14($sp)
.L7F066EEC:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");
#ifdef VERSION_JP
asm(R"
glabel sub_GAME_7F066E64
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F08CF0C
   nop   
  beqz  $v0, .L7F066ED0
   nop   
  jal   get_textptr_for_textID
   li    $a0, 39128
  jal   jp_display_string_in_lower_left_corner
   move  $a0, $v0
  lui   $t7, %hi(pPlayer) 
  lw    $t7, %lo(pPlayer)($t7)
  li    $t6, 1
  lui   $a0, %hi(ptr_sfx_buf)
  sw    $t6, 0x1060($t7)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 245
  jal   play_sfx_a1
   move  $a2, $zero
  move  $a0, $zero
  jal   draw_item_in_hand_has_more_ammo
   li    $a1, 61
  li    $a0, 1
  jal   draw_item_in_hand_has_more_ammo
   move  $a1, $zero
  b     .L7F066EEC
   lw    $ra, 0x14($sp)
.L7F066ED0:
  jal   get_textptr_for_textID
   li    $a0, 39129
  jal   jp_display_string_in_lower_left_corner
   move  $a0, $v0
  jal   sub_GAME_7F05D690
   nop   
  lw    $ra, 0x14($sp)
.L7F066EEC:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");
#endif
#endif

asm(R"
glabel get_keyanalyzer_flag
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  jr    $ra
   lw    $v0, 0x1060($t6)
");

asm(R"
glabel sub_GAME_7F066F08
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  li    $a0, 10
  li    $a1, 2
  move  $a2, $zero
  jal   add_ammo_to_inventory
   li    $a3, 1
  li    $a0, 5
  li    $a1, 2
  move  $a2, $zero
  jal   add_ammo_to_inventory
   li    $a3, 1
  jal   add_item_to_inventory
   li    $a0, 17
  jal   set_sound_effect_for_weapontype_collection
   li    $a0, 17
  jal   display_text_for_weapon_in_lower_left_corner
   li    $a0, 17
  lui   $a0, %hi(GsniperrifleZ_stats+0x1C)
  jal   check_cur_player_ammo_amount_in_inventory
   lw    $a0, %lo(GsniperrifleZ_stats+0x1C)($a0)
  lui   $v1, %hi(GsniperrifleZ_stats)
  addiu $v1, %lo(GsniperrifleZ_stats) # addiu $v1, $v1, 0x2c04
  lh    $t6, 0x20($v1)
  lw    $a0, 0x1c($v1)
  jal   give_cur_player_ammo
   addu  $a1, $v0, $t6
  jal   sub_GAME_7F08C61C
   li    $a0, 44
  move  $a0, $zero
  jal   draw_item_in_hand_has_more_ammo
   li    $a1, 17
  li    $a0, 1
  jal   draw_item_in_hand_has_more_ammo
   move  $a1, $zero
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel get_vertical_position_solo_watch_menu_main_page_for_item
  sll   $t6, $a0, 3
  subu  $t6, $t6, $a0
  sll   $t6, $t6, 3
  lui   $at, %hi(gitem_structs+20)
  addu  $at, $at, $t6
  jr    $ra
   lwc1  $f0, %lo(gitem_structs+20)($at)
");

asm(R"
glabel get_lateral_position_solo_watch_menu_main_page_for_item
  sll   $t6, $a0, 3
  subu  $t6, $t6, $a0
  sll   $t6, $t6, 3
  lui   $at, %hi(gitem_structs+24)
  addu  $at, $at, $t6
  jr    $ra
   lwc1  $f0, %lo(gitem_structs+24)($at)
");

asm(R"
glabel get_depth_on_solo_watch_menu_page_for_item
  sll   $t6, $a0, 3
  subu  $t6, $t6, $a0
  sll   $t6, $t6, 3
  lui   $at, %hi(gitem_structs+28)
  addu  $at, $at, $t6
  jr    $ra
   lwc1  $f0, %lo(gitem_structs+28)($at)
");

asm(R"
glabel get_xrotation_solo_watch_menu_for_item
  sll   $t6, $a0, 3
  subu  $t6, $t6, $a0
  sll   $t6, $t6, 3
  lui   $at, %hi(gitem_structs+32)
  addu  $at, $at, $t6
  jr    $ra
   lwc1  $f0, %lo(gitem_structs+32)($at)
");

asm(R"
glabel get_yrotation_solo_watch_menu_for_item
  sll   $t6, $a0, 3
  subu  $t6, $t6, $a0
  sll   $t6, $t6, 3
  lui   $at, %hi(gitem_structs+36)
  addu  $at, $at, $t6
  jr    $ra
   lwc1  $f0, %lo(gitem_structs+36)($at)
");

asm(R"
glabel get_45_degree_angle
  li    $at, 0x42340000 # 45.000000
  mtc1  $at, $f0
  jr    $ra
   sw    $a0, ($sp)
");

asm(R"
glabel get_ptr_first_title_line_item
  sll   $t6, $a0, 3
  subu  $t6, $t6, $a0
  addiu $sp, $sp, -0x18
  sll   $t6, $t6, 3
  lui   $a0, %hi(gitem_structs+0x10)
  sw    $ra, 0x14($sp)
  addu  $a0, $a0, $t6
  jal   get_textptr_for_textID
   lhu   $a0, %lo(gitem_structs+0x10)($a0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel get_ptr_second_title_line_item
  sll   $t6, $a0, 3
  subu  $t6, $t6, $a0
  addiu $sp, $sp, -0x18
  sll   $t6, $t6, 3
  lui   $a0, %hi(gitem_structs+0x12)
  sw    $ra, 0x14($sp)
  addu  $a0, $a0, $t6
  jal   get_textptr_for_textID
   lhu   $a0, %lo(gitem_structs+0x12)($a0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel get_ptr_short_watch_text_for_item
  sll   $t6, $a0, 3
  subu  $t6, $t6, $a0
  addiu $sp, $sp, -0x18
  sll   $t6, $t6, 3
  lui   $a0, %hi(gitem_structs+0x2A)
  sw    $ra, 0x14($sp)
  addu  $a0, $a0, $t6
  jal   get_textptr_for_textID
   lhu   $a0, %lo(gitem_structs+0x2A)($a0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel get_ptr_long_watch_text_for_item
  sll   $t6, $a0, 3
  subu  $t6, $t6, $a0
  addiu $sp, $sp, -0x18
  sll   $t6, $t6, 3
  lui   $a0, %hi(gitem_structs+0x28)
  sw    $ra, 0x14($sp)
  addu  $a0, $a0, $t6
  jal   get_textptr_for_textID
   lhu   $a0, %lo(gitem_structs+0x28)($a0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel get_45_degree_angle_0
  li    $at, 0x42340000 # 45.000000
  mtc1  $at, $f0
  jr    $ra
   sw    $a0, ($sp)
");

asm(R"
glabel get_horizontal_offset_on_solo_watch_menu_for_item
  sll   $t6, $a0, 3
  subu  $t6, $t6, $a0
  sll   $t6, $t6, 3
  lui   $at, %hi(gitem_structs+44)
  addu  $at, $at, $t6
  jr    $ra
   lwc1  $f0, %lo(gitem_structs+44)($at)
");

asm(R"
glabel get_vertical_offset_on_solo_watch_menu_for_item
  sll   $t6, $a0, 3
  subu  $t6, $t6, $a0
  sll   $t6, $t6, 3
  lui   $at, %hi(gitem_structs+48)
  addu  $at, $at, $t6
  jr    $ra
   lwc1  $f0, %lo(gitem_structs+48)($at)
");

asm(R"
glabel get_depth_offset_solo_watch_menu_inventory_page_for_item
  sll   $t6, $a0, 3
  subu  $t6, $t6, $a0
  sll   $t6, $t6, 3
  lui   $at, %hi(gitem_structs+52)
  addu  $at, $at, $t6
  jr    $ra
   lwc1  $f0, %lo(gitem_structs+52)($at)
");

asm(R"
glabel sub_GAME_7F067174
  sll   $t7, $a0, 3
  subu  $t7, $t7, $a0
  sll   $t7, $t7, 2
  addu  $t7, $t7, $a0
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  sll   $t7, $t7, 2
  addu  $t7, $t7, $a0
  sll   $t7, $t7, 3
  addu  $t8, $t6, $t7
  jr    $ra
   lwc1  $f0, 0xa80($t8)
");

asm(R"
glabel sub_GAME_7F0671A4
  addiu $sp, $sp, -0x30
  sw    $ra, 0x14($sp)
  jal   get_item_in_hand
   move  $a0, $zero
  sw    $v0, 0x2c($sp)
  jal   get_item_in_hand
   li    $a0, 1
  sw    $v0, 0x28($sp)
  jal   get_ptr_item_statistics
   lw    $a0, 0x2c($sp)
  lw    $a0, 0x28($sp)
  jal   get_ptr_item_statistics
   sw    $v0, 0x1c($sp)
  lw    $t6, 0x2c($sp)
  lw    $v1, 0x1c($sp)
  move  $a1, $v0
  beqz  $t6, .L7F067240
   move  $a0, $zero
  sw    $v1, 0x1c($sp)
  jal   get_hands_firing_status
   sw    $v0, 0x18($sp)
  lw    $v1, 0x1c($sp)
  beqz  $v0, .L7F067240
   lw    $a1, 0x18($sp)
  lui   $a2, %hi(pPlayer)
  addiu $a2, %lo(pPlayer) # addiu $a2, $a2, -0x5f50
  lw    $v0, ($a2)
  lwc1  $f6, 0x5c($v1)
  lwc1  $f4, 0xa80($v0)
  add.s $f8, $f4, $f6
  swc1  $f8, 0xa80($v0)
  lw    $v0, ($a2)
  lwc1  $f0, 0x58($v1)
  lwc1  $f10, 0xa80($v0)
  c.lt.s $f0, $f10
  nop   
  bc1fl .L7F067244
   lw    $t7, 0x28($sp)
  swc1  $f0, 0xa80($v0)
.L7F067240:
  lw    $t7, 0x28($sp)
.L7F067244:
  lui   $a2, %hi(pPlayer)
  addiu $a2, %lo(pPlayer) # addiu $a2, $a2, -0x5f50
  beqz  $t7, .L7F0672A8
   li    $a0, 1
  sw    $v1, 0x1c($sp)
  jal   get_hands_firing_status
   sw    $a1, 0x18($sp)
  lui   $a2, %hi(pPlayer)
  addiu $a2, %lo(pPlayer) # addiu $a2, $a2, -0x5f50
  lw    $v1, 0x1c($sp)
  beqz  $v0, .L7F0672A8
   lw    $a1, 0x18($sp)
  lw    $v0, ($a2)
  lwc1  $f4, 0x5c($a1)
  lwc1  $f18, 0xe28($v0)
  add.s $f6, $f18, $f4
  swc1  $f6, 0xe28($v0)
  lw    $v0, ($a2)
  lwc1  $f0, 0x58($a1)
  lwc1  $f8, 0xe28($v0)
  c.lt.s $f0, $f8
  nop   
  bc1f  .L7F0672A8
   nop   
  swc1  $f0, 0xe28($v0)
.L7F0672A8:
  lui   $a0, %hi(global_timer_delta)
  addiu $a0, %lo(global_timer_delta) # addiu $a0, $a0, -0x7c88
  lwc1  $f0, ($a0)
  lwc1  $f10, 0x5c($v1)
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f16
  mul.s $f18, $f10, $f0
  lwc1  $f4, 0x60($v1)
  lw    $v0, ($a2)
  lwc1  $f8, 0x54($v1)
  mul.s $f6, $f4, $f16
  lwc1  $f14, 0xa80($v0)
  sub.s $f10, $f14, $f8
  div.s $f12, $f18, $f6
  lwc1  $f18, 0x64($v1)
  mul.s $f4, $f10, $f0
  nop   
  mul.s $f6, $f18, $f16
  div.s $f2, $f4, $f6
  c.lt.s $f12, $f2
  nop   
  bc1f  .L7F067308
   nop   
  mov.s $f12, $f2
.L7F067308:
  sub.s $f8, $f14, $f12
  swc1  $f8, 0xa80($v0)
  lw    $v0, ($a2)
  lwc1  $f0, 0x54($v1)
  lwc1  $f10, 0xa80($v0)
  c.lt.s $f10, $f0
  nop   
  bc1fl .L7F067338
   lwc1  $f0, ($a0)
  swc1  $f0, 0xa80($v0)
  lw    $v0, ($a2)
  lwc1  $f0, ($a0)
.L7F067338:
  lwc1  $f18, 0x5c($a1)
  lwc1  $f6, 0x60($a1)
  lwc1  $f14, 0xe28($v0)
  mul.s $f4, $f18, $f0
  lwc1  $f10, 0x54($a1)
  mul.s $f8, $f6, $f16
  sub.s $f18, $f14, $f10
  mul.s $f6, $f18, $f0
  div.s $f12, $f4, $f8
  lwc1  $f4, 0x64($a1)
  mul.s $f8, $f4, $f16
  div.s $f2, $f6, $f8
  c.lt.s $f12, $f2
  nop   
  bc1fl .L7F067380
   sub.s $f10, $f14, $f12
  mov.s $f12, $f2
  sub.s $f10, $f14, $f12
.L7F067380:
  swc1  $f10, 0xe28($v0)
  lw    $v0, ($a2)
  lwc1  $f0, 0x54($a1)
  lwc1  $f18, 0xe28($v0)
  c.lt.s $f18, $f0
  nop   
  bc1fl .L7F0673A8
   lw    $ra, 0x14($sp)
  swc1  $f0, 0xe28($v0)
  lw    $ra, 0x14($sp)
.L7F0673A8:
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0673B4
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   get_item_in_hand
   sw    $a0, 0x18($sp)
  jal   get_ammo_type_for_weapon
   move  $a0, $v0
  sltiu $t6, $v0, 1
  bnez  $t6, .L7F067410
   move  $v0, $t6
  lw    $t8, 0x18($sp)
  lui   $t7, %hi(pPlayer) 
  lw    $t7, %lo(pPlayer)($t7)
  sll   $t9, $t8, 3
  subu  $t9, $t9, $t8
  sll   $t9, $t9, 2
  addu  $t9, $t9, $t8
  sll   $t9, $t9, 2
  addu  $t9, $t9, $t8
  sll   $t9, $t9, 3
  addu  $t0, $t7, $t9
  lw    $v0, 0x89c($t0)
  slt   $t1, $zero, $v0
  move  $v0, $t1
.L7F067410:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F067420
  addiu $sp, $sp, -0x50
  lui   $t7, %hi(D_80035E9C) 
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  addiu $t7, %lo(D_80035E9C) # addiu $t7, $t7, 0x5e9c
  lw    $at, ($t7)
  lw    $t0, 4($t7)
  addiu $t6, $sp, 0x48
  lui   $s0, %hi(pPlayer)
  addiu $s0, %lo(pPlayer) # addiu $s0, $s0, -0x5f50
  sw    $at, ($t6)
  sw    $t0, 4($t6)
  lw    $v1, ($s0)
  lw    $t1, 0xfcc($v1)
  sw    $t1, 0xfd0($v1)
  lw    $t2, ($s0)
  sw    $a0, 0xfcc($t2)
  lw    $v1, ($s0)
  lw    $v0, 0xfcc($v1)
  bnez  $v0, .L7F067490
   nop   
  lw    $t3, 0xfd0($v1)
  li    $t4, 1
  beqz  $t3, .L7F067490
   nop   
  sw    $t4, 0xfc8($v1)
  lw    $v1, ($s0)
  lw    $v0, 0xfcc($v1)
.L7F067490:
  beql  $v0, $zero, .L7F06793C
   sw    $zero, 0xfd4($v1)
  jal   get_item_in_hand
   move  $a0, $zero
  sw    $v0, 0x44($sp)
  jal   get_item_in_hand
   li    $a0, 1
  lw    $v1, ($s0)
  sw    $v0, 0x40($sp)
  lui   $t9, %hi(clock_timer) 
  lw    $t9, %lo(clock_timer)($t9)
  lw    $t5, 0xfd4($v1)
  lw    $a0, 0x44($sp)
  addu  $t8, $t5, $t9
  beqz  $a0, .L7F0678C0
   sw    $t8, 0xfd4($v1)
  beql  $v0, $zero, .L7F0678C4
   lw    $t5, ($s0)
  jal   check_special_attributes
   li    $a1, 128
  beqz  $v0, .L7F067608
   lw    $a0, 0x40($sp)
  jal   check_special_attributes
   li    $a1, 128
  beql  $v0, $zero, .L7F06760C
   lw    $a0, 0x44($sp)
  lw    $v1, ($s0)
  lw    $t6, 0xfd4($v1)
  slti  $at, $t6, 0x15
  bnezl $at, .L7F067590
   lw    $t4, 0xfd0($v1)
  lw    $t7, 0xfd8($v1)
  li    $v0, 1
  sll   $t0, $t7, 2
  addu  $t1, $sp, $t0
  sw    $v0, 0x48($t1)
  lw    $t2, 0xfd8($v1)
  jal   sub_GAME_7F0673B4
   subu  $a0, $v0, $t2
  bnezl $v0, .L7F067570
   lw    $t7, ($s0)
  lw    $v1, ($s0)
  lw    $t3, 0xfd8($v1)
  sll   $t4, $t3, 3
  subu  $t4, $t4, $t3
  sll   $t4, $t4, 2
  addu  $t4, $t4, $t3
  sll   $t4, $t4, 2
  addu  $t4, $t4, $t3
  sll   $t4, $t4, 3
  negu  $t5, $t4
  addu  $t9, $v1, $t5
  lw    $t8, 0xc28($t9)
  beql  $t8, $zero, .L7F067940
   move  $a0, $zero
  lw    $t7, ($s0)
.L7F067570:
  li    $t6, 1
  lw    $t0, 0xfd8($t7)
  sll   $t1, $t0, 2
  negu  $t2, $t1
  addu  $t3, $sp, $t2
  b     .L7F06793C
   sw    $t6, 0x4c($t3)
  lw    $t4, 0xfd0($v1)
.L7F067590:
  bnezl $t4, .L7F0675DC
   lw    $v1, ($s0)
  lw    $t5, 0xfd8($v1)
  li    $t9, 1
  jal   sub_GAME_7F0673B4
   subu  $a0, $t9, $t5
  bnezl $v0, .L7F0675C8
   lw    $v1, ($s0)
  lw    $t8, ($s0)
  jal   sub_GAME_7F0673B4
   lw    $a0, 0xfd8($t8)
  bnezl $v0, .L7F0675DC
   lw    $v1, ($s0)
  lw    $v1, ($s0)
.L7F0675C8:
  li    $t0, 1
  lw    $t7, 0xfd8($v1)
  subu  $t1, $t0, $t7
  sw    $t1, 0xfd8($v1)
  lw    $v1, ($s0)
.L7F0675DC:
  li    $t6, 1
  lw    $t2, 0xfd8($v1)
  sll   $t3, $t2, 2
  addu  $t4, $sp, $t3
  sw    $t6, 0x48($t4)
  lw    $t9, 0xfd8($v1)
  sll   $t5, $t9, 2
  negu  $t8, $t5
  addu  $t0, $sp, $t8
  b     .L7F06793C
   sw    $zero, 0x4c($t0)
.L7F067608:
  lw    $a0, 0x44($sp)
.L7F06760C:
  jal   check_special_attributes
   li    $a1, 128
  bnez  $v0, .L7F06762C
   lw    $a0, 0x40($sp)
  jal   check_special_attributes
   li    $a1, 128
  beql  $v0, $zero, .L7F0677B4
   lw    $v1, ($s0)
.L7F06762C:
  lw    $v1, ($s0)
  lw    $a0, 0x44($sp)
  lw    $t7, 0xfd4($v1)
  slti  $at, $t7, 0x1f
  bnez  $at, .L7F0676C4
   nop   
  lw    $t1, 0xfd8($v1)
  li    $v0, 1
  sll   $t2, $t1, 2
  addu  $t6, $sp, $t2
  sw    $v0, 0x48($t6)
  lw    $t3, 0xfd8($v1)
  jal   sub_GAME_7F0673B4
   subu  $a0, $v0, $t3
  bnezl $v0, .L7F0676A8
   lw    $t1, ($s0)
  lw    $v1, ($s0)
  lw    $t4, 0xfd8($v1)
  sll   $t9, $t4, 3
  subu  $t9, $t9, $t4
  sll   $t9, $t9, 2
  addu  $t9, $t9, $t4
  sll   $t9, $t9, 2
  addu  $t9, $t9, $t4
  sll   $t9, $t9, 3
  negu  $t5, $t9
  addu  $t8, $v1, $t5
  lw    $t0, 0xc28($t8)
  beql  $t0, $zero, .L7F067940
   move  $a0, $zero
  lw    $t1, ($s0)
.L7F0676A8:
  li    $t7, 1
  lw    $t2, 0xfd8($t1)
  sll   $t6, $t2, 2
  negu  $t3, $t6
  addu  $t4, $sp, $t3
  b     .L7F06793C
   sw    $t7, 0x4c($t4)
.L7F0676C4:
  jal   check_special_attributes
   li    $a1, 128
  beqz  $v0, .L7F0676DC
   li    $a1, 1
  b     .L7F0676DC
   move  $a1, $zero
.L7F0676DC:
  move  $a0, $a1
  jal   sub_GAME_7F0673B4
   sw    $a1, 0x3c($sp)
  bnez  $v0, .L7F067728
   lw    $a1, 0x3c($sp)
  sll   $a2, $a1, 3
  subu  $a2, $a2, $a1
  sll   $a2, $a2, 2
  addu  $a2, $a2, $a1
  lw    $t9, ($s0)
  sll   $a2, $a2, 2
  addu  $a2, $a2, $a1
  sll   $a2, $a2, 3
  addu  $t5, $t9, $a2
  lw    $t8, 0x880($t5)
  li    $t1, 1
  subu  $a0, $t1, $a1
  beql  $t8, $zero, .L7F067738
   sw    $a0, 0x20($sp)
.L7F067728:
  lw    $t0, ($s0)
  b     .L7F067780
   sw    $a1, 0xfd8($t0)
  sw    $a0, 0x20($sp)
.L7F067738:
  jal   sub_GAME_7F0673B4
   sw    $a2, 0x24($sp)
  lw    $a0, 0x20($sp)
  bnez  $v0, .L7F067764
   lw    $a2, 0x24($sp)
  lw    $v1, ($s0)
  negu  $t2, $a2
  addu  $t6, $v1, $t2
  lw    $t7, 0xc28($t6)
  beql  $t7, $zero, .L7F067774
   lw    $t4, 0xfd8($v1)
.L7F067764:
  lw    $t3, ($s0)
  b     .L7F067780
   sw    $a0, 0xfd8($t3)
  lw    $t4, 0xfd8($v1)
.L7F067774:
  li    $t9, 1
  subu  $t5, $t9, $t4
  sw    $t5, 0xfd8($v1)
.L7F067780:
  lw    $v1, ($s0)
  li    $t8, 1
  lw    $t0, 0xfd8($v1)
  sll   $t1, $t0, 2
  addu  $t2, $sp, $t1
  sw    $t8, 0x48($t2)
  lw    $t6, 0xfd8($v1)
  sll   $t7, $t6, 2
  negu  $t3, $t7
  addu  $t9, $sp, $t3
  b     .L7F06793C
   sw    $zero, 0x4c($t9)
  lw    $v1, ($s0)
.L7F0677B4:
  lw    $t4, 0xfd4($v1)
  slti  $at, $t4, 0x1f
  bnezl $at, .L7F067848
   lw    $t6, 0xfd0($v1)
  lw    $t5, 0xfd8($v1)
  li    $v0, 1
  sll   $t0, $t5, 2
  addu  $t8, $sp, $t0
  sw    $v0, 0x48($t8)
  lw    $t1, 0xfd8($v1)
  jal   sub_GAME_7F0673B4
   subu  $a0, $v0, $t1
  bnezl $v0, .L7F067828
   lw    $t5, ($s0)
  lw    $v1, ($s0)
  lw    $t2, 0xfd8($v1)
  sll   $t6, $t2, 3
  subu  $t6, $t6, $t2
  sll   $t6, $t6, 2
  addu  $t6, $t6, $t2
  sll   $t6, $t6, 2
  addu  $t6, $t6, $t2
  sll   $t6, $t6, 3
  negu  $t7, $t6
  addu  $t3, $v1, $t7
  lw    $t9, 0xc28($t3)
  beql  $t9, $zero, .L7F067940
   move  $a0, $zero
  lw    $t5, ($s0)
.L7F067828:
  li    $t4, 1
  lw    $t0, 0xfd8($t5)
  sll   $t8, $t0, 2
  negu  $t1, $t8
  addu  $t2, $sp, $t1
  b     .L7F06793C
   sw    $t4, 0x4c($t2)
  lw    $t6, 0xfd0($v1)
.L7F067848:
  bnezl $t6, .L7F067894
   lw    $v1, ($s0)
  lw    $t7, 0xfd8($v1)
  li    $t3, 1
  jal   sub_GAME_7F0673B4
   subu  $a0, $t3, $t7
  bnezl $v0, .L7F067880
   lw    $v1, ($s0)
  lw    $t9, ($s0)
  jal   sub_GAME_7F0673B4
   lw    $a0, 0xfd8($t9)
  bnezl $v0, .L7F067894
   lw    $v1, ($s0)
  lw    $v1, ($s0)
.L7F067880:
  li    $t0, 1
  lw    $t5, 0xfd8($v1)
  subu  $t8, $t0, $t5
  sw    $t8, 0xfd8($v1)
  lw    $v1, ($s0)
.L7F067894:
  li    $t4, 1
  lw    $t1, 0xfd8($v1)
  sll   $t2, $t1, 2
  addu  $t6, $sp, $t2
  sw    $t4, 0x48($t6)
  lw    $t3, 0xfd8($v1)
  sll   $t7, $t3, 2
  negu  $t9, $t7
  addu  $t0, $sp, $t9
  b     .L7F06793C
   sw    $zero, 0x4c($t0)
.L7F0678C0:
  lw    $t5, ($s0)
.L7F0678C4:
  jal   get_item_in_hand
   lw    $a0, 0xfd8($t5)
  bnezl $v0, .L7F067908
   lw    $v1, ($s0)
  lw    $t8, ($s0)
  li    $t4, 1
  lw    $t1, 0xfd8($t8)
  jal   get_item_in_hand
   subu  $a0, $t4, $t1
  beql  $v0, $zero, .L7F067908
   lw    $v1, ($s0)
  lw    $v1, ($s0)
  li    $t6, 1
  lw    $t2, 0xfd8($v1)
  subu  $t3, $t6, $t2
  sw    $t3, 0xfd8($v1)
  lw    $v1, ($s0)
.L7F067908:
  li    $t7, 1
  lw    $t9, 0xfd8($v1)
  sll   $t0, $t9, 2
  addu  $t5, $sp, $t0
  sw    $t7, 0x48($t5)
  lw    $t8, 0xfd8($v1)
  sll   $t4, $t8, 2
  negu  $t1, $t4
  addu  $t6, $sp, $t1
  sw    $zero, 0x4c($t6)
  b     .L7F067940
   move  $a0, $zero
  sw    $zero, 0xfd4($v1)
.L7F06793C:
  move  $a0, $zero
.L7F067940:
  jal   handle_weapon_id_values_possibly_1st_person_animation
   lw    $a1, 0x48($sp)
  li    $a0, 1
  jal   handle_weapon_id_values_possibly_1st_person_animation
   lw    $a1, 0x4c($sp)
  jal   used_to_load_1st_person_model_on_demand
   move  $a0, $zero
  jal   used_to_load_1st_person_model_on_demand
   li    $a0, 1
  jal   sub_GAME_7F0671A4
   nop   
  lw    $t2, ($s0)
  lw    $t3, 0xfe0($t2)
  beqz  $t3, .L7F0679A0
   nop   
  jal   get_curplayer_positiondata
   nop   
  lw    $a1, ($s0)
  move  $a0, $v0
  jal   set_color_shading_from_tile
   addiu $a1, $a1, 0xfdc
  lw    $t9, ($s0)
  b     .L7F0679C4
   sw    $zero, 0xfe0($t9)
.L7F0679A0:
  jal   get_curplayer_positiondata
   nop   
  move  $a0, $v0
  jal   set_color_shading_from_tile
   addiu $a1, $sp, 0x38
  lw    $a0, ($s0)
  addiu $a1, $sp, 0x38
  jal   update_color_shading
   addiu $a0, $a0, 0xfdc
.L7F0679C4:
  jal   get_item_in_hand
   move  $a0, $zero
  sw    $v0, 0x2c($sp)
  jal   get_item_in_hand
   li    $a0, 1
  lw    $a0, 0x2c($sp)
  jal   sub_GAME_7F08D9EC
   move  $a1, $v0
  lw    $v1, ($s0)
  lui   $t7, %hi(clock_timer) 
  lw    $v0, 0x1270($v1)
  bltzl $v0, .L7F067A94
   lw    $ra, 0x1c($sp)
  lw    $t7, %lo(clock_timer)($t7)
  addiu $a3, $v1, 0x870
  li    $t8, -1
  addu  $t0, $v0, $t7
  sw    $t0, 0x1270($v1)
  lw    $v1, ($s0)
  lw    $t5, 0x1270($v1)
  slti  $at, $t5, 0x12c
  beql  $at, $zero, .L7F067A6C
   sw    $t8, 0x1270($v1)
  lw    $a0, 0x1d4($a3)
  beqz  $a0, .L7F067A3C
   nop   
  jal   sfxGetArg0Unk3F
   sw    $a3, 0x34($sp)
  bnez  $v0, .L7F067A90
   lw    $a3, 0x34($sp)
.L7F067A3C:
  jal   get_controls_locked_flag
   sw    $a3, 0x34($sp)
  bnez  $v0, .L7F067A90
   lw    $a3, 0x34($sp)
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 246
  jal   play_sfx_a1
   addiu $a2, $a3, 0x1d4
  b     .L7F067A94
   lw    $ra, 0x1c($sp)
  sw    $t8, 0x1270($v1)
.L7F067A6C:
  lw    $a0, 0x1d4($a3)
  beql  $a0, $zero, .L7F067A94
   lw    $ra, 0x1c($sp)
  jal   sfxGetArg0Unk3F
   sw    $a3, 0x34($sp)
  beqz  $v0, .L7F067A90
   lw    $a3, 0x34($sp)
  jal   sfxDeactivate
   lw    $a0, 0x1d4($a3)
.L7F067A90:
  lw    $ra, 0x1c($sp)
.L7F067A94:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x50
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F067AA4
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  jr    $ra
   sw    $a0, 0xfe4($t6)
");

asm(R"
glabel sub_GAME_7F067AB4
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  move  $a1, $a0
  sw    $a1, 0x18($sp)
  jal   sub_GAME_7F05DCB8
   move  $a0, $zero
  lw    $a1, 0x18($sp)
  lui   $v0, %hi(pPlayer)
  addiu $v0, %lo(pPlayer) # addiu $v0, $v0, -0x5f50
  lwc1  $f4, ($a1)
  lw    $t6, ($v0)
  li    $a0, 1
  add.s $f6, $f0, $f4
  swc1  $f6, 0xa38($t6)
  lw    $t7, ($v0)
  lwc1  $f8, 4($a1)
  swc1  $f8, 0xa3c($t7)
  lw    $t8, ($v0)
  lwc1  $f10, 8($a1)
  jal   sub_GAME_7F05DCB8
   swc1  $f10, 0xa40($t8)
  lw    $a1, 0x18($sp)
  lui   $v0, %hi(pPlayer)
  addiu $v0, %lo(pPlayer) # addiu $v0, $v0, -0x5f50
  lwc1  $f16, ($a1)
  lw    $t9, ($v0)
  add.s $f18, $f0, $f16
  swc1  $f18, 0xde0($t9)
  lw    $t0, ($v0)
  lwc1  $f4, 4($a1)
  swc1  $f4, 0xde4($t0)
  lw    $t1, ($v0)
  lwc1  $f6, 8($a1)
  swc1  $f6, 0xde8($t1)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F067B4C
  lui   $v0, %hi(pPlayer)
  addiu $v0, %lo(pPlayer) # addiu $v0, $v0, -0x5f50
  lw    $t6, ($v0)
  lwc1  $f0, ($a0)
  swc1  $f0, 0xc0c($t6)
  lw    $t7, ($v0)
  swc1  $f0, 0xfb4($t7)
  lw    $t8, ($v0)
  lwc1  $f0, 4($a0)
  swc1  $f0, 0xc10($t8)
  lw    $t9, ($v0)
  swc1  $f0, 0xfb8($t9)
  lw    $t0, ($v0)
  lwc1  $f0, 8($a0)
  swc1  $f0, 0xc14($t0)
  lw    $t1, ($v0)
  jr    $ra
   swc1  $f0, 0xfbc($t1)
");

asm(R"
glabel caclulate_gun_crosshair_position_rotation
  addiu $sp, $sp, -0x58
  sdc1  $f22, 0x18($sp)
  sdc1  $f20, 0x10($sp)
  mtc1  $a2, $f20
  mtc1  $a3, $f22
  sw    $ra, 0x24($sp)
  swc1  $f12, 0x58($sp)
  jal   getPlayer_c_screenwidth
   swc1  $f14, 0x5c($sp)
  jal   getPlayer_c_screenheight
   swc1  $f0, 0x50($sp)
  lui   $a3, %hi(pPlayer)
  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
  lw    $v0, ($a3)
  swc1  $f0, 0x4c($sp)
  lwc1  $f12, 0x58($sp)
  lwc1  $f18, 0xff8($v0)
  lwc1  $f14, 0x5c($sp)
  lui   $a0, %hi(clock_timer)
  c.eq.s $f20, $f18
  nop   
  bc1t  .L7F067C34
   li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f16
  lwc1  $f4, 0xff0($v0)
  sub.s $f6, $f16, $f18
  sub.s $f2, $f16, $f20
  mul.s $f8, $f4, $f6
  div.s $f10, $f8, $f2
  swc1  $f10, 0xff0($v0)
  lw    $v0, ($a3)
  lwc1  $f6, 0xff8($v0)
  lwc1  $f4, 0xff4($v0)
  sub.s $f8, $f16, $f6
  mul.s $f10, $f4, $f8
  div.s $f6, $f10, $f2
  swc1  $f6, 0xff4($v0)
  lw    $t6, ($a3)
  swc1  $f20, 0xff8($t6)
  lw    $v0, ($a3)
.L7F067C34:
  lwc1  $f18, 0x100c($v0)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f16
  c.eq.s $f22, $f18
  li    $at, 0x3F800000 # 1.000000
  sub.s $f2, $f16, $f20
  bc1tl .L7F067CA0
   mtc1  $at, $f4
  sub.s $f4, $f16, $f22
  sub.s $f10, $f16, $f18
  swc1  $f4, 0x2c($sp)
  lwc1  $f8, 0x1004($v0)
  lwc1  $f4, 0x2c($sp)
  mul.s $f6, $f8, $f10
  div.s $f8, $f6, $f4
  swc1  $f8, 0x1004($v0)
  lw    $v0, ($a3)
  lwc1  $f6, 0x100c($v0)
  lwc1  $f10, 0x1008($v0)
  sub.s $f4, $f16, $f6
  lwc1  $f6, 0x2c($sp)
  mul.s $f8, $f10, $f4
  div.s $f10, $f8, $f6
  swc1  $f10, 0x1008($v0)
  lw    $t7, ($a3)
  swc1  $f22, 0x100c($t7)
  mtc1  $at, $f4
.L7F067CA0:
  addiu $a0, %lo(clock_timer) # addiu $a0, $a0, -0x7c8c
  lw    $t8, ($a0)
  sub.s $f8, $f4, $f22
  move  $v1, $zero
  blez  $t8, .L7F067CF8
   swc1  $f8, 0x30($sp)
  lw    $v0, ($a3)
.L7F067CBC:
  addiu $v1, $v1, 1
  lwc1  $f6, 0xff0($v0)
  mul.s $f10, $f6, $f20
  add.s $f4, $f10, $f12
  swc1  $f4, 0xff0($v0)
  lw    $v0, ($a3)
  lwc1  $f8, 0xff4($v0)
  mul.s $f6, $f8, $f20
  add.s $f10, $f6, $f14
  swc1  $f10, 0xff4($v0)
  lw    $t9, ($a0)
  slt   $at, $v1, $t9
  bnezl $at, .L7F067CBC
   lw    $v0, ($a3)
  move  $v1, $zero
.L7F067CF8:
  li    $at, 0x40400000 # 3.000000
  mtc1  $at, $f18
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f20
  lwc1  $f4, 0x50($sp)
  lw    $v0, ($a3)
  li    $at, 0x40800000 # 4.000000
  mul.s $f8, $f4, $f20
  swc1  $f8, 0x2c($sp)
  lwc1  $f6, 0xff0($v0)
  mul.s $f10, $f6, $f2
  nop   
  mul.s $f6, $f10, $f4
  nop   
  mul.s $f10, $f6, $f20
  add.s $f4, $f10, $f8
  swc1  $f4, 0xfe8($v0)
  lw    $v0, ($a3)
  lwc1  $f6, 0xff4($v0)
  mul.s $f10, $f6, $f2
  nop   
  mul.s $f8, $f10, $f0
  nop   
  mul.s $f4, $f8, $f20
  nop   
  mul.s $f6, $f0, $f20
  add.s $f10, $f4, $f6
  swc1  $f10, 0xfec($v0)
  lw    $v0, ($a3)
  lwc1  $f8, 0x50($sp)
  lwc1  $f16, 0xfe8($v0)
  c.lt.s $f16, $f18
  nop   
  bc1f  .L7F067D90
   nop   
  swc1  $f18, 0xfe8($v0)
  b     .L7F067DB4
   lw    $v0, ($a3)
.L7F067D90:
  mtc1  $at, $f4
  nop   
  sub.s $f2, $f8, $f4
  c.lt.s $f2, $f16
  nop   
  bc1fl .L7F067DB8
   lwc1  $f2, 0xfec($v0)
  swc1  $f2, 0xfe8($v0)
  lw    $v0, ($a3)
.L7F067DB4:
  lwc1  $f2, 0xfec($v0)
.L7F067DB8:
  li    $at, 0x40800000 # 4.000000
  c.lt.s $f2, $f18
  nop   
  bc1fl .L7F067DD8
   mtc1  $at, $f6
  b     .L7F067DF4
   swc1  $f18, 0xfec($v0)
  mtc1  $at, $f6
.L7F067DD8:
  nop   
  sub.s $f16, $f0, $f6
  c.lt.s $f16, $f2
  nop   
  bc1fl .L7F067DF8
   sw    $v1, 0x54($sp)
  swc1  $f16, 0xfec($v0)
.L7F067DF4:
  sw    $v1, 0x54($sp)
.L7F067DF8:
  swc1  $f12, 0x58($sp)
  jal   getPlayer_c_screenleft
   swc1  $f14, 0x5c($sp)
  lui   $a3, %hi(pPlayer)
  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
  lw    $v0, ($a3)
  lwc1  $f10, 0xfe8($v0)
  add.s $f8, $f10, $f0
  jal   getPlayer_c_screentop
   swc1  $f8, 0xfe8($v0)
  lui   $a3, %hi(pPlayer)
  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
  lw    $v0, ($a3)
  lw    $v1, 0x54($sp)
  lui   $a0, %hi(clock_timer)
  lwc1  $f4, 0xfec($v0)
  lwc1  $f12, 0x58($sp)
  lwc1  $f14, 0x5c($sp)
  add.s $f6, $f4, $f0
  addiu $a0, %lo(clock_timer) # addiu $a0, $a0, -0x7c8c
  swc1  $f6, 0xfec($v0)
  lw    $t0, ($a0)
  blezl $t0, .L7F067E98
   lw    $v0, ($a3)
  lw    $v0, ($a3)
.L7F067E5C:
  addiu $v1, $v1, 1
  lwc1  $f10, 0x1004($v0)
  mul.s $f8, $f10, $f22
  add.s $f4, $f8, $f12
  swc1  $f4, 0x1004($v0)
  lw    $v0, ($a3)
  lwc1  $f6, 0x1008($v0)
  mul.s $f10, $f6, $f22
  add.s $f8, $f10, $f14
  swc1  $f8, 0x1008($v0)
  lw    $t1, ($a0)
  slt   $at, $v1, $t1
  bnezl $at, .L7F067E5C
   lw    $v0, ($a3)
  lw    $v0, ($a3)
.L7F067E98:
  lwc1  $f0, 0x30($sp)
  lwc1  $f10, 0x50($sp)
  lwc1  $f4, 0x1004($v0)
  lwc1  $f2, 0x4c($sp)
  mul.s $f6, $f4, $f0
  nop   
  mul.s $f8, $f6, $f10
  lwc1  $f6, 0x2c($sp)
  mul.s $f4, $f8, $f20
  add.s $f10, $f4, $f6
  swc1  $f10, 0xffc($v0)
  lw    $v0, ($a3)
  lwc1  $f8, 0x1008($v0)
  mul.s $f4, $f8, $f0
  nop   
  mul.s $f6, $f4, $f2
  nop   
  mul.s $f10, $f6, $f20
  nop   
  mul.s $f8, $f2, $f20
  add.s $f4, $f10, $f8
  jal   getPlayer_c_screenleft
   swc1  $f4, 0x1000($v0)
  lui   $a3, %hi(pPlayer)
  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
  lw    $v0, ($a3)
  lwc1  $f6, 0xffc($v0)
  add.s $f10, $f6, $f0
  jal   getPlayer_c_screentop
   swc1  $f10, 0xffc($v0)
  lui   $a3, %hi(pPlayer)
  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
  lw    $v0, ($a3)
  addiu $a1, $sp, 0x40
  lui   $a2, 0x447a
  lwc1  $f8, 0x1000($v0)
  add.s $f4, $f8, $f0
  swc1  $f4, 0x1000($v0)
  lw    $a0, ($a3)
  jal   sub_GAME_7F077EEC
   addiu $a0, $a0, 0xffc
  jal   sub_GAME_7F067AB4
   addiu $a0, $sp, 0x40
  lw    $ra, 0x24($sp)
  ldc1  $f20, 0x10($sp)
  ldc1  $f22, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x58
");

asm(R"
glabel sub_GAME_7F067F58
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  swc1  $f12, 0x18($sp)
  swc1  $f14, 0x1c($sp)
  sw    $a2, 0x20($sp)
  jal   get_item_in_hand
   move  $a0, $zero
  jal   get_ptr_item_statistics
   move  $a0, $v0
  lwc1  $f2, 0x20($sp)
  lwc1  $f0, 0x3c($v0)
  lwc1  $f12, 0x18($sp)
  mfc1  $a2, $f2
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F067FA4
   mfc1  $a3, $f0
  mov.s $f0, $f2
  mfc1  $a3, $f0
.L7F067FA4:
  jal   caclulate_gun_crosshair_position_rotation
   lwc1  $f14, 0x1c($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

#ifdef VERSION_US
asm(R"
glabel sub_GAME_7F067FBC
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  swc1  $f12, 0x18($sp)
  swc1  $f14, 0x1c($sp)
  jal   get_item_in_hand
   move  $a0, $zero
  jal   get_ptr_item_statistics
   move  $a0, $v0
  lwc1  $f0, 0x38($v0)
  lwc1  $f2, 0x3c($v0)
  lwc1  $f12, 0x18($sp)
  mfc1  $a2, $f0
  mfc1  $a3, $f2
  jal   caclulate_gun_crosshair_position_rotation
   lwc1  $f14, 0x1c($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

#ifdef VERSION_JP
asm(R"
glabel sub_GAME_7F067FBC
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  swc1  $f12, 0x18($sp)
  swc1  $f14, 0x1c($sp)
  jal   get_item_in_hand
   move  $a0, $zero
  jal   get_ptr_item_statistics
   move  $a0, $v0
  lwc1  $f0, 0x3c($v0)
  lui   $a2, (0x3F4CCCCD >> 16) # lui $a2, 0x3f4c
  ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
  mfc1  $a3, $f0
  lwc1  $f12, 0x18($sp)
  jal   caclulate_gun_crosshair_position_rotation
   lwc1  $f14, 0x1c($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");
#endif

#endif

asm(R"
glabel sub_GAME_7F068008
  lui   $v0, %hi(pPlayer)
  addiu $v0, %lo(pPlayer) # addiu $v0, $v0, -0x5f50
  lw    $t6, ($v0)
  lwc1  $f4, 0xfe8($t6)
  swc1  $f4, ($a0)
  lw    $t7, ($v0)
  lwc1  $f6, 0xfec($t7)
  jr    $ra
   swc1  $f6, ($a1)
");

asm(R"
glabel sub_GAME_7F06802C
  addiu $sp, $sp, -0x30
  sw    $ra, 0x14($sp)
  jal   getPlayer_c_screenleft
   nop   
  jal   getPlayer_c_screenwidth
   swc1  $f0, 0x1c($sp)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f4
  lwc1  $f8, 0x1c($sp)
  lui   $v0, %hi(pPlayer)
  mul.s $f6, $f0, $f4
  addiu $v0, %lo(pPlayer) # addiu $v0, $v0, -0x5f50
  lw    $t6, ($v0)
  add.s $f2, $f6, $f8
  swc1  $f2, 0xfe8($t6)
  lw    $t7, ($v0)
  jal   getPlayer_c_screentop
   swc1  $f2, 0xffc($t7)
  jal   getPlayer_c_screenheight
   swc1  $f0, 0x1c($sp)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f10
  lwc1  $f18, 0x1c($sp)
  lui   $v0, %hi(pPlayer)
  mul.s $f16, $f0, $f10
  addiu $v0, %lo(pPlayer) # addiu $v0, $v0, -0x5f50
  lw    $t8, ($v0)
  addiu $a1, $sp, 0x24
  lui   $a2, 0x447a
  add.s $f2, $f16, $f18
  swc1  $f2, 0xfec($t8)
  lw    $t9, ($v0)
  swc1  $f2, 0x1000($t9)
  lw    $a0, ($v0)
  jal   sub_GAME_7F077EEC
   addiu $a0, $a0, 0xffc
  jal   sub_GAME_7F067AB4
   addiu $a0, $sp, 0x24
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0680D4
  addiu $sp, $sp, -0x28
  lui   $v1, %hi(pPlayer)
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  sw    $ra, 0x14($sp)
  lwc1  $f4, ($a0)
  lw    $t6, ($v1)
  swc1  $f4, 0x1010($t6)
  lw    $t7, ($v1)
  lwc1  $f6, 4($a0)
  swc1  $f6, 0x1014($t7)
  lw    $t8, ($v1)
  lwc1  $f8, 8($a0)
  swc1  $f8, 0x1018($t8)
  lw    $a1, ($v1)
  jal   sub_GAME_7F058714
   addiu $a1, $a1, 0x101c
  lui   $v1, %hi(pPlayer)
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $v0, ($v1)
  li    $at, 0x447A0000 # 1000.000000
  mtc1  $at, $f0
  lwc1  $f10, 0x103c($v0)
  addiu $a0, $sp, 0x1c
  addiu $a1, $v0, 0xfe8
  mul.s $f16, $f10, $f0
  swc1  $f16, 0x1c($sp)
  lwc1  $f18, 0x1040($v0)
  mul.s $f4, $f18, $f0
  swc1  $f4, 0x20($sp)
  lwc1  $f6, 0x1044($v0)
  mul.s $f8, $f6, $f0
  jal   sub_GAME_7F077FF4
   swc1  $f8, 0x24($sp)
  lui   $v1, %hi(pPlayer)
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $v0, ($v1)
  addiu $a0, $sp, 0x1c
  lwc1  $f10, 0xfe8($v0)
  swc1  $f10, 0xffc($v0)
  lw    $v0, ($v1)
  lwc1  $f16, 0xfec($v0)
  jal   sub_GAME_7F067AB4
   swc1  $f16, 0x1000($v0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F068190
  mtc1  $zero, $f0
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  swc1  $f0, ($a0)
  swc1  $f0, 4($a0)
  swc1  $f0, 8($a0)
  lui   $a0, %hi(pPlayer)
  lw    $a0, %lo(pPlayer)($a0)
  lui   $a2, 0x3f80
  jal   sub_GAME_7F077EEC
   addiu $a0, $a0, 0xfe8
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_800543B0
.word 0x3faaaaab /*1.3333334*/
.text
glabel sub_GAME_7F0681CC
  addiu $sp, $sp, -0x38
  sw    $ra, 0x14($sp)
  sw    $a0, 0x38($sp)
  sw    $a1, 0x3c($sp)
  sw    $a2, 0x40($sp)
  jal   get_item_in_hand
   move  $a0, $a2
  jal   get_ptr_item_statistics
   move  $a0, $v0
  lwc1  $f4, 0x30($v0)
  lw    $a0, 0x40($sp)
  jal   return_ammo_in_hand
   swc1  $f4, 0x28($sp)
  move  $a0, $v0
  jal   check_special_attributes
   li    $a1, 4096
  beqz  $v0, .L7F068264
   nop   
  lw    $t7, 0x40($sp)
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  sll   $t8, $t7, 3
  subu  $t8, $t8, $t7
  sll   $t8, $t8, 2
  addu  $t8, $t8, $t7
  sll   $t8, $t8, 2
  addu  $t8, $t8, $t7
  sll   $t8, $t8, 3
  addu  $t9, $t6, $t8
  lw    $t0, 0xc08($t9)
  li    $at, 1
  lwc1  $f6, 0x28($sp)
  bne   $t0, $at, .L7F068264
   li    $at, 0x3E800000 # 0.250000
  mtc1  $at, $f8
  nop   
  mul.s $f10, $f6, $f8
  swc1  $f10, 0x28($sp)
.L7F068264:
  jal   video_related_23
   nop   
  li    $at, 0x42F00000 # 120.000000
  mtc1  $at, $f16
  lwc1  $f18, 0x28($sp)
  mul.s $f4, $f16, $f18
  div.s $f6, $f4, $f0
  jal   get_random_value
   swc1  $f6, 0x24($sp)
  jal   get_random_value
   sw    $v0, 0x1c($sp)
  lw    $t1, 0x1c($sp)
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f0
  mtc1  $t1, $f8
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $t1, .L7F0682B8
   cvt.s.w $f10, $f8
  mtc1  $at, $f16
  nop   
  add.s $f10, $f10, $f16
.L7F0682B8:
  mul.s $f18, $f10, $f0
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f4
  mtc1  $v0, $f8
  li    $at, 0x4F800000 # 4294967296.000000
  cvt.s.w $f16, $f8
  bgez  $v0, .L7F0682E4
   sub.s $f6, $f18, $f4
  mtc1  $at, $f10
  nop   
  add.s $f16, $f16, $f10
.L7F0682E4:
  mul.s $f18, $f16, $f0
  nop   
  mul.s $f4, $f18, $f6
  jal   getPlayer_c_screenwidth
   swc1  $f4, 0x20($sp)
  jal   getPlayer_c_perspaspect
   swc1  $f0, 0x18($sp)
  lwc1  $f8, 0x20($sp)
  lwc1  $f10, 0x24($sp)
  lwc1  $f18, 0x18($sp)
  lui   $at, %hi(D_800543B0)
  mul.s $f16, $f8, $f10
  lwc1  $f4, %lo(D_800543B0)($at)
  li    $at, 0x43A00000 # 320.000000
  mtc1  $at, $f10
  lui   $t2, %hi(pPlayer) 
  lw    $t2, %lo(pPlayer)($t2)
  mul.s $f6, $f16, $f18
  nop   
  mul.s $f8, $f6, $f4
  lwc1  $f6, 0xfe8($t2)
  mul.s $f16, $f0, $f10
  div.s $f18, $f8, $f16
  add.s $f4, $f18, $f6
  jal   get_random_value
   swc1  $f4, 0x30($sp)
  jal   get_random_value
   sw    $v0, 0x1c($sp)
  lw    $t3, 0x1c($sp)
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f0
  mtc1  $t3, $f10
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $t3, .L7F06837C
   cvt.s.w $f8, $f10
  mtc1  $at, $f16
  nop   
  add.s $f8, $f8, $f16
.L7F06837C:
  mul.s $f18, $f8, $f0
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f6
  mtc1  $v0, $f10
  li    $at, 0x4F800000 # 4294967296.000000
  cvt.s.w $f16, $f10
  bgez  $v0, .L7F0683A8
   sub.s $f4, $f18, $f6
  mtc1  $at, $f8
  nop   
  add.s $f16, $f16, $f8
.L7F0683A8:
  mul.s $f18, $f16, $f0
  nop   
  mul.s $f6, $f18, $f4
  jal   getPlayer_c_screenheight
   swc1  $f6, 0x20($sp)
  lwc1  $f10, 0x20($sp)
  lwc1  $f8, 0x24($sp)
  li    $at, 0x43700000 # 240.000000
  mtc1  $at, $f4
  mul.s $f16, $f10, $f8
  lui   $t4, %hi(pPlayer) 
  lw    $t4, %lo(pPlayer)($t4)
  lw    $v0, 0x38($sp)
  mtc1  $zero, $f2
  lwc1  $f10, 0xfec($t4)
  addiu $a0, $sp, 0x30
  mul.s $f18, $f0, $f16
  lui   $a2, 0x3f80
  div.s $f6, $f18, $f4
  add.s $f8, $f6, $f10
  swc1  $f8, 0x34($sp)
  swc1  $f2, ($v0)
  swc1  $f2, 4($v0)
  swc1  $f2, 8($v0)
  jal   sub_GAME_7F077EEC
   lw    $a1, 0x3c($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F068420
  lui   $t6, %hi(dword_CODE_bss_80075E64) 
  lw    $t6, %lo(dword_CODE_bss_80075E64)($t6)
  lui   $v1, %hi(dword_CODE_bss_80075DC8)
  addiu $v1, %lo(dword_CODE_bss_80075DC8) # addiu $v1, $v1, 0x5dc8
  beqz  $t6, .L7F068458
   lui   $v0, %hi(dword_CODE_bss_80076A48)
  addiu $v0, %lo(dword_CODE_bss_80076A48) # addiu $v0, $v0, 0x6a48
  addiu $v1, $v1, 0xa0
.L7F068440:
  sltu  $at, $v1, $v0
  beqz  $at, .L7F068458
   nop   
  lw    $t7, 0x9c($v1)
  bnezl $t7, .L7F068440
   addiu $v1, $v1, 0xa0
.L7F068458:
  lui   $v0, %hi(dword_CODE_bss_80076A48)
  addiu $v0, %lo(dword_CODE_bss_80076A48) # addiu $v0, $v0, 0x6a48
  sltu  $at, $v1, $v0
  beqz  $at, .L7F068500
   move  $v0, $zero
  sw    $a0, 0x9c($v1)
  lwc1  $f4, 0x30($a1)
  mtc1  $zero, $f0
  li    $at, 0x3F800000 # 1.000000
  swc1  $f4, 4($v1)
  lwc1  $f6, 0x34($a1)
  move  $v0, $v1
  swc1  $f6, 8($v1)
  lwc1  $f8, 0x38($a1)
  swc1  $f8, 0xc($v1)
  lwc1  $f10, ($a1)
  swc1  $f10, 0x1c($v1)
  lwc1  $f16, 4($a1)
  swc1  $f16, 0x20($v1)
  lwc1  $f18, 8($a1)
  swc1  $f0, 0x28($v1)
  swc1  $f18, 0x24($v1)
  lwc1  $f4, 0x10($a1)
  swc1  $f4, 0x2c($v1)
  lwc1  $f6, 0x14($a1)
  mtc1  $at, $f4
  swc1  $f6, 0x30($v1)
  lwc1  $f8, 0x18($a1)
  swc1  $f0, 0x38($v1)
  swc1  $f8, 0x34($v1)
  lwc1  $f10, 0x20($a1)
  swc1  $f10, 0x3c($v1)
  lwc1  $f16, 0x24($a1)
  swc1  $f16, 0x40($v1)
  lwc1  $f18, 0x28($a1)
  swc1  $f0, 0x48($v1)
  swc1  $f0, 0x4c($v1)
  swc1  $f0, 0x50($v1)
  swc1  $f0, 0x54($v1)
  swc1  $f4, 0x58($v1)
  jr    $ra
   swc1  $f18, 0x44($v1)

.L7F068500:
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_800543B4
.word 0x3dccccce /*0.10000001*/
glabel D_800543B8
.word 0x3f088888 /*0.5333333*/
glabel D_800543BC
.word 0x40c90fdb /*6.2831855*/
glabel D_800543C0
.word 0x3ec90fdb /*0.39269909*/
glabel D_800543C4
.word 0x40c90fdb /*6.2831855*/
glabel D_800543C8
.word 0x3ec90fdb /*0.39269909*/
glabel D_800543CC
.word 0x40c90fdb /*6.2831855*/
glabel D_800543D0
.word 0x3ec90fdb /*0.39269909*/
glabel D_800543D4
.word 0x493d6c30 /*775875.0*/
glabel expended_shell_initial_gravity_modifier_pistol
.word 0x3e8e38e4 /*0.27777779*/
glabel D_800543DC
.word 0x3fb55555 /*1.4166666*/
glabel D_800543E0
.word 0x3fd55555 /*1.6666666*/
glabel D_800543E4
.word 0x40c90fdb /*6.2831855*/
glabel D_800543E8
.word 0x3ec90fdb /*0.39269909*/
glabel D_800543EC
.word 0x40c90fdb /*6.2831855*/
glabel D_800543F0
.word 0x3ec90fdb /*0.39269909*/
glabel D_800543F4
.word 0x40c90fdb /*6.2831855*/
glabel D_800543F8
.word 0x3ec90fdb /*0.39269909*/
glabel D_800543FC
.word 0x493d6c30 /*775875.0*/
glabel expended_shell_initial_gravity_modifier_non_pistol
.word 0x3e8e38e4 /*0.27777779*/
.text
glabel sub_GAME_7F068508
  addiu $sp, $sp, -0xc0
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x14($sp)
  move  $s0, $a0
  sw    $s1, 0x18($sp)
  jal   get_item_in_hand
   sw    $a1, 0xc4($sp)
  sw    $v0, 0x78($sp)
  jal   get_ptr_item_statistics
   move  $a0, $v0
  lw    $v1, 0x28($v0)
  beql  $v1, $zero, .L7F068D10
   lw    $ra, 0x1c($sp)
  jal   getPlayerCount
   sw    $v1, 0x70($sp)
  slti  $at, $v0, 2
  beqz  $at, .L7F068D0C
   lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  sll   $t6, $s0, 5
  sll   $s1, $s0, 3
  addu  $t7, $v0, $t6
  lw    $t8, 0x818($t7)
  subu  $s1, $s1, $s0
  sll   $s1, $s1, 2
  lw    $v1, ($t8)
  addu  $s1, $s1, $s0
  sll   $s1, $s1, 2
  beqz  $v1, .L7F0685F8
   addu  $s1, $s1, $s0
  lw    $v0, 4($v1)
  lui   $at, %hi(D_800543B4)
  lwc1  $f0, %lo(D_800543B4)($at)
  lwc1  $f4, ($v0)
  addiu $a0, $sp, 0x64
  addiu $a1, $sp, 0x7c
  mul.s $f6, $f4, $f0
  swc1  $f6, 0x64($sp)
  lwc1  $f8, 4($v0)
  mul.s $f10, $f8, $f0
  swc1  $f10, 0x68($sp)
  lwc1  $f18, 8($v0)
  mul.s $f4, $f18, $f0
  jal   init_something_copy_posdata_to_it
   swc1  $f4, 0x6c($sp)
  sll   $s1, $s0, 3
  subu  $s1, $s1, $s0
  sll   $s1, $s1, 2
  addu  $s1, $s1, $s0
  lui   $t9, %hi(pPlayer) 
  lw    $t9, %lo(pPlayer)($t9)
  sll   $s1, $s1, 2
  addu  $s1, $s1, $s0
  sll   $s1, $s1, 3
  addu  $a0, $t9, $s1
  addiu $a0, $a0, 0xad8
  jal   matrix_4x4_multiply_in_place
   addiu $a1, $sp, 0x7c
  b     .L7F068610
   lw    $a0, 0x70($sp)
.L7F0685F8:
  sll   $s1, $s1, 3
  addu  $a0, $v0, $s1
  addiu $a0, $a0, 0xad8
  jal   matrix_4x4_copy
   addiu $a1, $sp, 0x7c
  lw    $a0, 0x70($sp)
.L7F068610:
  jal   sub_GAME_7F068420
   addiu $a1, $sp, 0x7c
  beqz  $v0, .L7F068D0C
   move  $s0, $v0
  lui   $t1, %hi(D_80035EA4) 
  addiu $t1, %lo(D_80035EA4) # addiu $t1, $t1, 0x5ea4
  lw    $at, ($t1)
  lw    $v1, 0x78($sp)
  addiu $t0, $sp, 0x54
  sw    $at, ($t0)
  lw    $at, 8($t1)
  lw    $t3, 4($t1)
  sw    $at, 8($t0)
  sw    $t3, 4($t0)
  lwc1  $f6, 0xc4($sp)
  li    $at, 4
  beq   $v1, $at, .L7F06867C
   swc1  $f6, ($v0)
  li    $at, 5
  beq   $v1, $at, .L7F06867C
   li    $at, 6
  beq   $v1, $at, .L7F06867C
   li    $at, 20
  beq   $v1, $at, .L7F06867C
   li    $at, 21
  bne   $v1, $at, .L7F0689C4
   nop   
.L7F06867C:
  jal   get_random_value
   nop   
  mtc1  $v0, $f8
  lui   $at, %hi(D_800543B8)
  lwc1  $f0, %lo(D_800543B8)($at)
  bgez  $v0, .L7F0686A8
   cvt.s.w $f10, $f8
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f18
  nop   
  add.s $f10, $f10, $f18
.L7F0686A8:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f4
  li    $at, 0x3D800000 # 0.062500
  mtc1  $at, $f18
  mul.s $f6, $f10, $f4
  nop   
  mul.s $f8, $f6, $f0
  nop   
  mul.s $f10, $f8, $f18
  add.s $f4, $f10, $f0
  neg.s $f6, $f4
  jal   get_random_value
   swc1  $f6, 0x10($s0)
  mtc1  $v0, $f8
  li    $at, 0x40200000 # 2.500000
  mtc1  $at, $f0
  bgez  $v0, .L7F068700
   cvt.s.w $f18, $f8
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f10
  nop   
  add.s $f18, $f18, $f10
.L7F068700:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f4
  li    $at, 0x3D800000 # 0.062500
  mtc1  $at, $f10
  mul.s $f6, $f18, $f4
  lui   $t4, %hi(pPlayer) 
  addiu $a1, $s0, 0x10
  mul.s $f8, $f6, $f0
  mtc1  $zero, $f6
  nop   
  swc1  $f6, 0x18($s0)
  mul.s $f18, $f8, $f10
  add.s $f4, $f18, $f0
  swc1  $f4, 0x14($s0)
  lw    $t4, %lo(pPlayer)($t4)
  addu  $a0, $t4, $s1
  jal   sub_GAME_7F0583D8
   addiu $a0, $a0, 0xad8
  jal   get_random_value
   nop   
  mtc1  $v0, $f8
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F06876C
   cvt.s.w $f10, $f8
  mtc1  $at, $f18
  nop   
  add.s $f10, $f10, $f18
.L7F06876C:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f4
  lui   $at, %hi(D_800543BC)
  lwc1  $f8, %lo(D_800543BC)($at)
  mul.s $f0, $f10, $f4
  li    $at, 0x3D800000 # 0.062500
  mtc1  $at, $f10
  lui   $at, %hi(D_800543C0)
  add.s $f6, $f0, $f0
  mul.s $f18, $f6, $f8
  lwc1  $f6, %lo(D_800543C0)($at)
  mul.s $f4, $f18, $f10
  sub.s $f8, $f4, $f6
  jal   get_random_value
   swc1  $f8, 0x54($sp)
  mtc1  $v0, $f18
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F0687C4
   cvt.s.w $f10, $f18
  mtc1  $at, $f4
  nop   
  add.s $f10, $f10, $f4
.L7F0687C4:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f6
  lui   $at, %hi(D_800543C4)
  lwc1  $f18, %lo(D_800543C4)($at)
  mul.s $f0, $f10, $f6
  li    $at, 0x3D800000 # 0.062500
  mtc1  $at, $f10
  lui   $at, %hi(D_800543C8)
  add.s $f8, $f0, $f0
  mul.s $f4, $f8, $f18
  lwc1  $f8, %lo(D_800543C8)($at)
  mul.s $f6, $f4, $f10
  sub.s $f18, $f6, $f8
  jal   get_random_value
   swc1  $f18, 0x58($sp)
  mtc1  $v0, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F06881C
   cvt.s.w $f10, $f4
  mtc1  $at, $f6
  nop   
  add.s $f10, $f10, $f6
.L7F06881C:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f8
  lui   $at, %hi(D_800543CC)
  lwc1  $f4, %lo(D_800543CC)($at)
  mul.s $f0, $f10, $f8
  li    $at, 0x3D800000 # 0.062500
  mtc1  $at, $f10
  lui   $at, %hi(D_800543D0)
  addiu $a0, $sp, 0x54
  addiu $a1, $s0, 0x5c
  add.s $f18, $f0, $f0
  mul.s $f6, $f18, $f4
  lwc1  $f18, %lo(D_800543D0)($at)
  mul.s $f8, $f6, $f10
  sub.s $f4, $f8, $f18
  jal   sub_GAME_7F058714
   swc1  $f4, 0x5c($sp)
  jal   get_random_value
   nop   
  lui   $v1, (0x00158679 >> 16) # lui $v1, 0x15
  ori   $v1, (0x00158679 & 0xFFFF) # ori $v1, $v1, 0x8679
  srl   $t5, $v0, 0x18
  multu $t5, $v1
  mflo  $t6
  sra   $t7, $t6, 0xa
  addu  $t8, $t7, $v1
  jal   get_random_value
   sw    $t8, 0x4c($sp)
  lw    $t9, 0x4c($sp)
  lwc1  $f12, 0x14($s0)
  li    $at, 0x4F800000 # 4294967296.000000
  divu  $zero, $v0, $t9
  mfhi  $t2
  mtc1  $t2, $f6
  bnez  $t9, .L7F0688B0
   nop   
  break 7
.L7F0688B0:
  lui   $a0, %hi(pPlayer)
  bgez  $t2, .L7F0688C8
   cvt.s.w $f10, $f6
  mtc1  $at, $f8
  nop   
  add.s $f10, $f10, $f8
.L7F0688C8:
  lui   $at, %hi(D_800543D4)
  lwc1  $f18, %lo(D_800543D4)($at)
  lui   $at, %hi(expended_shell_initial_gravity_modifier_pistol)
  lwc1  $f4, %lo(expended_shell_initial_gravity_modifier_pistol)($at)
  div.s $f0, $f10, $f18
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f18
  lwc1  $f14, 0x10($s0)
  lwc1  $f16, 0x18($s0)
  lui   $t0, %hi(clock_timer) 
  addiu $a0, %lo(pPlayer) # addiu $a0, $a0, -0x5f50
  mul.s $f6, $f0, $f4
  sub.s $f2, $f12, $f6
  lwc1  $f6, 8($s0)
  add.s $f8, $f12, $f2
  swc1  $f2, 0x14($s0)
  mul.s $f10, $f0, $f8
  nop   
  mul.s $f4, $f10, $f18
  lwc1  $f10, 4($s0)
  mul.s $f18, $f0, $f14
  add.s $f8, $f6, $f4
  lwc1  $f4, 0xc($s0)
  add.s $f6, $f10, $f18
  swc1  $f8, 8($s0)
  mul.s $f8, $f0, $f16
  swc1  $f6, 4($s0)
  add.s $f10, $f4, $f8
  swc1  $f10, 0xc($s0)
  lw    $t0, %lo(clock_timer)($t0)
  blez  $t0, .L7F068D0C
   nop   
  lw    $t1, ($a0)
  lui   $v1, %hi(global_timer_delta)
  addiu $v1, %lo(global_timer_delta) # addiu $v1, $v1, -0x7c88
  addu  $v0, $t1, $s1
  lwc1  $f18, 0xb08($v0)
  lwc1  $f6, 0xb48($v0)
  lwc1  $f8, ($v1)
  sub.s $f4, $f18, $f6
  div.s $f10, $f4, $f8
  add.s $f18, $f14, $f10
  swc1  $f18, 0x10($s0)
  lw    $t3, ($a0)
  lwc1  $f10, ($v1)
  addu  $v0, $t3, $s1
  lwc1  $f6, 0xb0c($v0)
  lwc1  $f4, 0xb4c($v0)
  sub.s $f8, $f6, $f4
  lwc1  $f6, 0x14($s0)
  div.s $f18, $f8, $f10
  add.s $f4, $f6, $f18
  swc1  $f4, 0x14($s0)
  lw    $t4, ($a0)
  lwc1  $f18, ($v1)
  addu  $v0, $t4, $s1
  lwc1  $f8, 0xb10($v0)
  lwc1  $f10, 0xb50($v0)
  sub.s $f6, $f8, $f10
  div.s $f4, $f6, $f18
  add.s $f8, $f16, $f4
  b     .L7F068D0C
   swc1  $f8, 0x18($s0)
.L7F0689C4:
  jal   get_random_value
   nop   
  mtc1  $v0, $f10
  lui   $at, %hi(D_800543DC)
  lwc1  $f0, %lo(D_800543DC)($at)
  bgez  $v0, .L7F0689F0
   cvt.s.w $f6, $f10
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f18
  nop   
  add.s $f6, $f6, $f18
.L7F0689F0:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f4
  li    $at, 0x3E000000 # 0.125000
  mtc1  $at, $f18
  mul.s $f8, $f6, $f4
  nop   
  mul.s $f10, $f8, $f0
  nop   
  mul.s $f6, $f10, $f18
  add.s $f4, $f6, $f0
  neg.s $f8, $f4
  jal   get_random_value
   swc1  $f8, 0x10($s0)
  mtc1  $v0, $f10
  lui   $at, %hi(D_800543E0)
  lwc1  $f0, %lo(D_800543E0)($at)
  bgez  $v0, .L7F068A48
   cvt.s.w $f18, $f10
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f6
  nop   
  add.s $f18, $f18, $f6
.L7F068A48:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f4
  li    $at, 0x3E000000 # 0.125000
  mtc1  $at, $f6
  mul.s $f8, $f18, $f4
  lui   $t5, %hi(pPlayer) 
  addiu $a1, $s0, 0x10
  mul.s $f10, $f8, $f0
  mtc1  $zero, $f8
  nop   
  swc1  $f8, 0x18($s0)
  mul.s $f18, $f10, $f6
  add.s $f4, $f18, $f0
  swc1  $f4, 0x14($s0)
  lw    $t5, %lo(pPlayer)($t5)
  addu  $a0, $t5, $s1
  jal   sub_GAME_7F0583D8
   addiu $a0, $a0, 0xad8
  jal   get_random_value
   nop   
  mtc1  $v0, $f10
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F068AB4
   cvt.s.w $f6, $f10
  mtc1  $at, $f18
  nop   
  add.s $f6, $f6, $f18
.L7F068AB4:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f4
  lui   $at, %hi(D_800543E4)
  lwc1  $f10, %lo(D_800543E4)($at)
  mul.s $f0, $f6, $f4
  li    $at, 0x3D800000 # 0.062500
  mtc1  $at, $f6
  lui   $at, %hi(D_800543E8)
  add.s $f8, $f0, $f0
  mul.s $f18, $f8, $f10
  lwc1  $f8, %lo(D_800543E8)($at)
  mul.s $f4, $f18, $f6
  sub.s $f10, $f4, $f8
  jal   get_random_value
   swc1  $f10, 0x54($sp)
  mtc1  $v0, $f18
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F068B0C
   cvt.s.w $f6, $f18
  mtc1  $at, $f4
  nop   
  add.s $f6, $f6, $f4
.L7F068B0C:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f8
  lui   $at, %hi(D_800543EC)
  lwc1  $f18, %lo(D_800543EC)($at)
  mul.s $f0, $f6, $f8
  li    $at, 0x3D800000 # 0.062500
  mtc1  $at, $f6
  lui   $at, %hi(D_800543F0)
  add.s $f10, $f0, $f0
  mul.s $f4, $f10, $f18
  lwc1  $f10, %lo(D_800543F0)($at)
  mul.s $f8, $f4, $f6
  sub.s $f18, $f8, $f10
  jal   get_random_value
   swc1  $f18, 0x58($sp)
  mtc1  $v0, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F068B64
   cvt.s.w $f6, $f4
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F068B64:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f10
  lui   $at, %hi(D_800543F4)
  lwc1  $f4, %lo(D_800543F4)($at)
  mul.s $f0, $f6, $f10
  li    $at, 0x3D800000 # 0.062500
  mtc1  $at, $f6
  lui   $at, %hi(D_800543F8)
  addiu $a0, $sp, 0x54
  addiu $a1, $s0, 0x5c
  add.s $f18, $f0, $f0
  mul.s $f8, $f18, $f4
  lwc1  $f18, %lo(D_800543F8)($at)
  mul.s $f10, $f8, $f6
  sub.s $f4, $f10, $f18
  jal   sub_GAME_7F058714
   swc1  $f4, 0x5c($sp)
  jal   get_random_value
   nop   
  lui   $v1, (0x00158679 >> 16) # lui $v1, 0x15
  ori   $v1, (0x00158679 & 0xFFFF) # ori $v1, $v1, 0x8679
  srl   $t6, $v0, 0x18
  multu $t6, $v1
  mflo  $t7
  sra   $t8, $t7, 0xa
  addu  $t9, $t8, $v1
  jal   get_random_value
   sw    $t9, 0x3c($sp)
  lw    $t2, 0x3c($sp)
  lwc1  $f12, 0x14($s0)
  li    $at, 0x4F800000 # 4294967296.000000
  divu  $zero, $v0, $t2
  mfhi  $t0
  mtc1  $t0, $f8
  bnez  $t2, .L7F068BF8
   nop   
  break 7
.L7F068BF8:
  lui   $t3, %hi(pPlayer) 
  bgez  $t0, .L7F068C10
   cvt.s.w $f6, $f8
  mtc1  $at, $f10
  nop   
  add.s $f6, $f6, $f10
.L7F068C10:
  lui   $at, %hi(D_800543FC)
  lwc1  $f18, %lo(D_800543FC)($at)
  lui   $at, %hi(expended_shell_initial_gravity_modifier_non_pistol)
  lwc1  $f4, %lo(expended_shell_initial_gravity_modifier_non_pistol)($at)
  div.s $f0, $f6, $f18
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f18
  lwc1  $f14, 0x10($s0)
  lwc1  $f16, 0x18($s0)
  lui   $t1, %hi(clock_timer) 
  mul.s $f8, $f0, $f4
  sub.s $f2, $f12, $f8
  lwc1  $f8, 8($s0)
  add.s $f10, $f12, $f2
  swc1  $f2, 0x14($s0)
  mul.s $f6, $f0, $f10
  nop   
  mul.s $f4, $f6, $f18
  lwc1  $f6, 4($s0)
  mul.s $f18, $f0, $f14
  add.s $f10, $f8, $f4
  lwc1  $f4, 0xc($s0)
  add.s $f8, $f6, $f18
  swc1  $f10, 8($s0)
  mul.s $f10, $f0, $f16
  swc1  $f8, 4($s0)
  add.s $f6, $f4, $f10
  swc1  $f6, 0xc($s0)
  lw    $t1, %lo(clock_timer)($t1)
  blez  $t1, .L7F068D0C
   nop   
  lw    $t3, %lo(pPlayer)($t3)
  lui   $v1, %hi(global_timer_delta)
  addiu $v1, %lo(global_timer_delta) # addiu $v1, $v1, -0x7c88
  addu  $v0, $t3, $s1
  lwc1  $f18, 0xb08($v0)
  lwc1  $f8, 0xb48($v0)
  lwc1  $f10, ($v1)
  lui   $t4, %hi(pPlayer) 
  sub.s $f4, $f18, $f8
  lui   $t5, %hi(pPlayer) 
  div.s $f6, $f4, $f10
  add.s $f18, $f14, $f6
  swc1  $f18, 0x10($s0)
  lw    $t4, %lo(pPlayer)($t4)
  lwc1  $f6, ($v1)
  addu  $v0, $t4, $s1
  lwc1  $f8, 0xb0c($v0)
  lwc1  $f4, 0xb4c($v0)
  sub.s $f10, $f8, $f4
  lwc1  $f8, 0x14($s0)
  div.s $f18, $f10, $f6
  add.s $f4, $f8, $f18
  swc1  $f4, 0x14($s0)
  lw    $t5, %lo(pPlayer)($t5)
  lwc1  $f18, ($v1)
  addu  $v0, $t5, $s1
  lwc1  $f10, 0xb10($v0)
  lwc1  $f6, 0xb50($v0)
  sub.s $f8, $f10, $f6
  div.s $f4, $f8, $f18
  add.s $f10, $f16, $f4
  swc1  $f10, 0x18($s0)
.L7F068D0C:
  lw    $ra, 0x1c($sp)
.L7F068D10:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0xc0
");

#ifdef VERSION_US
asm(R"
.late_rodata
glabel expended_shell_initial_gravity_modifier_all
.word 0x3e8e38e4 /*0.27777779*/
.text
glabel sub_GAME_7F068D20
  lui   $at, %hi(global_timer_delta)
  lwc1  $f2, %lo(global_timer_delta)($at)
  lui   $at, %hi(expended_shell_initial_gravity_modifier_all)
  lwc1  $f4, %lo(expended_shell_initial_gravity_modifier_all)($at)
  addiu $sp, $sp, -0x28
  sw    $ra, 0x24($sp)
  mul.s $f6, $f2, $f4
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  lwc1  $f0, 0x14($a0)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f8
  sub.s $f12, $f0, $f6
  lwc1  $f4, 8($a0)
  mul.s $f10, $f2, $f8
  lui   $a2, %hi(dword_CODE_bss_80075DB0)
  add.s $f16, $f0, $f12
  move  $a3, $a0
  addiu $a2, %lo(dword_CODE_bss_80075DB0) # addiu $a2, $a2, 0x5db0
  mul.s $f18, $f10, $f16
  lwc1  $f10, ($a0)
  add.s $f6, $f4, $f18
  swc1  $f6, 8($a0)
  lwc1  $f8, 8($a0)
  c.lt.s $f8, $f10
  nop   
  bc1fl .L7F068DEC
   lwc1  $f4, 0x10($a3)
  lw    $t6, ($a2)
  lui   $v0, %hi(pPlayer)
  bnez  $t6, .L7F068DE0
   nop   
  lw    $v0, %lo(pPlayer)($v0)
  li    $v1, 2
  lw    $t7, 0x894($v0)
  beq   $v1, $t7, .L7F068DE0
   nop   
  lw    $t8, 0xc3c($v0)
  lui   $a0, %hi(ptr_sfx_buf)
  li    $a1, 122
  beq   $v1, $t8, .L7F068DE0
   nop   
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   sw    $a3, 0x28($sp)
  lw    $a3, 0x28($sp)
.L7F068DE0:
  b     .L7F068E50
   sw    $zero, 0x9c($a3)
  lwc1  $f4, 0x10($a3)
.L7F068DEC:
  lwc1  $f10, 0x18($a3)
  lwc1  $f16, 4($a3)
  mul.s $f18, $f2, $f4
  lwc1  $f8, 0xc($a3)
  lui   $s3, %hi(clock_timer)
  mul.s $f4, $f2, $f10
  addiu $s3, %lo(clock_timer) # addiu $s3, $s3, -0x7c8c
  swc1  $f12, 0x14($a3)
  move  $s0, $zero
  addiu $s1, $a3, 0x5c
  add.s $f6, $f16, $f18
  addiu $s2, $a3, 0x1c
  add.s $f16, $f8, $f4
  swc1  $f6, 4($a3)
  swc1  $f16, 0xc($a3)
  lw    $t9, ($s3)
  blez  $t9, .L7F068E50
   move  $a0, $s1
.L7F068E34:
  jal   matrix_4x4_multiply_homogeneous_in_place
   move  $a1, $s2
  lw    $t0, ($s3)
  addiu $s0, $s0, 1
  slt   $at, $s0, $t0
  bnezl $at, .L7F068E34
   move  $a0, $s1
.L7F068E50:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

#ifdef VERSION_JP
asm(R"
.late_rodata
glabel expended_shell_initial_gravity_modifier_all
.word 0x3e8e38e4 /*0.27777779*/
.text
glabel sub_GAME_7F068D20
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  lwc1  $f2, %lo(global_timer_delta)($at)
  lui   $at, %hi(expended_shell_initial_gravity_modifier_all) # $at, 0x8005
  lwc1  $f4, %lo(expended_shell_initial_gravity_modifier_all)($at)
  addiu $sp, $sp, -0x28
  sw    $ra, 0x24($sp)
  mul.s $f6, $f2, $f4
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  lwc1  $f0, 0x14($a0)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f8
  sub.s $f12, $f0, $f6
  lwc1  $f4, 8($a0)
  mul.s $f10, $f2, $f8
  lui   $a2, %hi(dword_CODE_bss_80075DB0) # $a2, 0x8007
  add.s $f16, $f0, $f12
  move  $a3, $a0
  addiu $a2, %lo(dword_CODE_bss_80075DB0) # addiu $a2, $a2, 0x5df0
  mul.s $f18, $f10, $f16
  lwc1  $f10, ($a0)
  add.s $f6, $f4, $f18
  swc1  $f6, 8($a0)
  lwc1  $f8, 8($a0)
  c.lt.s $f8, $f10
  nop   
  bc1fl .Ljp7F0693D8
   lwc1  $f4, 0x10($a3)
  lw    $t6, ($a2)
  lui   $s3, %hi(clock_timer) # $s3, 0x8005
  addiu $s3, %lo(clock_timer) # addiu $s3, $s3, -0x7c5c
  bnez  $t6, .Ljp7F0693CC
   nop   
  lw    $t7, ($s3)
  lui   $v0, %hi(pPlayer) # $v0, 0x8008
  blez  $t7, .Ljp7F0693CC
   nop   
  lw    $v0, %lo(pPlayer)($v0)
  li    $v1, 2
  lw    $t8, 0x894($v0)
  beq   $v1, $t8, .Ljp7F0693CC
   nop   
  lw    $t9, 0xc3c($v0)
  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  li    $a1, 122
  beq   $v1, $t9, .Ljp7F0693CC
   nop   
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   sw    $a3, 0x28($sp)
  lw    $a3, 0x28($sp)
.Ljp7F0693CC:
  b     .Ljp7F06943C
   sw    $zero, 0x9c($a3)
  lwc1  $f4, 0x10($a3)
.Ljp7F0693D8:
  lwc1  $f10, 0x18($a3)
  lwc1  $f16, 4($a3)
  mul.s $f18, $f2, $f4
  lwc1  $f8, 0xc($a3)
  lui   $s3, %hi(clock_timer) # $s3, 0x8005
  mul.s $f4, $f2, $f10
  addiu $s3, %lo(clock_timer) # addiu $s3, $s3, -0x7c5c
  swc1  $f12, 0x14($a3)
  move  $s0, $zero
  addiu $s1, $a3, 0x5c
  add.s $f6, $f16, $f18
  addiu $s2, $a3, 0x1c
  add.s $f16, $f8, $f4
  swc1  $f6, 4($a3)
  swc1  $f16, 0xc($a3)
  lw    $t0, ($s3)
  blez  $t0, .Ljp7F06943C
   move  $a0, $s1
.Ljp7F069420:
  jal   matrix_4x4_multiply_homogeneous_in_place
   move  $a1, $s2
  lw    $t1, ($s3)
  addiu $s0, $s0, 1
  slt   $at, $s0, $t1
  bnezl $at, .Ljp7F069420
   move  $a0, $s1
.Ljp7F06943C:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");
#endif

#endif

asm(R"
glabel sub_GAME_7F068E6C
  addiu $sp, $sp, -0x20
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  lui   $s1, %hi(dword_CODE_bss_80076A48)
  lui   $s0, %hi(dword_CODE_bss_80075DC8)
  sw    $ra, 0x1c($sp)
  addiu $s1, %lo(dword_CODE_bss_80076A48) # addiu $s1, $s1, 0x6a48
  addiu $s0, %lo(dword_CODE_bss_80075DC8) # addiu $s0, $s0, 0x5dc8
  lw    $t6, 0x9c($s0)
.L7F068E90:
  beql  $t6, $zero, .L7F068EA4
   addiu $s0, $s0, 0xa0
  jal   sub_GAME_7F068D20
   move  $a0, $s0
  addiu $s0, $s0, 0xa0
.L7F068EA4:
  sltu  $at, $s0, $s1
  bnezl $at, .L7F068E90
   lw    $t6, 0x9c($s0)
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x20
");

asm(R"
.late_rodata
glabel D_80054408
.word 0x3dccccce /*0.10000001*/
glabel D_8005440C
.word 0xc6ea6000 /*-30000.0*/
glabel D_80054410
.word 0x46ea6000 /*30000.0*/
.text
glabel sub_GAME_7F068EC4
  addiu $sp, $sp, -0xe8
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a0, 0xe8($sp)
  sw    $a1, 0xec($sp)
  lw    $t7, ($a1)
  sw    $t7, 0xe4($sp)
  lw    $v0, 0x9c($a0)
  lh    $a0, 0xe($v0)
  sw    $v0, 0xe0($sp)
  sll   $t9, $a0, 6
  jal   sub_GAME_7F0BD714
   move  $a0, $t9
  lui   $t1, %hi(D_80035EB0) 
  addiu $t1, %lo(D_80035EB0) # addiu $t1, $t1, 0x5eb0
  sw    $v0, 0xdc($sp)
  addiu $t4, $t1, 0x3c
  addiu $t0, $sp, 0x7c
.L7F068F0C:
  lw    $at, ($t1)
  addiu $t1, $t1, 0xc
  addiu $t0, $t0, 0xc
  sw    $at, -0xc($t0)
  lw    $at, -8($t1)
  sw    $at, -8($t0)
  lw    $at, -4($t1)
  bne   $t1, $t4, .L7F068F0C
   sw    $at, -4($t0)
  lw    $at, ($t1)
  li    $s0, 1
  sw    $at, ($t0)
  jal   set_objuse_flag_compute_grp_nums_set_obj_loaded
   lw    $a0, 0xe0($sp)
  addiu $a0, $sp, 0xbc
  lw    $a1, 0xe0($sp)
  jal   sub_GAME_7F075F68
   move  $a2, $zero
  lw    $t5, 0xdc($sp)
  lw    $a0, 0xe8($sp)
  addiu $a1, $sp, 0x3c
  sw    $t5, 0xc8($sp)
  jal   matrix_4x4_copy
   addiu $a0, $a0, 0x1c
  lui   $at, %hi(D_80054408)
  lwc1  $f12, %lo(D_80054408)($at)
  jal   matrix_multiply_A1_by_F12
   addiu $a1, $sp, 0x3c
  lw    $a0, 0xe8($sp)
  addiu $a1, $sp, 0x3c
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   addiu $a0, $a0, 4
  jal   get_BONDdata_field_10CC
   nop   
  move  $a0, $v0
  addiu $a1, $sp, 0x3c
  jal   matrix_4x4_multiply_homogeneous
   lw    $a2, 0xc8($sp)
  lui   $at, %hi(D_8005440C)
  lwc1  $f12, %lo(D_8005440C)($at)
  lui   $at, %hi(D_80054410)
  lwc1  $f2, %lo(D_80054410)($at)
  move  $v0, $zero
  lw    $v1, 0xc8($sp)
  li    $a0, 12
.L7F068FC0:
  lwc1  $f0, 0x30($v1)
  addiu $v0, $v0, 4
  c.lt.s $f2, $f0
  nop   
  bc1fl .L7F068FE4
   c.lt.s $f0, $f12
  b     .L7F068FF4
   move  $s0, $zero
  c.lt.s $f0, $f12
.L7F068FE4:
  nop   
  bc1f  .L7F068FF4
   nop   
  move  $s0, $zero
.L7F068FF4:
  bne   $v0, $a0, .L7F068FC0
   addiu $v1, $v1, 4
  beqz  $s0, .L7F069078
   li    $t8, 4
  lw    $t6, 0xe4($sp)
  lw    $t7, 0xdc($sp)
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  sw    $zero, 0x80($sp)
  sw    $t8, 0xac($sp)
  sw    $t6, 0x88($sp)
  sw    $t7, 0x8c($sp)
  lbu   $t3, 0xfdc($v0)
  lbu   $t1, 0xfdd($v0)
  lbu   $t9, 0xfdf($v0)
  lbu   $t6, 0xfde($v0)
  sll   $t2, $t3, 0x18
  sll   $t0, $t1, 0x10
  or    $t4, $t9, $t2
  or    $t5, $t4, $t0
  sll   $t7, $t6, 8
  or    $t8, $t5, $t7
  sw    $t8, 0xb0($sp)
  addiu $a0, $sp, 0x7c
  jal   subdraw
   addiu $a1, $sp, 0xbc
  lw    $t3, 0x88($sp)
  lw    $t9, 0xec($sp)
  sw    $t3, ($t9)
  lw    $t2, 0xe0($sp)
  lw    $a0, 0xdc($sp)
  jal   sub_GAME_7F08BD48
   lh    $a1, 0xe($t2)
.L7F069078:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0xe8
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F06908C
  addiu $sp, $sp, -0x28
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $s2, 0x20($sp)
  lui   $s1, %hi(dword_CODE_bss_80076A48)
  lui   $s0, %hi(dword_CODE_bss_80075DC8)
  move  $s2, $a0
  sw    $ra, 0x24($sp)
  addiu $s1, %lo(dword_CODE_bss_80076A48) # addiu $s1, $s1, 0x6a48
  addiu $s0, %lo(dword_CODE_bss_80075DC8) # addiu $s0, $s0, 0x5dc8
  lw    $t6, 0x9c($s0)
.L7F0690B8:
  move  $a0, $s0
  beql  $t6, $zero, .L7F0690D0
   addiu $s0, $s0, 0xa0
  jal   sub_GAME_7F068EC4
   move  $a1, $s2
  addiu $s0, $s0, 0xa0
.L7F0690D0:
  sltu  $at, $s0, $s1
  bnezl $at, .L7F0690B8
   lw    $t6, 0x9c($s0)
  lw    $ra, 0x24($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
glabel set_unset_ammo_on_screen_setting
  beqz  $a1, .L7F069118
   lui   $v0, %hi(pPlayer)
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  not   $t7, $a0
  lw    $t6, 0x1064($v0)
  and   $t8, $t6, $t7
  jr    $ra
   sw    $t8, 0x1064($v0)

.L7F069118:
  lw    $v0, %lo(pPlayer)($v0)
  lw    $t9, 0x1064($v0)
  or    $t0, $t9, $a0
  sw    $t0, 0x1064($v0)
  jr    $ra
   nop   
");

asm(R"
glabel give_cur_player_ammo
  addiu $sp, $sp, -0x28
  sw    $s0, 0x18($sp)
  move  $s0, $a0
  sw    $ra, 0x1c($sp)
  sw    $a1, 0x2c($sp)
  jal   get_item_in_hand
   move  $a0, $zero
  sw    $v0, 0x24($sp)
  jal   get_ammo_type_for_weapon
   move  $a0, $v0
  bne   $v0, $s0, .L7F0691D8
   lw    $a0, 0x24($sp)
  jal   check_special_attributes
   lui   $a1, 0x20
  beqz  $v0, .L7F0691D8
   lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  lw    $t7, 0x2c($sp)
  lw    $t6, 0x89c($v1)
  addu  $t8, $t6, $t7
  sw    $t8, 0x89c($v1)
  jal   get_ptr_item_statistics
   lw    $a0, 0x24($sp)
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  lh    $t9, 0x20($v0)
  lw    $t0, 0x89c($v1)
  slt   $at, $t9, $t0
  beql  $at, $zero, .L7F0691CC
   sll   $t3, $s0, 2
  jal   get_ptr_item_statistics
   lw    $a0, 0x24($sp)
  lui   $t2, %hi(pPlayer) 
  lw    $t2, %lo(pPlayer)($t2)
  lh    $t1, 0x20($v0)
  lui   $v1, %hi(pPlayer)
  sw    $t1, 0x89c($t2)
  lw    $v1, %lo(pPlayer)($v1)
  sll   $t3, $s0, 2
.L7F0691CC:
  addu  $t4, $v1, $t3
  b     .L7F06922C
   sw    $zero, 0x1130($t4)
.L7F0691D8:
  sll   $t5, $s0, 2
  subu  $t5, $t5, $s0
  sll   $t5, $t5, 2
  lui   $v0, %hi(ammo_related)
  addu  $v0, $v0, $t5
  lw    $v1, 0x2c($sp)
  lw    $v0, %lo(ammo_related)($v0)
  lui   $t6, %hi(pPlayer) 
  lui   $t9, %hi(pPlayer) 
  slt   $at, $v0, $v1
  beqz  $at, .L7F06921C
   nop   
  lw    $t6, %lo(pPlayer)($t6)
  sll   $t7, $s0, 2
  addu  $t8, $t6, $t7
  b     .L7F06922C
   sw    $v0, 0x1130($t8)
.L7F06921C:
  lw    $t9, %lo(pPlayer)($t9)
  sll   $t0, $s0, 2
  addu  $t1, $t9, $t0
  sw    $v1, 0x1130($t1)
.L7F06922C:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel check_cur_player_ammo_amount_in_inventory
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  sll   $t7, $a0, 2
  addu  $t8, $t6, $t7
  jr    $ra
   lw    $v0, 0x1130($t8)
");

asm(R"
glabel check_cur_player_ammo_amount_total
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  jal   check_cur_player_ammo_amount_in_inventory
   sw    $a0, 0x20($sp)
  move  $s0, $v0
  jal   get_item_in_hand
   move  $a0, $zero
  jal   get_ammo_type_for_weapon
   move  $a0, $v0
  lw    $t6, 0x20($sp)
  bne   $v0, $t6, .L7F069298
   nop   
  jal   get_ammo_in_hands_magazine
   move  $a0, $zero
  addu  $s0, $s0, $v0
.L7F069298:
  jal   get_item_in_hand
   li    $a0, 1
  jal   get_ammo_type_for_weapon
   move  $a0, $v0
  lw    $t7, 0x20($sp)
  bnel  $v0, $t7, .L7F0692C4
   lw    $ra, 0x1c($sp)
  jal   get_ammo_in_hands_magazine
   li    $a0, 1
  addu  $s0, $s0, $v0
  lw    $ra, 0x1c($sp)
.L7F0692C4:
  move  $v0, $s0
  lw    $s0, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x20
");

asm(R"
glabel get_max_ammo_for_type
  sll   $t6, $a0, 2
  subu  $t6, $t6, $a0
  sll   $t6, $t6, 2
  lui   $v0, %hi(ammo_related)
  addu  $v0, $v0, $t6
  jr    $ra
   lw    $v0, %lo(ammo_related)($v0)
");

asm(R"
glabel set_max_ammo_for_cur_player
  addiu $sp, $sp, -0x28
  sw    $s1, 0x1c($sp)
  sw    $s2, 0x20($sp)
  sw    $s0, 0x18($sp)
  lui   $s1, %hi(ammo_related)
  sw    $ra, 0x24($sp)
  addiu $s1, %lo(ammo_related) # addiu $s1, $s1, 0x5ef0
  move  $s0, $zero
  li    $s2, 30
.L7F069314:
  move  $a0, $s0
  jal   give_cur_player_ammo
   lw    $a1, ($s1)
  addiu $s0, $s0, 1
  bne   $s0, $s2, .L7F069314
   addiu $s1, $s1, 0xc
  lw    $ra, 0x24($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
glabel get_ammo_in_hands_magazine
  sll   $t7, $a0, 3
  subu  $t7, $t7, $a0
  sll   $t7, $t7, 2
  addu  $t7, $t7, $a0
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  sll   $t7, $t7, 2
  addu  $t7, $t7, $a0
  sll   $t7, $t7, 3
  addu  $t8, $t6, $t7
  jr    $ra
   lw    $v0, 0x89c($t8)
");

asm(R"
glabel get_ammo_in_hands_weapon
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  jal   get_item_in_hand
   sw    $a0, 0x20($sp)
  move  $a0, $v0
  jal   get_ammo_count_for_weapon
   sw    $v0, 0x1c($sp)
  lw    $v1, 0x1c($sp)
  li    $at, 15
  move  $a1, $v0
  beq   $v1, $at, .L7F0693B0
   lw    $t6, 0x20($sp)
  li    $at, 16
  bne   $v1, $at, .L7F06941C
   move  $v0, $a1
.L7F0693B0:
  li    $t7, 1
  subu  $a0, $t7, $t6
  jal   get_item_in_hand
   sw    $a1, 0x18($sp)
  li    $at, 15
  beq   $v0, $at, .L7F0693D8
   lw    $a1, 0x18($sp)
  li    $at, 16
  bne   $v0, $at, .L7F069414
   nop   
.L7F0693D8:
  lw    $t9, 0x20($sp)
  lui   $t8, %hi(pPlayer) 
  lw    $t8, %lo(pPlayer)($t8)
  sll   $t0, $t9, 3
  subu  $t0, $t0, $t9
  sll   $t0, $t0, 2
  addu  $t0, $t0, $t9
  sll   $t0, $t0, 2
  addu  $t0, $t0, $t9
  sll   $t0, $t0, 3
  negu  $t1, $t0
  addu  $t2, $t8, $t1
  lw    $t3, 0xc4c($t2)
  b     .L7F06941C
   subu  $v0, $a1, $t3
.L7F069414:
  b     .L7F06941C
   move  $v0, $a1
.L7F06941C:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel get_ammo_type_for_weapon
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   get_ptr_item_statistics
   nop   
  lw    $ra, 0x14($sp)
  lw    $v0, 0x1c($v0)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel get_ammo_count_for_weapon
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   get_ptr_item_statistics
   nop   
  lw    $t7, 0x1c($v0)
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  lw    $ra, 0x14($sp)
  sll   $t8, $t7, 2
  addu  $t9, $t6, $t8
  lw    $v0, 0x1130($t9)
  jr    $ra
   addiu $sp, $sp, 0x18
");

asm(R"
glabel add_ammo_to_weapon
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   get_ptr_item_statistics
   sw    $a1, 0x1c($sp)
  lw    $a0, 0x1c($v0)
  jal   give_cur_player_ammo
   lw    $a1, 0x1c($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel get_max_ammo_for_weapon
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   get_ptr_item_statistics
   nop   
  lw    $t6, 0x1c($v0)
  lw    $ra, 0x14($sp)
  lui   $v0, %hi(ammo_related)
  sll   $t7, $t6, 2
  subu  $t7, $t7, $t6
  sll   $t7, $t7, 2
  addu  $v0, $v0, $t7
  lw    $v0, %lo(ammo_related)($v0)
  jr    $ra
   addiu $sp, $sp, 0x18
");

asm(R"
glabel microcode_generation_ammo_related
  addiu $sp, $sp, -0xb8
  sw    $a0, 0xb8($sp)
  addiu $t7, $a0, 8
  sw    $ra, 0x44($sp)
  sw    $s0, 0x40($sp)
  sw    $t7, 0xb8($sp)
  lui   $t8, (0xBA000602 >> 16) # lui $t8, 0xba00
  ori   $t8, (0xBA000602 & 0xFFFF) # ori $t8, $t8, 0x602
  li    $t9, 192
  sw    $t9, 4($a0)
  sw    $t8, ($a0)
  lw    $t0, 0xb8($sp)
  lui   $t2, (0xBA001301 >> 16) # lui $t2, 0xba00
  ori   $t2, (0xBA001301 & 0xFFFF) # ori $t2, $t2, 0x1301
  addiu $t1, $t0, 8
  sw    $t1, 0xb8($sp)
  sw    $zero, 4($t0)
  sw    $t2, ($t0)
  lw    $t3, 0xb8($sp)
  lui   $t5, (0xB9000002 >> 16) # lui $t5, 0xb900
  ori   $t5, (0xB9000002 & 0xFFFF) # ori $t5, $t5, 2
  addiu $t4, $t3, 8
  sw    $t4, 0xb8($sp)
  sw    $zero, 4($t3)
  sw    $t5, ($t3)
  lw    $t6, 0xb8($sp)
  lui   $t8, (0xBA001001 >> 16) # lui $t8, 0xba00
  ori   $t8, (0xBA001001 & 0xFFFF) # ori $t8, $t8, 0x1001
  addiu $t7, $t6, 8
  sw    $t7, 0xb8($sp)
  sw    $zero, 4($t6)
  sw    $t8, ($t6)
  lw    $t9, 0xb8($sp)
  lui   $t1, (0xBA000C02 >> 16) # lui $t1, 0xba00
  ori   $t1, (0xBA000C02 & 0xFFFF) # ori $t1, $t1, 0xc02
  addiu $t0, $t9, 8
  sw    $t0, 0xb8($sp)
  sw    $zero, 4($t9)
  sw    $t1, ($t9)
  lw    $t2, 0xb8($sp)
  lui   $t4, (0xBA000903 >> 16) # lui $t4, 0xba00
  ori   $t4, (0xBA000903 & 0xFFFF) # ori $t4, $t4, 0x903
  addiu $t3, $t2, 8
  sw    $t3, 0xb8($sp)
  li    $t5, 3072
  sw    $t5, 4($t2)
  sw    $t4, ($t2)
  lw    $t6, 0xb8($sp)
  lui   $t8, (0xBA000E02 >> 16) # lui $t8, 0xba00
  ori   $t8, (0xBA000E02 & 0xFFFF) # ori $t8, $t8, 0xe02
  addiu $t7, $t6, 8
  sw    $t7, 0xb8($sp)
  sw    $zero, 4($t6)
  sw    $t8, ($t6)
  lbu   $a0, 4($a1)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $a2, $f14
  mtc1  $a0, $f4
  mtc1  $a3, $f12
  mtc1  $at, $f0
  move  $s0, $a1
  bgez  $a0, .L7F0695F4
   cvt.s.w $f6, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F0695F4:
  mul.s $f10, $f6, $f0
  bgez  $a0, .L7F069608
   sra   $t9, $a0, 1
  addiu $at, $a0, 1
  sra   $t9, $at, 1
.L7F069608:
  mtc1  $t9, $f16
  lw    $t0, 0xcc($sp)
  lui   $t7, 0xe700
  cvt.s.w $f18, $f16
  addiu $a0, $sp, 0xb8
  move  $a1, $s0
  move  $a3, $zero
  sub.s $f4, $f10, $f18
  mtc1  $zero, $f10
  beqz  $t0, .L7F06963C
   swc1  $f4, 0xb0($sp)
  neg.s $f8, $f4
  swc1  $f8, 0xb0($sp)
.L7F06963C:
  lwc1  $f6, 0xb0($sp)
  c.le.s $f10, $f12
  lui   $t0, (0xBA001402 >> 16) # lui $t0, 0xba00
  add.s $f16, $f6, $f14
  bc1f  .L7F069684
   swc1  $f16, 0xb0($sp)
  lbu   $t1, 5($s0)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t1, $f18
  bgez  $t1, .L7F069674
   cvt.s.w $f4, $f18
  mtc1  $at, $f8
  nop   
  add.s $f4, $f4, $f8
.L7F069674:
  mul.s $f6, $f4, $f0
  sub.s $f16, $f12, $f6
  b     .L7F0696E4
   swc1  $f16, 0xb4($sp)
.L7F069684:
  lbu   $v0, 5($s0)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $v0, $f10
  bgez  $v0, .L7F0696A4
   cvt.s.w $f18, $f10
  mtc1  $at, $f8
  nop   
  add.s $f18, $f18, $f8
.L7F0696A4:
  mul.s $f4, $f18, $f0
  bgez  $v0, .L7F0696B8
   sra   $t2, $v0, 1
  addiu $at, $v0, 1
  sra   $t2, $at, 1
.L7F0696B8:
  mtc1  $t2, $f6
  lwc1  $f18, 0xc8($sp)
  cvt.s.w $f16, $f6
  sub.s $f10, $f4, $f16
  lwc1  $f4, 0xd0($sp)
  sub.s $f6, $f18, $f10
  neg.s $f8, $f10
  add.s $f16, $f6, $f4
  swc1  $f8, 0xb4($sp)
  swc1  $f6, 0xb4($sp)
  swc1  $f16, 0xb4($sp)
.L7F0696E4:
  lbu   $t3, 4($s0)
  li    $at, 0x4F800000 # 4294967296.000000
  li    $a2, 1
  mtc1  $t3, $f8
  bgez  $t3, .L7F069708
   cvt.s.w $f18, $f8
  mtc1  $at, $f10
  nop   
  add.s $f18, $f18, $f10
.L7F069708:
  mul.s $f6, $f18, $f0
  li    $at, 0x4F800000 # 4294967296.000000
  swc1  $f6, 0xa8($sp)
  lbu   $t4, 5($s0)
  mtc1  $t4, $f4
  bgez  $t4, .L7F069730
   cvt.s.w $f16, $f4
  mtc1  $at, $f8
  nop   
  add.s $f16, $f16, $f8
.L7F069730:
  mul.s $f10, $f16, $f0
  lw    $t5, 0xb8($sp)
  ori   $t0, (0xBA001402 & 0xFFFF) # ori $t0, $t0, 0x1402
  lui   $t3, (0xB900031D >> 16) # lui $t3, 0xb900
  addiu $t6, $t5, 8
  sw    $t6, 0xb8($sp)
  lui   $t4, (0x00504240 >> 16) # lui $t4, 0x50
  swc1  $f10, 0xac($sp)
  sw    $zero, 4($t5)
  sw    $t7, ($t5)
  lw    $t8, 0xb8($sp)
  ori   $t4, (0x00504240 & 0xFFFF) # ori $t4, $t4, 0x4240
  ori   $t3, (0xB900031D & 0xFFFF) # ori $t3, $t3, 0x31d
  addiu $t9, $t8, 8
  sw    $t9, 0xb8($sp)
  sw    $zero, 4($t8)
  sw    $t0, ($t8)
  lw    $t1, 0xb8($sp)
  lui   $t8, (0xFFFDF6FB >> 16) # lui $t8, 0xfffd
  lui   $t7, (0xFCFFFFFF >> 16) # lui $t7, 0xfcff
  addiu $t2, $t1, 8
  sw    $t2, 0xb8($sp)
  sw    $t4, 4($t1)
  sw    $t3, ($t1)
  lw    $t5, 0xb8($sp)
  ori   $t7, (0xFCFFFFFF & 0xFFFF) # ori $t7, $t7, 0xffff
  ori   $t8, (0xFFFDF6FB & 0xFFFF) # ori $t8, $t8, 0xf6fb
  addiu $t6, $t5, 8
  sw    $t6, 0xb8($sp)
  sw    $t8, 4($t5)
  sw    $t7, ($t5)
  lw    $t9, 0xb8($sp)
  lui   $t1, 0xfa00
  lui   $at, 0xf600
  addiu $t0, $t9, 8
  sw    $t0, 0xb8($sp)
  sw    $zero, 4($t9)
  sw    $t1, ($t9)
  lwc1  $f18, 0xac($sp)
  lwc1  $f6, 0xb4($sp)
  lwc1  $f10, 0xa8($sp)
  lwc1  $f16, 0xb0($sp)
  add.s $f4, $f18, $f6
  lw    $v0, 0xb8($sp)
  add.s $f18, $f16, $f10
  addiu $t3, $v0, 8
  sw    $t3, 0xb8($sp)
  trunc.w.s $f8, $f4
  trunc.w.s $f6, $f18
  mfc1  $t5, $f8
  mfc1  $t1, $f6
  addiu $t6, $t5, 1
  andi  $t7, $t6, 0x3ff
  addiu $t2, $t1, 1
  andi  $t3, $t2, 0x3ff
  sll   $t8, $t7, 2
  or    $t9, $t8, $at
  sll   $t4, $t3, 0xe
  or    $t5, $t9, $t4
  sw    $t5, ($v0)
  lwc1  $f8, 0xac($sp)
  lwc1  $f4, 0xb4($sp)
  lwc1  $f6, 0xa8($sp)
  lwc1  $f18, 0xb0($sp)
  sub.s $f16, $f4, $f8
  sub.s $f4, $f18, $f6
  trunc.w.s $f10, $f16
  trunc.w.s $f8, $f4
  mfc1  $t7, $f10
  mfc1  $t3, $f8
  addiu $t8, $t7, -1
  andi  $t0, $t8, 0x3ff
  addiu $t9, $t3, -1
  andi  $t4, $t9, 0x3ff
  sll   $t5, $t4, 0xe
  sll   $t1, $t0, 2
  or    $t6, $t1, $t5
  sw    $t6, 4($v0)
  lw    $t7, 0xd4($sp)
  beqz  $t7, .L7F06987C
   nop   
  b     .L7F06987C
   li    $a2, 2
.L7F06987C:
  jal   likely_generate_DL_for_image_declaration
   sw    $zero, 0x10($sp)
  lbu   $t8, 5($s0)
  lbu   $a3, 4($s0)
  lw    $t2, 0xd8($sp)
  lw    $t3, 0xdc($sp)
  lw    $t9, 0xe0($sp)
  lw    $t4, 0xe4($sp)
  li    $t0, 1
  sw    $t0, 0x1c($sp)
  sw    $zero, 0x18($sp)
  sw    $zero, 0x14($sp)
  sw    $t8, 0x10($sp)
  sw    $t2, 0x20($sp)
  sw    $t3, 0x24($sp)
  sw    $t9, 0x28($sp)
  sw    $t4, 0x2c($sp)
  lbu   $t1, 6($s0)
  sw    $zero, 0x34($sp)
  addiu $a0, $sp, 0xb8
  slt   $t5, $zero, $t1
  sw    $t5, 0x30($sp)
  addiu $a1, $sp, 0xb0
  jal   display_image_at_on_screen_coord
   addiu $a2, $sp, 0xa8
  lw    $t6, 0xb8($sp)
  lui   $t8, 0xe700
  lui   $t3, (0xBA000602 >> 16) # lui $t3, 0xba00
  addiu $t7, $t6, 8
  sw    $t7, 0xb8($sp)
  sw    $zero, 4($t6)
  sw    $t8, ($t6)
  lw    $t0, 0xb8($sp)
  ori   $t3, (0xBA000602 & 0xFFFF) # ori $t3, $t3, 0x602
  li    $t9, 64
  addiu $t2, $t0, 8
  sw    $t2, 0xb8($sp)
  sw    $t9, 4($t0)
  sw    $t3, ($t0)
  lw    $t4, 0xb8($sp)
  lui   $t5, (0xBA001301 >> 16) # lui $t5, 0xba00
  ori   $t5, (0xBA001301 & 0xFFFF) # ori $t5, $t5, 0x1301
  addiu $t1, $t4, 8
  sw    $t1, 0xb8($sp)
  lui   $t6, 8
  sw    $t6, 4($t4)
  sw    $t5, ($t4)
  lw    $t7, 0xb8($sp)
  lui   $t0, (0xB9000002 >> 16) # lui $t0, 0xb900
  ori   $t0, (0xB9000002 & 0xFFFF) # ori $t0, $t0, 2
  addiu $t8, $t7, 8
  sw    $t8, 0xb8($sp)
  sw    $zero, 4($t7)
  sw    $t0, ($t7)
  lw    $t2, 0xb8($sp)
  lui   $t9, (0xBA001001 >> 16) # lui $t9, 0xba00
  ori   $t9, (0xBA001001 & 0xFFFF) # ori $t9, $t9, 0x1001
  addiu $t3, $t2, 8
  sw    $t3, 0xb8($sp)
  lui   $t4, 1
  sw    $t4, 4($t2)
  sw    $t9, ($t2)
  lw    $t1, 0xb8($sp)
  lui   $t6, (0xBA000C02 >> 16) # lui $t6, 0xba00
  ori   $t6, (0xBA000C02 & 0xFFFF) # ori $t6, $t6, 0xc02
  addiu $t5, $t1, 8
  sw    $t5, 0xb8($sp)
  li    $t7, 8192
  sw    $t7, 4($t1)
  sw    $t6, ($t1)
  lw    $t8, 0xb8($sp)
  lui   $t2, (0xBA000903 >> 16) # lui $t2, 0xba00
  ori   $t2, (0xBA000903 & 0xFFFF) # ori $t2, $t2, 0x903
  addiu $t0, $t8, 8
  sw    $t0, 0xb8($sp)
  li    $t3, 3072
  sw    $t3, 4($t8)
  sw    $t2, ($t8)
  lw    $t9, 0xb8($sp)
  lui   $t1, (0xBA000E02 >> 16) # lui $t1, 0xba00
  ori   $t1, (0xBA000E02 & 0xFFFF) # ori $t1, $t1, 0xe02
  addiu $t4, $t9, 8
  sw    $t4, 0xb8($sp)
  sw    $zero, 4($t9)
  sw    $t1, ($t9)
  lw    $ra, 0x44($sp)
  lw    $s0, 0x40($sp)
  lw    $v0, 0xb8($sp)
  jr    $ra
   addiu $sp, $sp, 0xb8
");

asm(R"
glabel set_rgba_redirect_generate_microcode
  addiu $sp, $sp, -0x38
  mtc1  $a2, $f12
  mtc1  $a3, $f14
  lwc1  $f4, 0x48($sp)
  lw    $t6, 0x4c($sp)
  lwc1  $f6, 0x50($sp)
  lw    $t7, 0x54($sp)
  sw    $ra, 0x34($sp)
  li    $t8, 255
  li    $t9, 255
  li    $t0, 255
  li    $t1, 255
  mfc1  $a2, $f12
  mfc1  $a3, $f14
  sw    $t1, 0x2c($sp)
  sw    $t0, 0x28($sp)
  sw    $t9, 0x24($sp)
  sw    $t8, 0x20($sp)
  swc1  $f4, 0x10($sp)
  sw    $t6, 0x14($sp)
  swc1  $f6, 0x18($sp)
  jal   microcode_generation_ammo_related
   sw    $t7, 0x1c($sp)
  lw    $ra, 0x34($sp)
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   
");

asm(R"
glabel some_kind_of_display_routine
  addiu $sp, $sp, -0x60
  lui   $t6, %hi(ptrFirstFontTableSmall) 
  lw    $t6, %lo(ptrFirstFontTableSmall)($t6)
  sw    $s0, 0x38($sp)
  sw    $a3, 0x6c($sp)
  move  $s0, $a0
  sw    $ra, 0x3c($sp)
  sw    $a1, 0x64($sp)
  sw    $a2, 0x68($sp)
  lui   $a3, %hi(ptrSecondFontTableSmall)
  sw    $zero, 0x5c($sp)
  sw    $zero, 0x58($sp)
  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
  lw    $a2, 0x64($sp)
  addiu $a1, $sp, 0x48
  addiu $a0, $sp, 0x4c
  sw    $zero, 0x14($sp)
  sw    $zero, 0x54($sp)
  sw    $zero, 0x50($sp)
  sw    $zero, 0x48($sp)
  sw    $zero, 0x4c($sp)
  jal   sub_GAME_7F0AE98C
   sw    $t6, 0x10($sp)
  lw    $v1, 0x6c($sp)
  li    $a0, 1
  lw    $v0, 0x68($sp)
  bne   $v1, $a0, .L7F069AD4
   addiu $a1, $sp, 0x5c
  lw    $t1, 0x48($sp)
  sw    $v0, 0x5c($sp)
  addu  $v1, $v0, $t1
  b     .L7F069B18
   sw    $v1, 0x54($sp)
.L7F069AD4:
  bnez  $v1, .L7F069AF0
   li    $at, 2
  lw    $t1, 0x48($sp)
  sw    $v0, 0x54($sp)
  subu  $t7, $v0, $t1
  b     .L7F069B18
   sw    $t7, 0x5c($sp)
.L7F069AF0:
  bne   $v1, $at, .L7F069B18
   lw    $t1, 0x48($sp)
  bgez  $t1, .L7F069B08
   sra   $t8, $t1, 1
  addiu $at, $t1, 1
  sra   $t8, $at, 1
.L7F069B08:
  addu  $v1, $t8, $v0
  subu  $t9, $v1, $t1
  sw    $t9, 0x5c($sp)
  sw    $v1, 0x54($sp)
.L7F069B18:
  lw    $v0, 0x74($sp)
  addiu $a2, $sp, 0x58
  addiu $a3, $sp, 0x54
  bne   $v0, $a0, .L7F069B44
   addiu $t6, $sp, 0x50
  lw    $v0, 0x70($sp)
  lw    $t2, 0x4c($sp)
  sw    $v0, 0x58($sp)
  addu  $t0, $v0, $t2
  b     .L7F069B90
   sw    $t0, 0x50($sp)
.L7F069B44:
  bnez  $v0, .L7F069B64
   li    $at, 2
  lw    $v0, 0x70($sp)
  lw    $t2, 0x4c($sp)
  sw    $v0, 0x50($sp)
  subu  $t3, $v0, $t2
  b     .L7F069B90
   sw    $t3, 0x58($sp)
.L7F069B64:
  bne   $v0, $at, .L7F069B90
   lw    $t2, 0x4c($sp)
  lw    $v0, 0x70($sp)
  bgez  $t2, .L7F069B80
   sra   $t4, $t2, 1
  addiu $at, $t2, 1
  sra   $t4, $at, 1
.L7F069B80:
  addu  $t0, $t4, $v0
  subu  $t5, $t0, $t2
  sw    $t5, 0x58($sp)
  sw    $t0, 0x50($sp)
.L7F069B90:
  move  $a0, $s0
  jal   draw_blackbox_to_screen
   sw    $t6, 0x10($sp)
  lw    $t7, 0x78($sp)
  move  $s0, $v0
  beqz  $t7, .L7F069C18
   nop   
  jal   get_video2_settings_txtClipW
   nop   
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lui   $t8, %hi(ptrSecondFontTableSmall) 
  lui   $t9, %hi(ptrFirstFontTableSmall) 
  lw    $t9, %lo(ptrFirstFontTableSmall)($t9)
  lw    $t8, %lo(ptrSecondFontTableSmall)($t8)
  lh    $t5, 0x44($sp)
  lui   $t4, (0x646464FF >> 16) # lui $t4, 0x6464
  ori   $t4, (0x646464FF & 0xFFFF) # ori $t4, $t4, 0x64ff
  li    $t3, -1
  sw    $t3, 0x18($sp)
  sw    $t4, 0x1c($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x5c
  addiu $a2, $sp, 0x58
  lw    $a3, 0x64($sp)
  sw    $v0, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $zero, 0x2c($sp)
  sw    $t9, 0x14($sp)
  sw    $t8, 0x10($sp)
  jal   jp_text_write_stuff
   sw    $t5, 0x20($sp)
  b     .L7F069C78
   move  $s0, $v0
.L7F069C18:
  jal   get_video2_settings_txtClipW
   nop   
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x44($sp)
  lui   $t6, %hi(ptrSecondFontTableSmall) 
  lui   $t7, %hi(ptrFirstFontTableSmall) 
  lw    $t7, %lo(ptrFirstFontTableSmall)($t7)
  lw    $t6, %lo(ptrSecondFontTableSmall)($t6)
  lh    $t9, 0x44($sp)
  lui   $t8, (0x00FF00B0 >> 16) # lui $t8, 0xff
  ori   $t8, (0x00FF00B0 & 0xFFFF) # ori $t8, $t8, 0xb0
  sw    $t8, 0x18($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x5c
  addiu $a2, $sp, 0x58
  lw    $a3, 0x64($sp)
  sw    $v0, 0x20($sp)
  sw    $zero, 0x24($sp)
  sw    $zero, 0x28($sp)
  sw    $t7, 0x14($sp)
  sw    $t6, 0x10($sp)
  jal   en_text_write_stuff
   sw    $t9, 0x1c($sp)
  move  $s0, $v0
.L7F069C78:
  lw    $ra, 0x3c($sp)
  move  $v0, $s0
  lw    $s0, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x60
");

asm(R"
glabel display_ammo_total_in_a1
  addiu $sp, $sp, -0x38
  sw    $a2, 0x40($sp)
  move  $a2, $a1
  sw    $a1, 0x3c($sp)
  sw    $ra, 0x24($sp)
  sw    $a0, 0x38($sp)
  lui   $a1, %hi(aD_9)
  sw    $a3, 0x44($sp)
  addiu $a1, %lo(aD_9) # addiu $a1, $a1, 0x3bf4
  jal   sprintf
   addiu $a0, $sp, 0x2c
  lw    $t6, 0x48($sp)
  lw    $t7, 0x4c($sp)
  lw    $t8, 0x50($sp)
  lw    $a0, 0x38($sp)
  addiu $a1, $sp, 0x2c
  lw    $a2, 0x40($sp)
  lw    $a3, 0x44($sp)
  sw    $t6, 0x10($sp)
  sw    $t7, 0x14($sp)
  jal   some_kind_of_display_routine
   sw    $t8, 0x18($sp)
  lw    $ra, 0x24($sp)
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   
");

asm(R"
glabel generate_ammo_total_microcode
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  addiu $sp, $sp, -0x68
  sw    $ra, 0x24($sp)
  sw    $a0, 0x68($sp)
  lw    $t6, 0x1064($v0)
  bnezl $t6, .L7F06A324
   lw    $ra, 0x24($sp)
  lw    $t7, 0x29c4($v0)
  bnezl $t7, .L7F06A324
   lw    $ra, 0x24($sp)
  jal   get_item_in_hand
   li    $a0, 1
  sw    $v0, 0x64($sp)
  jal   get_item_in_hand
   move  $a0, $zero
  jal   getPlayerCount
   sw    $v0, 0x60($sp)
  slti  $at, $v0, 3
  beqz  $at, .L7F069D58
   li    $t8, 59
  li    $t9, 59
  sw    $t8, 0x58($sp)
  b     .L7F069D8C
   sw    $t9, 0x54($sp)
.L7F069D58:
  jal   get_cur_playernum
   nop   
  andi  $t0, $v0, 1
  beqz  $t0, .L7F069D80
   li    $t3, 59
  li    $t1, 43
  li    $t2, 127
  sw    $t1, 0x58($sp)
  b     .L7F069D8C
   sw    $t2, 0x54($sp)
.L7F069D80:
  li    $t4, 109
  sw    $t3, 0x58($sp)
  sw    $t4, 0x54($sp)
.L7F069D8C:
  lw    $t5, 0x60($sp)
  beql  $t5, $zero, .L7F06A070
   lw    $a0, 0x64($sp)
  jal   get_ammo_type_for_weapon
   move  $a0, $t5
  beqz  $v0, .L7F06A06C
   sw    $v0, 0x5c($sp)
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  li    $at, 6
  lw    $v0, 0x894($t6)
  beq   $v0, $at, .L7F06A06C
   li    $at, 7
  beq   $v0, $at, .L7F06A06C
   lw    $a0, 0x60($sp)
  jal   check_special_attributes
   lui   $a1, 8
  bnez  $v0, .L7F06A06C
   lw    $t7, 0x5c($sp)
  sll   $t8, $t7, 2
  subu  $t8, $t8, $t7
  lui   $t9, %hi(ammo_related) 
  addiu $t9, %lo(ammo_related) # addiu $t9, $t9, 0x5ef0
  sll   $t8, $t8, 2
  addu  $v1, $t8, $t9
  lw    $v0, 4($v1)
  li    $t0, 5
  sw    $t0, 0x44($sp)
  beqz  $v0, .L7F069EA0
   lui   $t1, %hi(globalbank_rdram_offset) 
  lw    $t1, %lo(globalbank_rdram_offset)($t1)
  sw    $v1, 0x28($sp)
  addu  $v0, $v0, $t1
  jal   getPlayer_c_screenleft
   sw    $v0, 0x48($sp)
  jal   getPlayer_c_screenwidth
   swc1  $f0, 0x30($sp)
  jal   get_video2_settings_uly
   swc1  $f0, 0x34($sp)
  jal   get_video2_settings_height
   sh    $v0, 0x38($sp)
  lw    $t2, 0x54($sp)
  lh    $t3, 0x38($sp)
  lwc1  $f4, 0x34($sp)
  lwc1  $f6, 0x30($sp)
  mtc1  $t2, $f10
  addu  $t4, $v0, $t3
  add.s $f8, $f4, $f6
  addiu $t5, $t4, -0x14
  mtc1  $t5, $f4
  cvt.s.w $f16, $f10
  lw    $t6, 0x28($sp)
  sw    $zero, 0x14($sp)
  li    $t7, 1
  lw    $a0, 0x68($sp)
  cvt.s.w $f6, $f4
  lw    $a1, 0x48($sp)
  lui   $a3, 0xbf80
  sub.s $f18, $f8, $f16
  swc1  $f6, 0x10($sp)
  lwc1  $f10, 8($t6)
  sw    $t7, 0x1c($sp)
  mfc1  $a2, $f18
  jal   set_rgba_redirect_generate_microcode
   swc1  $f10, 0x18($sp)
  lw    $t8, 0x48($sp)
  sw    $v0, 0x68($sp)
  lbu   $t9, 4($t8)
  sw    $t9, 0x44($sp)
.L7F069EA0:
  jal   microcode_constructor
   lw    $a0, 0x68($sp)
  sw    $v0, 0x68($sp)
  lw    $a0, 0x60($sp)
  jal   check_special_attributes
   lui   $a1, 0x40
  beqz  $v0, .L7F069F00
   lui   $a1, 0x40
  lw    $t1, 0x5c($sp)
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  sw    $zero, 0x4c($sp)
  sll   $t2, $t1, 2
  lw    $t5, 0x64($sp)
  lw    $t6, 0x60($sp)
  addu  $t3, $v0, $t2
  lw    $t4, 0x1130($t3)
  lw    $t0, 0x89c($v0)
  bne   $t5, $t6, .L7F069EF8
   addu  $v1, $t0, $t4
  lw    $t7, 0xc44($v0)
  addu  $v1, $v1, $t7
.L7F069EF8:
  b     .L7F069F24
   sw    $v1, 0x50($sp)
.L7F069F00:
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lw    $t9, 0x5c($sp)
  lw    $t8, 0x89c($v0)
  sll   $t1, $t9, 2
  addu  $t2, $v0, $t1
  sw    $t8, 0x4c($sp)
  lw    $t3, 0x1130($t2)
  sw    $t3, 0x50($sp)
.L7F069F24:
  jal   check_special_attributes
   lw    $a0, 0x60($sp)
  bnezl $v0, .L7F069FBC
   lw    $t5, 0x50($sp)
  jal   get_video2_settings_ulx
   nop   
  jal   get_video2_settings_width
   sh    $v0, 0x2c($sp)
  jal   get_video2_settings_uly
   sh    $v0, 0x2e($sp)
  jal   get_video2_settings_height
   sh    $v0, 0x38($sp)
  lh    $t0, 0x2e($sp)
  lh    $t4, 0x2c($sp)
  lw    $t6, 0x54($sp)
  lw    $t8, 0x44($sp)
  lh    $t1, 0x38($sp)
  addu  $t5, $t0, $t4
  subu  $t7, $t5, $t6
  addu  $t2, $v0, $t1
  addiu $t3, $t2, -0x12
  li    $t4, 1
  li    $t0, 2
  sw    $t0, 0x14($sp)
  sw    $t4, 0x18($sp)
  sw    $t3, 0x10($sp)
  lw    $a0, 0x68($sp)
  lw    $a1, 0x4c($sp)
  bgez  $t8, .L7F069FA4
   sra   $t9, $t8, 1
  addiu $at, $t8, 1
  sra   $t9, $at, 1
.L7F069FA4:
  subu  $a2, $t7, $t9
  addiu $a2, $a2, -4
  jal   display_ammo_total_in_a1
   move  $a3, $zero
  sw    $v0, 0x68($sp)
  lw    $t5, 0x50($sp)
.L7F069FBC:
  lw    $a0, 0x60($sp)
  bgtz  $t5, .L7F069FD8
   nop   
  jal   check_special_attributes
   lui   $a1, 0x40
  beqz  $v0, .L7F06A060
   nop   
.L7F069FD8:
  jal   get_video2_settings_ulx
   nop   
  jal   get_video2_settings_width
   sh    $v0, 0x2c($sp)
  jal   get_video2_settings_uly
   sh    $v0, 0x2e($sp)
  jal   get_video2_settings_height
   sh    $v0, 0x38($sp)
  lh    $t6, 0x2e($sp)
  lh    $t8, 0x2c($sp)
  lw    $t9, 0x54($sp)
  lw    $t2, 0x44($sp)
  lh    $t4, 0x38($sp)
  addu  $t7, $t6, $t8
  subu  $t1, $t7, $t9
  addiu $t3, $t2, 1
  addu  $t5, $v0, $t4
  addiu $t6, $t5, -0x12
  li    $t7, 1
  li    $t8, 2
  sw    $t8, 0x14($sp)
  sw    $t7, 0x18($sp)
  sw    $t6, 0x10($sp)
  lw    $a0, 0x68($sp)
  lw    $a1, 0x50($sp)
  bgez  $t3, .L7F06A04C
   sra   $t0, $t3, 1
  addiu $at, $t3, 1
  sra   $t0, $at, 1
.L7F06A04C:
  addu  $a2, $t1, $t0
  addiu $a2, $a2, 3
  jal   display_ammo_total_in_a1
   li    $a3, 1
  sw    $v0, 0x68($sp)
.L7F06A060:
  jal   combiner_bayer_lod_perspective
   lw    $a0, 0x68($sp)
  sw    $v0, 0x68($sp)
.L7F06A06C:
  lw    $a0, 0x64($sp)
.L7F06A070:
  beql  $a0, $zero, .L7F06A324
   lw    $ra, 0x24($sp)
  jal   get_ammo_type_for_weapon
   nop   
  beqz  $v0, .L7F06A320
   sw    $v0, 0x5c($sp)
  lui   $t9, %hi(pPlayer) 
  lw    $t9, %lo(pPlayer)($t9)
  li    $at, 6
  lw    $v0, 0xc3c($t9)
  beq   $v0, $at, .L7F06A320
   li    $at, 7
  beq   $v0, $at, .L7F06A320
   lw    $a0, 0x64($sp)
  jal   check_special_attributes
   lui   $a1, 8
  bnez  $v0, .L7F06A320
   lw    $t2, 0x5c($sp)
  sll   $t3, $t2, 2
  subu  $t3, $t3, $t2
  lui   $t1, %hi(ammo_related) 
  addiu $t1, %lo(ammo_related) # addiu $t1, $t1, 0x5ef0
  sll   $t3, $t3, 2
  addu  $v1, $t3, $t1
  lw    $v0, 4($v1)
  li    $t0, 5
  sw    $t0, 0x3c($sp)
  beqz  $v0, .L7F06A174
   lui   $t4, %hi(globalbank_rdram_offset) 
  lw    $t4, %lo(globalbank_rdram_offset)($t4)
  sw    $v1, 0x28($sp)
  addu  $v0, $v0, $t4
  jal   getPlayer_c_screenleft
   sw    $v0, 0x40($sp)
  jal   get_video2_settings_uly
   swc1  $f0, 0x34($sp)
  jal   get_video2_settings_height
   sh    $v0, 0x38($sp)
  lw    $t5, 0x58($sp)
  lh    $t6, 0x38($sp)
  lwc1  $f18, 0x34($sp)
  mtc1  $t5, $f16
  lw    $t2, 0x28($sp)
  addu  $t8, $v0, $t6
  cvt.s.w $f16, $f16
  addiu $t7, $t8, -0x14
  mtc1  $t7, $f14
  li    $t9, 1
  sw    $t9, 0x14($sp)
  cvt.s.w $f14, $f14
  li    $t3, 1
  lw    $a0, 0x68($sp)
  lw    $a1, 0x40($sp)
  lui   $a3, 0xbf80
  add.s $f16, $f18, $f16
  swc1  $f14, 0x10($sp)
  lwc1  $f14, 8($t2)
  sw    $t3, 0x1c($sp)
  mfc1  $a2, $f16
  jal   set_rgba_redirect_generate_microcode
   swc1  $f14, 0x18($sp)
  lw    $t1, 0x40($sp)
  sw    $v0, 0x68($sp)
  lbu   $t0, 4($t1)
  sw    $t0, 0x3c($sp)
.L7F06A174:
  jal   microcode_constructor
   lw    $a0, 0x68($sp)
  sw    $v0, 0x68($sp)
  lw    $a0, 0x64($sp)
  jal   check_special_attributes
   lui   $a1, 0x40
  beqz  $v0, .L7F06A1D4
   lui   $a1, 0x40
  lw    $t5, 0x5c($sp)
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  sw    $zero, 0x4c($sp)
  sll   $t6, $t5, 2
  lw    $t9, 0x64($sp)
  lw    $t2, 0x60($sp)
  addu  $t8, $v0, $t6
  lw    $t7, 0x1130($t8)
  lw    $t4, 0xc44($v0)
  bne   $t9, $t2, .L7F06A1CC
   addu  $v1, $t4, $t7
  lw    $t3, 0x89c($v0)
  addu  $v1, $v1, $t3
.L7F06A1CC:
  b     .L7F06A1F8
   sw    $v1, 0x50($sp)
.L7F06A1D4:
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lw    $t0, 0x5c($sp)
  lw    $t1, 0xc44($v0)
  sll   $t5, $t0, 2
  addu  $t6, $v0, $t5
  sw    $t1, 0x4c($sp)
  lw    $t8, 0x1130($t6)
  sw    $t8, 0x50($sp)
.L7F06A1F8:
  jal   check_special_attributes
   lw    $a0, 0x64($sp)
  bnezl $v0, .L7F06A280
   lw    $t4, 0x50($sp)
  jal   get_video2_settings_ulx
   nop   
  jal   get_video2_settings_uly
   sh    $v0, 0x2e($sp)
  jal   get_video2_settings_height
   sh    $v0, 0x38($sp)
  lh    $t4, 0x2e($sp)
  lw    $t7, 0x58($sp)
  lw    $t2, 0x3c($sp)
  lh    $t1, 0x38($sp)
  addu  $t9, $t4, $t7
  li    $t6, 2
  addu  $t0, $v0, $t1
  addiu $t5, $t0, -0x12
  li    $t8, 1
  sw    $t8, 0x18($sp)
  sw    $t5, 0x10($sp)
  sw    $t6, 0x14($sp)
  lw    $a0, 0x68($sp)
  lw    $a1, 0x4c($sp)
  bgez  $t2, .L7F06A268
   sra   $t3, $t2, 1
  addiu $at, $t2, 1
  sra   $t3, $at, 1
.L7F06A268:
  addu  $a2, $t9, $t3
  addiu $a2, $a2, 3
  jal   display_ammo_total_in_a1
   li    $a3, 1
  sw    $v0, 0x68($sp)
  lw    $t4, 0x50($sp)
.L7F06A280:
  lw    $a0, 0x64($sp)
  bgtz  $t4, .L7F06A29C
   nop   
  jal   check_special_attributes
   lui   $a1, 0x40
  beqz  $v0, .L7F06A314
   nop   
.L7F06A29C:
  jal   get_video2_settings_ulx
   nop   
  jal   get_video2_settings_uly
   sh    $v0, 0x2e($sp)
  jal   get_video2_settings_height
   sh    $v0, 0x38($sp)
  lh    $t7, 0x2e($sp)
  lw    $t2, 0x58($sp)
  lw    $t3, 0x3c($sp)
  lh    $t5, 0x38($sp)
  addu  $t9, $t7, $t2
  addiu $t1, $t3, 1
  addu  $t6, $v0, $t5
  addiu $t8, $t6, -0x12
  li    $t7, 1
  li    $t4, 2
  sw    $t4, 0x14($sp)
  sw    $t7, 0x18($sp)
  sw    $t8, 0x10($sp)
  lw    $a0, 0x68($sp)
  lw    $a1, 0x50($sp)
  bgez  $t1, .L7F06A300
   sra   $t0, $t1, 1
  addiu $at, $t1, 1
  sra   $t0, $at, 1
.L7F06A300:
  subu  $a2, $t9, $t0
  addiu $a2, $a2, -4
  jal   display_ammo_total_in_a1
   move  $a3, $zero
  sw    $v0, 0x68($sp)
.L7F06A314:
  jal   combiner_bayer_lod_perspective
   lw    $a0, 0x68($sp)
  sw    $v0, 0x68($sp)
.L7F06A320:
  lw    $ra, 0x24($sp)
.L7F06A324:
  lw    $v0, 0x68($sp)
  addiu $sp, $sp, 0x68
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F06A334
  addiu $sp, $sp, -0x58
  sw    $s0, 0x28($sp)
  move  $s0, $a0
  sw    $ra, 0x2c($sp)
  jal   get_item_in_hand
   li    $a0, 1
  sw    $v0, 0x54($sp)
  jal   get_item_in_hand
   move  $a0, $zero
  beqz  $v0, .L7F06A594
   move  $a0, $v0
  jal   get_ammo_type_for_weapon
   sw    $v0, 0x50($sp)
  beqz  $v0, .L7F06A594
   sw    $v0, 0x4c($sp)
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  li    $at, 6
  lw    $v0, 0x894($t6)
  beq   $v0, $at, .L7F06A594
   li    $at, 7
  beq   $v0, $at, .L7F06A594
   lw    $a0, 0x50($sp)
  jal   check_special_attributes
   lui   $a1, 8
  bnez  $v0, .L7F06A594
   lw    $t7, 0x4c($sp)
  sll   $t8, $t7, 2
  subu  $t8, $t8, $t7
  lui   $t9, %hi(ammo_related) 
  addiu $t9, %lo(ammo_related) # addiu $t9, $t9, 0x5ef0
  sll   $t8, $t8, 2
  addu  $v0, $t8, $t9
  lw    $t0, 4($v0)
  li    $t1, 5
  sw    $t1, 0x3c($sp)
  sw    $v0, 0x30($sp)
  lw    $a0, 0x50($sp)
  jal   get_ptr_item_statistics
   sw    $t0, 0x40($sp)
  lw    $v1, 0x40($sp)
  lui   $t2, %hi(globalbank_rdram_offset) 
  beqz  $v1, .L7F06A450
   nop   
  lw    $t2, %lo(globalbank_rdram_offset)($t2)
  addu  $v1, $v1, $t2
  jal   get_video2_settings_uly
   sw    $v1, 0x40($sp)
  jal   get_video2_settings_height
   sh    $v0, 0x34($sp)
  lh    $t3, 0x34($sp)
  lw    $t6, 0x30($sp)
  sw    $zero, 0x14($sp)
  addu  $t4, $v0, $t3
  addiu $t5, $t4, -0x14
  mtc1  $t5, $f4
  li    $t7, 1
  move  $a0, $s0
  cvt.s.w $f6, $f4
  lw    $a1, 0x40($sp)
  lui   $a2, 0x4348
  lui   $a3, 0x4334
  swc1  $f6, 0x10($sp)
  lwc1  $f8, 8($t6)
  sw    $t7, 0x1c($sp)
  jal   set_rgba_redirect_generate_microcode
   swc1  $f8, 0x18($sp)
  lw    $t8, 0x40($sp)
  move  $s0, $v0
  lbu   $t9, 4($t8)
  sw    $t9, 0x3c($sp)
.L7F06A450:
  jal   microcode_constructor
   move  $a0, $s0
  move  $s0, $v0
  lw    $a0, 0x50($sp)
  jal   check_special_attributes
   lui   $a1, 0x40
  beqz  $v0, .L7F06A4B0
   lui   $a1, 0x40
  lw    $t1, 0x4c($sp)
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  sw    $zero, 0x44($sp)
  sll   $t2, $t1, 2
  lw    $t5, 0x54($sp)
  lw    $t6, 0x50($sp)
  addu  $t3, $v0, $t2
  lw    $t4, 0x1130($t3)
  lw    $t0, 0x89c($v0)
  bne   $t5, $t6, .L7F06A4A8
   addu  $v1, $t0, $t4
  lw    $t7, 0xc44($v0)
  addu  $v1, $v1, $t7
.L7F06A4A8:
  b     .L7F06A4D4
   sw    $v1, 0x48($sp)
.L7F06A4B0:
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lw    $t9, 0x4c($sp)
  lw    $t8, 0x89c($v0)
  sll   $t1, $t9, 2
  addu  $t2, $v0, $t1
  sw    $t8, 0x44($sp)
  lw    $t3, 0x1130($t2)
  sw    $t3, 0x48($sp)
.L7F06A4D4:
  jal   check_special_attributes
   lw    $a0, 0x50($sp)
  bnez  $v0, .L7F06A524
   move  $a0, $s0
  lw    $t0, 0x3c($sp)
  li    $t5, 196
  li    $t6, 177
  li    $t7, 2
  sw    $t7, 0x14($sp)
  sw    $t6, 0x10($sp)
  lw    $a1, 0x44($sp)
  bgez  $t0, .L7F06A510
   sra   $t4, $t0, 1
  addiu $at, $t0, 1
  sra   $t4, $at, 1
.L7F06A510:
  subu  $a2, $t5, $t4
  move  $a3, $zero
  jal   display_ammo_total_in_a1
   sw    $zero, 0x18($sp)
  move  $s0, $v0
.L7F06A524:
  lw    $t8, 0x48($sp)
  lw    $a0, 0x50($sp)
  bgtzl $t8, .L7F06A548
   lw    $a2, 0x3c($sp)
  jal   check_special_attributes
   lui   $a1, 0x40
  beqz  $v0, .L7F06A588
   nop   
  lw    $a2, 0x3c($sp)
.L7F06A548:
  li    $t1, 177
  li    $t2, 2
  addiu $a2, $a2, 1
  sw    $t2, 0x14($sp)
  sw    $t1, 0x10($sp)
  move  $a0, $s0
  lw    $a1, 0x48($sp)
  bgez  $a2, .L7F06A574
   sra   $t9, $a2, 1
  addiu $at, $a2, 1
  sra   $t9, $at, 1
.L7F06A574:
  addiu $a2, $t9, 0xcb
  li    $a3, 1
  jal   display_ammo_total_in_a1
   sw    $zero, 0x18($sp)
  move  $s0, $v0
.L7F06A588:
  jal   combiner_bayer_lod_perspective
   move  $a0, $s0
  move  $s0, $v0
.L7F06A594:
  lw    $ra, 0x2c($sp)
  move  $v0, $s0
  lw    $s0, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x58
");

asm(R"
glabel set_unset_bitflags
  beqz  $a1, .L7F06A5CC
   lui   $v0, %hi(pPlayer)
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  not   $t7, $a0
  lw    $t6, 0x1128($v0)
  and   $t8, $t6, $t7
  jr    $ra
   sw    $t8, 0x1128($v0)

.L7F06A5CC:
  lw    $v0, %lo(pPlayer)($v0)
  lw    $t9, 0x1128($v0)
  or    $t0, $t9, $a0
  sw    $t0, 0x1128($v0)
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F06A5E4
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  addiu $sp, $sp, -0x58
  sw    $ra, 0x3c($sp)
  sw    $a0, 0x58($sp)
  lw    $t6, 0x1128($v0)
  bnezl $t6, .L7F06A6EC
   lw    $ra, 0x3c($sp)
  lw    $t7, 0x29c4($v0)
  lui   $a1, %hi(crosshairimage)
  li    $a2, 4
  bnez  $t7, .L7F06A6E8
   move  $a3, $zero
  lw    $t9, ($a0)
  sw    $zero, 0x10($sp)
  addiu $a0, $sp, 0x54
  lw    $a1, %lo(crosshairimage)($a1)
  jal   likely_generate_DL_for_image_declaration
   sw    $t9, 0x54($sp)
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  li    $at, 0x41800000 # 16.000000
  mtc1  $at, $f0
  lwc1  $f4, 0xfe8($v0)
  swc1  $f4, 0x4c($sp)
  lwc1  $f6, 0xfec($v0)
  swc1  $f0, 0x44($sp)
  swc1  $f0, 0x48($sp)
  jal   get_screen_ratio
   swc1  $f6, 0x50($sp)
  li    $at, 1
  bne   $v0, $at, .L7F06A67C
   addiu $a0, $sp, 0x54
  li    $at, 0x3F400000 # 0.750000
  mtc1  $at, $f10
  lwc1  $f8, 0x44($sp)
  mul.s $f16, $f8, $f10
  swc1  $f16, 0x44($sp)
.L7F06A67C:
  lui   $t6, %hi(crosshairimage) 
  lw    $t6, %lo(crosshairimage)($t6)
  li    $t0, 32
  li    $t1, 1
  li    $t2, 255
  li    $t3, 255
  li    $t4, 255
  li    $t5, 110
  sw    $t5, 0x2c($sp)
  sw    $t4, 0x28($sp)
  sw    $t3, 0x24($sp)
  sw    $t2, 0x20($sp)
  sw    $t1, 0x1c($sp)
  sw    $t0, 0x10($sp)
  sw    $zero, 0x14($sp)
  sw    $zero, 0x18($sp)
  lbu   $t7, 6($t6)
  sw    $zero, 0x34($sp)
  addiu $a1, $sp, 0x4c
  slt   $t8, $zero, $t7
  sw    $t8, 0x30($sp)
  addiu $a2, $sp, 0x44
  jal   display_image_at_on_screen_coord
   li    $a3, 32
  lw    $t9, 0x54($sp)
  lw    $t0, 0x58($sp)
  sw    $t9, ($t0)
.L7F06A6E8:
  lw    $ra, 0x3c($sp)
.L7F06A6EC:
  addiu $sp, $sp, 0x58
  jr    $ra
   nop   
");

asm(R"
glabel inc_curplayer_hitcount_with_weapon
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a1, 0x1c($sp)
  jal   check_special_attributes
   lui   $a1, 1
  beqz  $v0, .L7F06A730
   lui   $t6, %hi(pPlayersPerm) 
  lw    $t7, 0x1c($sp)
  lw    $t6, %lo(pPlayersPerm)($t6)
  sll   $t8, $t7, 2
  addu  $v0, $t6, $t8
  lw    $t9, ($v0)
  addiu $t0, $t9, 1
  sw    $t0, ($v0)
.L7F06A730:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel get_curplayer_shot_register
  lui   $t6, %hi(pPlayersPerm) 
  lw    $t6, %lo(pPlayersPerm)($t6)
  sll   $t7, $a0, 2
  addu  $t8, $t6, $t7
  jr    $ra
   lw    $v0, ($t8)
");

asm(R"
glabel inc_cur_civilian_casualties
  lui   $v0, %hi(pPlayersPerm)
  lw    $v0, %lo(pPlayersPerm)($v0)
  lw    $t6, 0x6c($v0)
  addiu $t7, $t6, 1
  jr    $ra
   sw    $t7, 0x6c($v0)
");

asm(R"
glabel get_civilian_casualties
  lui   $t6, %hi(pPlayersPerm) 
  lw    $t6, %lo(pPlayersPerm)($t6)
  jr    $ra
   lw    $v0, 0x6c($t6)
");

#ifdef VERSION_US
asm(R"
glabel increment_num_kills_display_text_in_MP
  lui   $v1, %hi(pPlayersPerm)
  lw    $v1, %lo(pPlayersPerm)($v1)
  addiu $sp, $sp, -0x140
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  lw    $t6, 0x1c($v1)
  lui   $s0, %hi(pPlayer)
  addiu $s0, %lo(pPlayer) # addiu $s0, $s0, -0x5f50
  addiu $t7, $t6, 1
  sw    $t7, 0x1c($v1)
  lw    $v0, ($s0)
  lw    $t8, 0x29f8($v0)
  addiu $t9, $t8, 1
  jal   getPlayerCount
   sw    $t9, 0x29f8($v0)
  slti  $at, $v0, 2
  bnezl $at, .L7F06A914
   lw    $ra, 0x1c($sp)
  jal   get_mission_timer
   nop   
  sw    $v0, 0x34($sp)
  jal   get_textptr_for_textID
   li    $a0, 39130
  lui   $t0, %hi(pPlayersPerm) 
  lw    $t0, %lo(pPlayersPerm)($t0)
  lui   $a1, %hi(aSD)
  addiu $a1, %lo(aSD) # addiu $a1, $a1, 0x3bf8
  addiu $a0, $sp, 0x40
  move  $a2, $v0
  jal   sprintf
   lw    $a3, 0x1c($t0)
  jal   display_string_in_lower_left_corner
   addiu $a0, $sp, 0x40
  lui   $v1, %hi(pPlayersPerm)
  lw    $v1, %lo(pPlayersPerm)($v1)
  lw    $t1, 0x1c($v1)
  slti  $at, $t1, 2
  bnezl $at, .L7F06A860
   lw    $v0, ($s0)
  lw    $t3, ($s0)
  lw    $t2, 0x34($sp)
  lw    $t5, 0x48($v1)
  lw    $t4, 0x29e4($t3)
  subu  $v0, $t2, $t4
  slt   $at, $t5, $v0
  beql  $at, $zero, .L7F06A84C
   lw    $t6, 0x44($v1)
  sw    $v0, 0x48($v1)
  lui   $v1, %hi(pPlayersPerm)
  lw    $v1, %lo(pPlayersPerm)($v1)
  lw    $t6, 0x44($v1)
.L7F06A84C:
  slt   $at, $v0, $t6
  beql  $at, $zero, .L7F06A860
   lw    $v0, ($s0)
  sw    $v0, 0x44($v1)
  lw    $v0, ($s0)
.L7F06A860:
  li    $a2, -1
  li    $a0, 1
  lw    $t7, 0x29ec($v0)
  sw    $t7, 0x29f0($v0)
  lw    $v0, ($s0)
  lw    $t8, 0x29e8($v0)
  sw    $t8, 0x29ec($v0)
  lw    $v0, ($s0)
  lw    $t9, 0x29e4($v0)
  sw    $t9, 0x29e8($v0)
  lw    $t1, ($s0)
  lw    $t0, 0x34($sp)
  sw    $t0, 0x29e4($t1)
  lw    $v0, ($s0)
  lw    $a1, 0x29e8($v0)
  beq   $a2, $a1, .L7F06A8F4
   nop   
  lw    $v1, 0x29e4($v0)
  subu  $t3, $v1, $a1
  slti  $at, $t3, 0x78
  beqz  $at, .L7F06A8F4
   nop   
  lw    $a1, 0x29ec($v0)
  li    $a0, 2
  beq   $a2, $a1, .L7F06A8F4
   subu  $t2, $v1, $a1
  slti  $at, $t2, 0x78
  beqz  $at, .L7F06A8F4
   nop   
  lw    $a1, 0x29f0($v0)
  addiu $a0, $a0, 1
  beq   $a2, $a1, .L7F06A8F4
   subu  $t4, $v1, $a1
  slti  $at, $t4, 0x78
  beqz  $at, .L7F06A8F4
   nop   
  addiu $a0, $a0, 1
.L7F06A8F4:
  lui   $v1, %hi(pPlayersPerm)
  lw    $v1, %lo(pPlayersPerm)($v1)
  lw    $t5, 0x58($v1)
  slt   $at, $t5, $a0
  beql  $at, $zero, .L7F06A914
   lw    $ra, 0x1c($sp)
  sw    $a0, 0x58($v1)
  lw    $ra, 0x1c($sp)
.L7F06A914:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x140
  jr    $ra
   nop   
");
#endif

#ifdef VERSION_JP
asm(R"
glabel increment_num_kills_display_text_in_MP
  lui   $v1, %hi(pPlayersPerm)
  lw    $v1, %lo(pPlayersPerm)($v1)
  addiu $sp, $sp, -0x140
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  lw    $t6, 0x1c($v1)
  lui   $s0, %hi(pPlayer)
  addiu $s0, %lo(pPlayer) # addiu $s0, $s0, -0x5f50
  addiu $t7, $t6, 1
  sw    $t7, 0x1c($v1)
  lw    $v0, ($s0)
  lw    $t8, 0x29f8($v0)
  addiu $t9, $t8, 1
  jal   getPlayerCount
   sw    $t9, 0x29f8($v0)
  slti  $at, $v0, 2
  bnezl $at, .L7F06A914
   lw    $ra, 0x1c($sp)
  jal   get_mission_timer
   nop   
  sw    $v0, 0x34($sp)
  jal   get_textptr_for_textID
   li    $a0, 39130
  lui   $t0, %hi(pPlayersPerm) 
  lw    $t0, %lo(pPlayersPerm)($t0)
  lui   $a1, %hi(aSD)
  addiu $a1, %lo(aSD) # addiu $a1, $a1, 0x3bf8
  addiu $a0, $sp, 0x40
  move  $a2, $v0
  jal   sprintf
   lw    $a3, 0x1c($t0)
  jal   jp_display_string_in_lower_left_corner
   addiu $a0, $sp, 0x40
  lui   $v1, %hi(pPlayersPerm)
  lw    $v1, %lo(pPlayersPerm)($v1)
  lw    $t1, 0x1c($v1)
  slti  $at, $t1, 2
  bnezl $at, .L7F06A860
   lw    $v0, ($s0)
  lw    $t3, ($s0)
  lw    $t2, 0x34($sp)
  lw    $t5, 0x48($v1)
  lw    $t4, 0x29e4($t3)
  subu  $v0, $t2, $t4
  slt   $at, $t5, $v0
  beql  $at, $zero, .L7F06A84C
   lw    $t6, 0x44($v1)
  sw    $v0, 0x48($v1)
  lui   $v1, %hi(pPlayersPerm)
  lw    $v1, %lo(pPlayersPerm)($v1)
  lw    $t6, 0x44($v1)
.L7F06A84C:
  slt   $at, $v0, $t6
  beql  $at, $zero, .L7F06A860
   lw    $v0, ($s0)
  sw    $v0, 0x44($v1)
  lw    $v0, ($s0)
.L7F06A860:
  li    $a2, -1
  li    $a0, 1
  lw    $t7, 0x29ec($v0)
  sw    $t7, 0x29f0($v0)
  lw    $v0, ($s0)
  lw    $t8, 0x29e8($v0)
  sw    $t8, 0x29ec($v0)
  lw    $v0, ($s0)
  lw    $t9, 0x29e4($v0)
  sw    $t9, 0x29e8($v0)
  lw    $t1, ($s0)
  lw    $t0, 0x34($sp)
  sw    $t0, 0x29e4($t1)
  lw    $v0, ($s0)
  lw    $a1, 0x29e8($v0)
  beq   $a2, $a1, .L7F06A8F4
   nop   
  lw    $v1, 0x29e4($v0)
  subu  $t3, $v1, $a1
  slti  $at, $t3, 0x78
  beqz  $at, .L7F06A8F4
   nop   
  lw    $a1, 0x29ec($v0)
  li    $a0, 2
  beq   $a2, $a1, .L7F06A8F4
   subu  $t2, $v1, $a1
  slti  $at, $t2, 0x78
  beqz  $at, .L7F06A8F4
   nop   
  lw    $a1, 0x29f0($v0)
  addiu $a0, $a0, 1
  beq   $a2, $a1, .L7F06A8F4
   subu  $t4, $v1, $a1
  slti  $at, $t4, 0x78
  beqz  $at, .L7F06A8F4
   nop   
  addiu $a0, $a0, 1
.L7F06A8F4:
  lui   $v1, %hi(pPlayersPerm)
  lw    $v1, %lo(pPlayersPerm)($v1)
  lw    $t5, 0x58($v1)
  slt   $at, $t5, $a0
  beql  $at, $zero, .L7F06A914
   lw    $ra, 0x1c($sp)
  sw    $a0, 0x58($v1)
  lw    $ra, 0x1c($sp)
.L7F06A914:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x140
  jr    $ra
   nop   
");
#endif

asm(R"
glabel get_curplay_killcount
  lui   $t6, %hi(pPlayersPerm) 
  lw    $t6, %lo(pPlayersPerm)($t6)
  jr    $ra
   lw    $v0, 0x1c($t6)
");

asm(R"
glabel increment_num_times_killed_MwtGC
  lui   $v0, %hi(pPlayersPerm)
  lw    $v0, %lo(pPlayersPerm)($v0)
  lw    $t6, 0x20($v0)
  addiu $t7, $t6, 1
  jr    $ra
   sw    $t7, 0x20($v0)
");

asm(R"
glabel get_times_killed_mwtgx
  lui   $t6, %hi(pPlayersPerm) 
  lw    $t6, %lo(pPlayersPerm)($t6)
  jr    $ra
   lw    $v0, 0x20($t6)
");

#ifdef VERSION_US
asm(R"
glabel increment_num_deaths
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  addiu $sp, $sp, -0x130
  sw    $ra, 0x1c($sp)
  lw    $t6, 0x29d8($v0)
  addiu $t7, $t6, 1
  jal   getPlayerCount
   sw    $t7, 0x29d8($v0)
  slti  $at, $v0, 2
  bnez  $at, .L7F06A9F8
   lui   $t8, %hi(pPlayer) 
  lw    $t8, %lo(pPlayer)($t8)
  li    $at, 1
  lw    $t9, 0x29d8($t8)
  bne   $t9, $at, .L7F06A9B8
   nop   
  jal   get_textptr_for_textID
   li    $a0, 39131
  addiu $a0, $sp, 0x30
  jal   sprintf
   move  $a1, $v0
  b     .L7F06A9F0
   nop   
.L7F06A9B8:
  jal   get_textptr_for_textID
   li    $a0, 39132
  sw    $v0, 0x28($sp)
  jal   get_textptr_for_textID
   li    $a0, 39133
  lui   $t0, %hi(pPlayer) 
  lw    $t0, %lo(pPlayer)($t0)
  lui   $a1, %hi(aSDS)
  addiu $a1, %lo(aSDS) # addiu $a1, $a1, 0x3c00
  lw    $a3, 0x29d8($t0)
  sw    $v0, 0x10($sp)
  addiu $a0, $sp, 0x30
  jal   sprintf
   lw    $a2, 0x28($sp)
.L7F06A9F0:
  jal   display_string_in_lower_left_corner
   addiu $a0, $sp, 0x30
.L7F06A9F8:
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x130
  jr    $ra
   nop   
");
#endif

#ifdef VERSION_JP
asm(R"
glabel increment_num_deaths
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  addiu $sp, $sp, -0x130
  sw    $ra, 0x1c($sp)
  lw    $t6, 0x29d8($v0)
  addiu $t7, $t6, 1
  jal   getPlayerCount
   sw    $t7, 0x29d8($v0)
  slti  $at, $v0, 2
  bnez  $at, .L7F06A9F8
   lui   $t8, %hi(pPlayer) 
  lw    $t8, %lo(pPlayer)($t8)
  li    $at, 1
  lw    $t9, 0x29d8($t8)
  bne   $t9, $at, .L7F06A9B8
   nop   
  jal   get_textptr_for_textID
   li    $a0, 39131
  addiu $a0, $sp, 0x30
  jal   sprintf
   move  $a1, $v0
  b     .L7F06A9F0
   nop   
.L7F06A9B8:
  jal   get_textptr_for_textID
   li    $a0, 39132
  sw    $v0, 0x28($sp)
  jal   get_textptr_for_textID
   li    $a0, 39133
  lui   $t0, %hi(pPlayer) 
  lw    $t0, %lo(pPlayer)($t0)
  lui   $a1, %hi(aSDS)
  addiu $a1, %lo(aSDS) # addiu $a1, $a1, 0x3c00
  lw    $a3, 0x29d8($t0)
  sw    $v0, 0x10($sp)
  addiu $a0, $sp, 0x30
  jal   sprintf
   lw    $a2, 0x28($sp)
.L7F06A9F0:
  jal   jp_display_string_in_lower_left_corner
   addiu $a0, $sp, 0x30
.L7F06A9F8:
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x130
  jr    $ra
   nop   
");
#endif

int get_curplayer_numdeaths(void) {
  return *((int *)((char *)pPlayer + 0x29D8));
}

#ifdef VERSION_US
asm(R"
glabel increment_num_suicides_display_MP
  addiu $sp, $sp, -0x140
  sw    $s0, 0x18($sp)
  lui   $s0, %hi(pPlayer)
  addiu $s0, %lo(pPlayer) # addiu $s0, $s0, -0x5f50
  lw    $v0, ($s0)
  sw    $ra, 0x1c($sp)
  lw    $t6, 0x29dc($v0)
  addiu $t7, $t6, 1
  jal   getPlayerCount
   sw    $t7, 0x29dc($v0)
  slti  $at, $v0, 2
  bnezl $at, .L7F06AB90
   lw    $ra, 0x1c($sp)
  jal   get_mission_timer
   nop   
  sw    $v0, 0x34($sp)
  jal   get_textptr_for_textID
   li    $a0, 39134
  lw    $t8, ($s0)
  lui   $a1, %hi(aSD_0)
  addiu $a1, %lo(aSD_0) # addiu $a1, $a1, 0x3c0c
  addiu $a0, $sp, 0x40
  move  $a2, $v0
  jal   sprintf
   lw    $a3, 0x29dc($t8)
  jal   display_string_in_lower_left_corner
   addiu $a0, $sp, 0x40
  lui   $a3, %hi(pPlayersPerm)
  addiu $a3, %lo(pPlayersPerm) # addiu $a3, $a3, -0x5f4c
  lw    $v0, ($a3)
  lw    $t9, 0x1c($v0)
  slti  $at, $t9, 2
  bnezl $at, .L7F06AAE0
   lw    $v0, ($s0)
  lw    $t1, ($s0)
  lw    $t0, 0x34($sp)
  lw    $t3, 0x48($v0)
  lw    $t2, 0x29e4($t1)
  subu  $v1, $t0, $t2
  slt   $at, $t3, $v1
  beql  $at, $zero, .L7F06AACC
   lw    $t4, 0x44($v0)
  sw    $v1, 0x48($v0)
  lw    $v0, ($a3)
  lw    $t4, 0x44($v0)
.L7F06AACC:
  slt   $at, $v1, $t4
  beql  $at, $zero, .L7F06AAE0
   lw    $v0, ($s0)
  sw    $v1, 0x44($v0)
  lw    $v0, ($s0)
.L7F06AAE0:
  li    $a2, -1
  li    $v1, 1
  lw    $t5, 0x29ec($v0)
  sw    $t5, 0x29f0($v0)
  lw    $v0, ($s0)
  lw    $t6, 0x29e8($v0)
  sw    $t6, 0x29ec($v0)
  lw    $v0, ($s0)
  lw    $t7, 0x29e4($v0)
  sw    $t7, 0x29e8($v0)
  lw    $t9, ($s0)
  lw    $t8, 0x34($sp)
  sw    $t8, 0x29e4($t9)
  lw    $v0, ($s0)
  lw    $a1, 0x29e8($v0)
  beql  $a2, $a1, .L7F06AB78
   lw    $v0, ($a3)
  lw    $a0, 0x29e4($v0)
  subu  $t1, $a0, $a1
  slti  $at, $t1, 0x78
  beql  $at, $zero, .L7F06AB78
   lw    $v0, ($a3)
  lw    $a1, 0x29ec($v0)
  li    $v1, 2
  beq   $a2, $a1, .L7F06AB74
   subu  $t0, $a0, $a1
  slti  $at, $t0, 0x78
  beql  $at, $zero, .L7F06AB78
   lw    $v0, ($a3)
  lw    $a1, 0x29f0($v0)
  addiu $v1, $v1, 1
  beq   $a2, $a1, .L7F06AB74
   subu  $t2, $a0, $a1
  slti  $at, $t2, 0x78
  beql  $at, $zero, .L7F06AB78
   lw    $v0, ($a3)
  addiu $v1, $v1, 1
.L7F06AB74:
  lw    $v0, ($a3)
.L7F06AB78:
  lw    $t3, 0x58($v0)
  slt   $at, $t3, $v1
  beql  $at, $zero, .L7F06AB90
   lw    $ra, 0x1c($sp)
  sw    $v1, 0x58($v0)
  lw    $ra, 0x1c($sp)
.L7F06AB90:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x140
  jr    $ra
   nop   
");
#endif

#ifdef VERSION_JP
asm(R"
glabel increment_num_suicides_display_MP
  addiu $sp, $sp, -0x140
  sw    $s0, 0x18($sp)
  lui   $s0, %hi(pPlayer)
  addiu $s0, %lo(pPlayer) # addiu $s0, $s0, -0x5f50
  lw    $v0, ($s0)
  sw    $ra, 0x1c($sp)
  lw    $t6, 0x29dc($v0)
  addiu $t7, $t6, 1
  jal   getPlayerCount
   sw    $t7, 0x29dc($v0)
  slti  $at, $v0, 2
  bnezl $at, .L7F06AB90
   lw    $ra, 0x1c($sp)
  jal   get_mission_timer
   nop   
  sw    $v0, 0x34($sp)
  jal   get_textptr_for_textID
   li    $a0, 39134
  lw    $t8, ($s0)
  lui   $a1, %hi(aSD_0)
  addiu $a1, %lo(aSD_0) # addiu $a1, $a1, 0x3c0c
  addiu $a0, $sp, 0x40
  move  $a2, $v0
  jal   sprintf
   lw    $a3, 0x29dc($t8)
  jal   jp_display_string_in_lower_left_corner
   addiu $a0, $sp, 0x40
  lui   $a3, %hi(pPlayersPerm)
  addiu $a3, %lo(pPlayersPerm) # addiu $a3, $a3, -0x5f4c
  lw    $v0, ($a3)
  lw    $t9, 0x1c($v0)
  slti  $at, $t9, 2
  bnezl $at, .L7F06AAE0
   lw    $v0, ($s0)
  lw    $t1, ($s0)
  lw    $t0, 0x34($sp)
  lw    $t3, 0x48($v0)
  lw    $t2, 0x29e4($t1)
  subu  $v1, $t0, $t2
  slt   $at, $t3, $v1
  beql  $at, $zero, .L7F06AACC
   lw    $t4, 0x44($v0)
  sw    $v1, 0x48($v0)
  lw    $v0, ($a3)
  lw    $t4, 0x44($v0)
.L7F06AACC:
  slt   $at, $v1, $t4
  beql  $at, $zero, .L7F06AAE0
   lw    $v0, ($s0)
  sw    $v1, 0x44($v0)
  lw    $v0, ($s0)
.L7F06AAE0:
  li    $a2, -1
  li    $v1, 1
  lw    $t5, 0x29ec($v0)
  sw    $t5, 0x29f0($v0)
  lw    $v0, ($s0)
  lw    $t6, 0x29e8($v0)
  sw    $t6, 0x29ec($v0)
  lw    $v0, ($s0)
  lw    $t7, 0x29e4($v0)
  sw    $t7, 0x29e8($v0)
  lw    $t9, ($s0)
  lw    $t8, 0x34($sp)
  sw    $t8, 0x29e4($t9)
  lw    $v0, ($s0)
  lw    $a1, 0x29e8($v0)
  beql  $a2, $a1, .L7F06AB78
   lw    $v0, ($a3)
  lw    $a0, 0x29e4($v0)
  subu  $t1, $a0, $a1
  slti  $at, $t1, 0x78
  beql  $at, $zero, .L7F06AB78
   lw    $v0, ($a3)
  lw    $a1, 0x29ec($v0)
  li    $v1, 2
  beq   $a2, $a1, .L7F06AB74
   subu  $t0, $a0, $a1
  slti  $at, $t0, 0x78
  beql  $at, $zero, .L7F06AB78
   lw    $v0, ($a3)
  lw    $a1, 0x29f0($v0)
  addiu $v1, $v1, 1
  beq   $a2, $a1, .L7F06AB74
   subu  $t2, $a0, $a1
  slti  $at, $t2, 0x78
  beql  $at, $zero, .L7F06AB78
   lw    $v0, ($a3)
  addiu $v1, $v1, 1
.L7F06AB74:
  lw    $v0, ($a3)
.L7F06AB78:
  lw    $t3, 0x58($v0)
  slt   $at, $t3, $v1
  beql  $at, $zero, .L7F06AB90
   lw    $ra, 0x1c($sp)
  sw    $v1, 0x58($v0)
  lw    $ra, 0x1c($sp)
.L7F06AB90:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x140
  jr    $ra
   nop   
");
#endif

asm(R"
glabel get_curplayer_numsuicides
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  jr    $ra
   lw    $v0, 0x29dc($t6)
");
