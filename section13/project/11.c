#include <stdio.h>

#define LEN (100)

double compute_average_word_length(const char *sentence);

int main(void)
{
    char sentence[LEN + 1];

    printf("Enter a sentence: ");

    fgets(sentence, LEN, stdin);

    printf("Average word length: %.1f\n", compute_average_word_length(sentence));

    return 0;
}

double compute_average_word_length(const char *sentence)
{
    int words = 0;
    int length = 0;

    while (*sentence) {
        while (*sentence && *sentence != ' ') {
            sentence++;
            length++;
        }
        words++;
        while (*sentence && *sentence == ' ') {
            sentence++;
        }
    }

    return (double)length / words;
}