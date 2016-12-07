#include <stdio.h>
#define MAXLINE 1000

// pseudo getline
int getslen(char s[]);
void printreverse(int len, char from[], char to[]);

// reverse the character string s
// reverse the input one line at a time
int main()
{
  int len;
  // these are arrays, and actually DO hold their changes unlike auto var.!
  char from[MAXLINE];
  char   to[MAXLINE];
  
  // beware, this is read-only... 
  // char from[]  = "Hello it's me!";   // I think the newline and null are implied?
  len = getslen(from);
  printreverse(len, from, to);

  return 0;
}

int getslen(char s[])
{
  int c, ct;
  ct = 0;

  while ((c = getchar()) != EOF) {
    // ++ct;
    s[ct] = c;
    ++ct;
  }
  return ct;
}

void printreverse(int len, char from[], char to[])
{
  for (int i = 0; i < len; i++) {
    to[i] = from[len - (1 + i)];
    // s[len - (1 - i)] = to[i];
  }
  to[len] = '\0';
  printf("%s\n", to);
}
