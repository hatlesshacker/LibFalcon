/* This File is Part of LibFalcon.

 * Copyright (c) 2018, Syed Nasim
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright notice, this
     list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright notice,
     this list of conditions and the following disclaimer in the documentation
     and/or other materials provided with the distribution.

   * Neither the name of LibFalcon nor the names of its
     contributors may be used to endorse or promote products derived from
     this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#if defined(__cplusplus)
extern "C" {
#endif

#include <stdint.h>
#include <kernel.h>


#define KBRD_INTRFC 0x64


#define KBRD_BIT_KDATA 0
#define KBRD_BIT_UDATA 1

#define KBRD_IO 0x60
#define KBRD_RESET 0xFE

#define bit(n) (1<<(n))


#define check_flag(flags, n) ((flags) & bit(n))

inline void reboot()
{
    uint8_t temp;

    asm volatile ("cli");


    do
    {
        temp = inportb(KBRD_INTRFC);
        if (check_flag(temp, KBRD_BIT_KDATA) != 0)
            inportb(KBRD_IO);
    } while (check_flag(temp, KBRD_BIT_UDATA) != 0);

    outportb(KBRD_INTRFC, KBRD_RESET);
    loop:
    asm volatile ("hlt");
    goto loop;
}

#if defined(__cplusplus)
}
#endif
