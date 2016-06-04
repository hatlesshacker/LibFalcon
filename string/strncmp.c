#if defined(__cplusplus)
extern "C" {
#endif

#include <string.h>
int strncmp( const char * s1, const char * s2, size_t n )
{
    while ( *s1 && n && ( *s1 == *s2 ) )
    {
        ++s1;
        ++s2;
        --n;
    }
    if ( ( n == 0 ) )
    {
        return 0;
    }
    else
    {
        return ( *(uint8_t *)s1 - *(uint8_t *)s2 );
    }
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
