#include <stdlib.h>
#include <string.h>

bool streq(string_t s1, string_t s2)
{
	size_t l1 = strlen(s1);
	size_t l2 = strlen(s2);
	if (l1 != l2)
		return false;
	for (size_t i = 0; i < l1; ++i)
	{
		if (s1[i] != s2[i])
			return false;
	}
	return true;
}
