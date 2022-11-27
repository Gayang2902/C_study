#include <stdio.h>
#include <math.h>

double compute_polynomial(double);

int main(void)
{
    double x;
    
    scanf("%lf", &x);

    printf("3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 | x = %.0lf\n --> %.0lf\n", x, compute_polynomial(x));
    
    return 0;
}

double compute_polynomial(double x)
{
    return (3 * pow(x, 5)) + (2 * pow(x, 4)) - (5 * pow(x, 3)) - pow(x, 2) + (7 * x) - 6;
}