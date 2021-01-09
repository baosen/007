#include "bondtypes.h" // game structs and types
#include <gbi.h>

typedef struct {
  int levelID;
  void *bg_seg_filename, *bg_stan_filename;
  float levelscale, visibility, unknownfloat;
} levelentry;

int ptr_bg_data;
int ptr_clipping;
int dword_CODE_bss_8007BF98;
char list_visible_rooms_in_cur_global_vis_packet[0x98];
int num_visible_rooms_in_cur_global_vis_packet;
char dword_CODE_bss_8007C040[0x60];
char dword_CODE_bss_8007C0A0[0x60];
char dword_CODE_bss_8007C100[0x3E80];
int ptr_bgdata_portals;
int ptr_bgdata_offsets;
int dword_CODE_bss_8007FF88;
int ptr_bgdata_room_fileposition_list;
int dword_CODE_bss_8007FF90;
int dword_CODE_bss_8007FF94;
int dword_CODE_bss_8007FF98;
int dword_CODE_bss_8007FF9C;
int dword_CODE_bss_8007FFA0;

char dword_CODE_bss_8007FFA4;
char dword_CODE_bss_8007FFA5;
char dword_CODE_bss_8007FFA6;
char dword_CODE_bss_8007FFA7;
char dword_CODE_bss_8007FFA8[0x1658];
char dword_CODE_bss_80081600[0x18];
char table_for_portals[0xFA8];

int *ptr_bg_c_debug_debug_notice_list = 0;
float room_data_float1 = 1.0;
float room_data_float2 = 1.0;
float D_800413FC = 1.0;
int D_80041400 = 1;
int D_80041404 = 1;
int D_80041408 = 1;
int D_8004140C = -1;
int D_80041410 = -1;

typedef struct s_room_info {
  short bitflags;
  unsigned char model_bin_loaded;
  unsigned char bitflags2;
  void *ptr_point_index;
  void *ptr_expanded_mapping_info;
  void *ptr_secondary_expanded_mapping_info;
  int csize_point_index_binary;
  int csize_primary_DL_binary;
  int csize_secondary_DL_binary;
  int usize_point_index_binary;
  int usize_primary_DL_binary;
  int usize_secondary_DL_binary;
  int cur_room_totalsize;
  void *ptr_unique_collision_points;
  int bitflags3;
  unsigned char room_loaded_mask;
  unsigned char field_35;
  short field_36;
  float minxbounds;
  float minybounds;
  float minzbounds;
  float maxxbounds;
  float maxybounds;
  float maxzbounds;
} s_room_info;

s_room_info array_room_info[0x96] = {0};

int MaxNumRooms = 150;
int D_800442F8 = 0;

#define N_SIZE 50
int D_800442FC[N_SIZE] = {0};
int D_800443C4[N_SIZE] = {0};

levelentry levelinfotable[] = {
    {LEVELID_BUNKER1, "bg/bg_sev_all_p.seg", "Tbg_sev_all_p_stanZ", 0.53931433,
     1.0, 23.148148},
    {LEVELID_SILO, "bg/bg_silo_all_p.seg", "Tbg_silo_all_p_stanZ", 0.47256002,
     1.0, 29.069},
    {LEVELID_STATUE, "bg/bg_stat_all_p.seg", "Tbg_stat_all_p_stanZ",
     0.107202865, 1.0, 0.0801},
    {LEVELID_CONTROL, "bg/bg_arec_all_p.seg", "Tbg_arec_all_p_stanZ",
     0.49886572, 1.0, 80.645164},
    {LEVELID_ARCHIVES, "bg/bg_arch_all_p.seg", "Tbg_arch_all_p_stanZ",
     0.50678575, 1.0, 54.347824},
    {LEVELID_TRAIN, "bg/bg_tra_all_p.seg", "Tbg_tra_all_p_stanZ", 0.15019713,
     1.0, 19.53125},
    {LEVELID_FRIGATE, "bg/bg_dest_all_p.seg", "Tbg_dest_all_p_stanZ",
     0.44757429, 1.0, 36.764706},
    {LEVELID_BUNKER2, "bg/bg_sevb_all_p.seg", "Tbg_sevb_all_p_stanZ",
     0.53931433, 1.0, 23.148148},
    {LEVELID_AZTEC, "bg/bg_azt_all_p.seg", "Tbg_azt_all_p_stanZ", 0.35300568,
     1.0, 52.083332},
    {LEVELID_STREETS, "bg/bg_pete_all_p.seg", "Tbg_pete_all_p_stanZ",
     0.34187999, 1.0, 42.372883},
    {LEVELID_DEPOT, "bg/bg_depo_all_p.seg", "Tbg_depo_all_p_stanZ", 0.21847887,
     1.0, 17.605633},
    {LEVELID_COMPLEX, "bg/bg_ref_all_p.seg", "Tbg_ref_all_p_stanZ", 0.94285715,
     1.0, 37.878788},
    {LEVELID_EGYPT, "bg/bg_cryp_all_p.seg", "Tbg_cryp_all_p_stanZ", 0.25608,
     1.0, 23.584906},
    {LEVELID_DAM, "bg/bg_dam_all_p.seg", "Tbg_dam_all_p_stanZ", 0.23363999, 0.2,
     100.0},
    {LEVELID_FACILITY, "bg/bg_ark_all_p.seg", "Tbg_ark_all_p_stanZ", 1.20648,
     1.0, 64.102562},
    {LEVELID_RUNWAY, "bg/bg_run_all_p.seg", "Tbg_run_all_p_stanZ", 0.089571431,
     1.0, 4.5537338},
    {LEVELID_SURFACE, "bg/bg_sevx_all_p.seg", "Tbg_sevx_all_p_stanZ",
     0.45445713, 0.2, 22.603975},
    {LEVELID_JUNGLE, "bg/bg_jun_all_p.seg", "Tbg_jun_all_p_stanZ", 0.094662853,
     1.0, 6.6844921},
    {LEVELID_TEMPLE, "bg/bg_dish_all_p.seg", "Tbg_dish_all_p_stanZ", 0.47142857,
     1.0, 147.05882},
    {LEVELID_CAVERNS, "bg/bg_cave_all_p.seg", "Tbg_cave_all_p_stanZ",
     0.26824287, 1.0, 13.44086},
    {LEVELID_CITADEL, "bg/bg_cat_all_p.seg", "Tbg_cat_all_p_stanZ", 0.76852286,
     1.0, 38.461536},
    {LEVELID_CRADLE, "bg/bg_crad_all_p.seg", "Tbg_crad_all_p_stanZ", 0.23571429,
     1.0, 43.103451},
    {LEVELID_SHO, "bg/bg_sho_all_p.seg", "Tbg_sho_all_p_stanZ", 0.528, 1.0,
     21.18644},
    {LEVELID_SURFACE2, "bg/bg_sevx_all_p.seg", "Tbg_sevx_all_p_stanZ",
     0.45445713, 0.2, 22.603975},
    {LEVELID_ELD, "bg/bg_eld_all_p.seg", "Tbg_eld_all_p_stanZ", 0.94285715, 1.0,
     10.123456},
    {LEVELID_BASEMENT, "bg/bg_ame_all_p.seg", "Tbg_ame_all_p_stanZ", 0.65999997,
     1.0, 37.878788},
    {LEVELID_STACK, "bg/bg_ame_all_p.seg", "Tbg_ame_all_p_stanZ", 0.65999997,
     1.0, 37.878788},
    {LEVELID_LUE, "bg/bg_lue_all_p.seg", "Tbg_lue_all_p_stanZ", 0.94285715, 1.0,
     10.123456},
    {LEVELID_LIBRARY, "bg/bg_ame_all_p.seg", "Tbg_ame_all_p_stanZ", 0.65999997,
     1.0, 37.878788},
    {LEVELID_RIT, "bg/bg_rit_all_p.seg", "Tbg_rit_all_p_stanZ", 0.94285715, 1.0,
     10.123456},
    {LEVELID_CAVES, "bg/bg_oat_all_p.seg", "Tbg_oat_all_p_stanZ", 0.14142857,
     1.0, 10.123456},
    {LEVELID_EAR, "bg/bg_ear_all_p.seg", "Tbg_ear_all_p_stanZ", 0.94285715, 1.0,
     10.123456},
    {LEVELID_LEE, "bg/bg_lee_all_p.seg", "Tbg_lee_all_p_stanZ", 0.94285715, 1.0,
     10.123456},
    {LEVELID_LIP, "bg/bg_lip_all_p.seg", "Tbg_lip_all_p_stanZ", 0.94285715, 1.0,
     10.123456},
    {LEVELID_CUBA, "bg/bg_len_all_p.seg", "Tbg_len_all_p_stanZ", 0.094662853,
     1.0, 6.6844921},
    {LEVELID_WAX, "bg/bg_wax_all_p.seg", "Tbg_wax_all_p_stanZ", 0.94285715, 1.0,
     10.123456},
    {LEVELID_PAM, "bg/bg_pam_all_p.seg", "Tbg_pam_all_p_stanZ", 0.94285715, 1.0,
     10.123456},
    {LEVELID_MAX, "bg/bgx.seg", "TbgxZ", 0.94285715, 1.0, 1.0}};

int D_8004481C[] = {0x1000100, 0};
int D_80044824[] = {0x32C2E32, 0x373E3F4E, 0x56595D72, 0x76797AFF, 0x11003AFF};
int current_room_maybe = 1;
int NumberOfRoomsDrawn = 0;
// back for now to build till rom is compiling and this can be determined
int GlobalLight[] = {0x96969600, 0x96969600, 0xFFFFFF00,
                     0xFFFFFF00, 0x4D4D2E00, 0};
// Lights1 GlobalLight = gdSPDefLights1(
//	150,150,150        /* ambient color grey */ //D:80044840
//	255,255,255,77,77,46    /* white light from the upper west-south-west
//(42 up, 244') */ //D:80044848
//);
// OR
// Lights1 GlobalLight = { 255,255,255, 0xff,		/* diffuse */
//	77,77,46,    0, 		/* direction */
//	150,150,150 , 0xff 		/* ambient */
//}; //to be honest, while this looks simpler but Im confused at the order...
// Light has Ambient first then directional, its stored in mem this way too, so
// why is this declaired diffuse then ambient (taken from topgun.c)
// At the end of the day though, whichever is the same as bin should be used,
// even if the first is as SDK wants (Def Lights)

int D_80044858 = 0;
int D_8004485C = 1;
int D_80044860 = 0;
int D_80044864 = 0;
int D_80044868 = 0x7FFF;
int D_8004486C = 0x7FFF;
int D_80044870 = 0x7FFF;
int D_80044874 = 0xFFFF8000;
int D_80044878 = 0xFFFF8000;
int D_8004487C = 0xFFFF8000;
int D_80044880 = 0x7FFF;
int D_80044884 = 0x7FFF;
int D_80044888 = 0x7FFF;
int D_8004488C = 0xFFFF8000;
int D_80044890 = 0xFFFF8000;
int D_80044894 = 0xFFFF8000;
int D_80044898 = 0;
int D_8004489C = 0xF;
int D_800448A0 = 0;
int D_800448A4 = 0;
int D_800448A8[20] = {0};
int D_800448F8 = 0;
int current_visibility = 0;
int D_80044900 = 0;

int D_80044904 = 0x7F7FFFFF;
int D_80044908 = 0x7F7FFFFF;
int D_8004490C = 0x7F7FFFFF;
int D_80044910 = 0xFF7FFFFF;
int D_80044914 = 0xFF7FFFFF;
int D_80044918 = 0xFF7FFFFF;
int D_8004491C = 0;
int D_80044920 = 0;
int D_80044924 = 0;

// RenderMode/Combiner Look-Up-Tables
// Looks for value on left, and replaces with correct value on right
// eg 0x0C192078 = C8112078, or had they used macros
// gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2 ) The reason for
// this LUT is to dynamicly change the rendermode and combiner to FOG / NoFog or
// any other setting they might have wanted to test during development as it
// applies during runtime
/*Reminder:
        1cycle combiners repeat both cycles gDPSetCombineMode(G_CC_MODULATERGBA,
   G_CC_MODULATERGBA2) (       -  )*     +  ,  (       -  )*     +
        G_CC_MODULATERGBA2	    COMBINED, 0, SHADE, 0, COMBINED, 0, SHADE, 0
*/
/*
//New Defines to be added to gbi.h
#define	ModulateRGB_EnvA 	TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT
//custom combiner for triangle alpha
#define	ModulateRGB_EnvA2 	COMBINED, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT
//custom combiner for triangle alpha
#define	ModulateRGBA_EnvA 	TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0
//custom combiner for Texture*triangle alpha #define	ModulateRGBA_EnvA2
COMBINED, 0, SHADE, 0, COMBINED, 0, ENVIRONMENT, 0 //custom combiner for
texture*triangle alpha
#define	SHADE_EnvA 		    0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT
//custom combiner for triangle alpha #define	TLRGB_ATile1 		TEXEL1,
TEXEL0, LOD_FRACTION, TEXEL0, 1, 0, TEXEL1, 0
*/
// Primary.
Gfx D_80044928[] = {
    0xFC26A004, 0x1F1093FF, 0xFC232DFF, 0xFFFFFE38,
    // gDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATERGBA2),
    // gDPSetCombineLERP(TEXEL1, 0, COMBINED_ALPHA, 0, TEXEL1, 0, PRIM_LOD_FRAC,
    // 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    0x0, 0x0};

// Secondary.
Gfx D_80044940[] = {
    0xB900031D, 0x0C192078, 0xB900031D, 0xC8112078, 0xB900031D, 0x0C182078,
    0xB900031D, 0xC8102078, 0xB900031D, 0x0C192D58, 0xB900031D, 0xC8112D58,
    0xB900031D, 0x0C184DD8, 0xB900031D, 0xC8104DD8, 0xB900031D, 0x0C1849D8,
    0xB900031D, 0xC81049D8, 0xB900031D, 0x0C193078, 0xB900031D, 0xC8113078,
    0xB900031D, 0x0C192048, 0xB900031D, 0xC8112048, 0xB900031D, 0x0C182048,
    0xB900031D, 0xC8102048,

    /*
    //Add FOG to all rendermodes
    //Standard HiQuality Surface to Standard Fogable HiQuality Surface
    gDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_OPA_SURF2),
    gDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
    //Terrain to Fogable Terrain
    gDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_OPA_TERR2),
    gDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_TERR2),
    //Standard DECAL to FOG DECAL
    gDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_OPA_DECAL2),
    gDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_DECAL2),
    //Transparent DECAL to  FOG Transparent DECAL
    gDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_DECAL2),
    gDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_DECAL2),
    //Transparent Surface to FOG Transparent Surface
    gDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_SURF2),
    gDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_SURF2),
    // Billboard Cut-out to FOG Billboard Cut-out - eg, Mario Tree or Depot lamp
    // See PGDLists\Transparent Textures.htm for more info
    gDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_TEX_EDGE2),
    gDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2),
    //Standard Z-Less OPA to Standard FOG Z-Less OPA
    gDPSetRenderMode(G_RM_PASS, G_RM_AA_OPA_SURF2),
    gDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_OPA_SURF2),
    //Z-Less OPA Terrain to Z-Less Fog OPA Terrain
    gDPSetRenderMode(G_RM_PASS, G_RM_AA_OPA_TERR2),
    gDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_OPA_TERR2),
    */
    0x0, 0x0};

Gfx D_800449C8[] = {
    0xB900031D, 0x0C184DD8, 0xB900031D, 0xC8104DD8, 0xB900031D, 0x0C1849D8,
    0xB900031D, 0xC81049D8, 0xB900031D, 0x0C193078, 0xB900031D, 0xC8113078,
    0xFC26A004, 0x1F1093FF, 0xFC26A004, 0x1F1493FF, 0xFC121824, 0xFF33FFFF,
    0xFC121A24, 0xFF37FFFF, 0xFC26A004, 0x1FFC93FC, 0xFC26A004, 0x1FFC93FD,
    0xFC127E24, 0xFFFFF9FC, 0xFC127E24, 0xFFFFFBFD, 0xFC26A004, 0x1F1093FF,
    0xFC26A004, 0x1F1493FF, 0xFC121824, 0xFF33FFFF, 0xFC121A24, 0xFF37FFFF,
    0xFC26A004, 0x1FFC93FC, 0xFC26A004, 0x1FFC93FD, 0xFC127E24, 0xFFFFF9FC,
    0xFC127E24, 0xFFFFFBFD, 0xFCFFFFFF, 0xFFFE7838, 0xFCFFFFFF, 0xFFFE7A38,
    0xFCFFFFFF, 0xFFFE793C, 0xFCFFFFFF, 0xFFFE7B3D, 0xFC26E404, 0x1F10FFFF,
    0xFC26E404, 0x1F14FFFF,
    /*
    //Add FOG to Rendermodes
    //Transparent DECAL to  FOG Transparent DECAL
    gDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_DECAL2),
    gDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_DECAL2),
    //Transparent Surface to FOG Transparent Surface
    gDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_SURF2),
    gDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_SURF2),
    // Billboard Cut-out to FOG Billboard Cut-out - eg, Mario Tree or Depot lamp
    gDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_TEX_EDGE2),
    gDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2),

    // Swap all refrences to Shade in Alpha to Environment
    gDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATERGBA2) ,
    gDPSetCombineMode(G_CC_TRILERP, ModulateRGBA_EnvA2),
    gDPSetCombineMode(G_CC_MODULATERGBA, G_CC_MODULATERGBA) ,
    gDPSetCombineMode(ModulateRGBA_EnvA, ModulateRGBA_EnvA),
    gDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATERGB2) ,
    gDPSetCombineMode(G_CC_TRILERP, ModulateRGB_EnvA2),
    gDPSetCombineMode(G_CC_MODULATERGB, G_CC_MODULATERGB) ,
    gDPSetCombineMode(ModulateRGB_EnvA, ModulateRGB_EnvA),
    gDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATERGBA2) ,
    gDPSetCombineMode(G_CC_TRILERP, ModulateRGBA_EnvA2),
    gDPSetCombineMode(G_CC_MODULATERGBA, G_CC_MODULATERGBA) ,
    gDPSetCombineMode(ModulateRGBA_EnvA, ModulateRGBA_EnvA),
    gDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATERGB2) ,
    gDPSetCombineMode(G_CC_TRILERP, ModulateRGB_EnvA2),
    gDPSetCombineMode(G_CC_MODULATERGB, G_CC_MODULATERGB) ,
    gDPSetCombineMode(ModulateRGB_EnvA, ModulateRGB_EnvA),
    gDPSetCombineMode(G_CC_SHADE, G_CC_PASS2) ,
    gDPSetCombineMode(G_CC_SHADE_EnvA, G_CC_PASS2),
    gDPSetCombineMode(G_CC_SHADE, G_CC_SHADE) ,
    gDPSetCombineMode(G_CC_SHADE_EnvA, G_CC_SHADE_EnvA),
    // This one is an oddball... its extra here AND is weird using Tile1 only
    for Alpha gDPSetCombineMode(TLRGB_ATile1, G_CC_MODULATERGBA) ,
    gDPSetCombineMode(TLRGB_ATile1, ModulateRGB_EnvA2),
    */
    0x0, 0x0};

// Loaded once on first time entering level, only once ever
long long D_80044AB0[] = {
    0xFC26A0041F1093FF, 0xFC26A0041F1493FF, 0xFC121824FF33FFFF,
    0xFC121A24FF37FFFF, 0xFC26A0041FFC93FC, 0xFC26A0041FFC93FD,
    0xFC127E24FFFFF9FC, 0xFC127E24FFFFFBFD, 0xFC26A0041F1093FF,
    0xFC26A0041F1493FF, 0xFC121824FF33FFFF, 0xFC121A24FF37FFFF,
    0xFC26A0041FFC93FC, 0xFC26A0041FFC93FD, 0xFC127E24FFFFF9FC,
    0xFC127E24FFFFFBFD, 0xFCFFFFFFFFFE7838, 0xFCFFFFFFFFFE7A38,
    0xFCFFFFFFFFFE793C, 0xFCFFFFFFFFFE7B3D,
    /*
    // Swap all refrences to Shade in Alpha to Environment
    gDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATERGBA2) ,
    gDPSetCombineMode(G_CC_TRILERP, ModulateRGBA_EnvA2),
    gDPSetCombineMode(G_CC_MODULATERGBA, G_CC_MODULATERGBA) ,
    gDPSetCombineMode(ModulateRGBA_EnvA, ModulateRGBA_EnvA),
    gDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATERGB2) ,
    gDPSetCombineMode(G_CC_TRILERP, ModulateRGB_EnvA2),
    gDPSetCombineMode(G_CC_MODULATERGB, G_CC_MODULATERGB) ,
    gDPSetCombineMode(ModulateRGB_EnvA, ModulateRGB_EnvA),
    gDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATERGBA2) ,
    gDPSetCombineMode(G_CC_TRILERP, ModulateRGBA_EnvA2),
    gDPSetCombineMode(G_CC_MODULATERGBA, G_CC_MODULATERGBA) ,
    gDPSetCombineMode(ModulateRGBA_EnvA, ModulateRGBA_EnvA),
    gDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATERGB2) ,
    gDPSetCombineMode(G_CC_TRILERP, ModulateRGB_EnvA2),
    gDPSetCombineMode(G_CC_MODULATERGB, G_CC_MODULATERGB) ,
    gDPSetCombineMode(ModulateRGB_EnvA, ModulateRGB_EnvA),
    gDPSetCombineMode(G_CC_SHADE, G_CC_PASS2) ,
    gDPSetCombineMode(G_CC_SHADE_EnvA, G_CC_PASS2),
    gDPSetCombineMode(G_CC_SHADE, G_CC_SHADE) ,
    gDPSetCombineMode(G_CC_SHADE_EnvA, G_CC_SHADE_EnvA),
    */
    0x0};

// Loaded once on first time entering level, only once ever
long long D_80044B58[] = {
    0xFC26A0041F1093FF, 0xFC26A0041F1493FF, 0xFC121824FF33FFFF,
    0xFC121A24FF37FFFF, 0xFC26A0041FFC93FC, 0xFC26A0041FFC93FD,
    0xFC127E24FFFFF9FC, 0xFC127E24FFFFFBFD, 0xFC26A0041F1093FF,
    0xFC26A0041F1493FF, 0xFC121824FF33FFFF, 0xFC121A24FF37FFFF,
    0xFC26A0041FFC93FC, 0xFC26A0041FFC93FD, 0xFC127E24FFFFF9FC,
    0xFC127E24FFFFFBFD, 0xFCFFFFFFFFFE7838, 0xFCFFFFFFFFFE7A38,
    0xFCFFFFFFFFFE793C, 0xFCFFFFFFFFFE7B3D,
    /*
    // Swap all refrences to Shade in Alpha to Environment
    gDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATERGBA2) ,
    gDPSetCombineMode(G_CC_TRILERP, ModulateRGBA_EnvA2),
    gDPSetCombineMode(G_CC_MODULATERGBA, G_CC_MODULATERGBA2) ,
    gDPSetCombineMode(ModulateRGBA_EnvA, ModulateRGBA_EnvA2),
    gDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATERGB2) ,
    gDPSetCombineMode(G_CC_TRILERP, ModulateRGB_EnvA2),
    gDPSetCombineMode(G_CC_MODULATERGB, G_CC_MODULATERGB2) ,
    gDPSetCombineMode(ModulateRGB_EnvA, ModulateRGB_EnvA2),
    gDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATERGBA2) ,
    gDPSetCombineMode(G_CC_TRILERP, ModulateRGBA_EnvA2),
    gDPSetCombineMode(G_CC_MODULATERGBA, G_CC_MODULATERGBA2) ,
    gDPSetCombineMode(ModulateRGBA_EnvA, ModulateRGBA_EnvA2),
    gDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATERGB2) ,
    gDPSetCombineMode(G_CC_TRILERP, ModulateRGB_EnvA2),
    gDPSetCombineMode(G_CC_MODULATERGB, G_CC_MODULATERGB2) ,
    gDPSetCombineMode(ModulateRGB_EnvA, ModulateRGB_EnvA2),
    gDPSetCombineMode(G_CC_SHADE, G_CC_PASS2) ,
    gDPSetCombineMode(G_CC_SHADE_EnvA, G_CC_PASS2),
    gDPSetCombineMode(G_CC_SHADE, G_CC_SHADE2) ,
    gDPSetCombineMode(G_CC_SHADE_EnvA, G_CC_SHADE_EnvA2),
    */
    0x0};

long long D_80044C00[] = {
    0xB900031D005049D8, 0xB900031D00553078, 0xB900031D0C1849D8,
    0xB900031D0C193078,
    /*
    //Transparent 1Cycle to  BillBoard 1Cycle
    gDPSetRenderMode(G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2),
    gDPSetRenderMode(G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE2),
    //Transparent Surface to Billboard
    gDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_SURF2),
    gDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_TEX_EDGE2),
    */
    0x0};

// water
long long D_80044C28[] = {
    0xB900031D00552078, 0xB900031D00502078, 0xB900031D0C192078,
    0xB900031D0C182078,
    /*
    //1 Cycle Opa to Particle
    gDPSetRenderMode(RM_AA_ZB_OPA_SURF, RM_AA_ZB_OPA_SURF2),
    gDPSetRenderMode(G_RM_AA_ZB_PCL_SURF, G_RM_AA_ZB_PCL_SURF2),
    //2 cycle Opa to Particle
    gDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_OPA_SURF2),
    gDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_PCL_SURF2),
    */
    0x0};

long long D_80044C50[] = {
    0xB900031D0C1849D8, 0xB900031D0C184B50,
    /*
    //Transparent to Cloud (Saves AA - Stops Jaggies from appearing behind
    BillBoard) gDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_SURF2),
    gDPSetRenderMode(G_RM_PASS, G_RM_ZB_CLD_SURF2),
    */
    0x0};

//(Wallet Bond - Main Menu)
long long D_80044C68[] = {
    0xBA00140200000000, 0xBA00140200100000, // 1Cycle --> 2Cycle
    0xB900031D00502048, 0xB900031D08D02048, 0xFC127E24FFFFF9FC,
    0xFC127FFFFFFFF838,
    /*
        //1 Cycle particle Surface to 2 Cycle colour + 1-a*Fog ???
        gsDPSetCycleType(G_CYC_2CYCLE),
        gDPSetRenderMode(G_RM_AA_PCL_SURF, G_RM_AA_PCL_SURF2),
       gDPSetRenderMode(AA_EN | IM_RD | CVG_DST_CLAMP | ALPHA_CVG_SEL |
       ZMODE_OPA | GBL_c1(G_BL_CLR_IN, G_BL_A_SHADE, G_BL_CLR_FOG, G_BL_1MA) |
       GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)),
        gDPSetCombineMode(G_CC_MODULATERGBA, G_CC_PASS2),
       gDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATERGBA2),
        */
    0x0};

long long D_80044CA0[] = {
    0xFC127E24FFFFF9FC, 0xFC137E26FFFFFBFD, 0xFC121824FF33FFFF,
    0xFC131A26FF37FFFF, 0xFC127E24FFFFF9FC, 0xFC137E26FFFFFBFD,
    0xFC121824FF33FFFF, 0xFC131A26FF37FFFF, 0xFCFFFFFFFFFE793C,
    0xFC637EC6FFFFFBFD, 0xFC26A0041FFC93FC, 0xFC26A0061FFC93FD,
    0xFC26A0041F1093FF, 0xFC26A0061F1493FF, 0xFC26A0041FFC93FC,
    0xFC26A0061FFC93FD, 0xFC26A0041F1093FF, 0xFC26A0061F1493FF,
    0xFC26E4041FFCFFFC, 0xFC26E4061FFCFFFD, 0xFC26E4041F10FFFF,
    0xFC26E4061F14FFFF, 0xFC26E4041FFCFFFC, 0xFC26E4061FFCFFFD,
    0xFC26E4041F10FFFF, 0xFC26E4061F14FFFF, 0xFCFFFFFFFFFE7838,
    0xFC637FFFFFFFFA38,
    /*
        gDPSetCombineMode(G_CC_MODULATERGB, G_CC_MODULATERGB2) ,
       gDPSetCombineMode(ModulateRGB_EnvA, ModulateRGB_EnvA2),
        gDPSetCombineMode(G_CC_MODULATERGBA, G_CC_MODULATERGBA2) ,
       gDPSetCombineMode(ModulateRGBA_EnvA, ModulateRGBA_EnvA2),
        gDPSetCombineMode(G_CC_MODULATERGB, G_CC_MODULATERGB2) ,
       gDPSetCombineMode(ModulateRGB_EnvA, ModulateRGB_EnvA2),
        gDPSetCombineMode(G_CC_MODULATERGBA, G_CC_MODULATERGBA2) ,
       gDPSetCombineMode(ModulateRGBA_EnvA, ModulateRGBA_EnvA2),
        gDPSetCombineMode(G_CC_SHADE, G_CC_SHADE2), gDPSetCombineLERP(CENTER, 0,
       COMBINED_ALPHA, 0, 0, 0, 0, ENVIRONMENT, CENTER, 0, COMBINED_ALPHA, 0, 0,
       0, 0, ENVIRONMENT), gDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATERGB2) ,
       gDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0,
       LOD_FRACTION, TEXEL0, COMBINED, 0, COMBINED_ALPHA, 0, 0, 0, 0,
       ENVIRONMENT), gDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATERGBA2),
       gDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0,
       LOD_FRACTION, TEXEL0, COMBINED, 0, COMBINED_ALPHA, 0, COMBINED, 0,
       ENVIRONMENT, 0), gDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATERGB2) ,
       gDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0,
       LOD_FRACTION, TEXEL0, COMBINED, 0, COMBINED_ALPHA, 0, 0, 0, 0,
       ENVIRONMENT), gDPSetCombineMode(G_CC_TRILERP, G_CC_MODULATERGBA2),
       gDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0,
       LOD_FRACTION, TEXEL0, COMBINED, 0, COMBINED_ALPHA, 0, COMBINED, 0,
       ENVIRONMENT, 0), gDPSetCombineMode(TLRGB_ATile1, G_CC_MODULATERGB2),
       gDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 1, 0, TEXEL1, 0,
       COMBINED, 0, COMBINED_ALPHA, 0, 0, 0, 0, ENVIRONMENT),
        gDPSetCombineMode(TLRGB_ATile1, G_CC_MODULATERGBA2),
       gDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 1, 0, TEXEL1, 0,
       COMBINED, 0, COMBINED_ALPHA, 0, COMBINED, 0, ENVIRONMENT, 0),
        gDPSetCombineMode(TLRGB_ATile1, G_CC_MODULATERGB2),
       gDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 1, 0, TEXEL1, 0,
       COMBINED, 0, COMBINED_ALPHA, 0, 0, 0, 0, ENVIRONMENT),
        gDPSetCombineMode(TLRGB_ATile1, G_CC_MODULATERGBA2),
       gDPSetCombineLERP(TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, 1, 0, TEXEL1, 0,
       COMBINED, 0, COMBINED_ALPHA, 0, COMBINED, 0, ENVIRONMENT, 0),
        gDPSetCombineMode(G_CC_SHADE, G_CC_PASS2), gDPSetCombineLERP(CENTER, 0,
       COMBINED_ALPHA, 0, 0, 0, 0, ENVIRONMENT 0, 0, 0, COMBINED, 0, 0, 0,
       COMBINED),
        */
    0x0};

int *ptrDynamic_CC_RM_LUT[] = {
    &D_80044928, &D_80044940, &D_80044C00, &D_80044C28, &D_80044C50,
    &D_800449C8, &D_80044AB0, &D_80044B58, &D_80044C68, &D_80044CA0};
int D_80044DB0 = 0;

void something_with_bg_c_debug(void) {
  get_ptr_debug_notice_list_entry(&ptr_bg_c_debug_debug_notice_list,
                                  "bg_c_debug");
}

asm(R"
glabel sub_GAME_7F0B37EC
  lui   $v0, %hi(D_80044824)
  lui   $v1, %hi(current_room_maybe)
  lui   $t0, %hi(ptr_bgdata_portals) 
  lui   $a3, %hi(D_80041400)
  addiu $v0, %lo(D_80044824) # addiu $v0, $v0, 0x4824
  addiu $v1, %lo(current_room_maybe) # addiu $v1, $v1, 0x4838
  addiu $a3, %lo(D_80041400) # addiu $a3, $a3, 0x1400
  addiu $t0, %lo(ptr_bgdata_portals) # addiu $t0, $t0, -0x80
  li    $t1, 255
  lw    $t6, ($a3)
.L7F0B3814:
  lbu   $t7, ($v0)
  addiu $v0, $v0, 1
  bnel  $t6, $t7, .L7F0B3890
   lbu   $t7, 2($v0)
  lbu   $a0, ($v0)
  lbu   $t8, 1($v0)
.L7F0B382C:
  andi  $a1, $a0, 0xff
  move  $a2, $a1
  slt   $at, $t8, $a1
  bnezl $at, .L7F0B3878
   lbu   $a0, 2($v0)
  lw    $t9, ($t0)
.L7F0B3844:
  sll   $t2, $a2, 3
  addiu $a1, $a1, 1
  addu  $a0, $t9, $t2
  lbu   $t3, 6($a0)
  andi  $a2, $a1, 0xff
  move  $a1, $a2
  ori   $t4, $t3, 2
  sb    $t4, 6($a0)
  lbu   $t6, 1($v0)
  slt   $at, $t6, $a2
  beql  $at, $zero, .L7F0B3844
   lw    $t9, ($t0)
  lbu   $a0, 2($v0)
.L7F0B3878:
  addiu $v0, $v0, 2
  bnel  $t1, $a0, .L7F0B382C
   lbu   $t8, 1($v0)
  b     .L7F0B38A0
   addiu $v0, $v0, 1
  lbu   $t7, 2($v0)
.L7F0B3890:
  addiu $v0, $v0, 2
  bnel  $t1, $t7, .L7F0B3890
   lbu   $t7, 2($v0)
  addiu $v0, $v0, 1
.L7F0B38A0:
  sltu  $at, $v0, $v1
  bnezl $at, .L7F0B3814
   lw    $t6, ($a3)
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B38B4
  addiu $sp, $sp, -0x20
  sw    $s0, 0x14($sp)
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  move  $s0, $a1
  lbu   $v0, ($a1)
  andi  $v1, $a0, 0xff
  move  $a0, $s0
.L7F0B38D4:
  beq   $v1, $v0, .L7F0B3904
   nop   
  lbu   $v0, 1($s0)
  addiu $s0, $s0, 1
  bnez  $v0, .L7F0B38D4
   nop   
  lbu   $t6, 1($s0)
.L7F0B38F0:
  addiu $s0, $s0, 1
  bnezl $t6, .L7F0B38F0
   lbu   $t6, 1($s0)
  b     .L7F0B399C
   addiu $s0, $s0, 1
.L7F0B3904:
  lui   $s1, %hi(pPlayer)
  move  $s0, $a0
  addiu $s1, %lo(pPlayer) # addiu $s1, $s1, -0x5f50
  lbu   $v0, ($a0)
  lw    $a1, ($s1)
.L7F0B3918:
  move  $a0, $v0
  jal   sub_GAME_7F0B5208
   addiu $a1, $a1, 0x1118
  beqz  $v0, .L7F0B3940
   move  $a1, $zero
  lw    $a2, ($s1)
  lbu   $a0, ($s0)
  li    $a3, 1
  jal   sub_GAME_7F0B39BC
   addiu $a2, $a2, 0x1118
.L7F0B3940:
  lbu   $v0, 1($s0)
  addiu $s0, $s0, 1
  bnezl $v0, .L7F0B3918
   lw    $a1, ($s1)
  addiu $s0, $s0, 1
  lbu   $v0, ($s0)
  lw    $a1, ($s1)
.L7F0B395C:
  move  $a0, $v0
  jal   sub_GAME_7F0B5208
   addiu $a1, $a1, 0x1118
  beqz  $v0, .L7F0B3984
   move  $a1, $zero
  lw    $a2, ($s1)
  lbu   $a0, ($s0)
  li    $a3, 1
  jal   sub_GAME_7F0B39BC
   addiu $a2, $a2, 0x1118
.L7F0B3984:
  lbu   $v0, 1($s0)
  addiu $s0, $s0, 1
  bnezl $v0, .L7F0B395C
   lw    $a1, ($s1)
  b     .L7F0B39AC
   lw    $ra, 0x1c($sp)
.L7F0B399C:
  lbu   $v0, ($s0)
  bnezl $v0, .L7F0B38D4
   move  $a0, $s0
  lw    $ra, 0x1c($sp)
.L7F0B39AC:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x20
");

asm(R"
glabel sub_GAME_7F0B39BC
  sll   $t6, $a0, 2
  addu  $t6, $t6, $a0
  lui   $t7, %hi(array_room_info) 
  addiu $t7, %lo(array_room_info) # addiu $t7, $t7, 0x1414
  sll   $t6, $t6, 4
  addu  $v0, $t6, $t7
  lbu   $t9, 0x34($v0)
  addiu $sp, $sp, -0x30
  sw    $s0, 0x18($sp)
  li    $t8, 1
  move  $s0, $a0
  sw    $ra, 0x1c($sp)
  sw    $a3, 0x3c($sp)
  beqz  $t9, .L7F0B3A00
   sb    $t8, ($v0)
  b     .L7F0B3AF0
   move  $v0, $zero
.L7F0B3A00:
  lui   $a3, %hi(NumberOfRoomsDrawn)
  addiu $a3, %lo(NumberOfRoomsDrawn) # addiu $a3, $a3, 0x483c
  lw    $a0, ($a3)
  move  $v0, $zero
  lui   $t5, %hi(dword_CODE_bss_8007FFA0) 
  blez  $a0, .L7F0B3AA4
   sll   $t4, $a0, 3
  lui   $v1, %hi(dword_CODE_bss_8007FFA0)
  addiu $v1, %lo(dword_CODE_bss_8007FFA0) # addiu $v1, $v1, -0x60
.L7F0B3A24:
  lw    $t0, ($v1)
  addiu $v0, $v0, 1
  slt   $at, $v0, $a0
  bne   $s0, $t0, .L7F0B3A9C
   nop   
  lw    $t1, 4($v1)
  move  $a0, $a2
  slt   $at, $t1, $a1
  beql  $at, $zero, .L7F0B3A54
   addiu $a1, $v1, 8
  sw    $a1, 4($v1)
  addiu $a1, $v1, 8
.L7F0B3A54:
  sw    $v1, 0x20($sp)
  jal   sub_GAME_7F0B5CC0
   sw    $a2, 0x38($sp)
  lw    $a2, 0x38($sp)
  lw    $v1, 0x20($sp)
  lw    $t2, 0x3c($sp)
  lwc1  $f4, ($a2)
  lw    $v0, 0x18($v1)
  swc1  $f4, 8($v1)
  lwc1  $f6, 4($a2)
  or    $t3, $v0, $t2
  swc1  $f6, 0xc($v1)
  lwc1  $f8, 8($a2)
  swc1  $f8, 0x10($v1)
  lwc1  $f10, 0xc($a2)
  sw    $t3, 0x18($v1)
  b     .L7F0B3AF0
   swc1  $f10, 0x14($v1)
.L7F0B3A9C:
  bnez  $at, .L7F0B3A24
   addiu $v1, $v1, 0x1c
.L7F0B3AA4:
  subu  $t4, $t4, $a0
  sll   $t4, $t4, 2
  addiu $t5, %lo(dword_CODE_bss_8007FFA0) # addiu $t5, $t5, -0x60
  addu  $v1, $t4, $t5
  sw    $s0, ($v1)
  sw    $a1, 4($v1)
  lwc1  $f16, ($a2)
  lw    $t6, 0x3c($sp)
  addiu $t7, $a0, 1
  swc1  $f16, 8($v1)
  lwc1  $f18, 4($a2)
  move  $v0, $zero
  swc1  $f18, 0xc($v1)
  lwc1  $f4, 8($a2)
  swc1  $f4, 0x10($v1)
  lwc1  $f6, 0xc($a2)
  sw    $t7, ($a3)
  sw    $t6, 0x18($v1)
  swc1  $f6, 0x14($v1)
.L7F0B3AF0:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

void bgZeroBitflags2ForRoom(int roomnum) {
  array_room_info[roomnum].bitflags2 = '\0';
}

asm(R"
glabel sub_GAME_7F0B3B20
  lui   $t6, %hi(array_room_info+0x3) 
  lbu   $t6, %lo(array_room_info+0x3)($t6)
  lui   $t7, %hi(array_room_info + 0x53)
  beqz  $t6, .L7F0B3B3C
   nop   
  jr    $ra
   move  $v0, $zero

.L7F0B3B3C:
  lbu   $t7, %lo(array_room_info + 0x53)($t7)
  lui   $v0, %hi(array_room_info + 0xA0)
  addiu $v0, %lo(array_room_info + 0xA0) # addiu $v0, $v0, 0x14b4
  beqz  $t7, .L7F0B3B58
   li    $v1, 2
  jr    $ra
   li    $v0, 1

.L7F0B3B58:
  li    $a0, 150
.L7F0B3B5C:
  lbu   $t8, 3($v0)
  beql  $t8, $zero, .L7F0B3B74
   lbu   $t9, 0x53($v0)
  jr    $ra
   move  $v0, $v1

  lbu   $t9, 0x53($v0)
.L7F0B3B74:
  beql  $t9, $zero, .L7F0B3B88
   lbu   $t0, 0xa3($v0)
  jr    $ra
   addiu $v0, $v1, 1

  lbu   $t0, 0xa3($v0)
.L7F0B3B88:
  beql  $t0, $zero, .L7F0B3B9C
   lbu   $t1, 0xf3($v0)
  jr    $ra
   addiu $v0, $v1, 2

  lbu   $t1, 0xf3($v0)
.L7F0B3B9C:
  beql  $t1, $zero, .L7F0B3BB0
   addiu $v1, $v1, 4
  jr    $ra
   addiu $v0, $v1, 3

  addiu $v1, $v1, 4
.L7F0B3BB0:
  bne   $v1, $a0, .L7F0B3B5C
   addiu $v0, $v0, 0x140
  li    $v0, -1
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B3BC4
  lui   $at, %hi(NumberOfRoomsDrawn)
  sw    $zero, %lo(NumberOfRoomsDrawn)($at)
  lui   $at, %hi(array_room_info+0x3)
  sb    $zero, %lo(array_room_info+0x3)($at)
  lui   $at, %hi(array_room_info + 0x53)
  lui   $v1, %hi(array_room_info + 0xA0)
  lui   $v0, %hi(MaxNumRooms)
  addiu $v0, %lo(MaxNumRooms) # addiu $v0, $v0, 0x42f4
  addiu $v1, %lo(array_room_info + 0xA0) # addiu $v1, $v1, 0x14b4
  sb    $zero, %lo(array_room_info + 0x53)($at)
.L7F0B3BEC:
  addiu $v1, $v1, 0x140
  sb    $zero, -0x13d($v1)
  sb    $zero, -0xed($v1)
  sb    $zero, -0x9d($v1)
  bne   $v1, $v0, .L7F0B3BEC
   sb    $zero, -0x4d($v1)
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B3C0C
  lui   $v1, %hi(NumberOfRoomsDrawn)
  lw    $v1, %lo(NumberOfRoomsDrawn)($v1)
  move  $a2, $a1
  lui   $a1, %hi(dword_CODE_bss_8007FFA0)
  blez  $v1, .L7F0B3C6C
   move  $v0, $zero
  addiu $a1, %lo(dword_CODE_bss_8007FFA0) # addiu $a1, $a1, -0x60
.L7F0B3C28:
  lw    $t6, ($a1)
  addiu $v0, $v0, 1
  slt   $at, $v0, $v1
  bne   $a0, $t6, .L7F0B3C64
   nop   
  lwc1  $f4, 8($a1)
  li    $v0, 1
  swc1  $f4, ($a2)
  lwc1  $f6, 0xc($a1)
  swc1  $f6, 4($a2)
  lwc1  $f8, 0x10($a1)
  swc1  $f8, 8($a2)
  lwc1  $f10, 0x14($a1)
  jr    $ra
   swc1  $f10, 0xc($a2)

.L7F0B3C64:
  bnez  $at, .L7F0B3C28
   addiu $a1, $a1, 0x1c
.L7F0B3C6C:
  mtc1  $zero, $f0
  move  $v0, $zero
  swc1  $f0, ($a2)
  swc1  $f0, 4($a2)
  swc1  $f0, 8($a2)
  swc1  $f0, 0xc($a2)
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B3C8C
  addiu $sp, $sp, -0x80
  lui   $v0, %hi(NumberOfRoomsDrawn)
  lw    $v0, %lo(NumberOfRoomsDrawn)($v0)
  sw    $s7, 0x38($sp)
  sw    $s6, 0x34($sp)
  sw    $s0, 0x1c($sp)
  lui   $s7, (0x05F5E0FF >> 16) # lui $s7, 0x5f5
  move  $s0, $a0
  sw    $ra, 0x3c($sp)
  sw    $s5, 0x30($sp)
  sw    $s4, 0x2c($sp)
  sw    $s3, 0x28($sp)
  sw    $s2, 0x24($sp)
  sw    $s1, 0x20($sp)
  ori   $s7, (0x05F5E0FF & 0xFFFF) # ori $s7, $s7, 0xe0ff
  blez  $v0, .L7F0B3D1C
   move  $s6, $zero
  sll   $t7, $v0, 3
  subu  $t7, $t7, $v0
  lui   $t6, %hi(dword_CODE_bss_8007FFA0)
  addiu $s2, $t6, %lo(dword_CODE_bss_8007FFA0)
  sll   $t7, $t7, 2
  addu  $a0, $t7, $s2
  lw    $v1, 4($s2)
.L7F0B3CEC:
  addiu $s2, $s2, 0x1c
  slt   $at, $s6, $v1
  beql  $at, $zero, .L7F0B3D04
   slt   $at, $v1, $s7
  move  $s6, $v1
  slt   $at, $v1, $s7
.L7F0B3D04:
  beql  $at, $zero, .L7F0B3D14
   sltu  $at, $s2, $a0
  move  $s7, $v1
  sltu  $at, $s2, $a0
.L7F0B3D14:
  bnezl $at, .L7F0B3CEC
   lw    $v1, 4($s2)
.L7F0B3D1C:
  slt   $at, $s6, $s7
  bnez  $at, .L7F0B3E94
   move  $s5, $s7
  addiu $t8, $s6, 1
  lui   $s4, (0x01030040 >> 16) # lui $s4, 0x103
  ori   $s4, (0x01030040 & 0xFFFF) # ori $s4, $s4, 0x40
  sw    $t8, 0x44($sp)
.L7F0B3D38:
  blez  $v0, .L7F0B3E84
   move  $s3, $zero
  lui   $s2, %hi(dword_CODE_bss_8007FFA0)
  addiu $s2, %lo(dword_CODE_bss_8007FFA0) # addiu $s2, $s2, -0x60
.L7F0B3D48:
  lw    $t9, 4($s2)
  move  $s1, $s0
  bnel  $s5, $t9, .L7F0B3E78
   addiu $s3, $s3, 1
  addiu $s0, $s0, 8
  jal   get_BONDdata_field_10D8
   sw    $s4, ($s1)
  jal   osVirtualToPhysical
   move  $a0, $v0
  sw    $v0, 4($s1)
  jal   sub_GAME_7F0BB298
   move  $a0, $s0
  jal   get_debug_do_draw_obj
   move  $s0, $v0
  beql  $v0, $zero, .L7F0B3DAC
   move  $s1, $s0
  jal   sub_GAME_7F0BD8F0
   nop   
  beqz  $v0, .L7F0B3DA8
   move  $a0, $s0
  lw    $a1, ($s2)
  jal   sub_GAME_7F03A6F4
   move  $a2, $zero
  move  $s0, $v0
.L7F0B3DA8:
  move  $s1, $s0
.L7F0B3DAC:
  sw    $s4, ($s1)
  jal   get_BONDdata_field_10E0
   addiu $s0, $s0, 8
  jal   osVirtualToPhysical
   move  $a0, $v0
  sw    $v0, 4($s1)
  lwc1  $f4, 0x14($s2)
  lw    $a3, 0x10($s2)
  lw    $a2, 0xc($s2)
  lw    $a1, 8($s2)
  move  $a0, $s0
  jal   sub_GAME_7F0B4FF4
   swc1  $f4, 0x10($sp)
  move  $a0, $v0
  jal   sub_GAME_7F0BB070
   move  $a1, $zero
  jal   get_debug_do_draw_bg
   move  $s0, $v0
  beql  $v0, $zero, .L7F0B3E1C
   move  $s1, $s0
  jal   sub_GAME_7F0BD8F0
   nop   
  beqz  $v0, .L7F0B3E18
   move  $a0, $s0
  jal   sub_GAME_7F0B677C
   lw    $a1, ($s2)
  move  $s0, $v0
.L7F0B3E18:
  move  $s1, $s0
.L7F0B3E1C:
  sw    $s4, ($s1)
  jal   get_BONDdata_field_10D8
   addiu $s0, $s0, 8
  jal   osVirtualToPhysical
   move  $a0, $v0
  sw    $v0, 4($s1)
  jal   sub_GAME_7F0BB298
   move  $a0, $s0
  jal   get_debug_do_draw_obj
   move  $s0, $v0
  beqz  $v0, .L7F0B3E6C
   nop   
  jal   sub_GAME_7F0BD8F0
   nop   
  beqz  $v0, .L7F0B3E6C
   move  $a0, $s0
  lw    $a1, ($s2)
  jal   sub_GAME_7F03A6F4
   li    $a2, 2
  move  $s0, $v0
.L7F0B3E6C:
  lui   $v0, %hi(NumberOfRoomsDrawn)
  lw    $v0, %lo(NumberOfRoomsDrawn)($v0)
  addiu $s3, $s3, 1
.L7F0B3E78:
  slt   $at, $s3, $v0
  bnez  $at, .L7F0B3D48
   addiu $s2, $s2, 0x1c
.L7F0B3E84:
  lw    $t0, 0x44($sp)
  addiu $s5, $s5, 1
  bne   $t0, $s5, .L7F0B3D38
   nop   
.L7F0B3E94:
  lui   $s4, (0x01030040 >> 16) # lui $s4, 0x103
  ori   $s4, (0x01030040 & 0xFFFF) # ori $s4, $s4, 0x40
  jal   sub_GAME_7F0BB298
   move  $a0, $s0
  jal   sub_GAME_7F0B4FB4
   move  $a0, $v0
  move  $s1, $v0
  addiu $s0, $v0, 8
  jal   get_BONDdata_field_10E0
   sw    $s4, ($v0)
  jal   osVirtualToPhysical
   move  $a0, $v0
  jal   sub_GAME_7F0BD8F0
   sw    $v0, 4($s1)
  beqz  $v0, .L7F0B3EE8
   nop   
  jal   sub_GAME_7F0A0AB4
   move  $a0, $s0
  jal   sub_GAME_7F0A1D78
   move  $a0, $v0
  move  $s0, $v0
.L7F0B3EE8:
  lui   $v0, %hi(NumberOfRoomsDrawn)
  slt   $at, $s6, $s7
  lw    $v0, %lo(NumberOfRoomsDrawn)($v0)
  bnez  $at, .L7F0B4004
   move  $s5, $s6
  addiu $s6, $s7, -1
.L7F0B3F00:
  blez  $v0, .L7F0B3FF8
   move  $s3, $zero
  lui   $s2, %hi(dword_CODE_bss_8007FFA0)
  addiu $s2, %lo(dword_CODE_bss_8007FFA0) # addiu $s2, $s2, -0x60
.L7F0B3F10:
  lw    $t1, 4($s2)
  move  $s1, $s0
  bnel  $s5, $t1, .L7F0B3FEC
   addiu $s3, $s3, 1
  addiu $s0, $s0, 8
  jal   get_BONDdata_field_10E0
   sw    $s4, ($s1)
  jal   osVirtualToPhysical
   move  $a0, $v0
  sw    $v0, 4($s1)
  lwc1  $f6, 0x14($s2)
  lw    $a3, 0x10($s2)
  lw    $a2, 0xc($s2)
  lw    $a1, 8($s2)
  move  $a0, $s0
  jal   sub_GAME_7F0B4FF4
   swc1  $f6, 0x10($sp)
  move  $a0, $v0
  jal   sub_GAME_7F0BB070
   li    $a1, 1
  jal   get_debug_do_draw_bg
   move  $s0, $v0
  beql  $v0, $zero, .L7F0B3F90
   move  $s1, $s0
  jal   sub_GAME_7F0BD8F0
   nop   
  beqz  $v0, .L7F0B3F8C
   move  $a0, $s0
  jal   sub_GAME_7F0B6898
   lw    $a1, ($s2)
  move  $s0, $v0
.L7F0B3F8C:
  move  $s1, $s0
.L7F0B3F90:
  sw    $s4, ($s1)
  jal   get_BONDdata_field_10D8
   addiu $s0, $s0, 8
  jal   osVirtualToPhysical
   move  $a0, $v0
  sw    $v0, 4($s1)
  jal   sub_GAME_7F0BB298
   move  $a0, $s0
  jal   get_debug_do_draw_obj
   move  $s0, $v0
  beqz  $v0, .L7F0B3FE0
   nop   
  jal   sub_GAME_7F0BD8F0
   nop   
  beqz  $v0, .L7F0B3FE0
   move  $a0, $s0
  lw    $a1, ($s2)
  jal   sub_GAME_7F03A6F4
   li    $a2, 1
  move  $s0, $v0
.L7F0B3FE0:
  lui   $v0, %hi(NumberOfRoomsDrawn)
  lw    $v0, %lo(NumberOfRoomsDrawn)($v0)
  addiu $s3, $s3, 1
.L7F0B3FEC:
  slt   $at, $s3, $v0
  bnez  $at, .L7F0B3F10
   addiu $s2, $s2, 0x1c
.L7F0B3FF8:
  addiu $s5, $s5, -1
  bne   $s5, $s6, .L7F0B3F00
   nop   
.L7F0B4004:
  lw    $ra, 0x3c($sp)
  move  $v0, $s0
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  lw    $s2, 0x24($sp)
  lw    $s3, 0x28($sp)
  lw    $s4, 0x2c($sp)
  lw    $s5, 0x30($sp)
  lw    $s6, 0x34($sp)
  lw    $s7, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x80
");

asm(R"
glabel sub_GAME_7F0B4034
  lui   $v0, %hi(ptr_bgdata_room_fileposition_list)
  lw    $v0, %lo(ptr_bgdata_room_fileposition_list)($v0)
  sll   $t6, $a0, 2
  subu  $t6, $t6, $a0
  sll   $t6, $t6, 3
  addu  $t7, $v0, $t6
  lw    $t8, 4($t7)
  sll   $t9, $a0, 2
  move  $v1, $a0
  bnez  $t8, .L7F0B407C
   subu  $t9, $t9, $a0
  sll   $t9, $t9, 3
  addu  $a0, $v0, $t9
  lw    $t0, 0x1c($a0)
.L7F0B406C:
  addiu $v1, $v1, 1
  addiu $a0, $a0, 0x18
  beql  $t0, $zero, .L7F0B406C
   lw    $t0, 0x1c($a0)
.L7F0B407C:
  jr    $ra
   move  $v0, $v1
");

asm(R"
glabel sub_GAME_7F0B4084
  lui   $v0, %hi(ptr_bgdata_room_fileposition_list)
  lw    $v0, %lo(ptr_bgdata_room_fileposition_list)($v0)
  sll   $t6, $a0, 2
  subu  $t6, $t6, $a0
  sll   $t6, $t6, 3
  addu  $t7, $v0, $t6
  lw    $t8, 8($t7)
  sll   $t9, $a0, 2
  move  $v1, $a0
  bnez  $t8, .L7F0B40CC
   subu  $t9, $t9, $a0
  sll   $t9, $t9, 3
  addu  $a0, $v0, $t9
  lw    $t0, 0x20($a0)
.L7F0B40BC:
  addiu $v1, $v1, 1
  addiu $a0, $a0, 0x18
  beql  $t0, $zero, .L7F0B40BC
   lw    $t0, 0x20($a0)
.L7F0B40CC:
  jr    $ra
   move  $v0, $v1
");

asm(R"
glabel sub_GAME_7F0B40D4
  lui   $v0, %hi(ptr_bgdata_room_fileposition_list)
  lw    $v0, %lo(ptr_bgdata_room_fileposition_list)($v0)
  sll   $t6, $a0, 2
  subu  $t6, $t6, $a0
  sll   $t6, $t6, 3
  addu  $t7, $v0, $t6
  lw    $t8, ($t7)
  sll   $t9, $a0, 2
  move  $v1, $a0
  bnez  $t8, .L7F0B411C
   subu  $t9, $t9, $a0
  sll   $t9, $t9, 3
  addu  $a0, $v0, $t9
  lw    $t0, 0x18($a0)
.L7F0B410C:
  addiu $v1, $v1, 1
  addiu $a0, $a0, 0x18
  beql  $t0, $zero, .L7F0B410C
   lw    $t0, 0x18($a0)
.L7F0B411C:
  jr    $ra
   move  $v0, $v1
");

asm(R"
glabel load_bg_file
  addiu $sp, $sp, -0xb8
  sw    $s2, 0x20($sp)
  lui   $s2, %hi(D_80041400)
  sw    $s0, 0x18($sp)
  addiu $s2, %lo(D_80041400) # addiu $s2, $s2, 0x1400
  lui   $s0, %hi(array_room_info)
  lui   $v0, %hi(MaxNumRooms)
  sw    $ra, 0x3c($sp)
  sw    $fp, 0x38($sp)
  sw    $s7, 0x34($sp)
  sw    $s6, 0x30($sp)
  sw    $s5, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s1, 0x1c($sp)
  sw    $zero, ($s2)
  addiu $v0, %lo(MaxNumRooms) # addiu $v0, $v0, 0x42f4
  addiu $s0, %lo(array_room_info) # addiu $s0, $s0, 0x1414
.L7F0B416C:
  addiu $s0, $s0, 0x50
  sltu  $at, $s0, $v0
  bnez  $at, .L7F0B416C
   sw    $zero, -0x24($s0)
  lui   $v0, %hi(levelinfotable)
  addiu $v0, %lo(levelinfotable) # addiu $v0, $v0, 0x448c
  move  $s1, $zero
.L7F0B4188:
  lw    $t6, ($v0)
  bnel  $a0, $t6, .L7F0B419C
   addiu $s1, $s1, 1
  sw    $s1, ($s2)
  addiu $s1, $s1, 1
.L7F0B419C:
  slti  $at, $s1, 0x26
  bnez  $at, .L7F0B4188
   addiu $v0, $v0, 0x18
  jal   init_lightfixture_tables
   sw    $a0, 0xb8($sp)
  lw    $t8, ($s2)
  li    $s4, 24
  lui   $s1, %hi(levelinfotable)
  multu $t8, $s4
  addiu $s1, %lo(levelinfotable) # addiu $s1, $s1, 0x448c
  lui   $s7, %hi(ptr_bg_data) 
  addiu $s7, %lo(ptr_bg_data) # addiu $s7, $s7, -0x4070
  addiu $a1, $sp, 0x70
  sw    $a1, ($s7)
  move  $a2, $zero
  li    $a3, 64
  mflo  $t9
  addu  $t0, $s1, $t9
  jal   obLoadBGFileBytesAtOffset
   lw    $a0, 4($t0)
  lw    $v0, ($s7)
  lui   $s6, %hi(ptr_bgdata_offsets)
  addiu $s6, %lo(ptr_bgdata_offsets) # addiu $s6, $s6, -0x7c
  sw    $v0, ($s6)
  lw    $t2, 4($v0)
  lui   $s3, 0xf100
  lui   $s5, %hi(ptr_bgdata_room_fileposition_list)
  addu  $t3, $t2, $v0
  addiu $s5, %lo(ptr_bgdata_room_fileposition_list) # addiu $s5, $s5, -0x74
  addu  $t4, $t3, $s3
  sw    $t4, ($s5)
  lw    $s0, 0x18($t4)
  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
  and   $t6, $s0, $at
  addiu $s0, $t6, -1
  ori   $t7, $s0, 0xf
  addiu $s0, $t7, 1
  move  $a0, $s0
  jal   mempAllocBytesInBank
   li    $a1, 4
  lw    $t8, ($s2)
  sw    $v0, ($s7)
  move  $a1, $v0
  multu $t8, $s4
  move  $a2, $zero
  move  $a3, $s0
  mflo  $t9
  addu  $t0, $s1, $t9
  jal   obLoadBGFileBytesAtOffset
   lw    $a0, 4($t0)
  lw    $t1, ($s2)
  li    $a1, 2
  move  $a2, $zero
  multu $t1, $s4
  li    $a3, 4
  mflo  $t2
  addu  $t3, $s1, $t2
  jal   _load_resource_named_to_membank
   lw    $a0, 8($t3)
  lui   $s0, %hi(ptr_clipping)
  addiu $s0, %lo(ptr_clipping) # addiu $s0, $s0, -0x406c
  sw    $v0, ($s0)
  move  $a0, $v0
  move  $a1, $zero
  jal   stanDetermineEOF
   move  $a2, $v0
  jal   stanLoadFile
   lw    $a0, ($s0)
  lw    $t4, ($s2)
  multu $t4, $s4
  mflo  $t5
  addu  $t6, $s1, $t5
  jal   sub_GAME_7F0B4810
   lwc1  $f12, 0xc($t6)
  lw    $t7, ($s2)
  multu $t7, $s4
  mflo  $t8
  addu  $t9, $s1, $t8
  jal   sub_GAME_7F0B2950
   lwc1  $f12, 0xc($t9)
  lw    $t0, ($s2)
  multu $t0, $s4
  mflo  $t1
  addu  $t2, $s1, $t1
  jal   sub_GAME_7F0915BC
   lwc1  $f12, 0xc($t2)
  lw    $t3, ($s2)
  multu $t3, $s4
  mflo  $t4
  addu  $t5, $s1, $t4
  jal   sub_GAME_7F022E1C
   lwc1  $f12, 0xc($t5)
  lw    $t6, ($s2)
  lui   $s0, %hi(D_800413FC)
  addiu $s0, %lo(D_800413FC) # addiu $s0, $s0, 0x13fc
  multu $t6, $s4
  mflo  $t7
  addu  $t8, $s1, $t7
  lwc1  $f4, 0x10($t8)
  swc1  $f4, ($s0)
  jal   sub_GAME_7F08976C
   lwc1  $f12, ($s0)
  jal   sub_GAME_7F058C4C
   lwc1  $f12, ($s0)
  lw    $v0, ($s7)
  lui   $v1, %hi(dword_CODE_bss_8007BF98)
  lui   $a0, %hi(dword_CODE_bss_8007FF88)
  lw    $t9, ($v0)
  addiu $a0, %lo(dword_CODE_bss_8007FF88) # addiu $a0, $a0, -0x78
  addiu $v1, %lo(dword_CODE_bss_8007BF98) # addiu $v1, $v1, -0x4068
  li    $t0, 1
  sw    $t0, ($a0)
  bnez  $t9, .L7F0B479C
   sw    $t9, ($v1)
  li    $t2, 2
  sw    $t2, ($a0)
  sw    $v0, ($s6)
  lw    $t3, 4($v0)
  lui   $s6, %hi(MaxNumRooms)
  addiu $s6, %lo(MaxNumRooms) # addiu $s6, $s6, 0x42f4
  addu  $t4, $t3, $v0
  addu  $t5, $t4, $s3
  sw    $t5, ($s5)
  sw    $zero, ($s6)
  lw    $t6, 0x1c($t5)
  move  $a1, $v0
  beqz  $t6, .L7F0B43BC
   addiu $a0, $t5, 0x18
  lw    $t7, ($s6)
.L7F0B43A4:
  addiu $a0, $a0, 0x18
  addiu $t8, $t7, 1
  sw    $t8, ($s6)
  lw    $t9, 4($a0)
  bnezl $t9, .L7F0B43A4
   lw    $t7, ($s6)
.L7F0B43BC:
  lw    $t0, 8($a1)
  lui   $fp, %hi(ptr_bgdata_portals) 
  addiu $fp, %lo(ptr_bgdata_portals) # addiu $fp, $fp, -0x80
  addu  $t1, $t0, $v0
  addu  $t2, $t1, $s3
  sw    $t2, ($fp)
  lw    $v1, 0xc($a1)
  bnez  $v1, .L7F0B43EC
   lui   $s2, %hi(dword_CODE_bss_8007FF90)
  addiu $s2, %lo(dword_CODE_bss_8007FF90) # addiu $s2, $s2, -0x70
  b     .L7F0B4424
   sw    $zero, ($s2)
.L7F0B43EC:
  lui   $s2, %hi(dword_CODE_bss_8007FF90)
  addu  $t3, $v1, $v0
  addiu $s2, %lo(dword_CODE_bss_8007FF90) # addiu $s2, $s2, -0x70
  addu  $t4, $t3, $s3
  sw    $t4, ($s2)
  lw    $a0, 0x10($a1)
  lui   $at, %hi(dword_CODE_bss_8007FF94)
  bnez  $a0, .L7F0B441C
   addu  $t5, $a0, $v0
  lui   $at, %hi(dword_CODE_bss_8007FF94)
  b     .L7F0B4424
   sw    $zero, %lo(dword_CODE_bss_8007FF94)($at)
.L7F0B441C:
  addu  $t6, $t5, $s3
  sw    $t6, %lo(dword_CODE_bss_8007FF94)($at)
.L7F0B4424:
  lw    $a0, ($fp)
  move  $s0, $zero
  lw    $t7, ($a0)
  move  $v0, $a0
  beqz  $t7, .L7F0B4464
   move  $v1, $t7
  lw    $t8, ($s7)
.L7F0B4440:
  addiu $s0, $s0, 8
  addu  $t9, $v1, $t8
  addu  $t0, $t9, $s3
  sw    $t0, ($v0)
  lw    $t1, ($fp)
  addu  $v0, $t1, $s0
  lw    $v1, ($v0)
  bnezl $v1, .L7F0B4440
   lw    $t8, ($s7)
.L7F0B4464:
  lw    $a0, ($s2)
  beql  $a0, $zero, .L7F0B44D0
   lw    $t9, ($s6)
  lbu   $t2, ($a0)
  move  $s0, $zero
  move  $v1, $a0
  beqz  $t2, .L7F0B44CC
   andi  $v0, $t2, 0xff
  li    $s1, 100
.L7F0B4488:
  bnel  $s1, $v0, .L7F0B44BC
   lbu   $v0, 8($v1)
  lw    $t3, 4($v1)
  lw    $t4, ($s7)
  addu  $t5, $t3, $t4
  jal   sub_GAME_7F0B5E88
   addu  $a0, $t5, $s3
  lw    $t6, ($s2)
  addu  $t7, $t6, $s0
  sw    $v0, 4($t7)
  lw    $t8, ($s2)
  addu  $v1, $t8, $s0
  lbu   $v0, 8($v1)
.L7F0B44BC:
  addiu $s0, $s0, 8
  addiu $v1, $v1, 8
  bnez  $v0, .L7F0B4488
   nop   
.L7F0B44CC:
  lw    $t9, ($s6)
.L7F0B44D0:
  lui   $s0, %hi(array_room_info + 0x10 +0x40)
  addiu $s0, %lo(array_room_info + 0x10 +0x40) # addiu $s0, $s0, 0x1464
  slti  $at, $t9, 2
  bnez  $at, .L7F0B4670
   li    $s1, 1
  lw    $a0, ($s5)
  li    $s3, 24
  li    $s7, -1
  addiu $a0, $a0, 0x18
.L7F0B44F4:
  sb    $zero, 2($s0)
  sb    $zero, 0x35($s0)
  lw    $t0, 4($a0)
  addiu $s2, $s1, 1
  beql  $t0, $zero, .L7F0B4588
   sw    $zero, 0x14($s0)
  addiu $s2, $s1, 1
  jal   sub_GAME_7F0B4034
   move  $a0, $s2
  move  $a0, $s1
  jal   sub_GAME_7F0B4084
   sw    $v0, 0x68($sp)
  lw    $a1, 0x68($sp)
  slt   $at, $v0, $a1
  bnez  $at, .L7F0B455C
   nop   
  multu $a1, $s4
  lw    $v1, ($s5)
  addu  $a0, $v1, $s3
  lw    $t4, 4($a0)
  mflo  $t1
  addu  $t2, $v1, $t1
  lw    $t3, 4($t2)
  subu  $t5, $t3, $t4
  b     .L7F0B4588
   sw    $t5, 0x14($s0)
.L7F0B455C:
  multu $v0, $s4
  lw    $v1, ($s5)
  addu  $a0, $v1, $s3
  lw    $t9, 4($a0)
  mflo  $t6
  addu  $t7, $v1, $t6
  lw    $t8, 8($t7)
  subu  $t0, $t8, $t9
  b     .L7F0B4588
   sw    $t0, 0x14($s0)
  sw    $zero, 0x14($s0)
.L7F0B4588:
  lw    $t1, 8($a0)
  beql  $t1, $zero, .L7F0B4608
   sw    $zero, 0x18($s0)
  jal   sub_GAME_7F0B4034
   move  $a0, $s2
  move  $s1, $v0
  jal   sub_GAME_7F0B4084
   move  $a0, $s2
  slt   $at, $v0, $s1
  bnez  $at, .L7F0B45DC
   nop   
  multu $s1, $s4
  lw    $v1, ($s5)
  addu  $a0, $v1, $s3
  lw    $t5, 8($a0)
  mflo  $t2
  addu  $t3, $v1, $t2
  lw    $t4, 4($t3)
  subu  $t6, $t4, $t5
  b     .L7F0B4608
   sw    $t6, 0x18($s0)
.L7F0B45DC:
  multu $v0, $s4
  lw    $v1, ($s5)
  addu  $a0, $v1, $s3
  lw    $t0, 8($a0)
  mflo  $t7
  addu  $t8, $v1, $t7
  lw    $t9, 8($t8)
  subu  $t1, $t9, $t0
  b     .L7F0B4608
   sw    $t1, 0x18($s0)
  sw    $zero, 0x18($s0)
.L7F0B4608:
  lw    $t2, ($a0)
  beql  $t2, $zero, .L7F0B464C
   sw    $zero, 0x10($s0)
  jal   sub_GAME_7F0B40D4
   move  $a0, $s2
  multu $v0, $s4
  lw    $v1, ($s5)
  lw    $a1, ($s6)
  addu  $a0, $v1, $s3
  lw    $t6, ($a0)
  mflo  $t3
  addu  $t4, $v1, $t3
  lw    $t5, ($t4)
  subu  $t7, $t5, $t6
  b     .L7F0B4650
   sw    $t7, 0x10($s0)
  sw    $zero, 0x10($s0)
.L7F0B464C:
  lw    $a1, ($s6)
.L7F0B4650:
  slt   $at, $s2, $a1
  move  $s1, $s2
  addiu $s0, $s0, 0x50
  addiu $s3, $s3, 0x18
  addiu $a0, $a0, 0x18
  bnez  $at, .L7F0B44F4
   sw    $s7, -0x28($s0)
  li    $s1, 1
.L7F0B4670:
  jal   sub_GAME_7F0BC530
   nop   
  lw    $t8, ($s6)
  slti  $at, $t8, 2
  bnezl $at, .L7F0B46A8
   lw    $a0, ($fp)
.L7F0B4688:
  jal   sub_GAME_7F0B9338
   move  $a0, $s1
  lw    $t9, ($s6)
  addiu $s1, $s1, 1
  slt   $at, $s1, $t9
  bnez  $at, .L7F0B4688
   nop   
  lw    $a0, ($fp)
.L7F0B46A8:
  lui   $v1, %hi(D_800443C4)
  addiu $v1, %lo(D_800443C4) # addiu $v1, $v1, 0x43c4
  lw    $v0, ($a0)
  move  $s1, $zero
  move  $s0, $zero
  beqz  $v0, .L7F0B4700
   nop   
  move  $a0, $s1
.L7F0B46C8:
  jal   sub_GAME_7F0B993C
   sw    $v1, 0x4c($sp)
  lw    $a0, ($fp)
  lw    $v1, 0x4c($sp)
  addiu $s0, $s0, 8
  addu  $t0, $a0, $s0
  sb    $v0, ($v1)
  lw    $t1, ($t0)
  addiu $s1, $s1, 1
  addiu $v1, $v1, 1
  bnezl $t1, .L7F0B46C8
   move  $a0, $s1
  move  $s1, $zero
  lw    $v0, ($a0)
.L7F0B4700:
  beqz  $v0, .L7F0B4730
   move  $s0, $zero
.L7F0B4708:
  jal   sub_GAME_7F0B9B94
   move  $a0, $s1
  lw    $a0, ($fp)
  addiu $s0, $s0, 8
  addiu $s1, $s1, 1
  addu  $t2, $a0, $s0
  lw    $t3, ($t2)
  bnez  $t3, .L7F0B4708
   nop   
  move  $s1, $zero
.L7F0B4730:
  lw    $t4, ($s6)
  blezl $t4, .L7F0B4760
   lw    $t6, ($a0)
.L7F0B473C:
  jal   sub_GAME_7F0B95D8
   move  $a0, $s1
  lw    $t5, ($s6)
  addiu $s1, $s1, 1
  slt   $at, $s1, $t5
  bnez  $at, .L7F0B473C
   nop   
  lw    $a0, ($fp)
  lw    $t6, ($a0)
.L7F0B4760:
  move  $s0, $zero
  move  $v0, $a0
  beqz  $t6, .L7F0B4794
   nop   
  lbu   $t7, 6($v0)
.L7F0B4774:
  addiu $s0, $s0, 8
  andi  $t8, $t7, 0xfe
  sb    $t8, 6($v0)
  lw    $t9, ($fp)
  addu  $v0, $t9, $s0
  lw    $t0, ($v0)
  bnezl $t0, .L7F0B4774
   lbu   $t7, 6($v0)
.L7F0B4794:
  jal   sub_GAME_7F0B37EC
   nop   
.L7F0B479C:
  jal   sub_GAME_7F0BAA5C
   lw    $a0, 0xb8($sp)
  lw    $ra, 0x3c($sp)
  li    $t1, 200
  lui   $at, %hi(D_800442F8)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  lw    $s3, 0x24($sp)
  lw    $s4, 0x28($sp)
  lw    $s5, 0x2c($sp)
  lw    $s6, 0x30($sp)
  lw    $s7, 0x34($sp)
  lw    $fp, 0x38($sp)
  sw    $t1, %lo(D_800442F8)($at)
  jr    $ra
   addiu $sp, $sp, 0xb8
");

asm(R"
glabel sub_GAME_7F0B47E0
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F0B667C
   nop   
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f12
  jal   sub_GAME_7F058C4C
   nop   
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

void sub_GAME_7F0B4810(float arg0) {
  room_data_float1 = arg0;
  room_data_float2 = (float)(1.0f / arg0);
}

float get_room_data_float2(void) { return room_data_float2; }

float get_room_data_float1(void) { return room_data_float1; }

asm(R"
glabel sub_GAME_7F0B4848
  lui   $t6, %hi(D_80041400) 
  lw    $t6, %lo(D_80041400)($t6)
  lui   $t8, %hi(levelinfotable) 
  addiu $t8, %lo(levelinfotable) # addiu $t8, $t8, 0x448c
  sll   $t7, $t6, 2
  subu  $t7, $t7, $t6
  sll   $t7, $t7, 3
  addu  $v0, $t7, $t8
  lwc1  $f4, 0x14($v0)
  lwc1  $f6, 0xc($v0)
  jr    $ra
   div.s $f0, $f4, $f6
");

float sub_GAME_7F0B4878(void) { return D_800413FC; }

asm(R"
.late_rodata
glabel jpt_80058C58
.word .L7F0B4914
.word .L7F0B4914
.word .L7F0B4914
.word .L7F0B491C
.word .L7F0B491C
.word .L7F0B491C
.word .L7F0B4914
.word .L7F0B491C
.word .L7F0B4914

.text
glabel sub_GAME_7F0B4884
  addiu $sp, $sp, -0x40
  sw    $ra, 0x3c($sp)
  sw    $s6, 0x30($sp)
  lui   $at, %hi(num_visible_rooms_in_cur_global_vis_packet)
  sw    $fp, 0x38($sp)
  sw    $s7, 0x34($sp)
  sw    $s5, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  li    $s6, -1
  jal   get_cur_playernum
   sw    $zero, %lo(num_visible_rooms_in_cur_global_vis_packet)($at)
  jal   sub_GAME_7F09B4D8
   move  $a0, $v0
  bnez  $v0, .L7F0B48D8
   nop   
  jal   sub_GAME_7F0B66E8
   nop   
.L7F0B48D8:
  jal   get_camera_mode
   nop   
  lui   $v1, %hi(D_800442F8)
  addiu $t7, $v0, -1
  addiu $v1, %lo(D_800442F8) # addiu $v1, $v1, 0x42f8
  li    $t6, 3
  sltiu $at, $t7, 9
  beqz  $at, .L7F0B491C
   sw    $t6, ($v1)
  sll   $t7, $t7, 2
  lui   $at, %hi(jpt_80058C58)
  addu  $at, $at, $t7
  lw    $t7, %lo(jpt_80058C58)($at)
.L7F0B490C:
  jr    $t7
   nop   
.L7F0B4914:
  li    $t8, 200
  sw    $t8, ($v1)
def_7F0B490C:
.L7F0B491C:
  jal   get_cur_players_room
   nop   
  lui   $at, %hi(current_room_maybe)
  move  $s3, $v0
  jal   get_BONDdata_position
   sw    $v0, %lo(current_room_maybe)($at)
  jal   get_BONDdata_position3
   move  $s4, $v0
  lui   $v1, %hi(ptr_bgdata_portals)
  move  $s5, $v0
  lw    $v1, %lo(ptr_bgdata_portals)($v1)
  move  $s7, $zero
  li    $fp, 11
  lw    $t9, ($v1)
.L7F0B4954:
  lui   $s2, %hi(D_800443C4)
  addiu $s2, %lo(D_800443C4) # addiu $s2, $s2, 0x43c4
  beqz  $t9, .L7F0B49F4
   move  $s0, $zero
  move  $s1, $zero
  move  $v0, $v1
.L7F0B496C:
  lbu   $t0, ($s2)
  bnezl $t0, .L7F0B49E0
   lw    $t6, 8($v0)
  beql  $s0, $s6, .L7F0B49E0
   lw    $t6, 8($v0)
  lbu   $t1, 4($v0)
  move  $a0, $s0
  move  $a1, $s4
  beq   $s3, $t1, .L7F0B49A0
   nop   
  lbu   $t2, 5($v0)
  bne   $s3, $t2, .L7F0B49D0
   nop   
.L7F0B49A0:
  jal   sub_GAME_7F0B9F14
   move  $a2, $s5
  beqz  $v0, .L7F0B49D0
   lui   $v1, %hi(ptr_bgdata_portals)
  lw    $v1, %lo(ptr_bgdata_portals)($v1)
  move  $s6, $s0
  addu  $v0, $v1, $s1
  lbu   $t4, 4($v0)
  lbu   $t3, 5($v0)
  xor   $t5, $s3, $t4
  b     .L7F0B49F4
   xor   $s3, $t3, $t5
.L7F0B49D0:
  lui   $v1, %hi(ptr_bgdata_portals)
  lw    $v1, %lo(ptr_bgdata_portals)($v1)
  addu  $v0, $v1, $s1
  lw    $t6, 8($v0)
.L7F0B49E0:
  addiu $s0, $s0, 1
  addiu $s2, $s2, 1
  addiu $s1, $s1, 8
  bnez  $t6, .L7F0B496C
   addiu $v0, $v0, 8
.L7F0B49F4:
  sll   $t7, $s0, 3
  addu  $t8, $v1, $t7
  lw    $t9, ($t8)
  addiu $s7, $s7, 1
  beqz  $t9, .L7F0B4A14
   nop   
  bnel  $s7, $fp, .L7F0B4954
   lw    $t9, ($v1)
.L7F0B4A14:
  lui   $at, %hi(current_room_maybe)
  jal   sub_GAME_7F0B8A6C
   sw    $s3, %lo(current_room_maybe)($at)
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
glabel sub_GAME_7F0B4A50
  sw    $a1, 4($sp)
  lbu   $t6, ($a0)
  li    $t0, 255
  andi  $a2, $a1, 0xff
  beq   $t0, $t6, .L7F0B4A94
   move  $v0, $zero
  addu  $v1, $a0, $zero
  lbu   $a1, ($a0)
  move  $a3, $a2
.L7F0B4A74:
  beq   $a3, $a1, .L7F0B4AAC
   addiu $v0, $v0, 1
  slti  $at, $v0, 0x10
  beqz  $at, .L7F0B4A94
   addiu $v1, $v1, 1
  lbu   $a1, ($v1)
  bne   $t0, $a1, .L7F0B4A74
   nop   
.L7F0B4A94:
  slti  $at, $v0, 0xf
  beqz  $at, .L7F0B4AAC
   addu  $v1, $a0, $v0
  li    $t7, 255
  sb    $a2, ($v1)
  sb    $t7, 1($v1)
.L7F0B4AAC:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B4AB4
  addiu $sp, $sp, -0x160
  sw    $s5, 0x2c($sp)
  lui   $s5, %hi(ptr_bgdata_portals)
  addiu $s5, %lo(ptr_bgdata_portals) # addiu $s5, $s5, -0x80
  lw    $t0, ($s5)
  sw    $ra, 0x3c($sp)
  sw    $fp, 0x38($sp)
  sw    $s7, 0x34($sp)
  sw    $s6, 0x30($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a3, 0x16c($sp)
  lw    $t6, ($t0)
  move  $s3, $a0
  move  $s4, $a1
  beqz  $t6, .L7F0B4B4C
   move  $s6, $a2
  addiu $s1, $sp, 0x5c
  move  $s2, $zero
  sw    $zero, 0x12c($sp)
  lw    $a0, 0x12c($sp)
.L7F0B4B14:
  move  $a1, $s3
  jal   sub_GAME_7F0B9F14
   move  $a2, $s4
  sb    $v0, ($s1)
  lw    $t7, 0x12c($sp)
  lw    $t0, ($s5)
  addiu $s2, $s2, 8
  addiu $t8, $t7, 1
  sw    $t8, 0x12c($sp)
  addu  $t9, $t0, $s2
  lw    $t1, ($t9)
  addiu $s1, $s1, 1
  bnezl $t1, .L7F0B4B14
   lw    $a0, 0x12c($sp)
.L7F0B4B4C:
  addiu $v1, $sp, 0x150
  move  $a0, $s6
  addiu $v0, $sp, 0x158
.L7F0B4B58:
  lbu   $t2, ($a0)
  addiu $v1, $v1, 1
  sltu  $at, $v1, $v0
  addiu $a0, $a0, 1
  bnez  $at, .L7F0B4B58
   sb    $t2, -1($v1)
  move  $a0, $s6
  addiu $v0, $sp, 0x130
  addiu $v1, $sp, 0x138
.L7F0B4B7C:
  lbu   $t3, ($a0)
  addiu $v0, $v0, 1
  sltu  $at, $v0, $v1
  addiu $a0, $a0, 1
  bnez  $at, .L7F0B4B7C
   sb    $t3, -1($v0)
  lbu   $t4, 0x150($sp)
  li    $a1, 255
  sw    $zero, 0x124($sp)
  beq   $a1, $t4, .L7F0B4BC8
   addiu $fp, $sp, 0x160
  addiu $v1, $sp, 0x150
  addiu $v0, $sp, 0x160
  lbu   $t5, 1($v1)
.L7F0B4BB4:
  addiu $v1, $v1, 1
  beql  $a1, $t5, .L7F0B4BCC
   sw    $zero, 0x124($sp)
  bnel  $v1, $v0, .L7F0B4BB4
   lbu   $t5, 1($v1)
.L7F0B4BC8:
  sw    $zero, 0x124($sp)
.L7F0B4BCC:
  li    $s7, 2
  li    $s6, 1
  addiu $s4, $sp, 0x130
  addiu $s3, $sp, 0x140
.L7F0B4BDC:
  li    $t6, 255
  sb    $t6, 0x140($sp)
  sw    $zero, 0x12c($sp)
  lw    $t7, ($t0)
  move  $s2, $zero
  move  $v1, $t0
  beql  $t7, $zero, .L7F0B4CEC
   lbu   $a0, 0x140($sp)
  lbu   $t8, 0x150($sp)
.L7F0B4C00:
  lw    $t9, 0x12c($sp)
  addiu $t1, $sp, 0x5c
  beq   $a1, $t8, .L7F0B4CC4
   addu  $s1, $t9, $t1
  addiu $t2, $sp, 0x150
  addu  $s0, $zero, $t2
  lbu   $v0, ($s1)
.L7F0B4C1C:
  bne   $s6, $v0, .L7F0B4C64
   nop   
  lbu   $t3, 4($v1)
  lbu   $t4, ($s0)
  move  $a0, $s3
  bne   $t3, $t4, .L7F0B4C64
   nop   
  jal   sub_GAME_7F0B4A50
   lbu   $a1, 5($v1)
  lw    $t5, ($s5)
  move  $a0, $s4
  addu  $t6, $t5, $s2
  jal   sub_GAME_7F0B4A50
   lbu   $a1, 5($t6)
  lw    $t0, ($s5)
  sb    $zero, ($s1)
  andi  $v0, $zero, 0xff
  addu  $v1, $t0, $s2
.L7F0B4C64:
  bnel  $s7, $v0, .L7F0B4CAC
   lbu   $t2, 1($s0)
  lbu   $t7, 5($v1)
  lbu   $t8, ($s0)
  move  $a0, $s3
  bnel  $t7, $t8, .L7F0B4CAC
   lbu   $t2, 1($s0)
  jal   sub_GAME_7F0B4A50
   lbu   $a1, 4($v1)
  lw    $t9, ($s5)
  move  $a0, $s4
  addu  $t1, $t9, $s2
  jal   sub_GAME_7F0B4A50
   lbu   $a1, 4($t1)
  lw    $t0, ($s5)
  sb    $zero, ($s1)
  addu  $v1, $t0, $s2
  lbu   $t2, 1($s0)
.L7F0B4CAC:
  li    $at, 255
  addiu $s0, $s0, 1
  beql  $t2, $at, .L7F0B4CC8
   lw    $t3, 0x12c($sp)
  bnel  $s0, $fp, .L7F0B4C1C
   lbu   $v0, ($s1)
.L7F0B4CC4:
  lw    $t3, 0x12c($sp)
.L7F0B4CC8:
  addiu $s2, $s2, 8
  addiu $v1, $v1, 8
  addiu $t4, $t3, 1
  sw    $t4, 0x12c($sp)
  lw    $t5, ($v1)
  li    $a1, 255
  bnezl $t5, .L7F0B4C00
   lbu   $t8, 0x150($sp)
  lbu   $a0, 0x140($sp)
.L7F0B4CEC:
  addiu $v1, $sp, 0x150
  addiu $v0, $sp, 0x140
  bne   $a1, $a0, .L7F0B4D04
   nop   
  b     .L7F0B4D54
   lbu   $v0, 0x150($sp)
.L7F0B4D04:
  lbu   $t6, ($v0)
  addiu $v0, $v0, 1
  addiu $t7, $sp, 0x150
  sltu  $at, $v0, $t7
  addiu $v1, $v1, 1
  bnez  $at, .L7F0B4D04
   sb    $t6, -1($v1)
  beq   $a1, $a0, .L7F0B4D48
   sw    $zero, 0x124($sp)
  move  $v0, $s3
  lbu   $t8, 1($v0)
.L7F0B4D30:
  addiu $v0, $v0, 1
  addiu $t9, $sp, 0x150
  beq   $a1, $t8, .L7F0B4D48
   nop   
  bnel  $v0, $t9, .L7F0B4D30
   lbu   $t8, 1($v0)
.L7F0B4D48:
  bne   $a1, $a0, .L7F0B4BDC
   sw    $zero, 0x124($sp)
  lbu   $v0, 0x150($sp)
.L7F0B4D54:
  beq   $a1, $v0, .L7F0B4D9C
   lw    $t1, 0x124($sp)
  lw    $t3, 0x16c($sp)
  addiu $t2, $sp, 0x150
  addu  $v1, $t1, $t2
  lbu   $v0, ($v1)
  addu  $a0, $t3, $t1
  sb    $v0, ($a0)
.L7F0B4D74:
  lw    $t5, 0x124($sp)
  addiu $v1, $v1, 1
  addiu $a0, $a0, 1
  addiu $t6, $t5, 1
  slti  $at, $t6, 7
  beqz  $at, .L7F0B4D9C
   sw    $t6, 0x124($sp)
  lbu   $v0, ($v1)
  bnel  $a1, $v0, .L7F0B4D74
   sb    $v0, ($a0)
.L7F0B4D9C:
  lw    $t8, 0x16c($sp)
  lw    $t9, 0x124($sp)
  lw    $a2, 0x178($sp)
  li    $t7, 255
  addu  $t1, $t8, $t9
  sb    $t7, ($t1)
  blez  $a2, .L7F0B4E04
   sw    $zero, 0x124($sp)
  lbu   $t2, 0x130($sp)
  addiu $v0, $sp, 0x130
  lw    $a0, 0x170($sp)
  beql  $a1, $t2, .L7F0B4E08
   lw    $t5, 0x124($sp)
  lbu   $v1, ($v0)
  sw    $v1, ($a0)
.L7F0B4DD8:
  lw    $t3, 0x124($sp)
  addiu $v0, $v0, 1
  addiu $a0, $a0, 4
  addiu $t4, $t3, 1
  slt   $at, $t4, $a2
  beqz  $at, .L7F0B4E04
   sw    $t4, 0x124($sp)
  lbu   $v1, ($v0)
  li    $at, 255
  bnel  $v1, $at, .L7F0B4DD8
   sw    $v1, ($a0)
.L7F0B4E04:
  lw    $t5, 0x124($sp)
.L7F0B4E08:
  lw    $t6, 0x174($sp)
  sw    $t5, ($t6)
  lw    $ra, 0x3c($sp)
  lw    $fp, 0x38($sp)
  lw    $s7, 0x34($sp)
  lw    $s6, 0x30($sp)
  lw    $s5, 0x2c($sp)
  lw    $s4, 0x28($sp)
  lw    $s3, 0x24($sp)
  lw    $s2, 0x20($sp)
  lw    $s1, 0x1c($sp)
  lw    $s0, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x160
");

asm(R"
glabel sub_GAME_7F0B4E40
  addiu $sp, $sp, -0x30
  sw    $ra, 0x14($sp)
  move  $v0, $a0
  lui   $t6, (0xBC000002 >> 16) # lui $t6, 0xbc00
  lui   $t7, (0x80000040 >> 16) 
  ori   $t7, (0x80000040 & 0xFFFF) # ori $t7, $t7, 0x40
  ori   $t6, (0xBC000002 & 0xFFFF) # ori $t6, $t6, 2
  addiu $v1, $a0, 8
  sw    $t6, ($v0)
  sw    $t7, 4($v0)
  lui   $t8, (0x03860010 >> 16) # lui $t8, 0x386
  lui   $t9, %hi(GlobalLight+0x8) 
  addiu $t9, %lo(GlobalLight+0x8) # addiu $t9, $t9, 0x4848
  ori   $t8, (0x03860010 & 0xFFFF) # ori $t8, $t8, 0x10
  addiu $a1, $v1, 8
  sw    $t8, ($v1)
  sw    $t9, 4($v1)
  lui   $t0, (0x03880010 >> 16) # lui $t0, 0x388
  lui   $t1, %hi(GlobalLight) 
  addiu $t1, %lo(GlobalLight) # addiu $t1, $t1, 0x4840
  ori   $t0, (0x03880010 & 0xFFFF) # ori $t0, $t0, 0x10
  addiu $a2, $a1, 8
  lui   $t2, (0x03840010 >> 16) # lui $t2, 0x384
  sw    $t0, ($a1)
  sw    $t1, 4($a1)
  ori   $t2, (0x03840010 & 0xFFFF) # ori $t2, $t2, 0x10
  sw    $t2, ($a2)
  addiu $a0, $a2, 8
  sw    $a0, 0x30($sp)
  jal   sub_GAME_7F078474
   sw    $a2, 0x20($sp)
  lw    $a1, 0x30($sp)
  lw    $a2, 0x20($sp)
  lui   $t3, (0x03820010 >> 16) # lui $t3, 0x382
  ori   $t3, (0x03820010 & 0xFFFF) # ori $t3, $t3, 0x10
  sw    $v0, 4($a2)
  sw    $t3, ($a1)
  addiu $a0, $a1, 8
  sw    $a0, 0x30($sp)
  jal   sub_GAME_7F078474
   sw    $a1, 0x1c($sp)
  lw    $a0, 0x30($sp)
  lw    $a1, 0x1c($sp)
  addiu $t4, $v0, 0x10
  lui   $t5, (0xBC003C06 >> 16) # lui $t5, 0xbc00
  ori   $t5, (0xBC003C06 & 0xFFFF) # ori $t5, $t5, 0x3c06
  move  $v1, $a0
  sw    $t4, 4($a1)
  sw    $t5, ($v1)
  lui   $t6, %hi(ptr_bg_data) 
  lw    $t6, %lo(ptr_bg_data)($t6)
  lui   $t7, %hi(dword_CODE_bss_8007FF88) 
  li    $at, 1
  sw    $t6, 4($v1)
  lw    $t7, %lo(dword_CODE_bss_8007FF88)($t7)
  addiu $a0, $a0, 8
  move  $v0, $a0
  bne   $t7, $at, .L7F0B4F44
   lui   $t8, 0x600
  sw    $t8, ($v0)
  lui   $t9, %hi(dword_CODE_bss_8007BF98) 
  lw    $t9, %lo(dword_CODE_bss_8007BF98)($t9)
  addiu $a0, $a0, 8
  b     .L7F0B4F68
   sw    $t9, 4($v0)
.L7F0B4F44:
  jal   sub_GAME_7F0BB070
   move  $a1, $zero
  jal   sub_GAME_7F0B8D78
   move  $a0, $v0
  jal   sub_GAME_7F0B4FB4
   move  $a0, $v0
  jal   sub_GAME_7F0BB298
   move  $a0, $v0
  move  $a0, $v0
.L7F0B4F68:
  lui   $t0, (0x01030040 >> 16) # lui $t0, 0x103
  ori   $t0, (0x01030040 & 0xFFFF) # ori $t0, $t0, 0x40
  move  $v0, $a0
  sw    $t0, ($v0)
  lui   $t1, %hi(m) 
  lw    $t1, %lo(m)($t1)
  addiu $a0, $a0, 8
  jal   sub_GAME_7F08BCF4
   sw    $t1, 4($v0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B4F9C
  lui   $t6, %hi(dword_CODE_bss_8007FF94) 
  lw    $t6, %lo(dword_CODE_bss_8007FF94)($t6)
  sll   $t7, $a0, 2
  addu  $t8, $t6, $t7
  jr    $ra
   lwc1  $f0, 4($t8)
");

asm(R"
glabel sub_GAME_7F0B4FB4
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  lh    $t7, 0x7f2($v0)
  lh    $a2, 0x7f6($v0)
  lh    $t6, 0x7f0($v0)
  lh    $a1, 0x7f4($v0)
  addu  $t8, $a2, $t7
  sw    $t8, 0x10($sp)
  jal   sub_GAME_7F0B5058
   addu  $a3, $a1, $t6
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B4FF4
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  mtc1  $a3, $f12
  sw    $a0, 0x28($sp)
  sw    $a1, 0x2c($sp)
  jal   sub_GAME_7F05C4B8
   sw    $a2, 0x30($sp)
  sw    $v0, 0x20($sp)
  jal   sub_GAME_7F05C4B8
   lwc1  $f12, 0x38($sp)
  lwc1  $f4, 0x2c($sp)
  lwc1  $f8, 0x30($sp)
  lw    $a0, 0x28($sp)
  trunc.w.s $f6, $f4
  lw    $a3, 0x20($sp)
  sw    $v0, 0x10($sp)
  trunc.w.s $f10, $f8
  mfc1  $a1, $f6
  mfc1  $a2, $f10
  jal   sub_GAME_7F0B5058
   nop   
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B5058
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  sw    $a0, ($sp)
  sw    $a3, 0xc($sp)
  lh    $v1, 0x7f4($v0)
  slt   $at, $a1, $v1
  beql  $at, $zero, .L7F0B5080
   lh    $a0, 0x7f6($v0)
  move  $a1, $v1
  lh    $a0, 0x7f6($v0)
.L7F0B5080:
  mtc1  $a1, $f4
  slt   $at, $a2, $a0
  beqz  $at, .L7F0B5094
   cvt.s.w $f6, $f4
  move  $a2, $a0
.L7F0B5094:
  lh    $t6, 0x7f0($v0)
  lw    $t7, 0xc($sp)
  mtc1  $a2, $f16
  addu  $a3, $v1, $t6
  slt   $at, $a3, $t7
  beqz  $at, .L7F0B50B4
   cvt.s.w $f18, $f16
  sw    $a3, 0xc($sp)
.L7F0B50B4:
  lh    $t8, 0x7f2($v0)
  lw    $a3, 0x10($sp)
  addu  $v1, $a0, $t8
  slt   $at, $v1, $a3
  beql  $at, $zero, .L7F0B50D4
   lui   $at, 0x4080
  move  $a3, $v1
  li    $at, 0x40800000 # 4.000000
.L7F0B50D4:
  mtc1  $at, $f0
  lw    $v1, ($sp)
  lui   $at, 0xed00
  mul.s $f8, $f6, $f0
  addiu $t0, $v1, 8
  sw    $t0, ($sp)
  mul.s $f4, $f18, $f0
  trunc.w.s $f10, $f8
  trunc.w.s $f6, $f4
  mfc1  $t2, $f10
  mtc1  $a3, $f4
  mfc1  $t7, $f6
  andi  $t3, $t2, 0xfff
  sll   $t4, $t3, 0xc
  or    $t5, $t4, $at
  andi  $t8, $t7, 0xfff
  or    $t9, $t5, $t8
  sw    $t9, ($v1)
  lw    $t0, 0xc($sp)
  cvt.s.w $f6, $f4
  mtc1  $t0, $f8
  nop   
  cvt.s.w $f10, $f8
  mul.s $f16, $f10, $f0
  nop   
  mul.s $f8, $f6, $f0
  trunc.w.s $f18, $f16
  trunc.w.s $f10, $f8
  mfc1  $t2, $f18
  mfc1  $t7, $f10
  andi  $t3, $t2, 0xfff
  sll   $t4, $t3, 0xc
  andi  $t5, $t7, 0xfff
  or    $t8, $t4, $t5
  sw    $t8, 4($v1)
  jr    $ra
   lw    $v0, ($sp)
");

asm(R"
glabel sub_GAME_7F0B5168
  lui   $v1, %hi(table_for_portals)
  lui   $a0, %hi(table_for_portals+0xFA0)
  addiu $a0, %lo(table_for_portals+0xFA0) # addiu $a0, $a0, 0x25b8
  addiu $v1, %lo(table_for_portals) # addiu $v1, $v1, 0x1618
  li    $v0, -1
.L7F0B517C:
  addiu $v1, $v1, 0x50
  sw    $v0, -0x3c($v1)
  sw    $v0, -0x28($v1)
  sw    $v0, -0x14($v1)
  bne   $v1, $a0, .L7F0B517C
   sw    $v0, -0x50($v1)
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B519C
  lwc1  $f0, ($a0)
  lwc1  $f4, ($a1)
  move  $v0, $zero
  c.le.s $f4, $f0
  nop   
  bc1f  .L7F0B5200
   nop   
  lwc1  $f6, 8($a1)
  c.le.s $f0, $f6
  nop   
  bc1f  .L7F0B5200
   nop   
  lwc1  $f0, 4($a0)
  lwc1  $f8, 4($a1)
  c.le.s $f8, $f0
  nop   
  bc1f  .L7F0B5200
   nop   
  lwc1  $f10, 0xc($a1)
  c.le.s $f0, $f10
  nop   
  bc1f  .L7F0B5200
   nop   
  jr    $ra
   li    $v0, 1

.L7F0B5200:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B5208
  addiu $sp, $sp, -0x78
  sw    $ra, 0x34($sp)
  sw    $s6, 0x30($sp)
  sw    $s5, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a0, 0x78($sp)
  move  $s0, $a1
  move  $s1, $zero
  move  $s6, $zero
  move  $s2, $zero
  move  $s3, $zero
  move  $s4, $zero
  move  $s5, $zero
  jal   video_related_27
   addiu $a0, $sp, 0x3c
  lui   $at, %hi(D_800413FC)
  lwc1  $f6, %lo(D_800413FC)($at)
  lwc1  $f4, 0x40($sp)
  lw    $t6, 0x78($sp)
  lui   $t8, %hi(array_room_info) 
  div.s $f8, $f4, $f6
  sll   $t7, $t6, 2
  addu  $t7, $t7, $t6
  sll   $t7, $t7, 4
  addiu $t8, %lo(array_room_info) # addiu $t8, $t8, 0x1414
  addu  $a2, $t7, $t8
  move  $v1, $zero
  swc1  $f8, 0x40($sp)
  andi  $t9, $v1, 1
.L7F0B528C:
  beqz  $t9, .L7F0B52A0
   andi  $t0, $v1, 2
  lwc1  $f10, 0x38($a2)
  b     .L7F0B52A8
   swc1  $f10, 0x5c($sp)
.L7F0B52A0:
  lwc1  $f16, 0x44($a2)
  swc1  $f16, 0x5c($sp)
.L7F0B52A8:
  beqz  $t0, .L7F0B52BC
   andi  $t1, $v1, 4
  lwc1  $f18, 0x3c($a2)
  b     .L7F0B52C4
   swc1  $f18, 0x60($sp)
.L7F0B52BC:
  lwc1  $f4, 0x48($a2)
  swc1  $f4, 0x60($sp)
.L7F0B52C4:
  beqz  $t1, .L7F0B52D8
   addiu $a0, $sp, 0x5c
  lwc1  $f6, 0x40($a2)
  b     .L7F0B52E0
   swc1  $f6, 0x64($sp)
.L7F0B52D8:
  lwc1  $f8, 0x4c($a2)
  swc1  $f8, 0x64($sp)
.L7F0B52E0:
  addiu $a1, $sp, 0x68
  sw    $v1, 0x74($sp)
  jal   sub_GAME_7F0B5488
   sw    $a2, 0x38($sp)
  lw    $v1, 0x74($sp)
  lw    $a2, 0x38($sp)
  bnez  $v0, .L7F0B5390
   li    $a3, 8
  lwc1  $f10, 0x70($sp)
  lwc1  $f18, 0x40($sp)
  lwc1  $f4, 0x68($sp)
  neg.s $f16, $f10
  lwc1  $f10, 0x68($sp)
  c.le.s $f18, $f16
  lwc1  $f16, 0x6c($sp)
  bc1fl .L7F0B532C
   lwc1  $f6, ($s0)
  addiu $s1, $s1, 1
  lwc1  $f6, ($s0)
.L7F0B532C:
  c.le.s $f6, $f4
  lwc1  $f6, 0x6c($sp)
  bc1fl .L7F0B5344
   lwc1  $f8, 8($s0)
  addiu $s2, $s2, 1
  lwc1  $f8, 8($s0)
.L7F0B5344:
  c.le.s $f10, $f8
  nop   
  bc1fl .L7F0B535C
   lwc1  $f18, 4($s0)
  addiu $s3, $s3, 1
  lwc1  $f18, 4($s0)
.L7F0B535C:
  c.le.s $f18, $f16
  nop   
  bc1fl .L7F0B5374
   lwc1  $f4, 0xc($s0)
  addiu $s4, $s4, 1
  lwc1  $f4, 0xc($s0)
.L7F0B5374:
  c.le.s $f6, $f4
  nop   
  bc1f  .L7F0B5388
   nop   
  addiu $s5, $s5, 1
.L7F0B5388:
  b     .L7F0B5420
   addiu $s6, $s6, 1
.L7F0B5390:
  lwc1  $f8, 0x70($sp)
  lwc1  $f16, 0x40($sp)
  lwc1  $f4, 0x68($sp)
  neg.s $f10, $f8
  lwc1  $f6, 0x68($sp)
  c.le.s $f16, $f10
  lwc1  $f16, 0x6c($sp)
  bc1fl .L7F0B53BC
   lwc1  $f18, ($s0)
  addiu $s1, $s1, 1
  lwc1  $f18, ($s0)
.L7F0B53BC:
  c.le.s $f4, $f18
  lwc1  $f18, 0x6c($sp)
  bc1fl .L7F0B53D8
   lwc1  $f8, 8($s0)
  b     .L7F0B53EC
   addiu $s2, $s2, 1
  lwc1  $f8, 8($s0)
.L7F0B53D8:
  c.le.s $f8, $f6
  nop   
  bc1fl .L7F0B53F0
   lwc1  $f10, 4($s0)
  addiu $s3, $s3, 1
.L7F0B53EC:
  lwc1  $f10, 4($s0)
.L7F0B53F0:
  c.le.s $f16, $f10
  nop   
  bc1fl .L7F0B540C
   lwc1  $f4, 0xc($s0)
  b     .L7F0B5420
   addiu $s4, $s4, 1
  lwc1  $f4, 0xc($s0)
.L7F0B540C:
  c.le.s $f4, $f18
  nop   
  bc1fl .L7F0B5424
   addiu $v1, $v1, 1
  addiu $s5, $s5, 1
.L7F0B5420:
  addiu $v1, $v1, 1
.L7F0B5424:
  bnel  $v1, $a3, .L7F0B528C
   andi  $t9, $v1, 1
  beq   $s6, $a3, .L7F0B545C
   lw    $s0, 0x18($sp)
  beq   $s1, $a3, .L7F0B545C
   nop   
  beq   $s2, $a3, .L7F0B545C
   nop   
  beq   $s3, $a3, .L7F0B545C
   nop   
  beq   $s4, $a3, .L7F0B545C
   nop   
  bne   $s5, $a3, .L7F0B5464
   li    $v0, 1
.L7F0B545C:
  b     .L7F0B5464
   move  $v0, $zero
.L7F0B5464:
  lw    $ra, 0x34($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  lw    $s3, 0x24($sp)
  lw    $s4, 0x28($sp)
  lw    $s5, 0x2c($sp)
  lw    $s6, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x78
");

asm(R"
glabel sub_GAME_7F0B5488
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  move  $s0, $a1
  jal   get_BONDdata_field_10CC
   sw    $a0, 0x20($sp)
  lw    $a2, 0x20($sp)
  lui   $v1, %hi(room_data_float2)
  addiu $v1, %lo(room_data_float2) # addiu $v1, $v1, 0x13f8
  lwc1  $f6, ($v1)
  lwc1  $f4, ($a2)
  move  $a0, $v0
  move  $a1, $s0
  mul.s $f8, $f4, $f6
  swc1  $f8, ($s0)
  lwc1  $f16, ($v1)
  lwc1  $f10, 4($a2)
  mul.s $f18, $f10, $f16
  swc1  $f18, 4($s0)
  lwc1  $f6, ($v1)
  lwc1  $f4, 8($a2)
  mul.s $f8, $f4, $f6
  jal   sub_GAME_7F058474
   swc1  $f8, 8($s0)
  move  $a0, $s0
  jal   sub_GAME_7F078060
   move  $a1, $s0
  mtc1  $zero, $f10
  lwc1  $f16, 8($s0)
  lw    $ra, 0x1c($sp)
  li    $v0, 1
  c.lt.s $f10, $f16
  nop   
  bc1f  .L7F0B551C
   nop   
  b     .L7F0B551C
   move  $v0, $zero
.L7F0B551C:
  lw    $s0, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x20
");

asm(R"
.late_rodata
glabel D_80058C7C
.word 0x3f666666 /*0.89999998*/
.text
glabel sub_GAME_7F0B5528
  addiu $sp, $sp, -0xb0
  sdc1  $f20, 0x18($sp)
  mtc1  $a1, $f20
  sw    $ra, 0x54($sp)
  sw    $s6, 0x48($sp)
  move  $s6, $a2
  sw    $fp, 0x50($sp)
  sw    $s7, 0x4c($sp)
  sw    $s5, 0x44($sp)
  sw    $s4, 0x40($sp)
  sw    $s3, 0x3c($sp)
  sw    $s2, 0x38($sp)
  sw    $s1, 0x34($sp)
  sw    $s0, 0x30($sp)
  sdc1  $f24, 0x28($sp)
  sdc1  $f22, 0x20($sp)
  jal   get_BONDdata_field_10CC
   sw    $a0, 0xb0($sp)
  sw    $v0, 0xac($sp)
  li    $fp, 1
  jal   video_related_27
   addiu $a0, $sp, 0x98
  lui   $at, %hi(D_800413FC)
  lwc1  $f6, %lo(D_800413FC)($at)
  lwc1  $f4, 0x9c($sp)
  lui   $s3, %hi(ptr_bgdata_portals)
  lw    $s5, 0xb0($sp)
  div.s $f8, $f4, $f6
  addiu $s3, %lo(ptr_bgdata_portals) # addiu $s3, $s3, -0x80
  lw    $t7, ($s3)
  sll   $t6, $s5, 3
  move  $s5, $t6
  addu  $t8, $t7, $t6
  move  $s2, $zero
  move  $s0, $s6
  swc1  $f8, 0x9c($sp)
  lw    $v0, ($t8)
  lbu   $a0, ($v0)
  blezl $a0, .L7F0B56FC
   mtc1  $zero, $f22
  lui   $at, %hi(D_80058C7C)
  lui   $s4, %hi(room_data_float2)
  mtc1  $zero, $f22
  addiu $s4, %lo(room_data_float2) # addiu $s4, $s4, 0x13f8
  lwc1  $f24, %lo(D_80058C7C)($at)
  move  $s1, $zero
  addiu $s7, $sp, 0x80
  addu  $t9, $v0, $s1
.L7F0B55E8:
  lwc1  $f10, 4($t9)
  c.eq.s $f20, $f22
  move  $a1, $s7
  swc1  $f10, ($s0)
  lw    $t0, ($s3)
  addu  $t1, $t0, $s5
  lw    $t2, ($t1)
  addu  $t3, $t2, $s1
  lwc1  $f18, 8($t3)
  swc1  $f18, 4($s0)
  lw    $t4, ($s3)
  addu  $t5, $t4, $s5
  lw    $t6, ($t5)
  addu  $t7, $t6, $s1
  lwc1  $f4, 0xc($t7)
  bc1t  .L7F0B5670
   swc1  $f4, 8($s0)
  jal   sub_GAME_7F0B96CC
   lw    $a0, 0xb0($sp)
  lwc1  $f8, 0x80($sp)
  lwc1  $f6, ($s0)
  lwc1  $f4, 4($s0)
  mul.s $f10, $f8, $f20
  add.s $f18, $f6, $f10
  swc1  $f18, ($s0)
  lwc1  $f8, 0x84($sp)
  lwc1  $f18, 8($s0)
  mul.s $f6, $f8, $f20
  add.s $f10, $f4, $f6
  swc1  $f10, 4($s0)
  lwc1  $f8, 0x88($sp)
  mul.s $f4, $f8, $f20
  add.s $f6, $f18, $f4
  swc1  $f6, 8($s0)
.L7F0B5670:
  lwc1  $f10, ($s0)
  lwc1  $f8, ($s4)
  lwc1  $f4, 4($s0)
  move  $a1, $s0
  mul.s $f18, $f10, $f8
  lwc1  $f8, 8($s0)
  swc1  $f18, ($s0)
  lwc1  $f6, ($s4)
  mul.s $f10, $f4, $f6
  swc1  $f10, 4($s0)
  lwc1  $f18, ($s4)
  mul.s $f4, $f8, $f18
  swc1  $f4, 8($s0)
  jal   sub_GAME_7F058474
   lw    $a0, 0xac($sp)
  lwc1  $f6, 0x9c($sp)
  lwc1  $f18, 8($s0)
  neg.s $f10, $f6
  mul.s $f8, $f10, $f24
  c.lt.s $f8, $f18
  nop   
  bc1fl .L7F0B56D4
   lw    $t8, ($s3)
  move  $fp, $zero
  lw    $t8, ($s3)
.L7F0B56D4:
  addiu $s2, $s2, 1
  addiu $s1, $s1, 0xc
  addu  $t9, $t8, $s5
  lw    $v0, ($t9)
  addiu $s0, $s0, 0xc
  lbu   $a0, ($v0)
  slt   $at, $s2, $a0
  bnezl $at, .L7F0B55E8
   addu  $t9, $v0, $s1
  mtc1  $zero, $f22
.L7F0B56FC:
  beqz  $fp, .L7F0B570C
   move  $a3, $a0
  b     .L7F0B5828
   move  $v0, $zero
.L7F0B570C:
  blez  $a0, .L7F0B5824
   move  $s2, $zero
  move  $s0, $s6
  li    $a2, 12
.L7F0B571C:
  addiu $a1, $s2, 1
  div   $zero, $a1, $a0
  lwc1  $f16, 8($s0)
  mfhi  $v1
  move  $s2, $a1
  c.lt.s $f22, $f16
  bnez  $a0, .L7F0B5740
   nop   
  break 7
.L7F0B5740:
  li    $at, -1
  bne   $a0, $at, .L7F0B5758
   lui   $at, 0x8000
  bne   $a1, $at, .L7F0B5758
   nop   
  break 6
.L7F0B5758:
  bc1fl .L7F0B5784
   c.le.s $f16, $f22
  multu $v1, $a2
  mflo  $t0
  addu  $v0, $s6, $t0
  lwc1  $f14, 8($v0)
  c.le.s $f14, $f22
  nop   
  bc1tl .L7F0B57B4
   sub.s $f6, $f14, $f16
  c.le.s $f16, $f22
.L7F0B5784:
  nop   
  bc1fl .L7F0B581C
   slt   $at, $a1, $a0
  multu $v1, $a2
  mflo  $t1
  addu  $v0, $s6, $t1
  lwc1  $f14, 8($v0)
  c.lt.s $f22, $f14
  nop   
  bc1fl .L7F0B581C
   slt   $at, $a1, $a0
  sub.s $f6, $f14, $f16
.L7F0B57B4:
  lwc1  $f0, ($s0)
  lwc1  $f10, ($v0)
  neg.s $f4, $f16
  multu $a3, $a2
  div.s $f12, $f4, $f6
  lui   $t3, %hi(ptr_bgdata_portals) 
  addiu $a3, $a3, 1
  sub.s $f8, $f10, $f0
  mflo  $t2
  addu  $v1, $s6, $t2
  addiu $v1, $v1, 0xc
  mul.s $f18, $f8, $f12
  add.s $f4, $f18, $f0
  swc1  $f4, -0xc($v1)
  lwc1  $f6, 4($v0)
  lwc1  $f2, 4($s0)
  swc1  $f22, -4($v1)
  sub.s $f10, $f6, $f2
  mul.s $f8, $f10, $f12
  add.s $f18, $f8, $f2
  swc1  $f18, -8($v1)
  lw    $t3, %lo(ptr_bgdata_portals)($t3)
  addu  $t4, $t3, $s5
  lw    $t5, ($t4)
  lbu   $a0, ($t5)
  slt   $at, $a1, $a0
.L7F0B581C:
  bnez  $at, .L7F0B571C
   addiu $s0, $s0, 0xc
.L7F0B5824:
  move  $v0, $a3
.L7F0B5828:
  lw    $ra, 0x54($sp)
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
  lw    $s7, 0x4c($sp)
  lw    $fp, 0x50($sp)
  jr    $ra
   addiu $sp, $sp, 0xb0
");

asm(R"
glabel sub_GAME_7F0B5864
  addiu $sp, $sp, -0x170
  sll   $t6, $a0, 2
  addu  $t6, $t6, $a0
  lui   $t7, %hi(table_for_portals) 
  sw    $s5, 0x3c($sp)
  addiu $t7, %lo(table_for_portals) # addiu $t7, $t7, 0x1618
  sll   $t6, $t6, 2
  addu  $s5, $t6, $t7
  lw    $t8, ($s5)
  sw    $s6, 0x40($sp)
  sw    $s0, 0x28($sp)
  move  $s0, $a0
  move  $s6, $a1
  sw    $ra, 0x44($sp)
  sw    $s4, 0x38($sp)
  sw    $s3, 0x34($sp)
  sw    $s2, 0x30($sp)
  sw    $s1, 0x2c($sp)
  sdc1  $f22, 0x20($sp)
  bltz  $t8, .L7F0B58E0
   sdc1  $f20, 0x18($sp)
  lwc1  $f4, 4($s5)
  swc1  $f4, ($a1)
  lwc1  $f6, 8($s5)
  swc1  $f6, 4($a1)
  lwc1  $f8, 0xc($s5)
  swc1  $f8, 8($a1)
  lwc1  $f10, 0x10($s5)
  swc1  $f10, 0xc($a1)
  b     .L7F0B5AE4
   lw    $v0, ($s5)
.L7F0B58E0:
  jal   sub_GAME_7F0B9990
   move  $a0, $s0
  addiu $s1, $sp, 0x80
  mfc1  $a1, $f0
  mov.s $f22, $f0
  move  $a2, $s1
  jal   sub_GAME_7F0B5528
   move  $a0, $s0
  mtc1  $zero, $f20
  sll   $t9, $v0, 2
  move  $s3, $v0
  c.lt.s $f20, $f22
  subu  $t9, $t9, $v0
  move  $a0, $s0
  bc1fl .L7F0B593C
   move  $s2, $zero
  neg.s $f4, $f22
  sll   $t9, $t9, 2
  mfc1  $a1, $f4
  jal   sub_GAME_7F0B5528
   addu  $a2, $s1, $t9
  addu  $s3, $s3, $v0
  move  $s2, $zero
.L7F0B593C:
  blez  $s3, .L7F0B5A24
   move  $s1, $zero
  addiu $s0, $sp, 0x80
  addiu $s4, $sp, 0x78
.L7F0B594C:
  lwc1  $f6, 8($s0)
  lwc1  $f14, 0x74($sp)
  lwc1  $f16, 0x6c($sp)
  c.le.s $f6, $f20
  lwc1  $f18, 0x70($sp)
  lwc1  $f22, 0x68($sp)
  move  $a0, $s0
  bc1fl .L7F0B59FC
   addiu $s1, $s1, 1
  jal   sub_GAME_7F078060
   move  $a1, $s4
  bnez  $s2, .L7F0B5994
   lwc1  $f2, 0x78($sp)
  lwc1  $f22, 0x78($sp)
  lwc1  $f16, 0x7c($sp)
  mov.s $f18, $f22
  b     .L7F0B59F4
   mov.s $f14, $f16
.L7F0B5994:
  lwc1  $f22, 0x68($sp)
  lwc1  $f18, 0x70($sp)
  lwc1  $f12, 0x7c($sp)
  c.lt.s $f2, $f22
  lwc1  $f16, 0x6c($sp)
  lwc1  $f14, 0x74($sp)
  bc1fl .L7F0B59BC
   c.lt.s $f18, $f2
  mov.s $f22, $f2
  c.lt.s $f18, $f2
.L7F0B59BC:
  nop   
  bc1fl .L7F0B59D0
   c.lt.s $f12, $f16
  mov.s $f18, $f2
  c.lt.s $f12, $f16
.L7F0B59D0:
  nop   
  bc1fl .L7F0B59E4
   c.lt.s $f14, $f12
  mov.s $f16, $f12
  c.lt.s $f14, $f12
.L7F0B59E4:
  nop   
  bc1fl .L7F0B59F8
   addiu $s2, $s2, 1
  mov.s $f14, $f12
.L7F0B59F4:
  addiu $s2, $s2, 1
.L7F0B59F8:
  addiu $s1, $s1, 1
.L7F0B59FC:
  addiu $s0, $s0, 0xc
  swc1  $f14, 0x74($sp)
  swc1  $f16, 0x6c($sp)
  swc1  $f18, 0x70($sp)
  bne   $s1, $s3, .L7F0B594C
   swc1  $f22, 0x68($sp)
  swc1  $f14, 0x74($sp)
  swc1  $f16, 0x6c($sp)
  swc1  $f18, 0x70($sp)
  swc1  $f22, 0x68($sp)
.L7F0B5A24:
  lwc1  $f14, 0x74($sp)
  lwc1  $f16, 0x6c($sp)
  lwc1  $f18, 0x70($sp)
  bnez  $s2, .L7F0B5A4C
   lwc1  $f22, 0x68($sp)
  swc1  $f20, 0x74($sp)
  swc1  $f20, 0x6c($sp)
  swc1  $f20, 0x70($sp)
  b     .L7F0B5A9C
   swc1  $f20, 0x68($sp)
.L7F0B5A4C:
  c.le.s $f18, $f22
  swc1  $f14, 0x74($sp)
  swc1  $f16, 0x6c($sp)
  swc1  $f18, 0x70($sp)
  bc1t  .L7F0B5A74
   swc1  $f22, 0x68($sp)
  c.le.s $f14, $f16
  swc1  $f14, 0x74($sp)
  swc1  $f16, 0x6c($sp)
  bc1f  .L7F0B5A9C
.L7F0B5A74:
   lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lwc1  $f8, 0x1118($v0)
  swc1  $f8, 0x68($sp)
  lwc1  $f10, 0x111c($v0)
  swc1  $f10, 0x6c($sp)
  lwc1  $f4, 0x1120($v0)
  swc1  $f4, 0x70($sp)
  lwc1  $f6, 0x1124($v0)
  swc1  $f6, 0x74($sp)
.L7F0B5A9C:
  lwc1  $f8, 0x68($sp)
  move  $v0, $s2
  swc1  $f8, ($s6)
  lwc1  $f10, 0x6c($sp)
  lwc1  $f8, ($s6)
  swc1  $f10, 4($s6)
  lwc1  $f4, 0x70($sp)
  swc1  $f4, 8($s6)
  lwc1  $f6, 0x74($sp)
  swc1  $f6, 0xc($s6)
  swc1  $f8, 4($s5)
  lwc1  $f10, 4($s6)
  swc1  $f10, 8($s5)
  lwc1  $f4, 8($s6)
  swc1  $f4, 0xc($s5)
  lwc1  $f6, 0xc($s6)
  sw    $s2, ($s5)
  swc1  $f6, 0x10($s5)
.L7F0B5AE4:
  lw    $ra, 0x44($sp)
  ldc1  $f20, 0x18($sp)
  ldc1  $f22, 0x20($sp)
  lw    $s0, 0x28($sp)
  lw    $s1, 0x2c($sp)
  lw    $s2, 0x30($sp)
  lw    $s3, 0x34($sp)
  lw    $s4, 0x38($sp)
  lw    $s5, 0x3c($sp)
  lw    $s6, 0x40($sp)
  jr    $ra
   addiu $sp, $sp, 0x170
");

asm(R"
glabel sub_GAME_7F0B5B14
  lw    $t0, 0x10($sp)
  addiu $t6, $a3, 1
  andi  $t7, $t6, 0x3ff
  sll   $t8, $t7, 0xe
  lui   $at, 0xf600
  addiu $t1, $t0, 1
  andi  $t2, $t1, 0x3ff
  or    $t9, $t8, $at
  andi  $t7, $a2, 0x3ff
  andi  $t5, $a1, 0x3ff
  sll   $t6, $t5, 0xe
  sll   $t8, $t7, 2
  sll   $t3, $t2, 2
  or    $t4, $t9, $t3
  or    $t0, $t6, $t8
  sw    $t0, 4($a0)
  sw    $t4, ($a0)
  jr    $ra
   addiu $v0, $a0, 8
");

asm(R"
glabel sub_GAME_7F0B5B60
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $a1, 0x24($sp)
  sw    $a3, 0x2c($sp)
  sw    $a2, 0x10($sp)
  jal   sub_GAME_7F0B5B14
   sw    $a2, 0x28($sp)
  lw    $a1, 0x2c($sp)
  lw    $t6, 0x30($sp)
  move  $a0, $v0
  lw    $a2, 0x28($sp)
  move  $a3, $a1
  jal   sub_GAME_7F0B5B14
   sw    $t6, 0x10($sp)
  lw    $a2, 0x30($sp)
  move  $a0, $v0
  lw    $a1, 0x24($sp)
  lw    $a3, 0x2c($sp)
  jal   sub_GAME_7F0B5B14
   sw    $a2, 0x10($sp)
  lw    $a3, 0x24($sp)
  lw    $t8, 0x30($sp)
  move  $a0, $v0
  lw    $a2, 0x28($sp)
  move  $a1, $a3
  jal   sub_GAME_7F0B5B14
   sw    $t8, 0x10($sp)
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel vis_is_inline_of_sight
  lwc1  $f0, ($a1)
  lwc1  $f2, ($a0)
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F0B5C00
   swc1  $f0, ($a0)
  b     .L7F0B5C00
   swc1  $f2, ($a0)
  swc1  $f0, ($a0)
.L7F0B5C00:
  lwc1  $f0, 4($a1)
  lwc1  $f2, 4($a0)
  move  $v0, $zero
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F0B5C28
   swc1  $f0, 4($a0)
  b     .L7F0B5C28
   swc1  $f2, 4($a0)
  swc1  $f0, 4($a0)
.L7F0B5C28:
  lwc1  $f0, 8($a0)
  lwc1  $f2, 8($a1)
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F0B5C4C
   swc1  $f2, 8($a0)
  b     .L7F0B5C4C
   swc1  $f0, 8($a0)
  swc1  $f2, 8($a0)
.L7F0B5C4C:
  lwc1  $f0, 0xc($a0)
  lwc1  $f2, 0xc($a1)
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F0B5C70
   swc1  $f2, 0xc($a0)
  b     .L7F0B5C70
   swc1  $f0, 0xc($a0)
  swc1  $f2, 0xc($a0)
.L7F0B5C70:
  lwc1  $f0, 8($a0)
  lwc1  $f4, ($a0)
  c.le.s $f0, $f4
  nop   
  bc1fl .L7F0B5C94
   lwc1  $f0, 0xc($a0)
  jr    $ra
   swc1  $f0, ($a0)

  lwc1  $f0, 0xc($a0)
.L7F0B5C94:
  lwc1  $f6, 4($a0)
  li    $v0, 1
  c.le.s $f0, $f6
  nop   
  bc1f  .L7F0B5CB8
   nop   
  swc1  $f0, 4($a0)
  jr    $ra
   move  $v0, $zero

.L7F0B5CB8:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B5CC0
  lwc1  $f0, ($a0)
  lwc1  $f2, ($a1)
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F0B5CE4
   swc1  $f2, ($a0)
  b     .L7F0B5CE4
   swc1  $f0, ($a0)
  swc1  $f2, ($a0)
.L7F0B5CE4:
  lwc1  $f0, 4($a0)
  lwc1  $f2, 4($a1)
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F0B5D08
   swc1  $f2, 4($a0)
  b     .L7F0B5D08
   swc1  $f0, 4($a0)
  swc1  $f2, 4($a0)
.L7F0B5D08:
  lwc1  $f0, 8($a1)
  lwc1  $f2, 8($a0)
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F0B5D2C
   swc1  $f0, 8($a0)
  b     .L7F0B5D2C
   swc1  $f2, 8($a0)
  swc1  $f0, 8($a0)
.L7F0B5D2C:
  lwc1  $f0, 0xc($a1)
  lwc1  $f2, 0xc($a0)
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F0B5D50
   swc1  $f0, 0xc($a0)
  jr    $ra
   swc1  $f2, 0xc($a0)

  swc1  $f0, 0xc($a0)
.L7F0B5D50:
  jr    $ra
   nop   
");

asm(R"
glabel copy_4_floats_a1_to_a0
  lwc1  $f4, ($a1)
  swc1  $f4, ($a0)
  lwc1  $f6, 4($a1)
  swc1  $f6, 4($a0)
  lwc1  $f8, 8($a1)
  swc1  $f8, 8($a0)
  lwc1  $f10, 0xc($a1)
  jr    $ra
   swc1  $f10, 0xc($a0)
");

const char aPortD[] = "PORT%d";

asm(R"
glabel sub_GAME_7F0B5D7C
  lui   $v0, %hi(D_80044860)
  lw    $v0, %lo(D_80044860)($v0)
  li    $at, 10
  lui   $t8, %hi(dword_CODE_bss_8007C040) 
  addiu $v0, $v0, 1
  div   $zero, $v0, $at
  mfhi  $t6
  sll   $t7, $t6, 3
  addiu $sp, $sp, -0x20
  move  $a2, $a0
  addu  $t7, $t7, $t6
  addiu $t8, %lo(dword_CODE_bss_8007C040) # addiu $t8, $t8, -0x3fc0
  sw    $ra, 0x14($sp)
  addu  $a0, $t7, $t8
  lui   $at, %hi(D_80044860)
  lui   $a1, %hi(aPortD)
  sw    $a0, 0x1c($sp)
  addiu $a1, %lo(aPortD) # addiu $a1, $a1, -0x73b8
  jal   sprintf
   sw    $t6, %lo(D_80044860)($at)
  lw    $ra, 0x14($sp)
  lw    $v0, 0x1c($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

const char aRoomD[] = "ROOM%d";
asm(R"
glabel sub_GAME_7F0B5DE0
  lui   $v0, %hi(D_80044864)
  lw    $v0, %lo(D_80044864)($v0)
  li    $at, 10
  lui   $t8, %hi(dword_CODE_bss_8007C0A0) 
  addiu $v0, $v0, 1
  div   $zero, $v0, $at
  mfhi  $t6
  sll   $t7, $t6, 3
  addiu $sp, $sp, -0x20
  move  $a2, $a0
  addu  $t7, $t7, $t6
  addiu $t8, %lo(dword_CODE_bss_8007C0A0) # addiu $t8, $t8, -0x3f60
  sw    $ra, 0x14($sp)
  addu  $a0, $t7, $t8
  lui   $at, %hi(D_80044864)
  lui   $a1, %hi(aRoomD)
  sw    $a0, 0x1c($sp)
  addiu $a1, %lo(aRoomD) # addiu $a1, $a1, -0x73b0
  jal   sprintf
   sw    $t6, %lo(D_80044864)($at)
  lw    $ra, 0x14($sp)
  lw    $v0, 0x1c($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

int getMaxNumRooms(void) { return MaxNumRooms; }

asm(R"
glabel sub_GAME_7F0B5E50
  sll   $t6, $a0, 2
  addu  $t6, $t6, $a0
  sll   $t6, $t6, 4
  lui   $v0, %hi(array_room_info)
  addu  $v0, $v0, $t6
  jr    $ra
   lbu   $v0, %lo(array_room_info)($v0)
");

asm(R"
glabel sub_GAME_7F0B5E6C
  sll   $t6, $a0, 2
  addu  $t6, $t6, $a0
  sll   $t6, $t6, 4
  lui   $v0, %hi(array_room_info+0x1)
  addu  $v0, $v0, $t6
  jr    $ra
   lbu   $v0, %lo(array_room_info+0x1)($v0)
");

asm(R"
glabel sub_GAME_7F0B5E88
  lui   $v0, %hi(ptr_bgdata_portals)
  lw    $v0, %lo(ptr_bgdata_portals)($v0)
  move  $v1, $zero
  lw    $t6, ($v0)
  move  $a1, $v0
  beql  $t6, $zero, .L7F0B5ED0
   move  $v0, $zero
  lw    $a2, ($v0)
.L7F0B5EA8:
  bnel  $a0, $a2, .L7F0B5EBC
   lw    $a2, 8($a1)
  jr    $ra
   move  $v0, $v1

  lw    $a2, 8($a1)
.L7F0B5EBC:
  addiu $v1, $v1, 1
  addiu $a1, $a1, 8
  bnez  $a2, .L7F0B5EA8
   nop   
  move  $v0, $zero
.L7F0B5ED0:
  jr    $ra
   nop   
");

asm(R"
glabel generate_room_load_string
  addiu $sp, $sp, -0xc0
  sw    $ra, 0x14($sp)
  jal   get_debug_prroomloads_flag
   nop   
  beqz  $v0, .L7F0B5F7C
   lui   $a3, %hi(MaxNumRooms)
  lw    $a3, %lo(MaxNumRooms)($a3)
  lui   $v1, %hi(array_room_info + 0x10 +0x40)
  addiu $v1, %lo(array_room_info + 0x10 +0x40) # addiu $v1, $v1, 0x1464
  slti  $at, $a3, 2
  bnez  $at, .L7F0B5F74
   li    $a0, 1
  addiu $v0, $sp, 0x29
  li    $a2, 46
  li    $a1, 10
.L7F0B5F14:
  lbu   $t6, 2($v1)
  addiu $v1, $v1, 0x50
  beql  $t6, $zero, .L7F0B5F64
   sb    $a2, ($v0)
  div   $zero, $a0, $a1
  mfhi  $t7
  addiu $t8, $t7, 0x30
  bnez  $a1, .L7F0B5F3C
   nop   
  break 7
.L7F0B5F3C:
  li    $at, -1
  bne   $a1, $at, .L7F0B5F54
   lui   $at, 0x8000
  bne   $a0, $at, .L7F0B5F54
   nop   
  break 6
.L7F0B5F54:
  sb    $t8, ($v0)
  b     .L7F0B5F68
   addiu $a0, $a0, 1
  sb    $a2, ($v0)
.L7F0B5F64:
  addiu $a0, $a0, 1
.L7F0B5F68:
  slt   $at, $a0, $a3
  bnez  $at, .L7F0B5F14
   addiu $v0, $v0, 1
.L7F0B5F74:
  addu  $t9, $sp, $a0
  sb    $zero, 0x28($t9)
.L7F0B5F7C:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0xc0
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B5F8C
  addiu $sp, $sp, -0x2118
  sw    $ra, 0x14($sp)
  jal   decompressdata
   addiu $a2, $sp, 0x18
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x2118
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B5FAC
  sll   $t7, $a0, 2
  addu  $t7, $t7, $a0
  lui   $t8, %hi(array_room_info) 
  addiu $t8, %lo(array_room_info) # addiu $t8, $t8, 0x1414
  sll   $t7, $t7, 4
  addu  $v1, $t7, $t8
  lw    $a3, 0x10($v1)
  li    $at, -16
  addiu $sp, $sp, -0x30
  addiu $a3, $a3, 0xf
  and   $t9, $a3, $at
  addiu $t2, $t9, 0x20
  slt   $at, $a2, $t2
  sw    $ra, 0x14($sp)
  sw    $a0, 0x30($sp)
  sw    $a1, 0x34($sp)
  sw    $a2, 0x38($sp)
  beqz  $at, .L7F0B6000
   move  $a3, $t9
  b     .L7F0B608C
   li    $v0, -1
.L7F0B6000:
  lw    $t4, 0x30($sp)
  li    $t0, 24
  lui   $t9, %hi(D_80041400) 
  multu $t4, $t0
  lw    $t9, %lo(D_80041400)($t9)
  lui   $t3, %hi(ptr_bgdata_room_fileposition_list) 
  lw    $t3, %lo(ptr_bgdata_room_fileposition_list)($t3)
  lui   $v0, %hi(ptr_bg_data)
  lw    $v0, %lo(ptr_bg_data)($v0)
  lw    $t2, 0x38($sp)
  lui   $a0, %hi(levelinfotable)
  lui   $at, 0xf100
  subu  $t4, $t2, $a3
  mflo  $t5
  addu  $t6, $t3, $t5
  lw    $t7, ($t6)
  multu $t9, $t0
  lw    $t3, 0x34($sp)
  addu  $t8, $t7, $v0
  subu  $a2, $t8, $v0
  addu  $a1, $t4, $t3
  addu  $a2, $a2, $at
  sw    $a1, 0x18($sp)
  sw    $v1, 0x1c($sp)
  mflo  $t1
  addu  $a0, $a0, $t1
  jal   obLoadBGFileBytesAtOffset
   lw    $a0, %lo(levelinfotable+4)($a0)
  lw    $a0, 0x18($sp)
  jal   sub_GAME_7F0B5F8C
   lw    $a1, 0x34($sp)
  lw    $v1, 0x1c($sp)
  lw    $t5, 0x34($sp)
  sw    $v0, 0x1c($v1)
  sw    $t5, 4($v1)
.L7F0B608C:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B609C
  sll   $t7, $a0, 2
  addu  $t7, $t7, $a0
  lui   $t8, %hi(array_room_info) 
  addiu $t8, %lo(array_room_info) # addiu $t8, $t8, 0x1414
  sll   $t7, $t7, 4
  addu  $t0, $t7, $t8
  lw    $a3, 0x14($t0)
  addiu $sp, $sp, -0x38
  li    $at, -16
  addiu $a3, $a3, 0xf
  and   $t9, $a3, $at
  addiu $t2, $t9, 0x20
  sw    $s0, 0x14($sp)
  slt   $at, $a2, $t2
  move  $s0, $a1
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $a0, 0x38($sp)
  sw    $a2, 0x40($sp)
  beqz  $at, .L7F0B60F8
   move  $a3, $t9
  b     .L7F0B61C8
   li    $v0, -1
.L7F0B60F8:
  lw    $t4, 0x38($sp)
  li    $v1, 24
  lui   $t9, %hi(D_80041400) 
  multu $t4, $v1
  lw    $t9, %lo(D_80041400)($t9)
  lui   $t3, %hi(ptr_bgdata_room_fileposition_list) 
  lw    $t3, %lo(ptr_bgdata_room_fileposition_list)($t3)
  lui   $v0, %hi(ptr_bg_data)
  lw    $v0, %lo(ptr_bg_data)($v0)
  lw    $t2, 0x40($sp)
  lui   $a0, %hi(levelinfotable)
  lui   $at, 0xf100
  subu  $t4, $t2, $a3
  mflo  $t5
  addu  $t6, $t3, $t5
  lw    $t7, 4($t6)
  multu $t9, $v1
  addu  $s1, $t4, $s0
  addu  $t8, $t7, $v0
  subu  $a2, $t8, $v0
  addu  $a2, $a2, $at
  move  $a1, $s1
  sw    $t0, 0x20($sp)
  mflo  $t1
  addu  $a0, $a0, $t1
  jal   obLoadBGFileBytesAtOffset
   lw    $a0, %lo(levelinfotable+4)($a0)
  move  $a0, $s1
  jal   sub_GAME_7F0B5F8C
   move  $a1, $s0
  lw    $t3, 0x40($sp)
  move  $s1, $v0
  move  $a0, $s0
  subu  $t5, $t3, $v0
  addu  $a1, $t5, $s0
  sw    $a1, 0x28($sp)
  jal   sub_GAME_7F0CE794
   move  $a2, $v0
  jal   sub_GAME_7F0BC4C4
   lw    $a0, 0x38($sp)
  lw    $a0, 0x28($sp)
  move  $a1, $s1
  move  $a2, $s0
  jal   process_microcode_sort_display_modes_expand_image_calls
   move  $a3, $zero
  slt   $at, $s1, $v0
  beqz  $at, .L7F0B61BC
   lw    $v1, 0x20($sp)
  move  $s1, $v0
.L7F0B61BC:
  sw    $s0, 8($v1)
  sw    $s1, 0x20($v1)
  move  $v0, $s1
.L7F0B61C8:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x38
");

asm(R"
glabel sub_GAME_7F0B61DC
  sll   $t7, $a0, 2
  addu  $t7, $t7, $a0
  lui   $t8, %hi(array_room_info) 
  addiu $t8, %lo(array_room_info) # addiu $t8, $t8, 0x1414
  sll   $t7, $t7, 4
  addu  $t0, $t7, $t8
  lw    $a3, 0x18($t0)
  addiu $sp, $sp, -0x38
  li    $at, -16
  addiu $a3, $a3, 0xf
  and   $t9, $a3, $at
  addiu $t2, $t9, 0x20
  sw    $s1, 0x18($sp)
  slt   $at, $a2, $t2
  move  $s1, $a1
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x14($sp)
  sw    $a0, 0x38($sp)
  sw    $a2, 0x40($sp)
  beqz  $at, .L7F0B6238
   move  $a3, $t9
  b     .L7F0B6300
   li    $v0, -1
.L7F0B6238:
  lw    $t4, 0x38($sp)
  li    $v1, 24
  lui   $t9, %hi(D_80041400) 
  multu $t4, $v1
  lw    $t9, %lo(D_80041400)($t9)
  lui   $t3, %hi(ptr_bgdata_room_fileposition_list) 
  lw    $t3, %lo(ptr_bgdata_room_fileposition_list)($t3)
  lui   $v0, %hi(ptr_bg_data)
  lw    $v0, %lo(ptr_bg_data)($v0)
  lw    $t2, 0x40($sp)
  lui   $a0, %hi(levelinfotable)
  lui   $at, 0xf100
  subu  $t4, $t2, $a3
  mflo  $t5
  addu  $t6, $t3, $t5
  lw    $t7, 8($t6)
  multu $t9, $v1
  addu  $s0, $t4, $s1
  addu  $t8, $t7, $v0
  subu  $a2, $t8, $v0
  addu  $a2, $a2, $at
  move  $a1, $s0
  sw    $t0, 0x20($sp)
  mflo  $t1
  addu  $a0, $a0, $t1
  jal   obLoadBGFileBytesAtOffset
   lw    $a0, %lo(levelinfotable+4)($a0)
  move  $a0, $s0
  jal   sub_GAME_7F0B5F8C
   move  $a1, $s1
  lw    $t3, 0x40($sp)
  move  $s0, $v0
  move  $a0, $s1
  subu  $t5, $t3, $v0
  addu  $a1, $t5, $s1
  sw    $a1, 0x28($sp)
  jal   sub_GAME_7F0CE794
   move  $a2, $v0
  lw    $a0, 0x28($sp)
  move  $a1, $s0
  move  $a2, $s1
  jal   process_microcode_sort_display_modes_expand_image_calls
   move  $a3, $zero
  slt   $at, $s0, $v0
  beqz  $at, .L7F0B62F4
   lw    $v1, 0x20($sp)
  move  $s0, $v0
.L7F0B62F4:
  sw    $s1, 0xc($v1)
  sw    $s0, 0x24($v1)
  move  $v0, $s0
.L7F0B6300:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x38
");

asm(R"
glabel sub_GAME_7F0B6314
  sll   $t6, $a0, 2
  addu  $t6, $t6, $a0
  lui   $t7, %hi(array_room_info) 
  addiu $t7, %lo(array_room_info) # addiu $t7, $t7, 0x1414
  sll   $t6, $t6, 4
  addu  $v0, $t6, $t7
  lbu   $t9, 2($v0)
  addiu $sp, $sp, -0x18
  li    $t8, 1
  sw    $ra, 0x14($sp)
  bnez  $t9, .L7F0B6354
   sb    $t8, 0x35($v0)
  jal   sub_GAME_7F0B6368
   nop   
  b     .L7F0B6358
   li    $v0, 1
.L7F0B6354:
  move  $v0, $zero
.L7F0B6358:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B6368
  lui   $t7, %hi(MaxNumRooms) 
  lw    $t7, %lo(MaxNumRooms)($t7)
  addiu $sp, $sp, -0x30
  sw    $ra, 0x14($sp)
  slt   $at, $a0, $t7
  sw    $a0, 0x30($sp)
  beqz  $at, .L7F0B65B4
   move  $a3, $zero
  sll   $t9, $a0, 2
  addu  $t9, $t9, $a0
  lui   $t0, %hi(array_room_info) 
  addiu $t0, %lo(array_room_info) # addiu $t0, $t0, 0x1414
  sll   $t9, $t9, 4
  addu  $v1, $t9, $t0
  lbu   $t1, 2($v1)
  bnezl $t1, .L7F0B65B8
   lw    $ra, 0x14($sp)
  lw    $v0, 0x28($v1)
  blezl $v0, .L7F0B63E8
   sw    $v1, 0x1c($sp)
  sw    $v0, 0x2c($sp)
  sw    $v1, 0x1c($sp)
  jal   get_debug_joy2detailedit_flag
   sw    $zero, 0x28($sp)
  lw    $v1, 0x1c($sp)
  beqz  $v0, .L7F0B63FC
   lw    $a3, 0x28($sp)
  lw    $t2, 0x2c($sp)
  addiu $t3, $t2, 0x400
  b     .L7F0B63FC
   sw    $t3, 0x2c($sp)
  sw    $v1, 0x1c($sp)
.L7F0B63E8:
  jal   mem_related_0
   sw    $a3, 0x28($sp)
  lw    $v1, 0x1c($sp)
  lw    $a3, 0x28($sp)
  sw    $v0, 0x2c($sp)
.L7F0B63FC:
  lw    $a0, 0x2c($sp)
  sw    $v1, 0x1c($sp)
  jal   mem_related_something_find_first
   sw    $a3, 0x28($sp)
  lw    $v1, 0x1c($sp)
  lw    $a3, 0x28($sp)
  beqz  $v0, .L7F0B65B4
   sw    $v0, 0x20($sp)
  lw    $t4, 0x10($v1)
  lw    $a0, 0x30($sp)
  move  $a1, $v0
  beqz  $t4, .L7F0B6464
   lw    $a2, 0x2c($sp)
  sw    $v1, 0x1c($sp)
  jal   sub_GAME_7F0B5FAC
   sw    $a3, 0x28($sp)
  lw    $v1, 0x1c($sp)
  bltz  $v0, .L7F0B646C
   lw    $a3, 0x28($sp)
  lw    $a0, 0x30($sp)
  sw    $v1, 0x1c($sp)
  jal   sub_GAME_7F0BB978
   sw    $v0, 0x28($sp)
  lw    $v1, 0x1c($sp)
  b     .L7F0B646C
   lw    $a3, 0x28($sp)
.L7F0B6464:
  sw    $zero, 4($v1)
  sw    $zero, 0x1c($v1)
.L7F0B646C:
  lw    $t5, 0x14($v1)
  lw    $t6, 0x20($sp)
  lw    $a0, 0x30($sp)
  beqz  $t5, .L7F0B64A4
   addu  $a1, $t6, $a3
  lw    $t7, 0x2c($sp)
  sw    $v1, 0x1c($sp)
  sw    $a3, 0x28($sp)
  jal   sub_GAME_7F0B609C
   subu  $a2, $t7, $a3
  lw    $v1, 0x1c($sp)
  bltz  $v0, .L7F0B64A4
   lw    $a3, 0x28($sp)
  addu  $a3, $a3, $v0
.L7F0B64A4:
  lw    $t8, 0x18($v1)
  lw    $t9, 0x20($sp)
  lw    $a0, 0x30($sp)
  beqz  $t8, .L7F0B64E0
   addu  $a1, $t9, $a3
  lw    $t0, 0x2c($sp)
  sw    $v1, 0x1c($sp)
  sw    $a3, 0x28($sp)
  jal   sub_GAME_7F0B61DC
   subu  $a2, $t0, $a3
  lw    $v1, 0x1c($sp)
  blez  $v0, .L7F0B64E4
   lw    $a3, 0x28($sp)
  b     .L7F0B64E4
   addu  $a3, $a3, $v0
.L7F0B64E0:
  sw    $zero, 0xc($v1)
.L7F0B64E4:
  lw    $t3, 0x2c($sp)
  addiu $v0, $a3, 0x20
  li    $at, -16
  and   $t1, $v0, $at
  li    $t2, 1
  sw    $t1, 0x28($v1)
  beq   $t3, $t1, .L7F0B651C
   sb    $t2, 2($v1)
  lw    $a0, 0x20($sp)
  move  $a1, $t3
  move  $a2, $t1
  jal   mem_related_1
   sw    $v1, 0x1c($sp)
  lw    $v1, 0x1c($sp)
.L7F0B651C:
  lui   $t4, %hi(sky_enabled) 
  lw    $t4, %lo(sky_enabled)($t4)
  li    $a2, 6
  beql  $t4, $zero, .L7F0B6574
   lw    $a0, 8($v1)
  lw    $a0, 8($v1)
  lw    $t5, 0x20($v1)
  li    $a2, 1
  sw    $v1, 0x1c($sp)
  jal   sub_GAME_7F0BA640
   addu  $a1, $t5, $a0
  lw    $v1, 0x1c($sp)
  lw    $a0, 0xc($v1)
  beqz  $a0, .L7F0B65A4
   nop   
  lw    $t6, 0x24($v1)
  li    $a2, 5
  jal   sub_GAME_7F0BA640
   addu  $a1, $t6, $a0
  b     .L7F0B65A4
   nop   
  lw    $a0, 8($v1)
.L7F0B6574:
  lw    $t7, 0x20($v1)
  sw    $v1, 0x1c($sp)
  jal   sub_GAME_7F0BA640
   addu  $a1, $t7, $a0
  lw    $v1, 0x1c($sp)
  lw    $a0, 0xc($v1)
  beqz  $a0, .L7F0B65A4
   nop   
  lw    $t8, 0x24($v1)
  li    $a2, 7
  jal   sub_GAME_7F0BA640
   addu  $a1, $t8, $a0
.L7F0B65A4:
  jal   sub_GAME_7F0B6994
   lw    $a0, 0x30($sp)
  jal   generate_room_load_string
   nop   
.L7F0B65B4:
  lw    $ra, 0x14($sp)
.L7F0B65B8:
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B65C4
  sll   $t6, $a0, 2
  addiu $sp, $sp, -0x20
  addu  $t6, $t6, $a0
  lui   $t7, %hi(array_room_info) 
  sw    $s0, 0x18($sp)
  addiu $t7, %lo(array_room_info) # addiu $t7, $t7, 0x1414
  sll   $t6, $t6, 4
  addu  $s0, $t6, $t7
  lw    $a2, 0x2c($s0)
  sw    $ra, 0x1c($sp)
  beql  $a2, $zero, .L7F0B6624
   lw    $v0, 0x28($s0)
  lh    $a1, 0x30($s0)
  li    $at, -16
  move  $a0, $a2
  sll   $t8, $a1, 3
  subu  $t8, $t8, $a1
  sll   $t8, $t8, 2
  addiu $a1, $t8, 0xf
  and   $t9, $a1, $at
  jal   mem_related_model_room_buffers_0
   move  $a1, $t9
  sw    $zero, 0x2c($s0)
  lw    $v0, 0x28($s0)
.L7F0B6624:
  blez  $v0, .L7F0B6660
   nop   
  lw    $a0, 4($s0)
  move  $a1, $v0
  beqz  $a0, .L7F0B664C
   nop   
  jal   mem_related_model_room_buffers_0
   move  $a1, $v0
  b     .L7F0B6658
   sw    $zero, 4($s0)
.L7F0B664C:
  jal   mem_related_model_room_buffers_0
   lw    $a0, 8($s0)
  sw    $zero, 4($s0)
.L7F0B6658:
  sw    $zero, 8($s0)
  sw    $zero, 0xc($s0)
.L7F0B6660:
  jal   generate_room_load_string
   sb    $zero, 2($s0)
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B667C
  lui   $v0, %hi(MaxNumRooms)
  lw    $v0, %lo(MaxNumRooms)($v0)
  addiu $sp, $sp, -0x20
  sw    $s1, 0x18($sp)
  slti  $at, $v0, 2
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x14($sp)
  bnez  $at, .L7F0B66D4
   li    $s1, 1
  lui   $s0, %hi(array_room_info + 0x10 +0x40)
  addiu $s0, %lo(array_room_info + 0x10 +0x40) # addiu $s0, $s0, 0x1464
.L7F0B66A8:
  lbu   $t6, 2($s0)
  beql  $t6, $zero, .L7F0B66C8
   addiu $s1, $s1, 1
  jal   sub_GAME_7F0B65C4
   move  $a0, $s1
  lui   $v0, %hi(MaxNumRooms)
  lw    $v0, %lo(MaxNumRooms)($v0)
  addiu $s1, $s1, 1
.L7F0B66C8:
  slt   $at, $s1, $v0
  bnez  $at, .L7F0B66A8
   addiu $s0, $s0, 0x50
.L7F0B66D4:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x20
");

asm(R"
glabel sub_GAME_7F0B66E8
  lui   $v1, %hi(MaxNumRooms)
  lw    $v1, %lo(MaxNumRooms)($v1)
  addiu $sp, $sp, -0x28
  sw    $s1, 0x1c($sp)
  slti  $at, $v1, 2
  sw    $ra, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s0, 0x18($sp)
  bnez  $at, .L7F0B6764
   li    $s1, 1
  lui   $s0, %hi(array_room_info + 0x10 +0x40)
  addiu $s0, %lo(array_room_info + 0x10 +0x40) # addiu $s0, $s0, 0x1464
  li    $s2, 4
.L7F0B671C:
  lbu   $t6, 0x35($s0)
  bnezl $t6, .L7F0B6758
   addiu $s1, $s1, 1
  lbu   $v0, 2($s0)
  bne   $s2, $v0, .L7F0B6748
   nop   
  jal   sub_GAME_7F0B65C4
   move  $a0, $s1
  lui   $v1, %hi(MaxNumRooms)
  b     .L7F0B6754
   lw    $v1, %lo(MaxNumRooms)($v1)
.L7F0B6748:
  beqz  $v0, .L7F0B6754
   addiu $t7, $v0, 1
  sb    $t7, 2($s0)
.L7F0B6754:
  addiu $s1, $s1, 1
.L7F0B6758:
  slt   $at, $s1, $v1
  bnez  $at, .L7F0B671C
   addiu $s0, $s0, 0x50
.L7F0B6764:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
glabel sub_GAME_7F0B677C
  lui   $t6, %hi(MaxNumRooms) 
  lw    $t6, %lo(MaxNumRooms)($t6)
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  slt   $at, $a1, $t6
  move  $a3, $a0
  bnez  $at, .L7F0B67A4
   move  $a2, $a1
  b     .L7F0B6888
   move  $v0, $a0
.L7F0B67A4:
  lui   $t7, %hi(D_8004485C) 
  lw    $t7, %lo(D_8004485C)($t7)
  lui   $t8, %hi(D_80044858) 
  li    $at, 10
  bnez  $t7, .L7F0B67CC
   sll   $t1, $a2, 2
  div   $zero, $a2, $at
  lw    $t8, %lo(D_80044858)($t8)
  mfhi  $t9
  bne   $t8, $t9, .L7F0B6884
.L7F0B67CC:
   addu  $t1, $t1, $a2
  lui   $t2, %hi(array_room_info) 
  addiu $t2, %lo(array_room_info) # addiu $t2, $t2, 0x1414
  sll   $t1, $t1, 4
  addu  $v1, $t1, $t2
  lbu   $v0, 2($v1)
  lui   $t0, %hi(D_800442F8) 
  addiu $t0, %lo(D_800442F8) # addiu $t0, $t0, 0x42f8
  bnez  $v0, .L7F0B6828
   nop   
  lw    $a1, ($t0)
  move  $a0, $a2
  blez  $a1, .L7F0B6828
   addiu $t3, $a1, -1
  sw    $t3, ($t0)
  sw    $v1, 0x1c($sp)
  sw    $a2, 0x2c($sp)
  jal   sub_GAME_7F0B6368
   sw    $a3, 0x28($sp)
  lw    $v1, 0x1c($sp)
  lw    $a2, 0x2c($sp)
  lw    $a3, 0x28($sp)
  lbu   $v0, 2($v1)
.L7F0B6828:
  bnez  $v0, .L7F0B6838
   move  $a0, $a3
  b     .L7F0B6888
   move  $v0, $a3
.L7F0B6838:
  move  $a1, $a2
  jal   sub_GAME_7F0BC9C4
   sw    $v1, 0x1c($sp)
  lw    $v1, 0x1c($sp)
  lui   $t4, (0xBC003806 >> 16) # lui $t4, 0xbc00
  ori   $t4, (0xBC003806 & 0xFFFF) # ori $t4, $t4, 0x3806
  sw    $t4, ($v0)
  lw    $t5, 4($v1)
  lui   $a0, 0x8000
  lui   $t7, 0x600
  addu  $t6, $t5, $a0
  sw    $t6, 4($v0)
  sw    $t7, 8($v0)
  lw    $t8, 8($v1)
  li    $t1, 1
  addiu $a3, $v0, 0x10
  addu  $t9, $t8, $a0
  sw    $t9, 0xc($v0)
  sb    $t1, 2($v1)
.L7F0B6884:
  move  $v0, $a3
.L7F0B6888:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B6898
  lui   $t6, %hi(MaxNumRooms) 
  lw    $t6, %lo(MaxNumRooms)($t6)
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  slt   $at, $a1, $t6
  bnez  $at, .L7F0B68BC
   move  $a2, $a0
  b     .L7F0B6984
   move  $v0, $a0
.L7F0B68BC:
  sll   $t7, $a1, 2
  addu  $t7, $t7, $a1
  lui   $t8, %hi(array_room_info) 
  addiu $t8, %lo(array_room_info) # addiu $t8, $t8, 0x1414
  sll   $t7, $t7, 4
  addu  $v1, $t7, $t8
  lw    $t9, 0xc($v1)
  lui   $t0, %hi(D_8004485C) 
  bnez  $t9, .L7F0B68EC
   nop   
  b     .L7F0B6984
   move  $v0, $a2
.L7F0B68EC:
  lw    $t0, %lo(D_8004485C)($t0)
  lui   $t1, %hi(D_80044858) 
  li    $at, 10
  bnezl $t0, .L7F0B6918
   lbu   $t3, 2($v1)
  div   $zero, $a1, $at
  lw    $t1, %lo(D_80044858)($t1)
  mfhi  $t2
  bnel  $t1, $t2, .L7F0B6984
   move  $v0, $a2
  lbu   $t3, 2($v1)
.L7F0B6918:
  move  $a0, $a2
  beql  $t3, $zero, .L7F0B6974
   move  $a0, $a1
  jal   sub_GAME_7F0BC9C4
   sw    $v1, 0x1c($sp)
  lw    $v1, 0x1c($sp)
  lui   $t4, (0xBC003806 >> 16) # lui $t4, 0xbc00
  ori   $t4, (0xBC003806 & 0xFFFF) # ori $t4, $t4, 0x3806
  sw    $t4, ($v0)
  lw    $t5, 4($v1)
  lui   $a0, 0x8000
  lui   $t7, 0x600
  addu  $t6, $t5, $a0
  sw    $t6, 4($v0)
  sw    $t7, 8($v0)
  lw    $t8, 0xc($v1)
  li    $t0, 1
  addiu $a2, $v0, 0x10
  addu  $t9, $t8, $a0
  sw    $t9, 0xc($v0)
  b     .L7F0B6980
   sb    $t0, 2($v1)
  move  $a0, $a1
.L7F0B6974:
  jal   sub_GAME_7F0B6368
   sw    $a2, 0x28($sp)
  lw    $a2, 0x28($sp)
.L7F0B6980:
  move  $v0, $a2
.L7F0B6984:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B6994
  sll   $t7, $a0, 2
  addu  $t7, $t7, $a0
  lui   $t8, %hi(array_room_info) 
  addiu $t8, %lo(array_room_info) # addiu $t8, $t8, 0x1414
  sll   $t7, $t7, 4
  addu  $a1, $t7, $t8
  lw    $t9, 0x2c($a1)
  addiu $sp, $sp, -0x50
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  bnez  $t9, .L7F0B6CD8
   sw    $a0, 0x50($sp)
  lw    $t6, 4($a1)
  lw    $a2, 8($a1)
  li    $s0, -72
  sw    $t6, 0x44($sp)
  lb    $t7, ($a2)
  move  $t5, $zero
  li    $at, -16
  beq   $s0, $t7, .L7F0B6A10
   move  $t3, $a2
  lb    $v1, ($a2)
  li    $s1, 4
.L7F0B69F4:
  bnel  $s1, $v1, .L7F0B6A04
   lb    $v1, 8($t3)
  addiu $t5, $t5, 1
  lb    $v1, 8($t3)
.L7F0B6A04:
  addiu $t3, $t3, 8
  bne   $s0, $v1, .L7F0B69F4
   nop   
.L7F0B6A10:
  sll   $a0, $t5, 3
  subu  $a0, $a0, $t5
  sll   $a0, $a0, 2
  addiu $a0, $a0, 0xf
  and   $t8, $a0, $at
  li    $s1, 4
  move  $a0, $t8
  sw    $t8, 0x24($sp)
  sw    $a1, 0x28($sp)
  sw    $a2, 0x48($sp)
  jal   mem_related_something_find_first
   sw    $t5, 0x3c($sp)
  lw    $a1, 0x28($sp)
  lw    $a2, 0x48($sp)
  beqz  $v0, .L7F0B6CD8
   lw    $t5, 0x3c($sp)
  sw    $v0, 0x2c($a1)
  sh    $t5, 0x30($a1)
  lb    $t9, ($a2)
  move  $t5, $zero
  move  $ra, $zero
  beq   $s0, $t9, .L7F0B6CD8
   move  $t3, $a2
  lui   $t4, %hi(ptr_bgdata_room_fileposition_list) 
  addiu $t4, %lo(ptr_bgdata_room_fileposition_list) # addiu $t4, $t4, -0x74
  lb    $v1, ($a2)
  li    $t1, -32768
  li    $t0, 32767
.L7F0B6A80:
  bne   $s1, $v1, .L7F0B6CC4
   sll   $t6, $t5, 3
  subu  $t6, $t6, $t5
  sll   $t6, $t6, 2
  addu  $a0, $v0, $t6
  sh    $ra, ($a0)
  lw    $t2, 0x50($sp)
  sll   $t8, $t5, 3
  subu  $t8, $t8, $t5
  sll   $t7, $t2, 2
  sll   $t8, $t8, 2
  subu  $t7, $t7, $t2
  sll   $t2, $t7, 3
  addu  $v1, $v0, $t8
  move  $a2, $zero
.L7F0B6ABC:
  addiu $a2, $a2, 1
  slti  $at, $a2, 3
  addiu $v1, $v1, 4
  sw    $t0, ($v1)
  bnez  $at, .L7F0B6ABC
   sw    $t1, 0xc($v1)
  lbu   $a3, 1($t3)
  lw    $t7, 4($t3)
  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
  srl   $t9, $a3, 4
  andi  $t6, $t9, 0xf
  lw    $t9, 0x44($sp)
  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
  addiu $a3, $t6, 1
  and   $t8, $t7, $at
  move  $a2, $zero
  blez  $a3, .L7F0B6BA4
   addu  $v1, $t8, $t9
  move  $a1, $v1
.L7F0B6B08:
  lh    $v1, ($a1)
  lw    $t6, 4($a0)
  addiu $a2, $a2, 1
  slt   $at, $v1, $t6
  beql  $at, $zero, .L7F0B6B28
   lh    $v1, 2($a1)
  sw    $v1, 4($a0)
  lh    $v1, 2($a1)
.L7F0B6B28:
  lw    $t7, 8($a0)
  slt   $at, $v1, $t7
  beql  $at, $zero, .L7F0B6B40
   lh    $v1, 4($a1)
  sw    $v1, 8($a0)
  lh    $v1, 4($a1)
.L7F0B6B40:
  lw    $t8, 0xc($a0)
  slt   $at, $v1, $t8
  beql  $at, $zero, .L7F0B6B58
   lh    $v1, ($a1)
  sw    $v1, 0xc($a0)
  lh    $v1, ($a1)
.L7F0B6B58:
  lw    $t9, 0x10($a0)
  slt   $at, $t9, $v1
  beql  $at, $zero, .L7F0B6B70
   lh    $v1, 2($a1)
  sw    $v1, 0x10($a0)
  lh    $v1, 2($a1)
.L7F0B6B70:
  lw    $t6, 0x14($a0)
  slt   $at, $t6, $v1
  beql  $at, $zero, .L7F0B6B88
   lh    $v1, 4($a1)
  sw    $v1, 0x14($a0)
  lh    $v1, 4($a1)
.L7F0B6B88:
  lw    $t7, 0x18($a0)
  slt   $at, $t7, $v1
  beqz  $at, .L7F0B6B9C
   nop   
  sw    $v1, 0x18($a0)
.L7F0B6B9C:
  bne   $a2, $a3, .L7F0B6B08
   addiu $a1, $a1, 0x10
.L7F0B6BA4:
  lw    $v1, 0x10($a0)
  lw    $t8, 4($a0)
  addiu $t9, $v1, 1
  bnel  $t8, $v1, .L7F0B6BC0
   lw    $v1, 0x14($a0)
  sw    $t9, 0x10($a0)
  lw    $v1, 0x14($a0)
.L7F0B6BC0:
  lw    $t6, 8($a0)
  addiu $t7, $v1, 1
  bnel  $t6, $v1, .L7F0B6BD8
   lw    $v1, 0xc($a0)
  sw    $t7, 0x14($a0)
  lw    $v1, 0xc($a0)
.L7F0B6BD8:
  lw    $a1, 0x18($a0)
  bne   $v1, $a1, .L7F0B6BEC
   addiu $t8, $a1, 1
  sw    $t8, 0x18($a0)
  lw    $v1, 0xc($a0)
.L7F0B6BEC:
  lw    $t6, ($t4)
  lw    $t9, 4($a0)
  lw    $t8, 8($a0)
  addu  $t7, $t6, $t2
  lwc1  $f4, 0xc($t7)
  addiu $t5, $t5, 1
  trunc.w.s $f6, $f4
  mfc1  $t6, $f6
  nop   
  addu  $t7, $t9, $t6
  sw    $t7, 4($a0)
  lw    $t9, ($t4)
  addu  $t6, $t9, $t2
  lwc1  $f8, 0x10($t6)
  trunc.w.s $f10, $f8
  mfc1  $t9, $f10
  nop   
  addu  $t6, $t8, $t9
  sw    $t6, 8($a0)
  lw    $t7, ($t4)
  addu  $t8, $t7, $t2
  lwc1  $f16, 0x14($t8)
  lw    $t8, 0x10($a0)
  trunc.w.s $f18, $f16
  mfc1  $t6, $f18
  nop   
  addu  $t7, $v1, $t6
  sw    $t7, 0xc($a0)
  lw    $t9, ($t4)
  lw    $t7, 0x14($a0)
  addu  $t6, $t9, $t2
  lwc1  $f4, 0xc($t6)
  trunc.w.s $f6, $f4
  mfc1  $t9, $f6
  nop   
  addu  $t6, $t8, $t9
  sw    $t6, 0x10($a0)
  lw    $t8, ($t4)
  lw    $t6, 0x18($a0)
  addu  $t9, $t8, $t2
  lwc1  $f8, 0x10($t9)
  trunc.w.s $f10, $f8
  mfc1  $t8, $f10
  nop   
  addu  $t9, $t7, $t8
  sw    $t9, 0x14($a0)
  lw    $t7, ($t4)
  addu  $t8, $t7, $t2
  lwc1  $f16, 0x14($t8)
  trunc.w.s $f18, $f16
  mfc1  $t7, $f18
  nop   
  addu  $t8, $t6, $t7
  sw    $t8, 0x18($a0)
.L7F0B6CC4:
  lb    $v1, 8($t3)
  addiu $ra, $ra, 1
  addiu $t3, $t3, 8
  bne   $s0, $v1, .L7F0B6A80
   nop   
.L7F0B6CD8:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x50
");

asm(R"
glabel sub_GAME_7F0B6CEC
  lw    $t6, ($a2)
  addiu $sp, $sp, -0x78
  mtc1  $t6, $f4
  nop   
  cvt.s.w $f6, $f4
  swc1  $f6, 0x6c($sp)
  lw    $t7, 4($a2)
  mtc1  $t7, $f8
  nop   
  cvt.s.w $f10, $f8
  swc1  $f10, 0x70($sp)
  lw    $t8, 8($a2)
  mtc1  $t8, $f4
  nop   
  cvt.s.w $f6, $f4
  swc1  $f6, 0x74($sp)
  lw    $t9, ($a3)
  mtc1  $t9, $f8
  nop   
  cvt.s.w $f10, $f8
  swc1  $f10, 0x60($sp)
  lw    $t0, 4($a3)
  mtc1  $t0, $f4
  nop   
  cvt.s.w $f6, $f4
  lwc1  $f4, 0x60($sp)
  swc1  $f6, 0x64($sp)
  lw    $t1, 8($a3)
  lwc1  $f6, 0x6c($sp)
  mtc1  $t1, $f8
  nop   
  cvt.s.w $f10, $f8
  mtc1  $zero, $f8
  swc1  $f10, 0x68($sp)
  lwc1  $f18, ($a1)
  lwc1  $f0, ($a0)
  mtc1  $zero, $f10
  c.lt.s $f18, $f8
  sub.s $f16, $f4, $f0
  bc1f  .L7F0B6D9C
   sub.s $f14, $f6, $f0
  neg.s $f18, $f18
  neg.s $f14, $f14
  neg.s $f16, $f16
.L7F0B6D9C:
  c.lt.s $f14, $f10
  nop   
  bc1fl .L7F0B6DD0
   c.lt.s $f16, $f14
  mtc1  $zero, $f4
  nop   
  c.lt.s $f16, $f4
  nop   
  bc1fl .L7F0B6DD0
   c.lt.s $f16, $f14
  b     .L7F0B7008
   move  $v0, $zero
  c.lt.s $f16, $f14
.L7F0B6DD0:
  nop   
  bc1fl .L7F0B6DEC
   lwc1  $f6, 4($a0)
  mov.s $f0, $f14
  mov.s $f14, $f16
  mov.s $f16, $f0
  lwc1  $f6, 4($a0)
.L7F0B6DEC:
  lwc1  $f12, 4($a1)
  lwc1  $f8, 0x64($sp)
  swc1  $f6, 4($sp)
  mtc1  $zero, $f6
  lwc1  $f10, 4($sp)
  lwc1  $f4, 0x70($sp)
  c.lt.s $f12, $f6
  sub.s $f2, $f8, $f10
  mtc1  $zero, $f8
  bc1f  .L7F0B6E24
   sub.s $f0, $f4, $f10
  neg.s $f12, $f12
  neg.s $f0, $f0
  neg.s $f2, $f2
.L7F0B6E24:
  c.lt.s $f0, $f8
  nop   
  bc1fl .L7F0B6E58
   c.lt.s $f2, $f0
  mtc1  $zero, $f4
  nop   
  c.lt.s $f2, $f4
  nop   
  bc1fl .L7F0B6E58
   c.lt.s $f2, $f0
  b     .L7F0B7008
   move  $v0, $zero
  c.lt.s $f2, $f0
.L7F0B6E58:
  mul.s $f6, $f14, $f12
  bc1f  .L7F0B6E70
   nop   
  swc1  $f0, 0x20($sp)
  mov.s $f0, $f2
  lwc1  $f2, 0x20($sp)
.L7F0B6E70:
  mul.s $f10, $f0, $f18
  swc1  $f6, 4($sp)
  lwc1  $f4, 4($sp)
  swc1  $f10, ($sp)
  lwc1  $f8, ($sp)
  c.lt.s $f8, $f4
  nop   
  bc1f  .L7F0B6EC4
   nop   
  mul.s $f0, $f2, $f18
  c.lt.s $f0, $f4
  nop   
  bc1f  .L7F0B6EB0
   nop   
  b     .L7F0B7008
   move  $v0, $zero
.L7F0B6EB0:
  mul.s $f10, $f16, $f12
  swc1  $f14, 0x34($sp)
  swc1  $f18, 0x30($sp)
  b     .L7F0B6EFC
   swc1  $f10, 4($sp)
.L7F0B6EC4:
  mul.s $f14, $f16, $f12
  lwc1  $f6, ($sp)
  c.lt.s $f14, $f6
  nop   
  bc1f  .L7F0B6EE4
   nop   
  b     .L7F0B7008
   move  $v0, $zero
.L7F0B6EE4:
  mul.s $f8, $f2, $f18
  swc1  $f0, 0x34($sp)
  swc1  $f12, 0x30($sp)
  swc1  $f14, 4($sp)
  swc1  $f8, ($sp)
  lwc1  $f0, ($sp)
.L7F0B6EFC:
  lwc1  $f4, 4($sp)
  mtc1  $zero, $f8
  c.lt.s $f4, $f0
  mtc1  $zero, $f4
  bc1fl .L7F0B6F24
   mov.s $f0, $f2
  mov.s $f0, $f16
  b     .L7F0B6F28
   mov.s $f14, $f18
  mov.s $f0, $f2
.L7F0B6F24:
  mov.s $f14, $f12
.L7F0B6F28:
  lwc1  $f2, 8($a1)
  lwc1  $f16, 8($a0)
  lwc1  $f6, 0x74($sp)
  c.lt.s $f2, $f8
  lwc1  $f10, 0x68($sp)
  sub.s $f18, $f6, $f16
  lwc1  $f6, 0x34($sp)
  bc1f  .L7F0B6F58
   sub.s $f12, $f10, $f16
  neg.s $f2, $f2
  neg.s $f18, $f18
  neg.s $f12, $f12
.L7F0B6F58:
  c.lt.s $f18, $f4
  lwc1  $f8, 0x30($sp)
  bc1fl .L7F0B6F8C
   c.lt.s $f12, $f18
  mtc1  $zero, $f10
  nop   
  c.lt.s $f12, $f10
  nop   
  bc1fl .L7F0B6F8C
   c.lt.s $f12, $f18
  b     .L7F0B7008
   move  $v0, $zero
  c.lt.s $f12, $f18
.L7F0B6F8C:
  nop   
  bc1f  .L7F0B6FA4
   nop   
  mov.s $f16, $f18
  mov.s $f18, $f12
  mov.s $f12, $f16
.L7F0B6FA4:
  mul.s $f16, $f6, $f2
  nop   
  mul.s $f4, $f18, $f8
  lwc1  $f8, 0x30($sp)
  c.lt.s $f16, $f4
  nop   
  bc1f  .L7F0B6FE8
   nop   
  mul.s $f10, $f0, $f2
  nop   
  mul.s $f6, $f18, $f14
  c.lt.s $f10, $f6
  nop   
  bc1f  .L7F0B7004
   nop   
  b     .L7F0B7008
   move  $v0, $zero
.L7F0B6FE8:
  mul.s $f4, $f12, $f8
  c.lt.s $f4, $f16
  nop   
  bc1fl .L7F0B7008
   li    $v0, 1
  b     .L7F0B7008
   move  $v0, $zero
.L7F0B7004:
  li    $v0, 1
.L7F0B7008:
  jr    $ra
   addiu $sp, $sp, 0x78
");

asm(R"
glabel sub_GAME_7F0B7010
  addiu $sp, $sp, -0x140
  lw    $t6, 0x150($sp)
  lui   $t8, %hi(array_room_info) 
  sw    $ra, 0x4c($sp)
  sll   $t7, $t6, 2
  addu  $t7, $t7, $t6
  sw    $fp, 0x48($sp)
  sw    $s7, 0x44($sp)
  sw    $s6, 0x40($sp)
  sw    $s5, 0x3c($sp)
  sw    $s4, 0x38($sp)
  sw    $s3, 0x34($sp)
  sw    $s2, 0x30($sp)
  sw    $s1, 0x2c($sp)
  sw    $s0, 0x28($sp)
  sw    $a0, 0x140($sp)
  sw    $a1, 0x144($sp)
  sw    $a2, 0x148($sp)
  sll   $t7, $t7, 4
  addiu $t8, %lo(array_room_info) # addiu $t8, $t8, 0x1414
  lh    $t9, ($a3)
  addu  $t0, $t7, $t8
  lw    $s3, 8($t0)
  sll   $t1, $t9, 3
  lui   $t5, (0x7FFFFFFF >> 16) # lui $t5, 0x7fff
  addu  $s3, $t1, $s3
  lw    $t3, 4($s3)
  lbu   $s7, 1($s3)
  ori   $t5, (0x7FFFFFFF & 0xFFFF) # ori $t5, $t5, 0xffff
  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
  sw    $t5, 0xf0($sp)
  sw    $zero, 0x12c($sp)
  lb    $v0, 8($s3)
  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
  lw    $v1, 4($t0)
  and   $t4, $t3, $at
  li    $at, 4
  andi  $t2, $s7, 0xf
  move  $s7, $t2
  addiu $s3, $s3, 8
  beq   $v0, $at, .L7F0B7A44
   addu  $s1, $t4, $v1
  li    $at, -72
  beq   $v0, $at, .L7F0B7A44
   li    $s6, 253
  sw    $t0, 0x64($sp)
  addiu $t0, $sp, 0xa8
  lw    $s4, 0x154($sp)
  li    $at, -65
.L7F0B70D4:
  bne   $v0, $at, .L7F0B7554
   lui   $t6, %hi(D_80044868) 
  addiu $t6, %lo(D_80044868) # addiu $t6, $t6, 0x4868
  lw    $at, ($t6)
  addiu $a2, $sp, 0xd4
  lui   $t9, %hi(D_80044874) 
  sw    $at, ($a2)
  lw    $t8, 4($t6)
  addiu $t9, %lo(D_80044874) # addiu $t9, $t9, 0x4874
  addiu $a3, $sp, 0xc8
  sw    $t8, 4($a2)
  lw    $at, 8($t6)
  li    $a1, 10
  move  $v0, $zero
  sw    $at, 8($a2)
  lw    $at, ($t9)
  addiu $a0, $sp, 0xe4
  sw    $at, ($a3)
  lw    $t2, 4($t9)
  sw    $t2, 4($a3)
  lw    $at, 8($t9)
  sw    $at, 8($a3)
  lbu   $t3, 5($s3)
  div   $zero, $t3, $a1
  mflo  $t4
  subu  $t5, $t4, $s7
  sw    $t5, 0xe4($sp)
  lbu   $t7, 6($s3)
  bnez  $a1, .L7F0B7150
   nop   
  break 7
.L7F0B7150:
  li    $at, -1
  bne   $a1, $at, .L7F0B7168
   lui   $at, 0x8000
  bne   $t3, $at, .L7F0B7168
   nop   
  break 6
.L7F0B7168:
  div   $zero, $t7, $a1
  mflo  $t6
  subu  $t8, $t6, $s7
  sw    $t8, 0xe8($sp)
  lbu   $t1, 7($s3)
  bnez  $a1, .L7F0B7188
   nop   
  break 7
.L7F0B7188:
  li    $at, -1
  bne   $a1, $at, .L7F0B71A0
   lui   $at, 0x8000
  bne   $t7, $at, .L7F0B71A0
   nop   
  break 6
.L7F0B71A0:
  div   $zero, $t1, $a1
  lw    $t3, 0x150($sp)
  mflo  $t9
  subu  $t2, $t9, $s7
  sll   $t4, $t3, 2
  subu  $t4, $t4, $t3
  sll   $t4, $t4, 3
  sw    $t2, 0xec($sp)
  sw    $t4, 0x54($sp)
  bnez  $a1, .L7F0B71D0
   nop   
  break 7
.L7F0B71D0:
  li    $at, -1
  bne   $a1, $at, .L7F0B71E8
   lui   $at, 0x8000
  bne   $t1, $at, .L7F0B71E8
   nop   
  break 6
.L7F0B71E8:
  lw    $t5, ($a0)
.L7F0B71EC:
  lw    $t6, 0xd4($sp)
  addiu $a0, $a0, 4
  sll   $t7, $t5, 4
  addu  $v1, $s1, $t7
  lh    $v0, ($v1)
  addiu $t4, $sp, 0xf0
  slt   $at, $v0, $t6
  beql  $at, $zero, .L7F0B721C
   lw    $t8, 0xc8($sp)
  sw    $v0, 0xd4($sp)
  lh    $v0, ($v1)
  lw    $t8, 0xc8($sp)
.L7F0B721C:
  slt   $at, $t8, $v0
  beql  $at, $zero, .L7F0B7230
   lh    $v0, 2($v1)
  sw    $v0, 0xc8($sp)
  lh    $v0, 2($v1)
.L7F0B7230:
  lw    $t1, 0xd8($sp)
  slt   $at, $v0, $t1
  beql  $at, $zero, .L7F0B724C
   lw    $t9, 0xcc($sp)
  sw    $v0, 0xd8($sp)
  lh    $v0, 2($v1)
  lw    $t9, 0xcc($sp)
.L7F0B724C:
  slt   $at, $t9, $v0
  beql  $at, $zero, .L7F0B7260
   lh    $v0, 4($v1)
  sw    $v0, 0xcc($sp)
  lh    $v0, 4($v1)
.L7F0B7260:
  lw    $t2, 0xdc($sp)
  slt   $at, $v0, $t2
  beql  $at, $zero, .L7F0B727C
   lw    $t3, 0xd0($sp)
  sw    $v0, 0xdc($sp)
  lh    $v0, 4($v1)
  lw    $t3, 0xd0($sp)
.L7F0B727C:
  slt   $at, $t3, $v0
  beqz  $at, .L7F0B728C
   nop   
  sw    $v0, 0xd0($sp)
.L7F0B728C:
  bnel  $a0, $t4, .L7F0B71EC
   lw    $t5, ($a0)
  lui   $t5, %hi(ptr_bgdata_room_fileposition_list) 
  lw    $t5, %lo(ptr_bgdata_room_fileposition_list)($t5)
  lw    $t7, 0x54($sp)
  lw    $t6, 0xd4($sp)
  lw    $t2, 0xd8($sp)
  addu  $v0, $t5, $t7
  lwc1  $f4, 0xc($v0)
  lw    $t7, 0xdc($sp)
  lw    $a0, 0x140($sp)
  trunc.w.s $f6, $f4
  lw    $a1, 0x148($sp)
  mfc1  $t1, $f6
  nop   
  addu  $t9, $t6, $t1
  sw    $t9, 0xd4($sp)
  lwc1  $f8, 0x10($v0)
  lw    $t9, 0xc8($sp)
  trunc.w.s $f10, $f8
  mfc1  $t4, $f10
  nop   
  addu  $t5, $t2, $t4
  sw    $t5, 0xd8($sp)
  lwc1  $f16, 0x14($v0)
  lw    $t5, 0xcc($sp)
  trunc.w.s $f18, $f16
  mfc1  $t6, $f18
  nop   
  addu  $t1, $t7, $t6
  sw    $t1, 0xdc($sp)
  lwc1  $f4, 0xc($v0)
  lw    $t1, 0xd0($sp)
  trunc.w.s $f6, $f4
  mfc1  $t2, $f6
  nop   
  addu  $t4, $t9, $t2
  sw    $t4, 0xc8($sp)
  lwc1  $f8, 0x10($v0)
  trunc.w.s $f10, $f8
  mfc1  $t7, $f10
  nop   
  addu  $t6, $t5, $t7
  sw    $t6, 0xcc($sp)
  lwc1  $f16, 0x14($v0)
  trunc.w.s $f18, $f16
  mfc1  $t9, $f18
  nop   
  addu  $t2, $t1, $t9
  jal   sub_GAME_7F0B6CEC
   sw    $t2, 0xd0($sp)
  beqz  $v0, .L7F0B7A28
   addiu $t0, $sp, 0xa8
  lw    $t4, 0xe4($sp)
  lw    $t5, 0xe8($sp)
  lui   $t9, %hi(ptr_bgdata_room_fileposition_list) 
  sll   $t8, $t4, 4
  lw    $t9, %lo(ptr_bgdata_room_fileposition_list)($t9)
  lw    $t6, 0xec($sp)
  lw    $t1, 0x54($sp)
  addu  $a0, $s1, $t8
  lw    $t8, 0x148($sp)
  lw    $t4, 0x144($sp)
  lw    $t2, 0x140($sp)
  sll   $t7, $t5, 4
  addiu $t5, $sp, 0xf8
  sll   $t3, $t6, 4
  addu  $a3, $t1, $t9
  addiu $a3, $a3, 0xc
  addu  $a2, $s1, $t3
  sw    $t5, 0x1c($sp)
  addu  $a1, $s1, $t7
  sw    $t8, 0x18($sp)
  sw    $t4, 0x14($sp)
  jal   sub_GAME_7F092890
   sw    $t2, 0x10($sp)
  beqz  $v0, .L7F0B7A28
   addiu $t0, $sp, 0xa8
  lw    $a2, 0x140($sp)
  lwc1  $f4, 0xf8($sp)
  lwc1  $f16, 0xfc($sp)
  lwc1  $f8, ($a2)
  trunc.w.s $f6, $f4
  lwc1  $f4, 4($a2)
  move  $v0, $s3
  trunc.w.s $f10, $f8
  mfc1  $t6, $f6
  lwc1  $f8, 0x100($sp)
  trunc.w.s $f18, $f16
  mfc1  $t1, $f10
  lwc1  $f16, 8($a2)
  trunc.w.s $f6, $f4
  subu  $v1, $t6, $t1
  multu $v1, $v1
  mfc1  $t2, $f18
  mfc1  $t8, $f6
  trunc.w.s $f10, $f8
  lw    $t3, 0x64($sp)
  subu  $a0, $t2, $t8
  trunc.w.s $f18, $f16
  mfc1  $t7, $f10
  li    $t8, 1
  sw    $t8, 0x12c($sp)
  mflo  $t1
  mfc1  $t6, $f18
  lbu   $t5, ($s3)
  multu $a0, $a0
  subu  $a1, $t7, $t6
  lw    $t6, 0x64($sp)
  mflo  $t9
  addu  $t4, $t1, $t9
  nop   
  multu $a1, $a1
  mflo  $t2
  addu  $s2, $t4, $t2
  beq   $s6, $t5, .L7F0B748C
   move  $fp, $s2
  lw    $v1, 8($t3)
  sltu  $at, $v1, $s3
  beql  $at, $zero, .L7F0B7490
   lw    $t1, 8($t6)
  lbu   $t7, -8($v0)
.L7F0B7474:
  addiu $v0, $v0, -8
  sltu  $at, $v1, $v0
  beql  $s6, $t7, .L7F0B7490
   lw    $t1, 8($t6)
  bnezl $at, .L7F0B7474
   lbu   $t7, -8($v0)
.L7F0B748C:
  lw    $t1, 8($t6)
.L7F0B7490:
  bnel  $v0, $t1, .L7F0B74A4
   lw    $v1, 4($v0)
  b     .L7F0B74B4
   li    $s0, -1
  lw    $v1, 4($v0)
.L7F0B74A4:
  lui   $at, 0x8000
  addiu $v1, $v1, -8
  or    $t9, $v1, $at
  lhu   $s0, ($t9)
.L7F0B74B4:
  jal   check_if_imageID_is_light
   move  $a0, $s0
  beqz  $v0, .L7F0B74C8
   addiu $t0, $sp, 0xa8
  addiu $fp, $s2, -4
.L7F0B74C8:
  lw    $t4, 0xf0($sp)
  slt   $at, $fp, $t4
  beqz  $at, .L7F0B7A28
   li    $at, 1277
  beql  $s0, $at, .L7F0B7A2C
   lb    $v0, 8($s3)
  lwc1  $f4, 0xf8($sp)
  sw    $fp, 0xf0($sp)
  swc1  $f4, ($s4)
  lwc1  $f6, 0xfc($sp)
  swc1  $f6, 4($s4)
  lwc1  $f8, 0x100($sp)
  swc1  $f8, 8($s4)
  lwc1  $f10, 0x104($sp)
  swc1  $f10, 0xc($s4)
  lwc1  $f16, 0x108($sp)
  swc1  $f16, 0x10($s4)
  lwc1  $f18, 0x10c($sp)
  swc1  $f18, 0x14($s4)
  lw    $t2, 0xe4($sp)
  sll   $t8, $t2, 4
  addu  $t5, $t8, $s1
  sw    $t5, 0x18($s4)
  lw    $t3, 0xe8($sp)
  sll   $t7, $t3, 4
  addu  $t6, $t7, $s1
  sw    $t6, 0x1c($s4)
  lw    $t1, 0xec($sp)
  sh    $s0, 0x2a($s4)
  sw    $s3, 0x24($s4)
  sll   $t9, $t1, 4
  addu  $t4, $t9, $s1
  sw    $t4, 0x20($s4)
  b     .L7F0B7A28
   sh    $zero, 0x28($s4)
.L7F0B7554:
  li    $at, -79
  bne   $v0, $at, .L7F0B7A28
   lw    $t2, 0x150($sp)
  sll   $t8, $t2, 2
  subu  $t8, $t8, $t2
  sll   $t8, $t8, 3
  sw    $t8, 0x54($sp)
  move  $s5, $zero
.L7F0B7574:
  lui   $t3, %hi(D_80044880) 
  addiu $t3, %lo(D_80044880) # addiu $t3, $t3, 0x4880
  lw    $at, ($t3)
  addiu $t5, $sp, 0x8c
  lw    $t1, 4($t3)
  sw    $at, ($t5)
  lw    $at, 8($t3)
  lui   $t4, %hi(D_8004488C) 
  addiu $t4, %lo(D_8004488C) # addiu $t4, $t4, 0x488c
  sw    $t1, 4($t5)
  sw    $at, 8($t5)
  lw    $at, ($t4)
  addiu $t9, $sp, 0x80
  lw    $t6, 4($t4)
  sw    $at, ($t9)
  lw    $at, 8($t4)
  sw    $t6, 4($t9)
  bnez  $s5, .L7F0B75F4
   sw    $at, 8($t9)
  lw    $t7, 4($s3)
  andi  $t5, $t7, 0xf
  subu  $t3, $t5, $s7
  sw    $t3, 0x9c($sp)
  lbu   $t1, 7($s3)
  srl   $t8, $t1, 4
  subu  $t2, $t8, $s7
  sw    $t2, 0xa0($sp)
  lw    $t9, ($s3)
  andi  $t4, $t9, 0xf
  subu  $t6, $t4, $s7
  b     .L7F0B76A4
   sw    $t6, 0xa4($sp)
.L7F0B75F4:
  li    $at, 1
  bnel  $s5, $at, .L7F0B7638
   li    $at, 2
  lbu   $t7, 6($s3)
  andi  $t5, $t7, 0xf
  subu  $t3, $t5, $s7
  sw    $t3, 0x9c($sp)
  lhu   $t1, 6($s3)
  srl   $t8, $t1, 0xc
  subu  $t2, $t8, $s7
  sw    $t2, 0xa0($sp)
  lbu   $t9, 3($s3)
  srl   $t4, $t9, 4
  subu  $t6, $t4, $s7
  b     .L7F0B76A4
   sw    $t6, 0xa4($sp)
  li    $at, 2
.L7F0B7638:
  bnel  $s5, $at, .L7F0B7678
   lbu   $t7, 4($s3)
  lhu   $t7, 4($s3)
  andi  $t5, $t7, 0xf
  subu  $t3, $t5, $s7
  sw    $t3, 0x9c($sp)
  lbu   $t1, 5($s3)
  srl   $t8, $t1, 4
  subu  $t2, $t8, $s7
  sw    $t2, 0xa0($sp)
  lbu   $t9, 2($s3)
  andi  $t4, $t9, 0xf
  subu  $t6, $t4, $s7
  b     .L7F0B76A4
   sw    $t6, 0xa4($sp)
  lbu   $t7, 4($s3)
.L7F0B7678:
  andi  $t5, $t7, 0xf
  subu  $t3, $t5, $s7
  sw    $t3, 0x9c($sp)
  lw    $t1, 4($s3)
  srl   $t8, $t1, 0x1c
  subu  $t2, $t8, $s7
  sw    $t2, 0xa0($sp)
  lhu   $t9, 2($s3)
  srl   $t4, $t9, 0xc
  subu  $t6, $t4, $s7
  sw    $t6, 0xa4($sp)
.L7F0B76A4:
  addiu $a0, $sp, 0x9c
  lw    $t7, ($a0)
.L7F0B76AC:
  lw    $t3, 0x8c($sp)
  addiu $a0, $a0, 4
  sll   $t5, $t7, 4
  addu  $v1, $s1, $t5
  lh    $v0, ($v1)
  slt   $at, $v0, $t3
  beql  $at, $zero, .L7F0B76D8
   lw    $t1, 0x80($sp)
  sw    $v0, 0x8c($sp)
  lh    $v0, ($v1)
  lw    $t1, 0x80($sp)
.L7F0B76D8:
  slt   $at, $t1, $v0
  beql  $at, $zero, .L7F0B76EC
   lh    $v0, 2($v1)
  sw    $v0, 0x80($sp)
  lh    $v0, 2($v1)
.L7F0B76EC:
  lw    $t8, 0x90($sp)
  slt   $at, $v0, $t8
  beql  $at, $zero, .L7F0B7708
   lw    $t2, 0x84($sp)
  sw    $v0, 0x90($sp)
  lh    $v0, 2($v1)
  lw    $t2, 0x84($sp)
.L7F0B7708:
  slt   $at, $t2, $v0
  beql  $at, $zero, .L7F0B771C
   lh    $v0, 4($v1)
  sw    $v0, 0x84($sp)
  lh    $v0, 4($v1)
.L7F0B771C:
  lw    $t9, 0x94($sp)
  slt   $at, $v0, $t9
  beql  $at, $zero, .L7F0B7738
   lw    $t4, 0x88($sp)
  sw    $v0, 0x94($sp)
  lh    $v0, 4($v1)
  lw    $t4, 0x88($sp)
.L7F0B7738:
  slt   $at, $t4, $v0
  beqz  $at, .L7F0B7748
   nop   
  sw    $v0, 0x88($sp)
.L7F0B7748:
  bnel  $a0, $t0, .L7F0B76AC
   lw    $t7, ($a0)
  lui   $t6, %hi(ptr_bgdata_room_fileposition_list) 
  lw    $t6, %lo(ptr_bgdata_room_fileposition_list)($t6)
  lw    $t7, 0x54($sp)
  lw    $t5, 0x8c($sp)
  lw    $t2, 0x90($sp)
  addu  $v0, $t6, $t7
  lwc1  $f4, 0xc($v0)
  lw    $t7, 0x94($sp)
  lw    $a0, 0x140($sp)
  trunc.w.s $f6, $f4
  lw    $a1, 0x148($sp)
  addiu $a2, $sp, 0x8c
  addiu $a3, $sp, 0x80
  mfc1  $t1, $f6
  nop   
  addu  $t8, $t5, $t1
  sw    $t8, 0x8c($sp)
  lwc1  $f8, 0x10($v0)
  lw    $t8, 0x80($sp)
  trunc.w.s $f10, $f8
  mfc1  $t4, $f10
  nop   
  addu  $t6, $t2, $t4
  sw    $t6, 0x90($sp)
  lwc1  $f16, 0x14($v0)
  lw    $t6, 0x84($sp)
  trunc.w.s $f18, $f16
  mfc1  $t5, $f18
  nop   
  addu  $t1, $t7, $t5
  sw    $t1, 0x94($sp)
  lwc1  $f4, 0xc($v0)
  lw    $t1, 0x88($sp)
  trunc.w.s $f6, $f4
  mfc1  $t2, $f6
  nop   
  addu  $t4, $t8, $t2
  sw    $t4, 0x80($sp)
  lwc1  $f8, 0x10($v0)
  trunc.w.s $f10, $f8
  mfc1  $t7, $f10
  nop   
  addu  $t5, $t6, $t7
  sw    $t5, 0x84($sp)
  lwc1  $f16, 0x14($v0)
  trunc.w.s $f18, $f16
  mfc1  $t8, $f18
  nop   
  addu  $t2, $t1, $t8
  jal   sub_GAME_7F0B6CEC
   sw    $t2, 0x88($sp)
  beqz  $v0, .L7F0B7A18
   addiu $t0, $sp, 0xa8
  lw    $t4, 0x9c($sp)
  lw    $t6, 0xa0($sp)
  lui   $t8, %hi(ptr_bgdata_room_fileposition_list) 
  sll   $t3, $t4, 4
  lw    $t8, %lo(ptr_bgdata_room_fileposition_list)($t8)
  lw    $t5, 0xa4($sp)
  lw    $t1, 0x54($sp)
  addu  $a0, $s1, $t3
  lw    $t3, 0x148($sp)
  lw    $t4, 0x144($sp)
  lw    $t2, 0x140($sp)
  sll   $t7, $t6, 4
  addiu $t6, $sp, 0xf8
  sll   $t9, $t5, 4
  addu  $a3, $t1, $t8
  addiu $a3, $a3, 0xc
  addu  $a2, $s1, $t9
  sw    $t6, 0x1c($sp)
  addu  $a1, $s1, $t7
  sw    $t3, 0x18($sp)
  sw    $t4, 0x14($sp)
  jal   sub_GAME_7F092890
   sw    $t2, 0x10($sp)
  beqz  $v0, .L7F0B7A18
   addiu $t0, $sp, 0xa8
  lw    $a2, 0x140($sp)
  lwc1  $f4, 0xf8($sp)
  lwc1  $f16, 0xfc($sp)
  lwc1  $f8, ($a2)
  trunc.w.s $f6, $f4
  lwc1  $f4, 4($a2)
  move  $v0, $s3
  trunc.w.s $f10, $f8
  mfc1  $t5, $f6
  lwc1  $f8, 0x100($sp)
  trunc.w.s $f18, $f16
  mfc1  $t1, $f10
  lwc1  $f16, 8($a2)
  trunc.w.s $f6, $f4
  subu  $v1, $t5, $t1
  multu $v1, $v1
  mfc1  $t2, $f18
  mfc1  $t3, $f6
  trunc.w.s $f10, $f8
  lw    $t9, 0x64($sp)
  subu  $a0, $t2, $t3
  trunc.w.s $f18, $f16
  mfc1  $t7, $f10
  li    $t3, 1
  sw    $t3, 0x12c($sp)
  mflo  $t1
  mfc1  $t5, $f18
  lbu   $t6, ($s3)
  multu $a0, $a0
  subu  $a1, $t7, $t5
  lw    $t5, 0x64($sp)
  mflo  $t8
  addu  $t4, $t1, $t8
  nop   
  multu $a1, $a1
  mflo  $t2
  addu  $s2, $t4, $t2
  beq   $s6, $t6, .L7F0B7950
   move  $fp, $s2
  lw    $v1, 8($t9)
  sltu  $at, $v1, $s3
  beql  $at, $zero, .L7F0B7954
   lw    $t1, 8($t5)
  lbu   $t7, -8($v0)
.L7F0B7938:
  addiu $v0, $v0, -8
  sltu  $at, $v1, $v0
  beql  $s6, $t7, .L7F0B7954
   lw    $t1, 8($t5)
  bnezl $at, .L7F0B7938
   lbu   $t7, -8($v0)
.L7F0B7950:
  lw    $t1, 8($t5)
.L7F0B7954:
  bnel  $v0, $t1, .L7F0B7968
   lw    $v1, 4($v0)
  b     .L7F0B7978
   li    $s0, -1
  lw    $v1, 4($v0)
.L7F0B7968:
  lui   $at, 0x8000
  addiu $v1, $v1, -8
  or    $t8, $v1, $at
  lhu   $s0, ($t8)
.L7F0B7978:
  jal   check_if_imageID_is_light
   move  $a0, $s0
  beqz  $v0, .L7F0B798C
   addiu $t0, $sp, 0xa8
  addiu $fp, $s2, -4
.L7F0B798C:
  lw    $t4, 0xf0($sp)
  slt   $at, $fp, $t4
  beqz  $at, .L7F0B7A18
   li    $at, 1277
  beql  $s0, $at, .L7F0B7A1C
   addiu $s5, $s5, 1
  lwc1  $f4, 0xf8($sp)
  sw    $fp, 0xf0($sp)
  swc1  $f4, ($s4)
  lwc1  $f6, 0xfc($sp)
  swc1  $f6, 4($s4)
  lwc1  $f8, 0x100($sp)
  swc1  $f8, 8($s4)
  lwc1  $f10, 0x104($sp)
  swc1  $f10, 0xc($s4)
  lwc1  $f16, 0x108($sp)
  swc1  $f16, 0x10($s4)
  lwc1  $f18, 0x10c($sp)
  swc1  $f18, 0x14($s4)
  lw    $t2, 0x9c($sp)
  sll   $t3, $t2, 4
  addu  $t6, $t3, $s1
  sw    $t6, 0x18($s4)
  lw    $t9, 0xa0($sp)
  addiu $t2, $s5, 1
  sll   $t7, $t9, 4
  addu  $t5, $t7, $s1
  sw    $t5, 0x1c($s4)
  lw    $t1, 0xa4($sp)
  sh    $s0, 0x2a($s4)
  sw    $s3, 0x24($s4)
  sll   $t8, $t1, 4
  addu  $t4, $t8, $s1
  sw    $t4, 0x20($s4)
  sh    $t2, 0x28($s4)
.L7F0B7A18:
  addiu $s5, $s5, 1
.L7F0B7A1C:
  li    $at, 4
  bne   $s5, $at, .L7F0B7574
   nop   
.L7F0B7A28:
  lb    $v0, 8($s3)
.L7F0B7A2C:
  li    $at, 4
  addiu $s3, $s3, 8
  beq   $v0, $at, .L7F0B7A44
   li    $at, -72
  bnel  $v0, $at, .L7F0B70D4
   li    $at, -65
.L7F0B7A44:
  lw    $ra, 0x4c($sp)
  lw    $v0, 0x12c($sp)
  lw    $s0, 0x28($sp)
  lw    $s1, 0x2c($sp)
  lw    $s2, 0x30($sp)
  lw    $s3, 0x34($sp)
  lw    $s4, 0x38($sp)
  lw    $s5, 0x3c($sp)
  lw    $s6, 0x40($sp)
  lw    $s7, 0x44($sp)
  lw    $fp, 0x48($sp)
  jr    $ra
   addiu $sp, $sp, 0x140
");

asm(R"
glabel sub_GAME_7F0B7A78
  addiu $sp, $sp, -0xd8
  lui   $t6, (0x7FFFFFFF >> 16) # lui $t6, 0x7fff
  ori   $t6, (0x7FFFFFFF & 0xFFFF) # ori $t6, $t6, 0xffff
  sw    $ra, 0x44($sp)
  sw    $fp, 0x40($sp)
  sw    $s7, 0x3c($sp)
  sw    $s6, 0x38($sp)
  sw    $s5, 0x34($sp)
  sw    $s4, 0x30($sp)
  sw    $s3, 0x2c($sp)
  sw    $s2, 0x28($sp)
  sw    $s1, 0x24($sp)
  sw    $s0, 0x20($sp)
  sw    $a2, 0xe0($sp)
  sw    $zero, 0x6c($sp)
  sw    $t6, 0x74($sp)
  lui   $at, %hi(room_data_float1)
  lwc1  $f0, %lo(room_data_float1)($at)
  lwc1  $f4, ($a0)
  sll   $t8, $a2, 2
  addu  $t8, $t8, $a2
  mul.s $f6, $f4, $f0
  lui   $t9, %hi(array_room_info) 
  addiu $t9, %lo(array_room_info) # addiu $t9, $t9, 0x1414
  sll   $t8, $t8, 4
  addu  $t0, $t8, $t9
  lw    $v0, 0x2c($t0)
  move  $s1, $a3
  swc1  $f6, 0xc4($sp)
  lwc1  $f8, 4($a0)
  mul.s $f10, $f8, $f0
  swc1  $f10, 0xc8($sp)
  lwc1  $f16, 8($a0)
  mul.s $f18, $f16, $f0
  swc1  $f18, 0xcc($sp)
  lwc1  $f4, ($a1)
  mul.s $f6, $f4, $f0
  swc1  $f6, 0xb8($sp)
  lwc1  $f8, 4($a1)
  lwc1  $f4, 0xb8($sp)
  lwc1  $f6, 0xc4($sp)
  mul.s $f10, $f8, $f0
  sub.s $f8, $f4, $f6
  lwc1  $f6, 0xcc($sp)
  swc1  $f10, 0xbc($sp)
  lwc1  $f16, 8($a1)
  lwc1  $f10, 0xbc($sp)
  swc1  $f8, 0xac($sp)
  mul.s $f18, $f16, $f0
  lwc1  $f16, 0xc8($sp)
  swc1  $f18, 0xc0($sp)
  lwc1  $f4, 0xc0($sp)
  sub.s $f18, $f10, $f16
  sub.s $f8, $f4, $f6
  swc1  $f18, 0xb0($sp)
  bnez  $v0, .L7F0B7B64
   swc1  $f8, 0xb4($sp)
  b     .L7F0B7D64
   move  $v0, $zero
.L7F0B7B64:
  lh    $v1, 0x30($t0)
  move  $s4, $zero
  move  $s3, $v0
  blez  $v1, .L7F0B7CDC
   addiu $s5, $v0, 4
  addiu $s6, $v0, 0x10
  sh    $v1, 0xd2($sp)
  sw    $t0, 0x58($sp)
  addiu $fp, $sp, 0xac
  addiu $s7, $sp, 0xc4
.L7F0B7B8C:
  move  $a0, $s7
  move  $a1, $fp
  move  $a2, $s5
  jal   sub_GAME_7F0B6CEC
   move  $a3, $s6
  beqz  $v0, .L7F0B7CC0
   move  $a0, $s7
  lw    $t1, 0xe0($sp)
  addiu $t2, $sp, 0x7c
  sw    $t2, 0x14($sp)
  addiu $a1, $sp, 0xb8
  move  $a2, $fp
  move  $a3, $s3
  jal   sub_GAME_7F0B7010
   sw    $t1, 0x10($sp)
  beqz  $v0, .L7F0B7CC0
   lwc1  $f10, 0x7c($sp)
  lwc1  $f16, 0xc4($sp)
  lwc1  $f6, 0x80($sp)
  lwc1  $f8, 0xc8($sp)
  sub.s $f18, $f10, $f16
  li    $t1, 1
  sw    $t1, 0x6c($sp)
  sub.s $f10, $f6, $f8
  lh    $a0, 0xa6($sp)
  trunc.w.s $f4, $f18
  lwc1  $f18, 0x84($sp)
  trunc.w.s $f16, $f10
  mfc1  $v0, $f4
  lwc1  $f4, 0xcc($sp)
  multu $v0, $v0
  mfc1  $v1, $f16
  sub.s $f6, $f18, $f4
  trunc.w.s $f8, $f6
  mflo  $t6
  mfc1  $a1, $f8
  nop   
  multu $v1, $v1
  mflo  $t7
  addu  $t8, $t6, $t7
  nop   
  multu $a1, $a1
  mflo  $t9
  addu  $s2, $t8, $t9
  jal   check_if_imageID_is_light
   move  $s0, $s2
  beqz  $v0, .L7F0B7C50
   lw    $t2, 0x74($sp)
  addiu $s0, $s2, -4
.L7F0B7C50:
  slt   $at, $s0, $t2
  beql  $at, $zero, .L7F0B7CC4
   lh    $t9, 0xd2($sp)
  lwc1  $f10, 0x7c($sp)
  sw    $s0, 0x74($sp)
  swc1  $f10, ($s1)
  lwc1  $f16, 0x80($sp)
  swc1  $f16, 4($s1)
  lwc1  $f18, 0x84($sp)
  swc1  $f18, 8($s1)
  lwc1  $f4, 0x88($sp)
  swc1  $f4, 0xc($s1)
  lwc1  $f6, 0x8c($sp)
  swc1  $f6, 0x10($s1)
  lwc1  $f8, 0x90($sp)
  swc1  $f8, 0x14($s1)
  lw    $t3, 0x94($sp)
  sw    $t3, 0x18($s1)
  lw    $t4, 0x98($sp)
  sw    $t4, 0x1c($s1)
  lw    $t5, 0x9c($sp)
  sw    $t5, 0x20($s1)
  lh    $t6, 0xa6($sp)
  sh    $t6, 0x2a($s1)
  lw    $t7, 0xa0($sp)
  sw    $t7, 0x24($s1)
  lh    $t8, 0xa4($sp)
  sh    $t8, 0x28($s1)
.L7F0B7CC0:
  lh    $t9, 0xd2($sp)
.L7F0B7CC4:
  addiu $s4, $s4, 1
  addiu $s3, $s3, 0x1c
  addiu $s5, $s5, 0x1c
  bne   $s4, $t9, .L7F0B7B8C
   addiu $s6, $s6, 0x1c
  lw    $t0, 0x58($sp)
.L7F0B7CDC:
  lw    $t1, 0x6c($sp)
  beql  $t1, $zero, .L7F0B7D64
   lw    $v0, 0x6c($sp)
  lw    $v0, 0x24($s1)
  li    $a0, 245
  lbu   $t2, ($v0)
  beql  $a0, $t2, .L7F0B7D2C
   lw    $t4, 8($t0)
  lw    $v1, 8($t0)
  sltu  $at, $v1, $v0
  beql  $at, $zero, .L7F0B7D2C
   lw    $t4, 8($t0)
  lbu   $t3, -8($v0)
.L7F0B7D10:
  addiu $v0, $v0, -8
  sltu  $at, $v1, $v0
  beql  $a0, $t3, .L7F0B7D2C
   lw    $t4, 8($t0)
  bnezl $at, .L7F0B7D10
   lbu   $t3, -8($v0)
  lw    $t4, 8($t0)
.L7F0B7D2C:
  bnel  $v0, $t4, .L7F0B7D48
   lbu   $t5, 1($v0)
  li    $v0, -1
  sh    $v0, 0x2c($s1)
  b     .L7F0B7D60
   sh    $v0, 0x2e($s1)
  lbu   $t5, 1($v0)
.L7F0B7D48:
  srl   $t6, $t5, 5
  sh    $t6, 0x2c($s1)
  lw    $t7, ($v0)
  sll   $t8, $t7, 0xb
  srl   $t9, $t8, 0x1e
  sh    $t9, 0x2e($s1)
.L7F0B7D60:
  lw    $v0, 0x6c($sp)
.L7F0B7D64:
  lw    $ra, 0x44($sp)
  lw    $s0, 0x20($sp)
  lw    $s1, 0x24($sp)
  lw    $s2, 0x28($sp)
  lw    $s3, 0x2c($sp)
  lw    $s4, 0x30($sp)
  lw    $s5, 0x34($sp)
  lw    $s6, 0x38($sp)
  lw    $s7, 0x3c($sp)
  lw    $fp, 0x40($sp)
  jr    $ra
   addiu $sp, $sp, 0xd8
");

void sub_GAME_7F0B7D94(void) {
  D_800448A0 = 0;
  D_800448A4 = 0;
}

asm(R"
glabel sub_GAME_7F0B7DA8
  sll   $t6, $a0, 2
  addu  $t6, $t6, $a0
  lui   $t7, %hi(array_room_info) 
  addiu $t7, %lo(array_room_info) # addiu $t7, $t7, 0x1414
  sll   $t6, $t6, 4
  addu  $v0, $t6, $t7
  lbu   $v1, 3($v0)
  slti  $at, $v1, 0xff
  beqz  $at, .L7F0B7DDC
   move  $a1, $v1
  addiu $t8, $v1, 1
  sb    $t8, 3($v0)
  andi  $a1, $t8, 0xff
.L7F0B7DDC:
  jr    $ra
   move  $v0, $a1
");

asm(R"
glabel sub_GAME_7F0B7DE4
  lui   $t0, %hi(D_800448A0) 
  addiu $t0, %lo(D_800448A0) # addiu $t0, $t0, 0x48a0
  lw    $t6, ($t0)
  addiu $sp, $sp, -0x20
  lui   $t8, %hi(dword_CODE_bss_8007C100) 
  addiu $t8, %lo(dword_CODE_bss_8007C100) # addiu $t8, $t8, -0x3f00
  slti  $at, $a3, 2
  sll   $t7, $t6, 5
  sw    $ra, 0x14($sp)
  sw    $a0, 0x20($sp)
  sw    $a1, 0x24($sp)
  sw    $a2, 0x28($sp)
  bnez  $at, .L7F0B7E60
   addu  $v1, $t7, $t8
  lui   $t9, %hi(ptr_bgdata_portals) 
  lw    $t9, %lo(ptr_bgdata_portals)($t9)
  sll   $t2, $a2, 3
  addu  $v0, $t9, $t2
  lbu   $t3, 4($v0)
  lbu   $t4, 5($v0)
  sw    $a3, 0x2c($sp)
  sw    $v1, 0x1c($sp)
  xor   $t5, $t3, $t4
  jal   sub_GAME_7F0B7DA8
   xor   $a0, $t5, $a1
  lui   $t0, %hi(D_800448A0) 
  slti  $at, $v0, 9
  addiu $t0, %lo(D_800448A0) # addiu $t0, $t0, 0x48a0
  lw    $v1, 0x1c($sp)
  beqz  $at, .L7F0B7ED4
   lw    $a3, 0x2c($sp)
.L7F0B7E60:
  lw    $t7, 0x20($sp)
  lw    $v0, 0x30($sp)
  li    $at, 500
  sw    $t7, ($v1)
  lw    $t8, 0x24($sp)
  lui   $t3, %hi(D_800448A4) 
  sw    $t8, 4($v1)
  lw    $t1, 0x28($sp)
  sw    $a3, 0xc($v1)
  sw    $t1, 8($v1)
  lwc1  $f4, ($v0)
  swc1  $f4, 0x10($v1)
  lwc1  $f6, 4($v0)
  swc1  $f6, 0x14($v1)
  lwc1  $f8, 8($v0)
  swc1  $f8, 0x18($v1)
  lwc1  $f10, 0xc($v0)
  swc1  $f10, 0x1c($v1)
  lw    $t9, ($t0)
  addiu $a0, $t9, 1
  bne   $a0, $at, .L7F0B7EC0
   sw    $a0, ($t0)
  sw    $zero, ($t0)
  move  $a0, $zero
.L7F0B7EC0:
  lw    $t3, %lo(D_800448A4)($t3)
  addiu $t4, $a0, -1
  bnel  $t3, $a0, .L7F0B7ED8
   lw    $ra, 0x14($sp)
  sw    $t4, ($t0)
.L7F0B7ED4:
  lw    $ra, 0x14($sp)
.L7F0B7ED8:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B7EE4
  addiu $sp, $sp, -0x28
  lui   $v1, %hi(D_800448A4)
  addiu $v1, %lo(D_800448A4) # addiu $v1, $v1, 0x48a4
  lui   $t8, %hi(D_800448A0) 
  lw    $t8, %lo(D_800448A0)($t8)
  lw    $t0, ($v1)
  sw    $ra, 0x1c($sp)
  sw    $a0, 0x28($sp)
  lw    $t7, ($a0)
  sll   $t9, $t0, 5
  bne   $t8, $t0, .L7F0B7F1C
   sw    $t7, 0x20($sp)
  b     .L7F0B7F74
   move  $v0, $zero
.L7F0B7F1C:
  lui   $t1, %hi(dword_CODE_bss_8007C100) 
  addiu $t1, %lo(dword_CODE_bss_8007C100) # addiu $t1, $t1, -0x3f00
  addu  $v0, $t9, $t1
  lw    $a1, 4($v0)
  lw    $a2, 8($v0)
  lw    $a3, 0xc($v0)
  addiu $t2, $v0, 0x10
  sw    $t2, 0x10($sp)
  jal   sub_GAME_7F0B7F84
   lw    $a0, 0x20($sp)
  lui   $v1, %hi(D_800448A4)
  addiu $v1, %lo(D_800448A4) # addiu $v1, $v1, 0x48a4
  lw    $t3, ($v1)
  li    $at, 500
  move  $a0, $v0
  addiu $t4, $t3, 1
  bne   $t4, $at, .L7F0B7F68
   sw    $t4, ($v1)
  sw    $zero, ($v1)
.L7F0B7F68:
  lw    $t6, 0x28($sp)
  li    $v0, 1
  sw    $a0, ($t6)
.L7F0B7F74:
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B7F84
  addiu $sp, $sp, -0x80
  lui   $v0, %hi(D_80044898)
  addiu $v0, %lo(D_80044898) # addiu $v0, $v0, 0x4898
  lw    $t6, ($v0)
  sw    $s4, 0x30($sp)
  sw    $s3, 0x2c($sp)
  sw    $s2, 0x28($sp)
  slti  $at, $a3, 0x65
  addiu $t7, $t6, 1
  move  $s2, $a0
  move  $s3, $a3
  move  $s4, $a2
  sw    $ra, 0x34($sp)
  sw    $s1, 0x24($sp)
  sw    $s0, 0x20($sp)
  sw    $a1, 0x84($sp)
  bnez  $at, .L7F0B7FD4
   sw    $t7, ($v0)
  b     .L7F0B8354
   move  $v0, $a0
.L7F0B7FD4:
  lui   $t8, %hi(D_8004489C) 
  lw    $t8, %lo(D_8004489C)($t8)
  slt   $at, $t8, $s3
  beql  $at, $zero, .L7F0B7FF4
   slti  $at, $s3, 0x10
  b     .L7F0B8354
   move  $v0, $s2
  slti  $at, $s3, 0x10
.L7F0B7FF4:
  bnez  $at, .L7F0B8004
   lui   $t9, %hi(ptr_bgdata_portals) 
  b     .L7F0B8354
   move  $v0, $s2
.L7F0B8004:
  lw    $t9, %lo(ptr_bgdata_portals)($t9)
  sll   $v0, $s4, 3
  lui   $t3, %hi(D_800442FC) 
  addu  $t0, $t9, $v0
  lbu   $t1, 6($t0)
  addiu $t3, %lo(D_800442FC) # addiu $t3, $t3, 0x42fc
  addu  $v1, $s4, $t3
  andi  $t2, $t1, 1
  beql  $t2, $zero, .L7F0B8038
   sw    $v0, 0x44($sp)
  b     .L7F0B8354
   move  $v0, $s2
  sw    $v0, 0x44($sp)
.L7F0B8038:
  jal   get_BONDdata_position
   sw    $v1, 0x3c($sp)
  move  $s0, $v0
  move  $a0, $s4
  jal   sub_GAME_7F0B96CC
   addiu $a1, $sp, 0x54
  lwc1  $f4, 0x54($sp)
  lwc1  $f6, ($s0)
  lwc1  $f10, 0x58($sp)
  lwc1  $f16, 4($s0)
  mul.s $f8, $f4, $f6
  lwc1  $f6, 8($s0)
  lui   $at, %hi(room_data_float1)
  mul.s $f18, $f10, $f16
  lwc1  $f10, 0x5c($sp)
  move  $a0, $s4
  mul.s $f16, $f6, $f10
  add.s $f4, $f8, $f18
  lwc1  $f18, %lo(room_data_float1)($at)
  add.s $f8, $f16, $f4
  mul.s $f2, $f8, $f18
  jal   sub_GAME_7F0B9990
   swc1  $f2, 0x50($sp)
  lui   $t4, %hi(ptr_bgdata_portals) 
  lw    $t4, %lo(ptr_bgdata_portals)($t4)
  lw    $t5, 0x44($sp)
  lw    $t6, 0x84($sp)
  lwc1  $f2, 0x50($sp)
  addu  $v0, $t4, $t5
  lbu   $v1, 4($v0)
  bnel  $t6, $v1, .L7F0B80E0
   add.s $f4, $f2, $f0
  sub.s $f6, $f2, $f0
  lwc1  $f10, 0x64($sp)
  lbu   $s1, 5($v0)
  c.le.s $f10, $f6
  nop   
  bc1fl .L7F0B8104
   lwc1  $f8, 0x60($sp)
  b     .L7F0B8354
   move  $v0, $s2
  add.s $f4, $f2, $f0
.L7F0B80E0:
  lwc1  $f16, 0x60($sp)
  move  $s1, $v1
  c.le.s $f4, $f16
  nop   
  bc1fl .L7F0B8104
   lwc1  $f8, 0x60($sp)
  b     .L7F0B8354
   move  $v0, $s2
  lwc1  $f8, 0x60($sp)
.L7F0B8104:
  lwc1  $f6, 0x64($sp)
  sub.s $f18, $f8, $f0
  c.lt.s $f18, $f2
  nop   
  bc1fl .L7F0B8160
   lbu   $t7, 6($v0)
  add.s $f10, $f6, $f0
  c.lt.s $f2, $f10
  nop   
  bc1fl .L7F0B8160
   lbu   $t7, 6($v0)
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lwc1  $f16, 0x1118($v0)
  swc1  $f16, 0x70($sp)
  lwc1  $f4, 0x111c($v0)
  swc1  $f4, 0x74($sp)
  lwc1  $f8, 0x1120($v0)
  swc1  $f8, 0x78($sp)
  lwc1  $f18, 0x1124($v0)
  b     .L7F0B8260
   swc1  $f18, 0x7c($sp)
  lbu   $t7, 6($v0)
.L7F0B8160:
  addiu $a1, $sp, 0x70
  move  $a0, $s4
  andi  $t8, $t7, 2
  beqz  $t8, .L7F0B81F4
   nop   
  jal   sub_GAME_7F0B5864
   move  $a0, $s4
  bnez  $v0, .L7F0B818C
   lui   $t9, %hi(ptr_bgdata_portals) 
  b     .L7F0B8354
   move  $v0, $s2
.L7F0B818C:
  lw    $t9, %lo(ptr_bgdata_portals)($t9)
  lw    $t0, 0x44($sp)
  lw    $t4, 0x84($sp)
  addiu $a1, $sp, 0x70
  addu  $v0, $t9, $t0
  lbu   $t1, 5($v0)
  lbu   $t2, 4($v0)
  xor   $t3, $t1, $t2
  xor   $s1, $t3, $t4
  jal   sub_GAME_7F0B5208
   move  $a0, $s1
  bnez  $v0, .L7F0B81C8
   nop   
  b     .L7F0B8354
   move  $v0, $s2
.L7F0B81C8:
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  lwc1  $f6, 0x1118($v0)
  swc1  $f6, 0x70($sp)
  lwc1  $f10, 0x111c($v0)
  swc1  $f10, 0x74($sp)
  lwc1  $f16, 0x1120($v0)
  swc1  $f16, 0x78($sp)
  lwc1  $f4, 0x1124($v0)
  b     .L7F0B8228
   swc1  $f4, 0x7c($sp)
.L7F0B81F4:
  jal   sub_GAME_7F0B5864
   addiu $a1, $sp, 0x70
  bnez  $v0, .L7F0B820C
   addiu $a0, $sp, 0x70
  b     .L7F0B8354
   move  $v0, $s2
.L7F0B820C:
  jal   vis_is_inline_of_sight
   lw    $a1, 0x90($sp)
  lui   $a1, %hi(pPlayer)
  lw    $a1, %lo(pPlayer)($a1)
  addiu $a0, $sp, 0x70
  jal   vis_is_inline_of_sight
   addiu $a1, $a1, 0x1118
.L7F0B8228:
  lwc1  $f8, 0x70($sp)
  lwc1  $f18, 0x78($sp)
  lwc1  $f6, 0x74($sp)
  lwc1  $f10, 0x7c($sp)
  c.le.s $f18, $f8
  nop   
  bc1t  .L7F0B8258
   nop   
  c.le.s $f10, $f6
  nop   
  bc1fl .L7F0B8264
   lw    $t5, 0x3c($sp)
.L7F0B8258:
  b     .L7F0B8354
   move  $v0, $s2
.L7F0B8260:
  lw    $t5, 0x3c($sp)
.L7F0B8264:
  sb    $s3, ($t5)
  lwc1  $f4, 0x78($sp)
  lwc1  $f16, 0x70($sp)
  lwc1  $f18, 0x7c($sp)
  lwc1  $f8, 0x74($sp)
  c.lt.s $f16, $f4
  nop   
  bc1f  .L7F0B82D0
   nop   
  c.lt.s $f8, $f18
  lui   $t6, %hi(ptr_bgdata_portals) 
  lw    $t7, 0x44($sp)
  bc1f  .L7F0B82D0
   nop   
  lw    $t6, %lo(ptr_bgdata_portals)($t6)
  move  $a0, $s1
  move  $a1, $s3
  addu  $t8, $t6, $t7
  lbu   $a3, 6($t8)
  addiu $a2, $sp, 0x70
  andi  $t9, $a3, 2
  jal   sub_GAME_7F0B39BC
   move  $a3, $t9
  beqz  $v0, .L7F0B82D8
   lui   $a0, %hi(ptr_bgdata_portals)
  b     .L7F0B8354
   move  $v0, $s2
.L7F0B82D0:
  b     .L7F0B8354
   move  $v0, $s2
.L7F0B82D8:
  lw    $a0, %lo(ptr_bgdata_portals)($a0)
  move  $s0, $zero
  move  $v1, $zero
  lw    $t0, ($a0)
  move  $v0, $a0
  beql  $t0, $zero, .L7F0B8354
   move  $v0, $s2
.L7F0B82F4:
  beql  $s0, $s4, .L7F0B8340
   lw    $t5, 8($v0)
  lbu   $t1, 4($v0)
  move  $a0, $s2
  move  $a1, $s1
  beq   $s1, $t1, .L7F0B8318
   move  $a2, $s0
  lbu   $t2, 5($v0)
  bne   $s1, $t2, .L7F0B833C
.L7F0B8318:
   addiu $t3, $sp, 0x70
  sw    $t3, 0x10($sp)
  addiu $a3, $s3, 1
  jal   sub_GAME_7F0B7DE4
   sw    $v1, 0x40($sp)
  lui   $t4, %hi(ptr_bgdata_portals) 
  lw    $t4, %lo(ptr_bgdata_portals)($t4)
  lw    $v1, 0x40($sp)
  addu  $v0, $t4, $v1
.L7F0B833C:
  lw    $t5, 8($v0)
.L7F0B8340:
  addiu $s0, $s0, 1
  addiu $v1, $v1, 8
  bnez  $t5, .L7F0B82F4
   addiu $v0, $v0, 8
  move  $v0, $s2
.L7F0B8354:
  lw    $ra, 0x34($sp)
  lw    $s0, 0x20($sp)
  lw    $s1, 0x24($sp)
  lw    $s2, 0x28($sp)
  lw    $s3, 0x2c($sp)
  lw    $s4, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x80
");

asm(R"
glabel push_arg_to_table
  lui   $a1, %hi(D_800448F8)
  addiu $a1, %lo(D_800448F8) # addiu $a1, $a1, 0x48f8
  lw    $v1, ($a1)
  lui   $at, %hi(D_800448A8)
  move  $v0, $a0
  sll   $t6, $v1, 2
  addu  $at, $at, $t6
  sw    $a0, %lo(D_800448A8)($at)
  li    $at, 20
  addiu $t7, $v1, 1
  div   $zero, $t7, $at
  mfhi  $t8
  sw    $t8, ($a1)
  jr    $ra
   nop   
");

asm(R"
glabel pull_arg_from_stack
  lui   $a0, %hi(D_800448F8)
  addiu $a0, %lo(D_800448F8) # addiu $a0, $a0, 0x48f8
  lw    $t6, ($a0)
  li    $at, 20
  lui   $v1, %hi(D_800448A8)
  addiu $t7, $t6, 0x13
  div   $zero, $t7, $at
  mfhi  $t8
  sll   $t0, $t8, 2
  addu  $v1, $v1, $t0
  sw    $t8, ($a0)
  jr    $ra
   lw    $v0, %lo(D_800448A8)($v1)
");

asm(R"
glabel sub_GAME_7F0B83E4
  lui   $t6, %hi(D_800448F8) 
  lw    $t6, %lo(D_800448F8)($t6)
  li    $at, 20
  lui   $v0, %hi(D_800448A8)
  subu  $t7, $t6, $a0
  addiu $t8, $t7, 0x13
  div   $zero, $t8, $at
  mfhi  $t9
  sll   $t0, $t9, 2
  addu  $v0, $v0, $t0
  jr    $ra
   lw    $v0, %lo(D_800448A8)($v0)
");

asm(R"
.late_rodata
/*D:80058C80*/
glabel jpt_80058C80
.word if_statement
.word dont_exec_commands_even_on_return
.word endif_continue_exec
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word if_statement_pull_from_stack
.word toggle_exec_vs_ro
.word endif

/*D:80058CB4*/
glabel vis_command_jpt
.word break
.word push_to_stack
.word pull_from_stack
.word and_merge_last_two_on_stack
.word or_merge_last_two_on_stack
.word not_merge_last_two_on_stack
.word carrot_merge_last_two_on_stack
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word push_tf_if_in_range_rooms
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word invalid_type_terminate
.word force_visible
.word match_portal_vis
.word add_visible_room
.word remove_vis
.word visible_if_seen_through_portal
.word not_visible_if_seen_through_portal
.word disable_room
.word disable_room_range
.word preload_room
.word preload_room_range
.text
glabel parse_global_vis_command_list
  addiu $sp, $sp, -0x80
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  lui   $at, %hi(dword_CODE_bss_80081600 + 0x10)
  move  $s1, $a0
  move  $s2, $a1
  sw    $ra, 0x3c($sp)
  sw    $fp, 0x38($sp)
  sw    $s7, 0x34($sp)
  sw    $s6, 0x30($sp)
  sw    $s5, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s0, 0x18($sp)
  li    $s3, 1
  bnez  $a0, .L7F0B8460
   sw    $zero, %lo(dword_CODE_bss_80081600 + 0x10)($at)
  b     .L7F0B89F4
   move  $v0, $a0
.L7F0B8460:
  lui   $fp, %hi(pPlayer) 
  lui   $s6, %hi(dword_CODE_bss_80081600)
  lui   $s4, %hi(current_visibility)
  addiu $s4, %lo(current_visibility) # addiu $s4, $s4, 0x48fc
  addiu $s6, %lo(dword_CODE_bss_80081600) # addiu $s6, $s6, 0x1600
  addiu $fp, %lo(pPlayer) # addiu $fp, $fp, -0x5f50
  li    $s7, 1
  li    $s5, 1
.L7F0B8480:
  lbu   $a0, ($s1)
.L7F0B8484:
  slti  $at, $a0, 0x28
  bnez  $at, .L7F0B84B0
   addiu $t6, $a0, -0x50
  sltiu $at, $t6, 0xd
  beqz  $at, .L7F0B89F0
   sll   $t6, $t6, 2
  lui   $at, %hi(jpt_80058C80)
  addu  $at, $at, $t6
  lw    $t6, %lo(jpt_80058C80)($at)
  jr    $t6
   nop   
.L7F0B84B0:
  sltiu $at, $a0, 0x28
  beqz  $at, .L7F0B89F0
   sll   $t7, $a0, 2
  lui   $at, %hi(vis_command_jpt)
  addu  $at, $at, $t7
  lw    $t7, %lo(vis_command_jpt)($at)
  jr    $t7
   nop   
break:
  b     .L7F0B89F4
   move  $v0, $s1
push_to_stack:
  beql  $s2, $zero, .L7F0B84EC
   lbu   $t8, 1($s1)
  jal   push_arg_to_table
   lw    $a0, 4($s1)
  lbu   $t8, 1($s1)
.L7F0B84EC:
  sll   $t9, $t8, 3
  b     .L7F0B8480
   addu  $s1, $s1, $t9
pull_from_stack:
  beql  $s2, $zero, .L7F0B850C
   lbu   $t0, 1($s1)
  jal   pull_arg_from_stack
   nop   
  lbu   $t0, 1($s1)
.L7F0B850C:
  sll   $t1, $t0, 3
  b     .L7F0B8480
   addu  $s1, $s1, $t1
and_merge_last_two_on_stack:
  beql  $s2, $zero, .L7F0B853C
   lbu   $t2, 1($s1)
  jal   pull_arg_from_stack
   nop   
  jal   pull_arg_from_stack
   move  $s0, $v0
  jal   push_arg_to_table
   and   $a0, $v0, $s0
  lbu   $t2, 1($s1)
.L7F0B853C:
  sll   $t3, $t2, 3
  b     .L7F0B8480
   addu  $s1, $s1, $t3
or_merge_last_two_on_stack:
  beql  $s2, $zero, .L7F0B856C
   lbu   $t4, 1($s1)
  jal   pull_arg_from_stack
   nop   
  jal   pull_arg_from_stack
   move  $s0, $v0
  jal   push_arg_to_table
   or    $a0, $v0, $s0
  lbu   $t4, 1($s1)
.L7F0B856C:
  sll   $t5, $t4, 3
  b     .L7F0B8480
   addu  $s1, $s1, $t5
not_merge_last_two_on_stack:
  beql  $s2, $zero, .L7F0B8594
   lbu   $t6, 1($s1)
  jal   pull_arg_from_stack
   nop   
  jal   push_arg_to_table
   sltiu $a0, $v0, 1
  lbu   $t6, 1($s1)
.L7F0B8594:
  sll   $t7, $t6, 3
  b     .L7F0B8480
   addu  $s1, $s1, $t7
carrot_merge_last_two_on_stack:
  beql  $s2, $zero, .L7F0B85C4
   lbu   $t8, 1($s1)
  jal   pull_arg_from_stack
   nop   
  jal   pull_arg_from_stack
   move  $s0, $v0
  jal   push_arg_to_table
   xor   $a0, $v0, $s0
  lbu   $t8, 1($s1)
.L7F0B85C4:
  sll   $t9, $t8, 3
  b     .L7F0B8480
   addu  $s1, $s1, $t9
push_tf_if_in_range_rooms:
  beqz  $s2, .L7F0B8604
   lui   $v0, %hi(current_room_maybe)
  lw    $v0, %lo(current_room_maybe)($v0)
  lw    $t0, 0xc($s1)
  slt   $a0, $v0, $t0
  xori  $a0, $a0, 1
  beqz  $a0, .L7F0B85FC
   nop   
  lw    $t1, 0x14($s1)
  slt   $a0, $t1, $v0
  xori  $a0, $a0, 1
.L7F0B85FC:
  jal   push_arg_to_table
   nop   
.L7F0B8604:
  lbu   $t2, 1($s1)
  sll   $t3, $t2, 3
  b     .L7F0B8480
   addu  $s1, $s1, $t3
force_visible:
  beql  $s2, $zero, .L7F0B8648
   lbu   $t4, 1($s1)
  lw    $v0, ($fp)
  lwc1  $f4, 0x1118($v0)
  swc1  $f4, ($s6)
  lwc1  $f6, 0x111c($v0)
  swc1  $f6, 4($s6)
  lwc1  $f8, 0x1120($v0)
  swc1  $f8, 8($s6)
  lwc1  $f10, 0x1124($v0)
  sw    $zero, ($s4)
  swc1  $f10, 0xc($s6)
  lbu   $t4, 1($s1)
.L7F0B8648:
  sll   $t5, $t4, 3
  b     .L7F0B8480
   addu  $s1, $s1, $t5
match_portal_vis:
  beqz  $s2, .L7F0B8698
   move  $a1, $s6
  jal   sub_GAME_7F0B5864
   lw    $a0, 0xc($s1)
  bnezl $v0, .L7F0B8678
   lw    $a1, ($fp)
  b     .L7F0B8698
   sw    $s7, ($s4)
  lw    $a1, ($fp)
.L7F0B8678:
  move  $a0, $s6
  jal   vis_is_inline_of_sight
   addiu $a1, $a1, 0x1118
  bnezl $v0, .L7F0B8698
   sw    $zero, ($s4)
  b     .L7F0B8698
   sw    $s7, ($s4)
  sw    $zero, ($s4)
.L7F0B8698:
  lbu   $t6, 1($s1)
  sll   $t7, $t6, 3
  b     .L7F0B8480
   addu  $s1, $s1, $t7
visible_if_seen_through_portal:
  beqz  $s2, .L7F0B8704
   addiu $a1, $sp, 0x68
  jal   sub_GAME_7F0B5864
   lw    $a0, 0xc($s1)
  beql  $v0, $zero, .L7F0B8708
   lbu   $t9, 1($s1)
  lw    $a1, ($fp)
  addiu $a0, $sp, 0x68
  jal   vis_is_inline_of_sight
   addiu $a1, $a1, 0x1118
  beql  $v0, $zero, .L7F0B8708
   lbu   $t9, 1($s1)
  lw    $t8, ($s4)
  addiu $a1, $sp, 0x68
  move  $a0, $s6
  beqz  $t8, .L7F0B86FC
   nop   
  jal   copy_4_floats_a1_to_a0
   move  $a0, $s6
  b     .L7F0B8704
   sw    $zero, ($s4)
.L7F0B86FC:
  jal   sub_GAME_7F0B5CC0
   addiu $a1, $sp, 0x68
.L7F0B8704:
  lbu   $t9, 1($s1)
.L7F0B8708:
  sll   $t0, $t9, 3
  b     .L7F0B8480
   addu  $s1, $s1, $t0
not_visible_if_seen_through_portal:
  beql  $s2, $zero, .L7F0B877C
   lbu   $t2, 1($s1)
  lw    $t1, ($s4)
  addiu $a1, $sp, 0x58
  bnezl $t1, .L7F0B877C
   lbu   $t2, 1($s1)
  jal   sub_GAME_7F0B5864
   lw    $a0, 0xc($s1)
  bnezl $v0, .L7F0B8748
   lw    $a1, ($fp)
  b     .L7F0B8778
   sw    $s7, ($s4)
  lw    $a1, ($fp)
.L7F0B8748:
  addiu $a0, $sp, 0x58
  jal   vis_is_inline_of_sight
   addiu $a1, $a1, 0x1118
  bnez  $v0, .L7F0B8764
   move  $a0, $s6
  b     .L7F0B8778
   sw    $s7, ($s4)
.L7F0B8764:
  jal   vis_is_inline_of_sight
   addiu $a1, $sp, 0x58
  bnezl $v0, .L7F0B877C
   lbu   $t2, 1($s1)
  sw    $s7, ($s4)
.L7F0B8778:
  lbu   $t2, 1($s1)
.L7F0B877C:
  sll   $t3, $t2, 3
  b     .L7F0B8480
   addu  $s1, $s1, $t3
add_visible_room:
  beql  $s2, $zero, .L7F0B87E8
   lbu   $t7, 1($s1)
  lw    $t4, ($s4)
  move  $a1, $s6
  bnezl $t4, .L7F0B87E8
   lbu   $t7, 1($s1)
  jal   sub_GAME_7F0B5208
   lw    $a0, 0xc($s1)
  beqz  $v0, .L7F0B87E4
   move  $a1, $zero
  lw    $a0, 0xc($s1)
  move  $a2, $s6
  jal   sub_GAME_7F0B39BC
   move  $a3, $zero
  lui   $v1, %hi(num_visible_rooms_in_cur_global_vis_packet)
  lw    $v1, %lo(num_visible_rooms_in_cur_global_vis_packet)($v1)
  lw    $t5, 0xc($s1)
  lui   $at, %hi(list_visible_rooms_in_cur_global_vis_packet)
  addu  $at, $at, $v1
  sb    $t5, %lo(list_visible_rooms_in_cur_global_vis_packet)($at)
  lui   $at, %hi(num_visible_rooms_in_cur_global_vis_packet)
  addiu $t6, $v1, 1
  sw    $t6, %lo(num_visible_rooms_in_cur_global_vis_packet)($at)
.L7F0B87E4:
  lbu   $t7, 1($s1)
.L7F0B87E8:
  sll   $t8, $t7, 3
  b     .L7F0B8480
   addu  $s1, $s1, $t8
disable_room:
  beql  $s2, $zero, .L7F0B881C
   lbu   $t1, 1($s1)
  lw    $t9, 0xc($s1)
  lui   $at, %hi(array_room_info + 0x10 +0x24)
  sll   $t0, $t9, 2
  addu  $t0, $t0, $t9
  sll   $t0, $t0, 4
  addu  $at, $at, $t0
  sb    $s5, %lo(array_room_info + 0x10 +0x24)($at)
  lbu   $t1, 1($s1)
.L7F0B881C:
  sll   $t2, $t1, 3
  b     .L7F0B8480
   addu  $s1, $s1, $t2
disable_room_range:
  beql  $s2, $zero, .L7F0B8878
   lbu   $t7, 1($s1)
  lw    $v0, 0xc($s1)
  lw    $t3, 0x14($s1)
  lui   $t5, %hi(array_room_info) 
  sll   $t4, $v0, 2
  slt   $at, $t3, $v0
  bnez  $at, .L7F0B8874
   addu  $t4, $t4, $v0
  sll   $t4, $t4, 4
  addiu $t5, %lo(array_room_info) # addiu $t5, $t5, 0x1414
  addu  $v1, $t4, $t5
  sb    $s5, 0x34($v1)
.L7F0B885C:
  lw    $t6, 0x14($s1)
  addiu $v0, $v0, 1
  addiu $v1, $v1, 0x50
  slt   $at, $t6, $v0
  beql  $at, $zero, .L7F0B885C
   sb    $s5, 0x34($v1)
.L7F0B8874:
  lbu   $t7, 1($s1)
.L7F0B8878:
  sll   $t8, $t7, 3
  b     .L7F0B8480
   addu  $s1, $s1, $t8
preload_room:
  beql  $s2, $zero, .L7F0B88AC
   lbu   $t0, 1($s1)
  beql  $s3, $zero, .L7F0B88AC
   lbu   $t0, 1($s1)
  jal   sub_GAME_7F0B6314
   lw    $a0, 0xc($s1)
  sltiu $s3, $v0, 1
  andi  $t9, $s3, 0xff
  move  $s3, $t9
  lbu   $t0, 1($s1)
.L7F0B88AC:
  sll   $t1, $t0, 3
  b     .L7F0B8480
   addu  $s1, $s1, $t1
preload_room_range:
  beql  $s2, $zero, .L7F0B8908
   lbu   $t3, 1($s1)
  lw    $s0, 0xc($s1)
  lw    $v1, 0x14($s1)
  slt   $at, $v1, $s0
  bnezl $at, .L7F0B8908
   lbu   $t3, 1($s1)
.L7F0B88D4:
  beql  $s3, $zero, .L7F0B88F8
   addiu $s0, $s0, 1
  jal   sub_GAME_7F0B6314
   move  $a0, $s0
  sltiu $s3, $v0, 1
  andi  $t2, $s3, 0xff
  move  $s3, $t2
  lw    $v1, 0x14($s1)
  addiu $s0, $s0, 1
.L7F0B88F8:
  slt   $at, $v1, $s0
  beqz  $at, .L7F0B88D4
   nop   
  lbu   $t3, 1($s1)
.L7F0B8908:
  sll   $t4, $t3, 3
  b     .L7F0B8480
   addu  $s1, $s1, $t4
remove_vis:
  beql  $s2, $zero, .L7F0B8924
   lbu   $t5, 1($s1)
  sw    $s7, ($s4)
  lbu   $t5, 1($s1)
.L7F0B8924:
  sll   $t6, $t5, 3
  b     .L7F0B8480
   addu  $s1, $s1, $t6
if_statement:
  lbu   $t7, 1($s1)
  move  $a1, $s2
  sll   $t8, $t7, 3
  jal   parse_global_vis_command_list
   addu  $a0, $t8, $s1
  lbu   $t9, 1($v0)
  sll   $t0, $t9, 3
  b     .L7F0B8480
   addu  $s1, $v0, $t0
endif_continue_exec:
  lbu   $t1, 1($s1)
  lui   $at, %hi(dword_CODE_bss_80081600 + 0x10)
  sw    $zero, %lo(dword_CODE_bss_80081600 + 0x10)($at)
  sll   $t2, $t1, 3
  b     .L7F0B89F4
   addu  $v0, $s1, $t2
dont_exec_commands_even_on_return:
  lbu   $t3, 1($s1)
  sltu  $v0, $zero, $s2
  move  $s2, $zero
  sll   $t4, $t3, 3
  beqz  $v0, .L7F0B8480
   addu  $s1, $s1, $t4
  lui   $at, %hi(dword_CODE_bss_80081600 + 0x10)
  b     .L7F0B8480
   sw    $s7, %lo(dword_CODE_bss_80081600 + 0x10)($at)
if_statement_pull_from_stack:
  jal   pull_arg_from_stack
   nop   
  lbu   $t5, 1($s1)
  and   $a1, $v0, $s2
  sll   $t6, $t5, 3
  jal   parse_global_vis_command_list
   addu  $a0, $t6, $s1
  lui   $t7, %hi(dword_CODE_bss_80081600 + 0x10) 
  lw    $t7, %lo(dword_CODE_bss_80081600 + 0x10)($t7)
  move  $s1, $v0
  beql  $t7, $zero, .L7F0B8484
   lbu   $a0, ($s1)
  b     .L7F0B8480
   move  $s2, $zero
toggle_exec_vs_ro:
  lbu   $t9, 1($s1)
  xori  $t8, $s2, 1
  move  $s2, $t8
  sll   $t0, $t9, 3
  b     .L7F0B8480
   addu  $s1, $s1, $t0
endif:
  lbu   $t1, 1($s1)
  sll   $t2, $t1, 3
  b     .L7F0B89F4
   addu  $v0, $s1, $t2
invalid_type_terminate:
.L7F0B89F0:
  move  $v0, $s1
.L7F0B89F4:
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
   addiu $sp, $sp, 0x80
");

asm(R"
glabel sub_GAME_7F0B8A24
  addiu $sp, $sp, -0x18
  lui   $at, %hi(current_visibility)
  sw    $ra, 0x14($sp)
  move  $a2, $a0
  bnez  $a0, .L7F0B8A44
   sw    $zero, %lo(current_visibility)($at)
  b     .L7F0B8A5C
   move  $v0, $a0
.L7F0B8A44:
  move  $a0, $zero
  jal   sub_GAME_7F0B83E4
   sw    $a2, 0x18($sp)
  lw    $a0, 0x18($sp)
  jal   parse_global_vis_command_list
   li    $a1, 1
.L7F0B8A5C:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B8A6C
  addiu $sp, $sp, -0x60
  sw    $ra, 0x24($sp)
  sw    $s1, 0x20($sp)
  jal   sub_GAME_7F0B908C
   sw    $s0, 0x1c($sp)
  lui   $s1, %hi(pPlayer)
  addiu $s1, %lo(pPlayer) # addiu $s1, $s1, -0x5f50
  lw    $v0, ($s1)
  lwc1  $f4, 0x1118($v0)
  swc1  $f4, 0x50($sp)
  lwc1  $f6, 0x111c($v0)
  swc1  $f6, 0x54($sp)
  lwc1  $f8, 0x1120($v0)
  swc1  $f8, 0x58($sp)
  lwc1  $f10, 0x1124($v0)
  jal   sub_GAME_7F0B3BC4
   swc1  $f10, 0x5c($sp)
  lui   $v0, %hi(array_room_info)
  lui   $v1, %hi(MaxNumRooms)
  addiu $v1, %lo(MaxNumRooms) # addiu $v1, $v1, 0x42f4
  addiu $v0, %lo(array_room_info) # addiu $v0, $v0, 0x1414
.L7F0B8AC0:
  addiu $v0, $v0, 0x50
  sltu  $at, $v0, $v1
  sb    $zero, -0x50($v0)
  sb    $zero, -0x4f($v0)
  bnez  $at, .L7F0B8AC0
   sb    $zero, -0x1c($v0)
  lui   $v0, %hi(D_800442FC)
  lui   $v1, %hi(D_800443C4)
  addiu $v1, %lo(D_800443C4) # addiu $v1, $v1, 0x43c4
  addiu $v0, %lo(D_800442FC) # addiu $v0, $v0, 0x42fc
.L7F0B8AE8:
  addiu $v0, $v0, 4
  sb    $zero, -3($v0)
  sb    $zero, -2($v0)
  sb    $zero, -1($v0)
  bne   $v0, $v1, .L7F0B8AE8
   sb    $zero, -4($v0)
  lui   $v0, %hi(D_80044858)
  addiu $v0, %lo(D_80044858) # addiu $v0, $v0, 0x4858
  lw    $t6, ($v0)
  li    $at, 10
  addiu $t7, $t6, 1
  div   $zero, $t7, $at
  mfhi  $t8
  sw    $t8, ($v0)
  lui   $at, %hi(dword_CODE_bss_8007FF98)
  sw    $zero, %lo(dword_CODE_bss_8007FF98)($at)
  lui   $at, %hi(D_80044898)
  jal   sub_GAME_7F0B7D94
   sw    $zero, %lo(D_80044898)($at)
  jal   sub_GAME_7F0B5168
   nop   
  lui   $a0, %hi(dword_CODE_bss_8007FF90)
  jal   sub_GAME_7F0B8A24
   lw    $a0, %lo(dword_CODE_bss_8007FF90)($a0)
  lui   $v0, %hi(D_80041400)
  lw    $v0, %lo(D_80041400)($v0)
  li    $v1, 21
  lui   $t9, %hi(ptr_bgdata_portals) 
  beq   $v1, $v0, .L7F0B8B70
   nop   
  lw    $t9, %lo(ptr_bgdata_portals)($t9)
  lw    $t2, ($t9)
  bnez  $t2, .L7F0B8BF8
   nop   
.L7F0B8B70:
  bne   $v1, $v0, .L7F0B8B8C
   li    $a0, 9
  lw    $a2, ($s1)
  move  $a1, $zero
  li    $a3, 1
  jal   sub_GAME_7F0B39BC
   addiu $a2, $a2, 0x1118
.L7F0B8B8C:
  lui   $t3, %hi(MaxNumRooms) 
  lw    $t3, %lo(MaxNumRooms)($t3)
  li    $s0, 1
  slti  $at, $t3, 2
  bnez  $at, .L7F0B8BE8
   nop   
  lw    $a1, ($s1)
.L7F0B8BA8:
  move  $a0, $s0
  jal   sub_GAME_7F0B5208
   addiu $a1, $a1, 0x1118
  beqz  $v0, .L7F0B8BD0
   move  $a0, $s0
  lw    $a2, ($s1)
  move  $a1, $zero
  li    $a3, 1
  jal   sub_GAME_7F0B39BC
   addiu $a2, $a2, 0x1118
.L7F0B8BD0:
  lui   $t4, %hi(MaxNumRooms) 
  lw    $t4, %lo(MaxNumRooms)($t4)
  addiu $s0, $s0, 1
  slt   $at, $s0, $t4
  bnezl $at, .L7F0B8BA8
   lw    $a1, ($s1)
.L7F0B8BE8:
  lui   $a0, %hi(ptr_bgdata_portals)
  lw    $a0, %lo(ptr_bgdata_portals)($a0)
  b     .L7F0B8CD8
   lw    $v0, ($a0)
.L7F0B8BF8:
  bne   $v1, $v0, .L7F0B8C14
   li    $a0, 9
  lw    $a2, ($s1)
  move  $a1, $zero
  li    $a3, 1
  jal   sub_GAME_7F0B39BC
   addiu $a2, $a2, 0x1118
.L7F0B8C14:
  lw    $a2, ($s1)
  lui   $a0, %hi(current_room_maybe)
  lw    $a0, %lo(current_room_maybe)($a0)
  move  $a1, $zero
  li    $a3, 1
  jal   sub_GAME_7F0B39BC
   addiu $a2, $a2, 0x1118
  lui   $a0, %hi(ptr_bgdata_portals)
  lw    $a0, %lo(ptr_bgdata_portals)($a0)
  move  $s0, $zero
  move  $v1, $zero
  lw    $t5, ($a0)
  move  $v0, $a0
  beqz  $t5, .L7F0B8CA4
.L7F0B8C4C:
   lui   $a1, %hi(current_room_maybe)
  lw    $a1, %lo(current_room_maybe)($a1)
  lbu   $t6, 4($v0)
  move  $a0, $zero
  move  $a2, $s0
  beq   $a1, $t6, .L7F0B8C70
   li    $a3, 1
  lbu   $t7, 5($v0)
  bne   $a1, $t7, .L7F0B8C90
.L7F0B8C70:
   addiu $t8, $sp, 0x50
  sw    $t8, 0x10($sp)
  jal   sub_GAME_7F0B7DE4
   sw    $v1, 0x34($sp)
  lui   $t9, %hi(ptr_bgdata_portals) 
  lw    $t9, %lo(ptr_bgdata_portals)($t9)
  lw    $v1, 0x34($sp)
  addu  $v0, $t9, $v1
.L7F0B8C90:
  lw    $t2, 8($v0)
  addiu $s0, $s0, 1
  addiu $v1, $v1, 8
  bnez  $t2, .L7F0B8C4C
   addiu $v0, $v0, 8
.L7F0B8CA4:
  addiu $s0, $sp, 0x44
  sw    $zero, 0x44($sp)
  jal   sub_GAME_7F0B7EE4
   move  $a0, $s0
  beqz  $v0, .L7F0B8CCC
   nop   
.L7F0B8CBC:
  jal   sub_GAME_7F0B7EE4
   move  $a0, $s0
  bnez  $v0, .L7F0B8CBC
   nop   
.L7F0B8CCC:
  lui   $a0, %hi(ptr_bgdata_portals)
  lw    $a0, %lo(ptr_bgdata_portals)($a0)
  lw    $v0, ($a0)
.L7F0B8CD8:
  beqz  $v0, .L7F0B8D64
   li    $t1, 1
  lui   $a3, %hi(array_room_info)
  addiu $a3, %lo(array_room_info) # addiu $a3, $a3, 0x1414
  move  $v0, $a0
  li    $t0, 80
  lbu   $v1, 4($v0)
.L7F0B8CF4:
  lbu   $a0, 5($v0)
  multu $v1, $t0
  mflo  $t3
  addu  $a1, $a3, $t3
  lbu   $a2, ($a1)
  beqz  $a2, .L7F0B8D30
   nop   
  multu $a0, $t0
  mflo  $t4
  addu  $v1, $a3, $t4
  lbu   $t5, ($v1)
  bnez  $t5, .L7F0B8D30
   nop   
  b     .L7F0B8D54
   sb    $t1, 1($v1)
.L7F0B8D30:
  multu $a0, $t0
  mflo  $t6
  addu  $t7, $a3, $t6
  lbu   $t8, ($t7)
  beql  $t8, $zero, .L7F0B8D58
   lw    $t9, 8($v0)
  bnezl $a2, .L7F0B8D58
   lw    $t9, 8($v0)
  sb    $t1, 1($a1)
.L7F0B8D54:
  lw    $t9, 8($v0)
.L7F0B8D58:
  addiu $v0, $v0, 8
  bnezl $t9, .L7F0B8CF4
   lbu   $v1, 4($v0)
.L7F0B8D64:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x60
");

asm(R"
glabel sub_GAME_7F0B8D78
  lui   $t6, %hi(D_80041400) 
  lw    $t6, %lo(D_80041400)($t6)
  addiu $sp, $sp, -0x18
  li    $at, 13
  sw    $ra, 0x14($sp)
  bne   $t6, $at, .L7F0B8DD4
   move  $a2, $a0
  lui   $a0, %hi(NumberOfRoomsDrawn)
  lw    $a0, %lo(NumberOfRoomsDrawn)($a0)
  lui   $v0, %hi(dword_CODE_bss_8007FFA0)
  addiu $v0, %lo(dword_CODE_bss_8007FFA0) # addiu $v0, $v0, -0x60
  blez  $a0, .L7F0B8DD4
   move  $v1, $zero
  li    $a1, 35
.L7F0B8DB0:
  lw    $t7, ($v0)
  addiu $v1, $v1, 1
  slt   $at, $v1, $a0
  bne   $a1, $t7, .L7F0B8DCC
   nop   
  b     .L7F0B8DD4
   sw    $zero, 4($v0)
.L7F0B8DCC:
  bnez  $at, .L7F0B8DB0
   addiu $v0, $v0, 0x1c
.L7F0B8DD4:
  jal   sub_GAME_7F0B3C8C
   move  $a0, $a2
  jal   sub_GAME_7F0B4FB4
   move  $a0, $v0
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B8DF4
  lui   $t0, %hi(ptr_bgdata_portals) 
  addiu $t0, %lo(ptr_bgdata_portals) # addiu $t0, $t0, -0x80
  lw    $a3, ($t0)
  addiu $sp, $sp, -0x10
  sw    $s1, 0xc($sp)
  sw    $s0, 8($sp)
  lw    $t6, ($a3)
  move  $s0, $a1
  move  $s1, $a2
  move  $v1, $zero
  beqz  $t6, .L7F0B8E84
   move  $v0, $zero
  move  $a1, $zero
  move  $a2, $a3
  lbu   $t7, 4($a2)
.L7F0B8E30:
  sll   $t9, $v1, 2
  addu  $t1, $s0, $t9
  beql  $a0, $t7, .L7F0B8E50
   sw    $v0, ($t1)
  lbu   $t8, 5($a2)
  bnel  $a0, $t8, .L7F0B8E58
   slt   $at, $v1, $s1
  sw    $v0, ($t1)
.L7F0B8E50:
  addiu $v1, $v1, 1
  slt   $at, $v1, $s1
.L7F0B8E58:
  bnezl $at, .L7F0B8E6C
   lw    $t2, ($t0)
  b     .L7F0B8E88
   move  $v0, $v1
  lw    $t2, ($t0)
.L7F0B8E6C:
  addiu $a1, $a1, 8
  addiu $v0, $v0, 1
  addu  $a2, $t2, $a1
  lw    $t3, ($a2)
  bnezl $t3, .L7F0B8E30
   lbu   $t7, 4($a2)
.L7F0B8E84:
  move  $v0, $v1
.L7F0B8E88:
  lw    $s0, 8($sp)
  lw    $s1, 0xc($sp)
  jr    $ra
   addiu $sp, $sp, 0x10
");

asm(R"
glabel sub_GAME_7F0B8E98
  lui   $a3, %hi(num_visible_rooms_in_cur_global_vis_packet)
  addiu $a3, %lo(num_visible_rooms_in_cur_global_vis_packet) # addiu $a3, $a3, -0x3fc8
  lw    $t6, ($a3)
  move  $v1, $zero
  blez  $t6, .L7F0B8EF4
   nop   
  blez  $a1, .L7F0B8EF4
   sll   $t7, $zero, 2
  lui   $t8, %hi(list_visible_rooms_in_cur_global_vis_packet) 
  addiu $t8, %lo(list_visible_rooms_in_cur_global_vis_packet) # addiu $t8, $t8, -0x4060
  addu  $a2, $zero, $t8
  addu  $v0, $a0, $t7
  lbu   $t9, ($a2)
.L7F0B8ECC:
  addiu $v1, $v1, 1
  addiu $v0, $v0, 4
  sw    $t9, -4($v0)
  lw    $t0, ($a3)
  addiu $a2, $a2, 1
  slt   $at, $v1, $t0
  beqz  $at, .L7F0B8EF4
   slt   $at, $v1, $a1
  bnezl $at, .L7F0B8ECC
   lbu   $t9, ($a2)
.L7F0B8EF4:
  jr    $ra
   move  $v0, $v1
");

asm(R"
glabel sub_GAME_7F0B8EFC
  addiu $sp, $sp, -0x10
  lui   $a3, %hi(ptr_bgdata_portals)
  lw    $a3, %lo(ptr_bgdata_portals)($a3)
  sw    $s2, 0xc($sp)
  sw    $s1, 8($sp)
  sw    $s0, 4($sp)
  lw    $t6, ($a3)
  move  $s0, $a0
  move  $s1, $a1
  move  $s2, $a2
  beqz  $t6, .L7F0B8FB8
   move  $v1, $zero
  move  $a0, $zero
  move  $a1, $a3
  lbu   $v0, 4($a1)
.L7F0B8F38:
  lbu   $a2, 5($a1)
  bne   $v0, $s0, .L7F0B8F4C
   nop   
  move  $v0, $a2
  move  $a2, $s0
.L7F0B8F4C:
  bnel  $a2, $s0, .L7F0B8FA8
   lw    $t1, 8($a1)
  blez  $v1, .L7F0B8F78
   move  $a2, $zero
  move  $a3, $s1
.L7F0B8F60:
  lw    $t7, ($a3)
  addiu $a2, $a2, 1
  beql  $v0, $t7, .L7F0B8FA8
   lw    $t1, 8($a1)
  bne   $a2, $v1, .L7F0B8F60
   addiu $a3, $a3, 4
.L7F0B8F78:
  sll   $t8, $v1, 2
  addiu $v1, $v1, 1
  addu  $t9, $s1, $t8
  slt   $at, $v1, $s2
  bnez  $at, .L7F0B8F98
   sw    $v0, ($t9)
  b     .L7F0B8FBC
   move  $v0, $v1
.L7F0B8F98:
  lui   $t0, %hi(ptr_bgdata_portals) 
  lw    $t0, %lo(ptr_bgdata_portals)($t0)
  addu  $a1, $t0, $a0
  lw    $t1, 8($a1)
.L7F0B8FA8:
  addiu $a0, $a0, 8
  addiu $a1, $a1, 8
  bnezl $t1, .L7F0B8F38
   lbu   $v0, 4($a1)
.L7F0B8FB8:
  move  $v0, $v1
.L7F0B8FBC:
  lw    $s0, 4($sp)
  lw    $s1, 8($sp)
  lw    $s2, 0xc($sp)
  jr    $ra
   addiu $sp, $sp, 0x10
");

asm(R"
glabel sub_GAME_7F0B8FD0
  lui   $v1, %hi(ptr_bgdata_portals)
  lw    $v1, %lo(ptr_bgdata_portals)($v1)
  move  $a2, $a0
  lw    $t6, ($v1)
  move  $a0, $v1
  beql  $t6, $zero, .L7F0B9038
   move  $v0, $zero
  lbu   $v0, 4($a0)
.L7F0B8FF0:
  lbu   $v1, 5($a0)
  bne   $v0, $a2, .L7F0B900C
   nop   
  bne   $v1, $a1, .L7F0B900C
   nop   
  jr    $ra
   li    $v0, 1

.L7F0B900C:
  bnel  $v1, $a2, .L7F0B9028
   lw    $t7, 8($a0)
  bnel  $v0, $a1, .L7F0B9028
   lw    $t7, 8($a0)
  jr    $ra
   li    $v0, 1

  lw    $t7, 8($a0)
.L7F0B9028:
  addiu $a0, $a0, 8
  bnezl $t7, .L7F0B8FF0
   lbu   $v0, 4($a0)
  move  $v0, $zero
.L7F0B9038:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B9040
  lui   $t7, %hi(D_80041404) 
  addiu $t7, %lo(D_80041404) # addiu $t7, $t7, 0x1404
  sll   $t6, $a0, 2
  addu  $v0, $t6, $t7
  lw    $t8, ($v0)
  mtc1  $a1, $f12
  mtc1  $a2, $f14
  mtc1  $t8, $f4
  nop   
  cvt.s.w $f6, $f4
  mul.s $f8, $f6, $f12
  add.s $f10, $f8, $f14
  trunc.w.s $f16, $f10
  mfc1  $t1, $f16
  nop   
  mtc1  $t1, $f18
  sw    $t1, ($v0)
  jr    $ra
   cvt.s.w $f0, $f18
");

asm(R"
glabel sub_GAME_7F0B908C
  lui   $v0, %hi(D_80041404)
  addiu $v0, %lo(D_80041404) # addiu $v0, $v0, 0x1404
  lw    $t6, ($v0)
  lw    $t7, 4($v0)
  addiu $sp, $sp, -0x30
  mtc1  $t6, $f4
  mtc1  $t7, $f8
  sw    $ra, 0x14($sp)
  cvt.s.w $f6, $f4
  cvt.s.w $f10, $f8
  swc1  $f6, 0x2c($sp)
  jal   get_video2_settings_txtClipW
   swc1  $f10, 0x24($sp)
  lui   $t8, %hi(D_8004140C) 
  lw    $t8, %lo(D_8004140C)($t8)
  mtc1  $v0, $f4
  mtc1  $t8, $f16
  cvt.s.w $f6, $f4
  cvt.s.w $f18, $f16
  add.s $f8, $f18, $f6
  jal   get_video2_settings_txtClipH
   swc1  $f8, 0x28($sp)
  lui   $t9, %hi(D_80041410) 
  lw    $t9, %lo(D_80041410)($t9)
  mtc1  $v0, $f4
  mtc1  $t9, $f10
  cvt.s.w $f18, $f4
  cvt.s.w $f16, $f10
  add.s $f6, $f16, $f18
  jal   get_video2_settings_ulx
   swc1  $f6, 0x20($sp)
  mtc1  $v0, $f8
  lui   $a0, %hi(pPlayer)
  addiu $a0, %lo(pPlayer) # addiu $a0, $a0, -0x5f50
  cvt.s.w $f10, $f8
  lw    $t0, ($a0)
  lwc1  $f2, 0x2c($sp)
  swc1  $f10, 0x1118($t0)
  lw    $v1, ($a0)
  lwc1  $f0, 0x1118($v1)
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F0B914C
   lwc1  $f12, 0x28($sp)
  swc1  $f2, 0x1118($v1)
  lw    $v1, ($a0)
  lwc1  $f0, 0x1118($v1)
  lwc1  $f12, 0x28($sp)
.L7F0B914C:
  c.lt.s $f12, $f0
  nop   
  bc1f  .L7F0B9160
   nop   
  swc1  $f12, 0x1118($v1)
.L7F0B9160:
  jal   get_video2_settings_uly
   nop   
  mtc1  $v0, $f4
  lui   $a0, %hi(pPlayer)
  addiu $a0, %lo(pPlayer) # addiu $a0, $a0, -0x5f50
  cvt.s.w $f16, $f4
  lw    $t1, ($a0)
  lwc1  $f2, 0x24($sp)
  swc1  $f16, 0x111c($t1)
  lw    $v1, ($a0)
  lwc1  $f0, 0x111c($v1)
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F0B91AC
   lwc1  $f12, 0x20($sp)
  swc1  $f2, 0x111c($v1)
  lw    $v1, ($a0)
  lwc1  $f0, 0x111c($v1)
  lwc1  $f12, 0x20($sp)
.L7F0B91AC:
  c.lt.s $f12, $f0
  nop   
  bc1f  .L7F0B91C0
   nop   
  swc1  $f12, 0x111c($v1)
.L7F0B91C0:
  jal   get_video2_settings_ulx
   nop   
  jal   get_video2_settings_width
   sh    $v0, 0x1e($sp)
  lh    $t2, 0x1e($sp)
  lui   $a0, %hi(pPlayer)
  addiu $a0, %lo(pPlayer) # addiu $a0, $a0, -0x5f50
  addu  $t3, $v0, $t2
  mtc1  $t3, $f18
  lw    $t4, ($a0)
  cvt.s.w $f6, $f18
  swc1  $f6, 0x1120($t4)
  lw    $v1, ($a0)
  lwc1  $f8, 0x2c($sp)
  lwc1  $f0, 0x1120($v1)
  c.lt.s $f0, $f8
  nop   
  bc1fl .L7F0B921C
   lwc1  $f10, 0x28($sp)
  swc1  $f8, 0x1120($v1)
  lw    $v1, ($a0)
  lwc1  $f0, 0x1120($v1)
  lwc1  $f10, 0x28($sp)
.L7F0B921C:
  c.lt.s $f10, $f0
  nop   
  bc1f  .L7F0B9230
   nop   
  swc1  $f10, 0x1120($v1)
.L7F0B9230:
  jal   get_video2_settings_uly
   nop   
  jal   get_video2_settings_height
   sh    $v0, 0x1e($sp)
  lh    $t5, 0x1e($sp)
  lui   $a0, %hi(pPlayer)
  addiu $a0, %lo(pPlayer) # addiu $a0, $a0, -0x5f50
  addu  $t6, $v0, $t5
  mtc1  $t6, $f4
  lw    $t7, ($a0)
  cvt.s.w $f16, $f4
  swc1  $f16, 0x1124($t7)
  lw    $v1, ($a0)
  lwc1  $f18, 0x24($sp)
  lwc1  $f0, 0x1124($v1)
  c.lt.s $f0, $f18
  nop   
  bc1fl .L7F0B9290
   lwc1  $f6, 0x20($sp)
  swc1  $f18, 0x1124($v1)
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  lwc1  $f0, 0x1124($v1)
  lwc1  $f6, 0x20($sp)
.L7F0B9290:
  c.lt.s $f6, $f0
  nop   
  bc1fl .L7F0B92A8
   lw    $ra, 0x14($sp)
  swc1  $f6, 0x1124($v1)
  lw    $ra, 0x14($sp)
.L7F0B92A8:
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B92B4
  sll   $t6, $a0, 2
  addu  $t6, $t6, $a0
  lui   $t7, %hi(array_room_info) 
  li    $at, 0x3F000000 # 0.500000
  addiu $t7, %lo(array_room_info) # addiu $t7, $t7, 0x1414
  sll   $t6, $t6, 4
  mtc1  $at, $f0
  addu  $a2, $t6, $t7
  li    $a0, 3
  move  $v0, $zero
  move  $v1, $a1
  lwc1  $f16, 0x44($a2)
  lwc1  $f14, 0x38($a2)
  addiu $v0, $v0, 1
  add.s $f14, $f16, $f14
  mul.s $f18, $f14, $f0
  beql  $v0, $a0, .L7F0B9328
   addiu $a2, $a2, 4
  swc1  $f18, ($v1)
.L7F0B9300:
  lwc1  $f16, 0x48($a2)
  addiu $a2, $a2, 4
  lwc1  $f14, 0x38($a2)
  addiu $v0, $v0, 1
  addiu $v1, $v1, 4
  add.s $f14, $f16, $f14
  mul.s $f18, $f14, $f0
  bnel  $v0, $a0, .L7F0B9300
   swc1  $f18, ($v1)
  addiu $a2, $a2, 4
.L7F0B9328:
  addiu $v1, $v1, 4
  swc1  $f18, -4($v1)
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B9338
  lui   $t0, %hi(ptr_bgdata_room_fileposition_list) 
  addiu $t0, %lo(ptr_bgdata_room_fileposition_list) # addiu $t0, $t0, -0x74
  lw    $t6, ($t0)
  sll   $v0, $a0, 2
  addiu $sp, $sp, -0x50
  subu  $v0, $v0, $a0
  sll   $v0, $v0, 3
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  addu  $t1, $t6, $v0
  lw    $t7, ($t1)
  lui   $t8, %hi(array_room_info) 
  move  $s0, $a0
  bnez  $t7, .L7F0B9444
   addiu $t8, %lo(array_room_info) # addiu $t8, $t8, 0x1414
  lui   $t8, %hi(dword_CODE_bss_8007B9DC) 
  lw    $t8, %lo(dword_CODE_bss_8007B9DC)($t8)
  sll   $t9, $a0, 2
  lui   $t3, %hi(dword_CODE_bss_8007B128)
  slt   $at, $a0, $t8
  beqz  $at, .L7F0B95C4
   addu  $t3, $t3, $t9
  lw    $t3, %lo(dword_CODE_bss_8007B128)($t3)
  sll   $t4, $s0, 2
  addu  $t4, $t4, $s0
  beqz  $t3, .L7F0B95C4
   move  $a0, $zero
  sll   $t6, $s0, 2
  subu  $t6, $t6, $s0
  lui   $t5, %hi(array_room_info) 
  lui   $t7, %hi(dword_CODE_bss_8007B358) 
  addiu $t7, %lo(dword_CODE_bss_8007B358) # addiu $t7, $t7, -0x4ca8
  addiu $t5, %lo(array_room_info) # addiu $t5, $t5, 0x1414
  sll   $t6, $t6, 2
  sll   $t4, $t4, 4
  addu  $a1, $t4, $t5
  addu  $a2, $t6, $t7
  li    $a3, 12
.L7F0B93D0:
  lh    $v0, ($a2)
  lh    $v1, 6($a2)
  lw    $t3, ($t0)
  mtc1  $v0, $f4
  mtc1  $v1, $f8
  addu  $t8, $v1, $v0
  cvt.s.w $f6, $f4
  sll   $t4, $s0, 2
  subu  $t4, $t4, $s0
  sll   $t4, $t4, 3
  addu  $t5, $t3, $t4
  cvt.s.w $f10, $f8
  addu  $t6, $t5, $a0
  addiu $a0, $a0, 4
  swc1  $f6, 0x38($a1)
  addiu $a1, $a1, 4
  addiu $a2, $a2, 2
  swc1  $f10, 0x40($a1)
  bgez  $t8, .L7F0B9428
   sra   $t9, $t8, 1
  addiu $at, $t8, 1
  sra   $t9, $at, 1
.L7F0B9428:
  mtc1  $t9, $f16
  nop   
  cvt.s.w $f18, $f16
  bne   $a0, $a3, .L7F0B93D0
   swc1  $f18, 0xc($t6)
  b     .L7F0B95C8
   lw    $ra, 0x1c($sp)
.L7F0B9444:
  sll   $t7, $s0, 2
  addu  $t7, $t7, $s0
  sll   $t7, $t7, 4
  addu  $t0, $t7, $t8
  lbu   $t2, 2($t0)
  move  $a0, $s0
  bnezl $t2, .L7F0B9490
   lw    $a2, 4($t0)
  sw    $v0, 0x30($sp)
  sw    $t0, 0x28($sp)
  jal   sub_GAME_7F0B6368
   sb    $t2, 0x37($sp)
  lui   $t9, %hi(ptr_bgdata_room_fileposition_list) 
  lw    $t9, %lo(ptr_bgdata_room_fileposition_list)($t9)
  lw    $v0, 0x30($sp)
  lw    $t0, 0x28($sp)
  lbu   $t2, 0x37($sp)
  addu  $t1, $t9, $v0
  lw    $a2, 4($t0)
.L7F0B9490:
  lw    $t9, 0x1c($t0)
  li    $t3, 32767
  li    $t4, 32767
  addu  $a3, $t9, $a2
  li    $t5, 32767
  li    $t6, -32767
  li    $t7, -32767
  li    $t8, -32767
  sltu  $at, $a2, $a3
  sh    $t3, 0x38($sp)
  sh    $t4, 0x3a($sp)
  sh    $t5, 0x3c($sp)
  sh    $t6, 0x3e($sp)
  sh    $t7, 0x40($sp)
  beqz  $at, .L7F0B9528
   sh    $t8, 0x42($sp)
  addiu $a1, $sp, 0x3e
  move  $a0, $a2
.L7F0B94D8:
  addiu $v1, $sp, 0x38
.L7F0B94DC:
  lh    $v0, ($a0)
  lh    $t3, ($v1)
  slt   $at, $v0, $t3
  beql  $at, $zero, .L7F0B94FC
   lh    $t4, 6($v1)
  sh    $v0, ($v1)
  lh    $v0, ($a0)
  lh    $t4, 6($v1)
.L7F0B94FC:
  slt   $at, $t4, $v0
  beql  $at, $zero, .L7F0B9510
   addiu $v1, $v1, 2
  sh    $v0, 6($v1)
  addiu $v1, $v1, 2
.L7F0B9510:
  bne   $v1, $a1, .L7F0B94DC
   addiu $a0, $a0, 2
  addiu $a2, $a2, 0x10
  sltu  $at, $a2, $a3
  bnezl $at, .L7F0B94D8
   move  $a0, $a2
.L7F0B9528:
  lh    $t5, 0x38($sp)
  lh    $t6, 0x3a($sp)
  lwc1  $f4, 0xc($t1)
  mtc1  $t5, $f6
  mtc1  $t6, $f18
  lh    $t7, 0x3c($sp)
  cvt.s.w $f8, $f6
  lh    $t8, 0x3e($sp)
  lh    $t9, 0x40($sp)
  lh    $t3, 0x42($sp)
  cvt.s.w $f6, $f18
  add.s $f10, $f4, $f8
  swc1  $f10, 0x38($t0)
  lwc1  $f16, 0x10($t1)
  mtc1  $t7, $f10
  add.s $f4, $f16, $f6
  cvt.s.w $f18, $f10
  swc1  $f4, 0x3c($t0)
  lwc1  $f8, 0x14($t1)
  mtc1  $t8, $f4
  add.s $f16, $f8, $f18
  cvt.s.w $f10, $f4
  swc1  $f16, 0x40($t0)
  lwc1  $f6, 0xc($t1)
  mtc1  $t9, $f16
  add.s $f8, $f6, $f10
  cvt.s.w $f4, $f16
  swc1  $f8, 0x44($t0)
  lwc1  $f18, 0x10($t1)
  mtc1  $t3, $f8
  add.s $f6, $f18, $f4
  cvt.s.w $f16, $f8
  swc1  $f6, 0x48($t0)
  lwc1  $f10, 0x14($t1)
  add.s $f18, $f10, $f16
  bnez  $t2, .L7F0B95C4
   swc1  $f18, 0x4c($t0)
  jal   sub_GAME_7F0B65C4
   move  $a0, $s0
.L7F0B95C4:
  lw    $ra, 0x1c($sp)
.L7F0B95C8:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x50
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B95D8
  lui   $a1, %hi(ptr_bgdata_portals)
  lw    $a1, %lo(ptr_bgdata_portals)($a1)
  move  $v0, $zero
  li    $t3, 12
  lw    $t6, ($a1)
  move  $v1, $a1
  beqz  $t6, .L7F0B96C4
   nop   
  lbu   $t7, 4($v1)
.L7F0B95FC:
  beql  $a0, $t7, .L7F0B9614
   lw    $a2, ($v1)
  lbu   $t8, 5($v1)
  bnel  $a0, $t8, .L7F0B96B8
   lw    $t9, 8($v1)
  lw    $a2, ($v1)
.L7F0B9614:
  sll   $t4, $a0, 2
  addu  $t4, $t4, $a0
  lbu   $t9, ($a2)
  sll   $t4, $t4, 4
  move  $a1, $zero
  blez  $t9, .L7F0B96B4
   lui   $t5, %hi(array_room_info) 
  addiu $t5, %lo(array_room_info) # addiu $t5, $t5, 0x1414
  addu  $t1, $t4, $t5
  move  $t0, $zero
.L7F0B963C:
  move  $t2, $t1
.L7F0B9640:
  sll   $t6, $a1, 2
  subu  $t6, $t6, $a1
  sll   $t6, $t6, 2
  addu  $t7, $a2, $t6
  addu  $t8, $t7, $t0
  lwc1  $f0, 4($t8)
  lwc1  $f4, 0x38($t2)
  addiu $t0, $t0, 4
  c.lt.s $f0, $f4
  nop   
  bc1fl .L7F0B967C
   lwc1  $f6, 0x44($t2)
  swc1  $f0, 0x38($t2)
  addiu $v0, $v0, 1
  lwc1  $f6, 0x44($t2)
.L7F0B967C:
  c.lt.s $f6, $f0
  nop   
  bc1fl .L7F0B9698
   addiu $t2, $t2, 4
  swc1  $f0, 0x44($t2)
  addiu $v0, $v0, 1
  addiu $t2, $t2, 4
.L7F0B9698:
  bne   $t0, $t3, .L7F0B9640
   lw    $a2, ($v1)
  lbu   $a3, ($a2)
  addiu $a1, $a1, 1
  slt   $at, $a1, $a3
  bnezl $at, .L7F0B963C
   move  $t0, $zero
.L7F0B96B4:
  lw    $t9, 8($v1)
.L7F0B96B8:
  addiu $v1, $v1, 8
  bnezl $t9, .L7F0B95FC
   lbu   $t7, 4($v1)
.L7F0B96C4:
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80058D54
.word 0x7f7fffff /*3.4028235e38*/
glabel D_80058D58
.word 0xff7fffff /*-3.4028235e38*/
.text
glabel sub_GAME_7F0B96CC
  addiu $sp, $sp, -0x78
  lui   $t6, %hi(ptr_bgdata_portals) 
  lw    $t6, %lo(ptr_bgdata_portals)($t6)
  sll   $t0, $a0, 3
  sw    $s0, 0x20($sp)
  move  $s0, $a1
  sw    $ra, 0x24($sp)
  sdc1  $f20, 0x18($sp)
  addiu $a0, $sp, 0x78
  addiu $a2, $sp, 0x6c
  move  $v0, $zero
  addu  $a3, $t6, $t0
  addiu $a2, $a2, 4
  sltu  $at, $a2, $a0
  beqz  $at, .L7F0B9734
   lw    $t7, ($a3)
.L7F0B970C:
  addu  $v1, $t7, $v0
  lwc1  $f20, 4($v1)
  lwc1  $f18, 0x10($v1)
  addiu $a2, $a2, 4
  sltu  $at, $a2, $a0
  sub.s $f18, $f20, $f18
  addiu $v0, $v0, 4
  swc1  $f18, -8($a2)
  bnez  $at, .L7F0B970C
   lw    $t7, ($a3)
.L7F0B9734:
  addu  $v1, $t7, $v0
  lwc1  $f20, 4($v1)
  lwc1  $f18, 0x10($v1)
  addiu $v0, $v0, 4
  sub.s $f18, $f20, $f18
  swc1  $f18, -4($a2)
  move  $v0, $zero
  addiu $a0, $sp, 0x60
  addiu $a1, $sp, 0x6c
  addiu $a0, $a0, 4
  sltu  $at, $a0, $a1
  beqz  $at, .L7F0B9790
   lw    $t8, ($a3)
.L7F0B9768:
  addu  $v1, $t8, $v0
  lwc1  $f20, 0x1c($v1)
  lwc1  $f18, 0x10($v1)
  addiu $a0, $a0, 4
  sltu  $at, $a0, $a1
  sub.s $f18, $f20, $f18
  addiu $v0, $v0, 4
  swc1  $f18, -8($a0)
  bnez  $at, .L7F0B9768
   lw    $t8, ($a3)
.L7F0B9790:
  addu  $v1, $t8, $v0
  lwc1  $f20, 0x1c($v1)
  lwc1  $f18, 0x10($v1)
  addiu $v0, $v0, 4
  sub.s $f18, $f20, $f18
  swc1  $f18, -4($a0)
  lwc1  $f8, 0x70($sp)
  lwc1  $f10, 0x68($sp)
  lwc1  $f6, 0x64($sp)
  mul.s $f4, $f8, $f10
  lwc1  $f8, 0x74($sp)
  mul.s $f10, $f6, $f8
  sub.s $f6, $f4, $f10
  swc1  $f6, ($s0)
  lwc1  $f4, 0x60($sp)
  lwc1  $f8, 0x74($sp)
  lwc1  $f6, 0x68($sp)
  lwc1  $f16, ($s0)
  mul.s $f10, $f8, $f4
  lwc1  $f8, 0x6c($sp)
  mul.s $f4, $f6, $f8
  sub.s $f6, $f10, $f4
  swc1  $f6, 4($s0)
  lwc1  $f10, 0x64($sp)
  lwc1  $f8, 0x6c($sp)
  lwc1  $f6, 0x60($sp)
  lwc1  $f18, 4($s0)
  mul.s $f4, $f8, $f10
  lwc1  $f8, 0x70($sp)
  mul.s $f10, $f6, $f8
  sub.s $f6, $f4, $f10
  mul.s $f8, $f16, $f16
  nop   
  mul.s $f4, $f18, $f18
  swc1  $f6, 8($s0)
  lwc1  $f14, 8($s0)
  sw    $t0, 0x40($sp)
  mul.s $f6, $f14, $f14
  add.s $f10, $f8, $f4
  jal   sqrtf
   add.s $f12, $f6, $f10
  mtc1  $zero, $f8
  lw    $t0, 0x40($sp)
  mov.s $f20, $f0
  c.eq.s $f0, $f8
  li    $at, 0x3F800000 # 1.000000
  move  $v1, $zero
  bc1tl .L7F0B9864
   lwc1  $f6, ($s0)
  mtc1  $at, $f4
  nop   
  div.s $f20, $f4, $f0
  lwc1  $f6, ($s0)
.L7F0B9864:
  lwc1  $f8, 4($s0)
  lui   $t9, %hi(ptr_bgdata_portals) 
  mul.s $f10, $f6, $f20
  lwc1  $f6, 8($s0)
  lui   $at, %hi(D_80058D54)
  mul.s $f4, $f8, $f20
  swc1  $f10, ($s0)
  mul.s $f10, $f6, $f20
  swc1  $f4, 4($s0)
  swc1  $f10, 8($s0)
  lw    $t9, %lo(ptr_bgdata_portals)($t9)
  lwc1  $f2, %lo(D_80058D54)($at)
  lui   $at, %hi(D_80058D58)
  addu  $t1, $t9, $t0
  lw    $a1, ($t1)
  lwc1  $f12, %lo(D_80058D58)($at)
  lbu   $a2, ($a1)
  move  $v0, $a1
  blez  $a2, .L7F0B9920
   sll   $a0, $a2, 2
  subu  $a0, $a0, $a2
  sll   $a0, $a0, 2
  lwc1  $f14, 8($s0)
  lwc1  $f16, ($s0)
  lwc1  $f18, 4($s0)
.L7F0B98C8:
  lwc1  $f8, 4($v0)
  lwc1  $f6, 8($v0)
  addiu $v1, $v1, 0xc
  mul.s $f4, $f8, $f16
  slt   $at, $v1, $a0
  mul.s $f10, $f6, $f18
  lwc1  $f6, 0xc($v0)
  add.s $f8, $f4, $f10
  mul.s $f4, $f14, $f6
  add.s $f0, $f4, $f8
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F0B9908
   c.lt.s $f12, $f0
  mov.s $f2, $f0
  c.lt.s $f12, $f0
.L7F0B9908:
  nop   
  bc1f  .L7F0B9918
   nop   
  mov.s $f12, $f0
.L7F0B9918:
  bnez  $at, .L7F0B98C8
   addiu $v0, $v0, 0xc
.L7F0B9920:
  swc1  $f2, 0xc($s0)
  swc1  $f12, 0x10($s0)
  lw    $ra, 0x24($sp)
  lw    $s0, 0x20($sp)
  ldc1  $f20, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x78
");

asm(R"
.late_rodata
glabel D_80058D5C
.word 0x3f7fbe77 /*0.99900001*/

.text
glabel sub_GAME_7F0B993C
  addiu $sp, $sp, -0x30
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F0B96CC
   addiu $a1, $sp, 0x1c
  lwc1  $f0, 0x24($sp)
  lwc1  $f2, 0x1c($sp)
  lui   $at, %hi(D_80058D5C)
  mul.s $f4, $f0, $f0
  lwc1  $f10, %lo(D_80058D5C)($at)
  lw    $ra, 0x14($sp)
  mul.s $f6, $f2, $f2
  li    $v0, 1
  add.s $f8, $f4, $f6
  c.lt.s $f8, $f10
  nop   
  bc1f  .L7F0B9988
   nop   
  b     .L7F0B9988
   move  $v0, $zero
.L7F0B9988:
  jr    $ra
   addiu $sp, $sp, 0x30
");

asm(R"
glabel sub_GAME_7F0B9990
  lui   $t6, %hi(ptr_bgdata_portals) 
  lw    $t6, %lo(ptr_bgdata_portals)($t6)
  sll   $t7, $a0, 3
  li    $at, 0x3E800000 # 0.250000
  addu  $t8, $t6, $t7
  lbu   $v0, 7($t8)
  mtc1  $at, $f8
  andi  $t0, $v0, 0xf
  mtc1  $t0, $f4
  sra   $a1, $v0, 4
  andi  $t9, $a1, 0xf
  cvt.s.w $f6, $f4
  andi  $a0, $t9, 3
  move  $v1, $t9
  negu  $a0, $a0
  mul.s $f2, $f6, $f8
  beqz  $t9, .L7F0B9A0C
   nop   
  beqz  $a0, .L7F0B99F4
   addu  $v0, $a0, $t9
.L7F0B99E0:
  addiu $v1, $v1, -1
  bne   $v0, $v1, .L7F0B99E0
   add.s $f2, $f2, $f2
  beqz  $v1, .L7F0B9A0C
   nop   
.L7F0B99F4:
  add.s $f2, $f2, $f2
  addiu $v1, $v1, -4
  add.s $f2, $f2, $f2
  add.s $f2, $f2, $f2
  bnez  $v1, .L7F0B99F4
   add.s $f2, $f2, $f2
.L7F0B9A0C:
  jr    $ra
   mov.s $f0, $f2
");

unsigned char sub_GAME_7F0B9A14(int i) {
  return *((unsigned char *)&((((long long *)ptr_bgdata_portals)[i])) + 7);
}

asm(R"
glabel sub_GAME_7F0B9A2C
  lui   $t6, %hi(ptr_bgdata_portals) 
  lw    $t6, %lo(ptr_bgdata_portals)($t6)
  sll   $t7, $a0, 3
  addu  $v1, $t6, $t7
  lbu   $v0, 7($v1)
  slti  $at, $v0, 0xff
  bnez  $at, .L7F0B9A54
   addiu $v0, $v0, 1
  b     .L7F0B9A74
   li    $v0, 255
.L7F0B9A54:
  andi  $t8, $v0, 0xff
  sra   $t9, $t8, 4
  andi  $t0, $t9, 0xf
  blez  $t0, .L7F0B9A74
   move  $v0, $t8
  ori   $v0, $t8, 8
  andi  $t1, $v0, 0xff
  move  $v0, $t1
.L7F0B9A74:
  jr    $ra
   sb    $v0, 7($v1)
");

asm(R"
glabel sub_GAME_7F0B9A7C
  lui   $t6, %hi(ptr_bgdata_portals) 
  lw    $t6, %lo(ptr_bgdata_portals)($t6)
  sll   $t7, $a0, 3
  addu  $v1, $t6, $t7
  lbu   $v0, 7($v1)
  sra   $t8, $v0, 4
  andi  $t9, $t8, 0xf
  bnez  $t9, .L7F0B9AB8
   move  $a1, $v0
  blez  $a1, .L7F0B9ADC
   nop   
  addiu $v0, $v0, -1
  andi  $t0, $v0, 0xff
  b     .L7F0B9ADC
   move  $v0, $t0
.L7F0B9AB8:
  addiu $v0, $v0, -1
  andi  $t1, $v0, 0xff
  andi  $t2, $t1, 0xf
  slti  $at, $t2, 8
  beqz  $at, .L7F0B9ADC
   move  $v0, $t1
  addiu $v0, $t1, -8
  andi  $t3, $v0, 0xff
  move  $v0, $t3
.L7F0B9ADC:
  jr    $ra
   sb    $v0, 7($v1)
");

asm(R"
glabel sub_GAME_7F0B9AE4
  lui   $t6, %hi(ptr_bgdata_portals) 
  lw    $t6, %lo(ptr_bgdata_portals)($t6)
  sll   $t7, $a0, 3
  addu  $t8, $t6, $t7
  lbu   $v0, 6($t8)
  andi  $t9, $v0, 1
  jr    $ra
   move  $v0, $t9
");

asm(R"
glabel sub_GAME_7F0B9B04
  lui   $t6, %hi(ptr_bgdata_portals) 
  lw    $t6, %lo(ptr_bgdata_portals)($t6)
  sll   $t7, $a0, 3
  addu  $t8, $t6, $t7
  lbu   $v0, 6($t8)
  andi  $t9, $v0, 2
  jr    $ra
   move  $v0, $t9
");

asm(R"
glabel sub_GAME_7F0B9B24
  lui   $t6, %hi(ptr_bgdata_portals) 
  lw    $t6, %lo(ptr_bgdata_portals)($t6)
  sll   $t7, $a0, 3
  addu  $v0, $t6, $t7
  lbu   $t8, 6($v0)
  ori   $t9, $t8, 2
  jr    $ra
   sb    $t9, 6($v0)
");

asm(R"
glabel sub_GAME_7F0B9B44
  lui   $t6, %hi(ptr_bgdata_portals) 
  lw    $t6, %lo(ptr_bgdata_portals)($t6)
  sll   $t7, $a0, 3
  addu  $v0, $t6, $t7
  lbu   $t8, 6($v0)
  andi  $t9, $t8, 0xfd
  jr    $ra
   sb    $t9, 6($v0)
");

asm(R"
glabel sub_GAME_7F0B9B64
  lui   $a2, %hi(ptr_bgdata_portals)
  addiu $a2, %lo(ptr_bgdata_portals) # addiu $a2, $a2, -0x80
  lw    $t6, ($a2)
  sll   $v1, $a0, 3
  addu  $a1, $t6, $v1
  lbu   $t7, 5($a1)
  lbu   $v0, 4($a1)
  sb    $t7, 4($a1)
  lw    $t8, ($a2)
  addu  $t9, $t8, $v1
  jr    $ra
   sb    $v0, 5($t9)
");

asm(R"
glabel sub_GAME_7F0B9B94
  lui   $t6, %hi(ptr_bgdata_portals) 
  lw    $t6, %lo(ptr_bgdata_portals)($t6)
  addiu $sp, $sp, -0x60
  sll   $t8, $a0, 3
  sw    $ra, 0x14($sp)
  sw    $a0, 0x60($sp)
  addu  $v0, $t6, $t8
  lbu   $t9, 5($v0)
  lbu   $a0, 4($v0)
  addiu $a1, $sp, 0x54
  jal   sub_GAME_7F0B92B4
   sw    $t9, 0x28($sp)
  lw    $a0, 0x28($sp)
  jal   sub_GAME_7F0B92B4
   addiu $a1, $sp, 0x48
  lw    $a0, 0x60($sp)
  jal   sub_GAME_7F0B96CC
   addiu $a1, $sp, 0x34
  lwc1  $f4, 0x38($sp)
  lwc1  $f6, 0x58($sp)
  lwc1  $f18, 0x34($sp)
  lwc1  $f10, 0x54($sp)
  mul.s $f8, $f4, $f6
  lwc1  $f16, 0x3c($sp)
  lwc1  $f12, 0x44($sp)
  mul.s $f4, $f18, $f10
  lwc1  $f10, 0x5c($sp)
  lwc1  $f14, 0x40($sp)
  move  $v0, $zero
  lw    $a0, 0x60($sp)
  add.s $f6, $f4, $f8
  mul.s $f4, $f10, $f16
  add.s $f2, $f4, $f6
  c.lt.s $f12, $f2
  nop   
  bc1fl .L7F0B9C6C
   lwc1  $f4, 0x38($sp)
  li    $v0, 1
  jal   sub_GAME_7F0B9B64
   sw    $v0, 0x24($sp)
  lwc1  $f12, 0x44($sp)
  lwc1  $f0, 0x40($sp)
  lwc1  $f8, 0x38($sp)
  lwc1  $f16, 0x3c($sp)
  lwc1  $f18, 0x34($sp)
  neg.s $f14, $f12
  neg.s $f12, $f0
  neg.s $f10, $f8
  lw    $v0, 0x24($sp)
  swc1  $f10, 0x38($sp)
  swc1  $f12, 0x44($sp)
  neg.s $f16, $f16
  neg.s $f18, $f18
  lwc1  $f4, 0x38($sp)
.L7F0B9C6C:
  lwc1  $f6, 0x4c($sp)
  lwc1  $f10, 0x48($sp)
  swc1  $f14, 0x40($sp)
  mul.s $f8, $f4, $f6
  swc1  $f16, 0x3c($sp)
  swc1  $f18, 0x34($sp)
  mul.s $f4, $f18, $f10
  lwc1  $f10, 0x50($sp)
  add.s $f6, $f4, $f8
  mul.s $f4, $f10, $f16
  add.s $f0, $f4, $f6
  c.le.s $f0, $f14
  nop   
  bc1fl .L7F0B9CBC
   lw    $ra, 0x14($sp)
  beqz  $v0, .L7F0B9CB8
   lw    $a0, 0x60($sp)
  jal   sub_GAME_7F0B9B64
   sw    $v0, 0x24($sp)
.L7F0B9CB8:
  lw    $ra, 0x14($sp)
.L7F0B9CBC:
  addiu $sp, $sp, 0x60
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0B9CC8
  addiu $sp, $sp, -0x40
  sw    $fp, 0x38($sp)
  lui   $fp, %hi(ptr_bgdata_portals) 
  addiu $fp, %lo(ptr_bgdata_portals) # addiu $fp, $fp, -0x80
  lw    $v1, ($fp)
  sw    $ra, 0x3c($sp)
  sw    $s7, 0x34($sp)
  sw    $s6, 0x30($sp)
  sw    $s5, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  lw    $t6, ($v1)
  move  $s2, $a0
  move  $s3, $a1
  move  $s6, $a2
  move  $s7, $a3
  li    $s4, -1
  beqz  $t6, .L7F0B9D88
   move  $s0, $zero
  move  $s1, $zero
  move  $v0, $v1
  lbu   $v1, 4($v0)
.L7F0B9D2C:
  bne   $s2, $v1, .L7F0B9D40
   nop   
  lbu   $t7, 5($v0)
  beql  $s3, $t7, .L7F0B9D54
   move  $a0, $s0
.L7F0B9D40:
  bnel  $s3, $v1, .L7F0B9D70
   lw    $t9, ($fp)
  lbu   $t8, 5($v0)
  bne   $s2, $t8, .L7F0B9D6C
   move  $a0, $s0
.L7F0B9D54:
  move  $a1, $s6
  jal   sub_GAME_7F0B9F14
   move  $a2, $s7
  beql  $v0, $zero, .L7F0B9D70
   lw    $t9, ($fp)
  move  $s4, $s0
.L7F0B9D6C:
  lw    $t9, ($fp)
.L7F0B9D70:
  addiu $s1, $s1, 8
  addiu $s0, $s0, 1
  addu  $v0, $t9, $s1
  lw    $t0, ($v0)
  bnezl $t0, .L7F0B9D2C
   lbu   $v1, 4($v0)
.L7F0B9D88:
  lw    $ra, 0x3c($sp)
  move  $v0, $s4
  lw    $s4, 0x28($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  lw    $s3, 0x24($sp)
  lw    $s5, 0x2c($sp)
  lw    $s6, 0x30($sp)
  lw    $s7, 0x34($sp)
  lw    $fp, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x40
");

asm(R"
glabel sub_GAME_7F0B9DBC
  lui   $t6, %hi(ptr_bgdata_portals) 
  lw    $t6, %lo(ptr_bgdata_portals)($t6)
  sll   $t7, $a0, 3
  sltu  $t0, $zero, $a1
  addu  $v0, $t6, $t7
  lbu   $t8, 6($v0)
  ori   $t9, $t8, 1
  xor   $t1, $t9, $t0
  jr    $ra
   sb    $t1, 6($v0)
");

int sub_GAME_7F0B9DE4(int arg0, int arg1, int arg2) {
  int a = arg1, b = arg2;
  return arg0;
}

void sub_GAME_7F0B9DF4(int arg0) {}

void sub_GAME_7F0B9DFC(int arg0) {}

asm(R"
.late_rodata
glabel D_80058D60
.word 0x7f7fffff /*3.4028235e38*/
.text
glabel sub_GAME_7F0B9E04
  addiu $sp, $sp, -0x48
  sw    $s6, 0x3c($sp)
  lui   $s6, %hi(ptr_bgdata_portals)
  addiu $s6, %lo(ptr_bgdata_portals) # addiu $s6, $s6, -0x80
  lw    $t6, ($s6)
  sw    $ra, 0x44($sp)
  sw    $s7, 0x40($sp)
  sw    $s5, 0x38($sp)
  sw    $s4, 0x34($sp)
  sw    $s3, 0x30($sp)
  sw    $s2, 0x2c($sp)
  sw    $s1, 0x28($sp)
  sw    $s0, 0x24($sp)
  sdc1  $f22, 0x18($sp)
  sdc1  $f20, 0x10($sp)
  lw    $t7, ($t6)
  lui   $at, %hi(D_80058D60)
  move  $s4, $a0
  move  $s5, $a1
  li    $s3, -1
  move  $s1, $zero
  lwc1  $f20, %lo(D_80058D60)($at)
  beqz  $t7, .L7F0B9EDC
   move  $s0, $zero
  lui   $s7, %hi(D_80044900) 
  mtc1  $zero, $f22
  addiu $s7, %lo(D_80044900) # addiu $s7, $s7, 0x4900
  move  $s2, $zero
  move  $a0, $s0
.L7F0B9E78:
  move  $a1, $s4
  jal   sub_GAME_7F0B9F14
   move  $a2, $s5
  beql  $v0, $zero, .L7F0B9EC4
   lw    $t8, ($s6)
  lwc1  $f0, ($s7)
  c.lt.s $f0, $f22
  nop   
  bc1fl .L7F0B9EA8
   c.lt.s $f0, $f20
  neg.s $f0, $f0
  c.lt.s $f0, $f20
.L7F0B9EA8:
  nop   
  bc1fl .L7F0B9EC4
   lw    $t8, ($s6)
  move  $s3, $s0
  mov.s $f20, $f0
  addiu $s1, $s1, 1
  lw    $t8, ($s6)
.L7F0B9EC4:
  addiu $s2, $s2, 8
  addiu $s0, $s0, 1
  addu  $t9, $t8, $s2
  lw    $t0, ($t9)
  bnezl $t0, .L7F0B9E78
   move  $a0, $s0
.L7F0B9EDC:
  lw    $ra, 0x44($sp)
  move  $v0, $s3
  lw    $s3, 0x30($sp)
  ldc1  $f20, 0x10($sp)
  ldc1  $f22, 0x18($sp)
  lw    $s0, 0x24($sp)
  lw    $s1, 0x28($sp)
  lw    $s2, 0x2c($sp)
  lw    $s4, 0x34($sp)
  lw    $s5, 0x38($sp)
  lw    $s6, 0x3c($sp)
  lw    $s7, 0x40($sp)
  jr    $ra
   addiu $sp, $sp, 0x48
");

asm(R"
glabel sub_GAME_7F0B9F14
  addiu $sp, $sp, -0xa0
  sw    $s0, 0x18($sp)
  move  $s0, $a1
  sw    $ra, 0x1c($sp)
  sw    $a0, 0xa0($sp)
  addiu $a1, $sp, 0x60
  sw    $a2, 0xa8($sp)
  sb    $zero, 0x4b($sp)
  jal   sub_GAME_7F0B96CC
   sb    $zero, 0x4a($sp)
  lw    $a2, 0xa8($sp)
  lwc1  $f16, ($s0)
  lui   $at, %hi(room_data_float1)
  lwc1  $f10, ($a2)
  lwc1  $f12, %lo(room_data_float1)($at)
  lbu   $t2, 0x4b($sp)
  sub.s $f6, $f10, $f16
  lbu   $t3, 0x4a($sp)
  swc1  $f6, 0x8c($sp)
  lwc1  $f8, 4($s0)
  lwc1  $f4, 4($a2)
  sub.s $f18, $f4, $f8
  lwc1  $f8, 0x60($sp)
  swc1  $f18, 0x90($sp)
  lwc1  $f16, 8($s0)
  lwc1  $f10, 8($a2)
  sub.s $f6, $f10, $f16
  lwc1  $f16, 0x64($sp)
  swc1  $f6, 0x94($sp)
  lwc1  $f4, ($s0)
  lwc1  $f10, 4($s0)
  mul.s $f18, $f4, $f8
  nop   
  mul.s $f6, $f10, $f16
  lwc1  $f10, 0x68($sp)
  add.s $f4, $f18, $f6
  lwc1  $f18, 8($s0)
  mul.s $f6, $f10, $f18
  add.s $f18, $f6, $f4
  lwc1  $f6, ($a2)
  mul.s $f14, $f18, $f12
  lwc1  $f18, 4($a2)
  mul.s $f4, $f6, $f8
  nop   
  mul.s $f6, $f18, $f16
  lwc1  $f18, 8($a2)
  mul.s $f16, $f10, $f18
  lwc1  $f10, 0x6c($sp)
  add.s $f8, $f4, $f6
  lwc1  $f6, 0x6c($sp)
  add.s $f4, $f16, $f8
  c.lt.s $f14, $f6
  mul.s $f0, $f4, $f12
  bc1f  .L7F0BA000
   nop   
  c.lt.s $f0, $f6
  nop   
  bc1t  .L7F0BA020
   nop   
.L7F0BA000:
  c.lt.s $f10, $f14
  li    $at, 0x3F000000 # 0.500000
  bc1fl .L7F0BA02C
   add.s $f18, $f14, $f0
  c.lt.s $f10, $f0
  nop   
  bc1fl .L7F0BA02C
   add.s $f18, $f14, $f0
.L7F0BA020:
  b     .L7F0BA258
   move  $v0, $zero
  add.s $f18, $f14, $f0
.L7F0BA02C:
  mtc1  $at, $f16
  lwc1  $f4, 0x6c($sp)
  lw    $t6, 0xa0($sp)
  mul.s $f8, $f18, $f16
  lui   $t7, %hi(ptr_bgdata_portals) 
  lw    $t7, %lo(ptr_bgdata_portals)($t7)
  lui   $at, %hi(D_80044900)
  sll   $t8, $t6, 3
  addu  $t0, $t7, $t8
  move  $a3, $zero
  sub.s $f6, $f8, $f4
  move  $a0, $zero
  swc1  $f6, %lo(D_80044900)($at)
  lw    $v0, ($t0)
  lbu   $a2, ($v0)
  blezl $a2, .L7F0BA238
   lwc1  $f18, 0x6c($sp)
  mtc1  $zero, $f2
  li    $t4, 12
  addiu $t1, $a3, 1
.L7F0BA07C:
  div   $zero, $t1, $a2
  mfhi  $a1
  addu  $t5, $v0, $a0
  lwc1  $f18, 4($t5)
  multu $a1, $t4
  bnez  $a2, .L7F0BA09C
   nop   
  break 7
.L7F0BA09C:
  li    $at, -1
  bne   $a2, $at, .L7F0BA0B4
   lui   $at, 0x8000
  bne   $t1, $at, .L7F0BA0B4
   nop   
  break 6
.L7F0BA0B4:
  mflo  $v1
  addu  $t9, $v0, $v1
  lwc1  $f10, 4($t9)
  sub.s $f16, $f10, $f18
  swc1  $f16, 0x74($sp)
  lw    $v0, ($t0)
  addu  $t6, $v0, $v1
  addu  $t7, $v0, $a0
  lwc1  $f4, 8($t7)
  lwc1  $f8, 8($t6)
  sub.s $f6, $f8, $f4
  lwc1  $f4, 0x94($sp)
  swc1  $f6, 0x78($sp)
  lw    $v0, ($t0)
  lwc1  $f8, 0x78($sp)
  addu  $t8, $v0, $v1
  addu  $t9, $v0, $a0
  lwc1  $f18, 0xc($t9)
  lwc1  $f10, 0xc($t8)
  mul.s $f6, $f8, $f4
  swc1  $f8, 0x20($sp)
  sub.s $f16, $f10, $f18
  lwc1  $f10, 0x90($sp)
  lwc1  $f8, 0x74($sp)
  swc1  $f16, 0x7c($sp)
  lwc1  $f18, 0x7c($sp)
  mul.s $f16, $f10, $f18
  sub.s $f6, $f6, $f16
  lwc1  $f16, 0x8c($sp)
  mul.s $f18, $f18, $f16
  swc1  $f6, 0x50($sp)
  mul.s $f4, $f4, $f8
  sub.s $f18, $f18, $f4
  mul.s $f4, $f8, $f10
  lwc1  $f8, 0x20($sp)
  swc1  $f18, 0x54($sp)
  mul.s $f10, $f16, $f8
  sub.s $f16, $f4, $f10
  mul.s $f8, $f6, $f6
  nop   
  mul.s $f4, $f18, $f18
  swc1  $f16, 0x58($sp)
  mul.s $f6, $f16, $f16
  add.s $f10, $f8, $f4
  add.s $f0, $f6, $f10
  c.eq.s $f0, $f2
  nop   
  bc1f  .L7F0BA180
   nop   
  b     .L7F0BA258
   move  $v0, $zero
.L7F0BA180:
  lw    $t5, ($t0)
  lwc1  $f18, 0x50($sp)
  lwc1  $f16, 0x54($sp)
  addu  $v0, $t5, $a0
  lwc1  $f8, 4($v0)
  lwc1  $f6, 8($v0)
  mul.s $f4, $f18, $f8
  nop   
  mul.s $f10, $f16, $f6
  lwc1  $f6, 0xc($v0)
  add.s $f8, $f4, $f10
  lwc1  $f4, 0x58($sp)
  mul.s $f10, $f6, $f4
  add.s $f6, $f10, $f8
  swc1  $f6, 0x5c($sp)
  lwc1  $f10, ($s0)
  mul.s $f8, $f18, $f10
  lwc1  $f18, 4($s0)
  mul.s $f10, $f16, $f18
  lwc1  $f18, 8($s0)
  add.s $f16, $f8, $f10
  mul.s $f8, $f18, $f4
  add.s $f10, $f8, $f16
  mul.s $f0, $f10, $f12
  c.lt.s $f0, $f6
  nop   
  bc1f  .L7F0BA208
   nop   
  beqz  $t3, .L7F0BA200
   nop   
  b     .L7F0BA258
   move  $v0, $zero
.L7F0BA200:
  b     .L7F0BA218
   li    $t2, 1
.L7F0BA208:
  beqz  $t2, .L7F0BA218
   li    $t3, 1
  b     .L7F0BA258
   move  $v0, $zero
.L7F0BA218:
  lw    $v0, ($t0)
  move  $a3, $t1
  addiu $a0, $a0, 0xc
  lbu   $a2, ($v0)
  slt   $at, $t1, $a2
  bnezl $at, .L7F0BA07C
   addiu $t1, $a3, 1
  lwc1  $f18, 0x6c($sp)
.L7F0BA238:
  li    $v1, 2
  c.lt.s $f14, $f18
  nop   
  bc1f  .L7F0BA254
   nop   
  b     .L7F0BA254
   li    $v1, 1
.L7F0BA254:
  move  $v0, $v1
.L7F0BA258:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0xa0
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0BA26C
  move  $v1, $zero
  move  $t0, $a1
  move  $t1, $a2
  li    $v0, 12
.L7F0BA27C:
  lwc1  $f4, ($t0)
  lwc1  $f6, ($t1)
  addu  $t6, $a3, $v1
  addu  $t7, $a0, $v1
  c.lt.s $f4, $f6
  addiu $v1, $v1, 4
  addiu $t0, $t0, 4
  bc1t  .L7F0BA2B8
   nop   
  lwc1  $f8, ($t6)
  lwc1  $f10, ($t7)
  c.lt.s $f8, $f10
  nop   
  bc1f  .L7F0BA2C0
   nop   
.L7F0BA2B8:
  jr    $ra
   move  $v0, $zero

.L7F0BA2C0:
  bne   $v1, $v0, .L7F0BA27C
   addiu $t1, $t1, 4
  li    $v0, 1
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0BA2D4
  addiu $sp, $sp, -0xb8
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
  sw    $a3, 0xc4($sp)
  lui   $at, %hi(room_data_float1)
  lwc1  $f0, %lo(room_data_float1)($at)
  lwc1  $f4, ($a0)
  lw    $s1, ($a3)
  lui   $fp, %hi(D_80044904) 
  mul.s $f6, $f4, $f0
  move  $s4, $a2
  move  $t0, $zero
  addiu $fp, %lo(D_80044904) # addiu $fp, $fp, 0x4904
  addiu $s0, $sp, 0x70
  lw    $s5, 0xc8($sp)
  addiu $s6, $sp, 0x70
  swc1  $f6, 0xa0($sp)
  lwc1  $f8, 4($a0)
  addiu $s7, $sp, 0x64
  mul.s $f10, $f8, $f0
  swc1  $f10, 0xa4($sp)
  lwc1  $f16, 8($a0)
  mul.s $f18, $f16, $f0
  swc1  $f18, 0xa8($sp)
  lwc1  $f4, ($a1)
  mul.s $f6, $f4, $f0
  swc1  $f6, 0x94($sp)
  lwc1  $f8, 4($a1)
  mul.s $f10, $f8, $f0
  swc1  $f10, 0x98($sp)
  lwc1  $f16, 8($a1)
  sw    $s1, 0x7c($sp)
  mul.s $f18, $f16, $f0
  swc1  $f18, 0x9c($sp)
.L7F0BA37C:
  slt   $at, $t0, $s1
  beqz  $at, .L7F0BA574
   sll   $t7, $t0, 2
  addu  $t8, $s4, $t7
  lui   $v0, %hi(ptr_bgdata_portals)
  lw    $v0, %lo(ptr_bgdata_portals)($v0)
  sw    $t8, 0x5c($sp)
.L7F0BA398:
  lw    $t1, ($v0)
  lw    $t9, 0x5c($sp)
  move  $s2, $zero
  beqz  $t1, .L7F0BA558
   lw    $s3, ($t9)
  sw    $t0, 0x8c($sp)
  move  $a3, $v0
  lbu   $t2, 6($a3)
.L7F0BA3B8:
  andi  $t3, $t2, 1
  bnezl $t3, .L7F0BA544
   lw    $t2, 8($a3)
  lbu   $t4, 4($a3)
  beql  $s3, $t4, .L7F0BA3E0
   lw    $at, ($fp)
  lbu   $t5, 5($a3)
  bnel  $s3, $t5, .L7F0BA544
   lw    $t2, 8($a3)
  lw    $at, ($fp)
.L7F0BA3E0:
  lw    $t7, 4($fp)
  lui   $t8, %hi(D_80044910) 
  sw    $at, ($s6)
  lw    $at, 8($fp)
  addiu $t8, %lo(D_80044910) # addiu $t8, $t8, 0x4910
  sw    $t7, 4($s6)
  sw    $at, 8($s6)
  lw    $at, ($t8)
  move  $a2, $zero
  sw    $at, ($s7)
  lw    $t1, 4($t8)
  sw    $t1, 4($s7)
  lw    $at, 8($t8)
  sw    $at, 8($s7)
  lw    $a1, ($a3)
  lbu   $t2, ($a1)
  blez  $t2, .L7F0BA4A0
   move  $a0, $zero
.L7F0BA428:
  addiu $v1, $sp, 0x70
  addiu $v0, $sp, 0x64
.L7F0BA430:
  sll   $t3, $a2, 2
  subu  $t3, $t3, $a2
  sll   $t3, $t3, 2
  addu  $t4, $a1, $t3
  addu  $t5, $t4, $a0
  lwc1  $f0, 4($t5)
  lwc1  $f4, ($v1)
  addiu $a0, $a0, 4
  c.lt.s $f0, $f4
  nop   
  bc1fl .L7F0BA468
   lwc1  $f6, ($v0)
  swc1  $f0, ($v1)
  lwc1  $f6, ($v0)
.L7F0BA468:
  addiu $v1, $v1, 4
  c.lt.s $f6, $f0
  nop   
  bc1fl .L7F0BA484
   addiu $v0, $v0, 4
  swc1  $f0, ($v0)
  addiu $v0, $v0, 4
.L7F0BA484:
  bne   $v0, $s0, .L7F0BA430
   lw    $a1, ($a3)
  lbu   $v0, ($a1)
  addiu $a2, $a2, 1
  slt   $at, $a2, $v0
  bnezl $at, .L7F0BA428
   move  $a0, $zero
.L7F0BA4A0:
  move  $a0, $s6
  move  $a1, $s7
  addiu $a2, $sp, 0xa0
  jal   sub_GAME_7F0BA26C
   addiu $a3, $sp, 0x94
  beqz  $v0, .L7F0BA534
   lui   $t6, %hi(ptr_bgdata_portals) 
  lw    $t6, %lo(ptr_bgdata_portals)($t6)
  move  $t0, $zero
  slt   $at, $s1, $s5
  addu  $a3, $t6, $s2
  lbu   $v0, 4($a3)
  bne   $s3, $v0, .L7F0BA4E0
   move  $v1, $v0
  b     .L7F0BA4E0
   lbu   $v1, 5($a3)
.L7F0BA4E0:
  blez  $s1, .L7F0BA500
   move  $v0, $s4
.L7F0BA4E8:
  lw    $t7, ($v0)
  beq   $v1, $t7, .L7F0BA500
   nop   
  addiu $t0, $t0, 1
  bne   $t0, $s1, .L7F0BA4E8
   addiu $v0, $v0, 4
.L7F0BA500:
  bne   $t0, $s1, .L7F0BA534
   nop   
  beqz  $at, .L7F0BA51C
   sll   $t9, $s1, 2
  addu  $t8, $s4, $t9
  sw    $v1, ($t8)
  addiu $s1, $s1, 1
.L7F0BA51C:
  slt   $at, $s1, $s5
  bnez  $at, .L7F0BA534
   nop   
  lw    $t1, 0xc4($sp)
  b     .L7F0BA590
   sw    $s1, ($t1)
.L7F0BA534:
  lui   $v0, %hi(ptr_bgdata_portals)
  lw    $v0, %lo(ptr_bgdata_portals)($v0)
  addu  $a3, $v0, $s2
  lw    $t2, 8($a3)
.L7F0BA544:
  addiu $s2, $s2, 8
  addiu $a3, $a3, 8
  bnezl $t2, .L7F0BA3B8
   lbu   $t2, 6($a3)
  lw    $t0, 0x8c($sp)
.L7F0BA558:
  lw    $t3, 0x5c($sp)
  lw    $t5, 0x7c($sp)
  addiu $t0, $t0, 1
  addiu $t4, $t3, 4
  slt   $at, $t0, $t5
  bnez  $at, .L7F0BA398
   sw    $t4, 0x5c($sp)
.L7F0BA574:
  lw    $t6, 0x7c($sp)
  beql  $s1, $t6, .L7F0BA58C
   lw    $t7, 0xc4($sp)
  b     .L7F0BA37C
   sw    $s1, 0x7c($sp)
  lw    $t7, 0xc4($sp)
.L7F0BA58C:
  sw    $s1, ($t7)
.L7F0BA590:
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
   addiu $sp, $sp, 0xb8
");

asm(R"
glabel sub_GAME_7F0BA5C0
  sltu  $at, $a0, $a1
  beqz  $at, .L7F0BA638
   move  $v0, $a0
  lui   $a2, %hi(D_80044940)
  addiu $a2, %lo(D_80044940) # addiu $a2, $a2, 0x4940
  lw    $t6, ($a2)
.L7F0BA5D8:
  lui   $t7, %hi(D_80044940) 
  addiu $t7, %lo(D_80044940) # addiu $t7, $t7, 0x4940
  beqz  $t6, .L7F0BA628
   move  $v1, $a2
  lw    $a0, ($t7)
  lw    $t8, ($v0)
.L7F0BA5F0:
  bnel  $t8, $a0, .L7F0BA61C
   lw    $a0, 0x10($v1)
  lw    $t9, 4($v0)
  lw    $t0, 4($v1)
  bnel  $t9, $t0, .L7F0BA61C
   lw    $a0, 0x10($v1)
  lw    $at, 8($v1)
  sw    $at, ($v0)
  lw    $t2, 0xc($v1)
  sw    $t2, 4($v0)
  lw    $a0, 0x10($v1)
.L7F0BA61C:
  addiu $v1, $v1, 0x10
  bnezl $a0, .L7F0BA5F0
   lw    $t8, ($v0)
.L7F0BA628:
  addiu $v0, $v0, 8
  sltu  $at, $v0, $a1
  bnezl $at, .L7F0BA5D8
   lw    $t6, ($a2)
.L7F0BA638:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0BA640 /*DynamicCCRMLUT(Int DLSize (a0), Gfx GBICommand(a1), Gfx ReplacementGBICommand (a2))*/
  beqz  $a1, .L7F0BA654   /*if a1 = 0 goto L7F0BA654*/
   move  $v0, $a0         /*v0 = a0*/
  sltu  $at, $v0, $a1     /*if a1 < v0   then goto L7F0BA668*/
  bnez  $at, .L7F0BA668   
   nop   
.L7F0BA654:
  bnez  $a1, .L7F0BA710   /*if a1 != 0 goto return*/
   nop   
  lb    $t6, ($a0)        /*t6 = byte(a0)*/
  li    $t0, -72          /*t0 = 0xB8*/
  beq   $t0, $t6, .L7F0BA710  /*if t6 = 0xB8 return (B8 = EndDl())*/
.L7F0BA668:
   lui   $t1, %hi(ptrDynamic_CC_RM_LUT) 
  addiu $t1, %lo(ptrDynamic_CC_RM_LUT) # addiu $t1, $t1, 0x4d88
  sll   $t7, $a2, 2   /*t7 = a2 << 2*/
  addu  $t8, $t1, $t7 /*t8 = t7 + t1*/
  lw    $v1, ($t8)
  lui   $a3, %hi(D_80044DB0)
  lw    $a3, %lo(D_80044DB0)($a3) # 0x4DB0($a3), 
  lw    $a0, ($v1)
  li    $t0, -72
  beqz  $a0, .L7F0BA6D4
   nop   
  lw    $t9, ($v0)
.L7F0BA698:
  bnel  $t9, $a0, .L7F0BA6C8
   lw    $a0, 0x10($v1)
  lw    $t2, 4($v0)
  lw    $t3, 4($v1)
  bnel  $t2, $t3, .L7F0BA6C8
   lw    $a0, 0x10($v1)
  lw    $at, 8($v1)
  addiu $a3, $a3, 1
  sw    $at, ($v0)
  lw    $t5, 0xc($v1)
  sw    $t5, 4($v0)
  lw    $a0, 0x10($v1)
.L7F0BA6C8:
  addiu $v1, $v1, 0x10
  bnezl $a0, .L7F0BA698
   lw    $t9, ($v0)
.L7F0BA6D4:
  beqz  $a1, .L7F0BA6F0
   addiu $v0, $v0, 8
  lui   $at, %hi(D_80044DB0)
  sw    $a3, %lo(D_80044DB0)($at)
  sltu  $at, $v0, $a1
  bnez  $at, .L7F0BA668
   nop   
.L7F0BA6F0:
  lui   $at, %hi(D_80044DB0)
  bnez  $a1, .L7F0BA710
   sw    $a3, %lo(D_80044DB0)($at)
  lui   $at, %hi(D_80044DB0)
  sw    $a3, %lo(D_80044DB0)($at)
  lb    $t6, ($v0)
  bne   $t0, $t6, .L7F0BA668
   nop   
.L7F0BA710:
  jr    $ra
   nop   
");
