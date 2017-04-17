#include <kernel/init.h>
#include <kernel/tty.h>
#include <kernel/memory.h>
#include <kernel/error.h>
#include <stdstructs/list.h>
#include <../arch/i386/vga.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdmath.h>
#include <hash.h>
#include <file.h>
#include <irfs.h>

int streq(string_t s1, string_t s2)
{
	size_t l1 = strlen(s1);
	size_t l2 = strlen(s2);
	if (l1 != l2)
		return 0;
	for (size_t i = 0; i < l1; ++i)
	{
		if (s1[i] != s2[i])
			return 0;
	}
	return 1;
}

string_t *split(string_t s, int *ct)
{
	int i = 0;
	int len = (int)strlen(s);
	if (len == 0)
		return null;
	string_t word;
	string_t *sl = allocate(256);
	if (!sl)
		panic("111");
	int size = 0;
	int m = 0;
	for (i = 0; i < len; ++i)
	{
		++size;
		if (s[i] != ' ')
			continue;
		else
		{
			if ((i == 0 || s[i-1] == ' ') && i < len - 1)
				continue;
			else
			{
				word = allocate(size + 1);
				word[size] = word[size - 1] = 0;
				memcpy(word, s + i - size + 1, size);
				if (word[size] == ' ')
					word[size] = 0;
				if (word[size-1] == ' ')
					word[size-1] = 0;
				sl[m] = word;
				++m;
				size = 0;
//				++i;
			}
		}
	}
	--i;
	word = allocate(size + 1);
	word[size] = word[size - 1] = 0;
	memcpy(word, s + i - size + 1, size);
	if (word[size] == ' ')
		word[size] = 0;
	if (word[size-1] == ' ')
		word[size-1] = 0;
	sl[m] = word;
	++m;
	*ct = m;
	return sl;
}

void startInit()
{
	init_ramfs();
	list fl = get_fls();
	
	printf("Klosy shell 1.0 beta (kernel 1.4)\n");
	
	string_t s = allocate(256);
	string_t *spl;
	if (!s)
	{
		kerr("klsh: unable to allocate memory");
		
	}
	/*
	printf("[%s]\n---\n\n", split("dssdabcvq  defdhtstwstow 123udddwwdeahfgy 45efeffe6")[2]);
	*/
	
	while (1)
	{
		printf("%okodopp@klosy-klsh-1.4%o / %o$ ", cl(lightGreen, black), cl(lightBlue, black), cl(lightGrey, black));
		scan_strl(s);
		int cnt = 0;
		spl = split(s, &cnt);
		printf("spl[0] = <<%s>>. spl[1] = <<%s>>.\n", spl[0], spl[1]);
		if (streq(spl[0], "exit"))
			return;
		else if (streq(spl[0], "cat"))
		{
			if (cnt != 2)
			{
				printf("Usage: cat <file>\n");
				continue;
			}
			string_t s2 = spl[1];
			list ls = fl;
			while (ls && ls->elem && ((file)(ls->elem))->name_hash != hash(s2))
			{
				ls = ls->next;
			}
			if (!ls || !ls->elem)
			{
				printf("File '%s' not found\n", s2);
				continue;
			}
			file fil = (file)(ls->elem);
			size_t sz = fil->size;
			char *buf = allocate(sz + 1);
			if (!buf)
				panic("666 #2");
			fread(fil, sz, buf);
			freset(fil);
			buf[sz] = 0;
			printf("File '%s': %s", spl[1], buf);
			deallocate(buf, sz + 1);
		}
		else
			if (!streq(spl[0], "")) printf("klsh: %s: unknown command\n", spl[0]);
	}
	
}
