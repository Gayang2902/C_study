/* Write a program that asks the user for a 12-hour time, then displays
 * the time in 24-hour form:
   Enter a 12-hour time: 9:11 PM
   Equivalent 24-hour time: 21:11
 * See Programming Project 8 for a description of the input format. */

#include <stdio.h>

int main(void)
{
    int hour, min;
    char time;

    printf("Enter a 12-hour time: ");
    scanf("%d :%d %c", &hour, &min, &time);

    if (time == 'P') {
        hour += 12;
    }
    printf("Equivalent 24-hour time: %d:%d\n", hour, min);

    return 0;
}