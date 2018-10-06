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

#ifndef _STDARG_H_
#define _STDARG_H_

#ifndef RC_INVOKED

#ifndef _VA_LIST_DEFINED
#define _VA_LIST_DEFINED
#endif

#ifndef _VA_LIST
#define _VA_LIST
typedef char *va_list;
#endif

#define __va_argsiz(t)                                                         \
  (((sizeof(t) + sizeof(int) - 1) / sizeof(int)) * sizeof(int))

#ifdef __GNUC__

#define va_start(ap, pN) ((ap) = ((va_list)__builtin_next_arg(pN)))
#else

#define va_start(ap, pN) ((ap) = ((va_list)(&pN) + __va_argsiz(pN)))
#endif

#define va_end(ap) ((void)0)

#define va_arg(ap, t)                                                          \
  (((ap) = (ap) + __va_argsiz(t)), *((t *)(void *)((ap)-__va_argsiz(t))))

#endif

#endif
