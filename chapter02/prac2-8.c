#include <stdio.h>

int main(int argc, char *argv[])
{
  char buf[BUFSIZ];
  printf("Please type your name: ");
  fgets(buf, sizeof(buf), stdin);
  printf("hello, %s", buf);


  snprintf(buf, sizeof(buf), "%s", argv[0]);
  printf("%s\n", buf);

  return 0;
}
