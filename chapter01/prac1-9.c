#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

  int i, sum = 0;

  for (i = 1; i < argc; i++) {
    sum += atoi(argv[i]);
  }

  printf("sum is %d\n", sum);

  return 0;
}
