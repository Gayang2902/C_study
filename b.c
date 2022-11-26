#include <ncurses.h>
#include <unistd.h>

int timer(void)
{
    int row = 10, col = 10
    initscr();
    noecho();
    curs_set(FALSE);

    keypad(stdscr, TRUE);

    while (1) {
        int input = getch();
        clear();
        switch (input) {
            case KEY_UP:
                mvprintw(--row, col, "A");
                continue;
            case KEY_DOWN:        
                mvprintw(++row, col, "A");
                continue;
            case KEY_LEFT:
                mvprintw(row, --col, "A");
                continue;
            case KEY_RIGHT:
                mvprintw(row, ++col, "A");
                continue;
        }
        if (input == 'q') {
            break;
        }
    }

    endwin();
    return 0;
}

int main(void) 
{
    return timer();
}