#include <stdio.h>
#include <stdlib.h>

#define N 10

int main(int argc, char const *argv[])
{
  int i, data[N];
  if (argc - 1 > N) {
    exit(1);
  }
  for (i = 1; i < argc; i++) {
    data[i - 1] = atoi(argv[i]);
  }

  return 0;
}
