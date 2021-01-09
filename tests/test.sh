USA_ROM_SHA1=$(awk '{print $1}' tests/usa.sha1)
BUILT_USA_ROM_SHA1=`sha1sum $1 | awk '{print $1}'`

if [ "$BUILT_USA_ROM_SHA1" = "$USA_ROM_SHA1" ]; then
    exit 0
fi
exit 1
