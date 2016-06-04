#ifndef _STRING_H
#define _STRING_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h> /* for NULL and size_t */
#include <stdint.h>

void* memchr(const void* s, int32_t c, size_t n);
int32_t memcmp(const void* s1, const void* s2, size_t n);
void* memcpy(void* restrict s1, const void* restrict s2, size_t n);
void* memmove(void* s1, const void* s2, size_t n);
void* memset(void* s, int32_t c, size_t n);
char* strcat(char* restrict s1, const char* restrict s2);
char* strchr(const char* s, int32_t c);
int32_t strcmp(const char* s1, const char* s2);
int32_t strcoll(const char* s1, const char* s2);
char* strcpy(char* restrict s1, const char* restrict s2);
size_t strcspn(const char* s1, const char* s2);
char* strerror(int32_t errnum);
size_t strlen(const char* s);
char* strncat(char* restrict s1, const char* restrict s2, size_t n);
int32_t strncmp(const char* s1, const char* s2, size_t n);
char* strncpy(char* restrict s1, const char* restrict s2, size_t n);
size_t strnlen(const char* s, size_t maxlen);
char* strpbrk(const char* s1, const char* s2);
char* strrchr(const char* s, int32_t c);
size_t strspn(const char* s1, const char* s2);
char* strstr(const char* s1, const char* s2);
char* strtok(char* restrict s1, const char* restrict s2);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _STRING_H */
