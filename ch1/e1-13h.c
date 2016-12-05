#include <stdio.h>

#define IN  1
#define OUT 0

// Write program to print histogram of the lengths of words in 
// its input
// Horizontal bar version
// Assumptions: input has limit of 10 words...
// Program: add in the length into array sections
int main()
{
  int array[10];
  for (int i = 0; i < 10; i++) {
    array[i] = 0;
  }
  
  int state, itr;
  state = OUT;
  itr = 0;

  while ((c = getchar()) != EOF) {
    if ((c == '\n') || (c == '\t') || (c == ' ')) {
      
    }
  }
}
