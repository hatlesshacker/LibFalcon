/*
 * Implement the following hooks in your kernel source code.
 * Some of these functions are already implemented, but you can override them with your own code.
 *
 */

extern void cls();
extern void kputs(unsigned char *c);
extern void kputs_dec(uint32_t n);
extern void kputs_hex(uint32_t n);
extern void kputch(unsigned char c);
