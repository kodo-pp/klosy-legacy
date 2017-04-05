#ifndef __cplusplus
#error this file MUST be compiled with g++
#endif

#include <stdlib.h>
#include <kernel/memory.h>
#include <kernel/error.h>
#include <stdio.h>

template <class T> T ignore(T v)
{
	return v;
}

void *operator new(size_t size)
{
	return allocate(size);
}
void *operator new[](size_t size)
{
	return allocate(size);
}
void operator delete(void *ptr)
{
	ignore(ptr);
	kerr("operator delete is not implemented. Use deallocate(void *, size_t)");
}
void operator delete[](void *ptr)
{
	ignore(ptr);
	kerr("operator delete[] is not implemented. Use deallocate(void *, size_t).");
	return;
}

template <class T> void cppmemfree(T *ptr, size_t count = 1)
{
	printf("Deallocating 0x%x, size %d * %d = %d\n", (int)ptr, (int)sizeof(T), (int)count, (int)sizeof(T) * (int)count);
	deallocate(ptr, sizeof(T) * count);
}
