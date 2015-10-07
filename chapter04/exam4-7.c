#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

enum {
  MYNAMELEN = 15,
};

char name[] = "Rie";
int myname, notmyname, junkchars;

void processword(void);

int main(void)
{
  int c;

  assert(strlen(name) <= MYNAMELEN);
  while ((c = getchar()) != EOF) {
    if (isalpha(c)) {
      ungetc(c, stdin);
      processword();
    } else {
      junkchars++;
    }
  }

  printf("my name %d, not my name %d, junk chars %d\n",
         myname, notmyname, junkchars);

  return 0;
}

void processword(void)
{
  int c, i;
  char buf[MYNAMELEN + 2];

  i = 0;
  while ((c = getchar()) != EOF) {
    if (isalpha(c)) {
      buf[i]= c;
      i++;
      if (i == sizeof(buf) - 1) {
        while ((c = getchar()) != EOF) {
          if (!isalpha(c)) {
            ungetc(c, stdin);
            break;
          }
        }
        goto wordgot;
      }
    } else {
      ungetc(c, stdin);
      goto wordgot;
    }
  }

wordgot:
  buf[i] = '\0';
  if (!strcmp(buf, name)) {
    myname++;
  } else {
    notmyname++;
  }

}
