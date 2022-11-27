#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER (100)

int g_secret_number;

void initialize_number_generator(void);
void choose_new_secret_number(void);
void read_guesses(void);

int main(void)
{
    char command = '\0';
    printf("1과 %d 사이의 난수 맞추기\n\n", MAX_NUMBER);
    initialize_number_generator();
    do {
        choose_new_secret_number();
        printf("난수 맞추기 시작\n");
        read_guesses();
        printf("한 판 더? (Y / N) ");
        scanf(" %c", &command);
        printf("\n");
    } while (command == 'y' || command == 'Y');

    return 0;
}

void initialize_number_generator(void)
{
    srand((unsigned)time(NULL));
}

void choose_new_secret_number(void)
{
    g_secret_number = rand () % MAX_NUMBER + 1;
}

void read_guesses(void)
{
    int guess = 0;
    int num_guesses = 0;

    for (;;) {
        ++num_guesses;
        printf("정답은?: ");
        scanf("%d", &guess);
        if (guess == g_secret_number) {
            printf("%d번째 시도만에 맞춤\n\n", num_guesses);
            return;
        } else if (guess < g_secret_number) {
            printf("작음\n");
        } else {
            printf("큼\n");
        }
    }
}