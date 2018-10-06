

#if defined(__cplusplus)
extern "C" {
#endif

#include <string.h>
#include <stdint.h>
size_t strnlen(const char *s, size_t n)
{
	const char *p = memchr(s, 0, n);
	return p ? p-s : n;
}

#if defined(__cplusplus)
} 
#endif
