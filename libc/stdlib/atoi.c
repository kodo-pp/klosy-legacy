#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int atoi(string_t source)
{
	int value = 0;
	for (int i = 0; source[i] <= '9' && source[i] >= '0'; ++i)
	{
		value *= 10;
		value += source[i] - '0';
	}
	return value;
}
