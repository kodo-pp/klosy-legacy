#ifndef _STDIO_H
#define _STDIO_H 1

#include <sys/cdefs.h>
#include <string.h>
#define EOF (-1)

#ifdef __cplusplus
extern "C"
{
#endif

int printf(const char* __restrict, ...);
int putchar(int);
int puts(const char*);
int getchar(void);
int getchar_nofilter(void);
void scan_strl(string_t);
int scan_intl(void);

#ifdef __cplusplus
}
#endif

#endif
