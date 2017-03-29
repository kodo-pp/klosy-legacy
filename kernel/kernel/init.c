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

void startInit()
{
//	printf("make file\n");
//	sleep(1000);
//	printf("make file\n");
	file f = make_file("File 1");
	if (!f)
		panic("no f");
	string_t s = "Hello world!", s1 = allocate(64);
	if (!s1)
		panic("zzzaaa");
	memset(s1, 0, 64);
//	printf("write file\n");
//	sleep(1000);
//	printf("write file\n");
	fwrite(f, strlen(s)*sizeof(char), s);
	f->pos = 0;
//	printf("read file\n");
//	sleep(1000);
//	printf("read file\n");
	fread(f, strlen(s)*sizeof(char), s1);
	printf("%d, %s.\n", (int)strlen(s1), s1);
	panic("azaza");
}
