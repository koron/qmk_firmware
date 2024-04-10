#!/bin/sh

set -eu

cp -Rp ../keyball/qmk_firmware/keyboards/keyball keyboards/
find keyboards/keyball -type f -regex '.*\.\(c\|h\|json\|md\)' | xargs dos2unix -q
