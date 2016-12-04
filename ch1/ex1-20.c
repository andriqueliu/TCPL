#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
#define SPACES 8

int plox(char line[]);
void copyfixtabs(char to[], char from[], int masteri);
void copy(char to[], char from[], int masteri);


// replaces tabs with the proper number of spaces (8)... 8 should be a symbolic parameter
int main()
{
    int len; /* current line length */
    int masteri = 0;
    char line[MAXLINE]; /* current input line */ // looks like these act as "buffers"
    char stuff[MAXLINE]; /* longest line saved here */

    while ((len = plox(line)) > 0) {
        copyfixtabs(stuff, line, masteri);
        masteri = masteri + len; // note, the mi here is not the same as mi down there, so it has to still be incremented here
    }
    
    stuff[masteri] = '\0'; // this should be necessary...

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
    s[i] = '\0'; // returned length includes null
    return i;
}

/*
int copyfixtabs(char to[], char from[], int masteri)
{
    int i = 0;
    int j = 0;
    int 
    
    while (from[i] != '\0') {
        if (from[i] != '\t') {
            to[masteri] = from[i];
            ++i;
            ++masteri;
        }
    }
}
*/

void copyfixtabs(char to[], char from[], int masteri)
{
    int i = 0; // !!! int i, j = 0 is not the same as what's currently written :(
    int j = 0;
    while (from[i] != '\0') {
        if (from[i] != 't') {
            to[masteri] = from[i];
            ++i;
            ++masteri;
        } else {
            for (j = 0; j < SPACES; j++) { // this just means to add 8 spaces total
                to[masteri] = ' ';
                ++masteri;
            }
            ++i;
        }
    }
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
