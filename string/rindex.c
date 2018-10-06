

#if defined(__cplusplus)
extern "C" {
#endif

#include <string.h>
char* rindex(const char *s, int c)
{
	return strrchr(s, c);
}

#if defined(__cplusplus)
} 
#endif
