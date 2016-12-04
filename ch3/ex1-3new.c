#include <stdio.h>

#define MAXLINE 999

// DONE!!!

// task: escape will convert chars like newline and tab into visible escape seqs...
// use a switch
// also write a function for the reverse direction

// important: c = getchar() is what's doing the iterating
/* getline: read a line into s, return length */ // ALSO!!! for Cygwin, ctrl + d sends the EOF. also, getline is already defined...?
int plox(char s[])
{
    int c, i;
    // another version of that for loop
    i = 0;
    while ((i < (MAXLINE - 1)) && ((c = getchar()) != EOF) && (c != '\n')) {
    /*
    for (i = 0; i < (MAXLINE - 1) && ((c = getchar()) != EOF) && (c != '\n'); ++i) { // !!! K&R seems to like ++i over i++... former returns
                                                                                     // incremented value, latter returns original
                                                                                     */
        s[i] = c;
        ++i;        // if i is less than 999, not at EOF, and not end of line...
    } 
    if (c == '\n') { // if you previous stopped the for loop because of a newline, then add a newline into the array
        s[i] = c;
        ++i;
    }
    s[i] = '\0'; // returned length... "hi" will return 3 for you, includes newline
    return i;
}

// actually, is masteri even necessary for this exercise...?
// also use masteri here... use ptrs later
void escape(char to[], char from[], int masteri)
{
    
    int i = 0;
    int j = 0;
    
    while (from[i] != '\0') {
        switch (from[i]) {
       
        case '\n':
            to[j] = '\\';
            to[j + 1] = 'n';
            j += 2;
            break;
        case '\t':
            to[j] = '\\';
            to[j + 1] = 't';
            j += 2;
            break;
       
        default:
            to[j] = from[i];
            ++j;
            break;
        }
        ++i;
    }

    /*
    while (from[i] != '\0') {
        if (from[i] == '\n') {
            to[j] = '\\';
            to[j + 1] = 'n';
            j += 2;
            ++i;
        } else if (from[i] == '\t') {
            to[j] = '\\';
            to[j + 1] = 't';
            j += 2;
            ++i;
        } else {
            to[j] = from[i];
            ++j;
            ++i;
        }
    }
    */
    
    
    to[j] = '\0';
    printf("%s\n", to);
}

int main()
{
   int len;
   int masteri = 0;
   char line[MAXLINE];
   char stuff[MAXLINE];

   while ((len = plox(line)) > 0) {
       escape(stuff, line, masteri);
   }

   return 0;
}
