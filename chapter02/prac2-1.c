#include <stdio.h>

int main(void)
{
  char c, *p;
  p = &c;
  *p = 'A';

  printf("%c\n", *p);

  return 0;
}
