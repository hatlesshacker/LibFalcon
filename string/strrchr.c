#if defined(__cplusplus)
extern "C" {
#endif

#include <string.h>
char * strrchr( const char * s, int32_t c )
{
    size_t i = 0;
    while ( s[i++] );
    do
    {
        if ( s[--i] == (char) c )
        {
            return (char *) s + i;
        }
    } while ( i );
    return NULL;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
