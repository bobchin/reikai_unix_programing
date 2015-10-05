#include <termios.h>
#include <unistd.h>

int main(void)
{
  struct termios *tp;
  /* 端末の設定をtpが指す構造体に取得 */
  tcgetattr(STDIN_FILENO, tp);

  return 0;
}
