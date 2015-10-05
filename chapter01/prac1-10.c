#include <stdio.h>

struct point {
  int x;
  int y;
};

int point_is_equal(struct point *, struct point *);


int main(void)
{
  struct point z1 = { 100, 200 };
  struct point z2 = { 100, 200 };
  struct point z3 = { 101, 200 };
  struct point z4 = { 100, 201 };
  struct point z5 = { 101, 201 };

  printf("z1==z2:%d\n", point_is_equal(&z1, &z2));
  printf("z1==z3:%d\n", point_is_equal(&z1, &z3));
  printf("z1==z4:%d\n", point_is_equal(&z1, &z4));
  printf("z1==z5:%d\n", point_is_equal(&z1, &z5));

  return 0;
}

int point_is_equal(struct point *p1, struct point *p2)
{
  return (p1->x == p2->x && p1->y == p2->y);
}
