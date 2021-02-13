#include "image_externs.h"

struct image_entry {
  char flag1, flag2;
  unsigned short size;
  char flag3, flag4;
  char flag5, flag6;
};

extern int ptr_texture_alloc_start;
extern struct image_entry image_entries[];

int ptr_texture_alloc_start, ptr_texture_alloc_end, ptr_next_available_space,
    ptr_last_entry_facemapping;
int word_CODE_bss_8008C730[0x258];
int dword_CODE_bss_8008D090, dword_CODE_bss_8008D094;

unsigned int bytes = 0x6DDD0, D_80049174 = 0;

// bytes in pixel data for image
int pixelbytecounts[] = {4, 3, 3, 3, 2, 2, 1, 1, 1, 1, 1, 1, 1};

// 1=alphagrab.  Grabs 1 bit of alpha data for each pixel
int pixelalphas[] = {0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0};

// bits in 'samples', *2	-1=bitmask
int pixelsamplebits[] = {0x100, 0x20, 0x100, 0x20, 0x100, 0x10, 8,
                         0x100, 0x10, 0x100, 0x10, 0x100, 0x10};

// bitcount for pixel data
int pixelbitcount[] = {
    0x20, 0x10, 0x18, 0xF, 0x10, 8, 4, 8, 4, 0x10, 0x10, 0x10, 0x10,
};

// N64 image types (0=color, 1=YUV, 2=indexed, 3=IA, 4=I)
int n64imagetypes[] = {0, 0, 0, 0, 3, 3, 3, 4, 4, 2, 2, 2, 2};

// N64 pixel sizes (0=4bit, 1=8bit, 2=16bit, 3=32bit)
int n64pixelsizes[] = {3, 2, 3, 2, 2, 1, 0, 1, 0, 1, 0, 1, 0};

// imageflip values for indexed types
int imgflipvalues[] = {0, 0, 0,      0,      0,      0,     0,
                       0, 0, 0x8000, 0x8000, 0xC000, 0xC000};

int D_800492E4[7] = {0};

// TODO: Need way to calculate size at compile time from external data.
struct image_entry image_entries[] = {
    {0, 0, _image1_size, 0, 0, 0, 0},
    {0, 0, _image2_size, 0, 0, 0, 0},
    {0, 0, _image3_size, 0, 0, 0, 0},
    {0, 0, _image4_size, 0, 0, 0, 0},
    {0, 0, _image5_size, 0, 0, 0, 0},
    {0, 0, _image6_size, 0, 0, 0, 0},
    {0, 0, _image7_size, 0, 0, 0, 0},
    {0, 0, _image8_size, 0, 0, 0, 0},
    {0, 0, _image9_size, 0, 0, 0, 0},
    {0x11, 0, _image10_size, 0, 0, 0, 0},
    {0x11, 0, _image11_size, 0, 0, 0, 0},
    {0, 0, _image12_size, 0, 0, 0, 0},
    {0, 0, _image13_size, 0, 0, 0, 0},
    {0, 0, _image14_size, 0, 0, 0, 0},
    {0, 0, _image15_size, 0, 0, 0, 0},
    {0, 0, _image16_size, 0, 0, 0, 0},
    {0, 0, _image17_size, 0, 0, 0, 0},
    {0, 0, _image18_size, 0, 0, 0, 0},
    {0, 0, _image19_size, 0, 0, 0, 0},
    {0, 0, _image20_size, 0, 0, 0, 0},
    {0x77, 0, _image21_size, 0, 0, 0, 0},
    {0, 0, _image22_size, 0x38, 0xD2, 0, 0},
    {0x77, 0, _image23_size, 0x38, 0xD2, 0, 0},
    {0, 0, _image24_size, 0, 0, 0, 0},
    {0, 0, _image25_size, 0, 0, 0, 0},
    {0, 0, _image26_size, 0, 0, 0, 0},
    {0, 0, _image27_size, 0, 0, 0, 0},
    {0, 0, _image28_size, 0, 0, 0, 0},
    {0, 0, _image29_size, 0, 0, 0, 0},
    {0xAA, 0, _image30_size, 0, 0, 0, 0},
    {0xAA, 0, _image31_size, 0, 0, 0, 0},
    {0xAA, 0, _image32_size, 0, 0, 0, 0},
    {0xAA, 0, _image33_size, 0, 0, 0, 0},
    {0x22, 0, _image34_size, 0, 0, 0, 0},
    {0x22, 0, _image35_size, 0, 0, 0, 0},
    {0x22, 0, _image36_size, 0, 0, 0, 0},
    {0x22, 0, _image37_size, 0, 0, 0, 0},
    {0, 0, _image38_size, 0, 0, 0, 0},
    {0, 0, _image39_size, 0, 0, 0, 0},
    {0, 0, _image40_size, 0, 0, 0, 0},
    {0, 0, _image41_size, 0, 0, 0, 0},
    {0, 0, _image42_size, 0, 0, 0, 0},
    {0, 0, _image43_size, 0, 0, 0, 0},
    {0xAA, 0, _image44_size, 0, 0, 0, 0},
    {0, 0, _image45_size, 0, 0, 0, 0},
    {0xAA, 0, _image46_size, 0, 0, 0, 0},
    {0, 0, _image47_size, 0, 0, 0, 0},
    {0, 0, _image48_size, 0, 0, 0, 0},
    {0, 0, _image49_size, 0, 0, 0, 0},
    {0, 0, _image50_size, 0, 0, 0, 0},
    {0x33, 0, _image51_size, 0, 0, 0, 0},
    {0, 0, _image52_size, 0, 0, 0, 0},
    {0, 0, _image53_size, 0, 0, 0, 0},
    {0, 0, _image54_size, 0, 0, 0, 0},
    {0, 0, _image55_size, 0, 0, 0, 0},
    {0, 0, _image56_size, 0, 0, 0, 0},
    {0, 0, _image57_size, 0, 0, 0, 0},
    {0, 0, _image58_size, 0, 0, 0, 0},
    {0, 0, _image59_size, 0, 0, 0, 0},
    {0, 0, _image60_size, 0, 0, 0, 0},
    {0, 0, _image61_size, 0, 0, 0, 0},
    {0, 0, _image62_size, 0, 0, 0, 0},
    {0, 0, _image63_size, 0, 0, 0, 0},
    {0, 0, _image64_size, 0, 0, 0, 0},
    {0, 0, _image65_size, 0, 0, 0, 0},
    {0, 0, _image66_size, 0, 0, 0, 0},
    {0, 0, _image67_size, 0, 0, 0, 0},
    {0, 0, _image68_size, 0, 0, 0, 0},
    {0, 0, _image69_size, 0, 0, 0, 0},
    {0, 0, _image70_size, 0, 0, 0, 0},
    {0, 0, _image71_size, 0, 0, 0, 0},
    {0, 0, _image72_size, 0, 0, 0, 0},
    {0, 0, _image73_size, 0, 0, 0, 0},
    {0, 0, _image74_size, 0, 0, 0, 0},
    {0, 0, _image75_size, 0, 0, 0, 0},
    {0xAA, 0, _image76_size, 0, 0, 0, 0},
    {0xAA, 0, _image77_size, 0, 0, 0, 0},
    {0xAA, 0, _image78_size, 0, 0, 0, 0},
    {0x22, 0, _image79_size, 0, 0, 0, 0},
    {0x22, 0, _image80_size, 0, 0, 0, 0},
    {0x33, 0, _image81_size, 0, 0, 0, 0},
    {0x33, 0, _image82_size, 0, 0, 0, 0},
    {0x33, 0, _image83_size, 0, 0, 0, 0},
    {0x33, 0, _image84_size, 0, 0, 0, 0},
    {0x33, 0, _image85_size, 0, 0, 0, 0},
    {0, 0, _image86_size, 0, 0, 0, 0},
    {0, 0, _image87_size, 0, 0, 0, 0},
    {0, 0, _image88_size, 0, 0, 0, 0},
    {0x11, 0, _image89_size, 0, 0, 0, 0},
    {0x11, 0, _image90_size, 0, 0, 0, 0},
    {0x11, 0, _image91_size, 0, 0, 0, 0},
    {0x11, 0, _image92_size, 0, 0, 0, 0},
    {0x11, 0, _image93_size, 0, 0, 0, 0},
    {0x11, 0, _image94_size, 0, 0, 0, 0},
    {0x11, 0, _image95_size, 0, 0, 0, 0},
    {0x11, 0, _image96_size, 0, 0, 0, 0},
    {0x11, 0, _image97_size, 0, 0, 0, 0},
    {0x11, 0, _image98_size, 0, 0, 0, 0},
    {0x11, 0, _image99_size, 0, 0, 0, 0},
    {0x11, 0, _image100_size, 0, 0, 0, 0},
    {0x11, 0, _image101_size, 0, 0, 0, 0},
    {0x11, 0, _image102_size, 0, 0, 0, 0},
    {0x11, 0, _image103_size, 0, 0, 0, 0},
    {0x11, 0, _image104_size, 0, 0, 0, 0},
    {0x11, 0, _image105_size, 0, 0, 0, 0},
    {0x11, 0, _image106_size, 0, 0, 0, 0},
    {0x11, 0, _image107_size, 0, 0, 0, 0},
    {0x11, 0, _image108_size, 0, 0, 0, 0},
    {0x11, 0, _image109_size, 0, 0, 0, 0},
    {0x11, 0, _image110_size, 0, 0, 0, 0},
    {0x11, 0, _image111_size, 0, 0, 0, 0},
    {0x11, 0, _image112_size, 0, 0, 0, 0},
    {0x11, 0, _image113_size, 0, 0, 0, 0},
    {0x11, 0, _image114_size, 0, 0, 0, 0},
    {0x11, 0, _image115_size, 0, 0, 0, 0},
    {0x11, 0, _image116_size, 0, 0, 0, 0},
    {0x11, 0, _image117_size, 0, 0, 0, 0},
    {0x11, 0, _image118_size, 0, 0, 0, 0},
    {0x11, 0, _image119_size, 0, 0, 0, 0},
    {0x11, 0, _image120_size, 0, 0, 0, 0},
    {0x11, 0, _image121_size, 0, 0, 0, 0},
    {0x11, 0, _image122_size, 0, 0, 0, 0},
    {0x11, 0, _image123_size, 0, 0, 0, 0},
    {0x11, 0, _image124_size, 0, 0, 0, 0},
    {0x11, 0, _image125_size, 0, 0, 0, 0},
    {0x11, 0, _image126_size, 0, 0, 0, 0},
    {0x11, 0, _image127_size, 0, 0, 0, 0},
    {0x11, 0, _image128_size, 0, 0, 0, 0},
    {0x11, 0, _image129_size, 0, 0, 0, 0},
    {0x11, 0, _image130_size, 0, 0, 0, 0},
    {0x11, 0, _image131_size, 0, 0, 0, 0},
    {0x11, 0, _image132_size, 0, 0, 0, 0},
    {0x11, 0, _image133_size, 0, 0, 0, 0},
    {0x11, 0, _image134_size, 0, 0, 0, 0},
    {0x11, 0, _image135_size, 0, 0, 0, 0},
    {0x11, 0, _image136_size, 0, 0, 0, 0},
    {0x11, 0, _image137_size, 0, 0, 0, 0},
    {0x11, 0, _image138_size, 0, 0, 0, 0},
    {0x11, 0, _image139_size, 0, 0, 0, 0},
    {0x11, 0, _image140_size, 0, 0, 0, 0},
    {0x11, 0, _image141_size, 0, 0, 0, 0},
    {0x11, 0, _image142_size, 0, 0, 0, 0},
    {0x11, 0, _image143_size, 0, 0, 0, 0},
    {0x11, 0, _image144_size, 0, 0, 0, 0},
    {0x11, 0, _image145_size, 0, 0, 0, 0},
    {0x11, 0, _image146_size, 0, 0, 0, 0},
    {0x11, 0, _image147_size, 0, 0, 0, 0},
    {0, 0, _image148_size, 0, 0, 0, 0},
    {0xAA, 0, _image149_size, 0, 0, 0, 0},
    {0xAA, 0, _image150_size, 0, 0, 0, 0},
    {0xAA, 0, _image151_size, 0, 0, 0, 0},
    {0xAA, 0, _image152_size, 0, 0, 0, 0},
    {0xAA, 0, _image153_size, 0, 0, 0, 0},
    {0xAA, 0, _image154_size, 0, 0, 0, 0},
    {0xAA, 0, _image155_size, 0, 0, 0, 0},
    {0xAA, 0, _image156_size, 0, 0, 0, 0},
    {0, 0, _image157_size, 0, 0, 0, 0},
    {0, 0, _image158_size, 0, 0, 0, 0},
    {0, 0, _image159_size, 0, 0, 0, 0},
    {0, 0, _image160_size, 0, 0, 0, 0},
    {0x33, 0, _image161_size, 0, 0, 0, 0},
    {0x33, 0, _image162_size, 0, 0, 0, 0},
    {0x33, 0, _image163_size, 0, 0, 0, 0},
    {0x33, 0, _image164_size, 0, 0, 0, 0},
    {0x33, 0, _image165_size, 0, 0, 0, 0},
    {0x33, 0, _image166_size, 0, 0, 0, 0},
    {0x33, 0, _image167_size, 0, 0, 0, 0},
    {0x33, 0, _image168_size, 0, 0, 0, 0},
    {0, 0, _image169_size, 0, 0, 0, 0},
    {0x33, 0, _image170_size, 0, 0, 0, 0},
    {0, 0, _image171_size, 0, 0, 0, 0},
    {0, 0, _image172_size, 0, 0, 0, 0},
    {0, 0, _image173_size, 0, 0, 0, 0},
    {0, 0, _image174_size, 0, 0, 0, 0},
    {0, 0, _image175_size, 0, 0, 0, 0},
    {0, 0, _image176_size, 0, 0, 0, 0},
    {0, 0, _image177_size, 0, 0, 0, 0},
    {0xAA, 0, _image178_size, 0, 0, 0, 0},
    {0xAA, 0, _image179_size, 0, 0, 0, 0},
    {0xAA, 0, _image180_size, 0, 0, 0, 0},
    {0x11, 0, _image181_size, 0, 0, 0, 0},
    {0x11, 0, _image182_size, 0, 0, 0, 0},
    {0, 0, _image183_size, 0, 0, 0, 0},
    {0x11, 0, _image184_size, 0, 0, 0, 0},
    {0, 0, _image185_size, 0, 0, 0, 0},
    {0x22, 0, _image186_size, 0, 0, 0, 0},
    {0x77, 0, _image187_size, 0, 0, 0, 0},
    {0x77, 0, _image188_size, 0, 0, 0, 0},
    {0x22, 0, _image189_size, 0, 0, 0, 0},
    {0, 0, _image190_size, 0, 0, 0, 0},
    {0, 0, _image191_size, 0, 0, 0, 0},
    {0, 0, _image192_size, 0, 0, 0, 0},
    {0, 0, _image193_size, 0, 0, 0, 0},
    {0, 0, _image194_size, 0, 0, 0, 0},
    {0x33, 0, _image195_size, 0, 0, 0, 0},
    {0x11, 0, _image196_size, 0, 0, 0, 0},
    {0x77, 0, _image197_size, 0, 0, 0, 0},
    {0x33, 0, _image198_size, 0, 0, 0, 0},
    {0, 0, _image199_size, 0, 0, 0, 0},
    {0x33, 0, _image200_size, 0, 0, 0, 0},
    {0, 0, _image201_size, 0, 0, 0, 0},
    {0x44, 0, _image202_size, 0, 0, 0, 0},
    {0x44, 0, _image203_size, 0, 0, 0, 0},
    {0x44, 0, _image204_size, 0, 0, 0, 0},
    {0x44, 0, _image205_size, 0, 0, 0, 0},
    {0x44, 0, _image206_size, 0, 0, 0, 0},
    {0, 0, _image207_size, 0, 0, 0, 0},
    {0, 0, _image208_size, 0, 0, 0, 0},
    {0, 0, _image209_size, 0, 0, 0, 0},
    {0, 0, _image210_size, 0, 0, 0, 0},
    {0, 0, _image211_size, 0, 0, 0, 0},
    {0, 0, _image212_size, 0, 0, 0, 0},
    {0, 0, _image213_size, 0, 0, 0, 0},
    {0, 0, _image214_size, 0, 0, 0, 0},
    {0xAA, 0, _image215_size, 0, 0, 0, 0},
    {0, 0, _image216_size, 0, 0, 0, 0},
    {0, 0, _image217_size, 0, 0, 0, 0},
    {0, 0, _image218_size, 0, 0, 0, 0},
    {0, 0, _image219_size, 0, 0, 0, 0},
    {0x22, 0, _image220_size, 0, 0, 0, 0},
    {0x22, 0, _image221_size, 0, 0, 0, 0},
    {0x22, 0, _image222_size, 0, 0, 0, 0},
    {0x22, 0, _image223_size, 0, 0, 0, 0},
    {0x22, 0, _image224_size, 0, 0, 0, 0},
    {0x22, 0, _image225_size, 0, 0, 0, 0},
    {0x22, 0, _image226_size, 0, 0, 0, 0},
    {0, 0, _image227_size, 0, 0, 0, 0},
    {0, 0, _image228_size, 0, 0, 0, 0},
    {0, 0, _image229_size, 0, 0, 0, 0},
    {0xAA, 0, _image230_size, 0, 0, 0, 0},
    {0, 0, _image231_size, 0, 0, 0, 0},
    {0, 0, _image232_size, 0, 0, 0, 0},
    {0, 0, _image233_size, 0, 0, 0, 0},
    {0, 0, _image234_size, 0, 0, 0, 0},
    {0, 0, _image235_size, 0, 0, 0, 0},
    {0xAA, 0, _image236_size, 0, 0, 0, 0},
    {0xAA, 0, _image237_size, 0, 0, 0, 0},
    {0xAA, 0, _image238_size, 0, 0, 0, 0},
    {0xAA, 0, _image239_size, 0, 0, 0, 0},
    {0xAA, 0, _image240_size, 0, 0, 0, 0},
    {0xAA, 0, _image241_size, 0, 0, 0, 0},
    {0xAA, 0, _image242_size, 0, 0, 0, 0},
    {0x77, 0, _image243_size, 0, 0, 0, 0},
    {0x77, 0, _image244_size, 0, 0, 0, 0},
    {0x77, 0, _image245_size, 0, 0, 0, 0},
    {0, 0, _image246_size, 0, 0, 0, 0},
    {0, 0, _image247_size, 0, 0, 0, 0},
    {0x33, 0, _image248_size, 0, 0, 0, 0},
    {0x33, 0, _image249_size, 0, 0, 0, 0},
    {0x33, 0, _image250_size, 0, 0, 0, 0},
    {0x33, 0, _image251_size, 0, 0, 0, 0},
    {0x11, 0, _image252_size, 0, 0, 0, 0},
    {0x44, 0, _image253_size, 0, 0, 0, 0},
    {0x44, 0, _image254_size, 0, 0, 0, 0},
    {0x44, 0, _image255_size, 0, 0, 0, 0},
    {0x44, 0, _image256_size, 0, 0, 0, 0},
    {0x44, 0, _image257_size, 0, 0, 0, 0},
    {0x11, 0, _image258_size, 0, 0, 0, 0},
    {0x11, 0, _image259_size, 0, 0, 0, 0},
    {0x11, 0, _image260_size, 0, 0, 0, 0},
    {0xAA, 0, _image261_size, 0, 0, 0, 0},
    {0xAA, 0, _image262_size, 0, 0, 0, 0},
    {0xAA, 0, _image263_size, 0, 0, 0, 0},
    {0xAA, 0, _image264_size, 0, 0, 0, 0},
    {0x77, 0, _image265_size, 0, 0, 0, 0},
    {0xAA, 0, _image266_size, 0, 0, 0, 0},
    {0, 0, _image267_size, 0, 0, 0, 0},
    {0, 0, _image268_size, 0, 0, 0, 0},
    {0, 0, _image269_size, 0, 0, 0, 0},
    {0, 0, _image270_size, 0, 0, 0, 0},
    {0, 0, _image271_size, 0, 0, 0, 0},
    {0, 0, _image272_size, 0, 0, 0, 0},
    {0, 0, _image273_size, 0, 0, 0, 0},
    {0, 0, _image274_size, 0, 0, 0, 0},
    {0, 0, _image275_size, 0, 0, 0, 0},
    {0, 0, _image276_size, 0, 0, 0, 0},
    {0, 0, _image277_size, 0, 0, 0, 0},
    {0, 0, _image278_size, 0, 0, 0, 0},
    {0, 0, _image279_size, 0, 0, 0, 0},
    {0x11, 0, _image280_size, 0, 0, 0, 0},
    {0x11, 0, _image281_size, 0, 0, 0, 0},
    {0x11, 0, _image282_size, 0, 0, 0, 0},
    {0x11, 0, _image283_size, 0, 0, 0, 0},
    {0x11, 0, _image284_size, 0, 0, 0, 0},
    {0x11, 0, _image285_size, 0, 0, 0, 0},
    {0x11, 0, _image286_size, 0, 0, 0, 0},
    {0x11, 0, _image287_size, 0, 0, 0, 0},
    {0x11, 0, _image288_size, 0, 0, 0, 0},
    {0x11, 0, _image289_size, 0, 0, 0, 0},
    {0x11, 0, _image290_size, 0, 0, 0, 0},
    {0x11, 0, _image291_size, 0, 0, 0, 0},
    {0x11, 0, _image292_size, 0, 0, 0, 0},
    {0, 0, _image293_size, 0, 0, 0, 0},
    {0x11, 0, _image294_size, 0, 0, 0, 0},
    {0x11, 0, _image295_size, 0, 0, 0, 0},
    {0x11, 0, _image296_size, 0, 0, 0, 0},
    {0x11, 0, _image297_size, 0, 0, 0, 0},
    {0x11, 0, _image298_size, 0, 0, 0, 0},
    {0x11, 0, _image299_size, 0, 0, 0, 0},
    {0x11, 0, _image300_size, 0, 0, 0, 0},
    {0x11, 0, _image301_size, 0, 0, 0, 0},
    {0x11, 0, _image302_size, 0, 0, 0, 0},
    {0x11, 0, _image303_size, 0, 0, 0, 0},
    {0x11, 0, _image304_size, 0, 0, 0, 0},
    {0x77, 0, _image305_size, 0, 0, 0, 0},
    {0x11, 0, _image306_size, 0, 0, 0, 0},
    {0x11, 0, _image307_size, 0, 0, 0, 0},
    {0x11, 0, _image308_size, 0, 0, 0, 0},
    {0x11, 0, _image309_size, 0, 0, 0, 0},
    {0x11, 0, _image310_size, 0, 0, 0, 0},
    {0x11, 0, _image311_size, 0, 0, 0, 0},
    {0x11, 0, _image312_size, 0, 0, 0, 0},
    {0x11, 0, _image313_size, 0, 0, 0, 0},
    {0x11, 0, _image314_size, 0, 0, 0, 0},
    {0x11, 0, _image315_size, 0, 0, 0, 0},
    {0x11, 0, _image316_size, 0, 0, 0, 0},
    {0x11, 0, _image317_size, 0, 0, 0, 0},
    {0x11, 0, _image318_size, 0, 0, 0, 0},
    {0x11, 0, _image319_size, 0, 0, 0, 0},
    {0x11, 0, _image320_size, 0, 0, 0, 0},
    {0x11, 0, _image321_size, 0, 0, 0, 0},
    {0, 0, _image322_size, 0, 0, 0, 0},
    {0, 0, _image323_size, 0, 0, 0, 0},
    {0, 0, _image324_size, 0, 0, 0, 0},
    {0, 0, _image325_size, 0, 0, 0, 0},
    {0, 0, _image326_size, 0, 0, 0, 0},
    {0, 0, _image327_size, 0, 0, 0, 0},
    {0, 0, _image328_size, 0, 0, 0, 0},
    {0, 0, _image329_size, 0, 0, 0, 0},
    {0xAA, 0, _image330_size, 0, 0, 0, 0},
    {0xAA, 0, _image331_size, 0, 0, 0, 0},
    {0xAA, 0, _image332_size, 0, 0, 0, 0},
    {0xAA, 0, _image333_size, 0, 0, 0, 0},
    {0xAA, 0, _image334_size, 0, 0, 0, 0},
    {0xAA, 0, _image335_size, 0, 0, 0, 0},
    {0xAA, 0, _image336_size, 0, 0, 0, 0},
    {0xAA, 0, _image337_size, 0, 0, 0, 0},
    {0xAA, 0, _image338_size, 0, 0, 0, 0},
    {0xAA, 0, _image339_size, 0, 0, 0, 0},
    {0xAA, 0, _image340_size, 0, 0, 0, 0},
    {0xAA, 0, _image341_size, 0, 0, 0, 0},
    {0xAA, 0, _image342_size, 0, 0, 0, 0},
    {0xAA, 0, _image343_size, 0, 0, 0, 0},
    {0xAA, 0, _image344_size, 0, 0, 0, 0},
    {0xAA, 0, _image345_size, 0, 0, 0, 0},
    {0xAA, 0, _image346_size, 0, 0, 0, 0},
    {0xAA, 0, _image347_size, 0, 0, 0, 0},
    {0xAA, 0, _image348_size, 0, 0, 0, 0},
    {0xAA, 0, _image349_size, 0, 0, 0, 0},
    {0xAA, 0, _image350_size, 0, 0, 0, 0},
    {0xAA, 0, _image351_size, 0, 0, 0, 0},
    {0xAA, 0, _image352_size, 0, 0, 0, 0},
    {0xAA, 0, _image353_size, 0, 0, 0, 0},
    {0xAA, 0, _image354_size, 0, 0, 0, 0},
    {0xAA, 0, _image355_size, 0, 0, 0, 0},
    {0xAA, 0, _image356_size, 0, 0, 0, 0},
    {0xAA, 0, _image357_size, 0, 0, 0, 0},
    {0xAA, 0, _image358_size, 0, 0, 0, 0},
    {0xAA, 0, _image359_size, 0, 0, 0, 0},
    {0xAA, 0, _image360_size, 0, 0, 0, 0},
    {0xAA, 0, _image361_size, 0, 0, 0, 0},
    {0xAA, 0, _image362_size, 0, 0, 0, 0},
    {0xAA, 0, _image363_size, 0, 0, 0, 0},
    {0xAA, 0, _image364_size, 0, 0, 0, 0},
    {0xAA, 0, _image365_size, 0, 0, 0, 0},
    {0xAA, 0, _image366_size, 0, 0, 0, 0},
    {0xAA, 0, _image367_size, 0, 0, 0, 0},
    {0xAA, 0, _image368_size, 0, 0, 0, 0},
    {0xAA, 0, _image369_size, 0, 0, 0, 0},
    {0, 0, _image370_size, 0, 0, 0, 0},
    {0, 0, _image371_size, 0, 0, 0, 0},
    {0xAA, 0, _image372_size, 0, 0, 0, 0},
    {0xAA, 0, _image373_size, 0, 0, 0, 0},
    {0xAA, 0, _image374_size, 0, 0, 0, 0},
    {0xAA, 0, _image375_size, 0, 0, 0, 0},
    {0xAA, 0, _image376_size, 0, 0, 0, 0},
    {0xAA, 0, _image377_size, 0, 0, 0, 0},
    {0xAA, 0, _image378_size, 0, 0, 0, 0},
    {0xAA, 0, _image379_size, 0, 0, 0, 0},
    {0xAA, 0, _image380_size, 0, 0, 0, 0},
    {0xAA, 0, _image381_size, 0, 0, 0, 0},
    {0xAA, 0, _image382_size, 0, 0, 0, 0},
    {0x33, 0, _image383_size, 0, 0, 0, 0},
    {0x33, 0, _image384_size, 0, 0, 0, 0},
    {0x33, 0, _image385_size, 0, 0, 0, 0},
    {0x33, 0, _image386_size, 0, 0, 0, 0},
    {0, 0, _image387_size, 0, 0, 0, 0},
    {0, 0, _image388_size, 0, 0, 0, 0},
    {0, 0, _image389_size, 0, 0, 0, 0},
    {0, 0, _image390_size, 0, 0, 0, 0},
    {0, 0, _image391_size, 0, 0, 0, 0},
    {0, 0, _image392_size, 0, 0, 0, 0},
    {0, 0, _image393_size, 0, 0, 0, 0},
    {0, 0, _image394_size, 0, 0, 0, 0},
    {0x33, 0, _image395_size, 0, 0, 0, 0},
    {0x22, 0, _image396_size, 0, 0, 0, 0},
    {0x22, 0, _image397_size, 0, 0, 0, 0},
    {0x22, 0, _image398_size, 0, 0, 0, 0},
    {0x22, 0, _image399_size, 0, 0, 0, 0},
    {0x33, 0, _image400_size, 0, 0, 0, 0},
    {0x33, 0, _image401_size, 0, 0, 0, 0},
    {0x33, 0, _image402_size, 0, 0, 0, 0},
    {0x11, 0, _image403_size, 0, 0, 0, 0},
    {0x11, 0, _image404_size, 0, 0, 0, 0},
    {0x11, 0, _image405_size, 0, 0, 0, 0},
    {0x77, 0, _image406_size, 0, 0, 0, 0},
    {0x11, 0, _image407_size, 0, 0, 0, 0},
    {0x11, 0, _image408_size, 0, 0, 0, 0},
    {0x11, 0, _image409_size, 0, 0, 0, 0},
    {0x11, 0, _image410_size, 0, 0, 0, 0},
    {0x11, 0, _image411_size, 0, 0, 0, 0},
    {0, 0, _image412_size, 0, 0, 0, 0},
    {0, 0, _image413_size, 0, 0, 0, 0},
    {0, 0, _image414_size, 0, 0, 0, 0},
    {0, 0, _image415_size, 0, 0, 0, 0},
    {0, 0, _image416_size, 0, 0, 0, 0},
    {0, 0, _image417_size, 0, 0, 0, 0},
    {0, 0, _image418_size, 0, 0, 0, 0},
    {0, 0, _image419_size, 0, 0, 0, 0},
    {0, 0, _image420_size, 0, 0, 0, 0},
    {0, 0, _image421_size, 0, 0, 0, 0},
    {0, 0, _image422_size, 0, 0, 0, 0},
    {0, 0, _image423_size, 0, 0, 0, 0},
    {0, 0, _image424_size, 0, 0, 0, 0},
    {0, 0, _image425_size, 0, 0, 0, 0},
    {0, 0, _image426_size, 0, 0, 0, 0},
    {0xAA, 0, _image427_size, 0, 0, 0, 0},
    {0xAA, 0, _image428_size, 0, 0, 0, 0},
    {0x44, 0, _image429_size, 0, 0, 0, 0},
    {0xAA, 0, _image430_size, 0, 0, 0, 0},
    {0x33, 0, _image431_size, 0, 0, 0, 0},
    {0, 0, _image432_size, 0, 0, 0, 0},
    {0x11, 0, _image433_size, 0, 0, 0, 0},
    {0x11, 0, _image434_size, 0, 0, 0, 0},
    {0x77, 0, _image435_size, 0, 0, 0, 0},
    {0x11, 0, _image436_size, 0, 0, 0, 0},
    {0x11, 0, _image437_size, 0, 0, 0, 0},
    {0, 0, _image438_size, 0, 0, 0, 0},
    {0, 0, _image439_size, 0, 0, 0, 0},
    {0, 0, _image440_size, 0, 0, 0, 0},
    {0, 0, _image441_size, 0, 0, 0, 0},
    {0, 0, _image442_size, 0, 0, 0, 0},
    {0x77, 0, _image443_size, 0, 0, 0, 0},
    {0, 0, _image444_size, 0, 0, 0, 0},
    {0, 0, _image445_size, 0, 0, 0, 0},
    {0, 0, _image446_size, 0, 0, 0, 0},
    {0, 0, _image447_size, 0, 0, 0, 0},
    {0x44, 0, _image448_size, 0, 0, 0, 0},
    {0x44, 0, _image449_size, 0, 0, 0, 0},
    {0x11, 0, _image450_size, 0, 0, 0, 0},
    {0x11, 0, _image451_size, 0, 0, 0, 0},
    {0xAA, 0, _image452_size, 0, 0, 0, 0},
    {0x33, 0, _image453_size, 0, 0, 0, 0},
    {0x33, 0, _image454_size, 0, 0, 0, 0},
    {0, 0, _image455_size, 0, 0, 0, 0},
    {0, 0, _image456_size, 0, 0, 0, 0},
    {0, 0, _image457_size, 0, 0, 0, 0},
    {0xAA, 0, _image458_size, 0, 0, 0, 0},
    {0x33, 0, _image459_size, 0, 0, 0, 0},
    {0x33, 0, _image460_size, 0, 0, 0, 0},
    {0, 0, _image461_size, 0, 0, 0, 0},
    {0xAA, 0, _image462_size, 0, 0, 0, 0},
    {0, 0, _image463_size, 0, 0, 0, 0},
    {0, 0, _image464_size, 0, 0, 0, 0},
    {0, 0, _image465_size, 0, 0, 0, 0},
    {0xAA, 0, _image466_size, 0, 0, 0, 0},
    {0xAA, 0, _image467_size, 0, 0, 0, 0},
    {0xAA, 0, _image468_size, 0, 0, 0, 0},
    {0xAA, 0, _image469_size, 0, 0, 0, 0},
    {0xAA, 0, _image470_size, 0, 0, 0, 0},
    {0, 0, _image471_size, 0, 0, 0, 0},
    {0xAA, 0, _image472_size, 0, 0, 0, 0},
    {0xAA, 0, _image473_size, 0, 0, 0, 0},
    {0xAA, 0, _image474_size, 0, 0, 0, 0},
    {0x33, 0, _image475_size, 0, 0, 0, 0},
    {0x33, 0, _image476_size, 0, 0, 0, 0},
    {0x33, 0, _image477_size, 0, 0, 0, 0},
    {0x33, 0, _image478_size, 0, 0, 0, 0},
    {0x33, 0, _image479_size, 0, 0, 0, 0},
    {0x33, 0, _image480_size, 0, 0, 0, 0},
    {0, 0, _image481_size, 0, 0, 0, 0},
    {0x33, 0, _image482_size, 0, 0, 0, 0},
    {0x33, 0, _image483_size, 0, 0, 0, 0},
    {0x33, 0, _image484_size, 0, 0, 0, 0},
    {0x33, 0, _image485_size, 0, 0, 0, 0},
    {0x33, 0, _image486_size, 0, 0, 0, 0},
    {0xAA, 0, _image487_size, 0, 0, 0, 0},
    {0xAA, 0, _image488_size, 0, 0, 0, 0},
    {0xAA, 0, _image489_size, 0, 0, 0, 0},
    {0, 0, _image490_size, 0, 0, 0, 0},
    {0, 0, _image491_size, 0, 0, 0, 0},
    {0x33, 0, _image492_size, 0, 0, 0, 0},
    {0xAA, 0, _image493_size, 0, 0, 0, 0},
    {0, 0, _image494_size, 0, 0, 0, 0},
    {0, 0, _image495_size, 0, 0, 0, 0},
    {0, 0, _image496_size, 0, 0, 0, 0},
    {0, 0, _image497_size, 0, 0, 0, 0},
    {0, 0, _image498_size, 0, 0, 0, 0},
    {0, 0, _image499_size, 0, 0, 0, 0},
    {0xAA, 0, _image500_size, 0, 0, 0, 0},
    {0xAA, 0, _image501_size, 0, 0, 0, 0},
    {0xAA, 0, _image502_size, 0, 0, 0, 0},
    {0x33, 0, _image503_size, 0, 0, 0, 0},
    {0x33, 0, _image504_size, 0, 0, 0, 0},
    {0, 0, _image505_size, 0, 0, 0, 0},
    {0x33, 0, _image506_size, 0, 0, 0, 0},
    {0, 0, _image507_size, 0, 0, 0, 0},
    {0x33, 0, _image508_size, 0, 0, 0, 0},
    {0x33, 0, _image509_size, 0, 0, 0, 0},
    {0x33, 0, _image510_size, 0, 0, 0, 0},
    {0x33, 0, _image511_size, 0, 0, 0, 0},
    {0x33, 0, _image512_size, 0, 0, 0, 0},
    {0x33, 0, _image513_size, 0, 0, 0, 0},
    {0, 0, _image514_size, 0, 0, 0, 0},
    {0x33, 0, _image515_size, 0, 0, 0, 0},
    {0xAA, 0, _image516_size, 0, 0, 0, 0},
    {0xAA, 0, _image517_size, 0, 0, 0, 0},
    {0xAA, 0, _image518_size, 0, 0, 0, 0},
    {0xAA, 0, _image519_size, 0, 0, 0, 0},
    {0xAA, 0, _image520_size, 0, 0, 0, 0},
    {0, 0, _image521_size, 0, 0, 0, 0},
    {0xAA, 0, _image522_size, 0, 0, 0, 0},
    {0x33, 0, _image523_size, 0, 0, 0, 0},
    {0x33, 0, _image524_size, 0, 0, 0, 0},
    {0, 0, _image525_size, 0, 0, 0, 0},
    {0x33, 0, _image526_size, 0, 0, 0, 0},
    {0xAA, 0, _image527_size, 0, 0, 0, 0},
    {0xAA, 0, _image528_size, 0, 0, 0, 0},
    {0xAA, 0, _image529_size, 0, 0, 0, 0},
    {0xAA, 0, _image530_size, 0, 0, 0, 0},
    {0, 0, _image531_size, 0, 0, 0, 0},
    {0, 0, _image532_size, 0, 0, 0, 0},
    {0, 0, _image533_size, 0, 0, 0, 0},
    {0x33, 0, _image534_size, 0, 0, 0, 0},
    {0x33, 0, _image535_size, 0, 0, 0, 0},
    {0x33, 0, _image536_size, 0, 0, 0, 0},
    {0x44, 0, _image537_size, 0, 0, 0, 0},
    {0x77, 0, _image538_size, 0, 0, 0, 0},
    {0x77, 0, _image539_size, 0, 0, 0, 0},
    {0, 0, _image540_size, 0, 0, 0, 0},
    {0, 0, _image541_size, 0, 0, 0, 0},
    {0, 0, _image542_size, 0, 0, 0, 0},
    {0xAA, 0, _image543_size, 0, 0, 0, 0},
    {0, 0, _image544_size, 0, 0, 0, 0},
    {0, 0, _image545_size, 0, 0, 0, 0},
    {0x33, 0, _image546_size, 0, 0, 0, 0},
    {0x33, 0, _image547_size, 0, 0, 0, 0},
    {0x33, 0, _image548_size, 0, 0, 0, 0},
    {0x33, 0, _image549_size, 0, 0, 0, 0},
    {0x33, 0, _image550_size, 0, 0, 0, 0},
    {0x33, 0, _image551_size, 0, 0, 0, 0},
    {0x33, 0, _image552_size, 0, 0, 0, 0},
    {0x33, 0, _image553_size, 0, 0, 0, 0},
    {0x33, 0, _image554_size, 0, 0, 0, 0},
    {0x33, 0, _image555_size, 0, 0, 0, 0},
    {0x33, 0, _image556_size, 0, 0, 0, 0},
    {0x33, 0, _image557_size, 0, 0, 0, 0},
    {0x33, 0, _image558_size, 0, 0, 0, 0},
    {0x33, 0, _image559_size, 0, 0, 0, 0},
    {0x33, 0, _image560_size, 0, 0, 0, 0},
    {0x33, 0, _image561_size, 0, 0, 0, 0},
    {0x33, 0, _image562_size, 0, 0, 0, 0},
    {0x33, 0, _image563_size, 0, 0, 0, 0},
    {0x33, 0, _image564_size, 0, 0, 0, 0},
    {0x33, 0, _image565_size, 0, 0, 0, 0},
    {0x33, 0, _image566_size, 0, 0, 0, 0},
    {0x33, 0, _image567_size, 0, 0, 0, 0},
    {0x33, 0, _image568_size, 0, 0, 0, 0},
    {0x33, 0, _image569_size, 0, 0, 0, 0},
    {0x33, 0, _image570_size, 0, 0, 0, 0},
    {0x33, 0, _image571_size, 0, 0, 0, 0},
    {0x33, 0, _image572_size, 0, 0, 0, 0},
    {0x33, 0, _image573_size, 0, 0, 0, 0},
    {0x33, 0, _image574_size, 0, 0, 0, 0},
    {0x33, 0, _image575_size, 0, 0, 0, 0},
    {0x33, 0, _image576_size, 0, 0, 0, 0},
    {0x22, 0, _image577_size, 0, 0, 0, 0},
    {0x33, 0, _image578_size, 0, 0, 0, 0},
    {0x33, 0, _image579_size, 0, 0, 0, 0},
    {0x33, 0, _image580_size, 0, 0, 0, 0},
    {0x33, 0, _image581_size, 0, 0, 0, 0},
    {0, 0, _image582_size, 0, 0, 0, 0},
    {0, 0, _image583_size, 0, 0, 0, 0},
    {0, 0, _image584_size, 0, 0, 0, 0},
    {0, 0, _image585_size, 0, 0, 0, 0},
    {0, 0, _image586_size, 0, 0, 0, 0},
    {0, 0, _image587_size, 0, 0, 0, 0},
    {0, 0, _image588_size, 0, 0, 0, 0},
    {0x77, 0, _image589_size, 0, 0, 0, 0},
    {0x77, 0, _image590_size, 0, 0, 0, 0},
    {0x77, 0, _image591_size, 0, 0, 0, 0},
    {0x77, 0, _image592_size, 0, 0, 0, 0},
    {0x77, 0, _image593_size, 0, 0, 0, 0},
    {0x77, 0, _image594_size, 0, 0, 0, 0},
    {0x77, 0, _image595_size, 0, 0, 0, 0},
    {0x77, 0, _image596_size, 0, 0, 0, 0},
    {0, 0, _image597_size, 0, 0, 0, 0},
    {0, 0, _image598_size, 0, 0, 0, 0},
    {0, 0, _image599_size, 0, 0, 0, 0},
    {0, 0, _image600_size, 0, 0, 0, 0},
    {0, 0, _image601_size, 0, 0, 0, 0},
    {0, 0, _image602_size, 0, 0, 0, 0},
    {0, 0, _image603_size, 0, 0, 0, 0},
    {0, 0, _image604_size, 0, 0, 0, 0},
    {0, 0, _image605_size, 0, 0, 0, 0},
    {0, 0, _image606_size, 0, 0, 0, 0},
    {0, 0, _image607_size, 0, 0, 0, 0},
    {0, 0, _image608_size, 0, 0, 0, 0},
    {0, 0, _image609_size, 0, 0, 0, 0},
    {0, 0, _image610_size, 0, 0, 0, 0},
    {0, 0, _image611_size, 0, 0, 0, 0},
    {0, 0, _image612_size, 0, 0, 0, 0},
    {0x33, 0, _image613_size, 0, 0, 0, 0},
    {0x33, 0, _image614_size, 0, 0, 0, 0},
    {0x33, 0, _image615_size, 0, 0, 0, 0},
    {0x33, 0, _image616_size, 0, 0, 0, 0},
    {0x33, 0, _image617_size, 0, 0, 0, 0},
    {0, 0, _image618_size, 0, 0, 0, 0},
    {0, 0, _image619_size, 0, 0, 0, 0},
    {0x22, 0, _image620_size, 0, 0, 0, 0},
    {0x33, 0, _image621_size, 0, 0, 0, 0},
    {0x33, 0, _image622_size, 0, 0, 0, 0},
    {0x33, 0, _image623_size, 0, 0, 0, 0},
    {0, 0, _image624_size, 0, 0, 0, 0},
    {0, 0, _image625_size, 0, 0, 0, 0},
    {0, 0, _image626_size, 0, 0, 0, 0},
    {0, 0, _image627_size, 0, 0, 0, 0},
    {0, 0, _image628_size, 0, 0, 0, 0},
    {0, 0, _image629_size, 0, 0, 0, 0},
    {0, 0, _image630_size, 0, 0, 0, 0},
    {0, 0, _image631_size, 0, 0, 0, 0},
    {0x99, 0, _image632_size, 0, 0, 0, 0},
    {0x99, 0, _image633_size, 0, 0, 0, 0},
    {0, 0, _image634_size, 0, 0, 0, 0},
    {0, 0, _image635_size, 0, 0, 0, 0},
    {0, 0, _image636_size, 0, 0, 0, 0},
    {0, 0, _image637_size, 0, 0, 0, 0},
    {0, 0, _image638_size, 0, 0, 0, 0},
    {0, 0, _image639_size, 0, 0, 0, 0},
    {0, 0, _image640_size, 0, 0, 0, 0},
    {0, 0, _image641_size, 0, 0, 0, 0},
    {0, 0, _image642_size, 0, 0, 0, 0},
    {0, 0, _image643_size, 0, 0, 0, 0},
    {0x33, 0, _image644_size, 0, 0, 0, 0},
    {0x33, 0, _image645_size, 0, 0, 0, 0},
    {0x33, 0, _image646_size, 0, 0, 0, 0},
    {0, 0, _image647_size, 0, 0, 0, 0},
    {0x33, 0, _image648_size, 0, 0, 0, 0},
    {0, 0, _image649_size, 0, 0, 0, 0},
    {0, 0, _image650_size, 0, 0, 0, 0},
    {0, 0, _image651_size, 0, 0, 0, 0},
    {0x33, 0, _image652_size, 0, 0, 0, 0},
    {0x44, 0, _image653_size, 0, 0, 0, 0},
    {0x4C, 0, _image654_size, 0, 0, 0, 0},
    {0x4C, 0, _image655_size, 0, 0, 0, 0},
    {0x4C, 0, _image656_size, 0, 0, 0, 0},
    {0x44, 0, _image657_size, 0, 0, 0, 0},
    {0x44, 0, _image658_size, 0, 0, 0, 0},
    {0x44, 0, _image659_size, 0, 0, 0, 0},
    {0, 0, _image660_size, 0, 0, 0, 0},
    {0, 0, _image661_size, 0, 0, 0, 0},
    {0, 0, _image662_size, 0, 0, 0, 0},
    {0, 0, _image663_size, 0, 0, 0, 0},
    {0, 0, _image664_size, 0, 0, 0, 0},
    {0, 0, _image665_size, 0, 0, 0, 0},
    {0, 0, _image666_size, 0, 0, 0, 0},
    {0, 0, _image667_size, 0, 0, 0, 0},
    {0, 0, _image668_size, 0, 0, 0, 0},
    {0, 0, _image669_size, 0, 0, 0, 0},
    {0, 0, _image670_size, 0, 0, 0, 0},
    {0, 0, _image671_size, 0, 0, 0, 0},
    {0x33, 0, _image672_size, 0, 0, 0, 0},
    {0x33, 0, _image673_size, 0, 0, 0, 0},
    {0x33, 0, _image674_size, 0, 0, 0, 0},
    {0x33, 0, _image675_size, 0, 0, 0, 0},
    {0x11, 0, _image676_size, 0, 0, 0, 0},
    {0x11, 0, _image677_size, 0, 0, 0, 0},
    {0, 0, _image678_size, 0, 0, 0, 0},
    {0x22, 0, _image679_size, 0, 0, 0, 0},
    {0x33, 0, _image680_size, 0, 0, 0, 0},
    {0x33, 0, _image681_size, 0, 0, 0, 0},
    {0x33, 0, _image682_size, 0, 0, 0, 0},
    {0x33, 0, _image683_size, 0, 0, 0, 0},
    {0x33, 0, _image684_size, 0, 0, 0, 0},
    {0x33, 0, _image685_size, 0, 0, 0, 0},
    {0x33, 0, _image686_size, 0, 0, 0, 0},
    {0x33, 0, _image687_size, 0, 0, 0, 0},
    {0x33, 0, _image688_size, 0, 0, 0, 0},
    {0x33, 0, _image689_size, 0, 0, 0, 0},
    {0, 0, _image690_size, 0, 0, 0, 0},
    {0, 0, _image691_size, 0, 0, 0, 0},
    {0, 0, _image692_size, 0, 0, 0, 0},
    {0xAA, 0, _image693_size, 0, 0, 0, 0},
    {0x44, 0, _image694_size, 0, 0, 0, 0},
    {0, 0, _image695_size, 0, 0, 0, 0},
    {0x99, 0, _image696_size, 0, 0, 0, 0},
    {0x99, 0, _image697_size, 0, 0, 0, 0},
    {0x77, 0, _image698_size, 0, 0, 0, 0},
    {0x99, 0, _image699_size, 0, 0, 0, 0},
    {0x99, 0, _image700_size, 0, 0, 0, 0},
    {0x33, 0, _image701_size, 0, 0, 0, 0},
    {0x33, 0, _image702_size, 0, 0, 0, 0},
    {0xAA, 0, _image703_size, 0, 0, 0, 0},
    {0xAA, 0, _image704_size, 0, 0, 0, 0},
    {0xAA, 0, _image705_size, 0, 0, 0, 0},
    {0x33, 0, _image706_size, 0, 0, 0, 0},
    {0x33, 0, _image707_size, 0, 0, 0, 0},
    {0x33, 0, _image708_size, 0, 0, 0, 0},
    {0x33, 0, _image709_size, 0, 0, 0, 0},
    {0x33, 0, _image710_size, 0, 0, 0, 0},
    {0x33, 0, _image711_size, 0, 0, 0, 0},
    {0x33, 0, _image712_size, 0, 0, 0, 0},
    {0, 0, _image713_size, 0, 0, 0, 0},
    {0, 0, _image714_size, 0, 0, 0, 0},
    {0, 0, _image715_size, 0, 0, 0, 0},
    {0x33, 0, _image716_size, 0, 0, 0, 0},
    {0x33, 0, _image717_size, 0, 0, 0, 0},
    {0x33, 0, _image718_size, 0, 0, 0, 0},
    {0x99, 0, _image719_size, 0, 0, 0, 0},
    {0x99, 0, _image720_size, 0, 0, 0, 0},
    {0x11, 0, _image721_size, 0, 0, 0, 0},
    {0x11, 0, _image722_size, 0, 0, 0, 0},
    {0, 0, _image723_size, 0, 0, 0, 0},
    {0x11, 0, _image724_size, 0, 0, 0, 0},
    {0x11, 0, _image725_size, 0, 0, 0, 0},
    {0x11, 0, _image726_size, 0, 0, 0, 0},
    {0xAA, 0, _image727_size, 0, 0, 0, 0},
    {0xAA, 0, _image728_size, 0, 0, 0, 0},
    {0xAA, 0, _image729_size, 0, 0, 0, 0},
    {0xAA, 0, _image730_size, 0, 0, 0, 0},
    {0xAA, 0, _image731_size, 0, 0, 0, 0},
    {0xAA, 0, _image732_size, 0, 0, 0, 0},
    {0, 0, _image733_size, 0, 0, 0, 0},
    {0, 0, _image734_size, 0, 0, 0, 0},
    {0, 0, _image735_size, 0, 0, 0, 0},
    {0, 0, _image736_size, 0, 0, 0, 0},
    {0, 0, _image737_size, 0, 0, 0, 0},
    {0, 0, _image738_size, 0, 0, 0, 0},
    {0, 0, _image739_size, 0, 0, 0, 0},
    {0, 0, _image740_size, 0, 0, 0, 0},
    {0, 0, _image741_size, 0, 0, 0, 0},
    {0, 0, _image742_size, 0, 0, 0, 0},
    {0, 0, _image743_size, 0, 0, 0, 0},
    {0, 0, _image744_size, 0, 0, 0, 0},
    {0, 0, _image745_size, 0, 0, 0, 0},
    {0, 0, _image746_size, 0, 0, 0, 0},
    {0, 0, _image747_size, 0, 0, 0, 0},
    {0, 0, _image748_size, 0, 0, 0, 0},
    {0, 0, _image749_size, 0, 0, 0, 0},
    {0, 0, _image750_size, 0, 0, 0, 0},
    {0, 0, _image751_size, 0, 0, 0, 0},
    {0, 0, _image752_size, 0, 0, 0, 0},
    {0, 0, _image753_size, 0, 0, 0, 0},
    {0, 0, _image754_size, 0, 0, 0, 0},
    {0, 0, _image755_size, 0, 0, 0, 0},
    {0, 0, _image756_size, 0, 0, 0, 0},
    {0, 0, _image757_size, 0, 0, 0, 0},
    {0, 0, _image758_size, 0, 0, 0, 0},
    {0, 0, _image759_size, 0, 0, 0, 0},
    {0, 0, _image760_size, 0, 0, 0, 0},
    {0x77, 0, _image761_size, 0, 0, 0, 0},
    {0x77, 0, _image762_size, 0, 0, 0, 0},
    {0, 0, _image763_size, 0, 0, 0, 0},
    {0, 0, _image764_size, 0, 0, 0, 0},
    {0, 0, _image765_size, 0, 0, 0, 0},
    {0, 0, _image766_size, 0, 0, 0, 0},
    {0, 0, _image767_size, 0, 0, 0, 0},
    {0, 0, _image768_size, 0, 0, 0, 0},
    {0, 0, _image769_size, 0, 0, 0, 0},
    {0, 0, _image770_size, 0, 0, 0, 0},
    {0, 0, _image771_size, 0, 0, 0, 0},
    {0, 0, _image772_size, 0, 0, 0, 0},
    {0xAA, 0, _image773_size, 0, 0, 0, 0},
    {0xAA, 0, _image774_size, 0, 0, 0, 0},
    {0xAA, 0, _image775_size, 0, 0, 0, 0},
    {0x88, 0, _image776_size, 0, 0, 0, 0},
    {0, 0, _image777_size, 0, 0, 0, 0},
    {0x11, 0, _image778_size, 0, 0, 0, 0},
    {0, 0, _image779_size, 0, 0, 0, 0},
    {0, 0, _image780_size, 0, 0, 0, 0},
    {0, 0, _image781_size, 0, 0, 0, 0},
    {0, 0, _image782_size, 0, 0, 0, 0},
    {0, 0, _image783_size, 0, 0, 0, 0},
    {0x77, 0, _image784_size, 0, 0, 0, 0},
    {0, 0, _image785_size, 0, 0, 0, 0},
    {0, 0, _image786_size, 0, 0, 0, 0},
    {0, 0, _image787_size, 0, 0, 0, 0},
    {0xAA, 0, _image788_size, 0, 0, 0, 0},
    {0, 0, _image789_size, 0, 0, 0, 0},
    {0, 0, _image790_size, 0, 0, 0, 0},
    {0, 0, _image791_size, 0, 0, 0, 0},
    {0, 0, _image792_size, 0, 0, 0, 0},
    {0, 0, _image793_size, 0, 0, 0, 0},
    {0, 0, _image794_size, 0, 0, 0, 0},
    {0, 0, _image795_size, 0, 0, 0, 0},
    {0, 0, _image796_size, 0, 0, 0, 0},
    {0x33, 0, _image797_size, 0, 0, 0, 0},
    {0x33, 0, _image798_size, 0, 0, 0, 0},
    {0x33, 0, _image799_size, 0, 0, 0, 0},
    {0x33, 0, _image800_size, 0, 0, 0, 0},
    {0x33, 0, _image801_size, 0, 0, 0, 0},
    {0x33, 0, _image802_size, 0, 0, 0, 0},
    {0x33, 0, _image803_size, 0, 0, 0, 0},
    {0x33, 0, _image804_size, 0, 0, 0, 0},
    {0, 0, _image805_size, 0, 0, 0, 0},
    {0xAA, 0, _image806_size, 0, 0, 0, 0},
    {0, 0, _image807_size, 0, 0, 0, 0},
    {0, 0, _image808_size, 0, 0, 0, 0},
    {0x44, 0, _image809_size, 0, 0, 0, 0},
    {0x44, 0, _image810_size, 0, 0, 0, 0},
    {0x44, 0, _image811_size, 0, 0, 0, 0},
    {0, 0, _image812_size, 0, 0, 0, 0},
    {0, 0, _image813_size, 0, 0, 0, 0},
    {0, 0, _image814_size, 0, 0, 0, 0},
    {0, 0, _image815_size, 0, 0, 0, 0},
    {0, 0, _image816_size, 0, 0, 0, 0},
    {0, 0, _image817_size, 0, 0, 0, 0},
    {0x33, 0, _image818_size, 0, 0, 0, 0},
    {0xAA, 0, _image819_size, 0, 0, 0, 0},
    {0x33, 0, _image820_size, 0, 0, 0, 0},
    {0x33, 0, _image821_size, 0, 0, 0, 0},
    {0, 0, _image822_size, 0, 0, 0, 0},
    {0, 0, _image823_size, 0, 0, 0, 0},
    {0, 0, _image824_size, 0, 0, 0, 0},
    {0, 0, _image825_size, 0, 0, 0, 0},
    {0, 0, _image826_size, 0, 0, 0, 0},
    {0, 0, _image827_size, 0, 0, 0, 0},
    {0, 0, _image828_size, 0, 0, 0, 0},
    {0, 0, _image829_size, 0, 0, 0, 0},
    {0, 0, _image830_size, 0, 0, 0, 0},
    {0, 0, _image831_size, 0, 0, 0, 0},
    {0, 0, _image832_size, 0, 0, 0, 0},
    {0, 0, _image833_size, 0, 0, 0, 0},
    {0, 0, _image834_size, 0, 0, 0, 0},
    {0, 0, _image835_size, 0, 0, 0, 0},
    {0, 0, _image836_size, 0, 0, 0, 0},
    {0xAA, 0, _image837_size, 0, 0, 0, 0},
    {0, 0, _image838_size, 0, 0, 0, 0},
    {0, 0, _image839_size, 0, 0, 0, 0},
    {0, 0, _image840_size, 0, 0, 0, 0},
    {0, 0, _image841_size, 0, 0, 0, 0},
    {0, 0, _image842_size, 0, 0, 0, 0},
    {0xAA, 0, _image843_size, 0, 0, 0, 0},
    {0xAA, 0, _image844_size, 0, 0, 0, 0},
    {0xAA, 0, _image845_size, 0, 0, 0, 0},
    {0x33, 0, _image846_size, 0, 0, 0, 0},
    {0x33, 0, _image847_size, 0, 0, 0, 0},
    {0x33, 0, _image848_size, 0, 0, 0, 0},
    {0x33, 0, _image849_size, 0, 0, 0, 0},
    {0, 0, _image850_size, 0, 0, 0, 0},
    {0, 0, _image851_size, 0, 0, 0, 0},
    {0, 0, _image852_size, 0, 0, 0, 0},
    {0, 0, _image853_size, 0, 0, 0, 0},
    {0, 0, _image854_size, 0, 0, 0, 0},
    {0, 0, _image855_size, 0, 0, 0, 0},
    {0, 0, _image856_size, 0, 0, 0, 0},
    {0x44, 0, _image857_size, 0, 0, 0, 0},
    {0xAA, 0, _image858_size, 0, 0, 0, 0},
    {0xAA, 0, _image859_size, 0, 0, 0, 0},
    {0x33, 0, _image860_size, 0, 0, 0, 0},
    {0x33, 0, _image861_size, 0, 0, 0, 0},
    {0x33, 0, _image862_size, 0, 0, 0, 0},
    {0x33, 0, _image863_size, 0, 0, 0, 0},
    {0, 0, _image864_size, 0, 0, 0, 0},
    {0x44, 0, _image865_size, 0, 0, 0, 0},
    {0x44, 0, _image866_size, 0, 0, 0, 0},
    {0x22, 0, _image867_size, 0, 0, 0, 0},
    {0x99, 0, _image868_size, 0, 0, 0, 0},
    {0x99, 0, _image869_size, 0, 0, 0, 0},
    {0xAA, 0, _image870_size, 0, 0, 0, 0},
    {0, 0, _image871_size, 0, 0, 0, 0},
    {0, 0, _image872_size, 0, 0, 0, 0},
    {0, 0, _image873_size, 0, 0, 0, 0},
    {0, 0, _image874_size, 0, 0, 0, 0},
    {0, 0, _image875_size, 0, 0, 0, 0},
    {0, 0, _image876_size, 0, 0, 0, 0},
    {0, 0, _image877_size, 0, 0, 0, 0},
    {0, 0, _image878_size, 0, 0, 0, 0},
    {0, 0, _image879_size, 0, 0, 0, 0},
    {0, 0, _image880_size, 0, 0, 0, 0},
    {0, 0, _image881_size, 0, 0, 0, 0},
    {0, 0, _image882_size, 0, 0, 0, 0},
    {0, 0, _image883_size, 0, 0, 0, 0},
    {0, 0, _image884_size, 0, 0, 0, 0},
    {0, 0, _image885_size, 0, 0, 0, 0},
    {0, 0, _image886_size, 0, 0, 0, 0},
    {0, 0, _image887_size, 0, 0, 0, 0},
    {0, 0, _image888_size, 0, 0, 0, 0},
    {0x33, 0, _image889_size, 0, 0, 0, 0},
    {0xAA, 0, _image890_size, 0, 0, 0, 0},
    {0xAA, 0, _image891_size, 0, 0, 0, 0},
    {0xAA, 0, _image892_size, 0, 0, 0, 0},
    {0xAA, 0, _image893_size, 0, 0, 0, 0},
    {0xAA, 0, _image894_size, 0, 0, 0, 0},
    {0xAA, 0, _image895_size, 0, 0, 0, 0},
    {0, 0, _image896_size, 0, 0, 0, 0},
    {0, 0, _image897_size, 0, 0, 0, 0},
    {0, 0, _image898_size, 0, 0, 0, 0},
    {0, 0, _image899_size, 0, 0, 0, 0},
    {0, 0, _image900_size, 0, 0, 0, 0},
    {0x99, 0, _image901_size, 0, 0, 0, 0},
    {0x99, 0, _image902_size, 0, 0, 0, 0},
    {0x99, 0, _image903_size, 0, 0, 0, 0},
    {0x99, 0, _image904_size, 0, 0, 0, 0},
    {0, 0, _image905_size, 0, 0, 0, 0},
    {0, 0, _image906_size, 0, 0, 0, 0},
    {0, 0, _image907_size, 0, 0, 0, 0},
    {0, 0, _image908_size, 0, 0, 0, 0},
    {0, 0, _image909_size, 0, 0, 0, 0},
    {0x33, 0, _image910_size, 0, 0, 0, 0},
    {0x33, 0, _image911_size, 0, 0, 0, 0},
    {0x33, 0, _image912_size, 0, 0, 0, 0},
    {0x33, 0, _image913_size, 0, 0, 0, 0},
    {0x33, 0, _image914_size, 0, 0, 0, 0},
    {0x33, 0, _image915_size, 0, 0, 0, 0},
    {0x33, 0, _image916_size, 0, 0, 0, 0},
    {0x33, 0, _image917_size, 0, 0, 0, 0},
    {0x33, 0, _image918_size, 0, 0, 0, 0},
    {0x33, 0, _image919_size, 0, 0, 0, 0},
    {0xAA, 0, _image920_size, 0, 0, 0, 0},
    {0x33, 0, _image921_size, 0, 0, 0, 0},
    {0x33, 0, _image922_size, 0, 0, 0, 0},
    {0x33, 0, _image923_size, 0, 0, 0, 0},
    {0x33, 0, _image924_size, 0, 0, 0, 0},
    {0, 0, _image925_size, 0, 0, 0, 0},
    {0, 0, _image926_size, 0, 0, 0, 0},
    {0, 0, _image927_size, 0, 0, 0, 0},
    {0, 0, _image928_size, 0, 0, 0, 0},
    {0, 0, _image929_size, 0, 0, 0, 0},
    {0, 0, _image930_size, 0, 0, 0, 0},
    {0, 0, _image931_size, 0, 0, 0, 0},
    {0, 0, _image932_size, 0, 0, 0, 0},
    {0, 0, _image933_size, 0, 0, 0, 0},
    {0, 0, _image934_size, 0, 0, 0, 0},
    {0, 0, _image935_size, 0, 0, 0, 0},
    {0, 0, _image936_size, 0, 0, 0, 0},
    {0, 0, _image937_size, 0, 0, 0, 0},
    {0, 0, _image938_size, 0, 0, 0, 0},
    {0, 0, _image939_size, 0, 0, 0, 0},
    {0, 0, _image940_size, 0, 0, 0, 0},
    {0, 0, _image941_size, 0, 0, 0, 0},
    {0, 0, _image942_size, 0, 0, 0, 0},
    {0, 0, _image943_size, 0, 0, 0, 0},
    {0, 0, _image944_size, 0, 0, 0, 0},
    {0, 0, _image945_size, 0, 0, 0, 0},
    {0, 0, _image946_size, 0, 0, 0, 0},
    {0, 0, _image947_size, 0, 0, 0, 0},
    {0, 0, _image948_size, 0, 0, 0, 0},
    {0, 0, _image949_size, 0, 0, 0, 0},
    {0, 0, _image950_size, 0, 0, 0, 0},
    {0, 0, _image951_size, 0, 0, 0, 0},
    {0, 0, _image952_size, 0, 0, 0, 0},
    {0, 0, _image953_size, 0, 0, 0, 0},
    {0, 0, _image954_size, 0, 0, 0, 0},
    {0, 0, _image955_size, 0, 0, 0, 0},
    {0, 0, _image956_size, 0, 0, 0, 0},
    {0, 0, _image957_size, 0, 0, 0, 0},
    {0, 0, _image958_size, 0, 0, 0, 0},
    {0, 0, _image959_size, 0, 0, 0, 0},
    {0x77, 0, _image960_size, 0, 0, 0, 0},
    {0x77, 0, _image961_size, 0, 0, 0, 0},
    {0x11, 0, _image962_size, 0, 0, 0, 0},
    {0x11, 0, _image963_size, 0, 0, 0, 0},
    {0x11, 0, _image964_size, 0, 0, 0, 0},
    {0x11, 0, _image965_size, 0, 0, 0, 0},
    {0x11, 0, _image966_size, 0, 0, 0, 0},
    {0x11, 0, _image967_size, 0, 0, 0, 0},
    {0x11, 0, _image968_size, 0, 0, 0, 0},
    {0x11, 0, _image969_size, 0, 0, 0, 0},
    {0x77, 0, _image970_size, 0, 0, 0, 0},
    {0x77, 0, _image971_size, 0, 0, 0, 0},
    {0x77, 0, _image972_size, 0, 0, 0, 0},
    {0x77, 0, _image973_size, 0, 0, 0, 0},
    {0x77, 0, _image974_size, 0, 0, 0, 0},
    {0x77, 0, _image975_size, 0, 0, 0, 0},
    {0x77, 0, _image976_size, 0, 0, 0, 0},
    {0x77, 0, _image977_size, 0, 0, 0, 0},
    {0x77, 0, _image978_size, 0, 0, 0, 0},
    {0x77, 0, _image979_size, 0, 0, 0, 0},
    {0x77, 0, _image980_size, 0, 0, 0, 0},
    {0x77, 0, _image981_size, 0, 0, 0, 0},
    {0x77, 0, _image982_size, 0, 0, 0, 0},
    {0, 0, _image983_size, 0, 0, 0, 0},
    {0xAA, 0, _image984_size, 0, 0, 0, 0},
    {0xAA, 0, _image985_size, 0, 0, 0, 0},
    {0, 0, _image986_size, 0, 0, 0, 0},
    {0, 0, _image987_size, 0, 0, 0, 0},
    {0, 0, _image988_size, 0, 0, 0, 0},
    {0, 0, _image989_size, 0, 0, 0, 0},
    {0, 0, _image990_size, 0, 0, 0, 0},
    {0, 0, _image991_size, 0, 0, 0, 0},
    {0, 0, _image992_size, 0, 0, 0, 0},
    {0, 0, _image993_size, 0, 0, 0, 0},
    {0, 0, _image994_size, 0, 0, 0, 0},
    {0, 0, _image995_size, 0, 0, 0, 0},
    {0, 0, _image996_size, 0, 0, 0, 0},
    {0, 0, _image997_size, 0, 0, 0, 0},
    {0, 0, _image998_size, 0, 0, 0, 0},
    {0, 0, _image999_size, 0, 0, 0, 0},
    {0x33, 0, _image1000_size, 0, 0, 0, 0},
    {0x33, 0, _image1001_size, 0, 0, 0, 0},
    {0x33, 0, _image1002_size, 0, 0, 0, 0},
    {0x33, 0, _image1003_size, 0, 0, 0, 0},
    {0x33, 0, _image1004_size, 0, 0, 0, 0},
    {0, 0, _image1005_size, 0, 0, 0, 0},
    {0, 0, _image1006_size, 0, 0, 0, 0},
    {0, 0, _image1007_size, 0, 0, 0, 0},
    {0, 0, _image1008_size, 0, 0, 0, 0},
    {0, 0, _image1009_size, 0, 0, 0, 0},
    {0x77, 0, _image1010_size, 0, 0, 0, 0},
    {0x77, 0, _image1011_size, 0, 0, 0, 0},
    {0xAA, 0, _image1012_size, 0, 0, 0, 0},
    {0xAA, 0, _image1013_size, 0, 0, 0, 0},
    {0xAA, 0, _image1014_size, 0, 0, 0, 0},
    {0, 0, _image1015_size, 0, 0, 0, 0},
    {0, 0, _image1016_size, 0, 0, 0, 0},
    {0x33, 0, _image1017_size, 0, 0, 0, 0},
    {0x33, 0, _image1018_size, 0, 0, 0, 0},
    {0x33, 0, _image1019_size, 0, 0, 0, 0},
    {0x77, 0, _image1020_size, 0, 0, 0, 0},
    {0, 0, _image1021_size, 0, 0, 0, 0},
    {0xAA, 0, _image1022_size, 0, 0, 0, 0},
    {0x11, 0, _image1023_size, 0, 0, 0, 0},
    {0x22, 0, _image1024_size, 0, 0, 0, 0},
    {0x22, 0, _image1025_size, 0, 0, 0, 0},
    {0, 0, _image1026_size, 0, 0, 0, 0},
    {0xAA, 0, _image1027_size, 0, 0, 0, 0},
    {0, 0, _image1028_size, 0, 0, 0, 0},
    {0, 0, _image1029_size, 0, 0, 0, 0},
    {0, 0, _image1030_size, 0, 0, 0, 0},
    {0, 0, _image1031_size, 0, 0, 0, 0},
    {0xAA, 0, _image1032_size, 0, 0, 0, 0},
    {0, 0, _image1033_size, 0, 0, 0, 0},
    {0, 0, _image1034_size, 0, 0, 0, 0},
    {0, 0, _image1035_size, 0, 0, 0, 0},
    {0, 0, _image1036_size, 0, 0, 0, 0},
    {0, 0, _image1037_size, 0, 0, 0, 0},
    {0, 0, _image1038_size, 0, 0, 0, 0},
    {0, 0, _image1039_size, 0, 0, 0, 0},
    {0, 0, _image1040_size, 0, 0, 0, 0},
    {0, 0, _image1041_size, 0, 0, 0, 0},
    {0, 0, _image1042_size, 0, 0, 0, 0},
    {0, 0, _image1043_size, 0, 0, 0, 0},
    {0, 0, _image1044_size, 0, 0, 0, 0},
    {0, 0, _image1045_size, 0, 0, 0, 0},
    {0, 0, _image1046_size, 0, 0, 0, 0},
    {0, 0, _image1047_size, 0, 0, 0, 0},
    {0, 0, _image1048_size, 0, 0, 0, 0},
    {0x11, 0, _image1049_size, 0, 0, 0, 0},
    {0, 0, _image1050_size, 0, 0, 0, 0},
    {0, 0, _image1051_size, 0, 0, 0, 0},
    {0, 0, _image1052_size, 0, 0, 0, 0},
    {0, 0, _image1053_size, 0, 0, 0, 0},
    {0, 0, _image1054_size, 0, 0, 0, 0},
    {0, 0, _image1055_size, 0, 0, 0, 0},
    {0, 0, _image1056_size, 0, 0, 0, 0},
    {0, 0, _image1057_size, 0, 0, 0, 0},
    {0, 0, _image1058_size, 0, 0, 0, 0},
    {0, 0, _image1059_size, 0, 0, 0, 0},
    {0, 0, _image1060_size, 0, 0, 0, 0},
    {0, 0, _image1061_size, 0, 0, 0, 0},
    {0, 0, _image1062_size, 0, 0, 0, 0},
    {0xAA, 0, _image1063_size, 0, 0, 0, 0},
    {0xAA, 0, _image1064_size, 0, 0, 0, 0},
    {0xAA, 0, _image1065_size, 0, 0, 0, 0},
    {0xAA, 0, _image1066_size, 0, 0, 0, 0},
    {0, 0, _image1067_size, 0, 0, 0, 0},
    {0, 0, _image1068_size, 0, 0, 0, 0},
    {0xAA, 0, _image1069_size, 0, 0, 0, 0},
    {0xAA, 0, _image1070_size, 0, 0, 0, 0},
    {0xAA, 0, _image1071_size, 0, 0, 0, 0},
    {0xAA, 0, _image1072_size, 0, 0, 0, 0},
    {0xAA, 0, _image1073_size, 0, 0, 0, 0},
    {0xAA, 0, _image1074_size, 0, 0, 0, 0},
    {0xAA, 0, _image1075_size, 0, 0, 0, 0},
    {0xAA, 0, _image1076_size, 0, 0, 0, 0},
    {0xAA, 0, _image1077_size, 0, 0, 0, 0},
    {0x44, 0, _image1078_size, 0, 0, 0, 0},
    {0, 0, _image1079_size, 0, 0, 0, 0},
    {0, 0, _image1080_size, 0, 0, 0, 0},
    {0xAA, 0, _image1081_size, 0, 0, 0, 0},
    {0xAA, 0, _image1082_size, 0, 0, 0, 0},
    {0xAA, 0, _image1083_size, 0, 0, 0, 0},
    {0, 0, _image1084_size, 0, 0, 0, 0},
    {0, 0, _image1085_size, 0, 0, 0, 0},
    {0, 0, _image1086_size, 0, 0, 0, 0},
    {0, 0, _image1087_size, 0, 0, 0, 0},
    {0, 0, _image1088_size, 0, 0, 0, 0},
    {0, 0, _image1089_size, 0, 0, 0, 0},
    {0, 0, _image1090_size, 0, 0, 0, 0},
    {0xAA, 0, _image1091_size, 0, 0, 0, 0},
    {0x33, 0, _image1092_size, 0, 0, 0, 0},
    {0x33, 0, _image1093_size, 0, 0, 0, 0},
    {0x33, 0, _image1094_size, 0, 0, 0, 0},
    {0x33, 0, _image1095_size, 0, 0, 0, 0},
    {0x33, 0, _image1096_size, 0, 0, 0, 0},
    {0x33, 0, _image1097_size, 0, 0, 0, 0},
    {0x33, 0, _image1098_size, 0, 0, 0, 0},
    {0x33, 0, _image1099_size, 0, 0, 0, 0},
    {0x33, 0, _image1100_size, 0, 0, 0, 0},
    {0x33, 0, _image1101_size, 0, 0, 0, 0},
    {0x33, 0, _image1102_size, 0, 0, 0, 0},
    {0, 0, _image1103_size, 0, 0, 0, 0},
    {0, 0, _image1104_size, 0, 0, 0, 0},
    {0, 0, _image1105_size, 0, 0, 0, 0},
    {0, 0, _image1106_size, 0, 0, 0, 0},
    {0, 0, _image1107_size, 0, 0, 0, 0},
    {0, 0, _image1108_size, 0, 0, 0, 0},
    {0, 0, _image1109_size, 0, 0, 0, 0},
    {0, 0, _image1110_size, 0, 0, 0, 0},
    {0, 0, _image1111_size, 0, 0, 0, 0},
    {0, 0, _image1112_size, 0, 0, 0, 0},
    {0, 0, _image1113_size, 0, 0, 0, 0},
    {0, 0, _image1114_size, 0, 0, 0, 0},
    {0, 0, _image1115_size, 0, 0, 0, 0},
    {0, 0, _image1116_size, 0, 0, 0, 0},
    {0x33, 0, _image1117_size, 0, 0, 0, 0},
    {0x33, 0, _image1118_size, 0, 0, 0, 0},
    {0, 0, _image1119_size, 0, 0, 0, 0},
    {0x77, 0, _image1120_size, 0, 0, 0, 0},
    {0x77, 0, _image1121_size, 0, 0, 0, 0},
    {0x77, 0, _image1122_size, 0, 0, 0, 0},
    {0x77, 0, _image1123_size, 0, 0, 0, 0},
    {0x77, 0, _image1124_size, 0, 0, 0, 0},
    {0x77, 0, _image1125_size, 0, 0, 0, 0},
    {0, 0, _image1126_size, 0, 0, 0, 0},
    {0, 0, _image1127_size, 0, 0, 0, 0},
    {0x77, 0, _image1128_size, 0, 0, 0, 0},
    {0x11, 0, _image1129_size, 0, 0, 0, 0},
    {0x11, 0, _image1130_size, 0, 0, 0, 0},
    {0, 0, _image1131_size, 0, 0, 0, 0},
    {0, 0, _image1132_size, 0, 0, 0, 0},
    {0, 0, _image1133_size, 0, 0, 0, 0},
    {0x11, 0, _image1134_size, 0, 0, 0, 0},
    {0x11, 0, _image1135_size, 0, 0, 0, 0},
    {0x22, 0, _image1136_size, 0, 0, 0, 0},
    {0x22, 0, _image1137_size, 0, 0, 0, 0},
    {0x22, 0, _image1138_size, 0, 0, 0, 0},
    {0x33, 0, _image1139_size, 0, 0, 0, 0},
    {0x33, 0, _image1140_size, 0, 0, 0, 0},
    {0x33, 0, _image1141_size, 0, 0, 0, 0},
    {0, 0, _image1142_size, 0, 0, 0, 0},
    {0, 0, _image1143_size, 0, 0, 0, 0},
    {0, 0, _image1144_size, 0, 0, 0, 0},
    {0, 0, _image1145_size, 0, 0, 0, 0},
    {0, 0, _image1146_size, 0, 0, 0, 0},
    {0x77, 0, _image1147_size, 0, 0, 0, 0},
    {0, 0, _image1148_size, 0, 0, 0, 0},
    {0, 0, _image1149_size, 0, 0, 0, 0},
    {0, 0, _image1150_size, 0, 0, 0, 0},
    {0x33, 0, _image1151_size, 0, 0, 0, 0},
    {0x33, 0, _image1152_size, 0, 0, 0, 0},
    {0x33, 0, _image1153_size, 0, 0, 0, 0},
    {0, 0, _image1154_size, 0, 0, 0, 0},
    {0, 0, _image1155_size, 0, 0, 0, 0},
    {0x77, 0, _image1156_size, 0, 0, 0, 0},
    {0xAA, 0, _image1157_size, 0, 0, 0, 0},
    {0x66, 0, _image1158_size, 0, 0, 0, 0},
    {0xAA, 0, _image1159_size, 0, 0, 0, 0},
    {0xAA, 0, _image1160_size, 0, 0, 0, 0},
    {0xAA, 0, _image1161_size, 0, 0, 0, 0},
    {0xAA, 0, _image1162_size, 0, 0, 0, 0},
    {0xAA, 0, _image1163_size, 0, 0, 0, 0},
    {0xAA, 0, _image1164_size, 0, 0, 0, 0},
    {0xAA, 0, _image1165_size, 0, 0, 0, 0},
    {0, 0, _image1166_size, 0, 0, 0, 0},
    {0xAA, 0, _image1167_size, 0, 0, 0, 0},
    {0xAA, 0, _image1168_size, 0, 0, 0, 0},
    {0xAA, 0, _image1169_size, 0, 0, 0, 0},
    {0, 0, _image1170_size, 0, 0, 0, 0},
    {0xAA, 0, _image1171_size, 0, 0, 0, 0},
    {0xAA, 0, _image1172_size, 0, 0, 0, 0},
    {0, 0, _image1173_size, 0, 0, 0, 0},
    {0x11, 0, _image1174_size, 0, 0, 0, 0},
    {0x11, 0, _image1175_size, 0, 0, 0, 0},
    {0x11, 0, _image1176_size, 0, 0, 0, 0},
    {0x33, 0, _image1177_size, 0, 0, 0, 0},
    {0x33, 0, _image1178_size, 0, 0, 0, 0},
    {0x33, 0, _image1179_size, 0, 0, 0, 0},
    {0x33, 0, _image1180_size, 0, 0, 0, 0},
    {0x33, 0, _image1181_size, 0, 0, 0, 0},
    {0x33, 0, _image1182_size, 0, 0, 0, 0},
    {0x33, 0, _image1183_size, 0, 0, 0, 0},
    {0x33, 0, _image1184_size, 0, 0, 0, 0},
    {0, 0, _image1185_size, 0, 0, 0, 0},
    {0, 0, _image1186_size, 0, 0, 0, 0},
    {0, 0, _image1187_size, 0, 0, 0, 0},
    {0, 0, _image1188_size, 0, 0, 0, 0},
    {0, 0, _image1189_size, 0, 0, 0, 0},
    {0, 0, _image1190_size, 0, 0, 0, 0},
    {0, 0, _image1191_size, 0, 0, 0, 0},
    {0xAA, 0, _image1192_size, 0, 0, 0, 0},
    {0, 0, _image1193_size, 0, 0, 0, 0},
    {0xAA, 0, _image1194_size, 0, 0, 0, 0},
    {0x33, 0, _image1195_size, 0, 0, 0, 0},
    {0xAA, 0, _image1196_size, 0, 0, 0, 0},
    {0, 0, _image1197_size, 0, 0, 0, 0},
    {0x33, 0, _image1198_size, 0, 0, 0, 0},
    {0, 0, _image1199_size, 0, 0, 0, 0},
    {0, 0, _image1200_size, 0, 0, 0, 0},
    {0, 0, _image1201_size, 0, 0, 0, 0},
    {0, 0, _image1202_size, 0, 0, 0, 0},
    {0x33, 0, _image1203_size, 0, 0, 0, 0},
    {0x22, 0, _image1204_size, 0, 0, 0, 0},
    {0x22, 0, _image1205_size, 0, 0, 0, 0},
    {0x22, 0, _image1206_size, 0, 0, 0, 0},
    {0, 0, _image1207_size, 0, 0, 0, 0},
    {0, 0, _image1208_size, 0, 0, 0, 0},
    {0, 0, _image1209_size, 0, 0, 0, 0},
    {0, 0, _image1210_size, 0, 0, 0, 0},
    {0, 0, _image1211_size, 0, 0, 0, 0},
    {0, 0, _image1212_size, 0, 0, 0, 0},
    {0, 0, _image1213_size, 0, 0, 0, 0},
    {0, 0, _image1214_size, 0, 0, 0, 0},
    {0xAA, 0, _image1215_size, 0, 0, 0, 0},
    {0x22, 0, _image1216_size, 0, 0, 0, 0},
    {0x22, 0, _image1217_size, 0, 0, 0, 0},
    {0, 0, _image1218_size, 0, 0, 0, 0},
    {0, 0, _image1219_size, 0, 0, 0, 0},
    {0, 0, _image1220_size, 0, 0, 0, 0},
    {0x33, 0, _image1221_size, 0, 0, 0, 0},
    {0, 0, _image1222_size, 0, 0, 0, 0},
    {0, 0, _image1223_size, 0, 0, 0, 0},
    {0, 0, _image1224_size, 0, 0, 0, 0},
    {0, 0, _image1225_size, 0, 0, 0, 0},
    {0, 0, _image1226_size, 0, 0, 0, 0},
    {0, 0, _image1227_size, 0, 0, 0, 0},
    {0, 0, _image1228_size, 0, 0, 0, 0},
    {0, 0, _image1229_size, 0, 0, 0, 0},
    {0, 0, _image1230_size, 0, 0, 0, 0},
    {0x33, 0, _image1231_size, 0, 0, 0, 0},
    {0x33, 0, _image1232_size, 0, 0, 0, 0},
    {0x33, 0, _image1233_size, 0, 0, 0, 0},
    {0x33, 0, _image1234_size, 0, 0, 0, 0},
    {0x33, 0, _image1235_size, 0, 0, 0, 0},
    {0x33, 0, _image1236_size, 0, 0, 0, 0},
    {0x33, 0, _image1237_size, 0, 0, 0, 0},
    {0x33, 0, _image1238_size, 0, 0, 0, 0},
    {0x33, 0, _image1239_size, 0, 0, 0, 0},
    {0x33, 0, _image1240_size, 0, 0, 0, 0},
    {0x33, 0, _image1241_size, 0, 0, 0, 0},
    {0x33, 0, _image1242_size, 0, 0, 0, 0},
    {0xAA, 0, _image1243_size, 0, 0, 0, 0},
    {0x33, 0, _image1244_size, 0, 0, 0, 0},
    {0x33, 0, _image1245_size, 0, 0, 0, 0},
    {0x33, 0, _image1246_size, 0, 0, 0, 0},
    {0x33, 0, _image1247_size, 0, 0, 0, 0},
    {0, 0, _image1248_size, 0, 0, 0, 0},
    {0x33, 0, _image1249_size, 0, 0, 0, 0},
    {0, 0, _image1250_size, 0, 0, 0, 0},
    {0, 0, _image1251_size, 0, 0, 0, 0},
    {0, 0, _image1252_size, 0, 0, 0, 0},
    {0, 0, _image1253_size, 0, 0, 0, 0},
    {0, 0, _image1254_size, 0, 0, 0, 0},
    {0, 0, _image1255_size, 0, 0, 0, 0},
    {0, 0, _image1256_size, 0, 0, 0, 0},
    {0x22, 0, _image1257_size, 0, 0, 0, 0},
    {0, 0, _image1258_size, 0, 0, 0, 0},
    {0, 0, _image1259_size, 0, 0, 0, 0},
    {0, 0, _image1260_size, 0, 0, 0, 0},
    {0x44, 0, _image1261_size, 0, 0, 0, 0},
    {0x22, 0, _image1262_size, 0, 0, 0, 0},
    {0xAA, 0, _image1263_size, 0, 0, 0, 0},
    {0x11, 0, _image1264_size, 0, 0, 0, 0},
    {0x11, 0, _image1265_size, 0, 0, 0, 0},
    {0x11, 0, _image1266_size, 0, 0, 0, 0},
    {0x11, 0, _image1267_size, 0, 0, 0, 0},
    {0x11, 0, _image1268_size, 0, 0, 0, 0},
    {0, 0, _image1269_size, 0, 0, 0, 0},
    {0xAA, 0, _image1270_size, 0, 0, 0, 0},
    {0, 0, _image1271_size, 0, 0, 0, 0},
    {0, 0, _image1272_size, 0, 0, 0, 0},
    {0, 0, _image1273_size, 0, 0, 0, 0},
    {0, 0, _image1274_size, 0, 0, 0, 0},
    {0, 0, _image1275_size, 0, 0, 0, 0},
    {0, 0, _image1276_size, 0, 0, 0, 0},
    {0, 0, _image1277_size, 0, 0, 0, 0},
    {0, 0, _image1278_size, 0, 0, 0, 0},
    {0, 0, _image1279_size, 0, 0, 0, 0},
    {0, 0, _image1280_size, 0, 0, 0, 0},
    {0x11, 0, _image1281_size, 0, 0, 0, 0},
    {0x22, 0, _image1282_size, 0, 0, 0, 0},
    {0x22, 0, _image1283_size, 0, 0, 0, 0},
    {0, 0, _image1284_size, 0, 0, 0, 0},
    {0, 0, _image1285_size, 0, 0, 0, 0},
    {0x11, 0, _image1286_size, 0, 0, 0, 0},
    {0x11, 0, _image1287_size, 0, 0, 0, 0},
    {0x11, 0, _image1288_size, 0, 0, 0, 0},
    {0x11, 0, _image1289_size, 0, 0, 0, 0},
    {0x11, 0, _image1290_size, 0, 0, 0, 0},
    {0x11, 0, _image1291_size, 0, 0, 0, 0},
    {0x11, 0, _image1292_size, 0, 0, 0, 0},
    {0x11, 0, _image1293_size, 0, 0, 0, 0},
    {0x11, 0, _image1294_size, 0, 0, 0, 0},
    {0x11, 0, _image1295_size, 0, 0, 0, 0},
    {0x11, 0, _image1296_size, 0, 0, 0, 0},
    {0x11, 0, _image1297_size, 0, 0, 0, 0},
    {0x11, 0, _image1298_size, 0, 0, 0, 0},
    {0x11, 0, _image1299_size, 0, 0, 0, 0},
    {0x11, 0, _image1300_size, 0, 0, 0, 0},
    {0x11, 0, _image1301_size, 0, 0, 0, 0},
    {0x11, 0, _image1302_size, 0, 0, 0, 0},
    {0x11, 0, _image1303_size, 0, 0, 0, 0},
    {0x11, 0, _image1304_size, 0, 0, 0, 0},
    {0x11, 0, _image1305_size, 0, 0, 0, 0},
    {0x11, 0, _image1306_size, 0, 0, 0, 0},
    {0x11, 0, _image1307_size, 0, 0, 0, 0},
    {0x11, 0, _image1308_size, 0, 0, 0, 0},
    {0x11, 0, _image1309_size, 0, 0, 0, 0},
    {0x11, 0, _image1310_size, 0, 0, 0, 0},
    {0x11, 0, _image1311_size, 0, 0, 0, 0},
    {0x11, 0, _image1312_size, 0, 0, 0, 0},
    {0x11, 0, _image1313_size, 0, 0, 0, 0},
    {0x11, 0, _image1314_size, 0, 0, 0, 0},
    {0x11, 0, _image1315_size, 0, 0, 0, 0},
    {0x11, 0, _image1316_size, 0, 0, 0, 0},
    {0x11, 0, _image1317_size, 0, 0, 0, 0},
    {0x11, 0, _image1318_size, 0, 0, 0, 0},
    {0x11, 0, _image1319_size, 0, 0, 0, 0},
    {0x11, 0, _image1320_size, 0, 0, 0, 0},
    {0x11, 0, _image1321_size, 0, 0, 0, 0},
    {0x11, 0, _image1322_size, 0, 0, 0, 0},
    {0x11, 0, _image1323_size, 0, 0, 0, 0},
    {0x11, 0, _image1324_size, 0, 0, 0, 0},
    {0x11, 0, _image1325_size, 0, 0, 0, 0},
    {0x11, 0, _image1326_size, 0, 0, 0, 0},
    {0x11, 0, _image1327_size, 0, 0, 0, 0},
    {0x11, 0, _image1328_size, 0, 0, 0, 0},
    {0x11, 0, _image1329_size, 0, 0, 0, 0},
    {0x11, 0, _image1330_size, 0, 0, 0, 0},
    {0x11, 0, _image1331_size, 0, 0, 0, 0},
    {0x11, 0, _image1332_size, 0, 0, 0, 0},
    {0x11, 0, _image1333_size, 0, 0, 0, 0},
    {0x11, 0, _image1334_size, 0, 0, 0, 0},
    {0x11, 0, _image1335_size, 0, 0, 0, 0},
    {0x11, 0, _image1336_size, 0, 0, 0, 0},
    {0x11, 0, _image1337_size, 0, 0, 0, 0},
    {0x11, 0, _image1338_size, 0, 0, 0, 0},
    {0x11, 0, _image1339_size, 0, 0, 0, 0},
    {0x11, 0, _image1340_size, 0, 0, 0, 0},
    {0x11, 0, _image1341_size, 0, 0, 0, 0},
    {0x11, 0, _image1342_size, 0, 0, 0, 0},
    {0x11, 0, _image1343_size, 0, 0, 0, 0},
    {0x11, 0, _image1344_size, 0, 0, 0, 0},
    {0x11, 0, _image1345_size, 0, 0, 0, 0},
    {0x11, 0, _image1346_size, 0, 0, 0, 0},
    {0x11, 0, _image1347_size, 0, 0, 0, 0},
    {0x11, 0, _image1348_size, 0, 0, 0, 0},
    {0x11, 0, _image1349_size, 0, 0, 0, 0},
    {0x11, 0, _image1350_size, 0, 0, 0, 0},
    {0x11, 0, _image1351_size, 0, 0, 0, 0},
    {0x11, 0, _image1352_size, 0, 0, 0, 0},
    {0x11, 0, _image1353_size, 0, 0, 0, 0},
    {0x11, 0, _image1354_size, 0, 0, 0, 0},
    {0x11, 0, _image1355_size, 0, 0, 0, 0},
    {0x11, 0, _image1356_size, 0, 0, 0, 0},
    {0, 0, _image1357_size, 0, 0, 0, 0},
    {0, 0, _image1358_size, 0, 0, 0, 0},
    {0x11, 0, _image1359_size, 0, 0, 0, 0},
    {0x11, 0, _image1360_size, 0, 0, 0, 0},
    {0x11, 0, _image1361_size, 0, 0, 0, 0},
    {0x11, 0, _image1362_size, 0, 0, 0, 0},
    {0x11, 0, _image1363_size, 0, 0, 0, 0},
    {0x11, 0, _image1364_size, 0, 0, 0, 0},
    {0x11, 0, _image1365_size, 0, 0, 0, 0},
    {0, 0, _image1366_size, 0, 0, 0, 0},
    {0, 0, _image1367_size, 0, 0, 0, 0},
    {0x33, 0, _image1368_size, 0, 0, 0, 0},
    {0x33, 0, _image1369_size, 0, 0, 0, 0},
    {0x33, 0, _image1370_size, 0, 0, 0, 0},
    {0, 0, _image1371_size, 0, 0, 0, 0},
    {0, 0, _image1372_size, 0, 0, 0, 0},
    {0, 0, _image1373_size, 0, 0, 0, 0},
    {0xAA, 0, _image1374_size, 0, 0, 0, 0},
    {0xAA, 0, _image1375_size, 0, 0, 0, 0},
    {0x33, 0, _image1376_size, 0, 0, 0, 0},
    {0x33, 0, _image1377_size, 0, 0, 0, 0},
    {0, 0, _image1378_size, 0, 0, 0, 0},
    {0, 0, _image1379_size, 0, 0, 0, 0},
    {0, 0, _image1380_size, 0, 0, 0, 0},
    {0, 0, _image1381_size, 0, 0, 0, 0},
    {0, 0, _image1382_size, 0, 0, 0, 0},
    {0, 0, _image1383_size, 0, 0, 0, 0},
    {0x44, 0, _image1384_size, 0, 0, 0, 0},
    {0, 0, _image1385_size, 0, 0, 0, 0},
    {0xAA, 0, _image1386_size, 0, 0, 0, 0},
    {0xAA, 0, _image1387_size, 0, 0, 0, 0},
    {0xAA, 0, _image1388_size, 0, 0, 0, 0},
    {0, 0, _image1389_size, 0, 0, 0, 0},
    {0, 0, _image1390_size, 0, 0, 0, 0},
    {0, 0, _image1391_size, 0, 0, 0, 0},
    {0, 0, _image1392_size, 0, 0, 0, 0},
    {0, 0, _image1393_size, 0, 0, 0, 0},
    {0, 0, _image1394_size, 0, 0, 0, 0},
    {0, 0, _image1395_size, 0, 0, 0, 0},
    {0, 0, _image1396_size, 0, 0, 0, 0},
    {0, 0, _image1397_size, 0, 0, 0, 0},
    {0, 0, _image1398_size, 0, 0, 0, 0},
    {0, 0, _image1399_size, 0, 0, 0, 0},
    {0, 0, _image1400_size, 0, 0, 0, 0},
    {0, 0, _image1401_size, 0, 0, 0, 0},
    {0, 0, _image1402_size, 0, 0, 0, 0},
    {0, 0, _image1403_size, 0, 0, 0, 0},
    {0, 0, _image1404_size, 0, 0, 0, 0},
    {0, 0, _image1405_size, 0, 0, 0, 0},
    {0, 0, _image1406_size, 0, 0, 0, 0},
    {0, 0, _image1407_size, 0, 0, 0, 0},
    {0, 0, _image1408_size, 0, 0, 0, 0},
    {0, 0, _image1409_size, 0, 0, 0, 0},
    {0, 0, _image1410_size, 0, 0, 0, 0},
    {0, 0, _image1411_size, 0, 0, 0, 0},
    {0, 0, _image1412_size, 0, 0, 0, 0},
    {0, 0, _image1413_size, 0, 0, 0, 0},
    {0, 0, _image1414_size, 0, 0, 0, 0},
    {0, 0, _image1415_size, 0, 0, 0, 0},
    {0, 0, _image1416_size, 0, 0, 0, 0},
    {0, 0, _image1417_size, 0, 0, 0, 0},
    {0, 0, _image1418_size, 0, 0, 0, 0},
    {0x99, 0, _image1419_size, 0, 0, 0, 0},
    {0xAA, 0, _image1420_size, 0, 0, 0, 0},
    {0xAA, 0, _image1421_size, 0, 0, 0, 0},
    {0, 0, _image1422_size, 0, 0, 0, 0},
    {0, 0, _image1423_size, 0, 0, 0, 0},
    {0, 0, _image1424_size, 0, 0, 0, 0},
    {0, 0, _image1425_size, 0, 0, 0, 0},
    {0, 0, _image1426_size, 0, 0, 0, 0},
    {0x33, 0, _image1427_size, 0, 0, 0, 0},
    {0, 0, _image1428_size, 0, 0, 0, 0},
    {0, 0, _image1429_size, 0, 0, 0, 0},
    {0, 0, _image1430_size, 0, 0, 0, 0},
    {0x33, 0, _image1431_size, 0, 0, 0, 0},
    {0x33, 0, _image1432_size, 0, 0, 0, 0},
    {0x33, 0, _image1433_size, 0, 0, 0, 0},
    {0x33, 0, _image1434_size, 0, 0, 0, 0},
    {0x33, 0, _image1435_size, 0, 0, 0, 0},
    {0x44, 0, _image1436_size, 0, 0, 0, 0},
    {0x44, 0, _image1437_size, 0, 0, 0, 0},
    {0, 0, _image1438_size, 0, 0, 0, 0},
    {0x33, 0, _image1439_size, 0, 0, 0, 0},
    {0x22, 0, _image1440_size, 0, 0, 0, 0},
    {0xAA, 0, _image1441_size, 0, 0, 0, 0},
    {0, 0, _image1442_size, 0, 0, 0, 0},
    {0, 0, _image1443_size, 0, 0, 0, 0},
    {0, 0, _image1444_size, 0, 0, 0, 0},
    {0, 0, _image1445_size, 0, 0, 0, 0},
    {0, 0, _image1446_size, 0, 0, 0, 0},
    {0, 0, _image1447_size, 0, 0, 0, 0},
    {0, 0, _image1448_size, 0, 0, 0, 0},
    {0xAA, 0, _image1449_size, 0, 0, 0, 0},
    {0x44, 0, _image1450_size, 0, 0, 0, 0},
    {0xAA, 0, _image1451_size, 0, 0, 0, 0},
    {0xAA, 0, _image1452_size, 0, 0, 0, 0},
    {0xAA, 0, _image1453_size, 0, 0, 0, 0},
    {0xAA, 0, _image1454_size, 0, 0, 0, 0},
    {0xAA, 0, _image1455_size, 0, 0, 0, 0},
    {0, 0, _image1456_size, 0, 0, 0, 0},
    {0, 0, _image1457_size, 0, 0, 0, 0},
    {0, 0, _image1458_size, 0, 0, 0, 0},
    {0, 0, _image1459_size, 0, 0, 0, 0},
    {0, 0, _image1460_size, 0, 0, 0, 0},
    {0xAA, 0, _image1461_size, 0, 0, 0, 0},
    {0x33, 0, _image1462_size, 0, 0, 0, 0},
    {0x33, 0, _image1463_size, 0, 0, 0, 0},
    {0x33, 0, _image1464_size, 0, 0, 0, 0},
    {0x33, 0, _image1465_size, 0, 0, 0, 0},
    {0x33, 0, _image1466_size, 0, 0, 0, 0},
    {0, 0, _image1467_size, 0, 0, 0, 0},
    {0x33, 0, _image1468_size, 0, 0, 0, 0},
    {0x11, 0, _image1469_size, 0, 0, 0, 0},
    {0x11, 0, _image1470_size, 0, 0, 0, 0},
    {0x33, 0, _image1471_size, 0, 0, 0, 0},
    {0, 0, _image1472_size, 0, 0, 0, 0},
    {0, 0, _image1473_size, 0, 0, 0, 0},
    {0xAA, 0, _image1474_size, 0, 0, 0, 0},
    {0xAA, 0, _image1475_size, 0, 0, 0, 0},
    {0x11, 0, _image1476_size, 0, 0, 0, 0},
    {0x11, 0, _image1477_size, 0, 0, 0, 0},
    {0x11, 0, _image1478_size, 0, 0, 0, 0},
    {0x11, 0, _image1479_size, 0, 0, 0, 0},
    {0x11, 0, _image1480_size, 0, 0, 0, 0},
    {0, 0, _image1481_size, 0, 0, 0, 0},
    {0, 0, _image1482_size, 0, 0, 0, 0},
    {0, 0, _image1483_size, 0, 0, 0, 0},
    {0, 0, _image1484_size, 0, 0, 0, 0},
    {0x11, 0, _image1485_size, 0, 0, 0, 0},
    {0x11, 0, _image1486_size, 0, 0, 0, 0},
    {0x11, 0, _image1487_size, 0, 0, 0, 0},
    {0, 0, _image1488_size, 0, 0, 0, 0},
    {0, 0, _image1489_size, 0, 0, 0, 0},
    {0, 0, _image1490_size, 0, 0, 0, 0},
    {0, 0, _image1491_size, 0, 0, 0, 0},
    {0, 0, _image1492_size, 0, 0, 0, 0},
    {0, 0, _image1493_size, 0, 0, 0, 0},
    {0, 0, _image1494_size, 0, 0, 0, 0},
    {0, 0, _image1495_size, 0, 0, 0, 0},
    {0, 0, _image1496_size, 0, 0, 0, 0},
    {0, 0, _image1497_size, 0, 0, 0, 0},
    {0, 0, _image1498_size, 0, 0, 0, 0},
    {0, 0, _image1499_size, 0, 0, 0, 0},
    {0x22, 0, _image1500_size, 0, 0, 0, 0},
    {0x22, 0, _image1501_size, 0, 0, 0, 0},
    {0, 0, _image1502_size, 0, 0, 0, 0},
    {0, 0, _image1503_size, 0, 0, 0, 0},
    {0, 0, _image1504_size, 0, 0, 0, 0},
    {0, 0, _image1505_size, 0, 0, 0, 0},
    {0, 0, _image1506_size, 0, 0, 0, 0},
    {0, 0, _image1507_size, 0, 0, 0, 0},
    {0, 0, _image1508_size, 0, 0, 0, 0},
    {0x55, 0, _image1509_size, 0, 0, 0, 0},
    {0x55, 0, _image1510_size, 0, 0, 0, 0},
    {0x55, 0, _image1511_size, 0, 0, 0, 0},
    {0x55, 0, _image1512_size, 0, 0, 0, 0},
    {0x55, 0, _image1513_size, 0, 0, 0, 0},
    {0, 0, _image1514_size, 0, 0, 0, 0},
    {0, 0, _image1515_size, 0, 0, 0, 0},
    {0x44, 0, _image1516_size, 0, 0, 0, 0},
    {0x44, 0, _image1517_size, 0, 0, 0, 0},
    {0x44, 0, _image1518_size, 0, 0, 0, 0},
    {0x44, 0, _image1519_size, 0, 0, 0, 0},
    {0x44, 0, _image1520_size, 0, 0, 0, 0},
    {0x44, 0, _image1521_size, 0, 0, 0, 0},
    {0x44, 0, _image1522_size, 0, 0, 0, 0},
    {0, 0, _image1523_size, 0, 0, 0, 0},
    {0x22, 0, _image1524_size, 0, 0, 0, 0},
    {0x22, 0, _image1525_size, 0, 0, 0, 0},
    {0x22, 0, _image1526_size, 0, 0, 0, 0},
    {0x22, 0, _image1527_size, 0, 0, 0, 0},
    {0x22, 0, _image1528_size, 0, 0, 0, 0},
    {0x22, 0, _image1529_size, 0, 0, 0, 0},
    {0x22, 0, _image1530_size, 0, 0, 0, 0},
    {0x22, 0, _image1531_size, 0, 0, 0, 0},
    {0x22, 0, _image1532_size, 0, 0, 0, 0},
    {0x22, 0, _image1533_size, 0, 0, 0, 0},
    {0x22, 0, _image1534_size, 0, 0, 0, 0},
    {0x22, 0, _image1535_size, 0, 0, 0, 0},
    {0x22, 0, _image1536_size, 0, 0, 0, 0},
    {0x22, 0, _image1537_size, 0, 0, 0, 0},
    {0x22, 0, _image1538_size, 0, 0, 0, 0},
    {0x22, 0, _image1539_size, 0, 0, 0, 0},
    {0x22, 0, _image1540_size, 0, 0, 0, 0},
    {0x22, 0, _image1541_size, 0, 0, 0, 0},
    {0, 0, _image1542_size, 0, 0, 0, 0},
    {0, 0, _image1543_size, 0, 0, 0, 0},
    {0, 0, _image1544_size, 0, 0, 0, 0},
    {0, 0, _image1545_size, 0, 0, 0, 0},
    {0, 0, _image1546_size, 0, 0, 0, 0},
    {0, 0, _image1547_size, 0, 0, 0, 0},
    {0, 0, _image1548_size, 0, 0, 0, 0},
    {0, 0, _image1549_size, 0, 0, 0, 0},
    {0, 0, _image1550_size, 0, 0, 0, 0},
    {0, 0, _image1551_size, 0, 0, 0, 0},
    {0, 0, _image1552_size, 0, 0, 0, 0},
    {0, 0, _image1553_size, 0, 0, 0, 0},
    {0, 0, _image1554_size, 0, 0, 0, 0},
    {0, 0, _image1555_size, 0, 0, 0, 0},
    {0, 0, _image1556_size, 0, 0, 0, 0},
    {0, 0, _image1557_size, 0, 0, 0, 0},
    {0, 0, _image1558_size, 0, 0, 0, 0},
    {0, 0, _image1559_size, 0, 0, 0, 0},
    {0, 0, _image1560_size, 0, 0, 0, 0},
    {0, 0, _image1561_size, 0, 0, 0, 0},
    {0, 0, _image1562_size, 0, 0, 0, 0},
    {0, 0, _image1563_size, 0, 0, 0, 0},
    {0, 0, _image1564_size, 0, 0, 0, 0},
    {0, 0, _image1565_size, 0, 0, 0, 0},
    {0, 0, _image1566_size, 0, 0, 0, 0},
    {0, 0, _image1567_size, 0, 0, 0, 0},
    {0, 0, _image1568_size, 0, 0, 0, 0},
    {0, 0, _image1569_size, 0, 0, 0, 0},
    {0, 0, _image1570_size, 0, 0, 0, 0},
    {0, 0, _image1571_size, 0, 0, 0, 0},
    {0, 0, _image1572_size, 0, 0, 0, 0},
    {0, 0, _image1573_size, 0, 0, 0, 0},
    {0, 0, _image1574_size, 0, 0, 0, 0},
    {0, 0, _image1575_size, 0, 0, 0, 0},
    {0, 0, _image1576_size, 0, 0, 0, 0},
    {0, 0, _image1577_size, 0, 0, 0, 0},
    {0, 0, _image1578_size, 0, 0, 0, 0},
    {0, 0, _image1579_size, 0, 0, 0, 0},
    {0, 0, _image1580_size, 0, 0, 0, 0},
    {0, 0, _image1581_size, 0, 0, 0, 0},
    {0, 0, _image1582_size, 0, 0, 0, 0},
    {0, 0, _image1583_size, 0, 0, 0, 0},
    {0, 0, _image1584_size, 0, 0, 0, 0},
    {0, 0, _image1585_size, 0, 0, 0, 0},
    {0, 0, _image1586_size, 0, 0, 0, 0},
    {0, 0, _image1587_size, 0, 0, 0, 0},
    {0, 0, _image1588_size, 0, 0, 0, 0},
    {0, 0, _image1589_size, 0, 0, 0, 0},
    {0, 0, _image1590_size, 0, 0, 0, 0},
    {0, 0, _image1591_size, 0, 0, 0, 0},
    {0, 0, _image1592_size, 0, 0, 0, 0},
    {0, 0, _image1593_size, 0, 0, 0, 0},
    {0, 0, _image1594_size, 0, 0, 0, 0},
    {0, 0, _image1595_size, 0, 0, 0, 0},
    {0, 0, _image1596_size, 0, 0, 0, 0},
    {0, 0, _image1597_size, 0, 0, 0, 0},
    {0, 0, _image1598_size, 0, 0, 0, 0},
    {0, 0, _image1599_size, 0, 0, 0, 0},
    {0, 0, _image1600_size, 0, 0, 0, 0},
    {0, 0, _image1601_size, 0, 0, 0, 0},
    {0, 0, _image1602_size, 0, 0, 0, 0},
    {0, 0, _image1603_size, 0, 0, 0, 0},
    {0, 0, _image1604_size, 0, 0, 0, 0},
    {0, 0, _image1605_size, 0, 0, 0, 0},
    {0, 0, _image1606_size, 0, 0, 0, 0},
    {0, 0, _image1607_size, 0, 0, 0, 0},
    {0, 0, _image1608_size, 0, 0, 0, 0},
    {0, 0, _image1609_size, 0, 0, 0, 0},
    {0, 0, _image1610_size, 0, 0, 0, 0},
    {0, 0, _image1611_size, 0, 0, 0, 0},
    {0, 0, _image1612_size, 0, 0, 0, 0},
    {0, 0, _image1613_size, 0, 0, 0, 0},
    {0, 0, _image1614_size, 0, 0, 0, 0},
    {0, 0, _image1615_size, 0, 0, 0, 0},
    {0, 0, _image1616_size, 0, 0, 0, 0},
    {0, 0, _image1617_size, 0, 0, 0, 0},
    {0, 0, _image1618_size, 0, 0, 0, 0},
    {0, 0, _image1619_size, 0, 0, 0, 0},
    {0, 0, _image1620_size, 0, 0, 0, 0},
    {0, 0, _image1621_size, 0, 0, 0, 0},
    {0, 0, _image1622_size, 0, 0, 0, 0},
    {0, 0, _image1623_size, 0, 0, 0, 0},
    {0, 0, _image1624_size, 0, 0, 0, 0},
    {0, 0, _image1625_size, 0, 0, 0, 0},
    {0, 0, _image1626_size, 0, 0, 0, 0},
    {0, 0, _image1627_size, 0, 0, 0, 0},
    {0, 0, _image1628_size, 0, 0, 0, 0},
    {0, 0, _image1629_size, 0, 0, 0, 0},
    {0, 0, _image1630_size, 0, 0, 0, 0},
    {0, 0, _image1631_size, 0, 0, 0, 0},
    {0, 0, _image1632_size, 0, 0, 0, 0},
    {0, 0, _image1633_size, 0, 0, 0, 0},
    {0, 0, _image1634_size, 0, 0, 0, 0},
    {0, 0, _image1635_size, 0, 0, 0, 0},
    {0, 0, _image1636_size, 0, 0, 0, 0},
    {0, 0, _image1637_size, 0, 0, 0, 0},
    {0, 0, _image1638_size, 0, 0, 0, 0},
    {0, 0, _image1639_size, 0, 0, 0, 0},
    {0, 0, _image1640_size, 0, 0, 0, 0},
    {0, 0, _image1641_size, 0, 0, 0, 0},
    {0, 0, _image1642_size, 0, 0, 0, 0},
    {0, 0, _image1643_size, 0, 0, 0, 0},
    {0, 0, _image1644_size, 0, 0, 0, 0},
    {0, 0, _image1645_size, 0, 0, 0, 0},
    {0, 0, _image1646_size, 0, 0, 0, 0},
    {0, 0, _image1647_size, 0, 0, 0, 0},
    {0, 0, _image1648_size, 0, 0, 0, 0},
    {0, 0, _image1649_size, 0, 0, 0, 0},
    {0, 0, _image1650_size, 0, 0, 0, 0},
    {0, 0, _image1651_size, 0, 0, 0, 0},
    {0, 0, _image1652_size, 0, 0, 0, 0},
    {0x33, 0, _image1653_size, 0, 0, 0, 0},
    {0, 0, _image1654_size, 0, 0, 0, 0},
    {0, 0, _image1655_size, 0, 0, 0, 0},
    {0, 0, _image1656_size, 0, 0, 0, 0},
    {0, 0, _image1657_size, 0, 0, 0, 0},
    {0, 0, _image1658_size, 0, 0, 0, 0},
    {0, 0, _image1659_size, 0, 0, 0, 0},
    {0, 0, _image1660_size, 0, 0, 0, 0},
    {0, 0, _image1661_size, 0, 0, 0, 0},
    {0, 0, _image1662_size, 0, 0, 0, 0},
    {0, 0, _image1663_size, 0, 0, 0, 0},
    {0, 0, _image1664_size, 0, 0, 0, 0},
    {0, 0, _image1665_size, 0, 0, 0, 0},
    {0, 0, _image1666_size, 0, 0, 0, 0},
    {0x33, 0, _image1667_size, 0, 0, 0, 0},
    {0x33, 0, _image1668_size, 0, 0, 0, 0},
    {0xAA, 0, _image1669_size, 0, 0, 0, 0},
    {0x33, 0, _image1670_size, 0, 0, 0, 0},
    {0x33, 0, _image1671_size, 0, 0, 0, 0},
    {0, 0, _image1672_size, 0, 0, 0, 0},
    {0, 0, _image1673_size, 0, 0, 0, 0},
    {0, 0, _image1674_size, 0, 0, 0, 0},
    {0, 0, _image1675_size, 0, 0, 0, 0},
    {0, 0, _image1676_size, 0, 0, 0, 0},
    {0, 0, _image1677_size, 0, 0, 0, 0},
    {0, 0, _image1678_size, 0, 0, 0, 0},
    {0, 0, _image1679_size, 0, 0, 0, 0},
    {0, 0, _image1680_size, 0, 0, 0, 0},
    {0, 0, _image1681_size, 0, 0, 0, 0},
    {0, 0, _image1682_size, 0, 0, 0, 0},
    {0, 0, _image1683_size, 0, 0, 0, 0},
    {0, 0, _image1684_size, 0, 0, 0, 0},
    {0, 0, _image1685_size, 0, 0, 0, 0},
    {0, 0, _image1686_size, 0, 0, 0, 0},
    {0, 0, _image1687_size, 0, 0, 0, 0},
    {0, 0, _image1688_size, 0, 0, 0, 0},
    {0, 0, _image1689_size, 0, 0, 0, 0},
    {0, 0, _image1690_size, 0, 0, 0, 0},
    {0, 0, _image1691_size, 0, 0, 0, 0},
    {0, 0, _image1692_size, 0, 0, 0, 0},
    {0, 0, _image1693_size, 0, 0, 0, 0},
    {0, 0, _image1694_size, 0, 0, 0, 0},
    {0, 0, _image1695_size, 0, 0, 0, 0},
    {0, 0, _image1696_size, 0, 0, 0, 0},
    {0, 0, _image1697_size, 0, 0, 0, 0},
    {0, 0, _image1698_size, 0, 0, 0, 0},
    {0, 0, _image1699_size, 0, 0, 0, 0},
    {0, 0, _image1700_size, 0, 0, 0, 0},
    {0, 0, _image1701_size, 0, 0, 0, 0},
    {0, 0, _image1702_size, 0, 0, 0, 0},
    {0, 0, _image1703_size, 0, 0, 0, 0},
    {0, 0, _image1704_size, 0, 0, 0, 0},
    {0, 0, _image1705_size, 0, 0, 0, 0},
    {0, 0, _image1706_size, 0, 0, 0, 0},
    {0, 0, _image1707_size, 0, 0, 0, 0},
    {0, 0, _image1708_size, 0, 0, 0, 0},
    {0, 0, _image1709_size, 0, 0, 0, 0},
    {0, 0, _image1710_size, 0, 0, 0, 0},
    {0, 0, _image1711_size, 0, 0, 0, 0},
    {0, 0, _image1712_size, 0, 0, 0, 0},
    {0, 0, _image1713_size, 0, 0, 0, 0},
    {0, 0, _image1714_size, 0, 0, 0, 0},
    {0, 0, _image1715_size, 0, 0, 0, 0},
    {0, 0, _image1716_size, 0, 0, 0, 0},
    {0, 0, _image1717_size, 0, 0, 0, 0},
    {0, 0, _image1718_size, 0, 0, 0, 0},
    {0, 0, _image1719_size, 0, 0, 0, 0},
    {0, 0, _image1720_size, 0, 0, 0, 0},
    {0, 0, _image1721_size, 0, 0, 0, 0},
    {0, 0, _image1722_size, 0, 0, 0, 0},
    {0, 0, _image1723_size, 0, 0, 0, 0},
    {0, 0, _image1724_size, 0, 0, 0, 0},
    {0, 0, _image1725_size, 0, 0, 0, 0},
    {0, 0, _image1726_size, 0, 0, 0, 0},
    {0, 0, _image1727_size, 0, 0, 0, 0},
    {0, 0, _image1728_size, 0, 0, 0, 0},
    {0, 0, _image1729_size, 0, 0, 0, 0},
    {0x33, 0, _image1730_size, 0, 0, 0, 0},
    {0x33, 0, _image1731_size, 0, 0, 0, 0},
    {0x33, 0, _image1732_size, 0, 0, 0, 0},
    {0x33, 0, _image1733_size, 0, 0, 0, 0},
    {0, 0, _image1734_size, 0, 0, 0, 0},
    {0, 0, _image1735_size, 0, 0, 0, 0},
    {0, 0, _image1736_size, 0, 0, 0, 0},
    {0, 0, _image1737_size, 0, 0, 0, 0},
    {0, 0, _image1738_size, 0, 0, 0, 0},
    {0, 0, _image1739_size, 0, 0, 0, 0},
    {0, 0, _image1740_size, 0, 0, 0, 0},
    {0, 0, _image1741_size, 0, 0, 0, 0},
    {0, 0, _image1742_size, 0, 0, 0, 0},
    {0, 0, _image1743_size, 0, 0, 0, 0},
    {0, 0, _image1744_size, 0, 0, 0, 0},
    {0, 0, _image1745_size, 0, 0, 0, 0},
    {0, 0, _image1746_size, 0, 0, 0, 0},
    {0, 0, _image1747_size, 0, 0, 0, 0},
    {0, 0, _image1748_size, 0, 0, 0, 0},
    {0, 0, _image1749_size, 0, 0, 0, 0},
    {0, 0, _image1750_size, 0, 0, 0, 0},
    {0, 0, _image1751_size, 0, 0, 0, 0},
    {0, 0, _image1752_size, 0, 0, 0, 0},
    {0, 0, _image1753_size, 0, 0, 0, 0},
    {0, 0, _image1754_size, 0, 0, 0, 0},
    {0, 0, _image1755_size, 0, 0, 0, 0},
    {0, 0, _image1756_size, 0, 0, 0, 0},
    {0, 0, _image1757_size, 0, 0, 0, 0},
    {0, 0, _image1758_size, 0, 0, 0, 0},
    {0, 0, _image1759_size, 0, 0, 0, 0},
    {0, 0, _image1760_size, 0, 0, 0, 0},
    {0, 0, _image1761_size, 0, 0, 0, 0},
    {0, 0, _image1762_size, 0, 0, 0, 0},
    {0, 0, _image1763_size, 0, 0, 0, 0},
    {0, 0, _image1764_size, 0, 0, 0, 0},
    {0, 0, _image1765_size, 0, 0, 0, 0},
    {0, 0, _image1766_size, 0, 0, 0, 0},
    {0, 0, _image1767_size, 0, 0, 0, 0},
    {0, 0, _image1768_size, 0, 0, 0, 0},
    {0, 0, _image1769_size, 0, 0, 0, 0},
    {0, 0, _image1770_size, 0, 0, 0, 0},
    {0, 0, _image1771_size, 0, 0, 0, 0},
    {0, 0, _image1772_size, 0, 0, 0, 0},
    {0, 0, _image1773_size, 0, 0, 0, 0},
    {0, 0, _image1774_size, 0, 0, 0, 0},
    {0, 0, _image1775_size, 0, 0, 0, 0},
    {0, 0, _image1776_size, 0, 0, 0, 0},
    {0, 0, _image1777_size, 0, 0, 0, 0},
    {0, 0, _image1778_size, 0, 0, 0, 0},
    {0, 0, _image1779_size, 0, 0, 0, 0},
    {0, 0, _image1780_size, 0, 0, 0, 0},
    {0, 0, _image1781_size, 0, 0, 0, 0},
    {0, 0, _image1782_size, 0, 0, 0, 0},
    {0, 0, _image1783_size, 0, 0, 0, 0},
    {0, 0, _image1784_size, 0, 0, 0, 0},
    {0, 0, _image1785_size, 0, 0, 0, 0},
    {0, 0, _image1786_size, 0, 0, 0, 0},
    {0, 0, _image1787_size, 0, 0, 0, 0},
    {0, 0, _image1788_size, 0, 0, 0, 0},
    {0, 0, _image1789_size, 0, 0, 0, 0},
    {0, 0, _image1790_size, 0, 0, 0, 0},
    {0, 0, _image1791_size, 0, 0, 0, 0},
    {0, 0, _image1792_size, 0, 0, 0, 0},
    {0, 0, _image1793_size, 0, 0, 0, 0},
    {0, 0, _image1794_size, 0, 0, 0, 0},
    {0, 0, _image1795_size, 0, 0, 0, 0},
    {0, 0, _image1796_size, 0, 0, 0, 0},
    {0, 0, _image1797_size, 0, 0, 0, 0},
    {0, 0, _image1798_size, 0, 0, 0, 0},
    {0, 0, _image1799_size, 0, 0, 0, 0},
    {0, 0, _image1800_size, 0, 0, 0, 0},
    {0, 0, _image1801_size, 0, 0, 0, 0},
    {0, 0, _image1802_size, 0, 0, 0, 0},
    {0, 0, _image1803_size, 0, 0, 0, 0},
    {0, 0, _image1804_size, 0, 0, 0, 0},
    {0, 0, _image1805_size, 0, 0, 0, 0},
    {0, 0, _image1806_size, 0, 0, 0, 0},
    {0, 0, _image1807_size, 0, 0, 0, 0},
    {0, 0, _image1808_size, 0, 0, 0, 0},
    {0, 0, _image1809_size, 0, 0, 0, 0},
    {0, 0, _image1810_size, 0, 0, 0, 0},
    {0, 0, _image1811_size, 0, 0, 0, 0},
    {0, 0, _image1812_size, 0, 0, 0, 0},
    {0, 0, _image1813_size, 0, 0, 0, 0},
    {0, 0, _image1814_size, 0, 0, 0, 0},
    {0, 0, _image1815_size, 0, 0, 0, 0},
    {0, 0, _image1816_size, 0, 0, 0, 0},
    {0, 0, _image1817_size, 0, 0, 0, 0},
    {0, 0, _image1818_size, 0, 0, 0, 0},
    {0, 0, _image1819_size, 0, 0, 0, 0},
    {0, 0, _image1820_size, 0, 0, 0, 0},
    {0, 0, _image1821_size, 0, 0, 0, 0},
    {0, 0, _image1822_size, 0, 0, 0, 0},
    {0, 0, _image1823_size, 0, 0, 0, 0},
    {0, 0, _image1824_size, 0, 0, 0, 0},
    {0, 0, _image1825_size, 0, 0, 0, 0},
    {0, 0, _image1826_size, 0, 0, 0, 0},
    {0, 0, _image1827_size, 0, 0, 0, 0},
    {0, 0, _image1828_size, 0, 0, 0, 0},
    {0, 0, _image1829_size, 0, 0, 0, 0},
    {0, 0, _image1830_size, 0, 0, 0, 0},
    {0, 0, _image1831_size, 0, 0, 0, 0},
    {0, 0, _image1832_size, 0, 0, 0, 0},
    {0, 0, _image1833_size, 0, 0, 0, 0},
    {0, 0, _image1834_size, 0, 0, 0, 0},
    {0, 0, _image1835_size, 0, 0, 0, 0},
    {0, 0, _image1836_size, 0, 0, 0, 0},
    {0, 0, _image1837_size, 0, 0, 0, 0},
    {0, 0, _image1838_size, 0, 0, 0, 0},
    {0, 0, _image1839_size, 0, 0, 0, 0},
    {0, 0, _image1840_size, 0, 0, 0, 0},
    {0, 0, _image1841_size, 0, 0, 0, 0},
    {0, 0, _image1842_size, 0, 0, 0, 0},
    {0, 0, _image1843_size, 0, 0, 0, 0},
    {0, 0, _image1844_size, 0, 0, 0, 0},
    {0, 0, _image1845_size, 0, 0, 0, 0},
    {0, 0, _image1846_size, 0, 0, 0, 0},
    {0, 0, _image1847_size, 0, 0, 0, 0},
    {0, 0, _image1848_size, 0, 0, 0, 0},
    {0, 0, _image1849_size, 0, 0, 0, 0},
    {0, 0, _image1850_size, 0, 0, 0, 0},
    {0, 0, _image1851_size, 0, 0, 0, 0},
    {0, 0, _image1852_size, 0, 0, 0, 0},
    {0, 0, _image1853_size, 0, 0, 0, 0},
    {0, 0, _image1854_size, 0, 0, 0, 0},
    {0, 0, _image1855_size, 0, 0, 0, 0},
    {0, 0, _image1856_size, 0, 0, 0, 0},
    {0, 0, _image1857_size, 0, 0, 0, 0},
    {0, 0, _image1858_size, 0, 0, 0, 0},
    {0, 0, _image1859_size, 0, 0, 0, 0},
    {0, 0, _image1860_size, 0, 0, 0, 0},
    {0, 0, _image1861_size, 0, 0, 0, 0},
    {0, 0, _image1862_size, 0, 0, 0, 0},
    {0, 0, _image1863_size, 0, 0, 0, 0},
    {0, 0, _image1864_size, 0, 0, 0, 0},
    {0, 0, _image1865_size, 0, 0, 0, 0},
    {0, 0, _image1866_size, 0, 0, 0, 0},
    {0, 0, _image1867_size, 0, 0, 0, 0},
    {0, 0, _image1868_size, 0, 0, 0, 0},
    {0, 0, _image1869_size, 0, 0, 0, 0},
    {0, 0, _image1870_size, 0, 0, 0, 0},
    {0, 0, _image1871_size, 0, 0, 0, 0},
    {0, 0, _image1872_size, 0, 0, 0, 0},
    {0, 0, _image1873_size, 0, 0, 0, 0},
    {0, 0, _image1874_size, 0, 0, 0, 0},
    {0, 0, _image1875_size, 0, 0, 0, 0},
    {0, 0, _image1876_size, 0, 0, 0, 0},
    {0, 0, _image1877_size, 0, 0, 0, 0},
    {0, 0, _image1878_size, 0, 0, 0, 0},
    {0, 0, _image1879_size, 0, 0, 0, 0},
    {0, 0, _image1880_size, 0, 0, 0, 0},
    {0, 0, _image1881_size, 0, 0, 0, 0},
    {0, 0, _image1882_size, 0, 0, 0, 0},
    {0, 0, _image1883_size, 0, 0, 0, 0},
    {0, 0, _image1884_size, 0, 0, 0, 0},
    {0, 0, _image1885_size, 0, 0, 0, 0},
    {0, 0, _image1886_size, 0, 0, 0, 0},
    {0, 0, _image1887_size, 0, 0, 0, 0},
    {0, 0, _image1888_size, 0, 0, 0, 0},
    {0, 0, _image1889_size, 0, 0, 0, 0},
    {0, 0, _image1890_size, 0, 0, 0, 0},
    {0, 0, _image1891_size, 0, 0, 0, 0},
    {0, 0, _image1892_size, 0, 0, 0, 0},
    {0, 0, _image1893_size, 0, 0, 0, 0},
    {0, 0, _image1894_size, 0, 0, 0, 0},
    {0, 0, _image1895_size, 0, 0, 0, 0},
    {0, 0, _image1896_size, 0, 0, 0, 0},
    {0, 0, _image1897_size, 0, 0, 0, 0},
    {0, 0, _image1898_size, 0, 0, 0, 0},
    {0, 0, _image1899_size, 0, 0, 0, 0},
    {0, 0, _image1900_size, 0, 0, 0, 0},
    {0, 0, _image1901_size, 0, 0, 0, 0},
    {0, 0, _image1902_size, 0, 0, 0, 0},
    {0, 0, _image1903_size, 0, 0, 0, 0},
    {0, 0, _image1904_size, 0, 0, 0, 0},
    {0, 0, _image1905_size, 0, 0, 0, 0},
    {0, 0, _image1906_size, 0, 0, 0, 0},
    {0, 0, _image1907_size, 0, 0, 0, 0},
    {0, 0, _image1908_size, 0, 0, 0, 0},
    {0, 0, _image1909_size, 0, 0, 0, 0},
    {0, 0, _image1910_size, 0, 0, 0, 0},
    {0, 0, _image1911_size, 0, 0, 0, 0},
    {0, 0, _image1912_size, 0, 0, 0, 0},
    {0, 0, _image1913_size, 0, 0, 0, 0},
    {0, 0, _image1914_size, 0, 0, 0, 0},
    {0, 0, _image1915_size, 0, 0, 0, 0},
    {0, 0, _image1916_size, 0, 0, 0, 0},
    {0, 0, _image1917_size, 0, 0, 0, 0},
    {0, 0, _image1918_size, 0, 0, 0, 0},
    {0, 0, _image1919_size, 0, 0, 0, 0},
    {0, 0, _image1920_size, 0, 0, 0, 0},
    {0, 0, _image1921_size, 0, 0, 0, 0},
    {0, 0, _image1922_size, 0, 0, 0, 0},
    {0, 0, _image1923_size, 0, 0, 0, 0},
    {0, 0, _image1924_size, 0, 0, 0, 0},
    {0, 0, _image1925_size, 0, 0, 0, 0},
    {0, 0, _image1926_size, 0, 0, 0, 0},
    {0, 0, _image1927_size, 0, 0, 0, 0},
    {0, 0, _image1928_size, 0, 0, 0, 0},
    {0, 0, _image1929_size, 0, 0, 0, 0},
    {0, 0, _image1930_size, 0, 0, 0, 0},
    {0, 0, _image1931_size, 0, 0, 0, 0},
    {0, 0, _image1932_size, 0, 0, 0, 0},
    {0, 0, _image1933_size, 0, 0, 0, 0},
    {0, 0, _image1934_size, 0, 0, 0, 0},
    {0, 0, _image1935_size, 0, 0, 0, 0},
    {0, 0, _image1936_size, 0, 0, 0, 0},
    {0, 0, _image1937_size, 0, 0, 0, 0},
    {0, 0, _image1938_size, 0, 0, 0, 0},
    {0, 0, _image1939_size, 0, 0, 0, 0},
    {0, 0, _image1940_size, 0, 0, 0, 0},
    {0, 0, _image1941_size, 0, 0, 0, 0},
    {0, 0, _image1942_size, 0, 0, 0, 0},
    {0, 0, _image1943_size, 0, 0, 0, 0},
    {0, 0, _image1944_size, 0, 0, 0, 0},
    {0, 0, _image1945_size, 0, 0, 0, 0},
    {0, 0, _image1946_size, 0, 0, 0, 0},
    {0, 0, _image1947_size, 0, 0, 0, 0},
    {0, 0, _image1948_size, 0, 0, 0, 0},
    {0, 0, _image1949_size, 0, 0, 0, 0},
    {0, 0, _image1950_size, 0, 0, 0, 0},
    {0, 0, _image1951_size, 0, 0, 0, 0},
    {0, 0, _image1952_size, 0, 0, 0, 0},
    {0, 0, _image1953_size, 0, 0, 0, 0},
    {0, 0, _image1954_size, 0, 0, 0, 0},
    {0, 0, _image1955_size, 0, 0, 0, 0},
    {0, 0, _image1956_size, 0, 0, 0, 0},
    {0, 0, _image1957_size, 0, 0, 0, 0},
    {0, 0, _image1958_size, 0, 0, 0, 0},
    {0, 0, _image1959_size, 0, 0, 0, 0},
    {0, 0, _image1960_size, 0, 0, 0, 0},
    {0, 0, _image1961_size, 0, 0, 0, 0},
    {0, 0, _image1962_size, 0, 0, 0, 0},
    {0, 0, _image1963_size, 0, 0, 0, 0},
    {0, 0, _image1964_size, 0, 0, 0, 0},
    {0, 0, _image1965_size, 0, 0, 0, 0},
    {0, 0, _image1966_size, 0, 0, 0, 0},
    {0, 0, _image1967_size, 0, 0, 0, 0},
    {0, 0, _image1968_size, 0, 0, 0, 0},
    {0, 0, _image1969_size, 0, 0, 0, 0},
    {0, 0, _image1970_size, 0, 0, 0, 0},
    {0, 0, _image1971_size, 0, 0, 0, 0},
    {0, 0, _image1972_size, 0, 0, 0, 0},
    {0, 0, _image1973_size, 0, 0, 0, 0},
    {0, 0, _image1974_size, 0, 0, 0, 0},
    {0, 0, _image1975_size, 0, 0, 0, 0},
    {0, 0, _image1976_size, 0, 0, 0, 0},
    {0, 0, _image1977_size, 0, 0, 0, 0},
    {0, 0, _image1978_size, 0, 0, 0, 0},
    {0, 0, _image1979_size, 0, 0, 0, 0},
    {0, 0, _image1980_size, 0, 0, 0, 0},
    {0, 0, _image1981_size, 0, 0, 0, 0},
    {0, 0, _image1982_size, 0, 0, 0, 0},
    {0, 0, _image1983_size, 0, 0, 0, 0},
    {0, 0, _image1984_size, 0, 0, 0, 0},
    {0, 0, _image1985_size, 0, 0, 0, 0},
    {0, 0, _image1986_size, 0, 0, 0, 0},
    {0, 0, _image1987_size, 0, 0, 0, 0},
    {0, 0, _image1988_size, 0, 0, 0, 0},
    {0, 0, _image1989_size, 0, 0, 0, 0},
    {0, 0, _image1990_size, 0, 0, 0, 0},
    {0, 0, _image1991_size, 0, 0, 0, 0},
    {0, 0, _image1992_size, 0, 0, 0, 0},
    {0, 0, _image1993_size, 0, 0, 0, 0},
    {0, 0, _image1994_size, 0, 0, 0, 0},
    {0, 0, _image1995_size, 0, 0, 0, 0},
    {0, 0, _image1996_size, 0, 0, 0, 0},
    {0, 0, _image1997_size, 0, 0, 0, 0},
    {0, 0, _image1998_size, 0, 0, 0, 0},
    {0, 0, _image1999_size, 0, 0, 0, 0},
    {0, 0, _image2000_size, 0, 0, 0, 0},
    {0, 0, _image2001_size, 0, 0, 0, 0},
    {0, 0, _image2002_size, 0, 0, 0, 0},
    {0, 0, _image2003_size, 0, 0, 0, 0},
    {0, 0, _image2004_size, 0, 0, 0, 0},
    {0, 0, _image2005_size, 0, 0, 0, 0},
    {0, 0, _image2006_size, 0, 0, 0, 0},
    {0, 0, _image2007_size, 0, 0, 0, 0},
    {0, 0, _image2008_size, 0, 0, 0, 0},
    {0, 0, _image2009_size, 0, 0, 0, 0},
    {0, 0, _image2010_size, 0, 0, 0, 0},
    {0, 0, _image2011_size, 0, 0, 0, 0},
    {0, 0, _image2012_size, 0, 0, 0, 0},
    {0, 0, _image2013_size, 0, 0, 0, 0},
    {0, 0, _image2014_size, 0, 0, 0, 0},
    {0, 0, _image2015_size, 0, 0, 0, 0},
    {0, 0, _image2016_size, 0, 0, 0, 0},
    {0, 0, _image2017_size, 0, 0, 0, 0},
    {0, 0, _image2018_size, 0, 0, 0, 0},
    {0, 0, _image2019_size, 0, 0, 0, 0},
    {0, 0, _image2020_size, 0, 0, 0, 0},
    {0, 0, _image2021_size, 0, 0, 0, 0},
    {0, 0, _image2022_size, 0, 0, 0, 0},
    {0, 0, _image2023_size, 0, 0, 0, 0},
    {0, 0, _image2024_size, 0, 0, 0, 0},
    {0, 0, _image2025_size, 0, 0, 0, 0},
    {0, 0, _image2026_size, 0, 0, 0, 0},
    {0, 0, _image2027_size, 0, 0, 0, 0},
    {0, 0, _image2028_size, 0, 0, 0, 0},
    {0, 0, _image2029_size, 0, 0, 0, 0},
    {0, 0, _image2030_size, 0, 0, 0, 0},
    {0, 0, _image2031_size, 0, 0, 0, 0},
    {0, 0, _image2032_size, 0, 0, 0, 0},
    {0, 0, _image2033_size, 0, 0, 0, 0},
    {0, 0, _image2034_size, 0, 0, 0, 0},
    {0, 0, _image2035_size, 0, 0, 0, 0},
    {0, 0, _image2036_size, 0, 0, 0, 0},
    {0, 0, _image2037_size, 0, 0, 0, 0},
    {0, 0, _image2038_size, 0, 0, 0, 0},
    {0, 0, _image2039_size, 0, 0, 0, 0},
    {0, 0, _image2040_size, 0, 0, 0, 0},
    {0, 0, _image2041_size, 0, 0, 0, 0},
    {0, 0, _image2042_size, 0, 0, 0, 0},
    {0, 0, _image2043_size, 0, 0, 0, 0},
    {0, 0, _image2044_size, 0, 0, 0, 0},
    {0, 0, _image2045_size, 0, 0, 0, 0},
    {0, 0, _image2046_size, 0, 0, 0, 0},
    {0, 0, _image2047_size, 0, 0, 0, 0},
    {0, 0, _image2048_size, 0, 0, 0, 0},
    {0, 0, _image2049_size, 0, 0, 0, 0},
    {0, 0, _image2050_size, 0, 0, 0, 0},
    {0, 0, _image2051_size, 0, 0, 0, 0},
    {0, 0, _image2052_size, 0, 0, 0, 0},
    {0, 0, _image2053_size, 0, 0, 0, 0},
    {0, 0, _image2054_size, 0, 0, 0, 0},
    {0, 0, _image2055_size, 0, 0, 0, 0},
    {0, 0, _image2056_size, 0, 0, 0, 0},
    {0, 0, _image2057_size, 0, 0, 0, 0},
    {0, 0, _image2058_size, 0, 0, 0, 0},
    {0, 0, _image2059_size, 0, 0, 0, 0},
    {0, 0, _image2060_size, 0, 0, 0, 0},
    {0, 0, _image2061_size, 0, 0, 0, 0},
    {0, 0, _image2062_size, 0, 0, 0, 0},
    {0, 0, _image2063_size, 0, 0, 0, 0},
    {0, 0, _image2064_size, 0, 0, 0, 0},
    {0, 0, _image2065_size, 0, 0, 0, 0},
    {0, 0, _image2066_size, 0, 0, 0, 0},
    {0, 0, _image2067_size, 0, 0, 0, 0},
    {0, 0, _image2068_size, 0, 0, 0, 0},
    {0, 0, _image2069_size, 0, 0, 0, 0},
    {0, 0, _image2070_size, 0, 0, 0, 0},
    {0, 0, _image2071_size, 0, 0, 0, 0},
    {0, 0, _image2072_size, 0, 0, 0, 0},
    {0, 0, _image2073_size, 0, 0, 0, 0},
    {0, 0, _image2074_size, 0, 0, 0, 0},
    {0, 0, _image2075_size, 0, 0, 0, 0},
    {0, 0, _image2076_size, 0, 0, 0, 0},
    {0, 0, _image2077_size, 0, 0, 0, 0},
    {0, 0, _image2078_size, 0, 0, 0, 0},
    {0, 0, _image2079_size, 0, 0, 0, 0},
    {0, 0, _image2080_size, 0, 0, 0, 0},
    {0, 0, _image2081_size, 0, 0, 0, 0},
    {0, 0, _image2082_size, 0, 0, 0, 0},
    {0, 0, _image2083_size, 0, 0, 0, 0},
    {0, 0, _image2084_size, 0, 0, 0, 0},
    {0, 0, _image2085_size, 0, 0, 0, 0},
    {0, 0, _image2086_size, 0, 0, 0, 0},
    {0, 0, _image2087_size, 0, 0, 0, 0},
    {0, 0, _image2088_size, 0, 0, 0, 0},
    {0, 0, _image2089_size, 0, 0, 0, 0},
    {0, 0, _image2090_size, 0, 0, 0, 0},
    {0, 0, _image2091_size, 0, 0, 0, 0},
    {0, 0, _image2092_size, 0, 0, 0, 0},
    {0, 0, _image2093_size, 0, 0, 0, 0},
    {0, 0, _image2094_size, 0, 0, 0, 0},
    {0, 0, _image2095_size, 0, 0, 0, 0},
    {0, 0, _image2096_size, 0, 0, 0, 0},
    {0, 0, _image2097_size, 0, 0, 0, 0},
    {0, 0, _image2098_size, 0, 0, 0, 0},
    {0, 0, _image2099_size, 0, 0, 0, 0},
    {0, 0, _image2100_size, 0, 0, 0, 0},
    {0, 0, _image2101_size, 0, 0, 0, 0},
    {0, 0, _image2102_size, 0, 0, 0, 0},
    {0, 0, _image2103_size, 0, 0, 0, 0},
    {0, 0, _image2104_size, 0, 0, 0, 0},
    {0, 0, _image2105_size, 0, 0, 0, 0},
    {0, 0, _image2106_size, 0, 0, 0, 0},
    {0, 0, _image2107_size, 0, 0, 0, 0},
    {0, 0, _image2108_size, 0, 0, 0, 0},
    {0, 0, _image2109_size, 0, 0, 0, 0},
    {0, 0, _image2110_size, 0, 0, 0, 0},
    {0, 0, _image2111_size, 0, 0, 0, 0},
    {0, 0, _image2112_size, 0, 0, 0, 0},
    {0, 0, _image2113_size, 0, 0, 0, 0},
    {0, 0, _image2114_size, 0, 0, 0, 0},
    {0, 0, _image2115_size, 0, 0, 0, 0},
    {0, 0, _image2116_size, 0, 0, 0, 0},
    {0, 0, _image2117_size, 0, 0, 0, 0},
    {0, 0, _image2118_size, 0, 0, 0, 0},
    {0, 0, _image2119_size, 0, 0, 0, 0},
    {0, 0, _image2120_size, 0, 0, 0, 0},
    {0, 0, _image2121_size, 0, 0, 0, 0},
    {0, 0, _image2122_size, 0, 0, 0, 0},
    {0, 0, _image2123_size, 0, 0, 0, 0},
    {0, 0, _image2124_size, 0, 0, 0, 0},
    {0, 0, _image2125_size, 0, 0, 0, 0},
    {0, 0, _image2126_size, 0, 0, 0, 0},
    {0, 0, _image2127_size, 0, 0, 0, 0},
    {0, 0, _image2128_size, 0, 0, 0, 0},
    {0, 0, _image2129_size, 0, 0, 0, 0},
    {0, 0, _image2130_size, 0, 0, 0, 0},
    {0, 0, _image2131_size, 0, 0, 0, 0},
    {0, 0, _image2132_size, 0, 0, 0, 0},
    {0, 0, _image2133_size, 0, 0, 0, 0},
    {0, 0, _image2134_size, 0, 0, 0, 0},
    {0, 0, _image2135_size, 0, 0, 0, 0},
    {0, 0, _image2136_size, 0, 0, 0, 0},
    {0, 0, _image2137_size, 0, 0, 0, 0},
    {0, 0, _image2138_size, 0, 0, 0, 0},
    {0, 0, _image2139_size, 0, 0, 0, 0},
    {0, 0, _image2140_size, 0, 0, 0, 0},
    {0, 0, _image2141_size, 0, 0, 0, 0},
    {0, 0, _image2142_size, 0, 0, 0, 0},
    {0, 0, _image2143_size, 0, 0, 0, 0},
    {0, 0, _image2144_size, 0, 0, 0, 0},
    {0, 0, _image2145_size, 0, 0, 0, 0},
    {0, 0, _image2146_size, 0, 0, 0, 0},
    {0, 0, _image2147_size, 0, 0, 0, 0},
    {0, 0, _image2148_size, 0, 0, 0, 0},
    {0, 0, _image2149_size, 0, 0, 0, 0},
    {0, 0, _image2150_size, 0, 0, 0, 0},
    {0, 0, _image2151_size, 0, 0, 0, 0},
    {0, 0, _image2152_size, 0, 0, 0, 0},
    {0, 0, _image2153_size, 0, 0, 0, 0},
    {0, 0, _image2154_size, 0, 0, 0, 0},
    {0, 0, _image2155_size, 0, 0, 0, 0},
    {0, 0, _image2156_size, 0, 0, 0, 0},
    {0, 0, _image2157_size, 0, 0, 0, 0},
    {0, 0, _image2158_size, 0, 0, 0, 0},
    {0, 0, _image2159_size, 0, 0, 0, 0},
    {0, 0, _image2160_size, 0, 0, 0, 0},
    {0, 0, _image2161_size, 0, 0, 0, 0},
    {0, 0, _image2162_size, 0, 0, 0, 0},
    {0, 0, _image2163_size, 0, 0, 0, 0},
    {0, 0, _image2164_size, 0, 0, 0, 0},
    {0, 0, _image2165_size, 0, 0, 0, 0},
    {0, 0, _image2166_size, 0, 0, 0, 0},
    {0, 0, _image2167_size, 0, 0, 0, 0},
    {0, 0, _image2168_size, 0, 0, 0, 0},
    {0, 0, _image2169_size, 0, 0, 0, 0},
    {0, 0, _image2170_size, 0, 0, 0, 0},
    {0, 0, _image2171_size, 0, 0, 0, 0},
    {0, 0, _image2172_size, 0, 0, 0, 0},
    {0, 0, _image2173_size, 0, 0, 0, 0},
    {0x11, 0, _image2174_size, 0, 0, 0, 0},
    {0x11, 0, _image2175_size, 0, 0, 0, 0},
    {0x11, 0, _image2176_size, 0, 0, 0, 0},
    {0, 0, _image2177_size, 0, 0, 0, 0},
    {0, 0, _image2178_size, 0, 0, 0, 0},
    {0, 0, _image2179_size, 0, 0, 0, 0},
    {0, 0, _image2180_size, 0, 0, 0, 0},
    {0, 0, _image2181_size, 0, 0, 0, 0},
    {0, 0, _image2182_size, 0, 0, 0, 0},
    {0, 0, _image2183_size, 0, 0, 0, 0},
    {0, 0, _image2184_size, 0, 0, 0, 0},
    {0, 0, _image2185_size, 0, 0, 0, 0},
    {0, 0, _image2186_size, 0, 0, 0, 0},
    {0, 0, _image2187_size, 0, 0, 0, 0},
    {0, 0, _image2188_size, 0, 0, 0, 0},
    {0, 0, _image2189_size, 0, 0, 0, 0},
    {0, 0, _image2190_size, 0, 0, 0, 0},
    {0, 0, _image2191_size, 0, 0, 0, 0},
    {0, 0, _image2192_size, 0, 0, 0, 0},
    {0, 0, _image2193_size, 0, 0, 0, 0},
    {0, 0, _image2194_size, 0, 0, 0, 0},
    {0, 0, _image2195_size, 0, 0, 0, 0},
    {0, 0, _image2196_size, 0, 0, 0, 0},
    {0, 0, _image2197_size, 0, 0, 0, 0},
    {0, 0, _image2198_size, 0, 0, 0, 0},
    {0, 0, _image2199_size, 0, 0, 0, 0},
    {0, 0, _image2200_size, 0, 0, 0, 0},
    {0, 0, _image2201_size, 0, 0, 0, 0},
    {0, 0, _image2202_size, 0, 0, 0, 0},
    {0, 0, _image2203_size, 0, 0, 0, 0},
    {0, 0, _image2204_size, 0, 0, 0, 0},
    {0, 0, _image2205_size, 0, 0, 0, 0},
    {0, 0, _image2206_size, 0, 0, 0, 0},
    {0, 0, _image2207_size, 0, 0, 0, 0},
    {0, 0, _image2208_size, 0, 0, 0, 0},
    {0, 0, _image2209_size, 0, 0, 0, 0},
    {0, 0, _image2210_size, 0, 0, 0, 0},
    {0, 0, _image2211_size, 0, 0, 0, 0},
    {0, 0, _image2212_size, 0, 0, 0, 0},
    {0, 0, _image2213_size, 0, 0, 0, 0},
    {0, 0, _image2214_size, 0, 0, 0, 0},
    {0, 0, _image2215_size, 0, 0, 0, 0},
    {0, 0, _image2216_size, 0, 0, 0, 0},
    {0, 0, _image2217_size, 0, 0, 0, 0},
    {0, 0, _image2218_size, 0, 0, 0, 0},
    {0, 0, _image2219_size, 0, 0, 0, 0},
    {0, 0, _image2220_size, 0, 0, 0, 0},
    {0, 0, _image2221_size, 0, 0, 0, 0},
    {0, 0, _image2222_size, 0, 0, 0, 0},
    {0, 0, _image2223_size, 0, 0, 0, 0},
    {0, 0, _image2224_size, 0, 0, 0, 0},
    {0, 0, _image2225_size, 0, 0, 0, 0},
    {0, 0, _image2226_size, 0, 0, 0, 0},
    {0, 0, _image2227_size, 0, 0, 0, 0},
    {0, 0, _image2228_size, 0, 0, 0, 0},
    {0, 0, _image2229_size, 0, 0, 0, 0},
    {0, 0, _image2230_size, 0, 0, 0, 0},
    {0, 0, _image2231_size, 0, 0, 0, 0},
    {0, 0, _image2232_size, 0, 0, 0, 0},
    {0, 0, _image2233_size, 0, 0, 0, 0},
    {0, 0, _image2234_size, 0, 0, 0, 0},
    {0, 0, _image2235_size, 0, 0, 0, 0},
    {0, 0, _image2236_size, 0, 0, 0, 0},
    {0, 0, _image2237_size, 0, 0, 0, 0},
    {0, 0, _image2238_size, 0, 0, 0, 0},
    {0, 0, _image2239_size, 0, 0, 0, 0},
    {0, 0, _image2240_size, 0, 0, 0, 0},
    {0, 0, _image2241_size, 0, 0, 0, 0},
    {0, 0, _image2242_size, 0, 0, 0, 0},
    {0, 0, _image2243_size, 0, 0, 0, 0},
    {0, 0, _image2244_size, 0, 0, 0, 0},
    {0, 0, _image2245_size, 0, 0, 0, 0},
    {0, 0, _image2246_size, 0, 0, 0, 0},
    {0, 0, _image2247_size, 0, 0, 0, 0},
    {0, 0, _image2248_size, 0, 0, 0, 0},
    {0, 0, _image2249_size, 0, 0, 0, 0},
    {0, 0, _image2250_size, 0, 0, 0, 0},
    {0, 0, _image2251_size, 0, 0, 0, 0},
    {0, 0, _image2252_size, 0, 0, 0, 0},
    {0, 0, _image2253_size, 0, 0, 0, 0},
    {0, 0, _image2254_size, 0, 0, 0, 0},
    {0, 0, _image2255_size, 0, 0, 0, 0},
    {0, 0, _image2256_size, 0, 0, 0, 0},
    {0, 0, _image2257_size, 0, 0, 0, 0},
    {0, 0, _image2258_size, 0, 0, 0, 0},
    {0, 0, _image2259_size, 0, 0, 0, 0},
    {0, 0, _image2260_size, 0, 0, 0, 0},
    {0x33, 0, _image2261_size, 0, 0, 0, 0},
    {0, 0, _image2262_size, 0, 0, 0, 0},
    {0, 0, _image2263_size, 0, 0, 0, 0},
    {0, 0, _image2264_size, 0, 0, 0, 0},
    {0, 0, _image2265_size, 0, 0, 0, 0},
    {0, 0, _image2266_size, 0, 0, 0, 0},
    {0, 0, _image2267_size, 0, 0, 0, 0},
    {0, 0, _image2268_size, 0, 0, 0, 0},
    {0, 0, _image2269_size, 0, 0, 0, 0},
    {0, 0, _image2270_size, 0, 0, 0, 0},
    {0, 0, _image2271_size, 0, 0, 0, 0},
    {0, 0, _image2272_size, 0, 0, 0, 0},
    {0, 0, _image2273_size, 0, 0, 0, 0},
    {0, 0, _image2274_size, 0, 0, 0, 0},
    {0, 0, _image2275_size, 0, 0, 0, 0},
    {0, 0, _image2276_size, 0, 0, 0, 0},
    {0, 0, _image2277_size, 0, 0, 0, 0},
    {0x22, 0, _image2278_size, 0, 0, 0, 0},
    {0, 0, _image2279_size, 0, 0, 0, 0},
    {0x22, 0, _image2280_size, 0, 0, 0, 0},
    {0x22, 0, _image2281_size, 0, 0, 0, 0},
    {0, 0, _image2282_size, 0, 0, 0, 0},
    {0x22, 0, _image2283_size, 0, 0, 0, 0},
    {0, 0, _image2284_size, 0, 0, 0, 0},
    {0, 0, _image2285_size, 0, 0, 0, 0},
    {0, 0, _image2286_size, 0, 0, 0, 0},
    {0, 0, _image2287_size, 0, 0, 0, 0},
    {0, 0, _image2288_size, 0, 0, 0, 0},
    {0, 0, _image2289_size, 0, 0, 0, 0},
    {0, 0, _image2290_size, 0, 0, 0, 0},
    {0, 0, _image2291_size, 0, 0, 0, 0},
    {0, 0, _image2292_size, 0, 0, 0, 0},
    {0, 0, _image2293_size, 0, 0, 0, 0},
    {0, 0, _image2294_size, 0, 0, 0, 0},
    {0xAA, 0, _image2295_size, 0, 0, 0, 0},
    {0xAA, 0, _image2296_size, 0, 0, 0, 0},
    {0xAA, 0, _image2297_size, 0, 0, 0, 0},
    {0, 0, _image2298_size, 0, 0, 0, 0},
    {0xAA, 0, _image2299_size, 0, 0, 0, 0},
    {0xAA, 0, _image2300_size, 0, 0, 0, 0},
    {0x33, 0, _image2301_size, 0, 0, 0, 0},
    {0x77, 0, _image2302_size, 0, 0, 0, 0},
    {0x77, 0, _image2303_size, 0, 0, 0, 0},
    {0x77, 0, _image2304_size, 0, 0, 0, 0},
    {0x77, 0, _image2305_size, 0, 0, 0, 0},
    {0xAA, 0, _image2306_size, 0, 0, 0, 0},
    {0xAA, 0, _image2307_size, 0, 0, 0, 0},
    {0xAA, 0, _image2308_size, 0, 0, 0, 0},
    {0xAA, 0, _image2309_size, 0, 0, 0, 0},
    {0xAA, 0, _image2310_size, 0, 0, 0, 0},
    {0x22, 0, _image2311_size, 0, 0, 0, 0},
    {0x11, 0, _image2312_size, 0, 0, 0, 0},
    {0, 0, _image2313_size, 0, 0, 0, 0},
    {0x77, 0, _image2314_size, 0, 0, 0, 0},
    {0x77, 0, _image2315_size, 0, 0, 0, 0},
    {0xAA, 0, _image2316_size, 0, 0, 0, 0},
    {0, 0, _image2317_size, 0, 0, 0, 0},
    {0xAA, 0, _image2318_size, 0, 0, 0, 0},
    {0xAA, 0, _image2319_size, 0, 0, 0, 0},
    {0xAA, 0, _image2320_size, 0, 0, 0, 0},
    {0xAA, 0, _image2321_size, 0, 0, 0, 0},
    {0, 0, _image2322_size, 0, 0, 0, 0},
    {0x33, 0, _image2323_size, 0, 0, 0, 0},
    {0x33, 0, _image2324_size, 0, 0, 0, 0},
    {0, 0, _image2325_size, 0, 0, 0, 0},
    {0, 0, _image2326_size, 0, 0, 0, 0},
    {0, 0, _image2327_size, 0, 0, 0, 0},
    {0, 0, _image2328_size, 0, 0, 0, 0},
    {0, 0, _image2329_size, 0, 0, 0, 0},
    {0, 0, _image2330_size, 0, 0, 0, 0},
    {0, 0, _image2331_size, 0, 0, 0, 0},
    {0, 0, _image2332_size, 0, 0, 0, 0},
    {0, 0, _image2333_size, 0, 0, 0, 0},
    {0, 0, _image2334_size, 0, 0, 0, 0},
    {0, 0, _image2335_size, 0, 0, 0, 0},
    {0x22, 0, _image2336_size, 0, 0, 0, 0},
    {0x22, 0, _image2337_size, 0, 0, 0, 0},
    {0x22, 0, _image2338_size, 0, 0, 0, 0},
    {0x22, 0, _image2339_size, 0, 0, 0, 0},
    {0x33, 0, _image2340_size, 0, 0, 0, 0},
    {0, 0, _image2341_size, 0, 0, 0, 0},
    {0, 0, _image2342_size, 0, 0, 0, 0},
    {0x55, 0, _image2343_size, 0, 0, 0, 0},
    {0x55, 0, _image2344_size, 0, 0, 0, 0},
    {0, 0, _image2345_size, 0, 0, 0, 0},
    {0, 0, _image2346_size, 0, 0, 0, 0},
    {0, 0, _image2347_size, 0, 0, 0, 0},
    {0, 0, _image2348_size, 0, 0, 0, 0},
    {0, 0, _image2349_size, 0, 0, 0, 0},
    {0, 0, _image2350_size, 0, 0, 0, 0},
    {0, 0, _image2351_size, 0, 0, 0, 0},
    {0, 0, _image2352_size, 0, 0, 0, 0},
    {0, 0, _image2353_size, 0, 0, 0, 0},
    {0, 0, _image2354_size, 0, 0, 0, 0},
    {0, 0, _image2355_size, 0, 0, 0, 0},
    {0, 0, _image2356_size, 0, 0, 0, 0},
    {0, 0, _image2357_size, 0, 0, 0, 0},
    {0, 0, _image2358_size, 0, 0, 0, 0},
    {0, 0, _image2359_size, 0, 0, 0, 0},
    {0, 0, _image2360_size, 0, 0, 0, 0},
    {0, 0, _image2361_size, 0, 0, 0, 0},
    {0, 0, _image2362_size, 0, 0, 0, 0},
    {0, 0, _image2363_size, 0, 0, 0, 0},
    {0, 0, _image2364_size, 0, 0, 0, 0},
    {0, 0, _image2365_size, 0, 0, 0, 0},
    {0, 0, _image2366_size, 0, 0, 0, 0},
    {0, 0, _image2367_size, 0, 0, 0, 0},
    {0, 0, _image2368_size, 0, 0, 0, 0},
    {0, 0, _image2369_size, 0, 0, 0, 0},
    {0x11, 0, _image2370_size, 0, 0, 0, 0},
    {0x11, 0, _image2371_size, 0, 0, 0, 0},
    {0x44, 0, _image2372_size, 0, 0, 0, 0},
    {0x44, 0, _image2373_size, 0, 0, 0, 0},
    {0, 0, _image2374_size, 0, 0, 0, 0},
    {0, 0, _image2375_size, 0, 0, 0, 0},
    {0xAA, 0, _image2376_size, 0, 0, 0, 0},
    {0x11, 0, _image2377_size, 0, 0, 0, 0},
    {0x33, 0, _image2378_size, 0, 0, 0, 0},
    {0, 0, _image2379_size, 0, 0, 0, 0},
    {0x22, 0, _image2380_size, 0, 0, 0, 0},
    {0x33, 0, _image2381_size, 0, 0, 0, 0},
    {0x44, 0, _image2382_size, 0, 0, 0, 0},
    {0, 0, _image2383_size, 0, 0, 0, 0},
    {0, 0, _image2384_size, 0, 0, 0, 0},
    {0, 0, _image2385_size, 0, 0, 0, 0},
    {0x33, 0, _image2386_size, 0, 0, 0, 0},
    {0, 0, _image2387_size, 0, 0, 0, 0},
    {0, 0, _image2388_size, 0, 0, 0, 0},
    {0x44, 0, _image2389_size, 0, 0, 0, 0},
    {0, 0, _image2390_size, 0, 0, 0, 0},
    {0xAA, 0, _image2391_size, 0, 0, 0, 0},
    {0, 0, _image2392_size, 0, 0, 0, 0},
    {0x44, 0, _image2393_size, 0, 0, 0, 0},
    {0, 0, _image2394_size, 0, 0, 0, 0},
    {0, 0, _image2395_size, 0, 0, 0, 0},
    {0, 0, _image2396_size, 0, 0, 0, 0},
    {0x33, 0, _image2397_size, 0, 0, 0, 0},
    {0, 0, _image2398_size, 0, 0, 0, 0},
    {0xAA, 0, _image2399_size, 0, 0, 0, 0},
    {0x33, 0, _image2400_size, 0, 0, 0, 0},
    {0x33, 0, _image2401_size, 0, 0, 0, 0},
    {0x44, 0, _image2402_size, 0, 0, 0, 0},
    {0x11, 0, _image2403_size, 0, 0, 0, 0},
    {0, 0, _image2404_size, 0, 0, 0, 0},
    {0x22, 0, _image2405_size, 0, 0, 0, 0},
    {0x11, 0, _image2406_size, 0, 0, 0, 0},
    {0x22, 0, _image2407_size, 0, 0, 0, 0},
    {0, 0, _image2408_size, 0, 0, 0, 0},
    {0x11, 0, _image2409_size, 0, 0, 0, 0},
    {0, 0, _image2410_size, 0, 0, 0, 0},
    {0x11, 0, _image2411_size, 0, 0, 0, 0},
    {0, 0, _image2412_size, 0, 0, 0, 0},
    {0, 0, _image2413_size, 0, 0, 0, 0},
    {0x11, 0, _image2414_size, 0, 0, 0, 0},
    {0x44, 0, _image2415_size, 0, 0, 0, 0},
    {0, 0, _image2416_size, 0, 0, 0, 0},
    {0, 0, _image2417_size, 0, 0, 0, 0},
    {0xAA, 0, _image2418_size, 0, 0, 0, 0},
    {0, 0, _image2419_size, 0, 0, 0, 0},
    {0, 0, _image2420_size, 0, 0, 0, 0},
    {0, 0, _image2421_size, 0, 0, 0, 0},
    {0, 0, _image2422_size, 0, 0, 0, 0},
    {0, 0, _image2423_size, 0, 0, 0, 0},
    {0, 0, _image2424_size, 0, 0, 0, 0},
    {0, 0, _image2425_size, 0, 0, 0, 0},
    {0, 0, _image2426_size, 0, 0, 0, 0},
    {0, 0, _image2427_size, 0, 0, 0, 0},
    {0, 0, _image2428_size, 0, 0, 0, 0},
    {0x44, 0, _image2429_size, 0, 0, 0, 0},
    {0x33, 0, _image2430_size, 0, 0, 0, 0},
    {0x33, 0, _image2431_size, 0, 0, 0, 0},
    {0, 0, _image2432_size, 0, 0, 0, 0},
    {0, 0, _image2433_size, 0, 0, 0, 0},
    {0, 0, _image2434_size, 0, 0, 0, 0},
    {0, 0, _image2435_size, 0, 0, 0, 0},
    {0, 0, _image2436_size, 0, 0, 0, 0},
    {0, 0, _image2437_size, 0, 0, 0, 0},
    {0, 0, _image2438_size, 0, 0, 0, 0},
    {0, 0, _image2439_size, 0, 0, 0, 0},
    {0, 0, _image2440_size, 0, 0, 0, 0},
    {0, 0, _image2441_size, 0, 0, 0, 0},
    {0, 0, _image2442_size, 0, 0, 0, 0},
    {0, 0, _image2443_size, 0, 0, 0, 0},
    {0, 0, _image2444_size, 0, 0, 0, 0},
    {0, 0, _image2445_size, 0, 0, 0, 0},
    {0, 0, _image2446_size, 0, 0, 0, 0},
    {0, 0, _image2447_size, 0, 0, 0, 0},
    {0, 0, _image2448_size, 0, 0, 0, 0},
    {0, 0, _image2449_size, 0, 0, 0, 0},
    {0, 0, _image2450_size, 0, 0, 0, 0},
    {0, 0, _image2451_size, 0, 0, 0, 0},
    {0, 0, _image2452_size, 0, 0, 0, 0},
    {0, 0, _image2453_size, 0, 0, 0, 0},
    {0, 0, _image2454_size, 0, 0, 0, 0},
    {0, 0, _image2455_size, 0, 0, 0, 0},
    {0, 0, _image2456_size, 0, 0, 0, 0},
    {0, 0, _image2457_size, 0, 0, 0, 0},
    {0, 0, _image2458_size, 0, 0, 0, 0},
    {0, 0, _image2459_size, 0, 0, 0, 0},
    {0, 0, _image2460_size, 0, 0, 0, 0},
    {0, 0, _image2461_size, 0, 0, 0, 0},
    {0, 0, _image2462_size, 0, 0, 0, 0},
    {0, 0, _image2463_size, 0, 0, 0, 0},
    {0, 0, _image2464_size, 0, 0, 0, 0},
    {0, 0, _image2465_size, 0, 0, 0, 0},
    {0, 0, _image2466_size, 0, 0, 0, 0},
    {0, 0, _image2467_size, 0, 0, 0, 0},
    {0, 0, _image2468_size, 0, 0, 0, 0},
    {0, 0, _image2469_size, 0, 0, 0, 0},
    {0, 0, _image2470_size, 0, 0, 0, 0},
    {0, 0, _image2471_size, 0, 0, 0, 0},
    {0, 0, _image2472_size, 0, 0, 0, 0},
    {0, 0, _image2473_size, 0, 0, 0, 0},
    {0, 0, _image2474_size, 0, 0, 0, 0},
    {0x11, 0, _image2475_size, 0, 0, 0, 0},
    {0, 0, _image2476_size, 0, 0, 0, 0},
    {0, 0, _image2477_size, 0, 0, 0, 0},
    {0, 0, _image2478_size, 0, 0, 0, 0},
    {0, 0, _image2479_size, 0, 0, 0, 0},
    {0, 0, _image2480_size, 0, 0, 0, 0},
    {0, 0, _image2481_size, 0, 0, 0, 0},
    {0, 0, _image2482_size, 0, 0, 0, 0},
    {0, 0, _image2483_size, 0, 0, 0, 0},
    {0, 0, _image2484_size, 0, 0, 0, 0},
    {0, 0, _image2485_size, 0, 0, 0, 0},
    {0, 0, _image2486_size, 0, 0, 0, 0},
    {0, 0, _image2487_size, 0, 0, 0, 0},
    {0, 0, _image2488_size, 0, 0, 0, 0},
    {0, 0, _image2489_size, 0, 0, 0, 0},
    {0, 0, _image2490_size, 0, 0, 0, 0},
    {0, 0, _image2491_size, 0, 0, 0, 0},
    {0, 0, _image2492_size, 0, 0, 0, 0},
    {0, 0, _image2493_size, 0, 0, 0, 0},
    {0, 0, _image2494_size, 0, 0, 0, 0},
    {0, 0, _image2495_size, 0, 0, 0, 0},
    {0, 0, _image2496_size, 0, 0, 0, 0},
    {0, 0, _image2497_size, 0, 0, 0, 0},
    {0, 0, _image2498_size, 0, 0, 0, 0},
    {0, 0, _image2499_size, 0, 0, 0, 0},
    {0, 0, _image2500_size, 0, 0, 0, 0},
    {0, 0, _image2501_size, 0, 0, 0, 0},
    {0, 0, _image2502_size, 0, 0, 0, 0},
    {0, 0, _image2503_size, 0, 0, 0, 0},
    {0, 0, _image2504_size, 0, 0, 0, 0},
    {0, 0, _image2505_size, 0, 0, 0, 0},
    {0, 0, _image2506_size, 0, 0, 0, 0},
    {0, 0, _image2507_size, 0, 0, 0, 0},
    {0, 0, _image2508_size, 0, 0, 0, 0},
    {0, 0, _image2509_size, 0, 0, 0, 0},
    {0, 0, _image2510_size, 0, 0, 0, 0},
    {0, 0, _image2511_size, 0, 0, 0, 0},
    {0, 0, _image2512_size, 0, 0, 0, 0},
    {0, 0, _image2513_size, 0, 0, 0, 0},
    {0, 0, _image2514_size, 0, 0, 0, 0},
    {0, 0, _image2515_size, 0, 0, 0, 0},
    {0, 0, _image2516_size, 0, 0, 0, 0},
    {0, 0, _image2517_size, 0, 0, 0, 0},
    {0, 0, _image2518_size, 0, 0, 0, 0},
    {0, 0, _image2519_size, 0, 0, 0, 0},
    {0, 0, _image2520_size, 0, 0, 0, 0},
    {0, 0, _image2521_size, 0, 0, 0, 0},
    {0, 0, _image2522_size, 0, 0, 0, 0},
    {0, 0, _image2523_size, 0, 0, 0, 0},
    {0, 0, _image2524_size, 0, 0, 0, 0},
    {0, 0, _image2525_size, 0, 0, 0, 0},
    {0, 0, _image2526_size, 0, 0, 0, 0},
    {0, 0, _image2527_size, 0, 0, 0, 0},
    {0, 0, _image2528_size, 0, 0, 0, 0},
    {0, 0, _image2529_size, 0, 0, 0, 0},
    {0, 0, _image2530_size, 0, 0, 0, 0},
    {0, 0, _image2531_size, 0, 0, 0, 0},
    {0, 0, _image2532_size, 0, 0, 0, 0},
    {0, 0, _image2533_size, 0, 0, 0, 0},
    {0, 0, _image2534_size, 0, 0, 0, 0},
    {0, 0, _image2535_size, 0, 0, 0, 0},
    {0, 0, _image2536_size, 0, 0, 0, 0},
    {0, 0, _image2537_size, 0, 0, 0, 0},
    {0, 0, _image2538_size, 0, 0, 0, 0},
    {0, 0, _image2539_size, 0, 0, 0, 0},
    {0, 0, _image2540_size, 0, 0, 0, 0},
    {0, 0, _image2541_size, 0, 0, 0, 0},
    {0, 0, _image2542_size, 0, 0, 0, 0},
    {0, 0, _image2543_size, 0, 0, 0, 0},
    {0, 0, _image2544_size, 0, 0, 0, 0},
    {0, 0, _image2545_size, 0, 0, 0, 0},
    {0, 0, _image2546_size, 0, 0, 0, 0},
    {0, 0, _image2547_size, 0, 0, 0, 0},
    {0, 0, _image2548_size, 0, 0, 0, 0},
    {0, 0, _image2549_size, 0, 0, 0, 0},
    {0, 0, _image2550_size, 0, 0, 0, 0},
    {0, 0, _image2551_size, 0, 0, 0, 0},
    {0, 0, _image2552_size, 0, 0, 0, 0},
    {0, 0, _image2553_size, 0, 0, 0, 0},
    {0, 0, _image2554_size, 0, 0, 0, 0},
    {0, 0, _image2555_size, 0, 0, 0, 0},
    {0, 0, _image2556_size, 0, 0, 0, 0},
    {0, 0, _image2557_size, 0, 0, 0, 0},
    {0, 0, _image2558_size, 0, 0, 0, 0},
    {0, 0, _image2559_size, 0, 0, 0, 0},
    {0, 0, _image2560_size, 0, 0, 0, 0},
    {0, 0, _image2561_size, 0, 0, 0, 0},
    {0, 0, _image2562_size, 0, 0, 0, 0},
    {0, 0, _image2563_size, 0, 0, 0, 0},
    {0, 0, _image2564_size, 0, 0, 0, 0},
    {0, 0, _image2565_size, 0, 0, 0, 0},
    {0, 0, _image2566_size, 0, 0, 0, 0},
    {0, 0, _image2567_size, 0, 0, 0, 0},
    {0, 0, _image2568_size, 0, 0, 0, 0},
    {0, 0, _image2569_size, 0, 0, 0, 0},
    {0, 0, _image2570_size, 0, 0, 0, 0},
    {0, 0, _image2571_size, 0, 0, 0, 0},
    {0, 0, _image2572_size, 0, 0, 0, 0},
    {0, 0, _image2573_size, 0, 0, 0, 0},
    {0, 0, _image2574_size, 0, 0, 0, 0},
    {0, 0, _image2575_size, 0, 0, 0, 0},
    {0, 0, _image2576_size, 0, 0, 0, 0},
    {0, 0, _image2577_size, 0, 0, 0, 0},
    {0, 0, _image2578_size, 0, 0, 0, 0},
    {0, 0, _image2579_size, 0, 0, 0, 0},
    {0, 0, _image2580_size, 0, 0, 0, 0},
    {0, 0, _image2581_size, 0, 0, 0, 0},
    {0, 0, _image2582_size, 0, 0, 0, 0},
    {0, 0, _image2583_size, 0, 0, 0, 0},
    {0, 0, _image2584_size, 0, 0, 0, 0},
    {0, 0, _image2585_size, 0, 0, 0, 0},
    {0, 0, _image2586_size, 0, 0, 0, 0},
    {0, 0, _image2587_size, 0, 0, 0, 0},
    {0, 0, _image2588_size, 0, 0, 0, 0},
    {0, 0, _image2589_size, 0, 0, 0, 0},
    {0, 0, _image2590_size, 0, 0, 0, 0},
    {0, 0, _image2591_size, 0, 0, 0, 0},
    {0, 0, _image2592_size, 0, 0, 0, 0},
    {0, 0, _image2593_size, 0, 0, 0, 0},
    {0, 0, _image2594_size, 0, 0, 0, 0},
    {0, 0, _image2595_size, 0, 0, 0, 0},
    {0, 0, _image2596_size, 0, 0, 0, 0},
    {0, 0, _image2597_size, 0, 0, 0, 0},
    {0, 0, _image2598_size, 0, 0, 0, 0},
    {0, 0, _image2599_size, 0, 0, 0, 0},
    {0, 0, _image2600_size, 0, 0, 0, 0},
    {0, 0, _image2601_size, 0, 0, 0, 0},
    {0, 0, _image2602_size, 0, 0, 0, 0},
    {0, 0, _image2603_size, 0, 0, 0, 0},
    {0, 0, _image2604_size, 0, 0, 0, 0},
    {0, 0, _image2605_size, 0, 0, 0, 0},
    {0, 0, _image2606_size, 0, 0, 0, 0},
    {0, 0, _image2607_size, 0, 0, 0, 0},
    {0, 0, _image2608_size, 0, 0, 0, 0},
    {0, 0, _image2609_size, 0, 0, 0, 0},
    {0, 0, _image2610_size, 0, 0, 0, 0},
    {0, 0, _image2611_size, 0, 0, 0, 0},
    {0, 0, _image2612_size, 0, 0, 0, 0},
    {0, 0, _image2613_size, 0, 0, 0, 0},
    {0, 0, _image2614_size, 0, 0, 0, 0},
    {0, 0, _image2615_size, 0, 0, 0, 0},
    {0, 0, _image2616_size, 0, 0, 0, 0},
    {0, 0, _image2617_size, 0, 0, 0, 0},
    {0, 0, _image2618_size, 0, 0, 0, 0},
    {0, 0, _image2619_size, 0, 0, 0, 0},
    {0, 0, _image2620_size, 0, 0, 0, 0},
    {0, 0, _image2621_size, 0, 0, 0, 0},
    {0, 0, _image2622_size, 0, 0, 0, 0},
    {0, 0, _image2623_size, 0, 0, 0, 0},
    {0, 0, _image2624_size, 0, 0, 0, 0},
    {0, 0, _image2625_size, 0, 0, 0, 0},
    {0, 0, _image2626_size, 0, 0, 0, 0},
    {0, 0, _image2627_size, 0, 0, 0, 0},
    {0, 0, _image2628_size, 0, 0, 0, 0},
    {0, 0, _image2629_size, 0, 0, 0, 0},
    {0, 0, _image2630_size, 0, 0, 0, 0},
    {0, 0, _image2631_size, 0, 0, 0, 0},
    {0, 0, _image2632_size, 0, 0, 0, 0},
    {0, 0, _image2633_size, 0, 0, 0, 0},
    {0, 0, _image2634_size, 0, 0, 0, 0},
    {0, 0, _image2635_size, 0, 0, 0, 0},
    {0, 0, _image2636_size, 0, 0, 0, 0},
    {0, 0, _image2637_size, 0, 0, 0, 0},
    {0, 0, _image2638_size, 0, 0, 0, 0},
    {0, 0, _image2639_size, 0, 0, 0, 0},
    {0, 0, _image2640_size, 0, 0, 0, 0},
    {0, 0, _image2641_size, 0, 0, 0, 0},
    {0, 0, _image2642_size, 0, 0, 0, 0},
    {0, 0, _image2643_size, 0, 0, 0, 0},
    {0, 0, _image2644_size, 0, 0, 0, 0},
    {0, 0, _image2645_size, 0, 0, 0, 0},
    {0, 0, _image2646_size, 0, 0, 0, 0},
    {0, 0, _image2647_size, 0, 0, 0, 0},
    {0, 0, _image2648_size, 0, 0, 0, 0},
    {0, 0, _image2649_size, 0, 0, 0, 0},
    {0, 0, _image2650_size, 0, 0, 0, 0},
    {0, 0, _image2651_size, 0, 0, 0, 0},
    {0, 0, _image2652_size, 0, 0, 0, 0},
    {0, 0, _image2653_size, 0, 0, 0, 0},
    {0, 0, _image2654_size, 0, 0, 0, 0},
    {0, 0, _image2655_size, 0, 0, 0, 0},
    {0, 0, _image2656_size, 0, 0, 0, 0},
    {0, 0, _image2657_size, 0, 0, 0, 0},
    {0, 0, _image2658_size, 0, 0, 0, 0},
    {0, 0, _image2659_size, 0, 0, 0, 0},
    {0, 0, _image2660_size, 0, 0, 0, 0},
    {0, 0, _image2661_size, 0, 0, 0, 0},
    {0, 0, _image2662_size, 0, 0, 0, 0},
    {0, 0, _image2663_size, 0, 0, 0, 0},
    {0, 0, _image2664_size, 0, 0, 0, 0},
    {0, 0, _image2665_size, 0, 0, 0, 0},
    {0, 0, _image2666_size, 0, 0, 0, 0},
    {0, 0, _image2667_size, 0, 0, 0, 0},
    {0, 0, _image2668_size, 0, 0, 0, 0},
    {0, 0, _image2669_size, 0, 0, 0, 0},
    {0, 0, _image2670_size, 0, 0, 0, 0},
    {0, 0, _image2671_size, 0, 0, 0, 0},
    {0, 0, _image2672_size, 0, 0, 0, 0},
    {0, 0, _image2673_size, 0, 0, 0, 0},
    {0, 0, _image2674_size, 0, 0, 0, 0},
    {0, 0, _image2675_size, 0, 0, 0, 0},
    {0, 0, _image2676_size, 0, 0, 0, 0},
    {0, 0, _image2677_size, 0, 0, 0, 0},
    {0, 0, _image2678_size, 0, 0, 0, 0},
    {0, 0, _image2679_size, 0, 0, 0, 0},
    {0, 0, _image2680_size, 0, 0, 0, 0},
    {0, 0, _image2681_size, 0, 0, 0, 0},
    {0, 0, _image2682_size, 0, 0, 0, 0},
    {0, 0, _image2683_size, 0, 0, 0, 0},
    {0, 0, _image2684_size, 0, 0, 0, 0},
    {0, 0, _image2685_size, 0, 0, 0, 0},
    {0, 0, _image2686_size, 0, 0, 0, 0},
    {0, 0, _image2687_size, 0, 0, 0, 0},
    {0, 0, _image2688_size, 0, 0, 0, 0},
    {0, 0, _image2689_size, 0, 0, 0, 0},
    {0, 0, _image2690_size, 0, 0, 0, 0},
    {0, 0, _image2691_size, 0, 0, 0, 0},
    {0, 0, _image2692_size, 0, 0, 0, 0},
    {0, 0, _image2693_size, 0, 0, 0, 0},
    {0, 0, _image2694_size, 0, 0, 0, 0},
    {0, 0, _image2695_size, 0, 0, 0, 0},
    {0, 0, _image2696_size, 0, 0, 0, 0},
    {0, 0, _image2697_size, 0, 0, 0, 0},
    {0, 0, _image2698_size, 0, 0, 0, 0},
    {0, 0, 0xFFFF, 0, 0, 0, 0}};

void nullsub_41(void) {}

asm(R"
glabel image_related_calls_decompressdata_function
  addiu $sp, $sp, -0x2ba8
  sw    $ra, 0x4c($sp)
  sw    $s5, 0x3c($sp)
  sw    $s1, 0x2c($sp)
  sw    $fp, 0x48($sp)
  sw    $s7, 0x44($sp)
  sw    $s6, 0x40($sp)
  sw    $s4, 0x38($sp)
  sw    $s3, 0x34($sp)
  sw    $s2, 0x30($sp)
  sw    $s0, 0x28($sp)
  sw    $a1, 0x2bac($sp)
  sw    $a2, 0x2bb0($sp)
  sw    $a3, 0x2bb4($sp)
  move  $s1, $zero
  jal   makeemptyimageatpos
   move  $s5, $zero
  lw    $a2, 0x2bb0($sp)
  lw    $a3, 0x2bb4($sp)
  move  $t0, $zero
  beql  $a2, $zero, .L7F0C66C4
   li    $t6, 1
  beql  $a3, $zero, .L7F0C66C4
   li    $t6, 1
  b     .L7F0C66CC
   sw    $a3, 0x2b9c($sp)
  li    $t6, 1
.L7F0C66C4:
  lw    $a3, 0x2bb4($sp)
  sw    $t6, 0x2b9c($sp)
.L7F0C66CC:
  lw    $fp, 0x2bb8($sp)
  sll   $t9, $a3, 5
  sll   $t5, $a2, 5
  lw    $v1, 0xc($fp)
  andi  $t6, $t5, 0x20
  lui   $a1, %hi(dword_CODE_bss_8008D090)
  lbu   $t1, 0xb($v1)
  andi  $t2, $t1, 0xff1f
  or    $t3, $t9, $t2
  sb    $t3, 0xb($v1)
  lw    $v1, 0xc($fp)
  lbu   $t7, 0xc($v1)
  andi  $t8, $t7, 0xffdf
  or    $t1, $t6, $t8
  beqz  $a2, .L7F0C675C
   sb    $t1, 0xc($v1)
  lw    $a1, %lo(dword_CODE_bss_8008D090)($a1)
  li    $s5, 1
  blez  $a1, .L7F0C675C
   nop   
  lw    $t9, 0xc($fp)
  lui   $t3, %hi(word_CODE_bss_8008C730)
  addiu $v0, $t3, %lo(word_CODE_bss_8008C730)
  lw    $v1, ($t9)
  sll   $t4, $a1, 4
  addu  $a0, $t4, $v0
  srl   $t2, $v1, 0x14
  move  $v1, $t2
  lh    $t5, ($v0)
.L7F0C6740:
  addiu $v0, $v0, 0x10
  sltu  $at, $v0, $a0
  bne   $v1, $t5, .L7F0C6754
   nop   
  move  $s5, $zero
.L7F0C6754:
  bnezl $at, .L7F0C6740
   lh    $t5, ($v0)
.L7F0C675C:
  jal   sub_GAME_7F0CBF2C
   li    $a0, 8
  sw    $v0, 0x2b94($sp)
  jal   sub_GAME_7F0CBF2C
   li    $a0, 8
  addiu $v1, $v0, 1
  blez  $v1, .L7F0C67AC
   sw    $v1, 0x2b78($sp)
  lw    $t6, 0x2b78($sp)
  addiu $v1, $sp, 0x70
  sll   $t8, $t6, 1
  addu  $s0, $t8, $v1
.L7F0C678C:
  li    $a0, 16
  jal   sub_GAME_7F0CBF2C
   sw    $v1, 0x5c($sp)
  lw    $v1, 0x5c($sp)
  addiu $v1, $v1, 2
  sltu  $at, $v1, $s0
  bnez  $at, .L7F0C678C
   sh    $v0, -2($v1)
.L7F0C67AC:
  lw    $t1, 0x2b9c($sp)
  lui   $s7, %hi(n64imagetypes) 
  addiu $s7, %lo(n64imagetypes) # addiu $s7, $s7, -0x6db8
  blez  $t1, .L7F0C694C
   move  $s3, $zero
  addiu $s4, $sp, 0x2370
.L7F0C67C4:
  jal   sub_GAME_7F0CBF2C
   li    $a0, 8
  move  $s6, $v0
  jal   sub_GAME_7F0CBF2C
   li    $a0, 8
  bnez  $s3, .L7F0C6880
   sw    $v0, 0x2b84($sp)
  lw    $t9, 0xc($fp)
  sb    $s6, 8($t9)
  lw    $t2, 0xc($fp)
  sb    $v0, 9($t2)
  lw    $t4, 0x2b78($sp)
  lw    $t5, 0xc($fp)
  addiu $t3, $t4, -1
  sb    $t3, 0xa($t5)
  lw    $a0, 0x2b94($sp)
  lw    $v1, 0xc($fp)
  sll   $t6, $a0, 2
  addu  $t8, $s7, $t6
  lw    $t1, ($t8)
  lbu   $t4, 0xb($v1)
  move  $a0, $t6
  sll   $t9, $t1, 2
  andi  $t2, $t9, 0x1c
  andi  $t3, $t4, 0xffe3
  or    $t5, $t2, $t3
  sb    $t5, 0xb($v1)
  lw    $v1, 0xc($fp)
  lui   $t6, %hi(n64pixelsizes)
  addu  $t6, $t6, $a0
  lw    $t8, %lo(n64pixelsizes)($t6)
  lbu   $t1, 0xb($v1)
  lui   $t2, %hi(imgflipvalues)
  andi  $t7, $t8, 3
  andi  $t9, $t1, 0xfffc
  or    $t4, $t7, $t9
  sb    $t4, 0xb($v1)
  lw    $v1, 0xc($fp)
  addu  $t2, $t2, $a0
  lw    $t2, %lo(imgflipvalues)($t2)
  lbu   $t1, 0xc($v1)
  sra   $t5, $t2, 0xe
  sll   $t8, $t5, 6
  andi  $t7, $t1, 0xff3f
  or    $t9, $t8, $t7
  b     .L7F0C68A8
   sb    $t9, 0xc($v1)
.L7F0C6880:
  beqz  $s5, .L7F0C68A8
   lui   $t4, %hi(dword_CODE_bss_8008D090) 
  lw    $t4, %lo(dword_CODE_bss_8008D090)($t4)
  lui   $t5, %hi(word_CODE_bss_8008C730) 
  addiu $t5, %lo(word_CODE_bss_8008C730) # addiu $t5, $t5, -0x38d0
  sll   $t2, $t4, 4
  addu  $t3, $t2, $s3
  addu  $v1, $t3, $t5
  sb    $s6, 1($v1)
  sb    $v0, 8($v1)
.L7F0C68A8:
  multu $s6, $v0
  lui   $a0, %hi(img_curpos)
  move  $a1, $s4
  addiu $a2, $sp, 0x270
  mflo  $t6
  slti  $at, $t6, 0x1001
  bnez  $at, .L7F0C68D0
   nop   
  b     .L7F0C6B98
   move  $v0, $zero
.L7F0C68D0:
  jal   decompressdata
   lw    $a0, %lo(img_curpos)($a0)
  lw    $t1, 0x2bac($sp)
  move  $a0, $s4
  move  $a1, $s6
  addu  $s0, $t1, $s1
  sw    $s0, 0x10($sp)
  lw    $a2, 0x2b84($sp)
  jal   copy_loaded_image_to_final_mem_location
   lw    $a3, 0x2b94($sp)
  jal   sub_GAME_7F0CE894
   move  $s2, $v0
  jal   makeemptyimageatpos
   move  $a0, $v0
  lw    $t8, 0x2bb0($sp)
  li    $at, 1
  lw    $t7, 0x2bb4($sp)
  bnel  $t8, $at, .L7F0C6938
   lw    $t9, 0x2b9c($sp)
  blez  $t7, .L7F0C6934
   move  $a0, $s0
  move  $a1, $s6
  lw    $a2, 0x2b84($sp)
  jal   sub_GAME_7F0CB67C
   lw    $a3, 0x2b94($sp)
.L7F0C6934:
  lw    $t9, 0x2b9c($sp)
.L7F0C6938:
  addiu $s3, $s3, 1
  addu  $s1, $s1, $s2
  bne   $s3, $t9, .L7F0C67C4
   nop   
  sw    $s6, 0x2b88($sp)
.L7F0C694C:
  lw    $s6, 0x2b88($sp)
  beqz  $s5, .L7F0C6994
   move  $t0, $zero
  lw    $t4, 0xc($fp)
  lui   $v0, %hi(dword_CODE_bss_8008D090)
  addiu $v0, %lo(dword_CODE_bss_8008D090) # addiu $v0, $v0, -0x2f70
  lw    $a1, ($v0)
  lw    $t2, ($t4)
  lui   $at, %hi(word_CODE_bss_8008C730)
  sll   $t5, $a1, 4
  addu  $at, $at, $t5
  srl   $t3, $t2, 0x14
  sh    $t3, %lo(word_CODE_bss_8008C730)($at)
  addiu $t6, $a1, 1
  slti  $at, $t6, 0x96
  bnez  $at, .L7F0C6994
   sw    $t6, ($v0)
  sw    $zero, ($v0)
.L7F0C6994:
  lw    $t8, 0x2bb0($sp)
  lw    $t7, 0x2bb4($sp)
  bnez  $t8, .L7F0C6AB8
   slti  $t9, $t7, 2
  xori  $t9, $t9, 1
  beqz  $t9, .L7F0C6A94
   lw    $t6, 0x2bb4($sp)
  lw    $s7, 0x2bac($sp)
  move  $s4, $s6
  lw    $s5, 0x2b84($sp)
  li    $s3, 1
  beqz  $t9, .L7F0C6A74
   addu  $s0, $s7, $s1
  addiu $s6, $sp, 0x70
.L7F0C69CC:
  lw    $t2, 0x2b94($sp)
  lw    $t3, 0x2b78($sp)
  move  $a0, $s7
  move  $a1, $s0
  move  $a2, $s4
  move  $a3, $s5
  sw    $s6, 0x14($sp)
  sw    $t0, 0x2ba4($sp)
  sw    $t2, 0x10($sp)
  jal   sub_GAME_7F0C6C70
   sw    $t3, 0x18($sp)
  addu  $t5, $s1, $v0
  slti  $at, $t5, 0x801
  lw    $t0, 0x2ba4($sp)
  bnez  $at, .L7F0C6A28
   move  $s2, $v0
  lw    $v1, 0xc($fp)
  sll   $t8, $s3, 5
  lbu   $t7, 0xb($v1)
  andi  $t4, $t7, 0xff1f
  or    $t9, $t8, $t4
  b     .L7F0C6A74
   sb    $t9, 0xb($v1)
.L7F0C6A28:
  move  $a0, $s7
  move  $a1, $s4
  move  $a2, $s5
  lw    $a3, 0x2b94($sp)
  jal   sub_GAME_7F0CB67C
   sw    $t0, 0x2ba4($sp)
  lw    $t5, 0x2bb4($sp)
  addiu $s4, $s4, 1
  addiu $s5, $s5, 1
  addiu $s3, $s3, 1
  sra   $t2, $s4, 1
  sra   $t3, $s5, 1
  move  $s7, $s0
  lw    $t0, 0x2ba4($sp)
  addu  $s1, $s1, $s2
  move  $s4, $t2
  move  $s5, $t3
  bne   $s3, $t5, .L7F0C69CC
   addu  $s0, $s0, $s2
.L7F0C6A74:
  move  $a0, $s7
  move  $a1, $s4
  move  $a2, $s5
  lw    $a3, 0x2b94($sp)
  jal   sub_GAME_7F0CB67C
   sw    $t0, 0x2ba4($sp)
  b     .L7F0C6AB8
   lw    $t0, 0x2ba4($sp)
.L7F0C6A94:
  li    $at, 1
  bne   $t6, $at, .L7F0C6AB8
   lw    $a0, 0x2bac($sp)
  move  $a1, $s6
  lw    $a2, 0x2b84($sp)
  lw    $a3, 0x2b94($sp)
  jal   sub_GAME_7F0CB67C
   sw    $t0, 0x2ba4($sp)
  lw    $t0, 0x2ba4($sp)
.L7F0C6AB8:
  lw    $t1, 0x2b78($sp)
  lw    $t7, 0x2bac($sp)
  li    $at, -8
  blez  $t1, .L7F0C6B90
   andi  $a0, $t1, 3
  beqz  $a0, .L7F0C6B18
   addu  $s0, $t7, $s1
  sll   $t8, $t0, 1
  addiu $t4, $sp, 0x70
  addu  $v1, $t8, $t4
  move  $v0, $a0
.L7F0C6AE4:
  lhu   $t9, ($v1)
  addiu $t0, $t0, 1
  addiu $s1, $s1, 2
  sra   $t2, $t9, 8
  sb    $t2, ($s0)
  lhu   $t5, ($v1)
  addiu $s0, $s0, 2
  addiu $v1, $v1, 2
  bne   $v0, $t0, .L7F0C6AE4
   sb    $t5, -1($s0)
  lw    $t6, 0x2b78($sp)
  beql  $t0, $t6, .L7F0C6B94
   addiu $s1, $s1, 7
.L7F0C6B18:
  lw    $t8, 0x2b78($sp)
  addiu $t1, $sp, 0x70
  sll   $t7, $t0, 1
  sll   $t4, $t8, 1
  addu  $v0, $t4, $t1
  addu  $v1, $t7, $t1
.L7F0C6B30:
  lhu   $t9, ($v1)
  addiu $v1, $v1, 8
  addiu $s1, $s1, 8
  sra   $t2, $t9, 8
  sb    $t2, ($s0)
  lhu   $t5, -8($v1)
  addiu $s0, $s0, 8
  sb    $t5, -7($s0)
  lhu   $t6, -6($v1)
  sra   $t7, $t6, 8
  sb    $t7, -6($s0)
  lhu   $t4, -6($v1)
  sb    $t4, -5($s0)
  lhu   $t1, -4($v1)
  sra   $t9, $t1, 8
  sb    $t9, -4($s0)
  lhu   $t3, -4($v1)
  sb    $t3, -3($s0)
  lhu   $t5, -2($v1)
  sra   $t6, $t5, 8
  sb    $t6, -2($s0)
  lhu   $t8, -2($v1)
  bne   $v1, $v0, .L7F0C6B30
   sb    $t8, -1($s0)
.L7F0C6B90:
  addiu $s1, $s1, 7
.L7F0C6B94:
  and   $v0, $s1, $at
.L7F0C6B98:
  lw    $ra, 0x4c($sp)
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
   addiu $sp, $sp, 0x2ba8
");

asm(R"
glabel copy_loaded_image_to_final_mem_location
  addiu $sp, $sp, -0x20
  sw    $s1, 0xc($sp)
  sw    $s0, 8($sp)
  li    $at, 9
  move  $s0, $a1
  move  $s1, $a0
  beq   $a3, $at, .L7F0C6BF4
   lw    $v1, 0x30($sp)
  li    $at, 11
  bnel  $a3, $at, .L7F0C6C00
   li    $at, 10
.L7F0C6BF4:
  b     .L7F0C6C18
   li    $v0, 1
  li    $at, 10
.L7F0C6C00:
  beq   $a3, $at, .L7F0C6C10
   li    $at, 12
  bne   $a3, $at, .L7F0C6C18
   lw    $v0, 0x10($sp)
.L7F0C6C10:
  b     .L7F0C6C18
   li    $v0, 2
.L7F0C6C18:
  blez  $a2, .L7F0C6C58
   move  $a0, $zero
  li    $a3, -8
.L7F0C6C24:
  blez  $s0, .L7F0C6C48
   move  $a1, $zero
.L7F0C6C2C:
  lbu   $t6, ($s1)
  addu  $a1, $a1, $v0
  slt   $at, $a1, $s0
  addiu $v1, $v1, 1
  addiu $s1, $s1, 1
  bnez  $at, .L7F0C6C2C
   sb    $t6, -1($v1)
.L7F0C6C48:
  addiu $a0, $a0, 1
  addiu $t7, $v1, 7
  bne   $a0, $a2, .L7F0C6C24
   and   $v1, $t7, $a3
.L7F0C6C58:
  lw    $t8, 0x30($sp)
  lw    $s0, 8($sp)
  lw    $s1, 0xc($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   subu  $v0, $v1, $t8
");

asm(R"
glabel sub_GAME_7F0C6C70
  addiu $sp, $sp, -0xa8
  sw    $s0, 0x20($sp)
  lw    $s0, 0xb8($sp)
  addiu $t7, $a3, 1
  sw    $fp, 0x40($sp)
  sw    $s5, 0x34($sp)
  li    $v0, 9
  sra   $t8, $t7, 1
  move  $fp, $a2
  sw    $ra, 0x44($sp)
  sw    $s7, 0x3c($sp)
  sw    $s6, 0x38($sp)
  sw    $s4, 0x30($sp)
  sw    $s3, 0x2c($sp)
  sw    $s2, 0x28($sp)
  sw    $s1, 0x24($sp)
  sw    $a3, 0xb4($sp)
  sw    $a1, 0x74($sp)
  move  $s5, $a0
  sw    $t8, 0x60($sp)
  beq   $s0, $v0, .L7F0C6CF0
   sw    $t8, 0x94($sp)
  li    $at, 10
  beq   $s0, $at, .L7F0C6D14
   addiu $t7, $fp, 1
  li    $at, 11
  beq   $s0, $at, .L7F0C6CF0
   li    $at, 12
  beql  $s0, $at, .L7F0C6D18
   sra   $t8, $t7, 1
  b     .L7F0C6D30
   nop   
.L7F0C6CF0:
  addiu $t9, $fp, 1
  sra   $t2, $t9, 1
  addiu $t3, $t2, 7
  addiu $t5, $fp, 7
  andi  $t4, $t3, 0xff8
  andi  $t6, $t5, 0xff8
  sw    $t4, 0x98($sp)
  b     .L7F0C6D30
   sw    $t6, 0x9c($sp)
.L7F0C6D14:
  sra   $t8, $t7, 1
.L7F0C6D18:
  addiu $t9, $t8, 0xf
  addiu $t3, $fp, 0xf
  andi  $t2, $t9, 0xff0
  andi  $t4, $t3, 0xff0
  sw    $t2, 0x98($sp)
  sw    $t4, 0x9c($sp)
.L7F0C6D30:
  beq   $s0, $v0, .L7F0C6D58
   li    $at, 10
  beq   $s0, $at, .L7F0C70F0
   li    $at, 11
  beq   $s0, $at, .L7F0C6F5C
   li    $at, 12
  beq   $s0, $at, .L7F0C74B0
   move  $v0, $zero
  b     .L7F0C777C
   nop   
.L7F0C6D58:
  lw    $t5, 0xb4($sp)
  lw    $t6, 0x9c($sp)
  sw    $zero, 0xa0($sp)
  blez  $t5, .L7F0C6F44
   sll   $t7, $t6, 1
  sw    $t7, 0x50($sp)
  lw    $s7, 0xc0($sp)
  lw    $s3, 0xbc($sp)
.L7F0C6D78:
  lw    $t9, 0xa0($sp)
  lw    $t8, 0xb4($sp)
  move  $s1, $zero
  addiu $t2, $t9, 1
  slt   $at, $t2, $t8
  beqz  $at, .L7F0C6D9C
   lw    $t3, 0x9c($sp)
  b     .L7F0C6DA0
   lw    $s6, 0x9c($sp)
.L7F0C6D9C:
  move  $s6, $zero
.L7F0C6DA0:
  blez  $t3, .L7F0C6F14
   move  $s2, $s5
  addu  $s4, $s6, $s5
  addiu $v0, $s1, 1
.L7F0C6DB0:
  slt   $at, $v0, $fp
  beqz  $at, .L7F0C6DC4
   move  $a0, $s3
  b     .L7F0C6DC8
   move  $v1, $v0
.L7F0C6DC4:
  move  $v1, $s1
.L7F0C6DC8:
  lbu   $t4, ($s2)
  addu  $t7, $s5, $v1
  lbu   $t9, ($t7)
  sll   $t5, $t4, 1
  addu  $t6, $s3, $t5
  lh    $s0, ($t6)
  addu  $t6, $s6, $v1
  lbu   $t3, ($s4)
  addu  $t7, $t6, $s5
  sll   $t8, $t9, 1
  lbu   $t9, ($t7)
  addu  $t2, $s3, $t8
  lh    $t0, ($t2)
  sll   $t4, $t3, 1
  addu  $t5, $s3, $t4
  sll   $t8, $t9, 1
  lh    $t1, ($t5)
  addu  $t2, $s3, $t8
  lh    $v0, ($t2)
  sra   $t3, $s0, 0xb
  andi  $t4, $t3, 0x1f
  sra   $t5, $t0, 0xb
  andi  $t6, $t5, 0x1f
  sra   $t9, $t1, 0xb
  andi  $t8, $t9, 0x1f
  addu  $t7, $t4, $t6
  sra   $t3, $v0, 0xb
  andi  $t5, $t3, 0x1f
  addu  $t2, $t7, $t8
  addu  $a2, $t2, $t5
  sra   $t9, $s0, 6
  andi  $t7, $t9, 0x1f
  sra   $t4, $a2, 2
  sra   $t8, $t0, 6
  andi  $t3, $t8, 0x1f
  andi  $a2, $t4, 0x1f
  sra   $t5, $t1, 6
  andi  $t4, $t5, 0x1f
  addu  $t2, $t7, $t3
  sra   $t9, $v0, 6
  andi  $t8, $t9, 0x1f
  addu  $t6, $t2, $t4
  addu  $a3, $t6, $t8
  sra   $t5, $s0, 1
  andi  $t2, $t5, 0x1f
  sra   $t7, $a3, 2
  sra   $t4, $t0, 1
  andi  $t9, $t4, 0x1f
  andi  $a3, $t7, 0x1f
  sra   $t8, $t1, 1
  andi  $t7, $t8, 0x1f
  addu  $t6, $t2, $t9
  sra   $t5, $v0, 1
  andi  $t4, $t5, 0x1f
  addu  $t3, $t6, $t7
  addu  $t2, $t3, $t4
  sra   $t9, $t2, 2
  andi  $t6, $s0, 1
  andi  $t7, $t0, 1
  addu  $t5, $t6, $t7
  andi  $t8, $t9, 0x1f
  andi  $t3, $t1, 1
  addu  $t4, $t5, $t3
  andi  $t2, $v0, 1
  addu  $t9, $t4, $t2
  sw    $t8, 0x10($sp)
  addiu $t8, $t9, 2
  sra   $t6, $t8, 2
  andi  $t7, $t6, 1
  sw    $t7, 0x14($sp)
  jal   sub_GAME_7F0C77AC
   move  $a1, $s7
  lw    $t5, 0x74($sp)
  sra   $t3, $s1, 1
  addiu $s1, $s1, 2
  addu  $t4, $t5, $t3
  sb    $v0, ($t4)
  lw    $t2, 0x9c($sp)
  addiu $s2, $s2, 2
  addiu $s4, $s4, 2
  slt   $at, $s1, $t2
  bnezl $at, .L7F0C6DB0
   addiu $v0, $s1, 1
.L7F0C6F14:
  lw    $t5, 0xa0($sp)
  lw    $t4, 0xb4($sp)
  lw    $t9, 0x74($sp)
  lw    $t8, 0x98($sp)
  lw    $t7, 0x50($sp)
  addiu $t3, $t5, 2
  slt   $at, $t3, $t4
  addu  $t6, $t9, $t8
  sw    $t3, 0xa0($sp)
  sw    $t6, 0x74($sp)
  bnez  $at, .L7F0C6D78
   addu  $s5, $s5, $t7
.L7F0C6F44:
  lw    $t2, 0x60($sp)
  lw    $t9, 0x98($sp)
  multu $t2, $t9
  mflo  $v0
  b     .L7F0C7780
   lw    $ra, 0x44($sp)
.L7F0C6F5C:
  lw    $t8, 0xb4($sp)
  lw    $t6, 0x9c($sp)
  sw    $zero, 0xa0($sp)
  blez  $t8, .L7F0C70D8
   sll   $t7, $t6, 1
  sw    $t7, 0x50($sp)
  lw    $s7, 0xc0($sp)
  lw    $s3, 0xbc($sp)
.L7F0C6F7C:
  lw    $t3, 0xa0($sp)
  lw    $t5, 0xb4($sp)
  move  $s1, $zero
  addiu $t4, $t3, 1
  slt   $at, $t4, $t5
  beqz  $at, .L7F0C6FA0
   lw    $t2, 0x9c($sp)
  b     .L7F0C6FA4
   lw    $s6, 0x9c($sp)
.L7F0C6FA0:
  move  $s6, $zero
.L7F0C6FA4:
  blez  $t2, .L7F0C70A8
   move  $s2, $s5
  addu  $s4, $s6, $s5
  addiu $v0, $s1, 1
.L7F0C6FB4:
  slt   $at, $v0, $fp
  beqz  $at, .L7F0C6FC8
   move  $a0, $s3
  b     .L7F0C6FCC
   move  $v1, $v0
.L7F0C6FC8:
  move  $v1, $s1
.L7F0C6FCC:
  lbu   $t9, ($s2)
  addu  $t7, $s5, $v1
  lbu   $t3, ($t7)
  sll   $t8, $t9, 1
  addu  $t6, $s3, $t8
  lh    $s0, ($t6)
  lbu   $t2, ($s4)
  addu  $t6, $s6, $v1
  addu  $t7, $t6, $s5
  sll   $t5, $t3, 1
  lbu   $t3, ($t7)
  addu  $t4, $s3, $t5
  sll   $t9, $t2, 1
  lh    $t0, ($t4)
  addu  $t8, $s3, $t9
  lh    $t1, ($t8)
  sll   $t5, $t3, 1
  addu  $t4, $s3, $t5
  lh    $v0, ($t4)
  sra   $t2, $s0, 8
  sra   $t8, $t0, 8
  andi  $t6, $t8, 0xff
  andi  $t9, $t2, 0xff
  sra   $t3, $t1, 8
  andi  $t5, $t3, 0xff
  addu  $t7, $t9, $t6
  addu  $t4, $t7, $t5
  sra   $t2, $v0, 8
  andi  $t8, $t2, 0xff
  addu  $a2, $t4, $t8
  andi  $t3, $s0, 0xff
  andi  $t7, $t0, 0xff
  addu  $t5, $t3, $t7
  andi  $t2, $t1, 0xff
  addu  $t4, $t5, $t2
  andi  $t8, $v0, 0xff
  addu  $a3, $t4, $t8
  sra   $t9, $a2, 2
  andi  $a2, $t9, 0xff
  addiu $a3, $a3, 1
  sra   $t9, $a3, 2
  andi  $a3, $t9, 0xff
  jal   sub_GAME_7F0C7BD8
   move  $a1, $s7
  lw    $t3, 0x74($sp)
  sra   $t7, $s1, 1
  addiu $s1, $s1, 2
  addu  $t5, $t3, $t7
  sb    $v0, ($t5)
  lw    $t2, 0x9c($sp)
  addiu $s2, $s2, 2
  addiu $s4, $s4, 2
  slt   $at, $s1, $t2
  bnezl $at, .L7F0C6FB4
   addiu $v0, $s1, 1
.L7F0C70A8:
  lw    $t3, 0xa0($sp)
  lw    $t5, 0xb4($sp)
  lw    $t4, 0x74($sp)
  lw    $t8, 0x98($sp)
  lw    $t6, 0x50($sp)
  addiu $t7, $t3, 2
  slt   $at, $t7, $t5
  addu  $t9, $t4, $t8
  sw    $t7, 0xa0($sp)
  sw    $t9, 0x74($sp)
  bnez  $at, .L7F0C6F7C
   addu  $s5, $s5, $t6
.L7F0C70D8:
  lw    $t2, 0x60($sp)
  lw    $t4, 0x98($sp)
  multu $t2, $t4
  mflo  $v0
  b     .L7F0C7780
   lw    $ra, 0x44($sp)
.L7F0C70F0:
  lw    $t8, 0xb4($sp)
  lw    $t9, 0x98($sp)
  sw    $zero, 0xa0($sp)
  blez  $t8, .L7F0C7494
   sra   $t6, $t9, 1
  sw    $t6, 0x4c($sp)
  lw    $s7, 0xc0($sp)
  lw    $s3, 0xbc($sp)
.L7F0C7110:
  lw    $t7, 0xa0($sp)
  lw    $t3, 0xb4($sp)
  move  $s1, $zero
  addiu $t5, $t7, 1
  slt   $at, $t5, $t3
  beqz  $at, .L7F0C713C
   lw    $t4, 0x9c($sp)
  lw    $s6, 0x9c($sp)
  sra   $t2, $s6, 1
  b     .L7F0C7140
   move  $s6, $t2
.L7F0C713C:
  move  $s6, $zero
.L7F0C7140:
  blez  $t4, .L7F0C7464
   addu  $s4, $s5, $s6
  sra   $a1, $s1, 1
.L7F0C714C:
  addu  $t8, $a1, $s5
  lbu   $v0, ($t8)
  addiu $t5, $s1, 1
  slt   $a0, $t5, $fp
  sra   $t9, $v0, 4
  andi  $t6, $t9, 0xf
  sll   $t7, $t6, 1
  addu  $t3, $s3, $t7
  beqz  $a0, .L7F0C717C
   lh    $s0, ($t3)
  b     .L7F0C7180
   move  $v1, $zero
.L7F0C717C:
  li    $v1, 4
.L7F0C7180:
  addu  $t6, $a1, $s6
  addu  $t7, $t6, $s5
  lbu   $t3, ($t7)
  srav  $t2, $v0, $v1
  andi  $t4, $t2, 0xf
  sll   $t8, $t4, 1
  sra   $t5, $t3, 4
  andi  $t2, $t5, 0xf
  addu  $t9, $s3, $t8
  sll   $t4, $t2, 1
  addu  $t8, $s3, $t4
  lh    $t0, ($t9)
  beqz  $a0, .L7F0C71C0
   lh    $t1, ($t8)
  b     .L7F0C71C4
   move  $v1, $zero
.L7F0C71C0:
  li    $v1, 4
.L7F0C71C4:
  addu  $t9, $s4, $a1
  lbu   $t6, ($t9)
  sra   $t4, $s0, 0xb
  andi  $t8, $t4, 0x1f
  srav  $t7, $t6, $v1
  andi  $t3, $t7, 0xf
  sll   $t5, $t3, 1
  addu  $t2, $s3, $t5
  lh    $v0, ($t2)
  sra   $t9, $t0, 0xb
  andi  $t6, $t9, 0x1f
  sra   $t3, $t1, 0xb
  andi  $t5, $t3, 0x1f
  addu  $t7, $t8, $t6
  sra   $t4, $v0, 0xb
  andi  $t9, $t4, 0x1f
  addu  $t2, $t7, $t5
  addu  $a2, $t2, $t9
  sra   $t3, $s0, 6
  andi  $t7, $t3, 0x1f
  sra   $t8, $a2, 2
  sra   $t5, $t0, 6
  andi  $t4, $t5, 0x1f
  andi  $a2, $t8, 0x1f
  sra   $t9, $t1, 6
  andi  $t8, $t9, 0x1f
  addu  $t2, $t7, $t4
  sra   $t3, $v0, 6
  andi  $t5, $t3, 0x1f
  addu  $t6, $t2, $t8
  addu  $a3, $t6, $t5
  sra   $t9, $s0, 1
  andi  $t2, $t9, 0x1f
  sra   $t7, $a3, 2
  sra   $t8, $t0, 1
  andi  $t3, $t8, 0x1f
  andi  $a3, $t7, 0x1f
  sra   $t5, $t1, 1
  andi  $t7, $t5, 0x1f
  addu  $t6, $t2, $t3
  sra   $t9, $v0, 1
  andi  $t8, $t9, 0x1f
  addu  $t4, $t6, $t7
  addu  $t2, $t4, $t8
  sra   $t3, $t2, 2
  andi  $t7, $t0, 1
  andi  $t6, $s0, 1
  addu  $t9, $t6, $t7
  andi  $t5, $t3, 0x1f
  andi  $t4, $t1, 1
  addu  $t8, $t9, $t4
  andi  $t2, $v0, 1
  addu  $t3, $t8, $t2
  sw    $t5, 0x10($sp)
  addiu $t5, $t3, 2
  sra   $t6, $t5, 2
  andi  $t7, $t6, 1
  sw    $t7, 0x14($sp)
  move  $a1, $s7
  jal   sub_GAME_7F0C77AC
   move  $a0, $s3
  lw    $t9, 0x74($sp)
  sra   $t4, $s1, 2
  addiu $a2, $s1, 2
  sll   $t2, $v0, 4
  sra   $t3, $a2, 1
  addu  $s2, $t9, $t4
  sb    $t2, ($s2)
  addu  $t5, $t3, $s5
  lbu   $a0, ($t5)
  addiu $t8, $s1, 3
  slt   $a1, $t8, $fp
  sra   $t6, $a0, 4
  andi  $t7, $t6, 0xf
  sll   $t9, $t7, 1
  addu  $t4, $s3, $t9
  lh    $s0, ($t4)
  beqz  $a1, .L7F0C7308
   move  $a2, $t3
  b     .L7F0C730C
   move  $v1, $zero
.L7F0C7308:
  li    $v1, 4
.L7F0C730C:
  addu  $t7, $a2, $s6
  addu  $t9, $t7, $s5
  lbu   $t4, ($t9)
  srav  $t2, $a0, $v1
  andi  $t3, $t2, 0xf
  sll   $t5, $t3, 1
  sra   $t8, $t4, 4
  andi  $t2, $t8, 0xf
  addu  $t6, $s3, $t5
  sll   $t3, $t2, 1
  addu  $t5, $s3, $t3
  lh    $t0, ($t6)
  beqz  $a1, .L7F0C734C
   lh    $t1, ($t5)
  b     .L7F0C7350
   move  $v1, $zero
.L7F0C734C:
  li    $v1, 4
.L7F0C7350:
  addu  $t6, $s4, $a2
  lbu   $t7, ($t6)
  sra   $t3, $s0, 0xb
  andi  $t5, $t3, 0x1f
  srav  $t9, $t7, $v1
  andi  $t4, $t9, 0xf
  sll   $t8, $t4, 1
  addu  $t2, $s3, $t8
  lh    $v0, ($t2)
  sra   $t6, $t0, 0xb
  andi  $t7, $t6, 0x1f
  sra   $t4, $t1, 0xb
  andi  $t8, $t4, 0x1f
  addu  $t9, $t5, $t7
  sra   $t3, $v0, 0xb
  andi  $t6, $t3, 0x1f
  addu  $t2, $t9, $t8
  addu  $a2, $t2, $t6
  sra   $t4, $s0, 6
  andi  $t9, $t4, 0x1f
  sra   $t5, $a2, 2
  sra   $t8, $t0, 6
  andi  $t3, $t8, 0x1f
  andi  $a2, $t5, 0x1f
  sra   $t6, $t1, 6
  andi  $t5, $t6, 0x1f
  addu  $t2, $t9, $t3
  sra   $t4, $v0, 6
  andi  $t8, $t4, 0x1f
  addu  $t7, $t2, $t5
  addu  $a3, $t7, $t8
  sra   $t6, $s0, 1
  andi  $t2, $t6, 0x1f
  sra   $t9, $a3, 2
  sra   $t5, $t0, 1
  andi  $t4, $t5, 0x1f
  andi  $a3, $t9, 0x1f
  sra   $t8, $t1, 1
  andi  $t9, $t8, 0x1f
  addu  $t7, $t2, $t4
  sra   $t6, $v0, 1
  andi  $t5, $t6, 0x1f
  addu  $t3, $t7, $t9
  addu  $t2, $t3, $t5
  sra   $t4, $t2, 2
  andi  $t9, $t0, 1
  andi  $t7, $s0, 1
  addu  $t6, $t7, $t9
  andi  $t8, $t4, 0x1f
  andi  $t3, $t1, 1
  addu  $t5, $t6, $t3
  andi  $t2, $v0, 1
  addu  $t4, $t5, $t2
  sw    $t8, 0x10($sp)
  addiu $t8, $t4, 2
  sra   $t7, $t8, 2
  andi  $t9, $t7, 1
  sw    $t9, 0x14($sp)
  move  $a0, $s3
  jal   sub_GAME_7F0C77AC
   move  $a1, $s7
  lbu   $t6, ($s2)
  addiu $s1, $s1, 4
  or    $t5, $t6, $v0
  sb    $t5, ($s2)
  lw    $t2, 0x9c($sp)
  slt   $at, $s1, $t2
  bnezl $at, .L7F0C714C
   sra   $a1, $s1, 1
.L7F0C7464:
  lw    $t6, 0xa0($sp)
  lw    $t5, 0xb4($sp)
  lw    $t4, 0x74($sp)
  lw    $t8, 0x4c($sp)
  lw    $t9, 0x9c($sp)
  addiu $t3, $t6, 2
  slt   $at, $t3, $t5
  addu  $t7, $t4, $t8
  sw    $t3, 0xa0($sp)
  sw    $t7, 0x74($sp)
  bnez  $at, .L7F0C7110
   addu  $s5, $s5, $t9
.L7F0C7494:
  lw    $t2, 0x98($sp)
  lw    $t8, 0x94($sp)
  sra   $t4, $t2, 1
  multu $t4, $t8
  mflo  $v0
  b     .L7F0C7780
   lw    $ra, 0x44($sp)
.L7F0C74B0:
  lw    $t7, 0xb4($sp)
  lw    $t9, 0x98($sp)
  sw    $zero, 0xa0($sp)
  blez  $t7, .L7F0C7760
   sra   $t6, $t9, 1
  sw    $t6, 0x4c($sp)
  lw    $s7, 0xc0($sp)
  lw    $s3, 0xbc($sp)
.L7F0C74D0:
  lw    $t5, 0xa0($sp)
  lw    $t3, 0xb4($sp)
  move  $s1, $zero
  addiu $t2, $t5, 1
  slt   $at, $t2, $t3
  beqz  $at, .L7F0C74FC
   lw    $t8, 0x9c($sp)
  lw    $s6, 0x9c($sp)
  sra   $t4, $s6, 1
  b     .L7F0C7500
   move  $s6, $t4
.L7F0C74FC:
  move  $s6, $zero
.L7F0C7500:
  blez  $t8, .L7F0C7730
   sra   $a1, $s1, 1
.L7F0C7508:
  addu  $t7, $a1, $s5
  lbu   $v0, ($t7)
  addiu $t2, $s1, 1
  slt   $a0, $t2, $fp
  sra   $t9, $v0, 4
  andi  $t6, $t9, 0xf
  sll   $t5, $t6, 1
  addu  $t3, $s3, $t5
  srav  $t4, $v0, $a0
  beqz  $t4, .L7F0C753C
   lh    $s0, ($t3)
  b     .L7F0C7540
   move  $v1, $zero
.L7F0C753C:
  li    $v1, 4
.L7F0C7540:
  addu  $t6, $a1, $s6
  addu  $t5, $t6, $s5
  lbu   $v0, ($t5)
  andi  $t8, $v1, 0xf
  sll   $t7, $t8, 1
  sra   $t3, $v0, 4
  andi  $t2, $t3, 0xf
  addu  $t9, $s3, $t7
  sll   $t4, $t2, 1
  addu  $t8, $s3, $t4
  srav  $t7, $v0, $a0
  lh    $t0, ($t9)
  beqz  $t7, .L7F0C7580
   lh    $t1, ($t8)
  b     .L7F0C7584
   move  $v1, $zero
.L7F0C7580:
  li    $v1, 4
.L7F0C7584:
  andi  $t9, $v1, 0xf
  sll   $t6, $t9, 1
  addu  $t5, $s3, $t6
  lh    $v0, ($t5)
  sra   $t3, $s0, 8
  sra   $t4, $t0, 8
  andi  $t8, $t4, 0xff
  andi  $t2, $t3, 0xff
  sra   $t9, $t1, 8
  andi  $t6, $t9, 0xff
  addu  $t7, $t2, $t8
  addu  $t5, $t7, $t6
  sra   $t3, $v0, 8
  andi  $t4, $t3, 0xff
  addu  $a2, $t5, $t4
  andi  $t7, $t0, 0xff
  andi  $t9, $s0, 0xff
  addu  $t6, $t9, $t7
  andi  $t3, $t1, 0xff
  addu  $t5, $t6, $t3
  andi  $t4, $v0, 0xff
  addu  $a3, $t5, $t4
  sra   $t2, $a2, 2
  andi  $a2, $t2, 0xff
  addiu $a3, $a3, 1
  sra   $t2, $a3, 2
  andi  $a3, $t2, 0xff
  move  $a0, $s3
  jal   sub_GAME_7F0C7BD8
   move  $a1, $s7
  lw    $t9, 0x74($sp)
  sra   $t7, $s1, 2
  addiu $a2, $s1, 2
  sll   $t3, $v0, 4
  sra   $t5, $a2, 1
  addu  $s2, $t9, $t7
  sb    $t3, ($s2)
  addu  $t4, $t5, $s5
  lbu   $a0, ($t4)
  addiu $t6, $s1, 3
  slt   $a1, $t6, $fp
  sra   $t2, $a0, 4
  andi  $t8, $t2, 0xf
  sll   $t9, $t8, 1
  addu  $t7, $s3, $t9
  srav  $t3, $a0, $a1
  lh    $s0, ($t7)
  beqz  $t3, .L7F0C7650
   move  $a2, $t5
  b     .L7F0C7654
   move  $v1, $zero
.L7F0C7650:
  li    $v1, 4
.L7F0C7654:
  addu  $t8, $a2, $s6
  addu  $t9, $t8, $s5
  lbu   $v0, ($t9)
  andi  $t5, $v1, 0xf
  sll   $t4, $t5, 1
  sra   $t7, $v0, 4
  andi  $t6, $t7, 0xf
  addu  $t2, $s3, $t4
  sll   $t3, $t6, 1
  addu  $t5, $s3, $t3
  srav  $t4, $v0, $a1
  lh    $t0, ($t2)
  beqz  $t4, .L7F0C7694
   lh    $t1, ($t5)
  b     .L7F0C7698
   move  $v1, $zero
.L7F0C7694:
  li    $v1, 4
.L7F0C7698:
  andi  $t2, $v1, 0xf
  sll   $t8, $t2, 1
  addu  $t9, $s3, $t8
  lh    $v0, ($t9)
  sra   $t7, $s0, 8
  sra   $t3, $t0, 8
  andi  $t5, $t3, 0xff
  andi  $t6, $t7, 0xff
  sra   $t2, $t1, 8
  andi  $t8, $t2, 0xff
  addu  $t4, $t6, $t5
  addu  $t9, $t4, $t8
  sra   $t7, $v0, 8
  andi  $t3, $t7, 0xff
  addu  $a2, $t9, $t3
  andi  $t4, $t0, 0xff
  andi  $t2, $s0, 0xff
  addu  $t8, $t2, $t4
  andi  $t7, $t1, 0xff
  addu  $t9, $t8, $t7
  andi  $t3, $v0, 0xff
  addu  $a3, $t9, $t3
  sra   $t6, $a2, 2
  andi  $a2, $t6, 0xff
  addiu $a3, $a3, 1
  sra   $t6, $a3, 2
  andi  $a3, $t6, 0xff
  move  $a0, $s3
  jal   sub_GAME_7F0C7BD8
   move  $a1, $s7
  lbu   $t2, ($s2)
  addiu $s1, $s1, 4
  or    $t8, $t2, $v0
  sb    $t8, ($s2)
  lw    $t7, 0x9c($sp)
  slt   $at, $s1, $t7
  bnezl $at, .L7F0C7508
   sra   $a1, $s1, 1
.L7F0C7730:
  lw    $t2, 0xa0($sp)
  lw    $t8, 0xb4($sp)
  lw    $t9, 0x74($sp)
  lw    $t3, 0x4c($sp)
  lw    $t5, 0x9c($sp)
  addiu $t4, $t2, 2
  slt   $at, $t4, $t8
  addu  $t6, $t9, $t3
  sw    $t4, 0xa0($sp)
  sw    $t6, 0x74($sp)
  bnez  $at, .L7F0C74D0
   addu  $s5, $s5, $t5
.L7F0C7760:
  lw    $t7, 0x98($sp)
  lw    $t3, 0x94($sp)
  sra   $t9, $t7, 1
  multu $t9, $t3
  mflo  $v0
  b     .L7F0C7780
   lw    $ra, 0x44($sp)
.L7F0C777C:
  lw    $ra, 0x44($sp)
.L7F0C7780:
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
   addiu $sp, $sp, 0xa8
");

asm(R"
glabel sub_GAME_7F0C77AC
  addiu $sp, $sp, -0x18
  sw    $s2, 0xc($sp)
  sw    $s1, 8($sp)
  sw    $s0, 4($sp)
  move  $s0, $a2
  move  $s1, $a3
  move  $s2, $a0
  sw    $s4, 0x14($sp)
  sw    $s3, 0x10($sp)
  sw    $a1, 0x1c($sp)
  blez  $a1, .L7F0C78D4
   move  $v1, $zero
  andi  $a2, $a1, 3
  beqz  $a2, .L7F0C7844
   lw    $t1, 0x28($sp)
  sll   $t7, $zero, 1
  lw    $t2, 0x2c($sp)
  addu  $v0, $s2, $t7
  sll   $t8, $s0, 0xb
  sll   $t9, $a3, 6
  or    $t6, $t8, $t9
  sll   $t7, $t1, 1
  or    $t8, $t6, $t7
  or    $a1, $t8, $t2
  andi  $t9, $a1, 0xffff
  move  $a1, $t9
  move  $a0, $a2
.L7F0C7818:
  lhu   $t6, ($v0)
  bnel  $a1, $t6, .L7F0C7830
   addiu $v1, $v1, 1
  b     .L7F0C7BBC
   move  $v0, $v1
  addiu $v1, $v1, 1
.L7F0C7830:
  bne   $a0, $v1, .L7F0C7818
   addiu $v0, $v0, 2
  lw    $t7, 0x1c($sp)
  beql  $v1, $t7, .L7F0C78D8
   lw    $a2, 0x1c($sp)
.L7F0C7844:
  lw    $t1, 0x28($sp)
  sll   $t8, $v1, 1
  lw    $t2, 0x2c($sp)
  addu  $v0, $s2, $t8
  sll   $t9, $s0, 0xb
  sll   $t6, $s1, 6
  or    $t7, $t9, $t6
  sll   $t8, $t1, 1
  or    $t9, $t7, $t8
  or    $a1, $t9, $t2
  andi  $t6, $a1, 0xffff
  move  $a1, $t6
.L7F0C7874:
  lhu   $t7, ($v0)
  bnel  $a1, $t7, .L7F0C788C
   lhu   $t8, 2($v0)
  b     .L7F0C7BBC
   move  $v0, $v1
  lhu   $t8, 2($v0)
.L7F0C788C:
  lw    $t7, 0x1c($sp)
  bnel  $a1, $t8, .L7F0C78A4
   lhu   $t9, 4($v0)
  b     .L7F0C7BBC
   addiu $v0, $v1, 1
  lhu   $t9, 4($v0)
.L7F0C78A4:
  bnel  $a1, $t9, .L7F0C78B8
   lhu   $t6, 6($v0)
  b     .L7F0C7BBC
   addiu $v0, $v1, 2
  lhu   $t6, 6($v0)
.L7F0C78B8:
  bnel  $a1, $t6, .L7F0C78CC
   addiu $v1, $v1, 4
  b     .L7F0C7BBC
   addiu $v0, $v1, 3
  addiu $v1, $v1, 4
.L7F0C78CC:
  bne   $v1, $t7, .L7F0C7874
   addiu $v0, $v0, 8
.L7F0C78D4:
  lw    $a2, 0x1c($sp)
.L7F0C78D8:
  lw    $t1, 0x28($sp)
  lw    $t2, 0x2c($sp)
  addiu $a2, $a2, -1
  slti  $at, $a2, 2
  move  $a1, $zero
  bnez  $at, .L7F0C79D8
   move  $a3, $a2
  multu $s0, $s0
  mflo  $t8
  nop   
  nop   
  multu $s1, $s1
  mflo  $t9
  addu  $t6, $t8, $t9
  sll   $t9, $t2, 4
  multu $t1, $t1
  subu  $t9, $t9, $t2
  sll   $t9, $t9, 6
  addu  $t9, $t9, $t2
  mflo  $t7
  addu  $t8, $t6, $t7
  addu  $t0, $t8, $t9
  addu  $t3, $a3, $a1
.L7F0C7934:
  sra   $a0, $t3, 1
  sll   $t7, $a0, 1
  addu  $t8, $s2, $t7
  lhu   $v1, ($t8)
  sra   $t4, $v1, 0xb
  andi  $t9, $t4, 0x1f
  multu $t9, $t9
  sra   $t5, $v1, 6
  andi  $t6, $t5, 0x1f
  sra   $s3, $v1, 1
  andi  $t7, $s3, 0x1f
  mflo  $t8
  nop   
  nop   
  multu $t6, $t6
  mflo  $t9
  addu  $t6, $t8, $t9
  andi  $t9, $v1, 1
  multu $t7, $t7
  mflo  $t7
  addu  $t8, $t6, $t7
  sll   $t6, $t9, 4
  subu  $t6, $t6, $t9
  sll   $t6, $t6, 6
  addu  $t6, $t6, $t9
  addu  $s4, $t8, $t6
  slt   $at, $s4, $t0
  beql  $at, $zero, .L7F0C79B4
   slt   $at, $t0, $s4
  b     .L7F0C79C8
   move  $a1, $a0
  slt   $at, $t0, $s4
.L7F0C79B4:
  beqz  $at, .L7F0C79C4
   move  $a3, $a0
  b     .L7F0C79C8
   move  $a3, $a0
.L7F0C79C4:
  move  $a1, $a0
.L7F0C79C8:
  subu  $t7, $a3, $a1
  slti  $at, $t7, 2
  beql  $at, $zero, .L7F0C7934
   addu  $t3, $a3, $a1
.L7F0C79D8:
  addiu $a1, $a3, -4
  bgez  $a1, .L7F0C79E8
   lw    $t9, 0x1c($sp)
  move  $a1, $zero
.L7F0C79E8:
  addiu $a3, $a3, 4
  slt   $at, $a3, $t9
  bnez  $at, .L7F0C79FC
   lui   $s4, (0x000F423F >> 16) # lui $s4, 0xf
  move  $a3, $a2
.L7F0C79FC:
  ori   $s4, (0x000F423F & 0xFFFF) # ori $s4, $s4, 0x423f
  slt   $at, $a3, $a1
  move  $t0, $zero
  move  $a2, $s4
  bnez  $at, .L7F0C7BB8
   move  $a0, $a1
  subu  $v0, $a3, $a1
  addiu $v0, $v0, 1
  andi  $t8, $v0, 1
  beqz  $t8, .L7F0C7AB0
   sll   $t6, $a1, 1
  addu  $t7, $s2, $t6
  lhu   $v0, ($t7)
  addiu $a0, $a1, 1
  li    $v1, 961
  andi  $t9, $v0, 1
  bne   $t2, $t9, .L7F0C7A4C
   sra   $t8, $v0, 0xb
  b     .L7F0C7A4C
   move  $v1, $zero
.L7F0C7A4C:
  andi  $t6, $t8, 0x1f
  subu  $t3, $t6, $s0
  multu $t3, $t3
  sra   $t7, $v0, 6
  andi  $t9, $t7, 0x1f
  subu  $t4, $t9, $s1
  sra   $t8, $v0, 1
  andi  $t6, $t8, 0x1f
  subu  $t5, $t6, $t1
  mflo  $t7
  addu  $t9, $v1, $t7
  nop   
  multu $t4, $t4
  mflo  $t8
  addu  $t6, $t9, $t8
  addiu $t9, $a3, 1
  multu $t5, $t5
  mflo  $t7
  addu  $s3, $t6, $t7
  slt   $at, $s3, $s4
  beqz  $at, .L7F0C7AAC
   nop   
  move  $t0, $a1
  move  $a2, $s3
.L7F0C7AAC:
  beq   $t9, $a0, .L7F0C7BB8
.L7F0C7AB0:
   sll   $t8, $a0, 1
  addu  $a1, $s2, $t8
.L7F0C7AB8:
  lhu   $v0, ($a1)
  li    $v1, 961
  andi  $t6, $v0, 1
  bne   $t2, $t6, .L7F0C7AD4
   sra   $t7, $v0, 0xb
  b     .L7F0C7AD4
   move  $v1, $zero
.L7F0C7AD4:
  andi  $t9, $t7, 0x1f
  subu  $t4, $t9, $s0
  multu $t4, $t4
  sra   $t8, $v0, 6
  andi  $t6, $t8, 0x1f
  subu  $t5, $t6, $s1
  sra   $t7, $v0, 1
  andi  $t9, $t7, 0x1f
  subu  $s2, $t9, $t1
  mflo  $t8
  addu  $t6, $v1, $t8
  li    $v1, 961
  multu $t5, $t5
  mflo  $t7
  addu  $t9, $t6, $t7
  nop   
  multu $s2, $s2
  mflo  $t8
  addu  $s3, $t9, $t8
  slt   $at, $s3, $a2
  beql  $at, $zero, .L7F0C7B38
   lhu   $v0, 2($a1)
  move  $t0, $a0
  move  $a2, $s3
  lhu   $v0, 2($a1)
.L7F0C7B38:
  andi  $t6, $v0, 1
  bne   $t2, $t6, .L7F0C7B4C
   sra   $t7, $v0, 0xb
  b     .L7F0C7B4C
   move  $v1, $zero
.L7F0C7B4C:
  andi  $t9, $t7, 0x1f
  subu  $t3, $t9, $s0
  multu $t3, $t3
  sra   $t8, $v0, 6
  andi  $t6, $t8, 0x1f
  subu  $t4, $t6, $s1
  sra   $t7, $v0, 1
  andi  $t9, $t7, 0x1f
  subu  $t5, $t9, $t1
  mflo  $t8
  addu  $t6, $v1, $t8
  nop   
  multu $t4, $t4
  mflo  $t7
  addu  $t9, $t6, $t7
  addiu $t6, $a3, 1
  multu $t5, $t5
  mflo  $t8
  addu  $s2, $t9, $t8
  slt   $at, $s2, $a2
  beql  $at, $zero, .L7F0C7BB0
   addiu $a0, $a0, 2
  addiu $t0, $a0, 1
  move  $a2, $s2
  addiu $a0, $a0, 2
.L7F0C7BB0:
  bne   $t6, $a0, .L7F0C7AB8
   addiu $a1, $a1, 4
.L7F0C7BB8:
  move  $v0, $t0
.L7F0C7BBC:
  lw    $s0, 4($sp)
  lw    $s1, 8($sp)
  lw    $s2, 0xc($sp)
  lw    $s3, 0x10($sp)
  lw    $s4, 0x14($sp)
  jr    $ra
   addiu $sp, $sp, 0x18
");

asm(R"
glabel sub_GAME_7F0C7BD8
  addiu $sp, $sp, -0x10
  sw    $s1, 0xc($sp)
  sw    $s0, 8($sp)
  blez  $a1, .L7F0C7CA8
   move  $v1, $zero
  andi  $t2, $a1, 3
  beqz  $t2, .L7F0C7C34
   move  $t0, $t2
  sll   $t7, $a2, 8
  or    $t1, $t7, $a3
  andi  $t8, $t1, 0xffff
  sll   $t6, $zero, 1
  addu  $v0, $a0, $t6
  move  $t1, $t8
.L7F0C7C10:
  lhu   $t9, ($v0)
  bnel  $t1, $t9, .L7F0C7C28
   addiu $v1, $v1, 1
  b     .L7F0C7DEC
   move  $v0, $v1
  addiu $v1, $v1, 1
.L7F0C7C28:
  bne   $t0, $v1, .L7F0C7C10
   addiu $v0, $v0, 2
  beq   $v1, $a1, .L7F0C7CA8
.L7F0C7C34:
   sll   $t7, $a2, 8
  or    $t1, $t7, $a3
  andi  $t8, $t1, 0xffff
  sll   $t6, $v1, 1
  addu  $v0, $a0, $t6
  move  $t1, $t8
.L7F0C7C4C:
  lhu   $t9, ($v0)
  bnel  $t1, $t9, .L7F0C7C64
   lhu   $t6, 2($v0)
  b     .L7F0C7DEC
   move  $v0, $v1
  lhu   $t6, 2($v0)
.L7F0C7C64:
  bnel  $t1, $t6, .L7F0C7C78
   lhu   $t7, 4($v0)
  b     .L7F0C7DEC
   addiu $v0, $v1, 1
  lhu   $t7, 4($v0)
.L7F0C7C78:
  bnel  $t1, $t7, .L7F0C7C8C
   lhu   $t8, 6($v0)
  b     .L7F0C7DEC
   addiu $v0, $v1, 2
  lhu   $t8, 6($v0)
.L7F0C7C8C:
  bnel  $t1, $t8, .L7F0C7CA0
   addiu $v1, $v1, 4
  b     .L7F0C7DEC
   addiu $v0, $v1, 3
  addiu $v1, $v1, 4
.L7F0C7CA0:
  bne   $v1, $a1, .L7F0C7C4C
   addiu $v0, $v0, 8
.L7F0C7CA8:
  addiu $t0, $a1, -1
  slti  $at, $t0, 2
  move  $v0, $zero
  bnez  $at, .L7F0C7D54
   move  $v1, $t0
  multu $a2, $a2
  mflo  $t9
  nop   
  nop   
  multu $a3, $a3
  mflo  $t6
  addu  $t1, $t9, $t6
  nop   
  addu  $t3, $v1, $v0
.L7F0C7CE0:
  sra   $t2, $t3, 1
  sll   $t8, $t2, 1
  addu  $t9, $a0, $t8
  lhu   $t4, ($t9)
  sra   $t5, $t4, 8
  andi  $t6, $t5, 0xff
  multu $t6, $t6
  andi  $s0, $t4, 0xff
  mflo  $t7
  nop   
  nop   
  multu $s0, $s0
  mflo  $t8
  addu  $s1, $t7, $t8
  slt   $at, $s1, $t1
  beql  $at, $zero, .L7F0C7D30
   slt   $at, $t1, $s1
  b     .L7F0C7D44
   move  $v0, $t2
  slt   $at, $t1, $s1
.L7F0C7D30:
  beqz  $at, .L7F0C7D40
   move  $v1, $t2
  b     .L7F0C7D44
   move  $v1, $t2
.L7F0C7D40:
  move  $v0, $t2
.L7F0C7D44:
  subu  $t9, $v1, $v0
  slti  $at, $t9, 2
  beql  $at, $zero, .L7F0C7CE0
   addu  $t3, $v1, $v0
.L7F0C7D54:
  addiu $v0, $v1, -4
  bgez  $v0, .L7F0C7D64
   addiu $v1, $v1, 4
  move  $v0, $zero
.L7F0C7D64:
  slt   $at, $v1, $a1
  bnez  $at, .L7F0C7D74
   move  $a1, $zero
  move  $v1, $t0
.L7F0C7D74:
  lui   $t0, (0x000F423F >> 16) # lui $t0, 0xf
  slt   $at, $v1, $v0
  ori   $t0, (0x000F423F & 0xFFFF) # ori $t0, $t0, 0x423f
  bnez  $at, .L7F0C7DE8
   move  $t2, $v0
  sll   $t6, $v0, 1
  addu  $v0, $a0, $t6
  addiu $t3, $v1, 1
.L7F0C7D94:
  lhu   $t4, ($v0)
  sra   $t7, $t4, 8
  andi  $t8, $t7, 0xff
  subu  $v1, $t8, $a2
  multu $v1, $v1
  andi  $t9, $t4, 0xff
  subu  $a0, $t9, $a3
  mflo  $t6
  nop   
  nop   
  multu $a0, $a0
  mflo  $t7
  addu  $t1, $t6, $t7
  slt   $at, $t1, $t0
  beql  $at, $zero, .L7F0C7DE0
   addiu $t2, $t2, 1
  move  $a1, $t2
  move  $t0, $t1
  addiu $t2, $t2, 1
.L7F0C7DE0:
  bne   $t3, $t2, .L7F0C7D94
   addiu $v0, $v0, 2
.L7F0C7DE8:
  move  $v0, $a1
.L7F0C7DEC:
  lw    $s0, 8($sp)
  lw    $s1, 0xc($sp)
  jr    $ra
   addiu $sp, $sp, 0x10
");

asm(R"
.late_rodata
/*D:8005BD30*/
glabel jpt_8005BD30
.word huffman_type0_1
.word huffman_type0_1
.word huffman_type2
.word huffman_type3
.word huffman_type4
.word huffman_type5
.word huffman_type6
.word huffman_type7
.word huffman_type8
.word huffman_type9
.text
glabel process_huffman_compressed_images
  addiu $sp, $sp, -0x30a8
  sw    $ra, 0x4c($sp)
  sw    $fp, 0x48($sp)
  sw    $s7, 0x44($sp)
  sw    $s6, 0x40($sp)
  sw    $s5, 0x3c($sp)
  sw    $s4, 0x38($sp)
  sw    $s3, 0x34($sp)
  sw    $s2, 0x30($sp)
  sw    $s1, 0x2c($sp)
  sw    $s0, 0x28($sp)
  sw    $a1, 0x30ac($sp)
  sw    $a2, 0x30b0($sp)
  sw    $a3, 0x30b4($sp)
  sw    $zero, 0x88($sp)
  jal   makeemptyimageatpos
   sw    $zero, 0x70($sp)
  lw    $t1, 0x30b0($sp)
  lw    $t2, 0x30b4($sp)
  li    $t6, 1
  beqz  $t1, .L7F0C7E64
   lui   $t0, %hi(dword_CODE_bss_8008D090) 
  beql  $t2, $zero, .L7F0C7E68
   lw    $t2, 0x30b4($sp)
  b     .L7F0C7E6C
   sw    $t2, 0x9c($sp)
.L7F0C7E64:
  lw    $t2, 0x30b4($sp)
.L7F0C7E68:
  sw    $t6, 0x9c($sp)
.L7F0C7E6C:
  lw    $a3, 0x30b8($sp)
  sll   $t9, $t2, 5
  sll   $t7, $t1, 5
  lw    $v1, 0xc($a3)
  andi  $t8, $t7, 0x20
  addiu $t0, %lo(dword_CODE_bss_8008D090) # addiu $t0, $t0, -0x2f70
  lbu   $t3, 0xb($v1)
  andi  $t4, $t3, 0xff1f
  or    $t5, $t9, $t4
  sb    $t5, 0xb($v1)
  lw    $v1, 0xc($a3)
  lbu   $t3, 0xc($v1)
  andi  $t9, $t3, 0xffdf
  or    $t4, $t8, $t9
  beqz  $t1, .L7F0C7F04
   sb    $t4, 0xc($v1)
  lw    $a1, ($t0)
  li    $a2, 1
  sw    $a2, 0x70($sp)
  blezl $a1, .L7F0C7F08
   lw    $t9, 0x9c($sp)
  lw    $t5, 0xc($a3)
  lui   $t7, %hi(word_CODE_bss_8008C730)
  addiu $v0, $t7, %lo(word_CODE_bss_8008C730)
  lw    $v1, ($t5)
  sll   $t3, $a1, 4
  addu  $a0, $t3, $v0
  srl   $t6, $v1, 0x14
  move  $v1, $t6
  lh    $t8, ($v0)
.L7F0C7EE4:
  addiu $v0, $v0, 0x10
  sltu  $at, $v0, $a0
  bne   $v1, $t8, .L7F0C7EF8
   nop   
  move  $a2, $zero
.L7F0C7EF8:
  bnezl $at, .L7F0C7EE4
   lh    $t8, ($v0)
  sw    $a2, 0x70($sp)
.L7F0C7F04:
  lw    $t9, 0x9c($sp)
.L7F0C7F08:
  lui   $t0, %hi(dword_CODE_bss_8008D090) 
  addiu $t0, %lo(dword_CODE_bss_8008D090) # addiu $t0, $t0, -0x2f70
  lw    $a2, 0x70($sp)
  blez  $t9, .L7F0C8600
   sw    $zero, 0xa0($sp)
  sw    $a2, 0x70($sp)
  addiu $fp, $sp, 0x10a8
.L7F0C7F24:
  jal   sub_GAME_7F0CBF2C
   li    $a0, 4
  sw    $v0, 0x80($sp)
  jal   sub_GAME_7F0CBF2C
   li    $a0, 8
  move  $s6, $v0
  jal   sub_GAME_7F0CBF2C
   li    $a0, 8
  move  $s7, $v0
  jal   sub_GAME_7F0CBF2C
   li    $a0, 4
  lw    $a1, 0xa0($sp)
  lw    $a0, 0x30b8($sp)
  lw    $t3, 0x70($sp)
  bnez  $a1, .L7F0C7FF8
   nop   
  lw    $t4, 0xc($a0)
  lui   $t3, %hi(n64imagetypes)
  sb    $s6, 8($t4)
  lw    $t5, 0xc($a0)
  sb    $s7, 9($t5)
  lw    $s4, 0x80($sp)
  lw    $v1, 0xc($a0)
  sll   $t6, $s4, 2
  addu  $t3, $t3, $t6
  lw    $t7, %lo(n64imagetypes)($t3)
  lbu   $t4, 0xb($v1)
  move  $s4, $t6
  sll   $t8, $t7, 2
  andi  $t9, $t8, 0x1c
  andi  $t5, $t4, 0xffe3
  or    $t6, $t9, $t5
  sb    $t6, 0xb($v1)
  lw    $v1, 0xc($a0)
  lui   $t3, %hi(n64pixelsizes)
  addu  $t3, $t3, $s4
  lw    $t7, %lo(n64pixelsizes)($t3)
  lbu   $t4, 0xb($v1)
  lui   $t6, %hi(imgflipvalues)
  andi  $t8, $t7, 3
  andi  $t9, $t4, 0xfffc
  or    $t5, $t8, $t9
  sb    $t5, 0xb($v1)
  lw    $v1, 0xc($a0)
  addu  $t6, $t6, $s4
  lw    $t6, %lo(imgflipvalues)($t6)
  lbu   $t9, 0xc($v1)
  sra   $t7, $t6, 0xe
  sll   $t8, $t7, 6
  andi  $t5, $t9, 0xff3f
  or    $t6, $t8, $t5
  b     .L7F0C8020
   sb    $t6, 0xc($v1)
.L7F0C7FF8:
  beqz  $t3, .L7F0C8020
   lui   $t7, %hi(dword_CODE_bss_8008D090) 
  lw    $t7, %lo(dword_CODE_bss_8008D090)($t7)
  lui   $t8, %hi(word_CODE_bss_8008C730) 
  addiu $t8, %lo(word_CODE_bss_8008C730) # addiu $t8, $t8, -0x38d0
  sll   $t4, $t7, 4
  addu  $t9, $t4, $a1
  addu  $v1, $t9, $t8
  sb    $s6, 1($v1)
  sb    $s7, 8($v1)
.L7F0C8020:
  multu $s6, $s7
  sll   $t5, $v0, 2
  mflo  $s5
  slti  $at, $s5, 0x2001
  bnezl $at, .L7F0C8044
   sltiu $at, $v0, 0xa
  b     .L7F0C8724
   move  $v0, $zero
  sltiu $at, $v0, 0xa
.L7F0C8044:
  beqz  $at, .L7F0C8534
   lui   $at, %hi(jpt_8005BD30)
  addu  $at, $at, $t5
  lw    $t5, %lo(jpt_8005BD30)($at)
  jr    $t5
   nop   
huffman_type0_1:
  lw    $t6, 0x30ac($sp)
  lw    $t3, 0x88($sp)
  move  $a1, $s6
  move  $a2, $s7
  addu  $s0, $t6, $t3
  move  $a0, $s0
  jal   image_compression0_expand
   lw    $a3, 0x80($sp)
  b     .L7F0C855C
   move  $s1, $v0
huffman_type2:
  lw    $s4, 0x80($sp)
  lui   $t4, %hi(pixelbytecounts)
  lui   $a2, %hi(pixelsamplebits)
  sll   $t7, $s4, 2
  addu  $t4, $t4, $t7
  lw    $t4, %lo(pixelbytecounts)($t4)
  addu  $a2, $a2, $t7
  lw    $a2, %lo(pixelsamplebits)($a2)
  multu $t4, $s6
  move  $s4, $t7
  move  $a0, $fp
  mflo  $t9
  nop   
  nop   
  multu $t9, $s7
  mflo  $a1
  jal   generate_sample_table
   nop   
  lui   $t8, %hi(pixelbytecounts+52)
  addu  $t8, $t8, $s4
  lw    $t8, %lo(pixelbytecounts+52)($t8)
  sll   $t5, $s5, 2
  subu  $t5, $t5, $s5
  beqz  $t8, .L7F0C80F0
   addu  $a0, $fp, $t5
  jal   image_get_alpha_values
   move  $a1, $s5
.L7F0C80F0:
  lw    $t6, 0x30ac($sp)
  lw    $t3, 0x88($sp)
  lw    $t7, 0x80($sp)
  move  $a0, $fp
  addu  $s0, $t6, $t3
  move  $a3, $s0
  move  $a1, $s6
  move  $a2, $s7
  jal   generate_link_final_image
   sw    $t7, 0x10($sp)
  b     .L7F0C855C
   move  $s1, $v0
huffman_type3:
  lw    $s4, 0x80($sp)
  lui   $t9, %hi(pixelbytecounts) 
  addiu $t9, %lo(pixelbytecounts) # addiu $t9, $t9, -0x6e88
  sll   $t4, $s4, 2
  addu  $s3, $t4, $t9
  lw    $t8, ($s3)
  move  $s4, $t4
  move  $s1, $zero
  blez  $t8, .L7F0C8184
   lui   $t5, %hi(pixelsamplebits) 
  addiu $t5, %lo(pixelsamplebits) # addiu $t5, $t5, -0x6e20
  addu  $s2, $t4, $t5
  move  $s0, $fp
  move  $a0, $s0
.L7F0C8158:
  move  $a1, $s5
  jal   generate_sample_table
   lw    $a2, ($s2)
  multu $s6, $s7
  lw    $t3, ($s3)
  addiu $s1, $s1, 1
  slt   $at, $s1, $t3
  mflo  $t6
  addu  $s0, $s0, $t6
  bnezl $at, .L7F0C8158
   move  $a0, $s0
.L7F0C8184:
  lui   $t7, %hi(pixelbytecounts+52)
  addu  $t7, $t7, $s4
  lw    $t7, %lo(pixelbytecounts+52)($t7)
  sll   $t4, $s5, 2
  subu  $t4, $t4, $s5
  beqz  $t7, .L7F0C81A8
   addu  $a0, $fp, $t4
  jal   image_get_alpha_values
   move  $a1, $s5
.L7F0C81A8:
  lw    $t9, 0x30ac($sp)
  lw    $t8, 0x88($sp)
  lw    $t5, 0x80($sp)
  move  $a0, $fp
  addu  $s0, $t9, $t8
  move  $a3, $s0
  move  $a1, $s6
  move  $a2, $s7
  jal   generate_link_final_image
   sw    $t5, 0x10($sp)
  b     .L7F0C855C
   move  $s1, $v0
huffman_type4:
  lw    $s4, 0x80($sp)
  lui   $t3, %hi(pixelbytecounts)
  move  $a0, $fp
  sll   $t6, $s4, 2
  addu  $t3, $t3, $t6
  lw    $t3, %lo(pixelbytecounts)($t3)
  move  $s4, $t6
  multu $t3, $s6
  mflo  $t7
  nop   
  nop   
  multu $t7, $s7
  mflo  $a1
  jal   type4_7_9_getsamples
   nop   
  lui   $t4, %hi(pixelbytecounts+52)
  addu  $t4, $t4, $s4
  lw    $t4, %lo(pixelbytecounts+52)($t4)
  sll   $t9, $s5, 2
  subu  $t9, $t9, $s5
  beqz  $t4, .L7F0C8238
   addu  $a0, $fp, $t9
  jal   image_get_alpha_values
   move  $a1, $s5
.L7F0C8238:
  lw    $t8, 0x30ac($sp)
  lw    $t5, 0x88($sp)
  lw    $t6, 0x80($sp)
  move  $a0, $fp
  addu  $s0, $t8, $t5
  move  $a3, $s0
  move  $a1, $s6
  move  $a2, $s7
  jal   generate_link_final_image
   sw    $t6, 0x10($sp)
  b     .L7F0C855C
   move  $s1, $v0
huffman_type5:
  lw    $t3, 0x80($sp)
  lui   $a1, %hi(pixelsamplebits+52)
  addiu $a0, $sp, 0xa8
  sll   $t7, $t3, 2
  addu  $a1, $a1, $t7
  jal   type5_6_7_getsamples
   lw    $a1, %lo(pixelsamplebits+52)($a1)
  lw    $t4, 0x30ac($sp)
  lw    $t9, 0x88($sp)
  lw    $t8, 0x80($sp)
  move  $a0, $s6
  addu  $s0, $t4, $t9
  move  $a2, $s0
  move  $a1, $s7
  addiu $a3, $sp, 0xa8
  sw    $v0, 0x10($sp)
  jal   type5_generate_link_final_image
   sw    $t8, 0x14($sp)
  b     .L7F0C855C
   move  $s1, $v0
huffman_type6:
  lw    $t5, 0x80($sp)
  lui   $a1, %hi(pixelsamplebits+52)
  addiu $a0, $sp, 0xa8
  sll   $t6, $t5, 2
  addu  $a1, $a1, $t6
  jal   type5_6_7_getsamples
   lw    $a1, %lo(pixelsamplebits+52)($a1)
  move  $s1, $v0
  move  $a0, $fp
  move  $a1, $s5
  jal   generate_sample_table
   move  $a2, $v0
  lw    $t3, 0x30ac($sp)
  lw    $t7, 0x88($sp)
  lw    $t9, 0x80($sp)
  addiu $t4, $sp, 0xa8
  addu  $s0, $t3, $t7
  move  $a3, $s0
  sw    $t4, 0x10($sp)
  move  $a0, $fp
  move  $a1, $s6
  move  $a2, $s7
  sw    $s1, 0x14($sp)
  jal   type6_7_generate_link_final_image
   sw    $t9, 0x18($sp)
  b     .L7F0C855C
   move  $s1, $v0
huffman_type7:
  lw    $t8, 0x80($sp)
  lui   $a1, %hi(pixelsamplebits+52)
  addiu $a0, $sp, 0xa8
  sll   $t5, $t8, 2
  addu  $a1, $a1, $t5
  jal   type5_6_7_getsamples
   lw    $a1, %lo(pixelsamplebits+52)($a1)
  move  $s1, $v0
  move  $a0, $fp
  jal   type4_7_9_getsamples
   move  $a1, $s5
  lw    $t6, 0x30ac($sp)
  lw    $t3, 0x88($sp)
  lw    $t4, 0x80($sp)
  addiu $t7, $sp, 0xa8
  addu  $s0, $t6, $t3
  move  $a3, $s0
  sw    $t7, 0x10($sp)
  move  $a0, $fp
  move  $a1, $s6
  move  $a2, $s7
  sw    $s1, 0x14($sp)
  jal   type6_7_generate_link_final_image
   sw    $t4, 0x18($sp)
  b     .L7F0C855C
   move  $s1, $v0
huffman_type8:
  lw    $s4, 0x80($sp)
  li    $a0, 3
  sll   $t9, $s4, 2
  jal   sub_GAME_7F0CBF2C
   move  $s4, $t9
  lui   $t8, %hi(pixelbytecounts) 
  addiu $t8, %lo(pixelbytecounts) # addiu $t8, $t8, -0x6e88
  addu  $s3, $s4, $t8
  lw    $t5, ($s3)
  lui   $t3, %hi(pixelsamplebits) 
  addiu $t3, %lo(pixelsamplebits) # addiu $t3, $t3, -0x6e20
  multu $t5, $s6
  addu  $s2, $s4, $t3
  move  $s0, $v0
  lw    $a2, ($s2)
  move  $a0, $fp
  mflo  $t6
  nop   
  nop   
  multu $t6, $s7
  mflo  $a1
  jal   generate_sample_table
   nop   
  lw    $t7, ($s3)
  lw    $t4, ($s2)
  move  $a0, $fp
  multu $t7, $s7
  move  $a1, $s6
  move  $a3, $s0
  sw    $t4, 0x10($sp)
  mflo  $a2
  jal   type8_9_doohick
   nop   
  lui   $t9, %hi(pixelbytecounts+52)
  addu  $t9, $t9, $s4
  lw    $t9, %lo(pixelbytecounts+52)($t9)
  sll   $t8, $s5, 2
  subu  $t8, $t8, $s5
  beqz  $t9, .L7F0C8434
   addu  $a0, $fp, $t8
  jal   image_get_alpha_values
   move  $a1, $s5
.L7F0C8434:
  lw    $t5, 0x30ac($sp)
  lw    $t6, 0x88($sp)
  lw    $t3, 0x80($sp)
  move  $a0, $fp
  addu  $s0, $t5, $t6
  move  $a3, $s0
  move  $a1, $s6
  move  $a2, $s7
  jal   generate_link_final_image
   sw    $t3, 0x10($sp)
  b     .L7F0C855C
   move  $s1, $v0
huffman_type9:
  lw    $s4, 0x80($sp)
  li    $a0, 3
  sll   $t7, $s4, 2
  jal   sub_GAME_7F0CBF2C
   move  $s4, $t7
  lui   $t4, %hi(pixelbytecounts) 
  addiu $t4, %lo(pixelbytecounts) # addiu $t4, $t4, -0x6e88
  addu  $s3, $s4, $t4
  lw    $t9, ($s3)
  move  $s0, $v0
  move  $a0, $fp
  multu $t9, $s6
  mflo  $t8
  nop   
  nop   
  multu $t8, $s7
  mflo  $a1
  jal   type4_7_9_getsamples
   nop   
  lw    $t5, ($s3)
  lui   $t6, %hi(pixelsamplebits)
  addu  $t6, $t6, $s4
  multu $t5, $s7
  lw    $t6, %lo(pixelsamplebits)($t6)
  move  $a0, $fp
  move  $a1, $s6
  move  $a3, $s0
  sw    $t6, 0x10($sp)
  mflo  $a2
  jal   type8_9_doohick
   nop   
  lui   $t3, %hi(pixelbytecounts+52)
  addu  $t3, $t3, $s4
  lw    $t3, %lo(pixelbytecounts+52)($t3)
  sll   $t7, $s5, 2
  subu  $t7, $t7, $s5
  beqz  $t3, .L7F0C8504
   addu  $a0, $fp, $t7
  jal   image_get_alpha_values
   move  $a1, $s5
.L7F0C8504:
  lw    $t4, 0x30ac($sp)
  lw    $t9, 0x88($sp)
  lw    $t8, 0x80($sp)
  move  $a0, $fp
  addu  $s0, $t4, $t9
  move  $a3, $s0
  move  $a1, $s6
  move  $a2, $s7
  jal   generate_link_final_image
   sw    $t8, 0x10($sp)
  b     .L7F0C855C
   move  $s1, $v0
def_7F0C8054:
.L7F0C8534:
  lui   $t5, %hi(dword_CODE_bss_8008D090) 
  lw    $t5, %lo(dword_CODE_bss_8008D090)($t5)
  lui   $t7, %hi(word_CODE_bss_8008C730) 
  addiu $t7, %lo(word_CODE_bss_8008C730) # addiu $t7, $t7, -0x38d0
  sll   $t6, $t5, 4
  addu  $v1, $t6, $t7
  sb    $s6, 1($v1)
  sb    $s7, 8($v1)
.L7F0C8554:
  b     .L7F0C8554
   nop   
.L7F0C855C:
  lw    $t4, 0x30b0($sp)
  li    $at, 1
  lw    $t9, 0x30b4($sp)
  bne   $t4, $at, .L7F0C8588
   nop   
  blez  $t9, .L7F0C8588
   move  $a0, $s0
  move  $a1, $s6
  move  $a2, $s7
  jal   sub_GAME_7F0CB67C
   lw    $a3, 0x80($sp)
.L7F0C8588:
  lui   $v0, %hi(img_bitcount)
  lw    $t5, 0x88($sp)
  addiu $v0, %lo(img_bitcount) # addiu $v0, $v0, -0x2f58
  lw    $t3, ($v0)
  addiu $s1, $s1, 7
  li    $at, -8
  and   $t8, $s1, $at
  addu  $t6, $t5, $t8
  bnez  $t3, .L7F0C85C8
   sw    $t6, 0x88($sp)
  lui   $t7, %hi(img_curpos) 
  lw    $t7, %lo(img_curpos)($t7)
  lui   $at, %hi(img_curpos)
  addiu $t4, $t7, 1
  b     .L7F0C85CC
   sw    $t4, %lo(img_curpos)($at)
.L7F0C85C8:
  sw    $zero, ($v0)
.L7F0C85CC:
  lw    $t9, 0xa0($sp)
  lw    $t5, 0x9c($sp)
  addiu $t8, $t9, 1
  bne   $t8, $t5, .L7F0C7F24
   sw    $t8, 0xa0($sp)
  lui   $t0, %hi(dword_CODE_bss_8008D090) 
  addiu $t0, %lo(dword_CODE_bss_8008D090) # addiu $t0, $t0, -0x2f70
  sw    $s6, 0x98($sp)
  sw    $s7, 0x94($sp)
  lw    $t2, 0x30b4($sp)
  lw    $t1, 0x30b0($sp)
  lw    $a3, 0x30b8($sp)
  lw    $a2, 0x70($sp)
.L7F0C8600:
  lw    $s6, 0x98($sp)
  beqz  $a2, .L7F0C8640
   lw    $s7, 0x94($sp)
  lw    $t6, 0xc($a3)
  lw    $a1, ($t0)
  lui   $at, %hi(word_CODE_bss_8008C730)
  lw    $t3, ($t6)
  sll   $t4, $a1, 4
  addu  $at, $at, $t4
  srl   $t7, $t3, 0x14
  sh    $t7, %lo(word_CODE_bss_8008C730)($at)
  addiu $t9, $a1, 1
  slti  $at, $t9, 0x96
  bnez  $at, .L7F0C8640
   sw    $t9, ($t0)
  sw    $zero, ($t0)
.L7F0C8640:
  bnez  $t1, .L7F0C8720
   slti  $at, $t2, 2
  bnez  $at, .L7F0C8704
   lw    $s4, 0x30ac($sp)
  lw    $t3, 0x30b4($sp)
  lw    $t5, 0x88($sp)
  li    $t6, 1
  slti  $at, $t3, 2
  move  $s2, $s6
  move  $s3, $s7
  sw    $t6, 0xa0($sp)
  bnez  $at, .L7F0C86E8
   addu  $s0, $s4, $t5
.L7F0C8674:
  lw    $t7, 0x80($sp)
  move  $a0, $s4
  move  $a1, $s0
  move  $a2, $s2
  move  $a3, $s3
  jal   image_decompresion_related
   sw    $t7, 0x10($sp)
  move  $s1, $v0
  move  $a0, $s4
  move  $a1, $s2
  move  $a2, $s3
  jal   sub_GAME_7F0CB67C
   lw    $a3, 0x80($sp)
  lw    $t6, 0xa0($sp)
  lw    $t4, 0x88($sp)
  lw    $t7, 0x30b4($sp)
  addiu $s2, $s2, 1
  addiu $s3, $s3, 1
  sra   $t8, $s2, 1
  sra   $t5, $s3, 1
  move  $s4, $s0
  addiu $t3, $t6, 1
  addu  $t9, $t4, $s1
  sw    $t3, 0xa0($sp)
  sw    $t9, 0x88($sp)
  move  $s2, $t8
  move  $s3, $t5
  bne   $t3, $t7, .L7F0C8674
   addu  $s0, $s0, $s1
.L7F0C86E8:
  move  $a0, $s4
  move  $a1, $s2
  move  $a2, $s3
  jal   sub_GAME_7F0CB67C
   lw    $a3, 0x80($sp)
  b     .L7F0C8724
   lw    $v0, 0x88($sp)
.L7F0C8704:
  li    $at, 1
  bne   $t2, $at, .L7F0C8720
   lw    $a0, 0x30ac($sp)
  move  $a1, $s6
  move  $a2, $s7
  jal   sub_GAME_7F0CB67C
   lw    $a3, 0x80($sp)
.L7F0C8720:
  lw    $v0, 0x88($sp)
.L7F0C8724:
  lw    $ra, 0x4c($sp)
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
   addiu $sp, $sp, 0x30a8
");

asm(R"
.late_rodata
/*D:8005BD58*/
glabel jpt_8005BD58
.word .L7F0C87CC
.word .L7F0C87F0
.word .L7F0C87CC
.word .L7F0C87F0
.word .L7F0C87F0
.word .L7F0C8814
.word .L7F0C8838
.word .L7F0C8814
.word .L7F0C8838

/*D:8005BD7C*/
glabel jpt_8005BD7C
.word .L7F0C887C
.word .L7F0C8A2C
.word .L7F0C887C
.word .L7F0C8A2C
.word .L7F0C8BE0
.word .L7F0C8D1C
.word .L7F0C8F00
.word .L7F0C8E34
.word .L7F0C9090
.text
glabel image_decompresion_related
  addiu $sp, $sp, -0xb8
  lw    $v0, 0xc8($sp)
  addiu $t9, $a3, 1
  sw    $s7, 0x20($sp)
  sw    $s6, 0x1c($sp)
  sw    $s5, 0x18($sp)
  sw    $s4, 0x14($sp)
  sw    $s1, 8($sp)
  sw    $s0, 4($sp)
  sra   $t4, $t9, 1
  sltiu $at, $v0, 9
  move  $s5, $a2
  move  $s7, $a3
  sw    $fp, 0x24($sp)
  sw    $s3, 0x10($sp)
  sw    $s2, 0xc($sp)
  move  $t1, $a1
  move  $s6, $a1
  move  $s1, $a1
  move  $v1, $a0
  move  $s4, $a0
  move  $s0, $a0
  beqz  $at, .L7F0C8858
   sw    $t4, 0x4c($sp)
  sll   $t8, $v0, 2
  lui   $at, %hi(jpt_8005BD58)
  addu  $at, $at, $t8
  lw    $t8, %lo(jpt_8005BD58)($at)
  jr    $t8
   nop   
.L7F0C87CC:
  addiu $t6, $s5, 1
  sra   $t9, $t6, 1
  addiu $t7, $t9, 3
  addiu $s2, $s5, 3
  andi  $t8, $t7, 0xffc
  andi  $t6, $s2, 0xffc
  sw    $t8, 0xa8($sp)
  b     .L7F0C8858
   sw    $t6, 0xac($sp)
.L7F0C87F0:
  addiu $t9, $s5, 1
  sra   $t7, $t9, 1
  addiu $t8, $t7, 3
  addiu $s2, $s5, 3
  andi  $t6, $t8, 0xffc
  andi  $t9, $s2, 0xffc
  sw    $t6, 0xa8($sp)
  b     .L7F0C8858
   sw    $t9, 0xac($sp)
.L7F0C8814:
  addiu $t7, $s5, 1
  sra   $t8, $t7, 1
  addiu $t6, $t8, 7
  addiu $s2, $s5, 7
  andi  $t9, $t6, 0xff8
  andi  $t7, $s2, 0xff8
  sw    $t9, 0xa8($sp)
  b     .L7F0C8858
   sw    $t7, 0xac($sp)
.L7F0C8838:
  addiu $t8, $s5, 1
  sra   $t6, $t8, 1
  addiu $t9, $t6, 0xf
  addiu $s2, $s5, 0xf
  andi  $t7, $t9, 0xff0
  andi  $t8, $s2, 0xff0
  sw    $t7, 0xa8($sp)
  sw    $t8, 0xac($sp)
def_7F0C87C4:
.L7F0C8858:
  sltiu $at, $v0, 9
  beqz  $at, .L7F0C91A0
   lw    $s2, 0xac($sp)
  sll   $t6, $v0, 2
  lui   $at, %hi(jpt_8005BD7C)
  addu  $at, $at, $t6
  lw    $t6, %lo(jpt_8005BD7C)($at)
  jr    $t6
   nop   
.L7F0C887C:
  blez  $s7, .L7F0C8A10
   move  $fp, $zero
  lw    $a0, 0xa8($sp)
  move  $a1, $s2
  sll   $t7, $a1, 3
  sll   $t9, $a0, 2
  move  $a0, $t9
  move  $a1, $t7
.L7F0C889C:
  addiu $t8, $fp, 1
  slt   $at, $t8, $s7
  beqz  $at, .L7F0C88B4
   move  $t0, $zero
  b     .L7F0C88B8
   move  $s3, $s2
.L7F0C88B4:
  move  $s3, $zero
.L7F0C88B8:
  blez  $s2, .L7F0C8A00
   addiu $fp, $fp, 2
  sll   $t6, $s3, 2
  addu  $t5, $v1, $t6
  move  $s0, $t5
  move  $a2, $v1
.L7F0C88D0:
  addiu $v0, $t0, 1
  slt   $at, $v0, $s5
  beqz  $at, .L7F0C88E8
   move  $a3, $t0
  b     .L7F0C88E8
   move  $a3, $v0
.L7F0C88E8:
  sll   $t3, $a3, 2
  addu  $t9, $v1, $t3
  lw    $t2, ($t9)
  lw    $v0, ($a2)
  addu  $t7, $t5, $t3
  lw    $t4, ($s0)
  lw    $s1, ($t7)
  srl   $t9, $t2, 0x18
  andi  $t7, $t9, 0xff
  srl   $t8, $v0, 0x18
  andi  $t6, $t8, 0xff
  addu  $t8, $t6, $t7
  srl   $t9, $t4, 0x18
  andi  $t6, $t9, 0xff
  addu  $t7, $t8, $t6
  srl   $t9, $s1, 0x18
  andi  $t8, $t9, 0xff
  addu  $t6, $t7, $t8
  srl   $t7, $t6, 2
  sll   $t8, $t7, 0x18
  srl   $t6, $v0, 0x10
  andi  $t9, $t6, 0xff
  srl   $t7, $t2, 0x10
  andi  $t6, $t7, 0xff
  addu  $t7, $t9, $t6
  srl   $t9, $t4, 0x10
  andi  $t6, $t9, 0xff
  addu  $t9, $t7, $t6
  srl   $t7, $s1, 0x10
  andi  $t6, $t7, 0xff
  addu  $t7, $t9, $t6
  srl   $t9, $t7, 2
  andi  $t6, $t9, 0xff
  sll   $t7, $t6, 0x10
  or    $t9, $t8, $t7
  srl   $t6, $v0, 8
  andi  $t8, $t6, 0xff
  srl   $t7, $t2, 8
  andi  $t6, $t7, 0xff
  addu  $t7, $t8, $t6
  srl   $t8, $t4, 8
  andi  $t6, $t8, 0xff
  addu  $t8, $t7, $t6
  srl   $t7, $s1, 8
  andi  $t6, $t7, 0xff
  addu  $t7, $t8, $t6
  srl   $t8, $t7, 2
  andi  $t6, $t8, 0xff
  sll   $t7, $t6, 8
  or    $t8, $t9, $t7
  andi  $t9, $t2, 0xff
  andi  $t6, $v0, 0xff
  addu  $t7, $t6, $t9
  andi  $t6, $t4, 0xff
  addu  $t9, $t7, $t6
  andi  $t7, $s1, 0xff
  addu  $t6, $t9, $t7
  addiu $t9, $t6, 1
  srl   $t7, $t9, 2
  andi  $t6, $t7, 0xff
  sra   $t7, $t0, 1
  or    $t9, $t8, $t6
  addiu $t0, $t0, 2
  sll   $t8, $t7, 2
  slt   $at, $t0, $s2
  addu  $t6, $t1, $t8
  addiu $a2, $a2, 8
  addiu $s0, $s0, 8
  bnez  $at, .L7F0C88D0
   sw    $t9, ($t6)
.L7F0C8A00:
  slt   $at, $fp, $s7
  addu  $t1, $t1, $a0
  bnez  $at, .L7F0C889C
   addu  $v1, $v1, $a1
.L7F0C8A10:
  lw    $t7, 0x4c($sp)
  lw    $t8, 0xa8($sp)
  multu $t7, $t8
  mflo  $v0
  sll   $t9, $v0, 2
  b     .L7F0C91A4
   move  $v0, $t9
.L7F0C8A2C:
  blez  $s7, .L7F0C8BC4
   move  $fp, $zero
  lw    $t6, 0xa8($sp)
  sll   $t9, $s2, 2
  sw    $t9, 0x34($sp)
  sll   $t7, $t6, 1
  sw    $t7, 0x38($sp)
.L7F0C8A48:
  addiu $t6, $fp, 1
  slt   $at, $t6, $s7
  beqz  $at, .L7F0C8A60
   move  $t0, $zero
  b     .L7F0C8A64
   move  $s3, $s2
.L7F0C8A60:
  move  $s3, $zero
.L7F0C8A64:
  blez  $s2, .L7F0C8BAC
   addiu $fp, $fp, 2
  sll   $t7, $s3, 1
  addu  $s1, $s4, $t7
  move  $s0, $s1
  move  $t5, $s4
.L7F0C8A7C:
  addiu $v0, $t0, 1
  slt   $at, $v0, $s5
  beqz  $at, .L7F0C8A94
   move  $a3, $t0
  b     .L7F0C8A94
   move  $a3, $v0
.L7F0C8A94:
  sll   $a2, $a3, 1
  addu  $t8, $s4, $a2
  lhu   $t2, ($t8)
  lhu   $t1, ($t5)
  addu  $t9, $s1, $a2
  lhu   $t3, ($s0)
  lhu   $t4, ($t9)
  sra   $t8, $t2, 0xb
  andi  $t9, $t8, 0x1f
  sra   $t6, $t1, 0xb
  andi  $t7, $t6, 0x1f
  addu  $t6, $t7, $t9
  sra   $t8, $t3, 0xb
  andi  $t7, $t8, 0x1f
  addu  $t9, $t6, $t7
  sra   $t8, $t4, 0xb
  andi  $t6, $t8, 0x1f
  addu  $t7, $t9, $t6
  sra   $t9, $t7, 2
  sll   $t6, $t9, 0xb
  sra   $t7, $t1, 6
  andi  $t8, $t7, 0x1f
  sra   $t9, $t2, 6
  andi  $t7, $t9, 0x1f
  addu  $t9, $t8, $t7
  sra   $t8, $t3, 6
  andi  $t7, $t8, 0x1f
  addu  $t8, $t9, $t7
  sra   $t9, $t4, 6
  andi  $t7, $t9, 0x1f
  addu  $t9, $t8, $t7
  sra   $t8, $t9, 2
  andi  $t7, $t8, 0x1f
  sll   $t9, $t7, 6
  or    $t8, $t6, $t9
  sra   $t7, $t1, 1
  andi  $t6, $t7, 0x1f
  sra   $t9, $t2, 1
  andi  $t7, $t9, 0x1f
  addu  $t9, $t6, $t7
  sra   $t6, $t3, 1
  andi  $t7, $t6, 0x1f
  addu  $t6, $t9, $t7
  sra   $t9, $t4, 1
  andi  $t7, $t9, 0x1f
  addu  $t9, $t6, $t7
  sra   $t6, $t9, 2
  andi  $t7, $t6, 0x1f
  sll   $t9, $t7, 1
  or    $t6, $t8, $t9
  andi  $t8, $t2, 1
  andi  $t7, $t1, 1
  addu  $t9, $t7, $t8
  andi  $t7, $t3, 1
  addu  $t8, $t9, $t7
  andi  $t9, $t4, 1
  addu  $t7, $t8, $t9
  addiu $t8, $t7, 2
  sra   $t9, $t8, 2
  andi  $t7, $t9, 1
  sra   $t9, $t0, 1
  or    $t8, $t6, $t7
  addiu $t0, $t0, 2
  sll   $t6, $t9, 1
  slt   $at, $t0, $s2
  addu  $t7, $s6, $t6
  addiu $t5, $t5, 4
  addiu $s0, $s0, 4
  bnez  $at, .L7F0C8A7C
   sh    $t8, ($t7)
.L7F0C8BAC:
  lw    $t9, 0x38($sp)
  lw    $t6, 0x34($sp)
  slt   $at, $fp, $s7
  addu  $s6, $s6, $t9
  bnez  $at, .L7F0C8A48
   addu  $s4, $s4, $t6
.L7F0C8BC4:
  lw    $t8, 0x4c($sp)
  lw    $t7, 0xa8($sp)
  multu $t8, $t7
  mflo  $v0
  sll   $t9, $v0, 1
  b     .L7F0C91A4
   move  $v0, $t9
.L7F0C8BE0:
  blez  $s7, .L7F0C8D00
   move  $fp, $zero
  lw    $t6, 0xa8($sp)
  sll   $t9, $s2, 2
  sw    $t9, 0x34($sp)
  sll   $t8, $t6, 1
  sw    $t8, 0x38($sp)
.L7F0C8BFC:
  addiu $t6, $fp, 1
  slt   $at, $t6, $s7
  beqz  $at, .L7F0C8C14
   move  $t0, $zero
  b     .L7F0C8C18
   move  $s3, $s2
.L7F0C8C14:
  move  $s3, $zero
.L7F0C8C18:
  blez  $s2, .L7F0C8CE8
   addiu $fp, $fp, 2
  sll   $t8, $s3, 1
  addu  $s1, $s4, $t8
  move  $s0, $s1
  move  $t5, $s4
.L7F0C8C30:
  addiu $v0, $t0, 1
  slt   $at, $v0, $s5
  beqz  $at, .L7F0C8C48
   move  $a3, $t0
  b     .L7F0C8C48
   move  $a3, $v0
.L7F0C8C48:
  sll   $a2, $a3, 1
  addu  $t7, $s4, $a2
  lhu   $t2, ($t7)
  lhu   $t1, ($t5)
  addu  $t9, $s1, $a2
  lhu   $t3, ($s0)
  lhu   $t4, ($t9)
  sra   $t7, $t2, 8
  andi  $t9, $t7, 0xff
  sra   $t6, $t1, 8
  andi  $t8, $t6, 0xff
  addu  $t6, $t8, $t9
  sra   $t7, $t3, 8
  andi  $t8, $t7, 0xff
  addu  $t9, $t6, $t8
  sra   $t7, $t4, 8
  andi  $t6, $t7, 0xff
  addu  $t8, $t9, $t6
  sra   $t9, $t8, 2
  sll   $t6, $t9, 8
  andi  $t7, $t2, 0xff
  andi  $t8, $t1, 0xff
  addu  $t9, $t8, $t7
  andi  $t8, $t3, 0xff
  addu  $t7, $t9, $t8
  andi  $t9, $t4, 0xff
  addu  $t8, $t7, $t9
  addiu $t7, $t8, 1
  sra   $t9, $t7, 2
  andi  $t8, $t9, 0xff
  sra   $t9, $t0, 1
  or    $t7, $t6, $t8
  addiu $t0, $t0, 2
  sll   $t6, $t9, 1
  slt   $at, $t0, $s2
  addu  $t8, $s6, $t6
  addiu $t5, $t5, 4
  addiu $s0, $s0, 4
  bnez  $at, .L7F0C8C30
   sh    $t7, ($t8)
.L7F0C8CE8:
  lw    $t9, 0x38($sp)
  lw    $t6, 0x34($sp)
  slt   $at, $fp, $s7
  addu  $s6, $s6, $t9
  bnez  $at, .L7F0C8BFC
   addu  $s4, $s4, $t6
.L7F0C8D00:
  lw    $t7, 0x4c($sp)
  lw    $t8, 0xa8($sp)
  multu $t7, $t8
  mflo  $v0
  sll   $t9, $v0, 1
  b     .L7F0C91A4
   move  $v0, $t9
.L7F0C8D1C:
  blez  $s7, .L7F0C8E1C
   move  $fp, $zero
  sll   $s4, $s2, 1
.L7F0C8D28:
  addiu $t6, $fp, 1
  slt   $at, $t6, $s7
  beqz  $at, .L7F0C8D40
   move  $t0, $zero
  b     .L7F0C8D44
   move  $s3, $s2
.L7F0C8D40:
  move  $s3, $zero
.L7F0C8D44:
  blez  $s2, .L7F0C8E08
   addiu $fp, $fp, 2
  move  $t4, $s0
  addu  $t5, $s3, $s0
.L7F0C8D54:
  addiu $v0, $t0, 1
  slt   $at, $v0, $s5
  beqz  $at, .L7F0C8D6C
   move  $a3, $t0
  b     .L7F0C8D6C
   move  $a3, $v0
.L7F0C8D6C:
  addu  $t7, $s0, $a3
  lbu   $t1, ($t7)
  addu  $t8, $s3, $a3
  lbu   $t3, ($t4)
  addu  $t9, $t8, $s0
  lbu   $t2, ($t5)
  lbu   $a2, ($t9)
  sra   $t8, $t1, 4
  andi  $t9, $t8, 0xf
  sra   $t6, $t3, 4
  andi  $t7, $t6, 0xf
  addu  $t6, $t7, $t9
  sra   $t8, $t2, 4
  andi  $t7, $t8, 0xf
  addu  $t9, $t6, $t7
  sra   $t8, $a2, 4
  andi  $t6, $t8, 0xf
  addu  $t7, $t9, $t6
  sll   $t8, $t7, 2
  andi  $t9, $t8, 0xf0
  andi  $t7, $t1, 0xf
  andi  $t6, $t3, 0xf
  addu  $t8, $t6, $t7
  andi  $t6, $t2, 0xf
  addu  $t7, $t8, $t6
  andi  $t8, $a2, 0xf
  addu  $t6, $t7, $t8
  addiu $t7, $t6, 1
  sra   $t8, $t7, 2
  andi  $t6, $t8, 0xf
  sra   $t8, $t0, 1
  addiu $t0, $t0, 2
  or    $t7, $t9, $t6
  slt   $at, $t0, $s2
  addu  $t9, $s1, $t8
  addiu $t4, $t4, 2
  addiu $t5, $t5, 2
  bnez  $at, .L7F0C8D54
   sb    $t7, ($t9)
.L7F0C8E08:
  lw    $t6, 0xa8($sp)
  slt   $at, $fp, $s7
  addu  $s0, $s0, $s4
  bnez  $at, .L7F0C8D28
   addu  $s1, $s1, $t6
.L7F0C8E1C:
  lw    $t8, 0x4c($sp)
  lw    $t7, 0xa8($sp)
  multu $t8, $t7
  mflo  $v0
  b     .L7F0C91A8
   lw    $s0, 4($sp)
.L7F0C8E34:
  blez  $s7, .L7F0C8EE8
   move  $fp, $zero
  sll   $s4, $s2, 1
.L7F0C8E40:
  addiu $t9, $fp, 1
  slt   $at, $t9, $s7
  beqz  $at, .L7F0C8E58
   move  $t0, $zero
  b     .L7F0C8E5C
   move  $s3, $s2
.L7F0C8E58:
  move  $s3, $zero
.L7F0C8E5C:
  blez  $s2, .L7F0C8ED4
   addiu $fp, $fp, 2
  move  $t4, $s0
  addu  $t5, $s3, $s0
.L7F0C8E6C:
  addiu $v0, $t0, 1
  slt   $at, $v0, $s5
  beqz  $at, .L7F0C8E84
   move  $a3, $t0
  b     .L7F0C8E84
   move  $a3, $v0
.L7F0C8E84:
  addu  $t6, $s0, $a3
  lbu   $t3, ($t4)
  lbu   $t1, ($t6)
  addu  $t8, $s3, $a3
  lbu   $t2, ($t5)
  addu  $t7, $t8, $s0
  lbu   $a2, ($t7)
  addu  $t9, $t3, $t1
  addu  $t6, $t9, $t2
  addu  $t8, $t6, $a2
  addiu $t7, $t8, 1
  sra   $t8, $t0, 1
  addiu $t0, $t0, 2
  sra   $t6, $t7, 2
  slt   $at, $t0, $s2
  addu  $t7, $s1, $t8
  addiu $t4, $t4, 2
  addiu $t5, $t5, 2
  bnez  $at, .L7F0C8E6C
   sb    $t6, ($t7)
.L7F0C8ED4:
  lw    $t9, 0xa8($sp)
  slt   $at, $fp, $s7
  addu  $s0, $s0, $s4
  bnez  $at, .L7F0C8E40
   addu  $s1, $s1, $t9
.L7F0C8EE8:
  lw    $t8, 0x4c($sp)
  lw    $t6, 0xa8($sp)
  multu $t8, $t6
  mflo  $v0
  b     .L7F0C91A8
   lw    $s0, 4($sp)
.L7F0C8F00:
  blez  $s7, .L7F0C9078
   move  $fp, $zero
  lw    $s4, 0xa8($sp)
  sra   $t7, $s4, 1
  move  $s4, $t7
.L7F0C8F14:
  blez  $s2, .L7F0C9064
   move  $t0, $zero
  addiu $a3, $fp, 1
.L7F0C8F20:
  sra   $t5, $t0, 1
  addu  $v0, $t5, $s0
  slt   $at, $a3, $s7
  beqz  $at, .L7F0C8F3C
   lbu   $t3, ($v0)
  b     .L7F0C8F40
   sra   $s3, $s2, 1
.L7F0C8F3C:
  move  $s3, $zero
.L7F0C8F40:
  addu  $t9, $s3, $t5
  addu  $t8, $t9, $s0
  slt   $at, $a3, $s7
  lbu   $t1, ($t8)
  beqz  $at, .L7F0C8F60
   lbu   $t2, 1($v0)
  b     .L7F0C8F64
   sra   $s3, $s2, 1
.L7F0C8F60:
  move  $s3, $zero
.L7F0C8F64:
  addu  $t6, $s3, $t5
  addu  $t7, $t6, $s0
  lbu   $a2, 1($t7)
  sra   $t6, $t3, 1
  andi  $t7, $t6, 7
  sra   $t9, $t3, 5
  andi  $t8, $t9, 7
  addu  $t9, $t8, $t7
  sra   $t6, $t1, 5
  andi  $t8, $t6, 7
  addu  $t7, $t9, $t8
  sra   $t6, $t1, 1
  andi  $t9, $t6, 7
  addu  $t8, $t7, $t9
  sll   $t6, $t8, 3
  andi  $t7, $t6, 0xe0
  sra   $t9, $t2, 5
  andi  $t8, $t9, 7
  sra   $t6, $t2, 1
  andi  $t9, $t6, 7
  addu  $t6, $t8, $t9
  sra   $t8, $a2, 5
  andi  $t9, $t8, 7
  addu  $t8, $t6, $t9
  sra   $t6, $a2, 1
  andi  $t9, $t6, 7
  addu  $t6, $t8, $t9
  sra   $t8, $t6, 1
  andi  $t9, $t8, 0xe
  or    $t6, $t7, $t9
  sra   $t8, $t3, 4
  andi  $t7, $t8, 1
  andi  $t9, $t3, 1
  addu  $t8, $t7, $t9
  sra   $t7, $t1, 4
  andi  $t9, $t7, 1
  addu  $t7, $t8, $t9
  andi  $t8, $t1, 1
  addu  $t9, $t7, $t8
  addiu $t7, $t9, 1
  sll   $t8, $t7, 2
  andi  $t9, $t8, 0x10
  sra   $t7, $t2, 4
  andi  $t8, $t7, 1
  andi  $t7, $t2, 1
  addu  $t8, $t8, $t7
  sw    $t6, 0x28($sp)
  sra   $t7, $a2, 4
  andi  $t6, $t7, 1
  addu  $t6, $t8, $t6
  andi  $t8, $a2, 1
  addu  $t7, $t6, $t8
  addiu $t6, $t7, 1
  sra   $t8, $t6, 2
  andi  $t7, $t8, 1
  lw    $t8, 0x28($sp)
  or    $t6, $t9, $t7
  sra   $t7, $t0, 2
  addiu $t0, $t0, 4
  or    $t9, $t8, $t6
  slt   $at, $t0, $s2
  addu  $t8, $s1, $t7
  bnez  $at, .L7F0C8F20
   sb    $t9, ($t8)
.L7F0C9064:
  addiu $fp, $fp, 2
  slt   $at, $fp, $s7
  addu  $s1, $s1, $s4
  bnez  $at, .L7F0C8F14
   addu  $s0, $s0, $s2
.L7F0C9078:
  lw    $t6, 0xa8($sp)
  sra   $t7, $t6, 1
  multu $t7, $t4
  mflo  $v0
  b     .L7F0C91A8
   lw    $s0, 4($sp)
.L7F0C9090:
  blez  $s7, .L7F0C9188
   move  $fp, $zero
  lw    $s4, 0xa8($sp)
  sra   $t9, $s4, 1
  move  $s4, $t9
.L7F0C90A4:
  blez  $s2, .L7F0C9174
   move  $t0, $zero
  addiu $a3, $fp, 1
.L7F0C90B0:
  sra   $t5, $t0, 1
  addu  $v0, $t5, $s0
  slt   $at, $a3, $s7
  beqz  $at, .L7F0C90CC
   lbu   $t3, ($v0)
  b     .L7F0C90D0
   sra   $s3, $s2, 1
.L7F0C90CC:
  move  $s3, $zero
.L7F0C90D0:
  addu  $t8, $s3, $t5
  addu  $t6, $t8, $s0
  slt   $at, $a3, $s7
  lbu   $t1, ($t6)
  beqz  $at, .L7F0C90F0
   lbu   $t2, 1($v0)
  b     .L7F0C90F4
   sra   $s3, $s2, 1
.L7F0C90F0:
  move  $s3, $zero
.L7F0C90F4:
  addu  $t7, $s3, $t5
  addu  $t9, $t7, $s0
  sra   $t8, $t3, 4
  andi  $t6, $t8, 0xf
  lbu   $a2, 1($t9)
  andi  $t7, $t3, 0xf
  addu  $t9, $t6, $t7
  sra   $t8, $t1, 4
  andi  $t6, $t8, 0xf
  addu  $t7, $t9, $t6
  andi  $t8, $t1, 0xf
  addu  $t9, $t7, $t8
  sll   $t6, $t9, 2
  andi  $t7, $t6, 0xf0
  sra   $t8, $t2, 4
  andi  $t9, $t8, 0xf
  andi  $t6, $t2, 0xf
  addu  $t8, $t9, $t6
  sra   $t9, $a2, 4
  andi  $t6, $t9, 0xf
  addu  $t9, $t8, $t6
  andi  $t8, $a2, 0xf
  addu  $t6, $t9, $t8
  sra   $t9, $t6, 2
  andi  $t8, $t9, 0xf
  sra   $t9, $t0, 2
  addiu $t0, $t0, 4
  or    $t6, $t7, $t8
  slt   $at, $t0, $s2
  addu  $t7, $s1, $t9
  bnez  $at, .L7F0C90B0
   sb    $t6, ($t7)
.L7F0C9174:
  addiu $fp, $fp, 2
  slt   $at, $fp, $s7
  addu  $s1, $s1, $s4
  bnez  $at, .L7F0C90A4
   addu  $s0, $s0, $s2
.L7F0C9188:
  lw    $t8, 0xa8($sp)
  sra   $t9, $t8, 1
  multu $t9, $t4
  mflo  $v0
  b     .L7F0C91A8
   lw    $s0, 4($sp)
def_7F0C8874:
.L7F0C91A0:
  move  $v0, $zero
.L7F0C91A4:
  lw    $s0, 4($sp)
.L7F0C91A8:
  lw    $s1, 8($sp)
  lw    $s2, 0xc($sp)
  lw    $s3, 0x10($sp)
  lw    $s4, 0x14($sp)
  lw    $s5, 0x18($sp)
  lw    $s6, 0x1c($sp)
  lw    $s7, 0x20($sp)
  lw    $fp, 0x24($sp)
  jr    $ra
   addiu $sp, $sp, 0xb8
");

asm(R"
glabel generate_sample_table
  addiu $sp, $sp, -0x3078
  sw    $ra, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s1, 0x1c($sp)
  move  $s4, $a2
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s0, 0x18($sp)
  sw    $a0, 0x3078($sp)
  sw    $a1, 0x307c($sp)
  move  $ra, $zero
  blez  $a2, .L7F0C9228
   move  $s1, $zero
  addiu $s0, $sp, 0x2078
.L7F0C9208:
  sw    $ra, 0x5c($sp)
  jal   sub_GAME_7F0CBF2C
   li    $a0, 8
  addiu $s1, $s1, 1
  lw    $ra, 0x5c($sp)
  addiu $s0, $s0, 2
  bne   $s1, $s4, .L7F0C9208
   sh    $v0, -2($s0)
.L7F0C9228:
  addiu $v0, $sp, 0x78
  addiu $a0, $sp, 0x2078
  li    $v1, -1
.L7F0C9234:
  addiu $v0, $v0, 4
  sltu  $at, $v0, $a0
  sh    $v1, -4($v0)
  bnez  $at, .L7F0C9234
   sh    $v1, -2($v0)
  li    $t0, 9999
  li    $a2, 9999
  blez  $s4, .L7F0C9378
   move  $s1, $zero
  andi  $v0, $s4, 1
  beqz  $v0, .L7F0C92AC
   addiu $t7, $sp, 0x2078
  lhu   $v0, 0x2078($sp)
  slti  $at, $v0, 0x270f
  beql  $at, $zero, .L7F0C9284
   slti  $at, $v0, 0x270f
  andi  $a2, $v0, 0xffff
  b     .L7F0C9294
   sw    $zero, 0x60($sp)
  slti  $at, $v0, 0x270f
.L7F0C9284:
  beql  $at, $zero, .L7F0C9298
   lw    $a3, 0x60($sp)
  lhu   $a2, 0x2078($sp)
  sw    $zero, 0x60($sp)
.L7F0C9294:
  lw    $a3, 0x60($sp)
.L7F0C9298:
  lw    $t1, 0x64($sp)
  li    $s1, 1
  sw    $a3, 0x60($sp)
  beq   $s1, $s4, .L7F0C936C
   sw    $t1, 0x64($sp)
.L7F0C92AC:
  sll   $t6, $s1, 1
  addu  $s0, $t6, $t7
  lw    $a3, 0x60($sp)
  lw    $t1, 0x64($sp)
.L7F0C92BC:
  lhu   $v1, ($s0)
  move  $a1, $t0
  move  $a0, $a2
  slt   $at, $v1, $t0
  beqz  $at, .L7F0C9300
   move  $v0, $v1
  slt   $at, $a0, $a1
  beql  $at, $zero, .L7F0C92F4
   andi  $a2, $v1, 0xffff
  andi  $t0, $v1, 0xffff
  move  $a1, $t0
  b     .L7F0C9318
   move  $t1, $s1
  andi  $a2, $v1, 0xffff
.L7F0C92F4:
  move  $a0, $a2
  b     .L7F0C9318
   move  $a3, $s1
.L7F0C9300:
  slt   $at, $v0, $a0
  beql  $at, $zero, .L7F0C931C
   lhu   $v1, 2($s0)
  andi  $a2, $v1, 0xffff
  move  $a0, $a2
  move  $a3, $s1
.L7F0C9318:
  lhu   $v1, 2($s0)
.L7F0C931C:
  slt   $at, $v1, $a1
  beqz  $at, .L7F0C934C
   move  $v0, $v1
  slt   $at, $a0, $a1
  beql  $at, $zero, .L7F0C9344
   andi  $a2, $v1, 0xffff
  andi  $t0, $v1, 0xffff
  b     .L7F0C9360
   addiu $t1, $s1, 1
  andi  $a2, $v1, 0xffff
.L7F0C9344:
  b     .L7F0C9360
   addiu $a3, $s1, 1
.L7F0C934C:
  slt   $at, $v0, $a0
  beql  $at, $zero, .L7F0C9364
   addiu $s1, $s1, 2
  andi  $a2, $v1, 0xffff
  addiu $a3, $s1, 1
.L7F0C9360:
  addiu $s1, $s1, 2
.L7F0C9364:
  bne   $s1, $s4, .L7F0C92BC
   addiu $s0, $s0, 4
.L7F0C936C:
  move  $s1, $zero
  sw    $a3, 0x60($sp)
  sw    $t1, 0x64($sp)
.L7F0C9378:
  lw    $a3, 0x60($sp)
  lw    $t1, 0x64($sp)
  addiu $s3, $sp, 0x78
  li    $t5, 9999
  li    $t4, 9999
  addiu $t3, $sp, 0x2078
  sll   $t8, $a3, 1
.L7F0C9394:
  sll   $t9, $t1, 1
  addu  $v0, $t3, $t9
  addu  $a1, $t3, $t8
  lhu   $t6, ($a1)
  lhu   $t7, ($v0)
  sll   $t8, $t1, 2
  sll   $t9, $a3, 2
  addu  $t2, $t6, $t7
  addu  $a0, $s3, $t9
  addu  $v1, $s3, $t8
  li    $t0, 9999
  bnez  $t2, .L7F0C93CC
   li    $a2, 9999
  li    $t2, 1
.L7F0C93CC:
  lh    $t6, ($v1)
  sh    $t4, ($v0)
  sh    $t4, ($a1)
  bgezl $t6, .L7F0C942C
   lh    $t8, ($a0)
  lh    $t7, 2($v1)
  addiu $t8, $t1, 0x2710
  bgezl $t7, .L7F0C942C
   lh    $t8, ($a0)
  sh    $t8, ($v1)
  lh    $t9, ($a0)
  move  $s2, $t1
  sh    $t2, ($v0)
  bgez  $t9, .L7F0C9420
   nop   
  lh    $t6, 2($a0)
  addiu $t7, $a3, 0x2710
  bgez  $t6, .L7F0C9420
   nop   
  b     .L7F0C94F8
   sh    $t7, 2($v1)
.L7F0C9420:
  b     .L7F0C94F8
   sh    $a3, 2($v1)
  lh    $t8, ($a0)
.L7F0C942C:
  lh    $t6, 0x78($sp)
  bgez  $t8, .L7F0C9480
   nop   
  lh    $t9, 2($a0)
  bgez  $t9, .L7F0C9480
   nop   
  addiu $t6, $a3, 0x2710
  sh    $t6, ($a0)
  lh    $t7, ($v1)
  move  $s2, $a3
  sh    $t2, ($a1)
  bgez  $t7, .L7F0C9478
   nop   
  lh    $t8, 2($v1)
  addiu $t9, $t1, 0x2710
  bgez  $t8, .L7F0C9478
   nop   
  b     .L7F0C94F8
   sh    $t9, 2($a0)
.L7F0C9478:
  b     .L7F0C94F8
   sh    $t1, 2($a0)
.L7F0C9480:
  bgez  $t6, .L7F0C94A8
   move  $s2, $zero
  sll   $t7, $zero, 2
  addu  $v0, $s3, $t7
  lh    $t8, 2($v0)
  lhu   $t9, 0x2078($sp)
  bgez  $t8, .L7F0C94A8
   slti  $at, $t9, 0x270f
  beql  $at, $zero, .L7F0C94E8
   sll   $t8, $s2, 1
.L7F0C94A8:
  addiu $s2, $s2, 1
.L7F0C94AC:
  sll   $t6, $s2, 2
  addu  $v0, $s3, $t6
  lh    $t7, ($v0)
  bgezl $t7, .L7F0C94AC
   addiu $s2, $s2, 1
  lh    $t8, 2($v0)
  bgezl $t8, .L7F0C94AC
   addiu $s2, $s2, 1
  sll   $t9, $s2, 1
  addu  $t6, $t3, $t9
  lhu   $t7, ($t6)
  slti  $at, $t7, 0x270f
  bnezl $at, .L7F0C94AC
   addiu $s2, $s2, 1
  sll   $t8, $s2, 1
.L7F0C94E8:
  addu  $t9, $t3, $t8
  sh    $t2, ($t9)
  sh    $t1, ($v0)
  sh    $a3, 2($v0)
.L7F0C94F8:
  blez  $s4, .L7F0C95FC
   andi  $v0, $s4, 1
  beql  $v0, $zero, .L7F0C9544
   sll   $t6, $s1, 1
  lhu   $v0, 0x2078($sp)
  li    $s1, 1
  slti  $at, $v0, 0x270f
  beql  $at, $zero, .L7F0C952C
   slti  $at, $v0, 0x270f
  andi  $a2, $v0, 0xffff
  b     .L7F0C953C
   move  $a3, $zero
  slti  $at, $v0, 0x270f
.L7F0C952C:
  beqz  $at, .L7F0C953C
   nop   
  lhu   $a2, 0x2078($sp)
  move  $a3, $zero
.L7F0C953C:
  beq   $s1, $s4, .L7F0C95F8
   sll   $t6, $s1, 1
.L7F0C9544:
  addu  $s0, $t3, $t6
.L7F0C9548:
  lhu   $v1, ($s0)
  move  $a1, $t0
  move  $a0, $a2
  slt   $at, $v1, $t0
  beqz  $at, .L7F0C958C
   move  $v0, $v1
  slt   $at, $a0, $a1
  beql  $at, $zero, .L7F0C9580
   andi  $a2, $v1, 0xffff
  andi  $t0, $v1, 0xffff
  move  $a1, $t0
  b     .L7F0C95A4
   move  $t1, $s1
  andi  $a2, $v1, 0xffff
.L7F0C9580:
  move  $a0, $a2
  b     .L7F0C95A4
   move  $a3, $s1
.L7F0C958C:
  slt   $at, $v0, $a0
  beql  $at, $zero, .L7F0C95A8
   lhu   $v1, 2($s0)
  andi  $a2, $v1, 0xffff
  move  $a0, $a2
  move  $a3, $s1
.L7F0C95A4:
  lhu   $v1, 2($s0)
.L7F0C95A8:
  slt   $at, $v1, $a1
  beqz  $at, .L7F0C95D8
   move  $v0, $v1
  slt   $at, $a0, $a1
  beql  $at, $zero, .L7F0C95D0
   andi  $a2, $v1, 0xffff
  andi  $t0, $v1, 0xffff
  b     .L7F0C95EC
   addiu $t1, $s1, 1
  andi  $a2, $v1, 0xffff
.L7F0C95D0:
  b     .L7F0C95EC
   addiu $a3, $s1, 1
.L7F0C95D8:
  slt   $at, $v0, $a0
  beql  $at, $zero, .L7F0C95F0
   addiu $s1, $s1, 2
  andi  $a2, $v1, 0xffff
  addiu $a3, $s1, 1
.L7F0C95EC:
  addiu $s1, $s1, 2
.L7F0C95F0:
  bne   $s1, $s4, .L7F0C9548
   addiu $s0, $s0, 4
.L7F0C95F8:
  move  $s1, $zero
.L7F0C95FC:
  beql  $t5, $t0, .L7F0C9610
   li    $ra, 1
  bne   $t5, $a2, .L7F0C9610
   nop   
  li    $ra, 1
.L7F0C9610:
  beql  $ra, $zero, .L7F0C9394
   sll   $t8, $a3, 1
  lw    $t7, 0x307c($sp)
  sw    $s2, 0x70($sp)
  addiu $s3, $sp, 0x78
  blez  $t7, .L7F0C969C
   lw    $v0, 0x3078($sp)
  slti  $at, $s2, 0x2710
.L7F0C9630:
  beqz  $at, .L7F0C9664
   move  $s0, $s2
.L7F0C9638:
  jal   sub_GAME_7F0CBF2C
   li    $a0, 1
  sll   $t8, $s0, 2
  addu  $t9, $s3, $t8
  sll   $t6, $v0, 1
  addu  $t7, $t9, $t6
  lh    $s0, ($t7)
  slti  $at, $s0, 0x2710
  bnez  $at, .L7F0C9638
   nop   
  lw    $v0, 0x3078($sp)
.L7F0C9664:
  slti  $at, $s4, 0x101
  beqz  $at, .L7F0C9680
   addiu $t6, $s0, -0x2710
  addiu $t8, $s0, -0x2710
  addu  $t9, $v0, $s1
  b     .L7F0C968C
   sb    $t8, ($t9)
.L7F0C9680:
  sll   $t7, $s1, 1
  addu  $t8, $v0, $t7
  sh    $t6, ($t8)
.L7F0C968C:
  lw    $t9, 0x307c($sp)
  addiu $s1, $s1, 1
  bnel  $s1, $t9, .L7F0C9630
   slti  $at, $s2, 0x2710
.L7F0C969C:
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  lw    $s3, 0x24($sp)
  lw    $s4, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x3078
");

asm(R"
glabel type4_7_9_getsamples
  addiu $sp, $sp, -0x38
  sw    $s2, 0x1c($sp)
  move  $s2, $a0
  sw    $ra, 0x2c($sp)
  sw    $s5, 0x28($sp)
  sw    $s4, 0x24($sp)
  sw    $s3, 0x20($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  sw    $a1, 0x3c($sp)
  jal   sub_GAME_7F0CBF2C
   li    $a0, 3
  sw    $v0, 0x34($sp)
  jal   sub_GAME_7F0CBF2C
   li    $a0, 3
  sw    $v0, 0x30($sp)
  jal   sub_GAME_7F0CBF2C
   li    $a0, 4
  lw    $t6, 0x34($sp)
  lw    $t7, 0x30($sp)
  move  $s4, $v0
  move  $s5, $zero
  addu  $t8, $t6, $t7
  addu  $a0, $t8, $v0
  addiu $v1, $a0, 1
  blez  $v1, .L7F0C9738
   lw    $t9, 0x3c($sp)
.L7F0C9728:
  subu  $v1, $v1, $v0
  addiu $v1, $v1, -1
  bgtz  $v1, .L7F0C9728
   addiu $s5, $s5, 1
.L7F0C9738:
  blez  $t9, .L7F0C98FC
   move  $s1, $zero
.L7F0C9740:
  jal   sub_GAME_7F0CBF2C
   li    $a0, 1
  bnez  $v0, .L7F0C9788
   slti  $at, $s4, 9
  beqz  $at, .L7F0C9770
   move  $a0, $s4
  move  $a0, $s4
  jal   sub_GAME_7F0CBF2C
   addu  $s0, $s2, $s1
  sb    $v0, ($s0)
  b     .L7F0C98EC
   addiu $s1, $s1, 1
.L7F0C9770:
  sll   $t0, $s1, 1
  jal   sub_GAME_7F0CBF2C
   addu  $s0, $s2, $t0
  sh    $v0, ($s0)
  b     .L7F0C98EC
   addiu $s1, $s1, 1
.L7F0C9788:
  jal   sub_GAME_7F0CBF2C
   lw    $a0, 0x34($sp)
  subu  $s3, $s1, $v0
  addiu $s3, $s3, -1
  jal   sub_GAME_7F0CBF2C
   lw    $a0, 0x30($sp)
  addu  $a0, $v0, $s5
  slti  $at, $s4, 9
  beqz  $at, .L7F0C9848
   move  $a3, $a0
  addu  $a2, $s3, $a0
  slt   $at, $s3, $a2
  move  $v1, $s3
  beqz  $at, .L7F0C9834
   addu  $s0, $s2, $s1
  subu  $a1, $a2, $s3
  andi  $t1, $a1, 3
  beqz  $t1, .L7F0C97F8
   addu  $a0, $t1, $s3
  addu  $v0, $s2, $v1
.L7F0C97D8:
  lbu   $t2, ($v0)
  addiu $v1, $v1, 1
  addiu $s1, $s1, 1
  addiu $s0, $s0, 1
  addiu $v0, $v0, 1
  bne   $a0, $v1, .L7F0C97D8
   sb    $t2, -1($s0)
  beq   $v1, $a2, .L7F0C9834
.L7F0C97F8:
   addu  $a0, $s3, $a3
  addu  $v0, $s2, $v1
.L7F0C9800:
  lbu   $t3, ($v0)
  addiu $v1, $v1, 4
  addiu $s1, $s1, 4
  sb    $t3, ($s0)
  lbu   $t4, 1($v0)
  addiu $s0, $s0, 4
  addiu $v0, $v0, 4
  sb    $t4, -3($s0)
  lbu   $t5, -2($v0)
  sb    $t5, -2($s0)
  lbu   $t6, -1($v0)
  bne   $v1, $a0, .L7F0C9800
   sb    $t6, -1($s0)
.L7F0C9834:
  jal   sub_GAME_7F0CBF2C
   move  $a0, $s4
  sb    $v0, ($s0)
  b     .L7F0C98EC
   addiu $s1, $s1, 1
.L7F0C9848:
  addu  $a2, $s3, $a0
  slt   $at, $s3, $a2
  sll   $t7, $s1, 1
  addu  $s0, $s2, $t7
  beqz  $at, .L7F0C98DC
   move  $v1, $s3
  subu  $a1, $a2, $s3
  andi  $t8, $a1, 3
  beqz  $t8, .L7F0C9898
   addu  $a0, $t8, $s3
  sll   $t9, $v1, 1
  addu  $v0, $s2, $t9
.L7F0C9878:
  lhu   $t0, ($v0)
  addiu $v1, $v1, 1
  addiu $s1, $s1, 1
  addiu $s0, $s0, 2
  addiu $v0, $v0, 2
  bne   $a0, $v1, .L7F0C9878
   sh    $t0, -2($s0)
  beq   $v1, $a2, .L7F0C98DC
.L7F0C9898:
   addu  $a0, $s3, $a3
  sll   $t1, $a0, 1
  sll   $t2, $v1, 1
  addu  $v0, $s2, $t2
  addu  $a1, $t1, $s2
.L7F0C98AC:
  lhu   $t3, ($v0)
  addiu $v0, $v0, 8
  addiu $s1, $s1, 4
  sh    $t3, ($s0)
  lhu   $t4, -6($v0)
  addiu $s0, $s0, 8
  sh    $t4, -6($s0)
  lhu   $t5, -4($v0)
  sh    $t5, -4($s0)
  lhu   $t6, -2($v0)
  bne   $v0, $a1, .L7F0C98AC
   sh    $t6, -2($s0)
.L7F0C98DC:
  jal   sub_GAME_7F0CBF2C
   move  $a0, $s4
  sh    $v0, ($s0)
  addiu $s1, $s1, 1
.L7F0C98EC:
  lw    $t7, 0x3c($sp)
  slt   $at, $s1, $t7
  bnez  $at, .L7F0C9740
   nop   
.L7F0C98FC:
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  lw    $s4, 0x24($sp)
  lw    $s5, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x38
");

asm(R"
glabel type5_6_7_getsamples
  addiu $sp, $sp, -0x30
  sw    $s3, 0x20($sp)
  move  $s3, $a0
  sw    $ra, 0x2c($sp)
  sw    $s2, 0x1c($sp)
  move  $s2, $a1
  sw    $s5, 0x28($sp)
  sw    $s4, 0x24($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  jal   sub_GAME_7F0CBF2C
   li    $a0, 11
  slti  $at, $s2, 0x11
  beqz  $at, .L7F0C9988
   move  $s5, $v0
  blez  $v0, .L7F0C99FC
   move  $s0, $zero
  move  $s1, $s3
.L7F0C9968:
  jal   sub_GAME_7F0CBF2C
   move  $a0, $s2
  addiu $s0, $s0, 1
  addiu $s1, $s1, 2
  bne   $s0, $s5, .L7F0C9968
   sh    $v0, -2($s1)
  b     .L7F0C9A00
   lw    $ra, 0x2c($sp)
.L7F0C9988:
  slti  $at, $s2, 0x19
  beqz  $at, .L7F0C99C0
   nop   
  blez  $v0, .L7F0C99FC
   move  $s0, $zero
  move  $s1, $s3
.L7F0C99A0:
  jal   sub_GAME_7F0CBF2C
   move  $a0, $s2
  addiu $s0, $s0, 1
  addiu $s1, $s1, 4
  bne   $s0, $s5, .L7F0C99A0
   sw    $v0, -4($s1)
  b     .L7F0C9A00
   lw    $ra, 0x2c($sp)
.L7F0C99C0:
  blez  $v0, .L7F0C99FC
   move  $s0, $zero
  addiu $s4, $s2, -0x18
  move  $s1, $s3
.L7F0C99D0:
  jal   sub_GAME_7F0CBF2C
   li    $a0, 24
  move  $s2, $v0
  jal   sub_GAME_7F0CBF2C
   move  $a0, $s4
  sll   $t6, $s2, 8
  addiu $s0, $s0, 1
  or    $t7, $v0, $t6
  addiu $s1, $s1, 4
  bne   $s0, $s5, .L7F0C99D0
   sw    $t7, -4($s1)
.L7F0C99FC:
  lw    $ra, 0x2c($sp)
.L7F0C9A00:
  move  $v0, $s5
  lw    $s5, 0x28($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  lw    $s4, 0x24($sp)
  jr    $ra
   addiu $sp, $sp, 0x30
");

asm(R"
glabel sub_GAME_7F0C9A24
  addiu $a0, $a0, -1
  blez  $a0, .L7F0C9A40
   move  $v1, $zero
.L7F0C9A30:
  sra   $t6, $a0, 1
  move  $a0, $t6
  bgtz  $t6, .L7F0C9A30
   addiu $v1, $v1, 1
.L7F0C9A40:
  jr    $ra
   move  $v0, $v1
");

asm(R"
glabel image_get_alpha_values
  addiu $sp, $sp, -0x28
  sw    $s2, 0x20($sp)
  sw    $s0, 0x18($sp)
  move  $s2, $a1
  sw    $ra, 0x24($sp)
  sw    $s1, 0x1c($sp)
  blez  $a1, .L7F0C9A84
   move  $s0, $zero
  move  $s1, $a0
.L7F0C9A6C:
  jal   sub_GAME_7F0CBF2C
   li    $a0, 1
  addiu $s0, $s0, 1
  addiu $s1, $s1, 1
  bne   $s0, $s2, .L7F0C9A6C
   sb    $v0, -1($s1)
.L7F0C9A84:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
.late_rodata
/*D:8005BDA0*/
glabel jpt_8005BDA0
.word .L7F0C9B0C
.word .L7F0C9BEC
.word .L7F0C9B84
.word .L7F0C9C4C
.word .L7F0C9BEC
.word .L7F0C9CB4
.word .L7F0C9D10
.word .L7F0C9CB4
.word .L7F0C9D10
.text
glabel image_compression0_expand
  addiu $sp, $sp, -0x38
  sw    $s5, 0x28($sp)
  addiu $s5, $a0, 0xf
  li    $at, -16
  and   $t6, $s5, $at
  sw    $s3, 0x20($sp)
  li    $at, -8
  addiu $v0, $a0, 7
  and   $s3, $v0, $at
  sw    $s7, 0x30($sp)
  sw    $s6, 0x2c($sp)
  sw    $s2, 0x1c($sp)
  sltiu $at, $a3, 9
  move  $s2, $a1
  move  $s7, $a2
  sw    $ra, 0x34($sp)
  sw    $s4, 0x24($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  move  $s5, $t6
  beqz  $at, .L7F0C9D74
   move  $s6, $s3
  sll   $t8, $a3, 2
  lui   $at, %hi(jpt_8005BDA0)
  addu  $at, $at, $t8
  lw    $t8, %lo(jpt_8005BDA0)($at)
  jr    $t8
   nop   
.L7F0C9B0C:
  blez  $s7, .L7F0C9B68
   move  $s4, $zero
  addiu $s3, $s2, 3
  andi  $t9, $s3, 0xffc
  sll   $s3, $t9, 2
.L7F0C9B20:
  blez  $s2, .L7F0C9B5C
   move  $s0, $zero
  move  $s1, $s5
.L7F0C9B2C:
  jal   sub_GAME_7F0CBF2C
   li    $a0, 16
  sll   $t1, $v0, 0x10
  sw    $t1, ($s1)
  jal   sub_GAME_7F0CBF2C
   li    $a0, 16
  lw    $t2, ($s1)
  addiu $s0, $s0, 1
  addiu $s1, $s1, 4
  or    $t3, $t2, $v0
  bne   $s0, $s2, .L7F0C9B2C
   sw    $t3, -4($s1)
.L7F0C9B5C:
  addiu $s4, $s4, 1
  bne   $s4, $s7, .L7F0C9B20
   addu  $s5, $s5, $s3
.L7F0C9B68:
  addiu $t4, $s2, 3
  andi  $t5, $t4, 0xffc
  multu $t5, $s7
  mflo  $v0
  sll   $t6, $v0, 2
  b     .L7F0C9D78
   move  $v0, $t6
.L7F0C9B84:
  blez  $s7, .L7F0C9BD0
   move  $s4, $zero
  addiu $s3, $s2, 3
  andi  $t7, $s3, 0xffc
  sll   $s3, $t7, 2
.L7F0C9B98:
  blez  $s2, .L7F0C9BC4
   move  $s0, $zero
  move  $s1, $s5
.L7F0C9BA4:
  jal   sub_GAME_7F0CBF2C
   li    $a0, 24
  sll   $t9, $v0, 8
  addiu $s0, $s0, 1
  ori   $t0, $t9, 0xff
  addiu $s1, $s1, 4
  bne   $s0, $s2, .L7F0C9BA4
   sw    $t0, -4($s1)
.L7F0C9BC4:
  addiu $s4, $s4, 1
  bne   $s4, $s7, .L7F0C9B98
   addu  $s5, $s5, $s3
.L7F0C9BD0:
  addiu $t1, $s2, 3
  andi  $t2, $t1, 0xffc
  multu $t2, $s7
  mflo  $v0
  sll   $t3, $v0, 2
  b     .L7F0C9D78
   move  $v0, $t3
.L7F0C9BEC:
  blez  $s7, .L7F0C9C30
   move  $s4, $zero
  addiu $s3, $s2, 3
  andi  $t4, $s3, 0xffc
  sll   $s3, $t4, 1
.L7F0C9C00:
  blez  $s2, .L7F0C9C24
   move  $s0, $zero
  move  $s1, $s6
.L7F0C9C0C:
  jal   sub_GAME_7F0CBF2C
   li    $a0, 16
  addiu $s0, $s0, 1
  addiu $s1, $s1, 2
  bne   $s0, $s2, .L7F0C9C0C
   sh    $v0, -2($s1)
.L7F0C9C24:
  addiu $s4, $s4, 1
  bne   $s4, $s7, .L7F0C9C00
   addu  $s6, $s6, $s3
.L7F0C9C30:
  addiu $t6, $s2, 3
  andi  $t7, $t6, 0xffc
  multu $t7, $s7
  mflo  $v0
  sll   $t8, $v0, 1
  b     .L7F0C9D78
   move  $v0, $t8
.L7F0C9C4C:
  blez  $s7, .L7F0C9C98
   move  $s4, $zero
  addiu $s3, $s2, 3
  andi  $t9, $s3, 0xffc
  sll   $s3, $t9, 1
.L7F0C9C60:
  blez  $s2, .L7F0C9C8C
   move  $s0, $zero
  move  $s1, $s6
.L7F0C9C6C:
  jal   sub_GAME_7F0CBF2C
   li    $a0, 15
  sll   $t1, $v0, 1
  addiu $s0, $s0, 1
  ori   $t2, $t1, 1
  addiu $s1, $s1, 2
  bne   $s0, $s2, .L7F0C9C6C
   sh    $t2, -2($s1)
.L7F0C9C8C:
  addiu $s4, $s4, 1
  bne   $s4, $s7, .L7F0C9C60
   addu  $s6, $s6, $s3
.L7F0C9C98:
  addiu $t3, $s2, 3
  andi  $t4, $t3, 0xffc
  multu $t4, $s7
  mflo  $v0
  sll   $t5, $v0, 1
  b     .L7F0C9D78
   move  $v0, $t5
.L7F0C9CB4:
  blez  $s7, .L7F0C9CF8
   move  $s4, $zero
  addiu $s5, $s2, 7
  andi  $t6, $s5, 0xff8
  move  $s5, $t6
.L7F0C9CC8:
  blez  $s2, .L7F0C9CEC
   move  $s0, $zero
  move  $s1, $s3
.L7F0C9CD4:
  jal   sub_GAME_7F0CBF2C
   li    $a0, 8
  addiu $s0, $s0, 1
  addiu $s1, $s1, 1
  bne   $s0, $s2, .L7F0C9CD4
   sb    $v0, -1($s1)
.L7F0C9CEC:
  addiu $s4, $s4, 1
  bne   $s4, $s7, .L7F0C9CC8
   addu  $s3, $s3, $s5
.L7F0C9CF8:
  addiu $t7, $s2, 7
  andi  $t8, $t7, 0xff8
  multu $t8, $s7
  mflo  $v0
  b     .L7F0C9D7C
   lw    $ra, 0x34($sp)
.L7F0C9D10:
  blez  $s7, .L7F0C9D58
   move  $s4, $zero
  addiu $s1, $s2, 0xf
  andi  $t9, $s1, 0xff0
  sra   $s1, $t9, 1
.L7F0C9D24:
  blez  $s2, .L7F0C9D4C
   move  $s0, $zero
.L7F0C9D2C:
  jal   sub_GAME_7F0CBF2C
   li    $a0, 8
  sra   $t1, $s0, 1
  addiu $s0, $s0, 2
  slt   $at, $s0, $s2
  addu  $t2, $s3, $t1
  bnez  $at, .L7F0C9D2C
   sb    $v0, ($t2)
.L7F0C9D4C:
  addiu $s4, $s4, 1
  bne   $s4, $s7, .L7F0C9D24
   addu  $s3, $s3, $s1
.L7F0C9D58:
  addiu $t3, $s2, 0xf
  andi  $t4, $t3, 0xff0
  sra   $t5, $t4, 1
  multu $t5, $s7
  mflo  $v0
  b     .L7F0C9D7C
   lw    $ra, 0x34($sp)
def_7F0C9B04:
.L7F0C9D74:
  move  $v0, $zero
.L7F0C9D78:
  lw    $ra, 0x34($sp)
.L7F0C9D7C:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  lw    $s4, 0x24($sp)
  lw    $s5, 0x28($sp)
  lw    $s6, 0x2c($sp)
  lw    $s7, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x38
");

asm(R"
.late_rodata
/*D:8005BDC4*/
glabel jpt_8005BDC4
.word .L7F0C9DF8
.word .L7F0CA138
.word .L7F0C9FAC
.word .L7F0CA400
.word .L7F0CA2EC
.word .L7F0CA58C
.word .L7F0CA738
.word .L7F0CA68C
.word .L7F0CA7F0
.text
glabel generate_link_final_image
  addiu $sp, $sp, -0x68
  lw    $t6, 0x78($sp)
  sw    $s2, 0x10($sp)
  sw    $s1, 0xc($sp)
  sw    $s0, 8($sp)
  sltiu $at, $t6, 9
  move  $s0, $a1
  move  $s1, $a0
  move  $s2, $a2
  sw    $s3, 0x14($sp)
  move  $t2, $a3
  move  $t1, $a3
  move  $v1, $a3
  beqz  $at, .L7F0CA874
   move  $t0, $zero
  sll   $t6, $t6, 2
  lui   $at, %hi(jpt_8005BDC4)
  addu  $at, $at, $t6
  lw    $t6, %lo(jpt_8005BDC4)($at)
  jr    $t6
   nop   
.L7F0C9DF8:
  blez  $s2, .L7F0C9F90
   move  $a3, $zero
  addiu $t7, $s0, 3
  andi  $t8, $t7, 0xffc
  sll   $t9, $t8, 2
  sw    $t9, 0x1c($sp)
.L7F0C9E10:
  blez  $s0, .L7F0C9F80
   move  $a1, $zero
  multu $s0, $s2
  addu  $t4, $s1, $t0
  andi  $a2, $s0, 3
  sll   $t9, $zero, 2
  addu  $t1, $t2, $t9
  move  $t5, $a2
  addu  $v0, $s1, $t0
  mflo  $t3
  sll   $t6, $t3, 2
  subu  $t6, $t6, $t3
  addu  $t7, $t6, $t0
  sll   $t8, $t3, 1
  addu  $s3, $t4, $t8
  addu  $a0, $t7, $s1
  beqz  $a2, .L7F0C9EA8
   addu  $v1, $t4, $t3
.L7F0C9E58:
  lbu   $t7, ($v0)
  lbu   $t6, ($a0)
  addiu $a1, $a1, 1
  sll   $t8, $t7, 0x18
  lbu   $t7, ($v1)
  or    $t9, $t6, $t8
  addiu $t0, $t0, 1
  sll   $t6, $t7, 0x10
  lbu   $t7, ($s3)
  or    $t8, $t9, $t6
  addiu $v0, $v0, 1
  sll   $t9, $t7, 8
  or    $t6, $t8, $t9
  sw    $t6, ($t1)
  addiu $a0, $a0, 1
  addiu $v1, $v1, 1
  addiu $s3, $s3, 1
  bne   $t5, $a1, .L7F0C9E58
   addiu $t1, $t1, 4
  beq   $a1, $s0, .L7F0C9F80
.L7F0C9EA8:
   sll   $t7, $a1, 2
  addu  $t1, $t2, $t7
.L7F0C9EB0:
  lbu   $t9, ($v0)
  lbu   $t8, ($a0)
  addiu $a1, $a1, 4
  sll   $t6, $t9, 0x18
  lbu   $t9, ($v1)
  or    $t7, $t8, $t6
  addiu $t0, $t0, 4
  sll   $t8, $t9, 0x10
  lbu   $t9, ($s3)
  or    $t6, $t7, $t8
  addiu $v0, $v0, 4
  sll   $t7, $t9, 8
  or    $t8, $t6, $t7
  sw    $t8, ($t1)
  lbu   $t6, -3($v0)
  lbu   $t9, 1($a0)
  addiu $a0, $a0, 4
  sll   $t7, $t6, 0x18
  lbu   $t6, 1($v1)
  or    $t8, $t9, $t7
  addiu $v1, $v1, 4
  sll   $t9, $t6, 0x10
  lbu   $t6, 1($s3)
  or    $t7, $t8, $t9
  addiu $s3, $s3, 4
  sll   $t8, $t6, 8
  or    $t9, $t7, $t8
  sw    $t9, 4($t1)
  lbu   $t7, -2($v0)
  lbu   $t6, -2($a0)
  addiu $t1, $t1, 0x10
  sll   $t8, $t7, 0x18
  lbu   $t7, -2($v1)
  or    $t9, $t6, $t8
  sll   $t6, $t7, 0x10
  lbu   $t7, -2($s3)
  or    $t8, $t9, $t6
  sll   $t9, $t7, 8
  or    $t6, $t8, $t9
  sw    $t6, -8($t1)
  lbu   $t8, -1($v0)
  lbu   $t7, -1($a0)
  sll   $t9, $t8, 0x18
  lbu   $t8, -1($v1)
  or    $t6, $t7, $t9
  sll   $t7, $t8, 0x10
  lbu   $t8, -1($s3)
  or    $t9, $t6, $t7
  sll   $t6, $t8, 8
  or    $t7, $t9, $t6
  bne   $a1, $s0, .L7F0C9EB0
   sw    $t7, -4($t1)
.L7F0C9F80:
  lw    $t8, 0x1c($sp)
  addiu $a3, $a3, 1
  bne   $a3, $s2, .L7F0C9E10
   addu  $t2, $t2, $t8
.L7F0C9F90:
  addiu $t9, $s0, 3
  andi  $t6, $t9, 0xffc
  multu $t6, $s2
  mflo  $v0
  sll   $t7, $v0, 2
  b     .L7F0CA878
   move  $v0, $t7
.L7F0C9FAC:
  blez  $s2, .L7F0CA11C
   move  $a3, $zero
  addiu $t8, $s0, 3
  andi  $t9, $t8, 0xffc
  sll   $t6, $t9, 2
  sw    $t6, 0x1c($sp)
.L7F0C9FC4:
  blez  $s0, .L7F0CA10C
   move  $a1, $zero
  multu $s0, $s2
  addu  $t7, $s1, $t0
  andi  $a2, $s0, 3
  sll   $t6, $zero, 2
  addu  $t1, $t2, $t6
  move  $a0, $a2
  addu  $v0, $s1, $t0
  mflo  $t3
  sll   $t8, $t3, 1
  addu  $t9, $t8, $t0
  addu  $t4, $t9, $s1
  beqz  $a2, .L7F0CA048
   addu  $v1, $t7, $t3
.L7F0CA000:
  lbu   $t9, ($v0)
  lbu   $t7, ($t4)
  addiu $a1, $a1, 1
  sll   $t6, $t9, 0x18
  lbu   $t9, ($v1)
  sll   $t8, $t7, 8
  or    $t7, $t8, $t6
  sll   $t8, $t9, 0x10
  or    $t6, $t7, $t8
  ori   $t9, $t6, 0xff
  sw    $t9, ($t1)
  addiu $t0, $t0, 1
  addiu $v0, $v0, 1
  addiu $v1, $v1, 1
  addiu $t4, $t4, 1
  bne   $a0, $a1, .L7F0CA000
   addiu $t1, $t1, 4
  beq   $a1, $s0, .L7F0CA10C
.L7F0CA048:
   sll   $t7, $a1, 2
  addu  $t1, $t2, $t7
.L7F0CA050:
  lbu   $t9, ($v0)
  lbu   $t8, ($t4)
  addiu $a1, $a1, 4
  sll   $t7, $t9, 0x18
  lbu   $t9, ($v1)
  sll   $t6, $t8, 8
  or    $t8, $t6, $t7
  sll   $t6, $t9, 0x10
  or    $t7, $t8, $t6
  ori   $t9, $t7, 0xff
  sw    $t9, ($t1)
  lbu   $t7, 1($v0)
  lbu   $t8, 1($t4)
  addiu $t0, $t0, 4
  sll   $t9, $t7, 0x18
  lbu   $t7, 1($v1)
  sll   $t6, $t8, 8
  or    $t8, $t6, $t9
  sll   $t6, $t7, 0x10
  or    $t9, $t8, $t6
  ori   $t7, $t9, 0xff
  sw    $t7, 4($t1)
  lbu   $t9, 2($v0)
  lbu   $t8, 2($t4)
  addiu $v0, $v0, 4
  sll   $t7, $t9, 0x18
  lbu   $t9, 2($v1)
  sll   $t6, $t8, 8
  or    $t8, $t6, $t7
  sll   $t6, $t9, 0x10
  or    $t7, $t8, $t6
  ori   $t9, $t7, 0xff
  sw    $t9, 8($t1)
  lbu   $t7, -1($v0)
  lbu   $t8, 3($t4)
  addiu $v1, $v1, 4
  sll   $t9, $t7, 0x18
  lbu   $t7, -1($v1)
  sll   $t6, $t8, 8
  or    $t8, $t6, $t9
  sll   $t6, $t7, 0x10
  or    $t9, $t8, $t6
  ori   $t7, $t9, 0xff
  sw    $t7, 0xc($t1)
  addiu $t4, $t4, 4
  bne   $a1, $s0, .L7F0CA050
   addiu $t1, $t1, 0x10
.L7F0CA10C:
  lw    $t8, 0x1c($sp)
  addiu $a3, $a3, 1
  bne   $a3, $s2, .L7F0C9FC4
   addu  $t2, $t2, $t8
.L7F0CA11C:
  addiu $t6, $s0, 3
  andi  $t9, $t6, 0xffc
  multu $t9, $s2
  mflo  $v0
  sll   $t7, $v0, 2
  b     .L7F0CA878
   move  $v0, $t7
.L7F0CA138:
  blez  $s2, .L7F0CA2D0
   move  $a3, $zero
  addiu $t8, $s0, 3
  andi  $t6, $t8, 0xffc
  sll   $t9, $t6, 1
  sw    $t9, 0x1c($sp)
.L7F0CA150:
  blez  $s0, .L7F0CA2C0
   move  $a1, $zero
  multu $s0, $s2
  addu  $t4, $s1, $t0
  andi  $a2, $s0, 3
  sll   $t9, $zero, 1
  addu  $t2, $t1, $t9
  move  $t5, $a2
  addu  $v0, $s1, $t0
  mflo  $t3
  sll   $t7, $t3, 2
  subu  $t7, $t7, $t3
  addu  $t8, $t7, $t0
  sll   $t6, $t3, 1
  addu  $s3, $t4, $t6
  addu  $a0, $t8, $s1
  beqz  $a2, .L7F0CA1E8
   addu  $v1, $t4, $t3
.L7F0CA198:
  lbu   $t8, ($v0)
  lbu   $t7, ($a0)
  addiu $a1, $a1, 1
  sll   $t6, $t8, 0xb
  lbu   $t8, ($v1)
  or    $t9, $t7, $t6
  addiu $t0, $t0, 1
  sll   $t7, $t8, 6
  lbu   $t8, ($s3)
  or    $t6, $t9, $t7
  addiu $v0, $v0, 1
  sll   $t9, $t8, 1
  or    $t7, $t6, $t9
  sh    $t7, ($t2)
  addiu $a0, $a0, 1
  addiu $v1, $v1, 1
  addiu $s3, $s3, 1
  bne   $t5, $a1, .L7F0CA198
   addiu $t2, $t2, 2
  beq   $a1, $s0, .L7F0CA2C0
.L7F0CA1E8:
   sll   $t8, $a1, 1
  addu  $t2, $t1, $t8
.L7F0CA1F0:
  lbu   $t9, ($v0)
  lbu   $t6, ($a0)
  addiu $a1, $a1, 4
  sll   $t7, $t9, 0xb
  lbu   $t9, ($v1)
  or    $t8, $t6, $t7
  addiu $t0, $t0, 4
  sll   $t6, $t9, 6
  lbu   $t9, ($s3)
  or    $t7, $t8, $t6
  addiu $v0, $v0, 4
  sll   $t8, $t9, 1
  or    $t6, $t7, $t8
  sh    $t6, ($t2)
  lbu   $t7, -3($v0)
  lbu   $t9, 1($a0)
  addiu $a0, $a0, 4
  sll   $t8, $t7, 0xb
  lbu   $t7, 1($v1)
  or    $t6, $t9, $t8
  addiu $v1, $v1, 4
  sll   $t9, $t7, 6
  lbu   $t7, 1($s3)
  or    $t8, $t6, $t9
  addiu $s3, $s3, 4
  sll   $t6, $t7, 1
  or    $t9, $t8, $t6
  sh    $t9, 2($t2)
  lbu   $t8, -2($v0)
  lbu   $t7, -2($a0)
  addiu $t2, $t2, 8
  sll   $t6, $t8, 0xb
  lbu   $t8, -2($v1)
  or    $t9, $t7, $t6
  sll   $t7, $t8, 6
  lbu   $t8, -2($s3)
  or    $t6, $t9, $t7
  sll   $t9, $t8, 1
  or    $t7, $t6, $t9
  sh    $t7, -4($t2)
  lbu   $t6, -1($v0)
  lbu   $t8, -1($a0)
  sll   $t9, $t6, 0xb
  lbu   $t6, -1($v1)
  or    $t7, $t8, $t9
  sll   $t8, $t6, 6
  lbu   $t6, -1($s3)
  or    $t9, $t7, $t8
  sll   $t7, $t6, 1
  or    $t8, $t9, $t7
  bne   $a1, $s0, .L7F0CA1F0
   sh    $t8, -2($t2)
.L7F0CA2C0:
  lw    $t6, 0x1c($sp)
  addiu $a3, $a3, 1
  bne   $a3, $s2, .L7F0CA150
   addu  $t1, $t1, $t6
.L7F0CA2D0:
  addiu $t9, $s0, 3
  andi  $t7, $t9, 0xffc
  multu $t7, $s2
  mflo  $v0
  sll   $t8, $v0, 1
  b     .L7F0CA878
   move  $v0, $t8
.L7F0CA2EC:
  blez  $s2, .L7F0CA3E4
   move  $a3, $zero
  addiu $t6, $s0, 3
  andi  $t9, $t6, 0xffc
  sll   $t7, $t9, 1
  sw    $t7, 0x1c($sp)
.L7F0CA304:
  blez  $s0, .L7F0CA3D4
   move  $a1, $zero
  multu $s0, $s2
  andi  $a2, $s0, 3
  sll   $t9, $zero, 1
  addu  $t2, $t1, $t9
  move  $v1, $a2
  addu  $v0, $s1, $t0
  mflo  $t8
  addu  $t6, $t0, $t8
  beqz  $a2, .L7F0CA364
   addu  $t3, $t6, $s1
.L7F0CA334:
  lbu   $t8, ($v0)
  lbu   $t7, ($t3)
  addiu $a1, $a1, 1
  sll   $t6, $t8, 8
  or    $t9, $t7, $t6
  sh    $t9, ($t2)
  addiu $t0, $t0, 1
  addiu $v0, $v0, 1
  addiu $t3, $t3, 1
  bne   $v1, $a1, .L7F0CA334
   addiu $t2, $t2, 2
  beq   $a1, $s0, .L7F0CA3D4
.L7F0CA364:
   sll   $t8, $a1, 1
  addu  $t2, $t1, $t8
.L7F0CA36C:
  lbu   $t6, ($v0)
  lbu   $t7, ($t3)
  addiu $a1, $a1, 4
  sll   $t9, $t6, 8
  or    $t8, $t7, $t9
  sh    $t8, ($t2)
  lbu   $t7, 1($v0)
  lbu   $t6, 1($t3)
  addiu $t0, $t0, 4
  sll   $t9, $t7, 8
  or    $t8, $t6, $t9
  sh    $t8, 2($t2)
  lbu   $t6, 2($v0)
  lbu   $t7, 2($t3)
  addiu $v0, $v0, 4
  sll   $t9, $t6, 8
  or    $t8, $t7, $t9
  sh    $t8, 4($t2)
  lbu   $t7, -1($v0)
  lbu   $t6, 3($t3)
  addiu $t3, $t3, 4
  sll   $t9, $t7, 8
  or    $t8, $t6, $t9
  sh    $t8, 6($t2)
  bne   $a1, $s0, .L7F0CA36C
   addiu $t2, $t2, 8
.L7F0CA3D4:
  lw    $t7, 0x1c($sp)
  addiu $a3, $a3, 1
  bne   $a3, $s2, .L7F0CA304
   addu  $t1, $t1, $t7
.L7F0CA3E4:
  addiu $t6, $s0, 3
  andi  $t9, $t6, 0xffc
  multu $t9, $s2
  mflo  $v0
  sll   $t8, $v0, 1
  b     .L7F0CA878
   move  $v0, $t8
.L7F0CA400:
  blez  $s2, .L7F0CA570
   move  $a3, $zero
  addiu $t7, $s0, 3
  andi  $t6, $t7, 0xffc
  sll   $t9, $t6, 1
  sw    $t9, 0x1c($sp)
.L7F0CA418:
  blez  $s0, .L7F0CA560
   move  $a1, $zero
  multu $s0, $s2
  addu  $t8, $s1, $t0
  andi  $a2, $s0, 3
  sll   $t9, $zero, 1
  addu  $t2, $t1, $t9
  move  $a0, $a2
  addu  $v0, $s1, $t0
  mflo  $t3
  sll   $t7, $t3, 1
  addu  $t6, $t7, $t0
  addu  $t4, $t6, $s1
  beqz  $a2, .L7F0CA49C
   addu  $v1, $t8, $t3
.L7F0CA454:
  lbu   $t6, ($v0)
  lbu   $t8, ($t4)
  addiu $a1, $a1, 1
  sll   $t9, $t6, 0xb
  lbu   $t6, ($v1)
  sll   $t7, $t8, 1
  or    $t8, $t7, $t9
  sll   $t7, $t6, 6
  or    $t9, $t8, $t7
  ori   $t6, $t9, 1
  sh    $t6, ($t2)
  addiu $t0, $t0, 1
  addiu $v0, $v0, 1
  addiu $v1, $v1, 1
  addiu $t4, $t4, 1
  bne   $a0, $a1, .L7F0CA454
   addiu $t2, $t2, 2
  beq   $a1, $s0, .L7F0CA560
.L7F0CA49C:
   sll   $t8, $a1, 1
  addu  $t2, $t1, $t8
.L7F0CA4A4:
  lbu   $t6, ($v0)
  lbu   $t7, ($t4)
  addiu $a1, $a1, 4
  sll   $t8, $t6, 0xb
  lbu   $t6, ($v1)
  sll   $t9, $t7, 1
  or    $t7, $t9, $t8
  sll   $t9, $t6, 6
  or    $t8, $t7, $t9
  ori   $t6, $t8, 1
  sh    $t6, ($t2)
  lbu   $t8, 1($v0)
  lbu   $t7, 1($t4)
  addiu $t0, $t0, 4
  sll   $t6, $t8, 0xb
  lbu   $t8, 1($v1)
  sll   $t9, $t7, 1
  or    $t7, $t9, $t6
  sll   $t9, $t8, 6
  or    $t6, $t7, $t9
  ori   $t8, $t6, 1
  sh    $t8, 2($t2)
  lbu   $t6, 2($v0)
  lbu   $t7, 2($t4)
  addiu $v0, $v0, 4
  sll   $t8, $t6, 0xb
  lbu   $t6, 2($v1)
  sll   $t9, $t7, 1
  or    $t7, $t9, $t8
  sll   $t9, $t6, 6
  or    $t8, $t7, $t9
  ori   $t6, $t8, 1
  sh    $t6, 4($t2)
  lbu   $t8, -1($v0)
  lbu   $t7, 3($t4)
  addiu $v1, $v1, 4
  sll   $t6, $t8, 0xb
  lbu   $t8, -1($v1)
  sll   $t9, $t7, 1
  or    $t7, $t9, $t6
  sll   $t9, $t8, 6
  or    $t6, $t7, $t9
  ori   $t8, $t6, 1
  sh    $t8, 6($t2)
  addiu $t4, $t4, 4
  bne   $a1, $s0, .L7F0CA4A4
   addiu $t2, $t2, 8
.L7F0CA560:
  lw    $t7, 0x1c($sp)
  addiu $a3, $a3, 1
  bne   $a3, $s2, .L7F0CA418
   addu  $t1, $t1, $t7
.L7F0CA570:
  addiu $t9, $s0, 3
  andi  $t6, $t9, 0xffc
  multu $t6, $s2
  mflo  $v0
  sll   $t8, $v0, 1
  b     .L7F0CA878
   move  $v0, $t8
.L7F0CA58C:
  blez  $s2, .L7F0CA674
   move  $a3, $zero
  addiu $a0, $s0, 7
  andi  $t7, $a0, 0xff8
  move  $a0, $t7
.L7F0CA5A0:
  blez  $s0, .L7F0CA668
   move  $a1, $zero
  multu $s0, $s2
  andi  $a2, $s0, 3
  move  $t2, $a2
  addu  $v0, $s1, $t0
  addu  $t1, $v1, $zero
  mflo  $t9
  addu  $t6, $t0, $t9
  beqz  $a2, .L7F0CA5FC
   addu  $t3, $t6, $s1
.L7F0CA5CC:
  lbu   $t7, ($v0)
  lbu   $t8, ($t3)
  addiu $a1, $a1, 1
  sll   $t9, $t7, 4
  or    $t6, $t8, $t9
  sb    $t6, ($t1)
  addiu $t0, $t0, 1
  addiu $v0, $v0, 1
  addiu $t3, $t3, 1
  bne   $t2, $a1, .L7F0CA5CC
   addiu $t1, $t1, 1
  beq   $a1, $s0, .L7F0CA668
.L7F0CA5FC:
   addu  $t1, $v1, $a1
.L7F0CA600:
  lbu   $t8, ($v0)
  lbu   $t7, ($t3)
  addiu $a1, $a1, 4
  sll   $t9, $t8, 4
  or    $t6, $t7, $t9
  sb    $t6, ($t1)
  lbu   $t7, 1($v0)
  lbu   $t8, 1($t3)
  addiu $t0, $t0, 4
  sll   $t9, $t7, 4
  or    $t6, $t8, $t9
  sb    $t6, 1($t1)
  lbu   $t8, 2($v0)
  lbu   $t7, 2($t3)
  addiu $v0, $v0, 4
  sll   $t9, $t8, 4
  or    $t6, $t7, $t9
  sb    $t6, 2($t1)
  lbu   $t7, -1($v0)
  lbu   $t8, 3($t3)
  addiu $t3, $t3, 4
  sll   $t9, $t7, 4
  or    $t6, $t8, $t9
  sb    $t6, 3($t1)
  bne   $a1, $s0, .L7F0CA600
   addiu $t1, $t1, 4
.L7F0CA668:
  addiu $a3, $a3, 1
  bne   $a3, $s2, .L7F0CA5A0
   addu  $v1, $v1, $a0
.L7F0CA674:
  addiu $t7, $s0, 7
  andi  $t8, $t7, 0xff8
  multu $t8, $s2
  mflo  $v0
  b     .L7F0CA87C
   lw    $s0, 8($sp)
.L7F0CA68C:
  blez  $s2, .L7F0CA720
   move  $a3, $zero
  addiu $a0, $s0, 7
  andi  $t9, $a0, 0xff8
  move  $a0, $t9
.L7F0CA6A0:
  blez  $s0, .L7F0CA714
   move  $a1, $zero
  andi  $a2, $s0, 3
  beqz  $a2, .L7F0CA6DC
   addu  $v0, $s1, $t0
  move  $t2, $a2
  addu  $t1, $v1, $zero
.L7F0CA6BC:
  lbu   $t6, ($v0)
  addiu $a1, $a1, 1
  addiu $t0, $t0, 1
  addiu $v0, $v0, 1
  addiu $t1, $t1, 1
  bne   $t2, $a1, .L7F0CA6BC
   sb    $t6, -1($t1)
  beq   $a1, $s0, .L7F0CA714
.L7F0CA6DC:
   addu  $t1, $v1, $a1
.L7F0CA6E0:
  lbu   $t7, ($v0)
  addiu $a1, $a1, 4
  addiu $t0, $t0, 4
  sb    $t7, ($t1)
  lbu   $t8, 1($v0)
  addiu $v0, $v0, 4
  addiu $t1, $t1, 4
  sb    $t8, -3($t1)
  lbu   $t9, -2($v0)
  sb    $t9, -2($t1)
  lbu   $t6, -1($v0)
  bne   $a1, $s0, .L7F0CA6E0
   sb    $t6, -1($t1)
.L7F0CA714:
  addiu $a3, $a3, 1
  bne   $a3, $s2, .L7F0CA6A0
   addu  $v1, $v1, $a0
.L7F0CA720:
  addiu $t7, $s0, 7
  andi  $t8, $t7, 0xff8
  multu $t8, $s2
  mflo  $v0
  b     .L7F0CA87C
   lw    $s0, 8($sp)
.L7F0CA738:
  blez  $s2, .L7F0CA7D4
   move  $a3, $zero
  addiu $a2, $s0, 0xf
  andi  $t9, $a2, 0xff0
  move  $a2, $t9
  andi  $t1, $s0, 1
.L7F0CA750:
  blez  $s0, .L7F0CA7C0
   move  $a1, $zero
  multu $s0, $s2
  addu  $v0, $s1, $t0
  mflo  $t6
  sll   $t7, $t6, 2
  subu  $t7, $t7, $t6
  addu  $t8, $t7, $t0
  addu  $a0, $t8, $s1
.L7F0CA774:
  lbu   $t6, ($v0)
  lbu   $t9, 1($a0)
  addiu $t0, $t0, 2
  sll   $t7, $t6, 5
  lbu   $t6, ($a0)
  or    $t8, $t9, $t7
  addiu $v0, $v0, 2
  sll   $t9, $t6, 4
  lbu   $t6, -1($v0)
  or    $t7, $t8, $t9
  addiu $a0, $a0, 2
  sll   $t8, $t6, 1
  sra   $t6, $a1, 1
  addiu $a1, $a1, 2
  or    $t9, $t7, $t8
  slt   $at, $a1, $s0
  addu  $t7, $v1, $t6
  bnez  $at, .L7F0CA774
   sb    $t9, ($t7)
.L7F0CA7C0:
  beqz  $t1, .L7F0CA7CC
   addiu $a3, $a3, 1
  addiu $t0, $t0, -1
.L7F0CA7CC:
  bne   $a3, $s2, .L7F0CA750
   addu  $v1, $v1, $a2
.L7F0CA7D4:
  addiu $t8, $s0, 0xf
  andi  $t6, $t8, 0xff0
  sra   $t9, $t6, 1
  multu $t9, $s2
  mflo  $v0
  b     .L7F0CA87C
   lw    $s0, 8($sp)
.L7F0CA7F0:
  blez  $s2, .L7F0CA858
   move  $a3, $zero
  addiu $a0, $s0, 0xf
  andi  $t7, $a0, 0xff0
  sra   $a0, $t7, 1
  andi  $t1, $s0, 1
.L7F0CA808:
  blez  $s0, .L7F0CA844
   move  $a1, $zero
  addu  $v0, $s1, $t0
.L7F0CA814:
  lbu   $t9, ($v0)
  lbu   $t6, 1($v0)
  addiu $t0, $t0, 2
  sll   $t7, $t9, 4
  sra   $t9, $a1, 1
  addiu $a1, $a1, 2
  or    $t8, $t6, $t7
  slt   $at, $a1, $s0
  addu  $t6, $v1, $t9
  sb    $t8, ($t6)
  bnez  $at, .L7F0CA814
   addiu $v0, $v0, 2
.L7F0CA844:
  beqz  $t1, .L7F0CA850
   addiu $a3, $a3, 1
  addiu $t0, $t0, -1
.L7F0CA850:
  bne   $a3, $s2, .L7F0CA808
   addu  $v1, $v1, $a0
.L7F0CA858:
  addiu $t7, $s0, 0xf
  andi  $t9, $t7, 0xff0
  sra   $t8, $t9, 1
  multu $t8, $s2
  mflo  $v0
  b     .L7F0CA87C
   lw    $s0, 8($sp)
def_7F0C9DF0:
.L7F0CA874:
  move  $v0, $zero
.L7F0CA878:
  lw    $s0, 8($sp)
.L7F0CA87C:
  lw    $s1, 0xc($sp)
  lw    $s2, 0x10($sp)
  lw    $s3, 0x14($sp)
  jr    $ra
   addiu $sp, $sp, 0x68
");

asm(R"
.late_rodata
/*D:8005BDE8*/
glabel jpt_8005BDE8
.word .L7F0CA908
.word .L7F0CA9FC
.word .L7F0CA97C
.word .L7F0CAA78
.word .L7F0CA9FC
.word .L7F0CAAFC
.word .L7F0CAB74
.word .L7F0CAAFC
.word .L7F0CAB74
.text
glabel type5_generate_link_final_image
  addiu $sp, $sp, -0x40
  sw    $s4, 0x28($sp)
  move  $s4, $a0
  sw    $ra, 0x3c($sp)
  sw    $fp, 0x38($sp)
  sw    $s7, 0x34($sp)
  sw    $s5, 0x2c($sp)
  sw    $s3, 0x24($sp)
  move  $s3, $a3
  sw    $s6, 0x30($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a1, 0x44($sp)
  move  $s7, $a2
  move  $fp, $a2
  move  $s5, $a2
  jal   sub_GAME_7F0C9A24
   lw    $a0, 0x50($sp)
  lw    $t6, 0x54($sp)
  move  $s2, $v0
  move  $v0, $zero
  sltiu $at, $t6, 9
  beqz  $at, .L7F0CAC28
   sll   $t6, $t6, 2
  lui   $at, %hi(jpt_8005BDE8)
  addu  $at, $at, $t6
  lw    $t6, %lo(jpt_8005BDE8)($at)
  jr    $t6
   nop   
.L7F0CA908:
  lw    $v1, 0x44($sp)
  addiu $s5, $s4, 3
  andi  $t7, $s5, 0xffc
  blez  $v1, .L7F0CA960
   move  $s6, $zero
  sll   $s5, $t7, 2
.L7F0CA920:
  blez  $s4, .L7F0CA954
   move  $s0, $zero
  move  $s1, $s7
.L7F0CA92C:
  jal   sub_GAME_7F0CBF2C
   move  $a0, $s2
  sll   $t9, $v0, 2
  addu  $t0, $s3, $t9
  lw    $t1, ($t0)
  addiu $s0, $s0, 1
  addiu $s1, $s1, 4
  bne   $s0, $s4, .L7F0CA92C
   sw    $t1, -4($s1)
  lw    $v1, 0x44($sp)
.L7F0CA954:
  addiu $s6, $s6, 1
  bne   $s6, $v1, .L7F0CA920
   addu  $s7, $s7, $s5
.L7F0CA960:
  addiu $t2, $s4, 3
  andi  $t3, $t2, 0xffc
  multu $t3, $v1
  mflo  $v0
  sll   $t4, $v0, 2
  b     .L7F0CAC28
   move  $v0, $t4
.L7F0CA97C:
  lw    $t5, 0x44($sp)
  addiu $s5, $s4, 3
  andi  $t6, $s5, 0xffc
  blez  $t5, .L7F0CA9DC
   move  $s6, $zero
  sll   $s5, $t6, 2
.L7F0CA994:
  blez  $s4, .L7F0CA9C8
   move  $s0, $zero
  move  $s1, $s7
.L7F0CA9A0:
  jal   sub_GAME_7F0CBF2C
   move  $a0, $s2
  sll   $t8, $v0, 2
  addu  $t9, $s3, $t8
  lw    $t0, ($t9)
  addiu $s0, $s0, 1
  addiu $s1, $s1, 4
  sll   $t1, $t0, 8
  bne   $s0, $s4, .L7F0CA9A0
   sw    $t1, -4($s1)
.L7F0CA9C8:
  lw    $t2, 0x44($sp)
  addiu $s6, $s6, 1
  addu  $s7, $s7, $s5
  bne   $s6, $t2, .L7F0CA994
   nop   
.L7F0CA9DC:
  lw    $t5, 0x44($sp)
  addiu $t3, $s4, 3
  andi  $t4, $t3, 0xffc
  multu $t4, $t5
  mflo  $v0
  sll   $t6, $v0, 2
  b     .L7F0CAC28
   move  $v0, $t6
.L7F0CA9FC:
  lw    $t7, 0x44($sp)
  addiu $s5, $s4, 3
  andi  $t8, $s5, 0xffc
  blez  $t7, .L7F0CAA58
   move  $s6, $zero
  sll   $s5, $t8, 1
.L7F0CAA14:
  blez  $s4, .L7F0CAA44
   move  $s0, $zero
  move  $s1, $fp
.L7F0CAA20:
  jal   sub_GAME_7F0CBF2C
   move  $a0, $s2
  sll   $t0, $v0, 1
  addu  $t1, $s3, $t0
  lhu   $t2, ($t1)
  addiu $s0, $s0, 1
  addiu $s1, $s1, 2
  bne   $s0, $s4, .L7F0CAA20
   sh    $t2, -2($s1)
.L7F0CAA44:
  lw    $t3, 0x44($sp)
  addiu $s6, $s6, 1
  addu  $fp, $fp, $s5
  bne   $s6, $t3, .L7F0CAA14
   nop   
.L7F0CAA58:
  lw    $t6, 0x44($sp)
  addiu $t4, $s4, 3
  andi  $t5, $t4, 0xffc
  multu $t5, $t6
  mflo  $v0
  sll   $t7, $v0, 1
  b     .L7F0CAC28
   move  $v0, $t7
.L7F0CAA78:
  lw    $t8, 0x44($sp)
  addiu $s5, $s4, 3
  andi  $t9, $s5, 0xffc
  blez  $t8, .L7F0CAADC
   move  $s6, $zero
  sll   $s5, $t9, 1
.L7F0CAA90:
  blez  $s4, .L7F0CAAC8
   move  $s0, $zero
  move  $s1, $fp
.L7F0CAA9C:
  jal   sub_GAME_7F0CBF2C
   move  $a0, $s2
  sll   $t1, $v0, 1
  addu  $t2, $s3, $t1
  lhu   $t3, ($t2)
  addiu $s0, $s0, 1
  addiu $s1, $s1, 2
  sll   $t4, $t3, 1
  ori   $t5, $t4, 1
  bne   $s0, $s4, .L7F0CAA9C
   sh    $t5, -2($s1)
.L7F0CAAC8:
  lw    $t6, 0x44($sp)
  addiu $s6, $s6, 1
  addu  $fp, $fp, $s5
  bne   $s6, $t6, .L7F0CAA90
   nop   
.L7F0CAADC:
  lw    $t9, 0x44($sp)
  addiu $t7, $s4, 3
  andi  $t8, $t7, 0xffc
  multu $t8, $t9
  mflo  $v0
  sll   $t0, $v0, 1
  b     .L7F0CAC28
   move  $v0, $t0
.L7F0CAAFC:
  lw    $t1, 0x44($sp)
  addiu $s7, $s4, 7
  andi  $t2, $s7, 0xff8
  blez  $t1, .L7F0CAB58
   move  $s6, $zero
  move  $s7, $t2
.L7F0CAB14:
  blez  $s4, .L7F0CAB44
   move  $s0, $zero
  move  $s1, $s5
.L7F0CAB20:
  jal   sub_GAME_7F0CBF2C
   move  $a0, $s2
  sll   $t3, $v0, 1
  addu  $t4, $s3, $t3
  lhu   $t5, ($t4)
  addiu $s0, $s0, 1
  addiu $s1, $s1, 1
  bne   $s0, $s4, .L7F0CAB20
   sb    $t5, -1($s1)
.L7F0CAB44:
  lw    $t6, 0x44($sp)
  addiu $s6, $s6, 1
  addu  $s5, $s5, $s7
  bne   $s6, $t6, .L7F0CAB14
   nop   
.L7F0CAB58:
  lw    $t9, 0x44($sp)
  addiu $t7, $s4, 7
  andi  $t8, $t7, 0xff8
  multu $t8, $t9
  mflo  $v0
  b     .L7F0CAC2C
   lw    $ra, 0x3c($sp)
.L7F0CAB74:
  lw    $t0, 0x44($sp)
  addiu $s7, $s4, 0xf
  andi  $t1, $s7, 0xff0
  blez  $t0, .L7F0CAC08
   move  $s6, $zero
  sra   $s7, $t1, 1
.L7F0CAB8C:
  blez  $s4, .L7F0CABF4
   move  $s0, $zero
.L7F0CAB94:
  jal   sub_GAME_7F0CBF2C
   move  $a0, $s2
  sll   $t4, $v0, 1
  addu  $t5, $s3, $t4
  lhu   $t6, ($t5)
  sra   $t3, $s0, 1
  addiu $t8, $s0, 1
  addu  $s1, $s5, $t3
  slt   $at, $t8, $s4
  sll   $t7, $t6, 4
  beqz  $at, .L7F0CABE4
   sb    $t7, ($s1)
  jal   sub_GAME_7F0CBF2C
   move  $a0, $s2
  sll   $t0, $v0, 1
  addu  $t1, $s3, $t0
  lbu   $t2, 1($t1)
  lbu   $t9, ($s1)
  or    $t3, $t9, $t2
  sb    $t3, ($s1)
.L7F0CABE4:
  addiu $s0, $s0, 2
  slt   $at, $s0, $s4
  bnez  $at, .L7F0CAB94
   nop   
.L7F0CABF4:
  lw    $t4, 0x44($sp)
  addiu $s6, $s6, 1
  addu  $s5, $s5, $s7
  bne   $s6, $t4, .L7F0CAB8C
   nop   
.L7F0CAC08:
  lw    $t8, 0x44($sp)
  addiu $t5, $s4, 0xf
  andi  $t6, $t5, 0xff0
  sra   $t7, $t6, 1
  multu $t7, $t8
  mflo  $v0
  b     .L7F0CAC2C
   lw    $ra, 0x3c($sp)
def_7F0CA900:
.L7F0CAC28:
  lw    $ra, 0x3c($sp)
.L7F0CAC2C:
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
.late_rodata
/*D:8005BE0C*/
glabel jpt_8005BE0C
.word .L7F0CACC4
.word .L7F0CB0AC
.word .L7F0CAE90
.word .L7F0CB26C
.word .L7F0CB0AC
.word .L7F0CB3C4
.word .L7F0CB584
.word .L7F0CB3C4
.word .L7F0CB584
.text
glabel type6_7_generate_link_final_image
  addiu $sp, $sp, -0x28
  sw    $s0, 4($sp)
  lw    $s0, 0x3c($sp)
  sw    $s2, 0xc($sp)
  sw    $s1, 8($sp)
  slti  $at, $s0, 0x101
  move  $s1, $a1
  move  $s2, $a2
  sw    $a0, 0x28($sp)
  move  $t1, $a3
  move  $t2, $a3
  beqz  $at, .L7F0CAC94
   move  $t3, $a3
  b     .L7F0CAC9C
   lw    $a1, 0x10($sp)
.L7F0CAC94:
  lw    $a1, 0x28($sp)
  lw    $a0, 0x14($sp)
.L7F0CAC9C:
  lw    $t6, 0x40($sp)
  move  $v0, $zero
  sltiu $at, $t6, 9
  beqz  $at, .L7F0CB668
   sll   $t6, $t6, 2
  lui   $at, %hi(jpt_8005BE0C)
  addu  $at, $at, $t6
  lw    $t6, %lo(jpt_8005BE0C)($at)
  jr    $t6
   nop   
.L7F0CACC4:
  blez  $s2, .L7F0CAE74
   move  $a3, $zero
  addiu $t4, $s1, 3
  andi  $t7, $t4, 0xffc
  sll   $t4, $t7, 2
  sll   $t0, $s1, 1
  lw    $v1, 0x38($sp)
.L7F0CACE0:
  blez  $s1, .L7F0CAE60
   move  $v0, $zero
  andi  $a2, $s1, 3
  beqz  $a2, .L7F0CAD4C
   move  $t3, $a2
  sll   $t9, $zero, 2
  addu  $t2, $t1, $t9
.L7F0CACFC:
  slti  $at, $s0, 0x101
  beqz  $at, .L7F0CAD24
   sll   $t7, $v0, 1
  addu  $t6, $a0, $v0
  lbu   $t7, ($t6)
  sll   $t8, $t7, 2
  addu  $t9, $v1, $t8
  lw    $t6, ($t9)
  b     .L7F0CAD3C
   sw    $t6, ($t2)
.L7F0CAD24:
  addu  $t8, $a1, $t7
  lhu   $t9, ($t8)
  sll   $t6, $t9, 2
  addu  $t7, $v1, $t6
  lw    $t8, ($t7)
  sw    $t8, ($t2)
.L7F0CAD3C:
  addiu $v0, $v0, 1
  bne   $t3, $v0, .L7F0CACFC
   addiu $t2, $t2, 4
  beq   $v0, $s1, .L7F0CAE60
.L7F0CAD4C:
   sll   $t9, $v0, 2
  addu  $t2, $t1, $t9
.L7F0CAD54:
  slti  $at, $s0, 0x101
  beqz  $at, .L7F0CAD7C
   sll   $t7, $v0, 1
  addu  $t6, $a0, $v0
  lbu   $t7, ($t6)
  sll   $t8, $t7, 2
  addu  $t9, $v1, $t8
  lw    $t6, ($t9)
  b     .L7F0CAD94
   sw    $t6, ($t2)
.L7F0CAD7C:
  addu  $t8, $a1, $t7
  lhu   $t9, ($t8)
  sll   $t6, $t9, 2
  addu  $t7, $v1, $t6
  lw    $t8, ($t7)
  sw    $t8, ($t2)
.L7F0CAD94:
  slti  $at, $s0, 0x101
  beqz  $at, .L7F0CADBC
   sll   $t6, $v0, 1
  addu  $t9, $a0, $v0
  lbu   $t6, 1($t9)
  sll   $t7, $t6, 2
  addu  $t8, $v1, $t7
  lw    $t9, ($t8)
  b     .L7F0CADD4
   sw    $t9, 4($t2)
.L7F0CADBC:
  addu  $t7, $a1, $t6
  lhu   $t8, 2($t7)
  sll   $t9, $t8, 2
  addu  $t6, $v1, $t9
  lw    $t7, ($t6)
  sw    $t7, 4($t2)
.L7F0CADD4:
  slti  $at, $s0, 0x101
  beqz  $at, .L7F0CADFC
   sll   $t9, $v0, 1
  addu  $t8, $a0, $v0
  lbu   $t9, 2($t8)
  sll   $t6, $t9, 2
  addu  $t7, $v1, $t6
  lw    $t8, ($t7)
  b     .L7F0CAE14
   sw    $t8, 8($t2)
.L7F0CADFC:
  addu  $t6, $a1, $t9
  lhu   $t7, 4($t6)
  sll   $t8, $t7, 2
  addu  $t9, $v1, $t8
  lw    $t6, ($t9)
  sw    $t6, 8($t2)
.L7F0CAE14:
  slti  $at, $s0, 0x101
  beqz  $at, .L7F0CAE3C
   sll   $t8, $v0, 1
  addu  $t7, $a0, $v0
  lbu   $t8, 3($t7)
  sll   $t9, $t8, 2
  addu  $t6, $v1, $t9
  lw    $t7, ($t6)
  b     .L7F0CAE54
   sw    $t7, 0xc($t2)
.L7F0CAE3C:
  addu  $t9, $a1, $t8
  lhu   $t6, 6($t9)
  sll   $t7, $t6, 2
  addu  $t8, $v1, $t7
  lw    $t9, ($t8)
  sw    $t9, 0xc($t2)
.L7F0CAE54:
  addiu $v0, $v0, 4
  bne   $v0, $s1, .L7F0CAD54
   addiu $t2, $t2, 0x10
.L7F0CAE60:
  addiu $a3, $a3, 1
  addu  $t1, $t1, $t4
  addu  $a0, $a0, $s1
  bne   $a3, $s2, .L7F0CACE0
   addu  $a1, $a1, $t0
.L7F0CAE74:
  addiu $t6, $s1, 3
  andi  $t7, $t6, 0xffc
  multu $t7, $s2
  mflo  $v0
  sll   $t8, $v0, 2
  b     .L7F0CB668
   move  $v0, $t8
.L7F0CAE90:
  blez  $s2, .L7F0CB090
   move  $a3, $zero
  addiu $t4, $s1, 3
  andi  $t9, $t4, 0xffc
  sll   $t4, $t9, 2
  sll   $t0, $s1, 1
  lw    $v1, 0x38($sp)
.L7F0CAEAC:
  blez  $s1, .L7F0CB07C
   move  $v0, $zero
  andi  $a2, $s1, 3
  beqz  $a2, .L7F0CAF28
   move  $t3, $a2
  sll   $t7, $zero, 2
  addu  $t2, $t1, $t7
.L7F0CAEC8:
  slti  $at, $s0, 0x101
  beqz  $at, .L7F0CAEF8
   sll   $t7, $v0, 1
  addu  $t8, $a0, $v0
  lbu   $t9, ($t8)
  sll   $t6, $t9, 2
  addu  $t7, $v1, $t6
  lw    $t8, ($t7)
  sll   $t9, $t8, 8
  ori   $t6, $t9, 0xff
  b     .L7F0CAF18
   sw    $t6, ($t2)
.L7F0CAEF8:
  addu  $t8, $a1, $t7
  lhu   $t9, ($t8)
  sll   $t6, $t9, 2
  addu  $t7, $v1, $t6
  lw    $t8, ($t7)
  sll   $t9, $t8, 8
  ori   $t6, $t9, 0xff
  sw    $t6, ($t2)
.L7F0CAF18:
  addiu $v0, $v0, 1
  bne   $t3, $v0, .L7F0CAEC8
   addiu $t2, $t2, 4
  beq   $v0, $s1, .L7F0CB07C
.L7F0CAF28:
   sll   $t7, $v0, 2
  addu  $t2, $t1, $t7
.L7F0CAF30:
  slti  $at, $s0, 0x101
  beqz  $at, .L7F0CAF60
   sll   $t7, $v0, 1
  addu  $t8, $a0, $v0
  lbu   $t9, ($t8)
  sll   $t6, $t9, 2
  addu  $t7, $v1, $t6
  lw    $t8, ($t7)
  sll   $t9, $t8, 8
  ori   $t6, $t9, 0xff
  b     .L7F0CAF80
   sw    $t6, ($t2)
.L7F0CAF60:
  addu  $t8, $a1, $t7
  lhu   $t9, ($t8)
  sll   $t6, $t9, 2
  addu  $t7, $v1, $t6
  lw    $t8, ($t7)
  sll   $t9, $t8, 8
  ori   $t6, $t9, 0xff
  sw    $t6, ($t2)
.L7F0CAF80:
  slti  $at, $s0, 0x101
  beqz  $at, .L7F0CAFB0
   sll   $t6, $v0, 1
  addu  $t7, $a0, $v0
  lbu   $t8, 1($t7)
  sll   $t9, $t8, 2
  addu  $t6, $v1, $t9
  lw    $t7, ($t6)
  sll   $t8, $t7, 8
  ori   $t9, $t8, 0xff
  b     .L7F0CAFD0
   sw    $t9, 4($t2)
.L7F0CAFB0:
  addu  $t7, $a1, $t6
  lhu   $t8, 2($t7)
  sll   $t9, $t8, 2
  addu  $t6, $v1, $t9
  lw    $t7, ($t6)
  sll   $t8, $t7, 8
  ori   $t9, $t8, 0xff
  sw    $t9, 4($t2)
.L7F0CAFD0:
  slti  $at, $s0, 0x101
  beqz  $at, .L7F0CB000
   sll   $t9, $v0, 1
  addu  $t6, $a0, $v0
  lbu   $t7, 2($t6)
  sll   $t8, $t7, 2
  addu  $t9, $v1, $t8
  lw    $t6, ($t9)
  sll   $t7, $t6, 8
  ori   $t8, $t7, 0xff
  b     .L7F0CB020
   sw    $t8, 8($t2)
.L7F0CB000:
  addu  $t6, $a1, $t9
  lhu   $t7, 4($t6)
  sll   $t8, $t7, 2
  addu  $t9, $v1, $t8
  lw    $t6, ($t9)
  sll   $t7, $t6, 8
  ori   $t8, $t7, 0xff
  sw    $t8, 8($t2)
.L7F0CB020:
  slti  $at, $s0, 0x101
  beqz  $at, .L7F0CB050
   sll   $t8, $v0, 1
  addu  $t9, $a0, $v0
  lbu   $t6, 3($t9)
  sll   $t7, $t6, 2
  addu  $t8, $v1, $t7
  lw    $t9, ($t8)
  sll   $t6, $t9, 8
  ori   $t7, $t6, 0xff
  b     .L7F0CB070
   sw    $t7, 0xc($t2)
.L7F0CB050:
  addu  $t9, $a1, $t8
  lhu   $t6, 6($t9)
  sll   $t7, $t6, 2
  addu  $t8, $v1, $t7
  lw    $t9, ($t8)
  sll   $t6, $t9, 8
  ori   $t7, $t6, 0xff
  sw    $t7, 0xc($t2)
.L7F0CB070:
  addiu $v0, $v0, 4
  bne   $v0, $s1, .L7F0CAF30
   addiu $t2, $t2, 0x10
.L7F0CB07C:
  addiu $a3, $a3, 1
  addu  $t1, $t1, $t4
  addu  $a0, $a0, $s1
  bne   $a3, $s2, .L7F0CAEAC
   addu  $a1, $a1, $t0
.L7F0CB090:
  addiu $t8, $s1, 3
  andi  $t9, $t8, 0xffc
  multu $t9, $s2
  mflo  $v0
  sll   $t6, $v0, 2
  b     .L7F0CB668
   move  $v0, $t6
.L7F0CB0AC:
  blez  $s2, .L7F0CB250
   move  $a3, $zero
  addiu $t5, $s1, 3
  andi  $t7, $t5, 0xffc
  sll   $t5, $t7, 1
  sll   $t0, $s1, 1
  lw    $v1, 0x38($sp)
.L7F0CB0C8:
  blez  $s1, .L7F0CB23C
   move  $v0, $zero
  andi  $a2, $s1, 3
  beqz  $a2, .L7F0CB134
   move  $t4, $a2
  sll   $t1, $zero, 1
  addu  $t3, $t2, $t1
.L7F0CB0E4:
  slti  $at, $s0, 0x101
  beqz  $at, .L7F0CB10C
   addu  $t6, $a1, $t1
  addu  $t9, $a0, $v0
  lbu   $t6, ($t9)
  sll   $t7, $t6, 1
  addu  $t8, $v1, $t7
  lhu   $t9, ($t8)
  b     .L7F0CB120
   sh    $t9, ($t3)
.L7F0CB10C:
  lhu   $t7, ($t6)
  sll   $t8, $t7, 1
  addu  $t9, $v1, $t8
  lhu   $t6, ($t9)
  sh    $t6, ($t3)
.L7F0CB120:
  addiu $v0, $v0, 1
  addiu $t1, $t1, 2
  bne   $t4, $v0, .L7F0CB0E4
   addiu $t3, $t3, 2
  beq   $v0, $s1, .L7F0CB23C
.L7F0CB134:
   sll   $t1, $v0, 1
  addu  $t3, $t2, $t1
.L7F0CB13C:
  slti  $at, $s0, 0x101
  beqz  $at, .L7F0CB164
   addu  $t8, $a1, $t1
  addu  $t7, $a0, $v0
  lbu   $t8, ($t7)
  sll   $t9, $t8, 1
  addu  $t6, $v1, $t9
  lhu   $t7, ($t6)
  b     .L7F0CB178
   sh    $t7, ($t3)
.L7F0CB164:
  lhu   $t9, ($t8)
  sll   $t6, $t9, 1
  addu  $t7, $v1, $t6
  lhu   $t8, ($t7)
  sh    $t8, ($t3)
.L7F0CB178:
  slti  $at, $s0, 0x101
  beqz  $at, .L7F0CB1A0
   addu  $t6, $a1, $t1
  addu  $t9, $a0, $v0
  lbu   $t6, 1($t9)
  sll   $t7, $t6, 1
  addu  $t8, $v1, $t7
  lhu   $t9, ($t8)
  b     .L7F0CB1B4
   sh    $t9, 2($t3)
.L7F0CB1A0:
  lhu   $t7, 2($t6)
  sll   $t8, $t7, 1
  addu  $t9, $v1, $t8
  lhu   $t6, ($t9)
  sh    $t6, 2($t3)
.L7F0CB1B4:
  slti  $at, $s0, 0x101
  beqz  $at, .L7F0CB1DC
   addu  $t8, $a1, $t1
  addu  $t7, $a0, $v0
  lbu   $t8, 2($t7)
  sll   $t9, $t8, 1
  addu  $t6, $v1, $t9
  lhu   $t7, ($t6)
  b     .L7F0CB1F0
   sh    $t7, 4($t3)
.L7F0CB1DC:
  lhu   $t9, 4($t8)
  sll   $t6, $t9, 1
  addu  $t7, $v1, $t6
  lhu   $t8, ($t7)
  sh    $t8, 4($t3)
.L7F0CB1F0:
  slti  $at, $s0, 0x101
  beqz  $at, .L7F0CB218
   addu  $t6, $a1, $t1
  addu  $t9, $a0, $v0
  lbu   $t6, 3($t9)
  sll   $t7, $t6, 1
  addu  $t8, $v1, $t7
  lhu   $t9, ($t8)
  b     .L7F0CB22C
   sh    $t9, 6($t3)
.L7F0CB218:
  lhu   $t7, 6($t6)
  sll   $t8, $t7, 1
  addu  $t9, $v1, $t8
  lhu   $t6, ($t9)
  sh    $t6, 6($t3)
.L7F0CB22C:
  addiu $v0, $v0, 4
  addiu $t1, $t1, 8
  bne   $v0, $s1, .L7F0CB13C
   addiu $t3, $t3, 8
.L7F0CB23C:
  addiu $a3, $a3, 1
  addu  $t2, $t2, $t5
  addu  $a0, $a0, $s1
  bne   $a3, $s2, .L7F0CB0C8
   addu  $a1, $a1, $t0
.L7F0CB250:
  addiu $t7, $s1, 3
  andi  $t8, $t7, 0xffc
  multu $t8, $s2
  mflo  $v0
  sll   $t9, $v0, 1
  b     .L7F0CB668
   move  $v0, $t9
.L7F0CB26C:
  blez  $s2, .L7F0CB3A8
   move  $a3, $zero
  addiu $t5, $s1, 3
  andi  $t6, $t5, 0xffc
  sll   $t5, $t6, 1
  sll   $t0, $s1, 1
  lw    $v1, 0x38($sp)
.L7F0CB288:
  blez  $s1, .L7F0CB394
   move  $v0, $zero
  andi  $a2, $s1, 1
  beqz  $a2, .L7F0CB2E4
   slti  $at, $s0, 0x101
  beqz  $at, .L7F0CB2C4
   li    $v0, 1
  lbu   $t8, ($a0)
  sll   $t9, $t8, 1
  addu  $t6, $v1, $t9
  lhu   $t7, ($t6)
  sll   $t8, $t7, 1
  ori   $t9, $t8, 1
  b     .L7F0CB2E0
   sh    $t9, ($t2)
.L7F0CB2C4:
  lhu   $t6, ($a1)
  sll   $t7, $t6, 1
  addu  $t8, $v1, $t7
  lhu   $t9, ($t8)
  sll   $t6, $t9, 1
  ori   $t7, $t6, 1
  sh    $t7, ($t2)
.L7F0CB2E0:
  beq   $v0, $s1, .L7F0CB394
.L7F0CB2E4:
   sll   $t1, $v0, 1
  addu  $t3, $t2, $t1
.L7F0CB2EC:
  slti  $at, $s0, 0x101
  beqz  $at, .L7F0CB31C
   addu  $t7, $a1, $t1
  addu  $t8, $a0, $v0
  lbu   $t9, ($t8)
  sll   $t6, $t9, 1
  addu  $t7, $v1, $t6
  lhu   $t8, ($t7)
  sll   $t9, $t8, 1
  ori   $t6, $t9, 1
  b     .L7F0CB338
   sh    $t6, ($t3)
.L7F0CB31C:
  lhu   $t8, ($t7)
  sll   $t9, $t8, 1
  addu  $t6, $v1, $t9
  lhu   $t7, ($t6)
  sll   $t8, $t7, 1
  ori   $t9, $t8, 1
  sh    $t9, ($t3)
.L7F0CB338:
  slti  $at, $s0, 0x101
  beqz  $at, .L7F0CB368
   addu  $t9, $a1, $t1
  addu  $t6, $a0, $v0
  lbu   $t7, 1($t6)
  sll   $t8, $t7, 1
  addu  $t9, $v1, $t8
  lhu   $t6, ($t9)
  sll   $t7, $t6, 1
  ori   $t8, $t7, 1
  b     .L7F0CB384
   sh    $t8, 2($t3)
.L7F0CB368:
  lhu   $t6, 2($t9)
  sll   $t7, $t6, 1
  addu  $t8, $v1, $t7
  lhu   $t9, ($t8)
  sll   $t6, $t9, 1
  ori   $t7, $t6, 1
  sh    $t7, 2($t3)
.L7F0CB384:
  addiu $v0, $v0, 2
  addiu $t1, $t1, 4
  bne   $v0, $s1, .L7F0CB2EC
   addiu $t3, $t3, 4
.L7F0CB394:
  addiu $a3, $a3, 1
  addu  $t2, $t2, $t5
  addu  $a0, $a0, $s1
  bne   $a3, $s2, .L7F0CB288
   addu  $a1, $a1, $t0
.L7F0CB3A8:
  addiu $t8, $s1, 3
  andi  $t9, $t8, 0xffc
  multu $t9, $s2
  mflo  $v0
  sll   $t6, $v0, 1
  b     .L7F0CB668
   move  $v0, $t6
.L7F0CB3C4:
  blez  $s2, .L7F0CB56C
   move  $a3, $zero
  addiu $t1, $s1, 7
  andi  $t7, $t1, 0xff8
  move  $t1, $t7
  sll   $t0, $s1, 1
  lw    $v1, 0x38($sp)
.L7F0CB3E0:
  blez  $s1, .L7F0CB558
   move  $v0, $zero
  andi  $a2, $s1, 3
  beqz  $a2, .L7F0CB448
   move  $t4, $a2
  addu  $t2, $t3, $zero
.L7F0CB3F8:
  slti  $at, $s0, 0x101
  beqz  $at, .L7F0CB420
   sll   $t9, $v0, 1
  addu  $t8, $a0, $v0
  lbu   $t9, ($t8)
  sll   $t6, $t9, 1
  addu  $t7, $v1, $t6
  lhu   $t8, ($t7)
  b     .L7F0CB438
   sb    $t8, ($t2)
.L7F0CB420:
  addu  $t6, $a1, $t9
  lhu   $t7, ($t6)
  sll   $t8, $t7, 1
  addu  $t9, $v1, $t8
  lhu   $t6, ($t9)
  sb    $t6, ($t2)
.L7F0CB438:
  addiu $v0, $v0, 1
  bne   $t4, $v0, .L7F0CB3F8
   addiu $t2, $t2, 1
  beq   $v0, $s1, .L7F0CB558
.L7F0CB448:
   addu  $t2, $t3, $v0
.L7F0CB44C:
  slti  $at, $s0, 0x101
  beqz  $at, .L7F0CB474
   sll   $t8, $v0, 1
  addu  $t7, $a0, $v0
  lbu   $t8, ($t7)
  sll   $t9, $t8, 1
  addu  $t6, $v1, $t9
  lhu   $t7, ($t6)
  b     .L7F0CB48C
   sb    $t7, ($t2)
.L7F0CB474:
  addu  $t9, $a1, $t8
  lhu   $t6, ($t9)
  sll   $t7, $t6, 1
  addu  $t8, $v1, $t7
  lhu   $t9, ($t8)
  sb    $t9, ($t2)
.L7F0CB48C:
  slti  $at, $s0, 0x101
  beqz  $at, .L7F0CB4B4
   sll   $t7, $v0, 1
  addu  $t6, $a0, $v0
  lbu   $t7, 1($t6)
  sll   $t8, $t7, 1
  addu  $t9, $v1, $t8
  lhu   $t6, ($t9)
  b     .L7F0CB4CC
   sb    $t6, 1($t2)
.L7F0CB4B4:
  addu  $t8, $a1, $t7
  lhu   $t9, 2($t8)
  sll   $t6, $t9, 1
  addu  $t7, $v1, $t6
  lhu   $t8, ($t7)
  sb    $t8, 1($t2)
.L7F0CB4CC:
  slti  $at, $s0, 0x101
  beqz  $at, .L7F0CB4F4
   sll   $t6, $v0, 1
  addu  $t9, $a0, $v0
  lbu   $t6, 2($t9)
  sll   $t7, $t6, 1
  addu  $t8, $v1, $t7
  lhu   $t9, ($t8)
  b     .L7F0CB50C
   sb    $t9, 2($t2)
.L7F0CB4F4:
  addu  $t7, $a1, $t6
  lhu   $t8, 4($t7)
  sll   $t9, $t8, 1
  addu  $t6, $v1, $t9
  lhu   $t7, ($t6)
  sb    $t7, 2($t2)
.L7F0CB50C:
  slti  $at, $s0, 0x101
  beqz  $at, .L7F0CB534
   sll   $t9, $v0, 1
  addu  $t8, $a0, $v0
  lbu   $t9, 3($t8)
  sll   $t6, $t9, 1
  addu  $t7, $v1, $t6
  lhu   $t8, ($t7)
  b     .L7F0CB54C
   sb    $t8, 3($t2)
.L7F0CB534:
  addu  $t6, $a1, $t9
  lhu   $t7, 6($t6)
  sll   $t8, $t7, 1
  addu  $t9, $v1, $t8
  lhu   $t6, ($t9)
  sb    $t6, 3($t2)
.L7F0CB54C:
  addiu $v0, $v0, 4
  bne   $v0, $s1, .L7F0CB44C
   addiu $t2, $t2, 4
.L7F0CB558:
  addiu $a3, $a3, 1
  addu  $t3, $t3, $t1
  addu  $a0, $a0, $s1
  bne   $a3, $s2, .L7F0CB3E0
   addu  $a1, $a1, $t0
.L7F0CB56C:
  addiu $t7, $s1, 7
  andi  $t8, $t7, 0xff8
  multu $t8, $s2
  mflo  $v0
  b     .L7F0CB66C
   lw    $s0, 4($sp)
.L7F0CB584:
  blez  $s2, .L7F0CB64C
   move  $a3, $zero
  addiu $t1, $s1, 0xf
  andi  $t9, $t1, 0xff0
  sra   $t1, $t9, 1
  sll   $t0, $s1, 1
  lw    $v1, 0x38($sp)
.L7F0CB5A0:
  blez  $s1, .L7F0CB638
   move  $v0, $zero
  slti  $at, $s0, 0x101
.L7F0CB5AC:
  beqz  $at, .L7F0CB5F0
   sll   $t8, $v0, 1
  addu  $a2, $v0, $a0
  lbu   $t7, 1($a2)
  sll   $t8, $t7, 1
  lbu   $t7, ($a2)
  addu  $t9, $v1, $t8
  lhu   $t6, ($t9)
  sll   $t8, $t7, 1
  addu  $t9, $v1, $t8
  lhu   $t7, ($t9)
  sll   $t8, $t7, 4
  sra   $t7, $v0, 1
  or    $t9, $t6, $t8
  addu  $t6, $t3, $t7
  b     .L7F0CB628
   sb    $t9, ($t6)
.L7F0CB5F0:
  addu  $a2, $a1, $t8
  lhu   $t7, 2($a2)
  sll   $t9, $t7, 1
  lhu   $t7, ($a2)
  addu  $t6, $v1, $t9
  lhu   $t8, ($t6)
  sll   $t9, $t7, 1
  addu  $t6, $v1, $t9
  lhu   $t7, ($t6)
  sll   $t9, $t7, 4
  sra   $t7, $v0, 1
  or    $t6, $t8, $t9
  addu  $t8, $t3, $t7
  sb    $t6, ($t8)
.L7F0CB628:
  addiu $v0, $v0, 2
  slt   $at, $v0, $s1
  bnezl $at, .L7F0CB5AC
   slti  $at, $s0, 0x101
.L7F0CB638:
  addiu $a3, $a3, 1
  addu  $t3, $t3, $t1
  addu  $a0, $a0, $s1
  bne   $a3, $s2, .L7F0CB5A0
   addu  $a1, $a1, $t0
.L7F0CB64C:
  addiu $t9, $s1, 0xf
  andi  $t7, $t9, 0xff0
  sra   $t6, $t7, 1
  multu $t6, $s2
  mflo  $v0
  b     .L7F0CB66C
   lw    $s0, 4($sp)
def_7F0CACBC:
.L7F0CB668:
  lw    $s0, 4($sp)
.L7F0CB66C:
  lw    $s1, 8($sp)
  lw    $s2, 0xc($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
.late_rodata
/*D:8005BE30*/
glabel jpt_8005BE30
.word .L7F0CB6A8
.word .L7F0CB6BC
.word .L7F0CB6A8
.word .L7F0CB6BC
.word .L7F0CB6BC
.word .L7F0CB6D4
.word .L7F0CB6EC
.word .L7F0CB6D4
.word .L7F0CB6EC
.word .L7F0CB6D4
.word .L7F0CB6EC
.word .L7F0CB6D4
.word .L7F0CB6EC
.text
glabel sub_GAME_7F0CB67C
  addiu $sp, $sp, -0x10
  sltiu $at, $a3, 0xd
  sw    $a1, 0x14($sp)
  beqz  $at, .L7F0CB700
   move  $v1, $a3
  sll   $t6, $a3, 2
  lui   $at, %hi(jpt_8005BE30)
  addu  $at, $at, $t6
  lw    $t6, %lo(jpt_8005BE30)($at)
  jr    $t6
   nop   
.L7F0CB6A8:
  lw    $a1, 0x14($sp)
  addiu $a1, $a1, 3
  andi  $t7, $a1, 0xffc
  b     .L7F0CB700
   sw    $t7, 4($sp)
.L7F0CB6BC:
  lw    $a1, 0x14($sp)
  addiu $a1, $a1, 3
  andi  $t8, $a1, 0xffc
  sra   $t9, $t8, 1
  b     .L7F0CB700
   sw    $t9, 4($sp)
.L7F0CB6D4:
  lw    $a1, 0x14($sp)
  addiu $a1, $a1, 7
  andi  $t2, $a1, 0xff8
  sra   $t3, $t2, 2
  b     .L7F0CB700
   sw    $t3, 4($sp)
.L7F0CB6EC:
  lw    $a1, 0x14($sp)
  addiu $a1, $a1, 0xf
  andi  $t4, $a1, 0xff0
  sra   $t5, $t4, 3
  sw    $t5, 4($sp)
def_7F0CB6A0:
.L7F0CB700:
  lw    $a1, 4($sp)
  li    $at, 2
  sll   $t6, $a1, 2
  beqz  $v1, .L7F0CB718
   addu  $v0, $a0, $t6
  bne   $v1, $at, .L7F0CB784
.L7F0CB718:
   slti  $at, $a2, 2
  bnez  $at, .L7F0CB7D8
   li    $v1, 1
  move  $t1, $a1
  sll   $t7, $t1, 3
  move  $t1, $t7
.L7F0CB730:
  blez  $a1, .L7F0CB76C
   move  $a0, $zero
  move  $t0, $v0
.L7F0CB73C:
  lw    $a3, ($t0)
  lw    $t8, 8($t0)
  lw    $t9, 0xc($t0)
  sw    $a3, 8($t0)
  lw    $a3, 4($t0)
  addiu $a0, $a0, 4
  slt   $at, $a0, $a1
  addiu $t0, $t0, 0x10
  sw    $t8, -0x10($t0)
  sw    $t9, -0xc($t0)
  bnez  $at, .L7F0CB73C
   sw    $a3, -4($t0)
.L7F0CB76C:
  addiu $v1, $v1, 2
  slt   $at, $v1, $a2
  bnez  $at, .L7F0CB730
   addu  $v0, $v0, $t1
  b     .L7F0CB7D8
   nop   
.L7F0CB784:
  slti  $at, $a2, 2
  bnez  $at, .L7F0CB7D8
   li    $v1, 1
  move  $t1, $a1
  sll   $t2, $t1, 3
  move  $t1, $t2
.L7F0CB79C:
  blez  $a1, .L7F0CB7C8
   move  $a0, $zero
  move  $t0, $v0
.L7F0CB7A8:
  lw    $a3, ($t0)
  lw    $t3, 4($t0)
  addiu $a0, $a0, 2
  slt   $at, $a0, $a1
  addiu $t0, $t0, 8
  sw    $a3, -4($t0)
  bnez  $at, .L7F0CB7A8
   sw    $t3, -8($t0)
.L7F0CB7C8:
  addiu $v1, $v1, 2
  slt   $at, $v1, $a2
  bnez  $at, .L7F0CB79C
   addu  $v0, $v0, $t1
.L7F0CB7D8:
  jr    $ra
   addiu $sp, $sp, 0x10
");

asm(R"
.late_rodata
/*D:8005BE64*/
glabel jpt_8005BE64
.word .L7F0CB8A8
.word .L7F0CB8EC
.word .L7F0CB930
.word .L7F0CB974
.word .L7F0CB9C0
.word .L7F0CBA1C
.word .L7F0CBA78
.text
glabel type8_9_doohick
  addiu $sp, $sp, -0x10
  sw    $s1, 8($sp)
  sw    $s0, 4($sp)
  move  $s0, $a0
  move  $s1, $a3
  sw    $s2, 0xc($sp)
  blez  $a2, .L7F0CBAE0
   move  $v0, $zero
  lw    $t1, 0x20($sp)
.L7F0CB804:
  blez  $a1, .L7F0CBAD4
   move  $v1, $zero
  multu $v0, $a1
  sll   $t2, $t1, 1
  move  $s2, $s1
  mflo  $a3
  addu  $t0, $a3, $s0
  nop   
.L7F0CB824:
  lbu   $t6, ($t0)
  sltiu $at, $s2, 7
  blez  $v1, .L7F0CB83C
   addu  $a0, $t6, $t2
  b     .L7F0CB840
   lbu   $t3, -1($t0)
.L7F0CB83C:
  move  $t3, $zero
.L7F0CB840:
  blez  $v0, .L7F0CB864
   move  $t4, $zero
  addiu $t7, $v0, -1
  multu $t7, $a1
  mflo  $t8
  addu  $t9, $t8, $v1
  addu  $t6, $t9, $s0
  b     .L7F0CB864
   lbu   $t4, ($t6)
.L7F0CB864:
  blez  $v1, .L7F0CB88C
   move  $t5, $zero
  blez  $v0, .L7F0CB88C
   addiu $t7, $v0, -1
  multu $t7, $a1
  mflo  $t8
  addu  $t9, $t8, $v1
  addu  $t6, $t9, $s0
  b     .L7F0CB88C
   lbu   $t5, -1($t6)
.L7F0CB88C:
  beqz  $at, .L7F0CBAC8
   sll   $t7, $s2, 2
  lui   $at, %hi(jpt_8005BE64)
  addu  $at, $at, $t7
  lw    $t7, %lo(jpt_8005BE64)($at)
  jr    $t7
   nop   
.L7F0CB8A8:
  addu  $t8, $a0, $t3
  div   $zero, $t8, $t1
  addu  $t6, $s0, $a3
  addu  $t7, $t6, $v1
  mfhi  $t9
  sb    $t9, ($t7)
  bnez  $t1, .L7F0CB8CC
   nop   
  break 7
.L7F0CB8CC:
  li    $at, -1
  bne   $t1, $at, .L7F0CB8E4
   lui   $at, 0x8000
  bne   $t8, $at, .L7F0CB8E4
   nop   
  break 6
.L7F0CB8E4:
  b     .L7F0CBACC
   addiu $v1, $v1, 1
.L7F0CB8EC:
  addu  $t8, $a0, $t4
  div   $zero, $t8, $t1
  addu  $t9, $s0, $a3
  addu  $t7, $t9, $v1
  mfhi  $t6
  sb    $t6, ($t7)
  bnez  $t1, .L7F0CB910
   nop   
  break 7
.L7F0CB910:
  li    $at, -1
  bne   $t1, $at, .L7F0CB928
   lui   $at, 0x8000
  bne   $t8, $at, .L7F0CB928
   nop   
  break 6
.L7F0CB928:
  b     .L7F0CBACC
   addiu $v1, $v1, 1
.L7F0CB930:
  addu  $t8, $a0, $t5
  div   $zero, $t8, $t1
  addu  $t6, $s0, $a3
  addu  $t7, $t6, $v1
  mfhi  $t9
  sb    $t9, ($t7)
  bnez  $t1, .L7F0CB954
   nop   
  break 7
.L7F0CB954:
  li    $at, -1
  bne   $t1, $at, .L7F0CB96C
   lui   $at, 0x8000
  bne   $t8, $at, .L7F0CB96C
   nop   
  break 6
.L7F0CB96C:
  b     .L7F0CBACC
   addiu $v1, $v1, 1
.L7F0CB974:
  addu  $t8, $t3, $t4
  subu  $t6, $t8, $t5
  addu  $t9, $t6, $a0
  div   $zero, $t9, $t1
  addu  $t8, $s0, $a3
  addu  $t6, $t8, $v1
  mfhi  $t7
  sb    $t7, ($t6)
  bnez  $t1, .L7F0CB9A0
   nop   
  break 7
.L7F0CB9A0:
  li    $at, -1
  bne   $t1, $at, .L7F0CB9B8
   lui   $at, 0x8000
  bne   $t9, $at, .L7F0CB9B8
   nop   
  break 6
.L7F0CB9B8:
  b     .L7F0CBACC
   addiu $v1, $v1, 1
.L7F0CB9C0:
  subu  $t9, $t4, $t5
  bgez  $t9, .L7F0CB9D4
   sra   $t8, $t9, 1
  addiu $at, $t9, 1
  sra   $t8, $at, 1
.L7F0CB9D4:
  addu  $t7, $t8, $t3
  addu  $t6, $t7, $a0
  div   $zero, $t6, $t1
  addu  $t8, $s0, $a3
  addu  $t7, $t8, $v1
  mfhi  $t9
  sb    $t9, ($t7)
  bnez  $t1, .L7F0CB9FC
   nop   
  break 7
.L7F0CB9FC:
  li    $at, -1
  bne   $t1, $at, .L7F0CBA14
   lui   $at, 0x8000
  bne   $t6, $at, .L7F0CBA14
   nop   
  break 6
.L7F0CBA14:
  b     .L7F0CBACC
   addiu $v1, $v1, 1
.L7F0CBA1C:
  subu  $t6, $t3, $t5
  bgez  $t6, .L7F0CBA30
   sra   $t8, $t6, 1
  addiu $at, $t6, 1
  sra   $t8, $at, 1
.L7F0CBA30:
  addu  $t9, $t8, $t4
  addu  $t7, $t9, $a0
  div   $zero, $t7, $t1
  addu  $t8, $s0, $a3
  addu  $t9, $t8, $v1
  mfhi  $t6
  sb    $t6, ($t9)
  bnez  $t1, .L7F0CBA58
   nop   
  break 7
.L7F0CBA58:
  li    $at, -1
  bne   $t1, $at, .L7F0CBA70
   lui   $at, 0x8000
  bne   $t7, $at, .L7F0CBA70
   nop   
  break 6
.L7F0CBA70:
  b     .L7F0CBACC
   addiu $v1, $v1, 1
.L7F0CBA78:
  addu  $t7, $t3, $t4
  bgez  $t7, .L7F0CBA8C
   sra   $t8, $t7, 1
  addiu $at, $t7, 1
  sra   $t8, $at, 1
.L7F0CBA8C:
  addu  $t6, $t8, $a0
  div   $zero, $t6, $t1
  mfhi  $t9
  addu  $t7, $s0, $a3
  addu  $t8, $t7, $v1
  sb    $t9, ($t8)
  bnez  $t1, .L7F0CBAB0
   nop   
  break 7
.L7F0CBAB0:
  li    $at, -1
  bne   $t1, $at, .L7F0CBAC8
   lui   $at, 0x8000
  bne   $t6, $at, .L7F0CBAC8
   nop   
  break 6
def_7F0CB8A0:
.L7F0CBAC8:
  addiu $v1, $v1, 1
.L7F0CBACC:
  bne   $v1, $a1, .L7F0CB824
   addiu $t0, $t0, 1
.L7F0CBAD4:
  addiu $v0, $v0, 1
  bne   $v0, $a2, .L7F0CB804
   nop   
.L7F0CBAE0:
  lw    $s0, 4($sp)
  lw    $s1, 8($sp)
  lw    $s2, 0xc($sp)
  jr    $ra
   addiu $sp, $sp, 0x10
");

asm(R"
glabel sub_GAME_7F0CBAF4
  addu  $v0, $a1, $a2
  sw    $a1, ($a0)
  sw    $v0, 4($a0)
  sw    $a1, 8($a0)
  jr    $ra
   sw    $v0, 0xc($a0)
");

asm(R"
glabel sub_GAME_7F0CBB0C
  bnezl $a1, .L7F0CBB20
   lw    $v0, 4($a1)
  lui   $a1, %hi(ptr_texture_alloc_start)
  addiu $a1, %lo(ptr_texture_alloc_start) # addiu $a1, $a1, -0x38e0
  lw    $v0, 4($a1)
.L7F0CBB20:
  lw    $v1, 0xc($a1)
  sltu  $at, $v1, $v0
  beql  $at, $zero, .L7F0CBB5C
   move  $v0, $zero
  lw    $t6, ($v1)
.L7F0CBB34:
  srl   $t7, $t6, 0x14
  bnel  $a0, $t7, .L7F0CBB4C
   addiu $v1, $v1, 0x10
  jr    $ra
   move  $v0, $v1

  addiu $v1, $v1, 0x10
.L7F0CBB4C:
  sltu  $at, $v1, $v0
  bnezl $at, .L7F0CBB34
   lw    $t6, ($v1)
  move  $v0, $zero
.L7F0CBB5C:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0CBB64
  lw    $t6, 0xc($a0)
  lw    $t7, 8($a0)
  jr    $ra
   subu  $v0, $t6, $t7
");

asm(R"
glabel check_load_image_to_buffer
  addiu $sp, $sp, -0x30
  sw    $ra, 0x2c($sp)
  sw    $s5, 0x28($sp)
  sw    $s4, 0x24($sp)
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  lbu   $t6, ($a0)
  li    $s2, 184
  move  $s1, $a1
  beq   $s2, $t6, .L7F0CBBF4
   move  $s0, $a0
  lbu   $v0, ($a0)
  li    $s5, 205
  li    $s4, 171
  li    $s3, 253
.L7F0CBBB8:
  bnel  $s3, $v0, .L7F0CBBE8
   lbu   $v0, 8($s0)
  lbu   $t7, 4($s0)
  bnel  $s4, $t7, .L7F0CBBE8
   lbu   $v0, 8($s0)
  lbu   $t8, 5($s0)
  addiu $a0, $s0, 4
  bnel  $s5, $t8, .L7F0CBBE8
   lbu   $v0, 8($s0)
  jal   load_image_to_buffer
   move  $a1, $s1
  lbu   $v0, 8($s0)
.L7F0CBBE8:
  addiu $s0, $s0, 8
  bne   $s2, $v0, .L7F0CBBB8
   nop   
.L7F0CBBF4:
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
glabel load_image_to_buffer
  addiu $sp, $sp, -0xff8
  sw    $s0, 0x20($sp)
  move  $s0, $a1
  sw    $ra, 0x24($sp)
  bnez  $a1, .L7F0CBC38
   sw    $a0, 0xff8($sp)
  lui   $s0, %hi(ptr_texture_alloc_start)
  addiu $s0, %lo(ptr_texture_alloc_start) # addiu $s0, $s0, -0x38e0
.L7F0CBC38:
  lw    $t6, 0xff8($sp)
  lui   $v0, %hi(dword_CODE_bss_8008D094)
  addiu $v0, %lo(dword_CODE_bss_8008D094) # addiu $v0, $v0, -0x2f6c
  lw    $t7, ($t6)
  move  $a1, $s0
  andi  $a0, $t7, 0xffff
  jal   sub_GAME_7F0CBB0C
   sw    $a0, ($v0)
  bnez  $v0, .L7F0CBE2C
   move  $v1, $v0
  addiu $v1, $sp, 0x67
  srl   $t9, $v1, 4
  sll   $t0, $t9, 4
  jal   osWritebackDCacheAll
   sw    $t0, 0x2c($sp)
  lw    $a0, 0x2c($sp)
  jal   osInvalDCache
   li    $a1, 8192
  lui   $t1, %hi(dword_CODE_bss_8008D094) 
  lw    $t1, %lo(dword_CODE_bss_8008D094)($t1)
  lui   $t3, %hi(image_entries) 
  addiu $t3, %lo(image_entries) # addiu $t3, $t3, -0x6d00
  sll   $t2, $t1, 3
  addu  $v0, $t2, $t3
  lw    $v1, ($v0)
  lw    $a3, 8($v0)
  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
  and   $t4, $v1, $at
  and   $t5, $a3, $at
  subu  $a2, $t5, $t4
  addiu $a2, $a2, 0x1f
  li    $at, -8
  lui   $t7, %hi(_imagesRomSegmentStart) # $t7, 0x8f
  addiu $t7, %lo(_imagesRomSegmentStart) # addiu $t7, $t7, 0x7df0
  and   $t6, $t4, $at
  srl   $t8, $a2, 4
  sll   $a2, $t8, 4
  addu  $a1, $t6, $t7
  sw    $t4, 0x3c($sp)
  jal   romCopy
   lw    $a0, 0x2c($sp)
  lw    $v1, 0x3c($sp)
  lw    $t0, 0x2c($sp)
  move  $a0, $s0
  andi  $t1, $v1, 7
  addu  $t2, $t0, $t1
  sw    $t2, 0x54($sp)
  lbu   $v0, ($t2)
  addiu $t5, $t2, 1
  sw    $t5, 0x54($sp)
  andi  $a2, $v0, 0x80
  andi  $a1, $v0, 0x40
  sra   $t3, $a2, 7
  sra   $t4, $a1, 6
  move  $a2, $t3
  move  $a1, $t4
  bnez  $t4, .L7F0CBD48
   andi  $a3, $v0, 0x3f
  sw    $t4, 0x4c($sp)
  sw    $t3, 0x50($sp)
  jal   sub_GAME_7F0CBB64
   sw    $a3, 0x48($sp)
  slti  $at, $v0, 0x10cc
  lw    $a1, 0x4c($sp)
  lw    $a2, 0x50($sp)
  bnez  $at, .L7F0CBD74
   lw    $a3, 0x48($sp)
.L7F0CBD48:
  beqz  $a1, .L7F0CBD88
   move  $a0, $s0
  sw    $a1, 0x4c($sp)
  sw    $a2, 0x50($sp)
  jal   sub_GAME_7F0CBB64
   sw    $a3, 0x48($sp)
  slti  $at, $v0, 0xa28
  lw    $a1, 0x4c($sp)
  lw    $a2, 0x50($sp)
  beqz  $at, .L7F0CBD88
   lw    $a3, 0x48($sp)
.L7F0CBD74:
  jal   osVirtualToPhysical
   lw    $a0, ($s0)
  lw    $t6, 0xff8($sp)
  b     .L7F0CBE3C
   sw    $v0, ($t6)
.L7F0CBD88:
  lui   $t7, %hi(dword_CODE_bss_8008D094) 
  lw    $v0, 8($s0)
  lw    $t7, %lo(dword_CODE_bss_8008D094)($t7)
  lui   $t3, %hi(dword_CODE_bss_8008D094) 
  sh    $t7, ($v0)
  lw    $t8, 8($s0)
  lw    $t0, 0xc($s0)
  addiu $t9, $t8, 8
  addiu $t1, $t0, -0x10
  sw    $t9, 8($s0)
  sw    $t1, 0xc($s0)
  lhu   $t6, ($t1)
  lw    $t4, %lo(dword_CODE_bss_8008D094)($t3)
  move  $v1, $t1
  andi  $t7, $t6, 0xf
  sll   $t5, $t4, 4
  or    $t8, $t5, $t7
  sh    $t8, ($t1)
  lw    $t9, 8($s0)
  beqz  $a1, .L7F0CBDF8
   sw    $t9, 4($t1)
  lw    $a1, 8($s0)
  sw    $t1, 0x44($sp)
  sw    $s0, 0x10($sp)
  jal   image_related_calls_decompressdata_function
   lw    $a0, 0x54($sp)
  b     .L7F0CBE10
   lw    $v1, 0x44($sp)
.L7F0CBDF8:
  lw    $a1, 8($s0)
  sw    $v1, 0x44($sp)
  sw    $s0, 0x10($sp)
  jal   process_huffman_compressed_images
   lw    $a0, 0x54($sp)
  lw    $v1, 0x44($sp)
.L7F0CBE10:
  lw    $t0, 8($s0)
  move  $a0, $s0
  addu  $t1, $t0, $v0
  sw    $t1, 8($s0)
  jal   sub_GAME_7F0CBB64
   sw    $v1, 0x44($sp)
  lw    $v1, 0x44($sp)
.L7F0CBE2C:
  jal   osVirtualToPhysical
   lw    $a0, 4($v1)
  lw    $t3, 0xff8($sp)
  sw    $v0, ($t3)
.L7F0CBE3C:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0xff8
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0CBE50
  addiu $sp, $sp, -0x30
  sw    $ra, 0x2c($sp)
  sw    $s5, 0x28($sp)
  sw    $s4, 0x24($sp)
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  lh    $v0, 0x16($a0)
  move  $s4, $a0
  move  $s5, $a1
  lw    $s3, 0x18($a0)
  blez  $v0, .L7F0CBEC4
   move  $s2, $zero
  move  $s0, $zero
  move  $s1, $s3
.L7F0CBE90:
  lw    $t6, ($s1)
  addu  $a0, $s0, $s3
  slti  $at, $t6, 0xbb9
  beql  $at, $zero, .L7F0CBEB4
   addiu $s2, $s2, 1
  jal   load_image_to_buffer
   move  $a1, $s5
  lh    $v0, 0x16($s4)
  addiu $s2, $s2, 1
.L7F0CBEB4:
  slt   $at, $s2, $v0
  addiu $s0, $s0, 0xc
  bnez  $at, .L7F0CBE90
   addiu $s1, $s1, 0xc
.L7F0CBEC4:
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
glabel calls_load_image_to_buffer
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a0, 0x1c($sp)
  jal   load_image_to_buffer
   addiu $a0, $sp, 0x1c
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");
