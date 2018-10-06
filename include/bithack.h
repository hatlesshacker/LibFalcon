

#ifndef BITHACKS_H
#define BITHACKS_H

#define HEXIFY(X) 0x##X##LU

#define B8IFY(Y)                                                               \
  (((Y & 0x0000000FLU) ? 1 : 0) + ((Y & 0x000000F0LU) ? 2 : 0) +               \
   ((Y & 0x00000F00LU) ? 4 : 0) + ((Y & 0x0000F000LU) ? 8 : 0) +               \
   ((Y & 0x000F0000LU) ? 16 : 0) + ((Y & 0x00F00000LU) ? 32 : 0) +             \
   ((Y & 0x0F000000LU) ? 64 : 0) + ((Y & 0xF0000000LU) ? 128 : 0))

#define B8(Z) ((unsigned char)B8IFY(HEXIFY(Z)))

#define B_EVEN(x) (((x)&1) == 0)

#define B_ODD(x) (!B_EVEN((x)))

#define B_IS_SET(x, n) (((x) & (1 << (n))) ? 1 : 0)

#define B_SET(x, n) ((x) |= (1 << (n)))

#define B_UNSET(x, n) ((x) &= ~(1 << (n)))

#define B_TOGGLE(x, n) ((x) ^= (1 << (n)))

#define B_TURNOFF_1(x) ((x) &= ((x)-1))

#define B_ISOLATE_1(x) ((x) &= (-(x)))

#define B_PROPAGATE_1(x) ((x) |= ((x)-1))

#define B_ISOLATE_0(x) ((x) = ~(x) & ((x) + 1))

#define B_TURNON_0(x) ((x) |= ((x) + 1))

#endif
