#include "bondtypes.h"
#include "chrai.h"
#include "lvl.h"
#include "music.h"
#include <types.h>

int alarm_timer = 0;
int *ptr_alarm_sfx = 0;
float toxic_gas_sound_timer = 0.0;
int activate_gas_sound_timer = false;
float D_80030AD0 = 0.0;
float D_80030AD4 = 0.0;
float D_80030AD8 = 0.0;
int D_80030ADC = 0;
unsigned int D_80030AE0 = 0;
int ptr_gas_sound = 0;
int clock_drawn_flag = 1;
int clock_enable = 0;
float clock_time = 0;
int D_80030AF4 = 0;
int D_80030AF8 = 0;
int D_80030AFC = 0;
int D_80030B00 = 0;
int D_80030B04 = 0;
int D_80030B08 = 0;
int D_80030B0C = 0;
int bodypartshot = 0xFFFFFFFF;
float D_80030B14 = 1.0;
float D_80030B18 = 1.0;
float D_80030B1C = 1.0;
float D_80030B20 = 1.0;
float D_80030B24 = 1.0;
float solo_ammo_multiplier = 1.0;
short Throwing_knife_SFX[] = {0x5F, 0x60, 0x61};

unsigned int D_80030B34[] = {0, 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

unsigned int monitor_animation_microcode[] = {
    7,     0,     1,    0x400, 0x14,       8,    0x14, 2,     0x400,
    0x14,  0xD,   0xFF, 0x14,  8,          0x14, 5,    0x200, 0x14,
    6,     0x200, 0x14, 0xD,   0xFFFFFFFF, 0x14, 8,    0x14,  5,
    0x400, 0x14,  6,    0x400, 0x14,       8,    0x14, 0xB};

unsigned int D_80030C00[] = {
    7,          0xC,   1,          0x400, 0x14,       8,     0x14,       2,
    0x400,      0x14,  0xD,        0xFF,  0x14,       8,     0x14,       5,
    0x200,      0x14,  6,          0x200, 0x14,       0xD,   0xFFFFFFFF, 0x14,
    8,          0x14,  5,          0x400, 0x14,       6,     0x400,      0x14,
    8,          0x14,  7,          0xD,   1,          0x400, 0x14,       8,
    0x14,       2,     0x400,      0x14,  0xD,        0xFF,  0x14,       8,
    0x14,       5,     0x200,      0x14,  6,          0x200, 0x14,       0xD,
    0xFFFFFFFF, 0x14,  8,          0x14,  5,          0x400, 0x14,       6,
    0x400,      0x14,  8,          0x14,  7,          0xE,   1,          0x400,
    0x14,       8,     0x14,       2,     0x400,      0x14,  0xD,        0xFF,
    0x14,       8,     0x14,       5,     0x200,      0x14,  6,          0x200,
    0x14,       0xD,   0xFFFFFFFF, 0x14,  8,          0x14,  5,          0x400,
    0x14,       6,     0x400,      0x14,  8,          0x14,  7,          0xF,
    1,          0x400, 0x14,       8,     0x14,       2,     0x400,      0x14,
    0xD,        0xFF,  0x14,       8,     0x14,       5,     0x200,      0x14,
    6,          0x200, 0x14,       0xD,   0xFFFFFFFF, 0x14,  8,          0x14,
    5,          0x400, 0x14,       6,     0x400,      0x14,  8,          0x14,
    0xB,
};

unsigned int D_80030E24[] = {
    7, 0x11, 8, 0x50, 7, 0x12, 8, 0x50, 7, 0x13, 8, 0x50, 7,   0x14,
    8, 0x50, 7, 0x15, 8, 0x50, 7, 0x16, 8, 0x50, 7, 0x17, 8,   0x50,
    7, 0x18, 8, 0x50, 7, 0x19, 8, 0x50, 7, 0x1A, 8, 0x50, 0xB,
};

unsigned int D_80030EC8[] = {
    7, 7,   8, 0x50, 7, 8,    8, 0x50, 7, 9,    8, 0x50, 7, 0xC,  8,  0x50,
    7, 0xD, 8, 0x50, 8, 0x50, 7, 0x19, 8, 0x50, 7, 0x14, 8, 0x50, 0xB};

unsigned int D_80030F44[] = {
    0xD,   0x202020FF, 1,     7,     0x1C,  1,     0x800, 0x78,  8,
    0x78,  5,          0x100, 1,     6,     0x200, 0x3C,  1,     0xFFFFE000,
    0x78,  8,          0x78,  5,     0x400, 1,     6,     0x400, 0x3C,
    6,     0x400,      0x3C,  1,     0x800, 0x78,  8,     0x78,  5,
    0x80,  1,          6,     0x800, 0x3C,  6,     0x400, 0x78,  2,
    0x400, 0x3C,       1,     0x200, 0x78,  8,     0x78,  0xB};

unsigned int D_80031018[] = {
    0xD,   0x202020FF, 1, 7,     0x1C, 5, 0x80,  1,    6, 0x800, 0x3C, 6,
    0x400, 0x78,       2, 0x400, 0xA,  1, 0x200, 0x28, 8, 0x78,  0xB};

unsigned int D_80031074[] = {
    7,  0x1D,       0xD,  0x8000FF, 1,    2, 0xFFFFFE00, 0x50, 8, 0x78,
    2,  0xFFFFFF00, 0x14, 8,        0x78, 2, 0xFFFFFF80, 0xA,  8, 0x28,
    2,  0xFFFFFE00, 0x28, 8,        0x3C, 2, 0xFFFFFFC0, 0x1E, 8, 0x78,
    0xB};

unsigned int D_800310F0[] = {
    7, 0x1D,  0xD,  0x280000FF, 1,    2, 0x200, 0x50, 8,  0x78,
    2, 0x100, 0x14, 8,          0x78, 2, 0x80,  0xA,  8,  0x28,
    2, 0x200, 0x28, 8,          0x3C, 2, 0x40,  0x1E, 8,  0x78,
    2, 0x100, 0x14, 8,          0x78, 2, 0x80,  0xA,  0xB};

unsigned int D_8003118C[] = {
    7,    0x1D, 0xD,  0x3C00FF, 1,    2,    0x200, 0x50,  8,
    0x78, 2,    0x80, 0xA,      8,    0x28, 2,     0x100, 0x14,
    8,    0x78, 2,    0x80,     0xA,  8,    0x28,  2,     0x200,
    0x28, 8,    0x3C, 2,        0x40, 0x1E, 8,     0x78,  0xB};

unsigned int D_8003121C[] = {7,     0x1E, 0xD, 0x404000FF, 1,  1,
                             0x280, 1,    8,   0xA,        0xB};

unsigned int D_80031248[] = {7,     0x1E, 0xD, 0x4040FF, 1,  1,
                             0x280, 1,    8,   0xA,      0xB};

unsigned int D_80031274[] = {7,          0x1E, 0xD, 0x406440FF, 1,  1,
                             0xFFFFFD80, 1,    8,   0xA,        0xB};

unsigned int D_800312A0[] = {0xD, 0xAFF0AFE, 0x14, 9, &D_800312C8};

unsigned int D_800312B4[] = {0xD, 0xA640AFE, 0x14, 9,
                             (unsigned int)&D_800312C8};

unsigned int D_800312C8[] = {0xF,   0xB6, 8,           1,      0xA, &D_800312A0,
                             0x51E, 0xA,  &D_800312B4, 0x147A, 0xB};

unsigned int D_800312F4[] = {7, 0x30, 0xD, 0xA960AFE, 1, 9, &D_800312B4};

unsigned int D_80031310[] = {7, 0x10, 0xD,  0x303080FF, 0x1E, 8,    5,
                             7, 0x2D, 8,    5,          7,    0x2E, 8,
                             5, 7,    0x2F, 8,          5,    0xB};

unsigned int D_80031360[] = {
    7,          0x2C,       0xD,   0x308030FF, 0x1E,  1,          0xFFFFFC00,
    0x400,      8,          0x5A0, 3,          0x288, 0x168,      4,
    0x3AA,      0x168,      5,     0x80,       0x12C, 6,          0x80,
    0x12C,      0xD,        0xFF,  0x3C,       8,     0x3C,       0xD,
    0x808080FF, 0xA,        8,     0x5A,       0xD,   0x38C838FF, 0x1E,
    8,          0x1E,       0xD,   0x803838FF, 0x3C,  8,          0x3C,
    0xD,        0x808080FF, 0x3C,  8,          0x3C,  3,          0x200,
    0x168,      4,          0x200, 0x168,      5,     0x400,      0x2D0,
    6,          0x400,      0x2D0, 8,          0x12C, 7,          0x2C,
    8,          0x1A4,      0xD,   0xC800FF,   0x1E,  8,          0x1E,
    0xD,        0x1E381EFF, 0x3C,  8,          0x3C,  0xB};

unsigned int D_80031490[] = {
    0xD, 0xFF, 1,    0xD, 0xC8C8C8FF, 0x190, 7, 1, 8, 0x2A8, 7,  2, 8, 0x2A8, 7,
    4,   8,    0xB4, 0xD, 0x808032FF, 1,     7, 4, 8, 0xC8,  0xB};

unsigned int D_800314F8[] = {
    5,    0x400, 1,     6,   0x400,      1,    0xD, 0xC81414FF, 1,   7,
    6,    8,     0x258, 0xD, 0xC8C8C8FF, 5,    8,   5,          0xD, 0x383838FF,
    0x3C, 7,     0x1B,  0xD, 0xA0A0AFF,  0x64, 8,   0x190,      0xB};

unsigned int D_8003156C[] = {0xD,  0xA960AFF, 0,   7, 0x28, 8, 5, 7,
                             0x29, 8,         5,   7, 0x2A, 8, 5, 7,
                             0x2B, 8,         0xA, 7, 0x29, 8, 5, 0xB};

unsigned int D_800315CC[] = {
    7,         0x24,      0xD,       0xA960AFF, 0,         8,         3,
    0xD,       0x87808FF, 0,         8,         2,         0xD,       0xA960AFF,
    0,         8,         3,         0xD,       0x87808FF, 0,         8,
    2,         1,         0x264,     0x1E,      7,         0x25,      0xD,
    0xA960AFF, 0,         8,         3,         0xD,       0x87808FF, 0,
    8,         2,         7,         0x26,      0xD,       0xA960AFF, 0,
    8,         3,         0xD,       0x87808FF, 0,         8,         2,
    7,         0x27,      0xD,       0xA960AFF, 0,         8,         3,
    0xD,       0x87808FF, 0,         8,         2,         0xD,       0xA960AFF,
    0,         8,         3,         0xD,       0x87808FF, 0,         8,
    2,         0xD,       0xA960AFF, 0,         8,         3,         0xD,
    0x87808FF, 0,         8,         2,         0xD,       0xA960AFF, 0,
    8,         3,         0xD,       0x87808FF, 0,         8,         2,
    1,         0x19C,     0x28,      7,         0x26,      0xD,       0xA960AFF,
    0,         8,         3,         0xD,       0x87808FF, 0,         8,
    2,         0xD,       0xA960AFF, 0,         8,         3,         0xD,
    0x87808FF, 0,         8,         2,         7,         0x25,      0xD,
    0xA960AFF, 0,         8,         3,         0xD,       0x87808FF, 0,
    8,         2,         0xD,       0xA960AFF, 0,         8,         3,
    0xD,       0x87808FF, 0,         8,         2,         0xD,       0xA960AFF,
    0,         8,         3,         0xD,       0x87808FF, 0,         8,
    2,         0xD,       0xA960AFF, 0,         8,         3,         0xD,
    0x87808FF, 0,         8,         2,         0xB};

unsigned int D_80031848[] = {0x0000000D, 0x0A780AFF, 0x00000000, 0x00000007,
                             0x00000020, 0x00000008, 0x00000005, 0x00000007,
                             0x00000021, 0x00000008, 0x00000005, 0x00000007,
                             0x00000022, 0x00000008, 0x00000005, 0x00000007,
                             0x00000023, 0x00000008, 0x00000005, 0x0000000B};

unsigned int D_80031898[] = {7, 0x1C, 0xD, 0x800000, 1, 8, 5, 0xB};

struct struct_5 D_800318B8[] = {
    {0xA, D_80031018, 0x1999}, {0xA, D_8003156C, 0x1999},
    {0xA, D_8003121C, 0x1999}, {0xA, D_80031248, 0x1999},
    {0xA, D_80031274, 0x1999}, {0xA, D_800310F0, 0x3333},
    {0xA, D_8003118C, 0x6666}, {0xA, D_80031074, 0xFFFF}};

unsigned int D_80031918 = 0xB;

struct struct_5 D_8003191C[] = {{0xA, D_80030F44, 0x51E},
                                {0xA, D_8003121C, 0x51E},
                                {0xA, D_80031074, 0x51E},
                                {0xA, &D_80031950, 0x9999}};

unsigned int D_8003194C = 0xB;

struct struct_5 D_80031950[] = {
    {0xA, &D_800319D4, 0x1999}, {0xA, &D_800319F0, 0x1999},
    {0xA, &D_80031A0C, 0x1999}, {0xA, &D_80031A28, 0x1999},
    {0xA, &D_80031A44, 0x1999}, {0xA, &D_80031A60, 0x1999},
    {0xA, &D_80031A7C, 0x1999}, {0xA, &D_80031A98, 0x1999},
    {0xA, &D_80031AB4, 0x1999}, {0xA, &D_80031AD0, 0x1999}};
unsigned int D_800319C8[] = {8, 0x64, 0xB};

struct struct_0 D_800319D4 = {7, 0x11, 8, 0x14, 0xA, &D_80031AEC, 0xFFFF};
struct struct_0 D_800319F0 = {7, 0x12, 8, 0x14, 0xA, &D_80031AEC, 0xFFFF};
struct struct_0 D_80031A0C = {7, 0x13, 8, 0x14, 0xA, &D_80031AEC, 0xFFFF};
struct struct_0 D_80031A28 = {7, 0x14, 8, 0x14, 0xA, &D_80031AEC, 0xFFFF};
struct struct_0 D_80031A44 = {7, 0x15, 8, 0x14, 0xA, &D_80031AEC, 0xFFFF};
struct struct_0 D_80031A60 = {7, 0x16, 8, 0x14, 0xA, &D_80031AEC, 0xFFFF};
struct struct_0 D_80031A7C = {7, 0x17, 8, 0x14, 0xA, &D_80031AEC, 0xFFFF};
struct struct_0 D_80031A98 = {7, 0x18, 8, 0x14, 0xA, &D_80031AEC, 0xFFFF};
struct struct_0 D_80031AB4 = {7, 0x19, 8, 0x14, 0xA, &D_80031AEC, 0xFFFF};
struct struct_0 D_80031AD0 = {7, 0x1A, 8, 0x14, 0xA, &D_80031AEC, 0xFFFF};

struct struct_5 D_80031AEC[] = {{0xA, &D_80031B24, 0x1999},
                                {0xA, &D_80031B38, 0x1999},
                                {0xA, &D_80031B4C, 0x1999}};

struct struct_12 D_80031B10[] = {0xD,  0xC8, 0xC8, 0xC8,
                                 0xFF, 0x3C, 9,    D_80031B60};
struct struct_12 D_80031B24[] = {0xD,  0xC8, 0x32, 0x32,
                                 0xFF, 0x3C, 9,    D_80031B60};
struct struct_12 D_80031B38[] = {0xD,  0x32, 0xC8, 0x32,
                                 0xFF, 0x3C, 9,    D_80031B60};
struct struct_12 D_80031B4C[] = {0xD,  0x32, 0x32, 0xC8,
                                 0xFF, 0x3C, 9,    D_80031B60};
unsigned int D_80031B60[] = {8, 0x32};

struct struct_5 D_80031B68 = {0xA, &D_80031BB4, 0x1999};
struct struct_5 D_80031B74 = {0xA, &D_80031BD0, 0x1999};
struct struct_5 D_80031B80 = {0xA, &D_80031BEC, 0x1999};
struct struct_5 D_80031B8C = {0xA, &D_80031C08, 0x1999};
struct struct_5 D_80031B98 = {0xA, &D_80031C80, 0x1999};
unsigned int D_80031BA4[] = {8, 0x12C, 9, &D_80031D30};

struct struct_16 D_80031BB4 = {1, 0x800, 0x78, 8, 0x78, 9, D_80031D30};
struct struct_16 D_80031BD0 = {2, 0x2000, 0x32, 8, 0xC8, 9, D_80031D30};
struct struct_16 D_80031BEC = {2, 0x2000, 0xC8, 8, 0xC8, 9, D_80031D30};

unsigned int D_80031C08[] = {
    3,    0x288, 0x12C, 4,     0x3AA, 0x12C, 5,    0x80,  0xC8,  6,
    0x80, 0xC8,  8,     0x12C, 3,     0x200, 0x32, 4,     0x200, 0xC8,
    5,    0x400, 0x2D0, 6,     0x400, 0x2D0, 8,    0x258, 9,     D_80031D30};

unsigned int D_80031C80[] = {
    3,     0x320, 0x190, 4,     0x190, 0x190, 5,     0x80,      0xC8,
    6,     0x80,  0xC8,  8,     0x12C, 3,     0xC8,  0xC8,      4,
    0x190, 0x320, 5,     0x200, 0x2D0, 6,     0x200, 0x2D0,     8,
    0x320, 5,     0x400, 0x2D0, 6,     0x400, 0x2D0, 3,         0x200,
    0x64,  4,     0x200, 0x3C,  8,     0x1F4, 9,     D_80031D30};

unsigned int D_80031D30[] = {8,           0x32,   0xA, &D_80031AEC, 0x1999, 0xA,
                             &D_80031D58, 0x3333, 9,   &D_80031950};

struct struct_20 D_80031D58 = {
    8,   0x32, 0xD,  0xFFFFFFFF, 0xA,  0xD,  0xFF, 5,     0xD, 0xFFFFFFFF,
    0xA, 8,    0x19, 0xD,        0xFF, 0xC8, 8,    0x1F4, 9,   D_80031950};

unsigned int D_80031DA8[] = {
    7,    0x31, 5,    0x200, 0,          6,   0x200, 0,   0xD, 0xDC2828FF,
    0x3C, 8,    0x3C, 0xD,   0x323232FF, 0xA, 8,     0xA, 0xB};

unsigned int D_80031DF4[] = {
    7,    0x31, 5,    0x200, 0,          6,   0x200, 0,   0xD, 0x32C832FF,
    0x3C, 8,    0x3C, 0xD,   0x323232FF, 0xA, 8,     0xA, 0xB};

unsigned int D_80031E40[] = {7, 0x31, 5,          0x200, 0, 6,   0x200,
                             0, 0xD,  0x323232FF, 0xA,   8, 0xA, 0xB};

unsigned int D_80031E78[] = {7, 0x31, 5,          0x200, 0, 6,   0x200,
                             0, 0xD,  0xDC2828FF, 0xA,   8, 0xA, 0xB};

unsigned int D_80031EB0[] = {7, 0x31, 5,          0x200, 0, 6,   0x200,
                             0, 0xD,  0x32C832FF, 0xA,   8, 0xA, 0xB};

unsigned int D_80031EE8[] = {7, 0, 0xD, 0xFF, 0, 0xC};

unsigned int dword_D_80031F00[] = {5,      0x400, 0, 6,      0x400, 0,
                                   8,      1,     5, 0x1000, 0x14,  6,
                                   0x1000, 0x14,  8, 0x14,   0xB};

unsigned int dword_D_80031F44[] = {
    7,     0,     1,    0x400, 0x14,       8,    0x14, 2,     0x400,
    0x14,  0xD,   0xFF, 0x14,  8,          0x14, 5,    0x200, 0x14,
    6,     0x200, 0x14, 0xD,   0xFFFFFFFF, 0x14, 8,    0x14,  5,
    0x400, 0x14,  6,    0x400, 0x14,       8,    0x14, 0xB};

unsigned int D_80031FD0[] = {0, 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

unsigned int D_80032010 = 0;
unsigned int D_80032014 = 0;
unsigned int D_80032018 = 0;
unsigned int D_8003201C = 0;
unsigned int D_80032020 = 0;
unsigned int D_80032024 = 0;
unsigned int D_80032028 = 0;
unsigned int D_8003202C = 0;
unsigned int D_80032030 = 0;
unsigned int D_80032034 = 0;
unsigned int D_80032038 = 0;
unsigned int D_8003203C = 0;
unsigned int D_80032040 = 0;
unsigned int D_80032044 = 0;
unsigned int D_80032048 = 0;

unsigned int D_8003204C = 0x7FFF;
unsigned int D_80032050 = 0x7FFF;
unsigned int D_80032054 = 0x7FFF;
unsigned int D_80032058 = 0xFFFF8000;
unsigned int D_8003205C = 0xFFFF8000;
unsigned int D_80032060 = 0xFFFF8000;
unsigned int D_80032064 = 0;
unsigned int D_80032068 = 0;
unsigned int D_8003206C = 0;
unsigned int D_80032070 = 0x7FFF;
unsigned int D_80032074 = 0x7FFF;
unsigned int D_80032078 = 0x7FFF;
unsigned int D_8003207C = 0xFFFF8000;
unsigned int D_80032080 = 0xFFFF8000;
unsigned int D_80032084 = 0xFFFF8000;
unsigned int D_80032088 = 0;
unsigned int D_8003208C = 0;
unsigned int D_80032090 = 0;

unsigned int blank_07_object[] = {
    0x1000007, 0xFFFF,     1, 0, 0, 0, 0x3F800000, 0, 0, 0,
    0,         0x3F800000, 0, 0, 0, 0, 0x3F800000, 0, 0, 0,
    0,         0x3F800000, 0, 0, 0, 0, 0,          0, 0, 0x447A0000};

unsigned int D_8003210C[] = {0xFFFFFF00, 0xFFFFFF00};

unsigned int blank_11_object[] = {
    0x1000011, 0,          0x4000, 0, 0, 0, 0x3F800000, 0, 0, 0,
    0,         0x3F800000, 0,      0, 0, 0, 0x3F800000, 0, 0, 0,
    0,         0x3F800000, 0,      0, 0, 0, 0,          0, 0, 0x447A0000};

unsigned int D_8003218C[] = {0xFFFFFF00, 0xFFFFFF00};

unsigned int blank_08_object_preset_1[] = {
    0x1000008,  1,          0,       0, 0, 0, 0x3F800000, 0, 0, 0,
    0,          0x3F800000, 0,       0, 0, 0, 0x3F800000, 0, 0, 0,
    0,          0x3F800000, 0,       0, 0, 0, 0,          0, 0, 0x447A0000,
    0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF};

unsigned int D_80032218 = 0;

unsigned int blank_08_object_preset_4001[] = {
    0x1000008,  0x4001,     0,       0, 0, 0, 0x3F800000, 0, 0, 0,
    0,          0x3F800000, 0,       0, 0, 0, 0x3F800000, 0, 0, 0,
    0,          0x3F800000, 0,       0, 0, 0, 0,          0, 0, 0x447A0000,
    0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF};

unsigned int D_800322A0 = 0;
unsigned int D_800322A4 = 0;

unsigned int D_800322A8[] = {1, 3};
unsigned int D_800322B0[4] = {0};
unsigned int D_800322C0[12] = {0};

asm(R"
glabel sub_GAME_7F03FB70
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  lw    $t6, ($a0)
  move  $s0, $a0
  andi  $t7, $t6, 0x80
  beql  $t7, $zero, .L7F03FBDC
   lw    $t8, ($s0)
  lw    $a0, 0x98($a0)
  beql  $a0, $zero, .L7F03FBB8
   lw    $a0, 0x9c($s0)
  jal   sfxGetArg0Unk3F
   nop   
  beql  $v0, $zero, .L7F03FBB8
   lw    $a0, 0x9c($s0)
  jal   sfxDeactivate
   lw    $a0, 0x98($s0)
  lw    $a0, 0x9c($s0)
.L7F03FBB8:
  beql  $a0, $zero, .L7F03FBDC
   lw    $t8, ($s0)
  jal   sfxGetArg0Unk3F
   nop   
  beql  $v0, $zero, .L7F03FBDC
   lw    $t8, ($s0)
  jal   sfxDeactivate
   lw    $a0, 0x9c($s0)
  lw    $t8, ($s0)
.L7F03FBDC:
  lui   $at, 0x8000
  or    $t9, $t8, $at
  sw    $t9, ($s0)
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F03FBFC
  mtc1  $zero, $f0
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f2
  sw    $zero, ($a0)
  sw    $zero, 0x88($a0)
  lui   $at, %hi(D_80052A48)
  swc1  $f0, 4($a0)
  swc1  $f0, 8($a0)
  swc1  $f0, 0xc($a0)
  swc1  $f0, 0x10($a0)
  swc1  $f0, 0x14($a0)
  swc1  $f0, 0x18($a0)
  swc1  $f0, 0x1c($a0)
  swc1  $f2, 0x60($a0)
  lwc1  $f4, %lo(D_80052A48)($at)
  li    $v0, -1
  li    $t6, 1
  sw    $zero, 0x90($a0)
  sw    $v0, 0xa0($a0)
  sw    $zero, 0xa4($a0)
  sw    $zero, 0xa8($a0)
  sw    $v0, 0xac($a0)
  sw    $t6, 0xb8($a0)
  sw    $zero, 0xbc($a0)
  sw    $zero, 0xe0($a0)
  sw    $zero, 0xe4($a0)
  sw    $zero, 0xe8($a0)
  swc1  $f0, 0x94($a0)
  swc1  $f2, 0xc0($a0)
  swc1  $f2, 0xc4($a0)
  swc1  $f2, 0xc8($a0)
  jr    $ra
   swc1  $f4, 0x8c($a0)
");

asm(R"
glabel sub_GAME_7F03FC80
  addiu $sp, $sp, -0x30
  lui   $v0, %hi(dword_CODE_bss_80073DC0)
  lui   $a0, %hi(dword_CODE_bss_80075030)
  sw    $ra, 0x14($sp)
  li    $a2, -1
  addiu $a0, %lo(dword_CODE_bss_80075030) # addiu $a0, $a0, 0x5030
  addiu $v0, %lo(dword_CODE_bss_80073DC0) # addiu $v0, $v0, 0x3dc0
  move  $a1, $zero
  lui   $v1, 0x8000
.L7F03FCA4:
  lw    $t6, ($v0)
  addiu $v0, $v0, 0xec
  sltu  $at, $v0, $a0
  and   $t7, $t6, $v1
  beqz  $t7, .L7F03FCD4
   lui   $a3, %hi(dword_CODE_bss_80073DC0)
  addiu $a3, %lo(dword_CODE_bss_80073DC0) # addiu $a3, $a3, 0x3dc0
  addu  $a0, $a3, $a1
  jal   sub_GAME_7F03FBFC
   sw    $a0, 0x20($sp)
  b     .L7F03FD98
   lw    $v0, 0x20($sp)
.L7F03FCD4:
  bnez  $at, .L7F03FCA4
   addiu $a1, $a1, 0xec
  lui   $v0, %hi(dword_CODE_bss_80073DC0)
  lui   $a3, %hi(dword_CODE_bss_80073DC0)
  addiu $a3, %lo(dword_CODE_bss_80073DC0) # addiu $a3, $a3, 0x3dc0
  addiu $v0, %lo(dword_CODE_bss_80073DC0) # addiu $v0, $v0, 0x3dc0
  move  $v1, $zero
  li    $a1, 236
  li    $a0, 20
.L7F03FCF8:
  lw    $t8, 0xe4($v0)
  beql  $t8, $zero, .L7F03FD34
   addiu $v1, $v1, 1
  bltzl $a2, .L7F03FD30
   move  $a2, $v1
  multu $a2, $a1
  lw    $t9, 0xe8($v0)
  mflo  $t1
  addu  $t2, $a3, $t1
  lw    $t3, 0xe8($t2)
  slt   $at, $t9, $t3
  beql  $at, $zero, .L7F03FD34
   addiu $v1, $v1, 1
  move  $a2, $v1
.L7F03FD30:
  addiu $v1, $v1, 1
.L7F03FD34:
  bne   $v1, $a0, .L7F03FCF8
   addiu $v0, $v0, 0xec
  bltz  $a2, .L7F03FD98
   move  $v0, $zero
  multu $a2, $a1
  mflo  $v1
  addu  $t0, $a3, $v1
  lw    $t4, 0xe4($t0)
  lw    $a0, 0x10($t4)
  sw    $t0, 0x20($sp)
  jal   sub_GAME_7F040CF0
   sw    $v1, 0x24($sp)
  lw    $t0, 0x20($sp)
  lw    $v1, 0x24($sp)
  lui   $a3, %hi(dword_CODE_bss_80073DC0)
  lw    $v0, 0xe4($t0)
  addiu $a3, %lo(dword_CODE_bss_80073DC0) # addiu $a3, $a3, 0x3dc0
  addu  $a0, $a3, $v1
  lw    $t5, 0x64($v0)
  ori   $t6, $t5, 4
  sw    $t6, 0x64($v0)
  jal   sub_GAME_7F03FBFC
   sw    $a0, 0x1c($sp)
  b     .L7F03FD98
   lw    $v0, 0x1c($sp)
.L7F03FD98:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F03FDA8
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  lw    $v1, 4($a0)
  lw    $v0, 0x64($v1)
  andi  $t6, $v0, 0x40
  beqz  $t6, .L7F03FDDC
   andi  $t8, $v0, 0x80
  jal   sub_GAME_7F03FC80
   sw    $v1, 0x1c($sp)
  lw    $v1, 0x1c($sp)
  lw    $t7, 0x6c($v1)
  b     .L7F03FE04
   sw    $v0, 0x44($t7)
.L7F03FDDC:
  bnezl $t8, .L7F03FE08
   lw    $ra, 0x14($sp)
  jal   sub_GAME_7F03FC80
   sw    $v1, 0x1c($sp)
  lw    $v1, 0x1c($sp)
  beqz  $v0, .L7F03FE04
   sw    $v0, 0x6c($v1)
  lw    $t9, 0x64($v1)
  ori   $t0, $t9, 0x80
  sw    $t0, 0x64($v1)
.L7F03FE04:
  lw    $ra, 0x14($sp)
.L7F03FE08:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F03FE14
  lw    $v0, 4($a0)
  move  $v1, $zero
  lw    $a1, 0x64($v0)
  andi  $t6, $a1, 0x40
  beqz  $t6, .L7F03FE38
   andi  $t8, $a1, 0x80
  lw    $t7, 0x6c($v0)
  b     .L7F03FE44
   lw    $v1, 0x44($t7)
.L7F03FE38:
  beqz  $t8, .L7F03FE44
   nop   
  lw    $v1, 0x6c($v0)
.L7F03FE44:
  beqz  $v1, .L7F03FE80
   nop   
  lw    $t9, ($v1)
  li    $t2, 255
  li    $t3, 255
  ori   $t0, $t9, 4
  sw    $t0, ($v1)
  lw    $v0, 0x14($a0)
  beql  $v0, $zero, .L7F03FE80
   sb    $t3, 0xcc($v1)
  lbu   $t1, 3($v0)
  sb    $t2, 0xcd($v1)
  jr    $ra
   sb    $t1, 0xcc($v1)

  sb    $t3, 0xcc($v1)
.L7F03FE80:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F03FE88
  lw    $t6, ($a0)
  ori   $t7, $t6, 1
  jr    $ra
   sw    $t7, ($a0)
");

asm(R"
glabel sub_GAME_7F03FE98
  lui   $a0, %hi(dword_CODE_bss_80075030)
  lui   $v0, %hi(objinst)
  addiu $v0, %lo(objinst) # addiu $v0, $v0, 0x5b70
  addiu $a0, %lo(dword_CODE_bss_80075030) # addiu $a0, $a0, 0x5030
  move  $v1, $zero
.L7F03FEAC:
  lw    $t6, ($a0)
  andi  $t7, $t6, 1
  beqz  $t7, .L7F03FED0
   lui   $t8, %hi(dword_CODE_bss_80075030) 
  addiu $t8, %lo(dword_CODE_bss_80075030) # addiu $t8, $t8, 0x5030
  sw    $zero, ($a0)
  sw    $zero, 0x44($a0)
  jr    $ra
   addu  $v0, $v1, $t8

.L7F03FED0:
  lw    $t9, 0x48($a0)
  andi  $t0, $t9, 1
  beqz  $t0, .L7F03FEF8
   lui   $t2, %hi(dword_CODE_bss_80075030) 
  addiu $t2, %lo(dword_CODE_bss_80075030) # addiu $t2, $t2, 0x5030
  addiu $t1, $v1, 0x48
  addu  $v0, $t1, $t2
  sw    $zero, 0x48($a0)
  jr    $ra
   sw    $zero, 0x8c($a0)

.L7F03FEF8:
  lw    $t3, 0x90($a0)
  andi  $t4, $t3, 1
  beqz  $t4, .L7F03FF20
   lui   $t6, %hi(dword_CODE_bss_80075030) 
  addiu $t6, %lo(dword_CODE_bss_80075030) # addiu $t6, $t6, 0x5030
  addiu $t5, $v1, 0x90
  addu  $v0, $t5, $t6
  sw    $zero, 0x90($a0)
  jr    $ra
   sw    $zero, 0xd4($a0)

.L7F03FF20:
  lw    $t7, 0xd8($a0)
  andi  $t8, $t7, 1
  beqz  $t8, .L7F03FF48
   lui   $t0, %hi(dword_CODE_bss_80075030) 
  addiu $t0, %lo(dword_CODE_bss_80075030) # addiu $t0, $t0, 0x5030
  addiu $t9, $v1, 0xd8
  addu  $v0, $t9, $t0
  sw    $zero, 0xd8($a0)
  jr    $ra
   sw    $zero, 0x11c($a0)

.L7F03FF48:
  addiu $a0, $a0, 0x120
  bne   $a0, $v0, .L7F03FEAC
   addiu $v1, $v1, 0x120
  move  $v0, $zero
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F03FF60
  lbu   $t6, 2($a0)
  lui   $at, 0x4080
  andi  $t7, $t6, 0x80
  bnezl $t7, .L7F03FFA0
   lwc1  $f4, 0x70($a0)
  li    $at, 0x40400000 # 3.000000
  mtc1  $at, $f6
  lwc1  $f4, 0x70($a0)
  lwc1  $f10, 0x74($a0)
  mul.s $f8, $f4, $f6
  div.s $f16, $f8, $f10
  trunc.w.s $f18, $f16
  mfc1  $v0, $f18
  jr    $ra
   nop   

  lwc1  $f4, 0x70($a0)
.L7F03FFA0:
  mtc1  $at, $f6
  nop   
  add.s $f8, $f4, $f6
  trunc.w.s $f10, $f8
  mfc1  $v0, $f10
  nop   
  jr    $ra
   nop   
");

asm(R"
glabel do_something_if_object_destroyed
  lbu   $t6, 2($a0)
  andi  $t7, $t6, 0x80
  bnezl $t7, .L7F03FFDC
   lwc1  $f4, 0x70($a0)
  jr    $ra
   move  $v0, $zero

  lwc1  $f4, 0x70($a0)
.L7F03FFDC:
  trunc.w.s $f6, $f4
  mfc1  $v0, $f6
  nop   
  sra   $t9, $v0, 2
  addiu $v0, $t9, 1
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F03FFF8
  lw    $t6, ($a0)
  lw    $v0, 0x14($t6)
  beql  $v0, $zero, .L7F040070
   move  $v0, $zero
  beqz  $v0, .L7F040034
   move  $v1, $v0
  li    $a1, 10
  lhu   $t7, ($v1)
.L7F040018:
  bnel  $a1, $t7, .L7F04002C
   lw    $v1, 0xc($v1)
  jr    $ra
   lw    $v0, 4($v1)

  lw    $v1, 0xc($v1)
.L7F04002C:
  bnezl $v1, .L7F040018
   lhu   $t7, ($v1)
.L7F040034:
  lw    $a0, 0x14($v0)
  li    $a1, 10
  beql  $a0, $zero, .L7F040070
   move  $v0, $zero
  beqz  $a0, .L7F04006C
   move  $v1, $a0
  lhu   $t8, ($v1)
.L7F040050:
  bnel  $a1, $t8, .L7F040064
   lw    $v1, 0xc($v1)
  jr    $ra
   lw    $v0, 4($v1)

  lw    $v1, 0xc($v1)
.L7F040064:
  bnezl $v1, .L7F040050
   lhu   $t8, ($v1)
.L7F04006C:
  move  $v0, $zero
.L7F040070:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F040078
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lw    $t6, 0x14($a0)
  jal   sub_GAME_7F03FFF8
   lw    $a0, 8($t6)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel set_color_shading_from_tile
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  move  $t6, $a0
  move  $a3, $a1
  lw    $a1, 8($t6)
  lw    $a2, 0x10($t6)
  lw    $a0, 0x14($a0)
  jal   copy_tile_RGB_as_24bit
   sw    $a3, 0x1c($sp)
  lw    $a3, 0x1c($sp)
  li    $at, 0x3F400000 # 0.750000
  mtc1  $at, $f8
  lbu   $t3, 2($a3)
  lbu   $t5, ($a3)
  lbu   $ra, 1($a3)
  sll   $t7, $t3, 2
  sll   $t8, $t5, 2
  addu  $t7, $t7, $t3
  addu  $t8, $t8, $t5
  sll   $t6, $ra, 2
  sll   $t8, $t8, 4
  sll   $t7, $t7, 2
  addu  $t6, $t6, $ra
  sll   $t6, $t6, 3
  addu  $t7, $t7, $t3
  subu  $t8, $t8, $t5
  addu  $t9, $t7, $t8
  subu  $t6, $t6, $ra
  sll   $t6, $t6, 2
  addu  $v1, $t9, $t6
  sra   $t7, $v1, 8
  li    $t8, 255
  subu  $t9, $t8, $t7
  mtc1  $t9, $f4
  li    $t7, 1
  li    $at, 0x4F000000 # 2147483648.000000
  cvt.s.w $f6, $f4
  move  $v0, $zero
  move  $t4, $zero
  mul.s $f10, $f6, $f8
  cfc1  $t6, $31
  ctc1  $t7, $31
  nop   
  cvt.w.s $f16, $f10
  cfc1  $t7, $31
  nop   
  andi  $t7, $t7, 0x78
  beql  $t7, $zero, .L7F0401AC
   mfc1  $t7, $f16
  mtc1  $at, $f16
  li    $t7, 1
  sub.s $f16, $f10, $f16
  ctc1  $t7, $31
  nop   
  cvt.w.s $f16, $f16
  cfc1  $t7, $31
  nop   
  andi  $t7, $t7, 0x78
  bnez  $t7, .L7F0401A0
   nop   
  mfc1  $t7, $f16
  lui   $at, 0x8000
  b     .L7F0401B8
   or    $t7, $t7, $at
.L7F0401A0:
  b     .L7F0401B8
   li    $t7, -1
  mfc1  $t7, $f16
.L7F0401AC:
  nop   
  bltz  $t7, .L7F0401A0
   nop   
.L7F0401B8:
  ctc1  $t6, $31
  slt   $at, $t5, $ra
  beqz  $at, .L7F0401D0
   sb    $t7, 3($a3)
  b     .L7F0401D4
   li    $v0, 1
.L7F0401D0:
  li    $t4, 1
.L7F0401D4:
  addu  $t2, $a3, $v0
  lbu   $a2, ($t2)
  move  $a1, $v0
  addu  $t8, $a3, $t4
  slt   $at, $a2, $t3
  beql  $at, $zero, .L7F040200
   lbu   $t9, ($t8)
  addiu $t2, $a3, 2
  b     .L7F04021C
   lbu   $a2, ($t2)
  lbu   $t9, ($t8)
.L7F040200:
  move  $a1, $t4
  slt   $at, $t9, $t3
  beql  $at, $zero, .L7F04021C
   li    $t4, 2
  b     .L7F04021C
   li    $a1, 2
  li    $t4, 2
.L7F04021C:
  blez  $a2, .L7F04028C
   addu  $v1, $a3, $a1
  addu  $v0, $a3, $t4
  lbu   $t6, ($v0)
  lbu   $t7, ($v1)
  sb    $zero, ($v0)
  subu  $a0, $a2, $t6
  multu $t7, $a0
  move  $t1, $a0
  mflo  $t8
  nop   
  nop   
  div   $zero, $t8, $a2
  mflo  $t0
  sb    $t0, ($v1)
  sb    $a0, ($t2)
  bnez  $a2, .L7F040268
   nop   
  break 7
.L7F040268:
  li    $at, -1
  bne   $a2, $at, .L7F040280
   lui   $at, 0x8000
  bne   $t8, $at, .L7F040280
   nop   
  break 6
.L7F040280:
  lbu   $ra, 1($a3)
  lbu   $t5, ($a3)
  lbu   $t3, 2($a3)
.L7F04028C:
  srl   $t9, $t5, 1
  srl   $t6, $ra, 1
  srl   $t7, $t3, 1
  sb    $t9, ($a3)
  sb    $t6, 1($a3)
  sb    $t7, 2($a3)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0402B4
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lw    $v0, 4($a0)
  lw    $t6, 8($v0)
  andi  $t7, $t6, 0x400
  bnezl $t7, .L7F040304
   lw    $ra, 0x14($sp)
  jal   set_color_shading_from_tile
   sw    $a1, 0x1c($sp)
  lw    $a1, 0x1c($sp)
  lbu   $t8, ($a1)
  lbu   $t0, 1($a1)
  lbu   $t2, 2($a1)
  srl   $t9, $t8, 1
  srl   $t1, $t0, 1
  srl   $t3, $t2, 1
  sb    $t9, ($a1)
  sb    $t1, 1($a1)
  sb    $t3, 2($a1)
  lw    $ra, 0x14($sp)
.L7F040304:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel update_color_shading
  lbu   $t0, ($a0)
  lbu   $t6, ($a1)
  lbu   $t1, 1($a0)
  lbu   $t2, 2($a0)
  subu  $v0, $t6, $t0
  addiu $t7, $v0, 7
  sra   $t8, $t7, 3
  addu  $v1, $t0, $t8
  sb    $v1, ($a0)
  lbu   $t9, 1($a1)
  lbu   $t3, 3($a0)
  subu  $v0, $t9, $t1
  addiu $t4, $v0, 7
  sra   $t5, $t4, 3
  addu  $v1, $t1, $t5
  sb    $v1, 1($a0)
  lbu   $t6, 2($a1)
  subu  $v0, $t6, $t2
  addiu $t7, $v0, 7
  sra   $t8, $t7, 3
  addu  $v1, $t2, $t8
  sb    $v1, 2($a0)
  lbu   $t9, 3($a1)
  subu  $v0, $t9, $t3
  addiu $t4, $v0, 7
  sra   $t5, $t4, 3
  addu  $v1, $t3, $t5
  jr    $ra
   sb    $v1, 3($a0)
");

asm(R"
glabel sub_GAME_7F040384
  li    $at, 1
  bne   $a1, $at, .L7F04047C
   li    $at, 0x437F0000 # 255.000000
  mtc1  $at, $f2
  lwc1  $f4, ($a2)
  lwc1  $f8, 4($a2)
  lwc1  $f16, 8($a2)
  mul.s $f6, $f4, $f2
  nop   
  mul.s $f10, $f8, $f2
  nop   
  mul.s $f18, $f16, $f2
  swc1  $f6, ($a2)
  lwc1  $f8, ($a2)
  lwc1  $f6, 0xc($a2)
  swc1  $f10, 4($a2)
  swc1  $f18, 8($a2)
  lw    $t6, ($a0)
  lw    $t9, 4($a0)
  lw    $t2, 8($a0)
  mtc1  $t6, $f4
  lw    $t5, 0xc($a0)
  cvt.s.w $f0, $f4
  sub.s $f10, $f8, $f0
  mtc1  $t9, $f8
  mul.s $f16, $f6, $f10
  add.s $f18, $f16, $f0
  cvt.s.w $f0, $f8
  trunc.w.s $f4, $f18
  mfc1  $t8, $f4
  nop   
  sw    $t8, ($a0)
  lwc1  $f10, 4($a2)
  lwc1  $f6, 0xc($a2)
  sub.s $f16, $f10, $f0
  mtc1  $t2, $f10
  mul.s $f18, $f6, $f16
  add.s $f4, $f18, $f0
  cvt.s.w $f0, $f10
  trunc.w.s $f8, $f4
  mfc1  $t1, $f8
  nop   
  sw    $t1, 4($a0)
  lwc1  $f16, 8($a2)
  lwc1  $f6, 0xc($a2)
  sub.s $f18, $f16, $f0
  mtc1  $t5, $f16
  mul.s $f4, $f6, $f18
  add.s $f8, $f4, $f0
  cvt.s.w $f0, $f16
  trunc.w.s $f10, $f8
  sub.s $f18, $f2, $f0
  mfc1  $t4, $f10
  nop   
  sw    $t4, 8($a0)
  lwc1  $f6, 0xc($a2)
  mul.s $f4, $f6, $f18
  add.s $f8, $f4, $f0
  trunc.w.s $f10, $f8
  mfc1  $t7, $f10
  nop   
  sw    $t7, 0xc($a0)
.L7F04047C:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F040484
  addiu $sp, $sp, -0x68
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  lw    $t6, 0x68($a0)
  move  $s0, $a0
  beql  $t6, $zero, .L7F04053C
   lw    $ra, 0x1c($sp)
  jal   sub_GAME_7F040078
   nop   
  sw    $v0, 0x64($sp)
  addiu $a0, $s0, 0x18
  jal   sub_GAME_7F058020
   addiu $a1, $sp, 0x24
  addiu $a0, $s0, 0x58
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   addiu $a1, $sp, 0x24
  lw    $a3, 0x68($s0)
  lw    $a0, 0x64($sp)
  addiu $a1, $sp, 0x24
  jal   sub_GAME_7F03F540
   addiu $a2, $a3, 4
  lw    $a0, 0x64($sp)
  jal   sub_GAME_7F03E9BC
   addiu $a1, $sp, 0x24
  lwc1  $f4, 0x5c($s0)
  lw    $t7, 0x68($s0)
  addiu $a1, $sp, 0x24
  add.s $f6, $f0, $f4
  swc1  $f6, 0x48($t7)
  jal   sub_GAME_7F03EA5C
   lw    $a0, 0x64($sp)
  lwc1  $f8, 0x5c($s0)
  lw    $t8, 0x68($s0)
  li    $at, 40
  add.s $f10, $f0, $f8
  swc1  $f10, 0x44($t8)
  lbu   $t9, 3($s0)
  bnel  $t9, $at, .L7F04053C
   lw    $ra, 0x1c($sp)
  lw    $a3, 0x68($s0)
  li    $at, 0x43480000 # 200.000000
  mtc1  $at, $f18
  lwc1  $f16, 0x48($a3)
  sub.s $f4, $f16, $f18
  swc1  $f4, 0x48($a3)
  lw    $ra, 0x1c($sp)
.L7F04053C:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x68
  jr    $ra
   nop   
");

asm(R"
glabel init_standard_object
  addiu $sp, $sp, -0x20
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  move  $s0, $a0
  move  $s1, $a2
  bnez  $a2, .L7F040580
   sw    $ra, 0x1c($sp)
  sw    $a1, 0x24($sp)
  jal   remove_last_obj_pos_data_entry
   sw    $a3, 0x2c($sp)
  lw    $a1, 0x24($sp)
  lw    $a3, 0x2c($sp)
  move  $s1, $v0
.L7F040580:
  bnez  $a3, .L7F0405B4
   nop   
  lbu   $t6, 3($s0)
  li    $at, 40
  bne   $t6, $at, .L7F0405A8
   nop   
  jal   get_aircraft_obj_instance_controller
   move  $a0, $a1
  b     .L7F0405B4
   move  $a3, $v0
.L7F0405A8:
  jal   get_obj_instance_controller_for_header
   move  $a0, $a1
  move  $a3, $v0
.L7F0405B4:
  beqz  $s1, .L7F04069C
   nop   
  beqz  $a3, .L7F04069C
   nop   
  lw    $t7, 8($s0)
  sw    $a3, 0x14($s0)
  sw    $zero, 0x68($s0)
  andi  $t8, $t7, 0x100
  beqz  $t8, .L7F0405F8
   li    $a0, 80
  jal   mempAllocBytesInBank
   li    $a1, 4
  lbu   $t9, 2($s0)
  sw    $v0, 0x68($s0)
  ori   $t0, $t9, 8
  b     .L7F040604
   sb    $t0, 2($s0)
.L7F0405F8:
  lbu   $t1, 2($s0)
  andi  $t2, $t1, 0xfff7
  sb    $t2, 2($s0)
.L7F040604:
  mtc1  $zero, $f0
  lw    $t4, 0x14($s0)
  sw    $s1, 0x10($s0)
  sw    $zero, 0x6c($s0)
  sb    $zero, 0x78($s0)
  sb    $zero, 0x79($s0)
  sb    $zero, 0x7a($s0)
  sb    $zero, 0x7b($s0)
  sb    $zero, 0x7c($s0)
  sb    $zero, 0x7d($s0)
  sb    $zero, 0x7e($s0)
  sb    $zero, 0x7f($s0)
  li    $t3, -1
  swc1  $f0, 0x70($s0)
  sh    $t3, ($t4)
  lw    $t5, 0x14($s0)
  lui   $a1, %hi(PitemZ_entries+8)
  sw    $zero, 4($t5)
  lh    $t6, 4($s0)
  lw    $a0, 0x14($s0)
  sll   $t7, $t6, 2
  subu  $t7, $t7, $t6
  sll   $t7, $t7, 2
  addu  $a1, $a1, $t7
  jal   set_obj_instance_controller_scale
   lw    $a1, %lo(PitemZ_entries+8)($a1)
  mtc1  $zero, $f0
  li    $t8, 1
  sb    $t8, ($s1)
  sw    $s0, 4($s1)
  swc1  $f0, 8($s1)
  swc1  $f0, 0x58($s0)
  swc1  $f0, 0xc($s1)
  swc1  $f0, 0x5c($s0)
  swc1  $f0, 0x10($s1)
  swc1  $f0, 0x60($s0)
  b     .L7F0406E0
   sw    $zero, 0x14($s1)
.L7F04069C:
  beqz  $a3, .L7F0406CC
   nop   
  lbu   $t9, 3($s0)
  li    $at, 40
  bne   $t9, $at, .L7F0406C4
   nop   
  jal   set_aircraft_obj_inst_scale_to_zero
   move  $a0, $a3
  b     .L7F0406CC
   nop   
.L7F0406C4:
  jal   set_obj_instance_scale_to_zero
   move  $a0, $a3
.L7F0406CC:
  beql  $s1, $zero, .L7F0406E4
   lw    $ra, 0x1c($sp)
  jal   set_last_obj_pos_data
   move  $a0, $s1
  move  $s1, $zero
.L7F0406E0:
  lw    $ra, 0x1c($sp)
.L7F0406E4:
  move  $v0, $s1
  lw    $s1, 0x18($sp)
  lw    $s0, 0x14($sp)
  jr    $ra
   addiu $sp, $sp, 0x20
");

asm(R"
glabel sub_GAME_7F0406F8
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  move  $a2, $zero
  jal   init_standard_object
   move  $a3, $zero
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F04071C
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lh    $t6, 4($a0)
  lui   $a1, %hi(PitemZ_entries)
  sll   $t7, $t6, 2
  subu  $t7, $t7, $t6
  sll   $t7, $t7, 2
  addu  $a1, $a1, $t7
  jal   sub_GAME_7F0406F8
   lw    $a1, %lo(PitemZ_entries)($a1)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F040754
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a1, 0x2c($sp)
  sw    $a3, 0x34($sp)
  lw    $v0, 0x10($a0)
  move  $s0, $a0
  addiu $a1, $s0, 0x18
  move  $a0, $a2
  jal   sub_GAME_7F058020
   sw    $v0, 0x24($sp)
  lw    $v1, 0x2c($sp)
  lw    $v0, 0x24($sp)
  addiu $a1, $s0, 0x7c
  lwc1  $f0, ($v1)
  swc1  $f0, 8($v0)
  swc1  $f0, 0x58($s0)
  lwc1  $f0, 4($v1)
  swc1  $f0, 0xc($v0)
  swc1  $f0, 0x5c($s0)
  lwc1  $f0, 8($v1)
  swc1  $f0, 0x10($v0)
  swc1  $f0, 0x60($s0)
  lw    $t6, 0x34($sp)
  sw    $t6, 0x14($v0)
  jal   sub_GAME_7F0402B4
   lw    $a0, 0x10($s0)
  lbu   $t7, 0x7c($s0)
  lbu   $t8, 0x7d($s0)
  lbu   $t9, 0x7e($s0)
  lbu   $t0, 0x7f($s0)
  sb    $t7, 0x78($s0)
  sb    $t8, 0x79($s0)
  sb    $t9, 0x7a($s0)
  sb    $t0, 0x7b($s0)
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0407F4
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a0, 0x28($sp)
  sw    $a2, 0x30($sp)
  sw    $a3, 0x34($sp)
  lw    $t7, 0x14($a0)
  move  $s0, $a1
  jal   sub_GAME_7F03FFF8
   lw    $a0, 8($t7)
  sw    $v0, 0x20($sp)
  lw    $a2, 8($s0)
  lw    $a1, ($s0)
  jal   sub_GAME_7F0B2970
   lw    $a0, 0x34($sp)
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f4
  nop   
  add.s $f6, $f0, $f4
  swc1  $f6, 4($s0)
  lw    $a1, 0x30($sp)
  jal   sub_GAME_7F03E9BC
   lw    $a0, 0x20($sp)
  lwc1  $f8, 4($s0)
  move  $a1, $s0
  sub.s $f10, $f8, $f0
  swc1  $f10, 4($s0)
  lw    $a3, 0x34($sp)
  lw    $a2, 0x30($sp)
  jal   sub_GAME_7F040754
   lw    $a0, 0x28($sp)
  jal   sub_GAME_7F040484
   lw    $a0, 0x28($sp)
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_800529D0
.word 0xA000000 /*"\n"*/
glabel D_800529D4
.word 0x2E0A0000 /*".\n"*/
glabel D_800529D8
.word 0, 0, 0, 0, 0, 0, 0, 0
.word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
glabel D_80052A38
.word 0
glabel D_80052A3C
.word 0
glabel D_80052A40
.word 0xA000000 /*"\n"*/
glabel D_80052A44
.word 0x3A0A0000 /*":\n"*/
glabel D_80052A48
.word 0x3d4ccccd /*0.050000001*/
.late_rodata
glabel D_80052A4C
.word 0x40490fdb /*3.1415927*/

.text
glabel sub_GAME_7F04088C
  addiu $sp, $sp, -0xa8
  sw    $ra, 0x24($sp)
  sw    $s0, 0x20($sp)
  sw    $a1, 0xac($sp)
  sw    $a2, 0xb0($sp)
  sw    $a3, 0xb4($sp)
  lw    $t6, 0x14($a0)
  move  $s0, $a0
  jal   sub_GAME_7F03FFF8
   lw    $a0, 8($t6)
  sw    $v0, 0xa0($sp)
  jal   sub_GAME_7F03E864
   move  $a0, $v0
  lw    $a0, 0xa0($sp)
  jal   sub_GAME_7F03E86C
   swc1  $f0, 0x9c($sp)
  lw    $a3, 0xb4($sp)
  swc1  $f0, 0x98($sp)
  lwc1  $f2, 0x9c($sp)
  sw    $a3, 0x88($sp)
  lw    $v0, 8($s0)
  lui   $at, %hi(D_80052A4C)
  addiu $a1, $sp, 0x48
  andi  $t7, $v0, 4
  beqz  $t7, .L7F040950
   andi  $t8, $v0, 8
  jal   sub_GAME_7F058688
   lwc1  $f12, %lo(D_80052A4C)($at)
  lw    $a0, 0xb0($sp)
  jal   sub_GAME_7F058068
   addiu $a1, $sp, 0x48
  lwc1  $f0, 0x98($sp)
  lwc1  $f6, 0x58($sp)
  lw    $v0, 0xb8($sp)
  lwc1  $f18, 0x5c($sp)
  mul.s $f8, $f6, $f0
  lwc1  $f4, ($v0)
  mul.s $f6, $f18, $f0
  sub.s $f10, $f4, $f8
  swc1  $f10, 0x8c($sp)
  lwc1  $f16, 4($v0)
  lwc1  $f10, 0x60($sp)
  sub.s $f4, $f16, $f6
  mul.s $f18, $f10, $f0
  swc1  $f4, 0x90($sp)
  lwc1  $f8, 8($v0)
  sub.s $f16, $f8, $f18
  b     .L7F040AEC
   swc1  $f16, 0x94($sp)
.L7F040950:
  beqz  $t8, .L7F0409B0
   lw    $v0, 0xac($sp)
  lw    $a0, 0xb0($sp)
  addiu $a1, $sp, 0x48
  jal   sub_GAME_7F058020
   swc1  $f2, 0x9c($sp)
  lwc1  $f2, 0x9c($sp)
  lwc1  $f4, 0x58($sp)
  lw    $v0, 0xb8($sp)
  lwc1  $f16, 0x5c($sp)
  mul.s $f10, $f4, $f2
  lwc1  $f6, ($v0)
  mul.s $f4, $f16, $f2
  sub.s $f8, $f6, $f10
  swc1  $f8, 0x8c($sp)
  lwc1  $f18, 4($v0)
  lwc1  $f8, 0x60($sp)
  sub.s $f6, $f18, $f4
  mul.s $f16, $f8, $f2
  swc1  $f6, 0x90($sp)
  lwc1  $f10, 8($v0)
  sub.s $f18, $f10, $f16
  b     .L7F040AEC
   swc1  $f18, 0x94($sp)
.L7F0409B0:
  lw    $a1, ($v0)
  lw    $a2, 8($v0)
  swc1  $f2, 0x9c($sp)
  jal   sub_GAME_7F0B2970
   move  $a0, $a3
  lw    $a0, 0xb0($sp)
  addiu $a1, $sp, 0x48
  jal   sub_GAME_7F058020
   swc1  $f0, 0x40($sp)
  lwc1  $f2, 0x9c($sp)
  lwc1  $f6, 0x58($sp)
  lw    $v0, 0xb8($sp)
  lwc1  $f18, 0x60($sp)
  mul.s $f8, $f6, $f2
  lwc1  $f4, ($v0)
  lw    $t9, 0xb4($sp)
  mul.s $f6, $f18, $f2
  lw    $a0, 0xac($sp)
  sub.s $f10, $f4, $f8
  swc1  $f10, 0x8c($sp)
  lwc1  $f16, 8($v0)
  sub.s $f4, $f16, $f6
  swc1  $f4, 0x94($sp)
  jal   sub_GAME_7F03FAB0
   lbu   $a1, 3($t9)
  lwc1  $f2, 0x9c($sp)
  beqz  $v0, .L7F040AD0
   lwc1  $f12, 0x40($sp)
  lw    $a0, 0x10($v0)
  addiu $t0, $sp, 0x30
  sw    $t0, 0x10($sp)
  swc1  $f12, 0x40($sp)
  swc1  $f2, 0x9c($sp)
  addiu $a1, $sp, 0x3c
  addiu $a2, $sp, 0x38
  jal   sub_GAME_7F03CC20
   addiu $a3, $sp, 0x34
  lwc1  $f12, 0x40($sp)
  lwc1  $f8, 0x34($sp)
  lwc1  $f2, 0x9c($sp)
  lwc1  $f16, 0x98($sp)
  c.lt.s $f12, $f8
  nop   
  bc1fl .L7F040AB4
   lwc1  $f10, 0x5c($sp)
  sub.s $f6, $f16, $f2
  lwc1  $f18, 0x5c($sp)
  li    $at, 0x40800000 # 4.000000
  lwc1  $f10, 0x30($sp)
  mul.s $f4, $f18, $f6
  mtc1  $at, $f6
  add.s $f16, $f4, $f12
  add.s $f4, $f16, $f6
  c.lt.s $f10, $f4
  nop   
  bc1fl .L7F040AB4
   lwc1  $f10, 0x5c($sp)
  mul.s $f16, $f18, $f2
  sub.s $f6, $f8, $f16
  swc1  $f6, 0x90($sp)
  lw    $t1, 0x64($s0)
  ori   $t2, $t1, 0x8000
  b     .L7F040AEC
   sw    $t2, 0x64($s0)
  lwc1  $f10, 0x5c($sp)
.L7F040AB4:
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f8
  mul.s $f4, $f10, $f2
  sub.s $f18, $f12, $f4
  add.s $f16, $f18, $f8
  b     .L7F040AEC
   swc1  $f16, 0x90($sp)
.L7F040AD0:
  lwc1  $f6, 0x5c($sp)
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f18
  mul.s $f10, $f6, $f2
  sub.s $f4, $f12, $f10
  add.s $f8, $f4, $f18
  swc1  $f8, 0x90($sp)
.L7F040AEC:
  lw    $t3, 0xc($s0)
  lw    $v0, 0xac($sp)
  addiu $a0, $sp, 0x88
  andi  $t4, $t3, 1
  bnez  $t4, .L7F040B38
   lw    $a3, 0x8c($sp)
  lwc1  $f16, 0x94($sp)
  lw    $a1, ($v0)
  lw    $a2, 8($v0)
  jal   sub_GAME_7F0B0BE4
   swc1  $f16, 0x10($sp)
  beqz  $v0, .L7F040B38
   move  $a0, $s0
  addiu $a1, $sp, 0x8c
  addiu $a2, $sp, 0x48
  jal   sub_GAME_7F040754
   lw    $a3, 0x88($sp)
  b     .L7F040B84
   nop   
.L7F040B38:
  move  $a0, $s0
  lw    $a1, 0xac($sp)
  addiu $a2, $sp, 0x48
  jal   sub_GAME_7F040754
   lw    $a3, 0xb4($sp)
  lw    $t5, 0xc($s0)
  lwc1  $f6, 0x8c($sp)
  andi  $t6, $t5, 1
  bnezl $t6, .L7F040B74
   swc1  $f6, 0x58($s0)
  lw    $t7, 8($s0)
  andi  $t8, $t7, 0x1000
  beqz  $t8, .L7F040B84
   nop   
  swc1  $f6, 0x58($s0)
.L7F040B74:
  lwc1  $f10, 0x90($sp)
  swc1  $f10, 0x5c($s0)
  lwc1  $f4, 0x94($sp)
  swc1  $f4, 0x60($s0)
.L7F040B84:
  jal   sub_GAME_7F040484
   move  $a0, $s0
  lw    $ra, 0x24($sp)
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0xa8
  jr    $ra
   nop   
");






asm(R"
.late_rodata
glabel D_80052A50
.word 0x4096cbe4 /*4.712389*/
glabel D_80052A54
.word 0x40490fdb /*3.1415927*/

.text
glabel sub_GAME_7F040BA0
  addiu $sp, $sp, -0xc8
  sw    $ra, 0x24($sp)
  sw    $s0, 0x20($sp)
  sw    $a1, 0xcc($sp)
  sw    $a2, 0xd0($sp)
  sw    $a3, 0xd4($sp)
  lw    $t6, 0x14($a0)
  move  $s0, $a0
  jal   sub_GAME_7F03FFF8
   lw    $a0, 8($t6)
  jal   sub_GAME_7F03E874
   move  $a0, $v0
  lw    $t7, 0xd4($sp)
  lui   $at, %hi(D_80052A50)
  swc1  $f0, 0xbc($sp)
  lwc1  $f12, %lo(D_80052A50)($at)
  addiu $a1, $sp, 0x6c
  jal   sub_GAME_7F058570
   sw    $t7, 0xac($sp)
  lui   $at, %hi(D_80052A54)
  lwc1  $f12, %lo(D_80052A54)($at)
  jal   sub_GAME_7F0585FC
   addiu $a1, $sp, 0x2c
  addiu $a0, $sp, 0x2c
  jal   sub_GAME_7F058068
   addiu $a1, $sp, 0x6c
  lw    $a0, 0xd0($sp)
  jal   sub_GAME_7F058068
   addiu $a1, $sp, 0x6c
  lwc1  $f0, 0xbc($sp)
  lwc1  $f6, 0x8c($sp)
  lw    $v0, 0xd8($sp)
  lwc1  $f18, 0x90($sp)
  mul.s $f8, $f6, $f0
  lwc1  $f4, ($v0)
  addiu $a0, $sp, 0xac
  mul.s $f6, $f18, $f0
  sub.s $f10, $f4, $f8
  swc1  $f10, 0xb0($sp)
  lwc1  $f16, 4($v0)
  lwc1  $f10, 0x94($sp)
  lw    $a3, 0xb0($sp)
  sub.s $f4, $f16, $f6
  mul.s $f18, $f10, $f0
  swc1  $f4, 0xb4($sp)
  lwc1  $f8, 8($v0)
  lw    $v0, 0xcc($sp)
  sub.s $f16, $f8, $f18
  swc1  $f16, 0xb8($sp)
  lw    $t8, 0xc($s0)
  lwc1  $f6, 0xb8($sp)
  andi  $t9, $t8, 1
  bnezl $t9, .L7F040CAC
   move  $a0, $s0
  lw    $a1, ($v0)
  lw    $a2, 8($v0)
  jal   sub_GAME_7F0B0BE4
   swc1  $f6, 0x10($sp)
  beqz  $v0, .L7F040CA8
   move  $a0, $s0
  addiu $a1, $sp, 0xb0
  addiu $a2, $sp, 0x6c
  jal   sub_GAME_7F040754
   lw    $a3, 0xac($sp)
  b     .L7F040CD4
   nop   
.L7F040CA8:
  move  $a0, $s0
.L7F040CAC:
  lw    $a1, 0xcc($sp)
  addiu $a2, $sp, 0x6c
  jal   sub_GAME_7F040754
   lw    $a3, 0xd4($sp)
  lwc1  $f4, 0xb0($sp)
  swc1  $f4, 0x58($s0)
  lwc1  $f10, 0xb4($sp)
  swc1  $f10, 0x5c($s0)
  lwc1  $f8, 0xb8($sp)
  swc1  $f8, 0x60($s0)
.L7F040CD4:
  jal   sub_GAME_7F040484
   move  $a0, $s0
  lw    $ra, 0x24($sp)
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0xc8
  jr    $ra
   nop   
");






asm(R"
glabel sub_GAME_7F040CF0
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  lw    $v0, 4($a0)
  lw    $v1, 0x64($v0)
  andi  $t6, $v1, 0x40
  beqz  $t6, .L7F040D5C
   andi  $t8, $v1, 0x80
  lw    $a0, 0x6c($v0)
  beql  $a0, $zero, .L7F040D4C
   li    $at, -65
  lw    $a1, 0x44($a0)
  beqz  $a1, .L7F040D38
   nop   
  move  $a0, $a1
  jal   sub_GAME_7F03FB70
   sw    $v0, 0x1c($sp)
  lw    $v0, 0x1c($sp)
  lw    $a0, 0x6c($v0)
.L7F040D38:
  jal   sub_GAME_7F03FE88
   sw    $v0, 0x1c($sp)
  lw    $v0, 0x1c($sp)
  lw    $v1, 0x64($v0)
  li    $at, -65
.L7F040D4C:
  and   $t7, $v1, $at
  sw    $zero, 0x6c($v0)
  b     .L7F040D88
   sw    $t7, 0x64($v0)
.L7F040D5C:
  beql  $t8, $zero, .L7F040D8C
   lw    $ra, 0x14($sp)
  lw    $a0, 0x6c($v0)
  jal   sub_GAME_7F03FB70
   sw    $v0, 0x1c($sp)
  lw    $v0, 0x1c($sp)
  li    $at, -129
  lw    $t9, 0x64($v0)
  sw    $zero, 0x6c($v0)
  and   $t0, $t9, $at
  sw    $t0, 0x64($v0)
.L7F040D88:
  lw    $ra, 0x14($sp)
.L7F040D8C:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");






asm(R"
glabel sub_GAME_7F040D98
  addiu $sp, $sp, -0x28
  sw    $ra, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a1, 0x2c($sp)
  lbu   $v0, 3($a0)
  li    $at, 13
  move  $s0, $a2
  bne   $v0, $at, .L7F040E14
   move  $s2, $a0
  lw    $a0, 0xc4($a0)
  beql  $a0, $zero, .L7F040DEC
   lw    $a0, 0xc8($s2)
  jal   sfxGetArg0Unk3F
   nop   
  beql  $v0, $zero, .L7F040DEC
   lw    $a0, 0xc8($s2)
  jal   sfxDeactivate
   lw    $a0, 0xc4($s2)
  lw    $a0, 0xc8($s2)
.L7F040DEC:
  beql  $a0, $zero, .L7F040F28
   lw    $s1, 0x10($s2)
  jal   sfxGetArg0Unk3F
   nop   
  beql  $v0, $zero, .L7F040F28
   lw    $s1, 0x10($s2)
  jal   sfxDeactivate
   lw    $a0, 0xc8($s2)
  b     .L7F040F28
   lw    $s1, 0x10($s2)
.L7F040E14:
  li    $at, 8
  bnel  $v0, $at, .L7F040E3C
   li    $at, 1
  lw    $v0, 0x84($s2)
  beql  $v0, $zero, .L7F040F28
   lw    $s1, 0x10($s2)
  sw    $zero, 0x84($v0)
  b     .L7F040F24
   sw    $zero, 0x84($s2)
  li    $at, 1
.L7F040E3C:
  bnel  $v0, $at, .L7F040E98
   li    $at, 47
  lw    $a0, 0xf4($s2)
  beql  $a0, $zero, .L7F040E6C
   lw    $a0, 0xf8($s2)
  jal   sfxGetArg0Unk3F
   nop   
  beql  $v0, $zero, .L7F040E6C
   lw    $a0, 0xf8($s2)
  jal   sfxDeactivate
   lw    $a0, 0xf4($s2)
  lw    $a0, 0xf8($s2)
.L7F040E6C:
  beql  $a0, $zero, .L7F040F28
   lw    $s1, 0x10($s2)
  jal   sfxGetArg0Unk3F
   nop   
  beql  $v0, $zero, .L7F040F28
   lw    $s1, 0x10($s2)
  jal   sfxDeactivate
   lw    $a0, 0xf8($s2)
  b     .L7F040F28
   lw    $s1, 0x10($s2)
  li    $at, 47
.L7F040E98:
  bnel  $v0, $at, .L7F040EC0
   li    $at, 40
  lw    $a0, 0x8c($s2)
  bltzl $a0, .L7F040F28
   lw    $s1, 0x10($s2)
  jal   sub_GAME_7F0B9DBC
   li    $a1, 1
  b     .L7F040F28
   lw    $s1, 0x10($s2)
  li    $at, 40
.L7F040EC0:
  bnel  $v0, $at, .L7F040EF8
   li    $at, 39
  lw    $a0, 0xb0($s2)
  beql  $a0, $zero, .L7F040F28
   lw    $s1, 0x10($s2)
  jal   sfxGetArg0Unk3F
   nop   
  beql  $v0, $zero, .L7F040F28
   lw    $s1, 0x10($s2)
  jal   sfxDeactivate
   lw    $a0, 0xb0($s2)
  b     .L7F040F28
   lw    $s1, 0x10($s2)
  li    $at, 39
.L7F040EF8:
  bnel  $v0, $at, .L7F040F28
   lw    $s1, 0x10($s2)
  lw    $a0, 0xac($s2)
  beql  $a0, $zero, .L7F040F28
   lw    $s1, 0x10($s2)
  jal   sfxGetArg0Unk3F
   nop   
  beql  $v0, $zero, .L7F040F28
   lw    $s1, 0x10($s2)
  jal   sfxDeactivate
   lw    $a0, 0xac($s2)
.L7F040F24:
  lw    $s1, 0x10($s2)
.L7F040F28:
  beqz  $s1, .L7F04100C
   move  $a0, $s1
  jal   sub_GAME_7F0A0CCC
   move  $a1, $zero
  lw    $a0, 0x10($s2)
  jal   sub_GAME_7F0A0CCC
   li    $a1, 1
  bnezl $s0, .L7F041010
   lw    $ra, 0x24($sp)
  jal   sub_GAME_7F040CF0
   lw    $a0, 0x10($s2)
  lw    $s1, 0x10($s2)
  lw    $t6, 0x1c($s1)
  beqz  $t6, .L7F040F70
   nop   
  jal   sub_GAME_7F04C044
   move  $a0, $s1
  lw    $s1, 0x10($s2)
.L7F040F70:
  jal   sub_GAME_7F03E18C
   move  $a0, $s1
  lw    $s1, 0x10($s2)
  lw    $s0, 0x20($s1)
  beql  $s0, $zero, .L7F040FA8
   lbu   $t7, ($s1)
.L7F040F88:
  lw    $s1, 0x24($s0)
  lw    $a0, 4($s0)
  jal   sub_GAME_7F041024
   li    $a1, 1
  bnez  $s1, .L7F040F88
   move  $s0, $s1
  lw    $s1, 0x10($s2)
  lbu   $t7, ($s1)
.L7F040FA8:
  li    $at, 2
  beql  $t7, $at, .L7F040FC0
   lbu   $t8, 3($s2)
  jal   sub_GAME_7F050DE8
   lw    $a0, 0x14($s2)
  lbu   $t8, 3($s2)
.L7F040FC0:
  li    $at, 40
  bne   $t8, $at, .L7F040FDC
   nop   
  jal   set_aircraft_obj_inst_scale_to_zero
   lw    $a0, 0x14($s2)
  b     .L7F040FE8
   lw    $t9, 0x2c($sp)
.L7F040FDC:
  jal   set_obj_instance_scale_to_zero
   lw    $a0, 0x14($s2)
  lw    $t9, 0x2c($sp)
.L7F040FE8:
  beql  $t9, $zero, .L7F04100C
   sw    $zero, 0x10($s2)
  jal   sub_GAME_7F03A538
   lw    $a0, 0x10($s2)
  jal   unset_stateflag_0x04_for_posdata
   lw    $a0, 0x10($s2)
  jal   set_last_obj_pos_data
   lw    $a0, 0x10($s2)
  sw    $zero, 0x10($s2)
.L7F04100C:
  lw    $ra, 0x24($sp)
.L7F041010:
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");






asm(R"
glabel sub_GAME_7F041024
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F040D98
   move  $a2, $zero
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");






asm(R"
glabel if_a0_plus_3_is_4_then_10_else_20
  lbu   $t6, 3($a0)
  li    $at, 4
  bne   $t6, $at, .L7F041060
   li    $at, 0x41A00000 # 20.000000
  mtc1  $at, $f0
  jr    $ra
   nop   

.L7F041060:
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f0
  nop   
  jr    $ra
   nop   
");






asm(R"
glabel sub_GAME_7F041074
  addiu $sp, $sp, -0x18
  sw    $a3, 0x24($sp)
  lwc1  $f10, ($a0)
  lwc1  $f8, ($a2)
  move  $v0, $zero
  sub.s $f6, $f8, $f10
  swc1  $f6, 0xc($sp)
  lwc1  $f8, 4($a0)
  lwc1  $f4, 4($a2)
  sub.s $f10, $f4, $f8
  swc1  $f10, 0x10($sp)
  lwc1  $f4, 8($a0)
  lwc1  $f6, 8($a2)
  lwc1  $f10, 0xc($sp)
  sub.s $f8, $f6, $f4
  lwc1  $f4, 0x10($sp)
  swc1  $f8, 0x14($sp)
  lwc1  $f12, ($a1)
  lwc1  $f14, 4($a1)
  lwc1  $f2, 8($a1)
  mul.s $f6, $f12, $f10
  swc1  $f10, ($sp)
  mul.s $f8, $f14, $f4
  add.s $f6, $f6, $f8
  lwc1  $f8, 0x14($sp)
  mul.s $f10, $f8, $f2
  add.s $f0, $f10, $f6
  mtc1  $zero, $f10
  nop   
  c.lt.s $f10, $f0
  nop   
  bc1f  .L7F041158
   nop   
  mul.s $f6, $f12, $f12
  nop   
  mul.s $f10, $f14, $f14
  add.s $f6, $f6, $f10
  mul.s $f10, $f2, $f2
  add.s $f16, $f10, $f6
  lwc1  $f10, ($sp)
  mul.s $f6, $f10, $f10
  nop   
  mul.s $f10, $f4, $f4
  add.s $f4, $f6, $f10
  mul.s $f6, $f8, $f8
  lwc1  $f8, 0x24($sp)
  mul.s $f10, $f0, $f0
  add.s $f18, $f6, $f4
  mul.s $f6, $f8, $f8
  sub.s $f4, $f18, $f6
  mul.s $f8, $f4, $f16
  c.le.s $f8, $f10
  nop   
  bc1f  .L7F041158
   nop   
  b     .L7F041158
   li    $v0, 1
.L7F041158:
  jr    $ra
   addiu $sp, $sp, 0x18
");






asm(R"
glabel sub_GAME_7F041160
  addiu $sp, $sp, -0xa8
  sw    $ra, 0x44($sp)
  sw    $s7, 0x40($sp)
  sw    $s6, 0x3c($sp)
  sw    $s5, 0x38($sp)
  sw    $s4, 0x34($sp)
  sw    $s3, 0x30($sp)
  sw    $s2, 0x2c($sp)
  sw    $s1, 0x28($sp)
  sw    $s0, 0x24($sp)
  sw    $a3, 0xb4($sp)
  lw    $s7, 0x14($a0)
  sw    $zero, 0x9c($sp)
  sw    $zero, 0x64($sp)
  lbu   $t6, 3($a0)
  li    $at, 1
  move  $s1, $a1
  bne   $t6, $at, .L7F041210
   move  $s3, $a2
  addiu $a0, $a0, 0xd0
  lw    $a1, 0xc($s7)
  move  $a2, $s1
  jal   sub_GAME_7F0747D0
   move  $a3, $s3
  lw    $t7, 8($s7)
  move  $s0, $v0
  addiu $s4, $sp, 0x6c
  lw    $t8, ($t7)
  addiu $s5, $sp, 0x68
  blez  $v0, .L7F04126C
   sw    $t8, 0x9c($sp)
  addiu $s6, $sp, 0x64
  sw    $s6, 0x18($sp)
  move  $a0, $s7
  move  $a1, $t8
  move  $a2, $s1
  move  $a3, $s3
  sw    $s4, 0x10($sp)
  jal   sub_GAME_7F04D9B0
   sw    $s5, 0x14($sp)
  bnez  $v0, .L7F04126C
   nop   
  b     .L7F04126C
   move  $s0, $zero
.L7F041210:
  addiu $s6, $sp, 0x64
  addiu $s5, $sp, 0x68
  addiu $s4, $sp, 0x6c
  addiu $s2, $sp, 0x9c
  move  $a0, $s7
.L7F041224:
  move  $a1, $s1
  move  $a2, $s3
  jal   sub_GAME_7F0752FC
   move  $a3, $s2
  blez  $v0, .L7F041264
   move  $s0, $v0
  move  $a0, $s7
  lw    $a1, 0x9c($sp)
  move  $a2, $s1
  move  $a3, $s3
  sw    $s4, 0x10($sp)
  sw    $s5, 0x14($sp)
  jal   sub_GAME_7F04D9B0
   sw    $s6, 0x18($sp)
  bnez  $v0, .L7F04126C
   nop   
.L7F041264:
  bgtzl $s0, .L7F041224
   move  $a0, $s7
.L7F04126C:
  blez  $s0, .L7F0413D4
   move  $v0, $zero
  lwc1  $f4, 0x6c($sp)
  lw    $a1, 0xb4($sp)
  lw    $t9, 0xc($s7)
  lw    $t0, 0x68($sp)
  swc1  $f4, ($a1)
  lwc1  $f6, 0x70($sp)
  sll   $t1, $t0, 6
  addu  $s1, $t9, $t1
  swc1  $f6, 4($a1)
  lwc1  $f8, 0x74($sp)
  move  $a0, $s1
  jal   sub_GAME_7F058474
   swc1  $f8, 8($a1)
  jal   sub_GAME_7F078444
   nop   
  move  $a0, $v0
  jal   sub_GAME_7F058474
   lw    $a1, 0xb4($sp)
  lw    $s0, 0xb8($sp)
  lwc1  $f10, 0x78($sp)
  move  $a0, $s1
  move  $a1, $s0
  swc1  $f10, ($s0)
  lwc1  $f16, 0x7c($sp)
  swc1  $f16, 4($s0)
  lwc1  $f18, 0x80($sp)
  jal   sub_GAME_7F0583D8
   swc1  $f18, 8($s0)
  lwc1  $f2, ($s0)
  lwc1  $f4, ($s3)
  lwc1  $f12, 4($s0)
  lwc1  $f8, 4($s3)
  mul.s $f6, $f2, $f4
  lwc1  $f0, 8($s0)
  lwc1  $f18, 8($s3)
  mul.s $f10, $f12, $f8
  mtc1  $zero, $f14
  mul.s $f4, $f18, $f0
  add.s $f16, $f6, $f10
  add.s $f8, $f4, $f16
  c.lt.s $f14, $f8
  nop   
  bc1f  .L7F04133C
   nop   
  neg.s $f6, $f2
  neg.s $f10, $f12
  neg.s $f18, $f0
  swc1  $f6, ($s0)
  swc1  $f10, 4($s0)
  swc1  $f18, 8($s0)
.L7F04133C:
  jal   sub_GAME_7F078444
   nop   
  move  $a0, $v0
  jal   sub_GAME_7F0583D8
   move  $a1, $s0
  mtc1  $zero, $f14
  lwc1  $f4, ($s0)
  move  $a0, $s0
  addiu $a1, $s0, 4
  c.eq.s $f14, $f4
  nop   
  bc1f  .L7F04139C
   nop   
  lwc1  $f16, 4($s0)
  c.eq.s $f14, $f16
  nop   
  bc1f  .L7F04139C
   nop   
  lwc1  $f8, 8($s0)
  li    $at, 0x3F800000 # 1.000000
  c.eq.s $f14, $f8
  nop   
  bc1tl .L7F0413B0
   mtc1  $at, $f6
.L7F04139C:
  jal   guNormalize
   addiu $a2, $s0, 8
  b     .L7F0413BC
   lw    $t3, 0xbc($sp)
  mtc1  $at, $f6
.L7F0413B0:
  nop   
  swc1  $f6, 8($s0)
  lw    $t3, 0xbc($sp)
.L7F0413BC:
  li    $v0, 1
  sw    $s7, ($t3)
  lw    $t5, 0xc0($sp)
  lw    $t4, 0x64($sp)
  b     .L7F0413D4
   sw    $t4, ($t5)
.L7F0413D4:
  lw    $ra, 0x44($sp)
  lw    $s0, 0x24($sp)
  lw    $s1, 0x28($sp)
  lw    $s2, 0x2c($sp)
  lw    $s3, 0x30($sp)
  lw    $s4, 0x34($sp)
  lw    $s5, 0x38($sp)
  lw    $s6, 0x3c($sp)
  lw    $s7, 0x40($sp)
  jr    $ra
   addiu $sp, $sp, 0xa8
");






asm(R"
glabel sub_GAME_7F041400
  addiu $sp, $sp, -0xd8
  sw    $s5, 0x44($sp)
  sw    $s4, 0x40($sp)
  sdc1  $f20, 0x28($sp)
  li    $at, 0x3F800000 # 1.000000
  move  $s4, $a2
  move  $s5, $a1
  sw    $ra, 0x54($sp)
  sw    $a3, 0xe4($sp)
  mtc1  $at, $f20
  li    $t6, -1
  addiu $t7, $sp, 0xc8
  sw    $fp, 0x50($sp)
  sw    $s7, 0x4c($sp)
  sw    $s6, 0x48($sp)
  sw    $s3, 0x3c($sp)
  sw    $s2, 0x38($sp)
  sw    $s1, 0x34($sp)
  sw    $s0, 0x30($sp)
  sw    $a0, 0xd8($sp)
  sw    $t6, 0x94($sp)
  sw    $t7, 0x10($sp)
  addiu $a3, $sp, 0xcc
  addiu $a1, $sp, 0xd4
  jal   sub_GAME_7F03CC20
   addiu $a2, $sp, 0xd0
  lw    $t8, 0xd0($sp)
  lwc1  $f4, 0xcc($sp)
  blezl $t8, .L7F0417A8
   move  $v0, $zero
  lwc1  $f0, 4($s5)
  lwc1  $f8, 0xc8($sp)
  c.lt.s $f4, $f0
  nop   
  bc1fl .L7F0414A8
   c.lt.s $f0, $f8
  lwc1  $f6, 4($s4)
  c.lt.s $f4, $f6
  nop   
  bc1tl .L7F0417A8
   move  $v0, $zero
  c.lt.s $f0, $f8
.L7F0414A8:
  nop   
  bc1fl .L7F0414CC
   lwc1  $f16, ($s5)
  lwc1  $f10, 4($s4)
  c.lt.s $f10, $f8
  nop   
  bc1tl .L7F0417A8
   move  $v0, $zero
  lwc1  $f16, ($s5)
.L7F0414CC:
  lw    $t9, 0xd0($sp)
  move  $s0, $zero
  swc1  $f16, 0xa0($sp)
  lwc1  $f18, 8($s5)
  swc1  $f18, 0xa4($sp)
  lwc1  $f4, ($s4)
  swc1  $f4, 0x98($sp)
  lwc1  $f6, 8($s4)
  blez  $t9, .L7F0415FC
   swc1  $f6, 0x9c($sp)
  move  $s1, $zero
  addiu $fp, $sp, 0xb0
  addiu $s7, $sp, 0x98
  addiu $s6, $sp, 0xa0
  lw    $t0, 0xd0($sp)
.L7F041508:
  addiu $s3, $s0, 1
  lw    $t1, 0xd4($sp)
  div   $zero, $s3, $t0
  addu  $v1, $t1, $s1
  lwc1  $f10, ($v1)
  lwc1  $f12, ($s5)
  lwc1  $f14, 8($s5)
  lw    $a2, ($s4)
  lw    $a3, 8($s4)
  swc1  $f10, 0x10($sp)
  lwc1  $f8, 4($v1)
  mfhi  $v0
  sll   $t2, $v0, 3
  addu  $a0, $t1, $t2
  swc1  $f8, 0x14($sp)
  lwc1  $f16, ($a0)
  bnez  $t0, .L7F041554
   nop   
  break 7
.L7F041554:
  li    $at, -1
  bne   $t0, $at, .L7F04156C
   lui   $at, 0x8000
  bne   $s3, $at, .L7F04156C
   nop   
  break 6
.L7F04156C:
  swc1  $f16, 0x18($sp)
  lwc1  $f18, 4($a0)
  move  $s2, $v0
  jal   sub_GAME_7F0B0688
   swc1  $f18, 0x1c($sp)
  beql  $v0, $zero, .L7F0415E8
   lw    $t5, 0xd0($sp)
  lw    $t3, 0xd4($sp)
  sll   $t4, $s2, 3
  move  $a0, $s6
  addu  $v1, $t3, $s1
  lwc1  $f4, ($v1)
  addu  $v0, $t3, $t4
  move  $a1, $s7
  swc1  $f4, 0xb0($sp)
  lwc1  $f6, 4($v1)
  move  $a2, $fp
  addiu $a3, $sp, 0xa8
  swc1  $f6, 0xb4($sp)
  lwc1  $f10, ($v0)
  swc1  $f10, 0xa8($sp)
  lwc1  $f8, 4($v0)
  jal   sub_GAME_7F0B3200
   swc1  $f8, 0xac($sp)
  c.lt.s $f0, $f20
  nop   
  bc1fl .L7F0415E8
   lw    $t5, 0xd0($sp)
  mov.s $f20, $f0
  sw    $s0, 0x94($sp)
  lw    $t5, 0xd0($sp)
.L7F0415E8:
  move  $s0, $s3
  addiu $s1, $s1, 8
  slt   $at, $s3, $t5
  bnezl $at, .L7F041508
   lw    $t0, 0xd0($sp)
.L7F0415FC:
  lw    $t6, 0x94($sp)
  lw    $t7, 0xd4($sp)
  addiu $a0, $sp, 0x88
  blez  $t6, .L7F0417A4
   sll   $t8, $t6, 3
  lw    $t0, 0xd0($sp)
  addiu $t9, $t6, 1
  addu  $v0, $t7, $t8
  div   $zero, $t9, $t0
  mtc1  $zero, $f20
  lwc1  $f16, ($v0)
  mfhi  $t1
  swc1  $f20, 0x8c($sp)
  swc1  $f16, 0x88($sp)
  lwc1  $f18, 4($v0)
  sll   $t2, $t1, 3
  addu  $v1, $t7, $t2
  swc1  $f18, 0x90($sp)
  lwc1  $f4, ($v1)
  swc1  $f20, 0x80($sp)
  addiu $t3, $sp, 0x6c
  swc1  $f4, 0x7c($sp)
  lwc1  $f6, 4($v1)
  bnez  $t0, .L7F041664
   nop   
  break 7
.L7F041664:
  li    $at, -1
  bne   $t0, $at, .L7F04167C
   li    $at, 0x80000000 # -0.000000
  bne   $t9, $at, .L7F04167C
   nop   
  break 6
.L7F04167C:
  sw    $t3, 0x10($sp)
  addiu $a1, $sp, 0x7c
  move  $a2, $s5
  lw    $a3, 0xe4($sp)
  jal   sub_GAME_7F026130
   swc1  $f6, 0x84($sp)
  lwc1  $f10, 0x6c($sp)
  lwc1  $f8, ($s5)
  lw    $a1, 0xe4($sp)
  lwc1  $f6, 0x70($sp)
  sub.s $f16, $f10, $f8
  lwc1  $f10, 4($s5)
  lwc1  $f18, ($a1)
  lw    $v1, 0xf0($sp)
  sub.s $f8, $f6, $f10
  mul.s $f4, $f16, $f18
  lwc1  $f16, 4($a1)
  lwc1  $f10, 0x74($sp)
  lw    $v0, 0xe8($sp)
  mul.s $f18, $f8, $f16
  lwc1  $f8, 8($s5)
  lw    $a0, 0xec($sp)
  sub.s $f16, $f10, $f8
  lwc1  $f10, ($v1)
  add.s $f6, $f4, $f18
  lwc1  $f4, 8($a1)
  mul.s $f18, $f4, $f16
  add.s $f0, $f18, $f6
  c.lt.s $f0, $f10
  nop   
  bc1fl .L7F0417A8
   move  $v0, $zero
  swc1  $f0, ($v1)
  lwc1  $f8, 0x6c($sp)
  swc1  $f8, ($v0)
  lwc1  $f4, 0x70($sp)
  swc1  $f4, 4($v0)
  lwc1  $f16, 0x74($sp)
  swc1  $f16, 8($v0)
  lwc1  $f18, ($a1)
  swc1  $f20, 4($a0)
  neg.s $f6, $f18
  swc1  $f6, ($a0)
  lwc1  $f4, ($a0)
  lwc1  $f10, 8($a1)
  addiu $a1, $a0, 4
  c.eq.s $f20, $f4
  neg.s $f8, $f10
  bc1f  .L7F04175C
   swc1  $f8, 8($a0)
  lwc1  $f16, 8($a0)
  li    $at, 0x3F800000 # 1.000000
  c.eq.s $f20, $f16
  nop   
  bc1tl .L7F041770
   mtc1  $at, $f18
.L7F04175C:
  jal   guNormalize
   addiu $a2, $a0, 8
  b     .L7F04177C
   lw    $t4, 0xd8($sp)
  mtc1  $at, $f18
.L7F041770:
  nop   
  swc1  $f18, 8($a0)
  lw    $t4, 0xd8($sp)
.L7F04177C:
  lui   $at, %hi(D_80030B0C)
  li    $v0, 1
  sw    $t4, %lo(D_80030B0C)($at)
  lui   $at, %hi(bodypartshot)
  sw    $zero, %lo(bodypartshot)($at)
  lui   $at, %hi(objinst)
  sw    $zero, %lo(objinst)($at)
  lui   $at, %hi(dword_CODE_bss_80075B74)
  b     .L7F0417A8
   sw    $zero, %lo(dword_CODE_bss_80075B74)($at)
.L7F0417A4:
  move  $v0, $zero
.L7F0417A8:
  lw    $ra, 0x54($sp)
  ldc1  $f20, 0x28($sp)
  lw    $s0, 0x30($sp)
  lw    $s1, 0x34($sp)
  lw    $s2, 0x38($sp)
  lw    $s3, 0x3c($sp)
  lw    $s4, 0x40($sp)
  lw    $s5, 0x44($sp)
  lw    $s6, 0x48($sp)
  lw    $s7, 0x4c($sp)
  lw    $fp, 0x50($sp)
  jr    $ra
   addiu $sp, $sp, 0xd8
");






asm(R"
glabel sub_GAME_7F0417DC
  addiu $sp, $sp, -0x58
  sw    $s0, 0x28($sp)
  move  $s0, $a0
  sw    $ra, 0x34($sp)
  sw    $s2, 0x30($sp)
  sw    $s1, 0x2c($sp)
  sw    $a2, 0x60($sp)
  lw    $a0, 0x14($a0)
  move  $s1, $a1
  move  $s2, $a3
  jal   getinstsize
   sw    $a0, 0x54($sp)
  lw    $v0, 0x10($s0)
  mtc1  $zero, $f2
  lw    $t6, 0x1c($v0)
  bnezl $t6, .L7F041868
   neg.s $f8, $f0
  lwc1  $f4, 0x58($s0)
  lwc1  $f6, ($s1)
  lwc1  $f8, 0x5c($s0)
  lwc1  $f10, 4($s1)
  sub.s $f12, $f4, $f6
  lwc1  $f6, ($s2)
  lwc1  $f4, 8($s1)
  sub.s $f14, $f8, $f10
  lwc1  $f18, 0x60($s0)
  mul.s $f8, $f12, $f6
  lwc1  $f10, 4($s2)
  sub.s $f16, $f18, $f4
  lwc1  $f6, 8($s2)
  mul.s $f18, $f14, $f10
  add.s $f4, $f8, $f18
  mul.s $f10, $f6, $f16
  add.s $f2, $f10, $f4
  neg.s $f8, $f0
.L7F041868:
  lwc1  $f18, 0x68($sp)
  c.le.s $f8, $f2
  nop   
  bc1fl .L7F0419CC
   move  $v0, $zero
  add.s $f6, $f18, $f0
  c.le.s $f2, $f6
  nop   
  bc1fl .L7F0419CC
   move  $v0, $zero
  lbu   $t7, 1($v0)
  lw    $a1, 0x6c($sp)
  lw    $a2, 0x70($sp)
  andi  $t8, $t7, 2
  beqz  $t8, .L7F04194C
   lw    $a0, 0x54($sp)
  lw    $t9, 0x78($sp)
  lw    $t1, 0x80($sp)
  lw    $t2, 0x84($sp)
  move  $a0, $s0
  lw    $a3, 0x74($sp)
  sw    $t9, 0x10($sp)
  sw    $t1, 0x14($sp)
  jal   sub_GAME_7F041160
   sw    $t2, 0x18($sp)
  beqz  $v0, .L7F0419C8
   lw    $v1, 0x74($sp)
  lwc1  $f10, ($v1)
  lwc1  $f4, ($s1)
  lwc1  $f8, 4($v1)
  lwc1  $f18, 4($s1)
  sub.s $f12, $f10, $f4
  lwc1  $f4, ($s2)
  lwc1  $f10, 8($s1)
  sub.s $f14, $f8, $f18
  lwc1  $f6, 8($v1)
  mul.s $f8, $f12, $f4
  lwc1  $f18, 4($s2)
  sub.s $f16, $f6, $f10
  lwc1  $f4, 8($s2)
  mul.s $f6, $f14, $f18
  add.s $f10, $f8, $f6
  mul.s $f18, $f4, $f16
  mtc1  $zero, $f8
  lwc1  $f6, 0x68($sp)
  add.s $f2, $f18, $f10
  c.le.s $f8, $f2
  nop   
  bc1fl .L7F0419CC
   move  $v0, $zero
  c.le.s $f2, $f6
  lw    $t0, 0x7c($sp)
  li    $v0, 1
  bc1fl .L7F0419CC
   move  $v0, $zero
  b     .L7F0419CC
   swc1  $f2, ($t0)
.L7F04194C:
  jal   getinstsize
   sw    $v0, 0x3c($sp)
  mfc1  $a3, $f0
  move  $a0, $s1
  move  $a1, $s2
  jal   sub_GAME_7F041074
   addiu $a2, $s0, 0x58
  beqz  $v0, .L7F0419C8
   lw    $v1, 0x74($sp)
  lw    $t0, 0x7c($sp)
  lwc1  $f4, 0x68($sp)
  move  $a1, $s1
  move  $a3, $s2
  swc1  $f4, ($t0)
  lw    $t3, 0x78($sp)
  sw    $v1, 0x10($sp)
  lw    $a2, 0x60($sp)
  lw    $a0, 0x3c($sp)
  sw    $t0, 0x18($sp)
  jal   sub_GAME_7F041400
   sw    $t3, 0x14($sp)
  beqz  $v0, .L7F0419C8
   lw    $t4, 0x54($sp)
  lw    $t5, 0x80($sp)
  li    $v0, 1
  sw    $t4, ($t5)
  lw    $t6, 8($t4)
  lw    $t8, 0x84($sp)
  lw    $t7, ($t6)
  b     .L7F0419CC
   sw    $t7, ($t8)
.L7F0419C8:
  move  $v0, $zero
.L7F0419CC:
  lw    $ra, 0x34($sp)
  lw    $s0, 0x28($sp)
  lw    $s1, 0x2c($sp)
  lw    $s2, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x58
");






asm(R"
glabel sub_GAME_7F0419E4
  addiu $sp, $sp, -0x98
  sw    $ra, 0x64($sp)
  sw    $fp, 0x60($sp)
  sw    $s7, 0x5c($sp)
  sw    $s6, 0x58($sp)
  sw    $s5, 0x54($sp)
  sw    $s4, 0x50($sp)
  sw    $s3, 0x4c($sp)
  sw    $s2, 0x48($sp)
  sw    $s1, 0x44($sp)
  sw    $s0, 0x40($sp)
  sdc1  $f20, 0x38($sp)
  lw    $v1, 0x10($a0)
  lwc1  $f20, 0xa8($sp)
  lw    $s7, 0xac($sp)
  lw    $fp, 0xb0($sp)
  addiu $t6, $sp, 0x8c
  addiu $t7, $sp, 0x80
  addiu $t8, $sp, 0x7c
  addiu $t9, $sp, 0x78
  addiu $t0, $sp, 0x74
  move  $s0, $a0
  move  $s3, $a1
  move  $s4, $a2
  move  $s5, $a3
  move  $s6, $zero
  sw    $t0, 0x2c($sp)
  sw    $t9, 0x28($sp)
  sw    $t8, 0x24($sp)
  sw    $t7, 0x20($sp)
  sw    $t6, 0x1c($sp)
  sw    $v1, 0x6c($sp)
  swc1  $f20, 0x10($sp)
  sw    $s7, 0x14($sp)
  jal   sub_GAME_7F0417DC
   sw    $fp, 0x18($sp)
  beqz  $v0, .L7F041B08
   lw    $v1, 0x6c($sp)
  lw    $t1, 0xbc($sp)
  lwc1  $f4, 0x7c($sp)
  lw    $s1, 0xb4($sp)
  lwc1  $f6, ($t1)
  lw    $s2, 0xb8($sp)
  c.lt.s $f4, $f6
  nop   
  bc1fl .L7F041B0C
   lbu   $t6, 1($v1)
  swc1  $f4, ($t1)
  lwc1  $f8, 0x8c($sp)
  lui   $at, %hi(D_80030B0C)
  li    $t3, -1
  swc1  $f8, ($s1)
  lwc1  $f10, 0x90($sp)
  li    $s6, 1
  swc1  $f10, 4($s1)
  lwc1  $f16, 0x94($sp)
  swc1  $f16, 8($s1)
  lwc1  $f18, 0x80($sp)
  swc1  $f18, ($s2)
  lwc1  $f6, 0x84($sp)
  swc1  $f6, 4($s2)
  lwc1  $f4, 0x88($sp)
  swc1  $f4, 8($s2)
  lw    $t2, 0x10($s0)
  lw    $t4, 0x78($sp)
  lw    $t5, 0x74($sp)
  sw    $t2, %lo(D_80030B0C)($at)
  lui   $at, %hi(bodypartshot)
  sw    $t3, %lo(bodypartshot)($at)
  lui   $at, %hi(objinst)
  sw    $t4, %lo(objinst)($at)
  lui   $at, %hi(dword_CODE_bss_80075B74)
  sw    $t5, %lo(dword_CODE_bss_80075B74)($at)
.L7F041B08:
  lbu   $t6, 1($v1)
.L7F041B0C:
  lw    $s1, 0xb4($sp)
  lw    $s2, 0xb8($sp)
  andi  $t7, $t6, 2
  beql  $t7, $zero, .L7F041B84
   lw    $ra, 0x64($sp)
  lw    $s0, 0x20($v1)
  beql  $s0, $zero, .L7F041B84
   lw    $ra, 0x64($sp)
  lbu   $t8, 1($s0)
.L7F041B30:
  move  $a1, $s3
  move  $a2, $s4
  andi  $t9, $t8, 2
  beqz  $t9, .L7F041B74
   move  $a3, $s5
  lw    $a0, 4($s0)
  lw    $t0, 0xbc($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $fp, 0x18($sp)
  sw    $s7, 0x14($sp)
  swc1  $f20, 0x10($sp)
  jal   sub_GAME_7F0419E4
   sw    $t0, 0x24($sp)
  beql  $v0, $zero, .L7F041B78
   lw    $s0, 0x24($s0)
  li    $s6, 1
.L7F041B74:
  lw    $s0, 0x24($s0)
.L7F041B78:
  bnezl $s0, .L7F041B30
   lbu   $t8, 1($s0)
  lw    $ra, 0x64($sp)
.L7F041B84:
  move  $v0, $s6
  lw    $s6, 0x58($sp)
  ldc1  $f20, 0x38($sp)
  lw    $s0, 0x40($sp)
  lw    $s1, 0x44($sp)
  lw    $s2, 0x48($sp)
  lw    $s3, 0x4c($sp)
  lw    $s4, 0x50($sp)
  lw    $s5, 0x54($sp)
  lw    $s7, 0x5c($sp)
  lw    $fp, 0x60($sp)
  jr    $ra
   addiu $sp, $sp, 0x98
");






asm(R"
glabel sub_GAME_7F041BB8
  addiu $sp, $sp, -0x68
  sw    $a3, 0x74($sp)
  sw    $ra, 0x2c($sp)
  sw    $s2, 0x28($sp)
  sw    $s1, 0x24($sp)
  sw    $s0, 0x20($sp)
  sw    $a0, 0x68($sp)
  move  $a3, $a0
  lw    $s2, 0x18($a0)
  lw    $a0, 0x1c($a0)
  move  $s0, $a2
  move  $s1, $a1
  jal   getinstsize
   sw    $a3, 0x68($sp)
  lwc1  $f4, 8($s2)
  lwc1  $f6, ($s1)
  lwc1  $f8, 0xc($s2)
  lwc1  $f10, 4($s1)
  sub.s $f2, $f4, $f6
  lwc1  $f6, ($s0)
  lwc1  $f4, 8($s1)
  sub.s $f12, $f8, $f10
  lwc1  $f18, 0x10($s2)
  mul.s $f8, $f2, $f6
  lwc1  $f10, 4($s0)
  sub.s $f14, $f18, $f4
  lwc1  $f6, 8($s0)
  mul.s $f18, $f12, $f10
  add.s $f4, $f8, $f18
  mul.s $f10, $f6, $f14
  lwc1  $f18, 0x74($sp)
  neg.s $f8, $f0
  add.s $f16, $f10, $f4
  c.le.s $f8, $f16
  nop   
  bc1fl .L7F041DF4
   move  $v0, $zero
  add.s $f6, $f18, $f0
  c.le.s $f16, $f6
  nop   
  bc1fl .L7F041DF4
   move  $v0, $zero
  lbu   $t6, 1($s2)
  lw    $t8, 0x68($sp)
  addiu $a0, $sp, 0x38
  andi  $t7, $t6, 2
  beqz  $t7, .L7F041DF0
   addiu $a3, $sp, 0x40
  lw    $t9, 0x20($t8)
  addiu $t0, $sp, 0x3c
  sw    $t0, 0x10($sp)
  lw    $a1, 0x78($sp)
  lw    $a2, 0x7c($sp)
  jal   sub_GAME_7F06C010
   sw    $t9, 0x38($sp)
  blez  $v0, .L7F041DF0
   sw    $v0, 0x44($sp)
  lw    $a0, 0x40($sp)
  lw    $a1, 0x3c($sp)
  jal   sub_GAME_7F06C660
   move  $a2, $zero
  lw    $v1, 0x78($sp)
  lwc1  $f10, 0x30($v0)
  lw    $a3, 0x7c($sp)
  lwc1  $f4, ($v1)
  lwc1  $f8, 0x34($v0)
  lwc1  $f18, 4($v1)
  sub.s $f2, $f10, $f4
  lwc1  $f4, ($a3)
  lwc1  $f6, 0x38($v0)
  sub.s $f12, $f8, $f18
  lwc1  $f10, 8($v1)
  mul.s $f8, $f2, $f4
  lwc1  $f18, 4($a3)
  sub.s $f14, $f6, $f10
  lwc1  $f4, 8($a3)
  mul.s $f6, $f12, $f18
  lw    $a1, 0x88($sp)
  lw    $v0, 0x80($sp)
  mul.s $f18, $f4, $f14
  lw    $a0, 0x84($sp)
  add.s $f10, $f8, $f6
  lwc1  $f8, ($a1)
  add.s $f0, $f18, $f10
  c.lt.s $f0, $f8
  nop   
  bc1fl .L7F041DF4
   move  $v0, $zero
  swc1  $f0, ($a1)
  lwc1  $f6, ($s0)
  lwc1  $f18, ($s1)
  mtc1  $zero, $f2
  mul.s $f4, $f6, $f0
  addiu $a1, $a0, 4
  add.s $f10, $f4, $f18
  swc1  $f10, ($v0)
  lwc1  $f8, 4($s0)
  lwc1  $f4, 4($s1)
  mul.s $f6, $f8, $f0
  add.s $f18, $f6, $f4
  swc1  $f18, 4($v0)
  lwc1  $f10, 8($s0)
  lwc1  $f6, 8($s1)
  mul.s $f8, $f10, $f0
  add.s $f4, $f8, $f6
  swc1  $f4, 8($v0)
  lwc1  $f18, ($s0)
  swc1  $f2, 4($a0)
  neg.s $f10, $f18
  swc1  $f10, ($a0)
  lwc1  $f4, ($a0)
  lwc1  $f8, 8($s0)
  c.eq.s $f2, $f4
  neg.s $f6, $f8
  bc1f  .L7F041DA0
   swc1  $f6, 8($a0)
  lwc1  $f18, 8($a0)
  li    $at, 0x3F800000 # 1.000000
  c.eq.s $f2, $f18
  nop   
  bc1tl .L7F041DB4
   mtc1  $at, $f10
.L7F041DA0:
  jal   guNormalize
   addiu $a2, $a0, 8
  b     .L7F041DC0
   lw    $t1, 0x44($sp)
  mtc1  $at, $f10
.L7F041DB4:
  nop   
  swc1  $f10, 8($a0)
  lw    $t1, 0x44($sp)
.L7F041DC0:
  lui   $at, %hi(D_80030B0C)
  sw    $s2, %lo(D_80030B0C)($at)
  lw    $t2, 0x40($sp)
  lui   $at, %hi(bodypartshot)
  sw    $t1, %lo(bodypartshot)($at)
  lui   $at, %hi(objinst)
  lw    $t3, 0x3c($sp)
  sw    $t2, %lo(objinst)($at)
  lui   $at, %hi(dword_CODE_bss_80075B74)
  li    $v0, 1
  b     .L7F041DF4
   sw    $t3, %lo(dword_CODE_bss_80075B74)($at)
.L7F041DF0:
  move  $v0, $zero
.L7F041DF4:
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x20($sp)
  lw    $s1, 0x24($sp)
  lw    $s2, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x68
");






asm(R"
glabel sub_GAME_7F041E0C
  addiu $sp, $sp, -0xb8
  sw    $ra, 0x5c($sp)
  sw    $s4, 0x48($sp)
  sw    $s2, 0x40($sp)
  move  $s2, $a3
  move  $s4, $a1
  sw    $fp, 0x58($sp)
  sw    $s7, 0x54($sp)
  sw    $s6, 0x50($sp)
  sw    $s5, 0x4c($sp)
  sw    $s3, 0x44($sp)
  sw    $s1, 0x3c($sp)
  sw    $s0, 0x38($sp)
  sdc1  $f20, 0x30($sp)
  sw    $a0, 0xb8($sp)
  sw    $a2, 0xc0($sp)
  sw    $zero, 0xb4($sp)
  jal   get_ptr_for_players_tank
   sw    $zero, 0xa4($sp)
  lw    $v1, 0xc0($sp)
  sw    $v0, 0x74($sp)
  lwc1  $f6, ($s4)
  lwc1  $f4, ($v1)
  sub.s $f8, $f4, $f6
  swc1  $f8, 0x98($sp)
  lwc1  $f16, 4($s4)
  lwc1  $f10, 4($v1)
  sub.s $f18, $f10, $f16
  lwc1  $f10, 0x98($sp)
  swc1  $f18, 0x9c($sp)
  lwc1  $f6, 8($s4)
  lwc1  $f4, 8($v1)
  mul.s $f16, $f10, $f10
  lwc1  $f18, 0x9c($sp)
  sub.s $f8, $f4, $f6
  mul.s $f4, $f18, $f18
  swc1  $f8, 0xa0($sp)
  lwc1  $f8, 0xa0($sp)
  mul.s $f10, $f8, $f8
  add.s $f6, $f16, $f4
  jal   sqrtf
   add.s $f12, $f10, $f6
  mtc1  $zero, $f18
  mov.s $f20, $f0
  li    $at, 0x3F800000 # 1.000000
  c.eq.s $f0, $f18
  nop   
  bc1fl .L7F041EDC
   mtc1  $at, $f16
  b     .L7F042218
   move  $v0, $zero
  mtc1  $at, $f16
.L7F041EDC:
  lwc1  $f4, 0x98($sp)
  lwc1  $f10, 0x9c($sp)
  div.s $f0, $f16, $f20
  lwc1  $f18, 0xa0($sp)
  mul.s $f8, $f4, $f0
  nop   
  mul.s $f6, $f10, $f0
  nop   
  mul.s $f16, $f18, $f0
  swc1  $f8, 0x98($sp)
  swc1  $f6, 0x9c($sp)
  swc1  $f16, 0xa0($sp)
  lwc1  $f4, ($s4)
  swc1  $f4, 0x88($sp)
  lwc1  $f8, 4($s4)
  swc1  $f8, 0x8c($sp)
  lwc1  $f10, 8($s4)
  jal   get_BONDdata_field_10CC
   swc1  $f10, 0x90($sp)
  move  $a0, $v0
  jal   sub_GAME_7F058474
   addiu $a1, $sp, 0x88
  lwc1  $f6, 0x98($sp)
  lwc1  $f18, 0x9c($sp)
  lwc1  $f16, 0xa0($sp)
  swc1  $f6, 0x7c($sp)
  swc1  $f18, 0x80($sp)
  jal   get_BONDdata_field_10CC
   swc1  $f16, 0x84($sp)
  move  $a0, $v0
  jal   sub_GAME_7F0583D8
   addiu $a1, $sp, 0x7c
  beqz  $s2, .L7F0421C4
   swc1  $f20, 0xa8($sp)
  jal   sub_GAME_7F03E3FC
   lw    $a0, 0xd0($sp)
  lui   $s3, %hi(ptr_list_object_lookup_indices)
  lw    $s3, %lo(ptr_list_object_lookup_indices)($s3)
  addiu $fp, $sp, 0xa8
  addiu $s7, $sp, 0x98
  lh    $v0, ($s3)
  lw    $s6, 0xcc($sp)
  lw    $s5, 0xc8($sp)
  bltz  $v0, .L7F0421C4
   sll   $t6, $v0, 2
.L7F041F90:
  subu  $t6, $t6, $v0
  sll   $t6, $t6, 2
  lw    $t8, 0xb8($sp)
  addu  $t6, $t6, $v0
  lui   $t7, %hi(pos_data_entry) 
  addiu $t7, %lo(pos_data_entry) # addiu $t7, $t7, -0x63c8
  sll   $t6, $t6, 2
  addu  $s0, $t6, $t7
  beql  $s0, $t8, .L7F0421B8
   lh    $v0, 2($s3)
  lbu   $v0, ($s0)
  li    $at, 1
  beq   $v0, $at, .L7F041FD8
   li    $at, 4
  beq   $v0, $at, .L7F041FD8
   li    $at, 2
  bnel  $v0, $at, .L7F042094
   li    $at, 3
.L7F041FD8:
  lw    $s1, 4($s0)
  lw    $t9, 0x64($s1)
  andi  $t0, $t9, 8
  bnezl $t0, .L7F0421B8
   lh    $v0, 2($s3)
  lw    $t1, 0xc($s1)
  li    $at, 2
  sll   $t2, $t1, 6
  bltzl $t2, .L7F0421B8
   lh    $v0, 2($s3)
  bne   $v0, $at, .L7F042030
   andi  $t5, $s2, 1
  andi  $t3, $s2, 2
  bnezl $t3, .L7F04203C
   lw    $t6, 0x74($sp)
  jal   sub_GAME_7F03D9EC
   move  $a0, $s0
  and   $t4, $v0, $s2
  bnezl $t4, .L7F04203C
   lw    $t6, 0x74($sp)
  b     .L7F0421B8
   lh    $v0, 2($s3)
.L7F042030:
  beql  $t5, $zero, .L7F0421B8
   lh    $v0, 2($s3)
  lw    $t6, 0x74($sp)
.L7F04203C:
  move  $a0, $s1
  move  $a1, $s4
  bne   $s0, $t6, .L7F042058
   lw    $a2, 0xc0($sp)
  lbu   $t7, 2($s1)
  andi  $t8, $t7, 0x20
  bnez  $t8, .L7F0421B4
.L7F042058:
   addiu $t9, $sp, 0x88
  addiu $t0, $sp, 0x7c
  sw    $t0, 0x18($sp)
  sw    $t9, 0x14($sp)
  move  $a3, $s7
  swc1  $f20, 0x10($sp)
  sw    $s5, 0x1c($sp)
  sw    $s6, 0x20($sp)
  jal   sub_GAME_7F0419E4
   sw    $fp, 0x24($sp)
  beqz  $v0, .L7F0421B4
   li    $t1, 1
  b     .L7F0421B4
   sw    $t1, 0xa4($sp)
  li    $at, 3
.L7F042094:
  beq   $v0, $at, .L7F0420AC
   li    $at, 6
  bnel  $v0, $at, .L7F04215C
   li    $at, 6
  lw    $t2, 4($s0)
  beqz  $t2, .L7F042158
.L7F0420AC:
   li    $at, 6
  bne   $v0, $at, .L7F0420F0
   lw    $s1, 4($s0)
  jal   sub_GAME_7F09B15C
   move  $a0, $s0
  sll   $t3, $v0, 2
  lui   $t4, %hi(players_p1)
  addu  $t4, $t4, $t3
  lw    $t4, %lo(players_p1)($t4)
  andi  $t6, $s2, 4
  lw    $t5, 0xac($t4)
  beql  $t5, $zero, .L7F0421B8
   lh    $v0, 2($s3)
  bnezl $t6, .L7F04211C
   mfc1  $a3, $f20
  b     .L7F0421B8
   lh    $v0, 2($s3)
.L7F0420F0:
  li    $at, 3
  bnel  $v0, $at, .L7F04211C
   mfc1  $a3, $f20
  lhu   $t7, 0x12($s1)
  andi  $t9, $s2, 8
  andi  $t8, $t7, 0x100
  bnezl $t8, .L7F0421B8
   lh    $v0, 2($s3)
  beql  $t9, $zero, .L7F0421B8
   lh    $v0, 2($s3)
  mfc1  $a3, $f20
.L7F04211C:
  addiu $t0, $sp, 0x88
  addiu $t1, $sp, 0x7c
  sw    $t1, 0x14($sp)
  sw    $t0, 0x10($sp)
  move  $a0, $s1
  move  $a1, $s4
  move  $a2, $s7
  sw    $s5, 0x18($sp)
  sw    $s6, 0x1c($sp)
  jal   sub_GAME_7F041BB8
   sw    $fp, 0x20($sp)
  beqz  $v0, .L7F0421B4
   li    $t2, 1
  b     .L7F0421B4
   sw    $t2, 0xa4($sp)
.L7F042158:
  li    $at, 6
.L7F04215C:
  bnel  $v0, $at, .L7F0421B8
   lh    $v0, 2($s3)
  jal   sub_GAME_7F09B15C
   move  $a0, $s0
  sll   $t3, $v0, 2
  lui   $t4, %hi(players_p1)
  addu  $t4, $t4, $t3
  lw    $t4, %lo(players_p1)($t4)
  move  $a0, $s0
  move  $a1, $s4
  lw    $t5, 0xac($t4)
  lw    $a2, 0xc0($sp)
  move  $a3, $s7
  beql  $t5, $zero, .L7F0421B8
   lh    $v0, 2($s3)
  sw    $s5, 0x10($sp)
  sw    $s6, 0x14($sp)
  jal   sub_GAME_7F041400
   sw    $fp, 0x18($sp)
  beqz  $v0, .L7F0421B4
   li    $t6, 1
  sw    $t6, 0xa4($sp)
.L7F0421B4:
  lh    $v0, 2($s3)
.L7F0421B8:
  addiu $s3, $s3, 2
  bgezl $v0, .L7F041F90
   sll   $t6, $v0, 2
.L7F0421C4:
  lw    $t7, 0xa4($sp)
  lui   $v0, %hi(flt_CODE_bss_80075B78)
  addiu $v0, %lo(flt_CODE_bss_80075B78) # addiu $v0, $v0, 0x5b78
  beqz  $t7, .L7F042214
   lui   $v1, %hi(flt_CODE_bss_80075B88)
  lwc1  $f4, 0x98($sp)
  lwc1  $f8, 0x9c($sp)
  lwc1  $f10, 0xa0($sp)
  lwc1  $f6, 0x7c($sp)
  lwc1  $f18, 0x80($sp)
  lwc1  $f16, 0x84($sp)
  addiu $v1, %lo(flt_CODE_bss_80075B88) # addiu $v1, $v1, 0x5b88
  li    $t8, 1
  sw    $t8, 0xb4($sp)
  swc1  $f4, ($v0)
  swc1  $f8, 4($v0)
  swc1  $f10, 8($v0)
  swc1  $f6, ($v1)
  swc1  $f18, 4($v1)
  swc1  $f16, 8($v1)
.L7F042214:
  lw    $v0, 0xb4($sp)
.L7F042218:
  lw    $ra, 0x5c($sp)
  ldc1  $f20, 0x30($sp)
  lw    $s0, 0x38($sp)
  lw    $s1, 0x3c($sp)
  lw    $s2, 0x40($sp)
  lw    $s3, 0x44($sp)
  lw    $s4, 0x48($sp)
  lw    $s5, 0x4c($sp)
  lw    $s6, 0x50($sp)
  lw    $s7, 0x54($sp)
  lw    $fp, 0x58($sp)
  jr    $ra
   addiu $sp, $sp, 0xb8
");






asm(R"
.late_rodata
glabel D_80052A58
.word 0x3dcccccd /*0.1*/

.text
glabel handles_projectile_motion
  addiu $sp, $sp, -0x2b0
  sw    $ra, 0x3c($sp)
  sw    $s3, 0x38($sp)
  sw    $s2, 0x34($sp)
  sw    $s1, 0x30($sp)
  sw    $s0, 0x2c($sp)
  sdc1  $f20, 0x20($sp)
  lw    $v0, 0x10($a0)
  li    $t7, 1
  lui    $at, %hi(D_80030B0C)
  lw    $t6, 0x14($v0)
  sw    $t7, 0x2a4($sp)
  sw    $zero, %lo(D_80030B0C)($at)
  sw    $t6, 0x2a8($sp)
  lwc1  $f4, 0x58($a0)
  lwc1  $f0, ($a1)
  move  $s0, $a3
  move  $s1, $a1
  c.eq.s $f0, $f4
  move  $s2, $a0
  move  $s3, $a2
  bc1fl .L7F0422DC
   swc1  $f0, 0x268($sp)
  lwc1  $f6, 4($a1)
  lwc1  $f8, 0x5c($a0)
  c.eq.s $f6, $f8
  nop   
  bc1fl .L7F0422DC
   swc1  $f0, 0x268($sp)
  lwc1  $f10, 8($a1)
  lwc1  $f16, 0x60($a0)
  c.eq.s $f10, $f16
  nop   
  bc1tl .L7F0429EC
   lw    $ra, 0x3c($sp)
  swc1  $f0, 0x268($sp)
.L7F0422DC:
  lwc1  $f18, 4($s1)
  swc1  $f18, 0x26c($sp)
  lwc1  $f4, 8($s1)
  swc1  $f4, 0x270($sp)
  lw    $t8, 0x64($s2)
  andi  $t9, $t8, 0x80
  beql  $t9, $zero, .L7F0429EC
   lw    $ra, 0x3c($sp)
  lw    $t1, 0x6c($s2)
  addiu $a0, $s2, 0x58
  addiu $a1, $sp, 0x268
  lw    $t2, ($t1)
  addiu $a3, $sp, 0x74
  addiu $t4, $sp, 0x7c
  andi  $t3, $t2, 4
  beqz  $t3, .L7F0429E8
   addiu $t5, $sp, 0x260
  sw    $zero, 0x260($sp)
  lw    $a2, 0x6c($s2)
  li    $t6, 20
  sw    $t6, 0x18($sp)
  sw    $s1, 0x2b4($sp)
  sw    $a0, 0x48($sp)
  sw    $v0, 0x2ac($sp)
  sw    $t5, 0x14($sp)
  sw    $t4, 0x10($sp)
  jal   sub_GAME_7F0B4AB4
   addiu $a2, $a2, 0xcc
  lw    $v1, 0x260($sp)
  addiu $t8, $sp, 0x7c
  li    $a1, 100
  slti  $at, $v1, 0x15
  bnezl $at, .L7F04236C
   sll   $t7, $v1, 2
  li    $v1, 20
  sll   $t7, $v1, 2
.L7F04236C:
  addu  $a0, $t7, $t8
  jal   sub_GAME_7F0B8E98
   sw    $v1, 0x260($sp)
  lw    $v1, 0x260($sp)
  li    $t9, -1
  addiu $s1, $sp, 0x7c
  addu  $v1, $v1, $v0
  sll   $t1, $v1, 2
  addu  $t2, $sp, $t1
  sw    $t9, 0x7c($t2)
  lw    $t3, 0x7c($sp)
  sw    $v1, 0x260($sp)
  bltzl $t3, .L7F042618
   lw    $t5, 0x2a4($sp)
  mtc1  $zero, $f20
  lw    $a2, ($s1)
  lw    $a0, 0x48($sp)
.L7F0423B0:
  addiu $a1, $sp, 0x268
  jal   sub_GAME_7F0B7A78
   addiu $a3, $sp, 0x274
  beql  $v0, $zero, .L7F042608
   lw    $a2, 4($s1)
  jal   get_room_data_float2
   nop   
  lwc1  $f6, 0x274($sp)
  lwc1  $f10, 0x278($sp)
  lwc1  $f18, 0x27c($sp)
  mul.s $f8, $f6, $f0
  lwc1  $f6, 0x268($sp)
  mul.s $f16, $f10, $f0
  lwc1  $f10, 0x268($sp)
  mul.s $f4, $f18, $f0
  swc1  $f8, 0x274($sp)
  swc1  $f16, 0x278($sp)
  swc1  $f4, 0x27c($sp)
  lwc1  $f12, 0x58($s2)
  c.le.s $f12, $f6
  nop   
  bc1fl .L7F042430
   c.le.s $f10, $f12
  c.le.s $f8, $f6
  nop   
  bc1fl .L7F042430
   c.le.s $f10, $f12
  c.le.s $f12, $f8
  nop   
  bc1tl .L7F042460
   lwc1  $f2, 0x5c($s2)
  c.le.s $f10, $f12
.L7F042430:
  lwc1  $f16, 0x274($sp)
  bc1fl .L7F042608
   lw    $a2, 4($s1)
  c.le.s $f10, $f16
  nop   
  bc1fl .L7F042608
   lw    $a2, 4($s1)
  c.le.s $f16, $f12
  nop   
  bc1fl .L7F042608
   lw    $a2, 4($s1)
  lwc1  $f2, 0x5c($s2)
.L7F042460:
  lwc1  $f18, 0x26c($sp)
  lwc1  $f4, 0x278($sp)
  lwc1  $f6, 0x26c($sp)
  c.le.s $f2, $f18
  nop   
  bc1fl .L7F0424A0
   c.le.s $f6, $f2
  c.le.s $f4, $f18
  nop   
  bc1fl .L7F0424A0
   c.le.s $f6, $f2
  c.le.s $f2, $f4
  nop   
  bc1tl .L7F0424D0
   lwc1  $f0, 0x60($s2)
  c.le.s $f6, $f2
.L7F0424A0:
  lwc1  $f8, 0x278($sp)
  bc1fl .L7F042608
   lw    $a2, 4($s1)
  c.le.s $f6, $f8
  nop   
  bc1fl .L7F042608
   lw    $a2, 4($s1)
  c.le.s $f8, $f2
  nop   
  bc1fl .L7F042608
   lw    $a2, 4($s1)
  lwc1  $f0, 0x60($s2)
.L7F0424D0:
  lwc1  $f10, 0x270($sp)
  lwc1  $f16, 0x27c($sp)
  lwc1  $f18, 0x270($sp)
  c.le.s $f0, $f10
  nop   
  bc1fl .L7F042510
   c.le.s $f18, $f0
  c.le.s $f16, $f10
  nop   
  bc1fl .L7F042510
   c.le.s $f18, $f0
  c.le.s $f0, $f16
  nop   
  bc1tl .L7F042540
   lwc1  $f6, 0x274($sp)
  c.le.s $f18, $f0
.L7F042510:
  lwc1  $f4, 0x27c($sp)
  bc1fl .L7F042608
   lw    $a2, 4($s1)
  c.le.s $f18, $f4
  nop   
  bc1fl .L7F042608
   lw    $a2, 4($s1)
  c.le.s $f4, $f0
  nop   
  bc1fl .L7F042608
   lw    $a2, 4($s1)
  lwc1  $f6, 0x274($sp)
.L7F042540:
  lwc1  $f8, 0x278($sp)
  c.eq.s $f12, $f6
  nop   
  bc1fl .L7F042578
   lwc1  $f16, 0x274($sp)
  c.eq.s $f2, $f8
  lwc1  $f10, 0x27c($sp)
  bc1fl .L7F042578
   lwc1  $f16, 0x274($sp)
  c.eq.s $f0, $f10
  nop   
  bc1tl .L7F042608
   lw    $a2, 4($s1)
  lwc1  $f16, 0x274($sp)
.L7F042578:
  sw    $zero, 0x2a4($sp)
  move  $a0, $s0
  swc1  $f16, ($s3)
  lwc1  $f18, 0x278($sp)
  addiu $a1, $s0, 4
  swc1  $f18, 4($s3)
  lwc1  $f4, 0x27c($sp)
  swc1  $f4, 8($s3)
  lwc1  $f6, 0x280($sp)
  swc1  $f6, ($s0)
  lwc1  $f16, ($s0)
  lwc1  $f8, 0x284($sp)
  c.eq.s $f20, $f16
  swc1  $f8, 4($s0)
  lwc1  $f10, 0x288($sp)
  bc1f  .L7F0425E8
   swc1  $f10, 8($s0)
  lwc1  $f18, 4($s0)
  c.eq.s $f20, $f18
  nop   
  bc1f  .L7F0425E8
   nop   
  lwc1  $f4, 8($s0)
  li    $at, 0x3F800000 # 1.000000
  c.eq.s $f20, $f4
  nop   
  bc1tl .L7F0425FC
   mtc1  $at, $f6
.L7F0425E8:
  jal   guNormalize
   addiu $a2, $s0, 8
  b     .L7F042608
   lw    $a2, 4($s1)
  mtc1  $at, $f6
.L7F0425FC:
  nop   
  swc1  $f6, 8($s0)
  lw    $a2, 4($s1)
.L7F042608:
  addiu $s1, $s1, 4
  bgezl $a2, .L7F0423B0
   lw    $a0, 0x48($sp)
  lw    $t5, 0x2a4($sp)
.L7F042618:
  lw    $v0, 0x2b4($sp)
  bnezl $t5, .L7F0426FC
   addiu $t6, $sp, 0x7c
  lwc1  $f8, ($v0)
  lwc1  $f10, 0x58($s2)
  sub.s $f16, $f8, $f10
  swc1  $f16, 0x64($sp)
  lwc1  $f4, 0x5c($s2)
  lwc1  $f18, 4($v0)
  sub.s $f6, $f18, $f4
  lwc1  $f18, 0x64($sp)
  swc1  $f6, 0x68($sp)
  lwc1  $f10, 0x60($s2)
  lwc1  $f8, 8($v0)
  mul.s $f4, $f18, $f18
  lwc1  $f6, 0x68($sp)
  sub.s $f16, $f8, $f10
  mul.s $f8, $f6, $f6
  swc1  $f16, 0x6c($sp)
  lwc1  $f16, 0x6c($sp)
  mul.s $f18, $f16, $f16
  add.s $f10, $f4, $f8
  jal   sqrtf
   add.s $f12, $f18, $f10
  lui    $at, %hi(D_80052A58) # -0.000000
  lwc1  $f12, %lo(D_80052A58)($at)
  li    $at, 0x3F000000 # 0.500000
  lwc1  $f4, 0x64($sp)
  c.lt.s $f12, $f0
  nop   
  bc1fl .L7F0426A4
   mtc1  $at, $f2
  b     .L7F0426A8
   div.s $f2, $f12, $f0
  mtc1  $at, $f2
.L7F0426A4:
  nop   
.L7F0426A8:
  mul.s $f8, $f2, $f4
  lwc1  $f6, ($s3)
  lwc1  $f18, 4($s3)
  sub.s $f16, $f6, $f8
  lwc1  $f8, 8($s3)
  swc1  $f16, ($s3)
  lwc1  $f10, 0x68($sp)
  mul.s $f4, $f2, $f10
  sub.s $f6, $f18, $f4
  lwc1  $f4, ($s3)
  swc1  $f6, 4($s3)
  lwc1  $f16, 0x6c($sp)
  mul.s $f10, $f2, $f16
  sub.s $f18, $f8, $f10
  swc1  $f18, 8($s3)
  swc1  $f4, 0x268($sp)
  lwc1  $f6, 4($s3)
  swc1  $f6, 0x26c($sp)
  lwc1  $f16, 8($s3)
  swc1  $f16, 0x270($sp)
  addiu $t6, $sp, 0x7c
.L7F0426FC:
  sw    $t6, 0x18($sp)
  lw    $a0, 0x2ac($sp)
  lw    $a1, 0x48($sp)
  addiu $a2, $sp, 0x268
  li    $a3, 31
  sw    $s3, 0x10($sp)
  jal   sub_GAME_7F041E0C
   sw    $s0, 0x14($sp)
  bnez  $v0, .L7F0427F8
   lw    $t3, 0x2c4($sp)
  lw    $t7, 0x2a4($sp)
  lw    $t8, 0x2c0($sp)
  lw    $t5, 0x2a4($sp)
  bnezl $t7, .L7F04278C
   li    $s0, 1
  beql  $t8, $zero, .L7F04278C
   li    $s0, 1
  lw    $t1, 0x2c4($sp)
  li    $t9, 2
  sw    $t9, 0x2a4($sp)
  bnez  $t1, .L7F042780
   lw    $a0, 0x48($sp)
  lw    $a2, 0x6c($s2)
  addiu $t2, $sp, 0x7c
  addiu $t3, $sp, 0x260
  li    $t4, 20
  sw    $t4, 0x18($sp)
  sw    $t3, 0x14($sp)
  sw    $t2, 0x10($sp)
  move  $a1, $s3
  addiu $a3, $sp, 0x74
  jal   sub_GAME_7F0B4AB4
   addiu $a2, $a2, 0xcc
.L7F042780:
  b     .L7F04286C
   lw    $t1, 0x2a4($sp)
  li    $s0, 1
.L7F04278C:
  beq   $t5, $s0, .L7F04279C
   lw    $t6, 0x2c4($sp)
  bnezl $t6, .L7F04286C
   lw    $t1, 0x2a4($sp)
.L7F04279C:
  lw    $t7, 0x2a4($sp)
  lw    $a0, 0x48($sp)
  addiu $a1, $sp, 0x268
  beq   $t7, $s0, .L7F0427D4
   addiu $a3, $sp, 0x74
  lw    $a2, 0x6c($s2)
  addiu $t8, $sp, 0x7c
  addiu $t9, $sp, 0x260
  li    $t1, 20
  sw    $t1, 0x18($sp)
  sw    $t9, 0x14($sp)
  sw    $t8, 0x10($sp)
  jal   sub_GAME_7F0B4AB4
   addiu $a2, $a2, 0xcc
.L7F0427D4:
  lwc1  $f8, 0x268($sp)
  swc1  $f8, 0x58($s2)
  lwc1  $f10, 0x270($sp)
  swc1  $f10, 0x60($s2)
  lw    $t2, 0x2ac($sp)
  lwc1  $f0, 0x26c($sp)
  swc1  $f0, 0xc($t2)
  b     .L7F042868
   swc1  $f0, 0x5c($s2)
.L7F0427F8:
  bnez  $t3, .L7F042868
   addiu $a1, $sp, 0x268
  lwc1  $f18, 0x58($s2)
  addiu $t4, $sp, 0x7c
  addiu $t5, $sp, 0x260
  swc1  $f18, 0x268($sp)
  lwc1  $f4, 0x60($s2)
  li    $t6, 20
  lw    $a0, 0x48($sp)
  swc1  $f4, 0x270($sp)
  lw    $a2, 0x6c($s2)
  sw    $t6, 0x18($sp)
  sw    $t5, 0x14($sp)
  sw    $t4, 0x10($sp)
  addiu $a3, $sp, 0x74
  jal   sub_GAME_7F0B4AB4
   addiu $a2, $a2, 0xcc
  lwc1  $f0, 0x26c($sp)
  lw    $t7, 0x2ac($sp)
  li    $t9, 2
  swc1  $f0, 0xc($t7)
  swc1  $f0, 0x5c($s2)
  lw    $t8, 0x2c0($sp)
  beql  $t8, $zero, .L7F042868
   sw    $zero, 0x2a4($sp)
  b     .L7F042868
   sw    $t9, 0x2a4($sp)
  sw    $zero, 0x2a4($sp)
.L7F042868:
  lw    $t1, 0x2a4($sp)
.L7F04286C:
  li    $s0, 1
  lw    $t2, 0x2c4($sp)
  beql  $t1, $s0, .L7F042888
   lw    $t3, 0x6c($s2)
  bnezl $t2, .L7F0429EC
   lw    $ra, 0x3c($sp)
  lw    $t3, 0x6c($s2)
.L7F042888:
  move  $t0, $zero
  lw    $v0, ($t3)
  andi  $t4, $v0, 8
  bnez  $t4, .L7F042938
   move  $v0, $t4
  lw    $v0, 0x2ac($sp)
  addiu $a0, $sp, 0x2a8
  lw    $t5, 0x14($v0)
  sw    $t5, 0x2a8($sp)
  lwc1  $f6, 0x60($s2)
  lw    $a3, 0x58($s2)
  lw    $a2, 0x10($v0)
  lw    $a1, 8($v0)
  sw    $zero, 0x264($sp)
  jal   sub_GAME_7F0B0BE4
   swc1  $f6, 0x10($sp)
  bne   $v0, $s0, .L7F042908
   lw    $t0, 0x264($sp)
  lw    $t6, 0x2a8($sp)
  lw    $v1, 0x2ac($sp)
  beql  $t6, $zero, .L7F04290C
   lw    $v1, 0x6c($s2)
  sw    $t6, 0x14($v1)
  lwc1  $f16, 0x58($s2)
  swc1  $f16, 8($v1)
  lwc1  $f8, 0x60($s2)
  swc1  $f8, 0x10($v1)
  lw    $t7, 0x6c($s2)
  lw    $v0, ($t7)
  andi  $t8, $v0, 8
  b     .L7F042938
   move  $v0, $t8
.L7F042908:
  lw    $v1, 0x6c($s2)
.L7F04290C:
  lw    $t9, ($v1)
  ori   $t1, $t9, 8
  sw    $t1, ($v1)
  lw    $t2, 0x2ac($sp)
  lbu   $t3, 1($t2)
  ori   $t4, $t3, 8
  sb    $t4, 1($t2)
  lw    $t5, 0x6c($s2)
  lw    $v0, ($t5)
  andi  $t6, $v0, 8
  move  $v0, $t6
.L7F042938:
  beqz  $v0, .L7F042994
   lw    $a0, 0x48($sp)
  addiu $a1, $sp, 0x74
  move  $a2, $zero
  jal   sub_GAME_7F0AF20C
   sw    $t0, 0x264($sp)
  lw    $t0, 0x264($sp)
  beqz  $v0, .L7F042994
   sw    $v0, 0x2a8($sp)
  lw    $a0, 0x2ac($sp)
  li    $at, -9
  sw    $v0, 0x14($a0)
  lwc1  $f10, 0x58($s2)
  swc1  $f10, 8($a0)
  lwc1  $f18, 0x60($s2)
  swc1  $f18, 0x10($a0)
  lw    $v1, 0x6c($s2)
  lw    $t7, ($v1)
  and   $t8, $t7, $at
  sw    $t8, ($v1)
  lbu   $t9, 1($a0)
  and   $t1, $t9, $at
  sb    $t1, 1($a0)
.L7F042994:
  lbu   $t3, 0x74($sp)
  li    $a0, 255
  addiu $t4, $sp, 0x74
  beq   $a0, $t3, .L7F0429D8
   addu  $v0, $t0, $t4
  lbu   $v1, ($v0)
  li    $a1, 7
  lw    $t2, 0x6c($s2)
.L7F0429B4:
  addiu $v0, $v0, 1
  addu  $t5, $t2, $t0
  sb    $v1, 0xcc($t5)
  lbu   $v1, ($v0)
  addiu $t0, $t0, 1
  beql  $a0, $v1, .L7F0429DC
   lw    $t7, 0x6c($s2)
  bnel  $t0, $a1, .L7F0429B4
   lw    $t2, 0x6c($s2)
.L7F0429D8:
  lw    $t7, 0x6c($s2)
.L7F0429DC:
  li    $t6, 255
  addu  $t8, $t7, $t0
  sb    $t6, 0xcc($t8)
.L7F0429E8:
  lw    $ra, 0x3c($sp)
.L7F0429EC:
  lw    $v0, 0x2a4($sp)
  ldc1  $f20, 0x20($sp)
  lw    $s0, 0x2c($sp)
  lw    $s1, 0x30($sp)
  lw    $s2, 0x34($sp)
  lw    $s3, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x2b0
");






asm(R"
.late_rodata
glabel D_80052A5C
.word 0x3f7d70a4 /*0.99000001*/

.text
glabel sub_GAME_7F042A0C
  addiu $sp, $sp, -0xc0
  sw    $ra, 0x34($sp)
  sw    $s0, 0x30($sp)
  sw    $a2, 0xc8($sp)
  sw    $a3, 0xcc($sp)
  lw    $s0, 0x10($a0)
  lw    $t6, 0x14($s0)
  sw    $a1, 0xc4($sp)
  sw    $a0, 0xc0($sp)
  jal   if_a0_plus_3_is_4_then_10_else_20
   sw    $t6, 0xb8($sp)
  lw    $a1, 0xc4($sp)
  li    $t7, 1
  lui    $at, %hi(D_80030B0C)
  swc1  $f0, 0xb4($sp)
  sw    $t7, 0xb0($sp)
  sw    $zero, %lo(D_80030B0C)($at)
  lwc1  $f4, 8($s0)
  lwc1  $f2, ($a1)
  c.eq.s $f2, $f4
  nop   
  bc1fl .L7F042A9C
   swc1  $f2, 0x98($sp)
  lwc1  $f6, 4($a1)
  lwc1  $f8, 0xc($s0)
  c.eq.s $f6, $f8
  nop   
  bc1fl .L7F042A9C
   swc1  $f2, 0x98($sp)
  lwc1  $f10, 8($a1)
  lwc1  $f16, 0x10($s0)
  c.eq.s $f10, $f16
  nop   
  bc1tl .L7F042EA4
   lw    $ra, 0x34($sp)
  swc1  $f2, 0x98($sp)
.L7F042A9C:
  lwc1  $f18, 4($a1)
  lw    $t8, 0xc0($sp)
  swc1  $f18, 0x9c($sp)
  lwc1  $f4, 8($a1)
  swc1  $f4, 0xa0($sp)
  lw    $t9, 0x64($t8)
  andi  $t0, $t9, 0x80
  beql  $t0, $zero, .L7F042EA4
   lw    $ra, 0x34($sp)
  lw    $a0, 0x14($s0)
  lw    $a1, 8($s0)
  jal   sub_GAME_7F0B2970
   lw    $a2, 0x10($s0)
  lw    $t1, 0xc0($sp)
  lwc1  $f10, 0x9c($sp)
  lw    $t2, 0x6c($t1)
  lw    $t3, ($t2)
  andi  $t4, $t3, 0x40
  bnezl $t4, .L7F042B08
   lwc1  $f2, 0xc($s0)
  mtc1  $zero, $f18
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f16
  swc1  $f18, 0x90($sp)
  b     .L7F042B40
   swc1  $f16, 0x8c($sp)
  lwc1  $f2, 0xc($s0)
.L7F042B08:
  lwc1  $f4, 0x9c($sp)
  c.lt.s $f10, $f2
  nop   
  bc1fl .L7F042B34
   sub.s $f6, $f4, $f0
  sub.s $f16, $f2, $f0
  sub.s $f18, $f10, $f0
  swc1  $f16, 0x90($sp)
  b     .L7F042B40
   swc1  $f18, 0x8c($sp)
  sub.s $f6, $f4, $f0
.L7F042B34:
  sub.s $f8, $f2, $f0
  swc1  $f6, 0x90($sp)
  swc1  $f8, 0x8c($sp)
.L7F042B40:
  jal   sub_GAME_7F0B1CC4
   nop   
  lw    $a1, 8($s0)
  lw    $a2, 0x10($s0)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  lwc1  $f16, 0xa0($sp)
  lwc1  $f10, 0x90($sp)
  lwc1  $f18, 0x8c($sp)
  mtc1  $zero, $f4
  li    $t5, 31
  sw    $t5, 0x14($sp)
  addiu $a0, $sp, 0xb8
  lw    $a3, 0x98($sp)
  swc1  $f16, 0x10($sp)
  swc1  $f6, 0x24($sp)
  swc1  $f10, 0x18($sp)
  swc1  $f18, 0x1c($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f4, 0x20($sp)
  beqz  $v0, .L7F042C08
   lw    $t6, 0xb8($sp)
  beqz  $t6, .L7F042C08
   addiu $a0, $sp, 0xb8
  lwc1  $f8, 0x90($sp)
  lwc1  $f16, 0x8c($sp)
  li    $t7, 31
  sw    $t7, 0x10($sp)
  lw    $a1, 0x98($sp)
  lw    $a2, 0xa0($sp)
  lw    $a3, 0xb4($sp)
  swc1  $f8, 0x14($sp)
  jal   sub_GAME_7F0B18B8
   swc1  $f16, 0x18($sp)
  bgez  $v0, .L7F042C08
   lwc1  $f10, 0x98($sp)
  lw    $v0, 0xc0($sp)
  swc1  $f10, 0x58($v0)
  lwc1  $f18, 0xa0($sp)
  swc1  $f18, 0x60($v0)
  lw    $t8, 0xb8($sp)
  sw    $t8, 0x14($s0)
  lwc1  $f4, 0x98($sp)
  swc1  $f4, 8($s0)
  lwc1  $f6, 0xa0($sp)
  swc1  $f6, 0x10($s0)
  lwc1  $f0, 0x9c($sp)
  swc1  $f0, 0xc($s0)
  b     .L7F042EA0
   swc1  $f0, 0x5c($v0)
.L7F042C08:
  addiu $a0, $sp, 0x80
  jal   sub_GAME_7F0B28B0
   addiu $a1, $sp, 0x74
  lwc1  $f8, 0x7c($sp)
  lwc1  $f16, 0x88($sp)
  lw    $a0, 0xcc($sp)
  mtc1  $zero, $f2
  sub.s $f10, $f8, $f16
  addiu $a1, $a0, 4
  swc1  $f2, 4($a0)
  swc1  $f10, ($a0)
  lwc1  $f8, ($a0)
  lwc1  $f4, 0x74($sp)
  lwc1  $f18, 0x80($sp)
  c.eq.s $f2, $f8
  sub.s $f6, $f18, $f4
  bc1f  .L7F042C68
   swc1  $f6, 8($a0)
  lwc1  $f16, 8($a0)
  li    $at, 0x3F800000 # 1.000000
  c.eq.s $f2, $f16
  nop   
  bc1tl .L7F042C7C
   mtc1  $at, $f10
.L7F042C68:
  jal   guNormalize
   addiu $a2, $a0, 8
  b     .L7F042C88
   lwc1  $f0, 8($s0)
  mtc1  $at, $f10
.L7F042C7C:
  nop   
  swc1  $f10, 8($a0)
  lwc1  $f0, 8($s0)
.L7F042C88:
  lwc1  $f18, 0x98($sp)
  lwc1  $f4, 0x9c($sp)
  lwc1  $f10, 0x98($sp)
  c.eq.s $f18, $f0
  nop   
  bc1fl .L7F042CDC
   sub.s $f18, $f10, $f0
  lwc1  $f6, 0xc($s0)
  lwc1  $f8, 0xa0($sp)
  c.eq.s $f4, $f6
  nop   
  bc1fl .L7F042CDC
   sub.s $f18, $f10, $f0
  lwc1  $f16, 0x10($s0)
  lw    $v0, 0xc8($sp)
  lwc1  $f18, 0x98($sp)
  c.eq.s $f8, $f16
  nop   
  bc1tl .L7F042E7C
   swc1  $f18, ($v0)
  sub.s $f18, $f10, $f0
.L7F042CDC:
  lwc1  $f4, 0x9c($sp)
  lwc1  $f16, 0xa0($sp)
  addiu $a0, $s0, 8
  swc1  $f18, 0xa4($sp)
  lwc1  $f6, 0xc($s0)
  addiu $a1, $sp, 0xa4
  lw    $a2, 0xc8($sp)
  sub.s $f8, $f4, $f6
  swc1  $f8, 0xa8($sp)
  lwc1  $f10, 0x10($s0)
  sub.s $f18, $f16, $f10
  jal   sub_GAME_7F02624C
   swc1  $f18, 0xac($sp)
  lwc1  $f4, 0xb4($sp)
  lwc1  $f16, 0x80($sp)
  lwc1  $f10, 0x88($sp)
  swc1  $f4, 0x5c($sp)
  lwc1  $f6, 8($s0)
  lwc1  $f18, 0x74($sp)
  lwc1  $f4, 0x7c($sp)
  swc1  $f6, 0x60($sp)
  lwc1  $f8, 0x10($s0)
  swc1  $f16, 0x54($sp)
  swc1  $f10, 0x58($sp)
  swc1  $f18, 0x4c($sp)
  swc1  $f4, 0x50($sp)
  swc1  $f8, 0x64($sp)
  lwc1  $f8, 8($s0)
  lwc1  $f6, 0x98($sp)
  lwc1  $f10, 0xa0($sp)
  addiu $a0, $sp, 0x5c
  sub.s $f16, $f6, $f8
  addiu $a1, $sp, 0x54
  addiu $a2, $sp, 0x4c
  addiu $a3, $sp, 0x44
  swc1  $f16, 0x44($sp)
  lwc1  $f18, 0x10($s0)
  sub.s $f4, $f10, $f18
  jal   sub_GAME_7F0B33DC
   swc1  $f4, 0x48($sp)
  lwc1  $f8, 0x44($sp)
  lui   $at, %hi(D_80052A5C)
  lwc1  $f2, %lo(D_80052A5C)($at)
  mul.s $f16, $f8, $f0
  lw    $t9, 0x14($s0)
  lwc1  $f4, 0x9c($sp)
  li    $at, 0x3F800000 # 1.000000
  sw    $t9, 0xb8($sp)
  lwc1  $f6, 8($s0)
  swc1  $f4, 0x6c($sp)
  mul.s $f10, $f16, $f2
  lwc1  $f16, 0x48($sp)
  li    $t0, 31
  addiu $a0, $sp, 0xb8
  add.s $f18, $f6, $f10
  mul.s $f6, $f16, $f0
  lwc1  $f16, 0x90($sp)
  swc1  $f18, 0x68($sp)
  lwc1  $f8, 0x10($s0)
  lw    $a3, 0x68($sp)
  mul.s $f10, $f6, $f2
  lwc1  $f6, 0x8c($sp)
  add.s $f18, $f8, $f10
  mtc1  $at, $f10
  mtc1  $zero, $f8
  swc1  $f18, 0x70($sp)
  lw    $a2, 0x10($s0)
  lw    $a1, 8($s0)
  lwc1  $f4, 0x70($sp)
  sw    $t0, 0x14($sp)
  swc1  $f16, 0x18($sp)
  swc1  $f6, 0x1c($sp)
  swc1  $f10, 0x24($sp)
  swc1  $f8, 0x20($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f4, 0x10($sp)
  beqz  $v0, .L7F042E8C
   lw    $t1, 0xb8($sp)
  beqz  $t1, .L7F042E8C
   addiu $a0, $sp, 0xb8
  lwc1  $f18, 0x90($sp)
  lwc1  $f4, 0x8c($sp)
  li    $t2, 31
  sw    $t2, 0x10($sp)
  lw    $a1, 0x68($sp)
  lw    $a2, 0x70($sp)
  lw    $a3, 0xb4($sp)
  swc1  $f18, 0x14($sp)
  jal   sub_GAME_7F0B18B8
   swc1  $f4, 0x18($sp)
  bgez  $v0, .L7F042E8C
   lwc1  $f16, 0x68($sp)
  lw    $t3, 0xc0($sp)
  swc1  $f16, 0x58($t3)
  lwc1  $f6, 0x70($sp)
  swc1  $f6, 0x60($t3)
  lw    $t4, 0xb8($sp)
  sw    $t4, 0x14($s0)
  lwc1  $f8, 0x68($sp)
  swc1  $f8, 8($s0)
  lwc1  $f10, 0x70($sp)
  b     .L7F042E8C
   swc1  $f10, 0x10($s0)
  swc1  $f18, ($v0)
.L7F042E7C:
  lwc1  $f4, 0x9c($sp)
  swc1  $f4, 4($v0)
  lwc1  $f16, 0xa0($sp)
  swc1  $f16, 8($v0)
.L7F042E8C:
  lwc1  $f0, 0x6c($sp)
  swc1  $f0, 0xc($s0)
  lw    $t5, 0xc0($sp)
  swc1  $f0, 0x5c($t5)
  sw    $zero, 0xb0($sp)
.L7F042EA0:
  lw    $ra, 0x34($sp)
.L7F042EA4:
  lw    $v0, 0xb0($sp)
  lw    $s0, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0xc0
");






asm(R"
glabel sub_GAME_7F042EB4
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  lw    $t6, 0x64($a0)
  lw    $t3, 0x30($sp)
  andi  $t7, $t6, 0x80
  beqz  $t7, .L7F042F00
   nop   
  lw    $t8, 0x6c($a0)
  lw    $t1, 0x30($sp)
  lw    $t9, ($t8)
  andi  $t0, $t9, 4
  beqz  $t0, .L7F042F00
   nop   
  lw    $t2, 0x34($sp)
  sw    $t1, 0x10($sp)
  jal   handles_projectile_motion
   sw    $t2, 0x14($sp)
  b     .L7F042F0C
   lw    $ra, 0x1c($sp)
.L7F042F00:
  jal   sub_GAME_7F042A0C
   sw    $t3, 0x10($sp)
  lw    $ra, 0x1c($sp)
.L7F042F0C:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");






asm(R"
glabel sub_GAME_7F042F18
  addiu $sp, $sp, -0x28
  lui   $v1, %hi(clock_timer)
  addiu $v1, %lo(clock_timer) # addiu $v1, $v1, -0x7c8c
  lw    $t6, ($v1)
  sdc1  $f20, 8($sp)
  mtc1  $a3, $f20
  sdc1  $f26, 0x20($sp)
  sdc1  $f24, 0x18($sp)
  sdc1  $f22, 0x10($sp)
  mtc1  $a1, $f14
  lwc1  $f0, ($a2)
  blez  $t6, .L7F0430F0
   move  $v0, $zero
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f26
  mtc1  $zero, $f24
  lwc1  $f18, 0x3c($sp)
  lwc1  $f2, 0x38($sp)
  lwc1  $f16, ($a0)
.L7F042F64:
  sub.s $f12, $f14, $f16
  c.lt.s $f24, $f12
  nop   
  bc1fl .L7F04302C
   c.lt.s $f0, $f24
  c.lt.s $f24, $f0
  nop   
  bc1fl .L7F042FC8
   c.lt.s $f0, $f18
  mul.s $f4, $f0, $f0
  nop   
  mul.s $f6, $f4, $f26
  div.s $f8, $f6, $f2
  c.le.s $f12, $f8
  nop   
  bc1f  .L7F042FC4
   nop   
  sub.s $f0, $f0, $f2
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F043008
   c.le.s $f12, $f0
  b     .L7F043004
   mov.s $f0, $f2
.L7F042FC4:
  c.lt.s $f0, $f18
.L7F042FC8:
  nop   
  bc1fl .L7F043008
   c.le.s $f12, $f0
  c.lt.s $f0, $f24
  nop   
  bc1fl .L7F042FF0
   add.s $f0, $f0, $f20
  b     .L7F042FF0
   add.s $f0, $f0, $f2
  add.s $f0, $f0, $f20
.L7F042FF0:
  c.lt.s $f18, $f0
  nop   
  bc1fl .L7F043008
   c.le.s $f12, $f0
  mov.s $f0, $f18
.L7F043004:
  c.le.s $f12, $f0
.L7F043008:
  nop   
  bc1fl .L7F043020
   add.s $f10, $f16, $f0
  b     .L7F0430F0
   swc1  $f14, ($a0)
  add.s $f10, $f16, $f0
.L7F043020:
  b     .L7F0430DC
   swc1  $f10, ($a0)
  c.lt.s $f0, $f24
.L7F04302C:
  nop   
  bc1fl .L7F04307C
   neg.s $f22, $f18
  mul.s $f4, $f0, $f0
  neg.s $f10, $f12
  mul.s $f6, $f4, $f26
  div.s $f8, $f6, $f2
  c.le.s $f10, $f8
  nop   
  bc1fl .L7F04307C
   neg.s $f22, $f18
  add.s $f0, $f0, $f2
  neg.s $f22, $f2
  c.lt.s $f22, $f0
  nop   
  bc1fl .L7F0430C0
   c.le.s $f0, $f12
  b     .L7F0430BC
   mov.s $f0, $f22
  neg.s $f22, $f18
.L7F04307C:
  c.lt.s $f22, $f0
  nop   
  bc1fl .L7F0430C0
   c.le.s $f0, $f12
  c.lt.s $f24, $f0
  nop   
  bc1fl .L7F0430A8
   sub.s $f0, $f0, $f20
  b     .L7F0430A8
   sub.s $f0, $f0, $f2
  sub.s $f0, $f0, $f20
.L7F0430A8:
  c.lt.s $f0, $f22
  nop   
  bc1fl .L7F0430C0
   c.le.s $f0, $f12
  mov.s $f0, $f22
.L7F0430BC:
  c.le.s $f0, $f12
.L7F0430C0:
  nop   
  bc1fl .L7F0430D8
   add.s $f4, $f16, $f0
  b     .L7F0430F0
   swc1  $f14, ($a0)
  add.s $f4, $f16, $f0
.L7F0430D8:
  swc1  $f4, ($a0)
.L7F0430DC:
  lw    $t7, ($v1)
  addiu $v0, $v0, 1
  slt   $at, $v0, $t7
  bnezl $at, .L7F042F64
   lwc1  $f16, ($a0)
.L7F0430F0:
  swc1  $f0, ($a2)
  ldc1  $f26, 0x20($sp)
  ldc1  $f24, 0x18($sp)
  ldc1  $f22, 0x10($sp)
  ldc1  $f20, 8($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");






asm(R"
.late_rodata
glabel D_80052A60
.word 0xc0490fdb /*-3.1415927*/
glabel D_80052A64
.word 0x40c90fdb /*6.2831855*/
glabel D_80052A68
.word 0x40490fdb /*3.1415927*/
glabel D_80052A6C
.word 0x40c90fdb /*6.2831855*/
glabel D_80052A70
.word 0x40c90fdb /*6.2831855*/

.text
glabel sub_GAME_7F04310C
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  mtc1  $a1, $f12
  lwc1  $f4, ($a0)
  lui   $at, %hi(D_80052A60)
  lwc1  $f6, %lo(D_80052A60)($at)
  sub.s $f0, $f12, $f4
  mtc1  $a3, $f14
  lui   $at, %hi(D_80052A68)
  lwc1  $f16, 0x30($sp)
  c.lt.s $f0, $f6
  mfc1  $a3, $f14
  bc1f  .L7F043154
   nop   
  lui   $at, %hi(D_80052A68)
  lwc1  $f8, %lo(D_80052A64)($at)
  b     .L7F043174
   add.s $f12, $f12, $f8
.L7F043154:
  lwc1  $f10, %lo(D_80052A68)($at)
  lui   $at, %hi(D_80052A6C)
  c.le.s $f10, $f0
  nop   
  bc1fl .L7F043178
   lwc1  $f18, 0x34($sp)
  lwc1  $f2, %lo(D_80052A6C)($at)
  sub.s $f12, $f12, $f2
.L7F043174:
  lwc1  $f18, 0x34($sp)
.L7F043178:
  mfc1  $a1, $f12
  swc1  $f16, 0x10($sp)
  sw    $a0, 0x20($sp)
  jal   sub_GAME_7F042F18
   swc1  $f18, 0x14($sp)
  lw    $a0, 0x20($sp)
  mtc1  $zero, $f4
  lui   $at, %hi(D_80052A70)
  lwc1  $f0, ($a0)
  lwc1  $f2, %lo(D_80052A70)($at)
  c.lt.s $f0, $f4
  nop   
  bc1fl .L7F0431C0
   c.le.s $f2, $f0
  add.s $f6, $f0, $f2
  swc1  $f6, ($a0)
  lwc1  $f0, ($a0)
  c.le.s $f2, $f0
.L7F0431C0:
  nop   
  bc1fl .L7F0431D8
   lw    $ra, 0x1c($sp)
  sub.s $f8, $f0, $f2
  swc1  $f8, ($a0)
  lw    $ra, 0x1c($sp)
.L7F0431D8:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");






asm(R"
.late_rodata
glabel D_80052A74
.word 0x40c90fdb /*6.2831855*/
glabel D_80052A78
.word 0x3d4ccccd /*0.050000001*/
glabel D_80052A7C
.word 0x40c90fdb /*6.2831855*/
glabel D_80052A80
.word 0x3d4ccccd /*0.050000001*/
glabel D_80052A84
.word 0x3cf5c28f /*0.029999999*/
glabel D_80052A88
.word 0x3e19999a /*0.15000001*/

.text
glabel sub_GAME_7F0431E4
  addiu $sp, $sp, -0x118
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  sw    $a1, 0x11c($sp)
  lw    $t6, 0x64($a0)
  li    $at, 0xFFFE0000 # -nan
  ori   $at, (0xFFFEFFFF & 0xFFFF) # ori $at, $at, 0xffff
  and   $t7, $t6, $at
  andi  $t9, $t7, 0x80
  move  $s1, $a0
  beqz  $t9, .L7F04363C
   sw    $t7, 0x64($a0)
  lbu   $t0, 3($a0)
  lw    $s0, 0x6c($a0)
  li    $at, 1
  bne   $t0, $at, .L7F04324C
   addiu $a0, $s1, 0x18
  jal   sub_GAME_7F03FB70
   move  $a0, $s0
  lw    $t1, 0x64($s1)
  li    $at, -129
  sw    $zero, 0x6c($s1)
  and   $t2, $t1, $at
  b     .L7F04363C
   sw    $t2, 0x64($s1)
.L7F04324C:
  lw    $t3, ($s0)
  li    $at, -2
  sw    $zero, 0x88($s0)
  and   $t4, $t3, $at
  li    $at, -5
  sw    $t4, ($s0)
  and   $t6, $t4, $at
  sw    $t6, ($s0)
  sw    $a0, 0x28($sp)
  jal   sub_GAME_7F058860
   addiu $a1, $sp, 0x10c
  addiu $a0, $sp, 0x10c
  jal   sub_GAME_7F058714
   addiu $a1, $sp, 0xcc
  addiu $a1, $s0, 0x68
  sw    $a1, 0x24($sp)
  jal   sub_GAME_7F05B3F4
   addiu $a0, $sp, 0x10c
  addiu $a0, $sp, 0xcc
  jal   sub_GAME_7F059D38
   addiu $a1, $sp, 0x8c
  addiu $a0, $sp, 0x8c
  lw    $a1, 0x28($sp)
  jal   sub_GAME_7F0580C8
   addiu $a2, $sp, 0x4c
  lwc1  $f2, 0x4c($sp)
  lwc1  $f14, 0x50($sp)
  lwc1  $f0, 0x54($sp)
  mul.s $f4, $f2, $f2
  nop   
  mul.s $f6, $f14, $f14
  add.s $f8, $f4, $f6
  mul.s $f10, $f0, $f0
  jal   sqrtf
   add.s $f12, $f10, $f8
  swc1  $f0, 0xc0($s0)
  lwc1  $f4, 0x5c($sp)
  lwc1  $f10, 0x60($sp)
  mul.s $f6, $f4, $f4
  nop   
  mul.s $f8, $f10, $f10
  lwc1  $f10, 0x64($sp)
  add.s $f4, $f6, $f8
  mul.s $f6, $f10, $f10
  jal   sqrtf
   add.s $f12, $f6, $f4
  swc1  $f0, 0xc4($s0)
  lwc1  $f8, 0x6c($sp)
  lwc1  $f6, 0x70($sp)
  mul.s $f10, $f8, $f8
  nop   
  mul.s $f4, $f6, $f6
  lwc1  $f6, 0x74($sp)
  add.s $f8, $f10, $f4
  mul.s $f10, $f6, $f6
  jal   sqrtf
   add.s $f12, $f10, $f8
  swc1  $f0, 0xc8($s0)
  mtc1  $zero, $f16
  lwc1  $f2, 0x18($s1)
  lwc1  $f14, 0x20($s1)
  c.eq.s $f2, $f16
  nop   
  bc1f  .L7F043360
   nop   
  c.eq.s $f14, $f16
  li    $at, 0x3F800000 # 1.000000
  bc1tl .L7F0433A8
   mtc1  $at, $f14
.L7F043360:
  mul.s $f4, $f2, $f2
  swc1  $f2, 0x48($sp)
  swc1  $f14, 0x44($sp)
  mul.s $f6, $f14, $f14
  jal   sqrtf
   add.s $f12, $f4, $f6
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f18
  lwc1  $f2, 0x48($sp)
  lwc1  $f14, 0x44($sp)
  div.s $f12, $f18, $f0
  mtc1  $zero, $f16
  mul.s $f2, $f2, $f12
  nop   
  mul.s $f14, $f14, $f12
  b     .L7F0433B0
   nop   
  mtc1  $at, $f14
.L7F0433A8:
  mtc1  $at, $f18
  mov.s $f2, $f16
.L7F0433B0:
  swc1  $f2, 0x8c($sp)
  swc1  $f16, 0x90($sp)
  swc1  $f14, 0x94($sp)
  swc1  $f16, 0x98($sp)
  lwc1  $f10, 0x2c($s1)
  li    $at, 0xBF800000 # -1.000000
  addiu $a0, $sp, 0x8c
  c.le.s $f16, $f10
  addiu $a1, $sp, 0x10c
  bc1fl .L7F043408
   mtc1  $at, $f4
  neg.s $f8, $f14
  swc1  $f16, 0x9c($sp)
  swc1  $f18, 0xa0($sp)
  swc1  $f16, 0xa4($sp)
  swc1  $f16, 0xa8($sp)
  swc1  $f8, 0xac($sp)
  swc1  $f16, 0xb0($sp)
  swc1  $f2, 0xb4($sp)
  b     .L7F04342C
   swc1  $f16, 0xb8($sp)
  mtc1  $at, $f4
.L7F043408:
  neg.s $f6, $f2
  swc1  $f16, 0x9c($sp)
  swc1  $f16, 0xa4($sp)
  swc1  $f16, 0xa8($sp)
  swc1  $f14, 0xac($sp)
  swc1  $f16, 0xb0($sp)
  swc1  $f6, 0xb4($sp)
  swc1  $f16, 0xb8($sp)
  swc1  $f4, 0xa0($sp)
.L7F04342C:
  swc1  $f16, 0xbc($sp)
  swc1  $f16, 0xc0($sp)
  swc1  $f16, 0xc4($sp)
  jal   sub_GAME_7F058860
   swc1  $f18, 0xc8($sp)
  addiu $a1, $s0, 0x78
  sw    $a1, 0x28($sp)
  jal   sub_GAME_7F05B3F4
   addiu $a0, $sp, 0x10c
  lw    $a1, 0x28($sp)
  jal   sub_GAME_7F05BE10
   lw    $a0, 0x24($sp)
  mtc1  $zero, $f16
  nop   
  swc1  $f16, 0x60($s0)
  lwc1  $f8, 0xcc($sp)
  lwc1  $f10, 0x8c($sp)
  lwc1  $f6, 0x90($sp)
  mul.s $f4, $f10, $f8
  lwc1  $f10, 0xd0($sp)
  mul.s $f8, $f6, $f10
  lwc1  $f10, 0xd4($sp)
  add.s $f6, $f4, $f8
  lwc1  $f4, 0x94($sp)
  mul.s $f8, $f10, $f4
  jal   sub_GAME_7F05ACB0
   add.s $f12, $f8, $f6
  mtc1  $zero, $f16
  mov.s $f18, $f0
  c.lt.s $f16, $f0
  nop   
  bc1fl .L7F04350C
   c.lt.s $f16, $f0
  lwc1  $f2, 0x1c($s1)
  lw    $v0, 0x11c($sp)
  c.lt.s $f16, $f2
  nop   
  bc1fl .L7F04350C
   c.lt.s $f16, $f0
  lwc1  $f10, 4($v0)
  li    $at, 0x40800000 # 4.000000
  c.lt.s $f10, $f2
  nop   
  bc1fl .L7F04350C
   c.lt.s $f16, $f0
  mtc1  $at, $f4
  lui   $at, %hi(D_80052A74)
  lwc1  $f6, %lo(D_80052A74)($at)
  mul.s $f8, $f0, $f4
  lui   $at, %hi(D_80052A78)
  lwc1  $f4, %lo(D_80052A78)($at)
  div.s $f10, $f8, $f6
  div.s $f8, $f4, $f10
  b     .L7F0435E0
   swc1  $f8, 0x64($s0)
  c.lt.s $f16, $f0
.L7F04350C:
  lw    $v0, 0x11c($sp)
  lwc1  $f2, 0x1c($s1)
  bc1f  .L7F043564
   lwc1  $f14, 4($v0)
  c.lt.s $f2, $f16
  nop   
  bc1fl .L7F043568
   lwc1  $f10, 0x20($s1)
  c.lt.s $f2, $f14
  li    $at, 0x40800000 # 4.000000
  bc1fl .L7F043568
   lwc1  $f10, 0x20($s1)
  mtc1  $at, $f6
  lui   $at, %hi(D_80052A7C)
  lwc1  $f10, %lo(D_80052A7C)($at)
  mul.s $f4, $f0, $f6
  lui   $at, %hi(D_80052A80)
  lwc1  $f6, %lo(D_80052A80)($at)
  div.s $f8, $f4, $f10
  div.s $f4, $f6, $f8
  b     .L7F0435E0
   swc1  $f4, 0x64($s0)
.L7F043564:
  lwc1  $f10, 0x20($s1)
.L7F043568:
  lwc1  $f6, 8($v0)
  lwc1  $f4, ($v0)
  lw    $t7, 0x14($s1)
  mul.s $f8, $f10, $f6
  lwc1  $f10, 0x18($s1)
  lwc1  $f0, 0x14($t7)
  swc1  $f18, 0x30($sp)
  mul.s $f6, $f4, $f10
  nop   
  mul.s $f4, $f14, $f2
  add.s $f10, $f6, $f4
  mul.s $f4, $f0, $f0
  add.s $f6, $f8, $f10
  jal   sub_GAME_7F05ACB0
   div.s $f12, $f6, $f4
  mtc1  $zero, $f16
  lwc1  $f18, 0x30($sp)
  lui    $at, %hi(global_timer_delta)
  lwc1  $f8, %lo(global_timer_delta)($at)
  c.eq.s $f18, $f16
  li    $at, 0x3F800000 # 1.000000
  div.s $f2, $f0, $f8
  bc1tl .L7F0435D8
   mtc1  $at, $f6
  div.s $f10, $f2, $f18
  b     .L7F0435E0
   swc1  $f10, 0x64($s0)
  mtc1  $at, $f6
.L7F0435D8:
  nop   
  swc1  $f6, 0x64($s0)
.L7F0435E0:
  lwc1  $f0, 0x64($s0)
  lui   $at, %hi(D_80052A84)
  c.lt.s $f0, $f16
  nop   
  bc1f  .L7F043604
   nop   
  neg.s $f4, $f0
  swc1  $f4, 0x64($s0)
  lwc1  $f0, 0x64($s0)
.L7F043604:
  lwc1  $f2, %lo(D_80052A84)($at)
  lui   $at, %hi(D_80052A88)
  c.lt.s $f0, $f2
  nop   
  bc1f  .L7F043624
   nop   
  b     .L7F04363C
   swc1  $f2, 0x64($s0)
.L7F043624:
  lwc1  $f2, %lo(D_80052A88)($at)
  c.lt.s $f2, $f0
  nop   
  bc1fl .L7F043640
   lw    $ra, 0x1c($sp)
  swc1  $f2, 0x64($s0)
.L7F04363C:
  lw    $ra, 0x1c($sp)
.L7F043640:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x118
");






asm(R"
glabel sub_GAME_7F043650
  addiu $sp, $sp, -0x40
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  lw    $v0, 0x64($a0)
  move  $s0, $a0
  andi  $t6, $v0, 0x80
  beql  $t6, $zero, .L7F043828
   lw    $ra, 0x1c($sp)
  lw    $v1, 0x6c($a0)
  li    $at, -33
  lw    $t7, ($v1)
  andi  $t8, $t7, 1
  beql  $t8, $zero, .L7F0437CC
   and   $t0, $v0, $at
  lw    $t9, 0x90($v1)
  andi  $t0, $v0, 0x20
  bgtzl $t9, .L7F0437CC
   and   $t0, $v0, $at
  beqz  $t0, .L7F0437C8
   lui   $t2, %hi(Throwing_knife_SFX) 
  addiu $t2, %lo(Throwing_knife_SFX) # addiu $t2, $t2, 0xb2c
  lw    $at, ($t2)
  addiu $t1, $sp, 0x38
  sw    $at, ($t1)
  lhu   $at, 4($t2)
  sh    $at, 4($t1)
  lw    $t5, 0x6c($a0)
  lw    $t6, 0xa4($t5)
  jal   get_random_value
   sw    $t6, 0x34($sp)
  li    $at, 3
  divu  $zero, $v0, $at
  mfhi  $t7
  sw    $t7, 0x30($sp)
  lw    $v1, 0x6c($s0)
  lui   $t9, %hi(global_timer) 
  lw    $t9, %lo(global_timer)($t9)
  lw    $t8, 0xa0($v1)
  lw    $a3, 0x34($sp)
  addiu $t0, $t9, -6
  slt   $at, $t8, $t0
  beqz  $at, .L7F04372C
   sll   $t3, $a3, 2
  addu  $t1, $v1, $t3
  lw    $a0, 0x98($t1)
  beql  $a0, $zero, .L7F043730
   lw    $a3, 0x34($sp)
  jal   sfxGetArg0Unk3F
   sw    $t3, 0x2c($sp)
  beqz  $v0, .L7F04372C
   lw    $a3, 0x2c($sp)
  lw    $t2, 0x6c($s0)
  addu  $t4, $t2, $a3
  jal   sfxDeactivate
   lw    $a0, 0x98($t4)
.L7F04372C:
  lw    $a3, 0x34($sp)
.L7F043730:
  lw    $t6, 0x6c($s0)
  sll   $t5, $a3, 2
  addu  $t7, $t6, $t5
  lw    $t9, 0x98($t7)
  bnezl $t9, .L7F043828
   lw    $ra, 0x1c($sp)
  jal   get_controls_locked_flag
   sw    $t5, 0x2c($sp)
  bnez  $v0, .L7F043824
   lw    $a3, 0x2c($sp)
  lw    $t8, 0x30($sp)
  lw    $t3, 0x6c($s0)
  lui   $a0, %hi(ptr_sfx_buf)
  sll   $t0, $t8, 1
  addu  $a1, $sp, $t0
  lh    $a1, 0x38($a1)
  addu  $a2, $t3, $a3
  addiu $a2, $a2, 0x98
  sw    $a3, 0x2c($sp)
  jal   play_sfx_a1
   lw    $a0, %lo(ptr_sfx_buf)($a0)
  lw    $a3, 0x2c($sp)
  lw    $t1, 0x6c($s0)
  lw    $a1, 0x10($s0)
  addu  $t2, $t1, $a3
  lw    $a0, 0x98($t2)
  jal   sub_GAME_7F053A10
   addiu $a1, $a1, 8
  lui   $t4, %hi(global_timer) 
  lw    $t4, %lo(global_timer)($t4)
  lw    $t5, 0x6c($s0)
  li    $t7, 1
  sw    $t4, 0xa0($t5)
  lw    $t6, 0x34($sp)
  lw    $t8, 0x6c($s0)
  subu  $t9, $t7, $t6
  b     .L7F043824
   sw    $t9, 0xa4($t8)
.L7F0437C8:
  and   $t0, $v0, $at
.L7F0437CC:
  sw    $t0, 0x64($s0)
  lw    $a0, 0x98($v1)
  beql  $a0, $zero, .L7F0437FC
   lw    $t1, 0x6c($s0)
  jal   sfxGetArg0Unk3F
   nop   
  beql  $v0, $zero, .L7F0437FC
   lw    $t1, 0x6c($s0)
  lw    $t3, 0x6c($s0)
  jal   sfxDeactivate
   lw    $a0, 0x98($t3)
  lw    $t1, 0x6c($s0)
.L7F0437FC:
  lw    $a0, 0x9c($t1)
  beql  $a0, $zero, .L7F043828
   lw    $ra, 0x1c($sp)
  jal   sfxGetArg0Unk3F
   nop   
  beql  $v0, $zero, .L7F043828
   lw    $ra, 0x1c($sp)
  lw    $t2, 0x6c($s0)
  jal   sfxDeactivate
   lw    $a0, 0x9c($t2)
.L7F043824:
  lw    $ra, 0x1c($sp)
.L7F043828:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x40
  jr    $ra
   nop   
");






asm(R"
.late_rodata
glabel D_80052A8C
.word 0xbfc90fdb /*-1.5707964*/
glabel D_80052A90
.word 0xbfc90fdb /*-1.5707964*/

.text
glabel sub_GAME_7F043838
  addiu $sp, $sp, -0x128
  sw    $ra, 0x14($sp)
  sw    $a1, 0x12c($sp)
  lwc1  $f2, ($a0)
  lwc1  $f14, 4($a0)
  lwc1  $f0, 8($a0)
  mul.s $f4, $f2, $f2
  sw    $a0, 0x128($sp)
  mul.s $f6, $f14, $f14
  add.s $f8, $f4, $f6
  mul.s $f10, $f0, $f0
  jal   sqrtf
   add.s $f12, $f10, $f8
  lw    $a0, 0x128($sp)
  mtc1  $zero, $f2
  lwc1  $f4, ($a0)
  lwc1  $f6, 4($a0)
  lwc1  $f10, 8($a0)
  div.s $f14, $f4, $f0
  div.s $f18, $f6, $f0
  c.eq.s $f14, $f2
  nop   
  bc1f  .L7F0438C4
   div.s $f16, $f10, $f0
  c.eq.s $f16, $f2
  li    $at, 0x3F800000 # 1.000000
  bc1f  .L7F0438C4
   nop   
  mtc1  $at, $f8
  swc1  $f2, 0x124($sp)
  swc1  $f2, 0x120($sp)
  swc1  $f18, 0x11c($sp)
  swc1  $f2, 0x114($sp)
  b     .L7F043918
   swc1  $f8, 0x118($sp)
.L7F0438C4:
  mul.s $f4, $f14, $f14
  swc1  $f14, 0x10c($sp)
  swc1  $f16, 0x104($sp)
  mul.s $f6, $f16, $f16
  swc1  $f18, 0x108($sp)
  jal   sqrtf
   add.s $f12, $f4, $f6
  lwc1  $f14, 0x10c($sp)
  lwc1  $f16, 0x104($sp)
  lwc1  $f18, 0x108($sp)
  div.s $f2, $f14, $f0
  neg.s $f4, $f0
  swc1  $f4, 0x120($sp)
  div.s $f12, $f16, $f0
  mul.s $f8, $f18, $f2
  neg.s $f10, $f2
  swc1  $f10, 0x114($sp)
  swc1  $f8, 0x124($sp)
  mul.s $f6, $f18, $f12
  swc1  $f12, 0x118($sp)
  swc1  $f6, 0x11c($sp)
.L7F043918:
  lwc1  $f12, 0x118($sp)
  jal   convert_angle_using_inverse
   lwc1  $f14, 0x114($sp)
  swc1  $f0, 0xf4($sp)
  neg.s $f12, $f0
  jal   sub_GAME_7F0585FC
   addiu $a1, $sp, 0xb0
  lwc1  $f10, 0x124($sp)
  lwc1  $f8, 0x120($sp)
  lwc1  $f4, 0x11c($sp)
  addiu $a0, $sp, 0xb0
  addiu $a1, $sp, 0x24
  swc1  $f10, 0x24($sp)
  swc1  $f8, 0x28($sp)
  jal   sub_GAME_7F0583D8
   swc1  $f4, 0x2c($sp)
  lwc1  $f12, 0x24($sp)
  jal   convert_angle_using_inverse
   lwc1  $f14, 0x28($sp)
  lui   $at, %hi(D_80052A8C)
  lwc1  $f6, %lo(D_80052A8C)($at)
  lwc1  $f10, 0xf4($sp)
  swc1  $f0, 0xf0($sp)
  addiu $a1, $sp, 0x70
  jal   sub_GAME_7F0585FC
   add.s $f12, $f6, $f10
  lui   $at, %hi(D_80052A90)
  lwc1  $f8, %lo(D_80052A90)($at)
  lwc1  $f4, 0xf0($sp)
  addiu $a1, $sp, 0x30
  jal   sub_GAME_7F058570
   sub.s $f12, $f8, $f4
  addiu $a0, $sp, 0x70
  addiu $a1, $sp, 0x30
  jal   sub_GAME_7F0580C8
   lw    $a2, 0x12c($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x128
  jr    $ra
   nop   
");






asm(R"
glabel sub_GAME_7F0439B8
  addiu $sp, $sp, -0x68
  sw    $s0, 0x18($sp)
  move  $s0, $a0
  sw    $ra, 0x1c($sp)
  sw    $a1, 0x6c($sp)
  sw    $a2, 0x70($sp)
  addiu $a1, $sp, 0x28
  jal   sub_GAME_7F043838
   move  $a0, $a3
  lw    $t6, 0x14($s0)
  addiu $a1, $sp, 0x28
  jal   matrix_multiply_A1_by_F12
   lwc1  $f12, 0x14($t6)
  move  $a0, $s0
  lw    $a1, 0x6c($sp)
  addiu $a2, $sp, 0x28
  jal   sub_GAME_7F040754
   lw    $a3, 0x70($sp)
  lw    $t7, 0x14($s0)
  jal   sub_GAME_7F03FFF8
   lw    $a0, 8($t7)
  jal   sub_GAME_7F03E864
   move  $a0, $v0
  lwc1  $f6, 0x28($s0)
  lwc1  $f4, 0x58($s0)
  lwc1  $f18, 0x2c($s0)
  mul.s $f8, $f0, $f6
  lwc1  $f16, 0x5c($s0)
  move  $a0, $s0
  mul.s $f6, $f0, $f18
  sub.s $f10, $f4, $f8
  lwc1  $f8, 0x60($s0)
  sub.s $f4, $f16, $f6
  swc1  $f10, 0x58($s0)
  lwc1  $f10, 0x30($s0)
  swc1  $f4, 0x5c($s0)
  mul.s $f18, $f0, $f10
  sub.s $f16, $f8, $f18
  jal   sub_GAME_7F040484
   swc1  $f16, 0x60($s0)
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x68
  jr    $ra
   nop   
");






asm(R"
glabel sub_GAME_7F043A6C
  addiu $sp, $sp, -0xf0
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  sw    $a1, 0xf4($sp)
  sw    $a2, 0xf8($sp)
  sw    $a3, 0xfc($sp)
  lbu   $t7, 1($a1)
  move  $s1, $a0
  andi  $t8, $t7, 2
  beql  $t8, $zero, .L7F043B68
   move  $v0, $zero
  jal   sub_GAME_7F03FE98
   lw    $s0, 4($a0)
  beqz  $v0, .L7F043B64
   sw    $v0, 0x6c($s0)
  lw    $a0, 0xf8($sp)
  lw    $a1, 0xfc($sp)
  jal   sub_GAME_7F06C660
   move  $a2, $zero
  sw    $v0, 0x28($sp)
  lw    $t9, 0x64($s0)
  move  $a0, $s1
  ori   $t0, $t9, 0x40
  jal   sub_GAME_7F03E18C
   sw    $t0, 0x64($s0)
  jal   sub_GAME_7F03A538
   move  $a0, $s1
  jal   unset_stateflag_0x04_for_posdata
   move  $a0, $s1
  lw    $t1, 0xf8($sp)
  lw    $t2, 0x14($s0)
  move  $a0, $s1
  sw    $t1, 0x18($t2)
  lw    $t4, 0x14($s0)
  lw    $t3, 0xfc($sp)
  sw    $t3, 0x1c($t4)
  jal   sub_GAME_7F03A5A4
   lw    $a1, 0xf4($sp)
  addiu $s1, $sp, 0xac
  move  $a1, $s1
  jal   sub_GAME_7F058020
   addiu $a0, $s0, 0x18
  addiu $a0, $s0, 0x58
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   move  $a1, $s1
  jal   sub_GAME_7F078444
   nop   
  move  $a0, $v0
  lw    $a1, 0x28($sp)
  jal   sub_GAME_7F05818C
   addiu $a2, $sp, 0x6c
  addiu $a0, $sp, 0x6c
  jal   sub_GAME_7F059FB8
   addiu $a1, $sp, 0x2c
  lw    $a2, 0x6c($s0)
  addiu $a0, $sp, 0x2c
  move  $a1, $s1
  jal   sub_GAME_7F05818C
   addiu $a2, $a2, 4
  b     .L7F043B68
   li    $v0, 1
.L7F043B64:
  move  $v0, $zero
.L7F043B68:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0xf0
");

#ifdef VERSION_US
asm(R"
glabel generate_explosion_at_position
  addiu $sp, $sp, -0x60
  sw    $ra, 0x2c($sp)
  sw    $s0, 0x28($sp)
  sw    $a1, 0x64($sp)
  lw    $t0, 4($a0)
  lui   $at, 6
  move  $s0, $a0
  lw    $t6, 0x64($t0)
  addiu $t9, $s0, 0x2c
  and   $t7, $t6, $at
  srl   $t8, $t7, 0x11
  sw    $t8, 0x58($sp)
  lw    $a2, 0x1c($a0)
  move  $a0, $zero
  beql  $a2, $zero, .L7F043D10
   lw    $v0, 8($t0)
  lw    $v0, 0x1c($a2)
  move  $v1, $a2
  beql  $v0, $zero, .L7F043BE0
   lw    $t9, 0x14($v1)
  move  $v1, $v0
.L7F043BD0:
  lw    $v0, 0x1c($v0)
  bnezl $v0, .L7F043BD0
   move  $v1, $v0
  lw    $t9, 0x14($v1)
.L7F043BE0:
  sw    $t9, 0x50($sp)
  lbu   $t1, 1($s0)
  andi  $t2, $t1, 2
  beql  $t2, $zero, .L7F043C40
   lwc1  $f10, 8($v1)
  lw    $a0, 0x14($t0)
  sw    $t0, 0x5c($sp)
  jal   getsubmatrix
   sw    $v1, 0x54($sp)
  lwc1  $f4, 0x30($v0)
  swc1  $f4, 0x44($sp)
  lwc1  $f6, 0x34($v0)
  swc1  $f6, 0x48($sp)
  lwc1  $f8, 0x38($v0)
  jal   sub_GAME_7F078444
   swc1  $f8, 0x4c($sp)
  addiu $s0, $sp, 0x44
  move  $a1, $s0
  jal   sub_GAME_7F058474
   move  $a0, $v0
  lw    $v1, 0x54($sp)
  b     .L7F043C58
   lw    $t0, 0x5c($sp)
  lwc1  $f10, 8($v1)
.L7F043C40:
  addiu $s0, $sp, 0x44
  swc1  $f10, 0x44($sp)
  lwc1  $f16, 0xc($v1)
  swc1  $f16, 0x48($sp)
  lwc1  $f18, 0x10($v1)
  swc1  $f18, 0x4c($sp)
.L7F043C58:
  lbu   $t3, 1($v1)
  addiu $a0, $sp, 0x50
  lw    $a3, 0x44($sp)
  andi  $t4, $t3, 8
  bnez  $t4, .L7F043CD4
   lwc1  $f4, 0x4c($sp)
  lw    $a1, 8($v1)
  lw    $a2, 0x10($v1)
  sw    $t0, 0x5c($sp)
  sw    $v1, 0x54($sp)
  jal   sub_GAME_7F0B0BE4
   swc1  $f4, 0x10($sp)
  lw    $v1, 0x54($sp)
  beqz  $v0, .L7F043CD4
   lw    $t0, 0x5c($sp)
  lw    $t5, 8($t0)
  lw    $t8, 0x58($sp)
  addiu $t9, $v1, 0x2c
  andi  $t6, $t5, 0xe
  sltiu $t7, $t6, 1
  sw    $t7, 0x10($sp)
  sw    $t9, 0x18($sp)
  sw    $zero, 0x1c($sp)
  move  $a0, $zero
  move  $a1, $s0
  lw    $a2, 0x50($sp)
  lh    $a3, 0x66($sp)
  jal   sub_GAME_7F09C250
   sw    $t8, 0x14($sp)
  b     .L7F043D60
   lw    $ra, 0x2c($sp)
.L7F043CD4:
  lw    $t1, 0x58($sp)
  addiu $t2, $v1, 0x2c
  li    $t3, 1
  sw    $t3, 0x1c($sp)
  sw    $t2, 0x18($sp)
  move  $a0, $zero
  move  $a1, $s0
  lw    $a2, 0x50($sp)
  lh    $a3, 0x66($sp)
  sw    $zero, 0x10($sp)
  jal   sub_GAME_7F09C250
   sw    $t1, 0x14($sp)
  b     .L7F043D60
   lw    $ra, 0x2c($sp)
  lw    $v0, 8($t0)
.L7F043D10:
  andi  $t4, $v0, 0xe
  sltiu $v0, $t4, 1
  beql  $v0, $zero, .L7F043D30
   lw    $t8, 0x58($sp)
  lbu   $v0, 1($s0)
  andi  $t6, $v0, 8
  sltiu $v0, $t6, 1
  lw    $t8, 0x58($sp)
.L7F043D30:
  lw    $a2, 0x14($s0)
  sw    $t9, 0x18($sp)
  sw    $v0, 0x10($sp)
  sw    $t8, 0x14($sp)
  lbu   $t1, 1($s0)
  addiu $a1, $t0, 0x58
  lh    $a3, 0x66($sp)
  andi  $t2, $t1, 8
  sltu  $t3, $zero, $t2
  jal   sub_GAME_7F09C250
   sw    $t3, 0x1c($sp)
  lw    $ra, 0x2c($sp)
.L7F043D60:
  lw    $s0, 0x28($sp)
  addiu $sp, $sp, 0x60
  jr    $ra
   nop   
");

#ifdef VERSION_JP
asm(R"
glabel generate_explosion_at_position
  addiu $sp, $sp, -0x60
  sw    $ra, 0x2c($sp)
  sw    $s0, 0x28($sp)
  sw    $a1, 0x64($sp)
  lw    $t0, 4($a0)
  lui   $at, 6
  move  $s0, $a0
  lw    $t6, 0x64($t0)
  addiu $t9, $s0, 0x2c
  and   $t7, $t6, $at
  srl   $t8, $t7, 0x11
  sw    $t8, 0x58($sp)
  lw    $a2, 0x1c($a0)
  move  $a0, $zero
  beql  $a2, $zero, .L7F044010
   lw    $v0, 8($t0)
  lw    $v0, 0x1c($a2)
  move  $v1, $a2
  beql  $v0, $zero, .L7F043EE0
   lw    $t9, 0x14($v1)
  move  $v1, $v0
.L7F043ED0:
  lw    $v0, 0x1c($v0)
  bnezl $v0, .L7F043ED0
   move  $v1, $v0
  lw    $t9, 0x14($v1)
.L7F043EE0:
  sw    $t9, 0x4c($sp)
  lbu   $t1, 1($s0)
  andi  $t2, $t1, 2
  beql  $t2, $zero, .L7F043F40
   lwc1  $f10, 8($v1)
  lw    $a0, 0x14($t0)
  sw    $t0, 0x5c($sp)
  jal   getsubmatrix
   sw    $v1, 0x50($sp)
  lwc1  $f4, 0x30($v0)
  swc1  $f4, 0x40($sp)
  lwc1  $f6, 0x34($v0)
  swc1  $f6, 0x44($sp)
  lwc1  $f8, 0x38($v0)
  jal   sub_GAME_7F078444
   swc1  $f8, 0x48($sp)
  addiu $s0, $sp, 0x40
  move  $a1, $s0
  jal   sub_GAME_7F058474
   move  $a0, $v0
  lw    $v1, 0x50($sp)
  b     .L7F043F58
   lw    $t0, 0x5c($sp)
  lwc1  $f10, 8($v1)
.L7F043F40:
  addiu $s0, $sp, 0x40
  swc1  $f10, 0x40($sp)
  lwc1  $f16, 0xc($v1)
  swc1  $f16, 0x44($sp)
  lwc1  $f18, 0x10($v1)
  swc1  $f18, 0x48($sp)
.L7F043F58:
  lbu   $t3, 1($v1)
  addiu $a0, $sp, 0x4c
  lw    $a3, 0x40($sp)
  andi  $t4, $t3, 8
  bnez  $t4, .L7F043FD4
   lwc1  $f4, 0x48($sp)
  lw    $a1, 8($v1)
  lw    $a2, 0x10($v1)
  sw    $t0, 0x5c($sp)
  sw    $v1, 0x50($sp)
  jal   sub_GAME_7F0B0BE4
   swc1  $f4, 0x10($sp)
  lw    $v1, 0x50($sp)
  beqz  $v0, .L7F043FD4
   lw    $t0, 0x5c($sp)
  lw    $t5, 8($t0)
  lw    $t8, 0x58($sp)
  addiu $t9, $v1, 0x2c
  andi  $t6, $t5, 0xe
  sltiu $t7, $t6, 1
  sw    $t7, 0x10($sp)
  sw    $t9, 0x18($sp)
  sw    $zero, 0x1c($sp)
  move  $a0, $zero
  move  $a1, $s0
  lw    $a2, 0x4c($sp)
  lh    $a3, 0x66($sp)
  jal   sub_GAME_7F09C250
   sw    $t8, 0x14($sp)
  b     .L7F044060
   move  $v1, $v0
.L7F043FD4:
  lw    $t1, 0x58($sp)
  addiu $t2, $v1, 0x2c
  li    $t3, 1
  sw    $t3, 0x1c($sp)
  sw    $t2, 0x18($sp)
  move  $a0, $zero
  move  $a1, $s0
  lw    $a2, 0x4c($sp)
  lh    $a3, 0x66($sp)
  sw    $zero, 0x10($sp)
  jal   sub_GAME_7F09C250
   sw    $t1, 0x14($sp)
  b     .L7F044060
   move  $v1, $v0
  lw    $v0, 8($t0)
.L7F044010:
  andi  $t4, $v0, 0xe
  sltiu $v0, $t4, 1
  beql  $v0, $zero, .L7F044030
   lw    $t8, 0x58($sp)
  lbu   $v0, 1($s0)
  andi  $t6, $v0, 8
  sltiu $v0, $t6, 1
  lw    $t8, 0x58($sp)
.L7F044030:
  lw    $a2, 0x14($s0)
  sw    $t9, 0x18($sp)
  sw    $v0, 0x10($sp)
  sw    $t8, 0x14($sp)
  lbu   $t1, 1($s0)
  addiu $a1, $t0, 0x58
  lh    $a3, 0x66($sp)
  andi  $t2, $t1, 8
  sltu  $t3, $zero, $t2
  jal   sub_GAME_7F09C250
   sw    $t3, 0x1c($sp)
  move  $v1, $v0
.L7F044060:
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x28($sp)
  addiu $sp, $sp, 0x60
  jr    $ra
   move  $v0, $v1
    
");
#endif

#ifdef VERSION_US
asm(R"
.late_rodata
glabel D_80052A94
.word 0x47742400 /*62500.0*/

.text
glabel handle_thrown_explosive_detonation
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a0, 0x20($sp)
  lw    $a3, 4($a0)
  jal   get_cur_playernum
   sw    $a3, 0x1c($sp)
  jal   sub_GAME_7F09B4D8
   move  $a0, $v0
  bnez  $v0, .L7F0441F0
   lw    $a3, 0x1c($sp)
  lbu   $v0, 3($a3)
  li    $at, 7
  bnel  $v0, $at, .L7F043DE0
   li    $at, 8
  lw    $t7, 8($a3)
  lw    $a0, 0x20($sp)
  li    $a1, 12
  sll   $t8, $t7, 3
  bgezl $t8, .L7F0441F4
   lw    $ra, 0x14($sp)
  jal   generate_explosion_at_position
   sw    $a3, 0x1c($sp)
  lw    $a3, 0x1c($sp)
  lw    $t9, 0x64($a3)
  ori   $t0, $t9, 4
  b     .L7F0441F0
   sw    $t0, 0x64($a3)
  li    $at, 8
.L7F043DE0:
  bne   $v0, $at, .L7F0441F0
   lw    $t1, 0x20($sp)
  lw    $a2, 4($t1)
  li    $at, 26
  lb    $v1, 0x80($a2)
  beq   $v1, $at, .L7F043E04
   li    $at, 87
  bnel  $v1, $at, .L7F043E6C
   li    $at, 86
.L7F043E04:
  lh    $v0, 0x82($a2)
  lui   $t2, %hi(clock_timer) 
  bltzl $v0, .L7F043E6C
   li    $at, 86
  lw    $t2, %lo(clock_timer)($t2)
  subu  $t3, $v0, $t2
  sh    $t3, 0x82($a2)
  lh    $t4, 0x82($a2)
  lw    $a0, 0x20($sp)
  bgezl $t4, .L7F0441F4
   lw    $ra, 0x14($sp)
  lw    $t5, 0xc($a3)
  li    $a1, 13
  sll   $t6, $t5, 0
  bgez  $t6, .L7F043E4C
   nop   
  b     .L7F043E4C
   li    $a1, 17
.L7F043E4C:
  jal   generate_explosion_at_position
   sw    $a3, 0x1c($sp)
  lw    $a3, 0x1c($sp)
  lw    $t7, 0x64($a3)
  ori   $t8, $t7, 4
  b     .L7F0441F0
   sw    $t8, 0x64($a3)
  li    $at, 86
.L7F043E6C:
  bnel  $v1, $at, .L7F043EC0
   li    $at, 34
  lh    $t9, 0x82($a2)
  lw    $a0, 0x20($sp)
  bnezl $t9, .L7F0441F4
   lw    $ra, 0x14($sp)
  lw    $t0, 0xc($a3)
  li    $a1, 13
  sll   $t1, $t0, 0
  bgez  $t1, .L7F043EA0
   nop   
  b     .L7F043EA0
   li    $a1, 17
.L7F043EA0:
  jal   generate_explosion_at_position
   sw    $a3, 0x1c($sp)
  lw    $a3, 0x1c($sp)
  lw    $t2, 0x64($a3)
  ori   $t3, $t2, 4
  b     .L7F0441F0
   sw    $t3, 0x64($a3)
  li    $at, 34
.L7F043EC0:
  bnel  $v1, $at, .L7F043F14
   li    $at, 27
  lh    $t4, 0x82($a2)
  lw    $a0, 0x20($sp)
  li    $a1, 17
  bnezl $t4, .L7F0441F4
   lw    $ra, 0x14($sp)
  jal   generate_explosion_at_position
   sw    $a3, 0x1c($sp)
  lw    $a3, 0x1c($sp)
  li    $a0, 120
  lw    $t5, 0x64($a3)
  ori   $t6, $t5, 4
  jal   trigger_explosions_around_player
   sw    $t6, 0x64($a3)
  li    $a0, 2
  jal   set_unset_clock_lock_bits
   move  $a1, $zero
  b     .L7F0441F4
   lw    $ra, 0x14($sp)
  li    $at, 27
.L7F043F14:
  beq   $v1, $at, .L7F043F24
   li    $at, 33
  bnel  $v1, $at, .L7F043F9C
   li    $at, 29
.L7F043F24:
  lh    $v0, 0x82($a2)
  lui   $t7, %hi(clock_timer) 
  bltzl $v0, .L7F043F9C
   li    $at, 29
  lw    $t7, %lo(clock_timer)($t7)
  subu  $t8, $v0, $t7
  sh    $t8, 0x82($a2)
  lh    $t9, 0x82($a2)
  lw    $a0, 0x20($sp)
  bgezl $t9, .L7F0441F4
   lw    $ra, 0x14($sp)
  lw    $t0, 0xc($a3)
  li    $a1, 13
  sll   $t1, $t0, 0
  bgez  $t1, .L7F043F6C
   nop   
  b     .L7F043F6C
   li    $a1, 17
.L7F043F6C:
  sw    $a2, 0x18($sp)
  jal   generate_explosion_at_position
   sw    $a3, 0x1c($sp)
  lw    $a2, 0x18($sp)
  lw    $a3, 0x1c($sp)
  li    $t2, -1
  sh    $t2, 0x82($a2)
  lw    $t3, 0x64($a3)
  ori   $t4, $t3, 4
  b     .L7F0441F0
   sw    $t4, 0x64($a3)
  li    $at, 29
.L7F043F9C:
  bnel  $v1, $at, .L7F0440C4
   li    $at, 28
  lui   $v1, %hi(D_80030AF4)
  lw    $v1, %lo(D_80030AF4)($v1)
  lui   $t0, %hi(clock_timer) 
  beql  $v1, $zero, .L7F043FE4
   lh    $v0, 0x82($a2)
  lw    $v0, 0x64($a3)
  lui   $at, 6
  li    $t7, 1
  and   $t5, $v0, $at
  srl   $t6, $t5, 0x11
  sllv  $t8, $t7, $t6
  and   $t9, $v1, $t8
  beql  $t9, $zero, .L7F043FE4
   lh    $v0, 0x82($a2)
  sh    $zero, 0x82($a2)
  lh    $v0, 0x82($a2)
.L7F043FE4:
  slti  $at, $v0, 2
  bnez  $at, .L7F044018
   nop   
  lw    $t0, %lo(clock_timer)($t0)
  li    $t3, 1
  subu  $t1, $v0, $t0
  sh    $t1, 0x82($a2)
  lh    $t2, 0x82($a2)
  slti  $at, $t2, 2
  beql  $at, $zero, .L7F0441F4
   lw    $ra, 0x14($sp)
  b     .L7F0441F0
   sh    $t3, 0x82($a2)
.L7F044018:
  bnezl $v0, .L7F0441F4
   lw    $ra, 0x14($sp)
  lw    $t4, 0xc($a3)
  lw    $a0, 0x20($sp)
  li    $a1, 17
  sll   $t5, $t4, 0
  bgezl $t5, .L7F044054
   sw    $a2, 0x18($sp)
  sw    $a2, 0x18($sp)
  jal   generate_explosion_at_position
   sw    $a3, 0x1c($sp)
  lw    $a2, 0x18($sp)
  b     .L7F0440A8
   lw    $a3, 0x1c($sp)
  sw    $a2, 0x18($sp)
.L7F044054:
  jal   get_stage_num
   sw    $a3, 0x1c($sp)
  li    $at, 34
  lw    $a2, 0x18($sp)
  bne   $v0, $at, .L7F04408C
   lw    $a3, 0x1c($sp)
  lw    $a0, 0x20($sp)
  li    $a1, 19
  sw    $a2, 0x18($sp)
  jal   generate_explosion_at_position
   sw    $a3, 0x1c($sp)
  lw    $a2, 0x18($sp)
  b     .L7F0440A8
   lw    $a3, 0x1c($sp)
.L7F04408C:
  lw    $a0, 0x20($sp)
  li    $a1, 13
  sw    $a2, 0x18($sp)
  jal   generate_explosion_at_position
   sw    $a3, 0x1c($sp)
  lw    $a2, 0x18($sp)
  lw    $a3, 0x1c($sp)
.L7F0440A8:
  li    $t6, -1
  sh    $t6, 0x82($a2)
  lw    $t7, 0x64($a3)
  ori   $t8, $t7, 4
  b     .L7F0441F0
   sw    $t8, 0x64($a3)
  li    $at, 28
.L7F0440C4:
  bnel  $v1, $at, .L7F0441F4
   lw    $ra, 0x14($sp)
  lh    $v0, 0x82($a2)
  lui   $t9, %hi(clock_timer) 
  slti  $at, $v0, 2
  bnezl $at, .L7F044124
   li    $at, 1
  lw    $t9, %lo(clock_timer)($t9)
  li    $t2, 1
  move  $a0, $a2
  subu  $t0, $v0, $t9
  sh    $t0, 0x82($a2)
  lh    $t1, 0x82($a2)
  slti  $at, $t1, 2
  beql  $at, $zero, .L7F04419C
   lh    $t4, 0x82($a2)
  sh    $t2, 0x82($a2)
  sw    $a3, 0x1c($sp)
  jal   add_obj_to_temp_proxmine_table
   sw    $a2, 0x18($sp)
  lw    $a2, 0x18($sp)
  b     .L7F044198
   lw    $a3, 0x1c($sp)
  li    $at, 1
.L7F044124:
  bnel  $v0, $at, .L7F04419C
   lh    $t4, 0x82($a2)
  sw    $a2, 0x18($sp)
  jal   get_curplayer_positiondata
   sw    $a3, 0x1c($sp)
  lw    $t3, 0x20($sp)
  lwc1  $f4, 8($v0)
  lwc1  $f8, 0xc($v0)
  lwc1  $f6, 8($t3)
  lwc1  $f10, 0xc($t3)
  lwc1  $f16, 0x10($v0)
  sub.s $f0, $f4, $f6
  lwc1  $f18, 0x10($t3)
  lui   $at, %hi(D_80052A94)
  sub.s $f2, $f8, $f10
  mul.s $f4, $f0, $f0
  lw    $a2, 0x18($sp)
  sub.s $f12, $f16, $f18
  mul.s $f6, $f2, $f2
  lwc1  $f18, %lo(D_80052A94)($at)
  lw    $a3, 0x1c($sp)
  mul.s $f10, $f12, $f12
  add.s $f8, $f4, $f6
  add.s $f16, $f8, $f10
  c.lt.s $f16, $f18
  nop   
  bc1fl .L7F04419C
   lh    $t4, 0x82($a2)
  sh    $zero, 0x82($a2)
.L7F044198:
  lh    $t4, 0x82($a2)
.L7F04419C:
  lw    $a0, 0x20($sp)
  bnezl $t4, .L7F0441F4
   lw    $ra, 0x14($sp)
  lw    $t5, 0xc($a3)
  li    $a1, 13
  sll   $t6, $t5, 0
  bgez  $t6, .L7F0441C4
   nop   
  b     .L7F0441C4
   li    $a1, 17
.L7F0441C4:
  sw    $a2, 0x18($sp)
  jal   generate_explosion_at_position
   sw    $a3, 0x1c($sp)
  lw    $a0, 0x18($sp)
  lw    $a3, 0x1c($sp)
  li    $t7, -1
  sh    $t7, 0x82($a0)
  lw    $t8, 0x64($a3)
  ori   $t9, $t8, 4
  jal   remove_obj_from_temp_proxmine_table
   sw    $t9, 0x64($a3)
.L7F0441F0:
  lw    $ra, 0x14($sp)
.L7F0441F4:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

#ifdef VERSION_JP
asm(R"
.late_rodata
glabel D_80052A94
.word 0x47742400 /*62500.0*/

.text
glabel handle_thrown_explosive_detonation
  addiu $sp, $sp, -0x30
  sw    $ra, 0x14($sp)
  sw    $a0, 0x30($sp)
  lw    $a3, 4($a0)
  jal   get_cur_playernum
   sw    $a3, 0x2c($sp)
  jal   sub_GAME_7F09B4D8
   move  $a0, $v0
  bnez  $v0, .L7F0444D8
   lw    $a3, 0x2c($sp)
  lbu   $v0, 3($a3)
  li    $at, 7
  bnel  $v0, $at, .L7F0440E4
   li    $at, 8
  lw    $t7, 8($a3)
  lw    $a0, 0x30($sp)
  li    $a1, 12
  sll   $t8, $t7, 3
  bgezl $t8, .L7F0444DC
   lw    $ra, 0x14($sp)
  jal   generate_explosion_at_position
   sw    $a3, 0x2c($sp)
  lw    $a3, 0x2c($sp)
  lw    $t9, 0x64($a3)
  ori   $t0, $t9, 4
  b     .L7F0444D8
   sw    $t0, 0x64($a3)
  li    $at, 8
.L7F0440E4:
  bne   $v0, $at, .L7F0444D8
   lw    $t1, 0x30($sp)
  lw    $a2, 4($t1)
  li    $at, 26
  lb    $v1, 0x80($a2)
  beq   $v1, $at, .L7F044108
   li    $at, 87
  bnel  $v1, $at, .L7F044170
   li    $at, 86
.L7F044108:
  lh    $v0, 0x82($a2)
  lui   $t2, %hi(clock_timer) # $t2, 0x8005
  bltzl $v0, .L7F044170
   li    $at, 86
  lw    $t2, %lo(clock_timer)($t2)
  subu  $t3, $v0, $t2
  sh    $t3, 0x82($a2)
  lh    $t4, 0x82($a2)
  lw    $a0, 0x30($sp)
  bgezl $t4, .L7F0444DC
   lw    $ra, 0x14($sp)
  lw    $t5, 0xc($a3)
  li    $a1, 13
  sll   $t6, $t5, 0
  bgez  $t6, .L7F044150
   nop   
  b     .L7F044150
   li    $a1, 17
.L7F044150:
  jal   generate_explosion_at_position
   sw    $a3, 0x2c($sp)
  lw    $a3, 0x2c($sp)
  lw    $t7, 0x64($a3)
  ori   $t8, $t7, 4
  b     .L7F0444D8
   sw    $t8, 0x64($a3)
  li    $at, 86
.L7F044170:
  bnel  $v1, $at, .L7F0441C4
   li    $at, 34
  lh    $t9, 0x82($a2)
  lw    $a0, 0x30($sp)
  bnezl $t9, .L7F0444DC
   lw    $ra, 0x14($sp)
  lw    $t0, 0xc($a3)
  li    $a1, 13
  sll   $t1, $t0, 0
  bgez  $t1, .L7F0441A4
   nop   
  b     .L7F0441A4
   li    $a1, 17
.L7F0441A4:
  jal   generate_explosion_at_position
   sw    $a3, 0x2c($sp)
  lw    $a3, 0x2c($sp)
  lw    $t2, 0x64($a3)
  ori   $t3, $t2, 4
  b     .L7F0444D8
   sw    $t3, 0x64($a3)
  li    $at, 34
.L7F0441C4:
  bnel  $v1, $at, .L7F044218
   li    $at, 27
  lh    $t4, 0x82($a2)
  lw    $a0, 0x30($sp)
  li    $a1, 17
  bnezl $t4, .L7F0444DC
   lw    $ra, 0x14($sp)
  jal   generate_explosion_at_position
   sw    $a3, 0x2c($sp)
  lw    $a3, 0x2c($sp)
  li    $a0, 120
  lw    $t5, 0x64($a3)
  ori   $t6, $t5, 4
  jal   trigger_explosions_around_player
   sw    $t6, 0x64($a3)
  li    $a0, 2
  jal   set_unset_clock_lock_bits
   move  $a1, $zero
  b     .L7F0444DC
   lw    $ra, 0x14($sp)
  li    $at, 27
.L7F044218:
  beq   $v1, $at, .L7F044228
   li    $at, 33
  bnel  $v1, $at, .L7F0442A4
   li    $at, 29
.L7F044228:
  lh    $v0, 0x82($a2)
  lui   $t7, %hi(clock_timer) # $t7, 0x8005
  bltzl $v0, .L7F0442A4
   li    $at, 29
  lw    $t7, %lo(clock_timer)($t7)
  subu  $t8, $v0, $t7
  sh    $t8, 0x82($a2)
  lh    $t9, 0x82($a2)
  lw    $a0, 0x30($sp)
  bgezl $t9, .L7F0444DC
   lw    $ra, 0x14($sp)
  lw    $t0, 0xc($a3)
  li    $a1, 13
  sll   $t1, $t0, 0
  bgez  $t1, .L7F044270
   nop   
  b     .L7F044270
   li    $a1, 17
.L7F044270:
  sw    $a2, 0x28($sp)
  jal   generate_explosion_at_position
   sw    $a3, 0x2c($sp)
  lw    $a2, 0x28($sp)
  beqz  $v0, .L7F0444D8
   lw    $a3, 0x2c($sp)
  li    $t2, -1
  sh    $t2, 0x82($a2)
  lw    $t3, 0x64($a3)
  ori   $t4, $t3, 4
  b     .L7F0444D8
   sw    $t4, 0x64($a3)
  li    $at, 29
.L7F0442A4:
  bnel  $v1, $at, .L7F0443A4
   li    $at, 28
  lui   $v1, %hi(D_80030AF4) # $v1, 0x8003
  lw    $v1, %lo(D_80030AF4)($v1)
  lui   $t0, %hi(clock_timer) # $t0, 0x8005
  beql  $v1, $zero, .L7F0442EC
   lh    $v0, 0x82($a2)
  lw    $v0, 0x64($a3)
  lui   $at, 6
  li    $t7, 1
  and   $t5, $v0, $at
  srl   $t6, $t5, 0x11
  sllv  $t8, $t7, $t6
  and   $t9, $v1, $t8
  beql  $t9, $zero, .L7F0442EC
   lh    $v0, 0x82($a2)
  sh    $zero, 0x82($a2)
  lh    $v0, 0x82($a2)
.L7F0442EC:
  slti  $at, $v0, 2
  bnez  $at, .L7F044320
   nop   
  lw    $t0, %lo(clock_timer)($t0)
  li    $t3, 1
  subu  $t1, $v0, $t0
  sh    $t1, 0x82($a2)
  lh    $t2, 0x82($a2)
  slti  $at, $t2, 2
  beql  $at, $zero, .L7F0444DC
   lw    $ra, 0x14($sp)
  b     .L7F0444D8
   sh    $t3, 0x82($a2)
.L7F044320:
  bnezl $v0, .L7F0444DC
   lw    $ra, 0x14($sp)
  lw    $t4, 0xc($a3)
  li    $a1, 13
  sll   $t5, $t4, 0
  bgezl $t5, .L7F044348
   sw    $a1, 0x1c($sp)
  b     .L7F04436C
   li    $a1, 17
  sw    $a1, 0x1c($sp)
.L7F044348:
  sw    $a2, 0x28($sp)
  jal   get_stage_num
   sw    $a3, 0x2c($sp)
  li    $at, 34
  lw    $a1, 0x1c($sp)
  lw    $a2, 0x28($sp)
  bne   $v0, $at, .L7F04436C
   lw    $a3, 0x2c($sp)
  li    $a1, 19
.L7F04436C:
  lw    $a0, 0x30($sp)
  sw    $a2, 0x28($sp)
  jal   generate_explosion_at_position
   sw    $a3, 0x2c($sp)
  lw    $a2, 0x28($sp)
  beqz  $v0, .L7F0444D8
   lw    $a3, 0x2c($sp)
  li    $t6, -1
  sh    $t6, 0x82($a2)
  lw    $t7, 0x64($a3)
  ori   $t8, $t7, 4
  b     .L7F0444D8
   sw    $t8, 0x64($a3)
  li    $at, 28
.L7F0443A4:
  bnel  $v1, $at, .L7F0444DC
   lw    $ra, 0x14($sp)
  lh    $v0, 0x82($a2)
  lui   $t9, %hi(clock_timer) # $t9, 0x8005
  slti  $at, $v0, 2
  bnezl $at, .L7F044404
   li    $at, 1
  lw    $t9, %lo(clock_timer)($t9)
  li    $t2, 1
  move  $a0, $a2
  subu  $t0, $v0, $t9
  sh    $t0, 0x82($a2)
  lh    $t1, 0x82($a2)
  slti  $at, $t1, 2
  beql  $at, $zero, .L7F04447C
   lh    $t4, 0x82($a2)
  sh    $t2, 0x82($a2)
  sw    $a3, 0x2c($sp)
  jal   add_obj_to_temp_proxmine_table
   sw    $a2, 0x28($sp)
  lw    $a2, 0x28($sp)
  b     .L7F044478
   lw    $a3, 0x2c($sp)
  li    $at, 1
.L7F044404:
  bnel  $v0, $at, .L7F04447C
   lh    $t4, 0x82($a2)
  sw    $a2, 0x28($sp)
  jal   get_curplayer_positiondata
   sw    $a3, 0x2c($sp)
  lw    $t3, 0x30($sp)
  lwc1  $f4, 8($v0)
  lwc1  $f8, 0xc($v0)
  lwc1  $f6, 8($t3)
  lwc1  $f10, 0xc($t3)
  lwc1  $f16, 0x10($v0)
  sub.s $f0, $f4, $f6
  lwc1  $f18, 0x10($t3)
  lui   $at, %hi(D_80052A94) # $at, 0x8005
  sub.s $f2, $f8, $f10
  mul.s $f4, $f0, $f0
  lw    $a2, 0x28($sp)
  sub.s $f12, $f16, $f18
  mul.s $f6, $f2, $f2
  lwc1  $f18, %lo(D_80052A94)($at)
  lw    $a3, 0x2c($sp)
  mul.s $f10, $f12, $f12
  add.s $f8, $f4, $f6
  add.s $f16, $f8, $f10
  c.lt.s $f16, $f18
  nop   
  bc1fl .L7F04447C
   lh    $t4, 0x82($a2)
  sh    $zero, 0x82($a2)
.L7F044478:
  lh    $t4, 0x82($a2)
.L7F04447C:
  lw    $a0, 0x30($sp)
  bnezl $t4, .L7F0444DC
   lw    $ra, 0x14($sp)
  lw    $t5, 0xc($a3)
  li    $a1, 13
  sll   $t6, $t5, 0
  bgez  $t6, .L7F0444A4
   nop   
  b     .L7F0444A4
   li    $a1, 17
.L7F0444A4:
  sw    $a2, 0x28($sp)
  jal   generate_explosion_at_position
   sw    $a3, 0x2c($sp)
  lw    $a2, 0x28($sp)
  beqz  $v0, .L7F0444D8
   lw    $a3, 0x2c($sp)
  li    $t7, -1
  sh    $t7, 0x82($a2)
  lw    $t8, 0x64($a3)
  move  $a0, $a2
  ori   $t9, $t8, 4
  jal   remove_obj_from_temp_proxmine_table
   sw    $t9, 0x64($a3)
.L7F0444D8:
  lw    $ra, 0x14($sp)
.L7F0444DC:
  addiu $sp, $sp, 0x30
  jr    $ra
   nop       
");
#endif

#endif




asm(R"
glabel sub_GAME_7F044200
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  lw    $s0, 0x20($a0)
  beql  $s0, $zero, .L7F04423C
   lw    $ra, 0x1c($sp)
.L7F04421C:
  lw    $s1, 0x24($s0)
  jal   sub_GAME_7F044200
   move  $a0, $s0
  jal   sub_GAME_7F04C130
   move  $a0, $s0
  bnez  $s1, .L7F04421C
   move  $s0, $s1
  lw    $ra, 0x1c($sp)
.L7F04423C:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x20
");






asm(R"
glabel sub_GAME_7F04424C
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  lw    $a3, 4($a0)
  move  $s1, $a0
  lw    $t6, 0x64($a3)
  andi  $t7, $t6, 4
  beql  $t7, $zero, .L7F044298
   lbu   $t9, 1($s1)
  lbu   $a2, 2($a3)
  move  $a0, $a3
  li    $a1, 1
  andi  $t8, $a2, 4
  jal   sub_GAME_7F040D98
   move  $a2, $t8
  b     .L7F0442CC
   lw    $ra, 0x1c($sp)
  lbu   $t9, 1($s1)
.L7F044298:
  move  $a0, $s1
  andi  $t0, $t9, 0xfffd
  jal   handle_thrown_explosive_detonation
   sb    $t0, 1($s1)
  lw    $s0, 0x20($s1)
  beql  $s0, $zero, .L7F0442CC
   lw    $ra, 0x1c($sp)
.L7F0442B4:
  lw    $s1, 0x24($s0)
  jal   sub_GAME_7F04424C
   move  $a0, $s0
  bnez  $s1, .L7F0442B4
   move  $s0, $s1
  lw    $ra, 0x1c($sp)
.L7F0442CC:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x20
");






asm(R"
glabel sub_GAME_7F0442DC
  addiu $sp, $sp, -0x40
  sw    $ra, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  lw    $s1, 4($a0)
  move  $s2, $a0
  lw    $v0, 0x64($s1)
  lw    $s0, 0x14($s1)
  andi  $t6, $v0, 4
  beql  $t6, $zero, .L7F044330
   lw    $a1, 0x1c($s0)
  lbu   $a2, 2($s1)
  move  $a0, $s1
  li    $a1, 1
  andi  $t7, $a2, 4
  jal   sub_GAME_7F040D98
   move  $a2, $t7
  b     .L7F044400
   lw    $ra, 0x24($sp)
  lw    $a1, 0x1c($s0)
.L7F044330:
  andi  $t8, $v0, 0x40
  beql  $a1, $zero, .L7F0443CC
   lbu   $t4, 1($s2)
  beqz  $t8, .L7F0443C8
   move  $a2, $zero
  jal   sub_GAME_7F06C660
   lw    $a0, 0x18($s0)
  sw    $v0, 0x2c($sp)
  lbu   $t9, 1($s2)
  ori   $t0, $t9, 2
  sb    $t0, 1($s2)
  lw    $t1, 8($s0)
  lh    $a0, 0xe($t1)
  sll   $t2, $a0, 6
  jal   sub_GAME_7F0BD714
   move  $a0, $t2
  sw    $v0, 0xc($s0)
  lw    $a1, 0x6c($s1)
  lw    $a0, 0x2c($sp)
  move  $a2, $v0
  jal   sub_GAME_7F05818C
   addiu $a1, $a1, 4
  lw    $t3, 8($s0)
  move  $a0, $s0
  jal   sub_GAME_7F06EEA4
   lw    $a1, ($t3)
  jal   handle_thrown_explosive_detonation
   move  $a0, $s2
  lw    $s1, 0x20($s2)
  beql  $s1, $zero, .L7F044400
   lw    $ra, 0x24($sp)
.L7F0443AC:
  lw    $s0, 0x24($s1)
  jal   sub_GAME_7F0442DC
   move  $a0, $s1
  bnez  $s0, .L7F0443AC
   move  $s1, $s0
  b     .L7F044400
   lw    $ra, 0x24($sp)
.L7F0443C8:
  lbu   $t4, 1($s2)
.L7F0443CC:
  move  $a0, $s2
  andi  $t5, $t4, 0xfffd
  jal   handle_thrown_explosive_detonation
   sb    $t5, 1($s2)
  lw    $s1, 0x20($s2)
  beql  $s1, $zero, .L7F044400
   lw    $ra, 0x24($sp)
.L7F0443E8:
  lw    $s0, 0x24($s1)
  jal   sub_GAME_7F04424C
   move  $a0, $s1
  bnez  $s0, .L7F0443E8
   move  $s1, $s0
  lw    $ra, 0x24($sp)
.L7F044400:
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x40
");






asm(R"
glabel sub_GAME_7F044414
  addiu $sp, $sp, -0xb8
  sw    $s5, 0x44($sp)
  sw    $s2, 0x38($sp)
  sw    $s1, 0x34($sp)
  sw    $s0, 0x30($sp)
  move  $s0, $a1
  move  $s1, $a3
  move  $s2, $a0
  move  $s5, $a2
  sw    $ra, 0x4c($sp)
  sw    $s6, 0x48($sp)
  sw    $s4, 0x40($sp)
  sw    $s3, 0x3c($sp)
  sdc1  $f24, 0x28($sp)
  sdc1  $f22, 0x20($sp)
  sdc1  $f20, 0x18($sp)
  blez  $a1, .L7F044680
   move  $t0, $zero
  mtc1  $zero, $f24
  mtc1  $zero, $f23
  mtc1  $zero, $f22
  move  $s3, $a0
  ldc1  $f20, 0x88($sp)
  addiu $s6, $sp, 0x74
.L7F044474:
  addiu $s4, $t0, 1
  div   $zero, $s4, $s0
  mfhi  $a1
  sll   $t6, $a1, 3
  addu  $v0, $s2, $t6
  lwc1  $f6, 4($v0)
  lwc1  $f4, 4($s3)
  lwc1  $f10, ($v0)
  cvt.d.s $f8, $f6
  cvt.d.s $f0, $f4
  lwc1  $f2, ($s3)
  sub.d $f12, $f8, $f0
  bnez  $s0, .L7F0444B0
   nop   
  break 7
.L7F0444B0:
  li    $at, -1
  bne   $s0, $at, .L7F0444C8
   lui   $at, 0x8000
  bne   $s4, $at, .L7F0444C8
   nop   
  break 6
.L7F0444C8:
  c.eq.d $f12, $f22
  addiu $t7, $a1, 1
  cvt.d.s $f18, $f10
  cvt.d.s $f16, $f2
  bc1f  .L7F044520
   sub.d $f14, $f16, $f18
  c.eq.d $f14, $f22
  nop   
  bc1f  .L7F044520
   nop   
  swc1  $f2, 0x74($sp)
  swc1  $f24, 0x78($sp)
  lwc1  $f4, 4($s3)
  move  $a0, $s6
  move  $a1, $s5
  move  $a2, $s1
  jal   sub_GAME_7F03CCD8
   swc1  $f4, 0x7c($sp)
  beql  $v0, $zero, .L7F044674
   move  $t0, $s4
  b     .L7F044684
   move  $v0, $zero
.L7F044520:
  div   $zero, $t7, $s0
  mul.d $f6, $f0, $f14
  mfhi  $v0
  move  $v1, $v0
  move  $a0, $zero
  mul.d $f8, $f16, $f12
  add.d $f2, $f6, $f8
  bnez  $s0, .L7F044548
   nop   
  break 7
.L7F044548:
  li    $at, -1
  bne   $s0, $at, .L7F044560
   lui   $at, 0x8000
  bne   $t7, $at, .L7F044560
   nop   
  break 6
.L7F044560:
  beq   $t0, $v0, .L7F0445D8
   nop   
  sll   $t8, $v1, 3
.L7F04456C:
  addu  $v0, $s2, $t8
  lwc1  $f10, 4($v0)
  lwc1  $f6, ($v0)
  cvt.d.s $f18, $f10
  cvt.d.s $f8, $f6
  mul.d $f4, $f18, $f14
  nop   
  mul.d $f10, $f8, $f12
  add.d $f20, $f4, $f10
  c.eq.d $f20, $f2
  nop   
  bc1f  .L7F0445D8
   nop   
  addiu $t9, $v1, 1
  div   $zero, $t9, $s0
  mfhi  $v1
  bnez  $s0, .L7F0445B8
   nop   
  break 7
.L7F0445B8:
  li    $at, -1
  bne   $s0, $at, .L7F0445D0
   lui   $at, 0x8000
  bne   $t9, $at, .L7F0445D0
   nop   
  break 6
.L7F0445D0:
  bnel  $v1, $t0, .L7F04456C
   sll   $t8, $v1, 3
.L7F0445D8:
  blez  $s1, .L7F044660
   nop   
  move  $v0, $s5
.L7F0445E4:
  lwc1  $f18, 4($v0)
  lwc1  $f4, ($v0)
  c.eq.d $f20, $f2
  cvt.d.s $f6, $f18
  cvt.d.s $f10, $f4
  mul.d $f8, $f6, $f14
  nop   
  mul.d $f18, $f10, $f12
  bc1f  .L7F044614
   add.d $f0, $f8, $f18
  sub.d $f6, $f2, $f0
  add.d $f20, $f6, $f2
.L7F044614:
  c.lt.d $f0, $f2
  nop   
  bc1fl .L7F044638
   c.lt.d $f2, $f0
  c.lt.d $f20, $f2
  nop   
  bc1t  .L7F044660
   nop   
  c.lt.d $f2, $f0
.L7F044638:
  nop   
  bc1fl .L7F044658
   addiu $a0, $a0, 1
  c.lt.d $f2, $f20
  nop   
  bc1t  .L7F044660
   nop   
  addiu $a0, $a0, 1
.L7F044658:
  bne   $a0, $s1, .L7F0445E4
   addiu $v0, $v0, 8
.L7F044660:
  bnel  $a0, $s1, .L7F044674
   move  $t0, $s4
  b     .L7F044684
   li    $v0, 1
  move  $t0, $s4
.L7F044674:
  bne   $s4, $s0, .L7F044474
   addiu $s3, $s3, 8
  sdc1  $f20, 0x88($sp)
.L7F044680:
  move  $v0, $zero
.L7F044684:
  lw    $ra, 0x4c($sp)
  ldc1  $f20, 0x18($sp)
  ldc1  $f22, 0x20($sp)
  ldc1  $f24, 0x28($sp)
  lw    $s0, 0x30($sp)
  lw    $s1, 0x34($sp)
  lw    $s2, 0x38($sp)
  lw    $s3, 0x3c($sp)
  lw    $s4, 0x40($sp)
  lw    $s5, 0x44($sp)
  lw    $s6, 0x48($sp)
  jr    $ra
   addiu $sp, $sp, 0xb8
");

#ifdef VERSION_US
asm(R"
glabel sub_GAME_7F0446B8
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  sw    $a1, 0x1c($sp)
  sw    $a2, 0x20($sp)
  jal   sub_GAME_7F044414
   sw    $a3, 0x24($sp)
  beqz  $v0, .L7F0446E4
   lw    $a0, 0x20($sp)
  b     .L7F044708
   move  $v0, $zero
.L7F0446E4:
  lw    $a1, 0x24($sp)
  lw    $a2, 0x18($sp)
  jal   sub_GAME_7F044414
   lw    $a3, 0x1c($sp)
  beql  $v0, $zero, .L7F044708
   li    $v0, 1
  b     .L7F044708
   move  $v0, $zero
  li    $v0, 1
.L7F044708:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

#ifdef VERSION_JP
asm(R"
glabel sub_GAME_7F0446B8
  addiu $sp, $sp, -0x58
  sw    $s6, 0x38($sp)
  sw    $s5, 0x34($sp)
  sw    $s4, 0x30($sp)
  sw    $s3, 0x2c($sp)
  sw    $s1, 0x24($sp)
  move  $s3, $a1
  move  $s4, $a3
  move  $s5, $a0
  move  $s6, $a2
  sw    $ra, 0x3c($sp)
  sw    $s2, 0x28($sp)
  sw    $s0, 0x20($sp)
  sdc1  $f20, 0x18($sp)
  blez  $a1, .Ljp7F044A2C
   move  $s1, $zero
  mtc1  $zero, $f20
  move  $s0, $a0
  addiu $s2, $sp, 0x48
.Ljp7F0449EC:
  lwc1  $f4, ($s0)
  swc1  $f20, 0x4c($sp)
  move  $a0, $s2
  swc1  $f4, 0x48($sp)
  lwc1  $f6, 4($s0)
  move  $a1, $s6
  move  $a2, $s4
  jal   sub_GAME_7F03CCD8
   swc1  $f6, 0x50($sp)
  beqz  $v0, .Ljp7F044A20
   addiu $s1, $s1, 1
  b     .Ljp7F044AC0
   li    $v0, 1
.Ljp7F044A20:
  bne   $s1, $s3, .Ljp7F0449EC
   addiu $s0, $s0, 8
  move  $s1, $zero
.Ljp7F044A2C:
  mtc1  $zero, $f20
  blez  $s4, .Ljp7F044A78
   addiu $s2, $sp, 0x48
  move  $s0, $s6
.Ljp7F044A3C:
  lwc1  $f8, ($s0)
  swc1  $f20, 0x4c($sp)
  move  $a0, $s2
  swc1  $f8, 0x48($sp)
  lwc1  $f10, 4($s0)
  move  $a1, $s5
  move  $a2, $s3
  jal   sub_GAME_7F03CCD8
   swc1  $f10, 0x50($sp)
  beqz  $v0, .Ljp7F044A70
   addiu $s1, $s1, 1
  b     .Ljp7F044AC0
   li    $v0, 1
.Ljp7F044A70:
  bne   $s1, $s4, .Ljp7F044A3C
   addiu $s0, $s0, 8
.Ljp7F044A78:
  move  $a0, $s5
  move  $a1, $s3
  move  $a2, $s6
  jal   sub_GAME_7F044414
   move  $a3, $s4
  beqz  $v0, .Ljp7F044A9C
   move  $a0, $s6
  b     .Ljp7F044AC0
   move  $v0, $zero
.Ljp7F044A9C:
  move  $a1, $s4
  move  $a2, $s5
  jal   sub_GAME_7F044414
   move  $a3, $s3
  beql  $v0, $zero, .Ljp7F044AC0
   li    $v0, 1
  b     .Ljp7F044AC0
   move  $v0, $zero
  li    $v0, 1
.Ljp7F044AC0:
  lw    $ra, 0x3c($sp)
  ldc1  $f20, 0x18($sp)
  lw    $s0, 0x20($sp)
  lw    $s1, 0x24($sp)
  lw    $s2, 0x28($sp)
  lw    $s3, 0x2c($sp)
  lw    $s4, 0x30($sp)
  lw    $s5, 0x34($sp)
  lw    $s6, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x58   
");
#endif

#endif




asm(R"
glabel sub_GAME_7F044718
  addiu $sp, $sp, -0x68
  sw    $s4, 0x60($sp)
  sw    $s3, 0x5c($sp)
  sdc1  $f28, 0x40($sp)
  mtc1  $a1, $f28
  sw    $ra, 0x64($sp)
  sw    $s2, 0x58($sp)
  sw    $s1, 0x54($sp)
  sw    $s0, 0x50($sp)
  sdc1  $f30, 0x48($sp)
  sdc1  $f26, 0x38($sp)
  sdc1  $f24, 0x30($sp)
  sdc1  $f22, 0x28($sp)
  sdc1  $f20, 0x20($sp)
  move  $s3, $a3
  move  $s4, $a2
  lwc1  $f22, ($a0)
  lwc1  $f24, 8($a0)
  blez  $a3, .L7F04486C
   move  $v0, $zero
  mtc1  $zero, $f30
  move  $s1, $a2
.L7F044770:
  addiu $s2, $v0, 1
  div   $zero, $s2, $s3
  mfhi  $t6
  sll   $t7, $t6, 3
  addu  $s0, $s4, $t7
  lw    $a2, ($s0)
  lw    $a3, 4($s0)
  lwc1  $f12, ($s1)
  lwc1  $f14, 4($s1)
  bnez  $s3, .L7F0447A0
   nop   
  break 7
.L7F0447A0:
  li    $at, -1
  bne   $s3, $at, .L7F0447B8
   lui   $at, 0x8000
  bne   $s2, $at, .L7F0447B8
   nop   
  break 6
.L7F0447B8:
  swc1  $f24, 0x14($sp)
  jal   sub_GAME_7F0B16C4
   swc1  $f22, 0x10($sp)
  c.lt.s $f0, $f30
  mfc1  $a2, $f22
  mfc1  $a3, $f24
  mov.s $f20, $f0
  bc1fl .L7F0447E4
   lwc1  $f12, ($s1)
  neg.s $f20, $f0
  lwc1  $f12, ($s1)
.L7F0447E4:
  jal   sub_GAME_7F0B1794
   lwc1  $f14, 4($s1)
  mfc1  $a2, $f22
  mfc1  $a3, $f24
  mov.s $f26, $f0
  lwc1  $f12, ($s0)
  jal   sub_GAME_7F0B1794
   lwc1  $f14, 4($s0)
  c.lt.s $f20, $f28
  nop   
  bc1fl .L7F044864
   move  $v0, $s2
  c.lt.s $f26, $f28
  nop   
  bc1t  .L7F044858
   nop   
  c.lt.s $f0, $f28
  nop   
  bc1t  .L7F044858
   nop   
  lwc1  $f12, ($s1)
  lwc1  $f14, 4($s1)
  lw    $a2, ($s0)
  lw    $a3, 4($s0)
  swc1  $f24, 0x14($sp)
  jal   sub_GAME_7F0B17E4
   swc1  $f22, 0x10($sp)
  beql  $v0, $zero, .L7F044864
   move  $v0, $s2
.L7F044858:
  b     .L7F044870
   li    $v0, 1
  move  $v0, $s2
.L7F044864:
  bne   $s2, $s3, .L7F044770
   addiu $s1, $s1, 8
.L7F04486C:
  move  $v0, $zero
.L7F044870:
  lw    $ra, 0x64($sp)
  ldc1  $f20, 0x20($sp)
  ldc1  $f22, 0x28($sp)
  ldc1  $f24, 0x30($sp)
  ldc1  $f26, 0x38($sp)
  ldc1  $f28, 0x40($sp)
  ldc1  $f30, 0x48($sp)
  lw    $s0, 0x50($sp)
  lw    $s1, 0x54($sp)
  lw    $s2, 0x58($sp)
  lw    $s3, 0x5c($sp)
  lw    $s4, 0x60($sp)
  jr    $ra
   addiu $sp, $sp, 0x68
");






asm(R"
glabel sub_GAME_7F0448A8
  addiu $sp, $sp, -0xa0
  sw    $ra, 0x34($sp)
  sw    $s5, 0x30($sp)
  addiu $t6, $sp, 0x8c
  move  $s5, $a0
  sw    $s4, 0x2c($sp)
  sw    $s3, 0x28($sp)
  sw    $s2, 0x24($sp)
  sw    $s1, 0x20($sp)
  sw    $s0, 0x1c($sp)
  sw    $t6, 0x10($sp)
  addiu $a1, $sp, 0x98
  addiu $a2, $sp, 0x94
  jal   sub_GAME_7F03CC20
   addiu $a3, $sp, 0x90
  lw    $t7, 0x94($sp)
  addiu $s0, $sp, 0x6c
  move  $a0, $s5
  bgtz  $t7, .L7F044900
   nop   
  b     .L7F044B14
   li    $v0, 1
.L7F044900:
  jal   sub_GAME_7F03CB8C
   move  $a1, $s0
  jal   sub_GAME_7F03E3FC
   move  $a0, $s0
  lui   $s3, %hi(ptr_list_object_lookup_indices)
  lw    $s3, %lo(ptr_list_object_lookup_indices)($s3)
  li    $s4, 2
  lh    $v0, ($s3)
  bltz  $v0, .L7F044B10
   sll   $t8, $v0, 2
.L7F044928:
  subu  $t8, $t8, $v0
  sll   $t8, $t8, 2
  addu  $t8, $t8, $v0
  lui   $t9, %hi(pos_data_entry) 
  addiu $t9, %lo(pos_data_entry) # addiu $t9, $t9, -0x63c8
  sll   $t8, $t8, 2
  addu  $s2, $t8, $t9
  beql  $s2, $s5, .L7F044B04
   lh    $v0, 2($s3)
  lbu   $v0, ($s2)
  li    $at, 6
  beq   $v0, $at, .L7F044964
   li    $at, 3
  bnel  $v0, $at, .L7F044A50
   li    $at, 1
.L7F044964:
  lw    $v0, 4($s2)
  move  $a0, $s2
  addiu $a1, $sp, 0x5c
  beqz  $v0, .L7F044988
   addiu $a2, $sp, 0x64
  lw    $t0, 0x14($v0)
  andi  $t1, $t0, 0x400
  bnezl $t1, .L7F044B04
   lh    $v0, 2($s3)
.L7F044988:
  jal   sub_GAME_7F03CF88
   addiu $a3, $sp, 0x60
  jal   sub_GAME_7F03CFE8
   move  $a0, $s2
  lwc1  $f2, 0x60($sp)
  lwc1  $f8, 0x90($sp)
  lwc1  $f4, 0x64($sp)
  add.s $f2, $f2, $f0
  lwc1  $f10, 0x8c($sp)
  add.s $f6, $f4, $f0
  swc1  $f2, 0x60($sp)
  c.le.s $f2, $f8
  swc1  $f6, 0x64($sp)
  bc1fl .L7F044B04
   lh    $v0, 2($s3)
  c.le.s $f10, $f6
  addiu $s1, $s2, 8
  li    $s0, 1
  move  $a0, $s1
  bc1f  .L7F044B00
   lw    $a1, 0x98($sp)
  jal   sub_GAME_7F03CCD8
   lw    $a2, 0x94($sp)
  beqz  $v0, .L7F0449F0
   move  $a0, $s1
  move  $s0, $zero
.L7F0449F0:
  beqz  $s0, .L7F044A10
   lw    $a1, 0x5c($sp)
  lw    $a2, 0x98($sp)
  jal   sub_GAME_7F044718
   lw    $a3, 0x94($sp)
  beqz  $v0, .L7F044A10
   nop   
  move  $s0, $zero
.L7F044A10:
  bnezl $s0, .L7F044B04
   lh    $v0, 2($s3)
  lbu   $t2, ($s2)
  li    $at, 3
  bne   $t2, $at, .L7F044A44
   nop   
  lbu   $t3, ($s5)
  bne   $s4, $t3, .L7F044A44
   nop   
  lw    $v0, 4($s2)
  lhu   $t4, 0x12($v0)
  ori   $t5, $t4, 0x10
  sh    $t5, 0x12($v0)
.L7F044A44:
  b     .L7F044B14
   move  $v0, $zero
  li    $at, 1
.L7F044A50:
  beq   $v0, $at, .L7F044A68
   li    $at, 4
  beql  $v0, $at, .L7F044A6C
   lbu   $t6, ($s5)
  bnel  $s4, $v0, .L7F044B04
   lh    $v0, 2($s3)
.L7F044A68:
  lbu   $t6, ($s5)
.L7F044A6C:
  move  $a0, $s2
  addiu $a1, $sp, 0x4c
  bne   $s4, $t6, .L7F044A9C
   addiu $a2, $sp, 0x48
  beql  $s4, $v0, .L7F044B04
   lh    $v0, 2($s3)
  lw    $t7, 4($s2)
  li    $at, 43
  lbu   $v0, 3($t7)
  beq   $v0, $at, .L7F044B00
   li    $at, 40
  beq   $v0, $at, .L7F044B00
.L7F044A9C:
   addiu $t8, $sp, 0x40
  sw    $t8, 0x10($sp)
  jal   sub_GAME_7F03CC20
   addiu $a3, $sp, 0x44
  lw    $a1, 0x48($sp)
  lwc1  $f16, 0x90($sp)
  lwc1  $f18, 0x40($sp)
  blezl $a1, .L7F044B04
   lh    $v0, 2($s3)
  c.le.s $f18, $f16
  lwc1  $f4, 0x44($sp)
  lwc1  $f8, 0x8c($sp)
  bc1fl .L7F044B04
   lh    $v0, 2($s3)
  c.le.s $f8, $f4
  lw    $a0, 0x4c($sp)
  lw    $a2, 0x98($sp)
  bc1fl .L7F044B04
   lh    $v0, 2($s3)
  jal   sub_GAME_7F0446B8
   lw    $a3, 0x94($sp)
  beql  $v0, $zero, .L7F044B04
   lh    $v0, 2($s3)
  b     .L7F044B14
   move  $v0, $zero
.L7F044B00:
  lh    $v0, 2($s3)
.L7F044B04:
  addiu $s3, $s3, 2
  bgezl $v0, .L7F044928
   sll   $t8, $v0, 2
.L7F044B10:
  li    $v0, 1
.L7F044B14:
  lw    $ra, 0x34($sp)
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  lw    $s2, 0x24($sp)
  lw    $s3, 0x28($sp)
  lw    $s4, 0x2c($sp)
  lw    $s5, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0xa0
");






asm(R"
glabel sub_GAME_7F044B38
  addiu $sp, $sp, -0x158
  sw    $ra, 0x24($sp)
  sw    $s1, 0x20($sp)
  sw    $s0, 0x1c($sp)
  lw    $v1, 0x14($a0)
  lw    $s1, 0x10($a0)
  li    $t8, 1
  lw    $t9, 8($v1)
  move  $s0, $a0
  addiu $a1, $sp, 0xc8
  lw    $v0, 8($t9)
  lw    $t0, 4($v0)
  lw    $t1, 4($t0)
  sw    $t1, 0x148($sp)
  lw    $t2, 8($v0)
  lw    $t3, 4($t2)
  sw    $t3, 0x144($sp)
  lw    $t4, 0xc($v0)
  lw    $t5, 4($t4)
  sw    $t5, 0x140($sp)
  lw    $t6, 0x10($v0)
  lw    $t7, 4($t6)
  sw    $t8, 0x108($sp)
  sw    $t7, 0x13c($sp)
  lw    $t9, 0x18($v0)
  lw    $t0, 4($t9)
  sw    $t0, 0xc0($sp)
  lwc1  $f12, 0xa0($a0)
  jal   sub_GAME_7F0585FC
   sw    $v1, 0x154($sp)
  lw    $t1, 0x154($sp)
  addiu $a1, $sp, 0xc8
  jal   matrix_multiply_A1_by_F12
   lwc1  $f12, 0x14($t1)
  addiu $a0, $s0, 0x58
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   addiu $a1, $sp, 0xc8
  addiu $a0, $sp, 0xc8
  lw    $a1, 0x148($sp)
  jal   sub_GAME_7F058418
   addiu $a2, $sp, 0x130
  addiu $a0, $sp, 0xc8
  lw    $a1, 0x144($sp)
  jal   sub_GAME_7F058418
   addiu $a2, $sp, 0x124
  addiu $a0, $sp, 0xc8
  lw    $a1, 0x140($sp)
  jal   sub_GAME_7F058418
   addiu $a2, $sp, 0x118
  addiu $a0, $sp, 0xc8
  lw    $a1, 0x13c($sp)
  jal   sub_GAME_7F058418
   addiu $a2, $sp, 0x10c
  lw    $t2, 0x14($s1)
  lwc1  $f8, 0x138($sp)
  addiu $a0, $sp, 0xc4
  sw    $t2, 0xc4($sp)
  lw    $a2, 0x10($s1)
  lw    $a1, 8($s1)
  lw    $a3, 0x130($sp)
  jal   sub_GAME_7F0B0BE4
   swc1  $f8, 0x10($sp)
  beqz  $v0, .L7F044C4C
   lw    $a0, 0xc4($sp)
  lw    $a1, 0x130($sp)
  jal   sub_GAME_7F0B2970
   lw    $a2, 0x138($sp)
  b     .L7F044C50
   swc1  $f0, 0x134($sp)
.L7F044C4C:
  sw    $zero, 0x108($sp)
.L7F044C50:
  lw    $t3, 0x14($s1)
  lwc1  $f6, 0x12c($sp)
  addiu $a0, $sp, 0xc4
  sw    $t3, 0xc4($sp)
  lw    $a2, 0x10($s1)
  lw    $a1, 8($s1)
  lw    $a3, 0x124($sp)
  jal   sub_GAME_7F0B0BE4
   swc1  $f6, 0x10($sp)
  beqz  $v0, .L7F044C90
   lw    $a0, 0xc4($sp)
  lw    $a1, 0x124($sp)
  jal   sub_GAME_7F0B2970
   lw    $a2, 0x12c($sp)
  b     .L7F044C94
   swc1  $f0, 0x128($sp)
.L7F044C90:
  sw    $zero, 0x108($sp)
.L7F044C94:
  lw    $t4, 0x14($s1)
  lwc1  $f4, 0x120($sp)
  addiu $a0, $sp, 0xc4
  sw    $t4, 0xc4($sp)
  lw    $a2, 0x10($s1)
  lw    $a1, 8($s1)
  lw    $a3, 0x118($sp)
  jal   sub_GAME_7F0B0BE4
   swc1  $f4, 0x10($sp)
  beqz  $v0, .L7F044CD4
   lw    $a0, 0xc4($sp)
  lw    $a1, 0x118($sp)
  jal   sub_GAME_7F0B2970
   lw    $a2, 0x120($sp)
  b     .L7F044CD8
   swc1  $f0, 0x11c($sp)
.L7F044CD4:
  sw    $zero, 0x108($sp)
.L7F044CD8:
  lw    $t5, 0x14($s1)
  lwc1  $f10, 0x114($sp)
  addiu $a0, $sp, 0xc4
  sw    $t5, 0xc4($sp)
  lw    $a2, 0x10($s1)
  lw    $a1, 8($s1)
  lw    $a3, 0x10c($sp)
  jal   sub_GAME_7F0B0BE4
   swc1  $f10, 0x10($sp)
  beqz  $v0, .L7F044D18
   lw    $a0, 0xc4($sp)
  lw    $a1, 0x10c($sp)
  jal   sub_GAME_7F0B2970
   lw    $a2, 0x114($sp)
  b     .L7F044D1C
   swc1  $f0, 0x110($sp)
.L7F044D18:
  sw    $zero, 0x108($sp)
.L7F044D1C:
  lw    $t6, 0x108($sp)
  addiu $a0, $s0, 0x18
  addiu $a2, $sp, 0xbc
  beqz  $t6, .L7F045164
   move  $a1, $a0
  lwc1  $f18, 0x124($sp)
  lwc1  $f16, 0x130($sp)
  lwc1  $f14, 0x128($sp)
  lwc1  $f12, 0x134($sp)
  sub.s $f16, $f18, $f16
  lwc1  $f18, 0x12c($sp)
  lwc1  $f10, 0x138($sp)
  sub.s $f12, $f14, $f12
  swc1  $f16, 0xb4($sp)
  addiu $a0, $sp, 0xb4
  sub.s $f10, $f18, $f10
  swc1  $f12, 0xb8($sp)
  addiu $a1, $sp, 0xb8
  jal   guNormalize
   swc1  $f10, 0xbc($sp)
  lwc1  $f18, 0x10c($sp)
  lwc1  $f16, 0x124($sp)
  lwc1  $f14, 0x110($sp)
  lwc1  $f12, 0x128($sp)
  sub.s $f16, $f18, $f16
  lwc1  $f18, 0x114($sp)
  lwc1  $f10, 0x12c($sp)
  sub.s $f12, $f14, $f12
  swc1  $f16, 0xa8($sp)
  addiu $a0, $sp, 0xa8
  sub.s $f10, $f18, $f10
  swc1  $f12, 0xac($sp)
  addiu $a1, $sp, 0xac
  addiu $a2, $sp, 0xb0
  jal   guNormalize
   swc1  $f10, 0xb0($sp)
  lwc1  $f18, 0x118($sp)
  lwc1  $f16, 0x10c($sp)
  lwc1  $f14, 0x11c($sp)
  lwc1  $f12, 0x110($sp)
  sub.s $f16, $f18, $f16
  lwc1  $f18, 0x120($sp)
  lwc1  $f10, 0x114($sp)
  sub.s $f12, $f14, $f12
  swc1  $f16, 0x9c($sp)
  addiu $a0, $sp, 0x9c
  sub.s $f10, $f18, $f10
  swc1  $f12, 0xa0($sp)
  addiu $a1, $sp, 0xa0
  addiu $a2, $sp, 0xa4
  jal   guNormalize
   swc1  $f10, 0xa4($sp)
  lwc1  $f18, 0x130($sp)
  lwc1  $f16, 0x118($sp)
  lwc1  $f14, 0x134($sp)
  lwc1  $f12, 0x11c($sp)
  sub.s $f16, $f18, $f16
  lwc1  $f18, 0x138($sp)
  lwc1  $f10, 0x120($sp)
  sub.s $f12, $f14, $f12
  swc1  $f16, 0x90($sp)
  addiu $a0, $sp, 0x90
  sub.s $f10, $f18, $f10
  swc1  $f12, 0x94($sp)
  addiu $a1, $sp, 0x94
  addiu $a2, $sp, 0x98
  jal   guNormalize
   swc1  $f10, 0x98($sp)
  lwc1  $f8, 0xbc($sp)
  lwc1  $f6, 0xa8($sp)
  lwc1  $f10, 0xb0($sp)
  swc1  $f8, 0x28($sp)
  mul.s $f4, $f8, $f6
  lwc1  $f8, 0xb4($sp)
  swc1  $f6, 0x2c($sp)
  swc1  $f10, 0x34($sp)
  mul.s $f6, $f10, $f8
  swc1  $f8, 0x30($sp)
  lwc1  $f8, 0xa4($sp)
  sub.s $f0, $f4, $f6
  lwc1  $f4, 0x9c($sp)
  mul.s $f6, $f10, $f4
  lwc1  $f10, 0x2c($sp)
  swc1  $f4, 0x2c($sp)
  mul.s $f4, $f8, $f10
  sub.s $f14, $f6, $f4
  lwc1  $f6, 0x90($sp)
  c.le.s $f14, $f0
  nop   
  bc1fl .L7F044F10
   lwc1  $f6, 0xa4($sp)
  mul.s $f4, $f8, $f6
  swc1  $f10, 0x38($sp)
  lwc1  $f10, 0x2c($sp)
  lwc1  $f8, 0x98($sp)
  mul.s $f10, $f8, $f10
  sub.s $f4, $f4, $f10
  lwc1  $f10, 0x30($sp)
  c.le.s $f4, $f0
  nop   
  bc1fl .L7F044F10
   lwc1  $f6, 0xa4($sp)
  mul.s $f4, $f8, $f10
  lwc1  $f8, 0x28($sp)
  lwc1  $f12, 0xb8($sp)
  mul.s $f6, $f8, $f6
  sub.s $f4, $f4, $f6
  lwc1  $f6, 0x34($sp)
  c.le.s $f4, $f0
  nop   
  bc1fl .L7F044F10
   lwc1  $f6, 0xa4($sp)
  mul.s $f4, $f12, $f6
  lwc1  $f2, 0xac($sp)
  swc1  $f0, 0x78($sp)
  mul.s $f6, $f2, $f8
  sub.s $f8, $f4, $f6
  mul.s $f4, $f10, $f2
  lwc1  $f6, 0x38($sp)
  swc1  $f8, 0x74($sp)
  mul.s $f8, $f6, $f12
  sub.s $f10, $f4, $f8
  b     .L7F04501C
   swc1  $f10, 0x7c($sp)
  lwc1  $f6, 0xa4($sp)
.L7F044F10:
  lwc1  $f4, 0x90($sp)
  lwc1  $f10, 0x98($sp)
  swc1  $f6, 0x38($sp)
  mul.s $f8, $f6, $f4
  lwc1  $f6, 0x9c($sp)
  swc1  $f4, 0x34($sp)
  mul.s $f4, $f10, $f6
  sub.s $f0, $f8, $f4
  lwc1  $f8, 0xb4($sp)
  mul.s $f4, $f10, $f8
  lwc1  $f8, 0x34($sp)
  lwc1  $f10, 0xbc($sp)
  c.le.s $f0, $f14
  mul.s $f10, $f10, $f8
  bc1f  .L7F044F98
   sub.s $f2, $f4, $f10
  c.le.s $f2, $f14
  lwc1  $f8, 0x38($sp)
  bc1fl .L7F044F9C
   c.le.s $f2, $f0
  lwc1  $f2, 0xac($sp)
  lwc1  $f12, 0xa0($sp)
  lwc1  $f10, 0xb0($sp)
  mul.s $f4, $f2, $f8
  swc1  $f14, 0x78($sp)
  mul.s $f8, $f12, $f10
  sub.s $f10, $f4, $f8
  lwc1  $f4, 0xa8($sp)
  mul.s $f8, $f4, $f12
  swc1  $f10, 0x74($sp)
  mul.s $f10, $f6, $f2
  sub.s $f4, $f8, $f10
  b     .L7F04501C
   swc1  $f4, 0x7c($sp)
.L7F044F98:
  c.le.s $f2, $f0
.L7F044F9C:
  lwc1  $f12, 0xa0($sp)
  lwc1  $f14, 0x94($sp)
  lwc1  $f4, 0xbc($sp)
  bc1f  .L7F044FEC
   lwc1  $f6, 0x98($sp)
  lwc1  $f6, 0x98($sp)
  lwc1  $f14, 0x94($sp)
  lwc1  $f10, 0xa4($sp)
  mul.s $f8, $f12, $f6
  swc1  $f0, 0x78($sp)
  mul.s $f4, $f14, $f10
  lwc1  $f10, 0x9c($sp)
  sub.s $f6, $f8, $f4
  mul.s $f8, $f10, $f14
  lwc1  $f4, 0x90($sp)
  swc1  $f6, 0x74($sp)
  mul.s $f6, $f4, $f12
  sub.s $f10, $f8, $f6
  b     .L7F04501C
   swc1  $f10, 0x7c($sp)
.L7F044FEC:
  mul.s $f8, $f14, $f4
  lwc1  $f12, 0xb8($sp)
  swc1  $f2, 0x78($sp)
  mul.s $f10, $f12, $f6
  lwc1  $f6, 0x90($sp)
  sub.s $f4, $f8, $f10
  mul.s $f8, $f6, $f12
  lwc1  $f10, 0xb4($sp)
  swc1  $f4, 0x74($sp)
  mul.s $f4, $f10, $f14
  sub.s $f6, $f8, $f4
  swc1  $f6, 0x7c($sp)
.L7F04501C:
  jal   sinf
   lwc1  $f12, 0xa0($s0)
  mtc1  $zero, $f10
  swc1  $f0, 0x68($sp)
  swc1  $f10, 0x6c($sp)
  jal   cosf
   lwc1  $f12, 0xa0($s0)
  addiu $a0, $s0, 0x18
  swc1  $f0, 0x70($sp)
  jal   reset_array_of_0x10_floats
   sw    $a0, 0x58($sp)
  lwc1  $f8, 0x74($sp)
  lw    $a1, 0x58($sp)
  swc1  $f8, 0x28($s0)
  lwc1  $f4, 0x78($sp)
  lwc1  $f16, 0x28($s0)
  swc1  $f4, 0x2c($s0)
  lwc1  $f6, 0x7c($sp)
  lwc1  $f14, 0x2c($s0)
  swc1  $f6, 0x30($s0)
  lwc1  $f10, 0x70($sp)
  lwc1  $f4, 0x6c($sp)
  lwc1  $f0, 0x30($s0)
  mul.s $f8, $f14, $f10
  nop   
  mul.s $f6, $f4, $f0
  sub.s $f10, $f8, $f6
  swc1  $f10, 0x18($s0)
  lwc1  $f4, 0x68($sp)
  lwc1  $f6, 0x70($sp)
  mul.s $f8, $f0, $f4
  nop   
  mul.s $f10, $f6, $f16
  sub.s $f4, $f8, $f10
  swc1  $f4, 0x1c($s0)
  lwc1  $f6, 0x6c($sp)
  lwc1  $f10, 0x68($sp)
  mul.s $f8, $f16, $f6
  nop   
  mul.s $f4, $f10, $f14
  lwc1  $f10, 0x1c($s0)
  sub.s $f6, $f8, $f4
  swc1  $f6, 0x20($s0)
  swc1  $f10, 0x48($sp)
  lwc1  $f8, 0x48($sp)
  lwc1  $f2, 0x20($s0)
  lwc1  $f18, 0x18($s0)
  mul.s $f4, $f8, $f0
  nop   
  mul.s $f6, $f14, $f2
  sub.s $f10, $f4, $f6
  mul.s $f8, $f2, $f16
  nop   
  mul.s $f4, $f0, $f18
  swc1  $f10, 0x38($s0)
  mul.s $f10, $f18, $f14
  sub.s $f6, $f8, $f4
  swc1  $f6, 0x3c($s0)
  lwc1  $f8, 0x48($sp)
  mul.s $f4, $f16, $f8
  sub.s $f6, $f10, $f4
  swc1  $f6, 0x40($s0)
  lw    $t7, 0x154($sp)
  lwc1  $f12, 0x14($t7)
  jal   matrix_multiply_A1_by_F12
   sw    $a1, 0x58($sp)
  lw    $a0, 0x58($sp)
  lw    $a1, 0x148($sp)
  jal   sub_GAME_7F058418
   addiu $a2, $sp, 0x124
  jal   sub_GAME_7F03E864
   lw    $a0, 0xc0($sp)
  lw    $t8, 0x154($sp)
  lwc1  $f8, 0x134($sp)
  lwc1  $f10, 0x14($t8)
  mul.s $f4, $f0, $f10
  lwc1  $f10, 0x128($sp)
  sub.s $f6, $f8, $f4
  sub.s $f2, $f6, $f10
  swc1  $f2, 0xc($s1)
  b     .L7F0451C4
   swc1  $f2, 0x5c($s0)
.L7F045164:
  lwc1  $f12, 0xa0($s0)
  jal   sub_GAME_7F0585FC
   sw    $a0, 0x58($sp)
  lw    $t9, 0x154($sp)
  lw    $a1, 0x58($sp)
  jal   matrix_multiply_A1_by_F12
   lwc1  $f12, 0x14($t9)
  lw    $a0, 0x14($s1)
  lw    $a1, 8($s1)
  jal   sub_GAME_7F0B2970
   lw    $a2, 0x10($s1)
  swc1  $f0, 0x5c($sp)
  jal   sub_GAME_7F03E864
   lw    $a0, 0xc0($sp)
  lw    $t0, 0x148($sp)
  lw    $t1, 0x154($sp)
  lwc1  $f8, 4($t0)
  lwc1  $f6, 0x14($t1)
  add.s $f4, $f8, $f0
  lwc1  $f8, 0x5c($sp)
  mul.s $f10, $f4, $f6
  sub.s $f2, $f8, $f10
  swc1  $f2, 0xc($s1)
  swc1  $f2, 0x5c($s0)
.L7F0451C4:
  lw    $ra, 0x24($sp)
  lw    $v0, 0x108($sp)
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x158
");






asm(R"
glabel sub_GAME_7F0451DC
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a1, 0x1c($sp)
  sw    $a2, 0x20($sp)
  sw    $a3, 0x24($sp)
  jal   get_curplayer_positiondata
   sw    $a0, 0x18($sp)
  lw    $a0, 0x18($sp)
  lwc1  $f6, 8($v0)
  lwc1  $f10, 0xc($v0)
  lwc1  $f4, ($a0)
  lwc1  $f8, 4($a0)
  lwc1  $f18, 0x10($v0)
  sub.s $f0, $f4, $f6
  lwc1  $f16, 8($a0)
  sub.s $f2, $f8, $f10
  mul.s $f4, $f0, $f0
  sub.s $f14, $f16, $f18
  mul.s $f6, $f2, $f2
  add.s $f8, $f4, $f6
  mul.s $f10, $f14, $f14
  jal   sqrtf
   add.s $f12, $f8, $f10
  lwc1  $f12, 0x20($sp)
  lwc1  $f2, 0x1c($sp)
  lw    $ra, 0x14($sp)
  c.lt.s $f12, $f0
  nop   
  bc1fl .L7F045260
   c.lt.s $f0, $f2
  b     .L7F0452C8
   li    $v1, 255
  c.lt.s $f0, $f2
.L7F045260:
  lwc1  $f14, 0x24($sp)
  lwc1  $f16, 0x24($sp)
  li    $at, 0x3F800000 # 1.000000
  bc1fl .L7F045298
   mtc1  $at, $f10
  li    $at, 0x437F0000 # 255.000000
  mtc1  $at, $f18
  nop   
  mul.s $f4, $f16, $f18
  trunc.w.s $f6, $f4
  mfc1  $v1, $f6
  b     .L7F0452CC
   move  $v0, $v1
  mtc1  $at, $f10
.L7F045298:
  sub.s $f8, $f0, $f2
  li    $at, 0x437F0000 # 255.000000
  sub.s $f16, $f10, $f14
  sub.s $f4, $f12, $f2
  mul.s $f18, $f8, $f16
  mtc1  $at, $f8
  div.s $f6, $f18, $f4
  add.s $f10, $f6, $f14
  mul.s $f16, $f10, $f8
  trunc.w.s $f18, $f16
  mfc1  $v1, $f18
  nop   
.L7F0452C8:
  move  $v0, $v1
.L7F0452CC:
  jr    $ra
   addiu $sp, $sp, 0x18
");

#ifdef VERSION_US
asm(R"
.late_rodata
glabel rocket_initial_gravity_modifier
.word 0x3e8e38e4 /*0.27777779*/
glabel D_80052A9C
.word 0x3c360b61 /*0.011111111*/
glabel D_80052AA0
.word 0x3d8f5c29 /*0.07*/
glabel prop_projectile_gravity_modifier
.word 0x3e8e38e4 /*0.27777779*/
glabel D_80052AA8
.word 0x400e38e4 /*2.2222223*/
glabel D_80052AAC
.word 0x46d9038c /*27777.773*/
glabel D_80052AB0
.word 0x3f8ccccd /*1.1*/
glabel D_80052AB4
.word 0x3f666666 /*0.89999998*/
glabel D_80052AB8
.word 0x3f666666 /*0.89999998*/
glabel D_80052ABC
.word 0x3dcccccd /*0.1*/
glabel D_80052AC0
.word 0xbdcccccd /*-0.1*/
glabel D_80052AC4
.word 0xbdcccccd /*-0.1*/
glabel D_80052AC8
.word 0x40c90fdb /*6.2831855*/
glabel D_80052ACC
.word 0x40c90fdb /*6.2831855*/
glabel D_80052AD0
.word 0x40490fdb /*3.1415927*/
glabel D_80052AD4
.word 0x3f490fdb /*0.78539819*/
glabel D_80052AD8
.word 0xbf490fdb /*-0.78539819*/
glabel D_80052ADC
.word 0x40c90fdb /*6.2831855*/
glabel D_80052AE0
.word 0x3a2b92a6 /*0.00065449846*/
glabel D_80052AE4
.word 0x3a2b92a6 /*0.00065449846*/
glabel D_80052AE8
.word 0x40c90fdb /*6.2831855*/
glabel D_80052AEC
.word 0x37433637 /*0.000011635529*/
glabel D_80052AF0
.word 0x40c90fdb /*6.2831855*/
glabel D_80052AF4
.word 0x3a3702d4 /*0.00069813174*/
glabel D_80052AF8
.word 0x36c33637 /*0.0000058177643*/
glabel D_80052AFC
.word 0x39b702d4 /*0.00034906587*/
glabel D_80052B00
.word 0x40c90fdb /*6.2831855*/
glabel D_80052B04
.word 0x40c90fdb /*6.2831855*/
glabel D_80052B08
.word 0x40c90fdb /*6.2831855*/
glabel D_80052B0C
.word 0x40490fdb /*3.1415927*/
glabel D_80052B10
.word 0x3f9c61ab /*1.2217306*/
glabel D_80052B14
.word 0xbf9c61ab /*-1.2217306*/
glabel D_80052B18
.word 0xc0490fdb /*-3.1415927*/
glabel D_80052B1C
.word 0x40490fdb /*3.1415927*/
glabel D_80052B20
.word 0x40c90fdb /*6.2831855*/
glabel D_80052B24
.word 0x3f4ccccd /*0.80000001*/
glabel D_80052B28
.word 0xc0490fdb /*-3.1415927*/
glabel D_80052B2C
.word 0x40490fdb /*3.1415927*/
glabel D_80052B30
.word 0x3a64c389 /*0.00087266468*/
glabel D_80052B34
.word 0x3a64c389 /*0.00087266468*/
glabel D_80052B38
.word 0x40490fdb /*3.1415927*/
glabel D_80052B3C
.word 0x3f1930a7 /*0.59839863*/
glabel D_80052B40
.word 0x3c236719 /*0.0099733109*/
glabel D_80052B44
.word 0x3f7d70a4 /*0.99000001*/
glabel D_80052B48
.word 0x38d1b717 /*0.000099999997*/
glabel D_80052B4C
.word 0x3964c389 /*0.00021816617*/
glabel D_80052B50
.word 0x3bd67750 /*0.0065449849*/
glabel D_80052B54
.word 0x40c90fdb /*6.2831855*/
glabel D_80052B58
.word 0x3964c389 /*0.00021816617*/
glabel D_80052B5C
.word 0xb964c389 /*-0.00021816617*/
glabel D_80052B60
.word 0x40c90fdb /*6.2831855*/
glabel D_80052B64
.word 0x40c90fdb /*6.2831855*/
glabel D_80052B68
.word 0x3e99999a /*0.30000001*/
glabel D_80052B6C
.word 0x3fc90fdb /*1.5707964*/
glabel D_80052B70
.word 0x3fc90fdb /*1.5707964*/
glabel D_80052B74
.word 0x3e23d70a /*0.16*/
glabel D_80052B78
.word 0x461c4000 /*10000.0*/
glabel D_80052B7C
.word 0x453b8000 /*3000.0*/
glabel D_80052B80
.word 0x3f19999a /*0.60000002*/
glabel D_80052B84
.word 0x3e99999a /*0.30000001*/
glabel D_80052B88
.word 0xbdcccccd /*-0.1*/
glabel D_80052B8C
.word 0x3e4ccccd /*0.2*/
glabel D_80052B90
.word 0x453b8000 /*3000.0*/
glabel D_80052B94
.word 0x453b8000 /*3000.0*/

.text
glabel object_interaction
  addiu $sp, $sp, -0x6a8
  sw    $ra, 0x54($sp)
  sw    $s4, 0x50($sp)
  sw    $s3, 0x4c($sp)
  sw    $s2, 0x48($sp)
  sw    $s1, 0x44($sp)
  sw    $s0, 0x40($sp)
  sdc1  $f22, 0x38($sp)
  sdc1  $f20, 0x30($sp)
  lw    $s1, 4($a0)
  mtc1  $zero, $f22
  move  $s3, $a0
  lw    $s4, 0x14($s1)
  sw    $zero, 0x690($sp)
  sw    $zero, 0x680($sp)
  jal   getPlayerCount
   swc1  $f22, 0x67c($sp)
  li    $t4, 1
  sw    $v0, 0x674($sp)
  sw    $t4, 0x670($sp)
  lw    $v1, 0x64($s1)
  andi  $t6, $v1, 4
  beqz  $t6, .L7F045354
   andi  $t7, $v1, 8
  lbu   $a2, 2($s1)
  move  $a0, $s1
  move  $a1, $zero
  andi  $t5, $a2, 4
  jal   sub_GAME_7F040D98
   move  $a2, $t5
  b     .L7F049B30
   li    $v0, 1
.L7F045354:
  beqz  $t7, .L7F04536C
   andi  $t0, $v1, 0x80
  li    $at, -9
  and   $t8, $v1, $at
  b     .L7F045394
   sw    $t8, 0x64($s1)
.L7F04536C:
  beql  $t0, $zero, .L7F045398
   li    $at, 1
  lbu   $t1, 1($s3)
  li    $v0, 3
  andi  $t3, $t1, 0xfffd
  sb    $t3, 1($s3)
  lw    $t9, 0x64($s1)
  ori   $t2, $t9, 8
  b     .L7F049B30
   sw    $t2, 0x64($s1)
.L7F045394:
  li    $at, 1
.L7F045398:
  bne   $v0, $at, .L7F0453A8
   li    $t4, 1
  b     .L7F0453F8
   sw    $t4, 0x678($sp)
.L7F0453A8:
  jal   get_cur_playernum
   nop   
  jal   sub_GAME_7F09B4D8
   move  $a0, $v0
  sltiu $t6, $v0, 1
  sw    $t6, 0x678($sp)
  lw    $t5, 0x64($s1)
  andi  $t7, $t5, 0x80
  beql  $t7, $zero, .L7F0453FC
   lw    $t3, 0x678($sp)
  lw    $v0, 0x6c($s1)
  lui   $t8, %hi(pPlayer) 
  lw    $v1, 0x88($v0)
  beql  $v1, $zero, .L7F0453FC
   lw    $t3, 0x678($sp)
  lw    $t8, %lo(pPlayer)($t8)
  lw    $t0, 0xa8($t8)
  xor   $t1, $t0, $v1
  sltiu $t1, $t1, 1
  sw    $t1, 0x678($sp)
.L7F0453F8:
  lw    $t3, 0x678($sp)
.L7F0453FC:
  beql  $t3, $zero, .L7F048230
   lbu   $v0, 3($s1)
  lw    $t9, 0x64($s1)
  andi  $t2, $t9, 0x80
  beql  $t2, $zero, .L7F04661C
   lw    $t5, 0x690($sp)
  lw    $s0, 0x6c($s1)
  lui   $t6, %hi(clock_timer) 
  lw    $t6, %lo(clock_timer)($t6)
  lw    $t4, 0xe0($s0)
  addu  $t5, $t4, $t6
  slti  $at, $t5, 0x961
  bnez  $at, .L7F045440
   sw    $t5, 0xe0($s0)
  lw    $t8, 0x64($s1)
  ori   $t0, $t8, 4
  sw    $t0, 0x64($s1)
.L7F045440:
  lw    $t1, ($s0)
  andi  $t3, $t1, 0x100
  beql  $t3, $zero, .L7F045508
   lwc1  $f6, 0x58($s1)
  lbu   $t9, 3($s1)
  li    $at, 8
  li    $s2, 1
  bnel  $t9, $at, .L7F045480
   lw    $a0, 0x88($s0)
  sw    $s1, 0x648($sp)
  lb    $t2, 0x80($s1)
  li    $at, 86
  bnel  $t2, $at, .L7F045480
   lw    $a0, 0x88($s0)
  move  $s2, $zero
  lw    $a0, 0x88($s0)
.L7F045480:
  beql  $a0, $zero, .L7F045494
   move  $a0, $s1
  jal   sub_GAME_7F03D058
   move  $a1, $zero
  move  $a0, $s1
.L7F045494:
  addiu $a1, $s0, 0xd4
  addiu $a2, $sp, 0x64c
  addiu $a3, $sp, 0x658
  sw    $zero, 0x10($sp)
  jal   sub_GAME_7F042EB4
   sw    $s2, 0x14($sp)
  sw    $v0, 0x664($sp)
  lw    $a0, 0x88($s0)
  beql  $a0, $zero, .L7F0454C8
   lw    $t4, 0x664($sp)
  jal   sub_GAME_7F03D058
   li    $a1, 1
  lw    $t4, 0x664($sp)
.L7F0454C8:
  li    $at, 1
  lw    $v0, 0x648($sp)
  beql  $t4, $at, .L7F0454F8
   lw    $t5, ($s0)
  beql  $v0, $zero, .L7F0454F8
   lw    $t5, ($s0)
  lb    $t6, 0x80($v0)
  li    $at, 86
  bnel  $t6, $at, .L7F0454F8
   lw    $t5, ($s0)
  sh    $zero, 0x82($v0)
  lw    $t5, ($s0)
.L7F0454F8:
  li    $at, -257
  and   $t7, $t5, $at
  sw    $t7, ($s0)
  lwc1  $f6, 0x58($s1)
.L7F045508:
  lui   $t8, %hi(clock_timer) 
  lui   $at, 0x3f80
  swc1  $f6, 0x694($sp)
  lwc1  $f10, 0x5c($s1)
  swc1  $f10, 0x698($sp)
  lwc1  $f4, 0x60($s1)
  swc1  $f4, 0x69c($sp)
  lw    $v0, 0xbc($s0)
  blezl $v0, .L7F045540
   lw    $t1, 0x6c($s1)
  lw    $t8, %lo(clock_timer)($t8)
  subu  $t0, $v0, $t8
  sw    $t0, 0xbc($s0)
  lw    $t1, 0x6c($s1)
.L7F045540:
  lw    $t3, ($t1)
  andi  $t9, $t3, 1
  beql  $t9, $zero, .L7F046290
   lwc1  $f0, 0x60($s0)
  jal   sub_GAME_7F040078
   move  $a0, $s1
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  lui   $a3, %hi(clock_timer)
  addiu $a3, %lo(clock_timer) # addiu $a3, $a3, -0x7c8c
  sw    $v0, 0x640($sp)
  sw    $zero, 0x610($sp)
  sw    $zero, 0x60c($sp)
  sw    $zero, 0x604($sp)
  swc1  $f8, 0x638($sp)
  lw    $t2, 0xa8($s0)
  lw    $t4, ($a3)
  lwc1  $f20, 0x5c($s1)
  move  $s2, $zero
  addu  $t6, $t2, $t4
  sw    $t6, 0xa8($s0)
  lwc1  $f6, 0x18($s1)
  lui   $at, %hi(rocket_initial_gravity_modifier)
  swc1  $f6, 0x62c($sp)
  lwc1  $f10, 0x1c($s1)
  swc1  $f10, 0x630($sp)
  lwc1  $f4, 0x20($s1)
  swc1  $f4, 0x634($sp)
  lw    $v1, ($s0)
  andi  $t5, $v1, 0x20
  beqz  $t5, .L7F0456E8
   nop   
  lwc1  $f18, %lo(rocket_initial_gravity_modifier)($at)
  lwc1  $f0, 0x1c($s0)
  lui   $v0, %hi(global_timer_delta)
  addiu $v0, %lo(global_timer_delta) # addiu $v0, $v0, -0x7c88
  c.lt.s $f0, $f18
  nop   
  bc1fl .L7F04564C
   lwc1  $f0, 0xb0($s0)
  lwc1  $f8, 0x14($s0)
  lwc1  $f6, ($v0)
  lwc1  $f4, 0xb4($s0)
  lui   $at, %hi(D_80052A9C)
  mul.s $f10, $f8, $f6
  add.s $f8, $f4, $f10
  swc1  $f8, 0xb4($s0)
  lwc1  $f4, ($v0)
  lwc1  $f6, 0xb4($s0)
  lwc1  $f8, 0xb0($s0)
  mul.s $f10, $f6, $f4
  add.s $f6, $f8, $f10
  swc1  $f6, 0xb0($s0)
  lwc1  $f8, ($v0)
  lwc1  $f4, %lo(D_80052A9C)($at)
  mul.s $f10, $f4, $f8
  add.s $f6, $f0, $f10
  swc1  $f6, 0x1c($s0)
  lwc1  $f4, 0x1c($s0)
  c.lt.s $f18, $f4
  nop   
  bc1f  .L7F045640
   nop   
  swc1  $f18, 0x1c($s0)
.L7F045640:
  b     .L7F0456E8
   lw    $v1, ($s0)
  lwc1  $f0, 0xb0($s0)
.L7F04564C:
  lwc1  $f8, 0x698($sp)
  c.lt.s $f8, $f0
  nop   
  bc1f  .L7F0456C0
   lui   $at, %hi(global_timer_delta)
  lwc1  $f6, %lo(global_timer_delta)($at)
  lwc1  $f10, 0x14($s0)
  lwc1  $f8, 0xb4($s0)
  mul.s $f4, $f10, $f6
  add.s $f10, $f8, $f4
  swc1  $f10, 0xb4($s0)
  lwc1  $f8, %lo(global_timer_delta)($at)
  lwc1  $f6, 0xb4($s0)
  lui   $at, %hi(D_80052AA0)
  mul.s $f4, $f6, $f8
  add.s $f10, $f0, $f4
  swc1  $f10, 0xb0($s0)
  lwc1  $f8, 0x698($sp)
  lwc1  $f6, 0xb0($s0)
  lwc1  $f10, %lo(D_80052AA0)($at)
  lui   $at, %hi(global_timer_delta)
  sub.s $f4, $f6, $f8
  mul.s $f6, $f10, $f4
  lwc1  $f10, %lo(global_timer_delta)($at)
  mul.s $f4, $f6, $f10
  add.s $f6, $f8, $f4
  swc1  $f6, 0x698($sp)
  b     .L7F0456E8
   lw    $v1, ($s0)
.L7F0456C0:
  swc1  $f0, 0x698($sp)
  lw    $t7, ($s0)
  li    $at, -33
  lwc1  $f10, 0xb4($s0)
  and   $t8, $t7, $at
  sw    $t8, ($s0)
  ori   $v1, $t8, 0x10
  swc1  $f22, 0x1c($s0)
  sw    $v1, ($s0)
  swc1  $f10, 8($s0)
.L7F0456E8:
  lui   $v0, %hi(global_timer_delta)
  addiu $v0, %lo(global_timer_delta) # addiu $v0, $v0, -0x7c88
  lui   $at, %hi(prop_projectile_gravity_modifier)
  andi  $t3, $v1, 0x10
  lwc1  $f18, %lo(prop_projectile_gravity_modifier)($at)
  lwc1  $f2, ($v0)
  lwc1  $f0, 0x1c($s0)
  bnez  $t3, .L7F04575C
   lwc1  $f16, 0x14($s0)
  add.s $f4, $f16, $f0
  lwc1  $f8, 8($s0)
  li    $at, 0x3F000000 # 0.500000
  mul.s $f6, $f4, $f2
  add.s $f10, $f8, $f6
  swc1  $f10, 8($s0)
  lwc1  $f2, ($v0)
  lwc1  $f12, 8($s0)
  mtc1  $at, $f10
  mul.s $f4, $f18, $f2
  sub.s $f14, $f12, $f4
  add.s $f8, $f12, $f14
  mul.s $f6, $f2, $f8
  lwc1  $f8, 0x698($sp)
  mul.s $f4, $f6, $f10
  add.s $f6, $f8, $f4
  swc1  $f6, 0x698($sp)
  swc1  $f14, 8($s0)
  b     .L7F045788
   lwc1  $f2, ($v0)
.L7F04575C:
  add.s $f8, $f16, $f0
  lwc1  $f10, 8($s0)
  mul.s $f4, $f8, $f2
  add.s $f6, $f10, $f4
  swc1  $f6, 8($s0)
  lwc1  $f10, 8($s0)
  lwc1  $f2, ($v0)
  lwc1  $f8, 0x698($sp)
  mul.s $f4, $f10, $f2
  add.s $f6, $f8, $f4
  swc1  $f6, 0x698($sp)
.L7F045788:
  lwc1  $f8, 0x10($s0)
  lwc1  $f10, 4($s0)
  addiu $a0, $s1, 0x18
  mul.s $f4, $f8, $f2
  lwc1  $f8, 0x18($s0)
  addiu $a1, $s0, 0x20
  add.s $f6, $f10, $f4
  swc1  $f6, 4($s0)
  lwc1  $f10, ($v0)
  lwc1  $f6, 0xc($s0)
  mul.s $f4, $f8, $f10
  add.s $f8, $f6, $f4
  lwc1  $f6, 4($s0)
  swc1  $f8, 0xc($s0)
  lwc1  $f2, ($v0)
  lwc1  $f10, 0x694($sp)
  lw    $a2, ($a3)
  mul.s $f4, $f6, $f2
  lwc1  $f6, 0x69c($sp)
  add.s $f8, $f10, $f4
  swc1  $f8, 0x694($sp)
  lwc1  $f10, 0xc($s0)
  sw    $a1, 0x6c($sp)
  sw    $a0, 0x70($sp)
  mul.s $f4, $f10, $f2
  add.s $f8, $f6, $f4
  jal   sub_GAME_7F057DF8
   swc1  $f8, 0x69c($sp)
  lbu   $t9, 3($s1)
  li    $at, 8
  bnel  $t9, $at, .L7F045850
   lw    $a0, 0x88($s0)
  lb    $v0, 0x80($s1)
  li    $at, 29
  beq   $v0, $at, .L7F045848
   li    $at, 27
  beq   $v0, $at, .L7F045848
   li    $at, 28
  beq   $v0, $at, .L7F045848
   li    $at, 33
  beq   $v0, $at, .L7F045848
   li    $at, 47
  beq   $v0, $at, .L7F045848
   li    $at, 48
  beq   $v0, $at, .L7F045848
   li    $at, 34
  bnel  $v0, $at, .L7F045850
   lw    $a0, 0x88($s0)
.L7F045848:
  li    $s2, 1
  lw    $a0, 0x88($s0)
.L7F045850:
  beql  $a0, $zero, .L7F045864
   move  $a0, $s1
  jal   sub_GAME_7F03D058
   move  $a1, $zero
  move  $a0, $s1
.L7F045864:
  addiu $a1, $sp, 0x694
  addiu $a2, $sp, 0x614
  addiu $a3, $sp, 0x620
  sw    $s2, 0x10($sp)
  jal   sub_GAME_7F042EB4
   sw    $zero, 0x14($sp)
  sw    $v0, 0x664($sp)
  lw    $a0, 0x88($s0)
  beql  $a0, $zero, .L7F045898
   lw    $t4, 0x664($sp)
  jal   sub_GAME_7F03D058
   li    $a1, 1
  lw    $t4, 0x664($sp)
.L7F045898:
  li    $t2, 1
  li    $at, 2
  bne   $t4, $at, .L7F0459AC
   sw    $t2, 0x690($sp)
  lui   $v1, %hi(D_80030B0C)
  lw    $v1, %lo(D_80030B0C)($v1)
  beqz  $v1, .L7F0458D0
   nop   
  lbu   $v0, ($v1)
  li    $at, 3
  beq   $v0, $at, .L7F0459AC
   li    $at, 6
  beql  $v0, $at, .L7F0459B0
   lw    $t4, 0x604($sp)
.L7F0458D0:
  beqz  $v1, .L7F0458F0
   move  $a0, $zero
  lw    $v0, 4($v1)
  lw    $t6, 0x64($v0)
  andi  $t5, $t6, 0x80
  beqz  $t5, .L7F0458F0
   nop   
  li    $a0, 1
.L7F0458F0:
  bnezl $a0, .L7F0459B0
   lw    $t4, 0x604($sp)
  jal   sub_GAME_7F03FB70
   move  $a0, $s0
  lw    $t7, 0x64($s1)
  li    $at, -129
  sw    $zero, 0x6c($s1)
  and   $t8, $t7, $at
  sw    $t8, 0x64($s1)
  lbu   $v0, 1($s3)
  lui   $a0, %hi(ptr_sfx_buf)
  li    $a1, 241
  andi  $t0, $v0, 8
  beqz  $t0, .L7F045934
   move  $a2, $zero
  ori   $t1, $v0, 0x10
  sb    $t1, 1($s3)
.L7F045934:
  jal   play_sfx_a1
   lw    $a0, %lo(ptr_sfx_buf)($a0)
  move  $a0, $v0
  jal   sub_GAME_7F053A10
   addiu $a1, $s3, 8
  lw    $t3, 0x14($s3)
  lb    $a0, 0x80($s1)
  jal   sub_GAME_7F0577E8
   lbu   $a1, 3($t3)
  move  $a0, $s1
  addiu $a1, $sp, 0x614
  lw    $a2, 0x14($s3)
  jal   sub_GAME_7F0439B8
   addiu $a3, $sp, 0x620
  lui   $a1, %hi(D_80030B0C)
  lw    $a1, %lo(D_80030B0C)($a1)
  move  $a0, $s3
  lui   $a2, %hi(objinst)
  beqz  $a1, .L7F0459AC
   lui   $a3, %hi(dword_CODE_bss_80075B74)
  lw    $s2, 0x14($s3)
  lw    $a2, %lo(objinst)($a2)
  jal   sub_GAME_7F043A6C
   lw    $a3, %lo(dword_CODE_bss_80075B74)($a3)
  beqz  $v0, .L7F0459AC
   li    $t9, 5
  sw    $s2, 0x14($s3)
  li    $t2, 1
  sw    $t9, 0x680($sp)
  sw    $t2, 0x604($sp)
.L7F0459AC:
  lw    $t4, 0x604($sp)
.L7F0459B0:
  bnez  $t4, .L7F045D64
   lui   $s2, %hi(D_80030B0C)
  lw    $s2, %lo(D_80030B0C)($s2)
  beql  $s2, $zero, .L7F045D68
   lw    $t4, 0x604($sp)
  lbu   $t6, 3($s1)
  li    $at, 8
  bnel  $t6, $at, .L7F045D68
   lw    $t4, 0x604($sp)
  lb    $v0, 0x80($s1)
  li    $at, 3
  bnel  $v0, $at, .L7F045CEC
   li    $at, 86
  lbu   $v0, ($s2)
  li    $at, 3
  beq   $v0, $at, .L7F045A24
   li    $at, 6
  bnel  $v0, $at, .L7F045D68
   lw    $t4, 0x604($sp)
  lw    $t5, 4($s2)
  beql  $t5, $zero, .L7F045D68
   lw    $t4, 0x604($sp)
  jal   sub_GAME_7F09B15C
   move  $a0, $s2
  jal   get_cur_playernum
   move  $s2, $v0
  beq   $v0, $s2, .L7F045D64
   lui   $s2, %hi(D_80030B0C)
  lw    $s2, %lo(D_80030B0C)($s2)
.L7F045A24:
  lw    $v0, 0x6c($s1)
  lw    $a0, 4($s2)
  lw    $t7, ($v0)
  andi  $t8, $t7, 1
  beql  $t8, $zero, .L7F045D68
   lw    $t4, 0x604($sp)
  lw    $t0, 0x90($v0)
  bgtzl $t0, .L7F045D68
   lw    $t4, 0x604($sp)
  lw    $t1, 0x64($s1)
  lui   $a2, %hi(flt_CODE_bss_80075B78)
  addiu $a2, %lo(flt_CODE_bss_80075B78) # addiu $a2, $a2, 0x5b78
  andi  $t3, $t1, 0x20
  beqz  $t3, .L7F045D64
   lui   $a1, %hi(bodypartshot)
  lb    $a3, 0x80($s1)
  li    $t9, 1
  sw    $t9, 0x10($sp)
  jal   handles_shot_actors
   lw    $a1, %lo(bodypartshot)($a1)
  beqz  $v0, .L7F045D64
   li    $t2, 1
  sw    $t2, 0x604($sp)
  lwc1  $f16, 0x8c($s0)
  lwc1  $f10, 0x620($sp)
  c.lt.s $f22, $f16
  nop   
  bc1fl .L7F045B08
   lw    $t4, ($s0)
  lwc1  $f2, 4($s0)
  lwc1  $f12, 8($s0)
  lwc1  $f4, 0x624($sp)
  mul.s $f6, $f2, $f10
  lwc1  $f0, 0xc($s0)
  li    $at, 0x3F800000 # 1.000000
  mul.s $f8, $f12, $f4
  add.s $f4, $f6, $f8
  lwc1  $f6, 0x628($sp)
  mul.s $f8, $f6, $f0
  mtc1  $at, $f6
  add.s $f14, $f8, $f4
  add.s $f8, $f16, $f6
  neg.s $f4, $f8
  mul.s $f14, $f14, $f4
  nop   
  mul.s $f6, $f14, $f10
  add.s $f8, $f2, $f6
  swc1  $f8, 4($s0)
  lwc1  $f4, 0x624($sp)
  mul.s $f10, $f14, $f4
  add.s $f6, $f12, $f10
  swc1  $f6, 8($s0)
  lwc1  $f8, 0x628($sp)
  mul.s $f4, $f14, $f8
  add.s $f10, $f0, $f4
  swc1  $f10, 0xc($s0)
  lw    $t4, ($s0)
.L7F045B08:
  andi  $t6, $t4, 0x200
  bnezl $t6, .L7F045B20
   lw    $t5, 0x90($s0)
  jal   sub_GAME_7F057AC0
   lw    $a0, 0x6c($sp)
  lw    $t5, 0x90($s0)
.L7F045B20:
  lui   $a1, %hi(D_80030B0C)
  li    $a2, -1
  addiu $t7, $t5, 1
  sw    $t7, 0x90($s0)
  lw    $a1, %lo(D_80030B0C)($a1)
  jal   recall_joy2_hits_edit_detail_edit_flag
   lb    $a0, 0x80($s1)
  lui   $t8, %hi(D_80030B0C) 
  lw    $t8, %lo(D_80030B0C)($t8)
  lui   $v0, %hi(bodypartshot)
  lbu   $t0, 1($t8)
  andi  $t1, $t0, 2
  beql  $t1, $zero, .L7F045D68
   lw    $t4, 0x604($sp)
  lw    $v0, %lo(bodypartshot)($v0)
  li    $at, 100
  beq   $v0, $at, .L7F045D64
   li    $at, 110
  beq   $v0, $at, .L7F045D64
   lui   $a0, %hi(objinst)
  lui   $a1, %hi(dword_CODE_bss_80075B74)
  lw    $a1, %lo(dword_CODE_bss_80075B74)($a1)
  lw    $a0, %lo(objinst)($a0)
  jal   sub_GAME_7F06C660
   move  $a2, $zero
  lwc1  $f6, 0x614($sp)
  lwc1  $f8, 0x618($sp)
  lwc1  $f4, 0x61c($sp)
  move  $s2, $v0
  swc1  $f6, 0x5cc($sp)
  swc1  $f8, 0x5d0($sp)
  jal   get_BONDdata_field_10CC
   swc1  $f4, 0x5d4($sp)
  move  $a0, $v0
  jal   sub_GAME_7F058474
   addiu $a1, $sp, 0x5cc
  lwc1  $f10, 0x5cc($sp)
  lwc1  $f6, 0x30($s2)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f0
  sub.s $f8, $f10, $f6
  lui   $a0, %hi(objinst)
  lui   $a1, %hi(dword_CODE_bss_80075B74)
  lw    $a1, %lo(dword_CODE_bss_80075B74)($a1)
  mul.s $f4, $f8, $f0
  lwc1  $f8, 0x5d0($sp)
  lw    $a0, %lo(objinst)($a0)
  add.s $f6, $f10, $f4
  swc1  $f6, 0x5cc($sp)
  lwc1  $f10, 0x34($s2)
  sub.s $f4, $f8, $f10
  mul.s $f6, $f4, $f0
  lwc1  $f4, 0x5d4($sp)
  add.s $f10, $f8, $f6
  swc1  $f10, 0x5d0($sp)
  lwc1  $f8, 0x38($s2)
  sub.s $f6, $f4, $f8
  mul.s $f10, $f6, $f0
  add.s $f8, $f4, $f10
  jal   getjointsize
   swc1  $f8, 0x5d4($sp)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f6
  lui   $at, %hi(flt_CODE_bss_80075B88)
  lwc1  $f10, %lo(flt_CODE_bss_80075B88)($at)
  mul.s $f4, $f0, $f6
  lwc1  $f6, 0x5cc($sp)
  lui   $a0, %hi(objinst)
  lui   $a1, %hi(dword_CODE_bss_80075B74)
  lw    $a1, %lo(dword_CODE_bss_80075B74)($a1)
  lw    $a0, %lo(objinst)($a0)
  mul.s $f8, $f4, $f10
  sub.s $f4, $f6, $f8
  jal   getjointsize
   swc1  $f4, 0x5cc($sp)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f10
  lui   $at, %hi(flt_CODE_bss_80075B8C)
  lwc1  $f8, %lo(flt_CODE_bss_80075B8C)($at)
  mul.s $f6, $f0, $f10
  lwc1  $f10, 0x5d0($sp)
  lui   $a0, %hi(objinst)
  lui   $a1, %hi(dword_CODE_bss_80075B74)
  lw    $a1, %lo(dword_CODE_bss_80075B74)($a1)
  lw    $a0, %lo(objinst)($a0)
  mul.s $f4, $f6, $f8
  sub.s $f6, $f10, $f4
  jal   getjointsize
   swc1  $f6, 0x5d0($sp)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f8
  lui   $at, %hi(flt_CODE_bss_80075B90)
  lwc1  $f4, %lo(flt_CODE_bss_80075B90)($at)
  mul.s $f10, $f0, $f8
  lwc1  $f8, 0x5d4($sp)
  move  $a0, $s2
  addiu $a1, $sp, 0x58c
  mul.s $f6, $f10, $f4
  sub.s $f10, $f8, $f6
  jal   sub_GAME_7F059E64
   swc1  $f10, 0x5d4($sp)
  addiu $a0, $sp, 0x58c
  jal   sub_GAME_7F058474
   addiu $a1, $sp, 0x5cc
  lui   $a0, %hi(objinst)
  lui   $a1, %hi(bodypartshot)
  lui   $a2, %hi(dword_CODE_bss_80075B74)
  lw    $a2, %lo(dword_CODE_bss_80075B74)($a2)
  lw    $a1, %lo(bodypartshot)($a1)
  lw    $a0, %lo(objinst)($a0)
  jal   sub_GAME_7F0221DC
   addiu $a3, $sp, 0x5cc
  b     .L7F045D68
   lw    $t4, 0x604($sp)
  li    $at, 86
.L7F045CEC:
  bnel  $v0, $at, .L7F045D68
   lw    $t4, 0x604($sp)
  lbu   $v0, ($s2)
  li    $t3, 1
  li    $at, 3
  bne   $v0, $at, .L7F045D24
   sw    $t3, 0x604($sp)
  lw    $a0, 4($s2)
  addiu $a1, $s1, 0x58
  lui   $a2, 0x4000
  jal   sub_GAME_7F027804
   li    $a3, 1
  b     .L7F045D64
   sh    $zero, 0x82($s1)
.L7F045D24:
  li    $at, 1
  beq   $v0, $at, .L7F045D3C
   lui   $a1, 0x42c8
  li    $at, 4
  bnel  $v0, $at, .L7F045D64
   sh    $zero, 0x82($s1)
.L7F045D3C:
  lw    $v0, 0x64($s1)
  lui   $at, 6
  lw    $a0, 4($s2)
  and   $t9, $v0, $at
  srl   $t2, $t9, 0x11
  sw    $t2, 0x10($sp)
  addiu $a2, $s1, 0x58
  jal   maybe_detonate_object
   li    $a3, 86
  sh    $zero, 0x82($s1)
.L7F045D64:
  lw    $t4, 0x604($sp)
.L7F045D68:
  bnezl $t4, .L7F046198
   lw    $t2, 0x64($s1)
  lw    $t6, 0x664($sp)
  bnezl $t6, .L7F045E3C
   lw    $t7, ($s0)
  lwc1  $f16, 0x8c($s0)
  lwc1  $f4, 0x620($sp)
  c.lt.s $f22, $f16
  nop   
  bc1fl .L7F045E3C
   lw    $t7, ($s0)
  lwc1  $f2, 4($s0)
  lwc1  $f12, 8($s0)
  lwc1  $f6, 0x624($sp)
  mul.s $f8, $f2, $f4
  lwc1  $f0, 0xc($s0)
  li    $at, 0x3F800000 # 1.000000
  mul.s $f10, $f12, $f6
  c.le.s $f12, $f22
  add.s $f6, $f8, $f10
  lwc1  $f8, 0x628($sp)
  mul.s $f10, $f8, $f0
  mtc1  $at, $f8
  add.s $f14, $f10, $f6
  add.s $f10, $f16, $f8
  neg.s $f6, $f10
  mul.s $f14, $f14, $f6
  nop   
  mul.s $f8, $f14, $f4
  add.s $f10, $f2, $f8
  swc1  $f10, 4($s0)
  lwc1  $f6, 0x624($sp)
  mul.s $f4, $f14, $f6
  add.s $f8, $f12, $f4
  swc1  $f8, 8($s0)
  lwc1  $f10, 0x628($sp)
  mul.s $f6, $f14, $f10
  add.s $f4, $f0, $f6
  bc1f  .L7F045E38
   swc1  $f4, 0xc($s0)
  lwc1  $f8, 8($s0)
  li    $t5, 1
  c.le.s $f22, $f8
  nop   
  bc1tl .L7F045E38
   sw    $t5, 0x60c($sp)
  lwc1  $f10, 0x5c($s1)
  c.le.s $f20, $f10
  nop   
  bc1fl .L7F045E3C
   lw    $t7, ($s0)
  sw    $t5, 0x60c($sp)
.L7F045E38:
  lw    $t7, ($s0)
.L7F045E3C:
  lwc1  $f20, 0x63c($sp)
  andi  $t8, $t7, 8
  bnez  $t8, .L7F045E98
   nop   
  lw    $a0, 0x14($s3)
  lw    $a1, 8($s3)
  jal   sub_GAME_7F0B2970
   lw    $a2, 0x10($s3)
  mov.s $f20, $f0
  lw    $a0, 0x640($sp)
  jal   sub_GAME_7F03E9BC
   lw    $a1, 0x70($sp)
  sub.s $f4, $f20, $f0
  swc1  $f0, 0x638($sp)
  lwc1  $f6, 0xc($s3)
  move  $t0, $zero
  c.lt.s $f6, $f4
  nop   
  bc1f  .L7F045E90
   nop   
  li    $t0, 1
.L7F045E90:
  b     .L7F045E98
   sw    $t0, 0x610($sp)
.L7F045E98:
  lw    $t1, 0x610($sp)
  lw    $t3, 0x664($sp)
  bnezl $t1, .L7F045EB4
   lw    $t9, ($s0)
  bnezl $t3, .L7F045ED8
   lw    $t5, 0x610($sp)
  lw    $t9, ($s0)
.L7F045EB4:
  andi  $t2, $t9, 0x200
  bnezl $t2, .L7F045ECC
   lw    $t4, 0x90($s0)
  jal   sub_GAME_7F057AC0
   lw    $a0, 0x6c($sp)
  lw    $t4, 0x90($s0)
.L7F045ECC:
  addiu $t6, $t4, 1
  sw    $t6, 0x90($s0)
  lw    $t5, 0x610($sp)
.L7F045ED8:
  lw    $t7, 0x60c($sp)
  lw    $t8, 0x610($sp)
  bnez  $t5, .L7F045EF0
   nop   
  beql  $t7, $zero, .L7F045FD4
   lbu   $t4, 3($s1)
.L7F045EF0:
  beqz  $t8, .L7F045F18
   lwc1  $f4, 0x618($sp)
  lwc1  $f8, 0x638($sp)
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f6
  sub.s $f10, $f20, $f8
  add.s $f0, $f10, $f6
  swc1  $f0, 0xc($s3)
  b     .L7F045F34
   swc1  $f0, 0x5c($s1)
.L7F045F18:
  lwc1  $f8, 0x638($sp)
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f6
  sub.s $f10, $f4, $f8
  add.s $f2, $f10, $f6
  swc1  $f2, 0xc($s3)
  swc1  $f2, 0x5c($s1)
.L7F045F34:
  lw    $v1, 0x64($s1)
  move  $a0, $s1
  sll   $t0, $v1, 0xf
  bltz  $t0, .L7F045F4C
   ori   $t1, $v1, 0x100
  sw    $t1, 0x64($s1)
.L7F045F4C:
  lwc1  $f16, 0x8c($s0)
  c.lt.s $f22, $f16
  nop   
  bc1f  .L7F045FC8
   nop   
  lwc1  $f4, 8($s0)
  neg.s $f8, $f16
  lui   $at, %hi(D_80052AA8)
  mul.s $f10, $f4, $f8
  lwc1  $f0, %lo(D_80052AA8)($at)
  swc1  $f10, 8($s0)
  lwc1  $f6, 8($s0)
  c.lt.s $f6, $f0
  nop   
  bc1fl .L7F045FD4
   lbu   $t4, 3($s1)
  lw    $t3, ($s0)
  move  $a0, $s1
  andi  $t9, $t3, 2
  beqz  $t9, .L7F045FB8
   nop   
  lw    $t2, 0x90($s0)
  li    $at, 1
  bne   $t2, $at, .L7F045FB8
   nop   
  b     .L7F045FD0
   swc1  $f0, 8($s0)
.L7F045FB8:
  jal   sub_GAME_7F0431E4
   addiu $a1, $sp, 0x62c
  b     .L7F045FD4
   lbu   $t4, 3($s1)
.L7F045FC8:
  jal   sub_GAME_7F0431E4
   addiu $a1, $sp, 0x62c
.L7F045FD0:
  lbu   $t4, 3($s1)
.L7F045FD4:
  li    $at, 8
  bnel  $t4, $at, .L7F046198
   lw    $t2, 0x64($s1)
  lb    $v0, 0x80($s1)
  li    $at, 3
  bnel  $v0, $at, .L7F046004
   li    $at, 86
  jal   sub_GAME_7F043650
   move  $a0, $s1
  b     .L7F046104
   lw    $t8, 0x664($sp)
  li    $at, 86
.L7F046004:
  bne   $v0, $at, .L7F0460BC
   lw    $t6, 0x664($sp)
  beqz  $t6, .L7F04601C
   lw    $t5, 0x610($sp)
  beql  $t5, $zero, .L7F046028
   lwc1  $f2, 4($s0)
.L7F04601C:
  b     .L7F046100
   sh    $zero, 0x82($s1)
  lwc1  $f2, 4($s0)
.L7F046028:
  lwc1  $f12, 8($s0)
  lwc1  $f0, 0xc($s0)
  mul.s $f4, $f2, $f2
  lui    $at, %hi(D_80052AAC)
  addiu $a0, $s1, 0x58
  mul.s $f8, $f12, $f12
  li    $a2, 8
  mul.s $f6, $f0, $f0
  add.s $f10, $f4, $f8
  lwc1  $f4, %lo(D_80052AAC)($at)
  add.s $f14, $f6, $f10
  c.lt.s $f4, $f14
  nop   
  bc1fl .L7F046074
   lw    $t7, 0xa8($s0)
  swc1  $f22, 0x10($s0)
  swc1  $f22, 0x14($s0)
  swc1  $f22, 0x18($s0)
  lw    $t7, 0xa8($s0)
.L7F046074:
  slti  $at, $t7, 0x12d
  bnezl $at, .L7F04609C
   lbu   $t1, 1($s3)
  lw    $t8, ($s0)
  li    $at, -49
  swc1  $f22, 0x1c($s0)
  and   $t0, $t8, $at
  b     .L7F046100
   sw    $t0, ($s0)
  lbu   $t1, 1($s3)
.L7F04609C:
  lw    $a1, 0x14($s3)
  addiu $a3, $s3, 0x2c
  andi  $t3, $t1, 8
  sltu  $t9, $zero, $t3
  jal   sub_GAME_7F09E700
   sw    $t9, 0x10($sp)
  b     .L7F046104
   lw    $t8, 0x664($sp)
.L7F0460BC:
  li    $at, 87
  bne   $v0, $at, .L7F046100
   lw    $t2, 0x610($sp)
  bnez  $t2, .L7F0460D8
   lw    $t4, 0x60c($sp)
  beqz  $t4, .L7F0460E0
   addiu $a0, $s1, 0x58
.L7F0460D8:
  b     .L7F046100
   sh    $zero, 0x82($s1)
.L7F0460E0:
  lbu   $t6, 1($s3)
  lw    $a1, 0x14($s3)
  li    $a2, 9
  andi  $t5, $t6, 8
  sltu  $t7, $zero, $t5
  sw    $t7, 0x10($sp)
  jal   sub_GAME_7F09E700
   addiu $a3, $s3, 0x2c
.L7F046100:
  lw    $t8, 0x664($sp)
.L7F046104:
  lui   $s2, %hi(D_80048380)
  addiu $s2, %lo(D_80048380) # addiu $s2, $s2, -0x7c80
  beqz  $t8, .L7F04611C
   lw    $t0, 0x610($sp)
  beql  $t0, $zero, .L7F046198
   lw    $t2, 0x64($s1)
.L7F04611C:
  lw    $v0, ($s2)
  lw    $t1, 0xac($s0)
  addiu $t3, $v0, -2
  slt   $at, $t1, $t3
  beql  $at, $zero, .L7F046194
   sw    $v0, 0xac($s0)
  lb    $v0, 0x80($s1)
  addiu $t9, $s3, 8
  li    $at, 3
  beq   $v0, $at, .L7F046154
   sw    $t9, 0x70($sp)
  li    $at, 2
  bne   $v0, $at, .L7F046170
   lui   $a0, %hi(ptr_sfx_buf)
.L7F046154:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 3
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F046184
   move  $a0, $v0
.L7F046170:
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 45
  jal   play_sfx_a1
   move  $a2, $zero
  move  $a0, $v0
.L7F046184:
  jal   sub_GAME_7F053A10
   lw    $a1, 0x70($sp)
  lw    $v0, ($s2)
  sw    $v0, 0xac($s0)
.L7F046194:
  lw    $t2, 0x64($s1)
.L7F046198:
  lui   $s2, %hi(D_80048380)
  addiu $s2, %lo(D_80048380) # addiu $s2, $s2, -0x7c80
  andi  $t4, $t2, 0x80
  beql  $t4, $zero, .L7F04661C
   lw    $t5, 0x690($sp)
  lw    $t6, ($s0)
  andi  $t5, $t6, 0x400
  beql  $t5, $zero, .L7F04661C
   lw    $t5, 0x690($sp)
  lw    $v0, ($s2)
  li    $at, 0x43C80000 # 400.000000
  addiu $s0, $sp, 0x564
  andi  $t7, $v0, 7
  bnez  $t7, .L7F046618
   move  $a0, $zero
  mtc1  $at, $f0
  lwc1  $f8, 0x58($s1)
  li    $at, 0x44E10000 # 1800.000000
  mtc1  $at, $f4
  add.s $f6, $f8, $f0
  andi  $t8, $v0, 0xf
  swc1  $f6, 0x564($sp)
  lwc1  $f10, 0x5c($s1)
  sub.s $f8, $f10, $f4
  swc1  $f8, 0x568($sp)
  lwc1  $f6, 0x60($s1)
  bnez  $t8, .L7F046218
   swc1  $f6, 0x56c($sp)
  lwc1  $f10, 0x56c($sp)
  add.s $f4, $f10, $f0
  b     .L7F046224
   swc1  $f4, 0x56c($sp)
.L7F046218:
  lwc1  $f8, 0x56c($sp)
  sub.s $f6, $f8, $f0
  swc1  $f6, 0x56c($sp)
.L7F046224:
  lw    $v0, 0x10($s1)
  move  $a1, $s0
  li    $a3, 20
  lw    $a2, 0x14($v0)
  addiu $t0, $v0, 0x2c
  sw    $t0, 0x18($sp)
  sw    $zero, 0x1c($sp)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F09C250
   sw    $zero, 0x10($sp)
  lw    $t1, ($s2)
  li    $at, 40
  move  $a0, $s0
  div   $zero, $t1, $at
  mfhi  $t3
  bnezl $t3, .L7F04661C
   lw    $t5, 0x690($sp)
  lw    $v0, 0x10($s1)
  li    $t9, 1
  li    $a2, 10
  lw    $a1, 0x14($v0)
  sw    $t9, 0x10($sp)
  jal   sub_GAME_7F09E700
   addiu $a3, $v0, 0x2c
  b     .L7F04661C
   lw    $t5, 0x690($sp)
  lwc1  $f0, 0x60($s0)
.L7F046290:
  mtc1  $at, $f10
  li    $s2, 1
  lui   $at, %hi(global_timer_delta)
  c.lt.s $f0, $f10
  addiu $a0, $s0, 0x68
  addiu $a1, $s0, 0x78
  bc1fl .L7F046370
   lwc1  $f10, 4($s0)
  lwc1  $f2, 0x64($s0)
  lwc1  $f4, %lo(global_timer_delta)($at)
  lui   $t2, %hi(clock_timer) 
  lui   $at, %hi(D_80052AB0)
  mul.s $f8, $f2, $f4
  addiu $s2, $sp, 0x550
  add.s $f6, $f0, $f8
  swc1  $f6, 0x60($s0)
  lw    $t2, %lo(clock_timer)($t2)
  blezl $t2, .L7F0462EC
   li    $at, 0x3F800000 # 1.000000
  lwc1  $f10, %lo(D_80052AB0)($at)
  mul.s $f4, $f2, $f10
  swc1  $f4, 0x64($s0)
  li    $at, 0x3F800000 # 1.000000
.L7F0462EC:
  mtc1  $at, $f8
  lwc1  $f0, 0x60($s0)
  li    $at, 0x3F800000 # 1.000000
  c.lt.s $f8, $f0
  nop   
  bc1tl .L7F04631C
   mtc1  $at, $f6
  lw    $t4, ($s0)
  andi  $t6, $t4, 8
  beql  $t6, $zero, .L7F04632C
   mfc1  $a2, $f0
  mtc1  $at, $f6
.L7F04631C:
  nop   
  swc1  $f6, 0x60($s0)
  lwc1  $f0, 0x60($s0)
  mfc1  $a2, $f0
.L7F04632C:
  jal   sub_GAME_7F05BA08
   move  $a3, $s2
  addiu $a1, $s1, 0x18
  sw    $a1, 0x70($sp)
  jal   sub_GAME_7F05B628
   move  $a0, $s2
  lwc1  $f12, 0xc0($s0)
  jal   sub_GAME_7F0589B4
   lw    $a1, 0x70($sp)
  lwc1  $f12, 0xc4($s0)
  jal   sub_GAME_7F0589E4
   lw    $a1, 0x70($sp)
  lwc1  $f12, 0xc8($s0)
  jal   sub_GAME_7F058A4C
   lw    $a1, 0x70($sp)
  move  $s2, $zero
  lwc1  $f10, 4($s0)
.L7F046370:
  c.eq.s $f22, $f10
  nop   
  bc1fl .L7F0463B8
   lw    $t5, ($s0)
  lwc1  $f4, 0xc($s0)
  li    $at, 0x3F800000 # 1.000000
  c.eq.s $f22, $f4
  nop   
  bc1fl .L7F0463B8
   lw    $t5, ($s0)
  lwc1  $f8, 0x60($s0)
  mtc1  $at, $f6
  nop   
  c.lt.s $f8, $f6
  nop   
  bc1f  .L7F0465D0
   nop   
  lw    $t5, ($s0)
.L7F0463B8:
  move  $a0, $s1
  addiu $t8, $s1, 0x18
  andi  $t7, $t5, 8
  bnez  $t7, .L7F0465D0
   nop   
  sw    $t8, 0x70($sp)
  jal   sub_GAME_7F040078
   move  $s2, $zero
  lui   $v1, %hi(clock_timer)
  lw    $v1, %lo(clock_timer)($v1)
  sw    $v0, 0x54c($sp)
  move  $a0, $zero
  blez  $v1, .L7F04650C
   lui   $at, %hi(D_80052AB4)
  lwc1  $f14, %lo(D_80052AB4)($at)
  lwc1  $f10, 0x694($sp)
.L7F0463F8:
  lwc1  $f4, 4($s0)
  lwc1  $f6, 0x69c($sp)
  li    $at, 0x3F800000 # 1.000000
  add.s $f8, $f10, $f4
  swc1  $f8, 0x694($sp)
  lwc1  $f10, 0xc($s0)
  add.s $f4, $f6, $f10
  mtc1  $at, $f6
  swc1  $f4, 0x69c($sp)
  lwc1  $f8, 0x60($s0)
  c.le.s $f6, $f8
  nop   
  bc1fl .L7F046500
   addiu $a0, $a0, 1
  lwc1  $f10, 0x94($s0)
  c.lt.s $f22, $f10
  nop   
  bc1fl .L7F0464DC
   lwc1  $f6, 4($s0)
  lwc1  $f0, 0xc($s0)
  lwc1  $f2, 4($s0)
  sw    $a0, 0x548($sp)
  mul.s $f4, $f0, $f0
  nop   
  mul.s $f8, $f2, $f2
  jal   sqrtf
   add.s $f12, $f4, $f8
  lui   $at, %hi(D_80052AB8)
  lwc1  $f14, %lo(D_80052AB8)($at)
  lui   $at, %hi(global_timer_delta)
  lwc1  $f10, %lo(global_timer_delta)($at)
  lwc1  $f6, 0x94($s0)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  mul.s $f4, $f6, $f10
  lw    $a0, 0x548($sp)
  lui   $v1, %hi(clock_timer)
  div.s $f12, $f4, $f0
  c.le.s $f8, $f12
  nop   
  bc1fl .L7F0464B0
   lwc1  $f2, 4($s0)
  swc1  $f22, 4($s0)
  b     .L7F0464D0
   swc1  $f22, 0xc($s0)
  lwc1  $f2, 4($s0)
.L7F0464B0:
  lwc1  $f0, 0xc($s0)
  mul.s $f6, $f2, $f12
  nop   
  mul.s $f4, $f0, $f12
  sub.s $f10, $f2, $f6
  sub.s $f8, $f0, $f4
  swc1  $f10, 4($s0)
  swc1  $f8, 0xc($s0)
.L7F0464D0:
  b     .L7F0464FC
   lw    $v1, %lo(clock_timer)($v1)
  lwc1  $f6, 4($s0)
.L7F0464DC:
  lwc1  $f4, 0xc($s0)
  lui   $v1, %hi(clock_timer)
  mul.s $f10, $f6, $f14
  nop   
  mul.s $f8, $f4, $f14
  swc1  $f10, 4($s0)
  swc1  $f8, 0xc($s0)
  lw    $v1, %lo(clock_timer)($v1)
.L7F0464FC:
  addiu $a0, $a0, 1
.L7F046500:
  slt   $at, $a0, $v1
  bnezl $at, .L7F0463F8
   lwc1  $f10, 0x694($sp)
.L7F04650C:
  move  $a0, $s1
  addiu $a1, $sp, 0x694
  addiu $a2, $sp, 0x530
  addiu $a3, $sp, 0x53c
  sw    $zero, 0x10($sp)
  jal   sub_GAME_7F042EB4
   sw    $zero, 0x14($sp)
  li    $t0, 1
  sw    $t0, 0x690($sp)
  lw    $a2, 0x10($s3)
  lw    $a1, 8($s3)
  jal   sub_GAME_7F0B2970
   lw    $a0, 0x14($s3)
  mov.s $f20, $f0
  lw    $a0, 0x54c($sp)
  jal   sub_GAME_7F03E9BC
   lw    $a1, 0x70($sp)
  lui   $at, %hi(D_80052ABC)
  lwc1  $f14, %lo(D_80052ABC)($at)
  sub.s $f6, $f20, $f0
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f10
  lui   $at, %hi(D_80052AC0)
  add.s $f12, $f6, $f10
  swc1  $f12, 0xc($s3)
  swc1  $f12, 0x5c($s1)
  lwc1  $f2, 4($s0)
  c.lt.s $f2, $f14
  nop   
  bc1f  .L7F0465D0
   nop   
  lwc1  $f4, %lo(D_80052AC0)($at)
  c.lt.s $f4, $f2
  nop   
  bc1f  .L7F0465D0
   nop   
  lwc1  $f0, 0xc($s0)
  lui   $at, %hi(D_80052AC4)
  c.lt.s $f0, $f14
  nop   
  bc1f  .L7F0465D0
   nop   
  lwc1  $f8, %lo(D_80052AC4)($at)
  c.lt.s $f8, $f0
  nop   
  bc1f  .L7F0465D0
   nop   
  swc1  $f22, 0xc($s0)
  swc1  $f22, 4($s0)
.L7F0465D0:
  bnez  $s2, .L7F0465E8
   nop   
  lw    $t1, ($s0)
  andi  $t3, $t1, 8
  beql  $t3, $zero, .L7F04661C
   lw    $t5, 0x690($sp)
.L7F0465E8:
  jal   sub_GAME_7F03FB70
   move  $a0, $s0
  lw    $t9, 0x64($s1)
  li    $at, -129
  sw    $zero, 0x6c($s1)
  and   $t2, $t9, $at
  sw    $t2, 0x64($s1)
  lbu   $v0, 1($s3)
  andi  $t4, $v0, 8
  beqz  $t4, .L7F046618
   ori   $t6, $v0, 0x10
  sb    $t6, 1($s3)
.L7F046618:
  lw    $t5, 0x690($sp)
.L7F04661C:
  beqz  $t5, .L7F04664C
   addiu $t7, $s1, 0x58
  sw    $t7, 0x70($sp)
  jal   sub_GAME_7F040484
   move  $a0, $s1
  jal   sub_GAME_7F056CA0
   move  $a0, $s1
  lw    $a0, 0x10($s1)
  jal   sub_GAME_7F0402B4
   addiu $a1, $s1, 0x7c
  jal   detonate_proxmine_In_range
   lw    $a0, 0x70($sp)
.L7F04664C:
  lbu   $v0, 3($s1)
  li    $at, 1
  bnel  $v0, $at, .L7F0467A0
   li    $at, 6
  lw    $s0, 4($s3)
  lui   $t8, %hi(global_timer) 
  lwc1  $f6, 0xb4($s0)
  swc1  $f6, 0x67c($sp)
  lw    $v0, 0xec($s0)
  blezl $v0, .L7F0466BC
   lb    $t4, 0xbc($s0)
  lw    $t8, %lo(global_timer)($t8)
  lw    $t0, 0xa0($s0)
  subu  $t1, $t8, $t0
  slt   $at, $v0, $t1
  beql  $at, $zero, .L7F0466BC
   lb    $t4, 0xbc($s0)
  lb    $t3, 0xbc($s0)
  bnezl $t3, .L7F0466BC
   lb    $t4, 0xbc($s0)
  lw    $t9, 8($s0)
  move  $a0, $s0
  sll   $t2, $t9, 0
  bltzl $t2, .L7F0466BC
   lb    $t4, 0xbc($s0)
  jal   set_door_state
   li    $a1, 2
  lb    $t4, 0xbc($s0)
.L7F0466BC:
  li    $at, 3
  bnel  $t4, $at, .L7F046730
   lhu   $t5, 0x9a($s0)
  lw    $v0, 0xc8($s0)
  li    $v1, 1
  move  $a0, $s0
  beqz  $v0, .L7F04671C
   nop   
  beq   $v0, $s0, .L7F04671C
   nop   
  lb    $t6, 0xbc($v0)
.L7F0466E8:
  bnezl $t6, .L7F046708
   move  $v1, $zero
  lwc1  $f10, 0xb4($v0)
  c.lt.s $f22, $f10
  nop   
  bc1fl .L7F04670C
   lw    $v0, 0xc8($v0)
  move  $v1, $zero
.L7F046708:
  lw    $v0, 0xc8($v0)
.L7F04670C:
  beqz  $v0, .L7F04671C
   nop   
  bnel  $v0, $s0, .L7F0466E8
   lb    $t6, 0xbc($v0)
.L7F04671C:
  beql  $v1, $zero, .L7F046730
   lhu   $t5, 0x9a($s0)
  jal   sub_GAME_7F0548A4
   li    $a1, 1
  lhu   $t5, 0x9a($s0)
.L7F046730:
  li    $at, 8
  bne   $t5, $at, .L7F046764
   nop   
  jal   sub_GAME_7F054A20
   move  $a0, $s0
  beqz  $v0, .L7F046764
   nop   
  jal   sub_GAME_7F03E718
   move  $a0, $s0
  beqz  $v0, .L7F046764
   nop   
  jal   sub_GAME_7F05599C
   move  $a0, $s3
.L7F046764:
  lui   $t8, %hi(global_timer) 
  lw    $t8, %lo(global_timer)($t8)
  lw    $t7, 0xfc($s0)
  lui   $t0, %hi(clock_timer) 
  slt   $at, $t7, $t8
  bnez  $at, .L7F04678C
   nop   
  lw    $t0, %lo(clock_timer)($t0)
  bnezl $t0, .L7F048230
   lbu   $v0, 3($s1)
.L7F04678C:
  jal   sub_GAME_7F054FB4
   move  $a0, $s0
  b     .L7F048230
   lbu   $v0, 3($s1)
  li    $at, 6
.L7F0467A0:
  bnel  $v0, $at, .L7F046C64
   li    $at, 13
  lw    $t1, 8($s1)
  sll   $t3, $t1, 3
  bltzl $t3, .L7F046C64
   li    $at, 13
  lw    $s0, 4($s3)
  lw    $t9, 0xd4($s0)
  beql  $t9, $zero, .L7F0467D4
   lwc1  $f18, 0xd0($s0)
  b     .L7F0467D4
   lwc1  $f18, 0xcc($s0)
  lwc1  $f18, 0xd0($s0)
.L7F0467D4:
  jal   get_curplayer_positiondata
   swc1  $f18, 0x518($sp)
  sw    $v0, 0x514($sp)
  lwc1  $f8, 0x58($s1)
  lwc1  $f4, 8($v0)
  lwc1  $f0, 0xe8($s0)
  lwc1  $f10, 0x5c($s1)
  sub.s $f12, $f4, $f8
  lwc1  $f6, 0xc($v0)
  lwc1  $f8, 0x60($s1)
  c.lt.s $f22, $f0
  lwc1  $f4, 0x10($v0)
  lwc1  $f18, 0x518($sp)
  li    $s2, 1
  sub.s $f2, $f6, $f10
  bc1f  .L7F04684C
   sub.s $f14, $f4, $f8
  mul.s $f6, $f0, $f0
  nop   
  mul.s $f10, $f12, $f12
  nop   
  mul.s $f4, $f2, $f2
  add.s $f8, $f10, $f4
  mul.s $f10, $f14, $f14
  add.s $f4, $f8, $f10
  c.lt.s $f6, $f4
  nop   
  bc1f  .L7F04684C
   nop   
  move  $s2, $zero
.L7F04684C:
  lw    $t2, 8($s1)
  sll   $t4, $t2, 2
  bgez  $t4, .L7F046860
   nop   
  move  $s2, $zero
.L7F046860:
  beqz  $s2, .L7F04694C
   nop   
  jal   convert_angle_using_inverse
   swc1  $f18, 0x518($sp)
  lwc1  $f2, 0xc8($s0)
  lwc1  $f18, 0x518($sp)
  lui   $at, %hi(D_80052ACC)
  c.lt.s $f2, $f22
  nop   
  bc1f  .L7F04689C
   nop   
  lui   $at, %hi(D_80052AC8)
  lwc1  $f20, %lo(D_80052AC8)($at)
  b     .L7F0468B4
   add.s $f2, $f2, $f20
.L7F04689C:
  lwc1  $f20, %lo(D_80052ACC)($at)
  c.le.s $f20, $f2
  nop   
  bc1fl .L7F0468B8
   lwc1  $f8, 0xc4($s0)
  sub.s $f2, $f2, $f20
.L7F0468B4:
  lwc1  $f8, 0xc4($s0)
.L7F0468B8:
  lui   $at, %hi(D_80052AD0)
  add.s $f2, $f2, $f8
  c.le.s $f20, $f2
  nop   
  bc1fl .L7F0468D8
   c.lt.s $f0, $f2
  sub.s $f2, $f2, $f20
  c.lt.s $f0, $f2
.L7F0468D8:
  sub.s $f14, $f0, $f2
  bc1f  .L7F0468E8
   mov.s $f12, $f14
  add.s $f12, $f14, $f20
.L7F0468E8:
  lwc1  $f0, %lo(D_80052AD0)($at)
  lui   $at, %hi(D_80052AD4)
  sub.s $f12, $f12, $f0
  c.lt.s $f12, $f22
  nop   
  bc1fl .L7F04690C
   c.lt.s $f0, $f12
  add.s $f12, $f12, $f20
  c.lt.s $f0, $f12
.L7F04690C:
  nop   
  bc1f  .L7F04691C
   nop   
  sub.s $f12, $f12, $f20
.L7F04691C:
  lwc1  $f10, %lo(D_80052AD4)($at)
  lui    $at, %hi(D_80052AD8)
  c.lt.s $f10, $f12
  nop   
  bc1tl .L7F04694C
   move  $s2, $zero
  lwc1  $f6, %lo(D_80052AD8)($at)
  c.lt.s $f12, $f6
  nop   
  bc1f  .L7F04694C
   nop   
  move  $s2, $zero
.L7F04694C:
  beqz  $s2, .L7F046A20
   move  $a1, $zero
  lw    $t6, 0x14($s3)
  swc1  $f18, 0x518($sp)
  lw    $a0, 0x514($sp)
  jal   sub_GAME_7F08A03C
   sw    $t6, 0x4f0($sp)
  lw    $v0, 0x514($sp)
  li    $at, 0x42C80000 # 100.000000
  lw    $a1, 8($s3)
  lwc1  $f4, 0x10($v0)
  lw    $a2, 0x10($s3)
  lw    $a3, 8($v0)
  mtc1  $at, $f8
  mtc1  $at, $f10
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  li    $t5, 27
  sw    $t5, 0x14($sp)
  swc1  $f22, 0x20($sp)
  addiu $a0, $sp, 0x4f0
  swc1  $f4, 0x10($sp)
  swc1  $f8, 0x18($sp)
  swc1  $f10, 0x1c($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f6, 0x24($sp)
  beqz  $v0, .L7F046A0C
   lwc1  $f18, 0x518($sp)
  lui   $t8, %hi(clock_timer) 
  lw    $t8, %lo(clock_timer)($t8)
  lw    $t7, 0xe0($s0)
  li    $at, 0x43960000 # 300.000000
  mtc1  $at, $f4
  addu  $t0, $t7, $t8
  sw    $t0, 0xe0($s0)
  lui   $at, %hi(D_80030B14)
  lwc1  $f8, %lo(D_80030B14)($at)
  mul.s $f10, $f4, $f8
  trunc.w.s $f6, $f10
  mfc1  $t9, $f6
  nop   
  slt   $at, $t0, $t9
  bnezl $at, .L7F046A10
   lw    $a0, 0x514($sp)
  jal   start_alarm
   swc1  $f18, 0x518($sp)
  lwc1  $f18, 0x518($sp)
  sw    $zero, 0xe0($s0)
.L7F046A0C:
  lw    $a0, 0x514($sp)
.L7F046A10:
  li    $a1, 1
  jal   sub_GAME_7F08A03C
   swc1  $f18, 0x518($sp)
  lwc1  $f18, 0x518($sp)
.L7F046A20:
  lwc1  $f14, 0xc8($s0)
  c.lt.s $f14, $f18
  nop   
  bc1fl .L7F046B4C
   lwc1  $f0, 0xd8($s0)
  lwc1  $f0, 0xd8($s0)
  lui   $at, %hi(D_80052AE0)
  lwc1  $f16, %lo(D_80052AE0)($at)
  mul.s $f4, $f0, $f0
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f8
  lui   $at, %hi(global_timer_delta)
  mul.s $f10, $f4, $f8
  div.s $f2, $f10, $f16
  sub.s $f6, $f18, $f2
  c.le.s $f6, $f14
  nop   
  bc1fl .L7F046AA4
   lwc1  $f12, 0xdc($s0)
  lwc1  $f4, %lo(global_timer_delta)($at)
  mul.s $f8, $f16, $f4
  sub.s $f10, $f0, $f8
  swc1  $f10, 0xd8($s0)
  lwc1  $f0, 0xd8($s0)
  c.lt.s $f0, $f16
  nop   
  bc1f  .L7F046A98
   nop   
  swc1  $f16, 0xd8($s0)
  lwc1  $f0, 0xd8($s0)
.L7F046A98:
  b     .L7F046B10
   lwc1  $f14, 0xc8($s0)
  lwc1  $f12, 0xdc($s0)
.L7F046AA4:
  lui   $at, %hi(global_timer_delta)
  c.lt.s $f0, $f12
  nop   
  bc1f  .L7F046B10
   nop   
  lwc1  $f6, %lo(global_timer_delta)($at)
  mul.s $f4, $f16, $f6
  add.s $f2, $f0, $f4
  c.lt.s $f12, $f2
  nop   
  bc1f  .L7F046AD8
   nop   
  mov.s $f2, $f12
.L7F046AD8:
  mul.s $f8, $f2, $f2
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f10
  nop   
  mul.s $f6, $f8, $f10
  div.s $f4, $f6, $f16
  sub.s $f8, $f18, $f4
  c.lt.s $f14, $f8
  nop   
  bc1f  .L7F046B10
   nop   
  swc1  $f2, 0xd8($s0)
  lwc1  $f0, 0xd8($s0)
  lwc1  $f14, 0xc8($s0)
.L7F046B10:
  lui   $at, %hi(global_timer_delta)
  lwc1  $f10, %lo(global_timer_delta)($at)
  mul.s $f6, $f0, $f10
  add.s $f4, $f14, $f6
  swc1  $f4, 0xc8($s0)
  lwc1  $f8, 0xc8($s0)
  c.le.s $f18, $f8
  nop   
  bc1fl .L7F048230
   lbu   $v0, 3($s1)
  swc1  $f18, 0xc8($s0)
  swc1  $f22, 0xd8($s0)
  b     .L7F04822C
   sw    $zero, 0xd4($s0)
  lwc1  $f0, 0xd8($s0)
.L7F046B4C:
  lui   $at, %hi(D_80052AE4)
  lwc1  $f16, %lo(D_80052AE4)($at)
  mul.s $f10, $f0, $f0
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f6
  lui   $at, %hi(global_timer_delta)
  li    $t2, 1
  mul.s $f4, $f10, $f6
  div.s $f2, $f4, $f16
  add.s $f8, $f18, $f2
  c.le.s $f14, $f8
  nop   
  bc1fl .L7F046BBC
   lwc1  $f12, 0xdc($s0)
  lwc1  $f10, %lo(global_timer_delta)($at)
  mul.s $f6, $f16, $f10
  sub.s $f4, $f0, $f6
  swc1  $f4, 0xd8($s0)
  lwc1  $f0, 0xd8($s0)
  c.lt.s $f0, $f16
  nop   
  bc1f  .L7F046BB0
   nop   
  swc1  $f16, 0xd8($s0)
  lwc1  $f0, 0xd8($s0)
.L7F046BB0:
  b     .L7F046C28
   lwc1  $f14, 0xc8($s0)
  lwc1  $f12, 0xdc($s0)
.L7F046BBC:
  lui   $at, %hi(global_timer_delta)
  c.lt.s $f0, $f12
  nop   
  bc1f  .L7F046C28
   nop   
  lwc1  $f8, %lo(global_timer_delta)($at)
  mul.s $f10, $f16, $f8
  add.s $f2, $f0, $f10
  c.lt.s $f12, $f2
  nop   
  bc1f  .L7F046BF0
   nop   
  mov.s $f2, $f12
.L7F046BF0:
  mul.s $f6, $f2, $f2
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f4
  nop   
  mul.s $f8, $f6, $f4
  div.s $f10, $f8, $f16
  add.s $f6, $f18, $f10
  c.lt.s $f6, $f14
  nop   
  bc1f  .L7F046C28
   nop   
  swc1  $f2, 0xd8($s0)
  lwc1  $f0, 0xd8($s0)
  lwc1  $f14, 0xc8($s0)
.L7F046C28:
  lui   $at, %hi(global_timer_delta)
  lwc1  $f4, %lo(global_timer_delta)($at)
  mul.s $f8, $f0, $f4
  sub.s $f10, $f14, $f8
  swc1  $f10, 0xc8($s0)
  lwc1  $f6, 0xc8($s0)
  c.le.s $f6, $f18
  nop   
  bc1fl .L7F048230
   lbu   $v0, 3($s1)
  swc1  $f18, 0xc8($s0)
  swc1  $f22, 0xd8($s0)
  b     .L7F04822C
   sw    $t2, 0xd4($s0)
  li    $at, 13
.L7F046C64:
  bnel  $v0, $at, .L7F047564
   li    $at, 39
  lw    $t4, 8($s1)
  sll   $t6, $t4, 3
  bltzl $t6, .L7F047564
   li    $at, 39
  jal   get_curplayer_positiondata
   lw    $s0, 4($s3)
  sw    $zero, 0x4ac($sp)
  sw    $zero, 0x4a8($sp)
  sw    $zero, 0x4a4($sp)
  lw    $v1, 0xc($s1)
  move  $s2, $v0
  sll   $t5, $v1, 0
  bgez  $t5, .L7F046DF8
   sll   $t7, $v1, 1
  bgezl $t7, .L7F046CC8
   lwc1  $f2, 0x84($s0)
  lwc1  $f8, 0x90($s0)
  lwc1  $f4, 0x9c($s0)
  swc1  $f8, 0x84($s0)
  lwc1  $f2, 0x84($s0)
  b     .L7F046D98
   swc1  $f4, 0x98($s0)
  lwc1  $f2, 0x84($s0)
.L7F046CC8:
  lwc1  $f10, 0x90($s0)
  c.eq.s $f2, $f10
  nop   
  bc1f  .L7F046D98
   nop   
  lwc1  $f6, 0x98($s0)
  lwc1  $f4, 0x9c($s0)
  c.eq.s $f6, $f4
  nop   
  bc1f  .L7F046D98
   nop   
  jal   get_random_value
   nop   
  mtc1  $v0, $f8
  lui   $at, %hi(D_80052AE8)
  lwc1  $f20, %lo(D_80052AE8)($at)
  bgez  $v0, .L7F046D20
   cvt.s.w $f10, $f8
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f6
  nop   
  add.s $f10, $f10, $f6
.L7F046D20:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f4
  li    $at, 0x421C0000 # 39.000000
  mtc1  $at, $f6
  mul.s $f8, $f10, $f4
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  li    $at, 0x43B40000 # 360.000000
  mul.s $f10, $f8, $f6
  add.s $f8, $f10, $f4
  mtc1  $at, $f10
  mul.s $f6, $f8, $f20
  div.s $f4, $f6, $f10
  jal   get_random_value
   swc1  $f4, 0x98($s0)
  mtc1  $v0, $f8
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F046D78
   cvt.s.w $f6, $f8
  mtc1  $at, $f10
  nop   
  add.s $f6, $f6, $f10
.L7F046D78:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f4
  nop   
  mul.s $f8, $f6, $f4
  nop   
  mul.s $f10, $f8, $f20
  swc1  $f10, 0x84($s0)
  lwc1  $f2, 0x84($s0)
.L7F046D98:
  lui   $at, %hi(D_80052AEC)
  lwc1  $f0, %lo(D_80052AEC)($at)
  lui   $at, %hi(D_80052AF4)
  lwc1  $f6, %lo(D_80052AF4)($at)
  mfc1  $a1, $f2
  mfc1  $a3, $f0
  addiu $a0, $s0, 0x90
  addiu $a2, $s0, 0x94
  swc1  $f0, 0x10($sp)
  jal   sub_GAME_7F04310C
   swc1  $f6, 0x14($sp)
  lui   $at, %hi(D_80052AF8)
  lwc1  $f0, %lo(D_80052AF8)($at)
  lui   $at, %hi(D_80052AFC)
  lwc1  $f4, %lo(D_80052AFC)($at)
  lw    $a1, 0x98($s0)
  mfc1  $a3, $f0
  addiu $a0, $s0, 0x9c
  addiu $a2, $s0, 0xa0
  swc1  $f0, 0x10($sp)
  jal   sub_GAME_7F04310C
   swc1  $f4, 0x14($sp)
  b     .L7F048230
   lbu   $v0, 3($s1)
.L7F046DF8:
  lwc1  $f8, 8($s2)
  lwc1  $f10, 0x58($s1)
  lwc1  $f6, 0xc($s2)
  lwc1  $f4, 0x5c($s1)
  sub.s $f0, $f8, $f10
  li    $at, 0x41A00000 # 20.000000
  mtc1  $at, $f10
  sub.s $f8, $f6, $f4
  sub.s $f6, $f8, $f10
  mul.s $f10, $f0, $f0
  swc1  $f6, 0x4c0($sp)
  lwc1  $f8, 0x60($s1)
  lwc1  $f4, 0x10($s2)
  swc1  $f0, 0x4c4($sp)
  sub.s $f2, $f4, $f8
  mul.s $f6, $f2, $f2
  swc1  $f2, 0x4bc($sp)
  add.s $f20, $f10, $f6
  swc1  $f20, 0x4b8($sp)
  jal   sqrtf
   mov.s $f12, $f20
  swc1  $f0, 0x4b0($sp)
  lw    $t8, 8($s1)
  mov.s $f2, $f0
  sll   $t0, $t8, 4
  bgezl $t0, .L7F046E80
   lwc1  $f12, 0x4b8($sp)
  lwc1  $f0, 0x4c0($sp)
  mul.s $f4, $f0, $f0
  add.s $f12, $f20, $f4
  jal   sqrtf
   swc1  $f12, 0x4b8($sp)
  mov.s $f2, $f0
  lwc1  $f12, 0x4b8($sp)
.L7F046E80:
  jal   sub_GAME_7F02D244
   swc1  $f2, 0x4b4($sp)
  swc1  $f0, 0x4a0($sp)
  lwc1  $f8, 0x98($s0)
  lwc1  $f16, 0x84($s0)
  lwc1  $f2, 0x4b4($sp)
  swc1  $f8, 0x4d4($sp)
  lwc1  $f10, 0xa8($s0)
  c.le.s $f2, $f10
  nop   
  bc1fl .L7F047104
   lw    $t4, 0x4ac($sp)
  lwc1  $f12, 0x4c4($sp)
  lwc1  $f14, 0x4bc($sp)
  jal   convert_angle_using_inverse
   swc1  $f16, 0x4d8($sp)
  swc1  $f0, 0x49c($sp)
  lwc1  $f12, 0x4c0($sp)
  jal   convert_angle_using_inverse
   lwc1  $f14, 0x4b0($sp)
  swc1  $f0, 0x498($sp)
  lw    $v0, 8($s1)
  lwc1  $f16, 0x4d8($sp)
  li    $t9, 1
  sll   $t3, $v0, 1
  bltz  $t3, .L7F046EF4
   sll   $t1, $v0, 2
  bgez  $t1, .L7F046F04
   lwc1  $f6, 0x49c($sp)
.L7F046EF4:
  lui   $at, %hi(D_80052B00)
  lwc1  $f20, %lo(D_80052B00)($at)
  b     .L7F046F9C
   sw    $t9, 0x4ac($sp)
.L7F046F04:
  lwc1  $f4, 0x90($s0)
  lui   $at, %hi(D_80052B04)
  sub.s $f12, $f6, $f4
  c.lt.s $f12, $f22
  nop   
  bc1f  .L7F046F28
   nop   
  lwc1  $f20, %lo(D_80052B04)($at)
  add.s $f12, $f12, $f20
.L7F046F28:
  lui   $at, %hi(D_80052B08)
  lwc1  $f20, %lo(D_80052B08)($at)
  lui   $at, %hi(D_80052B0C)
  lwc1  $f8, %lo(D_80052B0C)($at)
  lui   $at, %hi(D_80052B10)
  c.lt.s $f8, $f12
  nop   
  bc1fl .L7F046F54
   lwc1  $f10, 0x9c($s0)
  sub.s $f12, $f12, $f20
  lwc1  $f10, 0x9c($s0)
.L7F046F54:
  sub.s $f2, $f0, $f10
  c.lt.s $f2, $f22
  nop   
  bc1f  .L7F046F68
   nop   
.L7F046F68:
  lwc1  $f6, %lo(D_80052B10)($at)
  lui   $at, %hi(D_80052B14)
  c.lt.s $f12, $f6
  nop   
  bc1fl .L7F046FA0
   lw    $t4, 0x4ac($sp)
  lwc1  $f4, %lo(D_80052B14)($at)
  li    $t2, 1
  c.lt.s $f4, $f12
  nop   
  bc1fl .L7F046FA0
   lw    $t4, 0x4ac($sp)
  sw    $t2, 0x4ac($sp)
.L7F046F9C:
  lw    $t4, 0x4ac($sp)
.L7F046FA0:
  lwc1  $f8, 0x49c($sp)
  move  $a0, $s2
  beqz  $t4, .L7F047100
   move  $a1, $zero
  lwc1  $f10, 0x84($s0)
  lui   $at, %hi(D_80052B18)
  lwc1  $f6, %lo(D_80052B18)($at)
  sub.s $f0, $f8, $f10
  lw    $t6, 0x14($s3)
  lui   $at, %hi(D_80052B1C)
  c.lt.s $f0, $f6
  sw    $t6, 0x490($sp)
  bc1f  .L7F046FE0
   nop   
  b     .L7F046FF8
   add.s $f0, $f0, $f20
.L7F046FE0:
  lwc1  $f4, %lo(D_80052B1C)($at)
  c.le.s $f4, $f0
  nop   
  bc1fl .L7F046FFC
   swc1  $f0, 0x494($sp)
  sub.s $f0, $f0, $f20
.L7F046FF8:
  swc1  $f0, 0x494($sp)
.L7F046FFC:
  jal   sub_GAME_7F08A03C
   swc1  $f16, 0x4d8($sp)
  lwc1  $f0, 0x494($sp)
  lwc1  $f8, 0x88($s0)
  lwc1  $f16, 0x4d8($sp)
  c.le.s $f0, $f8
  nop   
  bc1fl .L7F0470B8
   lw    $v0, 0xb8($s0)
  lwc1  $f10, 0x8c($s0)
  li    $t5, 27
  c.le.s $f10, $f0
  nop   
  bc1fl .L7F0470B8
   lw    $v0, 0xb8($s0)
  lwc1  $f6, 0x10($s2)
  lw    $a1, 8($s3)
  lw    $a2, 0x10($s3)
  lw    $a3, 8($s2)
  sw    $t5, 0x14($sp)
  swc1  $f6, 0x10($sp)
  lwc1  $f0, 0xc($s3)
  addiu $a0, $sp, 0x490
  swc1  $f0, 0x18($sp)
  swc1  $f0, 0x1c($sp)
  lwc1  $f2, 0xc($s2)
  swc1  $f16, 0x4d8($sp)
  swc1  $f2, 0x20($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f2, 0x24($sp)
  beqz  $v0, .L7F0470B4
   lwc1  $f16, 0x4d8($sp)
  lw    $t7, 0x490($sp)
  lw    $t8, 0x14($s2)
  bnel  $t7, $t8, .L7F0470B8
   lw    $v0, 0xb8($s0)
  lw    $t0, 8($s1)
  lui   $at, 0x2000
  li    $t1, 1
  or    $t3, $t0, $at
  sw    $t3, 8($s1)
  lwc1  $f4, 0x498($sp)
  sw    $t1, 0x4a4($sp)
  lwc1  $f16, 0x49c($sp)
  b     .L7F0470EC
   swc1  $f4, 0x4d4($sp)
.L7F0470B4:
  lw    $v0, 0xb8($s0)
.L7F0470B8:
  lui   $t9, %hi(global_timer) 
  bltzl $v0, .L7F0470EC
   sw    $zero, 0x4ac($sp)
  lw    $t9, %lo(global_timer)($t9)
  addiu $t2, $t9, -0x78
  slt   $at, $t2, $v0
  beql  $at, $zero, .L7F0470EC
   sw    $zero, 0x4ac($sp)
  lwc1  $f8, 0x9c($s0)
  lwc1  $f16, 0x90($s0)
  b     .L7F0470EC
   swc1  $f8, 0x4d4($sp)
  sw    $zero, 0x4ac($sp)
.L7F0470EC:
  move  $a0, $s2
  li    $a1, 1
  jal   sub_GAME_7F08A03C
   swc1  $f16, 0x4d8($sp)
  lwc1  $f16, 0x4d8($sp)
.L7F047100:
  lw    $t4, 0x4ac($sp)
.L7F047104:
  lui   $at, %hi(D_80052B20)
  lwc1  $f20, %lo(D_80052B20)($at)
  beql  $t4, $zero, .L7F04712C
   lw    $t6, 0xd0($s0)
  lwc1  $f12, 0x4b8($sp)
  jal   sub_GAME_7F02D244
   swc1  $f16, 0x4d8($sp)
  lwc1  $f16, 0x4d8($sp)
  swc1  $f0, 0x4a0($sp)
  lw    $t6, 0xd0($s0)
.L7F04712C:
  beqz  $t6, .L7F0471AC
   lui   $t5, %hi(global_timer) 
  lw    $t5, %lo(global_timer)($t5)
  li    $at, 120
  swc1  $f16, 0x4d8($sp)
  div   $zero, $t5, $at
  mfhi  $t7
  mtc1  $t7, $f10
  li    $at, 0x42F00000 # 120.000000
  mtc1  $at, $f8
  cvt.s.w $f6, $f10
  mul.s $f4, $f6, $f20
  jal   sinf
   div.s $f12, $f4, $f8
  lui   $at, %hi(D_80052B24)
  lwc1  $f6, %lo(D_80052B24)($at)
  lwc1  $f10, 0x4a0($sp)
  lwc1  $f16, 0x4d8($sp)
  mul.s $f4, $f10, $f6
  nop   
  mul.s $f8, $f4, $f0
  add.s $f16, $f16, $f8
  c.lt.s $f16, $f22
  nop   
  bc1f  .L7F047198
   nop   
  add.s $f16, $f16, $f20
.L7F047198:
  c.le.s $f20, $f16
  nop   
  bc1fl .L7F0471B0
   lwc1  $f2, 0x84($s0)
  sub.s $f16, $f16, $f20
.L7F0471AC:
  lwc1  $f2, 0x84($s0)
.L7F0471B0:
  lui   $at, %hi(D_80052B28)
  lwc1  $f10, %lo(D_80052B28)($at)
  sub.s $f0, $f16, $f2
  addiu $a0, $s0, 0x90
  c.lt.s $f0, $f10
  nop   
  bc1f  .L7F0471D8
   nop   
  b     .L7F0471F4
   add.s $f0, $f0, $f20
.L7F0471D8:
  lui   $at, %hi(D_80052B2C)
  lwc1  $f6, %lo(D_80052B2C)($at)
  c.le.s $f6, $f0
  nop   
  bc1fl .L7F0471F8
   lwc1  $f12, 0x88($s0)
  sub.s $f0, $f0, $f20
.L7F0471F4:
  lwc1  $f12, 0x88($s0)
.L7F0471F8:
  lui   $at, %hi(D_80052B30)
  c.lt.s $f12, $f0
  nop   
  bc1fl .L7F047218
   lwc1  $f12, 0x8c($s0)
  b     .L7F04722C
   add.s $f16, $f2, $f12
  lwc1  $f12, 0x8c($s0)
.L7F047218:
  c.lt.s $f0, $f12
  nop   
  bc1fl .L7F047230
   c.lt.s $f16, $f22
  add.s $f16, $f2, $f12
.L7F04722C:
  c.lt.s $f16, $f22
.L7F047230:
  nop   
  bc1fl .L7F047244
   c.le.s $f20, $f16
  add.s $f16, $f16, $f20
  c.le.s $f20, $f16
.L7F047244:
  nop   
  bc1f  .L7F047254
   nop   
  sub.s $f16, $f16, $f20
.L7F047254:
  lwc1  $f0, %lo(D_80052B30)($at)
  mfc1  $a1, $f16
  addiu $a2, $s0, 0x94
  swc1  $f0, 0x10($sp)
  lwc1  $f4, 0xa4($s0)
  mfc1  $a3, $f0
  swc1  $f16, 0x4d8($sp)
  jal   sub_GAME_7F04310C
   swc1  $f4, 0x14($sp)
  lui   $at, %hi(D_80052B34)
  lwc1  $f0, %lo(D_80052B34)($at)
  addiu $a0, $s0, 0x9c
  lw    $a1, 0x4d4($sp)
  swc1  $f0, 0x10($sp)
  lwc1  $f8, 0xa4($s0)
  mfc1  $a3, $f0
  addiu $a2, $s0, 0xa0
  jal   sub_GAME_7F04310C
   swc1  $f8, 0x14($sp)
  lwc1  $f16, 0x4d8($sp)
  lwc1  $f10, 0x90($s0)
  lui   $at, %hi(D_80052B38)
  lwc1  $f6, 0x4d4($sp)
  sub.s $f12, $f16, $f10
  c.lt.s $f12, $f22
  nop   
  bc1f  .L7F0472C8
   nop   
  add.s $f12, $f12, $f20
.L7F0472C8:
  lwc1  $f0, %lo(D_80052B38)($at)
  c.lt.s $f0, $f12
  nop   
  bc1fl .L7F0472E4
   lwc1  $f4, 0x9c($s0)
  sub.s $f12, $f12, $f20
  lwc1  $f4, 0x9c($s0)
.L7F0472E4:
  sub.s $f2, $f6, $f4
  c.lt.s $f2, $f22
  nop   
  bc1fl .L7F047300
   c.lt.s $f0, $f2
  add.s $f2, $f2, $f20
  c.lt.s $f0, $f2
.L7F047300:
  nop   
  bc1fl .L7F047314
   sw    $zero, 0xd0($s0)
  sub.s $f2, $f2, $f20
  sw    $zero, 0xd0($s0)
.L7F047314:
  lw    $t8, 0x4ac($sp)
  lwc1  $f8, 0x4a0($sp)
  beql  $t8, $zero, .L7F04743C
   lw    $t9, 0x4a8($sp)
  c.lt.s $f12, $f8
  lwc1  $f10, 0x4a0($sp)
  bc1fl .L7F04739C
   add.s $f0, $f10, $f10
  neg.s $f0, $f8
  c.lt.s $f0, $f12
  nop   
  bc1fl .L7F04739C
   add.s $f0, $f10, $f10
  c.lt.s $f2, $f8
  nop   
  bc1fl .L7F04739C
   add.s $f0, $f10, $f10
  c.lt.s $f0, $f2
  li    $t0, 1
  bc1fl .L7F04739C
   add.s $f0, $f10, $f10
  sw    $t0, 0xd0($s0)
  lw    $t1, 0x4a4($sp)
  li    $t3, 1
  sw    $t3, 0x4a8($sp)
  beqz  $t1, .L7F047438
   lui   $t9, %hi(global_timer) 
  lw    $t9, %lo(global_timer)($t9)
  lui   $t2, %hi(global_timer) 
  sw    $t9, 0xb8($s0)
  lw    $t2, %lo(global_timer)($t2)
  b     .L7F047438
   sw    $t2, 0xbc($s0)
  add.s $f0, $f10, $f10
.L7F04739C:
  c.lt.s $f12, $f0
  nop   
  bc1fl .L7F047408
   lw    $v0, 0xb8($s0)
  neg.s $f14, $f0
  c.lt.s $f14, $f12
  nop   
  bc1fl .L7F047408
   lw    $v0, 0xb8($s0)
  c.lt.s $f2, $f0
  nop   
  bc1fl .L7F047408
   lw    $v0, 0xb8($s0)
  c.lt.s $f14, $f2
  li    $t4, 1
  bc1fl .L7F047408
   lw    $v0, 0xb8($s0)
  sw    $t4, 0xd0($s0)
  lw    $t5, 0x4a4($sp)
  li    $t6, 1
  sw    $t6, 0x4a8($sp)
  beqz  $t5, .L7F047438
   lui   $t7, %hi(global_timer) 
  lw    $t7, %lo(global_timer)($t7)
  b     .L7F047438
   sw    $t7, 0xb8($s0)
  lw    $v0, 0xb8($s0)
.L7F047408:
  lui   $t8, %hi(global_timer) 
  bltzl $v0, .L7F04743C
   lw    $t9, 0x4a8($sp)
  lw    $t8, %lo(global_timer)($t8)
  li    $t3, 1
  li    $t1, 1
  addiu $t0, $t8, -0x78
  slt   $at, $t0, $v0
  beql  $at, $zero, .L7F04743C
   lw    $t9, 0x4a8($sp)
  sw    $t3, 0xd0($s0)
  sw    $t1, 0x4a8($sp)
.L7F047438:
  lw    $t9, 0x4a8($sp)
.L7F04743C:
  lui   $at, %hi(D_80052B3C)
  beql  $t9, $zero, .L7F047490
   lwc1  $f2, 0xb0($s0)
  lwc1  $f0, %lo(D_80052B3C)($at)
  lui   $at, %hi(D_80052B40)
  lwc1  $f6, %lo(D_80052B40)($at)
  lui   $at, %hi(global_timer_delta)
  lwc1  $f4, %lo(global_timer_delta)($at)
  lwc1  $f10, 0xb0($s0)
  mul.s $f8, $f6, $f4
  add.s $f6, $f10, $f8
  swc1  $f6, 0xb0($s0)
  lwc1  $f2, 0xb0($s0)
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F047508
   c.lt.s $f22, $f2
  swc1  $f0, 0xb0($s0)
  b     .L7F047504
   lwc1  $f2, 0xb0($s0)
  lwc1  $f2, 0xb0($s0)
.L7F047490:
  lui   $t2, %hi(clock_timer) 
  c.lt.s $f22, $f2
  nop   
  bc1fl .L7F047508
   c.lt.s $f22, $f2
  lw    $t2, %lo(clock_timer)($t2)
  move  $v0, $zero
  lui   $at, %hi(D_80052B44)
  blez  $t2, .L7F0474E4
   nop   
  lwc1  $f0, %lo(D_80052B44)($at)
  lwc1  $f4, 0xb0($s0)
.L7F0474C0:
  lui   $t4, %hi(clock_timer) 
  addiu $v0, $v0, 1
  mul.s $f10, $f4, $f0
  swc1  $f10, 0xb0($s0)
  lw    $t4, %lo(clock_timer)($t4)
  slt   $at, $v0, $t4
  bnezl $at, .L7F0474C0
   lwc1  $f4, 0xb0($s0)
  lwc1  $f2, 0xb0($s0)
.L7F0474E4:
  lui   $at, %hi(D_80052B48)
  lwc1  $f8, %lo(D_80052B48)($at)
  c.le.s $f2, $f8
  nop   
  bc1fl .L7F047508
   c.lt.s $f22, $f2
  swc1  $f22, 0xb0($s0)
  lwc1  $f2, 0xb0($s0)
.L7F047504:
  c.lt.s $f22, $f2
.L7F047508:
  lui   $at, %hi(global_timer_delta)
  bc1fl .L7F048230
   lbu   $v0, 3($s1)
  lwc1  $f4, %lo(global_timer_delta)($at)
  lwc1  $f6, 0xb4($s0)
  mul.s $f10, $f2, $f4
  add.s $f8, $f6, $f10
  swc1  $f8, 0xb4($s0)
  lwc1  $f0, 0xb4($s0)
  c.le.s $f20, $f0
  nop   
  bc1fl .L7F048230
   lbu   $v0, 3($s1)
  sub.s $f4, $f0, $f20
.L7F047540:
  swc1  $f4, 0xb4($s0)
  lwc1  $f0, 0xb4($s0)
  c.le.s $f20, $f0
  nop   
  bc1tl .L7F047540
   sub.s $f4, $f0, $f20
  b     .L7F048230
   lbu   $v0, 3($s1)
  li    $at, 39
.L7F047564:
  bne   $v0, $at, .L7F047EBC
   move  $a0, $s1
  lwc1  $f6, 0xa0($s1)
  sw    $zero, 0x478($sp)
  li    $a1, 1
  jal   parse_handle_actionblocks
   swc1  $f6, 0x47c($sp)
  lwc1  $f14, 0x98($s1)
  lui   $at, %hi(global_timer_delta)
  c.le.s $f22, $f14
  nop   
  bc1fl .L7F0475EC
   lw    $t6, 0xc($s1)
  lwc1  $f2, %lo(global_timer_delta)($at)
  lui   $at, %hi(global_timer_delta)
  c.le.s $f14, $f2
  nop   
  bc1fl .L7F0475C4
   lwc1  $f0, 0x88($s1)
  lwc1  $f10, 0x94($s1)
  lwc1  $f14, 0x98($s1)
  b     .L7F0475DC
   swc1  $f10, 0x88($s1)
  lwc1  $f0, 0x88($s1)
.L7F0475C4:
  lwc1  $f8, 0x94($s1)
  sub.s $f4, $f8, $f0
  mul.s $f6, $f4, $f2
  div.s $f10, $f6, $f14
  add.s $f8, $f0, $f10
  swc1  $f8, 0x88($s1)
.L7F0475DC:
  lwc1  $f4, %lo(global_timer_delta)($at)
  sub.s $f6, $f14, $f4
  swc1  $f6, 0x98($s1)
  lw    $t6, 0xc($s1)
.L7F0475EC:
  move  $s0, $zero
  sll   $t5, $t6, 0xc
  bltz  $t5, .L7F047648
   nop   
  jal   check_if_object_has_not_been_destroyed
   move  $a0, $s1
  beqz  $v0, .L7F047648
   nop   
  lwc1  $f10, 0x88($s1)
  addiu $a0, $s1, 0x58
  lui   $a1, 0x44fa
  c.lt.s $f22, $f10
  lui   $a2, (0x453B8000 >> 16) # lui $a2, 0x453b
  bc1t  .L7F04763C
   nop   
  lwc1  $f8, 0x94($s1)
  c.lt.s $f22, $f8
  nop   
  bc1f  .L7F047648
   nop   
.L7F04763C:
  jal   sub_GAME_7F053894
   ori   $a2, (0x453B8000 & 0xFFFF) # ori $a2, $a2, 0x8000
  move  $s0, $v0
.L7F047648:
  blezl $s0, .L7F0476B0
   lw    $a0, 0xac($s1)
  lw    $a0, 0xac($s1)
  beqz  $a0, .L7F04766C
   nop   
  jal   sfxGetArg0Unk3F
   nop   
  bnezl $v0, .L7F047690
   lw    $a0, 0xac($s1)
.L7F04766C:
  jal   get_controls_locked_flag
   nop   
  bnez  $v0, .L7F04768C
   lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 65
  jal   play_sfx_a1
   addiu $a2, $s1, 0xac
.L7F04768C:
  lw    $a0, 0xac($s1)
.L7F047690:
  li    $a1, 8
  beql  $a0, $zero, .L7F0476D4
   lw    $a0, 0xa4($s1)
  jal   sfx_c_70009184
   move  $a2, $s0
  b     .L7F0476D4
   lw    $a0, 0xa4($s1)
  lw    $a0, 0xac($s1)
.L7F0476B0:
  beql  $a0, $zero, .L7F0476D4
   lw    $a0, 0xa4($s1)
  jal   sfxGetArg0Unk3F
   nop   
  beql  $v0, $zero, .L7F0476D4
   lw    $a0, 0xa4($s1)
  jal   sfxDeactivate
   lw    $a0, 0xac($s1)
  lw    $a0, 0xa4($s1)
.L7F0476D4:
  lui   $a1, %hi(ptr_setup_path_tbl)
  beql  $a0, $zero, .L7F047784
   lw    $t3, 8($s1)
  lw    $t8, 0xa8($s1)
  lw    $t7, ($a0)
  addiu $a1, %lo(ptr_setup_path_tbl) # addiu $a1, $a1, 0x5d00
  sll   $t0, $t8, 2
  addu  $v0, $t7, $t0
  lw    $t3, ($v0)
  lw    $t9, ($a1)
  lw    $t6, 0x18($a1)
  sll   $t1, $t3, 4
  addu  $v1, $t1, $t9
  lw    $t2, ($v1)
  lwc1  $f6, 0x58($s1)
  lwc1  $f8, 0x60($s1)
  sll   $t4, $t2, 2
  subu  $t4, $t4, $t2
  sll   $t4, $t4, 2
  subu  $t4, $t4, $t2
  sll   $t4, $t4, 2
  addu  $a2, $t4, $t6
  lwc1  $f4, ($a2)
  lwc1  $f10, 8($a2)
  sw    $a2, 0x478($sp)
  sub.s $f12, $f4, $f6
  jal   convert_angle_using_inverse
   sub.s $f14, $f10, $f8
  swc1  $f0, 0x47c($sp)
  lw    $t5, 8($s1)
  lui   $at, (0xDFFFFFFF >> 16) # lui $at, 0xdfff
  lwc1  $f4, 0x47c($sp)
  sll   $t8, $t5, 2
  bgez  $t8, .L7F0477BC
   ori   $at, (0xDFFFFFFF & 0xFFFF) # ori $at, $at, 0xffff
  lw    $t7, 8($s1)
  swc1  $f4, 0xa0($s1)
  move  $a0, $s1
  and   $t0, $t7, $at
  jal   sub_GAME_7F044B38
   sw    $t0, 8($s1)
  b     .L7F0477C0
   lwc1  $f6, 0x88($s1)
  lw    $t3, 8($s1)
.L7F047784:
  sll   $t1, $t3, 2
  bgezl $t1, .L7F0477C0
   lwc1  $f6, 0x88($s1)
  lwc1  $f12, 0x38($s1)
  jal   convert_angle_using_inverse
   lwc1  $f14, 0x40($s1)
  lw    $t9, 8($s1)
  lui   $at, (0xDFFFFFFF >> 16) # lui $at, 0xdfff
  ori   $at, (0xDFFFFFFF & 0xFFFF) # ori $at, $at, 0xffff
  and   $t2, $t9, $at
  swc1  $f0, 0xa0($s1)
  sw    $t2, 8($s1)
  jal   sub_GAME_7F044B38
   move  $a0, $s1
.L7F0477BC:
  lwc1  $f6, 0x88($s1)
.L7F0477C0:
  c.lt.s $f22, $f6
  nop   
  bc1fl .L7F047E7C
   lw    $t0, 8($s1)
  lw    $t4, 0x14($s3)
  lw    $t6, 0x478($sp)
  mov.s $f14, $f22
  sw    $t4, 0x468($sp)
  lwc1  $f12, 0xa0($s1)
  swc1  $f12, 0x438($sp)
  lwc1  $f10, 0x9c($s1)
  beqz  $t6, .L7F04783C
   swc1  $f10, 0x434($sp)
  addiu $t5, $s1, 0x58
  sw    $t5, 0x70($sp)
  jal   sinf
   swc1  $f14, 0x430($sp)
  swc1  $f0, 0x43c($sp)
  swc1  $f22, 0x440($sp)
  jal   cosf
   lwc1  $f12, 0xa0($s1)
  swc1  $f0, 0x444($sp)
  lw    $a0, 0x70($sp)
  addiu $a1, $sp, 0x43c
  lw    $a2, 0x478($sp)
  jal   sub_GAME_7F02FC34
   lui   $a3, 0x4120
  beqz  $v0, .L7F04783C
   lwc1  $f14, 0x430($sp)
  lwc1  $f8, 0xa0($s1)
  swc1  $f8, 0x47c($sp)
.L7F04783C:
  lui   $at, %hi(D_80052B4C)
  lwc1  $f4, %lo(D_80052B4C)($at)
  lui   $at, %hi(D_80052B50)
  lwc1  $f6, %lo(D_80052B50)($at)
  lui   $a3, (0x38E4C389 >> 16) # lui $a3, 0x38e4
  ori   $a3, (0x38E4C389 & 0xFFFF) # ori $a3, $a3, 0xc389
  addiu $a0, $s1, 0xa0
  lw    $a1, 0x47c($sp)
  addiu $a2, $s1, 0x9c
  swc1  $f14, 0x430($sp)
  swc1  $f4, 0x10($sp)
  jal   sub_GAME_7F04310C
   swc1  $f6, 0x14($sp)
  lui   $at, %hi(D_80052B54)
  lwc1  $f20, %lo(D_80052B54)($at)
  lwc1  $f12, 0xa0($s1)
  lwc1  $f14, 0x430($sp)
  lui   $at, %hi(D_80052B58)
  c.le.s $f20, $f12
  nop   
  bc1fl .L7F0478B4
   c.lt.s $f12, $f22
  sub.s $f10, $f12, $f20
.L7F047898:
  swc1  $f10, 0xa0($s1)
  lwc1  $f12, 0xa0($s1)
  c.le.s $f20, $f12
  nop   
  bc1tl .L7F047898
   sub.s $f10, $f12, $f20
  c.lt.s $f12, $f22
.L7F0478B4:
  nop   
  bc1fl .L7F0478E0
   lwc1  $f4, 0x47c($sp)
  add.s $f8, $f12, $f20
.L7F0478C4:
  swc1  $f8, 0xa0($s1)
  lwc1  $f12, 0xa0($s1)
  c.lt.s $f12, $f22
  nop   
  bc1tl .L7F0478C4
   add.s $f8, $f12, $f20
  lwc1  $f4, 0x47c($sp)
.L7F0478E0:
  c.eq.s $f4, $f12
  nop   
  bc1fl .L7F047928
   lw    $t8, 8($s4)
  lwc1  $f0, 0x9c($s1)
  lwc1  $f6, %lo(D_80052B58)($at)
  lui   $at, %hi(D_80052B5C)
  c.le.s $f0, $f6
  nop   
  bc1fl .L7F047928
   lw    $t8, 8($s4)
  lwc1  $f10, %lo(D_80052B5C)($at)
  c.le.s $f10, $f0
  nop   
  bc1fl .L7F047928
   lw    $t8, 8($s4)
  swc1  $f22, 0x9c($s1)
  lw    $t8, 8($s4)
.L7F047928:
  lui   $at, %hi(global_timer_delta)
  lwc1  $f2, %lo(global_timer_delta)($at)
  lw    $t7, 8($t8)
  lwc1  $f4, 0x438($sp)
  c.lt.s $f22, $f2
  lw    $t0, 0xc($t7)
  bc1f  .L7F047954
   lw    $s0, 4($t0)
  lwc1  $f8, 0xa0($s1)
  sub.s $f6, $f8, $f4
  div.s $f14, $f6, $f2
.L7F047954:
  c.lt.s $f14, $f22
  nop   
  bc1f  .L7F047968
   nop   
  add.s $f14, $f14, $f20
.L7F047968:
  jal   sinf
   mov.s $f12, $f14
  lwc1  $f10, 8($s0)
  lwc1  $f8, 0x14($s4)
  lui   $at, %hi(global_timer_delta)
  mul.s $f4, $f10, $f8
  lwc1  $f10, %lo(global_timer_delta)($at)
  mul.s $f6, $f0, $f4
  nop   
  mul.s $f8, $f6, $f10
  swc1  $f8, 0x460($sp)
  jal   sinf
   lwc1  $f12, 0xa0($s1)
  swc1  $f0, 0x43c($sp)
  swc1  $f22, 0x440($sp)
  jal   cosf
   lwc1  $f12, 0xa0($s1)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f14
  swc1  $f0, 0x444($sp)
  lui   $at, %hi(global_timer_delta)
  lwc1  $f2, %lo(global_timer_delta)($at)
  lwc1  $f4, 0x88($s1)
  lwc1  $f10, 0x43c($sp)
  lwc1  $f12, 0x460($sp)
  mul.s $f6, $f4, $f2
  lwc1  $f4, 0x58($s1)
  addiu $s0, $sp, 0x468
  li    $t3, 31
  move  $a0, $s0
  mul.s $f8, $f6, $f10
  add.s $f6, $f4, $f8
  lwc1  $f4, 0x444($sp)
  mul.s $f8, $f4, $f12
  sub.s $f6, $f6, $f8
  swc1  $f6, 0x694($sp)
  lwc1  $f8, 0x5c($s1)
  mfc1  $a3, $f6
  swc1  $f8, 0x698($sp)
  lwc1  $f8, 0x88($s1)
  mul.s $f8, $f8, $f2
  nop   
  mul.s $f8, $f8, $f4
  lwc1  $f4, 0x60($s1)
  add.s $f4, $f4, $f8
  mul.s $f8, $f10, $f12
  add.s $f10, $f8, $f4
  swc1  $f10, 0x69c($sp)
  lw    $a2, 0x10($s3)
  lw    $a1, 8($s3)
  swc1  $f22, 0x20($sp)
  swc1  $f22, 0x18($sp)
  sw    $t3, 0x14($sp)
  swc1  $f10, 0x10($sp)
  swc1  $f14, 0x24($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f14, 0x1c($sp)
  beqz  $v0, .L7F047E38
   move  $a0, $s0
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  li    $t1, 31
  sw    $t1, 0x10($sp)
  lw    $a1, 0x694($sp)
  lw    $a2, 0x69c($sp)
  lui   $a3, 0x4120
  swc1  $f22, 0x14($sp)
  jal   sub_GAME_7F0B18B8
   swc1  $f8, 0x18($sp)
  bgezl $v0, .L7F047E3C
   lwc1  $f6, 0x98($s1)
  lw    $t9, 0x14($s3)
  lw    $t2, 0x468($sp)
  move  $a0, $s1
  sw    $t9, 0x44c($sp)
  lwc1  $f4, 8($s3)
  swc1  $f4, 0x450($sp)
  lwc1  $f6, 0xc($s3)
  swc1  $f6, 0x454($sp)
  lwc1  $f10, 0x10($s3)
  swc1  $f10, 0x458($sp)
  sw    $t2, 0x14($s3)
  lwc1  $f2, 0x694($sp)
  swc1  $f2, 8($s3)
  swc1  $f2, 0x58($s1)
  lwc1  $f2, 0x69c($sp)
  swc1  $f2, 0x10($s3)
  jal   sub_GAME_7F040484
   swc1  $f2, 0x60($s1)
  jal   sub_GAME_7F056CA0
   move  $a0, $s1
  jal   sub_GAME_7F0448A8
   move  $a0, $s3
  beqz  $v0, .L7F047D28
   move  $s2, $v0
  lw    $t4, 8($s4)
  lwc1  $f8, 0x18($s1)
  move  $a0, $s0
  lw    $t6, 8($t4)
  lw    $t5, 0x28($t6)
  lw    $v0, 4($t5)
  lwc1  $f4, 4($v0)
  mul.s $f6, $f8, $f4
  swc1  $f6, 0x424($sp)
  lwc1  $f10, 0x20($s1)
  lwc1  $f8, 4($v0)
  mul.s $f4, $f10, $f8
  swc1  $f4, 0x42c($sp)
  lwc1  $f6, 0x18($s1)
  lwc1  $f10, 8($v0)
  mul.s $f8, $f6, $f10
  swc1  $f8, 0x418($sp)
  lwc1  $f4, 0x20($s1)
  lwc1  $f6, 8($v0)
  mul.s $f10, $f4, $f6
  swc1  $f10, 0x420($sp)
  lwc1  $f8, 0x38($s1)
  lwc1  $f4, 0x14($v0)
  mul.s $f6, $f8, $f4
  swc1  $f6, 0x40c($sp)
  lwc1  $f10, 0x40($s1)
  lwc1  $f8, 0x14($v0)
  mul.s $f4, $f10, $f8
  swc1  $f4, 0x414($sp)
  lwc1  $f6, 0x38($s1)
  lwc1  $f10, 0x18($v0)
  mul.s $f8, $f6, $f10
  swc1  $f8, 0x400($sp)
  lwc1  $f4, 0x40($s1)
  lwc1  $f6, 0x18($v0)
  lwc1  $f8, 0x40c($sp)
  mul.s $f10, $f4, $f6
  lwc1  $f4, 0x424($sp)
  swc1  $f10, 0x408($sp)
  lw    $t8, 0x14($s3)
  sw    $t8, 0x468($sp)
  lwc1  $f0, 8($s3)
  lwc1  $f2, 0x10($s3)
  add.s $f6, $f0, $f4
  lwc1  $f4, 0x414($sp)
  mfc1  $a1, $f0
  mfc1  $a2, $f2
  add.s $f10, $f8, $f6
  lwc1  $f8, 0x42c($sp)
  add.s $f6, $f2, $f8
  mfc1  $a3, $f10
  add.s $f10, $f4, $f6
  jal   sub_GAME_7F0B0BE4
   swc1  $f10, 0x10($sp)
  beqz  $v0, .L7F047D24
   lwc1  $f4, 0x424($sp)
  lwc1  $f0, 8($s3)
  lwc1  $f8, 0x40c($sp)
  lwc1  $f2, 0x10($s3)
  add.s $f6, $f0, $f4
  lwc1  $f4, 0x414($sp)
  move  $a0, $s0
  add.s $f10, $f8, $f6
  lwc1  $f6, 0x42c($sp)
  mfc1  $a1, $f10
  add.s $f10, $f2, $f6
  add.s $f6, $f4, $f10
  lwc1  $f10, 0x418($sp)
  mfc1  $a2, $f6
  add.s $f6, $f0, $f10
  add.s $f10, $f8, $f6
  lwc1  $f8, 0x420($sp)
  add.s $f6, $f2, $f8
  mfc1  $a3, $f10
  add.s $f10, $f4, $f6
  jal   sub_GAME_7F0B0BE4
   swc1  $f10, 0x10($sp)
  beqz  $v0, .L7F047D24
   lwc1  $f4, 0x418($sp)
  lwc1  $f8, 8($s3)
  lwc1  $f6, 0x40c($sp)
  move  $a0, $s0
  add.s $f0, $f8, $f4
  lwc1  $f4, 0x420($sp)
  lwc1  $f8, 0x10($s3)
  add.s $f10, $f6, $f0
  lwc1  $f6, 0x414($sp)
  add.s $f2, $f8, $f4
  mfc1  $a1, $f10
  lwc1  $f8, 0x400($sp)
  add.s $f10, $f6, $f2
  lwc1  $f6, 0x408($sp)
  add.s $f4, $f8, $f0
  mfc1  $a2, $f10
  add.s $f10, $f6, $f2
  mfc1  $a3, $f4
  jal   sub_GAME_7F0B0BE4
   swc1  $f10, 0x10($sp)
  beqz  $v0, .L7F047D24
   lwc1  $f4, 0x418($sp)
  lwc1  $f0, 8($s3)
  lwc1  $f8, 0x400($sp)
  lwc1  $f2, 0x10($s3)
  add.s $f6, $f0, $f4
  lwc1  $f4, 0x408($sp)
  move  $a0, $s0
  add.s $f10, $f8, $f6
  lwc1  $f6, 0x420($sp)
  mfc1  $a1, $f10
  add.s $f10, $f2, $f6
  add.s $f6, $f4, $f10
  lwc1  $f10, 0x424($sp)
  mfc1  $a2, $f6
  add.s $f6, $f0, $f10
  add.s $f10, $f8, $f6
  lwc1  $f8, 0x42c($sp)
  add.s $f6, $f2, $f8
  mfc1  $a3, $f10
  add.s $f10, $f4, $f6
  jal   sub_GAME_7F0B0BE4
   swc1  $f10, 0x10($sp)
  beqz  $v0, .L7F047D24
   lwc1  $f4, 0x424($sp)
  lwc1  $f8, 8($s3)
  lwc1  $f6, 0x400($sp)
  move  $a0, $s0
  add.s $f0, $f8, $f4
  lwc1  $f4, 0x42c($sp)
  lwc1  $f8, 0x10($s3)
  add.s $f10, $f6, $f0
  lwc1  $f6, 0x408($sp)
  add.s $f2, $f8, $f4
  mfc1  $a1, $f10
  lwc1  $f8, 0x40c($sp)
  add.s $f10, $f6, $f2
  lwc1  $f6, 0x414($sp)
  add.s $f4, $f8, $f0
  mfc1  $a2, $f10
  add.s $f10, $f6, $f2
  mfc1  $a3, $f4
  jal   sub_GAME_7F0B0BE4
   swc1  $f10, 0x10($sp)
  bnez  $v0, .L7F047D28
   nop   
.L7F047D24:
  move  $s2, $zero
.L7F047D28:
  beqz  $s2, .L7F047DB8
   move  $a0, $s1
  addiu $t7, $s1, 0x58
  sw    $t7, 0x70($sp)
  jal   sub_GAME_7F044B38
   addiu $s0, $s1, 0x7c
  move  $a0, $s3
  jal   sub_GAME_7F0402B4
   move  $a1, $s0
  jal   detonate_proxmine_In_range
   lw    $a0, 0x70($sp)
  lw    $t0, 0x478($sp)
  addiu $a0, $sp, 0x450
  addiu $a1, $sp, 0x694
  beqz  $t0, .L7F047EB4
   move  $a2, $t0
  jal   sub_GAME_7F02FD50
   lui   $a3, 0x42c8
  beqz  $v0, .L7F047EB4
   nop   
  lw    $t3, 0xa8($s1)
  lw    $t9, 0xa4($s1)
  li    $at, 0x42700000 # 60.000000
  addiu $t1, $t3, 1
  sw    $t1, 0xa8($s1)
  lw    $t2, ($t9)
  sll   $t6, $t1, 2
  addu  $t5, $t2, $t6
  lw    $t8, ($t5)
  bgez  $t8, .L7F047EB4
   nop   
  mtc1  $at, $f8
  sw    $zero, 0xa4($s1)
  swc1  $f22, 0x94($s1)
  b     .L7F047EB4
   swc1  $f8, 0x98($s1)
.L7F047DB8:
  lwc1  $f4, 0x98($s1)
  li    $at, 0x42700000 # 60.000000
  c.lt.s $f4, $f22
  nop   
  bc1fl .L7F047DE4
   swc1  $f22, 0x88($s1)
  lwc1  $f6, 0x88($s1)
  mtc1  $at, $f10
  swc1  $f6, 0x94($s1)
  swc1  $f10, 0x98($s1)
  swc1  $f22, 0x88($s1)
.L7F047DE4:
  lwc1  $f8, 0x438($sp)
  move  $a0, $s1
  swc1  $f8, 0xa0($s1)
  lwc1  $f4, 0x434($sp)
  swc1  $f4, 0x9c($s1)
  lw    $t7, 0x44c($sp)
  sw    $t7, 0x14($s3)
  lwc1  $f2, 0x450($sp)
  swc1  $f2, 8($s3)
  swc1  $f2, 0x58($s1)
  lwc1  $f2, 0x454($sp)
  swc1  $f2, 0xc($s3)
  swc1  $f2, 0x5c($s1)
  lwc1  $f2, 0x458($sp)
  swc1  $f2, 0x10($s3)
  jal   sub_GAME_7F040484
   swc1  $f2, 0x60($s1)
  jal   sub_GAME_7F056CA0
   move  $a0, $s1
  b     .L7F047EB4
   nop   
.L7F047E38:
  lwc1  $f6, 0x98($s1)
.L7F047E3C:
  li    $at, 0x42700000 # 60.000000
  c.lt.s $f6, $f22
  nop   
  bc1fl .L7F047E64
   swc1  $f22, 0x88($s1)
  lwc1  $f10, 0x88($s1)
  mtc1  $at, $f8
  swc1  $f10, 0x94($s1)
  swc1  $f8, 0x98($s1)
  swc1  $f22, 0x88($s1)
.L7F047E64:
  lwc1  $f4, 0x438($sp)
  swc1  $f4, 0xa0($s1)
  lwc1  $f6, 0x434($sp)
  b     .L7F047EB4
   swc1  $f6, 0x9c($s1)
  lw    $t0, 8($s1)
.L7F047E7C:
  sll   $t3, $t0, 2
  bgez  $t3, .L7F047EB4
   nop   
  lwc1  $f12, 0x38($s1)
  jal   convert_angle_using_inverse
   lwc1  $f14, 0x40($s1)
  lw    $t1, 8($s1)
  lui   $at, (0xDFFFFFFF >> 16) # lui $at, 0xdfff
  ori   $at, (0xDFFFFFFF & 0xFFFF) # ori $at, $at, 0xffff
  and   $t9, $t1, $at
  swc1  $f0, 0xa0($s1)
  sw    $t9, 8($s1)
  jal   sub_GAME_7F044B38
   move  $a0, $s1
.L7F047EB4:
  b     .L7F048230
   lbu   $v0, 3($s1)
.L7F047EBC:
  li    $at, 40
  bne   $v0, $at, .L7F04822C
   move  $a0, $s1
  jal   parse_handle_actionblocks
   li    $a1, 1
  lw    $s0, 0x14($s1)
  addiu $a1, $s1, 0x58
  lw    $t4, 0x20($s0)
  move  $a0, $s0
  beql  $t4, $zero, .L7F048078
   lwc1  $f12, 0xa0($s1)
  jal   setsuboffset
   sw    $a1, 0x70($sp)
  lw    $s0, 0x14($s1)
  lui   $t6, %hi(animation_table_ptrs2+4) 
  lw    $t6, %lo(animation_table_ptrs2+4)($t6)
  lw    $t2, 0x20($s0)
  lui   $a1, (0x4127020C >> 16) # lui $a1, 0x4127
  move  $a0, $s0
  bne   $t2, $t6, .L7F047F30
   nop   
  jal   sub_GAME_7F06CE84
   ori   $a1, (0x4127020C & 0xFFFF) # ori $a1, $a1, 0x20c
  lui   $a1, (0x40490FDB >> 16) # lui $a1, 0x4049
  ori   $a1, (0x40490FDB & 0xFFFF) # ori $a1, $a1, 0xfdb
  jal   setsubroty
   lw    $a0, 0x14($s1)
  b     .L7F047FBC
   nop   
.L7F047F30:
  jal   get_stage_num
   nop   
  li    $at, 22
  bne   $v0, $at, .L7F047F68
   lui   $a1, (0x3F859B3D >> 16) # lui $a1, 0x3f85
  lw    $a0, 0x14($s1)
  jal   sub_GAME_7F06CE84
   ori   $a1, (0x3F859B3D & 0xFFFF) # ori $a1, $a1, 0x9b3d
  lui   $a1, (0x4016CBE4 >> 16) # lui $a1, 0x4016
  ori   $a1, (0x4016CBE4 & 0xFFFF) # ori $a1, $a1, 0xcbe4
  jal   setsubroty
   lw    $a0, 0x14($s1)
  b     .L7F047FBC
   nop   
.L7F047F68:
  jal   get_stage_num
   nop   
  li    $at, 26
  bne   $v0, $at, .L7F047FA4
   lui   $a1, 0x3f85
  lui   $a1, (0x3F859B3D >> 16) # lui $a1, 0x3f85
  ori   $a1, (0x3F859B3D & 0xFFFF) # ori $a1, $a1, 0x9b3d
  jal   sub_GAME_7F06CE84
   lw    $a0, 0x14($s1)
  lui   $a1, (0x407B9B3D >> 16) # lui $a1, 0x407b
  ori   $a1, (0x407B53D1 & 0xFFFF) # ori $a1, $a1, 0x53d1
  jal   setsubroty
   lw    $a0, 0x14($s1)
  b     .L7F047FBC
   nop   
.L7F047FA4:
  lw    $a0, 0x14($s1)
  jal   sub_GAME_7F06CE84
   ori   $a1, (0x407B9B3D & 0xFFFF) # ori $a1, $a1, 0x9b3d
  mfc1  $a1, $f22
  jal   setsubroty
   lw    $a0, 0x14($s1)
.L7F047FBC:
  lui   $a1, %hi(clock_timer)
  lw    $a1, %lo(clock_timer)($a1)
  lw    $a0, 0x14($s1)
  jal   sub_GAME_7F070AEC
   li    $a2, 1
  jal   subcalcpos
   lw    $a0, 0x14($s1)
  lw    $a0, 0x14($s1)
  jal   getsuboffset
   lw    $a1, 0x70($sp)
  lwc1  $f10, 0x58($s1)
  lui   $a1, %hi(ptr_setup_path_tbl)
  addiu $a1, %lo(ptr_setup_path_tbl) # addiu $a1, $a1, 0x5d00
  swc1  $f10, 8($s3)
  lwc1  $f8, 0x60($s1)
  swc1  $f8, 0x10($s3)
  lh    $v0, 6($s1)
  slti  $at, $v0, 0x2710
  beqz  $at, .L7F048034
   sll   $t7, $v0, 4
  sll   $t5, $v0, 2
  lui   $a1, %hi(ptr_setup_path_tbl)
  subu  $t5, $t5, $v0
  addiu $a1, %lo(ptr_setup_path_tbl) # addiu $a1, $a1, 0x5d00
  sll   $t5, $t5, 2
  lw    $t8, 0x18($a1)
  subu  $t5, $t5, $v0
  sll   $t5, $t5, 2
  b     .L7F048050
   addu  $v1, $t5, $t8
.L7F048034:
  lw    $t0, 0x1c($a1)
  addu  $t7, $t7, $v0
  sll   $t7, $t7, 2
  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
  addu  $v1, $t7, $t0
  addu  $v1, $v1, $at
.L7F048050:
  lwc1  $f4, 0x5c($s1)
  lwc1  $f6, 4($v1)
  add.s $f10, $f4, $f6
  swc1  $f10, 0xc($s3)
  lwc1  $f8, 0xc($s3)
  lw    $a0, 0x14($s1)
  swc1  $f8, 0x5c($s1)
  jal   setsuboffset
   lw    $a1, 0x70($sp)
  lwc1  $f12, 0xa0($s1)
.L7F048078:
  lui   $at, %hi(global_timer_delta)
  c.le.s $f22, $f12
  nop   
  bc1fl .L7F0480E0
   lwc1  $f0, 0x94($s1)
  lwc1  $f2, %lo(global_timer_delta)($at)
  lui   $at, %hi(global_timer_delta)
  c.le.s $f12, $f2
  nop   
  bc1fl .L7F0480B8
   lwc1  $f14, 0x98($s1)
  lwc1  $f4, 0x9c($s1)
  lwc1  $f12, 0xa0($s1)
  b     .L7F0480D0
   swc1  $f4, 0x98($s1)
  lwc1  $f14, 0x98($s1)
.L7F0480B8:
  lwc1  $f6, 0x9c($s1)
  sub.s $f10, $f6, $f14
  mul.s $f8, $f10, $f2
  div.s $f4, $f8, $f12
  add.s $f6, $f14, $f4
  swc1  $f6, 0x98($s1)
.L7F0480D0:
  lwc1  $f10, %lo(global_timer_delta)($at)
  sub.s $f8, $f12, $f10
  swc1  $f8, 0xa0($s1)
  lwc1  $f0, 0x94($s1)
.L7F0480E0:
  lui   $at, %hi(global_timer_delta)
  c.le.s $f22, $f0
  nop   
  bc1fl .L7F048148
   lw    $t3, 0xc($s1)
  lwc1  $f2, %lo(global_timer_delta)($at)
  lui   $at, %hi(global_timer_delta)
  c.le.s $f0, $f2
  nop   
  bc1fl .L7F048120
   lwc1  $f12, 0x8c($s1)
  lwc1  $f4, 0x90($s1)
  lwc1  $f0, 0x94($s1)
  b     .L7F048138
   swc1  $f4, 0x8c($s1)
  lwc1  $f12, 0x8c($s1)
.L7F048120:
  lwc1  $f6, 0x90($s1)
  sub.s $f10, $f6, $f12
  mul.s $f8, $f10, $f2
  div.s $f4, $f8, $f0
  add.s $f6, $f12, $f4
  swc1  $f6, 0x8c($s1)
.L7F048138:
  lwc1  $f10, %lo(global_timer_delta)($at)
  sub.s $f8, $f0, $f10
  swc1  $f8, 0x94($s1)
  lw    $t3, 0xc($s1)
.L7F048148:
  move  $s0, $zero
  sll   $t1, $t3, 0xc
  bltz  $t1, .L7F0481A4
   nop   
  jal   check_if_object_has_not_been_destroyed
   move  $a0, $s1
  beqz  $v0, .L7F0481A4
   nop   
  lwc1  $f4, 0x8c($s1)
  c.eq.s $f22, $f4
  nop   
  bc1t  .L7F0481A4
   nop   
  lw    $t9, 8($s1)
  lui   $a1, (0x459C4000 >> 16) # lui $a1, 0x459c
  ori   $a1, (0x459C4000 & 0xFFFF) # ori $a1, $a1, 0x4000
  sll   $t4, $t9, 2
  bltz  $t4, .L7F0481A4
   addiu $a0, $s1, 0x58
  lui   $a2, (0x45BB8000 >> 16) # lui $a2, 0x45bb
  jal   sub_GAME_7F053894
   ori   $a2, (0x45BB8000 & 0xFFFF) # ori $a2, $a2, 0x8000
  move  $s0, $v0
.L7F0481A4:
  blezl $s0, .L7F04820C
   lw    $a0, 0xb0($s1)
  lw    $a0, 0xb0($s1)
  beqz  $a0, .L7F0481C8
   nop   
  jal   sfxGetArg0Unk3F
   nop   
  bnezl $v0, .L7F0481EC
   lw    $a0, 0xb0($s1)
.L7F0481C8:
  jal   get_controls_locked_flag
   nop   
  bnez  $v0, .L7F0481E8
   lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 58
  jal   play_sfx_a1
   addiu $a2, $s1, 0xb0
.L7F0481E8:
  lw    $a0, 0xb0($s1)
.L7F0481EC:
  li    $a1, 8
  beql  $a0, $zero, .L7F048230
   lbu   $v0, 3($s1)
  jal   sfx_c_70009184
   move  $a2, $s0
  b     .L7F048230
   lbu   $v0, 3($s1)
  lw    $a0, 0xb0($s1)
.L7F04820C:
  beql  $a0, $zero, .L7F048230
   lbu   $v0, 3($s1)
  jal   sfxGetArg0Unk3F
   nop   
  beql  $v0, $zero, .L7F048230
   lbu   $v0, 3($s1)
  jal   sfxDeactivate
   lw    $a0, 0xb0($s1)
.L7F04822C:
  lbu   $v0, 3($s1)
.L7F048230:
  lui   $at, %hi(D_80052B64)
  lwc1  $f20, %lo(D_80052B64)($at)
  li    $at, 47
  bnel  $v0, $at, .L7F0482C0
   li    $at, 1
  lw    $s0, 4($s3)
  addiu $a0, $s1, 0x58
  lw    $t2, 0x80($s0)
  lw    $t6, 0x84($s0)
  lw    $a3, 0x90($s0)
  mtc1  $t2, $f6
  mtc1  $t6, $f10
  cvt.s.w $f6, $f6
  cvt.s.w $f10, $f10
  mfc1  $a1, $f6
  mfc1  $a2, $f10
  jal   sub_GAME_7F0451DC
   nop   
  lw    $a0, 0x8c($s0)
  sw    $v0, 0x88($s0)
  lw    $t5, 0x674($sp)
  bltz  $a0, .L7F0482B4
   li    $at, 1
  bne   $t5, $at, .L7F0482B4
   li    $at, 255
  bne   $v0, $at, .L7F0482AC
   nop   
  jal   sub_GAME_7F0B9DBC
   move  $a1, $zero
  b     .L7F0482B4
   nop   
.L7F0482AC:
  jal   sub_GAME_7F0B9DBC
   li    $a1, 1
.L7F0482B4:
  b     .L7F0483A4
   sw    $zero, 0x670($sp)
  li    $at, 1
.L7F0482C0:
  bnel  $v0, $at, .L7F0483A8
   lbu   $t7, 3($s1)
  lhu   $t7, 0x98($s1)
  andi  $t0, $t7, 2
  beql  $t0, $zero, .L7F0483A8
   lbu   $t7, 3($s1)
  lw    $s0, 4($s3)
  mfc1  $a3, $f22
  li    $s2, 1
  lw    $t3, 0xc0($s0)
  lw    $t1, 0xc4($s0)
  addiu $a0, $s1, 0x58
  mtc1  $t3, $f8
  mtc1  $t1, $f4
  cvt.s.w $f8, $f8
  cvt.s.w $f4, $f4
  mfc1  $a1, $f8
  mfc1  $a2, $f4
  jal   sub_GAME_7F0451DC
   nop   
  sh    $v0, 0xbe($s0)
  lw    $t9, 0x674($sp)
  li    $at, 1
  bnel  $t9, $at, .L7F0483A8
   lbu   $t7, 3($s1)
  lh    $t4, 0xbe($s0)
  li    $at, 255
  bnel  $t4, $at, .L7F04834C
   move  $s2, $zero
  lwc1  $f6, 0xb4($s0)
  c.lt.s $f22, $f6
  nop   
  bc1fl .L7F048350
   lw    $v0, 8($s4)
  move  $s2, $zero
.L7F04834C:
  lw    $v0, 8($s4)
.L7F048350:
  lui   $t2, %hi(prop_door_related) 
  addiu $t2, %lo(prop_door_related) # addiu $t2, $t2, -0x5e24
  lw    $t6, 4($v0)
  bne   $t2, $t6, .L7F048384
   nop   
  lw    $t5, 8($v0)
  move  $a0, $s4
  jal   extract_id_from_object_structure_microcode
   lw    $a1, 4($t5)
  lw    $t8, ($v0)
  bnez  $t8, .L7F048384
   nop   
  move  $s2, $zero
.L7F048384:
  beqz  $s2, .L7F04839C
   nop   
  jal   sub_GAME_7F0535C4
   move  $a0, $s0
  b     .L7F0483A8
   lbu   $t7, 3($s1)
.L7F04839C:
  jal   sub_GAME_7F053598
   move  $a0, $s0
.L7F0483A4:
  lbu   $t7, 3($s1)
.L7F0483A8:
  li    $s0, 45
  bnel  $s0, $t7, .L7F0483D0
   lw    $v1, 0xc($s1)
  jal   get_ptr_for_players_tank
   nop   
  bnel  $v0, $s3, .L7F0483D0
   lw    $v1, 0xc($s1)
  b     .L7F04842C
   li    $v1, 1
  lw    $v1, 0xc($s1)
.L7F0483D0:
  sll   $t0, $v1, 5
  bgezl $t0, .L7F0483E8
   lw    $t3, 0x64($s1)
  b     .L7F04842C
   li    $v1, 1
  lw    $t3, 0x64($s1)
.L7F0483E8:
  sll   $t9, $v1, 0xc
  move  $v1, $zero
  andi  $t1, $t3, 0x800
  bnez  $t1, .L7F04842C
   nop   
  bltz  $t9, .L7F04842C
   move  $a0, $s4
  addiu $t4, $s1, 0x58
  jal   getinstsize
   sw    $t4, 0x70($sp)
  mfc1  $a2, $f0
  move  $a0, $s3
  lw    $a1, 0x70($sp)
  jal   sub_GAME_7F054D6C
   lw    $a3, 0x670($sp)
  b     .L7F04842C
   move  $v1, $v0
.L7F04842C:
  beqz  $v1, .L7F049218
   lw    $t2, 0x678($sp)
  beqz  $t2, .L7F048444
   addiu $a0, $s1, 0x78
  jal   update_color_shading
   addiu $a1, $s1, 0x7c
.L7F048444:
  lbu   $t6, 1($s3)
  ori   $t5, $t6, 2
  sb    $t5, 1($s3)
  lw    $t8, 8($s4)
  lh    $a0, 0xe($t8)
  sll   $t7, $a0, 6
  jal   sub_GAME_7F0BD714
   move  $a0, $t7
  sw    $v0, 0xc($s4)
  lbu   $t0, 3($s1)
  li    $at, 1
  move  $s2, $v0
  bne   $t0, $at, .L7F04872C
   addiu $a0, $s1, 0x18
  lw    $a0, 4($s3)
  move  $a1, $v0
  jal   sub_GAME_7F0526EC
   sw    $a0, 0x39c($sp)
  jal   get_BONDdata_field_10CC
   nop   
  move  $a0, $v0
  jal   sub_GAME_7F058098
   move  $a1, $s2
  lw    $v0, 8($s4)
  lui   $t3, %hi(prop_eyelid_door_related) 
  addiu $t3, %lo(prop_eyelid_door_related) # addiu $t3, $t3, -0x5f00
  lw    $v1, 4($v0)
  lui   $t5, %hi(prop_iris_door_related) 
  lw    $a2, 0x39c($sp)
  bne   $t3, $v1, .L7F048550
   addiu $t5, %lo(prop_iris_door_related) # addiu $t5, $t5, -0x5ea4
  lwc1  $f10, 0xb4($a2)
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f4
  mul.s $f8, $f10, $f20
  lw    $t1, 8($v0)
  addiu $a1, $s2, 0x40
  lw    $t9, 4($t1)
  div.s $f6, $f8, $f4
  lw    $s0, 4($t9)
  sw    $a1, 0x6c($sp)
  sub.s $f12, $f20, $f6
  jal   sub_GAME_7F058570
   swc1  $f12, 0x394($sp)
  move  $a0, $s0
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   lw    $a1, 0x6c($sp)
  move  $a0, $s2
  jal   sub_GAME_7F058068
   lw    $a1, 0x6c($sp)
  lw    $t4, 8($s4)
  lwc1  $f10, 0x394($sp)
  addiu $a1, $s2, 0x80
  lw    $t2, 8($t4)
  sub.s $f12, $f20, $f10
  lw    $t6, 8($t2)
  lw    $s0, 4($t6)
  jal   sub_GAME_7F058570
   sw    $a1, 0x68($sp)
  move  $a0, $s0
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   lw    $a1, 0x68($sp)
  move  $a0, $s2
  jal   sub_GAME_7F058068
   lw    $a1, 0x68($sp)
  b     .L7F0491C8
   lw    $t7, 8($s4)
.L7F048550:
  bnel  $t5, $v1, .L7F0491C8
   lw    $t7, 8($s4)
  lwc1  $f2, 0xb4($a2)
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f4
  mul.s $f8, $f2, $f20
  lui   $at, %hi(D_80052B68)
  lwc1  $f10, %lo(D_80052B68)($at)
  mov.s $f14, $f22
  div.s $f6, $f8, $f4
  swc1  $f6, 0x384($sp)
  lwc1  $f12, 0x84($a2)
  mul.s $f0, $f12, $f10
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F04860C
   lw    $t0, 0x678($sp)
  sub.s $f8, $f2, $f0
  li    $at, 0x43B40000 # 360.000000
  lw    $t8, 0x678($sp)
  sub.s $f6, $f12, $f0
  mul.s $f4, $f12, $f8
  div.s $f10, $f4, $f6
  mtc1  $at, $f4
  mul.s $f8, $f10, $f20
  div.s $f14, $f8, $f4
  beqz  $t8, .L7F048600
   swc1  $f14, 0x380($sp)
  lwc1  $f6, 0x67c($sp)
  swc1  $f14, 0x380($sp)
  lui   $a0, %hi(ptr_sfx_buf)
  c.le.s $f6, $f0
  li    $a1, 202
  move  $a2, $zero
  addiu $t7, $s3, 8
  bc1f  .L7F048600
   nop   
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  sw    $t7, 0x70($sp)
  jal   play_sfx_a1
   swc1  $f14, 0x380($sp)
  move  $a0, $v0
  jal   sub_GAME_7F053A10
   lw    $a1, 0x70($sp)
.L7F048600:
  b     .L7F04865C
   sw    $zero, 0x38c($sp)
  lw    $t0, 0x678($sp)
.L7F04860C:
  swc1  $f14, 0x380($sp)
  beql  $t0, $zero, .L7F04865C
   sw    $zero, 0x38c($sp)
  lwc1  $f10, 0x67c($sp)
  swc1  $f14, 0x380($sp)
  lui   $a0, %hi(ptr_sfx_buf)
  c.lt.s $f0, $f10
  li    $a1, 203
  move  $a2, $zero
  addiu $t3, $s3, 8
  bc1fl .L7F04865C
   sw    $zero, 0x38c($sp)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  sw    $t3, 0x70($sp)
  jal   play_sfx_a1
   swc1  $f14, 0x380($sp)
  move  $a0, $v0
  jal   sub_GAME_7F053A10
   lw    $a1, 0x70($sp)
  sw    $zero, 0x38c($sp)
.L7F04865C:
  lw    $t1, 8($s4)
  lw    $v1, 0x38c($sp)
  lwc1  $f12, 0x380($sp)
  lw    $t9, 8($t1)
  sll   $v0, $v1, 1
  sll   $t4, $v0, 2
  addu  $t2, $t9, $t4
  lw    $t6, 4($t2)
  sll   $t8, $v0, 6
  addu  $a1, $s2, $t8
  lw    $t5, 4($t6)
  sw    $v0, 0x74($sp)
  addiu $a1, $a1, 0x40
  jal   sub_GAME_7F058688
   sw    $t5, 0x390($sp)
  lw    $t7, 0x74($sp)
  lw    $s0, 0x38c($sp)
  lw    $a0, 0x390($sp)
  sll   $t0, $t7, 6
  addu  $a1, $s2, $t0
  addiu $a1, $a1, 0x40
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   sw    $a1, 0x70($sp)
  move  $a0, $s2
  jal   sub_GAME_7F058068
   lw    $a1, 0x70($sp)
  lw    $t3, 8($s4)
  lw    $v0, 0x74($sp)
  lwc1  $f12, 0x384($sp)
  lw    $t1, 8($t3)
  addiu $v0, $v0, 2
  sll   $t9, $v0, 2
  addu  $t4, $t1, $t9
  lw    $t2, ($t4)
  sll   $t5, $v0, 6
  addu  $a1, $s2, $t5
  lw    $t6, 4($t2)
  sw    $a1, 0x6c($sp)
  jal   sub_GAME_7F058688
   sw    $t6, 0x390($sp)
  lw    $a0, 0x390($sp)
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   lw    $a1, 0x6c($sp)
  lw    $a0, 0x70($sp)
  jal   sub_GAME_7F058068
   lw    $a1, 0x6c($sp)
  addiu $s0, $s0, 1
  li    $at, 6
  bne   $s0, $at, .L7F04865C
   sw    $s0, 0x38c($sp)
  b     .L7F0491C8
   lw    $t7, 8($s4)
.L7F04872C:
  addiu $t8, $s1, 0x58
  sw    $t8, 0x70($sp)
  jal   sub_GAME_7F058020
   addiu $a1, $sp, 0x3a4
  lw    $a0, 0x70($sp)
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   addiu $a1, $sp, 0x3a4
  jal   get_BONDdata_field_10CC
   nop   
  move  $a0, $v0
  addiu $a1, $sp, 0x3a4
  jal   sub_GAME_7F05818C
   move  $a2, $s2
  lbu   $v0, 3($s1)
  li    $at, 6
  addiu $a1, $sp, 0x320
  bnel  $v0, $at, .L7F048824
   li    $at, 13
  lw    $v0, 4($s3)
  lw    $t7, 8($s4)
  lwc1  $f12, 0xc8($v0)
  lw    $t0, 8($t7)
  c.lt.s $f12, $f22
  lw    $t3, ($t0)
  bc1f  .L7F04879C
   lw    $s0, 4($t3)
  b     .L7F0487B0
   add.s $f12, $f12, $f20
.L7F04879C:
  c.le.s $f20, $f12
  nop   
  bc1f  .L7F0487B0
   nop   
  sub.s $f12, $f12, $f20
.L7F0487B0:
  jal   sub_GAME_7F0585FC
   sw    $v0, 0x370($sp)
  lw    $v0, 0x370($sp)
  addiu $a2, $s2, 0x40
  sw    $a2, 0x6c($sp)
  addiu $a0, $sp, 0x320
  jal   sub_GAME_7F0580C8
   addiu $a1, $v0, 0x84
  lwc1  $f8, ($s0)
  addiu $s2, $sp, 0x360
  move  $a1, $s2
  swc1  $f8, 0x360($sp)
  lwc1  $f4, 4($s0)
  addiu $a0, $sp, 0x3a4
  swc1  $f4, 0x364($sp)
  lwc1  $f6, 8($s0)
  jal   sub_GAME_7F058474
   swc1  $f6, 0x368($sp)
  move  $a0, $s2
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   lw    $a1, 0x6c($sp)
  jal   get_BONDdata_field_10CC
   nop   
  move  $a0, $v0
  jal   sub_GAME_7F058098
   lw    $a1, 0x6c($sp)
  b     .L7F0491C8
   lw    $t7, 8($s4)
  li    $at, 13
.L7F048824:
  bnel  $v0, $at, .L7F048A24
   li    $at, 8
  lw    $v0, 4($s3)
  lui   $at, %hi(D_80052B6C)
  lwc1  $f8, %lo(D_80052B6C)($at)
  lwc1  $f10, 0x90($v0)
  lwc1  $f4, 0x9c($v0)
  add.s $f12, $f10, $f8
  neg.s $f6, $f4
  c.le.s $f20, $f12
  swc1  $f6, 0x300($sp)
  bc1fl .L7F048860
   lw    $t1, 8($s4)
  sub.s $f12, $f12, $f20
  lw    $t1, 8($s4)
.L7F048860:
  addiu $a0, $sp, 0x3a4
  addiu $a1, $sp, 0x308
  lw    $t9, 8($t1)
  lw    $t4, 4($t9)
  lw    $s0, 4($t4)
  lwc1  $f10, ($s0)
  swc1  $f10, 0x308($sp)
  lwc1  $f8, 4($s0)
  swc1  $f8, 0x30c($sp)
  lwc1  $f4, 8($s0)
  swc1  $f12, 0x304($sp)
  sw    $v0, 0x318($sp)
  jal   sub_GAME_7F058474
   swc1  $f4, 0x310($sp)
  addiu $a1, $s2, 0x40
  lwc1  $f12, 0x304($sp)
  jal   sub_GAME_7F0585FC
   sw    $a1, 0x6c($sp)
  addiu $a0, $sp, 0x308
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   lw    $a1, 0x6c($sp)
  lw    $t2, 0x318($sp)
  lw    $a1, 0x6c($sp)
  lw    $t6, 0x14($t2)
  jal   matrix_multiply_A1_by_F12
   lwc1  $f12, 0x14($t6)
  jal   get_BONDdata_field_10CC
   nop   
  move  $a0, $v0
  jal   sub_GAME_7F058098
   lw    $a1, 0x6c($sp)
  lw    $t5, 8($s4)
  addiu $a1, $s2, 0x80
  lwc1  $f12, 0x300($sp)
  lw    $t8, 8($t5)
  lw    $t7, 8($t8)
  lw    $s0, 4($t7)
  jal   sub_GAME_7F058688
   sw    $a1, 0x68($sp)
  move  $a0, $s0
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   lw    $a1, 0x68($sp)
  lw    $a0, 0x6c($sp)
  jal   sub_GAME_7F058098
   lw    $a1, 0x68($sp)
  lw    $t0, 8($s4)
  move  $a0, $s4
  lw    $v1, 8($t0)
  lw    $a1, 0xc($v1)
  beql  $a1, $zero, .L7F048980
   lw    $a1, 0x10($v1)
  jal   sub_GAME_7F06C660
   move  $a2, $zero
  sw    $v0, 0x2fc($sp)
  lw    $t3, 8($s4)
  lw    $t4, 0x318($sp)
  move  $a1, $v0
  lw    $t1, 8($t3)
  lwc1  $f12, 0xb4($t4)
  lw    $t9, 0xc($t1)
  jal   sub_GAME_7F058570
   lw    $s0, 4($t9)
  lw    $s2, 0x2fc($sp)
  move  $a0, $s0
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   move  $a1, $s2
  lw    $a0, 0x68($sp)
  jal   sub_GAME_7F058098
   move  $a1, $s2
  lw    $t2, 8($s4)
  lw    $v1, 8($t2)
  lw    $a1, 0x10($v1)
.L7F048980:
  move  $a0, $s4
  beql  $a1, $zero, .L7F0489C8
   lw    $a1, 0x18($v1)
  jal   sub_GAME_7F06C660
   move  $a2, $zero
  lw    $t6, 8($s4)
  move  $s2, $v0
  move  $a1, $v0
  lw    $t5, 8($t6)
  lw    $t8, 0x10($t5)
  jal   init_something_copy_posdata_to_it
   lw    $a0, 4($t8)
  lw    $a0, 0x68($sp)
  jal   sub_GAME_7F058098
   move  $a1, $s2
  lw    $t7, 8($s4)
  lw    $v1, 8($t7)
  lw    $a1, 0x18($v1)
.L7F0489C8:
  move  $a0, $s4
  beql  $a1, $zero, .L7F0491C8
   lw    $t7, 8($s4)
  jal   sub_GAME_7F06C660
   move  $a2, $zero
  lw    $t0, 8($s4)
  lw    $t9, 0x318($sp)
  move  $s2, $v0
  lw    $t3, 8($t0)
  move  $a1, $v0
  lwc1  $f12, 0xb4($t9)
  lw    $t1, 0x18($t3)
  jal   sub_GAME_7F058570
   lw    $s0, 4($t1)
  move  $a0, $s0
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   move  $a1, $s2
  lw    $a0, 0x68($sp)
  jal   sub_GAME_7F058098
   move  $a1, $s2
  b     .L7F0491C8
   lw    $t7, 8($s4)
  li    $at, 8
.L7F048A24:
  bnel  $v0, $at, .L7F048A84
   li    $at, 12
  lw    $t4, 8($s4)
  li    $v0, 1
  addiu $a0, $s2, 0x40
  lh    $t2, 0xe($t4)
  slti  $at, $t2, 2
  bnezl $at, .L7F0491C8
   lw    $t7, 8($s4)
  sw    $v0, 0x2f8($sp)
.L7F048A4C:
  jal   reset_array_of_0x10_floats
   sw    $a0, 0x74($sp)
  lw    $t6, 8($s4)
  lw    $v0, 0x2f8($sp)
  lw    $a0, 0x74($sp)
  lh    $t5, 0xe($t6)
  addiu $v0, $v0, 1
  addiu $a0, $a0, 0x40
  slt   $at, $v0, $t5
  bnezl $at, .L7F048A4C
   sw    $v0, 0x2f8($sp)
  b     .L7F0491C8
   lw    $t7, 8($s4)
  li    $at, 12
.L7F048A84:
  bnel  $v0, $at, .L7F048B38
   li    $at, 39
  lw    $t8, 8($s4)
  addiu $a1, $s2, 0x40
  lw    $t7, 8($t8)
  lw    $t0, ($t7)
  lw    $a0, 4($t0)
  jal   init_something_copy_posdata_to_it
   sw    $a1, 0x6c($sp)
  move  $a0, $s2
  jal   sub_GAME_7F058098
   lw    $a1, 0x6c($sp)
  lw    $t3, 8($s4)
  addiu $a1, $s2, 0x80
  lw    $t1, 8($t3)
  lw    $t9, 4($t1)
  lw    $a0, 4($t9)
  jal   init_something_copy_posdata_to_it
   sw    $a1, 0x68($sp)
  move  $a0, $s2
  jal   sub_GAME_7F058098
   lw    $a1, 0x68($sp)
  lw    $t4, 8($s4)
  addiu $a1, $s2, 0xc0
  lw    $t2, 8($t4)
  lw    $t6, 8($t2)
  lw    $a0, 4($t6)
  jal   init_something_copy_posdata_to_it
   sw    $a1, 0x74($sp)
  move  $a0, $s2
  jal   sub_GAME_7F058098
   lw    $a1, 0x74($sp)
  lw    $t5, 8($s4)
  addiu $s0, $s2, 0x100
  move  $a1, $s0
  lw    $t8, 8($t5)
  lw    $t7, 0xc($t8)
  jal   init_something_copy_posdata_to_it
   lw    $a0, 4($t7)
  move  $a0, $s2
  jal   sub_GAME_7F058098
   move  $a1, $s0
  b     .L7F0491C8
   lw    $t7, 8($s4)
  li    $at, 39
.L7F048B38:
  bnel  $v0, $at, .L7F048E20
   li    $at, 40
  lw    $t0, 8($s4)
  lw    $t7, 0x678($sp)
  mov.s $f0, $f22
  lw    $v1, 8($t0)
  lw    $t3, 4($v1)
  lw    $t1, 4($t3)
  sw    $t1, 0x260($sp)
  lw    $t9, 8($v1)
  lw    $t4, 4($t9)
  sw    $t4, 0x25c($sp)
  lw    $t6, 0x10($v1)
  lw    $t2, 0xc($v1)
  lw    $t5, 4($t6)
  lw    $s0, 4($t2)
  sw    $t5, 0x254($sp)
  lw    $t8, 0x18($v1)
  lwc1  $f4, 0x14($s4)
  lw    $v0, 4($t8)
  lwc1  $f6, 0x10($v0)
  lwc1  $f10, 0xc($v0)
  sub.s $f8, $f6, $f10
  mul.s $f2, $f8, $f4
  beqz  $t7, .L7F048C34
   lui   $at, %hi(global_timer_delta)
  lwc1  $f10, %lo(global_timer_delta)($at)
  lwc1  $f6, 0x88($s1)
  li    $at, 0x3F000000 # 0.500000
  mul.s $f8, $f6, $f10
  mtc1  $at, $f10
  mul.s $f4, $f8, $f20
  nop   
  mul.s $f6, $f2, $f20
  nop   
  mul.s $f8, $f6, $f10
  lwc1  $f6, 0x8c($s1)
  div.s $f0, $f4, $f8
  add.s $f10, $f6, $f0
  swc1  $f10, 0x8c($s1)
  lwc1  $f12, 0x8c($s1)
  c.le.s $f20, $f12
  nop   
  bc1f  .L7F048C08
   nop   
  sub.s $f4, $f12, $f20
.L7F048BF0:
  swc1  $f4, 0x8c($s1)
  lwc1  $f12, 0x8c($s1)
  c.le.s $f20, $f12
  nop   
  bc1tl .L7F048BF0
   sub.s $f4, $f12, $f20
.L7F048C08:
  c.lt.s $f12, $f22
  nop   
  bc1fl .L7F048C38
   lwc1  $f6, 0x8c($s1)
  add.s $f8, $f12, $f20
.L7F048C1C:
  swc1  $f8, 0x8c($s1)
  lwc1  $f12, 0x8c($s1)
  c.lt.s $f12, $f22
  nop   
  bc1tl .L7F048C1C
   add.s $f8, $f12, $f20
.L7F048C34:
  lwc1  $f6, 0x8c($s1)
.L7F048C38:
  add.s $f10, $f6, $f0
  swc1  $f10, 0x8c($s1)
  lwc1  $f12, 0x8c($s1)
  c.le.s $f20, $f12
  nop   
  bc1fl .L7F048C74
   c.lt.s $f12, $f22
  sub.s $f4, $f12, $f20
.L7F048C58:
  swc1  $f4, 0x8c($s1)
  lwc1  $f12, 0x8c($s1)
  c.le.s $f20, $f12
  nop   
  bc1tl .L7F048C58
   sub.s $f4, $f12, $f20
  c.lt.s $f12, $f22
.L7F048C74:
  nop   
  bc1f  .L7F048C9C
   nop   
  add.s $f8, $f12, $f20
.L7F048C84:
  swc1  $f8, 0x8c($s1)
  lwc1  $f12, 0x8c($s1)
  c.lt.s $f12, $f22
  nop   
  bc1tl .L7F048C84
   add.s $f8, $f12, $f20
.L7F048C9C:
  jal   sub_GAME_7F058570
   addiu $a1, $sp, 0x2ac
  lwc1  $f6, 0x88($s1)
  c.lt.s $f22, $f6
  nop   
  bc1fl .L7F048D60
   lwc1  $f12, 0x90($s1)
  lw    $t0, 0x260($sp)
  lwc1  $f10, 8($s0)
  lwc1  $f12, 0x9c($s1)
  lwc1  $f4, 8($t0)
  lwc1  $f6, 0x14($s4)
  c.lt.s $f12, $f22
  sub.s $f8, $f10, $f4
  mul.s $f2, $f8, $f6
  bc1fl .L7F048CE8
   swc1  $f2, 0x250($sp)
  neg.s $f12, $f12
  swc1  $f2, 0x250($sp)
.L7F048CE8:
  jal   sinf
   swc1  $f12, 0x24c($sp)
  lwc1  $f2, 0x250($sp)
  lwc1  $f12, 0x24c($sp)
  mul.s $f10, $f0, $f2
  jal   cosf
   swc1  $f10, 0x248($sp)
  lwc1  $f2, 0x250($sp)
  lwc1  $f8, 0x88($s1)
  lwc1  $f12, 0x248($sp)
  mul.s $f4, $f0, $f2
  sub.s $f6, $f2, $f8
  jal   convert_angle_using_inverse
   sub.s $f14, $f4, $f6
  lwc1  $f2, 0x24c($sp)
  swc1  $f0, 0x90($s1)
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F048D40
   lwc1  $f10, 0x9c($s1)
  swc1  $f2, 0x90($s1)
  lwc1  $f10, 0x9c($s1)
.L7F048D40:
  c.lt.s $f22, $f10
  nop   
  bc1fl .L7F048D60
   lwc1  $f12, 0x90($s1)
  lwc1  $f8, 0x90($s1)
  sub.s $f4, $f20, $f8
  swc1  $f4, 0x90($s1)
  lwc1  $f12, 0x90($s1)
.L7F048D60:
  jal   sub_GAME_7F0585FC
   addiu $a1, $sp, 0x26c
  addiu $a1, $s2, 0xc0
  sw    $a1, 0x74($sp)
  jal   sub_GAME_7F058020
   addiu $a0, $sp, 0x2ac
  move  $a0, $s0
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   lw    $a1, 0x74($sp)
  move  $a0, $s2
  jal   sub_GAME_7F058098
   lw    $a1, 0x74($sp)
  addiu $s0, $s2, 0x100
  move  $a1, $s0
  jal   sub_GAME_7F058020
   addiu $a0, $sp, 0x2ac
  lw    $a0, 0x254($sp)
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   move  $a1, $s0
  move  $a0, $s2
  jal   sub_GAME_7F058098
   move  $a1, $s0
  addiu $a0, $sp, 0x26c
  jal   sub_GAME_7F058098
   addiu $a1, $sp, 0x2ac
  addiu $a1, $s2, 0x40
  sw    $a1, 0x6c($sp)
  jal   sub_GAME_7F058020
   addiu $a0, $sp, 0x2ac
  lw    $a0, 0x260($sp)
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   lw    $a1, 0x6c($sp)
  move  $a0, $s2
  jal   sub_GAME_7F058098
   lw    $a1, 0x6c($sp)
  addiu $a1, $s2, 0x80
  sw    $a1, 0x68($sp)
  jal   sub_GAME_7F058020
   addiu $a0, $sp, 0x2ac
  lw    $a0, 0x25c($sp)
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   lw    $a1, 0x68($sp)
  move  $a0, $s2
  jal   sub_GAME_7F058098
   lw    $a1, 0x68($sp)
  b     .L7F0491C8
   lw    $t7, 8($s4)
  li    $at, 40
.L7F048E20:
  bne   $v0, $at, .L7F04903C
   nop   
  lw    $t3, 8($s4)
  lui   $t2, %hi(clock_timer) 
  lw    $t2, %lo(clock_timer)($t2)
  lw    $t1, 8($t3)
  lw    $t6, 0x678($sp)
  addiu $s0, $sp, 0x1b0
  lw    $t9, 8($t1)
  lui   $t7, %hi(D_80030B34) 
  move  $a0, $s2
  lw    $t4, 4($t9)
  addiu $a1, $s2, 0x40
  blez  $t2, .L7F048ED0
   sw    $t4, 0x1fc($sp)
  beql  $t6, $zero, .L7F048ED4
   lw    $t5, 0x14($s1)
  lwc1  $f6, 0x88($s1)
  lwc1  $f10, 0x8c($s1)
  add.s $f8, $f6, $f10
  swc1  $f8, 0x88($s1)
  lwc1  $f0, 0x88($s1)
  c.le.s $f20, $f0
  nop   
  bc1fl .L7F048EA8
   c.lt.s $f0, $f22
  sub.s $f4, $f0, $f20
.L7F048E8C:
  swc1  $f4, 0x88($s1)
  lwc1  $f0, 0x88($s1)
  c.le.s $f20, $f0
  nop   
  bc1tl .L7F048E8C
   sub.s $f4, $f0, $f20
  c.lt.s $f0, $f22
.L7F048EA8:
  nop   
  bc1fl .L7F048ED4
   lw    $t5, 0x14($s1)
  add.s $f6, $f0, $f20
.L7F048EB8:
  swc1  $f6, 0x88($s1)
  lwc1  $f0, 0x88($s1)
  c.lt.s $f0, $f22
  nop   
  bc1tl .L7F048EB8
   add.s $f6, $f0, $f20
.L7F048ED0:
  lw    $t5, 0x14($s1)
.L7F048ED4:
  addiu $t7, %lo(D_80030B34) # addiu $t7, $t7, 0xb34
  addiu $t3, $t7, 0x3c
  lw    $t8, 0x20($t5)
  move  $t1, $s0
  beqz  $t8, .L7F048F3C
   nop   
.L7F048EEC:
  lw    $at, ($t7)
  addiu $t7, $t7, 0xc
  addiu $t1, $t1, 0xc
  sw    $at, -0xc($t1)
  lw    $at, -8($t7)
  sw    $at, -8($t1)
  lw    $at, -4($t7)
  bne   $t7, $t3, .L7F048EEC
   sw    $at, -4($t1)
  lw    $at, ($t7)
  jal   get_BONDdata_field_10CC
   sw    $at, ($t1)
  sw    $v0, 0x1b0($sp)
  sw    $s2, 0x1c0($sp)
  lw    $a1, 0x14($s1)
  jal   subcalcmatrices
   move  $a0, $s0
  addiu $t9, $s2, 0x40
  b     .L7F048F44
   sw    $t9, 0x6c($sp)
.L7F048F3C:
  jal   sub_GAME_7F058020
   sw    $a1, 0x6c($sp)
.L7F048F44:
  lw    $t4, 8($s1)
  addiu $a1, $sp, 0x200
  sll   $t2, $t4, 2
  bgez  $t2, .L7F048F6C
   nop   
  lwc1  $f12, 0x88($s1)
  jal   sub_GAME_7F058688
   addiu $a1, $sp, 0x200
  b     .L7F048F78
   addiu $a1, $s2, 0x80
.L7F048F6C:
  jal   sub_GAME_7F0585FC
   lwc1  $f12, 0x88($s1)
  addiu $a1, $s2, 0x80
.L7F048F78:
  sw    $a1, 0x68($sp)
  jal   sub_GAME_7F058020
   addiu $a0, $sp, 0x200
  lw    $a0, 0x1fc($sp)
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   lw    $a1, 0x68($sp)
  lw    $a0, 0x6c($sp)
  jal   sub_GAME_7F058098
   lw    $a1, 0x68($sp)
  lw    $t6, 8($s4)
  move  $a0, $s4
  move  $a2, $zero
  lw    $v1, 8($t6)
  lw    $a1, 0xc($v1)
  beql  $a1, $zero, .L7F049000
   lw    $a1, 0x10($v1)
  jal   sub_GAME_7F06C660
   lw    $s2, 4($a1)
  move  $s0, $v0
  lwc1  $f12, 0x88($s1)
  jal   sub_GAME_7F058570
   addiu $a1, $sp, 0x200
  addiu $a0, $sp, 0x200
  jal   sub_GAME_7F058020
   move  $a1, $s0
  move  $a0, $s2
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   move  $a1, $s0
  lw    $a0, 0x6c($sp)
  jal   sub_GAME_7F058098
   move  $a1, $s0
  lw    $t5, 8($s4)
  lw    $v1, 8($t5)
  lw    $a1, 0x10($v1)
.L7F049000:
  move  $a0, $s4
  move  $a2, $zero
  beql  $a1, $zero, .L7F0491C8
   lw    $t7, 8($s4)
  jal   sub_GAME_7F06C660
   lw    $s2, 4($a1)
  move  $s0, $v0
  move  $a0, $s2
  jal   init_something_copy_posdata_to_it
   move  $a1, $v0
  lw    $a0, 0x6c($sp)
  jal   sub_GAME_7F058098
   move  $a1, $s0
  b     .L7F0491C8
   lw    $t7, 8($s4)
.L7F04903C:
  bne   $s0, $v0, .L7F0491C4
   addiu $a1, $s2, 0x40
  lw    $t8, 8($s4)
  lw    $v1, 8($t8)
  lw    $t3, 0xc($v1)
  lw    $t0, 4($v1)
  lw    $t7, 4($t3)
  lw    $s0, 4($t0)
  sw    $t7, 0x164($sp)
  lw    $t1, 0x10($v1)
  lw    $t9, 4($t1)
  sw    $t9, 0x160($sp)
  lw    $t4, 8($v1)
  lw    $t2, 4($t4)
  sw    $t2, 0x15c($sp)
  lw    $t6, 0x18($v1)
  lw    $t5, 4($t6)
  sw    $t5, 0x158($sp)
  lwc1  $f14, 0xc8($s1)
  neg.s $f14, $f14
  c.lt.s $f14, $f22
  nop   
  bc1fl .L7F0490A4
   lwc1  $f12, 0xcc($s1)
  add.s $f14, $f14, $f20
  lwc1  $f12, 0xcc($s1)
.L7F0490A4:
  neg.s $f12, $f12
  c.lt.s $f12, $f22
  nop   
  bc1fl .L7F0490C0
   sw    $a1, 0x6c($sp)
  add.s $f12, $f12, $f20
  sw    $a1, 0x6c($sp)
.L7F0490C0:
  jal   sub_GAME_7F0585FC
   swc1  $f14, 0x154($sp)
  move  $a0, $s0
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   lw    $a1, 0x6c($sp)
  move  $a0, $s2
  jal   sub_GAME_7F058098
   lw    $a1, 0x6c($sp)
  addiu $a1, $s2, 0xc0
  lwc1  $f12, 0x154($sp)
  jal   sub_GAME_7F058570
   sw    $a1, 0x74($sp)
  lw    $a0, 0x164($sp)
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   lw    $a1, 0x74($sp)
  lw    $a0, 0x6c($sp)
  jal   sub_GAME_7F058098
   lw    $a1, 0x74($sp)
  lui   $at, %hi(D_80052B70)
  addiu $s0, $s2, 0x100
  move  $a1, $s0
  jal   sub_GAME_7F0585FC
   lwc1  $f12, %lo(D_80052B70)($at)
  lw    $a0, 0x160($sp)
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   move  $a1, $s0
  lw    $a0, 0x74($sp)
  jal   sub_GAME_7F058098
   move  $a1, $s0
  addiu $a1, $s2, 0x80
  sw    $a1, 0x68($sp)
  jal   init_something_copy_posdata_to_it
   lw    $a0, 0x15c($sp)
  lw    $a0, 0x6c($sp)
  jal   sub_GAME_7F058098
   lw    $a1, 0x68($sp)
  jal   sub_GAME_7F078444
   nop   
  addiu $s0, $sp, 0x16c
  move  $a2, $s0
  move  $a0, $v0
  jal   sub_GAME_7F05818C
   lw    $a1, 0x6c($sp)
  lw    $a0, 0x158($sp)
  move  $a1, $s0
  addiu $a2, $s1, 0x84
  jal   sub_GAME_7F03F540
   addiu $a3, $s1, 0x80
  lw    $t8, 8($s4)
  lw    $v1, 8($t8)
  lw    $a1, 0x1c($v1)
  beql  $a1, $zero, .L7F0491B0
   lw    $a1, 0x20($v1)
  jal   extract_id_from_object_structure_microcode
   move  $a0, $s4
  lw    $t0, 0xc4($s1)
  sh    $t0, ($v0)
  lw    $t3, 8($s4)
  lw    $v1, 8($t3)
  lw    $a1, 0x20($v1)
.L7F0491B0:
  beql  $a1, $zero, .L7F0491C8
   lw    $t7, 8($s4)
  jal   extract_id_from_object_structure_microcode
   move  $a0, $s4
  sw    $zero, ($v0)
.L7F0491C4:
  lw    $t7, 8($s4)
.L7F0491C8:
  move  $a0, $s4
  jal   sub_GAME_7F06EEA4
   lw    $a1, ($t7)
  lw    $t1, 0xc($s4)
  move  $a0, $s3
  lwc1  $f10, 0x38($t1)
  neg.s $f8, $f10
  jal   handle_thrown_explosive_detonation
   swc1  $f8, 0x18($s3)
  lw    $a0, 0x20($s3)
  beql  $a0, $zero, .L7F049254
   lw    $v1, 0x64($s1)
  lw    $v0, 0x24($a0)
.L7F0491FC:
  jal   sub_GAME_7F0442DC
   sw    $v0, 0x684($sp)
  lw    $a0, 0x684($sp)
  bnezl $a0, .L7F0491FC
   lw    $v0, 0x24($a0)
  b     .L7F049254
   lw    $v1, 0x64($s1)
.L7F049218:
  lbu   $t9, 1($s3)
  move  $a0, $s3
  andi  $t4, $t9, 0xfffd
  jal   handle_thrown_explosive_detonation
   sb    $t4, 1($s3)
  lw    $a0, 0x20($s3)
  beql  $a0, $zero, .L7F049254
   lw    $v1, 0x64($s1)
  lw    $v0, 0x24($a0)
.L7F04923C:
  jal   sub_GAME_7F04424C
   sw    $v0, 0x684($sp)
  lw    $a0, 0x684($sp)
  bnezl $a0, .L7F04923C
   lw    $v0, 0x24($a0)
  lw    $v1, 0x64($s1)
.L7F049254:
  li    $at, -257
  addiu $t5, $s3, 8
  andi  $t2, $v1, 0x100
  beqz  $t2, .L7F0492E0
   and   $t6, $v1, $at
  sw    $t6, 0x64($s1)
  jal   get_random_value
   sw    $t5, 0x70($sp)
  mtc1  $v0, $f4
  move  $a0, $s1
  bgez  $v0, .L7F049294
   cvt.s.w $f6, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f10
  nop   
  add.s $f6, $f6, $f10
.L7F049294:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f8
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f10
  mul.s $f4, $f6, $f8
  li    $at, 0x40000000 # 2.000000
  mtc1  $at, $f8
  lw    $t8, 0x64($s1)
  lui   $at, 6
  lw    $a2, 0x70($sp)
  and   $t0, $t8, $at
  mul.s $f6, $f4, $f10
  move  $a3, $zero
  srl   $t3, $t0, 0x11
  sw    $t3, 0x10($sp)
  add.s $f4, $f6, $f8
  mfc1  $a1, $f4
  jal   maybe_detonate_object
   nop   
.L7F0492E0:
  lw    $t7, 0x678($sp)
  beql  $t7, $zero, .L7F049B1C
   lw    $t1, 0x680($sp)
  lbu   $v0, 3($s1)
  li    $at, 1
  bnel  $v0, $at, .L7F049310
   li    $at, 13
  jal   sub_GAME_7F053A3C
   lw    $a0, 4($s3)
  b     .L7F049B10
   nop   
  li    $at, 13
.L7F049310:
  bne   $v0, $at, .L7F049B10
   nop   
  jal   get_controls_locked_flag
   nop   
  bnez  $v0, .L7F049B10
   nop   
  lw    $s0, 4($s3)
  sw    $zero, 0x13c($sp)
  sw    $zero, 0x138($sp)
  lw    $t1, 0xd0($s0)
  beql  $t1, $zero, .L7F049ACC
   lw    $t8, 8($s4)
  lw    $t9, 8($s1)
  sll   $t4, $t9, 3
  bltzl $t4, .L7F049ACC
   lw    $t8, 8($s4)
  lw    $t2, 0xac($s0)
  lui   $t4, %hi(global_timer) 
  addiu $t6, $t2, 1
  andi  $t5, $t6, 1
  sw    $t6, 0xac($s0)
  sltiu $t8, $t5, 1
  sw    $t8, 0x13c($sp)
  lw    $t0, 8($s4)
  xori  $t1, $t5, 1
  sltiu $t1, $t1, 1
  lw    $t3, 8($t0)
  lw    $t7, 0x14($t3)
  beql  $t7, $zero, .L7F049390
   lw    $t9, 0xc0($s0)
  sw    $t1, 0x138($sp)
  lw    $t9, 0xc0($s0)
.L7F049390:
  lw    $t4, %lo(global_timer)($t4)
  slt   $at, $t9, $t4
  beql  $at, $zero, .L7F049464
   lw    $t7, 0x13c($sp)
  lw    $a0, 0xc4($s0)
  beql  $a0, $zero, .L7F0493C8
   lw    $a0, 0xc8($s0)
  jal   sfxGetArg0Unk3F
   nop   
  beql  $v0, $zero, .L7F0493C8
   lw    $a0, 0xc8($s0)
  jal   sfxDeactivate
   lw    $a0, 0xc4($s0)
  lw    $a0, 0xc8($s0)
.L7F0493C8:
  beql  $a0, $zero, .L7F0493EC
   lw    $t2, 0xc4($s0)
  jal   sfxGetArg0Unk3F
   nop   
  beql  $v0, $zero, .L7F0493EC
   lw    $t2, 0xc4($s0)
  jal   sfxDeactivate
   lw    $a0, 0xc8($s0)
  lw    $t2, 0xc4($s0)
.L7F0493EC:
  lui   $a0, %hi(ptr_sfx_buf)
  li    $a1, 253
  bnez  $t2, .L7F049420
   addiu $a2, $s0, 0xc4
  addiu $t6, $s3, 8
  sw    $t6, 0x70($sp)
  jal   play_sfx_a1
   lw    $a0, %lo(ptr_sfx_buf)($a0)
  lw    $a0, 0xc4($s0)
  jal   sub_GAME_7F053A10
   lw    $a1, 0x70($sp)
  b     .L7F049450
   nop   
.L7F049420:
  lw    $t5, 0xc8($s0)
  lui   $a0, %hi(ptr_sfx_buf)
  li    $a1, 253
  bnez  $t5, .L7F049450
   addiu $a2, $s0, 0xc8
  addiu $t8, $s3, 8
  sw    $t8, 0x70($sp)
  jal   play_sfx_a1
   lw    $a0, %lo(ptr_sfx_buf)($a0)
  lw    $a0, 0xc8($s0)
  jal   sub_GAME_7F053A10
   lw    $a1, 0x70($sp)
.L7F049450:
  lui   $t0, %hi(global_timer) 
  lw    $t0, %lo(global_timer)($t0)
  addiu $t3, $t0, 2
  sw    $t3, 0xc0($s0)
  lw    $t7, 0x13c($sp)
.L7F049464:
  lw    $t1, 0x138($sp)
  li    $t9, 1
  bnezl $t7, .L7F049480
   sw    $t9, 0x11c($sp)
  beql  $t1, $zero, .L7F049ACC
   lw    $t8, 8($s4)
  sw    $t9, 0x11c($sp)
.L7F049480:
  sw    $zero, 0x10c($sp)
  lw    $t4, 0x14($s3)
  sw    $t4, 0x108($sp)
  lw    $t2, 0xac($s0)
  andi  $t6, $t2, 3
  sltiu $t5, $t6, 1
  jal   get_curplayer_positiondata
   sw    $t5, 0x104($sp)
  sw    $v0, 0x100($sp)
  lw    $t8, 8($s4)
  li    $a0, 5
  lw    $v1, 8($t8)
  lw    $t0, 0x1c($v1)
  beql  $t0, $zero, .L7F0494D4
   lbu   $t1, 1($s3)
  lw    $t3, 0xac($s0)
  andi  $t7, $t3, 7
  bnezl $t7, .L7F0494D4
   lbu   $t1, 1($s3)
  li    $a0, 7
  lbu   $t1, 1($s3)
.L7F0494D4:
  andi  $t9, $t1, 2
  beqz  $t9, .L7F049590
   sll   $s1, $a0, 2
  addu  $t4, $v1, $s1
  lw    $a1, ($t4)
  move  $a0, $s4
  beql  $a1, $zero, .L7F049594
   lwc1  $f4, 8($s3)
  jal   sub_GAME_7F06C660
   move  $a2, $zero
  lw    $t2, 8($s4)
  move  $s2, $v0
  lw    $t6, 8($t2)
  addu  $t5, $t6, $s1
  lw    $t8, ($t5)
  lw    $v1, 4($t8)
  lwc1  $f10, ($v1)
  swc1  $f10, 0x12c($sp)
  lwc1  $f6, 4($v1)
  swc1  $f6, 0x130($sp)
  lwc1  $f8, 8($v1)
  jal   sub_GAME_7F078444
   swc1  $f8, 0x134($sp)
  addiu $s1, $sp, 0xb8
  move  $a2, $s1
  move  $a0, $v0
  jal   sub_GAME_7F05818C
   move  $a1, $s2
  move  $a0, $s1
  jal   sub_GAME_7F058474
   addiu $a1, $sp, 0x12c
  lwc1  $f4, 0x134($sp)
  lw    $a1, 8($s3)
  lw    $a2, 0x10($s3)
  addiu $a0, $sp, 0x108
  lw    $a3, 0x12c($sp)
  jal   sub_GAME_7F0B0BE4
   swc1  $f4, 0x10($sp)
  bnez  $v0, .L7F0495A8
   nop   
  lwc1  $f10, 8($s3)
  swc1  $f10, 0x12c($sp)
  lwc1  $f6, 0xc($s3)
  swc1  $f6, 0x130($sp)
  lwc1  $f8, 0x10($s3)
  b     .L7F0495A8
   swc1  $f8, 0x134($sp)
.L7F049590:
  lwc1  $f4, 8($s3)
.L7F049594:
  swc1  $f4, 0x12c($sp)
  lwc1  $f10, 0xc($s3)
  swc1  $f10, 0x130($sp)
  lwc1  $f6, 0x10($s3)
  swc1  $f6, 0x134($sp)
.L7F0495A8:
  jal   cosf
   lwc1  $f12, 0x9c($s0)
  lwc1  $f12, 0x90($s0)
  jal   sinf
   swc1  $f0, 0x7c($sp)
  lwc1  $f2, 0x7c($sp)
  mul.s $f8, $f0, $f2
  swc1  $f8, 0x120($sp)
  jal   sinf
   lwc1  $f12, 0x9c($s0)
  swc1  $f0, 0x124($sp)
  jal   cosf
   lwc1  $f12, 0x9c($s0)
  lwc1  $f12, 0x90($s0)
  jal   cosf
   swc1  $f0, 0x7c($sp)
  lwc1  $f2, 0x7c($sp)
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f12
  mul.s $f14, $f0, $f2
  lwc1  $f4, 0x120($sp)
  lwc1  $f6, 0x12c($sp)
  mul.s $f10, $f4, $f12
  lwc1  $f4, 0x124($sp)
  swc1  $f14, 0x128($sp)
  add.s $f8, $f10, $f6
  mul.s $f10, $f4, $f12
  lwc1  $f6, 0x130($sp)
  mul.s $f4, $f14, $f12
  swc1  $f8, 0x110($sp)
  add.s $f8, $f10, $f6
  lwc1  $f10, 0x134($sp)
  add.s $f6, $f4, $f10
  swc1  $f8, 0x114($sp)
  jal   sub_GAME_7F0B1CC4
   swc1  $f6, 0x118($sp)
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f0
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  lwc1  $f8, 0x118($sp)
  li    $t0, 2
  sw    $t0, 0x14($sp)
  addiu $a0, $sp, 0x108
  lw    $a1, 0x12c($sp)
  lw    $a2, 0x134($sp)
  lw    $a3, 0x110($sp)
  swc1  $f22, 0x20($sp)
  swc1  $f0, 0x18($sp)
  swc1  $f0, 0x1c($sp)
  swc1  $f8, 0x10($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f4, 0x24($sp)
  bnez  $v0, .L7F0496DC
   addiu $a2, $sp, 0x110
  addiu $a0, $sp, 0x12c
  jal   sub_GAME_7F02624C
   addiu $a1, $sp, 0x120
  li    $at, 0x41D00000 # 26.000000
  mtc1  $at, $f16
  lwc1  $f6, 0x120($sp)
  lwc1  $f10, 0x110($sp)
  lwc1  $f14, 0x128($sp)
  mul.s $f8, $f16, $f6
  lwc1  $f6, 0x114($sp)
  lw    $t3, 0x108($sp)
  sw    $t3, 0x10c($sp)
  sub.s $f4, $f10, $f8
  lwc1  $f10, 0x124($sp)
  mul.s $f8, $f16, $f10
  swc1  $f4, 0x110($sp)
  lwc1  $f10, 0x118($sp)
  sub.s $f4, $f6, $f8
  mul.s $f6, $f16, $f14
  swc1  $f4, 0x114($sp)
  sub.s $f8, $f10, $f6
  swc1  $f8, 0x118($sp)
.L7F0496DC:
  lui   $t7, %hi(global_timer) 
  lw    $t7, %lo(global_timer)($t7)
  lw    $t1, 0xbc($s0)
  addiu $s1, $sp, 0x110
  lw    $a1, 0x100($sp)
  bne   $t7, $t1, .L7F04983C
   lwc1  $f10, 0x12c($sp)
  lwc1  $f4, 8($a1)
  lwc1  $f6, 0xc($a1)
  lwc1  $f8, 0x130($sp)
  sub.s $f0, $f4, $f10
  lwc1  $f4, 0x10($a1)
  swc1  $f10, 0x58($sp)
  sub.s $f2, $f6, $f8
  lwc1  $f6, 0x134($sp)
  sub.s $f12, $f4, $f6
  mul.s $f4, $f0, $f0
  nop   
  mul.s $f10, $f2, $f2
  add.s $f4, $f4, $f10
  mul.s $f10, $f12, $f12
  add.s $f20, $f4, $f10
  lwc1  $f10, 0x58($sp)
  lwc1  $f4, 0x110($sp)
  sub.s $f0, $f4, $f10
  lwc1  $f4, 0x114($sp)
  lwc1  $f10, 0x118($sp)
  sub.s $f2, $f4, $f8
  mul.s $f4, $f0, $f0
  sub.s $f12, $f10, $f6
  mul.s $f8, $f2, $f2
  add.s $f10, $f4, $f8
  mul.s $f6, $f12, $f12
  add.s $f4, $f10, $f6
  c.le.s $f20, $f4
  nop   
  bc1f  .L7F04983C
   nop   
  jal   check_if_bond_is_invincible
   nop   
  bnezl $v0, .L7F049840
   lw    $t9, 0x11c($sp)
  jal   sqrtf
   mov.s $f12, $f20
  li    $at, 0x43480000 # 200.000000
  mtc1  $at, $f12
  lui   $at, %hi(D_80052B74)
  lwc1  $f8, %lo(D_80052B74)($at)
  lui   $at, %hi(global_timer_delta)
  lwc1  $f10, %lo(global_timer_delta)($at)
  lui   $at, %hi(D_80030B1C)
  c.lt.s $f12, $f0
  mul.s $f6, $f8, $f10
  lwc1  $f4, %lo(D_80030B1C)($at)
  mul.s $f2, $f6, $f4
  bc1fl .L7F0497D0
   lwc1  $f10, 0xd4($s0)
  div.s $f8, $f12, $f0
  mul.s $f2, $f2, $f8
  nop   
  lwc1  $f10, 0xd4($s0)
.L7F0497D0:
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  add.s $f6, $f10, $f2
  swc1  $f6, 0xd4($s0)
  lwc1  $f4, 0xd4($s0)
  c.le.s $f8, $f4
  nop   
  bc1fl .L7F049840
   lw    $t9, 0x11c($sp)
  jal   sub_GAME_7F05DF84
   li    $a0, 14
  li    $at, 0x3E000000 # 0.125000
  mtc1  $at, $f10
  lui   $at, %hi(D_80030B20)
  lwc1  $f4, %lo(D_80030B20)($at)
  mul.s $f6, $f0, $f10
  lwc1  $f14, 0x90($s0)
  li    $a2, -1
  li    $a3, 1
  mul.s $f12, $f6, $f4
  jal   sub_GAME_7F089E4C
   nop   
  jal   check_if_bond_is_invincible
   swc1  $f22, 0xd4($s0)
  beql  $v0, $zero, .L7F049840
   lw    $t9, 0x11c($sp)
  sw    $zero, 0x11c($sp)
.L7F04983C:
  lw    $t9, 0x11c($sp)
.L7F049840:
  li    $at, 0x41D00000 # 26.000000
  mtc1  $at, $f16
  beqz  $t9, .L7F049888
   lw    $a1, 0x100($sp)
  lw    $t4, 0x10c($sp)
  move  $a0, $s1
  li    $a1, 1
  beql  $t4, $zero, .L7F049874
   li    $a0, 14
  mfc1  $a2, $f16
  jal   sub_GAME_7F0A3E1C
   lbu   $a3, 3($t4)
  li    $a0, 14
.L7F049874:
  move  $a1, $s1
  jal   recall_joy2_hits_edit_flag
   li    $a2, -1
  b     .L7F0498B0
   lw    $t2, 0x104($sp)
.L7F049888:
  lwc1  $f8, 8($a1)
  li    $a0, 14
  li    $a2, -1
  swc1  $f8, 0x110($sp)
  lwc1  $f10, 0xc($a1)
  swc1  $f10, 0x114($sp)
  lwc1  $f6, 0x10($a1)
  jal   recall_joy2_hits_edit_detail_edit_flag
   swc1  $f6, 0x118($sp)
  lw    $t2, 0x104($sp)
.L7F0498B0:
  lwc1  $f4, 0x12c($sp)
  beql  $t2, $zero, .L7F049ACC
   lw    $t8, 8($s4)
  lw    $v1, 0xcc($s0)
  swc1  $f4, 4($v1)
  lwc1  $f8, 0x130($sp)
  lwc1  $f4, 4($v1)
  swc1  $f8, 8($v1)
  lwc1  $f10, 0x134($sp)
  swc1  $f10, 0xc($v1)
  lwc1  $f6, 0x110($sp)
  sub.s $f8, $f6, $f4
  lwc1  $f6, 8($v1)
  swc1  $f8, 0x10($v1)
  lwc1  $f10, 0x114($sp)
  lwc1  $f2, 0x10($v1)
  sub.s $f4, $f10, $f6
  lwc1  $f10, 0xc($v1)
  swc1  $f4, 0x14($v1)
  lwc1  $f8, 0x118($sp)
  mul.s $f4, $f2, $f2
  lwc1  $f14, 0x14($v1)
  sub.s $f6, $f8, $f10
  mul.s $f8, $f14, $f14
  swc1  $f6, 0x18($v1)
  lwc1  $f0, 0x18($v1)
  sw    $v1, 0x90($sp)
  mul.s $f6, $f0, $f0
  add.s $f10, $f4, $f8
  jal   sqrtf
   add.s $f12, $f6, $f10
  lui   $at, %hi(D_80052B78)
  lwc1  $f14, %lo(D_80052B78)($at)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  lw    $v1, 0x90($sp)
  c.lt.s $f14, $f0
  mov.s $f12, $f0
  div.s $f2, $f4, $f0
  lwc1  $f8, 0x10($v1)
  lwc1  $f10, 0x14($v1)
  li    $at, 0x43FA0000 # 500.000000
  mtc1  $at, $f0
  mul.s $f6, $f8, $f2
  lwc1  $f8, 0x18($v1)
  mul.s $f4, $f10, $f2
  swc1  $f6, 0x10($v1)
  mul.s $f6, $f8, $f2
  swc1  $f4, 0x14($v1)
  bc1f  .L7F049980
   swc1  $f6, 0x18($v1)
  mov.s $f12, $f14
.L7F049980:
  c.lt.s $f12, $f0
  li    $t6, 14
  sb    $zero, ($v1)
  sb    $t6, 1($v1)
  bc1f  .L7F04999C
   swc1  $f12, 0x1c($v1)
  mov.s $f12, $f0
.L7F04999C:
  lb    $t5, 1($v1)
  li    $at, 22
  bne   $t5, $at, .L7F049A40
   lui   $at, %hi(D_80052B7C)
  lwc1  $f2, %lo(D_80052B7C)($at)
  li    $at, 0x3E800000 # 0.250000
  mtc1  $at, $f10
  lui   $at, %hi(D_80052B80)
  mul.s $f4, $f10, $f12
  swc1  $f4, 0x20($v1)
  lwc1  $f8, %lo(D_80052B80)($at)
  mul.s $f0, $f8, $f12
  c.lt.s $f2, $f0
  swc1  $f0, 0x24($v1)
  bc1fl .L7F0499E4
   sw    $v1, 0x90($sp)
  swc1  $f2, 0x24($v1)
  sw    $v1, 0x90($sp)
.L7F0499E4:
  jal   get_random_value
   swc1  $f12, 0x94($sp)
  mtc1  $v0, $f6
  lw    $v1, 0x90($sp)
  lwc1  $f12, 0x94($sp)
  bgez  $v0, .L7F049A10
   cvt.s.w $f10, $f6
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f4
  nop   
  add.s $f10, $f10, $f4
.L7F049A10:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f8
  lui   $at, %hi(D_80052B84)
  lwc1  $f4, %lo(D_80052B84)($at)
  mul.s $f6, $f10, $f8
  lui   $at, %hi(D_80052B88)
  lwc1  $f8, %lo(D_80052B88)($at)
  mul.s $f10, $f6, $f4
  sub.s $f6, $f8, $f10
  mul.s $f4, $f6, $f12
  b     .L7F049AC8
   swc1  $f4, 0x28($v1)
.L7F049A40:
  lui   $at, %hi(D_80052B8C)
  lwc1  $f8, %lo(D_80052B8C)($at)
  lui   $at, %hi(D_80052B90)
  mul.s $f0, $f8, $f12
  swc1  $f0, 0x20($v1)
  swc1  $f0, 0x24($v1)
  lwc1  $f10, %lo(D_80052B90)($at)
  lui   $at, %hi(D_80052B94)
  c.lt.s $f10, $f0
  nop   
  bc1f  .L7F049A78
   nop   
  lwc1  $f6, %lo(D_80052B94)($at)
  swc1  $f6, 0x24($v1)
.L7F049A78:
  jal   get_random_value
   sw    $v1, 0x90($sp)
  mtc1  $v0, $f4
  lw    $v1, 0x90($sp)
  bgez  $v0, .L7F049AA0
   cvt.s.w $f8, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f10
  nop   
  add.s $f8, $f8, $f10
.L7F049AA0:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f6
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  mul.s $f0, $f8, $f6
  lwc1  $f6, 0x20($v1)
  add.s $f4, $f0, $f0
  sub.s $f8, $f4, $f10
  mul.s $f4, $f8, $f6
  swc1  $f4, 0x28($v1)
.L7F049AC8:
  lw    $t8, 8($s4)
.L7F049ACC:
  lw    $v1, 8($t8)
  lw    $a1, 0x14($v1)
  beql  $a1, $zero, .L7F049AF8
   lw    $a1, 0x1c($v1)
  jal   extract_id_from_object_structure_microcode
   move  $a0, $s4
  lw    $t0, 0x13c($sp)
  sh    $t0, ($v0)
  lw    $t3, 8($s4)
  lw    $v1, 8($t3)
  lw    $a1, 0x1c($v1)
.L7F049AF8:
  beqz  $a1, .L7F049B10
   nop   
  jal   extract_id_from_object_structure_microcode
   move  $a0, $s4
  lw    $t7, 0x138($sp)
  sh    $t7, ($v0)
.L7F049B10:
  jal   sub_GAME_7F044200
   move  $a0, $s3
  lw    $t1, 0x680($sp)
.L7F049B1C:
  li    $at, 5
  bnel  $t1, $at, .L7F049B30
   lw    $v0, 0x680($sp)
  sw    $zero, 0x14($s3)
  lw    $v0, 0x680($sp)
.L7F049B30:
  lw    $ra, 0x54($sp)
  ldc1  $f20, 0x30($sp)
  ldc1  $f22, 0x38($sp)
  lw    $s0, 0x40($sp)
  lw    $s1, 0x44($sp)
  lw    $s2, 0x48($sp)
  lw    $s3, 0x4c($sp)
  lw    $s4, 0x50($sp)
  jr    $ra
   addiu $sp, $sp, 0x6a8
");

#ifdef VERSION_JP
asm(R"
.late_rodata
glabel rocket_initial_gravity_modifier
.word 0x3e8e38e4 /*0.27777779*/
glabel D_80052A9C
.word 0x3c360b61 /*0.011111111*/
glabel D_80052AA0
.word 0x3d8f5c29 /*0.07*/
glabel prop_projectile_gravity_modifier
.word 0x3e8e38e4 /*0.27777779*/
glabel D_80052AA8
.word 0x400e38e4 /*2.2222223*/
glabel D_80052AAC
.word 0x46d9038c /*27777.773*/
glabel D_80052AB0
.word 0x3f8ccccd /*1.1*/
glabel D_80052AB4
.word 0x3f666666 /*0.89999998*/
glabel D_80052AB8
.word 0x3f666666 /*0.89999998*/
glabel D_80052ABC
.word 0x3dcccccd /*0.1*/
glabel D_80052AC0
.word 0xbdcccccd /*-0.1*/
glabel D_80052AC4
.word 0xbdcccccd /*-0.1*/
glabel D_80052AC8
.word 0x40c90fdb /*6.2831855*/
glabel D_80052ACC
.word 0x40c90fdb /*6.2831855*/
glabel D_80052AD0
.word 0x40490fdb /*3.1415927*/
glabel D_80052AD4
.word 0x3f490fdb /*0.78539819*/
glabel D_80052AD8
.word 0xbf490fdb /*-0.78539819*/
glabel D_80052ADC
.word 0x40c90fdb /*6.2831855*/
glabel D_80052AE0
.word 0x3a2b92a6 /*0.00065449846*/
glabel D_80052AE4
.word 0x3a2b92a6 /*0.00065449846*/
glabel D_80052AE8
.word 0x40c90fdb /*6.2831855*/
glabel D_80052AEC
.word 0x37433637 /*0.000011635529*/
glabel D_80052AF0
.word 0x40c90fdb /*6.2831855*/
glabel D_80052AF4
.word 0x3a3702d4 /*0.00069813174*/
glabel D_80052AF8
.word 0x36c33637 /*0.0000058177643*/
glabel D_80052AFC
.word 0x39b702d4 /*0.00034906587*/
glabel D_80052B00
.word 0x40c90fdb /*6.2831855*/
glabel D_80052B04
.word 0x40c90fdb /*6.2831855*/
glabel D_80052B08
.word 0x40c90fdb /*6.2831855*/
glabel D_80052B0C
.word 0x40490fdb /*3.1415927*/
glabel D_80052B10
.word 0x3f9c61ab /*1.2217306*/
glabel D_80052B14
.word 0xbf9c61ab /*-1.2217306*/
glabel D_80052B18
.word 0xc0490fdb /*-3.1415927*/
glabel D_80052B1C
.word 0x40490fdb /*3.1415927*/
glabel D_80052B20
.word 0x40c90fdb /*6.2831855*/
glabel D_80052B24
.word 0x3f4ccccd /*0.80000001*/
glabel D_80052B28
.word 0xc0490fdb /*-3.1415927*/
glabel D_80052B2C
.word 0x40490fdb /*3.1415927*/
glabel D_80052B30
.word 0x3a64c389 /*0.00087266468*/
glabel D_80052B34
.word 0x3a64c389 /*0.00087266468*/
glabel D_80052B38
.word 0x40490fdb /*3.1415927*/
glabel D_80052B3C
.word 0x3f1930a7 /*0.59839863*/
glabel D_80052B40
.word 0x3c236719 /*0.0099733109*/
glabel D_80052B44
.word 0x3f7d70a4 /*0.99000001*/
glabel D_80052B48
.word 0x38d1b717 /*0.000099999997*/
glabel D_80052B4C
.word 0x3964c389 /*0.00021816617*/
glabel D_80052B50
.word 0x3bd67750 /*0.0065449849*/
glabel D_80052B54
.word 0x40c90fdb /*6.2831855*/
glabel D_80052B58
.word 0x3964c389 /*0.00021816617*/
glabel D_80052B5C
.word 0xb964c389 /*-0.00021816617*/
glabel D_80052B60
.word 0x40c90fdb /*6.2831855*/
glabel D_80052B64
.word 0x40c90fdb /*6.2831855*/
glabel D_80052B68
.word 0x3e99999a /*0.30000001*/
glabel D_80052B6C
.word 0x3fc90fdb /*1.5707964*/
glabel D_80052B70
.word 0x3fc90fdb /*1.5707964*/
glabel D_80052B74
.word 0x3e23d70a /*0.16*/
glabel D_80052B78
.word 0x461c4000 /*10000.0*/
glabel D_80052B7C
.word 0x453b8000 /*3000.0*/
glabel D_80052B80
.word 0x3f19999a /*0.60000002*/
glabel D_80052B84
.word 0x3e99999a /*0.30000001*/
glabel D_80052B88
.word 0xbdcccccd /*-0.1*/
glabel D_80052B8C
.word 0x3e4ccccd /*0.2*/
glabel D_80052B90
.word 0x453b8000 /*3000.0*/
glabel D_80052B94
.word 0x453b8000 /*3000.0*/

.text
glabel object_interaction
  addiu $sp, $sp, -0x6b0
  sw    $ra, 0x54($sp)
  sw    $s4, 0x50($sp)
  sw    $s3, 0x4c($sp)
  sw    $s2, 0x48($sp)
  sw    $s1, 0x44($sp)
  sw    $s0, 0x40($sp)
  sdc1  $f22, 0x38($sp)
  sdc1  $f20, 0x30($sp)
  lw    $s1, 4($a0)
  mtc1  $zero, $f22
  move  $s3, $a0
  lw    $s4, 0x14($s1)
  sw    $zero, 0x698($sp)
  sw    $zero, 0x688($sp)
  jal   getPlayerCount
   swc1  $f22, 0x684($sp)
  li    $t7, 1
  sw    $v0, 0x67c($sp)
  sw    $t7, 0x678($sp)
  lw    $v1, 0x64($s1)
  andi  $t9, $v1, 4
  beqz  $t9, .Ljp7F045728
   andi  $t0, $v1, 8
  lbu   $a2, 2($s1)
  move  $a0, $s1
  move  $a1, $zero
  andi  $t8, $a2, 4
  jal   sub_GAME_7F040D98
   move  $a2, $t8
  b     .Ljp7F049F34
   li    $v0, 1
.Ljp7F045728:
  beqz  $t0, .Ljp7F045740
   andi  $t3, $v1, 0x80
  li    $at, -9
  and   $t1, $v1, $at
  b     .Ljp7F045768
   sw    $t1, 0x64($s1)
.Ljp7F045740:
  beql  $t3, $zero, .Ljp7F04576C
   li    $at, 1
  lbu   $t4, 1($s3)
  li    $v0, 3
  andi  $t6, $t4, 0xfffd
  sb    $t6, 1($s3)
  lw    $t2, 0x64($s1)
  ori   $t5, $t2, 8
  b     .Ljp7F049F34
   sw    $t5, 0x64($s1)
.Ljp7F045768:
  li    $at, 1
.Ljp7F04576C:
  bne   $v0, $at, .Ljp7F04577C
   li    $t7, 1
  b     .Ljp7F0457DC
   sw    $t7, 0x680($sp)
.Ljp7F04577C:
  jal   get_cur_playernum
   nop   
  jal   sub_GAME_7F09B4D8
   move  $a0, $v0
  sltiu $t9, $v0, 1
  sw    $t9, 0x680($sp)
  lw    $t8, 0x64($s1)
  andi  $t0, $t8, 0x80
  beql  $t0, $zero, .Ljp7F0457E0
   lw    $t2, 0x680($sp)
  lw    $s0, 0x6c($s1)
  lw    $a0, 0x88($s0)
  beql  $a0, $zero, .Ljp7F0457E0
   lw    $t2, 0x680($sp)
  jal   sub_GAME_7F09B15C
   nop   
  bltz  $v0, .Ljp7F0457DC
   lui   $t1, %hi(pPlayer) # $t1, 0x8008
  lw    $t1, %lo(pPlayer)($t1)
  lw    $t4, 0x88($s0)
  lw    $t3, 0xa8($t1)
  xor   $t6, $t3, $t4
  sltiu $t6, $t6, 1
  sw    $t6, 0x680($sp)
.Ljp7F0457DC:
  lw    $t2, 0x680($sp)
.Ljp7F0457E0:
  beql  $t2, $zero, .Ljp7F048634
   lbu   $v0, 3($s1)
  lw    $t5, 0x64($s1)
  andi  $t7, $t5, 0x80
  beql  $t7, $zero, .Ljp7F046A20
   lw    $t3, 0x698($sp)
  lw    $s0, 0x6c($s1)
  lui   $t8, %hi(clock_timer) # $t8, 0x8005
  lw    $t8, %lo(clock_timer)($t8)
  lw    $t9, 0xe0($s0)
  addu  $t0, $t9, $t8
  slti  $at, $t0, 0x961
  bnez  $at, .Ljp7F045824
   sw    $t0, 0xe0($s0)
  lw    $t3, 0x64($s1)
  ori   $t4, $t3, 4
  sw    $t4, 0x64($s1)
.Ljp7F045824:
  lw    $t6, ($s0)
  andi  $t2, $t6, 0x100
  beql  $t2, $zero, .Ljp7F0458EC
   lwc1  $f6, 0x58($s1)
  lbu   $t5, 3($s1)
  li    $at, 8
  li    $s2, 1
  bnel  $t5, $at, .Ljp7F045864
   lw    $a0, 0x88($s0)
  sw    $s1, 0x650($sp)
  lb    $t7, 0x80($s1)
  li    $at, 86
  bnel  $t7, $at, .Ljp7F045864
   lw    $a0, 0x88($s0)
  move  $s2, $zero
  lw    $a0, 0x88($s0)
.Ljp7F045864:
  beql  $a0, $zero, .Ljp7F045878
   move  $a0, $s1
  jal   sub_GAME_7F03D058
   move  $a1, $zero
  move  $a0, $s1
.Ljp7F045878:
  addiu $a1, $s0, 0xd4
  addiu $a2, $sp, 0x654
  addiu $a3, $sp, 0x660
  sw    $zero, 0x10($sp)
  jal   sub_GAME_7F042EB4
   sw    $s2, 0x14($sp)
  sw    $v0, 0x66c($sp)
  lw    $a0, 0x88($s0)
  beql  $a0, $zero, .Ljp7F0458AC
   lw    $t9, 0x66c($sp)
  jal   sub_GAME_7F03D058
   li    $a1, 1
  lw    $t9, 0x66c($sp)
.Ljp7F0458AC:
  li    $at, 1
  lw    $v0, 0x650($sp)
  beql  $t9, $at, .Ljp7F0458DC
   lw    $t0, ($s0)
  beql  $v0, $zero, .Ljp7F0458DC
   lw    $t0, ($s0)
  lb    $t8, 0x80($v0)
  li    $at, 86
  bnel  $t8, $at, .Ljp7F0458DC
   lw    $t0, ($s0)
  sh    $zero, 0x82($v0)
  lw    $t0, ($s0)
.Ljp7F0458DC:
  li    $at, -257
  and   $t1, $t0, $at
  sw    $t1, ($s0)
  lwc1  $f6, 0x58($s1)
.Ljp7F0458EC:
  lui   $t3, %hi(clock_timer) # $t3, 0x8005
  lui   $at, 0x3f80
  swc1  $f6, 0x69c($sp)
  lwc1  $f10, 0x5c($s1)
  swc1  $f10, 0x6a0($sp)
  lwc1  $f4, 0x60($s1)
  swc1  $f4, 0x6a4($sp)
  lw    $v0, 0xbc($s0)
  blezl $v0, .Ljp7F045924
   lw    $t6, 0x6c($s1)
  lw    $t3, %lo(clock_timer)($t3)
  subu  $t4, $v0, $t3
  sw    $t4, 0xbc($s0)
  lw    $t6, 0x6c($s1)
.Ljp7F045924:
  lw    $t2, ($t6)
  andi  $t5, $t2, 1
  beql  $t5, $zero, .Ljp7F046674
   lwc1  $f0, 0x60($s0)
  jal   sub_GAME_7F040078
   move  $a0, $s1
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  lui   $a3, %hi(clock_timer) # $a3, 0x8005
  addiu $a3, %lo(clock_timer) # addiu $a3, $a3, -0x7c5c
  sw    $v0, 0x648($sp)
  sw    $zero, 0x618($sp)
  sw    $zero, 0x614($sp)
  sw    $zero, 0x60c($sp)
  swc1  $f8, 0x640($sp)
  lw    $t7, 0xa8($s0)
  lw    $t9, ($a3)
  lwc1  $f20, 0x5c($s1)
  move  $s2, $zero
  addu  $t8, $t7, $t9
  sw    $t8, 0xa8($s0)
  lwc1  $f6, 0x18($s1)
  lui   $at, %hi(rocket_initial_gravity_modifier) # $at, 0x8005
  swc1  $f6, 0x634($sp)
  lwc1  $f10, 0x1c($s1)
  swc1  $f10, 0x638($sp)
  lwc1  $f4, 0x20($s1)
  swc1  $f4, 0x63c($sp)
  lw    $v1, ($s0)
  andi  $t0, $v1, 0x20
  beqz  $t0, .Ljp7F045ACC
   nop   
  lwc1  $f18, %lo(rocket_initial_gravity_modifier)($at)
  lwc1  $f0, 0x1c($s0)
  lui   $v0, %hi(global_timer_delta) # $v0, 0x8005
  addiu $v0, %lo(global_timer_delta) # addiu $v0, $v0, -0x7c4c
  c.lt.s $f0, $f18
  nop   
  bc1fl .Ljp7F045A30
   lwc1  $f0, 0xb0($s0)
  lwc1  $f8, 0x14($s0)
  lwc1  $f6, ($v0)
  lwc1  $f4, 0xb4($s0)
  lui   $at, %hi(D_80052A9C) # $at, 0x8005
  mul.s $f10, $f8, $f6
  add.s $f8, $f4, $f10
  swc1  $f8, 0xb4($s0)
  lwc1  $f4, ($v0)
  lwc1  $f6, 0xb4($s0)
  lwc1  $f8, 0xb0($s0)
  mul.s $f10, $f6, $f4
  add.s $f6, $f8, $f10
  swc1  $f6, 0xb0($s0)
  lwc1  $f8, ($v0)
  lwc1  $f4, %lo(D_80052A9C)($at)
  mul.s $f10, $f4, $f8
  add.s $f6, $f0, $f10
  swc1  $f6, 0x1c($s0)
  lwc1  $f4, 0x1c($s0)
  c.lt.s $f18, $f4
  nop   
  bc1f  .Ljp7F045A24
   nop   
  swc1  $f18, 0x1c($s0)
.Ljp7F045A24:
  b     .Ljp7F045ACC
   lw    $v1, ($s0)
  lwc1  $f0, 0xb0($s0)
.Ljp7F045A30:
  lwc1  $f8, 0x6a0($sp)
  c.lt.s $f8, $f0
  nop   
  bc1f  .Ljp7F045AA4
   lui   $at, %hi(global_timer_delta) # $at, 0x8005
  lwc1  $f6, %lo(global_timer_delta)($at)
  lwc1  $f10, 0x14($s0)
  lwc1  $f8, 0xb4($s0)
  mul.s $f4, $f10, $f6
  add.s $f10, $f8, $f4
  swc1  $f10, 0xb4($s0)
  lwc1  $f8, %lo(global_timer_delta)($at)
  lwc1  $f6, 0xb4($s0)
  lui   $at, %hi(D_80052AA0) # $at, 0x8005
  mul.s $f4, $f6, $f8
  add.s $f10, $f0, $f4
  swc1  $f10, 0xb0($s0)
  lwc1  $f8, 0x6a0($sp)
  lwc1  $f6, 0xb0($s0)
  lwc1  $f10, %lo(D_80052AA0)($at)
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  sub.s $f4, $f6, $f8
  mul.s $f6, $f10, $f4
  lwc1  $f10, %lo(global_timer_delta)($at)
  mul.s $f4, $f6, $f10
  add.s $f6, $f8, $f4
  swc1  $f6, 0x6a0($sp)
  b     .Ljp7F045ACC
   lw    $v1, ($s0)
.Ljp7F045AA4:
  swc1  $f0, 0x6a0($sp)
  lw    $t1, ($s0)
  li    $at, -33
  lwc1  $f10, 0xb4($s0)
  and   $t3, $t1, $at
  sw    $t3, ($s0)
  ori   $v1, $t3, 0x10
  swc1  $f22, 0x1c($s0)
  sw    $v1, ($s0)
  swc1  $f10, 8($s0)
.Ljp7F045ACC:
  lui   $v0, %hi(global_timer_delta) # $v0, 0x8005
  addiu $v0, %lo(global_timer_delta) # addiu $v0, $v0, -0x7c4c
  lui   $at, %hi(prop_projectile_gravity_modifier) # $at, 0x8005
  andi  $t2, $v1, 0x10
  lwc1  $f18, %lo(prop_projectile_gravity_modifier)($at)
  lwc1  $f2, ($v0)
  lwc1  $f0, 0x1c($s0)
  bnez  $t2, .Ljp7F045B40
   lwc1  $f16, 0x14($s0)
  add.s $f4, $f16, $f0
  lwc1  $f8, 8($s0)
  li    $at, 0x3F000000 # 0.500000
  mul.s $f6, $f4, $f2
  add.s $f10, $f8, $f6
  swc1  $f10, 8($s0)
  lwc1  $f2, ($v0)
  lwc1  $f12, 8($s0)
  mtc1  $at, $f10
  mul.s $f4, $f18, $f2
  sub.s $f14, $f12, $f4
  add.s $f8, $f12, $f14
  mul.s $f6, $f2, $f8
  lwc1  $f8, 0x6a0($sp)
  mul.s $f4, $f6, $f10
  add.s $f6, $f8, $f4
  swc1  $f6, 0x6a0($sp)
  swc1  $f14, 8($s0)
  b     .Ljp7F045B6C
   lwc1  $f2, ($v0)
.Ljp7F045B40:
  add.s $f8, $f16, $f0
  lwc1  $f10, 8($s0)
  mul.s $f4, $f8, $f2
  add.s $f6, $f10, $f4
  swc1  $f6, 8($s0)
  lwc1  $f10, 8($s0)
  lwc1  $f2, ($v0)
  lwc1  $f8, 0x6a0($sp)
  mul.s $f4, $f10, $f2
  add.s $f6, $f8, $f4
  swc1  $f6, 0x6a0($sp)
.Ljp7F045B6C:
  lwc1  $f8, 0x10($s0)
  lwc1  $f10, 4($s0)
  addiu $a0, $s1, 0x18
  mul.s $f4, $f8, $f2
  lwc1  $f8, 0x18($s0)
  addiu $a1, $s0, 0x20
  add.s $f6, $f10, $f4
  swc1  $f6, 4($s0)
  lwc1  $f10, ($v0)
  lwc1  $f6, 0xc($s0)
  mul.s $f4, $f8, $f10
  add.s $f8, $f6, $f4
  lwc1  $f6, 4($s0)
  swc1  $f8, 0xc($s0)
  lwc1  $f2, ($v0)
  lwc1  $f10, 0x69c($sp)
  lw    $a2, ($a3)
  mul.s $f4, $f6, $f2
  lwc1  $f6, 0x6a4($sp)
  add.s $f8, $f10, $f4
  swc1  $f8, 0x69c($sp)
  lwc1  $f10, 0xc($s0)
  sw    $a1, 0x70($sp)
  sw    $a0, 0x74($sp)
  mul.s $f4, $f10, $f2
  add.s $f8, $f6, $f4
  jal   sub_GAME_7F057DF8
   swc1  $f8, 0x6a4($sp)
  lbu   $t5, 3($s1)
  li    $at, 8
  bnel  $t5, $at, .Ljp7F045C34
   lw    $a0, 0x88($s0)
  lb    $v0, 0x80($s1)
  li    $at, 29
  beq   $v0, $at, .Ljp7F045C2C
   li    $at, 27
  beq   $v0, $at, .Ljp7F045C2C
   li    $at, 28
  beq   $v0, $at, .Ljp7F045C2C
   li    $at, 33
  beq   $v0, $at, .Ljp7F045C2C
   li    $at, 47
  beq   $v0, $at, .Ljp7F045C2C
   li    $at, 48
  beq   $v0, $at, .Ljp7F045C2C
   li    $at, 34
  bnel  $v0, $at, .Ljp7F045C34
   lw    $a0, 0x88($s0)
.Ljp7F045C2C:
  li    $s2, 1
  lw    $a0, 0x88($s0)
.Ljp7F045C34:
  beql  $a0, $zero, .Ljp7F045C48
   move  $a0, $s1
  jal   sub_GAME_7F03D058
   move  $a1, $zero
  move  $a0, $s1
.Ljp7F045C48:
  addiu $a1, $sp, 0x69c
  addiu $a2, $sp, 0x61c
  addiu $a3, $sp, 0x628
  sw    $s2, 0x10($sp)
  jal   sub_GAME_7F042EB4
   sw    $zero, 0x14($sp)
  sw    $v0, 0x66c($sp)
  lw    $a0, 0x88($s0)
  beql  $a0, $zero, .Ljp7F045C7C
   lw    $t9, 0x66c($sp)
  jal   sub_GAME_7F03D058
   li    $a1, 1
  lw    $t9, 0x66c($sp)
.Ljp7F045C7C:
  li    $t7, 1
  li    $at, 2
  bne   $t9, $at, .Ljp7F045D90
   sw    $t7, 0x698($sp)
  lui   $v1, %hi(D_80030B0C) # $v1, 0x8003
  lw    $v1, %lo(D_80030B0C)($v1)
  beqz  $v1, .Ljp7F045CB4
   nop   
  lbu   $v0, ($v1)
  li    $at, 3
  beq   $v0, $at, .Ljp7F045D90
   li    $at, 6
  beql  $v0, $at, .Ljp7F045D94
   lw    $t9, 0x60c($sp)
.Ljp7F045CB4:
  beqz  $v1, .Ljp7F045CD4
   move  $a0, $zero
  lw    $v0, 4($v1)
  lw    $t8, 0x64($v0)
  andi  $t0, $t8, 0x80
  beqz  $t0, .Ljp7F045CD4
   nop   
  li    $a0, 1
.Ljp7F045CD4:
  bnezl $a0, .Ljp7F045D94
   lw    $t9, 0x60c($sp)
  jal   sub_GAME_7F03FB70
   move  $a0, $s0
  lw    $t1, 0x64($s1)
  li    $at, -129
  sw    $zero, 0x6c($s1)
  and   $t3, $t1, $at
  sw    $t3, 0x64($s1)
  lbu   $v0, 1($s3)
  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  li    $a1, 241
  andi  $t4, $v0, 8
  beqz  $t4, .Ljp7F045D18
   move  $a2, $zero
  ori   $t6, $v0, 0x10
  sb    $t6, 1($s3)
.Ljp7F045D18:
  jal   play_sfx_a1
   lw    $a0, %lo(ptr_sfx_buf)($a0)
  move  $a0, $v0
  jal   sub_GAME_7F053A10
   addiu $a1, $s3, 8
  lw    $t2, 0x14($s3)
  lb    $a0, 0x80($s1)
  jal   sub_GAME_7F0577E8
   lbu   $a1, 3($t2)
  move  $a0, $s1
  addiu $a1, $sp, 0x61c
  lw    $a2, 0x14($s3)
  jal   sub_GAME_7F0439B8
   addiu $a3, $sp, 0x628
  lui   $a1, %hi(D_80030B0C) # $a1, 0x8003
  lw    $a1, %lo(D_80030B0C)($a1)
  move  $a0, $s3
  lui   $a2, %hi(objinst) # $a2, 0x8007
  beqz  $a1, .Ljp7F045D90
   lui   $a3, %hi(dword_CODE_bss_80075B74) # $a3, 0x8007
  lw    $s2, 0x14($s3)
  lw    $a2, %lo(objinst)($a2)
  jal   sub_GAME_7F043A6C
   lw    $a3, %lo(dword_CODE_bss_80075B74)($a3)
  beqz  $v0, .Ljp7F045D90
   li    $t5, 5
  sw    $s2, 0x14($s3)
  li    $t7, 1
  sw    $t5, 0x688($sp)
  sw    $t7, 0x60c($sp)
.Ljp7F045D90:
  lw    $t9, 0x60c($sp)
.Ljp7F045D94:
  bnez  $t9, .Ljp7F046148
   lui   $s2, %hi(D_80030B0C) # $s2, 0x8003
  lw    $s2, %lo(D_80030B0C)($s2)
  beql  $s2, $zero, .Ljp7F04614C
   lw    $t9, 0x60c($sp)
  lbu   $t8, 3($s1)
  li    $at, 8
  bnel  $t8, $at, .Ljp7F04614C
   lw    $t9, 0x60c($sp)
  lb    $v0, 0x80($s1)
  li    $at, 3
  bnel  $v0, $at, .Ljp7F0460D0
   li    $at, 86
  lbu   $v0, ($s2)
  li    $at, 3
  beq   $v0, $at, .Ljp7F045E08
   li    $at, 6
  bnel  $v0, $at, .Ljp7F04614C
   lw    $t9, 0x60c($sp)
  lw    $t0, 4($s2)
  beql  $t0, $zero, .Ljp7F04614C
   lw    $t9, 0x60c($sp)
  jal   sub_GAME_7F09B15C
   move  $a0, $s2
  jal   get_cur_playernum
   move  $s2, $v0
  beq   $v0, $s2, .Ljp7F046148
   lui   $s2, %hi(D_80030B0C) # $s2, 0x8003
  lw    $s2, %lo(D_80030B0C)($s2)
.Ljp7F045E08:
  lw    $v0, 0x6c($s1)
  lw    $a0, 4($s2)
  lw    $t1, ($v0)
  andi  $t3, $t1, 1
  beql  $t3, $zero, .Ljp7F04614C
   lw    $t9, 0x60c($sp)
  lw    $t4, 0x90($v0)
  bgtzl $t4, .Ljp7F04614C
   lw    $t9, 0x60c($sp)
  lw    $t6, 0x64($s1)
  lui   $a2, %hi(flt_CODE_bss_80075B78) # $a2, 0x8007
  addiu $a2, %lo(flt_CODE_bss_80075B78) # addiu $a2, $a2, 0x5bb8
  andi  $t2, $t6, 0x20
  beqz  $t2, .Ljp7F046148
   lui   $a1, %hi(bodypartshot) # $a1, 0x8003
  lb    $a3, 0x80($s1)
  li    $t5, 1
  sw    $t5, 0x10($sp)
  jal   handles_shot_actors
   lw    $a1, %lo(bodypartshot)($a1)
  beqz  $v0, .Ljp7F046148
   li    $t7, 1
  sw    $t7, 0x60c($sp)
  lwc1  $f16, 0x8c($s0)
  lwc1  $f10, 0x628($sp)
  c.lt.s $f22, $f16
  nop   
  bc1fl .Ljp7F045EEC
   lw    $t9, ($s0)
  lwc1  $f2, 4($s0)
  lwc1  $f12, 8($s0)
  lwc1  $f4, 0x62c($sp)
  mul.s $f6, $f2, $f10
  lwc1  $f0, 0xc($s0)
  li    $at, 0x3F800000 # 1.000000
  mul.s $f8, $f12, $f4
  add.s $f4, $f6, $f8
  lwc1  $f6, 0x630($sp)
  mul.s $f8, $f6, $f0
  mtc1  $at, $f6
  add.s $f14, $f8, $f4
  add.s $f8, $f16, $f6
  neg.s $f4, $f8
  mul.s $f14, $f14, $f4
  nop   
  mul.s $f6, $f14, $f10
  add.s $f8, $f2, $f6
  swc1  $f8, 4($s0)
  lwc1  $f4, 0x62c($sp)
  mul.s $f10, $f14, $f4
  add.s $f6, $f12, $f10
  swc1  $f6, 8($s0)
  lwc1  $f8, 0x630($sp)
  mul.s $f4, $f14, $f8
  add.s $f10, $f0, $f4
  swc1  $f10, 0xc($s0)
  lw    $t9, ($s0)
.Ljp7F045EEC:
  andi  $t8, $t9, 0x200
  bnezl $t8, .Ljp7F045F04
   lw    $t0, 0x90($s0)
  jal   sub_GAME_7F057AC0
   lw    $a0, 0x70($sp)
  lw    $t0, 0x90($s0)
.Ljp7F045F04:
  lui   $a1, %hi(D_80030B0C) # $a1, 0x8003
  li    $a2, -1
  addiu $t1, $t0, 1
  sw    $t1, 0x90($s0)
  lw    $a1, %lo(D_80030B0C)($a1)
  jal   recall_joy2_hits_edit_detail_edit_flag
   lb    $a0, 0x80($s1)
  lui   $t3, %hi(D_80030B0C) # $t3, 0x8003
  lw    $t3, %lo(D_80030B0C)($t3)
  lui   $v0, %hi(bodypartshot) # $v0, 0x8003
  lbu   $t4, 1($t3)
  andi  $t6, $t4, 2
  beql  $t6, $zero, .Ljp7F04614C
   lw    $t9, 0x60c($sp)
  lw    $v0, %lo(bodypartshot)($v0)
  li    $at, 100
  beq   $v0, $at, .Ljp7F046148
   li    $at, 110
  beq   $v0, $at, .Ljp7F046148
   lui   $a0, %hi(objinst) # $a0, 0x8007
  lui   $a1, %hi(dword_CODE_bss_80075B74) # $a1, 0x8007
  lw    $a1, %lo(dword_CODE_bss_80075B74)($a1)
  lw    $a0, %lo(objinst)($a0)
  jal   sub_GAME_7F06C660
   move  $a2, $zero
  lwc1  $f6, 0x61c($sp)
  lwc1  $f8, 0x620($sp)
  lwc1  $f4, 0x624($sp)
  move  $s2, $v0
  swc1  $f6, 0x5d4($sp)
  swc1  $f8, 0x5d8($sp)
  jal   get_BONDdata_field_10CC
   swc1  $f4, 0x5dc($sp)
  move  $a0, $v0
  jal   sub_GAME_7F058474
   addiu $a1, $sp, 0x5d4
  lwc1  $f10, 0x5d4($sp)
  lwc1  $f6, 0x30($s2)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f0
  sub.s $f8, $f10, $f6
  lui   $a0, %hi(objinst) # $a0, 0x8007
  lui   $a1, %hi(dword_CODE_bss_80075B74) # $a1, 0x8007
  lw    $a1, %lo(dword_CODE_bss_80075B74)($a1)
  mul.s $f4, $f8, $f0
  lwc1  $f8, 0x5d8($sp)
  lw    $a0, %lo(objinst)($a0)
  add.s $f6, $f10, $f4
  swc1  $f6, 0x5d4($sp)
  lwc1  $f10, 0x34($s2)
  sub.s $f4, $f8, $f10
  mul.s $f6, $f4, $f0
  lwc1  $f4, 0x5dc($sp)
  add.s $f10, $f8, $f6
  swc1  $f10, 0x5d8($sp)
  lwc1  $f8, 0x38($s2)
  sub.s $f6, $f4, $f8
  mul.s $f10, $f6, $f0
  add.s $f8, $f4, $f10
  jal   getjointsize
   swc1  $f8, 0x5dc($sp)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f6
  lui   $at, %hi(flt_CODE_bss_80075B88) # $at, 0x8007
  lwc1  $f10, %lo(flt_CODE_bss_80075B88)($at)
  mul.s $f4, $f0, $f6
  lwc1  $f6, 0x5d4($sp)
  lui   $a0, %hi(objinst) # $a0, 0x8007
  lui   $a1, %hi(dword_CODE_bss_80075B74) # $a1, 0x8007
  lw    $a1, %lo(dword_CODE_bss_80075B74)($a1)
  lw    $a0, %lo(objinst)($a0)
  mul.s $f8, $f4, $f10
  sub.s $f4, $f6, $f8
  jal   getjointsize
   swc1  $f4, 0x5d4($sp)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f10
  lui   $at, %hi(flt_CODE_bss_80075B8C) # $at, 0x8007
  lwc1  $f8, %lo(flt_CODE_bss_80075B8C)($at)
  mul.s $f6, $f0, $f10
  lwc1  $f10, 0x5d8($sp)
  lui   $a0, %hi(objinst) # $a0, 0x8007
  lui   $a1, %hi(dword_CODE_bss_80075B74) # $a1, 0x8007
  lw    $a1, %lo(dword_CODE_bss_80075B74)($a1)
  lw    $a0, %lo(objinst)($a0)
  mul.s $f4, $f6, $f8
  sub.s $f6, $f10, $f4
  jal   getjointsize
   swc1  $f6, 0x5d8($sp)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f8
  lui   $at, %hi(flt_CODE_bss_80075B90) # $at, 0x8007
  lwc1  $f4, %lo(flt_CODE_bss_80075B90)($at)
  mul.s $f10, $f0, $f8
  lwc1  $f8, 0x5dc($sp)
  move  $a0, $s2
  addiu $a1, $sp, 0x594
  mul.s $f6, $f10, $f4
  sub.s $f10, $f8, $f6
  jal   sub_GAME_7F059E64
   swc1  $f10, 0x5dc($sp)
  addiu $a0, $sp, 0x594
  jal   sub_GAME_7F058474
   addiu $a1, $sp, 0x5d4
  lui   $a0, %hi(objinst) # $a0, 0x8007
  lui   $a1, %hi(bodypartshot) # $a1, 0x8003
  lui   $a2, %hi(dword_CODE_bss_80075B74) # $a2, 0x8007
  lw    $a2, %lo(dword_CODE_bss_80075B74)($a2)
  lw    $a1, %lo(bodypartshot)($a1)
  lw    $a0, %lo(objinst)($a0)
  jal   sub_GAME_7F0221DC
   addiu $a3, $sp, 0x5d4
  b     .Ljp7F04614C
   lw    $t9, 0x60c($sp)
  li    $at, 86
.Ljp7F0460D0:
  bnel  $v0, $at, .Ljp7F04614C
   lw    $t9, 0x60c($sp)
  lbu   $v0, ($s2)
  li    $t2, 1
  li    $at, 3
  bne   $v0, $at, .Ljp7F046108
   sw    $t2, 0x60c($sp)
  lw    $a0, 4($s2)
  addiu $a1, $s1, 0x58
  lui   $a2, 0x4000
  jal   sub_GAME_7F027804
   li    $a3, 1
  b     .Ljp7F046148
   sh    $zero, 0x82($s1)
.Ljp7F046108:
  li    $at, 1
  beq   $v0, $at, .Ljp7F046120
   lui   $a1, 0x42c8
  li    $at, 4
  bnel  $v0, $at, .Ljp7F046148
   sh    $zero, 0x82($s1)
.Ljp7F046120:
  lw    $v0, 0x64($s1)
  lui   $at, 6
  lw    $a0, 4($s2)
  and   $t5, $v0, $at
  srl   $t7, $t5, 0x11
  sw    $t7, 0x10($sp)
  addiu $a2, $s1, 0x58
  jal   maybe_detonate_object
   li    $a3, 86
  sh    $zero, 0x82($s1)
.Ljp7F046148:
  lw    $t9, 0x60c($sp)
.Ljp7F04614C:
  bnezl $t9, .Ljp7F04657C
   lw    $t7, 0x64($s1)
  lw    $t8, 0x66c($sp)
  bnezl $t8, .Ljp7F046220
   lw    $t1, ($s0)
  lwc1  $f16, 0x8c($s0)
  lwc1  $f4, 0x628($sp)
  c.lt.s $f22, $f16
  nop   
  bc1fl .Ljp7F046220
   lw    $t1, ($s0)
  lwc1  $f2, 4($s0)
  lwc1  $f12, 8($s0)
  lwc1  $f6, 0x62c($sp)
  mul.s $f8, $f2, $f4
  lwc1  $f0, 0xc($s0)
  li    $at, 0x3F800000 # 1.000000
  mul.s $f10, $f12, $f6
  c.le.s $f12, $f22
  add.s $f6, $f8, $f10
  lwc1  $f8, 0x630($sp)
  mul.s $f10, $f8, $f0
  mtc1  $at, $f8
  add.s $f14, $f10, $f6
  add.s $f10, $f16, $f8
  neg.s $f6, $f10
  mul.s $f14, $f14, $f6
  nop   
  mul.s $f8, $f14, $f4
  add.s $f10, $f2, $f8
  swc1  $f10, 4($s0)
  lwc1  $f6, 0x62c($sp)
  mul.s $f4, $f14, $f6
  add.s $f8, $f12, $f4
  swc1  $f8, 8($s0)
  lwc1  $f10, 0x630($sp)
  mul.s $f6, $f14, $f10
  add.s $f4, $f0, $f6
  bc1f  .Ljp7F04621C
   swc1  $f4, 0xc($s0)
  lwc1  $f8, 8($s0)
  li    $t0, 1
  c.le.s $f22, $f8
  nop   
  bc1tl .Ljp7F04621C
   sw    $t0, 0x614($sp)
  lwc1  $f10, 0x5c($s1)
  c.le.s $f20, $f10
  nop   
  bc1fl .Ljp7F046220
   lw    $t1, ($s0)
  sw    $t0, 0x614($sp)
.Ljp7F04621C:
  lw    $t1, ($s0)
.Ljp7F046220:
  lwc1  $f20, 0x644($sp)
  andi  $t3, $t1, 8
  bnez  $t3, .Ljp7F04627C
   nop   
  lw    $a0, 0x14($s3)
  lw    $a1, 8($s3)
  jal   sub_GAME_7F0B2970
   lw    $a2, 0x10($s3)
  mov.s $f20, $f0
  lw    $a0, 0x648($sp)
  jal   sub_GAME_7F03E9BC
   lw    $a1, 0x74($sp)
  sub.s $f4, $f20, $f0
  swc1  $f0, 0x640($sp)
  lwc1  $f6, 0xc($s3)
  move  $t4, $zero
  c.lt.s $f6, $f4
  nop   
  bc1f  .Ljp7F046274
   nop   
  li    $t4, 1
.Ljp7F046274:
  b     .Ljp7F04627C
   sw    $t4, 0x618($sp)
.Ljp7F04627C:
  lw    $t6, 0x618($sp)
  lw    $t2, 0x66c($sp)
  bnezl $t6, .Ljp7F046298
   lw    $t5, ($s0)
  bnezl $t2, .Ljp7F0462BC
   lw    $t0, 0x618($sp)
  lw    $t5, ($s0)
.Ljp7F046298:
  andi  $t7, $t5, 0x200
  bnezl $t7, .Ljp7F0462B0
   lw    $t9, 0x90($s0)
  jal   sub_GAME_7F057AC0
   lw    $a0, 0x70($sp)
  lw    $t9, 0x90($s0)
.Ljp7F0462B0:
  addiu $t8, $t9, 1
  sw    $t8, 0x90($s0)
  lw    $t0, 0x618($sp)
.Ljp7F0462BC:
  lw    $t1, 0x614($sp)
  lw    $t3, 0x618($sp)
  bnez  $t0, .Ljp7F0462D4
   nop   
  beql  $t1, $zero, .Ljp7F0463B8
   lbu   $t9, 3($s1)
.Ljp7F0462D4:
  beqz  $t3, .Ljp7F0462FC
   lwc1  $f4, 0x620($sp)
  lwc1  $f8, 0x640($sp)
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f6
  sub.s $f10, $f20, $f8
  add.s $f0, $f10, $f6
  swc1  $f0, 0xc($s3)
  b     .Ljp7F046318
   swc1  $f0, 0x5c($s1)
.Ljp7F0462FC:
  lwc1  $f8, 0x640($sp)
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f6
  sub.s $f10, $f4, $f8
  add.s $f2, $f10, $f6
  swc1  $f2, 0xc($s3)
  swc1  $f2, 0x5c($s1)
.Ljp7F046318:
  lw    $v1, 0x64($s1)
  move  $a0, $s1
  sll   $t4, $v1, 0xf
  bltz  $t4, .Ljp7F046330
   ori   $t6, $v1, 0x100
  sw    $t6, 0x64($s1)
.Ljp7F046330:
  lwc1  $f16, 0x8c($s0)
  c.lt.s $f22, $f16
  nop   
  bc1f  .Ljp7F0463AC
   nop   
  lwc1  $f4, 8($s0)
  neg.s $f8, $f16
  lui   $at, %hi(D_80052AA8) # $at, 0x8005
  mul.s $f10, $f4, $f8
  lwc1  $f0, %lo(D_80052AA8)($at)
  swc1  $f10, 8($s0)
  lwc1  $f6, 8($s0)
  c.lt.s $f6, $f0
  nop   
  bc1fl .Ljp7F0463B8
   lbu   $t9, 3($s1)
  lw    $t2, ($s0)
  move  $a0, $s1
  andi  $t5, $t2, 2
  beqz  $t5, .Ljp7F04639C
   nop   
  lw    $t7, 0x90($s0)
  li    $at, 1
  bne   $t7, $at, .Ljp7F04639C
   nop   
  b     .Ljp7F0463B4
   swc1  $f0, 8($s0)
.Ljp7F04639C:
  jal   sub_GAME_7F0431E4
   addiu $a1, $sp, 0x634
  b     .Ljp7F0463B8
   lbu   $t9, 3($s1)
.Ljp7F0463AC:
  jal   sub_GAME_7F0431E4
   addiu $a1, $sp, 0x634
.Ljp7F0463B4:
  lbu   $t9, 3($s1)
.Ljp7F0463B8:
  li    $at, 8
  bnel  $t9, $at, .Ljp7F04657C
   lw    $t7, 0x64($s1)
  lb    $v0, 0x80($s1)
  li    $at, 3
  bnel  $v0, $at, .Ljp7F0463E8
   li    $at, 86
  jal   sub_GAME_7F043650
   move  $a0, $s1
  b     .Ljp7F0464E8
   lw    $t3, 0x66c($sp)
  li    $at, 86
.Ljp7F0463E8:
  bne   $v0, $at, .Ljp7F0464A0
   lw    $t8, 0x66c($sp)
  beqz  $t8, .Ljp7F046400
   lw    $t0, 0x618($sp)
  beql  $t0, $zero, .Ljp7F04640C
   lwc1  $f2, 4($s0)
.Ljp7F046400:
  b     .Ljp7F0464E4
   sh    $zero, 0x82($s1)
  lwc1  $f2, 4($s0)
.Ljp7F04640C:
  lwc1  $f12, 8($s0)
  lwc1  $f0, 0xc($s0)
  mul.s $f4, $f2, $f2
  lui    $at, %hi(D_80052AAC)
  addiu $a0, $s1, 0x58
  mul.s $f8, $f12, $f12
  li    $a2, 8
  mul.s $f6, $f0, $f0
  add.s $f10, $f4, $f8
  lwc1  $f4, %lo(D_80052AAC)($at)
  add.s $f14, $f6, $f10
  c.lt.s $f4, $f14
  nop   
  bc1fl .Ljp7F046458
   lw    $t1, 0xa8($s0)
  swc1  $f22, 0x10($s0)
  swc1  $f22, 0x14($s0)
  swc1  $f22, 0x18($s0)
  lw    $t1, 0xa8($s0)
.Ljp7F046458:
  slti  $at, $t1, 0x12d
  bnezl $at, .Ljp7F046480
   lbu   $t6, 1($s3)
  lw    $t3, ($s0)
  li    $at, -49
  swc1  $f22, 0x1c($s0)
  and   $t4, $t3, $at
  b     .Ljp7F0464E4
   sw    $t4, ($s0)
  lbu   $t6, 1($s3)
.Ljp7F046480:
  lw    $a1, 0x14($s3)
  addiu $a3, $s3, 0x2c
  andi  $t2, $t6, 8
  sltu  $t5, $zero, $t2
  jal   sub_GAME_7F09E700
   sw    $t5, 0x10($sp)
  b     .Ljp7F0464E8
   lw    $t3, 0x66c($sp)
.Ljp7F0464A0:
  li    $at, 87
  bne   $v0, $at, .Ljp7F0464E4
   lw    $t7, 0x618($sp)
  bnez  $t7, .Ljp7F0464BC
   lw    $t9, 0x614($sp)
  beqz  $t9, .Ljp7F0464C4
   addiu $a0, $s1, 0x58
.Ljp7F0464BC:
  b     .Ljp7F0464E4
   sh    $zero, 0x82($s1)
.Ljp7F0464C4:
  lbu   $t8, 1($s3)
  lw    $a1, 0x14($s3)
  li    $a2, 9
  andi  $t0, $t8, 8
  sltu  $t1, $zero, $t0
  sw    $t1, 0x10($sp)
  jal   sub_GAME_7F09E700
   addiu $a3, $s3, 0x2c
.Ljp7F0464E4:
  lw    $t3, 0x66c($sp)
.Ljp7F0464E8:
  lui   $s2, %hi(D_80048380) # $s2, 0x8005
  addiu $s2, %lo(D_80048380) # addiu $s2, $s2, -0x7c50
  beqz  $t3, .Ljp7F046500
   lw    $t4, 0x618($sp)
  beql  $t4, $zero, .Ljp7F04657C
   lw    $t7, 0x64($s1)
.Ljp7F046500:
  lw    $v0, ($s2)
  lw    $t6, 0xac($s0)
  addiu $t2, $v0, -2
  slt   $at, $t6, $t2
  beql  $at, $zero, .Ljp7F046578
   sw    $v0, 0xac($s0)
  lb    $v0, 0x80($s1)
  addiu $t5, $s3, 8
  li    $at, 3
  beq   $v0, $at, .Ljp7F046538
   sw    $t5, 0x74($sp)
  li    $at, 2
  bne   $v0, $at, .Ljp7F046554
   lui   $a0, %hi(ptr_sfx_buf)
.Ljp7F046538:
  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 3
  jal   play_sfx_a1
   move  $a2, $zero
  b     .Ljp7F046568
   move  $a0, $v0
.Ljp7F046554:
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 45
  jal   play_sfx_a1
   move  $a2, $zero
  move  $a0, $v0
.Ljp7F046568:
  jal   sub_GAME_7F053A10
   lw    $a1, 0x74($sp)
  lw    $v0, ($s2)
  sw    $v0, 0xac($s0)
.Ljp7F046578:
  lw    $t7, 0x64($s1)
.Ljp7F04657C:
  lui   $s2, %hi(D_80048380) # $s2, 0x8005
  addiu $s2, %lo(D_80048380) # addiu $s2, $s2, -0x7c50
  andi  $t9, $t7, 0x80
  beql  $t9, $zero, .Ljp7F046A20
   lw    $t3, 0x698($sp)
  lw    $t8, ($s0)
  andi  $t0, $t8, 0x400
  beql  $t0, $zero, .Ljp7F046A20
   lw    $t3, 0x698($sp)
  lw    $v0, ($s2)
  li    $at, 0x43C80000 # 400.000000
  addiu $s0, $sp, 0x56c
  andi  $t1, $v0, 7
  bnez  $t1, .Ljp7F046A1C
   move  $a0, $zero
  mtc1  $at, $f0
  lwc1  $f8, 0x58($s1)
  li    $at, 0x44E10000 # 1800.000000
  mtc1  $at, $f4
  add.s $f6, $f8, $f0
  andi  $t3, $v0, 0xf
  swc1  $f6, 0x56c($sp)
  lwc1  $f10, 0x5c($s1)
  sub.s $f8, $f10, $f4
  swc1  $f8, 0x570($sp)
  lwc1  $f6, 0x60($s1)
  bnez  $t3, .Ljp7F0465FC
   swc1  $f6, 0x574($sp)
  lwc1  $f10, 0x574($sp)
  add.s $f4, $f10, $f0
  b     .Ljp7F046608
   swc1  $f4, 0x574($sp)
.Ljp7F0465FC:
  lwc1  $f8, 0x574($sp)
  sub.s $f6, $f8, $f0
  swc1  $f6, 0x574($sp)
.Ljp7F046608:
  lw    $v0, 0x10($s1)
  move  $a1, $s0
  li    $a3, 20
  lw    $a2, 0x14($v0)
  addiu $t4, $v0, 0x2c
  sw    $t4, 0x18($sp)
  sw    $zero, 0x1c($sp)
  sw    $zero, 0x14($sp)
  jal   sub_GAME_7F09C250
   sw    $zero, 0x10($sp)
  lw    $t6, ($s2)
  li    $at, 40
  move  $a0, $s0
  div   $zero, $t6, $at
  mfhi  $t2
  bnezl $t2, .Ljp7F046A20
   lw    $t3, 0x698($sp)
  lw    $v0, 0x10($s1)
  li    $t5, 1
  li    $a2, 10
  lw    $a1, 0x14($v0)
  sw    $t5, 0x10($sp)
  jal   sub_GAME_7F09E700
   addiu $a3, $v0, 0x2c
  b     .Ljp7F046A20
   lw    $t3, 0x698($sp)
  lwc1  $f0, 0x60($s0)
.Ljp7F046674:
  mtc1  $at, $f10
  li    $s2, 1
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  c.lt.s $f0, $f10
  addiu $a0, $s0, 0x68
  addiu $a1, $s0, 0x78
  bc1fl .Ljp7F046754
   lwc1  $f10, 4($s0)
  lwc1  $f2, 0x64($s0)
  lwc1  $f4, %lo(global_timer_delta)($at)
  lui   $t7, %hi(clock_timer) # $t7, 0x8005
  lui   $at, %hi(D_80052AB0)
  mul.s $f8, $f2, $f4
  addiu $s2, $sp, 0x558
  add.s $f6, $f0, $f8
  swc1  $f6, 0x60($s0)
  lw    $t7, %lo(clock_timer)($t7)
  blezl $t7, .Ljp7F0466D0
   li    $at, 0x3F800000 # 1.000000
  lwc1  $f10, %lo(D_80052AB0)($at)
  mul.s $f4, $f2, $f10
  swc1  $f4, 0x64($s0)
  li    $at, 0x3F800000 # 1.000000
.Ljp7F0466D0:
  mtc1  $at, $f8
  lwc1  $f0, 0x60($s0)
  li    $at, 0x3F800000 # 1.000000
  c.lt.s $f8, $f0
  nop   
  bc1tl .Ljp7F046700
   mtc1  $at, $f6
  lw    $t9, ($s0)
  andi  $t8, $t9, 8
  beql  $t8, $zero, .Ljp7F046710
   mfc1  $a2, $f0
  mtc1  $at, $f6
.Ljp7F046700:
  nop   
  swc1  $f6, 0x60($s0)
  lwc1  $f0, 0x60($s0)
  mfc1  $a2, $f0
.Ljp7F046710:
  jal   sub_GAME_7F05BA08
   move  $a3, $s2
  addiu $a1, $s1, 0x18
  sw    $a1, 0x74($sp)
  jal   sub_GAME_7F05B628
   move  $a0, $s2
  lwc1  $f12, 0xc0($s0)
  jal   sub_GAME_7F0589B4
   lw    $a1, 0x74($sp)
  lwc1  $f12, 0xc4($s0)
  jal   sub_GAME_7F0589E4
   lw    $a1, 0x74($sp)
  lwc1  $f12, 0xc8($s0)
  jal   sub_GAME_7F058A4C
   lw    $a1, 0x74($sp)
  move  $s2, $zero
  lwc1  $f10, 4($s0)
.Ljp7F046754:
  c.eq.s $f22, $f10
  nop   
  bc1fl .Ljp7F04679C
   lw    $t0, ($s0)
  lwc1  $f4, 0xc($s0)
  li    $at, 0x3F800000 # 1.000000
  c.eq.s $f22, $f4
  nop   
  bc1fl .Ljp7F04679C
   lw    $t0, ($s0)
  lwc1  $f8, 0x60($s0)
  mtc1  $at, $f6
  nop   
  c.lt.s $f8, $f6
  nop   
  bc1f  .Ljp7F0469B4
   nop   
  lw    $t0, ($s0)
.Ljp7F04679C:
  move  $a0, $s1
  addiu $t3, $s1, 0x18
  andi  $t1, $t0, 8
  bnez  $t1, .Ljp7F0469B4
   nop   
  sw    $t3, 0x74($sp)
  jal   sub_GAME_7F040078
   move  $s2, $zero
  lui   $v1, %hi(clock_timer) # $v1, 0x8005
  lw    $v1, %lo(clock_timer)($v1)
  sw    $v0, 0x554($sp)
  move  $a0, $zero
  blez  $v1, .Ljp7F0468F0
   lui   $at, %hi(D_80052AB4) # $at, 0x8005
  lwc1  $f14, %lo(D_80052AB4)($at)
  lwc1  $f10, 0x69c($sp)
.Ljp7F0467DC:
  lwc1  $f4, 4($s0)
  lwc1  $f6, 0x6a4($sp)
  li    $at, 0x3F800000 # 1.000000
  add.s $f8, $f10, $f4
  swc1  $f8, 0x69c($sp)
  lwc1  $f10, 0xc($s0)
  add.s $f4, $f6, $f10
  mtc1  $at, $f6
  swc1  $f4, 0x6a4($sp)
  lwc1  $f8, 0x60($s0)
  c.le.s $f6, $f8
  nop   
  bc1fl .Ljp7F0468E4
   addiu $a0, $a0, 1
  lwc1  $f10, 0x94($s0)
  c.lt.s $f22, $f10
  nop   
  bc1fl .Ljp7F0468C0
   lwc1  $f6, 4($s0)
  lwc1  $f0, 0xc($s0)
  lwc1  $f2, 4($s0)
  sw    $a0, 0x550($sp)
  mul.s $f4, $f0, $f0
  nop   
  mul.s $f8, $f2, $f2
  jal   sqrtf
   add.s $f12, $f4, $f8
  lui   $at, %hi(D_80052AB8) # $at, 0x8005
  lwc1  $f14, %lo(D_80052AB8)($at)
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  lwc1  $f10, %lo(global_timer_delta)($at)
  lwc1  $f6, 0x94($s0)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  mul.s $f4, $f6, $f10
  lw    $a0, 0x550($sp)
  lui   $v1, %hi(clock_timer) # $v1, 0x8005
  div.s $f12, $f4, $f0
  c.le.s $f8, $f12
  nop   
  bc1fl .Ljp7F046894
   lwc1  $f2, 4($s0)
  swc1  $f22, 4($s0)
  b     .Ljp7F0468B4
   swc1  $f22, 0xc($s0)
  lwc1  $f2, 4($s0)
.Ljp7F046894:
  lwc1  $f0, 0xc($s0)
  mul.s $f6, $f2, $f12
  nop   
  mul.s $f4, $f0, $f12
  sub.s $f10, $f2, $f6
  sub.s $f8, $f0, $f4
  swc1  $f10, 4($s0)
  swc1  $f8, 0xc($s0)
.Ljp7F0468B4:
  b     .Ljp7F0468E0
   lw    $v1, %lo(clock_timer)($v1)
  lwc1  $f6, 4($s0)
.Ljp7F0468C0:
  lwc1  $f4, 0xc($s0)
  lui   $v1, %hi(clock_timer) # $v1, 0x8005
  mul.s $f10, $f6, $f14
  nop   
  mul.s $f8, $f4, $f14
  swc1  $f10, 4($s0)
  swc1  $f8, 0xc($s0)
  lw    $v1, %lo(clock_timer)($v1)
.Ljp7F0468E0:
  addiu $a0, $a0, 1
.Ljp7F0468E4:
  slt   $at, $a0, $v1
  bnezl $at, .Ljp7F0467DC
   lwc1  $f10, 0x69c($sp)
.Ljp7F0468F0:
  move  $a0, $s1
  addiu $a1, $sp, 0x69c
  addiu $a2, $sp, 0x538
  addiu $a3, $sp, 0x544
  sw    $zero, 0x10($sp)
  jal   sub_GAME_7F042EB4
   sw    $zero, 0x14($sp)
  li    $t4, 1
  sw    $t4, 0x698($sp)
  lw    $a2, 0x10($s3)
  lw    $a1, 8($s3)
  jal   sub_GAME_7F0B2970
   lw    $a0, 0x14($s3)
  mov.s $f20, $f0
  lw    $a0, 0x554($sp)
  jal   sub_GAME_7F03E9BC
   lw    $a1, 0x74($sp)
  lui   $at, %hi(D_80052ABC) # $at, 0x8005
  lwc1  $f14, %lo(D_80052ABC)($at)
  sub.s $f6, $f20, $f0
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f10
  lui   $at, %hi(D_80052AC0) # $at, 0x8005
  add.s $f12, $f6, $f10
  swc1  $f12, 0xc($s3)
  swc1  $f12, 0x5c($s1)
  lwc1  $f2, 4($s0)
  c.lt.s $f2, $f14
  nop   
  bc1f  .Ljp7F0469B4
   nop   
  lwc1  $f4, %lo(D_80052AC0)($at)
  c.lt.s $f4, $f2
  nop   
  bc1f  .Ljp7F0469B4
   nop   
  lwc1  $f0, 0xc($s0)
  lui   $at, %hi(D_80052AC4) # $at, 0x8005
  c.lt.s $f0, $f14
  nop   
  bc1f  .Ljp7F0469B4
   nop   
  lwc1  $f8, %lo(D_80052AC4)($at)
  c.lt.s $f8, $f0
  nop   
  bc1f  .Ljp7F0469B4
   nop   
  swc1  $f22, 0xc($s0)
  swc1  $f22, 4($s0)
.Ljp7F0469B4:
  bnez  $s2, .Ljp7F0469CC
   nop   
  lw    $t6, ($s0)
  andi  $t2, $t6, 8
  beql  $t2, $zero, .Ljp7F046A20
   lw    $t3, 0x698($sp)
.Ljp7F0469CC:
  jal   sub_GAME_7F03FB70
   move  $a0, $s0
  lw    $t5, 0x64($s1)
  li    $at, -129
  sw    $zero, 0x6c($s1)
  and   $t7, $t5, $at
  sw    $t7, 0x64($s1)
  lbu   $v0, 1($s3)
  andi  $t9, $v0, 8
  beqz  $t9, .Ljp7F0469FC
   ori   $t8, $v0, 0x10
  sb    $t8, 1($s3)
.Ljp7F0469FC:
  lbu   $t0, 3($s1)
  li    $at, 8
  bnel  $t0, $at, .Ljp7F046A20
   lw    $t3, 0x698($sp)
  lw    $t1, 0x14($s3)
  lb    $a0, 0x80($s1)
  jal   sub_GAME_7F0577E8
   lbu   $a1, 3($t1)
.Ljp7F046A1C:
  lw    $t3, 0x698($sp)
.Ljp7F046A20:
  beqz  $t3, .Ljp7F046A50
   addiu $t4, $s1, 0x58
  sw    $t4, 0x74($sp)
  jal   sub_GAME_7F040484
   move  $a0, $s1
  jal   sub_GAME_7F056CA0
   move  $a0, $s1
  lw    $a0, 0x10($s1)
  jal   sub_GAME_7F0402B4
   addiu $a1, $s1, 0x7c
  jal   detonate_proxmine_In_range
   lw    $a0, 0x74($sp)
.Ljp7F046A50:
  lbu   $v0, 3($s1)
  li    $at, 1
  bnel  $v0, $at, .Ljp7F046BA4
   li    $at, 6
  lw    $s0, 4($s3)
  lwc1  $f6, 0xb4($s0)
  swc1  $f6, 0x684($sp)
  lw    $v0, 0xec($s0)
  blezl $v0, .Ljp7F046AC0
   lb    $t0, 0xbc($s0)
  lb    $t6, 0xbc($s0)
  bnezl $t6, .Ljp7F046AC0
   lb    $t0, 0xbc($s0)
  lw    $t2, 8($s0)
  lui   $t7, %hi(global_timer) # $t7, 0x8005
  sll   $t5, $t2, 0
  bltzl $t5, .Ljp7F046AC0
   lb    $t0, 0xbc($s0)
  lw    $t7, %lo(global_timer)($t7)
  lw    $t9, 0xa0($s0)
  move  $a0, $s0
  subu  $t8, $t7, $t9
  slt   $at, $v0, $t8
  beql  $at, $zero, .Ljp7F046AC0
   lb    $t0, 0xbc($s0)
  jal   set_door_state
   li    $a1, 2
  lb    $t0, 0xbc($s0)
.Ljp7F046AC0:
  li    $at, 3
  bnel  $t0, $at, .Ljp7F046B34
   lhu   $t3, 0x9a($s0)
  lw    $v0, 0xc8($s0)
  li    $v1, 1
  move  $a0, $s0
  beqz  $v0, .Ljp7F046B20
   nop   
  beq   $v0, $s0, .Ljp7F046B20
   nop   
  lb    $t1, 0xbc($v0)
.Ljp7F046AEC:
  bnezl $t1, .Ljp7F046B0C
   move  $v1, $zero
  lwc1  $f10, 0xb4($v0)
  c.lt.s $f22, $f10
  nop   
  bc1fl .Ljp7F046B10
   lw    $v0, 0xc8($v0)
  move  $v1, $zero
.Ljp7F046B0C:
  lw    $v0, 0xc8($v0)
.Ljp7F046B10:
  beqz  $v0, .Ljp7F046B20
   nop   
  bnel  $v0, $s0, .Ljp7F046AEC
   lb    $t1, 0xbc($v0)
.Ljp7F046B20:
  beql  $v1, $zero, .Ljp7F046B34
   lhu   $t3, 0x9a($s0)
  jal   sub_GAME_7F0548A4
   li    $a1, 1
  lhu   $t3, 0x9a($s0)
.Ljp7F046B34:
  li    $at, 8
  bne   $t3, $at, .Ljp7F046B68
   nop   
  jal   sub_GAME_7F054A20
   move  $a0, $s0
  beqz  $v0, .Ljp7F046B68
   nop   
  jal   sub_GAME_7F03E718
   move  $a0, $s0
  beqz  $v0, .Ljp7F046B68
   nop   
  jal   sub_GAME_7F05599C
   move  $a0, $s3
.Ljp7F046B68:
  lui   $t6, %hi(global_timer) # $t6, 0x8005
  lw    $t6, %lo(global_timer)($t6)
  lw    $t4, 0xfc($s0)
  lui   $t2, %hi(clock_timer) # $t2, 0x8005
  slt   $at, $t4, $t6
  bnez  $at, .Ljp7F046B90
   nop   
  lw    $t2, %lo(clock_timer)($t2)
  bnezl $t2, .Ljp7F048634
   lbu   $v0, 3($s1)
.Ljp7F046B90:
  jal   sub_GAME_7F054FB4
   move  $a0, $s0
  b     .Ljp7F048634
   lbu   $v0, 3($s1)
  li    $at, 6
.Ljp7F046BA4:
  bnel  $v0, $at, .Ljp7F047068
   li    $at, 13
  lw    $t5, 8($s1)
  sll   $t7, $t5, 3
  bltzl $t7, .Ljp7F047068
   li    $at, 13
  lw    $s0, 4($s3)
  lw    $t9, 0xd4($s0)
  beql  $t9, $zero, .Ljp7F046BD8
   lwc1  $f18, 0xd0($s0)
  b     .Ljp7F046BD8
   lwc1  $f18, 0xcc($s0)
  lwc1  $f18, 0xd0($s0)
.Ljp7F046BD8:
  jal   get_curplayer_positiondata
   swc1  $f18, 0x51c($sp)
  sw    $v0, 0x518($sp)
  lwc1  $f8, 0x58($s1)
  lwc1  $f4, 8($v0)
  lwc1  $f0, 0xe8($s0)
  lwc1  $f10, 0x5c($s1)
  sub.s $f12, $f4, $f8
  lwc1  $f6, 0xc($v0)
  lwc1  $f8, 0x60($s1)
  c.lt.s $f22, $f0
  lwc1  $f4, 0x10($v0)
  lwc1  $f18, 0x51c($sp)
  li    $s2, 1
  sub.s $f2, $f6, $f10
  bc1f  .Ljp7F046C50
   sub.s $f14, $f4, $f8
  mul.s $f6, $f0, $f0
  nop   
  mul.s $f10, $f12, $f12
  nop   
  mul.s $f4, $f2, $f2
  add.s $f8, $f10, $f4
  mul.s $f10, $f14, $f14
  add.s $f4, $f8, $f10
  c.lt.s $f6, $f4
  nop   
  bc1f  .Ljp7F046C50
   nop   
  move  $s2, $zero
.Ljp7F046C50:
  lw    $t8, 8($s1)
  sll   $t0, $t8, 2
  bgez  $t0, .Ljp7F046C64
   nop   
  move  $s2, $zero
.Ljp7F046C64:
  beqz  $s2, .Ljp7F046D50
   nop   
  jal   convert_angle_using_inverse
   swc1  $f18, 0x51c($sp)
  lwc1  $f2, 0xc8($s0)
  lwc1  $f18, 0x51c($sp)
  lui   $at, %hi(D_80052ACC)
  c.lt.s $f2, $f22
  nop   
  bc1f  .Ljp7F046CA0
   nop   
  lui   $at, %hi(D_80052AC8) # $at, 0x8005
  lwc1  $f20, %lo(D_80052AC8)($at)
  b     .Ljp7F046CB8
   add.s $f2, $f2, $f20
.Ljp7F046CA0:
  lwc1  $f20, %lo(D_80052ACC)($at)
  c.le.s $f20, $f2
  nop   
  bc1fl .Ljp7F046CBC
   lwc1  $f8, 0xc4($s0)
  sub.s $f2, $f2, $f20
.Ljp7F046CB8:
  lwc1  $f8, 0xc4($s0)
.Ljp7F046CBC:
  lui   $at, %hi(D_80052AD0) # $at, 0x8005
  add.s $f2, $f2, $f8
  c.le.s $f20, $f2
  nop   
  bc1fl .Ljp7F046CDC
   c.lt.s $f0, $f2
  sub.s $f2, $f2, $f20
  c.lt.s $f0, $f2
.Ljp7F046CDC:
  sub.s $f14, $f0, $f2
  bc1f  .Ljp7F046CEC
   mov.s $f12, $f14
  add.s $f12, $f14, $f20
.Ljp7F046CEC:
  lwc1  $f0, %lo(D_80052AD0)($at)
  lui   $at, %hi(D_80052AD4) # $at, 0x8005
  sub.s $f12, $f12, $f0
  c.lt.s $f12, $f22
  nop   
  bc1fl .Ljp7F046D10
   c.lt.s $f0, $f12
  add.s $f12, $f12, $f20
  c.lt.s $f0, $f12
.Ljp7F046D10:
  nop   
  bc1f  .Ljp7F046D20
   nop   
  sub.s $f12, $f12, $f20
.Ljp7F046D20:
  lwc1  $f10, %lo(D_80052AD4)($at)
  lui    $at, %hi(D_80052AD8)
  c.lt.s $f10, $f12
  nop   
  bc1tl .Ljp7F046D50
   move  $s2, $zero
  lwc1  $f6, %lo(D_80052AD8)($at)
  c.lt.s $f12, $f6
  nop   
  bc1f  .Ljp7F046D50
   nop   
  move  $s2, $zero
.Ljp7F046D50:
  beqz  $s2, .Ljp7F046E24
   move  $a1, $zero
  lw    $t1, 0x14($s3)
  swc1  $f18, 0x51c($sp)
  lw    $a0, 0x518($sp)
  jal   sub_GAME_7F08A03C
   sw    $t1, 0x4f4($sp)
  lw    $v0, 0x518($sp)
  li    $at, 0x42C80000 # 100.000000
  lw    $a1, 8($s3)
  lwc1  $f4, 0x10($v0)
  lw    $a2, 0x10($s3)
  lw    $a3, 8($v0)
  mtc1  $at, $f8
  mtc1  $at, $f10
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  li    $t3, 27
  sw    $t3, 0x14($sp)
  swc1  $f22, 0x20($sp)
  addiu $a0, $sp, 0x4f4
  swc1  $f4, 0x10($sp)
  swc1  $f8, 0x18($sp)
  swc1  $f10, 0x1c($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f6, 0x24($sp)
  beqz  $v0, .Ljp7F046E10
   lwc1  $f18, 0x51c($sp)
  lui   $t6, %hi(clock_timer) # $t6, 0x8005
  lw    $t6, %lo(clock_timer)($t6)
  lw    $t4, 0xe0($s0)
  li    $at, 0x43960000 # 300.000000
  mtc1  $at, $f4
  addu  $t2, $t4, $t6
  sw    $t2, 0xe0($s0)
  lui   $at, %hi(D_80030B14) # $at, 0x8003
  lwc1  $f8, %lo(D_80030B14)($at)
  mul.s $f10, $f4, $f8
  trunc.w.s $f6, $f10
  mfc1  $t9, $f6
  nop   
  slt   $at, $t2, $t9
  bnezl $at, .Ljp7F046E14
   lw    $a0, 0x518($sp)
  jal   start_alarm
   swc1  $f18, 0x51c($sp)
  lwc1  $f18, 0x51c($sp)
  sw    $zero, 0xe0($s0)
.Ljp7F046E10:
  lw    $a0, 0x518($sp)
.Ljp7F046E14:
  li    $a1, 1
  jal   sub_GAME_7F08A03C
   swc1  $f18, 0x51c($sp)
  lwc1  $f18, 0x51c($sp)
.Ljp7F046E24:
  lwc1  $f14, 0xc8($s0)
  c.lt.s $f14, $f18
  nop   
  bc1fl .Ljp7F046F50
   lwc1  $f0, 0xd8($s0)
  lwc1  $f0, 0xd8($s0)
  lui   $at, %hi(D_80052AE0) # $at, 0x8005
  lwc1  $f16, %lo(D_80052AE0)($at)
  mul.s $f4, $f0, $f0
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f8
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  mul.s $f10, $f4, $f8
  div.s $f2, $f10, $f16
  sub.s $f6, $f18, $f2
  c.le.s $f6, $f14
  nop   
  bc1fl .Ljp7F046EA8
   lwc1  $f12, 0xdc($s0)
  lwc1  $f4, %lo(global_timer_delta)($at)
  mul.s $f8, $f16, $f4
  sub.s $f10, $f0, $f8
  swc1  $f10, 0xd8($s0)
  lwc1  $f0, 0xd8($s0)
  c.lt.s $f0, $f16
  nop   
  bc1f  .Ljp7F046E9C
   nop   
  swc1  $f16, 0xd8($s0)
  lwc1  $f0, 0xd8($s0)
.Ljp7F046E9C:
  b     .Ljp7F046F14
   lwc1  $f14, 0xc8($s0)
  lwc1  $f12, 0xdc($s0)
.Ljp7F046EA8:
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  c.lt.s $f0, $f12
  nop   
  bc1f  .Ljp7F046F14
   nop   
  lwc1  $f6, %lo(global_timer_delta)($at)
  mul.s $f4, $f16, $f6
  add.s $f2, $f0, $f4
  c.lt.s $f12, $f2
  nop   
  bc1f  .Ljp7F046EDC
   nop   
  mov.s $f2, $f12
.Ljp7F046EDC:
  mul.s $f8, $f2, $f2
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f10
  nop   
  mul.s $f6, $f8, $f10
  div.s $f4, $f6, $f16
  sub.s $f8, $f18, $f4
  c.lt.s $f14, $f8
  nop   
  bc1f  .Ljp7F046F14
   nop   
  swc1  $f2, 0xd8($s0)
  lwc1  $f0, 0xd8($s0)
  lwc1  $f14, 0xc8($s0)
.Ljp7F046F14:
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  lwc1  $f10, %lo(global_timer_delta)($at)
  mul.s $f6, $f0, $f10
  add.s $f4, $f14, $f6
  swc1  $f4, 0xc8($s0)
  lwc1  $f8, 0xc8($s0)
  c.le.s $f18, $f8
  nop   
  bc1fl .Ljp7F048634
   lbu   $v0, 3($s1)
  swc1  $f18, 0xc8($s0)
  swc1  $f22, 0xd8($s0)
  b     .Ljp7F048630
   sw    $zero, 0xd4($s0)
  lwc1  $f0, 0xd8($s0)
.Ljp7F046F50:
  lui   $at, %hi(D_80052AE4) # $at, 0x8005
  lwc1  $f16, %lo(D_80052AE4)($at)
  mul.s $f10, $f0, $f0
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f6
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  li    $t8, 1
  mul.s $f4, $f10, $f6
  div.s $f2, $f4, $f16
  add.s $f8, $f18, $f2
  c.le.s $f14, $f8
  nop   
  bc1fl .Ljp7F046FC0
   lwc1  $f12, 0xdc($s0)
  lwc1  $f10, %lo(global_timer_delta)($at)
  mul.s $f6, $f16, $f10
  sub.s $f4, $f0, $f6
  swc1  $f4, 0xd8($s0)
  lwc1  $f0, 0xd8($s0)
  c.lt.s $f0, $f16
  nop   
  bc1f  .Ljp7F046FB4
   nop   
  swc1  $f16, 0xd8($s0)
  lwc1  $f0, 0xd8($s0)
.Ljp7F046FB4:
  b     .Ljp7F04702C
   lwc1  $f14, 0xc8($s0)
  lwc1  $f12, 0xdc($s0)
.Ljp7F046FC0:
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  c.lt.s $f0, $f12
  nop   
  bc1f  .Ljp7F04702C
   nop   
  lwc1  $f8, %lo(global_timer_delta)($at)
  mul.s $f10, $f16, $f8
  add.s $f2, $f0, $f10
  c.lt.s $f12, $f2
  nop   
  bc1f  .Ljp7F046FF4
   nop   
  mov.s $f2, $f12
.Ljp7F046FF4:
  mul.s $f6, $f2, $f2
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f4
  nop   
  mul.s $f8, $f6, $f4
  div.s $f10, $f8, $f16
  add.s $f6, $f18, $f10
  c.lt.s $f6, $f14
  nop   
  bc1f  .Ljp7F04702C
   nop   
  swc1  $f2, 0xd8($s0)
  lwc1  $f0, 0xd8($s0)
  lwc1  $f14, 0xc8($s0)
.Ljp7F04702C:
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  lwc1  $f4, %lo(global_timer_delta)($at)
  mul.s $f8, $f0, $f4
  sub.s $f10, $f14, $f8
  swc1  $f10, 0xc8($s0)
  lwc1  $f6, 0xc8($s0)
  c.le.s $f6, $f18
  nop   
  bc1fl .Ljp7F048634
   lbu   $v0, 3($s1)
  swc1  $f18, 0xc8($s0)
  swc1  $f22, 0xd8($s0)
  b     .Ljp7F048630
   sw    $t8, 0xd4($s0)
  li    $at, 13
.Ljp7F047068:
  bnel  $v0, $at, .Ljp7F047968
   li    $at, 39
  lw    $t0, 8($s1)
  sll   $t1, $t0, 3
  bltzl $t1, .Ljp7F047968
   li    $at, 39
  jal   get_curplayer_positiondata
   lw    $s0, 4($s3)
  sw    $zero, 0x4b0($sp)
  sw    $zero, 0x4ac($sp)
  sw    $zero, 0x4a8($sp)
  lw    $v1, 0xc($s1)
  move  $s2, $v0
  sll   $t3, $v1, 0
  bgez  $t3, .Ljp7F0471FC
   sll   $t4, $v1, 1
  bgezl $t4, .Ljp7F0470CC
   lwc1  $f2, 0x84($s0)
  lwc1  $f8, 0x90($s0)
  lwc1  $f4, 0x9c($s0)
  swc1  $f8, 0x84($s0)
  lwc1  $f2, 0x84($s0)
  b     .Ljp7F04719C
   swc1  $f4, 0x98($s0)
  lwc1  $f2, 0x84($s0)
.Ljp7F0470CC:
  lwc1  $f10, 0x90($s0)
  c.eq.s $f2, $f10
  nop   
  bc1f  .Ljp7F04719C
   nop   
  lwc1  $f6, 0x98($s0)
  lwc1  $f4, 0x9c($s0)
  c.eq.s $f6, $f4
  nop   
  bc1f  .Ljp7F04719C
   nop   
  jal   get_random_value
   nop   
  mtc1  $v0, $f8
  lui   $at, %hi(D_80052AE8) # $at, 0x8005
  lwc1  $f20, %lo(D_80052AE8)($at)
  bgez  $v0, .Ljp7F047124
   cvt.s.w $f10, $f8
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f6
  nop   
  add.s $f10, $f10, $f6
.Ljp7F047124:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f4
  li    $at, 0x421C0000 # 39.000000
  mtc1  $at, $f6
  mul.s $f8, $f10, $f4
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  li    $at, 0x43B40000 # 360.000000
  mul.s $f10, $f8, $f6
  add.s $f8, $f10, $f4
  mtc1  $at, $f10
  mul.s $f6, $f8, $f20
  div.s $f4, $f6, $f10
  jal   get_random_value
   swc1  $f4, 0x98($s0)
  mtc1  $v0, $f8
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .Ljp7F04717C
   cvt.s.w $f6, $f8
  mtc1  $at, $f10
  nop   
  add.s $f6, $f6, $f10
.Ljp7F04717C:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f4
  nop   
  mul.s $f8, $f6, $f4
  nop   
  mul.s $f10, $f8, $f20
  swc1  $f10, 0x84($s0)
  lwc1  $f2, 0x84($s0)
.Ljp7F04719C:
  lui   $at, %hi(D_80052AEC) # $at, 0x8005
  lwc1  $f0, %lo(D_80052AEC)($at)
  lui   $at, %hi(D_80052AF4) # $at, 0x8005
  lwc1  $f6, %lo(D_80052AF4)($at)
  mfc1  $a1, $f2
  mfc1  $a3, $f0
  addiu $a0, $s0, 0x90
  addiu $a2, $s0, 0x94
  swc1  $f0, 0x10($sp)
  jal   sub_GAME_7F04310C
   swc1  $f6, 0x14($sp)
  lui   $at, %hi(D_80052AF8) # $at, 0x8005
  lwc1  $f0, %lo(D_80052AF8)($at)
  lui   $at, %hi(D_80052AFC) # $at, 0x8005
  lwc1  $f4, %lo(D_80052AFC)($at)
  lw    $a1, 0x98($s0)
  mfc1  $a3, $f0
  addiu $a0, $s0, 0x9c
  addiu $a2, $s0, 0xa0
  swc1  $f0, 0x10($sp)
  jal   sub_GAME_7F04310C
   swc1  $f4, 0x14($sp)
  b     .Ljp7F048634
   lbu   $v0, 3($s1)
.Ljp7F0471FC:
  lwc1  $f8, 8($s2)
  lwc1  $f10, 0x58($s1)
  lwc1  $f6, 0xc($s2)
  lwc1  $f4, 0x5c($s1)
  sub.s $f0, $f8, $f10
  li    $at, 0x41A00000 # 20.000000
  mtc1  $at, $f10
  sub.s $f8, $f6, $f4
  sub.s $f6, $f8, $f10
  mul.s $f10, $f0, $f0
  swc1  $f6, 0x4c4($sp)
  lwc1  $f8, 0x60($s1)
  lwc1  $f4, 0x10($s2)
  swc1  $f0, 0x4c8($sp)
  sub.s $f2, $f4, $f8
  mul.s $f6, $f2, $f2
  swc1  $f2, 0x4c0($sp)
  add.s $f20, $f10, $f6
  swc1  $f20, 0x4bc($sp)
  jal   sqrtf
   mov.s $f12, $f20
  swc1  $f0, 0x4b4($sp)
  lw    $t6, 8($s1)
  mov.s $f2, $f0
  sll   $t2, $t6, 4
  bgezl $t2, .Ljp7F047284
   lwc1  $f12, 0x4bc($sp)
  lwc1  $f0, 0x4c4($sp)
  mul.s $f4, $f0, $f0
  add.s $f12, $f20, $f4
  jal   sqrtf
   swc1  $f12, 0x4bc($sp)
  mov.s $f2, $f0
  lwc1  $f12, 0x4bc($sp)
.Ljp7F047284:
  jal   sub_GAME_7F02D244
   swc1  $f2, 0x4b8($sp)
  swc1  $f0, 0x4a4($sp)
  lwc1  $f8, 0x98($s0)
  lwc1  $f16, 0x84($s0)
  lwc1  $f2, 0x4b8($sp)
  swc1  $f8, 0x4d8($sp)
  lwc1  $f10, 0xa8($s0)
  c.le.s $f2, $f10
  nop   
  bc1fl .Ljp7F047508
   lw    $t0, 0x4b0($sp)
  lwc1  $f12, 0x4c8($sp)
  lwc1  $f14, 0x4c0($sp)
  jal   convert_angle_using_inverse
   swc1  $f16, 0x4dc($sp)
  swc1  $f0, 0x4a0($sp)
  lwc1  $f12, 0x4c4($sp)
  jal   convert_angle_using_inverse
   lwc1  $f14, 0x4b4($sp)
  swc1  $f0, 0x49c($sp)
  lw    $v0, 8($s1)
  lwc1  $f16, 0x4dc($sp)
  li    $t9, 1
  sll   $t7, $v0, 1
  bltz  $t7, .Ljp7F0472F8
   sll   $t5, $v0, 2
  bgez  $t5, .Ljp7F047308
   lwc1  $f6, 0x4a0($sp)
.Ljp7F0472F8:
  lui   $at, %hi(D_80052B00) # $at, 0x8005
  lwc1  $f20, %lo(D_80052B00)($at)
  b     .Ljp7F0473A0
   sw    $t9, 0x4b0($sp)
.Ljp7F047308:
  lwc1  $f4, 0x90($s0)
  lui   $at, %hi(D_80052B04) # $at, 0x8005
  sub.s $f12, $f6, $f4
  c.lt.s $f12, $f22
  nop   
  bc1f  .Ljp7F04732C
   nop   
  lwc1  $f20, %lo(D_80052B04)($at)
  add.s $f12, $f12, $f20
.Ljp7F04732C:
  lui   $at, %hi(D_80052B08) # $at, 0x8005
  lwc1  $f20, %lo(D_80052B08)($at)
  lui   $at, %hi(D_80052B0C) # $at, 0x8005
  lwc1  $f8, %lo(D_80052B0C)($at)
  lui   $at, %hi(D_80052B10) # $at, 0x8005
  c.lt.s $f8, $f12
  nop   
  bc1fl .Ljp7F047358
   lwc1  $f10, 0x9c($s0)
  sub.s $f12, $f12, $f20
  lwc1  $f10, 0x9c($s0)
.Ljp7F047358:
  sub.s $f2, $f0, $f10
  c.lt.s $f2, $f22
  nop   
  bc1f  .Ljp7F04736C
   nop   
.Ljp7F04736C:
  lwc1  $f6, %lo(D_80052B10)($at)
  lui   $at, %hi(D_80052B14) # $at, 0x8005
  c.lt.s $f12, $f6
  nop   
  bc1fl .Ljp7F0473A4
   lw    $t0, 0x4b0($sp)
  lwc1  $f4, %lo(D_80052B14)($at)
  li    $t8, 1
  c.lt.s $f4, $f12
  nop   
  bc1fl .Ljp7F0473A4
   lw    $t0, 0x4b0($sp)
  sw    $t8, 0x4b0($sp)
.Ljp7F0473A0:
  lw    $t0, 0x4b0($sp)
.Ljp7F0473A4:
  lwc1  $f8, 0x4a0($sp)
  move  $a0, $s2
  beqz  $t0, .Ljp7F047504
   move  $a1, $zero
  lwc1  $f10, 0x84($s0)
  lui   $at, %hi(D_80052B18) # $at, 0x8005
  lwc1  $f6, %lo(D_80052B18)($at)
  sub.s $f0, $f8, $f10
  lw    $t1, 0x14($s3)
  lui   $at, %hi(D_80052B1C) # $at, 0x8005
  c.lt.s $f0, $f6
  sw    $t1, 0x494($sp)
  bc1f  .Ljp7F0473E4
   nop   
  b     .Ljp7F0473FC
   add.s $f0, $f0, $f20
.Ljp7F0473E4:
  lwc1  $f4, %lo(D_80052B1C)($at)
  c.le.s $f4, $f0
  nop   
  bc1fl .Ljp7F047400
   swc1  $f0, 0x498($sp)
  sub.s $f0, $f0, $f20
.Ljp7F0473FC:
  swc1  $f0, 0x498($sp)
.Ljp7F047400:
  jal   sub_GAME_7F08A03C
   swc1  $f16, 0x4dc($sp)
  lwc1  $f0, 0x498($sp)
  lwc1  $f8, 0x88($s0)
  lwc1  $f16, 0x4dc($sp)
  c.le.s $f0, $f8
  nop   
  bc1fl .Ljp7F0474BC
   lw    $v0, 0xb8($s0)
  lwc1  $f10, 0x8c($s0)
  li    $t3, 27
  c.le.s $f10, $f0
  nop   
  bc1fl .Ljp7F0474BC
   lw    $v0, 0xb8($s0)
  lwc1  $f6, 0x10($s2)
  lw    $a1, 8($s3)
  lw    $a2, 0x10($s3)
  lw    $a3, 8($s2)
  sw    $t3, 0x14($sp)
  swc1  $f6, 0x10($sp)
  lwc1  $f0, 0xc($s3)
  addiu $a0, $sp, 0x494
  swc1  $f0, 0x18($sp)
  swc1  $f0, 0x1c($sp)
  lwc1  $f2, 0xc($s2)
  swc1  $f16, 0x4dc($sp)
  swc1  $f2, 0x20($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f2, 0x24($sp)
  beqz  $v0, .Ljp7F0474B8
   lwc1  $f16, 0x4dc($sp)
  lw    $t4, 0x494($sp)
  lw    $t6, 0x14($s2)
  bnel  $t4, $t6, .Ljp7F0474BC
   lw    $v0, 0xb8($s0)
  lw    $t2, 8($s1)
  lui   $at, 0x2000
  li    $t5, 1
  or    $t7, $t2, $at
  sw    $t7, 8($s1)
  lwc1  $f4, 0x49c($sp)
  sw    $t5, 0x4a8($sp)
  lwc1  $f16, 0x4a0($sp)
  b     .Ljp7F0474F0
   swc1  $f4, 0x4d8($sp)
.Ljp7F0474B8:
  lw    $v0, 0xb8($s0)
.Ljp7F0474BC:
  lui   $t9, %hi(global_timer) # $t9, 0x8005
  bltzl $v0, .Ljp7F0474F0
   sw    $zero, 0x4b0($sp)
  lw    $t9, %lo(global_timer)($t9)
  addiu $t8, $t9, -0x78
  slt   $at, $t8, $v0
  beql  $at, $zero, .Ljp7F0474F0
   sw    $zero, 0x4b0($sp)
  lwc1  $f8, 0x9c($s0)
  lwc1  $f16, 0x90($s0)
  b     .Ljp7F0474F0
   swc1  $f8, 0x4d8($sp)
  sw    $zero, 0x4b0($sp)
.Ljp7F0474F0:
  move  $a0, $s2
  li    $a1, 1
  jal   sub_GAME_7F08A03C
   swc1  $f16, 0x4dc($sp)
  lwc1  $f16, 0x4dc($sp)
.Ljp7F047504:
  lw    $t0, 0x4b0($sp)
.Ljp7F047508:
  lui   $at, %hi(D_80052B20) # $at, 0x8005
  lwc1  $f20, %lo(D_80052B20)($at)
  beql  $t0, $zero, .Ljp7F047530
   lw    $t1, 0xd0($s0)
  lwc1  $f12, 0x4bc($sp)
  jal   sub_GAME_7F02D244
   swc1  $f16, 0x4dc($sp)
  lwc1  $f16, 0x4dc($sp)
  swc1  $f0, 0x4a4($sp)
  lw    $t1, 0xd0($s0)
.Ljp7F047530:
  beqz  $t1, .Ljp7F0475B0
   lui   $t3, %hi(global_timer) # $t3, 0x8005
  lw    $t3, %lo(global_timer)($t3)
  li    $at, 120
  swc1  $f16, 0x4dc($sp)
  div   $zero, $t3, $at
  mfhi  $t4
  mtc1  $t4, $f10
  li    $at, 0x42F00000 # 120.000000
  mtc1  $at, $f8
  cvt.s.w $f6, $f10
  mul.s $f4, $f6, $f20
  jal   sinf
   div.s $f12, $f4, $f8
  lui   $at, %hi(D_80052B24) # $at, 0x8005
  lwc1  $f6, %lo(D_80052B24)($at)
  lwc1  $f10, 0x4a4($sp)
  lwc1  $f16, 0x4dc($sp)
  mul.s $f4, $f10, $f6
  nop   
  mul.s $f8, $f4, $f0
  add.s $f16, $f16, $f8
  c.lt.s $f16, $f22
  nop   
  bc1f  .Ljp7F04759C
   nop   
  add.s $f16, $f16, $f20
.Ljp7F04759C:
  c.le.s $f20, $f16
  nop   
  bc1fl .Ljp7F0475B4
   lwc1  $f2, 0x84($s0)
  sub.s $f16, $f16, $f20
.Ljp7F0475B0:
  lwc1  $f2, 0x84($s0)
.Ljp7F0475B4:
  lui   $at, %hi(D_80052B28) # $at, 0x8005
  lwc1  $f10, %lo(D_80052B28)($at)
  sub.s $f0, $f16, $f2
  addiu $a0, $s0, 0x90
  c.lt.s $f0, $f10
  nop   
  bc1f  .Ljp7F0475DC
   nop   
  b     .Ljp7F0475F8
   add.s $f0, $f0, $f20
.Ljp7F0475DC:
  lui   $at, %hi(D_80052B2C) # $at, 0x8005
  lwc1  $f6, %lo(D_80052B2C)($at)
  c.le.s $f6, $f0
  nop   
  bc1fl .Ljp7F0475FC
   lwc1  $f12, 0x88($s0)
  sub.s $f0, $f0, $f20
.Ljp7F0475F8:
  lwc1  $f12, 0x88($s0)
.Ljp7F0475FC:
  lui   $at, %hi(D_80052B30) # $at, 0x8005
  c.lt.s $f12, $f0
  nop   
  bc1fl .Ljp7F04761C
   lwc1  $f12, 0x8c($s0)
  b     .Ljp7F047630
   add.s $f16, $f2, $f12
  lwc1  $f12, 0x8c($s0)
.Ljp7F04761C:
  c.lt.s $f0, $f12
  nop   
  bc1fl .Ljp7F047634
   c.lt.s $f16, $f22
  add.s $f16, $f2, $f12
.Ljp7F047630:
  c.lt.s $f16, $f22
.Ljp7F047634:
  nop   
  bc1fl .Ljp7F047648
   c.le.s $f20, $f16
  add.s $f16, $f16, $f20
  c.le.s $f20, $f16
.Ljp7F047648:
  nop   
  bc1f  .Ljp7F047658
   nop   
  sub.s $f16, $f16, $f20
.Ljp7F047658:
  lwc1  $f0, %lo(D_80052B30)($at)
  mfc1  $a1, $f16
  addiu $a2, $s0, 0x94
  swc1  $f0, 0x10($sp)
  lwc1  $f4, 0xa4($s0)
  mfc1  $a3, $f0
  swc1  $f16, 0x4dc($sp)
  jal   sub_GAME_7F04310C
   swc1  $f4, 0x14($sp)
  lui   $at, %hi(D_80052B34) # $at, 0x8005
  lwc1  $f0, %lo(D_80052B34)($at)
  addiu $a0, $s0, 0x9c
  lw    $a1, 0x4d8($sp)
  swc1  $f0, 0x10($sp)
  lwc1  $f8, 0xa4($s0)
  mfc1  $a3, $f0
  addiu $a2, $s0, 0xa0
  jal   sub_GAME_7F04310C
   swc1  $f8, 0x14($sp)
  lwc1  $f16, 0x4dc($sp)
  lwc1  $f10, 0x90($s0)
  lui   $at, %hi(D_80052B38) # $at, 0x8005
  lwc1  $f6, 0x4d8($sp)
  sub.s $f12, $f16, $f10
  c.lt.s $f12, $f22
  nop   
  bc1f  .Ljp7F0476CC
   nop   
  add.s $f12, $f12, $f20
.Ljp7F0476CC:
  lwc1  $f0, %lo(D_80052B38)($at)
  c.lt.s $f0, $f12
  nop   
  bc1fl .Ljp7F0476E8
   lwc1  $f4, 0x9c($s0)
  sub.s $f12, $f12, $f20
  lwc1  $f4, 0x9c($s0)
.Ljp7F0476E8:
  sub.s $f2, $f6, $f4
  c.lt.s $f2, $f22
  nop   
  bc1fl .Ljp7F047704
   c.lt.s $f0, $f2
  add.s $f2, $f2, $f20
  c.lt.s $f0, $f2
.Ljp7F047704:
  nop   
  bc1fl .Ljp7F047718
   sw    $zero, 0xd0($s0)
  sub.s $f2, $f2, $f20
  sw    $zero, 0xd0($s0)
.Ljp7F047718:
  lw    $t6, 0x4b0($sp)
  lwc1  $f8, 0x4a4($sp)
  beql  $t6, $zero, .Ljp7F047840
   lw    $t9, 0x4ac($sp)
  c.lt.s $f12, $f8
  lwc1  $f10, 0x4a4($sp)
  bc1fl .Ljp7F0477A0
   add.s $f0, $f10, $f10
  neg.s $f0, $f8
  c.lt.s $f0, $f12
  nop   
  bc1fl .Ljp7F0477A0
   add.s $f0, $f10, $f10
  c.lt.s $f2, $f8
  nop   
  bc1fl .Ljp7F0477A0
   add.s $f0, $f10, $f10
  c.lt.s $f0, $f2
  li    $t2, 1
  bc1fl .Ljp7F0477A0
   add.s $f0, $f10, $f10
  sw    $t2, 0xd0($s0)
  lw    $t5, 0x4a8($sp)
  li    $t7, 1
  sw    $t7, 0x4ac($sp)
  beqz  $t5, .Ljp7F04783C
   lui   $t9, %hi(global_timer) # $t9, 0x8005
  lw    $t9, %lo(global_timer)($t9)
  lui   $t8, %hi(global_timer) # $t8, 0x8005
  sw    $t9, 0xb8($s0)
  lw    $t8, %lo(global_timer)($t8)
  b     .Ljp7F04783C
   sw    $t8, 0xbc($s0)
  add.s $f0, $f10, $f10
.Ljp7F0477A0:
  c.lt.s $f12, $f0
  nop   
  bc1fl .Ljp7F04780C
   lw    $v0, 0xb8($s0)
  neg.s $f14, $f0
  c.lt.s $f14, $f12
  nop   
  bc1fl .Ljp7F04780C
   lw    $v0, 0xb8($s0)
  c.lt.s $f2, $f0
  nop   
  bc1fl .Ljp7F04780C
   lw    $v0, 0xb8($s0)
  c.lt.s $f14, $f2
  li    $t0, 1
  bc1fl .Ljp7F04780C
   lw    $v0, 0xb8($s0)
  sw    $t0, 0xd0($s0)
  lw    $t3, 0x4a8($sp)
  li    $t1, 1
  sw    $t1, 0x4ac($sp)
  beqz  $t3, .Ljp7F04783C
   lui   $t4, %hi(global_timer) # $t4, 0x8005
  lw    $t4, %lo(global_timer)($t4)
  b     .Ljp7F04783C
   sw    $t4, 0xb8($s0)
  lw    $v0, 0xb8($s0)
.Ljp7F04780C:
  lui   $t6, %hi(global_timer) # $t6, 0x8005
  bltzl $v0, .Ljp7F047840
   lw    $t9, 0x4ac($sp)
  lw    $t6, %lo(global_timer)($t6)
  li    $t7, 1
  li    $t5, 1
  addiu $t2, $t6, -0x78
  slt   $at, $t2, $v0
  beql  $at, $zero, .Ljp7F047840
   lw    $t9, 0x4ac($sp)
  sw    $t7, 0xd0($s0)
  sw    $t5, 0x4ac($sp)
.Ljp7F04783C:
  lw    $t9, 0x4ac($sp)
.Ljp7F047840:
  lui   $at, %hi(D_80052B3C) # $at, 0x8005
  beql  $t9, $zero, .Ljp7F047894
   lwc1  $f2, 0xb0($s0)
  lwc1  $f0, %lo(D_80052B3C)($at)
  lui   $at, %hi(D_80052B40) # $at, 0x8005
  lwc1  $f6, %lo(D_80052B40)($at)
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  lwc1  $f4, %lo(global_timer_delta)($at)
  lwc1  $f10, 0xb0($s0)
  mul.s $f8, $f6, $f4
  add.s $f6, $f10, $f8
  swc1  $f6, 0xb0($s0)
  lwc1  $f2, 0xb0($s0)
  c.lt.s $f0, $f2
  nop   
  bc1fl .Ljp7F04790C
   c.lt.s $f22, $f2
  swc1  $f0, 0xb0($s0)
  b     .Ljp7F047908
   lwc1  $f2, 0xb0($s0)
  lwc1  $f2, 0xb0($s0)
.Ljp7F047894:
  lui   $t8, %hi(clock_timer) # $t8, 0x8005
  c.lt.s $f22, $f2
  nop   
  bc1fl .Ljp7F04790C
   c.lt.s $f22, $f2
  lw    $t8, %lo(clock_timer)($t8)
  move  $v0, $zero
  lui   $at, %hi(D_80052B44) # $at, 0x8005
  blez  $t8, .Ljp7F0478E8
   nop   
  lwc1  $f0, %lo(D_80052B44)($at)
  lwc1  $f4, 0xb0($s0)
.Ljp7F0478C4:
  lui   $t0, %hi(clock_timer) # $t0, 0x8005
  addiu $v0, $v0, 1
  mul.s $f10, $f4, $f0
  swc1  $f10, 0xb0($s0)
  lw    $t0, %lo(clock_timer)($t0)
  slt   $at, $v0, $t0
  bnezl $at, .Ljp7F0478C4
   lwc1  $f4, 0xb0($s0)
  lwc1  $f2, 0xb0($s0)
.Ljp7F0478E8:
  lui   $at, %hi(D_80052B48) # $at, 0x8005
  lwc1  $f8, %lo(D_80052B48)($at)
  c.le.s $f2, $f8
  nop   
  bc1fl .Ljp7F04790C
   c.lt.s $f22, $f2
  swc1  $f22, 0xb0($s0)
  lwc1  $f2, 0xb0($s0)
.Ljp7F047908:
  c.lt.s $f22, $f2
.Ljp7F04790C:
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  bc1fl .Ljp7F048634
   lbu   $v0, 3($s1)
  lwc1  $f4, %lo(global_timer_delta)($at)
  lwc1  $f6, 0xb4($s0)
  mul.s $f10, $f2, $f4
  add.s $f8, $f6, $f10
  swc1  $f8, 0xb4($s0)
  lwc1  $f0, 0xb4($s0)
  c.le.s $f20, $f0
  nop   
  bc1fl .Ljp7F048634
   lbu   $v0, 3($s1)
  sub.s $f4, $f0, $f20
.Ljp7F047944:
  swc1  $f4, 0xb4($s0)
  lwc1  $f0, 0xb4($s0)
  c.le.s $f20, $f0
  nop   
  bc1tl .Ljp7F047944
   sub.s $f4, $f0, $f20
  b     .Ljp7F048634
   lbu   $v0, 3($s1)
  li    $at, 39
.Ljp7F047968:
  bne   $v0, $at, .Ljp7F0482C0
   move  $a0, $s1
  lwc1  $f6, 0xa0($s1)
  sw    $zero, 0x47c($sp)
  li    $a1, 1
  jal   parse_handle_actionblocks
   swc1  $f6, 0x480($sp)
  lwc1  $f14, 0x98($s1)
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  c.le.s $f22, $f14
  nop   
  bc1fl .Ljp7F0479F0
   lw    $t1, 0xc($s1)
  lwc1  $f2, %lo(global_timer_delta)($at)
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  c.le.s $f14, $f2
  nop   
  bc1fl .Ljp7F0479C8
   lwc1  $f0, 0x88($s1)
  lwc1  $f10, 0x94($s1)
  lwc1  $f14, 0x98($s1)
  b     .Ljp7F0479E0
   swc1  $f10, 0x88($s1)
  lwc1  $f0, 0x88($s1)
.Ljp7F0479C8:
  lwc1  $f8, 0x94($s1)
  sub.s $f4, $f8, $f0
  mul.s $f6, $f4, $f2
  div.s $f10, $f6, $f14
  add.s $f8, $f0, $f10
  swc1  $f8, 0x88($s1)
.Ljp7F0479E0:
  lwc1  $f4, %lo(global_timer_delta)($at)
  sub.s $f6, $f14, $f4
  swc1  $f6, 0x98($s1)
  lw    $t1, 0xc($s1)
.Ljp7F0479F0:
  move  $s0, $zero
  sll   $t3, $t1, 0xc
  bltz  $t3, .Ljp7F047A4C
   nop   
  jal   check_if_object_has_not_been_destroyed
   move  $a0, $s1
  beqz  $v0, .Ljp7F047A4C
   nop   
  lwc1  $f10, 0x88($s1)
  addiu $a0, $s1, 0x58
  lui   $a1, 0x44fa
  c.lt.s $f22, $f10
  lui   $a2, (0x453B8000 >> 16) # lui $a2, 0x453b
  bc1t  .Ljp7F047A40
   nop   
  lwc1  $f8, 0x94($s1)
  c.lt.s $f22, $f8
  nop   
  bc1f  .Ljp7F047A4C
   nop   
.Ljp7F047A40:
  jal   sub_GAME_7F053894
   ori   $a2, (0x453B8000 & 0xFFFF) # ori $a2, $a2, 0x8000
  move  $s0, $v0
.Ljp7F047A4C:
  blezl $s0, .Ljp7F047AB4
   lw    $a0, 0xac($s1)
  lw    $a0, 0xac($s1)
  beqz  $a0, .Ljp7F047A70
   nop   
  jal   sfxGetArg0Unk3F
   nop   
  bnezl $v0, .Ljp7F047A94
   lw    $a0, 0xac($s1)
.Ljp7F047A70:
  jal   get_controls_locked_flag
   nop   
  bnez  $v0, .Ljp7F047A90
   lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 65
  jal   play_sfx_a1
   addiu $a2, $s1, 0xac
.Ljp7F047A90:
  lw    $a0, 0xac($s1)
.Ljp7F047A94:
  li    $a1, 8
  beql  $a0, $zero, .Ljp7F047AD8
   lw    $a0, 0xa4($s1)
  jal   sfx_c_70009184
   move  $a2, $s0
  b     .Ljp7F047AD8
   lw    $a0, 0xa4($s1)
  lw    $a0, 0xac($s1)
.Ljp7F047AB4:
  beql  $a0, $zero, .Ljp7F047AD8
   lw    $a0, 0xa4($s1)
  jal   sfxGetArg0Unk3F
   nop   
  beql  $v0, $zero, .Ljp7F047AD8
   lw    $a0, 0xa4($s1)
  jal   sfxDeactivate
   lw    $a0, 0xac($s1)
  lw    $a0, 0xa4($s1)
.Ljp7F047AD8:
  lui   $a1, %hi(ptr_setup_path_tbl) # $a1, 0x8007
  beql  $a0, $zero, .Ljp7F047B88
   lw    $t7, 8($s1)
  lw    $t6, 0xa8($s1)
  lw    $t4, ($a0)
  addiu $a1, %lo(ptr_setup_path_tbl) # addiu $a1, $a1, 0x5d40
  sll   $t2, $t6, 2
  addu  $v0, $t4, $t2
  lw    $t7, ($v0)
  lw    $t9, ($a1)
  lw    $t1, 0x18($a1)
  sll   $t5, $t7, 4
  addu  $v1, $t5, $t9
  lw    $t8, ($v1)
  lwc1  $f6, 0x58($s1)
  lwc1  $f8, 0x60($s1)
  sll   $t0, $t8, 2
  subu  $t0, $t0, $t8
  sll   $t0, $t0, 2
  subu  $t0, $t0, $t8
  sll   $t0, $t0, 2
  addu  $a2, $t0, $t1
  lwc1  $f4, ($a2)
  lwc1  $f10, 8($a2)
  sw    $a2, 0x47c($sp)
  sub.s $f12, $f4, $f6
  jal   convert_angle_using_inverse
   sub.s $f14, $f10, $f8
  swc1  $f0, 0x480($sp)
  lw    $t3, 8($s1)
  lui   $at, (0xDFFFFFFF >> 16) # lui $at, 0xdfff
  lwc1  $f4, 0x480($sp)
  sll   $t6, $t3, 2
  bgez  $t6, .Ljp7F047BC0
   ori   $at, (0xDFFFFFFF & 0xFFFF) # ori $at, $at, 0xffff
  lw    $t4, 8($s1)
  swc1  $f4, 0xa0($s1)
  move  $a0, $s1
  and   $t2, $t4, $at
  jal   sub_GAME_7F044B38
   sw    $t2, 8($s1)
  b     .Ljp7F047BC4
   lwc1  $f6, 0x88($s1)
  lw    $t7, 8($s1)
.Ljp7F047B88:
  sll   $t5, $t7, 2
  bgezl $t5, .Ljp7F047BC4
   lwc1  $f6, 0x88($s1)
  lwc1  $f12, 0x38($s1)
  jal   convert_angle_using_inverse
   lwc1  $f14, 0x40($s1)
  lw    $t9, 8($s1)
  lui   $at, (0xDFFFFFFF >> 16) # lui $at, 0xdfff
  ori   $at, (0xDFFFFFFF & 0xFFFF) # ori $at, $at, 0xffff
  and   $t8, $t9, $at
  swc1  $f0, 0xa0($s1)
  sw    $t8, 8($s1)
  jal   sub_GAME_7F044B38
   move  $a0, $s1
.Ljp7F047BC0:
  lwc1  $f6, 0x88($s1)
.Ljp7F047BC4:
  c.lt.s $f22, $f6
  nop   
  bc1fl .Ljp7F048280
   lw    $t2, 8($s1)
  lw    $t0, 0x14($s3)
  lw    $t1, 0x47c($sp)
  mov.s $f14, $f22
  sw    $t0, 0x46c($sp)
  lwc1  $f12, 0xa0($s1)
  swc1  $f12, 0x43c($sp)
  lwc1  $f10, 0x9c($s1)
  beqz  $t1, .Ljp7F047C40
   swc1  $f10, 0x438($sp)
  addiu $t3, $s1, 0x58
  sw    $t3, 0x74($sp)
  jal   sinf
   swc1  $f14, 0x434($sp)
  swc1  $f0, 0x440($sp)
  swc1  $f22, 0x444($sp)
  jal   cosf
   lwc1  $f12, 0xa0($s1)
  swc1  $f0, 0x448($sp)
  lw    $a0, 0x74($sp)
  addiu $a1, $sp, 0x440
  lw    $a2, 0x47c($sp)
  jal   sub_GAME_7F02FC34
   lui   $a3, 0x4120
  beqz  $v0, .Ljp7F047C40
   lwc1  $f14, 0x434($sp)
  lwc1  $f8, 0xa0($s1)
  swc1  $f8, 0x480($sp)
.Ljp7F047C40:
  lui   $at, %hi(D_80052B4C) # $at, 0x8005
  lwc1  $f4, %lo(D_80052B4C)($at)
  lui   $at, %hi(D_80052B50) # $at, 0x8005
  lwc1  $f6, %lo(D_80052B50)($at)
  lui   $a3, (0x38E4C389 >> 16) # lui $a3, 0x38e4
  ori   $a3, (0x38E4C389 & 0xFFFF) # ori $a3, $a3, 0xc389
  addiu $a0, $s1, 0xa0
  lw    $a1, 0x480($sp)
  addiu $a2, $s1, 0x9c
  swc1  $f14, 0x434($sp)
  swc1  $f4, 0x10($sp)
  jal   sub_GAME_7F04310C
   swc1  $f6, 0x14($sp)
  lui   $at, %hi(D_80052B54) # $at, 0x8005
  lwc1  $f20, %lo(D_80052B54)($at)
  lwc1  $f12, 0xa0($s1)
  lwc1  $f14, 0x434($sp)
  lui   $at, %hi(D_80052B58) # $at, 0x8005
  c.le.s $f20, $f12
  nop   
  bc1fl .Ljp7F047CB8
   c.lt.s $f12, $f22
  sub.s $f10, $f12, $f20
.Ljp7F047C9C:
  swc1  $f10, 0xa0($s1)
  lwc1  $f12, 0xa0($s1)
  c.le.s $f20, $f12
  nop   
  bc1tl .Ljp7F047C9C
   sub.s $f10, $f12, $f20
  c.lt.s $f12, $f22
.Ljp7F047CB8:
  nop   
  bc1fl .Ljp7F047CE4
   lwc1  $f4, 0x480($sp)
  add.s $f8, $f12, $f20
.Ljp7F047CC8:
  swc1  $f8, 0xa0($s1)
  lwc1  $f12, 0xa0($s1)
  c.lt.s $f12, $f22
  nop   
  bc1tl .Ljp7F047CC8
   add.s $f8, $f12, $f20
  lwc1  $f4, 0x480($sp)
.Ljp7F047CE4:
  c.eq.s $f4, $f12
  nop   
  bc1fl .Ljp7F047D2C
   lw    $t6, 8($s4)
  lwc1  $f0, 0x9c($s1)
  lwc1  $f6, %lo(D_80052B58)($at)
  lui   $at, %hi(D_80052B5C) # $at, 0x8005
  c.le.s $f0, $f6
  nop   
  bc1fl .Ljp7F047D2C
   lw    $t6, 8($s4)
  lwc1  $f10, %lo(D_80052B5C)($at)
  c.le.s $f10, $f0
  nop   
  bc1fl .Ljp7F047D2C
   lw    $t6, 8($s4)
  swc1  $f22, 0x9c($s1)
  lw    $t6, 8($s4)
.Ljp7F047D2C:
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  lwc1  $f2, %lo(global_timer_delta)($at)
  lw    $t4, 8($t6)
  lwc1  $f4, 0x43c($sp)
  c.lt.s $f22, $f2
  lw    $t2, 0xc($t4)
  bc1f  .Ljp7F047D58
   lw    $s0, 4($t2)
  lwc1  $f8, 0xa0($s1)
  sub.s $f6, $f8, $f4
  div.s $f14, $f6, $f2
.Ljp7F047D58:
  c.lt.s $f14, $f22
  nop   
  bc1f  .Ljp7F047D6C
   nop   
  add.s $f14, $f14, $f20
.Ljp7F047D6C:
  jal   sinf
   mov.s $f12, $f14
  lwc1  $f10, 8($s0)
  lwc1  $f8, 0x14($s4)
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  mul.s $f4, $f10, $f8
  lwc1  $f10, %lo(global_timer_delta)($at)
  mul.s $f6, $f0, $f4
  nop   
  mul.s $f8, $f6, $f10
  swc1  $f8, 0x464($sp)
  jal   sinf
   lwc1  $f12, 0xa0($s1)
  swc1  $f0, 0x440($sp)
  swc1  $f22, 0x444($sp)
  jal   cosf
   lwc1  $f12, 0xa0($s1)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f14
  swc1  $f0, 0x448($sp)
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  lwc1  $f2, %lo(global_timer_delta)($at)
  lwc1  $f4, 0x88($s1)
  lwc1  $f10, 0x440($sp)
  lwc1  $f12, 0x464($sp)
  mul.s $f6, $f4, $f2
  lwc1  $f4, 0x58($s1)
  addiu $s0, $sp, 0x46c
  li    $t7, 31
  move  $a0, $s0
  mul.s $f8, $f6, $f10
  add.s $f6, $f4, $f8
  lwc1  $f4, 0x448($sp)
  mul.s $f8, $f4, $f12
  sub.s $f6, $f6, $f8
  swc1  $f6, 0x69c($sp)
  lwc1  $f8, 0x5c($s1)
  mfc1  $a3, $f6
  swc1  $f8, 0x6a0($sp)
  lwc1  $f8, 0x88($s1)
  mul.s $f8, $f8, $f2
  nop   
  mul.s $f8, $f8, $f4
  lwc1  $f4, 0x60($s1)
  add.s $f4, $f4, $f8
  mul.s $f8, $f10, $f12
  add.s $f10, $f8, $f4
  swc1  $f10, 0x6a4($sp)
  lw    $a2, 0x10($s3)
  lw    $a1, 8($s3)
  swc1  $f22, 0x20($sp)
  swc1  $f22, 0x18($sp)
  sw    $t7, 0x14($sp)
  swc1  $f10, 0x10($sp)
  swc1  $f14, 0x24($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f14, 0x1c($sp)
  beqz  $v0, .Ljp7F04823C
   move  $a0, $s0
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  li    $t5, 31
  sw    $t5, 0x10($sp)
  lw    $a1, 0x69c($sp)
  lw    $a2, 0x6a4($sp)
  lui   $a3, 0x4120
  swc1  $f22, 0x14($sp)
  jal   sub_GAME_7F0B18B8
   swc1  $f8, 0x18($sp)
  bgezl $v0, .Ljp7F048240
   lwc1  $f6, 0x98($s1)
  lw    $t9, 0x14($s3)
  lw    $t8, 0x46c($sp)
  move  $a0, $s1
  sw    $t9, 0x450($sp)
  lwc1  $f4, 8($s3)
  swc1  $f4, 0x454($sp)
  lwc1  $f6, 0xc($s3)
  swc1  $f6, 0x458($sp)
  lwc1  $f10, 0x10($s3)
  swc1  $f10, 0x45c($sp)
  sw    $t8, 0x14($s3)
  lwc1  $f2, 0x69c($sp)
  swc1  $f2, 8($s3)
  swc1  $f2, 0x58($s1)
  lwc1  $f2, 0x6a4($sp)
  swc1  $f2, 0x10($s3)
  jal   sub_GAME_7F040484
   swc1  $f2, 0x60($s1)
  jal   sub_GAME_7F056CA0
   move  $a0, $s1
  jal   sub_GAME_7F0448A8
   move  $a0, $s3
  beqz  $v0, .Ljp7F04812C
   move  $s2, $v0
  lw    $t0, 8($s4)
  lwc1  $f8, 0x18($s1)
  move  $a0, $s0
  lw    $t1, 8($t0)
  lw    $t3, 0x28($t1)
  lw    $v0, 4($t3)
  lwc1  $f4, 4($v0)
  mul.s $f6, $f8, $f4
  swc1  $f6, 0x428($sp)
  lwc1  $f10, 0x20($s1)
  lwc1  $f8, 4($v0)
  mul.s $f4, $f10, $f8
  swc1  $f4, 0x430($sp)
  lwc1  $f6, 0x18($s1)
  lwc1  $f10, 8($v0)
  mul.s $f8, $f6, $f10
  swc1  $f8, 0x41c($sp)
  lwc1  $f4, 0x20($s1)
  lwc1  $f6, 8($v0)
  mul.s $f10, $f4, $f6
  swc1  $f10, 0x424($sp)
  lwc1  $f8, 0x38($s1)
  lwc1  $f4, 0x14($v0)
  mul.s $f6, $f8, $f4
  swc1  $f6, 0x410($sp)
  lwc1  $f10, 0x40($s1)
  lwc1  $f8, 0x14($v0)
  mul.s $f4, $f10, $f8
  swc1  $f4, 0x418($sp)
  lwc1  $f6, 0x38($s1)
  lwc1  $f10, 0x18($v0)
  mul.s $f8, $f6, $f10
  swc1  $f8, 0x404($sp)
  lwc1  $f4, 0x40($s1)
  lwc1  $f6, 0x18($v0)
  lwc1  $f8, 0x410($sp)
  mul.s $f10, $f4, $f6
  lwc1  $f4, 0x428($sp)
  swc1  $f10, 0x40c($sp)
  lw    $t6, 0x14($s3)
  sw    $t6, 0x46c($sp)
  lwc1  $f0, 8($s3)
  lwc1  $f2, 0x10($s3)
  add.s $f6, $f0, $f4
  lwc1  $f4, 0x418($sp)
  mfc1  $a1, $f0
  mfc1  $a2, $f2
  add.s $f10, $f8, $f6
  lwc1  $f8, 0x430($sp)
  add.s $f6, $f2, $f8
  mfc1  $a3, $f10
  add.s $f10, $f4, $f6
  jal   sub_GAME_7F0B0BE4
   swc1  $f10, 0x10($sp)
  beqz  $v0, .Ljp7F048128
   lwc1  $f4, 0x428($sp)
  lwc1  $f0, 8($s3)
  lwc1  $f8, 0x410($sp)
  lwc1  $f2, 0x10($s3)
  add.s $f6, $f0, $f4
  lwc1  $f4, 0x418($sp)
  move  $a0, $s0
  add.s $f10, $f8, $f6
  lwc1  $f6, 0x430($sp)
  mfc1  $a1, $f10
  add.s $f10, $f2, $f6
  add.s $f6, $f4, $f10
  lwc1  $f10, 0x41c($sp)
  mfc1  $a2, $f6
  add.s $f6, $f0, $f10
  add.s $f10, $f8, $f6
  lwc1  $f8, 0x424($sp)
  add.s $f6, $f2, $f8
  mfc1  $a3, $f10
  add.s $f10, $f4, $f6
  jal   sub_GAME_7F0B0BE4
   swc1  $f10, 0x10($sp)
  beqz  $v0, .Ljp7F048128
   lwc1  $f4, 0x41c($sp)
  lwc1  $f8, 8($s3)
  lwc1  $f6, 0x410($sp)
  move  $a0, $s0
  add.s $f0, $f8, $f4
  lwc1  $f4, 0x424($sp)
  lwc1  $f8, 0x10($s3)
  add.s $f10, $f6, $f0
  lwc1  $f6, 0x418($sp)
  add.s $f2, $f8, $f4
  mfc1  $a1, $f10
  lwc1  $f8, 0x404($sp)
  add.s $f10, $f6, $f2
  lwc1  $f6, 0x40c($sp)
  add.s $f4, $f8, $f0
  mfc1  $a2, $f10
  add.s $f10, $f6, $f2
  mfc1  $a3, $f4
  jal   sub_GAME_7F0B0BE4
   swc1  $f10, 0x10($sp)
  beqz  $v0, .Ljp7F048128
   lwc1  $f4, 0x41c($sp)
  lwc1  $f0, 8($s3)
  lwc1  $f8, 0x404($sp)
  lwc1  $f2, 0x10($s3)
  add.s $f6, $f0, $f4
  lwc1  $f4, 0x40c($sp)
  move  $a0, $s0
  add.s $f10, $f8, $f6
  lwc1  $f6, 0x424($sp)
  mfc1  $a1, $f10
  add.s $f10, $f2, $f6
  add.s $f6, $f4, $f10
  lwc1  $f10, 0x428($sp)
  mfc1  $a2, $f6
  add.s $f6, $f0, $f10
  add.s $f10, $f8, $f6
  lwc1  $f8, 0x430($sp)
  add.s $f6, $f2, $f8
  mfc1  $a3, $f10
  add.s $f10, $f4, $f6
  jal   sub_GAME_7F0B0BE4
   swc1  $f10, 0x10($sp)
  beqz  $v0, .Ljp7F048128
   lwc1  $f4, 0x428($sp)
  lwc1  $f8, 8($s3)
  lwc1  $f6, 0x404($sp)
  move  $a0, $s0
  add.s $f0, $f8, $f4
  lwc1  $f4, 0x430($sp)
  lwc1  $f8, 0x10($s3)
  add.s $f10, $f6, $f0
  lwc1  $f6, 0x40c($sp)
  add.s $f2, $f8, $f4
  mfc1  $a1, $f10
  lwc1  $f8, 0x410($sp)
  add.s $f10, $f6, $f2
  lwc1  $f6, 0x418($sp)
  add.s $f4, $f8, $f0
  mfc1  $a2, $f10
  add.s $f10, $f6, $f2
  mfc1  $a3, $f4
  jal   sub_GAME_7F0B0BE4
   swc1  $f10, 0x10($sp)
  bnez  $v0, .Ljp7F04812C
   nop   
.Ljp7F048128:
  move  $s2, $zero
.Ljp7F04812C:
  beqz  $s2, .Ljp7F0481BC
   move  $a0, $s1
  addiu $t4, $s1, 0x58
  sw    $t4, 0x74($sp)
  jal   sub_GAME_7F044B38
   addiu $s0, $s1, 0x7c
  move  $a0, $s3
  jal   sub_GAME_7F0402B4
   move  $a1, $s0
  jal   detonate_proxmine_In_range
   lw    $a0, 0x74($sp)
  lw    $t2, 0x47c($sp)
  addiu $a0, $sp, 0x454
  addiu $a1, $sp, 0x69c
  beqz  $t2, .Ljp7F0482B8
   move  $a2, $t2
  jal   sub_GAME_7F02FD50
   lui   $a3, 0x42c8
  beqz  $v0, .Ljp7F0482B8
   nop   
  lw    $t7, 0xa8($s1)
  lw    $t9, 0xa4($s1)
  li    $at, 0x42700000 # 60.000000
  addiu $t5, $t7, 1
  sw    $t5, 0xa8($s1)
  lw    $t8, ($t9)
  sll   $t1, $t5, 2
  addu  $t3, $t8, $t1
  lw    $t6, ($t3)
  bgez  $t6, .Ljp7F0482B8
   nop   
  mtc1  $at, $f8
  sw    $zero, 0xa4($s1)
  swc1  $f22, 0x94($s1)
  b     .Ljp7F0482B8
   swc1  $f8, 0x98($s1)
.Ljp7F0481BC:
  lwc1  $f4, 0x98($s1)
  li    $at, 0x42700000 # 60.000000
  c.lt.s $f4, $f22
  nop   
  bc1fl .Ljp7F0481E8
   swc1  $f22, 0x88($s1)
  lwc1  $f6, 0x88($s1)
  mtc1  $at, $f10
  swc1  $f6, 0x94($s1)
  swc1  $f10, 0x98($s1)
  swc1  $f22, 0x88($s1)
.Ljp7F0481E8:
  lwc1  $f8, 0x43c($sp)
  move  $a0, $s1
  swc1  $f8, 0xa0($s1)
  lwc1  $f4, 0x438($sp)
  swc1  $f4, 0x9c($s1)
  lw    $t4, 0x450($sp)
  sw    $t4, 0x14($s3)
  lwc1  $f2, 0x454($sp)
  swc1  $f2, 8($s3)
  swc1  $f2, 0x58($s1)
  lwc1  $f2, 0x458($sp)
  swc1  $f2, 0xc($s3)
  swc1  $f2, 0x5c($s1)
  lwc1  $f2, 0x45c($sp)
  swc1  $f2, 0x10($s3)
  jal   sub_GAME_7F040484
   swc1  $f2, 0x60($s1)
  jal   sub_GAME_7F056CA0
   move  $a0, $s1
  b     .Ljp7F0482B8
   nop   
.Ljp7F04823C:
  lwc1  $f6, 0x98($s1)
.Ljp7F048240:
  li    $at, 0x42700000 # 60.000000
  c.lt.s $f6, $f22
  nop   
  bc1fl .Ljp7F048268
   swc1  $f22, 0x88($s1)
  lwc1  $f10, 0x88($s1)
  mtc1  $at, $f8
  swc1  $f10, 0x94($s1)
  swc1  $f8, 0x98($s1)
  swc1  $f22, 0x88($s1)
.Ljp7F048268:
  lwc1  $f4, 0x43c($sp)
  swc1  $f4, 0xa0($s1)
  lwc1  $f6, 0x438($sp)
  b     .Ljp7F0482B8
   swc1  $f6, 0x9c($s1)
  lw    $t2, 8($s1)
.Ljp7F048280:
  sll   $t7, $t2, 2
  bgez  $t7, .Ljp7F0482B8
   nop   
  lwc1  $f12, 0x38($s1)
  jal   convert_angle_using_inverse
   lwc1  $f14, 0x40($s1)
  lw    $t5, 8($s1)
  lui   $at, (0xDFFFFFFF >> 16) # lui $at, 0xdfff
  ori   $at, (0xDFFFFFFF & 0xFFFF) # ori $at, $at, 0xffff
  and   $t9, $t5, $at
  swc1  $f0, 0xa0($s1)
  sw    $t9, 8($s1)
  jal   sub_GAME_7F044B38
   move  $a0, $s1
.Ljp7F0482B8:
  b     .Ljp7F048634
   lbu   $v0, 3($s1)
.Ljp7F0482C0:
  li    $at, 40
  bne   $v0, $at, .Ljp7F048630
   move  $a0, $s1
  jal   parse_handle_actionblocks
   li    $a1, 1
  lw    $s0, 0x14($s1)
  addiu $a1, $s1, 0x58
  lw    $t0, 0x20($s0)
  move  $a0, $s0
  beql  $t0, $zero, .Ljp7F04847C
   lwc1  $f12, 0xa0($s1)
  jal   setsuboffset
   sw    $a1, 0x74($sp)
  lw    $s0, 0x14($s1)
  lui   $t1, %hi(animation_table_ptrs2+4) # $t1, 0x8003
  lw    $t1, %lo(animation_table_ptrs2+4)($t1)
  lw    $t8, 0x20($s0)
  lui   $a1, (0x4127020C >> 16) # lui $a1, 0x4127
  move  $a0, $s0
  bne   $t8, $t1, .Ljp7F048334
   nop   
  jal   sub_GAME_7F06CE84
   ori   $a1, (0x4127020C & 0xFFFF) # ori $a1, $a1, 0x20c
  lui   $a1, (0x40490FDB >> 16) # lui $a1, 0x4049
  ori   $a1, (0x40490FDB & 0xFFFF) # ori $a1, $a1, 0xfdb
  jal   setsubroty
   lw    $a0, 0x14($s1)
  b     .Ljp7F0483C0
   nop   
.Ljp7F048334:
  jal   get_stage_num
   nop   
  li    $at, 22
  bne   $v0, $at, .Ljp7F04836C
   lui   $a1, (0x3F859B3D >> 16) # lui $a1, 0x3f85
  lw    $a0, 0x14($s1)
  jal   sub_GAME_7F06CE84
   ori   $a1, (0x3F859B3D & 0xFFFF) # ori $a1, $a1, 0x9b3d
  lui   $a1, (0x4016CBE4 >> 16) # lui $a1, 0x4016
  ori   $a1, (0x4016CBE4 & 0xFFFF) # ori $a1, $a1, 0xcbe4
  jal   setsubroty
   lw    $a0, 0x14($s1)
  b     .Ljp7F0483C0
   nop   
.Ljp7F04836C:
  jal   get_stage_num
   nop   
  li    $at, 26
  bne   $v0, $at, .Ljp7F0483A8
   lui   $a1, 0x3f85
  lui   $a1, (0x3F859B3D >> 16) # lui $a1, 0x3f85
  ori   $a1, (0x3F859B3D & 0xFFFF) # ori $a1, $a1, 0x9b3d
  jal   sub_GAME_7F06CE84
   lw    $a0, 0x14($s1)
  lui   $a1, (0x407B9B3D >> 16) # lui $a1, 0x407b
  ori   $a1, (0x407B53D1 & 0xFFFF) # ori $a1, $a1, 0x53d1
  jal   setsubroty
   lw    $a0, 0x14($s1)
  b     .Ljp7F0483C0
   nop   
.Ljp7F0483A8:
  lw    $a0, 0x14($s1)
  jal   sub_GAME_7F06CE84
   ori   $a1, (0x407B9B3D & 0xFFFF) # ori $a1, $a1, 0x9b3d
  mfc1  $a1, $f22
  jal   setsubroty
   lw    $a0, 0x14($s1)
.Ljp7F0483C0:
  lui   $a1, %hi(clock_timer) # $a1, 0x8005
  lw    $a1, %lo(clock_timer)($a1)
  lw    $a0, 0x14($s1)
  jal   sub_GAME_7F070AEC
   li    $a2, 1
  jal   subcalcpos
   lw    $a0, 0x14($s1)
  lw    $a0, 0x14($s1)
  jal   getsuboffset
   lw    $a1, 0x74($sp)
  lwc1  $f10, 0x58($s1)
  lui   $a1, %hi(ptr_setup_path_tbl) # $a1, 0x8007
  addiu $a1, %lo(ptr_setup_path_tbl) # addiu $a1, $a1, 0x5d40
  swc1  $f10, 8($s3)
  lwc1  $f8, 0x60($s1)
  swc1  $f8, 0x10($s3)
  lh    $v0, 6($s1)
  slti  $at, $v0, 0x2710
  beqz  $at, .Ljp7F048438
   sll   $t4, $v0, 4
  sll   $t3, $v0, 2
  lui   $a1, %hi(ptr_setup_path_tbl) # $a1, 0x8007
  subu  $t3, $t3, $v0
  addiu $a1, %lo(ptr_setup_path_tbl) # addiu $a1, $a1, 0x5d40
  sll   $t3, $t3, 2
  lw    $t6, 0x18($a1)
  subu  $t3, $t3, $v0
  sll   $t3, $t3, 2
  b     .Ljp7F048454
   addu  $v1, $t3, $t6
.Ljp7F048438:
  lw    $t2, 0x1c($a1)
  addu  $t4, $t4, $v0
  sll   $t4, $t4, 2
  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
  addu  $v1, $t4, $t2
  addu  $v1, $v1, $at
.Ljp7F048454:
  lwc1  $f4, 0x5c($s1)
  lwc1  $f6, 4($v1)
  add.s $f10, $f4, $f6
  swc1  $f10, 0xc($s3)
  lwc1  $f8, 0xc($s3)
  lw    $a0, 0x14($s1)
  swc1  $f8, 0x5c($s1)
  jal   setsuboffset
   lw    $a1, 0x74($sp)
  lwc1  $f12, 0xa0($s1)
.Ljp7F04847C:
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  c.le.s $f22, $f12
  nop   
  bc1fl .Ljp7F0484E4
   lwc1  $f0, 0x94($s1)
  lwc1  $f2, %lo(global_timer_delta)($at)
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  c.le.s $f12, $f2
  nop   
  bc1fl .Ljp7F0484BC
   lwc1  $f14, 0x98($s1)
  lwc1  $f4, 0x9c($s1)
  lwc1  $f12, 0xa0($s1)
  b     .Ljp7F0484D4
   swc1  $f4, 0x98($s1)
  lwc1  $f14, 0x98($s1)
.Ljp7F0484BC:
  lwc1  $f6, 0x9c($s1)
  sub.s $f10, $f6, $f14
  mul.s $f8, $f10, $f2
  div.s $f4, $f8, $f12
  add.s $f6, $f14, $f4
  swc1  $f6, 0x98($s1)
.Ljp7F0484D4:
  lwc1  $f10, %lo(global_timer_delta)($at)
  sub.s $f8, $f12, $f10
  swc1  $f8, 0xa0($s1)
  lwc1  $f0, 0x94($s1)
.Ljp7F0484E4:
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  c.le.s $f22, $f0
  nop   
  bc1fl .Ljp7F04854C
   lw    $t7, 0xc($s1)
  lwc1  $f2, %lo(global_timer_delta)($at)
  lui   $at, %hi(global_timer_delta) # $at, 0x8005
  c.le.s $f0, $f2
  nop   
  bc1fl .Ljp7F048524
   lwc1  $f12, 0x8c($s1)
  lwc1  $f4, 0x90($s1)
  lwc1  $f0, 0x94($s1)
  b     .Ljp7F04853C
   swc1  $f4, 0x8c($s1)
  lwc1  $f12, 0x8c($s1)
.Ljp7F048524:
  lwc1  $f6, 0x90($s1)
  sub.s $f10, $f6, $f12
  mul.s $f8, $f10, $f2
  div.s $f4, $f8, $f0
  add.s $f6, $f12, $f4
  swc1  $f6, 0x8c($s1)
.Ljp7F04853C:
  lwc1  $f10, %lo(global_timer_delta)($at)
  sub.s $f8, $f0, $f10
  swc1  $f8, 0x94($s1)
  lw    $t7, 0xc($s1)
.Ljp7F04854C:
  move  $s0, $zero
  sll   $t5, $t7, 0xc
  bltz  $t5, .Ljp7F0485A8
   nop   
  jal   check_if_object_has_not_been_destroyed
   move  $a0, $s1
  beqz  $v0, .Ljp7F0485A8
   nop   
  lwc1  $f4, 0x8c($s1)
  c.eq.s $f22, $f4
  nop   
  bc1t  .Ljp7F0485A8
   nop   
  lw    $t9, 8($s1)
  lui   $a1, (0x459C4000 >> 16) # lui $a1, 0x459c
  ori   $a1, (0x459C4000 & 0xFFFF) # ori $a1, $a1, 0x4000
  sll   $t0, $t9, 2
  bltz  $t0, .Ljp7F0485A8
   addiu $a0, $s1, 0x58
  lui   $a2, (0x45BB8000 >> 16) # lui $a2, 0x45bb
  jal   sub_GAME_7F053894
   ori   $a2, (0x45BB8000 & 0xFFFF) # ori $a2, $a2, 0x8000
  move  $s0, $v0
.Ljp7F0485A8:
  blezl $s0, .Ljp7F048610
   lw    $a0, 0xb0($s1)
  lw    $a0, 0xb0($s1)
  beqz  $a0, .Ljp7F0485CC
   nop   
  jal   sfxGetArg0Unk3F
   nop   
  bnezl $v0, .Ljp7F0485F0
   lw    $a0, 0xb0($s1)
.Ljp7F0485CC:
  jal   get_controls_locked_flag
   nop   
  bnez  $v0, .Ljp7F0485EC
   lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 58
  jal   play_sfx_a1
   addiu $a2, $s1, 0xb0
.Ljp7F0485EC:
  lw    $a0, 0xb0($s1)
.Ljp7F0485F0:
  li    $a1, 8
  beql  $a0, $zero, .Ljp7F048634
   lbu   $v0, 3($s1)
  jal   sfx_c_70009184
   move  $a2, $s0
  b     .Ljp7F048634
   lbu   $v0, 3($s1)
  lw    $a0, 0xb0($s1)
.Ljp7F048610:
  beql  $a0, $zero, .Ljp7F048634
   lbu   $v0, 3($s1)
  jal   sfxGetArg0Unk3F
   nop   
  beql  $v0, $zero, .Ljp7F048634
   lbu   $v0, 3($s1)
  jal   sfxDeactivate
   lw    $a0, 0xb0($s1)
.Ljp7F048630:
  lbu   $v0, 3($s1)
.Ljp7F048634:
  lui   $at, %hi(D_80052B64) # $at, 0x8005
  lwc1  $f20, %lo(D_80052B64)($at)
  li    $at, 47
  bnel  $v0, $at, .Ljp7F0486C4
   li    $at, 1
  lw    $s0, 4($s3)
  addiu $a0, $s1, 0x58
  lw    $t8, 0x80($s0)
  lw    $t1, 0x84($s0)
  lw    $a3, 0x90($s0)
  mtc1  $t8, $f6
  mtc1  $t1, $f10
  cvt.s.w $f6, $f6
  cvt.s.w $f10, $f10
  mfc1  $a1, $f6
  mfc1  $a2, $f10
  jal   sub_GAME_7F0451DC
   nop   
  lw    $a0, 0x8c($s0)
  sw    $v0, 0x88($s0)
  lw    $t3, 0x67c($sp)
  bltz  $a0, .Ljp7F0486B8
   li    $at, 1
  bne   $t3, $at, .Ljp7F0486B8
   li    $at, 255
  bne   $v0, $at, .Ljp7F0486B0
   nop   
  jal   sub_GAME_7F0B9DBC
   move  $a1, $zero
  b     .Ljp7F0486B8
   nop   
.Ljp7F0486B0:
  jal   sub_GAME_7F0B9DBC
   li    $a1, 1
.Ljp7F0486B8:
  b     .Ljp7F0487A8
   sw    $zero, 0x678($sp)
  li    $at, 1
.Ljp7F0486C4:
  bnel  $v0, $at, .Ljp7F0487AC
   lbu   $t4, 3($s1)
  lhu   $t4, 0x98($s1)
  andi  $t2, $t4, 2
  beql  $t2, $zero, .Ljp7F0487AC
   lbu   $t4, 3($s1)
  lw    $s0, 4($s3)
  mfc1  $a3, $f22
  li    $s2, 1
  lw    $t7, 0xc0($s0)
  lw    $t5, 0xc4($s0)
  addiu $a0, $s1, 0x58
  mtc1  $t7, $f8
  mtc1  $t5, $f4
  cvt.s.w $f8, $f8
  cvt.s.w $f4, $f4
  mfc1  $a1, $f8
  mfc1  $a2, $f4
  jal   sub_GAME_7F0451DC
   nop   
  sh    $v0, 0xbe($s0)
  lw    $t9, 0x67c($sp)
  li    $at, 1
  bnel  $t9, $at, .Ljp7F0487AC
   lbu   $t4, 3($s1)
  lh    $t0, 0xbe($s0)
  li    $at, 255
  bnel  $t0, $at, .Ljp7F048750
   move  $s2, $zero
  lwc1  $f6, 0xb4($s0)
  c.lt.s $f22, $f6
  nop   
  bc1fl .Ljp7F048754
   lw    $v0, 8($s4)
  move  $s2, $zero
.Ljp7F048750:
  lw    $v0, 8($s4)
.Ljp7F048754:
  lui   $t8, %hi(prop_door_related) # $t8, 0x8004
  addiu $t8, %lo(prop_door_related) # addiu $t8, $t8, -0x5df4
  lw    $t1, 4($v0)
  bne   $t8, $t1, .Ljp7F048788
   nop   
  lw    $t3, 8($v0)
  move  $a0, $s4
  jal   extract_id_from_object_structure_microcode
   lw    $a1, 4($t3)
  lw    $t6, ($v0)
  bnez  $t6, .Ljp7F048788
   nop   
  move  $s2, $zero
.Ljp7F048788:
  beqz  $s2, .Ljp7F0487A0
   nop   
  jal   sub_GAME_7F0535C4
   move  $a0, $s0
  b     .Ljp7F0487AC
   lbu   $t4, 3($s1)
.Ljp7F0487A0:
  jal   sub_GAME_7F053598
   move  $a0, $s0
.Ljp7F0487A8:
  lbu   $t4, 3($s1)
.Ljp7F0487AC:
  li    $s0, 45
  bnel  $s0, $t4, .Ljp7F0487D4
   lw    $v1, 0xc($s1)
  jal   get_ptr_for_players_tank
   nop   
  bnel  $v0, $s3, .Ljp7F0487D4
   lw    $v1, 0xc($s1)
  b     .Ljp7F048830
   li    $v1, 1
  lw    $v1, 0xc($s1)
.Ljp7F0487D4:
  sll   $t2, $v1, 5
  bgezl $t2, .Ljp7F0487EC
   lw    $t7, 0x64($s1)
  b     .Ljp7F048830
   li    $v1, 1
  lw    $t7, 0x64($s1)
.Ljp7F0487EC:
  sll   $t9, $v1, 0xc
  move  $v1, $zero
  andi  $t5, $t7, 0x800
  bnez  $t5, .Ljp7F048830
   nop   
  bltz  $t9, .Ljp7F048830
   move  $a0, $s4
  addiu $t0, $s1, 0x58
  jal   getinstsize
   sw    $t0, 0x74($sp)
  mfc1  $a2, $f0
  move  $a0, $s3
  lw    $a1, 0x74($sp)
  jal   sub_GAME_7F054D6C
   lw    $a3, 0x678($sp)
  b     .Ljp7F048830
   move  $v1, $v0
.Ljp7F048830:
  beqz  $v1, .Ljp7F04961C
   lw    $t8, 0x680($sp)
  beqz  $t8, .Ljp7F048848
   addiu $a0, $s1, 0x78
  jal   update_color_shading
   addiu $a1, $s1, 0x7c
.Ljp7F048848:
  lbu   $t1, 1($s3)
  ori   $t3, $t1, 2
  sb    $t3, 1($s3)
  lw    $t6, 8($s4)
  lh    $a0, 0xe($t6)
  sll   $t4, $a0, 6
  jal   sub_GAME_7F0BD714
   move  $a0, $t4
  sw    $v0, 0xc($s4)
  lbu   $t2, 3($s1)
  li    $at, 1
  move  $s2, $v0
  bne   $t2, $at, .Ljp7F048B30
   addiu $a0, $s1, 0x18
  lw    $a0, 4($s3)
  move  $a1, $v0
  jal   sub_GAME_7F0526EC
   sw    $a0, 0x3a0($sp)
  jal   get_BONDdata_field_10CC
   nop   
  move  $a0, $v0
  jal   sub_GAME_7F058098
   move  $a1, $s2
  lw    $v0, 8($s4)
  lui   $t7, %hi(prop_eyelid_door_related) # $t7, 0x8004
  addiu $t7, %lo(prop_eyelid_door_related) # addiu $t7, $t7, -0x5ed0
  lw    $v1, 4($v0)
  lui   $t3, %hi(prop_iris_door_related) # $t3, 0x8004
  lw    $a2, 0x3a0($sp)
  bne   $t7, $v1, .Ljp7F048954
   addiu $t3, %lo(prop_iris_door_related) # addiu $t3, $t3, -0x5e74
  lwc1  $f10, 0xb4($a2)
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f4
  mul.s $f8, $f10, $f20
  lw    $t5, 8($v0)
  addiu $a1, $s2, 0x40
  lw    $t9, 4($t5)
  div.s $f6, $f8, $f4
  lw    $s0, 4($t9)
  sw    $a1, 0x70($sp)
  sub.s $f12, $f20, $f6
  jal   sub_GAME_7F058570
   swc1  $f12, 0x398($sp)
  move  $a0, $s0
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   lw    $a1, 0x70($sp)
  move  $a0, $s2
  jal   sub_GAME_7F058068
   lw    $a1, 0x70($sp)
  lw    $t0, 8($s4)
  lwc1  $f10, 0x398($sp)
  addiu $a1, $s2, 0x80
  lw    $t8, 8($t0)
  sub.s $f12, $f20, $f10
  lw    $t1, 8($t8)
  lw    $s0, 4($t1)
  jal   sub_GAME_7F058570
   sw    $a1, 0x6c($sp)
  move  $a0, $s0
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   lw    $a1, 0x6c($sp)
  move  $a0, $s2
  jal   sub_GAME_7F058068
   lw    $a1, 0x6c($sp)
  b     .Ljp7F0495CC
   lw    $t4, 8($s4)
.Ljp7F048954:
  bnel  $t3, $v1, .Ljp7F0495CC
   lw    $t4, 8($s4)
  lwc1  $f2, 0xb4($a2)
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f4
  mul.s $f8, $f2, $f20
  lui   $at, %hi(D_80052B68) # $at, 0x8005
  lwc1  $f10, %lo(D_80052B68)($at)
  mov.s $f14, $f22
  div.s $f6, $f8, $f4
  swc1  $f6, 0x388($sp)
  lwc1  $f12, 0x84($a2)
  mul.s $f0, $f12, $f10
  c.lt.s $f0, $f2
  nop   
  bc1fl .Ljp7F048A10
   lw    $t2, 0x680($sp)
  sub.s $f8, $f2, $f0
  li    $at, 0x43B40000 # 360.000000
  lw    $t6, 0x680($sp)
  sub.s $f6, $f12, $f0
  mul.s $f4, $f12, $f8
  div.s $f10, $f4, $f6
  mtc1  $at, $f4
  mul.s $f8, $f10, $f20
  div.s $f14, $f8, $f4
  beqz  $t6, .Ljp7F048A04
   swc1  $f14, 0x384($sp)
  lwc1  $f6, 0x684($sp)
  swc1  $f14, 0x384($sp)
  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  c.le.s $f6, $f0
  li    $a1, 202
  move  $a2, $zero
  addiu $t4, $s3, 8
  bc1f  .Ljp7F048A04
   nop   
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  sw    $t4, 0x74($sp)
  jal   play_sfx_a1
   swc1  $f14, 0x384($sp)
  move  $a0, $v0
  jal   sub_GAME_7F053A10
   lw    $a1, 0x74($sp)
.Ljp7F048A04:
  b     .Ljp7F048A60
   sw    $zero, 0x390($sp)
  lw    $t2, 0x680($sp)
.Ljp7F048A10:
  swc1  $f14, 0x384($sp)
  beql  $t2, $zero, .Ljp7F048A60
   sw    $zero, 0x390($sp)
  lwc1  $f10, 0x684($sp)
  swc1  $f14, 0x384($sp)
  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  c.lt.s $f0, $f10
  li    $a1, 203
  move  $a2, $zero
  addiu $t7, $s3, 8
  bc1fl .Ljp7F048A60
   sw    $zero, 0x390($sp)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  sw    $t7, 0x74($sp)
  jal   play_sfx_a1
   swc1  $f14, 0x384($sp)
  move  $a0, $v0
  jal   sub_GAME_7F053A10
   lw    $a1, 0x74($sp)
  sw    $zero, 0x390($sp)
.Ljp7F048A60:
  lw    $t5, 8($s4)
  lw    $v1, 0x390($sp)
  lwc1  $f12, 0x384($sp)
  lw    $t9, 8($t5)
  sll   $v0, $v1, 1
  sll   $t0, $v0, 2
  addu  $t8, $t9, $t0
  lw    $t1, 4($t8)
  sll   $t6, $v0, 6
  addu  $a1, $s2, $t6
  lw    $t3, 4($t1)
  sw    $v0, 0x78($sp)
  addiu $a1, $a1, 0x40
  jal   sub_GAME_7F058688
   sw    $t3, 0x394($sp)
  lw    $t4, 0x78($sp)
  lw    $s0, 0x390($sp)
  lw    $a0, 0x394($sp)
  sll   $t2, $t4, 6
  addu  $a1, $s2, $t2
  addiu $a1, $a1, 0x40
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   sw    $a1, 0x74($sp)
  move  $a0, $s2
  jal   sub_GAME_7F058068
   lw    $a1, 0x74($sp)
  lw    $t7, 8($s4)
  lw    $v0, 0x78($sp)
  lwc1  $f12, 0x388($sp)
  lw    $t5, 8($t7)
  addiu $v0, $v0, 2
  sll   $t9, $v0, 2
  addu  $t0, $t5, $t9
  lw    $t8, ($t0)
  sll   $t3, $v0, 6
  addu  $a1, $s2, $t3
  lw    $t1, 4($t8)
  sw    $a1, 0x70($sp)
  jal   sub_GAME_7F058688
   sw    $t1, 0x394($sp)
  lw    $a0, 0x394($sp)
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   lw    $a1, 0x70($sp)
  lw    $a0, 0x74($sp)
  jal   sub_GAME_7F058068
   lw    $a1, 0x70($sp)
  addiu $s0, $s0, 1
  li    $at, 6
  bne   $s0, $at, .Ljp7F048A60
   sw    $s0, 0x390($sp)
  b     .Ljp7F0495CC
   lw    $t4, 8($s4)
.Ljp7F048B30:
  addiu $t6, $s1, 0x58
  sw    $t6, 0x74($sp)
  jal   sub_GAME_7F058020
   addiu $a1, $sp, 0x3a8
  lw    $a0, 0x74($sp)
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   addiu $a1, $sp, 0x3a8
  jal   get_BONDdata_field_10CC
   nop   
  move  $a0, $v0
  addiu $a1, $sp, 0x3a8
  jal   sub_GAME_7F05818C
   move  $a2, $s2
  lbu   $v0, 3($s1)
  li    $at, 6
  addiu $a1, $sp, 0x324
  bnel  $v0, $at, .Ljp7F048C28
   li    $at, 13
  lw    $v0, 4($s3)
  lw    $t4, 8($s4)
  lwc1  $f12, 0xc8($v0)
  lw    $t2, 8($t4)
  c.lt.s $f12, $f22
  lw    $t7, ($t2)
  bc1f  .Ljp7F048BA0
   lw    $s0, 4($t7)
  b     .Ljp7F048BB4
   add.s $f12, $f12, $f20
.Ljp7F048BA0:
  c.le.s $f20, $f12
  nop   
  bc1f  .Ljp7F048BB4
   nop   
  sub.s $f12, $f12, $f20
.Ljp7F048BB4:
  jal   sub_GAME_7F0585FC
   sw    $v0, 0x374($sp)
  lw    $v0, 0x374($sp)
  addiu $a2, $s2, 0x40
  sw    $a2, 0x70($sp)
  addiu $a0, $sp, 0x324
  jal   sub_GAME_7F0580C8
   addiu $a1, $v0, 0x84
  lwc1  $f8, ($s0)
  addiu $s2, $sp, 0x364
  move  $a1, $s2
  swc1  $f8, 0x364($sp)
  lwc1  $f4, 4($s0)
  addiu $a0, $sp, 0x3a8
  swc1  $f4, 0x368($sp)
  lwc1  $f6, 8($s0)
  jal   sub_GAME_7F058474
   swc1  $f6, 0x36c($sp)
  move  $a0, $s2
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   lw    $a1, 0x70($sp)
  jal   get_BONDdata_field_10CC
   nop   
  move  $a0, $v0
  jal   sub_GAME_7F058098
   lw    $a1, 0x70($sp)
  b     .Ljp7F0495CC
   lw    $t4, 8($s4)
  li    $at, 13
.Ljp7F048C28:
  bnel  $v0, $at, .Ljp7F048E28
   li    $at, 8
  lw    $v0, 4($s3)
  lui   $at, %hi(D_80052B6C) # $at, 0x8005
  lwc1  $f8, %lo(D_80052B6C)($at)
  lwc1  $f10, 0x90($v0)
  lwc1  $f4, 0x9c($v0)
  add.s $f12, $f10, $f8
  neg.s $f6, $f4
  c.le.s $f20, $f12
  swc1  $f6, 0x304($sp)
  bc1fl .Ljp7F048C64
   lw    $t5, 8($s4)
  sub.s $f12, $f12, $f20
  lw    $t5, 8($s4)
.Ljp7F048C64:
  addiu $a0, $sp, 0x3a8
  addiu $a1, $sp, 0x30c
  lw    $t9, 8($t5)
  lw    $t0, 4($t9)
  lw    $s0, 4($t0)
  lwc1  $f10, ($s0)
  swc1  $f10, 0x30c($sp)
  lwc1  $f8, 4($s0)
  swc1  $f8, 0x310($sp)
  lwc1  $f4, 8($s0)
  swc1  $f12, 0x308($sp)
  sw    $v0, 0x31c($sp)
  jal   sub_GAME_7F058474
   swc1  $f4, 0x314($sp)
  addiu $a1, $s2, 0x40
  lwc1  $f12, 0x308($sp)
  jal   sub_GAME_7F0585FC
   sw    $a1, 0x70($sp)
  addiu $a0, $sp, 0x30c
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   lw    $a1, 0x70($sp)
  lw    $t8, 0x31c($sp)
  lw    $a1, 0x70($sp)
  lw    $t1, 0x14($t8)
  jal   matrix_multiply_A1_by_F12
   lwc1  $f12, 0x14($t1)
  jal   get_BONDdata_field_10CC
   nop   
  move  $a0, $v0
  jal   sub_GAME_7F058098
   lw    $a1, 0x70($sp)
  lw    $t3, 8($s4)
  addiu $a1, $s2, 0x80
  lwc1  $f12, 0x304($sp)
  lw    $t6, 8($t3)
  lw    $t4, 8($t6)
  lw    $s0, 4($t4)
  jal   sub_GAME_7F058688
   sw    $a1, 0x6c($sp)
  move  $a0, $s0
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   lw    $a1, 0x6c($sp)
  lw    $a0, 0x70($sp)
  jal   sub_GAME_7F058098
   lw    $a1, 0x6c($sp)
  lw    $t2, 8($s4)
  move  $a0, $s4
  lw    $v1, 8($t2)
  lw    $a1, 0xc($v1)
  beql  $a1, $zero, .Ljp7F048D84
   lw    $a1, 0x10($v1)
  jal   sub_GAME_7F06C660
   move  $a2, $zero
  sw    $v0, 0x300($sp)
  lw    $t7, 8($s4)
  lw    $t0, 0x31c($sp)
  move  $a1, $v0
  lw    $t5, 8($t7)
  lwc1  $f12, 0xb4($t0)
  lw    $t9, 0xc($t5)
  jal   sub_GAME_7F058570
   lw    $s0, 4($t9)
  lw    $s2, 0x300($sp)
  move  $a0, $s0
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   move  $a1, $s2
  lw    $a0, 0x6c($sp)
  jal   sub_GAME_7F058098
   move  $a1, $s2
  lw    $t8, 8($s4)
  lw    $v1, 8($t8)
  lw    $a1, 0x10($v1)
.Ljp7F048D84:
  move  $a0, $s4
  beql  $a1, $zero, .Ljp7F048DCC
   lw    $a1, 0x18($v1)
  jal   sub_GAME_7F06C660
   move  $a2, $zero
  lw    $t1, 8($s4)
  move  $s2, $v0
  move  $a1, $v0
  lw    $t3, 8($t1)
  lw    $t6, 0x10($t3)
  jal   init_something_copy_posdata_to_it
   lw    $a0, 4($t6)
  lw    $a0, 0x6c($sp)
  jal   sub_GAME_7F058098
   move  $a1, $s2
  lw    $t4, 8($s4)
  lw    $v1, 8($t4)
  lw    $a1, 0x18($v1)
.Ljp7F048DCC:
  move  $a0, $s4
  beql  $a1, $zero, .Ljp7F0495CC
   lw    $t4, 8($s4)
  jal   sub_GAME_7F06C660
   move  $a2, $zero
  lw    $t2, 8($s4)
  lw    $t9, 0x31c($sp)
  move  $s2, $v0
  lw    $t7, 8($t2)
  move  $a1, $v0
  lwc1  $f12, 0xb4($t9)
  lw    $t5, 0x18($t7)
  jal   sub_GAME_7F058570
   lw    $s0, 4($t5)
  move  $a0, $s0
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   move  $a1, $s2
  lw    $a0, 0x6c($sp)
  jal   sub_GAME_7F058098
   move  $a1, $s2
  b     .Ljp7F0495CC
   lw    $t4, 8($s4)
  li    $at, 8
.Ljp7F048E28:
  bnel  $v0, $at, .Ljp7F048E88
   li    $at, 12
  lw    $t0, 8($s4)
  li    $v0, 1
  addiu $a0, $s2, 0x40
  lh    $t8, 0xe($t0)
  slti  $at, $t8, 2
  bnezl $at, .Ljp7F0495CC
   lw    $t4, 8($s4)
  sw    $v0, 0x2fc($sp)
.Ljp7F048E50:
  jal   reset_array_of_0x10_floats
   sw    $a0, 0x78($sp)
  lw    $t1, 8($s4)
  lw    $v0, 0x2fc($sp)
  lw    $a0, 0x78($sp)
  lh    $t3, 0xe($t1)
  addiu $v0, $v0, 1
  addiu $a0, $a0, 0x40
  slt   $at, $v0, $t3
  bnezl $at, .Ljp7F048E50
   sw    $v0, 0x2fc($sp)
  b     .Ljp7F0495CC
   lw    $t4, 8($s4)
  li    $at, 12
.Ljp7F048E88:
  bnel  $v0, $at, .Ljp7F048F3C
   li    $at, 39
  lw    $t6, 8($s4)
  addiu $a1, $s2, 0x40
  lw    $t4, 8($t6)
  lw    $t2, ($t4)
  lw    $a0, 4($t2)
  jal   init_something_copy_posdata_to_it
   sw    $a1, 0x70($sp)
  move  $a0, $s2
  jal   sub_GAME_7F058098
   lw    $a1, 0x70($sp)
  lw    $t7, 8($s4)
  addiu $a1, $s2, 0x80
  lw    $t5, 8($t7)
  lw    $t9, 4($t5)
  lw    $a0, 4($t9)
  jal   init_something_copy_posdata_to_it
   sw    $a1, 0x6c($sp)
  move  $a0, $s2
  jal   sub_GAME_7F058098
   lw    $a1, 0x6c($sp)
  lw    $t0, 8($s4)
  addiu $a1, $s2, 0xc0
  lw    $t8, 8($t0)
  lw    $t1, 8($t8)
  lw    $a0, 4($t1)
  jal   init_something_copy_posdata_to_it
   sw    $a1, 0x78($sp)
  move  $a0, $s2
  jal   sub_GAME_7F058098
   lw    $a1, 0x78($sp)
  lw    $t3, 8($s4)
  addiu $s0, $s2, 0x100
  move  $a1, $s0
  lw    $t6, 8($t3)
  lw    $t4, 0xc($t6)
  jal   init_something_copy_posdata_to_it
   lw    $a0, 4($t4)
  move  $a0, $s2
  jal   sub_GAME_7F058098
   move  $a1, $s0
  b     .Ljp7F0495CC
   lw    $t4, 8($s4)
  li    $at, 39
.Ljp7F048F3C:
  bnel  $v0, $at, .Ljp7F049224
   li    $at, 40
  lw    $t2, 8($s4)
  lw    $t4, 0x680($sp)
  mov.s $f0, $f22
  lw    $v1, 8($t2)
  lw    $t7, 4($v1)
  lw    $t5, 4($t7)
  sw    $t5, 0x264($sp)
  lw    $t9, 8($v1)
  lw    $t0, 4($t9)
  sw    $t0, 0x260($sp)
  lw    $t1, 0x10($v1)
  lw    $t8, 0xc($v1)
  lw    $t3, 4($t1)
  lw    $s0, 4($t8)
  sw    $t3, 0x258($sp)
  lw    $t6, 0x18($v1)
  lwc1  $f4, 0x14($s4)
  lw    $v0, 4($t6)
  lwc1  $f6, 0x10($v0)
  lwc1  $f10, 0xc($v0)
  sub.s $f8, $f6, $f10
  mul.s $f2, $f8, $f4
  beqz  $t4, .Ljp7F049038
   lui   $at, %hi(global_timer_delta) # $at, 0x8005
  lwc1  $f10, %lo(global_timer_delta)($at)
  lwc1  $f6, 0x88($s1)
  li    $at, 0x3F000000 # 0.500000
  mul.s $f8, $f6, $f10
  mtc1  $at, $f10
  mul.s $f4, $f8, $f20
  nop   
  mul.s $f6, $f2, $f20
  nop   
  mul.s $f8, $f6, $f10
  lwc1  $f6, 0x8c($s1)
  div.s $f0, $f4, $f8
  add.s $f10, $f6, $f0
  swc1  $f10, 0x8c($s1)
  lwc1  $f12, 0x8c($s1)
  c.le.s $f20, $f12
  nop   
  bc1f  .Ljp7F04900C
   nop   
  sub.s $f4, $f12, $f20
.Ljp7F048FF4:
  swc1  $f4, 0x8c($s1)
  lwc1  $f12, 0x8c($s1)
  c.le.s $f20, $f12
  nop   
  bc1tl .Ljp7F048FF4
   sub.s $f4, $f12, $f20
.Ljp7F04900C:
  c.lt.s $f12, $f22
  nop   
  bc1fl .Ljp7F04903C
   lwc1  $f6, 0x8c($s1)
  add.s $f8, $f12, $f20
.Ljp7F049020:
  swc1  $f8, 0x8c($s1)
  lwc1  $f12, 0x8c($s1)
  c.lt.s $f12, $f22
  nop   
  bc1tl .Ljp7F049020
   add.s $f8, $f12, $f20
.Ljp7F049038:
  lwc1  $f6, 0x8c($s1)
.Ljp7F04903C:
  add.s $f10, $f6, $f0
  swc1  $f10, 0x8c($s1)
  lwc1  $f12, 0x8c($s1)
  c.le.s $f20, $f12
  nop   
  bc1fl .Ljp7F049078
   c.lt.s $f12, $f22
  sub.s $f4, $f12, $f20
.Ljp7F04905C:
  swc1  $f4, 0x8c($s1)
  lwc1  $f12, 0x8c($s1)
  c.le.s $f20, $f12
  nop   
  bc1tl .Ljp7F04905C
   sub.s $f4, $f12, $f20
  c.lt.s $f12, $f22
.Ljp7F049078:
  nop   
  bc1f  .Ljp7F0490A0
   nop   
  add.s $f8, $f12, $f20
.Ljp7F049088:
  swc1  $f8, 0x8c($s1)
  lwc1  $f12, 0x8c($s1)
  c.lt.s $f12, $f22
  nop   
  bc1tl .Ljp7F049088
   add.s $f8, $f12, $f20
.Ljp7F0490A0:
  jal   sub_GAME_7F058570
   addiu $a1, $sp, 0x2b0
  lwc1  $f6, 0x88($s1)
  c.lt.s $f22, $f6
  nop   
  bc1fl .Ljp7F049164
   lwc1  $f12, 0x90($s1)
  lw    $t2, 0x264($sp)
  lwc1  $f10, 8($s0)
  lwc1  $f12, 0x9c($s1)
  lwc1  $f4, 8($t2)
  lwc1  $f6, 0x14($s4)
  c.lt.s $f12, $f22
  sub.s $f8, $f10, $f4
  mul.s $f2, $f8, $f6
  bc1fl .Ljp7F0490EC
   swc1  $f2, 0x254($sp)
  neg.s $f12, $f12
  swc1  $f2, 0x254($sp)
.Ljp7F0490EC:
  jal   sinf
   swc1  $f12, 0x250($sp)
  lwc1  $f2, 0x254($sp)
  lwc1  $f12, 0x250($sp)
  mul.s $f10, $f0, $f2
  jal   cosf
   swc1  $f10, 0x24c($sp)
  lwc1  $f2, 0x254($sp)
  lwc1  $f8, 0x88($s1)
  lwc1  $f12, 0x24c($sp)
  mul.s $f4, $f0, $f2
  sub.s $f6, $f2, $f8
  jal   convert_angle_using_inverse
   sub.s $f14, $f4, $f6
  lwc1  $f2, 0x250($sp)
  swc1  $f0, 0x90($s1)
  c.lt.s $f0, $f2
  nop   
  bc1fl .Ljp7F049144
   lwc1  $f10, 0x9c($s1)
  swc1  $f2, 0x90($s1)
  lwc1  $f10, 0x9c($s1)
.Ljp7F049144:
  c.lt.s $f22, $f10
  nop   
  bc1fl .Ljp7F049164
   lwc1  $f12, 0x90($s1)
  lwc1  $f8, 0x90($s1)
  sub.s $f4, $f20, $f8
  swc1  $f4, 0x90($s1)
  lwc1  $f12, 0x90($s1)
.Ljp7F049164:
  jal   sub_GAME_7F0585FC
   addiu $a1, $sp, 0x270
  addiu $a1, $s2, 0xc0
  sw    $a1, 0x78($sp)
  jal   sub_GAME_7F058020
   addiu $a0, $sp, 0x2b0
  move  $a0, $s0
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   lw    $a1, 0x78($sp)
  move  $a0, $s2
  jal   sub_GAME_7F058098
   lw    $a1, 0x78($sp)
  addiu $s0, $s2, 0x100
  move  $a1, $s0
  jal   sub_GAME_7F058020
   addiu $a0, $sp, 0x2b0
  lw    $a0, 0x258($sp)
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   move  $a1, $s0
  move  $a0, $s2
  jal   sub_GAME_7F058098
   move  $a1, $s0
  addiu $a0, $sp, 0x270
  jal   sub_GAME_7F058098
   addiu $a1, $sp, 0x2b0
  addiu $a1, $s2, 0x40
  sw    $a1, 0x70($sp)
  jal   sub_GAME_7F058020
   addiu $a0, $sp, 0x2b0
  lw    $a0, 0x264($sp)
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   lw    $a1, 0x70($sp)
  move  $a0, $s2
  jal   sub_GAME_7F058098
   lw    $a1, 0x70($sp)
  addiu $a1, $s2, 0x80
  sw    $a1, 0x6c($sp)
  jal   sub_GAME_7F058020
   addiu $a0, $sp, 0x2b0
  lw    $a0, 0x260($sp)
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   lw    $a1, 0x6c($sp)
  move  $a0, $s2
  jal   sub_GAME_7F058098
   lw    $a1, 0x6c($sp)
  b     .Ljp7F0495CC
   lw    $t4, 8($s4)
  li    $at, 40
.Ljp7F049224:
  bne   $v0, $at, .Ljp7F049440
   nop   
  lw    $t7, 8($s4)
  lui   $t8, %hi(clock_timer) # $t8, 0x8005
  lw    $t8, %lo(clock_timer)($t8)
  lw    $t5, 8($t7)
  lw    $t1, 0x680($sp)
  addiu $s0, $sp, 0x1b4
  lw    $t9, 8($t5)
  lui   $t4, %hi(D_80030B34) # $t4, 0x8003
  move  $a0, $s2
  lw    $t0, 4($t9)
  addiu $a1, $s2, 0x40
  blez  $t8, .Ljp7F0492D4
   sw    $t0, 0x200($sp)
  beql  $t1, $zero, .Ljp7F0492D8
   lw    $t3, 0x14($s1)
  lwc1  $f6, 0x88($s1)
  lwc1  $f10, 0x8c($s1)
  add.s $f8, $f6, $f10
  swc1  $f8, 0x88($s1)
  lwc1  $f0, 0x88($s1)
  c.le.s $f20, $f0
  nop   
  bc1fl .Ljp7F0492AC
   c.lt.s $f0, $f22
  sub.s $f4, $f0, $f20
.Ljp7F049290:
  swc1  $f4, 0x88($s1)
  lwc1  $f0, 0x88($s1)
  c.le.s $f20, $f0
  nop   
  bc1tl .Ljp7F049290
   sub.s $f4, $f0, $f20
  c.lt.s $f0, $f22
.Ljp7F0492AC:
  nop   
  bc1fl .Ljp7F0492D8
   lw    $t3, 0x14($s1)
  add.s $f6, $f0, $f20
.Ljp7F0492BC:
  swc1  $f6, 0x88($s1)
  lwc1  $f0, 0x88($s1)
  c.lt.s $f0, $f22
  nop   
  bc1tl .Ljp7F0492BC
   add.s $f6, $f0, $f20
.Ljp7F0492D4:
  lw    $t3, 0x14($s1)
.Ljp7F0492D8:
  addiu $t4, %lo(D_80030B34) # addiu $t4, $t4, 0xb74
  addiu $t7, $t4, 0x3c
  lw    $t6, 0x20($t3)
  move  $t5, $s0
  beqz  $t6, .Ljp7F049340
   nop   
.Ljp7F0492F0:
  lw    $at, ($t4)
  addiu $t4, $t4, 0xc
  addiu $t5, $t5, 0xc
  sw    $at, -0xc($t5)
  lw    $at, -8($t4)
  sw    $at, -8($t5)
  lw    $at, -4($t4)
  bne   $t4, $t7, .Ljp7F0492F0
   sw    $at, -4($t5)
  lw    $at, ($t4)
  jal   get_BONDdata_field_10CC
   sw    $at, ($t5)
  sw    $v0, 0x1b4($sp)
  sw    $s2, 0x1c4($sp)
  lw    $a1, 0x14($s1)
  jal   subcalcmatrices
   move  $a0, $s0
  addiu $t9, $s2, 0x40
  b     .Ljp7F049348
   sw    $t9, 0x70($sp)
.Ljp7F049340:
  jal   sub_GAME_7F058020
   sw    $a1, 0x70($sp)
.Ljp7F049348:
  lw    $t0, 8($s1)
  addiu $a1, $sp, 0x204
  sll   $t8, $t0, 2
  bgez  $t8, .Ljp7F049370
   nop   
  lwc1  $f12, 0x88($s1)
  jal   sub_GAME_7F058688
   addiu $a1, $sp, 0x204
  b     .Ljp7F04937C
   addiu $a1, $s2, 0x80
.Ljp7F049370:
  jal   sub_GAME_7F0585FC
   lwc1  $f12, 0x88($s1)
  addiu $a1, $s2, 0x80
.Ljp7F04937C:
  sw    $a1, 0x6c($sp)
  jal   sub_GAME_7F058020
   addiu $a0, $sp, 0x204
  lw    $a0, 0x200($sp)
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   lw    $a1, 0x6c($sp)
  lw    $a0, 0x70($sp)
  jal   sub_GAME_7F058098
   lw    $a1, 0x6c($sp)
  lw    $t1, 8($s4)
  move  $a0, $s4
  move  $a2, $zero
  lw    $v1, 8($t1)
  lw    $a1, 0xc($v1)
  beql  $a1, $zero, .Ljp7F049404
   lw    $a1, 0x10($v1)
  jal   sub_GAME_7F06C660
   lw    $s2, 4($a1)
  move  $s0, $v0
  lwc1  $f12, 0x88($s1)
  jal   sub_GAME_7F058570
   addiu $a1, $sp, 0x204
  addiu $a0, $sp, 0x204
  jal   sub_GAME_7F058020
   move  $a1, $s0
  move  $a0, $s2
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   move  $a1, $s0
  lw    $a0, 0x70($sp)
  jal   sub_GAME_7F058098
   move  $a1, $s0
  lw    $t3, 8($s4)
  lw    $v1, 8($t3)
  lw    $a1, 0x10($v1)
.Ljp7F049404:
  move  $a0, $s4
  move  $a2, $zero
  beql  $a1, $zero, .Ljp7F0495CC
   lw    $t4, 8($s4)
  jal   sub_GAME_7F06C660
   lw    $s2, 4($a1)
  move  $s0, $v0
  move  $a0, $s2
  jal   init_something_copy_posdata_to_it
   move  $a1, $v0
  lw    $a0, 0x70($sp)
  jal   sub_GAME_7F058098
   move  $a1, $s0
  b     .Ljp7F0495CC
   lw    $t4, 8($s4)
.Ljp7F049440:
  bne   $s0, $v0, .Ljp7F0495C8
   addiu $a1, $s2, 0x40
  lw    $t6, 8($s4)
  lw    $v1, 8($t6)
  lw    $t7, 0xc($v1)
  lw    $t2, 4($v1)
  lw    $t4, 4($t7)
  lw    $s0, 4($t2)
  sw    $t4, 0x168($sp)
  lw    $t5, 0x10($v1)
  lw    $t9, 4($t5)
  sw    $t9, 0x164($sp)
  lw    $t0, 8($v1)
  lw    $t8, 4($t0)
  sw    $t8, 0x160($sp)
  lw    $t1, 0x18($v1)
  lw    $t3, 4($t1)
  sw    $t3, 0x15c($sp)
  lwc1  $f14, 0xc8($s1)
  neg.s $f14, $f14
  c.lt.s $f14, $f22
  nop   
  bc1fl .Ljp7F0494A8
   lwc1  $f12, 0xcc($s1)
  add.s $f14, $f14, $f20
  lwc1  $f12, 0xcc($s1)
.Ljp7F0494A8:
  neg.s $f12, $f12
  c.lt.s $f12, $f22
  nop   
  bc1fl .Ljp7F0494C4
   sw    $a1, 0x70($sp)
  add.s $f12, $f12, $f20
  sw    $a1, 0x70($sp)
.Ljp7F0494C4:
  jal   sub_GAME_7F0585FC
   swc1  $f14, 0x158($sp)
  move  $a0, $s0
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   lw    $a1, 0x70($sp)
  move  $a0, $s2
  jal   sub_GAME_7F058098
   lw    $a1, 0x70($sp)
  addiu $a1, $s2, 0xc0
  lwc1  $f12, 0x158($sp)
  jal   sub_GAME_7F058570
   sw    $a1, 0x78($sp)
  lw    $a0, 0x168($sp)
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   lw    $a1, 0x78($sp)
  lw    $a0, 0x70($sp)
  jal   sub_GAME_7F058098
   lw    $a1, 0x78($sp)
  lui   $at, %hi(D_80052B70) # $at, 0x8005
  addiu $s0, $s2, 0x100
  move  $a1, $s0
  jal   sub_GAME_7F0585FC
   lwc1  $f12, %lo(D_80052B70)($at)
  lw    $a0, 0x164($sp)
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   move  $a1, $s0
  lw    $a0, 0x78($sp)
  jal   sub_GAME_7F058098
   move  $a1, $s0
  addiu $a1, $s2, 0x80
  sw    $a1, 0x6c($sp)
  jal   init_something_copy_posdata_to_it
   lw    $a0, 0x160($sp)
  lw    $a0, 0x70($sp)
  jal   sub_GAME_7F058098
   lw    $a1, 0x6c($sp)
  jal   sub_GAME_7F078444
   nop   
  addiu $s0, $sp, 0x170
  move  $a2, $s0
  move  $a0, $v0
  jal   sub_GAME_7F05818C
   lw    $a1, 0x70($sp)
  lw    $a0, 0x15c($sp)
  move  $a1, $s0
  addiu $a2, $s1, 0x84
  jal   sub_GAME_7F03F540
   addiu $a3, $s1, 0x80
  lw    $t6, 8($s4)
  lw    $v1, 8($t6)
  lw    $a1, 0x1c($v1)
  beql  $a1, $zero, .Ljp7F0495B4
   lw    $a1, 0x20($v1)
  jal   extract_id_from_object_structure_microcode
   move  $a0, $s4
  lw    $t2, 0xc4($s1)
  sh    $t2, ($v0)
  lw    $t7, 8($s4)
  lw    $v1, 8($t7)
  lw    $a1, 0x20($v1)
.Ljp7F0495B4:
  beql  $a1, $zero, .Ljp7F0495CC
   lw    $t4, 8($s4)
  jal   extract_id_from_object_structure_microcode
   move  $a0, $s4
  sw    $zero, ($v0)
.Ljp7F0495C8:
  lw    $t4, 8($s4)
.Ljp7F0495CC:
  move  $a0, $s4
  jal   sub_GAME_7F06EEA4
   lw    $a1, ($t4)
  lw    $t5, 0xc($s4)
  move  $a0, $s3
  lwc1  $f10, 0x38($t5)
  neg.s $f8, $f10
  jal   handle_thrown_explosive_detonation
   swc1  $f8, 0x18($s3)
  lw    $a0, 0x20($s3)
  beql  $a0, $zero, .Ljp7F049658
   lw    $v1, 0x64($s1)
  lw    $v0, 0x24($a0)
.Ljp7F049600:
  jal   sub_GAME_7F0442DC
   sw    $v0, 0x68c($sp)
  lw    $a0, 0x68c($sp)
  bnezl $a0, .Ljp7F049600
   lw    $v0, 0x24($a0)
  b     .Ljp7F049658
   lw    $v1, 0x64($s1)
.Ljp7F04961C:
  lbu   $t9, 1($s3)
  move  $a0, $s3
  andi  $t0, $t9, 0xfffd
  jal   handle_thrown_explosive_detonation
   sb    $t0, 1($s3)
  lw    $a0, 0x20($s3)
  beql  $a0, $zero, .Ljp7F049658
   lw    $v1, 0x64($s1)
  lw    $v0, 0x24($a0)
.Ljp7F049640:
  jal   sub_GAME_7F04424C
   sw    $v0, 0x68c($sp)
  lw    $a0, 0x68c($sp)
  bnezl $a0, .Ljp7F049640
   lw    $v0, 0x24($a0)
  lw    $v1, 0x64($s1)
.Ljp7F049658:
  li    $at, -257
  addiu $t3, $s3, 8
  andi  $t8, $v1, 0x100
  beqz  $t8, .Ljp7F0496E4
   and   $t1, $v1, $at
  sw    $t1, 0x64($s1)
  jal   get_random_value
   sw    $t3, 0x74($sp)
  mtc1  $v0, $f4
  move  $a0, $s1
  bgez  $v0, .Ljp7F049698
   cvt.s.w $f6, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f10
  nop   
  add.s $f6, $f6, $f10
.Ljp7F049698:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f8
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f10
  mul.s $f4, $f6, $f8
  li    $at, 0x40000000 # 2.000000
  mtc1  $at, $f8
  lw    $t6, 0x64($s1)
  lui   $at, 6
  lw    $a2, 0x74($sp)
  and   $t2, $t6, $at
  mul.s $f6, $f4, $f10
  move  $a3, $zero
  srl   $t7, $t2, 0x11
  sw    $t7, 0x10($sp)
  add.s $f4, $f6, $f8
  mfc1  $a1, $f4
  jal   maybe_detonate_object
   nop   
.Ljp7F0496E4:
  lw    $t4, 0x680($sp)
  beql  $t4, $zero, .Ljp7F049F20
   lw    $t5, 0x688($sp)
  lbu   $v0, 3($s1)
  li    $at, 1
  bnel  $v0, $at, .Ljp7F049714
   li    $at, 13
  jal   sub_GAME_7F053A3C
   lw    $a0, 4($s3)
  b     .Ljp7F049F14
   nop   
  li    $at, 13
.Ljp7F049714:
  bne   $v0, $at, .Ljp7F049F14
   nop   
  jal   get_controls_locked_flag
   nop   
  bnez  $v0, .Ljp7F049F14
   nop   
  lw    $s0, 4($s3)
  sw    $zero, 0x140($sp)
  sw    $zero, 0x13c($sp)
  lw    $t5, 0xd0($s0)
  beql  $t5, $zero, .Ljp7F049ED0
   lw    $t6, 8($s4)
  lw    $t9, 8($s1)
  sll   $t0, $t9, 3
  bltzl $t0, .Ljp7F049ED0
   lw    $t6, 8($s4)
  lw    $t8, 0xac($s0)
  lui   $t0, %hi(global_timer) # $t0, 0x8005
  addiu $t1, $t8, 1
  andi  $t3, $t1, 1
  sw    $t1, 0xac($s0)
  sltiu $t6, $t3, 1
  sw    $t6, 0x140($sp)
  lw    $t2, 8($s4)
  xori  $t5, $t3, 1
  sltiu $t5, $t5, 1
  lw    $t7, 8($t2)
  lw    $t4, 0x14($t7)
  beql  $t4, $zero, .Ljp7F049794
   lw    $t9, 0xc0($s0)
  sw    $t5, 0x13c($sp)
  lw    $t9, 0xc0($s0)
.Ljp7F049794:
  lw    $t0, %lo(global_timer)($t0)
  slt   $at, $t9, $t0
  beql  $at, $zero, .Ljp7F049868
   lw    $t4, 0x140($sp)
  lw    $a0, 0xc4($s0)
  beql  $a0, $zero, .Ljp7F0497CC
   lw    $a0, 0xc8($s0)
  jal   sfxGetArg0Unk3F
   nop   
  beql  $v0, $zero, .Ljp7F0497CC
   lw    $a0, 0xc8($s0)
  jal   sfxDeactivate
   lw    $a0, 0xc4($s0)
  lw    $a0, 0xc8($s0)
.Ljp7F0497CC:
  beql  $a0, $zero, .Ljp7F0497F0
   lw    $t8, 0xc4($s0)
  jal   sfxGetArg0Unk3F
   nop   
  beql  $v0, $zero, .Ljp7F0497F0
   lw    $t8, 0xc4($s0)
  jal   sfxDeactivate
   lw    $a0, 0xc8($s0)
  lw    $t8, 0xc4($s0)
.Ljp7F0497F0:
  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  li    $a1, 253
  bnez  $t8, .Ljp7F049824
   addiu $a2, $s0, 0xc4
  addiu $t1, $s3, 8
  sw    $t1, 0x74($sp)
  jal   play_sfx_a1
   lw    $a0, %lo(ptr_sfx_buf)($a0)
  lw    $a0, 0xc4($s0)
  jal   sub_GAME_7F053A10
   lw    $a1, 0x74($sp)
  b     .Ljp7F049854
   nop   
.Ljp7F049824:
  lw    $t3, 0xc8($s0)
  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
  li    $a1, 253
  bnez  $t3, .Ljp7F049854
   addiu $a2, $s0, 0xc8
  addiu $t6, $s3, 8
  sw    $t6, 0x74($sp)
  jal   play_sfx_a1
   lw    $a0, %lo(ptr_sfx_buf)($a0)
  lw    $a0, 0xc8($s0)
  jal   sub_GAME_7F053A10
   lw    $a1, 0x74($sp)
.Ljp7F049854:
  lui   $t2, %hi(global_timer) # $t2, 0x8005
  lw    $t2, %lo(global_timer)($t2)
  addiu $t7, $t2, 2
  sw    $t7, 0xc0($s0)
  lw    $t4, 0x140($sp)
.Ljp7F049868:
  lw    $t5, 0x13c($sp)
  li    $t9, 1
  bnezl $t4, .Ljp7F049884
   sw    $t9, 0x120($sp)
  beql  $t5, $zero, .Ljp7F049ED0
   lw    $t6, 8($s4)
  sw    $t9, 0x120($sp)
.Ljp7F049884:
  sw    $zero, 0x110($sp)
  lw    $t0, 0x14($s3)
  sw    $t0, 0x10c($sp)
  lw    $t8, 0xac($s0)
  andi  $t1, $t8, 3
  sltiu $t3, $t1, 1
  jal   get_curplayer_positiondata
   sw    $t3, 0x108($sp)
  sw    $v0, 0x104($sp)
  lw    $t6, 8($s4)
  li    $a0, 5
  lw    $v1, 8($t6)
  lw    $t2, 0x1c($v1)
  beql  $t2, $zero, .Ljp7F0498D8
   lbu   $t5, 1($s3)
  lw    $t7, 0xac($s0)
  andi  $t4, $t7, 7
  bnezl $t4, .Ljp7F0498D8
   lbu   $t5, 1($s3)
  li    $a0, 7
  lbu   $t5, 1($s3)
.Ljp7F0498D8:
  andi  $t9, $t5, 2
  beqz  $t9, .Ljp7F049994
   sll   $s1, $a0, 2
  addu  $t0, $v1, $s1
  lw    $a1, ($t0)
  move  $a0, $s4
  beql  $a1, $zero, .Ljp7F049998
   lwc1  $f4, 8($s3)
  jal   sub_GAME_7F06C660
   move  $a2, $zero
  lw    $t8, 8($s4)
  move  $s2, $v0
  lw    $t1, 8($t8)
  addu  $t3, $t1, $s1
  lw    $t6, ($t3)
  lw    $v1, 4($t6)
  lwc1  $f10, ($v1)
  swc1  $f10, 0x130($sp)
  lwc1  $f6, 4($v1)
  swc1  $f6, 0x134($sp)
  lwc1  $f8, 8($v1)
  jal   sub_GAME_7F078444
   swc1  $f8, 0x138($sp)
  addiu $s1, $sp, 0xbc
  move  $a2, $s1
  move  $a0, $v0
  jal   sub_GAME_7F05818C
   move  $a1, $s2
  move  $a0, $s1
  jal   sub_GAME_7F058474
   addiu $a1, $sp, 0x130
  lwc1  $f4, 0x138($sp)
  lw    $a1, 8($s3)
  lw    $a2, 0x10($s3)
  addiu $a0, $sp, 0x10c
  lw    $a3, 0x130($sp)
  jal   sub_GAME_7F0B0BE4
   swc1  $f4, 0x10($sp)
  bnez  $v0, .Ljp7F0499AC
   nop   
  lwc1  $f10, 8($s3)
  swc1  $f10, 0x130($sp)
  lwc1  $f6, 0xc($s3)
  swc1  $f6, 0x134($sp)
  lwc1  $f8, 0x10($s3)
  b     .Ljp7F0499AC
   swc1  $f8, 0x138($sp)
.Ljp7F049994:
  lwc1  $f4, 8($s3)
.Ljp7F049998:
  swc1  $f4, 0x130($sp)
  lwc1  $f10, 0xc($s3)
  swc1  $f10, 0x134($sp)
  lwc1  $f6, 0x10($s3)
  swc1  $f6, 0x138($sp)
.Ljp7F0499AC:
  jal   cosf
   lwc1  $f12, 0x9c($s0)
  lwc1  $f12, 0x90($s0)
  jal   sinf
   swc1  $f0, 0x80($sp)
  lwc1  $f2, 0x80($sp)
  mul.s $f8, $f0, $f2
  swc1  $f8, 0x124($sp)
  jal   sinf
   lwc1  $f12, 0x9c($s0)
  swc1  $f0, 0x128($sp)
  jal   cosf
   lwc1  $f12, 0x9c($s0)
  lwc1  $f12, 0x90($s0)
  jal   cosf
   swc1  $f0, 0x80($sp)
  lwc1  $f2, 0x80($sp)
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f12
  mul.s $f14, $f0, $f2
  lwc1  $f4, 0x124($sp)
  lwc1  $f6, 0x130($sp)
  mul.s $f10, $f4, $f12
  lwc1  $f4, 0x128($sp)
  swc1  $f14, 0x12c($sp)
  add.s $f8, $f10, $f6
  mul.s $f10, $f4, $f12
  lwc1  $f6, 0x134($sp)
  mul.s $f4, $f14, $f12
  swc1  $f8, 0x114($sp)
  add.s $f8, $f10, $f6
  lwc1  $f10, 0x138($sp)
  add.s $f6, $f4, $f10
  swc1  $f8, 0x118($sp)
  jal   sub_GAME_7F0B1CC4
   swc1  $f6, 0x11c($sp)
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f0
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  lwc1  $f8, 0x11c($sp)
  li    $t2, 2
  sw    $t2, 0x14($sp)
  addiu $a0, $sp, 0x10c
  lw    $a1, 0x130($sp)
  lw    $a2, 0x138($sp)
  lw    $a3, 0x114($sp)
  swc1  $f22, 0x20($sp)
  swc1  $f0, 0x18($sp)
  swc1  $f0, 0x1c($sp)
  swc1  $f8, 0x10($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f4, 0x24($sp)
  bnez  $v0, .Ljp7F049AE0
   addiu $a2, $sp, 0x114
  addiu $a0, $sp, 0x130
  jal   sub_GAME_7F02624C
   addiu $a1, $sp, 0x124
  li    $at, 0x41D00000 # 26.000000
  mtc1  $at, $f16
  lwc1  $f6, 0x124($sp)
  lwc1  $f10, 0x114($sp)
  lwc1  $f14, 0x12c($sp)
  mul.s $f8, $f16, $f6
  lwc1  $f6, 0x118($sp)
  lw    $t7, 0x10c($sp)
  sw    $t7, 0x110($sp)
  sub.s $f4, $f10, $f8
  lwc1  $f10, 0x128($sp)
  mul.s $f8, $f16, $f10
  swc1  $f4, 0x114($sp)
  lwc1  $f10, 0x11c($sp)
  sub.s $f4, $f6, $f8
  mul.s $f6, $f16, $f14
  swc1  $f4, 0x118($sp)
  sub.s $f8, $f10, $f6
  swc1  $f8, 0x11c($sp)
.Ljp7F049AE0:
  lui   $t4, %hi(global_timer) # $t4, 0x8005
  lw    $t4, %lo(global_timer)($t4)
  lw    $t5, 0xbc($s0)
  addiu $s1, $sp, 0x114
  lw    $a1, 0x104($sp)
  bne   $t4, $t5, .Ljp7F049C40
   lwc1  $f10, 0x130($sp)
  lwc1  $f4, 8($a1)
  lwc1  $f6, 0xc($a1)
  lwc1  $f8, 0x134($sp)
  sub.s $f0, $f4, $f10
  lwc1  $f4, 0x10($a1)
  swc1  $f10, 0x58($sp)
  sub.s $f2, $f6, $f8
  lwc1  $f6, 0x138($sp)
  sub.s $f12, $f4, $f6
  mul.s $f4, $f0, $f0
  nop   
  mul.s $f10, $f2, $f2
  add.s $f4, $f4, $f10
  mul.s $f10, $f12, $f12
  add.s $f20, $f4, $f10
  lwc1  $f10, 0x58($sp)
  lwc1  $f4, 0x114($sp)
  sub.s $f0, $f4, $f10
  lwc1  $f4, 0x118($sp)
  lwc1  $f10, 0x11c($sp)
  sub.s $f2, $f4, $f8
  mul.s $f4, $f0, $f0
  sub.s $f12, $f10, $f6
  mul.s $f8, $f2, $f2
  add.s $f10, $f4, $f8
  mul.s $f6, $f12, $f12
  add.s $f4, $f10, $f6
  c.le.s $f20, $f4
  nop   
  bc1f  .Ljp7F049C40
   nop   
  jal   check_if_bond_is_invincible
   nop   
  bnezl $v0, .Ljp7F049C44
   lw    $t9, 0x120($sp)
  jal   sqrtf
   mov.s $f12, $f20
  li    $at, 0x43480000 # 200.000000
  mtc1  $at, $f12
  lui   $at, %hi(D_80052B74) # $at, 0x8005
  lwc1  $f8, %lo(D_80052B74)($at)
  lui   $at, %hi(jp_global_timer_delta) # $at, 0x8005
  lwc1  $f10, %lo(jp_global_timer_delta)($at)
  lui   $at, %hi(D_80030B1C) # $at, 0x8003
  c.lt.s $f12, $f0
  mul.s $f6, $f8, $f10
  lwc1  $f4, %lo(D_80030B1C)($at)
  mul.s $f2, $f6, $f4
  bc1fl .Ljp7F049BD4
   lwc1  $f10, 0xd4($s0)
  div.s $f8, $f12, $f0
  mul.s $f2, $f2, $f8
  nop   
  lwc1  $f10, 0xd4($s0)
.Ljp7F049BD4:
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  add.s $f6, $f10, $f2
  swc1  $f6, 0xd4($s0)
  lwc1  $f4, 0xd4($s0)
  c.le.s $f8, $f4
  nop   
  bc1fl .Ljp7F049C44
   lw    $t9, 0x120($sp)
  jal   sub_GAME_7F05DF84
   li    $a0, 14
  li    $at, 0x3E000000 # 0.125000
  mtc1  $at, $f10
  lui   $at, %hi(D_80030B20) # $at, 0x8003
  lwc1  $f4, %lo(D_80030B20)($at)
  mul.s $f6, $f0, $f10
  lwc1  $f14, 0x90($s0)
  li    $a2, -1
  li    $a3, 1
  mul.s $f12, $f6, $f4
  jal   sub_GAME_7F089E4C
   nop   
  jal   check_if_bond_is_invincible
   swc1  $f22, 0xd4($s0)
  beql  $v0, $zero, .Ljp7F049C44
   lw    $t9, 0x120($sp)
  sw    $zero, 0x120($sp)
.Ljp7F049C40:
  lw    $t9, 0x120($sp)
.Ljp7F049C44:
  li    $at, 0x41D00000 # 26.000000
  mtc1  $at, $f16
  beqz  $t9, .Ljp7F049C8C
   lw    $a1, 0x104($sp)
  lw    $t0, 0x110($sp)
  move  $a0, $s1
  li    $a1, 1
  beql  $t0, $zero, .Ljp7F049C78
   li    $a0, 14
  mfc1  $a2, $f16
  jal   sub_GAME_7F0A3E1C
   lbu   $a3, 3($t0)
  li    $a0, 14
.Ljp7F049C78:
  move  $a1, $s1
  jal   recall_joy2_hits_edit_flag
   li    $a2, -1
  b     .Ljp7F049CB4
   lw    $t8, 0x108($sp)
.Ljp7F049C8C:
  lwc1  $f8, 8($a1)
  li    $a0, 14
  li    $a2, -1
  swc1  $f8, 0x114($sp)
  lwc1  $f10, 0xc($a1)
  swc1  $f10, 0x118($sp)
  lwc1  $f6, 0x10($a1)
  jal   recall_joy2_hits_edit_detail_edit_flag
   swc1  $f6, 0x11c($sp)
  lw    $t8, 0x108($sp)
.Ljp7F049CB4:
  lwc1  $f4, 0x130($sp)
  beql  $t8, $zero, .Ljp7F049ED0
   lw    $t6, 8($s4)
  lw    $v1, 0xcc($s0)
  swc1  $f4, 4($v1)
  lwc1  $f8, 0x134($sp)
  lwc1  $f4, 4($v1)
  swc1  $f8, 8($v1)
  lwc1  $f10, 0x138($sp)
  swc1  $f10, 0xc($v1)
  lwc1  $f6, 0x114($sp)
  sub.s $f8, $f6, $f4
  lwc1  $f6, 8($v1)
  swc1  $f8, 0x10($v1)
  lwc1  $f10, 0x118($sp)
  lwc1  $f2, 0x10($v1)
  sub.s $f4, $f10, $f6
  lwc1  $f10, 0xc($v1)
  swc1  $f4, 0x14($v1)
  lwc1  $f8, 0x11c($sp)
  mul.s $f4, $f2, $f2
  lwc1  $f14, 0x14($v1)
  sub.s $f6, $f8, $f10
  mul.s $f8, $f14, $f14
  swc1  $f6, 0x18($v1)
  lwc1  $f0, 0x18($v1)
  sw    $v1, 0x94($sp)
  mul.s $f6, $f0, $f0
  add.s $f10, $f4, $f8
  jal   sqrtf
   add.s $f12, $f6, $f10
  lui   $at, %hi(D_80052B78) # $at, 0x8005
  lwc1  $f14, %lo(D_80052B78)($at)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  lw    $v1, 0x94($sp)
  c.lt.s $f14, $f0
  mov.s $f12, $f0
  div.s $f2, $f4, $f0
  lwc1  $f8, 0x10($v1)
  lwc1  $f10, 0x14($v1)
  li    $at, 0x43FA0000 # 500.000000
  mtc1  $at, $f0
  mul.s $f6, $f8, $f2
  lwc1  $f8, 0x18($v1)
  mul.s $f4, $f10, $f2
  swc1  $f6, 0x10($v1)
  mul.s $f6, $f8, $f2
  swc1  $f4, 0x14($v1)
  bc1f  .Ljp7F049D84
   swc1  $f6, 0x18($v1)
  mov.s $f12, $f14
.Ljp7F049D84:
  c.lt.s $f12, $f0
  li    $t1, 14
  sb    $zero, ($v1)
  sb    $t1, 1($v1)
  bc1f  .Ljp7F049DA0
   swc1  $f12, 0x1c($v1)
  mov.s $f12, $f0
.Ljp7F049DA0:
  lb    $t3, 1($v1)
  li    $at, 22
  bne   $t3, $at, .Ljp7F049E44
   lui   $at, %hi(D_80052B7C) # $at, 0x8005
  lwc1  $f2, %lo(D_80052B7C)($at)
  li    $at, 0x3E800000 # 0.250000
  mtc1  $at, $f10
  lui   $at, %hi(D_80052B80) # $at, 0x8005
  mul.s $f4, $f10, $f12
  swc1  $f4, 0x20($v1)
  lwc1  $f8, %lo(D_80052B80)($at)
  mul.s $f0, $f8, $f12
  c.lt.s $f2, $f0
  swc1  $f0, 0x24($v1)
  bc1fl .Ljp7F049DE8
   sw    $v1, 0x94($sp)
  swc1  $f2, 0x24($v1)
  sw    $v1, 0x94($sp)
.Ljp7F049DE8:
  jal   get_random_value
   swc1  $f12, 0x98($sp)
  mtc1  $v0, $f6
  lw    $v1, 0x94($sp)
  lwc1  $f12, 0x98($sp)
  bgez  $v0, .Ljp7F049E14
   cvt.s.w $f10, $f6
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f4
  nop   
  add.s $f10, $f10, $f4
.Ljp7F049E14:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f8
  lui   $at, %hi(D_80052B84) # $at, 0x8005
  lwc1  $f4, %lo(D_80052B84)($at)
  mul.s $f6, $f10, $f8
  lui   $at, %hi(D_80052B88) # $at, 0x8005
  lwc1  $f8, %lo(D_80052B88)($at)
  mul.s $f10, $f6, $f4
  sub.s $f6, $f8, $f10
  mul.s $f4, $f6, $f12
  b     .Ljp7F049ECC
   swc1  $f4, 0x28($v1)
.Ljp7F049E44:
  lui   $at, %hi(D_80052B8C) # $at, 0x8005
  lwc1  $f8, %lo(D_80052B8C)($at)
  lui   $at, %hi(D_80052B90) # $at, 0x8005
  mul.s $f0, $f8, $f12
  swc1  $f0, 0x20($v1)
  swc1  $f0, 0x24($v1)
  lwc1  $f10, %lo(D_80052B90)($at)
  lui   $at, %hi(D_80052B94) # $at, 0x8005
  c.lt.s $f10, $f0
  nop   
  bc1f  .Ljp7F049E7C
   nop   
  lwc1  $f6, %lo(D_80052B94)($at)
  swc1  $f6, 0x24($v1)
.Ljp7F049E7C:
  jal   get_random_value
   sw    $v1, 0x94($sp)
  mtc1  $v0, $f4
  lw    $v1, 0x94($sp)
  bgez  $v0, .Ljp7F049EA4
   cvt.s.w $f8, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f10
  nop   
  add.s $f8, $f8, $f10
.Ljp7F049EA4:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f6
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  mul.s $f0, $f8, $f6
  lwc1  $f6, 0x20($v1)
  add.s $f4, $f0, $f0
  sub.s $f8, $f4, $f10
  mul.s $f4, $f8, $f6
  swc1  $f4, 0x28($v1)
.Ljp7F049ECC:
  lw    $t6, 8($s4)
.Ljp7F049ED0:
  lw    $v1, 8($t6)
  lw    $a1, 0x14($v1)
  beql  $a1, $zero, .Ljp7F049EFC
   lw    $a1, 0x1c($v1)
  jal   extract_id_from_object_structure_microcode
   move  $a0, $s4
  lw    $t2, 0x140($sp)
  sh    $t2, ($v0)
  lw    $t7, 8($s4)
  lw    $v1, 8($t7)
  lw    $a1, 0x1c($v1)
.Ljp7F049EFC:
  beqz  $a1, .Ljp7F049F14
   nop   
  jal   extract_id_from_object_structure_microcode
   move  $a0, $s4
  lw    $t4, 0x13c($sp)
  sh    $t4, ($v0)
.Ljp7F049F14:
  jal   sub_GAME_7F044200
   move  $a0, $s3
  lw    $t5, 0x688($sp)
.Ljp7F049F20:
  li    $at, 5
  bnel  $t5, $at, .Ljp7F049F34
   lw    $v0, 0x688($sp)
  sw    $zero, 0x14($s3)
  lw    $v0, 0x688($sp)
.Ljp7F049F34:
  lw    $ra, 0x54($sp)
  ldc1  $f20, 0x30($sp)
  ldc1  $f22, 0x38($sp)
  lw    $s0, 0x40($sp)
  lw    $s1, 0x44($sp)
  lw    $s2, 0x48($sp)
  lw    $s3, 0x4c($sp)
  lw    $s4, 0x50($sp)
  jr    $ra
   addiu $sp, $sp, 0x6b0 
");
#endif

#endif



asm(R"
glabel sub_GAME_7F049B58
  addiu $sp, $sp, -0x38
  sw    $ra, 0x34($sp)
  sw    $s2, 0x20($sp)
  move  $s2, $a0
  sw    $s6, 0x30($sp)
  sw    $s5, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s1, 0x1c($sp)
  jal   get_ptr_obj_pos_list_current_entry
   sw    $s0, 0x18($sp)
  beqz  $v0, .L7F049C60
   move  $s0, $v0
  li    $s6, 6
  li    $s5, 13
  li    $s4, 1
  li    $s3, 3
  lbu   $v0, ($s0)
.L7F049BA0:
  move  $a0, $s2
  bne   $s3, $v0, .L7F049BD4
   nop   
  lw    $s1, 4($s0)
  move  $a2, $s4
  jal   sub_GAME_7F061E18
   addiu $a1, $s1, 0x180
  move  $a0, $v0
  addiu $a1, $s1, 0x1ac
  jal   sub_GAME_7F061E18
   move  $a2, $s4
  b     .L7F049C54
   move  $s2, $v0
.L7F049BD4:
  bne   $s4, $v0, .L7F049C04
   nop   
  lw    $v1, 4($s0)
  move  $a0, $s2
  move  $a2, $s4
  lbu   $t6, 3($v1)
  bnel  $s5, $t6, .L7F049C58
   lw    $s0, 0x24($s0)
  jal   sub_GAME_7F061E18
   lw    $a1, 0xcc($v1)
  b     .L7F049C54
   move  $s2, $v0
.L7F049C04:
  bnel  $s6, $v0, .L7F049C58
   lw    $s0, 0x24($s0)
  lw    $t7, 4($s0)
  beql  $t7, $zero, .L7F049C58
   lw    $s0, 0x24($s0)
  jal   sub_GAME_7F09B15C
   move  $a0, $s0
  jal   get_cur_playernum
   move  $s1, $v0
  beq   $v0, $s1, .L7F049C54
   move  $a0, $s2
  lw    $s1, 4($s0)
  move  $a2, $s4
  jal   sub_GAME_7F061E18
   addiu $a1, $s1, 0x180
  move  $a0, $v0
  addiu $a1, $s1, 0x1ac
  jal   sub_GAME_7F061E18
   move  $a2, $s4
  move  $s2, $v0
.L7F049C54:
  lw    $s0, 0x24($s0)
.L7F049C58:
  bnezl $s0, .L7F049BA0
   lbu   $v0, ($s0)
.L7F049C60:
  lw    $ra, 0x34($sp)
  move  $v0, $s2
  lw    $s2, 0x20($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s3, 0x24($sp)
  lw    $s4, 0x28($sp)
  lw    $s5, 0x2c($sp)
  lw    $s6, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x38
");






asm(R"
glabel save_ptr_monitor_ani_code_to_obj_ani_slot
  sw    $a1, ($a0)
  jr    $ra
   sh    $zero, 4($a0)
");






asm(R"
.late_rodata
/*D:80052B98*/
glabel jpt_80052B98
.word def_7F049CC0
.word .L7F049CC8
.word .L7F049CD4
.word .L7F049CE0
.word .L7F049CEC
.word .L7F049CF8
.word .L7F049D04
.word .L7F049D10
.word .L7F049D1C
.word .L7F049D28
.word .L7F049D34
.word .L7F049D40
.word .L7F049D4C
.word .L7F049D58
.word .L7F049D64
.word .L7F049D70
.word .L7F049D7C
.word .L7F049D88
.word .L7F049D94
.word .L7F049DA0
.word .L7F049DAC
.word .L7F049DB8
.word .L7F049DC4
.word .L7F049DD0
.word .L7F049DDC
.word .L7F049DE8
.word .L7F049DF4
.word .L7F049E00
.word .L7F049E0C
.word .L7F049E18
.word .L7F049E24
.word .L7F049E30
.word .L7F049E3C
.word .L7F049E48
.word .L7F049E54
.word .L7F049E60
.word .L7F049E6C
.word .L7F049E78
.word .L7F049E84
.word .L7F049E90
.word .L7F049E9C
.word .L7F049EA8
.word .L7F049EB4
.word .L7F049EC0
.word .L7F049ECC
.word .L7F049ED8
.word .L7F049EE4
.word .L7F049EF0
.word .L7F049EFC
.word .L7F049F08
.word .L7F049F14
.word .L7F049F20

.text
glabel set_ptr_monitor_img_to_obj_ani_slot
  addiu $sp, $sp, -0x18
  lui   $a2, %hi(monitor_animation_microcode)
  sltiu $at, $a1, 0x34
  sw    $ra, 0x14($sp)
  beqz  $at, .L7F049F28
   addiu $a2, %lo(monitor_animation_microcode) # addiu $a2, $a2, 0xb74
  sll   $t6, $a1, 2
  lui   $at, %hi(jpt_80052B98)
  addu  $at, $at, $t6
  lw    $t6, %lo(jpt_80052B98)($at)
  jr    $t6
   nop   
.L7F049CC8:
  lui   $a2, %hi(D_80030C00)
  b     .L7F049F28
   addiu $a2, %lo(D_80030C00) # addiu $a2, $a2, 0xc00
.L7F049CD4:
  lui   $a2, %hi(D_80030E24)
  b     .L7F049F28
   addiu $a2, %lo(D_80030E24) # addiu $a2, $a2, 0xe24
.L7F049CE0:
  lui   $a2, %hi(D_80030F44)
  b     .L7F049F28
   addiu $a2, %lo(D_80030F44) # addiu $a2, $a2, 0xf44
.L7F049CEC:
  lui   $a2, %hi(D_80031018)
  b     .L7F049F28
   addiu $a2, %lo(D_80031018) # addiu $a2, $a2, 0x1018
.L7F049CF8:
  lui   $a2, %hi(D_80031074)
  b     .L7F049F28
   addiu $a2, %lo(D_80031074) # addiu $a2, $a2, 0x1074
.L7F049D04:
  lui   $a2, %hi(D_800310F0)
  b     .L7F049F28
   addiu $a2, %lo(D_800310F0) # addiu $a2, $a2, 0x10f0
.L7F049D10:
  lui   $a2, %hi(D_8003118C)
  b     .L7F049F28
   addiu $a2, %lo(D_8003118C) # addiu $a2, $a2, 0x118c
.L7F049D1C:
  lui   $a2, %hi(D_8003121C)
  b     .L7F049F28
   addiu $a2, %lo(D_8003121C) # addiu $a2, $a2, 0x121c
.L7F049D28:
  lui   $a2, %hi(D_80031248)
  b     .L7F049F28
   addiu $a2, %lo(D_80031248) # addiu $a2, $a2, 0x1248
.L7F049D34:
  lui   $a2, %hi(D_80031274)
  b     .L7F049F28
   addiu $a2, %lo(D_80031274) # addiu $a2, $a2, 0x1274
.L7F049D40:
  lui   $a2, %hi(D_800312F4)
  b     .L7F049F28
   addiu $a2, %lo(D_800312F4) # addiu $a2, $a2, 0x12f4
.L7F049D4C:
  lui   $a2, %hi(D_80031310)
  b     .L7F049F28
   addiu $a2, %lo(D_80031310) # addiu $a2, $a2, 0x1310
.L7F049D58:
  lui   $a2, %hi(D_80031490)
  b     .L7F049F28
   addiu $a2, %lo(D_80031490) # addiu $a2, $a2, 0x1490
.L7F049D64:
  lui   $a2, %hi(D_800314F8)
  b     .L7F049F28
   addiu $a2, %lo(D_800314F8) # addiu $a2, $a2, 0x14f8
.L7F049D70:
  lui   $a2, %hi(D_80030EC8)
  b     .L7F049F28
   addiu $a2, %lo(D_80030EC8) # addiu $a2, $a2, 0xec8
.L7F049D7C:
  lui   $a2, %hi(D_80031360)
  b     .L7F049F28
   addiu $a2, %lo(D_80031360) # addiu $a2, $a2, 0x1360
.L7F049D88:
  lui   $a2, %hi(D_8003156C)
  b     .L7F049F28
   addiu $a2, %lo(D_8003156C) # addiu $a2, $a2, 0x156c
.L7F049D94:
  lui   $a2, %hi(D_800315CC)
  b     .L7F049F28
   addiu $a2, %lo(D_800315CC) # addiu $a2, $a2, 0x15cc
.L7F049DA0:
  lui   $a2, %hi(D_80031848)
  b     .L7F049F28
   addiu $a2, %lo(D_80031848) # addiu $a2, $a2, 0x1848
.L7F049DAC:
  lui   $a2, %hi(D_80031898)
  b     .L7F049F28
   addiu $a2, %lo(D_80031898) # addiu $a2, $a2, 0x1898
.L7F049DB8:
  lui   $a2, %hi(D_800318B8)
  b     .L7F049F28
   addiu $a2, %lo(D_800318B8) # addiu $a2, $a2, 0x18b8
.L7F049DC4:
  lui   $a2, %hi(D_8003191C)
  b     .L7F049F28
   addiu $a2, %lo(D_8003191C) # addiu $a2, $a2, 0x191c
.L7F049DD0:
  lui   $a2, %hi(D_80031950)
  b     .L7F049F28
   addiu $a2, %lo(D_80031950) # addiu $a2, $a2, 0x1950
.L7F049DDC:
  lui   $a2, %hi(D_800319D4)
  b     .L7F049F28
   addiu $a2, %lo(D_800319D4) # addiu $a2, $a2, 0x19d4
.L7F049DE8:
  lui   $a2, %hi(D_800319F0)
  b     .L7F049F28
   addiu $a2, %lo(D_800319F0) # addiu $a2, $a2, 0x19f0
.L7F049DF4:
  lui   $a2, %hi(D_80031A0C)
  b     .L7F049F28
   addiu $a2, %lo(D_80031A0C) # addiu $a2, $a2, 0x1a0c
.L7F049E00:
  lui   $a2, %hi(D_80031A28)
  b     .L7F049F28
   addiu $a2, %lo(D_80031A28) # addiu $a2, $a2, 0x1a28
.L7F049E0C:
  lui   $a2, %hi(D_80031A44)
  b     .L7F049F28
   addiu $a2, %lo(D_80031A44) # addiu $a2, $a2, 0x1a44
.L7F049E18:
  lui   $a2, %hi(D_80031A60)
  b     .L7F049F28
   addiu $a2, %lo(D_80031A60) # addiu $a2, $a2, 0x1a60
.L7F049E24:
  lui   $a2, %hi(D_80031A7C)
  b     .L7F049F28
   addiu $a2, %lo(D_80031A7C) # addiu $a2, $a2, 0x1a7c
.L7F049E30:
  lui   $a2, %hi(D_80031A98)
  b     .L7F049F28
   addiu $a2, %lo(D_80031A98) # addiu $a2, $a2, 0x1a98
.L7F049E3C:
  lui   $a2, %hi(D_80031AB4)
  b     .L7F049F28
   addiu $a2, %lo(D_80031AB4) # addiu $a2, $a2, 0x1ab4
.L7F049E48:
  lui   $a2, %hi(D_80031AD0)
  b     .L7F049F28
   addiu $a2, %lo(D_80031AD0) # addiu $a2, $a2, 0x1ad0
.L7F049E54:
  lui   $a2, %hi(D_80031AEC)
  b     .L7F049F28
   addiu $a2, %lo(D_80031AEC) # addiu $a2, $a2, 0x1aec
.L7F049E60:
  lui   $a2, %hi(D_80031B24)
  b     .L7F049F28
   addiu $a2, %lo(D_80031B24) # addiu $a2, $a2, 0x1b24
.L7F049E6C:
  lui   $a2, %hi(D_80031B38)
  b     .L7F049F28
   addiu $a2, %lo(D_80031B38) # addiu $a2, $a2, 0x1b38
.L7F049E78:
  lui   $a2, %hi(D_80031B4C)
  b     .L7F049F28
   addiu $a2, %lo(D_80031B4C) # addiu $a2, $a2, 0x1b4c
.L7F049E84:
  lui   $a2, %hi(D_80031B60)
  b     .L7F049F28
   addiu $a2, %lo(D_80031B60) # addiu $a2, $a2, 0x1b60
.L7F049E90:
  lui   $a2, %hi(D_80031BB4)
  b     .L7F049F28
   addiu $a2, %lo(D_80031BB4) # addiu $a2, $a2, 0x1bb4
.L7F049E9C:
  lui   $a2, %hi(D_80031BD0)
  b     .L7F049F28
   addiu $a2, %lo(D_80031BD0) # addiu $a2, $a2, 0x1bd0
.L7F049EA8:
  lui   $a2, %hi(D_80031BEC)
  b     .L7F049F28
   addiu $a2, %lo(D_80031BEC) # addiu $a2, $a2, 0x1bec
.L7F049EB4:
  lui   $a2, %hi(D_80031C08)
  b     .L7F049F28
   addiu $a2, %lo(D_80031C08) # addiu $a2, $a2, 0x1c08
.L7F049EC0:
  lui   $a2, %hi(D_80031C80)
  b     .L7F049F28
   addiu $a2, %lo(D_80031C80) # addiu $a2, $a2, 0x1c80
.L7F049ECC:
  lui   $a2, %hi(D_80031D30)
  b     .L7F049F28
   addiu $a2, %lo(D_80031D30) # addiu $a2, $a2, 0x1d30
.L7F049ED8:
  lui   $a2, %hi(D_80031D58)
  b     .L7F049F28
   addiu $a2, %lo(D_80031D58) # addiu $a2, $a2, 0x1d58
.L7F049EE4:
  lui   $a2, %hi(D_80031DA8)
  b     .L7F049F28
   addiu $a2, %lo(D_80031DA8) # addiu $a2, $a2, 0x1da8
.L7F049EF0:
  lui   $a2, %hi(D_80031DF4)
  b     .L7F049F28
   addiu $a2, %lo(D_80031DF4) # addiu $a2, $a2, 0x1df4
.L7F049EFC:
  lui   $a2, %hi(D_80031E40)
  b     .L7F049F28
   addiu $a2, %lo(D_80031E40) # addiu $a2, $a2, 0x1e40
.L7F049F08:
  lui   $a2, %hi(D_80031E78)
  b     .L7F049F28
   addiu $a2, %lo(D_80031E78) # addiu $a2, $a2, 0x1e78
.L7F049F14:
  lui   $a2, %hi(D_80031EB0)
  b     .L7F049F28
   addiu $a2, %lo(D_80031EB0) # addiu $a2, $a2, 0x1eb0
.L7F049F20:
  lui   $a2, %hi(D_80031EE8)
  addiu $a2, %lo(D_80031EE8) # addiu $a2, $a2, 0x1ee8
def_7F049CC0:
.L7F049F28:
  jal   save_ptr_monitor_ani_code_to_obj_ani_slot
   move  $a1, $a2
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");






asm(R"
glabel save_img_index_to_obj_ani_slot
  jr    $ra
   sw    $a1, 8($a0)
");

#ifdef VERSION_US
asm(R"
.late_rodata
glabel D_80052C68
.word 0x40c90fdb /*6.2831855*/
/*D:80052C6C*/
glabel jpt_80052C6C
.word command00_reset_scroll_shift
.word command01_horizontal_scroll
.word command02_vertical_scroll
.word command03_horizontal_pos
.word command04_vertical_pos
.word command05_zoomx
.word command06_zoomy
.word command07_use_image_from_global_monitor_table
.word command08_halt_processing_for_time
.word command09_jump
.word command0A_jump_conditional
.word command0B_restart
.word command0C_break
.word command0D_colour_transition
.word command0E_set_rotation
.word command0F_rotate

glabel D_80052CAC
.word 0x3fc90fdb /*1.5707964*/
glabel D_80052CB0
.word 0x3fb50481 /*1.4141999*/
glabel D_80052CB4
.word 0x3f59999a /*0.85000002*/
glabel D_80052CB8
.word 0x3e19999a /*0.15000001*/
glabel D_80052CBC
.word 0x3e19999a /*0.15000001*/
glabel D_80052CC0
.word 0x3f666666 /*0.89999998*/

.text
glabel process_monitor_animation_microcode
  addiu $sp, $sp, -0xb0
  sw    $s1, 0x44($sp)
  sw    $s0, 0x40($sp)
  move  $s0, $a2
  move  $s1, $a1
  sw    $ra, 0x4c($sp)
  sw    $s2, 0x48($sp)
  sdc1  $f26, 0x38($sp)
  sdc1  $f24, 0x30($sp)
  sdc1  $f22, 0x28($sp)
  sdc1  $f20, 0x20($sp)
  sw    $a0, 0xb0($sp)
  beqz  $a1, .L7F04ABF4
   sw    $a3, 0xbc($sp)
  lhu   $t6, ($a1)
  li    $at, 24
  andi  $t7, $t6, 0xff
  bnel  $t7, $at, .L7F04ABF8
   lw    $ra, 0x4c($sp)
  jal   sub_GAME_7F0BD6C4
   li    $a0, 4
  lw    $t8, 0xbc($sp)
  move  $s2, $v0
  lw    $a0, 0xb0($sp)
  addiu $t9, $t8, 8
  sw    $t9, 0xbc($sp)
  sw    $t8, 0xa8($sp)
  lw    $t0, 4($s1)
  move  $a1, $s1
  jal   extract_id_from_object_structure_microcode
   sw    $t0, 0xa4($sp)
  lui   $at, %hi(D_80052C68)
  lwc1  $f26, %lo(D_80052C68)($at)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f24
  li    $at, 0x3A800000 # 0.000977
  mtc1  $at, $f22
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f2
  mtc1  $zero, $f20
  sw    $v0, 0xa0($sp)
  move  $s1, $zero
  lhu   $v0, 4($s0)
.L7F049FF4:
  lw    $t1, ($s0)
  sll   $t2, $v0, 2
  addu  $v1, $t1, $t2
  lw    $t3, ($v1)
  sltiu $at, $t3, 0x10
  beqz  $at, .L7F04A468
   sll   $t3, $t3, 2
  lui   $at, %hi(jpt_80052C6C)
  addu  $at, $at, $t3
  lw    $t3, %lo(jpt_80052C6C)($at)
  jr    $t3
   nop   
command00_reset_scroll_shift:
  addiu $t4, $v0, 1
  swc1  $f20, 0x40($s0)
  swc1  $f20, 0x54($s0)
  b     .L7F04A468
   sh    $t4, 4($s0)
command01_horizontal_scroll:
  swc1  $f20, 0x3c($s0)
  lw    $t5, 8($v1)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t5, $f4
  bgez  $t5, .L7F04A05C
   cvt.s.w $f6, $f4
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F04A05C:
  div.s $f10, $f24, $f6
  lwc1  $f0, 0x38($s0)
  addiu $t7, $v0, 3
  swc1  $f0, 0x44($s0)
  swc1  $f10, 0x40($s0)
  lw    $t6, 4($v1)
  sh    $t7, 4($s0)
  mtc1  $t6, $f18
  nop   
  cvt.s.w $f4, $f18
  mul.s $f8, $f4, $f22
  add.s $f6, $f0, $f8
  b     .L7F04A468
   swc1  $f6, 0x48($s0)
command02_vertical_scroll:
  swc1  $f20, 0x50($s0)
  lw    $t8, 8($v1)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t8, $f10
  bgez  $t8, .L7F04A0B8
   cvt.s.w $f18, $f10
  mtc1  $at, $f4
  nop   
  add.s $f18, $f18, $f4
.L7F04A0B8:
  div.s $f8, $f24, $f18
  lwc1  $f0, 0x4c($s0)
  addiu $t0, $v0, 3
  swc1  $f0, 0x58($s0)
  swc1  $f8, 0x54($s0)
  lw    $t9, 4($v1)
  sh    $t0, 4($s0)
  mtc1  $t9, $f6
  nop   
  cvt.s.w $f10, $f6
  mul.s $f4, $f10, $f22
  add.s $f18, $f0, $f4
  b     .L7F04A468
   swc1  $f18, 0x5c($s0)
command03_horizontal_pos:
  swc1  $f20, 0x3c($s0)
  lw    $t1, 8($v1)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t1, $f8
  bgez  $t1, .L7F04A114
   cvt.s.w $f6, $f8
  mtc1  $at, $f10
  nop   
  add.s $f6, $f6, $f10
.L7F04A114:
  div.s $f4, $f24, $f6
  lwc1  $f18, 0x38($s0)
  addiu $t3, $v0, 3
  swc1  $f18, 0x44($s0)
  swc1  $f4, 0x40($s0)
  lw    $t2, 4($v1)
  sh    $t3, 4($s0)
  mtc1  $t2, $f8
  nop   
  cvt.s.w $f10, $f8
  mul.s $f6, $f10, $f22
  b     .L7F04A468
   swc1  $f6, 0x48($s0)
command04_vertical_pos:
  swc1  $f20, 0x50($s0)
  lw    $t4, 8($v1)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t4, $f4
  bgez  $t4, .L7F04A16C
   cvt.s.w $f18, $f4
  mtc1  $at, $f8
  nop   
  add.s $f18, $f18, $f8
.L7F04A16C:
  div.s $f10, $f24, $f18
  lwc1  $f6, 0x4c($s0)
  addiu $t6, $v0, 3
  swc1  $f6, 0x58($s0)
  swc1  $f10, 0x54($s0)
  lw    $t5, 4($v1)
  sh    $t6, 4($s0)
  mtc1  $t5, $f4
  nop   
  cvt.s.w $f8, $f4
  mul.s $f18, $f8, $f22
  b     .L7F04A468
   swc1  $f18, 0x5c($s0)
command05_zoomx:
  swc1  $f20, 0x14($s0)
  lw    $t7, 8($v1)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t7, $f10
  bgez  $t7, .L7F04A1C4
   cvt.s.w $f6, $f10
  mtc1  $at, $f4
  nop   
  add.s $f6, $f6, $f4
.L7F04A1C4:
  div.s $f8, $f24, $f6
  lwc1  $f18, 0x10($s0)
  addiu $t9, $v0, 3
  swc1  $f18, 0x1c($s0)
  swc1  $f8, 0x18($s0)
  lw    $t8, 4($v1)
  sh    $t9, 4($s0)
  mtc1  $t8, $f10
  nop   
  cvt.s.w $f4, $f10
  mul.s $f6, $f4, $f22
  b     .L7F04A468
   swc1  $f6, 0x20($s0)
command06_zoomy:
  swc1  $f20, 0x28($s0)
  lw    $t0, 8($v1)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t0, $f8
  bgez  $t0, .L7F04A21C
   cvt.s.w $f18, $f8
  mtc1  $at, $f10
  nop   
  add.s $f18, $f18, $f10
.L7F04A21C:
  div.s $f4, $f24, $f18
  lwc1  $f6, 0x24($s0)
  addiu $t2, $v0, 3
  swc1  $f6, 0x30($s0)
  swc1  $f4, 0x2c($s0)
  lw    $t1, 4($v1)
  sh    $t2, 4($s0)
  mtc1  $t1, $f8
  nop   
  cvt.s.w $f10, $f8
  mul.s $f18, $f10, $f22
  b     .L7F04A468
   swc1  $f18, 0x34($s0)
command07_use_image_from_global_monitor_table:
  move  $a0, $s0
  jal   save_img_index_to_obj_ani_slot
   lw    $a1, 4($v1)
  lhu   $t3, 4($s0)
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f2
  addiu $t4, $t3, 2
  b     .L7F04A468
   sh    $t4, 4($s0)
command08_halt_processing_for_time:
  lh    $v0, 6($s0)
  lui   $t5, %hi(clock_timer) 
  bltzl $v0, .L7F04A2B8
   lw    $t0, 4($v1)
  lw    $t5, %lo(clock_timer)($t5)
  subu  $t6, $v0, $t5
  sh    $t6, 6($s0)
  lh    $t7, 6($s0)
  bltzl $t7, .L7F04A2A8
   lhu   $t8, 4($s0)
  b     .L7F04A468
   li    $s1, 1
  lhu   $t8, 4($s0)
.L7F04A2A8:
  addiu $t9, $t8, 2
  b     .L7F04A468
   sh    $t9, 4($s0)
  lw    $t0, 4($v1)
.L7F04A2B8:
  li    $s1, 1
  b     .L7F04A468
   sh    $t0, 6($s0)
command09_jump:
  move  $a0, $s0
  jal   save_ptr_monitor_ani_code_to_obj_ani_slot
   lw    $a1, 4($v1)
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f2
  b     .L7F04A468
   nop   
command0A_jump_conditional:
  jal   get_random_value
   sw    $v1, 0x94($sp)
  lw    $v1, 0x94($sp)
  srl   $t1, $v0, 0x10
  move  $a0, $s0
  lw    $t2, 8($v1)
  sltu  $at, $t1, $t2
  beql  $at, $zero, .L7F04A320
   lhu   $t3, 4($s0)
  jal   save_ptr_monitor_ani_code_to_obj_ani_slot
   lw    $a1, 4($v1)
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f2
  b     .L7F04A468
   nop   
  lhu   $t3, 4($s0)
.L7F04A320:
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f2
  addiu $t4, $t3, 3
  sh    $t4, 4($s0)
  b     .L7F04A468
   nop   
command0B_restart:
  b     .L7F04A468
   sh    $zero, 4($s0)
command0C_break:
  b     .L7F04A468
   li    $s1, 1
command0D_colour_transition:
  swc1  $f20, 0x6c($s0)
  lw    $t5, 8($v1)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t5, $f4
  bgez  $t5, .L7F04A36C
   cvt.s.w $f6, $f4
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F04A36C:
  div.s $f10, $f24, $f6
  lbu   $t6, 0x60($s0)
  lbu   $t0, 0x63($s0)
  lbu   $t4, 0x66($s0)
  sb    $t6, 0x61($s0)
  lbu   $t8, 0x69($s0)
  swc1  $f10, 0x70($s0)
  lw    $t7, 4($v1)
  sb    $t0, 0x64($s0)
  srl   $t9, $t7, 0x18
  sb    $t9, 0x62($s0)
  lw    $t1, 4($v1)
  sb    $t4, 0x67($s0)
  srl   $t3, $t1, 0x10
  sb    $t3, 0x65($s0)
  lw    $t5, 4($v1)
  sb    $t8, 0x6a($s0)
  addiu $t1, $v0, 3
  srl   $t7, $t5, 8
  sb    $t7, 0x68($s0)
  lw    $t0, 4($v1)
  sh    $t1, 4($s0)
  b     .L7F04A468
   sb    $t0, 0x6b($s0)
command0E_set_rotation:
  lw    $t2, 4($v1)
  addiu $t3, $v0, 2
  sh    $t3, 4($s0)
  mtc1  $t2, $f18
  nop   
  cvt.s.w $f4, $f18
  mul.s $f8, $f4, $f26
  div.s $f6, $f8, $f2
  b     .L7F04A468
   swc1  $f6, 0xc($s0)
command0F_rotate:
  lw    $t4, 4($v1)
  lui   $at, %hi(global_timer_delta)
  lwc1  $f10, %lo(global_timer_delta)($at)
  mtc1  $t4, $f18
  nop   
  cvt.s.w $f4, $f18
  mul.s $f8, $f10, $f4
  lwc1  $f10, 0xc($s0)
  mul.s $f6, $f8, $f26
  div.s $f18, $f6, $f2
  add.s $f4, $f10, $f18
  swc1  $f4, 0xc($s0)
  lwc1  $f12, 0xc($s0)
  c.le.s $f26, $f12
  nop   
  bc1fl .L7F04A448
   c.lt.s $f12, $f20
  sub.s $f8, $f12, $f26
  swc1  $f8, 0xc($s0)
  lwc1  $f12, 0xc($s0)
  c.lt.s $f12, $f20
.L7F04A448:
  nop   
  bc1fl .L7F04A460
   lhu   $t5, 4($s0)
  add.s $f6, $f12, $f26
  swc1  $f6, 0xc($s0)
  lhu   $t5, 4($s0)
.L7F04A460:
  addiu $t6, $t5, 2
  sh    $t6, 4($s0)
def_7F04A01C:
.L7F04A468:
  beql  $s1, $zero, .L7F049FF4
   lhu   $v0, 4($s0)
  lwc1  $f0, 0x18($s0)
  c.lt.s $f20, $f0
  nop   
  bc1f  .L7F04A4DC
   lui   $v0, %hi(global_timer_delta)
  addiu $v0, %lo(global_timer_delta) # addiu $v0, $v0, -0x7c88
  lwc1  $f18, ($v0)
  lwc1  $f10, 0x14($s0)
  mul.s $f4, $f0, $f18
  add.s $f8, $f10, $f4
  swc1  $f8, 0x14($s0)
  lwc1  $f2, 0x14($s0)
  c.lt.s $f2, $f24
  nop   
  bc1fl .L7F04A4D0
   lwc1  $f8, 0x20($s0)
  lwc1  $f0, 0x1c($s0)
  lwc1  $f6, 0x20($s0)
  sub.s $f18, $f6, $f0
  mul.s $f10, $f18, $f2
  add.s $f4, $f0, $f10
  b     .L7F04A4DC
   swc1  $f4, 0x10($s0)
  lwc1  $f8, 0x20($s0)
.L7F04A4D0:
  swc1  $f24, 0x14($s0)
  swc1  $f20, 0x18($s0)
  swc1  $f8, 0x10($s0)
.L7F04A4DC:
  lwc1  $f0, 0x2c($s0)
  lui   $v0, %hi(global_timer_delta)
  addiu $v0, %lo(global_timer_delta) # addiu $v0, $v0, -0x7c88
  c.lt.s $f20, $f0
  nop   
  bc1fl .L7F04A550
   lwc1  $f0, 0x40($s0)
  lwc1  $f18, ($v0)
  lwc1  $f6, 0x28($s0)
  mul.s $f10, $f0, $f18
  add.s $f4, $f6, $f10
  swc1  $f4, 0x28($s0)
  lwc1  $f2, 0x28($s0)
  c.lt.s $f2, $f24
  nop   
  bc1fl .L7F04A540
   lwc1  $f4, 0x34($s0)
  lwc1  $f0, 0x30($s0)
  lwc1  $f8, 0x34($s0)
  sub.s $f18, $f8, $f0
  mul.s $f6, $f18, $f2
  add.s $f10, $f0, $f6
  b     .L7F04A54C
   swc1  $f10, 0x24($s0)
  lwc1  $f4, 0x34($s0)
.L7F04A540:
  swc1  $f24, 0x28($s0)
  swc1  $f20, 0x2c($s0)
  swc1  $f4, 0x24($s0)
.L7F04A54C:
  lwc1  $f0, 0x40($s0)
.L7F04A550:
  c.lt.s $f20, $f0
  nop   
  bc1fl .L7F04A5B8
   lwc1  $f0, 0x54($s0)
  lwc1  $f18, ($v0)
  lwc1  $f8, 0x3c($s0)
  mul.s $f6, $f0, $f18
  add.s $f10, $f8, $f6
  swc1  $f10, 0x3c($s0)
  lwc1  $f2, 0x3c($s0)
  c.lt.s $f2, $f24
  nop   
  bc1fl .L7F04A5A8
   lwc1  $f10, 0x48($s0)
  lwc1  $f0, 0x44($s0)
  lwc1  $f4, 0x48($s0)
  sub.s $f18, $f4, $f0
  mul.s $f8, $f18, $f2
  add.s $f6, $f0, $f8
  b     .L7F04A5B4
   swc1  $f6, 0x38($s0)
  lwc1  $f10, 0x48($s0)
.L7F04A5A8:
  swc1  $f24, 0x3c($s0)
  swc1  $f20, 0x40($s0)
  swc1  $f10, 0x38($s0)
.L7F04A5B4:
  lwc1  $f0, 0x54($s0)
.L7F04A5B8:
  c.lt.s $f20, $f0
  nop   
  bc1fl .L7F04A620
   lwc1  $f2, 0x70($s0)
  lwc1  $f18, ($v0)
  lwc1  $f4, 0x50($s0)
  mul.s $f8, $f0, $f18
  add.s $f6, $f4, $f8
  swc1  $f6, 0x50($s0)
  lwc1  $f2, 0x50($s0)
  c.lt.s $f2, $f24
  nop   
  bc1fl .L7F04A610
   lwc1  $f6, 0x5c($s0)
  lwc1  $f0, 0x58($s0)
  lwc1  $f10, 0x5c($s0)
  sub.s $f18, $f10, $f0
  mul.s $f4, $f18, $f2
  add.s $f8, $f0, $f4
  b     .L7F04A61C
   swc1  $f8, 0x4c($s0)
  lwc1  $f6, 0x5c($s0)
.L7F04A610:
  swc1  $f24, 0x50($s0)
  swc1  $f20, 0x54($s0)
  swc1  $f6, 0x4c($s0)
.L7F04A61C:
  lwc1  $f2, 0x70($s0)
.L7F04A620:
  c.lt.s $f20, $f2
  nop   
  bc1fl .L7F04A728
   lw    $t2, 0xa0($sp)
  lwc1  $f18, ($v0)
  lwc1  $f10, 0x6c($s0)
  mul.s $f4, $f2, $f18
  add.s $f8, $f10, $f4
  swc1  $f8, 0x6c($s0)
  lwc1  $f0, 0x6c($s0)
  c.lt.s $f0, $f24
  nop   
  bc1fl .L7F04A700
   lbu   $t7, 0x62($s0)
  lbu   $v0, 0x61($s0)
  lbu   $t7, 0x62($s0)
  lbu   $v1, 0x64($s0)
  lbu   $t2, 0x65($s0)
  subu  $t8, $t7, $v0
  mtc1  $t8, $f6
  subu  $t3, $t2, $v1
  mtc1  $t3, $f8
  cvt.s.w $f18, $f6
  lbu   $t7, 0x68($s0)
  lbu   $a0, 0x67($s0)
  lbu   $t2, 0x6b($s0)
  lbu   $a1, 0x6a($s0)
  cvt.s.w $f6, $f8
  mul.s $f10, $f18, $f0
  subu  $t8, $t7, $a0
  subu  $t3, $t2, $a1
  mul.s $f18, $f6, $f0
  trunc.w.s $f4, $f10
  trunc.w.s $f10, $f18
  mfc1  $t0, $f4
  mtc1  $t8, $f4
  mfc1  $t5, $f10
  cvt.s.w $f8, $f4
  mtc1  $t3, $f10
  addu  $t1, $v0, $t0
  addu  $t6, $v1, $t5
  sb    $t1, 0x60($s0)
  cvt.s.w $f4, $f10
  mul.s $f6, $f8, $f0
  sb    $t6, 0x63($s0)
  mul.s $f8, $f4, $f0
  trunc.w.s $f18, $f6
  trunc.w.s $f6, $f8
  mfc1  $t0, $f18
  mfc1  $t5, $f6
  addu  $t1, $a0, $t0
  sb    $t1, 0x66($s0)
  addu  $t6, $a1, $t5
  b     .L7F04A724
   sb    $t6, 0x69($s0)
  lbu   $t7, 0x62($s0)
.L7F04A700:
  lbu   $t8, 0x65($s0)
  lbu   $t9, 0x68($s0)
  lbu   $t0, 0x6b($s0)
  swc1  $f24, 0x6c($s0)
  swc1  $f20, 0x70($s0)
  sb    $t7, 0x60($s0)
  sb    $t8, 0x63($s0)
  sb    $t9, 0x66($s0)
  sb    $t0, 0x69($s0)
.L7F04A724:
  lw    $t2, 0xa0($sp)
.L7F04A728:
  lw    $v1, 0xa4($sp)
  lw    $t1, 0xbc($sp)
  sw    $s2, ($t2)
  lui   $t7, %hi(monitorimages) 
  sw    $t1, 4($t2)
  lw    $t3, 8($v1)
  lw    $at, ($t3)
  sw    $at, ($s2)
  lw    $t5, 4($t3)
  sw    $t5, 4($s2)
  lw    $at, 8($t3)
  sw    $at, 8($s2)
  lw    $t5, 0xc($t3)
  sw    $t5, 0xc($s2)
  lw    $t6, 8($v1)
  lw    $at, 0x10($t6)
  sw    $at, 0x10($s2)
  lw    $t8, 0x14($t6)
  sw    $t8, 0x14($s2)
  lw    $at, 0x18($t6)
  sw    $at, 0x18($s2)
  lw    $t8, 0x1c($t6)
  sw    $t8, 0x1c($s2)
  lw    $t9, 8($v1)
  lw    $at, 0x20($t9)
  sw    $at, 0x20($s2)
  lw    $t1, 0x24($t9)
  sw    $t1, 0x24($s2)
  lw    $at, 0x28($t9)
  sw    $at, 0x28($s2)
  lw    $t1, 0x2c($t9)
  sw    $t1, 0x2c($s2)
  lw    $t2, 8($v1)
  lw    $at, 0x30($t2)
  sw    $at, 0x30($s2)
  lw    $t3, 0x34($t2)
  sw    $t3, 0x34($s2)
  lw    $at, 0x38($t2)
  sw    $at, 0x38($s2)
  lw    $t3, 0x3c($t2)
  sw    $t3, 0x3c($s2)
  lw    $v0, 8($s0)
  sltiu $at, $v0, 0x64
  beqz  $at, .L7F04A7F4
   move  $s1, $v0
  sll   $t5, $v0, 2
  lw    $t7, %lo(monitorimages)($t7)
  subu  $t5, $t5, $v0
  sll   $t5, $t5, 2
  b     .L7F04A7F4
   addu  $s1, $t5, $t7
.L7F04A7F4:
  beqz  $s1, .L7F04AA9C
   li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f0
  lwc1  $f18, 0x10($s0)
  lwc1  $f10, 0x24($s0)
  lwc1  $f12, 0xc($s0)
  mul.s $f22, $f18, $f0
  c.eq.s $f20, $f12
  mul.s $f24, $f10, $f0
  mov.s $f14, $f22
  bc1t  .L7F04A874
   mov.s $f16, $f24
  swc1  $f14, 0x54($sp)
  jal   cosf
   swc1  $f16, 0x50($sp)
  lui   $at, %hi(D_80052CB0)
  lwc1  $f26, %lo(D_80052CB0)($at)
  lwc1  $f12, 0xc($s0)
  mul.s $f20, $f0, $f26
  jal   sinf
   nop   
  mul.s $f22, $f22, $f20
  lwc1  $f14, 0x54($sp)
  lwc1  $f16, 0x50($sp)
  mul.s $f2, $f0, $f26
  nop   
  mul.s $f24, $f24, $f2
  nop   
  mul.s $f14, $f14, $f2
  nop   
  mul.s $f16, $f16, $f20
  nop   
.L7F04A874:
  lbu   $t6, 4($s1)
  li    $at, 0x42000000 # 32.000000
  mtc1  $at, $f0
  mtc1  $t6, $f8
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $t6, .L7F04A89C
   cvt.s.w $f6, $f8
  mtc1  $at, $f18
  nop   
  add.s $f6, $f6, $f18
.L7F04A89C:
  lwc1  $f10, 0x38($s0)
  li    $at, 0x4F800000 # 4294967296.000000
  add.s $f4, $f10, $f22
  mul.s $f8, $f6, $f4
  nop   
  mul.s $f18, $f8, $f0
  trunc.w.s $f10, $f18
  mfc1  $t0, $f10
  nop   
  sh    $t0, 8($s2)
  lbu   $t9, 5($s1)
  mtc1  $t9, $f6
  bgez  $t9, .L7F04A8E0
   cvt.s.w $f4, $f6
  mtc1  $at, $f8
  nop   
  add.s $f4, $f4, $f8
.L7F04A8E0:
  lwc1  $f18, 0x4c($s0)
  li    $at, 0x4F800000 # 4294967296.000000
  add.s $f10, $f18, $f24
  mul.s $f6, $f4, $f10
  nop   
  mul.s $f8, $f6, $f0
  trunc.w.s $f18, $f8
  mfc1  $t4, $f18
  nop   
  sh    $t4, 0xa($s2)
  lbu   $t2, 4($s1)
  mtc1  $t2, $f4
  bgez  $t2, .L7F04A924
   cvt.s.w $f10, $f4
  mtc1  $at, $f6
  nop   
  add.s $f10, $f10, $f6
.L7F04A924:
  lwc1  $f8, 0x38($s0)
  li    $at, 0x4F800000 # 4294967296.000000
  sub.s $f18, $f8, $f14
  mul.s $f4, $f10, $f18
  nop   
  mul.s $f6, $f4, $f0
  trunc.w.s $f8, $f6
  mfc1  $t5, $f8
  nop   
  sh    $t5, 0x18($s2)
  lbu   $t7, 5($s1)
  mtc1  $t7, $f10
  bgez  $t7, .L7F04A968
   cvt.s.w $f18, $f10
  mtc1  $at, $f4
  nop   
  add.s $f18, $f18, $f4
.L7F04A968:
  lwc1  $f6, 0x4c($s0)
  li    $at, 0x4F800000 # 4294967296.000000
  add.s $f8, $f6, $f16
  mul.s $f10, $f18, $f8
  nop   
  mul.s $f4, $f10, $f0
  trunc.w.s $f6, $f4
  mfc1  $t8, $f6
  nop   
  sh    $t8, 0x1a($s2)
  lbu   $t0, 4($s1)
  mtc1  $t0, $f18
  bgez  $t0, .L7F04A9AC
   cvt.s.w $f8, $f18
  mtc1  $at, $f10
  nop   
  add.s $f8, $f8, $f10
.L7F04A9AC:
  lwc1  $f4, 0x38($s0)
  li    $at, 0x4F800000 # 4294967296.000000
  sub.s $f6, $f4, $f22
  mul.s $f18, $f8, $f6
  nop   
  mul.s $f10, $f18, $f0
  trunc.w.s $f4, $f10
  mfc1  $t1, $f4
  nop   
  sh    $t1, 0x28($s2)
  lbu   $t4, 5($s1)
  mtc1  $t4, $f8
  bgez  $t4, .L7F04A9F0
   cvt.s.w $f6, $f8
  mtc1  $at, $f18
  nop   
  add.s $f6, $f6, $f18
.L7F04A9F0:
  lwc1  $f10, 0x4c($s0)
  li    $at, 0x4F800000 # 4294967296.000000
  sub.s $f4, $f10, $f24
  mul.s $f8, $f6, $f4
  nop   
  mul.s $f18, $f8, $f0
  trunc.w.s $f10, $f18
  mfc1  $t3, $f10
  nop   
  sh    $t3, 0x2a($s2)
  lbu   $t5, 4($s1)
  mtc1  $t5, $f6
  bgez  $t5, .L7F04AA34
   cvt.s.w $f4, $f6
  mtc1  $at, $f8
  nop   
  add.s $f4, $f4, $f8
.L7F04AA34:
  lwc1  $f18, 0x38($s0)
  li    $at, 0x4F800000 # 4294967296.000000
  add.s $f10, $f18, $f14
  mul.s $f6, $f4, $f10
  nop   
  mul.s $f8, $f6, $f0
  trunc.w.s $f18, $f8
  mfc1  $t6, $f18
  nop   
  sh    $t6, 0x38($s2)
  lbu   $t8, 5($s1)
  mtc1  $t8, $f4
  bgez  $t8, .L7F04AA78
   cvt.s.w $f10, $f4
  mtc1  $at, $f6
  nop   
  add.s $f10, $f10, $f6
.L7F04AA78:
  lwc1  $f8, 0x4c($s0)
  sub.s $f18, $f8, $f16
  mul.s $f4, $f10, $f18
  nop   
  mul.s $f6, $f4, $f0
  trunc.w.s $f8, $f6
  mfc1  $t9, $f8
  nop   
  sh    $t9, 0x3a($s2)
.L7F04AA9C:
  lbu   $v0, 0x60($s0)
  li    $t4, 2
  lui   $t5, 0xb700
  sb    $v0, 0x3c($s2)
  sb    $v0, 0x2c($s2)
  sb    $v0, 0x1c($s2)
  sb    $v0, 0xc($s2)
  lbu   $v0, 0x63($s0)
  li    $t7, 8192
  addiu $a0, $sp, 0xbc
  sb    $v0, 0x3d($s2)
  sb    $v0, 0x2d($s2)
  sb    $v0, 0x1d($s2)
  sb    $v0, 0xd($s2)
  lbu   $v1, 0x66($s0)
  sb    $v1, 0x3e($s2)
  sb    $v1, 0x2e($s2)
  sb    $v1, 0x1e($s2)
  sb    $v1, 0xe($s2)
  lbu   $v0, 0x69($s0)
  sb    $v0, 0x3f($s2)
  sb    $v0, 0x2f($s2)
  sb    $v0, 0x1f($s2)
  sb    $v0, 0xf($s2)
  lbu   $t1, 0x69($s0)
  slti  $at, $t1, 0xff
  beql  $at, $zero, .L7F04AB14
   lw    $t2, 0xbc($sp)
  sw    $t4, 0xc4($sp)
  lw    $t2, 0xbc($sp)
.L7F04AB14:
  li    $t6, 2
  move  $a1, $s1
  addiu $t3, $t2, 8
  sw    $t3, 0xbc($sp)
  sw    $t7, 4($t2)
  sw    $t5, ($t2)
  sw    $t6, 0x10($sp)
  lw    $a3, 0xc0($sp)
  jal   likely_generate_DL_for_image_declaration
   lw    $a2, 0xc4($sp)
  lw    $s0, 0xbc($sp)
  lui   $t9, (0x01020040 >> 16) # lui $t9, 0x102
  ori   $t9, (0x01020040 & 0xFFFF) # ori $t9, $t9, 0x40
  addiu $t0, $s0, 8
  sw    $t0, 0xbc($sp)
  sw    $t9, ($s0)
  lw    $t1, 0xb0($sp)
  jal   osVirtualToPhysical
   lw    $a0, 0xc($t1)
  sw    $v0, 4($s0)
  lw    $s1, 0xbc($sp)
  lui   $t3, (0xBC001006 >> 16) # lui $t3, 0xbc00
  ori   $t3, (0xBC001006 & 0xFFFF) # ori $t3, $t3, 0x1006
  addiu $t2, $s1, 8
  sw    $t2, 0xbc($sp)
  move  $a0, $s2
  jal   osVirtualToPhysical
   sw    $t3, ($s1)
  sw    $v0, 4($s1)
  lw    $t5, 0xbc($sp)
  lui   $t6, (0x04300040 >> 16) # lui $t6, 0x430
  ori   $t6, (0x04300040 & 0xFFFF) # ori $t6, $t6, 0x40
  addiu $t7, $t5, 8
  sw    $t7, 0xbc($sp)
  lui   $t8, 0x400
  sw    $t8, 4($t5)
  sw    $t6, ($t5)
  lw    $t0, 0xbc($sp)
  lui   $t1, (0xB1000032 >> 16) # lui $t1, 0xb100
  ori   $t1, (0xB1000032 & 0xFFFF) # ori $t1, $t1, 0x32
  addiu $t9, $t0, 8
  sw    $t9, 0xbc($sp)
  li    $t4, 8208
  sw    $t4, 4($t0)
  sw    $t1, ($t0)
  lw    $t2, 0xbc($sp)
  lui   $t5, 0xb800
  lui   $t7, 0x601
  addiu $t3, $t2, 8
  sw    $t3, 0xbc($sp)
  sw    $zero, 4($t2)
  sw    $t5, ($t2)
  lw    $a2, 0xa8($sp)
  sw    $t7, ($a2)
  lw    $t6, 0xbc($sp)
  sw    $t6, 4($a2)
.L7F04ABF4:
  lw    $ra, 0x4c($sp)
.L7F04ABF8:
  lw    $v0, 0xbc($sp)
  ldc1  $f20, 0x20($sp)
  ldc1  $f22, 0x28($sp)
  ldc1  $f24, 0x30($sp)
  ldc1  $f26, 0x38($sp)
  lw    $s0, 0x40($sp)
  lw    $s1, 0x44($sp)
  lw    $s2, 0x48($sp)
  jr    $ra
   addiu $sp, $sp, 0xb0
");
#ifdef VERSION_JP
asm(R"
.late_rodata
glabel D_80052C68
.word 0x40c90fdb /*6.2831855*/
/*D:80052C6C*/
glabel jpt_80052C6C
.word command00_reset_scroll_shift
.word command01_horizontal_scroll
.word command02_vertical_scroll
.word command03_horizontal_pos
.word command04_vertical_pos
.word command05_zoomx
.word command06_zoomy
.word command07_use_image_from_global_monitor_table
.word command08_halt_processing_for_time
.word command09_jump
.word command0A_jump_conditional
.word command0B_restart
.word command0C_break
.word command0D_colour_transition
.word command0E_set_rotation
.word command0F_rotate

glabel D_80052CAC
.word 0x3fc90fdb /*1.5707964*/
glabel D_80052CB0
.word 0x3fb50481 /*1.4141999*/
glabel D_80052CB4
.word 0x3f59999a /*0.85000002*/
glabel D_80052CB8
.word 0x3e19999a /*0.15000001*/
glabel D_80052CBC
.word 0x3e19999a /*0.15000001*/
glabel D_80052CC0
.word 0x3f666666 /*0.89999998*/

.text
glabel process_monitor_animation_microcode
  addiu $sp, $sp, -0xb0
  sw    $s1, 0x44($sp)
  sw    $s0, 0x40($sp)
  move  $s0, $a2
  move  $s1, $a1
  sw    $ra, 0x4c($sp)
  sw    $s2, 0x48($sp)
  sdc1  $f26, 0x38($sp)
  sdc1  $f24, 0x30($sp)
  sdc1  $f22, 0x28($sp)
  sdc1  $f20, 0x20($sp)
  sw    $a0, 0xb0($sp)
  beqz  $a1, .L7F04ABF4
   sw    $a3, 0xbc($sp)
  lhu   $t6, ($a1)
  li    $at, 24
  andi  $t7, $t6, 0xff
  bnel  $t7, $at, .L7F04ABF8
   lw    $ra, 0x4c($sp)
  jal   sub_GAME_7F0BD6C4
   li    $a0, 4
  lw    $t8, 0xbc($sp)
  move  $s2, $v0
  lw    $a0, 0xb0($sp)
  addiu $t9, $t8, 8
  sw    $t9, 0xbc($sp)
  sw    $t8, 0xa8($sp)
  lw    $t0, 4($s1)
  move  $a1, $s1
  jal   extract_id_from_object_structure_microcode
   sw    $t0, 0xa4($sp)
  lui   $at, %hi(D_80052C68)
  lwc1  $f26, %lo(D_80052C68)($at)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f24
  li    $at, 0x3A800000 # 0.000977
  mtc1  $at, $f22
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f2
  mtc1  $zero, $f20
  sw    $v0, 0xa0($sp)
  move  $s1, $zero
  lhu   $v0, 4($s0)
.L7F049FF4:
  lw    $t1, ($s0)
  sll   $t2, $v0, 2
  addu  $v1, $t1, $t2
  lw    $t3, ($v1)
  sltiu $at, $t3, 0x10
  beqz  $at, .L7F04A468
   sll   $t3, $t3, 2
  lui   $at, %hi(jpt_80052C6C)
  addu  $at, $at, $t3
  lw    $t3, %lo(jpt_80052C6C)($at)
  jr    $t3
   nop   
command00_reset_scroll_shift:
  addiu $t4, $v0, 1
  swc1  $f20, 0x40($s0)
  swc1  $f20, 0x54($s0)
  b     .L7F04A468
   sh    $t4, 4($s0)
command01_horizontal_scroll:
  swc1  $f20, 0x3c($s0)
  lw    $t5, 8($v1)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t5, $f4
  bgez  $t5, .L7F04A05C
   cvt.s.w $f6, $f4
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F04A05C:
  div.s $f10, $f24, $f6
  lwc1  $f0, 0x38($s0)
  addiu $t7, $v0, 3
  swc1  $f0, 0x44($s0)
  swc1  $f10, 0x40($s0)
  lw    $t6, 4($v1)
  sh    $t7, 4($s0)
  mtc1  $t6, $f18
  nop   
  cvt.s.w $f4, $f18
  mul.s $f8, $f4, $f22
  add.s $f6, $f0, $f8
  b     .L7F04A468
   swc1  $f6, 0x48($s0)
command02_vertical_scroll:
  swc1  $f20, 0x50($s0)
  lw    $t8, 8($v1)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t8, $f10
  bgez  $t8, .L7F04A0B8
   cvt.s.w $f18, $f10
  mtc1  $at, $f4
  nop   
  add.s $f18, $f18, $f4
.L7F04A0B8:
  div.s $f8, $f24, $f18
  lwc1  $f0, 0x4c($s0)
  addiu $t0, $v0, 3
  swc1  $f0, 0x58($s0)
  swc1  $f8, 0x54($s0)
  lw    $t9, 4($v1)
  sh    $t0, 4($s0)
  mtc1  $t9, $f6
  nop   
  cvt.s.w $f10, $f6
  mul.s $f4, $f10, $f22
  add.s $f18, $f0, $f4
  b     .L7F04A468
   swc1  $f18, 0x5c($s0)
command03_horizontal_pos:
  swc1  $f20, 0x3c($s0)
  lw    $t1, 8($v1)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t1, $f8
  bgez  $t1, .L7F04A114
   cvt.s.w $f6, $f8
  mtc1  $at, $f10
  nop   
  add.s $f6, $f6, $f10
.L7F04A114:
  div.s $f4, $f24, $f6
  lwc1  $f18, 0x38($s0)
  addiu $t3, $v0, 3
  swc1  $f18, 0x44($s0)
  swc1  $f4, 0x40($s0)
  lw    $t2, 4($v1)
  sh    $t3, 4($s0)
  mtc1  $t2, $f8
  nop   
  cvt.s.w $f10, $f8
  mul.s $f6, $f10, $f22
  b     .L7F04A468
   swc1  $f6, 0x48($s0)
command04_vertical_pos:
  swc1  $f20, 0x50($s0)
  lw    $t4, 8($v1)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t4, $f4
  bgez  $t4, .L7F04A16C
   cvt.s.w $f18, $f4
  mtc1  $at, $f8
  nop   
  add.s $f18, $f18, $f8
.L7F04A16C:
  div.s $f10, $f24, $f18
  lwc1  $f6, 0x4c($s0)
  addiu $t6, $v0, 3
  swc1  $f6, 0x58($s0)
  swc1  $f10, 0x54($s0)
  lw    $t5, 4($v1)
  sh    $t6, 4($s0)
  mtc1  $t5, $f4
  nop   
  cvt.s.w $f8, $f4
  mul.s $f18, $f8, $f22
  b     .L7F04A468
   swc1  $f18, 0x5c($s0)
command05_zoomx:
  swc1  $f20, 0x14($s0)
  lw    $t7, 8($v1)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t7, $f10
  bgez  $t7, .L7F04A1C4
   cvt.s.w $f6, $f10
  mtc1  $at, $f4
  nop   
  add.s $f6, $f6, $f4
.L7F04A1C4:
  div.s $f8, $f24, $f6
  lwc1  $f18, 0x10($s0)
  addiu $t9, $v0, 3
  swc1  $f18, 0x1c($s0)
  swc1  $f8, 0x18($s0)
  lw    $t8, 4($v1)
  sh    $t9, 4($s0)
  mtc1  $t8, $f10
  nop   
  cvt.s.w $f4, $f10
  mul.s $f6, $f4, $f22
  b     .L7F04A468
   swc1  $f6, 0x20($s0)
command06_zoomy:
  swc1  $f20, 0x28($s0)
  lw    $t0, 8($v1)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t0, $f8
  bgez  $t0, .L7F04A21C
   cvt.s.w $f18, $f8
  mtc1  $at, $f10
  nop   
  add.s $f18, $f18, $f10
.L7F04A21C:
  div.s $f4, $f24, $f18
  lwc1  $f6, 0x24($s0)
  addiu $t2, $v0, 3
  swc1  $f6, 0x30($s0)
  swc1  $f4, 0x2c($s0)
  lw    $t1, 4($v1)
  sh    $t2, 4($s0)
  mtc1  $t1, $f8
  nop   
  cvt.s.w $f10, $f8
  mul.s $f18, $f10, $f22
  b     .L7F04A468
   swc1  $f18, 0x34($s0)
command07_use_image_from_global_monitor_table:
  move  $a0, $s0
  jal   save_img_index_to_obj_ani_slot
   lw    $a1, 4($v1)
  lhu   $t3, 4($s0)
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f2
  addiu $t4, $t3, 2
  b     .L7F04A468
   sh    $t4, 4($s0)
command08_halt_processing_for_time:
  lh    $v0, 6($s0)
  lui   $t5, %hi(clock_timer) 
  bltzl $v0, .L7F04A2B8
   lw    $t0, 4($v1)
  lw    $t5, %lo(clock_timer)($t5)
  subu  $t6, $v0, $t5
  sh    $t6, 6($s0)
  lh    $t7, 6($s0)
  bltzl $t7, .L7F04A2A8
   lhu   $t8, 4($s0)
  b     .L7F04A468
   li    $s1, 1
  lhu   $t8, 4($s0)
.L7F04A2A8:
  addiu $t9, $t8, 2
  b     .L7F04A468
   sh    $t9, 4($s0)
  lw    $t0, 4($v1)
.L7F04A2B8:
  li    $s1, 1
  b     .L7F04A468
   sh    $t0, 6($s0)
command09_jump:
  move  $a0, $s0
  jal   save_ptr_monitor_ani_code_to_obj_ani_slot
   lw    $a1, 4($v1)
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f2
  b     .L7F04A468
   nop   
command0A_jump_conditional:
  jal   get_random_value
   sw    $v1, 0x94($sp)
  lw    $v1, 0x94($sp)
  srl   $t1, $v0, 0x10
  move  $a0, $s0
  lw    $t2, 8($v1)
  sltu  $at, $t1, $t2
  beql  $at, $zero, .L7F04A320
   lhu   $t3, 4($s0)
  jal   save_ptr_monitor_ani_code_to_obj_ani_slot
   lw    $a1, 4($v1)
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f2
  b     .L7F04A468
   nop   
  lhu   $t3, 4($s0)
.L7F04A320:
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f2
  addiu $t4, $t3, 3
  sh    $t4, 4($s0)
  b     .L7F04A468
   nop   
command0B_restart:
  b     .L7F04A468
   sh    $zero, 4($s0)
command0C_break:
  b     .L7F04A468
   li    $s1, 1
command0D_colour_transition:
  swc1  $f20, 0x6c($s0)
  lw    $t5, 8($v1)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t5, $f4
  bgez  $t5, .L7F04A36C
   cvt.s.w $f6, $f4
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F04A36C:
  div.s $f10, $f24, $f6
  lbu   $t6, 0x60($s0)
  lbu   $t0, 0x63($s0)
  lbu   $t4, 0x66($s0)
  sb    $t6, 0x61($s0)
  lbu   $t8, 0x69($s0)
  swc1  $f10, 0x70($s0)
  lw    $t7, 4($v1)
  sb    $t0, 0x64($s0)
  srl   $t9, $t7, 0x18
  sb    $t9, 0x62($s0)
  lw    $t1, 4($v1)
  sb    $t4, 0x67($s0)
  srl   $t3, $t1, 0x10
  sb    $t3, 0x65($s0)
  lw    $t5, 4($v1)
  sb    $t8, 0x6a($s0)
  addiu $t1, $v0, 3
  srl   $t7, $t5, 8
  sb    $t7, 0x68($s0)
  lw    $t0, 4($v1)
  sh    $t1, 4($s0)
  b     .L7F04A468
   sb    $t0, 0x6b($s0)
command0E_set_rotation:
  lw    $t2, 4($v1)
  addiu $t3, $v0, 2
  sh    $t3, 4($s0)
  mtc1  $t2, $f18
  nop   
  cvt.s.w $f4, $f18
  mul.s $f8, $f4, $f26
  div.s $f6, $f8, $f2
  b     .L7F04A468
   swc1  $f6, 0xc($s0)
command0F_rotate:
  lw    $t4, 4($v1)
  lui   $at, %hi(jp_global_timer_delta)
  lwc1  $f10, %lo(jp_global_timer_delta)($at)
  mtc1  $t4, $f18
  nop   
  cvt.s.w $f4, $f18
  mul.s $f8, $f10, $f4
  lwc1  $f10, 0xc($s0)
  mul.s $f6, $f8, $f26
  div.s $f18, $f6, $f2
  add.s $f4, $f10, $f18
  swc1  $f4, 0xc($s0)
  lwc1  $f12, 0xc($s0)
  c.le.s $f26, $f12
  nop   
  bc1fl .L7F04A448
   c.lt.s $f12, $f20
  sub.s $f8, $f12, $f26
  swc1  $f8, 0xc($s0)
  lwc1  $f12, 0xc($s0)
  c.lt.s $f12, $f20
.L7F04A448:
  nop   
  bc1fl .L7F04A460
   lhu   $t5, 4($s0)
  add.s $f6, $f12, $f26
  swc1  $f6, 0xc($s0)
  lhu   $t5, 4($s0)
.L7F04A460:
  addiu $t6, $t5, 2
  sh    $t6, 4($s0)
def_7F04A01C:
.L7F04A468:
  beql  $s1, $zero, .L7F049FF4
   lhu   $v0, 4($s0)
  lwc1  $f0, 0x18($s0)
  c.lt.s $f20, $f0
  nop   
  bc1f  .L7F04A4DC
   lui   $v0, %hi(jp_global_timer_delta)
  addiu $v0, %lo(jp_global_timer_delta) # addiu $v0, $v0, -0x7c88
  lwc1  $f18, ($v0)
  lwc1  $f10, 0x14($s0)
  mul.s $f4, $f0, $f18
  add.s $f8, $f10, $f4
  swc1  $f8, 0x14($s0)
  lwc1  $f2, 0x14($s0)
  c.lt.s $f2, $f24
  nop   
  bc1fl .L7F04A4D0
   lwc1  $f8, 0x20($s0)
  lwc1  $f0, 0x1c($s0)
  lwc1  $f6, 0x20($s0)
  sub.s $f18, $f6, $f0
  mul.s $f10, $f18, $f2
  add.s $f4, $f0, $f10
  b     .L7F04A4DC
   swc1  $f4, 0x10($s0)
  lwc1  $f8, 0x20($s0)
.L7F04A4D0:
  swc1  $f24, 0x14($s0)
  swc1  $f20, 0x18($s0)
  swc1  $f8, 0x10($s0)
.L7F04A4DC:
  lwc1  $f0, 0x2c($s0)
  lui   $v0, %hi(jp_global_timer_delta)
  addiu $v0, %lo(jp_global_timer_delta) # addiu $v0, $v0, -0x7c88
  c.lt.s $f20, $f0
  nop   
  bc1fl .L7F04A550
   lwc1  $f0, 0x40($s0)
  lwc1  $f18, ($v0)
  lwc1  $f6, 0x28($s0)
  mul.s $f10, $f0, $f18
  add.s $f4, $f6, $f10
  swc1  $f4, 0x28($s0)
  lwc1  $f2, 0x28($s0)
  c.lt.s $f2, $f24
  nop   
  bc1fl .L7F04A540
   lwc1  $f4, 0x34($s0)
  lwc1  $f0, 0x30($s0)
  lwc1  $f8, 0x34($s0)
  sub.s $f18, $f8, $f0
  mul.s $f6, $f18, $f2
  add.s $f10, $f0, $f6
  b     .L7F04A54C
   swc1  $f10, 0x24($s0)
  lwc1  $f4, 0x34($s0)
.L7F04A540:
  swc1  $f24, 0x28($s0)
  swc1  $f20, 0x2c($s0)
  swc1  $f4, 0x24($s0)
.L7F04A54C:
  lwc1  $f0, 0x40($s0)
.L7F04A550:
  c.lt.s $f20, $f0
  nop   
  bc1fl .L7F04A5B8
   lwc1  $f0, 0x54($s0)
  lwc1  $f18, ($v0)
  lwc1  $f8, 0x3c($s0)
  mul.s $f6, $f0, $f18
  add.s $f10, $f8, $f6
  swc1  $f10, 0x3c($s0)
  lwc1  $f2, 0x3c($s0)
  c.lt.s $f2, $f24
  nop   
  bc1fl .L7F04A5A8
   lwc1  $f10, 0x48($s0)
  lwc1  $f0, 0x44($s0)
  lwc1  $f4, 0x48($s0)
  sub.s $f18, $f4, $f0
  mul.s $f8, $f18, $f2
  add.s $f6, $f0, $f8
  b     .L7F04A5B4
   swc1  $f6, 0x38($s0)
  lwc1  $f10, 0x48($s0)
.L7F04A5A8:
  swc1  $f24, 0x3c($s0)
  swc1  $f20, 0x40($s0)
  swc1  $f10, 0x38($s0)
.L7F04A5B4:
  lwc1  $f0, 0x54($s0)
.L7F04A5B8:
  c.lt.s $f20, $f0
  nop   
  bc1fl .L7F04A620
   lwc1  $f2, 0x70($s0)
  lwc1  $f18, ($v0)
  lwc1  $f4, 0x50($s0)
  mul.s $f8, $f0, $f18
  add.s $f6, $f4, $f8
  swc1  $f6, 0x50($s0)
  lwc1  $f2, 0x50($s0)
  c.lt.s $f2, $f24
  nop   
  bc1fl .L7F04A610
   lwc1  $f6, 0x5c($s0)
  lwc1  $f0, 0x58($s0)
  lwc1  $f10, 0x5c($s0)
  sub.s $f18, $f10, $f0
  mul.s $f4, $f18, $f2
  add.s $f8, $f0, $f4
  b     .L7F04A61C
   swc1  $f8, 0x4c($s0)
  lwc1  $f6, 0x5c($s0)
.L7F04A610:
  swc1  $f24, 0x50($s0)
  swc1  $f20, 0x54($s0)
  swc1  $f6, 0x4c($s0)
.L7F04A61C:
  lwc1  $f2, 0x70($s0)
.L7F04A620:
  c.lt.s $f20, $f2
  nop   
  bc1fl .L7F04A728
   lw    $t2, 0xa0($sp)
  lwc1  $f18, ($v0)
  lwc1  $f10, 0x6c($s0)
  mul.s $f4, $f2, $f18
  add.s $f8, $f10, $f4
  swc1  $f8, 0x6c($s0)
  lwc1  $f0, 0x6c($s0)
  c.lt.s $f0, $f24
  nop   
  bc1fl .L7F04A700
   lbu   $t7, 0x62($s0)
  lbu   $v0, 0x61($s0)
  lbu   $t7, 0x62($s0)
  lbu   $v1, 0x64($s0)
  lbu   $t2, 0x65($s0)
  subu  $t8, $t7, $v0
  mtc1  $t8, $f6
  subu  $t3, $t2, $v1
  mtc1  $t3, $f8
  cvt.s.w $f18, $f6
  lbu   $t7, 0x68($s0)
  lbu   $a0, 0x67($s0)
  lbu   $t2, 0x6b($s0)
  lbu   $a1, 0x6a($s0)
  cvt.s.w $f6, $f8
  mul.s $f10, $f18, $f0
  subu  $t8, $t7, $a0
  subu  $t3, $t2, $a1
  mul.s $f18, $f6, $f0
  trunc.w.s $f4, $f10
  trunc.w.s $f10, $f18
  mfc1  $t0, $f4
  mtc1  $t8, $f4
  mfc1  $t5, $f10
  cvt.s.w $f8, $f4
  mtc1  $t3, $f10
  addu  $t1, $v0, $t0
  addu  $t6, $v1, $t5
  sb    $t1, 0x60($s0)
  cvt.s.w $f4, $f10
  mul.s $f6, $f8, $f0
  sb    $t6, 0x63($s0)
  mul.s $f8, $f4, $f0
  trunc.w.s $f18, $f6
  trunc.w.s $f6, $f8
  mfc1  $t0, $f18
  mfc1  $t5, $f6
  addu  $t1, $a0, $t0
  sb    $t1, 0x66($s0)
  addu  $t6, $a1, $t5
  b     .L7F04A724
   sb    $t6, 0x69($s0)
  lbu   $t7, 0x62($s0)
.L7F04A700:
  lbu   $t8, 0x65($s0)
  lbu   $t9, 0x68($s0)
  lbu   $t0, 0x6b($s0)
  swc1  $f24, 0x6c($s0)
  swc1  $f20, 0x70($s0)
  sb    $t7, 0x60($s0)
  sb    $t8, 0x63($s0)
  sb    $t9, 0x66($s0)
  sb    $t0, 0x69($s0)
.L7F04A724:
  lw    $t2, 0xa0($sp)
.L7F04A728:
  lw    $v1, 0xa4($sp)
  lw    $t1, 0xbc($sp)
  sw    $s2, ($t2)
  lui   $t7, %hi(monitorimages) 
  sw    $t1, 4($t2)
  lw    $t3, 8($v1)
  lw    $at, ($t3)
  sw    $at, ($s2)
  lw    $t5, 4($t3)
  sw    $t5, 4($s2)
  lw    $at, 8($t3)
  sw    $at, 8($s2)
  lw    $t5, 0xc($t3)
  sw    $t5, 0xc($s2)
  lw    $t6, 8($v1)
  lw    $at, 0x10($t6)
  sw    $at, 0x10($s2)
  lw    $t8, 0x14($t6)
  sw    $t8, 0x14($s2)
  lw    $at, 0x18($t6)
  sw    $at, 0x18($s2)
  lw    $t8, 0x1c($t6)
  sw    $t8, 0x1c($s2)
  lw    $t9, 8($v1)
  lw    $at, 0x20($t9)
  sw    $at, 0x20($s2)
  lw    $t1, 0x24($t9)
  sw    $t1, 0x24($s2)
  lw    $at, 0x28($t9)
  sw    $at, 0x28($s2)
  lw    $t1, 0x2c($t9)
  sw    $t1, 0x2c($s2)
  lw    $t2, 8($v1)
  lw    $at, 0x30($t2)
  sw    $at, 0x30($s2)
  lw    $t3, 0x34($t2)
  sw    $t3, 0x34($s2)
  lw    $at, 0x38($t2)
  sw    $at, 0x38($s2)
  lw    $t3, 0x3c($t2)
  sw    $t3, 0x3c($s2)
  lw    $v0, 8($s0)
  sltiu $at, $v0, 0x64
  beqz  $at, .L7F04A7F4
   move  $s1, $v0
  sll   $t5, $v0, 2
  lw    $t7, %lo(monitorimages)($t7)
  subu  $t5, $t5, $v0
  sll   $t5, $t5, 2
  b     .L7F04A7F4
   addu  $s1, $t5, $t7
.L7F04A7F4:
  beqz  $s1, .L7F04AA9C
   li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f0
  lwc1  $f18, 0x10($s0)
  lwc1  $f10, 0x24($s0)
  lwc1  $f12, 0xc($s0)
  mul.s $f22, $f18, $f0
  c.eq.s $f20, $f12
  mul.s $f24, $f10, $f0
  mov.s $f14, $f22
  bc1t  .L7F04A874
   mov.s $f16, $f24
  swc1  $f14, 0x54($sp)
  jal   cosf
   swc1  $f16, 0x50($sp)
  lui   $at, %hi(D_80052CB0)
  lwc1  $f26, %lo(D_80052CB0)($at)
  lwc1  $f12, 0xc($s0)
  mul.s $f20, $f0, $f26
  jal   sinf
   nop   
  mul.s $f22, $f22, $f20
  lwc1  $f14, 0x54($sp)
  lwc1  $f16, 0x50($sp)
  mul.s $f2, $f0, $f26
  nop   
  mul.s $f24, $f24, $f2
  nop   
  mul.s $f14, $f14, $f2
  nop   
  mul.s $f16, $f16, $f20
  nop   
.L7F04A874:
  lbu   $t6, 4($s1)
  li    $at, 0x42000000 # 32.000000
  mtc1  $at, $f0
  mtc1  $t6, $f8
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $t6, .L7F04A89C
   cvt.s.w $f6, $f8
  mtc1  $at, $f18
  nop   
  add.s $f6, $f6, $f18
.L7F04A89C:
  lwc1  $f10, 0x38($s0)
  li    $at, 0x4F800000 # 4294967296.000000
  add.s $f4, $f10, $f22
  mul.s $f8, $f6, $f4
  nop   
  mul.s $f18, $f8, $f0
  trunc.w.s $f10, $f18
  mfc1  $t0, $f10
  nop   
  sh    $t0, 8($s2)
  lbu   $t9, 5($s1)
  mtc1  $t9, $f6
  bgez  $t9, .L7F04A8E0
   cvt.s.w $f4, $f6
  mtc1  $at, $f8
  nop   
  add.s $f4, $f4, $f8
.L7F04A8E0:
  lwc1  $f18, 0x4c($s0)
  li    $at, 0x4F800000 # 4294967296.000000
  add.s $f10, $f18, $f24
  mul.s $f6, $f4, $f10
  nop   
  mul.s $f8, $f6, $f0
  trunc.w.s $f18, $f8
  mfc1  $t4, $f18
  nop   
  sh    $t4, 0xa($s2)
  lbu   $t2, 4($s1)
  mtc1  $t2, $f4
  bgez  $t2, .L7F04A924
   cvt.s.w $f10, $f4
  mtc1  $at, $f6
  nop   
  add.s $f10, $f10, $f6
.L7F04A924:
  lwc1  $f8, 0x38($s0)
  li    $at, 0x4F800000 # 4294967296.000000
  sub.s $f18, $f8, $f14
  mul.s $f4, $f10, $f18
  nop   
  mul.s $f6, $f4, $f0
  trunc.w.s $f8, $f6
  mfc1  $t5, $f8
  nop   
  sh    $t5, 0x18($s2)
  lbu   $t7, 5($s1)
  mtc1  $t7, $f10
  bgez  $t7, .L7F04A968
   cvt.s.w $f18, $f10
  mtc1  $at, $f4
  nop   
  add.s $f18, $f18, $f4
.L7F04A968:
  lwc1  $f6, 0x4c($s0)
  li    $at, 0x4F800000 # 4294967296.000000
  add.s $f8, $f6, $f16
  mul.s $f10, $f18, $f8
  nop   
  mul.s $f4, $f10, $f0
  trunc.w.s $f6, $f4
  mfc1  $t8, $f6
  nop   
  sh    $t8, 0x1a($s2)
  lbu   $t0, 4($s1)
  mtc1  $t0, $f18
  bgez  $t0, .L7F04A9AC
   cvt.s.w $f8, $f18
  mtc1  $at, $f10
  nop   
  add.s $f8, $f8, $f10
.L7F04A9AC:
  lwc1  $f4, 0x38($s0)
  li    $at, 0x4F800000 # 4294967296.000000
  sub.s $f6, $f4, $f22
  mul.s $f18, $f8, $f6
  nop   
  mul.s $f10, $f18, $f0
  trunc.w.s $f4, $f10
  mfc1  $t1, $f4
  nop   
  sh    $t1, 0x28($s2)
  lbu   $t4, 5($s1)
  mtc1  $t4, $f8
  bgez  $t4, .L7F04A9F0
   cvt.s.w $f6, $f8
  mtc1  $at, $f18
  nop   
  add.s $f6, $f6, $f18
.L7F04A9F0:
  lwc1  $f10, 0x4c($s0)
  li    $at, 0x4F800000 # 4294967296.000000
  sub.s $f4, $f10, $f24
  mul.s $f8, $f6, $f4
  nop   
  mul.s $f18, $f8, $f0
  trunc.w.s $f10, $f18
  mfc1  $t3, $f10
  nop   
  sh    $t3, 0x2a($s2)
  lbu   $t5, 4($s1)
  mtc1  $t5, $f6
  bgez  $t5, .L7F04AA34
   cvt.s.w $f4, $f6
  mtc1  $at, $f8
  nop   
  add.s $f4, $f4, $f8
.L7F04AA34:
  lwc1  $f18, 0x38($s0)
  li    $at, 0x4F800000 # 4294967296.000000
  add.s $f10, $f18, $f14
  mul.s $f6, $f4, $f10
  nop   
  mul.s $f8, $f6, $f0
  trunc.w.s $f18, $f8
  mfc1  $t6, $f18
  nop   
  sh    $t6, 0x38($s2)
  lbu   $t8, 5($s1)
  mtc1  $t8, $f4
  bgez  $t8, .L7F04AA78
   cvt.s.w $f10, $f4
  mtc1  $at, $f6
  nop   
  add.s $f10, $f10, $f6
.L7F04AA78:
  lwc1  $f8, 0x4c($s0)
  sub.s $f18, $f8, $f16
  mul.s $f4, $f10, $f18
  nop   
  mul.s $f6, $f4, $f0
  trunc.w.s $f8, $f6
  mfc1  $t9, $f8
  nop   
  sh    $t9, 0x3a($s2)
.L7F04AA9C:
  lbu   $v0, 0x60($s0)
  li    $t4, 2
  lui   $t5, 0xb700
  sb    $v0, 0x3c($s2)
  sb    $v0, 0x2c($s2)
  sb    $v0, 0x1c($s2)
  sb    $v0, 0xc($s2)
  lbu   $v0, 0x63($s0)
  li    $t7, 8192
  addiu $a0, $sp, 0xbc
  sb    $v0, 0x3d($s2)
  sb    $v0, 0x2d($s2)
  sb    $v0, 0x1d($s2)
  sb    $v0, 0xd($s2)
  lbu   $v1, 0x66($s0)
  sb    $v1, 0x3e($s2)
  sb    $v1, 0x2e($s2)
  sb    $v1, 0x1e($s2)
  sb    $v1, 0xe($s2)
  lbu   $v0, 0x69($s0)
  sb    $v0, 0x3f($s2)
  sb    $v0, 0x2f($s2)
  sb    $v0, 0x1f($s2)
  sb    $v0, 0xf($s2)
  lbu   $t1, 0x69($s0)
  slti  $at, $t1, 0xff
  beql  $at, $zero, .L7F04AB14
   lw    $t2, 0xbc($sp)
  sw    $t4, 0xc4($sp)
  lw    $t2, 0xbc($sp)
.L7F04AB14:
  li    $t6, 2
  move  $a1, $s1
  addiu $t3, $t2, 8
  sw    $t3, 0xbc($sp)
  sw    $t7, 4($t2)
  sw    $t5, ($t2)
  sw    $t6, 0x10($sp)
  lw    $a3, 0xc0($sp)
  jal   likely_generate_DL_for_image_declaration
   lw    $a2, 0xc4($sp)
  lw    $s0, 0xbc($sp)
  lui   $t9, (0x01020040 >> 16) # lui $t9, 0x102
  ori   $t9, (0x01020040 & 0xFFFF) # ori $t9, $t9, 0x40
  addiu $t0, $s0, 8
  sw    $t0, 0xbc($sp)
  sw    $t9, ($s0)
  lw    $t1, 0xb0($sp)
  jal   osVirtualToPhysical
   lw    $a0, 0xc($t1)
  sw    $v0, 4($s0)
  lw    $s1, 0xbc($sp)
  lui   $t3, (0xBC001006 >> 16) # lui $t3, 0xbc00
  ori   $t3, (0xBC001006 & 0xFFFF) # ori $t3, $t3, 0x1006
  addiu $t2, $s1, 8
  sw    $t2, 0xbc($sp)
  move  $a0, $s2
  jal   osVirtualToPhysical
   sw    $t3, ($s1)
  sw    $v0, 4($s1)
  lw    $t5, 0xbc($sp)
  lui   $t6, (0x04300040 >> 16) # lui $t6, 0x430
  ori   $t6, (0x04300040 & 0xFFFF) # ori $t6, $t6, 0x40
  addiu $t7, $t5, 8
  sw    $t7, 0xbc($sp)
  lui   $t8, 0x400
  sw    $t8, 4($t5)
  sw    $t6, ($t5)
  lw    $t0, 0xbc($sp)
  lui   $t1, (0xB1000032 >> 16) # lui $t1, 0xb100
  ori   $t1, (0xB1000032 & 0xFFFF) # ori $t1, $t1, 0x32
  addiu $t9, $t0, 8
  sw    $t9, 0xbc($sp)
  li    $t4, 8208
  sw    $t4, 4($t0)
  sw    $t1, ($t0)
  lw    $t2, 0xbc($sp)
  lui   $t5, 0xb800
  lui   $t7, 0x601
  addiu $t3, $t2, 8
  sw    $t3, 0xbc($sp)
  sw    $zero, 4($t2)
  sw    $t5, ($t2)
  lw    $a2, 0xa8($sp)
  sw    $t7, ($a2)
  lw    $t6, 0xbc($sp)
  sw    $t6, 4($a2)
.L7F04ABF4:
  lw    $ra, 0x4c($sp)
.L7F04ABF8:
  lw    $v0, 0xbc($sp)
  ldc1  $f20, 0x20($sp)
  ldc1  $f22, 0x28($sp)
  ldc1  $f24, 0x30($sp)
  ldc1  $f26, 0x38($sp)
  lw    $s0, 0x40($sp)
  lw    $s1, 0x44($sp)
  lw    $s2, 0x48($sp)
  jr    $ra
   addiu $sp, $sp, 0xb0
");
#endif
#endif





asm(R"
glabel sub_GAME_7F04AC20
  addiu $sp, $sp, -0x78
  sw    $ra, 0x24($sp)
  sw    $s0, 0x20($sp)
  sw    $a0, 0x78($sp)
  sw    $a2, 0x80($sp)
  lbu   $t7, 1($a0)
  move  $s0, $a1
  andi  $t8, $t7, 2
  beql  $t8, $zero, .L7F04B140
   lw    $ra, 0x24($sp)
  lw    $t9, 4($a0)
  sw    $t9, 0x74($sp)
  lw    $t0, 0x14($t9)
  sw    $t0, 0x70($sp)
  lw    $t1, 8($t9)
  andi  $t2, $t1, 0x200
  sltu  $t3, $zero, $t2
  beqz  $t3, .L7F04AC7C
   sw    $t3, 0x28($sp)
  jal   get_BONDdata_field_10E0
   nop   
  sltu  $t4, $zero, $v0
  sw    $t4, 0x28($sp)
.L7F04AC7C:
  lw    $t5, 0x74($sp)
  li    $at, 10
  lw    $a3, 0xc($s0)
  lbu   $v1, 3($t5)
  bnel  $v1, $at, .L7F04AD18
   li    $at, 11
  lw    $t7, 8($s0)
  lw    $a0, 0x70($sp)
  andi  $t8, $t7, 1
  beql  $t8, $zero, .L7F04AE78
   li    $at, 1
  lw    $t0, 0xc($t5)
  lw    $t6, 0x78($sp)
  lw    $t1, 0x74($sp)
  sll   $t9, $t0, 0xf
  bgez  $t9, .L7F04ACC8
   lw    $v0, 4($t6)
  b     .L7F04ACE4
   move  $v1, $zero
.L7F04ACC8:
  lw    $t2, 8($t1)
  li    $v1, 1
  sll   $t3, $t2, 3
  bgez  $t3, .L7F04ACE4
   nop   
  b     .L7F04ACE4
   li    $v1, 8
.L7F04ACE4:
  lw    $t7, 8($a0)
  li    $t6, 1
  addiu $a2, $v0, 0x80
  lw    $t8, 8($t7)
  lw    $a1, ($t8)
  sw    $t6, 0x14($sp)
  jal   process_monitor_animation_microcode
   sw    $v1, 0x10($sp)
  lw    $t5, 0x74($sp)
  move  $a3, $v0
  b     .L7F04AE74
   lbu   $v1, 3($t5)
  li    $at, 11
.L7F04AD18:
  bnel  $v1, $at, .L7F04AE78
   li    $at, 1
  lw    $t0, 8($s0)
  lw    $t2, 0x74($sp)
  lw    $a0, 0x70($sp)
  andi  $t9, $t0, 1
  beql  $t9, $zero, .L7F04AE78
   li    $at, 1
  lw    $t3, 0xc($t2)
  lw    $t1, 0x78($sp)
  lw    $t7, 0x74($sp)
  sll   $t4, $t3, 0xf
  bgez  $t4, .L7F04AD58
   lw    $v0, 4($t1)
  b     .L7F04AD74
   move  $v1, $zero
.L7F04AD58:
  lw    $t8, 8($t7)
  li    $v1, 1
  sll   $t6, $t8, 3
  bgez  $t6, .L7F04AD74
   nop   
  b     .L7F04AD74
   li    $v1, 8
.L7F04AD74:
  lw    $t0, 8($a0)
  li    $t1, 1
  addiu $a2, $v0, 0x80
  lw    $t9, 8($t0)
  lw    $a1, ($t9)
  sw    $v0, 0x58($sp)
  sw    $t1, 0x14($sp)
  jal   process_monitor_animation_microcode
   sw    $v1, 0x10($sp)
  lw    $t2, 0x74($sp)
  move  $a3, $v0
  lw    $t7, 0x74($sp)
  lw    $t3, 0xc($t2)
  lw    $a0, 0x70($sp)
  sll   $t4, $t3, 0xf
  bgezl $t4, .L7F04ADC4
   lw    $t8, 8($t7)
  b     .L7F04ADE0
   move  $v1, $zero
  lw    $t8, 8($t7)
.L7F04ADC4:
  lui   $at, 0x3000
  li    $v1, 1
  and   $t6, $t8, $at
  beqz  $t6, .L7F04ADE0
   nop   
  b     .L7F04ADE0
   li    $v1, 8
.L7F04ADE0:
  lw    $t0, 8($a0)
  lw    $a2, 0x58($sp)
  li    $t1, 1
  lw    $t9, 8($t0)
  addiu $a2, $a2, 0xf4
  lw    $a1, 4($t9)
  sw    $v1, 0x60($sp)
  sw    $t1, 0x14($sp)
  jal   process_monitor_animation_microcode
   sw    $v1, 0x10($sp)
  lw    $a0, 0x70($sp)
  lw    $v1, 0x60($sp)
  lw    $a2, 0x58($sp)
  lw    $t3, 8($a0)
  li    $t7, 1
  move  $a3, $v0
  lw    $t4, 8($t3)
  addiu $a2, $a2, 0x168
  lw    $a1, 8($t4)
  sw    $t7, 0x14($sp)
  jal   process_monitor_animation_microcode
   sw    $v1, 0x10($sp)
  lw    $a0, 0x70($sp)
  lw    $v1, 0x60($sp)
  lw    $a2, 0x58($sp)
  lw    $t6, 8($a0)
  li    $t0, 1
  move  $a3, $v0
  lw    $t5, 8($t6)
  addiu $a2, $a2, 0x1dc
  lw    $a1, 0xc($t5)
  sw    $t0, 0x14($sp)
  jal   process_monitor_animation_microcode
   sw    $v1, 0x10($sp)
  lw    $t9, 0x74($sp)
  move  $a3, $v0
  lbu   $v1, 3($t9)
.L7F04AE74:
  li    $at, 1
.L7F04AE78:
  bne   $v1, $at, .L7F04AEE4
   lw    $a0, 0x74($sp)
  lw    $t1, 0x78($sp)
  move  $v0, $a3
  lui   $t2, 0xb600
  lw    $v1, 4($t1)
  li    $t3, 12288
  sw    $t3, 4($v0)
  sw    $t2, ($v0)
  lhu   $t4, 0x98($v1)
  addiu $a3, $a3, 8
  li    $t8, 2
  andi  $t7, $t4, 8
  beqz  $t7, .L7F04AEBC
   li    $t6, 3
  b     .L7F04AEC0
   sw    $t8, 0x3c($s0)
.L7F04AEBC:
  sw    $t6, 0x3c($s0)
.L7F04AEC0:
  lw    $t5, 0x30($s0)
  li    $at, 9
  bnel  $t5, $at, .L7F04AFF8
   lw    $t9, 0x28($sp)
  lw    $t0, 0x34($s0)
  li    $at, -256
  and   $t9, $t0, $at
  b     .L7F04AFF4
   sw    $t9, 0x34($s0)
.L7F04AEE4:
  jal   sub_GAME_7F04B478
   sw    $a3, 0x64($sp)
  lw    $a3, 0x64($sp)
  beqz  $v0, .L7F04AF30
   move  $a1, $zero
  lw    $v1, 4($v0)
  lw    $t1, 0x74($sp)
  beql  $v1, $zero, .L7F04AF34
   lw    $a0, 0x74($sp)
  lw    $t2, 0x14($t1)
  lhu   $t4, 0x1a($v1)
  lw    $t8, 8($v1)
  lw    $t3, 0x10($t2)
  sll   $t7, $t4, 2
  addu  $v0, $t3, $t7
  lw    $t6, ($v0)
  beql  $t8, $t6, .L7F04AF34
   lw    $a0, 0x74($sp)
  li    $a1, 1
.L7F04AF30:
  lw    $a0, 0x74($sp)
.L7F04AF34:
  sw    $a1, 0x40($sp)
  jal   do_something_if_object_destroyed
   sw    $a3, 0x64($sp)
  lw    $a1, 0x40($sp)
  beqz  $v0, .L7F04AF54
   lw    $a3, 0x64($sp)
  bnez  $a1, .L7F04AF7C
   lw    $a0, 0x74($sp)
.L7F04AF54:
  lw    $t0, 0x30($s0)
  li    $t5, 3
  li    $at, 9
  bne   $t0, $at, .L7F04AFF4
   sw    $t5, 0x3c($s0)
  lw    $t9, 0x34($s0)
  li    $at, -256
  and   $t1, $t9, $at
  b     .L7F04AFF4
   sw    $t1, 0x34($s0)
.L7F04AF7C:
  jal   do_something_if_object_destroyed
   sw    $a3, 0x64($sp)
  lw    $t4, 0x30($s0)
  lw    $a3, 0x64($sp)
  li    $t2, 1
  li    $at, 9
  bne   $t4, $at, .L7F04AFE0
   sw    $t2, 0x3c($s0)
  sll   $v1, $v0, 2
  subu  $v1, $v1, $v0
  sll   $v1, $v1, 3
  addu  $v1, $v1, $v0
  sll   $v1, $v1, 1
  addiu $a0, $v1, 0x64
  slti  $at, $a0, 0x100
  bnezl $at, .L7F04AFC8
   lw    $t3, 0x34($s0)
  li    $a0, 255
  lw    $t3, 0x34($s0)
.L7F04AFC8:
  li    $at, -256
  and   $t7, $t3, $at
  sw    $t7, 0x34($s0)
  or    $t6, $t7, $a0
  b     .L7F04AFF4
   sw    $t6, 0x34($s0)
.L7F04AFE0:
  blezl $v0, .L7F04AFF8
   lw    $t9, 0x28($sp)
  lw    $t5, 0x34($s0)
  ori   $t0, $t5, 0xff00
  sw    $t0, 0x34($s0)
.L7F04AFF4:
  lw    $t9, 0x28($sp)
.L7F04AFF8:
  lui   $t1, (0x01030040 >> 16) # lui $t1, 0x103
  ori   $t1, (0x01030040 & 0xFFFF) # ori $t1, $t1, 0x40
  beqz  $t9, .L7F04B028
   move  $v1, $a3
  addiu $a3, $a3, 8
  sw    $t1, ($v1)
  sw    $a3, 0x64($sp)
  jal   get_BONDdata_field_10E0
   sw    $v1, 0x34($sp)
  lw    $v1, 0x34($sp)
  lw    $a3, 0x64($sp)
  sw    $v0, 4($v1)
.L7F04B028:
  sw    $a3, 0xc($s0)
  lw    $a1, 0x70($sp)
  jal   subdraw
   move  $a0, $s0
  lw    $v1, 0x74($sp)
  lw    $a3, 0xc($s0)
  li    $at, 1
  lbu   $t2, 3($v1)
  lui   $t4, 0xb600
  li    $t3, 12288
  bne   $t2, $at, .L7F04B064
   move  $v0, $a3
  addiu $a3, $a3, 8
  sw    $t4, ($v0)
  sw    $t3, 4($v0)
.L7F04B064:
  lw    $a2, 0x80($sp)
  lbu   $t7, 2($v1)
  li    $t8, 1
  sllv  $t6, $t8, $a2
  and   $t5, $t7, $t6
  beqz  $t5, .L7F04B090
   move  $a0, $a3
  jal   sub_GAME_7F0A1A94
   lw    $a1, 0x78($sp)
  move  $a3, $v0
  lw    $a2, 0x80($sp)
.L7F04B090:
  lw    $t0, 0x28($sp)
  lui   $t9, (0x01030040 >> 16) # lui $t9, 0x103
  ori   $t9, (0x01030040 & 0xFFFF) # ori $t9, $t9, 0x40
  beqz  $t0, .L7F04B0C8
   move  $v1, $a3
  addiu $a3, $a3, 8
  sw    $t9, ($v1)
  sw    $a3, 0x64($sp)
  jal   get_BONDdata_field_10D8
   sw    $v1, 0x2c($sp)
  lw    $v1, 0x2c($sp)
  lw    $a3, 0x64($sp)
  sw    $v0, 4($v1)
  lw    $a2, 0x80($sp)
.L7F04B0C8:
  sw    $a3, 0xc($s0)
  lw    $t1, 0x78($sp)
  lw    $a0, 0x20($t1)
  beqz  $a0, .L7F04B100
   nop   
  lw    $a2, 0x80($sp)
.L7F04B0E0:
  move  $a1, $s0
  jal   sub_GAME_7F04AC20
   sw    $a0, 0x68($sp)
  lw    $a0, 0x68($sp)
  lw    $a0, 0x24($a0)
  bnezl $a0, .L7F04B0E0
   lw    $a2, 0x80($sp)
  lw    $a2, 0x80($sp)
.L7F04B100:
  beqz  $a2, .L7F04B13C
   lw    $t2, 0x28($sp)
  beqz  $t2, .L7F04B12C
   lw    $v0, 0x70($sp)
  lw    $v0, 0x70($sp)
  lw    $t4, 8($v0)
  lw    $a0, 0xc($v0)
  jal   sub_GAME_7F08BEEC
   lh    $a1, 0xe($t4)
  b     .L7F04B140
   lw    $ra, 0x24($sp)
.L7F04B12C:
  lw    $t3, 8($v0)
  lw    $a0, 0xc($v0)
  jal   sub_GAME_7F08BD48
   lh    $a1, 0xe($t3)
.L7F04B13C:
  lw    $ra, 0x24($sp)
.L7F04B140:
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0x78
  jr    $ra
   nop   
");






asm(R"
glabel sub_GAME_7F04B150
  addiu $sp, $sp, -0xc0
  lui   $t7, %hi(D_80031FD0) 
  sw    $ra, 0x24($sp)
  sw    $s0, 0x20($sp)
  sw    $a1, 0xc4($sp)
  sw    $a2, 0xc8($sp)
  addiu $t7, %lo(D_80031FD0) # addiu $t7, $t7, 0x1fd0
  lw    $s0, 4($a0)
  addiu $t0, $t7, 0x3c
  addiu $t6, $sp, 0x68
.L7F04B178:
  lw    $at, ($t7)
  addiu $t7, $t7, 0xc
  addiu $t6, $t6, 0xc
  sw    $at, -0xc($t6)
  lw    $at, -8($t7)
  sw    $at, -8($t6)
  lw    $at, -4($t7)
  bne   $t7, $t0, .L7F04B178
   sw    $at, -4($t6)
  lw    $at, ($t7)
  li    $t1, 255
  addiu $a1, $sp, 0xb0
  sw    $at, ($t6)
  sw    $t1, 0x3c($sp)
  jal   if_sky_present_convert_values
   sw    $a0, 0xc0($sp)
  bnez  $v0, .L7F04B1C8
   sw    $v0, 0xac($sp)
  b     .L7F04B464
   lw    $v0, 0xc4($sp)
.L7F04B1C8:
  lbu   $t2, 3($s0)
  li    $at, 47
  beql  $t2, $at, .L7F04B258
   lw    $t5, 0x3c($sp)
  jal   getinstsize
   lw    $a0, 0x14($s0)
  mfc1  $a1, $f0
  jal   sub_GAME_7F054B80
   lw    $a0, 0xc0($sp)
  lw    $t3, 0xc0($sp)
  mov.s $f2, $f0
  lh    $v0, 2($t3)
  blez  $v0, .L7F04B228
   slti  $at, $v0, 0x3c
  beql  $at, $zero, .L7F04B22C
   lui   $at, 0x437f
  mtc1  $v0, $f4
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f12
  cvt.s.w $f6, $f4
  sub.s $f8, $f12, $f6
  div.s $f10, $f8, $f12
  mul.s $f2, $f0, $f10
  nop   
.L7F04B228:
  li    $at, 0x437F0000 # 255.000000
.L7F04B22C:
  mtc1  $at, $f16
  nop   
  mul.s $f18, $f2, $f16
  trunc.w.s $f4, $f18
  mfc1  $v0, $f4
  nop   
  bgtz  $v0, .L7F04B254
   sw    $v0, 0x3c($sp)
  b     .L7F04B464
   lw    $v0, 0xc4($sp)
.L7F04B254:
  lw    $t5, 0x3c($sp)
.L7F04B258:
  lw    $t0, 0xc8($sp)
  lw    $a0, 0xc0($sp)
  slti  $at, $t5, 0xff
  bnez  $at, .L7F04B280
   addiu $a1, $sp, 0x58
  lw    $t9, 0xc($s0)
  lw    $t7, 0xc8($sp)
  sll   $t8, $t9, 0xf
  bgez  $t8, .L7F04B298
   nop   
.L7F04B280:
  bnez  $t0, .L7F04B290
   nop   
  b     .L7F04B464
   lw    $v0, 0xc4($sp)
.L7F04B290:
  b     .L7F04B2A8
   li    $v1, 3
.L7F04B298:
  bnez  $t7, .L7F04B2A8
   li    $v1, 2
  b     .L7F04B2A8
   li    $v1, 1
.L7F04B2A8:
  jal   sub_GAME_7F054A64
   sw    $v1, 0x44($sp)
  blez  $v0, .L7F04B2EC
   lw    $v1, 0x44($sp)
  lw    $t6, 0xc($s0)
  lw    $a0, 0xc4($sp)
  lw    $a1, 0x58($sp)
  sll   $t1, $t6, 5
  bltz  $t1, .L7F04B2EC
   lw    $a2, 0x5c($sp)
  lwc1  $f6, 0x64($sp)
  lw    $a3, 0x60($sp)
  sw    $v1, 0x44($sp)
  jal   sub_GAME_7F0B4FF4
   swc1  $f6, 0x10($sp)
  b     .L7F04B2FC
   lw    $v1, 0x44($sp)
.L7F04B2EC:
  lw    $a0, 0xc4($sp)
  jal   sub_GAME_7F0B4FB4
   sw    $v1, 0x44($sp)
  lw    $v1, 0x44($sp)
.L7F04B2FC:
  sw    $v1, 0x70($sp)
  lw    $t2, 0xc($s0)
  lw    $t5, 0x3c($sp)
  lui   $at, 1
  and   $t3, $t2, $at
  sltiu $t4, $t3, 1
  slti  $at, $t5, 0xff
  sw    $t4, 0x6c($sp)
  beqz  $at, .L7F04B334
   sw    $v0, 0x74($sp)
  li    $t9, 5
  sw    $t9, 0x98($sp)
  b     .L7F04B38C
   sw    $t5, 0x9c($sp)
.L7F04B334:
  li    $t8, 9
  sw    $t8, 0x98($sp)
  lbu   $v0, 3($s0)
  li    $at, 47
  bnel  $v0, $at, .L7F04B360
   li    $at, 1
  lw    $t0, 0x88($s0)
  sll   $t7, $t0, 8
  b     .L7F04B38C
   sw    $t7, 0x9c($sp)
  li    $at, 1
.L7F04B360:
  bnel  $v0, $at, .L7F04B38C
   sw    $zero, 0x9c($sp)
  lhu   $t6, 0x98($s0)
  andi  $t1, $t6, 2
  beql  $t1, $zero, .L7F04B38C
   sw    $zero, 0x9c($sp)
  lh    $t2, 0xbe($s0)
  sll   $t3, $t2, 8
  b     .L7F04B38C
   sw    $t3, 0x9c($sp)
  sw    $zero, 0x9c($sp)
.L7F04B38C:
  jal   sub_GAME_7F03FF60
   move  $a0, $s0
  sll   $t4, $v0, 2
  addu  $t4, $t4, $v0
  sll   $t4, $t4, 2
  addu  $t4, $t4, $v0
  li    $t9, 255
  subu  $a0, $t9, $t4
  bgez  $a0, .L7F04B3B8
   addiu $a2, $sp, 0xb0
  move  $a0, $zero
.L7F04B3B8:
  lbu   $t5, 0x78($s0)
  multu $t5, $a0
  sll   $t5, $v0, 4
  subu  $t5, $t5, $v0
  mflo  $t8
  sra   $t0, $t8, 8
  sw    $t0, 0x48($sp)
  lbu   $t7, 0x79($s0)
  multu $t7, $a0
  li    $t7, 255
  mflo  $t6
  sra   $t1, $t6, 8
  sw    $t1, 0x4c($sp)
  lbu   $t2, 0x7a($s0)
  multu $t2, $a0
  addiu $a0, $sp, 0x48
  mflo  $t3
  sra   $t9, $t3, 8
  sw    $t9, 0x50($sp)
  lbu   $t4, 0x7b($s0)
  addu  $t8, $t4, $t5
  slti  $at, $t8, 0x100
  bnez  $at, .L7F04B41C
   sw    $t8, 0x54($sp)
  sw    $t7, 0x54($sp)
.L7F04B41C:
  jal   sub_GAME_7F040384
   lw    $a1, 0xac($sp)
  lw    $t1, 0x48($sp)
  lw    $t6, 0x54($sp)
  lw    $t9, 0x4c($sp)
  lw    $t8, 0x50($sp)
  sll   $t2, $t1, 0x18
  or    $t3, $t6, $t2
  sll   $t4, $t9, 0x10
  or    $t5, $t3, $t4
  sll   $t0, $t8, 8
  or    $t7, $t5, $t0
  sw    $t7, 0xa0($sp)
  lw    $a0, 0xc0($sp)
  addiu $a1, $sp, 0x68
  jal   sub_GAME_7F04AC20
   lw    $a2, 0xc8($sp)
  lw    $v0, 0x74($sp)
.L7F04B464:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0xc0
  jr    $ra
   nop   
");






asm(R"
glabel sub_GAME_7F04B478
  addiu $sp, $sp, -0x30
  sw    $ra, 0x2c($sp)
  sw    $s5, 0x28($sp)
  sw    $s4, 0x24($sp)
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  lw    $t6, 0x14($a0)
  move  $s1, $a0
  li    $s2, 8
  lw    $v0, 8($t6)
  li    $s3, 18
  li    $s4, 23
  lw    $s0, ($v0)
  li    $s5, 24
  beql  $s0, $zero, .L7F04B56C
   move  $v0, $zero
  lhu   $v0, ($s0)
.L7F04B4C4:
  move  $a1, $s0
  andi  $t7, $v0, 0xff
  beq   $t7, $s2, .L7F04B4FC
   nop   
  beq   $t7, $s3, .L7F04B50C
   move  $a1, $s0
  beq   $t7, $s4, .L7F04B51C
   move  $a1, $s0
  beq   $t7, $s5, .L7F04B4F4
   nop   
  b     .L7F04B528
   lw    $v0, 0x14($s0)
.L7F04B4F4:
  b     .L7F04B56C
   move  $v0, $s0
.L7F04B4FC:
  jal   sub_GAME_7F06E970
   lw    $a0, 0x14($s1)
  b     .L7F04B528
   lw    $v0, 0x14($s0)
.L7F04B50C:
  jal   process_12_handle_switch
   lw    $a0, 0x14($s1)
  b     .L7F04B528
   lw    $v0, 0x14($s0)
.L7F04B51C:
  jal   process_17_pointer_to_head
   lw    $a0, 0x14($s1)
  lw    $v0, 0x14($s0)
.L7F04B528:
  beqz  $v0, .L7F04B538
   nop   
  b     .L7F04B560
   move  $s0, $v0
.L7F04B538:
  beqz  $s0, .L7F04B560
   nop   
  lw    $v0, 0xc($s0)
.L7F04B544:
  beql  $v0, $zero, .L7F04B558
   lw    $s0, 8($s0)
  b     .L7F04B560
   move  $s0, $v0
  lw    $s0, 8($s0)
.L7F04B558:
  bnezl $s0, .L7F04B544
   lw    $v0, 0xc($s0)
.L7F04B560:
  bnezl $s0, .L7F04B4C4
   lhu   $v0, ($s0)
  move  $v0, $zero
.L7F04B56C:
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  lw    $s4, 0x24($sp)
  lw    $s5, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x30
");






asm(R"
glabel sub_GAME_7F04B590
  lw    $v0, 4($a0)
  lui   $t6, %hi(prop_console_one_screen_related) 
  addiu $t6, %lo(prop_console_one_screen_related) # addiu $t6, $t6, -0x5f90
  bne   $t6, $v0, .L7F04B5BC
   lui   $t9, %hi(prop_console_four_screen_related)
  lw    $t7, 8($a0)
  lw    $t8, ($t7)
  bne   $a1, $t8, .L7F04B5BC
   nop   
  jr    $ra
   move  $v0, $zero

.L7F04B5BC:
  addiu $t9, $t9, %lo(prop_console_four_screen_related)
  bnel  $t9, $v0, .L7F04B608
   li    $v0, 1
  lw    $v0, 8($a0)
  lw    $t0, ($v0)
  beq   $a1, $t0, .L7F04B5FC
   nop   
  lw    $t1, 4($v0)
  beq   $a1, $t1, .L7F04B5FC
   nop   
  lw    $t2, 8($v0)
  beq   $a1, $t2, .L7F04B5FC
   nop   
  lw    $t3, 0xc($v0)
  bnel  $a1, $t3, .L7F04B608
   li    $v0, 1
.L7F04B5FC:
  jr    $ra
   move  $v0, $zero

  li    $v0, 1
.L7F04B608:
  jr    $ra
   nop   
");






asm(R"
glabel sub_GAME_7F04B610
  addiu $sp, $sp, -0x98
  sw    $s6, 0x30($sp)
  sw    $s4, 0x28($sp)
  sw    $ra, 0x3c($sp)
  sw    $fp, 0x38($sp)
  sw    $s7, 0x34($sp)
  sw    $s5, 0x2c($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  lui   $s4, (0xFFFE7961 >> 16) # lui $s4, 0xfffe
  li    $s6, 0x00010000 # 0.000000
  move  $s0, $a1
  move  $fp, $a0
  lw    $s1, 0x14($a0)
  ori   $s6, (0x0001869F & 0xFFFF) # ori $s6, $s6, 0x869f
  jal   sub_GAME_7F04B478
   ori   $s4, (0xFFFE7961 & 0xFFFF) # ori $s4, $s4, 0x7961
  beqz  $v0, .L7F04BCAC
   move  $a1, $v0
  lw    $s5, 4($v0)
  beql  $s5, $zero, .L7F04BCB0
   lw    $ra, 0x3c($sp)
  lw    $t6, 0x14($fp)
  jal   sub_GAME_7F04B590
   lw    $a0, 8($t6)
  beql  $v0, $zero, .L7F04BCB0
   lw    $ra, 0x3c($sp)
  lhu   $t8, 0x1a($s5)
  lw    $t7, 0x10($s1)
  sll   $t9, $t8, 2
  jal   get_random_value
   addu  $s3, $t7, $t9
  andi  $t0, $v0, 1
  beqz  $t0, .L7F04B6D0
   sll   $t1, $s0, 1
  sw    $t1, 0x40($sp)
  lh    $t2, 4($fp)
  lui   $t6, %hi(object_explosion_details+2)
  sll   $t3, $t2, 3
  subu  $t3, $t3, $t2
  sll   $t3, $t3, 1
  addu  $t5, $t3, $t1
  addu  $t6, $t6, $t5
  lhu   $t6, %lo(object_explosion_details+2)($t6)
  b     .L7F04B6FC
   sw    $t6, 0x78($sp)
.L7F04B6D0:
  lh    $t8, 4($fp)
  sll   $v0, $s0, 1
  lui   $t0, %hi(object_explosion_details+8)
  sll   $t7, $t8, 3
  subu  $t7, $t7, $t8
  sll   $t7, $t7, 1
  addu  $t9, $t7, $v0
  addu  $t0, $t0, $t9
  lhu   $t0, %lo(object_explosion_details+8)($t0)
  sw    $v0, 0x40($sp)
  sw    $t0, 0x78($sp)
.L7F04B6FC:
  jal   get_debug_explosioninfo_flag
   nop   
  bnez  $v0, .L7F04B714
   lw    $t1, 0x78($sp)
  bnez  $t1, .L7F04B73C
   nop   
.L7F04B714:
  jal   get_debug_explosioninfo_flag
   nop   
  jal   get_random_value
   nop   
  jal   get_debug_explosioninfo_flag
   sw    $v0, 0x78($sp)
  beqz  $v0, .L7F04B73C
   lw    $t2, 0x78($sp)
  andi  $t3, $t2, 0xffff
  sw    $t3, 0x78($sp)
.L7F04B73C:
  jal   sub_GAME_7F0A0D90
   lw    $a0, 0x10($fp)
  lh    $t4, 4($fp)
  li    $at, 76
  li    $s7, 1
  bne   $t4, $at, .L7F04B760
   nop   
  b     .L7F04B760
   move  $s7, $zero
.L7F04B760:
  jal   do_something_if_object_destroyed
   move  $a0, $fp
  lh    $a0, 0xc($s5)
  li    $a1, 2827
  lw    $a2, 8($s1)
  jal   sub_GAME_7F09BE4C
   move  $a3, $v0
  beqz  $v0, .L7F04B868
   move  $s0, $v0
  lw    $a0, ($s3)
  lw    $t5, 8($s5)
  beql  $t5, $a0, .L7F04B808
   lh    $t2, 0xc($s5)
  lh    $t6, 0xc($s5)
  move  $s2, $zero
  move  $s1, $zero
  blez  $t6, .L7F04B7F4
   move  $v1, $v0
  lw    $t8, ($s3)
.L7F04B7AC:
  addiu $s2, $s2, 1
  addiu $v1, $v1, 0x10
  addu  $t7, $t8, $s1
  lw    $at, ($t7)
  addiu $s1, $s1, 0x10
  sw    $at, -0x10($v1)
  lw    $t0, 4($t7)
  sw    $t0, -0xc($v1)
  lw    $at, 8($t7)
  sw    $at, -8($v1)
  lw    $t0, 0xc($t7)
  sw    $t0, -4($v1)
  lh    $t1, 0xc($s5)
  slt   $at, $s2, $t1
  bnezl $at, .L7F04B7AC
   lw    $t8, ($s3)
  lw    $a0, ($s3)
  move  $s2, $zero
.L7F04B7F4:
  jal   sub_GAME_7F09C044
   nop   
  b     .L7F04B860
   nop   
  lh    $t2, 0xc($s5)
.L7F04B808:
  move  $s2, $zero
  move  $s1, $zero
  blez  $t2, .L7F04B860
   move  $v1, $v0
  lw    $t3, 8($s5)
.L7F04B81C:
  addiu $s2, $s2, 1
  addiu $v1, $v1, 0x10
  addu  $t4, $t3, $s1
  lw    $at, ($t4)
  addiu $s1, $s1, 0x10
  sw    $at, -0x10($v1)
  lw    $t6, 4($t4)
  sw    $t6, -0xc($v1)
  lw    $at, 8($t4)
  sw    $at, -8($v1)
  lw    $t6, 0xc($t4)
  sw    $t6, -4($v1)
  lh    $t8, 0xc($s5)
  slt   $at, $s2, $t8
  bnezl $at, .L7F04B81C
   lw    $t3, 8($s5)
  move  $s2, $zero
.L7F04B860:
  b     .L7F04B93C
   sw    $s0, ($s3)
.L7F04B868:
  lw    $a0, ($s3)
  lw    $t9, 8($s5)
  beq   $t9, $a0, .L7F04B894
   nop   
  jal   sub_GAME_7F09C044
   nop   
  lw    $t7, 8($s5)
  sw    $t7, ($s3)
  lw    $t0, 0x64($fp)
  ori   $t1, $t0, 4
  sw    $t1, 0x64($fp)
.L7F04B894:
  lui   $at, %hi(D_80052CB4)
  lwc1  $f0, %lo(D_80052CB4)($at)
  lwc1  $f4, 0x28($fp)
  lwc1  $f8, 0x2c($fp)
  lwc1  $f16, 0x30($fp)
  mul.s $f6, $f4, $f0
  nop   
  mul.s $f10, $f8, $f0
  nop   
  mul.s $f18, $f16, $f0
  swc1  $f6, 0x28($fp)
  swc1  $f10, 0x2c($fp)
  beqz  $s7, .L7F04BCAC
   swc1  $f18, 0x30($fp)
  lw    $v0, 0x14($fp)
  lwc1  $f4, 0x14($v0)
  lw    $a0, 8($v0)
  jal   sub_GAME_7F03FFF8
   swc1  $f4, 0x5c($sp)
  move  $s0, $v0
  jal   sub_GAME_7F03E864
   move  $a0, $v0
  lwc1  $f6, 0x5c($sp)
  lui   $at, %hi(D_80052CB8)
  lwc1  $f10, %lo(D_80052CB8)($at)
  mul.s $f8, $f6, $f0
  lw    $v0, 0x10($fp)
  move  $a0, $s0
  lwc1  $f18, 0xc($v0)
  mul.s $f16, $f8, $f10
  add.s $f4, $f18, $f16
  jal   sub_GAME_7F03E864
   swc1  $f4, 0xc($v0)
  lwc1  $f6, 0x5c($sp)
  lui   $at, %hi(D_80052CBC)
  lwc1  $f10, %lo(D_80052CBC)($at)
  mul.s $f8, $f6, $f0
  lwc1  $f16, 0x5c($fp)
  mul.s $f18, $f8, $f10
  add.s $f4, $f16, $f18
  b     .L7F04BCAC
   swc1  $f4, 0x5c($fp)
.L7F04B93C:
  lh    $v0, 4($fp)
  li    $at, 38
  move  $s1, $zero
  beq   $v0, $at, .L7F04B960
   li    $at, 39
  beq   $v0, $at, .L7F04B960
   li    $at, 85
  bne   $v0, $at, .L7F04B968
   li    $t2, 1
.L7F04B960:
  b     .L7F04B96C
   sw    $zero, 0x70($sp)
.L7F04B968:
  sw    $t2, 0x70($sp)
.L7F04B96C:
  lh    $a0, 0xc($s5)
  lw    $a1, 0x40($sp)
  blez  $a0, .L7F04B9B8
   sll   $v1, $a0, 4
  lw    $s0, ($s3)
.L7F04B980:
  lh    $v0, 2($s0)
  addiu $s1, $s1, 0x10
  slt   $at, $v0, $s6
  beql  $at, $zero, .L7F04B99C
   slt   $at, $s4, $v0
  move  $s6, $v0
  slt   $at, $s4, $v0
.L7F04B99C:
  beql  $at, $zero, .L7F04B9AC
   slt   $at, $s1, $v1
  move  $s4, $v0
  slt   $at, $s1, $v1
.L7F04B9AC:
  bnez  $at, .L7F04B980
   addiu $s0, $s0, 0x10
  move  $s2, $zero
.L7F04B9B8:
  addu  $v0, $s6, $s4
  sra   $t3, $v0, 1
  li    $at, 6
  bne   $a1, $at, .L7F04B9E0
   move  $v1, $t3
  subu  $t5, $t3, $s6
  slti  $at, $t5, 0x29
  bnezl $at, .L7F04B9E4
   subu  $v0, $s4, $s6
  addiu $v1, $s6, 0x28
.L7F04B9E0:
  subu  $v0, $s4, $s6
.L7F04B9E4:
  slti  $at, $v0, 0x3d
  bnez  $at, .L7F04BA24
   slti  $at, $a1, 6
  beqz  $at, .L7F04BA08
   addiu $t4, $v0, -0x3c
  lui   $at, %hi(D_80052CC0)
  lwc1  $f6, %lo(D_80052CC0)($at)
  b     .L7F04BA34
   swc1  $f6, 0x68($sp)
.L7F04BA08:
  mtc1  $t4, $f8
  mtc1  $v0, $f16
  cvt.s.w $f10, $f8
  cvt.s.w $f18, $f16
  div.s $f4, $f10, $f18
  b     .L7F04BA34
   swc1  $f4, 0x68($sp)
.L7F04BA24:
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  nop   
  swc1  $f6, 0x68($sp)
.L7F04BA34:
  blezl $a0, .L7F04BCB0
   lw    $ra, 0x3c($sp)
  mtc1  $s6, $f8
  move  $s1, $zero
  sw    $v1, 0x7c($sp)
  cvt.s.w $f16, $f8
  li    $s4, 80
  swc1  $f16, 0x44($sp)
  lw    $t6, 8($s5)
.L7F04BA58:
  lw    $t2, 0x78($sp)
  addu  $v0, $t6, $s1
  lh    $t8, 4($v0)
  lh    $t9, ($v0)
  lh    $t0, 2($v0)
  addu  $t7, $t8, $t9
  addu  $t1, $t7, $t0
  jal   set_rand_val
   addu  $a0, $t1, $t2
  lw    $t3, 0x70($sp)
  move  $s0, $zero
  beqz  $t3, .L7F04BB40
   nop   
  lwc1  $f10, 0x2c($fp)
  mtc1  $zero, $f18
  nop   
  c.le.s $f18, $f10
  nop   
  bc1fl .L7F04BAF8
   lw    $t7, ($s3)
  lw    $t5, ($s3)
  lw    $t8, 0x7c($sp)
  addu  $t4, $t5, $s1
  lh    $t6, 2($t4)
  slt   $at, $t6, $t8
  bnez  $at, .L7F04BADC
   nop   
  beqz  $s7, .L7F04BAD4
   nop   
  b     .L7F04BB40
   li    $s0, 90
.L7F04BAD4:
  b     .L7F04BB40
   li    $s0, 20
.L7F04BADC:
  beqz  $s7, .L7F04BAEC
   nop   
  b     .L7F04BB40
   li    $s0, 20
.L7F04BAEC:
  b     .L7F04BB40
   li    $s0, 90
  lw    $t7, ($s3)
.L7F04BAF8:
  lw    $t9, 0x7c($sp)
  addu  $t0, $t7, $s1
  lh    $t1, 2($t0)
  slt   $at, $t9, $t1
  bnez  $at, .L7F04BB28
   nop   
  beqz  $s7, .L7F04BB20
   nop   
  b     .L7F04BB40
   li    $s0, 90
.L7F04BB20:
  b     .L7F04BB40
   li    $s0, 20
.L7F04BB28:
  beqz  $s7, .L7F04BB38
   nop   
  b     .L7F04BB40
   li    $s0, 20
.L7F04BB38:
  b     .L7F04BB40
   li    $s0, 90
.L7F04BB40:
  jal   get_rand_val
   nop   
  li    $at, 100
  divu  $zero, $v0, $at
  mfhi  $t2
  slt   $at, $t2, $s0
  beqz  $at, .L7F04BB98
   lw    $t2, 0x40($sp)
  lw    $t3, ($s3)
  li    $t0, 255
  addu  $t5, $t3, $s1
  sb    $zero, 0xc($t5)
  lw    $t4, ($s3)
  addu  $t6, $t4, $s1
  sb    $zero, 0xd($t6)
  lw    $t8, ($s3)
  addu  $t7, $t8, $s1
  sb    $zero, 0xe($t7)
  lw    $t9, ($s3)
  addu  $t1, $t9, $s1
  b     .L7F04BBB0
   sb    $t0, 0xf($t1)
.L7F04BB98:
  li    $at, 2
  bnel  $t2, $at, .L7F04BBB4
   lw    $t4, ($s3)
  lw    $t3, ($s3)
  addu  $t5, $t3, $s1
  sb    $zero, 0xf($t5)
.L7F04BBB0:
  lw    $t4, ($s3)
.L7F04BBB4:
  lwc1  $f8, 0x68($sp)
  lwc1  $f10, 0x44($sp)
  addu  $s0, $t4, $s1
  lh    $t6, 2($s0)
  subu  $t8, $t6, $s6
  mtc1  $t8, $f4
  nop   
  cvt.s.w $f6, $f4
  mul.s $f16, $f6, $f8
  add.s $f18, $f16, $f10
  trunc.w.s $f4, $f18
  mfc1  $t9, $f4
  jal   get_rand_val
   sh    $t9, 2($s0)
  divu  $zero, $v0, $s4
  lw    $t0, ($s3)
  mfhi  $t2
  addu  $s0, $t0, $s1
  lh    $t1, ($s0)
  bnez  $s4, .L7F04BC0C
   nop   
  break 7
.L7F04BC0C:
  addu  $t3, $t1, $t2
  addiu $t5, $t3, -0x28
  jal   get_rand_val
   sh    $t5, ($s0)
  divu  $zero, $v0, $s4
  lw    $t4, ($s3)
  mfhi  $t8
  addu  $s0, $t4, $s1
  lh    $t6, 2($s0)
  bnez  $s4, .L7F04BC3C
   nop   
  break 7
.L7F04BC3C:
  addu  $t7, $t6, $t8
  addiu $t9, $t7, -0x28
  jal   get_rand_val
   sh    $t9, 2($s0)
  divu  $zero, $v0, $s4
  lw    $t0, ($s3)
  mfhi  $t2
  addu  $s0, $t0, $s1
  lh    $t1, 4($s0)
  bnez  $s4, .L7F04BC6C
   nop   
  break 7
.L7F04BC6C:
  addu  $t3, $t1, $t2
  addiu $t5, $t3, -0x28
  sh    $t5, 4($s0)
  lw    $t4, ($s3)
  addu  $s0, $t4, $s1
  lh    $t6, 2($s0)
  slt   $at, $t6, $s6
  beql  $at, $zero, .L7F04BC98
   lh    $t8, 0xc($s5)
  sh    $s6, 2($s0)
  lh    $t8, 0xc($s5)
.L7F04BC98:
  addiu $s2, $s2, 1
  addiu $s1, $s1, 0x10
  slt   $at, $s2, $t8
  bnezl $at, .L7F04BA58
   lw    $t6, 8($s5)
.L7F04BCAC:
  lw    $ra, 0x3c($sp)
.L7F04BCB0:
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  lw    $s3, 0x24($sp)
  lw    $s4, 0x28($sp)
  lw    $s5, 0x2c($sp)
  lw    $s6, 0x30($sp)
  lw    $s7, 0x34($sp)
  lw    $fp, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x98
");






asm(R"
.late_rodata
glabel D_80052CC4
.word 0x3fd55555 /*1.6666666*/
glabel D_80052CC8
.word 0x40555555 /*3.3333333*/
glabel D_80052CCC
.word 0x3fd55555 /*1.6666666*/
glabel D_80052CD0
.word 0x40555555 /*3.3333333*/
glabel D_80052CD4
.word 0x3fd55555 /*1.6666666*/
glabel D_80052CD8
.word 0x40555555 /*3.3333333*/
glabel D_80052CDC
.word 0x40c90fdb /*6.2831855*/
glabel D_80052CE0
.word 0x3d490fdb /*0.049087387*/
glabel D_80052CE4
.word 0x40c90fdb /*6.2831855*/
glabel D_80052CE8
.word 0x3d490fdb /*0.049087387*/
glabel D_80052CEC
.word 0x40c90fdb /*6.2831855*/
glabel D_80052CF0
.word 0x3d490fdb /*0.049087387*/
glabel D_80052CF4
.word 0x40555555 /*3.3333333*/

.text
glabel sub_GAME_7F04BCDC
  addiu $sp, $sp, -0x50
  lui   $t7, %hi(D_80032010) 
  sw    $ra, 0x24($sp)
  sw    $s0, 0x20($sp)
  sdc1  $f20, 0x18($sp)
  sw    $a1, 0x54($sp)
  addiu $t7, %lo(D_80032010) # addiu $t7, $t7, 0x2010
  lw    $at, ($t7)
  addiu $t6, $sp, 0x38
  lw    $t0, 4($t7)
  sw    $at, ($t6)
  lw    $at, 8($t7)
  move  $a2, $a0
  sw    $t0, 4($t6)
  sw    $at, 8($t6)
  lw    $a0, 0x10($a0)
  move  $s0, $zero
  jal   sub_GAME_7F03FDA8
   sw    $a2, 0x50($sp)
  lw    $a2, 0x50($sp)
  lw    $v0, 0x64($a2)
  andi  $t1, $v0, 0x40
  beqz  $t1, .L7F04BD48
   andi  $t3, $v0, 0x80
  lw    $t2, 0x6c($a2)
  b     .L7F04BD54
   lw    $s0, 0x44($t2)
.L7F04BD48:
  beqz  $t3, .L7F04BD54
   nop   
  lw    $s0, 0x6c($a2)
.L7F04BD54:
  beql  $s0, $zero, .L7F04BFC0
   lw    $ra, 0x24($sp)
  jal   get_random_value
   nop   
  mtc1  $v0, $f4
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f20
  bgez  $v0, .L7F04BD88
   cvt.s.w $f6, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F04BD88:
  mul.s $f10, $f6, $f20
  lui   $at, %hi(D_80052CC4)
  lwc1  $f16, %lo(D_80052CC4)($at)
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f4
  lui   $at, %hi(D_80052CC8)
  lwc1  $f6, %lo(D_80052CC8)($at)
  mul.s $f18, $f10, $f16
  nop   
  mul.s $f8, $f18, $f4
  sub.s $f10, $f8, $f6
  jal   get_random_value
   swc1  $f10, 4($s0)
  mtc1  $v0, $f16
  bgez  $v0, .L7F04BDD8
   cvt.s.w $f18, $f16
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f4
  nop   
  add.s $f18, $f18, $f4
.L7F04BDD8:
  mul.s $f8, $f18, $f20
  lui   $at, %hi(D_80052CCC)
  lwc1  $f6, %lo(D_80052CCC)($at)
  lui   $at, %hi(D_80052CD0)
  lwc1  $f16, %lo(D_80052CD0)($at)
  mul.s $f0, $f8, $f6
  add.s $f10, $f0, $f0
  add.s $f4, $f10, $f16
  jal   get_random_value
   swc1  $f4, 8($s0)
  mtc1  $v0, $f18
  bgez  $v0, .L7F04BE1C
   cvt.s.w $f8, $f18
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f6
  nop   
  add.s $f8, $f8, $f6
.L7F04BE1C:
  mul.s $f10, $f8, $f20
  lui   $at, %hi(D_80052CD4)
  lwc1  $f16, %lo(D_80052CD4)($at)
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f18
  lui   $at, %hi(D_80052CD8)
  lwc1  $f8, %lo(D_80052CD8)($at)
  mul.s $f4, $f10, $f16
  nop   
  mul.s $f6, $f4, $f18
  sub.s $f10, $f6, $f8
  jal   get_random_value
   swc1  $f10, 0xc($s0)
  mtc1  $v0, $f16
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F04BE6C
   cvt.s.w $f4, $f16
  mtc1  $at, $f18
  nop   
  add.s $f4, $f4, $f18
.L7F04BE6C:
  mul.s $f6, $f4, $f20
  lui   $at, %hi(D_80052CDC)
  lwc1  $f8, %lo(D_80052CDC)($at)
  li    $at, 0x3C800000 # 0.015625
  mtc1  $at, $f16
  lui   $at, %hi(D_80052CE0)
  lwc1  $f4, %lo(D_80052CE0)($at)
  mul.s $f10, $f6, $f8
  nop   
  mul.s $f18, $f10, $f16
  sub.s $f6, $f18, $f4
  jal   get_random_value
   swc1  $f6, 0x38($sp)
  mtc1  $v0, $f8
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F04BEBC
   cvt.s.w $f10, $f8
  mtc1  $at, $f16
  nop   
  add.s $f10, $f10, $f16
.L7F04BEBC:
  mul.s $f18, $f10, $f20
  lui   $at, %hi(D_80052CE4)
  lwc1  $f4, %lo(D_80052CE4)($at)
  li    $at, 0x3C800000 # 0.015625
  mtc1  $at, $f8
  lui   $at, %hi(D_80052CE8)
  lwc1  $f10, %lo(D_80052CE8)($at)
  mul.s $f6, $f18, $f4
  nop   
  mul.s $f16, $f6, $f8
  sub.s $f18, $f16, $f10
  jal   get_random_value
   swc1  $f18, 0x3c($sp)
  mtc1  $v0, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F04BF0C
   cvt.s.w $f6, $f4
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F04BF0C:
  mul.s $f16, $f6, $f20
  lui   $at, %hi(D_80052CEC)
  lwc1  $f10, %lo(D_80052CEC)($at)
  li    $at, 0x3C800000 # 0.015625
  mtc1  $at, $f4
  lui   $at, %hi(D_80052CF0)
  lwc1  $f6, %lo(D_80052CF0)($at)
  mul.s $f18, $f16, $f10
  addiu $a0, $sp, 0x38
  addiu $a1, $s0, 0x20
  mul.s $f8, $f18, $f4
  sub.s $f16, $f8, $f6
  jal   sub_GAME_7F058714
   swc1  $f16, 0x40($sp)
  lw    $t4, ($s0)
  lw    $v0, 0x54($sp)
  ori   $t5, $t4, 1
  sw    $t5, ($s0)
  lwc1  $f10, ($v0)
  swc1  $f10, 0x44($sp)
  lwc1  $f18, 4($v0)
  swc1  $f18, 0x48($sp)
  lwc1  $f4, 8($v0)
  jal   sub_GAME_7F078444
   swc1  $f4, 0x4c($sp)
  move  $a0, $v0
  jal   sub_GAME_7F0583D8
   addiu $a1, $sp, 0x44
  lui   $at, %hi(D_80052CF4)
  lwc1  $f0, %lo(D_80052CF4)($at)
  lwc1  $f6, 0x44($sp)
  lwc1  $f8, 4($s0)
  lwc1  $f18, 0xc($s0)
  mul.s $f16, $f0, $f6
  add.s $f10, $f8, $f16
  swc1  $f10, 4($s0)
  lwc1  $f4, 0x4c($sp)
  mul.s $f6, $f0, $f4
  add.s $f8, $f18, $f6
  jal   get_curplayer_positiondata
   swc1  $f8, 0xc($s0)
  li    $t9, 1
  sw    $v0, 0x88($s0)
  sw    $t9, 0x90($s0)
  lw    $ra, 0x24($sp)
.L7F04BFC0:
  ldc1  $f20, 0x18($sp)
  lw    $s0, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x50
");






asm(R"
glabel sub_GAME_7F04BFD0
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  lw    $v0, 0x1c($a0)
  beql  $v0, $zero, .L7F04C038
   lw    $ra, 0x14($sp)
  lw    $v0, 4($a0)
  sw    $a1, 0x24($sp)
  jal   sub_GAME_7F03FDA8
   sw    $v0, 0x18($sp)
  lw    $v0, 0x18($sp)
  lw    $a1, 0x24($sp)
  lw    $v1, 0x64($v0)
  andi  $t6, $v1, 0x40
  beqz  $t6, .L7F04C024
   andi  $t8, $v1, 0x80
  lw    $t7, 0x6c($v0)
  lw    $a0, 0x44($t7)
  beqz  $a0, .L7F04C024
   nop   
  b     .L7F04C034
   sw    $a1, 0xb8($a0)
.L7F04C024:
  beql  $t8, $zero, .L7F04C038
   lw    $ra, 0x14($sp)
  lw    $t9, 0x6c($v0)
  sw    $a1, 0xb8($t9)
.L7F04C034:
  lw    $ra, 0x14($sp)
.L7F04C038:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");






asm(R"
glabel sub_GAME_7F04C044
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  lw    $a2, 0x1c($a0)
  move  $a1, $a0
  beql  $a2, $zero, .L7F04C124
   lw    $ra, 0x14($sp)
  lw    $v0, 4($a0)
  lw    $t6, 0x14($v0)
  sw    $a2, 0x24($sp)
  sw    $a1, 0x28($sp)
  sw    $v0, 0x20($sp)
  jal   sub_GAME_7F03A5D0
   sw    $t6, 0x1c($sp)
  lw    $t7, 0x1c($sp)
  lw    $v0, 0x20($sp)
  lw    $a2, 0x24($sp)
  lw    $a1, 0x28($sp)
  sw    $zero, 0x1c($t7)
  lw    $t8, 0x64($v0)
  lui   $at, (0xFFF7FFFF >> 16) # lui $at, 0xfff7
  ori   $at, (0xFFF7FFFF & 0xFFFF) # ori $at, $at, 0xffff
  and   $t9, $t8, $at
  sw    $t9, 0x64($v0)
  lbu   $v1, ($a2)
  li    $at, 3
  beq   $v1, $at, .L7F04C0B8
   li    $at, 6
  bnel  $v1, $at, .L7F04C124
   lw    $ra, 0x14($sp)
.L7F04C0B8:
  lw    $a0, 4($a2)
  beql  $a0, $zero, .L7F04C124
   lw    $ra, 0x14($sp)
  lw    $t0, 0x1d8($a0)
  bnel  $a1, $t0, .L7F04C0DC
   lw    $t1, 0x160($a0)
  b     .L7F04C120
   sw    $zero, 0x1d8($a0)
  lw    $t1, 0x160($a0)
.L7F04C0DC:
  move  $a2, $zero
  bnel  $a1, $t1, .L7F04C104
   lw    $t2, 0x164($a0)
  move  $a1, $zero
  jal   sub_GAME_7F02D118
   sw    $a0, 0x18($sp)
  lw    $a0, 0x18($sp)
  b     .L7F04C120
   sw    $zero, 0x160($a0)
  lw    $t2, 0x164($a0)
.L7F04C104:
  move  $a2, $zero
  bne   $a1, $t2, .L7F04C120
   li    $a1, 1
  jal   sub_GAME_7F02D118
   sw    $a0, 0x18($sp)
  lw    $a0, 0x18($sp)
  sw    $zero, 0x164($a0)
.L7F04C120:
  lw    $ra, 0x14($sp)
.L7F04C124:
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");






asm(R"
.late_rodata
glabel D_80052CF8
.word 0x3fd55555 /*1.6666666*/
glabel D_80052CFC
.word 0x3fd55555 /*1.6666666*/
glabel D_80052D00
.word 0x3fd55555 /*1.6666666*/
glabel D_80052D04
.word 0x40c90fdb /*6.2831855*/
glabel D_80052D08
.word 0x3cc90fdb /*0.024543693*/
glabel D_80052D0C
.word 0x40c90fdb /*6.2831855*/
glabel D_80052D10
.word 0x3cc90fdb /*0.024543693*/
glabel D_80052D14
.word 0x40c90fdb /*6.2831855*/
glabel D_80052D18
.word 0x3cc90fdb /*0.024543693*/
glabel D_80052D1C
.word 0x41555555 /*13.333333*/
glabel D_80052D20
.word 0x40d55555 /*6.6666665*/
glabel D_80052D24
.word 0x41555555 /*13.333333*/
glabel D_80052D28
.word 0x40c90fdb /*6.2831855*/
glabel D_80052D2C
.word 0x3cc90fdb /*0.024543693*/
glabel D_80052D30
.word 0x40c90fdb /*6.2831855*/
glabel D_80052D34
.word 0x3cc90fdb /*0.024543693*/
glabel D_80052D38
.word 0x40c90fdb /*6.2831855*/
glabel D_80052D3C
.word 0x3cc90fdb /*0.024543693*/
glabel D_80052D40
.word 0x3fd55555 /*1.6666666*/
glabel D_80052D44
.word 0x40555555 /*3.3333333*/
glabel D_80052D48
.word 0x3fd55555 /*1.6666666*/
glabel D_80052D4C
.word 0x3fd55555 /*1.6666666*/
glabel D_80052D50
.word 0x40555555 /*3.3333333*/
glabel D_80052D54
.word 0x40c90fdb /*6.2831855*/
glabel D_80052D58
.word 0x3dc90fdb /*0.098174773*/
glabel D_80052D5C
.word 0x40c90fdb /*6.2831855*/
glabel D_80052D60
.word 0x3dc90fdb /*0.098174773*/
glabel D_80052D64
.word 0x40c90fdb /*6.2831855*/
glabel D_80052D68
.word 0x3dc90fdb /*0.098174773*/

.text
glabel sub_GAME_7F04C130
  addiu $sp, $sp, -0x108
  sw    $ra, 0x3c($sp)
  sw    $s2, 0x38($sp)
  sw    $s1, 0x34($sp)
  sw    $s0, 0x30($sp)
  sw    $a0, 0x108($sp)
  lw    $t7, 0x1c($a0)
  sw    $t7, 0x104($sp)
  lw    $s2, 4($a0)
  lw    $t8, 0x64($s2)
  andi  $t9, $t8, 0x40
  beql  $t9, $zero, .L7F04C19C
   lw    $t4, 0x104($sp)
  lw    $a0, 0x6c($s2)
  lw    $v0, 0x44($a0)
  beql  $v0, $zero, .L7F04C19C
   lw    $t4, 0x104($sp)
  jal   sub_GAME_7F03FE88
   move  $s0, $v0
  lw    $t0, 0x64($s2)
  li    $at, -65
  sw    $s0, 0x6c($s2)
  and   $t1, $t0, $at
  sw    $t1, 0x64($s2)
  ori   $t3, $t1, 0x80
  sw    $t3, 0x64($s2)
  lw    $t4, 0x104($sp)
.L7F04C19C:
  move  $v0, $zero
  beqz  $t4, .L7F04CA2C
   nop   
  lw    $t5, 0x64($s2)
  andi  $t7, $t5, 0x80
  beqz  $t7, .L7F04CA2C
   nop   
  lw    $t6, 0x14($s2)
  li    $at, 2
  move  $s0, $t4
  sw    $t6, 0xf8($sp)
  lw    $s1, 0x6c($s2)
  lw    $t8, ($s1)
  lw    $v0, 0xb8($s1)
  ori   $t9, $t8, 1
  sw    $t9, ($s1)
  lw    $t0, 0x104($sp)
  bne   $v0, $at, .L7F04C3CC
   sw    $t0, 0x88($s1)
  lw    $t1, 0x104($sp)
  li    $v1, 3
  lui   $t5, %hi(D_8003201C) 
  lbu   $t2, ($t1)
  addiu $t5, %lo(D_8003201C) # addiu $t5, $t5, 0x201c
  addiu $t3, $sp, 0x98
  bnel  $v1, $t2, .L7F04C3D0
   li    $v1, 3
  lw    $v0, 4($t1)
  lw    $at, ($t5)
  lw    $t6, 4($t5)
  lw    $a0, 0x1c($v0)
  sw    $at, ($t3)
  lw    $at, 8($t5)
  sw    $t6, 4($t3)
  jal   getsubroty
   sw    $at, 8($t3)
  swc1  $f0, 0x94($sp)
  jal   sinf
   mov.s $f12, $f0
  lui   $at, %hi(D_80052CF8)
  lwc1  $f4, %lo(D_80052CF8)($at)
  mul.s $f6, $f0, $f4
  jal   get_random_value
   swc1  $f6, 4($s1)
  mtc1  $v0, $f8
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F04C268
   cvt.s.w $f10, $f8
  mtc1  $at, $f16
  nop   
  add.s $f10, $f10, $f16
.L7F04C268:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f18
  lui   $at, %hi(D_80052CFC)
  lwc1  $f8, %lo(D_80052CFC)($at)
  mul.s $f4, $f10, $f18
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f10
  neg.s $f6, $f4
  mul.s $f16, $f6, $f8
  nop   
  mul.s $f18, $f16, $f10
  swc1  $f18, 8($s1)
  jal   cosf
   lwc1  $f12, 0x94($sp)
  lui   $at, %hi(D_80052D00)
  lwc1  $f4, %lo(D_80052D00)($at)
  mul.s $f6, $f0, $f4
  jal   get_random_value
   swc1  $f6, 0xc($s1)
  mtc1  $v0, $f8
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F04C2D0
   cvt.s.w $f16, $f8
  mtc1  $at, $f10
  nop   
  add.s $f16, $f16, $f10
.L7F04C2D0:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f18
  lui   $at, %hi(D_80052D04)
  lwc1  $f6, %lo(D_80052D04)($at)
  mul.s $f4, $f16, $f18
  li    $at, 0x3C000000 # 0.007812
  mtc1  $at, $f10
  lui   $at, %hi(D_80052D08)
  lwc1  $f18, %lo(D_80052D08)($at)
  mul.s $f8, $f4, $f6
  nop   
  mul.s $f16, $f8, $f10
  sub.s $f4, $f16, $f18
  jal   get_random_value
   swc1  $f4, 0x98($sp)
  mtc1  $v0, $f6
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F04C328
   cvt.s.w $f8, $f6
  mtc1  $at, $f10
  nop   
  add.s $f8, $f8, $f10
.L7F04C328:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f16
  lui   $at, %hi(D_80052D0C)
  lwc1  $f4, %lo(D_80052D0C)($at)
  mul.s $f18, $f8, $f16
  li    $at, 0x3C000000 # 0.007812
  mtc1  $at, $f10
  lui   $at, %hi(D_80052D10)
  lwc1  $f16, %lo(D_80052D10)($at)
  mul.s $f6, $f18, $f4
  nop   
  mul.s $f8, $f6, $f10
  sub.s $f18, $f8, $f16
  jal   get_random_value
   swc1  $f18, 0x9c($sp)
  mtc1  $v0, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F04C380
   cvt.s.w $f6, $f4
  mtc1  $at, $f10
  nop   
  add.s $f6, $f6, $f10
.L7F04C380:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f8
  lui   $at, %hi(D_80052D14)
  lwc1  $f18, %lo(D_80052D14)($at)
  mul.s $f16, $f6, $f8
  li    $at, 0x3C000000 # 0.007812
  mtc1  $at, $f10
  lui   $at, %hi(D_80052D18)
  lwc1  $f8, %lo(D_80052D18)($at)
  addiu $a0, $sp, 0x98
  addiu $a1, $s1, 0x20
  mul.s $f4, $f16, $f18
  nop   
  mul.s $f6, $f4, $f10
  sub.s $f16, $f6, $f8
  jal   sub_GAME_7F058714
   swc1  $f16, 0xa0($sp)
  b     .L7F04C7F8
   lw    $t1, 0x104($sp)
.L7F04C3CC:
  li    $v1, 3
.L7F04C3D0:
  bne   $v1, $v0, .L7F04C574
   lw    $t4, 0x104($sp)
  lbu   $t8, ($t4)
  lui   $t0, %hi(D_80032028) 
  addiu $t0, %lo(D_80032028) # addiu $t0, $t0, 0x2028
  bne   $v1, $t8, .L7F04C574
   addiu $t9, $sp, 0x80
  lw    $v0, 4($t4)
  lw    $at, ($t0)
  lw    $t1, 4($t0)
  lw    $a0, 0x1c($v0)
  sw    $at, ($t9)
  lw    $at, 8($t0)
  sw    $t1, 4($t9)
  jal   getsubroty
   sw    $at, 8($t9)
  swc1  $f0, 0x7c($sp)
  jal   sinf
   mov.s $f12, $f0
  lui   $at, %hi(D_80052D1C)
  lwc1  $f18, %lo(D_80052D1C)($at)
  lui   $at, %hi(D_80052D20)
  mul.s $f4, $f0, $f18
  swc1  $f4, 4($s1)
  lwc1  $f10, %lo(D_80052D20)($at)
  swc1  $f10, 8($s1)
  jal   cosf
   lwc1  $f12, 0x7c($sp)
  lui   $at, %hi(D_80052D24)
  lwc1  $f6, %lo(D_80052D24)($at)
  mul.s $f8, $f0, $f6
  jal   get_random_value
   swc1  $f8, 0xc($s1)
  mtc1  $v0, $f16
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F04C470
   cvt.s.w $f18, $f16
  mtc1  $at, $f4
  nop   
  add.s $f18, $f18, $f4
.L7F04C470:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f10
  lui   $at, %hi(D_80052D28)
  lwc1  $f8, %lo(D_80052D28)($at)
  mul.s $f6, $f18, $f10
  li    $at, 0x3C000000 # 0.007812
  mtc1  $at, $f4
  lui   $at, %hi(D_80052D2C)
  lwc1  $f10, %lo(D_80052D2C)($at)
  mul.s $f16, $f6, $f8
  nop   
  mul.s $f18, $f16, $f4
  sub.s $f6, $f18, $f10
  jal   get_random_value
   swc1  $f6, 0x80($sp)
  mtc1  $v0, $f8
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F04C4C8
   cvt.s.w $f16, $f8
  mtc1  $at, $f4
  nop   
  add.s $f16, $f16, $f4
.L7F04C4C8:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f18
  lui   $at, %hi(D_80052D30)
  lwc1  $f6, %lo(D_80052D30)($at)
  mul.s $f10, $f16, $f18
  li    $at, 0x3C000000 # 0.007812
  mtc1  $at, $f4
  lui   $at, %hi(D_80052D34)
  lwc1  $f18, %lo(D_80052D34)($at)
  mul.s $f8, $f10, $f6
  nop   
  mul.s $f16, $f8, $f4
  sub.s $f10, $f16, $f18
  jal   get_random_value
   swc1  $f10, 0x84($sp)
  mtc1  $v0, $f6
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F04C520
   cvt.s.w $f8, $f6
  mtc1  $at, $f4
  nop   
  add.s $f8, $f8, $f4
.L7F04C520:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f16
  lui   $at, %hi(D_80052D38)
  lwc1  $f10, %lo(D_80052D38)($at)
  mul.s $f18, $f8, $f16
  li    $at, 0x3C000000 # 0.007812
  mtc1  $at, $f4
  lui   $at, %hi(D_80052D3C)
  lwc1  $f16, %lo(D_80052D3C)($at)
  addiu $a0, $sp, 0x80
  addiu $a1, $s1, 0x20
  mul.s $f6, $f18, $f10
  nop   
  mul.s $f8, $f6, $f4
  sub.s $f18, $f8, $f16
  jal   sub_GAME_7F058714
   swc1  $f18, 0x88($sp)
  lw    $t7, ($s1)
  ori   $t3, $t7, 0x40
  b     .L7F04C7F4
   sw    $t3, ($s1)
.L7F04C574:
  li    $at, 4
  bne   $v0, $at, .L7F04C7EC
   addiu $a0, $s1, 4
  lui   $t6, %hi(D_80032034) 
  addiu $t6, %lo(D_80032034) # addiu $t6, $t6, 0x2034
  lw    $at, ($t6)
  addiu $t5, $sp, 0x70
  lw    $t4, 4($t6)
  sw    $at, ($t5)
  lw    $at, 8($t6)
  sw    $t4, 4($t5)
  jal   get_curplayer_positiondata
   sw    $at, 8($t5)
  lw    $t2, 0x104($sp)
  lwc1  $f6, 8($v0)
  lwc1  $f8, 0x10($v0)
  lwc1  $f10, 8($t2)
  lwc1  $f4, 0x10($t2)
  sub.s $f12, $f10, $f6
  jal   convert_angle_using_inverse
   sub.s $f14, $f4, $f8
  jal   get_random_value
   swc1  $f0, 0x60($sp)
  sw    $v0, 0x50($sp)
  jal   sinf
   lwc1  $f12, 0x60($sp)
  lw    $t9, 0x50($sp)
  mtc1  $t9, $f16
  bgez  $t9, .L7F04C5FC
   cvt.s.w $f18, $f16
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f10
  nop   
  add.s $f18, $f18, $f10
.L7F04C5FC:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f6
  lui   $at, %hi(D_80052D40)
  lwc1  $f8, %lo(D_80052D40)($at)
  mul.s $f4, $f18, $f6
  lui   $at, %hi(D_80052D44)
  lwc1  $f10, %lo(D_80052D44)($at)
  mul.s $f2, $f4, $f8
  add.s $f16, $f2, $f2
  add.s $f18, $f16, $f10
  mul.s $f6, $f0, $f18
  jal   get_random_value
   swc1  $f6, 4($s1)
  mtc1  $v0, $f4
  bgez  $v0, .L7F04C64C
   cvt.s.w $f8, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f16
  nop   
  add.s $f8, $f8, $f16
.L7F04C64C:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f10
  lui   $at, %hi(D_80052D48)
  lwc1  $f6, %lo(D_80052D48)($at)
  mul.s $f18, $f8, $f10
  nop   
  mul.s $f0, $f18, $f6
  add.s $f4, $f0, $f0
  jal   get_random_value
   swc1  $f4, 8($s1)
  sw    $v0, 0x50($sp)
  jal   cosf
   lwc1  $f12, 0x60($sp)
  lw    $t0, 0x50($sp)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t0, $f16
  bgez  $t0, .L7F04C6A0
   cvt.s.w $f8, $f16
  mtc1  $at, $f10
  nop   
  add.s $f8, $f8, $f10
.L7F04C6A0:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f18
  lui   $at, %hi(D_80052D4C)
  lwc1  $f4, %lo(D_80052D4C)($at)
  mul.s $f6, $f8, $f18
  lui   $at, %hi(D_80052D50)
  lwc1  $f10, %lo(D_80052D50)($at)
  mul.s $f2, $f6, $f4
  add.s $f16, $f2, $f2
  add.s $f8, $f16, $f10
  mul.s $f18, $f0, $f8
  jal   get_random_value
   swc1  $f18, 0xc($s1)
  mtc1  $v0, $f6
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F04C6F0
   cvt.s.w $f4, $f6
  mtc1  $at, $f16
  nop   
  add.s $f4, $f4, $f16
.L7F04C6F0:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f10
  lui   $at, %hi(D_80052D54)
  lwc1  $f18, %lo(D_80052D54)($at)
  mul.s $f8, $f4, $f10
  li    $at, 0x3D000000 # 0.031250
  mtc1  $at, $f16
  lui   $at, %hi(D_80052D58)
  lwc1  $f10, %lo(D_80052D58)($at)
  mul.s $f6, $f8, $f18
  nop   
  mul.s $f4, $f6, $f16
  sub.s $f8, $f4, $f10
  jal   get_random_value
   swc1  $f8, 0x70($sp)
  mtc1  $v0, $f18
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F04C748
   cvt.s.w $f6, $f18
  mtc1  $at, $f16
  nop   
  add.s $f6, $f6, $f16
.L7F04C748:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f4
  lui   $at, %hi(D_80052D5C)
  lwc1  $f8, %lo(D_80052D5C)($at)
  mul.s $f10, $f6, $f4
  li    $at, 0x3D000000 # 0.031250
  mtc1  $at, $f16
  lui   $at, %hi(D_80052D60)
  lwc1  $f4, %lo(D_80052D60)($at)
  mul.s $f18, $f10, $f8
  nop   
  mul.s $f6, $f18, $f16
  sub.s $f10, $f6, $f4
  jal   get_random_value
   swc1  $f10, 0x74($sp)
  mtc1  $v0, $f8
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F04C7A0
   cvt.s.w $f18, $f8
  mtc1  $at, $f16
  nop   
  add.s $f18, $f18, $f16
.L7F04C7A0:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f6
  lui   $at, %hi(D_80052D64)
  lwc1  $f10, %lo(D_80052D64)($at)
  mul.s $f4, $f18, $f6
  li    $at, 0x3D000000 # 0.031250
  mtc1  $at, $f16
  lui   $at, %hi(D_80052D68)
  lwc1  $f6, %lo(D_80052D68)($at)
  addiu $a0, $sp, 0x70
  addiu $a1, $s1, 0x20
  mul.s $f8, $f4, $f10
  nop   
  mul.s $f18, $f8, $f16
  sub.s $f4, $f18, $f6
  jal   sub_GAME_7F058714
   swc1  $f4, 0x78($sp)
  b     .L7F04C7F8
   lw    $t1, 0x104($sp)
.L7F04C7EC:
  jal   sub_GAME_7F057C14
   addiu $a1, $s1, 0x20
.L7F04C7F4:
  lw    $t1, 0x104($sp)
.L7F04C7F8:
  lw    $t7, 0x1c($t1)
  beql  $t7, $zero, .L7F04C81C
   lw    $t3, 0x14($s0)
  lw    $v0, 0x1c($s0)
  move  $s0, $v0
.L7F04C80C:
  lw    $v0, 0x1c($v0)
  bnezl $v0, .L7F04C80C
   move  $s0, $v0
  lw    $t3, 0x14($s0)
.L7F04C81C:
  lw    $v0, 0x108($sp)
  sw    $t3, 0xb0($sp)
  lbu   $t8, 1($v0)
  andi  $t5, $t8, 2
  beql  $t5, $zero, .L7F04C95C
   lw    $t2, 0x14($s0)
  jal   if_a0_plus_3_is_4_then_10_else_20
   move  $a0, $s2
  swc1  $f0, 0x5c($sp)
  jal   getsubmatrix
   lw    $a0, 0xf8($sp)
  li    $t6, 31
  sw    $v0, 0x58($sp)
  jal   sub_GAME_7F078444
   sw    $t6, 0x54($sp)
  move  $a0, $v0
  lw    $a1, 0x58($sp)
  jal   sub_GAME_7F05818C
   addiu $a2, $sp, 0xb8
  lw    $t4, ($s1)
  li    $t9, 29
  move  $a0, $s0
  andi  $t2, $t4, 0x40
  beqz  $t2, .L7F04C884
   nop   
  sw    $t9, 0x54($sp)
.L7F04C884:
  jal   sub_GAME_7F03D058
   move  $a1, $zero
  lw    $a1, 8($s0)
  lw    $a2, 0x10($s0)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f2
  mtc1  $zero, $f0
  lwc1  $f10, 0xf0($sp)
  lw    $t0, 0x54($sp)
  addiu $s1, $sp, 0xb0
  move  $a0, $s1
  lw    $a3, 0xe8($sp)
  swc1  $f2, 0x1c($sp)
  swc1  $f2, 0x24($sp)
  swc1  $f10, 0x10($sp)
  swc1  $f0, 0x18($sp)
  swc1  $f0, 0x20($sp)
  jal   sub_GAME_7F0B0E24
   sw    $t0, 0x14($sp)
  beqz  $v0, .L7F04C918
   move  $a0, $s1
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f16
  lw    $t1, 0x54($sp)
  mtc1  $zero, $f8
  lw    $a1, 0xe8($sp)
  lw    $a2, 0xf0($sp)
  lw    $a3, 0x5c($sp)
  sw    $t1, 0x10($sp)
  swc1  $f16, 0x18($sp)
  jal   sub_GAME_7F0B18B8
   swc1  $f8, 0x14($sp)
  bgez  $v0, .L7F04C918
   lw    $t7, 0xb0($sp)
  lw    $t3, 0x108($sp)
  b     .L7F04C934
   sw    $t7, 0x14($t3)
.L7F04C918:
  lw    $t8, 0x14($s0)
  lw    $t5, 0x108($sp)
  sw    $t8, 0x14($t5)
  lwc1  $f18, 8($s0)
  swc1  $f18, 0xe8($sp)
  lwc1  $f6, 0x10($s0)
  swc1  $f6, 0xf0($sp)
.L7F04C934:
  move  $a0, $s0
  jal   sub_GAME_7F03D058
   li    $a1, 1
  lw    $t6, 0x58($sp)
  lw    $t4, 0x108($sp)
  lwc1  $f4, 0x38($t6)
  neg.s $f10, $f4
  b     .L7F04C984
   swc1  $f10, 0x18($t4)
  lw    $t2, 0x14($s0)
.L7F04C95C:
  addiu $a0, $sp, 0xb8
  jal   reset_array_of_0x10_floats
   sw    $t2, 0x14($v0)
  lw    $t9, 0xf8($sp)
  addiu $a1, $sp, 0xb8
  jal   matrix_multiply_A1_by_F12
   lwc1  $f12, 0x14($t9)
  addiu $a0, $s0, 8
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   addiu $a1, $sp, 0xb8
.L7F04C984:
  jal   sub_GAME_7F04C044
   lw    $a0, 0x108($sp)
  jal   set_current_objposdata_plus_0x28
   lw    $a0, 0x108($sp)
  jal   set_stateflag_0x04_for_posdata
   lw    $a0, 0x108($sp)
  lwc1  $f0, 0xe8($sp)
  lw    $t0, 0x108($sp)
  mtc1  $zero, $f8
  mtc1  $zero, $f16
  swc1  $f0, 8($t0)
  swc1  $f0, 0x58($s2)
  lwc1  $f0, 0xec($sp)
  lw    $t1, 0x108($sp)
  mtc1  $zero, $f18
  addiu $a0, $sp, 0xb8
  swc1  $f0, 0xc($t1)
  swc1  $f0, 0x5c($s2)
  lwc1  $f0, 0xf0($sp)
  lw    $t7, 0x108($sp)
  addiu $a1, $s2, 0x18
  swc1  $f0, 0x10($t7)
  swc1  $f0, 0x60($s2)
  swc1  $f8, 0xe8($sp)
  swc1  $f16, 0xec($sp)
  jal   sub_GAME_7F058020
   swc1  $f18, 0xf0($sp)
  lw    $a0, 0x10($s2)
  jal   sub_GAME_7F0402B4
   addiu $a1, $s2, 0x7c
  lbu   $t3, 0x7c($s2)
  lbu   $t8, 0x7d($s2)
  lbu   $t5, 0x7e($s2)
  lbu   $t6, 0x7f($s2)
  move  $a0, $s2
  sb    $t3, 0x78($s2)
  sb    $t8, 0x79($s2)
  sb    $t5, 0x7a($s2)
  jal   sub_GAME_7F056CA0
   sb    $t6, 0x7b($s2)
  b     .L7F04CA2C
   li    $v0, 1
.L7F04CA2C:
  lw    $ra, 0x3c($sp)
  lw    $s0, 0x30($sp)
  lw    $s1, 0x34($sp)
  lw    $s2, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x108
");






asm(R"
.late_rodata
glabel D_80052D6C
.word 0x3fd55555 /*1.6666666*/
glabel D_80052D70
.word 0x3f555555 /*0.83333331*/
glabel D_80052D74
.word 0x3fd55555 /*1.6666666*/
glabel D_80052D78
.word 0x3fd55555 /*1.6666666*/
glabel D_80052D7C
.word 0x3f555555 /*0.83333331*/
glabel D_80052D80
.word 0x40c90fdb /*6.2831855*/
glabel D_80052D84
.word 0x3C20D97C /*0.009817477*/
glabel D_80052D88
.word 0x40c90fdb /*6.2831855*/
glabel D_80052D8C
.word 0x3C20D97C /*0.009817477*/
glabel D_80052D90
.word 0x40c90fdb /*6.2831855*/
glabel D_80052D94
.word 0x3C20D97C /*0.009817477*/

.text
glabel sub_GAME_7F04CA44
  addiu $sp, $sp, -0x40
  sw    $ra, 0x24($sp)
  sw    $s1, 0x20($sp)
  sw    $s0, 0x1c($sp)
  sdc1  $f20, 0x10($sp)
  lw    $t6, 0x64($a0)
  lui   $at, (0xFFF9FFFF >> 16) # lui $at, 0xfff9
  lw    $t1, 0xc($a0)
  ori   $at, (0xFFF9FFFF & 0xFFFF) # ori $at, $at, 0xffff
  and   $t7, $t6, $at
  sll   $t9, $a1, 0x11
  sw    $t7, 0x64($a0)
  or    $t0, $t7, $t9
  andi  $t2, $t1, 0x100
  move  $s0, $a0
  bnez  $t2, .L7F04CCEC
   sw    $t0, 0x64($a0)
  lw    $t3, 8($a0)
  andi  $t6, $t0, 0xc0
  andi  $t4, $t3, 1
  beql  $t4, $zero, .L7F04CCF0
   lw    $ra, 0x24($sp)
  bnez  $t6, .L7F04CCEC
   lui   $t8, %hi(D_80032040) 
  addiu $t8, %lo(D_80032040) # addiu $t8, $t8, 0x2040
  lw    $at, ($t8)
  addiu $t7, $sp, 0x34
  lw    $t0, 4($t8)
  sw    $at, ($t7)
  lw    $at, 8($t8)
  sw    $t0, 4($t7)
  move  $s1, $zero
  sw    $at, 8($t7)
  jal   sub_GAME_7F03FDA8
   lw    $a0, 0x10($a0)
  lw    $t1, 0x64($s0)
  andi  $t2, $t1, 0x80
  beqz  $t2, .L7F04CAE4
   nop   
  lw    $s1, 0x6c($s0)
.L7F04CAE4:
  beql  $s1, $zero, .L7F04CCF0
   lw    $ra, 0x24($sp)
  jal   get_random_value
   nop   
  mtc1  $v0, $f4
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f20
  bgez  $v0, .L7F04CB18
   cvt.s.w $f6, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F04CB18:
  mul.s $f10, $f6, $f20
  lui   $at, %hi(D_80052D6C)
  lwc1  $f16, %lo(D_80052D6C)($at)
  lui   $at, %hi(D_80052D70)
  lwc1  $f4, %lo(D_80052D70)($at)
  mul.s $f18, $f10, $f16
  sub.s $f8, $f18, $f4
  jal   get_random_value
   swc1  $f8, 4($s1)
  mtc1  $v0, $f6
  lui   $at, %hi(D_80052D74)
  lwc1  $f2, %lo(D_80052D74)($at)
  bgez  $v0, .L7F04CB60
   cvt.s.w $f10, $f6
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f16
  nop   
  add.s $f10, $f10, $f16
.L7F04CB60:
  mul.s $f18, $f10, $f20
  nop   
  mul.s $f0, $f18, $f2
  add.s $f4, $f0, $f0
  add.s $f8, $f4, $f2
  jal   get_random_value
   swc1  $f8, 8($s1)
  mtc1  $v0, $f6
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F04CB98
   cvt.s.w $f16, $f6
  mtc1  $at, $f10
  nop   
  add.s $f16, $f16, $f10
.L7F04CB98:
  mul.s $f18, $f16, $f20
  lui   $at, %hi(D_80052D78)
  lwc1  $f4, %lo(D_80052D78)($at)
  lui   $at, %hi(D_80052D7C)
  lwc1  $f6, %lo(D_80052D7C)($at)
  mul.s $f8, $f18, $f4
  sub.s $f10, $f8, $f6
  swc1  $f10, 0xc($s1)
  lw    $t3, 0xc($s0)
  andi  $t4, $t3, 0x200
  bnezl $t4, .L7F04CCB4
   addiu $a0, $sp, 0x34
  jal   get_random_value
   nop   
  mtc1  $v0, $f16
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F04CBEC
   cvt.s.w $f18, $f16
  mtc1  $at, $f4
  nop   
  add.s $f18, $f18, $f4
.L7F04CBEC:
  mul.s $f8, $f18, $f20
  lui   $at, %hi(D_80052D80)
  lwc1  $f6, %lo(D_80052D80)($at)
  li    $at, 0x43A00000 # 320.000000
  mtc1  $at, $f16
  lui   $at, %hi(D_80052D84)
  lwc1  $f18, %lo(D_80052D84)($at)
  mul.s $f10, $f8, $f6
  div.s $f4, $f10, $f16
  sub.s $f8, $f4, $f18
  jal   get_random_value
   swc1  $f8, 0x34($sp)
  mtc1  $v0, $f6
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F04CC38
   cvt.s.w $f10, $f6
  mtc1  $at, $f16
  nop   
  add.s $f10, $f10, $f16
.L7F04CC38:
  mul.s $f4, $f10, $f20
  lui   $at, %hi(D_80052D88)
  lwc1  $f18, %lo(D_80052D88)($at)
  li    $at, 0x43A00000 # 320.000000
  mtc1  $at, $f6
  lui   $at, %hi(D_80052D8C)
  lwc1  $f10, %lo(D_80052D8C)($at)
  mul.s $f8, $f4, $f18
  div.s $f16, $f8, $f6
  sub.s $f4, $f16, $f10
  jal   get_random_value
   swc1  $f4, 0x38($sp)
  mtc1  $v0, $f18
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F04CC84
   cvt.s.w $f8, $f18
  mtc1  $at, $f6
  nop   
  add.s $f8, $f8, $f6
.L7F04CC84:
  mul.s $f16, $f8, $f20
  lui   $at, %hi(D_80052D90)
  lwc1  $f10, %lo(D_80052D90)($at)
  li    $at, 0x43A00000 # 320.000000
  mtc1  $at, $f18
  lui   $at, %hi(D_80052D94)
  lwc1  $f8, %lo(D_80052D94)($at)
  mul.s $f4, $f16, $f10
  div.s $f6, $f4, $f18
  sub.s $f16, $f6, $f8
  swc1  $f16, 0x3c($sp)
  addiu $a0, $sp, 0x34
.L7F04CCB4:
  jal   sub_GAME_7F058714
   addiu $a1, $s1, 0x20
  lw    $t5, ($s1)
  li    $at, -257
  ori   $t6, $t5, 1
  sw    $t6, ($s1)
  lw    $t9, 8($s0)
  lw    $t8, 0x64($s0)
  and   $t7, $t9, $at
  lui   $at, (0xFFFF7FFF >> 16) # lui $at, 0xffff
  ori   $at, (0xFFFF7FFF & 0xFFFF) # ori $at, $at, 0x7fff
  and   $t0, $t8, $at
  sw    $t7, 8($s0)
  sw    $t0, 0x64($s0)
.L7F04CCEC:
  lw    $ra, 0x24($sp)
.L7F04CCF0:
  ldc1  $f20, 0x10($sp)
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x40
");






asm(R"
glabel sub_GAME_7F04CD04
  addiu $sp, $sp, -0x58
  sw    $ra, 0x34($sp)
  sw    $s6, 0x30($sp)
  sw    $s5, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  lw    $t6, 0x14($a0)
  move  $s6, $a1
  lw    $s4, 4($a0)
  addiu $a1, $sp, 0x48
  addiu $a2, $sp, 0x44
  jal   sub_GAME_7F03CCB0
   lbu   $s5, 3($t6)
  lw    $t7, 0x44($sp)
  blezl $t7, .L7F04CDE8
   lw    $ra, 0x34($sp)
  jal   get_ptr_obj_pos_list_current_entry
   nop   
  beqz  $v0, .L7F04CDE4
   move  $s1, $v0
  li    $s3, 4
  li    $s2, 1
  lbu   $v0, ($s1)
.L7F04CD6C:
  beql  $s2, $v0, .L7F04CD80
   lw    $t8, 0x14($s1)
  bnel  $s3, $v0, .L7F04CDDC
   lw    $s1, 0x24($s1)
  lw    $t8, 0x14($s1)
.L7F04CD80:
  lbu   $t9, 3($t8)
  bnel  $s5, $t9, .L7F04CDDC
   lw    $s1, 0x24($s1)
  lw    $s0, 4($s1)
  lwc1  $f4, 0x5c($s4)
  lwc1  $f6, 0x5c($s0)
  c.lt.s $f4, $f6
  nop   
  bc1fl .L7F04CDDC
   lw    $s1, 0x24($s1)
  lw    $t0, 0x64($s0)
  addiu $a0, $s0, 0x58
  lw    $a1, 0x48($sp)
  andi  $t1, $t0, 0x8000
  beql  $t1, $zero, .L7F04CDDC
   lw    $s1, 0x24($s1)
  jal   sub_GAME_7F03CCD8
   lw    $a2, 0x44($sp)
  beqz  $v0, .L7F04CDD8
   move  $a0, $s0
  jal   sub_GAME_7F04CA44
   move  $a1, $s6
.L7F04CDD8:
  lw    $s1, 0x24($s1)
.L7F04CDDC:
  bnezl $s1, .L7F04CD6C
   lbu   $v0, ($s1)
.L7F04CDE4:
  lw    $ra, 0x34($sp)
.L7F04CDE8:
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  lw    $s3, 0x24($sp)
  lw    $s4, 0x28($sp)
  lw    $s5, 0x2c($sp)
  lw    $s6, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x58
");






asm(R"
glabel object_explosion_related
  addiu $sp, $sp, -0x48
  sw    $ra, 0x2c($sp)
  sw    $s1, 0x28($sp)
  sw    $s0, 0x24($sp)
  sw    $a1, 0x4c($sp)
  sw    $a2, 0x50($sp)
  lwc1  $f6, 0x70($a0)
  lwc1  $f4, 0x74($a0)
  move  $s1, $a0
  c.lt.s $f4, $f6
  nop   
  bc1tl .L7F04CE54
   lh    $t6, 4($s1)
  jal   do_something_if_object_destroyed
   nop   
  beql  $v0, $zero, .L7F04D15C
   lw    $ra, 0x2c($sp)
  lh    $t6, 4($s1)
.L7F04CE54:
  lui   $t8, %hi(object_explosion_details)
  lw    $v1, 0x10($s1)
  sll   $t7, $t6, 3
  subu  $t7, $t7, $t6
  sll   $t7, $t7, 1
  addu  $t8, $t8, $t7
  lh    $t8, %lo(object_explosion_details)($t8)
  move  $a0, $s1
  move  $s0, $v1
  sh    $t8, 0x3e($sp)
  lw    $t9, 0x1c($v1)
  beql  $t9, $zero, .L7F04CEA0
   lw    $t0, 0x14($s0)
  lw    $v0, 0x1c($s0)
  move  $s0, $v0
.L7F04CE90:
  lw    $v0, 0x1c($v0)
  bnezl $v0, .L7F04CE90
   move  $s0, $v0
  lw    $t0, 0x14($s0)
.L7F04CEA0:
  sw    $v1, 0x44($sp)
  jal   do_something_if_object_destroyed
   sw    $t0, 0x38($sp)
  bnez  $v0, .L7F04D008
   nop   
  lbu   $t1, 2($s1)
  mtc1  $zero, $f8
  ori   $t2, $t1, 0x80
  sb    $t2, 2($s1)
  swc1  $f8, 0x70($s1)
  lw    $t3, 0x38($sp)
  beql  $t3, $zero, .L7F04CF7C
   lw    $t4, 0xc($s1)
  lbu   $t4, 1($s0)
  lw    $v0, 0x4c($sp)
  addiu $a0, $sp, 0x38
  andi  $t5, $t4, 8
  bnezl $t5, .L7F04CF4C
   lw    $a2, 0x14($s0)
  lwc1  $f10, 8($v0)
  lw    $a1, 8($s0)
  lw    $a2, 0x10($s0)
  lw    $a3, ($v0)
  jal   sub_GAME_7F0B0BE4
   swc1  $f10, 0x10($sp)
  beqz  $v0, .L7F04CF48
   lw    $a0, 0x44($sp)
  lw    $t6, 8($s1)
  lw    $t9, 0x50($sp)
  addiu $t0, $s0, 0x2c
  andi  $t7, $t6, 0xe
  sltiu $t8, $t7, 1
  sw    $t8, 0x10($sp)
  sw    $t0, 0x18($sp)
  sw    $zero, 0x1c($sp)
  lw    $a1, 0x4c($sp)
  lw    $a2, 0x38($sp)
  lh    $a3, 0x3e($sp)
  jal   sub_GAME_7F09C250
   sw    $t9, 0x14($sp)
  b     .L7F04CF7C
   lw    $t4, 0xc($s1)
.L7F04CF48:
  lw    $a2, 0x14($s0)
.L7F04CF4C:
  lw    $t1, 0x50($sp)
  addiu $t2, $s0, 0x2c
  li    $t3, 1
  sw    $t3, 0x1c($sp)
  sw    $t2, 0x18($sp)
  sw    $zero, 0x10($sp)
  lw    $a0, 0x44($sp)
  lw    $a1, 0x4c($sp)
  lh    $a3, 0x3e($sp)
  jal   sub_GAME_7F09C250
   sw    $t1, 0x14($sp)
  lw    $t4, 0xc($s1)
.L7F04CF7C:
  move  $a0, $s1
  andi  $t5, $t4, 0x2000
  beqz  $t5, .L7F04CF9C
   nop   
  lw    $t6, 0x64($s1)
  ori   $t7, $t6, 4
  b     .L7F04D158
   sw    $t7, 0x64($s1)
.L7F04CF9C:
  jal   sub_GAME_7F04B610
   li    $a1, 1
  lw    $a0, 0x44($sp)
  bnel  $s0, $a0, .L7F04D15C
   lw    $ra, 0x2c($sp)
  jal   sub_GAME_7F04CD04
   lw    $a1, 0x50($sp)
  lw    $v0, 0x64($s1)
  andi  $t8, $v0, 0x8000
  beql  $t8, $zero, .L7F04CFEC
   lui   $at, 1
  jal   get_random_value
   nop   
  li    $at, 3
  divu  $zero, $v0, $at
  mfhi  $t9
  bnezl $t9, .L7F04D15C
   lw    $ra, 0x2c($sp)
  lw    $v0, 0x64($s1)
  lui   $at, 1
.L7F04CFEC:
  or    $t0, $v0, $at
  sw    $t0, 0x64($s1)
  lw    $a1, 0x50($sp)
  jal   sub_GAME_7F04CA44
   move  $a0, $s1
  b     .L7F04D15C
   lw    $ra, 0x2c($sp)
.L7F04D008:
  jal   sub_GAME_7F03FF60
   move  $a0, $s1
  andi  $t1, $v0, 3
  bnez  $t1, .L7F04D0DC
   sw    $v0, 0x34($sp)
  sra   $t2, $v0, 2
  addiu $a1, $t2, 1
  jal   sub_GAME_7F04B610
   move  $a0, $s1
  lw    $t3, 0x38($sp)
  beqz  $t3, .L7F04D0DC
   nop   
  lbu   $t4, 1($s0)
  lw    $v0, 0x4c($sp)
  addiu $a0, $sp, 0x38
  andi  $t5, $t4, 8
  bnezl $t5, .L7F04D0B0
   lw    $a2, 0x14($s0)
  lwc1  $f16, 8($v0)
  lw    $a1, 8($s0)
  lw    $a2, 0x10($s0)
  lw    $a3, ($v0)
  jal   sub_GAME_7F0B0BE4
   swc1  $f16, 0x10($sp)
  beqz  $v0, .L7F04D0AC
   lw    $a0, 0x44($sp)
  lw    $t6, 8($s1)
  lw    $t9, 0x50($sp)
  addiu $t0, $s0, 0x2c
  andi  $t7, $t6, 0xe
  sltiu $t8, $t7, 1
  sw    $t8, 0x10($sp)
  sw    $t0, 0x18($sp)
  sw    $zero, 0x1c($sp)
  lw    $a1, 0x4c($sp)
  lw    $a2, 0x38($sp)
  li    $a3, 16
  jal   sub_GAME_7F09C250
   sw    $t9, 0x14($sp)
  b     .L7F04D0DC
   nop   
.L7F04D0AC:
  lw    $a2, 0x14($s0)
.L7F04D0B0:
  lw    $t1, 0x50($sp)
  addiu $t2, $s0, 0x2c
  li    $t3, 1
  sw    $t3, 0x1c($sp)
  sw    $t2, 0x18($sp)
  sw    $zero, 0x10($sp)
  lw    $a0, 0x44($sp)
  lw    $a1, 0x4c($sp)
  li    $a3, 16
  jal   sub_GAME_7F09C250
   sw    $t1, 0x14($sp)
.L7F04D0DC:
  jal   do_something_if_object_destroyed
   move  $a0, $s1
  blezl $v0, .L7F04D130
   lw    $t1, 0x34($sp)
  lbu   $v0, 2($s1)
  andi  $t4, $v0, 4
  beql  $t4, $zero, .L7F04D130
   lw    $t1, 0x34($sp)
  lw    $t5, 0x64($s1)
  ori   $t7, $v0, 0x10
  andi  $t8, $v0, 0xffef
  andi  $t6, $t5, 0x1000
  beql  $t6, $zero, .L7F04D120
   sb    $t8, 2($s1)
  b     .L7F04D120
   sb    $t7, 2($s1)
  sb    $t8, 2($s1)
.L7F04D120:
  lw    $t0, 0x44($sp)
  li    $t9, 1200
  sh    $t9, 2($t0)
  lw    $t1, 0x34($sp)
.L7F04D130:
  slti  $at, $t1, 0xc
  bnezl $at, .L7F04D15C
   lw    $ra, 0x2c($sp)
  lw    $t2, 0x64($s1)
  lw    $t4, 8($s1)
  li    $at, -257
  ori   $t3, $t2, 0x1000
  and   $t5, $t4, $at
  sw    $t3, 0x64($s1)
  sw    $t5, 8($s1)
.L7F04D158:
  lw    $ra, 0x2c($sp)
.L7F04D15C:
  lw    $s0, 0x24($sp)
  lw    $s1, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x48
");






asm(R"
glabel sub_GAME_7F04D16C
  addiu $sp, $sp, -0x150
  sdc1  $f20, 0x28($sp)
  li    $at, 0x4F800000 # 4294967296.000000
  sw    $fp, 0x50($sp)
  sw    $s7, 0x4c($sp)
  sw    $s6, 0x48($sp)
  sw    $s5, 0x44($sp)
  sw    $s4, 0x40($sp)
  sw    $s3, 0x3c($sp)
  sw    $s1, 0x34($sp)
  sw    $s0, 0x30($sp)
  mtc1  $at, $f20
  move  $s1, $a3
  move  $s7, $a0
  move  $fp, $a2
  sw    $ra, 0x54($sp)
  sw    $s2, 0x38($sp)
  sw    $a1, 0x154($sp)
  sw    $zero, 0x110($sp)
  move  $s3, $a3
  lw    $s0, 0x14c($sp)
  lw    $s4, 0x168($sp)
  li    $s5, 253
  addiu $s6, $sp, 0xb0
.L7F04D1CC:
  lb    $v0, ($s1)
  li    $at, -72
  lw    $t6, 0x160($sp)
  bnel  $v0, $at, .L7F04D1F8
   li    $at, 4
  beqz  $t6, .L7F04D978
   move  $s3, $t6
  move  $s1, $t6
  b     .L7F04D1CC
   sw    $zero, 0x160($sp)
  li    $at, 4
.L7F04D1F8:
  bne   $v0, $at, .L7F04D22C
   lw    $t9, 0x164($sp)
  lbu   $v0, 1($s1)
  lw    $v1, 4($s1)
  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
  andi  $t7, $v0, 0xf
  and   $t8, $v1, $at
  addu  $t0, $t9, $t8
  sll   $t1, $t7, 4
  subu  $s0, $t0, $t1
  b     .L7F04D1CC
   addiu $s1, $s1, 8
.L7F04D22C:
  li    $at, -65
  bne   $v0, $at, .L7F04D5BC
   li    $v1, 10
  lui   $t3, %hi(D_8003204C) 
  addiu $t3, %lo(D_8003204C) # addiu $t3, $t3, 0x204c
  lw    $at, ($t3)
  addiu $t2, $sp, 0xe8
  lw    $t5, 4($t3)
  sw    $at, ($t2)
  lw    $at, 8($t3)
  lui   $t7, %hi(D_80032058) 
  addiu $t7, %lo(D_80032058) # addiu $t7, $t7, 0x2058
  sw    $t5, 4($t2)
  sw    $at, 8($t2)
  lw    $at, ($t7)
  addiu $t6, $sp, 0xdc
  lw    $t9, 4($t7)
  sw    $at, ($t6)
  lw    $at, 8($t7)
  sw    $t9, 4($t6)
  move  $v0, $zero
  sw    $at, 8($t6)
  lbu   $t0, 5($s1)
  addiu $a0, $sp, 0xf8
  move  $a1, $fp
  div   $zero, $t0, $v1
  mflo  $t1
  sw    $t1, 0xf8($sp)
  lbu   $t4, 6($s1)
  bnez  $v1, .L7F04D2AC
   nop   
  break 7
.L7F04D2AC:
  li    $at, -1
  bne   $v1, $at, .L7F04D2C4
   lui   $at, 0x8000
  bne   $t0, $at, .L7F04D2C4
   nop   
  break 6
.L7F04D2C4:
  div   $zero, $t4, $v1
  mflo  $t2
  sw    $t2, 0xfc($sp)
  lbu   $t3, 7($s1)
  bnez  $v1, .L7F04D2E0
   nop   
  break 7
.L7F04D2E0:
  li    $at, -1
  bne   $v1, $at, .L7F04D2F8
   lui   $at, 0x8000
  bne   $t4, $at, .L7F04D2F8
   nop   
  break 6
.L7F04D2F8:
  div   $zero, $t3, $v1
  mflo  $t5
  sw    $t5, 0x100($sp)
  bnez  $v1, .L7F04D310
   nop   
  break 7
.L7F04D310:
  li    $at, -1
  bne   $v1, $at, .L7F04D328
   lui   $at, 0x8000
  bne   $t3, $at, .L7F04D328
   nop   
  break 6
.L7F04D328:
  lw    $t8, ($a0)
.L7F04D32C:
  lw    $t7, 0xe8($sp)
  addiu $a0, $a0, 4
  sll   $t6, $t8, 4
  addu  $v1, $s0, $t6
  lh    $v0, ($v1)
  addiu $t3, $sp, 0x104
  slt   $at, $v0, $t7
  beql  $at, $zero, .L7F04D35C
   lw    $t9, 0xdc($sp)
  sw    $v0, 0xe8($sp)
  lh    $v0, ($v1)
  lw    $t9, 0xdc($sp)
.L7F04D35C:
  slt   $at, $t9, $v0
  beql  $at, $zero, .L7F04D370
   lh    $v0, 2($v1)
  sw    $v0, 0xdc($sp)
  lh    $v0, 2($v1)
.L7F04D370:
  lw    $t0, 0xec($sp)
  slt   $at, $v0, $t0
  beql  $at, $zero, .L7F04D38C
   lw    $t1, 0xe0($sp)
  sw    $v0, 0xec($sp)
  lh    $v0, 2($v1)
  lw    $t1, 0xe0($sp)
.L7F04D38C:
  slt   $at, $t1, $v0
  beql  $at, $zero, .L7F04D3A0
   lh    $v0, 4($v1)
  sw    $v0, 0xe0($sp)
  lh    $v0, 4($v1)
.L7F04D3A0:
  lw    $t4, 0xf0($sp)
  slt   $at, $v0, $t4
  beql  $at, $zero, .L7F04D3BC
   lw    $t2, 0xe4($sp)
  sw    $v0, 0xf0($sp)
  lh    $v0, 4($v1)
  lw    $t2, 0xe4($sp)
.L7F04D3BC:
  slt   $at, $t2, $v0
  beqz  $at, .L7F04D3CC
   nop   
  sw    $v0, 0xe4($sp)
.L7F04D3CC:
  bnel  $a0, $t3, .L7F04D32C
   lw    $t8, ($a0)
  move  $a0, $s7
  addiu $a2, $sp, 0xe8
  jal   sub_GAME_7F0B6CEC
   addiu $a3, $sp, 0xdc
  beqz  $v0, .L7F04D970
   lui   $t5, %hi(D_80032064) 
  addiu $t5, %lo(D_80032064) # addiu $t5, $t5, 0x2064
  lw    $at, ($t5)
  addiu $a3, $sp, 0xc4
  addiu $t8, $sp, 0x11c
  sw    $at, ($a3)
  lw    $t6, 4($t5)
  sw    $t6, 4($a3)
  lw    $at, 8($t5)
  sw    $at, 8($a3)
  lw    $t4, 0x100($sp)
  lw    $t0, 0xfc($sp)
  lw    $t7, 0xf8($sp)
  lw    $t3, 0x154($sp)
  sll   $t2, $t4, 4
  sll   $t1, $t0, 4
  sll   $t9, $t7, 4
  addu  $a0, $s0, $t9
  addu  $a1, $s0, $t1
  addu  $a2, $s0, $t2
  sw    $t8, 0x1c($sp)
  sw    $fp, 0x18($sp)
  sw    $s7, 0x10($sp)
  jal   sub_GAME_7F092890
   sw    $t3, 0x14($sp)
  beqz  $v0, .L7F04D970
   nop   
  lwc1  $f4, 0x11c($sp)
  lwc1  $f8, ($s7)
  lwc1  $f18, 0x120($sp)
  trunc.w.s $f6, $f4
  lbu   $t1, ($s1)
  move  $v0, $s1
  trunc.w.s $f10, $f8
  mfc1  $t6, $f6
  lwc1  $f6, 4($s7)
  trunc.w.s $f4, $f18
  mfc1  $t9, $f10
  sltu  $at, $s3, $s1
  trunc.w.s $f8, $f6
  subu  $t0, $t6, $t9
  mtc1  $t0, $f16
  mfc1  $t4, $f4
  mfc1  $t3, $f8
  cvt.s.w $f2, $f16
  lwc1  $f16, 0x124($sp)
  lwc1  $f4, 8($s7)
  subu  $t8, $t4, $t3
  mtc1  $t8, $f10
  trunc.w.s $f18, $f16
  trunc.w.s $f6, $f4
  mfc1  $t7, $f18
  cvt.s.w $f12, $f10
  mfc1  $t9, $f6
  mul.s $f10, $f2, $f2
  subu  $t0, $t7, $t9
  mtc1  $t0, $f8
  mul.s $f16, $f12, $f12
  beq   $s5, $t1, .L7F04D4FC
   cvt.s.w $f14, $f8
  beqz  $at, .L7F04D4FC
   nop   
  lbu   $t2, -8($v0)
.L7F04D4E4:
  addiu $v0, $v0, -8
  sltu  $at, $s3, $v0
  beq   $s5, $t2, .L7F04D4FC
   nop   
  bnezl $at, .L7F04D4E4
   lbu   $t2, -8($v0)
.L7F04D4FC:
  mul.s $f4, $f14, $f14
  bnel  $v0, $s3, .L7F04D514
   lw    $v1, 4($v0)
  b     .L7F04D524
   li    $a0, -1
  lw    $v1, 4($v0)
.L7F04D514:
  lui   $at, 0x8000
  addiu $v1, $v1, -8
  or    $t4, $v1, $at
  lhu   $a0, ($t4)
.L7F04D524:
  add.s $f18, $f10, $f16
  add.s $f0, $f18, $f4
  c.lt.s $f0, $f20
  nop   
  bc1f  .L7F04D970
   nop   
  lwc1  $f6, 0x11c($sp)
  li    $t4, 1
  mov.s $f20, $f0
  swc1  $f6, ($s4)
  lwc1  $f8, 0x120($sp)
  swc1  $f8, 4($s4)
  lwc1  $f10, 0x124($sp)
  swc1  $f10, 8($s4)
  lwc1  $f16, 0x128($sp)
  swc1  $f16, 0xc($s4)
  lwc1  $f18, 0x12c($sp)
  swc1  $f18, 0x10($s4)
  lwc1  $f4, 0x130($sp)
  swc1  $f4, 0x14($s4)
  lw    $t3, 0xf8($sp)
  sll   $t8, $t3, 4
  addu  $t5, $t8, $s0
  sw    $t5, 0x18($s4)
  lw    $t6, 0xfc($sp)
  sll   $t7, $t6, 4
  addu  $t9, $t7, $s0
  sw    $t9, 0x1c($s4)
  lw    $t0, 0x100($sp)
  sh    $a0, 0x2a($s4)
  sw    $s1, 0x24($s4)
  sll   $t1, $t0, 4
  addu  $t2, $t1, $s0
  sw    $t2, 0x20($s4)
  sh    $zero, 0x28($s4)
  sw    $t4, 0x110($sp)
  b     .L7F04D1CC
   addiu $s1, $s1, 8
.L7F04D5BC:
  li    $at, -79
  bne   $v0, $at, .L7F04D970
   nop   
  move  $s2, $zero
.L7F04D5CC:
  lui   $t8, %hi(D_80032070) 
  addiu $t8, %lo(D_80032070) # addiu $t8, $t8, 0x2070
  lw    $at, ($t8)
  addiu $t3, $sp, 0x94
  lw    $t6, 4($t8)
  sw    $at, ($t3)
  lw    $at, 8($t8)
  lui   $t9, %hi(D_8003207C) 
  addiu $t9, %lo(D_8003207C) # addiu $t9, $t9, 0x207c
  sw    $t6, 4($t3)
  sw    $at, 8($t3)
  lw    $at, ($t9)
  addiu $t7, $sp, 0x88
  lw    $t1, 4($t9)
  sw    $at, ($t7)
  lw    $at, 8($t9)
  sw    $t1, 4($t7)
  bnez  $s2, .L7F04D640
   sw    $at, 8($t7)
  lw    $t2, 4($s1)
  andi  $t4, $t2, 0xf
  sw    $t4, 0xa4($sp)
  lbu   $t5, 7($s1)
  srl   $t3, $t5, 4
  sw    $t3, 0xa8($sp)
  lw    $t8, ($s1)
  andi  $t6, $t8, 0xf
  b     .L7F04D6CC
   sw    $t6, 0xac($sp)
.L7F04D640:
  li    $at, 1
  bnel  $s2, $at, .L7F04D678
   li    $at, 2
  lbu   $t0, 6($s1)
  andi  $t7, $t0, 0xf
  sw    $t7, 0xa4($sp)
  lhu   $t9, 6($s1)
  srl   $t1, $t9, 0xc
  sw    $t1, 0xa8($sp)
  lbu   $t2, 3($s1)
  srl   $t4, $t2, 4
  b     .L7F04D6CC
   sw    $t4, 0xac($sp)
  li    $at, 2
.L7F04D678:
  bnel  $s2, $at, .L7F04D6AC
   lbu   $t9, 4($s1)
  lhu   $t5, 4($s1)
  andi  $t3, $t5, 0xf
  sw    $t3, 0xa4($sp)
  lbu   $t8, 5($s1)
  srl   $t6, $t8, 4
  sw    $t6, 0xa8($sp)
  lbu   $t0, 2($s1)
  andi  $t7, $t0, 0xf
  b     .L7F04D6CC
   sw    $t7, 0xac($sp)
  lbu   $t9, 4($s1)
.L7F04D6AC:
  andi  $t1, $t9, 0xf
  sw    $t1, 0xa4($sp)
  lw    $t2, 4($s1)
  srl   $t4, $t2, 0x1c
  sw    $t4, 0xa8($sp)
  lhu   $t5, 2($s1)
  srl   $t3, $t5, 0xc
  sw    $t3, 0xac($sp)
.L7F04D6CC:
  addiu $a0, $sp, 0xa4
  lw    $t8, ($a0)
.L7F04D6D4:
  lw    $t0, 0x94($sp)
  addiu $a0, $a0, 4
  sll   $t6, $t8, 4
  addu  $v1, $s0, $t6
  lh    $v0, ($v1)
  slt   $at, $v0, $t0
  beql  $at, $zero, .L7F04D700
   lw    $t7, 0x88($sp)
  sw    $v0, 0x94($sp)
  lh    $v0, ($v1)
  lw    $t7, 0x88($sp)
.L7F04D700:
  slt   $at, $t7, $v0
  beql  $at, $zero, .L7F04D714
   lh    $v0, 2($v1)
  sw    $v0, 0x88($sp)
  lh    $v0, 2($v1)
.L7F04D714:
  lw    $t9, 0x98($sp)
  slt   $at, $v0, $t9
  beql  $at, $zero, .L7F04D730
   lw    $t1, 0x8c($sp)
  sw    $v0, 0x98($sp)
  lh    $v0, 2($v1)
  lw    $t1, 0x8c($sp)
.L7F04D730:
  slt   $at, $t1, $v0
  beql  $at, $zero, .L7F04D744
   lh    $v0, 4($v1)
  sw    $v0, 0x8c($sp)
  lh    $v0, 4($v1)
.L7F04D744:
  lw    $t2, 0x9c($sp)
  slt   $at, $v0, $t2
  beql  $at, $zero, .L7F04D760
   lw    $t4, 0x90($sp)
  sw    $v0, 0x9c($sp)
  lh    $v0, 4($v1)
  lw    $t4, 0x90($sp)
.L7F04D760:
  slt   $at, $t4, $v0
  beqz  $at, .L7F04D770
   nop   
  sw    $v0, 0x90($sp)
.L7F04D770:
  bnel  $a0, $s6, .L7F04D6D4
   lw    $t8, ($a0)
  move  $a0, $s7
  move  $a1, $fp
  addiu $a2, $sp, 0x94
  jal   sub_GAME_7F0B6CEC
   addiu $a3, $sp, 0x88
  beqz  $v0, .L7F04D960
   lui   $t5, %hi(D_80032088) 
  addiu $t5, %lo(D_80032088) # addiu $t5, $t5, 0x2088
  lw    $at, ($t5)
  addiu $a3, $sp, 0x70
  addiu $t3, $sp, 0x11c
  sw    $at, ($a3)
  lw    $t8, 4($t5)
  sw    $t8, 4($a3)
  lw    $at, 8($t5)
  sw    $at, 8($a3)
  lw    $t1, 0xac($sp)
  lw    $t7, 0xa8($sp)
  lw    $t6, 0xa4($sp)
  lw    $t4, 0x154($sp)
  sll   $t2, $t1, 4
  sll   $t9, $t7, 4
  sll   $t0, $t6, 4
  addu  $a0, $s0, $t0
  addu  $a1, $s0, $t9
  addu  $a2, $s0, $t2
  sw    $t3, 0x1c($sp)
  sw    $fp, 0x18($sp)
  sw    $s7, 0x10($sp)
  jal   sub_GAME_7F092890
   sw    $t4, 0x14($sp)
  beql  $v0, $zero, .L7F04D964
   addiu $s2, $s2, 1
  lwc1  $f6, 0x11c($sp)
  lwc1  $f10, ($s7)
  lwc1  $f4, 0x120($sp)
  trunc.w.s $f8, $f6
  lbu   $t9, ($s1)
  move  $v0, $s1
  trunc.w.s $f16, $f10
  mfc1  $t8, $f8
  lwc1  $f8, 4($s7)
  trunc.w.s $f6, $f4
  mfc1  $t0, $f16
  sltu  $at, $s3, $s1
  trunc.w.s $f10, $f8
  subu  $t7, $t8, $t0
  mtc1  $t7, $f18
  mfc1  $t1, $f6
  mfc1  $t4, $f10
  cvt.s.w $f2, $f18
  lwc1  $f18, 0x124($sp)
  lwc1  $f6, 8($s7)
  subu  $t3, $t1, $t4
  mtc1  $t3, $f16
  trunc.w.s $f4, $f18
  trunc.w.s $f8, $f6
  mfc1  $t6, $f4
  cvt.s.w $f12, $f16
  mfc1  $t0, $f8
  mul.s $f16, $f2, $f2
  subu  $t7, $t6, $t0
  mtc1  $t7, $f10
  mul.s $f18, $f12, $f12
  beq   $s5, $t9, .L7F04D8A4
   cvt.s.w $f14, $f10
  beqz  $at, .L7F04D8A4
   nop   
  lbu   $t2, -8($v0)
.L7F04D88C:
  addiu $v0, $v0, -8
  sltu  $at, $s3, $v0
  beq   $s5, $t2, .L7F04D8A4
   nop   
  bnezl $at, .L7F04D88C
   lbu   $t2, -8($v0)
.L7F04D8A4:
  mul.s $f6, $f14, $f14
  bnel  $v0, $s3, .L7F04D8BC
   lw    $v1, 4($v0)
  b     .L7F04D8CC
   li    $a0, -1
  lw    $v1, 4($v0)
.L7F04D8BC:
  lui   $at, 0x8000
  addiu $v1, $v1, -8
  or    $t1, $v1, $at
  lhu   $a0, ($t1)
.L7F04D8CC:
  add.s $f4, $f16, $f18
  add.s $f0, $f4, $f6
  c.lt.s $f0, $f20
  nop   
  bc1fl .L7F04D964
   addiu $s2, $s2, 1
  lwc1  $f8, 0x11c($sp)
  addiu $t1, $s2, 1
  mov.s $f20, $f0
  swc1  $f8, ($s4)
  lwc1  $f10, 0x120($sp)
  swc1  $f10, 4($s4)
  lwc1  $f16, 0x124($sp)
  swc1  $f16, 8($s4)
  lwc1  $f18, 0x128($sp)
  swc1  $f18, 0xc($s4)
  lwc1  $f4, 0x12c($sp)
  swc1  $f4, 0x10($s4)
  lwc1  $f6, 0x130($sp)
  swc1  $f6, 0x14($s4)
  lw    $t4, 0xa4($sp)
  sll   $t3, $t4, 4
  addu  $t5, $t3, $s0
  sw    $t5, 0x18($s4)
  lw    $t8, 0xa8($sp)
  li    $t4, 1
  sll   $t6, $t8, 4
  addu  $t0, $t6, $s0
  sw    $t0, 0x1c($s4)
  lw    $t7, 0xac($sp)
  sh    $a0, 0x2a($s4)
  sw    $s1, 0x24($s4)
  sll   $t9, $t7, 4
  addu  $t2, $t9, $s0
  sw    $t2, 0x20($s4)
  sh    $t1, 0x28($s4)
  sw    $t4, 0x110($sp)
.L7F04D960:
  addiu $s2, $s2, 1
.L7F04D964:
  li    $at, 4
  bne   $s2, $at, .L7F04D5CC
   nop   
.L7F04D970:
  b     .L7F04D1CC
   addiu $s1, $s1, 8
.L7F04D978:
  lw    $ra, 0x54($sp)
  lw    $v0, 0x110($sp)
  ldc1  $f20, 0x28($sp)
  lw    $s0, 0x30($sp)
  lw    $s1, 0x34($sp)
  lw    $s2, 0x38($sp)
  lw    $s3, 0x3c($sp)
  lw    $s4, 0x40($sp)
  lw    $s5, 0x44($sp)
  lw    $s6, 0x48($sp)
  lw    $s7, 0x4c($sp)
  lw    $fp, 0x50($sp)
  jr    $ra
   addiu $sp, $sp, 0x150
");






asm(R"
.late_rodata
glabel D_80052D98
.word 0x46fffe00 /*32767.0*/
/*D:80052D9C*/
glabel jpt_80052D9C
.word loc_CODE_7F04DAA4
.word def_7F04DA40
.word def_7F04DA40
.word def_7F04DA40
.word loc_CODE_7F04DAD8
.word def_7F04DA40
.word def_7F04DA40
.word def_7F04DA40
.word def_7F04DA40
.word def_7F04DA40
.word def_7F04DA40
.word def_7F04DA40
.word def_7F04DA40
.word def_7F04DA40
.word loc_CODE_7F04DAEC
.word def_7F04DA40
.word def_7F04DA40
.word def_7F04DA40
.word def_7F04DA40
.word loc_CODE_7F04DB00
.word loc_CODE_7F04DA48

/*D:80052DF0*/
/*hack, doesn't fit in own function*/
glabel jpt_80052DF0
.word destroyable_object
.word nondestroyable_object
.word destroyable_object
.word nondestroyable_object
.word destroyable_object
.word destroyable_object
.word nondestroyable_object
.word nondestroyable_object
.word nondestroyable_object
.word destroyable_object
.word destroyable_object
.word destroyable_object
.word destroyable_object
.word nondestroyable_object
.word nondestroyable_object
.word nondestroyable_object
.word nondestroyable_object
.word nondestroyable_object
.word nondestroyable_object
.word nondestroyable_object
.word nondestroyable_object
.word nondestroyable_object
.word nondestroyable_object
.word nondestroyable_object
.word nondestroyable_object
.word nondestroyable_object
.word nondestroyable_object
.word nondestroyable_object
.word nondestroyable_object
.word nondestroyable_object
.word nondestroyable_object
.word nondestroyable_object
.word nondestroyable_object
.word nondestroyable_object
.word nondestroyable_object
.word destroyable_object
.word nondestroyable_object
.word nondestroyable_object

.text
glabel sub_GAME_7F04D9B0
  addiu $sp, $sp, -0xf8
  sw    $fp, 0x50($sp)
  sw    $s6, 0x48($sp)
  sw    $s2, 0x38($sp)
  sw    $s0, 0x30($sp)
  move  $s2, $a1
  move  $s6, $a0
  sw    $ra, 0x54($sp)
  sw    $s7, 0x4c($sp)
  sw    $s5, 0x44($sp)
  sw    $s4, 0x40($sp)
  sw    $s3, 0x3c($sp)
  sw    $s1, 0x34($sp)
  sdc1  $f20, 0x28($sp)
  sw    $a2, 0x100($sp)
  sw    $a3, 0x104($sp)
  sw    $zero, 0xd0($sp)
  sw    $zero, 0xcc($sp)
  move  $s0, $a1
  beqz  $a1, .L7F04DC7C
   move  $fp, $zero
  lui   $at, %hi(D_80052D98)
  lui   $s7, (0x00FFFFFF >> 16) # lui $s7, 0xff
  ori   $s7, (0x00FFFFFF & 0xFFFF) # ori $s7, $s7, 0xffff
  lwc1  $f20, %lo(D_80052D98)($at)
  lhu   $v0, ($s0)
.L7F04DA18:
  move  $s3, $zero
  move  $s5, $zero
  andi  $t6, $v0, 0xff
  addiu $t7, $t6, -4
  sltiu $at, $t7, 0x15
  beqz  $at, .L7F04DB0C
   sll   $t7, $t7, 2
  lui   $at, %hi(jpt_80052D9C)
  addu  $at, $at, $t7
  lw    $t7, %lo(jpt_80052D9C)($at)
  jr    $t7
   nop   
loc_CODE_7F04DA48:
  lw    $s1, 4($s0)
  move  $a0, $s6
  jal   extract_id_from_object_structure_microcode
   move  $a1, $s0
  lw    $v1, 4($v0)
  beqz  $v1, .L7F04DB0C
   nop   
  lw    $a0, ($s1)
  move  $s3, $v1
  bne   $a0, $v1, .L7F04DA84
   nop   
  lw    $t8, 0x1c($s1)
  and   $t9, $a0, $s7
  b     .L7F04DA84
   addu  $s3, $t8, $t9
.L7F04DA84:
  lw    $v1, 4($s1)
  beqz  $v1, .L7F04DA9C
   nop   
  lw    $t0, 0x1c($s1)
  and   $t1, $v1, $s7
  addu  $s5, $t0, $t1
.L7F04DA9C:
  b     .L7F04DB0C
   lw    $fp, ($v0)
loc_CODE_7F04DAA4:
  lw    $v0, 4($s0)
  lw    $a0, ($v0)
  beqz  $a0, .L7F04DB0C
   nop   
  lw    $a1, 4($v0)
  lw    $v1, 8($v0)
  and   $t2, $a0, $s7
  beqz  $a1, .L7F04DAD0
   addu  $s3, $v1, $t2
  and   $t3, $a1, $s7
  addu  $s5, $v1, $t3
.L7F04DAD0:
  b     .L7F04DB0C
   move  $fp, $v1
loc_CODE_7F04DAD8:
  move  $a0, $s6
  jal   sub_GAME_7F06E970
   move  $a1, $s0
  b     .L7F04DB0C
   nop   
loc_CODE_7F04DAEC:
  move  $a0, $s6
  jal   process_12_handle_switch
   move  $a1, $s0
  b     .L7F04DB0C
   nop   
loc_CODE_7F04DB00:
  move  $a0, $s6
  jal   process_17_pointer_to_head
   move  $a1, $s0
def_7F04DA40:
.L7F04DB0C:
  beqz  $s3, .L7F04DC1C
   move  $a0, $s0
  move  $a1, $zero
  jal   sub_GAME_7F06C570
   move  $s1, $zero
  bltz  $v0, .L7F04DB34
   move  $s4, $v0
  lw    $t4, 0xc($s6)
  sll   $t5, $v0, 6
  addu  $s1, $t4, $t5
.L7F04DB34:
  beqz  $s1, .L7F04DBDC
   lw    $t6, 0xd0($sp)
  beq   $s1, $t6, .L7F04DBDC
   move  $a0, $s1
  sw    $s1, 0xd0($sp)
  jal   sub_GAME_7F059FB8
   addiu $a1, $sp, 0x64
  lw    $t7, 0x100($sp)
  addiu $a0, $sp, 0x64
  addiu $a1, $sp, 0xec
  lwc1  $f4, ($t7)
  swc1  $f4, 0xec($sp)
  lwc1  $f6, 4($t7)
  swc1  $f6, 0xf0($sp)
  lwc1  $f8, 8($t7)
  jal   sub_GAME_7F058474
   swc1  $f8, 0xf4($sp)
  lw    $t8, 0x104($sp)
  addiu $a0, $sp, 0x64
  addiu $a1, $sp, 0xd4
  lwc1  $f10, ($t8)
  swc1  $f10, 0xd4($sp)
  lwc1  $f16, 4($t8)
  swc1  $f16, 0xd8($sp)
  lwc1  $f18, 8($t8)
  jal   sub_GAME_7F0583D8
   swc1  $f18, 0xdc($sp)
  lwc1  $f4, 0xd4($sp)
  lwc1  $f8, 0xec($sp)
  lwc1  $f16, 0xd8($sp)
  mul.s $f6, $f4, $f20
  lwc1  $f4, 0xf0($sp)
  mul.s $f18, $f16, $f20
  lwc1  $f16, 0xf4($sp)
  add.s $f10, $f6, $f8
  lwc1  $f8, 0xdc($sp)
  add.s $f6, $f18, $f4
  swc1  $f10, 0xe0($sp)
  mul.s $f10, $f8, $f20
  swc1  $f6, 0xe4($sp)
  add.s $f18, $f10, $f16
  swc1  $f18, 0xe8($sp)
.L7F04DBDC:
  lw    $t9, 0x108($sp)
  addiu $a0, $sp, 0xec
  addiu $a1, $sp, 0xe0
  addiu $a2, $sp, 0xd4
  move  $a3, $s3
  sw    $s5, 0x10($sp)
  sw    $fp, 0x14($sp)
  jal   sub_GAME_7F04D16C
   sw    $t9, 0x18($sp)
  beqz  $v0, .L7F04DC1C
   lw    $t0, 0x10c($sp)
  sw    $s4, ($t0)
  lw    $t1, 0x110($sp)
  li    $t2, 1
  sw    $s0, ($t1)
  sw    $t2, 0xcc($sp)
.L7F04DC1C:
  lw    $v0, 0x14($s0)
  lw    $t3, 0xcc($sp)
  beqz  $v0, .L7F04DC34
   nop   
  b     .L7F04DC6C
   move  $s0, $v0
.L7F04DC34:
  beqz  $s0, .L7F04DC6C
   nop   
.L7F04DC3C:
  bnel  $s0, $s2, .L7F04DC50
   lw    $v0, 0xc($s0)
  b     .L7F04DC6C
   move  $s0, $zero
  lw    $v0, 0xc($s0)
.L7F04DC50:
  beql  $v0, $zero, .L7F04DC64
   lw    $s0, 8($s0)
  b     .L7F04DC6C
   move  $s0, $v0
  lw    $s0, 8($s0)
.L7F04DC64:
  bnez  $s0, .L7F04DC3C
   nop   
.L7F04DC6C:
  beql  $s0, $zero, .L7F04DC80
   lw    $ra, 0x54($sp)
  beql  $t3, $zero, .L7F04DA18
   lhu   $v0, ($s0)
.L7F04DC7C:
  lw    $ra, 0x54($sp)
.L7F04DC80:
  lw    $v0, 0xcc($sp)
  ldc1  $f20, 0x28($sp)
  lw    $s0, 0x30($sp)
  lw    $s1, 0x34($sp)
  lw    $s2, 0x38($sp)
  lw    $s3, 0x3c($sp)
  lw    $s4, 0x40($sp)
  lw    $s5, 0x44($sp)
  lw    $s6, 0x48($sp)
  lw    $s7, 0x4c($sp)
  lw    $fp, 0x50($sp)
  jr    $ra
   addiu $sp, $sp, 0xf8
");






asm(R"
.late_rodata
/*hack, doesnt fit in own data above*/
.word destroyable_object
.word destroyable_object
.word destroyable_object
.word destroyable_object
.word destroyable_object
.word nondestroyable_object
.word destroyable_object
.word nondestroyable_object
.word destroyable_object

.text
glabel sub_GAME_7F04DCB4
  addiu $sp, $sp, -0x40
  sw    $ra, 0x34($sp)
  sw    $s0, 0x30($sp)
  lw    $t6, 0x10($a0)
  move  $s0, $a0
  jal   sub_GAME_7F040078
   sw    $t6, 0x3c($sp)
  lw    $a0, 0x3c($sp)
  move  $a1, $zero
  jal   sub_GAME_7F0A0CCC
   sw    $v0, 0x38($sp)
  lw    $a0, 0x3c($sp)
  jal   sub_GAME_7F0A0CCC
   li    $a1, 1
  lw    $v1, 0x38($sp)
  addiu $a0, $s0, 0x58
  addiu $a1, $s0, 0x18
  lwc1  $f4, 4($v1)
  addiu $a2, $s0, 0x28
  addiu $a3, $s0, 0x38
  swc1  $f4, 0x10($sp)
  lwc1  $f6, 8($v1)
  swc1  $f6, 0x14($sp)
  lwc1  $f8, 0xc($v1)
  swc1  $f8, 0x18($sp)
  lwc1  $f10, 0x10($v1)
  swc1  $f10, 0x1c($sp)
  lwc1  $f16, 0x14($v1)
  swc1  $f16, 0x20($sp)
  lwc1  $f18, 0x18($v1)
  jal   sub_GAME_7F0A1DA0
   swc1  $f18, 0x24($sp)
  lw    $t7, 0x64($s0)
  lbu   $t9, 2($s0)
  mtc1  $zero, $f4
  ori   $t8, $t7, 4
  ori   $t0, $t9, 0x80
  sw    $t8, 0x64($s0)
  sb    $t0, 2($s0)
  swc1  $f4, 0x70($s0)
  lw    $ra, 0x34($sp)
  lw    $s0, 0x30($sp)
  addiu $sp, $sp, 0x40
  jr    $ra
   nop   
");






asm(R"
glabel sub_GAME_7F04DD68
  addiu $sp, $sp, -0x80
  sw    $ra, 0x2c($sp)
  lw    $t6, 0x10($a0)
  addiu $a1, $sp, 0x30
  sw    $t6, 0x7c($sp)
  lw    $v1, 0x14($a0)
  lw    $t7, 8($v1)
  lw    $t8, 8($t7)
  lw    $t9, 8($t8)
  lw    $v0, 4($t9)
  sw    $v1, 0x78($sp)
  jal   sub_GAME_7F0526EC
   sw    $v0, 0x74($sp)
  lw    $v0, 0x74($sp)
  addiu $a0, $sp, 0x60
  addiu $a1, $sp, 0x30
  lwc1  $f4, 4($v0)
  addiu $a2, $sp, 0x40
  addiu $a3, $sp, 0x50
  swc1  $f4, 0x10($sp)
  lwc1  $f6, 8($v0)
  swc1  $f6, 0x14($sp)
  lwc1  $f8, 0xc($v0)
  swc1  $f8, 0x18($sp)
  lwc1  $f10, 0x10($v0)
  swc1  $f10, 0x1c($sp)
  lwc1  $f16, 0x14($v0)
  swc1  $f16, 0x20($sp)
  lwc1  $f18, 0x18($v0)
  jal   sub_GAME_7F0A1DA0
   swc1  $f18, 0x24($sp)
  lw    $a0, 0x7c($sp)
  jal   sub_GAME_7F0A0CCC
   li    $a1, 1
  lw    $a0, 0x78($sp)
  lw    $t0, 8($a0)
  lw    $t1, 8($t0)
  jal   extract_id_from_object_structure_microcode
   lw    $a1, 4($t1)
  sw    $zero, ($v0)
  lw    $ra, 0x2c($sp)
  addiu $sp, $sp, 0x80
  jr    $ra
   nop   
");






asm(R"
.late_rodata
/*hack, part of check_if_collectable_object*/
glabel jpt_80052EAC
.word collectable_object
.word notcollectable_object
.word notcollectable_object
.word collectable_object
.word collectable_object
.word notcollectable_object
.word notcollectable_object
.word notcollectable_object
.word notcollectable_object
.word notcollectable_object
.word notcollectable_object
.word notcollectable_object
.word notcollectable_object
.word collectable_object
.word notcollectable_object
.word notcollectable_object
.word collectable_object
.word collectable_object

.text
glabel sub_GAME_7F04DE18
  addiu $sp, $sp, -0x98
  sw    $ra, 0x34($sp)
  sw    $s0, 0x30($sp)
  lw    $t6, 0x10($a0)
  sw    $t6, 0x94($sp)
  lbu   $t8, 1($t6)
  lw    $s0, 0x14($a0)
  andi  $t9, $t8, 2
  beql  $t9, $zero, .L7F04DEC8
   lw    $a0, 0x94($sp)
  lw    $t0, 8($s0)
  move  $a0, $s0
  move  $a2, $zero
  lw    $v0, 8($t0)
  lw    $t1, 8($v0)
  lw    $a1, 4($v0)
  lw    $v1, 4($t1)
  jal   sub_GAME_7F06C660
   sw    $v1, 0x88($sp)
  jal   sub_GAME_7F078444
   sw    $v0, 0x84($sp)
  move  $a0, $v0
  lw    $a1, 0x84($sp)
  jal   sub_GAME_7F05818C
   addiu $a2, $sp, 0x44
  lw    $v1, 0x88($sp)
  addiu $a0, $sp, 0x74
  addiu $a1, $sp, 0x44
  lwc1  $f4, 4($v1)
  addiu $a2, $sp, 0x54
  addiu $a3, $sp, 0x64
  swc1  $f4, 0x10($sp)
  lwc1  $f6, 8($v1)
  swc1  $f6, 0x14($sp)
  lwc1  $f8, 0xc($v1)
  swc1  $f8, 0x18($sp)
  lwc1  $f10, 0x10($v1)
  swc1  $f10, 0x1c($sp)
  lwc1  $f16, 0x14($v1)
  swc1  $f16, 0x20($sp)
  lwc1  $f18, 0x18($v1)
  jal   sub_GAME_7F0A1DA0
   swc1  $f18, 0x24($sp)
  lw    $a0, 0x94($sp)
.L7F04DEC8:
  jal   sub_GAME_7F0A0CCC
   li    $a1, 1
  lw    $t2, 8($s0)
  move  $a0, $s0
  lw    $t3, 8($t2)
  jal   extract_id_from_object_structure_microcode
   lw    $a1, 0xc($t3)
  sw    $zero, ($v0)
  lw    $ra, 0x34($sp)
  lw    $s0, 0x30($sp)
  addiu $sp, $sp, 0x98
  jr    $ra
   nop   
");






asm(R"
glabel sub_GAME_7F04DEFC
  addiu $sp, $sp, -0x40
  sw    $ra, 0x3c($sp)
  sw    $s4, 0x38($sp)
  sw    $s3, 0x34($sp)
  sw    $s2, 0x30($sp)
  sw    $s1, 0x2c($sp)
  sw    $s0, 0x28($sp)
  sdc1  $f20, 0x20($sp)
  sw    $a0, 0x40($sp)
  lw    $v0, 4($a0)
  lw    $s2, 0x50($sp)
  lui   $at, (0xFFF9FFFF >> 16) # lui $at, 0xfff9
  lw    $t7, 0x64($v0)
  ori   $at, (0xFFF9FFFF & 0xFFFF) # ori $at, $at, 0xffff
  sll   $t0, $s2, 0x11
  and   $t8, $t7, $at
  or    $t1, $t8, $t0
  mtc1  $a1, $f20
  sll   $t3, $t1, 0xc
  sw    $t8, 0x64($v0)
  move  $s3, $a2
  move  $s4, $a3
  bltz  $t3, .L7F04DFAC
   sw    $t1, 0x64($v0)
  lw    $t4, 0x40($sp)
  lw    $s0, 0x20($t4)
  beql  $s0, $zero, .L7F04DF94
   lw    $t5, 0x40($sp)
.L7F04DF6C:
  lw    $s1, 0x24($s0)
  mfc1  $a1, $f20
  sw    $s2, 0x10($sp)
  move  $a0, $s0
  move  $a2, $s3
  jal   sub_GAME_7F04DEFC
   move  $a3, $s4
  bnez  $s1, .L7F04DF6C
   move  $s0, $s1
  lw    $t5, 0x40($sp)
.L7F04DF94:
  mfc1  $a1, $f20
  move  $a2, $s3
  lw    $a0, 4($t5)
  sw    $s2, 0x10($sp)
  jal   maybe_detonate_object
   move  $a3, $s4
.L7F04DFAC:
  lw    $ra, 0x3c($sp)
  ldc1  $f20, 0x20($sp)
  lw    $s0, 0x28($sp)
  lw    $s1, 0x2c($sp)
  lw    $s2, 0x30($sp)
  lw    $s3, 0x34($sp)
  lw    $s4, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x40
");






asm(R"
.text
glabel check_if_destroyable_object_type
  lbu   $t6, 3($a0)
  addiu $t7, $t6, -1
  sltiu $at, $t7, 0x2f
  beqz  $at, .L7F04E000
   sll   $t7, $t7, 2
  lui   $at, %hi(jpt_80052DF0)
  addu  $at, $at, $t7
  lw    $t7, %lo(jpt_80052DF0)($at)
  jr    $t7
   nop   
destroyable_object:
  jr    $ra
   li    $v0, 1

nondestroyable_object:
.L7F04E000:
  move  $v0, $zero
  jr    $ra
   nop   
");






asm(R"
glabel check_if_collectable_object
  lbu   $t6, 3($a0)
  addiu $t7, $t6, -4
  sltiu $at, $t7, 0x12
  beqz  $at, .L7F04E03C
   sll   $t7, $t7, 2
  lui   $at, %hi(jpt_80052EAC)
  addu  $at, $at, $t7
  lw    $t7, %lo(jpt_80052EAC)($at)
  jr    $t7
   nop   
collectable_object:
  jr    $ra
   li    $v0, 1

notcollectable_object:
.L7F04E03C:
  move  $v0, $zero
  jr    $ra
   nop   
");






asm(R"
glabel check_if_destroyable_not_invincible
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lbu   $t6, 3($a0)
  li    $at, 1
  bne   $t6, $at, .L7F04E068
   nop   
  b     .L7F04E0BC
   move  $v0, $zero
.L7F04E068:
  jal   check_if_collectable_object
   sw    $a0, 0x18($sp)
  beqz  $v0, .L7F04E0A0
   lw    $a0, 0x18($sp)
  lbu   $t7, 3($a0)
  li    $at, 21
  beql  $t7, $at, .L7F04E0A4
   lw    $t0, 8($a0)
  lw    $t8, 8($a0)
  sll   $t9, $t8, 0xf
  bltzl $t9, .L7F04E0BC
   li    $v0, 1
  b     .L7F04E0BC
   move  $v0, $zero
.L7F04E0A0:
  lw    $t0, 8($a0)
.L7F04E0A4:
  sll   $t1, $t0, 0xe
  bgezl $t1, .L7F04E0BC
   li    $v0, 1
  b     .L7F04E0BC
   move  $v0, $zero
  li    $v0, 1
.L7F04E0BC:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");






asm(R"
glabel sub_GAME_7F04E0CC
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  lw    $t6, 0xc($a0)
  mtc1  $a1, $f12
  lw    $t8, 0x30($sp)
  andi  $t7, $t6, 0x4000
  bnezl $t7, .L7F04E0FC
   lw    $ra, 0x1c($sp)
  mfc1  $a1, $f12
  jal   maybe_detonate_object
   sw    $t8, 0x10($sp)
  lw    $ra, 0x1c($sp)
.L7F04E0FC:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");






asm(R"
glabel maybe_detonate_object
  addiu $sp, $sp, -0xe0
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a2, 0xe8($sp)
  sw    $a3, 0xec($sp)
  lw    $t6, 0x64($a0)
  lui   $at, (0xFFF9FFFF >> 16) # lui $at, 0xfff9
  ori   $at, (0xFFF9FFFF & 0xFFFF) # ori $at, $at, 0xffff
  and   $t7, $t6, $at
  sw    $t7, 0x64($a0)
  lw    $t9, 0xf0($sp)
  lbu   $t3, 3($a0)
  mtc1  $a1, $f12
  sll   $t1, $t9, 0x11
  or    $t2, $t7, $t1
  li    $at, 36
  move  $s0, $a0
  bne   $t3, $at, .L7F04E168
   sw    $t2, 0x64($a0)
  jal   do_something_if_object_destroyed
   swc1  $f12, 0xe4($sp)
  li    $at, 1
  beq   $v0, $at, .L7F04E70C
   lwc1  $f12, 0xe4($sp)
.L7F04E168:
  lw    $t4, 0xec($sp)
  move  $a0, $s0
  bnezl $t4, .L7F04E1BC
   lw    $v1, 8($s0)
  jal   check_if_collectable_object
   swc1  $f12, 0xe4($sp)
  beqz  $v0, .L7F04E1A0
   lwc1  $f12, 0xe4($sp)
  lw    $t5, 8($s0)
  sll   $t6, $t5, 8
  bltzl $t6, .L7F04E2A8
   move  $a0, $s0
  b     .L7F04E710
   lw    $ra, 0x1c($sp)
.L7F04E1A0:
  lw    $t7, 8($s0)
  sll   $t9, $t7, 7
  bgezl $t9, .L7F04E2A8
   move  $a0, $s0
  b     .L7F04E710
   lw    $ra, 0x1c($sp)
  lw    $v1, 8($s0)
.L7F04E1BC:
  sll   $t8, $v1, 0xe
  bltzl $t8, .L7F04E710
   lw    $ra, 0x1c($sp)
  lbu   $v0, 3($s0)
  li    $a1, 8
  li    $a0, 7
  bne   $a1, $v0, .L7F04E22C
   nop   
  lb    $v0, 0x80($s0)
  li    $at, 26
  beq   $v0, $at, .L7F04E224
   li    $at, 27
  beq   $v0, $at, .L7F04E224
   li    $at, 29
  beq   $v0, $at, .L7F04E224
   li    $at, 28
  beq   $v0, $at, .L7F04E224
   li    $at, 86
  beq   $v0, $at, .L7F04E224
   li    $at, 87
  beq   $v0, $at, .L7F04E224
   li    $at, 33
  beq   $v0, $at, .L7F04E224
   li    $at, 34
  bnel  $v0, $at, .L7F04E710
   lw    $ra, 0x1c($sp)
.L7F04E224:
  b     .L7F04E70C
   sh    $zero, 0x82($s0)
.L7F04E22C:
  bnel  $a0, $v0, .L7F04E294
   move  $a0, $s0
  lw    $v0, 0x80($s0)
  li    $at, 5
  beq   $v0, $at, .L7F04E280
   li    $at, 6
  beql  $v0, $at, .L7F04E284
   lui   $at, 0x1000
  beql  $a0, $v0, .L7F04E284
   lui   $at, 0x1000
  beq   $a1, $v0, .L7F04E280
   li    $at, 9
  beq   $v0, $at, .L7F04E280
   li    $at, 11
  beq   $v0, $at, .L7F04E280
   li    $at, 15
  beq   $v0, $at, .L7F04E280
   li    $at, 16
  beq   $v0, $at, .L7F04E280
   li    $at, 19
  bne   $v0, $at, .L7F04E70C
.L7F04E280:
   li    $at, 0x10000000 # 0.000000
.L7F04E284:
  or    $t1, $v1, $at
  b     .L7F04E70C
   sw    $t1, 8($s0)
  move  $a0, $s0
.L7F04E294:
  jal   check_if_destroyable_not_invincible
   swc1  $f12, 0xe4($sp)
  beqz  $v0, .L7F04E70C
   lwc1  $f12, 0xe4($sp)
  move  $a0, $s0
.L7F04E2A8:
  jal   do_something_if_object_destroyed
   swc1  $f12, 0xe4($sp)
  bnez  $v0, .L7F04E2D4
   lwc1  $f12, 0xe4($sp)
  li    $at, 0x437A0000 # 250.000000
  mtc1  $at, $f6
  lwc1  $f4, 0x70($s0)
  mul.s $f8, $f12, $f6
  add.s $f10, $f4, $f8
  b     .L7F04E34C
   swc1  $f10, 0x70($s0)
.L7F04E2D4:
  move  $a0, $s0
  jal   sub_GAME_7F03FF60
   swc1  $f12, 0xe4($sp)
  li    $t3, 4
  lwc1  $f12, 0xe4($sp)
  bgez  $v0, .L7F04E2FC
   andi  $t2, $v0, 3
  beqz  $t2, .L7F04E2FC
   nop   
  addiu $t2, $t2, -4
.L7F04E2FC:
  subu  $t4, $t3, $t2
  mtc1  $t4, $f16
  li    $at, 0x3F800000 # 1.000000
  cvt.s.w $f0, $f16
  c.lt.s $f0, $f12
  nop   
  bc1fl .L7F04E328
   mtc1  $at, $f0
  b     .L7F04E340
   mov.s $f12, $f0
  mtc1  $at, $f0
.L7F04E328:
  nop   
  c.lt.s $f12, $f0
  nop   
  bc1fl .L7F04E344
   lwc1  $f18, 0x70($s0)
  mov.s $f12, $f0
.L7F04E340:
  lwc1  $f18, 0x70($s0)
.L7F04E344:
  add.s $f6, $f18, $f12
  swc1  $f6, 0x70($s0)
.L7F04E34C:
  lbu   $v0, 3($s0)
  li    $at, 42
  beq   $v0, $at, .L7F04E364
   li    $at, 47
  bne   $v0, $at, .L7F04E38C
   li    $a1, 1
.L7F04E364:
  lwc1  $f4, 0x70($s0)
  lwc1  $f8, 0x74($s0)
  c.le.s $f8, $f4
  nop   
  bc1fl .L7F04E3AC
   li    $at, 20
  jal   sub_GAME_7F04DCB4
   move  $a0, $s0
  b     .L7F04E3A8
   lbu   $v0, 3($s0)
.L7F04E38C:
  jal   sub_GAME_7F04BFD0
   lw    $a0, 0x10($s0)
  move  $a0, $s0
  lw    $a1, 0xe8($sp)
  jal   object_explosion_related
   lw    $a2, 0xf0($sp)
  lbu   $v0, 3($s0)
.L7F04E3A8:
  li    $at, 20
.L7F04E3AC:
  bnel  $v0, $at, .L7F04E544
   lbu   $v0, 3($s0)
  jal   do_something_if_object_destroyed
   move  $a0, $s0
  li    $at, 1
  bnel  $v0, $at, .L7F04E544
   lbu   $v0, 3($s0)
  jal   get_random_value
   nop   
  li    $at, 13
  divu  $zero, $v0, $at
  mfhi  $a0
  move  $a1, $a0
  nop   
  sll   $t5, $a0, 2
.L7F04E3E8:
  addu  $v1, $s0, $t5
  lhu   $t6, 0x82($v1)
  blezl $t6, .L7F04E52C
   addiu $a0, $a0, 1
  lhu   $t7, 0x80($v1)
  li    $at, 65535
  beql  $t7, $at, .L7F04E52C
   addiu $a0, $a0, 1
  sw    $v1, 0x24($sp)
  sw    $a0, 0xc4($sp)
  jal   sub_GAME_7F0518D0
   sw    $a1, 0xc8($sp)
  lw    $v1, 0x24($sp)
  lw    $a0, 0xc4($sp)
  lw    $a1, 0xc8($sp)
  beqz  $v0, .L7F04E528
   move  $a2, $v0
  lui   $t9, %hi(blank_07_object) 
  addiu $t0, $sp, 0x3c
  addiu $t9, %lo(blank_07_object) # addiu $t9, $t9, 0x2094
  lhu   $a3, 0x80($v1)
  addiu $t1, $t9, 0x78
  move  $t3, $t0
.L7F04E444:
  lw    $at, ($t9)
  addiu $t9, $t9, 0xc
  addiu $t3, $t3, 0xc
  sw    $at, -0xc($t3)
  lw    $at, -8($t9)
  sw    $at, -8($t3)
  lw    $at, -4($t9)
  bne   $t9, $t1, .L7F04E444
   sw    $at, -4($t3)
  lw    $at, ($t9)
  move  $t5, $t0
  move  $t6, $v0
  sw    $at, ($t3)
  lw    $t1, 4($t9)
  addiu $t4, $t0, 0x78
  sll   $t8, $a3, 2
  sw    $t1, 4($t3)
.L7F04E488:
  lw    $at, ($t5)
  addiu $t5, $t5, 0xc
  addiu $t6, $t6, 0xc
  sw    $at, -0xc($t6)
  lw    $at, -8($t5)
  sw    $at, -8($t6)
  lw    $at, -4($t5)
  bne   $t5, $t4, .L7F04E488
   sw    $at, -4($t6)
  lw    $at, ($t5)
  addiu $a1, $a0, 1
  move  $a0, $a2
  sw    $at, ($t6)
  lw    $t4, 4($t5)
  li    $at, 2
  subu  $t8, $t8, $a3
  sw    $t4, 4($t6)
  sh    $a3, 4($v0)
  bne   $a1, $at, .L7F04E4E0
   sw    $a1, 0x80($v0)
  li    $t7, 1
  sw    $t7, 0x80($v0)
.L7F04E4E0:
  sll   $t8, $t8, 2
  lui   $a1, %hi(PitemZ_entries)
  addu  $a1, $a1, $t8
  lw    $a1, %lo(PitemZ_entries)($a1)
  jal   sub_GAME_7F0406F8
   sw    $a2, 0xc0($sp)
  beqz  $v0, .L7F04E540
   lw    $a2, 0xc0($sp)
  lw    $a0, 0x14($a2)
  lw    $a1, 0x14($a0)
  jal   set_obj_instance_controller_scale
   sw    $a2, 0xc0($sp)
  lw    $a2, 0xc0($sp)
  lw    $a1, 0x10($s0)
  jal   sub_GAME_7F03A5A4
   lw    $a0, 0x10($a2)
  b     .L7F04E544
   lbu   $v0, 3($s0)
.L7F04E528:
  addiu $a0, $a0, 1
.L7F04E52C:
  li    $at, 13
  div   $zero, $a0, $at
  mfhi  $a0
  bnel  $a0, $a1, .L7F04E3E8
   sll   $t5, $a0, 2
.L7F04E540:
  lbu   $v0, 3($s0)
.L7F04E544:
  li    $at, 13
  bnel  $v0, $at, .L7F04E58C
   li    $at, 6
  lw    $t9, 8($s0)
  lui   $at, 0x4000
  move  $a0, $s0
  or    $t3, $t9, $at
  jal   do_something_if_object_destroyed
   sw    $t3, 8($s0)
  li    $at, 1
  bne   $v0, $at, .L7F04E6CC
   nop   
  lw    $t2, 8($s0)
  lui   $at, 0x1000
  or    $t4, $t2, $at
  b     .L7F04E6CC
   sw    $t4, 8($s0)
  li    $at, 6
.L7F04E58C:
  bnel  $v0, $at, .L7F04E5C0
   li    $at, 10
  jal   do_something_if_object_destroyed
   move  $a0, $s0
  li    $at, 1
  bne   $v0, $at, .L7F04E6CC
   nop   
  lw    $t5, 8($s0)
  lui   $at, 0x1000
  or    $t6, $t5, $at
  b     .L7F04E6CC
   sw    $t6, 8($s0)
  li    $at, 10
.L7F04E5C0:
  bnel  $v0, $at, .L7F04E5F4
   li    $at, 11
  jal   do_something_if_object_destroyed
   move  $a0, $s0
  li    $at, 1
  bne   $v0, $at, .L7F04E6CC
   addiu $a0, $s0, 0x80
  lui   $a1, %hi(D_80031EE8)
  jal   save_ptr_monitor_ani_code_to_obj_ani_slot
   addiu $a1, %lo(D_80031EE8) # addiu $a1, $a1, 0x1ee8
  b     .L7F04E6CC
   nop   
  li    $at, 11
.L7F04E5F4:
  bnel  $v0, $at, .L7F04E658
   li    $at, 36
  jal   do_something_if_object_destroyed
   move  $a0, $s0
  li    $at, 1
  bne   $v0, $at, .L7F04E6CC
   addiu $a0, $s0, 0x80
  lui   $a1, %hi(D_80031EE8)
  jal   save_ptr_monitor_ani_code_to_obj_ani_slot
   addiu $a1, %lo(D_80031EE8) # addiu $a1, $a1, 0x1ee8
  lui   $a1, %hi(D_80031EE8)
  addiu $a1, %lo(D_80031EE8) # addiu $a1, $a1, 0x1ee8
  jal   save_ptr_monitor_ani_code_to_obj_ani_slot
   addiu $a0, $s0, 0xf4
  lui   $a1, %hi(D_80031EE8)
  addiu $a1, %lo(D_80031EE8) # addiu $a1, $a1, 0x1ee8
  jal   save_ptr_monitor_ani_code_to_obj_ani_slot
   addiu $a0, $s0, 0x168
  lui   $a1, %hi(D_80031EE8)
  addiu $a1, %lo(D_80031EE8) # addiu $a1, $a1, 0x1ee8
  jal   save_ptr_monitor_ani_code_to_obj_ani_slot
   addiu $a0, $s0, 0x1dc
  b     .L7F04E6CC
   nop   
  li    $at, 36
.L7F04E658:
  bnel  $v0, $at, .L7F04E688
   li    $at, 21
  jal   do_something_if_object_destroyed
   move  $a0, $s0
  li    $at, 1
  bne   $v0, $at, .L7F04E6CC
   nop   
  jal   init_trigger_toxic_gas_effect
   addiu $a0, $s0, 0x58
  b     .L7F04E6CC
   nop   
  li    $at, 21
.L7F04E688:
  bne   $v0, $at, .L7F04E6CC
   nop   
  jal   do_something_if_object_destroyed
   move  $a0, $s0
  bnezl $v0, .L7F04E6C4
   mtc1  $zero, $f8
  lwc1  $f0, 0x74($s0)
  lwc1  $f16, 0x70($s0)
  lwc1  $f10, 0x80($s0)
  sub.s $f18, $f0, $f16
  mul.s $f6, $f10, $f18
  div.s $f4, $f6, $f0
  b     .L7F04E6CC
   swc1  $f4, 0x84($s0)
  mtc1  $zero, $f8
.L7F04E6C4:
  nop   
  swc1  $f8, 0x84($s0)
.L7F04E6CC:
  jal   do_something_if_object_destroyed
   move  $a0, $s0
  li    $at, 1
  bnel  $v0, $at, .L7F04E710
   lw    $ra, 0x1c($sp)
  lw    $t7, 0x10($s0)
  lw    $a0, 0x20($t7)
  beql  $a0, $zero, .L7F04E710
   lw    $ra, 0x1c($sp)
  lw    $v0, 0x24($a0)
.L7F04E6F4:
  li    $a1, 1
  jal   sub_GAME_7F04BFD0
   sw    $v0, 0x28($sp)
  lw    $a0, 0x28($sp)
  bnezl $a0, .L7F04E6F4
   lw    $v0, 0x24($a0)
.L7F04E70C:
  lw    $ra, 0x1c($sp)
.L7F04E710:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0xe0
  jr    $ra
   nop   
");






asm(R"
glabel sub_GAME_7F04E720
  addiu $sp, $sp, -0xc0
  sw    $ra, 0x4c($sp)
  sw    $s5, 0x48($sp)
  sw    $s4, 0x44($sp)
  sw    $s3, 0x40($sp)
  sw    $s2, 0x3c($sp)
  sw    $s1, 0x38($sp)
  sw    $s0, 0x34($sp)
  sw    $a0, 0xc0($sp)
  lw    $s5, 4($a0)
  move  $s3, $a1
  lw    $t7, 0x64($s5)
  andi  $t8, $t7, 0x1000
  bnezl $t8, .L7F04E99C
   lw    $ra, 0x4c($sp)
  lbu   $t0, 1($a0)
  andi  $t1, $t0, 2
  beql  $t1, $zero, .L7F04E99C
   lw    $ra, 0x4c($sp)
  lw    $s0, 0x20($a0)
  beql  $s0, $zero, .L7F04E794
   lw    $s4, 0x14($s5)
.L7F04E778:
  lw    $s1, 0x24($s0)
  move  $a0, $s0
  jal   sub_GAME_7F04E720
   move  $a1, $s3
  bnez  $s1, .L7F04E778
   move  $s0, $s1
  lw    $s4, 0x14($s5)
.L7F04E794:
  sw    $zero, 0xa8($sp)
  lbu   $t3, 3($s5)
  li    $at, 1
  addiu $s0, $s3, 0xc
  bne   $t3, $at, .L7F04E83C
   addiu $s1, $sp, 0xa8
  lhu   $t4, 0x98($s5)
  addiu $a0, $s5, 0xd0
  move  $a2, $s3
  andi  $t5, $t4, 4
  bnezl $t5, .L7F04E7E0
   addiu $s0, $s3, 0xc
  lhu   $v0, 0x9a($s5)
  li    $at, 6
  beq   $v0, $at, .L7F04E7DC
   li    $at, 7
  bne   $v0, $at, .L7F04E83C
   nop   
.L7F04E7DC:
  addiu $s0, $s3, 0xc
.L7F04E7E0:
  move  $a3, $s0
  jal   sub_GAME_7F0747D0
   lw    $a1, 0xc($s4)
  lw    $t6, 8($s4)
  move  $s2, $v0
  move  $a0, $s4
  lw    $t7, ($t6)
  move  $a2, $s3
  blez  $v0, .L7F04E894
   sw    $t7, 0xa8($sp)
  addiu $t8, $sp, 0x78
  addiu $t9, $sp, 0x74
  addiu $t0, $sp, 0x60
  sw    $t0, 0x18($sp)
  sw    $t9, 0x14($sp)
  sw    $t8, 0x10($sp)
  move  $a1, $t7
  jal   sub_GAME_7F04D9B0
   move  $a3, $s0
  bnez  $v0, .L7F04E894
   nop   
  b     .L7F04E894
   move  $s2, $zero
.L7F04E83C:
  move  $a0, $s4
.L7F04E840:
  move  $a1, $s3
  move  $a2, $s0
  jal   sub_GAME_7F0752FC
   move  $a3, $s1
  blez  $v0, .L7F04E88C
   move  $s2, $v0
  addiu $t1, $sp, 0x78
  addiu $t2, $sp, 0x74
  addiu $t3, $sp, 0x60
  sw    $t3, 0x18($sp)
  sw    $t2, 0x14($sp)
  sw    $t1, 0x10($sp)
  move  $a0, $s4
  lw    $a1, 0xa8($sp)
  move  $a2, $s3
  jal   sub_GAME_7F04D9B0
   move  $a3, $s0
  bnez  $v0, .L7F04E894
   nop   
.L7F04E88C:
  bgtzl $s2, .L7F04E840
   move  $a0, $s4
.L7F04E894:
  blez  $s2, .L7F04E998
   lw    $t5, 0x74($sp)
  lw    $t4, 0xc($s4)
  lwc1  $f4, 0x78($sp)
  lwc1  $f6, 0x7c($sp)
  lwc1  $f8, 0x80($sp)
  sll   $t6, $t5, 6
  addiu $a1, $sp, 0x68
  addu  $a0, $t4, $t6
  swc1  $f4, 0x68($sp)
  swc1  $f6, 0x6c($sp)
  jal   sub_GAME_7F058474
   swc1  $f8, 0x70($sp)
  lwc1  $f0, 0x70($sp)
  lwc1  $f10, 0x34($s3)
  move  $a0, $s3
  neg.s $f0, $f0
  lw    $a1, 0xc0($sp)
  c.le.s $f0, $f10
  move  $a3, $s2
  lw    $t4, 0xa8($sp)
  addiu $t6, $sp, 0x78
  bc1fl .L7F04E99C
   lw    $ra, 0x4c($sp)
  lw    $t7, 8($s5)
  li    $v1, 1
  sll   $t8, $t7, 0xe
  bltzl $t8, .L7F04E960
   lw    $t7, 0x74($sp)
  lbu   $v0, 3($s5)
  li    $at, 42
  beq   $v0, $at, .L7F04E920
   li    $at, 47
  bnel  $v0, $at, .L7F04E92C
   lw    $t9, 0x14($s5)
.L7F04E920:
  b     .L7F04E95C
   move  $v1, $zero
  lw    $t9, 0x14($s5)
.L7F04E92C:
  lui   $t0, %hi(prop_door_related) 
  addiu $t0, %lo(prop_door_related) # addiu $t0, $t0, -0x5e24
  lw    $v0, 8($t9)
  lw    $t1, 4($v0)
  bnel  $t0, $t1, .L7F04E960
   lw    $t7, 0x74($sp)
  lw    $t3, 8($v0)
  lw    $t2, 0x60($sp)
  lw    $t5, 0xc($t3)
  bnel  $t2, $t5, .L7F04E960
   lw    $t7, 0x74($sp)
  move  $v1, $zero
.L7F04E95C:
  lw    $t7, 0x74($sp)
.L7F04E960:
  lw    $t8, 0x60($sp)
  sw    $t4, 0x10($sp)
  sw    $t6, 0x14($sp)
  sw    $s4, 0x20($sp)
  sw    $v1, 0x24($sp)
  sw    $t7, 0x18($sp)
  sw    $t8, 0x1c($sp)
  lw    $t9, 0xc($s5)
  lui   $at, 0x10
  mfc1  $a2, $f0
  and   $t0, $t9, $at
  sltu  $t1, $zero, $t0
  jal   sub_GAME_7F03B9C0
   sw    $t1, 0x28($sp)
.L7F04E998:
  lw    $ra, 0x4c($sp)
.L7F04E99C:
  lw    $s0, 0x34($sp)
  lw    $s1, 0x38($sp)
  lw    $s2, 0x3c($sp)
  lw    $s3, 0x40($sp)
  lw    $s4, 0x44($sp)
  lw    $s5, 0x48($sp)
  jr    $ra
   addiu $sp, $sp, 0xc0
");






asm(R"
glabel sub_GAME_7F04E9BC
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  sw    $a0, 0x28($sp)
  sw    $a1, 0x2c($sp)
  lw    $a0, 4($a0)
  lw    $t7, 0x14($a0)
  sw    $a0, 0x24($sp)
  jal   sub_GAME_7F040078
   sw    $t7, 0x1c($sp)
  lw    $t8, 0x28($sp)
  lw    $a0, 0x24($sp)
  lbu   $t9, 1($t8)
  andi  $t0, $t9, 2
  beql  $t0, $zero, .L7F04EA5C
   lw    $ra, 0x14($sp)
  lw    $t1, 0x64($a0)
  andi  $t2, $t1, 0x1000
  bnezl $t2, .L7F04EA5C
   lw    $ra, 0x14($sp)
  lw    $t3, 0xc($a0)
  lw    $t5, 0x1c($sp)
  andi  $t4, $t3, 0x8000
  bnez  $t4, .L7F04EA58
   move  $a0, $v0
  jal   sub_GAME_7F03EB9C
   lw    $a1, 0xc($t5)
  lw    $t6, 0x1c($sp)
  lw    $a1, 0x2c($sp)
  lw    $t7, 0xc($t6)
  lwc1  $f6, 0x34($a1)
  lwc1  $f4, 0x38($t7)
  add.s $f2, $f0, $f4
  neg.s $f2, $f2
  c.le.s $f2, $f6
  nop   
  bc1fl .L7F04EA5C
   lw    $ra, 0x14($sp)
  jal   sub_GAME_7F04E720
   lw    $a0, 0x28($sp)
.L7F04EA58:
  lw    $ra, 0x14($sp)
.L7F04EA5C:
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");






asm(R"
glabel sub_GAME_7F04EA68
  addiu $sp, $sp, -0x70
  sw    $ra, 0x2c($sp)
  sw    $s1, 0x28($sp)
  sw    $s0, 0x24($sp)
  lw    $a2, 4($a1)
  move  $s0, $a1
  lw    $v0, 0x1c($a2)
  move  $v1, $a2
  beql  $v0, $zero, .L7F04EAA4
   lwc1  $f4, ($s0)
  move  $v1, $v0
.L7F04EA94:
  lw    $v0, 0x1c($v0)
  bnezl $v0, .L7F04EA94
   move  $v1, $v0
  lwc1  $f4, ($s0)
.L7F04EAA4:
  lwc1  $f6, 0xc($a0)
  lwc1  $f10, 0x14($a0)
  lwc1  $f18, ($a0)
  mul.s $f8, $f4, $f6
  lw    $s1, 4($a2)
  li    $at, 0x41D00000 # 26.000000
  mtc1  $at, $f0
  div.s $f16, $f8, $f10
  sub.s $f4, $f18, $f16
  swc1  $f4, 0x60($sp)
  lwc1  $f8, 0x10($a0)
  lwc1  $f6, ($s0)
  lwc1  $f18, 0x14($a0)
  lwc1  $f4, 4($a0)
  mul.s $f10, $f6, $f8
  div.s $f16, $f10, $f18
  sub.s $f6, $f4, $f16
  lwc1  $f4, 0x60($sp)
  swc1  $f6, 0x64($sp)
  lwc1  $f10, ($s0)
  lwc1  $f8, 8($a0)
  sub.s $f18, $f8, $f10
  lwc1  $f10, 0x64($sp)
  swc1  $f18, 0x68($sp)
  lwc1  $f16, 0xc($a0)
  mul.s $f6, $f0, $f16
  sub.s $f8, $f4, $f6
  lwc1  $f6, 0x68($sp)
  swc1  $f8, 0x60($sp)
  lwc1  $f18, 0x10($a0)
  mul.s $f16, $f0, $f18
  sub.s $f4, $f10, $f16
  swc1  $f4, 0x64($sp)
  lwc1  $f8, 0x14($a0)
  sw    $a0, 0x70($sp)
  sw    $v1, 0x5c($sp)
  mul.s $f18, $f0, $f8
  sub.s $f10, $f6, $f18
  jal   sub_GAME_7F078444
   swc1  $f10, 0x68($sp)
  move  $a0, $v0
  jal   sub_GAME_7F058474
   addiu $a1, $sp, 0x60
  lw    $t6, 0x4c($s0)
  lw    $v1, 0x5c($sp)
  beqz  $t6, .L7F04EB6C
   addiu $a0, $sp, 0x60
  jal   sub_GAME_7F067B4C
   sw    $v1, 0x5c($sp)
  lw    $v1, 0x5c($sp)
.L7F04EB6C:
  lw    $t7, 0x14($v1)
  addiu $a0, $sp, 0x60
  li    $a1, 1
  lui   $a2, 0x41d0
  jal   sub_GAME_7F0A3E1C
   lbu   $a3, 3($t7)
  jal   check_if_object_has_not_been_destroyed
   move  $a0, $s1
  beql  $v0, $zero, .L7F04EBC4
   lw    $t3, 0x4c($s0)
  jal   check_if_destroyable_not_invincible
   move  $a0, $s1
  beql  $v0, $zero, .L7F04EBC4
   lw    $t3, 0x4c($s0)
  lw    $t8, 0x4c($s0)
  lw    $t9, 0x70($sp)
  li    $a1, 6
  beql  $t8, $zero, .L7F04EBC4
   lw    $t3, 0x4c($s0)
  jal   inc_curplayer_hitcount_with_weapon
   lw    $a0, 0x18($t9)
  lw    $t3, 0x4c($s0)
.L7F04EBC4:
  bnezl $t3, .L7F04EBE4
   lw    $t4, 0x70($sp)
  lw    $a0, 4($s0)
  jal   sub_GAME_7F064720
   addiu $a0, $a0, 8
  b     .L7F04EBF8
   lw    $t5, 0x70($sp)
  lw    $t4, 0x70($sp)
.L7F04EBE4:
  lw    $a1, 4($s0)
  lh    $a2, 0x3a($s0)
  jal   recall_joy2_hits_edit_detail_edit_flag
   lw    $a0, 0x18($t4)
  lw    $t5, 0x70($sp)
.L7F04EBF8:
  li    $at, 23
  lw    $a0, 0x18($t5)
  beq   $a0, $at, .L7F04ED84
   nop   
  lw    $t6, 0x4c($s0)
  bnezl $t6, .L7F04EC98
   lh    $v0, 0x3a($s0)
  lw    $t8, 0x14($s1)
  lui   $t7, %hi(prop_door_related) 
  addiu $t7, %lo(prop_door_related) # addiu $t7, $t7, -0x5e24
  lw    $t9, 8($t8)
  lw    $t0, 4($s0)
  move  $v1, $zero
  lw    $t3, 4($t9)
  bnel  $t7, $t3, .L7F04EC40
   sb    $v1, 0x57($sp)
  li    $v1, 1
  sb    $v1, 0x57($sp)
.L7F04EC40:
  jal   get_random_value
   sw    $t0, 0x58($sp)
  li    $at, 3
  divu  $zero, $v0, $at
  lw    $t0, 0x58($sp)
  mfhi  $a2
  lb    $v1, 0x57($sp)
  sw    $t0, 0x10($sp)
  lw    $t6, 0x40($s0)
  addiu $a2, $a2, 0x11
  sll   $t4, $a2, 0x10
  sra   $a2, $t4, 0x10
  addiu $a0, $s0, 0x10
  addiu $a1, $s0, 0x1c
  li    $a3, 1
  sw    $v1, 0x18($sp)
  jal   sub_GAME_7F0A108C
   sw    $t6, 0x14($sp)
  lw    $t8, 0x70($sp)
  b     .L7F04ED84
   lw    $a0, 0x18($t8)
  lh    $v0, 0x3a($s0)
.L7F04EC98:
  move  $t1, $zero
  lui   $t7, %hi(image_entries)
  bgez  $v0, .L7F04ECB4
   sll   $t9, $v0, 3
  lui   $t0, %hi(D_8004E86C) 
  b     .L7F04ECD0
   lw    $t0, %lo(D_8004E86C)($t0)
.L7F04ECB4:
  addu  $t7, $t7, $t9
  lbu   $t7, %lo(image_entries)($t7)
  lui   $t0, %hi(D_8004E86C)
  andi  $t3, $t7, 0xf
  sll   $t4, $t3, 2
  addu  $t0, $t0, $t4
  lw    $t0, %lo(D_8004E86C)($t0)
.L7F04ECD0:
  sw    $t0, 0x50($sp)
  jal   get_random_value
   sb    $t1, 0x4b($sp)
  lw    $t0, 0x50($sp)
  lw    $t6, 0x14($s1)
  lui   $t8, %hi(prop_door_related) 
  lh    $t5, 0xa($t0)
  lw    $v1, 8($t6)
  addiu $t8, %lo(prop_door_related) # addiu $t8, $t8, -0x5e24
  divu  $zero, $v0, $t5
  lw    $a0, 4($v1)
  mfhi  $t2
  lb    $t1, 0x4b($sp)
  bnez  $t5, .L7F04ED10
   nop   
  break 7
.L7F04ED10:
  addiu $a1, $s0, 0x1c
  bne   $t8, $a0, .L7F04ED2C
   li    $a3, 1
  lw    $t7, 8($v1)
  lw    $t9, 0x44($s0)
  lw    $t3, 0xc($t7)
  beq   $t9, $t3, .L7F04ED50
.L7F04ED2C:
   lui   $t4, %hi(prop_cctv_related) 
  addiu $t4, %lo(prop_cctv_related) # addiu $t4, $t4, -0x5fa4
  bnel  $t4, $a0, .L7F04ED58
   lw    $t7, 4($t0)
  lw    $t6, 8($v1)
  lw    $t5, 0x44($s0)
  lw    $t8, 4($t6)
  bnel  $t5, $t8, .L7F04ED58
   lw    $t7, 4($t0)
.L7F04ED50:
  li    $t1, 1
  lw    $t7, 4($t0)
.L7F04ED58:
  lw    $t3, 4($s0)
  addiu $a0, $s0, 0x10
  addu  $t9, $t7, $t2
  lbu   $a2, ($t9)
  sw    $t3, 0x10($sp)
  lw    $t4, 0x40($s0)
  sw    $t1, 0x18($sp)
  jal   sub_GAME_7F0A108C
   sw    $t4, 0x14($sp)
  lw    $t6, 0x70($sp)
  lw    $a0, 0x18($t6)
.L7F04ED84:
  jal   sub_GAME_7F05DF84
   nop   
  lbu   $v0, 3($s1)
  li    $at, 13
  mov.s $f2, $f0
  bne   $v0, $at, .L7F04EDB0
   lui   $at, %hi(D_80030B24)
  lwc1  $f16, %lo(D_80030B24)($at)
  mul.s $f2, $f0, $f16
  b     .L7F04EE18
   nop   
.L7F04EDB0:
  li    $at, 6
  bne   $v0, $at, .L7F04EE18
   nop   
  lw    $t5, 0x14($s1)
  lui   $t8, %hi(prop_cctv_related) 
  addiu $t8, %lo(prop_cctv_related) # addiu $t8, $t8, -0x5fa4
  lw    $v1, 8($t5)
  lw    $t7, 4($v1)
  bne   $t8, $t7, .L7F04EE08
   nop   
  lw    $t3, 8($v1)
  lw    $t9, 0x44($s0)
  li    $at, 0x42C80000 # 100.000000
  lw    $t4, 4($t3)
  bne   $t9, $t4, .L7F04EE08
   nop   
  mtc1  $at, $f4
  move  $a0, $s1
  mul.s $f2, $f2, $f4
  jal   sub_GAME_7F04DE18
   swc1  $f2, 0x44($sp)
  lwc1  $f2, 0x44($sp)
.L7F04EE08:
  lui   $at, %hi(D_80030B18)
  lwc1  $f8, %lo(D_80030B18)($at)
  mul.s $f2, $f2, $f8
  nop   
.L7F04EE18:
  jal   get_cur_playernum
   swc1  $f2, 0x44($sp)
  lwc1  $f2, 0x44($sp)
  lw    $t6, 0x70($sp)
  move  $a0, $s1
  mfc1  $a1, $f2
  lw    $a3, 0x18($t6)
  sw    $v0, 0x10($sp)
  jal   sub_GAME_7F04E0CC
   addiu $a2, $sp, 0x60
  lw    $t8, 0x14($s1)
  lui   $t5, %hi(prop_door_related) 
  addiu $t5, %lo(prop_door_related) # addiu $t5, $t5, -0x5e24
  lw    $t7, 8($t8)
  lw    $t3, 4($t7)
  bne   $t5, $t3, .L7F04EE8C
   nop   
  lw    $t9, 0x4c($s0)
  bnez  $t9, .L7F04EE8C
   nop   
  lb    $t4, 0xbd($s1)
  addiu $t6, $t4, 1
  sb    $t6, 0xbd($s1)
  lb    $t8, 0xbd($s1)
  slti  $at, $t8, 3
  bnez  $at, .L7F04EE8C
   nop   
  jal   sub_GAME_7F04DD68
   move  $a0, $s1
.L7F04EE8C:
  jal   sub_GAME_7F044200
   lw    $a0, 4($s0)
  move  $s0, $zero
  jal   check_if_collectable_object
   move  $a0, $s1
  beql  $v0, $zero, .L7F04EEC4
   lw    $t3, 8($s1)
  lw    $t7, 8($s1)
  sll   $t5, $t7, 9
  bltzl $t5, .L7F04EED8
   lw    $t4, 0xc($s1)
  b     .L7F04EED4
   li    $s0, 1
  lw    $t3, 8($s1)
.L7F04EEC4:
  sll   $t9, $t3, 0xa
  bgezl $t9, .L7F04EED8
   lw    $t4, 0xc($s1)
  li    $s0, 1
.L7F04EED4:
  lw    $t4, 0xc($s1)
.L7F04EED8:
  andi  $t6, $t4, 2
  beql  $t6, $zero, .L7F04EEFC
   lw    $t8, 0xc($s1)
  jal   check_if_object_has_not_been_destroyed
   move  $a0, $s1
  bnezl $v0, .L7F04EEFC
   lw    $t8, 0xc($s1)
  li    $s0, 1
  lw    $t8, 0xc($s1)
.L7F04EEFC:
  lw    $a1, 0x70($sp)
  andi  $t7, $t8, 0x400
  beqz  $t7, .L7F04EF10
   addiu $a1, $a1, 0xc
  move  $s0, $zero
.L7F04EF10:
  beql  $s0, $zero, .L7F04EF24
   lw    $ra, 0x2c($sp)
  jal   sub_GAME_7F04BCDC
   move  $a0, $s1
  lw    $ra, 0x2c($sp)
.L7F04EF24:
  lw    $s0, 0x24($sp)
  lw    $s1, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x70
");






asm(R"
glabel check_if_object_has_not_been_destroyed
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   do_something_if_object_destroyed
   nop   
  lw    $ra, 0x14($sp)
  sltiu $t6, $v0, 1
  move  $v0, $t6
  jr    $ra
   addiu $sp, $sp, 0x18
");






asm(R"
.late_rodata
glabel D_80052EF4
.word 0x481c4000 /*160000.0*/
glabel D_80052EF8
.word 0x40060a92 /*2.0943952*/
glabel D_80052EFC
.word 0x471c4000 /*40000.0*/
glabel D_80052F00
.word 0x3ec90fdb /*0.39269909*/
glabel D_80052F04
.word 0x40c90fdb /*6.2831855*/
glabel D_80052F08
.word 0x40490fdb /*3.1415927*/
glabel D_80052F0C
.word 0x40c90fdb /*6.2831855*/

.text
glabel sub_GAME_7F04EF58
  addiu $sp, $sp, -0x58
  sw    $ra, 0x1c($sp)
  lw    $a1, 4($a0)
  li    $at, 5
  move  $a2, $a0
  lbu   $t6, 3($a1)
  beql  $t6, $at, .L7F04EF9C
   lbu   $t1, 1($a2)
  lw    $t7, 8($a1)
  sll   $t8, $t7, 0xc
  bltzl $t8, .L7F04EF9C
   lbu   $t1, 1($a2)
  lw    $t9, 0x64($a1)
  andi  $t0, $t9, 0x13
  beql  $t0, $zero, .L7F04F160
   lw    $ra, 0x1c($sp)
  lbu   $t1, 1($a2)
.L7F04EF9C:
  move  $a0, $a1
  andi  $t2, $t1, 2
  beql  $t2, $zero, .L7F04F160
   lw    $ra, 0x1c($sp)
  sw    $a1, 0x50($sp)
  jal   check_if_object_has_not_been_destroyed
   sw    $a2, 0x58($sp)
  beqz  $v0, .L7F04F15C
   lw    $a1, 0x50($sp)
  lw    $t3, 8($a1)
  sll   $t4, $t3, 6
  bltzl $t4, .L7F04F160
   lw    $ra, 0x1c($sp)
  jal   get_curplayer_positiondata
   sw    $a1, 0x50($sp)
  lw    $a1, 0x50($sp)
  lwc1  $f6, 8($v0)
  lwc1  $f10, 0xc($v0)
  lwc1  $f4, 0x58($a1)
  lwc1  $f8, 0x5c($a1)
  lw    $t5, 0x14($v0)
  sub.s $f12, $f4, $f6
  lwc1  $f6, 0x10($v0)
  lwc1  $f4, 0x60($a1)
  sub.s $f16, $f8, $f10
  mul.s $f8, $f12, $f12
  sw    $t5, 0x2c($sp)
  sub.s $f14, $f4, $f6
  lbu   $t6, 3($a1)
  li    $at, 40
  move  $v1, $v0
  mul.s $f10, $f14, $f14
  bnel  $t6, $at, .L7F04F054
   lui   $at, 0x4348
  lw    $t7, 8($a1)
  lui   $at, 0x43c8
  sll   $t8, $t7, 2
  bgezl $t8, .L7F04F054
   li    $at, 0x43480000 # 200.000000
  mtc1  $at, $f0
  lui   $at, %hi(D_80052EF4)
  lwc1  $f2, %lo(D_80052EF4)($at)
  lui   $at, %hi(D_80052EF8)
  b     .L7F04F068
   lwc1  $f18, %lo(D_80052EF8)($at)
  li    $at, 0x43480000 # 200.000000
.L7F04F054:
  mtc1  $at, $f0
  lui   $at, %hi(D_80052EFC)
  lwc1  $f2, %lo(D_80052EFC)($at)
  lui   $at, %hi(D_80052F00)
  lwc1  $f18, %lo(D_80052F00)($at)
.L7F04F068:
  add.s $f4, $f8, $f10
  c.lt.s $f4, $f2
  nop   
  bc1fl .L7F04F160
   lw    $ra, 0x1c($sp)
  c.lt.s $f16, $f0
  nop   
  bc1fl .L7F04F160
   lw    $ra, 0x1c($sp)
  neg.s $f6, $f0
  c.lt.s $f6, $f16
  nop   
  bc1fl .L7F04F160
   lw    $ra, 0x1c($sp)
  sw    $v1, 0x4c($sp)
  sw    $a1, 0x50($sp)
  jal   convert_angle_using_inverse
   swc1  $f18, 0x30($sp)
  jal   get_curplay_horizontal_rotation_in_degrees
   swc1  $f0, 0x24($sp)
  lwc1  $f12, 0x24($sp)
  lw    $v1, 0x4c($sp)
  lw    $a1, 0x50($sp)
  c.lt.s $f12, $f0
  lwc1  $f18, 0x30($sp)
  sub.s $f14, $f12, $f0
  lui   $at, %hi(D_80052F04)
  bc1f  .L7F04F0E4
   mov.s $f2, $f14
  lwc1  $f8, %lo(D_80052F04)($at)
  add.s $f2, $f14, $f8
.L7F04F0E4:
  lui   $at, %hi(D_80052F08)
  lwc1  $f10, %lo(D_80052F08)($at)
  lui   $at, %hi(D_80052F0C)
  c.lt.s $f10, $f2
  nop   
  bc1fl .L7F04F10C
   c.le.s $f2, $f18
  lwc1  $f4, %lo(D_80052F0C)($at)
  sub.s $f2, $f4, $f2
  c.le.s $f2, $f18
.L7F04F10C:
  nop   
  bc1fl .L7F04F160
   lw    $ra, 0x1c($sp)
  lw    $t9, 0xc($a1)
  lw    $v0, 0x58($sp)
  addiu $a0, $sp, 0x2c
  andi  $t0, $t9, 0x800
  beql  $t0, $zero, .L7F04F154
   lw    $t1, 0x58($sp)
  lwc1  $f6, 0x10($v0)
  lw    $a1, 8($v1)
  lw    $a2, 0x10($v1)
  lw    $a3, 8($v0)
  jal   sub_GAME_7F0B0BE4
   swc1  $f6, 0x10($sp)
  beql  $v0, $zero, .L7F04F160
   lw    $ra, 0x1c($sp)
  lw    $t1, 0x58($sp)
.L7F04F154:
  lui   $at, %hi(dword_CODE_bss_80071DF8)
  sw    $t1, %lo(dword_CODE_bss_80071DF8)($at)
.L7F04F15C:
  lw    $ra, 0x1c($sp)
.L7F04F160:
  addiu $sp, $sp, 0x58
  li    $v0, 1
  jr    $ra
   nop   
");






asm(R"
glabel sub_GAME_7F04F170
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a0, 0x28($sp)
  lw    $s0, 4($a0)
  sw    $zero, 0x20($sp)
  li    $at, 5
  lbu   $t7, 3($s0)
  lui   $a0, %hi(ptr_sfx_buf)
  li    $a1, 186
  bne   $t7, $at, .L7F04F1D0
   move  $a2, $zero
  jal   play_sfx_a1
   lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   is_alarm_on
   nop   
  beqz  $v0, .L7F04F1C8
   nop   
  jal   stop_alarm
   nop   
  b     .L7F04F1D4
   lw    $t8, 8($s0)
.L7F04F1C8:
  jal   start_alarm
   nop   
.L7F04F1D0:
  lw    $t8, 8($s0)
.L7F04F1D4:
  lw    $a0, 0x28($sp)
  sll   $t9, $t8, 0xc
  bgezl $t9, .L7F04F1F4
   lw    $t0, 0x64($s0)
  jal   collect_or_interact_object
   li    $a1, 1
  sw    $v0, 0x20($sp)
  lw    $t0, 0x64($s0)
.L7F04F1F4:
  ori   $t1, $t0, 0x4000
  sw    $t1, 0x64($s0)
  jal   sub_GAME_7F03E6A0
   lw    $a0, 0x28($sp)
  lw    $ra, 0x1c($sp)
  lw    $v0, 0x20($sp)
  lw    $s0, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");






asm(R"
glabel sub_GAME_7F04F218
  beqz  $a1, .L7F04F230
   lw    $v0, 4($a0)
  lbu   $t6, 2($v0)
  andi  $t7, $t6, 0xffdf
  jr    $ra
   sb    $t7, 2($v0)

.L7F04F230:
  lbu   $t8, 2($v0)
  ori   $t9, $t8, 0x20
  sb    $t9, 2($v0)
  jr    $ra
   nop   
");






asm(R"
glabel sub_GAME_7F04F244
  lw    $v0, 4($a0)
  lw    $v1, 0x68($v0)
  beql  $v1, $zero, .L7F04F2AC
   sw    $zero, ($a2)
  lw    $t6, 8($v0)
  andi  $t7, $t6, 0x100
  beql  $t7, $zero, .L7F04F2AC
   sw    $zero, ($a2)
  lbu   $t8, 2($v0)
  andi  $t9, $t8, 0x20
  bnezl $t9, .L7F04F2AC
   sw    $zero, ($a2)
  lw    $t0, ($v1)
  sw    $t0, ($a2)
  lw    $t1, 0x68($v0)
  addiu $t2, $t1, 4
  sw    $t2, ($a1)
  lw    $t3, 0x68($v0)
  lw    $t4, 0x10($sp)
  lwc1  $f4, 0x48($t3)
  swc1  $f4, ($t4)
  lw    $t5, 0x68($v0)
  lwc1  $f6, 0x44($t5)
  jr    $ra
   swc1  $f6, ($a3)

  sw    $zero, ($a2)
.L7F04F2AC:
  jr    $ra
   nop   
");






void append_text_picked_up(unsigned char *buffer,unsigned char * param2,unsigned char * param3)
{
  unsigned char *puVar1;

  puVar1 = get_textptr_for_textID(0xa400);
  string_append_from_obseg_textbank(buffer, puVar1);
  return;
}





void append_text_ammo_amount_word(unsigned char *buffer,AMMOTYPES ammotype,unsigned int amount)
{
  unsigned char *textfiletext;

  switch (ammotype) {
  case AMMO_9MM:
  case AMMO_9MM_2:
  case AMMO_RIFLE:
  case AMMO_PLASTIQUE:
    textfiletext = get_textptr_for_textID(0xa401);
    string_append_from_obseg_textbank(buffer, textfiletext);
    break;
  case AMMO_SHOTGUN:
  case AMMO_GRENADE:
  case AMMO_ROCKETS:
  case AMMO_REMOTEMINE:
  case AMMO_PROXMINE:
  case AMMO_TIMEDMINE:
  case AMMO_KNIFE:
  case AMMO_GRENADEROUND:
  case AMMO_MAGNUM:
  case AMMO_GGUN:
  case AMMO_DARTS:
  case AMMO_FLARE:
  case AMMO_PITON:
  case AMMO_DYNAMITE:
  case AMMO_BUG:
  case AMMO_MICRO_CAMERA:
    if (amount == 1) {
      textfiletext = get_textptr_for_textID(0xa402);
      string_append_from_obseg_textbank(buffer, textfiletext);
    } else {
      textfiletext = get_textptr_for_textID(0xa401);
      string_append_from_obseg_textbank(buffer, textfiletext);
    }
    break;
  case AMMO_EXPLOSIVEPEN:
  case AMMO_BOMBCASE:
    if (amount == 1) {
      textfiletext = get_textptr_for_textID(0xa403);
      string_append_from_obseg_textbank(buffer, textfiletext);
    } else {
      textfiletext = get_textptr_for_textID(0xa401);
      string_append_from_obseg_textbank(buffer, textfiletext);
    }
    break;
  case AMMO_GEKEY:
  case AMMO_TOKEN:
    if (amount == 1) {
      textfiletext = get_textptr_for_textID(0xa404);
      string_append_from_obseg_textbank(buffer, textfiletext);
    } else {
      textfiletext = get_textptr_for_textID(0xa401);
      string_append_from_obseg_textbank(buffer, textfiletext);
    }
  }
  return;
}

asm(R"
.late_rodata
glabel jpt_80052F84
.word text_pickup_shotgun_cartridge
.word text_pickup_hand_grenade
.word text_pickup_rocket
.word text_pickup_remote_mine
.word text_pickup_proximity_mine
.word text_pickup_timed_mine
.word pluralize_multiples
.word text_pickup_grenade_round
.word text_pickup_magnum_bullet
.word text_pickup_golden_bullet
.word text_pickup_dart
.word text_pickup_explosive_pen
.word text_pickup_explosive_case
.word text_pickup_flare
.word text_pickup_piton
.word pluralize_multiples
.word text_pickup_bug
.word text_pickup_micro_camera
.word text_pickup_goldeneye_key
.word text_pickup_plastique
.word pluralize_multiples
.word pluralize_multiples
.word pluralize_multiples
.word pluralize_multiples
.word pluralize_multiples
.word text_pickup_token

.text
glabel apped_text_ammotype
  addiu $sp, $sp, -0x20
  sw    $s0, 0x18($sp)
  li    $v0, 1
  move  $s0, $a0
  sw    $ra, 0x1c($sp)
  beq   $a1, $v0, .L7F04F43C
   sw    $a2, 0x28($sp)
  li    $at, 2
  beq   $a1, $at, .L7F04F43C
   li    $at, 3
  bnel  $a1, $at, .L7F04F45C
   li    $at, 10
.L7F04F43C:
  jal   get_textptr_for_textID
   li    $a0, 41989
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F04F778
   lw    $ra, 0x1c($sp)
  li    $at, 10
.L7F04F45C:
  bnel  $a1, $at, .L7F04F4C4
   li    $at, 19
  jal   get_textptr_for_textID
   li    $a0, 41999
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  lw    $t6, 0x28($sp)
  li    $at, 1
  bne   $t6, $at, .L7F04F4A4
   nop   
  jal   get_textptr_for_textID
   li    $a0, 42000
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F04F778
   lw    $ra, 0x1c($sp)
.L7F04F4A4:
  jal   get_textptr_for_textID
   li    $a0, 42001
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F04F778
   lw    $ra, 0x1c($sp)
  li    $at, 19
.L7F04F4C4:
  bne   $a1, $at, .L7F04F524
   addiu $t8, $a1, -4
  lw    $t7, 0x28($sp)
  bne   $t7, $v0, .L7F04F4F4
   nop   
  jal   get_textptr_for_textID
   li    $a0, 42009
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F04F508
   nop   
.L7F04F4F4:
  jal   get_textptr_for_textID
   li    $a0, 42010
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
.L7F04F508:
  jal   get_textptr_for_textID
   li    $a0, 42008
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F04F778
   lw    $ra, 0x1c($sp)
.L7F04F524:
  sltiu $at, $t8, 0x1a
  beqz  $at, .L7F04F750
   sll   $t8, $t8, 2
  lui   $at, %hi(jpt_80052F84)
  addu  $at, $at, $t8
  lw    $t8, %lo(jpt_80052F84)($at)
  jr    $t8
   nop   
text_pickup_shotgun_cartridge:
  jal   get_textptr_for_textID
   li    $a0, 41990
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F04F754
   lw    $t9, 0x28($sp)
text_pickup_magnum_bullet:
  jal   get_textptr_for_textID
   li    $a0, 41991
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F04F754
   lw    $t9, 0x28($sp)
text_pickup_golden_bullet:
  jal   get_textptr_for_textID
   li    $a0, 41992
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F04F754
   lw    $t9, 0x28($sp)
text_pickup_hand_grenade:
  jal   get_textptr_for_textID
   li    $a0, 41993
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F04F754
   lw    $t9, 0x28($sp)
text_pickup_grenade_round:
  jal   get_textptr_for_textID
   li    $a0, 41994
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F04F754
   lw    $t9, 0x28($sp)
text_pickup_rocket:
  jal   get_textptr_for_textID
   li    $a0, 41995
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F04F754
   lw    $t9, 0x28($sp)
text_pickup_remote_mine:
  jal   get_textptr_for_textID
   li    $a0, 41996
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F04F754
   lw    $t9, 0x28($sp)
text_pickup_proximity_mine:
  jal   get_textptr_for_textID
   li    $a0, 41997
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F04F754
   lw    $t9, 0x28($sp)
text_pickup_timed_mine:
  jal   get_textptr_for_textID
   li    $a0, 41998
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F04F754
   lw    $t9, 0x28($sp)
text_pickup_dart:
  jal   get_textptr_for_textID
   li    $a0, 42003
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F04F754
   lw    $t9, 0x28($sp)
text_pickup_explosive_pen:
  jal   get_textptr_for_textID
   li    $a0, 42004
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F04F754
   lw    $t9, 0x28($sp)
text_pickup_explosive_case:
  jal   get_textptr_for_textID
   li    $a0, 42005
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F04F754
   lw    $t9, 0x28($sp)
text_pickup_flare:
  jal   get_textptr_for_textID
   li    $a0, 42006
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F04F754
   lw    $t9, 0x28($sp)
text_pickup_piton:
  jal   get_textptr_for_textID
   li    $a0, 42007
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F04F754
   lw    $t9, 0x28($sp)
text_pickup_bug:
  jal   get_textptr_for_textID
   li    $a0, 42011
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F04F754
   lw    $t9, 0x28($sp)
text_pickup_micro_camera:
  jal   get_textptr_for_textID
   li    $a0, 42012
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F04F754
   lw    $t9, 0x28($sp)
text_pickup_goldeneye_key:
  jal   get_textptr_for_textID
   li    $a0, 42013
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F04F754
   lw    $t9, 0x28($sp)
text_pickup_token:
  jal   get_textptr_for_textID
   li    $a0, 42014
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F04F754
   lw    $t9, 0x28($sp)
text_pickup_plastique:
  jal   get_textptr_for_textID
   li    $a0, 42015
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
pluralize_multiples:
.L7F04F750:
  lw    $t9, 0x28($sp)
.L7F04F754:
  slti  $at, $t9, 2
  bnezl $at, .L7F04F778
   lw    $ra, 0x1c($sp)
  jal   get_textptr_for_textID
   li    $a0, 42002
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  lw    $ra, 0x1c($sp)
.L7F04F778:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

void set_sound_effect_for_ammo_collection(AMMOTYPES ammotype)
{
  switch (ammotype) {
  case AMMO_9MM:
  case AMMO_9MM_2:
  case AMMO_RIFLE:
  case AMMO_SHOTGUN:
  case AMMO_GRENADE:
  case AMMO_ROCKETS:
  case AMMO_GRENADEROUND:
  case AMMO_MAGNUM:
  case AMMO_GGUN:
  case AMMO_DARTS:
  case AMMO_EXPLOSIVEPEN:
  case AMMO_FLARE:
  case AMMO_PITON:
  case AMMO_DYNAMITE:
  case AMMO_GEKEY:
  case AMMO_TOKEN:
    play_sfx_a1(ptr_sfx_buf, 0xea, 0);
    break;
  case AMMO_REMOTEMINE:
  case AMMO_PROXMINE:
  case AMMO_TIMEDMINE:
  case AMMO_BOMBCASE:
  case AMMO_BUG:
  case AMMO_MICRO_CAMERA:
  case AMMO_PLASTIQUE:
    play_sfx_a1(ptr_sfx_buf, 0xeb, 0);
    break;
  case AMMO_KNIFE:
    play_sfx_a1(ptr_sfx_buf, 0xe9, 0);
  }
}

void set_sound_effect_for_weapontype_collection(ITEM_IDS weapontype)
{
  if ((weapontype == ITEM_KNIFE) || (weapontype == ITEM_THROWKNIFE)) {
    play_sfx_a1(ptr_sfx_buf, 0xe9, 0);
  } else {
    if (((((weapontype == ITEM_REMOTEMINE) ||
           (weapontype == ITEM_PROXIMITYMINE)) ||
          (weapontype == ITEM_TIMEDMINE)) ||
         ((weapontype == ITEM_BOMBCASE || (weapontype == ITEM_BUG)))) ||
        ((weapontype == ITEM_MICROCAMERA || (weapontype == ITEM_PLASTIQUE)))) {
      play_sfx_a1(ptr_sfx_buf, 0xeb, 0);
    } else {
      if (((weapontype == ITEM_GRENADE) || (weapontype == ITEM_57)) ||
          (weapontype == ITEM_56)) {
        play_sfx_a1(ptr_sfx_buf, 0xea, 0);
      } else {
        if (weapontype == ITEM_LASER) {
          play_sfx_a1(ptr_sfx_buf, 0xf2, 0);
        } else {
          play_sfx_a1(ptr_sfx_buf, 0xe8, 0);
        }
      }
    }
  }
}

asm(R"
glabel prepare_ammo_type_collection_text
  addiu $sp, $sp, -0x28
  sw    $ra, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sb    $zero, ($a0)
  lui   $t6, %hi(j_text_trigger) 
  lw    $t6, %lo(j_text_trigger)($t6)
  move  $s0, $a0
  move  $s1, $a1
  beqz  $t6, .L7F04F990
   move  $s2, $a2
  jal   apped_text_ammotype
   nop   
  jal   getPlayerCount
   nop   
  slti  $at, $v0, 3
  beqz  $at, .L7F04F978
   move  $a0, $s0
  move  $a1, $s1
  jal   append_text_picked_up
   move  $a2, $s2
.L7F04F978:
  lui   $a1, %hi(D_800529D0)
  addiu $a1, %lo(D_800529D0) # addiu $a1, $a1, 0x29d0
  jal   string_append_from_obseg_textbank
   move  $a0, $s0
  b     .L7F04F9E4
   lw    $ra, 0x24($sp)
.L7F04F990:
  jal   getPlayerCount
   nop   
  slti  $at, $v0, 3
  beqz  $at, .L7F04F9C0
   move  $a0, $s0
  move  $a1, $s1
  jal   append_text_picked_up
   move  $a2, $s2
  move  $a0, $s0
  move  $a1, $s1
  jal   append_text_ammo_amount_word
   move  $a2, $s2
.L7F04F9C0:
  move  $a0, $s0
  move  $a1, $s1
  jal   apped_text_ammotype
   move  $a2, $s2
  lui   $a1, %hi(D_800529D4)
  addiu $a1, %lo(D_800529D4) # addiu $a1, $a1, 0x29d4
  jal   string_append_from_obseg_textbank
   move  $a0, $s0
  lw    $ra, 0x24($sp)
.L7F04F9E4:
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

#ifdef VERSION_US
asm(R"
glabel display_text_when_ammo_collected
  addiu $sp, $sp, -0x80
  sw    $a0, 0x80($sp)
  lui   $t6, %hi(D_800529D8) 
  addiu $a0, $sp, 0x1c
  move  $a2, $a1
  addiu $t6, %lo(D_800529D8) # addiu $t6, $t6, 0x29d8
  lw    $a1, 0x80($sp)
  sw    $ra, 0x14($sp)
  addiu $t9, $t6, 0x60
  move  $t0, $a0
.L7F04FA20:
  lw    $at, ($t6)
  addiu $t6, $t6, 0xc
  addiu $t0, $t0, 0xc
  sw    $at, -0xc($t0)
  lw    $at, -8($t6)
  sw    $at, -8($t0)
  lw    $at, -4($t6)
  bne   $t6, $t9, .L7F04FA20
   sw    $at, -4($t0)
  lw    $at, ($t6)
  jal   prepare_ammo_type_collection_text
   sw    $at, ($t0)
  jal   display_string_in_lower_left_corner
   addiu $a0, $sp, 0x1c
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x80
  jr    $ra
   nop   
");

#ifdef VERSION_JP
asm(R"
.late_rodata

.text
glabel display_text_when_ammo_collected
  addiu $sp, $sp, -0x80
  sw    $a0, 0x80($sp)
  lui   $t6, %hi(D_800529D8) 
  addiu $a0, $sp, 0x1c
  move  $a2, $a1
  addiu $t6, %lo(D_800529D8) # addiu $t6, $t6, 0x29d8
  lw    $a1, 0x80($sp)
  sw    $ra, 0x14($sp)
  addiu $t9, $t6, 0x60
  move  $t0, $a0
.L7F04FA20:
  lw    $at, ($t6)
  addiu $t6, $t6, 0xc
  addiu $t0, $t0, 0xc
  sw    $at, -0xc($t0)
  lw    $at, -8($t6)
  sw    $at, -8($t0)
  lw    $at, -4($t6)
  bne   $t6, $t9, .L7F04FA20
   sw    $at, -4($t0)
  lw    $at, ($t6)
  jal   prepare_ammo_type_collection_text
   sw    $at, ($t0)
  jal   jp_display_string_in_lower_left_corner
   addiu $a0, $sp, 0x1c
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x80
  jr    $ra
   nop   
");
#endif

#endif

void add_ammo_to_inventory(AMMOTYPES ammotype,int amount,int doplaysound,int dodisplaytext)
{
  int curammo, maxammo;

  if (0 < amount) {
    curammo = check_cur_player_ammo_amount_in_inventory(ammotype);
    maxammo = get_max_ammo_for_type(ammotype);
    if (curammo < maxammo) {
      curammo = check_cur_player_ammo_amount_in_inventory(ammotype);
      give_cur_player_ammo(ammotype, curammo + amount);
#ifdef VERSION_JP
    }
#endif
    if (dodisplaytext != 0) {
      display_text_when_ammo_collected(ammotype, amount);
    }
    if (doplaysound != 0) {
      set_sound_effect_for_ammo_collection(ammotype);
    }
    if (ammotype == AMMO_GRENADE) {
      add_item_to_inventory(ITEM_GRENADE);
    } else if (ammotype == AMMO_REMOTEMINE) {
      add_item_to_inventory(ITEM_REMOTEMINE);
      add_item_to_inventory(ITEM_TRIGGER);
    } else if (ammotype == AMMO_PROXMINE) {
      add_item_to_inventory(ITEM_PROXIMITYMINE);
    } else if (ammotype == AMMO_TIMEDMINE) {
      add_item_to_inventory(ITEM_TIMEDMINE);
    } else if (ammotype == AMMO_KNIFE) {
      add_item_to_inventory(ITEM_THROWKNIFE);
    } else if (ammotype == AMMO_BOMBCASE) {
      add_item_to_inventory(ITEM_BOMBCASE);
    } else if (ammotype == AMMO_BUG) {
      add_item_to_inventory(ITEM_BUG);
    } else if (ammotype == AMMO_MICRO_CAMERA) {
      add_item_to_inventory(ITEM_MICROCAMERA);
    } else if (ammotype == AMMO_GEKEY) {
      add_item_to_inventory(ITEM_GOLDENEYEKEY);
    } else if (ammotype == AMMO_TOKEN) {
      add_item_to_inventory(ITEM_TOKEN);
    } else if (ammotype == AMMO_PLASTIQUE) {
      add_item_to_inventory(ITEM_PLASTIQUE);
    }
#ifndef VERSION_JP
  }
#endif
    }
}

asm(R"
.late_rodata
glabel ammo_collected_from_magazine
.word magazine_has_10_rounds_type1
.word magazine_has_10_rounds_type2
.word magazine_has_10_rounds_type3
.word magazine_has_5_rounds_type4
.word magazine_has_default_ammo_rounds
.word magazine_has_default_ammo_rounds
.word magazine_has_default_ammo_rounds
.word magazine_has_default_ammo_rounds
.word magazine_has_default_ammo_rounds
.word magazine_has_default_ammo_rounds
.word magazine_has_default_ammo_rounds
.word magazine_has_5_rounds_typeC
.word magazine_has_3_rounds_typeD
.word magazine_has_4_rounds_typeE

.text
glabel get_ammo_in_magazine
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  lw    $t6, 0x80($a0)
  li    $v1, 1
  addiu $t7, $t6, -1
  sltiu $at, $t7, 0xe
  beqz  $at, .L7F04FCA4
   sll   $t7, $t7, 2
  lui   $at, %hi(ammo_collected_from_magazine)
  addu  $at, $at, $t7
  lw    $t7, %lo(ammo_collected_from_magazine)($at)
  jr    $t7
   nop   
magazine_has_10_rounds_type1:
  b     .L7F04FCA4
   li    $v1, 10
magazine_has_10_rounds_type2:
  b     .L7F04FCA4
   li    $v1, 10
magazine_has_10_rounds_type3:
  b     .L7F04FCA4
   li    $v1, 10
magazine_has_5_rounds_type4:
  b     .L7F04FCA4
   li    $v1, 5
magazine_has_5_rounds_typeC:
  b     .L7F04FCA4
   li    $v1, 5
magazine_has_3_rounds_typeD:
  b     .L7F04FCA4
   li    $v1, 3
magazine_has_4_rounds_typeE:
  li    $v1, 4
magazine_has_default_ammo_rounds:
.L7F04FCA4:
  slti  $at, $v1, 2
  bnezl $at, .L7F04FCE8
   lw    $ra, 0x14($sp)
  jal   getPlayerCount
   sw    $v1, 0x1c($sp)
  li    $at, 1
  bne   $v0, $at, .L7F04FCE4
   lw    $v1, 0x1c($sp)
  mtc1  $v1, $f4
  lui   $at, %hi(solo_ammo_multiplier)
  lwc1  $f8, %lo(solo_ammo_multiplier)($at)
  cvt.s.w $f6, $f4
  mul.s $f10, $f6, $f8
  trunc.w.s $f16, $f10
  mfc1  $v1, $f16
  nop   
.L7F04FCE4:
  lw    $ra, 0x14($sp)
.L7F04FCE8:
  addiu $sp, $sp, 0x20
  move  $v0, $v1
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel ammo_in_weapon
.word weapon_has_10_rounds_type1
.word weapon_has_10_rounds_type2
.word weapon_has_10_rounds_type3
.word weapon_has_5_rounds_type4
.word weapon_has_default_ammo
.word weapon_has_default_ammo
.word weapon_has_default_ammo
.word weapon_has_default_ammo
.word weapon_has_default_ammo
.word weapon_has_default_ammo
.word weapon_has_3_rounds_typeB
.word weapon_has_5_rounds_typeC
.word weapon_has_3_rounds_typeD
.word weapon_has_4_rounds_typeE

.text
glabel ammo_collected_from_weapon
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a0, 0x20($sp)
  jal   get_ammo_type_for_weapon
   lb    $a0, 0x80($a0)
  lw    $t7, 0x20($sp)
  addiu $t0, $v0, -1
  li    $v1, 1
  lw    $t8, 8($t7)
  sltiu $at, $t0, 0xe
  sll   $t9, $t8, 1
  bgez  $t9, .L7F04FD34
   nop   
  b     .L7F04FDD0
   move  $v0, $zero
.L7F04FD34:
  beqz  $at, .L7F04FD8C
   sll   $t0, $t0, 2
  lui   $at, %hi(ammo_in_weapon)
  addu  $at, $at, $t0
  lw    $t0, %lo(ammo_in_weapon)($at)
  jr    $t0
   nop   
weapon_has_10_rounds_type1:
  b     .L7F04FD8C
   li    $v1, 10
weapon_has_10_rounds_type2:
  b     .L7F04FD8C
   li    $v1, 10
weapon_has_10_rounds_type3:
  b     .L7F04FD8C
   li    $v1, 10
weapon_has_5_rounds_type4:
  b     .L7F04FD8C
   li    $v1, 5
weapon_has_5_rounds_typeC:
  b     .L7F04FD8C
   li    $v1, 5
weapon_has_3_rounds_typeD:
  b     .L7F04FD8C
   li    $v1, 3
weapon_has_4_rounds_typeE:
  b     .L7F04FD8C
   li    $v1, 4
weapon_has_3_rounds_typeB:
  li    $v1, 3
weapon_has_default_ammo:
.L7F04FD8C:
  slti  $at, $v1, 2
  bnezl $at, .L7F04FDD0
   move  $v0, $v1
  jal   getPlayerCount
   sw    $v1, 0x18($sp)
  li    $at, 1
  bne   $v0, $at, .L7F04FDCC
   lw    $v1, 0x18($sp)
  mtc1  $v1, $f4
  lui   $at, %hi(solo_ammo_multiplier)
  lwc1  $f8, %lo(solo_ammo_multiplier)($at)
  cvt.s.w $f6, $f4
  mul.s $f10, $f6, $f8
  trunc.w.s $f16, $f10
  mfc1  $v1, $f16
  nop   
.L7F04FDCC:
  move  $v0, $v1
.L7F04FDD0:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel jpt_800530D0
.word weapon_collect_msg_a_hunting_knife
.word weapon_collect_msg_BLANK
.word weapon_collect_msg_a_pp7
.word weapon_collect_msg_a_silenced_pp7
.word weapon_collect_msg_a_dd44
.word weapon_collect_msg_a_klobb
.word weapon_collect_msg_a_kf7
.word weapon_collect_msg_a_zmg
.word weapon_collect_msg_a_d5k
.word weapon_collect_msg_a_silenced_d5k
.word weapon_collect_msg_a_phantom
.word weapon_collect_msg_a_ar33
.word weapon_collect_msg_a_rcp90
.word weapon_collect_msg_a_shotgun
.word weapon_collect_msg_an_auto_shotgun
.word weapon_collect_msg_a_sniper
.word weapon_collect_msg_a_cougar_magnum
.word weapon_collect_msg_a_golden_gun
.word weapon_collect_msg_a_silver_pp7
.word weapon_collect_msg_a_gold_pp7
.word weapon_collect_msg_a_moonraker_laser
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_grenade_launcher
.word weapon_collect_msg_a_rocket_launcher
.word weapon_collect_msg_BLANK
.word weapon_collect_msg_BLANK
.word weapon_collect_msg_BLANK
.word weapon_collect_msg_BLANK
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_BLANK
.word weapon_collect_msg_BLANK
.word weapon_collect_msg_a_flare_pistol
.word weapon_collect_msg_a_piton_gun
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_BLANK
.word weapon_collect_msg_BLANK
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_BLANK
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_keycard
.word weapon_collect_msg_a_yale_key
.word weapon_collect_msg_a_bolt_key
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_a_new_weapon
.word weapon_collect_msg_BLANK
.word weapon_collect_msg_BLANK
.word weapon_collect_msg_BLANK

.text
glabel generate_language_specific_text_for_weapon
  lui   $t6, %hi(j_text_trigger) 
  lw    $t6, %lo(j_text_trigger)($t6)
  addiu $sp, $sp, -0x28
  sw    $s0, 0x18($sp)
  move  $s0, $a0
  sw    $ra, 0x1c($sp)
  sw    $a1, 0x2c($sp)
  beqz  $t6, .L7F04FE2C
   sw    $zero, 0x24($sp)
  lui   $a1, %hi(D_80052A3C)
  jal   textpointer_load_parse_something
   addiu $a1, %lo(D_80052A3C) # addiu $a1, $a1, 0x2a3c
  jal   getPlayerCount
   nop   
  slti  $at, $v0, 3
  bnez  $at, .L7F04FE54
   li    $t7, 1
  b     .L7F04FE54
   sw    $t7, 0x24($sp)
.L7F04FE2C:
  jal   getPlayerCount
   nop   
  slti  $at, $v0, 3
  beql  $at, $zero, .L7F04FE58
   lw    $t8, 0x2c($sp)
  jal   get_textptr_for_textID
   li    $a0, 41984
  move  $a0, $s0
  jal   textpointer_load_parse_something
   move  $a1, $v0
.L7F04FE54:
  lw    $t8, 0x2c($sp)
.L7F04FE58:
  addiu $t9, $t8, -2
  sltiu $at, $t9, 0x57
  beqz  $at, .L7F050190
   sll   $t9, $t9, 2
  lui   $at, %hi(jpt_800530D0)
  addu  $at, $at, $t9
  lw    $t9, %lo(jpt_800530D0)($at)
  jr    $t9
   nop   
weapon_collect_msg_BLANK:
  jal   get_ammo_type_for_weapon
   lw    $a0, 0x2c($sp)
  move  $a0, $s0
  move  $a1, $v0
  jal   prepare_ammo_type_collection_text
   li    $a2, 1
  b     .L7F050214
   lw    $ra, 0x1c($sp)
weapon_collect_msg_a_hunting_knife:
  jal   get_textptr_for_textID
   li    $a0, 42016
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F0501A4
   nop   
weapon_collect_msg_a_pp7:
  jal   get_textptr_for_textID
   li    $a0, 42017
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F0501A4
   nop   
weapon_collect_msg_a_silenced_pp7:
  jal   get_textptr_for_textID
   li    $a0, 42018
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F0501A4
   nop   
weapon_collect_msg_a_dd44:
  jal   get_textptr_for_textID
   li    $a0, 42019
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F0501A4
   nop   
weapon_collect_msg_a_klobb:
  jal   get_textptr_for_textID
   li    $a0, 42020
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F0501A4
   nop   
weapon_collect_msg_a_kf7:
  jal   get_textptr_for_textID
   li    $a0, 42021
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F0501A4
   nop   
weapon_collect_msg_a_zmg:
  jal   get_textptr_for_textID
   li    $a0, 42022
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F0501A4
   nop   
weapon_collect_msg_a_d5k:
  jal   get_textptr_for_textID
   li    $a0, 42023
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F0501A4
   nop   
weapon_collect_msg_a_silenced_d5k:
  jal   get_textptr_for_textID
   li    $a0, 42024
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F0501A4
   nop   
weapon_collect_msg_a_phantom:
  jal   get_textptr_for_textID
   li    $a0, 42025
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F0501A4
   nop   
weapon_collect_msg_a_ar33:
  jal   get_textptr_for_textID
   li    $a0, 42026
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F0501A4
   nop   
weapon_collect_msg_a_rcp90:
  jal   get_textptr_for_textID
   li    $a0, 42027
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F0501A4
   nop   
weapon_collect_msg_a_shotgun:
  jal   get_textptr_for_textID
   li    $a0, 42028
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F0501A4
   nop   
weapon_collect_msg_an_auto_shotgun:
  jal   get_textptr_for_textID
   li    $a0, 42029
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F0501A4
   nop   
weapon_collect_msg_a_sniper:
  jal   get_textptr_for_textID
   li    $a0, 42030
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F0501A4
   nop   
weapon_collect_msg_a_grenade_launcher:
  jal   get_textptr_for_textID
   li    $a0, 42031
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F0501A4
   nop   
weapon_collect_msg_a_rocket_launcher:
  jal   get_textptr_for_textID
   li    $a0, 42032
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F0501A4
   nop   
weapon_collect_msg_a_cougar_magnum:
  jal   get_textptr_for_textID
   li    $a0, 42033
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F0501A4
   nop   
weapon_collect_msg_a_golden_gun:
  jal   get_textptr_for_textID
   li    $a0, 42034
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F0501A4
   nop   
weapon_collect_msg_a_moonraker_laser:
  jal   get_textptr_for_textID
   li    $a0, 42035
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F0501A4
   nop   
weapon_collect_msg_a_flare_pistol:
  jal   get_textptr_for_textID
   li    $a0, 42036
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F0501A4
   nop   
weapon_collect_msg_a_piton_gun:
  jal   get_textptr_for_textID
   li    $a0, 42037
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F0501A4
   nop   
weapon_collect_msg_a_silver_pp7:
  jal   get_textptr_for_textID
   li    $a0, 42038
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F0501A4
   nop   
weapon_collect_msg_a_gold_pp7:
  jal   get_textptr_for_textID
   li    $a0, 42039
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F0501A4
   nop   
weapon_collect_msg_a_keycard:
  jal   get_textptr_for_textID
   li    $a0, 42040
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F0501A4
   nop   
weapon_collect_msg_a_yale_key:
  jal   get_textptr_for_textID
   li    $a0, 42041
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F0501A4
   nop   
weapon_collect_msg_a_bolt_key:
  jal   get_textptr_for_textID
   li    $a0, 42042
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  b     .L7F0501A4
   nop   
weapon_collect_msg_a_new_weapon:
.L7F050190:
  jal   get_textptr_for_textID
   li    $a0, 42043
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
.L7F0501A4:
  lui   $t0, %hi(j_text_trigger) 
  lw    $t0, %lo(j_text_trigger)($t0)
  lw    $t1, 0x24($sp)
  beql  $t0, $zero, .L7F050214
   lw    $ra, 0x1c($sp)
  bnezl $t1, .L7F050214
   lw    $ra, 0x1c($sp)
  jal   strlen
   move  $a0, $s0
  addu  $t2, $v0, $s0
  lbu   $t3, -1($t2)
  li    $at, 10
  bne   $t3, $at, .L7F0501EC
   nop   
  jal   strlen
   move  $a0, $s0
  addu  $t4, $s0, $v0
  sb    $zero, -1($t4)
.L7F0501EC:
  jal   get_textptr_for_textID
   li    $a0, 41984
  move  $a0, $s0
  jal   string_append_from_obseg_textbank
   move  $a1, $v0
  lui   $a1, %hi(D_80052A40)
  addiu $a1, %lo(D_80052A40) # addiu $a1, $a1, 0x2a40
  jal   string_append_from_obseg_textbank
   move  $a0, $s0
  lw    $ra, 0x1c($sp)
.L7F050214:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

void display_text_for_weapon_in_lower_left_corner(ITEM_IDS weaponid) {
  char acStack100[100];

  generate_language_specific_text_for_weapon(acStack100, weaponid);
#ifdef VERSION_JP
  jp_display_string_in_lower_left_corner(acStack100);
#else
    display_string_in_lower_left_corner(acStack100);
#endif
  return;
}

#ifdef VERSION_US
asm(R"
.late_rodata
/*D:8005322C*/
glabel object_interaction_table
.word interact_default_object
.word interact_key_object
.word interact_default_object
.word interact_default_object
.word interact_magazine_object
.word interact_weapon_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_ammobox_object
.word interact_bodyarmor_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object

.text
glabel collect_or_interact_object
  addiu $sp, $sp, -0x70
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a0, 0x70($sp)
  sw    $a1, 0x74($sp)
  lw    $v1, 4($a0)
  lui   $t7, %hi(pPlayer) 
  lw    $t7, %lo(pPlayer)($t7)
  sw    $v1, 0x6c($sp)
  lui   $t9, %hi(clock_timer) 
  lw    $t8, 0xd8($t7)
  bnez  $t8, .L7F050294
   nop   
  lw    $t9, %lo(clock_timer)($t9)
  lw    $t0, 0x6c($sp)
  bnezl $t9, .L7F0502A0
   lbu   $t1, 3($t0)
.L7F050294:
  b     .L7F0506C8
   move  $v0, $zero
  lbu   $t1, 3($t0)
.L7F0502A0:
  addiu $t2, $t1, -3
  sltiu $at, $t2, 0x2d
  beqz  $at, .L7F05062C
   sll   $t2, $t2, 2
  lui   $at, %hi(object_interaction_table)
  addu  $at, $at, $t2
  lw    $t2, %lo(object_interaction_table)($at)
  jr    $t2
   nop   
interact_key_object:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 229
  jal   play_sfx_a1
   move  $a2, $zero
  lw    $t3, 0x74($sp)
  beqz  $t3, .L7F050308
   nop   
  jal   obj_get_activated_text
   lw    $a0, 0x6c($sp)
  bnez  $v0, .L7F050300
   move  $a0, $v0
  jal   get_textptr_for_textID
   li    $a0, 42044
  move  $a0, $v0
.L7F050300:
  jal   display_string_in_lower_left_corner
   nop   
.L7F050308:
  b     .L7F050674
   li    $v1, 4
interact_magazine_object:
  move  $s0, $v1
  jal   get_ammo_in_magazine
   move  $a0, $v1
  lw    $a0, 0x80($s0)
  move  $a1, $v0
  li    $a2, 1
  jal   add_ammo_to_inventory
   lw    $a3, 0x74($sp)
  b     .L7F050674
   li    $v1, 1
interact_ammobox_object:
  move  $v0, $zero
  move  $s0, $v1
  addiu $v1, $v0, 1
.L7F050344:
  li    $at, 1
  bne   $v0, $at, .L7F050354
   move  $a0, $v1
  li    $a0, 1
.L7F050354:
  lhu   $a1, 0x82($s0)
  sw    $a0, 0x4c($sp)
  sw    $v1, 0x20($sp)
  jal   getPlayerCount
   sw    $a1, 0x50($sp)
  li    $at, 1
  lw    $v1, 0x20($sp)
  lw    $a0, 0x4c($sp)
  bne   $v0, $at, .L7F05039C
   lw    $a1, 0x50($sp)
  mtc1  $a1, $f4
  lui   $at, %hi(solo_ammo_multiplier)
  lwc1  $f8, %lo(solo_ammo_multiplier)($at)
  cvt.s.w $f6, $f4
  mul.s $f10, $f6, $f8
  trunc.w.s $f16, $f10
  mfc1  $a1, $f16
  nop   
.L7F05039C:
  move  $a2, $zero
  lw    $a3, 0x74($sp)
  jal   add_ammo_to_inventory
   sw    $v1, 0x20($sp)
  lw    $v0, 0x20($sp)
  li    $at, 13
  addiu $s0, $s0, 4
  bnel  $v0, $at, .L7F050344
   addiu $v1, $v0, 1
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 234
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F050674
   li    $v1, 1
interact_weapon_object:
  sw    $zero, 0x44($sp)
  lb    $a0, 0x80($v1)
  jal   set_sound_effect_for_weapontype_collection
   sw    $v1, 0x48($sp)
  lw    $t5, 0x48($sp)
  li    $at, 29
  lb    $a0, 0x80($t5)
  bnel  $a0, $at, .L7F050414
   li    $at, 88
  jal   add_item_to_inventory
   li    $a0, 30
  b     .L7F050428
   lw    $t6, 0x6c($sp)
  li    $at, 88
.L7F050414:
  bne   $a0, $at, .L7F050424
   li    $a1, 88
  jal   draw_item_in_hand_has_more_ammo
   move  $a0, $zero
.L7F050424:
  lw    $t6, 0x6c($sp)
.L7F050428:
  lw    $t9, 0x48($sp)
  lw    $t7, 0x64($t6)
  andi  $t8, $t7, 0x400
  beqz  $t8, .L7F0504A4
   nop   
  lb    $t0, 0x80($t9)
  slti  $at, $t0, 0x21
  beql  $at, $zero, .L7F050458
   lw    $t1, 0x74($sp)
  jal   sub_GAME_7F08C764
   lw    $a0, 0x70($sp)
  lw    $t1, 0x74($sp)
.L7F050458:
  beql  $t1, $zero, .L7F050498
   lw    $t4, 0x48($sp)
  jal   obj_get_activated_text
   lw    $a0, 0x6c($sp)
  beqz  $v0, .L7F050480
   move  $a0, $v0
  jal   display_string_in_lower_left_corner
   nop   
  b     .L7F050490
   li    $t3, 1
.L7F050480:
  lw    $t2, 0x48($sp)
  jal   display_text_for_weapon_in_lower_left_corner
   lb    $a0, 0x80($t2)
  li    $t3, 1
.L7F050490:
  sw    $t3, 0x44($sp)
  lw    $t4, 0x48($sp)
.L7F050498:
  li    $v1, 4
  b     .L7F050510
   lb    $a0, 0x80($t4)
.L7F0504A4:
  jal   sub_GAME_7F08C764
   lw    $a0, 0x70($sp)
  beqz  $v0, .L7F0504B8
   li    $t5, 1
  sw    $t5, 0x44($sp)
.L7F0504B8:
  lw    $t6, 0x74($sp)
  lw    $t7, 0x48($sp)
  beql  $t6, $zero, .L7F050508
   lw    $t1, 0x48($sp)
  jal   weapon_get_activated_text
   lb    $a0, 0x80($t7)
  beqz  $v0, .L7F0504EC
   move  $a0, $v0
  li    $t8, 1
  jal   display_string_in_lower_left_corner
   sw    $t8, 0x44($sp)
  b     .L7F050508
   lw    $t1, 0x48($sp)
.L7F0504EC:
  lw    $t9, 0x44($sp)
  lw    $t0, 0x48($sp)
  beql  $t9, $zero, .L7F050508
   lw    $t1, 0x48($sp)
  jal   display_text_for_weapon_in_lower_left_corner
   lb    $a0, 0x80($t0)
  lw    $t1, 0x48($sp)
.L7F050508:
  li    $v1, 1
  lb    $a0, 0x80($t1)
.L7F050510:
  jal   get_ammo_type_for_weapon
   sw    $v1, 0x68($sp)
  lw    $v1, 0x68($sp)
  beqz  $v0, .L7F050674
   move  $s0, $v0
  lw    $a0, 0x48($sp)
  jal   ammo_collected_from_weapon
   sw    $v1, 0x68($sp)
  lw    $v1, 0x68($sp)
  blez  $v0, .L7F050674
   sw    $v0, 0x34($sp)
  move  $a0, $s0
  jal   check_cur_player_ammo_amount_in_inventory
   sw    $v1, 0x68($sp)
  sw    $v0, 0x24($sp)
  jal   get_max_ammo_for_type
   move  $a0, $s0
  lw    $t2, 0x24($sp)
  lw    $v1, 0x68($sp)
  move  $a0, $s0
  slt   $at, $t2, $v0
  beql  $at, $zero, .L7F050678
   li    $at, 1
  jal   check_cur_player_ammo_amount_in_inventory
   sw    $v1, 0x68($sp)
  lw    $t3, 0x34($sp)
  move  $a0, $s0
  jal   give_cur_player_ammo
   addu  $a1, $v0, $t3
  lw    $t4, 0x44($sp)
  lw    $v1, 0x68($sp)
  lw    $t5, 0x74($sp)
  bnezl $t4, .L7F050678
   li    $at, 1
  beqz  $t5, .L7F050674
   move  $a0, $s0
  lw    $a1, 0x34($sp)
  jal   display_text_when_ammo_collected
   sw    $v1, 0x68($sp)
  b     .L7F050674
   lw    $v1, 0x68($sp)
interact_bodyarmor_object:
  jal   add_BONDdata_watch_armor
   lwc1  $f12, 0x84($v1)
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 81
  jal   play_sfx_a1
   move  $a2, $zero
  lw    $t6, 0x74($sp)
  beqz  $t6, .L7F050624
   nop   
  jal   obj_get_activated_text
   lw    $a0, 0x6c($sp)
  bnez  $v0, .L7F05061C
   move  $a0, $v0
  jal   getPlayerCount
   nop   
  slti  $at, $v0, 3
  beqz  $at, .L7F050610
   nop   
  jal   get_textptr_for_textID
   li    $a0, 42045
  b     .L7F05061C
   move  $a0, $v0
.L7F050610:
  jal   get_textptr_for_textID
   li    $a0, 42046
  move  $a0, $v0
.L7F05061C:
  jal   display_string_in_lower_left_corner
   nop   
.L7F050624:
  b     .L7F050674
   li    $v1, 1
interact_default_object:
.L7F05062C:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 229
  jal   play_sfx_a1
   move  $a2, $zero
  lw    $t7, 0x74($sp)
  beql  $t7, $zero, .L7F050674
   li    $v1, 4
  jal   obj_get_activated_text
   lw    $a0, 0x6c($sp)
  bnez  $v0, .L7F050668
   move  $a0, $v0
  jal   get_textptr_for_textID
   li    $a0, 42047
  move  $a0, $v0
.L7F050668:
  jal   display_string_in_lower_left_corner
   nop   
  li    $v1, 4
.L7F050674:
  li    $at, 1
.L7F050678:
  bne   $v1, $at, .L7F0506B0
   lw    $t8, 0x6c($sp)
  lw    $t9, 0x64($t8)
  andi  $t0, $t9, 0x10
  bnez  $t0, .L7F0506B0
   nop   
  lbu   $a2, 2($t8)
  move  $a0, $t8
  move  $a1, $zero
  andi  $t1, $a2, 4
  jal   sub_GAME_7F040D98
   move  $a2, $t1
  b     .L7F0506C8
   li    $v0, 1
.L7F0506B0:
  beqz  $v1, .L7F0506C8
   move  $v0, $zero
  jal   add_prop_to_inventory
   lw    $a0, 0x70($sp)
  b     .L7F0506C8
   li    $v0, 4
.L7F0506C8:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x70
  jr    $ra
   nop   
");
#ifdef VERSION_JP
asm(R"
.late_rodata
/*D:8005322C*/
glabel object_interaction_table
.word interact_default_object
.word interact_key_object
.word interact_default_object
.word interact_default_object
.word interact_magazine_object
.word interact_weapon_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_ammobox_object
.word interact_bodyarmor_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object
.word interact_default_object

.text
glabel collect_or_interact_object
  addiu $sp, $sp, -0x70
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a0, 0x70($sp)
  sw    $a1, 0x74($sp)
  lw    $v1, 4($a0)
  lui   $t7, %hi(pPlayer) 
  lw    $t7, %lo(pPlayer)($t7)
  sw    $v1, 0x6c($sp)
  lui   $t9, %hi(clock_timer) 
  lw    $t8, 0xd8($t7)
  bnez  $t8, .L7F050294
   nop   
  lw    $t9, %lo(clock_timer)($t9)
  lw    $t0, 0x6c($sp)
  bnezl $t9, .L7F0502A0
   lbu   $t1, 3($t0)
.L7F050294:
  b     .L7F0506C8
   move  $v0, $zero
  lbu   $t1, 3($t0)
.L7F0502A0:
  addiu $t2, $t1, -3
  sltiu $at, $t2, 0x2d
  beqz  $at, .L7F05062C
   sll   $t2, $t2, 2
  lui   $at, %hi(object_interaction_table)
  addu  $at, $at, $t2
  lw    $t2, %lo(object_interaction_table)($at)
  jr    $t2
   nop   
interact_key_object:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 229
  jal   play_sfx_a1
   move  $a2, $zero
  lw    $t3, 0x74($sp)
  beqz  $t3, .L7F050308
   nop   
  jal   obj_get_activated_text
   lw    $a0, 0x6c($sp)
  bnez  $v0, .L7F050300
   move  $a0, $v0
  jal   get_textptr_for_textID
   li    $a0, 42044
  move  $a0, $v0
.L7F050300:
  jal   jp_display_string_in_lower_left_corner
   nop   
.L7F050308:
  b     .L7F050674
   li    $v1, 4
interact_magazine_object:
  move  $s0, $v1
  jal   get_ammo_in_magazine
   move  $a0, $v1
  lw    $a0, 0x80($s0)
  move  $a1, $v0
  li    $a2, 1
  jal   add_ammo_to_inventory
   lw    $a3, 0x74($sp)
  b     .L7F050674
   li    $v1, 1
interact_ammobox_object:
  move  $v0, $zero
  move  $s0, $v1
  addiu $v1, $v0, 1
.L7F050344:
  li    $at, 1
  bne   $v0, $at, .L7F050354
   move  $a0, $v1
  li    $a0, 1
.L7F050354:
  lhu   $a1, 0x82($s0)
  sw    $a0, 0x4c($sp)
  sw    $v1, 0x20($sp)
  jal   getPlayerCount
   sw    $a1, 0x50($sp)
  li    $at, 1
  lw    $v1, 0x20($sp)
  lw    $a0, 0x4c($sp)
  bne   $v0, $at, .L7F05039C
   lw    $a1, 0x50($sp)
  mtc1  $a1, $f4
  lui   $at, %hi(solo_ammo_multiplier)
  lwc1  $f8, %lo(solo_ammo_multiplier)($at)
  cvt.s.w $f6, $f4
  mul.s $f10, $f6, $f8
  trunc.w.s $f16, $f10
  mfc1  $a1, $f16
  nop   
.L7F05039C:
  move  $a2, $zero
  lw    $a3, 0x74($sp)
  jal   add_ammo_to_inventory
   sw    $v1, 0x20($sp)
  lw    $v0, 0x20($sp)
  li    $at, 13
  addiu $s0, $s0, 4
  bnel  $v0, $at, .L7F050344
   addiu $v1, $v0, 1
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 234
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F050674
   li    $v1, 1
interact_weapon_object:
  sw    $zero, 0x44($sp)
  lb    $a0, 0x80($v1)
  jal   set_sound_effect_for_weapontype_collection
   sw    $v1, 0x48($sp)
  lw    $t5, 0x48($sp)
  li    $at, 29
  lb    $a0, 0x80($t5)
  bnel  $a0, $at, .L7F050414
   li    $at, 88
  jal   add_item_to_inventory
   li    $a0, 30
  b     .L7F050428
   lw    $t6, 0x6c($sp)
  li    $at, 88
.L7F050414:
  bne   $a0, $at, .L7F050424
   li    $a1, 88
  jal   draw_item_in_hand_has_more_ammo
   move  $a0, $zero
.L7F050424:
  lw    $t6, 0x6c($sp)
.L7F050428:
  lw    $t9, 0x48($sp)
  lw    $t7, 0x64($t6)
  andi  $t8, $t7, 0x400
  beqz  $t8, .L7F0504A4
   nop   
  lb    $t0, 0x80($t9)
  slti  $at, $t0, 0x21
  beql  $at, $zero, .L7F050458
   lw    $t1, 0x74($sp)
  jal   sub_GAME_7F08C764
   lw    $a0, 0x70($sp)
  lw    $t1, 0x74($sp)
.L7F050458:
  beql  $t1, $zero, .L7F050498
   lw    $t4, 0x48($sp)
  jal   obj_get_activated_text
   lw    $a0, 0x6c($sp)
  beqz  $v0, .L7F050480
   move  $a0, $v0
  jal   jp_display_string_in_lower_left_corner
   nop   
  b     .L7F050490
   li    $t3, 1
.L7F050480:
  lw    $t2, 0x48($sp)
  jal   display_text_for_weapon_in_lower_left_corner
   lb    $a0, 0x80($t2)
  li    $t3, 1
.L7F050490:
  sw    $t3, 0x44($sp)
  lw    $t4, 0x48($sp)
.L7F050498:
  li    $v1, 4
  b     .L7F050510
   lb    $a0, 0x80($t4)
.L7F0504A4:
  jal   sub_GAME_7F08C764
   lw    $a0, 0x70($sp)
  beqz  $v0, .L7F0504B8
   li    $t5, 1
  sw    $t5, 0x44($sp)
.L7F0504B8:
  lw    $t6, 0x74($sp)
  lw    $t7, 0x48($sp)
  beql  $t6, $zero, .L7F050508
   lw    $t1, 0x48($sp)
  jal   weapon_get_activated_text
   lb    $a0, 0x80($t7)
  beqz  $v0, .L7F0504EC
   move  $a0, $v0
  li    $t8, 1
  jal   jp_display_string_in_lower_left_corner
   sw    $t8, 0x44($sp)
  b     .L7F050508
   lw    $t1, 0x48($sp)
.L7F0504EC:
  lw    $t9, 0x44($sp)
  lw    $t0, 0x48($sp)
  beql  $t9, $zero, .L7F050508
   lw    $t1, 0x48($sp)
  jal   display_text_for_weapon_in_lower_left_corner
   lb    $a0, 0x80($t0)
  lw    $t1, 0x48($sp)
.L7F050508:
  li    $v1, 1
  lb    $a0, 0x80($t1)
.L7F050510:
  jal   get_ammo_type_for_weapon
   sw    $v1, 0x68($sp)
  lw    $v1, 0x68($sp)
  beqz  $v0, .L7F050674
   move  $s0, $v0
  lw    $a0, 0x48($sp)
  jal   ammo_collected_from_weapon
   sw    $v1, 0x68($sp)
  lw    $v1, 0x68($sp)
  blez  $v0, .L7F050674
   sw    $v0, 0x34($sp)
  move  $a0, $s0
  jal   check_cur_player_ammo_amount_in_inventory
   sw    $v1, 0x68($sp)
  sw    $v0, 0x24($sp)
  jal   get_max_ammo_for_type
   move  $a0, $s0
  lw    $t2, 0x24($sp)
  lw    $v1, 0x68($sp)
  move  $a0, $s0
  slt   $at, $t2, $v0
  beql  $at, $zero, .L7F050678
   li    $at, 1
  jal   check_cur_player_ammo_amount_in_inventory
   sw    $v1, 0x68($sp)
  lw    $t3, 0x34($sp)
  move  $a0, $s0
  jal   give_cur_player_ammo
   addu  $a1, $v0, $t3
  lw    $t4, 0x44($sp)
  lw    $v1, 0x68($sp)
  lw    $t5, 0x74($sp)
  bnezl $t4, .L7F050678
   li    $at, 1
  beqz  $t5, .L7F050674
   move  $a0, $s0
  lw    $a1, 0x34($sp)
  jal   display_text_when_ammo_collected
   sw    $v1, 0x68($sp)
  b     .L7F050674
   lw    $v1, 0x68($sp)
interact_bodyarmor_object:
  jal   add_BONDdata_watch_armor
   lwc1  $f12, 0x84($v1)
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 81
  jal   play_sfx_a1
   move  $a2, $zero
  lw    $t6, 0x74($sp)
  beqz  $t6, .L7F050624
   nop   
  jal   obj_get_activated_text
   lw    $a0, 0x6c($sp)
  bnez  $v0, .L7F05061C
   move  $a0, $v0
  jal   getPlayerCount
   nop   
  slti  $at, $v0, 3
  beqz  $at, .L7F050610
   nop   
  jal   get_textptr_for_textID
   li    $a0, 42045
  b     .L7F05061C
   move  $a0, $v0
.L7F050610:
  jal   get_textptr_for_textID
   li    $a0, 42046
  move  $a0, $v0
.L7F05061C:
  jal   jp_display_string_in_lower_left_corner
   nop   
.L7F050624:
  b     .L7F050674
   li    $v1, 1
interact_default_object:
.L7F05062C:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 229
  jal   play_sfx_a1
   move  $a2, $zero
  lw    $t7, 0x74($sp)
  beql  $t7, $zero, .L7F050674
   li    $v1, 4
  jal   obj_get_activated_text
   lw    $a0, 0x6c($sp)
  bnez  $v0, .L7F050668
   move  $a0, $v0
  jal   get_textptr_for_textID
   li    $a0, 42047
  move  $a0, $v0
.L7F050668:
  jal   jp_display_string_in_lower_left_corner
   nop   
  li    $v1, 4
.L7F050674:
  li    $at, 1
.L7F050678:
  bne   $v1, $at, .L7F0506B0
   lw    $t8, 0x6c($sp)
  lw    $t9, 0x64($t8)
  andi  $t0, $t9, 0x10
  bnez  $t0, .L7F0506B0
   nop   
  lbu   $a2, 2($t8)
  move  $a0, $t8
  move  $a1, $zero
  andi  $t1, $a2, 4
  jal   sub_GAME_7F040D98
   move  $a2, $t1
  b     .L7F0506C8
   li    $v0, 1
.L7F0506B0:
  beqz  $v1, .L7F0506C8
   move  $v0, $zero
  jal   add_prop_to_inventory
   lw    $a0, 0x70($sp)
  b     .L7F0506C8
   li    $v0, 4
.L7F0506C8:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x70
  jr    $ra
   nop   
");
#endif
#endif

#ifdef VERSION_US
asm(R"
.late_rodata
glabel D_800532E0
.word 0xbf490fdb /*-0.78539819*/
glabel D_800532E4
.word 0x47ef4200 /*122500.0*/
glabel D_800532E8
.word 0x461c4000 /*10000.0*/
glabel D_800532EC
.word 0x47742400 /*62500.0*/
glabel D_800532F0
.word 0x40490fdb /*3.1415927*/
.text
glabel object_collectability_routines
  addiu $sp, $sp, -0x88
  sw    $ra, 0x2c($sp)
  sw    $a0, 0x88($sp)
  lw    $a0, 4($a0)
  jal   check_if_collectable_object
   sw    $a0, 0x84($sp)
  beqz  $v0, .L7F050724
   lw    $a0, 0x84($sp)
  lbu   $t7, 3($a0)
  li    $at, 17
  beql  $t7, $at, .L7F050728
   lw    $a0, 0x84($sp)
  lw    $v0, 8($a0)
  sll   $t8, $v0, 0xb
  bgezl $t8, .L7F050744
   sll   $t1, $v0, 0xc
  b     .L7F050D20
   move  $v0, $zero
.L7F050724:
  lw    $a0, 0x84($sp)
.L7F050728:
  lw    $v0, 8($a0)
  sll   $t9, $v0, 0xd
  bltzl $t9, .L7F050744
   sll   $t1, $v0, 0xc
  b     .L7F050D20
   move  $v0, $zero
  sll   $t1, $v0, 0xc
.L7F050744:
  bgezl $t1, .L7F050758
   lw    $t2, 0x64($a0)
  b     .L7F050D20
   move  $v0, $zero
  lw    $t2, 0x64($a0)
.L7F050758:
  andi  $t3, $t2, 0x80
  beqz  $t3, .L7F050788
   nop   
  lw    $v0, 0x6c($a0)
  lw    $t4, 0xbc($v0)
  blez  $t4, .L7F050788
   nop   
  lw    $t5, 0x90($v0)
  bnez  $t5, .L7F050788
   nop   
  b     .L7F050D20
   move  $v0, $zero
.L7F050788:
  jal   sub_GAME_7F03E7AC
   nop   
  bnez  $v0, .L7F0507A0
   lw    $a1, 0x84($sp)
  b     .L7F050D20
   move  $v0, $zero
.L7F0507A0:
  lbu   $v0, 3($a1)
  li    $at, 8
  lw    $t6, 0x88($sp)
  bnel  $v0, $at, .L7F050940
   li    $at, 7
  lw    $v1, 4($t6)
  li    $at, 26
  lb    $a0, 0x80($v1)
  beq   $a0, $at, .L7F0507D0
   li    $at, 87
  bnel  $a0, $at, .L7F0507F8
   li    $at, 29
.L7F0507D0:
  lh    $t7, 0x82($v1)
  bgez  $t7, .L7F0507EC
   nop   
  lw    $t8, 0x64($a1)
  andi  $t9, $t8, 4
  beql  $t9, $zero, .L7F0507F8
   li    $at, 29
.L7F0507EC:
  b     .L7F050D20
   move  $v0, $zero
  li    $at, 29
.L7F0507F8:
  beq   $a0, $at, .L7F050830
   li    $at, 28
  beq   $a0, $at, .L7F050830
   li    $at, 27
  beq   $a0, $at, .L7F050830
   li    $at, 33
  beq   $a0, $at, .L7F050830
   li    $at, 47
  beq   $a0, $at, .L7F050830
   li    $at, 48
  beq   $a0, $at, .L7F050830
   li    $at, 34
  bnel  $a0, $at, .L7F050858
   li    $at, 86
.L7F050830:
  lh    $t1, 0x82($v1)
  bgez  $t1, .L7F05084C
   nop   
  lw    $t2, 0x64($a1)
  andi  $t3, $t2, 4
  beql  $t3, $zero, .L7F050858
   li    $at, 86
.L7F05084C:
  b     .L7F050D20
   move  $v0, $zero
  li    $at, 86
.L7F050858:
  bne   $a0, $at, .L7F050878
   nop   
  lw    $t4, 0x64($a1)
  andi  $t5, $t4, 0x80
  beqz  $t5, .L7F050878
   nop   
  b     .L7F050D20
   move  $v0, $zero
.L7F050878:
  jal   is_weapon_in_inv
   sw    $v1, 0x80($sp)
  beqz  $v0, .L7F050AF0
   lw    $v1, 0x80($sp)
  lb    $a0, 0x80($v1)
  jal   get_ammo_type_for_weapon
   sw    $v1, 0x80($sp)
  beqz  $v0, .L7F050AF0
   lw    $v1, 0x80($sp)
  lb    $a0, 0x80($v1)
  jal   get_ammo_count_for_weapon
   sw    $v1, 0x80($sp)
  lw    $v1, 0x80($sp)
  lb    $a0, 0x80($v1)
  jal   get_max_ammo_for_weapon
   sw    $v0, 0x38($sp)
  lw    $a2, 0x38($sp)
  lw    $v1, 0x80($sp)
  slt   $at, $a2, $v0
  bnez  $at, .L7F050AF0
   nop   
  lw    $v0, 0x84($v1)
  bnez  $v0, .L7F0508E4
   nop   
  lb    $t6, 0x81($v1)
  bltz  $t6, .L7F050934
   nop   
.L7F0508E4:
  beql  $v0, $zero, .L7F0508FC
   lb    $a1, 0x81($v1)
  lb    $a1, 0x80($v0)
  b     .L7F050900
   move  $a0, $a1
  lb    $a1, 0x81($v1)
.L7F0508FC:
  move  $a0, $a1
.L7F050900:
  lw    $t7, 8($v1)
  sll   $t8, $t7, 3
  bgezl $t8, .L7F05091C
   lb    $a0, 0x80($v1)
  b     .L7F05091C
   lb    $a1, 0x80($v1)
  lb    $a0, 0x80($v1)
.L7F05091C:
  jal   is_item_for_hand_in_inventory
   nop   
  beqz  $v0, .L7F050AF0
   nop   
  b     .L7F050D20
   move  $v0, $zero
.L7F050934:
  b     .L7F050D20
   move  $v0, $zero
  li    $at, 7
.L7F050940:
  bne   $v0, $at, .L7F050980
   lw    $t9, 0x88($sp)
  lw    $v1, 4($t9)
  lw    $a0, 0x80($v1)
  jal   check_cur_player_ammo_amount_in_inventory
   sw    $v1, 0x74($sp)
  lw    $v1, 0x74($sp)
  lw    $a0, 0x80($v1)
  jal   get_max_ammo_for_type
   sw    $v0, 0x38($sp)
  lw    $a2, 0x38($sp)
  slt   $at, $a2, $v0
  bnez  $at, .L7F050AF0
   nop   
  b     .L7F050D20
   move  $v0, $zero
.L7F050980:
  li    $at, 20
  bne   $v0, $at, .L7F050A38
   lw    $t1, 0x88($sp)
  lw    $t2, 4($t1)
  li    $t3, 1
  sw    $t3, 0x6c($sp)
  move  $a0, $a1
  jal   do_something_if_object_destroyed
   sw    $t2, 0x70($sp)
  beqz  $v0, .L7F0509B4
   lw    $v1, 0x70($sp)
  b     .L7F050D20
   move  $v0, $zero
.L7F0509B4:
  move  $v0, $zero
.L7F0509B8:
  addiu $a1, $v0, 1
  li    $at, 1
  bne   $v0, $at, .L7F0509CC
   move  $a0, $a1
  li    $a0, 1
.L7F0509CC:
  lhu   $t4, 0x82($v1)
  blezl $t4, .L7F050A18
   li    $at, 13
  sw    $v1, 0x30($sp)
  sw    $a0, 0x64($sp)
  jal   check_cur_player_ammo_amount_in_inventory
   sw    $a1, 0x34($sp)
  lw    $a0, 0x64($sp)
  jal   get_max_ammo_for_type
   sw    $v0, 0x38($sp)
  lw    $a2, 0x38($sp)
  lw    $v1, 0x30($sp)
  lw    $a1, 0x34($sp)
  slt   $at, $a2, $v0
  beql  $at, $zero, .L7F050A18
   li    $at, 13
  b     .L7F050A24
   sw    $zero, 0x6c($sp)
  li    $at, 13
.L7F050A18:
  move  $v0, $a1
  bne   $a1, $at, .L7F0509B8
   addiu $v1, $v1, 4
.L7F050A24:
  lw    $t5, 0x6c($sp)
  beqz  $t5, .L7F050AF0
   nop   
  b     .L7F050D20
   move  $v0, $zero
.L7F050A38:
  li    $at, 21
  bne   $v0, $at, .L7F050AF0
   lw    $t6, 0x88($sp)
  lw    $t7, 4($t6)
  sw    $zero, 0x5c($sp)
  jal   get_BONDdata_watch_armor
   sw    $t7, 0x60($sp)
  lw    $t8, 0x60($sp)
  li    $t9, 1
  lwc1  $f4, 0x84($t8)
  c.le.s $f4, $f0
  nop   
  bc1f  .L7F050A78
   nop   
  b     .L7F050ADC
   sw    $t9, 0x5c($sp)
.L7F050A78:
  jal   getPlayerCount
   nop   
  slti  $at, $v0, 2
  bnezl $at, .L7F050AE0
   lw    $t3, 0x5c($sp)
  jal   get_scenario
   nop   
  li    $at, 2
  bne   $v0, $at, .L7F050ABC
   move  $v1, $v0
  jal   bondinvIsAliveWithFlag
   sw    $v0, 0x58($sp)
  beqz  $v0, .L7F050ABC
   lw    $v1, 0x58($sp)
  li    $t1, 1
  b     .L7F050ADC
   sw    $t1, 0x5c($sp)
.L7F050ABC:
  li    $at, 3
  bnel  $v1, $at, .L7F050AE0
   lw    $t3, 0x5c($sp)
  jal   checkforgoldengun
   nop   
  beqz  $v0, .L7F050ADC
   li    $t2, 1
  sw    $t2, 0x5c($sp)
.L7F050ADC:
  lw    $t3, 0x5c($sp)
.L7F050AE0:
  beqz  $t3, .L7F050AF0
   nop   
  b     .L7F050D20
   move  $v0, $zero
.L7F050AF0:
  jal   get_curplay_vertical_rotation_in_degrees
   nop   
  lui   $at, %hi(D_800532E0)
  lwc1  $f6, %lo(D_800532E0)($at)
  lui   $t4, %hi(pPlayer) 
  c.lt.s $f0, $f6
  nop   
  bc1f  .L7F050B2C
   nop   
  lw    $t4, %lo(pPlayer)($t4)
  lw    $t5, 0x1270($t4)
  bgez  $t5, .L7F050B2C
   nop   
  b     .L7F050D20
   move  $v0, $zero
.L7F050B2C:
  jal   get_curplayer_positiondata
   nop   
  lui   $t7, %hi(pPlayer) 
  lw    $t6, 0x84($sp)
  lw    $t7, %lo(pPlayer)($t7)
  lwc1  $f10, 8($v0)
  lwc1  $f18, 0xc($v0)
  lw    $t8, 0x1270($t7)
  lwc1  $f6, 0x10($v0)
  lwc1  $f8, 0x58($t6)
  lwc1  $f16, 0x5c($t6)
  lwc1  $f4, 0x60($t6)
  slti  $at, $t8, 0x3c
  move  $t0, $v0
  sub.s $f0, $f8, $f10
  sub.s $f12, $f16, $f18
  bnez  $at, .L7F050BF8
   sub.s $f2, $f4, $f6
  mul.s $f8, $f0, $f0
  lui   $at, %hi(D_800532E4)
  lwc1  $f18, %lo(D_800532E4)($at)
  mul.s $f10, $f2, $f2
  li    $at, 0xC3FA0000 # -500.000000
  move  $v0, $zero
  add.s $f16, $f8, $f10
  c.le.s $f16, $f18
  nop   
  bc1f  .L7F050BA4
   nop   
  li    $v0, 1
.L7F050BA4:
  beqz  $v0, .L7F050BF0
   move  $a2, $v0
  mtc1  $at, $f4
  li    $at, 0x43FA0000 # 500.000000
  move  $v0, $zero
  c.le.s $f4, $f12
  nop   
  bc1f  .L7F050BCC
   nop   
  li    $v0, 1
.L7F050BCC:
  beqz  $v0, .L7F050BF0
   move  $a2, $v0
  mtc1  $at, $f6
  move  $a2, $zero
  c.le.s $f12, $f6
  nop   
  bc1f  .L7F050BF0
   nop   
  li    $a2, 1
.L7F050BF0:
  b     .L7F050C78
   move  $v1, $a2
.L7F050BF8:
  mul.s $f8, $f0, $f0
  lui   $at, %hi(D_800532E8)
  lwc1  $f16, %lo(D_800532E8)($at)
  mul.s $f10, $f2, $f2
  li    $at, 0xC3480000 # -200.000000
  move  $v0, $zero
  add.s $f18, $f8, $f10
  c.le.s $f18, $f16
  nop   
  bc1f  .L7F050C28
   nop   
  li    $v0, 1
.L7F050C28:
  beqz  $v0, .L7F050C74
   move  $a2, $v0
  mtc1  $at, $f4
  li    $at, 0x43480000 # 200.000000
  move  $v0, $zero
  c.le.s $f4, $f12
  nop   
  bc1f  .L7F050C50
   nop   
  li    $v0, 1
.L7F050C50:
  beqz  $v0, .L7F050C74
   move  $a2, $v0
  mtc1  $at, $f6
  move  $a2, $zero
  c.le.s $f12, $f6
  nop   
  bc1fl .L7F050C78
   move  $v1, $a2
  li    $a2, 1
.L7F050C74:
  move  $v1, $a2
.L7F050C78:
  beqz  $a2, .L7F050D04
   lw    $t9, 0x84($sp)
  lw    $t1, 0xc($t9)
  lw    $v0, 0x88($sp)
  li    $at, 0x41F00000 # 30.000000
  andi  $t2, $t1, 0x1000
  bnez  $t2, .L7F050D04
   addiu $a0, $sp, 0x3c
  lw    $t3, 0x14($t0)
  mtc1  $at, $f0
  li    $at, 0x3F800000 # 1.000000
  sw    $t3, 0x3c($sp)
  lwc1  $f8, 0x10($v0)
  lw    $a3, 8($v0)
  lw    $a2, 0x10($t0)
  lw    $a1, 8($t0)
  mtc1  $at, $f16
  mtc1  $zero, $f10
  li    $t4, 2
  sw    $t4, 0x14($sp)
  sw    $v1, 0x40($sp)
  swc1  $f0, 0x1c($sp)
  swc1  $f0, 0x18($sp)
  swc1  $f8, 0x10($sp)
  swc1  $f16, 0x24($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f10, 0x20($sp)
  beqz  $v0, .L7F050D00
   lw    $v1, 0x40($sp)
  lw    $t6, 0x88($sp)
  lw    $t5, 0x3c($sp)
  lw    $t7, 0x14($t6)
  beq   $t5, $t7, .L7F050D04
   nop   
.L7F050D00:
  move  $v1, $zero
.L7F050D04:
  beqz  $v1, .L7F050D20
   move  $v0, $zero
  lw    $a0, 0x88($sp)
  jal   collect_or_interact_object
   li    $a1, 1
  b     .L7F050D24
   lw    $ra, 0x2c($sp)
.L7F050D20:
  lw    $ra, 0x2c($sp)
.L7F050D24:
  addiu $sp, $sp, 0x88
  jr    $ra
   nop   
");

#ifdef VERSION_JP
asm(R"
.late_rodata
glabel D_800532E0
.word 0xbf490fdb /*-0.78539819*/
glabel D_800532E4
.word 0x47ef4200 /*122500.0*/
glabel D_800532E8
.word 0x461c4000 /*10000.0*/
glabel D_800532EC
.word 0x47742400 /*62500.0*/
glabel D_800532F0
.word 0x40490fdb /*3.1415927*/
.text
glabel object_collectability_routines
  addiu $sp, $sp, -0x90
  sw    $ra, 0x34($sp)
  sw    $s0, 0x30($sp)
  sw    $a0, 0x90($sp)
  lw    $a0, 4($a0)
  jal   check_if_collectable_object
   sw    $a0, 0x8c($sp)
  beqz  $v0, .Ljp7F050B2C
   lw    $a0, 0x8c($sp)
  lbu   $t7, 3($a0)
  li    $at, 17
  beql  $t7, $at, .Ljp7F050B30
   lw    $a0, 0x8c($sp)
  lw    $v0, 8($a0)
  sll   $t8, $v0, 0xb
  bgezl $t8, .Ljp7F050B4C
   sll   $t1, $v0, 0xc
  b     .Ljp7F051218
   move  $v0, $zero
.Ljp7F050B2C:
  lw    $a0, 0x8c($sp)
.Ljp7F050B30:
  lw    $v0, 8($a0)
  sll   $t9, $v0, 0xd
  bltzl $t9, .Ljp7F050B4C
   sll   $t1, $v0, 0xc
  b     .Ljp7F051218
   move  $v0, $zero
  sll   $t1, $v0, 0xc
.Ljp7F050B4C:
  bgezl $t1, .Ljp7F050B60
   lw    $t2, 0x64($a0)
  b     .Ljp7F051218
   move  $v0, $zero
  lw    $t2, 0x64($a0)
.Ljp7F050B60:
  andi  $t3, $t2, 0x80
  beqz  $t3, .Ljp7F050B90
   nop   
  lw    $v0, 0x6c($a0)
  lw    $t4, 0xbc($v0)
  blez  $t4, .Ljp7F050B90
   nop   
  lw    $t5, 0x90($v0)
  bnez  $t5, .Ljp7F050B90
   nop   
  b     .Ljp7F051218
   move  $v0, $zero
.Ljp7F050B90:
  jal   sub_GAME_7F03E7AC
   nop   
  bnez  $v0, .Ljp7F050BA8
   lw    $a1, 0x8c($sp)
  b     .Ljp7F051218
   move  $v0, $zero
.Ljp7F050BA8:
  lbu   $v0, 3($a1)
  li    $at, 8
  lw    $t6, 0x90($sp)
  bnel  $v0, $at, .Ljp7F050D38
   li    $at, 7
  lw    $s0, 4($t6)
  li    $at, 26
  lb    $a0, 0x80($s0)
  beq   $a0, $at, .Ljp7F050BD8
   li    $at, 87
  bnel  $a0, $at, .Ljp7F050C00
   li    $at, 29
.Ljp7F050BD8:
  lh    $t7, 0x82($s0)
  bgez  $t7, .Ljp7F050BF4
   nop   
  lw    $t8, 0x64($a1)
  andi  $t9, $t8, 4
  beql  $t9, $zero, .Ljp7F050C00
   li    $at, 29
.Ljp7F050BF4:
  b     .Ljp7F051218
   move  $v0, $zero
  li    $at, 29
.Ljp7F050C00:
  beq   $a0, $at, .Ljp7F050C38
   li    $at, 28
  beq   $a0, $at, .Ljp7F050C38
   li    $at, 27
  beq   $a0, $at, .Ljp7F050C38
   li    $at, 33
  beq   $a0, $at, .Ljp7F050C38
   li    $at, 47
  beq   $a0, $at, .Ljp7F050C38
   li    $at, 48
  beq   $a0, $at, .Ljp7F050C38
   li    $at, 34
  bnel  $a0, $at, .Ljp7F050C60
   li    $at, 86
.Ljp7F050C38:
  lh    $t1, 0x82($s0)
  bgez  $t1, .Ljp7F050C54
   nop   
  lw    $t2, 0x64($a1)
  andi  $t3, $t2, 4
  beql  $t3, $zero, .Ljp7F050C60
   li    $at, 86
.Ljp7F050C54:
  b     .Ljp7F051218
   move  $v0, $zero
  li    $at, 86
.Ljp7F050C60:
  bne   $a0, $at, .Ljp7F050C80
   nop   
  lw    $t4, 0x64($a1)
  andi  $t5, $t4, 0x80
  beqz  $t5, .Ljp7F050C80
   nop   
  b     .Ljp7F051218
   move  $v0, $zero
.Ljp7F050C80:
  jal   is_weapon_in_inv
   nop   
  beqz  $v0, .Ljp7F050FF0
   nop   
  jal   get_ammo_type_for_weapon
   lb    $a0, 0x80($s0)
  beqz  $v0, .Ljp7F050FF0
   nop   
  jal   get_ammo_count_for_weapon
   lb    $a0, 0x80($s0)
  lb    $a0, 0x80($s0)
  jal   get_max_ammo_for_weapon
   sw    $v0, 0x40($sp)
  lw    $v1, 0x40($sp)
  slt   $at, $v1, $v0
  bnez  $at, .Ljp7F050FF0
   nop   
  lw    $v0, 0x84($s0)
  bnez  $v0, .Ljp7F050CDC
   nop   
  lb    $t6, 0x81($s0)
  bltz  $t6, .Ljp7F050D2C
   nop   
.Ljp7F050CDC:
  beql  $v0, $zero, .Ljp7F050CF4
   lb    $a1, 0x81($s0)
  lb    $a1, 0x80($v0)
  b     .Ljp7F050CF8
   move  $a0, $a1
  lb    $a1, 0x81($s0)
.Ljp7F050CF4:
  move  $a0, $a1
.Ljp7F050CF8:
  lw    $t7, 8($s0)
  sll   $t8, $t7, 3
  bgezl $t8, .Ljp7F050D14
   lb    $a0, 0x80($s0)
  b     .Ljp7F050D14
   lb    $a1, 0x80($s0)
  lb    $a0, 0x80($s0)
.Ljp7F050D14:
  jal   is_item_for_hand_in_inventory
   nop   
  beqz  $v0, .Ljp7F050FF0
   nop   
  b     .Ljp7F051218
   move  $v0, $zero
.Ljp7F050D2C:
  b     .Ljp7F051218
   move  $v0, $zero
  li    $at, 7
.Ljp7F050D38:
  bne   $v0, $at, .Ljp7F050E10
   lw    $t9, 0x90($sp)
  lw    $s0, 4($t9)
  jal   check_cur_player_ammo_amount_in_inventory
   lw    $a0, 0x80($s0)
  lw    $a0, 0x80($s0)
  jal   get_max_ammo_for_type
   sw    $v0, 0x40($sp)
  lw    $v1, 0x40($sp)
  slt   $at, $v1, $v0
  bnez  $at, .Ljp7F050FF0
   nop   
  lw    $v0, 0x80($s0)
  li    $at, 5
  bnel  $v0, $at, .Ljp7F050D90
   li    $at, 7
  jal   is_weapon_in_inv
   li    $a0, 26
  beqz  $v0, .Ljp7F050FF0
   nop   
  lw    $v0, 0x80($s0)
  li    $at, 7
.Ljp7F050D90:
  bnel  $v0, $at, .Ljp7F050DB0
   li    $at, 8
  jal   is_weapon_in_inv
   li    $a0, 29
  beqz  $v0, .Ljp7F050FF0
   nop   
  lw    $v0, 0x80($s0)
  li    $at, 8
.Ljp7F050DB0:
  bnel  $v0, $at, .Ljp7F050DD0
   li    $at, 9
  jal   is_weapon_in_inv
   li    $a0, 28
  beqz  $v0, .Ljp7F050FF0
   nop   
  lw    $v0, 0x80($s0)
  li    $at, 9
.Ljp7F050DD0:
  bnel  $v0, $at, .Ljp7F050DF0
   li    $at, 10
  jal   is_weapon_in_inv
   li    $a0, 27
  beqz  $v0, .Ljp7F050FF0
   nop   
  lw    $v0, 0x80($s0)
  li    $at, 10
.Ljp7F050DF0:
  bne   $v0, $at, .Ljp7F050E08
   nop   
  jal   is_weapon_in_inv
   li    $a0, 3
  beqz  $v0, .Ljp7F050FF0
   nop   
.Ljp7F050E08:
  b     .Ljp7F051218
   move  $v0, $zero
.Ljp7F050E10:
  li    $at, 20
  bne   $v0, $at, .Ljp7F050F44
   lw    $t1, 0x90($sp)
  lw    $s0, 4($t1)
  li    $t2, 1
  sw    $t2, 0x74($sp)
  jal   do_something_if_object_destroyed
   move  $a0, $a1
  beqz  $v0, .Ljp7F050E40
   move  $v1, $s0
  b     .Ljp7F051218
   move  $v0, $zero
.Ljp7F050E40:
  move  $v0, $zero
.Ljp7F050E44:
  addiu $s0, $v0, 1
  li    $at, 1
  bne   $v0, $at, .Ljp7F050E58
   sw    $s0, 0x3c($sp)
  li    $s0, 1
.Ljp7F050E58:
  sw    $v1, 0x38($sp)
  lhu   $t4, 0x82($v1)
  move  $a0, $s0
  blezl $t4, .Ljp7F050F20
   lw    $v0, 0x3c($sp)
  jal   check_cur_player_ammo_amount_in_inventory
   sw    $v1, 0x38($sp)
  move  $a0, $s0
  jal   get_max_ammo_for_type
   sw    $v0, 0x40($sp)
  lw    $v1, 0x40($sp)
  slt   $at, $v1, $v0
  beql  $at, $zero, .Ljp7F050E9C
   li    $at, 5
  b     .Ljp7F050F30
   sw    $zero, 0x74($sp)
  li    $at, 5
.Ljp7F050E9C:
  bnel  $s0, $at, .Ljp7F050EB4
   li    $at, 7
  jal   is_weapon_in_inv
   li    $a0, 26
  beqz  $v0, .Ljp7F050F14
   li    $at, 7
.Ljp7F050EB4:
  bnel  $s0, $at, .Ljp7F050ECC
   li    $at, 8
  jal   is_weapon_in_inv
   li    $a0, 29
  beqz  $v0, .Ljp7F050F14
   li    $at, 8
.Ljp7F050ECC:
  bnel  $s0, $at, .Ljp7F050EE4
   li    $at, 9
  jal   is_weapon_in_inv
   li    $a0, 28
  beqz  $v0, .Ljp7F050F14
   li    $at, 9
.Ljp7F050EE4:
  bnel  $s0, $at, .Ljp7F050EFC
   li    $at, 10
  jal   is_weapon_in_inv
   li    $a0, 27
  beqz  $v0, .Ljp7F050F14
   li    $at, 10
.Ljp7F050EFC:
  bnel  $s0, $at, .Ljp7F050F20
   lw    $v0, 0x3c($sp)
  jal   is_weapon_in_inv
   li    $a0, 3
  bnezl $v0, .Ljp7F050F20
   lw    $v0, 0x3c($sp)
.Ljp7F050F14:
  b     .Ljp7F050F30
   sw    $zero, 0x74($sp)
  lw    $v0, 0x3c($sp)
.Ljp7F050F20:
  lw    $v1, 0x38($sp)
  li    $at, 13
  bne   $v0, $at, .Ljp7F050E44
   addiu $v1, $v1, 4
.Ljp7F050F30:
  lw    $t5, 0x74($sp)
  beqz  $t5, .Ljp7F050FF0
   nop   
  b     .Ljp7F051218
   move  $v0, $zero
.Ljp7F050F44:
  li    $at, 21
  bne   $v0, $at, .Ljp7F050FF0
   lw    $t6, 0x90($sp)
  lw    $s0, 4($t6)
  jal   get_BONDdata_watch_armor
   sw    $zero, 0x64($sp)
  lwc1  $f4, 0x84($s0)
  li    $t7, 1
  c.le.s $f4, $f0
  nop   
  bc1f  .Ljp7F050F7C
   nop   
  b     .Ljp7F050FDC
   sw    $t7, 0x64($sp)
.Ljp7F050F7C:
  jal   getPlayerCount
   nop   
  slti  $at, $v0, 2
  bnezl $at, .Ljp7F050FE0
   lw    $t1, 0x64($sp)
  jal   get_scenario
   nop   
  li    $at, 2
  bne   $v0, $at, .Ljp7F050FBC
   move  $s0, $v0
  jal   bondinvIsAliveWithFlag
   nop   
  beqz  $v0, .Ljp7F050FBC
   li    $t8, 1
  b     .Ljp7F050FDC
   sw    $t8, 0x64($sp)
.Ljp7F050FBC:
  li    $at, 3
  bnel  $s0, $at, .Ljp7F050FE0
   lw    $t1, 0x64($sp)
  jal   checkforgoldengun
   nop   
  beqz  $v0, .Ljp7F050FDC
   li    $t9, 1
  sw    $t9, 0x64($sp)
.Ljp7F050FDC:
  lw    $t1, 0x64($sp)
.Ljp7F050FE0:
  beqz  $t1, .Ljp7F050FF0
   nop   
  b     .Ljp7F051218
   move  $v0, $zero
.Ljp7F050FF0:
  jal   get_curplay_vertical_rotation_in_degrees
   nop   
  lui   $at, %hi(D_800532E0) # $at, 0x8005
  lwc1  $f6, %lo(D_800532E0)($at)
  lui   $t2, %hi(pPlayer) # $t2, 0x8008
  c.lt.s $f0, $f6
  nop   
  bc1f  .Ljp7F05102C
   nop   
  lw    $t2, %lo(pPlayer)($t2)
  lw    $t3, 0x1270($t2)
  bgez  $t3, .Ljp7F05102C
   nop   
  b     .Ljp7F051218
   move  $v0, $zero
.Ljp7F05102C:
  jal   get_curplayer_positiondata
   nop   
  lui   $t5, %hi(pPlayer) # $t5, 0x8008
  lw    $t4, 0x8c($sp)
  lw    $t5, %lo(pPlayer)($t5)
  lwc1  $f10, 8($v0)
  lwc1  $f18, 0xc($v0)
  lw    $t6, 0x1270($t5)
  lwc1  $f6, 0x10($v0)
  lwc1  $f8, 0x58($t4)
  lwc1  $f16, 0x5c($t4)
  lwc1  $f4, 0x60($t4)
  slti  $at, $t6, 0x3c
  move  $t0, $v0
  sub.s $f0, $f8, $f10
  sub.s $f12, $f16, $f18
  bnez  $at, .Ljp7F0510F8
   sub.s $f2, $f4, $f6
  mul.s $f8, $f0, $f0
  lui   $at, %hi(D_800532E4) # $at, 0x8005
  lwc1  $f18, %lo(D_800532E4)($at)
  mul.s $f10, $f2, $f2
  li    $at, 0xC3FA0000 # -500.000000
  move  $v0, $zero
  add.s $f16, $f8, $f10
  c.le.s $f16, $f18
  nop   
  bc1f  .Ljp7F0510A4
   nop   
  li    $v0, 1
.Ljp7F0510A4:
  beqz  $v0, .Ljp7F0510F0
   move  $v1, $v0
  mtc1  $at, $f4
  li    $at, 0x43FA0000 # 500.000000
  move  $v0, $zero
  c.le.s $f4, $f12
  nop   
  bc1f  .Ljp7F0510CC
   nop   
  li    $v0, 1
.Ljp7F0510CC:
  beqz  $v0, .Ljp7F0510F0
   move  $v1, $v0
  mtc1  $at, $f6
  move  $v1, $zero
  c.le.s $f12, $f6
  nop   
  bc1f  .Ljp7F0510F0
   nop   
  li    $v1, 1
.Ljp7F0510F0:
  b     .Ljp7F051178
   move  $s0, $v1
.Ljp7F0510F8:
  mul.s $f8, $f0, $f0
  lui   $at, %hi(D_800532E8) # $at, 0x8005
  lwc1  $f16, %lo(D_800532E8)($at)
  mul.s $f10, $f2, $f2
  li    $at, 0xC3480000 # -200.000000
  move  $v0, $zero
  add.s $f18, $f8, $f10
  c.le.s $f18, $f16
  nop   
  bc1f  .Ljp7F051128
   nop   
  li    $v0, 1
.Ljp7F051128:
  beqz  $v0, .Ljp7F051174
   move  $v1, $v0
  mtc1  $at, $f4
  li    $at, 0x43480000 # 200.000000
  move  $v0, $zero
  c.le.s $f4, $f12
  nop   
  bc1f  .Ljp7F051150
   nop   
  li    $v0, 1
.Ljp7F051150:
  beqz  $v0, .Ljp7F051174
   move  $v1, $v0
  mtc1  $at, $f6
  move  $v1, $zero
  c.le.s $f12, $f6
  nop   
  bc1fl .Ljp7F051178
   move  $s0, $v1
  li    $v1, 1
.Ljp7F051174:
  move  $s0, $v1
.Ljp7F051178:
  beqz  $v1, .Ljp7F0511FC
   lw    $t7, 0x8c($sp)
  lw    $t8, 0xc($t7)
  lw    $v0, 0x90($sp)
  li    $at, 0x41F00000 # 30.000000
  andi  $t9, $t8, 0x1000
  bnez  $t9, .Ljp7F0511FC
   addiu $a0, $sp, 0x44
  lw    $t1, 0x14($t0)
  mtc1  $at, $f0
  li    $at, 0x3F800000 # 1.000000
  sw    $t1, 0x44($sp)
  lwc1  $f8, 0x10($v0)
  lw    $a3, 8($v0)
  lw    $a2, 0x10($t0)
  lw    $a1, 8($t0)
  mtc1  $at, $f16
  mtc1  $zero, $f10
  li    $t2, 2
  sw    $t2, 0x14($sp)
  swc1  $f0, 0x1c($sp)
  swc1  $f0, 0x18($sp)
  swc1  $f8, 0x10($sp)
  swc1  $f16, 0x24($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f10, 0x20($sp)
  beqz  $v0, .Ljp7F0511F8
   lw    $t4, 0x90($sp)
  lw    $t3, 0x44($sp)
  lw    $t5, 0x14($t4)
  beq   $t3, $t5, .Ljp7F0511FC
   nop   
.Ljp7F0511F8:
  move  $s0, $zero
.Ljp7F0511FC:
  beqz  $s0, .Ljp7F051218
   move  $v0, $zero
  lw    $a0, 0x90($sp)
  jal   collect_or_interact_object
   li    $a1, 1
  b     .Ljp7F05121C
   lw    $ra, 0x34($sp)
.Ljp7F051218:
  lw    $ra, 0x34($sp)
.Ljp7F05121C:
  lw    $s0, 0x30($sp)
  addiu $sp, $sp, 0x90
  jr    $ra
   nop   
");
#endif

#endif

asm(R"
glabel sub_GAME_7F050D30
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  sw    $a0, 0x28($sp)
  sw    $a1, 0x2c($sp)
  sw    $a3, 0x34($sp)
  lbu   $t7, 1($a0)
  andi  $t8, $t7, 2
  beql  $t8, $zero, .L7F050DD8
   move  $v0, $zero
  lw    $v1, 4($a0)
  lw    $a0, 0x14($v1)
  sw    $a2, 0x30($sp)
  jal   getsubmatrix
   sw    $v1, 0x24($sp)
  lw    $t1, 0x2c($sp)
  lwc1  $f4, 0x38($v0)
  lw    $v1, 0x24($sp)
  lw    $a2, 0x30($sp)
  lw    $t2, 0x34($sp)
  swc1  $f4, 8($t1)
  mtc1  $zero, $f0
  lwc1  $f6, 8($t1)
  c.lt.s $f6, $f0
  nop   
  bc1fl .L7F050DD8
   move  $v0, $zero
  lwc1  $f8, 0x30($v0)
  addiu $a1, $a2, 4
  addiu $a3, $t2, 4
  swc1  $f8, ($t1)
  lwc1  $f10, 0x34($v0)
  swc1  $f10, 4($t1)
  swc1  $f0, ($t2)
  swc1  $f0, 4($t2)
  swc1  $f0, ($a2)
  swc1  $f0, 4($a2)
  lw    $a0, 0x14($v1)
  jal   sub_GAME_7F03F90C
   sw    $t2, 0x10($sp)
  b     .L7F050DD8
   li    $v0, 1
  move  $v0, $zero
.L7F050DD8:
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F050DE8
  addiu $sp, $sp, -0x40
  sw    $ra, 0x3c($sp)
  sw    $fp, 0x38($sp)
  sw    $s7, 0x34($sp)
  sw    $s6, 0x30($sp)
  sw    $s5, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  lw    $s4, 8($a0)
  move  $s3, $a0
  li    $s5, 8
  lw    $s0, ($s4)
  li    $s6, 18
  li    $s7, 23
  beqz  $s0, .L7F050F20
   li    $fp, 24
  lhu   $v0, ($s0)
.L7F050E38:
  move  $a0, $s3
  andi  $t6, $v0, 0xff
  beq   $t6, $s5, .L7F050EB4
   nop   
  beq   $t6, $s6, .L7F050EC4
   move  $a0, $s3
  beq   $t6, $s7, .L7F050ED4
   move  $a0, $s3
  beq   $t6, $fp, .L7F050E68
   move  $a0, $s3
  b     .L7F050EE0
   lw    $v0, 0x14($s0)
.L7F050E68:
  lw    $s2, 4($s0)
  jal   extract_id_from_object_structure_microcode
   move  $a1, $s0
  lw    $t7, 8($s2)
  lw    $t8, ($v0)
  move  $s1, $v0
  move  $a0, $s4
  beq   $t7, $t8, .L7F050EAC
   nop   
  jal   sub_GAME_7F04B590
   move  $a1, $s0
  beqz  $v0, .L7F050EAC
   nop   
  jal   sub_GAME_7F09C044
   lw    $a0, ($s1)
  lw    $t9, 8($s2)
  sw    $t9, ($s1)
.L7F050EAC:
  b     .L7F050EE0
   lw    $v0, 0x14($s0)
.L7F050EB4:
  jal   sub_GAME_7F06E970
   move  $a1, $s0
  b     .L7F050EE0
   lw    $v0, 0x14($s0)
.L7F050EC4:
  jal   process_12_handle_switch
   move  $a1, $s0
  b     .L7F050EE0
   lw    $v0, 0x14($s0)
.L7F050ED4:
  jal   process_17_pointer_to_head
   move  $a1, $s0
  lw    $v0, 0x14($s0)
.L7F050EE0:
  beqz  $v0, .L7F050EF0
   nop   
  b     .L7F050F18
   move  $s0, $v0
.L7F050EF0:
  beqz  $s0, .L7F050F18
   nop   
  lw    $v0, 0xc($s0)
.L7F050EFC:
  beql  $v0, $zero, .L7F050F10
   lw    $s0, 8($s0)
  b     .L7F050F18
   move  $s0, $v0
  lw    $s0, 8($s0)
.L7F050F10:
  bnezl $s0, .L7F050EFC
   lw    $v0, 0xc($s0)
.L7F050F18:
  bnezl $s0, .L7F050E38
   lhu   $v0, ($s0)
.L7F050F20:
  lw    $ra, 0x3c($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  lw    $s3, 0x24($sp)
  lw    $s4, 0x28($sp)
  lw    $s5, 0x2c($sp)
  lw    $s6, 0x30($sp)
  lw    $s7, 0x34($sp)
  lw    $fp, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x40
");

asm(R"
glabel sub_GAME_7F050F50
  addiu $sp, $sp, -0x20
  sw    $a1, 0x24($sp)
  sw    $a2, 0x28($sp)
  move  $a1, $a2
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x14($sp)
  move  $a2, $a3
  move  $s0, $a0
  sw    $s1, 0x18($sp)
  jal   init_standard_object
   lw    $a3, 0x30($sp)
  beqz  $v0, .L7F051010
   move  $s1, $v0
  lw    $a0, 0x14($s0)
  beql  $a0, $zero, .L7F051014
   lw    $ra, 0x1c($sp)
  lhu   $t6, ($s0)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t6, $f4
  bgez  $t6, .L7F050FB0
   cvt.s.w $f6, $f4
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F050FB0:
  li    $at, 0x3B800000 # 0.003906
  mtc1  $at, $f10
  lwc1  $f16, 0x14($a0)
  mul.s $f0, $f6, $f10
  nop   
  mul.s $f18, $f16, $f0
  mfc1  $a1, $f18
  jal   set_obj_instance_controller_scale
   nop   
  lw    $v0, 0x24($sp)
  lw    $t8, 0x14($s0)
  move  $a0, $s1
  lw    $t7, 0x1c($v0)
  sw    $t7, 0x18($t8)
  lw    $t9, 0x1c($v0)
  lw    $t3, 0x14($s0)
  lw    $t0, 8($t9)
  lw    $t1, 8($t0)
  lw    $t2, 0x18($t1)
  sw    $t2, 0x1c($t3)
  jal   sub_GAME_7F03A5A4
   lw    $a1, 0x18($v0)
  lw    $t4, 0x24($sp)
  sw    $s1, 0x1d8($t4)
.L7F051010:
  lw    $ra, 0x1c($sp)
.L7F051014:
  move  $v0, $s1
  lw    $s1, 0x18($sp)
  lw    $s0, 0x14($sp)
  jr    $ra
   addiu $sp, $sp, 0x20
");

asm(R"
glabel sub_GAME_7F051028
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  sw    $a0, 0x28($sp)
  sw    $a1, 0x2c($sp)
  lh    $a0, 4($a0)
  jal   load_model
   sw    $a0, 0x20($sp)
  lw    $t7, 0x20($sp)
  lui   $a2, %hi(PitemZ_entries)
  lw    $a0, 0x28($sp)
  sll   $t8, $t7, 2
  subu  $t8, $t8, $t7
  sll   $t8, $t8, 2
  addu  $a2, $a2, $t8
  lw    $a2, %lo(PitemZ_entries)($a2)
  lw    $a1, 0x2c($sp)
  move  $a3, $zero
  jal   sub_GAME_7F050F50
   sw    $zero, 0x10($sp)
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F051084
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lw    $t6, 0x74($a0)
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f8
  mtc1  $t6, $f4
  nop   
  cvt.s.w $f6, $f4
  div.s $f10, $f6, $f8
  jal   sub_GAME_7F051028
   swc1  $f10, 0x74($a0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0510C0
  addiu $sp, $sp, -0xc0
  sll   $t6, $a1, 2
  subu  $t6, $t6, $a1
  sll   $t6, $t6, 2
  lui   $t7, %hi(PitemZ_entries)
  addu  $t7, $t7, $t6
  lw    $t7, %lo(PitemZ_entries)($t7)
  sw    $ra, 0x2c($sp)
  sw    $a0, 0xc0($sp)
  sw    $s2, 0x28($sp)
  sw    $s1, 0x24($sp)
  sw    $s0, 0x20($sp)
  sw    $a2, 0xc8($sp)
  move  $a0, $a1
  sw    $a1, 0xc4($sp)
  jal   load_model
   sw    $t7, 0xbc($sp)
  jal   remove_last_obj_pos_data_entry
   nop   
  move  $s0, $v0
  jal   get_obj_instance_controller_for_header
   lw    $a0, 0xbc($sp)
  move  $s1, $v0
  sltiu $a0, $s0, 1
  sltiu $a1, $v0, 1
  jal   sub_GAME_7F0515B0
   lw    $a2, 0xbc($sp)
  bnez  $s0, .L7F051140
   move  $s2, $v0
  jal   remove_last_obj_pos_data_entry
   nop   
  move  $s0, $v0
.L7F051140:
  bnez  $s1, .L7F051154
   nop   
  jal   get_obj_instance_controller_for_header
   lw    $a0, 0xbc($sp)
  move  $s1, $v0
.L7F051154:
  beqz  $s2, .L7F05122C
   nop   
  beqz  $s0, .L7F05122C
   nop   
  beqz  $s1, .L7F05122C
   addiu $v0, $sp, 0x30
  lui   $t8, %hi(blank_11_object) 
  addiu $t8, %lo(blank_11_object) # addiu $t8, $t8, 0x2114
  lw    $a1, 0xc0($sp)
  addiu $t0, $t8, 0x78
  move  $t1, $v0
.L7F051180:
  lw    $at, ($t8)
  addiu $t8, $t8, 0xc
  addiu $t1, $t1, 0xc
  sw    $at, -0xc($t1)
  lw    $at, -8($t8)
  sw    $at, -8($t1)
  lw    $at, -4($t8)
  bne   $t8, $t0, .L7F051180
   sw    $at, -4($t1)
  lw    $at, ($t8)
  move  $t4, $v0
  move  $t5, $s2
  sw    $at, ($t1)
  lw    $t0, 4($t8)
  addiu $t3, $v0, 0x78
  sw    $t0, 4($t1)
.L7F0511C0:
  lw    $at, ($t4)
  addiu $t4, $t4, 0xc
  addiu $t5, $t5, 0xc
  sw    $at, -0xc($t5)
  lw    $at, -8($t4)
  sw    $at, -8($t5)
  lw    $at, -4($t4)
  bne   $t4, $t3, .L7F0511C0
   sw    $at, -4($t5)
  lw    $at, ($t4)
  move  $a0, $s2
  move  $a3, $s0
  sw    $at, ($t5)
  lw    $t3, 4($t4)
  sw    $t3, 4($t5)
  lw    $t6, 0xc4($sp)
  sh    $t6, 4($s2)
  lw    $t7, 0xc8($sp)
  ori   $t9, $t7, 0x4000
  sw    $t9, 8($s2)
  lh    $t0, ($a1)
  sh    $t0, 6($s2)
  sw    $s1, 0x10($sp)
  jal   sub_GAME_7F050F50
   lw    $a2, 0xbc($sp)
  b     .L7F051250
   move  $s0, $v0
.L7F05122C:
  beqz  $s1, .L7F05123C
   nop   
  jal   set_obj_instance_scale_to_zero
   move  $a0, $s1
.L7F05123C:
  beql  $s0, $zero, .L7F051254
   lw    $ra, 0x2c($sp)
  jal   set_last_obj_pos_data
   move  $a0, $s0
  move  $s0, $zero
.L7F051250:
  lw    $ra, 0x2c($sp)
.L7F051254:
  move  $v0, $s0
  lw    $s0, 0x20($sp)
  lw    $s1, 0x24($sp)
  lw    $s2, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0xc0
");

asm(R"
glabel sub_GAME_7F05126C
  addiu $sp, $sp, -0x58
  sw    $s1, 0x20($sp)
  li    $t6, -1
  lui   $a3, %hi(D_80030AF8)
  lui   $t3, %hi(ProjectileData_start_address) 
  move  $s1, $a1
  sw    $ra, 0x24($sp)
  sw    $s0, 0x1c($sp)
  sw    $a0, 0x58($sp)
  sw    $a2, 0x60($sp)
  sw    $zero, 0x4c($sp)
  sw    $zero, 0x48($sp)
  sw    $t6, 0x44($sp)
  li    $t0, -1
  li    $t1, -1
  addiu $t3, %lo(ProjectileData_start_address) # addiu $t3, $t3, 0x1e80
  lw    $a3, %lo(D_80030AF8)($a3)
  li    $t2, 136
.L7F0512B4:
  multu $a3, $t2
  lw    $t8, 0x58($sp)
  mflo  $t7
  addu  $s0, $t3, $t7
  lw    $a0, 0x10($s0)
  bnezl $a0, .L7F0512EC
   lw    $t9, 0x64($s0)
  bnezl $t8, .L7F0513D4
   addiu $a3, $a3, 1
  bnezl $s1, .L7F0513D4
   addiu $a3, $a3, 1
  b     .L7F0513F0
   sw    $a3, 0x44($sp)
  lw    $t9, 0x64($s0)
.L7F0512EC:
  andi  $t4, $t9, 0x80
  bnezl $t4, .L7F0513D4
   addiu $a3, $a3, 1
  lbu   $t5, 2($s0)
  andi  $t6, $t5, 4
  bnezl $t6, .L7F0513D4
   addiu $a3, $a3, 1
  lh    $t7, 0x82($s0)
  bgtzl $t7, .L7F051324
   lb    $v0, 0x80($s0)
  lw    $t8, 0x1c($a0)
  beqz  $t8, .L7F05136C
   nop   
  lb    $v0, 0x80($s0)
.L7F051324:
  li    $at, 29
  beq   $v0, $at, .L7F051340
   li    $at, 28
  beq   $v0, $at, .L7F051340
   li    $at, 27
  bnel  $v0, $at, .L7F0513D4
   addiu $a3, $a3, 1
.L7F051340:
  lw    $v1, 0x1c($a0)
  beqz  $v1, .L7F05136C
   nop   
  lbu   $v0, ($v1)
  li    $at, 1
  beq   $v0, $at, .L7F05136C
   li    $at, 2
  beq   $v0, $at, .L7F05136C
   li    $at, 4
  bnel  $v0, $at, .L7F0513D4
   addiu $a3, $a3, 1
.L7F05136C:
  beqz  $s1, .L7F0513A8
   lw    $a1, 0x60($sp)
  lw    $a0, 0x14($s0)
  sw    $a3, 0x54($sp)
  sw    $t0, 0x40($sp)
  jal   sub_GAME_7F06C060
   sw    $t1, 0x3c($sp)
  lui   $t3, %hi(ProjectileData_start_address) 
  addiu $t3, %lo(ProjectileData_start_address) # addiu $t3, $t3, 0x1e80
  lw    $a3, 0x54($sp)
  lw    $t0, 0x40($sp)
  lw    $t1, 0x3c($sp)
  beqz  $v0, .L7F0513D0
   li    $t2, 136
  lw    $a0, 0x10($s0)
.L7F0513A8:
  lbu   $t9, 1($a0)
  andi  $t4, $t9, 2
  bnez  $t4, .L7F0513C4
   nop   
  bgez  $t0, .L7F0513C4
   nop   
  move  $t0, $a3
.L7F0513C4:
  bgezl $t1, .L7F0513D4
   addiu $a3, $a3, 1
  move  $t1, $a3
.L7F0513D0:
  addiu $a3, $a3, 1
.L7F0513D4:
  li    $at, 30
  div   $zero, $a3, $at
  lui   $t6, %hi(D_80030AF8) 
  lw    $t6, %lo(D_80030AF8)($t6)
  mfhi  $a3
  bne   $a3, $t6, .L7F0512B4
   nop   
.L7F0513F0:
  lw    $t7, 0x44($sp)
  li    $a0, 8
  addiu $a1, $sp, 0x4c
  bltz  $t7, .L7F051430
   addiu $a2, $sp, 0x48
  addiu $t8, $t7, 1
  li    $at, 30
  div   $zero, $t8, $at
  mfhi  $t9
  lui   $at, %hi(D_80030AF8)
  sw    $t9, %lo(D_80030AF8)($at)
  multu $t7, $t2
  mflo  $t4
  addu  $v0, $t3, $t4
  b     .L7F051578
   lw    $ra, 0x24($sp)
.L7F051430:
  lw    $t5, 0x60($sp)
  lw    $a3, 0x58($sp)
  sw    $s1, 0x10($sp)
  sw    $t0, 0x40($sp)
  sw    $t1, 0x3c($sp)
  jal   sub_GAME_7F056F08
   sw    $t5, 0x14($sp)
  lui   $t3, %hi(ProjectileData_start_address) 
  addiu $t3, %lo(ProjectileData_start_address) # addiu $t3, $t3, 0x1e80
  lw    $t0, 0x40($sp)
  lw    $t1, 0x3c($sp)
  beqz  $v0, .L7F05146C
   li    $t2, 136
  b     .L7F051578
   lw    $ra, 0x24($sp)
.L7F05146C:
  bltz  $t0, .L7F0514C4
   lw    $t7, 0x4c($sp)
  multu $t0, $t2
  li    $a1, 1
  mflo  $s0
  addu  $a0, $t3, $s0
  lw    $t6, 0x10($a0)
  beql  $t6, $zero, .L7F0514A8
   addiu $t8, $t0, 1
  jal   sub_GAME_7F041024
   sw    $t0, 0x40($sp)
  lui   $t3, %hi(ProjectileData_start_address) 
  addiu $t3, %lo(ProjectileData_start_address) # addiu $t3, $t3, 0x1e80
  lw    $t0, 0x40($sp)
  addiu $t8, $t0, 1
.L7F0514A8:
  li    $at, 30
  div   $zero, $t8, $at
  mfhi  $t9
  lui   $at, %hi(D_80030AF8)
  sw    $t9, %lo(D_80030AF8)($at)
  b     .L7F051574
   addu  $v0, $t3, $s0
.L7F0514C4:
  beqz  $t7, .L7F0514EC
   nop   
  lw    $t4, 0x10($t7)
  move  $a0, $t7
  beqz  $t4, .L7F0514E4
   nop   
  jal   sub_GAME_7F041024
   li    $a1, 1
.L7F0514E4:
  b     .L7F051574
   lw    $v0, 0x4c($sp)
.L7F0514EC:
  bltzl $t1, .L7F051548
   lw    $t9, 0x48($sp)
  multu $t1, $t2
  li    $a1, 1
  mflo  $s0
  addu  $a0, $t3, $s0
  lw    $t5, 0x10($a0)
  beql  $t5, $zero, .L7F051528
   addiu $t6, $t1, 1
  jal   sub_GAME_7F041024
   sw    $t1, 0x3c($sp)
  lui   $t3, %hi(ProjectileData_start_address) 
  addiu $t3, %lo(ProjectileData_start_address) # addiu $t3, $t3, 0x1e80
  lw    $t1, 0x3c($sp)
  addiu $t6, $t1, 1
.L7F051528:
  li    $at, 30
  div   $zero, $t6, $at
  mfhi  $t8
  lui   $at, %hi(D_80030AF8)
  sw    $t8, %lo(D_80030AF8)($at)
  b     .L7F051574
   addu  $v0, $t3, $s0
  lw    $t9, 0x48($sp)
.L7F051548:
  beql  $t9, $zero, .L7F051574
   move  $v0, $zero
  lw    $t4, 0x10($t9)
  move  $a0, $t9
  beqz  $t4, .L7F051568
   nop   
  jal   sub_GAME_7F041024
   li    $a1, 1
.L7F051568:
  b     .L7F051574
   lw    $v0, 0x48($sp)
  move  $v0, $zero
.L7F051574:
  lw    $ra, 0x24($sp)
.L7F051578:
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x58
");

asm(R"
glabel sub_GAME_7F051588
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  move  $a0, $zero
  move  $a1, $zero
  jal   sub_GAME_7F05126C
   move  $a2, $zero
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0515B0
  addiu $sp, $sp, -0x68
  sw    $s5, 0x34($sp)
  lui   $s5, %hi(D_80030AFC)
  sw    $s4, 0x30($sp)
  addiu $s5, %lo(D_80030AFC) # addiu $s5, $s5, 0xafc
  sw    $s6, 0x38($sp)
  sw    $s3, 0x2c($sp)
  sw    $s2, 0x28($sp)
  sw    $s1, 0x24($sp)
  li    $t6, -1
  lui   $s4, %hi(dword_CODE_bss_80072E70)
  move  $s2, $a1
  sw    $ra, 0x3c($sp)
  sw    $s0, 0x20($sp)
  sw    $a2, 0x70($sp)
  move  $a3, $a0
  sw    $zero, 0x5c($sp)
  sw    $zero, 0x58($sp)
  sw    $t6, 0x54($sp)
  li    $s1, -1
  li    $s3, -1
  addiu $s4, %lo(dword_CODE_bss_80072E70) # addiu $s4, $s4, 0x2e70
  li    $s6, 10
  lw    $v1, ($s5)
  sll   $t7, $v1, 7
.L7F051614:
  addu  $s0, $s4, $t7
  lw    $v0, 0x10($s0)
  bnezl $v0, .L7F051640
   lw    $t8, 0x64($s0)
  bnezl $a3, .L7F0516B0
   addiu $t3, $v1, 1
  bnezl $s2, .L7F0516B0
   addiu $t3, $v1, 1
  b     .L7F0516E8
   sw    $v1, 0x54($sp)
  lw    $t8, 0x64($s0)
.L7F051640:
  andi  $t9, $t8, 0x80
  bnezl $t9, .L7F0516B0
   addiu $t3, $v1, 1
  lw    $t0, 0x1c($v0)
  bnezl $t0, .L7F0516B0
   addiu $t3, $v1, 1
  beql  $s2, $zero, .L7F051688
   lbu   $t1, 1($v0)
  lw    $a0, 0x14($s0)
  lw    $a1, 0x70($sp)
  sw    $v1, 0x64($sp)
  jal   sub_GAME_7F06C060
   sw    $a3, 0x68($sp)
  lw    $v1, 0x64($sp)
  beqz  $v0, .L7F0516AC
   lw    $a3, 0x68($sp)
  lw    $v0, 0x10($s0)
  lbu   $t1, 1($v0)
.L7F051688:
  andi  $t2, $t1, 2
  bnez  $t2, .L7F0516A0
   nop   
  bgez  $s1, .L7F0516A0
   nop   
  move  $s1, $v1
.L7F0516A0:
  bgezl $s3, .L7F0516B0
   addiu $t3, $v1, 1
  move  $s3, $v1
.L7F0516AC:
  addiu $t3, $v1, 1
.L7F0516B0:
  div   $zero, $t3, $s6
  lw    $t4, ($s5)
  mfhi  $v1
  bnez  $s6, .L7F0516C8
   nop   
  break 7
.L7F0516C8:
  li    $at, -1
  bne   $s6, $at, .L7F0516E0
   lui   $at, 0x8000
  bne   $t3, $at, .L7F0516E0
   nop   
  break 6
.L7F0516E0:
  bnel  $v1, $t4, .L7F051614
   sll   $t7, $v1, 7
.L7F0516E8:
  lw    $t5, 0x54($sp)
  bltz  $t5, .L7F051734
   addiu $t6, $t5, 1
  div   $zero, $t6, $s6
  lw    $t8, 0x54($sp)
  mfhi  $t7
  sw    $t7, ($s5)
  bnez  $s6, .L7F051710
   nop   
  break 7
.L7F051710:
  li    $at, -1
  bne   $s6, $at, .L7F051728
   lui   $at, 0x8000
  bne   $t6, $at, .L7F051728
   nop   
  break 6
.L7F051728:
  sll   $t9, $t8, 7
  b     .L7F051880
   addu  $v0, $s4, $t9
.L7F051734:
  lw    $t0, 0x70($sp)
  li    $a0, 17
  addiu $a1, $sp, 0x5c
  addiu $a2, $sp, 0x58
  sw    $s2, 0x10($sp)
  jal   sub_GAME_7F056F08
   sw    $t0, 0x14($sp)
  beqz  $v0, .L7F051760
   move  $v1, $v0
  b     .L7F051880
   move  $v0, $v1
.L7F051760:
  bltzl $s1, .L7F0517C8
   lw    $t6, 0x5c($sp)
  sll   $t1, $s1, 7
  addu  $a0, $s4, $t1
  lw    $t2, 0x10($a0)
  beql  $t2, $zero, .L7F051788
   addiu $t3, $s1, 1
  jal   sub_GAME_7F041024
   li    $a1, 1
  addiu $t3, $s1, 1
.L7F051788:
  div   $zero, $t3, $s6
  mfhi  $t4
  sll   $t5, $s1, 7
  bnez  $s6, .L7F0517A0
   nop   
  break 7
.L7F0517A0:
  li    $at, -1
  bne   $s6, $at, .L7F0517B8
   lui   $at, 0x8000
  bne   $t3, $at, .L7F0517B8
   nop   
  break 6
.L7F0517B8:
  sw    $t4, ($s5)
  b     .L7F051880
   addu  $v0, $s4, $t5
  lw    $t6, 0x5c($sp)
.L7F0517C8:
  beqz  $t6, .L7F0517F0
   nop   
  lw    $t7, 0x10($t6)
  move  $a0, $t6
  beqz  $t7, .L7F0517E8
   nop   
  jal   sub_GAME_7F041024
   li    $a1, 1
.L7F0517E8:
  b     .L7F051880
   lw    $v0, 0x5c($sp)
.L7F0517F0:
  bltz  $s3, .L7F051850
   sll   $t8, $s3, 7
  addu  $a0, $s4, $t8
  lw    $t9, 0x10($a0)
  beql  $t9, $zero, .L7F051814
   addiu $t0, $s3, 1
  jal   sub_GAME_7F041024
   li    $a1, 1
  addiu $t0, $s3, 1
.L7F051814:
  div   $zero, $t0, $s6
  mfhi  $t1
  sll   $t2, $s3, 7
  bnez  $s6, .L7F05182C
   nop   
  break 7
.L7F05182C:
  li    $at, -1
  bne   $s6, $at, .L7F051844
   lui   $at, 0x8000
  bne   $t0, $at, .L7F051844
   nop   
  break 6
.L7F051844:
  sw    $t1, ($s5)
  b     .L7F051880
   addu  $v0, $s4, $t2
.L7F051850:
  lw    $t3, 0x58($sp)
  beql  $t3, $zero, .L7F051880
   move  $v0, $zero
  lw    $t4, 0x10($t3)
  move  $a0, $t3
  beqz  $t4, .L7F051874
   nop   
  jal   sub_GAME_7F041024
   li    $a1, 1
.L7F051874:
  b     .L7F051880
   lw    $v0, 0x58($sp)
  move  $v0, $zero
.L7F051880:
  lw    $ra, 0x3c($sp)
  lw    $s0, 0x20($sp)
  lw    $s1, 0x24($sp)
  lw    $s2, 0x28($sp)
  lw    $s3, 0x2c($sp)
  lw    $s4, 0x30($sp)
  lw    $s5, 0x34($sp)
  lw    $s6, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x68
");

asm(R"
glabel sub_GAME_7F0518A8
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  move  $a0, $zero
  move  $a1, $zero
  jal   sub_GAME_7F0515B0
   move  $a2, $zero
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0518D0
  addiu $sp, $sp, -0x20
  lui   $a0, %hi(dword_CODE_bss_80073370)
  lui   $v0, %hi(dword_CODE_bss_80073DC0)
  sw    $ra, 0x14($sp)
  addiu $v0, %lo(dword_CODE_bss_80073DC0) # addiu $v0, $v0, 0x3dc0
  addiu $a0, %lo(dword_CODE_bss_80073370) # addiu $a0, $a0, 0x3370
  move  $v1, $zero
.L7F0518EC:
  lw    $t6, 0x10($a0)
  addiu $a0, $a0, 0x84
  sltu  $at, $a0, $v0
  bnez  $t6, .L7F05190C
   lui   $t7, %hi(dword_CODE_bss_80073370) 
  addiu $t7, %lo(dword_CODE_bss_80073370) # addiu $t7, $t7, 0x3370
  b     .L7F051A08
   addu  $v0, $v1, $t7
.L7F05190C:
  bnez  $at, .L7F0518EC
   addiu $v1, $v1, 0x84
  lui   $a0, %hi(dword_CODE_bss_80073370)
  lui   $a1, %hi(dword_CODE_bss_80073DC0)
  addiu $a1, %lo(dword_CODE_bss_80073DC0) # addiu $a1, $a1, 0x3dc0
  addiu $a0, %lo(dword_CODE_bss_80073370) # addiu $a0, $a0, 0x3370
  move  $v1, $zero
.L7F051928:
  lw    $t8, 0x64($a0)
  andi  $t9, $t8, 0x80
  bnezl $t9, .L7F05198C
   addiu $a0, $a0, 0x84
  lbu   $t0, 2($a0)
  andi  $t1, $t0, 4
  bnezl $t1, .L7F05198C
   addiu $a0, $a0, 0x84
  lw    $v0, 0x10($a0)
  lw    $t2, 0x1c($v0)
  bnezl $t2, .L7F05198C
   addiu $a0, $a0, 0x84
  lbu   $t3, 1($v0)
  andi  $t4, $t3, 2
  bnezl $t4, .L7F05198C
   addiu $a0, $a0, 0x84
  li    $a1, 1
  jal   sub_GAME_7F041024
   sw    $v1, 0x18($sp)
  lw    $v1, 0x18($sp)
  lui   $t5, %hi(dword_CODE_bss_80073370) 
  addiu $t5, %lo(dword_CODE_bss_80073370) # addiu $t5, $t5, 0x3370
  b     .L7F051A08
   addu  $v0, $v1, $t5
  addiu $a0, $a0, 0x84
.L7F05198C:
  sltu  $at, $a0, $a1
  bnez  $at, .L7F051928
   addiu $v1, $v1, 0x84
  lui   $a0, %hi(dword_CODE_bss_80073370)
  lui   $v0, %hi(dword_CODE_bss_80073DC0)
  addiu $v0, %lo(dword_CODE_bss_80073DC0) # addiu $v0, $v0, 0x3dc0
  addiu $a0, %lo(dword_CODE_bss_80073370) # addiu $a0, $a0, 0x3370
  move  $v1, $zero
.L7F0519AC:
  lw    $t6, 0x64($a0)
  andi  $t7, $t6, 0x80
  bnezl $t7, .L7F0519FC
   addiu $a0, $a0, 0x84
  lbu   $t8, 2($a0)
  andi  $t9, $t8, 4
  bnezl $t9, .L7F0519FC
   addiu $a0, $a0, 0x84
  lw    $t0, 0x10($a0)
  lw    $t1, 0x1c($t0)
  bnez  $t1, .L7F0519F8
   li    $a1, 1
  jal   sub_GAME_7F041024
   sw    $v1, 0x18($sp)
  lw    $v1, 0x18($sp)
  lui   $t2, %hi(dword_CODE_bss_80073370) 
  addiu $t2, %lo(dword_CODE_bss_80073370) # addiu $t2, $t2, 0x3370
  b     .L7F051A08
   addu  $v0, $v1, $t2
.L7F0519F8:
  addiu $a0, $a0, 0x84
.L7F0519FC:
  bne   $a0, $v0, .L7F0519AC
   addiu $v1, $v1, 0x84
  move  $v0, $zero
.L7F051A08:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel trigger_remote_mine_detonation
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   get_cur_playernum
   nop   
  lui   $v1, %hi(D_80030AF4)
  addiu $v1, %lo(D_80030AF4) # addiu $v1, $v1, 0xaf4
  lw    $t6, ($v1)
  li    $t7, 1
  sllv  $t8, $t7, $v0
  or    $t9, $t6, $t8
  sw    $t9, ($v1)
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 243
  jal   play_sfx_a1
   move  $a2, $zero
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel check_if_entry_is_collectable
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  lbu   $t6, ($a1)
  li    $at, 4
  move  $s1, $a0
  bnel  $t6, $at, .L7F051AA8
   lw    $s0, 0x20($a1)
  lw    $v1, 4($a1)
  lb    $t7, 0x80($v1)
  bnel  $a0, $t7, .L7F051AA8
   lw    $s0, 0x20($a1)
  b     .L7F051AD8
   move  $v0, $v1
  lw    $s0, 0x20($a1)
.L7F051AA8:
  beqz  $s0, .L7F051AD4
   move  $a0, $s1
.L7F051AB0:
  jal   check_if_entry_is_collectable
   move  $a1, $s0
  beql  $v0, $zero, .L7F051ACC
   lw    $s0, 0x24($s0)
  b     .L7F051ADC
   lw    $ra, 0x1c($sp)
  lw    $s0, 0x24($s0)
.L7F051ACC:
  bnezl $s0, .L7F051AB0
   move  $a0, $s1
.L7F051AD4:
  move  $v0, $zero
.L7F051AD8:
  lw    $ra, 0x1c($sp)
.L7F051ADC:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x20
");

asm(R"
glabel check_if_item_deposited
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  move  $s1, $a0
  jal   get_ptr_obj_pos_list_current_entry
   sw    $s0, 0x14($sp)
  beqz  $v0, .L7F051B44
   move  $s0, $v0
  move  $a0, $s1
.L7F051B10:
  jal   check_if_entry_is_collectable
   move  $a1, $s0
  beql  $v0, $zero, .L7F051B3C
   lw    $s0, 0x24($s0)
  lw    $t6, 0x64($v0)
  andi  $t7, $t6, 0x80
  bnezl $t7, .L7F051B3C
   lw    $s0, 0x24($s0)
  b     .L7F051B4C
   lw    $ra, 0x1c($sp)
  lw    $s0, 0x24($s0)
.L7F051B3C:
  bnezl $s0, .L7F051B10
   move  $a0, $s1
.L7F051B44:
  move  $v0, $zero
  lw    $ra, 0x1c($sp)
.L7F051B4C:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x20
");

asm(R"
glabel add_obj_to_temp_proxmine_table
  lui   $v1, %hi(temp_mine_table)
  lui   $v0, %hi(gas_damage_flag)
  addiu $v0, %lo(gas_damage_flag) # addiu $v0, $v0, 0x1e78
  addiu $v1, %lo(temp_mine_table) # addiu $v1, $v1, 0x1e00
  lw    $t6, ($v1)
.L7F051B70:
  bnezl $t6, .L7F051B84
   addiu $v1, $v1, 4
  jr    $ra
   sw    $a0, ($v1)

  addiu $v1, $v1, 4
.L7F051B84:
  bnel  $v1, $v0, .L7F051B70
   lw    $t6, ($v1)
  jr    $ra
   nop   
");

asm(R"
glabel remove_obj_from_temp_proxmine_table
  lui   $v1, %hi(temp_mine_table)
  lui   $v0, %hi(gas_damage_flag)
  addiu $v0, %lo(gas_damage_flag) # addiu $v0, $v0, 0x1e78
  addiu $v1, %lo(temp_mine_table) # addiu $v1, $v1, 0x1e00
  lw    $t6, ($v1)
.L7F051BA8:
  bnel  $a0, $t6, .L7F051BBC
   addiu $v1, $v1, 4
  jr    $ra
   sw    $zero, ($v1)

  addiu $v1, $v1, 4
.L7F051BBC:
  bnel  $v1, $v0, .L7F051BA8
   lw    $t6, ($v1)
  jr    $ra
   nop   
");

asm(R"
glabel detonate_proxmine_In_range
  lui   $v1, %hi(temp_mine_table)
  lui   $at, %hi(D_800532EC)
  lui   $a3, %hi(gas_damage_flag)
  move  $a1, $a0
  addiu $a3, %lo(gas_damage_flag) # addiu $a3, $a3, 0x1e78
  lwc1  $f14, %lo(D_800532EC)($at)
  addiu $v1, %lo(temp_mine_table) # addiu $v1, $v1, 0x1e00
  li    $a2, 1
  lw    $a0, ($v1)
.L7F051BF0:
  beql  $a0, $zero, .L7F051C54
   lw    $v0, 4($v1)
  lh    $t6, 0x82($a0)
  bnel  $a2, $t6, .L7F051C54
   lw    $v0, 4($v1)
  lwc1  $f4, ($a1)
  lwc1  $f6, 0x58($a0)
  lwc1  $f8, 4($a1)
  lwc1  $f10, 0x5c($a0)
  sub.s $f0, $f4, $f6
  lwc1  $f16, 8($a1)
  lwc1  $f18, 0x60($a0)
  sub.s $f2, $f8, $f10
  mul.s $f4, $f0, $f0
  sub.s $f12, $f16, $f18
  mul.s $f6, $f2, $f2
  add.s $f8, $f4, $f6
  mul.s $f10, $f12, $f12
  add.s $f16, $f8, $f10
  c.lt.s $f16, $f14
  nop   
  bc1fl .L7F051C54
   lw    $v0, 4($v1)
  sh    $zero, 0x82($a0)
  lw    $v0, 4($v1)
.L7F051C54:
  addiu $v1, $v1, 8
  beqz  $v0, .L7F051CB8
   nop   
  lh    $t7, 0x82($v0)
  bne   $a2, $t7, .L7F051CB8
   nop   
  lwc1  $f18, ($a1)
  lwc1  $f4, 0x58($v0)
  lwc1  $f6, 4($a1)
  lwc1  $f8, 0x5c($v0)
  sub.s $f0, $f18, $f4
  lwc1  $f10, 8($a1)
  lwc1  $f16, 0x60($v0)
  sub.s $f2, $f6, $f8
  mul.s $f18, $f0, $f0
  sub.s $f12, $f10, $f16
  mul.s $f4, $f2, $f2
  add.s $f6, $f18, $f4
  mul.s $f8, $f12, $f12
  add.s $f10, $f6, $f8
  c.lt.s $f10, $f14
  nop   
  bc1f  .L7F051CB8
   nop   
  sh    $zero, 0x82($v0)
.L7F051CB8:
  bnel  $v1, $a3, .L7F051BF0
   lw    $a0, ($v1)
  jr    $ra
   nop   
");

asm(R"
glabel check_guard_detonate_proxmine
  addiu $sp, $sp, -0x50
  sw    $ra, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  jal   get_numguards
   sw    $s0, 0x18($sp)
  blez  $v0, .L7F051D54
   move  $s0, $zero
  sll   $s3, $v0, 4
  subu  $s3, $s3, $v0
  sll   $s3, $s3, 3
  subu  $s3, $s3, $v0
  lui   $s4, %hi(ptr_guard_data)
  addiu $s4, %lo(ptr_guard_data) # addiu $s4, $s4, -0x339c
  sll   $s3, $s3, 2
  addiu $s1, $sp, 0x38
  lw    $t6, ($s4)
.L7F051D14:
  addu  $a0, $s0, $t6
  lw    $t7, 0x1c($a0)
  beql  $t7, $zero, .L7F051D48
   addiu $s0, $s0, 0x1dc
  lhu   $t8, 0x12($a0)
  andi  $t9, $t8, 0x200
  beql  $t9, $zero, .L7F051D48
   addiu $s0, $s0, 0x1dc
  jal   sub_GAME_7F028894
   move  $a1, $s1
  jal   detonate_proxmine_In_range
   move  $a0, $s1
  addiu $s0, $s0, 0x1dc
.L7F051D48:
  slt   $at, $s0, $s3
  bnezl $at, .L7F051D14
   lw    $t6, ($s4)
.L7F051D54:
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  lw    $s3, 0x24($sp)
  lw    $s4, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x50
");

asm(R"
glabel link_objects
  lb    $t6, 0x80($a1)
  lb    $t7, 0x80($a0)
  sw    $a1, 0x84($a0)
  sb    $t6, 0x81($a0)
  sw    $a0, 0x84($a1)
  jr    $ra
   sb    $t7, 0x81($a1)
");

asm(R"
glabel complete_object_data_block_return_position_entry
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   init_standard_object
   nop   
  beqz  $v0, .L7F051DC4
   move  $a2, $v0
  li    $t6, 4
  sb    $t6, ($v0)
  sw    $v0, 0x20($sp)
  move  $a0, $v0
  jal   sub_GAME_7F052574
   move  $a1, $zero
  lw    $a2, 0x20($sp)
.L7F051DC4:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  move  $v0, $a2
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F051DD8
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F0406F8
   nop   
  beqz  $v0, .L7F051E08
   move  $a0, $v0
  li    $t6, 4
  sb    $t6, ($v0)
  sw    $v0, 0x1c($sp)
  jal   sub_GAME_7F052574
   move  $a1, $zero
  lw    $a0, 0x1c($sp)
.L7F051E08:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  move  $v0, $a0
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F051E1C
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lw    $v0, 8($a0)
  move  $a3, $a1
  move  $a2, $a0
  sll   $t6, $v0, 3
  bgez  $t6, .L7F051E44
   move  $a1, $zero
  b     .L7F051E44
   li    $a1, 1
.L7F051E44:
  lw    $a0, 0x10($a2)
  beql  $a0, $zero, .L7F051F20
   li    $v0, 1
  lw    $v1, 0x14($a2)
  sll   $t7, $v0, 2
  beql  $v1, $zero, .L7F051F20
   li    $v0, 1
  bltz  $t7, .L7F051F14
   nop   
  sll   $a0, $a1, 2
  addu  $v0, $a3, $a0
  lw    $t8, 0x160($v0)
  bnez  $t8, .L7F051F0C
   nop   
  lw    $t9, 0x1c($a3)
  bnez  $a0, .L7F051EA4
   sw    $t9, 0x18($v1)
  lw    $t0, 0x1c($a3)
  lw    $t4, 0x14($a2)
  lw    $t1, 8($t0)
  lw    $t2, 8($t1)
  lw    $t3, 0xc($t2)
  b     .L7F051EBC
   sw    $t3, 0x1c($t4)
.L7F051EA4:
  lw    $t5, 0x1c($a3)
  lw    $t9, 0x14($a2)
  lw    $t6, 8($t5)
  lw    $t7, 8($t6)
  lw    $t8, 0x14($t7)
  sw    $t8, 0x1c($t9)
.L7F051EBC:
  lw    $t0, 0x10($a2)
  negu  $t3, $a0
  addu  $t4, $a3, $t3
  sw    $t0, 0x160($v0)
  lw    $t1, 8($a2)
  sll   $t2, $t1, 0
  bgez  $t2, .L7F051F04
   nop   
  lw    $v0, 0x164($t4)
  move  $a0, $a2
  beqz  $v0, .L7F051F04
   nop   
  lw    $a1, 4($v0)
  sw    $a3, 0x1c($sp)
  jal   link_objects
   sw    $a2, 0x18($sp)
  lw    $a2, 0x18($sp)
  lw    $a3, 0x1c($sp)
.L7F051F04:
  b     .L7F051F14
   lw    $a0, 0x10($a2)
.L7F051F0C:
  b     .L7F051F20
   move  $v0, $zero
.L7F051F14:
  jal   sub_GAME_7F03A5A4
   lw    $a1, 0x18($a3)
  li    $v0, 1
.L7F051F20:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F051F30
  addiu $sp, $sp, -0x20
  sw    $a1, 0x24($sp)
  sw    $a2, 0x28($sp)
  move  $a1, $a2
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a3, 0x2c($sp)
  move  $a2, $a3
  move  $s0, $a0
  jal   complete_object_data_block_return_position_entry
   lw    $a3, 0x30($sp)
  beqz  $v0, .L7F051FC0
   sw    $v0, 0x2c($sp)
  lw    $a0, 0x14($s0)
  beql  $a0, $zero, .L7F051FC4
   lw    $ra, 0x1c($sp)
  lhu   $t6, ($s0)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t6, $f4
  bgez  $t6, .L7F051F90
   cvt.s.w $f6, $f4
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F051F90:
  li    $at, 0x3B800000 # 0.003906
  mtc1  $at, $f10
  lwc1  $f16, 0x14($a0)
  mul.s $f0, $f6, $f10
  nop   
  mul.s $f18, $f16, $f0
  mfc1  $a1, $f18
  jal   set_obj_instance_controller_scale
   nop   
  move  $a0, $s0
  jal   sub_GAME_7F051E1C
   lw    $a1, 0x24($sp)
.L7F051FC0:
  lw    $ra, 0x1c($sp)
.L7F051FC4:
  lw    $v0, 0x2c($sp)
  lw    $s0, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x20
");

asm(R"
glabel sub_GAME_7F051FD4
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  sw    $a0, 0x28($sp)
  sw    $a1, 0x2c($sp)
  lh    $a0, 4($a0)
  jal   load_model
   sw    $a0, 0x20($sp)
  lw    $t7, 0x20($sp)
  lui   $a2, %hi(PitemZ_entries)
  lw    $a0, 0x28($sp)
  sll   $t8, $t7, 2
  subu  $t8, $t8, $t7
  sll   $t8, $t8, 2
  addu  $a2, $a2, $t8
  lw    $a2, %lo(PitemZ_entries)($a2)
  lw    $a1, 0x2c($sp)
  move  $a3, $zero
  jal   sub_GAME_7F051F30
   sw    $zero, 0x10($sp)
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F052030
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lw    $t6, 0x74($a0)
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f8
  mtc1  $t6, $f4
  nop   
  cvt.s.w $f6, $f4
  div.s $f10, $f6, $f8
  jal   sub_GAME_7F051FD4
   swc1  $f10, 0x74($a0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel create_new_item_instance_of_model
  sll   $t6, $a0, 2
  addiu $sp, $sp, -0xb8
  subu  $t6, $t6, $a0
  sll   $t6, $t6, 2
  lui   $t7, %hi(PitemZ_entries)
  addu  $t7, $t7, $t6
  lw    $t7, %lo(PitemZ_entries)($t7)
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  sw    $a1, 0xbc($sp)
  sw    $a0, 0xb8($sp)
  jal   load_model
   sw    $t7, 0xb4($sp)
  jal   remove_last_obj_pos_data_entry
   nop   
  move  $s0, $v0
  jal   get_obj_instance_controller_for_header
   lw    $a0, 0xb4($sp)
  sltiu $a0, $s0, 1
  sltiu $a1, $v0, 1
  lw    $a2, 0xb4($sp)
  jal   sub_GAME_7F05126C
   sw    $v0, 0xac($sp)
  lw    $a3, 0xac($sp)
  bnez  $s0, .L7F0520E8
   move  $s1, $v0
  jal   remove_last_obj_pos_data_entry
   sw    $a3, 0xac($sp)
  lw    $a3, 0xac($sp)
  move  $s0, $v0
.L7F0520E8:
  bnez  $a3, .L7F0520FC
   nop   
  jal   get_obj_instance_controller_for_header
   lw    $a0, 0xb4($sp)
  move  $a3, $v0
.L7F0520FC:
  beqz  $s1, .L7F0521B0
   nop   
  beqz  $s0, .L7F0521B0
   nop   
  beqz  $a3, .L7F0521B0
   addiu $v0, $sp, 0x20
  lui   $t8, %hi(blank_08_object_preset_1) 
  addiu $t8, %lo(blank_08_object_preset_1) # addiu $t8, $t8, 0x2194
  addiu $t0, $t8, 0x84
  move  $t1, $v0
.L7F052124:
  lw    $at, ($t8)
  addiu $t8, $t8, 0xc
  addiu $t1, $t1, 0xc
  sw    $at, -0xc($t1)
  lw    $at, -8($t8)
  sw    $at, -8($t1)
  lw    $at, -4($t8)
  bne   $t8, $t0, .L7F052124
   sw    $at, -4($t1)
  lw    $at, ($t8)
  move  $t4, $v0
  move  $t5, $s1
  addiu $t3, $v0, 0x84
  sw    $at, ($t1)
.L7F05215C:
  lw    $at, ($t4)
  addiu $t4, $t4, 0xc
  addiu $t5, $t5, 0xc
  sw    $at, -0xc($t5)
  lw    $at, -8($t4)
  sw    $at, -8($t5)
  lw    $at, -4($t4)
  bne   $t4, $t3, .L7F05215C
   sw    $at, -4($t5)
  lw    $at, ($t4)
  move  $a0, $s1
  move  $a2, $s0
  sw    $at, ($t5)
  lw    $t6, 0xbc($sp)
  sb    $t6, 0x80($s1)
  lw    $t7, 0xb8($sp)
  sh    $t7, 4($s1)
  jal   complete_object_data_block_return_position_entry
   lw    $a1, 0xb4($sp)
  b     .L7F0521D4
   lw    $ra, 0x1c($sp)
.L7F0521B0:
  beqz  $a3, .L7F0521C0
   move  $s1, $zero
  jal   set_obj_instance_scale_to_zero
   move  $a0, $a3
.L7F0521C0:
  beql  $s0, $zero, .L7F0521D4
   lw    $ra, 0x1c($sp)
  jal   set_last_obj_pos_data
   move  $a0, $s0
  lw    $ra, 0x1c($sp)
.L7F0521D4:
  move  $v0, $s1
  lw    $s1, 0x18($sp)
  lw    $s0, 0x14($sp)
  jr    $ra
   addiu $sp, $sp, 0xb8
");

asm(R"
glabel set_0x4_in_runtime_flags_for_item_in_guards_hand
  sll   $t6, $a1, 2
  addu  $t7, $a0, $t6
  lw    $v0, 0x160($t7)
  beqz  $v0, .L7F05220C
   nop   
  lw    $v1, 4($v0)
  lw    $t8, 0x64($v1)
  ori   $t9, $t8, 4
  sw    $t9, 0x64($v1)
.L7F05220C:
  jr    $ra
   nop   
");

asm(R"
glabel something_with_generating_object
  addiu $sp, $sp, -0xc0
  lw    $t6, 0xd4($sp)
  sw    $ra, 0x2c($sp)
  sw    $s2, 0x28($sp)
  sw    $s1, 0x24($sp)
  sw    $s0, 0x20($sp)
  sw    $a0, 0xc0($sp)
  sw    $a1, 0xc4($sp)
  sw    $a2, 0xc8($sp)
  bnez  $t6, .L7F052264
   sw    $a3, 0xcc($sp)
  sll   $t8, $a1, 2
  subu  $t8, $t8, $a1
  sll   $t8, $t8, 2
  lui   $t9, %hi(PitemZ_entries)
  addu  $t9, $t9, $t8
  lw    $t9, %lo(PitemZ_entries)($t9)
  move  $a0, $a1
  jal   load_model
   sw    $t9, 0xd4($sp)
.L7F052264:
  jal   remove_last_obj_pos_data_entry
   nop   
  move  $s1, $v0
  jal   get_obj_instance_controller_for_header
   lw    $a0, 0xd4($sp)
  lw    $s0, 0xd0($sp)
  move  $s2, $v0
  sltiu $a0, $s1, 1
  bnez  $s0, .L7F052298
   sltiu $a1, $v0, 1
  jal   sub_GAME_7F05126C
   lw    $a2, 0xd4($sp)
  move  $s0, $v0
.L7F052298:
  bnez  $s1, .L7F0522AC
   nop   
  jal   remove_last_obj_pos_data_entry
   nop   
  move  $s1, $v0
.L7F0522AC:
  bnez  $s2, .L7F0522C0
   nop   
  jal   get_obj_instance_controller_for_header
   lw    $a0, 0xd4($sp)
  move  $s2, $v0
.L7F0522C0:
  beqz  $s0, .L7F052394
   nop   
  beqz  $s1, .L7F052394
   nop   
  beqz  $s2, .L7F052394
   addiu $v0, $sp, 0x30
  lui   $t0, %hi(blank_08_object_preset_4001) 
  addiu $t0, %lo(blank_08_object_preset_4001) # addiu $t0, $t0, 0x221c
  addiu $t2, $t0, 0x84
  move  $t3, $v0
.L7F0522E8:
  lw    $at, ($t0)
  addiu $t0, $t0, 0xc
  addiu $t3, $t3, 0xc
  sw    $at, -0xc($t3)
  lw    $at, -8($t0)
  sw    $at, -8($t3)
  lw    $at, -4($t0)
  bne   $t0, $t2, .L7F0522E8
   sw    $at, -4($t3)
  lw    $at, ($t0)
  move  $t6, $v0
  move  $t8, $s0
  addiu $t5, $v0, 0x84
  sw    $at, ($t3)
.L7F052320:
  lw    $at, ($t6)
  addiu $t6, $t6, 0xc
  addiu $t8, $t8, 0xc
  sw    $at, -0xc($t8)
  lw    $at, -8($t6)
  sw    $at, -8($t8)
  lw    $at, -4($t6)
  bne   $t6, $t5, .L7F052320
   sw    $at, -4($t8)
  lw    $at, ($t6)
  move  $a0, $s0
  move  $a3, $s1
  sw    $at, ($t8)
  lw    $t9, 0xc8($sp)
  sb    $t9, 0x80($s0)
  lw    $t7, 0xc4($sp)
  sh    $t7, 4($s0)
  lw    $t1, 0xcc($sp)
  ori   $t2, $t1, 0x4000
  sw    $t2, 8($s0)
  lw    $t0, 0xc0($sp)
  lh    $t3, ($t0)
  sh    $t3, 6($s0)
  sw    $s2, 0x10($sp)
  lw    $a2, 0xd4($sp)
  jal   sub_GAME_7F051F30
   lw    $a1, 0xc0($sp)
  b     .L7F0523B8
   move  $s1, $v0
.L7F052394:
  beqz  $s2, .L7F0523A4
   nop   
  jal   set_obj_instance_scale_to_zero
   move  $a0, $s2
.L7F0523A4:
  beql  $s1, $zero, .L7F0523BC
   lw    $ra, 0x2c($sp)
  jal   set_last_obj_pos_data
   move  $a0, $s1
  move  $s1, $zero
.L7F0523B8:
  lw    $ra, 0x2c($sp)
.L7F0523BC:
  move  $v0, $s1
  lw    $s1, 0x24($sp)
  lw    $s0, 0x20($sp)
  lw    $s2, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0xc0
");

asm(R"
glabel actor_draws_weapon_with_model
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $zero, 0x10($sp)
  jal   something_with_generating_object
   sw    $zero, 0x14($sp)
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0523F8
  addiu $sp, $sp, -0xb8
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  sw    $a1, 0xbc($sp)
  sw    $a2, 0xc0($sp)
  lw    $a3, 4($a0)
  move  $a0, $a3
  jal   something_with_weaponpos_of_guarddata_hand
   sw    $a3, 0xb4($sp)
  lw    $a3, 0xb4($sp)
  beqz  $v0, .L7F052540
   move  $v1, $v0
  lw    $s0, 4($v0)
  lw    $t6, 0x64($s0)
  andi  $t7, $t6, 0x800
  bnezl $t7, .L7F052538
   lbu   $t0, 1($v0)
  lw    $t8, 0xc($s0)
  lui   $t1, %hi(D_800322A4) 
  addiu $t1, %lo(D_800322A4) # addiu $t1, $t1, 0x22a4
  sll   $t9, $t8, 0xc
  bltz  $t9, .L7F052534
   addiu $t0, $sp, 0x68
  lw    $s1, 0x14($s0)
  addiu $t3, $t1, 0x3c
.L7F052460:
  lw    $at, ($t1)
  addiu $t1, $t1, 0xc
  addiu $t0, $t0, 0xc
  sw    $at, -0xc($t0)
  lw    $at, -8($t1)
  sw    $at, -8($t0)
  lw    $at, -4($t1)
  bne   $t1, $t3, .L7F052460
   sw    $at, -4($t0)
  lw    $at, ($t1)
  move  $a2, $zero
  sw    $at, ($t0)
  lbu   $t4, 1($v1)
  lw    $a0, 0x1c($a3)
  ori   $t5, $t4, 2
  sb    $t5, 1($v1)
  jal   sub_GAME_7F06C660
   lw    $a1, 0x1c($s1)
  lw    $t6, 0xbc($sp)
  li    $at, 1
  sw    $v0, 0x68($sp)
  bne   $t6, $at, .L7F0524DC
   addiu $a1, $sp, 0x20
  lui   $at, %hi(D_800532F0)
  jal   sub_GAME_7F058688
   lwc1  $f12, %lo(D_800532F0)($at)
  lw    $a0, 0x68($sp)
  jal   sub_GAME_7F058068
   addiu $a1, $sp, 0x20
  addiu $t7, $sp, 0x20
  sw    $t7, 0x68($sp)
.L7F0524DC:
  lw    $t8, 8($s1)
  lh    $a0, 0xe($t8)
  sll   $t9, $a0, 6
  jal   sub_GAME_7F0BD714
   move  $a0, $t9
  sw    $v0, 0x78($sp)
  addiu $a0, $sp, 0x68
  jal   instcalcmatrices
   move  $a1, $s1
  lw    $v0, 0xc0($sp)
  beql  $v0, $zero, .L7F052544
   lw    $ra, 0x1c($sp)
  lw    $t2, 0x64($s0)
  move  $a1, $s1
  andi  $t3, $t2, 0x80
  bnezl $t3, .L7F052544
   lw    $ra, 0x1c($sp)
  jal   sub_GAME_7F06B120
   lw    $a0, ($v0)
  lw    $t1, 0xc0($sp)
  b     .L7F052540
   sw    $v0, ($t1)
.L7F052534:
  lbu   $t0, 1($v0)
.L7F052538:
  andi  $t4, $t0, 0xfffd
  sb    $t4, 1($v0)
.L7F052540:
  lw    $ra, 0x1c($sp)
.L7F052544:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0xb8
");

asm(R"
glabel redirect_object_collectability_routines
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   object_collectability_routines
   nop   
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F052574
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a1, 0x24($sp)
  lw    $v0, 4($a0)
  lw    $a2, 0x14($v0)
  beql  $a2, $zero, .L7F0525F8
   lw    $ra, 0x14($sp)
  lw    $v0, 8($a2)
  lui   $t6, %hi(prop_weapon_related) 
  addiu $t6, %lo(prop_weapon_related) # addiu $t6, $t6, -0x3b04
  lw    $t7, 4($v0)
  bnel  $t6, $t7, .L7F0525F8
   lw    $ra, 0x14($sp)
  lw    $v1, 8($v0)
  move  $a0, $a2
  lw    $a1, ($v1)
  beql  $a1, $zero, .L7F0525DC
   lw    $a1, 8($v1)
  jal   extract_id_from_object_structure_microcode
   sw    $a2, 0x18($sp)
  lw    $t8, 0x24($sp)
  lw    $a2, 0x18($sp)
  sh    $t8, ($v0)
  lw    $t9, 8($a2)
  lw    $v1, 8($t9)
  lw    $a1, 8($v1)
.L7F0525DC:
  beql  $a1, $zero, .L7F0525F8
   lw    $ra, 0x14($sp)
  jal   extract_id_from_object_structure_microcode
   move  $a0, $a2
  lw    $t0, 0x24($sp)
  sw    $t0, ($v0)
  lw    $ra, 0x14($sp)
.L7F0525F8:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
.late_rodata
/*HACK*/
/*D:800532F4*/
glabel jpt_hat_worn
.word model_hat_fur
.word model_hat_fur
.word model_hat_fur
.word model_hat_greencap
.word model_hat_greencap
.text
glabel sub_GAME_7F052604
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lw    $v0, 4($a0)
  lw    $a2, 0x14($v0)
  beql  $a2, $zero, .L7F052674
   move  $v0, $zero
  lw    $v0, 8($a2)
  lui   $t6, %hi(prop_weapon_related) 
  addiu $t6, %lo(prop_weapon_related) # addiu $t6, $t6, -0x3b04
  lw    $t7, 4($v0)
  bnel  $t6, $t7, .L7F052674
   move  $v0, $zero
  lw    $v1, 8($v0)
  lw    $a1, ($v1)
  beql  $a1, $zero, .L7F052658
   lw    $a1, 8($v1)
  jal   extract_id_from_object_structure_microcode
   move  $a0, $a2
  b     .L7F052674
   lh    $v0, ($v0)
  lw    $a1, 8($v1)
.L7F052658:
  beql  $a1, $zero, .L7F052674
   move  $v0, $zero
  jal   extract_id_from_object_structure_microcode
   move  $a0, $a2
  b     .L7F052674
   lw    $v0, ($v0)
  move  $v0, $zero
.L7F052674:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
.late_rodata
/*D:800532F4*/
/*glabel jpt_hat_worn*/
/*.word model_hat_fur*/
/*.word model_hat_fur*/
/*.word model_hat_fur*/
/*.word model_hat_greencap*/
/*.word model_hat_greencap*/
.word model_hat_combat_helmet
.word model_hat_combat_helmet
.word model_hat_moonraker_headgear
.word model_hat_beret
.word model_hat_beret
.word model_hat_beret
.word model_hat_officerhat

.text
glabel get_hat_model
  lw    $v0, 4($a0)
  lh    $t6, 4($v0)
  li    $v0, -1
  addiu $t7, $t6, -0xd4
  sltiu $at, $t7, 0xc
  beqz  $at, .L7F0526E4
   sll   $t7, $t7, 2
  lui   $at, %hi(jpt_hat_worn)
  addu  $at, $at, $t7
  lw    $t7, %lo(jpt_hat_worn)($at)
  jr    $t7
   nop   
model_hat_fur:
  jr    $ra
   li    $v0, 4

model_hat_greencap:
  jr    $ra
   li    $v0, 1

model_hat_combat_helmet:
  jr    $ra
   li    $v0, 3

model_hat_moonraker_headgear:
  jr    $ra
   li    $v0, 5

model_hat_beret:
  jr    $ra
   move  $v0, $zero

model_hat_officerhat:
  jr    $ra
   li    $v0, 2

model_hat_default:
.L7F0526E4:
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80053324
.word 0x40c90fdb /*6.2831855*/
glabel D_80053328
.word 0x40c90fdb /*6.2831855*/
glabel D_8005332C
.word 0x40c90fdb /*6.2831855*/
glabel D_80053330
.word 0x40c90fdb /*6.2831855*/
glabel D_80053334
.word 0x461c4000 /*10000.0*/
glabel D_80053338
.word 0x3ecccccd /*0.40000001*/
glabel D_8005333C
.word 0x3ecccccd /*0.40000001*/
glabel D_80053340
.word 0x461c4000 /*10000.0*/
glabel D_80053344
.word 0x46b1de00 /*22767.0*/
glabel D_80053348
.word 0x459c4000 /*5000.0*/
.text
glabel sub_GAME_7F0526EC
  addiu $sp, $sp, -0xa0
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a1, 0xa4($sp)
  lhu   $v0, 0x9a($a0)
  li    $at, 5
  move  $s0, $a0
  beq   $v0, $at, .L7F052718
   li    $at, 9
  bnel  $v0, $at, .L7F052A3C
   li    $at, 6
.L7F052718:
  lh    $t9, 6($s0)
  lui   $t1, %hi(ptr_2xxxpresets) 
  lw    $t1, %lo(ptr_2xxxpresets)($t1)
  sll   $t0, $t9, 4
  addu  $t0, $t0, $t9
  sll   $t0, $t0, 2
  addu  $v0, $t0, $t1
  lwc1  $f6, 0x10($v0)
  lwc1  $f8, 0x20($v0)
  lwc1  $f18, 0x1c($v0)
  lwc1  $f10, 0x14($v0)
  mul.s $f4, $f6, $f8
  li    $at, 9
  mul.s $f16, $f18, $f10
  sub.s $f6, $f4, $f16
  swc1  $f6, 0x38($sp)
  lwc1  $f8, 0x14($v0)
  lwc1  $f18, 0x18($v0)
  lwc1  $f16, 0xc($v0)
  lwc1  $f4, 0x20($v0)
  mul.s $f10, $f8, $f18
  nop   
  mul.s $f8, $f4, $f16
  sub.s $f18, $f10, $f8
  swc1  $f18, 0x3c($sp)
  lwc1  $f4, 0xc($v0)
  lwc1  $f16, 0x1c($v0)
  lwc1  $f8, 0x18($v0)
  mul.s $f10, $f4, $f16
  lwc1  $f4, 0x10($v0)
  mul.s $f16, $f8, $f4
  sub.s $f8, $f10, $f16
  swc1  $f8, 0x40($sp)
  lwc1  $f10, 0x34($v0)
  lwc1  $f4, 0xc($v0)
  mul.s $f16, $f4, $f10
  lwc1  $f4, ($v0)
  add.s $f10, $f16, $f4
  swc1  $f10, 0x54($sp)
  lwc1  $f4, 0x34($v0)
  lwc1  $f16, 0x10($v0)
  mul.s $f16, $f16, $f4
  lwc1  $f4, 4($v0)
  add.s $f16, $f16, $f4
  swc1  $f16, 0x58($sp)
  lwc1  $f4, 0x14($v0)
  swc1  $f6, 0x20($sp)
  lwc1  $f6, 0x34($v0)
  mul.s $f4, $f4, $f6
  lwc1  $f6, 8($v0)
  add.s $f4, $f4, $f6
  lwc1  $f6, 0x20($sp)
  swc1  $f4, 0x5c($sp)
  lhu   $t2, 0x9a($s0)
  bne   $t2, $at, .L7F052834
   nop   
  swc1  $f18, 0x20($sp)
  lwc1  $f18, 0x30($v0)
  mul.s $f6, $f6, $f18
  add.s $f18, $f10, $f6
  lwc1  $f10, 0x20($sp)
  swc1  $f18, 0x54($sp)
  lwc1  $f6, 0x30($v0)
  mul.s $f18, $f10, $f6
  add.s $f10, $f16, $f18
  swc1  $f10, 0x58($sp)
  lwc1  $f6, 0x30($v0)
  mul.s $f16, $f8, $f6
  add.s $f18, $f4, $f16
  b     .L7F0528D8
   swc1  $f18, 0x5c($sp)
.L7F052834:
  lw    $t3, 8($s0)
  lwc1  $f10, 0x38($sp)
  lwc1  $f6, 0x38($sp)
  sll   $t4, $t3, 2
  bgezl $t4, .L7F052898
   lwc1  $f16, 0x2c($v0)
  lwc1  $f8, 0x30($v0)
  lwc1  $f4, 0x54($sp)
  lwc1  $f18, 0x3c($sp)
  mul.s $f6, $f10, $f8
  add.s $f16, $f4, $f6
  lwc1  $f4, 0x58($sp)
  swc1  $f16, 0x54($sp)
  lwc1  $f10, 0x30($v0)
  lwc1  $f16, 0x40($sp)
  mul.s $f8, $f18, $f10
  add.s $f6, $f4, $f8
  lwc1  $f4, 0x5c($sp)
  swc1  $f6, 0x58($sp)
  lwc1  $f18, 0x30($v0)
  mul.s $f10, $f16, $f18
  add.s $f8, $f4, $f10
  b     .L7F0528D8
   swc1  $f8, 0x5c($sp)
  lwc1  $f16, 0x2c($v0)
.L7F052898:
  lwc1  $f4, 0x54($sp)
  lwc1  $f8, 0x3c($sp)
  mul.s $f18, $f6, $f16
  add.s $f10, $f4, $f18
  lwc1  $f4, 0x58($sp)
  swc1  $f10, 0x54($sp)
  lwc1  $f6, 0x2c($v0)
  lwc1  $f10, 0x40($sp)
  mul.s $f16, $f8, $f6
  add.s $f18, $f4, $f16
  lwc1  $f4, 0x5c($sp)
  swc1  $f18, 0x58($sp)
  lwc1  $f8, 0x2c($v0)
  mul.s $f6, $f10, $f8
  add.s $f16, $f4, $f6
  swc1  $f16, 0x5c($sp)
.L7F0528D8:
  lwc1  $f18, 0x58($s0)
  lwc1  $f10, 0x54($sp)
  lwc1  $f6, 0x58($sp)
  addiu $a0, $s0, 0x18
  sub.s $f8, $f18, $f10
  lwc1  $f10, 0x5c($sp)
  lw    $a1, 0xa4($sp)
  swc1  $f8, 0x48($sp)
  lwc1  $f4, 0x5c($s0)
  sub.s $f16, $f4, $f6
  swc1  $f16, 0x4c($sp)
  lwc1  $f18, 0x60($s0)
  sub.s $f8, $f18, $f10
  jal   sub_GAME_7F058020
   swc1  $f8, 0x50($sp)
  addiu $a0, $sp, 0x48
  jal   init_something_copy_posdata_to_it
   addiu $a1, $sp, 0x60
  addiu $a0, $sp, 0x60
  jal   sub_GAME_7F058068
   lw    $a1, 0xa4($sp)
  lhu   $t5, 0x9a($s0)
  li    $at, 9
  bnel  $t5, $at, .L7F0529AC
   lw    $t8, 8($s0)
  lw    $t6, 8($s0)
  lui   $at, %hi(D_80053328)
  sll   $t7, $t6, 2
  bgez  $t7, .L7F052980
   nop   
  lui   $at, %hi(D_80053324)
  lwc1  $f0, %lo(D_80053324)($at)
  lwc1  $f4, 0xb4($s0)
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f16
  mul.s $f6, $f4, $f0
  addiu $a1, $sp, 0x60
  div.s $f18, $f6, $f16
  jal   sub_GAME_7F058688
   sub.s $f12, $f0, $f18
  b     .L7F052A10
   addiu $a0, $sp, 0x60
.L7F052980:
  lwc1  $f0, %lo(D_80053328)($at)
  lwc1  $f10, 0xb4($s0)
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f4
  mul.s $f8, $f10, $f0
  addiu $a1, $sp, 0x60
  jal   sub_GAME_7F058688
   div.s $f12, $f8, $f4
  b     .L7F052A10
   addiu $a0, $sp, 0x60
  lw    $t8, 8($s0)
.L7F0529AC:
  lui   $at, %hi(D_80053330)
  sll   $t9, $t8, 2
  bgez  $t9, .L7F0529EC
   nop   
  lui   $at, %hi(D_8005332C)
  lwc1  $f0, %lo(D_8005332C)($at)
  lwc1  $f6, 0xb4($s0)
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f18
  mul.s $f16, $f6, $f0
  addiu $a1, $sp, 0x60
  div.s $f10, $f16, $f18
  jal   sub_GAME_7F0585FC
   sub.s $f12, $f0, $f10
  b     .L7F052A10
   addiu $a0, $sp, 0x60
.L7F0529EC:
  lwc1  $f0, %lo(D_80053330)($at)
  lwc1  $f8, 0xb4($s0)
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f6
  mul.s $f4, $f8, $f0
  addiu $a1, $sp, 0x60
  jal   sub_GAME_7F0585FC
   div.s $f12, $f4, $f6
  addiu $a0, $sp, 0x60
.L7F052A10:
  jal   sub_GAME_7F058068
   lw    $a1, 0xa4($sp)
  addiu $a0, $sp, 0x54
  jal   init_something_copy_posdata_to_it
   addiu $a1, $sp, 0x60
  addiu $a0, $sp, 0x60
  jal   sub_GAME_7F058068
   lw    $a1, 0xa4($sp)
  b     .L7F052AD0
   lhu   $t0, 0x98($s0)
  li    $at, 6
.L7F052A3C:
  beq   $v0, $at, .L7F052A50
   addiu $a0, $s0, 0x18
  li    $at, 7
  bnel  $v0, $at, .L7F052A70
   lwc1  $f16, 0xa8($s0)
.L7F052A50:
  jal   sub_GAME_7F058020
   lw    $a1, 0xa4($sp)
  addiu $a0, $s0, 0x58
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   lw    $a1, 0xa4($sp)
  b     .L7F052AD0
   lhu   $t0, 0x98($s0)
  lwc1  $f16, 0xa8($s0)
.L7F052A70:
  lwc1  $f18, 0xb4($s0)
  lwc1  $f8, 0x58($s0)
  addiu $a0, $s0, 0x18
  mul.s $f10, $f16, $f18
  lw    $a1, 0xa4($sp)
  add.s $f4, $f10, $f8
  swc1  $f4, 0x2c($sp)
  lwc1  $f16, 0xb4($s0)
  lwc1  $f6, 0xac($s0)
  lwc1  $f10, 0x5c($s0)
  mul.s $f18, $f6, $f16
  add.s $f8, $f18, $f10
  swc1  $f8, 0x30($sp)
  lwc1  $f6, 0xb4($s0)
  lwc1  $f4, 0xb0($s0)
  lwc1  $f18, 0x60($s0)
  mul.s $f16, $f4, $f6
  add.s $f10, $f16, $f18
  jal   sub_GAME_7F058020
   swc1  $f10, 0x34($sp)
  addiu $a0, $sp, 0x2c
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   lw    $a1, 0xa4($sp)
  lhu   $t0, 0x98($s0)
.L7F052AD0:
  li    $at, 0xBF800000 # -1.000000
  andi  $t1, $t0, 8
  beql  $t1, $zero, .L7F052AF0
   lw    $ra, 0x1c($sp)
  mtc1  $at, $f12
  jal   sub_GAME_7F058A4C
   lw    $a1, 0xa4($sp)
  lw    $ra, 0x1c($sp)
.L7F052AF0:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0xa0
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F052B00
  addiu $sp, $sp, -0x70
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  lw    $t6, 0x14($a0)
  addiu $v1, $a0, 0xd0
  move  $s0, $a0
  lw    $t7, 8($t6)
  addiu $a1, $sp, 0x2c
  lw    $t8, ($t7)
  lw    $t9, 0x14($t8)
  lw    $v0, 4($t9)
  lw    $at, ($v0)
  sw    $at, ($v1)
  lw    $t2, 4($v0)
  sw    $t2, 4($v1)
  lw    $at, 8($v0)
  sw    $at, 8($v1)
  lw    $t2, 0xc($v0)
  sw    $t2, 0xc($v1)
  lw    $at, 0x10($v0)
  sw    $at, 0x10($v1)
  lw    $t2, 0x14($v0)
  sw    $t2, 0x14($v1)
  lw    $at, 0x18($v0)
  sw    $at, 0x18($v1)
  lhu   $t3, 0x98($a0)
  andi  $t4, $t3, 4
  beql  $t4, $zero, .L7F052BC4
   lwc1  $f16, 0xb4($s0)
  lhu   $t5, 0x9a($a0)
  li    $at, 4
  bnel  $t5, $at, .L7F052BA8
   lwc1  $f0, 4($v0)
  lwc1  $f0, 0x10($v0)
  lwc1  $f4, 0xc($v0)
  lwc1  $f8, 0xb4($a0)
  sub.s $f6, $f4, $f0
  mul.s $f10, $f6, $f8
  add.s $f16, $f0, $f10
  b     .L7F052BC0
   swc1  $f16, 0xe0($a0)
  lwc1  $f0, 4($v0)
.L7F052BA8:
  lwc1  $f18, 8($v0)
  lwc1  $f6, 0xb4($s0)
  sub.s $f4, $f18, $f0
  mul.s $f8, $f4, $f6
  add.s $f10, $f0, $f8
  swc1  $f10, 0xd4($s0)
.L7F052BC0:
  lwc1  $f16, 0xb4($s0)
.L7F052BC4:
  lwc1  $f18, 0x88($s0)
  move  $a0, $s0
  c.le.s $f18, $f16
  nop   
  bc1f  .L7F052BE8
   nop   
  lw    $t6, 0x68($s0)
  b     .L7F052D78
   sw    $zero, ($t6)
.L7F052BE8:
  jal   sub_GAME_7F0526EC
   sw    $v1, 0x28($sp)
  lw    $a3, 0x68($s0)
  lw    $a0, 0x28($sp)
  addiu $a1, $sp, 0x2c
  jal   sub_GAME_7F03F540
   addiu $a2, $a3, 4
  lhu   $v0, 0x9a($s0)
  li    $at, 4
  lw    $a0, 0x28($sp)
  bnel  $v0, $at, .L7F052C38
   li    $at, 8
  jal   sub_GAME_7F03E9BC
   addiu $a1, $sp, 0x2c
  lwc1  $f4, 0x5c($s0)
  lw    $t7, 0x68($s0)
  add.s $f6, $f0, $f4
  b     .L7F052C9C
   swc1  $f6, 0x48($t7)
  li    $at, 8
.L7F052C38:
  bne   $v0, $at, .L7F052C5C
   lw    $a0, 0x28($sp)
  lui   $at, %hi(D_80053334)
  lwc1  $f10, %lo(D_80053334)($at)
  lwc1  $f8, 0x5c($s0)
  lw    $t8, 0x68($s0)
  sub.s $f16, $f8, $f10
  b     .L7F052C9C
   swc1  $f16, 0x48($t8)
.L7F052C5C:
  jal   sub_GAME_7F03E9BC
   addiu $a1, $sp, 0x2c
  lwc1  $f18, 0x60($sp)
  lw    $t9, 0x68($s0)
  add.s $f4, $f0, $f18
  swc1  $f4, 0x48($t9)
  lhu   $t1, 0x98($s0)
  andi  $t0, $t1, 1
  beql  $t0, $zero, .L7F052CA0
   lhu   $v0, 0x9a($s0)
  lw    $a3, 0x68($s0)
  li    $at, 0x447A0000 # 1000.000000
  mtc1  $at, $f8
  lwc1  $f6, 0x48($a3)
  sub.s $f10, $f6, $f8
  swc1  $f10, 0x48($a3)
.L7F052C9C:
  lhu   $v0, 0x9a($s0)
.L7F052CA0:
  li    $at, 6
  bne   $v0, $at, .L7F052CC8
   lui   $at, %hi(D_80053338)
  lwc1  $f16, %lo(D_80053338)($at)
  lwc1  $f18, 0x84($s0)
  lwc1  $f6, 0xb4($s0)
  mul.s $f4, $f16, $f18
  c.lt.s $f4, $f6
  nop   
  bc1t  .L7F052CF4
.L7F052CC8:
   li    $at, 7
  bne   $v0, $at, .L7F052D10
   lui   $at, %hi(D_8005333C)
  lwc1  $f8, %lo(D_8005333C)($at)
  lwc1  $f10, 0x84($s0)
  lwc1  $f18, 0xb4($s0)
  mul.s $f16, $f8, $f10
  c.lt.s $f16, $f18
  nop   
  bc1fl .L7F052D14
   li    $at, 8
.L7F052CF4:
  lw    $a3, 0x68($s0)
  li    $at, 0x42480000 # 50.000000
  mtc1  $at, $f6
  lwc1  $f4, 0x48($a3)
  add.s $f8, $f4, $f6
  b     .L7F052D78
   swc1  $f8, 0x44($a3)
.L7F052D10:
  li    $at, 8
.L7F052D14:
  bne   $v0, $at, .L7F052D38
   lw    $a0, 0x28($sp)
  li    $at, 0x447A0000 # 1000.000000
  mtc1  $at, $f16
  lwc1  $f10, 0x5c($s0)
  lw    $t2, 0x68($s0)
  add.s $f18, $f10, $f16
  b     .L7F052D78
   swc1  $f18, 0x44($t2)
.L7F052D38:
  jal   sub_GAME_7F03EA5C
   addiu $a1, $sp, 0x2c
  lwc1  $f4, 0x60($sp)
  lw    $t3, 0x68($s0)
  add.s $f6, $f0, $f4
  swc1  $f6, 0x44($t3)
  lhu   $t4, 0x98($s0)
  andi  $t5, $t4, 1
  beql  $t5, $zero, .L7F052D7C
   lw    $ra, 0x1c($sp)
  lw    $a3, 0x68($s0)
  li    $at, 0x447A0000 # 1000.000000
  mtc1  $at, $f10
  lwc1  $f8, 0x44($a3)
  add.s $f16, $f8, $f10
  swc1  $f16, 0x44($a3)
.L7F052D78:
  lw    $ra, 0x1c($sp)
.L7F052D7C:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x70
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F052D8C
  addiu $sp, $sp, -0x58
  sw    $ra, 0x3c($sp)
  sw    $fp, 0x38($sp)
  sw    $s7, 0x34($sp)
  sw    $s6, 0x30($sp)
  sw    $s5, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  lhu   $t6, 0x98($a0)
  move  $s6, $a0
  andi  $t7, $t6, 4
  beql  $t7, $zero, .L7F05356C
   lw    $ra, 0x3c($sp)
  lw    $a0, 0x14($a0)
  lw    $t8, 8($a0)
  lw    $t9, ($t8)
  lw    $t6, 0x14($t9)
  lw    $a1, 0x14($t6)
  jal   extract_id_from_object_structure_microcode
   lw    $s5, 4($a1)
  lhu   $t7, 0x9a($s6)
  li    $s4, 4
  move  $s7, $v0
  bne   $s4, $t7, .L7F052E24
   li    $at, 0x3F000000 # 0.500000
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f6
  lwc1  $f4, 0xe0($s6)
  add.s $f8, $f4, $f6
  trunc.w.s $f10, $f8
  mfc1  $t5, $f10
  nop   
  sll   $t9, $t5, 0x10
  b     .L7F052E48
   sra   $t5, $t9, 0x10
.L7F052E24:
  lwc1  $f16, 0xd4($s6)
  mtc1  $at, $f18
  nop   
  add.s $f4, $f16, $f18
  trunc.w.s $f6, $f4
  mfc1  $t5, $f6
  nop   
  sll   $t8, $t5, 0x10
  sra   $t5, $t8, 0x10
.L7F052E48:
  lh    $a0, 0xc($s5)
  jal   sub_GAME_7F0BD6C4
   sh    $t5, 0x42($sp)
  lh    $t5, 0x42($sp)
  sw    $v0, ($s7)
  lh    $t6, 0xc($s5)
  move  $v1, $zero
  move  $fp, $zero
  bgez  $t6, .L7F052E78
   sra   $t7, $t6, 2
  addiu $at, $t6, 3
  sra   $t7, $at, 2
.L7F052E78:
  blez  $t7, .L7F053568
   move  $v1, $zero
.L7F052E80:
  sll   $s3, $fp, 4
.L7F052E84:
  lw    $t8, ($s7)
  addiu $a3, $v1, 2
  addiu $t4, $v1, 3
  addu  $v0, $t8, $s3
  addiu $s2, $v1, 1
  sll   $a0, $v1, 4
  addu  $t3, $v0, $a0
  bgez  $s2, .L7F052EB4
   andi  $a1, $s2, 3
  beqz  $a1, .L7F052EB4
   nop   
  addiu $a1, $a1, -4
.L7F052EB4:
  sll   $t9, $a1, 4
  move  $a1, $t9
  addu  $ra, $v0, $t9
  bgez  $a3, .L7F052ED4
   andi  $t6, $a3, 3
  beqz  $t6, .L7F052ED4
   nop   
  addiu $t6, $t6, -4
.L7F052ED4:
  sll   $t7, $t6, 4
  lw    $t6, 8($s5)
  move  $a3, $t7
  addu  $s0, $v0, $t7
  addu  $t1, $t6, $s3
  bgez  $t4, .L7F052EFC
   andi  $t8, $t4, 3
  beqz  $t8, .L7F052EFC
   nop   
  addiu $t8, $t8, -4
.L7F052EFC:
  sll   $t4, $t8, 4
  addu  $t2, $t1, $a3
  addu  $s1, $v0, $t4
  addu  $a2, $t1, $a0
  addu  $t0, $t1, $a1
  bnez  $v1, .L7F052F98
   addu  $a3, $t1, $t4
  lw    $at, ($a2)
  sw    $at, ($t3)
  lw    $t8, 4($a2)
  sw    $t8, 4($t3)
  lw    $at, 8($a2)
  sw    $at, 8($t3)
  lw    $t8, 0xc($a2)
  sw    $t8, 0xc($t3)
  lw    $at, ($t0)
  sw    $at, ($ra)
  lw    $t6, 4($t0)
  sw    $t6, 4($ra)
  lw    $at, 8($t0)
  sw    $at, 8($ra)
  lw    $t6, 0xc($t0)
  sw    $t6, 0xc($ra)
  lw    $at, ($t2)
  sw    $at, ($s0)
  lw    $t8, 4($t2)
  sw    $t8, 4($s0)
  lw    $at, 8($t2)
  sw    $at, 8($s0)
  lw    $t8, 0xc($t2)
  sw    $t8, 0xc($s0)
  lw    $at, ($a3)
  sw    $at, ($s1)
  lw    $t6, 4($a3)
  sw    $t6, 4($s1)
  lw    $at, 8($a3)
  sw    $at, 8($s1)
  lw    $t6, 0xc($a3)
  sw    $t6, 0xc($s1)
.L7F052F98:
  lhu   $t7, 0x9a($s6)
  bnel  $s4, $t7, .L7F053274
   lh    $a1, ($a2)
  lh    $a0, 2($a2)
  slt   $at, $a0, $t5
  bnez  $at, .L7F053538
   nop   
  lh    $a1, ($a2)
  lh    $t8, ($t0)
  bnel  $t8, $a1, .L7F0530A4
   lh    $t9, ($t2)
  lh    $t9, 4($t0)
  lh    $t6, 4($a2)
  bnel  $t9, $t6, .L7F0530A4
   lh    $t9, ($t2)
  lh    $t1, 2($t0)
  beql  $t1, $a0, .L7F0530A4
   lh    $t9, ($t2)
  lh    $v0, 8($a2)
  lh    $t8, 8($t0)
  subu  $t7, $a0, $t5
  subu  $t9, $t8, $v0
  multu $t7, $t9
  subu  $t8, $a0, $t1
  mflo  $t6
  nop   
  nop   
  div   $zero, $t6, $t8
  mflo  $t7
  addu  $t9, $t7, $v0
  sh    $t9, 8($t3)
  bnez  $t8, .L7F053020
   nop   
  break 7
.L7F053020:
  li    $at, -1
  bne   $t8, $at, .L7F053038
   lui   $at, 0x8000
  bne   $t6, $at, .L7F053038
   nop   
  break 6
.L7F053038:
  lh    $t8, 0xa($t0)
  lh    $v1, 0xa($a2)
  lh    $a0, 2($a2)
  subu  $t7, $t8, $v1
  subu  $t6, $a0, $t5
  multu $t6, $t7
  lh    $t8, 2($t0)
  subu  $t6, $a0, $t8
  mflo  $t9
  nop   
  nop   
  div   $zero, $t9, $t6
  mflo  $t7
  addu  $t8, $t7, $v1
  bnez  $t6, .L7F05307C
   nop   
  break 7
.L7F05307C:
  li    $at, -1
  bne   $t6, $at, .L7F053094
   lui   $at, 0x8000
  bne   $t9, $at, .L7F053094
   nop   
  break 6
.L7F053094:
  sh    $t8, 0xa($t3)
  b     .L7F053268
   nop   
  lh    $t9, ($t2)
.L7F0530A4:
  bnel  $t9, $a1, .L7F05318C
   lh    $t6, ($a3)
  lh    $t6, 4($t2)
  lh    $t7, 4($a2)
  bnel  $t6, $t7, .L7F05318C
   lh    $t6, ($a3)
  lh    $t0, 2($t2)
  beql  $t0, $a0, .L7F05318C
   lh    $t6, ($a3)
  lh    $v0, 8($a2)
  lh    $t9, 8($t2)
  subu  $t8, $a0, $t5
  subu  $t6, $t9, $v0
  multu $t8, $t6
  subu  $t9, $a0, $t0
  mflo  $t7
  nop   
  nop   
  div   $zero, $t7, $t9
  mflo  $t8
  addu  $t6, $t8, $v0
  sh    $t6, 8($t3)
  bnez  $t9, .L7F053108
   nop   
  break 7
.L7F053108:
  li    $at, -1
  bne   $t9, $at, .L7F053120
   lui   $at, 0x8000
  bne   $t7, $at, .L7F053120
   nop   
  break 6
.L7F053120:
  lh    $t9, 0xa($t2)
  lh    $v1, 0xa($a2)
  lh    $a0, 2($a2)
  subu  $t8, $t9, $v1
  subu  $t7, $a0, $t5
  multu $t7, $t8
  lh    $t9, 2($t2)
  subu  $t7, $a0, $t9
  mflo  $t6
  nop   
  nop   
  div   $zero, $t6, $t7
  mflo  $t8
  addu  $t9, $t8, $v1
  bnez  $t7, .L7F053164
   nop   
  break 7
.L7F053164:
  li    $at, -1
  bne   $t7, $at, .L7F05317C
   lui   $at, 0x8000
  bne   $t6, $at, .L7F05317C
   nop   
  break 6
.L7F05317C:
  sh    $t9, 0xa($t3)
  b     .L7F053268
   nop   
  lh    $t6, ($a3)
.L7F05318C:
  bne   $t6, $a1, .L7F053268
   nop   
  lh    $t7, 4($a3)
  lh    $t8, 4($a2)
  bne   $t7, $t8, .L7F053268
   nop   
  lh    $a1, 2($a3)
  beq   $a1, $a0, .L7F053268
   nop   
  lh    $v0, 8($a2)
  lh    $t6, 8($a3)
  subu  $t9, $a0, $t5
  subu  $t7, $t6, $v0
  multu $t9, $t7
  subu  $t6, $a0, $a1
  mflo  $t8
  nop   
  nop   
  div   $zero, $t8, $t6
  mflo  $t9
  addu  $t7, $t9, $v0
  sh    $t7, 8($t3)
  bnez  $t6, .L7F0531F0
   nop   
  break 7
.L7F0531F0:
  li    $at, -1
  bne   $t6, $at, .L7F053208
   lui   $at, 0x8000
  bne   $t8, $at, .L7F053208
   nop   
  break 6
.L7F053208:
  lh    $t6, 0xa($a3)
  lh    $v1, 0xa($a2)
  lh    $a0, 2($a2)
  subu  $t9, $t6, $v1
  subu  $t8, $a0, $t5
  multu $t8, $t9
  lh    $t6, 2($a3)
  subu  $t8, $a0, $t6
  mflo  $t7
  nop   
  nop   
  div   $zero, $t7, $t8
  mflo  $t9
  addu  $t6, $t9, $v1
  sh    $t6, 0xa($t3)
  bnez  $t8, .L7F053250
   nop   
  break 7
.L7F053250:
  li    $at, -1
  bne   $t8, $at, .L7F053268
   lui   $at, 0x8000
  bne   $t7, $at, .L7F053268
   nop   
  break 6
.L7F053268:
  b     .L7F053538
   sh    $t5, 2($t3)
  lh    $a1, ($a2)
.L7F053274:
  slt   $at, $t5, $a1
  bnez  $at, .L7F053538
   nop   
  lh    $a0, 2($a2)
  lh    $t7, 2($t0)
  bnel  $t7, $a0, .L7F053370
   lh    $t8, 2($t2)
  lh    $t8, 4($t0)
  lh    $t9, 4($a2)
  bnel  $t8, $t9, .L7F053370
   lh    $t8, 2($t2)
  lh    $t1, ($t0)
  beql  $t1, $a1, .L7F053370
   lh    $t8, 2($t2)
  lh    $v0, 8($a2)
  lh    $t7, 8($t0)
  subu  $t6, $t5, $a1
  subu  $t8, $t7, $v0
  multu $t6, $t8
  subu  $t7, $t1, $a1
  mflo  $t9
  nop   
  nop   
  div   $zero, $t9, $t7
  mflo  $t6
  addu  $t8, $t6, $v0
  sh    $t8, 8($t3)
  bnez  $t7, .L7F0532EC
   nop   
  break 7
.L7F0532EC:
  li    $at, -1
  bne   $t7, $at, .L7F053304
   lui   $at, 0x8000
  bne   $t9, $at, .L7F053304
   nop   
  break 6
.L7F053304:
  lh    $t7, 0xa($t0)
  lh    $v1, 0xa($a2)
  lh    $a1, ($a2)
  subu  $t6, $t7, $v1
  subu  $t9, $t5, $a1
  multu $t9, $t6
  lh    $t7, ($t0)
  subu  $t9, $t7, $a1
  mflo  $t8
  nop   
  nop   
  div   $zero, $t8, $t9
  mflo  $t6
  addu  $t7, $t6, $v1
  bnez  $t9, .L7F053348
   nop   
  break 7
.L7F053348:
  li    $at, -1
  bne   $t9, $at, .L7F053360
   lui   $at, 0x8000
  bne   $t8, $at, .L7F053360
   nop   
  break 6
.L7F053360:
  sh    $t7, 0xa($t3)
  b     .L7F053538
   sh    $t5, ($t3)
  lh    $t8, 2($t2)
.L7F053370:
  bnel  $t8, $a0, .L7F053458
   lh    $t9, 2($a3)
  lh    $t9, 4($t2)
  lh    $t6, 4($a2)
  bnel  $t9, $t6, .L7F053458
   lh    $t9, 2($a3)
  lh    $t0, ($t2)
  beql  $t0, $a1, .L7F053458
   lh    $t9, 2($a3)
  lh    $v0, 8($a2)
  lh    $t8, 8($t2)
  subu  $t7, $t5, $a1
  subu  $t9, $t8, $v0
  multu $t7, $t9
  subu  $t8, $t0, $a1
  mflo  $t6
  nop   
  nop   
  div   $zero, $t6, $t8
  mflo  $t7
  addu  $t9, $t7, $v0
  sh    $t9, 8($t3)
  bnez  $t8, .L7F0533D4
   nop   
  break 7
.L7F0533D4:
  li    $at, -1
  bne   $t8, $at, .L7F0533EC
   lui   $at, 0x8000
  bne   $t6, $at, .L7F0533EC
   nop   
  break 6
.L7F0533EC:
  lh    $t8, 0xa($t2)
  lh    $v1, 0xa($a2)
  lh    $a1, ($a2)
  subu  $t7, $t8, $v1
  subu  $t6, $t5, $a1
  multu $t6, $t7
  lh    $t8, ($t2)
  subu  $t6, $t8, $a1
  mflo  $t9
  nop   
  nop   
  div   $zero, $t9, $t6
  mflo  $t7
  addu  $t8, $t7, $v1
  bnez  $t6, .L7F053430
   nop   
  break 7
.L7F053430:
  li    $at, -1
  bne   $t6, $at, .L7F053448
   lui   $at, 0x8000
  bne   $t9, $at, .L7F053448
   nop   
  break 6
.L7F053448:
  sh    $t8, 0xa($t3)
  b     .L7F053538
   sh    $t5, ($t3)
  lh    $t9, 2($a3)
.L7F053458:
  bnel  $t9, $a0, .L7F053538
   sh    $t5, ($t3)
  lh    $t6, 4($a3)
  lh    $t7, 4($a2)
  bnel  $t6, $t7, .L7F053538
   sh    $t5, ($t3)
  lh    $a0, ($a3)
  beql  $a0, $a1, .L7F053538
   sh    $t5, ($t3)
  lh    $v0, 8($a2)
  lh    $t9, 8($a3)
  subu  $t8, $t5, $a1
  subu  $t6, $t9, $v0
  multu $t8, $t6
  subu  $t9, $a0, $a1
  mflo  $t7
  nop   
  nop   
  div   $zero, $t7, $t9
  mflo  $t8
  addu  $t6, $t8, $v0
  sh    $t6, 8($t3)
  bnez  $t9, .L7F0534BC
   nop   
  break 7
.L7F0534BC:
  li    $at, -1
  bne   $t9, $at, .L7F0534D4
   lui   $at, 0x8000
  bne   $t7, $at, .L7F0534D4
   nop   
  break 6
.L7F0534D4:
  lh    $t9, 0xa($a3)
  lh    $v1, 0xa($a2)
  lh    $a1, ($a2)
  subu  $t8, $t9, $v1
  subu  $t7, $t5, $a1
  multu $t7, $t8
  lh    $t9, ($a3)
  subu  $t7, $t9, $a1
  mflo  $t6
  nop   
  nop   
  div   $zero, $t6, $t7
  mflo  $t8
  addu  $t9, $t8, $v1
  sh    $t9, 0xa($t3)
  bnez  $t7, .L7F05351C
   nop   
  break 7
.L7F05351C:
  li    $at, -1
  bne   $t7, $at, .L7F053534
   lui   $at, 0x8000
  bne   $t6, $at, .L7F053534
   nop   
  break 6
.L7F053534:
  sh    $t5, ($t3)
.L7F053538:
  bne   $s2, $s4, .L7F052E84
   move  $v1, $s2
  lh    $v0, 0xc($s5)
  addiu $fp, $fp, 4
  bgez  $v0, .L7F053558
   sra   $t6, $v0, 2
  addiu $at, $v0, 3
  sra   $t6, $at, 2
.L7F053558:
  sll   $v1, $t6, 2
  slt   $at, $fp, $v1
  bnezl $at, .L7F052E80
   move  $v1, $zero
.L7F053568:
  lw    $ra, 0x3c($sp)
.L7F05356C:
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  lw    $s3, 0x24($sp)
  lw    $s4, 0x28($sp)
  lw    $s5, 0x2c($sp)
  lw    $s6, 0x30($sp)
  lw    $s7, 0x34($sp)
  lw    $fp, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x58
");

asm(R"
glabel sub_GAME_7F053598
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lw    $a2, 0xf0($a0)
  bltz  $a2, .L7F0535B4
   move  $a0, $a2
  jal   sub_GAME_7F0B9DBC
   li    $a1, 1
.L7F0535B4:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0535C4
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lw    $a2, 0xf0($a0)
  bltz  $a2, .L7F0535E0
   move  $a0, $a2
  jal   sub_GAME_7F0B9DBC
   move  $a1, $zero
.L7F0535E0:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel initialize_door
  addiu $sp, $sp, -0x30
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x14($sp)
  move  $s0, $a0
  sw    $s1, 0x18($sp)
  sw    $a1, 0x34($sp)
  sw    $a2, 0x38($sp)
  jal   sub_GAME_7F04071C
   sw    $a3, 0x3c($sp)
  lh    $t6, 4($s0)
  lui   $at, %hi(PitemZ_entries+8)
  move  $s1, $v0
  sll   $t7, $t6, 2
  subu  $t7, $t7, $t6
  sll   $t7, $t7, 2
  addu  $at, $at, $t7
  lwc1  $f4, %lo(PitemZ_entries+8)($at)
  li    $a0, 80
  li    $a1, 4
  jal   mempAllocBytesInBank
   swc1  $f4, 0x28($sp)
  sw    $v0, 0x68($s0)
  addiu $a1, $s0, 0x18
  sw    $a1, 0x20($sp)
  jal   sub_GAME_7F058020
   lw    $a0, 0x38($sp)
  lw    $a1, 0x20($sp)
  jal   matrix_multiply_A1_by_F12
   lwc1  $f12, 0x28($sp)
  lw    $v0, 0x40($sp)
  lw    $t8, 8($s0)
  mtc1  $zero, $f4
  lwc1  $f6, ($v0)
  sll   $t9, $t8, 0
  swc1  $f6, 0xa8($s0)
  lwc1  $f8, 4($v0)
  swc1  $f8, 0xac($s0)
  lwc1  $f10, 8($v0)
  bgez  $t9, .L7F05369C
   swc1  $f10, 0xb0($s0)
  lwc1  $f16, 0x84($s0)
  b     .L7F0536A8
   swc1  $f16, 0xb4($s0)
.L7F05369C:
  mtc1  $zero, $f18
  nop   
  swc1  $f18, 0xb4($s0)
.L7F0536A8:
  lhu   $t0, 0x98($s0)
  swc1  $f4, 0xb8($s0)
  sb    $zero, 0xbc($s0)
  andi  $t1, $t0, 4
  sb    $zero, 0xbd($s0)
  beqz  $t1, .L7F0536F8
   sw    $zero, 0xc8($s0)
  lw    $t2, 0x14($s0)
  li    $a1, 4
  lw    $t3, 8($t2)
  lw    $t4, ($t3)
  lw    $t5, 0x14($t4)
  lw    $t6, 0x14($t5)
  lw    $v0, 4($t6)
  lh    $a0, 0xc($v0)
  sll   $t7, $a0, 4
  jal   mempAllocBytesInBank
   move  $a0, $t7
  b     .L7F0536FC
   sw    $v0, 0xcc($s0)
.L7F0536F8:
  sw    $zero, 0xcc($s0)
.L7F0536FC:
  lw    $v1, 0x34($sp)
  lw    $v0, 0x44($sp)
  li    $t8, -1
  sw    $t8, 0xf0($s0)
  sw    $zero, 0xf4($s0)
  sw    $zero, 0xf8($s0)
  li    $t9, 2
  sb    $t9, ($s1)
  sw    $s0, 4($s1)
  lwc1  $f6, ($v1)
  move  $a0, $s0
  swc1  $f6, 8($s1)
  lwc1  $f8, 4($v1)
  swc1  $f8, 0xc($s1)
  lwc1  $f10, 8($v1)
  swc1  $f10, 0x10($s1)
  lw    $t0, 0x3c($sp)
  sw    $t0, 0x14($s1)
  lwc1  $f16, ($v0)
  lw    $t1, 8($s0)
  swc1  $f16, 0x58($s0)
  lwc1  $f18, 4($v0)
  ori   $t2, $t1, 0x100
  swc1  $f18, 0x5c($s0)
  lwc1  $f4, 8($v0)
  sw    $t2, 8($s0)
  jal   sub_GAME_7F052B00
   swc1  $f4, 0x60($s0)
  jal   sub_GAME_7F052D8C
   move  $a0, $s0
  lw    $a0, 0x10($s0)
  jal   sub_GAME_7F0402B4
   addiu $a1, $s0, 0x7c
  lbu   $t3, 0x7c($s0)
  lbu   $t4, 0x7d($s0)
  lbu   $t5, 0x7e($s0)
  lbu   $t6, 0x7f($s0)
  sb    $t3, 0x78($s0)
  sb    $t4, 0x79($s0)
  sb    $t5, 0x7a($s0)
  sb    $t6, 0x7b($s0)
  lw    $ra, 0x1c($sp)
  move  $v0, $s1
  lw    $s1, 0x18($sp)
  lw    $s0, 0x14($sp)
  jr    $ra
   addiu $sp, $sp, 0x30
");

asm(R"
glabel sub_GAME_7F0537B8
  li    $at, 0x43480000 # 200.000000
  mtc1  $at, $f0
  addiu $sp, $sp, -0x20
  sdc1  $f20, 0x10($sp)
  c.le.s $f12, $f0
  sw    $a2, 0x28($sp)
  mov.s $f20, $f12
  sw    $ra, 0x1c($sp)
  bc1f  .L7F0537E8
   lwc1  $f4, 0x28($sp)
  b     .L7F053880
   li    $v1, 32767
.L7F0537E8:
  c.le.s $f4, $f20
  nop   
  bc1fl .L7F053804
   c.le.s $f14, $f20
  b     .L7F053880
   move  $v1, $zero
  c.le.s $f14, $f20
.L7F053804:
  lwc1  $f6, 0x28($sp)
  lui   $at, %hi(D_80053340)
  bc1fl .L7F05383C
   sub.s $f12, $f20, $f0
  sub.s $f8, $f6, $f20
  lwc1  $f10, %lo(D_80053340)($at)
  sub.s $f18, $f6, $f14
  mul.s $f16, $f8, $f10
  div.s $f4, $f16, $f18
  trunc.w.s $f8, $f4
  mfc1  $v1, $f8
  b     .L7F053884
   lw    $ra, 0x1c($sp)
  sub.s $f12, $f20, $f0
.L7F05383C:
  jal   sqrtf
   swc1  $f14, 0x24($sp)
  li    $at, 0x43480000 # 200.000000
  mtc1  $at, $f10
  lwc1  $f14, 0x24($sp)
  mov.s $f20, $f0
  jal   sqrtf
   sub.s $f12, $f14, $f10
  lui   $at, %hi(D_80053344)
  lwc1  $f6, %lo(D_80053344)($at)
  li    $t9, 32767
  mul.s $f16, $f20, $f6
  div.s $f18, $f16, $f0
  trunc.w.s $f4, $f18
  mfc1  $t8, $f4
  nop   
  subu  $v1, $t9, $t8
.L7F053880:
  lw    $ra, 0x1c($sp)
.L7F053884:
  ldc1  $f20, 0x10($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   move  $v0, $v1
");

asm(R"
glabel sub_GAME_7F053894
  addiu $sp, $sp, -0x30
  sw    $ra, 0x2c($sp)
  sw    $s1, 0x20($sp)
  sdc1  $f20, 0x10($sp)
  sw    $a2, 0x38($sp)
  move  $s1, $a0
  sw    $s3, 0x28($sp)
  sw    $s2, 0x24($sp)
  sw    $s0, 0x1c($sp)
  sw    $a1, 0x34($sp)
  jal   getPlayerCount
   lwc1  $f20, 0x38($sp)
  blez  $v0, .L7F05393C
   lui   $t6, %hi(players_p1)
  addiu $s0, $t6, %lo(players_p1)
  sll   $t7, $v0, 2
  addu  $s2, $t7, $s0
  lw    $t8, ($s0)
.L7F0538DC:
  lwc1  $f6, ($s1)
  lwc1  $f10, 4($s1)
  lw    $v0, 0xa8($t8)
  lwc1  $f18, 8($s1)
  lwc1  $f4, 8($v0)
  lwc1  $f8, 0xc($v0)
  lwc1  $f16, 0x10($v0)
  sub.s $f0, $f4, $f6
  sub.s $f2, $f8, $f10
  mul.s $f4, $f0, $f0
  sub.s $f14, $f16, $f18
  mul.s $f6, $f2, $f2
  add.s $f8, $f4, $f6
  mul.s $f10, $f14, $f14
  jal   sqrtf
   add.s $f12, $f8, $f10
  c.lt.s $f0, $f20
  addiu $s0, $s0, 4
  sltu  $at, $s0, $s2
  bc1f  .L7F053934
   nop   
  mov.s $f20, $f0
.L7F053934:
  bnezl $at, .L7F0538DC
   lw    $t8, ($s0)
.L7F05393C:
  mov.s $f12, $f20
  lwc1  $f14, 0x34($sp)
  jal   sub_GAME_7F0537B8
   lw    $a2, 0x38($sp)
  lw    $ra, 0x2c($sp)
  ldc1  $f20, 0x10($sp)
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  lw    $s2, 0x24($sp)
  lw    $s3, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x30
");

asm(R"
glabel sub_GAME_7F05396C
  mtc1  $a2, $f12
  mtc1  $a3, $f14
  addiu $sp, $sp, -0x18
  sw    $a0, 0x18($sp)
  sw    $a1, 0x1c($sp)
  move  $a0, $a1
  sw    $ra, 0x14($sp)
  mfc1  $a1, $f12
  mfc1  $a2, $f14
  jal   sub_GAME_7F053894
   nop   
  lw    $a0, 0x18($sp)
  li    $a1, 8
  jal   sfx_c_70009184
   move  $a2, $v0
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0539B8
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lui   $at, %hi(D_80053348)
  lui   $a2, (0x45BB8000 >> 16) # lui $a2, 0x45bb
  ori   $a2, (0x45BB8000 & 0xFFFF) # ori $a2, $a2, 0x8000
  jal   sub_GAME_7F0537B8
   lwc1  $f14, %lo(D_80053348)($at)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0539E4
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lui   $a1, (0x459C4000 >> 16) # lui $a1, 0x459c
  lui   $a2, (0x45BB8000 >> 16) # lui $a2, 0x45bb
  ori   $a2, (0x45BB8000 & 0xFFFF) # ori $a2, $a2, 0x8000
  jal   sub_GAME_7F053894
   ori   $a1, (0x459C4000 & 0xFFFF) # ori $a1, $a1, 0x4000
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F053A10
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lui   $a2, (0x459C4000 >> 16) # lui $a2, 0x459c
  lui   $a3, (0x45BB8000 >> 16) # lui $a3, 0x45bb
  ori   $a3, (0x45BB8000 & 0xFFFF) # ori $a3, $a3, 0x8000
  jal   sub_GAME_7F05396C
   ori   $a2, (0x459C4000 & 0xFFFF) # ori $a2, $a2, 0x4000
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F053A3C
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  sw    $a0, 0x28($sp)
  lw    $a1, 0xf4($a0)
  sltu  $v1, $zero, $a1
  beql  $v1, $zero, .L7F053A68
   lw    $t7, 0x28($sp)
  jal   sfxGetArg0Unk3F
   move  $a0, $a1
  sltu  $v1, $zero, $v0
  lw    $t7, 0x28($sp)
.L7F053A68:
  sw    $v1, 0x24($sp)
  lw    $a0, 0xf8($t7)
  sltu  $v1, $zero, $a0
  beql  $v1, $zero, .L7F053A8C
   lw    $t8, 0x24($sp)
  jal   sfxGetArg0Unk3F
   nop   
  sltu  $v1, $zero, $v0
  lw    $t8, 0x24($sp)
.L7F053A8C:
  lw    $t9, 0x28($sp)
  bnezl $t8, .L7F053AA4
   lw    $a0, 0x10($t9)
  beql  $v1, $zero, .L7F053B04
   lw    $ra, 0x14($sp)
  lw    $a0, 0x10($t9)
.L7F053AA4:
  sw    $v1, 0x18($sp)
  jal   sub_GAME_7F0539E4
   addiu $a0, $a0, 8
  jal   get_controls_locked_flag
   sw    $v0, 0x1c($sp)
  beqz  $v0, .L7F053AC4
   lw    $v1, 0x18($sp)
  sw    $zero, 0x1c($sp)
.L7F053AC4:
  lw    $t0, 0x24($sp)
  lw    $t1, 0x28($sp)
  li    $a1, 8
  beqz  $t0, .L7F053AE8
   lw    $a2, 0x1c($sp)
  lw    $a0, 0xf4($t1)
  jal   sfx_c_70009184
   sw    $v1, 0x18($sp)
  lw    $v1, 0x18($sp)
.L7F053AE8:
  beqz  $v1, .L7F053B00
   lw    $t2, 0x28($sp)
  lw    $a0, 0xf8($t2)
  li    $a1, 8
  jal   sfx_c_70009184
   lw    $a2, 0x1c($sp)
.L7F053B00:
  lw    $ra, 0x14($sp)
.L7F053B04:
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F053B10
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  lw    $a1, 0xf4($a0)
  beql  $a1, $zero, .L7F053B44
   lw    $t8, 0x18($sp)
  jal   sfxGetArg0Unk3F
   move  $a0, $a1
  beqz  $v0, .L7F053B40
   lw    $t7, 0x18($sp)
  jal   sfxDeactivate
   lw    $a0, 0xf4($t7)
.L7F053B40:
  lw    $t8, 0x18($sp)
.L7F053B44:
  lw    $a0, 0xf8($t8)
  beql  $a0, $zero, .L7F053B6C
   lw    $ra, 0x14($sp)
  jal   sfxGetArg0Unk3F
   nop   
  beqz  $v0, .L7F053B68
   lw    $t9, 0x18($sp)
  jal   sfxDeactivate
   lw    $a0, 0xf8($t9)
.L7F053B68:
  lw    $ra, 0x14($sp)
.L7F053B6C:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
.late_rodata
/*D:8005334C*/
glabel door_opening_sound_table_0
.word .L7F053BEC
.word .L7F053C2C
.word .L7F053C6C
.word .L7F053CAC
.word .L7F053CEC
.word .L7F053D08
.word .L7F053D24
.word .L7F053D64
.word .L7F053DA4
.word .L7F053DC4
.word .L7F053DE0
.word .L7F053DFC
.word .L7F053E18
.word .L7F053E58
.word .L7F053E78
.word .L7F053E98
.word .L7F053EB4

.text
glabel play_door_opening_soundeffect_0
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a0, 0x20($sp)
  sw    $zero, 0x1c($sp)
  jal   sub_GAME_7F053B10
   sw    $zero, 0x18($sp)
  lw    $t6, 0x20($sp)
  lw    $a3, 0x18($sp)
  lw    $t8, 0x20($sp)
  lw    $t7, 0xf4($t6)
  lw    $t0, 0x20($sp)
  bnezl $t7, .L7F053BB8
   lw    $t9, 0xf8($t8)
  b     .L7F053BC4
   addiu $a3, $t6, 0xf4
  lw    $t9, 0xf8($t8)
.L7F053BB8:
  bnezl $t9, .L7F053BC8
   lw    $t1, 0xa4($t0)
  addiu $a3, $t8, 0xf8
.L7F053BC4:
  lw    $t1, 0xa4($t0)
.L7F053BC8:
  addiu $t2, $t1, -1
  sltiu $at, $t2, 0x11
  beqz  $at, .L7F053F2C
   sll   $t2, $t2, 2
  lui   $at, %hi(door_opening_sound_table_0)
  addu  $at, $at, $t2
  lw    $t2, %lo(door_opening_sound_table_0)($at)
  jr    $t2
   nop   
.L7F053BEC:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 210
  move  $a2, $zero
  jal   play_sfx_a1
   sw    $a3, 0x18($sp)
  lw    $a3, 0x18($sp)
  sw    $v0, 0x1c($sp)
  lui   $a0, %hi(ptr_sfx_buf)
  beqz  $a3, .L7F053F2C
   li    $a1, 211
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   move  $a2, $a3
  b     .L7F053F30
   lw    $t4, 0x1c($sp)
.L7F053C2C:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 210
  move  $a2, $zero
  jal   play_sfx_a1
   sw    $a3, 0x18($sp)
  lw    $a3, 0x18($sp)
  sw    $v0, 0x1c($sp)
  lui   $a0, %hi(ptr_sfx_buf)
  beqz  $a3, .L7F053F2C
   li    $a1, 7
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   move  $a2, $a3
  b     .L7F053F30
   lw    $t4, 0x1c($sp)
.L7F053C6C:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 202
  move  $a2, $zero
  jal   play_sfx_a1
   sw    $a3, 0x18($sp)
  lw    $a3, 0x18($sp)
  sw    $v0, 0x1c($sp)
  lui   $a0, %hi(ptr_sfx_buf)
  beqz  $a3, .L7F053F2C
   li    $a1, 204
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   move  $a2, $a3
  b     .L7F053F30
   lw    $t4, 0x1c($sp)
.L7F053CAC:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 214
  move  $a2, $zero
  jal   play_sfx_a1
   sw    $a3, 0x18($sp)
  lw    $a3, 0x18($sp)
  sw    $v0, 0x1c($sp)
  lui   $a0, %hi(ptr_sfx_buf)
  beqz  $a3, .L7F053F2C
   li    $a1, 216
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   move  $a2, $a3
  b     .L7F053F30
   lw    $t4, 0x1c($sp)
.L7F053CEC:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 188
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F053F2C
   sw    $v0, 0x1c($sp)
.L7F053D08:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 7
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F053F2C
   sw    $v0, 0x1c($sp)
.L7F053D24:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 192
  move  $a2, $zero
  jal   play_sfx_a1
   sw    $a3, 0x18($sp)
  lw    $a3, 0x18($sp)
  sw    $v0, 0x1c($sp)
  lui   $a0, %hi(ptr_sfx_buf)
  beqz  $a3, .L7F053F2C
   li    $a1, 191
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   move  $a2, $a3
  b     .L7F053F30
   lw    $t4, 0x1c($sp)
.L7F053D64:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 188
  move  $a2, $zero
  jal   play_sfx_a1
   sw    $a3, 0x18($sp)
  lw    $a3, 0x18($sp)
  sw    $v0, 0x1c($sp)
  lui   $a0, %hi(ptr_sfx_buf)
  beqz  $a3, .L7F053F2C
   li    $a1, 7
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   move  $a2, $a3
  b     .L7F053F30
   lw    $t4, 0x1c($sp)
.L7F053DA4:
  beqz  $a3, .L7F053F2C
   lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 194
  jal   play_sfx_a1
   move  $a2, $a3
  b     .L7F053F30
   lw    $t4, 0x1c($sp)
.L7F053DC4:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 196
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F053F2C
   sw    $v0, 0x1c($sp)
.L7F053DE0:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 7
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F053F2C
   sw    $v0, 0x1c($sp)
.L7F053DFC:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 200
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F053F2C
   sw    $v0, 0x1c($sp)
.L7F053E18:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 7
  move  $a2, $zero
  jal   play_sfx_a1
   sw    $a3, 0x18($sp)
  lw    $a3, 0x18($sp)
  sw    $v0, 0x1c($sp)
  lui   $a0, %hi(ptr_sfx_buf)
  beqz  $a3, .L7F053F2C
   li    $a1, 7
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   move  $a2, $a3
  b     .L7F053F30
   lw    $t4, 0x1c($sp)
.L7F053E58:
  beqz  $a3, .L7F053F2C
   lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 218
  jal   play_sfx_a1
   move  $a2, $a3
  b     .L7F053F30
   lw    $t4, 0x1c($sp)
.L7F053E78:
  beqz  $a3, .L7F053F2C
   lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 225
  jal   play_sfx_a1
   move  $a2, $a3
  b     .L7F053F30
   lw    $t4, 0x1c($sp)
.L7F053E98:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 214
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F053F2C
   sw    $v0, 0x1c($sp)
.L7F053EB4:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 7
  move  $a2, $zero
  jal   play_sfx_a1
   sw    $a3, 0x18($sp)
  lw    $a3, 0x18($sp)
  beqz  $v0, .L7F053EF4
   sw    $v0, 0x1c($sp)
  lw    $t3, 0x20($sp)
  move  $a0, $v0
  lw    $a1, 0x10($t3)
  sw    $a3, 0x18($sp)
  jal   sub_GAME_7F053A10
   addiu $a1, $a1, 8
  lw    $a3, 0x18($sp)
.L7F053EF4:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 202
  move  $a2, $zero
  jal   play_sfx_a1
   sw    $a3, 0x18($sp)
  lw    $a3, 0x18($sp)
  sw    $v0, 0x1c($sp)
  lui   $a0, %hi(ptr_sfx_buf)
  beqz  $a3, .L7F053F2C
   li    $a1, 204
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   move  $a2, $a3
def_7F053BE4:
.L7F053F2C:
  lw    $t4, 0x1c($sp)
.L7F053F30:
  lw    $t5, 0x20($sp)
  beqz  $t4, .L7F053F4C
   nop   
  lw    $a1, 0x10($t5)
  move  $a0, $t4
  jal   sub_GAME_7F053A10
   addiu $a1, $a1, 8
.L7F053F4C:
  jal   sub_GAME_7F053A3C
   lw    $a0, 0x20($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
.late_rodata
/*D:80053390*/
glabel door_opening_sound_table_1
.word .L7F053FD8
.word .L7F054018
.word .L7F054058
.word .L7F054098
.word .L7F05428C
.word .L7F05428C
.word .L7F0540D8
.word .L7F054118
.word .L7F054158
.word .L7F05428C
.word .L7F05428C
.word .L7F05428C
.word .L7F054178
.word .L7F0541B8
.word .L7F0541D8
.word .L7F0541F8
.word .L7F054214
.text
glabel play_door_opening_soundeffect_1
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a0, 0x20($sp)
  sw    $zero, 0x1c($sp)
  jal   sub_GAME_7F053B10
   sw    $zero, 0x18($sp)
  lw    $t6, 0x20($sp)
  lw    $a3, 0x18($sp)
  lw    $t8, 0x20($sp)
  lw    $t7, 0xf4($t6)
  lw    $t0, 0x20($sp)
  bnezl $t7, .L7F053FA4
   lw    $t9, 0xf8($t8)
  b     .L7F053FB0
   addiu $a3, $t6, 0xf4
  lw    $t9, 0xf8($t8)
.L7F053FA4:
  bnezl $t9, .L7F053FB4
   lw    $t1, 0xa4($t0)
  addiu $a3, $t8, 0xf8
.L7F053FB0:
  lw    $t1, 0xa4($t0)
.L7F053FB4:
  addiu $t2, $t1, -1
  sltiu $at, $t2, 0x11
  beqz  $at, .L7F05428C
   sll   $t2, $t2, 2
  lui   $at, %hi(door_opening_sound_table_1)
  addu  $at, $at, $t2
  lw    $t2, %lo(door_opening_sound_table_1)($at)
.L7F053FD0:
  jr    $t2
   nop   
.L7F053FD8:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 210
  move  $a2, $zero
  jal   play_sfx_a1
   sw    $a3, 0x18($sp)
  lw    $a3, 0x18($sp)
  sw    $v0, 0x1c($sp)
  lui   $a0, %hi(ptr_sfx_buf)
  beqz  $a3, .L7F05428C
   li    $a1, 211
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   move  $a2, $a3
  b     .L7F054290
   lw    $t4, 0x1c($sp)
.L7F054018:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 210
  move  $a2, $zero
  jal   play_sfx_a1
   sw    $a3, 0x18($sp)
  lw    $a3, 0x18($sp)
  sw    $v0, 0x1c($sp)
  lui   $a0, %hi(ptr_sfx_buf)
  beqz  $a3, .L7F05428C
   li    $a1, 7
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   move  $a2, $a3
  b     .L7F054290
   lw    $t4, 0x1c($sp)
.L7F054058:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 202
  move  $a2, $zero
  jal   play_sfx_a1
   sw    $a3, 0x18($sp)
  lw    $a3, 0x18($sp)
  sw    $v0, 0x1c($sp)
  lui   $a0, %hi(ptr_sfx_buf)
  beqz  $a3, .L7F05428C
   li    $a1, 204
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   move  $a2, $a3
  b     .L7F054290
   lw    $t4, 0x1c($sp)
.L7F054098:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 214
  move  $a2, $zero
  jal   play_sfx_a1
   sw    $a3, 0x18($sp)
  lw    $a3, 0x18($sp)
  sw    $v0, 0x1c($sp)
  lui   $a0, %hi(ptr_sfx_buf)
  beqz  $a3, .L7F05428C
   li    $a1, 216
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   move  $a2, $a3
  b     .L7F054290
   lw    $t4, 0x1c($sp)
.L7F0540D8:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 192
  move  $a2, $zero
  jal   play_sfx_a1
   sw    $a3, 0x18($sp)
  lw    $a3, 0x18($sp)
  sw    $v0, 0x1c($sp)
  lui   $a0, %hi(ptr_sfx_buf)
  beqz  $a3, .L7F05428C
   li    $a1, 191
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   move  $a2, $a3
  b     .L7F054290
   lw    $t4, 0x1c($sp)
.L7F054118:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 188
  move  $a2, $zero
  jal   play_sfx_a1
   sw    $a3, 0x18($sp)
  lw    $a3, 0x18($sp)
  sw    $v0, 0x1c($sp)
  lui   $a0, %hi(ptr_sfx_buf)
  beqz  $a3, .L7F05428C
   li    $a1, 7
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   move  $a2, $a3
  b     .L7F054290
   lw    $t4, 0x1c($sp)
.L7F054158:
  beqz  $a3, .L7F05428C
   lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 194
  jal   play_sfx_a1
   move  $a2, $a3
  b     .L7F054290
   lw    $t4, 0x1c($sp)
.L7F054178:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 7
  move  $a2, $zero
  jal   play_sfx_a1
   sw    $a3, 0x18($sp)
  lw    $a3, 0x18($sp)
  sw    $v0, 0x1c($sp)
  lui   $a0, %hi(ptr_sfx_buf)
  beqz  $a3, .L7F05428C
   li    $a1, 7
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   move  $a2, $a3
  b     .L7F054290
   lw    $t4, 0x1c($sp)
.L7F0541B8:
  beqz  $a3, .L7F05428C
   lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 218
  jal   play_sfx_a1
   move  $a2, $a3
  b     .L7F054290
   lw    $t4, 0x1c($sp)
.L7F0541D8:
  beqz  $a3, .L7F05428C
   lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 225
  jal   play_sfx_a1
   move  $a2, $a3
  b     .L7F054290
   lw    $t4, 0x1c($sp)
.L7F0541F8:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 214
  jal   play_sfx_a1
   move  $a2, $zero
  b     .L7F05428C
   sw    $v0, 0x1c($sp)
.L7F054214:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 7
  move  $a2, $zero
  jal   play_sfx_a1
   sw    $a3, 0x18($sp)
  lw    $a3, 0x18($sp)
  beqz  $v0, .L7F054254
   sw    $v0, 0x1c($sp)
  lw    $t3, 0x20($sp)
  move  $a0, $v0
  lw    $a1, 0x10($t3)
  sw    $a3, 0x18($sp)
  jal   sub_GAME_7F053A10
   addiu $a1, $a1, 8
  lw    $a3, 0x18($sp)
.L7F054254:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 202
  move  $a2, $zero
  jal   play_sfx_a1
   sw    $a3, 0x18($sp)
  lw    $a3, 0x18($sp)
  sw    $v0, 0x1c($sp)
  lui   $a0, %hi(ptr_sfx_buf)
  beqz  $a3, .L7F05428C
   li    $a1, 204
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   move  $a2, $a3
def_7F053FD0:
.L7F05428C:
  lw    $t4, 0x1c($sp)
.L7F054290:
  lw    $t5, 0x20($sp)
  beqz  $t4, .L7F0542AC
   nop   
  lw    $a1, 0x10($t5)
  move  $a0, $t4
  jal   sub_GAME_7F053A10
   addiu $a1, $a1, 8
.L7F0542AC:
  jal   sub_GAME_7F053A3C
   lw    $a0, 0x20($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
.late_rodata
/*D:800533D4*/
glabel door_closing_sound_table_0
.word .L7F054308
.word .L7F054328
.word .L7F054348
.word .L7F054368
.word .L7F054484
.word .L7F054484
.word .L7F054388
.word .L7F0543A8
.word .L7F0543C8
.word .L7F054484
.word .L7F054484
.word .L7F054484
.word .L7F0543E8
.word .L7F054408
.word .L7F054428
.word .L7F054448
.word .L7F054468
.text
glabel play_door_closing_soundeffect_0
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a0, 0x20($sp)
  jal   sub_GAME_7F053B10
   sw    $zero, 0x1c($sp)
  lw    $a3, 0x20($sp)
  lw    $a2, 0x1c($sp)
  lw    $t6, 0xa4($a3)
  addiu $t7, $t6, -1
  sltiu $at, $t7, 0x11
  beqz  $at, .L7F054484
   sll   $t7, $t7, 2
  lui   $at, %hi(door_closing_sound_table_0)
  addu  $at, $at, $t7
  lw    $t7, %lo(door_closing_sound_table_0)($at)
.L7F054300:
  jr    $t7
   nop   
.L7F054308:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 210
  jal   play_sfx_a1
   move  $a2, $zero
  move  $a2, $v0
  b     .L7F054484
   lw    $a3, 0x20($sp)
.L7F054328:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 210
  jal   play_sfx_a1
   move  $a2, $zero
  move  $a2, $v0
  b     .L7F054484
   lw    $a3, 0x20($sp)
.L7F054348:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 203
  jal   play_sfx_a1
   move  $a2, $zero
  move  $a2, $v0
  b     .L7F054484
   lw    $a3, 0x20($sp)
.L7F054368:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 215
  jal   play_sfx_a1
   move  $a2, $zero
  move  $a2, $v0
  b     .L7F054484
   lw    $a3, 0x20($sp)
.L7F054388:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 210
  jal   play_sfx_a1
   move  $a2, $zero
  move  $a2, $v0
  b     .L7F054484
   lw    $a3, 0x20($sp)
.L7F0543A8:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 187
  jal   play_sfx_a1
   move  $a2, $zero
  move  $a2, $v0
  b     .L7F054484
   lw    $a3, 0x20($sp)
.L7F0543C8:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 195
  jal   play_sfx_a1
   move  $a2, $zero
  move  $a2, $v0
  b     .L7F054484
   lw    $a3, 0x20($sp)
.L7F0543E8:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 7
  jal   play_sfx_a1
   move  $a2, $zero
  move  $a2, $v0
  b     .L7F054484
   lw    $a3, 0x20($sp)
.L7F054408:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 219
  jal   play_sfx_a1
   move  $a2, $zero
  move  $a2, $v0
  b     .L7F054484
   lw    $a3, 0x20($sp)
.L7F054428:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 226
  jal   play_sfx_a1
   move  $a2, $zero
  move  $a2, $v0
  b     .L7F054484
   lw    $a3, 0x20($sp)
.L7F054448:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 215
  jal   play_sfx_a1
   move  $a2, $zero
  move  $a2, $v0
  b     .L7F054484
   lw    $a3, 0x20($sp)
.L7F054468:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 203
  jal   play_sfx_a1
   move  $a2, $zero
  move  $a2, $v0
  lw    $a3, 0x20($sp)
def_7F054300:
.L7F054484:
  beqz  $a2, .L7F0544A0
   nop   
  lw    $a1, 0x10($a3)
  move  $a0, $a2
  jal   sub_GAME_7F053A10
   addiu $a1, $a1, 8
  lw    $a3, 0x20($sp)
.L7F0544A0:
  jal   sub_GAME_7F053A3C
   move  $a0, $a3
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
.late_rodata
/*D:80053418*/
glabel door_closing_sound_table_1
.word .L7F0544FC
.word .L7F05451C
.word .L7F05453C
.word .L7F05455C
.word .L7F05457C
.word .L7F05459C
.word .L7F0545BC
.word .L7F0545DC
.word .L7F0545FC
.word .L7F05461C
.word .L7F05463C
.word .L7F05465C
.word .L7F05467C
.word .L7F05469C
.word .L7F0546BC
.word .L7F0546DC
.word .L7F0546FC

.text
glabel play_door_closing_soundeffect_1
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a0, 0x20($sp)
  jal   sub_GAME_7F053B10
   sw    $zero, 0x1c($sp)
  lw    $a3, 0x20($sp)
  lw    $a2, 0x1c($sp)
  lw    $t6, 0xa4($a3)
  addiu $t7, $t6, -1
  sltiu $at, $t7, 0x11
  beqz  $at, .L7F054718
   sll   $t7, $t7, 2
  lui   $at, %hi(door_closing_sound_table_1)
  addu  $at, $at, $t7
  lw    $t7, %lo(door_closing_sound_table_1)($at)
  jr    $t7
   nop   
.L7F0544FC:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 210
  jal   play_sfx_a1
   move  $a2, $zero
  move  $a2, $v0
  b     .L7F054718
   lw    $a3, 0x20($sp)
.L7F05451C:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 210
  jal   play_sfx_a1
   move  $a2, $zero
  move  $a2, $v0
  b     .L7F054718
   lw    $a3, 0x20($sp)
.L7F05453C:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 203
  jal   play_sfx_a1
   move  $a2, $zero
  move  $a2, $v0
  b     .L7F054718
   lw    $a3, 0x20($sp)
.L7F05455C:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 215
  jal   play_sfx_a1
   move  $a2, $zero
  move  $a2, $v0
  b     .L7F054718
   lw    $a3, 0x20($sp)
.L7F05457C:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 187
  jal   play_sfx_a1
   move  $a2, $zero
  move  $a2, $v0
  b     .L7F054718
   lw    $a3, 0x20($sp)
.L7F05459C:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 7
  jal   play_sfx_a1
   move  $a2, $zero
  move  $a2, $v0
  b     .L7F054718
   lw    $a3, 0x20($sp)
.L7F0545BC:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 210
  jal   play_sfx_a1
   move  $a2, $zero
  move  $a2, $v0
  b     .L7F054718
   lw    $a3, 0x20($sp)
.L7F0545DC:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 187
  jal   play_sfx_a1
   move  $a2, $zero
  move  $a2, $v0
  b     .L7F054718
   lw    $a3, 0x20($sp)
.L7F0545FC:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 195
  jal   play_sfx_a1
   move  $a2, $zero
  move  $a2, $v0
  b     .L7F054718
   lw    $a3, 0x20($sp)
.L7F05461C:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 197
  jal   play_sfx_a1
   move  $a2, $zero
  move  $a2, $v0
  b     .L7F054718
   lw    $a3, 0x20($sp)
.L7F05463C:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 199
  jal   play_sfx_a1
   move  $a2, $zero
  move  $a2, $v0
  b     .L7F054718
   lw    $a3, 0x20($sp)
.L7F05465C:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 201
  jal   play_sfx_a1
   move  $a2, $zero
  move  $a2, $v0
  b     .L7F054718
   lw    $a3, 0x20($sp)
.L7F05467C:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 7
  jal   play_sfx_a1
   move  $a2, $zero
  move  $a2, $v0
  b     .L7F054718
   lw    $a3, 0x20($sp)
.L7F05469C:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 219
  jal   play_sfx_a1
   move  $a2, $zero
  move  $a2, $v0
  b     .L7F054718
   lw    $a3, 0x20($sp)
.L7F0546BC:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 226
  jal   play_sfx_a1
   move  $a2, $zero
  move  $a2, $v0
  b     .L7F054718
   lw    $a3, 0x20($sp)
.L7F0546DC:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 215
  jal   play_sfx_a1
   move  $a2, $zero
  move  $a2, $v0
  b     .L7F054718
   lw    $a3, 0x20($sp)
.L7F0546FC:
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  li    $a1, 203
  jal   play_sfx_a1
   move  $a2, $zero
  move  $a2, $v0
  lw    $a3, 0x20($sp)
def_7F0544F4:
.L7F054718:
  beqz  $a2, .L7F054734
   nop   
  lw    $a1, 0x10($a3)
  move  $a0, $a2
  jal   sub_GAME_7F053A10
   addiu $a1, $a1, 8
  lw    $a3, 0x20($sp)
.L7F054734:
  jal   sub_GAME_7F053A3C
   move  $a0, $a3
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F05474C
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lw    $t6, 8($a0)
  lw    $t8, 0x64($a0)
  lui   $at, (0x7FFFFFFF >> 16) # lui $at, 0x7fff
  ori   $at, (0x7FFFFFFF & 0xFFFF) # ori $at, $at, 0xffff
  and   $t7, $t6, $at
  ori   $t9, $t8, 0x200
  sw    $t7, 8($a0)
  sw    $t9, 0x64($a0)
  jal   play_door_opening_soundeffect_0
   sw    $a0, 0x18($sp)
  jal   sub_GAME_7F053598
   lw    $a0, 0x18($sp)
  lw    $a0, 0x18($sp)
  li    $at, 8
  lhu   $t0, 0x9a($a0)
  bnel  $t0, $at, .L7F0547D0
   lw    $ra, 0x14($sp)
  lw    $t1, 8($a0)
  lw    $v0, 0x68($a0)
  mtc1  $zero, $f4
  lui   $at, 0x200
  or    $t2, $t1, $at
  sw    $t2, 8($a0)
  beqz  $v0, .L7F0547BC
   swc1  $f4, 0x88($a0)
  sw    $zero, ($v0)
.L7F0547BC:
  lw    $t3, 8($a0)
  li    $at, -257
  and   $t4, $t3, $at
  sw    $t4, 8($a0)
  lw    $ra, 0x14($sp)
.L7F0547D0:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0547DC
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lw    $t6, 8($a0)
  lui   $at, (0x7FFFFFFF >> 16) # lui $at, 0x7fff
  ori   $at, (0x7FFFFFFF & 0xFFFF) # ori $at, $at, 0xffff
  and   $t7, $t6, $at
  jal   play_door_opening_soundeffect_1
   sw    $t7, 8($a0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F05480C
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   play_door_closing_soundeffect_0
   sw    $a0, 0x18($sp)
  lw    $a1, 0x18($sp)
  li    $at, 8
  lhu   $t6, 0x9a($a1)
  bnel  $t6, $at, .L7F054870
   lw    $ra, 0x14($sp)
  lw    $a0, 0x10($a1)
  jal   sub_GAME_7F03FDA8
   sw    $a1, 0x18($sp)
  lw    $a1, 0x18($sp)
  lw    $t7, 0x64($a1)
  andi  $t8, $t7, 0x80
  beql  $t8, $zero, .L7F054870
   lw    $ra, 0x14($sp)
  lw    $v0, 0x6c($a1)
  lw    $t9, ($v0)
  ori   $t0, $t9, 1
  sw    $t0, ($v0)
  lw    $a0, 0x6c($a1)
  jal   reset_array_of_0x10_floats
   addiu $a0, $a0, 0x20
  lw    $ra, 0x14($sp)
.L7F054870:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F05487C
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   play_door_closing_soundeffect_1
   sw    $a0, 0x18($sp)
  jal   sub_GAME_7F0535C4
   lw    $a0, 0x18($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0548A4
  addiu $sp, $sp, -0x18
  li    $at, 1
  bne   $a1, $at, .L7F0548E8
   sw    $ra, 0x14($sp)
  lb    $v0, 0xbc($a0)
  li    $at, 3
  beql  $v0, $zero, .L7F0548D0
   sw    $a0, 0x18($sp)
  bne   $v0, $at, .L7F0548E0
   nop   
  sw    $a0, 0x18($sp)
.L7F0548D0:
  jal   sub_GAME_7F05474C
   sw    $a1, 0x1c($sp)
  lw    $a0, 0x18($sp)
  lw    $a1, 0x1c($sp)
.L7F0548E0:
  b     .L7F054978
   sb    $a1, 0xbc($a0)
.L7F0548E8:
  li    $at, 2
  bnel  $a1, $at, .L7F054978
   sb    $a1, 0xbc($a0)
  lb    $v0, 0xbc($a0)
  bnez  $v0, .L7F054930
   nop   
  mtc1  $zero, $f4
  lwc1  $f6, 0xb4($a0)
  c.lt.s $f4, $f6
  nop   
  bc1f  .L7F054930
   nop   
  sw    $a0, 0x18($sp)
  jal   sub_GAME_7F0547DC
   sw    $a1, 0x1c($sp)
  lw    $a0, 0x18($sp)
  lw    $a1, 0x1c($sp)
  lb    $v0, 0xbc($a0)
.L7F054930:
  beqz  $v0, .L7F054940
   li    $at, 3
  bne   $v0, $at, .L7F05495C
   nop   
.L7F054940:
  mtc1  $zero, $f8
  lwc1  $f10, 0xb4($a0)
  li    $at, 3
  c.lt.s $f8, $f10
  nop   
  bc1f  .L7F054964
   nop   
.L7F05495C:
  b     .L7F054978
   sb    $a1, 0xbc($a0)
.L7F054964:
  bnel  $v0, $at, .L7F05497C
   lw    $ra, 0x14($sp)
  b     .L7F054978
   sb    $zero, 0xbc($a0)
  sb    $a1, 0xbc($a0)
.L7F054978:
  lw    $ra, 0x14($sp)
.L7F05497C:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel set_door_state
  addiu $sp, $sp, -0x28
  sw    $ra, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  lw    $t6, 0xc($a0)
  move  $s1, $a0
  move  $s2, $a1
  sll   $t7, $t6, 1
  bgez  $t7, .L7F0549D0
   li    $at, 1
  bne   $a1, $at, .L7F0549D0
   nop   
  lb    $t8, 0xbc($a0)
  li    $s2, 2
  bnez  $t8, .L7F0549D0
   nop   
  li    $a1, 3
.L7F0549D0:
  jal   sub_GAME_7F0548A4
   move  $a0, $s1
  lw    $s0, 0xc8($s1)
  beql  $s0, $zero, .L7F054A0C
   lw    $ra, 0x24($sp)
  beq   $s0, $s1, .L7F054A08
   move  $a0, $s0
.L7F0549EC:
  jal   sub_GAME_7F0548A4
   move  $a1, $s2
  lw    $s0, 0xc8($s0)
  beql  $s0, $zero, .L7F054A0C
   lw    $ra, 0x24($sp)
  bnel  $s0, $s1, .L7F0549EC
   move  $a0, $s0
.L7F054A08:
  lw    $ra, 0x24($sp)
.L7F054A0C:
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
glabel sub_GAME_7F054A20
  lb    $v1, 0xbc($a0)
  sltiu $v0, $v1, 1
  bnez  $v0, .L7F054A3C
   xori  $v0, $v1, 3
  sltiu $v0, $v0, 1
  beqz  $v0, .L7F054A5C
   nop   
.L7F054A3C:
  mtc1  $zero, $f4
  lwc1  $f6, 0xb4($a0)
  move  $v0, $zero
  c.le.s $f6, $f4
  nop   
  bc1f  .L7F054A5C
   nop   
  li    $v0, 1
.L7F054A5C:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F054A64
  addiu $sp, $sp, -0x68
  sw    $s3, 0x20($sp)
  sw    $s0, 0x14($sp)
  move  $s0, $a1
  addiu $s3, $sp, 0x48
  sw    $ra, 0x24($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  move  $s2, $zero
  jal   sub_GAME_7F03CB8C
   move  $a1, $s3
  lw    $a0, 0x48($sp)
  move  $s1, $s3
  addiu $s3, $sp, 0x2c
  bltzl $a0, .L7F054B64
   lw    $ra, 0x24($sp)
.L7F054AA4:
  jal   sub_GAME_7F0B3C0C
   move  $a1, $s3
  beqz  $v0, .L7F054B50
   sltu  $v0, $zero, $s2
  beqz  $v0, .L7F054B30
   li    $s2, 1
  lwc1  $f4, 0x2c($sp)
  lwc1  $f6, ($s0)
  c.lt.s $f4, $f6
  nop   
  bc1fl .L7F054ADC
   lwc1  $f8, 0x30($sp)
  swc1  $f4, ($s0)
  lwc1  $f8, 0x30($sp)
.L7F054ADC:
  lwc1  $f10, 4($s0)
  c.lt.s $f8, $f10
  nop   
  bc1fl .L7F054AF8
   lwc1  $f16, 8($s0)
  swc1  $f8, 4($s0)
  lwc1  $f16, 8($s0)
.L7F054AF8:
  lwc1  $f18, 0x34($sp)
  c.lt.s $f16, $f18
  nop   
  bc1fl .L7F054B14
   lwc1  $f6, 0xc($s0)
  swc1  $f18, 8($s0)
  lwc1  $f6, 0xc($s0)
.L7F054B14:
  lwc1  $f4, 0x38($sp)
  c.lt.s $f6, $f4
  nop   
  bc1fl .L7F054B54
   lw    $a0, 4($s1)
  b     .L7F054B50
   swc1  $f4, 0xc($s0)
.L7F054B30:
  lwc1  $f10, 0x2c($sp)
  swc1  $f10, ($s0)
  lwc1  $f8, 0x30($sp)
  swc1  $f8, 4($s0)
  lwc1  $f16, 0x34($sp)
  swc1  $f16, 8($s0)
  lwc1  $f18, 0x38($sp)
  swc1  $f18, 0xc($s0)
.L7F054B50:
  lw    $a0, 4($s1)
.L7F054B54:
  addiu $s1, $s1, 4
  bgez  $a0, .L7F054AA4
   nop   
  lw    $ra, 0x24($sp)
.L7F054B64:
  move  $v0, $s2
  lw    $s2, 0x1c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x68
");

asm(R"
glabel sub_GAME_7F054B80
  addiu $sp, $sp, -0x20
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f16
  sw    $ra, 0x14($sp)
  sw    $a0, 0x20($sp)
  sw    $a1, 0x24($sp)
  jal   return_nearfog_values
   swc1  $f16, 0x1c($sp)
  beqz  $v0, .L7F054C44
   lwc1  $f16, 0x1c($sp)
  lw    $t6, 0x20($sp)
  lwc1  $f4, 8($v0)
  lwc1  $f6, 0x18($t6)
  c.lt.s $f4, $f6
  nop   
  bc1fl .L7F054C48
   lw    $ra, 0x14($sp)
  sw    $v0, 0x18($sp)
  jal   getPlayer_c_lodscalez
   swc1  $f16, 0x1c($sp)
  lw    $v1, 0x18($sp)
  lw    $t7, 0x20($sp)
  li    $at, 0x42C80000 # 100.000000
  lwc1  $f2, 8($v1)
  lwc1  $f8, 0x18($t7)
  mtc1  $at, $f18
  lwc1  $f6, 0x24($sp)
  sub.s $f10, $f8, $f2
  lwc1  $f14, 4($v1)
  lwc1  $f16, 0x1c($sp)
  mul.s $f4, $f10, $f18
  div.s $f8, $f4, $f6
  add.s $f10, $f8, $f2
  mul.s $f12, $f10, $f0
  c.le.s $f14, $f12
  nop   
  bc1fl .L7F054C28
   lwc1  $f0, ($v1)
  mtc1  $zero, $f16
  b     .L7F054C48
   lw    $ra, 0x14($sp)
  lwc1  $f0, ($v1)
.L7F054C28:
  c.lt.s $f0, $f12
  nop   
  bc1fl .L7F054C48
   lw    $ra, 0x14($sp)
  sub.s $f18, $f14, $f12
  sub.s $f4, $f14, $f0
  div.s $f16, $f18, $f4
.L7F054C44:
  lw    $ra, 0x14($sp)
.L7F054C48:
  addiu $sp, $sp, 0x20
  mov.s $f0, $f16
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F054C58
  addiu $sp, $sp, -0x38
  sw    $ra, 0x14($sp)
  li    $t6, 1
  sw    $a0, 0x38($sp)
  sw    $a1, 0x3c($sp)
  jal   return_nearfog_values
   sw    $t6, 0x34($sp)
  beql  $v0, $zero, .L7F054D5C
   lw    $ra, 0x14($sp)
  jal   get_BONDdata_position
   sw    $v0, 0x30($sp)
  jal   get_BONDdata_field_10CC
   sw    $v0, 0x1c($sp)
  lw    $v1, 0x1c($sp)
  lw    $a1, 0x38($sp)
  lw    $a0, 0x30($sp)
  lwc1  $f6, ($v1)
  lwc1  $f4, ($a1)
  sub.s $f8, $f4, $f6
  swc1  $f8, 0x24($sp)
  lwc1  $f16, 4($v1)
  lwc1  $f10, 4($a1)
  sub.s $f18, $f10, $f16
  lwc1  $f10, 0x24($sp)
  swc1  $f18, 0x28($sp)
  lwc1  $f6, 8($v1)
  lwc1  $f4, 8($a1)
  sub.s $f8, $f4, $f6
  lwc1  $f4, 0x28($sp)
  swc1  $f8, 0x2c($sp)
  lwc1  $f16, ($v0)
  lwc1  $f6, 4($v0)
  mul.s $f18, $f10, $f16
  lwc1  $f16, 8($v0)
  mul.s $f8, $f4, $f6
  lwc1  $f4, 0x2c($sp)
  mul.s $f6, $f16, $f4
  add.s $f10, $f18, $f8
  lwc1  $f18, 8($a0)
  add.s $f12, $f6, $f10
  c.lt.s $f18, $f12
  nop   
  bc1fl .L7F054D5C
   lw    $ra, 0x14($sp)
  sw    $a0, 0x30($sp)
  jal   getPlayer_c_lodscalez
   swc1  $f12, 0x20($sp)
  lw    $a0, 0x30($sp)
  lwc1  $f12, 0x20($sp)
  li    $at, 0x42C80000 # 100.000000
  lwc1  $f2, 8($a0)
  mtc1  $at, $f16
  lwc1  $f6, 0x3c($sp)
  sub.s $f8, $f12, $f2
  mul.s $f4, $f8, $f16
  lwc1  $f8, 4($a0)
  div.s $f10, $f4, $f6
  add.s $f18, $f10, $f2
  mul.s $f12, $f18, $f0
  c.le.s $f8, $f12
  nop   
  bc1fl .L7F054D5C
   lw    $ra, 0x14($sp)
  sw    $zero, 0x34($sp)
  lw    $ra, 0x14($sp)
.L7F054D5C:
  lw    $v0, 0x34($sp)
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_8005345C
.word 0x4e742400 /*1.024e9*/
glabel D_80053460
.word 0x40c90fdb /*6.2831855*/
glabel D_80053464
.word 0x40c90fdb /*6.2831855*/
glabel D_80053468
.word 0x40490fdb /*3.1415927*/
glabel D_8005346C
.word 0x40c90fdb /*6.2831855*/
glabel D_80053470
.word 0x40490fdb /*3.1415927*/
glabel D_80053474
.word 0x40c90fdb /*6.2831855*/
glabel D_80053478
.word 0x40c90fdb /*6.2831855*/
glabel D_8005347C
.word 0x40490fdb /*3.1415927*/
glabel D_80053480
.word 0x40c90fdb /*6.2831855*/
glabel D_80053484
.word 0x3eb2b8c3 /*0.34906587*/
glabel D_80053488
.word 0x40490fdb /*3.1415927*/
glabel D_8005348C
.word 0x471c4000 /*40000.0*/
.text
glabel sub_GAME_7F054D6C
  addiu $sp, $sp, -0x70
  sw    $s1, 0x18($sp)
  move  $s1, $a1
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x14($sp)
  sw    $a0, 0x70($sp)
  sw    $a2, 0x78($sp)
  sw    $a3, 0x7c($sp)
  sw    $zero, 0x44($sp)
  jal   sub_GAME_7F03CB8C
   addiu $a1, $sp, 0x50
  lw    $a0, 0x50($sp)
  addiu $s0, $sp, 0x50
  bltzl $a0, .L7F054E94
   lw    $ra, 0x1c($sp)
.L7F054DA8:
  jal   sub_GAME_7F0B5E50
   nop   
  beqz  $v0, .L7F054E80
   move  $a0, $s1
  jal   sub_GAME_7F0BB2C8
   lw    $a1, 0x78($sp)
  beqz  $v0, .L7F054E90
   lw    $t6, 0x7c($sp)
  beqz  $t6, .L7F054DDC
   move  $a0, $s1
  jal   sub_GAME_7F054C58
   lw    $a1, 0x78($sp)
  beqz  $v0, .L7F054E90
.L7F054DDC:
   addiu $s0, $sp, 0x34
  move  $a1, $s0
  jal   sub_GAME_7F054A64
   lw    $a0, 0x70($sp)
  beqz  $v0, .L7F054E0C
   move  $a0, $s1
  move  $a0, $s1
  lw    $a1, 0x78($sp)
  jal   sub_GAME_7F078BF4
   move  $a2, $s0
  b     .L7F054E18
   sw    $v0, 0x44($sp)
.L7F054E0C:
  jal   sub_GAME_7F078A58
   lw    $a1, 0x78($sp)
  sw    $v0, 0x44($sp)
.L7F054E18:
  beql  $v0, $zero, .L7F054E94
   lw    $ra, 0x1c($sp)
  jal   get_BONDdata_position
   nop   
  lwc1  $f4, ($s1)
  lwc1  $f6, ($v0)
  lwc1  $f8, 4($s1)
  lwc1  $f10, 4($v0)
  sub.s $f0, $f4, $f6
  lwc1  $f16, 8($s1)
  lwc1  $f18, 8($v0)
  sub.s $f2, $f8, $f10
  mul.s $f6, $f0, $f0
  lui   $at, %hi(D_8005345C)
  sub.s $f12, $f16, $f18
  mul.s $f8, $f2, $f2
  lwc1  $f4, %lo(D_8005345C)($at)
  mul.s $f16, $f12, $f12
  add.s $f10, $f6, $f8
  add.s $f18, $f10, $f16
  c.lt.s $f4, $f18
  nop   
  bc1fl .L7F054E94
   lw    $ra, 0x1c($sp)
  b     .L7F054E90
   sw    $zero, 0x44($sp)
.L7F054E80:
  lw    $a0, 4($s0)
  addiu $s0, $s0, 4
  bgez  $a0, .L7F054DA8
   nop   
.L7F054E90:
  lw    $ra, 0x1c($sp)
.L7F054E94:
  lw    $v0, 0x44($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x70
");

asm(R"
glabel sub_GAME_7F054EA8
  addiu $sp, $sp, -0x28
  sw    $ra, 0x24($sp)
  sw    $s0, 0x20($sp)
  lb    $v0, 0xbc($a0)
  li    $at, 1
  move  $s0, $a0
  bne   $v0, $at, .L7F054F34
   move  $v1, $zero
  lwc1  $f4, 0x90($s0)
  lw    $a1, 0x84($s0)
  lw    $a3, 0x8c($s0)
  swc1  $f4, 0x10($sp)
  lwc1  $f6, 0x94($s0)
  addiu $a0, $a0, 0xb4
  addiu $a2, $s0, 0xb8
  jal   sub_GAME_7F042F18
   swc1  $f6, 0x14($sp)
  lwc1  $f2, 0xb4($s0)
  lwc1  $f0, 0x84($s0)
  li    $v1, 1
  c.le.s $f0, $f2
  nop   
  bc1fl .L7F054F14
   mtc1  $zero, $f12
  b     .L7F054FA0
   swc1  $f0, 0xb4($s0)
  mtc1  $zero, $f12
.L7F054F14:
  nop   
  c.le.s $f2, $f12
  nop   
  bc1f  .L7F054F2C
   nop   
  swc1  $f12, 0xb4($s0)
.L7F054F2C:
  b     .L7F054FA0
   li    $v1, 1
.L7F054F34:
  li    $at, 2
  bne   $v0, $at, .L7F054FA0
   addiu $a0, $s0, 0xb4
  lwc1  $f8, 0x90($s0)
  mtc1  $zero, $f12
  lw    $a3, 0x8c($s0)
  swc1  $f8, 0x10($sp)
  lwc1  $f10, 0x94($s0)
  mfc1  $a1, $f12
  addiu $a2, $s0, 0xb8
  jal   sub_GAME_7F042F18
   swc1  $f10, 0x14($sp)
  lwc1  $f2, 0xb4($s0)
  lwc1  $f0, 0x84($s0)
  mtc1  $zero, $f12
  li    $v1, 1
  c.le.s $f0, $f2
  nop   
  bc1fl .L7F054F90
   c.le.s $f2, $f12
  b     .L7F054FA0
   swc1  $f0, 0xb4($s0)
  c.le.s $f2, $f12
.L7F054F90:
  nop   
  bc1f  .L7F054FA0
   nop   
  swc1  $f12, 0xb4($s0)
.L7F054FA0:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   move  $v0, $v1
");

asm(R"
glabel sub_GAME_7F054FB4
  addiu $sp, $sp, -0x38
  sw    $s5, 0x30($sp)
  sw    $s4, 0x2c($sp)
  sw    $s2, 0x24($sp)
  sw    $s1, 0x20($sp)
  move  $s2, $a0
  sw    $ra, 0x34($sp)
  sw    $s3, 0x28($sp)
  sw    $s0, 0x1c($sp)
  sdc1  $f20, 0x10($sp)
  move  $s4, $zero
  li    $s5, 1
  beqz  $a0, .L7F055028
   move  $s1, $a0
  lwc1  $f4, 0xb4($s1)
.L7F054FF0:
  move  $a0, $s1
  jal   sub_GAME_7F054EA8
   swc1  $f4, 0xfc($s1)
  beql  $v0, $zero, .L7F05500C
   lw    $s1, 0xc8($s1)
  li    $s4, 1
  lw    $s1, 0xc8($s1)
.L7F05500C:
  bne   $s1, $s2, .L7F05501C
   nop   
  b     .L7F055028
   move  $s1, $s2
.L7F05501C:
  bnezl $s1, .L7F054FF0
   lwc1  $f4, 0xb4($s1)
  move  $s1, $s2
.L7F055028:
  beqz  $s4, .L7F055078
   nop   
  beqz  $s2, .L7F055078
   nop   
.L7F055038:
  jal   sub_GAME_7F052B00
   move  $a0, $s1
  jal   sub_GAME_7F0448A8
   lw    $a0, 0x10($s1)
  bnez  $v0, .L7F055058
   move  $s5, $v0
  b     .L7F055078
   move  $s1, $s2
.L7F055058:
  lw    $s1, 0xc8($s1)
  bne   $s1, $s2, .L7F05506C
   nop   
  b     .L7F055078
   move  $s1, $s2
.L7F05506C:
  bnez  $s1, .L7F055038
   nop   
  move  $s1, $s2
.L7F055078:
  beqz  $s2, .L7F055204
   lui   $s3, %hi(global_timer)
  mtc1  $zero, $f20
  addiu $s3, %lo(global_timer) # addiu $s3, $s3, -0x7c84
.L7F055088:
  beql  $s4, $zero, .L7F05514C
   lhu   $t7, 0x98($s1)
  beqz  $s5, .L7F055128
   move  $a0, $s1
  lb    $v0, 0xbc($s1)
  li    $at, 1
  bnel  $v0, $at, .L7F0550E4
   li    $at, 2
  lwc1  $f6, 0xb4($s1)
  lwc1  $f8, 0x84($s1)
  c.le.s $f8, $f6
  nop   
  bc1fl .L7F055118
   lw    $a0, 0x10($s1)
  sb    $zero, 0xbc($s1)
  swc1  $f20, 0xb8($s1)
  lw    $t6, ($s3)
  move  $a0, $s1
  jal   sub_GAME_7F05480C
   sw    $t6, 0xec($s1)
  b     .L7F055118
   lw    $a0, 0x10($s1)
  li    $at, 2
.L7F0550E4:
  bnel  $v0, $at, .L7F055118
   lw    $a0, 0x10($s1)
  lwc1  $f10, 0xb4($s1)
  move  $a0, $s1
  c.le.s $f10, $f20
  nop   
  bc1fl .L7F055118
   lw    $a0, 0x10($s1)
  sb    $zero, 0xbc($s1)
  swc1  $f20, 0xb8($s1)
  jal   sub_GAME_7F05487C
   sw    $zero, 0xec($s1)
  lw    $a0, 0x10($s1)
.L7F055118:
  jal   sub_GAME_7F0402B4
   addiu $a1, $s1, 0x7c
  b     .L7F055138
   nop   
.L7F055128:
  lwc1  $f16, 0xfc($s1)
  swc1  $f20, 0xb8($s1)
  jal   sub_GAME_7F052B00
   swc1  $f16, 0xb4($s1)
.L7F055138:
  jal   sub_GAME_7F052D8C
   move  $a0, $s1
  b     .L7F0551EC
   lw    $t1, ($s3)
  lhu   $t7, 0x98($s1)
.L7F05514C:
  andi  $t8, $t7, 4
  beql  $t8, $zero, .L7F0551EC
   lw    $t1, ($s3)
  lw    $a0, 0x14($s1)
  lw    $t9, 8($a0)
  lw    $t0, ($t9)
  lw    $t1, 0x14($t0)
  lw    $a1, 0x14($t1)
  jal   extract_id_from_object_structure_microcode
   lw    $s0, 4($a1)
  lw    $v1, 0xcc($s1)
  lw    $t2, ($v0)
  beql  $v1, $t2, .L7F0551E8
   sw    $v1, ($v0)
  lh    $t3, 0xc($s0)
  move  $a0, $zero
  blezl $t3, .L7F0551E8
   sw    $v1, ($v0)
  move  $v1, $zero
  lw    $t6, ($v0)
.L7F05519C:
  lw    $t4, 0xcc($s1)
  addiu $a0, $a0, 1
  addu  $t7, $t6, $v1
  lw    $at, ($t7)
  addu  $t5, $t4, $v1
  addiu $v1, $v1, 0x10
  sw    $at, ($t5)
  lw    $t9, 4($t7)
  sw    $t9, 4($t5)
  lw    $at, 8($t7)
  sw    $at, 8($t5)
  lw    $t9, 0xc($t7)
  sw    $t9, 0xc($t5)
  lh    $t0, 0xc($s0)
  slt   $at, $a0, $t0
  bnezl $at, .L7F05519C
   lw    $t6, ($v0)
  lw    $v1, 0xcc($s1)
  sw    $v1, ($v0)
.L7F0551E8:
  lw    $t1, ($s3)
.L7F0551EC:
  sw    $t1, 0xfc($s1)
  lw    $s1, 0xc8($s1)
  beql  $s1, $s2, .L7F055208
   lw    $ra, 0x34($sp)
  bnez  $s1, .L7F055088
   nop   
.L7F055204:
  lw    $ra, 0x34($sp)
.L7F055208:
  ldc1  $f20, 0x10($sp)
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  lw    $s2, 0x24($sp)
  lw    $s3, 0x28($sp)
  lw    $s4, 0x2c($sp)
  lw    $s5, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x38
");

asm(R"
glabel sub_GAME_7F05522C
  addiu $sp, $sp, -0x68
  sw    $ra, 0x14($sp)
  sw    $a0, 0x68($sp)
  sw    $a1, 0x6c($sp)
  sw    $a2, 0x70($sp)
  sw    $a3, 0x74($sp)
  lh    $t9, 6($a0)
  lui   $t1, %hi(ptr_2xxxpresets) 
  lw    $t1, %lo(ptr_2xxxpresets)($t1)
  sll   $t0, $t9, 4
  addu  $t0, $t0, $t9
  sll   $t0, $t0, 2
  addu  $v1, $t0, $t1
  jal   get_curplayer_positiondata
   sw    $v1, 0x5c($sp)
  lui   $a0, %hi(pPlayer)
  lw    $a0, %lo(pPlayer)($a0)
  li    $at, 0x41F00000 # 30.000000
  mtc1  $at, $f0
  lwc1  $f4, 0x498($a0)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f2
  mul.s $f10, $f4, $f0
  li    $at, 0x3F400000 # 0.750000
  mtc1  $at, $f12
  lwc1  $f4, 8($v0)
  lw    $t2, 0x74($sp)
  lw    $v1, 0x5c($sp)
  mul.s $f8, $f10, $f2
  nop   
  mul.s $f6, $f8, $f12
  add.s $f10, $f6, $f4
  swc1  $f10, 0x30($sp)
  lwc1  $f8, 0xc($v0)
  swc1  $f8, 0x34($sp)
  lwc1  $f6, 0x4a0($a0)
  mul.s $f4, $f6, $f0
  lwc1  $f6, 0x10($v0)
  mul.s $f10, $f4, $f2
  nop   
  mul.s $f8, $f10, $f12
  add.s $f4, $f8, $f6
  beqz  $t2, .L7F05534C
   swc1  $f4, 0x38($sp)
  lwc1  $f10, 0x30($v1)
  lwc1  $f18, 0x2c($v1)
  swc1  $f10, 0x3c($sp)
  lwc1  $f8, 0x10($v1)
  lwc1  $f6, 0x20($v1)
  lwc1  $f10, 0x1c($v1)
  mul.s $f4, $f8, $f6
  lwc1  $f8, 0x14($v1)
  mul.s $f6, $f10, $f8
  sub.s $f10, $f4, $f6
  swc1  $f10, 0x44($sp)
  lwc1  $f4, 0x18($v1)
  lwc1  $f8, 0x14($v1)
  lwc1  $f10, 0x20($v1)
  mul.s $f6, $f8, $f4
  lwc1  $f8, 0xc($v1)
  mul.s $f4, $f10, $f8
  sub.s $f10, $f6, $f4
  swc1  $f10, 0x48($sp)
  lwc1  $f6, 0x1c($v1)
  lwc1  $f8, 0xc($v1)
  lwc1  $f10, 0x18($v1)
  mul.s $f4, $f8, $f6
  lwc1  $f8, 0x10($v1)
  mul.s $f6, $f10, $f8
  sub.s $f10, $f4, $f6
  b     .L7F055370
   swc1  $f10, 0x4c($sp)
.L7F05534C:
  lwc1  $f8, 0x38($v1)
  lwc1  $f18, 0x34($v1)
  swc1  $f8, 0x3c($sp)
  lwc1  $f4, 0xc($v1)
  swc1  $f4, 0x44($sp)
  lwc1  $f6, 0x10($v1)
  swc1  $f6, 0x48($sp)
  lwc1  $f10, 0x14($v1)
  swc1  $f10, 0x4c($sp)
.L7F055370:
  lwc1  $f4, 0x44($sp)
  lwc1  $f8, ($v1)
  mul.s $f6, $f4, $f18
  lwc1  $f4, 0x30($sp)
  add.s $f10, $f8, $f6
  lwc1  $f6, 0x4c($sp)
  lwc1  $f8, 8($v1)
  swc1  $f18, 0x40($sp)
  sub.s $f12, $f10, $f4
  mul.s $f10, $f6, $f18
  lwc1  $f6, 0x38($sp)
  sw    $v1, 0x5c($sp)
  add.s $f4, $f8, $f10
  jal   convert_angle_using_inverse
   sub.s $f14, $f4, $f6
  jal   get_curplay_horizontal_rotation_in_degrees
   swc1  $f0, 0x20($sp)
  lwc1  $f12, 0x20($sp)
  lw    $v1, 0x5c($sp)
  lwc1  $f18, 0x40($sp)
  c.lt.s $f12, $f0
  lui   $at, %hi(D_80053460)
  sub.s $f14, $f12, $f0
  lw    $v0, 0x68($sp)
  lwc1  $f16, 0x3c($sp)
  bc1f  .L7F0553E4
   mov.s $f2, $f14
  lwc1  $f0, %lo(D_80053460)($at)
  add.s $f2, $f14, $f0
.L7F0553E4:
  lui   $at, %hi(D_80053464)
  lwc1  $f0, %lo(D_80053464)($at)
  lui   $at, %hi(D_80053468)
  lwc1  $f8, %lo(D_80053468)($at)
  lwc1  $f10, 0x44($sp)
  c.lt.s $f8, $f2
  nop   
  bc1fl .L7F055410
   lhu   $t3, 0x9a($v0)
  sub.s $f2, $f2, $f0
  lhu   $t3, 0x9a($v0)
.L7F055410:
  li    $at, 5
  bne   $t3, $at, .L7F055530
   nop   
  lwc1  $f10, 0xb4($v0)
  lw    $t4, 8($v0)
  li    $at, 0x43B40000 # 360.000000
  mul.s $f4, $f10, $f0
  mtc1  $at, $f6
  sll   $t5, $t4, 2
  bgez  $t5, .L7F055440
   div.s $f12, $f4, $f6
  sub.s $f12, $f0, $f12
.L7F055440:
  sw    $v1, 0x5c($sp)
  swc1  $f2, 0x64($sp)
  swc1  $f12, 0x2c($sp)
  jal   cosf
   swc1  $f18, 0x40($sp)
  lwc1  $f12, 0x2c($sp)
  jal   sinf
   swc1  $f0, 0x28($sp)
  lwc1  $f18, 0x40($sp)
  lwc1  $f4, 0x44($sp)
  lw    $v1, 0x5c($sp)
  lwc1  $f8, 0x3c($sp)
  mul.s $f6, $f4, $f18
  lwc1  $f10, ($v1)
  sub.s $f2, $f8, $f18
  lwc1  $f16, 0x28($sp)
  add.s $f8, $f10, $f6
  mul.s $f10, $f4, $f16
  lwc1  $f6, 0x4c($sp)
  swc1  $f8, 0x18($sp)
  mul.s $f8, $f6, $f0
  add.s $f10, $f10, $f8
  mul.s $f8, $f2, $f10
  lwc1  $f10, 0x18($sp)
  add.s $f10, $f10, $f8
  lwc1  $f8, 0x30($sp)
  sub.s $f12, $f10, $f8
  mul.s $f8, $f6, $f18
  lwc1  $f10, 8($v1)
  add.s $f10, $f10, $f8
  neg.s $f8, $f4
  mul.s $f4, $f8, $f0
  nop   
  mul.s $f8, $f6, $f16
  add.s $f6, $f4, $f8
  mul.s $f4, $f2, $f6
  lwc1  $f6, 0x38($sp)
  add.s $f8, $f10, $f4
  jal   convert_angle_using_inverse
   sub.s $f14, $f8, $f6
  jal   get_curplay_horizontal_rotation_in_degrees
   swc1  $f0, 0x20($sp)
  lwc1  $f12, 0x20($sp)
  lui   $at, %hi(D_8005346C)
  c.lt.s $f12, $f0
  sub.s $f14, $f12, $f0
  bc1f  .L7F055508
   mov.s $f2, $f14
  lwc1  $f10, %lo(D_8005346C)($at)
  add.s $f2, $f14, $f10
.L7F055508:
  lui   $at, %hi(D_80053470)
  lwc1  $f4, %lo(D_80053470)($at)
  lui   $at, %hi(D_80053474)
  c.lt.s $f4, $f2
  nop   
  bc1fl .L7F0555B4
   lwc1  $f0, 0x64($sp)
  lwc1  $f8, %lo(D_80053474)($at)
  b     .L7F0555B0
   sub.s $f2, $f2, $f8
.L7F055530:
  mul.s $f4, $f10, $f16
  lwc1  $f6, ($v1)
  lwc1  $f10, 0x30($sp)
  add.s $f8, $f6, $f4
  lwc1  $f4, 0x4c($sp)
  lwc1  $f6, 8($v1)
  swc1  $f2, 0x64($sp)
  sub.s $f12, $f8, $f10
  mul.s $f8, $f4, $f16
  lwc1  $f4, 0x38($sp)
  add.s $f10, $f6, $f8
  jal   convert_angle_using_inverse
   sub.s $f14, $f10, $f4
  jal   get_curplay_horizontal_rotation_in_degrees
   swc1  $f0, 0x20($sp)
  lwc1  $f12, 0x20($sp)
  lui   $at, %hi(D_80053478)
  c.lt.s $f12, $f0
  sub.s $f14, $f12, $f0
  bc1f  .L7F05558C
   mov.s $f2, $f14
  lwc1  $f6, %lo(D_80053478)($at)
  add.s $f2, $f14, $f6
.L7F05558C:
  lui   $at, %hi(D_8005347C)
  lwc1  $f8, %lo(D_8005347C)($at)
  lui   $at, %hi(D_80053480)
  c.lt.s $f8, $f2
  nop   
  bc1fl .L7F0555B4
   lwc1  $f0, 0x64($sp)
  lwc1  $f10, %lo(D_80053480)($at)
  sub.s $f2, $f2, $f10
.L7F0555B0:
  lwc1  $f0, 0x64($sp)
.L7F0555B4:
  lw    $t6, 0x6c($sp)
  lw    $t8, 0x6c($sp)
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F0555E0
   swc1  $f2, ($t8)
  swc1  $f0, ($t6)
  lw    $t7, 0x70($sp)
  b     .L7F0555E8
   swc1  $f2, ($t7)
  swc1  $f2, ($t8)
.L7F0555E0:
  lw    $t9, 0x70($sp)
  swc1  $f0, ($t9)
.L7F0555E8:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x68
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0555F8
  addiu $sp, $sp, -0x58
  lui   $t7, %hi(dword_CODE_bss_80071DF8) 
  lw    $t7, %lo(dword_CODE_bss_80071DF8)($t7)
  sw    $s4, 0x30($sp)
  sw    $s3, 0x2c($sp)
  li    $t6, 1
  move  $s3, $a0
  move  $s4, $a1
  sw    $ra, 0x34($sp)
  sw    $s2, 0x28($sp)
  sw    $s1, 0x24($sp)
  sw    $s0, 0x20($sp)
  sdc1  $f20, 0x18($sp)
  bnez  $t7, .L7F0557DC
   sw    $t6, 0x54($sp)
  addiu $a1, $sp, 0x50
  addiu $a2, $sp, 0x4c
  jal   sub_GAME_7F05522C
   move  $a3, $s4
  lui   $at, %hi(D_80053484)
  lwc1  $f2, %lo(D_80053484)($at)
  lwc1  $f4, 0x50($sp)
  neg.s $f0, $f2
  c.le.s $f0, $f4
  nop   
  bc1fl .L7F0556A8
   lw    $s0, 0xc8($s3)
  c.le.s $f4, $f2
  lwc1  $f6, 0x4c($sp)
  bc1fl .L7F0556A8
   lw    $s0, 0xc8($s3)
  c.le.s $f0, $f6
  nop   
  bc1fl .L7F0556A8
   lw    $s0, 0xc8($s3)
  c.le.s $f6, $f2
  lui   $at, %hi(dword_CODE_bss_80071DF8)
  bc1fl .L7F0556A8
   lw    $s0, 0xc8($s3)
  lw    $t8, 0x10($s3)
  sw    $zero, 0x54($sp)
  b     .L7F0557DC
   sw    $t8, %lo(dword_CODE_bss_80071DF8)($at)
  lw    $s0, 0xc8($s3)
.L7F0556A8:
  beql  $s0, $zero, .L7F055788
   lwc1  $f8, 0x4c($sp)
  beq   $s0, $s3, .L7F055784
   lwc1  $f8, 0x50($sp)
  mtc1  $zero, $f20
  lwc1  $f10, 0x4c($sp)
  c.le.s $f20, $f8
  nop   
  bc1tl .L7F0556E0
   addiu $a1, $sp, 0x40
  c.lt.s $f10, $f20
  nop   
  bc1f  .L7F055784
   addiu $a1, $sp, 0x40
.L7F0556E0:
  addiu $a2, $sp, 0x3c
  move  $a0, $s0
  jal   sub_GAME_7F05522C
   move  $a3, $s4
  lwc1  $f16, 0x50($sp)
  lwc1  $f0, 0x40($sp)
  c.lt.s $f20, $f16
  nop   
  bc1fl .L7F055720
   lwc1  $f18, 0x4c($sp)
  c.lt.s $f0, $f16
  nop   
  bc1fl .L7F055720
   lwc1  $f18, 0x4c($sp)
  swc1  $f0, 0x50($sp)
  lwc1  $f18, 0x4c($sp)
.L7F055720:
  lwc1  $f0, 0x3c($sp)
  c.lt.s $f18, $f20
  nop   
  bc1fl .L7F05574C
   lw    $s0, 0xc8($s0)
  c.lt.s $f18, $f0
  nop   
  bc1fl .L7F05574C
   lw    $s0, 0xc8($s0)
  swc1  $f0, 0x4c($sp)
  lw    $s0, 0xc8($s0)
.L7F05574C:
  lwc1  $f4, 0x50($sp)
  beql  $s0, $zero, .L7F055788
   lwc1  $f8, 0x4c($sp)
  beql  $s0, $s3, .L7F055788
   lwc1  $f8, 0x4c($sp)
  c.le.s $f20, $f4
  nop   
  bc1tl .L7F0556E0
   addiu $a1, $sp, 0x40
  lwc1  $f6, 0x4c($sp)
  c.lt.s $f6, $f20
  nop   
  bc1tl .L7F0556E0
   addiu $a1, $sp, 0x40
.L7F055784:
  lwc1  $f8, 0x4c($sp)
.L7F055788:
  lwc1  $f10, 0x50($sp)
  lui   $at, %hi(D_80053488)
  lwc1  $f18, %lo(D_80053488)($at)
  sub.s $f16, $f8, $f10
  mtc1  $zero, $f20
  c.lt.s $f16, $f18
  nop   
  bc1fl .L7F0557E0
   lw    $ra, 0x34($sp)
  c.lt.s $f10, $f20
  nop   
  bc1fl .L7F0557E0
   lw    $ra, 0x34($sp)
  c.lt.s $f20, $f8
  nop   
  bc1fl .L7F0557E0
   lw    $ra, 0x34($sp)
  lw    $t9, 0x10($s3)
  lui   $at, %hi(dword_CODE_bss_80071DF8)
  sw    $zero, 0x54($sp)
  sw    $t9, %lo(dword_CODE_bss_80071DF8)($at)
.L7F0557DC:
  lw    $ra, 0x34($sp)
.L7F0557E0:
  lw    $v0, 0x54($sp)
  ldc1  $f20, 0x18($sp)
  lw    $s0, 0x20($sp)
  lw    $s1, 0x24($sp)
  lw    $s2, 0x28($sp)
  lw    $s3, 0x2c($sp)
  lw    $s4, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x58
");

asm(R"
glabel sub_GAME_7F055804
  addiu $sp, $sp, -0x88
  li    $t6, 1
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $t6, 0x84($sp)
  lw    $s0, 4($a0)
  lw    $t7, 8($s0)
  sll   $t8, $t7, 6
  bltzl $t8, .L7F05598C
   lw    $ra, 0x1c($sp)
  mtc1  $zero, $f4
  lwc1  $f6, 0x84($s0)
  c.lt.s $f4, $f6
  nop   
  bc1fl .L7F05598C
   lw    $ra, 0x1c($sp)
  lbu   $t9, 1($a0)
  andi  $t0, $t9, 2
  beql  $t0, $zero, .L7F05598C
   lw    $ra, 0x1c($sp)
  sw    $zero, 0x7c($sp)
  jal   get_curplayer_positiondata
   sw    $a0, 0x88($sp)
  sw    $v0, 0x78($sp)
  lwc1  $f10, 8($v0)
  lwc1  $f8, 0x58($s0)
  lwc1  $f6, 0x10($v0)
  lwc1  $f4, 0x60($s0)
  sub.s $f0, $f8, $f10
  lwc1  $f18, 0xc($v0)
  lwc1  $f16, 0x5c($s0)
  sub.s $f2, $f4, $f6
  mul.s $f8, $f0, $f0
  lui   $at, %hi(D_8005348C)
  sub.s $f12, $f16, $f18
  mul.s $f10, $f2, $f2
  lwc1  $f18, %lo(D_8005348C)($at)
  lw    $a0, 0x88($sp)
  li    $at, 0x43480000 # 200.000000
  add.s $f16, $f8, $f10
  c.lt.s $f16, $f18
  nop   
  bc1f  .L7F0558EC
   nop   
  mtc1  $at, $f4
  li    $at, 0xC3480000 # -200.000000
  c.lt.s $f12, $f4
  nop   
  bc1f  .L7F0558EC
   nop   
  mtc1  $at, $f6
  li    $t1, 1
  c.lt.s $f6, $f12
  nop   
  bc1f  .L7F0558EC
   nop   
  b     .L7F055948
   sw    $t1, 0x7c($sp)
.L7F0558EC:
  jal   sub_GAME_7F03CB8C
   addiu $a1, $sp, 0x48
  lw    $a0, 0x78($sp)
  jal   sub_GAME_7F03CB8C
   addiu $a1, $sp, 0x28
  addiu $a0, $sp, 0x48
  jal   sub_GAME_7F03DB70
   addiu $a1, $sp, 0x28
  beqz  $v0, .L7F055948
   lui   $t4, %hi(ptr_2xxxpresets) 
  lh    $t2, 6($s0)
  lw    $t4, %lo(ptr_2xxxpresets)($t4)
  lw    $a0, 0x78($sp)
  sll   $t3, $t2, 4
  addu  $t3, $t3, $t2
  sll   $t3, $t3, 2
  lui   $a1, 0x4316
  addu  $a2, $t3, $t4
  jal   sub_GAME_7F03F598
   addiu $a0, $a0, 8
  beqz  $v0, .L7F055948
   li    $t5, 1
  sw    $t5, 0x7c($sp)
.L7F055948:
  lw    $t6, 0x7c($sp)
  move  $a0, $s0
  beql  $t6, $zero, .L7F05598C
   lw    $ra, 0x1c($sp)
  jal   sub_GAME_7F0555F8
   move  $a1, $zero
  beqz  $v0, .L7F055988
   sw    $v0, 0x84($sp)
  lw    $t7, 0xc($s0)
  move  $a0, $s0
  sll   $t8, $t7, 0
  bgezl $t8, .L7F05598C
   lw    $ra, 0x1c($sp)
  jal   sub_GAME_7F0555F8
   li    $a1, 1
  sw    $v0, 0x84($sp)
.L7F055988:
  lw    $ra, 0x1c($sp)
.L7F05598C:
  lw    $v0, 0x84($sp)
  lw    $s0, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x88
");

asm(R"
glabel sub_GAME_7F05599C
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a0, 0x20($sp)
  lw    $s0, 4($a0)
  li    $at, 1
  lb    $v0, 0xbc($s0)
  move  $a0, $s0
  beq   $v0, $at, .L7F0559CC
   li    $at, 3
  bnel  $v0, $at, .L7F0559E0
   li    $at, 2
.L7F0559CC:
  jal   set_door_state
   li    $a1, 2
  b     .L7F055A3C
   lw    $t7, 0x64($s0)
  li    $at, 2
.L7F0559E0:
  bne   $v0, $at, .L7F0559F8
   move  $a0, $s0
  jal   set_door_state
   li    $a1, 1
  b     .L7F055A3C
   lw    $t7, 0x64($s0)
.L7F0559F8:
  bnez  $v0, .L7F055A38
   li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f4
  lwc1  $f6, 0xb4($s0)
  li    $a1, 2
  move  $a0, $s0
  c.lt.s $f4, $f6
  nop   
  bc1f  .L7F055A30
   nop   
  jal   set_door_state
   move  $a0, $s0
  b     .L7F055A3C
   lw    $t7, 0x64($s0)
.L7F055A30:
  jal   set_door_state
   li    $a1, 1
.L7F055A38:
  lw    $t7, 0x64($s0)
.L7F055A3C:
  lw    $t9, 0xc($s0)
  li    $at, -9
  ori   $t8, $t7, 0x4000
  and   $t0, $t9, $at
  sw    $t8, 0x64($s0)
  sw    $t0, 0xc($s0)
  jal   sub_GAME_7F03E6A0
   lw    $a0, 0x20($sp)
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F055A70
  lh    $t6, 6($a1)
  lui   $t8, %hi(ptr_2xxxpresets) 
  lw    $t8, %lo(ptr_2xxxpresets)($t8)
  sll   $t7, $t6, 4
  addu  $t7, $t7, $t6
  sll   $t7, $t7, 2
  addu  $v0, $t7, $t8
  lwc1  $f4, 0x10($v0)
  lwc1  $f6, 0x20($v0)
  lwc1  $f10, 0x1c($v0)
  lwc1  $f18, 0x14($v0)
  mul.s $f8, $f4, $f6
  addiu $sp, $sp, -0x20
  mul.s $f4, $f10, $f18
  sub.s $f6, $f8, $f4
  swc1  $f6, 4($sp)
  lwc1  $f18, 0x18($v0)
  lwc1  $f10, 0x14($v0)
  lwc1  $f4, 0x20($v0)
  mul.s $f8, $f10, $f18
  lwc1  $f10, 0xc($v0)
  mul.s $f18, $f4, $f10
  sub.s $f4, $f8, $f18
  swc1  $f4, 8($sp)
  lwc1  $f8, 0x1c($v0)
  lwc1  $f10, 0xc($v0)
  mul.s $f18, $f10, $f8
  lwc1  $f8, 0x10($v0)
  lwc1  $f10, 0x18($v0)
  mul.s $f10, $f10, $f8
  sub.s $f8, $f18, $f10
  swc1  $f8, 0xc($sp)
  lwc1  $f10, ($v0)
  lwc1  $f18, 8($a0)
  lhu   $t9, 0x98($a1)
  sub.s $f0, $f18, $f10
  lwc1  $f10, 4($v0)
  lwc1  $f18, 0xc($a0)
  andi  $t0, $t9, 8
  sub.s $f2, $f18, $f10
  lwc1  $f10, 8($v0)
  lwc1  $f18, 0x10($a0)
  sub.s $f12, $f18, $f10
  mul.s $f18, $f0, $f6
  mtc1  $zero, $f0
  mul.s $f10, $f2, $f4
  add.s $f6, $f18, $f10
  mul.s $f4, $f8, $f12
  add.s $f16, $f4, $f6
  beqz  $t0, .L7F055B40
   mov.s $f14, $f16
  neg.s $f14, $f16
.L7F055B40:
  c.lt.s $f14, $f0
  nop   
  bc1fl .L7F055B5C
   c.lt.s $f0, $f14
  b     .L7F055B70
   move  $v0, $zero
  c.lt.s $f0, $f14
.L7F055B5C:
  li    $v0, 1
  bc1f  .L7F055B70
   nop   
  b     .L7F055B70
   li    $v0, 1
.L7F055B70:
  jr    $ra
   addiu $sp, $sp, 0x20
");

asm(R"
glabel sub_GAME_7F055B78
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lw    $t6, 8($a1)
  sll   $t7, $t6, 4
  bgezl $t7, .L7F055C34
   lw    $ra, 0x14($sp)
  lb    $t8, 0xbc($a1)
  bnezl $t8, .L7F055C34
   lw    $ra, 0x14($sp)
  mtc1  $zero, $f4
  lwc1  $f6, 0xb4($a1)
  c.eq.s $f4, $f6
  nop   
  bc1fl .L7F055C34
   lw    $ra, 0x14($sp)
  jal   sub_GAME_7F055A70
   sw    $a1, 0x1c($sp)
  lw    $a1, 0x1c($sp)
  move  $a0, $zero
  lhu   $t9, 0x98($a1)
  andi  $t0, $t9, 8
  bnez  $t0, .L7F055BE8
   nop   
  bnez  $v0, .L7F055BE0
   nop   
  lui   $a0, 0x2000
.L7F055BE0:
  b     .L7F055BF8
   lw    $t1, 8($a1)
.L7F055BE8:
  beql  $v0, $zero, .L7F055BF8
   lw    $t1, 8($a1)
  lui   $a0, 0x2000
  lw    $t1, 8($a1)
.L7F055BF8:
  lui   $v1, 0x2000
  move  $v0, $a1
  xor   $t2, $t1, $a0
  sll   $t3, $t2, 2
  bgezl $t3, .L7F055C34
   lw    $ra, 0x14($sp)
  lw    $t4, 8($v0)
.L7F055C14:
  xor   $t5, $t4, $v1
  sw    $t5, 8($v0)
  lw    $v0, 0xc8($v0)
  beql  $v0, $zero, .L7F055C34
   lw    $ra, 0x14($sp)
  bnel  $v0, $a1, .L7F055C14
   lw    $t4, 8($v0)
  lw    $ra, 0x14($sp)
.L7F055C34:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

#ifdef VERSION_US
asm(R"
glabel sub_GAME_7F055C40
  addiu $sp, $sp, -0x30
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a0, 0x30($sp)
  lw    $s0, 4($a0)
  jal   get_curplayer_positiondata
   sw    $zero, 0x28($sp)
  sw    $v0, 0x24($sp)
  lw    $a0, 0x9c($s0)
  lw    $v1, 0x28($sp)
  bnez  $a0, .L7F055C78
   nop   
  b     .L7F055CE4
   li    $v1, 1
.L7F055C78:
  jal   sub_GAME_7F08CE70
   sw    $v1, 0x28($sp)
  beqz  $v0, .L7F055C90
   lw    $v1, 0x28($sp)
  b     .L7F055CE4
   li    $v1, 1
.L7F055C90:
  lw    $a0, 0x24($sp)
  move  $a1, $s0
  jal   sub_GAME_7F055A70
   sw    $v1, 0x28($sp)
  beqz  $v0, .L7F055CC8
   lw    $v1, 0x28($sp)
  lw    $v0, 0xc($s0)
  sll   $t7, $v0, 3
  bgez  $t7, .L7F055CE4
   sll   $t8, $v0, 4
  bltzl $t8, .L7F055CE8
   move  $a0, $s0
  b     .L7F055CE4
   li    $v1, 1
.L7F055CC8:
  lw    $v0, 0xc($s0)
  sll   $t9, $v0, 3
  bltz  $t9, .L7F055CE4
   sll   $t0, $v0, 4
  bgezl $t0, .L7F055CE8
   move  $a0, $s0
  li    $v1, 1
.L7F055CE4:
  move  $a0, $s0
.L7F055CE8:
  jal   sub_GAME_7F03E718
   sw    $v1, 0x28($sp)
  bnez  $v0, .L7F055CFC
   lw    $v1, 0x28($sp)
  move  $v1, $zero
.L7F055CFC:
  beqz  $v1, .L7F055D1C
   lw    $a0, 0x24($sp)
  jal   sub_GAME_7F055B78
   move  $a1, $s0
  jal   sub_GAME_7F05599C
   lw    $a0, 0x30($sp)
  b     .L7F055DB8
   lw    $ra, 0x1c($sp)
.L7F055D1C:
  lb    $t1, 0xbc($s0)
  li    $at, 0x3F000000 # 0.500000
  bnezl $t1, .L7F055DB8
   lw    $ra, 0x1c($sp)
  lwc1  $f4, 0xb4($s0)
  mtc1  $at, $f6
  nop   
  c.lt.s $f4, $f6
  nop   
  bc1fl .L7F055DB8
   lw    $ra, 0x1c($sp)
  lw    $v0, 0xc($s0)
  andi  $t2, $v0, 4
  bnezl $t2, .L7F055DA4
   lw    $t4, 0x64($s0)
  jal   get_textoverride_by_obj
   move  $a0, $s0
  beqz  $v0, .L7F055D8C
   nop   
  lw    $t3, 0x1c($v0)
  beqz  $t3, .L7F055D8C
   nop   
  jal   get_textptr_for_textID
   lw    $a0, 0x1c($v0)
  jal   display_string_in_lower_left_corner
   move  $a0, $v0
  b     .L7F055DA0
   lw    $v0, 0xc($s0)
.L7F055D8C:
  jal   get_textptr_for_textID
   li    $a0, 42048
  jal   display_string_in_lower_left_corner
   move  $a0, $v0
  lw    $v0, 0xc($s0)
.L7F055DA0:
  lw    $t4, 0x64($s0)
.L7F055DA4:
  ori   $t6, $v0, 8
  sw    $t6, 0xc($s0)
  ori   $t5, $t4, 0x4000
  sw    $t5, 0x64($s0)
  lw    $ra, 0x1c($sp)
.L7F055DB8:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   move  $v0, $zero
");
#ifdef VERSION_JP
asm(R"
glabel sub_GAME_7F055C40
  addiu $sp, $sp, -0x30
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a0, 0x30($sp)
  lw    $s0, 4($a0)
  jal   get_curplayer_positiondata
   sw    $zero, 0x28($sp)
  sw    $v0, 0x24($sp)
  lw    $a0, 0x9c($s0)
  lw    $v1, 0x28($sp)
  bnez  $a0, .L7F055C78
   nop   
  b     .L7F055CE4
   li    $v1, 1
.L7F055C78:
  jal   sub_GAME_7F08CE70
   sw    $v1, 0x28($sp)
  beqz  $v0, .L7F055C90
   lw    $v1, 0x28($sp)
  b     .L7F055CE4
   li    $v1, 1
.L7F055C90:
  lw    $a0, 0x24($sp)
  move  $a1, $s0
  jal   sub_GAME_7F055A70
   sw    $v1, 0x28($sp)
  beqz  $v0, .L7F055CC8
   lw    $v1, 0x28($sp)
  lw    $v0, 0xc($s0)
  sll   $t7, $v0, 3
  bgez  $t7, .L7F055CE4
   sll   $t8, $v0, 4
  bltzl $t8, .L7F055CE8
   move  $a0, $s0
  b     .L7F055CE4
   li    $v1, 1
.L7F055CC8:
  lw    $v0, 0xc($s0)
  sll   $t9, $v0, 3
  bltz  $t9, .L7F055CE4
   sll   $t0, $v0, 4
  bgezl $t0, .L7F055CE8
   move  $a0, $s0
  li    $v1, 1
.L7F055CE4:
  move  $a0, $s0
.L7F055CE8:
  jal   sub_GAME_7F03E718
   sw    $v1, 0x28($sp)
  bnez  $v0, .L7F055CFC
   lw    $v1, 0x28($sp)
  move  $v1, $zero
.L7F055CFC:
  beqz  $v1, .L7F055D1C
   lw    $a0, 0x24($sp)
  jal   sub_GAME_7F055B78
   move  $a1, $s0
  jal   sub_GAME_7F05599C
   lw    $a0, 0x30($sp)
  b     .L7F055DB8
   lw    $ra, 0x1c($sp)
.L7F055D1C:
  lb    $t1, 0xbc($s0)
  li    $at, 0x3F000000 # 0.500000
  bnezl $t1, .L7F055DB8
   lw    $ra, 0x1c($sp)
  lwc1  $f4, 0xb4($s0)
  mtc1  $at, $f6
  nop   
  c.lt.s $f4, $f6
  nop   
  bc1fl .L7F055DB8
   lw    $ra, 0x1c($sp)
  lw    $v0, 0xc($s0)
  andi  $t2, $v0, 4
  bnezl $t2, .L7F055DA4
   lw    $t4, 0x64($s0)
  jal   get_textoverride_by_obj
   move  $a0, $s0
  beqz  $v0, .L7F055D8C
   nop   
  lw    $t3, 0x1c($v0)
  beqz  $t3, .L7F055D8C
   nop   
  jal   get_textptr_for_textID
   lw    $a0, 0x1c($v0)
  jal   jp_display_string_in_lower_left_corner
   move  $a0, $v0
  b     .L7F055DA0
   lw    $v0, 0xc($s0)
.L7F055D8C:
  jal   get_textptr_for_textID
   li    $a0, 42048
  jal   jp_display_string_in_lower_left_corner
   move  $a0, $v0
  lw    $v0, 0xc($s0)
.L7F055DA0:
  lw    $t4, 0x64($s0)
.L7F055DA4:
  ori   $t6, $v0, 8
  sw    $t6, 0xc($s0)
  ori   $t5, $t4, 0x4000
  sw    $t5, 0x64($s0)
  lw    $ra, 0x1c($sp)
.L7F055DB8:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   move  $v0, $zero
");
#endif

#endif

void start_alarm(void) {
  if (alarm_timer < 1)
    alarm_timer = 1;
}

void deactivate_alarm_sound_effect(void) {
  if ((ptr_alarm_sfx != 0) && (sfxGetArg0Unk3F(ptr_alarm_sfx) != 0))
    sfxDeactivate(ptr_alarm_sfx);
}

void stop_alarm(void) {
  alarm_timer = 0;
  deactivate_alarm_sound_effect();
}

int is_alarm_on(void) { return 0 < alarm_timer; }

asm(R"
glabel init_trigger_toxic_gas_effect
  mtc1  $zero, $f4
  li    $t6, 1
  lui   $at, %hi(activate_gas_sound_timer)
  sw    $t6, %lo(activate_gas_sound_timer)($at)
  addiu $sp, $sp, -0x18
  lui   $at, %hi(D_80030AE0)
  sw    $ra, 0x14($sp)
  swc1  $f4, %lo(D_80030AE0)($at)
  lwc1  $f6, ($a0)
  lui   $v0, %hi(D_80030AD0)
  addiu $v0, %lo(D_80030AD0) # addiu $v0, $v0, 0xad0
  swc1  $f6, ($v0)
  lwc1  $f8, 4($a0)
  swc1  $f8, 4($v0)
  lwc1  $f10, 8($a0)
  jal   get_stage_num
   swc1  $f10, 8($v0)
  li    $at, 32
  bne   $v0, $at, .L7F055ECC
   li    $at, 0x42F00000 # 120.000000
  mtc1  $at, $f16
  lui   $at, %hi(gas_damage_flag)
  swc1  $f16, %lo(gas_damage_flag)($at)
  lui   $at, %hi(gas_cutoff_flag)
  b     .L7F055EE8
   sw    $zero, %lo(gas_cutoff_flag)($at)
.L7F055ECC:
  li    $at, 0x45610000 # 3600.000000
  mtc1  $at, $f18
  lui   $at, %hi(gas_damage_flag)
  li    $t7, 1
  swc1  $f18, %lo(gas_damage_flag)($at)
  lui   $at, %hi(gas_cutoff_flag)
  sw    $t7, %lo(gas_cutoff_flag)($at)
.L7F055EE8:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

void check_deactivate_gas_sound(void) {
  if ((ptr_gas_sound != 0) && (sfxGetArg0Unk3F(ptr_gas_sound) != 0)) {
    sfxDeactivate(ptr_gas_sound);
  }
}

asm(R"
glabel check_if_toxic_gas_activated
  lui   $at, %hi(toxic_gas_sound_timer)
  lwc1  $f6, %lo(toxic_gas_sound_timer)($at)
  mtc1  $zero, $f4
  move  $v0, $zero
  c.lt.s $f4, $f6
  nop   
  bc1f  .L7F055F5C
   nop   
  li    $v0, 1
.L7F055F5C:
  jr    $ra
   nop   
");

asm(R"
glabel handle_gas_damage
  lui   $v0, %hi(activate_gas_sound_timer)
  addiu $v0, %lo(activate_gas_sound_timer) # addiu $v0, $v0, 0xacc
  lw    $t6, ($v0)
  addiu $sp, $sp, -0x20
  mtc1  $zero, $f16
  beqz  $t6, .L7F055FC0
   sw    $ra, 0x1c($sp)
  lui   $v1, %hi(toxic_gas_sound_timer)
  addiu $v1, %lo(toxic_gas_sound_timer) # addiu $v1, $v1, 0xac8
  lui   $at, %hi(global_timer_delta)
  lwc1  $f6, %lo(global_timer_delta)($at)
  lwc1  $f4, ($v1)
  lui   $at, %hi(gas_damage_flag)
  add.s $f8, $f4, $f6
  swc1  $f8, ($v1)
  lwc1  $f10, ($v1)
  lwc1  $f0, %lo(gas_damage_flag)($at)
  c.le.s $f0, $f10
  nop   
  bc1f  .L7F055FC0
   nop   
  swc1  $f0, ($v1)
  sw    $zero, ($v0)
.L7F055FC0:
  lui   $v1, %hi(toxic_gas_sound_timer)
  addiu $v1, %lo(toxic_gas_sound_timer) # addiu $v1, $v1, 0xac8
  lwc1  $f0, ($v1)
  lui   $t7, %hi(disable_player_pickups_flag) 
  c.lt.s $f16, $f0
  nop   
  bc1fl .L7F056154
   lw    $ra, 0x1c($sp)
  lw    $t7, %lo(disable_player_pickups_flag)($t7)
  lui   $at, %hi(gas_damage_flag)
  bnezl $t7, .L7F056154
   lw    $ra, 0x1c($sp)
  lwc1  $f18, %lo(gas_damage_flag)($at)
  jal   switch_to_solosky2
   div.s $f12, $f0, $f18
  lui   $t8, %hi(gas_cutoff_flag) 
  lw    $t8, %lo(gas_cutoff_flag)($t8)
  lui   $v1, %hi(toxic_gas_sound_timer)
  addiu $v1, %lo(toxic_gas_sound_timer) # addiu $v1, $v1, 0xac8
  beqz  $t8, .L7F056150
   lui   $a0, %hi(D_80030ADC)
  lui   $v0, %hi(global_timer)
  lw    $v0, %lo(global_timer)($v0)
  addiu $a0, %lo(D_80030ADC) # addiu $a0, $a0, 0xadc
  lw    $t9, ($a0)
  addiu $t0, $v0, -0xe1
  slt   $at, $t9, $t0
  beqz  $at, .L7F05609C
   li    $at, 0x44160000 # 600.000000
  mtc1  $at, $f4
  lwc1  $f0, ($v1)
  sw    $v0, ($a0)
  lui   $a0, %hi(ptr_sfx_buf)
  c.le.s $f4, $f0
  li    $a1, 98
  move  $a2, $zero
  bc1fl .L7F05606C
   lui   $at, 0x44e1
  jal   play_sfx_a1
   lw    $a0, %lo(ptr_sfx_buf)($a0)
  lui   $at, %hi(toxic_gas_sound_timer)
  lwc1  $f0, %lo(toxic_gas_sound_timer)($at)
  li    $at, 0x44E10000 # 1800.000000
.L7F05606C:
  mtc1  $at, $f6
  li    $at, 0x3E000000 # 0.125000
  c.le.s $f6, $f0
  nop   
  bc1f  .L7F05609C
   nop   
  mtc1  $zero, $f14
  mtc1  $at, $f12
  li    $a3, -1
  mfc1  $a2, $f14
  jal   record_damage_kills
   sw    $zero, 0x10($sp)
.L7F05609C:
  lui   $v0, %hi(D_80030AE0)
  addiu $v0, %lo(D_80030AE0) # addiu $v0, $v0, 0xae0
  lui   $at, %hi(gas_damage_flag)
  lwc1  $f8, %lo(gas_damage_flag)($at)
  lwc1  $f0, ($v0)
  lui   $at, %hi(global_timer_delta)
  lui   $a0, %hi(ptr_gas_sound)
  c.lt.s $f0, $f8
  nop   
  bc1f  .L7F05612C
   nop   
  lwc1  $f10, %lo(global_timer_delta)($at)
  lui   $t1, %hi(ptr_gas_sound) 
  add.s $f16, $f0, $f10
  swc1  $f16, ($v0)
  lw    $t1, %lo(ptr_gas_sound)($t1)
  bnez  $t1, .L7F056108
   nop   
  jal   get_controls_locked_flag
   nop   
  bnez  $v0, .L7F056108
   lui   $a0, %hi(ptr_sfx_buf)
  lui   $a2, %hi(ptr_gas_sound)
  addiu $a2, %lo(ptr_gas_sound) # addiu $a2, $a2, 0xae4
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  jal   play_sfx_a1
   li    $a1, 102
.L7F056108:
  lui   $a0, %hi(ptr_gas_sound)
  lw    $a0, %lo(ptr_gas_sound)($a0)
  lui   $a1, %hi(D_80030AD0)
  beql  $a0, $zero, .L7F056154
   lw    $ra, 0x1c($sp)
  jal   sub_GAME_7F053A10
   addiu $a1, %lo(D_80030AD0) # addiu $a1, $a1, 0xad0
  b     .L7F056154
   lw    $ra, 0x1c($sp)
.L7F05612C:
  lw    $a0, %lo(ptr_gas_sound)($a0)
  beql  $a0, $zero, .L7F056154
   lw    $ra, 0x1c($sp)
  jal   sfxGetArg0Unk3F
   nop   
  beqz  $v0, .L7F056150
   lui   $a0, %hi(ptr_gas_sound)
  jal   sfxDeactivate
   lw    $a0, %lo(ptr_gas_sound)($a0)
.L7F056150:
  lw    $ra, 0x1c($sp)
.L7F056154:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");
#endif

void set_unset_clock_lock_bits(int clocklockbits, int flag) {
  if (flag != 0) {
    clock_drawn_flag &= ~clocklockbits;
    return;
  }
  clock_drawn_flag |= clocklockbits;
}

unsigned int is_clock_drawn_onscreen(void) { return clock_drawn_flag == 0; }

void set_clock_time(float time) { clock_time = time; }

float get_clock_time(void) { return clock_time; }

void set_clock_enable(int enable) { clock_enable = enable; }

int get_clock_enable(void) { return clock_enable; }

void if_enabled_reset_clock(void) {
  if (clock_enable != 0)
    clock_time -= global_timer_delta;
}

asm(R"
glabel sub_GAME_7F056210
  lui   $t6, %hi(clock_drawn_flag) 
  lw    $t6, %lo(clock_drawn_flag)($t6)
  addiu $sp, $sp, -0x48
  sw    $s1, 0x28($sp)
  move  $s1, $a0
  sw    $ra, 0x2c($sp)
  bnez  $t6, .L7F0565D8
   sw    $s0, 0x24($sp)
  lui   $at, %hi(clock_time)
  lwc1  $f2, %lo(clock_time)($at)
  mtc1  $zero, $f4
  li    $at, 0x45610000 # 3600.000000
  mtc1  $at, $f6
  c.lt.s $f2, $f4
  nop   
  bc1fl .L7F05625C
   div.s $f12, $f2, $f6
  neg.s $f2, $f2
  div.s $f12, $f2, $f6
.L7F05625C:
  jal   truncf
   swc1  $f2, 0x30($sp)
  trunc.w.s $f8, $f0
  li    $at, 0x42700000 # 60.000000
  lwc1  $f2, 0x30($sp)
  mtc1  $at, $f10
  mfc1  $t8, $f8
  div.s $f12, $f2, $f10
  jal   truncf
   sw    $t8, 0x44($sp)
  li    $at, 0x42C80000 # 100.000000
  lwc1  $f2, 0x30($sp)
  mtc1  $at, $f18
  trunc.w.s $f16, $f0
  lw    $t1, 0x44($sp)
  mul.s $f4, $f2, $f18
  li    $at, 0x42700000 # 60.000000
  mfc1  $t0, $f16
  sll   $t2, $t1, 4
  subu  $t2, $t2, $t1
  mtc1  $at, $f6
  sll   $t2, $t2, 2
  subu  $t3, $t0, $t2
  sw    $t3, 0x40($sp)
  jal   truncf
   div.s $f12, $f4, $f6
  lw    $t6, 0x44($sp)
  trunc.w.s $f8, $f0
  lw    $t9, 0x40($sp)
  sll   $t7, $t6, 2
  subu  $t7, $t7, $t6
  sll   $t7, $t7, 4
  subu  $t7, $t7, $t6
  sll   $t1, $t9, 2
  mfc1  $t5, $f8
  sll   $t7, $t7, 3
  subu  $t1, $t1, $t9
  sll   $t1, $t1, 3
  subu  $t7, $t7, $t6
  sll   $t7, $t7, 4
  addu  $t1, $t1, $t9
  sll   $t1, $t1, 2
  subu  $t8, $t5, $t7
  subu  $t0, $t8, $t1
  sw    $t0, 0x3c($sp)
  jal   microcode_constructor
   move  $a0, $s1
  jal   get_video2_settings_uly
   move  $s1, $v0
  sll   $s0, $v0, 0x10
  sra   $t2, $s0, 0x10
  jal   get_video2_settings_height
   move  $s0, $t2
  lw    $a1, 0x44($sp)
  li    $at, 100
  addu  $t6, $v0, $s0
  div   $zero, $a1, $at
  mfhi  $t3
  li    $at, 10
  addiu $t5, $t6, -0x12
  div   $zero, $t3, $at
  mflo  $a1
  li    $t7, 2
  li    $t9, 1
  sw    $t9, 0x18($sp)
  sw    $t7, 0x14($sp)
  sw    $t5, 0x10($sp)
  move  $a0, $s1
  li    $a2, 130
  jal   display_ammo_total_in_a1
   li    $a3, 2
  jal   get_video2_settings_uly
   move  $s1, $v0
  sll   $s0, $v0, 0x10
  sra   $t8, $s0, 0x10
  jal   get_video2_settings_height
   move  $s0, $t8
  lw    $a1, 0x44($sp)
  li    $at, 10
  addu  $t0, $v0, $s0
  div   $zero, $a1, $at
  mfhi  $a1
  addiu $t2, $t0, -0x12
  li    $t3, 2
  li    $t4, 1
  sw    $t4, 0x18($sp)
  sw    $t3, 0x14($sp)
  sw    $t2, 0x10($sp)
  move  $a0, $s1
  li    $a2, 138
  jal   display_ammo_total_in_a1
   li    $a3, 2
  jal   get_video2_settings_uly
   move  $s1, $v0
  sll   $s0, $v0, 0x10
  sra   $t6, $s0, 0x10
  jal   get_video2_settings_height
   move  $s0, $t6
  addu  $t5, $v0, $s0
  addiu $t7, $t5, -0x12
  lui   $a1, %hi(D_80052A44)
  li    $t9, 2
  li    $t8, 1
  sw    $t8, 0x18($sp)
  sw    $t9, 0x14($sp)
  addiu $a1, %lo(D_80052A44) # addiu $a1, $a1, 0x2a44
  sw    $t7, 0x10($sp)
  move  $a0, $s1
  li    $a2, 147
  jal   some_kind_of_display_routine
   li    $a3, 2
  jal   get_video2_settings_uly
   move  $s1, $v0
  sll   $s0, $v0, 0x10
  sra   $t1, $s0, 0x10
  jal   get_video2_settings_height
   move  $s0, $t1
  lw    $a1, 0x40($sp)
  li    $at, 60
  addu  $t3, $v0, $s0
  div   $zero, $a1, $at
  mfhi  $t0
  li    $at, 10
  addiu $t4, $t3, -0x12
  div   $zero, $t0, $at
  mflo  $a1
  li    $t6, 2
  li    $t5, 1
  sw    $t5, 0x18($sp)
  sw    $t6, 0x14($sp)
  sw    $t4, 0x10($sp)
  move  $a0, $s1
  li    $a2, 156
  jal   display_ammo_total_in_a1
   li    $a3, 2
  jal   get_video2_settings_uly
   move  $s1, $v0
  sll   $s0, $v0, 0x10
  sra   $t7, $s0, 0x10
  jal   get_video2_settings_height
   move  $s0, $t7
  lw    $a1, 0x40($sp)
  li    $at, 10
  addu  $t8, $v0, $s0
  div   $zero, $a1, $at
  mfhi  $a1
  addiu $t1, $t8, -0x12
  li    $t0, 2
  li    $t2, 1
  sw    $t2, 0x18($sp)
  sw    $t0, 0x14($sp)
  sw    $t1, 0x10($sp)
  move  $a0, $s1
  li    $a2, 164
  jal   display_ammo_total_in_a1
   li    $a3, 2
  jal   get_video2_settings_uly
   move  $s1, $v0
  sll   $s0, $v0, 0x10
  sra   $t3, $s0, 0x10
  jal   get_video2_settings_height
   move  $s0, $t3
  addu  $t4, $v0, $s0
  addiu $t6, $t4, -0x12
  lui   $a1, %hi(D_80052A44)
  li    $t5, 2
  li    $t7, 1
  sw    $t7, 0x18($sp)
  sw    $t5, 0x14($sp)
  addiu $a1, %lo(D_80052A44) # addiu $a1, $a1, 0x2a44
  sw    $t6, 0x10($sp)
  move  $a0, $s1
  li    $a2, 173
  jal   some_kind_of_display_routine
   li    $a3, 2
  jal   get_video2_settings_uly
   move  $s1, $v0
  sll   $s0, $v0, 0x10
  sra   $t9, $s0, 0x10
  jal   get_video2_settings_height
   move  $s0, $t9
  lw    $a1, 0x3c($sp)
  li    $at, 100
  addu  $t0, $v0, $s0
  div   $zero, $a1, $at
  mfhi  $t8
  li    $at, 10
  addiu $t2, $t0, -0x12
  div   $zero, $t8, $at
  mflo  $a1
  li    $t3, 2
  li    $t4, 1
  sw    $t4, 0x18($sp)
  sw    $t3, 0x14($sp)
  sw    $t2, 0x10($sp)
  move  $a0, $s1
  li    $a2, 182
  jal   display_ammo_total_in_a1
   li    $a3, 2
  jal   get_video2_settings_uly
   move  $s1, $v0
  sll   $s0, $v0, 0x10
  sra   $t6, $s0, 0x10
  jal   get_video2_settings_height
   move  $s0, $t6
  lw    $a1, 0x3c($sp)
  li    $at, 10
  addu  $t7, $v0, $s0
  div   $zero, $a1, $at
  mfhi  $a1
  addiu $t9, $t7, -0x12
  li    $t8, 2
  li    $t1, 1
  sw    $t1, 0x18($sp)
  sw    $t8, 0x14($sp)
  sw    $t9, 0x10($sp)
  move  $a0, $s1
  li    $a2, 190
  jal   display_ammo_total_in_a1
   li    $a3, 2
  jal   combiner_bayer_lod_perspective
   move  $a0, $v0
  move  $s1, $v0
.L7F0565D8:
  lw    $ra, 0x2c($sp)
  move  $v0, $s1
  lw    $s1, 0x28($sp)
  lw    $s0, 0x24($sp)
  jr    $ra
   addiu $sp, $sp, 0x48
");

void handle_alarm_gas_timer_calldamage(void) {
  if (is_alarm_on()) {
    if ((ptr_alarm_sfx == 0) && (get_controls_locked_flag() == 0))
      play_sfx_a1(ptr_sfx_buf, 0xa3, &ptr_alarm_sfx);
    alarm_timer += clock_timer;
    if (1800 < alarm_timer)
      stop_alarm();
  }
  handle_gas_damage();
  if_enabled_reset_clock();
  check_guard_detonate_proxmine();
  D_80030AF4 = 0;
}

asm(R"
glabel sub_GAME_7F056690
  addiu $sp, $sp, -0x30
  sw    $ra, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  jal   get_ptr_obj_pos_list_current_entry
   sw    $s0, 0x18($sp)
  beqz  $v0, .L7F05675C
   move  $s2, $v0
  li    $s4, 1
  lbu   $t6, ($s2)
.L7F0566C0:
  bnel  $s4, $t6, .L7F056754
   lw    $s2, 0x24($s2)
  lbu   $t7, 1($s2)
  andi  $t8, $t7, 2
  bnezl $t8, .L7F056754
   lw    $s2, 0x24($s2)
  lw    $s1, 4($s2)
  lbu   $t9, 2($s1)
  move  $a0, $s1
  andi  $t0, $t9, 0x80
  beql  $t0, $zero, .L7F056754
   lw    $s2, 0x24($s2)
  jal   sub_GAME_7F04B478
   lw    $s3, 0x14($s1)
  beqz  $v0, .L7F05675C
   move  $a1, $v0
  lw    $s0, 4($v0)
  beql  $s0, $zero, .L7F056760
   lw    $ra, 0x2c($sp)
  lw    $t1, 0x14($s1)
  jal   sub_GAME_7F04B590
   lw    $a0, 8($t1)
  beql  $v0, $zero, .L7F056754
   lw    $s2, 0x24($s2)
  lhu   $t3, 0x1a($s0)
  lw    $t2, 0x10($s3)
  lw    $t5, 8($s0)
  sll   $t4, $t3, 2
  addu  $v0, $t2, $t4
  lw    $t6, ($v0)
  beq   $t5, $t6, .L7F056750
   move  $a0, $s1
  jal   sub_GAME_7F041024
   li    $a1, 1
  b     .L7F056760
   lw    $ra, 0x2c($sp)
.L7F056750:
  lw    $s2, 0x24($s2)
.L7F056754:
  bnezl $s2, .L7F0566C0
   lbu   $t6, ($s2)
.L7F05675C:
  lw    $ra, 0x2c($sp)
.L7F056760:
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  lw    $s3, 0x24($sp)
  lw    $s4, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x30
");

asm(R"
glabel drop_inventory
  addiu $sp, $sp, -0x38
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  sw    $ra, 0x34($sp)
  sw    $s4, 0x30($sp)
  sw    $s3, 0x2c($sp)
  sw    $s2, 0x28($sp)
  sw    $s1, 0x24($sp)
  sw    $s0, 0x20($sp)
  lw    $t7, 0xa8($t6)
  move  $a1, $zero
  lw    $s2, 4($t7)
  jal   set_0x4_in_runtime_flags_for_item_in_guards_hand
   move  $a0, $s2
  move  $a0, $s2
  jal   set_0x4_in_runtime_flags_for_item_in_guards_hand
   li    $a1, 1
  li    $s0, 1
  li    $s4, 89
  lui   $s3, 0x2000
.L7F0567CC:
  jal   sub_GAME_7F09B244
   move  $a0, $s0
  bltz  $v0, .L7F056820
   move  $s1, $v0
  jal   is_weapon_in_inv
   move  $a0, $s0
  beqz  $v0, .L7F056820
   move  $a0, $s2
  move  $a1, $s1
  move  $a2, $s0
  move  $a3, $s3
  sw    $zero, 0x10($sp)
  jal   something_with_generating_object
   sw    $zero, 0x14($sp)
  beqz  $v0, .L7F056820
   move  $s1, $v0
  move  $a0, $v0
  jal   sub_GAME_7F04BFD0
   li    $a1, 1
  jal   sub_GAME_7F04C130
   move  $a0, $s1
.L7F056820:
  addiu $s0, $s0, 1
  bne   $s0, $s4, .L7F0567CC
   nop   
  lw    $ra, 0x34($sp)
  lw    $s0, 0x20($sp)
  lw    $s1, 0x24($sp)
  lw    $s2, 0x28($sp)
  lw    $s3, 0x2c($sp)
  lw    $s4, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x38
");
