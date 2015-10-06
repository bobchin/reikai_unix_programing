#include <stdio.h>
#include <stdarg.h>

void tiny_printf(char *, ...);

int main(void)
{
  tiny_printf("hello: \n");
  tiny_printf("hello: %d\n", 1);
  tiny_printf("hello: %d %d\n", 1, 2);
  return 0;
}

void tiny_printf(char * format, ...)
{
  va_list pvar;
  va_start(pvar, format);

  while (*format != '\0') {
    if (*format != '%') {
      putchar(*format);
    } else if (*++format == 'd') {
      putchar('0' + va_arg(pvar, int));
    }
    format++;
  }

  va_end(pvar);
}
