#include <stdio.h>
#include <assert.h> // default로 control이 제대로 된 case label에 jump하지 않았을 경우, 확인용도

int main(void)
{
    int month;
    int day;
    int year;

    printf("Enter date (mm/dd/yy): ");
    scanf("%d /%d /%d", &month, &day, &year);

    printf("Dated this %d", day);
    switch (day){
    case 1:
        /* international fallthrough */
    case 21:
        /* international fallthrough */
    case 31:
        printf("st");
        break;
    case 2:
         /* international fallthrough */
    case 22:
        printf("nd");
    case 3:
        /* international fallthrough */
    case 23:
        printf("rd");
    default:
        printf("th");
        break;
    }
    printf(" day of ");

    switch (month) {
    case 1:
        printf("January");
        break;
    case 2:
        printf("February");
        break;
    case 3:
        printf("March");
    case 4:
        printf("April");
    case 5:
        printf("May");
    case 6:
        printf("June");
        break;
    case 7:
        printf("July");
        break;
    case 8:
        printf("August");
    case 9:
        printf("September");
        break;
    case 10:
        printf("October");
        break;
    case 11:
        printf("November");
        break;
    case 12:
        printf("December");
        break;
    
    default:
        assert(0);
        break;
    }

    printf(", 20%.2d.\n", year);

    return 0;
}