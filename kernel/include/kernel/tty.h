#ifndef _KERNEL_TTY_H
#define _KERNEL_TTY_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

//bool make_tty(int, size_t, size_t, size_t, size_t);
//void use_tty(int);
void terminal_clear();
void terminal_setcolor(uint8_t);
void terminal_initialize(void);
void terminal_putchar(char c);
void terminal_write(const char* data, size_t size);
void terminal_writestring(const char* data);
void terminal_position(int, int);
void scroll();

#endif // _KERNEL_TTY_H
