#include <stdio.h>

int main(void)
{
    int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11;
    int check_digit;
    
    printf("Enter the first (single) digit: ");
    scanf("%d", &n1);
    printf("Enter first group of five digits: ");
    scanf("%1d%1d%1d%1d%1d", &n2, &n3, &n4, &n5, &n6);
    printf("Enter second group fo five digits: ");
    scanf("%1d%1d%1d%1d%1d", &n7, &n8, &n9, &n10, &n11);

    check_digit = (9 - ((((n1+n3+n5+n7+n9+n11) * 3) + (n2+n4+n6+n8+n10)) - 1) % 10);
    printf("Check digit: %d\n", check_digit);

    return 0;
}