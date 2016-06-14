#define max(a,b)        (((a) > (b)) ? (a) : (b))
#define min(a,b)        (((a) < (b)) ? (a) : (b))

#include <stdint.h>
#include <stddef.h>

long atol(const char*);
int atoi(const char*);
int abs(int);
void *bsearch(const void* , const void* , size_t, size_t , int (*cmp)(const void *, const void *));
long long atoll(const char*);
long long llabs(long long);
long labs(long);
