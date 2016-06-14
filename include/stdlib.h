#define max(a,b)        (((a) > (b)) ? (a) : (b))
#define min(a,b)        (((a) < (b)) ? (a) : (b))

#include <stdint.h>
#include <stddef.h>

typedef struct { int quot, rem; } div_t;
typedef struct { long quot, rem; } ldiv_t;
typedef struct { long long quot, rem; } lldiv_t;

long atol(const char*);
int atoi(const char*);
int abs(int);
void *bsearch(const void* , const void* , size_t, size_t , int (*cmp)(const void *, const void *));
long long atoll(const char*);
long long llabs(long long);
long labs(long);
lldiv_t lldiv(long long, long long);
ldiv_t ldiv(long, long);
div_t div(int32_t, int32_t);
