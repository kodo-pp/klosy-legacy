#!/bin/sh
set -e
. ./config.sh

for PROJECT in $PROJECTS; do
  (cd $PROJECT && $MAKE clean)
done

rm -rf sysroot || true
rm -rf isodir || true
rm -rf klosy.iso || true
rm     etc/bin2hex || true

touch 'kostyl~'
rm -r `find . | egrep '\~$'`
