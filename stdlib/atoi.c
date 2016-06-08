#if defined(__cplusplus)
extern "C" {
#endif

#include <stdlib.h>
#include <ctype.h>
    int32_t atoi(const uint8_t* s)
    {
        int32_t n=0, neg=0;
        while (isspace(*s)) s++;
        switch (*s)
        {
        case '-':
            neg=1;
        case '+':
            s++;
        }
        /* Compute n as a negative number to avoid overflow on INT_MIN */
        while (isdigit(*s))
            n = 10*n - (*s++ - '0');
        return neg ? n : -n;
    }

#if defined(__cplusplus)
} /* extern "C" */
#endif
