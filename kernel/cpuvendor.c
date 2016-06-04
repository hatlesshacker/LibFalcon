#if defined(__cplusplus)
extern "C" {
#endif

#include <kernel.h>
char* get_cpuvendor()
{
    switch(__get_cpuvendor())
    {
    case 0x756e6547: /* Intel */
        return "INTEL";
        break;
    case 0x68747541: /* AMD */
        return "AMD";
        break;
    default:
        return "UNKNOWN";
        break;
    }
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
