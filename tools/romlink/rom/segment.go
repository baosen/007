package rom

import "romlink/segment"

var pathToRomfile string

func SetPathToRomfile(path string) {
	pathToRomfile = path
}

func printSegment(s1, s2 string, subalign, compressed bool) {
	segment.PrintSegment(pathToRomfile, s1, s2, subalign, compressed)
}
