/*---------------------------------------------------------------------------*/
/* atoi() - convert a string to a signed short integer                       */
/*---------------------------------------------------------------------------*/

#if defined(__cplusplus)
extern "C" {
#endif

#include <stdlib.h>
int atoi(const char *string)
{
  return((int)atol(string));
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
