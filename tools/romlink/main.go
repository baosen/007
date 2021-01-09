package main

import (
	"io/ioutil"
	"os"

	"romlink/rom"
)

// romlink generates a GNU linker .ld-file from a .rom and .segment romlink file.
// It is used to generate the linker script for GNU linker editor to link together the rom.
func main() {
	if len(os.Args) <= 1 {
		fatal("missing argument that specifies the path to .rom-file\n")
	}
	pathToRomfile := os.Args[1]
	rom.SetPathToRomfile(pathToRomfile)
	romlinkFile, err := os.Open(pathToRomfile)
	if err != nil {
		fatal("failed to open: %s", pathToRomfile)
	}

	b, err := ioutil.ReadAll(romlinkFile)
	if err != nil {
		fatal("failed to read the contents of: %s", pathToRomfile)
	}
	compileRomlinkInput(string(b))
}
