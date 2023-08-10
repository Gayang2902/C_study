// 13.5의 remind.c의 개선판
// reminder 배열을 동적 메모리 할당
// 메모리 절약, strcat으로 리마인더 정리할 필요없음

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REMIND (50)
#define MSG_LEN (60)

struct vstring {
    int len;
    char chars[];
};

int read_line(char str[], int n);

int main(void)
{
    struct vstring* reminders[MAX_REMIND];
    char day_str[3];
    char msg_str[MSG_LEN + 1];
    int day;
    int i, j;
    int num_remind = 0;

    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("-- No space left --\n");
            break;
        }

        printf("Enter day and reminder: ");
        scanf("%2d", &day);
        if (day == 0) { break; }
        sprintf(day_str, "%2d", day);
        read_line(msg_str, MSG_LEN);

        for (i = 0; i < num_remind; i++) {
            if (strcmp(day_str, reminders[i]->chars) < 0) { break; } // s1 < s2 일때 음수 반환이므로 기존에 존재하는 리마인더의 날짜들 사이에 들어가게 함
        }
        for (j = num_remind; j > i; j--) { reminders[j] = reminders[j-1]; } // 새로 넣을 리마인더의 공간 마련, 위로 한칸씩 밈

        reminders[i] = malloc(sizeof(struct vstring) + 2 + strlen(msg_str) + 1);
        if (reminders[i] == NULL) {
            printf("-- No space left --\n");
            break;
        }

        strcpy(reminders[i]->chars, day_str);
        strcat(reminders[i]->chars, msg_str);
        reminders[i]->len = strlen(reminders[i]->chars);

        num_remind++;
    }

    printf("\nDay Reminder\n");
    for (i = 0; i < num_remind; i++) { printf(" %s\n", reminders[i]->chars); }

    return 0;
}

int read_line(char str[], int n)
{
    int ch;
    int i = 0;

    while ((ch = getchar()) != '\n') { if (i < n) { str[i++] = ch; } }
    str[i] = '\0';
    return i;
}