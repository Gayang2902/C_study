#include <stdio.h>

#define SIZE (10)

void selection_sort_recursive(int arr[], int n);

int main(void)
{
    int array[SIZE];

    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &array[i]);
    }

    selection_sort_recursive(array, SIZE);

    for (int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

void selection_sort_recursive(int array[], int n)
{
    if (n == 1) {
        return;
    }

    int largest, temp;
    largest = 0;

    for (int i = 0; i < n; i++) {
        if (array[i] > array[largest]) {
            largest = i;
        }
    }
    temp = array[n - 1];
    array[n - 1] = array[largest];
    array[largest] = temp;

    return selection_sort_recursive(array, n - 1);
}