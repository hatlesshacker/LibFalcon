

#if defined(__cplusplus)
extern "C" {
#endif

#include <string.h>
void bcopy(const void *s1, void *s2, size_t n)
{
	memmove(s2, s1, n);
}

#if defined(__cplusplus)
} 
#endif
