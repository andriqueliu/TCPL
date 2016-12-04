#include <stdio.h>

int main()
{
    char plox[] = { 'b', 'a', 'e', '\0' };
    char ploise[] = "babe";
    char *str = "bae"; // !!! read-only, there's your problem!!!
    printf("%s\n", plox);
    printf("%s\n", ploise);
    printf("%s\n", str);

    plox[0] = '0';
    printf("%s\n", plox);

    ploise[0] = '0';
    printf("%s\n", ploise);

//    str[0] = '0';             // this definitely doesn't work...  
//    printf("%s\n", str); 
    // let's try changing something in the ptr version
    printf("%c\n", str[0]); // that works...
    *str[0] = '0';
    printf("%c\n", str[0]);

}
