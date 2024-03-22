#!/bin/sh

set -u

keyboards=()
keyboards+=(keyball39)
keyboards+=(keyball44)
keyboards+=(keyball46)
keyboards+=(keyball61)
keyboards+=(one47)

keymaps=()
keymaps+=(test)
keymaps+=(default)
keymaps+=(via)

for kb in "${keyboards[@]}" ; do
  tmpmaps=(${keymaps[@]})
  # Add special keymaps for keyball46
  if [ $kb = keyball46 ] ; then
    tmpmaps+=(test_Left test_Both)
    tmpmaps+=(via_Left via_Both)
  fi
  for km in "${tmpmaps[@]}" ; do
    echo "# build $kb:$km"
    make SKIP_GIT=yes KEEP_BIN=true "keyball/${kb}:${km}"
    echo ""
  done
done
