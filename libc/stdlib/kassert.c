#include <stdlib.h>
#include <stdbool.h>
#include <kernel/error.h>

void kassert(bool val)
{
	if (!val)
	{
		kerr("kassertion failed");
	}
}
