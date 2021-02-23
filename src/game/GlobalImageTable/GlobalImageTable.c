#include "bondtypes.h"

typedef struct sGlobalImageTable {
  unsigned int globalDL_0x000[30];
  unsigned int globalDL_0x078[42];
  unsigned int globalDL_0x120[42];
  unsigned int globalDL_0x1c8[42];
  unsigned int globalDL_0x270[42];
  unsigned int globalDL_0x318[42];
  unsigned int globalDL_0x3c0[42];
  unsigned int globalDL_0x468[42];
  unsigned int globalDL_0x510[42];
  unsigned int globalDL_0x5b8[42];
  unsigned int globalDL_0x660[42];
  unsigned int globalDL_0x708[42];
  unsigned int globalDL_0x7b0[42];
  unsigned int globalDL_0x858[42];
  unsigned int globalDL_0x900[42];
  unsigned int globalDL_0x9a8[42];
  unsigned int globalDL_0xa50[30];
  struct sImageTableEntry s_genericimage[1];
  struct sImageTableEntry s_impactimages[20];
  struct sImageTableEntry s_explosion_smokeimages[6];
  struct sImageTableEntry s_scattered_explosions[5];
  struct sImageTableEntry s_flareimage1[1];
  struct sImageTableEntry s_flareimage2[1];
  struct sImageTableEntry s_flareimage3[1];
  struct sImageTableEntry s_flareimage4[1];
  struct sImageTableEntry s_flareimage5[1];
  struct sImageTableEntry s_ammo9mmimage[1];
  struct sImageTableEntry s_rifleammoimage[1];
  struct sImageTableEntry s_shotgunammoimage[1];
  struct sImageTableEntry s_knifeammoimage[1];
  struct sImageTableEntry s_glammoimage[1];
  struct sImageTableEntry s_rocketammoimage[1];
  struct sImageTableEntry s_genericmineammoimage[1];
  struct sImageTableEntry s_grenadeammoimage[1];
  struct sImageTableEntry s_magnumammoimage[1];
  struct sImageTableEntry s_goldengunammoimage[1];
  struct sImageTableEntry s_remotemineammoimage[1];
  struct sImageTableEntry s_timedmineammoimage[1];
  struct sImageTableEntry s_proxmineammoimage[1];
  struct sImageTableEntry s_tankammoimage[1];
  struct sImageTableEntry s_crosshairimage[1];
  struct sImageTableEntry s_betacrosshairimage[1];
  struct sImageTableEntry s_glassoverlayimage[2];
  struct sImageTableEntry s_monitorimages[50];
  struct sImageTableEntry s_skywaterimages[3];
  struct sImageTableEntry s_mainfolderimages[6];
  struct sImageTableEntry s_mpradarimages[1];
  struct sImageTableEntry s_mpcharselimages[64];
  struct sImageTableEntry s_mpstageselimages[17];
} sGlobalImageTable;

struct sGlobalImageTable GlobalImageTable = {
    {// globalDL_0x000
     0xE7000000, 0x00000000, 0xBA001402, 0x00000000, 0xB900031D, 0x00504B50,
     0xBA001001, 0x00000000, 0xFC121824, 0xFF33FFFF, 0xBB000001, 0xFFFFFFFF,
     0xFD700000, 0xABCD083A, 0xF5700000, 0x07000000, 0xE6000000, 0x00000000,
     0xF3000000, 0x0761F125, 0xF5680E00, 0x00018060, 0xF2000000, 0x000DC0DC,
     0xBA000E02, 0x00000000, 0xE7000000, 0x00000000, 0xB8000000, 0x00000000},

    {// globalDL_0x078
     0xE7000000, 0x00000000, 0xBA001402, 0x00100000, 0xB900031D, 0x0C184B50,
     0xBA001001, 0x00000000, 0xFC111404, 0xFF13FFFF, 0xBB000001, 0xFFFFFFFF,
     0xFD700000, 0xABCD0824, 0xF5700000, 0x07000000, 0xE6000000, 0x00000000,
     0xF3000000, 0x0761F125, 0xF5680E00, 0x00018060, 0xF2000000, 0x000DC0DC,
     0xFD100000, 0xABCD0825, 0xF5100188, 0x07000000, 0xE6000000, 0x00000000,
     0xF3000000, 0x070DF200, 0xF5100988, 0x01090A42, 0xF2000000, 0x010DC0DC,
     0xBA000E02, 0x00000000, 0xE7000000, 0x00000000, 0xB8000000, 0x00000000},

    {// globalDL_0x120
     0xE7000000, 0x00000000, 0xBA001402, 0x00100000, 0xB900031D, 0x0C184B50,
     0xBA001001, 0x00000000, 0xFC111404, 0xFF13FFFF, 0xBB000001, 0xFFFFFFFF,
     0xFD700000, 0xABCD0828, 0xF5700000, 0x07000000, 0xE6000000, 0x00000000,
     0xF3000000, 0x0761F125, 0xF5680E00, 0x00018060, 0xF2000000, 0x000DC0DC,
     0xFD100000, 0xABCD0829, 0xF5100188, 0x07000000, 0xE6000000, 0x00000000,
     0xF3000000, 0x070DF200, 0xF5100988, 0x01090A42, 0xF2000000, 0x010DC0DC,
     0xBA000E02, 0x00000000, 0xE7000000, 0x00000000, 0xB8000000, 0x00000000},

    {// globalDL_0x1c8
     0xE7000000, 0x00000000, 0xBA001402, 0x00100000, 0xB900031D, 0x0C184B50,
     0xBA001001, 0x00000000, 0xFC111404, 0xFF13FFFF, 0xBB000001, 0xFFFFFFFF,
     0xFD700000, 0xABCD0832, 0xF5700000, 0x07000000, 0xE6000000, 0x00000000,
     0xF3000000, 0x0761F125, 0xF5680E00, 0x00018060, 0xF2000000, 0x000DC0DC,
     0xFD100000, 0xABCD0833, 0xF5100188, 0x07000000, 0xE6000000, 0x00000000,
     0xF3000000, 0x070DF200, 0xF5100988, 0x01090A42, 0xF2000000, 0x010DC0DC,
     0xBA000E02, 0x00000000, 0xE7000000, 0x00000000, 0xB8000000, 0x00000000},

    {// globalDL_0x270
     0xE7000000, 0x00000000, 0xBA001402, 0x00100000, 0xB900031D, 0x0C184B50,
     0xBA001001, 0x00000000, 0xFC111404, 0xFF13FFFF, 0xBB000001, 0xFFFFFFFF,
     0xFD700000, 0xABCD0834, 0xF5700000, 0x07000000, 0xE6000000, 0x00000000,
     0xF3000000, 0x0761F125, 0xF5680E00, 0x00018060, 0xF2000000, 0x000DC0DC,
     0xFD100000, 0xABCD0835, 0xF5100188, 0x07000000, 0xE6000000, 0x00000000,
     0xF3000000, 0x070DF200, 0xF5100988, 0x01090A42, 0xF2000000, 0x010DC0DC,
     0xBA000E02, 0x00000000, 0xE7000000, 0x00000000, 0xB8000000, 0x00000000},

    {// globalDL_0x318
     0xE7000000, 0x00000000, 0xBA001402, 0x00100000, 0xB900031D, 0x0C184B50,
     0xBA001001, 0x00000000, 0xFC111404, 0xFF13FFFF, 0xBB000001, 0xFFFFFFFF,
     0xFD700000, 0xABCD0836, 0xF5700000, 0x07000000, 0xE6000000, 0x00000000,
     0xF3000000, 0x0761F125, 0xF5680E00, 0x00018060, 0xF2000000, 0x000DC0DC,
     0xFD100000, 0xABCD0837, 0xF5100188, 0x07000000, 0xE6000000, 0x00000000,
     0xF3000000, 0x070DF200, 0xF5100988, 0x01090A42, 0xF2000000, 0x010DC0DC,
     0xBA000E02, 0x00000000, 0xE7000000, 0x00000000, 0xB8000000, 0x00000000},

    {// globalDL_0x3c0
     0xE7000000, 0x00000000, 0xBA001402, 0x00100000, 0xB900031D, 0x0C184B50,
     0xBA001001, 0x00000000, 0xFC111404, 0xFF13FFFF, 0xBB000001, 0xFFFFFFFF,
     0xFD700000, 0xABCD0838, 0xF5700000, 0x07000000, 0xE6000000, 0x00000000,
     0xF3000000, 0x0761F125, 0xF5680E00, 0x00018060, 0xF2000000, 0x000DC0DC,
     0xFD100000, 0xABCD0839, 0xF5100188, 0x07000000, 0xE6000000, 0x00000000,
     0xF3000000, 0x070DF200, 0xF5100988, 0x01090A42, 0xF2000000, 0x010DC0DC,
     0xBA000E02, 0x00000000, 0xE7000000, 0x00000000, 0xB8000000, 0x00000000},

    {// globalDL_0x468
     0xE7000000, 0x00000000, 0xBA001402, 0x00100000, 0xB900031D, 0x0C184B50,
     0xBA001001, 0x00000000, 0xFC111404, 0xFF13FFFF, 0xBB000001, 0xFFFFFFFF,
     0xFD700000, 0xABCD083A, 0xF5700000, 0x07000000, 0xE6000000, 0x00000000,
     0xF3000000, 0x0761F125, 0xF5680E00, 0x00018060, 0xF2000000, 0x000DC0DC,
     0xFD100000, 0xABCD083B, 0xF5100188, 0x07000000, 0xE6000000, 0x00000000,
     0xF3000000, 0x070DF200, 0xF5100988, 0x01090A42, 0xF2000000, 0x010DC0DC,
     0xBA000E02, 0x00000000, 0xE7000000, 0x00000000, 0xB8000000, 0x00000000},

    {// globalDL_0x510
     0xE7000000, 0x00000000, 0xBA001402, 0x00100000, 0xB900031D, 0x0C184B50,
     0xBA001001, 0x00000000, 0xFC111404, 0xFF13FFFF, 0xBB000001, 0xFFFFFFFF,
     0xFD700000, 0xABCD083C, 0xF5700000, 0x07000000, 0xE6000000, 0x00000000,
     0xF3000000, 0x0761F125, 0xF5680E00, 0x00018060, 0xF2000000, 0x000DC0DC,
     0xFD100000, 0xABCD083D, 0xF5100188, 0x07000000, 0xE6000000, 0x00000000,
     0xF3000000, 0x070DF200, 0xF5100988, 0x01090A42, 0xF2000000, 0x010DC0DC,
     0xBA000E02, 0x00000000, 0xE7000000, 0x00000000, 0xB8000000, 0x00000000},

    {// globalDL_0x5b8
     0xE7000000, 0x00000000, 0xBA001402, 0x00100000, 0xB900031D, 0x0C184B50,
     0xBA001001, 0x00000000, 0xFC111404, 0xFF13FFFF, 0xBB000001, 0xFFFFFFFF,
     0xFD700000, 0xABCD083E, 0xF5700000, 0x07000000, 0xE6000000, 0x00000000,
     0xF3000000, 0x0761F125, 0xF5680E00, 0x00018060, 0xF2000000, 0x000DC0DC,
     0xFD100000, 0xABCD083F, 0xF5100188, 0x07000000, 0xE6000000, 0x00000000,
     0xF3000000, 0x070DF200, 0xF5100988, 0x01090A42, 0xF2000000, 0x010DC0DC,
     0xBA000E02, 0x00000000, 0xE7000000, 0x00000000, 0xB8000000, 0x00000000},

    {// globalDL_0x660
     0xE7000000, 0x00000000, 0xBA001402, 0x00100000, 0xB900031D, 0x0C184B50,
     0xBA001001, 0x00000000, 0xFC111404, 0xFF13FFFF, 0xBB000001, 0xFFFFFFFF,
     0xFD700000, 0xABCD0840, 0xF5700000, 0x07000000, 0xE6000000, 0x00000000,
     0xF3000000, 0x0761F125, 0xF5680E00, 0x00018060, 0xF2000000, 0x000DC0DC,
     0xFD100000, 0xABCD0841, 0xF5100188, 0x07000000, 0xE6000000, 0x00000000,
     0xF3000000, 0x070DF200, 0xF5100988, 0x01090A42, 0xF2000000, 0x010DC0DC,
     0xBA000E02, 0x00000000, 0xE7000000, 0x00000000, 0xB8000000, 0x00000000},

    {// globalDL_0x708
     0xE7000000, 0x00000000, 0xBA001402, 0x00100000, 0xB900031D, 0x0C184B50,
     0xBA001001, 0x00000000, 0xFC111404, 0xFF13FFFF, 0xBB000001, 0xFFFFFFFF,
     0xFD700000, 0xABCD0826, 0xF5700000, 0x07000000, 0xE6000000, 0x00000000,
     0xF3000000, 0x0761F125, 0xF5680E00, 0x00018060, 0xF2000000, 0x000DC0DC,
     0xFD100000, 0xABCD0827, 0xF5100188, 0x07000000, 0xE6000000, 0x00000000,
     0xF3000000, 0x070DF200, 0xF5100988, 0x01090A42, 0xF2000000, 0x010DC0DC,
     0xBA000E02, 0x00000000, 0xE7000000, 0x00000000, 0xB8000000, 0x00000000},

    {// globalDL_0x7b0
     0xE7000000, 0x00000000, 0xBA001402, 0x00100000, 0xB900031D, 0x0C184B50,
     0xBA001001, 0x00000000, 0xFC111404, 0xFF13FFFF, 0xBB000001, 0xFFFFFFFF,
     0xFD700000, 0xABCD082A, 0xF5700000, 0x07000000, 0xE6000000, 0x00000000,
     0xF3000000, 0x0761F125, 0xF5680E00, 0x00018060, 0xF2000000, 0x000DC0DC,
     0xFD100000, 0xABCD082B, 0xF5100188, 0x07000000, 0xE6000000, 0x00000000,
     0xF3000000, 0x070DF200, 0xF5100988, 0x01090A42, 0xF2000000, 0x010DC0DC,
     0xBA000E02, 0x00000000, 0xE7000000, 0x00000000, 0xB8000000, 0x00000000},

    {// globalDL_0x858
     0xE7000000, 0x00000000, 0xBA001402, 0x00100000, 0xB900031D, 0x0C184B50,
     0xBA001001, 0x00000000, 0xFC111404, 0xFF13FFFF, 0xBB000001, 0xFFFFFFFF,
     0xFD700000, 0xABCD082C, 0xF5700000, 0x07000000, 0xE6000000, 0x00000000,
     0xF3000000, 0x0761F125, 0xF5680E00, 0x00018060, 0xF2000000, 0x000DC0DC,
     0xFD100000, 0xABCD082D, 0xF5100188, 0x07000000, 0xE6000000, 0x00000000,
     0xF3000000, 0x070DF200, 0xF5100988, 0x01090A42, 0xF2000000, 0x010DC0DC,
     0xBA000E02, 0x00000000, 0xE7000000, 0x00000000, 0xB8000000, 0x00000000},

    {// globalDL_0x900
     0xE7000000, 0x00000000, 0xBA001402, 0x00100000, 0xB900031D, 0x0C184B50,
     0xBA001001, 0x00000000, 0xFC111404, 0xFF13FFFF, 0xBB000001, 0xFFFFFFFF,
     0xFD700000, 0xABCD082E, 0xF5700000, 0x07000000, 0xE6000000, 0x00000000,
     0xF3000000, 0x0761F125, 0xF5680E00, 0x00018060, 0xF2000000, 0x000DC0DC,
     0xFD100000, 0xABCD082F, 0xF5100188, 0x07000000, 0xE6000000, 0x00000000,
     0xF3000000, 0x070DF200, 0xF5100988, 0x01090A42, 0xF2000000, 0x010DC0DC,
     0xBA000E02, 0x00000000, 0xE7000000, 0x00000000, 0xB8000000, 0x00000000},

    {// globalDL_0x9a8
     0xE7000000, 0x00000000, 0xBA001402, 0x00100000, 0xB900031D, 0x0C184B50,
     0xBA001001, 0x00000000, 0xFC111404, 0xFF13FFFF, 0xBB000001, 0xFFFFFFFF,
     0xFD700000, 0xABCD0830, 0xF5700000, 0x07000000, 0xE6000000, 0x00000000,
     0xF3000000, 0x0761F125, 0xF5680E00, 0x00018060, 0xF2000000, 0x000DC0DC,
     0xFD100000, 0xABCD0831, 0xF5100188, 0x07000000, 0xE6000000, 0x00000000,
     0xF3000000, 0x070DF200, 0xF5100988, 0x01090A42, 0xF2000000, 0x010DC0DC,
     0xBA000E02, 0x00000000, 0xE7000000, 0x00000000, 0xB8000000, 0x00000000},

    {// globalDL_0xa50
     0xE7000000, 0x00000000, 0xBA001402, 0x00000000, 0xB900031D, 0x00552078,
     0xBA001001, 0x00000000, 0xFC121824, 0xFF33FFFF, 0xBB000001, 0xFFFFFFFF,
     0xFD700000, 0xABCD03F7, 0xF5700000, 0x07000000, 0xE6000000, 0x00000000,
     0xF3000000, 0x071FF200, 0xE7000000, 0x00000000, 0xF5680800, 0x00014050,
     0xF2000000, 0x0007C07C, 0xBA000E02, 0x00000000, 0xB8000000, 0x00000000},

    {// s_genericimage
     {0x858, 0x36, 0x36, 3, F_IA, D_8BIT, MIRROR, MIRROR, 0}},

    {// s_impactimages
     {0x878, 0x30, 0x30, 6, F_IA, D_8BIT, MIRROR, MIRROR, 0},
     {0x879, 0x40, 0x20, 7, F_IA, D_8BIT, MIRROR, MIRROR, 0},
     {0x87A, 0x40, 0x40, 0, F_IA, D_8BIT, MIRROR, MIRROR, 0},
     {0xCE, 0x40, 0x20, 7, F_IA, D_8BIT, MIRROR, MIRROR, 0},
     {0x878, 0x30, 0x30, 6, F_IA, D_8BIT, MIRROR, MIRROR, 0},
     {0x878, 0x30, 0x30, 6, F_IA, D_8BIT, MIRROR, MIRROR, 0},
     {0x878, 0x30, 0x30, 6, F_IA, D_8BIT, MIRROR, MIRROR, 0},
     {0x87B, 0x20, 0x20, 0, F_IA, D_8BIT, MIRROR, MIRROR, 0},
     {0x87C, 0x20, 0x20, 0, F_RGBA, D_16BIT, MIRROR, MIRROR, 0},
     {0x5C3, 0x20, 0x20, 6, F_RGBA, D_16BIT, MIRROR, MIRROR, 0},
     {0x87D, 0x20, 0x20, 6, F_RGBA, D_16BIT, MIRROR, MIRROR, 0},
     {0x5C4, 0x20, 0x20, 6, F_RGBA, D_16BIT, MIRROR, MIRROR, 0},
     {0x87E, 0x20, 0x20, 6, F_RGBA, D_16BIT, MIRROR, MIRROR, 0},
     {0x87F, 0x20, 0x20, 6, F_RGBA, D_16BIT, MIRROR, MIRROR, 0},
     {0x5C6, 0x20, 0x20, 6, F_RGBA, D_16BIT, MIRROR, MIRROR, 0},
     {0x5C7, 0x20, 0x20, 6, F_RGBA, D_16BIT, MIRROR, MIRROR, 0},
     {0x87A, 0x40, 0x40, 0, F_IA, D_8BIT, MIRROR, MIRROR, 0},
     {0x878, 0x30, 0x30, 6, F_IA, D_8BIT, MIRROR, MIRROR, 0},
     {0x878, 0x30, 0x30, 6, F_IA, D_8BIT, MIRROR, MIRROR, 0},
     {0x878, 0x30, 0x30, 6, F_IA, D_8BIT, MIRROR, MIRROR, 0}},

    {// s_explosion_smokeimages
     {0x880, 0x40, 0x40, 0, F_IA, D_8BIT, 0, 0, 0},
     {0x881, 0x40, 0x40, 0, F_IA, D_8BIT, 0, 0, 0},
     {0x882, 0x40, 0x40, 0, F_IA, D_8BIT, 0, 0, 0},
     {0x883, 0x40, 0x40, 0, F_IA, D_8BIT, 0, 0, 0},
     {0x884, 0x40, 0x40, 0, F_IA, D_8BIT, 0, 0, 0},
     {0x885, 0x40, 0x40, 0, F_IA, D_8BIT, 0, 0, 0}},

    {// s_scattered_explosions
     {0x886, 0x40, 0x40, 0, F_IA, D_8BIT, 0, 0, 0},
     {0x887, 0x40, 0x40, 0, F_IA, D_8BIT, 0, 0, 0},
     {0x888, 0x40, 0x40, 0, F_IA, D_8BIT, 0, 0, 0},
     {0x889, 0x40, 0x40, 0, F_IA, D_8BIT, 0, 0, 0},
     {0x88A, 0x40, 0x40, 0, F_IA, D_8BIT, 0, 0, 0}},

    {// s_flareimage1
     {0x8B5, 0x40, 0x40, 0, F_IA, D_8BIT, 0, 0, 0}},

    {// s_flareimage2
     {0x8B6, 0x40, 0x40, 0, F_IA, D_8BIT, 0, 0, 0}},

    {// s_flareimage3
     {0x850, 0x10, 0x20, 6, F_RGBA, D_32BIT, 0, 0, 0}},

    {// s_flareimage4
     {0x857, 0x10, 0x20, 6, F_RGBA, D_32BIT, 0, 0, 0}},

    {// s_flareimage5
     {0x856, 0x20, 0x20, 0, F_RGBA, D_32BIT, 0, 0, 0}},

    {// s_ammo9mmimage
     {0x8B7, 5, 0xC, 0, F_RGBA, D_32BIT, MIRROR, MIRROR, 0}},

    {// s_rifleammoimage
     {0x8B8, 5, 0x1C, 0, F_RGBA, D_32BIT, MIRROR, MIRROR, 0}},

    {// s_shotgunammoimage
     {0x877, 6, 0x14, 0, F_RGBA, D_32BIT, MIRROR, MIRROR, 0}},

    {// s_knifeammoimage
     {0x876, 6, 0x18, 0, F_RGBA, D_32BIT, MIRROR, MIRROR, 0}},

    {// s_glammoimage
     {0x875, 8, 0x15, 0, F_RGBA, D_32BIT, 0, MIRROR, 0}},

    {// s_rocketammoimage
     {0x871, 7, 0x16, 0, F_RGBA, D_32BIT, MIRROR, MIRROR, 0}},

    {// s_genericmineammoimage
     {0x872, 0xE, 0xE, 0, F_RGBA, D_32BIT, MIRROR, MIRROR, 0}},

    {// s_grenadeammoimage
     {0x873, 0xE, 0x12, 0, F_RGBA, D_32BIT, MIRROR, MIRROR, 0}},

    {// s_magnumammoimage
     {0x874, 5, 0xF, 0, F_RGBA, D_32BIT, MIRROR, MIRROR, 0}},

    {// s_goldengunammoimage
     {0x8B9, 5, 0xC, 0, F_RGBA, D_32BIT, MIRROR, MIRROR, 0}},

    {// s_remotemineammoimage
     {0x8BA, 0xE, 0xE, 0, F_RGBA, D_32BIT, MIRROR, MIRROR, 0}},

    {// s_timedmineammoimage
     {0x8BE, 0xE, 0xE, 0, F_RGBA, D_32BIT, MIRROR, MIRROR, 0}},

    {// s_proxmineammoimage
     {0x8BB, 0xE, 0xE, 0, F_RGBA, D_32BIT, MIRROR, MIRROR, 0}},

    {// s_tankammoimage
     {0x9A0, 7, 0x16, 0, F_IA, D_8BIT, MIRROR, MIRROR, 0}},

    {// s_crosshairimage
     {0x8BC, 0x20, 0x20, 0, F_RGBA, D_32BIT, 0, 0, 0}},

    {// s_betacrosshairimage
     {0x8BD, 0x20, 0x20, 0, F_RGBA, D_32BIT, 0, 0, 0}},

    {// s_glassoverlayimage
     {0x292, 0x20, 1, 6, F_IA, D_8BIT, 0, 0, 0},
     {0x28E, 0x36, 0x36, 3, F_IA, D_8BIT, MIRROR, MIRROR, 0}},

    {// s_monitorimages
     {0x88B, 0x20, 0x20, 0, F_I, D_8BIT, 0, 0, 0},
     {0x88C, 0x80, 0x10, 0, F_I, D_8BIT, 0, 0, 0},
     {0x88D, 0x80, 0x10, 0, F_I, D_8BIT, 0, 0, 0},
     {0x88E, 0x80, 0x10, 0, F_I, D_8BIT, 0, 0, 0},
     {0x88F, 0x80, 0x10, 0, F_I, D_8BIT, 0, 0, 0},
     {0x890, 0x80, 0x10, 0, F_I, D_8BIT, 0, 0, 0},
     {0x891, 0x80, 0x10, 0, F_I, D_8BIT, 0, 0, 0},
     {0x892, 0x20, 0x20, 6, F_RGBA, D_16BIT, 0, 0, 0},
     {0x893, 0x20, 0x20, 6, F_RGBA, D_16BIT, 0, 0, 0},
     {0x894, 0x20, 0x20, 6, F_RGBA, D_16BIT, 0, 0, 0},
     {0x895, 0x20, 0x20, 6, F_RGBA, D_16BIT, 0, 0, 0},
     {0x4A1, 0x20, 0x20, 6, F_RGBA, D_16BIT, 0, 0, 0},
     {0x896, 0x20, 0x20, 6, F_RGBA, D_16BIT, 0, 0, 0},
     {0x897, 0x20, 0x20, 6, F_RGBA, D_16BIT, 0, 0, 0},
     {0x4A2, 0x20, 0x20, 6, F_RGBA, D_16BIT, 0, 0, 0},
     {0x4A3, 0x20, 0x20, 6, F_RGBA, D_16BIT, 0, 0, 0},
     {0x898, 0x10, 0x10, 5, F_I, D_8BIT, 0, 0, 0},
     {0x246, 0x20, 0x20, 6, F_RGBA, D_16BIT, 0, 0, 0},
     {0x247, 0x20, 0x20, 6, F_RGBA, D_16BIT, 0, 0, 0},
     {0x248, 0x20, 0x20, 6, F_RGBA, D_16BIT, 0, 0, 0},
     {0x899, 0x20, 0x20, 6, F_RGBA, D_16BIT, 0, 0, 0},
     {0x89A, 0x20, 0x20, 6, F_RGBA, D_16BIT, 0, 0, 0},
     {0x89B, 0x20, 0x20, 6, F_RGBA, D_16BIT, 0, 0, 0},
     {0x89C, 0x20, 0x20, 6, F_RGBA, D_16BIT, 0, 0, 0},
     {0x245, 0x20, 0x20, 6, F_RGBA, D_16BIT, 0, 0, 0},
     {0x89D, 0x20, 0x20, 6, F_RGBA, D_16BIT, 0, 0, 0},
     {0x89E, 0x20, 0x20, 6, F_RGBA, D_16BIT, 0, 0, 0},
     {0x8B3, 0x40, 0x40, 0, F_I, D_8BIT, 0, 0, 0},
     {0x8AF, 0x20, 0x20, 0, F_I, D_8BIT, 0, 0, 0},
     {0x8B0, 0x20, 0x20, 0, F_I, D_8BIT, 0, 0, 0},
     {0x8B1, 0x20, 0x20, 0, F_I, D_8BIT, 0, 0, 0},
     {0x8B2, 0x20, 0x20, 0, F_I, D_8BIT, 0, 0, 0},
     {0x8AB, 0x20, 0x20, 0, F_I, D_8BIT, 0, 0, 0},
     {0x8AC, 0x20, 0x20, 0, F_I, D_8BIT, 0, 0, 0},
     {0x8AD, 0x20, 0x20, 0, F_I, D_8BIT, 0, 0, 0},
     {0x8AE, 0x20, 0x20, 0, F_I, D_8BIT, 0, 0, 0},
     {0x8AA, 0x20, 0x20, 0, F_I, D_8BIT, 0, 0, 0},
     {0x89F, 0x20, 0x20, 0, F_I, D_8BIT, 0, 0, 0},
     {0x8A0, 0x20, 0x20, 0, F_I, D_8BIT, 0, 0, 0},
     {0x8A1, 0x20, 0x20, 0, F_I, D_8BIT, 0, 0, 0},
     {0x8A2, 0x20, 0x20, 6, F_I, D_8BIT, 0, 0, 0},
     {0x8A3, 0x20, 0x20, 6, F_I, D_8BIT, 0, 0, 0},
     {0x8A4, 0x20, 0x20, 6, F_I, D_8BIT, 0, 0, 0},
     {0x8A5, 0x20, 0x20, 6, F_I, D_8BIT, 0, 0, 0},
     {0x8A6, 0x80, 0x30, 0, F_I, D_8BIT, 0, MIRROR, 0},
     {0x8A7, 0x10, 0x10, 5, F_I, D_8BIT, 0, 0, 0},
     {0x8A8, 0x10, 0x10, 5, F_I, D_8BIT, 0, 0, 0},
     {0x8A9, 0x10, 0x10, 5, F_I, D_8BIT, 0, 0, 0},
     {0x8D7, 0x36, 0x36, 0, F_IA, D_8BIT, MIRROR, MIRROR, 0},
     {0x345, 0x20, 0x20, 6, F_RGBA, D_16BIT, 0, 0, 0}},

    {// s_skywaterimages
     {0x8B4, 0x40, 0x40, 0, F_IA, D_8BIT, 0, 0, 0},
     {0x5E4, 0x40, 0x40, 0, F_I, D_8BIT, 0, 0, 0},
     {0x5E5, 0x20, 0x20, 6, F_RGBA, D_16BIT, 0, 0, 0}},

    {// s_mainfolderimages
     {0, 0x20, 0x1C, 0, F_RGBA, D_32BIT, 0, MIRROR, 0},
     {2, 0x20, 0x1C, 0, F_RGBA, D_32BIT, 0, MIRROR, 0},
     {3, 0x7A, 0x12, 0, F_IA, D_8BIT, MIRROR, MIRROR, 0},
     {1, 0xF, 0xF, 0, F_IA, D_8BIT, MIRROR, MIRROR, 0},
     {4, 0x14, 0x14, 0, F_IA, D_8BIT, MIRROR, MIRROR, 0},
     {0xA47, 0x10, 0x10, 0, F_I, D_8BIT, 0, 0, 0}},

    {// s_mpradarimages
     {0xC8, 0x20, 0x20, 6, F_RGBA, D_16BIT, 0, 0, 0}},

    {// s_mpcharselimages
     {0xA2A, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA2B, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA2C, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA2D, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA32, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA33, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA34, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA35, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA36, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA37, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA38, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA39, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA2E, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA2F, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA30, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA31, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA48, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA49, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA4A, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA4B, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA4C, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA4D, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA4E, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA4F, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA50, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA51, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA52, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA53, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA54, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA55, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA56, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA57, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA58, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA59, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA5A, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA5B, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA5C, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA5D, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA5E, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA5F, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA60, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA61, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA62, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA63, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA64, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA65, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA66, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA67, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA68, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA69, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA6A, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA6B, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA6C, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA6D, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA6E, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA6F, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA7A, 0x41, 0x43, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA7B, 0x41, 0x43, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA7C, 0x41, 0x43, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA7D, 0x41, 0x43, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA86, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA85, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA83, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0},
     {0xA84, 0x41, 0x41, 7, F_I, D_4BIT, MIRROR, MIRROR, 0}},

    {// s_mpstageselimages
     {0xA20, 0x44, 0x2C, 0, F_I, D_8BIT, MIRROR, MIRROR, 0},
     {0xA16, 0x44, 0x2C, 0, F_I, D_8BIT, MIRROR, MIRROR, 0},
     {0xA12, 0x44, 0x2C, 0, F_I, D_8BIT, MIRROR, MIRROR, 0},
     {0xA19, 0x44, 0x2C, 0, F_I, D_8BIT, MIRROR, MIRROR, 0},
     {0xA14, 0x44, 0x2C, 0, F_I, D_8BIT, MIRROR, MIRROR, 0},
     {0xA1E, 0x44, 0x2C, 0, F_I, D_8BIT, MIRROR, MIRROR, 0},
     {0xA1B, 0x44, 0x2C, 0, F_I, D_8BIT, MIRROR, MIRROR, 0},
     {0xA24, 0x44, 0x2C, 0, F_I, D_8BIT, MIRROR, MIRROR, 0},
     {0xA17, 0x44, 0x2C, 0, F_I, D_8BIT, MIRROR, MIRROR, 0},
     {0xA15, 0x44, 0x2C, 0, F_I, D_8BIT, MIRROR, MIRROR, 0},
     {0xA18, 0x44, 0x2C, 0, F_I, D_8BIT, MIRROR, MIRROR, 0},
     {0xA1A, 0x44, 0x2C, 0, F_I, D_8BIT, MIRROR, MIRROR, 0},
     {0xA7E, 0x44, 0x2C, 0, F_I, D_8BIT, MIRROR, MIRROR, 0},
     {0xA7F, 0x44, 0x2C, 0, F_I, D_8BIT, MIRROR, MIRROR, 0},
     {0xA80, 0x44, 0x2C, 0, F_I, D_8BIT, MIRROR, MIRROR, 0},
     {0xA81, 0x44, 0x2C, 0, F_I, D_8BIT, MIRROR, MIRROR, 0},
     {0xA87, 0x44, 0x2C, 0, F_I, D_8BIT, MIRROR, MIRROR, 0}}};
