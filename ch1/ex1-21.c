#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
#define SPACES 8

int plox(char line[]);
int entab(char to[], char from[], int masteri, int len);
void copy(char to[], char from[], int masteri);

// DONE

// entab: replaces strings of blanks with efficient tabs and spaces
int main()
{
    int len; /* current line length */
    int masteri = 0;
    int total = 0;
    char line[MAXLINE]; /* current input line */ // looks like these act as "buffers"
    char stuff[MAXLINE]; /* longest line saved here */

    while ((len = plox(line)) > 0) {
        total = entab(stuff, line, masteri, len);
        masteri = masteri + total;
//        masteri = masteri + len; // note, the mi here is not the same as mi down there, so it has to still be incremented here
    }
    stuff[masteri] = '\0'; // this is what FIXED it...
    
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

// by this point, a line of input is in from[]... you also have len ("  " has len 3! pl'\n', and at position 3, has a NULL)
// so, here, split up the blank spaces. % to get spaces, / to get tabs
// masteri is still used to keep track of the "to" array's position
// for example, len of 3 means 2 spaces, an endofline, and a NULL
int entab(char to[], char from[], int masteri, int len)
{
    int tabs, spaces, i, total;
    total = 0;
    tabs = (len - 1) / SPACES;
    spaces = (len - 1) % SPACES;
    for (i = 0; i < tabs; ++i) {
        to[masteri] = '\t';
        ++masteri;
        ++total;
    }
    for (i = 0; i < spaces; ++i) {
        to[masteri] = ' ';
        ++masteri;
        ++total;
    }
    return total;

/*
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
    */
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
