#ifndef _ULTRA64_GBI_H_
#define _ULTRA64_GBI_H_

#ifdef F3DEX_GBI_2E
#ifndef F3DEX_GBI_2
#define F3DEX_GBI_2
#endif
#define GBI_FLOATS
#endif

#ifdef F3DEX_GBI_2
#ifndef F3DEX_GBI
#define F3DEX_GBI
#endif
#define G_NOOP 0x00
#define G_RDPHALF_2 0xf1
#define G_SETOTHERMODE_H 0xe3
#define G_SETOTHERMODE_L 0xe2
#define G_RDPHALF_1 0xe1
#define G_SPNOOP 0xe0
#define G_ENDDL 0xdf
#define G_DL 0xde
#define G_LOAD_UCODE 0xdd
#define G_MOVEMEM 0xdc
#define G_MOVEWORD 0xdb
#define G_MTX 0xda
#define G_GEOMETRYMODE 0xd9
#define G_POPMTX 0xd8
#define G_TEXTURE 0xd7
#define G_DMA_IO 0xd6
#define G_SPECIAL_1 0xd5
#define G_SPECIAL_2 0xd4
#define G_SPECIAL_3 0xd3

#define G_VTX 0x01
#define G_MODIFYVTX 0x02
#define G_CULLDL 0x03
#define G_BRANCH_Z 0x04
#define G_TRI1 0x05
#define G_TRI2 0x06
#define G_QUAD 0x07
#define G_LINE3D 0x08
#else              /* F3DEX_GBI_2 */

/* DMA commands: */
#define G_SPNOOP 0 /* handle 0 gracefully */
#define G_MTX 1
#define G_RESERVED0 2 /* not implemeted */
#define G_MOVEMEM 3   /* move a block of memory (up to 4 words) to dmem */
#define G_VTX 4
#define G_RESERVED1 5 /* not implemeted */
#define G_DL 6
#define G_RESERVED2 7     /* not implemeted */
#define G_RESERVED3 8     /* not implemeted */
#define G_SPRITE2D_BASE 9 /* sprite command */

/* IMMEDIATE commands: */
#define G_IMMFIRST -65
#define G_TRI1 (G_IMMFIRST - 0)
#define G_CULLDL (G_IMMFIRST - 1)
#define G_POPMTX (G_IMMFIRST - 2)
#define G_MOVEWORD (G_IMMFIRST - 3)
#define G_TEXTURE (G_IMMFIRST - 4)
#define G_SETOTHERMODE_H (G_IMMFIRST - 5)
#define G_SETOTHERMODE_L (G_IMMFIRST - 6)
#define G_ENDDL (G_IMMFIRST - 7)
#define G_SETGEOMETRYMODE (G_IMMFIRST - 8)
#define G_CLEARGEOMETRYMODE (G_IMMFIRST - 9)
#define G_LINE3D (G_IMMFIRST - 10)
#define G_RDPHALF_1 (G_IMMFIRST - 11)
#define G_RDPHALF_2 (G_IMMFIRST - 12)
#if (defined(F3DEX_GBI) || defined(F3DLP_GBI))
#define G_MODIFYVTX (G_IMMFIRST - 13)
#define G_TRI2 (G_IMMFIRST - 14)
#define G_BRANCH_Z (G_IMMFIRST - 15)
#define G_LOAD_UCODE (G_IMMFIRST - 16)
#else
#define G_RDPHALF_CONT (G_IMMFIRST - 13)
#endif

/* We are overloading 2 of the immediate commands
   to keep the byte alignment of dmem the same */

#define G_SPRITE2D_SCALEFLIP (G_IMMFIRST - 1)
#define G_SPRITE2D_DRAW (G_IMMFIRST - 2)

/* RDP commands: */
#define G_NOOP 0xc0 /*   0 */

#endif /* F3DEX_GBI_2 */

/* RDP commands: */
#define G_SETCIMG 0xff         /*  -1 */
#define G_SETZIMG 0xfe         /*  -2 */
#define G_SETTIMG 0xfd         /*  -3 */
#define G_SETCOMBINE 0xfc      /*  -4 */
#define G_SETENVCOLOR 0xfb     /*  -5 */
#define G_SETPRIMCOLOR 0xfa    /*  -6 */
#define G_SETBLENDCOLOR 0xf9   /*  -7 */
#define G_SETFOGCOLOR 0xf8     /*  -8 */
#define G_SETFILLCOLOR 0xf7    /*  -9 */
#define G_FILLRECT 0xf6        /* -10 */
#define G_SETTILE 0xf5         /* -11 */
#define G_LOADTILE 0xf4        /* -12 */
#define G_LOADBLOCK 0xf3       /* -13 */
#define G_SETTILESIZE 0xf2     /* -14 */
#define G_LOADTLUT 0xf0        /* -16 */
#define G_RDPSETOTHERMODE 0xef /* -17 */
#define G_SETPRIMDEPTH 0xee    /* -18 */
#define G_SETSCISSOR 0xed      /* -19 */
#define G_SETCONVERT 0xec      /* -20 */
#define G_SETKEYR 0xeb         /* -21 */
#define G_SETKEYGB 0xea        /* -22 */
#define G_RDPFULLSYNC 0xe9     /* -23 */
#define G_RDPTILESYNC 0xe8     /* -24 */
#define G_RDPPIPESYNC 0xe7     /* -25 */
#define G_RDPLOADSYNC 0xe6     /* -26 */
#define G_TEXRECTFLIP 0xe5     /* -27 */
#define G_TEXRECT 0xe4         /* -28 */

/*
 * The following commands are the "generated" RDP commands; the user
 * never sees them, the RSP microcode generates them.
 *
 * The layout of the bits is magical, to save work in the ucode.
 * These id's are -56, -52, -54, -50, -55, -51, -53, -49, ...
 *                                 edge, shade, texture, zbuff bits:  estz
 */
#define G_TRI_FILL 0xc8             /* fill triangle:            11001000 */
#define G_TRI_SHADE 0xcc            /* shade triangle:           11001100 */
#define G_TRI_TXTR 0xca             /* texture triangle:         11001010 */
#define G_TRI_SHADE_TXTR 0xce       /* shade, texture triangle:  11001110 */
#define G_TRI_FILL_ZBUFF 0xc9       /* fill, zbuff triangle:     11001001 */
#define G_TRI_SHADE_ZBUFF 0xcd      /* shade, zbuff triangle:    11001101 */
#define G_TRI_TXTR_ZBUFF 0xcb       /* texture, zbuff triangle:  11001011 */
#define G_TRI_SHADE_TXTR_ZBUFF 0xcf /* shade, txtr, zbuff trngl: 11001111 */

/*
 * A TRI_FILL triangle is just the edges. You need to set the DP
 * to use primcolor, in order to see anything. (it is NOT a triangle
 * that gets rendered in 'fill mode'. Triangles can't be rendered
 * in 'fill mode')
 *
 * A TRI_SHADE is a gouraud triangle that has colors interpolated.
 * Flat-shaded triangles (from the software) are still gouraud shaded,
 * it's just the colors are all the same and the deltas are 0.
 *
 * Other triangle types, and combinations are more obvious.
 */

/* masks to build RDP triangle commands: */
#define G_RDP_TRI_FILL_MASK 0x08
#define G_RDP_TRI_SHADE_MASK 0x04
#define G_RDP_TRI_TXTR_MASK 0x02
#define G_RDP_TRI_ZBUFF_MASK 0x01

/*
 * HACK:
 * This is a dreadful hack. For version 1.0 hardware, there are still
 * some 'bowtie' hangs. This parameter can be increased to avoid
 * the hangs. Every increase of 4 chops one scanline off of every
 * triangle. Values of 4,8,12 should be sufficient to avoid any
 * bowtie hang.
 *
 * Change this value, then recompile ALL of your program (including static
 * display lists!)
 *
 * THIS WILL BE REMOVED FOR HARDWARE VERSION 2.0!
 */
#define BOWTIE_VAL 0

/* gets added to RDP command, in order to test for addres fixup: */
#define G_RDP_ADDR_FIXUP 3 /* |RDP cmds| <= this, do addr fixup */
#ifdef _LANGUAGE_ASSEMBLY
#define G_RDP_TEXRECT_CHECK ((-1 * G_TEXRECTFLIP) & 0xff)
#endif

/* macros for command parsing: */
#define GDMACMD(x) (x)
#define GIMMCMD(x) (G_IMMFIRST - (x))
#define GRDPCMD(x) (0xff - (x))

#define G_DMACMDSIZ 128
#define G_IMMCMDSIZ 64
#define G_RDPCMDSIZ 64

/*
 * Coordinate shift values, number of bits of fraction
 */
#define G_TEXTURE_IMAGE_FRAC 2
#define G_TEXTURE_SCALE_FRAC 16
#define G_SCALE_FRAC 8
#define G_ROTATE_FRAC 16

/*
 * Parameters to graphics commands
 */

/*
 * Data packing macros
 */

/*
 * Maximum z-buffer value, used to initialize the z-buffer.
 * Note : this number is NOT the viewport z-scale constant.
 * See the comment next to G_MAXZ for more info.
 */
#define G_MAXFBZ 0x3fff /* 3b exp, 11b mantissa */

#define GPACK_RGBA5551(r, g, b, a)                                             \
  ((((r) << 8) & 0xf800) | (((g) << 3) & 0x7c0) | (((b) >> 2) & 0x3e) |        \
   ((a)&0x1))
#define GPACK_ZDZ(z, dz) ((z) << 2 | (dz))

/*
 * G_MTX: parameter flags
 */
#ifdef F3DEX_GBI_2
#define G_MTX_MODELVIEW 0x00 /* matrix types */
#define G_MTX_PROJECTION 0x04
#define G_MTX_MUL 0x00 /* concat or load */
#define G_MTX_LOAD 0x02
#define G_MTX_NOPUSH 0x00 /* push or not */
#define G_MTX_PUSH 0x01
#else                        /* F3DEX_GBI_2 */
#define G_MTX_MODELVIEW 0x00 /* matrix types */
#define G_MTX_PROJECTION 0x01
#define G_MTX_MUL 0x00 /* concat or load */
#define G_MTX_LOAD 0x02
#define G_MTX_NOPUSH 0x00 /* push or not */
#define G_MTX_PUSH 0x04
#endif /* F3DEX_GBI_2 */

/*
 * flags for G_SETGEOMETRYMODE
 * (this rendering state is maintained in RSP)
 *
 * DO NOT USE THE LOW 8 BITS OF GEOMETRYMODE:
 * The weird bit-ordering is for the micro-code: the lower byte
 * can be OR'd in with G_TRI_SHADE (11001100) to construct
 * the triangle command directly. Don't break it...
 *
 * DO NOT USE THE HIGH 8 BITS OF GEOMETRYMODE:
 * The high byte is OR'd with 0x703 to form the clip code mask.
 * If it is set to 0x04, this will cause near clipping to occur.
 * If it is zero, near clipping will not occur.
 *
 * Further explanation:
 * G_SHADE is necessary in order to see the color that you passed
 * down with the vertex. If G_SHADE isn't set, you need to set the DP
 * appropriately and use primcolor to see anything.
 *
 * G_SHADING_SMOOTH enabled means use all 3 colors of the triangle.
 * If it is not set, then do 'flat shading', where only one vertex color
 * is used (and all 3 vertices are set to that same color by the ucode)
 * See the man page for gSP1Triangle().
 *
 */
#define G_ZBUFFER 0x00000001
#define G_SHADE 0x00000004 /* enable Gouraud interp */
/* rest of low byte reserved for setup ucode */
#ifdef F3DEX_GBI_2
#define G_TEXTURE_ENABLE 0x00000000 /* Ignored               */
#define G_SHADING_SMOOTH 0x00200000 /* flat or smooth shaded */
#define G_CULL_FRONT 0x00000200
#define G_CULL_BACK 0x00000400
#define G_CULL_BOTH 0x00000600 /* To make code cleaner */
#else
#define G_TEXTURE_ENABLE 0x00000002 /* Microcode use only */
#define G_SHADING_SMOOTH 0x00000200 /* flat or smooth shaded */
#define G_CULL_FRONT 0x00001000
#define G_CULL_BACK 0x00002000
#define G_CULL_BOTH 0x00003000 /* To make code cleaner */
#endif
#define G_FOG 0x00010000
#define G_LIGHTING 0x00020000
#define G_TEXTURE_GEN 0x00040000
#define G_TEXTURE_GEN_LINEAR 0x00080000
#define G_LOD 0x00100000 /* NOT IMPLEMENTED */
#if (defined(F3DEX_GBI) || defined(F3DLP_GBI))
#define G_CLIPPING 0x00800000
#else
#define G_CLIPPING 0x00000000
#endif

#ifdef _LANGUAGE_ASSEMBLY
#define G_FOG_H (G_FOG / 0x10000)
#define G_LIGHTING_H (G_LIGHTING / 0x10000)
#define G_TEXTURE_GEN_H (G_TEXTURE_GEN / 0x10000)
#define G_TEXTURE_GEN_LINEAR_H (G_TEXTURE_GEN_LINEAR / 0x10000)
#define G_LOD_H (G_LOD / 0x10000) /* NOT IMPLEMENTED */
#if (defined(F3DEX_GBI) || defined(F3DLP_GBI))
#define G_CLIPPING_H (G_CLIPPING / 0x10000)
#endif
#endif

/* Need these defined for Sprite Microcode */
#ifdef _LANGUAGE_ASSEMBLY
#define G_TX_LOADTILE 7
#define G_TX_RENDERTILE 0

#define G_TX_NOMIRROR 0
#define G_TX_WRAP 0
#define G_TX_MIRROR 0x1
#define G_TX_CLAMP 0x2
#define G_TX_NOMASK 0
#define G_TX_NOLOD 0
#endif

/*
 * G_SETIMG fmt: set image formats
 */
#define G_IM_FMT_RGBA 0
#define G_IM_FMT_YUV 1
#define G_IM_FMT_CI 2
#define G_IM_FMT_IA 3
#define G_IM_FMT_I 4

/*
 * G_SETIMG siz: set image pixel size
 */
#define G_IM_SIZ_4b 0
#define G_IM_SIZ_8b 1
#define G_IM_SIZ_16b 2
#define G_IM_SIZ_32b 3
#define G_IM_SIZ_DD 5

#define G_IM_SIZ_4b_BYTES 0
#define G_IM_SIZ_4b_TILE_BYTES G_IM_SIZ_4b_BYTES
#define G_IM_SIZ_4b_LINE_BYTES G_IM_SIZ_4b_BYTES

#define G_IM_SIZ_8b_BYTES 1
#define G_IM_SIZ_8b_TILE_BYTES G_IM_SIZ_8b_BYTES
#define G_IM_SIZ_8b_LINE_BYTES G_IM_SIZ_8b_BYTES

#define G_IM_SIZ_16b_BYTES 2
#define G_IM_SIZ_16b_TILE_BYTES G_IM_SIZ_16b_BYTES
#define G_IM_SIZ_16b_LINE_BYTES G_IM_SIZ_16b_BYTES

#define G_IM_SIZ_32b_BYTES 4
#define G_IM_SIZ_32b_TILE_BYTES 2
#define G_IM_SIZ_32b_LINE_BYTES 2

#define G_IM_SIZ_4b_LOAD_BLOCK G_IM_SIZ_16b
#define G_IM_SIZ_8b_LOAD_BLOCK G_IM_SIZ_16b
#define G_IM_SIZ_16b_LOAD_BLOCK G_IM_SIZ_16b
#define G_IM_SIZ_32b_LOAD_BLOCK G_IM_SIZ_32b

#define G_IM_SIZ_4b_SHIFT 2
#define G_IM_SIZ_8b_SHIFT 1
#define G_IM_SIZ_16b_SHIFT 0
#define G_IM_SIZ_32b_SHIFT 0

#define G_IM_SIZ_4b_INCR 3
#define G_IM_SIZ_8b_INCR 1
#define G_IM_SIZ_16b_INCR 0
#define G_IM_SIZ_32b_INCR 0

/*
 * G_SETCOMBINE: color combine modes
 */
/* Color combiner constants: */
#define G_CCMUX_COMBINED 0
#define G_CCMUX_TEXEL0 1
#define G_CCMUX_TEXEL1 2
#define G_CCMUX_PRIMITIVE 3
#define G_CCMUX_SHADE 4
#define G_CCMUX_ENVIRONMENT 5
#define G_CCMUX_CENTER 6
#define G_CCMUX_SCALE 6
#define G_CCMUX_COMBINED_ALPHA 7
#define G_CCMUX_TEXEL0_ALPHA 8
#define G_CCMUX_TEXEL1_ALPHA 9
#define G_CCMUX_PRIMITIVE_ALPHA 10
#define G_CCMUX_SHADE_ALPHA 11
#define G_CCMUX_ENV_ALPHA 12
#define G_CCMUX_LOD_FRACTION 13
#define G_CCMUX_PRIM_LOD_FRAC 14
#define G_CCMUX_NOISE 7
#define G_CCMUX_K4 7
#define G_CCMUX_K5 15
#define G_CCMUX_1 6
#define G_CCMUX_0 31

/* Alpha combiner constants: */
#define G_ACMUX_COMBINED 0
#define G_ACMUX_TEXEL0 1
#define G_ACMUX_TEXEL1 2
#define G_ACMUX_PRIMITIVE 3
#define G_ACMUX_SHADE 4
#define G_ACMUX_ENVIRONMENT 5
#define G_ACMUX_LOD_FRACTION 0
#define G_ACMUX_PRIM_LOD_FRAC 6
#define G_ACMUX_1 6
#define G_ACMUX_0 7

/* typical CC cycle 1 modes */
#define G_CC_PRIMITIVE 0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE
#define G_CC_SHADE 0, 0, 0, SHADE, 0, 0, 0, SHADE

#define G_CC_MODULATEI TEXEL0, 0, SHADE, 0, 0, 0, 0, SHADE
#define G_CC_MODULATEIDECALA TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0
#define G_CC_MODULATEIFADE TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT

#define G_CC_MODULATERGB G_CC_MODULATEI
#define G_CC_MODULATERGBDECALA G_CC_MODULATEIDECALA
#define G_CC_MODULATERGBFADE G_CC_MODULATEIFADE

#define G_CC_MODULATEIA TEXEL0, 0, SHADE, 0, TEXEL0, 0, SHADE, 0
#define G_CC_MODULATEIFADEA TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0

#define G_CC_MODULATEFADE TEXEL0, 0, SHADE, 0, ENVIRONMENT, 0, TEXEL0, 0

#define G_CC_MODULATERGBA G_CC_MODULATEIA
#define G_CC_MODULATERGBFADEA G_CC_MODULATEIFADEA

#define G_CC_MODULATEI_PRIM TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE
#define G_CC_MODULATEIA_PRIM TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0
#define G_CC_MODULATEIDECALA_PRIM TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0

#define G_CC_MODULATERGB_PRIM G_CC_MODULATEI_PRIM
#define G_CC_MODULATERGBA_PRIM G_CC_MODULATEIA_PRIM
#define G_CC_MODULATERGBDECALA_PRIM G_CC_MODULATEIDECALA_PRIM

#define G_CC_FADE SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0
#define G_CC_FADEA TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0

#define G_CC_DECALRGB 0, 0, 0, TEXEL0, 0, 0, 0, SHADE
#define G_CC_DECALRGBA 0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0
#define G_CC_DECALFADE 0, 0, 0, TEXEL0, 0, 0, 0, ENVIRONMENT

#define G_CC_DECALFADEA 0, 0, 0, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0

#define G_CC_BLENDI ENVIRONMENT, SHADE, TEXEL0, SHADE, 0, 0, 0, SHADE
#define G_CC_BLENDIA ENVIRONMENT, SHADE, TEXEL0, SHADE, TEXEL0, 0, SHADE, 0
#define G_CC_BLENDIDECALA ENVIRONMENT, SHADE, TEXEL0, SHADE, 0, 0, 0, TEXEL0

#define G_CC_BLENDRGBA TEXEL0, SHADE, TEXEL0_ALPHA, SHADE, 0, 0, 0, SHADE
#define G_CC_BLENDRGBDECALA TEXEL0, SHADE, TEXEL0_ALPHA, SHADE, 0, 0, 0, TEXEL0
#define G_CC_BLENDRGBFADEA                                                     \
  TEXEL0, SHADE, TEXEL0_ALPHA, SHADE, 0, 0, 0, ENVIRONMENT

#define G_CC_ADDRGB TEXEL0, 0, TEXEL0, SHADE, 0, 0, 0, SHADE
#define G_CC_ADDRGBDECALA TEXEL0, 0, TEXEL0, SHADE, 0, 0, 0, TEXEL0
#define G_CC_ADDRGBFADE TEXEL0, 0, TEXEL0, SHADE, 0, 0, 0, ENVIRONMENT

#define G_CC_REFLECTRGB ENVIRONMENT, 0, TEXEL0, SHADE, 0, 0, 0, SHADE
#define G_CC_REFLECTRGBDECALA ENVIRONMENT, 0, TEXEL0, SHADE, 0, 0, 0, TEXEL0

#define G_CC_HILITERGB PRIMITIVE, SHADE, TEXEL0, SHADE, 0, 0, 0, SHADE
#define G_CC_HILITERGBA                                                        \
  PRIMITIVE, SHADE, TEXEL0, SHADE, PRIMITIVE, SHADE, TEXEL0, SHADE
#define G_CC_HILITERGBDECALA PRIMITIVE, SHADE, TEXEL0, SHADE, 0, 0, 0, TEXEL0

#define G_CC_SHADEDECALA 0, 0, 0, SHADE, 0, 0, 0, TEXEL0
#define G_CC_SHADEFADEA 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT

#define G_CC_BLENDPE                                                           \
  PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, SHADE, 0
#define G_CC_BLENDPEDECALA                                                     \
  PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, TEXEL0

/* oddball modes */
#define _G_CC_BLENDPE                                                          \
  ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, TEXEL0, 0, SHADE, 0
#define _G_CC_BLENDPEDECALA                                                    \
  ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, 0, 0, 0, TEXEL0
#define _G_CC_TWOCOLORTEX PRIMITIVE, SHADE, TEXEL0, SHADE, 0, 0, 0, SHADE
/* used for 1-cycle sparse mip-maps, primitive color has color of lowest LOD */
#define _G_CC_SPARSEST                                                         \
  PRIMITIVE, TEXEL0, LOD_FRACTION, TEXEL0, PRIMITIVE, TEXEL0, LOD_FRACTION,    \
      TEXEL0
#define G_CC_TEMPLERP                                                          \
  TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0, TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0

/* typical CC cycle 1 modes, usually followed by other cycle 2 modes */
#define G_CC_TRILERP                                                           \
  TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0
#define G_CC_INTERFERENCE TEXEL0, 0, TEXEL1, 0, TEXEL0, 0, TEXEL1, 0

/*
 *  One-cycle color convert operation
 */
#define G_CC_1CYUV2RGB TEXEL0, K4, K5, TEXEL0, 0, 0, 0, SHADE

/*
 *  NOTE: YUV2RGB expects TF step1 color conversion to occur in 2nd clock.
 * Therefore, CC looks for step1 results in TEXEL1
 */
#define G_CC_YUV2RGB TEXEL1, K4, K5, TEXEL1, 0, 0, 0, 0

/* typical CC cycle 2 modes */
#define G_CC_PASS2 0, 0, 0, COMBINED, 0, 0, 0, COMBINED
#define G_CC_MODULATEI2 COMBINED, 0, SHADE, 0, 0, 0, 0, SHADE
#define G_CC_MODULATEIA2 COMBINED, 0, SHADE, 0, COMBINED, 0, SHADE, 0
#define G_CC_MODULATERGB2 G_CC_MODULATEI2
#define G_CC_MODULATERGBA2 G_CC_MODULATEIA2
#define G_CC_MODULATEI_PRIM2 COMBINED, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE
#define G_CC_MODULATEIA_PRIM2                                                  \
  COMBINED, 0, PRIMITIVE, 0, COMBINED, 0, PRIMITIVE, 0
#define G_CC_MODULATERGB_PRIM2 G_CC_MODULATEI_PRIM2
#define G_CC_MODULATERGBA_PRIM2 G_CC_MODULATEIA_PRIM2
#define G_CC_DECALRGB2 0, 0, 0, COMBINED, 0, 0, 0, SHADE
/*
 * ?
#define	G_CC_DECALRGBA2		COMBINED, SHADE, COMBINED_ALPHA, SHADE, 0, 0, 0,
SHADE
*/
#define G_CC_BLENDI2 ENVIRONMENT, SHADE, COMBINED, SHADE, 0, 0, 0, SHADE
#define G_CC_BLENDIA2 ENVIRONMENT, SHADE, COMBINED, SHADE, COMBINED, 0, SHADE, 0
#define G_CC_CHROMA_KEY2 TEXEL0, CENTER, SCALE, 0, 0, 0, 0, 0
#define G_CC_HILITERGB2 ENVIRONMENT, COMBINED, TEXEL0, COMBINED, 0, 0, 0, SHADE
#define G_CC_HILITERGBA2                                                       \
  ENVIRONMENT, COMBINED, TEXEL0, COMBINED, ENVIRONMENT, COMBINED, TEXEL0,      \
      COMBINED
#define G_CC_HILITERGBDECALA2                                                  \
  ENVIRONMENT, COMBINED, TEXEL0, COMBINED, 0, 0, 0, TEXEL0
#define G_CC_HILITERGBPASSA2                                                   \
  ENVIRONMENT, COMBINED, TEXEL0, COMBINED, 0, 0, 0, COMBINED

/*
 * G_SETOTHERMODE_L sft: shift count
 */
#define G_MDSFT_ALPHACOMPARE 0
#define G_MDSFT_ZSRCSEL 2
#define G_MDSFT_RENDERMODE 3
#define G_MDSFT_BLENDER 16

/*
 * G_SETOTHERMODE_H sft: shift count
 */
#define G_MDSFT_BLENDMASK 0 /* unsupported */
#define G_MDSFT_ALPHADITHER 4
#define G_MDSFT_RGBDITHER 6

#define G_MDSFT_COMBKEY 8
#define G_MDSFT_TEXTCONV 9
#define G_MDSFT_TEXTFILT 12
#define G_MDSFT_TEXTLUT 14
#define G_MDSFT_TEXTLOD 16
#define G_MDSFT_TEXTDETAIL 17
#define G_MDSFT_TEXTPERSP 19
#define G_MDSFT_CYCLETYPE 20
#define G_MDSFT_COLORDITHER 22 /* unsupported in HW 2.0 */
#define G_MDSFT_PIPELINE 23

/* G_SETOTHERMODE_H gPipelineMode */
#define G_PM_1PRIMITIVE (1 << G_MDSFT_PIPELINE)
#define G_PM_NPRIMITIVE (0 << G_MDSFT_PIPELINE)

/* G_SETOTHERMODE_H gSetCycleType */
#define G_CYC_1CYCLE (0 << G_MDSFT_CYCLETYPE)
#define G_CYC_2CYCLE (1 << G_MDSFT_CYCLETYPE)
#define G_CYC_COPY (2 << G_MDSFT_CYCLETYPE)
#define G_CYC_FILL (3 << G_MDSFT_CYCLETYPE)

/* G_SETOTHERMODE_H gSetTexturePersp */
#define G_TP_NONE (0 << G_MDSFT_TEXTPERSP)
#define G_TP_PERSP (1 << G_MDSFT_TEXTPERSP)

/* G_SETOTHERMODE_H gSetTextureDetail */
#define G_TD_CLAMP (0 << G_MDSFT_TEXTDETAIL)
#define G_TD_SHARPEN (1 << G_MDSFT_TEXTDETAIL)
#define G_TD_DETAIL (2 << G_MDSFT_TEXTDETAIL)

/* G_SETOTHERMODE_H gSetTextureLOD */
#define G_TL_TILE (0 << G_MDSFT_TEXTLOD)
#define G_TL_LOD (1 << G_MDSFT_TEXTLOD)

/* G_SETOTHERMODE_H gSetTextureLUT */
#define G_TT_NONE (0 << G_MDSFT_TEXTLUT)
#define G_TT_RGBA16 (2 << G_MDSFT_TEXTLUT)
#define G_TT_IA16 (3 << G_MDSFT_TEXTLUT)

/* G_SETOTHERMODE_H gSetTextureFilter */
#define G_TF_POINT (0 << G_MDSFT_TEXTFILT)
#define G_TF_AVERAGE (3 << G_MDSFT_TEXTFILT)
#define G_TF_BILERP (2 << G_MDSFT_TEXTFILT)

/* G_SETOTHERMODE_H gSetTextureConvert */
#define G_TC_CONV (0 << G_MDSFT_TEXTCONV)
#define G_TC_FILTCONV (5 << G_MDSFT_TEXTCONV)
#define G_TC_FILT (6 << G_MDSFT_TEXTCONV)

/* G_SETOTHERMODE_H gSetCombineKey */
#define G_CK_NONE (0 << G_MDSFT_COMBKEY)
#define G_CK_KEY (1 << G_MDSFT_COMBKEY)

/* G_SETOTHERMODE_H gSetColorDither */
#define G_CD_MAGICSQ (0 << G_MDSFT_RGBDITHER)
#define G_CD_BAYER (1 << G_MDSFT_RGBDITHER)
#define G_CD_NOISE (2 << G_MDSFT_RGBDITHER)

#ifndef _HW_VERSION_1
#define G_CD_DISABLE (3 << G_MDSFT_RGBDITHER)
#define G_CD_ENABLE G_CD_NOISE /* HW 1.0 compatibility mode */
#else
#define G_CD_ENABLE (1 << G_MDSFT_COLORDITHER)
#define G_CD_DISABLE (0 << G_MDSFT_COLORDITHER)
#endif

/* G_SETOTHERMODE_H gSetAlphaDither */
#define G_AD_PATTERN (0 << G_MDSFT_ALPHADITHER)
#define G_AD_NOTPATTERN (1 << G_MDSFT_ALPHADITHER)
#define G_AD_NOISE (2 << G_MDSFT_ALPHADITHER)
#define G_AD_DISABLE (3 << G_MDSFT_ALPHADITHER)

/* G_SETOTHERMODE_L gSetAlphaCompare */
#define G_AC_NONE (0 << G_MDSFT_ALPHACOMPARE)
#define G_AC_THRESHOLD (1 << G_MDSFT_ALPHACOMPARE)
#define G_AC_DITHER (3 << G_MDSFT_ALPHACOMPARE)

/* G_SETOTHERMODE_L gSetDepthSource */
#define G_ZS_PIXEL (0 << G_MDSFT_ZSRCSEL)
#define G_ZS_PRIM (1 << G_MDSFT_ZSRCSEL)

/* G_SETOTHERMODE_L gSetRenderMode */
#define AA_EN 0x8
#define Z_CMP 0x10
#define Z_UPD 0x20
#define IM_RD 0x40
#define CLR_ON_CVG 0x80
#define CVG_DST_CLAMP 0
#define CVG_DST_WRAP 0x100
#define CVG_DST_FULL 0x200
#define CVG_DST_SAVE 0x300
#define ZMODE_OPA 0
#define ZMODE_INTER 0x400
#define ZMODE_XLU 0x800
#define ZMODE_DEC 0xc00
#define CVG_X_ALPHA 0x1000
#define ALPHA_CVG_SEL 0x2000
#define FORCE_BL 0x4000
#define TEX_EDGE 0x0000 /* used to be 0x8000 */

#define G_BL_CLR_IN 0
#define G_BL_CLR_MEM 1
#define G_BL_CLR_BL 2
#define G_BL_CLR_FOG 3
#define G_BL_1MA 0
#define G_BL_A_MEM 1
#define G_BL_A_IN 0
#define G_BL_A_FOG 1
#define G_BL_A_SHADE 2
#define G_BL_1 2
#define G_BL_0 3

#define GBL_c1(m1a, m1b, m2a, m2b)                                             \
  (m1a) << 30 | (m1b) << 26 | (m2a) << 22 | (m2b) << 18
#define GBL_c2(m1a, m1b, m2a, m2b)                                             \
  (m1a) << 28 | (m1b) << 24 | (m2a) << 20 | (m2b) << 16

#define RM_AA_ZB_OPA_SURF(clk)                                                 \
  AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | ALPHA_CVG_SEL |  \
      GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)

#define RM_RA_ZB_OPA_SURF(clk)                                                 \
  AA_EN | Z_CMP | Z_UPD | CVG_DST_CLAMP | ZMODE_OPA | ALPHA_CVG_SEL |          \
      GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)

#define RM_AA_ZB_XLU_SURF(clk)                                                 \
  AA_EN | Z_CMP | IM_RD | CVG_DST_WRAP | CLR_ON_CVG | FORCE_BL | ZMODE_XLU |   \
      GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)

#define RM_AA_ZB_OPA_DECAL(clk)                                                \
  AA_EN | Z_CMP | IM_RD | CVG_DST_WRAP | ALPHA_CVG_SEL | ZMODE_DEC |           \
      GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)

#define RM_RA_ZB_OPA_DECAL(clk)                                                \
  AA_EN | Z_CMP | CVG_DST_WRAP | ALPHA_CVG_SEL | ZMODE_DEC |                   \
      GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)

#define RM_AA_ZB_XLU_DECAL(clk)                                                \
  AA_EN | Z_CMP | IM_RD | CVG_DST_WRAP | CLR_ON_CVG | FORCE_BL | ZMODE_DEC |   \
      GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)

#define RM_AA_ZB_OPA_INTER(clk)                                                \
  AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | ALPHA_CVG_SEL |              \
      ZMODE_INTER |                                                            \
      GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)

#define RM_RA_ZB_OPA_INTER(clk)                                                \
  AA_EN | Z_CMP | Z_UPD | CVG_DST_CLAMP | ALPHA_CVG_SEL | ZMODE_INTER |        \
      GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)

#define RM_AA_ZB_XLU_INTER(clk)                                                \
  AA_EN | Z_CMP | IM_RD | CVG_DST_WRAP | CLR_ON_CVG | FORCE_BL | ZMODE_INTER | \
      GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)

#define RM_AA_ZB_XLU_LINE(clk)                                                 \
  AA_EN | Z_CMP | IM_RD | CVG_DST_CLAMP | CVG_X_ALPHA | ALPHA_CVG_SEL |        \
      FORCE_BL | ZMODE_XLU |                                                   \
      GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)

#define RM_AA_ZB_DEC_LINE(clk)                                                 \
  AA_EN | Z_CMP | IM_RD | CVG_DST_SAVE | CVG_X_ALPHA | ALPHA_CVG_SEL |         \
      FORCE_BL | ZMODE_DEC |                                                   \
      GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)

#define RM_AA_ZB_TEX_EDGE(clk)                                                 \
  AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | CVG_X_ALPHA |                \
      ALPHA_CVG_SEL | ZMODE_OPA | TEX_EDGE |                                   \
      GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)

#define RM_AA_ZB_TEX_INTER(clk)                                                \
  AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | CVG_X_ALPHA |                \
      ALPHA_CVG_SEL | ZMODE_INTER | TEX_EDGE |                                 \
      GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)

#define RM_AA_ZB_SUB_SURF(clk)                                                 \
  AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_FULL | ZMODE_OPA | ALPHA_CVG_SEL |   \
      GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)

#define RM_AA_ZB_PCL_SURF(clk)                                                 \
  AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | G_AC_DITHER |    \
      GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)

#define RM_AA_ZB_OPA_TERR(clk)                                                 \
  AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | ALPHA_CVG_SEL |  \
      GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)

#define RM_AA_ZB_TEX_TERR(clk)                                                 \
  AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | CVG_X_ALPHA |                \
      ALPHA_CVG_SEL | ZMODE_OPA | TEX_EDGE |                                   \
      GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)

#define RM_AA_ZB_SUB_TERR(clk)                                                 \
  AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_FULL | ZMODE_OPA | ALPHA_CVG_SEL |   \
      GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)

#define RM_AA_OPA_SURF(clk)                                                    \
  AA_EN | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | ALPHA_CVG_SEL |                  \
      GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)

#define RM_RA_OPA_SURF(clk)                                                    \
  AA_EN | CVG_DST_CLAMP | ZMODE_OPA | ALPHA_CVG_SEL |                          \
      GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)

#define RM_AA_XLU_SURF(clk)                                                    \
  AA_EN | IM_RD | CVG_DST_WRAP | CLR_ON_CVG | FORCE_BL | ZMODE_OPA |           \
      GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)

#define RM_AA_XLU_LINE(clk)                                                    \
  AA_EN | IM_RD | CVG_DST_CLAMP | CVG_X_ALPHA | ALPHA_CVG_SEL | FORCE_BL |     \
      ZMODE_OPA | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)

#define RM_AA_DEC_LINE(clk)                                                    \
  AA_EN | IM_RD | CVG_DST_FULL | CVG_X_ALPHA | ALPHA_CVG_SEL | FORCE_BL |      \
      ZMODE_OPA | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)

#define RM_AA_TEX_EDGE(clk)                                                    \
  AA_EN | IM_RD | CVG_DST_CLAMP | CVG_X_ALPHA | ALPHA_CVG_SEL | ZMODE_OPA |    \
      TEX_EDGE | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)

#define RM_AA_SUB_SURF(clk)                                                    \
  AA_EN | IM_RD | CVG_DST_FULL | ZMODE_OPA | ALPHA_CVG_SEL |                   \
      GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)

#define RM_AA_PCL_SURF(clk)                                                    \
  AA_EN | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | G_AC_DITHER |                    \
      GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)

#define RM_AA_OPA_TERR(clk)                                                    \
  AA_EN | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | ALPHA_CVG_SEL |                  \
      GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)

#define RM_AA_TEX_TERR(clk)                                                    \
  AA_EN | IM_RD | CVG_DST_CLAMP | CVG_X_ALPHA | ALPHA_CVG_SEL | ZMODE_OPA |    \
      TEX_EDGE | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)

#define RM_AA_SUB_TERR(clk)                                                    \
  AA_EN | IM_RD | CVG_DST_FULL | ZMODE_OPA | ALPHA_CVG_SEL |                   \
      GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)

#define RM_ZB_OPA_SURF(clk)                                                    \
  Z_CMP | Z_UPD | CVG_DST_FULL | ALPHA_CVG_SEL | ZMODE_OPA |                   \
      GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)

#define RM_ZB_XLU_SURF(clk)                                                    \
  Z_CMP | IM_RD | CVG_DST_FULL | FORCE_BL | ZMODE_XLU |                        \
      GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)

#define RM_ZB_OPA_DECAL(clk)                                                   \
  Z_CMP | CVG_DST_FULL | ALPHA_CVG_SEL | ZMODE_DEC |                           \
      GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)

#define RM_ZB_XLU_DECAL(clk)                                                   \
  Z_CMP | IM_RD | CVG_DST_FULL | FORCE_BL | ZMODE_DEC |                        \
      GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)

#define RM_ZB_CLD_SURF(clk)                                                    \
  Z_CMP | IM_RD | CVG_DST_SAVE | FORCE_BL | ZMODE_XLU |                        \
      GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)

#define RM_ZB_OVL_SURF(clk)                                                    \
  Z_CMP | IM_RD | CVG_DST_SAVE | FORCE_BL | ZMODE_DEC |                        \
      GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)

#define RM_ZB_PCL_SURF(clk)                                                    \
  Z_CMP | Z_UPD | CVG_DST_FULL | ZMODE_OPA | G_AC_DITHER |                     \
      GBL_c##clk(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1)

#define RM_OPA_SURF(clk)                                                       \
  CVG_DST_CLAMP | FORCE_BL | ZMODE_OPA |                                       \
      GBL_c##clk(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1)

#define RM_XLU_SURF(clk)                                                       \
  IM_RD | CVG_DST_FULL | FORCE_BL | ZMODE_OPA |                                \
      GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)

#define RM_TEX_EDGE(clk)                                                       \
  CVG_DST_CLAMP | CVG_X_ALPHA | ALPHA_CVG_SEL | FORCE_BL | ZMODE_OPA |         \
      TEX_EDGE | AA_EN | GBL_c##clk(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1)

#define RM_CLD_SURF(clk)                                                       \
  IM_RD | CVG_DST_SAVE | FORCE_BL | ZMODE_OPA |                                \
      GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)

#define RM_PCL_SURF(clk)                                                       \
  CVG_DST_FULL | FORCE_BL | ZMODE_OPA | G_AC_DITHER |                          \
      GBL_c##clk(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1)

#define RM_ADD(clk)                                                            \
  IM_RD | CVG_DST_SAVE | FORCE_BL | ZMODE_OPA |                                \
      GBL_c##clk(G_BL_CLR_IN, G_BL_A_FOG, G_BL_CLR_MEM, G_BL_1)

#define RM_NOOP(clk) GBL_c##clk(0, 0, 0, 0)

#define RM_VISCVG(clk)                                                         \
  IM_RD | FORCE_BL | GBL_c##clk(G_BL_CLR_IN, G_BL_0, G_BL_CLR_BL, G_BL_A_MEM)

/* for rendering to an 8-bit framebuffer */
#define RM_OPA_CI(clk)                                                         \
  CVG_DST_CLAMP | ZMODE_OPA |                                                  \
      GBL_c##clk(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1)

/* Custom version of RM_AA_ZB_XLU_SURF with Z_UPD */
#define RM_CUSTOM_AA_ZB_XLU_SURF(clk) RM_AA_ZB_XLU_SURF(clk) | Z_UPD

#define G_RM_AA_ZB_OPA_SURF RM_AA_ZB_OPA_SURF(1)
#define G_RM_AA_ZB_OPA_SURF2 RM_AA_ZB_OPA_SURF(2)
#define G_RM_AA_ZB_XLU_SURF RM_AA_ZB_XLU_SURF(1)
#define G_RM_AA_ZB_XLU_SURF2 RM_AA_ZB_XLU_SURF(2)
#define G_RM_AA_ZB_OPA_DECAL RM_AA_ZB_OPA_DECAL(1)
#define G_RM_AA_ZB_OPA_DECAL2 RM_AA_ZB_OPA_DECAL(2)
#define G_RM_AA_ZB_XLU_DECAL RM_AA_ZB_XLU_DECAL(1)
#define G_RM_AA_ZB_XLU_DECAL2 RM_AA_ZB_XLU_DECAL(2)
#define G_RM_AA_ZB_OPA_INTER RM_AA_ZB_OPA_INTER(1)
#define G_RM_AA_ZB_OPA_INTER2 RM_AA_ZB_OPA_INTER(2)
#define G_RM_AA_ZB_XLU_INTER RM_AA_ZB_XLU_INTER(1)
#define G_RM_AA_ZB_XLU_INTER2 RM_AA_ZB_XLU_INTER(2)
#define G_RM_AA_ZB_XLU_LINE RM_AA_ZB_XLU_LINE(1)
#define G_RM_AA_ZB_XLU_LINE2 RM_AA_ZB_XLU_LINE(2)
#define G_RM_AA_ZB_DEC_LINE RM_AA_ZB_DEC_LINE(1)
#define G_RM_AA_ZB_DEC_LINE2 RM_AA_ZB_DEC_LINE(2)
#define G_RM_AA_ZB_TEX_EDGE RM_AA_ZB_TEX_EDGE(1)
#define G_RM_AA_ZB_TEX_EDGE2 RM_AA_ZB_TEX_EDGE(2)
#define G_RM_AA_ZB_TEX_INTER RM_AA_ZB_TEX_INTER(1)
#define G_RM_AA_ZB_TEX_INTER2 RM_AA_ZB_TEX_INTER(2)
#define G_RM_AA_ZB_SUB_SURF RM_AA_ZB_SUB_SURF(1)
#define G_RM_AA_ZB_SUB_SURF2 RM_AA_ZB_SUB_SURF(2)
#define G_RM_AA_ZB_PCL_SURF RM_AA_ZB_PCL_SURF(1)
#define G_RM_AA_ZB_PCL_SURF2 RM_AA_ZB_PCL_SURF(2)
#define G_RM_AA_ZB_OPA_TERR RM_AA_ZB_OPA_TERR(1)
#define G_RM_AA_ZB_OPA_TERR2 RM_AA_ZB_OPA_TERR(2)
#define G_RM_AA_ZB_TEX_TERR RM_AA_ZB_TEX_TERR(1)
#define G_RM_AA_ZB_TEX_TERR2 RM_AA_ZB_TEX_TERR(2)
#define G_RM_AA_ZB_SUB_TERR RM_AA_ZB_SUB_TERR(1)
#define G_RM_AA_ZB_SUB_TERR2 RM_AA_ZB_SUB_TERR(2)

#define G_RM_RA_ZB_OPA_SURF RM_RA_ZB_OPA_SURF(1)
#define G_RM_RA_ZB_OPA_SURF2 RM_RA_ZB_OPA_SURF(2)
#define G_RM_RA_ZB_OPA_DECAL RM_RA_ZB_OPA_DECAL(1)
#define G_RM_RA_ZB_OPA_DECAL2 RM_RA_ZB_OPA_DECAL(2)
#define G_RM_RA_ZB_OPA_INTER RM_RA_ZB_OPA_INTER(1)
#define G_RM_RA_ZB_OPA_INTER2 RM_RA_ZB_OPA_INTER(2)

#define G_RM_AA_OPA_SURF RM_AA_OPA_SURF(1)
#define G_RM_AA_OPA_SURF2 RM_AA_OPA_SURF(2)
#define G_RM_AA_XLU_SURF RM_AA_XLU_SURF(1)
#define G_RM_AA_XLU_SURF2 RM_AA_XLU_SURF(2)
#define G_RM_AA_XLU_LINE RM_AA_XLU_LINE(1)
#define G_RM_AA_XLU_LINE2 RM_AA_XLU_LINE(2)
#define G_RM_AA_DEC_LINE RM_AA_DEC_LINE(1)
#define G_RM_AA_DEC_LINE2 RM_AA_DEC_LINE(2)
#define G_RM_AA_TEX_EDGE RM_AA_TEX_EDGE(1)
#define G_RM_AA_TEX_EDGE2 RM_AA_TEX_EDGE(2)
#define G_RM_AA_SUB_SURF RM_AA_SUB_SURF(1)
#define G_RM_AA_SUB_SURF2 RM_AA_SUB_SURF(2)
#define G_RM_AA_PCL_SURF RM_AA_PCL_SURF(1)
#define G_RM_AA_PCL_SURF2 RM_AA_PCL_SURF(2)
#define G_RM_AA_OPA_TERR RM_AA_OPA_TERR(1)
#define G_RM_AA_OPA_TERR2 RM_AA_OPA_TERR(2)
#define G_RM_AA_TEX_TERR RM_AA_TEX_TERR(1)
#define G_RM_AA_TEX_TERR2 RM_AA_TEX_TERR(2)
#define G_RM_AA_SUB_TERR RM_AA_SUB_TERR(1)
#define G_RM_AA_SUB_TERR2 RM_AA_SUB_TERR(2)

#define G_RM_RA_OPA_SURF RM_RA_OPA_SURF(1)
#define G_RM_RA_OPA_SURF2 RM_RA_OPA_SURF(2)

#define G_RM_ZB_OPA_SURF RM_ZB_OPA_SURF(1)
#define G_RM_ZB_OPA_SURF2 RM_ZB_OPA_SURF(2)
#define G_RM_ZB_XLU_SURF RM_ZB_XLU_SURF(1)
#define G_RM_ZB_XLU_SURF2 RM_ZB_XLU_SURF(2)
#define G_RM_ZB_OPA_DECAL RM_ZB_OPA_DECAL(1)
#define G_RM_ZB_OPA_DECAL2 RM_ZB_OPA_DECAL(2)
#define G_RM_ZB_XLU_DECAL RM_ZB_XLU_DECAL(1)
#define G_RM_ZB_XLU_DECAL2 RM_ZB_XLU_DECAL(2)
#define G_RM_ZB_CLD_SURF RM_ZB_CLD_SURF(1)
#define G_RM_ZB_CLD_SURF2 RM_ZB_CLD_SURF(2)
#define G_RM_ZB_OVL_SURF RM_ZB_OVL_SURF(1)
#define G_RM_ZB_OVL_SURF2 RM_ZB_OVL_SURF(2)
#define G_RM_ZB_PCL_SURF RM_ZB_PCL_SURF(1)
#define G_RM_ZB_PCL_SURF2 RM_ZB_PCL_SURF(2)

#define G_RM_OPA_SURF RM_OPA_SURF(1)
#define G_RM_OPA_SURF2 RM_OPA_SURF(2)
#define G_RM_XLU_SURF RM_XLU_SURF(1)
#define G_RM_XLU_SURF2 RM_XLU_SURF(2)
#define G_RM_CLD_SURF RM_CLD_SURF(1)
#define G_RM_CLD_SURF2 RM_CLD_SURF(2)
#define G_RM_TEX_EDGE RM_TEX_EDGE(1)
#define G_RM_TEX_EDGE2 RM_TEX_EDGE(2)
#define G_RM_PCL_SURF RM_PCL_SURF(1)
#define G_RM_PCL_SURF2 RM_PCL_SURF(2)
#define G_RM_ADD RM_ADD(1)
#define G_RM_ADD2 RM_ADD(2)
#define G_RM_NOOP RM_NOOP(1)
#define G_RM_NOOP2 RM_NOOP(2)
#define G_RM_VISCVG RM_VISCVG(1)
#define G_RM_VISCVG2 RM_VISCVG(2)
#define G_RM_OPA_CI RM_OPA_CI(1)
#define G_RM_OPA_CI2 RM_OPA_CI(2)

#define G_RM_CUSTOM_AA_ZB_XLU_SURF RM_CUSTOM_AA_ZB_XLU_SURF(1)
#define G_RM_CUSTOM_AA_ZB_XLU_SURF2 RM_CUSTOM_AA_ZB_XLU_SURF(2)

#define G_RM_FOG_SHADE_A                                                       \
  GBL_c1(G_BL_CLR_FOG, G_BL_A_SHADE, G_BL_CLR_IN, G_BL_1MA)
#define G_RM_FOG_PRIM_A GBL_c1(G_BL_CLR_FOG, G_BL_A_FOG, G_BL_CLR_IN, G_BL_1MA)
#define G_RM_PASS GBL_c1(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1)

/*
 * G_SETCONVERT: K0-5
 */
#define G_CV_K0 175
#define G_CV_K1 -43
#define G_CV_K2 -89
#define G_CV_K3 222
#define G_CV_K4 114
#define G_CV_K5 42

/*
 * G_SETSCISSOR: interlace mode
 */
#define G_SC_NON_INTERLACE 0
#define G_SC_ODD_INTERLACE 3
#define G_SC_EVEN_INTERLACE 2

/* flags to inhibit pushing of the display list (on branch) */
#define G_DL_PUSH 0x00
#define G_DL_NOPUSH 0x01

/* Vertex (set up for use with colors) */
typedef struct {
  short ob[3]; /* x, y, z */
  unsigned short flag;
  short tc[2];         /* texture coord */
  unsigned char cn[4]; /* color & alpha */
} Vtx_t;

/* Vertex (set up for use with normals) */
typedef struct {
  short ob[3]; /* x, y, z */
  unsigned short flag;
  short tc[2];      /* texture coord */
  signed char n[3]; /* normal */
  unsigned char a;  /* alpha  */
} Vtx_tn;

typedef union {
  Vtx_t v;  /* Use this one for colors  */
  Vtx_tn n; /* Use this one for normals */
  long long int force_structure_alignment;
} Vtx;

typedef struct {
  short vscale[4]; /* scale, 2 bits fraction */
  short vtrans[4]; /* translate, 2 bits fraction */
} Vp_t;

typedef union {
  Vp_t vp;
  long long int force_structure_alignment;
} Vp;

typedef struct {
  unsigned int w0, w1;
} Gwords;

/* TODO: fill in the rest of the members */
typedef union {
  Gwords words;
  long long int force_structure_alignment;
} Gfx;

#define _SHIFTL(value, shift, size)                                            \
  ((unsigned int)(((unsigned int)(value) & ((1 << size) - 1)) << shift))

enum { G_OFF, G_ON };

#ifndef MAX
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#endif

#ifndef MIN
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#endif

#define gSPMatrix(pkt, m, p)                                                   \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = _SHIFTL(0x01, 24, 8) | _SHIFTL((p), 16, 8) |                \
                   _SHIFTL(sizeof(Mtx), 0, 16);                                \
    _g->words.w1 = (unsigned int)(m);                                          \
  }

#define gSPVertex(pkt, v, n, v0)                                               \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = _SHIFTL(0x04, 24, 8) |                                      \
                   _SHIFTL(((n)-1) << 4 | (v0), 16, 8) |                       \
                   _SHIFTL(sizeof(Vtx) * (n), 0, 16);                          \
    _g->words.w1 = (unsigned int)(v);                                          \
  }

#define gDPLoadSync(pkt)                                                       \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = 0xE6000000;                                                 \
    _g->words.w1 = 0x00000000;                                                 \
  }

#define gDPPipeSync(pkt)                                                       \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = 0xE7000000;                                                 \
    _g->words.w1 = 0x00000000;                                                 \
  }

#define gDPTileSync(pkt)                                                       \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = 0xE8000000;                                                 \
    _g->words.w1 = 0x00000000;                                                 \
  }

#define gDPFullSync(pkt)                                                       \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = 0xE9000000;                                                 \
    _g->words.w1 = 0x00000000;                                                 \
  }

#define gSPDisplayList(pkt, dl)                                                \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = 0x06000000;                                                 \
    _g->words.w1 = (unsigned int)(dl);                                         \
  }

#define gSPBranchList(pkt, dl)                                                 \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = 0x06010000;                                                 \
    _g->words.w1 = (unsigned int)(dl);                                         \
  }

#define gSPEndDisplayList(pkt)                                                 \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = 0xB8000000;                                                 \
    _g->words.w1 = 0x00000000;                                                 \
  }

#define gDPSetCycleType(pkt, type)                                             \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = 0xBA001402;                                                 \
    _g->words.w1 = type;                                                       \
  }

#define gDPPipelineMode(pkt, mode)                                             \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = 0xBA001701;                                                 \
    _g->words.w1 = mode;                                                       \
  }

#define gDPSetScissor(pkt, mode, ulx, uly, lrx, lry)                           \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = _SHIFTL(0xED, 24, 8) |                                      \
                   _SHIFTL((int)((float)(ulx)*4.0f), 12, 12) |                 \
                   _SHIFTL((int)((float)(uly)*4.0f), 0, 12);                   \
    _g->words.w1 = _SHIFTL((mode), 24, 8) |                                    \
                   _SHIFTL((int)((float)(lrx)*4.0f), 12, 12) |                 \
                   _SHIFTL((int)((float)(lry)*4.0f), 0, 12);                   \
  }

#define gDPSetCombine(pkt, muxs0, muxs1)                                       \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = _SHIFTL(0xFC, 24, 8) | _SHIFTL((muxs0), 0, 24);             \
    _g->words.w1 = (muxs1);                                                    \
  }

#define gDPSetTextureLOD(pkt, type)                                            \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = 0xBA001001;                                                 \
    _g->words.w1 = type;                                                       \
  }

#define gDPSetTextureLUT(pkt, type)                                            \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = 0xBA000E02;                                                 \
    _g->words.w1 = type;                                                       \
  }

#define gDPSetTextureDetail(pkt, type)                                         \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = 0xBA001102;                                                 \
    _g->words.w1 = type;                                                       \
  }

#define gDPSetTexturePersp(pkt, type)                                          \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = 0xBA001301;                                                 \
    _g->words.w1 = type;                                                       \
  }

#define gDPSetTextureFilter(pkt, type)                                         \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = 0xBA000C02;                                                 \
    _g->words.w1 = type;                                                       \
  }

#define gDPSetTextureConvert(pkt, type)                                        \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = 0xBA000903;                                                 \
    _g->words.w1 = type;                                                       \
  }

#define gDPSetCombineKey(pkt, type)                                            \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = 0xBA000801;                                                 \
    _g->words.w1 = type;                                                       \
  }

#define gDPSetColorDither(pkt, type)                                           \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = 0xBA000602;                                                 \
    _g->words.w1 = type;                                                       \
  }

#define gDPSetFillColor(pkt, color)                                            \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = 0xF7000000;                                                 \
    _g->words.w1 = color;                                                      \
  }

#define gDPFillRectangle(pkt, ulx, uly, lrx, lry)                              \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 =                                                             \
        _SHIFTL(0xF6, 24, 8) | _SHIFTL((lrx), 14, 10) | _SHIFTL((lry), 2, 10); \
    _g->words.w1 =                                                             \
        _SHIFTL(0, 24, 8) | _SHIFTL((ulx), 14, 10) | _SHIFTL((uly), 2, 10);    \
  }

#define gDPSetAlphaCompare(pkt, type)                                          \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = 0xB9000002;                                                 \
    _g->words.w1 = type;                                                       \
  }

#define gDPSetDepthSource(pkt, type)                                           \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = 0xB9000201;                                                 \
    _g->words.w1 = type;                                                       \
  }

#define gSPSetOtherMode(pkt, cmd, shift, length, data)                         \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = _SHIFTL((cmd), 24, 8) | _SHIFTL((shift), 8, 8) |            \
                   _SHIFTL(((length)-1), 0, 8);                                \
    _g->words.w1 = (data);                                                     \
  }

#define gDPSetRenderMode(pkt, mode1, mode2)                                    \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = 0xB900031D;                                                 \
    _g->words.w1 = (mode1) | (mode2);                                          \
  }

#define gSPClearGeometryMode(pkt, mode)                                        \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = 0xB6000000;                                                 \
    _g->words.w1 = mode;                                                       \
  }

#define gSPSetGeometryMode(pkt, word)                                          \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = 0xB7000000;                                                 \
    _g->words.w1 = word;                                                       \
  }

#define gSPNumLights(pkt, n)                                                   \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = 0xBC000002;                                                 \
    _g->words.w1 = (0x80000000 + ((n) + 1) * 0x20);                            \
  }

#define gSPTexture(pkt, sc, tc, level, tile, on)                               \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = _SHIFTL(0xBB, 24, 8) | _SHIFTL(0, 16, 8) |                  \
                   _SHIFTL((level), 11, 3) | _SHIFTL((tile), 8, 3) |           \
                   _SHIFTL((on), 0, 8);                                        \
    _g->words.w1 = _SHIFTL((sc), 16, 16) | _SHIFTL((tc), 0, 16);               \
  }

#define gDPSetColorImage(pkt, fmt, size, width, image)                         \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = _SHIFTL(0xFF, 24, 8) | _SHIFTL((fmt), 21, 3) |              \
                   _SHIFTL((size), 19, 2) | _SHIFTL((width)-1, 0, 12);         \
    _g->words.w1 = (image);                                                    \
  }

#define gDPSetTileSize(pkt, tile, uls, ult, lrs, lrt)                          \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 =                                                             \
        _SHIFTL(0xF2, 24, 8) | _SHIFTL(uls, 12, 12) | _SHIFTL(ult, 0, 12);     \
    _g->words.w1 =                                                             \
        _SHIFTL(tile, 24, 3) | _SHIFTL(lrs, 12, 12) | _SHIFTL(lrt, 0, 12);     \
  }

#define gDPLoadBlock(pkt, tile, uls, ult, lrs, dxt)                            \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 =                                                             \
        _SHIFTL(0xF3, 24, 8) | _SHIFTL((uls), 12, 12) | _SHIFTL((ult), 0, 12); \
    _g->words.w1 = _SHIFTL((tile), 24, 3) |                                    \
                   _SHIFTL((MIN((lrs), G_TX_LDBLK_MAX_TXL)), 12, 12) |         \
                   _SHIFTL((dxt), 0, 12);                                      \
  }

#define gDPSetTile(pkt, fmt, siz, line, tmem, tile, palette, cmt, maskt,       \
                   shiftt, cms, masks, shifts)                                 \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = _SHIFTL(0xF5, 24, 8) | _SHIFTL((fmt), 21, 3) |              \
                   _SHIFTL((siz), 19, 2) | _SHIFTL((line), 9, 9) |             \
                   _SHIFTL((tmem), 0, 9);                                      \
    _g->words.w1 = _SHIFTL((tile), 24, 3) | _SHIFTL((palette), 20, 4) |        \
                   _SHIFTL((cmt), 18, 2) | _SHIFTL((maskt), 14, 4) |           \
                   _SHIFTL((shiftt), 10, 4) | _SHIFTL((cms), 8, 2) |           \
                   _SHIFTL((masks), 4, 4) | _SHIFTL((shifts), 0, 4);           \
  }

#define gDPSetDepthImage(pkt, image)                                           \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = _SHIFTL(0xFE, 24, 8);                                       \
    _g->words.w1 = (image);                                                    \
  }

#define gDPSetPrimColor(pkt, m, l, r, g, b, a)                                 \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 =                                                             \
        _SHIFTL(G_SETPRIMCOLOR, 24, 8) | _SHIFTL(m, 8, 8) | _SHIFTL(l, 0, 8);  \
    _g->words.w1 = _SHIFTL(r, 24, 8) | _SHIFTL(g, 16, 8) | _SHIFTL(b, 8, 8) |  \
                   _SHIFTL(a, 0, 8);                                           \
  }

#define gDPSetEnvColor(pkt, r, g, b, a)                                        \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = _SHIFTL(0xFB, 24, 8);                                       \
    _g->words.w1 = _SHIFTL((r), 24, 8) | _SHIFTL((g), 16, 8) |                 \
                   _SHIFTL((b), 8, 8) | _SHIFTL((a), 0, 8);                    \
  }

#define gDPSetTextureImage(pkt, fmt, size, width, img)                         \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = _SHIFTL(0xFD, 24, 8) | _SHIFTL((fmt), 21, 3) |              \
                   _SHIFTL((size), 19, 2) | _SHIFTL((width)-1, 0, 12);         \
    _g->words.w1 = (unsigned int)(img);                                        \
  }

#define gMoveWd(pkt, index, offset, data)                                      \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = _SHIFTL(0xBC, 24, 8) | _SHIFTL((offset), 8, 16) |           \
                   _SHIFTL((index), 0, 8);                                     \
    _g->words.w1 = (unsigned int)(data);                                       \
  }

/* Matrix Operations */
#define G_MTX_MODELVIEW 0x00
#define G_MTX_PROJECTION 0x01
#define G_MTX_MUL 0x00
#define G_MTX_LOAD 0x02
#define G_MTX_NOPUSH 0x00
#define G_MTX_PUSH 0x04

#define gSPPopMatrix(pkt, n)                                                   \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = 0xBD000000;                                                 \
    _g->words.w1 = (n);                                                        \
  }

#define gSPViewport(pkt, v)                                                    \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = _SHIFTL(0x03, 24, 8) | _SHIFTL(G_MV_VIEWPORT, 16, 8) |      \
                   _SHIFTL(sizeof(Vp), 0, 16);                                 \
    _g->words.w1 = (unsigned int)(v);                                          \
  }

#define gSP1Triangle(pkt, v0, v1, v2, flag)                                    \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = _SHIFTL(0xBF, 24, 8);                                       \
    _g->words.w1 = _SHIFTL((flag), 24, 8) | _SHIFTL((v0)*10, 16, 8) |          \
                   _SHIFTL((v1)*10, 8, 8) | _SHIFTL((v2)*10, 0, 8);            \
  }

#if (defined(F3DLP_GBI) || defined(F3DEX_GBI))
/***
 ***  2 Triangles
 ***/
#define gSP2Triangles(pkt, v00, v01, v02, flag0, v10, v11, v12, flag1)         \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
                                                                               \
    _g->words.w0 =                                                             \
        (_SHIFTL(G_TRI2, 24, 8) | __gsSP1Triangle_w1f(v00, v01, v02, flag0));  \
    _g->words.w1 = __gsSP1Triangle_w1f(v10, v11, v12, flag1);                  \
  }

#define gsSP2Triangles(v00, v01, v02, flag0, v10, v11, v12, flag1)             \
  {                                                                            \
    (_SHIFTL(G_TRI2, 24, 8) | __gsSP1Triangle_w1f(v00, v01, v02, flag0)),      \
        __gsSP1Triangle_w1f(v10, v11, v12, flag1)                              \
  }

#endif /* F3DEX_GBI/F3DLP_GBI */

#if (defined(TRI4_Ext))
/***
 ***  4 Triangles - 2Tri Extension
 ***  Draws up to four triangles at a time.
 ***  Expects values from 0-F, corresponding with # points declared by vertex
 *command.
 ***  Triangles with all points set to 0 are not drawn.
 ***  Vertex Buffer reduced to 16 due to only being able to address 0-F
 ***/
#define gSP4Triangles(pkt, v00, v01, v02, v10, v11, v12, v20, v21, v22, v30,                                                  \
                      v31, v32)                                                                                               \
  {                                                                                                                           \
    Gfx *_g = (Gfx *)(pkt);                                                                                                   \
                                                                                                                              \
        _g->words.w0 = (_SHIFTL(G_TRI2, 24, 8)|				\
			_SHIFTL((v32),12,4)|_SHIFTL((v22),8,4)|_SHIFTL((v12),4,4)|_SHIFTL((v02),0,4);	\
		_g->words.w1 =  _SHIFTL((v31),28,4)|_SHIFTL((v30),24,4)|_SHIFTL((v21),20,4)|_SHIFTL((v20),16,4) \
						_SHIFTL((v11),12,4)|_SHIFTL((v10),8,4)|_SHIFTL((v02),4,4)|_SHIFTL((v00),0,4); \
  }

#define gsSP4Triangles(v00, v01, v02, flag0, v10, v11, v12, flag1)             \
  {                                                                            \
    (_SHIFTL(G_TRI2, 24, 8) | _SHIFTL((v32), 12, 4) | _SHIFTL((v22), 8, 4) |   \
     _SHIFTL((v12), 4, 4) | _SHIFTL((v02), 0, 4)),                             \
        (_SHIFTL((v31), 28, 4) | _SHIFTL((v30), 24, 4) |                       \
         _SHIFTL((v21), 20, 4) | _SHIFTL((v20), 16, 4) _SHIFTL((v11), 12, 4) | \
         _SHIFTL((v10), 8, 4) | _SHIFTL((v02), 4, 4) | _SHIFTL((v00), 0, 4));  \
  }

#endif /* TRI4_Ext*/

#define gSPTextureRectangle(pkt, xl, yl, xh, yh, tile, s, t, dsdx, dtdy)       \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 =                                                             \
        _SHIFTL(0xE4, 24, 8) | _SHIFTL((xh), 12, 12) | _SHIFTL((yh), 0, 12);   \
    _g->words.w1 =                                                             \
        _SHIFTL((tile), 24, 3) | _SHIFTL((xl), 12, 12) | _SHIFTL((yl), 0, 12); \
  }                                                                            \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = _SHIFTL(0xB3, 24, 8);                                       \
    _g->words.w1 = _SHIFTL((s), 16, 16) | _SHIFTL((t), 0, 16);                 \
  }                                                                            \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = _SHIFTL(0xB2, 24, 8);                                       \
    _g->words.w1 = _SHIFTL((dsdx), 16, 16) | _SHIFTL((dtdy), 0, 16);           \
  }

/* Lights and Light Operations */

typedef struct {
  unsigned char col[3];
  char pad1;
  unsigned char colc[3];
  char pad2;
  signed char dir[3];
  char pad3;
} Light_t;

typedef struct {
  unsigned char col[3];
  char pad1;
  unsigned char colc[3];
  char pad2;
} Ambient_t;

typedef union {
  Ambient_t l;
  long long int force_structure_alignment[1];
} Ambient;

typedef union {
  Light_t l;
  long long int force_structure_alignment[2];
} Light;

typedef struct {
  Ambient a;
  Light l[4];
} Lights4;

typedef struct {
  Light l[2];
} LookAt;

typedef struct {
  int x1, y1, x2, y2;
} Hilite_t;

typedef union {
  Hilite_t h;
  long int force_alignmnet[4];
} Hilite;

/* for gSPNumLights */
// is NUMLIGHTS_0 accurate?
#define NUMLIGHTS_0 1
enum {
  NUMLIGHTS_1 = 1,
  NUMLIGHTS_2,
  NUMLIGHTS_3,
  NUMLIGHTS_4,
  NUMLIGHTS_5,
  NUMLIGHTS_6,
  NUMLIGHTS_7
};

/* for gSPLight */
enum {
  LIGHT_1 = 1,
  LIGHT_2,
  LIGHT_3,
  LIGHT_4,
  LIGHT_5,
  LIGHT_6,
  LIGHT_7,
  LIGHT_8
};

#define gSPLight(pkt, l, n)                                                    \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = _SHIFTL(G_MOVEMEM, 24, 8) |                                 \
                   _SHIFTL(((n)-1) * 2 + G_MV_L0, 16, 8) |                     \
                   _SHIFTL(sizeof(Light), 0, 16);                              \
    _g->words.w1 = (unsigned int)(l);                                          \
  }

#define gSPLookAtX(pkt, la)                                                    \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = _SHIFTL(G_MOVEMEM, 24, 8) | _SHIFTL(G_MV_LOOKATX, 16, 8) |  \
                   _SHIFTL(sizeof(Light), 0, 16);                              \
    _g->words.w1 = (unsigned int)(la);                                         \
  }

#define gSPLookAtY(pkt, la)                                                    \
  {                                                                            \
    Gfx *_g = (Gfx *)(pkt);                                                    \
    _g->words.w0 = _SHIFTL(G_MOVEMEM, 24, 8) | _SHIFTL(G_MV_LOOKATY, 16, 8) |  \
                   _SHIFTL(sizeof(Light), 0, 16);                              \
    _g->words.w1 = (unsigned int)(la);                                         \
  }

#define gSPLookAt(pkt, la)                                                     \
  { gSPLookAtX((pkt), (la)) gSPLookAtY((pkt), (char *)(la) + 16) }

#endif
