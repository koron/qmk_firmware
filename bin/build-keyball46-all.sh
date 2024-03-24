#!/bin/sh

set -eu

version=2.0.0-alpha.3

keymaps=()
keymaps+=(default)
keymaps+=(test test_Left test_Both)
keymaps+=(via via_Left via_Both)

targets=()
firms=()
for keymap in "${keymaps[@]}" ; do
  targets+=(keyball/keyball46:${keymap})
  firms+=(keyball_keyball46_${keymap}.hex)
done

make SKIP_GIT=yes "${targets[@]}"

outdir=tmp/firms/keyball46/${version}

mkdir -p ${outdir}
rm -f ${outdir}/keyball46*.zip

for keymap in "${keymaps[@]}" ; do
  zip -9 ${outdir}/keyball46_${keymap}_${version}.zip keyball_keyball46_${keymap}.hex
done

zip -9 ${outdir}/keyball46-${version}.zip "${firms[@]}"
