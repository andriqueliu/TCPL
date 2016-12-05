#include <stdio.h>

// !!! CTRL + D is EOF in UNIX style systems, CTRL + Z for Windows
// count lines in input
int main()
{
  int c, nl;

  nl = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      ++nl;
    }
  }

  printf("%d\n", nl);
}
