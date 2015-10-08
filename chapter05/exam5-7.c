#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../sub/mysub.h"

int main(void)
{
  char buf[PATH_MAX];
  char *av[4] = { "ls", "-l", buf, NULL };

  getstr("directory? ", buf, sizeof(buf));
  printf("Files in %s:\n", buf);
  fflush(stdout);

  execv("/bin/ls", av);

  perror("execv");
  exit(1);
}
