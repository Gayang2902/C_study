#include <stdio.h>
#include "word.h"

// white space를 띄어쓰기로 모두 통일해줌
int read_char(void)
{
    int ch = getchar();

    return (ch == '\n' || ch == '\t') ? ' ' : ch;
}

int read_word(char *word, int max_len)
{
    int ch;
    int cursor = 0;

    // word 사이 공백 무시
    while ((ch = getchar()) == ' ');

    while(ch != ' ' && ch != EOF) {
        if (cursor < max_len) {
            word[cursor++] = ch;
        }
        ch = read_char();
    }
    word[cursor] = '\0';

    return cursor;
}