#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_DIGITS (10)

// 행마다 숫자의 모양이 담겨져있음.
const int g_segments[10][7] = {
    {1, 1, 1, 1, 1, 1, 0}, 
    {0, 1, 1, 0, 0, 0, 0}, 
    {1, 1, 0, 1, 1, 0, 1}, 
    {1, 1, 1, 1, 0, 0, 1},
    {0, 1, 1, 0, 0, 1, 1}, 
    {1, 0, 1, 1, 0, 1, 1}, 
    {1, 0, 1, 1, 1, 1, 1}, 
    {1, 1, 1, 0, 0, 0, 0}, 
    {1, 1, 1, 1, 1, 1, 1}, 
    {1, 1, 1, 1, 0, 1, 1}};
char g_digits[4][MAX_DIGITS * 4];

const int g_grid[7][2] = {
    {0, 1},
    {1, 2},
    {2, 2},
    {2, 1},
    {2, 0},
    {1, 0},
    {1, 1}};

// g_digtis를 전체공백으로
void clear_digits_array(void);
// 위치에 맞게 digit -> segment 변환
// position range (0 ~ MAX_DIGIT - 1)
void process_digit(int digit, int position);
// g_digits 출력
void print_digits_array(void);

int main(void)
{
    char ch;
    int position = 0;

    clear_digits_array();
    
    printf("Enter a number: ");
    while ((ch = getchar()) != '\n') {
        if (isdigit(ch)) {
            process_digit(ch - '0', position);
            position += 4;
        }
    }
    print_digits_array();

    return 0;
}

void clear_digits_array(void)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < MAX_DIGITS * 4; j++) {
            g_digits[i][j] = ' ';
        }
    }
}

void process_digit(int digit, int position)
{
    for (int i = 0; i < 7; i++) {
        if (g_segments[digit][i]) {
            g_digits[g_grid[i][0]][g_grid[i][1] + position] = i % 3 == 0 ? '_' : '|';
        }
    }
}

void print_digits_array(void)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < MAX_DIGITS * 4; j++) {
            printf("%c", g_digits[i][j]);
        }
        printf("\n");
    }
}   