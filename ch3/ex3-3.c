#include <stdio.h>
#include <string.h>

#define ASTART 97
#define ZEND 122

// ... DONE!

// expand from into to
// ex. a-c will give you abc
void expand(char from[], char to[])
{
    int start = from[0]; // starting int 'a' for ex
    int end = from[2];   // ending int 'z' for ex
    int times = (end - start);
    to[0] = start;
    for (int i = 1; i < times; ++i) {
        to[i] = start + i;
    }
    to[times] = end;
    to[times + 1] = '\0'; // critical to avoid weird memory errors
}

int main()
{
    char ex1[100] = "a-z";
    char out[100];
    
    /*
    char ex1[50] = "a-b-c";
    char ex2[50] = "-b-z";
    char out[100];
    */

    /*
    // test... so, printing out lol as a char or int array gives you 'a'
    // this is the case when you print as %s! 
    int a = 97;
    int lol[50];
    lol[0] = a;
    printf("%s\n", lol);
    */

    expand(ex1, out);
    printf("%s\n", out);
}

/*
void expand(char *str1, char *str2)
{
    int i = 0;
    int length = strlen(str1);
    

    while (str1[i] != EOF) {
        if (str1[i] == '-') {
            if (i == 0) { // so the very first is a hyphen 
            
            } else if (i == (length - 1)) { // so the very last is a hyphen
               
            } else { // so the hyphen is somewhere in the middle
                
            }
        }

        i++;
    }
}
*/
