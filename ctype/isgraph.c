#if defined(__cplusplus)
extern "C" {
#endif

int isgraph(int c)
{
	return (unsigned)c-0x21 < 0x5e;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
