#ifdef __cplusplus
extern "C"
{
#endif
#ifndef _STDLIB_H
#define _STDLIB_H 1

#define null ((void *)0)

#include <sys/cdefs.h>
#include <string.h>		// string_t
#include <stdbool.h>

#define max(x, y) (x)>(y)?(x):(y)
#define min(x, y) (x)<(y)?(x):(y)

#ifdef __cplusplus
extern "C"
{
#endif

__attribute__((__noreturn__))
void abort(void);
void panic(string_t);
void epanic();
void warn(string_t);
int itoa(int, string_t);
int dtoa(float, string_t); // Thanks to cb30.
int itox(int, string_t);
int atoi(string_t);
void kassert(bool);
void halt(void);

#ifdef __cplusplus
}
#endif

#endif

#ifdef __cplusplus
}
#endif
