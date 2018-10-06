

#if defined(__cplusplus)
extern "C" {
#endif

#include <string.h>
size_t strlen( const char * s )
{
    size_t rc = 0;
    while ( s[rc] )
    {
        ++rc;
    }
    return rc;
}

#if defined(__cplusplus)
} 
#endif
