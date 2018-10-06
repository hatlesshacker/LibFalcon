#define SETBITS(mem, bits) (mem) |= (bits)
#define CLEARBITS(mem, bits) (mem) &= ~(bits)
#define BIN(b7, b6, b5, b4, b3, b2, b1, b0)                                    \
  (unsigned char)(((b7) << 7) + ((b6) << 6) + ((b5) << 5) + ((b4) << 4) +      \
                  ((b3) << 3) + ((b2) << 2) + ((b1) << 1) + ((b0) << 0))
