#if defined(__cplusplus)
extern "C" {
#endif

#include <stdlib.h>
ldiv_t ldiv(long numerator, long denominator)
{
	return (ldiv_t){ numerator/denominator, numerator%denominator };
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
