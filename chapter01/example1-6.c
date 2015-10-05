#include <stdio.h>

union foo {
  int i;
  double d;
};

int main(void)
{
  union foo x;

  x.d = 12.34;
  printf("%f\n", x.d);
  printf("%d\n", x.i);

  return 0;
}
