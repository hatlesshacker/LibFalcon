#if defined(__cplusplus)
extern "C" {
#endif

#include <stdint.h>

uint16_t inportw (uint16_t port)
{
    uint16_t ret;
    asm volatile ("inw %1, %0" : "=a" (ret) : "dN" (port));
    return ret;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
