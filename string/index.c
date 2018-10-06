

#if defined(__cplusplus)
extern "C" {
#endif

#include <string.h>
char* index(const char *s, int c)
{
	return strchr(s, c);
}

#if defined(__cplusplus)
} 
#endif
