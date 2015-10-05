#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

union any_t {
  char c;
  int i;
  float f;
  double d;
};

enum any_discr {
  ANY_CHAR, ANY_INT, ANY_FLOAT, ANY_DOUBLE,
};

union any_t any_add(union any_t a1, union any_t a2, enum any_discr discr);

struct any_t2 {
  enum any_discr discr;
  union any_t u;
};

struct any_t2 any_add2(struct any_t2 a1, struct any_t2 a2);

int main(void)
{
  union any_t a1, a2, a3;
  a1.i = 999;
  printf("%d\n", a1.i);

  a2.i = 1;
  a3 = any_add(a1, a2, ANY_INT);
  printf("%d\n", a3.i);

  struct any_t2 b1, b2, b3;
  b1.u.i = 999;
  b1.discr = ANY_INT;
  printf("%d\n", b1.u.i);
  b2.u.i = 1;
  b2.discr = ANY_INT;

  b3 = any_add2(b1, b2);
  printf("%d\n", b3.u.i);

  return 0;
}

union any_t any_add(union any_t a1, union any_t a2, enum any_discr discr)
{
  union any_t result;

  switch (discr) {
    case ANY_CHAR:   result.c = a1.c + a2.c; break;
    case ANY_INT:    result.i = a1.i + a2.i; break;
    case ANY_FLOAT:  result.f = a1.f + a2.f; break;
    case ANY_DOUBLE: result.d = a1.d + a2.d; break;
    default: assert(0);
  }

  return result;
}

struct any_t2 any_add2(struct any_t2 a1, struct any_t2 a2)
{
  if (a1.discr != a2.discr) {
    fprintf(stderr, "different type!");
    exit(1);
  }

  struct any_t2 result;

  switch (a1.discr) {
    case ANY_CHAR:   result.u.c = a1.u.c + a2.u.c; break;
    case ANY_INT:    result.u.i = a1.u.i + a2.u.i; break;
    case ANY_FLOAT:  result.u.f = a1.u.f + a2.u.f; break;
    case ANY_DOUBLE: result.u.d = a1.u.d + a2.u.d; break;
  }

  return result;
}
