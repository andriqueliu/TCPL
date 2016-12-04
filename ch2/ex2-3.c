#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define CONV 48

// incomplete... revisit this later

int htoi(char *hex_string);

// write fn. htoi(s)... converts string of hex digits into equiv. integer value
int main()
{
//    char *ex = "0000"; // strlen will give you length 4 here
//    htoi(ex);
//
//    printf("%d\n", ('1' - CONV)); // that works! prints char value as a real int
}

// since you're passed in a char. array, then each value is a char!
int htoi(char *hex_string)
{
    int i;
    int len = strlen(hex_string);

    for (i = (len - 1); i > -1; --i) {
        if (isdigit(hex_string[i])) {
            int dig_val = hex_string[i] - CONV;
        }
    }
}

/*
int htoi(char *hex_string)
{
    int len = strlen(hex_string);
    int i;
    int exp = 0;
    int total = 0;
    for (i = (len - 1); i > -1; --i) {
        int digit = strtol(hex_string[i], 10);
        total = total + (int) (pow(digit, exp));
    }

}
*/
