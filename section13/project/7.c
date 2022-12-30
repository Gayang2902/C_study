#include <stdio.h>

int main(void)
{
    int num;
    char *ten[] = {"twenty", "thirty", "fourty", "fifty",
                    "sixty", "seventy", "eighty", "ninety"};
    char *oneten[] = {"ten", "eleven", "tweleve", "thirteen", "fourteen",
                      "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    char *one[] = {"", "one", "two", "three", "four", "five",
                   "six", "seven", "eight", "nine"};

    printf("Enter a two-digit number: ");
    scanf("%d", &num);
    printf("You entered the number ");
    if (num / 10 == 1) {
        printf("%s\n", oneten[num % 10]);
    } else {
        printf("%s-%s\n", ten[(num / 10) - 2], one[num % 10]);
    }

    return 0;
}