#include <stdlib.h>
#include <string.h>
#include <kernel/memory.h>

string_t *split(string_t s, int *ct)
{
	int i = 0;
	int len = (int)strlen(s);/*
	if (len == 0)
		return null;*/
	string_t word;
	string_t *sl = allocate(256);
	if (!sl)
		panic("111");
	int size = 0;
	int m = 0;
	for (i = 0; i < len; ++i)
	{
		++size;
		if (s[i] != ' ')
			continue;
		else
		{
			if ((i == 0 || s[i-1] == ' ') && i < len - 1)
				continue;
			else
			{
				word = allocate(size + 1);
				word[size] = word[size - 1] = 0;
				memcpy(word, s + i - size + 1, size);
				if (word[size] == ' ')
					word[size] = 0;
				if (word[size-1] == ' ')
					word[size-1] = 0;
				sl[m] = word;
				++m;
				size = 0;
			}
		}
	}
	--i;
	word = allocate(size + 1);
	word[size] = word[size - 1] = 0;
	memcpy(word, s + i - size + 1, size);
	if (word[size] == ' ')
		word[size] = 0;
	if (word[size-1] == ' ')
		word[size-1] = 0;
	sl[m] = word;
	++m;
	*ct = m;
	return sl;
}

string_t *csplit(string_t s, int *ct, char split_ch)
{
	int i = 0;
	int len = (int)strlen(s);/*
	if (len == 0)
		return null;*/
	string_t word;
	string_t *sl = allocate(256);
	if (!sl)
		panic("111");
	int size = 0;
	int m = 0;
	for (i = 0; i < len; ++i)
	{
		++size;
		if (s[i] != split_ch)
			continue;
		else
		{
			if ((i == 0 || s[i-1] == split_ch) && i < len - 1)
				continue;
			else
			{
				word = allocate(size + 1);
				word[size] = word[size - 1] = 0;
				memcpy(word, s + i - size + 1, size);
				if (word[size] == split_ch)
					word[size] = 0;
				if (word[size-1] == split_ch)
					word[size-1] = 0;
				sl[m] = word;
				++m;
				size = 0;
			}
		}
	}
	--i;
	word = allocate(size + 1);
	word[size] = word[size - 1] = 0;
	memcpy(word, s + i - size + 1, size);
	if (word[size] == split_ch)
		word[size] = 0;
	if (word[size-1] == split_ch)
		word[size-1] = 0;
	sl[m] = word;
	++m;
	*ct = m;
	return sl;
}


