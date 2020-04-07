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

#ifndef BITHACKS_H
#define BITHACKS_H

#define HEXIFY(X) 0x##X##LU

#define B8IFY(Y)                                                               \
  (((Y & 0x0000000FLU) ? 1 : 0) + ((Y & 0x000000F0LU) ? 2 : 0) +               \
   ((Y & 0x00000F00LU) ? 4 : 0) + ((Y & 0x0000F000LU) ? 8 : 0) +               \
   ((Y & 0x000F0000LU) ? 16 : 0) + ((Y & 0x00F00000LU) ? 32 : 0) +             \
   ((Y & 0x0F000000LU) ? 64 : 0) + ((Y & 0xF0000000LU) ? 128 : 0))

#define B8(Z) ((unsigned char)B8IFY(HEXIFY(Z)))

#define B_EVEN(x) (((x)&1) == 0)

#define B_ODD(x) (!B_EVEN((x)))

#define B_IS_SET(x, n) (((x) & (1 << (n))) ? 1 : 0)

#define B_SET(x, n) ((x) |= (1 << (n)))

#define B_UNSET(x, n) ((x) &= ~(1 << (n)))

#define B_TOGGLE(x, n) ((x) ^= (1 << (n)))

#define B_TURNOFF_1(x) ((x) &= ((x)-1))

#define B_ISOLATE_1(x) ((x) &= (-(x)))

#define B_PROPAGATE_1(x) ((x) |= ((x)-1))

#define B_ISOLATE_0(x) ((x) = ~(x) & ((x) + 1))

#define B_TURNON_0(x) ((x) |= ((x) + 1))

#endif
