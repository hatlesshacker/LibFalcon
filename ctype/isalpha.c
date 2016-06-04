#if defined(__cplusplus)
extern "C" {
#endif

#include <ctype.h>
#include <stdint.h>
int32_t isalpha(const int32_t c) {
  return isupper(c) || islower(c);
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
