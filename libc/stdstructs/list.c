/* libc/stdstructs/list.c - двусвязный список. Реализация функций.
kodopp */

//#error todo
#include <stdstructs/list.h>
#include <stdlib.h>
#include <kernel/memory.h>

/* Создаёт список из 1 элемента с заданным размером элемента. При невозможности
создания (нехватка RAM и т.п.) возвращает null */
list make_list(void *elem)
{
	list ls = allocate(sizeof(struct _list));
	if (ls == null)
		return null;
	ls->elem = elem;
	ls->next = null;
	ls->prev = null;
	return ls;
}

/* Создаёт новый элемент существующего списка. При невозможности создания
возвращает false, при успешном создании возвращает true. Созданный элемент
помещается в поле prev текущего */
bool list_insert_prev(list ls, void *elem)
{
	if (ls == null)
		return false;
	
	list newls = make_list(elem);
	if (newls == null)
		return false;
	
	newls->next = ls;
	newls->prev = ls->prev;
	ls->prev = newls;
	return true;
}

/* Создаёт новый элемент существующего списка. При невозможности создания
возвращает false, при успешном создании возвращает true. Созданный элемент
помещается в поле next текущего */
bool list_insert_next(list ls, void *elem)
{
	if (ls == null)
		return false;
	
	list newls = make_list(elem);
	if (newls == null)
		return false;
	
	newls->prev = ls;
	newls->next = ls->next;
	ls->next = newls;
	return true;
}

/* Удаляет заданный элемент списка. Возвращает указатель на данные элемента
или null при ошибке */
void *list_pop(list ls)
{
	if (ls == null)
		return null;
	
	void *ret = ls->elem;
	
	if (ls->prev != null)
	{
		ls->prev->next = ls->next;
	}
	if (ls->next != null)
	{
		ls->next->prev = ls->prev;
	}
	
	deallocate(ls, sizeof(struct _list));
	return ret;
}

/* Удаляет все элементы списка. Возвращает true в случае успеха и false в
случае неудачи. Все данные в списке и указатели на них будут потеряны */
bool list_clear(list ls)
{
	if (ls == null)
		return false;
	
	list tls = ls;
	tls = list_prevmost(tls);
	
	while (tls->next != null)
	{
		list tls_nxt = tls->next;
		list_pop(tls);
		tls = tls_nxt;
	}
	return true;
}

/* Вычисляет длину списка, начиная с текущего элемента. Вернёт 0 в случае
неудачи */
size_t list_len(list ls)
{
	if (ls == null)
		return 0;
	
	list tls = ls;
	size_t sz = 0;
	while (tls)
	{
		tls = tls->next;
		++sz;
	}
	
	return sz;
}

/* Вычисляет длину списка, начиная с list_prevmost. Вернёт 0 в случае
неудачи */
size_t list_abs_len(list ls)
{
	list pmls = list_prevmost(ls);
	return list_len(pmls);
}

/* Возвращает n-ный элемент списка, начиная с текущего злемента. Вернёт null
в случае неудачи */
list list_at(list ls, int n)
{
	list tls = ls;
	int reversed = 0;
	if (n < 0)
	{
		reversed = 1;
		n = -n;
	}
	
	for (int i = 0; i < n; ++i)
	{
		if (tls == null)
			return null;
		
		tls = reversed ? tls->prev : tls->next;
	}
	
	return tls;
}

/* Возвращает n-ный элемент списка, начиная с list_prevmost. Вернёт null
в случае неудачи */
list list_abs_at(list ls, int n)
{
	if (ls == null)
		return null;
	
	list pmls = list_prevmost(ls);
	return list_at(pmls, n);
}

/* Возвращает крайний элемент списка в сторону prev */
list list_prevmost(list ls)
{
	if (ls == null)
		return null;
	
	list tls = ls;
	while (tls->prev)
	{
		tls = tls->prev;
	}
	return tls;
}

/* Возвращает крайний элемент списка в сторону next */
list list_nextmost(list ls)
{
	if (ls == null)
		return null;
	
	list tls = ls;
	while (tls->next)
	{
		tls = tls->next;
	}
	return tls;
}
