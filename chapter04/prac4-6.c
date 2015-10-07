#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATAFILE "acctbook.txt"
#define DATELEN 10

int main(int argc, char *argv[])
{
  int year, month, day;
  char date[DATELEN + 1];
  char buf[BUFSIZ];
  FILE *fp;

  if (argc < 2) {
    fprintf(stderr, "usage: %s yyyy/mm/dd\n", argv[0]);
    exit(1);
  }

  if (sscanf(argv[1], "%d/%d/%d", &year, &month, &day) != 3) {
    fprintf(stderr, "Please specify date as yyyy/dd/mm\n");
    exit(1);
  }
  if (year < 100) {
    year += 2000;
  }
  snprintf(date, sizeof(date), "%04d/%02d/%02d", year, month, day);

  if ((fp = fopen(DATAFILE, "r")) == NULL) {
    perror("fopen");
    exit(1);
  }

  double sum = 0.0;
  while (fgets(buf, sizeof(buf), fp) != NULL) {
    double fee;
    if (strncmp(buf, date, DATELEN) == 0) {
      sscanf(buf, "%*s %lf", &fee);
      sum += fee;
    }
  }
  if (ferror(fp)) {
    perror("fgets");
    exit(1);
  }

  printf("%s %.2f\n", date, sum);

  fclose(fp);

  return 0;
}
