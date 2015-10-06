#include <stdio.h>

int check_bit(unsigned int x, int n);

int main(void)
{
  int i;
  for (i = 0; i < 31; i++) {
    printf("%d", check_bit(0x20, i));
  }
  printf("\n");

  return 0;
}

int check_bit(unsigned int x, int n)
{
  return (x & (1 << n)) != 0;
}
