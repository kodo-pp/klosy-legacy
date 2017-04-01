.PHONY: all run iso clean irfs
all: run
irfs:
	./initramfs.sh
iso: clean irfs iso.sh
	./iso.sh
run: iso
	./qemu.sh
clean:
	./clean.sh
