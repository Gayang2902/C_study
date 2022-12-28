#include <stdio.h>
#include <string.h>

#define MAX_REMIND (50)
#define MSG_LEN (60)
#define TIME (4)
#define DAY (2)
#define MONTH (2)

int read_line(char *str, size_t size);
void clear_input(void);

int main(void)
{
    char reminders[MAX_REMIND][MONTH + DAY + TIME + MSG_LEN + 1];
    char msg_str[MSG_LEN + 1];
    char time_str[TIME + 1];
    char month_str[MONTH + 1];
    char day_str[8 + 1 + 2 + 1 + 2 + 1];
    int month;
    int day;
    int hour;
    int min;
    int i;
    int j;
    int num_remind = 0;

    printf("-- Enter reminders: \'mm/dd hh:mm message\' --\n\n");
    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("-- No space left --\n");
            break;
        }

        printf("Enter day and reminder: ");
        scanf("%2d/ %2d", &month, &day);
        if (day == 0 || month == 0) {
            break;
        } else if (day < 0 || day > 31) {
            printf("-- Day out of range 0-31; Try again --\n");
            while (getchar() != '\n');
            continue;
        }
        scanf(" %d: %d", &hour, &min);
        // 4.2d 최소 4칸.최소 2자릿수
        sprintf(day_str, "%4.2d%4.2d %.2d:%.2d", month, day, hour, min);
        read_line(msg_str, MSG_LEN);

        for (i = 0; i < num_remind; i++) {
            if (strncmp(day_str, reminders[i], 14) < 0) {
                break;
            }
        }
        for (j = num_remind; j > i; j--) {
            strcpy(reminders[i], reminders[j - 1]);
        }

        strcpy(reminders[i], day_str);
        strcat(reminders[i], msg_str);

        num_remind++;
    }

    printf("\nDay Reminder\n");
    for (i = 0; i < num_remind; i++) {
        printf(" %s\n", reminders[i]);
    }

    return 0;
}

int read_line(char *str, size_t n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n') {
        if (i < n) {
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    return i;
}

void clear_input(void)
{
    char ch;
    while ((ch = getchar()) != '\n');
}