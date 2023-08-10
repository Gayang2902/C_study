#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool is_palindrome(const char *message);

int main(void)
{
    char str[1000];
    char ch;
    char *p = str;

    printf("Enter a message: ");

    while ((ch = toupper(getchar())) != '\n' && p < str + 1000) {
        if (isalpha(ch)) {
            *(p++) = ch;
        }
    } 
    *p = '\0';

    if (is_palindrome(str)) {
        printf("Palindrome\n");
    } else {
        printf("Not a palindrome\n");
    }

    return 0;
}

bool is_palindrome(const char *message)
{
    int i = 0;
    int j = strlen(message) - 1;

    while (i < j) {
        // printf("center = %d\n", center--);
        // printf("message[i] = %c\tmessage[j] = %c\n", message[i], message[j]);
        if (message[i++] != message[j--]) {
            return false;
        }
    }
    return true;
}