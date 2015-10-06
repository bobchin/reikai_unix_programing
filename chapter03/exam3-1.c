#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
  int fd;
  ssize_t cc;
  char buf[10];

  if ((fd = open("hello.txt", O_RDONLY)) == -1) {
    perror("open");
    exit(1);
  }

  while ((cc = read(fd, buf, sizeof(buf))) > 0) {
    printf("%d bytes read\n", (int)cc);
  }
  if (cc == -1) {
    perror("read");
    exit(1);
  }
  if (close(fd) == -1) {
    perror("close");
    exit(1);
  }

  return 0;
}
