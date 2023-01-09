#include <stdio.h>
#include <string.h>

#define LEN (80)

void encrypt(char *message, int shift);

int main(void)
{
    char message[LEN + 1];
    int shift;

    printf("Enter message to be encrypted: ");
    fgets(message, LEN, stdin);

    printf("Enter shift amount (1-25): ");
    shift = getchar();

    printf("Encrypted message: ");
    encrypt(message, getchar());
    printf("%s\n", message);

    return 0;
}

void encrypt(char *message, int shift)
{
    while (*message) {
        if ('A' <= *message && *message <= 'Z') {
            *message = (((*message - 'A') + shift) % 26) + 'A';
        } else if ('a' <= *message && *message <= 'z') {
            *message = ((*message - 'a') + shift) % 26 + 'a';
        }
        message++;
    }
}