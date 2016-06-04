#if defined(__cplusplus)
extern "C" {
#endif

#include <ctype.h>
#include <stdint.h>
int32_t isspace(const int32_t c) {
  switch (c) { /* in the "C" locale: */
    case ' ':  /* space */
    case '\f': /* form feed */
    case '\n': /* new-line */
    case '\r': /* carriage return */
    case '\t': /* horizontal tab */
    case '\v': /* vertical tab */
      return 1;
    default:
      return 0;
  }
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
