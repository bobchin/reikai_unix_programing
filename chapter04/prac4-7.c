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

  int age = 20;
  for (int i = 0; i < PSIZE; i++) {
    strcpy(a[i].name, "bobchin");
    a[i].age = age++;
    a[i].sex = male;
  }

  if ((fp = fopen("persondata.db", "w")) == NULL) {
    perror("fopen");
    exit(1);
  }

  if (fwrite(a, sizeof(struct person), PSIZE, fp) < PSIZE) {
    perror("fwrite");
    exit(1);
  }

  fclose(fp);

  return 0;
}
