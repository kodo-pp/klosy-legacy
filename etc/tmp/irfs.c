// WARNING: THIS FILE IS MACHINE-GENERATED AND AUTO-REWRITED ON EACH BUILD.
// DO NOT EDIT IT
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

static int hex2dec(char hexch)
{
	if ('0' <= hexch && hexch <= '9')
		return hexch - '0';
	else if ('A' <= hexch && hexch <= 'F')
		return hexch - 'A' + 10;
	else if ('a' <= hexch && hexch <= 'f')
		return hexch - 'a' + 10;
	else
		return -1;
}

static void f_add(string_t s)
{
	size_t flen = strlen(s) / 2;
	for (size_t i = 0; i < flen; ++i)
	{
		char ch = (hex2dec(s[i*2]) << 4) | hex2dec(s[i*2+1]);
		fwrite_8(curr_file, ch);
	}
}

void init_ramfs()
{
	fls = make_list(null);

	if (curr_file)
		curr_file->pos = 0;
	fls = list_nextmost(fls);
	curr_file = make_file("aaa");
	list_insert_next(fls, curr_file);
	f_add("7165696F71650A756164672020705920454622772049464F770A206F77665B752077663B3B7720663F5746205569777920666F0A44656E6973206C6F780A");

	if (curr_file)
		curr_file->pos = 0;
	fls = list_nextmost(fls);
	curr_file = make_file("bbb");
	list_insert_next(fls, curr_file);
	f_add("206F383372796F474C200A574626592020663977302A57265E566F3957460A0A46572826545726467420776C6F79776637206C2057464C4F2057666C393720740A");

	if (curr_file)
		curr_file->pos = 0;
	fls = list_nextmost(fls);
	curr_file = make_file("ccc");
	list_insert_next(fls, curr_file);
	f_add("7232303837363272393879666F6868636974660A");

	if (curr_file)
		curr_file->pos = 0;
	fls = list_nextmost(fls);
	curr_file = make_file("randata");
	list_insert_next(fls, curr_file);
	f_add("82524C58732A94463B464EAEA1938653ED370A10B86DFD4459BC792EC18B086AF6C59850E907CB247230B608FEFFF2786C59D8748CC6364A0CBBF3444EAE4DAFF45F3094C08A474880C4619B659F70DBB8334125E5223369598227915D10771F4EFC13BD");

	if (curr_file)
		curr_file->pos = 0;
	fls = list_nextmost(fls);
	curr_file = make_file("readme");
	list_insert_next(fls, curr_file);
	f_add("23206B6C6F73790A4B6C6F73792069732061206C69676874776569676874206F7065726174696E672073797374656D2E204920637265617465642074686973207265706F206F6E6C7920626563617573652069742773207361666520746F2073746F72652074686520736F7572636520636F6465206F6E204769744875622C206E6F74206F6E206D7920636F6D70757465722E0A2A2A5761726E696E673A2A2A204B6C6F737920697320696E20646576656C6F70656D656E7420616E642069742069736E277420726561647920666F7220646F776E6C6F6164696E672E0A");

	curr_file->pos = 0;
	fls = list_prevmost(fls)->next;
	list_pop(fls->prev);
}
