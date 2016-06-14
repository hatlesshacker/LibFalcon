#ifndef _STRING_H
#define _STRING_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h> /* for NULL and size_t */
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

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _STRING_H */
