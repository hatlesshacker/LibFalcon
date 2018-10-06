#include <kernel.h>

extern void int32(unsigned char intnum, regs16_t *regs);

void int32_call(char interrupt, regs16_t r) {
   int32(interrupt, &r);
 }
