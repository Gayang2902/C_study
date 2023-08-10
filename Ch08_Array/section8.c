#include <stdio.h>

// #include <stdbool.h>
// int main(void)
// {
//     bool digit_seen[10] = {false, };
//     int occurrences[10] = {0, };
//     int digit;
//     long n;

//     printf("Enter a number: ");
//     scanf("%ld", &n);

//     while (n > 0) {
//         digit = n % 10;
//         occurrences[digit]++;
//         n /= 10;
//     }
//     printf("Digit:           ");
//     for (int i = 0; i < 10; i++)
//         printf("%3d", i);
//     printf("\n");
//     printf("Occurrences:     ");
//     for (int i = 0; i < 10; i++)
//         printf("%3d", occurrences[i]);
//     printf("\n");

//     return 0;
// }

// #define A_LEN ((int) sizeof(a) / sizeof(a[0]))

// int main(void)
// {
//     int a[10];
//     int i;

//     printf("Enter %d numbers: ", 10);
//     for (i = 0; i < A_LEN; i++) {
//         scanf("%d", &a[i]);
//     }

//     printf("In reverse order:");
//     for (i = A_LEN - 1; i >= 0; i--) {
//         printf(" %d", a[i]);
//     }
//     printf("\n");

//     return 0;
// }

// #include <ctype.h>

// int main(void)
// {
//     int str;
//     int length = 30;
//     char string[length];

//     length = 0;
//     printf("Enter message: ");
//         do {
//             string[length] = (char) getchar();
//             string[length] = toupper(string[length]);
//         } while (string[length++] != '\n');

//     printf("In B1FF-speak: ");

//     for (int i = 0; i < length - 1; i++) {
//         switch (string[i]) {
//             case 'A':
//                 string[i] = '4';
//                 break;
//             case 'B':
//                 string[i] = '8';
//                 break;
//             case 'E':
//                 string[i] = '3';
//                 break;
//             case 'I':
//                 string[i] = '1';
//                 break;
//             case 'O':
//                 string[i] = '0';
//                 break;
//             case 'S':
//                 string[i] = '5';
//                 break;
//         }
//         printf("%c", string[i]);
//     }
//     printf("!!!!!!!!!!\n");

//     return 0;
// }

// #define ROW (5)
// #define COLUMN (5)

// int main(void)
// {
//     int array[ROW][COLUMN] = {0, };
//     int row_sum[ROW] = {0, };
//     int col_sum[COLUMN] = {0, };

//     for (int i = 0; i < ROW; i++) {
//         printf("Enter row %d: ", i + 1);
//         for (int j = 0; j < COLUMN; j++) {
//             scanf(" %d", &array[i][j]);
//             row_sum[i] += array[i][j];
//             col_sum[j] += array[j][i];
//         }
//     }
//     printf("\n");

//     printf("Row totals: ");
//     for (int i = 0; i < ROW; i++) {
//         printf("%3d", row_sum[i]);
//     }
//     printf("\n");
//     printf("Column totals: ");
//     for (int i = 0; i < COLUMN; i++) {
//         printf("%3d", col_sum[i]);
//     }
//     printf("\n");

//     return 0;
// }

// #include <stdlib.h>
// #include <time.h>

// #define SIZE (10)
// #define DIRECTION (4)
// #define UP (0)
// #define DOWN (1)
// #define RIGHT (2)
// #define LEFT (3)

// int main(void)
// {
//     char map[SIZE][SIZE] = {
//         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.',},
//         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.',},
//         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.',},
//         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.',},
//         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.',},
//         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.',},
//         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.',},
//         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.',},
//         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.',},
//         {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.',}};
//     char checker = 'A';
//     int direction;
//     int x = 0, y = 0;

//     srand((unsigned) time(NULL));
    
//     map[y][x] = checker;
//     checker += 1;
//     while (checker <= 90) {
//         if (map[y][x + 1] != '.' &&
//             map[y - 1][x] != '.' &&
//             map[y + 1][x] != '.' &&
//             map[y][x - 1] != '.') {
//                 break;
//             }
//         direction = rand() % DIRECTION;
//         printf("DIRECTION: %d\n", direction);
//         switch (direction) {
//             case UP: 
//                 if (y - 1 < 0 || map[y - 1][x] != '.') {
//                     continue;
//                 }
//                 y -= 1;
//                 break;
//             case DOWN:
//                 if (SIZE - 1 < y + 1 || map[y + 1][x] != '.') {
//                     continue;
//                 }
//                 y += 1;
//                 break;
//             case RIGHT:
//                 if (SIZE - 1 < x + 1 || map[y][x + 1] != '.') {
//                     continue;
//                 }
//                 x += 1;
//                 break;
//             case LEFT:
//                 if (x - 1 < 0 || map[y][x - 1] != '.') {
//                     continue;
//                 }
//                 x -= 1;
//                 break;
//         } 
//         map[y][x] = checker;
//         checker += 1;
//     }

//     for (int i = 0; i < SIZE; i++) {
//         for (int j = 0; j < SIZE; j++) {
//             printf("%c ", map[i][j]);
//         }
//         printf("\n");
//     }
//     printf("\n");

//     return 0;
// }

// int main(void)
// {
//     char sentence[100];
//     char c;
//     char question_mark = '?';
//     char exclamation_point = '!';
//     char period = '.';
//     int index = 0;
//     int forward, backward;
    
//     printf("Enter a sentence: ");
    
//     while (1) {
//         sentence[index] = (char)getchar();
//         if (sentence[index] == question_mark || sentence[index] == exclamation_point || sentence[index] == period) {
//             break;
//         }
//         index++;
//     }

//     forward = index - 1;
//     backward = index - 1;
//     printf("Reversal of sentence: ");
//     while (forward > 0) {
//         forward--;
//         if (sentence[forward - 1] == ' ' || forward == 0) {
//             for (int i = forward; i <= backward; i++) {
//                 putchar((int)sentence[i]);
//             }
//             backward = forward - 2;
//             if (forward != 0) {
//                 printf(" ");
//             }
//             continue;
//         }
//     }
//     printf("%c\n", sentence[index]);

//     return 0;
// }

// int main(void)
// {
//     char message[80];
//     char ch;
//     int len = 0;
//     int n;

//     printf("Enter message to be encrypted: ");
//     for (; message[len - 1] != '\n'; message[len] = (char)getchar(), len++);
//     printf("Enter shift amount (1-25): ");
//     scanf("%d", &n);
//     getchar();

//     printf("Encrypted message: ");
//     for (int i = 0; i < len; i++) {
//         ch = message[i];
//         if ('A' <= ch && ch <= 'Z') {
//             message[i] = (((ch - 'A') + n) % 26) + 'A';
//         } else if ('a' <= ch && ch <= 'z') {
//             message[i] = ((ch - 'a') + n) % 26 + 'a';
//         } else continue;
//     }
//     for (int i = 0; i < len; i++) {
//         putchar((int)message[i]);
//     }
//     printf("\n");

//     return 0;
// }

// #include <ctype.h>
// int main(void)
// {
//     int check[26] = {0, };
//     int sum = 0;
//     char ch;

//     printf("Enter first word: ");
//     do {
//         ch = (char)getchar();
//         if (isalpha(ch)) {
//             ch = tolower(ch);
//             check[ch - 97]++;   
//         }
//     } while (ch != '\n');

//     printf("Enter second word: ");
//     do {
//         ch = (char)getchar();
//         if (isalpha(ch)) {
//             ch = tolower(ch);
//             check[ch - 97]--;
//         }
//     } while (ch != '\n');

//     for (int i = 0; (i < 26) && (sum == 0); i++) {
//         sum = check[i];
//     }
//     if (sum == 0) {
//         printf("The words are anagrams.\n");
//     } else {
//         printf("The words are not anagrams.\n");
//     }

//     return 0;
// }

int main(void)
{
    int n;
    int row, col;

    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");
    scanf("%d", &n);

    // 가변크기 배열 선언 후 전체 0으로 초기화
    int array[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            array[i][j] = 0;
        }
    }
    
    // 시작 위치 조정 (마방진의 가운데)
    row = 0;
    col = ((n - 1) / 2);

    array[row][col] = 1;
    for (int i = 2; i <= (n * n); i++) {
        // 이전 반복에서 위치가 첫 번째 행이라면 마지막 행으로 위치 변경
        if (row == 0) {
            row = n;
        }
        // 다음 위치가 비어 있지 않다면 바로 아래로 위치 변경
        if (array[(row - 1)][(col + 1) % n] != 0) {
            row = (row + 1) % n;
        }
        else {
            row = (row - 1);
            // 모듈러 연산을 통해 배열의 인덱스를 벗어나는 n이 되면 0이 되도록 조정
            col = (col + 1) % n;
        }
        // 배열에 숫자를 넣기 위해 i와 실제 반복 카운트를 맞춤
        array[row][col] = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%6d", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}