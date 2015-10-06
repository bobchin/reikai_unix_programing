#include <stdio.h>

#define ROUNDUP(p, n) (((unsigned int)(p)) + ((n) - 1)) & ~((n) - 1)

int main(void)
{
  printf("%d\n", ROUNDUP(100, 4));
  printf("%d\n", ROUNDUP(101, 4));
  printf("%d\n", ROUNDUP(104, 4));

  return 0;
}
