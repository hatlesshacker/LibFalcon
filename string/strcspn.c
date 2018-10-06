

#if defined(__cplusplus)
extern "C" {
#endif

#include <string.h>
size_t strcspn( const char * s1, const char * s2 )
{
    size_t len = 0;
    const char * p;
    while ( s1[len] )
    {
        p = s2;
        while ( *p )
        {
            if ( s1[len] == *p++ )
            {
                return len;
            }
        }
        ++len;
    }
    return len;
}

#if defined(__cplusplus)
} 
#endif
