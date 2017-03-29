/*#include <file.h>
#include <hash.h>
#include <string.h>
#include <stdlib.h>
#include <kernel/memory.h>
static const int DEFAULT_FILE_SIZE = 16;
static int frw_err = 0;

int get_frw_err()
{
	return frw_err;
}
void reset_frw_err()
{
	frw_err = 0;
}

file make_file(string_t name)
{
	file f = allocate(sizeof(struct _file));
	if (f == null)
		return null;
	int64_t h = hash(name);
	f->name_hash = h;
	f->size = DEFAULT_FILE_SIZE;
	f->data = allocate(DEFAULT_FILE_SIZE);
	if (f->data == null)
	{
		deallocate(f, sizeof(struct _file));
		return null;
	}
	return f; 
}

int resize_file(file f, size_t new_size)
{
	if (f == null)
		return 0;
	if (new_size < f->size)
	{
		deallocate(f->data + new_size, f->size - new_size);
		f->size = new_size;
	}
	else if (new_size > f->size)
	{
		void *new_data = allocate(new_size);
		if (new_data == null)
			return 0;
		memset(new_data, 0, new_size);
		memcpy(new_data, f->data, f->size);
		deallocate(f->data, f->size);
		f->size = new_size;
		f->data = new_data;
	}
	return 1;
}

int rename_file(file f, string_t new_name)
{
	if (f == null)
		return 0;
	int64_t nh = hash(new_name);
	f->name_hash = nh;
	return 1; 
}

int8_t fread_8(file f)
{
	if (f == null)
	{
		frw_err = 1;
		return 0;
	}
	else if (f->position >= f->size)
	{
		frw_err = 2;
		return 0;
	}
	else
	{
		int8_t *ptr = (int8_t *)(f->data);
		int8_t ret = ptr[f->position++];
		return ret;
	}
}

int fread(file f, size_t sz, void *_buf)
{
	if (f == null || _buf == null)
		return 0;
	int8_t *buf = (int8_t *)_buf;
	for (size_t i = 0; i < sz; ++i)
	{
		buf[i] = fread_8(f);
		if (get_frw_err())
		{
			return 0;
		}
	}
	return 1;
}

int fwrite_8(file f, int8_t data)
{
	if (f == null)
		return 0;
	if (f->position >= f->size)
		return 0;
	int8_t *p = (int8_t *)(f->data);
	p[f->position++] = data;
	return 1;
}
int fwrite(file, size_t, void *);*/
