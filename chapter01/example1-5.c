#include <stdio.h>
#include <stddef.h>

struct foo {
  char a;
  int b;
};

int main(void) {
  printf("%ld\n", offsetof(struct foo, b));

  return 0;
}
