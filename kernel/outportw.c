#if defined(__cplusplus)
extern "C" {
#endif

#include <stdint.h>

inline void outportw (unsigned short _port, uint16_t _data)
{
    asm volatile ("outw %1, %0" : : "dN" (_port), "a" (_data));
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
