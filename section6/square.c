#include <stdio.h>

int main(void)
{
    int num;
    int square;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &num);

    square = 1;

    while (square <= num) {
        printf("%10d%10d\n", square, square*square);
        square++;
    }

    return 0;
}