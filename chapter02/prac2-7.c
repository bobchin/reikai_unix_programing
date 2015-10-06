#include <stdio.h>
#include <stdlib.h>

struct point {int x, y;};

int main(void)
{
  struct point *p = malloc(sizeof(struct point));

  int *q = &p->x;
  p->x = 10;
  p->y = 20;
  printf("%d\n", *q);
  free(p);

  return 0;
}
