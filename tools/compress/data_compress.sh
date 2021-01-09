#!/bin/bash
set -e

#MAPFILE="./src/"$2".map"
MAPFILE=$2

# Extract data segment.
DATASEG_START=$(printf "%d\n" 0x$(grep ${MAPFILE} -e '__csegtempPos =' | cut -d "x" -f3))
DATASEG_LEN=$(printf "%d\n" 0x$(grep ${MAPFILE} -e 'load address 0x0000000000c00000' | cut -d "x" -f3 | cut -d " " -f1))
dd skip=${DATASEG_START} count=${DATASEG_LEN} if=$1 of=data_seg bs=1 status=none

# Truncate $1 to 0x$(printf "%x\n" ${DATASEG_START})"
head --bytes=${DATASEG_START} < $1 > $1.tmp

# Compress data segment.
tools/rz/deflate/1172compress.sh < data_seg > data_seg.rz

# Inject compressed data segment.
CDATA_POS=$(printf "%d\n" 0x$(grep  ${MAPFILE} -e 'c_data_array' | cut -d "x" -f 2 | cut -d " " -f 1 ))
dd if=data_seg.rz of=$1.tmp obs=1 seek=${CDATA_POS} conv=notrunc status=none
rm data_seg data_seg.rz

mv $1.tmp $3
