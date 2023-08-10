#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER (100)

void initialize_number_generator(void);
int get_new_secret_number(void);
void read_guesses(int secret_number);

int main(void)
{
    char command = '\0';
    int secret_number = 0;

    printf("1과 %d 사이의 난수 맞추기\n\n", MAX_NUMBER);
    initialize_number_generator();
    do {
        secret_number = get_new_secret_number();
        printf("난수 맞추기 시작\n");
        read_guesses(secret_number);
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

int get_new_secret_number(void)
{
    return rand() % MAX_NUMBER + 1;
}

void read_guesses(int secret_number)
{
    int guess = 0;
    int num_guesses = 0;

    for (;;) {
        ++num_guesses;
        printf("정답은?: ");
        scanf("%d", &guess);
        if (guess == secret_number) {
            printf("%d번째 시도만에 맞춤\n\n", num_guesses);
            return;
        } else if (guess < secret_number) {
            printf("작음\n");
        } else {
            printf("큼\n");
        }
    }
}