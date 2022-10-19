#include <stdio.h>

// int main(void)
// {
//     printf("       *\n      *\n     *\n*   *\n * *\n  *\n");
//     return 0;
// }

// #define V ((4.0f / 3.0f) * 3.14f)
// int main(void)
// {
//     int radius = 10;
//     printf("V: %.1f\n", V*radius*radius*radius);
//     return 0;
// }

// #define V ((4.0f / 3.0f) * 3.14f)
// int main(void)
// {
//     float radius;
//     scanf("%f", &radius);
//     printf("V: %.1f\n", V*radius*radius*radius);
//     return 0;
// }

// int main(void)
// {
//     float money;
//     printf("Enter an amount: ");
//     scanf("%f", &money);
//     printf("With tax added: %.2f\n", money+((5/money)*100));
//     return 0;
// }

// int main(void)
// {
//     int x;
//     scanf("%d", &x);
//     printf("%d\n", (3*x*x*x*x*x)+(2*x*x*x*x)-(5*x*x*x)-(7*x*x)-6);
//     return 0;
// }

// int main(void)
// {
//     int us_dollar;

//     printf("Enter a dollar amount: ");
//     scanf("%d", &us_dollar);
//     printf("#20 bills: %d\n", us_dollar / 20);
//     us_dollar %= 20;
//     printf("#10 bills: %d\n", us_dollar / 10);
//     us_dollar %= 10;
//     printf("$5 bills: %d\n", us_dollar / 5);
//     us_dollar %= 5;
//     printf("#1 bills: %d\n", us_dollar / 1);
//     us_dollar %= 1;
//     return 0;
// }

int main(void)
{
    float loan;
    float rate;
    float payment;

    printf("Enter amount of loan: ");
    scanf("%f", &loan);
    printf("Enter interest rate: ");
    scanf("%f", &rate);
    rate = loan * (rate / 100 / 12);
    printf("Enter monthly payment: ");
    scanf("%f", &payment);

    loan = (loan - payment + rate);
    printf("Balance remaining after first payment: %.2f\n", loan);
    loan = (loan - payment + rate);
    printf("Balance remaining after second payment: %.2f\n", loan);
    loan = (loan - payment + rate);
    printf("Balance remaining after third payment: %.2f\n", loan);
    return 0;
}