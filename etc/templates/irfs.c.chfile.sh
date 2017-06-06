#!/bin/bash
echo -e "\tif (curr_file)"
echo -e "\t\tcurr_file->pos = 0;"
echo -e "\tfls = list_nextmost(fls);"
echo -e "\tcurr_file = make_file(\"`echo $1 | sed 's/\"/\\\\"/g'`\");"
echo -e "\tlist_insert_next(fls, curr_file);"
