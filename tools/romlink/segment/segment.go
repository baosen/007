package segment

import (
	"fmt"
	"os"
	"path/filepath"
	"text/template"
)

const rootPath = "bazel-out/k8-fastbuild/bin/src" // TODO: Fix this hack.

var previousSegmentName string

// GetAbsolutePath returns the absolute path to segment file.
func GetAbsolutePath(segmentDirPath, segmentFilepath string) string {
	return fmt.Sprintf("%s/%s", filepath.Dir(segmentDirPath), segmentFilepath)
}

var romDirPath string     // contains the file path to the .rom-file.
var segmentDirPath string // contains the file path to the .segment-file.

// getSegmentFileContent formats and returns the contents of the .segment-file.
func getSegmentFileContent(pathToRomfile, segmentFilepath string) string {
	if pathToRomfile == "" {
		panic("path to romfile is empty")
	}

	romDirPath = filepath.Dir(pathToRomfile)
	segmentDirPath = filepath.Dir(segmentFilepath)

	// Parse segment file.
	parse(readSegmentFile(GetAbsolutePath(romDirPath, segmentFilepath)))
	parsingOutput := getOutput()

	return generateSegmentFileContent(romDirPath, segmentDirPath, parsingOutput)
}

func generateSegmentFileContent(romDirPath, segmentDirPath string, parsingOutput []string) string {
	var formattedSegmentFileContent string
	for _, line := range parsingOutput {
		if romDirPath == "." {
			if segmentDirPath == "." {
				formattedSegmentFileContent += fmt.Sprintf("        %s/%s;\n", rootPath, line)
				continue
			}
			formattedSegmentFileContent += fmt.Sprintf("        %s/%s/%s;\n", rootPath, segmentDirPath, line)
			continue
		}
		if segmentDirPath == "." {
			formattedSegmentFileContent += fmt.Sprintf("        %s/%s/%s;\n", rootPath, romDirPath, line)
			continue
		}
		formattedSegmentFileContent += fmt.Sprintf("        %s/%s/%s/%s;\n", rootPath, romDirPath, segmentDirPath, line)
		continue
	}
	return formattedSegmentFileContent
}

func GetPreviousSegmentName() string {
	return previousSegmentName
}

// PrintSegment prints the segment-portion of the .ld-file.
func PrintSegment(pathToRomfile, address, pathToSegmentFile string, subalign, compressed bool) {
	segmentName := getSegmentName(filepath.Base(pathToSegmentFile))
	segment := segment{
		Address:             address,
		Name:                segmentName,
		Objects:             getSegmentFileContent(pathToRomfile, pathToSegmentFile),
		PreviousSegmentName: GetPreviousSegmentName(),
		Subalign:            subalign,
		Compressed:          compressed,
	}
	tmpl, err := template.New("segment").Parse(segmentBlock)
	if err != nil {
		panic(err)
	}
	err = tmpl.Execute(os.Stdout, segment)
	if err != nil {
		panic(err)
	}
	previousSegmentName = segmentName
}
