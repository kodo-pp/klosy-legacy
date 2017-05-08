#ifndef _STRING_H
#define _STRING_H 1

#include <sys/cdefs.h>

#include <stddef.h>
#include <stdbool.h>

typedef char * string_t;

#ifdef __cplusplus
extern "C" 
{
#endif

int memcmp(const void*, const void*, size_t);
void* memcpy(void* __restrict, const void* __restrict, size_t);
void* memmove(void*, const void*, size_t);
void* memset(void*, int, size_t);
size_t strlen(const char*);
bool streq(string_t, string_t);
string_t *split(string_t, int *);
string_t *csplit(string_t, int *, char ch);

#ifdef __cplusplus
}
#endif

#endif
