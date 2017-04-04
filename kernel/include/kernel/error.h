#ifdef __cplusplus
extern "C"
{
#endif
#ifndef ERROR_H
#define ERROR_H

#include <stdlib.h>
#include <string.h>

void kerr(string_t);
void kerr_init(int);
void kerr_reset();

#endif // ERROR_H

#ifdef __cplusplus
}
#endif
