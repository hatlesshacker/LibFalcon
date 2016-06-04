#if defined(__cplusplus)
extern "C" {
#endif

#include <stdint.h>
#include <kernel.h>

/* keyboard interface IO port: data and control
   READ:   status port
   WRITE:  control register */
#define KBRD_INTRFC 0x64

/* keyboard interface bits */
#define KBRD_BIT_KDATA 0 /* keyboard data is in buffer (output buffer is empty) (bit 0) */
#define KBRD_BIT_UDATA 1 /* user data is in buffer (command buffer is empty) (bit 1) */

#define KBRD_IO 0x60 /* keyboard IO port */
#define KBRD_RESET 0xFE /* reset CPU command */

#define bit(n) (1<<(n)) /* Set bit n to 1 */

/* Check if bit n in flags is set */
#define check_flag(flags, n) ((flags) & bit(n))

void reboot()
{
    uint8_t temp;

    asm volatile ("cli"); /* disable all interrupts */

    /* Clear all keyboard buffers (output and command buffers) */
    do
    {
        temp = inportb(KBRD_INTRFC); /* empty user data */
        if (check_flag(temp, KBRD_BIT_KDATA) != 0)
            inportb(KBRD_IO); /* empty keyboard data */
    } while (check_flag(temp, KBRD_BIT_UDATA) != 0);

    outportb(KBRD_INTRFC, KBRD_RESET); /* pulse CPU reset line */
    loop:
    asm volatile ("hlt"); /* if that didn't work, halt the CPU */
    goto loop; /* But if a non maskable interrupt is received, halt again */
}

#if defined(__cplusplus)
} /* extern "C" */
#endif