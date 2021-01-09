#!/bin/bash

# C Compiler for GoldenEye 007.

thisdir=$(dirname $0)

# $1: include directories.
# $2: input files.
# $3: output file.
# $4: country code.
INCLUDE_DIRECTORIES="-I $thisdir/include $1"
INPUT_FILES=$2
OUTPUT_FILE=$3
COUNTRY_CODE=$4

if [ "$COUNTRY_CODE" = "usa" ]; then
    export LCDEFS="-DVERSION_US"
    export ASMDEFS="--defsym VERSION_US=1"
elif [ "$COUNTRY_CODE" = "japan" ]; then
    export LCDEFS="-DVERSION_JP"
    export ASMDEFS="--defsym VERSION_JP=1"
fi

TOOLCHAIN="mips-linux-gnu-"
ASSEMBLER="${TOOLCHAIN}as"
ASSEMBLER_FLAGS="-march=vr4300 -mabi=32 $ASMDEFS $INCLUDE_DIRECTORIES"

ASSEMBLY_PREPROCESSOR="python3 $thisdir/asmpreproc/asm-processor.py"
IRIX_C_COMPILER="$thisdir/irix/cc"
COMPILER_FLAGS="-Wo,-loopunroll,0 -Wab,-r4300_mul -non_shared -G 0 -Xcpluscomm -woff 568,709,712,797,807,819,820,852,821,838,893 -signed -mips2 $LCDEFS $INCLUDE_DIRECTORIES"
OPTIMIZATION_FLAGS="-O2" # used by GoldenEye 007.

$ASSEMBLY_PREPROCESSOR $OPTIMIZATION_FLAGS $INPUT_FILES | $IRIX_C_COMPILER $COMPILER_FLAGS $OPTIMIZATION_FLAGS -c $thisdir/asmpreproc/include-stdin.c -o $OUTPUT_FILE
$ASSEMBLY_PREPROCESSOR $OPTIMIZATION_FLAGS $INPUT_FILES --post-process $OUTPUT_FILE --assembler "$ASSEMBLER $ASSEMBLER_FLAGS" --asm-prelude $thisdir/asmpreproc/prelude.s
