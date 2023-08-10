/* Modify Programming Project 6 from Chapter 10 so that it uses the stack ADT described in Section 19.4. 
 * You may use any of the implementations of the ADT described in that section.*/

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include "stack-ADT.h"

void reverse_polish_notation(Stack s, char ch);

int main(void)
{
    Stack s = create_stack();

    char ch;
    for (;;) {
        printf("Enter an RPN expression: ");
        do {
            scanf(" %c", &ch);
            reverse_polish_notation(s, ch);
        } while (ch != '=');
        printf("Value of expression: %d\n", pop(s));
    }

    destroy_stack(s);

    return 0;
}

void reverse_polish_notation(Stack s, char ch)
{
    char oper1, oper2;
    char result;
    if ('0' <= ch && ch <= '9') {
        push(s, ch - '0');
    } else if (ch == '=') {
        return;
    } else if (isalpha(ch)) {
        exit(EXIT_SUCCESS);
    } else {
        oper2 = pop(s);
        oper1 = pop(s);
        if (ch == '+') {
            result = oper1 + oper2;
            printf("%d + %d\n", oper1, oper2);
        } else if (ch == '-') {
            result = oper1 - oper2;
            printf("%d - %d\n", oper1, oper2);
        } else if (ch == '*') {
            result = oper1 * oper2;
            printf("%d * %d\n", oper1, oper2);
        } else if (ch == '/') {
            result = oper1 / oper2;
            printf("%d / %d\n", oper1, oper2);
        } else {
            exit(EXIT_SUCCESS);
        }
        push(s, result);
    }
}