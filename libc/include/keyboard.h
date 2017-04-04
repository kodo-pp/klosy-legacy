#ifdef __cplusplus
extern "C"
{
#endif
#ifndef KBD_H
#define KBD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void outb(uint16_t, uint8_t);
uint8_t inb(uint16_t);
char getScanCode();
void kbd_sleep();
/*
enum keys
{
	keyEsc = 1,
	keyEnter = 28,
};*/
int fromScanCode(int);
int filter(int);
int schar(int);

#define SCR (1<<0)
#define SCL (1<<1)
#define SCU (1<<2)
#define SCD (1<<3)
#define SCDV (1<<4)
#define SCDH (1<<5)

#endif

#ifdef __cplusplus
}
#endif
