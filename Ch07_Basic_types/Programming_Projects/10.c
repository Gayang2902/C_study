/* Write a program that counts the number of vowels (a, e, i, o, u) in a sentence: 
   Enter a sentence: And that's the way it is. 
   Your sentence contains 6 vowels. 
 */

#include <ctype.h>
#include <stdio.h>

int main(void)
{
    int vowels = 0;
    int character;

    printf("Enter a sentence: ");
    
    do {
        character = getchar();
        character = toupper(character);
        if (character == 'A' || character == 'E' || character == 'I' || character == 'O' || character == 'U') {
            ++vowels;
        }
    } while (character != '\n');

    printf("Your sentence contains %d vowels.\n", vowels);
    
    return 0;
}