#include <stdio.h>

float income_tax(float income);

int main(void)
{
    float income;
    float tax;

    printf("Enter the amount of taxable income: ");
    scanf("%f", &income);

    tax = income_tax(income);
    
    printf("The tax is %.2f\n", tax);

    return 0;
}

float income_tax(float income)  
{
    if (income <= 750) {
        return income * 0.01f;
    } else if (750 < income && income <= 2250) {
        return 7.50f + income * 0.02f;
    } else if (2250 < income && income <= 3750) {
        return 37.50f + income * 0.03f;
    } else if (3750 < income && income <= 5250) {
        return 85.50f + income * 0.04f;
    } else if (5250 < income && income <= 7000) {
        return 142.50f + income * 0.05f;
    } else {
        return 230.00f + income * 0.06f;
    }
}