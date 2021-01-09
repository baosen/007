package main

import "fmt"

// Print MIPS .ld-header.
func printHeader() {
	fmt.Print(`OUTPUT_ARCH (mips)

SECTIONS {
    _RomSegmentEnd = 0;
`)
}

const discardBlock = `
    /DISCARD/ : {
        * (.MIPS.abiflags);
        * (.musicdecompressed);
        * (.options);
        * (.gnu.attributes);
        * (.pdr);
        * (.mdebug);
        * (.gptab.bss);
        * (.gptab.data);
        * (.reginfo);
    }
`

// Print end of output of .ld.
func printEnd() {
	fmt.Print(discardBlock)
	fmt.Println("}")
}
