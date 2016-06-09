#include <stdint.h>

unsigned char inportb (unsigned short);
uint16_t inportw (uint16_t);
void outportb (unsigned short , unsigned char);
void outportw (unsigned short , uint16_t);
unsigned int inportl(unsigned short);
void outportl(unsigned int, unsigned short);
void reboot();
char* get_cpuvendor();
int __get_cpuvendor();
