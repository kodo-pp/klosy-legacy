#!/bin/bash
while read line; do
	echo "f_add(\"`echo $line | sed -e 's/\"/\\\\"/g'`\");"
done
