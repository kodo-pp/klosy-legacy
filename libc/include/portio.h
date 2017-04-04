#ifdef __cplusplus
extern "C"
{
#endif
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

void outb(uint16_t, uint8_t);
uint8_t inb(uint16_t);

#ifdef __cplusplus
}
#endif
