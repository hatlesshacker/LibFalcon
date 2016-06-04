#if defined(__cplusplus)
extern "C" {
#endif

#include <ctype.h>
#include <stdint.h>
int32_t ispunct(const int32_t c) {
  return isprint32_t(c) && !isspace(c) && !isalnum(c);
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
