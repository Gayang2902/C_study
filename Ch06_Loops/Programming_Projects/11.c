/* The value of the mathematical constant c can be expressed as an infinite series:
 * e = 1 + 1/1! + 1/2! + 1/3! + ...
 * Write a program that approximates e by computing the value of
 * 1 + 1/1! + 1/2! + 1/3! + ... + 1/n!
 * where n is an integer entered by the user. */

#include <stdio.h>

int main(void)
{
    double e=1, fac=1;;
    int n;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            fac = fac * j;
        }
        e = e + (1/fac);
        fac = 1;
    }
    printf("e: %.4lf\n", e);
    
    return 0;
}