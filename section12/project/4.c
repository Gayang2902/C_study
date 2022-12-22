#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char str[1000];
    char ch;
    char* p = str;

    printf("Enter a message: ");

    while ((ch = toupper(getchar())) != '\n' && p < str + 1000) {
        if (isalpha(ch)) {
            *(p++) = ch;
        }
    } 

    for (int i = 0; str + i < p; i++) {
        if (*(str + i) != *(--p)) {
            ch = 0;
        }
    }

    if (ch != 0) {
        printf("Palindrome\n");
    } else {
        printf("Not a palindrome\n");
    }

    return 0;
}