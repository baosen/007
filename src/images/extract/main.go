package main

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"os"
)

// file consist of the offset and length of a image-file inside the ROM-file.
type file struct {
	Offset int64 `json:"offset"` // rom offset.
	Length int   `json:"length"` // length of file in bytes.
}

func main() {
	pathToRomFile := os.Args[1]
	romFile, err := os.Open(pathToRomFile)
	if err != nil {
		panic(err)
	}

	outputDir := os.Args[2]
	if _, err := os.Stat(outputDir); os.IsNotExist(err) {
		if err := os.Mkdir(outputDir, os.ModePerm); err != nil {
			panic(err)
		}
	}

	// Read JSON-file.
	pathToJsonFile := os.Args[3]
	jsonFile, err := os.Open(pathToJsonFile)
	if err != nil {
		panic(err)
	}
	jsonBytes, err := ioutil.ReadAll(jsonFile)
	if err != nil {
		panic(err)
	}
	var files []file
	if err := json.Unmarshal(jsonBytes, &files); err != nil {
		panic(err)
	}

	imageExterns, err := os.Create(outputDir + "/image_externs.h")
	if err != nil {
		panic(err)
	}
	imageSegment, err := os.Create(outputDir + "/images.segment")
	if err != nil {
		panic(err)
	}
	for i, image := range files {
		number := i + 1

		// Write image size to .h.
		fmt.Fprintf(imageExterns, "#define _image%d_size %d\n", number, image.Length)

		// Write image.segment.
		fmt.Fprintf(imageSegment, "%d.o (.data)\n", number)

		// Write image.bin file.
		b := make([]byte, image.Length)
		n, err := romFile.ReadAt(b, image.Offset)
		if err != nil {
			panic(err)
		}
		if n != image.Length {
			panic(n)
		}
		imageFile, err := os.Create(fmt.Sprintf("%s/%d.bin", outputDir, number))
		if err != nil {
			panic(err)
		}
		written, err := imageFile.Write(b)
		if err != nil {
			panic(err)
		}
		if written != len(b) {
			panic(err)
		}
		if err := imageFile.Close(); err != nil {
			panic(err)
		}
	}
	if err := imageExterns.Close(); err != nil {
		panic(err)
	}
	if err := romFile.Close(); err != nil {
		panic(err)
	}
}
