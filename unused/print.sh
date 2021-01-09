#!/bin/bash
set -e

PATH_TO_US_BASE_ROM="roms/usa.z64"

while IFS=, read -r offset size name compressed extract
do
    if [ "$extract" != "1" ]; then
        echo "$offset,$size,$name,$compressed,$extract" >> unused.csv
        #if [ "$compressed" == "1" ]; then
        #    echo "$offset,$size,$name,$compressed,$extract" >> compressed.csv
        #else
        #    echo "$offset,$size,$name,$compressed,$extract" >> uncompressed.csv
        #fi
    #else
        #echo "$offset,$size,$name,$compressed,$extract" >> unused.csv
    fi
done < filelist.u.csv
