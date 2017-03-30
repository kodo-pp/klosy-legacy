#!/bin/bash
echo 'Constructing initramfs...'
cat etc/templates/irfs.c.begin > etc/tmp/irfs.c
for i in `ls irfs.dir`; do
	echo -n "  file $i "
	etc/templates/irfs.c.chfile.sh $i >> etc/tmp/irfs.c
	cat "irfs.dir/$i" | ./stdin2c.sh >> etc/tmp/irfs.c
	echo '' >> etc/tmp/irfs.c # newline
	echo 'packed'
done
cat etc/templates/irfs.c.end >> etc/tmp/irfs.c
cp etc/tmp/irfs.c libc/initramfs
echo 'Done'
