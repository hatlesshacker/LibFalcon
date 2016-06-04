#if defined(__cplusplus)
extern "C" {
#endif

#include <string.h>
int strcmp( const char * s1, const char * s2 )
{
    while ( ( *s1 ) && ( *s1 == *s2 ) )
    {
        ++s1;
        ++s2;
    }
    return ( *(uint8_t *)s1 - *(uint8_t *)s2 );
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
