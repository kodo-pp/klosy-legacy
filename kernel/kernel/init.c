#include <kernel/init.h>
#include <kernel/tty.h>
#include <kernel/memory.h>
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

#ifdef __cplusplus
extern "C"
{
#endif

void startInit(void)
{
	init_ramfs();
	list ls = get_fls();
	printf("%d\n", (int)list_abs_len(ls));
	string_t s = allocate(4);
	if (!s)
		panic("no s");
	for (int i = 0; i < (int)list_abs_len(ls); ++i)
	{
		s = "null";
		if (list_abs_at(ls, i)->elem)
		{
			((file)(list_abs_at(ls,i)->elem))->pos = 0;
			printf("fread: %d\n", fread((file)(list_abs_at(ls,i)->elem), 4, s));
		}
		printf("at(%d) = <<%s>>\n", i, s);
	}
}

#ifdef __cplusplus
}
#endif
