#include <stdio.h>

#define LEN (100)

int main(void)
{
    char ch;
    char str[LEN];
    char* p = str;

    printf("Enter a message: ");
    while ((ch = getchar()) != '\n' && p < str + LEN) {
        *(p++) = ch;
    }
    p--;

    printf("Reversal is: ");
    while (p >= str) {
        printf("%c", *(p--));
        // putchar(*p--);
    }
    printf("\n");

    return 0;
}