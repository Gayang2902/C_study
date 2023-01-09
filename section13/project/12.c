#include <stdio.h>
#include <string.h>

#define WORDS (30) 
#define WORD (20)

void reverse(const char *word);

int main(void)
{
    char sentence[WORDS][WORD + 1];

    char c;
    int terminating_char = 0;
    int row = 0;
    int col = 0;
    
    printf("Enter a sentence: ");
    while ((c = getchar()) != '\n' && row < WORDS) {
        if (c == ' ' || c == '\t') {
            sentence[row][col] = '\0';
            row++;
            col = 0;
            continue;
        }
        if (c == '?' || c == '!' || c == '.') {
            terminating_char = c;
            sentence[row][col] = '\0';
            break;
        } else if (col < WORD) {
            sentence[row][col++] = c;
        }
    }

    printf("Reversal sentence: ");
    while (row) {
        printf("%s ", sentence[row--]);
    }   
    printf("%s%c\n", sentence[row], terminating_char);    

    return 0;
}