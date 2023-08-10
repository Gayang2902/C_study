/* Write a program that asks the user to enter a fraction, then reduces the fraction to lowest terms. */

#include <stdio.h>

int main(void)
{
    int nemer, denomin;
    int m, n, mod;

    printf("Enter a fraction: ");
    scanf("%d /%d", &nemer, &denomin);

    m = nemer; n = denomin;
    while (n!=0) {
        mod = m % n;
        m = n;
        n = mod;
    }
    printf("In lowest terms: %d/%d\n", nemer/m, denomin/m);

    return 0;
}