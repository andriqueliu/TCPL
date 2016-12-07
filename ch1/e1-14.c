#include <stdio.h>

#define IN  1
#define OUT 0

// Write program to print a histogram of the frequencies
// of different characters in its input
// Program... so, make an array that encompasses every ascii character
// at each character (since, each char is really just equiv. to an int in
// arithmetic and etc.) 
int main()
{
  int array[256];   // a char would work... covers all the possible data
  for (int i = 0; i < 10; i++) {
    array[i] = 0;
  }
  
  int state, itr, count, c;
  state = OUT;
  itr = 0;
  count = 0;

  while ((c = getchar()) != EOF) {
    if ((c == '\n') || (c == '\t') || (c == ' ')) {
      array[itr++] = count;
      count = 0;
    } else {
      ++count;
    }
  }

  for (int i = 0; i < 10; i++) {
    for (int num = 0; num < array[i]; num++) {
      printf("-");
    }
    printf("\n");
  }
}
