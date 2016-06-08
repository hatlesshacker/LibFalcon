# ***************************************
# **
# ***  Makefile for DuckLib
# **
# ***************************************

CC = gcc
AS = nasm
ASF = -f elf
CFLAGS = -nostdlib -nostdinc -I./include/ -std=gnu99
AR = ar
OBJS=

.PHONY: $(OBJS)

include ctype/makefile
include maths/makefile
include misc/makefile
include string/makefile
include stdlib/makefile
include kernel/makefile
include liballoc/makefile

all: $(OBJS)
	@$(AR) rcs libfalcon.a $(OBJS)
	@echo "Build Successfull."

%.o: %.c
	@echo "  CC       $@"
	@$(CC) $(CFLAGS) -c $< -o $@

%.o: %.asm
	@echo "  NASM     $@"
	@$(AS) $(ASF) $< -o $@

clean:
	rm -f $(OBJS) libfalcon.a
