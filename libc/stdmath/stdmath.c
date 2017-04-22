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


