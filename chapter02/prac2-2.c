#include <termios.h>
#include <unistd.h>

int main(void)
{
  struct termios t;
  /* 端末の設定をtpが指す構造体に取得 */
  tcgetattr(STDIN_FILENO, &t);

  return 0;
}
