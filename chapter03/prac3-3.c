#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
  int fd;
  char buf[6];

  if ((fd = open("hello.txt", O_RDONLY)) == -1) {
    perror("open");
    exit(1);
  }

  if (read(fd, buf, 5) != 5) {
    perror("read");
    exit(1);
  }
  buf[5] = '\0';

  printf("buf=%s\n", buf);

  if (close(fd) == -1) {
    perror("close");
    exit(1);
  }

  return 0;
}
