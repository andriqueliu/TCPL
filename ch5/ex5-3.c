#include <stdio.h>

// write a ptr version of strcat, copies string t to the end of s
// so, go to the end of string s first, then copy over string t
void strcatlol(char *s, char *t)
{
    // while value of s is not pointing to a NULL... THEN increment
    // while (*(s++) != '\0') {
    while (*s != '\0') {
        ++s;
    }
    while (*t != '\0') {
        *s = *t;
        ++s;
        ++t;
    }
}

int main()
{
    char ex1[500] = "Hey hello "; // make ex1 big enough, it's getting stuff added onto it
    char ex2[] = "it's me\n";
    strcatlol(ex1, ex2);
    printf("%s\n", ex1);

    return 0;
}
