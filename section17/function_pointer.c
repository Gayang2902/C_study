#include <math.h>
#include <stdlib.h>

#define PI (3.14)

double integrate(double (*f)(double), double a, double b);

int main(void)
{
    double result;

    result = integrate(sin, 0.0, PI / 2);
    
}