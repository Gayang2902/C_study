#include <stdio.h>

#define MAX (100) 

int main(void)
{
    char ch, terminating_ch;
    char *p, *q;
    char str[MAX] = {0, };

    printf("Enter a sentence: ");
    for (p = str; (ch = getchar()) != '\n' && p < str + MAX; p++) {
        if (ch == '.' || ch == '!' || ch == '?') {
            terminating_ch = ch;
            break;
        }
        *p = ch;
    }

    printf("Reversal of sentence: ");
    while (p >= str) {
        while (*(--p) != ' ' && p != str);
        q = p == str ? str : p + 1;
        while (*q != ' ' && *q != '\0') {
            // printf("%c", *(q++));
            putchar(*(q++));
        }
        if (str <= p) {
            // printf(" ");
            putchar(' ');
        }
    }

    printf("%c\n", terminating_ch);
    printf("\n");
    
    return 0;
}