#if defined(__cplusplus)
extern "C" {
#endif

long labs(long a)
{
	return a>0 ? a : -a;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
