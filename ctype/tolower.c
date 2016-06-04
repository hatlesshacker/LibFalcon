#if defined(__cplusplus)
extern "C" {
#endif

#include <ctype.h>
#include <stdint.h>
int32_t tolower(const int32_t c) {
  return isupper(c) ? 'a' + (c - 'A') : c; /* in the "C" locale */
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
