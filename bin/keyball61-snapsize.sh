#!/bin/sh

set -eu

nobuild=0
noout=0

while getopts BO OPT ; do
  case $OPT in
    B) nobuild=1 ;;
    O) noout=1 ;;
  esac
done

targets=()
targets+=(keyball/keyball61:default)
targets+=(keyball/keyball61:test)
targets+=(keyball/keyball61:via)

if [ $nobuild -eq 0 ] ; then
  make SKIP_GIT=yes "${targets[@]}"
fi

out=$(date +tmp/snapsize/%Y%m%dT%H%M%S.log)

if [ $noout -eq 0 ] ; then
  outdir=$(dirname "$out")
  if [ ! -e "$outdir" ] ; then
    mkdir -p "$outdir"
  fi
  $(dirname "$0")/hexsize.sh keyball_keyball61_*.hex | tee "$out"
else
  $(dirname "$0")/hexsize.sh keyball_keyball61_*.hex
fi
