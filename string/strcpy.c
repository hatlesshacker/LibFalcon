

#if defined(__cplusplus)
extern "C" {
#endif

#include <string.h>
char * strcpy( char * restrict s1, const char * restrict s2 )
{
    char * rc = s1;
    while ( ( *s1++ = *s2++ ) );
    return rc;
}

#if defined(__cplusplus)
} 
#endif
