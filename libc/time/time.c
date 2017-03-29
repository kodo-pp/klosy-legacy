#include <stdlib.h>
#include <stdio.h>
#include <keyboard.h>
#include <time.h>

uint64_t ts = 0;

enum
{
	cmos_address = 0x70,
	cmos_data    = 0x71
};

static inline int get_update_in_progress_flag()
{
	outb(cmos_address, 0x0A);
	return (inb(cmos_data) & 0x80);
}

static inline unsigned char get_RTC_register(int reg)
{
	outb(cmos_address, reg);
	return inb(cmos_data);
}

uint8_t read_CMOS_time(int reg)
{
	return get_RTC_register(reg);
}

uint64_t calibrate_time()
{
	printf("Calibrating time... ");
	uint64_t ticks = 0;
	uint8_t t = read_CMOS_time(0);
	while (t == read_CMOS_time(0));
	++t;
	while (t == read_CMOS_time(0))
		ticks++;
	return ticks / 2;
}

void set_timecal(uint64_t ticks)
{
	ts = ticks;
	//printf("DEBUG: set_timecal: ts = %d", (int)ts);
}

bool sleep(uint32_t ms)
{
	for (uint64_t ticks = 0; ticks < ts / 1000 * ms; ++ticks)
	{
		read_CMOS_time(0);
	}
	return true;
}
