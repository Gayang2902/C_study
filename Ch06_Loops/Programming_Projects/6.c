/* Wirte a program that prompts the user to enter a number n, then prints all even 
 squares between 1 to n. For example, if the user enters 100, the program should print
 * the following. 4 16 36 64 100. */

#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    for (int i = 2; i * i <= n; i %=printf("%d\n", i*i), i+=2);

    return 0;
}