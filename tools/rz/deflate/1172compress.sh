#!/bin/bash
set -e

# Write header.
echo -ne \\x11\\x72 >&1

# Deflate using an old version of gzip from 1993.
thisdir=$(dirname $0)
./tools/rz/deflate/gzip --no-name --best <&0 | tail --bytes=+11 | head --bytes=-8 >&1
