#include <stdio.h>

// int main(void)
// {
//     int num;
//     int digit;
    
//     printf("Enter a number: ");
//     scanf("%d", &num);
    
//     if (0 <= num && num <= 9)
//         digit = 1;
//     else if (10 <= num && num <= 99)
//         digit = 2;
//     else if (100 <= num && num <= 999)
//         digit = 3;
//     else if (1000 <= num && num <= 9999)
//         digit = 4;
//     else if (10000 <= num && num <= 99999)
//         digit = 5;
//     else
//         digit = 0;
    
//     printf("The number %d has %d digits\n", num, digit);
    
//     return 0;
// }

// int main(void)
// {
//     int hour, min;

//     printf("Enter a 24-hour time: ");
//     scanf("%d : %d", &hour, &min);

//     if (hour <= 12) {
//         printf("Equivalent 12-hour time: %d:%d AM\n", hour, min);
//     } else {
//         hour -= 12;
//         printf("Equivalent 12-hour time: %d:%d PM\n", hour, min);
//     }

//     return 0;
// }

// 3번 문제 이어서 풀이할 것.
// int main(void)
// {
//     float num_of_share;
//     float price_per_share;

//     printf("Enter the numbers of shares and the price per share: ");
//     scanf("%f , %f", &num_of_share, &price_per_share);

//     if (value < 2500.00f) {
//         commission = 30.00f + .017f * value;
//     } else if (value < 6250.00f) {
//         commission = 56.00f + .0066f * value;
//     } else if (value < 20000.00f) {
//         commission = 76.00f + .0034f * value;
//     } else if (value < 50000.00f) {
//         commission = 100.00f + .0022f * value;
//     } else if (value < 500000.00f) {
//         commission = 155.00f + .0011f * value;
//     } else {
//         commission = 255.00f + .0009f * value;
//     }

//     if (commission < 39.00f) {
//         commission = 39.00f;
//     }

//     printf("Commission: $%.2f\n", commission);

//     return 0;
// }

// int main(void)
// {
//     float knots;

//     printf("Enter a wind speed (in knots): ");
//     scanf("%f", &knots);
    
//     if (knots < 1) {
//         printf("Calm\n");
//     } else if (1 <= knots && knots <= 3) {
//         printf("Light air\n");
//     } else if (4 <= knots && knots <= 27) {
//         printf("Breeze\n");
//     } else if (28 <= knots && knots <= 47) {
//         printf("Gale\n");
//     } else if (48 <= knots && knots <= 63) {
//         printf("Storm\n");
//     } else if (63 < knots) {
//         printf("Hurricane\n");
//     }

//     return 0;
// }

// int main(void)
// {
//     float income;
//     float tax;

//     printf("Enter the amount of taxable income: ");
//     scanf("%f", &income);

//     if (income <= 750) {
//         tax = income * 0.01f;
//     } else if (750 < income && income <= 2250) {
//         tax = 7.50f + income * 0.02f;
//     } else if (2250 < income && income <= 3750) {
//         tax = 37.50f + income * 0.03f;
//     } else if (3750 < income && income <= 5250) {
//         tax = 85.50f + income * 0.04f;
//     } else if (5250 < income && income <= 7000) {
//         tax = 142.50f + income * 0.05f;
//     } else {
//         tax = 230.00f + income * 0.06f;
//     }

//     printf("The tax is %.2f\n", tax);

//     return 0;
// }

// int main(void) // 6번 문제는 생략
// {
//     int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11;
//     int check_digit;
    
//     printf("Enter the first (single) digit: ");
//     scanf("%d", &n1);
//     printf("Enter first group of five digits: ");
//     scanf("%1d%1d%1d%1d%1d", &n2, &n3, &n4, &n5, &n6);
//     printf("Enter second group fo five digits: ");
//     scanf("%1d%1d%1d%1d%1d", &n7, &n8, &n9, &n10, &n11);

//     check_digit = (9 - ((((n1+n3+n5+n7+n9+n11) * 3) + (n2+n4+n6+n8+n10)) - 1) % 10);
//     printf("Check digit: %d\n", check_digit);

//     return 0;
// }

// int main(void)
// {
//     int num1, num2, num3, num4;
//     int largest, smallest;

//     printf("Enter four integers: ");
//     scanf("%d %d %d %d", &num1, &num2, &num3, &num4);
//     largest = num1;
//     smallest = num1;

//     if (num2 < largest) {
//         num2 = smallest;
//     } else largest = num2;
//     if (num3 < largest) {
//         if (num3 < smallest) {
//             smallest = num3;
//         }
//     } else largest = num3;
//     if (num4 < largest) {
//         if (num4 < smallest) {
//             smallest = num4;
//         }
//     } else largest = num4;
    

//     printf("Largest: %d\nSmallest: %d\n", largest, smallest);

//     return 0;    
// }

// int main(void)
// { // 12:00 pm = 720
//     int hour, min, con;
//     printf("Enter a 24-hour time: ");
//     scanf("%d:%d", &hour, &min);

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
//     int mm1, dd1, yy1, mm2, dd2, yy2;
//     int yy, dd, mm;
//     printf("Enter first date (mm/dd/yy): ");
//     scanf("%d /%d /%d", &mm1, &dd1, &yy1);
//     printf("Enter second date (mm/dd/yy): ");
//     scanf("%d /%d /%d", &mm2, &dd2, &yy2);

//     if (yy1 < yy2) {
        
//     }
// }

// int main(void)
// {
//     int grade;
//     int ten, one;
//     printf("Enter numerical grade: ");
//     scanf("%d", &grade);

//     ten = grade / 10;
//     one = grade % 10;

//     switch (ten) {
//     case 10:
//         if (0 < one) {
//             printf("ERROR\n");
//             break;
//         }
//     case 9:
//         printf("Letter grade: A\n");
//         break;
//     case 8:
//         printf("Letter grade: B\n");
//         break;
//     case 7:
//         printf("Letter grade: C\n");
//         break;
//     case 6:
//         printf("Letter grade: D\n");
//         break;
//     case 5:
//         /* international fallthrough */
//     case 4:
//         /* international fallthrough */
//     case 3:
//         /* international fallthrough */
//     case 2:
//         /* international fallthrough */
//     case 1:
//         /* international fallthrough */
//     case 0:
//         if (grade < 0) {
//             printf("ERROR\n");
//             break;
//         }
//         printf("Letter grade: F\n");
//         break;
//     default:
//         printf("ERROR\n");
//     }

//     return 0;
// }

// int main(void)
// {
//     int num;
//     int ten, one;
//     printf("Enter a two-digit number: ");
//     scanf("%d", &num);
//     ten = num / 10;
//     one = num % 10;

//     switch (ten) {
//     case 9:
//         printf("You entered the number ninety-");
//         break;
//     case 8:
//         printf("You entered the number eighty-");
//         break;
//     case 7:
//         printf("You entered the number seventy-");
//         break;
//     case 6:
//         printf("You entered the number sixty-");
//         break;
//     case 5:
//         printf("You entered the number fifty-");
//         break;
//     case 4:
//         printf("You entered the number forty-");
//         break;
//     case 3:
//         printf("You entered the number thirty-");
//         break;
//     case 2:
//         printf("You entered the number twenty-");
//         break;
//     case 1:
//         if (one == 1) {
//             printf("You entered the number eleven.\n");
//         } else if (one == 2) {
//             printf("You entered the number twelve.\n");
//         } else if (one 
//     }
// }