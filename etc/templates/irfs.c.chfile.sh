#!/bin/bash
echo "fls = list_nextmost(fls);"
echo "list_insert_next(fls, curr_file);"
echo "curr_file = make_file(\"`echo $1 | sed 's/\"/\\\\"/g'`\");"
