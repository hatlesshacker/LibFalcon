unsigned char inportb (unsigned short _port);
uint16_t inportw (uint16_t port);
void outportb (unsigned short _port, unsigned char _data);
void outportw (unsigned short _port, uint16_t _data);
void reboot();
char* get_cpuvendor();
int __get_cpuvendor();
