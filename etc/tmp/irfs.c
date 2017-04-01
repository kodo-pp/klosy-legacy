#include <file.h>
#include <stdlib.h>
#include <string.h>
#include <stdstructs/list.h>
#include <irfs.h>
#include <stdio.h>
#include <time.h>

static file curr_file = null;
static list fls = null;

list get_fls()
{
	return fls;
}

static void f_add(string_t s)
{
	fwrite(curr_file, strlen(s), s);
	string_t s1 = "\n";
	fwrite(curr_file, 1, s1);
}

void init_ramfs()
{

fls = make_list(null);

if (curr_file)
    curr_file->pos = 0;
fls = list_nextmost(fls);
curr_file = make_file("aaa");
list_insert_next(fls, curr_file);
f_add("qeioqe");
f_add("uadg pY EF\"w IFOw");
f_add("owf[u wf;;w f?WF Uiwy fo");

if (curr_file)
    curr_file->pos = 0;
fls = list_nextmost(fls);
curr_file = make_file("bbb");
list_insert_next(fls, curr_file);
f_add("o83ryoGL");
f_add("WF&Y f9w0*W&^Vo9WF");
f_add("");
f_add("FW(&TW&Ft wloywf7 l WFLO Wfl97 t");

if (curr_file)
    curr_file->pos = 0;
fls = list_nextmost(fls);
curr_file = make_file("cafwehgrhr");
list_insert_next(fls, curr_file);
f_add("r208762r98yfohhcitf");

curr_file->pos = 0;
fls = list_prevmost(fls)->next;
list_pop(fls->prev);

}
