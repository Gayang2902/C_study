#include <stdio.h>
#include <stdint.h>

int main(void)
{
    printf("%zu", sizeof(char));
    printf("%zu", sizeof(short));
    printf("%zu", sizeof(int));
    printf("%zu", sizeof(long));
    printf("%zu", sizeof(long long));
    
    printf("%zu", sizeof(float));
    // sizeof(double);
    // sizeof(long double);

    return 0;
}