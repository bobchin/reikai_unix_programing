#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "../sub/mysub.h"

int main(void)
{
  char cmd[1024];
  int status;

  for (;;) {
    getstr("@ ", cmd, sizeof(cmd));

    /* 子プロセス */
    if (fork() == 0) {
      execlp(cmd, cmd, (char *)0);
      perror("execlp");
      exit(1);
    }

    /* 親プロセス */
    if (wait(&status) == (pid_t)-1) {
      perror("wait");
      exit(1);
    }
  }

  exit(0);
}
