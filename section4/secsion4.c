#include <stdio.h>

// int main(void)
// {
//     int num;
//     int sep1, sep2, sep3;

//     printf("Enter a two-digit number: ");
//     scanf("%d", &num);
//     sep1 = num / 100;
//     sep2 = (num % 100) / 10;
//     sep3 = (num % 100) % 10;
//     printf("The %d's reversal is: %d%d%d\n", num, sep3, sep2, sep1);

//     return 0;
// }

// int main(void)
// {
//     int num1, num2, num3;

//     printf("Enter a three-digit number: ");
//     scanf("%1d%1d%1d", &num1, &num2, &num3);
//     printf("The reversal is: %d%d%d\n", num3, num2, num1);

//     return 0;
// }

// int main(void)
// {
//     int be_octal;
//     int n1, n2, n3, n4, n5;

//     printf("Enter a number between 0 and 32767: ");
//     scanf("%d", &be_octal);
//     n1 = be_octal % 8; be_octal /= 8;
//     n2 = be_octal % 8; be_octal /= 8;
//     n3 = be_octal % 8; be_octal /= 8;
//     n4 = be_octal % 8; be_octal /= 8;
//     n5 = be_octal % 8; be_octal /= 8;
//     printf("In octal, your number is: %d%d%d%d%d\n", n5, n4, n3, n2, n1);
    
//     return 0;
// }

// int main(void)
// {
//     int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11;
//     int check_digit;
    
//     printf("Enter the digit: ");
//     scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9, &n10, &n11);
//     check_digit = (9 - ((((n1+n3+n5+n7+n9+n11) * 3) + (n2+n4+n6+n8+n10)) - 1) % 10);
//     printf("Check digit: %d\n", check_digit);

//     return 0;
// }

int main(void)
{
    int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12;
    int check_digit;

    printf("Enter th first 12 digits of an EAN: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9, &n10, &n11, &n12);
    check_digit = 9 - (((((n2+n4+n6+n8+n10+n12) * 3) + (n1+n3+n5+n7+n9+n11)) - 1) % 10);
    printf("Check digit: %d\n", check_digit);

    return 0;
}