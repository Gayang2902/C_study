#include <stdio.h>

void create_magic_square(int n, char magic_square[n][n]);
void print_magic_square(int n, char magic_square[n][n]);

int main(void)
{
    int n;

    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");
    scanf("%d", &n);
    char array[n][n];

    create_magic_square(n, array);
    print_magic_square(n, array);

    return 0;
}

void create_magic_square(int n, char array[n][n])
{
    int row, col;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            array[i][j] = 0;
        }
    }
    
    row = 0;
    col = ((n - 1) / 2);
    array[row][col] = 1;
    for (int i = 2; i <= (n * n); i++) {
        if (row == 0) {
            row = n;
        }
        if (array[(row - 1) % n][(col + 1) % n] != 0) {
            row = (row + 1) % n;
        } else {
            row = (row - 1) % n;
            col = (col + 1) % n;
        }
        array[row][col] = i;
    }
}

void print_magic_square(int n, char array[n][n])
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%6d", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}