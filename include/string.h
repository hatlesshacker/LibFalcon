/* This File is Part of LibFalcon.

 * Copyright (c) 2016, Syed Nasim
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

#ifndef _STRING_H
#define _STRING_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h> /* for NULL and size_t */
#include <stdarg.h>
#include <stdint.h>

void* memchr(const void*, int32_t, size_t);
int32_t memcmp(const void* , const void* , size_t);
void* memcpy(void* restrict , const void* restrict , size_t);
void* memmove(void*, const void* , size_t);
void* memset(void*, int32_t c, size_t);
char* strcat(char* restrict , const char* restrict);
char* strchr(const char* , int32_t);
int32_t strcmp(const char* , const char*);
int32_t strcoll(const char* , const char*);
char* strcpy(char* restrict , const char* restrict);
size_t strcspn(const char* , const char*);
char* strerror(int32_t errnum);
size_t strlen(const char* );
size_t strnlen(const char*, size_t);
char* strncat(char* restrict , const char* restrict , size_t);
int32_t strncmp(const char*,const char* ,size_t);
char* strncpy(char* restrict,const char* restrict,size_t);
size_t strnlen(const char*,size_t);
char* strpbrk(const char*,const char*);
char* strrchr(const char*,int32_t);
size_t strspn(const char*,const char*);
char* strstr(const char*,const char*);
char* strtok(char* restrict,const char* restrict);
int32_t strcoll(const char*, const char*);
void bzero(void*, size_t);
void bcopy(const void*, void*, size_t);
int bcmp(const void*, const void*, size_t);
char* index(const char*, int);
char* rindex(const char*, int);
int vsprintf(char *buf, const char *fmt, va_list args);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _STRING_H */
