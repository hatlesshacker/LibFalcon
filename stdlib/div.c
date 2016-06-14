#if defined(__cplusplus)
extern "C" {
#endif

#include <stdlib.h>
#include <stdint.h>
div_t div(int32_t numerator, int32_t denominator)
{
	return (div_t){ numerator/denominator, numerator%denominator };
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
