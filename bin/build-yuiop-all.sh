#!/bin/sh

set -eu

#make -j8 SKIP_GIT=yes yuiop/yuiop47:default
#make -j8 SKIP_GIT=yes yuiop/yuiop50d:default
#make -j8 SKIP_GIT=yes yuiop/yuiop22rs:default
#make -j8 SKIP_GIT=yes yuiop/yuiop60hh4:default
#make -j8 SKIP_GIT=yes yuiop/yuiop31rs:test

make -j8 SKIP_GIT=yes yuiop/yuiop60hh5:default yuiop/yuiop60hh5:test
