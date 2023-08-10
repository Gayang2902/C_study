/* Write a program that takes a first name and last name entered by the user and displays
 * the last name, a comma, and the first initial, followed by a period:
   Enter a first and last name: Lloyd Fosdick
   Fodsick, L.
 * The user's input may contain extre spaces before the first name, between the first and last names,
 * and after the last name. */

#include <stdio.h>

int main(void)
{
    char initial;
    int str;

    printf("Enter a first and last name: ");

    scanf(" %c", &initial);
    getchar();

    while (getchar() != ' ');

    while (1) {
        str = getchar();
        if (str == '\n' || str == ' ') {
            break;
        }
        putchar(str);    
    }
    
    printf(", %c.\n", initial);

    return 0;
}