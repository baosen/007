#ifndef _BONDCONSTANTS_H_
#define _BONDCONSTANTS_H_

#define GAME_TICKRATE 60

#define SECS_TO_TIMER60(SECS) (SECS * GAME_TICKRATE)
#define MINS_TO_TIMER60(MINS) (SECS_TO_TIMER60(MINS * GAME_TICKRATE))

/* special character number identifiers */
#define CHR_BOND_CINEMA                                                        \
  -8 /* only works when bond has a third person model (intro/exit cutscene) */
#define CHR_CLONE -7
#define CHR_SEE_SHOT -6 /* stored as chr->chrseeshot */
#define CHR_SEE_DIE -5  /* stored as chr->chrseedie */
#define CHR_PRESET -4   /* stored as chr->chrpreset1 */
#define CHR_SELF -3

/* private character ID, cannot be accessed with ai commands */
#define CHR_OBJECTIVE -2 /* objective ai list chr ID */
#define CHR_FREE -1 /* chr IDs when free'd (killed or removed from level) */
#define CHR_SPAWN_NUM_START                                                    \
  5000 /* default chr num for spawned guards with ai command BD/BE */
#define CHR_CLONED_NUM_START                                                   \
  10000 /* default chr num for cloed guards with ai command C1 */

#define PAD_PRESET 9000 /* stored as chr->padpreset1 */

typedef unsigned short PAD;
typedef unsigned short PADEXTRA;

#define PADEXTRA_START 10000
#define PADEX(PAD) (PAD + PADEXTRA_START) /* used for setups */

typedef enum RGBA_ENUM { RED, GREEN, BLUE, ALPHA } RGBA_ENUM;

typedef enum MISSION_BRIEFING {
  BRIEF_OVERVIEW,
  BRIEF_M,
  BRIEF_Q,
  BRIEF_MONEYPENNY
} MISSION_BRIEFING;

typedef enum DIFFICULTY {
  DIFFICULTY_AGENT,
  DIFFICULTY_SECRET,
  DIFFICULTY_00,
  DIFFICULTY_007,
  DIFFICULTY_MULTI = 0xFFFFFFFF
} DIFFICULTY;

typedef enum LEVELID {
  LEVELID_BUNKER1 = 0x9,
  LEVELID_SILO = 0x14,
  LEVELID_STATUE = 0x16,
  LEVELID_CONTROL = 0x17,
  LEVELID_ARCHIVES = 0x18,
  LEVELID_TRAIN = 0x19,
  LEVELID_FRIGATE = 0x1A,
  LEVELID_BUNKER2 = 0x1B,
  LEVELID_AZTEC = 0x1C,
  LEVELID_STREETS = 0x1D,
  LEVELID_DEPOT = 0x1E,
  LEVELID_COMPLEX = 0x1F,
  LEVELID_EGYPT = 0x20,
  LEVELID_DAM = 0x21,
  LEVELID_FACILITY = 0x22,
  LEVELID_RUNWAY = 0x23,
  LEVELID_SURFACE = 0x24,
  LEVELID_JUNGLE = 0x25,
  LEVELID_TEMPLE = 0x26,
  LEVELID_CAVERNS = 0x27,
  LEVELID_CITADEL = 0x28,
  LEVELID_CRADLE = 0x29,
  LEVELID_SHO = 0x2A,
  LEVELID_SURFACE2 = 0x2B,
  LEVELID_ELD = 0x2C,
  LEVELID_BASEMENT = 0x2D,
  LEVELID_STACK = 0x2E,
  LEVELID_LUE = 0x2F,
  LEVELID_LIBRARY = 0x30,
  LEVELID_RIT = 0x31,
  LEVELID_CAVES = 0x32,
  LEVELID_EAR = 0x33,
  LEVELID_LEE = 0x34,
  LEVELID_LIP = 0x35,
  LEVELID_CUBA = 0x36,
  LEVELID_WAX = 0x37,
  LEVELID_PAM = 0x38,
  LEVELID_MAX = 0x39,
  LEVELID_TITLE = 0x5A,
  LEVELID_NONE = 0xFFFFFFFF
} LEVELID;

typedef enum LEVEL_SOLO_SEQUENCE {
  SP_LEVEL_DAM = 1,
  SP_LEVEL_FACILITY,
  SP_LEVEL_RUNWAY,
  SP_LEVEL_SURFACE1,
  SP_LEVEL_BUNKER1,
  SP_LEVEL_SILO,
  SP_LEVEL_FRIGATE,
  SP_LEVEL_SURFACE2,
  SP_LEVEL_BUNKER2,
  SP_LEVEL_STATUE,
  SP_LEVEL_ARCHIVES,
  SP_LEVEL_STREETS,
  SP_LEVEL_DEPOT,
  SP_LEVEL_TRAIN,
  SP_LEVEL_JUNGLE,
  SP_LEVEL_CONTROL,
  SP_LEVEL_CAVERNS,
  SP_LEVEL_CRADLE,
  SP_LEVEL_AZTEC,
  SP_LEVEL_EGYPT
} LEVEL_SOLO_SEQUENCE;

typedef enum LEVEL_INDEX {
  LEVEL_INDEX_SEVBUNKER,
  LEVEL_INDEX_SILO,
  LEVEL_INDEX_STATUE,
  LEVEL_INDEX_CONTROL,
  LEVEL_INDEX_ARCH,
  LEVEL_INDEX_TRA,
  LEVEL_INDEX_DEST,
  LEVEL_INDEX_SEVB,
  LEVEL_INDEX_AZT,
  LEVEL_INDEX_PETE,
  LEVEL_INDEX_DEPO,
  LEVEL_INDEX_REF,
  LEVEL_INDEX_CRYP,
  LEVEL_INDEX_DAM,
  LEVEL_INDEX_ARK,
  LEVEL_INDEX_RUN,
  LEVEL_INDEX_SEVX,
  LEVEL_INDEX_JUN,
  LEVEL_INDEX_DISH,
  LEVEL_INDEX_CAVE,
  LEVEL_INDEX_CAT,
  LEVEL_INDEX_CRAD,
  LEVEL_INDEX_SHO,
  LEVEL_INDEX_SEVXB,
  LEVEL_INDEX_ELD,
  LEVEL_INDEX_IMP,
  LEVEL_INDEX_ASH,
  LEVEL_INDEX_LUE,
  LEVEL_INDEX_AME,
  LEVEL_INDEX_RIT,
  LEVEL_INDEX_OAT,
  LEVEL_INDEX_EAR,
  LEVEL_INDEX_LEE,
  LEVEL_INDEX_LIP,
  LEVEL_INDEX_LEN,
  LEVEL_INDEX_WAX,
  LEVEL_INDEX_PAM,
  LEVEL_INDEX_X
} LEVEL_INDEX;

/* language file to slot allocation */
#define TEXT(TEXTBANK, TEXTSLOT) ((TEXTBANK * 0x0400U) + TEXTSLOT)

typedef enum TEXTBANK_LEVEL_INDEX {
  LNULL,      /* Null (unused) */
  LAME,       /* Library (multi) */
  LARCH,      /* Archives */
  LARK,       /* Facility */
  LASH,       /* Stack (multi) */
  LAZT,       /* Aztec */
  LCAT,       /* Citadel (multi) */
  LCAVE,      /* Caverns */
  LAREC,      /* Control */
  LCRAD,      /* Cradle */
  LCRYP,      /* Egypt */
  LDAM,       /* Dam */
  LDEPO,      /* Depot */
  LDEST,      /* Frigate */
  LDISH,      /* Temple (multi) */
  LEAR,       /* Ear (unused) */
  LELD,       /* Eld (unused) */
  LIMP,       /* Basement (multi) */
  LJUN,       /* Jungle */
  LLEE,       /* Lee (unused) */
  LLEN,       /* Cuba */
  LLIP,       /* Lip (unused) */
  LLUE,       /* Lue (unused) */
  LOAT,       /* Cave (multi) */
  LPAM,       /* Pam (unused) */
  LPETE,      /* Streets */
  LREF,       /* Complex (multi) */
  LRIT,       /* Rit (unused) */
  LRUN,       /* Runway */
  LSEVB,      /* Bunker 2 */
  LSEV,       /* Bunker 1 */
  LSEVX,      /* Surface 1 */
  LSEVXB,     /* Surface 2 */
  LSHO,       /* Sho (unused) */
  LSILO,      /* Silo */
  LSTAT,      /* Statue */
  LTRA,       /* Train */
  LWAX,       /* Wax (unused) */
  LGUN,       /* Guns */
  LTITLE,     /* Stage and menu titles */
  LMPMENU,    /* Multi menus */
  LPROPOBJ,   /* In-game pickups */
  LMPWEAPONS, /* Multi weapon select */
  LOPTIONS,   /* Solo in-game menus */
  LMISC       /* Cheat options */
} TEXTBANK_LEVEL_INDEX;

typedef enum MP_STAGE_SELECTED {
  MP_STAGE_RANDOM,
  MP_STAGE_TEMPLE,
  MP_STAGE_COMPLEX,
  MP_STAGE_CAVES,
  MP_STAGE_LIBRARY,
  MP_STAGE_BASEMENT,
  MP_STAGE_STACK,
  MP_STAGE_FACILITY,
  MP_STAGE_BUNKER,
  MP_STAGE_ARCHIVES,
  MP_STAGE_CAVERNS,
  MP_STAGE_EGYPT
} MP_STAGE_SELECTED;

typedef enum GENDER { FEMALE, MALE } GENDER;

typedef enum BODIES {
  BODY_Jungle_Commando,
  BODY_St_Petersburg_Guard,
  BODY_Russian_Soldier,
  BODY_Russian_Infantry,
  BODY_Janus_Special_Forces,
  BODY_Tuxedo,
  BODY_Boris,
  BODY_Ourumov,
  BODY_Trevelyan_Janus,
  BODY_Trevelyan_006,
  BODY_Valentin_,
  BODY_Xenia,
  BODY_Baron_Samedi,
  BODY_Jaws,
  BODY_Mayday,
  BODY_Oddjob,
  BODY_Natalya_Skirt,
  BODY_Janus_Marine,
  BODY_Russian_Commandant,
  BODY_Siberian_Guard_1_Mishkin,
  BODY_Naval_Officer,
  BODY_Siberian_Special_Forces,
  BODY_Special_Operations_Uniform,
  BODY_Formal_Wear,
  BODY_Jungle_Fatigues,
  BODY_Parka,
  BODY_Unused_Female,
  BODY_Rosika,
  BODY_Scientist_2_Female,
  BODY_Civilian_1_Female,
  BODY_Unused_Male_1,
  BODY_Unused_Male_2,
  BODY_Civilian_4,
  BODY_Civilian_2,
  BODY_Civilian_3,
  BODY_Scientist_1_Male,
  BODY_Helicopter_Pilot,
  BODY_Siberian_Guard_2,
  BODY_Arctic_Commando,
  BODY_Moonraker_Elite_1_Male,
  BODY_Moonraker_Elite_2_Female,
  BODY_Left_Suit_Hand_Floating_Arm,
  BODY_Male_Karl,
  BODY_Male_Alan,
  BODY_Male_Pete,
  BODY_Male_Martin,
  BODY_Male_Mark,
  BODY_Male_Duncan,
  BODY_Male_Shaun,
  BODY_Male_Dwayne,
  BODY_Male_B,
  BODY_Male_Dave_Dr_Doak,
  BODY_Male_Grant,
  BODY_Male_Des,
  BODY_Male_Chris,
  BODY_Male_Lee,
  BODY_Male_Neil,
  BODY_Male_Jim,
  BODY_Male_Robin,
  BODY_Male_Steve_H,
  BODY_Male_Terrorist,
  BODY_Male_Biker,
  BODY_Male_Graeme,
  BODY_Male_Steve_Ellis,
  BODY_Male_Joel,
  BODY_Male_Scott,
  BODY_Male_Joe_Altered,
  BODY_Male_Ken,
  BODY_Male_Joe,
  BODY_Male_Mishkin,
  BODY_Female_Sally,
  BODY_Female_Marion_Rosika,
  BODY_Female_Mandy,
  BODY_Female_Vivien,
  BODY_Male_Pierce_Bond_1,
  BODY_Male_Pierce_Bond_2,
  BODY_Male_Pierce_Bond_3,
  BODY_Male_Pierce_Bond_Parka,
  BODY_Male_Pierce_Bond_Tuxedo,
  BODY_Natalya_Jungle_Fatigues
} BODIES;

typedef enum HEADS {
  HEAD_Male_Karl = 0x2A,
  HEAD_Male_Alan = 0x2B,
  HEAD_Male_Pete = 0x2C,
  HEAD_Male_Martin = 0x2D,
  HEAD_Male_Mark = 0x2E,
  HEAD_Male_Duncan = 0x2F,
  HEAD_Male_Shaun = 0x30,
  HEAD_Male_Dwayne = 0x31,
  HEAD_Male_B = 0x32,
  HEAD_Male_Dave_Dr_Doak = 0x33,
  HEAD_Male_Grant = 0x34,
  HEAD_Male_Des = 0x35,
  HEAD_Male_Chris = 0x36,
  HEAD_Male_Lee = 0x37,
  HEAD_Male_Neil = 0x38,
  HEAD_Male_Jim = 0x39,
  HEAD_Male_Robin = 0x3A,
  HEAD_Male_Steve_H = 0x3B,
  HEAD_Male_Terrorist = 0x3C,
  HEAD_Male_Biker = 0x3D,
  HEAD_Male_Graeme = 0x3E,
  HEAD_Male_Steve_Ellis = 0x3F,
  HEAD_Male_Joel = 0x40,
  HEAD_Male_Scott = 0x41,
  HEAD_Male_Joe_Altered = 0x42,
  HEAD_Male_Ken = 0x43,
  HEAD_Male_Joe = 0x44,
  HEAD_Male_Mishkin = 0x45,
  HEAD_Female_Sally = 0x46,
  HEAD_Female_Marion_Rosika = 0x47,
  HEAD_Female_Mandy = 0x48,
  HEAD_Female_Vivien = 0x49,
  HEAD_Male_Pierce_Bond_1 = 0x4A,
  HEAD_Male_Pierce_Bond_2 = 0x4B,
  HEAD_Male_Pierce_Bond_3 = 0x4C,
  HEAD_Male_Pierce_Bond_Parka = 0x4D,
  HEAD_Male_Pierce_Bond_Tuxedo_DEFAULT = 0x4E,
  HEAD_Natalya_Jungle_Fatigues = 0x4F
} HEADS;

typedef enum mission_setup_type {
  MISSION_PART,
  MISSION_HEADER
} mission_setup_type;

typedef enum MUSIC_TRACKS {
  M_ARCHIVES = 11,
  M_ARCHIVESX = 37,
  M_AZTEC = 25,
  M_AZTECX = 46,
  M_BUNKER1 = 15,
  M_BUNKER1X = 41,
  M_BUNKER2 = 16,
  M_BUNKER2X = 42,
  M_CITADEL = 6,
  M_CONTROL = 8,
  M_CONTROLX = 33,
  M_CRADLE = 19,
  M_CRADLEX = 48,
  M_CUBA = 49,
  M_DAM = 9,
  M_DAMX = 35,
  M_DEATHSOLO = 27,
  M_DEPOT = 4,
  M_DEPOTX = 32,
  M_EGYPTIAN = 22,
  M_EGYPTIANX = 39,
  M_EGYPTX = 47,
  M_ELEVATOR_CONTROL = 18,
  M_ELEVATOR_WC = 21,
  M_END_SOMETHING = 62,
  M_FACILITY = 7,
  M_FACILITYX = 31,
  M_FOLDERS = 23,
  M_FRIGATE = 10,
  M_FRIGATEX = 36,
  M_GUITARGLISS = 54,
  M_INTRO = 2,
  M_INTROSWOOSH = 44,
  M_JUNGLE = 55,
  M_JUNGLEX = 43,
  M_MPDEATH = 58,
  M_MPTHEME = 5,
  M_MPTHEME2 = 13,
  M_MPTHEME3 = 52,
  M_NONE = 0,
  M_RUNWAY = 50,
  M_RUNWAYPLANE = 51,
  M_RUNWAYX = 56,
  M_SHORT_SOLO_DEATH = 1,
  M_SILO = 12,
  M_SILOX = 38,
  M_STATUE = 17,
  M_STATUEPART = 61,
  M_STATUEX = 45,
  M_STREETS = 14,
  M_STREETSX = 40,
  M_SURFACE1 = 57,
  M_SURFACE2 = 28,
  M_SURFACE2END = 60,
  M_SURFACE2X = 59,
  M_TRAIN = 3,
  M_TRAINX = 29,
  M_UNK = 20,
  M_UNK2 = 30,
  M_WATCH = 24,
  M_WATERCAVERNS = 26,
  M_WATERCAVERNSX = 34,
  M_WIND = 53
} MUSIC_TRACKS;

typedef enum GAMEMODE {
  GAMEMODE_SOLO = 0x0,
  GAMEMODE_MULTI,
  GAMEMODE_CHEATS,
  GAMEMODE_INTRO = 0xFFFFFFFF
} GAMEMODE;

typedef enum MPSCENARIOS {
  SCENARIO_NORMAL,
  SCENARIO_YOLT,
  SCENARIO_TLD,
  SCENARIO_MWTGG,
  SCENARIO_LTK,
  SCENARIO_2v2,
  SCENARIO_3v1,
  SCENARIO_2v1
} MPSCENARIOS;

typedef enum WATCH_BRIEFING_PAGE {
  BRIEFING_TITLE,
  BRIEFING_OVERVIEW,
  BRIEFING_M,
  BRIEFING_Q,
  BRIEFING_MONEYPENNY
} WATCH_BRIEFING_PAGE;

typedef enum MENU {
  MENU_LEGAL_SCREEN,
  MENU_NINTENDO_LOGO,
  MENU_RAREWARE_LOGO,
  MENU_EYE_INTRO,
  MENU_GOLDENEYE_LOGO,
  MENU_FILE_SELECT,
  MENU_MODE_SELECT,
  MENU_MISSION_SELECT,
  MENU_DIFFICULTY,
  MENU_007_OPTIONS,
  MENU_BRIEFING,
  MENU_RUN_STAGE,
  MENU_MISSION_FAILED,
  MENU_MISSION_COMPLETE,
  MENU_MP_OPTIONS,
  MENU_MP_CHAR_SELECT,
  MENU_MP_HANDICAP,
  MENU_MP_CONTROL_STYLE,
  MENU_MP_STAGE_SELECT,
  MENU_MP_SCENARIO_SELECT,
  MENU_MP_TEAMS,
  MENU_CHEAT,
  MENU_NO_CONTROLLERS,
  MENU_SWITCH_SCREENS,
  MENU_DISPLAY_CAST,
  MENU_SPECTRUM_EMU
} MENU;

typedef enum CONTROLLER_CONFIG {
  CONTROLLER_CONFIG_HONEY,
  CONTROLLER_CONFIG_SOLITARE,
  CONTROLLER_CONFIG_KISSY,
  CONTROLLER_CONFIG_GOODNIGHT,
  CONTROLLER_CONFIG_PLENTY,
  CONTROLLER_CONFIG_GALORE,
  CONTROLLER_CONFIG_DOMINO,
  CONTROLLER_CONFIG_GOODHEAD,
  CONTROLLER_CONFIG_CINEMA
} CONTROLLER_CONFIG;

typedef enum CUFF_TYPES {
  CUFF_BLUE,
  CUFF_TUX,
  CUFF_JUNGLE,
  CUFF_BOILER,
  CUFF_SNOW,
  CUFF_WHITE,
  CUFF_TUX6,
  CUFF_TUX7,
  CUFF_TUX8
} CUFF_TYPES;

typedef enum ITEM_IDS {
  ITEM_UNARMED,
  ITEM_FIST,
  ITEM_KNIFE,
  ITEM_THROWKNIFE,
  ITEM_WPPK,
  ITEM_WPPKSIL,
  ITEM_TT33,
  ITEM_SKORPION,
  ITEM_AK47,
  ITEM_UZI,
  ITEM_MP5K,
  ITEM_MP5KSIL,
  ITEM_SPECTRE,
  ITEM_M16,
  ITEM_FNP90,
  ITEM_SHOTGUN,
  ITEM_AUTOSHOT,
  ITEM_SNIPERRIFLE,
  ITEM_RUGER,
  ITEM_GOLDENGUN,
  ITEM_SILVERWPPK,
  ITEM_GOLDWPPK,
  ITEM_LASER,
  ITEM_WATCHLASER,
  ITEM_GRENADELAUNCH,
  ITEM_ROCKETLAUNCH,
  ITEM_GRENADE,
  ITEM_TIMEDMINE,
  ITEM_PROXIMITYMINE,
  ITEM_REMOTEMINE,
  ITEM_TRIGGER,
  ITEM_TASER,
  ITEM_TANKSHELLS,
  ITEM_BOMBCASE,
  ITEM_PLASTIQUE,
  ITEM_FLAREPISTOL,
  ITEM_PITONGUN,
  ITEM_BUNGEE,
  ITEM_DOORDECODER,
  ITEM_BOMBDEFUSER,
  ITEM_CAMERA,
  ITEM_LOCKEXPLODER,
  ITEM_DOOREXPLODER,
  ITEM_BRIEFCASE,
  ITEM_WEAPONCASE,
  ITEM_SAFECRACKERCASE,
  ITEM_KEYANALYSERCASE,
  ITEM_BUG,
  ITEM_MICROCAMERA,
  ITEM_BUGDETECTOR,
  ITEM_EXPLOSIVEFLOPPY,
  ITEM_POLARIZEDGLASSES,
  ITEM_DARKGLASSES,
  ITEM_CREDITCARD,
  ITEM_GASKEYRING,
  ITEM_DATATHIEF,
  ITEM_WATCHIDENTIFIER,
  ITEM_WATCHCOMMUNICATOR,
  ITEM_WATCHGEIGERCOUNTER,
  ITEM_WATCHMAGNETREPEL,
  ITEM_WATCHMAGNETATTRACT,
  ITEM_GOLDENEYEKEY,
  ITEM_BLACKBOX,
  ITEM_CIRCUITBOARD,
  ITEM_CLIPBOARD,
  ITEM_STAFFLIST,
  ITEM_DOSSIERRED,
  ITEM_PLANS,
  ITEM_SPYFILE,
  ITEM_BLUEPRINTS,
  ITEM_MAP,
  ITEM_AUDIOTAPE,
  ITEM_VIDEOTAPE,
  ITEM_DATTAPE,
  ITEM_SPOOLTAPE,
  ITEM_MICROFILM,
  ITEM_MICROCODE,
  ITEM_LECTRE,
  ITEM_MONEY,
  ITEM_GOLDBAR,
  ITEM_HEROIN,
  ITEM_KEYCARD,
  ITEM_KEYYALE,
  ITEM_KEYBOLT,
  ITEM_SUIT_LF_HAND,
  ITEM_JOYPAD,
  ITEM_56,
  ITEM_57,
  ITEM_TOKEN
} ITEM_IDS;

typedef enum PROPS {
  PROP_alarm1,           /* Beta Alarm / Default Multi Weapon */
  PROP_alarm2,           /* Alarm */
  PROP_explosionbit,     /* White Pyramid (Explosion Bit) */
  PROP_ammo_crate1,      /* Ammo Crate (Brown w/ Edge Brace, 6x240 Black) */
  PROP_ammo_crate2,      /* Ammo Crate (Brown w/ Center Brace, 12x8 Black) */
  PROP_ammo_crate3,      /* Ammo Crate (Green w/ Center Brace, 12x8 Brown) */
  PROP_ammo_crate4,      /* Ammo Crate (Green w/ Edge Brace, 6x8 White) */
  PROP_ammo_crate5,      /* Ammo Crate (Green w/ Double Brace, 24x60 Black) */
  PROP_bin1,             /* Rusted Trash Bin */
  PROP_blotter1,         /* Desk Blotter */
  PROP_book1,            /* Red Book */
  PROP_bookshelf1,       /* Bookshelf */
  PROP_bridge_console1a, /* Bridge Console w/ Monitor, Navigation + Keyboard 1A
                          */
  PROP_bridge_console1b, /* Bridge Console w/ Navigation 1B */
  PROP_bridge_console2a, /* Bridge Console w/ Navigation, Monitor + Keyboard 2A
                          */
  PROP_bridge_console2b, /* Bridge Console w/ Various Controls 2B */
  PROP_bridge_console3a, /* Bridge Console w/ Monitor, Navigation + Keyboard 3A
                          */
  PROP_bridge_console3b, /* Bridge Console w/ Monitor, Keyboard + Navigation 3B
                          */
  PROP_card_box1,        /* Cardboard Box, Kapto|Enb */
  PROP_card_box2,        /* Cardboard Box, Red Arrow, Bahko */
  PROP_card_box3,        /* Cardboard Box, Scrawled Text, Bahah */
  PROP_card_box4_lg,     /* Cardboard Box, Three Seams */
  PROP_card_box5_lg,     /* Cardboard Box, Two Seams, Bahah */
  PROP_card_box6_lg,     /* Cardboard Box, Bahko */
  PROP_cctv,             /* Surveillance Camera */
  PROP_console1,         /* Double Screen Consoles w/ Keyboards */
  PROP_console2,         /* Double Screen Consoles w/ Left Keyboard */
  PROP_console3,         /* Double Screen Consoles w/ Right Keyboard */
  PROP_console_seva,     /* Console w/ Keyboard */
  PROP_console_sevb,     /* Console w/ Monitor + Keyboard */
  PROP_console_sevc,     /* Console w/ Switches */
  PROP_console_sevd,     /* Console w/ Five Gauges */
  PROP_console_sev2a,    /* Console w/ Four Faders */
  PROP_console_sev2b,    /* Console w/ Monitor, Keyboard + Switches */
  PROP_console_sev2c,    /* Console w/ Three Gauges */
  PROP_console_sev2d,    /* Console w/ Pressure Gauge */
  PROP_console_sev_GEa,  /* Console w/ GoldenEye Key Slot */
  PROP_console_sev_GEb,  /* Console w/ Faders + Pressure Gauge */
  PROP_desk1,            /* Desk w/ Kickplate */
  PROP_desk2,            /* Desk */
  PROP_desk_lamp2,       /* Desk Lamp */
  PROP_disc_reader,      /* External Hard Drive */
  PROP_disk_drive1,      /* Floppy Disc Drive */
  PROP_filing_cabinet1,  /* Filing Cabinet */
  PROP_jerry_can1,       /* Jerrycan (Fuel Container) */
  PROP_keyboard1,        /* Computer Keyboard */
  PROP_kit_units1,       /* Kitchen Cabinets */
  PROP_letter_tray1,     /* Letter Tray */
  PROP_mainframe1,       /* Mainframe, Basic */
  PROP_mainframe2,       /* Mainframe, Advanced */
  PROP_metal_chair1,     /* Chair (Metal) */
  PROP_metal_crate1,     /* Metal Crate, 6 Top Corner */
  PROP_metal_crate2,     /* Metal Crate, 6 Bottom Corner */
  PROP_metal_crate3,     /* Metal Crate, Toxic Materials */
  PROP_metal_crate4,     /* Metal Crate, Double Stripe - Class D1 Hazard */
  PROP_missile_rack,     /* Naval Harpoon Missile in Containment Rack */
  PROP_missile_rack2,    /* Naval Harpoon Missiles in Containment Racks x4 */
  PROP_oil_drum1,        /* Oil Drum, Single Stripe, Ribbed */
  PROP_oil_drum2,        /* Oil Drum, Single Stripe, Ribbed - Class D1 Hazard */
  PROP_oil_drum3,        /* Oil Drum, Single Stripe, Ribbed - Toxic Materials */
  PROP_oil_drum5,        /* Oil Drum, Double Stripe - Toxic Materials */
  PROP_oil_drum6,        /* Oil Drum - Toxic Materials */
  PROP_oil_drum7,        /* Oil Drum, Double Dashes - Class D1 Hazard */
  PROP_padlock,          /* Padlock */
  PROP_phone1,           /* Telephone */
  PROP_radio_unit1,      /* Radio Tuner w/ 1 Knob + 2 Gauges */
  PROP_radio_unit2,      /* Radio Tuner w/ 1 Knob + 5 Gauges */
  PROP_radio_unit3,      /* Radio Tuner w/ 3 Knobs + 5 Gauges */
  PROP_radio_unit4,      /* Radio Tuner w/ 3 Knobs + 2 Gauges */
  PROP_sat1_reflect,     /* GoldenEye Satellite */
  PROP_satdish,          /* Satellite Dish (Arkangelsk) */
  PROP_satbox,           /* Uplink Box */
  PROP_stool1,           /* Wooden Stool */
  PROP_swivel_chair1,    /* Swivel Chair */
  PROP_torpedo_rack,     /* Naval Torpedo Rack x3 */
  PROP_tv1,              /* Television Monitor */
  PROP_tv_holder,        /* Hanging Monitor Rack */
  PROP_tvscreen,         /* Wall Monitor Screen */
  PROP_tv4screen,        /* Wall Monitor Screens, 4-in-1 */
  PROP_wood_lg_crate1,   /* Wooden Crate w/ #4 Label, Bahah */
  PROP_wood_lg_crate2,   /* Wooden Crate, Darker Shading, Kapto|Enb */
  PROP_wood_md_crate3,   /* Wooden Crates x8, Bahko */
  PROP_wood_sm_crate4,   /* Wooden Crate w/ #2 Label, Bahko */
  PROP_wood_sm_crate5,   /* Wooden Crate w/ #4 Label, Darker Shading, Bahah */
  PROP_wood_sm_crate6,   /* Wooden Crate w/ UP Arrow, Kapto|Enb */
  PROP_wooden_table1,    /* Wooden Table */
  PROP_swipe_card2,      /* Keycard */
  PROP_borg_crate,       /* Blue and Gold Printed Circuit Cube (Borg Crate) */
  PROP_boxes4x4,         /* Metal Crate Stack, 4x4 */
  PROP_boxes3x4,         /* Metal Crate Stack, 3x4 */
  PROP_boxes2x4,         /* Metal Crate Stack, 2x4 */
  PROP_sec_panel,        /* Security Card Panel */
  PROP_ICBM_nose,        /* Silo Missile (ICBM), Nose Cone Only */
  PROP_ICBM,             /* Silo Missile (ICBM) */
  PROP_tuning_console1,  /* Dual Consoles on Castors */
  PROP_desk_arecibo1,    /* Computer Work Desk */
  PROP_locker3,          /* Lockers, Single Venting */
  PROP_locker4,          /* Lockers, Double Venting */
  PROP_roofgun,          /* Ceiling Mounted Drone Gun */
  PROP_dest_engine,      /* Frigate Engine */
  PROP_dest_exocet,      /* Naval MK 29 Missile Launcher (Exocet) */
  PROP_dest_gun,         /* Naval 100 mm Gun Turret (TR 100) */
  PROP_dest_harpoon,     /* Naval MK 141 Launch Canisters (Harpoon) */
  PROP_dest_seawolf,     /* Naval MK 26 Dual Missile Launcher (Seawolf) */
  PROP_window,           /* Window Glass */
  PROP_window_lib_lg1,   /* Window Glass, Lattice Frame, 4x10 (single-sided) */
  PROP_window_lib_sm1,   /* Window Glass, Lattice Frame, 4x3 (double-sided) */
  PROP_window_cor11,     /* Window Glass, Lattice Frame, 4x4 (single-sided) */
  PROP_jungle3_tree,     /* Jungle Large Tree */
  PROP_palm,             /* Jungle Palm Tree */
  PROP_palmtree,        /* Jungle Palm Tree, Resprouting After Loss of Fronds */
  PROP_plant2b,         /* Jungle Plant, Low Shrub */
  PROP_labbench,        /* Laboratory Table w/ Sink Drains */
  PROP_gasbarrel,       /* White Bin */
  PROP_gasbarrels,      /* White Bins x4 */
  PROP_bodyarmour,      /* Body Armor */
  PROP_bodyarmourvest,  /* Body Armor (Vest) */
  PROP_gastank,         /* Bottling Tank */
  PROP_glassware1,      /* Glass Cup */
  PROP_hatchbolt,       /* Metallic Securing Strip (Hatch Bolt) */
  PROP_brakeunit,       /* Train Brake Controller */
  PROP_ak47mag,         /* Gun Magazine (KF7 Soviet) */
  PROP_m16mag,          /* Gun Magazine (AR33 Assault Rifle) */
  PROP_mp5kmag,         /* Gun Magazine (D5K Deutsche) */
  PROP_skorpionmag,     /* Gun Magazine (Klobb) */
  PROP_spectremag,      /* Gun Magazine (Phantom) */
  PROP_uzimag,          /* Gun Magazine (ZMG (9mm)) */
  PROP_silencer,        /* Silencer */
  PROP_chrextinguisher, /* Fire Extinguisher */
  PROP_boxcartridges,   /* Box of Shells (Shotgun Cartridges) */
  PROP_fnp90mag,        /* Gun Magazine (RC-P90) */
  PROP_goldenshells,    /* Box of Shells (Golden Gun Bullets) */
  PROP_magnumshells,    /* Box of Shells (Magnum Rounds) */
  PROP_wppkmag,         /* Gun Magazine (PP7) */
  PROP_tt33mag,         /* Gun Magazine (DD44 Dostovei) */
  PROP_sev_door,       /* Grey Containment Door w/ Caution Stripes and Window */
  PROP_sev_door3,      /* Grey Electronic Door w/ LEFT Arrow */
  PROP_sev_door3_wind, /* BETA Electronic Door w/ LEFT Arrow and Fake Window */
  PROP_sev_door4_wind, /* Grey Electronic Door w/ LEFT Arrow and Window */
  PROP_sev_trislide,   /* Glass Door w/ Stone Frame */
  PROP_sev_door_v1,    /* Grey Electronic Door w/ UP Arrow */
  PROP_steel_door1,    /* Silver Corrugated Door w/ Caution Stripes */
  PROP_steel_door2,    /* Rusty Door w/ Handle */
  PROP_steel_door3,    /* Double Cross Brace Door */
  PROP_silo_lift_door, /* Elevator Door */
  PROP_steel_door2b,   /* Rusty Door w/o Handle */
  PROP_door_roller1,   /* Blue Bay Door w/ Caution Stripes */
  PROP_door_roller2,   /* Blue Bay Door w/ Venting and Caution Stripes */
  PROP_door_roller3,   /* Blue Bay Door w/ Venting and Caution Stripes */
  PROP_door_roller4, /* Cargo Bay Door w/ UP Arrow and Transportation Stripes */
  PROP_door_st_arec1, /* Blue Corrugated Door w/ Transportation Stripes */
  PROP_door_st_arec2, /* Blue Reversed Corrugated Door w/ Transportation Stripes
                       */
  PROP_door_dest1,    /* Grey Frigate Door w/ Indents and Caution Stripes */
  PROP_door_dest2,    /* Grey Frigate Door w/ Indents, Caution Stripes and KEEP
                         CLEAR Label */
  PROP_gas_plant_sw_do1,    /* Grey Swinging Door w/ Blue Stripe */
  PROP_gas_plant_sw2_do1,   /* Grey Swinging Door, Darker */
  PROP_gas_plant_sw3_do1,   /* Grey Swinging Door, Lighter */
  PROP_gas_plant_sw4_do1,   /* Light Wooden Door (Looks Like Sand) */
  PROP_gas_plant_met1_do1,  /* Brown Electronic Door */
  PROP_gas_plant_wc_cub1,   /* Bathroom Stall Door */
  PROP_gasplant_clear_door, /* Laboratory Glass Door */
  PROP_train_door,          /* Dark Wooden Door */
  PROP_train_door2,         /* Dark Wooden Door w/ Window */
  PROP_train_door3,         /* Dark Wooden Door w/ Window + Shutter */
  PROP_door_eyelid,         /* Eyelid Door */
  PROP_door_iris,           /* Iris Door */
  PROP_sevdoorwood,         /* Cabin Door */
  PROP_sevdoorwind,         /* Weathered Swinging Door w/ Window */
  PROP_sevdoornowind,       /* Weathered Swinging Door */
  PROP_sevdoormetslide,     /* Brown Corrugated Electronic Door */
  PROP_cryptdoor1a,         /* Stone Door w/ Prints (Set A) */
  PROP_cryptdoor1b,         /* Sand Door w/ Damage (Set A) */
  PROP_cryptdoor2a,         /* Stone Door w/ Prints, Darker (Set B) */
  PROP_cryptdoor2b,         /* Sand Door w/ Damage, Darker (Set B) */
  PROP_cryptdoor3,          /* Egyptian Moving Wall */
  PROP_cryptdoor4,          /* Brown Sand Door (Temple) */
  PROP_vertdoor,            /* Blast Door (Control) */
  PROP_hatchdoor,           /* Train Floor Hatch */
  PROP_damgatedoor,         /* Security Gate (Dam) */
  PROP_damtundoor,          /* Tunnel Flood Door (Dam) */
  PROP_damchaindoor,        /* Mesh Gate */
  PROP_silotopdoor,         /* Launch Tube Ceiling Shutter (Silo) */
  PROP_doorprison1,         /* Cell Door */
  PROP_doorstatgate,        /* Park Gate */
  PROP_chrkalash,           /* KF7 Soviet */
  PROP_chrgrenadelaunch,    /* Grenade Launcher */
  PROP_chrknife,            /* Hunting Knife */
  PROP_chrlaser,            /* Moonraker Laser */
  PROP_chrm16,              /* AR33 Assault Rifle */
  PROP_chrmp5k,             /* D5K Deutsche */
  PROP_chrruger,            /* Cougar Magnum */
  PROP_chrwppk,             /* PP7 Special Issue */
  PROP_chrshotgun,          /* Shotgun */
  PROP_chrskorpion,         /* Klobb */
  PROP_chrspectre,          /* Phantom */
  PROP_chruzi,              /* ZMG (9mm) */
  PROP_chrgrenade,          /* Hand Grenade */
  PROP_chrfnp90,            /* RC-P90 */
  PROP_chrbriefcase,        /* Briefcase */
  PROP_chrremotemine,       /* Remote Mine */
  PROP_chrproximitymine,    /* Proximity Mine */
  PROP_chrtimedmine,        /* Timed Mine */
  PROP_chrrocket,           /* Rocket */
  PROP_chrgrenaderound,     /* Grenade Round */
  PROP_chrwppksil,          /* PP7 (Silenced) */
  PROP_chrtt33,             /* DD44 Dostovei */
  PROP_chrmp5ksil,          /* D5K (Silenced) */
  PROP_chrautoshot,         /* Automatic Shotgun */
  PROP_chrgolden,           /* Golden Gun */
  PROP_chrthrowknife,       /* Throwing Knife */
  PROP_chrsniperrifle,      /* Sniper Rifle */
  PROP_chrrocketlaunch,     /* Rocket Launcher */
  PROP_hatfurry,            /* Fur Hat, Blue */
  PROP_hatfurrybrown,       /* Fur Hat, Brown */
  PROP_hatfurryblack,       /* Fur Hat, Black */
  PROP_hattbird,            /* Side Cap, Light Green */
  PROP_hattbirdbrown,       /* Side Cap, Dark Green */
  PROP_hathelmet,           /* Combat Helmet, Green */
  PROP_hathelmetgrey,       /* Combat Helmet, Grey */
  PROP_hatmoon,             /* Elite Headgear */
  PROP_hatberet,            /* Special Forces Beret, Black */
  PROP_hatberetblue,        /* Special Forces Beret, Navy */
  PROP_hatberetred,         /* Special Forces Beret, Burgundy */
  PROP_hatpeaked,           /* Officer's Peaked Visor Cap */
  PROP_chrwristdart,        /* Pchrwristdart (BETA) */
  PROP_chrexplosivepen,     /* Pchrexplosivepen (BETA) */
  PROP_chrbombcase,         /* Bomb Case (Briefcase Laying Down) */
  PROP_chrflarepistol,      /* Pchrflarepistol (BETA Pickup) */
  PROP_chrpitongun,         /* Pchrpitongun (BETA Pickup) */
  PROP_chrfingergun,        /* Pchrfingergun (BETA Pickup) */
  PROP_chrsilverwppk,       /* Pchrsilverwppk (BETA Pickup) */
  PROP_chrgoldwppk,         /* Pchrgoldwppk (BETA Pickup) */
  PROP_chrdynamite,         /* Pchrdynamite (BETA Pickup) */
  PROP_chrbungee,           /* Pchrbungee (BETA Pickup) */
  PROP_chrdoordecoder,      /* Door Decoder */
  PROP_chrbombdefuser,      /* Bomb Defuser */
  PROP_chrbugdetector,      /* Pchrbugdetector (BETA Pickup) */
  PROP_chrsafecrackercase,  /* Safe Cracker Case (Briefcase Laying Down) */
  PROP_chrcamera,           /* Photo Camera (007) */
  PROP_chrlockexploder,     /* Pchrlockexploder (BETA Pickup) */
  PROP_chrdoorexploder,     /* Pchrdoorexploder (BETA Pickup) */
  PROP_chrkeyanalysercase,  /* Key Analyzer Case (Briefcase Laying Down) */
  PROP_chrweaponcase,       /* Weapon Case (Briefcase Standing Up) */
  PROP_chrkeyyale,          /* Yale Key */
  PROP_chrkeybolt,          /* Bolt Key */
  PROP_chrbug,              /* Covert Modem / Tracker Bug */
  PROP_chrmicrocamera,      /* Micro Camera */
  PROP_floppy,              /* Floppy Disc */
  PROP_chrgoldeneyekey,     /* GoldenEye Key */
  PROP_chrpolarizedglasses, /* Polarized Glasses */
  PROP_chrcreditcard,       /* Pchrcreditcard (BETA Pickup) */
  PROP_chrdarkglasses,      /* Pchrdarkglasses (BETA Pickup) */
  PROP_chrgaskeyring,       /* Gas Keyring */
  PROP_chrdatathief,        /* Datathief */
  PROP_safe,                /* Safe Body */
  PROP_bomb,                /* Pbomb (BETA Pickup) */
  PROP_chrplans,            /* Plans (Briefing Folder) */
  PROP_chrspyfile,          /* Pchrspyfile (BETA Pickup) */
  PROP_chrblueprints,       /* Pirate Blueprints */
  PROP_chrcircuitboard,     /* Circuitboard */
  PROP_chrmap,              /* Bunker Expansion Plans */
  PROP_chrspooltape,        /* Pchrspooltape (BETA Pickup) */
  PROP_chraudiotape,        /* Audiotape */
  PROP_chrmicrofilm,        /* Pchrmicrofilm (BETA Pickup) */
  PROP_chrmicrocode,        /* Pchrmicrocode (BETA Pickup) */
  PROP_chrlectre,           /* Pchrlectre (BETA Pickup) */
  PROP_chrmoney,            /* Pchrmoney (BETA Pickup) */
  PROP_chrgoldbar,          /* Pchrgoldbar (BETA Pickup) */
  PROP_chrheroin,           /* Pchrheroin (BETA Pickup) */
  PROP_chrclipboard,        /* Clipboard */
  PROP_chrdossierred,       /* Red Dossier */
  PROP_chrstafflist,        /* Staff List */
  PROP_chrdattape,          /* DAT */
  PROP_chrplastique,        /* Plastique */
  PROP_chrblackbox,         /* Black Box (Orange Flight Recorder) */
  PROP_chrvideotape,        /* CCTV Tape (GoldenEye VHS) */
  PROP_nintendologo,        /* Nintendo Logo */
  PROP_goldeneyelogo,       /* GoldenEye Logo */
  PROP_walletbond,        /* Classified Folder w/ Royal Crest (Folder Menus) */
  PROP_miltruck,          /* Supply Truck */
  PROP_jeep,              /* Military Jeep */
  PROP_artic,             /* Red Prime Mover */
  PROP_helicopter,        /* Transport Helicopter w/ Natalya */
  PROP_tiger,             /* Pirate Euro Chopper */
  PROP_milcopter,         /* Hound Helicopter */
  PROP_hind,              /* Soviet Camouflage Chopper */
  PROP_artictrailer,      /* Black Trailer */
  PROP_motorbike,         /* Motorbike */
  PROP_tank,              /* Tank */
  PROP_apc,               /* Armored Personnel Carrier */
  PROP_speedboat,         /* Speedboat */
  PROP_plane,             /* Aeroplane */
  PROP_gun_runway1,       /* Heavy Gun Emplacement */
  PROP_safedoor,          /* Safe Door */
  PROP_key_holder,        /* Key Rack */
  PROP_hatchsevx,         /* Grating (Ventshaft Hatch) */
  PROP_sevdish,           /* Satellite Dish (Severnaya) */
  PROP_archsecdoor1,      /* Archives Moving Wall (Dark) */
  PROP_archsecdoor2,      /* Archives Moving Wall (Light) */
  PROP_groundgun,         /* Free Standing Drone Gun */
  PROP_trainextdoor,      /* Train Exterior Door */
  PROP_carbmw,            /* White Car #1 (BMW) */
  PROP_carescort,         /* White Car #2 (Escort) */
  PROP_cargolf,           /* White Car #3 (Golf) */
  PROP_carweird,          /* Red Car (Cadillac) */
  PROP_carzil,            /* Ourumov's Car (ZIL) */
  PROP_shuttle_door_l,    /* Exhaust Bay Doors, Left Side */
  PROP_shuttle_door_r,    /* Exhaust Bay Doors, Right Side */
  PROP_depot_gate_entry,  /* Metallic Gate w/ Red Star */
  PROP_depot_door_steel,  /* Rusty Door w/ Handle (Lo-Res) */
  PROP_glassware2,        /* Beaker w/ Blue Topper */
  PROP_glassware3,        /* Erlenmeyer Flask */
  PROP_glassware4,        /* Set of Five Beakers */
  PROP_landmine,          /* Land Mine */
  PROP_plant1,            /* Jungle Plant, Withered and Dying */
  PROP_plant11,           /* Jungle Plant, Turning Colour */
  PROP_plant2,            /* Jungle Plant, Healthy and Thick */
  PROP_plant3,            /* Jungle Plant, Tall Leaves */
  PROP_jungle5_tree,      /* Jungle Tree, Moss Covered */
  PROP_legalpage,         /* GoldenEye Certification Screen */
  PROP_st_pete_room_1i,   /* Roads and Buildings #1 (stretch of road) */
  PROP_st_pete_room_2i,   /* Roads and Buildings #2 (stretch of road) */
  PROP_st_pete_room_3t,   /* Roads and Buildings #3 (intersection) */
  PROP_st_pete_room_5c,   /* Roads and Buildings #4 (street corner) */
  PROP_st_pete_room_6c,   /* Roads and Buildings #5 (street corner) */
  PROP_door_rollertrain,  /* Roller Door */
  PROP_door_win,          /* Glass Sliding Door (Aztec) */
  PROP_door_aztec,        /* Stone Sliding Door (Aztec) */
  PROP_shuttle,           /* Moonraker Shuttle */
  PROP_door_azt_desk,     /* Boardroom Table (Aztec Exhaust Bay) */
  PROP_door_azt_desk_top, /* Boardroom Table Extension (Aztec Exhaust Bay) */
  PROP_door_azt_chair,    /* Boardroom Chair (Aztec Exhaust Bay) */
  PROP_door_mf,           /* Mainframe Door */
  PROP_flag,              /* Flag Tag Token */
  PROP_barricade,         /* Road Barricade */
  PROP_modembox,          /* Covert Modem Connection Screen */
  PROP_doorpanel,         /* Sliding Door Activation Switch */
  PROP_doorconsole,       /* Console w/ Activation Light */
  PROP_chrtesttube,       /* Glass Test Tube */
  PROP_bollard            /* Bollard */
} PROPS;

typedef enum PROJECTILES {
  PROJECTILES_MAX = 0x2E,
  PROJECTILES_TYPE_KNIFE = PROP_chrknife,
  PROJECTILES_TYPE_GRENADE = PROP_chrgrenade,
  PROJECTILES_TYPE_REMOTE_MINE = PROP_chrremotemine,
  PROJECTILES_TYPE_PROX_MINE = PROP_chrproximitymine,
  PROJECTILES_TYPE_TIMED_MINE = PROP_chrtimedmine,
  PROJECTILES_TYPE_ROCKET_ROUND = PROP_chrrocket,
  PROJECTILES_TYPE_ROCKET_ROUND2 = PROP_chrrocket,
  PROJECTILES_TYPE_GLAUNCH_ROUND = PROP_chrgrenaderound,
  PROJECTILES_TYPE_BOMBCASE = PROP_chrbombcase,
  PROJECTILES_TYPE_BUG = PROP_chrbug,
  PROJECTILES_TYPE_MICROCAMERA = PROP_chrmicrocamera,
  PROJECTILES_TYPE_GE_KEY = PROP_chrgoldeneyekey,
  PROJECTILES_TYPE_PLASTIQUE = PROP_chrplastique
} PROJECTILES;

typedef enum AMMOTYPES {
  AMMO_9MM = 1,
  AMMO_9MM_2,
  AMMO_RIFLE,
  AMMO_SHOTGUN,
  AMMO_GRENADE,
  AMMO_ROCKETS,
  AMMO_REMOTEMINE,
  AMMO_PROXMINE,
  AMMO_TIMEDMINE,
  AMMO_KNIFE,
  AMMO_GRENADEROUND,
  AMMO_MAGNUM,
  AMMO_GGUN,
  AMMO_DARTS,
  AMMO_EXPLOSIVEPEN,
  AMMO_BOMBCASE,
  AMMO_FLARE,
  AMMO_PITON,
  AMMO_DYNAMITE,
  AMMO_BUG,
  AMMO_MICRO_CAMERA,
  AMMO_GEKEY,
  AMMO_PLASTIQUE,
  AMMO_WATCH_LASER,
  AMMO_WATCH_MAGNET,
  AMMO_UNK,
  AMMO_CAMERA,
  AMMO_TANK,
  AMMO_TOKEN
} AMMOTYPES;

typedef enum DOORSTATE { OPEN = 0x1, CLOSED } DOORSTATE;

typedef enum SCREEN_SIZE {
  SCREEN_SIZE_320x240,
  SCREEN_SIZE_440x330
} SCREEN_SIZE;

typedef enum CAMERAMODE {
  INTRO_CAM = 1,
  FADESWIRL_CAM,
  SWIRL_CAM,
  FP_CAM,
  UNK5_CAM,
  UNK6_CAM,
  POSEND_CAM,
  FP_NOINPUT_CAM,
  MP_CAM,
  UNK10_CAM
} CAMERAMODE;

typedef enum IMAGE_FORMAT { F_RGBA, F_YUV, F_CI, F_IA, F_I } IMAGE_FORMAT;

typedef enum IMAGE_BITDEPTH { D_4BIT, D_8BIT, D_16BIT, D_32BIT } IMAGE_BITDEPTH;

typedef enum CM_FLAGS { CLAMP = 1, MIRROR } CM_FLAGS;

/* motion capture actor: duncan botwood */
/* motion capture assistance: b jones */
/* recorded using 'flock of birds' system by ascension technology corporation,
 * in a freezing metal barn in the depths of winter */
/* note: animations are double handed weapon (KF7) unless specified (unarmed,
 * one_handed_weapon, dual_wield) */
typedef enum ANIMATIONS {
  ANIM_idle,
  ANIM_fire_standing,
  ANIM_fire_standing_fast,
  ANIM_fire_hip,
  ANIM_fire_shoulder_left,
  ANIM_fire_turn_right1,
  ANIM_fire_turn_right2,
  ANIM_fire_kneel_right_leg,
  ANIM_fire_kneel_left_leg,
  ANIM_fire_kneel_left,
  ANIM_fire_kneel_right,
  ANIM_fire_roll_left,
  ANIM_fire_roll_right1,
  ANIM_fire_roll_left_fast,
  ANIM_hit_left_shoulder,
  ANIM_hit_right_shoulder,
  ANIM_hit_left_arm,
  ANIM_hit_right_arm,
  ANIM_hit_left_hand,
  ANIM_hit_right_hand,
  ANIM_hit_left_leg,
  ANIM_hit_right_leg,
  ANIM_death_genitalia, /* thank you mr. botwood, here is your award */
  ANIM_hit_neck,
  ANIM_death_neck,
  ANIM_death_stagger_back_to_wall,
  ANIM_death_forward_face_down,
  ANIM_death_forward_spin_face_up,
  ANIM_death_backward_fall_face_up1,
  ANIM_death_backward_spin_face_down_right,
  ANIM_death_backward_spin_face_up_right,
  ANIM_death_backward_spin_face_down_left,
  ANIM_death_backward_spin_face_up_left,
  ANIM_death_forward_face_down_hard,
  ANIM_death_forward_face_down_soft,
  ANIM_death_fetal_position_right,
  ANIM_death_fetal_position_left,
  ANIM_death_backward_fall_face_up2,
  ANIM_side_step_left,
  ANIM_fire_roll_right2,
  ANIM_walking,
  ANIM_sprinting,
  ANIM_running,
  ANIM_bond_eye_walk,
  ANIM_bond_eye_fire,
  ANIM_bond_watch,
  ANIM_surrendering_armed,
  ANIM_surrendering_armed_drop_weapon,
  ANIM_fire_walking,
  ANIM_fire_running,
  ANIM_null50, /* invalid slot */
  ANIM_null51, /* invalid slot */
  ANIM_fire_jump_to_side_left,
  ANIM_fire_jump_to_side_right,
  ANIM_hit_butt_long,
  ANIM_hit_butt_short,
  ANIM_death_head,
  ANIM_death_left_leg,
  ANIM_slide_right,
  ANIM_slide_left,
  ANIM_jump_backwards,
  ANIM_extending_left_hand,
  ANIM_fire_throw_grenade,
  ANIM_spotting_bond, /* used by chr ai command guard_points_at_bond */
  ANIM_look_around, /* used by chr ai command guard_animation_looks_around_self
                     */
  ANIM_fire_standing_one_handed_weapon,
  ANIM_fire_standing_draw_one_handed_weapon_fast,
  ANIM_fire_standing_draw_one_handed_weapon_slow,
  ANIM_fire_hip_one_handed_weapon_fast,
  ANIM_fire_hip_one_handed_weapon_slow,
  ANIM_fire_hip_forward_one_handed_weapon,
  ANIM_fire_standing_right_one_handed_weapon,
  ANIM_fire_step_right_one_handed_weapon,
  ANIM_fire_standing_left_one_handed_weapon_slow,
  ANIM_fire_standing_left_one_handed_weapon_fast,
  ANIM_fire_kneel_forward_one_handed_weapon_slow,
  ANIM_fire_kneel_forward_one_handed_weapon_fast,
  ANIM_fire_kneel_right_one_handed_weapon_slow,
  ANIM_fire_kneel_right_one_handed_weapon_fast,
  ANIM_fire_kneel_left_one_handed_weapon_slow,
  ANIM_fire_kneel_left_one_handed_weapon_fast,
  ANIM_fire_kneel_left_one_handed_weapon,
  ANIM_aim_walking_one_handed_weapon,
  ANIM_aim_walking_left_one_handed_weapon,
  ANIM_aim_walking_right_one_handed_weapon,
  ANIM_aim_running_one_handed_weapon,
  ANIM_aim_running_right_one_handed_weapon,
  ANIM_aim_running_left_one_handed_weapon,
  ANIM_aim_sprinting_one_handed_weapon,
  ANIM_running_one_handed_weapon,
  ANIM_sprinting_one_handed_weapon,
  ANIM_null91, /* invalid slot */
  ANIM_null92, /* invalid slot */
  ANIM_null93, /* invalid slot */
  ANIM_null94, /* invalid slot */
  ANIM_null95, /* invalid slot */
  ANIM_null96, /* invalid slot */
  ANIM_draw_one_handed_weapon_and_look_around,
  ANIM_draw_one_handed_weapon_and_stand_up,
  ANIM_aim_one_handed_weapon_left_right,
  ANIM_cock_one_handed_weapon_and_turn_around,
  ANIM_holster_one_handed_weapon_and_cross_arms,
  ANIM_cock_one_handed_weapon_turn_around_and_stand_up,
  ANIM_draw_one_handed_weapon_and_turn_around,
  ANIM_step_forward_and_hold_one_handed_weapon,
  ANIM_holster_one_handed_weapon_and_adjust_suit,
  ANIM_idle_unarmed,
  ANIM_walking_unarmed,
  ANIM_fire_walking_dual_wield,
  ANIM_fire_walking_dual_wield_hands_crossed,
  ANIM_fire_running_dual_wield,
  ANIM_fire_running_dual_wield_hands_crossed,
  ANIM_fire_sprinting_dual_wield,
  ANIM_fire_sprinting_dual_wield_hands_crossed,
  ANIM_walking_female,
  ANIM_running_female,
  ANIM_fire_kneel_dual_wield,
  ANIM_fire_kneel_dual_wield_left,
  ANIM_fire_kneel_dual_wield_right,
  ANIM_fire_kneel_dual_wield_hands_crossed,
  ANIM_fire_kneel_dual_wield_hands_crossed_left,
  ANIM_fire_kneel_dual_wield_hands_crossed_right,
  ANIM_fire_standing_dual_wield,
  ANIM_fire_standing_dual_wield_left,
  ANIM_fire_standing_dual_wield_right,
  ANIM_fire_standing_dual_wield_hands_crossed_left,
  ANIM_fire_standing_dual_wield_hands_crossed_right,
  ANIM_fire_standing_aiming_down_sights,
  ANIM_fire_kneel_aiming_down_sights,
  ANIM_hit_taser, /* unused tazer boy hit reaction */
  ANIM_death_explosion_forward,
  ANIM_death_explosion_left1,
  ANIM_death_explosion_back_left,
  ANIM_death_explosion_back1,
  ANIM_death_explosion_right,
  ANIM_death_explosion_forward_right1,
  ANIM_death_explosion_back2,
  ANIM_death_explosion_forward_roll,
  ANIM_death_explosion_forward_face_down,
  ANIM_death_explosion_left2,
  ANIM_death_explosion_forward_right2,
  ANIM_death_explosion_forward_right2_alt, /* copy of right2 with different fall
                                            */
  ANIM_death_explosion_forward_right3,
  ANIM_null143, /* invalid slot */
  ANIM_null144, /* invalid slot */
  ANIM_null145, /* invalid slot */
  ANIM_null146, /* invalid slot */
  ANIM_running_hands_up,
  ANIM_sprinting_hands_up,
  ANIM_aim_and_blow_one_handed_weapon, /* reversed animation? */
  ANIM_aim_one_handed_weapon_left,
  ANIM_aim_one_handed_weapon_right,
  ANIM_conversation,
  ANIM_drop_weapon_and_show_fight_stance, /* orthodox stance woo */
  ANIM_yawning,
  ANIM_swatting_flies,
  ANIM_scratching_leg,
  ANIM_scratching_butt,
  ANIM_adjusting_crotch,
  ANIM_sneeze,
  ANIM_conversation_cleaned, /* cleaned up copy of ANIM_conversation (compare
                                left wrist) */
  ANIM_conversation_listener,
  ANIM_startled_and_looking_around,
  ANIM_laughing_in_disbelief,
  ANIM_surrendering_unarmed,
  ANIM_coughing_standing,
  ANIM_coughing_kneel1,
  ANIM_coughing_kneel2,
  ANIM_standing_up,
  ANIM_null169, /* invalid slot */
  ANIM_dancing,
  ANIM_dancing_one_handed_weapon,
  ANIM_keyboard_right_hand1,
  ANIM_keyboard_right_hand2,
  ANIM_keyboard_left_hand,
  ANIM_keyboard_right_hand_tapping,
  ANIM_bond_eye_fire_alt, /* unused */
  ANIM_dam_jump,
  ANIM_surface_vent_jump,
  ANIM_cradle_jump,
  ANIM_cradle_fall,
  ANIM_credits_bond_kissing,
  ANIM_credits_natalya_kissing
} ANIMATIONS;

typedef enum AIRCRAFT_ANIMATIONS {
  ANIM_helicopter_cradle,
  ANIM_plane_runway,
  ANIM_helicopter_takeoff
} AIRCRAFT_ANIMATIONS;

typedef enum HANDEDNESS { RIGHT_HAND, LEFT_HAND } HANDEDNESS;

// used by characters
typedef enum ACT_TYPE {
  ACT_INIT,
  ACT_STAND,
  ACT_KNEEL,
  ACT_ANIM,
  ACT_DIE,
  ACT_DEAD,
  ACT_ARGH,
  ACT_PREARGH,
  ACT_ATTACK,
  ACT_ATTACKWALK,
  ACT_ATTACKROLL,
  ACT_SIDESTEP,
  ACT_JUMPOUT,
  ACT_RUNPOS,
  ACT_PATROL,
  ACT_GOPOS,
  ACT_SURRENDER,
  ACT_LOOKATTARGET,
  ACT_SURPRISED,
  ACT_STARTALARM,
  ACT_THROWGRENADE,
  ACT_TURNDIR,
  ACT_TEST,
  ACT_NULL
} ACT_TYPE;

#define CHRFLAG_INVINCIBLE 0x00000010         // invincible
#define CHRFLAG_00000200 0x00000200    // unknown

#endif
