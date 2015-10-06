#include <stdio.h>

int L2B_int(int little);

int main(void)
{
  int x = 0x12345678;
  printf("%x, %x\n", x, L2B_int(x));

  return 0;
}

int L2B_int(int little)
{
  int i, big;
  char *lc = (char *)&little, *bc = (char *)&big;

  for (i = 0; i < sizeof(int); i++) {
    bc[sizeof(int) - i - 1] = lc[i];
  }

  return big;
}
