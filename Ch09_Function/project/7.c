#include <stdio.h>

int power_recursive(int number, int exponent);

int main(void)
{
    int number, exponent;
    printf("Enter number and exponent(number^exponent): ");
    scanf(" %d^%d", &number, &exponent);
    printf("The %d^%d = %d\n", number, exponent, power_recursive(number, exponent));

    return 0;

}
int power_recursive(int number, int exponent)
{
    int i;
    printf("Call\n");
    if (exponent == 0) {
        return 1;
    } else if (exponent % 2 == 0) {
        i = power_recursive(number, exponent / 2);
        return i * i;
    } else {
        return number * power_recursive(number, exponent - 1);
    }
}

// 짝수면 n/2, 2 로
// 홀수면 1, n - 1로  