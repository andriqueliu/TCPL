#include <stdio.h>

// done

float convertftoc(float fahr)
{
    float celsius;
    return celsius = (5.0 / 9.0) * (fahr - 32.0);
}

int main()
{
    float fahr = 100;
    printf("%f\n", convertftoc(fahr));
}
