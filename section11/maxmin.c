#include <stdio.h>

#define ARRAY_SIZE (10)

void get_max_min(int arr[], int size, int* out_max, int* out_min);

int main(void)
{
    int int_arr[ARRAY_SIZE] = {0, };
    int big = 0;
    int small = 0;

    printf("Enter %d numbers: ", ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        scanf("%d", &int_arr[i]);
    }

    get_max_min(int_arr, ARRAY_SIZE, &big, &small);

    printf("Largest: %d\n", big);
    printf("Smallest: %d\n", small);

    return 0;
}

void get_max_min(int arr[], int size, int* out_max, int* out_min)
{
    *out_max = *out_min = arr[0];
    for (int i = 0; i < size; i++) {
        if (*out_max < arr[i]) {
            *out_max = arr[i];
        } else if (arr[i] < *out_min) {
            *out_min = arr[i];
        }
    }
}