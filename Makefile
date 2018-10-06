# ***************************************
# **
# ***  Makefile for DuckLib
# **
# ***************************************

CC = gcc-6
AS = nasm
ASF = -f elf
CFLAGS = -O0 -nostdlib -nostdinc -I./include/ -std=gnu99 -Wall -Wextra \
         -Wno-address -Wno-sign-compare
AR = ar
OBJS=
DESTDIR=
with-liballoc=yes

.PHONY: $(OBJS)

include ctype/makefile
include maths/makefile
include string/makefile
include stdlib/makefile
include kernel/makefile

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
	rm -f $(OBJS) libfalcon.a
