

#if defined(__cplusplus)
extern "C" {
#endif

#include <string.h>
char * strncpy( char * restrict s1, const char * restrict s2, size_t n )
{
    char * rc = s1;
    while ( ( n > 0 ) && ( *s1++ = *s2++ ) )
    {
        --n;
    }
    while ( n-- > 1 )
    {
        *s1++ = '\0';
    }
    return rc;
}

#if defined(__cplusplus)
} 
#endif
