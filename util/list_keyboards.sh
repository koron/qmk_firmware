#!/bin/sh
# Temporary shell script to find keyboards
#
# This allows us to include DEFAULT_FOLDER targets.

while getopts f OPT ; do
  case $OPT in
    f) force=1 ;;
  esac
done

if [ x"$force" != "x1" -a -e .keyboards_cache ] ; then
	cat .keyboards_cache
	exit 0
fi

find -L keyboards -type f -name rules.mk | grep -v keymaps | sed 's!keyboards/\(.*\)/rules.mk!\1!'
