package segment

import (
	"fmt"
	"io/ioutil"
	"os"
	"path/filepath"
)

func readSegmentFile(shortenedFilePath string) string {
	realFilePath := fmt.Sprintf(
		"%s/%s.segment",
		filepath.Dir(shortenedFilePath),
		getSegmentName(filepath.Base(shortenedFilePath)),
	)
	segmentFile, err := os.Open(realFilePath)
	if err != nil {
		panic(err)
	}
	byteSlice, err := ioutil.ReadAll(segmentFile)
	if err != nil {
		panic(err)
	}
	return string(byteSlice)
}
