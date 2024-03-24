#!/bin/sh

set -eu

for km in \
  crkbd/rev1/common:kaoriya \
  crkbd/rev1/legacy:kaoriya \
  dztech/dz60rgb/v2:kaoriya \
  re64:kaoriya \
  uzu42:kaoriya \
; do
  make SKIP_GIT=yes $km:clean
  make SKIP_GIT=yes $km
done
