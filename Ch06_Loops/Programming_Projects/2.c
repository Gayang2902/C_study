/* Write a program that asks the user to enter two integers, 
 * then calculates and displays their greatest common divisor (GCD). 
 * Hint: The classic algorithm for computing the GCD, known as 
 * Euclid's algorithm, goes as follows; 
 * Let m and n be variables containing the two numbers. If n is 0, then stop:
 * m contains the GCD. Otherwise, compute the remainder when m is divided by n.
 * Copy n into m and copy the remainder into n. Then repeat the process, starting with 
 * testing whether n is 0. */
 
#include <stdio.h>

int main(void)
{
    int m, n, remainder;

    printf("Enter two integers: ");
    scanf("%d %d", &m, &n);

    while (n!=0) { // using Euclid's algorithm
        remainder = m % n; 
        m = n;
        n = remainder;
    }
    printf("Greatest commom divisor: %d\n", m);

    return 0;
}