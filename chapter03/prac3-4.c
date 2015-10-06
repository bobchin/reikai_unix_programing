#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define INFILE "input.file"
#define OUTFILE "output.file"

int main(void)
{
  int fdin, fdout;
  ssize_t cc;
  char buf[BUFSIZ];

  if ((fdin = open(INFILE, O_RDONLY)) == -1) {
    perror("open intput.file");
    exit(1);
  }
  if ((fdout = open(OUTFILE, O_WRONLY|O_CREAT|O_TRUNC, 0666)) == -1) {
    perror("open outtput.file");
    exit(1);
  }

  while((cc = read(fdin, buf, sizeof(buf))) > 0) {
    if (write(fdout, buf, cc) == -1) {
      perror("write");
      exit(1);
    }
  }

  if (cc == -1) {
    perror("read");
    exit(1);
  }

  if (close(fdin) == -1) {
    perror("close");
    exit(1);
  }
  if (close(fdout) == -1) {
    perror("close");
    exit(1);
  }

  return 0;
}
