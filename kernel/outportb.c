#if defined(__cplusplus)
extern "C" {
#endif

void outportb (unsigned short _port, unsigned char _data)
{
    asm volatile ("outb %1, %0" : : "dN" (_port), "a" (_data));
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
