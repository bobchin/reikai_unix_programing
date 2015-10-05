#include <stdio.h>
#include <stddef.h>

struct foo {
  char c1;
  int i;
  char c2;
  long double ld;
};

int main(void)
{
  struct foo f;

  printf("padding   <->c1: %ld\n", offsetof(struct foo, c1));
  printf("padding c1<-> i: %ld\n", offsetof(struct foo, i) - offsetof(struct foo, c1) - sizeof(f.c1));
  printf("padding  i<->c2: %ld\n", offsetof(struct foo, c2) - offsetof(struct foo, i) - sizeof(f.i));
  printf("padding c2<->ld: %ld\n", offsetof(struct foo, ld) - offsetof(struct foo, c2) - sizeof(f.c2));

  printf("char's alignment        :%ld\n", __alignof__(char));
  printf("int's alignment         :%ld\n", __alignof__(int));
  printf("long double's alignment :%ld\n", __alignof__(long double));

  return 0;
}
