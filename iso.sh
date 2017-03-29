#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/klosy.kernel isodir/boot/klosy.kernel
cat grubcfg.txt > isodir/boot/grub/grub.cfg # `cat ./grubcfg.txt`<< EOF
#menuentry "klosy alpha 1.0.1" {
#	multiboot /boot/klosy.kernel
#}
#EOF
grub-mkrescue -o klosy.iso isodir

