#include <stdio.h>
#include <ctype.h>

int compute_scrabble_value(const char *sentence);

int main(void)
{
    int sum;
    char word[81];

    printf("Enter a word: ");
    scanf("%s", word);

    printf("Scrabble value: %d\n", compute_scrabble_value(word));

    return 0;    
}

int compute_scrabble_value(const char *sentence)
{
    int sum = 0;
    int values[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3,
                   1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    while (*sentence) {
        sum += values[toupper(*sentence++) - 'A'];
    }

    return sum;
}