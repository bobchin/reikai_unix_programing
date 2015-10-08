#include <ctype.h>

int strtovec(char *s, char **v, int max)
{
  int i, skip;

  skip = 0;
  if (max < 1 || v == 0) {
    skip = 1;
  }

  i = 0;
  for (;;) {
    if (!skip && i >= max - 1) {
      v[i] = 0;
      skip = 1;
    }

    /* 頭の空白を無視 */
    while (*s != '\0' && isspace(*s)) s++;
    if (*s == '\0') break;

    /* 先頭が見つかった */
    if (!skip) v[i] = s;
    i++;

    /* 終わりを見つける */
    while (*s != '\0' && !isspace(*s)) s++;
    if (*s == '\0') break;

    /* 空白をヌルポインタに */
    *s = '\0';
    s++;
  }

  if (!skip) {
    v[i] = 0;
  }
  i++;
  return i;
}
