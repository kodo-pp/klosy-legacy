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
#include <cpp/memdefs.hpp>

#ifdef __cplusplus
extern "C"
{
#endif

class Test
{
	public:
		int a;
		int b;
		int64_t c;
};

void startInit(void)
{
//	init_ramfs();
	printf("sizeof Test = %d\n", sizeof(Test));
	Test *t = new Test;
	int8_t *z = new int8_t;
	printf("t at 0x%x\nz at 0x%x\n", t, z);
	delete t;
	delete z;
}

#ifdef __cplusplus
}
#endif
