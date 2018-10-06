#include <stdarg.h>
#include <string.h>
#include <hooks.h>

static unsigned char buf[1024];

int printk(const char *fmt, ...) {
  va_list args;
  int i;

  va_start(args, fmt);
  i = vsprintf(buf, fmt, args);
  va_end(args);

  kputs(buf);

  return i;
}
