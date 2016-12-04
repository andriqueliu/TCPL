#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int plox(char line[]);
void copy(char to[], char from[]);

/* print the longest input line */
int main()
{
    int len; /* current line length */
    int max; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */ // looks like these act as "buffers"
    char longest[MAXLINE]; /* longest line saved here */
    max = 0;

    while ((len = plox(line)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) { /* there was a line */
        printf("%s", longest);
        printf("The longest length was: %d\n", max); // includes newline
    }

    return 0;
}

// important: c = getchar() is what's doing the iterating
/* getline: read a line into s, return length */ // ALSO!!! for Cygwin, ctrl + d sends the EOF. also, getline is already defined...?
int plox(char s[])
{
    int c, i;
    for (i = 0; i < (MAXLINE - 1) && ((c = getchar()) != EOF) && (c != '\n'); ++i) { // !!! K&R seems to like ++i over i++... former returns incremented value, latter returns original
        s[i] = c;                                                // if i is less than 999, not at EOF, and not end of line...
    } 
    if (c == '\n') { // if you previous stopped the for loop because of a newline, then add a newline into the array
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) // from is implemented in plox
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0') { // note this syntax... you set them equal to each other... once a newline is reached, loop stops
                                        // BUT, newline has already been added to the arrays
        ++i;
    }
}
