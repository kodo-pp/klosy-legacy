#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <keyboard.h>
#include <time.h>
#include <portio.h>

//const int kbd_sleep_cycles = 1200000;

//void outb(uint16_t port, uint8_t val)
//{
//    asm volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
//    /* There's an outb %al, $imm8  encoding, for compile-time constant port numbers that fit in 8b.  (N constraint).
//     * Wider immediate constants would be truncated at assemble-time (e.g. "i" constraint).
//     * The  outb  %al, %dx  encoding is the only option for all other cases.
//     * %1 expands to %dx because  port  is a uint16_t.  %w1 could be used if we had the port number a wider C type */
//}

//uint8_t inb(uint16_t port)
//{
//    uint8_t ret;
//    asm volatile ( "inb %1, %0"
//                   : "=a"(ret)
//                   : "Nd"(port) );
//    return ret;
//}

/*
PS/2 keyboard code.
Dependencies:
inb function and scancode table.
*/
char getScanCode()
{
	char c = 0;
	do
	{
		if (inb(0x60) != c)
		{
			c = inb(0x60);
			if (c > 0)
			return c;
		}
	}
	while (1);
}

void kbd_sleep()
{
	sleep(350);
}

int fromScanCode(int scancode)
{
	switch(scancode) // Дальше длиииинное switch-case выражение
	{
		case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: return scancode - 1 + '0'; break;
		case 11: return '0';  break;
		case 12: return '-';  break;
		case 13: return '=';  break;
		case 14: return '\b'; break;
		case 16: return 'q';  break;
		case 17: return 'w';  break;
		case 18: return 'e';  break;
		case 19: return 'r';  break;
		case 20: return 't';  break;
		case 21: return 'y';  break;
		case 22: return 'u';  break;
		case 23: return 'i';  break;
		case 24: return 'o';  break;
		case 25: return 'p';  break;
		case 26: return '[';  break;
		case 27: return ']';  break;
		case 28: return '\n'; break;
		case 30: return 'a';  break;
		case 31: return 's';  break;
		case 32: return 'd';  break;
		case 33: return 'f';  break;
		case 34: return 'g';  break;
		case 35: return 'h';  break;
		case 36: return 'j';  break;
		case 37: return 'k';  break;
		case 38: return 'l';  break;
		case 39: return ';';  break;
		case 40: return '\''; break;
		case 43: return '\\'; break;
		case 44: return 'z';  break;
		case 46: return 'c';  break;
		case 45: return 'x';  break;
		case 47: return 'v';  break;
		case 48: return 'b';  break; // 你為什麼讀它？
		case 49: return 'n';  break;
		case 50: return 'm';  break;
		case 51: return ',';  break;
		case 52: return '.';  break;
		case 53: return '/';  break;
		case 55: return '*';  break;
		case 57: return ' ';  break;
		case 78: return '+';  break;
		case 74: return '-';  break;
		case 72: return '^' | 0x0100; break;
		case 75: return '<' | 0x0100; break;
		case 80: return 'v' | 0x0100; break;
		case 77: return '>' | 0x0100; break;
		case 1:  return 'e' | 0x0100; break;
		case 42: return 'A' | 0x0200; break;
		case 54: return 'B' | 0x0200; break;
		
		default: return scancode; break;
	}
	return '0';
}

int filter(int ch)
{
	if (ch == ('A' | 0x0200) || ch == ('B' | 0x0200))
		return ch;
	if (ch & 0xFF00)
		return 0xFFFF;
	return ch;
}

int schar(int c)
{
	if ((c & SCR) && (c & SCL) && (c & SCU) && (c & SCD) && (c & SCDH) && (c & SCDV)) 	return 206;
	if ((c & SCR) && (c & SCL) && (c & SCU) && (c & SCD) && (c & SCDH)) 				return 216;
	if ((c & SCR) && (c & SCL) && (c & SCU) && (c & SCD) && (c & SCDV)) 				return 215;
	if ((c & SCR) && (c & SCL) && (c & SCU) && (c & SCD)) 								return 197;
	
	
	
	if ((c & SCR) && (c & SCL) && (c & SCU) && (c & SCDH) && (c & SCDV))				return 202;
	if ((c & SCR) && (c & SCL) && (c & SCU) && (c & SCDH)) 								return 207;
	if ((c & SCR) && (c & SCL) && (c & SCU) && (c & SCDV)) 								return 208;
	if ((c & SCR) && (c & SCL) && (c & SCU)) 											return 193;
	
	if ((c & SCR) && (c & SCL) && (c & SCD) && (c & SCDH) && (c & SCDV)) 				return 203;
	if ((c & SCR) && (c & SCL) && (c & SCD) && (c & SCDH))								return 209;
	if ((c & SCR) && (c & SCL) && (c & SCD) && (c & SCDV)) 								return 210;
	if ((c & SCR) && (c & SCL) && (c & SCD))											return 194;
	
	if ((c & SCR) && (c & SCU) && (c & SCD) && (c & SCDH) && (c & SCDV)) 				return 204;
	if ((c & SCR) && (c & SCU) && (c & SCD) && (c & SCDH)) 								return 198;
	if ((c & SCR) && (c & SCU) && (c & SCD) && (c & SCDV)) 								return 199;
	if ((c & SCR) && (c & SCU) && (c & SCD)) 											return 195;
	
	if ((c & SCL) && (c & SCU) && (c & SCD) && (c & SCDH) && (c & SCDV)) 				return 185;
	if ((c & SCL) && (c & SCU) && (c & SCD) && (c & SCDH)) 								return 181;
	if ((c & SCL) && (c & SCU) && (c & SCD) && (c & SCDV)) 								return 182;
	if ((c & SCL) && (c & SCU) && (c & SCD)) 											return 180;
	
	
	
	
	if ((c & SCL) && (c & SCU) && (c & SCDH) && (c & SCDV)) 							return 188;
	if ((c & SCL) && (c & SCU) && (c & SCDH)) 											return 190;
	if ((c & SCL) && (c & SCU) && (c & SCDV)) 											return 189;
	if ((c & SCL) && (c & SCU)) 														return 217;
	
	if ((c & SCR) && (c & SCU) && (c & SCDH) && (c & SCDV)) 							return 200;
	if ((c & SCR) && (c & SCU) && (c & SCDH)) 											return 212;
	if ((c & SCR) && (c & SCU) && (c & SCDV)) 											return 211;
	if ((c & SCR) && (c & SCU)) 														return 192;
	
	if ((c & SCR) && (c & SCD) && (c & SCDH) && (c & SCDV)) 							return 218;
	if ((c & SCR) && (c & SCD) && (c & SCDH)) 											return 213;
	if ((c & SCR) && (c & SCD) && (c & SCDV)) 											return 214;
	if ((c & SCR) && (c & SCD)) 														return 218;
	
	if ((c & SCL) && (c & SCD) && (c & SCDH) && (c & SCDV)) 							return 187;
	if ((c & SCL) && (c & SCD) && (c & SCDH)) 											return 184;
	if ((c & SCL) && (c & SCD) && (c & SCDV)) 											return 183;
	if ((c & SCL) && (c & SCD)) 														return 191;
	
	
	
	if ((c & SCL) && (c & SCR) && (c & SCDH))				 							return 205;
	if ((c & SCL) && (c & SCR))								 							return 196;
	if ((c & SCU) && (c & SCD) && (c & SCDV))				 							return 186;
	if ((c & SCU) && (c & SCD))								 							return 179;
	
	return 1;
}
