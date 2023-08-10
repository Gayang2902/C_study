#include <stdio.h>
#include <string.h>

#define LEN (100)

void reverse(char *message);

int main(void)
{
    char ch;
    char str[LEN];
    char* p = str;

    printf("Enter a message: ");
    while ((ch = getchar()) != '\n' && p < str + LEN) {
        *(p++) = ch;
    }
    *p = '\0';

    // reverse(str);
    // for (int i = 0; i < strlen(str); i++) {
    //     printf("%c", str[i]);
    // }
    // printf("\n");

    reverse(str);
    printf("Reversal is: %s\n", str);

    return 0;
}

void reverse(char *message)
{
    char *op = message;
    char *tp = message + strlen(message) - 1;
    char temp;

    while (op != tp) {
        printf("%c\n", *op);
        printf("%c\n", *tp);
        temp = *op;
        *op++ = *tp;
        *tp-- = temp;
    }
}