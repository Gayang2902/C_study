#include <stdio.h>

// int main(void)
// {
//     float num, large=0;

//     for(;;) {
//         printf("Enter a number: ");
//         scanf(" %f", &num);
//         if (num <= 0) {
//             break;
//         }
//         if (large < num) {
//             large = num;
//         }
//     }

//     printf("The largest number entered was %.2f\n", large);
//     return 0;
// }

// int main(void)
// {
//     int m, n, remainder;

//     printf("Enter two integers: ");
//     scanf("%d %d", &m, &n);

//     while (n!=0) { // using Euclid's algorithm
//         remainder = m % n; 
//         m = n;
//         n = remainder;
//     }
//     printf("Greatest commom divisor: %d\n", m);

//     return 0;
// }

// int main(void)
// {
//     int nemer, denomin;
//     int m, n, mod;

//     printf("Enter a fraction: ");
//     scanf("%d /%d", &nemer, &denomin);

//     m = nemer; n = denomin;
//     while (n!=0) {
//         mod = m % n;
//         m = n;
//         n = mod;
//     }
//     printf("In lowest terms: %d/%d\n", nemer/m, denomin/m);

//     return 0;
// }

// int main(void)
// {
//     float commission;
//     float value;
    
//     for(;;) {
//         printf("Enter value of trade: ");
//         scanf("%f", &value);
//         if (value == 0) break;

//         if (value < 2500.00f) {
//             commission = 30.00f + .017f * value;
//         }   else if (value < 6250.00f) {
//             commission = 56.00f + .0066f * value;
//         } else if (value < 20000.00f) {
//             commission = 76.00f + .0034f * value;
//         } else if (value < 50000.00f) {
//            commission = 100.00f + .0022f * value;
//         } else if (value < 500000.00f) {
//             commission = 155.00f + .0011f * value;
//         } else {
//             commission = 255.00f + .0009f * value;
//         }
//         if (commission < 39.00f) {
//             commission = 39.00f;
//         }

//         printf("Commission: $%.2f\n", commission);
//     }

//     return 0;
// }

// int main(void)
// {
//     int n;
//     scanf("%d", &n);

//     for (int i = 2; i*i <= n; printf("%d\n", i*i), i++);

//     return 0;
// }

// int main(void)
// {
//     int month, start, token;

//     printf("Enter number of days in month: ");
//     scanf("%d", &month);
//     printf("Enter starting day of the week (1=Sun, 7=Sat): ");
//     scanf(" %d", &start);

//     token = 8 - start;
//     for (int i = start; i != 1; i--) printf("   ");
//     for (int i = 1; i <= month; i++) {
//         printf("%2d ", i);
//         token--;
//         if (token == 0) {
//             token = 7;
//             printf("\n");
//         }
//     }
//     printf("\n");

//     return 0;
// }

int main(void)
{
    double e=1, fac=1;;
    int n;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            fac = fac * j;
        }
        e = e + (1/fac);
        fac = 1;
    }
    printf("e: %.4lf\n", e);
    
    return 0;
}