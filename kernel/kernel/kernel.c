#include <stdio.h>
#include <kernel/tty.h>
#include <kernel/init.h>
#include <kernel/memory.h>
#include <kernel/error.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include "../arch/i386/vga.h"

uint64_t ticks;

void startInit();

void kernel_early()
{
	memInit();
	terminal_initialize();
	printf("Starting kernel\n");
	printf("Terminal ready\n");
	printf("Initializing error handling system\n");
	kerr_init(3);
	printf("EHS ready\n");
	uint64_t temp1 = calibrate_time();
	if (temp1 > 100)
	{
		ticks = temp1;
		printf("%oDone%o\n", cl(green, black), cl(lightGrey, black));
	}
	else
	{
		printf("%oFailed, retrying...%o\n", cl(red, black), cl(lightGrey, black));
		uint64_t temp2 = calibrate_time();
		if (temp2 > 100)
		{
			ticks = temp2;
			printf("%oDone%o\n", cl(green, black), cl(lightGrey, black));
		}
		else
		{
			printf("%oFailed%o\n", cl(red, black), cl(lightGrey, black));
			panic("unable to calibrate time");
		}
	}
	set_timecal(ticks);
	printf("Kernel ready\n");
	return;
}

void kernel_main(void)//сложноватенько половина printf'ов - тупо для красоты)
{	
	kernel_early();
	
	printf("%c%c%c%c%c%c%c\n", schar(SCR|SCD), schar(SCL|SCR), schar(SCL|SCR), schar(SCL|SCR), schar(SCL|SCR), schar(SCL|SCR), schar(SCL|SCD|SCDV));
	printf("%c%oKLOSY%o%c%ov beta 1.3%o\n", schar(SCD|SCU), cl(blue, red), cl(lightGrey, black), schar(SCD|SCU|SCDV), cl(red, blue), cl(lightGrey, black));
	printf("%c%c%c%c%c%c%c\n", schar(SCR|SCU|SCDH), schar(SCL|SCR|SCDH), schar(SCL|SCR|SCDH), schar(SCL|SCR|SCDH), schar(SCL|SCR|SCDH), schar(SCL|SCR|SCDH), schar(SCL|SCU|SCDV|SCDH));
	printf("%oAlmost a good one!%o\n\n", cl(white, black), cl(lightGrey, black));
	
	startInit(); // основа - вот
	
	// after init exits
	printf("%oShutting down...%o\n", cl(red, black), cl(lightGrey, black));
	panic("shutdown"); // shutdown function is not implemented yet
}
