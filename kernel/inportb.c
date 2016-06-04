#if defined(__cplusplus)
extern "C" {
#endif

unsigned char inportb (unsigned short port)
{
    unsigned char rv;
    asm volatile ("inb %1, %0" : "=a" (rv) : "dN" (port));
    return rv;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
