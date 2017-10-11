#include <stdlib.h>
#include <keyboard.h>

uint8_t read_CMOS_time(int);
uint64_t calibrate_time();
void set_timecal(uint64_t);
bool sleep(uint32_t);

