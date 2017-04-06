#include <stdlib.h>
#include <stdio.h>
#include <kernel/memory.h>
#include <kernel/error.h>

void *smart_allocate(size_t requested_size)
{
//	printf("Allocate: size=%d\n", requested_size);
	if (requested_size <= 0) // На всякий случай
		return null;

	size_t real_size = requested_size + sizeof(size_t); // Размер, который реально будет выделен. Перед выделенными данными new() кладёт size_t - размер этих данных, чтобы потом можно было их удалить
	void *ptr_to_allocated = allocate(real_size);
	if (ptr_to_allocated == null) // Не удалось выделить память
	{
		return null;
	}

	size_t *ptr_to_size_t = (size_t *)ptr_to_allocated;
	*ptr_to_size_t = requested_size;
	return (int8_t *)ptr_to_allocated + sizeof(size_t);
}

void smart_deallocate(void *allocated_begin)
{	
//	printf("Deallocate: ptr=0x%x, size=", allocated_begin);
	if (allocated_begin == null || allocated_begin < (void *)sizeof(size_t))
		return;
	
	size_t *ptr_to_size_t = (size_t *)((int8_t *)allocated_begin - sizeof(size_t));
	void *real_allocated_begin = (int8_t *)allocated_begin - sizeof(size_t);
	
	size_t requested_size = *ptr_to_size_t;
	if (requested_size <= 0)
		return;
	
	size_t real_size = requested_size + sizeof(size_t);
	if (real_size <= 0) // Возможно переполнение size_t
		return;
	
	deallocate(real_allocated_begin, real_size);
//	printf("%d\n", requested_size);
	return;
}

void *operator new(size_t requested_size)
{	
	return smart_allocate(requested_size);
}

void *operator new[](size_t requested_size)
{	
	return smart_allocate(requested_size);
}

void operator delete(void *allocated_begin)
{
	smart_deallocate(allocated_begin);
	return;
}

void operator delete[](void *allocated_begin)
{
	smart_deallocate(allocated_begin);
	return;
}
