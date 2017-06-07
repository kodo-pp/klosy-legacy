.PHONY: all run iso clean irfs
all: run
irfs: etc/bin2hex
	./initramfs.sh
etc/bin2hex: etc/bin2hex.cpp
	g++ etc/bin2hex.cpp -o etc/bin2hex -Wall -O2
iso: clean irfs iso.sh
	./iso.sh
run: iso
	./qemu.sh
clean:
	./clean.sh
