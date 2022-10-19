// 부피와 무게를 구해주는 프로그램

#include <stdio.h>

int main(void)
{
    int height;
    int length;
    int width;
    int volume;
    int weight;

    height = 8;
    length = 12;
    width = 10;

    volume = height * length * width;
    weight = (volume + 165) / 166;

    printf("Dimensions: %dx%dx%d\n", length, width, height);
    printf("Volume (cubic inches): %d\n", volume);
    printf("Dismensional weight (pounds): %d\n", weight);

    return 0;
}