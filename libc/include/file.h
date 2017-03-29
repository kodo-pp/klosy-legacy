#ifndef FILE_H
#define FILE_H

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

struct _file // Структура, отражающая файл
{
	uint64_t name_hash; // Хэш имени 
	void *data; // Указатель на данные в файле
	size_t size; // Размер файла
	size_t pos; // Позиция "курсора" при чтении/записи
};

typedef struct _file* file;

//Дальше пошли функции    
int get_frw_err();
void reset_frw_err();
file make_file(string_t); // Создать файл с заданным именем
int resize_file(file, size_t); // Изменить размер файла
int rename_file(file, string_t); // Переименовать файл
int8_t fread_8(file); // Прочитать байт из файла
int fread(file, size_t, void *); // Прочитать n байт из файла
int fwrite_8(file, int8_t); // Записать байт в файл
int fwrite(file, size_t, void *); // Записать n байт в файл

#endif
