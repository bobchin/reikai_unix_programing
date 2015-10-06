#include <stdio.h>

int main(void)
{
  int i = 0x12345678;
  fwrite(&i, sizeof(i), 1, stdout);

  return 0;
}
