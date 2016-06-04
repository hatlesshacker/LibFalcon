#if defined(__cplusplus)
extern "C" {
#endif

#include <string.h>
char * strncat( char * restrict s1, const char * restrict s2, size_t n )
{
    char * rc = s1;
    while ( *s1 )
    {
        ++s1;
    }
    while ( n && ( *s1++ = *s2++ ) )
    {
        --n;
    }
    if ( n == 0 )
    {
        *s1 = '\0';
    }
    return rc;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
