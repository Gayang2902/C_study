#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define LEN (80)

bool are_anagrams(const char *word1, const char *word2);

int main(void)
{
    char wordo[LEN + 1] = {0, };
    char wordt[LEN + 1] = {0, };

    printf("Enter first word: ");
    fgets(wordo, LEN, stdin);

    printf("Enter second word: ");
    fgets(wordt, LEN, stdin);

    if (are_anagrams(wordo, wordt)) {
        printf("The words are anagrams.\n");
    } else {
        printf("The words are not anagrams.\n");
    }

    return 0;
}

bool are_anagrams(const char *word1, const char *word2)
{
    char checker[26] = {0, };

    while (*word1) {
        if (isalpha(*word1)) {
            checker[toupper(*word1) - 'A']++;
        }
        word1++;
    }
    while (*word2) {
        if (isalpha(*word2)) {
            checker[toupper(*word2) - 'A']--;
        }
        word2++;
    }
    for (int i = 0; i < 26; i++) {
        if (checker[i] != 0) {
            return false;
        }
    }
    return true;
}