#include <string.h>
#include <stdio.h>

int memcmp(const void* aptr, const void* bptr, size_t size)
{
	const unsigned char* a = (const unsigned char*) aptr;
	const unsigned char* b = (const unsigned char*) bptr;
//	printf("a = 0x%x : [%s], b = 0x%x : [%s], size = %d\n", a, a, b, b, size);
	for (size_t i = 0; i < size; i++) {
		if (a[i] < b[i])
			return -1;
		else if (b[i] < a[i])
			return 1;
	}
	return 0;
}
