#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <errno.h>

int main(int argc, char *argv[])
{
  long val;
  char *end;

  errno = 0;
  val = strtol(argv[1], &end, 0);
  if (errno != 0) {
    perror("strtol");
    exit(1);
  }

  if (end[0] != '\0') {
    fprintf(stderr, "Non digit charactor: %c\n", end[0]);
    exit(1);
  }

  printf("%ld\n", val);

  return 0;
}
