// 화씨를 섭씨로 바꿔주는 프로그램

#include <stdio.h>

#define FREZZING_PT (32.0f)
#define SCALE_FACTOR (5.0f / 9.0f)

int main(void)
{
    float fahrenheit;
    float celsius;

    printf("Enter Fahrenheit temperature: ");
    scanf("%f", &fahrenheit);

    celsius = (fahrenheit - FREZZING_PT) * SCALE_FACTOR;
    printf("Celsius equivalent: %.1f\n", celsius);

    return 0;
}