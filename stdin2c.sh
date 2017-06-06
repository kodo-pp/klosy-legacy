#!/bin/bash
while read line; do
	echo -e "\tf_add(\"`echo $line | sed -e 's/\"/\\\\"/g'`\");"
done
