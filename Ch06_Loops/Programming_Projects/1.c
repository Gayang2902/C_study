/* Writes a program that finds the largest in a series of numbers enetered by user.
 * The program must prompt the user to enter numbers one by one.
 * When the user enters 0 or negaive number, the program must display the largest 
 * nonnegative number entered. */

#include <stdio.h>

int main(void)
{
    float num, large=0;

    for(;;) {
        printf("Enter a number: ");
        scanf(" %f", &num);
        if (num <= 0) {
            break;
        }
        if (large < num) {
            large = num;
        }
    }

    printf("The largest number entered was %.2f\n", large);
    return 0;
}