#include <kernel/init.h>
#include <kernel/tty.h>
#include <kernel/memory.h>
#include <kernel/error.h>
#include <stdstructs/list.h>
#include <../arch/i386/vga.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdmath.h>
#include <hash.h>
#include <file.h>
#include <irfs.h>

bool askpassword()
{
	printf("Enter root password: ");
	string_t pwd = allocate(256);
	scan_strl(pwd);
	bool succ = streq(pwd, "*****"); // Ultra secure password
	deallocate(pwd, 256);
	return succ;
}

void start_sh(void);

void startInit()
{
	init_ramfs();
	start_sh();
}

void start_sh(void) // Ugly, I know
{
	list fl = get_fls();
	printf("Klosy shell 1.2 beta (kernel 1.4)\n");
	
	string_t s = allocate(256);
	string_t *spl;
	if (!s)
	{
		kerr("klsh: unable to allocate memory");
		
	}
	
	bool isroot = false;
	string_t user = "somebody";
	while (1)
	{
		printf("%o%s@klosy-klsh-1.4%o / %o%c ", cl(isroot ? red : lightGreen, black), isroot ? "root" : user, cl(lightBlue, black), cl(lightGrey, black), isroot ? '#' : '$');
		scan_strl(s);
		int cnt = 0;
		spl = split(s, &cnt);
		if (streq(spl[0], "exit"))
		{
			return;
		}
		else if (streq(spl[0], "cat"))
		{
			if (cnt != 2)
			{
				printf("Usage: cat <file>\n");
				continue;
			}
			string_t s2 = spl[1];
			list ls = fl;
			while (ls && ls->elem && ((file)(ls->elem))->name_hash != hash(s2))
			{
				ls = ls->next;
			}
			if (!ls || !ls->elem)
			{
				printf("File '%s' not found\n", s2);
				continue;
			}
			file fil = (file)(ls->elem);
			size_t sz = fil->size;
			char *buf = allocate(sz + 1);
			if (!buf)
				return;
			fread(fil, sz, buf);
			freset(fil);
			buf[sz] = 0;
			printf("%s", buf);
			deallocate(buf, sz + 1);
		}
		else if (streq(spl[0], "echo"))
		{
			if (cnt <= 1)
			{
				printf("Usage: echo <text1> [text2] ...\n");
				continue;
			}
			for (int i = 1; i < cnt; ++i)
			{
				printf("%s%c", spl[i], i == cnt - 1 ? '\n' : ' ');
			}
		}
		else if (streq(spl[0], "su"))
		{
			if (cnt != 2 && cnt != 1)
			{
				printf("Usage: su [user]\n");
				continue;
			}
			if (cnt == 1 || streq(spl[1], "root"))
			{
				if (!isroot)
				{
					bool succ = askpassword();
					if (!succ)
					{
						printf("root password incorrect, permission denied\n");
						continue;
					}
				}
				user = "root";
				isroot = true;
			}
			else
			{
				user = spl[1];
				isroot = false;
			}
		}
		else if (streq(spl[0], "whoami"))
		{
			if (cnt != 1)
			{
				printf("Usage: whoami\n");
				continue;
			}
			printf("%s\n", isroot ? "root" : user);
		}
		else if (streq(spl[0], "panic"))
		{
			if (cnt != 2)
			{
				printf("Usage: panic <reason>\n(Only one-word reasons supported)\n");
				continue;
			}
			if (!isroot)
			{
				printf("panic: operation not permitted\n");
				continue;
			}
			else
			{
				panic(spl[1]);
			}
		}
		else if (streq(spl[0], "epanic"))
		{
			if (cnt != 1)
			{
				printf("Usage: epanic\n");
				continue;
			}
			if (!isroot)
			{
				printf("epanic: operation not permitted\n");
				continue;
			}
			else
			{
				epanic();
			}
		}
		else if (streq(spl[0], "kc"))
		{
			while (true)
			{
				int sc = getScanCode();
				printf("%d: %d (%c)\n", sc, fromScanCode(sc), fromScanCode(sc));
			}
		}
		else if (streq(spl[0], "uc"))
		{
			update_cursor(24, 79);
			sleep(10000);
		}
		else if (streq(spl[0], "ls"))
		{
			list tempfl = fl;
			while (tempfl)
			{
				printf("%s\n", ((file)(tempfl->elem))->name);
				tempfl = tempfl->next;
			}
		}
		else
		{
			if (!streq(spl[0], ""))
			{
				printf("klsh: %s: unknown command\n", spl[0]);
			}
		}
	}
	
}
