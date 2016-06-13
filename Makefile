# ***************************************
# **
# ***  Makefile for DuckLib
# **
# ***************************************

CC = gcc
AS = nasm
ASF = -f elf
CFLAGS = -O0 -nostdlib -nostdinc -I./include/ -std=gnu99
AR = ar
OBJS=
DESTDIR=
WITH_LIBALLOC=0

.PHONY: $(OBJS)

include ctype/makefile
include maths/makefile
include string/makefile
include stdlib/makefile
include kernel/makefile

ifeq ("$(WITH_LIBALLOC)" , "1")
   include externals/liballoc/makefile
endif

all: $(OBJS)
	@$(AR) rcs libfalcon.a $(OBJS)
	@echo "Build Successfull."

%.o: %.c
	@echo "  CC       $@"
	@$(CC) $(CFLAGS) -c $< -o $@

%.o: %.asm
	@echo "  NASM     $@"
	@$(AS) $(ASF) $< -o $@

test:
	@echo "Test suite not available!"

clean:
	rm -f $(OBJS) libfalcon.a externals/liballoc/*.o
