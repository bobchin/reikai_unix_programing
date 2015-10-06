#include <stdio.h>

int main(int argc, char *argv[])
{
  char buf[1024];
  printf("Please type your name: ");
  gets(buf);
  printf("hello, %s\n", buf);


  sprintf(buf, "%s", argv[0]);
  printf("%s\n", buf);

  return 0;
}
