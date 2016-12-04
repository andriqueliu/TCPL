#include <stdio.h>

int main()
{
    int c, count;

    count = 0;
    c = getchar();
    printf("%c\n", c);
    while ((c = getchar()) != EOF) { // getchar returns an int... takes char of 				     // chars AND the EOF
	if (c == '\n' || c == '\t') {
	    count++;
	}
    }
    printf("&d\n", count);

    return 0;
}
