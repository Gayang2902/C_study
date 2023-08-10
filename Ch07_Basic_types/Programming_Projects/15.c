/* Write a program that computes the factorial of a positive integer:
 * (a) Use a short variable to store the value of the factorial. 
 * What is the largest value of n for which the program correctly prints the factorial of n?
 * (b) Repeat part (a), using an int variable instead.
 * (c) Repeat part (a), using a long variable instead.
 * (d) Repeat part (a), using a long long variable instead.
 * (if your compiler supports the long long type.)
 * (e) Repeat part (a), using a float variable instead.
 * (f) Repeat part (a), using a double variable instead.
 * (g) Repeat part (a), using a long double variable instead.
 * In cases (e)-(g), the program will display a close approximation of the factorial, 
 * not necessarily the exact value. */

#include <stdio.h>

int main(void)
{
    int factorial;
    long double f = 1, i = 1;

    printf("Enter a positive integer: ");
    scanf("%d", &factorial);

    for (; i <= factorial; f *= i, i++);

    printf("Factorial of %d: %Lf\n", factorial, f);
    return 0;   
}
