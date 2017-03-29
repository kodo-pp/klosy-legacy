#include <hash.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <kernel/memory.h>

const size_t MIN_STR_LEN = 16; // Минимальная длина строки, для которой эффективен данный хэш

static uint64_t _hash(string_t str, uint64_t mod, uint64_t asize, size_t len)
{
	uint64_t res = 0, asize_pow = 1;
	for (size_t i = 0; i < len; ++i)
	{
		res += str[i] * asize_pow;
		asize_pow *= asize;
		res %= mod;
		asize_pow %= mod;
	}
	return res;
}

static inline uint64_t xhash(string_t str, size_t len)
{
	return _hash(str, 12345678901234567ll, 12345ll, len) // Тут идут рандомные чиселки
	     ^ _hash(str, 36016490451032542ll, 83195ll, len)
	     ^ _hash(str, 34810446721486217ll, 73914ll, len)
	     ^ _hash(str, 93714874014602824ll, 83195ll, len)
	     ^ _hash(str, 26487108525895710ll, 87314ll, len)
	     ^ _hash(str, 52014709471650140ll, 56418ll, len)
	     ^ _hash(str, 75916586147253187ll, 18591ll, len)
	     ^ _hash(str, 83195614651364815ll, 34186ll, len);
}

uint64_t hash(string_t str)
{
	size_t len = strlen(str);
	if (len < MIN_STR_LEN)
	{
		string_t newstr = allocate(MIN_STR_LEN);
		if (newstr != null)
		{
			memset(newstr, 0, MIN_STR_LEN);
			memcpy(newstr, str, len);
			for (size_t i = len; i < MIN_STR_LEN; ++i)
			{
				newstr[i] = (char)((char)((1ll*i*(i+1)*(i*i-1)*(len+1)*1234567) >> 8) ^ (i > 0 ? newstr[i-1] : 0)); // Просто любая жуткая формула для генерации псевдослучайного числа на основе предыдущих символов.
//				printf("qqqq:%d\n");
			}
			return xhash(newstr, MIN_STR_LEN);
		}
		else
		{
//			printf("azaza\n");
			return 0;
		}
	}
	else
	{
		return xhash(str, len);
	}
}
