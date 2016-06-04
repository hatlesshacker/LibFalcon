#if defined(__cplusplus)
extern "C" {
#endif

#include <string.h>
char * strncpy( char * restrict s1, const char * restrict s2, size_t n )
{
    char * rc = s1;
    while ( ( n > 0 ) && ( *s1++ = *s2++ ) )
    {
        /* Cannot do "n--" in the conditional as size_t is unsigned and we have
           to check it again for >0 in the next loop below, so we must not risk
           underflow.
        */
        --n;
    }
    /* Checking against 1 as we missed the last --n in the loop above. */
    while ( n-- > 1 )
    {
        *s1++ = '\0';
    }
    return rc;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
