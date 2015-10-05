#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

extern int errno;

int main(void)
{
  if (rmdir("foo") == -1) {
    int old_errno = errno;
    if (old_errno == ENOTEMPTY) {
      system("ls foo");
    } else {
      perror("rmdir");
      exit(1);
    }
  }

  return 0;
}
