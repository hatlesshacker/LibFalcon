#if defined(__cplusplus)
extern "C" {
#endif

#include <stdlib.h>
lldiv_t lldiv(long long numerator, long long denominator)
{
	return (lldiv_t){ numerator/denominator, numerator%denominator };
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
