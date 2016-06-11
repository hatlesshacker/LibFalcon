#if defined(__cplusplus)
extern "C" {
#endif

#include <ctype.h>
int isascii(int c)
{
	return !(c&~0x7f);
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
