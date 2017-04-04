#ifdef __cplusplus
extern "C"
{
#endif
#ifndef ARCH_I386_VGA_H
#define ARCH_I386_VGA_H

#include <stdint.h>
#define black VGA_COLOR_BLACK
#define blue VGA_COLOR_BLUE
#define green VGA_COLOR_GREEN
#define cyan VGA_COLOR_CYAN
#define red VGA_COLOR_RED
#define magenta VGA_COLOR_MAGENTA
#define brown VGA_COLOR_BROWN
#define lightGrey VGA_COLOR_LIGHT_GREY
#define darkGrey VGA_COLOR_DARK_GREY
#define lightBlue VGA_COLOR_LIGHT_BLUE
#define lightGreen VGA_COLOR_LIGHT_GREEN
#define lightCyan VGA_COLOR_LIGHT_CYAN
#define lightRed VGA_COLOR_LIGHT_RED
#define lightMagenta VGA_COLOR_LIGHT_MAGENTA
#define lightBrown VGA_COLOR_LIGHT_BROWN
#define white VGA_COLOR_WHITE
#define cl vga_entry_color

enum vga_color
{
	VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GREY = 7,
	VGA_COLOR_DARK_GREY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_LIGHT_MAGENTA = 13,
	VGA_COLOR_LIGHT_BROWN = 14,
	VGA_COLOR_WHITE = 15,
};

static inline uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg)
{
	return fg | bg << 4;
}

static inline uint16_t vga_entry(unsigned char uc, uint8_t color)
{
	return (uint16_t) uc | (uint16_t) color << 8;
}

#endif

#ifdef __cplusplus
}
#endif
