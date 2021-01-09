.section .data

.byte  0x80, 0x37, 0x12, 0x40 # PI BSD Domain 1 register

.word  0x0000000F # clock rate setting

# This is where the PIF Boot ROM jumps to when finished running.
.word  0x80000400 # entry point

.word  0x00001447 # release

# Used by the IPL boot code to verify that the ROM has not been tampered with at boot.
# Can be calculated by n64cksum.
.word  0xDCBC50D1 # checksum1
.word  0x09FD1AA3 # checksum2

.word  0x00000000 # unknown
.word  0x00000000 # unknown

# ROM name:
.ascii "GOLDENEYE           " # fixed 20 bytes.

.word  0x00000000 # unknown

.word  0x0000004E # cartridge
.ascii "GE"       # cartridge ID
.ifdef VERSION_US
    .ascii "E"        # country
.endif
.ifdef VERSION_JP
    .ascii "J"        # country
.endif
.ifdef VERSION_EU
    .ascii "P"        # country
.endif

.byte  0x00       # version
