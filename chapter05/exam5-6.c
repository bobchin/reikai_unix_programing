#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../sub/mysub.h"

int main(void)
{
  char buf[PATH_MAX];

  getstr("directory? ", buf, sizeof(buf));
  printf("Files in %s:\n", buf);
  fflush(stdout);

  execl("/bin/ls", "ls", "-l", buf, (char *)0);

  perror("execl");
  exit(1);
}
