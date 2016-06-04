#if defined(__cplusplus)
extern "C" {
#endif

#include <ctype.h>
#include <stdint.h>
int32_t toupper(const int32_t c) {
  return islower(c) ? 'A' + (c - 'a') : c; /* in the "C" locale */
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
