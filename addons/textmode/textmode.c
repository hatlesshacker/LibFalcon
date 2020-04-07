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

#include <kernel.h>
#include <stdint.h>
#include <libfalcon/textmode.h>

unsigned short *video_memory = (unsigned short *)0xB8000;
unsigned char cursor_x = 0;
unsigned char cursor_y = 0;

unsigned char LF_get_cursor_y() {
    return cursor_y;
}
unsigned char LF_get_cursor_x() {
    return cursor_x;
}
unsigned short *LF_get_video_memory() {
    return video_memory;
}

void LF_move_cursor() {
    unsigned short cursorLocation = cursor_y * 80 + cursor_x;
    outportb(0x3D4, 14);
    outportb(0x3D5, cursorLocation >> 8);
    outportb(0x3D4, 15);
    outportb(0x3D5, cursorLocation);
}

void LF_scroll() {

    unsigned char attributeByte = (0 << 4) | (15 & 0x0F);
    unsigned short blank = 0x20 | (attributeByte << 8);

    if (cursor_y >= 25) {

        int i;
        for (i = 0 * 80; i < 24 * 80; i++) {
            video_memory[i] = video_memory[i + 80];
        }

        for (i = 24 * 80; i < 25 * 80; i++) {
            video_memory[i] = blank;
        }

        cursor_y = 24;
    }
}
