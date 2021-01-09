package rom

import (
	"fmt"
	"strconv"

	"romlink/segment"
)

var previousAddress string

// setPreviousAddress sets the previous parsed address.
func setPreviousAddress(prevAddress string) {
	previousAddress = prevAddress
}

// computeMemoryAddress computes memory address.
func computeMemoryAddress(sign, hex string) string {
	if previousAddress == "" {
		panic("missing previous address")
	}
	a, _ := strconv.ParseInt(previousAddress, 16, 64)
	b, _ := strconv.ParseInt(hex, 16, 64)
	switch sign {
	case "+":
		return fmt.Sprintf("0x%08x", a+b)
	}
	panic("invalid relative address")
}

// computeStartMemoryAddress sets the end of the previous segment as the start address.
func computeStartMemoryAddress() string {
	return fmt.Sprintf("_%sSegmentEnd", segment.GetPreviousSegmentName())
}
