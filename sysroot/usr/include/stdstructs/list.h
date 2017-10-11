#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

#ifndef null
#	warning list.h: null not defined, redifining
#	define null ((void *)0)
#endif

struct _list
{
	size_t elem_size;
	struct _list *next;
	struct _list *prev;
	void *elem;
};

typedef struct _list* list;

list make_list(void *);
bool list_insert_prev(list, void *);
bool list_insert_next(list, void *);
void *list_pop(list);
bool list_clear(list);
size_t list_len(list);
size_t list_abs_len(list);
list list_at(list, int);
list list_abs_at(list, int);
list list_prevmost(list);
list list_nextmost(list);

#endif // LIST_H

