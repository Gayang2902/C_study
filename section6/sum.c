#include <stdio.h>

int main(void)
{
    int num;
    int sum = 0;

    printf("This programs sums a series of integers.\n");
    printf("Enter integers (0 to terminate): ");

    scanf("%d", &num);
    while (num != 0) {
        sum += num;
        scanf(" %d", &num);
    }
    printf("The sum is: %d\n", sum);

    return 0;
}