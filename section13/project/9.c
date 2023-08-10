#include <ctype.h>
#include <stdio.h>

int compute_vowel_count(const char *sentence);

int main(void)
{
    char character[100];
    char ch;
    char *p = character;

    printf("Enter a sentence: ");

    while ((ch = getchar()) != '\n' && p < character + 100) {
        *(p++) = ch;
    }
    *p = '\0';

    printf("Your sentence contains %d vowels.\n", compute_vowel_count(character));
    
    return 0;
}

int compute_vowel_count(const char *sentence)
{   
    int vowels = 0;

    while (*sentence) {
        switch (toupper(*sentence)) {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                vowels++;
                break;
            default:
                break;
        }
        sentence++;
    }

    return vowels;
}