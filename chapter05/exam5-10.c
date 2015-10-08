#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../sub/mysub.h"
#include "../sub/myvec.h"

enum {
  MAXARGV = 100,
};

int main(void)
{
  char cmd[1024];
  char *av[MAXARGV];
  int ac, status, bg;
  pid_t cpid, zpid;

  for (;;) {
    /* 幽霊がいたらwaitする */
    while ((zpid = waitpid(-1, &status, WNOHANG)) > 0) {
      fprintf(stderr, "process %d salvaged\n", zpid);
    }
    if (zpid == -1 && errno != ECHILD) {
      perror("waitpid(2)");
      exit(1);
    }

    getstr("@ ", cmd, sizeof(cmd));
    if (feof(stdin)) {
      /* Ctrl+D */
      exit(0);
    } else if (ferror(stdin)) {
      perror("getstr");
      exit(1);
    }

    if ((ac = strtovec(cmd, av, MAXARGV)) > MAXARGV) {
      fputs("argument list too long\n", stderr);
      continue;
    }
    /* 最後のヌルポインタを削除 */
    ac--;
    if (ac == 0) {
      /* 入力なし */
      continue;
    }

    bg = 0;
    if (!strcmp(av[ac - 1], "&")) {
      bg = 1;

      /* 最後の "&" を削除 */
      av[ac - 1] = NULL;
      ac--;
      if (ac == 0){
        fputs("invalid null command\n", stderr);
        continue;
      }
    }

    if ((cpid = fork()) == -1) {
      perror("fork");
      exit(1);
    }

    if (cpid == 0) {
      /* 子プロセス */
      execvp(av[0], av);
      perror("execvp");
      exit(1);
    } else {
      /* 親プロセス */
      if (!bg) {
        if (waitpid(cpid, &status, 0) == (pid_t)-1) {
          perror("waitpid(1)");
          exit(1);
        }
        fprintf(stderr, "process %d finished\n", cpid);
      }
    }
  }
  exit(0);
}
