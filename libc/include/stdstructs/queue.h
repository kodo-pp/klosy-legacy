#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

void *makeList(size_t, void *);
void *lishPushBack(void *, void *, size_t);
void *listPopBack(void *, size_t);
void *listPushFront(void *, void *, size_t)
void *listPopFront(void *, size_t);
void *listPush(void *, void *, size_t);
void *listPop(void *, size_t);
void *listBack(void *, size_t);
void *listFront(void *, size_t);
void *listPrevious(void *, size_t);
void *listNext(void *, size_t);
void *listAbsoluteIndex(void *, size_t, int);
void *listRelativeIndex(void *, size_t, int);

#endif
