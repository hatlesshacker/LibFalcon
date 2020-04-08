AUTOMAKE_OPTIONS = foreign
lib_LIBRARIES = libfalcon.a
libfalcon_a_SOURCES = ctype/isalnum.c\
			ctype/isalpha.c\
			ctype/isascii.c\
			ctype/isblank.c\
			ctype/iscntrl.c\
			ctype/isdigit.c\
			ctype/isgraph.c\
			ctype/islower.c\
			ctype/isprint.c\
			ctype/ispunct.c\
			ctype/isspace.c\
			ctype/isupper.c\
			ctype/isxdigit.c\
			ctype/tolower.c\
			ctype/toupper.c\
			kernel/cpuvendor.c\
			kernel/inportb.c\
			kernel/inportl.c\
			kernel/inportw.c\
			kernel/int32-a.c\
			kernel/outportb.c\
			kernel/outportl.c\
			kernel/outportw.c\
			kernel/reboot.c\
			maths/acos.c\
			maths/add.c\
			maths/asin.c\
			maths/atan.c\
			maths/atan2.c\
			maths/cos.c\
			maths/div.c\
			maths/fabs.c\
			maths/fmod.c\
			maths/ldexp.c\
			maths/mod.c\
			maths/mul.c\
			maths/pow.c\
			maths/sin.c\
			maths/sqrt.c\
			maths/sqrtf.c\
			maths/sub.c\
			maths/tan.c\
			stdlib/abs.c\
			stdlib/atoi.c\
			stdlib/atol.c\
			stdlib/atoll.c\
			stdlib/bsearch.c\
			stdlib/div.c\
			stdlib/labs.c\
			stdlib/ldiv.c\
			stdlib/llabs.c\
			stdlib/lldiv.c\
			stdlib/rand.c\
			string/bcmp.c\
			string/bcopy.c\
			string/bzero.c\
			string/index.c\
			string/memchr.c\
			string/memcmp.c\
			string/memcpy.c\
			string/memmove.c\
			string/memset.c\
			string/printk.c\
			string/rindex.c\
			string/strcat.c\
			string/strchr.c\
			string/strcmp.c\
			string/strcoll.c\
			string/strcpy.c\
			string/strcspn.c\
			string/strlen.c\
			string/strncat.c\
			string/strncmp.c\
			string/strncpy.c\
			string/strnlen.c\
			string/strpbrk.c\
			string/strrchr.c\
			string/strspn.c\
			string/strstr.c\
			string/strtok.c\
			string/swab.c\
			string/vsprintf.c\
			kernel/cpuid.asm\
			kernel/cr.asm\
			kernel/int32-b.asm

AM_CFLAGS = -I$(top_srcdir)/libfalcon/ -ffreestanding -nostdlib -m32 -Wall -Wextra

nobase_include_HEADERS = 	libfalcon/bithack.h\
				libfalcon/bits.h\
				libfalcon/ctype.h\
				libfalcon/endian.h\
				libfalcon/float.h\
				libfalcon/kernel.h\
				libfalcon/libfalcon/liballoc.h\
				libfalcon/libfalcon/textmode.h\
				libfalcon/math.h\
				libfalcon/stdarg.h\
				libfalcon/stddef.h\
				libfalcon/stdint.h\
				libfalcon/stdlib.h\
				libfalcon/string.h

NASMFLAGS = @PACKAGE_NASMFLAGS@
NASM = /usr/bin/nasm

.asm.o:
	$(NASM) $(NASMFLAGS) $< -o $@
