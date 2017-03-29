#include <kernel/memory.h>
#include <stdint.h>
#include <time.h>

int8_t *reserved_begin = (int8_t *)0x100000;
size_t reserved_size = 0x4000000; // 64 MiB
int8_t *allocbuf_begin = (int8_t *)0x4100000;
size_t allocbuf_size = 0x100000;

static size_t getOffset(int8_t *ptr)
{
	return (size_t)ptr - (size_t)reserved_begin;
}

static void setAllocated(size_t offset, size_t size, int val)
{
	int8_t *ptr = (int8_t *)(offset + (size_t)allocbuf_begin);
	memset(ptr, (val ? 0xFF : 0), size);
}

static int canAllocate(size_t offset, size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		if (allocbuf_begin[offset + i] != (int8_t)0)
			return 0;
	}
	return 1;
}

static int8_t *getAllocPtr(size_t offset)
{
	return (int8_t *)((size_t)reserved_begin + offset);
}

void memInit()
{
	setAllocated(getOffset(reserved_begin), reserved_size, 0);
}

void* allocate(size_t size)
{
	//printf("Allocate request: size=%d", size);
	void *res = null;
	size_t offset;
	for (offset = 0; offset < allocbuf_size; ++offset)
	{
		if (canAllocate(offset, size))
		{
			setAllocated(offset, size, 1);
			res = (void *)getAllocPtr(offset);
			break;
		}
	}
	//printf(" : %d\n", res);
	//sleep(5000);
	return res;
}

void deallocate(void *begin, size_t size)
{
	setAllocated(getOffset((int8_t *)begin), size, 0);
}
