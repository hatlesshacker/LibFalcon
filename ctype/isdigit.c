#if defined(__cplusplus)
extern "C" {
#endif

#include <ctype.h>
#include <stdint.h>
int32_t isdigit(const int32_t c) {
  return c >= '0' && c <= '9';
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
