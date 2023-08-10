#include <stdio.h>

double get_average(double left, double right) 
{
    return (left + right) / 2;
}

int main(void)
{
    double x;
    double y;
    double z;

    printf("Enter three numbers: ");
    scanf("%lf %lf %lf", &x, &y, &z);
    printf("Average of %g and %g: %g\n", x, y, get_average(x, y));
    printf("Average of %g and %g: %g\n", y, z, get_average(y, z));
    printf("Average of %g and %g: %g\n", x, z, get_average(x, z));

    return 0;
}