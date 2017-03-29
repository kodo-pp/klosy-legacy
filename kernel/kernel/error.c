#include <kernel/error.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int err_count;
static int max_errors;

void kerr_init(int _max_errors)
{
	max_errors = _max_errors;
	err_count = 0;
}

void kerr_reset()
{
	err_count = 0;
}

void kerr(string_t estr)
{
	++err_count;
	printf("Kernel error: %s\n", estr);
	if (err_count > max_errors)
	{
		panic("too many kernel errors");
	}
}
