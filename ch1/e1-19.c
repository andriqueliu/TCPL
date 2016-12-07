#include <stdio.h>
#define MAXLINE 1000

// pseudo getline
int getslen(char s[]);
void printreverse(int len, char from[], char to[]);

// reverse the character string s
// reverse the input one line at a time
int main()
{
  int len, max;
  // these are arrays, and actually DO hold their changes unlike auto var.!
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  // notice: calls a function and returns the length
  while((len = pgetline(line, MAXLINE)) > 0) {
    copy(longest, line);
  }
  // just in case you were given empty input
  if (max > 0) {
    printf("%s", longest);
  }

  return 0;
}

int getslen(char s[])
{
  int c, ct;
  ct = 0;

  while ((c = getchar()) != EOF) {
    ++ct;
    s[ct] = c;
  }
  return ct;
}

void printreverse(int len, char from[], char to[])
{
  for (int i = 0; i < len; i++) {
    to[i] = s[len - (1 - i)];
    // s[len - (1 - i)] = to[i];
  }
  to[len] = '\0';
  printf("%s\n", to[]);
}
