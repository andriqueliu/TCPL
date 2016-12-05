#include <stdio.h>

// avoid magic numbers!
#define LOWER 0
#define UPPER 300
#define STEP 20

// change to print out reverse order
int main()
{
  int fahr;
  
  // for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) {
  for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP) {
    printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr-32));
  }
}
