#include <kernel/init.h>
#include <kernel/tty.h>
#include <kernel/memory.h>
#include <stdstructs/list.h>
#include <../arch/i386/vga.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdmath.h>
#include <hash.h>

/*
Итак, нам нужно:
Функции для рисования точек и линий
синус, косинус, кв.корень все? Может, ещё что-то понадобится, но пока всё
Мы создадим библиотеку stdmath и положим нужные функции туда
Пока потестим
Теперь добавим в систему сборки stdmath
*/
 // Должно быть две точки (маленьких прямоугольника)
void startInit()
{/*
	int d = 0; // Угол поорота
	while(true)
	{
		terminal_clear();
		// Рисуем куб
		draw_line(round(21+20*cos(d)), round(4+3*sin(d)), round(21+20*cos(d)), round(19+3*sin(d)));
		draw_line(round(21+20*cos(d+90)), round(4+3*sin(d+90)), round(21+20*cos(d+90)), round(19+3*sin(d+90)));
		draw_line(round(21+20*cos(d+180)), round(4+3*sin(d+180)), round(21+20*cos(d+180)), round(19+3*sin(d+180)));
		draw_line(round(21+20*cos(d+270)), round(4+3*sin(d+270)), round(21+20*cos(d+270)), round(19+3*sin(d+270)));
		
		draw_line(round(21+20*cos(d)), round(4+3*sin(d)), round(21+20*cos(d+90)), round(4+3*sin(d+90)));
		draw_line(round(21+20*cos(d+90)), round(4+3*sin(d+90)), round(21+20*cos(d+180)), round(4+3*sin(d+180)));
		draw_line(round(21+20*cos(d+180)), round(4+3*sin(d+180)), round(21+20*cos(d+270)), round(4+3*sin(d+270)));
		draw_line(round(21+20*cos(d+270)), round(4+3*sin(d+270)), round(21+20*cos(d)), round(4+3*sin(d)));
		
		draw_line(round(21+20*cos(d+270)), round(19+3*sin(d+270)), round(21+20*cos(d)), round(19+3*sin(d)));
		draw_line(round(21+20*cos(d)), round(19+3*sin(d)), round(21+20*cos(d+90)), round(19+3*sin(d+90)));
		draw_line(round(21+20*cos(d+90)), round(19+3*sin(d+90)), round(21+20*cos(d+180)), round(19+3*sin(d+180)));
		draw_line(round(21+20*cos(d+180)), round(19+3*sin(d+180)), round(21+20*cos(d+270)), round(19+3*sin(d+270)));
		
		sleep(500); // Ждём некоторое время 500 милисекунд+?+  Не совсем точно, конечно, но что-то вроде этого
		d += 10;
		d %= 360;
	}
	panic("test");*/
	printf("low dword of hash of 'Hello world!abcd' is %d\n", (int)hash("Hello world!abcd"));
	printf("low dword of hash of 'Hello world!abc' is %d\n", (int)hash("Hello world!abc"));
	printf("low dword of hash of 'Hello world!abcde' is %d\n", (int)hash("Hello world!abcde"));
	printf("low dword of hash of 'Hello world!abce' is %d\n", (int)hash("Hello world!abce"));
	printf("low dword of hash of 'Iello world!abcd' is %d\n", (int)hash("Iello world!abcd"));
	printf("low dword of hash of 'a' is %d\n", (int)hash("a"));
	printf("low dword of hash of '' is %d\n", (int)hash(""));
} // Одной из точек недостаёт работает. nНе всегда Зашибись ОК. Я пошёл,  можешь здесь поэкспериментировать (поменять цвета, порисовать, и т.п. Только 1 сек) Всё, я пошёл пока пока а кстати, сейчас Ctrl+C и Ctrl+V работают?
//у меня нет. Ладно, пока пока
