#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "mysub.h"

#define PHONEBOOK "phone1.dat"
#define RECLEN 32

void show(int);
void input(int);

int main(void)
{
  int fd;
  int cmd, finish;

  if ((fd = open(PHONEBOOK, O_RDWR|O_CREAT, 0666)) < 0) {
    perror("open");
    exit(1);
  }

  finish = 0;
  while (!finish) {
    cmd = getint("command (0=show, 1=input, 2=end)? ");
    switch (cmd) {
      case 0:
        show(fd);
        break;
      case 1:
        input(fd);
        break;
      case 2:
        finish = 1;
        break;
      default:
        fprintf(stderr, "unknown command %d\n", cmd);
        break;
    }
  }

  if (close(fd) == -1) {
    perror("close");
    exit(1);
  }

  return 0;
}

void show(int fd)
{
  int recno;
  ssize_t cc;
  char rec[RECLEN + 1];

  rec[RECLEN] = '\0';
  recno = getint("record number? ");

  if (lseek(fd, recno * RECLEN, SEEK_SET) == -1) {
    perror("lseek");
    exit(1);
  }

  if ((cc = read(fd, rec, RECLEN)) < 0) {
    perror("read");
    exit(1);
  }

  if (cc == 0) {
    printf("no tiem\n");
  } else {
    printf("item = \"%s\"\n", rec);
  }
}

void input(int fd)
{
  int recno;
  char rec[RECLEN + 1];

  memset(rec, 0, sizeof(rec));
  recno = getint("record number? ");
  if (lseek(fd, recno * RECLEN, SEEK_SET) == -1) {
    perror("lseek");
    exit(1);
  }

  getstr("name? ", rec, sizeof(rec));
  if (write(fd, rec, RECLEN) != RECLEN) {
    perror("write");
    exit(1);
  }
}
