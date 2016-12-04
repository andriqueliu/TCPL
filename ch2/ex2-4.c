#include <stdio.h>
#include <string.h>

// alt. version of squeeze that deletes each char. in s1 that matches any char in s2.
// idea: perhaps make another method... at each char, call it... it will iterate through s2 and see if there are
// any chars matching it
// then, once something IS found...
// just use that same "place" and replace that thing with a null char or something... maybe a space instead?

// ... DONE! learned: str* is not the same as str[]!!!

//int matchchar(char character, char *check) 
int matchchar(char character, char check[]) 
{
    int i;
    for (i = 0; i < strlen(check); ++i) {
        if (character == check[i]) {
//            printf("lol\n");
            return 1;
        }
    }
    return 0;
}

/*
// this isn't written right, it examines the entire word...
// it SHOULD be examining just one char at a time
int match(char test[], char check[])
{
    int i, j;
    for (i = 0; i < strlen(test); ++i) {
        char character = strlen[i];
        for (j = 0; j < strlen(check); ++j) {
            if (test[i] == check[j]) {
                return 1;
            }
        }
    }
    return 0;
}
*/

void squeeze2(char s1[], char s2[]) {
//void squeeze2(char *s1, char *s2) {
    int i;
    for (i = 0; i < strlen(s1); ++i) {
        
        if (matchchar(s1[i], s2)) {
            s1[i] = ' ';
            printf("%c\n", s1[i]);

        }
        
    }
//    printf("lol\n");
}



int main()
{
    char ex1[] = "plox";
    char ex2[] = "p";
    squeeze2(ex1, ex2);

    printf("%s\n", ex1);
}
