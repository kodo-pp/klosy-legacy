#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static char toChar(int digit)
{
	if (0 <= digit && digit <= 9)
		return digit + '0';
	if (10 <= digit && digit <= 15)
		return digit - 10 + 'A';
	return '0';
}

int itox(int number, string_t target_string) // TODO: add support for negative numbers
{
	if (number < 0) // By now we just do nothing if we meet negative number
		return 0;
	int temp = number;
	int digits_count = 0;
	
	do
	{
		temp /= 16;
		++digits_count;
	}
	while (temp);
		
	if (target_string != null)
	{
		char temp_string[digits_count + 1];
		temp_string[digits_count] = '\0';
		int i = digits_count - 1;
		do
		{
			temp_string[i] = toChar(number % 16);
			number /= 16;
			--i;
		}
		while (number);
		memcpy(target_string,temp_string, sizeof(temp_string));
	}
	return digits_count;
}
