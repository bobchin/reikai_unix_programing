#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
  int fd;

  fd = open("input.txt", O_RDONLY);
  if (fd == -1) {
    perror("open");
    exit(1);
  }

  printf("fd=%d\n", fd);

  close(fd);

  return 0;
}
