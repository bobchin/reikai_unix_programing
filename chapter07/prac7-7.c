#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int popen2(const char *command, FILE *fp[2])
{
  pid_t pid;
  int pfd1[2], pfd2[2];

  if (pipe(pfd1) == -1) return -1;
  if (pipe(pfd2) == -1) return -1;

  if ((pid = fork()) == 0) {
    /* 子プロセス */
    dup2(pfd1[0], 0);
    dup2(pfd2[1], 1);
    close(pfd1[0]); close(pfd1[1]);
    close(pfd2[0]); close(pfd2[1]);
    execlp("sh", "/bin/sh", "-c", command, (char *)NULL);
  }

  close(pfd1[0]);
  close(pfd2[1]);
  fp[0] = fdopen(pfd2[0], "r");
  fp[1] = fdopen(pfd1[1], "w");

  return 0;
}

int main(void)
{
  FILE *fp[2];
  char buf[1024], *ret;

  popen2("sort", fp);
  fprintf(fp[1], "orange\n");
  fprintf(fp[1], "apple\n");
  fprintf(fp[1], "banana\n");
  fclose(fp[1]);

  while (1) {
    ret = fgets(buf, sizeof(buf), fp[0]);
    if (ret == NULL) break;
    printf("%s", buf);
  }

  return 0;
}
