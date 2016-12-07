#include <stdio.h>

#define MAX 256

#define IN  1
#define OUT 0

// Write program to print a histogram of the frequencies
// of different characters in its input
// Program... so, make an array that encompasses every ascii character
// at each character (since, each char is really just equiv. to an int in
// arithmetic and etc.) 
int main()
{
  int array[MAX];   // a char would work... covers all the possible data
  int c;
  
  for (int i = 0; i < MAX; i++) {
    array[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    ++array[c];   // legal?
  }
  
  for (int i = 0; i < MAX; i++) {
    printf("%c: ", i);
    for (int j = 0; j < array[i]; j++) {
      printf("-");
    }
    printf("\n");
  }
  
  /*  
  for (int i = 0; i < MAX; i++) {
    printf("%c: %d\n", i, array[i]);
  }
  */
}
