all: run
iso: clean iso.sh
	./iso.sh
run: iso
	./qemu.sh
clean:
	./clean.sh
