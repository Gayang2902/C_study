#include <stdio.h>

int main(void)
{
    const char *months[] = {"January", "February", "March", "April",
                          "May", "June", "July", "August",
                          "September", "October", "November", "December"};
    // char date[21];
    int day;
    int month;
    int year;

    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%2d / %2d / %4d", &month, &day, &year);
    printf("You entered the date %s %d, %d\n", months[month - 1], day, year);
    
    return 0;
}