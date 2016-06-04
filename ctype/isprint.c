#if defined(__cplusplus)
extern "C" {
#endif

#include <ctype.h>
#include <stdint.h>
int32_t isprint32_t(const int32_t c) {
  return c >= 0x20 && c <= 0x7E;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
