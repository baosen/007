package segment

import "testing"

func TestSegmentParsingImport(t *testing.T) {
	Parse("import game/obseg")
}

func TestSegmentParsingObject(t *testing.T) {
	Parse("obseg.o (.text)")
}
