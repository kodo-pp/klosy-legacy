#include <stdio.h>
#include <keyboard.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int getchar_nofilter()
{
	int t;
	do
	{
		t = fromScanCode(getScanCode());
	}
	while (t == 0xFFFF);
	kbd_sleep();
	return t;
}

int getchar()
{
	return filter(getchar_nofilter());
}

int shifted_char(int ch)
{
	if ('a' <= ch && ch <= 'z')
		return ch - 'a' + 'A';
	switch(ch)
	{
		case '`': return '~'; break;
		case '1': return '!'; break;
		case '2': return '@'; break;
		case '3': return '#'; break;
		case '4': return '$'; break;
		case '5': return '%'; break;
		case '6': return '^'; break;
		case '7': return '&'; break;
		case '8': return '*'; break;
		case '9': return '('; break;
		case '0': return ')'; break;
		case '-': return '_'; break;
		case '=': return '+'; break;
		case '[': return '{'; break;
		case ']': return '}'; break;
		case ';': return ':'; break;
		case '\'': return '"'; break;
		case '\\': return '|'; break;
		case ',': return '<'; break;
		case '.': return '>'; break;
		case '/': return '?'; break;
		default: return ch; break;
	}
}

void scan_strl(string_t dest)
{
	char temp[256];
	memset(temp, 0, sizeof(temp));
	int i = 0;
	bool sh = false;
	while (1)
	{
		int t = getchar();
		if (t == (0x0200 | 'A') || t == (0x0200 | 'B'))
		{
			sh = !sh;
			continue;
		}
		else if (t == '\n')
		{
			printf("\n");
			break;
		}
		else if (t == '\b')
		{
			if (i > 0)
			{
				printf("\b");
				i--;
			}
		}
		else if (t != 0xFFFF && i < 255)
		{
			printf("%c", sh ? shifted_char(t) : t);
			temp[i] = sh ? shifted_char(t) : t;
			++i;
		}
		sh = false;
	}
	// На всякий случай добавим нуль-терминатор (несмотря на то, что он был поставлен memset'ом)
	temp[i] = '\0';
	memmove(dest, temp, sizeof(temp));
	memset(temp, 0, sizeof(temp));
}
int scan_intl(void)
{
	char temp[256];
	memset(temp, 0, sizeof(temp));
	scan_strl(temp);
	int result = atoi(temp);
	memset(temp, 0, sizeof(temp));
	return result;
}
