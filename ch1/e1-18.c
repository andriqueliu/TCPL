#include <stdio.h>
#define MAXLINE 1000

// pseudo getline
int pgetline(char line[], int maxline);
void copy(char to[], char from[]);

// remove trailing blanks and tabs from lines of input, delete 
// entirely blank lines
// Print all of these lines at the end for convenience
int main()
{
  int len, max;
  // these are arrays, and are actually altered!
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

// read a line into s, return length
int pgetline(char s[], int lim)
{
  int c, i;
  
  // for: will put EVERYTHING into a buffer
  // condition: less than buffer max, char is not EOF, and
  // you're not at the end of a line
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }
  // the rest of this function...
  // if you hit a newline, then add a newline and a null
  // if there's nothing left, just add the null
  if (c == '\n') {
    s[i] = c;
    ++i;
  } 
  s[i] = '\0';
  return i;
}

void copy(char to[], char from[])
{
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}
