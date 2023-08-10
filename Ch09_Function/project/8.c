#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(void);
bool play_game(void);

int main(void)
{
    bool result;
    int win = 0, lose = 0;
    char c;

    srand((unsigned)time(NULL));

    do {
        result = play_game();
        if (result == true) {
            printf("You win!\n");
            win++;
        } else {
            printf("You lose!\n");
            lose++;
        }
        printf("Play again? ");
        scanf(" %c", &c);
    } while (c == 'y');
    printf("Wins: %d   Losses: %d\n", win, lose);
    
    return 0;
}

int roll_dice(void)
{
    return (rand() % 6 + 1) + (rand() % 6 + 1);
}

bool play_game(void)
{
    int point;
    int roll;
    int spe[5] = {7, 11, 2, 3, 12};
    point = roll_dice();
    printf("You rolled: %d\n", point);
    if (point == spe[0] || point == spe[1]) {
        return true;
    } else if (point == spe[2] || point == spe[3] || point == spe[4]) {
        return false;
    } else {
        printf("Your point is %d\n", point);
        for (;;) {
            roll = roll_dice();
            printf("You rolled: %d\n", roll);
            if (point == roll) {
                return true;
            } else if (roll == 7) {
                return false;
            } else continue;
        }
    }
}