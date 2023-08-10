#include <stdio.h>
#include "stack.h"

int main(void)
{
    char ch;
    for (;;) {
        printf("Enter an RPN expression: ");
        do {
            scanf(" %c", &ch);
            reverse_polish_notation(ch);
        } while (ch != '=');
        printf("Value of expression: %d\n", pop());
    }
}