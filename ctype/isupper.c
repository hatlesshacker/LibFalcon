#if defined(__cplusplus)
extern "C" {
#endif

#include <ctype.h>
#include <stdint.h>
int32_t isupper(const int32_t c) {
  return c >= 'A' && c <= 'Z';
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
