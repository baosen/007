#include "obseg.h"

struct resource_lookup_data_entry {
  unsigned int rom_size, pc_remaining, pc_size, rom_remaining;
  unsigned char loaded_bank, unk_11;
  unsigned short reserved;
};

struct fileentry {
  int index;
  char *filename;
  unsigned char *hw_address;
};

void sub_GAME_7F0BD234(void);
unsigned char *load_resource_index_to_buffer(int index, int param_2,
                                             unsigned char *ptrdata, int bytes);
unsigned char *load_rom_resource_index_to_membank(int index, int type, int size,
                                                  unsigned char bank);
void resource_load_from_indy(unsigned char *ptrdata, int bytes,
                             struct fileentry *srcfile,
                             struct resource_lookup_data_entry *lookupdata);

struct resource_lookup_data_entry resource_lookup_data_array[736];

int ob_c_debug_notice_list_entry = 0;

struct fileentry file_resource_table[] = {
    {0, "", 0},
    {1, "bg/bg_sev_all_p.seg", &bg_sev_all_p_seg},
    {2, "bg/bg_silo_all_p.seg", &bg_silo_all_p_seg},
    {3, "bg/bg_stat_all_p.seg", &bg_stat_all_p_seg},
    {4, "bg/bg_arec_all_p.seg", &bg_arec_all_p_seg},
    {5, "bg/bg_arch_all_p.seg", &bg_arch_all_p_seg},
    {6, "bg/bg_tra_all_p.seg", &bg_tra_all_p_seg},
    {7, "bg/bg_dest_all_p.seg", &bg_dest_all_p_seg},
    {8, "bg/bg_sevb_all_p.seg", &bg_sevb_all_p_seg},
    {9, "bg/bg_azt_all_p.seg", &bg_azt_all_p_seg},
    {0xA, "bg/bg_pete_all_p.seg", &bg_pete_all_p_seg},
    {0xB, "bg/bg_depo_all_p.seg", &bg_depo_all_p_seg},
    {0xC, "bg/bg_ref_all_p.seg", &bg_ref_all_p_seg},
    {0xD, "bg/bg_cryp_all_p.seg", &bg_cryp_all_p_seg},
    {0xE, "bg/bg_dam_all_p.seg", &bg_dam_all_p_seg},
    {0xF, "bg/bg_ark_all_p.seg", &bg_ark_all_p_seg},
    {0x10, "bg/bg_run_all_p.seg", &bg_run_all_p_seg},
    {0x11, "bg/bg_sevx_all_p.seg", &bg_sevx_all_p_seg},
    {0x12, "bg/bg_jun_all_p.seg", &bg_jun_all_p_seg},
    {0x13, "bg/bg_dish_all_p.seg", &bg_dish_all_p_seg},
    {0x14, "bg/bg_cave_all_p.seg", &bg_cave_all_p_seg},
    {0x15, "bg/bg_cat_all_p.seg", &bg_cat_all_p_seg},
    {0x16, "bg/bg_crad_all_p.seg", &bg_crad_all_p_seg},
    {0x17, "bg/bg_sho_all_p.seg", &bg_sho_all_p_seg},
    {0x18, "bg/bg_eld_all_p.seg", &bg_imp_all_p_seg},
    {0x19, "bg/bg_imp_all_p.seg", &bg_imp_all_p_seg},
    {0x1A, "bg/bg_ash_all_p.seg", &bg_imp_all_p_seg},
    {0x1B, "bg/bg_lue_all_p.seg", &bg_imp_all_p_seg},
    {0x1C, "bg/bg_ame_all_p.seg", &bg_imp_all_p_seg},
    {0x1D, "bg/bg_rit_all_p.seg", &bg_rit_all_p_seg},
    {0x1E, "bg/bg_oat_all_p.seg", &bg_oat_all_p_seg},
    {0x1F, "bg/bg_ear_all_p.seg", &bg_ear_all_p_seg},
    {0x20, "bg/bg_lee_all_p.seg", &bg_lee_all_p_seg},
    {0x21, "bg/bg_lip_all_p.seg", &bg_lip_all_p_seg},
    {0x22, "bg/bg_len_all_p.seg", &bg_len_all_p_seg},
    {0x23, "bg/bg_wax_all_p.seg", &bg_wax_all_p_seg},
    {0x24, "bg/bg_pam_all_p.seg", &bg_pam_all_p_seg},

    {0x25, "CarmourguardZ", &CarmourguardZ},
    {0x26, "CbaronsamediZ", &CbaronsamediZ},
    {0x27, "CbluecamguardZ", &CbluecamguardZ},
    {0x28, "CbluemanZ", &CbluemanZ},
    {0x29, "CbluewomanZ", &CbluewomanZ},
    {0x2A, "CboilerbondZ", &CboilerbondZ},
    {0x2B, "CboilertrevZ", &CboilertrevZ},
    {0x2C, "CborisZ", &CborisZ},
    {0x2D, "CcamguardZ", &CcamguardZ},
    {0x2E, "CcardimanZ", &CcardimanZ},
    {0x2F, "CcheckmanZ", &CcheckmanZ},
    {0x30, "CcommguardZ", &CcommguardZ},
    {0x31, "CdjbondZ", &CdjbondZ},
    {0x32, "CfattechwomanZ", &CfattechwomanZ},
    {0x33, "Cgreatguard2Z", &Cgreatguard2Z},
    {0x34, "CgreatguardZ", &CgreatguardZ},
    {0x35, "CgreyguardZ", &CgreyguardZ},
    {0x36, "CgreymanZ", &CgreymanZ},
    {0x37, "CheadalanZ", &CheadalanZ},
    {0x38, "CheadbZ", &CheadbZ},
    {0x39, "CheadbalaclavaZ", &CheadbalaclavaZ},
    {0x3A, "CheadbikeZ", &CheadbikeZ},
    {0x3B, "CheadbrosnanZ", &CheadbrosnanZ},
    {0x3C, "CheadbrosnanboilerZ", &CheadbrosnanboilerZ},
    {0x3D, "CheadbrosnansnowZ", &CheadbrosnansnowZ},
    {0x3E, "CheadbrosnansuitZ", &CheadbrosnansuitZ},
    {0x3F, "CheadbrosnantimberZ", &CheadbrosnantimberZ},
    {0x40, "CheadchrisZ", &CheadchrisZ},
    {0x41, "CheaddaveZ", &CheaddaveZ},
    {0x42, "CheaddesZ", &CheaddesZ},
    {0x43, "CheadduncanZ", &CheadduncanZ},
    {0x44, "CheaddwayneZ", &CheaddwayneZ},
    {0x45, "CheadgrahamZ", &CheadgrahamZ},
    {0x46, "CheadgrantZ", &CheadgrantZ},
    {0x47, "CheadjimZ", &CheadjimZ},
    {0x48, "Cheadjoe2Z", &Cheadjoe2Z},
    {0x49, "CheadjoeZ", &CheadjoeZ},
    {0x4A, "CheadjoelZ", &CheadjoelZ},
    {0x4B, "CheadkarlZ", &CheadkarlZ},
    {0x4C, "CheadkenZ", &CheadkenZ},
    {0x4D, "CheadleeZ", &CheadleeZ},
    {0x4E, "CheadmandyZ", &CheadmandyZ},
    {0x4F, "CheadmarionZ", &CheadmarionZ},
    {0x50, "CheadmarkZ", &CheadmarkZ},
    {0x51, "CheadmartinZ", &CheadmartinZ},
    {0x52, "CheadmishkinZ", &CheadmishkinZ},
    {0x53, "CheadneilZ", &CheadneilZ},
    {0x54, "CheadpeteZ", &CheadpeteZ},
    {0x55, "CheadrobinZ", &CheadrobinZ},
    {0x56, "CheadsallyZ", &CheadsallyZ},
    {0x57, "CheadscottZ", &CheadscottZ},
    {0x58, "CheadshaunZ", &CheadshaunZ},
    {0x59, "CheadsteveeZ", &CheadsteveeZ},
    {0x5A, "CheadstevehZ", &CheadstevehZ},
    {0x5B, "CheadvivienZ", &CheadvivienZ},
    {0x5C, "CjawsZ", &CjawsZ},
    {0x5D, "CjeanwomanZ", &CjeanwomanZ},
    {0x5E, "CmaydayZ", &CmaydayZ},
    {0x5F, "CmoonfemaleZ", &CmoonfemaleZ},
    {0x60, "CmoonguardZ", &CmoonguardZ},
    {0x61, "CnatalyaZ", &CnatalyaZ},
    {0x62, "CnavyguardZ", &CnavyguardZ},
    {0x63, "CoddjobZ", &CoddjobZ},
    {0x64, "ColiveguardZ", &ColiveguardZ},
    {0x65, "CorumovZ", &CorumovZ},
    {0x66, "CpilotZ", &CpilotZ},
    {0x67, "CredmanZ", &CredmanZ},
    {0x68, "CrusguardZ", &CrusguardZ},
    {0x69, "CsnowbondZ", &CsnowbondZ},
    {0x6A, "CsnowguardZ", &CsnowguardZ},
    {0x6B, "CspicebondZ", &CspicebondZ},
    {0x6C, "Csuit_lf_handZ", &Csuit_lf_handZ},
    {0x6D, "CsuitbondZ", &CsuitbondZ},
    {0x6E, "CtechmanZ", &CtechmanZ},
    {0x6F, "CtechwomanZ", &CtechwomanZ},
    {0x70, "CtimberbondZ", &CtimberbondZ},
    {0x71, "CtrevelyanZ", &CtrevelyanZ},
    {0x72, "CtrevguardZ", &CtrevguardZ},
    {0x73, "CvalentinZ", &CvalentinZ},
    {0x74, "CxeniaZ", &CxeniaZ},

    {0x75, "Gak47Z", &Gak47Z},
    {0x76, "GaudiotapeZ", &GaudiotapeZ},
    {0x77, "GautoshotZ", &GautoshotZ},
    {0x78, "GblackboxZ", &GblackboxZ},
    {0x79, "GblueprintsZ", &GblueprintsZ},
    {0x7A, "GbombcaseZ", &GbombcaseZ},
    {0x7B, "GbombdefuserZ", &GbombdefuserZ},
    {0x7C, "GbriefcaseZ", &GbriefcaseZ},
    {0x7D, "GbugZ", &GbugZ},
    {0x7E, "GbugdetectorZ", &GbugdetectorZ},
    {0x7F, "GbungeeZ", &GbungeeZ},
    {0x80, "GcameraZ", &GcameraZ},
    {0x81, "GcartblueZ", &GcartblueZ},
    {0x82, "GcartridgeZ", &GcartridgeZ},
    {0x83, "GcartrifleZ", &GcartrifleZ},
    {0x84, "GcartshellZ", &GcartshellZ},
    {0x85, "GcircuitboardZ", &GcircuitboardZ},
    {0x86, "GclipboardZ", &GclipboardZ},
    {0x87, "GcreditcardZ", &GcreditcardZ},
    {0x88, "GdarkglassesZ", &GdarkglassesZ},
    {0x89, "GdatathiefZ", &GdatathiefZ},
    {0x8A, "GdattapeZ", &GdattapeZ},
    {0x8B, "GdoordecoderZ", &GdoordecoderZ},
    {0x8C, "GdoorexploderZ", &GdoorexploderZ},
    {0x8D, "GdossierredZ", &GdossierredZ},
    {0x8E, "GdynamiteZ", &GdynamiteZ},
    {0x8F, "GexplosivefloppyZ", &GexplosivefloppyZ},
    {0x90, "GexplosivepenZ", &GexplosivepenZ},
    {0x91, "GextinguisherZ", &GextinguisherZ},
    {0x92, "GfingergunZ", &GfingergunZ},
    {0x93, "GfistZ", &GfistZ},
    {0x94, "GflarepistolZ", &GflarepistolZ},
    {0x95, "Gfnp90Z", &Gfnp90Z},
    {0x96, "GgaskeyringZ", &GgaskeyringZ},
    {0x97, "GgoldbarZ", &GgoldbarZ},
    {0x98, "GgoldeneyekeyZ", &GgoldeneyekeyZ},
    {0x99, "GgoldengunZ", &GgoldengunZ},
    {0x9A, "GgoldwppkZ", &GgoldwppkZ},
    {0x9B, "GgrenadeZ", &GgrenadeZ},
    {0x9C, "GgrenadelaunchZ", &GgrenadelaunchZ},
    {0x9D, "GheroinZ", &GheroinZ},
    {0x9E, "GjoypadZ", &GjoypadZ},
    {0x9F, "GkeyanalysercaseZ", &GkeyanalysercaseZ},
    {0xA0, "GkeyboltZ", &GkeyboltZ},
    {0xA1, "GkeycardZ", &GkeycardZ},
    {0xA2, "GkeyyaleZ", &GkeyyaleZ},
    {0xA3, "GknifeZ", &GknifeZ},
    {0xA4, "GlaserZ", &GlaserZ},
    {0xA5, "GlectreZ", &GlectreZ},
    {0xA6, "GlockexploderZ", &GlockexploderZ},
    {0xA7, "Gm16Z", &Gm16Z},
    {0xA8, "GmapZ", &GmapZ},
    {0xA9, "GmicrocameraZ", &GmicrocameraZ},
    {0xAA, "GmicrocodeZ", &GmicrocodeZ},
    {0xAB, "GmicrofilmZ", &GmicrofilmZ},
    {0xAC, "GmoneyZ", &GmoneyZ},
    {0xAD, "Gmp5kZ", &Gmp5kZ},
    {0xAE, "Gmp5ksilZ", &Gmp5ksilZ},
    {0xAF, "GpitongunZ", &GpitongunZ},
    {0xB0, "GplansZ", &GplansZ},
    {0xB1, "GplastiqueZ", &GplastiqueZ},
    {0xB2, "GpolarizedglassesZ", &GpolarizedglassesZ},
    {0xB3, "GproximitymineZ", &GproximitymineZ},
    {0xB4, "GremotemineZ", &GremotemineZ},
    {0xB5, "GrocketlaunchZ", &GrocketlaunchZ},
    {0xB6, "GrugerZ", &GrugerZ},
    {0xB7, "GsafecrackercaseZ", &GsafecrackercaseZ},
    {0xB8, "GshotgunZ", &GshotgunZ},
    {0xB9, "GsilverwppkZ", &GsilverwppkZ},
    {0xBA, "GskorpionZ", &GskorpionZ},
    {0xBB, "GsniperrifleZ", &GsniperrifleZ},
    {0xBC, "GspectreZ", &GspectreZ},
    {0xBD, "GspooltapeZ", &GspooltapeZ},
    {0xBE, "GspyfileZ", &GspyfileZ},
    {0xBF, "GstafflistZ", &GstafflistZ},
    {0xC0, "GtaserZ", &GtaserZ},
    {0xC1, "GthrowknifeZ", &GthrowknifeZ},
    {0xC2, "GtimedmineZ", &GtimedmineZ},
    {0xC3, "GtriggerZ", &GtriggerZ},
    {0xC4, "Gtt33Z", &Gtt33Z},
    {0xC5, "GuziZ", &GuziZ},
    {0xC6, "GvideotapeZ", &GvideotapeZ},
    {0xC7, "GwatchcommunicatorZ", &GwatchcommunicatorZ},
    {0xC8, "GwatchgeigercounterZ", &GwatchgeigercounterZ},
    {0xC9, "GwatchidentifierZ", &GwatchidentifierZ},
    {0xCA, "GwatchlaserZ", &GwatchlaserZ},
    {0xCB, "GwatchmagnetattractZ", &GwatchmagnetattractZ},
    {0xCC, "GwatchmagnetrepelZ", &GwatchmagnetrepelZ},
    {0xCD, "GweaponcaseZ", &GweaponcaseZ},
    {0xCE, "GwppkZ", &GwppkZ},
    {0xCF, "GwppksilZ", &GwppksilZ},
    {0xD0, "GwristdartZ", &GwristdartZ},

    {0xD1, "PICBMZ", &PICBMZ},
    {0xD2, "PICBM_noseZ", &PICBM_noseZ},
    {0xD3, "Pak47magZ", &Pak47magZ},
    {0xD4, "Palarm1Z", &Palarm1Z},
    {0xD5, "Palarm2Z", &Palarm2Z},
    {0xD6, "Pammo_crate1Z", &Pammo_crate1Z},
    {0xD7, "Pammo_crate2Z", &Pammo_crate2Z},
    {0xD8, "Pammo_crate3Z", &Pammo_crate3Z},
    {0xD9, "Pammo_crate4Z", &Pammo_crate4Z},
    {0xDA, "Pammo_crate5Z", &Pammo_crate5Z},
    {0xDB, "PapcZ", &PapcZ},
    {0xDC, "Parchsecdoor1Z", &Parchsecdoor1Z},
    {0xDD, "Parchsecdoor2Z", &Parchsecdoor2Z},
    {0xDE, "ParticZ", &ParticZ},
    {0xDF, "PartictrailerZ", &PartictrailerZ},
    {0xE0, "PbarricadeZ", &PbarricadeZ},
    {0xE1, "Pbin1Z", &Pbin1Z},
    {0xE2, "Pblotter1Z", &Pblotter1Z},
    {0xE3, "PbodyarmourZ", &PbodyarmourZ},
    {0xE4, "PbodyarmourvestZ", &PbodyarmourvestZ},
    {0xE5, "PbollardZ", &PbollardZ},
    {0xE6, "PbombZ", &PbombZ},
    {0xE7, "Pbook1Z", &Pbook1Z},
    {0xE8, "Pbookshelf1Z", &Pbookshelf1Z},
    {0xE9, "Pborg_crateZ", &Pborg_crateZ},
    {0xEA, "PboxcartridgesZ", &PboxcartridgesZ},
    {0xEB, "Pboxes2x4Z", &Pboxes2x4Z},
    {0xEC, "Pboxes3x4Z", &Pboxes3x4Z},
    {0xED, "Pboxes4x4Z", &Pboxes4x4Z},
    {0xEE, "PbrakeunitZ", &PbrakeunitZ},
    {0xEF, "Pbridge_console1aZ", &Pbridge_console1aZ},
    {0xF0, "Pbridge_console1bZ", &Pbridge_console1bZ},
    {0xF1, "Pbridge_console2aZ", &Pbridge_console2aZ},
    {0xF2, "Pbridge_console2bZ", &Pbridge_console2bZ},
    {0xF3, "Pbridge_console3aZ", &Pbridge_console3aZ},
    {0xF4, "Pbridge_console3bZ", &Pbridge_console3bZ},
    {0xF5, "PcarbmwZ", &PcarbmwZ},
    {0xF6, "Pcard_box1Z", &Pcard_box1Z},
    {0xF7, "Pcard_box2Z", &Pcard_box2Z},
    {0xF8, "Pcard_box3Z", &Pcard_box3Z},
    {0xF9, "Pcard_box4_lgZ", &Pcard_box4Z},
    {0xFA, "Pcard_box5_lgZ", &Pcard_box5Z},
    {0xFB, "Pcard_box6_lgZ", &Pcard_box6Z},
    {0xFC, "PcarescortZ", &PcarescortZ},
    {0xFD, "PcargolfZ", &PcargolfZ},
    {0xFE, "PcarweirdZ", &PcarweirdZ},
    {0xFF, "PcarzilZ", &PcarzilZ},
    {0x100, "PcctvZ", &PcctvZ},
    {0x101, "PchraudiotapeZ", &PchraudiotapeZ},
    {0x102, "PchrautoshotZ", &PchrautoshotZ},
    {0x103, "PchrblackboxZ", &PchrblackboxZ},
    {0x104, "PchrblueprintsZ", &PchrblueprintsZ},
    {0x105, "PchrbombcaseZ", &PchrbombcaseZ},
    {0x106, "PchrbombdefuserZ", &PchrbombdefuserZ},
    {0x107, "PchrbriefcaseZ", &PchrbriefcaseZ},
    {0x108, "PchrbugZ", &PchrbugZ},
    {0x109, "PchrbugdetectorZ", &PchrbugdetectorZ},
    {0x10A, "PchrbungeeZ", &PchrbungeeZ},
    {0x10B, "PchrcameraZ", &PchrcameraZ},
    {0x10C, "PchrcircuitboardZ", &PchrcircuitboardZ},
    {0x10D, "PchrclipboardZ", &PchrclipboardZ},
    {0x10E, "PchrcreditcardZ", &PchrcreditcardZ},
    {0x10F, "PchrdarkglassesZ", &PchrdarkglassesZ},
    {0x110, "PchrdatathiefZ", &PchrdatathiefZ},
    {0x111, "PchrdattapeZ", &PchrdattapeZ},
    {0x112, "PchrdoordecoderZ", &PchrdoordecoderZ},
    {0x113, "PchrdoorexploderZ", &PchrdoorexploderZ},
    {0x114, "PchrdossierredZ", &PchrdossierredZ},
    {0x115, "PchrdynamiteZ", &PchrdynamiteZ},
    {0x116, "PchrexplosivepenZ", &PchrexplosivepenZ},
    {0x117, "PchrextinguisherZ", &PchrextinguisherZ},
    {0x118, "PchrfingergunZ", &PchrfingergunZ},
    {0x119, "PchrflarepistolZ", &PchrflarepistolZ},
    {0x11A, "Pchrfnp90Z", &Pchrfnp90Z},
    {0x11B, "PchrgaskeyringZ", &PchrgaskeyringZ},
    {0x11C, "PchrgoldbarZ", &PchrgoldbarZ},
    {0x11D, "PchrgoldenZ", &PchrgoldenZ},
    {0x11E, "PchrgoldeneyekeyZ", &PchrgoldeneyekeyZ},
    {0x11F, "PchrgoldwppkZ", &PchrgoldwppkZ},
    {0x120, "PchrgrenadeZ", &PchrgrenadeZ},
    {0x121, "PchrgrenadelaunchZ", &PchrgrenadelaunchZ},
    {0x122, "PchrgrenaderoundZ", &PchrgrenaderoundZ},
    {0x123, "PchrheroinZ", &PchrheroinZ},
    {0x124, "PchrkalashZ", &PchrkalashZ},
    {0x125, "PchrkeyanalysercaseZ", &PchrkeyanalysercaseZ},
    {0x126, "PchrkeyboltZ", &PchrkeyboltZ},
    {0x127, "PchrkeyyaleZ", &PchrkeyyaleZ},
    {0x128, "PchrknifeZ", &PchrknifeZ},
    {0x129, "PchrlaserZ", &PchrlaserZ},
    {0x12A, "PchrlectreZ", &PchrlectreZ},
    {0x12B, "PchrlockexploderZ", &PchrlockexploderZ},
    {0x12C, "Pchrm16Z", &Pchrm16Z},
    {0x12D, "PchrmapZ", &PchrmapZ},
    {0x12E, "PchrmicrocameraZ", &PchrmicrocameraZ},
    {0x12F, "PchrmicrocodeZ", &PchrmicrocodeZ},
    {0x130, "PchrmicrofilmZ", &PchrmicrofilmZ},
    {0x131, "PchrmoneyZ", &PchrmoneyZ},
    {0x132, "Pchrmp5kZ", &Pchrmp5kZ},
    {0x133, "Pchrmp5ksilZ", &Pchrmp5ksilZ},
    {0x134, "PchrpitongunZ", &PchrpitongunZ},
    {0x135, "PchrplansZ", &PchrplansZ},
    {0x136, "PchrplastiqueZ", &PchrplastiqueZ},
    {0x137, "PchrpolarizedglassesZ", &PchrpolarizedglassesZ},
    {0x138, "PchrproximitymineZ", &PchrproximitymineZ},
    {0x139, "PchrremotemineZ", &PchrremotemineZ},
    {0x13A, "PchrrocketZ", &PchrrocketZ},
    {0x13B, "PchrrocketlaunchZ", &PchrrocketlaunchZ},
    {0x13C, "PchrrugerZ", &PchrrugerZ},
    {0x13D, "PchrsafecrackercaseZ", &PchrsafecrackercaseZ},
    {0x13E, "PchrshotgunZ", &PchrshotgunZ},
    {0x13F, "PchrsilverwppkZ", &PchrsilverwppkZ},
    {0x140, "PchrskorpionZ", &PchrskorpionZ},
    {0x141, "PchrsniperrifleZ", &PchrsniperrifleZ},
    {0x142, "PchrspectreZ", &PchrspectreZ},
    {0x143, "PchrspooltapeZ", &PchrspooltapeZ},
    {0x144, "PchrspyfileZ", &PchrspyfileZ},
    {0x145, "PchrstafflistZ", &PchrstafflistZ},
    {0x146, "PchrtesttubeZ", &PchrtesttubeZ},
    {0x147, "PchrthrowknifeZ", &PchrthrowknifeZ},
    {0x148, "PchrtimedmineZ", &PchrtimedmineZ},
    {0x149, "Pchrtt33Z", &Pchrtt33Z},
    {0x14A, "PchruziZ", &PchruziZ},
    {0x14B, "PchrvideotapeZ", &PchrvideotapeZ},
    {0x14C, "PchrweaponcaseZ", &PchrweaponcaseZ},
    {0x14D, "PchrwppkZ", &PchrwppkZ},
    {0x14E, "PchrwppksilZ", &PchrwppksilZ},
    {0x14F, "PchrwristdartZ", &PchrwristdartZ},
    {0x150, "Pconsole1Z", &Pconsole1Z},
    {0x151, "Pconsole2Z", &Pconsole2Z},
    {0x152, "Pconsole3Z", &Pconsole3Z},
    {0x153, "Pconsole_sev2aZ", &Pconsole_sev2aZ},
    {0x154, "Pconsole_sev2bZ", &Pconsole_sev2bZ},
    {0x155, "Pconsole_sev2cZ", &Pconsole_sev2cZ},
    {0x156, "Pconsole_sev2dZ", &Pconsole_sev2dZ},
    {0x157, "Pconsole_sev_GEaZ", &Pconsole_sev_GEaZ},
    {0x158, "Pconsole_sev_GEbZ", &Pconsole_sev_GEbZ},
    {0x159, "Pconsole_sevaZ", &Pconsole_sevaZ},
    {0x15A, "Pconsole_sevbZ", &Pconsole_sevbZ},
    {0x15B, "Pconsole_sevcZ", &Pconsole_sevcZ},
    {0x15C, "Pconsole_sevdZ", &Pconsole_sevdZ},
    {0x15D, "Pcryptdoor1aZ", &Pcryptdoor1aZ},
    {0x15E, "Pcryptdoor1bZ", &Pcryptdoor1bZ},
    {0x15F, "Pcryptdoor2aZ", &Pcryptdoor2aZ},
    {0x160, "Pcryptdoor2bZ", &Pcryptdoor2bZ},
    {0x161, "Pcryptdoor3Z", &Pcryptdoor3Z},
    {0x162, "Pcryptdoor4Z", &Pcryptdoor4Z},
    {0x163, "PdamchaindoorZ", &PdamchaindoorZ},
    {0x164, "PdamgatedoorZ", &PdamgatedoorZ},
    {0x165, "PdamtundoorZ", &PdamtundoorZ},
    {0x166, "Pdepot_door_steelZ", &Pdepot_door_steelZ},
    {0x167, "Pdepot_gate_entryZ", &Pdepot_gate_entryZ},
    {0x168, "Pdesk1Z", &Pdesk1Z},
    {0x169, "Pdesk2Z", &Pdesk2Z},
    {0x16A, "Pdesk_arecibo1Z", &Pdesk_arecibo1Z},
    {0x16B, "Pdesk_lamp2Z", &Pdesk_lamp2Z},
    {0x16C, "Pdest_engineZ", &Pdest_engineZ},
    {0x16D, "Pdest_exocetZ", &Pdest_exocetZ},
    {0x16E, "Pdest_gunZ", &Pdest_gunZ},
    {0x16F, "Pdest_harpoonZ", &Pdest_harpoonZ},
    {0x170, "Pdest_seawolfZ", &Pdest_seawolfZ},
    {0x171, "Pdisc_readerZ", &Pdisc_readerZ},
    {0x172, "Pdisk_drive1Z", &Pdisk_drive1Z},
    {0x173, "Pdoor_azt_chairZ", &Pdoor_azt_chairZ},
    {0x174, "Pdoor_azt_deskZ", &Pdoor_azt_deskZ},
    {0x175, "Pdoor_azt_desk_topZ", &Pdoor_azt_desk_topZ},
    {0x176, "Pdoor_aztecZ", &Pdoor_aztecZ},
    {0x177, "Pdoor_dest1Z", &Pdoor_dest1Z},
    {0x178, "Pdoor_dest2Z", &Pdoor_dest2Z},
    {0x179, "Pdoor_eyelidZ", &Pdoor_eyelidZ},
    {0x17A, "Pdoor_irisZ", &Pdoor_irisZ},
    {0x17B, "Pdoor_mfZ", &Pdoor_mfZ},
    {0x17C, "Pdoor_roller1Z", &Pdoor_roller1Z},
    {0x17D, "Pdoor_roller2Z", &Pdoor_roller2Z},
    {0x17E, "Pdoor_roller3Z", &Pdoor_roller3Z},
    {0x17F, "Pdoor_roller4Z", &Pdoor_roller4Z},
    {0x180, "Pdoor_rollertrainZ", &Pdoor_rollertrainZ},
    {0x181, "Pdoor_st_arec1Z", &Pdoor_st_arec1Z},
    {0x182, "Pdoor_st_arec2Z", &Pdoor_st_arec2Z},
    {0x183, "Pdoor_winZ", &Pdoor_winZ},
    {0x184, "PdoorconsoleZ", &PdoorconsoleZ},
    {0x185, "PdoorpanelZ", &PdoorpanelZ},
    {0x186, "Pdoorprison1Z", &Pdoorprison1Z},
    {0x187, "PdoorstatgateZ", &PdoorstatgateZ},
    {0x188, "PexplosionbitZ", &PexplosionbitZ},
    {0x189, "Pfiling_cabinet1Z", &Pfiling_cabinet1Z},
    {0x18A, "PflagZ", &PflagZ},
    {0x18B, "PfloppyZ", &PfloppyZ},
    {0x18C, "Pfnp90magZ", &Pfnp90magZ},
    {0x18D, "Pgas_plant_met1_do1Z", &Pgas_plant_met1_do1Z},
    {0x18E, "Pgas_plant_sw2_do1Z", &Pgas_plant_sw2_do1Z},
    {0x18F, "Pgas_plant_sw3_do1Z", &Pgas_plant_sw3_do1Z},
    {0x190, "Pgas_plant_sw4_do1Z", &Pgas_plant_sw4_do1Z},
    {0x191, "Pgas_plant_sw_do1Z", &Pgas_plant_sw_do1Z},
    {0x192, "Pgas_plant_wc_cub1Z", &Pgas_plant_wc_cub1Z},
    {0x193, "PgasbarrelZ", &PgasbarrelZ},
    {0x194, "PgasbarrelsZ", &PgasbarrelsZ},
    {0x195, "Pgasplant_clear_doorZ", &Pgasplant_clear_doorZ},
    {0x196, "PgastankZ", &PgastankZ},
    {0x197, "Pglassware1Z", &Pglassware1Z},
    {0x198, "Pglassware2Z", &Pglassware2Z},
    {0x199, "Pglassware3Z", &Pglassware3Z},
    {0x19A, "Pglassware4Z", &Pglassware4Z},
    {0x19B, "PgoldeneyelogoZ", &PgoldeneyelogoZ},
    {0x19C, "PgoldenshellsZ", &PgoldenshellsZ},
    {0x19D, "PgroundgunZ", &PgroundgunZ},
    {0x19E, "Pgun_runway1Z", &Pgun_runway1Z},
    {0x19F, "PhatberetZ", &PhatberetZ},
    {0x1A0, "PhatberetblueZ", &PhatberetblueZ},
    {0x1A1, "PhatberetredZ", &PhatberetredZ},
    {0x1A2, "PhatchboltZ", &PhatchboltZ},
    {0x1A3, "PhatchdoorZ", &PhatchdoorZ},
    {0x1A4, "PhatchsevxZ", &PhatchsevxZ},
    {0x1A5, "PhatfurryZ", &PhatfurryZ},
    {0x1A6, "PhatfurryblackZ", &PhatfurryblackZ},
    {0x1A7, "PhatfurrybrownZ", &PhatfurrybrownZ},
    {0x1A8, "PhathelmetZ", &PhathelmetZ},
    {0x1A9, "PhathelmetgreyZ", &PhathelmetgreyZ},
    {0x1AA, "PhatmoonZ", &PhatmoonZ},
    {0x1AB, "PhatpeakedZ", &PhatpeakedZ},
    {0x1AC, "PhattbirdZ", &PhattbirdZ},
    {0x1AD, "PhattbirdbrownZ", &PhattbirdbrownZ},
    {0x1AE, "PhelicopterZ", &PhelicopterZ},
    {0x1AF, "PhindZ", &PhindZ},
    {0x1B0, "PjeepZ", &PjeepZ},
    {0x1B1, "Pjerry_can1Z", &Pjerry_can1Z},
    {0x1B2, "Pjungle3_treeZ", &Pjungle3_treeZ},
    {0x1B3, "Pjungle5_treeZ", &Pjungle5_treeZ},
    {0x1B4, "Pkey_holderZ", &Pkey_holderZ},
    {0x1B5, "Pkeyboard1Z", &Pkeyboard1Z},
    {0x1B6, "Pkit_units1Z", &Pkit_units1Z},
    {0x1B7, "PlabbenchZ", &PlabbenchZ},
    {0x1B8, "PlandmineZ", &PlandmineZ},
    {0x1B9, "PlegalpageZ", &PlegalpageZ},
    {0x1BA, "Pletter_tray1Z", &Pletter_tray1Z},
    {0x1BB, "Plocker3Z", &Plocker3Z},
    {0x1BC, "Plocker4Z", &Plocker4Z},
    {0x1BD, "Pm16magZ", &Pm16magZ},
    {0x1BE, "PmagnumshellsZ", &PmagnumshellsZ},
    {0x1BF, "Pmainframe1Z", &Pmainframe1Z},
    {0x1C0, "Pmainframe2Z", &Pmainframe2Z},
    {0x1C1, "Pmetal_chair1Z", &Pmetal_chair1Z},
    {0x1C2, "Pmetal_crate1Z", &Pmetal_crate1Z},
    {0x1C3, "Pmetal_crate2Z", &Pmetal_crate2Z},
    {0x1C4, "Pmetal_crate3Z", &Pmetal_crate3Z},
    {0x1C5, "Pmetal_crate4Z", &Pmetal_crate4Z},
    {0x1C6, "PmilcopterZ", &PmilcopterZ},
    {0x1C7, "PmiltruckZ", &PmiltruckZ},
    {0x1C8, "Pmissile_rack2Z", &Pmissile_rack2Z},
    {0x1C9, "Pmissile_rackZ", &Pmissile_rackZ},
    {0x1CA, "PmodemboxZ", &PmodemboxZ},
    {0x1CB, "PmotorbikeZ", &PmotorbikeZ},
    {0x1CC, "Pmp5kmagZ", &Pmp5kmagZ},
    {0x1CD, "PnintendologoZ", &PnintendologoZ},
    {0x1CE, "Poil_drum1Z", &Poil_drum1Z},
    {0x1CF, "Poil_drum2Z", &Poil_drum2Z},
    {0x1D0, "Poil_drum3Z", &Poil_drum3Z},
    {0x1D1, "Poil_drum5Z", &Poil_drum5Z},
    {0x1D2, "Poil_drum6Z", &Poil_drum6Z},
    {0x1D3, "Poil_drum7Z", &Poil_drum7Z},
    {0x1D4, "PpadlockZ", &PpadlockZ},
    {0x1D5, "PpalmZ", &PpalmZ},
    {0x1D6, "PpalmtreeZ", &PpalmtreeZ},
    {0x1D7, "Pphone1Z", &Pphone1Z},
    {0x1D8, "PplaneZ", &PplaneZ},
    {0x1D9, "Pplant11Z", &Pplant11Z},
    {0x1DA, "Pplant1Z", &Pplant1Z},
    {0x1DB, "Pplant2Z", &Pplant2Z},
    {0x1DC, "Pplant2bZ", &Pplant2bZ},
    {0x1DD, "Pplant3Z", &Pplant3Z},
    {0x1DE, "Pradio_unit1Z", &Pradio_unit1Z},
    {0x1DF, "Pradio_unit2Z", &Pradio_unit2Z},
    {0x1E0, "Pradio_unit3Z", &Pradio_unit3Z},
    {0x1E1, "Pradio_unit4Z", &Pradio_unit4Z},
    {0x1E2, "ProofgunZ", &ProofgunZ},
    {0x1E3, "PsafeZ", &PsafeZ},
    {0x1E4, "PsafedoorZ", &PsafedoorZ},
    {0x1E5, "Psat1_reflectZ", &Psat1_reflectZ},
    {0x1E6, "PsatboxZ", &PsatboxZ},
    {0x1E7, "PsatdishZ", &PsatdishZ},
    {0x1E8, "Psec_panelZ", &Psec_panelZ},
    {0x1E9, "Psev_door3Z", &Psev_door3Z},
    {0x1EA, "Psev_door3_windZ", &Psev_door3_windZ},
    {0x1EB, "Psev_door4_windZ", &Psev_door4_windZ},
    {0x1EC, "Psev_doorZ", &Psev_doorZ},
    {0x1ED, "Psev_door_v1Z", &Psev_door_v1Z},
    {0x1EE, "Psev_trislideZ", &Psev_trislideZ},
    {0x1EF, "PsevdishZ", &PsevdishZ},
    {0x1F0, "PsevdoormetslideZ", &PsevdoormetslideZ},
    {0x1F1, "PsevdoornowindZ", &PsevdoornowindZ},
    {0x1F2, "PsevdoorwindZ", &PsevdoorwindZ},
    {0x1F3, "PsevdoorwoodZ", &PsevdoorwoodZ},
    {0x1F4, "PshuttleZ", &PshuttleZ},
    {0x1F5, "Pshuttle_door_lZ", &Pshuttle_door_lZ},
    {0x1F6, "Pshuttle_door_rZ", &Pshuttle_door_rZ},
    {0x1F7, "PsilencerZ", &PsilencerZ},
    {0x1F8, "Psilo_lift_doorZ", &Psilo_lift_doorZ},
    {0x1F9, "PsilotopdoorZ", &PsilotopdoorZ},
    {0x1FA, "PskorpionmagZ", &PskorpionmagZ},
    {0x1FB, "PspectremagZ", &PspectremagZ},
    {0x1FC, "PspeedboatZ", &PspeedboatZ},
    {0x1FD, "Pst_pete_room_1iZ", &Pst_pete_room_1iZ},
    {0x1FE, "Pst_pete_room_2iZ", &Pst_pete_room_2iZ},
    {0x1FF, "Pst_pete_room_3tZ", &Pst_pete_room_3tZ},
    {0x200, "Pst_pete_room_5cZ", &Pst_pete_room_5cZ},
    {0x201, "Pst_pete_room_6cZ", &Pst_pete_room_6cZ},
    {0x202, "Psteel_door1Z", &Psteel_door1Z},
    {0x203, "Psteel_door2Z", &Psteel_door2Z},
    {0x204, "Psteel_door2bZ", &Psteel_door2bZ},
    {0x205, "Psteel_door3Z", &Psteel_door3Z},
    {0x206, "Pstool1Z", &Pstool1Z},
    {0x207, "Pswipe_card2Z", &Pswipe_card2Z},
    {0x208, "Pswivel_chair1Z", &Pswivel_chair1Z},
    {0x209, "PtankZ", &PtankZ},
    {0x20A, "PtigerZ", &PtigerZ},
    {0x20B, "Ptorpedo_rackZ", &Ptorpedo_rackZ},
    {0x20C, "Ptrain_door2Z", &Ptrain_door2Z},
    {0x20D, "Ptrain_door3Z", &Ptrain_door3Z},
    {0x20E, "Ptrain_doorZ", &Ptrain_doorZ},
    {0x20F, "PtrainextdoorZ", &PtrainextdoorZ},
    {0x210, "Ptt33magZ", &Ptt33magZ},
    {0x211, "Ptuning_console1Z", &Ptuning_console1Z},
    {0x212, "Ptv1Z", &Ptv1Z},
    {0x213, "Ptv4screenZ", &Ptv4screenZ},
    {0x214, "Ptv_holderZ", &Ptv_holderZ},
    {0x215, "PtvscreenZ", &PtvscreenZ},
    {0x216, "PuzimagZ", &PuzimagZ},
    {0x217, "PvertdoorZ", &PvertdoorZ},
    {0x218, "PwalletbondZ", &PwalletbondZ},
    {0x219, "PwindowZ", &PwindowZ},
    {0x21A, "Pwindow_cor11Z", &Pwindow_cor11Z},
    {0x21B, "Pwindow_lib_lg1Z", &Pwindow_lib_lg1Z},
    {0x21C, "Pwindow_lib_sm1Z", &Pwindow_lib_sm1Z},
    {0x21D, "Pwood_lg_crate1Z", &Pwood_lg_crate1Z},
    {0x21E, "Pwood_lg_crate2Z", &Pwood_lg_crate2Z},
    {0x21F, "Pwood_md_crate3Z", &Pwood_md_crate3Z},
    {0x220, "Pwood_sm_crate4Z", &Pwood_sm_crate4Z},
    {0x221, "Pwood_sm_crate5Z", &Pwood_sm_crate5Z},
    {0x222, "Pwood_sm_crate6Z", &Pwood_sm_crate6Z},
    {0x223, "Pwooden_table1Z", &Pwooden_table1Z},
    {0x224, "PwppkmagZ", &PwppkmagZ},

    {0x225, "Tbg_ame_all_p_stanZ", &Tbg_ame_all_p_stanZ},
    {0x226, "Tbg_arch_all_p_stanZ", &Tbg_arch_all_p_stanZ},
    {0x227, "Tbg_arec_all_p_stanZ", &Tbg_arec_all_p_stanZ},
    {0x228, "Tbg_ark_all_p_stanZ", &Tbg_ark_all_p_stanZ},
    {0x229, "Tbg_ash_all_p_stanZ", &Tbg_ash_all_p_stanZ},
    {0x22A, "Tbg_azt_all_p_stanZ", &Tbg_azt_all_p_stanZ},
    {0x22B, "Tbg_cat_all_p_stanZ", &Tbg_cat_all_p_stanZ},
    {0x22C, "Tbg_cave_all_p_stanZ", &Tbg_cave_all_p_stanZ},
    {0x22D, "Tbg_crad_all_p_stanZ", &Tbg_crad_all_p_stanZ},
    {0x22E, "Tbg_cryp_all_p_stanZ", &Tbg_cryp_all_p_stanZ},
    {0x22F, "Tbg_dam_all_p_stanZ", &Tbg_dam_all_p_stanZ},
    {0x230, "Tbg_depo_all_p_stanZ", &Tbg_depo_all_p_stanZ},
    {0x231, "Tbg_dest_all_p_stanZ", &Tbg_dest_all_p_stanZ},
    {0x232, "Tbg_dish_all_p_stanZ", &Tbg_dish_all_p_stanZ},
    {0x233, "Tbg_ear_all_p_stanZ", &Tbg_imp_all_p_stanZ},
    {0x234, "Tbg_eld_all_p_stanZ", &Tbg_imp_all_p_stanZ},
    {0x235, "Tbg_imp_all_p_stanZ", &Tbg_imp_all_p_stanZ},
    {0x236, "Tbg_jun_all_p_stanZ", &Tbg_jun_all_p_stanZ},
    {0x237, "Tbg_lee_all_p_stanZ", &Tbg_len_all_p_stanZ},
    {0x238, "Tbg_len_all_p_stanZ", &Tbg_len_all_p_stanZ},
    {0x239, "Tbg_lip_all_p_stanZ", &Tbg_oat_all_p_stanZ},
    {0x23A, "Tbg_lue_all_p_stanZ", &Tbg_oat_all_p_stanZ},
    {0x23B, "Tbg_oat_all_p_stanZ", &Tbg_oat_all_p_stanZ},
    {0x23C, "Tbg_pam_all_p_stanZ", &Tbg_pete_all_p_stanZ},
    {0x23D, "Tbg_pete_all_p_stanZ", &Tbg_pete_all_p_stanZ},
    {0x23E, "Tbg_ref_all_p_stanZ", &Tbg_ref_all_p_stanZ},
    {0x23F, "Tbg_rit_all_p_stanZ", &Tbg_run_all_p_stanZ},
    {0x240, "Tbg_run_all_p_stanZ", &Tbg_run_all_p_stanZ},
    {0x241, "Tbg_sev_all_p_stanZ", &Tbg_sev_all_p_stanZ},
    {0x242, "Tbg_sevb_all_p_stanZ", &Tbg_sevb_all_p_stanZ},
    {0x243, "Tbg_sevx_all_p_stanZ", &Tbg_sevx_all_p_stanZ},
    {0x244, "Tbg_silo_all_p_stanZ", &Tbg_silo_all_p_stanZ},
    {0x245, "Tbg_stat_all_p_stanZ", &Tbg_stat_all_p_stanZ},
    {0x246, "Tbg_tra_all_p_stanZ", &Tbg_tra_all_p_stanZ},
    {0x247, "Tbg_wax_all_p_stanZ", &UbriefarchZ},

    {0x248, "UbriefarchZ", &UbriefarchZ},
    {0x249, "UbriefarkZ", &UbriefarkZ},
    {0x24A, "UbriefaztZ", &UbriefaztZ},
    {0x24B, "UbriefcaveZ", &UbriefcaveZ},
    {0x24C, "UbriefcontrolZ", &UbriefcontrolZ},
    {0x24D, "UbriefcradZ", &UbriefcradZ},
    {0x24E, "UbriefcrypZ", &UbriefcrypZ},
    {0x24F, "UbriefdamZ", &UbriefdamZ},
    {0x250, "UbriefdepoZ", &UbriefdepoZ},
    {0x251, "UbriefdestZ", &UbriefdestZ},
    {0x252, "UbriefjunZ", &UbriefjunZ},
    {0x253, "UbriefpeteZ", &UbriefpeteZ},
    {0x254, "UbriefrunZ", &UbriefrunZ},
    {0x255, "UbriefsevbZ", &UbriefsevbZ},
    {0x256, "UbriefsevbunkerZ", &UbriefsevbunkerZ},
    {0x257, "UbriefsevxZ", &UbriefsevxZ},
    {0x258, "UbriefsevxbZ", &UbriefsevxbZ},
    {0x259, "UbriefsiloZ", &UbriefsiloZ},
    {0x25A, "UbriefstatueZ", &UbriefstatueZ},
    {0x25B, "UbrieftraZ", &UbrieftraZ},

    {0x25C, "Ump_setupameZ", &Ump_setupameZ},
    {0x25D, "Ump_setuparchZ", &Ump_setuparchZ},
    {0x25E, "Ump_setuparkZ", &Ump_setuparkZ},
    {0x25F, "Ump_setupashZ", &Ump_setupashZ},
    {0x260, "Ump_setupcaveZ", &Ump_setupcaveZ},
    {0x261, "Ump_setupcradZ", &Ump_setupcradZ},
    {0x262, "Ump_setupcrypZ", &Ump_setupcrypZ},
    {0x263, "Ump_setupdishZ", &Ump_setupdishZ},
    {0x264, "Ump_setupimpZ", &Ump_setupimpZ},
    {0x265, "Ump_setupoatZ", &Ump_setupoatZ},
    {0x266, "Ump_setuprefZ", &Ump_setuprefZ},
    {0x267, "Ump_setupsevbZ", &Ump_setupsevbZ},
    {0x268, "Ump_setupstatueZ", &Ump_setupstatueZ},

    {0x269, "UsetuparchZ", &UsetuparchZ},
    {0x26A, "UsetuparkZ", &UsetuparkZ},
    {0x26B, "UsetupaztZ", &UsetupaztZ},
    {0x26C, "UsetupcaveZ", &UsetupcaveZ},
    {0x26D, "UsetupcontrolZ", &UsetupcontrolZ},
    {0x26E, "UsetupcradZ", &UsetupcradZ},
    {0x26F, "UsetupcrypZ", &UsetupcrypZ},
    {0x270, "UsetupdamZ", &UsetupdamZ},
    {0x271, "UsetupdepoZ", &UsetupdepoZ},
    {0x272, "UsetupdestZ", &UsetupdestZ},
    {0x273, "UsetupjunZ", &UsetupjunZ},
    {0x274, "UsetuplenZ", &UsetuplenZ},
    {0x275, "UsetuppeteZ", &UsetuppeteZ},
    {0x276, "UsetuprunZ", &UsetuprunZ},
    {0x277, "UsetupsevbZ", &UsetupsevbZ},
    {0x278, "UsetupsevbunkerZ", &UsetupsevbunkerZ},
    {0x279, "UsetupsevxZ", &UsetupsevxZ},
    {0x27A, "UsetupsevxbZ", &UsetupsevxbZ},
    {0x27B, "UsetupsiloZ", &UsetupsiloZ},
    {0x27C, "UsetupstatueZ", &UsetupstatueZ},
    {0x27D, "UsetuptraZ", &UsetuptraZ},

    {0x27E, "LameE", &LameE},
    {0x27F, "LameJ", &LameJ},
    {0x280, "LarchE", &LarchE},
    {0x281, "LarchJ", &LarchJ},
    {0x282, "LarecE", &LarecE},
    {0x283, "LarecJ", &LarecJ},
    {0x284, "LarkE", &LarkE},
    {0x285, "LarkJ", &LarkJ},
    {0x286, "LashE", &LashE},
    {0x287, "LashJ", &LashJ},
    {0x288, "LaztE", &LaztE},
    {0x289, "LaztJ", &LaztJ},
    {0x28A, "LcatE", &LcatE},
    {0x28B, "LcatJ", &LcatJ},
    {0x28C, "LcaveE", &LcaveE},
    {0x28D, "LcaveJ", &LcaveJ},
    {0x28E, "LcradE", &LcradE},
    {0x28F, "LcradJ", &LcradJ},
    {0x290, "LcrypE", &LcrypE},
    {0x291, "LcrypJ", &LcrypJ},
    {0x292, "LdamE", &LdamE},
    {0x293, "LdamJ", &LdamJ},
    {0x294, "LdepoE", &LdepoE},
    {0x295, "LdepoJ", &LdepoJ},
    {0x296, "LdestE", &LdestE},
    {0x297, "LdestJ", &LdestJ},
    {0x298, "LdishE", &LdishE},
    {0x299, "LdishJ", &LdishJ},
    {0x29A, "LearE", &LearE},
    {0x29B, "LearJ", &LearJ},
    {0x29C, "LeldE", &LeldE},
    {0x29D, "LeldJ", &LeldJ},
    {0x29E, "LgunE", &LgunE},
    {0x29F, "LgunJ", &LgunJ},
    {0x2A0, "LimpE", &LimpE},
    {0x2A1, "LimpJ", &LimpJ},
    {0x2A2, "LjunE", &LjunE},
    {0x2A3, "LjunJ", &LjunJ},
    {0x2A4, "LleeE", &LleeE},
    {0x2A5, "LleeJ", &LleeJ},
    {0x2A6, "LlenE", &LlenE},
    {0x2A7, "LlenJ", &LlenJ},
    {0x2A8, "LlipE", &LlipE},
    {0x2A9, "LlipJ", &LlipJ},
    {0x2AA, "LlueE", &LlueE},
    {0x2AB, "LlueJ", &LlueJ},
    {0x2AC, "LmiscE", &LmiscE},
    {0x2AD, "LmiscJ", &LmiscJ},
    {0x2AE, "LmpmenuE", &LmpmenuE},
    {0x2AF, "LmpmenuJ", &LmpmenuJ},
    {0x2B0, "LmpweaponsE", &LmpweaponsE},
    {0x2B1, "LmpweaponsJ", &LmpweaponsJ},
    {0x2B2, "LoatE", &LoatE},
    {0x2B3, "LoatJ", &LoatJ},
    {0x2B4, "LoptionsE", &LoptionsE},
    {0x2B5, "LoptionsJ", &LoptionsJ},
    {0x2B6, "LpamE", &LpamE},
    {0x2B7, "LpamJ", &LpamJ},
    {0x2B8, "LpeteE", &LpeteE},
    {0x2B9, "LpeteJ", &LpeteJ},
    {0x2BA, "LpropobjE", &LpropobjE},
    {0x2BB, "LpropobjJ", &LpropobjJ},
    {0x2BC, "LrefE", &LrefE},
    {0x2BD, "LrefJ", &LrefJ},
    {0x2BE, "LritE", &LritE},
    {0x2BF, "LritJ", &LritJ},
    {0x2C0, "LrunE", &LrunE},
    {0x2C1, "LrunJ", &LrunJ},
    {0x2C2, "LsevE", &LsevE},
    {0x2C3, "LsevJ", &LsevJ},
    {0x2C4, "LsevbE", &LsevbE},
    {0x2C5, "LsevbJ", &LsevbJ},
    {0x2C6, "LsevxE", &LsevxE},
    {0x2C7, "LsevxJ", &LsevxJ},
    {0x2C8, "LsevxbE", &LsevxbE},
    {0x2C9, "LsevxbJ", &LsevxbJ},
    {0x2CA, "LshoE", &LshoE},
    {0x2CB, "LshoJ", &LshoJ},
    {0x2CC, "LsiloE", &LsiloE},
    {0x2CD, "LsiloJ", &LsiloJ},
    {0x2CE, "LstatE", &LstatE},
    {0x2CF, "LstatJ", &LstatJ},
    {0x2D0, "LtitleE", &LtitleE},
    {0x2D1, "LtitleJ", &LtitleJ},
    {0x2D2, "LtraE", &LtraE},
    {0x2D3, "LtraJ", &LtraJ},
    {0x2D4, "LwaxE", &LwaxE},
    {0x2D5, "LwaxJ", &LwaxJ},

    {0x2D6, "ob/ob_end.seg", &ob_seg},
    {0},
    {0},
    {0},
    {0},
    {0},
    {0},
    {0},
    {0},
    {0}};

#define OBJ_INDEX_END 727
int file_entry_max = OBJ_INDEX_END;

void load_resource(unsigned char *ptrdata, unsigned int bytes,
                   struct fileentry *srcfile,
                   struct resource_lookup_data_entry *lookupdata) {
  unsigned char *source;
  unsigned char buffer[0x2100];
  int unused;

  if (bytes == 0) {
    romCopy(ptrdata, srcfile->hw_address, lookupdata->rom_size);
    return;
  }
  source = (ptrdata + bytes) - ((lookupdata->rom_size + 7) & -8);
  if ((unsigned int)(source - ptrdata) < 8) {
    lookupdata->pc_remaining = 0;
  } else {
    romCopy(source, srcfile->hw_address, lookupdata->rom_size);
    lookupdata->pc_remaining = decompressdata(source, ptrdata, buffer);
  }
}

const unsigned int rz_header_1[] = {0x11720000};
const unsigned int rz_header_2[] = {0x11720000};

asm(R"
glabel resource_load_from_indy
  addiu $sp, $sp, -0x2128
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  move  $s0, $a0
  move  $s1, $a3
  sw    $ra, 0x1c($sp)
  bnez  $a1, .L7F0BCB68
   sw    $a1, 0x212c($sp)
  lw    $a0, 4($a2)
  jal   load_resource_on_indy
   move  $a1, $s0
  b     .L7F0BCC18
   lw    $ra, 0x1c($sp)
.L7F0BCB68:
  lw    $a0, 4($a2)
  sw    $a2, 0x2130($sp)
  jal   check_file_found_on_indy
   addiu $a1, $s1, 8
  lw    $t9, 8($s1)
  lw    $t7, 0x212c($sp)
  li    $at, -8
  addiu $t0, $t9, 7
  and   $t1, $t0, $at
  addu  $t8, $s0, $t7
  subu  $a3, $t8, $t1
  subu  $t2, $a3, $s0
  sltiu $at, $t2, 8
  beqz  $at, .L7F0BCBAC
   lw    $a2, 0x2130($sp)
  b     .L7F0BCC14
   sw    $zero, 4($s1)
.L7F0BCBAC:
  lw    $a0, 4($a2)
  sw    $a3, 0x2124($sp)
  jal   load_resource_on_indy
   move  $a1, $a3
  lw    $a3, 0x2124($sp)
  lui   $t4, %hi(rz_header_1) 
  lbu   $t4, %lo(rz_header_1)($t4)
  lbu   $t3, ($a3)
  lui   $t6, %hi(rz_header_2 + 0x1) 
  move  $a1, $s0
  bne   $t3, $t4, .L7F0BCC04
   move  $a0, $a3
  lbu   $t5, 1($a3)
  lbu   $t6, %lo(rz_header_2 + 0x1)($t6)
  addiu $a2, $sp, 0x24
  bne   $t5, $t6, .L7F0BCC04
   nop   
  move  $a0, $a3
  jal   decompressdata
   move  $a1, $s0
  b     .L7F0BCC10
   move  $v1, $v0
.L7F0BCC04:
  jal   _bcopy
   lw    $a2, 8($s1)
  lw    $v1, 8($s1)
.L7F0BCC10:
  sw    $v1, 4($s1)
.L7F0BCC14:
  lw    $ra, 0x1c($sp)
.L7F0BCC18:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x2128
");

const char aOb_c_debug[] = "ob_c_debug";

asm(R"
glabel ob_c_debug_setup
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lui   $a0, %hi(ob_c_debug_notice_list_entry)
  lui   $a1, %hi(aOb_c_debug)
  addiu $a1, %lo(aOb_c_debug) # addiu $a1, $a1, -0x498c
  jal   get_ptr_debug_notice_list_entry
   addiu $a0, %lo(ob_c_debug_notice_list_entry) # addiu $a0, $a0, 0x6050
  lui   $v1, %hi(file_entry_max)
  lw    $v1, %lo(file_entry_max)($v1)
  lui   $a0, %hi(file_resource_table + 0xC)
  addiu $a0, %lo(file_resource_table + 0xC) # addiu $a0, $a0, 0x6060
  addiu $v1, $v1, -1
  slti  $at, $v1, 2
  bnez  $at, .L7F0BCCAC
   lui   $v0, %hi(resource_lookup_data_array+0x14)
  sll   $t6, $v1, 2
  addu  $t6, $t6, $v1
  lui   $t7, %hi(resource_lookup_data_array) 
  addiu $t7, %lo(resource_lookup_data_array) # addiu $t7, $t7, -0x7750
  sll   $t6, $t6, 2
  addu  $a1, $t6, $t7
  addiu $v0, %lo(resource_lookup_data_array+0x14) # addiu $v0, $v0, -0x773c
.L7F0BCC80:
  lw    $t8, 0x14($a0)
  lw    $t9, 8($a0)
  addiu $v0, $v0, 0x14
  sltu  $at, $v0, $a1
  subu  $v1, $t8, $t9
  addiu $a0, $a0, 0xc
  sw    $v1, -0x14($v0)
  sw    $zero, -0x10($v0)
  sw    $zero, -0xc($v0)
  bnez  $at, .L7F0BCC80
   sw    $zero, -8($v0)
.L7F0BCCAC:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

void _load_rom_index_to_membank(int index, int param_2, int size,
                                unsigned char bank) {
  load_rom_resource_index_to_membank(index, param_2, size, bank);
}

void _load_resource_index_to_membank(int index, int param_2,
                                     unsigned char *ptrdata, int size) {
  load_resource_index_to_buffer(index, param_2, ptrdata, size);
}

void _load_resource_named_to_membank(unsigned char *filename, int param_2,
                                     int size, unsigned char bank) {
  load_rom_resource_index_to_membank(get_index_num_of_named_resource(filename),
                                     param_2, size, bank);
}

void _load_resource_named_to_buffer(unsigned char *filename, int bank,
                                    unsigned char *ptrdata, int size) {
  load_resource_index_to_buffer(get_index_num_of_named_resource(filename), bank,
                                ptrdata, size);
}

void obLoadBGFileBytesAtOffset(unsigned char *bgname, unsigned char *target,
                               int offset, int len) {
  int index;
  struct fileentry *fileentry;

  index = get_index_num_of_named_resource(bgname);
  fileentry = &file_resource_table[index];

  if (resource_lookup_data_array[index].rom_size != 0) {
    // if the size of offset data would exceed file size, loop forever
    if ((resource_lookup_data_array[index].rom_size + 0xF) < (offset + len)) {
      while (1) {
      };
    }
    romCopy(target, &fileentry->hw_address[offset], len, fileentry);
  }
}

asm(R"
glabel load_rom_resource_index_to_membank
  addiu $sp, $sp, -0x30
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  sw    $a0, 0x30($sp)
  sw    $a1, 0x34($sp)
  sw    $a2, 0x38($sp)
  beqz  $a1, .L7F0BCE44
   sw    $a3, 0x3c($sp)
  li    $at, 1
  beq   $a1, $at, .L7F0BCE44
   li    $at, 2
  bne   $a1, $at, .L7F0BCF0C
   lw    $t5, 0x30($sp)
.L7F0BCE44:
  lw    $t7, 0x30($sp)
  lui   $t9, %hi(resource_lookup_data_array) 
  addiu $t9, %lo(resource_lookup_data_array) # addiu $t9, $t9, -0x7750
  sll   $t8, $t7, 2
  addu  $t8, $t8, $t7
  sll   $t8, $t8, 2
  addu  $s1, $t8, $t9
  lw    $s0, 4($s1)
  bnezl $s0, .L7F0BCE80
   move  $a0, $s0
  jal   mempGetBankSizeLeft
   lbu   $a0, 0x3f($sp)
  sw    $v0, 4($s1)
  move  $s0, $v0
  move  $a0, $s0
.L7F0BCE80:
  jal   mempAllocBytesInBank
   lbu   $a1, 0x3f($sp)
  lw    $s0, 4($s1)
  lui   $t2, %hi(file_resource_table) 
  addiu $t2, %lo(file_resource_table) # addiu $t2, $t2, 0x6054
  sw    $s0, 0xc($s1)
  lw    $t0, 0x30($sp)
  move  $a0, $v0
  move  $a3, $s1
  sll   $t1, $t0, 2
  subu  $t1, $t1, $t0
  sll   $t1, $t1, 2
  addu  $a2, $t1, $t2
  lw    $t3, 8($a2)
  move  $a1, $s0
  bnez  $t3, .L7F0BCEDC
   nop   
  move  $a1, $s0
  move  $a3, $s1
  jal   resource_load_from_indy
   sw    $v0, 0x24($sp)
  b     .L7F0BCEE8
   lw    $s0, 0x24($sp)
.L7F0BCEDC:
  jal   load_resource
   sw    $a0, 0x24($sp)
  lw    $s0, 0x24($sp)
.L7F0BCEE8:
  lw    $t4, 0x34($sp)
  move  $a0, $s0
  lbu   $a2, 0x3f($sp)
  beql  $t4, $zero, .L7F0BCFCC
   lw    $ra, 0x1c($sp)
  jal   mempAddEntryOfSizeToBank
   lw    $a1, 4($s1)
  b     .L7F0BCFCC
   lw    $ra, 0x1c($sp)
.L7F0BCF0C:
  sll   $t6, $t5, 2
  addu  $t6, $t6, $t5
  lui   $t7, %hi(resource_lookup_data_array) 
  addiu $t7, %lo(resource_lookup_data_array) # addiu $t7, $t7, -0x7750
  sll   $t6, $t6, 2
  addu  $s1, $t6, $t7
  lw    $s0, 4($s1)
  bnezl $s0, .L7F0BCF50
   move  $a0, $s0
  lw    $v0, ($s1)
  beqz  $v0, .L7F0BCF44
   move  $s0, $v0
  b     .L7F0BCF4C
   sw    $v0, 4($s1)
.L7F0BCF44:
  lw    $s0, 8($s1)
  sw    $s0, 4($s1)
.L7F0BCF4C:
  move  $a0, $s0
.L7F0BCF50:
  jal   mempAllocBytesInBank
   lbu   $a1, 0x3f($sp)
  lw    $t9, 4($s1)
  lui   $t2, %hi(file_resource_table) 
  addiu $t2, %lo(file_resource_table) # addiu $t2, $t2, 0x6054
  sw    $t9, 0xc($s1)
  lw    $t0, 0x30($sp)
  move  $s0, $v0
  move  $a3, $s1
  sll   $t1, $t0, 2
  subu  $t1, $t1, $t0
  sll   $t1, $t1, 2
  addu  $a2, $t1, $t2
  lw    $t3, 8($a2)
  move  $a0, $s0
  move  $a1, $zero
  bnez  $t3, .L7F0BCFAC
   nop   
  move  $a0, $v0
  jal   resource_load_from_indy
   move  $a1, $zero
  b     .L7F0BCFB8
   lw    $t4, 0x38($sp)
.L7F0BCFAC:
  jal   load_resource
   move  $a3, $s1
  lw    $t4, 0x38($sp)
.L7F0BCFB8:
  lbu   $t5, 0x3f($sp)
  bnezl $t4, .L7F0BCFCC
   lw    $ra, 0x1c($sp)
  sb    $t5, 0x10($s1)
  lw    $ra, 0x1c($sp)
.L7F0BCFCC:
  move  $v0, $s0
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x30
");

/*
 *this matches except:
 *baserom.u.z64
 *000F 1BC0: AE 0C 00 0C 8F A5 00 2C  0F C2 F2 A8 8F A4 00 28  ......., .......(
 *ge007.u.z64               this   is flipped with   this
 *000F 1BC0: AE 0C 00 0C 8F A4 00 28  0F C2 F2 A8 8F A5 00 2C  .......( .......,
 */
asm(R"
glabel load_resource_index_to_buffer
  sll   $t6, $a0, 2
  addiu $sp, $sp, -0x20
  addu  $t6, $t6, $a0
  lui   $t7, %hi(resource_lookup_data_array) 
  sw    $s0, 0x18($sp)
  addiu $t7, %lo(resource_lookup_data_array) # addiu $t7, $t7, -0x7750
  sll   $t6, $t6, 2
  addu  $s0, $t6, $t7
  lw    $t8, 4($s0)
  sw    $ra, 0x1c($sp)
  sw    $a2, 0x28($sp)
  bnez  $t8, .L7F0BD030
   sw    $a3, 0x2c($sp)
  lw    $v0, ($s0)
  beql  $v0, $zero, .L7F0BD02C
   lw    $t9, 8($s0)
  b     .L7F0BD030
   sw    $v0, 4($s0)
  lw    $t9, 8($s0)
.L7F0BD02C:
  sw    $t9, 4($s0)
.L7F0BD030:
  beqz  $a1, .L7F0BD048
   li    $at, 1
  beq   $a1, $at, .L7F0BD048
   li    $at, 2
  bne   $a1, $at, .L7F0BD0A8
   sll   $t5, $a0, 2
.L7F0BD048:
  sll   $t0, $a0, 2
  subu  $t0, $t0, $a0
  lui   $t1, %hi(file_resource_table) 
  addiu $t1, %lo(file_resource_table) # addiu $t1, $t1, 0x6054
  sll   $t0, $t0, 2
  addu  $a2, $t0, $t1
  lw    $t2, 8($a2)
  lw    $t3, 0x2c($sp)
  lw    $t4, 0x2c($sp)
  bnez  $t2, .L7F0BD090
   move  $a3, $s0
  sw    $t3, 0xc($s0)
  lw    $a0, 0x28($sp)
  lw    $a1, 0x2c($sp)
  jal   resource_load_from_indy
   move  $a3, $s0
  b     .L7F0BD0F0
   lw    $ra, 0x1c($sp)
.L7F0BD090:
  sw    $t4, 0xc($s0)
  lw    $a1, 0x2c($sp)
  jal   load_resource
   lw    $a0, 0x28($sp)
  b     .L7F0BD0F0
   lw    $ra, 0x1c($sp)
.L7F0BD0A8:
  subu  $t5, $t5, $a0
  lui   $t6, %hi(file_resource_table) 
  addiu $t6, %lo(file_resource_table) # addiu $t6, $t6, 0x6054
  sll   $t5, $t5, 2
  addu  $a2, $t5, $t6
  lw    $t7, 8($a2)
  move  $a3, $s0
  lw    $a0, 0x28($sp)
  bnez  $t7, .L7F0BD0E4
   move  $a1, $zero
  lw    $a0, 0x28($sp)
  jal   resource_load_from_indy
   move  $a1, $zero
  b     .L7F0BD0F0
   lw    $ra, 0x1c($sp)
.L7F0BD0E4:
  jal   load_resource
   move  $a3, $s0
  lw    $ra, 0x1c($sp)
.L7F0BD0F0:
  lw    $v0, 0x28($sp)
  lw    $s0, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x20
");

int get_pc_remaining_buffer_for_index(int index) {
  return resource_lookup_data_array[index].pc_remaining;
}

int get_rom_remaining_buffer_for_index(int index) {
  return resource_lookup_data_array[index].rom_remaining;
}

asm(R"
glabel sub_GAME_7F0BD138
  sll   $t6, $a0, 2
  addu  $t6, $t6, $a0
  lui   $t7, %hi(resource_lookup_data_array) 
  addiu $t7, %lo(resource_lookup_data_array) # addiu $t7, $t7, -0x7750
  sll   $t6, $t6, 2
  addiu $sp, $sp, -0x18
  addu  $v0, $t6, $t7
  sw    $ra, 0x14($sp)
  sw    $a1, 0x1c($sp)
  sw    $a2, 4($v0)
  beqz  $a3, .L7F0BD178
   sw    $a2, 0xc($v0)
  move  $a0, $a1
  move  $a1, $a2
  jal   mempAddEntryOfSizeToBank
   li    $a2, 4
.L7F0BD178:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

int get_pc_buffer_remaining_value(unsigned char *name) {
  return resource_lookup_data_array[get_index_num_of_named_resource(name)]
      .pc_remaining;
}

void obBlankResourcesLoadedInBank(unsigned char bank) {
  int i;
  for (i = 1; i < file_entry_max; i++) {
    if (resource_lookup_data_array[i].loaded_bank <= bank) {
      resource_lookup_data_array[i].loaded_bank = '\0';
    }
    if (bank == 4) {
      resource_lookup_data_array[i].pc_remaining = 0;
    }
  }
}

void sub_GAME_7F0BD234(void) { obBlankResourcesLoadedInBank(5); }

asm(R"
glabel get_index_num_of_named_resource
  addiu $sp, $sp, -0x40
  sw    $s2, 0x1c($sp)
  lui   $s2, %hi(file_entry_max)
  addiu $s2, %lo(file_entry_max) # addiu $s2, $s2, -0x7d2c
  lw    $v0, ($s2)
  sw    $s3, 0x20($sp)
  sw    $s1, 0x18($sp)
  slti  $at, $v0, 2
  move  $s3, $a0
  sw    $ra, 0x24($sp)
  sw    $s0, 0x14($sp)
  bnez  $at, .L7F0BD2CC
   li    $s1, 1
  lui   $s0, %hi(file_resource_table + 0xC)
  addiu $s0, %lo(file_resource_table + 0xC) # addiu $s0, $s0, 0x6060
  lw    $a1, 4($s0)
.L7F0BD294:
  beql  $a1, $zero, .L7F0BD2B8
   lw    $v0, ($s2)
  jal   something_with_strings_0
   move  $a0, $s3
  bnezl $v0, .L7F0BD2B8
   lw    $v0, ($s2)
  b     .L7F0BD368
   move  $v0, $s1
  lw    $v0, ($s2)
.L7F0BD2B8:
  addiu $s1, $s1, 1
  addiu $s0, $s0, 0xc
  slt   $at, $s1, $v0
  bnezl $at, .L7F0BD294
   lw    $a1, 4($s0)
.L7F0BD2CC:
  slti  $at, $v0, 0x2e0
  bnez  $at, .L7F0BD2E0
   move  $s1, $v0
  b     .L7F0BD368
   move  $v0, $zero
.L7F0BD2E0:
  addiu $t6, $v0, 1
  sw    $t6, ($s2)
  move  $a0, $s3
  jal   check_file_found_on_indy
   addiu $a1, $sp, 0x34
  bnez  $v0, .L7F0BD304
   sll   $t7, $s1, 2
  b     .L7F0BD368
   move  $v0, $zero
.L7F0BD304:
  subu  $t7, $t7, $s1
  lui   $t8, %hi(file_resource_table) 
  addiu $t8, %lo(file_resource_table) # addiu $t8, $t8, 0x6054
  sll   $t7, $t7, 2
  sll   $t9, $s1, 2
  addu  $s0, $t7, $t8
  addu  $t9, $t9, $s1
  lui   $t0, %hi(resource_lookup_data_array) 
  addiu $t0, %lo(resource_lookup_data_array) # addiu $t0, $t0, -0x7750
  sll   $t9, $t9, 2
  sw    $s1, ($s0)
  sw    $s3, 4($s0)
  addu  $v1, $t9, $t0
  sb    $zero, 0x11($v1)
  sw    $zero, 8($s0)
  sw    $zero, ($v1)
  sw    $zero, 4($v1)
  lw    $t1, 0x34($sp)
  sw    $zero, 0xc($v1)
  sb    $zero, 0x10($v1)
  addiu $t2, $t1, 0xf
  ori   $t3, $t2, 0xf
  xori  $t4, $t3, 0xf
  sw    $t4, 8($v1)
  move  $v0, $s1
.L7F0BD368:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x40
");

void removed_handle_filetable_entry(unsigned int index) {}

void removed_loop_handle_filetable_entries(void) {
  int i;
  for (i = 1; i < file_entry_max; i++)
    removed_handle_filetable_entry(i);
}

void removed_loop_filetableentries(void) {
  int i;
  for (i = 1; i < file_entry_max; i++)
    ;
}

asm(R"
glabel sub_GAME_7F0BD410
  lui   $v1, %hi(file_entry_max)
  lw    $v1, %lo(file_entry_max)($v1)
  lui   $v0, %hi(resource_lookup_data_array+0x14)
  addiu $v0, %lo(resource_lookup_data_array+0x14) # addiu $v0, $v0, -0x773c
  slti  $at, $v1, 2
  bnez  $at, .L7F0BD450
   sll   $t6, $v1, 2
  addu  $t6, $t6, $v1
  lui   $t7, %hi(resource_lookup_data_array) 
  addiu $t7, %lo(resource_lookup_data_array) # addiu $t7, $t7, -0x7750
  sll   $t6, $t6, 2
  addu  $a0, $t6, $t7
  addiu $v0, $v0, 0x14
.L7F0BD444:
  sltu  $at, $v0, $a0
  bnezl $at, .L7F0BD444
   addiu $v0, $v0, 0x14
.L7F0BD450:
  jr    $ra
   nop   
");
