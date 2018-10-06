

#if defined(__cplusplus)
extern "C" {
#endif

#include <string.h>
#include <stddef.h>
char * strtok( char * restrict s1, const char * restrict s2 )
{
    static char * tmp = NULL;
    const char * p = s2;

    if ( s1 != NULL )
    {
        tmp = s1;
    }
    else
    {
        if ( tmp == NULL )
        {
            return NULL;
        }
        s1 = tmp;
    }

    while ( *p && *s1 )
    {
        if ( *s1 == *p )
        {
            ++s1;
            p = s2;
            continue;
        }
        ++p;
    }

    if ( ! *s1 )
    {
        return ( tmp = NULL );
    }

    tmp = s1;
    while ( *tmp )
    {
        p = s2;
        while ( *p )
        {
            if ( *tmp == *p++ )
            {
                *tmp++ = '\0';
                return s1;
            }
        }
        ++tmp;
    }

    tmp = NULL;
    return s1;
}

#if defined(__cplusplus)
} 
#endif
