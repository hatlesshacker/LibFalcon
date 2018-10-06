

#if defined(__cplusplus)
extern "C" {
#endif

#include <string.h>
void * memcpy( void * restrict s1, const void * restrict s2, size_t n )
{
    char * dest = (char *) s1;
    const char * src = (const char *) s2;
    while ( n-- )
    {
        *dest++ = *src++;
    }
    return s1;
}

#if defined(__cplusplus)
} 
#endif
