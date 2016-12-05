#include <stdio.h>

// psuedo boolean functionality
#define IN 1
#define OUT 0

// prints input one word per line
// print each char, BUT, once you reach a space, print out a newline
int main()
{
  // int c, nl, nw, nc, state;
  int c, state;

  state = OUT;
  // nl = nw = nc = 0;
  while((c = getchar()) != EOF) {
    /*
    if (c == '\n') {
      ++nl;
    }
    */
    /*
    if ((c == ' ') || (c == '\n') || (c == '\t')) {
      state = OUT;
      printf("\n");
    } else if (state == OUT) {
      state = IN;
      ++nw;
    }
    */
    if ((c == ' ') || (c == '\n') || (c == '\t')) {
      printf("\n");
    } else {
      printf("%c", c);
    }
  }

  
}
