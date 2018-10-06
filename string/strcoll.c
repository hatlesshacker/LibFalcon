

#if defined(__cplusplus)
extern "C" {
#endif

#include <string.h>
#include <stdint.h>
int32_t strcoll(const char *s1, const char *s2)
{
	return strcmp(s1, s2);
}

#if defined(__cplusplus)
} 
#endif
