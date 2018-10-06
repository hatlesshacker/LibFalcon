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
#include <textmode.h>

void kputch(unsigned char c) {
  unsigned char cursor_x = get_cursor_x();
  unsigned char cursor_y = get_cursor_y();
  unsigned short *video_memory = get_video_memory();

  unsigned char backColour = 0;
  unsigned char foreColour = 15;
  unsigned char attributeByte = (backColour << 4) | (foreColour & 0x0F);
  unsigned short attribute = attributeByte << 8;
  unsigned short *location;

  if (c == 0x08 && cursor_x) {
    cursor_x--;
  } else if (c == 0x09) {
    cursor_x = (cursor_x + 8) & ~(8 - 1);
  }

  else if (c == '\r') {
    cursor_x = 0;
  }

  else if (c == '\n') {
    cursor_x = 0;
    cursor_y++;
  }

  else if (c >= ' ') {
    location = video_memory + (cursor_y * 80 + cursor_x);
    *location = c | attribute;
    cursor_x++;
  }
  if (cursor_x >= 80) {
    cursor_x = 0;
    cursor_y++;
  }

  scroll();
  move_cursor();
}
