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

// #include <ctype.h>
// int main(void)
// { // 12:00 pm = 720
//     int hour, min, con;
//     char time;
//     printf("Enter a 12-hour time: ");
//     scanf("%d:%d %c", &hour, &min, &time);

//     time = toupper(time);
//     if (time == 'P') {
//         hour += 12;
//     }
//     con = ((hour*60) + min) / 100;
    

//     switch (con) {
//     case 4:
//         printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.\n");
//         break;
//     case 5:
//         printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m.\n");
//         break;
//     case 6:
//         printf("Closest departure time is 11:19 a.m., arriving at 1:31 p.m.\n");
//         break;
//     case 7:
//         printf("Closest departure time is 12:47 p.m., arriving at 3:00 p.m.\n");
//         break;
//     case 8:
//         printf("Closest departure time is 2:00 p.m., arriving at 4:08 p.m.\n");
//         break;
//     case 9:
//         printf("Closest departure time is 3:45 p.m., arriving at 5:55 p.m.\n");
//         break;
//     case 11:
//         printf("Closest departure time is 7:00 p.m., arriving at 9:20 p.m.\n");
//     case 13:
//         printf("Closest departure time is 9:45 p.m., arriving at 11:58 p.m.\n");
//         break;
//     }

//     return 0;    
// }

// int main(void)
// {
//     int hour, min;
//     char time;

//     printf("Enter a 12-hour time: ");
//     scanf("%d :%d %c", &hour, &min, &time);

//     if (time == 'P') {
//         hour += 12;
//     }
//     printf("Equivalent 24-hour time: %d:%d\n", hour, min);

//     return 0;
// }

// #include <ctype.h>
// int main(void)
// {
//     int vowels = 0;
//     int character;

//     printf("Enter a sentence: ");
    
//     do {
//         character = getchar();
//         character = toupper(character);
//         if (character == 'A' || character == 'E' || character == 'I' || character == 'O' || character == 'U') {
//             ++vowels;
//         }
//     } while (character != '\n');

//     printf("Your sentence contains %d vowels.\n", vowels);
    
//     return 0;
// }

// int main(void)
// {
//     char initial;
//     int str;

//     printf("Enter a first and last name: ");

//     scanf(" %c", &initial);
//     getchar();

//     while (getchar() != ' ');

//     while (1) {
//         str = getchar();
//         if (str == '\n' || str == ' ') {
//             break;
//         }
//         putchar(str);    
//     }
    
//     printf(", %c.\n", initial);

//     return 0;
// }

// int main(void)
// {
//     float num;
//     float result = 0;
//     int operator;

//     printf("Enter an expression: ");
//     num = scanf("%f", &num);
//     result += num;

//     while (1) {
//         operator = getchar();

//         if (operator == '+') {
//             scanf("%f", &num);
//             result += num;
//             continue;
//         } else if (operator == '-') {
//             scanf("%f", &num);
//             result -= num;
//             continue;
//         } else if (operator == '*') {
//             scanf("%f", &num);
//             result *= num;
//             continue;
//         } else if (operator == '/') {
//             scanf("%f", &num);
//             result /= num;
//             continue;
//         } else if (operator == '\n') {
//             break;
//         }
//     }
//     printf("Value if expression: %.1f\n", result);

//     return 0;
// }

// int main(void)
// {
//     int cha;
//     int each_length = 0, sentence = 0;

//     printf("Enter a sentence: ");

//     while (1) {
//         cha = getchar();
//         if (cha == ' ') {
//             sentence++;
//             continue;
//         } else if (cha == '.') {
//             sentence++;
//             printf("Average word length: %.1f\n", (float)each_length / sentence);
//             return 0;
//         }
//         each_length++;
//     }
// }

// #include <math.h> // fabs() 를 이용해 double의 absolute 값을 구한다.

// int main(void) // 제곱근을 가장 효율적으로 구하는 뉴턴-랩슨법
// {   
//     double x;
//     double y = 1.0f, average;
//     double old_y;
//     int i = 1;
//     // y의 기존 값과 Y의 새 값의 차이의 절대 값이 .00001과 y의 곱보다 작을 때.

//     printf("Enter a positive number: ");
//     scanf("%lf",&x);
    
//     do {
//         average = ((x/y) + y) / 2;
//         old_y = y;
//         y = average;
//         printf("%d\n", i++); 
//     } while (fabs(y - old_y) > (.00001 * y));

//     printf("Square root: %.5lf\n", y);

//     return 0;
// }

// int main(void)
// {
//     int factorial;
//     long double f = 1, i = 1;

//     printf("Enter a positive integer: ");
//     scanf("%d", &factorial);

//     for (; i <= factorial; f *= i, i++);

//     printf("Factorial of %d: %Lf\n", factorial, f);
//     return 0;   
// }

