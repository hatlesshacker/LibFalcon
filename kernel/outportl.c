#if defined(__cplusplus)
extern "C" {
#endif

void outportl(unsigned int __val, unsigned short __port)
{
	__asm__ volatile ("outl %0,%1" : : "a" (__val), "dN" (__port));
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
