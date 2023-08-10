/* Write a program that prints a one-month calendar. The user specifies the number
 * of days in the month and the day of the week on which the month begins.
 * Hint: This program isn't as hard as it looks. The most important part is 
 * for statement that uses a variable i to count from 1 to n, where n is the number
 * of days in the month, printing each value of i. Inside the loop, an if statement
 * tests whether i is the last day in a week; if so, it prints a new-line character. */

#include <stdio.h>

int main(void)
{
    int month, start, token;

    printf("Enter number of days in month: ");
    scanf("%d", &month);
    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf(" %d", &start);

    token = 8 - start;
    for (int i = start; i != 1; i--) printf(" ");
    for (int i = 1; i <= month; i++) {
        printf("%2d ", i);
        token--;
        if (token == 0) {
            token = 7;
            printf("\n");
        }
    }
    printf("\n");

    return 0;
}