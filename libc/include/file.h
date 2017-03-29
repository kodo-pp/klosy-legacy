#ifndef FILE_H
#define FILE_H

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

struct _file // Структура, отражающая файл
{
	uint64_t name_hash; // Хэш имени (попозже расскажу, что такое хэш)
	void *data; // Указатель на данные в файле
	size_t size; // Размер файла
	size_t pos; // Позиция "курсора" при чтении/записи
}

typedef struct _file* file; // Определяем более удобный тип
//typedef - слово для определения новых типов данных на основе старых ясно То есть мы можем обращаться не как struct _file *, а как file


//Дальше пошли функции    
int get_frw_err();//что это? Если во время ввода-вывода в файл возникла ошибка, эта функция возвращает не 0, иначе возвращает 0. Проверка то есть. ыгы С остальным думаю разберусь сам. Ну ладно тогда пока.... подожди. я загружу полный архив с кодом на облако и скину тебе вк. ок
void reset_frw_err();
file make_file(string_t); // Создать файл с заданным именем
int resize_file(file, size_t); // Изменить размер файла
int rename_file(file, string_t); // Переименовать файл
int8_t fread_8(file); // Прочитать байт из файла
int fread(file, size_t, void *); // Прочитать n байт из файла
int fwrite_8(file, int8_t); // Записать байт в файл что значит int8_t    int, занимающий 1 байт (значения от -128 до 127) откуда 8 берется 1 байт = 8 бит ясн
int fwrite(file, size_t, void *); // Записать n байт в файл
//почему файловая система оперативной памяти а не жесткого диска можно написать и для HDD, но придётся гуглить про работу с ним. ок
// Так, тут вроде всё опроеделили, теперь расскажу-ка я про хэши
/*
Грубо говоря, хэш - преобразование строки в число. Желательно, чтобы двум разным строкам не соответствовали одинаковые хэши. Я ушёл ужинать. Все с хэшами разобрался
*/

#endif
