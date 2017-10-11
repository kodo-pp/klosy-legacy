#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <keyboard.h>

#include <kernel/tty.h>

#include "vga.h"

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
static uint16_t* const VGA_MEMORY = (uint16_t*) 0xB8000;

static size_t terminal_row;
static size_t terminal_column;
static uint8_t terminal_color;
static uint16_t* terminal_buffer;

void update_cursor(int row, int col) // by Dark Fiber
{
	unsigned short position=(row*80) + col;
	// cursor LOW port to vga INDEX register
	outb(0x3D4, 0x0F);
	outb(0x3D5, (unsigned char)(position&0xFF));
	// cursor HIGH port to vga INDEX register
	outb(0x3D4, 0x0E);
	outb(0x3D5, (unsigned char )((position>>8)&0xFF));
}
 
size_t terminal_index(size_t x, size_t y)
{
	return y * VGA_WIDTH + x;
}

void terminal_clear()
{
	terminal_row = terminal_column = 0;
	for (size_t i = 0; i < VGA_HEIGHT; ++i)
		for (size_t j = 0; j < VGA_WIDTH; ++j)
			terminal_putchar(0);
	terminal_row = terminal_column = 0;
}

void terminal_initialize(void)
{
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	terminal_buffer = VGA_MEMORY;
	for (size_t y = 0; y < VGA_HEIGHT; y++)
	{
		for (size_t x = 0; x < VGA_WIDTH; x++)
		{
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}

void terminal_setcolor(uint8_t color) {
	terminal_color = color;
}

void terminal_putentryat(unsigned char c, uint8_t color, size_t x, size_t y) {
	const size_t index = terminal_index(x, y);
	terminal_buffer[index] = vga_entry(c, color);
}

void terminal_putchar(char c) {
	unsigned char uc = c;
	if (uc == '\n') // newline
	{
		if (++terminal_row == VGA_HEIGHT)
		{
			scroll();
			--terminal_row; // because it points to the line after the last line
		}
		terminal_column = -1; // it will be increased later
	}
	else if (uc == '\b') // backspace
	{
		if (terminal_column != 0) // if we can do it
		{
			terminal_putentryat('\0', terminal_color, terminal_column-1, terminal_row); // erase current character
			--terminal_column; // move cursor one char left
		}
		--terminal_column; // it will be increased later but we don't need it
	}
	else // anything else
	{
		terminal_putentryat(uc, terminal_color, terminal_column, terminal_row);
	}
	if (++terminal_column == VGA_WIDTH) // move cursor one char right and check whether we came to the end of line (EOL)
	{
		terminal_column = 0;
		if (++terminal_row == VGA_HEIGHT) // if it was the last line and we are pointing now to the line which doesn't exist
		{
			scroll();
			--terminal_row;
		}
	}
	update_cursor(terminal_row >= VGA_HEIGHT-1 ? VGA_HEIGHT-2 : terminal_row, terminal_column >= VGA_WIDTH-1 ? VGA_WIDTH-2 : terminal_column);
}

void terminal_write(const char* data, size_t size) // calls terminal_putchar() for every character in the string
{
	for (size_t i = 0; i < size; i++)
		terminal_putchar(data[i]);
	terminal_putentryat(0, terminal_color, terminal_column, terminal_row);
	update_cursor(terminal_row >= VGA_HEIGHT ? 24 : terminal_row, terminal_column >= VGA_WIDTH ? 79 : terminal_column);
}

void terminal_writestring(const char* data) // calls terminal_write() but determines the string length by itself
{
	terminal_write(data, strlen(data));
}

void scroll() // moves each char in terminal one line up and fills the last line with '\0'
{
	for (size_t x = 0; x < VGA_WIDTH; ++x)
	{
		for (size_t y = 0; y < VGA_HEIGHT - 1; ++y)
		{
			size_t src_index = terminal_index(x, y + 1),
			       dst_index = terminal_index(x, y);
			terminal_buffer[dst_index] = terminal_buffer[src_index];
		}
		terminal_buffer[terminal_index(x, VGA_HEIGHT - 1)] = '\0';
	}
}

void terminal_position(int x, int y)
{
	terminal_row = y;
	terminal_column = x;
}
