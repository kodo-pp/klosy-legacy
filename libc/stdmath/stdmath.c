#include <stdmath.h>
#include <stdio.h>
#include <stdlib.h>
#include <kernel/tty.h>
#include <../../kernel/arch/i386/vga.h>
#include <trigonometric_functions.h>

double sqrt(double x)
{
	double treshold = 0.000000001 /* 10^-9 */;
	if (x < 0 || treshold <= 0)
		return -1;
	
	double l, r, m; 
	if (x < 1)
	{
		l = 0.0;
		r = 1.0;
	}
	else if (x > 1)
	{
		l = 0.0;
		r = x;
	}
	else // x == 1
	{
		return 1;
	}
	
	while (r - l > treshold)
	{
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

int round(double x)
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

void draw_line(int x1, int y1, int x2, int y2)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	if (dx == 0)
	{
		if (dy > 0)
		{
			for (int i = 0; i <= dy; ++i)
			{
				draw_point(x1, y1 + i);
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
	double k = (double)dy / dx;
	if (abs(dx) > abs(dy))
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
				draw_point(round(x1 + i/k), y1+i);
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
}

