#if defined(__cplusplus)
extern "C" {
#endif

#include <string.h>
void * memset( void * s, int c, size_t n )
{
    uint8_t * p = (uint8_t *) s;
    while ( n-- )
    {
        *p++ = (uint8_t) c;
    }
    return s;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
