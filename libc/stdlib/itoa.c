#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int itoa(int number, string_t target_string)
{
	int is_negative = (number<0 ? 1 : 0);
	if (number < 0)
		number *= -1;
	int temp = number;
	int digits_count = 0;
	
	do
	{
		temp /= 10;
		++digits_count;
	}
	while (temp);
		
	if (target_string != null)
	{
		char temp_string[digits_count + 1 + is_negative];
		temp_string[digits_count] = '\0';
		if (is_negative)
			temp_string[0] = '-';
		int i = digits_count - 1 + is_negative;
		do
		{
			temp_string[i] = number % 10 + 48;
			number /= 10;
			--i;
		}
		while (number);
		memcpy(target_string,temp_string, sizeof(temp_string));
	}
	return digits_count + is_negative;
}
