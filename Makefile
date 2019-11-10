#  This File is Part of LibFalcon.
#
#  * Copyright (c) 2018, Syed Nasim
#    All rights reserved.
#
#    Redistribution and use in source and binary forms, with or without
#    modification, are permitted provided that the following conditions are met:
#
#    * Redistributions of source code must retain the above copyright notice, this
#      list of conditions and the following disclaimer.
#
#    * Redistributions in binary form must reproduce the above copyright notice,
#      this list of conditions and the following disclaimer in the documentation
#      and/or other materials provided with the distribution.
#
#    * Neither the name of LibFalcon nor the names of its
#      contributors may be used to endorse or promote products derived from
#      this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
# OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


CC = gcc
AS = nasm
ASF = -f elf
CFLAGS = -O0 -nostdlib -nostdinc -I./include/ -std=gnu99 -Wall -Wextra \
         -Wno-address -Wno-sign-compare -Wno-parentheses -Wno-unused-but-set-variable\
				 -Wno-pointer-sign
AR = ar
OBJS=

.PHONY: $(OBJS)

# IMPLEMENTED HOOKS: Remove them if you have your own code.
include hooks/textmode/makefile

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
