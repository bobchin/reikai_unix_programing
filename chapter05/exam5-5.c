#include <stdio.h>
#include <unistd.h>

int main(void)
{
  printf("Invoking ls.\n");
  fflush(stdout);
  execlp("ls", "ls", (char *)0);

  /* execlpに成功したらここは通らない */
  printf("Done.\n");
  return 0;
}
