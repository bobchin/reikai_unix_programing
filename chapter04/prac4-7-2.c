#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PSIZE 10

enum sex {
  male = 0,
  female,
};

struct person {
  char name[32];
  int age;
  enum sex sex;
};

int main(void)
{
  struct person a[PSIZE];
  FILE *fp;

  if ((fp = fopen("persondata.db", "r")) == NULL) {
    perror("fopen");
    exit(1);
  }

  if (fread(a, sizeof(struct person), PSIZE, fp) < PSIZE) {
    perror("fwrite");
    exit(1);
  }

  fclose(fp);

  for (int i = 0; i < PSIZE; i++) {
    printf("name='%s' age=%d sex=%s\n", a[i].name, a[i].age, a[i].sex? "女": "男");
  }

  return 0;
}
