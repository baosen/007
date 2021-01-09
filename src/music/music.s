.section .music

.global _sfxctl
_sfxctl:
 .incbin "sfx.ctl"

.global _sfxtbl
_sfxtbl:
 .incbin "sfx.tbl"

.global _instrumentsctl
_instrumentsctl:
 .incbin "instruments.ctl"

.global _instrumentstbl
_instrumentstbl:
 .incbin "instruments.tbl"

.global _musicsampletbl
_musicsampletbl:
.global number_music_samples
number_music_samples:
 .half (table_music_data_end - number_music_samples)/8
 .half 0

.macro music_table_entry name
 .word \name - number_music_samples
 .half end_d_\name - d_\name
 .half end_\name - \name
.endm

music_table_entry no_music
music_table_entry solo_death_abrev
music_table_entry intro_eye
music_table_entry train
music_table_entry depot
music_table_entry jungle_unused
music_table_entry citadel
music_table_entry facility
music_table_entry control
music_table_entry dam
music_table_entry frigate
music_table_entry archives
music_table_entry silo
music_table_entry jungle_perimeter_unused
music_table_entry streets
music_table_entry bunker1
music_table_entry bunker2
music_table_entry statue
music_table_entry elevator_control
music_table_entry cradle
music_table_entry null1
music_table_entry elevator_wc
music_table_entry egyptian
music_table_entry folders
music_table_entry watchmusic
music_table_entry aztec
music_table_entry watercaverns
music_table_entry deathsolo
music_table_entry surface2
music_table_entry trainx
music_table_entry null2
music_table_entry facilityx
music_table_entry depotx
music_table_entry controlx
music_table_entry watercavernsx
music_table_entry damx
music_table_entry frigatex
music_table_entry archivesx
music_table_entry silox
music_table_entry null3
music_table_entry streetsx
music_table_entry bunker1x
music_table_entry bunker2x
music_table_entry junglex
music_table_entry nint_rare_logo
music_table_entry statuex
music_table_entry aztecx
music_table_entry egyptianx
music_table_entry cradlex
music_table_entry cuba
music_table_entry runway
music_table_entry runway_plane
music_table_entry surface2x
music_table_entry windblowing
music_table_entry multideath_alt
music_table_entry jungle
music_table_entry runwayx
music_table_entry surface1
music_table_entry multiplayerdeath
music_table_entry surface1x
music_table_entry surface2_ending
music_table_entry statue_ending
music_table_entry frigate_outro
table_music_data_end:

.macro music_file name
  .section .musiccompressed
  .global \name
  \name:
  .ifdef VERSION_US
    .incbin "\name\.rz"
  .endif
  .ifdef VERSION_JP
    .incbin "\name\.rz"
  .endif
  .ifdef VERSION_EU
    .incbin "\name\.rz"
  .endif
  end_\name:

  .section .musicdecompressed
  d_\name:
    .incbin "\name\.bin"
  end_d_\name:
.endm

# music_fileA is used for the entries that end with A....the A doesn't seem to be from compression.
.macro music_fileA name
  .section .musiccompressed
  .global \name
  \name:
  .ifdef VERSION_US
    .incbin "\name\.rz"
  .endif
  .ifdef VERSION_JP
    .incbin "\name\.rz"
  .endif
  .ifdef VERSION_EU
    .incbin "\name\.rz"
  .endif
    .byte 0xA
  end_\name:

  .section .musicdecompressed
  d_\name:
    .incbin "\name\.bin"
  end_d_\name:
.endm

music_file no_music
music_fileA solo_death_abrev
music_file intro_eye
music_fileA train
music_fileA depot
music_file jungle_unused
music_fileA citadel
music_file facility
music_file control
music_fileA dam
music_file frigate
music_file archives
music_file silo
music_fileA jungle_perimeter_unused
music_fileA streets
music_fileA bunker1
music_fileA bunker2
music_file statue
music_fileA elevator_control
music_fileA cradle
music_fileA null1
music_fileA elevator_wc
music_file egyptian
music_file folders
music_fileA watchmusic
music_file aztec
music_fileA watercaverns
music_fileA deathsolo
music_fileA surface2
music_fileA trainx
music_fileA null2
music_file facilityx
music_file depotx
music_file controlx
music_file watercavernsx
music_fileA damx
music_file frigatex
music_fileA archivesx
music_file silox
music_fileA null3
music_file streetsx
music_file bunker1x
music_fileA bunker2x
music_fileA junglex
music_file nint_rare_logo
music_fileA statuex
music_file aztecx
music_file egyptianx
music_fileA cradlex
music_fileA cuba
music_file runway
music_file runway_plane
music_file surface2x
music_fileA windblowing
music_file multideath_alt
music_file jungle
music_file runwayx
music_fileA surface1
music_file multiplayerdeath
music_file surface1x
music_fileA surface2_ending
music_file statue_ending
music_fileA frigate_outro

.section .musiccompressed
.half 0
.word 0
