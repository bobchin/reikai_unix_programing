#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
  if (rmdir("foo") == -1) {
    perror("rmdir");
    exit(1);
  }

  return 0;
}
