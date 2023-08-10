#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

#define STACK_SIZE (100)

char stack[STACK_SIZE] = {0, };
int g_top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char item);
char pop(void);
void stack_overflow(void);
void stack_underflow(void);
int evaluate_RPN_expression(const char *expression);

int main(void)
{
    char *p;
    char ch;

    char expression[STACK_SIZE];
    for (;;) {
        p = expression;
        printf("Enter an RPN expression: ");
        while (((ch = getchar()) != '\n') && (p < expression + STACK_SIZE)) {
            *p++ = ch;
        }

        printf("Value of expression: %d\n", evaluate_RPN_expression(expression));

        p = expression;
        while (*p) {
            *p++ = '\0';
        }
    }

    return 0;
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

void push(char item)
{
    if (is_full()) {
        stack_overflow();
    } else {
        stack[g_top++] = item;
    }
}

char pop(void)
{
    if (is_empty()) {
        stack_underflow();
    } else {
        return stack[--g_top];
    }
    return EXIT_FAILURE;
}

void stack_overflow(void)
{
    printf("\nExpression is too complex\n");
    exit(EXIT_SUCCESS);
}

void stack_underflow(void)
{
    printf("\nNot enough operands in expression\n");
    exit(EXIT_SUCCESS);
}

int evaluate_RPN_expression(const char *expression)
{
    char oper1 = 1, oper2 = 2;

    while (*expression) {
        if (isdigit(*expression)) {
            push(*expression - '0');
        } else {
            switch (*expression) {
                case '+': 
                    push(pop() + pop());
                    break;
                case '-': 
                    oper2 = pop(); oper1 = pop();
                    push(oper1 - oper2);
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '/':
                    oper2 = pop(); oper1 = pop();
                    push(oper1 / oper2);
                    break;
                case '=':
                    return pop();
                case ' ':
                    break;
                default:
                    exit(EXIT_FAILURE);
            }
        }
        expression++;
    } 
    exit(EXIT_FAILURE);
}