#include <stdio.h>

void reduce(int numerator, int denominator, int* reduced_numerator, int* reduced_denominator);

int main(void)
{
    int nemer, denomin;
    int reduced_nem, reduced_dem;

    printf("Enter a fraction: ");
    scanf("%d /%d", &nemer, &denomin);
    reduce(nemer, denomin, &reduced_nem, &reduced_dem);

    printf("In lowest terms: %d/%d\n", reduced_nem, reduced_dem);    

    return 0;
}

void reduce(int numerator, int denominator, int* reduced_numerator, int* reduced_denominator)
{
    int mod;

    while (denominator != 0) {
        mod = numerator % denominator;
        numerator = denominator;
        denominator = mod;
    }

    *reduced_numerator = numerator / mod;
    *reduced_denominator = denominator / mod;
}