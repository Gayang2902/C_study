#include <stdio.h>
#include <string.h>

#define MAX (20)

int main(void)
{
    char word[MAX + 1];
    char smallest[MAX + 1];
    char largest[MAX + 1]; 

    printf("Enter word: ");
    scanf("%20s", word);
    strcpy(smallest, word);
    strcpy(largest, word);

    while (strlen(word) != 4) {
        printf("Enter word: ");
        scanf("%20s", word);
        if (strcmp(word, smallest) < 0) {
            strcpy(smallest, word);
        } else if (strcmp(word, largest) > 0) {
            strcpy(largest, word);
        }
    }

    printf("\nSmallest word: %s\nLargest word: %s\n", smallest, largest);

    return 0;
}