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