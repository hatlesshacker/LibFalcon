#if defined(__cplusplus)
extern "C" {
#endif

#include <string.h>
#include <stdint.h>
int memcmp( const void * s1, const void * s2, size_t n )
{
    const uint8_t * p1 = (const uint8_t *) s1;
    const uint8_t * p2 = (const uint8_t *) s2;
    while ( n-- )
    {
        if ( *p1 != *p2 )
        {
            return *p1 - *p2;
        }
        ++p1;
        ++p2;
    }
    return 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
