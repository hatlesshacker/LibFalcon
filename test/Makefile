CC = gcc
CFLAGS = -m32 -nostdlib -nostdinc -w -I ../OUT/include
AS = nasm
ASF = -f elf
LINKER = ld 
LINKERFLAGS = -m elf_i386 -T link.ld
EMU = qemu-system-i386

## **** The kernel bootable image ****
kernel.iso : kernel.bin grub.cfg
	echo "** Creating Bootable Image.."
	mkdir -p isodir
	mkdir -p isodir/boot
	cp kernel.bin isodir/boot/kernel.bin
	mkdir -p isodir/boot/grub
	cp grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o kernel.iso isodir
	echo "** Build Successfull."

kernel.bin: link.ld objs
	echo "** Linking Stuffs Together.."
	$(LINKER) $(LINKERFLAGS) -o kernel.bin boot.o kernel.o ../OUT/libfalcon.a

objs:
	@$(CC) $(CFLAGS) -c kernel.c -o kernel.o
	@$(AS) $(ASF) boot.asm -o boot.o

clean:
	rm -rf isodir *.o *.bin *.iso

test: kernel.iso
	echo "** Testing Nasix with qemu."
	$(EMU) -cdrom kernel.iso