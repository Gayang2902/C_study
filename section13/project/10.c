#include <stdio.h>

void reverse_name(char *name);

int main(void)
{
    char initial;
    int str;

    printf("Enter a first and last name: ");

    scanf(" %c", &initial);
    getchar();

    while (getchar() != ' ');

    while (1) {
        str = getchar();
        if (str == '\n' || str == ' ') {
            break;
        }
        putchar(str);    
    }
    
    printf(", %c.\n", initial);

    return 0;
}

void reverse_name(char *name)
{
    
}