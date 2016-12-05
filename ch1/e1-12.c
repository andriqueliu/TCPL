#include <stdio.h>

// psuedo boolean functionality
#define IN 1
#define OUT 0

// prints input one word per line
// idea, when you're reached the end of a word, just print the word!
int main()
{
  int c, nl, nw, nc, state;

  state = OUT;
  nl = nw = nc = 0;
  while((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n') {
      ++nl;
    }
    if ((c == ' ') || (c == '\n') || (c == '\t')) {
      state = OUT;
    } else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }

  printf("%d %d %d\n", nl, nw, nc);
}
