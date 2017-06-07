#!/bin/bash
about_comment_text='// WARNING: THIS FILE IS MACHINE-GENERATED AND AUTO-REWRITED ON EACH BUILD.
// DO NOT EDIT IT'
echo 'Constructing initramfs...'
echo "$about_comment_text" > etc/tmp/irfs.c
cat etc/templates/irfs.c.begin >> etc/tmp/irfs.c
for i in `ls irfs.dir`; do
	echo -n "  file $i "
	etc/templates/irfs.c.chfile.sh $i >> etc/tmp/irfs.c
	cat "irfs.dir/$i" | etc/hex2c.sh >> etc/tmp/irfs.c
	echo '' >> etc/tmp/irfs.c # newline
	echo 'packed'
done
cat etc/templates/irfs.c.end >> etc/tmp/irfs.c
cp etc/tmp/irfs.c libc/initramfs
echo 'Done'
