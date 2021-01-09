package segment

import (
	"path/filepath"
	"strings"
)

func getSegmentName(filename string) string {
	return strings.TrimSuffix(filename, filepath.Ext(filename))
}
