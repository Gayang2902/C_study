// #include <stdio.h>

// int main(void)
// {
//     printf("%6d,%4d", 86, 1040);
//     printf("%12.5e", 30.253);
//     printf("%.4f", 83.162);
//     printf("%-6.2g", .0000009979);
// }

#include <stdio.h>

int main(void)
{
    // int month, day, year;
    
    // printf("Enter a date (mm/dd/yyyy): ");
    // scanf("%d/%d/%d", &month, &day, &year);

    // printf("You entered the date %d%.2d%d\n", year, month, day);


    //
    // int item_num;
    // float unit_price;
    // int year, month, date;

    // printf("Enter item number: ");
    // scanf("%d", &item_num);
    // printf("Enter unit price: ");
    // scanf("%f", &unit_price);
    // printf("Enter purchase date (mm/dd/yyyy): ");
    // scanf("%d/%d/%d", &date, &month, &year);

    // printf("Item\tUnit\tPurchase\n\tPrice\tDate\n%d\t$%7.2f\t%d/%d/%d\n", item_num, unit_price, date, month, year);

    // return 0;


    //
    // int gsi, gi, pc, in, cd;

    // printf("Enter ISBN: ");
    // scanf("%d-%d-%d-%d-%d", &gsi, &gi, &pc, &in, &cd);
    // printf("GSI prefix: %d\n", gsi);
    // printf("Group identifier: %d\n", gi);
    // printf("Publisher code: %d\n", pc);
    // printf("Item number: %d\n", in);
    // printf("Check digit: %d\n", cd);

    // return 0;


    //
    // int p1, p2, p3;

    // printf("Enter phone number [(xxx) xxx-xxxx]: ");
    // scanf("(%d) %d-%d", &p1, &p2, &p3);
    // printf("You entered %d.%d.%d\n", p1, p2, p3);

    // return 0;


    //
    int num1, num2, num3, num4, num5, num6, num7, num8, num9, num10,
    num11, num12, num13, num14, num15, num16;

    printf("Enter the numbers from 1 to 16 in any order:\n");
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", 
    &num1, &num2, &num3, &num4, &num5, &num6, &num7, &num8, &num9, &num10,
    &num11, &num12, &num13, &num14, &num15, &num16);

    printf("%2d %2d %2d %2d\n%2d %2d %2d %2d\n%2d %2d %2d %2d\n%2d %2d %2d %2d\n", num1, num2, num3, num4, num5, num6, num7, num8, num9, num10, num11, num12, num13, num14, num15, num16);
    printf("\nRow sums: %d %d %d %d\n", num1+num2+num3+num4, num5+num6+num7+num8, num9+num10+num11+num12, num13+num14+num15+num16);
    printf("Column sums: %d %d %d %d\n", num1+num5+num9+num13, num2+num6+num10+num14, num3+num7+num11+num15, num4+num8+num12+num16);
    printf("Diagonal sums: %d %d\n", num1+num6+num11+num16, num4+num8+num12+num16);

    return 0;
}