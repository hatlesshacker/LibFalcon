

#if defined(__cplusplus)
extern "C" {
#endif

#include <string.h>
void bzero(void *s, size_t n)
{
	memset(s, 0, n);
}

#if defined(__cplusplus)
} 
#endif
