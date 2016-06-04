#if defined(__cplusplus)
extern "C" {
#endif

#include <string.h>
#include <stdint.h>

void * memchr( const void * s, int c, size_t n )
{
    const uint8_t * p = (const uint8_t *) s;
    while ( n-- )
    {
        if ( *p == (uint8_t) c )
        {
            return (void *) p;
        }
        ++p;
    }
    return NULL;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
