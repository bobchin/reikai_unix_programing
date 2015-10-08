#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
  int pid;

  if ((pid = fork()) == 0) {
    // 子プロセス
    printf("This is Child Proccess. PID:%d PPID:%d\n", getpid(), getppid());
    exit(0);
  } else {
    // 親プロセス
    printf("This is Parent Process. PID:%d CPID:%d\n", getpid(), pid);
    while(1)
      sleep(1);
  }

  return 0;
}
