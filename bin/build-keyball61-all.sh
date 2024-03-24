#!/bin/sh

set -eu

version=0.8.0-beta.1
series=keyball
keyboard=keyball61

keymaps=()
keymaps+=(default)
keymaps+=(test)
keymaps+=(via)

targets=()
firms=()
for keymap in "${keymaps[@]}" ; do
  targets+=(${series}/${keyboard}:${keymap})
  firms+=(${series}_${keyboard}_${keymap}.hex)
done

make SKIP_GIT=yes "${targets[@]}"

outdir=tmp/firms/${keyboard}/${version}

mkdir -p ${outdir}
rm -f ${outdir}/${keyboard}*.zip

for keymap in "${keymaps[@]}" ; do
  zip -9 ${outdir}/${keyboard}_${keymap}_${version}.zip ${series}_${keyboard}_${keymap}.hex
done

zip -9 ${outdir}/${keyboard}-${version}.zip "${firms[@]}"
