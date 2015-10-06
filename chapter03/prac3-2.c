#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
  int fd;
  if ((fd = open("empty.file", O_WRONLY|O_CREAT|O_TRUNC, 0666)) == -1) {
    perror("open");
    exit(1);
  }

  if (close(fd) == -1) {
    perror("close");
    exit(1);
  }

  return 0;
}
