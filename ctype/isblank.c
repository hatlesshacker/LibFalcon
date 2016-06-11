#if defined(__cplusplus)
extern "C" {
#endif

#include <ctype.h>
int isblank(int c)
{
	return (c == ' ' || c == '\t');
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
