#include <stdio.h>

void increment(int i);
void add(char *from, char *to);

int main()
{/*
    char *str = "Hello";
    char str1[5000];
    add(str, str1);
    printf("%s\n", str1);

    int i = 0;
    increment(i);
    printf("%d\n", i);
   */ 
    static int i = 0;
    int j = 0;
    increment(i);
    increment(j);
    printf("%d %d\n", i, j);
}

void increment(int i)
{
    i = i + 5;
    printf("%d\n", i);
}

void add(char *str, char *str1)
{
    int i = 0;
    for (int i = 0; i < 5; ++i) {
        str1[i] = str[i];
    }
}
