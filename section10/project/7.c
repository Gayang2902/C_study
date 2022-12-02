#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITS (10)

// 행마다 숫자의 모양이 담겨져있음.
const int g_segments[10][7] = {
    {1, 1, 1, 1, 1, 1, 0}, {0, 1, 1, 0, 0, 0, 0}, {1, 1, 0, 1, 1, 0, 1}, {1, 1, 1, 1, 0, 0, 1},
    {0, 1, 1, 0, 0, 1, 1}, {1, 0, 1, 1, 0, 1, 1}, {1, 0, 1, 1, 1, 1, 1}, {1, 1, 1, 0, 0, 0, 0}, 
    {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 0, 1, 1}};
char g_digits[4][40];

// g_digtis를 전체공백으로
void clear_digits_array(void);
// 위치에 맞게 digit -> segment 변환
// position range (0 ~ MAX_DIGIT - 1)
void process_digit(int digit, int position);
// g_digits 출력
void print_digits_array(void);

int main(void)
{
    for (;;) {
        clear_digit_array();
        printf("Enter a number: ");
        for (int i = 0; i < MAX_DIGITS; i++) {
            process_digit(getchar(), i);
        }
        print_digits_array();
    }

    return 0;
}

void clear_digits_array(void)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 40; j++) {
            g_digits[i][j] = ' ';
        }
    }
}

void process_digit(int digit, int position)
{
    if (digit == 'e') {
        printf("EXIT\n");
        exit(EXIT_SUCCESS);
    }


}

void print_digits_array(void)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 40; j++) {
            printf("%c", g_digits[i][j]);
        }
        printf("\n");
    }
}   