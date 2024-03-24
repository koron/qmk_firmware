#!/bin/sh

set -eu

#make SKIP_GIT=yes yuiop/yuiop47:default
#make SKIP_GIT=yes yuiop/yuiop50d:default
#make SKIP_GIT=yes yuiop/yuiop22rs:default
#make SKIP_GIT=yes yuiop/yuiop60hh4:default
#make SKIP_GIT=yes yuiop/yuiop31rs:test

make SKIP_GIT=yes yuiop/yuiop60hh5:default yuiop/yuiop60hh5:test
