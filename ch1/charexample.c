#include <stdio.h>

int main()
{
  int c;   // to accomodate EOF

  c = getchar();
  while (c != EOF) {
    putchar(c);
    c = getchar();
  }
}
