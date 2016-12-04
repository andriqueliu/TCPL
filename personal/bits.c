#include <stdio.h>
#include <stdlib.h>
/*
void print_bin(uint8_t bits)
{
    char buffer[33];
    itoa(bits, buffer, 2);
    printf("binary: %s\n", buffer);
}
*/
int main()
{
    typedef uint8_t BYTE;
    uint8_t ex = 00000000;
    uint8_t ex1 = 0b00000101;
    uint8_t ex2 = 0b00001101;

    uint8_t ex3;
    char buffer[50];
    
    ex3 = ex1 & ex2;

    if (ex3 == ex1) {
	printf("I guess it worked.\n"); // so, 0b is working... bitwise operator is working
    }

    //sprintf(buffer, "%u", ex1);
    //printf("%s\n", buffer);
    
    //print_bin(ex1);

    return 0;
}

