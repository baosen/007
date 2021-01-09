package main

import (
	"fmt"
	"os"
)

// fatal prints an error message to the user and exits the program.
func fatal(format string, s ...interface{}) {
	if len(s) <= 0 {
		fmt.Fprintf(os.Stderr, "error: "+format)
		os.Exit(1)
	}
	fmt.Fprintf(os.Stderr, "error: "+format, s)
	os.Exit(1)
}
