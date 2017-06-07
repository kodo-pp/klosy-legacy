#include <iostream>

static const char *hextab = "0123456789ABCDEF";

static char lohex(char ch)
{
	return hextab[ch & 0xF];
}

static char hihex(char ch)
{
	return hextab[(ch & 0xF0) >> 4];
}

int main()
{
	char ch;
	while (std::cin.get(ch))
	{
		std::cout << hihex(ch) << lohex(ch);
	}
	
	std::cout << std::endl;
	return 0;
}
