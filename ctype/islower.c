#if defined(__cplusplus)
extern "C" {
#endif

#include <ctype.h>
#include <stdint.h>
int32_t islower(const int32_t c) {
  return c >= 'a' && c <= 'z';
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
