#include <stdio.h>

// ... DONE

// write strend(s, t) which returns 1 if string t occurs at the end of string s, 0 otherwise
// extend: see if some string occurs in that other string
int strendlol(char *s, char *t)
{
    // iterate through a whole string... as soon as you meet a char that matches,
    // iterate through both strings together and see if you can reach the end of t
    while (*s != '\0') {
        if (*s == *t) {
            char *backs = s;
            char *backt = t;
            while (*s == *t) {
                ++s;
                ++t;
            }
            if (*t == '\0') {
                return 1;
            }
            s = backs + 1;
            t = backt;
        } else {
            ++s;
        }
    }
    
    return 0;
}

int main()
{
    char *ex1 = "Hello it is me";
    char *ex3 = "Hell yo Hello";
    char *ex2 = "Hello";
    printf("%d\n", strendlol(ex1, ex2));
    printf("%d\n", strendlol(ex3, ex2));
    return 0;
}
