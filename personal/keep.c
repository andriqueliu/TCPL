#include <stdio.h>

void test1(int num);
void test2(int *numptr);

// !!! YEP, the ptr stuff keeps the value working and everything

int main()
{
    int i = 5;
    int j = 5;
    int *iptr = &i;
    test1(j);
    test2(iptr);
    printf("%d\n", j);
    printf("%d\n", *iptr);
}

void test1(int num)
{
    num = num + 10;
}

void test2(int *numptr)
{
    *numptr = *numptr + 10;
}
