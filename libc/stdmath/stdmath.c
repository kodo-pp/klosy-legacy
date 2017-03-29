#include <stdmath.h>
#include <stdio.h>
#include <stdlib.h>
#include <kernel/tty.h>
#include <../../kernel/arch/i386/vga.h>
#include <trigonometric_functions.h>
// Что? там же void да, ты прав

double sqrt(double x)
{
//	printf("%d", (int)x);
	double treshold = 0.000000001 /* 10^-9 */;
	if (x < 0 || treshold <= 0)
		return -1;
	
	// Бинпоиск
	double l, r, m; 
	if (x < 1)
	{
//		printf("<");
		l = 0.0;
		r = 1.0;
	}
	else if (x > 1)
	{
//		printf(">");
		l = 0.0;
		r = x;
	}
	else // x == 1
	{
		return 1;
	}
	
	while (r - l > treshold)
	{
	//	printf("w,l=%d,r=%d,m=%d\n", (int)l, (int)r, (int)m);
		m = (l + r) / 2;
		if (m*m < x)
			l = m;
		else if (m*m > x)
			r = m;
		else
			return m;
	}
	return r;
}

double abs(double x)
{
	if (x < 0)
		return -x;
	else
		return x;
}

int round(double x)//че это округление числа
{
	int zx = (int)x;
	double fx = x - zx;
	if (fx >= .5)
		++zx;
	return zx;
}


void draw_point(int x, int y)
{
	if (0 <= x && x < 80 && 0 <= y && y < 24)
	{
		terminal_position(x, y);
		printf("%o %o", cl(white, red), cl(lightGrey, black));
	}
}

void draw_line(int x1, int y1, int x2, int y2) //Готово значит нет он идет в else  там п
{
	int dx = x2 - x1;
	int dy = y2 - y1;// Я думаю...++   k=dy/(double)dx  вроде так
	if (dx == 0)
	{
		if (dy > 0)
		{
			for (int i = 0; i <= dy; ++i)
			{
				draw_point(x1, y1 + i); // OK URAAAAAAAAAAAAAAAA!ок 
			}
		}
		else
		{
			for (int i = 0; i >= dy; --i)
			{
				draw_point(x1, y1 + i);
			}
		}
		return;
	}
	if (dy == 0)
	{
		if (dx > 0)
		{
			for (int i = 0; i <= dx; ++i)
			{
				draw_point(x1 + i, y1);
			}
		}
		else
		{
			for (int i = 0; i >= dx; --i)
			{
				draw_point(x1 + i, y1);
			}
		}
		return;
	}
	double k = (double)dy / dx; // Короче, по-моему, одна из фич дробной арифметики. И я через 10 мин иду в спортзал. Ок. Нужно успеть исправить
	if (abs(dx) > abs(dy))//чтобы не было этого
	{
		if (dx > 0)
		{
			for(int i = 0; i <= dx; i++)
			{
				draw_point(x1 + i, round(y1+i*k));
			}
		}
		else
		{
			for(int i = 0; i >= dx; i--)
			{
				draw_point(x1 + i, round(y1+i*k));
			}
		}
	}
	else
	{
		if (dy > 0)
		{
			for(int i = 0; i <= dy; i++)
			{
				draw_point(round(x1 + i/k), y1+i); // что? думаю можно сделать проще как копировать? Ctrl+c, ctrl+v 
			}
		}
		else
		{
			for(int i = 0; i >= dy; i--)
			{
				draw_point(round(x1 + i/k), y1 + i);
			}
		}
	}
	// Ну что, будемм тестить? dy же то же может быть меньше нуля k может быть<0 А нам это здесь пофиг. Точка поставится, ксли y1+i*k >= 0
}




/*
void draw_line(int x1, 
if(x1>x2) {x1 ^= x2; x2 ^= x1; x1 ^= x2;} // Это будет неверно.      Если x1=1, y1=10, x2=10, y2=1, то это пойдёт в x1=1, y1=1, x2=10, y2=10    две разные прямые точно так что не проще //что значит ^=      a ^= b      a = a ^ b      ^ - побитовый (XOR)-   1 ^ 1 -> 0   0 ^ 0 -> 0    1 ^ 0 -> 1   0 ^ 1 -> 1    ^=-?  короче способ поменять два числа местами, не используя 3-го+
	int dx = x2 - x1;
	int dy = y2 - y1;// Я думаю...++   k=dy/(double)dx  вроде так
	double k = (double)dy / dx;
	if (abs(dx) > abs(dy))
	{
		if (dx >= 0)
		{
			for(int i = 0; i <= dx; i++)
			{
				draw_point(x1 + i, round(y1+i*k));
			}
		}
		else
		{
			for(int i = 0; i >= dx; i--)
			{
				draw_point(x1 + i, round(y1+i*k));
			}
		}
	}
*/
