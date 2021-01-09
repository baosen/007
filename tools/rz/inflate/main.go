package main

import (
	"bytes"
	"compress/flate"
	"encoding/json"
	"fmt"
	"io"
	"io/ioutil"
	"os"
)

type segment struct {
	Compressed bool   `json:"compressed"`
	Files      []file `json:"files"`
}

// file consist of the offset, length and name of a data file inside the ROM-file.
type file struct {
	Offset int64  `json:"offset"` // rom offset.
	Length int    `json:"length"` // length of file in bytes.
	Name   string `json:"name"`   // file name.
}

func printUsage() {
	fmt.Printf("Usage: %s <game rom in .z64> <data file offsets in json> <output directory>\n", os.Args[0])
	os.Exit(1)
}

func die(err error) {
	fmt.Fprintf(os.Stderr, "Error: %v\n", err)
	os.Exit(1)
}

func openROM() *os.File {
	romFile, err := os.Open(os.Args[1])
	if err != nil {
		die(err)
	}
	return romFile
}

// decompress decompresses (inflate) binary stream compressed using DEFLATE.
func decompress(b []byte) (io.ReadCloser, error) {
	// Check if the binary byte stream contains the header that indicates it is from GoldenEye 007 and deflated using DEFLATE (RFC 1951).
	if b[0] == 0x11 && b[1] == 0x72 {
		return flate.NewReader(bytes.NewBuffer(b[2:])), nil // Skip the first two header bytes.
	}
	return nil, fmt.Errorf("error: invalid format")
}

func readDataJSONFile() segment {
	dataOffsetJSONFile, err := os.Open(os.Args[2])
	if err != nil {
		die(err)
	}
	jsonBytes, err := ioutil.ReadAll(dataOffsetJSONFile)
	if err != nil {
		die(err)
	}
	var segmentFromJSON segment
	if err := json.Unmarshal(jsonBytes, &segmentFromJSON); err != nil {
		die(err)
	}
	return segmentFromJSON
}

func main() {
	if len(os.Args) < 3 {
		printUsage()
	}
	romFile := openROM()

	outputDirectory := os.Args[3]
	segment := readDataJSONFile()
	for _, file := range segment.Files {
		b := make([]byte, file.Length)
		n, err := romFile.ReadAt(b, file.Offset)
		if err != nil {
			die(err)
		}
		if n != file.Length {
			die(fmt.Errorf("%v", n))
		}
		outputFile, err := os.Create(fmt.Sprintf("%s/%s", outputDirectory, file.Name))
		if err != nil {
			die(err)
		}

		// Is segment compressed.
		if segment.Compressed {
			uncompressedBytes, err := decompress(b)
			if err != nil {
				die(err)
			}
			_, err = io.Copy(outputFile, uncompressedBytes)
			if err != nil {
				die(err)
			}
		} else { // not compressed.
			written, err := outputFile.Write(b)
			if err != nil {
				die(err)
			}
			if written != len(b) {
				die(err)
			}
		}
		if err := outputFile.Close(); err != nil {
			die(err)
		}
	}
	if err := romFile.Close(); err != nil {
		die(err)
	}
}
