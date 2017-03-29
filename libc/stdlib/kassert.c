#include <stdlib.h>
#include <stdbool.h>
#include <kernel/error.h>

void kassert(bool val)
{
	if (!val)
	{
		kerr("kassertion failed");
	}
}

/*
Денис обещал проспонсировать нас. Я предполагаю, что он даст нам 100 рублей (но
с вероятностью 93.2% он не даст ничего). Укажем ли мы его в списке людей,
принимавших участие в создании?
*/
