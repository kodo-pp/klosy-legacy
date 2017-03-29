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

void scan_strl(string_t dest)
{
	char temp[256];
	memset(temp, 0, sizeof(temp));
	int i = 0;
	while (1)
	{
		int t = getchar();
		if (t != 0xFFFF && i < 255)
		{
			printf("%c", t);
			temp[i] = t;
			++i;
		}
		if (t == '\n')
		{
			printf("\n");
			break;
		}
		if (t == '\b')
		{
			i-=2;
		}
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
