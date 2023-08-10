/* Write a program that evaluates an expression. 
 * The operands in the expression are floating-point numbers; the operators are +, -, * and /. 
 * The expression is evalued from left to right (no operator taes precedence over any other operator). */

#include <stdio.h>

int main(void)
{
    float num;
    float result = 0;
    int operator;

    printf("Enter an expression: ");
    num = scanf("%f", &num);
    result += num;

    while (1) {
        operator = getchar();

        if (operator == '+') {
            scanf("%f", &num);
            result += num;
            continue;
        } else if (operator == '-') {
            scanf("%f", &num);
            result -= num;
            continue;
        } else if (operator == '*') {
            scanf("%f", &num);
            result *= num;
            continue;
        } else if (operator == '/') {
            scanf("%f", &num);
            result /= num;
            continue;
        } else if (operator == '\n') {
            break;
        }
    }
    printf("Value if expression: %.1f\n", result);

    return 0;
}