#!/bin/bash
echo "if (curr_file)"
echo "    curr_file->pos = 0;"
echo "fls = list_nextmost(fls);"
echo "curr_file = make_file(\"`echo $1 | sed 's/\"/\\\\"/g'`\");"
echo "list_insert_next(fls, curr_file);"
