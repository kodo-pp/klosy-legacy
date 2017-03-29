/*#include <file.h>
#include <hash.h>
#include <string.h>
#include <stdlib.h>
#include <kernel/memory.h>
// https://pastebin.com/zmZjDvuu
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
		deallocate(f, sizeof(struct _file));//но здесь обращаемся не как file здесь нет звёздочки, то есть это не укахатель. Нам нужно узнать размер самой структуры, а не указателя на неё
		// sizeof - размер какой-то переменной или какого-та типа данныз. Например: sizeof(int) == 4;      short a[10]; sizeof(a) == 20 эта функция из стандартной библиотеки? Нет, она встроенная в компилятор так стоп на всех компиляторах она есть? Должна быть на всех. Это часть стандарта языка. Ясно.
		return null;
	}
	return f; // Я пошёл пить чай, буду, когда вернусь. ок.
}

int resize_file(file f, size_t new_size)
{
	if (f == null)
		return 0;
	if (new_size < f->size)
	{
		deallocate(f->data + new_size, f->size - new_size);//что значит->     f - это указатель на структуру _file.  f->size   - то же самое, что и   (*f).size
								//																			struct str s1; struct str *s2 = &s1;       s1.value   ==    s2->value
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

int rename_file(file f, string_t new_name) // файл  новое имя файла то есть мы в функцию указатель на файл помещаем Да, указатель на struct _file, то есть file
{
	if (f == null)//зачем? Если сюда передадут нулевой указатель, то ОС не упадёт
		return 0;
	int64_t nh = hash(new_name); // Здесь мы считаем хэш нового имени и кладём его туда
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

int fwrite_8(file f, int8_t data) // Всё понятно? Если бы... Что например непонятно?
{
	if (f == null)
		return 0;
	if (f->position >= f->size)
		return 0;
	int8_t *p = (int8_t *)(f->data);
	p[f->position++] = data;
	return 1;
}
int fwrite(file, size_t, void *); // Ты здесь? ................*/
