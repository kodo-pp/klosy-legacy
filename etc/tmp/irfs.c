#include <file.h>
#include <stdlib.h>
#include <string.h>
#include <stdstructs/list.h>
#include <initramfs.h>

static file curr_file = null;
static list fls = null;

list get_fls()
{
	return fls;
}

static void f_add(string_t s)
{
	fwrite(curr_file, strlen(s), s);
	fwrite(curr_file, 1, 10);
}

void init_ramfs()
{

list fls = make_list(null);

fls = list_nextmost(fls);
list_insert_next(fls, curr_file);
curr_file = make_file("aaa");
f_add("qeioqe");
f_add("uadg pY EF\"w IFOw");
f_add("owf[u wf;;w f?WF Uiwy fo");

fls = list_nextmost(fls);
list_insert_next(fls, curr_file);
curr_file = make_file("bbb");
f_add("o83ryoGL");
f_add("WF&Y f9w0*W&^Vo9WF");
f_add("");
f_add("FW(&TW&Ft wloywf7 l WFLO Wfl97 t");

fls = list_nextmost(fls);
list_insert_next(fls, curr_file);
curr_file = make_file("cafwehgrhr");
f_add("r208762r98yfohhcitf");

fls = list_prevmost(fls);
}
