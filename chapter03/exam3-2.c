#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
  int fd;

  if ((fd = open("bye.txt", O_WRONLY|O_CREAT|O_TRUNC, 0666)) == -1) {
    perror("open");
    exit(1);
  }

  if (write(fd, "See you", 7) != 7) {
    perror("write");
    exit(1);
  }

  if (write(fd, " later!", 7) != 7) {
    perror("write");
    exit(1);
  }

  if (write(fd, "\nBye!\n", 6) != 6) {
    perror("write");
    exit(1);
  }

  if (close(fd) == -1) {
    perror("close");
    exit(1);
  }

  return 0;
}
