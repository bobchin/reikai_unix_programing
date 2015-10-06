#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define OUTFILE "output.file"

int main(void)
{
  int ofd;
  ssize_t cc;
  char buf[1024];

  if ((ofd = open(OUTFILE, O_WRONLY|O_CREAT|O_TRUNC, 0666)) == -1) {
    perror("open");
    exit(1);
  }

  while ((cc = read(STDIN_FILENO, buf, sizeof(buf))) > 0) {
    if (write(ofd, buf, cc) < cc) {
      perror("write");
      exit(1);
    }
  }

  if (cc == -1) {
    perror("read");
    exit(1);
  }

  if (close(ofd) == -1) {
    perror("close");
    exit(1);
  }

  return 0;
}
