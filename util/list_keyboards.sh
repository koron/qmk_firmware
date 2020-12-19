#!/bin/sh
# Temporary shell script to find keyboards
#
# This allows us to exclude keyboards by including a .noci file.

if [ -e .keyboards_cache ] ; then
	cat .keyboards_cache
	exit 0
fi

find -L keyboards -type f -name rules.mk | grep -v keymaps | sed 's!keyboards/\(.*\)/rules.mk!\1!' | while read keyboard; do
	[ "$1" = "noci" -a -e "keyboards/${keyboard}/.noci" ] || echo "$keyboard"
done
