#include <stdio.h>

void pls(char to[], char from[])
{
    int i = 0;
    int j = 0;
    while (from[i] != '\0') {
        switch(from[i]) {
        case '0':
            printf("Yo!\n");
            break;
        case '1':
            printf("Hello\n");
            break;
        case '2':
            printf("Lmao\n");
            break;
        default:
            printf("cock\n");
            break;
        }
        ++i;
    }
}

int main()
{
    char ploise[50] = "012";
    char test[50];
    pls(test, ploise);
}
