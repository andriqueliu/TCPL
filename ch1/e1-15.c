#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

void convertTemps(int fahr)
{
  // no int i used here...
  for (; fahr <= UPPER; fahr += STEP) {
    printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
  } 
}

// Write a program that uses the temp. conversion of Section 1.2
int main()
{
  int a, b;
  a = 0;
  b = 50;
  
  convertTemps(a);
  convertTemps(b);

  return 0;
}
