#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
#define SATISFY 5

int plox(char line[]);
void copy(char to[], char from[], int masteri);

// print all input lines longer than 80 chars
int main()
{
    int len; /* current line length */
    int max; /* maximum length seen so far */
    int masteri = 0;
    char line[MAXLINE]; /* current input line */ // looks like these act as "buffers"
    char stuff[MAXLINE]; /* longest line saved here */

    while ((len = plox(line)) > 0) {
        if (len > SATISFY) {
            copy(stuff, line, masteri); // this line and the next write things over to the stuff array
            masteri = masteri + len;
        }
    }
    
    printf("%s\n", stuff);

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
    s[i] = '\0'; // returned length includes newline
    return i;
}



/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[], int masteri) // from is implemented in plox
{
    int i = 0;
    while ((to[masteri] = from[i]) != '\0') { // note this syntax... you set them equal to each other... once a newline is reached, loop stops
                                        // BUT, newline has already been added to the arrays
        ++i;
        ++masteri; // note, the increments don't carry over to new calls to this, which is why masteri = masteri + len was added
    }
}
