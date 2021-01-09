#!/bin/bash
PATH_TO_BASE_JAPAN_ROM="roms/japan.z64"
true="1"
mkdir -p \
    assets \
    assets/font \
    assets/images \
    assets/images/split \
    assets/music \
    assets/ramrom \
    assets/obseg \
    assets/obseg/bg \
    assets/obseg/brief \
    assets/obseg/chr \
    assets/obseg/gun \
    assets/obseg/prop \
    assets/obseg/setup \
    assets/obseg/setup/japan \
    assets/obseg/stan \
    assets/obseg/text \
    assets/obseg/text/japan

deflate_compressed_file() {
    dd bs=1 skip=$offset count=$size if=$PATH_TO_BASE_JAPAN_ROM status=none | ./tools/rarezip/rarezip decompress > $name.bin
}

go build -o ./tools/rarezip/rarezip ./tools/rarezip/main.go

echo "Processing Files"
while IFS=, read -r offset size name compressed extract
do
    if [ "$extract" == "$true" ]; then
        if [ "$compressed" == "$true" ]; then
            echo "Extracting compressed $name, $size bytes..."
            deflate_compressed_file
            echo "Successfully decompressed $name"
        else
            echo "Extracting uncompressed $name, $size bytes..."
            dd bs=1 skip=$offset count=$size if=$PATH_TO_BASE_JAPAN_ROM of=$name status=none
            echo "Successfully extracted $name"
        fi
    else
        echo "skip $name"
    fi
done < filediff.j.csv
#filediff.j.csv should follow pattern of:
#offset,size,name,compressed,extract
#formatting matters, no comments, no extra lines, unix line endings only
#and always end with a newline
