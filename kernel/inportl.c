#if defined(__cplusplus)
extern "C" {
#endif

unsigned int inportl(unsigned short __port)
{
	unsigned int __val;
	__asm__ volatile ("inl %1,%0" : "=a" (__val) : "dN" (__port));
	return __val;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
