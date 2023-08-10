#include <stdio.h>

// int main(void)
// {
//     int i;
//     int n;
//     int odd;
//     int square;

//     printf("This program prints a table of squares.\n");
//     printf("Enter number of entries in table: ");
//     scanf("%d", &n);
//     getchar();

//     i = 1;
//     odd = 3;
//     for(square=1; i<=n; odd+=2) {
//         printf("%10d%10d\n", i, square);
//         ++i;
//         if (i % 24 == 0) {
//             do {
//                 printf("Prss Enter to continue...");
//             } while (getchar() != '\n');
//         }
//         square += odd;
//     }
//     return 0;
// }

// #include <ctype.h>

// int main(void)
// {
//     int word;
//     int count = 0;

//     printf("Enter a word: ");

//     do {
//         word = getchar();
//         word = toupper(word);
//         switch (word) {
//             case 'A':
//             case 'E':
//             case 'I':
//             case 'L':
//             case 'N':
//             case 'O':
//             case 'R':
//             case 'S':
//             case 'T':
//             case 'U':
//                 count += 1;
//                 break;
//             case 'D':
//             case 'G':
//                 count += 2;
//                 break;
//             case 'B':
//             case 'C':
//             case 'M':
//             case 'P':
//                 count += 3;
//                 break;
//             case 'F':
//             case 'H':
//             case 'V':
//             case 'W':
//             case 'Y':
//                 count += 4;
//                 break;
//             case 'K':
//                 count += 5;
//                 break;
//             case 'J':
//             case 'X':
//                 count += 8;
//                 break;
//             case 'Q':
//             case 'Z':
//                 count += 10;
//                 break;
//         } 
//     } while (word != '\n');

//     printf("Scrabble value: %d\n", count);

//     return 0;
// }

// int main(void)
// {
//     printf("%zu\n", sizeof(int));
//     printf("%zu\n", sizeof(short));
//     printf("%zu\n", sizeof(long));
//     printf("%zu\n", sizeof(float));
//     printf("%zu\n", sizeof(double));
//     printf("%zu\n", sizeof(long double));
//     return 0;
// }