.section .romfiles, "a"

.global _jfontdlSegmentStart
_jfontdlSegmentStart:
    .incbin "jfont_dl.bin"
.global _jfontdlSegmentEnd
_jfontdlSegmentEnd:

.global _jfontcharSegmentStart
_jfontcharSegmentStart:
.ifdef VERSION_US
    .incbin "usa.jfont_chardata.bin"
.endif
.ifdef VERSION_JP
    .incbin "japan.jfont_chardata.bin"
.endif

.global _efontchar
_efontchar:
    .incbin "efont_chardata.bin"

.global _animation_table
_animation_table:
    .incbin "animationtable_entries.bin"

.global _animation_data
_animation_data:
    .incbin "animationtable_data.bin"
