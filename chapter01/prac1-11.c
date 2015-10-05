#include <stdio.h>

struct point {
  int x;
  int y;
};

enum LINE_STYLE {
  SOLID = 0,
  DASHED,
  DOTTED,
};

struct line {
  struct point point1, point2;
  enum LINE_STYLE style;
};

int main(void) {

  struct line line1 = {{10, 20}, {20, 30}, DASHED};

  printf("(%d, %d) - (%d, %d), style=%d\n",
        line1.point1.x, line1.point1.y,
        line1.point2.x, line1.point2.y,
        line1.style);

  return 0;
}
