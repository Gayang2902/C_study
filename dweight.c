// 부피와 무게를 구해주는 프로그램

#include <stdio.h>

int main(void)
{
    int height = 8;
    int length = 12;
    int width = 10;
    int volume;

    volume = height * length * width;

    printf("Dimensions: %dx%dx%d\n", length, width, height);
    printf("Volume (cubic inches): %d\n", volume);
    printf("Dismensional weight (pounds): %d\n", (volume + 165) / 166);

    return 0;
}