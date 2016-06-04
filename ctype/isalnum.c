#if defined(__cplusplus)
extern "C" {
#endif

#include <ctype.h>
#include <stdint.h>
int32_t isalnum(const int32_t c) {
  return isalpha(c) || isdigit(c);
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
