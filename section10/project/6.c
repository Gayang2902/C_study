#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

#define STACK_SIZE (100)

char stack[STACK_SIZE];
int g_top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
bool push(char item);
char pop(void);
void reverse_polish_notation(char);
void stack_overflow();
void stack_underflow();

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

void make_empty(void)
{
    g_top = 0;
}

bool is_empty(void)
{
    return g_top == 0;
}

bool is_full(void)
{
    return g_top == STACK_SIZE;
}

bool push(char item)
{
    if (is_full()) {
        stack_overflow();
    }
    stack[g_top++] = item;
    return true;
}

char pop(void)
{
    if (is_empty()) {
        stack_underflow();
    } else {
        return stack[--g_top];
    }
}

void reverse_polish_notation(char ch)
{
    char oper1, oper2;
    char result;
    if ('0' <= ch && ch <= '9') {
        push(ch - '0');
    } else if (ch == '=') {
        return;
    } else if (isalpha(ch)) {
        exit(EXIT_SUCCESS);
    } else {
        oper2 = pop();
        oper1 = pop();
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
        push(result);
    }
}

void stack_overflow(void)
{
    printf("Expression is too complex\n");
    exit(EXIT_SUCCESS);
}

void stack_underflow(void)
{
    printf("Not enough operands in expression\n");
    exit(EXIT_SUCCESS);
}